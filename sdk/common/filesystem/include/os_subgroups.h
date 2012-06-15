/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#ifndef _OS_SUBGROUPS_H
#define _OS_SUBGROUPS_H

#include "groups.h"

//commented out codes are ones that are not being used at all right now.

#define OS_KERNEL_GROUP           (OS_GROUP|0x00000000)
#define OS_BOOT_GROUP             (OS_GROUP|0x00001000)
#define OS_DMI_GROUP              (OS_GROUP|0x00002000)
#define OS_MEMORY_MANAGER_GROUP   (OS_GROUP|0x00003000)
#define OS_POWER_MANAGER_GROUP    (OS_GROUP|0x00004000)
#define OS_FILESYSTEM_GROUP       (OS_GROUP|0x00005000)
#define OS_DPC_GROUP              (OS_GROUP|0x00006000)
#define OS_HCM_GROUP              (OS_GROUP|0x00007000)
#define OS_PMI_GROUP              (OS_GROUP|0x00008000)
#define OS_EOI_GROUP              (OS_GROUP|0x0000A000)
#define OS_VMI_GROUP              (OS_GROUP|0x0000B000)
#define OS_SYSMGR_GROUP           (OS_GROUP|0x0000C000)

#endif//_OS_SUBGROUPS_H 

