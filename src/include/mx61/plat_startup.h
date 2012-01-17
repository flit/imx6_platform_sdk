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
#define IMAGE_ENTRY_ADDR        0x10000000
#define IMAGE_SIZE              4*1024*1024

#define L2CC_REG1_CTRL			0x00A02100
#define L2CC_INV_REG			0x00A0277C
#define L2CC_TAG_RAM_CTRL		0x00A02108
#define L2CC_DAT_RAM_CTRL		0x00A0210C
#define L2CC_PREFETCH_CTRL		0x00A02F60

#define PLATFORM_INIT           plat_dcd_startup
// image starts at 0x00907000
//flash header & DCD @ 0x400
.macro plat_dcd_startup
    b startup_imx6x
    .org 0x400
/* First IVT to copy the plugin that initializes the system into OCRAM */
ivt_header:             .long 0x402000D1    //Tag=0xD1, Len=0x0020, Ver=0x40
app_code_jump_v:        .long 0x00907458    // Plugin entry point, address after the second IVT table
reserv1:                .long 0x0
dcd_ptr:                .long 0x0
boot_data_ptr:          .long 0x00907420
self_ptr:               .long 0x00907400
app_code_csf:           .long 0x0 // reserve 4K for csf
reserv2:                .long 0x0
boot_data:              .long 0x00907000
image_len:              .long 16*1024  
plugin:                 .long 0x1  // Enable plugin flag

/* Second IVT to give entry point into the bootloader copied to DDR */
ivt2_header:            .long 0x402000D1    //Tag=0xD1, Len=0x0020, Ver=0x40
app2_code_jump_v:       .long startup_imx6x       // Entry point for the bootloader
reserv3:                .long 0x0
dcd2_ptr:               .long 0x0
boot_data2_ptr:         .long boot_data2
self_ptr2:              .long ivt2_header
app_code_csf2:          .long 0x0 // reserve 4K for csf
reserv4:                .long 0x0
boot_data2:             .long IMAGE_ENTRY_ADDR
image_len2:             .long IMAGE_SIZE
plugin2:                .long 0x0

// Here starts the plugin code
plugin_start:
// Save the return address and the function arguments
    push    {r0-r4, lr}

/*
 * Note: The DDR settings provided below are specific to Freescale development boards and are the latest settings at the time of release.
 * However, it is recommended to contact your Freescale representative in case there are any improvements to these settings.
 */
#if ((defined MX61_ARD) || (defined MX61_SABRE_TABLET) || (defined MX61_SABRE_LITE) || (defined MX61_EVB))
    /*Use default DDR frequency: 528MHz*/
    ldr r0, =0x020c4068
    ldr r1, =0xffffffff
    str r1, [r0]
    ldr r0, =0x020c406c
    ldr r1, =0xffffffff
    str r1, [r0]
    ldr r0, =0x020c4070
    ldr r1, =0xffffffff
    str r1, [r0]
    ldr r0, =0x020c4074
    ldr r1, =0xffffffff
    str r1, [r0]
    ldr r0, =0x020c4078
    ldr r1, =0xffffffff
    str r1, [r0]
    ldr r0, =0x020c407c
    ldr r1, =0xffffffff
    str r1, [r0]
    ldr r0, =0x020c4080
    ldr r1, =0xffffffff
    str r1, [r0]
    ldr r0, =0x020c4084
    ldr r1, =0xffffffff
    str r1, [r0]
    ldr r0, =0x020e05a8
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e05b0
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0524
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e051c
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0518
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e050c
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e05b8
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e05c0
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e05ac
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e05b4
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0528
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0520
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0514
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0510
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e05bc
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e05c4
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e056c
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0578
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0588
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0594
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e057c
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0590
    ldr r1, =0x00003000
    str r1, [r0]
    ldr r0, =0x020e0598
    ldr r1, =0x00003000
    str r1, [r0]
    ldr r0, =0x020e058c
    ldr r1, =0x00000000
    str r1, [r0]
    ldr r0, =0x020e059c
    ldr r1, =0x00003030
    str r1, [r0]
    ldr r0, =0x020e05a0
    ldr r1, =0x00003030
    str r1, [r0]
    ldr r0, =0x020e0784
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0788
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0794
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e079c
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e07a0
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e07a4
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e07a8
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0748
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e074c
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0750
    ldr r1, =0x00020000
    str r1, [r0]
    ldr r0, =0x020e0758
    ldr r1, =0x00000000
    str r1, [r0]
    ldr r0, =0x020e0774
    ldr r1, =0x00020000
    str r1, [r0]
    ldr r0, =0x020e078c
    ldr r1, =0x00000030
    str r1, [r0]
    ldr r0, =0x020e0798
    ldr r1, =0x000c0000
    str r1, [r0]
    ldr r0, =0x021b081c
    ldr r1, =0x33333333
    str r1, [r0]
    ldr r0, =0x021b0820
    ldr r1, =0x33333333
    str r1, [r0]
    ldr r0, =0x021b0824
    ldr r1, =0x33333333
    str r1, [r0]
    ldr r0, =0x021b0828
    ldr r1, =0x33333333
    str r1, [r0]
    ldr r0, =0x021b481c
    ldr r1, =0x33333333
    str r1, [r0]
    ldr r0, =0x021b4820
    ldr r1, =0x33333333
    str r1, [r0]
    ldr r0, =0x021b4824
    ldr r1, =0x33333333
    str r1, [r0]
    ldr r0, =0x021b4828
    ldr r1, =0x33333333
    str r1, [r0]
    ldr r0, =0x021b0018
    ldr r1, =0x00081740
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x00008000
    str r1, [r0]
    ldr r0, =0x021b000c
    ldr r1, =0x555A7975
    str r1, [r0]
    ldr r0, =0x021b0010
    ldr r1, =0xFF538E64
    str r1, [r0]
    ldr r0, =0x021b0014
    ldr r1, =0x01ff00db
    str r1, [r0]
    ldr r0, =0x021b002c
    ldr r1, =0x000026d2
    str r1, [r0]
    ldr r0, =0x021b0030
    ldr r1, =0x005b0e21
    str r1, [r0]
    ldr r0, =0x021b0008
    ldr r1, =0x09444040
    str r1, [r0]
    ldr r0, =0x021b0004
    ldr r1, =0x00025576
    str r1, [r0]
    ldr r0, =0x021b0040
    ldr r1, =0x00000027
    str r1, [r0]
    ldr r0, =0x021b0000
    ldr r1, =0xc31a0000
    str r1, [r0]
    ldr r0, =0x021b0404
    ldr r1, =0x00011006
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x04088032
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x0408803a
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x00008033
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x0000803b
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x00428031
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x00428039
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x09408030
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x09408038
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x04008040
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x04008048
    str r1, [r0]
    ldr r0, =0x021b0800
    ldr r1, =0xa1380003
    str r1, [r0]
    ldr r0, =0x021b4800
    ldr r1, =0xa1380003
    str r1, [r0]
    ldr r0, =0x021b0020
    ldr r1, =0x00005800
    str r1, [r0]
    ldr r0, =0x021b0818
    ldr r1, =0x00022227
    str r1, [r0]
    ldr r0, =0x021b4818
    ldr r1, =0x00022227
    str r1, [r0]
    ldr r0, =0x021b083c
    ldr r1, =0x434b0350
    str r1, [r0]
    ldr r0, =0x021b0840
    ldr r1, =0x034c0359
    str r1, [r0]
    ldr r0, =0x021b483c
    ldr r1, =0x434b0350
    str r1, [r0]
    ldr r0, =0x021b4840
    ldr r1, =0x03650348
    str r1, [r0]
    ldr r0, =0x021b0848
    ldr r1, =0x4436383b
    str r1, [r0]
    ldr r0, =0x021b4848
    ldr r1, =0x39393341
    str r1, [r0]
    ldr r0, =0x021b0850
    ldr r1, =0x35373933
    str r1, [r0]
    ldr r0, =0x021b4850
    ldr r1, =0x48254a36
    str r1, [r0]
    ldr r0, =0x021b080c
    ldr r1, =0x001F001F
    str r1, [r0]
    ldr r0, =0x021b0810
    ldr r1, =0x001F001F
    str r1, [r0]
    ldr r0, =0x021b480c
    ldr r1, =0x00440044
    str r1, [r0]
    ldr r0, =0x021b4810
    ldr r1, =0x00440044
    str r1, [r0]
    ldr r0, =0x021b08b8
    ldr r1, =0x00000800
    str r1, [r0]
    ldr r0, =0x021b48b8
    ldr r1, =0x00000800
    str r1, [r0]
    ldr r0, =0x021b001c
    ldr r1, =0x00000000
    str r1, [r0]

    b read_obds
#endif

read_obds:
/********************
    The following is to fill in those arguments for this ROM function
    pu_irom_hwcnfg_setup(void **start, size_t *bytes, const void *boot_data)

    This function is used to copy data from the storage media into DDR.

    start - Initial (possibly partial) image load address on entry.  Final image load address on exit.
    bytes - Initial (possibly partial) image size on entry.  Final image size on exit.
    boot_data - Initial @ref ivt Boot Data load address.
*/

    adr r0, DDR_DEST_ADDR
    adr r1, COPY_SIZE
    adr r2, BOOT_DATA

/*
 * check the _pu_irom_api_table for the address
 */
before_calling_rom___pu_irom_hwcnfg_setup:
    mov r4, #0x2000
    add r4, r4, #0xed
    blx r4	// This address might change in future ROM versions.
after_calling_rom___pu_irom_hwcnfg_setup:

// To return to ROM from plugin, we need to fill in these argument.
// Here is what need to do:
// Need to construct the paramters for this function before return to ROM:
// plugin_download(void **start, size_t *bytes, UINT32 *ivt_offset)
    pop {r0-r4, lr}
    ldr r5, DDR_DEST_ADDR
    str r5, [r0]
    ldr r5, COPY_SIZE
    str r5, [r1]
    mov r5, #0x400  /* Point to the second IVT table at offset 0x42C */
    add r5, r5, #0x2C
    str r5, [r2]
    mov r0, #1
    push {r0,r1}
    disable_L2_cache
    pop {r0,r1}
    bx lr          // return back to ROM code

DDR_DEST_ADDR:    .word   IMAGE_ENTRY_ADDR
COPY_SIZE:        .word   IMAGE_SIZE
BOOT_DATA:        .word   IMAGE_ENTRY_ADDR
                  .word   IMAGE_SIZE  //real data to be copied by the pu_irom_hwcnfg_setup()
                  .word   0

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
    ldr r1, =IMAGE_ENTRY_ADDR
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
    ldr r1, =(IMAGE_ENTRY_ADDR + 0x8)
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
