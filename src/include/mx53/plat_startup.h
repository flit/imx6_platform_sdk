/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
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
#define IMAGE_ENTRY_ADDR        0x75000000
#define IMAGE_SIZE              2*1024*1024

#define PLATFORM_INIT           plat_dcd_startup

//flash header & DCD @ 0x400
.macro plat_dcd_startup
    b startup
    .org 0x400
/* First IVT to copy the plugin that initializes the system into OCRAM */
ivt_header:             .long 0x402000D1    //Tag=0xD1, Len=0x0020, Ver=0x40
app_code_jump_v:        .long 0xF8006458    // Plugin entry point, address after the second IVT table
reserv1:                .long 0x0
dcd_ptr:                .long 0x0
boot_data_ptr:          .long 0xF8006420
self_ptr:               .long 0xF8006400
app_code_csf:           .long 0x0 // reserve 4K for csf
reserv2:                .long 0x0
boot_data:              .long 0xF8006000
image_len:              .long 8*1024  // Can copy upto 72K, which is the length of the MX50 OCRAM free space
plugin:                 .long 0x1  // Enable plugin flag

/* Second IVT to give entry point into the bootloader copied to DDR */
ivt2_header:            .long 0x402000D1    //Tag=0xD1, Len=0x0020, Ver=0x40
app2_code_jump_v:       .long startup       // Entry point for the bootloader
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
    push    {r0-r3, lr}

    ldr r0, =BOOT_ROM_BASE_ADDR
    ldr r1, [r0, #ROM_SI_REV_OFFSET]

    cmp r1, #0x20

    // if TO2, increase LDO to 1.3V
    ldr r0, =0x53fa8004
    ldr r1, =0x00194005
    streq r1, [r0]

/*
 * Note: The DDR settings provided below are specific to Freescale development boards and are the latest settings at the time of release.
 * However, it is recommended to contact your Freescale representative in case there are any improvements to these settings.
 */

/*
 * EVK: Rev A: 1GB of DDR for CSD0 and CSD1
 * Rev B: 1GB DDR2 CSD0 only
 */
#ifdef MX53_EVK
    // MX53_EVK Rev A and B

    // IOMUX Setup
    ldr r0, =0x53fa8500
    mov r1, #0x00380000
    mov r2, #0x00200000
    add r3, r1, #0x40

    str r1, [r0, #0x54]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3
    str r3, [r0, #0x58]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3
    str r1, [r0, #0x60]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2
    str r3, [r0, #0x64]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT1
    str r3, [r0, #0x68]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2

    str r2, [r0, #0x70]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_1
    str r1, [r0, #0x74]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS

    str r2, [r0, #0x78]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_0

    str r3, [r0, #0x7c]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0
    str r3, [r0, #0x80]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT0
    str r1, [r0, #0x84]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0
    str r1, [r0, #0x88]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS
    str r3, [r0, #0x90]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1
    str r1, [r0, #0x94]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1

    ldr r0, =0x53fa86f0
    str r1, [r0, #0x0]   //IOMUXC_SW_PAD_CTL_GRP_ADDDS
    mov r2, #0x00000200
    str r2, [r0, #0x4]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE_CTL
    mov r2, #0x00000000
    str r2, [r0, #0xc]   //IOMUXC_SW_PAD_CTL_GRP_DDRPKE

    ldr r0, =0x53fa8700
    str r2, [r0, #0x14]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE
    str r1, [r0, #0x18]   //IOMUXC_SW_PAD_CTL_GRP_B0DS
    str r1, [r0, #0x1c]   //IOMUXC_SW_PAD_CTL_GRP_B1DS
    str r1, [r0, #0x20]   //IOMUXC_SW_PAD_CTL_GRP_CTLDS
    mov r2, #0x06000000
    str r2, [r0, #0x24]   //IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE - DDR_SEL=0
    str r1, [r0, #0x28]   //IOMUXC_SW_PAD_CTL_GRP_B2DS
    str r1, [r0, #0x2c]   //IOMUXC_SW_PAD_CTL_GRP_B3DS

    // Initialize DDR2 memory - Hynix H5PS2G83AFR
    ldr r0, =ESDCTL_REGISTERS_BASE_ADDR

    ldr r1, =0x2b2f3031
    str r1, [r0, #0x088]

    ldr r1, =0x40363333
    str r1, [r0, #0x090]

    // add 3 logic unit of delay to sdclk -- for EVK only
    ldr r1, =0x00000f00
    str r1, [r0, #0x098]

    ldr r1, =0x00000800
    str r1, [r0, #0x0F8]

    ldr r1, =0x01310132
    str r1, [r0, #0x07c]

    ldr r1, =0x0133014b
    str r1, [r0, #0x080]

    // Enable bank interleaving, RALAT = 0x3, DDR2_EN = 1 -- EVK
    ldr r1, =0x000016d0
    str r1, [r0, #0x018]

    // Enable CSD0, CDS1 row width = 15, column width = 10, burst length = 4, data width = 32bit -- EVK
    ldr r1, =0xc4110000
    str r1, [r0, #0x00]

    // tRFC = 78 ck, tXS = 82 ck, tXP = 2 ck, tXPDLL(tXARD) = 2 ck, tFAW = 14 ck, CAS latency = 5 ck
    ldr r1, =0x4d5122d2
    str r1, [r0, #0x0C]

    // tRCD = 5 ck, tRP = 5 ck, tRC = 23 ck, tRAS = 18 ck, tRPA = 1, tWR = 6 ck, tMRD = 2 ck, tCWL = 4 ck
    ldr r1, =0x92d18a22
    str r1, [r0, #0x10]

    // tDLLK(tXSRD) = 200 cycles, tRTP = 3 ck, tWTR = 3ck, tRRD = 3ck
    ldr r1, =0x00c70092
    str r1, [r0, #0x14]

    ldr r1, =0x000026d2
    str r1, [r0, #0x2C]

    ldr r1, =0x009f000e
    str r1, [r0, #0x30]

    ldr r1, =0x12272000
    str r1, [r0, #0x08]

    ldr r1, =0x00030012
    str r1, [r0, #0x04]

    ldr r1, =0x04008010
    str r1, [r0, #0x1C]

    ldr r1, =0x00008032
    str r1, [r0, #0x1C]

    ldr r1, =0x00008033
    str r1, [r0, #0x1C]

    ldr r1, =0x00008031
    str r1, [r0, #0x1C]

    ldr r1, =0x0b5280b0
    str r1, [r0, #0x1C]

    ldr r1, =0x04008010
    str r1, [r0, #0x1C]

    ldr r1, =0x00008020
    str r1, [r0, #0x1C]

    ldr r1, =0x00008020
    str r1, [r0, #0x1C]

    // BL = 4, CAS latency = 5, write recovery = 6
    ldr r1, =0x0a528030
    str r1, [r0, #0x1C]

    ldr r1, =0x03c68031
    str r1, [r0, #0x1C]

    // reduced drive strength, enable 50ohm ODT
    ldr r1, =0x00468031
    str r1, [r0, #0x1C]

    // Even though Rev B does not have DDR on CSD1, keep these mode register
    // initialization sequences for future uses since it does not hurt to keep them
    ldr r1, =0x04008018
    str r1, [r0, #0x1C]

    ldr r1, =0x0000803a
    str r1, [r0, #0x1C]

    ldr r1, =0x0000803b
    str r1, [r0, #0x1C]

    ldr r1, =0x00008039
    str r1, [r0, #0x1C]

    ldr r1, =0x0b528138
    str r1, [r0, #0x1C]

    ldr r1, =0x04008018
    str r1, [r0, #0x1C]

    ldr r1, =0x00008028
    str r1, [r0, #0x1C]

    ldr r1, =0x00008028
    str r1, [r0, #0x1C]

    // BL = 4, CAS latency = 5, write recovery = 6
    ldr r1, =0x0a528038
    str r1, [r0, #0x1C]

    ldr r1, =0x03c68039
    str r1, [r0, #0x1C]

    ldr r1, =0x00468039
    str r1, [r0, #0x1C]

    ldr r1, =0x00005800
    str r1, [r0, #0x20]

    ldr r1, =0x00033337
    str r1, [r0, #0x58]

    ldr r1, =0x00000000
    str r1, [r0, #0x1C]
    b read_sdk
#endif

// ard: 1GB DDR2 CSD0 only, based on TO2 init
#if (defined (MX53_ARD) && defined (BOARD_VERSION1))
    // MX53_ARD

    // IOMUX Setup
    ldr r0, =0x53fa8500
    mov r1, #0x00200000
    mov r2, #0x00200000
    add r3, r1, #0x40
    mov r4, #0x00280000

    str r1, [r0, #0x54]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3
    str r3, [r0, #0x58]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3
    str r1, [r0, #0x60]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2
    str r3, [r0, #0x64]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT1
    str r3, [r0, #0x68]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2

    str r1, [r0, #0x70]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_1 for ARD
    str r4, [r0, #0x74]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS

    str r1, [r0, #0x78]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_0 for ARD
    str r3, [r0, #0x7c]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0
    str r3, [r0, #0x80]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT0
    str r1, [r0, #0x84]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0
    str r4, [r0, #0x88]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS
    str r3, [r0, #0x90]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1
    str r1, [r0, #0x94]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1

    ldr r0, =0x53fa86f0
    str r4, [r0, #0x0]   //IOMUXC_SW_PAD_CTL_GRP_ADDDS
    mov r2, #0x00000200
    str r2, [r0, #0x4]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE_CTL
    mov r2, #0x00000000
    str r2, [r0, #0xc]   //IOMUXC_SW_PAD_CTL_GRP_DDRPKE

    ldr r0, =0x53fa8700
    str r2, [r0, #0x14]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE
    str r1, [r0, #0x18]   //IOMUXC_SW_PAD_CTL_GRP_B0DS
    str r1, [r0, #0x1c]   //IOMUXC_SW_PAD_CTL_GRP_B1DS
    str r4, [r0, #0x20]   //IOMUXC_SW_PAD_CTL_GRP_CTLDS
    mov r2, #0x02000000
    str r2, [r0, #0x24]   //IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE - DDR_SEL=0
    str r1, [r0, #0x28]   //IOMUXC_SW_PAD_CTL_GRP_B2DS
    str r1, [r0, #0x2c]   //IOMUXC_SW_PAD_CTL_GRP_B3DS

    // Initialize DDR2 memory - Hynix H5PS2G83AFR
    ldr r0, =ESDCTL_REGISTERS_BASE_ADDR

    ldr r1, =0x34333936
    str r1, [r0, #0x088]

    ldr r1, =0x49434942
    str r1, [r0, #0x090]

    ldr r1, =0x00000800
    str r1, [r0, #0x0F8]

    ldr r1, =0x01350138
    str r1, [r0, #0x07c]

    ldr r1, =0x01380139
    str r1, [r0, #0x080]

    // Enable bank interleaving, RALAT = 0x3, DDR2_EN = 1 -- ARD
    ldr r1, =0x00001710
    str r1, [r0, #0x018]

    // Enable CSD0, row width = 15, column width = 10, burst length = 4, data width = 32bit -- ARD
    ldr r1, =0x84110000
    str r1, [r0, #0x00]

    // tRFC = 78 ck, tXS = 82 ck, tXP = 2 ck, tXPDLL(tXARD) = 2 ck, tFAW = 14 ck, CAS latency = 5 ck
    ldr r1, =0x4d5122d2
    str r1, [r0, #0x0C]

    // tRCD = 5 ck, tRP = 5 ck, tRC = 23 ck, tRAS = 18 ck, tRPA = 1, tWR = 6 ck, tMRD = 2 ck, tCWL = 4 ck
    ldr r1, =0x92d18a22
    str r1, [r0, #0x10]

    // tDLLK(tXSRD) = 200 cycles, tRTP = 3 ck, tWTR = 3ck, tRRD = 3ck
    ldr r1, =0x00c70092
    str r1, [r0, #0x14]

    ldr r1, =0x000026d2
    str r1, [r0, #0x2C]

    ldr r1, =0x009f000e
    str r1, [r0, #0x30]

    ldr r1, =0x12272000
    str r1, [r0, #0x08]

    ldr r1, =0x00030012
    str r1, [r0, #0x04]

    ldr r1, =0x04008010
    str r1, [r0, #0x1C]

    ldr r1, =0x00008032
    str r1, [r0, #0x1C]

    ldr r1, =0x00008033
    str r1, [r0, #0x1C]

    ldr r1, =0x00008031
    str r1, [r0, #0x1C]

    ldr r1, =0x0b5280b0
    str r1, [r0, #0x1C]

    ldr r1, =0x04008010
    str r1, [r0, #0x1C]

    ldr r1, =0x00008020
    str r1, [r0, #0x1C]

    ldr r1, =0x00008020
    str r1, [r0, #0x1C]

    // BL = 4, CAS latency = 5, write recovery = 6
    ldr r1, =0x0a528030
    str r1, [r0, #0x1C]

    ldr r1, =0x03c68031
    str r1, [r0, #0x1C]

    // full drive strength, enable 50ohm ODT
    ldr r1, =0x00448031
    str r1, [r0, #0x1C]

    // Even though Rev B does not have DDR on CSD1, keep these mode register
    // initialization sequences for future uses since it does not hurt to keep them
    ldr r1, =0x04008018
    str r1, [r0, #0x1C]

    ldr r1, =0x0000803a
    str r1, [r0, #0x1C]

    ldr r1, =0x0000803b
    str r1, [r0, #0x1C]

    ldr r1, =0x00008039
    str r1, [r0, #0x1C]

    ldr r1, =0x0b528138
    str r1, [r0, #0x1C]

    ldr r1, =0x04008018
    str r1, [r0, #0x1C]

    ldr r1, =0x00008028
    str r1, [r0, #0x1C]

    ldr r1, =0x00008028
    str r1, [r0, #0x1C]

    // BL = 4, CAS latency = 5, write recovery = 6
    ldr r1, =0x0a528038
    str r1, [r0, #0x1C]

    ldr r1, =0x03c68039
    str r1, [r0, #0x1C]

    ldr r1, =0x00448039
    str r1, [r0, #0x1C]

    ldr r1, =0x00005800
    str r1, [r0, #0x20]

    ldr r1, =0x00033335
    str r1, [r0, #0x58]

    ldr r1, =0x00000000
    str r1, [r0, #0x1C]
    
    // Enable ZQ calibration to tightly control the impedance of the DDR IO pads
    ldr r1, =0x04b80003
    str r1, [r0, #0x40]

    ldr r0, =CCM_BASE_ADDR
    ldr r1, [r0, #0x14]
    add r1, r1, #0x00010000
    str r1, [r0, #0x14]

    b read_sdk
#endif      // #ifdef MX53_ARD

//cpu2: 1GB of DDR2 for CSD0 and CSD1, slightly different timings than EVK
#ifdef MX53_CPU2
    ldr r0, =0x53fa8500
    mov r1, #0x00380000
    mov r2, #0x00200000
    add r3, r1, #0x40

    str r1, [r0, #0x54]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3
    str r3, [r0, #0x58]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3
    str r1, [r0, #0x60]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2
    str r3, [r0, #0x64]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT1
    str r3, [r0, #0x68]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2
    str r1, [r0, #0x70]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_1
    str r1, [r0, #0x74]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS
    str r1, [r0, #0x78]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_0
    str r3, [r0, #0x7c]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0
    str r3, [r0, #0x80]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT0
    str r1, [r0, #0x84]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0
    str r1, [r0, #0x88]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS
    str r3, [r0, #0x90]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1
    str r1, [r0, #0x94]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1

    ldr r0, =0x53fa86f0
    str r1, [r0, #0x0]   //IOMUXC_SW_PAD_CTL_GRP_ADDDS
    mov r2, #0x00000200
    str r2, [r0, #0x4]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE_CTL
    mov r2, #0x00000000
    str r2, [r0, #0xc]   //IOMUXC_SW_PAD_CTL_GRP_DDRPKE

    ldr r0, =0x53fa8700
    str r2, [r0, #0x14]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE
    str r1, [r0, #0x18]   //IOMUXC_SW_PAD_CTL_GRP_B0DS
    str r1, [r0, #0x1c]   //IOMUXC_SW_PAD_CTL_GRP_B1DS
    str r1, [r0, #0x20]   //IOMUXC_SW_PAD_CTL_GRP_CTLDS
    mov r2, #0x02000000
    str r2, [r0, #0x24]   //IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE - DDR_SEL=0
    str r1, [r0, #0x28]   //IOMUXC_SW_PAD_CTL_GRP_B2DS
    str r1, [r0, #0x2c]   //IOMUXC_SW_PAD_CTL_GRP_B3DS

    // Initialize DDR2 memory - Hynix H5PS2G83AFR
    ldr r0, =ESDCTL_REGISTERS_BASE_ADDR

    ldr r1, =0x2d313331
    str r1, [r0, #0x088]

    ldr r1, =0x393b3836
    str r1, [r0, #0x090]

    ldr r1, =0x00000800
    str r1, [r0, #0x0F8]

    ldr r1, =0x020c0211
    str r1, [r0, #0x07c]

    ldr r1, =0x014c0155
    str r1, [r0, #0x080]

    // Enable bank interleaving, RALAT = 0x4, DDR2_EN = 1
    ldr r1, =0x00001710
    str r1, [r0, #0x018]

    // Enable CSD0, row width = 15, column width = 10, burst length = 4, data width = 32bit
    ldr r1, =0xc4110000
    str r1, [r0, #0x00]

    // tRFC = 78 ck, tXS = 82 ck, tXP = 2 ck, tXPDLL(tXARD) = 2 ck, tFAW = 14 ck, CAS latency = 5 ck
    ldr r1, =0x4d5122d2
    str r1, [r0, #0x0C]

    // tRCD = 5 ck, tRP = 5 ck, tRC = 23 ck, tRAS = 18 ck, tRPA = 1, tWR = 6 ck, tMRD = 2 ck, tCWL = 4 ck
    ldr r1, =0x92d18a22
    str r1, [r0, #0x10]

    // tDLLK(tXSRD) = 200 cycles, tRTP = 3 ck, tWTR = 3ck, tRRD = 3ck
    ldr r1, =0x00c70092
    str r1, [r0, #0x14]

    ldr r1, =0x000026d2
    str r1, [r0, #0x2C]

    ldr r1, =0x009f000e
    str r1, [r0, #0x30]

    ldr r1, =0x12272000
    str r1, [r0, #0x08]

    ldr r1, =0x00030012
    str r1, [r0, #0x04]

    ldr r1, =0x04008010
    str r1, [r0, #0x1C]

    ldr r1, =0x00008032
    str r1, [r0, #0x1C]

    ldr r1, =0x00008033
    str r1, [r0, #0x1C]

    ldr r1, =0x00008031
    str r1, [r0, #0x1C]

    ldr r1, =0x0b5280b0
    str r1, [r0, #0x1C]

    ldr r1, =0x04008010
    str r1, [r0, #0x1C]

    ldr r1, =0x00008020
    str r1, [r0, #0x1C]

    ldr r1, =0x00008020
    str r1, [r0, #0x1C]

    // BL = 4, CAS latency = 5, write recovery = 6
    ldr r1, =0x0a528030
    str r1, [r0, #0x1C]

    ldr r1, =0x03c68031
    str r1, [r0, #0x1C]

    // reduced drive strength, enable 50ohm ODT
    ldr r1, =0x00468031
    str r1, [r0, #0x1C]

    // CSD1 init
    ldr r1, =0x04008018
    str r1, [r0, #0x1C]

    ldr r1, =0x0000803a
    str r1, [r0, #0x1C]

    ldr r1, =0x0000803b
    str r1, [r0, #0x1C]

    ldr r1, =0x00008039
    str r1, [r0, #0x1C]

    ldr r1, =0x0b528138
    str r1, [r0, #0x1C]

    ldr r1, =0x04008018
    str r1, [r0, #0x1C]

    ldr r1, =0x00008028
    str r1, [r0, #0x1C]

    ldr r1, =0x00008028
    str r1, [r0, #0x1C]

    // BL = 4, CAS latency = 5, write recovery = 6
    ldr r1, =0x0a528038
    str r1, [r0, #0x1C]

    ldr r1, =0x03c68039
    str r1, [r0, #0x1C]

    ldr r1, =0x00468039
    str r1, [r0, #0x1C]

    ldr r1, =0x00005800
    str r1, [r0, #0x20]

    ldr r1, =0x00033337
    str r1, [r0, #0x58]

    ldr r1, =0x00000000
    str r1, [r0, #0x1C]
    b read_sdk
#endif

#if defined (MX53_SBRTH_LCB) || defined (MX53_SBRTH_SMD) || (defined (MX53_ARD) && defined (BOARD_VERSION2))
    // Sabretooth init
    ldr r0, =0x53fa8500
    mov r1, #0x00300000
    mov r2, #0x00200000
    add r3, r1, #0x40

    str r1, [r0, #0x54]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3
    str r3, [r0, #0x58]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3
    str r1, [r0, #0x60]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2
    str r3, [r0, #0x64]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT1
    str r3, [r0, #0x68]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2
    str r1, [r0, #0x70]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_1
    str r1, [r0, #0x74]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS
    str r1, [r0, #0x78]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_0
    str r3, [r0, #0x7c]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0
    str r3, [r0, #0x80]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT0
    str r1, [r0, #0x84]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0
    str r1, [r0, #0x88]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS
    str r3, [r0, #0x90]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1
    str r1, [r0, #0x94]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1

    ldr r0, =0x53fa86f0
    str r1, [r0, #0x0]   //IOMUXC_SW_PAD_CTL_GRP_ADDDS for DDR addr bus
    mov r2, #0x00000000
    str r2, [r0, #0x4]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE_CTL
                         //for sDQS[3:0], 1=DDR2, 0=CMOS mode
    str r2, [r0, #0xc]   //IOMUXC_SW_PAD_CTL_GRP_DDRPKE

    ldr r0, =0x53fa8700
    str r2, [r0, #0x14]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE for D[31:0], 1=DDR2, 0=CMOS mode
    str r1, [r0, #0x18]   //IOMUXC_SW_PAD_CTL_GRP_B0DS
    str r1, [r0, #0x1c]   //IOMUXC_SW_PAD_CTL_GRP_B1DS
    str r1, [r0, #0x20]   //IOMUXC_SW_PAD_CTL_GRP_CTLDS for CSD0, CSD1, SDCKE0, SDCKE1, SDWE
    mov r2, #0x04000000
    str r2, [r0, #0x24]   //IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE - DDR_SEL=10
    str r1, [r0, #0x28]   //IOMUXC_SW_PAD_CTL_GRP_B2DS
    str r1, [r0, #0x2c]   //IOMUXC_SW_PAD_CTL_GRP_B3DS

    // Initialize DDR3 memory - Micron DDR3
    ldr r0, =ESDCTL_REGISTERS_BASE_ADDR

    ldr r1, =0x35343535
    str r1, [r0, #0x088]

    ldr r1, =0x4d444c44
    str r1, [r0, #0x090]

    ldr r1, =0x01370138
    str r1, [r0, #0x07c]

    ldr r1, =0x013b013c
    str r1, [r0, #0x080]

    // Enable bank interleaving, RALAT = 0x5, DDR2_EN = 0, WALAT=0x1
    ldr r1, =0x00011740
    str r1, [r0, #0x018]

    // Enable CSD0 and CSD1, row width = 14, column width = 10, burst length = 8, data width = 32bit
    ldr r1, =0xc3190000
    str r1, [r0, #0x00]

    // tRFC=64ck;tXS=68;tXP=3;tXPDLL=10;tFAW=15;CAS=6ck
    ldr r1, =0x9f5152e3
    str r1, [r0, #0x0C]

    // tRCD=6;tRP=6;tRC=21;tRAS=15;tRPA=1;tWR=6;tMRD=4;tCWL=5ck
    ldr r1, =0xb68e8a63
    str r1, [r0, #0x10]

    // tDLLK(tXSRD)=512 cycles; tRTP=4;tWTR=4;tRRD=4
    ldr r1, =0x01ff00db
    str r1, [r0, #0x14]

    ldr r1, =0x000026d2
    str r1, [r0, #0x2C]

    ldr r1, =0x009f0e21
    str r1, [r0, #0x30]

    ldr r1, =0x12273030
    str r1, [r0, #0x08]

    ldr r1, =0x0002002d
    str r1, [r0, #0x04]

    // mode register writes, CSD0
    ldr r1, =0x00008032
    str r1, [r0, #0x1C]

    ldr r1, =0x00008033
    str r1, [r0, #0x1C]

    ldr r1, =0x00028031
    str r1, [r0, #0x1C]

    ldr r1, =0x092080b0
    str r1, [r0, #0x1C]

    ldr r1, =0x04008040
    str r1, [r0, #0x1C]

    // mode register writes, CSD1
    ldr r1, =0x0000803a
    str r1, [r0, #0x1C]

    ldr r1, =0x0000803b
    str r1, [r0, #0x1C]

    ldr r1, =0x00028039
    str r1, [r0, #0x1C]

    ldr r1, =0x09208138
    str r1, [r0, #0x1C]

    ldr r1, =0x04008048
    str r1, [r0, #0x1C]

    ldr r1, =0x00001800
    str r1, [r0, #0x20]

    ldr r1, =0x04b80003
    str r1, [r0, #0x40]

    ldr r1, =0x00022227
    str r1, [r0, #0x58]

    ldr r1, =0x00000000
    str r1, [r0, #0x1C]
    b read_sdk
#endif

//qslvr_lcb_smd:
#if defined (MX53_QS ) || defined (MX53_LCB) || defined (MX53_SMD)
    // Quicksilver init
    ldr r0, =0x53fa8500
    mov r1, #0x00300000
    mov r2, #0x00200000
    add r3, r1, #0x40

    str r1, [r0, #0x54]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3
    str r3, [r0, #0x58]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3
    str r1, [r0, #0x60]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2
    str r3, [r0, #0x64]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT1
    str r3, [r0, #0x68]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2
    str r1, [r0, #0x70]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_1
    str r1, [r0, #0x74]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS
    str r1, [r0, #0x78]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_0
    str r3, [r0, #0x7c]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0
    str r3, [r0, #0x80]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT0
    str r1, [r0, #0x84]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0
    str r1, [r0, #0x88]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS
    str r3, [r0, #0x90]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1
    str r1, [r0, #0x94]   //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1

    ldr r0, =0x53fa86f0
    str r1, [r0, #0x0]   //IOMUXC_SW_PAD_CTL_GRP_ADDDS for DDR addr bus
    mov r2, #0x00000000
    str r2, [r0, #0x4]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE_CTL
                         //for sDQS[3:0], 1=DDR2, 0=CMOS mode
    str r2, [r0, #0xc]   //IOMUXC_SW_PAD_CTL_GRP_DDRPKE

    ldr r0, =0x53fa8700
    str r2, [r0, #0x14]   //IOMUXC_SW_PAD_CTL_GRP_DDRMODE for D[31:0], 1=DDR2, 0=CMOS mode
    str r1, [r0, #0x18]   //IOMUXC_SW_PAD_CTL_GRP_B0DS
    str r1, [r0, #0x1c]   //IOMUXC_SW_PAD_CTL_GRP_B1DS
    str r1, [r0, #0x20]   //IOMUXC_SW_PAD_CTL_GRP_CTLDS for CSD0, CSD1, SDCKE0, SDCKE1, SDWE
    mov r2, #0x04000000
    str r2, [r0, #0x24]   //IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE - DDR_SEL=10
    str r1, [r0, #0x28]   //IOMUXC_SW_PAD_CTL_GRP_B2DS
    str r1, [r0, #0x2c]   //IOMUXC_SW_PAD_CTL_GRP_B3DS

    // Initialize DDR3 memory - Micron DDR3
    ldr r0, =ESDCTL_REGISTERS_BASE_ADDR

    ldr r1, =0x32383535
    str r1, [r0, #0x088]

    ldr r1, =0x40383538
    str r1, [r0, #0x090]

    ldr r1, =0x00000800
    str r1, [r0, #0x0F8]

    ldr r1, =0x0136014d
    str r1, [r0, #0x07c]

    ldr r1, =0x01510141
    str r1, [r0, #0x080]

    // Enable bank interleaving, RALAT = 0x5, DDR2_EN = 0, WALAT=0x1
    ldr r1, =0x00011740
    str r1, [r0, #0x018]

    // Enable CSD0 and CSD1, row width = 14, column width = 10, burst length = 8, data width = 32bit
    ldr r1, =0xc3190000
    str r1, [r0, #0x00]

    // tRFC=64ck;tXS=68;tXP=3;tXPDLL=10;tFAW=15;CAS=6ck
    ldr r1, =0x9f5152e3
    str r1, [r0, #0x0C]

    // tRCD=6;tRP=6;tRC=21;tRAS=15;tRPA=1;tWR=6;tMRD=4;tCWL=5ck
    ldr r1, =0xb68e8a63
    str r1, [r0, #0x10]

    // tDLLK(tXSRD)=512 cycles; tRTP=4;tWTR=4;tRRD=4
    ldr r1, =0x01ff00db
    str r1, [r0, #0x14]

    ldr r1, =0x000026d2
    str r1, [r0, #0x2C]

    ldr r1, =0x009f0e21
    str r1, [r0, #0x30]

    ldr r1, =0x12273030
    str r1, [r0, #0x08]

    ldr r1, =0x0002002d
    str r1, [r0, #0x04]

    // mode register writes, CSD0
    ldr r1, =0x00008032
    str r1, [r0, #0x1C]

    ldr r1, =0x00008033
    str r1, [r0, #0x1C]

    ldr r1, =0x00028031
    str r1, [r0, #0x1C]

    ldr r1, =0x092080b0
    str r1, [r0, #0x1C]

    ldr r1, =0x04008040
    str r1, [r0, #0x1C]

    // mode register writes, CSD1
    ldr r1, =0x0000803a
    str r1, [r0, #0x1C]

    ldr r1, =0x0000803b
    str r1, [r0, #0x1C]

    ldr r1, =0x00028039
    str r1, [r0, #0x1C]

    ldr r1, =0x09208138
    str r1, [r0, #0x1C]

    ldr r1, =0x04008048
    str r1, [r0, #0x1C]

    ldr r1, =0x00001800
    str r1, [r0, #0x20]

    ldr r1, =0x04b80003
    str r1, [r0, #0x40]

    ldr r1, =0x00022227
    str r1, [r0, #0x58]

    ldr r1, =0x00000000
    str r1, [r0, #0x1C]
    b read_sdk
#endif

read_sdk:
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

before_calling_rom___pu_irom_hwcnfg_setup:
    /* Different ROM address for TO 1.0 & TO 2.0 */
    moveq r4, #0x1800
    addeq r4, r4, #0x4d
    beq 2f
    mov r4, #0x400000
    add r4, r4, #0x5000
    add r4, r4, #0xc7

2:  blx r4 // This address might change in future ROM versions
after_calling_rom___pu_irom_hwcnfg_setup:

// To return to ROM from plugin, we need to fill in these argument.
// Here is what need to do:
// Need to construct the paramters for this function before return to ROM:
// plugin_download(void **start, size_t *bytes, UINT32 *ivt_offset)
    pop {r0-r3, lr}
    ldr r4, DDR_DEST_ADDR
    str r4, [r0]
    ldr r4, COPY_SIZE
    str r4, [r1]
    mov r4, #0x400  /* Point to the second IVT table at offset 0x42C */
    add r4, r4, #0x2C
    str r4, [r2]
    mov r0, #1

    bx lr          // return back to ROM code

DDR_DEST_ADDR:    .word   IMAGE_ENTRY_ADDR
COPY_SIZE:        .word   IMAGE_SIZE
BOOT_DATA:        .word   IMAGE_ENTRY_ADDR
                  .word   IMAGE_SIZE  //real data to be copied by the pu_irom_hwcnfg_setup()
                  .word   0

.endm   //plat_dcd_startup

#define PLATFORM_ASM_STARTUP           platform_asm_startup
.macro platform_asm_startup


    // explicitly disable L2 cache
    mrc 15, 0, r0, c1, c0, 1
    bic r0, r0, #0x2
    mcr 15, 0, r0, c1, c0, 1

    // reconfigure L2 cache aux control reg
    mov r0, #0xC0		// tag RAM
    add r0, r0, #0x4	// data RAM
    orr r0, r0, #(1 << 24)    // disable write allocate delay
    orr r0, r0, #(1 << 23)    // disable write allocate combine
    orr r0, r0, #(1 << 22)    // disable write allocate

    mcr 15, 1, r0, c9, c0, 2

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
        ldr r0, =AIPS1_BASE_ADDR
        ldr r1, =0x77777777
        str r1, [r0, #0x00]
        str r1, [r0, #0x04]
        ldr r0, =AIPS2_BASE_ADDR
        str r1, [r0, #0x00]
        str r1, [r0, #0x04]

    .endm /* init_aips */


#endif //_PLAT_STARTUP_H_
