/*
 * Copyright (C) 2008-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
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

/*!
 * system memory arrangement, including IRAM and DRAM
 */
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
#if defined(MX6SDL_EVB)
    /*params:  ttb_base  phy    virt   size     memory_type         permission */
//  MMU_CONFIG(ttb_base, 0x000, 0x000, 0x001,   OUTER_INNER_WB_WA,  ARM_ACCESS_PERM_RW_RW); /* ROM */
    MMU_CONFIG(ttb_base, 0x000, 0x000, 0x100, STRONGLY_ORDERED, ARM_ACCESS_PERM_RW_RW); /* peripherals */
    MMU_CONFIG(ttb_base, 0x100, 0x100, 0x200, OUTER_INNER_WB_WA, ARM_ACCESS_PERM_RW_RW);    /* SDRAM */
    MMU_CONFIG(ttb_base, 0x300, 0x300, 0x700, NON_CACHABLE, ARM_ACCESS_PERM_RW_RW); /* SDRAM reserved for DMA Access */
#elif defined(MX6SDL_SMART_DEVICE)
    MMU_CONFIG(ttb_base, 0x000, 0x000, 0x100, STRONGLY_ORDERED, ARM_ACCESS_PERM_RW_RW); /* peripherals */
    MMU_CONFIG(ttb_base, 0x100, 0x100, 0x100, OUTER_INNER_WB_WA, ARM_ACCESS_PERM_RW_RW);    /* SDRAM */
    MMU_CONFIG(ttb_base, 0x200, 0x200, 0x300, NON_CACHABLE, ARM_ACCESS_PERM_RW_RW); /* SDRAM reserved for DMA Access */
#endif
}
