/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _VDOA_H
#define _VDOA_H

#include "regs.h"

#ifndef REGS_VDOA_BASE
#define REGS_VDOA_BASE (REGS_BASE + 0x021e4000)

#endif


/*
 * HW_VDOA_VDOAC - VDOA Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BNDM : 2;
        unsigned NF : 1;
        unsigned SYNC : 1;
        unsigned SO : 1;
        unsigned PFS : 1;
        unsigned ISEL : 1;
        unsigned RESERVED0 : 25;

    } B;
} hw_vdoa_vdoac_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAC register
 */
#define HW_VDOA_VDOAC_ADDR      (REGS_VDOA_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAC           (*(volatile hw_vdoa_vdoac_t *) HW_VDOA_VDOAC_ADDR)
#define HW_VDOA_VDOAC_RD()      (HW_VDOA_VDOAC.U)
#define HW_VDOA_VDOAC_WR(v)     (HW_VDOA_VDOAC.U = (v))
#define HW_VDOA_VDOAC_SET(v)    (HW_VDOA_VDOAC_WR(HW_VDOA_VDOAC_RD() |  (v)))
#define HW_VDOA_VDOAC_CLR(v)    (HW_VDOA_VDOAC_WR(HW_VDOA_VDOAC_RD() & ~(v)))
#define HW_VDOA_VDOAC_TOG(v)    (HW_VDOA_VDOAC_WR(HW_VDOA_VDOAC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAC bitfields
 */

/* --- Register HW_VDOA_VDOAC, field BNDM */

#define BP_VDOA_VDOAC_BNDM      0
#define BM_VDOA_VDOAC_BNDM      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAC_BNDM(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAC_BNDM)
#else
#define BF_VDOA_VDOAC_BNDM(v)   (((v) << 0) & BM_VDOA_VDOAC_BNDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAC_BNDM(v)   BF_CS1(VDOA_VDOAC, BNDM, v)
#endif

/* --- Register HW_VDOA_VDOAC, field NF */

#define BP_VDOA_VDOAC_NF      2
#define BM_VDOA_VDOAC_NF      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAC_NF(v)   ((((reg32_t) v) << 2) & BM_VDOA_VDOAC_NF)
#else
#define BF_VDOA_VDOAC_NF(v)   (((v) << 2) & BM_VDOA_VDOAC_NF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAC_NF(v)   BF_CS1(VDOA_VDOAC, NF, v)
#endif

/* --- Register HW_VDOA_VDOAC, field SYNC */

#define BP_VDOA_VDOAC_SYNC      3
#define BM_VDOA_VDOAC_SYNC      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAC_SYNC(v)   ((((reg32_t) v) << 3) & BM_VDOA_VDOAC_SYNC)
#else
#define BF_VDOA_VDOAC_SYNC(v)   (((v) << 3) & BM_VDOA_VDOAC_SYNC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAC_SYNC(v)   BF_CS1(VDOA_VDOAC, SYNC, v)
#endif

/* --- Register HW_VDOA_VDOAC, field SO */

#define BP_VDOA_VDOAC_SO      4
#define BM_VDOA_VDOAC_SO      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAC_SO(v)   ((((reg32_t) v) << 4) & BM_VDOA_VDOAC_SO)
#else
#define BF_VDOA_VDOAC_SO(v)   (((v) << 4) & BM_VDOA_VDOAC_SO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAC_SO(v)   BF_CS1(VDOA_VDOAC, SO, v)
#endif

/* --- Register HW_VDOA_VDOAC, field PFS */

#define BP_VDOA_VDOAC_PFS      5
#define BM_VDOA_VDOAC_PFS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAC_PFS(v)   ((((reg32_t) v) << 5) & BM_VDOA_VDOAC_PFS)
#else
#define BF_VDOA_VDOAC_PFS(v)   (((v) << 5) & BM_VDOA_VDOAC_PFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAC_PFS(v)   BF_CS1(VDOA_VDOAC, PFS, v)
#endif

/* --- Register HW_VDOA_VDOAC, field ISEL */

#define BP_VDOA_VDOAC_ISEL      6
#define BM_VDOA_VDOAC_ISEL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAC_ISEL(v)   ((((reg32_t) v) << 6) & BM_VDOA_VDOAC_ISEL)
#else
#define BF_VDOA_VDOAC_ISEL(v)   (((v) << 6) & BM_VDOA_VDOAC_ISEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAC_ISEL(v)   BF_CS1(VDOA_VDOAC, ISEL, v)
#endif

/*
 * HW_VDOA_VDOASRR - VDOA Start and Reset
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SWRST : 1;
        unsigned START : 1;
        unsigned RESERVED0 : 30;

    } B;
} hw_vdoa_vdoasrr_t;
#endif

/*
 * constants & macros for entire VDOA_VDOASRR register
 */
#define HW_VDOA_VDOASRR_ADDR      (REGS_VDOA_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOASRR           (*(volatile hw_vdoa_vdoasrr_t *) HW_VDOA_VDOASRR_ADDR)
#define HW_VDOA_VDOASRR_RD()      (HW_VDOA_VDOASRR.U)
#define HW_VDOA_VDOASRR_WR(v)     (HW_VDOA_VDOASRR.U = (v))
#define HW_VDOA_VDOASRR_SET(v)    (HW_VDOA_VDOASRR_WR(HW_VDOA_VDOASRR_RD() |  (v)))
#define HW_VDOA_VDOASRR_CLR(v)    (HW_VDOA_VDOASRR_WR(HW_VDOA_VDOASRR_RD() & ~(v)))
#define HW_VDOA_VDOASRR_TOG(v)    (HW_VDOA_VDOASRR_WR(HW_VDOA_VDOASRR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOASRR bitfields
 */

/* --- Register HW_VDOA_VDOASRR, field SWRST */

#define BP_VDOA_VDOASRR_SWRST      0
#define BM_VDOA_VDOASRR_SWRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOASRR_SWRST(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOASRR_SWRST)
#else
#define BF_VDOA_VDOASRR_SWRST(v)   (((v) << 0) & BM_VDOA_VDOASRR_SWRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOASRR_SWRST(v)   BF_CS1(VDOA_VDOASRR, SWRST, v)
#endif

/* --- Register HW_VDOA_VDOASRR, field START */

#define BP_VDOA_VDOASRR_START      1
#define BM_VDOA_VDOASRR_START      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOASRR_START(v)   ((((reg32_t) v) << 1) & BM_VDOA_VDOASRR_START)
#else
#define BF_VDOA_VDOASRR_START(v)   (((v) << 1) & BM_VDOA_VDOASRR_START)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOASRR_START(v)   BF_CS1(VDOA_VDOASRR, START, v)
#endif

/*
 * HW_VDOA_VDOAIE - VDOA Interrupt Enable Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EIEOT : 1;
        unsigned EITERR : 1;
        unsigned RESERVED0 : 30;

    } B;
} hw_vdoa_vdoaie_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIE register
 */
#define HW_VDOA_VDOAIE_ADDR      (REGS_VDOA_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIE           (*(volatile hw_vdoa_vdoaie_t *) HW_VDOA_VDOAIE_ADDR)
#define HW_VDOA_VDOAIE_RD()      (HW_VDOA_VDOAIE.U)
#define HW_VDOA_VDOAIE_WR(v)     (HW_VDOA_VDOAIE.U = (v))
#define HW_VDOA_VDOAIE_SET(v)    (HW_VDOA_VDOAIE_WR(HW_VDOA_VDOAIE_RD() |  (v)))
#define HW_VDOA_VDOAIE_CLR(v)    (HW_VDOA_VDOAIE_WR(HW_VDOA_VDOAIE_RD() & ~(v)))
#define HW_VDOA_VDOAIE_TOG(v)    (HW_VDOA_VDOAIE_WR(HW_VDOA_VDOAIE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIE bitfields
 */

/* --- Register HW_VDOA_VDOAIE, field EIEOT */

#define BP_VDOA_VDOAIE_EIEOT      0
#define BM_VDOA_VDOAIE_EIEOT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIE_EIEOT(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIE_EIEOT)
#else
#define BF_VDOA_VDOAIE_EIEOT(v)   (((v) << 0) & BM_VDOA_VDOAIE_EIEOT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIE_EIEOT(v)   BF_CS1(VDOA_VDOAIE, EIEOT, v)
#endif

/* --- Register HW_VDOA_VDOAIE, field EITERR */

#define BP_VDOA_VDOAIE_EITERR      1
#define BM_VDOA_VDOAIE_EITERR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIE_EITERR(v)   ((((reg32_t) v) << 1) & BM_VDOA_VDOAIE_EITERR)
#else
#define BF_VDOA_VDOAIE_EITERR(v)   (((v) << 1) & BM_VDOA_VDOAIE_EITERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIE_EITERR(v)   BF_CS1(VDOA_VDOAIE, EITERR, v)
#endif

/*
 * HW_VDOA_VDOAIST - VDOA Interrupt Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EOT : 1;
        unsigned TERR : 1;
        unsigned RESERVED0 : 30;

    } B;
} hw_vdoa_vdoaist_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIST register
 */
#define HW_VDOA_VDOAIST_ADDR      (REGS_VDOA_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIST           (*(volatile hw_vdoa_vdoaist_t *) HW_VDOA_VDOAIST_ADDR)
#define HW_VDOA_VDOAIST_RD()      (HW_VDOA_VDOAIST.U)
#define HW_VDOA_VDOAIST_WR(v)     (HW_VDOA_VDOAIST.U = (v))
#define HW_VDOA_VDOAIST_SET(v)    (HW_VDOA_VDOAIST_WR(HW_VDOA_VDOAIST_RD() |  (v)))
#define HW_VDOA_VDOAIST_CLR(v)    (HW_VDOA_VDOAIST_WR(HW_VDOA_VDOAIST_RD() & ~(v)))
#define HW_VDOA_VDOAIST_TOG(v)    (HW_VDOA_VDOAIST_WR(HW_VDOA_VDOAIST_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIST bitfields
 */

/* --- Register HW_VDOA_VDOAIST, field EOT */

#define BP_VDOA_VDOAIST_EOT      0
#define BM_VDOA_VDOAIST_EOT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIST_EOT(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIST_EOT)
#else
#define BF_VDOA_VDOAIST_EOT(v)   (((v) << 0) & BM_VDOA_VDOAIST_EOT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIST_EOT(v)   BF_CS1(VDOA_VDOAIST, EOT, v)
#endif

/* --- Register HW_VDOA_VDOAIST, field TERR */

#define BP_VDOA_VDOAIST_TERR      1
#define BM_VDOA_VDOAIST_TERR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIST_TERR(v)   ((((reg32_t) v) << 1) & BM_VDOA_VDOAIST_TERR)
#else
#define BF_VDOA_VDOAIST_TERR(v)   (((v) << 1) & BM_VDOA_VDOAIST_TERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIST_TERR(v)   BF_CS1(VDOA_VDOAIST, TERR, v)
#endif

/*
 * HW_VDOA_VDOAFP - VDOA Frame Parameters Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FW : 14;
        unsigned RESERVED0 : 2;
        unsigned FH : 13;
        unsigned RESERVED1 : 3;

    } B;
} hw_vdoa_vdoafp_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAFP register
 */
#define HW_VDOA_VDOAFP_ADDR      (REGS_VDOA_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAFP           (*(volatile hw_vdoa_vdoafp_t *) HW_VDOA_VDOAFP_ADDR)
#define HW_VDOA_VDOAFP_RD()      (HW_VDOA_VDOAFP.U)
#define HW_VDOA_VDOAFP_WR(v)     (HW_VDOA_VDOAFP.U = (v))
#define HW_VDOA_VDOAFP_SET(v)    (HW_VDOA_VDOAFP_WR(HW_VDOA_VDOAFP_RD() |  (v)))
#define HW_VDOA_VDOAFP_CLR(v)    (HW_VDOA_VDOAFP_WR(HW_VDOA_VDOAFP_RD() & ~(v)))
#define HW_VDOA_VDOAFP_TOG(v)    (HW_VDOA_VDOAFP_WR(HW_VDOA_VDOAFP_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAFP bitfields
 */

/* --- Register HW_VDOA_VDOAFP, field FW */

#define BP_VDOA_VDOAFP_FW      0
#define BM_VDOA_VDOAFP_FW      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAFP_FW(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAFP_FW)
#else
#define BF_VDOA_VDOAFP_FW(v)   (((v) << 0) & BM_VDOA_VDOAFP_FW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAFP_FW(v)   BF_CS1(VDOA_VDOAFP, FW, v)
#endif

/* --- Register HW_VDOA_VDOAFP, field FH */

#define BP_VDOA_VDOAFP_FH      16
#define BM_VDOA_VDOAFP_FH      0x1fff0000

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAFP_FH(v)   ((((reg32_t) v) << 16) & BM_VDOA_VDOAFP_FH)
#else
#define BF_VDOA_VDOAFP_FH(v)   (((v) << 16) & BM_VDOA_VDOAFP_FH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAFP_FH(v)   BF_CS1(VDOA_VDOAFP, FH, v)
#endif

/*
 * HW_VDOA_VDOAIEBA00 - VDOA IPU External Buffer 0 Frame 0 Address
                        Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IEBA00 : 32;

    } B;
} hw_vdoa_vdoaieba00_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA00 register
 */
#define HW_VDOA_VDOAIEBA00_ADDR      (REGS_VDOA_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA00           (*(volatile hw_vdoa_vdoaieba00_t *) HW_VDOA_VDOAIEBA00_ADDR)
#define HW_VDOA_VDOAIEBA00_RD()      (HW_VDOA_VDOAIEBA00.U)
#define HW_VDOA_VDOAIEBA00_WR(v)     (HW_VDOA_VDOAIEBA00.U = (v))
#define HW_VDOA_VDOAIEBA00_SET(v)    (HW_VDOA_VDOAIEBA00_WR(HW_VDOA_VDOAIEBA00_RD() |  (v)))
#define HW_VDOA_VDOAIEBA00_CLR(v)    (HW_VDOA_VDOAIEBA00_WR(HW_VDOA_VDOAIEBA00_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA00_TOG(v)    (HW_VDOA_VDOAIEBA00_WR(HW_VDOA_VDOAIEBA00_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIEBA00 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA00, field IEBA00 */

#define BP_VDOA_VDOAIEBA00_IEBA00      0
#define BM_VDOA_VDOAIEBA00_IEBA00      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIEBA00_IEBA00(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIEBA00_IEBA00)
#else
#define BF_VDOA_VDOAIEBA00_IEBA00(v)   (((v) << 0) & BM_VDOA_VDOAIEBA00_IEBA00)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIEBA00_IEBA00(v)   BF_CS1(VDOA_VDOAIEBA00, IEBA00, v)
#endif

/*
 * HW_VDOA_VDOAIEBA01 - VDOA IPU External Buffer 0 Frame 1 Address
                        Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IEBA01 : 32;

    } B;
} hw_vdoa_vdoaieba01_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA01 register
 */
#define HW_VDOA_VDOAIEBA01_ADDR      (REGS_VDOA_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA01           (*(volatile hw_vdoa_vdoaieba01_t *) HW_VDOA_VDOAIEBA01_ADDR)
#define HW_VDOA_VDOAIEBA01_RD()      (HW_VDOA_VDOAIEBA01.U)
#define HW_VDOA_VDOAIEBA01_WR(v)     (HW_VDOA_VDOAIEBA01.U = (v))
#define HW_VDOA_VDOAIEBA01_SET(v)    (HW_VDOA_VDOAIEBA01_WR(HW_VDOA_VDOAIEBA01_RD() |  (v)))
#define HW_VDOA_VDOAIEBA01_CLR(v)    (HW_VDOA_VDOAIEBA01_WR(HW_VDOA_VDOAIEBA01_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA01_TOG(v)    (HW_VDOA_VDOAIEBA01_WR(HW_VDOA_VDOAIEBA01_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIEBA01 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA01, field IEBA01 */

#define BP_VDOA_VDOAIEBA01_IEBA01      0
#define BM_VDOA_VDOAIEBA01_IEBA01      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIEBA01_IEBA01(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIEBA01_IEBA01)
#else
#define BF_VDOA_VDOAIEBA01_IEBA01(v)   (((v) << 0) & BM_VDOA_VDOAIEBA01_IEBA01)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIEBA01_IEBA01(v)   BF_CS1(VDOA_VDOAIEBA01, IEBA01, v)
#endif

/*
 * HW_VDOA_VDOAIEBA02 - VDOA IPU External Buffer 0 Frame 2 Address
                        Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IEBA02 : 32;

    } B;
} hw_vdoa_vdoaieba02_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA02 register
 */
#define HW_VDOA_VDOAIEBA02_ADDR      (REGS_VDOA_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA02           (*(volatile hw_vdoa_vdoaieba02_t *) HW_VDOA_VDOAIEBA02_ADDR)
#define HW_VDOA_VDOAIEBA02_RD()      (HW_VDOA_VDOAIEBA02.U)
#define HW_VDOA_VDOAIEBA02_WR(v)     (HW_VDOA_VDOAIEBA02.U = (v))
#define HW_VDOA_VDOAIEBA02_SET(v)    (HW_VDOA_VDOAIEBA02_WR(HW_VDOA_VDOAIEBA02_RD() |  (v)))
#define HW_VDOA_VDOAIEBA02_CLR(v)    (HW_VDOA_VDOAIEBA02_WR(HW_VDOA_VDOAIEBA02_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA02_TOG(v)    (HW_VDOA_VDOAIEBA02_WR(HW_VDOA_VDOAIEBA02_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIEBA02 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA02, field IEBA02 */

#define BP_VDOA_VDOAIEBA02_IEBA02      0
#define BM_VDOA_VDOAIEBA02_IEBA02      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIEBA02_IEBA02(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIEBA02_IEBA02)
#else
#define BF_VDOA_VDOAIEBA02_IEBA02(v)   (((v) << 0) & BM_VDOA_VDOAIEBA02_IEBA02)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIEBA02_IEBA02(v)   BF_CS1(VDOA_VDOAIEBA02, IEBA02, v)
#endif

/*
 * HW_VDOA_VDOAIEBA10 - VDOA IPU External Buffer 1 Frame 0 Address
                        Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IEBA10 : 32;

    } B;
} hw_vdoa_vdoaieba10_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA10 register
 */
#define HW_VDOA_VDOAIEBA10_ADDR      (REGS_VDOA_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA10           (*(volatile hw_vdoa_vdoaieba10_t *) HW_VDOA_VDOAIEBA10_ADDR)
#define HW_VDOA_VDOAIEBA10_RD()      (HW_VDOA_VDOAIEBA10.U)
#define HW_VDOA_VDOAIEBA10_WR(v)     (HW_VDOA_VDOAIEBA10.U = (v))
#define HW_VDOA_VDOAIEBA10_SET(v)    (HW_VDOA_VDOAIEBA10_WR(HW_VDOA_VDOAIEBA10_RD() |  (v)))
#define HW_VDOA_VDOAIEBA10_CLR(v)    (HW_VDOA_VDOAIEBA10_WR(HW_VDOA_VDOAIEBA10_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA10_TOG(v)    (HW_VDOA_VDOAIEBA10_WR(HW_VDOA_VDOAIEBA10_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIEBA10 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA10, field IEBA10 */

#define BP_VDOA_VDOAIEBA10_IEBA10      0
#define BM_VDOA_VDOAIEBA10_IEBA10      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIEBA10_IEBA10(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIEBA10_IEBA10)
#else
#define BF_VDOA_VDOAIEBA10_IEBA10(v)   (((v) << 0) & BM_VDOA_VDOAIEBA10_IEBA10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIEBA10_IEBA10(v)   BF_CS1(VDOA_VDOAIEBA10, IEBA10, v)
#endif

/*
 * HW_VDOA_VDOAIEBA11 - VDOA IPU External Buffer 1 Frame 1 Address
                        Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IEBA11 : 32;

    } B;
} hw_vdoa_vdoaieba11_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA11 register
 */
#define HW_VDOA_VDOAIEBA11_ADDR      (REGS_VDOA_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA11           (*(volatile hw_vdoa_vdoaieba11_t *) HW_VDOA_VDOAIEBA11_ADDR)
#define HW_VDOA_VDOAIEBA11_RD()      (HW_VDOA_VDOAIEBA11.U)
#define HW_VDOA_VDOAIEBA11_WR(v)     (HW_VDOA_VDOAIEBA11.U = (v))
#define HW_VDOA_VDOAIEBA11_SET(v)    (HW_VDOA_VDOAIEBA11_WR(HW_VDOA_VDOAIEBA11_RD() |  (v)))
#define HW_VDOA_VDOAIEBA11_CLR(v)    (HW_VDOA_VDOAIEBA11_WR(HW_VDOA_VDOAIEBA11_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA11_TOG(v)    (HW_VDOA_VDOAIEBA11_WR(HW_VDOA_VDOAIEBA11_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIEBA11 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA11, field IEBA11 */

#define BP_VDOA_VDOAIEBA11_IEBA11      0
#define BM_VDOA_VDOAIEBA11_IEBA11      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIEBA11_IEBA11(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIEBA11_IEBA11)
#else
#define BF_VDOA_VDOAIEBA11_IEBA11(v)   (((v) << 0) & BM_VDOA_VDOAIEBA11_IEBA11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIEBA11_IEBA11(v)   BF_CS1(VDOA_VDOAIEBA11, IEBA11, v)
#endif

/*
 * HW_VDOA_VDOAIEBA12 - VDOA IPU External Buffer 1 Frame 2 Address
                        Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IEBA12 : 32;

    } B;
} hw_vdoa_vdoaieba12_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA12 register
 */
#define HW_VDOA_VDOAIEBA12_ADDR      (REGS_VDOA_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA12           (*(volatile hw_vdoa_vdoaieba12_t *) HW_VDOA_VDOAIEBA12_ADDR)
#define HW_VDOA_VDOAIEBA12_RD()      (HW_VDOA_VDOAIEBA12.U)
#define HW_VDOA_VDOAIEBA12_WR(v)     (HW_VDOA_VDOAIEBA12.U = (v))
#define HW_VDOA_VDOAIEBA12_SET(v)    (HW_VDOA_VDOAIEBA12_WR(HW_VDOA_VDOAIEBA12_RD() |  (v)))
#define HW_VDOA_VDOAIEBA12_CLR(v)    (HW_VDOA_VDOAIEBA12_WR(HW_VDOA_VDOAIEBA12_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA12_TOG(v)    (HW_VDOA_VDOAIEBA12_WR(HW_VDOA_VDOAIEBA12_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIEBA12 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA12, field IEBA12 */

#define BP_VDOA_VDOAIEBA12_IEBA12      0
#define BM_VDOA_VDOAIEBA12_IEBA12      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIEBA12_IEBA12(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIEBA12_IEBA12)
#else
#define BF_VDOA_VDOAIEBA12_IEBA12(v)   (((v) << 0) & BM_VDOA_VDOAIEBA12_IEBA12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIEBA12_IEBA12(v)   BF_CS1(VDOA_VDOAIEBA12, IEBA12, v)
#endif

/*
 * HW_VDOA_VDOASL - VDOA IPU Stride Line Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ISLY : 15;
        unsigned RESERVED0 : 1;
        unsigned VSLY : 14;
        unsigned RESERVED1 : 2;

    } B;
} hw_vdoa_vdoasl_t;
#endif

/*
 * constants & macros for entire VDOA_VDOASL register
 */
#define HW_VDOA_VDOASL_ADDR      (REGS_VDOA_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOASL           (*(volatile hw_vdoa_vdoasl_t *) HW_VDOA_VDOASL_ADDR)
#define HW_VDOA_VDOASL_RD()      (HW_VDOA_VDOASL.U)
#define HW_VDOA_VDOASL_WR(v)     (HW_VDOA_VDOASL.U = (v))
#define HW_VDOA_VDOASL_SET(v)    (HW_VDOA_VDOASL_WR(HW_VDOA_VDOASL_RD() |  (v)))
#define HW_VDOA_VDOASL_CLR(v)    (HW_VDOA_VDOASL_WR(HW_VDOA_VDOASL_RD() & ~(v)))
#define HW_VDOA_VDOASL_TOG(v)    (HW_VDOA_VDOASL_WR(HW_VDOA_VDOASL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOASL bitfields
 */

/* --- Register HW_VDOA_VDOASL, field ISLY */

#define BP_VDOA_VDOASL_ISLY      0
#define BM_VDOA_VDOASL_ISLY      0x00007fff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOASL_ISLY(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOASL_ISLY)
#else
#define BF_VDOA_VDOASL_ISLY(v)   (((v) << 0) & BM_VDOA_VDOASL_ISLY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOASL_ISLY(v)   BF_CS1(VDOA_VDOASL, ISLY, v)
#endif

/* --- Register HW_VDOA_VDOASL, field VSLY */

#define BP_VDOA_VDOASL_VSLY      16
#define BM_VDOA_VDOASL_VSLY      0x3fff0000

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOASL_VSLY(v)   ((((reg32_t) v) << 16) & BM_VDOA_VDOASL_VSLY)
#else
#define BF_VDOA_VDOASL_VSLY(v)   (((v) << 16) & BM_VDOA_VDOASL_VSLY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOASL_VSLY(v)   BF_CS1(VDOA_VDOASL, VSLY, v)
#endif

/*
 * HW_VDOA_VDOAIUBO - VDOA IPU U (Chroma) Buffer Offset Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IUBO : 27;
        unsigned RESERVED0 : 5;

    } B;
} hw_vdoa_vdoaiubo_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIUBO register
 */
#define HW_VDOA_VDOAIUBO_ADDR      (REGS_VDOA_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIUBO           (*(volatile hw_vdoa_vdoaiubo_t *) HW_VDOA_VDOAIUBO_ADDR)
#define HW_VDOA_VDOAIUBO_RD()      (HW_VDOA_VDOAIUBO.U)
#define HW_VDOA_VDOAIUBO_WR(v)     (HW_VDOA_VDOAIUBO.U = (v))
#define HW_VDOA_VDOAIUBO_SET(v)    (HW_VDOA_VDOAIUBO_WR(HW_VDOA_VDOAIUBO_RD() |  (v)))
#define HW_VDOA_VDOAIUBO_CLR(v)    (HW_VDOA_VDOAIUBO_WR(HW_VDOA_VDOAIUBO_RD() & ~(v)))
#define HW_VDOA_VDOAIUBO_TOG(v)    (HW_VDOA_VDOAIUBO_WR(HW_VDOA_VDOAIUBO_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAIUBO bitfields
 */

/* --- Register HW_VDOA_VDOAIUBO, field IUBO */

#define BP_VDOA_VDOAIUBO_IUBO      0
#define BM_VDOA_VDOAIUBO_IUBO      0x07ffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAIUBO_IUBO(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAIUBO_IUBO)
#else
#define BF_VDOA_VDOAIUBO_IUBO(v)   (((v) << 0) & BM_VDOA_VDOAIUBO_IUBO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAIUBO_IUBO(v)   BF_CS1(VDOA_VDOAIUBO, IUBO, v)
#endif

/*
 * HW_VDOA_VDOAVEBA0 - VDOA VPU External Buffer 0 Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned VEBA0 : 32;

    } B;
} hw_vdoa_vdoaveba0_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAVEBA0 register
 */
#define HW_VDOA_VDOAVEBA0_ADDR      (REGS_VDOA_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAVEBA0           (*(volatile hw_vdoa_vdoaveba0_t *) HW_VDOA_VDOAVEBA0_ADDR)
#define HW_VDOA_VDOAVEBA0_RD()      (HW_VDOA_VDOAVEBA0.U)
#define HW_VDOA_VDOAVEBA0_WR(v)     (HW_VDOA_VDOAVEBA0.U = (v))
#define HW_VDOA_VDOAVEBA0_SET(v)    (HW_VDOA_VDOAVEBA0_WR(HW_VDOA_VDOAVEBA0_RD() |  (v)))
#define HW_VDOA_VDOAVEBA0_CLR(v)    (HW_VDOA_VDOAVEBA0_WR(HW_VDOA_VDOAVEBA0_RD() & ~(v)))
#define HW_VDOA_VDOAVEBA0_TOG(v)    (HW_VDOA_VDOAVEBA0_WR(HW_VDOA_VDOAVEBA0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAVEBA0 bitfields
 */

/* --- Register HW_VDOA_VDOAVEBA0, field VEBA0 */

#define BP_VDOA_VDOAVEBA0_VEBA0      0
#define BM_VDOA_VDOAVEBA0_VEBA0      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAVEBA0_VEBA0(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAVEBA0_VEBA0)
#else
#define BF_VDOA_VDOAVEBA0_VEBA0(v)   (((v) << 0) & BM_VDOA_VDOAVEBA0_VEBA0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAVEBA0_VEBA0(v)   BF_CS1(VDOA_VDOAVEBA0, VEBA0, v)
#endif

/*
 * HW_VDOA_VDOAVEBA1 - VDOA VPU External Buffer 1 Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned VEBA1 : 32;

    } B;
} hw_vdoa_vdoaveba1_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAVEBA1 register
 */
#define HW_VDOA_VDOAVEBA1_ADDR      (REGS_VDOA_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAVEBA1           (*(volatile hw_vdoa_vdoaveba1_t *) HW_VDOA_VDOAVEBA1_ADDR)
#define HW_VDOA_VDOAVEBA1_RD()      (HW_VDOA_VDOAVEBA1.U)
#define HW_VDOA_VDOAVEBA1_WR(v)     (HW_VDOA_VDOAVEBA1.U = (v))
#define HW_VDOA_VDOAVEBA1_SET(v)    (HW_VDOA_VDOAVEBA1_WR(HW_VDOA_VDOAVEBA1_RD() |  (v)))
#define HW_VDOA_VDOAVEBA1_CLR(v)    (HW_VDOA_VDOAVEBA1_WR(HW_VDOA_VDOAVEBA1_RD() & ~(v)))
#define HW_VDOA_VDOAVEBA1_TOG(v)    (HW_VDOA_VDOAVEBA1_WR(HW_VDOA_VDOAVEBA1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAVEBA1 bitfields
 */

/* --- Register HW_VDOA_VDOAVEBA1, field VEBA1 */

#define BP_VDOA_VDOAVEBA1_VEBA1      0
#define BM_VDOA_VDOAVEBA1_VEBA1      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAVEBA1_VEBA1(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAVEBA1_VEBA1)
#else
#define BF_VDOA_VDOAVEBA1_VEBA1(v)   (((v) << 0) & BM_VDOA_VDOAVEBA1_VEBA1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAVEBA1_VEBA1(v)   BF_CS1(VDOA_VDOAVEBA1, VEBA1, v)
#endif

/*
 * HW_VDOA_VDOAVEBA2 - VDOA VPU External Buffer 2 Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned VEBA2 : 32;

    } B;
} hw_vdoa_vdoaveba2_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAVEBA2 register
 */
#define HW_VDOA_VDOAVEBA2_ADDR      (REGS_VDOA_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAVEBA2           (*(volatile hw_vdoa_vdoaveba2_t *) HW_VDOA_VDOAVEBA2_ADDR)
#define HW_VDOA_VDOAVEBA2_RD()      (HW_VDOA_VDOAVEBA2.U)
#define HW_VDOA_VDOAVEBA2_WR(v)     (HW_VDOA_VDOAVEBA2.U = (v))
#define HW_VDOA_VDOAVEBA2_SET(v)    (HW_VDOA_VDOAVEBA2_WR(HW_VDOA_VDOAVEBA2_RD() |  (v)))
#define HW_VDOA_VDOAVEBA2_CLR(v)    (HW_VDOA_VDOAVEBA2_WR(HW_VDOA_VDOAVEBA2_RD() & ~(v)))
#define HW_VDOA_VDOAVEBA2_TOG(v)    (HW_VDOA_VDOAVEBA2_WR(HW_VDOA_VDOAVEBA2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAVEBA2 bitfields
 */

/* --- Register HW_VDOA_VDOAVEBA2, field VEBA2 */

#define BP_VDOA_VDOAVEBA2_VEBA2      0
#define BM_VDOA_VDOAVEBA2_VEBA2      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAVEBA2_VEBA2(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAVEBA2_VEBA2)
#else
#define BF_VDOA_VDOAVEBA2_VEBA2(v)   (((v) << 0) & BM_VDOA_VDOAVEBA2_VEBA2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAVEBA2_VEBA2(v)   BF_CS1(VDOA_VDOAVEBA2, VEBA2, v)
#endif

/*
 * HW_VDOA_VDOAVUBO - VDOA VPU U (Chroma) Buffer Offset Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned VUBO : 27;
        unsigned RESERVED0 : 5;

    } B;
} hw_vdoa_vdoavubo_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAVUBO register
 */
#define HW_VDOA_VDOAVUBO_ADDR      (REGS_VDOA_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAVUBO           (*(volatile hw_vdoa_vdoavubo_t *) HW_VDOA_VDOAVUBO_ADDR)
#define HW_VDOA_VDOAVUBO_RD()      (HW_VDOA_VDOAVUBO.U)
#define HW_VDOA_VDOAVUBO_WR(v)     (HW_VDOA_VDOAVUBO.U = (v))
#define HW_VDOA_VDOAVUBO_SET(v)    (HW_VDOA_VDOAVUBO_WR(HW_VDOA_VDOAVUBO_RD() |  (v)))
#define HW_VDOA_VDOAVUBO_CLR(v)    (HW_VDOA_VDOAVUBO_WR(HW_VDOA_VDOAVUBO_RD() & ~(v)))
#define HW_VDOA_VDOAVUBO_TOG(v)    (HW_VDOA_VDOAVUBO_WR(HW_VDOA_VDOAVUBO_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOAVUBO bitfields
 */

/* --- Register HW_VDOA_VDOAVUBO, field VUBO */

#define BP_VDOA_VDOAVUBO_VUBO      0
#define BM_VDOA_VDOAVUBO_VUBO      0x07ffffff

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOAVUBO_VUBO(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOAVUBO_VUBO)
#else
#define BF_VDOA_VDOAVUBO_VUBO(v)   (((v) << 0) & BM_VDOA_VDOAVUBO_VUBO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOAVUBO_VUBO(v)   BF_CS1(VDOA_VDOAVUBO, VUBO, v)
#endif

/*
 * HW_VDOA_VDOASR - VDOA Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CURRENT : 1;
        unsigned CURRENT : 2;
        unsigned EOB : 1;
        unsigned ERRW : 1;
        unsigned RESERVED0 : 27;

    } B;
} hw_vdoa_vdoasr_t;
#endif

/*
 * constants & macros for entire VDOA_VDOASR register
 */
#define HW_VDOA_VDOASR_ADDR      (REGS_VDOA_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOASR           (*(volatile hw_vdoa_vdoasr_t *) HW_VDOA_VDOASR_ADDR)
#define HW_VDOA_VDOASR_RD()      (HW_VDOA_VDOASR.U)
#define HW_VDOA_VDOASR_WR(v)     (HW_VDOA_VDOASR.U = (v))
#define HW_VDOA_VDOASR_SET(v)    (HW_VDOA_VDOASR_WR(HW_VDOA_VDOASR_RD() |  (v)))
#define HW_VDOA_VDOASR_CLR(v)    (HW_VDOA_VDOASR_WR(HW_VDOA_VDOASR_RD() & ~(v)))
#define HW_VDOA_VDOASR_TOG(v)    (HW_VDOA_VDOASR_WR(HW_VDOA_VDOASR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VDOA_VDOASR bitfields
 */

/* --- Register HW_VDOA_VDOASR, field CURRENT */

#define BP_VDOA_VDOASR_CURRENT      0
#define BM_VDOA_VDOASR_CURRENT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOASR_CURRENT(v)   ((((reg32_t) v) << 0) & BM_VDOA_VDOASR_CURRENT)
#else
#define BF_VDOA_VDOASR_CURRENT(v)   (((v) << 0) & BM_VDOA_VDOASR_CURRENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOASR_CURRENT(v)   BF_CS1(VDOA_VDOASR, CURRENT, v)
#endif

/* --- Register HW_VDOA_VDOASR, field CURRENT */

#define BP_VDOA_VDOASR_CURRENT      1
#define BM_VDOA_VDOASR_CURRENT      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOASR_CURRENT(v)   ((((reg32_t) v) << 1) & BM_VDOA_VDOASR_CURRENT)
#else
#define BF_VDOA_VDOASR_CURRENT(v)   (((v) << 1) & BM_VDOA_VDOASR_CURRENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOASR_CURRENT(v)   BF_CS1(VDOA_VDOASR, CURRENT, v)
#endif

/* --- Register HW_VDOA_VDOASR, field EOB */

#define BP_VDOA_VDOASR_EOB      3
#define BM_VDOA_VDOASR_EOB      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOASR_EOB(v)   ((((reg32_t) v) << 3) & BM_VDOA_VDOASR_EOB)
#else
#define BF_VDOA_VDOASR_EOB(v)   (((v) << 3) & BM_VDOA_VDOASR_EOB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOASR_EOB(v)   BF_CS1(VDOA_VDOASR, EOB, v)
#endif

/* --- Register HW_VDOA_VDOASR, field ERRW */

#define BP_VDOA_VDOASR_ERRW      4
#define BM_VDOA_VDOASR_ERRW      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_VDOA_VDOASR_ERRW(v)   ((((reg32_t) v) << 4) & BM_VDOA_VDOASR_ERRW)
#else
#define BF_VDOA_VDOASR_ERRW(v)   (((v) << 4) & BM_VDOA_VDOASR_ERRW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VDOA_VDOASR_ERRW(v)   BF_CS1(VDOA_VDOASR, ERRW, v)
#endif


#endif // _VDOA_H

