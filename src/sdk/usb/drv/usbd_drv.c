/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file usbd_drv.c
 * @brief USB device driver functions
 *
 * These functions demonstrate how to program the USB controller and\n
 * are not intended for use in an actual application.
 */
#include "usb/usb.h"
#include "soc_memory_map.h"

//! Function to initialize the USB controller for device operation.
/*! This initialization performs basic configuration to prepare the device for connection to a host.
 *
 * @param port           The USB module to use
 * @param endpointList   pointer to list with endpoint queue heads
 */

uint32_t usbd_device_init(usb_module_t *port, usbdEndpointPair_t *endpointList)
{
	/*!
	 * Disable vbus in case it is enabled.\n
	 * Devices never drive Vbus.
	 */
	usbDisableVbus(port);

	/*!
	 *  First start clocks and PLL
	 */

	if(usbEnableClocks(port) == -1)
		{
			return -1;
		};

 	/*!
 	 *  Enable and initialize transceiver interface for controller
 	 */

	if (usbEnableTransceiver(port) == -1)
	{
		return -1;
	}

	//! - Select PHY type for this hardware
	if(port->phyType == Ulpi)
	{

	port->moduleBaseAddress->USB_PORTSC = (port->moduleBaseAddress->USB_PORTSC & (~(USB_PORTSC_PTS(3)))) \
            | (USB_PORTSC_PTS(2));

	}
	else
	{
		port->moduleBaseAddress->USB_PORTSC &= (~(USB_PORTSC_PTS(3)));  // UTMI PHY
	}

		// Reset controller after switching PHY's
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_RST);

		// wait for reset to complete
		while(port->moduleBaseAddress->USB_USBCMD & (USB_USBCMD_RST));

  	//! - Set controller to device Mode
	port->moduleBaseAddress->USB_USBMODE = (USB_USBMODE_CM_DEVICE);

  	//! - Set initial configuration for controller
  	port->moduleBaseAddress->USB_USBCMD &= (~( USB_USBCMD_ITC(0xFF)));	// Set interrupt threshold control = 0

    port->moduleBaseAddress->USB_USBMODE |= (USB_USBMODE_SLOM);	// Setup Lockouts Off

    //! Setup the endpoint list
	// Check if endpoint list is aligned on a 4K boundary
	if((int)endpointList % 2048 != 0)
	{
		printf("Endpoint List not aligned on 4K boundary");
		return(-1);
	}

	//! - Set the device endpoint list address
  	port->moduleBaseAddress->USB_ASYNCLISTADDR = (uint32_t)&endpointList[0];

  	/*
  	 * Clear the entire endpoint list
  	 * this is not really necessary but makes it easier to check memory content when debugging
  	 */
  	int i;
  	for ( i =0; i < (8 * 2 * 16); i++)
		*(uint32_t *)(&endpointList[0] + i) = 0;

  	//! - Configure Endpoint 0.
  	//  Only the required EP0 for control traffic is initialized at this time.
  	port->moduleBaseAddress->USB_ENDPTCTRL[0] |= (USB_ENDPTCTRL_TXE | USB_ENDPTCTRL_RXE);	// Enable TX/RX of EP0

 	//! - Initialize queue head for EP0 IN (device to host)
  	usbdEndpointInfo_t endpoint0In, endpoint0Out;

  	endpoint0In.endpointNumber = 0;
  	endpoint0In.endpointDirection = IN;
  	endpoint0In.maxPacketLength = 0x40;
  	endpoint0In.mult = 0;
  	endpoint0In.interruptOnSetup = TRUE;

	usbd_endpoint_qh_init(&endpointList[0], &endpoint0In, DTD_TERMINATE);	// No nextDtd at this time

	//! - Initialize queue head for EP0 OUT (host to device)
  	endpoint0Out.endpointNumber = 0;
  	endpoint0Out.endpointDirection = OUT;
  	endpoint0Out.maxPacketLength = 0x40;
   	endpoint0Out.mult = 0;
 	endpoint0Out.interruptOnSetup = FALSE;


	usbd_endpoint_qh_init(&endpointList[0], &endpoint0Out, DTD_TERMINATE);	// No nextDtd at this time

	//! Start controller
	port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_RS);

	return(0);

}

//! Function to initialize the controller after the USB bus reset
/*!
 * USB device response to a USB bus reset.
 *
 * @param port		USB controller to use
 * @return			returns the operating speed of the port
 */
usbPortSpeed_t usbd_bus_reset(usb_module_t *port)
{
	uint32_t temp;


    //! - Clear all setup token semaphores
    temp = port->moduleBaseAddress->USB_ENDPTSETUPSTAT;
    port->moduleBaseAddress->USB_ENDPTSETUPSTAT = temp;

    //! - Clear all complete status bits
    temp = port->moduleBaseAddress->USB_ENDPTCOMPLETE;
    port->moduleBaseAddress->USB_ENDPTCOMPLETE = temp;

	//! - Wait for all primed status to clear
	while (port->moduleBaseAddress->USB_ENDPTPRIME);

    //! - Flush all endpoints
    port->moduleBaseAddress->USB_ENDPTFLUSH = 0xFFFFFFFF;

   	//! - Wait for host to stop signaling reset
	while (port->moduleBaseAddress->USB_PORTSC & (USB_PORTSC_PR));

	//! - Clear reset status bit
	port->moduleBaseAddress->USB_USBSTS |= (USB_USBSTS_URI | USB_USBSTS_UI);

	//! Return the connection speed (full/high speed)
  	return(usb_get_port_speed(port));
}

/*!
 * USB device function to return the data from a setup packet.
 * NOTE: We assume only endpoint 0 is a control endpoint
 *
 * @param	endpointList	pointer to the device endpoint list address
 * @param	port			pointer to controller info structure
 * @param	setupPacket		Setup data of the setup packet
 */
void usbd_get_setup_packet(usb_module_t *port, usbdEndpointPair_t *endpointList, usbdSetupPacket_t *setupPacket)
{

	usbdDeviceEndpointQueueHead_t *enpointQueueHead;					// reference to the queue head
	enpointQueueHead = (usbdDeviceEndpointQueueHead_t*)&(endpointList[0].out);	// endpoint 0 out

    //! - Wait for setup packet to arrive
	while(!(port->moduleBaseAddress->USB_ENDPTSETUPSTAT & (USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(1))));

    /*! copy setup data from queue head to buffer and check semaphore\n
     * SUTW will be cleared when a new setup packet arrives.\n
     * To avoid data corruption, we check the SUTW flag after the copy\n
     * and when it is cleared, we repeat the copy to get the new setup data.
     */
    do {
    	port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_SUTW);							//! - Set setup tripwire
    	memcpy(setupPacket, &enpointQueueHead->setupBuffer, sizeof(usbdSetupPacket_t));		//! - copy the setup data
    }  while ( !(port->moduleBaseAddress->USB_USBCMD & (USB_USBCMD_SUTW)));					//! - repeat if SUTW got cleared

    //! - Clear setup identification
    port->moduleBaseAddress->USB_ENDPTSETUPSTAT |= (USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(1));

    //! - Clear Setup tripwire bit
    port->moduleBaseAddress->USB_USBCMD &= (~USB_USBCMD_SUTW);

    //! - Flush Endpoint 0 IN and OUT in case some a previous transaction was left pending
    port->moduleBaseAddress->USB_ENDPTSTATUS &= (USB_ENDPTSTATUS_ERBR(0) | USB_ENDPTSTATUS_ETBR(0));

    //! - Wait for ENDPSETUPSTAT to clear.\n
    //! It must be clear before the status phase/data phase can be primed
    while (port->moduleBaseAddress->USB_ENDPTSETUPSTAT & (USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(1)));
}

//! Function to send an IN control packet to the host.
/*! NOTE: this function uses the default control endpoint (0).\n
 *       The endpoint number is hard-coded.
 *
 * @param	port			Controller to use
 * @param	endpointList	pointer to the device endpoint list
 * @param	buffer			Data to be sent to host
 * @param	size			Amount of data to be transferred in bytes
 */
void usbd_device_send_control_packet(usb_module_t *port, usbdEndpointPair_t *endpointList, uint8_t* buffer, uint32_t size)
{
	usbdEndpointDtd_t *dtdIn, *dtdOut;
	uint8_t *receiveBuffer;		// Buffer to receive the data phase (i.e. zero length packet)

	receiveBuffer = (uint8_t*) malloc(MAX_USB_DESC_SIZE);

	//! - Initialize the device descriptor to send
	dtdIn = usbd_dtd_init(size, 0, 0, (uint32_t*) buffer);

	//! - Put the IN transfer descriptor on the queue head.
	endpointList[0].in.nextDtd = (uint32_t)dtdIn;

    //! - Prime transmit endpoint (IN)
    port->moduleBaseAddress->USB_ENDPTPRIME |= (USB_ENDPTPRIME_PETB(1));


	/*!
	 * Initialize a transfer descriptor for receive.\n
	 * The host won't actually send anything,\n
	 * but a dTD needs to be setup to correctly deal with the 0 byte OUT\n
	 * packet the host sends after receiving the IN data.\n
	 * The OUT transaction must be queued together with the IN transaction\n
	 * for error recovery purposes.\n
	 */
	dtdOut = usbd_dtd_init(0x40, 1, 0, (uint32_t*) receiveBuffer);

	//! - Put the OUT transfer descriptor on the queue head
	endpointList[0].out.nextDtd = (uint32_t)dtdOut;

    //! - Prime prime receive endpoint (OUT)
    port->moduleBaseAddress->USB_ENDPTPRIME |= (USB_ENDPTPRIME_PERB(1));

    /*!
     * Wait for OUT to complete and clear interrupt flag\n
     * NOTE. The transfer is complete when the OUT transaction (status phase) is received\n
     *       regardless whether or not the IN transaction is ACK'd.
     */

    //! - Wait for interrupt flag
	while (!(port->moduleBaseAddress->USB_USBSTS & (USB_USBSTS_UI )));
	port->moduleBaseAddress->USB_USBSTS |= (USB_USBSTS_UI);

	//! - Check endpoint's complete flags and clear
	// This is normally used in the ISR to determine if and which endpoint generated an interrupt
	if (port->moduleBaseAddress->USB_ENDPTCOMPLETE & USB_ENDPTCOMPLETE_ETCE0){
		port->moduleBaseAddress->USB_ENDPTCOMPLETE |= USB_ENDPTCOMPLETE_ETCE0;		// Clear complete Flag
	}
	else {
		while (1);		// Not our endpoint. Do something else
	}

	//! Check Active flag in OUT dTD and wait for it to clear.
	//! This is the only true indication that the transfer did complete.

	while (dtdIn->dtdToken & USB_DTD_TOKEN_STAT_ACTIVE );

	// Return memory to heap
    free((void *)dtdIn->mallocPointer);
    free((void *)dtdOut->mallocPointer);
    free((void *)receiveBuffer);


}

 //! Function to send an zero length IN packet to the host.
 /*!
 * Zero Length packets are used as completion handshake in control transfers.\n
 * They can also be used to signal the end of a variable length transfer.\n
 *
 * @param port				Usb controller to use
 * @param endpointList		pointer to the device endpoint list
 * @param endpointNumber	endpoint info data structure for the endpoint to use
 */
void usbd_device_send_zero_len_packet(usb_module_t *port, usbdEndpointPair_t *endpointList, uint32_t endpointNumber)
{
	usbdEndpointDtd_t *usbDtd;
	uint32_t emptyBuffer = 0;

	//! Set up dTD for zero length packet
	//! - Initialize dTD
	usbDtd = usbd_dtd_init(0, 1, 0, (uint32_t*) &emptyBuffer);

	//! - Put dTD on endpoint queue head
	endpointList[0].in.nextDtd = (uint32_t)usbDtd;

    //! - Prime Tx buffer for control endpoint
    port->moduleBaseAddress->USB_ENDPTPRIME |= (USB_ENDPTPRIME_PETB(1<<endpointNumber));

    //! - Wait for prime to complete
    while (port->moduleBaseAddress->USB_ENDPTPRIME & (USB_ENDPTPRIME_PETB(1<<endpointNumber)));

    //! - Wait for IN to complete and clear flag
	while (!(port->moduleBaseAddress->USB_USBSTS & (USB_USBSTS_UI)));
	port->moduleBaseAddress->USB_USBSTS |= (USB_USBSTS_UI);

	//! - Check Active flag and wait for it to clear
	while (usbDtd->dtdToken & USB_DTD_TOKEN_STAT_ACTIVE);

	/* Return memory for dTDs to heap */
    free((void *)usbDtd->mallocPointer);
}

//! Function to initialize an endpoint queue head
/*!
 * Initialize an endpoint queue head. The space for the endpoint queue heads was
 * allocated when the endpoint list was created, so this function does not
 * call malloc.
 *
 * @param endpointList		location of the endpoint list
 * @param usbdEndpoint    Pointer to the endpoint characteristics
 * @param nextDtd		pointer to the first transfer descriptor for the queue head
 */
void usbd_endpoint_qh_init(usbdEndpointPair_t *endpointList, usbdEndpointInfo_t *usbdEndpoint, uint32_t nextDtd)
{
	usbdDeviceEndpointQueueHead_t* usbdQueueHead;
	uint32_t endpointCapabilities;

	//! Locate entry in the list
	if (usbdEndpoint->endpointDirection == OUT){
		usbdQueueHead = &(endpointList[usbdEndpoint->endpointNumber].out);
	}
	else {
		usbdQueueHead = &(endpointList[usbdEndpoint->endpointNumber].in);
	}

  	if (usbdEndpoint->interruptOnSetup == TRUE)
  		endpointCapabilities = USB_EP_QH_EP_CHAR_IOS;
  	else
  		endpointCapabilities = 0;

  	usbdQueueHead->endpointCharacteristics = ( endpointCapabilities
  							| USB_EP_QH_EP_CHAR_MULT(usbdEndpoint->mult)
  							| USB_EP_QH_EP_CHAR_ZLT		// Turn Zero Length Termination off
  						 	| USB_EP_QH_EP_CHAR_MAX_PACKET(usbdEndpoint->maxPacketLength));

	usbdQueueHead->currentDtd = 0;		// Will be updated by the controller with nextDtd on startup
	usbdQueueHead->nextDtd = nextDtd;	// This will be the first dTD that the controller uses
	usbdQueueHead->dtdToken = 0;		// Will be updated with the token from nextdTD on startup

	int i;
	for(i = 0; i < 5; i++)			// Clear the buffer pointers (for ease of debug)
		usbdQueueHead->dtdBuffer[i] = 0;

}

//! Function to create a new transfer descriptor
/*!
 * This functions allocate memory for a device transfer descriptor (dTD) and
 * initializes the dTD. This function assumes the dTD is the last in the list so
 * the next dTD pointer is marked as invalid.
 *
 * 	@param transferSize			number of bytes to be transferred
 *	@param interruptOnComplete	interrupt on complete flag
 *	@param multOverride			Override the queue head multiplier setting (0 for default)
 *	@param bufferPointer		pointer to the data buffer
 *
 *	@return 					pointer to the transfer descriptor
 *
 */
usbdEndpointDtd_t *usbd_dtd_init(uint32_t transferSize, uint32_t interruptOnComplete, uint32_t multOverride, uint32_t *bufferPointer)
{
	usbdEndpointDtd_t *usbDtd;
	uint32_t token;
	uint32_t mallocAddress;
   /*
	* The USB controller requires dTDs to be aligned on a 32 byte boundary.
	* In order to accomplish this, the data is over-allocated and
	* adjusted.
 	*/
	mallocAddress = (uint32_t)malloc(sizeof(usbdEndpointDtd_t)*2 - 1);
    usbDtd = (usbdEndpointDtd_t *)((mallocAddress + 32) & 0xFFFFFFE0);	// Align on 32-byte boundary

	usbDtd->nextDtd = 0xDEAD0001;	//! invalidate nextDtd (set T-bit)

	//! Check if transfer fits in 5 4K buffers
	//  We assume the pay load data is in contiguous memory
  	if ((int)transferSize - (0x1000 - (int)bufferPointer % 0x1000) > 0x4000){
  		// Error: Transfer does not fit in 1 descriptor
  		return((usbdEndpointDtd_t *) 0);
  	}


  	if (interruptOnComplete)
  		token = USB_DTD_TOKEN_IOC;
  	else
  		token = 0;

  	usbDtd->dtdToken = (token
  							| USB_DTD_TOKEN_TOTAL_BYTES(transferSize)
  							| USB_DTD_TOKEN_MULTO(multOverride)
  							| USB_DTD_TOKEN_STAT_ACTIVE );

  	//! Calculate & write the buffer pointers/
  	// Split input buffer in 5 4K buffers
  	int i;
  	for (i = 0; i < 5; i++) {
  		usbDtd->dtdBuffer[i] = (uint32_t) bufferPointer;

  		// next buffer starts at 4K next 4K boundary
  		bufferPointer = (uint32_t *)((uint32_t)bufferPointer - (uint32_t)bufferPointer % 0x1000 + 0x1000);
   	}
	usbDtd->mallocPointer = mallocAddress;  // Keep track of allocated memory

	return usbDtd;
}

//! Function to add a transfer descriptor or a list of transfer descriptors to an active endpoint
/*! This function places a new transfer on the linked list of transfer descriptors.\n
 * If the list was empty, the new transfer descriptor is placed on the queue head.
 *
 * 	@param port					Pointer to controller info structure.
 * 	@param usbdEndpoint			Endpoint
 *	@param endpointList			Pointer to the endpoint list
 *	@param new_dtd				pointer to the descriptor to add
 *
 */
void usbd_add_dtd(usb_module_t *port, usbdEndpointPair_t *endpointList, usbdEndpointInfo_t *usbdEndpoint, usbdEndpointDtd_t *new_dtd)
{

	uint32_t endpointStat = 0;
	uint32_t bitmask = 0;
	usbdDeviceEndpointQueueHead_t *queue_head;

	//! Function overview:
	/*! Determine whether the link list is empty:\n
	 *	- Case 1: Link list is empty\n
	 * 	 	-# Write dQH next pointer AND dQH terminate bit to 0 as a single DWord operation.
	 *		-# Clear active & halt bit in dQH (in case set from a previous error).
	 *	 	-# Prime endpoint by writing ‘1’ to correct bit position in ENDPTPRIME.\n
	 *	- Case 2: Link list is not empty
	 *		-# Add dTD to end of linked list.
	 *		-# Read correct prime bit in ENDPTPRIME – if ‘1’ DONE.
	 *		-# Set ATDTW bit in USBCMD register to ‘1’.
	 *		-# Read correct status bit in ENDPTSTAT. (store in tmp. variable for later)
	 *		-# Read ATDTW bit in USBCMD register.\n
	 *			If ‘0’ goto c.\n
	 *			If ‘1’ continue to f.\n
	 *		-# Write ATDTW bit in USBCMD register to ‘0’.
	 *		-# If status bit read in (d) is ‘1’ DONE.
	 *		-# If status bit read in (d) is ‘0’ then Goto Case 1: Step 1.
	 */

	//! Implementation:

	//! Calculate the bit mask (position) for the endpoint registers
	bitmask = 1 << usbdEndpoint->endpointNumber;
	if (usbdEndpoint->endpointDirection == IN){
		bitmask = bitmask << 16;				// Tx bits are in upper 16 bits
	}

	//! Locate the endpoint's queue head
	if (usbdEndpoint->endpointDirection == OUT){
		queue_head = &endpointList[usbdEndpoint->endpointNumber].out;
	} else {
		queue_head = &endpointList[usbdEndpoint->endpointNumber].in;
	}

	//! Find the last dtd in the list
	usbdEndpointDtd_t *last_dtd;

	last_dtd = (usbdEndpointDtd_t *)queue_head->currentDtd;		// Start search at currently active dTD

	// Loop until we find the dtd with the T bit set in next_dtd
	while(!(last_dtd->nextDtd & USB_DTD_NEXT_DTD_T)){
		last_dtd = (usbdEndpointDtd_t *)last_dtd->nextDtd;				// move to next element
	}

	//! Add dtd to the linked list (so our reclaim routine can always find dtds)
	last_dtd->nextDtd = (uint32_t)new_dtd;

	//! Determine whether the link list was empty
	if(!(last_dtd == (usbdEndpointDtd_t *)queue_head->currentDtd)){		//! List is NOT empty (case 2)

		//! Make sure the controller did not finish before the dtd was added
		//! if Prime bit is not set:
		if(!(port->moduleBaseAddress->USB_ENDPTPRIME & bitmask)){
			do {//! - loop until ATDTW bit remains set
				//! - set ATDTW bit
				port->moduleBaseAddress->USB_USBCMD |= USB_USBCMD_ATDTW;
				//! - Read ENDPTSTAT bit
				endpointStat = port->moduleBaseAddress->USB_ENDPTSTATUS | bitmask;
			} while ((port->moduleBaseAddress->USB_USBCMD & USB_USBCMD_ATDTW) == 0);

			port->moduleBaseAddress->USB_USBCMD &= ~(USB_USBCMD_ATDTW);		//! clear ATDTW bit
		}
		else {
			endpointStat = 0x8000;		// set endpointStat to non-zero to skip the "case 1" action
		}
	}
	if(endpointStat == 0){		//! List was empty before we could add the dTD (Case 1)
		//! - Add the dTD to the queue head
		queue_head->nextDtd = (uint32_t)new_dtd;
		//! - Clear Active and Error flags
		queue_head->dtdToken &= ~(USB_QTD_TOKEN_STAT_ACTIVE | USB_QTD_TOKEN_STAT_HALTED);
		//! - Prime the endpoint
		port->moduleBaseAddress->USB_ENDPTPRIME |= bitmask;
	}
}

//! Function to reclaim used transfer descriptors.
/*! This function parses the list of transfer descriptors, starting\n
 * at the Head pointer and up to the currently active descriptor.\n
 * It removes retired descriptors from the list and returns memory used by the descriptor to the heap.
 *
 * 	@param port					Pointer to controller info structure.
 * 	@param usbdEndpoint			Endpoint
 *	@param endpointList			Pointer to the endpoint list
 *	@param head					pointer to the head of the list
 *
 *	@return						Pointer to the new list head.
 *
 */
usbdEndpointDtd_t *usbd_reclaim_dtd(usb_module_t *port, usbdEndpointPair_t *endpointList, usbdEndpointInfo_t *usbdEndpoint, usbdEndpointDtd_t *head)
{

	usbdEndpointDtd_t *descriptor, *nextDescriptor;
	usbdDeviceEndpointQueueHead_t *queueHead;

	//! Locate the endpoint queue head
	if (usbdEndpoint->endpointDirection == OUT){
		queueHead = &endpointList[usbdEndpoint->endpointNumber].out;
	} else {
		queueHead = &endpointList[usbdEndpoint->endpointNumber].in;
	}

	//! walk the list until we reach the currently active descriptor
	descriptor = head;
	while (descriptor != (usbdEndpointDtd_t *)queueHead->currentDtd){
		// Check Active bit. Should be cleared in all cases.
		if(descriptor->dtdToken & USB_DTD_TOKEN_STAT_ACTIVE){
			printf ("** Active descriptor on free list!\n");
		}
		//! - Remove descriptor
		nextDescriptor = (usbdEndpointDtd_t *)descriptor->nextDtd;
		free ((void *)descriptor->mallocPointer);
		descriptor = nextDescriptor;
	}
	//! Return current descriptor
	return descriptor;
}
