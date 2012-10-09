/*
 * Copyright (C) 2008-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

//! @addtogroup diag_mmu
//! @{

/*!
 * @file  mmu.h
 * @brief System memory arangement.
 */

#ifndef _MMU_H_
#define _MMU_H_

#include "sdk.h"

#define ARM_FIRST_LEVEL_PAGE_TABLE_SIZE 0x4000

#define ARM_UNCACHEABLE                         0
#define ARM_CACHEABLE                           1

#define ARM_UNBUFFERABLE                        0
#define ARM_BUFFERABLE                          1

#define ARM_ACCESS_PERM_NONE_NONE               0
#define ARM_ACCESS_PERM_RO_NONE                 0
#define ARM_ACCESS_PERM_RO_RO                   0
#define ARM_ACCESS_PERM_RW_NONE                 1
#define ARM_ACCESS_PERM_RW_RO                   2
#define ARM_ACCESS_PERM_RW_RW                   3

#define B_DISABLE	(0<<2)
#define B_ENABLE	(1<<2)
#define C_DISABLE	(0<<3)
#define C_ENABLE	(1<<3)
#define TEX(x)		((x)<<12)
#define NON_SHARE	(0<<16)
#define SHAREABLE	(1<<16)

#define STRONGLY_ORDERED   	(B_DISABLE | C_DISABLE | TEX(0) | SHAREABLE)
#define OUTER_INNER_WB_WA 	(B_ENABLE | C_ENABLE | TEX(1))
#define OUTER_INNER_WT		(B_DISABLE | C_ENABLE | TEX(0))
#define OUTER_INNER_WT_S	(B_DISABLE | C_ENABLE | TEX(0) | SHAREABLE)
#define DEVICE_SHARED		(B_ENABLE | C_DISABLE | TEX(0) | SHAREABLE)
#define DEVICE_NSHARED		(B_DISABLE | C_DISABLE | TEX(2) | NON_SHARE)
#define NON_CACHABLE		(B_DISABLE | C_DISABLE | TEX(1) | NON_SHARE)

/*TLB first level descriptor*/
struct ARM_MMU_FIRST_LEVEL_SECTION {
    unsigned int id:2;
    unsigned int b:1;
    unsigned int c:1;
    unsigned int imp:1;
    unsigned int domain:4;
    unsigned int sbz0:1;
    unsigned int ap:2;
    unsigned int tex:3;
    unsigned int apx:1;
    unsigned int s:1;
    unsigned int ng:1;
    unsigned int sbz:1;
    unsigned int ns:1;
    unsigned int base_address:12;
};

#define ARM_MMU_FIRST_LEVEL_SECTION_ID 0x2

/*only section(1MB) is supported here. small page, page and super section is not implemented*/
union ARM_MMU_FIRST_LEVEL_DESCRIPTOR {
    uint32_t word;              // for initialization purpose
    struct ARM_MMU_FIRST_LEVEL_SECTION section; // section descriptor
};

#define ARM_MMU_SECTION(ttb_base, physical_base, virtual_base,            \
                        memory_type, permission)   						  \
    do {                                                       			  \
        register union ARM_MMU_FIRST_LEVEL_DESCRIPTOR desc;               \
                                                                          \
        desc.word = 0;                                                    \
        desc.section.id = ARM_MMU_FIRST_LEVEL_SECTION_ID;                 \
        desc.section.domain = 0;                                          \
        desc.section.c = ((memory_type & 0x8) >> 3);                      \
        desc.section.b = ((memory_type & 0x4) >> 2);                      \
		desc.section.s = ((memory_type & 0x10000) >> 16); 				  \
		desc.section.tex = ((memory_type & 0x7000) >> 12);                \
        desc.section.ap = (permission);                                   \
        desc.section.base_address = (physical_base);                      \
        *(uint32_t *)(ttb_base + ((virtual_base)<<2)) = desc.word;        \
    } while(0)

#define MMU_CONFIG(ttb_base, pbase, vbase, size, mem_type, access)  	  \
	do {																  \
        int i; int j = pbase; int k = vbase;                              \
        for (i = size; i > 0 ; i--,j++,k++) {                             \
        ARM_MMU_SECTION(ttb_base, j, k, mem_type, access);             \
      }                                                                   \
    } while(0)

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * system memory arrangement, including IRAM and DRAM
 */
void system_memory_arrange(void);

#if defined(__cplusplus)
}
#endif

//! @}

#endif // _MMU_H_

