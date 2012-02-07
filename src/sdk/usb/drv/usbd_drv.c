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
 * 
 */


/*!
 * Initialize the USB controller for device  operation. This initialization performs
 * basic configuration to prepare the device for connection to a host.
 *
 * @param port           The USB module to use
 * @param endpointList   pointer to list with endpoint queue heads
 */

#include "usb.h"
#include "usb_registers.h"
#include "usb_defines.h"
#include "soc_memory_map.h"

uint32_t usbd_device_init(usb_module_t *port, usbdEndpointPair_t *endpointList)
{
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

	//! Select PHY type for this hardware
	if(port->phyType == Ulpi)
	{

	port->moduleBaseAddress->USB_PORTSC = (port->moduleBaseAddress->USB_PORTSC & (~(USB_PORTSC_PTS(3)))) \
            | (USB_PORTSC_PTS(2));

	}
	else
	{
		port->moduleBaseAddress->USB_PORTSC &= (~(USB_PORTSC_PTS(3)));  // UTMI PHY
	}

		//! Reset controller after switching PHY's
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_RST);

		//! wait for reset to complete
		while(port->moduleBaseAddress->USB_USBCMD & (USB_USBCMD_RST));

  	//! Set controller to device Mode
	port->moduleBaseAddress->USB_USBMODE = (USB_USBMODE_CM_DEVICE);

  	//! Initial configuration for controller
  	port->moduleBaseAddress->USB_USBCMD &= (~( USB_USBCMD_ITC(0xFF)));	// Set interrupt threshold control = 0

    port->moduleBaseAddress->USB_USBMODE |= (USB_USBMODE_SLOM);	// Setup Lockouts Off

    //! Setup the endpoint list
	// Check if endpoint list is aligned on a 4K boundary
	if((int)endpointList % 2048 != 0)
	{
		printf("Endpoint List not aligned on 4K boundary");
		return(-1);
	}

	// Set the device endpoint list address
  	port->moduleBaseAddress->USB_ASYNCLISTADDR = (uint32_t)&endpointList[0];

  	/*
  	 * Clear the entire endpoint list
  	 * this is not really necessary but makes it easier to check memory content when debugging
  	 */
  	int i;
  	for ( i =0; i < (8 * 2 * 16); i++)
		*(uint32_t *)(&endpointList[0] + i) = 0;

  	//! Configure EP0.
  	//  Only the required EP0 for control traffic is initialized at this time.
  	port->moduleBaseAddress->USB_ENDPTCTRL[0] |= (USB_ENDPTCTRL_TXE | USB_ENDPTCTRL_RXE);	// Enable TX/RX of EP0

 	//! Initialize queue head for EP0 IN (device to host)
  	usbdEndpointInfo_t endpoint0In, endpoint0Out;

  	endpoint0In.endpointNumber = 0;
  	endpoint0In.endpointDirection = IN;
  	endpoint0In.maxPacketLength = 0x40;
  	endpoint0In.interruptOnSetup = TRUE;

	usbd_endpoint_qh_init(&endpointList[0], &endpoint0In, DTD_TERMINATE);	// No nextDtd at this time

	//! Initialize queue head for EP0 OUT (host to device)
  	endpoint0Out.endpointNumber = 0;
  	endpoint0Out.endpointDirection = OUT;
  	endpoint0Out.maxPacketLength = 0x40;
  	endpoint0Out.interruptOnSetup = FALSE;


	usbd_endpoint_qh_init(&endpointList[0], &endpoint0Out, DTD_TERMINATE);	// No nextDtd at this time

	//! Start controller
	port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_RS);

	return(0);

}


/********************************************************************/
/*
 * USB device response to a USB bus reset.
 *
 * Parameters:
 */
usbPortSpeed_t usbd_bus_reset(usb_module_t *port)
{
	uint32_t temp;


    /* Clear all setup token semaphores */
    temp = port->moduleBaseAddress->USB_ENDPTSETUPSTAT;
    port->moduleBaseAddress->USB_ENDPTSETUPSTAT = temp;

    /* Clear all complete status bits */
    temp = port->moduleBaseAddress->USB_ENDPTCOMPLETE;
    port->moduleBaseAddress->USB_ENDPTCOMPLETE = temp;

	/* Wait for all primed status to clear */
	while (port->moduleBaseAddress->USB_ENDPTPRIME);

    /* Flush all endpoints */
    port->moduleBaseAddress->USB_ENDPTFLUSH = 0xFFFFFFFF;

   	/* Wait for host to stop signaling reset */
	while (port->moduleBaseAddress->USB_PORTSC & (USB_PORTSC_PR));

	/* Clear reset status bit */
	port->moduleBaseAddress->USB_USBSTS |= (USB_USBSTS_URI | USB_USBSTS_UI);

	//! Get the connection speed (full/high speed)
  	usbPortSpeed_t portSpeed = usb_get_port_speed(port);

  	return(portSpeed);
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

    //! Wait for setup
	while(!(port->moduleBaseAddress->USB_ENDPTSETUPSTAT & (USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(1))));

    //! Clear setup identification
    port->moduleBaseAddress->USB_ENDPTSETUPSTAT |= (USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(1));

    //! copy setup data from queue head to buffer and check semaphore
    //! SUTW will be cleared when a new setup packet arrives.
    //! To avoid data corruption, we check the SUTW flag after the copy
    //! and when it is cleared, we repeat the copy to get the new setup data
    do {
    	port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_SUTW);							//! Set setup tripwire
    	memcpy(setupPacket, &enpointQueueHead->setupBuffer, sizeof(usbdSetupPacket_t));		//! copy the setup data
    }  while ( !(port->moduleBaseAddress->USB_USBCMD & (USB_USBCMD_SUTW)));					//! repeat if SUTW got cleared

    //! Clear Setup tripwire bit
    port->moduleBaseAddress->USB_USBCMD &= (~USB_USBCMD_SUTW);

    //! Wait for ENDPSETUPSTAT to clear. It must be clear before the status phase/data phase can be primed
    while (port->moduleBaseAddress->USB_ENDPTSETUPSTAT & (USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(1)));
}

/*!
 * Function to send an IN control packet to the host.
 * NOTE: this function uses the default control endpoint (0).
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

	//! Initialize the device descriptor to send
	dtdIn = usbd_dtd_init(size, 0, 0, (uint32_t*) buffer);

	//! Put the IN transfer descriptor on the queue head.
	// Endpoint 0 IN follows endpoint 0 OUT and is at offset 64 (0x40)
	endpointList[0].in.nextDtd = (uint32_t)dtdIn;

    //! Prime transmit endpoint (IN)
    port->moduleBaseAddress->USB_ENDPTPRIME |= (USB_ENDPTPRIME_PETB(1));


	/*!
	 * Initialize a transfer descriptor for receive.
	 * The host won't actually send anything,
	 * but a dTD needs to be setup to correctly deal with the 0 byte OUT
	 * packet the host sends after receiving the IN data.
	 * The OUT transaction must be queued together with the IN transaction
	 * for error recovery purposes.
	 */
	dtdOut = usbd_dtd_init(0x40, 1, 0, (uint32_t*) receiveBuffer);

	//! Put the OUT transfer descriptor on the queue head
	// Endpoint 0 OUT is the first endpoint in the list
	endpointList[0].out.nextDtd = (uint32_t)dtdOut;

    //! Prime prime receive endpoint (OUT)
    port->moduleBaseAddress->USB_ENDPTPRIME |= (USB_ENDPTPRIME_PERB(1));

    /*!
     * Wait for OUT to complete and clear interrupt flag
     * NOTE. The transfer is complete when the OUT transaction (status phase) is received
     *       regardless whether or not the IN transaction is ACK'd
     */

    //! Wait for interrupt flag
	while (!(port->moduleBaseAddress->USB_USBSTS & (USB_USBSTS_UI )));
	port->moduleBaseAddress->USB_USBSTS |= (USB_USBSTS_UI);

	//! Check endpoints compelete flags and clear
	// This is normally used in the ISR to determine if and which endpoint generated an interrupt
	if (port->moduleBaseAddress->USB_ENDPTCOMPLETE & USB_ENDPTCOMPLETE_ETCE0){
		port->moduleBaseAddress->USB_ENDPTCOMPLETE |= USB_ENDPTCOMPLETE_ETCE0;		// Clear complete Flag
	}
	else {
		while (1);		// Not our endpoint. Do something else
	}

	//! Check Active flag in OUT dTD and wait for it to clear.
	//! This is the only true indication that the transfer did complete
	// This is normally used to re-claim used dTDs

	while (dtdIn->dtdToken & USB_DTD_TOKEN_STAT_ACTIVE );

	// Return memory to heap
    free((void *)dtdIn->mallocPointer);
    free((void *)dtdOut->mallocPointer);
    free((void *)receiveBuffer);


}

 //! Function to send an zero length IN packet to the host.
 /*!
 * Zero Length packets are used as completion handshake in control transfers.
 * They can also be used to signal the end of a variable length transfer.
 *
 * Parameters:
 * @param port			Usb controller to use
 * @param endpointList	pointer to the device endpoint list
 * @param endpoint		endpoint info data structure for the endpoint to use
 */
void usbd_device_send_zero_len_packet(usb_module_t *port, usbdEndpointPair_t *endpointList, uint32_t endpointNumber)
{
	usbdEndpointDtd_t *usbDtd;
	uint32_t emptyBuffer = 0;

	//! Set up dTD for zero length packet
	//! Initialize dTD
	usbDtd = usbd_dtd_init(0, 1, 0, (uint32_t*) &emptyBuffer);

	//! Put dTD on endpoint queue head
	endpointList[0].in.nextDtd = (uint32_t)usbDtd;

    //! Prime Tx buffer for control endpoint
    port->moduleBaseAddress->USB_ENDPTPRIME |= (USB_ENDPTPRIME_PETB(1<<endpointNumber));

    //! Wait for prime to complete
    while (port->moduleBaseAddress->USB_ENDPTPRIME & (USB_ENDPTPRIME_PETB(1<<endpointNumber)));

    //! Wait for IN to complete and clear flag
	while (!(port->moduleBaseAddress->USB_USBSTS & (USB_USBSTS_UI)));
	port->moduleBaseAddress->USB_USBSTS |= (USB_USBSTS_UI);

	//! Check Active flag and wait for it to clear
	while (usbDtd->dtdToken & USB_DTD_TOKEN_STAT_ACTIVE);

	/* Return memory for dTDs to heap */
    free((void *)usbDtd->mallocPointer);
}

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

/*!
 * usbd_dtd_init: create and new device transfer descriptor
 *
 * This functions allocate memory for a device transfer descriptor (dTD) and
 * initializes the dTD. This function assumes the dTD is the last in the list so
 * the next dTD pointer is marked as invalid.
 *
 * 	@param transferSize			number of bytes to be transferred
 *	@param interruptOnComplete	interrupt on complete flag
 *	@param multOverride			Override the queue head multiplier setting (0 for default)
 *	@param bufferPointer		pointer to the data buffer
 *
 *	@return usbDtd				pointer to the transfer descriptor
 *
 */
usbdEndpointDtd_t *usbd_dtd_init(uint32_t transferSize, uint32_t interruptOnComplete, uint32_t multOverride, uint32_t *bufferPointer)
{
	usbdEndpointDtd_t *usbDtd;
	uint32_t token;
	uint32_t mallocAddress;
   /*
	* The USB requires dTDs to be aligned on a 64 byte boundary.
	* In order to accomplish this, the data is over-allocated and
	* adjusted.
 	*/
	mallocAddress = (uint32_t)malloc(sizeof(usbdEndpointDtd_t)*2 - 1);
    usbDtd = (usbdEndpointDtd_t *)((mallocAddress + 32) & 0xFFFFFFE0);	// Align on 64-byte boundary

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

