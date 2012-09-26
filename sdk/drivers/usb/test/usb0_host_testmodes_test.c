/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file usb0_host_testmodes_test.c
 * @brief Enabled EHCI test modes in host contoller
 *
 * This test allows for setting the EHCI test modes in any of the host controllers,\n
 * including the OTG controllers.\n
 * Tests and Controller can be selected via a terminal connected to the serial port.
 */

#include "usb/usb.h"
#include "soc_memory_map.h"
#include "registers.h"
#include "hardware.h"
#include <stdio.h>

int get_menu_item(char *menu_table[]);


void usb0_host_testmodes_test (usb_module_t	*usbPort)
{
	uint32_t core = (uint32_t)usbPort->controllerID;

    static char *ehci_test_menu[] = {
        "normal mode",
        "Test_J",
        "Test_K",
        "Test_SE0/NAK",
        "Test_packet",
        "Suspend",
        "Resume",
        "Reset",
        "Exit EHCI test",
        ""                      /* Empty string is end of menu table */
    };

    int test_mode;

	//! Initialize the USB host controller.
	usbh_init(usbPort);

    while (1) {
        /* request test mode */
        printf("Select EHCI test mode for measurement:\n\n");
        test_mode = get_menu_item(ehci_test_menu);

        if (test_mode == 8)
            return;				// exit test

        if (test_mode < 5) {
            //! Set EHCI test mode in PORTSC register
            printf(("\nSetting test mode %s\n"), ehci_test_menu[test_mode]);
		HW_USBC_PORTSC1_WR(core, (HW_USBC_PORTSC1_RD(core) & (~BM_USBC_UH1_PORTSC1_PTC)) 
					| BF_USBC_UH1_PORTSC1_PTC(test_mode));
        } else {
            //! The following are not EHCI test modes, but useful for compliance measurements.
            switch (test_mode) {
            case 5:            //! - Suspend
		HW_USBC_PORTSC1_WR(core, HW_USBC_PORTSC1_RD(core) | BM_USBC_UH1_PORTSC1_SUSP);
                break;
            case 6:            //! - Resume
		HW_USBC_PORTSC1_WR(core, HW_USBC_PORTSC1_RD(core) | BM_USBC_UH1_PORTSC1_FPR);
                break;
            case 7:            //! - reset
		HW_USBC_PORTSC1_WR(core, HW_USBC_PORTSC1_RD(core) | BM_USBC_UH1_PORTSC1_PR);
                break;
            }
        }
    }
}


