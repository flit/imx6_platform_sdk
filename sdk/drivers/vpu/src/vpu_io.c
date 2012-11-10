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
 * @file vpu_io.c
 *
 * @brief VPU system ioctrl implementation
 *
 * @ingroup VPU
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vpu/vpu_debug.h"
#include "vpu/vpu_reg.h"
#include "vpu/vpu_io.h"
#include "vpu/vpu_lib.h"
#include "vpu/vpu_util.h"
#include "sdk.h"

#define VPU_MEM_START_ADDR	(VIDEO_BUFFERS_START)
#define VPU_MEM_END_ADDR	(VIDEO_BUFFERS_END)

static unsigned int g_vpu_mem_alloc_ptr = VPU_MEM_START_ADDR;

vpu_mem_desc g_vpu_reg_base;
vpu_mem_desc g_bit_work_addr;

extern vpu_resource_t *g_vpu_hw_map;

int g_vpu_system_mem_size = 0;

int vpu_malloc(vpu_mem_desc * buff);

int vpu_is_initialized(void)
{
    int val;

    val = vpu_reg_read(BIT_CUR_PC);

    return val != 0;
}

/*!
 * @brief remap the vpu registers.
 * it should be on any access to vpu registers.
 */
/* make consideration for both register and physical mem access */
static inline unsigned long *vpu_reg_map(unsigned long offset)
{
    return (unsigned long *)(offset + (unsigned long)g_vpu_reg_base.virt_addr);
}

/*!
 * @brief IO system initialization.
 * before starting the codec, this function must be called first.
 * the work buffer address and vpu base address are settled here
 *
 */
int vpu_io_init(void)
{
    /*vpu base is equal to the physical address. MMU disabled */
    g_vpu_system_mem_size = 0;
    g_vpu_reg_base.phy_addr = (unsigned long)VPU_BASE_ADDR;
    g_vpu_reg_base.virt_addr = (unsigned long)VPU_BASE_ADDR;

    g_bit_work_addr.size = TEMP_BUF_SIZE + PARA_BUF_SIZE + CODE_BUF_SIZE + PARA_BUF2_SIZE;
    if (vpu_malloc(&g_bit_work_addr) < 0) {
        err_msg("Get bitwork address failed!\n");
        goto err;
    }
    g_vpu_system_mem_size += g_bit_work_addr.size;
    g_vpu_hw_map = vpu_semaphore_open();

    return 0;

  err:
    err_msg("Error in %s", __FUNCTION__);
    vpu_io_uninit();
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
int vpu_io_uninit(void)
{
    g_vpu_mem_alloc_ptr = g_bit_work_addr.phy_addr;
    g_vpu_system_mem_size = 0;
    return 0;
}

unsigned long vpu_reg_write(unsigned long addr, unsigned int data)
{
    unsigned long *reg_addr = vpu_reg_map(addr);
    *(volatile unsigned long *)reg_addr = data;

    return 0;
}

unsigned long vpu_reg_read(unsigned long addr)
{
    unsigned long *reg_addr = vpu_reg_map(addr);
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
int vpu_malloc(vpu_mem_desc * buff)
{
    buff->size = (buff->size + 0xFFF) & 0xFFFFF000; //align 
    if (g_vpu_mem_alloc_ptr + buff->size > VPU_MEM_END_ADDR) {
        err_msg("Memory reserved for VPU is not enough!!\n");
        err_msg("Memory required 0x%x, actual pointer 0x%x, actual room 0x%x!!\n",
                buff->size, g_vpu_mem_alloc_ptr, VPU_MEM_END_ADDR - g_vpu_mem_alloc_ptr);
        return -1;
    } else {
        buff->phy_addr = g_vpu_mem_alloc_ptr;
        buff->virt_addr = g_vpu_mem_alloc_ptr;
        g_vpu_mem_alloc_ptr += buff->size;
    }
    info_msg("%s: phy addr = %08lx\n", __FUNCTION__, buff->phy_addr);

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
int vpu_codec_io_deinit(void)
{
    int i = 0;
    g_vpu_mem_alloc_ptr = g_bit_work_addr.phy_addr + g_vpu_system_mem_size;
    for (i = 0; i < MAX_NUM_INSTANCE; i++) {
        g_vpu_hw_map->codecInstPool[i].inUse = 0;
        g_vpu_hw_map->codecInstPool[i].initDone = 0;
    }
    return 0;
}

/*!
 * @brief
 * When the system starts up, resetting is needed in advance.
 */
void vpu_reset(void)
{
    unsigned long *reg_addr = vpu_reg_map(BIT_CODE_RESET);
    (*(volatile unsigned long *)reg_addr) |= 0x1;
    hal_delay_us(10);
    (*(volatile unsigned long *)reg_addr) &= ~0x1;

    return;
}
