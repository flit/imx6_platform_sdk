/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file mx61_usb.c
 * @brief i.MX6x specific USB routines.
 *
 * The functions in this file address implementation specific handling like USB transceiver, PLL, clocks etc.
 * Each supported i.MX device has a dedicated set of routines.
 * The routines are referenced in the usb_module structure.
 */

#include "usb_regs.h"
#include "usb.h"
#include "hardware.h"
#include "imx_i2c.h"
#include "soc_memory_map.h"

int usbEnableClocks(usb_module_t *port)
{

	multiAccess_t *usbPllControl;


	/*!
	 * First enable the USB clock for the controller
	 */

    *(volatile uint32_t *)(CCM_CCGR6) |= 0x00000003;


	/*!
	 * Enable the PLL
	 * OTG, Host2 and Host3 controllers use USB_PLL0
	 * Host1 controller uses USB_PLL1
	 */

	switch (port->controllerID)
	{
	case OTG:											// OTG, Host2 and Host3 use the same PLL
	case Host2:
	case Host3:
		usbPllControl = (multiAccess_t *)(HW_ANADIG_USB1_PLL_480_CTRL_RW);
		break;
	case Host1:
		usbPllControl = (multiAccess_t *)(HW_ANADIG_USB2_PLL_480_CTRL_RW);
		break;
	default:
		return (-1);
	}

	usbPllControl->SET = USBPLL_CTRL_POWER;     		  // Turn power on.
    while (!(usbPllControl->RW & USBPLL_CTRL_LOCK));      // Wait for PLL to lock
    usbPllControl->CLEAR = USBPLL_CTRL_BYPASS;    	      // Clear bypass
    usbPllControl->SET = USBPLL_CTRL_ENABLE;      	      // Enable USB clocks
	return (0);
}

/*!
 * Enable USB transceiver
 * This function enables the USB transceiver for the selected USB port.
 */
int usbEnableTransceiver(usb_module_t *port)
{

	usbPhy_t *usbPhy;

	switch(port->controllerID)
	{
	case OTG:
		usbPhy = (usbPhy_t *)(IP2APB_USBPHY1_BASE_ADDR);     // Point register structure to USBPHY1
		break;
	case Host1:
		usbPhy = (usbPhy_t *)(IP2APB_USBPHY2_BASE_ADDR);     // Point register structure to USBPHY2
		break;
	default:
		break;
	}
    /* NOTE !! CLKGATE must be cleared before clearing power down */
    usbPhy->USBPHY_CTRL.CLEAR =   (USBPHY_CTRL_SFTRST);   // clear SFTRST
    usbPhy->USBPHY_CTRL.CLEAR = (USBPHY_CTRL_CLKGATE);    // clear CLKGATE
    usbPhy->USBPHY_PWD.RW = 0;                            // clear all power down bits
    usbPhy->USBPHY_CTRL.SET = (3 << 14);
    usbPhy->USBPHY_CTRL.SET = (1 << 1);                   // Enable Host Disconnect

    // Check if all power down bits are clear
    if(usbPhy->USBPHY_PWD.RW != 0 )
    	return -1;   // Phy still in power-down mode. Check if all clocks are running.
    else return 0;
}

/*!
 * This function enables Vbus for the given USB port
 * The procedure to enable Vbus depends on both the Chip and board hardware
 * This implementation is for the MX6q Sabre-AI board.
 */
void usbEnableVbus(usb_module_t *port)
{

	switch(port->controllerID)
	{
	case OTG:
		// Vbus control is on I2C port expander C1 for the ARD board.
		max7310_set_gpio_output(MAX7310_I2C_ID2, 1, 1);

		break;
	case Host1:
		// Vbus control is on I2C port expander B7 for the ARD board.
		max7310_set_gpio_output(MAX7310_I2C_ID1, 7, 1);

		break;
	case Host2:
	case Host3:
		// Nothing to be done here.
		break;
	default:
		// no such controller
		break;
	}
}

/*!
 * This function disables Vbus for the given USB port
 * The procedure to enable Vbus depends on both the Chip and board hardware
 * This implementation is for the MX6q Sabre-AI board
 */

void usbDisableVbus(usb_module_t *port)
{
	switch(port->controllerID)
	{
	case OTG:
		max7310_set_gpio_output(MAX7310_I2C_ID2, 1, 0);
		break;
	case Host1:
		max7310_set_gpio_output(MAX7310_I2C_ID1, 7, 0);
		break;
	case Host2:
	case Host3:
		// Nothing to be done here.
		break;
	default:
		// no such controller
		break;
	}
}

