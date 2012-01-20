//*================================================================================================
//* Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
//* THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
//* BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
//* Freescale Semiconductor, Inc.
//*================================================================================================
// Initialization script for MX53 SMD, LCB, and ARD rev B, DDR3
// Version 1.0
// Version 1.1 (July 8, 2011)
// - change ESDREF[REF_SEL]=01 (for 32KHz), from incorrect setting of 00 (64KHz)
// - change DDR3 MR0 write to "setmem /32 0x63fd901c = 0x052080b0" from "0x092080b0"
//    this changed write recovery from 8 clocks to 6 clocks (in line with ESDCFG1[tWR]) 
// Version 1.2 (July 22, 2011)
// - changed WALAT = 0x0 in ESDMISC (was 0x1).  
// Version 1.3 (Nov 7, 2011)
// - uncommented FRC_MSR and palced after delay line register settings
// - provided more comments for delay line calibrated values
//*================================================================================================

wait = on

//*================================================================================================
// init ARM
//*================================================================================================
 
//*================================================================================================
// Disable WDOG
//*================================================================================================
setmem /16 0x53f98000 = 0x30

//*================================================================================================
// Enable all clocks (they are disabled by ROM code)
//*================================================================================================
setmem /32 0x53fd4068 = 0xffffffff
setmem /32 0x53fd406c = 0xffffffff
setmem /32 0x53fd4070 = 0xffffffff
setmem /32 0x53fd4074 = 0xffffffff
setmem /32 0x53fd4078 = 0xffffffff
setmem /32 0x53fd407c = 0xffffffff
setmem /32 0x53fd4080 = 0xffffffff
setmem /32 0x53fd4084 = 0xffffffff

//*================================================================================================
// Initialization script for 32 bit DDR2 (CS0+CS1) 
//*================================================================================================

// DDR3 IOMUX configuration
//* Global pad control options */
setmem /32 0x53fa86f4 = 0x00000000  //IOMUXC_SW_PAD_CTL_GRP_DDRMODE_CTL for sDQS[3:0], 1=DDR2, 0=CMOS mode
setmem /32 0x53fa8714 = 0x00000000  //IOMUXC_SW_PAD_CTL_GRP_DDRMODE for D[31:0], 1=DDR2, 0=CMOS mode
setmem /32 0x53fa86fc = 0x00000000  //IOMUXC_SW_PAD_CTL_GRP_DDRPKE

setmem /32 0x53fa8724 = 0x04000000  //IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE - DDR_SEL=10 

//* Data bus byte lane pad drive strength control options */
setmem /32 0x53fa872c = 0x00300000  //IOMUXC_SW_PAD_CTL_GRP_B3DS
setmem /32 0x53fa8554 = 0x00300000  //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3
setmem /32 0x53fa8558 = 0x00300040  //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3

setmem /32 0x53fa8728 = 0x00300000  //IOMUXC_SW_PAD_CTL_GRP_B2DS
setmem /32 0x53fa8560 = 0x00300000  //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2
setmem /32 0x53fa8568 = 0x00300040  //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2

setmem /32 0x53fa871c = 0x00300000  //IOMUXC_SW_PAD_CTL_GRP_B1DS
setmem /32 0x53fa8594 = 0x00300000  //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1
setmem /32 0x53fa8590 = 0x00300040  //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1

setmem /32 0x53fa8718 = 0x00300000  //IOMUXC_SW_PAD_CTL_GRP_B0DS
setmem /32 0x53fa8584 = 0x00300000  //IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0
setmem /32 0x53fa857c = 0x00300040  //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0

//* SDCLK pad drive strength control options */
setmem /32 0x53fa8578 = 0x00300000  //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_0
setmem /32 0x53fa8570 = 0x00300000  //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_1

//* Control and addr bus pad drive strength control options */
setmem /32 0x53fa8574 = 0x00300000  //IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS
setmem /32 0x53fa8588 = 0x00300000  //IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS
setmem /32 0x53fa86f0 = 0x00300000  //IOMUXC_SW_PAD_CTL_GRP_ADDDS for DDR addr bus
setmem /32 0x53fa8720 = 0x00300000  //IOMUXC_SW_PAD_CTL_GRP_CTLDS for CSD0, CSD1, SDCKE0, SDCKE1, SDWE
setmem /32 0x53fa8564 = 0x00300040  //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT1
setmem /32 0x53fa8580 = 0x00300040  //IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT0

// Initialize DDR3 memory - Micron MT41J128M16-187E
// calibrated values 
// Note: delay values found optimized for one QuickStart board and the calibrated values
// were simply re-used on other ARD and SMD boards
// It is strongly recommended for the user to run calibration code and find the values to fit their particular board.
setmem /32 0x63fd9088 = 0x35343535 //read delay lines
setmem /32 0x63fd9090 = 0x4d444c44 //write delay lines

setmem /32 0x63fd907c = 0x01370138 //DQS gating 0
setmem /32 0x63fd9080 = 0x013b013c //DQS gating 1

setmem /32 0x63fd90F8 = 0x00000800 //Measure unit

//* CPU3 Board setting
// Enable bank interleaving, Address mirror on, WALAT = 0x1, RALAT = 0x5, DDR2_EN = 0
//setmem /32 0x63fd9018 = 0x00091740 //Misc register: 

//* QuickStart, ARD, and SMD board setting
// Enable bank interleaving, Address mirror off, WALAT = 0x0, RALAT = 0x5, DDR2_EN = 0
setmem /32 0x63fd9018 = 0x00001740 //Misc register

// Enable CSD0 and CSD1, row width = 14, column width = 10, burst length = 8, data width = 32bit
setmem /32 0x63fd9000 = 0xc3190000 //Main control register
// tRFC=64ck;tXS=68;tXP=3;tXPDLL=10;tFAW=15;CAS=6ck
setmem /32 0x63fd900C = 0x9f5152e3 //timing configuration Reg 0. 
// tRCD=6;tRP=6;tRC=21;tRAS=15;tRPA=1;tWR=6;tMRD=4;tCWL=5ck
setmem /32 0x63fd9010 = 0xb68e8a63 //timing configuration Reg 1
// tDLLK(tXSRD)=512 cycles; tRTP=4;tWTR=4;tRRD=4
setmem /32 0x63fd9014 = 0x01ff00db //timing configuration Reg 2
setmem /32 0x63fd902c = 0x000026d2 //command delay (default)
setmem /32 0x63fd9030 = 0x009f0e21 //out of reset delays
// Keep tAOFPD, tAONPD, tANPD, and tAXPD as default since they are bigger than calc values
setmem /32 0x63fd9008 = 0x12273030 //ODT timings 
// tCKE=3; tCKSRX=5; tCKSRE=5
setmem /32 0x63fd9004 = 0x0002002d //Power down control

//**********************************
//DDR device configuration:
//**********************************
//**********************************
// CS0:
//**********************************
setmem /32 0x63fd901c = 0x00008032 //write mode reg MR2 with cs0 (see below for settings)
// Full array self refresh 
// Rtt_WR disabled (no ODT at IO CMOS operation) 
// Manual self refresh
// CWS=5

setmem /32 0x63fd901c = 0x00008033 //write mode reg MR3 with cs0 .
setmem /32 0x63fd901c = 0x00028031 //write mode reg MR1 with cs0. ODS=01: out buff= RZQ/7 (see below for settings)
// out impedance = RZQ/7 
// Rtt_nom disabled (no ODT at IO CMOS operation) 
// Aditive latency off
// write leveling disabled
// tdqs (differential?) disabled

setmem /32 0x63fd901c = 0x052080b0 //write mode reg MR0 with cs0 , with dll_rst0,  (WR)=6, CL=6, DLL_reset=1
setmem /32 0x63fd901c = 0x04008040 //ZQ calibration with cs0 (A10 high indicates ZQ cal long ZQCL)

//**********************************
// CS1:
//**********************************
setmem /32 0x63fd901c = 0x0000803a //write mode reg MR2 with cs1 . 
setmem /32 0x63fd901c = 0x0000803b //write mode reg MR3 with cs1
setmem /32 0x63fd901c = 0x00028039 //write mode reg MR1 with cs1. ODS=01: out buff= RZQ/7
setmem /32 0x63fd901c = 0x05208138 //write mode reg MR0 with cs1, write recovery (WR)=6, CL=6, DLL_reset=1 
setmem /32 0x63fd901c = 0x04008048 //ZQ calibration with cs1 (A10 high indicates ZQ cal long ZQCL)
//**********************************

// Old value, REF_SEL inocrrectly set for 64kHz
//setmem /32 0x63fd9020 = 0x00001800 // Refresh control register
// correct REF_SEL setting of 32kHz
setmem /32 0x63fd9020 = 0x00005800 // Refresh control register
setmem /32 0x63fd9040 = 0x04b80003 // ZQ HW control
setmem /32 0x63fd9058 = 0x00022227 // ODT control register

setmem /32 0x63fd901c = 0x00000000  

// CLKO muxing (comment out for now till needed to avoid conflicts with intended usage of signals)
//setmem /32 0x53FA8314 = 0
//setmem /32 0x53FA8320 = 0x4
//setmem /32 0x53FD4060 = 0x01e900f0

// For TO2 only, increase LDO for VDIG_PLL to 1.3V
setmem /32 0x53fa8004 = 0x00194005
