/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
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

#define VPU_MEM_START_ADDR	(VIDEO_BUFFERS_START)
#define VPU_MEM_END_ADDR	(VIDEO_BUFFERS_END)

static unsigned int vpu_mem_alloc_ptr = VPU_MEM_START_ADDR;

static unsigned long vpu_reg_base;

vpu_mem_desc bit_work_addr;

extern vpu_resource_t *vpu_hw_map;

int vpu_system_mem_size = 0;

int IOGetMem(vpu_mem_desc * buff);

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
    /*vpu base is equal to the physical address. MMU disabled */
    vpu_reg_base = (unsigned long)VPU_BASE_ADDR;
    vpu_system_mem_size = 0;
    bit_work_addr.size = TEMP_BUF_SIZE + PARA_BUF_SIZE + CODE_BUF_SIZE + PARA_BUF2_SIZE;

    if (IOGetMem(&bit_work_addr) < 0) {
        err_msg("Get bitwork address failed!\n");
        goto err;
    }
    vpu_system_mem_size += bit_work_addr.size;
    vpu_hw_map = vpu_semaphore_open();

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
    vpu_mem_alloc_ptr = bit_work_addr.phy_addr;
    vpu_system_mem_size = 0;
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
int IOGetMem(vpu_mem_desc * buff)
{
    buff->size = (buff->size + 0xFFF) & 0xFFFFF000; //align 
    if (vpu_mem_alloc_ptr + buff->size > VPU_MEM_END_ADDR) {
        err_msg("Memory reserved for VPU is not enough!!\n");
        err_msg("Memory required 0x%x, actual pointer 0x%x, actual room 0x%x!!\n",
                buff->size, vpu_mem_alloc_ptr, VPU_MEM_END_ADDR - vpu_mem_alloc_ptr);
        return -1;
    } else {
        buff->phy_addr = vpu_mem_alloc_ptr;
        buff->cpu_addr = vpu_mem_alloc_ptr;
        buff->virt_uaddr = vpu_mem_alloc_ptr;
        vpu_mem_alloc_ptr += buff->size;
    }
    dprintf(3, "%s: phy addr = %08lx\n", __func__, buff->phy_addr);

    return 0;
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
int IOCodecCleanup(void)
{
    int i = 0;
    vpu_mem_alloc_ptr = bit_work_addr.phy_addr + vpu_system_mem_size;
    for (i = 0; i < MAX_NUM_INSTANCE; i++) {
        vpu_hw_map->codecInstPool[i].inUse = 0;
        vpu_hw_map->codecInstPool[i].initDone = 0;
    }
    return 0;
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
