/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file usb_test.c
 * @brief USB test.
 *
 * @ingroup diag_usb
 */

#include "sdk.h"
#include <stdio.h>

extern void usb0_host_test(usb_module_t *port);
extern void usb0_host_testmodes_test(usb_module_t *port);
extern void usb0_device_mouse_test(usb_module_t *port);

void usb_test(void) {
	int controller = -1, test = -1, b_menu_loop = 1, b_submenu_loop = 1;
	usb_module_t usbModuleInfo, *usbPort;

	static char *ehci_controller_menu[] = {
			"OTG controller",
			"Host1 controller",
			"Exit USB test",
			""
	};

	static char *select_test_menu[] = {
			"usb_host_test",
			"usb_host_testmode_test",
			"usb_device_mouse_test",
			"Exit to upper menu",
			"" };

	usbPort = &usbModuleInfo;

	while (b_menu_loop) {
		controller = get_menu_item(ehci_controller_menu);
		if(0 == controller) {
			// Initialize the OTG controller info structure.
			usbPort->moduleName = "OTG controller";
			usbPort->controllerID = OTG;
			usbPort->phyType = Utmi;
		}else if(1 == controller){
			// Initialize the Host1 controller info structure.
			usbPort->moduleName = "Host1 controller";
			usbPort->controllerID = Host1;
			usbPort->phyType = Utmi;
		}else{
			printf("Invalid controller selection\n"); // should never get to this point
			controller = -1;
			b_menu_loop = 0;
		}

		b_submenu_loop = 1;	
		while (b_submenu_loop) {
			test = get_menu_item(select_test_menu);
			if(0 == test) {
				printf("Running usb_host_test on %s", usbPort->moduleName);
				usb0_host_test(usbPort);
			}else if(1 == test){
				printf("Running usb_host_testmode_test on %s",
						usbPort->moduleName);
				usb0_host_testmodes_test(usbPort);
			}else if(2 == test){
				if (usbPort->controllerID == OTG) {
					printf("Running usb_device_mouse_test on %s",
							usbPort->moduleName);
					usb0_device_mouse_test(usbPort);
				} else {
					printf(
							"Invalid controller selection.\nOnly OTG controller can operate in device mode\n");
				}
			}else{
				b_submenu_loop = 0;
			}
		}
	}
}
