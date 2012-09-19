/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
/*
 * File:		USB.h
 * Purpose:		USB definitions
 *
 * Notes:
 */

#ifndef _USB_H
#define _USB_H

#include "usb_defines.h"
#include "usb_registers.h"

enum usbController {
    OTG = 0,
    Host1,
    Host2,
    Host3
};

enum usbPhyType {
    Utmi,
    Ulpi,
    Serial,
    Hsic
};

typedef enum usbPortSpeed {
    usbSpeedUnknown,
    usbSpeedLow,
    usbSpeedFull,
    usbSpeedHigh
} usbPortSpeed_t;

typedef enum usbPeriodicListType {
    listTypeIsochronous = 0,
    listTypeQueueHead,
    listTypeSplitTransaction,
    listTypeFrameSpan
} usbPeriodicListType_t;

typedef struct usb_module {
    char *moduleName;
    usbRegisters_t *moduleBaseAddress;
    enum usbController controllerID;
    enum usbPhyType phyType;    // UTMI, ULPI, Serial, HSIC
} usb_module_t;

/*!
 *  usb host data structure definitions
 */

/* USB host queue head structure */
typedef struct usbhQueueHead {
    uint32_t queueHeadLinkPointer;
    uint32_t endpointCharacteristics;
    uint32_t endpointCapabilities;
    uint32_t currentQtd;
    uint32_t nextQtd;
    uint32_t alternateNextQtd;
    uint32_t qtdToken;
    uint32_t qtdBuffer[5];
    uint32_t mallocPointer;     /* Used to keep track of the
                                   memory block allocated for the data structure */
} usbhQueueHead_t;

/*!
 *  USB host queue element transfer descriptor
 */
typedef struct usbhTransferDescriptor {
    uint32_t nextQtd;
    uint32_t alternateNextQtd;
    uint32_t qtdToken;
    uint32_t qtdBuffer[5];
    uint32_t mallocPointer;     /* Used to keep track of the unaligned
                                   memory allocated for the data structure */

} usbhTransferDescriptor_t;

/*!
 * Protocol descriptor definitions
 */

typedef struct usbDeviceDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t iManufacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
} usbDeviceDescriptor_t;

typedef struct usbConfigurationDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
    uint8_t bNumInterfaces;
    uint8_t bConfigurationValue;
    uint8_t iConfiguration;
    uint8_t bmAttributes;
    uint8_t MaxPower;
} usbConfigurationDescriptor_t;

typedef struct usbInterfaceDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bInterfaceNumber;
    uint8_t bAlternateSetting;
    uint8_t bNumEndpoints;
    uint8_t bInterfaceClass;
    uint8_t bInterfaceSubClass;
    uint8_t bInterfaceProtocol;
    uint8_t iInterface;
} usbInterfaceDescriptor_t;

/* USB Descriptor Type */
#define DEVICE_DESCRIPTOR             0x1
#define CONFIG_DESCRIPTOR             0x2
#define STRING_DESCRIPTOR             0x3
#define INTERFACE_DESCRIPTOR          0x4
#define ENDPOINT_DESCRIPTOR           0x5
#define DEVICE_QUALIFIER_DESCRIPTOR   0x6
#define OTHER_SPEED_CONFIG_DESCRIPTOR 0x7
#define INTERFACE_POWER_DESCRIPTOR    0x8

//HID class interface descriptor definitions
#define CLASS_CODE_HID                     0x03
#define SUBCLASS_CODE_HID_NOSUBCLASS       0x00
#define SUBCLASS_CODE_HID_BOOT_INTERFACE   0x01
#define PROTOCOL_CODE_HID_NONE             0x00
#define PROTOCOL_CODE_HID_KEYBOARD         0x01
#define PROTOCOL_CODE_HID_MOUSE            0x02

//MSC class interface descriptor definitions
#define CLASS_CODE_MSC                     0x08
#define SUBCLASS_CODE_MSC_RBC              0x01 /*Reduced Block Commandds, typically for a flash device */
#define SUBCLASS_CODE_MSC_SFF8020          0x02 /*a CD/DVD device uses SFF-8020i or MMC-2 command blocks */
#define SUBCLASS_CODE_MSC_QIC              0x03 /*a tape device uses QIC-157 command blocks */
#define SUBCLASS_CODE_MSC_UFI              0x04 /*a floppy disk drive device */
#define SUBCLASS_CODE_MSC_SFF8070          0x05 /*a floppy disk drive device */
#define SUBCLASS_CODE_MSC_SCSI             0x06 /*SCSI transparent command set, popular in msc */
#define PROTOCOL_CODE_MSC_CBI00            0x00 /*for floppy device - with command completion interrupt */
#define PROTOCOL_CODE_MSC_CBI01            0x01 /*for floppy device - with no command completion interrupt */
#define PROTOCOL_CODE_MSC_BOT              0x50 /*Bulk-Only Transport, popular in msc */

//HUB class interface descriptor definitions
#define CLASS_CODE_HUB                     0x09
#define SUBCLASS_CODE_HUB                  0x00
#define PROTOCOL_CODE_HUB_NON_HIGHSPEED    0x00 /*for full/low speed hub */
#define PROTOCOL_CODE_HUB_MULTI_TT         0x02 /*multiple TT */
#define PROTOCOL_CODE_USB_SINGLE_TT        0x01 /*single TT */

typedef struct usbEndpointDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
} usbEndpointDescriptor_t;

typedef struct usbHidDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdHID;
    uint8_t bCountryCode;
    uint8_t bNumDescriptors;
    uint8_t bReportDescriptorType;
    uint8_t wDescriptorLength[2];   // !!!! Not aligned on 16-bit boundary  !!!
} usbHidDescriptor_t;

/*!
 * Device driver definitions
 */

/*!
 * USB device endpoint list
 */

typedef uint32_t endpointList_t[8];

/*
 * USB device setup packet
 */

typedef struct usbdSetupPacket {
    uint8_t bRequestType;
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
} usbdSetupPacket_t;

/*!
 *  USB device endpoint queue head structure
 */

typedef struct usbdDeviceEndpointQueueHead {
    uint32_t endpointCharacteristics;
    uint32_t currentDtd;
    uint32_t nextDtd;
    uint32_t dtdToken;
    uint32_t dtdBuffer[5];
    uint32_t reserved;
    usbdSetupPacket_t setupBuffer;
    uint32_t reserved1[4];
} usbdDeviceEndpointQueueHead_t;

typedef struct usbdEndpointPair {
    usbdDeviceEndpointQueueHead_t out;
    usbdDeviceEndpointQueueHead_t in;
} usbdEndpointPair_t;

/*
 *  USB device endpoint transfer descriptor
 */
typedef struct usbdEndpointDtd {
    uint32_t nextDtd;
    uint32_t dtdToken;
    uint32_t dtdBuffer[5];
    uint32_t mallocPointer;     /* Used to keep track of the memory allocated for the data structure */
} usbdEndpointDtd_t;

/*!
 * Endpoint characteristics
 */
typedef enum usbdEndpointDirection {
    IN,
    OUT
} usbdEndpointDirection_t;

typedef struct usbdEndpointInfo {
    usbPortSpeed_t Speed;
    uint32_t endpointNumber;
    usbdEndpointDirection_t endpointDirection;
    uint32_t mult;
    uint32_t maxPacketLength;
    bool interruptOnSetup;
} usbdEndpointInfo_t;

/*!
 * Definitions for Setup packet
 */

/* Defines for commands in setup packets */
#define GET_DESCRIPTOR				0x8006
#define SET_CONFIGURATION			0x0009
#define SET_IDLE					0x210A
#define GET_HID_CLASS_DESCRIPTOR	0x8106
#define SET_FEATURE					0x0003

//! Host driver function prototypes
int usbh_init(usb_module_t *);
void usbh_bus_reset(usb_module_t *);
void get_setup_packet(usb_module_t *, uint32_t, uint32_t *, uint32_t *);
void usbh_enable_asynchronous_schedule(usb_module_t * port);
void usbh_disable_asynchronous_schedule(usb_module_t * port);
uint32_t usbh_periodic_schedule_init(usb_module_t *, uint32_t frame_list_size,
                                     uint32_t * frame_list);
usbhTransferDescriptor_t *usbh_qtd_init(uint32_t, uint32_t, uint32_t, uint32_t *);
usbhQueueHead_t *usbh_qh_init(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
uint32_t swap32(uint32_t data);

//! device driver function prototypes
uint32_t usbd_device_init(usb_module_t * port, usbdEndpointPair_t * endpointList);
usbPortSpeed_t usbd_bus_reset(usb_module_t * port);
void usbd_get_setup_packet(usb_module_t * port, usbdEndpointPair_t * endpointList,
                           usbdSetupPacket_t * setupPacket);
void usbd_device_send_control_packet(usb_module_t * port, usbdEndpointPair_t * endpointList,
                                     uint8_t * buffer, uint32_t size);
void usbd_device_send_zero_len_packet(usb_module_t * port, usbdEndpointPair_t * endpointList,
                                      uint32_t endpoint);
void usbd_endpoint_qh_init(usbdEndpointPair_t * endpointList, usbdEndpointInfo_t * usbdEndpoint,
                           uint32_t nextDtd);
void usbd_add_dtd(usb_module_t * port, usbdEndpointPair_t * endpointList,
                  usbdEndpointInfo_t * usbdEndpoint, usbdEndpointDtd_t * new_dtd);
usbdEndpointDtd_t *usbd_dtd_init(uint32_t transferSize, uint32_t interruptOnComplete,
                                 uint32_t multOverride, uint32_t * bufferPointer);
usbdEndpointDtd_t *usbd_reclaim_dtd(usb_module_t * port, usbdEndpointPair_t * endpointList,
                                    usbdEndpointInfo_t * usbdEndpoint, usbdEndpointDtd_t * head);
void fillBuffer(uint32_t * buffer);

//! common prototypes

usbPortSpeed_t usb_get_port_speed(usb_module_t * port);
int usbEnableClocks(usb_module_t * port);
int usbEnableTransceiver(usb_module_t * port);
int get_menu_item(char *menu_table[]);

#define DTD_TERMINATE 0xDEAD001
#define QTD_TERMINATE 0xDEAD001
#define OUT_PID  0
#define IN_PID  1
#define SETUP_PID  2

#define EPS_FULL 0
#define EPS_LOW	1
#define EPS_HIGH 2

#define MAX_USB_BUFFER_SIZE 0x100
#define MAX_USB_DESC_SIZE 	0x40

#define MAX_QTD_TRANS_SIZE	0x5000
#define MAX_DTD_TRANS_SIZE	0x5000
#define MAX_QH_PACKET_SIZE	0x400

#endif /* _USB_H */
