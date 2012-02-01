/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
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

/********************************************************************/
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

typedef struct usb_module
{
	int8_t              *moduleName;
	usbRegisters_t      *moduleBaseAddress;
	enum usbController  controllerID;
	enum usbPhyType     phyType;				              // UTMI, ULPI, Serial, HSIC
} usb_module_t;

typedef enum usbPeriodicListType {
	listTypeIsochronous = 0,
	listTypeQueueHead,
	listTypeSplitTransaction,
	listTypeFrameSpan
} usbPeriodicListType_t;

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
	uint32_t mallocPointer;	/* Used to keep track of the
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
	uint32_t mallocPointer;	/* Used to keep track of the unaligned
						   memory allocated for the data structure */

} usbhTransferDescriptor_t;

/*!
 * Descriptor definitions
 */

typedef struct usbDeviceDescriptor {
	uint8_t		bLength;
	uint8_t		bDescriptorType;
	uint16_t	bcdUSB;
	uint8_t		bDeviceClass;
	uint8_t		bDeviceSubClass;
	uint8_t		bDeviceProtocol;
	uint8_t     bMaxPacketSize;
	uint16_t	idVendor;
	uint16_t    idProduct;
	uint16_t    bcdDevice;
	uint8_t     iManufacturer;
	uint8_t     iSerialNumber;
	uint8_t     bNumConfigurations;
} usbDeviceDescriptor_t;



/* function prototypes */
int usbh_init(usb_module_t *);
void usbh_bus_reset(usb_module_t *);
void get_setup_packet(usb_module_t *, uint32_t, uint32_t*, uint32_t*);
void usbh_enable_asynchronous_schedule(usb_module_t *port);
void usbh_disable_asynchronous_schedule(usb_module_t *port);
usbPortSpeed_t usbh_get_port_speed(usb_module_t *);
uint32_t usbh_periodic_schedule_init(usb_module_t *, uint32_t frame_list_size, uint32_t *frame_list);
int swap32(int);
usbhTransferDescriptor_t * usbh_qtd_init(uint32_t, uint32_t, uint32_t, uint32_t*);
usbhQueueHead_t * usbh_qh_init(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

int usbEnableClocks(usb_module_t *port);
int usbEnableTransceiver(usb_module_t *port);
void usbEnableVbus(usb_module_t *port);
void usbDisableVbus(usb_module_t *port);

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

#define USB_UTMI_PHY 1
#define USB_ULPI_PHY 2
#define USB_SERIAL_PHY 3


/* Use USB interrupt i/o polling */

#endif	/* _USB_H */

