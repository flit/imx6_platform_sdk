/*
 * Copyright (c) 2010-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * This file contains the basic usb test routines which include a hub test and 
 * obtaining the device descriptor mounted on the usb bus.
 *
 */
#include <string.h>
#include "io.h"
#include "obds.h"
//#include "usb/usb_hub_class.h"
#include "registers/regsusbcore.h"
#include "registers/regsusbnoncore.h"
#include "registers/regsusbphy.h"

const char g_usb_otg_dev_enum_test_name[] = "USB OTG Device Enumeration Test";
const char g_usb_host1_dev_enum_test_name[] = "USB Host1 Device Enumeration Test";
const char g_usb_EHCI_test_modes_name[] = "Set EHCI Test Modes";

/*qh and td pointers defintion*/
usbhQueueHead_t *pQH = (usbhQueueHead_t *) QH_BUFFER;
usbhTransferDescriptor_t *pTD = (usbhTransferDescriptor_t *) TD_BUFFER;

/* function declaration*/
static void usbh_hub_usb251x_init(void);
static void usbh_hub_enumeration(usb_module_t *port);
static void usbh_dev_enumeration(usb_module_t *port);
void dump_usb_regs(unsigned int usb_controller_base_addr);

//External functions declaration for hub test
extern void reset_usb_hub(void);

extern void usbhub_get_hub_descriptor(usbhQueueHead_t *pQueueHeader,
                               usbhTransferDescriptor_t *pTransDesc,
                               uint8_t *buf, usb_module_t *port);

extern void usbhub_hub_set_port_feature(usbhQueueHead_t *pQueueHeader,
                                    usbhTransferDescriptor_t *pTransDesc,
                                    uint8_t bFeature, uint8_t hub_addr,
                                    uint8_t bPort, usb_module_t *port);

extern void usbhub_hub_clear_port_feature(usbhQueueHead_t *pQueueHeader,
                                          usbhTransferDescriptor_t *pTransDesc,
                                          uint8_t bFeature,uint8_t hub_addr, 
                                          uint8_t bPort, usb_module_t *port);

extern uint32_t usbhub_hub_get_port_status(usbhQueueHead_t *pQueueHeader,
                                         usbhTransferDescriptor_t *pTransDesc,
                                         uint8_t *buf, uint8_t hib_addr,
                                         uint8_t bPort, usb_module_t *port);

/*external function declaration*/
extern void usb0_host_testmodes_test(usb_module_t *port);

extern void usbh_get_dev_desc(usb_module_t *, usbhQueueHead_t *, usbDeviceDescriptor_t *);
extern void usbh_get_config_desc(usb_module_t *, usbhQueueHead_t *, uint8_t *);
extern void usbh_set_device_address(usb_module_t *port, usbhQueueHead_t *usb_qh_ep0, uint32_t device_address);
extern void usbh_set_configuration(usb_module_t *port, usbhQueueHead_t * usb_qh_ep0, uint32_t config_value);
extern uint16_t usbh_get_device_status(usbhQueueHead_t *pQueueHeader, 
                           usbhTransferDescriptor_t *pTransDesc, 
                           uint8_t * buf, uint8_t dev_addr,
                           usb_module_t *port);

uint8_t buffer[0x100] __attribute__ ((aligned(4)));
static int failCount = 0;

#define VID_LOW_VALUE   0x24    /* Vendor ID low value */
#define VID_HIGH_VALUE   0x04   /* Vendor ID high value */
#define PID_LOW_VALUE   0x06    /* Product ID low value */
#define PID_HIGH_VALUE  0x00    /* Product ID high value */

/*!
  * Wait delay function
  */
void Wait100Ms(void)
{
    hal_delay_us(100000);
}

/*!
 * USB hub 251x init and enumeration function
 * @param usb_base_addr      base address of desired usb module under test
 */
static void usbh_hub_usb251x_init(void)
{
    // Reset the HUB device, function in hardware.c 
    reset_usb_hub();

    Wait100Ms();
}

//static void usbh_hub_enumeration(u32 usb_base_addr)
static void usbh_hub_enumeration(usb_module_t *port)
{
    usbDeviceDescriptor_t dev_descriptor;
    usbConfigurationDescriptor_t config_descriptor;
    usbInterfaceDescriptor_t if_descriptor[2];
    usbEndpointDescriptor_t ep_descriptor[2];
    usb_hub_descriptor_t hub_descriptor;

    uint32_t i, temp, stride;
//c    uint32_t dev_status, port_status, hub_addr = 0;
    uint32_t hub_port_num = 0, if_num = 0, ep_num = 0;

    memset((void *)&dev_descriptor, 0, sizeof(usbDeviceDescriptor_t));
    memset((void *)&config_descriptor, 0, sizeof(usbConfigurationDescriptor_t));
    memset((void *)&if_descriptor, 0, 2 * sizeof(usbInterfaceDescriptor_t));
    memset((void *)&ep_descriptor, 0, 2 * sizeof(usbEndpointDescriptor_t));
    memset((void *)&hub_descriptor, 0, sizeof(usb_hub_descriptor_t));

    printf("Test - USB Hub SMSC251x enumeration: \n");
    //Standard - Get Device Descriptor 
//    usbh_get_device_descriptor(pQH, pTD, buffer, usb_base_addr);
//    memcpy((void *)&dev_descriptor, (void *)buffer, sizeof(usbDeviceDescriptor_t));

    usbh_get_dev_desc(port, pQH, &dev_descriptor);

    if ((dev_descriptor.bDeviceClass == CLASS_CODE_HUB)
        && (dev_descriptor.bDescriptorType == DEVICE_DESCRIPTOR)) {
        printf("Device Descriptor : \n");
        printf("   bcdUSB             : 0x%02X\n", dev_descriptor.bcdUSB);
        printf("   bDeviceClass       : 0x%02X\n", dev_descriptor.bDeviceClass);
        printf("   bDeviceSubClass    : 0x%02X\n", dev_descriptor.bDeviceSubClass);
        printf("   bDeviceProtocol    : 0x%02X\n", dev_descriptor.bDeviceProtocol);
        printf("   bMaxPacketSize     : 0x%02X\n", dev_descriptor.bMaxPacketSize);
        printf("   idVendor           : 0x%04X\n", dev_descriptor.idVendor);
        printf("   idProduct          : 0x%04X\n", dev_descriptor.idProduct);
        printf("   bcdDevice          : 0x%04X\n", dev_descriptor.bcdDevice);
        printf("   iManufacturer      : %d\n", dev_descriptor.iManufacturer);
        printf("   iProduct           : %d\n", dev_descriptor.iProduct);
        printf("   iSerialNumber      : %d\n", dev_descriptor.iSerialNumber);
        printf("   bNumConfigurations : %d\n", dev_descriptor.bNumConfigurations);
    } else {
        printf("It's not a hub\n");
        printf("Device Class    : 0x%02X\n", dev_descriptor.bDeviceClass);
        failCount++;
        return;
    }

    // Standard - Get Config Descriptor 
//    usbh_get_config_descriptor(pQH, pTD, buffer, usb_base_addr);
//    memcpy((void *)&conf_descriptor, (void *)buffer, sizeof(usb_config_descriptor_t));

    usbh_get_config_desc(port, pQH, (uint8_t*)&config_descriptor); 
    memcpy((void *)buffer, (void *)&config_descriptor, sizeof(usbConfigurationDescriptor_t));

    if (config_descriptor.bDescriptorType == CONFIG_DESCRIPTOR) {
        //parsing the config desc
        temp = config_descriptor.wTotalLength;
        stride = config_descriptor.bLength;
        while ((stride < temp) && (*(buffer + stride + 1))) {
            switch (*(buffer + stride + 1)) {
            case (INTERFACE_DESCRIPTOR):
                memcpy((void *)&if_descriptor[if_num], (void *)(buffer + stride),
                       sizeof(usbInterfaceDescriptor_t));
                stride += if_descriptor[if_num].bLength;
                if_num++;
                break;

            case (ENDPOINT_DESCRIPTOR):
                memcpy((void *)&ep_descriptor[ep_num], (void *)(buffer + stride),
                       sizeof(usbEndpointDescriptor_t));
                stride += ep_descriptor[ep_num].bLength;
                ep_num++;
                break;
            default:
                stride += *(buffer + stride + 1);
                break;
            }
        }

    } else {
        printf("get config descriptor error\n");
        failCount++;
        return;
    }
/*c
    //Hub Class - Get HUB Descriptor 
    usbhub_get_hub_descriptor(pQH, pTD, buffer, port);
    memcpy((void *)&hub_descriptor, (void *)buffer, sizeof(usb_hub_descriptor_t));
    if (hub_descriptor.bDescriptorType == 0x29) {
        hub_port_num = hub_descriptor.bNbrPorts;
        printf("HUB supported downstream ports number : %d\n", hub_port_num);
    } else {
        printf("get hub descriptor error\n");
        failCount++;
        return;
    }

    // Standard - Set Address to Hub 
    hub_addr = 1;
    usbh_set_device_address(port, pQH, hub_addr);

    //Standard - Get Device Status 
    dev_status = usbh_get_device_status(pQH, pTD, buffer, hub_addr, port);
    //dev_status = *((uint32_t *)buffer);

    // Standard - Set Configuration 
    usbh_set_configuration(port, pQH, (uint32_t)(config_descriptor.bConfigurationValue));

    printf("Hub reset all ports to identify attached devices, please wait...\n");
    // Hub Class - SetPortFeature(PORT_POWER) 
    for (i = 1; i <= hub_port_num; i++) {
        usbhub_hub_set_port_feature(pQH, pTD, HUB_CLASS_FEATURE_SELECTOR_PORT_POWER, ((uint8_t)hub_addr), ((uint8_t) i), port);
    }
    // Hub Class - ClearPortFeature(C_PORT_CONNECTION) 
    for (i = 1; i <= hub_port_num; i++) {
        usbhub_hub_clear_port_feature(pQH, pTD, HUB_CLASS_FEATURE_SELECTOR_C_PORT_CONNECTION,
                                      hub_addr, i, port);    
    }

    //Hub Class - Get Port Status 
    for (i = 1; i <= hub_port_num; i++) {
        port_status = usbhub_hub_get_port_status(pQH, pTD, buffer, hub_addr, i, port);

        if (port_status & HUB_PORT_STATUS_DEVICE_PRESENT) {
            printf("+ Found device on hub port %d\n", i);
            break;
        }
    }
*///c
    if (i > hub_port_num) {
        printf("+ Found no device on hub port 1-%d\n", hub_port_num);
        return;
    }
/*c
    usbhub_hub_get_port_status(pQH, pTD, buffer, hub_addr, i, port);
    //reset portX where a device is attached 
    // Hub Class - SetPortFeature(PORT_RESET) 
    usbhub_hub_set_port_feature(pQH, pTD, HUB_CLASS_FEATURE_SELECTOR_PORT_RESET, hub_addr, i, port);
    // Hub Class - GetPortStatus 
    do {
        port_status = usbhub_hub_get_port_status(pQH, pTD, buffer, hub_addr, i, port);
    } while (!(port_status & HUB_PORT_CHANGE_PORT_RESET_COMPLETE));
    //Hub Class - ClearPortFeature(C_PORT_RESET) 
    usbhub_hub_clear_port_feature(pQH, pTD, HUB_CLASS_FEATURE_SELECTOR_C_PORT_RESET, hub_addr, i, port);
    do {
        port_status = usbhub_hub_get_port_status(pQH, pTD, buffer, hub_addr, i, port);
    } while ((port_status & HUB_PORT_CHANGE_PORT_RESET_COMPLETE));
*///c
    // After reset, the device should be at default state, and wait to be enumerated 
    // Start to enumerate the device on portX 
    memset((void *)&dev_descriptor, 0, sizeof(usbDeviceDescriptor_t));
    // Standard - Get Device Descriptor 
    usbh_get_dev_desc(port, pQH, &dev_descriptor);
    if (dev_descriptor.bDescriptorType == DEVICE_DESCRIPTOR) {
        printf("Device Descriptor : \n");
        printf("   bcdUSB             : 0x%02X\n", dev_descriptor.bcdUSB);
        printf("   bDeviceClass       : 0x%02X\n", dev_descriptor.bDeviceClass);
        printf("   bDeviceSubClass    : 0x%02X\n", dev_descriptor.bDeviceSubClass);
        printf("   bDeviceProtocol    : 0x%02X\n", dev_descriptor.bDeviceProtocol);
        printf("   bMaxPacketSize    : 0x%02X\n", dev_descriptor.bMaxPacketSize);
        printf("   idVendor           : 0x%04X\n", dev_descriptor.idVendor);
        printf("   idProduct          : 0x%04X\n", dev_descriptor.idProduct);
        printf("   bcdDevice          : 0x%04X\n", dev_descriptor.bcdDevice);
        printf("   iManufacturer      : %d\n", dev_descriptor.iManufacturer);
        printf("   iProduct           : %d\n", dev_descriptor.iProduct);
        printf("   iSerialNumber      : %d\n", dev_descriptor.iSerialNumber);
        printf("   bNumConfigurations : %d\n", dev_descriptor.bNumConfigurations);
    } else {
        printf("It's not a valid device descriptor\n");
        printf("Device Class    : 0x%02X\n", dev_descriptor.bDeviceClass);
        failCount++;
        return;
    }
}

/*!
 * USB dev enumeration function
 * @param usb_base_addr      base address of desired usb module under test
 */
//static void usbh_dev_enumeration(u32 usb_base_addr)
static void usbh_dev_enumeration(usb_module_t *port)
{
    usbDeviceDescriptor_t dev_descriptor;
    //usb_config_descriptor_t conf_descriptor;
    //usb_interface_descriptor_t if_descriptor[2];
    //usb_endpoint_descriptor_t ep_descriptor[2];
    //usb_hub_descriptor_t hub_descriptor;

    memset((void *)&dev_descriptor, 0, sizeof(usbDeviceDescriptor_t));
    //memset((void*)&conf_descriptor,0,sizeof(usb_config_descriptor_t));
    //memset((void*)if_descriptor,0,2*sizeof(usb_interface_descriptor_t));
    //memset((void*)ep_descriptor,0,2*sizeof(usb_endpoint_descriptor_t));
    //memset((void*)&hub_descriptor,0,sizeof(usb_hub_descriptor_t));

    printf("Test - device enumeration: \n");
    /*Standard - Get Device Descriptor */
//    usbh_get_device_descriptor(pQH, pTD, buffer, usb_base_addr);
    usbh_get_dev_desc(port, pQH, &dev_descriptor);

//    memcpy((void *)&dev_descriptor, (void *)buffer, sizeof(usb_device_descriptor_t));

    if (dev_descriptor.bDescriptorType == DEVICE_DESCRIPTOR) {
        printf("Device Descriptor : \n");
        printf("   bcdUSB             : 0x%02X\n", dev_descriptor.bcdUSB);
        printf("   bDeviceClass       : 0x%02X\n", dev_descriptor.bDeviceClass);
        printf("   bDeviceSubClass    : 0x%02X\n", dev_descriptor.bDeviceSubClass);
        printf("   bDeviceProtocol    : 0x%02X\n", dev_descriptor.bDeviceProtocol);
        printf("   bMaxPacketSize     : 0x%02X\n", dev_descriptor.bMaxPacketSize);
        printf("   idVendor           : 0x%04X\n", dev_descriptor.idVendor);
        printf("   idProduct          : 0x%04X\n", dev_descriptor.idProduct);
        printf("   bcdDevice          : 0x%04X\n", dev_descriptor.bcdDevice);
        printf("   iManufacturer      : %d\n", dev_descriptor.iManufacturer);
        printf("   iProduct           : %d\n", dev_descriptor.iProduct);
        printf("   iSerialNumber      : %d\n", dev_descriptor.iSerialNumber);
        printf("   bNumConfigurations : %d\n", dev_descriptor.bNumConfigurations);
    } else {
        printf("can't enumerate the attached device\n");
        failCount++;
        return;
    }
}

int usbh_EHCI_test_mode_test_enable;
uint32_t usbh_EHCI_test_mode_base;
/*!
 * USB EHCI test mode setup  
 * This allows to enable the ECHI test modes in the controller
 * these modes allow for measuring the eye diagram and other parameters
 * @param 			none
 *
 * @return          always 0 (success)
 */
int EHCI_test_mode(void)
{

    static char *ehci_controller_menu[] = {
        "OTG controller",
        "Host1 controller",
        ""
    };

/*    static char *ehci_test_menu[] = {
        "normal mode",
        "Test_J",
        "Test_K",
        "Test_SE0/NAK",
        "Test_packet",
        "Suspend",
        "Resume",
        "Reset",
        "Exit EHCI test",
        ""                      //Empty string is end of menu table 
    };
*/
    //Add this variable to meet SDK functions
    usb_module_t usbModuleInfo, *usbport;
    int controller;

    usbport = &usbModuleInfo;

    /*initialize the USB host controller */
    controller = -1;
    while (controller == -1) {
        controller = get_menu_item(ehci_controller_menu);
        switch (controller) {
        case 0:
            usbport->moduleName = "OTG controller";
//c            usbport->moduleBaseAddress = (usbRegisters_t *)(usbh_EHCI_test_mode_base);
            usbport->controllerID = OTG;
            usbport->phyType = Utmi; 
            break;
        case 1:
            usbport->moduleName = "Host1 controller";
//c            usbport->moduleBaseAddress = (usbRegisters_t *)(usbh_EHCI_test_mode_base + 0x200);
            usbport->controllerID = Host1;
            usbport->phyType = Utmi;

            break;
        default:
            printf("Invalid controller selection\n");   // should never get to this point
            controller = -1;
            break;
        }
    }

    usb0_host_testmodes_test(usbport);
    return TEST_PASSED;

}

int usbh_dev_enum_test_enable;
uint32_t usbh_dev_enum_test_base;
/*!
 * USB device enumeration test  
 * This tests the usb host interface and enumerates a usb device
 * @param usb_base_addr      base address of desired usb module under test
 *
 * @return          0 on success; non-zero otherwise
 */
int usbh_dev_enum_test(void)
{

    usb_module_t usbModuleInfo, *usbport;
printf("usbh_dev_enum func\n");
    usbport = &usbModuleInfo;
    usbport->moduleName = "Host1 controller";
//c    usbport->moduleBaseAddress = (usbRegisters_t*) usbh_dev_enum_test_base;
    usbport->controllerID = Host1;
    usbport->phyType = Utmi;

    printf("\nRun the USBH1 device enumeration test? Make sure plug in a USB device!\n");
    if (!is_input_char('y', NULL)) {
        return TEST_BYPASSED;
    }

    failCount = 0;
    /*initialize the USB host */
    usbh_init(usbport);
    printf("usbh_init completed.\n");

#if defined(CHIP_MX6SL)
    dump_usb_regs(HW_USBC_UOG2_ID_ADDR);
#endif
    /*request the device descriptor of attached device */
    usbh_dev_enumeration(usbport);

    if (failCount == 0) {
        TEST_EXIT("PASSED");
        return TEST_PASSED;
    } else {
        TEST_EXIT("FAILED");
        return TEST_FAILED;
    }
}

//RUN_TEST("USBH1 Enum", usbh_dev_enum_test)

void dump_usb_regs(unsigned int usb_controller_base_addr)
{
#if defined(CHIP_MX6SL)
	char usb_controller_string[32] = {0};
	char usb_phy_string[32] = {0};
	unsigned int usb_phy_base_addr = 0;

	switch(usb_controller_base_addr)
	{
		case HW_USBC_UOG1_ID_ADDR:
			sprintf(usb_controller_string, "OTG1");
			sprintf(usb_phy_string, "PHY1");
			usb_phy_base_addr = REGS_USBPHY1_BASE;
			break;
		case HW_USBC_UOG2_ID_ADDR:
			sprintf(usb_controller_string, "OTG2");
			sprintf(usb_phy_string, "PHY2");
			usb_phy_base_addr = REGS_USBPHY2_BASE;
			break;
		case HW_USBC_UH1_ID_ADDR:
			sprintf(usb_controller_string, "HOST1");
			sprintf(usb_phy_string, "PHY2");
			usb_phy_base_addr = REGS_USBPHY2_BASE;
			break;
		default:
			sprintf(usb_controller_string, "UNKNOWN");
			sprintf(usb_phy_string, "UNKNOWN");
			break;
	}

	unsigned int addr = 0;

	printf("\nUSB %s Registers\n", usb_phy_string);
	for (addr = usb_phy_base_addr; addr <= usb_phy_base_addr + 0x80; addr+=0x10 )
	{
		printf("%08X: %08X\n", addr, readl(addr));
	}

	printf("\nUSB %s Core Registers\n", usb_controller_string);
	for (addr = usb_controller_base_addr; addr <= usb_controller_base_addr + 0x1A8; addr+=4 )
	{
		printf("%08X: %08X\n", addr, readl(addr));
	}

	printf("\nUSB Non-Core Registers\n");
	for (addr = HW_USBNC_USB_OTG1_CTRL_ADDR; addr <= HW_USBNC_USB_OTG2_PHY_CTRL_0_ADDR; addr+=4 )
	{
		printf("%08X: %08X\n", addr, readl(addr));
	}
	printf("\n");
#endif
}

/*!
 * USB device enumeration test
 * This tests the usb OTG interface and enumerates a usb device
 * @param usb_base_addr      base address of desired usb module under test
 *
 * @return          TEST_PASS or TEST_FAILED
 */
test_return_t usbo_dev_enum_test(void)
{
    const char* indent = menu_get_indent();

    usb_module_t usbModuleInfo, *usbport;
    usbport = &usbModuleInfo;
    usbport->moduleName = "";
//c    usbport->moduleBaseAddress = (usbRegisters_t *) REGS_USBC_BASE;
    usbport->controllerID = OTG;
    usbport->phyType = Utmi;
    
    printf("%sIs there a USB OTG device connected to the OTG port?\n", indent);
    if (!is_input_char('y', indent))
        return TEST_BYPASSED;

#if defined(CHIP_MX6SL)
    dump_usb_regs(HW_USBC_UOG1_ID_ADDR);
#endif
    failCount = 0;
    /*initialize the USB host */
    usbh_init(usbport);
    /*request the device descriptor of attached device */
printf("pass USBH init, then enumeration\n");

    usbh_dev_enumeration(usbport);

    if (failCount == 0)
        return TEST_PASSED;
    else
        return TEST_FAILED;
}

int usbh_hub251x_test_enable;
uint32_t usbh_hub251x_test_base;
/*!
 * USB HUB251x test  
 * This tests the interface to the SMSC251x and enumerates the hub.
 * @param usb_base_addr      base address of desired usb module under test
 *
 * @return          0 on success; non-zero otherwise
 */
int usbh_hub251x_test(void)
{
    usb_module_t usbModuleInfo, *usbPort;

    usbPort = &usbModuleInfo;
    usbPort->moduleName = "Host1 controller";
//c    usbPort->moduleBaseAddress = (usbRegisters_t *)(usbh_hub251x_test_base);
    usbPort->controllerID = Host1;
    usbPort->phyType = Utmi;

    if (!usbh_hub251x_test_enable) {
        return TEST_NOT_PRESENT;
    }

    PROMPT_RUN_TEST("USBH HUB", NULL);
    // USB HUB test
    printf("\nWould you like to run the USBH1 HUB test?\n");
    if (!is_input_char('y', NULL)) {
        return TEST_BYPASSED;
    }
    failCount = 0;

    /*initialize usb hub */
    usbh_hub_usb251x_init();
    /*initialize the USB host */
    usbh_init(usbPort);
    /*hub enumeration & read sata device descriptor */
    usbh_hub_enumeration(usbPort);

    if (failCount == 0) {
        TEST_EXIT("PASSED");
        return TEST_PASSED;
    } else {
        TEST_EXIT("FAILED");
        return TEST_FAILED;
    }
}

//RUN_TEST("USBH1 HUB", usbh_hub251x_test)
