/*
 * File:    drive_tags.h
 *
 * Copyright (c) SigmaTel, Inc. All rights reserved.
 *
 * SigmaTel, Inc.
 * Proprietary & Confidential
 *
 * This source code and the algorithms implemented therein constitute
 * confidential information and may comprise trade secrets of SigmaTel, Inc.
 * or its associates, and any use thereof is subject to the terms and
 * conditions of the Confidential Disclosure Agreement pursual to which this
 * source code was originally received.
 */

#if !defined(_drive_tags_h_)
#define _drive_tags_h_

//! \name Drive tag definitions
//@{

//! \brief player drive tag.
#define DRIVE_TAG_STMPSYS_S             0x00
#define DRIVE_TAG_STMPSYS_S_INFO        ("Player Firmware Drive")

//! \brief UsbMscMtp drive tag, old name was DRIVE_TAG_USBMSC_S. 
#define DRIVE_TAG_HOSTLINK_S            0x01
#define DRIVE_TAG_HOSTLINK_S_INFO       ("Hostlink Firmware Drive")

//! \brief Primary player resource drive tag.
#define DRIVE_TAG_RESOURCE_BIN          0x02
#define DRIVE_TAG_RESOURCE_BIN_INFO     ("Primary Resource Drive")

//! \brief Backup player resource drive tag.
#define DRIVE_TAG_RESOURCE2_BIN         0x12
#define DRIVE_TAG_RESOURCE2_BIN_INFO    ("Backup Resource Drive")

//! \brief Master player resource drive tag.
#define DRIVE_TAG_RESOURCE_MASTER_BIN       0x22
#define DRIVE_TAG_RESOURCE_MASTER_BIN_INFO  ("Master Resource Drive")

//! \brief the host has 0x05 reserved for OTG drive.
#define DRIVE_TAG_OTGHOST_S             0x05
#define DRIVE_TAG_OTGHOST_S_INFO  	    ("USB OTG Drive")

//! \brief Internal data drive tag.
#define DRIVE_TAG_DATA                  0x00 // 0x0A
#define DRIVE_TAG_DATA_INFO  	        ("Public Data Drive")

//! \brief External data drive tag.
#define DRIVE_TAG_DATA_EXTERNAL         0x01 // 0x0D
#define DRIVE_TAG_DATA_EXTERNAL_INFO  	("External Media Data Drive")

//! \brief Hidden data drive tag for DRM information.
#define DRIVE_TAG_DATA_HIDDEN           0x02 // 0x0B
#define DRIVE_TAG_DATA_HIDDEN_INFO  	("Hidden Data Drive")

//! \brief Hidden data drive 2 tag for persistent settings.
#define DRIVE_TAG_DATA_HIDDEN_2         0x03 // 0x0C
#define DRIVE_TAG_DATA_HIDDEN_2_INFO  	("Second Hidden Data Drive")

//! \brief Primary player firmware drive tag.
#define DRIVE_TAG_BOOTMANAGER_S         0x50
#define DRIVE_TAG_BOOTMANAGER_S_INFO  	("Primary Firmware Drive")

//! \brief Backup player firmware drive tag.
#define DRIVE_TAG_BOOTMANAGER2_S        0x60
#define DRIVE_TAG_BOOTMANAGER2_S_INFO  	("Backup Firmware Drive")

//! \brief Master player firmware drive tag.
#define DRIVE_TAG_BOOTMANAGER_MASTER_S          0x70
#define DRIVE_TAG_BOOTMANAGER_MASTER_S_INFO  	("Master Firmware Drive")

//! \brief Bootlet firmware drive tag.
#define DRIVE_TAG_BOOTLET_S             0xa0
#define DRIVE_TAG_BOOTLET_S_INFO  	   ("Bootlet Firmware Drive")

//! \brief the host has 0xFF reserved for usbmsc.sb file used in recovery mode operation only.
#define DRIVE_TAG_UPDATER_S             0xFF
#define DRIVE_TAG_UPDATER_S_INFO  	    ("USB Recovery")

//@}

#endif // _drive_tags_h_
