/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file usbh_drv.c
 * @brief USB host driver.
 *
 */

/*!
 * Initialize the USB for host operation. This initialization sets
 * up the USB host to detect a device connection.
 *
 * Parameters:
 * @param port      USB module to initialize
 */

#include "usb.h"
#include "usb_registers.h"
#include "usb_defines.h"

int usbh_init(usb_module_t *port)
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

	if(port->phyType == Ulpi)
	{
		port->moduleBaseAddress->USB_PORTSC &= (~(USB_PORTSC_PTS(3)));
		port->moduleBaseAddress->USB_PORTSC |= (USB_PORTSC_PTS(2));

	}
	else if(port->phyType == Utmi)
	{
		port->moduleBaseAddress->USB_PORTSC &= (~(USB_PORTSC_PTS(3)));
	}
	else if(port->phyType == Serial)
	{
		port->moduleBaseAddress->USB_PORTSC |= (USB_PORTSC_PTS(3));
	}
	else 
	{
	/* Invalid PHY type */
		return(-1);
	}
	
	//! Reset controller after switching PHY's
	port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_RST);
	
	//! wait for reset to complete
	while(port->moduleBaseAddress->USB_USBCMD & (USB_USBCMD_RST));

	//! set controller to host mode
	port->moduleBaseAddress->USB_USBMODE = (USB_USBMODE_CM_HOST);

	//! Set Asynchronous schedule park mode to 3
	//! to allow up to 3 successive transactions same queue.
	//! set interrupt interval to 0 for immediate interrupt
	port->moduleBaseAddress->USB_USBCMD = ( 0 | USB_USBCMD_ASP(3) | USB_USBCMD_ITC(0));
	

#ifdef USB_USE_INT		
	/* setup interrupt */
	usb_init_host_interrupts(port->moduleBaseAddress);
#endif

    //! start the controller
    //! the controller will start running but the schedules are not yet enabled.
	port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_RS);
	
	//! Enable port power.
	//! Port power must be set for port to detect a device connection
	port->moduleBaseAddress->USB_PORTSC |= (USB_PORTSC_PP);
	
	//! Enable Vbus power when Vbus power is controlled by GPIO
	//! On some board hardware, Vbus is not controlled by PortPower
	usbEnableVbus(port);
	
	return 0;
}



/*!
 * Initialize the periodic schedule. This function creates an empty
 * frame list for the periodic schedule, points the periodic base
 * address to the empty frame list, and enables the periodic schedule.
 *
 * @param port              USB module to initialize
 * @param frame_list_size   size of the frame list for the periodic schedule
 * @param frame_list        pointer to the start of the allocated frame list
 */
uint32_t usbh_periodic_schedule_init(struct usb_module *port, uint32_t frame_list_size, uint32_t * frame_list)
{
	int i;
	uint32_t periodic_base;

	//! Initialize the USBCMD register for the desired frame list size

 	//! Clear all FS bits before we start
 	port->moduleBaseAddress->USB_USBCMD &= ~(USB_USBCMD_FS_MASK);

 	//! Set the new size
	switch (frame_list_size)
	{ case 1024:
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_FS_1024);
	   	break;
	  case 512:
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_FS_512);
	   	break;
	  case 256:
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_FS_256);
	   	break;
	  case 128:
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_FS_128);
	   	break;
	  case 64:
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_FS_64);
	   	break;
	  case 32:
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_FS_32);
	   	break;
	  case 16:
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_FS_16);
	   	break;
	  case 8:
		port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_FS_8);
	   	break;
  	default:
  		// Invalid frame list size
		return (-1);
	    break;
	}
	
   /*!
	* The USB specification requires the frame list to be aligned on an 8Kbyte boundary.
 	*/

	//! Check if allocated frame list memory is aligned
	if((int)frame_list % (1024 * 4) != 0)
	{
		printf("Frame list not aligned on 4K boundary");
		return(-1);
	}

	/*!
	 * Fill the frame list with link pointers marked invalid
	 * since we don't have any traffic to send yet.
	 */
	periodic_base = (uint32_t)frame_list;

    for ( i=0; i<(frame_list_size); i++)
		*(frame_list++) = 1;
		
	//! Initialize the Periodic base address register
	port->moduleBaseAddress->USB_PERIODICLISTBASE = periodic_base;

	//! Enable the periodic schedule
	port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_PSE);
	
	//! Wait for periodic schedule to become enabled
	while (!(port->moduleBaseAddress->USB_USBSTS & (USB_USBSTS_PS)));
    
    #ifdef DEBUG_PRINT			
	   	printf("Periodic schedule is enabled.\n");
    #endif
    
    return periodic_base;
}

/*!
 * Issue a USB reset to the specified port.
 *
 * @param port      USB module to send reset
 */
void usbh_bus_reset(struct usb_module *port)
{
	//! Set Port Reset
	port->moduleBaseAddress->USB_PORTSC |= (USB_PORTSC_PR);
	#ifdef DEBUG_PRINT
		printf("Start reset.\n");
    	printf("PORTSC = 0x%08x\n",(port->moduleBaseAddress->USB_PORTSC));
    #endif
    
	//! Wait for reset to finish
	while (port->moduleBaseAddress->USB_PORTSC & (USB_PORTSC_PR));
	
    #ifdef DEBUG_PRINT			
		printf("USB reset complete.\n\n");							
	#endif							
}

/*!
 * Return the speed of the USB port.
 *
 * @param port  USB module to send reset
 */
usbPortSpeed_t usbh_get_port_speed(usb_module_t *port)
{

	//! Determine the speed we are connected at.
	//! This must be called after the bus reset
	switch ((port->moduleBaseAddress->USB_PORTSC) & USB_PORTSC_PSPD(0x3))
	{ case USB_PORTSC_PSPD_FULL:
		return usbSpeedFull;
		break;
	case USB_PORTSC_PSPD_LOW:
		return usbSpeedLow;
		break;
	case USB_PORTSC_PSPD_HIGH:
		return usbSpeedHigh;
		break;
	default:
		return usbSpeedUnknown;			// invalid port speed.
		break;
	}
}

/*!
 * Enable the asynchronous schedule
 */
void usbh_enable_asynchronous_schedule(usb_module_t *port)
{
    // Enable the Asynchronous schedule
	port->moduleBaseAddress->USB_USBCMD |= (USB_USBCMD_ASE);

	// Wait for asynchronous schedule to enable
	while (!(port->moduleBaseAddress->USB_USBSTS & (USB_USBSTS_AS)));
}

/*!
 * Disable the asynchronous schedule.
 *
 * @param port  USB module
 */
void usbh_disable_asynchronous_schedule(struct usb_module *port)
{
	//! Disable the asynchronous schedule */
	port->moduleBaseAddress->USB_USBCMD &= (~USB_USBCMD_ASE);
	
	//! Wait for asynchronous enable bit to clear */
	while (port->moduleBaseAddress->USB_USBCMD & (USB_USBCMD_ASE));
}

/*!
* Disable the   periodic lists.
*
* @param port  USB module
*/
void usbh_disable_Periodic_list (struct usb_module *port)
{
	//! Disable the periodic schedule */
	port->moduleBaseAddress->USB_USBCMD &= (~USB_USBCMD_PSE);
	
	//! Wait for periodic schedule enable bit to clear */
	while (port->moduleBaseAddress->USB_USBCMD & (USB_USBCMD_PSE));
}

/*!
 * Initialize the qTD.
 * This function initializes a transfer descriptor.
 * the next qTD and alternate next qTD pointers are initialized with the terminate bit set.
 *
 * @param transferSize   number of bytes to be transferred
 * @param ioc            interrupt on complete flag
 * @param pid            PID code for the transfer
 * @param bufferPointer  pointer to the data buffer
 */
usbhTransferDescriptor_t * usbh_qtd_init(uint32_t transferSize, uint32_t ioc, uint32_t pid, uint32_t *bufferPointer)
{
	uint32_t token;
	uint32_t bufferOffset;				// offset in first 4K buffer
	int remainingSize;             // remaining number of byte to allocate

	usbhTransferDescriptor_t  *usbhQtd;

	int memoryPointer;
	int i;

	/*!
	 * Allocate memory for the transfer descriptor
	 */
	memoryPointer = (int)malloc(sizeof(usbhTransferDescriptor_t) + 63); // over allocate to accommodate 64-byte alignment
	if(memoryPointer == 0)
	{
		return NULL;         // No memory available
	}

   /*!
	* Allign qTD on a 64 byte boundary.
 	*/
	if((memoryPointer % 64) != 0)
	{
			usbhQtd = (usbhTransferDescriptor_t *)((memoryPointer / 64 + 1) * 64);     // first 64-byte boundary within allocated memory
	}
	else
		usbhQtd = (usbhTransferDescriptor_t *)memoryPointer;

	usbhQtd->mallocPointer = memoryPointer;              // keep track of allocated memory

	//! Set terminate bit on all pointers
	usbhQtd->nextQtd = 0xDEAD0001;
	usbhQtd->alternateNextQtd = 0x1;
	
	//! Set the PID for the for the transaction
	switch (pid)
	{
		case SETUP_PID:
			token = USB_QTD_TOKEN_PID_SETUP;
			break;
		case OUT_PID:
			token = (USB_QTD_TOKEN_DT | USB_QTD_TOKEN_PID_OUT);
			break;
		case IN_PID:
			token = (USB_QTD_TOKEN_DT | USB_QTD_TOKEN_PID_IN);
			break;
	  	default:
	  		#ifdef DEBUG_PRINT
	  			printf("ERR!! Invalid PID\n");
	  		#endif
	  			return NULL;
		    break;
	}
  	
  	if (ioc)
  		token |= USB_QTD_TOKEN_IOC;         // Set interrupt on completion.
  	                                        // Note: Short packets will always interrupt!
  
  	usbhQtd->qtdToken = (token
  							| USB_QTD_TOKEN_TRANS_SIZE(transferSize)
  							| USB_QTD_TOKEN_CERR(0x3)
  							| USB_QTD_TOKEN_STAT_ACTIVE );
  							
  	//! allocate first buffer
	//! first qtd buffer holds data up to first 4K address boundary)
	usbhQtd->qtdBuffer[0] = (uint32_t) bufferPointer;
	bufferOffset = (uint32_t)bufferPointer % 4096;
	remainingSize = (int)(transferSize - (4096 - bufferOffset));

	//! assign remaining buffers
	//! All remaining buffers start at a 4K boundary

	for(i = 1; i < 5; i++)
	{
		if (remainingSize > 0)		// allocate next 4K
		{
			usbhQtd->qtdBuffer[i] = (uint32_t)bufferPointer + ((4096 * i) - bufferOffset);
			remainingSize -= 4096;
		}
		else
			usbhQtd->qtdBuffer[i] = 0;
	}
	if (remainingSize > 0){
	    free((void *)(usbhQtd->mallocPointer));
		usbhQtd = NULL;         // Error. transfer size exceeds maximum available size.
	}
	return usbhQtd;
}

/*!
 * Initialize the QH.
 * This function assumes the QH is the only one in the horizontal list so
 * the horizontal link pointer points to the queue head. This function
 * doesn't initialize the qTD pointer either. This must be done later. 
 *
 * Parameters:
 * @param max_packet maximum packet length for the endpoint
 * @param head       used to mark the QH as the first in the linked list (not used for interrupt QHs)
 * @param eps        end point speed
 * @param epnum      end point number
 * @param dev_addr   device address
 * @param smask      interrupt schedule mask (only used for periodic schedule QHs)
 */

usbhQueueHead_t * usbh_qh_init(uint32_t max_packet, uint32_t head, uint32_t eps, uint32_t epnum,
			uint32_t dev_addr, uint32_t smask)
{
	uint32_t token;
	uint32_t memoryPointer;
	usbhQueueHead_t *queueHead;
	int i;

   /*!
	* Allocate memory for the queue head.
	* over allocate to accommodate 64-byte alignment
 	*/
	memoryPointer = (uint32_t)malloc(sizeof(usbhQueueHead_t) + 63);
	if(memoryPointer == 0)
	{
		return NULL;         // No memory available
	}

   /*!
	* Align QH on a 64 byte boundary.
	*/
	if((memoryPointer % 64) != 0)
	{
		queueHead = (usbhQueueHead_t *)((memoryPointer / 64 + 1) * 64);     // first 64-byte boundary within allocated memory
	}
	else
		queueHead = (usbhQueueHead_t *)memoryPointer;

	queueHead->mallocPointer = memoryPointer;

	queueHead->queueHeadLinkPointer = (((uint32_t) queueHead)
								| USB_QH_LINK_PTR_TYP_QH
								| USB_QH_LINK_PTR_T  );
								
	//! Set endpoint speed
	switch (eps)
	{
		case EPS_FULL:
			token = USB_QH_EP_CHAR_EPS_FULL;
			break;
		case EPS_LOW:
			token = USB_QH_EP_CHAR_EPS_LOW;
			break;
		case EPS_HIGH:
			token = USB_QH_EP_CHAR_EPS_HIGH;
			break;
	  	default:
	  		#ifdef DEBUG_PRINT
	  			printf("ERR!! Invalid EPS\n");
	  		#endif
		    break;
	}
	
	if (head)
		token |= USB_QH_EP_CHAR_H;
  			  		
  	queueHead->endpointCharacteristics = ( token
  						 | USB_QH_EP_CHAR_MAX_PACKET(max_packet)
  						 | USB_QH_EP_CHAR_DTC
  						 | USB_QH_EP_CHAR_EP(epnum)
  						 | USB_QH_EP_CHAR_DEV_ADDR(dev_addr) );
		
    /* Set interrupt to occur every 8ms */
    queueHead->endpointCapabilities = (USB_QH_EP_CAP_MULT_ONE
    					| USB_QH_EP_CAP_UFRAME_SMASK(smask));
    
		
	queueHead->currentQtd = 0;
	queueHead->nextQtd = 1;					// Set terminate bit on Next qtd pointer
	queueHead->alternateNextQtd = 1;		// Set terminate bit on alternate next qtd pointer
	queueHead->qtdToken = 0;

	for(i = 0; i< 5; i++)              // Clear buffer pointers (for debug purposes)
	{
		queueHead->qtdBuffer[i] = 0;
	}
	return queueHead;
}
