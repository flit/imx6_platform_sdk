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
#ifndef _SMBUS_H_
#define _SMBUS_H_
#include "sdk.h"

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
