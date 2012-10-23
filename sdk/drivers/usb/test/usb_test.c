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
#ifdef CHIP_MX6SL
			"OTG controller1",
			"OTG controller2",
#else
			"OTG controller",
			"Host1 controller",
#endif
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
#ifdef CHIP_MX6SL
			usbPort->moduleName = "OTG controller1";
			usbPort->controllerID = OTG1;
#else
			usbPort->moduleName = "OTG controller";
			usbPort->controllerID = OTG;
#endif
			usbPort->phyType = Utmi;
		}else if(1 == controller){
#ifdef CHIP_MX6SL
			usbPort->moduleName = "OTG controller2";
			usbPort->controllerID = OTG2;
#else
			usbPort->moduleName = "Host1 controller";
			usbPort->controllerID = Host1;
#endif
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
				printf("Running usb_host_test on %s\n", usbPort->moduleName);
				usb0_host_test(usbPort);
			}else if(1 == test){
				printf("Running usb_host_testmode_test on %s\n",
						usbPort->moduleName);
				usb0_host_testmodes_test(usbPort);
			}else if(2 == test){
#ifndef CHIP_MX6SL
				if (usbPort->controllerID = OTG) {
#else
				if ((usbPort->controllerID = OTG1) || (usbPort->controllerID = OTG2)) {
#endif
					printf("Running usb_device_mouse_test on %s\n",
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
