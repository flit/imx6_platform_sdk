/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file vpu_io.h
 *
 * @brief VPU system ioctrl definition
 *
 * @ingroup VPU
 */

#ifndef __VPU__IO__H
#define __VPU__IO__H

#include "io.h"

/*!
 * @brief  vpu memory description structure
 */
typedef struct vpu_mem_desc {
    int size;                   /*!requested memory size */
    unsigned long phy_addr;     /*!physical memory address allocated */
    unsigned long cpu_addr;     /*!cpu addr for system free usage */
    unsigned long virt_uaddr;   /*!virtual user space address */
} vpu_mem_desc;

typedef struct iram_t {
    unsigned long start;
    unsigned long end;
} iram_t;

#ifndef	true
#define true	1
#endif
#ifndef	false
#define false	0
#endif

typedef void (*vpu_callback) (int status);

int IOSystemInit(void *callback);
int IOSystemShutdown(void);
int IOGetMem(vpu_mem_desc * buff);
int IOCodecCleanup(void);
int IOWaitForInt(int timeout_in_ms);
int IOGetIramBase(iram_t * iram);
int IOGetPhyShareMem(vpu_mem_desc * buff);
int IOFreePhyPicParaMem(vpu_mem_desc * buff);
int IOFreePhyUserDataMem(vpu_mem_desc * buff);
int IOSysSWReset(void);

unsigned long VpuWriteReg(unsigned long addr, unsigned int data);
unsigned long VpuReadReg(unsigned long addr);

void ResetVpu(void);
int isVpuInitialized(void);

#endif
