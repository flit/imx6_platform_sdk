/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _WDOG_H
#define _WDOG_H

#include "regs.h"

#ifndef REGS_WDOG_BASE
#define REGS_WDOG0_BASE (REGS_BASE + 0x020bc000)
#define REGS_WDOG1_BASE (REGS_BASE + 0x020c0000)
#define REGS_WDOG_BASE(x) ( x == 0 ? REGS_WDOG0_BASE : x == 1 ? REGS_WDOG1_BASE : 0xffff0000)

#endif


/*
 * HW_WDOG_WCR - Watchdog Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short WDZST : 1;
        unsigned short WDBG : 1;
        unsigned short WDE : 1;
        unsigned short RESERVED0 : 1;
        unsigned short WDT : 1;
        unsigned short WRE : 1;
        unsigned short SRS : 1;
        unsigned short WDA : 1;
        unsigned short WOE : 1;
        unsigned short WDW : 1;
        unsigned short RESERVED1 : 1;
        unsigned short WT : 8;

    } B;
} hw_wdog_wcr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WCR register
 */
#define HW_WDOG_WCR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WCR(x)           (*(volatile hw_wdog_wcr_t *) HW_WDOG_WCR_ADDR(x))
#define HW_WDOG_WCR_RD(x)        (HW_WDOG_WCR(x).U)
#define HW_WDOG_WCR_WR(x, v)     (HW_WDOG_WCR(x).U = (v))
#define HW_WDOG_WCR_SET(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) |  (v)))
#define HW_WDOG_WCR_CLR(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) & ~(v)))
#define HW_WDOG_WCR_TOG(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WCR bitfields
 */

/* --- Register HW_WDOG_WCR, field WDZST */

#define BP_WDOG_WCR_WDZST      0
#define BM_WDOG_WCR_WDZST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDZST(v)   ((((reg32_t) v) << 0) & BM_WDOG_WCR_WDZST)
#else
#define BF_WDOG_WCR_WDZST(v)   (((v) << 0) & BM_WDOG_WCR_WDZST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDZST(v)   BF_CS1(WDOG_WCR, WDZST, v)
#endif

/* --- Register HW_WDOG_WCR, field WDBG */

#define BP_WDOG_WCR_WDBG      1
#define BM_WDOG_WCR_WDBG      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDBG(v)   ((((reg32_t) v) << 1) & BM_WDOG_WCR_WDBG)
#else
#define BF_WDOG_WCR_WDBG(v)   (((v) << 1) & BM_WDOG_WCR_WDBG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDBG(v)   BF_CS1(WDOG_WCR, WDBG, v)
#endif

/* --- Register HW_WDOG_WCR, field WDE */

#define BP_WDOG_WCR_WDE      2
#define BM_WDOG_WCR_WDE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDE(v)   ((((reg32_t) v) << 2) & BM_WDOG_WCR_WDE)
#else
#define BF_WDOG_WCR_WDE(v)   (((v) << 2) & BM_WDOG_WCR_WDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDE(v)   BF_CS1(WDOG_WCR, WDE, v)
#endif

/* --- Register HW_WDOG_WCR, field WDT */

#define BP_WDOG_WCR_WDT      3
#define BM_WDOG_WCR_WDT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDT(v)   ((((reg32_t) v) << 3) & BM_WDOG_WCR_WDT)
#else
#define BF_WDOG_WCR_WDT(v)   (((v) << 3) & BM_WDOG_WCR_WDT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDT(v)   BF_CS1(WDOG_WCR, WDT, v)
#endif

/* --- Register HW_WDOG_WCR, field WRE */

#define BP_WDOG_WCR_WRE      3
#define BM_WDOG_WCR_WRE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WRE(v)   ((((reg32_t) v) << 3) & BM_WDOG_WCR_WRE)
#else
#define BF_WDOG_WCR_WRE(v)   (((v) << 3) & BM_WDOG_WCR_WRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WRE(v)   BF_CS1(WDOG_WCR, WRE, v)
#endif

/* --- Register HW_WDOG_WCR, field SRS */

#define BP_WDOG_WCR_SRS      4
#define BM_WDOG_WCR_SRS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_SRS(v)   ((((reg32_t) v) << 4) & BM_WDOG_WCR_SRS)
#else
#define BF_WDOG_WCR_SRS(v)   (((v) << 4) & BM_WDOG_WCR_SRS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_SRS(v)   BF_CS1(WDOG_WCR, SRS, v)
#endif

/* --- Register HW_WDOG_WCR, field WDA */

#define BP_WDOG_WCR_WDA      5
#define BM_WDOG_WCR_WDA      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDA(v)   ((((reg32_t) v) << 5) & BM_WDOG_WCR_WDA)
#else
#define BF_WDOG_WCR_WDA(v)   (((v) << 5) & BM_WDOG_WCR_WDA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDA(v)   BF_CS1(WDOG_WCR, WDA, v)
#endif

/* --- Register HW_WDOG_WCR, field WOE */

#define BP_WDOG_WCR_WOE      6
#define BM_WDOG_WCR_WOE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WOE(v)   ((((reg32_t) v) << 6) & BM_WDOG_WCR_WOE)
#else
#define BF_WDOG_WCR_WOE(v)   (((v) << 6) & BM_WDOG_WCR_WOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WOE(v)   BF_CS1(WDOG_WCR, WOE, v)
#endif

/* --- Register HW_WDOG_WCR, field WDW */

#define BP_WDOG_WCR_WDW      7
#define BM_WDOG_WCR_WDW      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDW(v)   ((((reg32_t) v) << 7) & BM_WDOG_WCR_WDW)
#else
#define BF_WDOG_WCR_WDW(v)   (((v) << 7) & BM_WDOG_WCR_WDW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDW(v)   BF_CS1(WDOG_WCR, WDW, v)
#endif

/* --- Register HW_WDOG_WCR, field WT */

#define BP_WDOG_WCR_WT      8
#define BM_WDOG_WCR_WT      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WT(v)   ((((reg32_t) v) << 8) & BM_WDOG_WCR_WT)
#else
#define BF_WDOG_WCR_WT(v)   (((v) << 8) & BM_WDOG_WCR_WT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WT(v)   BF_CS1(WDOG_WCR, WT, v)
#endif

/*
 * HW_WDOG_WSR - Watchdog Service Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short WSR : 16;

    } B;
} hw_wdog_wsr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WSR register
 */
#define HW_WDOG_WSR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WSR(x)           (*(volatile hw_wdog_wsr_t *) HW_WDOG_WSR_ADDR(x))
#define HW_WDOG_WSR_RD(x)        (HW_WDOG_WSR(x).U)
#define HW_WDOG_WSR_WR(x, v)     (HW_WDOG_WSR(x).U = (v))
#define HW_WDOG_WSR_SET(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) |  (v)))
#define HW_WDOG_WSR_CLR(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) & ~(v)))
#define HW_WDOG_WSR_TOG(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WSR bitfields
 */

/* --- Register HW_WDOG_WSR, field WSR */

#define BP_WDOG_WSR_WSR      0
#define BM_WDOG_WSR_WSR      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WSR_WSR(v)   ((((reg32_t) v) << 0) & BM_WDOG_WSR_WSR)
#else
#define BF_WDOG_WSR_WSR(v)   (((v) << 0) & BM_WDOG_WSR_WSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WSR_WSR(v)   BF_CS1(WDOG_WSR, WSR, v)
#endif

/*
 * HW_WDOG_WRSR - Watchdog Reset Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SFTW : 1;
        unsigned short TOUT : 1;
        unsigned short RESERVED0 : 2;
        unsigned short POR : 1;
        unsigned short RESERVED1 : 11;

    } B;
} hw_wdog_wrsr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WRSR register
 */
#define HW_WDOG_WRSR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WRSR(x)           (*(volatile hw_wdog_wrsr_t *) HW_WDOG_WRSR_ADDR(x))
#define HW_WDOG_WRSR_RD(x)        (HW_WDOG_WRSR(x).U)
#define HW_WDOG_WRSR_WR(x, v)     (HW_WDOG_WRSR(x).U = (v))
#define HW_WDOG_WRSR_SET(x, v)    (HW_WDOG_WRSR_WR(x, HW_WDOG_WRSR_RD(x) |  (v)))
#define HW_WDOG_WRSR_CLR(x, v)    (HW_WDOG_WRSR_WR(x, HW_WDOG_WRSR_RD(x) & ~(v)))
#define HW_WDOG_WRSR_TOG(x, v)    (HW_WDOG_WRSR_WR(x, HW_WDOG_WRSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WRSR bitfields
 */

/* --- Register HW_WDOG_WRSR, field SFTW */

#define BP_WDOG_WRSR_SFTW      0
#define BM_WDOG_WRSR_SFTW      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WRSR_SFTW(v)   ((((reg32_t) v) << 0) & BM_WDOG_WRSR_SFTW)
#else
#define BF_WDOG_WRSR_SFTW(v)   (((v) << 0) & BM_WDOG_WRSR_SFTW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WRSR_SFTW(v)   BF_CS1(WDOG_WRSR, SFTW, v)
#endif

/* --- Register HW_WDOG_WRSR, field TOUT */

#define BP_WDOG_WRSR_TOUT      1
#define BM_WDOG_WRSR_TOUT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WRSR_TOUT(v)   ((((reg32_t) v) << 1) & BM_WDOG_WRSR_TOUT)
#else
#define BF_WDOG_WRSR_TOUT(v)   (((v) << 1) & BM_WDOG_WRSR_TOUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WRSR_TOUT(v)   BF_CS1(WDOG_WRSR, TOUT, v)
#endif

/* --- Register HW_WDOG_WRSR, field POR */

#define BP_WDOG_WRSR_POR      4
#define BM_WDOG_WRSR_POR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WRSR_POR(v)   ((((reg32_t) v) << 4) & BM_WDOG_WRSR_POR)
#else
#define BF_WDOG_WRSR_POR(v)   (((v) << 4) & BM_WDOG_WRSR_POR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WRSR_POR(v)   BF_CS1(WDOG_WRSR, POR, v)
#endif

/*
 * HW_WDOG_WICR - Watchdog Interrupt Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short WICT : 8;
        unsigned short RESERVED0 : 6;
        unsigned short WTIS : 1;
        unsigned short WIE : 1;

    } B;
} hw_wdog_wicr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WICR register
 */
#define HW_WDOG_WICR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WICR(x)           (*(volatile hw_wdog_wicr_t *) HW_WDOG_WICR_ADDR(x))
#define HW_WDOG_WICR_RD(x)        (HW_WDOG_WICR(x).U)
#define HW_WDOG_WICR_WR(x, v)     (HW_WDOG_WICR(x).U = (v))
#define HW_WDOG_WICR_SET(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) |  (v)))
#define HW_WDOG_WICR_CLR(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) & ~(v)))
#define HW_WDOG_WICR_TOG(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WICR bitfields
 */

/* --- Register HW_WDOG_WICR, field WICT */

#define BP_WDOG_WICR_WICT      0
#define BM_WDOG_WICR_WICT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WICR_WICT(v)   ((((reg32_t) v) << 0) & BM_WDOG_WICR_WICT)
#else
#define BF_WDOG_WICR_WICT(v)   (((v) << 0) & BM_WDOG_WICR_WICT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WICR_WICT(v)   BF_CS1(WDOG_WICR, WICT, v)
#endif

/* --- Register HW_WDOG_WICR, field WTIS */

#define BP_WDOG_WICR_WTIS      14
#define BM_WDOG_WICR_WTIS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WICR_WTIS(v)   ((((reg32_t) v) << 14) & BM_WDOG_WICR_WTIS)
#else
#define BF_WDOG_WICR_WTIS(v)   (((v) << 14) & BM_WDOG_WICR_WTIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WICR_WTIS(v)   BF_CS1(WDOG_WICR, WTIS, v)
#endif

/* --- Register HW_WDOG_WICR, field WIE */

#define BP_WDOG_WICR_WIE      15
#define BM_WDOG_WICR_WIE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WICR_WIE(v)   ((((reg32_t) v) << 15) & BM_WDOG_WICR_WIE)
#else
#define BF_WDOG_WICR_WIE(v)   (((v) << 15) & BM_WDOG_WICR_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WICR_WIE(v)   BF_CS1(WDOG_WICR, WIE, v)
#endif

/*
 * HW_WDOG_WMCR - Watchdog Miscellaneous Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short PDE : 1;
        unsigned short RESERVED0 : 15;

    } B;
} hw_wdog_wmcr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WMCR register
 */
#define HW_WDOG_WMCR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WMCR(x)           (*(volatile hw_wdog_wmcr_t *) HW_WDOG_WMCR_ADDR(x))
#define HW_WDOG_WMCR_RD(x)        (HW_WDOG_WMCR(x).U)
#define HW_WDOG_WMCR_WR(x, v)     (HW_WDOG_WMCR(x).U = (v))
#define HW_WDOG_WMCR_SET(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) |  (v)))
#define HW_WDOG_WMCR_CLR(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) & ~(v)))
#define HW_WDOG_WMCR_TOG(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WMCR bitfields
 */

/* --- Register HW_WDOG_WMCR, field PDE */

#define BP_WDOG_WMCR_PDE      0
#define BM_WDOG_WMCR_PDE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WMCR_PDE(v)   ((((reg32_t) v) << 0) & BM_WDOG_WMCR_PDE)
#else
#define BF_WDOG_WMCR_PDE(v)   (((v) << 0) & BM_WDOG_WMCR_PDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WMCR_PDE(v)   BF_CS1(WDOG_WMCR, PDE, v)
#endif

/*
 * HW_WDOG_WCVR - Watchdog Counter Value Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short WTCV : 8;
        unsigned short RESERVED0 : 8;

    } B;
} hw_wdog_wcvr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WCVR register
 */
#define HW_WDOG_WCVR_ADDR(x)      (REGS_WDOG_BASE(x) + 0xa)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WCVR(x)           (*(volatile hw_wdog_wcvr_t *) HW_WDOG_WCVR_ADDR(x))
#define HW_WDOG_WCVR_RD(x)        (HW_WDOG_WCVR(x).U)
#define HW_WDOG_WCVR_WR(x, v)     (HW_WDOG_WCVR(x).U = (v))
#define HW_WDOG_WCVR_SET(x, v)    (HW_WDOG_WCVR_WR(x, HW_WDOG_WCVR_RD(x) |  (v)))
#define HW_WDOG_WCVR_CLR(x, v)    (HW_WDOG_WCVR_WR(x, HW_WDOG_WCVR_RD(x) & ~(v)))
#define HW_WDOG_WCVR_TOG(x, v)    (HW_WDOG_WCVR_WR(x, HW_WDOG_WCVR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WCVR bitfields
 */

/* --- Register HW_WDOG_WCVR, field WTCV */

#define BP_WDOG_WCVR_WTCV      0
#define BM_WDOG_WCVR_WTCV      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCVR_WTCV(v)   ((((reg32_t) v) << 0) & BM_WDOG_WCVR_WTCV)
#else
#define BF_WDOG_WCVR_WTCV(v)   (((v) << 0) & BM_WDOG_WCVR_WTCV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCVR_WTCV(v)   BF_CS1(WDOG_WCVR, WTCV, v)
#endif


#endif // _WDOG_H

