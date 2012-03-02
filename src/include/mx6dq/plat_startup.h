/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file plat_startup.inc
 * @brief This file contains start-up DCD.
 *
 * @ingroup diag_init
 */
 /* *INDENT-OFF* */
#ifndef _PLAT_STARTUP_H_
#define _PLAT_STARTUP_H_

#include "soc_memory_map.h"

#define LE_TO_BE(x) (((x << 24) & 0xFF000000) | \
                    ((x << 8) & 0xFF0000) |     \
                    ((x >> 8) & 0xFF00) |       \
                    ((x >> 24) & 0xFF))

#define DCD_DATA(addr, data)        \
            .long LE_TO_BE(addr);   \
            .long LE_TO_BE(data)    \

#define L2CC_REG1_CTRL			0x00A02100
#define L2CC_INV_REG			0x00A0277C
#define L2CC_TAG_RAM_CTRL		0x00A02108
#define L2CC_DAT_RAM_CTRL		0x00A0210C
#define L2CC_PREFETCH_CTRL		0x00A02F60

#define PLATFORM_INIT           plat_dcd_startup
#define IVT_OFFSET              0x400

.macro plat_dcd_startup
    b startup_imx6x
    .org IVT_OFFSET
/* IVT to give entry point into the bootloader copied to DDR */
ivt_header:            .long 0x402000D1    /* Tag=0xD1, Len=0x0020, Ver=0x40 */
app_code_jump_v:       .long startup_imx6x       // Entry point for the bootloader
reserved1:             .long 0x0
dcd_ptr:               .long dcd_header
boot_data_ptr:         .long boot_data_start
self_ptr:              .long ivt_header
app_code_csf:          .long 0x0 /* reserve 4K for csf */
reserved2:             .long 0x0
/* Boot image data */
boot_data_start:       .long _start_image_add   /* from linker script */
boot_image_len:        .long _image_size        /* from linker script */
plugin:                .long 0x0

    .org IVT_OFFSET + 0x30
/*
 * Note: The DDR settings provided below are specific to Freescale development boards and are the latest settings at the time of release.
 * However, it is recommended to contact your Freescale representative in case there are any improvements to these settings.
 */
#if ((defined MX6DQ_ARD) || (defined MX6DQ_SMART_DEVICE) || (defined MX6DQ_SABRE_LITE) || (defined MX6DQ_EVB))
dcd_header:         .long 0x40D802D2 /* Tag=0xD2, Len=4 + 4 + 8*90, Ver=0x40 */
dcd_write_data_cmd: .long 0x04D402CC /* Tag=0xCC, Len=4 + 8*90, Param=0x04 */

    /*Use default DDR frequency: 528MHz*/
    DCD_DATA(0x020e05a8, 0x00000030)
    DCD_DATA(0x020e05b0, 0x00000030)
    DCD_DATA(0x020e0524, 0x00000030)
    DCD_DATA(0x020e051c, 0x00000030)
    DCD_DATA(0x020e0518, 0x00000030)
    DCD_DATA(0x020e050c, 0x00000030)
    DCD_DATA(0x020e05b8, 0x00000030)
    DCD_DATA(0x020e05c0, 0x00000030)
    DCD_DATA(0x020e05ac, 0x00000030)
    DCD_DATA(0x020e05b4, 0x00000030)
    DCD_DATA(0x020e0528, 0x00000030)
    DCD_DATA(0x020e0520, 0x00000030)
    DCD_DATA(0x020e0514, 0x00000030)
    DCD_DATA(0x020e0510, 0x00000030)
    DCD_DATA(0x020e05bc, 0x00000030)
    DCD_DATA(0x020e05c4, 0x00000030)
    DCD_DATA(0x020e056c, 0x00000030)
    DCD_DATA(0x020e0578, 0x00000030)
    DCD_DATA(0x020e0588, 0x00000030)
    DCD_DATA(0x020e0594, 0x00000030)
    DCD_DATA(0x020e057c, 0x00000030)
    DCD_DATA(0x020e0590, 0x00003000)
    DCD_DATA(0x020e0598, 0x00003000)
    DCD_DATA(0x020e058c, 0x00000000)
    DCD_DATA(0x020e059c, 0x00003030)
    DCD_DATA(0x020e05a0, 0x00003030)
    DCD_DATA(0x020e0784, 0x00000030)
    DCD_DATA(0x020e0788, 0x00000030)
    DCD_DATA(0x020e0794, 0x00000030)
    DCD_DATA(0x020e079c, 0x00000030)
    DCD_DATA(0x020e07a0, 0x00000030)
    DCD_DATA(0x020e07a4, 0x00000030)
    DCD_DATA(0x020e07a8, 0x00000030)
    DCD_DATA(0x020e0748, 0x00000030)
    DCD_DATA(0x020e074c, 0x00000030)
    DCD_DATA(0x020e0750, 0x00020000)
    DCD_DATA(0x020e0758, 0x00000000)
    DCD_DATA(0x020e0774, 0x00020000)
    DCD_DATA(0x020e078c, 0x00000030)
    DCD_DATA(0x020e0798, 0x000c0000)
    DCD_DATA(0x021b081c, 0x33333333)
    DCD_DATA(0x021b0820, 0x33333333)
    DCD_DATA(0x021b0824, 0x33333333)
    DCD_DATA(0x021b0828, 0x33333333)
    DCD_DATA(0x021b481c, 0x33333333)
    DCD_DATA(0x021b4820, 0x33333333)
    DCD_DATA(0x021b4824, 0x33333333)
    DCD_DATA(0x021b4828, 0x33333333)
    DCD_DATA(0x021b0018, 0x00081740)
    DCD_DATA(0x021b001c, 0x00008000)
    DCD_DATA(0x021b000c, 0x555A7975)
    DCD_DATA(0x021b0010, 0xFF538E64)
    DCD_DATA(0x021b0014, 0x01ff00db)
    DCD_DATA(0x021b002c, 0x000026d2)
    DCD_DATA(0x021b0030, 0x005b0e21)
    DCD_DATA(0x021b0008, 0x09444040)
    DCD_DATA(0x021b0004, 0x00025576)
    DCD_DATA(0x021b0040, 0x00000027)
    DCD_DATA(0x021b0000, 0xc31a0000)
    DCD_DATA(0x021b0404, 0x00011006)
    DCD_DATA(0x021b001c, 0x04088032)
    DCD_DATA(0x021b001c, 0x0408803a)
    DCD_DATA(0x021b001c, 0x00008033)
    DCD_DATA(0x021b001c, 0x0000803b)
    DCD_DATA(0x021b001c, 0x00428031)
    DCD_DATA(0x021b001c, 0x00428039)
    DCD_DATA(0x021b001c, 0x09408030)
    DCD_DATA(0x021b001c, 0x09408038)
    DCD_DATA(0x021b001c, 0x04008040)
    DCD_DATA(0x021b001c, 0x04008048)
    DCD_DATA(0x021b0800, 0xa1380003)
    DCD_DATA(0x021b4800, 0xa1380003)
    DCD_DATA(0x021b0020, 0x00005800)
    DCD_DATA(0x021b0818, 0x00022227)
    DCD_DATA(0x021b4818, 0x00022227)
    DCD_DATA(0x021b083c, 0x434b0350)
    DCD_DATA(0x021b0840, 0x034c0359)
    DCD_DATA(0x021b483c, 0x434b0350)
    DCD_DATA(0x021b4840, 0x03650348)
    DCD_DATA(0x021b0848, 0x4436383b)
    DCD_DATA(0x021b4848, 0x39393341)
    DCD_DATA(0x021b0850, 0x35373933)
    DCD_DATA(0x021b4850, 0x48254a36)
    DCD_DATA(0x021b080c, 0x001F001F)
    DCD_DATA(0x021b0810, 0x001F001F)
    DCD_DATA(0x021b480c, 0x00440044)
    DCD_DATA(0x021b4810, 0x00440044)
    DCD_DATA(0x021b08b8, 0x00000800)
    DCD_DATA(0x021b48b8, 0x00000800)
    DCD_DATA(0x021b001c, 0x00000000)

#endif
.endm   //plat_dcd_startup

// #define PLATFORM_ASM_STARTUP           platform_asm_startup
.macro platform_asm_startup

config_L2_cache:
	disable_L2_cache

init_aips_start:
    init_aips

init_reloc_start:
    /* Check if need to copy image to Redboot ROM space */
    ldr r0, =0xFFFFF000
    and r0, r0, pc
    ldr r1, =_start_image_add
    cmp r0, r1
    beq skip_SDRAM_copy

    add r2, r0, #IMAGE_SIZE

1:  ldmia r0!, {r3-r10}
    stmia r1!, {r3-r10}
    cmp r0, r2
    ble 1b
    /* Jump to SDRAM */
    ldr r1, =0xFFFF
    and r0, pc, r1         /* offset of pc */
    ldr r1, =(_start_image_add + 0x8)
    add pc, r0, r1
    nop
    nop
    nop
    nop

skip_SDRAM_copy:
.endm   //platform_asm_startup

/* AIPS setup - Only setup MPROTx registers. The PACR default values are good.*/
.macro init_aips
    /*
     * Set all MPROTx to be non-bufferable, trusted for R/W,
     * not forced to user-mode.
     */
    ldr r0, =AIPS_TZ1_BASE_ADDR
    ldr r1, =0x77777777
    str r1, [r0, #0x00]
    str r1, [r0, #0x04]

    ldr r0, =AIPS_TZ2_BASE_ADDR
    str r1, [r0, #0x00]
    str r1, [r0, #0x04]

.endm /* init_aips */

.macro enable_L1_cache
	mov r0, #0
	mcr	p15, 0, r0, c7, c5, 6 // invalidate BTAC
	mcr p15, 0, r0, c7, c5, 0 // invalidate icache
	
	mov r0, #0
	mcr p15, 2, r0, c0, c0, 0 // select DCache
	mrc p15, 1, r0, c0, c0, 0 // read CCSIDR
	mov r0, r0, ASR #13
	ldr	r3, =0x3FFF
	and r0, r0, r3
	cmp r0, #0x7F
	moveq r6, #0x1000 // 4KB * 4way = 16KB
	beq	invalidate_dcache
	cmp r0, #0xFF
	moveq r6, #0x2000 // 32KB
	beq invalidate_dcache
	movne r6, #0x4000 // 64KB

invalidate_dcache:
	mov r2, #0x00000000
	mov r3, #0x40000000
	mov r4, #0x80000000
	mov r5, #0xC0000000

invalidate_dcache_byset:
	mcr p15, 0, r2, c7, c6, 2 //invalidate dcache on way 0
	mcr p15, 0, r3, c7, c6, 2 //invalidate dcache on way 1
	mcr p15, 0, r4, c7, c6, 2 //invalidate dcache on way 2
	mcr p15, 0, r5, c7, c6, 2 //invalidate dcache on way 3
	add r2, r2, #0x20
	add r3, r3, #0x20
	add r4, r4, #0x20
	add r5, r5, #0x20
	
	cmp r2, r6
	bne invalidate_dcache_byset
	
	ldr	r0, =0x00930000 //where to store the TLB page table
	mcr p15, 0, r0, c2, c0, 0
	ldr	r0, =0x55555555
	mcr p15, 0, r0, c3, c0, 0
	
	mrc p15, 0, r0, c1, c0, 0 // read CP15 register 1 into r0
	orr r0, r0, #(0x1<<12)    // enable I Cache
	orr r0, r0, #(0x1<<11)    // turn on BP
	orr r0, r0, #(0x1<<2)     // enable D Cache
	/*Attention: If you want to enable MMU, must set up the TLB tables first!!*/
	bic r0, r0, #(0x1<<0) 	  // disable MMU
	mcr p15, 0, r0, c1, c0, 0 // write CP15 register 1
.endm

.macro disable_L1_cache
	mrc p15, 0, r0, c1, c0, 0
	bic r0, r0, #(0x1<<12) 
	bic r0, r0, #(0x1<<11) 
	bic r0, r0, #(0x1<<2) 
	bic r0, r0, #(0x1<<0) 
	mcr p15, 0, r0, c1, c0, 0
.endm

.macro enable_L2_cache
	/* set latency: 4x cycles read, 2x cycles write, (3x cycles setup)*/
	ldr     r1,= L2CC_TAG_RAM_CTRL
	ldr     r0,=0x0132
	str     r0,[r1]
	ldr     r1, =L2CC_DAT_RAM_CTRL
	ldr     r0,=0x0132
	str     r0,[r1]
	
	/* invalidate L2Cache by way */
	ldr     r1, =L2CC_INV_REG
	ldr     r0, =0xffff
	str     r0,[r1]
l2cc_inv_done:
	ldr     r2,[r1]
	mov     r0,#0x0
	cmp     r2,r0
	bne     l2cc_inv_done
	
	/* turn on l2 cache */
	ldr     r1, =L2CC_REG1_CTRL
	mov     r0,#1
	str     r0,[r1]
.endm

.macro disable_L2_cache
	ldr     r1, =L2CC_REG1_CTRL
	mov     r0,#0
	str     r0,[r1]
.endm

#endif //_PLAT_STARTUP_H_
