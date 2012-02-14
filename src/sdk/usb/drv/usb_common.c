/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file usb_common.c
 * @brief USB common routines.
 */
/*! This routine returns the current speed of the port\n
 * This must be called after the bus reset is completed.
 *
 * @param	port			The usb controller
 * @return	usbPortSpeed	The operating speed full/high
 */

#include "usb.h"

usbPortSpeed_t usb_get_port_speed(usb_module_t *port)
{
	usbPortSpeed_t speed;


	/* Determine the speed we are connected at. */
		switch (port->moduleBaseAddress->USB_PORTSC & USB_PORTSC_PSPD(0x3))
		{ case USB_PORTSC_PSPD_FULL:
			speed = usbSpeedFull;
			printf("Connected at full-speed\n");
    		break;
  		case USB_PORTSC_PSPD_LOW:
  			speed = usbSpeedLow;
	  		printf("Connected at low-speed\n");
    		break;
  		case USB_PORTSC_PSPD_HIGH:
  			speed = usbSpeedHigh;
	  		printf("Connected at high-speed\n");
		    break;
	  	default:
	  		speed = usbSpeedUnknown;
	  		printf("Invalid port speed\n");
		    break;
		}
    	printf("PORTSC = 0x%08x\n", port->moduleBaseAddress->USB_PORTSC);

	return speed;
}

/*!
 * This routine performs a byte swap on a 32-bit word
 *
 * @param data
 * @return	Swapped data
 */
uint32_t swap32(uint32_t data)
{
	uint32_t temp = 0;

	temp  = (data & 0xff) << 24;
	temp |= ((data & 0xff00)<< 8);
	temp |= ((data & 0xff0000) >>8);
	temp |= ((data & 0xff000000) >> 24);

    return(temp);
}

