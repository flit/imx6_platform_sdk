/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef _SMBUS_H_
#define _SMBUS_H_
#include "hardware.h"
#include "io.h"

////////////////////////////////////////////////////////////
//         Macro Defintions                               //
////////////////////////////////////////////////////////////
#define SMBUS_DEVICE_DEFAULT_ADDRESS  0x61  /*Need to left shift one bit */

////////////////////////////////////////////////////////////
//         Data Structures                                //
////////////////////////////////////////////////////////////
enum SMBUS_COMMAND_SET {
    SMBUS_CMD_PREPARE_TO_ARP = 0x01,
    SMBUS_CMD_RESET_DEVICE_GENERAL = 0x02,
    SMBUS_CMD_GET_UDID_GENERAL = 0x03,
    SMBUS_CMD_ASSIGN_ADDRESS = 0x04,
};

enum SMBUS_DIR {
    SMBUS_WRITE = 0,
    SMBUS_READ,
};
typedef struct SMBUS_DEVICE_UDID {
    uint8_t devcap;                  /*Device Capabilities */
    uint8_t ver;                     /*Version or Revision */
    uint16_t vid;                    /*Vendor ID */
    uint16_t pid;                    /*Device ID */
    uint16_t interface;              /*Interface */
    uint16_t subvid;                 /*Subsystem Vendor ID */
    uint16_t subpid;                 /*Subsystem Device ID */
    uint32_t specid;                 /*Vendor Specific ID */
} smbus_device_udid_t;
/*Address Type - Bit[7:6] in device capabilities field*/
#define ADDR_TYPE_FIXED_ADDRESS               0x0
#define ADDR_TYPE_DYNAMIC_PERSISTENT_ADDRESS  0x1
#define ADDR_TYPE_DYNAMIC_VOLATILE_ADDRESS    0x2
#define ADDR_TYPE_RANDOM_NUMBER               0x3

/* Bit 0 in device capabilities field*/
#define PEC_SUPPORTED                         0x1

////////////////////////////////////////////////////////////
//         Function Declarations                          //
////////////////////////////////////////////////////////////
#endif /*_SMBUS_H_*/
