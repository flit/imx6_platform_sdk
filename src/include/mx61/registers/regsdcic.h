/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _DCIC_H
#define _DCIC_H

#include "regs.h"

#ifndef REGS_DCIC_BASE
#define REGS_DCIC0_BASE (REGS_BASE + 0x020e4000)
#define REGS_DCIC1_BASE (REGS_BASE + 0x020e8000)
#define REGS_DCIC_BASE(x) ( x == 0 ? REGS_DCIC0_BASE : x == 1 ? REGS_DCIC1_BASE : 0xffff0000)

#endif


/*
 * HW_DCIC_DCICC - DCIC Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 24;
        unsigned CLK_POL : 1;
        unsigned VSYNC_POL : 1;
        unsigned HSYNC_POL : 1;
        unsigned DE_POL : 1;
        unsigned RESERVED1 : 3;
        unsigned IC_EN : 1;

    } B;
} hw_dcic_dcicc_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICC register
 */
#define HW_DCIC_DCICC_ADDR(x)      (REGS_DCIC_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICC(x)           (*(volatile hw_dcic_dcicc_t *) HW_DCIC_DCICC_ADDR(x))
#define HW_DCIC_DCICC_RD(x)        (HW_DCIC_DCICC(x).U)
#define HW_DCIC_DCICC_WR(x, v)     (HW_DCIC_DCICC(x).U = (v))
#define HW_DCIC_DCICC_SET(x, v)    (HW_DCIC_DCICC_WR(x, HW_DCIC_DCICC_RD(x) |  (v)))
#define HW_DCIC_DCICC_CLR(x, v)    (HW_DCIC_DCICC_WR(x, HW_DCIC_DCICC_RD(x) & ~(v)))
#define HW_DCIC_DCICC_TOG(x, v)    (HW_DCIC_DCICC_WR(x, HW_DCIC_DCICC_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual DCIC_DCICC bitfields
 */

/* --- Register HW_DCIC_DCICC, field CLK_POL */

#define BP_DCIC_DCICC_CLK_POL      7
#define BM_DCIC_DCICC_CLK_POL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_CLK_POL(v)   ((((reg32_t) v) << 7) & BM_DCIC_DCICC_CLK_POL)
#else
#define BF_DCIC_DCICC_CLK_POL(v)   (((v) << 7) & BM_DCIC_DCICC_CLK_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICC_CLK_POL(v)   BF_CS1(DCIC_DCICC, CLK_POL, v)
#endif

/* --- Register HW_DCIC_DCICC, field VSYNC_POL */

#define BP_DCIC_DCICC_VSYNC_POL      6
#define BM_DCIC_DCICC_VSYNC_POL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_VSYNC_POL(v)   ((((reg32_t) v) << 6) & BM_DCIC_DCICC_VSYNC_POL)
#else
#define BF_DCIC_DCICC_VSYNC_POL(v)   (((v) << 6) & BM_DCIC_DCICC_VSYNC_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICC_VSYNC_POL(v)   BF_CS1(DCIC_DCICC, VSYNC_POL, v)
#endif

/* --- Register HW_DCIC_DCICC, field HSYNC_POL */

#define BP_DCIC_DCICC_HSYNC_POL      5
#define BM_DCIC_DCICC_HSYNC_POL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_HSYNC_POL(v)   ((((reg32_t) v) << 5) & BM_DCIC_DCICC_HSYNC_POL)
#else
#define BF_DCIC_DCICC_HSYNC_POL(v)   (((v) << 5) & BM_DCIC_DCICC_HSYNC_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICC_HSYNC_POL(v)   BF_CS1(DCIC_DCICC, HSYNC_POL, v)
#endif

/* --- Register HW_DCIC_DCICC, field DE_POL */

#define BP_DCIC_DCICC_DE_POL      4
#define BM_DCIC_DCICC_DE_POL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_DE_POL(v)   ((((reg32_t) v) << 4) & BM_DCIC_DCICC_DE_POL)
#else
#define BF_DCIC_DCICC_DE_POL(v)   (((v) << 4) & BM_DCIC_DCICC_DE_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICC_DE_POL(v)   BF_CS1(DCIC_DCICC, DE_POL, v)
#endif

/* --- Register HW_DCIC_DCICC, field IC_EN */

#define BP_DCIC_DCICC_IC_EN      0
#define BM_DCIC_DCICC_IC_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_IC_EN(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICC_IC_EN)
#else
#define BF_DCIC_DCICC_IC_EN(v)   (((v) << 0) & BM_DCIC_DCICC_IC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICC_IC_EN(v)   BF_CS1(DCIC_DCICC, IC_EN, v)
#endif

/*
 * HW_DCIC_DCICIC - DCIC Interrupt Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 15;
        unsigned EXT_SIG_EN : 1;
        unsigned RESERVED1 : 12;
        unsigned FREEZE_MASK : 1;
        unsigned RESERVED2 : 1;
        unsigned FI_MASK : 1;
        unsigned EI_MASK : 1;

    } B;
} hw_dcic_dcicic_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICIC register
 */
#define HW_DCIC_DCICIC_ADDR(x)      (REGS_DCIC_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICIC(x)           (*(volatile hw_dcic_dcicic_t *) HW_DCIC_DCICIC_ADDR(x))
#define HW_DCIC_DCICIC_RD(x)        (HW_DCIC_DCICIC(x).U)
#define HW_DCIC_DCICIC_WR(x, v)     (HW_DCIC_DCICIC(x).U = (v))
#define HW_DCIC_DCICIC_SET(x, v)    (HW_DCIC_DCICIC_WR(x, HW_DCIC_DCICIC_RD(x) |  (v)))
#define HW_DCIC_DCICIC_CLR(x, v)    (HW_DCIC_DCICIC_WR(x, HW_DCIC_DCICIC_RD(x) & ~(v)))
#define HW_DCIC_DCICIC_TOG(x, v)    (HW_DCIC_DCICIC_WR(x, HW_DCIC_DCICIC_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual DCIC_DCICIC bitfields
 */

/* --- Register HW_DCIC_DCICIC, field EXT_SIG_EN */

#define BP_DCIC_DCICIC_EXT_SIG_EN      16
#define BM_DCIC_DCICIC_EXT_SIG_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICIC_EXT_SIG_EN(v)   ((((reg32_t) v) << 16) & BM_DCIC_DCICIC_EXT_SIG_EN)
#else
#define BF_DCIC_DCICIC_EXT_SIG_EN(v)   (((v) << 16) & BM_DCIC_DCICIC_EXT_SIG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICIC_EXT_SIG_EN(v)   BF_CS1(DCIC_DCICIC, EXT_SIG_EN, v)
#endif

/* --- Register HW_DCIC_DCICIC, field FREEZE_MASK */

#define BP_DCIC_DCICIC_FREEZE_MASK      3
#define BM_DCIC_DCICIC_FREEZE_MASK      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICIC_FREEZE_MASK(v)   ((((reg32_t) v) << 3) & BM_DCIC_DCICIC_FREEZE_MASK)
#else
#define BF_DCIC_DCICIC_FREEZE_MASK(v)   (((v) << 3) & BM_DCIC_DCICIC_FREEZE_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICIC_FREEZE_MASK(v)   BF_CS1(DCIC_DCICIC, FREEZE_MASK, v)
#endif

/* --- Register HW_DCIC_DCICIC, field FI_MASK */

#define BP_DCIC_DCICIC_FI_MASK      1
#define BM_DCIC_DCICIC_FI_MASK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICIC_FI_MASK(v)   ((((reg32_t) v) << 1) & BM_DCIC_DCICIC_FI_MASK)
#else
#define BF_DCIC_DCICIC_FI_MASK(v)   (((v) << 1) & BM_DCIC_DCICIC_FI_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICIC_FI_MASK(v)   BF_CS1(DCIC_DCICIC, FI_MASK, v)
#endif

/* --- Register HW_DCIC_DCICIC, field EI_MASK */

#define BP_DCIC_DCICIC_EI_MASK      0
#define BM_DCIC_DCICIC_EI_MASK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICIC_EI_MASK(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICIC_EI_MASK)
#else
#define BF_DCIC_DCICIC_EI_MASK(v)   (((v) << 0) & BM_DCIC_DCICIC_EI_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICIC_EI_MASK(v)   BF_CS1(DCIC_DCICIC, EI_MASK, v)
#endif

/*
 * HW_DCIC_DCICS - DCIC Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned FI_STAT : 1;
        unsigned EI_STAT : 1;
        unsigned ROI_MATCH_STAT : 16;

    } B;
} hw_dcic_dcics_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICS register
 */
#define HW_DCIC_DCICS_ADDR(x)      (REGS_DCIC_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICS(x)           (*(volatile hw_dcic_dcics_t *) HW_DCIC_DCICS_ADDR(x))
#define HW_DCIC_DCICS_RD(x)        (HW_DCIC_DCICS(x).U)
#define HW_DCIC_DCICS_WR(x, v)     (HW_DCIC_DCICS(x).U = (v))
#define HW_DCIC_DCICS_SET(x, v)    (HW_DCIC_DCICS_WR(x, HW_DCIC_DCICS_RD(x) |  (v)))
#define HW_DCIC_DCICS_CLR(x, v)    (HW_DCIC_DCICS_WR(x, HW_DCIC_DCICS_RD(x) & ~(v)))
#define HW_DCIC_DCICS_TOG(x, v)    (HW_DCIC_DCICS_WR(x, HW_DCIC_DCICS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual DCIC_DCICS bitfields
 */

/* --- Register HW_DCIC_DCICS, field FI_STAT */

#define BP_DCIC_DCICS_FI_STAT      17
#define BM_DCIC_DCICS_FI_STAT      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICS_FI_STAT(v)   ((((reg32_t) v) << 17) & BM_DCIC_DCICS_FI_STAT)
#else
#define BF_DCIC_DCICS_FI_STAT(v)   (((v) << 17) & BM_DCIC_DCICS_FI_STAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICS_FI_STAT(v)   BF_CS1(DCIC_DCICS, FI_STAT, v)
#endif

/* --- Register HW_DCIC_DCICS, field EI_STAT */

#define BP_DCIC_DCICS_EI_STAT      16
#define BM_DCIC_DCICS_EI_STAT      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICS_EI_STAT(v)   ((((reg32_t) v) << 16) & BM_DCIC_DCICS_EI_STAT)
#else
#define BF_DCIC_DCICS_EI_STAT(v)   (((v) << 16) & BM_DCIC_DCICS_EI_STAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICS_EI_STAT(v)   BF_CS1(DCIC_DCICS, EI_STAT, v)
#endif

/* --- Register HW_DCIC_DCICS, field ROI_MATCH_STAT */

#define BP_DCIC_DCICS_ROI_MATCH_STAT      0
#define BM_DCIC_DCICS_ROI_MATCH_STAT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICS_ROI_MATCH_STAT(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICS_ROI_MATCH_STAT)
#else
#define BF_DCIC_DCICS_ROI_MATCH_STAT(v)   (((v) << 0) & BM_DCIC_DCICS_ROI_MATCH_STAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICS_ROI_MATCH_STAT(v)   BF_CS1(DCIC_DCICS, ROI_MATCH_STAT, v)
#endif

/*
 * HW_DCIC_DCICRC - DCIC ROI Config Register m
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ROI_EN : 1;
        unsigned ROI_FREEZE : 1;
        unsigned RESERVED0 : 2;
        unsigned START_OFFSET_Y : 12;
        unsigned RESERVED1 : 3;
        unsigned START_OFFSET_X : 13;

    } B;
} hw_dcic_dcicrc_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICRC register
 */
#define HW_DCIC_DCICRC_ADDR(x)      (REGS_DCIC_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRC(x)           (*(volatile hw_dcic_dcicrc_t *) HW_DCIC_DCICRC_ADDR(x))
#define HW_DCIC_DCICRC_RD(x)        (HW_DCIC_DCICRC(x).U)
#define HW_DCIC_DCICRC_WR(x, v)     (HW_DCIC_DCICRC(x).U = (v))
#define HW_DCIC_DCICRC_SET(x, v)    (HW_DCIC_DCICRC_WR(x, HW_DCIC_DCICRC_RD(x) |  (v)))
#define HW_DCIC_DCICRC_CLR(x, v)    (HW_DCIC_DCICRC_WR(x, HW_DCIC_DCICRC_RD(x) & ~(v)))
#define HW_DCIC_DCICRC_TOG(x, v)    (HW_DCIC_DCICRC_WR(x, HW_DCIC_DCICRC_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual DCIC_DCICRC bitfields
 */

/* --- Register HW_DCIC_DCICRC, field ROI_EN */

#define BP_DCIC_DCICRC_ROI_EN      31
#define BM_DCIC_DCICRC_ROI_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRC_ROI_EN(v)   ((((reg32_t) v) << 31) & BM_DCIC_DCICRC_ROI_EN)
#else
#define BF_DCIC_DCICRC_ROI_EN(v)   (((v) << 31) & BM_DCIC_DCICRC_ROI_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICRC_ROI_EN(v)   BF_CS1(DCIC_DCICRC, ROI_EN, v)
#endif

/* --- Register HW_DCIC_DCICRC, field ROI_FREEZE */

#define BP_DCIC_DCICRC_ROI_FREEZE      30
#define BM_DCIC_DCICRC_ROI_FREEZE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRC_ROI_FREEZE(v)   ((((reg32_t) v) << 30) & BM_DCIC_DCICRC_ROI_FREEZE)
#else
#define BF_DCIC_DCICRC_ROI_FREEZE(v)   (((v) << 30) & BM_DCIC_DCICRC_ROI_FREEZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICRC_ROI_FREEZE(v)   BF_CS1(DCIC_DCICRC, ROI_FREEZE, v)
#endif

/* --- Register HW_DCIC_DCICRC, field START_OFFSET_Y */

#define BP_DCIC_DCICRC_START_OFFSET_Y      16
#define BM_DCIC_DCICRC_START_OFFSET_Y      0x0fff0000

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRC_START_OFFSET_Y(v)   ((((reg32_t) v) << 16) & BM_DCIC_DCICRC_START_OFFSET_Y)
#else
#define BF_DCIC_DCICRC_START_OFFSET_Y(v)   (((v) << 16) & BM_DCIC_DCICRC_START_OFFSET_Y)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICRC_START_OFFSET_Y(v)   BF_CS1(DCIC_DCICRC, START_OFFSET_Y, v)
#endif

/* --- Register HW_DCIC_DCICRC, field START_OFFSET_X */

#define BP_DCIC_DCICRC_START_OFFSET_X      0
#define BM_DCIC_DCICRC_START_OFFSET_X      0x00001fff

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRC_START_OFFSET_X(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICRC_START_OFFSET_X)
#else
#define BF_DCIC_DCICRC_START_OFFSET_X(v)   (((v) << 0) & BM_DCIC_DCICRC_START_OFFSET_X)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICRC_START_OFFSET_X(v)   BF_CS1(DCIC_DCICRC, START_OFFSET_X, v)
#endif

/*
 * HW_DCIC_DCICRS - DCIC ROI Size Register m
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 4;
        unsigned END_OFFSET_Y : 12;
        unsigned RESERVED1 : 3;
        unsigned END_OFFSET_X : 13;

    } B;
} hw_dcic_dcicrs_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICRS register
 */
#define HW_DCIC_DCICRS_ADDR(x)      (REGS_DCIC_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRS(x)           (*(volatile hw_dcic_dcicrs_t *) HW_DCIC_DCICRS_ADDR(x))
#define HW_DCIC_DCICRS_RD(x)        (HW_DCIC_DCICRS(x).U)
#define HW_DCIC_DCICRS_WR(x, v)     (HW_DCIC_DCICRS(x).U = (v))
#define HW_DCIC_DCICRS_SET(x, v)    (HW_DCIC_DCICRS_WR(x, HW_DCIC_DCICRS_RD(x) |  (v)))
#define HW_DCIC_DCICRS_CLR(x, v)    (HW_DCIC_DCICRS_WR(x, HW_DCIC_DCICRS_RD(x) & ~(v)))
#define HW_DCIC_DCICRS_TOG(x, v)    (HW_DCIC_DCICRS_WR(x, HW_DCIC_DCICRS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual DCIC_DCICRS bitfields
 */

/* --- Register HW_DCIC_DCICRS, field END_OFFSET_Y */

#define BP_DCIC_DCICRS_END_OFFSET_Y      16
#define BM_DCIC_DCICRS_END_OFFSET_Y      0x0fff0000

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRS_END_OFFSET_Y(v)   ((((reg32_t) v) << 16) & BM_DCIC_DCICRS_END_OFFSET_Y)
#else
#define BF_DCIC_DCICRS_END_OFFSET_Y(v)   (((v) << 16) & BM_DCIC_DCICRS_END_OFFSET_Y)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICRS_END_OFFSET_Y(v)   BF_CS1(DCIC_DCICRS, END_OFFSET_Y, v)
#endif

/* --- Register HW_DCIC_DCICRS, field END_OFFSET_X */

#define BP_DCIC_DCICRS_END_OFFSET_X      0
#define BM_DCIC_DCICRS_END_OFFSET_X      0x00001fff

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRS_END_OFFSET_X(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICRS_END_OFFSET_X)
#else
#define BF_DCIC_DCICRS_END_OFFSET_X(v)   (((v) << 0) & BM_DCIC_DCICRS_END_OFFSET_X)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICRS_END_OFFSET_X(v)   BF_CS1(DCIC_DCICRS, END_OFFSET_X, v)
#endif

/*
 * HW_DCIC_DCICRRS - DCIC ROI Reference Signature Register m
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned REFERENCE_SIGNATURE : 32;

    } B;
} hw_dcic_dcicrrs_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICRRS register
 */
#define HW_DCIC_DCICRRS_ADDR(x)      (REGS_DCIC_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRRS(x)           (*(volatile hw_dcic_dcicrrs_t *) HW_DCIC_DCICRRS_ADDR(x))
#define HW_DCIC_DCICRRS_RD(x)        (HW_DCIC_DCICRRS(x).U)
#define HW_DCIC_DCICRRS_WR(x, v)     (HW_DCIC_DCICRRS(x).U = (v))
#define HW_DCIC_DCICRRS_SET(x, v)    (HW_DCIC_DCICRRS_WR(x, HW_DCIC_DCICRRS_RD(x) |  (v)))
#define HW_DCIC_DCICRRS_CLR(x, v)    (HW_DCIC_DCICRRS_WR(x, HW_DCIC_DCICRRS_RD(x) & ~(v)))
#define HW_DCIC_DCICRRS_TOG(x, v)    (HW_DCIC_DCICRRS_WR(x, HW_DCIC_DCICRRS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual DCIC_DCICRRS bitfields
 */

/* --- Register HW_DCIC_DCICRRS, field REFERENCE_SIGNATURE */

#define BP_DCIC_DCICRRS_REFERENCE_SIGNATURE      0
#define BM_DCIC_DCICRRS_REFERENCE_SIGNATURE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICRRS_REFERENCE_SIGNATURE)
#else
#define BF_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)   (((v) << 0) & BM_DCIC_DCICRRS_REFERENCE_SIGNATURE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)   BF_CS1(DCIC_DCICRRS, REFERENCE_SIGNATURE, v)
#endif

/*
 * HW_DCIC_DCICRCS - DCIC ROI Calculated Signature m
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CALCULATED_SIGNATURE : 32;

    } B;
} hw_dcic_dcicrcs_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICRCS register
 */
#define HW_DCIC_DCICRCS_ADDR(x)      (REGS_DCIC_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRCS(x)           (*(volatile hw_dcic_dcicrcs_t *) HW_DCIC_DCICRCS_ADDR(x))
#define HW_DCIC_DCICRCS_RD(x)        (HW_DCIC_DCICRCS(x).U)
#define HW_DCIC_DCICRCS_WR(x, v)     (HW_DCIC_DCICRCS(x).U = (v))
#define HW_DCIC_DCICRCS_SET(x, v)    (HW_DCIC_DCICRCS_WR(x, HW_DCIC_DCICRCS_RD(x) |  (v)))
#define HW_DCIC_DCICRCS_CLR(x, v)    (HW_DCIC_DCICRCS_WR(x, HW_DCIC_DCICRCS_RD(x) & ~(v)))
#define HW_DCIC_DCICRCS_TOG(x, v)    (HW_DCIC_DCICRCS_WR(x, HW_DCIC_DCICRCS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual DCIC_DCICRCS bitfields
 */

/* --- Register HW_DCIC_DCICRCS, field CALCULATED_SIGNATURE */

#define BP_DCIC_DCICRCS_CALCULATED_SIGNATURE      0
#define BM_DCIC_DCICRCS_CALCULATED_SIGNATURE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRCS_CALCULATED_SIGNATURE(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICRCS_CALCULATED_SIGNATURE)
#else
#define BF_DCIC_DCICRCS_CALCULATED_SIGNATURE(v)   (((v) << 0) & BM_DCIC_DCICRCS_CALCULATED_SIGNATURE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DCIC_DCICRCS_CALCULATED_SIGNATURE(v)   BF_CS1(DCIC_DCICRCS, CALCULATED_SIGNATURE, v)
#endif


#endif // _DCIC_H

