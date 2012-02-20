/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _EPIT_H
#define _EPIT_H

#include "regs.h"

#ifndef REGS_EPIT_BASE
#define REGS_EPIT0_BASE (REGS_BASE + 0x020d0000)
#define REGS_EPIT1_BASE (REGS_BASE + 0x020d4000)
#define REGS_EPIT_BASE(x) ( x == 0 ? REGS_EPIT0_BASE : x == 1 ? REGS_EPIT1_BASE : 0xffff0000)

#endif


/*
 * HW_EPIT_EPITCR - Control register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 6;
        unsigned CLKSRC : 2;
        unsigned OM : 2;
        unsigned STOPEN : 1;
        unsigned RESERVED1 : 1;
        unsigned DOZEN : 1;
        unsigned WAITEN : 1;
        unsigned DBGEN : 1;
        unsigned IOVW : 1;
        unsigned SWR : 1;
        unsigned PRESCALAR : 12;
        unsigned RLD : 1;
        unsigned OCIEN : 1;
        unsigned ENMOD : 1;
        unsigned EN : 1;

    } B;
} hw_epit_epitcr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCR register
 */
#define HW_EPIT_EPITCR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCR(x)           (*(volatile hw_epit_epitcr_t *) HW_EPIT_EPITCR_ADDR(x))
#define HW_EPIT_EPITCR_RD(x)        (HW_EPIT_EPITCR(x).U)
#define HW_EPIT_EPITCR_WR(x, v)     (HW_EPIT_EPITCR(x).U = (v))
#define HW_EPIT_EPITCR_SET(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) |  (v)))
#define HW_EPIT_EPITCR_CLR(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) & ~(v)))
#define HW_EPIT_EPITCR_TOG(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITCR bitfields
 */

/* --- Register HW_EPIT_EPITCR, field CLKSRC */

#define BP_EPIT_EPITCR_CLKSRC      24
#define BM_EPIT_EPITCR_CLKSRC      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_CLKSRC(v)   ((((reg32_t) v) << 24) & BM_EPIT_EPITCR_CLKSRC)
#else
#define BF_EPIT_EPITCR_CLKSRC(v)   (((v) << 24) & BM_EPIT_EPITCR_CLKSRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_CLKSRC(v)   BF_CS1(EPIT_EPITCR, CLKSRC, v)
#endif

/* --- Register HW_EPIT_EPITCR, field OM */

#define BP_EPIT_EPITCR_OM      22
#define BM_EPIT_EPITCR_OM      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_OM(v)   ((((reg32_t) v) << 22) & BM_EPIT_EPITCR_OM)
#else
#define BF_EPIT_EPITCR_OM(v)   (((v) << 22) & BM_EPIT_EPITCR_OM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_OM(v)   BF_CS1(EPIT_EPITCR, OM, v)
#endif

/* --- Register HW_EPIT_EPITCR, field STOPEN */

#define BP_EPIT_EPITCR_STOPEN      21
#define BM_EPIT_EPITCR_STOPEN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_STOPEN(v)   ((((reg32_t) v) << 21) & BM_EPIT_EPITCR_STOPEN)
#else
#define BF_EPIT_EPITCR_STOPEN(v)   (((v) << 21) & BM_EPIT_EPITCR_STOPEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_STOPEN(v)   BF_CS1(EPIT_EPITCR, STOPEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field DOZEN */

#define BP_EPIT_EPITCR_DOZEN      20
#define BM_EPIT_EPITCR_DOZEN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_DOZEN(v)   ((((reg32_t) v) << 20) & BM_EPIT_EPITCR_DOZEN)
#else
#define BF_EPIT_EPITCR_DOZEN(v)   (((v) << 20) & BM_EPIT_EPITCR_DOZEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_DOZEN(v)   BF_CS1(EPIT_EPITCR, DOZEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field WAITEN */

#define BP_EPIT_EPITCR_WAITEN      19
#define BM_EPIT_EPITCR_WAITEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_WAITEN(v)   ((((reg32_t) v) << 19) & BM_EPIT_EPITCR_WAITEN)
#else
#define BF_EPIT_EPITCR_WAITEN(v)   (((v) << 19) & BM_EPIT_EPITCR_WAITEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_WAITEN(v)   BF_CS1(EPIT_EPITCR, WAITEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field DBGEN */

#define BP_EPIT_EPITCR_DBGEN      18
#define BM_EPIT_EPITCR_DBGEN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_DBGEN(v)   ((((reg32_t) v) << 18) & BM_EPIT_EPITCR_DBGEN)
#else
#define BF_EPIT_EPITCR_DBGEN(v)   (((v) << 18) & BM_EPIT_EPITCR_DBGEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_DBGEN(v)   BF_CS1(EPIT_EPITCR, DBGEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field IOVW */

#define BP_EPIT_EPITCR_IOVW      17
#define BM_EPIT_EPITCR_IOVW      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_IOVW(v)   ((((reg32_t) v) << 17) & BM_EPIT_EPITCR_IOVW)
#else
#define BF_EPIT_EPITCR_IOVW(v)   (((v) << 17) & BM_EPIT_EPITCR_IOVW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_IOVW(v)   BF_CS1(EPIT_EPITCR, IOVW, v)
#endif

/* --- Register HW_EPIT_EPITCR, field SWR */

#define BP_EPIT_EPITCR_SWR      16
#define BM_EPIT_EPITCR_SWR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_SWR(v)   ((((reg32_t) v) << 16) & BM_EPIT_EPITCR_SWR)
#else
#define BF_EPIT_EPITCR_SWR(v)   (((v) << 16) & BM_EPIT_EPITCR_SWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_SWR(v)   BF_CS1(EPIT_EPITCR, SWR, v)
#endif

/* --- Register HW_EPIT_EPITCR, field PRESCALAR */

#define BP_EPIT_EPITCR_PRESCALAR      4
#define BM_EPIT_EPITCR_PRESCALAR      0x0000fff0

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_PRESCALAR(v)   ((((reg32_t) v) << 4) & BM_EPIT_EPITCR_PRESCALAR)
#else
#define BF_EPIT_EPITCR_PRESCALAR(v)   (((v) << 4) & BM_EPIT_EPITCR_PRESCALAR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_PRESCALAR(v)   BF_CS1(EPIT_EPITCR, PRESCALAR, v)
#endif

/* --- Register HW_EPIT_EPITCR, field RLD */

#define BP_EPIT_EPITCR_RLD      3
#define BM_EPIT_EPITCR_RLD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_RLD(v)   ((((reg32_t) v) << 3) & BM_EPIT_EPITCR_RLD)
#else
#define BF_EPIT_EPITCR_RLD(v)   (((v) << 3) & BM_EPIT_EPITCR_RLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_RLD(v)   BF_CS1(EPIT_EPITCR, RLD, v)
#endif

/* --- Register HW_EPIT_EPITCR, field OCIEN */

#define BP_EPIT_EPITCR_OCIEN      2
#define BM_EPIT_EPITCR_OCIEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_OCIEN(v)   ((((reg32_t) v) << 2) & BM_EPIT_EPITCR_OCIEN)
#else
#define BF_EPIT_EPITCR_OCIEN(v)   (((v) << 2) & BM_EPIT_EPITCR_OCIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_OCIEN(v)   BF_CS1(EPIT_EPITCR, OCIEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field ENMOD */

#define BP_EPIT_EPITCR_ENMOD      1
#define BM_EPIT_EPITCR_ENMOD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_ENMOD(v)   ((((reg32_t) v) << 1) & BM_EPIT_EPITCR_ENMOD)
#else
#define BF_EPIT_EPITCR_ENMOD(v)   (((v) << 1) & BM_EPIT_EPITCR_ENMOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_ENMOD(v)   BF_CS1(EPIT_EPITCR, ENMOD, v)
#endif

/* --- Register HW_EPIT_EPITCR, field EN */

#define BP_EPIT_EPITCR_EN      0
#define BM_EPIT_EPITCR_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_EN(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITCR_EN)
#else
#define BF_EPIT_EPITCR_EN(v)   (((v) << 0) & BM_EPIT_EPITCR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_EN(v)   BF_CS1(EPIT_EPITCR, EN, v)
#endif

/*
 * HW_EPIT_EPITSR - Status register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned OCIF : 1;

    } B;
} hw_epit_epitsr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITSR register
 */
#define HW_EPIT_EPITSR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITSR(x)           (*(volatile hw_epit_epitsr_t *) HW_EPIT_EPITSR_ADDR(x))
#define HW_EPIT_EPITSR_RD(x)        (HW_EPIT_EPITSR(x).U)
#define HW_EPIT_EPITSR_WR(x, v)     (HW_EPIT_EPITSR(x).U = (v))
#define HW_EPIT_EPITSR_SET(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) |  (v)))
#define HW_EPIT_EPITSR_CLR(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) & ~(v)))
#define HW_EPIT_EPITSR_TOG(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITSR bitfields
 */

/* --- Register HW_EPIT_EPITSR, field OCIF */

#define BP_EPIT_EPITSR_OCIF      0
#define BM_EPIT_EPITSR_OCIF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITSR_OCIF(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITSR_OCIF)
#else
#define BF_EPIT_EPITSR_OCIF(v)   (((v) << 0) & BM_EPIT_EPITSR_OCIF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITSR_OCIF(v)   BF_CS1(EPIT_EPITSR, OCIF, v)
#endif

/*
 * HW_EPIT_EPITLR - Load register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LOAD : 32;

    } B;
} hw_epit_epitlr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITLR register
 */
#define HW_EPIT_EPITLR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITLR(x)           (*(volatile hw_epit_epitlr_t *) HW_EPIT_EPITLR_ADDR(x))
#define HW_EPIT_EPITLR_RD(x)        (HW_EPIT_EPITLR(x).U)
#define HW_EPIT_EPITLR_WR(x, v)     (HW_EPIT_EPITLR(x).U = (v))
#define HW_EPIT_EPITLR_SET(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) |  (v)))
#define HW_EPIT_EPITLR_CLR(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) & ~(v)))
#define HW_EPIT_EPITLR_TOG(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITLR bitfields
 */

/* --- Register HW_EPIT_EPITLR, field LOAD */

#define BP_EPIT_EPITLR_LOAD      0
#define BM_EPIT_EPITLR_LOAD      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITLR_LOAD(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITLR_LOAD)
#else
#define BF_EPIT_EPITLR_LOAD(v)   (((v) << 0) & BM_EPIT_EPITLR_LOAD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITLR_LOAD(v)   BF_CS1(EPIT_EPITLR, LOAD, v)
#endif

/*
 * HW_EPIT_EPITCMPR - Compare register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COMPARE : 32;

    } B;
} hw_epit_epitcmpr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCMPR register
 */
#define HW_EPIT_EPITCMPR_ADDR(x)      (REGS_EPIT_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCMPR(x)           (*(volatile hw_epit_epitcmpr_t *) HW_EPIT_EPITCMPR_ADDR(x))
#define HW_EPIT_EPITCMPR_RD(x)        (HW_EPIT_EPITCMPR(x).U)
#define HW_EPIT_EPITCMPR_WR(x, v)     (HW_EPIT_EPITCMPR(x).U = (v))
#define HW_EPIT_EPITCMPR_SET(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) |  (v)))
#define HW_EPIT_EPITCMPR_CLR(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) & ~(v)))
#define HW_EPIT_EPITCMPR_TOG(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITCMPR bitfields
 */

/* --- Register HW_EPIT_EPITCMPR, field COMPARE */

#define BP_EPIT_EPITCMPR_COMPARE      0
#define BM_EPIT_EPITCMPR_COMPARE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCMPR_COMPARE(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITCMPR_COMPARE)
#else
#define BF_EPIT_EPITCMPR_COMPARE(v)   (((v) << 0) & BM_EPIT_EPITCMPR_COMPARE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCMPR_COMPARE(v)   BF_CS1(EPIT_EPITCMPR, COMPARE, v)
#endif

/*
 * HW_EPIT_EPITCNR - Counter register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32;

    } B;
} hw_epit_epitcnr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCNR register
 */
#define HW_EPIT_EPITCNR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCNR(x)           (*(volatile hw_epit_epitcnr_t *) HW_EPIT_EPITCNR_ADDR(x))
#define HW_EPIT_EPITCNR_RD(x)        (HW_EPIT_EPITCNR(x).U)
#define HW_EPIT_EPITCNR_WR(x, v)     (HW_EPIT_EPITCNR(x).U = (v))
#define HW_EPIT_EPITCNR_SET(x, v)    (HW_EPIT_EPITCNR_WR(x, HW_EPIT_EPITCNR_RD(x) |  (v)))
#define HW_EPIT_EPITCNR_CLR(x, v)    (HW_EPIT_EPITCNR_WR(x, HW_EPIT_EPITCNR_RD(x) & ~(v)))
#define HW_EPIT_EPITCNR_TOG(x, v)    (HW_EPIT_EPITCNR_WR(x, HW_EPIT_EPITCNR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITCNR bitfields
 */

/* --- Register HW_EPIT_EPITCNR, field COUNT */

#define BP_EPIT_EPITCNR_COUNT      0
#define BM_EPIT_EPITCNR_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCNR_COUNT(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITCNR_COUNT)
#else
#define BF_EPIT_EPITCNR_COUNT(v)   (((v) << 0) & BM_EPIT_EPITCNR_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCNR_COUNT(v)   BF_CS1(EPIT_EPITCNR, COUNT, v)
#endif


#endif // _EPIT_H

