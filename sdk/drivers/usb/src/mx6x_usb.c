/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file mx6x_usb.c
 * @brief i.MX6x specific USB routines.
 *
 * The functions in this file are implementation specific routines, like USB transceiver, PLL, clocks etc.\n
 * Each supported i.MX device has a dedicated set of routines.\n
 * The routines are referenced in the usb_module structure.
 * 
 * @ingroup diag_usb
 */

#include "hardware.h"
#include "usb_regs.h"
#include "registers/regsccm.h"
#include "registers/regsccmanalog.h"

/*!
 * This function enables the clocks needed for USB operation.
 * @param port
 * @return
 */
int usbEnableClocks(usb_module_t * port)
{

    multiAccess_t *usbPllControl;

    /*!
     * Enable the USB clock for the controller
     */

//     *(volatile uint32_t *)(CCM_CCGR6) |= 0x00000003;
    HW_CCM_CCGR6.B.CG0 = 3;

    /*!
     * Enable the PLL\n
     * OTG, Host2 and Host3 controllers use USB_PLL0
     * Host1 controller uses USB_PLL1
     */

    switch (port->controllerID) {
    case OTG:                  // OTG, Host2 and Host3 use the same PLL
    case Host2:
    case Host3:
        usbPllControl = (multiAccess_t *) (HW_CCM_ANALOG_PLL_USB1_ADDR);
        break;
    case Host1:
        usbPllControl = (multiAccess_t *) (HW_CCM_ANALOG_PLL_USB2_ADDR);
        break;
    default:
        return (-1);
    }

    usbPllControl->SET = USBPLL_CTRL_POWER; //! - Turn PLL power on.
	usbPllControl->SET = USBPLL_CTRL_EN_USB_CLKS;	//!Powers the 9-phase PLL outputs for USBPHY0
    while (!(usbPllControl->RW & USBPLL_CTRL_LOCK)) ;   //! - Wait for PLL to lock
    usbPllControl->CLEAR = USBPLL_CTRL_BYPASS;  //! - Clear bypass
    usbPllControl->SET = USBPLL_CTRL_ENABLE;    //! - Enable PLL clock output for the PHY
    return (0);
}

/*!
 * Enable USB transceiver\n
 * This function enables the USB transceiver for the selected USB port.
 *
 * @param port      USB module to initialize
 */
int usbEnableTransceiver(usb_module_t * port)
{

    usbPhy_t *usbPhy;

    switch (port->controllerID) {
    case OTG:
        usbPhy = (usbPhy_t *) (IP2APB_USBPHY1_BASE_ADDR);   // Point register structure to USBPHY1
        break;
    case Host1:
        usbPhy = (usbPhy_t *) (IP2APB_USBPHY2_BASE_ADDR);   // Point register structure to USBPHY2
        break;
    default:
        return -1;
    }
    //! NOTE !! CLKGATE must be cleared before clearing power down
    usbPhy->USBPHY_CTRL.CLEAR = (USBPHY_CTRL_SFTRST);   //! - clear SFTRST
    usbPhy->USBPHY_CTRL.CLEAR = (USBPHY_CTRL_CLKGATE);  //! - clear CLKGATE
    usbPhy->USBPHY_PWD.RW = 0;  //! - clear all power down bits
    usbPhy->USBPHY_CTRL.SET = (3 << 14);
    usbPhy->USBPHY_CTRL.SET = (1 << 1); //! - Enable Host Disconnect

    //! disable the charger detector. This must be off during normal operation
    {
        // this register is not documented. Will be updated in the next release
        uint32_t *ChargerDetectControl;
        ChargerDetectControl = (uint32_t *) 0x020c81b0;
        *ChargerDetectControl |= 1 << 20;   // disable detector
    }

    //! Check if all power down bits are clear
    if (usbPhy->USBPHY_PWD.RW != 0)
        return -1;              // Phy still in power-down mode. Check if all clocks are running.
    else
        return 0;
}
