/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
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

/*!
 * @file vpu_io.h
 *
 * @brief VPU system ioctrl definition
 *
 * @ingroup VPU
 */

#ifndef __VPU__IO__H
#define __VPU__IO__H

#include "sdk.h"

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

int IOSystemInit(void);
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
