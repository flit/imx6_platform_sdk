/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SDMACORE_H
#define _SDMACORE_H

#include "regs.h"

#ifndef REGS_SDMACORE_BASE
#define REGS_SDMACORE_BASE (REGS_BASE + 0x020ec000)

#endif


/*
 * HW_SDMACORE_MC0PTR - ARM platform Channel 0 Pointer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MC0PTR : 32;

    } B;
} hw_sdmacore_mc0ptr_t;
#endif

/*
 * constants & macros for entire SDMACORE_MC0PTR register
 */
#define HW_SDMACORE_MC0PTR_ADDR      (REGS_SDMACORE_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_MC0PTR           (*(volatile hw_sdmacore_mc0ptr_t *) HW_SDMACORE_MC0PTR_ADDR)
#define HW_SDMACORE_MC0PTR_RD()      (HW_SDMACORE_MC0PTR.U)
#define HW_SDMACORE_MC0PTR_WR(v)     (HW_SDMACORE_MC0PTR.U = (v))
#define HW_SDMACORE_MC0PTR_SET(v)    (HW_SDMACORE_MC0PTR_WR(HW_SDMACORE_MC0PTR_RD() |  (v)))
#define HW_SDMACORE_MC0PTR_CLR(v)    (HW_SDMACORE_MC0PTR_WR(HW_SDMACORE_MC0PTR_RD() & ~(v)))
#define HW_SDMACORE_MC0PTR_TOG(v)    (HW_SDMACORE_MC0PTR_WR(HW_SDMACORE_MC0PTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_MC0PTR bitfields
 */

/* --- Register HW_SDMACORE_MC0PTR, field MC0PTR */

#define BP_SDMACORE_MC0PTR_MC0PTR      0
#define BM_SDMACORE_MC0PTR_MC0PTR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MC0PTR_MC0PTR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_MC0PTR_MC0PTR)
#else
#define BF_SDMACORE_MC0PTR_MC0PTR(v)   (((v) << 0) & BM_SDMACORE_MC0PTR_MC0PTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MC0PTR_MC0PTR(v)   BF_CS1(SDMACORE_MC0PTR, MC0PTR, v)
#endif

/*
 * HW_SDMACORE_DC0PTR - DSP Channel 0 Pointer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DC0PTR : 32;

    } B;
} hw_sdmacore_dc0ptr_t;
#endif

/*
 * constants & macros for entire SDMACORE_DC0PTR register
 */
#define HW_SDMACORE_DC0PTR_ADDR      (REGS_SDMACORE_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_DC0PTR           (*(volatile hw_sdmacore_dc0ptr_t *) HW_SDMACORE_DC0PTR_ADDR)
#define HW_SDMACORE_DC0PTR_RD()      (HW_SDMACORE_DC0PTR.U)
#define HW_SDMACORE_DC0PTR_WR(v)     (HW_SDMACORE_DC0PTR.U = (v))
#define HW_SDMACORE_DC0PTR_SET(v)    (HW_SDMACORE_DC0PTR_WR(HW_SDMACORE_DC0PTR_RD() |  (v)))
#define HW_SDMACORE_DC0PTR_CLR(v)    (HW_SDMACORE_DC0PTR_WR(HW_SDMACORE_DC0PTR_RD() & ~(v)))
#define HW_SDMACORE_DC0PTR_TOG(v)    (HW_SDMACORE_DC0PTR_WR(HW_SDMACORE_DC0PTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_DC0PTR bitfields
 */

/* --- Register HW_SDMACORE_DC0PTR, field DC0PTR */

#define BP_SDMACORE_DC0PTR_DC0PTR      0
#define BM_SDMACORE_DC0PTR_DC0PTR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_DC0PTR_DC0PTR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_DC0PTR_DC0PTR)
#else
#define BF_SDMACORE_DC0PTR_DC0PTR(v)   (((v) << 0) & BM_SDMACORE_DC0PTR_DC0PTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_DC0PTR_DC0PTR(v)   BF_CS1(SDMACORE_DC0PTR, DC0PTR, v)
#endif

/*
 * HW_SDMACORE_CCPTR - Current Channel Pointer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCPTR : 16;
        unsigned RESERVED0 : 16;

    } B;
} hw_sdmacore_ccptr_t;
#endif

/*
 * constants & macros for entire SDMACORE_CCPTR register
 */
#define HW_SDMACORE_CCPTR_ADDR      (REGS_SDMACORE_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_CCPTR           (*(volatile hw_sdmacore_ccptr_t *) HW_SDMACORE_CCPTR_ADDR)
#define HW_SDMACORE_CCPTR_RD()      (HW_SDMACORE_CCPTR.U)
#define HW_SDMACORE_CCPTR_WR(v)     (HW_SDMACORE_CCPTR.U = (v))
#define HW_SDMACORE_CCPTR_SET(v)    (HW_SDMACORE_CCPTR_WR(HW_SDMACORE_CCPTR_RD() |  (v)))
#define HW_SDMACORE_CCPTR_CLR(v)    (HW_SDMACORE_CCPTR_WR(HW_SDMACORE_CCPTR_RD() & ~(v)))
#define HW_SDMACORE_CCPTR_TOG(v)    (HW_SDMACORE_CCPTR_WR(HW_SDMACORE_CCPTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_CCPTR bitfields
 */

/* --- Register HW_SDMACORE_CCPTR, field CCPTR */

#define BP_SDMACORE_CCPTR_CCPTR      0
#define BM_SDMACORE_CCPTR_CCPTR      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_CCPTR_CCPTR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_CCPTR_CCPTR)
#else
#define BF_SDMACORE_CCPTR_CCPTR(v)   (((v) << 0) & BM_SDMACORE_CCPTR_CCPTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_CCPTR_CCPTR(v)   BF_CS1(SDMACORE_CCPTR, CCPTR, v)
#endif

/*
 * HW_SDMACORE_CCR - Current Channel Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCR : 5;
        unsigned RESERVED0 : 27;

    } B;
} hw_sdmacore_ccr_t;
#endif

/*
 * constants & macros for entire SDMACORE_CCR register
 */
#define HW_SDMACORE_CCR_ADDR      (REGS_SDMACORE_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_CCR           (*(volatile hw_sdmacore_ccr_t *) HW_SDMACORE_CCR_ADDR)
#define HW_SDMACORE_CCR_RD()      (HW_SDMACORE_CCR.U)
#define HW_SDMACORE_CCR_WR(v)     (HW_SDMACORE_CCR.U = (v))
#define HW_SDMACORE_CCR_SET(v)    (HW_SDMACORE_CCR_WR(HW_SDMACORE_CCR_RD() |  (v)))
#define HW_SDMACORE_CCR_CLR(v)    (HW_SDMACORE_CCR_WR(HW_SDMACORE_CCR_RD() & ~(v)))
#define HW_SDMACORE_CCR_TOG(v)    (HW_SDMACORE_CCR_WR(HW_SDMACORE_CCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_CCR bitfields
 */

/* --- Register HW_SDMACORE_CCR, field CCR */

#define BP_SDMACORE_CCR_CCR      0
#define BM_SDMACORE_CCR_CCR      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_CCR_CCR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_CCR_CCR)
#else
#define BF_SDMACORE_CCR_CCR(v)   (((v) << 0) & BM_SDMACORE_CCR_CCR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_CCR_CCR(v)   BF_CS1(SDMACORE_CCR, CCR, v)
#endif

/*
 * HW_SDMACORE_NCR - Highest Pending Channel Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NCR : 5;
        unsigned RESERVED0 : 27;

    } B;
} hw_sdmacore_ncr_t;
#endif

/*
 * constants & macros for entire SDMACORE_NCR register
 */
#define HW_SDMACORE_NCR_ADDR      (REGS_SDMACORE_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_NCR           (*(volatile hw_sdmacore_ncr_t *) HW_SDMACORE_NCR_ADDR)
#define HW_SDMACORE_NCR_RD()      (HW_SDMACORE_NCR.U)
#define HW_SDMACORE_NCR_WR(v)     (HW_SDMACORE_NCR.U = (v))
#define HW_SDMACORE_NCR_SET(v)    (HW_SDMACORE_NCR_WR(HW_SDMACORE_NCR_RD() |  (v)))
#define HW_SDMACORE_NCR_CLR(v)    (HW_SDMACORE_NCR_WR(HW_SDMACORE_NCR_RD() & ~(v)))
#define HW_SDMACORE_NCR_TOG(v)    (HW_SDMACORE_NCR_WR(HW_SDMACORE_NCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_NCR bitfields
 */

/* --- Register HW_SDMACORE_NCR, field NCR */

#define BP_SDMACORE_NCR_NCR      0
#define BM_SDMACORE_NCR_NCR      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_NCR_NCR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_NCR_NCR)
#else
#define BF_SDMACORE_NCR_NCR(v)   (((v) << 0) & BM_SDMACORE_NCR_NCR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_NCR_NCR(v)   BF_CS1(SDMACORE_NCR, NCR, v)
#endif

/*
 * HW_SDMACORE_EVENTS - External DMA Requests Mirror
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EVENTS : 32;

    } B;
} hw_sdmacore_events_t;
#endif

/*
 * constants & macros for entire SDMACORE_EVENTS register
 */
#define HW_SDMACORE_EVENTS_ADDR      (REGS_SDMACORE_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EVENTS           (*(volatile hw_sdmacore_events_t *) HW_SDMACORE_EVENTS_ADDR)
#define HW_SDMACORE_EVENTS_RD()      (HW_SDMACORE_EVENTS.U)
#define HW_SDMACORE_EVENTS_WR(v)     (HW_SDMACORE_EVENTS.U = (v))
#define HW_SDMACORE_EVENTS_SET(v)    (HW_SDMACORE_EVENTS_WR(HW_SDMACORE_EVENTS_RD() |  (v)))
#define HW_SDMACORE_EVENTS_CLR(v)    (HW_SDMACORE_EVENTS_WR(HW_SDMACORE_EVENTS_RD() & ~(v)))
#define HW_SDMACORE_EVENTS_TOG(v)    (HW_SDMACORE_EVENTS_WR(HW_SDMACORE_EVENTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EVENTS bitfields
 */

/* --- Register HW_SDMACORE_EVENTS, field EVENTS */

#define BP_SDMACORE_EVENTS_EVENTS      0
#define BM_SDMACORE_EVENTS_EVENTS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EVENTS_EVENTS(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EVENTS_EVENTS)
#else
#define BF_SDMACORE_EVENTS_EVENTS(v)   (((v) << 0) & BM_SDMACORE_EVENTS_EVENTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EVENTS_EVENTS(v)   BF_CS1(SDMACORE_EVENTS, EVENTS, v)
#endif

/*
 * HW_SDMACORE_CCPRI - Current Channel Priority
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCPRI : 3;
        unsigned RESERVED0 : 29;

    } B;
} hw_sdmacore_ccpri_t;
#endif

/*
 * constants & macros for entire SDMACORE_CCPRI register
 */
#define HW_SDMACORE_CCPRI_ADDR      (REGS_SDMACORE_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_CCPRI           (*(volatile hw_sdmacore_ccpri_t *) HW_SDMACORE_CCPRI_ADDR)
#define HW_SDMACORE_CCPRI_RD()      (HW_SDMACORE_CCPRI.U)
#define HW_SDMACORE_CCPRI_WR(v)     (HW_SDMACORE_CCPRI.U = (v))
#define HW_SDMACORE_CCPRI_SET(v)    (HW_SDMACORE_CCPRI_WR(HW_SDMACORE_CCPRI_RD() |  (v)))
#define HW_SDMACORE_CCPRI_CLR(v)    (HW_SDMACORE_CCPRI_WR(HW_SDMACORE_CCPRI_RD() & ~(v)))
#define HW_SDMACORE_CCPRI_TOG(v)    (HW_SDMACORE_CCPRI_WR(HW_SDMACORE_CCPRI_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_CCPRI bitfields
 */

/* --- Register HW_SDMACORE_CCPRI, field CCPRI */

#define BP_SDMACORE_CCPRI_CCPRI      0
#define BM_SDMACORE_CCPRI_CCPRI      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_CCPRI_CCPRI(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_CCPRI_CCPRI)
#else
#define BF_SDMACORE_CCPRI_CCPRI(v)   (((v) << 0) & BM_SDMACORE_CCPRI_CCPRI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_CCPRI_CCPRI(v)   BF_CS1(SDMACORE_CCPRI, CCPRI, v)
#endif

/*
 * HW_SDMACORE_NCPRI - Next Channel Priority
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NCPRI : 3;
        unsigned RESERVED0 : 29;

    } B;
} hw_sdmacore_ncpri_t;
#endif

/*
 * constants & macros for entire SDMACORE_NCPRI register
 */
#define HW_SDMACORE_NCPRI_ADDR      (REGS_SDMACORE_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_NCPRI           (*(volatile hw_sdmacore_ncpri_t *) HW_SDMACORE_NCPRI_ADDR)
#define HW_SDMACORE_NCPRI_RD()      (HW_SDMACORE_NCPRI.U)
#define HW_SDMACORE_NCPRI_WR(v)     (HW_SDMACORE_NCPRI.U = (v))
#define HW_SDMACORE_NCPRI_SET(v)    (HW_SDMACORE_NCPRI_WR(HW_SDMACORE_NCPRI_RD() |  (v)))
#define HW_SDMACORE_NCPRI_CLR(v)    (HW_SDMACORE_NCPRI_WR(HW_SDMACORE_NCPRI_RD() & ~(v)))
#define HW_SDMACORE_NCPRI_TOG(v)    (HW_SDMACORE_NCPRI_WR(HW_SDMACORE_NCPRI_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_NCPRI bitfields
 */

/* --- Register HW_SDMACORE_NCPRI, field NCPRI */

#define BP_SDMACORE_NCPRI_NCPRI      0
#define BM_SDMACORE_NCPRI_NCPRI      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_NCPRI_NCPRI(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_NCPRI_NCPRI)
#else
#define BF_SDMACORE_NCPRI_NCPRI(v)   (((v) << 0) & BM_SDMACORE_NCPRI_NCPRI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_NCPRI_NCPRI(v)   BF_CS1(SDMACORE_NCPRI, NCPRI, v)
#endif

/*
 * HW_SDMACORE_ECOUNT - OnCE Event Cell Counter
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ECOUNT : 16;
        unsigned RESERVED0 : 16;

    } B;
} hw_sdmacore_ecount_t;
#endif

/*
 * constants & macros for entire SDMACORE_ECOUNT register
 */
#define HW_SDMACORE_ECOUNT_ADDR      (REGS_SDMACORE_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_ECOUNT           (*(volatile hw_sdmacore_ecount_t *) HW_SDMACORE_ECOUNT_ADDR)
#define HW_SDMACORE_ECOUNT_RD()      (HW_SDMACORE_ECOUNT.U)
#define HW_SDMACORE_ECOUNT_WR(v)     (HW_SDMACORE_ECOUNT.U = (v))
#define HW_SDMACORE_ECOUNT_SET(v)    (HW_SDMACORE_ECOUNT_WR(HW_SDMACORE_ECOUNT_RD() |  (v)))
#define HW_SDMACORE_ECOUNT_CLR(v)    (HW_SDMACORE_ECOUNT_WR(HW_SDMACORE_ECOUNT_RD() & ~(v)))
#define HW_SDMACORE_ECOUNT_TOG(v)    (HW_SDMACORE_ECOUNT_WR(HW_SDMACORE_ECOUNT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_ECOUNT bitfields
 */

/* --- Register HW_SDMACORE_ECOUNT, field ECOUNT */

#define BP_SDMACORE_ECOUNT_ECOUNT      0
#define BM_SDMACORE_ECOUNT_ECOUNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECOUNT_ECOUNT(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_ECOUNT_ECOUNT)
#else
#define BF_SDMACORE_ECOUNT_ECOUNT(v)   (((v) << 0) & BM_SDMACORE_ECOUNT_ECOUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECOUNT_ECOUNT(v)   BF_CS1(SDMACORE_ECOUNT, ECOUNT, v)
#endif

/*
 * HW_SDMACORE_ECTL - OnCE Event Cell Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ATS : 2;
        unsigned AATC : 2;
        unsigned ABTC : 2;
        unsigned ATC : 2;
        unsigned DTC : 2;
        unsigned ECTC : 2;
        unsigned CNT : 1;
        unsigned EN : 1;
        unsigned RESERVED0 : 18;

    } B;
} hw_sdmacore_ectl_t;
#endif

/*
 * constants & macros for entire SDMACORE_ECTL register
 */
#define HW_SDMACORE_ECTL_ADDR      (REGS_SDMACORE_BASE + 0xa)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_ECTL           (*(volatile hw_sdmacore_ectl_t *) HW_SDMACORE_ECTL_ADDR)
#define HW_SDMACORE_ECTL_RD()      (HW_SDMACORE_ECTL.U)
#define HW_SDMACORE_ECTL_WR(v)     (HW_SDMACORE_ECTL.U = (v))
#define HW_SDMACORE_ECTL_SET(v)    (HW_SDMACORE_ECTL_WR(HW_SDMACORE_ECTL_RD() |  (v)))
#define HW_SDMACORE_ECTL_CLR(v)    (HW_SDMACORE_ECTL_WR(HW_SDMACORE_ECTL_RD() & ~(v)))
#define HW_SDMACORE_ECTL_TOG(v)    (HW_SDMACORE_ECTL_WR(HW_SDMACORE_ECTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_ECTL bitfields
 */

/* --- Register HW_SDMACORE_ECTL, field ATS */

#define BP_SDMACORE_ECTL_ATS      0
#define BM_SDMACORE_ECTL_ATS      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_ATS(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_ECTL_ATS)
#else
#define BF_SDMACORE_ECTL_ATS(v)   (((v) << 0) & BM_SDMACORE_ECTL_ATS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_ATS(v)   BF_CS1(SDMACORE_ECTL, ATS, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field AATC */

#define BP_SDMACORE_ECTL_AATC      2
#define BM_SDMACORE_ECTL_AATC      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_AATC(v)   ((((reg32_t) v) << 2) & BM_SDMACORE_ECTL_AATC)
#else
#define BF_SDMACORE_ECTL_AATC(v)   (((v) << 2) & BM_SDMACORE_ECTL_AATC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_AATC(v)   BF_CS1(SDMACORE_ECTL, AATC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field ABTC */

#define BP_SDMACORE_ECTL_ABTC      4
#define BM_SDMACORE_ECTL_ABTC      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_ABTC(v)   ((((reg32_t) v) << 4) & BM_SDMACORE_ECTL_ABTC)
#else
#define BF_SDMACORE_ECTL_ABTC(v)   (((v) << 4) & BM_SDMACORE_ECTL_ABTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_ABTC(v)   BF_CS1(SDMACORE_ECTL, ABTC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field ATC */

#define BP_SDMACORE_ECTL_ATC      6
#define BM_SDMACORE_ECTL_ATC      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_ATC(v)   ((((reg32_t) v) << 6) & BM_SDMACORE_ECTL_ATC)
#else
#define BF_SDMACORE_ECTL_ATC(v)   (((v) << 6) & BM_SDMACORE_ECTL_ATC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_ATC(v)   BF_CS1(SDMACORE_ECTL, ATC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field DTC */

#define BP_SDMACORE_ECTL_DTC      8
#define BM_SDMACORE_ECTL_DTC      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_DTC(v)   ((((reg32_t) v) << 8) & BM_SDMACORE_ECTL_DTC)
#else
#define BF_SDMACORE_ECTL_DTC(v)   (((v) << 8) & BM_SDMACORE_ECTL_DTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_DTC(v)   BF_CS1(SDMACORE_ECTL, DTC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field ECTC */

#define BP_SDMACORE_ECTL_ECTC      10
#define BM_SDMACORE_ECTL_ECTC      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_ECTC(v)   ((((reg32_t) v) << 10) & BM_SDMACORE_ECTL_ECTC)
#else
#define BF_SDMACORE_ECTL_ECTC(v)   (((v) << 10) & BM_SDMACORE_ECTL_ECTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_ECTC(v)   BF_CS1(SDMACORE_ECTL, ECTC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field CNT */

#define BP_SDMACORE_ECTL_CNT      12
#define BM_SDMACORE_ECTL_CNT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_CNT(v)   ((((reg32_t) v) << 12) & BM_SDMACORE_ECTL_CNT)
#else
#define BF_SDMACORE_ECTL_CNT(v)   (((v) << 12) & BM_SDMACORE_ECTL_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_CNT(v)   BF_CS1(SDMACORE_ECTL, CNT, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field EN */

#define BP_SDMACORE_ECTL_EN      13
#define BM_SDMACORE_ECTL_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_EN(v)   ((((reg32_t) v) << 13) & BM_SDMACORE_ECTL_EN)
#else
#define BF_SDMACORE_ECTL_EN(v)   (((v) << 13) & BM_SDMACORE_ECTL_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_EN(v)   BF_CS1(SDMACORE_ECTL, EN, v)
#endif

/*
 * HW_SDMACORE_EAA - OnCE Event Address Register A
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EAA : 16;
        unsigned RESERVED0 : 16;

    } B;
} hw_sdmacore_eaa_t;
#endif

/*
 * constants & macros for entire SDMACORE_EAA register
 */
#define HW_SDMACORE_EAA_ADDR      (REGS_SDMACORE_BASE + 0xb)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EAA           (*(volatile hw_sdmacore_eaa_t *) HW_SDMACORE_EAA_ADDR)
#define HW_SDMACORE_EAA_RD()      (HW_SDMACORE_EAA.U)
#define HW_SDMACORE_EAA_WR(v)     (HW_SDMACORE_EAA.U = (v))
#define HW_SDMACORE_EAA_SET(v)    (HW_SDMACORE_EAA_WR(HW_SDMACORE_EAA_RD() |  (v)))
#define HW_SDMACORE_EAA_CLR(v)    (HW_SDMACORE_EAA_WR(HW_SDMACORE_EAA_RD() & ~(v)))
#define HW_SDMACORE_EAA_TOG(v)    (HW_SDMACORE_EAA_WR(HW_SDMACORE_EAA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EAA bitfields
 */

/* --- Register HW_SDMACORE_EAA, field EAA */

#define BP_SDMACORE_EAA_EAA      0
#define BM_SDMACORE_EAA_EAA      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EAA_EAA(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EAA_EAA)
#else
#define BF_SDMACORE_EAA_EAA(v)   (((v) << 0) & BM_SDMACORE_EAA_EAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EAA_EAA(v)   BF_CS1(SDMACORE_EAA, EAA, v)
#endif

/*
 * HW_SDMACORE_EAB - OnCE Event Cell Address Register B
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EAB : 16;
        unsigned RESERVED0 : 16;

    } B;
} hw_sdmacore_eab_t;
#endif

/*
 * constants & macros for entire SDMACORE_EAB register
 */
#define HW_SDMACORE_EAB_ADDR      (REGS_SDMACORE_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EAB           (*(volatile hw_sdmacore_eab_t *) HW_SDMACORE_EAB_ADDR)
#define HW_SDMACORE_EAB_RD()      (HW_SDMACORE_EAB.U)
#define HW_SDMACORE_EAB_WR(v)     (HW_SDMACORE_EAB.U = (v))
#define HW_SDMACORE_EAB_SET(v)    (HW_SDMACORE_EAB_WR(HW_SDMACORE_EAB_RD() |  (v)))
#define HW_SDMACORE_EAB_CLR(v)    (HW_SDMACORE_EAB_WR(HW_SDMACORE_EAB_RD() & ~(v)))
#define HW_SDMACORE_EAB_TOG(v)    (HW_SDMACORE_EAB_WR(HW_SDMACORE_EAB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EAB bitfields
 */

/* --- Register HW_SDMACORE_EAB, field EAB */

#define BP_SDMACORE_EAB_EAB      0
#define BM_SDMACORE_EAB_EAB      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EAB_EAB(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EAB_EAB)
#else
#define BF_SDMACORE_EAB_EAB(v)   (((v) << 0) & BM_SDMACORE_EAB_EAB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EAB_EAB(v)   BF_CS1(SDMACORE_EAB, EAB, v)
#endif

/*
 * HW_SDMACORE_EAM - OnCE Event Cell Address Mask
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EAM : 16;
        unsigned RESERVED0 : 16;

    } B;
} hw_sdmacore_eam_t;
#endif

/*
 * constants & macros for entire SDMACORE_EAM register
 */
#define HW_SDMACORE_EAM_ADDR      (REGS_SDMACORE_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EAM           (*(volatile hw_sdmacore_eam_t *) HW_SDMACORE_EAM_ADDR)
#define HW_SDMACORE_EAM_RD()      (HW_SDMACORE_EAM.U)
#define HW_SDMACORE_EAM_WR(v)     (HW_SDMACORE_EAM.U = (v))
#define HW_SDMACORE_EAM_SET(v)    (HW_SDMACORE_EAM_WR(HW_SDMACORE_EAM_RD() |  (v)))
#define HW_SDMACORE_EAM_CLR(v)    (HW_SDMACORE_EAM_WR(HW_SDMACORE_EAM_RD() & ~(v)))
#define HW_SDMACORE_EAM_TOG(v)    (HW_SDMACORE_EAM_WR(HW_SDMACORE_EAM_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EAM bitfields
 */

/* --- Register HW_SDMACORE_EAM, field EAM */

#define BP_SDMACORE_EAM_EAM      0
#define BM_SDMACORE_EAM_EAM      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EAM_EAM(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EAM_EAM)
#else
#define BF_SDMACORE_EAM_EAM(v)   (((v) << 0) & BM_SDMACORE_EAM_EAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EAM_EAM(v)   BF_CS1(SDMACORE_EAM, EAM, v)
#endif

/*
 * HW_SDMACORE_ED - OnCE Event Cell Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ED : 32;

    } B;
} hw_sdmacore_ed_t;
#endif

/*
 * constants & macros for entire SDMACORE_ED register
 */
#define HW_SDMACORE_ED_ADDR      (REGS_SDMACORE_BASE + 0xe)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_ED           (*(volatile hw_sdmacore_ed_t *) HW_SDMACORE_ED_ADDR)
#define HW_SDMACORE_ED_RD()      (HW_SDMACORE_ED.U)
#define HW_SDMACORE_ED_WR(v)     (HW_SDMACORE_ED.U = (v))
#define HW_SDMACORE_ED_SET(v)    (HW_SDMACORE_ED_WR(HW_SDMACORE_ED_RD() |  (v)))
#define HW_SDMACORE_ED_CLR(v)    (HW_SDMACORE_ED_WR(HW_SDMACORE_ED_RD() & ~(v)))
#define HW_SDMACORE_ED_TOG(v)    (HW_SDMACORE_ED_WR(HW_SDMACORE_ED_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_ED bitfields
 */

/* --- Register HW_SDMACORE_ED, field ED */

#define BP_SDMACORE_ED_ED      0
#define BM_SDMACORE_ED_ED      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ED_ED(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_ED_ED)
#else
#define BF_SDMACORE_ED_ED(v)   (((v) << 0) & BM_SDMACORE_ED_ED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ED_ED(v)   BF_CS1(SDMACORE_ED, ED, v)
#endif

/*
 * HW_SDMACORE_EDM - OnCE Event Cell Data Mask
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EDM : 32;

    } B;
} hw_sdmacore_edm_t;
#endif

/*
 * constants & macros for entire SDMACORE_EDM register
 */
#define HW_SDMACORE_EDM_ADDR      (REGS_SDMACORE_BASE + 0xf)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EDM           (*(volatile hw_sdmacore_edm_t *) HW_SDMACORE_EDM_ADDR)
#define HW_SDMACORE_EDM_RD()      (HW_SDMACORE_EDM.U)
#define HW_SDMACORE_EDM_WR(v)     (HW_SDMACORE_EDM.U = (v))
#define HW_SDMACORE_EDM_SET(v)    (HW_SDMACORE_EDM_WR(HW_SDMACORE_EDM_RD() |  (v)))
#define HW_SDMACORE_EDM_CLR(v)    (HW_SDMACORE_EDM_WR(HW_SDMACORE_EDM_RD() & ~(v)))
#define HW_SDMACORE_EDM_TOG(v)    (HW_SDMACORE_EDM_WR(HW_SDMACORE_EDM_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EDM bitfields
 */

/* --- Register HW_SDMACORE_EDM, field EDM */

#define BP_SDMACORE_EDM_EDM      0
#define BM_SDMACORE_EDM_EDM      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EDM_EDM(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EDM_EDM)
#else
#define BF_SDMACORE_EDM_EDM(v)   (((v) << 0) & BM_SDMACORE_EDM_EDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EDM_EDM(v)   BF_CS1(SDMACORE_EDM, EDM, v)
#endif

/*
 * HW_SDMACORE_RTB - OnCE Real-Time Buffer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RTB : 32;

    } B;
} hw_sdmacore_rtb_t;
#endif

/*
 * constants & macros for entire SDMACORE_RTB register
 */
#define HW_SDMACORE_RTB_ADDR      (REGS_SDMACORE_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_RTB           (*(volatile hw_sdmacore_rtb_t *) HW_SDMACORE_RTB_ADDR)
#define HW_SDMACORE_RTB_RD()      (HW_SDMACORE_RTB.U)
#define HW_SDMACORE_RTB_WR(v)     (HW_SDMACORE_RTB.U = (v))
#define HW_SDMACORE_RTB_SET(v)    (HW_SDMACORE_RTB_WR(HW_SDMACORE_RTB_RD() |  (v)))
#define HW_SDMACORE_RTB_CLR(v)    (HW_SDMACORE_RTB_WR(HW_SDMACORE_RTB_RD() & ~(v)))
#define HW_SDMACORE_RTB_TOG(v)    (HW_SDMACORE_RTB_WR(HW_SDMACORE_RTB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_RTB bitfields
 */

/* --- Register HW_SDMACORE_RTB, field RTB */

#define BP_SDMACORE_RTB_RTB      0
#define BM_SDMACORE_RTB_RTB      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_RTB_RTB(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_RTB_RTB)
#else
#define BF_SDMACORE_RTB_RTB(v)   (((v) << 0) & BM_SDMACORE_RTB_RTB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_RTB_RTB(v)   BF_CS1(SDMACORE_RTB, RTB, v)
#endif

/*
 * HW_SDMACORE_TB - OnCE Trace Buffer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHFADDR : 14;
        unsigned TADDR : 14;
        unsigned TBF : 1;
        unsigned RESERVED0 : 3;

    } B;
} hw_sdmacore_tb_t;
#endif

/*
 * constants & macros for entire SDMACORE_TB register
 */
#define HW_SDMACORE_TB_ADDR      (REGS_SDMACORE_BASE + 0x19)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_TB           (*(volatile hw_sdmacore_tb_t *) HW_SDMACORE_TB_ADDR)
#define HW_SDMACORE_TB_RD()      (HW_SDMACORE_TB.U)
#define HW_SDMACORE_TB_WR(v)     (HW_SDMACORE_TB.U = (v))
#define HW_SDMACORE_TB_SET(v)    (HW_SDMACORE_TB_WR(HW_SDMACORE_TB_RD() |  (v)))
#define HW_SDMACORE_TB_CLR(v)    (HW_SDMACORE_TB_WR(HW_SDMACORE_TB_RD() & ~(v)))
#define HW_SDMACORE_TB_TOG(v)    (HW_SDMACORE_TB_WR(HW_SDMACORE_TB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_TB bitfields
 */

/* --- Register HW_SDMACORE_TB, field CHFADDR */

#define BP_SDMACORE_TB_CHFADDR      0
#define BM_SDMACORE_TB_CHFADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_TB_CHFADDR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_TB_CHFADDR)
#else
#define BF_SDMACORE_TB_CHFADDR(v)   (((v) << 0) & BM_SDMACORE_TB_CHFADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_TB_CHFADDR(v)   BF_CS1(SDMACORE_TB, CHFADDR, v)
#endif

/* --- Register HW_SDMACORE_TB, field TADDR */

#define BP_SDMACORE_TB_TADDR      14
#define BM_SDMACORE_TB_TADDR      0x0fffc000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_TB_TADDR(v)   ((((reg32_t) v) << 14) & BM_SDMACORE_TB_TADDR)
#else
#define BF_SDMACORE_TB_TADDR(v)   (((v) << 14) & BM_SDMACORE_TB_TADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_TB_TADDR(v)   BF_CS1(SDMACORE_TB, TADDR, v)
#endif

/* --- Register HW_SDMACORE_TB, field TBF */

#define BP_SDMACORE_TB_TBF      28
#define BM_SDMACORE_TB_TBF      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_TB_TBF(v)   ((((reg32_t) v) << 28) & BM_SDMACORE_TB_TBF)
#else
#define BF_SDMACORE_TB_TBF(v)   (((v) << 28) & BM_SDMACORE_TB_TBF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_TB_TBF(v)   BF_CS1(SDMACORE_TB, TBF, v)
#endif

/*
 * HW_SDMACORE_OSTAT - OnCE Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ECDR : 3;
        unsigned RESERVED0 : 4;
        unsigned MST : 1;
        unsigned SWB : 1;
        unsigned ODR : 1;
        unsigned EDR : 1;
        unsigned RCV : 1;
        unsigned PST : 4;
        unsigned RESERVED1 : 16;

    } B;
} hw_sdmacore_ostat_t;
#endif

/*
 * constants & macros for entire SDMACORE_OSTAT register
 */
#define HW_SDMACORE_OSTAT_ADDR      (REGS_SDMACORE_BASE + 0x1a)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_OSTAT           (*(volatile hw_sdmacore_ostat_t *) HW_SDMACORE_OSTAT_ADDR)
#define HW_SDMACORE_OSTAT_RD()      (HW_SDMACORE_OSTAT.U)
#define HW_SDMACORE_OSTAT_WR(v)     (HW_SDMACORE_OSTAT.U = (v))
#define HW_SDMACORE_OSTAT_SET(v)    (HW_SDMACORE_OSTAT_WR(HW_SDMACORE_OSTAT_RD() |  (v)))
#define HW_SDMACORE_OSTAT_CLR(v)    (HW_SDMACORE_OSTAT_WR(HW_SDMACORE_OSTAT_RD() & ~(v)))
#define HW_SDMACORE_OSTAT_TOG(v)    (HW_SDMACORE_OSTAT_WR(HW_SDMACORE_OSTAT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_OSTAT bitfields
 */

/* --- Register HW_SDMACORE_OSTAT, field ECDR */

#define BP_SDMACORE_OSTAT_ECDR      0
#define BM_SDMACORE_OSTAT_ECDR      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_ECDR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_OSTAT_ECDR)
#else
#define BF_SDMACORE_OSTAT_ECDR(v)   (((v) << 0) & BM_SDMACORE_OSTAT_ECDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_ECDR(v)   BF_CS1(SDMACORE_OSTAT, ECDR, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field MST */

#define BP_SDMACORE_OSTAT_MST      7
#define BM_SDMACORE_OSTAT_MST      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_MST(v)   ((((reg32_t) v) << 7) & BM_SDMACORE_OSTAT_MST)
#else
#define BF_SDMACORE_OSTAT_MST(v)   (((v) << 7) & BM_SDMACORE_OSTAT_MST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_MST(v)   BF_CS1(SDMACORE_OSTAT, MST, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field SWB */

#define BP_SDMACORE_OSTAT_SWB      8
#define BM_SDMACORE_OSTAT_SWB      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_SWB(v)   ((((reg32_t) v) << 8) & BM_SDMACORE_OSTAT_SWB)
#else
#define BF_SDMACORE_OSTAT_SWB(v)   (((v) << 8) & BM_SDMACORE_OSTAT_SWB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_SWB(v)   BF_CS1(SDMACORE_OSTAT, SWB, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field ODR */

#define BP_SDMACORE_OSTAT_ODR      9
#define BM_SDMACORE_OSTAT_ODR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_ODR(v)   ((((reg32_t) v) << 9) & BM_SDMACORE_OSTAT_ODR)
#else
#define BF_SDMACORE_OSTAT_ODR(v)   (((v) << 9) & BM_SDMACORE_OSTAT_ODR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_ODR(v)   BF_CS1(SDMACORE_OSTAT, ODR, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field EDR */

#define BP_SDMACORE_OSTAT_EDR      10
#define BM_SDMACORE_OSTAT_EDR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_EDR(v)   ((((reg32_t) v) << 10) & BM_SDMACORE_OSTAT_EDR)
#else
#define BF_SDMACORE_OSTAT_EDR(v)   (((v) << 10) & BM_SDMACORE_OSTAT_EDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_EDR(v)   BF_CS1(SDMACORE_OSTAT, EDR, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field RCV */

#define BP_SDMACORE_OSTAT_RCV      11
#define BM_SDMACORE_OSTAT_RCV      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_RCV(v)   ((((reg32_t) v) << 11) & BM_SDMACORE_OSTAT_RCV)
#else
#define BF_SDMACORE_OSTAT_RCV(v)   (((v) << 11) & BM_SDMACORE_OSTAT_RCV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_RCV(v)   BF_CS1(SDMACORE_OSTAT, RCV, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field PST */

#define BP_SDMACORE_OSTAT_PST      12
#define BM_SDMACORE_OSTAT_PST      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_PST(v)   ((((reg32_t) v) << 12) & BM_SDMACORE_OSTAT_PST)
#else
#define BF_SDMACORE_OSTAT_PST(v)   (((v) << 12) & BM_SDMACORE_OSTAT_PST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_PST(v)   BF_CS1(SDMACORE_OSTAT, PST, v)
#endif

/*
 * HW_SDMACORE_MCHN0ADDR - Channel 0 Boot Address
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHN0ADDR : 14;
        unsigned SMSZ : 1;
        unsigned RESERVED0 : 17;

    } B;
} hw_sdmacore_mchn0addr_t;
#endif

/*
 * constants & macros for entire SDMACORE_MCHN0ADDR register
 */
#define HW_SDMACORE_MCHN0ADDR_ADDR      (REGS_SDMACORE_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_MCHN0ADDR           (*(volatile hw_sdmacore_mchn0addr_t *) HW_SDMACORE_MCHN0ADDR_ADDR)
#define HW_SDMACORE_MCHN0ADDR_RD()      (HW_SDMACORE_MCHN0ADDR.U)
#define HW_SDMACORE_MCHN0ADDR_WR(v)     (HW_SDMACORE_MCHN0ADDR.U = (v))
#define HW_SDMACORE_MCHN0ADDR_SET(v)    (HW_SDMACORE_MCHN0ADDR_WR(HW_SDMACORE_MCHN0ADDR_RD() |  (v)))
#define HW_SDMACORE_MCHN0ADDR_CLR(v)    (HW_SDMACORE_MCHN0ADDR_WR(HW_SDMACORE_MCHN0ADDR_RD() & ~(v)))
#define HW_SDMACORE_MCHN0ADDR_TOG(v)    (HW_SDMACORE_MCHN0ADDR_WR(HW_SDMACORE_MCHN0ADDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_MCHN0ADDR bitfields
 */

/* --- Register HW_SDMACORE_MCHN0ADDR, field CHN0ADDR */

#define BP_SDMACORE_MCHN0ADDR_CHN0ADDR      0
#define BM_SDMACORE_MCHN0ADDR_CHN0ADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MCHN0ADDR_CHN0ADDR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_MCHN0ADDR_CHN0ADDR)
#else
#define BF_SDMACORE_MCHN0ADDR_CHN0ADDR(v)   (((v) << 0) & BM_SDMACORE_MCHN0ADDR_CHN0ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MCHN0ADDR_CHN0ADDR(v)   BF_CS1(SDMACORE_MCHN0ADDR, CHN0ADDR, v)
#endif

/* --- Register HW_SDMACORE_MCHN0ADDR, field SMSZ */

#define BP_SDMACORE_MCHN0ADDR_SMSZ      14
#define BM_SDMACORE_MCHN0ADDR_SMSZ      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MCHN0ADDR_SMSZ(v)   ((((reg32_t) v) << 14) & BM_SDMACORE_MCHN0ADDR_SMSZ)
#else
#define BF_SDMACORE_MCHN0ADDR_SMSZ(v)   (((v) << 14) & BM_SDMACORE_MCHN0ADDR_SMSZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MCHN0ADDR_SMSZ(v)   BF_CS1(SDMACORE_MCHN0ADDR, SMSZ, v)
#endif

/*
 * HW_SDMACORE_ENDIANNESS - ENDIAN Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned APEND : 1;
        unsigned RESERVED0 : 2;
        unsigned BPEND : 1;
        unsigned RESERVED1 : 1;
        unsigned BYTESWP : 1;
        unsigned RESERVED2 : 29;

    } B;
} hw_sdmacore_endianness_t;
#endif

/*
 * constants & macros for entire SDMACORE_ENDIANNESS register
 */
#define HW_SDMACORE_ENDIANNESS_ADDR      (REGS_SDMACORE_BASE + 0x1d)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_ENDIANNESS           (*(volatile hw_sdmacore_endianness_t *) HW_SDMACORE_ENDIANNESS_ADDR)
#define HW_SDMACORE_ENDIANNESS_RD()      (HW_SDMACORE_ENDIANNESS.U)
#define HW_SDMACORE_ENDIANNESS_WR(v)     (HW_SDMACORE_ENDIANNESS.U = (v))
#define HW_SDMACORE_ENDIANNESS_SET(v)    (HW_SDMACORE_ENDIANNESS_WR(HW_SDMACORE_ENDIANNESS_RD() |  (v)))
#define HW_SDMACORE_ENDIANNESS_CLR(v)    (HW_SDMACORE_ENDIANNESS_WR(HW_SDMACORE_ENDIANNESS_RD() & ~(v)))
#define HW_SDMACORE_ENDIANNESS_TOG(v)    (HW_SDMACORE_ENDIANNESS_WR(HW_SDMACORE_ENDIANNESS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_ENDIANNESS bitfields
 */

/* --- Register HW_SDMACORE_ENDIANNESS, field APEND */

#define BP_SDMACORE_ENDIANNESS_APEND      0
#define BM_SDMACORE_ENDIANNESS_APEND      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ENDIANNESS_APEND(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_ENDIANNESS_APEND)
#else
#define BF_SDMACORE_ENDIANNESS_APEND(v)   (((v) << 0) & BM_SDMACORE_ENDIANNESS_APEND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ENDIANNESS_APEND(v)   BF_CS1(SDMACORE_ENDIANNESS, APEND, v)
#endif

/* --- Register HW_SDMACORE_ENDIANNESS, field BPEND */

#define BP_SDMACORE_ENDIANNESS_BPEND      1
#define BM_SDMACORE_ENDIANNESS_BPEND      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ENDIANNESS_BPEND(v)   ((((reg32_t) v) << 1) & BM_SDMACORE_ENDIANNESS_BPEND)
#else
#define BF_SDMACORE_ENDIANNESS_BPEND(v)   (((v) << 1) & BM_SDMACORE_ENDIANNESS_BPEND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ENDIANNESS_BPEND(v)   BF_CS1(SDMACORE_ENDIANNESS, BPEND, v)
#endif

/* --- Register HW_SDMACORE_ENDIANNESS, field BYTESWP */

#define BP_SDMACORE_ENDIANNESS_BYTESWP      2
#define BM_SDMACORE_ENDIANNESS_BYTESWP      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ENDIANNESS_BYTESWP(v)   ((((reg32_t) v) << 2) & BM_SDMACORE_ENDIANNESS_BYTESWP)
#else
#define BF_SDMACORE_ENDIANNESS_BYTESWP(v)   (((v) << 2) & BM_SDMACORE_ENDIANNESS_BYTESWP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ENDIANNESS_BYTESWP(v)   BF_CS1(SDMACORE_ENDIANNESS, BYTESWP, v)
#endif

/*
 * HW_SDMACORE_MODE - Mode Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned APEND : 1;
        unsigned RESERVED0 : 2;
        unsigned BPEND : 1;
        unsigned BYTESWP : 1;
        unsigned DSPCTRL : 1;
        unsigned RESERVED1 : 28;

    } B;
} hw_sdmacore_mode_t;
#endif

/*
 * constants & macros for entire SDMACORE_MODE register
 */
#define HW_SDMACORE_MODE_ADDR      (REGS_SDMACORE_BASE + 0x1d)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_MODE           (*(volatile hw_sdmacore_mode_t *) HW_SDMACORE_MODE_ADDR)
#define HW_SDMACORE_MODE_RD()      (HW_SDMACORE_MODE.U)
#define HW_SDMACORE_MODE_WR(v)     (HW_SDMACORE_MODE.U = (v))
#define HW_SDMACORE_MODE_SET(v)    (HW_SDMACORE_MODE_WR(HW_SDMACORE_MODE_RD() |  (v)))
#define HW_SDMACORE_MODE_CLR(v)    (HW_SDMACORE_MODE_WR(HW_SDMACORE_MODE_RD() & ~(v)))
#define HW_SDMACORE_MODE_TOG(v)    (HW_SDMACORE_MODE_WR(HW_SDMACORE_MODE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_MODE bitfields
 */

/* --- Register HW_SDMACORE_MODE, field APEND */

#define BP_SDMACORE_MODE_APEND      0
#define BM_SDMACORE_MODE_APEND      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MODE_APEND(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_MODE_APEND)
#else
#define BF_SDMACORE_MODE_APEND(v)   (((v) << 0) & BM_SDMACORE_MODE_APEND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MODE_APEND(v)   BF_CS1(SDMACORE_MODE, APEND, v)
#endif

/* --- Register HW_SDMACORE_MODE, field BPEND */

#define BP_SDMACORE_MODE_BPEND      1
#define BM_SDMACORE_MODE_BPEND      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MODE_BPEND(v)   ((((reg32_t) v) << 1) & BM_SDMACORE_MODE_BPEND)
#else
#define BF_SDMACORE_MODE_BPEND(v)   (((v) << 1) & BM_SDMACORE_MODE_BPEND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MODE_BPEND(v)   BF_CS1(SDMACORE_MODE, BPEND, v)
#endif

/* --- Register HW_SDMACORE_MODE, field BYTESWP */

#define BP_SDMACORE_MODE_BYTESWP      2
#define BM_SDMACORE_MODE_BYTESWP      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MODE_BYTESWP(v)   ((((reg32_t) v) << 2) & BM_SDMACORE_MODE_BYTESWP)
#else
#define BF_SDMACORE_MODE_BYTESWP(v)   (((v) << 2) & BM_SDMACORE_MODE_BYTESWP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MODE_BYTESWP(v)   BF_CS1(SDMACORE_MODE, BYTESWP, v)
#endif

/* --- Register HW_SDMACORE_MODE, field DSPCTRL */

#define BP_SDMACORE_MODE_DSPCTRL      3
#define BM_SDMACORE_MODE_DSPCTRL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MODE_DSPCTRL(v)   ((((reg32_t) v) << 3) & BM_SDMACORE_MODE_DSPCTRL)
#else
#define BF_SDMACORE_MODE_DSPCTRL(v)   (((v) << 3) & BM_SDMACORE_MODE_DSPCTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MODE_DSPCTRL(v)   BF_CS1(SDMACORE_MODE, DSPCTRL, v)
#endif

/*
 * HW_SDMACORE_SDMA_LOCK - Lock Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LOCK : 1;
        unsigned RESERVED0 : 31;

    } B;
} hw_sdmacore_sdma_lock_t;
#endif

/*
 * constants & macros for entire SDMACORE_SDMA_LOCK register
 */
#define HW_SDMACORE_SDMA_LOCK_ADDR      (REGS_SDMACORE_BASE + 0x1e)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_SDMA_LOCK           (*(volatile hw_sdmacore_sdma_lock_t *) HW_SDMACORE_SDMA_LOCK_ADDR)
#define HW_SDMACORE_SDMA_LOCK_RD()      (HW_SDMACORE_SDMA_LOCK.U)
#define HW_SDMACORE_SDMA_LOCK_WR(v)     (HW_SDMACORE_SDMA_LOCK.U = (v))
#define HW_SDMACORE_SDMA_LOCK_SET(v)    (HW_SDMACORE_SDMA_LOCK_WR(HW_SDMACORE_SDMA_LOCK_RD() |  (v)))
#define HW_SDMACORE_SDMA_LOCK_CLR(v)    (HW_SDMACORE_SDMA_LOCK_WR(HW_SDMACORE_SDMA_LOCK_RD() & ~(v)))
#define HW_SDMACORE_SDMA_LOCK_TOG(v)    (HW_SDMACORE_SDMA_LOCK_WR(HW_SDMACORE_SDMA_LOCK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_SDMA_LOCK bitfields
 */

/* --- Register HW_SDMACORE_SDMA_LOCK, field LOCK */

#define BP_SDMACORE_SDMA_LOCK_LOCK      0
#define BM_SDMACORE_SDMA_LOCK_LOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_SDMA_LOCK_LOCK(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_SDMA_LOCK_LOCK)
#else
#define BF_SDMACORE_SDMA_LOCK_LOCK(v)   (((v) << 0) & BM_SDMACORE_SDMA_LOCK_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_SDMA_LOCK_LOCK(v)   BF_CS1(SDMACORE_SDMA_LOCK, LOCK, v)
#endif

/*
 * HW_SDMACORE_EVENTS2 - External DMA Requests Mirror #2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EVENTS : 16;
        unsigned RESERVED0 : 16;

    } B;
} hw_sdmacore_events2_t;
#endif

/*
 * constants & macros for entire SDMACORE_EVENTS2 register
 */
#define HW_SDMACORE_EVENTS2_ADDR      (REGS_SDMACORE_BASE + 0x1f)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EVENTS2           (*(volatile hw_sdmacore_events2_t *) HW_SDMACORE_EVENTS2_ADDR)
#define HW_SDMACORE_EVENTS2_RD()      (HW_SDMACORE_EVENTS2.U)
#define HW_SDMACORE_EVENTS2_WR(v)     (HW_SDMACORE_EVENTS2.U = (v))
#define HW_SDMACORE_EVENTS2_SET(v)    (HW_SDMACORE_EVENTS2_WR(HW_SDMACORE_EVENTS2_RD() |  (v)))
#define HW_SDMACORE_EVENTS2_CLR(v)    (HW_SDMACORE_EVENTS2_WR(HW_SDMACORE_EVENTS2_RD() & ~(v)))
#define HW_SDMACORE_EVENTS2_TOG(v)    (HW_SDMACORE_EVENTS2_WR(HW_SDMACORE_EVENTS2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EVENTS2 bitfields
 */

/* --- Register HW_SDMACORE_EVENTS2, field EVENTS */

#define BP_SDMACORE_EVENTS2_EVENTS      0
#define BM_SDMACORE_EVENTS2_EVENTS      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EVENTS2_EVENTS(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EVENTS2_EVENTS)
#else
#define BF_SDMACORE_EVENTS2_EVENTS(v)   (((v) << 0) & BM_SDMACORE_EVENTS2_EVENTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EVENTS2_EVENTS(v)   BF_CS1(SDMACORE_EVENTS2, EVENTS, v)
#endif

/*
 * HW_SDMACORE_HE - AP Enable Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HE : 32;

    } B;
} hw_sdmacore_he_t;
#endif

/*
 * constants & macros for entire SDMACORE_HE register
 */
#define HW_SDMACORE_HE_ADDR      (REGS_SDMACORE_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_HE           (*(volatile hw_sdmacore_he_t *) HW_SDMACORE_HE_ADDR)
#define HW_SDMACORE_HE_RD()      (HW_SDMACORE_HE.U)
#define HW_SDMACORE_HE_WR(v)     (HW_SDMACORE_HE.U = (v))
#define HW_SDMACORE_HE_SET(v)    (HW_SDMACORE_HE_WR(HW_SDMACORE_HE_RD() |  (v)))
#define HW_SDMACORE_HE_CLR(v)    (HW_SDMACORE_HE_WR(HW_SDMACORE_HE_RD() & ~(v)))
#define HW_SDMACORE_HE_TOG(v)    (HW_SDMACORE_HE_WR(HW_SDMACORE_HE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_HE bitfields
 */

/* --- Register HW_SDMACORE_HE, field HE */

#define BP_SDMACORE_HE_HE      0
#define BM_SDMACORE_HE_HE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_HE_HE(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_HE_HE)
#else
#define BF_SDMACORE_HE_HE(v)   (((v) << 0) & BM_SDMACORE_HE_HE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_HE_HE(v)   BF_CS1(SDMACORE_HE, HE, v)
#endif

/*
 * HW_SDMACORE_DE - BP Enable Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DE : 32;

    } B;
} hw_sdmacore_de_t;
#endif

/*
 * constants & macros for entire SDMACORE_DE register
 */
#define HW_SDMACORE_DE_ADDR      (REGS_SDMACORE_BASE + 0x21)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_DE           (*(volatile hw_sdmacore_de_t *) HW_SDMACORE_DE_ADDR)
#define HW_SDMACORE_DE_RD()      (HW_SDMACORE_DE.U)
#define HW_SDMACORE_DE_WR(v)     (HW_SDMACORE_DE.U = (v))
#define HW_SDMACORE_DE_SET(v)    (HW_SDMACORE_DE_WR(HW_SDMACORE_DE_RD() |  (v)))
#define HW_SDMACORE_DE_CLR(v)    (HW_SDMACORE_DE_WR(HW_SDMACORE_DE_RD() & ~(v)))
#define HW_SDMACORE_DE_TOG(v)    (HW_SDMACORE_DE_WR(HW_SDMACORE_DE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_DE bitfields
 */

/* --- Register HW_SDMACORE_DE, field DE */

#define BP_SDMACORE_DE_DE      0
#define BM_SDMACORE_DE_DE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_DE_DE(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_DE_DE)
#else
#define BF_SDMACORE_DE_DE(v)   (((v) << 0) & BM_SDMACORE_DE_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_DE_DE(v)   BF_CS1(SDMACORE_DE, DE, v)
#endif

/*
 * HW_SDMACORE_PRIV - Current Channel BP Privilege Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BPPRIV : 1;
        unsigned RESERVED0 : 31;

    } B;
} hw_sdmacore_priv_t;
#endif

/*
 * constants & macros for entire SDMACORE_PRIV register
 */
#define HW_SDMACORE_PRIV_ADDR      (REGS_SDMACORE_BASE + 0x22)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_PRIV           (*(volatile hw_sdmacore_priv_t *) HW_SDMACORE_PRIV_ADDR)
#define HW_SDMACORE_PRIV_RD()      (HW_SDMACORE_PRIV.U)
#define HW_SDMACORE_PRIV_WR(v)     (HW_SDMACORE_PRIV.U = (v))
#define HW_SDMACORE_PRIV_SET(v)    (HW_SDMACORE_PRIV_WR(HW_SDMACORE_PRIV_RD() |  (v)))
#define HW_SDMACORE_PRIV_CLR(v)    (HW_SDMACORE_PRIV_WR(HW_SDMACORE_PRIV_RD() & ~(v)))
#define HW_SDMACORE_PRIV_TOG(v)    (HW_SDMACORE_PRIV_WR(HW_SDMACORE_PRIV_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_PRIV bitfields
 */

/* --- Register HW_SDMACORE_PRIV, field BPPRIV */

#define BP_SDMACORE_PRIV_BPPRIV      0
#define BM_SDMACORE_PRIV_BPPRIV      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_PRIV_BPPRIV(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_PRIV_BPPRIV)
#else
#define BF_SDMACORE_PRIV_BPPRIV(v)   (((v) << 0) & BM_SDMACORE_PRIV_BPPRIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_PRIV_BPPRIV(v)   BF_CS1(SDMACORE_PRIV, BPPRIV, v)
#endif

/*
 * HW_SDMACORE_PRF_CNT - Profile Free Running Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNTER : 22;
        unsigned OFL : 1;
        unsigned RES : 6;
        unsigned EN : 1;
        unsigned SEL : 2;

    } B;
} hw_sdmacore_prf_cnt_t;
#endif

/*
 * constants & macros for entire SDMACORE_PRF_CNT register
 */
#define HW_SDMACORE_PRF_CNT_ADDR      (REGS_SDMACORE_BASE + 0x23)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_PRF_CNT           (*(volatile hw_sdmacore_prf_cnt_t *) HW_SDMACORE_PRF_CNT_ADDR)
#define HW_SDMACORE_PRF_CNT_RD()      (HW_SDMACORE_PRF_CNT.U)
#define HW_SDMACORE_PRF_CNT_WR(v)     (HW_SDMACORE_PRF_CNT.U = (v))
#define HW_SDMACORE_PRF_CNT_SET(v)    (HW_SDMACORE_PRF_CNT_WR(HW_SDMACORE_PRF_CNT_RD() |  (v)))
#define HW_SDMACORE_PRF_CNT_CLR(v)    (HW_SDMACORE_PRF_CNT_WR(HW_SDMACORE_PRF_CNT_RD() & ~(v)))
#define HW_SDMACORE_PRF_CNT_TOG(v)    (HW_SDMACORE_PRF_CNT_WR(HW_SDMACORE_PRF_CNT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_PRF_CNT bitfields
 */

/* --- Register HW_SDMACORE_PRF_CNT, field COUNTER */

#define BP_SDMACORE_PRF_CNT_COUNTER      0
#define BM_SDMACORE_PRF_CNT_COUNTER      0x003fffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_PRF_CNT_COUNTER(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_PRF_CNT_COUNTER)
#else
#define BF_SDMACORE_PRF_CNT_COUNTER(v)   (((v) << 0) & BM_SDMACORE_PRF_CNT_COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_PRF_CNT_COUNTER(v)   BF_CS1(SDMACORE_PRF_CNT, COUNTER, v)
#endif

/* --- Register HW_SDMACORE_PRF_CNT, field OFL */

#define BP_SDMACORE_PRF_CNT_OFL      22
#define BM_SDMACORE_PRF_CNT_OFL      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_PRF_CNT_OFL(v)   ((((reg32_t) v) << 22) & BM_SDMACORE_PRF_CNT_OFL)
#else
#define BF_SDMACORE_PRF_CNT_OFL(v)   (((v) << 22) & BM_SDMACORE_PRF_CNT_OFL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_PRF_CNT_OFL(v)   BF_CS1(SDMACORE_PRF_CNT, OFL, v)
#endif

/* --- Register HW_SDMACORE_PRF_CNT, field RES */

#define BP_SDMACORE_PRF_CNT_RES      23
#define BM_SDMACORE_PRF_CNT_RES      0x1f800000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_PRF_CNT_RES(v)   ((((reg32_t) v) << 23) & BM_SDMACORE_PRF_CNT_RES)
#else
#define BF_SDMACORE_PRF_CNT_RES(v)   (((v) << 23) & BM_SDMACORE_PRF_CNT_RES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_PRF_CNT_RES(v)   BF_CS1(SDMACORE_PRF_CNT, RES, v)
#endif

/* --- Register HW_SDMACORE_PRF_CNT, field EN */

#define BP_SDMACORE_PRF_CNT_EN      29
#define BM_SDMACORE_PRF_CNT_EN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_PRF_CNT_EN(v)   ((((reg32_t) v) << 29) & BM_SDMACORE_PRF_CNT_EN)
#else
#define BF_SDMACORE_PRF_CNT_EN(v)   (((v) << 29) & BM_SDMACORE_PRF_CNT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_PRF_CNT_EN(v)   BF_CS1(SDMACORE_PRF_CNT, EN, v)
#endif

/* --- Register HW_SDMACORE_PRF_CNT, field SEL */

#define BP_SDMACORE_PRF_CNT_SEL      30
#define BM_SDMACORE_PRF_CNT_SEL      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_PRF_CNT_SEL(v)   ((((reg32_t) v) << 30) & BM_SDMACORE_PRF_CNT_SEL)
#else
#define BF_SDMACORE_PRF_CNT_SEL(v)   (((v) << 30) & BM_SDMACORE_PRF_CNT_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_PRF_CNT_SEL(v)   BF_CS1(SDMACORE_PRF_CNT, SEL, v)
#endif


#endif // _SDMACORE_H

