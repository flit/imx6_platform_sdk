/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SDMABP_H
#define _SDMABP_H

#include "regs.h"

#ifndef REGS_SDMABP_BASE
#define REGS_SDMABP_BASE (REGS_BASE + 0x020ec000)

#endif


/*
 * HW_SDMABP_DC0PTR - Channel 0 Pointer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DC0PTR : 32;

    } B;
} hw_sdmabp_dc0ptr_t;
#endif

/*
 * constants & macros for entire SDMABP_DC0PTR register
 */
#define HW_SDMABP_DC0PTR_ADDR      (REGS_SDMABP_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_DC0PTR           (*(volatile hw_sdmabp_dc0ptr_t *) HW_SDMABP_DC0PTR_ADDR)
#define HW_SDMABP_DC0PTR_RD()      (HW_SDMABP_DC0PTR.U)
#define HW_SDMABP_DC0PTR_WR(v)     (HW_SDMABP_DC0PTR.U = (v))
#define HW_SDMABP_DC0PTR_SET(v)    (HW_SDMABP_DC0PTR_WR(HW_SDMABP_DC0PTR_RD() |  (v)))
#define HW_SDMABP_DC0PTR_CLR(v)    (HW_SDMABP_DC0PTR_WR(HW_SDMABP_DC0PTR_RD() & ~(v)))
#define HW_SDMABP_DC0PTR_TOG(v)    (HW_SDMABP_DC0PTR_WR(HW_SDMABP_DC0PTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMABP_DC0PTR bitfields
 */

/* --- Register HW_SDMABP_DC0PTR, field DC0PTR */

#define BP_SDMABP_DC0PTR_DC0PTR      0
#define BM_SDMABP_DC0PTR_DC0PTR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_DC0PTR_DC0PTR(v)   ((((reg32_t) v) << 0) & BM_SDMABP_DC0PTR_DC0PTR)
#else
#define BF_SDMABP_DC0PTR_DC0PTR(v)   (((v) << 0) & BM_SDMABP_DC0PTR_DC0PTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMABP_DC0PTR_DC0PTR(v)   BF_CS1(SDMABP_DC0PTR, DC0PTR, v)
#endif

/*
 * HW_SDMABP_INTR - Channel Interrupts
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DI : 32;

    } B;
} hw_sdmabp_intr_t;
#endif

/*
 * constants & macros for entire SDMABP_INTR register
 */
#define HW_SDMABP_INTR_ADDR      (REGS_SDMABP_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_INTR           (*(volatile hw_sdmabp_intr_t *) HW_SDMABP_INTR_ADDR)
#define HW_SDMABP_INTR_RD()      (HW_SDMABP_INTR.U)
#define HW_SDMABP_INTR_WR(v)     (HW_SDMABP_INTR.U = (v))
#define HW_SDMABP_INTR_SET(v)    (HW_SDMABP_INTR_WR(HW_SDMABP_INTR_RD() |  (v)))
#define HW_SDMABP_INTR_CLR(v)    (HW_SDMABP_INTR_WR(HW_SDMABP_INTR_RD() & ~(v)))
#define HW_SDMABP_INTR_TOG(v)    (HW_SDMABP_INTR_WR(HW_SDMABP_INTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMABP_INTR bitfields
 */

/* --- Register HW_SDMABP_INTR, field DI */

#define BP_SDMABP_INTR_DI      0
#define BM_SDMABP_INTR_DI      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_INTR_DI(v)   ((((reg32_t) v) << 0) & BM_SDMABP_INTR_DI)
#else
#define BF_SDMABP_INTR_DI(v)   (((v) << 0) & BM_SDMABP_INTR_DI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMABP_INTR_DI(v)   BF_CS1(SDMABP_INTR, DI, v)
#endif

/*
 * HW_SDMABP_STOP_STAT - Channel Stop/Channel Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DE : 32;

    } B;
} hw_sdmabp_stop_stat_t;
#endif

/*
 * constants & macros for entire SDMABP_STOP_STAT register
 */
#define HW_SDMABP_STOP_STAT_ADDR      (REGS_SDMABP_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_STOP_STAT           (*(volatile hw_sdmabp_stop_stat_t *) HW_SDMABP_STOP_STAT_ADDR)
#define HW_SDMABP_STOP_STAT_RD()      (HW_SDMABP_STOP_STAT.U)
#define HW_SDMABP_STOP_STAT_WR(v)     (HW_SDMABP_STOP_STAT.U = (v))
#define HW_SDMABP_STOP_STAT_SET(v)    (HW_SDMABP_STOP_STAT_WR(HW_SDMABP_STOP_STAT_RD() |  (v)))
#define HW_SDMABP_STOP_STAT_CLR(v)    (HW_SDMABP_STOP_STAT_WR(HW_SDMABP_STOP_STAT_RD() & ~(v)))
#define HW_SDMABP_STOP_STAT_TOG(v)    (HW_SDMABP_STOP_STAT_WR(HW_SDMABP_STOP_STAT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMABP_STOP_STAT bitfields
 */

/* --- Register HW_SDMABP_STOP_STAT, field DE */

#define BP_SDMABP_STOP_STAT_DE      0
#define BM_SDMABP_STOP_STAT_DE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_STOP_STAT_DE(v)   ((((reg32_t) v) << 0) & BM_SDMABP_STOP_STAT_DE)
#else
#define BF_SDMABP_STOP_STAT_DE(v)   (((v) << 0) & BM_SDMABP_STOP_STAT_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMABP_STOP_STAT_DE(v)   BF_CS1(SDMABP_STOP_STAT, DE, v)
#endif

/*
 * HW_SDMABP_DSTART - Channel Start
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DSTART : 32;

    } B;
} hw_sdmabp_dstart_t;
#endif

/*
 * constants & macros for entire SDMABP_DSTART register
 */
#define HW_SDMABP_DSTART_ADDR      (REGS_SDMABP_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_DSTART           (*(volatile hw_sdmabp_dstart_t *) HW_SDMABP_DSTART_ADDR)
#define HW_SDMABP_DSTART_RD()      (HW_SDMABP_DSTART.U)
#define HW_SDMABP_DSTART_WR(v)     (HW_SDMABP_DSTART.U = (v))
#define HW_SDMABP_DSTART_SET(v)    (HW_SDMABP_DSTART_WR(HW_SDMABP_DSTART_RD() |  (v)))
#define HW_SDMABP_DSTART_CLR(v)    (HW_SDMABP_DSTART_WR(HW_SDMABP_DSTART_RD() & ~(v)))
#define HW_SDMABP_DSTART_TOG(v)    (HW_SDMABP_DSTART_WR(HW_SDMABP_DSTART_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMABP_DSTART bitfields
 */

/* --- Register HW_SDMABP_DSTART, field DSTART */

#define BP_SDMABP_DSTART_DSTART      0
#define BM_SDMABP_DSTART_DSTART      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_DSTART_DSTART(v)   ((((reg32_t) v) << 0) & BM_SDMABP_DSTART_DSTART)
#else
#define BF_SDMABP_DSTART_DSTART(v)   (((v) << 0) & BM_SDMABP_DSTART_DSTART)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMABP_DSTART_DSTART(v)   BF_CS1(SDMABP_DSTART, DSTART, v)
#endif

/*
 * HW_SDMABP_EVTERR - DMA Request Error Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHNERR : 32;

    } B;
} hw_sdmabp_evterr_t;
#endif

/*
 * constants & macros for entire SDMABP_EVTERR register
 */
#define HW_SDMABP_EVTERR_ADDR      (REGS_SDMABP_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_EVTERR           (*(volatile hw_sdmabp_evterr_t *) HW_SDMABP_EVTERR_ADDR)
#define HW_SDMABP_EVTERR_RD()      (HW_SDMABP_EVTERR.U)
#define HW_SDMABP_EVTERR_WR(v)     (HW_SDMABP_EVTERR.U = (v))
#define HW_SDMABP_EVTERR_SET(v)    (HW_SDMABP_EVTERR_WR(HW_SDMABP_EVTERR_RD() |  (v)))
#define HW_SDMABP_EVTERR_CLR(v)    (HW_SDMABP_EVTERR_WR(HW_SDMABP_EVTERR_RD() & ~(v)))
#define HW_SDMABP_EVTERR_TOG(v)    (HW_SDMABP_EVTERR_WR(HW_SDMABP_EVTERR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMABP_EVTERR bitfields
 */

/* --- Register HW_SDMABP_EVTERR, field CHNERR */

#define BP_SDMABP_EVTERR_CHNERR      0
#define BM_SDMABP_EVTERR_CHNERR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_EVTERR_CHNERR(v)   ((((reg32_t) v) << 0) & BM_SDMABP_EVTERR_CHNERR)
#else
#define BF_SDMABP_EVTERR_CHNERR(v)   (((v) << 0) & BM_SDMABP_EVTERR_CHNERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMABP_EVTERR_CHNERR(v)   BF_CS1(SDMABP_EVTERR, CHNERR, v)
#endif

/*
 * HW_SDMABP_INTRMASK - Channel DSP Interrupt Mask
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DIMASK : 32;

    } B;
} hw_sdmabp_intrmask_t;
#endif

/*
 * constants & macros for entire SDMABP_INTRMASK register
 */
#define HW_SDMABP_INTRMASK_ADDR      (REGS_SDMABP_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_INTRMASK           (*(volatile hw_sdmabp_intrmask_t *) HW_SDMABP_INTRMASK_ADDR)
#define HW_SDMABP_INTRMASK_RD()      (HW_SDMABP_INTRMASK.U)
#define HW_SDMABP_INTRMASK_WR(v)     (HW_SDMABP_INTRMASK.U = (v))
#define HW_SDMABP_INTRMASK_SET(v)    (HW_SDMABP_INTRMASK_WR(HW_SDMABP_INTRMASK_RD() |  (v)))
#define HW_SDMABP_INTRMASK_CLR(v)    (HW_SDMABP_INTRMASK_WR(HW_SDMABP_INTRMASK_RD() & ~(v)))
#define HW_SDMABP_INTRMASK_TOG(v)    (HW_SDMABP_INTRMASK_WR(HW_SDMABP_INTRMASK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMABP_INTRMASK bitfields
 */

/* --- Register HW_SDMABP_INTRMASK, field DIMASK */

#define BP_SDMABP_INTRMASK_DIMASK      0
#define BM_SDMABP_INTRMASK_DIMASK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_INTRMASK_DIMASK(v)   ((((reg32_t) v) << 0) & BM_SDMABP_INTRMASK_DIMASK)
#else
#define BF_SDMABP_INTRMASK_DIMASK(v)   (((v) << 0) & BM_SDMABP_INTRMASK_DIMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMABP_INTRMASK_DIMASK(v)   BF_CS1(SDMABP_INTRMASK, DIMASK, v)
#endif

/*
 * HW_SDMABP_EVTERRDBG - DMA Request Error Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHNERR : 32;

    } B;
} hw_sdmabp_evterrdbg_t;
#endif

/*
 * constants & macros for entire SDMABP_EVTERRDBG register
 */
#define HW_SDMABP_EVTERRDBG_ADDR      (REGS_SDMABP_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_EVTERRDBG           (*(volatile hw_sdmabp_evterrdbg_t *) HW_SDMABP_EVTERRDBG_ADDR)
#define HW_SDMABP_EVTERRDBG_RD()      (HW_SDMABP_EVTERRDBG.U)
#define HW_SDMABP_EVTERRDBG_WR(v)     (HW_SDMABP_EVTERRDBG.U = (v))
#define HW_SDMABP_EVTERRDBG_SET(v)    (HW_SDMABP_EVTERRDBG_WR(HW_SDMABP_EVTERRDBG_RD() |  (v)))
#define HW_SDMABP_EVTERRDBG_CLR(v)    (HW_SDMABP_EVTERRDBG_WR(HW_SDMABP_EVTERRDBG_RD() & ~(v)))
#define HW_SDMABP_EVTERRDBG_TOG(v)    (HW_SDMABP_EVTERRDBG_WR(HW_SDMABP_EVTERRDBG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMABP_EVTERRDBG bitfields
 */

/* --- Register HW_SDMABP_EVTERRDBG, field CHNERR */

#define BP_SDMABP_EVTERRDBG_CHNERR      0
#define BM_SDMABP_EVTERRDBG_CHNERR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_EVTERRDBG_CHNERR(v)   ((((reg32_t) v) << 0) & BM_SDMABP_EVTERRDBG_CHNERR)
#else
#define BF_SDMABP_EVTERRDBG_CHNERR(v)   (((v) << 0) & BM_SDMABP_EVTERRDBG_CHNERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMABP_EVTERRDBG_CHNERR(v)   BF_CS1(SDMABP_EVTERRDBG, CHNERR, v)
#endif


#endif // _SDMABP_H

