/*
 * Copyright (c) 2008-2012, Freescale Semiconductor, Inc.
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
 * @file  mmu.c
 * @brief System memory arangement.
 *
 * @ingroup diag_init
 */
#include "buffers.h"
#include "mmu.h"

#define TTB_BASE_ADDR TLB_ENTRY_START

void system_memory_arrange(void)
{
    /*using section to partition the external memory. pay attention using 
       section as partition unit we will need 16KB as the TLB memory. */
    uint32_t ttb_base = TTB_BASE_ADDR;
    uint32_t domain_access = 0x55555555;
  __asm("MCR	p15, 0, %0, c2, c0, 0": :"r"(ttb_base));
    //set TTB register
  __asm("MCR	p15, 0, %0, c3, c0, 0": :"r"(domain_access));
    //set DACR register

    /*ckear all TLB entries */
    memset((void *)ttb_base, 0, ARM_FIRST_LEVEL_PAGE_TABLE_SIZE);
#if defined(BOARD_EVB)
    /*params:  ttb_base  phy    virt   size     memory_type         permission */
//  MMU_CONFIG(ttb_base, 0x000, 0x000, 0x001,   OUTER_INNER_WB_WA,  ARM_ACCESS_PERM_RW_RW); /* ROM */
    MMU_CONFIG(ttb_base, 0x000, 0x000, 0x100, STRONGLY_ORDERED, ARM_ACCESS_PERM_RW_RW); /* peripherals */
    MMU_CONFIG(ttb_base, 0x100, 0x100, 0x200, OUTER_INNER_WB_WA, ARM_ACCESS_PERM_RW_RW);    /* SDRAM */
    MMU_CONFIG(ttb_base, 0x300, 0x300, 0x700, NON_CACHABLE, ARM_ACCESS_PERM_RW_RW); /* SDRAM reserved for DMA Access */
#elif defined(BOARD_SMART_DEVICE)
    MMU_CONFIG(ttb_base, 0x000, 0x000, 0x100, STRONGLY_ORDERED, ARM_ACCESS_PERM_RW_RW); /* peripherals */
    MMU_CONFIG(ttb_base, 0x100, 0x100, 0x100, OUTER_INNER_WB_WA, ARM_ACCESS_PERM_RW_RW);    /* SDRAM */
    MMU_CONFIG(ttb_base, 0x200, 0x200, 0x300, NON_CACHABLE, ARM_ACCESS_PERM_RW_RW); /* SDRAM reserved for DMA Access */
#endif
}
