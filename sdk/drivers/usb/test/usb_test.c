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
	int controller, test;
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
			"Exit menu",
			"" };

	usbPort = &usbModuleInfo;

	controller = -1;
	while (controller == -1) {
		controller = get_menu_item(ehci_controller_menu);
		switch (controller) {
		case 0:
			// Initialize the OTG controller info structure.
			usbPort->moduleName = "OTG controller";
			usbPort->controllerID = OTG;
			usbPort->phyType = Utmi;
			break;
		case 1:
			// Initialize the Host1 controller info structure.
			usbPort->moduleName = "Host1 controller";
			usbPort->controllerID = Host1;
			usbPort->phyType = Utmi;
			break;
		case 2:
			// Exit use test
			return;

		default:
			printf("Invalid controller selection\n"); // should never get to this point
			controller = -1;
			break;
		}

		test = -1;
		while (test == -1) {
			test = get_menu_item(select_test_menu);
			switch (test) {
			case 0:
				printf("Running usb_host_test on %s", usbPort->moduleName);
				usb0_host_test(usbPort);
				break;
			case 1:
				printf("Running usb_host_testmode_test on %s",
						usbPort->moduleName);
				usb0_host_testmodes_test(usbPort);
				break;
			case 2:
				if (usbPort->controllerID == OTG) {
					printf("Running usb_device_mouse_test on %s",
							usbPort->moduleName);
					usb0_device_mouse_test(usbPort);
				} else {
					printf(
							"Invalid controller selection.\nOnly OTG controller can operate in device mode\n");
				}
				break;
			case 3:
				return;
			}
		}
	}
}
