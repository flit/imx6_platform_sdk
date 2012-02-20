/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _ECSPI_H
#define _ECSPI_H

#include "regs.h"

#ifndef REGS_ECSPI_BASE
#define REGS_ECSPI0_BASE (REGS_BASE + 0x02008000)
#define REGS_ECSPI1_BASE (REGS_BASE + 0x0200c000)
#define REGS_ECSPI2_BASE (REGS_BASE + 0x02010000)
#define REGS_ECSPI3_BASE (REGS_BASE + 0x02014000)
#define REGS_ECSPI4_BASE (REGS_BASE + 0x02018000)
#define REGS_ECSPI_BASE(x) ( x == 0 ? REGS_ECSPI0_BASE : x == 1 ? REGS_ECSPI1_BASE : x == 2 ? REGS_ECSPI2_BASE : x == 3 ? REGS_ECSPI3_BASE : x == 4 ? REGS_ECSPI4_BASE : 0xffff0000)

#endif


/*
 * HW_ECSPI_RXDATA - Receive Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ECSPI_RXDATA : 32;

    } B;
} hw_ecspi_rxdata_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_RXDATA register
 */
#define HW_ECSPI_RXDATA_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_RXDATA(x)           (*(volatile hw_ecspi_rxdata_t *) HW_ECSPI_RXDATA_ADDR(x))
#define HW_ECSPI_RXDATA_RD(x)        (HW_ECSPI_RXDATA(x).U)
#define HW_ECSPI_RXDATA_WR(x, v)     (HW_ECSPI_RXDATA(x).U = (v))
#define HW_ECSPI_RXDATA_SET(x, v)    (HW_ECSPI_RXDATA_WR(x, HW_ECSPI_RXDATA_RD(x) |  (v)))
#define HW_ECSPI_RXDATA_CLR(x, v)    (HW_ECSPI_RXDATA_WR(x, HW_ECSPI_RXDATA_RD(x) & ~(v)))
#define HW_ECSPI_RXDATA_TOG(x, v)    (HW_ECSPI_RXDATA_WR(x, HW_ECSPI_RXDATA_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_RXDATA bitfields
 */

/* --- Register HW_ECSPI_RXDATA, field ECSPI_RXDATA */

#define BP_ECSPI_RXDATA_ECSPI_RXDATA      0
#define BM_ECSPI_RXDATA_ECSPI_RXDATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_RXDATA_ECSPI_RXDATA(v)   ((((reg32_t) v) << 0) & BM_ECSPI_RXDATA_ECSPI_RXDATA)
#else
#define BF_ECSPI_RXDATA_ECSPI_RXDATA(v)   (((v) << 0) & BM_ECSPI_RXDATA_ECSPI_RXDATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_RXDATA_ECSPI_RXDATA(v)   BF_CS1(ECSPI_RXDATA, ECSPI_RXDATA, v)
#endif

/*
 * HW_ECSPI_TXDATA - Transmit Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ECSPI_TXDATA : 32;

    } B;
} hw_ecspi_txdata_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_TXDATA register
 */
#define HW_ECSPI_TXDATA_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_TXDATA(x)           (*(volatile hw_ecspi_txdata_t *) HW_ECSPI_TXDATA_ADDR(x))
#define HW_ECSPI_TXDATA_RD(x)        (HW_ECSPI_TXDATA(x).U)
#define HW_ECSPI_TXDATA_WR(x, v)     (HW_ECSPI_TXDATA(x).U = (v))
#define HW_ECSPI_TXDATA_SET(x, v)    (HW_ECSPI_TXDATA_WR(x, HW_ECSPI_TXDATA_RD(x) |  (v)))
#define HW_ECSPI_TXDATA_CLR(x, v)    (HW_ECSPI_TXDATA_WR(x, HW_ECSPI_TXDATA_RD(x) & ~(v)))
#define HW_ECSPI_TXDATA_TOG(x, v)    (HW_ECSPI_TXDATA_WR(x, HW_ECSPI_TXDATA_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_TXDATA bitfields
 */

/* --- Register HW_ECSPI_TXDATA, field ECSPI_TXDATA */

#define BP_ECSPI_TXDATA_ECSPI_TXDATA      0
#define BM_ECSPI_TXDATA_ECSPI_TXDATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TXDATA_ECSPI_TXDATA(v)   ((((reg32_t) v) << 0) & BM_ECSPI_TXDATA_ECSPI_TXDATA)
#else
#define BF_ECSPI_TXDATA_ECSPI_TXDATA(v)   (((v) << 0) & BM_ECSPI_TXDATA_ECSPI_TXDATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TXDATA_ECSPI_TXDATA(v)   BF_CS1(ECSPI_TXDATA, ECSPI_TXDATA, v)
#endif

/*
 * HW_ECSPI_CONREG - Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EN : 1;
        unsigned MODE : 1;
        unsigned HT : 1;
        unsigned XCH : 1;
        unsigned SMC : 1;
        unsigned POL : 1;
        unsigned CHANNEL : 4;
        unsigned PHA : 1;
        unsigned SSCTL : 1;
        unsigned SSPOL : 1;
        unsigned POST : 4;
        unsigned DRCTL : 2;
        unsigned RESERVED0 : 2;
        unsigned CHIP : 2;
        unsigned PRE : 4;
        unsigned RESERVED1 : 2;
        unsigned DATA : 3;
        unsigned DRCTL : 2;
        unsigned CHANNEL : 2;
        unsigned RESERVED2 : 1;
        unsigned BURST : 12;

    } B;
} hw_ecspi_conreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_CONREG register
 */
#define HW_ECSPI_CONREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_CONREG(x)           (*(volatile hw_ecspi_conreg_t *) HW_ECSPI_CONREG_ADDR(x))
#define HW_ECSPI_CONREG_RD(x)        (HW_ECSPI_CONREG(x).U)
#define HW_ECSPI_CONREG_WR(x, v)     (HW_ECSPI_CONREG(x).U = (v))
#define HW_ECSPI_CONREG_SET(x, v)    (HW_ECSPI_CONREG_WR(x, HW_ECSPI_CONREG_RD(x) |  (v)))
#define HW_ECSPI_CONREG_CLR(x, v)    (HW_ECSPI_CONREG_WR(x, HW_ECSPI_CONREG_RD(x) & ~(v)))
#define HW_ECSPI_CONREG_TOG(x, v)    (HW_ECSPI_CONREG_WR(x, HW_ECSPI_CONREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_CONREG bitfields
 */

/* --- Register HW_ECSPI_CONREG, field EN */

#define BP_ECSPI_CONREG_EN      0
#define BM_ECSPI_CONREG_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_EN(v)   ((((reg32_t) v) << 0) & BM_ECSPI_CONREG_EN)
#else
#define BF_ECSPI_CONREG_EN(v)   (((v) << 0) & BM_ECSPI_CONREG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_EN(v)   BF_CS1(ECSPI_CONREG, EN, v)
#endif

/* --- Register HW_ECSPI_CONREG, field MODE */

#define BP_ECSPI_CONREG_MODE      1
#define BM_ECSPI_CONREG_MODE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_MODE(v)   ((((reg32_t) v) << 1) & BM_ECSPI_CONREG_MODE)
#else
#define BF_ECSPI_CONREG_MODE(v)   (((v) << 1) & BM_ECSPI_CONREG_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_MODE(v)   BF_CS1(ECSPI_CONREG, MODE, v)
#endif

/* --- Register HW_ECSPI_CONREG, field HT */

#define BP_ECSPI_CONREG_HT      1
#define BM_ECSPI_CONREG_HT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_HT(v)   ((((reg32_t) v) << 1) & BM_ECSPI_CONREG_HT)
#else
#define BF_ECSPI_CONREG_HT(v)   (((v) << 1) & BM_ECSPI_CONREG_HT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_HT(v)   BF_CS1(ECSPI_CONREG, HT, v)
#endif

/* --- Register HW_ECSPI_CONREG, field XCH */

#define BP_ECSPI_CONREG_XCH      2
#define BM_ECSPI_CONREG_XCH      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_XCH(v)   ((((reg32_t) v) << 2) & BM_ECSPI_CONREG_XCH)
#else
#define BF_ECSPI_CONREG_XCH(v)   (((v) << 2) & BM_ECSPI_CONREG_XCH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_XCH(v)   BF_CS1(ECSPI_CONREG, XCH, v)
#endif

/* --- Register HW_ECSPI_CONREG, field SMC */

#define BP_ECSPI_CONREG_SMC      3
#define BM_ECSPI_CONREG_SMC      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_SMC(v)   ((((reg32_t) v) << 3) & BM_ECSPI_CONREG_SMC)
#else
#define BF_ECSPI_CONREG_SMC(v)   (((v) << 3) & BM_ECSPI_CONREG_SMC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_SMC(v)   BF_CS1(ECSPI_CONREG, SMC, v)
#endif

/* --- Register HW_ECSPI_CONREG, field POL */

#define BP_ECSPI_CONREG_POL      4
#define BM_ECSPI_CONREG_POL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_POL(v)   ((((reg32_t) v) << 4) & BM_ECSPI_CONREG_POL)
#else
#define BF_ECSPI_CONREG_POL(v)   (((v) << 4) & BM_ECSPI_CONREG_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_POL(v)   BF_CS1(ECSPI_CONREG, POL, v)
#endif

/* --- Register HW_ECSPI_CONREG, field CHANNEL */

#define BP_ECSPI_CONREG_CHANNEL      4
#define BM_ECSPI_CONREG_CHANNEL      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_CHANNEL(v)   ((((reg32_t) v) << 4) & BM_ECSPI_CONREG_CHANNEL)
#else
#define BF_ECSPI_CONREG_CHANNEL(v)   (((v) << 4) & BM_ECSPI_CONREG_CHANNEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_CHANNEL(v)   BF_CS1(ECSPI_CONREG, CHANNEL, v)
#endif

/* --- Register HW_ECSPI_CONREG, field PHA */

#define BP_ECSPI_CONREG_PHA      5
#define BM_ECSPI_CONREG_PHA      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_PHA(v)   ((((reg32_t) v) << 5) & BM_ECSPI_CONREG_PHA)
#else
#define BF_ECSPI_CONREG_PHA(v)   (((v) << 5) & BM_ECSPI_CONREG_PHA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_PHA(v)   BF_CS1(ECSPI_CONREG, PHA, v)
#endif

/* --- Register HW_ECSPI_CONREG, field SSCTL */

#define BP_ECSPI_CONREG_SSCTL      6
#define BM_ECSPI_CONREG_SSCTL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_SSCTL(v)   ((((reg32_t) v) << 6) & BM_ECSPI_CONREG_SSCTL)
#else
#define BF_ECSPI_CONREG_SSCTL(v)   (((v) << 6) & BM_ECSPI_CONREG_SSCTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_SSCTL(v)   BF_CS1(ECSPI_CONREG, SSCTL, v)
#endif

/* --- Register HW_ECSPI_CONREG, field SSPOL */

#define BP_ECSPI_CONREG_SSPOL      7
#define BM_ECSPI_CONREG_SSPOL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_SSPOL(v)   ((((reg32_t) v) << 7) & BM_ECSPI_CONREG_SSPOL)
#else
#define BF_ECSPI_CONREG_SSPOL(v)   (((v) << 7) & BM_ECSPI_CONREG_SSPOL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_SSPOL(v)   BF_CS1(ECSPI_CONREG, SSPOL, v)
#endif

/* --- Register HW_ECSPI_CONREG, field POST */

#define BP_ECSPI_CONREG_POST      8
#define BM_ECSPI_CONREG_POST      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_POST(v)   ((((reg32_t) v) << 8) & BM_ECSPI_CONREG_POST)
#else
#define BF_ECSPI_CONREG_POST(v)   (((v) << 8) & BM_ECSPI_CONREG_POST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_POST(v)   BF_CS1(ECSPI_CONREG, POST, v)
#endif

/* --- Register HW_ECSPI_CONREG, field DRCTL */

#define BP_ECSPI_CONREG_DRCTL      8
#define BM_ECSPI_CONREG_DRCTL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_DRCTL(v)   ((((reg32_t) v) << 8) & BM_ECSPI_CONREG_DRCTL)
#else
#define BF_ECSPI_CONREG_DRCTL(v)   (((v) << 8) & BM_ECSPI_CONREG_DRCTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_DRCTL(v)   BF_CS1(ECSPI_CONREG, DRCTL, v)
#endif

/* --- Register HW_ECSPI_CONREG, field CHIP */

#define BP_ECSPI_CONREG_CHIP      12
#define BM_ECSPI_CONREG_CHIP      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_CHIP(v)   ((((reg32_t) v) << 12) & BM_ECSPI_CONREG_CHIP)
#else
#define BF_ECSPI_CONREG_CHIP(v)   (((v) << 12) & BM_ECSPI_CONREG_CHIP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_CHIP(v)   BF_CS1(ECSPI_CONREG, CHIP, v)
#endif

/* --- Register HW_ECSPI_CONREG, field PRE */

#define BP_ECSPI_CONREG_PRE      12
#define BM_ECSPI_CONREG_PRE      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_PRE(v)   ((((reg32_t) v) << 12) & BM_ECSPI_CONREG_PRE)
#else
#define BF_ECSPI_CONREG_PRE(v)   (((v) << 12) & BM_ECSPI_CONREG_PRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_PRE(v)   BF_CS1(ECSPI_CONREG, PRE, v)
#endif

/* --- Register HW_ECSPI_CONREG, field DATA */

#define BP_ECSPI_CONREG_DATA      16
#define BM_ECSPI_CONREG_DATA      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_DATA(v)   ((((reg32_t) v) << 16) & BM_ECSPI_CONREG_DATA)
#else
#define BF_ECSPI_CONREG_DATA(v)   (((v) << 16) & BM_ECSPI_CONREG_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_DATA(v)   BF_CS1(ECSPI_CONREG, DATA, v)
#endif

/* --- Register HW_ECSPI_CONREG, field DRCTL */

#define BP_ECSPI_CONREG_DRCTL      16
#define BM_ECSPI_CONREG_DRCTL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_DRCTL(v)   ((((reg32_t) v) << 16) & BM_ECSPI_CONREG_DRCTL)
#else
#define BF_ECSPI_CONREG_DRCTL(v)   (((v) << 16) & BM_ECSPI_CONREG_DRCTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_DRCTL(v)   BF_CS1(ECSPI_CONREG, DRCTL, v)
#endif

/* --- Register HW_ECSPI_CONREG, field CHANNEL */

#define BP_ECSPI_CONREG_CHANNEL      18
#define BM_ECSPI_CONREG_CHANNEL      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_CHANNEL(v)   ((((reg32_t) v) << 18) & BM_ECSPI_CONREG_CHANNEL)
#else
#define BF_ECSPI_CONREG_CHANNEL(v)   (((v) << 18) & BM_ECSPI_CONREG_CHANNEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_CHANNEL(v)   BF_CS1(ECSPI_CONREG, CHANNEL, v)
#endif

/* --- Register HW_ECSPI_CONREG, field BURST */

#define BP_ECSPI_CONREG_BURST      20
#define BM_ECSPI_CONREG_BURST      0xfff00000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_BURST(v)   ((((reg32_t) v) << 20) & BM_ECSPI_CONREG_BURST)
#else
#define BF_ECSPI_CONREG_BURST(v)   (((v) << 20) & BM_ECSPI_CONREG_BURST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_BURST(v)   BF_CS1(ECSPI_CONREG, BURST, v)
#endif

/*
 * HW_ECSPI_CONFIGREG - Config Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SCLK : 4;
        unsigned SCLK : 4;
        unsigned SS : 4;
        unsigned SS : 4;
        unsigned DATA : 4;
        unsigned SCLK : 4;
        unsigned HT : 5;
        unsigned RESERVED0 : 3;

    } B;
} hw_ecspi_configreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_CONFIGREG register
 */
#define HW_ECSPI_CONFIGREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_CONFIGREG(x)           (*(volatile hw_ecspi_configreg_t *) HW_ECSPI_CONFIGREG_ADDR(x))
#define HW_ECSPI_CONFIGREG_RD(x)        (HW_ECSPI_CONFIGREG(x).U)
#define HW_ECSPI_CONFIGREG_WR(x, v)     (HW_ECSPI_CONFIGREG(x).U = (v))
#define HW_ECSPI_CONFIGREG_SET(x, v)    (HW_ECSPI_CONFIGREG_WR(x, HW_ECSPI_CONFIGREG_RD(x) |  (v)))
#define HW_ECSPI_CONFIGREG_CLR(x, v)    (HW_ECSPI_CONFIGREG_WR(x, HW_ECSPI_CONFIGREG_RD(x) & ~(v)))
#define HW_ECSPI_CONFIGREG_TOG(x, v)    (HW_ECSPI_CONFIGREG_WR(x, HW_ECSPI_CONFIGREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_CONFIGREG bitfields
 */

/* --- Register HW_ECSPI_CONFIGREG, field SCLK */

#define BP_ECSPI_CONFIGREG_SCLK      0
#define BM_ECSPI_CONFIGREG_SCLK      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SCLK(v)   ((((reg32_t) v) << 0) & BM_ECSPI_CONFIGREG_SCLK)
#else
#define BF_ECSPI_CONFIGREG_SCLK(v)   (((v) << 0) & BM_ECSPI_CONFIGREG_SCLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONFIGREG_SCLK(v)   BF_CS1(ECSPI_CONFIGREG, SCLK, v)
#endif

/* --- Register HW_ECSPI_CONFIGREG, field SCLK */

#define BP_ECSPI_CONFIGREG_SCLK      4
#define BM_ECSPI_CONFIGREG_SCLK      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SCLK(v)   ((((reg32_t) v) << 4) & BM_ECSPI_CONFIGREG_SCLK)
#else
#define BF_ECSPI_CONFIGREG_SCLK(v)   (((v) << 4) & BM_ECSPI_CONFIGREG_SCLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONFIGREG_SCLK(v)   BF_CS1(ECSPI_CONFIGREG, SCLK, v)
#endif

/* --- Register HW_ECSPI_CONFIGREG, field SS */

#define BP_ECSPI_CONFIGREG_SS      8
#define BM_ECSPI_CONFIGREG_SS      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SS(v)   ((((reg32_t) v) << 8) & BM_ECSPI_CONFIGREG_SS)
#else
#define BF_ECSPI_CONFIGREG_SS(v)   (((v) << 8) & BM_ECSPI_CONFIGREG_SS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONFIGREG_SS(v)   BF_CS1(ECSPI_CONFIGREG, SS, v)
#endif

/* --- Register HW_ECSPI_CONFIGREG, field SS */

#define BP_ECSPI_CONFIGREG_SS      12
#define BM_ECSPI_CONFIGREG_SS      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SS(v)   ((((reg32_t) v) << 12) & BM_ECSPI_CONFIGREG_SS)
#else
#define BF_ECSPI_CONFIGREG_SS(v)   (((v) << 12) & BM_ECSPI_CONFIGREG_SS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONFIGREG_SS(v)   BF_CS1(ECSPI_CONFIGREG, SS, v)
#endif

/* --- Register HW_ECSPI_CONFIGREG, field DATA */

#define BP_ECSPI_CONFIGREG_DATA      16
#define BM_ECSPI_CONFIGREG_DATA      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_DATA(v)   ((((reg32_t) v) << 16) & BM_ECSPI_CONFIGREG_DATA)
#else
#define BF_ECSPI_CONFIGREG_DATA(v)   (((v) << 16) & BM_ECSPI_CONFIGREG_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONFIGREG_DATA(v)   BF_CS1(ECSPI_CONFIGREG, DATA, v)
#endif

/* --- Register HW_ECSPI_CONFIGREG, field SCLK */

#define BP_ECSPI_CONFIGREG_SCLK      20
#define BM_ECSPI_CONFIGREG_SCLK      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SCLK(v)   ((((reg32_t) v) << 20) & BM_ECSPI_CONFIGREG_SCLK)
#else
#define BF_ECSPI_CONFIGREG_SCLK(v)   (((v) << 20) & BM_ECSPI_CONFIGREG_SCLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONFIGREG_SCLK(v)   BF_CS1(ECSPI_CONFIGREG, SCLK, v)
#endif

/* --- Register HW_ECSPI_CONFIGREG, field HT */

#define BP_ECSPI_CONFIGREG_HT      24
#define BM_ECSPI_CONFIGREG_HT      0x1f000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_HT(v)   ((((reg32_t) v) << 24) & BM_ECSPI_CONFIGREG_HT)
#else
#define BF_ECSPI_CONFIGREG_HT(v)   (((v) << 24) & BM_ECSPI_CONFIGREG_HT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONFIGREG_HT(v)   BF_CS1(ECSPI_CONFIGREG, HT, v)
#endif

/*
 * HW_ECSPI_INTREG - Interrupt Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TEEN : 1;
        unsigned THEN : 1;
        unsigned TFEN : 1;
        unsigned RREN : 1;
        unsigned RHEN : 1;
        unsigned RFEN : 1;
        unsigned ROEN : 1;
        unsigned TCEN : 1;
        unsigned RESERVED0 : 24;

    } B;
} hw_ecspi_intreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_INTREG register
 */
#define HW_ECSPI_INTREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_INTREG(x)           (*(volatile hw_ecspi_intreg_t *) HW_ECSPI_INTREG_ADDR(x))
#define HW_ECSPI_INTREG_RD(x)        (HW_ECSPI_INTREG(x).U)
#define HW_ECSPI_INTREG_WR(x, v)     (HW_ECSPI_INTREG(x).U = (v))
#define HW_ECSPI_INTREG_SET(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) |  (v)))
#define HW_ECSPI_INTREG_CLR(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) & ~(v)))
#define HW_ECSPI_INTREG_TOG(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_INTREG bitfields
 */

/* --- Register HW_ECSPI_INTREG, field TEEN */

#define BP_ECSPI_INTREG_TEEN      0
#define BM_ECSPI_INTREG_TEEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TEEN(v)   ((((reg32_t) v) << 0) & BM_ECSPI_INTREG_TEEN)
#else
#define BF_ECSPI_INTREG_TEEN(v)   (((v) << 0) & BM_ECSPI_INTREG_TEEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_TEEN(v)   BF_CS1(ECSPI_INTREG, TEEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field THEN */

#define BP_ECSPI_INTREG_THEN      1
#define BM_ECSPI_INTREG_THEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_THEN(v)   ((((reg32_t) v) << 1) & BM_ECSPI_INTREG_THEN)
#else
#define BF_ECSPI_INTREG_THEN(v)   (((v) << 1) & BM_ECSPI_INTREG_THEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_THEN(v)   BF_CS1(ECSPI_INTREG, THEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field TFEN */

#define BP_ECSPI_INTREG_TFEN      2
#define BM_ECSPI_INTREG_TFEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TFEN(v)   ((((reg32_t) v) << 2) & BM_ECSPI_INTREG_TFEN)
#else
#define BF_ECSPI_INTREG_TFEN(v)   (((v) << 2) & BM_ECSPI_INTREG_TFEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_TFEN(v)   BF_CS1(ECSPI_INTREG, TFEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field RREN */

#define BP_ECSPI_INTREG_RREN      3
#define BM_ECSPI_INTREG_RREN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RREN(v)   ((((reg32_t) v) << 3) & BM_ECSPI_INTREG_RREN)
#else
#define BF_ECSPI_INTREG_RREN(v)   (((v) << 3) & BM_ECSPI_INTREG_RREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_RREN(v)   BF_CS1(ECSPI_INTREG, RREN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field RHEN */

#define BP_ECSPI_INTREG_RHEN      4
#define BM_ECSPI_INTREG_RHEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RHEN(v)   ((((reg32_t) v) << 4) & BM_ECSPI_INTREG_RHEN)
#else
#define BF_ECSPI_INTREG_RHEN(v)   (((v) << 4) & BM_ECSPI_INTREG_RHEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_RHEN(v)   BF_CS1(ECSPI_INTREG, RHEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field RFEN */

#define BP_ECSPI_INTREG_RFEN      5
#define BM_ECSPI_INTREG_RFEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RFEN(v)   ((((reg32_t) v) << 5) & BM_ECSPI_INTREG_RFEN)
#else
#define BF_ECSPI_INTREG_RFEN(v)   (((v) << 5) & BM_ECSPI_INTREG_RFEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_RFEN(v)   BF_CS1(ECSPI_INTREG, RFEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field ROEN */

#define BP_ECSPI_INTREG_ROEN      6
#define BM_ECSPI_INTREG_ROEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_ROEN(v)   ((((reg32_t) v) << 6) & BM_ECSPI_INTREG_ROEN)
#else
#define BF_ECSPI_INTREG_ROEN(v)   (((v) << 6) & BM_ECSPI_INTREG_ROEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_ROEN(v)   BF_CS1(ECSPI_INTREG, ROEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field TCEN */

#define BP_ECSPI_INTREG_TCEN      7
#define BM_ECSPI_INTREG_TCEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TCEN(v)   ((((reg32_t) v) << 7) & BM_ECSPI_INTREG_TCEN)
#else
#define BF_ECSPI_INTREG_TCEN(v)   (((v) << 7) & BM_ECSPI_INTREG_TCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_TCEN(v)   BF_CS1(ECSPI_INTREG, TCEN, v)
#endif

/*
 * HW_ECSPI_INTREG - Interrupt Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TEEN : 1;
        unsigned TDREN : 1;
        unsigned TFEN : 1;
        unsigned RREN : 1;
        unsigned RDREN : 1;
        unsigned RFEN : 1;
        unsigned ROEN : 1;
        unsigned TCEN : 1;
        unsigned RESERVED0 : 24;

    } B;
} hw_ecspi_intreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_INTREG register
 */
#define HW_ECSPI_INTREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_INTREG(x)           (*(volatile hw_ecspi_intreg_t *) HW_ECSPI_INTREG_ADDR(x))
#define HW_ECSPI_INTREG_RD(x)        (HW_ECSPI_INTREG(x).U)
#define HW_ECSPI_INTREG_WR(x, v)     (HW_ECSPI_INTREG(x).U = (v))
#define HW_ECSPI_INTREG_SET(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) |  (v)))
#define HW_ECSPI_INTREG_CLR(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) & ~(v)))
#define HW_ECSPI_INTREG_TOG(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_INTREG bitfields
 */

/* --- Register HW_ECSPI_INTREG, field TEEN */

#define BP_ECSPI_INTREG_TEEN      0
#define BM_ECSPI_INTREG_TEEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TEEN(v)   ((((reg32_t) v) << 0) & BM_ECSPI_INTREG_TEEN)
#else
#define BF_ECSPI_INTREG_TEEN(v)   (((v) << 0) & BM_ECSPI_INTREG_TEEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_TEEN(v)   BF_CS1(ECSPI_INTREG, TEEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field TDREN */

#define BP_ECSPI_INTREG_TDREN      1
#define BM_ECSPI_INTREG_TDREN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TDREN(v)   ((((reg32_t) v) << 1) & BM_ECSPI_INTREG_TDREN)
#else
#define BF_ECSPI_INTREG_TDREN(v)   (((v) << 1) & BM_ECSPI_INTREG_TDREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_TDREN(v)   BF_CS1(ECSPI_INTREG, TDREN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field TFEN */

#define BP_ECSPI_INTREG_TFEN      2
#define BM_ECSPI_INTREG_TFEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TFEN(v)   ((((reg32_t) v) << 2) & BM_ECSPI_INTREG_TFEN)
#else
#define BF_ECSPI_INTREG_TFEN(v)   (((v) << 2) & BM_ECSPI_INTREG_TFEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_TFEN(v)   BF_CS1(ECSPI_INTREG, TFEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field RREN */

#define BP_ECSPI_INTREG_RREN      3
#define BM_ECSPI_INTREG_RREN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RREN(v)   ((((reg32_t) v) << 3) & BM_ECSPI_INTREG_RREN)
#else
#define BF_ECSPI_INTREG_RREN(v)   (((v) << 3) & BM_ECSPI_INTREG_RREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_RREN(v)   BF_CS1(ECSPI_INTREG, RREN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field RDREN */

#define BP_ECSPI_INTREG_RDREN      4
#define BM_ECSPI_INTREG_RDREN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RDREN(v)   ((((reg32_t) v) << 4) & BM_ECSPI_INTREG_RDREN)
#else
#define BF_ECSPI_INTREG_RDREN(v)   (((v) << 4) & BM_ECSPI_INTREG_RDREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_RDREN(v)   BF_CS1(ECSPI_INTREG, RDREN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field RFEN */

#define BP_ECSPI_INTREG_RFEN      5
#define BM_ECSPI_INTREG_RFEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RFEN(v)   ((((reg32_t) v) << 5) & BM_ECSPI_INTREG_RFEN)
#else
#define BF_ECSPI_INTREG_RFEN(v)   (((v) << 5) & BM_ECSPI_INTREG_RFEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_RFEN(v)   BF_CS1(ECSPI_INTREG, RFEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field ROEN */

#define BP_ECSPI_INTREG_ROEN      6
#define BM_ECSPI_INTREG_ROEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_ROEN(v)   ((((reg32_t) v) << 6) & BM_ECSPI_INTREG_ROEN)
#else
#define BF_ECSPI_INTREG_ROEN(v)   (((v) << 6) & BM_ECSPI_INTREG_ROEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_ROEN(v)   BF_CS1(ECSPI_INTREG, ROEN, v)
#endif

/* --- Register HW_ECSPI_INTREG, field TCEN */

#define BP_ECSPI_INTREG_TCEN      7
#define BM_ECSPI_INTREG_TCEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TCEN(v)   ((((reg32_t) v) << 7) & BM_ECSPI_INTREG_TCEN)
#else
#define BF_ECSPI_INTREG_TCEN(v)   (((v) << 7) & BM_ECSPI_INTREG_TCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_INTREG_TCEN(v)   BF_CS1(ECSPI_INTREG, TCEN, v)
#endif

/*
 * HW_ECSPI_DMAREG - DMA Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TEDEN : 1;
        unsigned THDEN : 1;
        unsigned RESERVED0 : 2;
        unsigned RHDEN : 1;
        unsigned RFDEN : 1;
        unsigned RESERVED1 : 26;

    } B;
} hw_ecspi_dmareg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_DMAREG register
 */
#define HW_ECSPI_DMAREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_DMAREG(x)           (*(volatile hw_ecspi_dmareg_t *) HW_ECSPI_DMAREG_ADDR(x))
#define HW_ECSPI_DMAREG_RD(x)        (HW_ECSPI_DMAREG(x).U)
#define HW_ECSPI_DMAREG_WR(x, v)     (HW_ECSPI_DMAREG(x).U = (v))
#define HW_ECSPI_DMAREG_SET(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) |  (v)))
#define HW_ECSPI_DMAREG_CLR(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) & ~(v)))
#define HW_ECSPI_DMAREG_TOG(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_DMAREG bitfields
 */

/* --- Register HW_ECSPI_DMAREG, field TEDEN */

#define BP_ECSPI_DMAREG_TEDEN      0
#define BM_ECSPI_DMAREG_TEDEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_TEDEN(v)   ((((reg32_t) v) << 0) & BM_ECSPI_DMAREG_TEDEN)
#else
#define BF_ECSPI_DMAREG_TEDEN(v)   (((v) << 0) & BM_ECSPI_DMAREG_TEDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_TEDEN(v)   BF_CS1(ECSPI_DMAREG, TEDEN, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field THDEN */

#define BP_ECSPI_DMAREG_THDEN      1
#define BM_ECSPI_DMAREG_THDEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_THDEN(v)   ((((reg32_t) v) << 1) & BM_ECSPI_DMAREG_THDEN)
#else
#define BF_ECSPI_DMAREG_THDEN(v)   (((v) << 1) & BM_ECSPI_DMAREG_THDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_THDEN(v)   BF_CS1(ECSPI_DMAREG, THDEN, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field RHDEN */

#define BP_ECSPI_DMAREG_RHDEN      4
#define BM_ECSPI_DMAREG_RHDEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RHDEN(v)   ((((reg32_t) v) << 4) & BM_ECSPI_DMAREG_RHDEN)
#else
#define BF_ECSPI_DMAREG_RHDEN(v)   (((v) << 4) & BM_ECSPI_DMAREG_RHDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_RHDEN(v)   BF_CS1(ECSPI_DMAREG, RHDEN, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field RFDEN */

#define BP_ECSPI_DMAREG_RFDEN      5
#define BM_ECSPI_DMAREG_RFDEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RFDEN(v)   ((((reg32_t) v) << 5) & BM_ECSPI_DMAREG_RFDEN)
#else
#define BF_ECSPI_DMAREG_RFDEN(v)   (((v) << 5) & BM_ECSPI_DMAREG_RFDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_RFDEN(v)   BF_CS1(ECSPI_DMAREG, RFDEN, v)
#endif

/*
 * HW_ECSPI_DMAREG - DMA Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TX : 6;
        unsigned RESERVED0 : 1;
        unsigned TEDEN : 1;
        unsigned RESERVED1 : 8;
        unsigned RX : 6;
        unsigned RESERVED2 : 1;
        unsigned RXDEN : 1;
        unsigned RX : 6;
        unsigned RESERVED3 : 1;
        unsigned RXTDEN : 1;

    } B;
} hw_ecspi_dmareg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_DMAREG register
 */
#define HW_ECSPI_DMAREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_DMAREG(x)           (*(volatile hw_ecspi_dmareg_t *) HW_ECSPI_DMAREG_ADDR(x))
#define HW_ECSPI_DMAREG_RD(x)        (HW_ECSPI_DMAREG(x).U)
#define HW_ECSPI_DMAREG_WR(x, v)     (HW_ECSPI_DMAREG(x).U = (v))
#define HW_ECSPI_DMAREG_SET(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) |  (v)))
#define HW_ECSPI_DMAREG_CLR(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) & ~(v)))
#define HW_ECSPI_DMAREG_TOG(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_DMAREG bitfields
 */

/* --- Register HW_ECSPI_DMAREG, field TX */

#define BP_ECSPI_DMAREG_TX      0
#define BM_ECSPI_DMAREG_TX      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_TX(v)   ((((reg32_t) v) << 0) & BM_ECSPI_DMAREG_TX)
#else
#define BF_ECSPI_DMAREG_TX(v)   (((v) << 0) & BM_ECSPI_DMAREG_TX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_TX(v)   BF_CS1(ECSPI_DMAREG, TX, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field TEDEN */

#define BP_ECSPI_DMAREG_TEDEN      7
#define BM_ECSPI_DMAREG_TEDEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_TEDEN(v)   ((((reg32_t) v) << 7) & BM_ECSPI_DMAREG_TEDEN)
#else
#define BF_ECSPI_DMAREG_TEDEN(v)   (((v) << 7) & BM_ECSPI_DMAREG_TEDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_TEDEN(v)   BF_CS1(ECSPI_DMAREG, TEDEN, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field RX */

#define BP_ECSPI_DMAREG_RX      16
#define BM_ECSPI_DMAREG_RX      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RX(v)   ((((reg32_t) v) << 16) & BM_ECSPI_DMAREG_RX)
#else
#define BF_ECSPI_DMAREG_RX(v)   (((v) << 16) & BM_ECSPI_DMAREG_RX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_RX(v)   BF_CS1(ECSPI_DMAREG, RX, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field RXDEN */

#define BP_ECSPI_DMAREG_RXDEN      23
#define BM_ECSPI_DMAREG_RXDEN      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RXDEN(v)   ((((reg32_t) v) << 23) & BM_ECSPI_DMAREG_RXDEN)
#else
#define BF_ECSPI_DMAREG_RXDEN(v)   (((v) << 23) & BM_ECSPI_DMAREG_RXDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_RXDEN(v)   BF_CS1(ECSPI_DMAREG, RXDEN, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field RX */

#define BP_ECSPI_DMAREG_RX      24
#define BM_ECSPI_DMAREG_RX      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RX(v)   ((((reg32_t) v) << 24) & BM_ECSPI_DMAREG_RX)
#else
#define BF_ECSPI_DMAREG_RX(v)   (((v) << 24) & BM_ECSPI_DMAREG_RX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_RX(v)   BF_CS1(ECSPI_DMAREG, RX, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field RXTDEN */

#define BP_ECSPI_DMAREG_RXTDEN      31
#define BM_ECSPI_DMAREG_RXTDEN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RXTDEN(v)   ((((reg32_t) v) << 31) & BM_ECSPI_DMAREG_RXTDEN)
#else
#define BF_ECSPI_DMAREG_RXTDEN(v)   (((v) << 31) & BM_ECSPI_DMAREG_RXTDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_DMAREG_RXTDEN(v)   BF_CS1(ECSPI_DMAREG, RXTDEN, v)
#endif

/*
 * HW_ECSPI_STATREG - Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TE : 1;
        unsigned TH : 1;
        unsigned TF : 1;
        unsigned RR : 1;
        unsigned RH : 1;
        unsigned RF : 1;
        unsigned RO : 1;
        unsigned TC : 1;
        unsigned RESERVED0 : 24;

    } B;
} hw_ecspi_statreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_STATREG register
 */
#define HW_ECSPI_STATREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_STATREG(x)           (*(volatile hw_ecspi_statreg_t *) HW_ECSPI_STATREG_ADDR(x))
#define HW_ECSPI_STATREG_RD(x)        (HW_ECSPI_STATREG(x).U)
#define HW_ECSPI_STATREG_WR(x, v)     (HW_ECSPI_STATREG(x).U = (v))
#define HW_ECSPI_STATREG_SET(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) |  (v)))
#define HW_ECSPI_STATREG_CLR(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) & ~(v)))
#define HW_ECSPI_STATREG_TOG(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_STATREG bitfields
 */

/* --- Register HW_ECSPI_STATREG, field TE */

#define BP_ECSPI_STATREG_TE      0
#define BM_ECSPI_STATREG_TE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_TE(v)   ((((reg32_t) v) << 0) & BM_ECSPI_STATREG_TE)
#else
#define BF_ECSPI_STATREG_TE(v)   (((v) << 0) & BM_ECSPI_STATREG_TE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_TE(v)   BF_CS1(ECSPI_STATREG, TE, v)
#endif

/* --- Register HW_ECSPI_STATREG, field TH */

#define BP_ECSPI_STATREG_TH      1
#define BM_ECSPI_STATREG_TH      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_TH(v)   ((((reg32_t) v) << 1) & BM_ECSPI_STATREG_TH)
#else
#define BF_ECSPI_STATREG_TH(v)   (((v) << 1) & BM_ECSPI_STATREG_TH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_TH(v)   BF_CS1(ECSPI_STATREG, TH, v)
#endif

/* --- Register HW_ECSPI_STATREG, field TF */

#define BP_ECSPI_STATREG_TF      2
#define BM_ECSPI_STATREG_TF      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_TF(v)   ((((reg32_t) v) << 2) & BM_ECSPI_STATREG_TF)
#else
#define BF_ECSPI_STATREG_TF(v)   (((v) << 2) & BM_ECSPI_STATREG_TF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_TF(v)   BF_CS1(ECSPI_STATREG, TF, v)
#endif

/* --- Register HW_ECSPI_STATREG, field RR */

#define BP_ECSPI_STATREG_RR      3
#define BM_ECSPI_STATREG_RR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_RR(v)   ((((reg32_t) v) << 3) & BM_ECSPI_STATREG_RR)
#else
#define BF_ECSPI_STATREG_RR(v)   (((v) << 3) & BM_ECSPI_STATREG_RR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_RR(v)   BF_CS1(ECSPI_STATREG, RR, v)
#endif

/* --- Register HW_ECSPI_STATREG, field RH */

#define BP_ECSPI_STATREG_RH      4
#define BM_ECSPI_STATREG_RH      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_RH(v)   ((((reg32_t) v) << 4) & BM_ECSPI_STATREG_RH)
#else
#define BF_ECSPI_STATREG_RH(v)   (((v) << 4) & BM_ECSPI_STATREG_RH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_RH(v)   BF_CS1(ECSPI_STATREG, RH, v)
#endif

/* --- Register HW_ECSPI_STATREG, field RF */

#define BP_ECSPI_STATREG_RF      5
#define BM_ECSPI_STATREG_RF      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_RF(v)   ((((reg32_t) v) << 5) & BM_ECSPI_STATREG_RF)
#else
#define BF_ECSPI_STATREG_RF(v)   (((v) << 5) & BM_ECSPI_STATREG_RF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_RF(v)   BF_CS1(ECSPI_STATREG, RF, v)
#endif

/* --- Register HW_ECSPI_STATREG, field RO */

#define BP_ECSPI_STATREG_RO      6
#define BM_ECSPI_STATREG_RO      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_RO(v)   ((((reg32_t) v) << 6) & BM_ECSPI_STATREG_RO)
#else
#define BF_ECSPI_STATREG_RO(v)   (((v) << 6) & BM_ECSPI_STATREG_RO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_RO(v)   BF_CS1(ECSPI_STATREG, RO, v)
#endif

/* --- Register HW_ECSPI_STATREG, field TC */

#define BP_ECSPI_STATREG_TC      7
#define BM_ECSPI_STATREG_TC      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_TC(v)   ((((reg32_t) v) << 7) & BM_ECSPI_STATREG_TC)
#else
#define BF_ECSPI_STATREG_TC(v)   (((v) << 7) & BM_ECSPI_STATREG_TC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_TC(v)   BF_CS1(ECSPI_STATREG, TC, v)
#endif

/*
 * HW_ECSPI_STATREG - Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TE : 1;
        unsigned TDR : 1;
        unsigned TF : 1;
        unsigned RR : 1;
        unsigned RDR : 1;
        unsigned RF : 1;
        unsigned RO : 1;
        unsigned TC : 1;
        unsigned RESERVED0 : 24;

    } B;
} hw_ecspi_statreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_STATREG register
 */
#define HW_ECSPI_STATREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_STATREG(x)           (*(volatile hw_ecspi_statreg_t *) HW_ECSPI_STATREG_ADDR(x))
#define HW_ECSPI_STATREG_RD(x)        (HW_ECSPI_STATREG(x).U)
#define HW_ECSPI_STATREG_WR(x, v)     (HW_ECSPI_STATREG(x).U = (v))
#define HW_ECSPI_STATREG_SET(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) |  (v)))
#define HW_ECSPI_STATREG_CLR(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) & ~(v)))
#define HW_ECSPI_STATREG_TOG(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_STATREG bitfields
 */

/* --- Register HW_ECSPI_STATREG, field TE */

#define BP_ECSPI_STATREG_TE      0
#define BM_ECSPI_STATREG_TE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_TE(v)   ((((reg32_t) v) << 0) & BM_ECSPI_STATREG_TE)
#else
#define BF_ECSPI_STATREG_TE(v)   (((v) << 0) & BM_ECSPI_STATREG_TE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_TE(v)   BF_CS1(ECSPI_STATREG, TE, v)
#endif

/* --- Register HW_ECSPI_STATREG, field TDR */

#define BP_ECSPI_STATREG_TDR      1
#define BM_ECSPI_STATREG_TDR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_TDR(v)   ((((reg32_t) v) << 1) & BM_ECSPI_STATREG_TDR)
#else
#define BF_ECSPI_STATREG_TDR(v)   (((v) << 1) & BM_ECSPI_STATREG_TDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_TDR(v)   BF_CS1(ECSPI_STATREG, TDR, v)
#endif

/* --- Register HW_ECSPI_STATREG, field TF */

#define BP_ECSPI_STATREG_TF      2
#define BM_ECSPI_STATREG_TF      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_TF(v)   ((((reg32_t) v) << 2) & BM_ECSPI_STATREG_TF)
#else
#define BF_ECSPI_STATREG_TF(v)   (((v) << 2) & BM_ECSPI_STATREG_TF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_TF(v)   BF_CS1(ECSPI_STATREG, TF, v)
#endif

/* --- Register HW_ECSPI_STATREG, field RR */

#define BP_ECSPI_STATREG_RR      3
#define BM_ECSPI_STATREG_RR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_RR(v)   ((((reg32_t) v) << 3) & BM_ECSPI_STATREG_RR)
#else
#define BF_ECSPI_STATREG_RR(v)   (((v) << 3) & BM_ECSPI_STATREG_RR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_RR(v)   BF_CS1(ECSPI_STATREG, RR, v)
#endif

/* --- Register HW_ECSPI_STATREG, field RDR */

#define BP_ECSPI_STATREG_RDR      4
#define BM_ECSPI_STATREG_RDR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_RDR(v)   ((((reg32_t) v) << 4) & BM_ECSPI_STATREG_RDR)
#else
#define BF_ECSPI_STATREG_RDR(v)   (((v) << 4) & BM_ECSPI_STATREG_RDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_RDR(v)   BF_CS1(ECSPI_STATREG, RDR, v)
#endif

/* --- Register HW_ECSPI_STATREG, field RF */

#define BP_ECSPI_STATREG_RF      5
#define BM_ECSPI_STATREG_RF      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_RF(v)   ((((reg32_t) v) << 5) & BM_ECSPI_STATREG_RF)
#else
#define BF_ECSPI_STATREG_RF(v)   (((v) << 5) & BM_ECSPI_STATREG_RF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_RF(v)   BF_CS1(ECSPI_STATREG, RF, v)
#endif

/* --- Register HW_ECSPI_STATREG, field RO */

#define BP_ECSPI_STATREG_RO      6
#define BM_ECSPI_STATREG_RO      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_RO(v)   ((((reg32_t) v) << 6) & BM_ECSPI_STATREG_RO)
#else
#define BF_ECSPI_STATREG_RO(v)   (((v) << 6) & BM_ECSPI_STATREG_RO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_RO(v)   BF_CS1(ECSPI_STATREG, RO, v)
#endif

/* --- Register HW_ECSPI_STATREG, field TC */

#define BP_ECSPI_STATREG_TC      7
#define BM_ECSPI_STATREG_TC      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_STATREG_TC(v)   ((((reg32_t) v) << 7) & BM_ECSPI_STATREG_TC)
#else
#define BF_ECSPI_STATREG_TC(v)   (((v) << 7) & BM_ECSPI_STATREG_TC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_STATREG_TC(v)   BF_CS1(ECSPI_STATREG, TC, v)
#endif

/*
 * HW_ECSPI_PERIODREG - Sample Period Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SAMPLE : 15;
        unsigned CSRC : 1;
        unsigned RESERVED0 : 16;

    } B;
} hw_ecspi_periodreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_PERIODREG register
 */
#define HW_ECSPI_PERIODREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_PERIODREG(x)           (*(volatile hw_ecspi_periodreg_t *) HW_ECSPI_PERIODREG_ADDR(x))
#define HW_ECSPI_PERIODREG_RD(x)        (HW_ECSPI_PERIODREG(x).U)
#define HW_ECSPI_PERIODREG_WR(x, v)     (HW_ECSPI_PERIODREG(x).U = (v))
#define HW_ECSPI_PERIODREG_SET(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) |  (v)))
#define HW_ECSPI_PERIODREG_CLR(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) & ~(v)))
#define HW_ECSPI_PERIODREG_TOG(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_PERIODREG bitfields
 */

/* --- Register HW_ECSPI_PERIODREG, field SAMPLE */

#define BP_ECSPI_PERIODREG_SAMPLE      0
#define BM_ECSPI_PERIODREG_SAMPLE      0x00007fff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_PERIODREG_SAMPLE(v)   ((((reg32_t) v) << 0) & BM_ECSPI_PERIODREG_SAMPLE)
#else
#define BF_ECSPI_PERIODREG_SAMPLE(v)   (((v) << 0) & BM_ECSPI_PERIODREG_SAMPLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_PERIODREG_SAMPLE(v)   BF_CS1(ECSPI_PERIODREG, SAMPLE, v)
#endif

/* --- Register HW_ECSPI_PERIODREG, field CSRC */

#define BP_ECSPI_PERIODREG_CSRC      15
#define BM_ECSPI_PERIODREG_CSRC      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_PERIODREG_CSRC(v)   ((((reg32_t) v) << 15) & BM_ECSPI_PERIODREG_CSRC)
#else
#define BF_ECSPI_PERIODREG_CSRC(v)   (((v) << 15) & BM_ECSPI_PERIODREG_CSRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_PERIODREG_CSRC(v)   BF_CS1(ECSPI_PERIODREG, CSRC, v)
#endif

/*
 * HW_ECSPI_PERIODREG - Sample Period Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SAMPLE : 15;
        unsigned CSRC : 1;
        unsigned CSD : 6;
        unsigned RESERVED0 : 10;

    } B;
} hw_ecspi_periodreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_PERIODREG register
 */
#define HW_ECSPI_PERIODREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_PERIODREG(x)           (*(volatile hw_ecspi_periodreg_t *) HW_ECSPI_PERIODREG_ADDR(x))
#define HW_ECSPI_PERIODREG_RD(x)        (HW_ECSPI_PERIODREG(x).U)
#define HW_ECSPI_PERIODREG_WR(x, v)     (HW_ECSPI_PERIODREG(x).U = (v))
#define HW_ECSPI_PERIODREG_SET(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) |  (v)))
#define HW_ECSPI_PERIODREG_CLR(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) & ~(v)))
#define HW_ECSPI_PERIODREG_TOG(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_PERIODREG bitfields
 */

/* --- Register HW_ECSPI_PERIODREG, field SAMPLE */

#define BP_ECSPI_PERIODREG_SAMPLE      0
#define BM_ECSPI_PERIODREG_SAMPLE      0x00007fff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_PERIODREG_SAMPLE(v)   ((((reg32_t) v) << 0) & BM_ECSPI_PERIODREG_SAMPLE)
#else
#define BF_ECSPI_PERIODREG_SAMPLE(v)   (((v) << 0) & BM_ECSPI_PERIODREG_SAMPLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_PERIODREG_SAMPLE(v)   BF_CS1(ECSPI_PERIODREG, SAMPLE, v)
#endif

/* --- Register HW_ECSPI_PERIODREG, field CSRC */

#define BP_ECSPI_PERIODREG_CSRC      15
#define BM_ECSPI_PERIODREG_CSRC      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_PERIODREG_CSRC(v)   ((((reg32_t) v) << 15) & BM_ECSPI_PERIODREG_CSRC)
#else
#define BF_ECSPI_PERIODREG_CSRC(v)   (((v) << 15) & BM_ECSPI_PERIODREG_CSRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_PERIODREG_CSRC(v)   BF_CS1(ECSPI_PERIODREG, CSRC, v)
#endif

/* --- Register HW_ECSPI_PERIODREG, field CSD */

#define BP_ECSPI_PERIODREG_CSD      16
#define BM_ECSPI_PERIODREG_CSD      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_PERIODREG_CSD(v)   ((((reg32_t) v) << 16) & BM_ECSPI_PERIODREG_CSD)
#else
#define BF_ECSPI_PERIODREG_CSD(v)   (((v) << 16) & BM_ECSPI_PERIODREG_CSD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_PERIODREG_CSD(v)   BF_CS1(ECSPI_PERIODREG, CSD, v)
#endif

/*
 * HW_ECSPI_TESTREG - Test Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TXCNT : 4;
        unsigned RXCNT : 4;
        unsigned RESERVED0 : 6;
        unsigned SMSTATUS : 4;
        unsigned RESERVED1 : 2;
        unsigned LBC : 1;
        unsigned SWAP : 1;
        unsigned RESERVED2 : 16;

    } B;
} hw_ecspi_testreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_TESTREG register
 */
#define HW_ECSPI_TESTREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_TESTREG(x)           (*(volatile hw_ecspi_testreg_t *) HW_ECSPI_TESTREG_ADDR(x))
#define HW_ECSPI_TESTREG_RD(x)        (HW_ECSPI_TESTREG(x).U)
#define HW_ECSPI_TESTREG_WR(x, v)     (HW_ECSPI_TESTREG(x).U = (v))
#define HW_ECSPI_TESTREG_SET(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) |  (v)))
#define HW_ECSPI_TESTREG_CLR(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) & ~(v)))
#define HW_ECSPI_TESTREG_TOG(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_TESTREG bitfields
 */

/* --- Register HW_ECSPI_TESTREG, field TXCNT */

#define BP_ECSPI_TESTREG_TXCNT      0
#define BM_ECSPI_TESTREG_TXCNT      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_TXCNT(v)   ((((reg32_t) v) << 0) & BM_ECSPI_TESTREG_TXCNT)
#else
#define BF_ECSPI_TESTREG_TXCNT(v)   (((v) << 0) & BM_ECSPI_TESTREG_TXCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_TXCNT(v)   BF_CS1(ECSPI_TESTREG, TXCNT, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field RXCNT */

#define BP_ECSPI_TESTREG_RXCNT      4
#define BM_ECSPI_TESTREG_RXCNT      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_RXCNT(v)   ((((reg32_t) v) << 4) & BM_ECSPI_TESTREG_RXCNT)
#else
#define BF_ECSPI_TESTREG_RXCNT(v)   (((v) << 4) & BM_ECSPI_TESTREG_RXCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_RXCNT(v)   BF_CS1(ECSPI_TESTREG, RXCNT, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field SMSTATUS */

#define BP_ECSPI_TESTREG_SMSTATUS      8
#define BM_ECSPI_TESTREG_SMSTATUS      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_SMSTATUS(v)   ((((reg32_t) v) << 8) & BM_ECSPI_TESTREG_SMSTATUS)
#else
#define BF_ECSPI_TESTREG_SMSTATUS(v)   (((v) << 8) & BM_ECSPI_TESTREG_SMSTATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_SMSTATUS(v)   BF_CS1(ECSPI_TESTREG, SMSTATUS, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field LBC */

#define BP_ECSPI_TESTREG_LBC      14
#define BM_ECSPI_TESTREG_LBC      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_LBC(v)   ((((reg32_t) v) << 14) & BM_ECSPI_TESTREG_LBC)
#else
#define BF_ECSPI_TESTREG_LBC(v)   (((v) << 14) & BM_ECSPI_TESTREG_LBC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_LBC(v)   BF_CS1(ECSPI_TESTREG, LBC, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field SWAP */

#define BP_ECSPI_TESTREG_SWAP      15
#define BM_ECSPI_TESTREG_SWAP      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_SWAP(v)   ((((reg32_t) v) << 15) & BM_ECSPI_TESTREG_SWAP)
#else
#define BF_ECSPI_TESTREG_SWAP(v)   (((v) << 15) & BM_ECSPI_TESTREG_SWAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_SWAP(v)   BF_CS1(ECSPI_TESTREG, SWAP, v)
#endif

/*
 * HW_ECSPI_TESTREG - Test Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TXCNT : 7;
        unsigned RESERVED0 : 1;
        unsigned RXCNT : 7;
        unsigned RESERVED1 : 13;
        unsigned RESERVED2 : 3;
        unsigned DLD : 2;
        unsigned RESERVED3 : 1;
        unsigned LBC : 1;

    } B;
} hw_ecspi_testreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_TESTREG register
 */
#define HW_ECSPI_TESTREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_TESTREG(x)           (*(volatile hw_ecspi_testreg_t *) HW_ECSPI_TESTREG_ADDR(x))
#define HW_ECSPI_TESTREG_RD(x)        (HW_ECSPI_TESTREG(x).U)
#define HW_ECSPI_TESTREG_WR(x, v)     (HW_ECSPI_TESTREG(x).U = (v))
#define HW_ECSPI_TESTREG_SET(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) |  (v)))
#define HW_ECSPI_TESTREG_CLR(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) & ~(v)))
#define HW_ECSPI_TESTREG_TOG(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_TESTREG bitfields
 */

/* --- Register HW_ECSPI_TESTREG, field TXCNT */

#define BP_ECSPI_TESTREG_TXCNT      0
#define BM_ECSPI_TESTREG_TXCNT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_TXCNT(v)   ((((reg32_t) v) << 0) & BM_ECSPI_TESTREG_TXCNT)
#else
#define BF_ECSPI_TESTREG_TXCNT(v)   (((v) << 0) & BM_ECSPI_TESTREG_TXCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_TXCNT(v)   BF_CS1(ECSPI_TESTREG, TXCNT, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field RXCNT */

#define BP_ECSPI_TESTREG_RXCNT      8
#define BM_ECSPI_TESTREG_RXCNT      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_RXCNT(v)   ((((reg32_t) v) << 8) & BM_ECSPI_TESTREG_RXCNT)
#else
#define BF_ECSPI_TESTREG_RXCNT(v)   (((v) << 8) & BM_ECSPI_TESTREG_RXCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_RXCNT(v)   BF_CS1(ECSPI_TESTREG, RXCNT, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field DLD */

#define BP_ECSPI_TESTREG_DLD      28
#define BM_ECSPI_TESTREG_DLD      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_DLD(v)   ((((reg32_t) v) << 28) & BM_ECSPI_TESTREG_DLD)
#else
#define BF_ECSPI_TESTREG_DLD(v)   (((v) << 28) & BM_ECSPI_TESTREG_DLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_DLD(v)   BF_CS1(ECSPI_TESTREG, DLD, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field LBC */

#define BP_ECSPI_TESTREG_LBC      31
#define BM_ECSPI_TESTREG_LBC      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_LBC(v)   ((((reg32_t) v) << 31) & BM_ECSPI_TESTREG_LBC)
#else
#define BF_ECSPI_TESTREG_LBC(v)   (((v) << 31) & BM_ECSPI_TESTREG_LBC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TESTREG_LBC(v)   BF_CS1(ECSPI_TESTREG, LBC, v)
#endif

/*
 * HW_ECSPI_MSGDATA - Message Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ECSPI_MSGDATA : 32;

    } B;
} hw_ecspi_msgdata_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_MSGDATA register
 */
#define HW_ECSPI_MSGDATA_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_MSGDATA(x)           (*(volatile hw_ecspi_msgdata_t *) HW_ECSPI_MSGDATA_ADDR(x))
#define HW_ECSPI_MSGDATA_RD(x)        (HW_ECSPI_MSGDATA(x).U)
#define HW_ECSPI_MSGDATA_WR(x, v)     (HW_ECSPI_MSGDATA(x).U = (v))
#define HW_ECSPI_MSGDATA_SET(x, v)    (HW_ECSPI_MSGDATA_WR(x, HW_ECSPI_MSGDATA_RD(x) |  (v)))
#define HW_ECSPI_MSGDATA_CLR(x, v)    (HW_ECSPI_MSGDATA_WR(x, HW_ECSPI_MSGDATA_RD(x) & ~(v)))
#define HW_ECSPI_MSGDATA_TOG(x, v)    (HW_ECSPI_MSGDATA_WR(x, HW_ECSPI_MSGDATA_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_MSGDATA bitfields
 */

/* --- Register HW_ECSPI_MSGDATA, field ECSPI_MSGDATA */

#define BP_ECSPI_MSGDATA_ECSPI_MSGDATA      0
#define BM_ECSPI_MSGDATA_ECSPI_MSGDATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_MSGDATA_ECSPI_MSGDATA(v)   ((((reg32_t) v) << 0) & BM_ECSPI_MSGDATA_ECSPI_MSGDATA)
#else
#define BF_ECSPI_MSGDATA_ECSPI_MSGDATA(v)   (((v) << 0) & BM_ECSPI_MSGDATA_ECSPI_MSGDATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_MSGDATA_ECSPI_MSGDATA(v)   BF_CS1(ECSPI_MSGDATA, ECSPI_MSGDATA, v)
#endif


#endif // _ECSPI_H

