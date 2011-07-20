/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*
 * Copyright (c) 2006, Chips & Media.  All rights reserved.
 */

/*
 * The code contained herein is licensed under the GNU Lesser General
 * Public License.  You may obtain a copy of the GNU Lesser General
 * Public License Version 2.1 or later at the following locations:
 *
 * http://www.opensource.org/licenses/lgpl-license.html
 * http://www.gnu.org/copyleft/lgpl.html
 */

/*!
 * @file vpu_io.c
 *
 * @brief VPU system ioctrl implementation
 *
 * @ingroup VPU
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vpu_debug.h"
#include "vpu_reg.h"
#include "vpu_io.h"
#include "vpu_lib.h"
#include "vpu_util.h"
#include "hardware.h"

#define VPU_MEM_START_ADDR	(CSD0_DDR_BASE_ADDR + 0x10000000)
#define VPU_MEM_END_ADDR	(CSD0_DDR_BASE_ADDR + 0x1FFFFFFF)

static unsigned int vpu_mem_alloc_ptr = VPU_MEM_START_ADDR;

static unsigned long vpu_reg_base;

vpu_mem_desc bit_work_addr;
vpu_mem_desc pic_para_addr;
vpu_mem_desc user_data_addr;

int IOGetMem(vpu_mem_desc * buff);

/*
 * Note: the order does not correspond to the bit order in BIT_AXI_SRAM_USE
 * register, but correspond to the items in use_iram_table array.
 * So if there's any IRAM size change in use_iram_table array, may consider
 * change this enumeration accordingly.
 */
enum {
    USE_DBK_INTERNAL_BUF,       /* MPEG-4 and MPEG-2 output deblocking */
    USE_OVL_INTERNAL_BUF,       /* overlap filter */
    USE_IP_INTERNAL_BUF,        /* intra/ACDC prediction */
    USE_BIT_INTERNAL_BUF,       /* MB prediction */
};

int isVpuInitialized(void)
{
    int val;

    val = VpuReadReg(BIT_CUR_PC);

    return val != 0;
}

/* make consideration for both register and physical mem access */
inline unsigned long *reg_map(unsigned long offset)
{
    return (unsigned long *)(offset + (unsigned long)vpu_reg_base);
}

/*!
 * @brief IO system initialization.
 *  When user wants to start up the codec system,
 *  this function call is needed, to open the codec device,
 *  map the register into user space,
 *  get the working buffer/code buffer/parameter buffer,
 *  download the firmware, and then set up the interrupt signal path.
 *
 * @param callback vpu interrupt callback.
 *
 * @return
 * @li  0	          System initialization success.
 * @li -1		System initialization failure.
 */
int IOSystemInit(void *callback)
{
    int ret;

    /*vpu base is equal to the physical address. MMU disabled */
    vpu_reg_base = (unsigned long)VPU_BASE_ADDR;

    bit_work_addr.size = WORK_BUF_SIZE + PARA_BUF_SIZE + CODE_BUF_SIZE + PARA_BUF2_SIZE;

    if (IOGetMem(&bit_work_addr) < 0) {
        err_msg("Get bitwork address failed!\n");
        goto err;
    }

    return 0;

  err:
    err_msg("Error in IOSystemInit()");
    IOSystemShutdown();
    return -1;
}

/*!
 * @brief IO system shut down.
 *
 * When user wants to stop the codec system, this
 * function call is needed, to release the interrupt
 * signal, free the working buffer/code buffer/parameter
 * buffer, unmap the register into user space, and
 * close the codec device.
 *
 * @param none
 *
 * @return
 * @li   0	System shutting down success.
 * @li   -1		System shutting down failure.
 */
int IOSystemShutdown(void)
{
    IOFreeMem(&bit_work_addr);
    IOFreeMem(&pic_para_addr);
    IOFreeMem(&user_data_addr);

    return 0;
}

unsigned long VpuWriteReg(unsigned long addr, unsigned int data)
{
    unsigned long *reg_addr = reg_map(addr);
    *(volatile unsigned long *)reg_addr = data;

    return 0;
}

unsigned long VpuReadReg(unsigned long addr)
{
    unsigned long *reg_addr = reg_map(addr);
    return *(volatile unsigned long *)reg_addr;
}

/*!
 * @brief Allocated buffer of requested size
 * When user wants to get massive memory for the system, they needs to fill
 * the required size in buff structure, and if this function succeeds in
 * allocating memory and returns 0, the returned physical memory is filled in
 * phy_addr of buff structure. If the function fails and return -1,
 * the phy_addr remains the same as before.
 *
 * @param buff	the structure contains the memory information to be retrieved;
 *
 * @return
 * @li 0		Allocation memory success.
 * @li -1		Allocation memory failure.
 */
static unsigned int sz_alloc;
int IOGetMem(vpu_mem_desc * buff)
{
    if (vpu_mem_alloc_ptr + buff->size > VPU_MEM_END_ADDR) {
        err_msg("Memory reserved for VPU is not enough!!\n");
        err_msg("Memory required 0x%x, actual pointer 0x%x, actual room 0x%x!!\n",
                buff->size, vpu_mem_alloc_ptr, VPU_MEM_END_ADDR - vpu_mem_alloc_ptr);
        return -1;
    } else {
        buff->phy_addr = vpu_mem_alloc_ptr;
        buff->cpu_addr = vpu_mem_alloc_ptr;
        buff->virt_uaddr = vpu_mem_alloc_ptr;
        sz_alloc += buff->size;
        vpu_mem_alloc_ptr += buff->size;
    }
    dprintf(3, "%s: phy addr = %08lx\n", __func__, buff->phy_addr);
    dprintf(3, "%s: alloc=%d, total=%d\n", __func__, buff->size, sz_alloc);

    return 0;
}

/* User cannot free physical share memory, this is done in driver */
int IOGetShareMem(vpu_mem_desc * buff)
{
    return IOGetMem(buff);
}

int IOGetPicParaMem(vpu_mem_desc * buff)
{
    return IOGetMem(buff);
}

int IOGetUserDataMem(vpu_mem_desc * buff)
{
    return IOGetMem(buff);
}

/*!
 * @brief Free specified memory
 * When user wants to free massive memory for the system,
 * they needs to fill the physical address and size to be freed
 * in buff structure.
 *
 * @param buff	the structure containing memory information to be freed;
 *
 * @return
 * @li 0            Freeing memory success.
 * @li -1		Freeing memory failure.
 */
int _IOFreeMem(vpu_mem_desc * buff)
{
    if (buff->phy_addr != 0) {
        dprintf(3, "%s: phy addr = %08lx\n", __func__, buff->phy_addr);
        buff->phy_addr = 0;
        buff->cpu_addr = 0;
        buff->virt_uaddr = 0;
        vpu_mem_alloc_ptr -= buff->size;
    }

    sz_alloc -= buff->size;
    dprintf(3, "%s: total=%d\n", __func__, sz_alloc);
    memset(buff, 0, sizeof(*buff));

    return 0;
}

int IOFreeMem(vpu_mem_desc * buff)
{
    return _IOFreeMem(buff);
}

int IOFreePicParaMem(vpu_mem_desc * buff)
{
    return _IOFreeMem(buff);
}

int IOFreeUserDataMem(vpu_mem_desc * buff)
{
    return _IOFreeMem(buff);
}

/*!
 * @brief
 * When the system starts up, resetting is needed in advance.
 */
void ResetVpu(void)
{
    unsigned long *reg_addr = reg_map(BIT_CODE_RESET);
    (*(volatile unsigned long *)reg_addr) |= 0x1;
    hal_delay_us(10);
    (*(volatile unsigned long *)reg_addr) &= ~0x1;

    return;
}
