/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _EIM_H
#define _EIM_H

#include "regs.h"

#ifndef REGS_EIM_BASE
#define REGS_EIM_BASE (REGS_BASE + 0x021b8000)

#endif


/*
 * HW_EIM_CSGCR1 - Chip Select n General Configuration Register
                        1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CSEN : 1;
        unsigned SWR : 1;
        unsigned SRD : 1;
        unsigned MUM : 1;
        unsigned WFL : 1;
        unsigned RFL : 1;
        unsigned CRE : 1;
        unsigned CREP : 1;
        unsigned BL : 3;
        unsigned WC : 1;
        unsigned BCD : 2;
        unsigned BCS : 2;
        unsigned DSZ : 3;
        unsigned SP : 1;
        unsigned CSREC : 3;
        unsigned AUS : 1;
        unsigned GBC : 3;
        unsigned WP : 1;
        unsigned PSZ : 4;

    } B;
} hw_eim_csgcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR1 register
 */
#define HW_EIM_CSGCR1_ADDR      (REGS_EIM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR1           (*(volatile hw_eim_csgcr1_t *) HW_EIM_CSGCR1_ADDR)
#define HW_EIM_CSGCR1_RD()      (HW_EIM_CSGCR1.U)
#define HW_EIM_CSGCR1_WR(v)     (HW_EIM_CSGCR1.U = (v))
#define HW_EIM_CSGCR1_SET(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() |  (v)))
#define HW_EIM_CSGCR1_CLR(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() & ~(v)))
#define HW_EIM_CSGCR1_TOG(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSGCR1 bitfields
 */

/* --- Register HW_EIM_CSGCR1, field CSEN */

#define BP_EIM_CSGCR1_CSEN      0
#define BM_EIM_CSGCR1_CSEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CSEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR1_CSEN)
#else
#define BF_EIM_CSGCR1_CSEN(v)   (((v) << 0) & BM_EIM_CSGCR1_CSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_CSEN(v)   BF_CS1(EIM_CSGCR1, CSEN, v)
#endif

/* --- Register HW_EIM_CSGCR1, field SWR */

#define BP_EIM_CSGCR1_SWR      1
#define BM_EIM_CSGCR1_SWR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SWR(v)   ((((reg32_t) v) << 1) & BM_EIM_CSGCR1_SWR)
#else
#define BF_EIM_CSGCR1_SWR(v)   (((v) << 1) & BM_EIM_CSGCR1_SWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_SWR(v)   BF_CS1(EIM_CSGCR1, SWR, v)
#endif

/* --- Register HW_EIM_CSGCR1, field SRD */

#define BP_EIM_CSGCR1_SRD      2
#define BM_EIM_CSGCR1_SRD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SRD(v)   ((((reg32_t) v) << 2) & BM_EIM_CSGCR1_SRD)
#else
#define BF_EIM_CSGCR1_SRD(v)   (((v) << 2) & BM_EIM_CSGCR1_SRD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_SRD(v)   BF_CS1(EIM_CSGCR1, SRD, v)
#endif

/* --- Register HW_EIM_CSGCR1, field MUM */

#define BP_EIM_CSGCR1_MUM      3
#define BM_EIM_CSGCR1_MUM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_MUM(v)   ((((reg32_t) v) << 3) & BM_EIM_CSGCR1_MUM)
#else
#define BF_EIM_CSGCR1_MUM(v)   (((v) << 3) & BM_EIM_CSGCR1_MUM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_MUM(v)   BF_CS1(EIM_CSGCR1, MUM, v)
#endif

/* --- Register HW_EIM_CSGCR1, field WFL */

#define BP_EIM_CSGCR1_WFL      4
#define BM_EIM_CSGCR1_WFL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WFL(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR1_WFL)
#else
#define BF_EIM_CSGCR1_WFL(v)   (((v) << 4) & BM_EIM_CSGCR1_WFL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_WFL(v)   BF_CS1(EIM_CSGCR1, WFL, v)
#endif

/* --- Register HW_EIM_CSGCR1, field RFL */

#define BP_EIM_CSGCR1_RFL      5
#define BM_EIM_CSGCR1_RFL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_RFL(v)   ((((reg32_t) v) << 5) & BM_EIM_CSGCR1_RFL)
#else
#define BF_EIM_CSGCR1_RFL(v)   (((v) << 5) & BM_EIM_CSGCR1_RFL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_RFL(v)   BF_CS1(EIM_CSGCR1, RFL, v)
#endif

/* --- Register HW_EIM_CSGCR1, field CRE */

#define BP_EIM_CSGCR1_CRE      6
#define BM_EIM_CSGCR1_CRE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CRE(v)   ((((reg32_t) v) << 6) & BM_EIM_CSGCR1_CRE)
#else
#define BF_EIM_CSGCR1_CRE(v)   (((v) << 6) & BM_EIM_CSGCR1_CRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_CRE(v)   BF_CS1(EIM_CSGCR1, CRE, v)
#endif

/* --- Register HW_EIM_CSGCR1, field CREP */

#define BP_EIM_CSGCR1_CREP      7
#define BM_EIM_CSGCR1_CREP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CREP(v)   ((((reg32_t) v) << 7) & BM_EIM_CSGCR1_CREP)
#else
#define BF_EIM_CSGCR1_CREP(v)   (((v) << 7) & BM_EIM_CSGCR1_CREP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_CREP(v)   BF_CS1(EIM_CSGCR1, CREP, v)
#endif

/* --- Register HW_EIM_CSGCR1, field BL */

#define BP_EIM_CSGCR1_BL      8
#define BM_EIM_CSGCR1_BL      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR1_BL)
#else
#define BF_EIM_CSGCR1_BL(v)   (((v) << 8) & BM_EIM_CSGCR1_BL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_BL(v)   BF_CS1(EIM_CSGCR1, BL, v)
#endif

/* --- Register HW_EIM_CSGCR1, field WC */

#define BP_EIM_CSGCR1_WC      11
#define BM_EIM_CSGCR1_WC      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WC(v)   ((((reg32_t) v) << 11) & BM_EIM_CSGCR1_WC)
#else
#define BF_EIM_CSGCR1_WC(v)   (((v) << 11) & BM_EIM_CSGCR1_WC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_WC(v)   BF_CS1(EIM_CSGCR1, WC, v)
#endif

/* --- Register HW_EIM_CSGCR1, field BCD */

#define BP_EIM_CSGCR1_BCD      12
#define BM_EIM_CSGCR1_BCD      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BCD(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR1_BCD)
#else
#define BF_EIM_CSGCR1_BCD(v)   (((v) << 12) & BM_EIM_CSGCR1_BCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_BCD(v)   BF_CS1(EIM_CSGCR1, BCD, v)
#endif

/* --- Register HW_EIM_CSGCR1, field BCS */

#define BP_EIM_CSGCR1_BCS      14
#define BM_EIM_CSGCR1_BCS      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BCS(v)   ((((reg32_t) v) << 14) & BM_EIM_CSGCR1_BCS)
#else
#define BF_EIM_CSGCR1_BCS(v)   (((v) << 14) & BM_EIM_CSGCR1_BCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_BCS(v)   BF_CS1(EIM_CSGCR1, BCS, v)
#endif

/* --- Register HW_EIM_CSGCR1, field DSZ */

#define BP_EIM_CSGCR1_DSZ      16
#define BM_EIM_CSGCR1_DSZ      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_DSZ(v)   ((((reg32_t) v) << 16) & BM_EIM_CSGCR1_DSZ)
#else
#define BF_EIM_CSGCR1_DSZ(v)   (((v) << 16) & BM_EIM_CSGCR1_DSZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_DSZ(v)   BF_CS1(EIM_CSGCR1, DSZ, v)
#endif

/* --- Register HW_EIM_CSGCR1, field SP */

#define BP_EIM_CSGCR1_SP      19
#define BM_EIM_CSGCR1_SP      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SP(v)   ((((reg32_t) v) << 19) & BM_EIM_CSGCR1_SP)
#else
#define BF_EIM_CSGCR1_SP(v)   (((v) << 19) & BM_EIM_CSGCR1_SP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_SP(v)   BF_CS1(EIM_CSGCR1, SP, v)
#endif

/* --- Register HW_EIM_CSGCR1, field CSREC */

#define BP_EIM_CSGCR1_CSREC      20
#define BM_EIM_CSGCR1_CSREC      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CSREC(v)   ((((reg32_t) v) << 20) & BM_EIM_CSGCR1_CSREC)
#else
#define BF_EIM_CSGCR1_CSREC(v)   (((v) << 20) & BM_EIM_CSGCR1_CSREC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_CSREC(v)   BF_CS1(EIM_CSGCR1, CSREC, v)
#endif

/* --- Register HW_EIM_CSGCR1, field AUS */

#define BP_EIM_CSGCR1_AUS      23
#define BM_EIM_CSGCR1_AUS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_AUS(v)   ((((reg32_t) v) << 23) & BM_EIM_CSGCR1_AUS)
#else
#define BF_EIM_CSGCR1_AUS(v)   (((v) << 23) & BM_EIM_CSGCR1_AUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_AUS(v)   BF_CS1(EIM_CSGCR1, AUS, v)
#endif

/* --- Register HW_EIM_CSGCR1, field GBC */

#define BP_EIM_CSGCR1_GBC      24
#define BM_EIM_CSGCR1_GBC      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_GBC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSGCR1_GBC)
#else
#define BF_EIM_CSGCR1_GBC(v)   (((v) << 24) & BM_EIM_CSGCR1_GBC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_GBC(v)   BF_CS1(EIM_CSGCR1, GBC, v)
#endif

/* --- Register HW_EIM_CSGCR1, field WP */

#define BP_EIM_CSGCR1_WP      27
#define BM_EIM_CSGCR1_WP      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WP(v)   ((((reg32_t) v) << 27) & BM_EIM_CSGCR1_WP)
#else
#define BF_EIM_CSGCR1_WP(v)   (((v) << 27) & BM_EIM_CSGCR1_WP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_WP(v)   BF_CS1(EIM_CSGCR1, WP, v)
#endif

/* --- Register HW_EIM_CSGCR1, field PSZ */

#define BP_EIM_CSGCR1_PSZ      28
#define BM_EIM_CSGCR1_PSZ      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_PSZ(v)   ((((reg32_t) v) << 28) & BM_EIM_CSGCR1_PSZ)
#else
#define BF_EIM_CSGCR1_PSZ(v)   (((v) << 28) & BM_EIM_CSGCR1_PSZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_PSZ(v)   BF_CS1(EIM_CSGCR1, PSZ, v)
#endif

/*
 * HW_EIM_CSGCR1 - Chip Select n General Configuration Register
                        1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CSEN : 1;
        unsigned SWR : 1;
        unsigned SRD : 1;
        unsigned MUM : 1;
        unsigned WFL : 1;
        unsigned RFL : 1;
        unsigned CRE : 1;
        unsigned CREP : 1;
        unsigned BL : 3;
        unsigned WC : 1;
        unsigned BCD : 2;
        unsigned BCS : 2;
        unsigned DSZ : 3;
        unsigned SP : 1;
        unsigned CSREC : 3;
        unsigned AUS : 1;
        unsigned GBC : 3;
        unsigned WP : 1;
        unsigned PSZ : 4;

    } B;
} hw_eim_csgcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR1 register
 */
#define HW_EIM_CSGCR1_ADDR      (REGS_EIM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR1           (*(volatile hw_eim_csgcr1_t *) HW_EIM_CSGCR1_ADDR)
#define HW_EIM_CSGCR1_RD()      (HW_EIM_CSGCR1.U)
#define HW_EIM_CSGCR1_WR(v)     (HW_EIM_CSGCR1.U = (v))
#define HW_EIM_CSGCR1_SET(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() |  (v)))
#define HW_EIM_CSGCR1_CLR(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() & ~(v)))
#define HW_EIM_CSGCR1_TOG(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSGCR1 bitfields
 */

/* --- Register HW_EIM_CSGCR1, field CSEN */

#define BP_EIM_CSGCR1_CSEN      0
#define BM_EIM_CSGCR1_CSEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CSEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR1_CSEN)
#else
#define BF_EIM_CSGCR1_CSEN(v)   (((v) << 0) & BM_EIM_CSGCR1_CSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_CSEN(v)   BF_CS1(EIM_CSGCR1, CSEN, v)
#endif

/* --- Register HW_EIM_CSGCR1, field SWR */

#define BP_EIM_CSGCR1_SWR      1
#define BM_EIM_CSGCR1_SWR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SWR(v)   ((((reg32_t) v) << 1) & BM_EIM_CSGCR1_SWR)
#else
#define BF_EIM_CSGCR1_SWR(v)   (((v) << 1) & BM_EIM_CSGCR1_SWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_SWR(v)   BF_CS1(EIM_CSGCR1, SWR, v)
#endif

/* --- Register HW_EIM_CSGCR1, field SRD */

#define BP_EIM_CSGCR1_SRD      2
#define BM_EIM_CSGCR1_SRD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SRD(v)   ((((reg32_t) v) << 2) & BM_EIM_CSGCR1_SRD)
#else
#define BF_EIM_CSGCR1_SRD(v)   (((v) << 2) & BM_EIM_CSGCR1_SRD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_SRD(v)   BF_CS1(EIM_CSGCR1, SRD, v)
#endif

/* --- Register HW_EIM_CSGCR1, field MUM */

#define BP_EIM_CSGCR1_MUM      3
#define BM_EIM_CSGCR1_MUM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_MUM(v)   ((((reg32_t) v) << 3) & BM_EIM_CSGCR1_MUM)
#else
#define BF_EIM_CSGCR1_MUM(v)   (((v) << 3) & BM_EIM_CSGCR1_MUM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_MUM(v)   BF_CS1(EIM_CSGCR1, MUM, v)
#endif

/* --- Register HW_EIM_CSGCR1, field WFL */

#define BP_EIM_CSGCR1_WFL      4
#define BM_EIM_CSGCR1_WFL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WFL(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR1_WFL)
#else
#define BF_EIM_CSGCR1_WFL(v)   (((v) << 4) & BM_EIM_CSGCR1_WFL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_WFL(v)   BF_CS1(EIM_CSGCR1, WFL, v)
#endif

/* --- Register HW_EIM_CSGCR1, field RFL */

#define BP_EIM_CSGCR1_RFL      5
#define BM_EIM_CSGCR1_RFL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_RFL(v)   ((((reg32_t) v) << 5) & BM_EIM_CSGCR1_RFL)
#else
#define BF_EIM_CSGCR1_RFL(v)   (((v) << 5) & BM_EIM_CSGCR1_RFL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_RFL(v)   BF_CS1(EIM_CSGCR1, RFL, v)
#endif

/* --- Register HW_EIM_CSGCR1, field CRE */

#define BP_EIM_CSGCR1_CRE      6
#define BM_EIM_CSGCR1_CRE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CRE(v)   ((((reg32_t) v) << 6) & BM_EIM_CSGCR1_CRE)
#else
#define BF_EIM_CSGCR1_CRE(v)   (((v) << 6) & BM_EIM_CSGCR1_CRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_CRE(v)   BF_CS1(EIM_CSGCR1, CRE, v)
#endif

/* --- Register HW_EIM_CSGCR1, field CREP */

#define BP_EIM_CSGCR1_CREP      7
#define BM_EIM_CSGCR1_CREP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CREP(v)   ((((reg32_t) v) << 7) & BM_EIM_CSGCR1_CREP)
#else
#define BF_EIM_CSGCR1_CREP(v)   (((v) << 7) & BM_EIM_CSGCR1_CREP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_CREP(v)   BF_CS1(EIM_CSGCR1, CREP, v)
#endif

/* --- Register HW_EIM_CSGCR1, field BL */

#define BP_EIM_CSGCR1_BL      8
#define BM_EIM_CSGCR1_BL      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR1_BL)
#else
#define BF_EIM_CSGCR1_BL(v)   (((v) << 8) & BM_EIM_CSGCR1_BL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_BL(v)   BF_CS1(EIM_CSGCR1, BL, v)
#endif

/* --- Register HW_EIM_CSGCR1, field WC */

#define BP_EIM_CSGCR1_WC      11
#define BM_EIM_CSGCR1_WC      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WC(v)   ((((reg32_t) v) << 11) & BM_EIM_CSGCR1_WC)
#else
#define BF_EIM_CSGCR1_WC(v)   (((v) << 11) & BM_EIM_CSGCR1_WC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_WC(v)   BF_CS1(EIM_CSGCR1, WC, v)
#endif

/* --- Register HW_EIM_CSGCR1, field BCD */

#define BP_EIM_CSGCR1_BCD      12
#define BM_EIM_CSGCR1_BCD      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BCD(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR1_BCD)
#else
#define BF_EIM_CSGCR1_BCD(v)   (((v) << 12) & BM_EIM_CSGCR1_BCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_BCD(v)   BF_CS1(EIM_CSGCR1, BCD, v)
#endif

/* --- Register HW_EIM_CSGCR1, field BCS */

#define BP_EIM_CSGCR1_BCS      14
#define BM_EIM_CSGCR1_BCS      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BCS(v)   ((((reg32_t) v) << 14) & BM_EIM_CSGCR1_BCS)
#else
#define BF_EIM_CSGCR1_BCS(v)   (((v) << 14) & BM_EIM_CSGCR1_BCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_BCS(v)   BF_CS1(EIM_CSGCR1, BCS, v)
#endif

/* --- Register HW_EIM_CSGCR1, field DSZ */

#define BP_EIM_CSGCR1_DSZ      16
#define BM_EIM_CSGCR1_DSZ      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_DSZ(v)   ((((reg32_t) v) << 16) & BM_EIM_CSGCR1_DSZ)
#else
#define BF_EIM_CSGCR1_DSZ(v)   (((v) << 16) & BM_EIM_CSGCR1_DSZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_DSZ(v)   BF_CS1(EIM_CSGCR1, DSZ, v)
#endif

/* --- Register HW_EIM_CSGCR1, field SP */

#define BP_EIM_CSGCR1_SP      19
#define BM_EIM_CSGCR1_SP      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SP(v)   ((((reg32_t) v) << 19) & BM_EIM_CSGCR1_SP)
#else
#define BF_EIM_CSGCR1_SP(v)   (((v) << 19) & BM_EIM_CSGCR1_SP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_SP(v)   BF_CS1(EIM_CSGCR1, SP, v)
#endif

/* --- Register HW_EIM_CSGCR1, field CSREC */

#define BP_EIM_CSGCR1_CSREC      20
#define BM_EIM_CSGCR1_CSREC      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CSREC(v)   ((((reg32_t) v) << 20) & BM_EIM_CSGCR1_CSREC)
#else
#define BF_EIM_CSGCR1_CSREC(v)   (((v) << 20) & BM_EIM_CSGCR1_CSREC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_CSREC(v)   BF_CS1(EIM_CSGCR1, CSREC, v)
#endif

/* --- Register HW_EIM_CSGCR1, field AUS */

#define BP_EIM_CSGCR1_AUS      23
#define BM_EIM_CSGCR1_AUS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_AUS(v)   ((((reg32_t) v) << 23) & BM_EIM_CSGCR1_AUS)
#else
#define BF_EIM_CSGCR1_AUS(v)   (((v) << 23) & BM_EIM_CSGCR1_AUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_AUS(v)   BF_CS1(EIM_CSGCR1, AUS, v)
#endif

/* --- Register HW_EIM_CSGCR1, field GBC */

#define BP_EIM_CSGCR1_GBC      24
#define BM_EIM_CSGCR1_GBC      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_GBC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSGCR1_GBC)
#else
#define BF_EIM_CSGCR1_GBC(v)   (((v) << 24) & BM_EIM_CSGCR1_GBC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_GBC(v)   BF_CS1(EIM_CSGCR1, GBC, v)
#endif

/* --- Register HW_EIM_CSGCR1, field WP */

#define BP_EIM_CSGCR1_WP      27
#define BM_EIM_CSGCR1_WP      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WP(v)   ((((reg32_t) v) << 27) & BM_EIM_CSGCR1_WP)
#else
#define BF_EIM_CSGCR1_WP(v)   (((v) << 27) & BM_EIM_CSGCR1_WP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_WP(v)   BF_CS1(EIM_CSGCR1, WP, v)
#endif

/* --- Register HW_EIM_CSGCR1, field PSZ */

#define BP_EIM_CSGCR1_PSZ      28
#define BM_EIM_CSGCR1_PSZ      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_PSZ(v)   ((((reg32_t) v) << 28) & BM_EIM_CSGCR1_PSZ)
#else
#define BF_EIM_CSGCR1_PSZ(v)   (((v) << 28) & BM_EIM_CSGCR1_PSZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR1_PSZ(v)   BF_CS1(EIM_CSGCR1, PSZ, v)
#endif

/*
 * HW_EIM_CSGCR2 - Chip Select n General Configuration Register
                        2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADH : 2;
        unsigned RESERVED0 : 2;
        unsigned DAPS : 4;
        unsigned DAE : 1;
        unsigned DAP : 1;
        unsigned RESERVED1 : 2;
        unsigned MUX16_BYP_GRANT : 1;
        unsigned RESERVED2 : 19;

    } B;
} hw_eim_csgcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR2 register
 */
#define HW_EIM_CSGCR2_ADDR      (REGS_EIM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR2           (*(volatile hw_eim_csgcr2_t *) HW_EIM_CSGCR2_ADDR)
#define HW_EIM_CSGCR2_RD()      (HW_EIM_CSGCR2.U)
#define HW_EIM_CSGCR2_WR(v)     (HW_EIM_CSGCR2.U = (v))
#define HW_EIM_CSGCR2_SET(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() |  (v)))
#define HW_EIM_CSGCR2_CLR(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() & ~(v)))
#define HW_EIM_CSGCR2_TOG(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSGCR2 bitfields
 */

/* --- Register HW_EIM_CSGCR2, field ADH */

#define BP_EIM_CSGCR2_ADH      0
#define BM_EIM_CSGCR2_ADH      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_ADH(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR2_ADH)
#else
#define BF_EIM_CSGCR2_ADH(v)   (((v) << 0) & BM_EIM_CSGCR2_ADH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_ADH(v)   BF_CS1(EIM_CSGCR2, ADH, v)
#endif

/* --- Register HW_EIM_CSGCR2, field DAPS */

#define BP_EIM_CSGCR2_DAPS      4
#define BM_EIM_CSGCR2_DAPS      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAPS(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR2_DAPS)
#else
#define BF_EIM_CSGCR2_DAPS(v)   (((v) << 4) & BM_EIM_CSGCR2_DAPS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_DAPS(v)   BF_CS1(EIM_CSGCR2, DAPS, v)
#endif

/* --- Register HW_EIM_CSGCR2, field DAE */

#define BP_EIM_CSGCR2_DAE      8
#define BM_EIM_CSGCR2_DAE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAE(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR2_DAE)
#else
#define BF_EIM_CSGCR2_DAE(v)   (((v) << 8) & BM_EIM_CSGCR2_DAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_DAE(v)   BF_CS1(EIM_CSGCR2, DAE, v)
#endif

/* --- Register HW_EIM_CSGCR2, field DAP */

#define BP_EIM_CSGCR2_DAP      9
#define BM_EIM_CSGCR2_DAP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAP(v)   ((((reg32_t) v) << 9) & BM_EIM_CSGCR2_DAP)
#else
#define BF_EIM_CSGCR2_DAP(v)   (((v) << 9) & BM_EIM_CSGCR2_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_DAP(v)   BF_CS1(EIM_CSGCR2, DAP, v)
#endif

/* --- Register HW_EIM_CSGCR2, field MUX16_BYP_GRANT */

#define BP_EIM_CSGCR2_MUX16_BYP_GRANT      12
#define BM_EIM_CSGCR2_MUX16_BYP_GRANT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_MUX16_BYP_GRANT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR2_MUX16_BYP_GRANT)
#else
#define BF_EIM_CSGCR2_MUX16_BYP_GRANT(v)   (((v) << 12) & BM_EIM_CSGCR2_MUX16_BYP_GRANT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_MUX16_BYP_GRANT(v)   BF_CS1(EIM_CSGCR2, MUX16_BYP_GRANT, v)
#endif

/*
 * HW_EIM_CSGCR2 - Chip Select n General Configuration Register
                        2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADH : 2;
        unsigned RESERVED0 : 2;
        unsigned DAPS : 4;
        unsigned DAE : 1;
        unsigned DAP : 1;
        unsigned RESERVED1 : 2;
        unsigned MUX16_BYP_GRANT : 1;
        unsigned RESERVED2 : 19;

    } B;
} hw_eim_csgcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR2 register
 */
#define HW_EIM_CSGCR2_ADDR      (REGS_EIM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR2           (*(volatile hw_eim_csgcr2_t *) HW_EIM_CSGCR2_ADDR)
#define HW_EIM_CSGCR2_RD()      (HW_EIM_CSGCR2.U)
#define HW_EIM_CSGCR2_WR(v)     (HW_EIM_CSGCR2.U = (v))
#define HW_EIM_CSGCR2_SET(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() |  (v)))
#define HW_EIM_CSGCR2_CLR(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() & ~(v)))
#define HW_EIM_CSGCR2_TOG(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSGCR2 bitfields
 */

/* --- Register HW_EIM_CSGCR2, field ADH */

#define BP_EIM_CSGCR2_ADH      0
#define BM_EIM_CSGCR2_ADH      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_ADH(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR2_ADH)
#else
#define BF_EIM_CSGCR2_ADH(v)   (((v) << 0) & BM_EIM_CSGCR2_ADH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_ADH(v)   BF_CS1(EIM_CSGCR2, ADH, v)
#endif

/* --- Register HW_EIM_CSGCR2, field DAPS */

#define BP_EIM_CSGCR2_DAPS      4
#define BM_EIM_CSGCR2_DAPS      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAPS(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR2_DAPS)
#else
#define BF_EIM_CSGCR2_DAPS(v)   (((v) << 4) & BM_EIM_CSGCR2_DAPS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_DAPS(v)   BF_CS1(EIM_CSGCR2, DAPS, v)
#endif

/* --- Register HW_EIM_CSGCR2, field DAE */

#define BP_EIM_CSGCR2_DAE      8
#define BM_EIM_CSGCR2_DAE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAE(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR2_DAE)
#else
#define BF_EIM_CSGCR2_DAE(v)   (((v) << 8) & BM_EIM_CSGCR2_DAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_DAE(v)   BF_CS1(EIM_CSGCR2, DAE, v)
#endif

/* --- Register HW_EIM_CSGCR2, field DAP */

#define BP_EIM_CSGCR2_DAP      9
#define BM_EIM_CSGCR2_DAP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAP(v)   ((((reg32_t) v) << 9) & BM_EIM_CSGCR2_DAP)
#else
#define BF_EIM_CSGCR2_DAP(v)   (((v) << 9) & BM_EIM_CSGCR2_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_DAP(v)   BF_CS1(EIM_CSGCR2, DAP, v)
#endif

/* --- Register HW_EIM_CSGCR2, field MUX16_BYP_GRANT */

#define BP_EIM_CSGCR2_MUX16_BYP_GRANT      12
#define BM_EIM_CSGCR2_MUX16_BYP_GRANT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_MUX16_BYP_GRANT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR2_MUX16_BYP_GRANT)
#else
#define BF_EIM_CSGCR2_MUX16_BYP_GRANT(v)   (((v) << 12) & BM_EIM_CSGCR2_MUX16_BYP_GRANT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSGCR2_MUX16_BYP_GRANT(v)   BF_CS1(EIM_CSGCR2, MUX16_BYP_GRANT, v)
#endif

/*
 * HW_EIM_CSRCR1 - Chip Select n Read Configuration Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RCSN : 3;
        unsigned RESERVED0 : 1;
        unsigned RCSA : 3;
        unsigned RESERVED1 : 1;
        unsigned OEN : 3;
        unsigned RESERVED2 : 1;
        unsigned OEA : 3;
        unsigned RESERVED3 : 1;
        unsigned RADVN : 3;
        unsigned RAL : 1;
        unsigned RADVA : 3;
        unsigned RESERVED4 : 1;
        unsigned RWSC : 6;
        unsigned RESERVED5 : 2;

    } B;
} hw_eim_csrcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR1 register
 */
#define HW_EIM_CSRCR1_ADDR      (REGS_EIM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR1           (*(volatile hw_eim_csrcr1_t *) HW_EIM_CSRCR1_ADDR)
#define HW_EIM_CSRCR1_RD()      (HW_EIM_CSRCR1.U)
#define HW_EIM_CSRCR1_WR(v)     (HW_EIM_CSRCR1.U = (v))
#define HW_EIM_CSRCR1_SET(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() |  (v)))
#define HW_EIM_CSRCR1_CLR(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() & ~(v)))
#define HW_EIM_CSRCR1_TOG(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSRCR1 bitfields
 */

/* --- Register HW_EIM_CSRCR1, field RCSN */

#define BP_EIM_CSRCR1_RCSN      0
#define BM_EIM_CSRCR1_RCSN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR1_RCSN)
#else
#define BF_EIM_CSRCR1_RCSN(v)   (((v) << 0) & BM_EIM_CSRCR1_RCSN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RCSN(v)   BF_CS1(EIM_CSRCR1, RCSN, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RCSA */

#define BP_EIM_CSRCR1_RCSA      4
#define BM_EIM_CSRCR1_RCSA      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RCSA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR1_RCSA)
#else
#define BF_EIM_CSRCR1_RCSA(v)   (((v) << 4) & BM_EIM_CSRCR1_RCSA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RCSA(v)   BF_CS1(EIM_CSRCR1, RCSA, v)
#endif

/* --- Register HW_EIM_CSRCR1, field OEN */

#define BP_EIM_CSRCR1_OEN      8
#define BM_EIM_CSRCR1_OEN      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_OEN(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR1_OEN)
#else
#define BF_EIM_CSRCR1_OEN(v)   (((v) << 8) & BM_EIM_CSRCR1_OEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_OEN(v)   BF_CS1(EIM_CSRCR1, OEN, v)
#endif

/* --- Register HW_EIM_CSRCR1, field OEA */

#define BP_EIM_CSRCR1_OEA      12
#define BM_EIM_CSRCR1_OEA      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_OEA(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR1_OEA)
#else
#define BF_EIM_CSRCR1_OEA(v)   (((v) << 12) & BM_EIM_CSRCR1_OEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_OEA(v)   BF_CS1(EIM_CSRCR1, OEA, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RADVN */

#define BP_EIM_CSRCR1_RADVN      16
#define BM_EIM_CSRCR1_RADVN      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RADVN(v)   ((((reg32_t) v) << 16) & BM_EIM_CSRCR1_RADVN)
#else
#define BF_EIM_CSRCR1_RADVN(v)   (((v) << 16) & BM_EIM_CSRCR1_RADVN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RADVN(v)   BF_CS1(EIM_CSRCR1, RADVN, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RAL */

#define BP_EIM_CSRCR1_RAL      19
#define BM_EIM_CSRCR1_RAL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RAL(v)   ((((reg32_t) v) << 19) & BM_EIM_CSRCR1_RAL)
#else
#define BF_EIM_CSRCR1_RAL(v)   (((v) << 19) & BM_EIM_CSRCR1_RAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RAL(v)   BF_CS1(EIM_CSRCR1, RAL, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RADVA */

#define BP_EIM_CSRCR1_RADVA      20
#define BM_EIM_CSRCR1_RADVA      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RADVA(v)   ((((reg32_t) v) << 20) & BM_EIM_CSRCR1_RADVA)
#else
#define BF_EIM_CSRCR1_RADVA(v)   (((v) << 20) & BM_EIM_CSRCR1_RADVA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RADVA(v)   BF_CS1(EIM_CSRCR1, RADVA, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RWSC */

#define BP_EIM_CSRCR1_RWSC      24
#define BM_EIM_CSRCR1_RWSC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSRCR1_RWSC)
#else
#define BF_EIM_CSRCR1_RWSC(v)   (((v) << 24) & BM_EIM_CSRCR1_RWSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RWSC(v)   BF_CS1(EIM_CSRCR1, RWSC, v)
#endif

/*
 * HW_EIM_CSRCR1 - Chip Select n Read Configuration Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RCSN : 3;
        unsigned RESERVED0 : 1;
        unsigned RCSA : 3;
        unsigned RESERVED1 : 1;
        unsigned OEN : 3;
        unsigned RESERVED2 : 1;
        unsigned OEA : 3;
        unsigned RESERVED3 : 1;
        unsigned RADVN : 3;
        unsigned RAL : 1;
        unsigned RADVA : 3;
        unsigned RESERVED4 : 1;
        unsigned RWSC : 6;
        unsigned RESERVED5 : 2;

    } B;
} hw_eim_csrcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR1 register
 */
#define HW_EIM_CSRCR1_ADDR      (REGS_EIM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR1           (*(volatile hw_eim_csrcr1_t *) HW_EIM_CSRCR1_ADDR)
#define HW_EIM_CSRCR1_RD()      (HW_EIM_CSRCR1.U)
#define HW_EIM_CSRCR1_WR(v)     (HW_EIM_CSRCR1.U = (v))
#define HW_EIM_CSRCR1_SET(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() |  (v)))
#define HW_EIM_CSRCR1_CLR(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() & ~(v)))
#define HW_EIM_CSRCR1_TOG(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSRCR1 bitfields
 */

/* --- Register HW_EIM_CSRCR1, field RCSN */

#define BP_EIM_CSRCR1_RCSN      0
#define BM_EIM_CSRCR1_RCSN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR1_RCSN)
#else
#define BF_EIM_CSRCR1_RCSN(v)   (((v) << 0) & BM_EIM_CSRCR1_RCSN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RCSN(v)   BF_CS1(EIM_CSRCR1, RCSN, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RCSA */

#define BP_EIM_CSRCR1_RCSA      4
#define BM_EIM_CSRCR1_RCSA      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RCSA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR1_RCSA)
#else
#define BF_EIM_CSRCR1_RCSA(v)   (((v) << 4) & BM_EIM_CSRCR1_RCSA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RCSA(v)   BF_CS1(EIM_CSRCR1, RCSA, v)
#endif

/* --- Register HW_EIM_CSRCR1, field OEN */

#define BP_EIM_CSRCR1_OEN      8
#define BM_EIM_CSRCR1_OEN      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_OEN(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR1_OEN)
#else
#define BF_EIM_CSRCR1_OEN(v)   (((v) << 8) & BM_EIM_CSRCR1_OEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_OEN(v)   BF_CS1(EIM_CSRCR1, OEN, v)
#endif

/* --- Register HW_EIM_CSRCR1, field OEA */

#define BP_EIM_CSRCR1_OEA      12
#define BM_EIM_CSRCR1_OEA      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_OEA(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR1_OEA)
#else
#define BF_EIM_CSRCR1_OEA(v)   (((v) << 12) & BM_EIM_CSRCR1_OEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_OEA(v)   BF_CS1(EIM_CSRCR1, OEA, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RADVN */

#define BP_EIM_CSRCR1_RADVN      16
#define BM_EIM_CSRCR1_RADVN      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RADVN(v)   ((((reg32_t) v) << 16) & BM_EIM_CSRCR1_RADVN)
#else
#define BF_EIM_CSRCR1_RADVN(v)   (((v) << 16) & BM_EIM_CSRCR1_RADVN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RADVN(v)   BF_CS1(EIM_CSRCR1, RADVN, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RAL */

#define BP_EIM_CSRCR1_RAL      19
#define BM_EIM_CSRCR1_RAL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RAL(v)   ((((reg32_t) v) << 19) & BM_EIM_CSRCR1_RAL)
#else
#define BF_EIM_CSRCR1_RAL(v)   (((v) << 19) & BM_EIM_CSRCR1_RAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RAL(v)   BF_CS1(EIM_CSRCR1, RAL, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RADVA */

#define BP_EIM_CSRCR1_RADVA      20
#define BM_EIM_CSRCR1_RADVA      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RADVA(v)   ((((reg32_t) v) << 20) & BM_EIM_CSRCR1_RADVA)
#else
#define BF_EIM_CSRCR1_RADVA(v)   (((v) << 20) & BM_EIM_CSRCR1_RADVA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RADVA(v)   BF_CS1(EIM_CSRCR1, RADVA, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RWSC */

#define BP_EIM_CSRCR1_RWSC      24
#define BM_EIM_CSRCR1_RWSC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSRCR1_RWSC)
#else
#define BF_EIM_CSRCR1_RWSC(v)   (((v) << 24) & BM_EIM_CSRCR1_RWSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR1_RWSC(v)   BF_CS1(EIM_CSRCR1, RWSC, v)
#endif

/*
 * HW_EIM_CSRCR2 - Chip Select n Read Configuration Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RBEN : 3;
        unsigned RBE : 1;
        unsigned RBEA : 3;
        unsigned RESERVED0 : 1;
        unsigned RL : 2;
        unsigned RESERVED1 : 2;
        unsigned PAT : 3;
        unsigned APR : 1;
        unsigned RESERVED2 : 16;

    } B;
} hw_eim_csrcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR2 register
 */
#define HW_EIM_CSRCR2_ADDR      (REGS_EIM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR2           (*(volatile hw_eim_csrcr2_t *) HW_EIM_CSRCR2_ADDR)
#define HW_EIM_CSRCR2_RD()      (HW_EIM_CSRCR2.U)
#define HW_EIM_CSRCR2_WR(v)     (HW_EIM_CSRCR2.U = (v))
#define HW_EIM_CSRCR2_SET(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() |  (v)))
#define HW_EIM_CSRCR2_CLR(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() & ~(v)))
#define HW_EIM_CSRCR2_TOG(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSRCR2 bitfields
 */

/* --- Register HW_EIM_CSRCR2, field RBEN */

#define BP_EIM_CSRCR2_RBEN      0
#define BM_EIM_CSRCR2_RBEN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR2_RBEN)
#else
#define BF_EIM_CSRCR2_RBEN(v)   (((v) << 0) & BM_EIM_CSRCR2_RBEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_RBEN(v)   BF_CS1(EIM_CSRCR2, RBEN, v)
#endif

/* --- Register HW_EIM_CSRCR2, field RBE */

#define BP_EIM_CSRCR2_RBE      3
#define BM_EIM_CSRCR2_RBE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBE(v)   ((((reg32_t) v) << 3) & BM_EIM_CSRCR2_RBE)
#else
#define BF_EIM_CSRCR2_RBE(v)   (((v) << 3) & BM_EIM_CSRCR2_RBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_RBE(v)   BF_CS1(EIM_CSRCR2, RBE, v)
#endif

/* --- Register HW_EIM_CSRCR2, field RBEA */

#define BP_EIM_CSRCR2_RBEA      4
#define BM_EIM_CSRCR2_RBEA      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBEA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR2_RBEA)
#else
#define BF_EIM_CSRCR2_RBEA(v)   (((v) << 4) & BM_EIM_CSRCR2_RBEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_RBEA(v)   BF_CS1(EIM_CSRCR2, RBEA, v)
#endif

/* --- Register HW_EIM_CSRCR2, field RL */

#define BP_EIM_CSRCR2_RL      8
#define BM_EIM_CSRCR2_RL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR2_RL)
#else
#define BF_EIM_CSRCR2_RL(v)   (((v) << 8) & BM_EIM_CSRCR2_RL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_RL(v)   BF_CS1(EIM_CSRCR2, RL, v)
#endif

/* --- Register HW_EIM_CSRCR2, field PAT */

#define BP_EIM_CSRCR2_PAT      12
#define BM_EIM_CSRCR2_PAT      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_PAT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR2_PAT)
#else
#define BF_EIM_CSRCR2_PAT(v)   (((v) << 12) & BM_EIM_CSRCR2_PAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_PAT(v)   BF_CS1(EIM_CSRCR2, PAT, v)
#endif

/* --- Register HW_EIM_CSRCR2, field APR */

#define BP_EIM_CSRCR2_APR      15
#define BM_EIM_CSRCR2_APR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_APR(v)   ((((reg32_t) v) << 15) & BM_EIM_CSRCR2_APR)
#else
#define BF_EIM_CSRCR2_APR(v)   (((v) << 15) & BM_EIM_CSRCR2_APR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_APR(v)   BF_CS1(EIM_CSRCR2, APR, v)
#endif

/*
 * HW_EIM_CSRCR2 - Chip Select n Read Configuration Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RBEN : 3;
        unsigned RBE : 1;
        unsigned RBEA : 3;
        unsigned RESERVED0 : 1;
        unsigned RL : 2;
        unsigned RESERVED1 : 2;
        unsigned PAT : 3;
        unsigned APR : 1;
        unsigned RESERVED2 : 16;

    } B;
} hw_eim_csrcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR2 register
 */
#define HW_EIM_CSRCR2_ADDR      (REGS_EIM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR2           (*(volatile hw_eim_csrcr2_t *) HW_EIM_CSRCR2_ADDR)
#define HW_EIM_CSRCR2_RD()      (HW_EIM_CSRCR2.U)
#define HW_EIM_CSRCR2_WR(v)     (HW_EIM_CSRCR2.U = (v))
#define HW_EIM_CSRCR2_SET(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() |  (v)))
#define HW_EIM_CSRCR2_CLR(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() & ~(v)))
#define HW_EIM_CSRCR2_TOG(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSRCR2 bitfields
 */

/* --- Register HW_EIM_CSRCR2, field RBEN */

#define BP_EIM_CSRCR2_RBEN      0
#define BM_EIM_CSRCR2_RBEN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR2_RBEN)
#else
#define BF_EIM_CSRCR2_RBEN(v)   (((v) << 0) & BM_EIM_CSRCR2_RBEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_RBEN(v)   BF_CS1(EIM_CSRCR2, RBEN, v)
#endif

/* --- Register HW_EIM_CSRCR2, field RBE */

#define BP_EIM_CSRCR2_RBE      3
#define BM_EIM_CSRCR2_RBE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBE(v)   ((((reg32_t) v) << 3) & BM_EIM_CSRCR2_RBE)
#else
#define BF_EIM_CSRCR2_RBE(v)   (((v) << 3) & BM_EIM_CSRCR2_RBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_RBE(v)   BF_CS1(EIM_CSRCR2, RBE, v)
#endif

/* --- Register HW_EIM_CSRCR2, field RBEA */

#define BP_EIM_CSRCR2_RBEA      4
#define BM_EIM_CSRCR2_RBEA      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBEA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR2_RBEA)
#else
#define BF_EIM_CSRCR2_RBEA(v)   (((v) << 4) & BM_EIM_CSRCR2_RBEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_RBEA(v)   BF_CS1(EIM_CSRCR2, RBEA, v)
#endif

/* --- Register HW_EIM_CSRCR2, field RL */

#define BP_EIM_CSRCR2_RL      8
#define BM_EIM_CSRCR2_RL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR2_RL)
#else
#define BF_EIM_CSRCR2_RL(v)   (((v) << 8) & BM_EIM_CSRCR2_RL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_RL(v)   BF_CS1(EIM_CSRCR2, RL, v)
#endif

/* --- Register HW_EIM_CSRCR2, field PAT */

#define BP_EIM_CSRCR2_PAT      12
#define BM_EIM_CSRCR2_PAT      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_PAT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR2_PAT)
#else
#define BF_EIM_CSRCR2_PAT(v)   (((v) << 12) & BM_EIM_CSRCR2_PAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_PAT(v)   BF_CS1(EIM_CSRCR2, PAT, v)
#endif

/* --- Register HW_EIM_CSRCR2, field APR */

#define BP_EIM_CSRCR2_APR      15
#define BM_EIM_CSRCR2_APR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_APR(v)   ((((reg32_t) v) << 15) & BM_EIM_CSRCR2_APR)
#else
#define BF_EIM_CSRCR2_APR(v)   (((v) << 15) & BM_EIM_CSRCR2_APR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSRCR2_APR(v)   BF_CS1(EIM_CSRCR2, APR, v)
#endif

/*
 * HW_EIM_CSWCR1 - Chip Select n Write Configuration Register
                        1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WCSN : 3;
        unsigned WCSA : 3;
        unsigned WEN : 3;
        unsigned WEA : 3;
        unsigned WBEN : 3;
        unsigned WBEA : 3;
        unsigned WADVN : 3;
        unsigned WADVA : 3;
        unsigned WWSC : 6;
        unsigned WBED : 1;
        unsigned WAL : 1;

    } B;
} hw_eim_cswcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR1 register
 */
#define HW_EIM_CSWCR1_ADDR      (REGS_EIM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR1           (*(volatile hw_eim_cswcr1_t *) HW_EIM_CSWCR1_ADDR)
#define HW_EIM_CSWCR1_RD()      (HW_EIM_CSWCR1.U)
#define HW_EIM_CSWCR1_WR(v)     (HW_EIM_CSWCR1.U = (v))
#define HW_EIM_CSWCR1_SET(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() |  (v)))
#define HW_EIM_CSWCR1_CLR(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() & ~(v)))
#define HW_EIM_CSWCR1_TOG(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSWCR1 bitfields
 */

/* --- Register HW_EIM_CSWCR1, field WCSN */

#define BP_EIM_CSWCR1_WCSN      0
#define BM_EIM_CSWCR1_WCSN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR1_WCSN)
#else
#define BF_EIM_CSWCR1_WCSN(v)   (((v) << 0) & BM_EIM_CSWCR1_WCSN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WCSN(v)   BF_CS1(EIM_CSWCR1, WCSN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WCSA */

#define BP_EIM_CSWCR1_WCSA      3
#define BM_EIM_CSWCR1_WCSA      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WCSA(v)   ((((reg32_t) v) << 3) & BM_EIM_CSWCR1_WCSA)
#else
#define BF_EIM_CSWCR1_WCSA(v)   (((v) << 3) & BM_EIM_CSWCR1_WCSA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WCSA(v)   BF_CS1(EIM_CSWCR1, WCSA, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WEN */

#define BP_EIM_CSWCR1_WEN      6
#define BM_EIM_CSWCR1_WEN      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WEN(v)   ((((reg32_t) v) << 6) & BM_EIM_CSWCR1_WEN)
#else
#define BF_EIM_CSWCR1_WEN(v)   (((v) << 6) & BM_EIM_CSWCR1_WEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WEN(v)   BF_CS1(EIM_CSWCR1, WEN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WEA */

#define BP_EIM_CSWCR1_WEA      9
#define BM_EIM_CSWCR1_WEA      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WEA(v)   ((((reg32_t) v) << 9) & BM_EIM_CSWCR1_WEA)
#else
#define BF_EIM_CSWCR1_WEA(v)   (((v) << 9) & BM_EIM_CSWCR1_WEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WEA(v)   BF_CS1(EIM_CSWCR1, WEA, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WBEN */

#define BP_EIM_CSWCR1_WBEN      12
#define BM_EIM_CSWCR1_WBEN      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBEN(v)   ((((reg32_t) v) << 12) & BM_EIM_CSWCR1_WBEN)
#else
#define BF_EIM_CSWCR1_WBEN(v)   (((v) << 12) & BM_EIM_CSWCR1_WBEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WBEN(v)   BF_CS1(EIM_CSWCR1, WBEN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WBEA */

#define BP_EIM_CSWCR1_WBEA      15
#define BM_EIM_CSWCR1_WBEA      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBEA(v)   ((((reg32_t) v) << 15) & BM_EIM_CSWCR1_WBEA)
#else
#define BF_EIM_CSWCR1_WBEA(v)   (((v) << 15) & BM_EIM_CSWCR1_WBEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WBEA(v)   BF_CS1(EIM_CSWCR1, WBEA, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WADVN */

#define BP_EIM_CSWCR1_WADVN      18
#define BM_EIM_CSWCR1_WADVN      0x001c0000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WADVN(v)   ((((reg32_t) v) << 18) & BM_EIM_CSWCR1_WADVN)
#else
#define BF_EIM_CSWCR1_WADVN(v)   (((v) << 18) & BM_EIM_CSWCR1_WADVN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WADVN(v)   BF_CS1(EIM_CSWCR1, WADVN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WADVA */

#define BP_EIM_CSWCR1_WADVA      21
#define BM_EIM_CSWCR1_WADVA      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WADVA(v)   ((((reg32_t) v) << 21) & BM_EIM_CSWCR1_WADVA)
#else
#define BF_EIM_CSWCR1_WADVA(v)   (((v) << 21) & BM_EIM_CSWCR1_WADVA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WADVA(v)   BF_CS1(EIM_CSWCR1, WADVA, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WWSC */

#define BP_EIM_CSWCR1_WWSC      24
#define BM_EIM_CSWCR1_WWSC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSWCR1_WWSC)
#else
#define BF_EIM_CSWCR1_WWSC(v)   (((v) << 24) & BM_EIM_CSWCR1_WWSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WWSC(v)   BF_CS1(EIM_CSWCR1, WWSC, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WBED */

#define BP_EIM_CSWCR1_WBED      30
#define BM_EIM_CSWCR1_WBED      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBED(v)   ((((reg32_t) v) << 30) & BM_EIM_CSWCR1_WBED)
#else
#define BF_EIM_CSWCR1_WBED(v)   (((v) << 30) & BM_EIM_CSWCR1_WBED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WBED(v)   BF_CS1(EIM_CSWCR1, WBED, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WAL */

#define BP_EIM_CSWCR1_WAL      31
#define BM_EIM_CSWCR1_WAL      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WAL(v)   ((((reg32_t) v) << 31) & BM_EIM_CSWCR1_WAL)
#else
#define BF_EIM_CSWCR1_WAL(v)   (((v) << 31) & BM_EIM_CSWCR1_WAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WAL(v)   BF_CS1(EIM_CSWCR1, WAL, v)
#endif

/*
 * HW_EIM_CSWCR1 - Chip Select n Write Configuration Register
                        1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WCSN : 3;
        unsigned WCSA : 3;
        unsigned WEN : 3;
        unsigned WEA : 3;
        unsigned WBEN : 3;
        unsigned WBEA : 3;
        unsigned WADVN : 3;
        unsigned WADVA : 3;
        unsigned WWSC : 6;
        unsigned WBED : 1;
        unsigned WAL : 1;

    } B;
} hw_eim_cswcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR1 register
 */
#define HW_EIM_CSWCR1_ADDR      (REGS_EIM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR1           (*(volatile hw_eim_cswcr1_t *) HW_EIM_CSWCR1_ADDR)
#define HW_EIM_CSWCR1_RD()      (HW_EIM_CSWCR1.U)
#define HW_EIM_CSWCR1_WR(v)     (HW_EIM_CSWCR1.U = (v))
#define HW_EIM_CSWCR1_SET(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() |  (v)))
#define HW_EIM_CSWCR1_CLR(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() & ~(v)))
#define HW_EIM_CSWCR1_TOG(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSWCR1 bitfields
 */

/* --- Register HW_EIM_CSWCR1, field WCSN */

#define BP_EIM_CSWCR1_WCSN      0
#define BM_EIM_CSWCR1_WCSN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR1_WCSN)
#else
#define BF_EIM_CSWCR1_WCSN(v)   (((v) << 0) & BM_EIM_CSWCR1_WCSN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WCSN(v)   BF_CS1(EIM_CSWCR1, WCSN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WCSA */

#define BP_EIM_CSWCR1_WCSA      3
#define BM_EIM_CSWCR1_WCSA      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WCSA(v)   ((((reg32_t) v) << 3) & BM_EIM_CSWCR1_WCSA)
#else
#define BF_EIM_CSWCR1_WCSA(v)   (((v) << 3) & BM_EIM_CSWCR1_WCSA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WCSA(v)   BF_CS1(EIM_CSWCR1, WCSA, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WEN */

#define BP_EIM_CSWCR1_WEN      6
#define BM_EIM_CSWCR1_WEN      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WEN(v)   ((((reg32_t) v) << 6) & BM_EIM_CSWCR1_WEN)
#else
#define BF_EIM_CSWCR1_WEN(v)   (((v) << 6) & BM_EIM_CSWCR1_WEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WEN(v)   BF_CS1(EIM_CSWCR1, WEN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WEA */

#define BP_EIM_CSWCR1_WEA      9
#define BM_EIM_CSWCR1_WEA      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WEA(v)   ((((reg32_t) v) << 9) & BM_EIM_CSWCR1_WEA)
#else
#define BF_EIM_CSWCR1_WEA(v)   (((v) << 9) & BM_EIM_CSWCR1_WEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WEA(v)   BF_CS1(EIM_CSWCR1, WEA, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WBEN */

#define BP_EIM_CSWCR1_WBEN      12
#define BM_EIM_CSWCR1_WBEN      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBEN(v)   ((((reg32_t) v) << 12) & BM_EIM_CSWCR1_WBEN)
#else
#define BF_EIM_CSWCR1_WBEN(v)   (((v) << 12) & BM_EIM_CSWCR1_WBEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WBEN(v)   BF_CS1(EIM_CSWCR1, WBEN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WBEA */

#define BP_EIM_CSWCR1_WBEA      15
#define BM_EIM_CSWCR1_WBEA      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBEA(v)   ((((reg32_t) v) << 15) & BM_EIM_CSWCR1_WBEA)
#else
#define BF_EIM_CSWCR1_WBEA(v)   (((v) << 15) & BM_EIM_CSWCR1_WBEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WBEA(v)   BF_CS1(EIM_CSWCR1, WBEA, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WADVN */

#define BP_EIM_CSWCR1_WADVN      18
#define BM_EIM_CSWCR1_WADVN      0x001c0000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WADVN(v)   ((((reg32_t) v) << 18) & BM_EIM_CSWCR1_WADVN)
#else
#define BF_EIM_CSWCR1_WADVN(v)   (((v) << 18) & BM_EIM_CSWCR1_WADVN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WADVN(v)   BF_CS1(EIM_CSWCR1, WADVN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WADVA */

#define BP_EIM_CSWCR1_WADVA      21
#define BM_EIM_CSWCR1_WADVA      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WADVA(v)   ((((reg32_t) v) << 21) & BM_EIM_CSWCR1_WADVA)
#else
#define BF_EIM_CSWCR1_WADVA(v)   (((v) << 21) & BM_EIM_CSWCR1_WADVA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WADVA(v)   BF_CS1(EIM_CSWCR1, WADVA, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WWSC */

#define BP_EIM_CSWCR1_WWSC      24
#define BM_EIM_CSWCR1_WWSC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSWCR1_WWSC)
#else
#define BF_EIM_CSWCR1_WWSC(v)   (((v) << 24) & BM_EIM_CSWCR1_WWSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WWSC(v)   BF_CS1(EIM_CSWCR1, WWSC, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WBED */

#define BP_EIM_CSWCR1_WBED      30
#define BM_EIM_CSWCR1_WBED      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBED(v)   ((((reg32_t) v) << 30) & BM_EIM_CSWCR1_WBED)
#else
#define BF_EIM_CSWCR1_WBED(v)   (((v) << 30) & BM_EIM_CSWCR1_WBED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WBED(v)   BF_CS1(EIM_CSWCR1, WBED, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WAL */

#define BP_EIM_CSWCR1_WAL      31
#define BM_EIM_CSWCR1_WAL      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WAL(v)   ((((reg32_t) v) << 31) & BM_EIM_CSWCR1_WAL)
#else
#define BF_EIM_CSWCR1_WAL(v)   (((v) << 31) & BM_EIM_CSWCR1_WAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR1_WAL(v)   BF_CS1(EIM_CSWCR1, WAL, v)
#endif

/*
 * HW_EIM_CSWCR2 - Chip Select n Write Configuration Register
                        2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WBCDD : 1;
        unsigned RESERVED0 : 31;

    } B;
} hw_eim_cswcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR2 register
 */
#define HW_EIM_CSWCR2_ADDR      (REGS_EIM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR2           (*(volatile hw_eim_cswcr2_t *) HW_EIM_CSWCR2_ADDR)
#define HW_EIM_CSWCR2_RD()      (HW_EIM_CSWCR2.U)
#define HW_EIM_CSWCR2_WR(v)     (HW_EIM_CSWCR2.U = (v))
#define HW_EIM_CSWCR2_SET(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() |  (v)))
#define HW_EIM_CSWCR2_CLR(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() & ~(v)))
#define HW_EIM_CSWCR2_TOG(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSWCR2 bitfields
 */

/* --- Register HW_EIM_CSWCR2, field WBCDD */

#define BP_EIM_CSWCR2_WBCDD      0
#define BM_EIM_CSWCR2_WBCDD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR2_WBCDD(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR2_WBCDD)
#else
#define BF_EIM_CSWCR2_WBCDD(v)   (((v) << 0) & BM_EIM_CSWCR2_WBCDD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR2_WBCDD(v)   BF_CS1(EIM_CSWCR2, WBCDD, v)
#endif

/*
 * HW_EIM_CSWCR2 - Chip Select n Write Configuration Register
                        2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WBCDD : 1;
        unsigned RESERVED0 : 31;

    } B;
} hw_eim_cswcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR2 register
 */
#define HW_EIM_CSWCR2_ADDR      (REGS_EIM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR2           (*(volatile hw_eim_cswcr2_t *) HW_EIM_CSWCR2_ADDR)
#define HW_EIM_CSWCR2_RD()      (HW_EIM_CSWCR2.U)
#define HW_EIM_CSWCR2_WR(v)     (HW_EIM_CSWCR2.U = (v))
#define HW_EIM_CSWCR2_SET(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() |  (v)))
#define HW_EIM_CSWCR2_CLR(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() & ~(v)))
#define HW_EIM_CSWCR2_TOG(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_CSWCR2 bitfields
 */

/* --- Register HW_EIM_CSWCR2, field WBCDD */

#define BP_EIM_CSWCR2_WBCDD      0
#define BM_EIM_CSWCR2_WBCDD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR2_WBCDD(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR2_WBCDD)
#else
#define BF_EIM_CSWCR2_WBCDD(v)   (((v) << 0) & BM_EIM_CSWCR2_WBCDD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_CSWCR2_WBCDD(v)   BF_CS1(EIM_CSWCR2, WBCDD, v)
#endif

/*
 * HW_EIM_WCR - EIM Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BCM : 1;
        unsigned GBCD : 2;
        unsigned RESERVED0 : 1;
        unsigned INTEN : 1;
        unsigned INTPOL : 1;
        unsigned RESERVED1 : 2;
        unsigned WDOG_EN : 1;
        unsigned WDOG_LIMIT : 2;
        unsigned RESERVED2 : 21;

    } B;
} hw_eim_wcr_t;
#endif

/*
 * constants & macros for entire EIM_WCR register
 */
#define HW_EIM_WCR_ADDR      (REGS_EIM_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_WCR           (*(volatile hw_eim_wcr_t *) HW_EIM_WCR_ADDR)
#define HW_EIM_WCR_RD()      (HW_EIM_WCR.U)
#define HW_EIM_WCR_WR(v)     (HW_EIM_WCR.U = (v))
#define HW_EIM_WCR_SET(v)    (HW_EIM_WCR_WR(HW_EIM_WCR_RD() |  (v)))
#define HW_EIM_WCR_CLR(v)    (HW_EIM_WCR_WR(HW_EIM_WCR_RD() & ~(v)))
#define HW_EIM_WCR_TOG(v)    (HW_EIM_WCR_WR(HW_EIM_WCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_WCR bitfields
 */

/* --- Register HW_EIM_WCR, field BCM */

#define BP_EIM_WCR_BCM      0
#define BM_EIM_WCR_BCM      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_BCM(v)   ((((reg32_t) v) << 0) & BM_EIM_WCR_BCM)
#else
#define BF_EIM_WCR_BCM(v)   (((v) << 0) & BM_EIM_WCR_BCM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_BCM(v)   BF_CS1(EIM_WCR, BCM, v)
#endif

/* --- Register HW_EIM_WCR, field GBCD */

#define BP_EIM_WCR_GBCD      1
#define BM_EIM_WCR_GBCD      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_GBCD(v)   ((((reg32_t) v) << 1) & BM_EIM_WCR_GBCD)
#else
#define BF_EIM_WCR_GBCD(v)   (((v) << 1) & BM_EIM_WCR_GBCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_GBCD(v)   BF_CS1(EIM_WCR, GBCD, v)
#endif

/* --- Register HW_EIM_WCR, field INTEN */

#define BP_EIM_WCR_INTEN      4
#define BM_EIM_WCR_INTEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_INTEN(v)   ((((reg32_t) v) << 4) & BM_EIM_WCR_INTEN)
#else
#define BF_EIM_WCR_INTEN(v)   (((v) << 4) & BM_EIM_WCR_INTEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_INTEN(v)   BF_CS1(EIM_WCR, INTEN, v)
#endif

/* --- Register HW_EIM_WCR, field INTPOL */

#define BP_EIM_WCR_INTPOL      5
#define BM_EIM_WCR_INTPOL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_INTPOL(v)   ((((reg32_t) v) << 5) & BM_EIM_WCR_INTPOL)
#else
#define BF_EIM_WCR_INTPOL(v)   (((v) << 5) & BM_EIM_WCR_INTPOL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_INTPOL(v)   BF_CS1(EIM_WCR, INTPOL, v)
#endif

/* --- Register HW_EIM_WCR, field WDOG_EN */

#define BP_EIM_WCR_WDOG_EN      8
#define BM_EIM_WCR_WDOG_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_WDOG_EN(v)   ((((reg32_t) v) << 8) & BM_EIM_WCR_WDOG_EN)
#else
#define BF_EIM_WCR_WDOG_EN(v)   (((v) << 8) & BM_EIM_WCR_WDOG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_WDOG_EN(v)   BF_CS1(EIM_WCR, WDOG_EN, v)
#endif

/* --- Register HW_EIM_WCR, field WDOG_LIMIT */

#define BP_EIM_WCR_WDOG_LIMIT      9
#define BM_EIM_WCR_WDOG_LIMIT      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_WDOG_LIMIT(v)   ((((reg32_t) v) << 9) & BM_EIM_WCR_WDOG_LIMIT)
#else
#define BF_EIM_WCR_WDOG_LIMIT(v)   (((v) << 9) & BM_EIM_WCR_WDOG_LIMIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_WDOG_LIMIT(v)   BF_CS1(EIM_WCR, WDOG_LIMIT, v)
#endif

/*
 * HW_EIM_WIAR - EIM IP Access Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPS_REQ : 1;
        unsigned IPS_ACK : 1;
        unsigned INT : 1;
        unsigned ERRST : 1;
        unsigned ACLK_EN : 1;
        unsigned RESERVED0 : 27;

    } B;
} hw_eim_wiar_t;
#endif

/*
 * constants & macros for entire EIM_WIAR register
 */
#define HW_EIM_WIAR_ADDR      (REGS_EIM_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_WIAR           (*(volatile hw_eim_wiar_t *) HW_EIM_WIAR_ADDR)
#define HW_EIM_WIAR_RD()      (HW_EIM_WIAR.U)
#define HW_EIM_WIAR_WR(v)     (HW_EIM_WIAR.U = (v))
#define HW_EIM_WIAR_SET(v)    (HW_EIM_WIAR_WR(HW_EIM_WIAR_RD() |  (v)))
#define HW_EIM_WIAR_CLR(v)    (HW_EIM_WIAR_WR(HW_EIM_WIAR_RD() & ~(v)))
#define HW_EIM_WIAR_TOG(v)    (HW_EIM_WIAR_WR(HW_EIM_WIAR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_WIAR bitfields
 */

/* --- Register HW_EIM_WIAR, field IPS_REQ */

#define BP_EIM_WIAR_IPS_REQ      0
#define BM_EIM_WIAR_IPS_REQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_IPS_REQ(v)   ((((reg32_t) v) << 0) & BM_EIM_WIAR_IPS_REQ)
#else
#define BF_EIM_WIAR_IPS_REQ(v)   (((v) << 0) & BM_EIM_WIAR_IPS_REQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_IPS_REQ(v)   BF_CS1(EIM_WIAR, IPS_REQ, v)
#endif

/* --- Register HW_EIM_WIAR, field IPS_ACK */

#define BP_EIM_WIAR_IPS_ACK      1
#define BM_EIM_WIAR_IPS_ACK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_IPS_ACK(v)   ((((reg32_t) v) << 1) & BM_EIM_WIAR_IPS_ACK)
#else
#define BF_EIM_WIAR_IPS_ACK(v)   (((v) << 1) & BM_EIM_WIAR_IPS_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_IPS_ACK(v)   BF_CS1(EIM_WIAR, IPS_ACK, v)
#endif

/* --- Register HW_EIM_WIAR, field INT */

#define BP_EIM_WIAR_INT      2
#define BM_EIM_WIAR_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_INT(v)   ((((reg32_t) v) << 2) & BM_EIM_WIAR_INT)
#else
#define BF_EIM_WIAR_INT(v)   (((v) << 2) & BM_EIM_WIAR_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_INT(v)   BF_CS1(EIM_WIAR, INT, v)
#endif

/* --- Register HW_EIM_WIAR, field ERRST */

#define BP_EIM_WIAR_ERRST      3
#define BM_EIM_WIAR_ERRST      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_ERRST(v)   ((((reg32_t) v) << 3) & BM_EIM_WIAR_ERRST)
#else
#define BF_EIM_WIAR_ERRST(v)   (((v) << 3) & BM_EIM_WIAR_ERRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_ERRST(v)   BF_CS1(EIM_WIAR, ERRST, v)
#endif

/* --- Register HW_EIM_WIAR, field ACLK_EN */

#define BP_EIM_WIAR_ACLK_EN      4
#define BM_EIM_WIAR_ACLK_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_ACLK_EN(v)   ((((reg32_t) v) << 4) & BM_EIM_WIAR_ACLK_EN)
#else
#define BF_EIM_WIAR_ACLK_EN(v)   (((v) << 4) & BM_EIM_WIAR_ACLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_ACLK_EN(v)   BF_CS1(EIM_WIAR, ACLK_EN, v)
#endif

/*
 * HW_EIM_EAR - Error Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ERROR : 32;

    } B;
} hw_eim_ear_t;
#endif

/*
 * constants & macros for entire EIM_EAR register
 */
#define HW_EIM_EAR_ADDR      (REGS_EIM_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_EAR           (*(volatile hw_eim_ear_t *) HW_EIM_EAR_ADDR)
#define HW_EIM_EAR_RD()      (HW_EIM_EAR.U)
#define HW_EIM_EAR_WR(v)     (HW_EIM_EAR.U = (v))
#define HW_EIM_EAR_SET(v)    (HW_EIM_EAR_WR(HW_EIM_EAR_RD() |  (v)))
#define HW_EIM_EAR_CLR(v)    (HW_EIM_EAR_WR(HW_EIM_EAR_RD() & ~(v)))
#define HW_EIM_EAR_TOG(v)    (HW_EIM_EAR_WR(HW_EIM_EAR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual EIM_EAR bitfields
 */

/* --- Register HW_EIM_EAR, field ERROR */

#define BP_EIM_EAR_ERROR      0
#define BM_EIM_EAR_ERROR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EIM_EAR_ERROR(v)   ((((reg32_t) v) << 0) & BM_EIM_EAR_ERROR)
#else
#define BF_EIM_EAR_ERROR(v)   (((v) << 0) & BM_EIM_EAR_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_EAR_ERROR(v)   BF_CS1(EIM_EAR, ERROR, v)
#endif


#endif // _EIM_H

