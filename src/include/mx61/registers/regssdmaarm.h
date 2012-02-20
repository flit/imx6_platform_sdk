/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SDMAARM_H
#define _SDMAARM_H

#include "regs.h"

#ifndef REGS_SDMAARM_BASE
#define REGS_SDMAARM_BASE (REGS_BASE + 0x020ec000)

#endif


/*
 * HW_SDMAARM_MC0PTR - ARM platform Channel 0 Pointer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MC0PTR : 32;

    } B;
} hw_sdmaarm_mc0ptr_t;
#endif

/*
 * constants & macros for entire SDMAARM_MC0PTR register
 */
#define HW_SDMAARM_MC0PTR_ADDR      (REGS_SDMAARM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_MC0PTR           (*(volatile hw_sdmaarm_mc0ptr_t *) HW_SDMAARM_MC0PTR_ADDR)
#define HW_SDMAARM_MC0PTR_RD()      (HW_SDMAARM_MC0PTR.U)
#define HW_SDMAARM_MC0PTR_WR(v)     (HW_SDMAARM_MC0PTR.U = (v))
#define HW_SDMAARM_MC0PTR_SET(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() |  (v)))
#define HW_SDMAARM_MC0PTR_CLR(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() & ~(v)))
#define HW_SDMAARM_MC0PTR_TOG(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_MC0PTR bitfields
 */

/* --- Register HW_SDMAARM_MC0PTR, field MC0PTR */

#define BP_SDMAARM_MC0PTR_MC0PTR      0
#define BM_SDMAARM_MC0PTR_MC0PTR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_MC0PTR_MC0PTR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_MC0PTR_MC0PTR)
#else
#define BF_SDMAARM_MC0PTR_MC0PTR(v)   (((v) << 0) & BM_SDMAARM_MC0PTR_MC0PTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_MC0PTR_MC0PTR(v)   BF_CS1(SDMAARM_MC0PTR, MC0PTR, v)
#endif

/*
 * HW_SDMAARM_INTR - Channel Interrupts
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HI : 32;

    } B;
} hw_sdmaarm_intr_t;
#endif

/*
 * constants & macros for entire SDMAARM_INTR register
 */
#define HW_SDMAARM_INTR_ADDR      (REGS_SDMAARM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_INTR           (*(volatile hw_sdmaarm_intr_t *) HW_SDMAARM_INTR_ADDR)
#define HW_SDMAARM_INTR_RD()      (HW_SDMAARM_INTR.U)
#define HW_SDMAARM_INTR_WR(v)     (HW_SDMAARM_INTR.U = (v))
#define HW_SDMAARM_INTR_SET(v)    (HW_SDMAARM_INTR_WR(HW_SDMAARM_INTR_RD() |  (v)))
#define HW_SDMAARM_INTR_CLR(v)    (HW_SDMAARM_INTR_WR(HW_SDMAARM_INTR_RD() & ~(v)))
#define HW_SDMAARM_INTR_TOG(v)    (HW_SDMAARM_INTR_WR(HW_SDMAARM_INTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_INTR bitfields
 */

/* --- Register HW_SDMAARM_INTR, field HI */

#define BP_SDMAARM_INTR_HI      0
#define BM_SDMAARM_INTR_HI      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_INTR_HI(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_INTR_HI)
#else
#define BF_SDMAARM_INTR_HI(v)   (((v) << 0) & BM_SDMAARM_INTR_HI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_INTR_HI(v)   BF_CS1(SDMAARM_INTR, HI, v)
#endif

/*
 * HW_SDMAARM_STOP_STAT - Channel Stop/Channel Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HE : 32;

    } B;
} hw_sdmaarm_stop_stat_t;
#endif

/*
 * constants & macros for entire SDMAARM_STOP_STAT register
 */
#define HW_SDMAARM_STOP_STAT_ADDR      (REGS_SDMAARM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_STOP_STAT           (*(volatile hw_sdmaarm_stop_stat_t *) HW_SDMAARM_STOP_STAT_ADDR)
#define HW_SDMAARM_STOP_STAT_RD()      (HW_SDMAARM_STOP_STAT.U)
#define HW_SDMAARM_STOP_STAT_WR(v)     (HW_SDMAARM_STOP_STAT.U = (v))
#define HW_SDMAARM_STOP_STAT_SET(v)    (HW_SDMAARM_STOP_STAT_WR(HW_SDMAARM_STOP_STAT_RD() |  (v)))
#define HW_SDMAARM_STOP_STAT_CLR(v)    (HW_SDMAARM_STOP_STAT_WR(HW_SDMAARM_STOP_STAT_RD() & ~(v)))
#define HW_SDMAARM_STOP_STAT_TOG(v)    (HW_SDMAARM_STOP_STAT_WR(HW_SDMAARM_STOP_STAT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_STOP_STAT bitfields
 */

/* --- Register HW_SDMAARM_STOP_STAT, field HE */

#define BP_SDMAARM_STOP_STAT_HE      0
#define BM_SDMAARM_STOP_STAT_HE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_STOP_STAT_HE(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_STOP_STAT_HE)
#else
#define BF_SDMAARM_STOP_STAT_HE(v)   (((v) << 0) & BM_SDMAARM_STOP_STAT_HE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_STOP_STAT_HE(v)   BF_CS1(SDMAARM_STOP_STAT, HE, v)
#endif

/*
 * HW_SDMAARM_HSTART - Channel Start
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HSTART : 32;

    } B;
} hw_sdmaarm_hstart_t;
#endif

/*
 * constants & macros for entire SDMAARM_HSTART register
 */
#define HW_SDMAARM_HSTART_ADDR      (REGS_SDMAARM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_HSTART           (*(volatile hw_sdmaarm_hstart_t *) HW_SDMAARM_HSTART_ADDR)
#define HW_SDMAARM_HSTART_RD()      (HW_SDMAARM_HSTART.U)
#define HW_SDMAARM_HSTART_WR(v)     (HW_SDMAARM_HSTART.U = (v))
#define HW_SDMAARM_HSTART_SET(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() |  (v)))
#define HW_SDMAARM_HSTART_CLR(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() & ~(v)))
#define HW_SDMAARM_HSTART_TOG(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_HSTART bitfields
 */

/* --- Register HW_SDMAARM_HSTART, field HSTART */

#define BP_SDMAARM_HSTART_HSTART      0
#define BM_SDMAARM_HSTART_HSTART      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_HSTART_HSTART(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_HSTART_HSTART)
#else
#define BF_SDMAARM_HSTART_HSTART(v)   (((v) << 0) & BM_SDMAARM_HSTART_HSTART)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_HSTART_HSTART(v)   BF_CS1(SDMAARM_HSTART, HSTART, v)
#endif

/*
 * HW_SDMAARM_EVTOVR - Channel Event Override
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EO : 32;

    } B;
} hw_sdmaarm_evtovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTOVR register
 */
#define HW_SDMAARM_EVTOVR_ADDR      (REGS_SDMAARM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTOVR           (*(volatile hw_sdmaarm_evtovr_t *) HW_SDMAARM_EVTOVR_ADDR)
#define HW_SDMAARM_EVTOVR_RD()      (HW_SDMAARM_EVTOVR.U)
#define HW_SDMAARM_EVTOVR_WR(v)     (HW_SDMAARM_EVTOVR.U = (v))
#define HW_SDMAARM_EVTOVR_SET(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() |  (v)))
#define HW_SDMAARM_EVTOVR_CLR(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() & ~(v)))
#define HW_SDMAARM_EVTOVR_TOG(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_EVTOVR bitfields
 */

/* --- Register HW_SDMAARM_EVTOVR, field EO */

#define BP_SDMAARM_EVTOVR_EO      0
#define BM_SDMAARM_EVTOVR_EO      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_EVTOVR_EO(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_EVTOVR_EO)
#else
#define BF_SDMAARM_EVTOVR_EO(v)   (((v) << 0) & BM_SDMAARM_EVTOVR_EO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_EVTOVR_EO(v)   BF_CS1(SDMAARM_EVTOVR, EO, v)
#endif

/*
 * HW_SDMAARM_DSPOVR - Channel BP Override
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DO : 32;

    } B;
} hw_sdmaarm_dspovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_DSPOVR register
 */
#define HW_SDMAARM_DSPOVR_ADDR      (REGS_SDMAARM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_DSPOVR           (*(volatile hw_sdmaarm_dspovr_t *) HW_SDMAARM_DSPOVR_ADDR)
#define HW_SDMAARM_DSPOVR_RD()      (HW_SDMAARM_DSPOVR.U)
#define HW_SDMAARM_DSPOVR_WR(v)     (HW_SDMAARM_DSPOVR.U = (v))
#define HW_SDMAARM_DSPOVR_SET(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() |  (v)))
#define HW_SDMAARM_DSPOVR_CLR(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() & ~(v)))
#define HW_SDMAARM_DSPOVR_TOG(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_DSPOVR bitfields
 */

/* --- Register HW_SDMAARM_DSPOVR, field DO */

#define BP_SDMAARM_DSPOVR_DO      0
#define BM_SDMAARM_DSPOVR_DO      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_DSPOVR_DO(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_DSPOVR_DO)
#else
#define BF_SDMAARM_DSPOVR_DO(v)   (((v) << 0) & BM_SDMAARM_DSPOVR_DO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_DSPOVR_DO(v)   BF_CS1(SDMAARM_DSPOVR, DO, v)
#endif

/*
 * HW_SDMAARM_HOSTOVR - Channel ARM platform Override
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HO : 32;

    } B;
} hw_sdmaarm_hostovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_HOSTOVR register
 */
#define HW_SDMAARM_HOSTOVR_ADDR      (REGS_SDMAARM_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_HOSTOVR           (*(volatile hw_sdmaarm_hostovr_t *) HW_SDMAARM_HOSTOVR_ADDR)
#define HW_SDMAARM_HOSTOVR_RD()      (HW_SDMAARM_HOSTOVR.U)
#define HW_SDMAARM_HOSTOVR_WR(v)     (HW_SDMAARM_HOSTOVR.U = (v))
#define HW_SDMAARM_HOSTOVR_SET(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() |  (v)))
#define HW_SDMAARM_HOSTOVR_CLR(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() & ~(v)))
#define HW_SDMAARM_HOSTOVR_TOG(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_HOSTOVR bitfields
 */

/* --- Register HW_SDMAARM_HOSTOVR, field HO */

#define BP_SDMAARM_HOSTOVR_HO      0
#define BM_SDMAARM_HOSTOVR_HO      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_HOSTOVR_HO(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_HOSTOVR_HO)
#else
#define BF_SDMAARM_HOSTOVR_HO(v)   (((v) << 0) & BM_SDMAARM_HOSTOVR_HO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_HOSTOVR_HO(v)   BF_CS1(SDMAARM_HOSTOVR, HO, v)
#endif

/*
 * HW_SDMAARM_EVTPEND - Channel Event Pending
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EP : 32;

    } B;
} hw_sdmaarm_evtpend_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTPEND register
 */
#define HW_SDMAARM_EVTPEND_ADDR      (REGS_SDMAARM_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTPEND           (*(volatile hw_sdmaarm_evtpend_t *) HW_SDMAARM_EVTPEND_ADDR)
#define HW_SDMAARM_EVTPEND_RD()      (HW_SDMAARM_EVTPEND.U)
#define HW_SDMAARM_EVTPEND_WR(v)     (HW_SDMAARM_EVTPEND.U = (v))
#define HW_SDMAARM_EVTPEND_SET(v)    (HW_SDMAARM_EVTPEND_WR(HW_SDMAARM_EVTPEND_RD() |  (v)))
#define HW_SDMAARM_EVTPEND_CLR(v)    (HW_SDMAARM_EVTPEND_WR(HW_SDMAARM_EVTPEND_RD() & ~(v)))
#define HW_SDMAARM_EVTPEND_TOG(v)    (HW_SDMAARM_EVTPEND_WR(HW_SDMAARM_EVTPEND_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_EVTPEND bitfields
 */

/* --- Register HW_SDMAARM_EVTPEND, field EP */

#define BP_SDMAARM_EVTPEND_EP      0
#define BM_SDMAARM_EVTPEND_EP      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_EVTPEND_EP(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_EVTPEND_EP)
#else
#define BF_SDMAARM_EVTPEND_EP(v)   (((v) << 0) & BM_SDMAARM_EVTPEND_EP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_EVTPEND_EP(v)   BF_CS1(SDMAARM_EVTPEND, EP, v)
#endif

/*
 * HW_SDMAARM_DSPENBL - DSP (BP) Channel Enable
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DE : 32;

    } B;
} hw_sdmaarm_dspenbl_t;
#endif

/*
 * constants & macros for entire SDMAARM_DSPENBL register
 */
#define HW_SDMAARM_DSPENBL_ADDR      (REGS_SDMAARM_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_DSPENBL           (*(volatile hw_sdmaarm_dspenbl_t *) HW_SDMAARM_DSPENBL_ADDR)
#define HW_SDMAARM_DSPENBL_RD()      (HW_SDMAARM_DSPENBL.U)
#define HW_SDMAARM_DSPENBL_WR(v)     (HW_SDMAARM_DSPENBL.U = (v))
#define HW_SDMAARM_DSPENBL_SET(v)    (HW_SDMAARM_DSPENBL_WR(HW_SDMAARM_DSPENBL_RD() |  (v)))
#define HW_SDMAARM_DSPENBL_CLR(v)    (HW_SDMAARM_DSPENBL_WR(HW_SDMAARM_DSPENBL_RD() & ~(v)))
#define HW_SDMAARM_DSPENBL_TOG(v)    (HW_SDMAARM_DSPENBL_WR(HW_SDMAARM_DSPENBL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_DSPENBL bitfields
 */

/* --- Register HW_SDMAARM_DSPENBL, field DE */

#define BP_SDMAARM_DSPENBL_DE      0
#define BM_SDMAARM_DSPENBL_DE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_DSPENBL_DE(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_DSPENBL_DE)
#else
#define BF_SDMAARM_DSPENBL_DE(v)   (((v) << 0) & BM_SDMAARM_DSPENBL_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_DSPENBL_DE(v)   BF_CS1(SDMAARM_DSPENBL, DE, v)
#endif

/*
 * HW_SDMAARM_RESET - Reset Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 30;
        unsigned RESCHED : 1;
        unsigned RESET : 1;

    } B;
} hw_sdmaarm_reset_t;
#endif

/*
 * constants & macros for entire SDMAARM_RESET register
 */
#define HW_SDMAARM_RESET_ADDR      (REGS_SDMAARM_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_RESET           (*(volatile hw_sdmaarm_reset_t *) HW_SDMAARM_RESET_ADDR)
#define HW_SDMAARM_RESET_RD()      (HW_SDMAARM_RESET.U)
#define HW_SDMAARM_RESET_WR(v)     (HW_SDMAARM_RESET.U = (v))
#define HW_SDMAARM_RESET_SET(v)    (HW_SDMAARM_RESET_WR(HW_SDMAARM_RESET_RD() |  (v)))
#define HW_SDMAARM_RESET_CLR(v)    (HW_SDMAARM_RESET_WR(HW_SDMAARM_RESET_RD() & ~(v)))
#define HW_SDMAARM_RESET_TOG(v)    (HW_SDMAARM_RESET_WR(HW_SDMAARM_RESET_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_RESET bitfields
 */

/* --- Register HW_SDMAARM_RESET, field RESCHED */

#define BP_SDMAARM_RESET_RESCHED      1
#define BM_SDMAARM_RESET_RESCHED      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_RESET_RESCHED(v)   ((((reg32_t) v) << 1) & BM_SDMAARM_RESET_RESCHED)
#else
#define BF_SDMAARM_RESET_RESCHED(v)   (((v) << 1) & BM_SDMAARM_RESET_RESCHED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_RESET_RESCHED(v)   BF_CS1(SDMAARM_RESET, RESCHED, v)
#endif

/* --- Register HW_SDMAARM_RESET, field RESET */

#define BP_SDMAARM_RESET_RESET      0
#define BM_SDMAARM_RESET_RESET      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_RESET_RESET(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_RESET_RESET)
#else
#define BF_SDMAARM_RESET_RESET(v)   (((v) << 0) & BM_SDMAARM_RESET_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_RESET_RESET(v)   BF_CS1(SDMAARM_RESET, RESET, v)
#endif

/*
 * HW_SDMAARM_EVTERR - DMA Request Error Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHNERR : 32;

    } B;
} hw_sdmaarm_evterr_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTERR register
 */
#define HW_SDMAARM_EVTERR_ADDR      (REGS_SDMAARM_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTERR           (*(volatile hw_sdmaarm_evterr_t *) HW_SDMAARM_EVTERR_ADDR)
#define HW_SDMAARM_EVTERR_RD()      (HW_SDMAARM_EVTERR.U)
#define HW_SDMAARM_EVTERR_WR(v)     (HW_SDMAARM_EVTERR.U = (v))
#define HW_SDMAARM_EVTERR_SET(v)    (HW_SDMAARM_EVTERR_WR(HW_SDMAARM_EVTERR_RD() |  (v)))
#define HW_SDMAARM_EVTERR_CLR(v)    (HW_SDMAARM_EVTERR_WR(HW_SDMAARM_EVTERR_RD() & ~(v)))
#define HW_SDMAARM_EVTERR_TOG(v)    (HW_SDMAARM_EVTERR_WR(HW_SDMAARM_EVTERR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_EVTERR bitfields
 */

/* --- Register HW_SDMAARM_EVTERR, field CHNERR */

#define BP_SDMAARM_EVTERR_CHNERR      0
#define BM_SDMAARM_EVTERR_CHNERR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_EVTERR_CHNERR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_EVTERR_CHNERR)
#else
#define BF_SDMAARM_EVTERR_CHNERR(v)   (((v) << 0) & BM_SDMAARM_EVTERR_CHNERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_EVTERR_CHNERR(v)   BF_CS1(SDMAARM_EVTERR, CHNERR, v)
#endif

/*
 * HW_SDMAARM_INTRMASK - Channel ARM platform Interrupt Mask
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HIMASK : 32;

    } B;
} hw_sdmaarm_intrmask_t;
#endif

/*
 * constants & macros for entire SDMAARM_INTRMASK register
 */
#define HW_SDMAARM_INTRMASK_ADDR      (REGS_SDMAARM_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_INTRMASK           (*(volatile hw_sdmaarm_intrmask_t *) HW_SDMAARM_INTRMASK_ADDR)
#define HW_SDMAARM_INTRMASK_RD()      (HW_SDMAARM_INTRMASK.U)
#define HW_SDMAARM_INTRMASK_WR(v)     (HW_SDMAARM_INTRMASK.U = (v))
#define HW_SDMAARM_INTRMASK_SET(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() |  (v)))
#define HW_SDMAARM_INTRMASK_CLR(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() & ~(v)))
#define HW_SDMAARM_INTRMASK_TOG(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_INTRMASK bitfields
 */

/* --- Register HW_SDMAARM_INTRMASK, field HIMASK */

#define BP_SDMAARM_INTRMASK_HIMASK      0
#define BM_SDMAARM_INTRMASK_HIMASK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_INTRMASK_HIMASK(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_INTRMASK_HIMASK)
#else
#define BF_SDMAARM_INTRMASK_HIMASK(v)   (((v) << 0) & BM_SDMAARM_INTRMASK_HIMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_INTRMASK_HIMASK(v)   BF_CS1(SDMAARM_INTRMASK, HIMASK, v)
#endif

/*
 * HW_SDMAARM_PSW - Schedule Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned NCP : 3;
        unsigned NCR : 5;
        unsigned CCP : 4;
        unsigned CCR : 4;

    } B;
} hw_sdmaarm_psw_t;
#endif

/*
 * constants & macros for entire SDMAARM_PSW register
 */
#define HW_SDMAARM_PSW_ADDR      (REGS_SDMAARM_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_PSW           (*(volatile hw_sdmaarm_psw_t *) HW_SDMAARM_PSW_ADDR)
#define HW_SDMAARM_PSW_RD()      (HW_SDMAARM_PSW.U)
#define HW_SDMAARM_PSW_WR(v)     (HW_SDMAARM_PSW.U = (v))
#define HW_SDMAARM_PSW_SET(v)    (HW_SDMAARM_PSW_WR(HW_SDMAARM_PSW_RD() |  (v)))
#define HW_SDMAARM_PSW_CLR(v)    (HW_SDMAARM_PSW_WR(HW_SDMAARM_PSW_RD() & ~(v)))
#define HW_SDMAARM_PSW_TOG(v)    (HW_SDMAARM_PSW_WR(HW_SDMAARM_PSW_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_PSW bitfields
 */

/* --- Register HW_SDMAARM_PSW, field NCP */

#define BP_SDMAARM_PSW_NCP      13
#define BM_SDMAARM_PSW_NCP      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PSW_NCP(v)   ((((reg32_t) v) << 13) & BM_SDMAARM_PSW_NCP)
#else
#define BF_SDMAARM_PSW_NCP(v)   (((v) << 13) & BM_SDMAARM_PSW_NCP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PSW_NCP(v)   BF_CS1(SDMAARM_PSW, NCP, v)
#endif

/* --- Register HW_SDMAARM_PSW, field NCR */

#define BP_SDMAARM_PSW_NCR      8
#define BM_SDMAARM_PSW_NCR      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PSW_NCR(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_PSW_NCR)
#else
#define BF_SDMAARM_PSW_NCR(v)   (((v) << 8) & BM_SDMAARM_PSW_NCR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PSW_NCR(v)   BF_CS1(SDMAARM_PSW, NCR, v)
#endif

/* --- Register HW_SDMAARM_PSW, field CCP */

#define BP_SDMAARM_PSW_CCP      4
#define BM_SDMAARM_PSW_CCP      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PSW_CCP(v)   ((((reg32_t) v) << 4) & BM_SDMAARM_PSW_CCP)
#else
#define BF_SDMAARM_PSW_CCP(v)   (((v) << 4) & BM_SDMAARM_PSW_CCP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PSW_CCP(v)   BF_CS1(SDMAARM_PSW, CCP, v)
#endif

/* --- Register HW_SDMAARM_PSW, field CCR */

#define BP_SDMAARM_PSW_CCR      0
#define BM_SDMAARM_PSW_CCR      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PSW_CCR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_PSW_CCR)
#else
#define BF_SDMAARM_PSW_CCR(v)   (((v) << 0) & BM_SDMAARM_PSW_CCR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PSW_CCR(v)   BF_CS1(SDMAARM_PSW, CCR, v)
#endif

/*
 * HW_SDMAARM_EVTERRDBG - DMA Request Error Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHNERR : 32;

    } B;
} hw_sdmaarm_evterrdbg_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTERRDBG register
 */
#define HW_SDMAARM_EVTERRDBG_ADDR      (REGS_SDMAARM_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTERRDBG           (*(volatile hw_sdmaarm_evterrdbg_t *) HW_SDMAARM_EVTERRDBG_ADDR)
#define HW_SDMAARM_EVTERRDBG_RD()      (HW_SDMAARM_EVTERRDBG.U)
#define HW_SDMAARM_EVTERRDBG_WR(v)     (HW_SDMAARM_EVTERRDBG.U = (v))
#define HW_SDMAARM_EVTERRDBG_SET(v)    (HW_SDMAARM_EVTERRDBG_WR(HW_SDMAARM_EVTERRDBG_RD() |  (v)))
#define HW_SDMAARM_EVTERRDBG_CLR(v)    (HW_SDMAARM_EVTERRDBG_WR(HW_SDMAARM_EVTERRDBG_RD() & ~(v)))
#define HW_SDMAARM_EVTERRDBG_TOG(v)    (HW_SDMAARM_EVTERRDBG_WR(HW_SDMAARM_EVTERRDBG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_EVTERRDBG bitfields
 */

/* --- Register HW_SDMAARM_EVTERRDBG, field CHNERR */

#define BP_SDMAARM_EVTERRDBG_CHNERR      0
#define BM_SDMAARM_EVTERRDBG_CHNERR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_EVTERRDBG_CHNERR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_EVTERRDBG_CHNERR)
#else
#define BF_SDMAARM_EVTERRDBG_CHNERR(v)   (((v) << 0) & BM_SDMAARM_EVTERRDBG_CHNERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_EVTERRDBG_CHNERR(v)   BF_CS1(SDMAARM_EVTERRDBG, CHNERR, v)
#endif

/*
 * HW_SDMAARM_CONFIG - Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 19;
        unsigned DSPDMA : 1;
        unsigned DSPDMA : 1;
        unsigned DSPCTRL : 1;
        unsigned DSPCTRL : 1;
        unsigned RTDOBS : 1;
        unsigned RESERVED1 : 6;
        unsigned ACR : 1;
        unsigned RESERVED2 : 2;
        unsigned CSM : 2;

    } B;
} hw_sdmaarm_config_t;
#endif

/*
 * constants & macros for entire SDMAARM_CONFIG register
 */
#define HW_SDMAARM_CONFIG_ADDR      (REGS_SDMAARM_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_CONFIG           (*(volatile hw_sdmaarm_config_t *) HW_SDMAARM_CONFIG_ADDR)
#define HW_SDMAARM_CONFIG_RD()      (HW_SDMAARM_CONFIG.U)
#define HW_SDMAARM_CONFIG_WR(v)     (HW_SDMAARM_CONFIG.U = (v))
#define HW_SDMAARM_CONFIG_SET(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() |  (v)))
#define HW_SDMAARM_CONFIG_CLR(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() & ~(v)))
#define HW_SDMAARM_CONFIG_TOG(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_CONFIG bitfields
 */

/* --- Register HW_SDMAARM_CONFIG, field DSPDMA */

#define BP_SDMAARM_CONFIG_DSPDMA      12
#define BM_SDMAARM_CONFIG_DSPDMA      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_DSPDMA(v)   ((((reg32_t) v) << 12) & BM_SDMAARM_CONFIG_DSPDMA)
#else
#define BF_SDMAARM_CONFIG_DSPDMA(v)   (((v) << 12) & BM_SDMAARM_CONFIG_DSPDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CONFIG_DSPDMA(v)   BF_CS1(SDMAARM_CONFIG, DSPDMA, v)
#endif

/* --- Register HW_SDMAARM_CONFIG, field DSPDMA */

#define BP_SDMAARM_CONFIG_DSPDMA      12
#define BM_SDMAARM_CONFIG_DSPDMA      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_DSPDMA(v)   ((((reg32_t) v) << 12) & BM_SDMAARM_CONFIG_DSPDMA)
#else
#define BF_SDMAARM_CONFIG_DSPDMA(v)   (((v) << 12) & BM_SDMAARM_CONFIG_DSPDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CONFIG_DSPDMA(v)   BF_CS1(SDMAARM_CONFIG, DSPDMA, v)
#endif

/* --- Register HW_SDMAARM_CONFIG, field DSPCTRL */

#define BP_SDMAARM_CONFIG_DSPCTRL      12
#define BM_SDMAARM_CONFIG_DSPCTRL      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_DSPCTRL(v)   ((((reg32_t) v) << 12) & BM_SDMAARM_CONFIG_DSPCTRL)
#else
#define BF_SDMAARM_CONFIG_DSPCTRL(v)   (((v) << 12) & BM_SDMAARM_CONFIG_DSPCTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CONFIG_DSPCTRL(v)   BF_CS1(SDMAARM_CONFIG, DSPCTRL, v)
#endif

/* --- Register HW_SDMAARM_CONFIG, field DSPCTRL */

#define BP_SDMAARM_CONFIG_DSPCTRL      12
#define BM_SDMAARM_CONFIG_DSPCTRL      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_DSPCTRL(v)   ((((reg32_t) v) << 12) & BM_SDMAARM_CONFIG_DSPCTRL)
#else
#define BF_SDMAARM_CONFIG_DSPCTRL(v)   (((v) << 12) & BM_SDMAARM_CONFIG_DSPCTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CONFIG_DSPCTRL(v)   BF_CS1(SDMAARM_CONFIG, DSPCTRL, v)
#endif

/* --- Register HW_SDMAARM_CONFIG, field RTDOBS */

#define BP_SDMAARM_CONFIG_RTDOBS      11
#define BM_SDMAARM_CONFIG_RTDOBS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_RTDOBS(v)   ((((reg32_t) v) << 11) & BM_SDMAARM_CONFIG_RTDOBS)
#else
#define BF_SDMAARM_CONFIG_RTDOBS(v)   (((v) << 11) & BM_SDMAARM_CONFIG_RTDOBS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CONFIG_RTDOBS(v)   BF_CS1(SDMAARM_CONFIG, RTDOBS, v)
#endif

/* --- Register HW_SDMAARM_CONFIG, field ACR */

#define BP_SDMAARM_CONFIG_ACR      4
#define BM_SDMAARM_CONFIG_ACR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_ACR(v)   ((((reg32_t) v) << 4) & BM_SDMAARM_CONFIG_ACR)
#else
#define BF_SDMAARM_CONFIG_ACR(v)   (((v) << 4) & BM_SDMAARM_CONFIG_ACR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CONFIG_ACR(v)   BF_CS1(SDMAARM_CONFIG, ACR, v)
#endif

/* --- Register HW_SDMAARM_CONFIG, field CSM */

#define BP_SDMAARM_CONFIG_CSM      0
#define BM_SDMAARM_CONFIG_CSM      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_CSM(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_CONFIG_CSM)
#else
#define BF_SDMAARM_CONFIG_CSM(v)   (((v) << 0) & BM_SDMAARM_CONFIG_CSM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CONFIG_CSM(v)   BF_CS1(SDMAARM_CONFIG, CSM, v)
#endif

/*
 * HW_SDMAARM_SDMA_LOCK - SDMA LOCK
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 30;
        unsigned SRESET_LOCK_CLR : 1;
        unsigned LOCK : 1;

    } B;
} hw_sdmaarm_sdma_lock_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_LOCK register
 */
#define HW_SDMAARM_SDMA_LOCK_ADDR      (REGS_SDMAARM_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_LOCK           (*(volatile hw_sdmaarm_sdma_lock_t *) HW_SDMAARM_SDMA_LOCK_ADDR)
#define HW_SDMAARM_SDMA_LOCK_RD()      (HW_SDMAARM_SDMA_LOCK.U)
#define HW_SDMAARM_SDMA_LOCK_WR(v)     (HW_SDMAARM_SDMA_LOCK.U = (v))
#define HW_SDMAARM_SDMA_LOCK_SET(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() |  (v)))
#define HW_SDMAARM_SDMA_LOCK_CLR(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() & ~(v)))
#define HW_SDMAARM_SDMA_LOCK_TOG(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_SDMA_LOCK bitfields
 */

/* --- Register HW_SDMAARM_SDMA_LOCK, field SRESET_LOCK_CLR */

#define BP_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR      1
#define BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   ((((reg32_t) v) << 1) & BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR)
#else
#define BF_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   (((v) << 1) & BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   BF_CS1(SDMAARM_SDMA_LOCK, SRESET_LOCK_CLR, v)
#endif

/* --- Register HW_SDMAARM_SDMA_LOCK, field LOCK */

#define BP_SDMAARM_SDMA_LOCK_LOCK      0
#define BM_SDMAARM_SDMA_LOCK_LOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_SDMA_LOCK_LOCK(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_SDMA_LOCK_LOCK)
#else
#define BF_SDMAARM_SDMA_LOCK_LOCK(v)   (((v) << 0) & BM_SDMAARM_SDMA_LOCK_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_SDMA_LOCK_LOCK(v)   BF_CS1(SDMAARM_SDMA_LOCK, LOCK, v)
#endif

/*
 * HW_SDMAARM_ONCE_ENB - OnCE Enable
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned ENB : 1;

    } B;
} hw_sdmaarm_once_enb_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_ENB register
 */
#define HW_SDMAARM_ONCE_ENB_ADDR      (REGS_SDMAARM_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_ENB           (*(volatile hw_sdmaarm_once_enb_t *) HW_SDMAARM_ONCE_ENB_ADDR)
#define HW_SDMAARM_ONCE_ENB_RD()      (HW_SDMAARM_ONCE_ENB.U)
#define HW_SDMAARM_ONCE_ENB_WR(v)     (HW_SDMAARM_ONCE_ENB.U = (v))
#define HW_SDMAARM_ONCE_ENB_SET(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() |  (v)))
#define HW_SDMAARM_ONCE_ENB_CLR(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() & ~(v)))
#define HW_SDMAARM_ONCE_ENB_TOG(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_ONCE_ENB bitfields
 */

/* --- Register HW_SDMAARM_ONCE_ENB, field ENB */

#define BP_SDMAARM_ONCE_ENB_ENB      0
#define BM_SDMAARM_ONCE_ENB_ENB      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_ENB_ENB(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_ENB_ENB)
#else
#define BF_SDMAARM_ONCE_ENB_ENB(v)   (((v) << 0) & BM_SDMAARM_ONCE_ENB_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_ENB_ENB(v)   BF_CS1(SDMAARM_ONCE_ENB, ENB, v)
#endif

/*
 * HW_SDMAARM_ONCE_DATA - OnCE Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATA : 32;

    } B;
} hw_sdmaarm_once_data_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_DATA register
 */
#define HW_SDMAARM_ONCE_DATA_ADDR      (REGS_SDMAARM_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_DATA           (*(volatile hw_sdmaarm_once_data_t *) HW_SDMAARM_ONCE_DATA_ADDR)
#define HW_SDMAARM_ONCE_DATA_RD()      (HW_SDMAARM_ONCE_DATA.U)
#define HW_SDMAARM_ONCE_DATA_WR(v)     (HW_SDMAARM_ONCE_DATA.U = (v))
#define HW_SDMAARM_ONCE_DATA_SET(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() |  (v)))
#define HW_SDMAARM_ONCE_DATA_CLR(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() & ~(v)))
#define HW_SDMAARM_ONCE_DATA_TOG(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_ONCE_DATA bitfields
 */

/* --- Register HW_SDMAARM_ONCE_DATA, field DATA */

#define BP_SDMAARM_ONCE_DATA_DATA      0
#define BM_SDMAARM_ONCE_DATA_DATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_DATA_DATA(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_DATA_DATA)
#else
#define BF_SDMAARM_ONCE_DATA_DATA(v)   (((v) << 0) & BM_SDMAARM_ONCE_DATA_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_DATA_DATA(v)   BF_CS1(SDMAARM_ONCE_DATA, DATA, v)
#endif

/*
 * HW_SDMAARM_ONCE_INSTR - OnCE Instruction Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned INSTR : 16;

    } B;
} hw_sdmaarm_once_instr_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_INSTR register
 */
#define HW_SDMAARM_ONCE_INSTR_ADDR      (REGS_SDMAARM_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_INSTR           (*(volatile hw_sdmaarm_once_instr_t *) HW_SDMAARM_ONCE_INSTR_ADDR)
#define HW_SDMAARM_ONCE_INSTR_RD()      (HW_SDMAARM_ONCE_INSTR.U)
#define HW_SDMAARM_ONCE_INSTR_WR(v)     (HW_SDMAARM_ONCE_INSTR.U = (v))
#define HW_SDMAARM_ONCE_INSTR_SET(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() |  (v)))
#define HW_SDMAARM_ONCE_INSTR_CLR(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() & ~(v)))
#define HW_SDMAARM_ONCE_INSTR_TOG(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_ONCE_INSTR bitfields
 */

/* --- Register HW_SDMAARM_ONCE_INSTR, field INSTR */

#define BP_SDMAARM_ONCE_INSTR_INSTR      0
#define BM_SDMAARM_ONCE_INSTR_INSTR      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_INSTR_INSTR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_INSTR_INSTR)
#else
#define BF_SDMAARM_ONCE_INSTR_INSTR(v)   (((v) << 0) & BM_SDMAARM_ONCE_INSTR_INSTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_INSTR_INSTR(v)   BF_CS1(SDMAARM_ONCE_INSTR, INSTR, v)
#endif

/*
 * HW_SDMAARM_ONCE_STAT - OnCE Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned PST : 4;
        unsigned RCV : 1;
        unsigned EDR : 1;
        unsigned ODR : 1;
        unsigned SWB : 1;
        unsigned MST : 1;
        unsigned RESERVED1 : 4;
        unsigned ECDR : 3;

    } B;
} hw_sdmaarm_once_stat_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_STAT register
 */
#define HW_SDMAARM_ONCE_STAT_ADDR      (REGS_SDMAARM_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_STAT           (*(volatile hw_sdmaarm_once_stat_t *) HW_SDMAARM_ONCE_STAT_ADDR)
#define HW_SDMAARM_ONCE_STAT_RD()      (HW_SDMAARM_ONCE_STAT.U)
#define HW_SDMAARM_ONCE_STAT_WR(v)     (HW_SDMAARM_ONCE_STAT.U = (v))
#define HW_SDMAARM_ONCE_STAT_SET(v)    (HW_SDMAARM_ONCE_STAT_WR(HW_SDMAARM_ONCE_STAT_RD() |  (v)))
#define HW_SDMAARM_ONCE_STAT_CLR(v)    (HW_SDMAARM_ONCE_STAT_WR(HW_SDMAARM_ONCE_STAT_RD() & ~(v)))
#define HW_SDMAARM_ONCE_STAT_TOG(v)    (HW_SDMAARM_ONCE_STAT_WR(HW_SDMAARM_ONCE_STAT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_ONCE_STAT bitfields
 */

/* --- Register HW_SDMAARM_ONCE_STAT, field PST */

#define BP_SDMAARM_ONCE_STAT_PST      12
#define BM_SDMAARM_ONCE_STAT_PST      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_STAT_PST(v)   ((((reg32_t) v) << 12) & BM_SDMAARM_ONCE_STAT_PST)
#else
#define BF_SDMAARM_ONCE_STAT_PST(v)   (((v) << 12) & BM_SDMAARM_ONCE_STAT_PST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_STAT_PST(v)   BF_CS1(SDMAARM_ONCE_STAT, PST, v)
#endif

/* --- Register HW_SDMAARM_ONCE_STAT, field RCV */

#define BP_SDMAARM_ONCE_STAT_RCV      11
#define BM_SDMAARM_ONCE_STAT_RCV      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_STAT_RCV(v)   ((((reg32_t) v) << 11) & BM_SDMAARM_ONCE_STAT_RCV)
#else
#define BF_SDMAARM_ONCE_STAT_RCV(v)   (((v) << 11) & BM_SDMAARM_ONCE_STAT_RCV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_STAT_RCV(v)   BF_CS1(SDMAARM_ONCE_STAT, RCV, v)
#endif

/* --- Register HW_SDMAARM_ONCE_STAT, field EDR */

#define BP_SDMAARM_ONCE_STAT_EDR      10
#define BM_SDMAARM_ONCE_STAT_EDR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_STAT_EDR(v)   ((((reg32_t) v) << 10) & BM_SDMAARM_ONCE_STAT_EDR)
#else
#define BF_SDMAARM_ONCE_STAT_EDR(v)   (((v) << 10) & BM_SDMAARM_ONCE_STAT_EDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_STAT_EDR(v)   BF_CS1(SDMAARM_ONCE_STAT, EDR, v)
#endif

/* --- Register HW_SDMAARM_ONCE_STAT, field ODR */

#define BP_SDMAARM_ONCE_STAT_ODR      9
#define BM_SDMAARM_ONCE_STAT_ODR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_STAT_ODR(v)   ((((reg32_t) v) << 9) & BM_SDMAARM_ONCE_STAT_ODR)
#else
#define BF_SDMAARM_ONCE_STAT_ODR(v)   (((v) << 9) & BM_SDMAARM_ONCE_STAT_ODR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_STAT_ODR(v)   BF_CS1(SDMAARM_ONCE_STAT, ODR, v)
#endif

/* --- Register HW_SDMAARM_ONCE_STAT, field SWB */

#define BP_SDMAARM_ONCE_STAT_SWB      8
#define BM_SDMAARM_ONCE_STAT_SWB      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_STAT_SWB(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_ONCE_STAT_SWB)
#else
#define BF_SDMAARM_ONCE_STAT_SWB(v)   (((v) << 8) & BM_SDMAARM_ONCE_STAT_SWB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_STAT_SWB(v)   BF_CS1(SDMAARM_ONCE_STAT, SWB, v)
#endif

/* --- Register HW_SDMAARM_ONCE_STAT, field MST */

#define BP_SDMAARM_ONCE_STAT_MST      7
#define BM_SDMAARM_ONCE_STAT_MST      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_STAT_MST(v)   ((((reg32_t) v) << 7) & BM_SDMAARM_ONCE_STAT_MST)
#else
#define BF_SDMAARM_ONCE_STAT_MST(v)   (((v) << 7) & BM_SDMAARM_ONCE_STAT_MST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_STAT_MST(v)   BF_CS1(SDMAARM_ONCE_STAT, MST, v)
#endif

/* --- Register HW_SDMAARM_ONCE_STAT, field ECDR */

#define BP_SDMAARM_ONCE_STAT_ECDR      0
#define BM_SDMAARM_ONCE_STAT_ECDR      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_STAT_ECDR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_STAT_ECDR)
#else
#define BF_SDMAARM_ONCE_STAT_ECDR(v)   (((v) << 0) & BM_SDMAARM_ONCE_STAT_ECDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_STAT_ECDR(v)   BF_CS1(SDMAARM_ONCE_STAT, ECDR, v)
#endif

/*
 * HW_SDMAARM_ONCE_CMD - OnCE Command Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 28;
        unsigned CMD : 4;

    } B;
} hw_sdmaarm_once_cmd_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_CMD register
 */
#define HW_SDMAARM_ONCE_CMD_ADDR      (REGS_SDMAARM_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_CMD           (*(volatile hw_sdmaarm_once_cmd_t *) HW_SDMAARM_ONCE_CMD_ADDR)
#define HW_SDMAARM_ONCE_CMD_RD()      (HW_SDMAARM_ONCE_CMD.U)
#define HW_SDMAARM_ONCE_CMD_WR(v)     (HW_SDMAARM_ONCE_CMD.U = (v))
#define HW_SDMAARM_ONCE_CMD_SET(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() |  (v)))
#define HW_SDMAARM_ONCE_CMD_CLR(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() & ~(v)))
#define HW_SDMAARM_ONCE_CMD_TOG(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_ONCE_CMD bitfields
 */

/* --- Register HW_SDMAARM_ONCE_CMD, field CMD */

#define BP_SDMAARM_ONCE_CMD_CMD      0
#define BM_SDMAARM_ONCE_CMD_CMD      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_CMD_CMD(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_CMD_CMD)
#else
#define BF_SDMAARM_ONCE_CMD_CMD(v)   (((v) << 0) & BM_SDMAARM_ONCE_CMD_CMD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ONCE_CMD_CMD(v)   BF_CS1(SDMAARM_ONCE_CMD, CMD, v)
#endif

/*
 * HW_SDMAARM_EVT_MIRROR - DMA Requests
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EVENTS : 32;

    } B;
} hw_sdmaarm_evt_mirror_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVT_MIRROR register
 */
#define HW_SDMAARM_EVT_MIRROR_ADDR      (REGS_SDMAARM_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVT_MIRROR           (*(volatile hw_sdmaarm_evt_mirror_t *) HW_SDMAARM_EVT_MIRROR_ADDR)
#define HW_SDMAARM_EVT_MIRROR_RD()      (HW_SDMAARM_EVT_MIRROR.U)
#define HW_SDMAARM_EVT_MIRROR_WR(v)     (HW_SDMAARM_EVT_MIRROR.U = (v))
#define HW_SDMAARM_EVT_MIRROR_SET(v)    (HW_SDMAARM_EVT_MIRROR_WR(HW_SDMAARM_EVT_MIRROR_RD() |  (v)))
#define HW_SDMAARM_EVT_MIRROR_CLR(v)    (HW_SDMAARM_EVT_MIRROR_WR(HW_SDMAARM_EVT_MIRROR_RD() & ~(v)))
#define HW_SDMAARM_EVT_MIRROR_TOG(v)    (HW_SDMAARM_EVT_MIRROR_WR(HW_SDMAARM_EVT_MIRROR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_EVT_MIRROR bitfields
 */

/* --- Register HW_SDMAARM_EVT_MIRROR, field EVENTS */

#define BP_SDMAARM_EVT_MIRROR_EVENTS      0
#define BM_SDMAARM_EVT_MIRROR_EVENTS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_EVT_MIRROR_EVENTS(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_EVT_MIRROR_EVENTS)
#else
#define BF_SDMAARM_EVT_MIRROR_EVENTS(v)   (((v) << 0) & BM_SDMAARM_EVT_MIRROR_EVENTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_EVT_MIRROR_EVENTS(v)   BF_CS1(SDMAARM_EVT_MIRROR, EVENTS, v)
#endif

/*
 * HW_SDMAARM_ILLINSTADDR - Illegal Instruction Trap Address
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 18;
        unsigned ILLINSTADDR : 14;

    } B;
} hw_sdmaarm_illinstaddr_t;
#endif

/*
 * constants & macros for entire SDMAARM_ILLINSTADDR register
 */
#define HW_SDMAARM_ILLINSTADDR_ADDR      (REGS_SDMAARM_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ILLINSTADDR           (*(volatile hw_sdmaarm_illinstaddr_t *) HW_SDMAARM_ILLINSTADDR_ADDR)
#define HW_SDMAARM_ILLINSTADDR_RD()      (HW_SDMAARM_ILLINSTADDR.U)
#define HW_SDMAARM_ILLINSTADDR_WR(v)     (HW_SDMAARM_ILLINSTADDR.U = (v))
#define HW_SDMAARM_ILLINSTADDR_SET(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() |  (v)))
#define HW_SDMAARM_ILLINSTADDR_CLR(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() & ~(v)))
#define HW_SDMAARM_ILLINSTADDR_TOG(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_ILLINSTADDR bitfields
 */

/* --- Register HW_SDMAARM_ILLINSTADDR, field ILLINSTADDR */

#define BP_SDMAARM_ILLINSTADDR_ILLINSTADDR      0
#define BM_SDMAARM_ILLINSTADDR_ILLINSTADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ILLINSTADDR_ILLINSTADDR)
#else
#define BF_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   (((v) << 0) & BM_SDMAARM_ILLINSTADDR_ILLINSTADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   BF_CS1(SDMAARM_ILLINSTADDR, ILLINSTADDR, v)
#endif

/*
 * HW_SDMAARM_CHN0ADDR - Channel 0 Boot Address
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 17;
        unsigned SMSZ : 1;
        unsigned CHN0ADDR : 14;

    } B;
} hw_sdmaarm_chn0addr_t;
#endif

/*
 * constants & macros for entire SDMAARM_CHN0ADDR register
 */
#define HW_SDMAARM_CHN0ADDR_ADDR      (REGS_SDMAARM_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_CHN0ADDR           (*(volatile hw_sdmaarm_chn0addr_t *) HW_SDMAARM_CHN0ADDR_ADDR)
#define HW_SDMAARM_CHN0ADDR_RD()      (HW_SDMAARM_CHN0ADDR.U)
#define HW_SDMAARM_CHN0ADDR_WR(v)     (HW_SDMAARM_CHN0ADDR.U = (v))
#define HW_SDMAARM_CHN0ADDR_SET(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() |  (v)))
#define HW_SDMAARM_CHN0ADDR_CLR(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() & ~(v)))
#define HW_SDMAARM_CHN0ADDR_TOG(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_CHN0ADDR bitfields
 */

/* --- Register HW_SDMAARM_CHN0ADDR, field SMSZ */

#define BP_SDMAARM_CHN0ADDR_SMSZ      14
#define BM_SDMAARM_CHN0ADDR_SMSZ      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CHN0ADDR_SMSZ(v)   ((((reg32_t) v) << 14) & BM_SDMAARM_CHN0ADDR_SMSZ)
#else
#define BF_SDMAARM_CHN0ADDR_SMSZ(v)   (((v) << 14) & BM_SDMAARM_CHN0ADDR_SMSZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CHN0ADDR_SMSZ(v)   BF_CS1(SDMAARM_CHN0ADDR, SMSZ, v)
#endif

/* --- Register HW_SDMAARM_CHN0ADDR, field CHN0ADDR */

#define BP_SDMAARM_CHN0ADDR_CHN0ADDR      0
#define BM_SDMAARM_CHN0ADDR_CHN0ADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CHN0ADDR_CHN0ADDR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_CHN0ADDR_CHN0ADDR)
#else
#define BF_SDMAARM_CHN0ADDR_CHN0ADDR(v)   (((v) << 0) & BM_SDMAARM_CHN0ADDR_CHN0ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CHN0ADDR_CHN0ADDR(v)   BF_CS1(SDMAARM_CHN0ADDR, CHN0ADDR, v)
#endif

/*
 * HW_SDMAARM_EVT_MIRROR - DMA Requests
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EVENTS : 32;

    } B;
} hw_sdmaarm_evt_mirror_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVT_MIRROR register
 */
#define HW_SDMAARM_EVT_MIRROR_ADDR      (REGS_SDMAARM_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVT_MIRROR           (*(volatile hw_sdmaarm_evt_mirror_t *) HW_SDMAARM_EVT_MIRROR_ADDR)
#define HW_SDMAARM_EVT_MIRROR_RD()      (HW_SDMAARM_EVT_MIRROR.U)
#define HW_SDMAARM_EVT_MIRROR_WR(v)     (HW_SDMAARM_EVT_MIRROR.U = (v))
#define HW_SDMAARM_EVT_MIRROR_SET(v)    (HW_SDMAARM_EVT_MIRROR_WR(HW_SDMAARM_EVT_MIRROR_RD() |  (v)))
#define HW_SDMAARM_EVT_MIRROR_CLR(v)    (HW_SDMAARM_EVT_MIRROR_WR(HW_SDMAARM_EVT_MIRROR_RD() & ~(v)))
#define HW_SDMAARM_EVT_MIRROR_TOG(v)    (HW_SDMAARM_EVT_MIRROR_WR(HW_SDMAARM_EVT_MIRROR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_EVT_MIRROR bitfields
 */

/* --- Register HW_SDMAARM_EVT_MIRROR, field EVENTS */

#define BP_SDMAARM_EVT_MIRROR_EVENTS      0
#define BM_SDMAARM_EVT_MIRROR_EVENTS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_EVT_MIRROR_EVENTS(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_EVT_MIRROR_EVENTS)
#else
#define BF_SDMAARM_EVT_MIRROR_EVENTS(v)   (((v) << 0) & BM_SDMAARM_EVT_MIRROR_EVENTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_EVT_MIRROR_EVENTS(v)   BF_CS1(SDMAARM_EVT_MIRROR, EVENTS, v)
#endif

/*
 * HW_SDMAARM_EVT_MIRROR2 - DMA Requests 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned EVENTS : 16;

    } B;
} hw_sdmaarm_evt_mirror2_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVT_MIRROR2 register
 */
#define HW_SDMAARM_EVT_MIRROR2_ADDR      (REGS_SDMAARM_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVT_MIRROR2           (*(volatile hw_sdmaarm_evt_mirror2_t *) HW_SDMAARM_EVT_MIRROR2_ADDR)
#define HW_SDMAARM_EVT_MIRROR2_RD()      (HW_SDMAARM_EVT_MIRROR2.U)
#define HW_SDMAARM_EVT_MIRROR2_WR(v)     (HW_SDMAARM_EVT_MIRROR2.U = (v))
#define HW_SDMAARM_EVT_MIRROR2_SET(v)    (HW_SDMAARM_EVT_MIRROR2_WR(HW_SDMAARM_EVT_MIRROR2_RD() |  (v)))
#define HW_SDMAARM_EVT_MIRROR2_CLR(v)    (HW_SDMAARM_EVT_MIRROR2_WR(HW_SDMAARM_EVT_MIRROR2_RD() & ~(v)))
#define HW_SDMAARM_EVT_MIRROR2_TOG(v)    (HW_SDMAARM_EVT_MIRROR2_WR(HW_SDMAARM_EVT_MIRROR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_EVT_MIRROR2 bitfields
 */

/* --- Register HW_SDMAARM_EVT_MIRROR2, field EVENTS */

#define BP_SDMAARM_EVT_MIRROR2_EVENTS      0
#define BM_SDMAARM_EVT_MIRROR2_EVENTS      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_EVT_MIRROR2_EVENTS(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_EVT_MIRROR2_EVENTS)
#else
#define BF_SDMAARM_EVT_MIRROR2_EVENTS(v)   (((v) << 0) & BM_SDMAARM_EVT_MIRROR2_EVENTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_EVT_MIRROR2_EVENTS(v)   BF_CS1(SDMAARM_EVT_MIRROR2, EVENTS, v)
#endif

/*
 * HW_SDMAARM_XTRIG_CONF1 - Cross-Trigger Events Configuration Register
                        1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1;
        unsigned CNF3 : 1;
        unsigned RESERVED1 : 1;
        unsigned NUM3 : 5;
        unsigned NUM3 : 6;
        unsigned RESERVED2 : 1;
        unsigned CNF2 : 1;
        unsigned RESERVED3 : 1;
        unsigned NUM2 : 6;
        unsigned NUM2 : 5;
        unsigned RESERVED4 : 1;
        unsigned CNF1 : 1;
        unsigned RESERVED5 : 1;
        unsigned NUM1 : 5;
        unsigned NUM1 : 6;
        unsigned RESERVED6 : 1;
        unsigned CNF0 : 1;
        unsigned RESERVED7 : 1;
        unsigned NUM0 : 5;
        unsigned NUM0 : 6;

    } B;
} hw_sdmaarm_xtrig_conf1_t;
#endif

/*
 * constants & macros for entire SDMAARM_XTRIG_CONF1 register
 */
#define HW_SDMAARM_XTRIG_CONF1_ADDR      (REGS_SDMAARM_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_XTRIG_CONF1           (*(volatile hw_sdmaarm_xtrig_conf1_t *) HW_SDMAARM_XTRIG_CONF1_ADDR)
#define HW_SDMAARM_XTRIG_CONF1_RD()      (HW_SDMAARM_XTRIG_CONF1.U)
#define HW_SDMAARM_XTRIG_CONF1_WR(v)     (HW_SDMAARM_XTRIG_CONF1.U = (v))
#define HW_SDMAARM_XTRIG_CONF1_SET(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() |  (v)))
#define HW_SDMAARM_XTRIG_CONF1_CLR(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() & ~(v)))
#define HW_SDMAARM_XTRIG_CONF1_TOG(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_XTRIG_CONF1 bitfields
 */

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF3 */

#define BP_SDMAARM_XTRIG_CONF1_CNF3      30
#define BM_SDMAARM_XTRIG_CONF1_CNF3      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_CNF3(v)   ((((reg32_t) v) << 30) & BM_SDMAARM_XTRIG_CONF1_CNF3)
#else
#define BF_SDMAARM_XTRIG_CONF1_CNF3(v)   (((v) << 30) & BM_SDMAARM_XTRIG_CONF1_CNF3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_CNF3(v)   BF_CS1(SDMAARM_XTRIG_CONF1, CNF3, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM3 */

#define BP_SDMAARM_XTRIG_CONF1_NUM3      24
#define BM_SDMAARM_XTRIG_CONF1_NUM3      0x1f000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM3(v)   ((((reg32_t) v) << 24) & BM_SDMAARM_XTRIG_CONF1_NUM3)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM3(v)   (((v) << 24) & BM_SDMAARM_XTRIG_CONF1_NUM3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_NUM3(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM3, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM3 */

#define BP_SDMAARM_XTRIG_CONF1_NUM3      24
#define BM_SDMAARM_XTRIG_CONF1_NUM3      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM3(v)   ((((reg32_t) v) << 24) & BM_SDMAARM_XTRIG_CONF1_NUM3)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM3(v)   (((v) << 24) & BM_SDMAARM_XTRIG_CONF1_NUM3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_NUM3(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM3, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF2 */

#define BP_SDMAARM_XTRIG_CONF1_CNF2      22
#define BM_SDMAARM_XTRIG_CONF1_CNF2      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_CNF2(v)   ((((reg32_t) v) << 22) & BM_SDMAARM_XTRIG_CONF1_CNF2)
#else
#define BF_SDMAARM_XTRIG_CONF1_CNF2(v)   (((v) << 22) & BM_SDMAARM_XTRIG_CONF1_CNF2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_CNF2(v)   BF_CS1(SDMAARM_XTRIG_CONF1, CNF2, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM2 */

#define BP_SDMAARM_XTRIG_CONF1_NUM2      16
#define BM_SDMAARM_XTRIG_CONF1_NUM2      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM2(v)   ((((reg32_t) v) << 16) & BM_SDMAARM_XTRIG_CONF1_NUM2)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM2(v)   (((v) << 16) & BM_SDMAARM_XTRIG_CONF1_NUM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_NUM2(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM2, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM2 */

#define BP_SDMAARM_XTRIG_CONF1_NUM2      16
#define BM_SDMAARM_XTRIG_CONF1_NUM2      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM2(v)   ((((reg32_t) v) << 16) & BM_SDMAARM_XTRIG_CONF1_NUM2)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM2(v)   (((v) << 16) & BM_SDMAARM_XTRIG_CONF1_NUM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_NUM2(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM2, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF1 */

#define BP_SDMAARM_XTRIG_CONF1_CNF1      14
#define BM_SDMAARM_XTRIG_CONF1_CNF1      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_CNF1(v)   ((((reg32_t) v) << 14) & BM_SDMAARM_XTRIG_CONF1_CNF1)
#else
#define BF_SDMAARM_XTRIG_CONF1_CNF1(v)   (((v) << 14) & BM_SDMAARM_XTRIG_CONF1_CNF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_CNF1(v)   BF_CS1(SDMAARM_XTRIG_CONF1, CNF1, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM1 */

#define BP_SDMAARM_XTRIG_CONF1_NUM1      8
#define BM_SDMAARM_XTRIG_CONF1_NUM1      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM1(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_XTRIG_CONF1_NUM1)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM1(v)   (((v) << 8) & BM_SDMAARM_XTRIG_CONF1_NUM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_NUM1(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM1, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM1 */

#define BP_SDMAARM_XTRIG_CONF1_NUM1      8
#define BM_SDMAARM_XTRIG_CONF1_NUM1      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM1(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_XTRIG_CONF1_NUM1)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM1(v)   (((v) << 8) & BM_SDMAARM_XTRIG_CONF1_NUM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_NUM1(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM1, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF0 */

#define BP_SDMAARM_XTRIG_CONF1_CNF0      6
#define BM_SDMAARM_XTRIG_CONF1_CNF0      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_CNF0(v)   ((((reg32_t) v) << 6) & BM_SDMAARM_XTRIG_CONF1_CNF0)
#else
#define BF_SDMAARM_XTRIG_CONF1_CNF0(v)   (((v) << 6) & BM_SDMAARM_XTRIG_CONF1_CNF0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_CNF0(v)   BF_CS1(SDMAARM_XTRIG_CONF1, CNF0, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM0 */

#define BP_SDMAARM_XTRIG_CONF1_NUM0      0
#define BM_SDMAARM_XTRIG_CONF1_NUM0      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM0(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_XTRIG_CONF1_NUM0)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM0(v)   (((v) << 0) & BM_SDMAARM_XTRIG_CONF1_NUM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_NUM0(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM0, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM0 */

#define BP_SDMAARM_XTRIG_CONF1_NUM0      0
#define BM_SDMAARM_XTRIG_CONF1_NUM0      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM0(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_XTRIG_CONF1_NUM0)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM0(v)   (((v) << 0) & BM_SDMAARM_XTRIG_CONF1_NUM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF1_NUM0(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM0, v)
#endif

/*
 * HW_SDMAARM_XTRIG_CONF2 - Cross-Trigger Events Configuration Register
                        2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1;
        unsigned CNF7 : 1;
        unsigned RESERVED1 : 1;
        unsigned NUM7 : 5;
        unsigned NUM7 : 6;
        unsigned RESERVED2 : 1;
        unsigned CNF6 : 1;
        unsigned RESERVED3 : 1;
        unsigned NUM6 : 5;
        unsigned NUM6 : 6;
        unsigned RESERVED4 : 1;
        unsigned CNF5 : 1;
        unsigned RESERVED5 : 1;
        unsigned NUM5 : 5;
        unsigned NUM5 : 6;
        unsigned RESERVED6 : 1;
        unsigned CNF4 : 1;
        unsigned RESERVED7 : 1;
        unsigned NUM4 : 5;
        unsigned NUM4 : 6;

    } B;
} hw_sdmaarm_xtrig_conf2_t;
#endif

/*
 * constants & macros for entire SDMAARM_XTRIG_CONF2 register
 */
#define HW_SDMAARM_XTRIG_CONF2_ADDR      (REGS_SDMAARM_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_XTRIG_CONF2           (*(volatile hw_sdmaarm_xtrig_conf2_t *) HW_SDMAARM_XTRIG_CONF2_ADDR)
#define HW_SDMAARM_XTRIG_CONF2_RD()      (HW_SDMAARM_XTRIG_CONF2.U)
#define HW_SDMAARM_XTRIG_CONF2_WR(v)     (HW_SDMAARM_XTRIG_CONF2.U = (v))
#define HW_SDMAARM_XTRIG_CONF2_SET(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() |  (v)))
#define HW_SDMAARM_XTRIG_CONF2_CLR(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() & ~(v)))
#define HW_SDMAARM_XTRIG_CONF2_TOG(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_XTRIG_CONF2 bitfields
 */

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF7 */

#define BP_SDMAARM_XTRIG_CONF2_CNF7      30
#define BM_SDMAARM_XTRIG_CONF2_CNF7      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_CNF7(v)   ((((reg32_t) v) << 30) & BM_SDMAARM_XTRIG_CONF2_CNF7)
#else
#define BF_SDMAARM_XTRIG_CONF2_CNF7(v)   (((v) << 30) & BM_SDMAARM_XTRIG_CONF2_CNF7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_CNF7(v)   BF_CS1(SDMAARM_XTRIG_CONF2, CNF7, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM7 */

#define BP_SDMAARM_XTRIG_CONF2_NUM7      24
#define BM_SDMAARM_XTRIG_CONF2_NUM7      0x1f000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM7(v)   ((((reg32_t) v) << 24) & BM_SDMAARM_XTRIG_CONF2_NUM7)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM7(v)   (((v) << 24) & BM_SDMAARM_XTRIG_CONF2_NUM7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_NUM7(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM7, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM7 */

#define BP_SDMAARM_XTRIG_CONF2_NUM7      24
#define BM_SDMAARM_XTRIG_CONF2_NUM7      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM7(v)   ((((reg32_t) v) << 24) & BM_SDMAARM_XTRIG_CONF2_NUM7)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM7(v)   (((v) << 24) & BM_SDMAARM_XTRIG_CONF2_NUM7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_NUM7(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM7, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF6 */

#define BP_SDMAARM_XTRIG_CONF2_CNF6      22
#define BM_SDMAARM_XTRIG_CONF2_CNF6      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_CNF6(v)   ((((reg32_t) v) << 22) & BM_SDMAARM_XTRIG_CONF2_CNF6)
#else
#define BF_SDMAARM_XTRIG_CONF2_CNF6(v)   (((v) << 22) & BM_SDMAARM_XTRIG_CONF2_CNF6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_CNF6(v)   BF_CS1(SDMAARM_XTRIG_CONF2, CNF6, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM6 */

#define BP_SDMAARM_XTRIG_CONF2_NUM6      16
#define BM_SDMAARM_XTRIG_CONF2_NUM6      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM6(v)   ((((reg32_t) v) << 16) & BM_SDMAARM_XTRIG_CONF2_NUM6)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM6(v)   (((v) << 16) & BM_SDMAARM_XTRIG_CONF2_NUM6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_NUM6(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM6, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM6 */

#define BP_SDMAARM_XTRIG_CONF2_NUM6      16
#define BM_SDMAARM_XTRIG_CONF2_NUM6      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM6(v)   ((((reg32_t) v) << 16) & BM_SDMAARM_XTRIG_CONF2_NUM6)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM6(v)   (((v) << 16) & BM_SDMAARM_XTRIG_CONF2_NUM6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_NUM6(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM6, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF5 */

#define BP_SDMAARM_XTRIG_CONF2_CNF5      14
#define BM_SDMAARM_XTRIG_CONF2_CNF5      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_CNF5(v)   ((((reg32_t) v) << 14) & BM_SDMAARM_XTRIG_CONF2_CNF5)
#else
#define BF_SDMAARM_XTRIG_CONF2_CNF5(v)   (((v) << 14) & BM_SDMAARM_XTRIG_CONF2_CNF5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_CNF5(v)   BF_CS1(SDMAARM_XTRIG_CONF2, CNF5, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM5 */

#define BP_SDMAARM_XTRIG_CONF2_NUM5      8
#define BM_SDMAARM_XTRIG_CONF2_NUM5      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM5(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_XTRIG_CONF2_NUM5)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM5(v)   (((v) << 8) & BM_SDMAARM_XTRIG_CONF2_NUM5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_NUM5(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM5, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM5 */

#define BP_SDMAARM_XTRIG_CONF2_NUM5      8
#define BM_SDMAARM_XTRIG_CONF2_NUM5      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM5(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_XTRIG_CONF2_NUM5)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM5(v)   (((v) << 8) & BM_SDMAARM_XTRIG_CONF2_NUM5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_NUM5(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM5, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF4 */

#define BP_SDMAARM_XTRIG_CONF2_CNF4      6
#define BM_SDMAARM_XTRIG_CONF2_CNF4      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_CNF4(v)   ((((reg32_t) v) << 6) & BM_SDMAARM_XTRIG_CONF2_CNF4)
#else
#define BF_SDMAARM_XTRIG_CONF2_CNF4(v)   (((v) << 6) & BM_SDMAARM_XTRIG_CONF2_CNF4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_CNF4(v)   BF_CS1(SDMAARM_XTRIG_CONF2, CNF4, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM4 */

#define BP_SDMAARM_XTRIG_CONF2_NUM4      0
#define BM_SDMAARM_XTRIG_CONF2_NUM4      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM4(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_XTRIG_CONF2_NUM4)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM4(v)   (((v) << 0) & BM_SDMAARM_XTRIG_CONF2_NUM4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_NUM4(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM4, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM4 */

#define BP_SDMAARM_XTRIG_CONF2_NUM4      0
#define BM_SDMAARM_XTRIG_CONF2_NUM4      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM4(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_XTRIG_CONF2_NUM4)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM4(v)   (((v) << 0) & BM_SDMAARM_XTRIG_CONF2_NUM4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_XTRIG_CONF2_NUM4(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM4, v)
#endif

/*
 * HW_SDMAARM_OTB - Once Trace Buffer Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 3;
        unsigned TBF : 1;
        unsigned TADDR : 14;
        unsigned CHFADDR : 14;

    } B;
} hw_sdmaarm_otb_t;
#endif

/*
 * constants & macros for entire SDMAARM_OTB register
 */
#define HW_SDMAARM_OTB_ADDR      (REGS_SDMAARM_BASE + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_OTB           (*(volatile hw_sdmaarm_otb_t *) HW_SDMAARM_OTB_ADDR)
#define HW_SDMAARM_OTB_RD()      (HW_SDMAARM_OTB.U)
#define HW_SDMAARM_OTB_WR(v)     (HW_SDMAARM_OTB.U = (v))
#define HW_SDMAARM_OTB_SET(v)    (HW_SDMAARM_OTB_WR(HW_SDMAARM_OTB_RD() |  (v)))
#define HW_SDMAARM_OTB_CLR(v)    (HW_SDMAARM_OTB_WR(HW_SDMAARM_OTB_RD() & ~(v)))
#define HW_SDMAARM_OTB_TOG(v)    (HW_SDMAARM_OTB_WR(HW_SDMAARM_OTB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_OTB bitfields
 */

/* --- Register HW_SDMAARM_OTB, field TBF */

#define BP_SDMAARM_OTB_TBF      28
#define BM_SDMAARM_OTB_TBF      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_OTB_TBF(v)   ((((reg32_t) v) << 28) & BM_SDMAARM_OTB_TBF)
#else
#define BF_SDMAARM_OTB_TBF(v)   (((v) << 28) & BM_SDMAARM_OTB_TBF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_OTB_TBF(v)   BF_CS1(SDMAARM_OTB, TBF, v)
#endif

/* --- Register HW_SDMAARM_OTB, field TADDR */

#define BP_SDMAARM_OTB_TADDR      14
#define BM_SDMAARM_OTB_TADDR      0x0fffc000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_OTB_TADDR(v)   ((((reg32_t) v) << 14) & BM_SDMAARM_OTB_TADDR)
#else
#define BF_SDMAARM_OTB_TADDR(v)   (((v) << 14) & BM_SDMAARM_OTB_TADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_OTB_TADDR(v)   BF_CS1(SDMAARM_OTB, TADDR, v)
#endif

/* --- Register HW_SDMAARM_OTB, field CHFADDR */

#define BP_SDMAARM_OTB_CHFADDR      0
#define BM_SDMAARM_OTB_CHFADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_OTB_CHFADDR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_OTB_CHFADDR)
#else
#define BF_SDMAARM_OTB_CHFADDR(v)   (((v) << 0) & BM_SDMAARM_OTB_CHFADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_OTB_CHFADDR(v)   BF_CS1(SDMAARM_OTB, CHFADDR, v)
#endif

/*
 * HW_SDMAARM_PRF_CNT_ - Profile Counter Registers
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNTER_CONFIG : 9;
        unsigned OFL : 1;
        unsigned COUNTER : 22;

    } B;
} hw_sdmaarm_prf_cnt__t;
#endif

/*
 * constants & macros for entire SDMAARM_PRF_CNT_ register
 */
#define HW_SDMAARM_PRF_CNT__ADDR      (REGS_SDMAARM_BASE + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_PRF_CNT_           (*(volatile hw_sdmaarm_prf_cnt__t *) HW_SDMAARM_PRF_CNT__ADDR)
#define HW_SDMAARM_PRF_CNT__RD()      (HW_SDMAARM_PRF_CNT_.U)
#define HW_SDMAARM_PRF_CNT__WR(v)     (HW_SDMAARM_PRF_CNT_.U = (v))
#define HW_SDMAARM_PRF_CNT__SET(v)    (HW_SDMAARM_PRF_CNT__WR(HW_SDMAARM_PRF_CNT__RD() |  (v)))
#define HW_SDMAARM_PRF_CNT__CLR(v)    (HW_SDMAARM_PRF_CNT__WR(HW_SDMAARM_PRF_CNT__RD() & ~(v)))
#define HW_SDMAARM_PRF_CNT__TOG(v)    (HW_SDMAARM_PRF_CNT__WR(HW_SDMAARM_PRF_CNT__RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_PRF_CNT_ bitfields
 */

/* --- Register HW_SDMAARM_PRF_CNT_, field COUNTER_CONFIG */

#define BP_SDMAARM_PRF_CNT__COUNTER_CONFIG      23
#define BM_SDMAARM_PRF_CNT__COUNTER_CONFIG      0xff800000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CNT__COUNTER_CONFIG(v)   ((((reg32_t) v) << 23) & BM_SDMAARM_PRF_CNT__COUNTER_CONFIG)
#else
#define BF_SDMAARM_PRF_CNT__COUNTER_CONFIG(v)   (((v) << 23) & BM_SDMAARM_PRF_CNT__COUNTER_CONFIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CNT__COUNTER_CONFIG(v)   BF_CS1(SDMAARM_PRF_CNT_, COUNTER_CONFIG, v)
#endif

/* --- Register HW_SDMAARM_PRF_CNT_, field OFL */

#define BP_SDMAARM_PRF_CNT__OFL      22
#define BM_SDMAARM_PRF_CNT__OFL      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CNT__OFL(v)   ((((reg32_t) v) << 22) & BM_SDMAARM_PRF_CNT__OFL)
#else
#define BF_SDMAARM_PRF_CNT__OFL(v)   (((v) << 22) & BM_SDMAARM_PRF_CNT__OFL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CNT__OFL(v)   BF_CS1(SDMAARM_PRF_CNT_, OFL, v)
#endif

/* --- Register HW_SDMAARM_PRF_CNT_, field COUNTER */

#define BP_SDMAARM_PRF_CNT__COUNTER      0
#define BM_SDMAARM_PRF_CNT__COUNTER      0x003fffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CNT__COUNTER(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_PRF_CNT__COUNTER)
#else
#define BF_SDMAARM_PRF_CNT__COUNTER(v)   (((v) << 0) & BM_SDMAARM_PRF_CNT__COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CNT__COUNTER(v)   BF_CS1(SDMAARM_PRF_CNT_, COUNTER, v)
#endif

/*
 * HW_SDMAARM_PRF_CFG - Profile config/status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 18;
        unsigned ISR : 1;
        unsigned OFL6 : 1;
        unsigned OFL5 : 1;
        unsigned OFL4 : 1;
        unsigned OFL3 : 1;
        unsigned OFL2 : 1;
        unsigned OFL1 : 1;
        unsigned INT_EN_6 : 1;
        unsigned INT_EN_5 : 1;
        unsigned INT_EN_4 : 1;
        unsigned INT_EN_3 : 1;
        unsigned INT_EN_2 : 1;
        unsigned INT_EN_1 : 1;
        unsigned EN : 1;

    } B;
} hw_sdmaarm_prf_cfg_t;
#endif

/*
 * constants & macros for entire SDMAARM_PRF_CFG register
 */
#define HW_SDMAARM_PRF_CFG_ADDR      (REGS_SDMAARM_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_PRF_CFG           (*(volatile hw_sdmaarm_prf_cfg_t *) HW_SDMAARM_PRF_CFG_ADDR)
#define HW_SDMAARM_PRF_CFG_RD()      (HW_SDMAARM_PRF_CFG.U)
#define HW_SDMAARM_PRF_CFG_WR(v)     (HW_SDMAARM_PRF_CFG.U = (v))
#define HW_SDMAARM_PRF_CFG_SET(v)    (HW_SDMAARM_PRF_CFG_WR(HW_SDMAARM_PRF_CFG_RD() |  (v)))
#define HW_SDMAARM_PRF_CFG_CLR(v)    (HW_SDMAARM_PRF_CFG_WR(HW_SDMAARM_PRF_CFG_RD() & ~(v)))
#define HW_SDMAARM_PRF_CFG_TOG(v)    (HW_SDMAARM_PRF_CFG_WR(HW_SDMAARM_PRF_CFG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_PRF_CFG bitfields
 */

/* --- Register HW_SDMAARM_PRF_CFG, field ISR */

#define BP_SDMAARM_PRF_CFG_ISR      13
#define BM_SDMAARM_PRF_CFG_ISR      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_ISR(v)   ((((reg32_t) v) << 13) & BM_SDMAARM_PRF_CFG_ISR)
#else
#define BF_SDMAARM_PRF_CFG_ISR(v)   (((v) << 13) & BM_SDMAARM_PRF_CFG_ISR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_ISR(v)   BF_CS1(SDMAARM_PRF_CFG, ISR, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field OFL6 */

#define BP_SDMAARM_PRF_CFG_OFL6      12
#define BM_SDMAARM_PRF_CFG_OFL6      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_OFL6(v)   ((((reg32_t) v) << 12) & BM_SDMAARM_PRF_CFG_OFL6)
#else
#define BF_SDMAARM_PRF_CFG_OFL6(v)   (((v) << 12) & BM_SDMAARM_PRF_CFG_OFL6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_OFL6(v)   BF_CS1(SDMAARM_PRF_CFG, OFL6, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field OFL5 */

#define BP_SDMAARM_PRF_CFG_OFL5      11
#define BM_SDMAARM_PRF_CFG_OFL5      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_OFL5(v)   ((((reg32_t) v) << 11) & BM_SDMAARM_PRF_CFG_OFL5)
#else
#define BF_SDMAARM_PRF_CFG_OFL5(v)   (((v) << 11) & BM_SDMAARM_PRF_CFG_OFL5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_OFL5(v)   BF_CS1(SDMAARM_PRF_CFG, OFL5, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field OFL4 */

#define BP_SDMAARM_PRF_CFG_OFL4      10
#define BM_SDMAARM_PRF_CFG_OFL4      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_OFL4(v)   ((((reg32_t) v) << 10) & BM_SDMAARM_PRF_CFG_OFL4)
#else
#define BF_SDMAARM_PRF_CFG_OFL4(v)   (((v) << 10) & BM_SDMAARM_PRF_CFG_OFL4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_OFL4(v)   BF_CS1(SDMAARM_PRF_CFG, OFL4, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field OFL3 */

#define BP_SDMAARM_PRF_CFG_OFL3      9
#define BM_SDMAARM_PRF_CFG_OFL3      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_OFL3(v)   ((((reg32_t) v) << 9) & BM_SDMAARM_PRF_CFG_OFL3)
#else
#define BF_SDMAARM_PRF_CFG_OFL3(v)   (((v) << 9) & BM_SDMAARM_PRF_CFG_OFL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_OFL3(v)   BF_CS1(SDMAARM_PRF_CFG, OFL3, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field OFL2 */

#define BP_SDMAARM_PRF_CFG_OFL2      8
#define BM_SDMAARM_PRF_CFG_OFL2      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_OFL2(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_PRF_CFG_OFL2)
#else
#define BF_SDMAARM_PRF_CFG_OFL2(v)   (((v) << 8) & BM_SDMAARM_PRF_CFG_OFL2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_OFL2(v)   BF_CS1(SDMAARM_PRF_CFG, OFL2, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field OFL1 */

#define BP_SDMAARM_PRF_CFG_OFL1      7
#define BM_SDMAARM_PRF_CFG_OFL1      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_OFL1(v)   ((((reg32_t) v) << 7) & BM_SDMAARM_PRF_CFG_OFL1)
#else
#define BF_SDMAARM_PRF_CFG_OFL1(v)   (((v) << 7) & BM_SDMAARM_PRF_CFG_OFL1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_OFL1(v)   BF_CS1(SDMAARM_PRF_CFG, OFL1, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field INT_EN_6 */

#define BP_SDMAARM_PRF_CFG_INT_EN_6      6
#define BM_SDMAARM_PRF_CFG_INT_EN_6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_INT_EN_6(v)   ((((reg32_t) v) << 6) & BM_SDMAARM_PRF_CFG_INT_EN_6)
#else
#define BF_SDMAARM_PRF_CFG_INT_EN_6(v)   (((v) << 6) & BM_SDMAARM_PRF_CFG_INT_EN_6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_INT_EN_6(v)   BF_CS1(SDMAARM_PRF_CFG, INT_EN_6, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field INT_EN_5 */

#define BP_SDMAARM_PRF_CFG_INT_EN_5      5
#define BM_SDMAARM_PRF_CFG_INT_EN_5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_INT_EN_5(v)   ((((reg32_t) v) << 5) & BM_SDMAARM_PRF_CFG_INT_EN_5)
#else
#define BF_SDMAARM_PRF_CFG_INT_EN_5(v)   (((v) << 5) & BM_SDMAARM_PRF_CFG_INT_EN_5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_INT_EN_5(v)   BF_CS1(SDMAARM_PRF_CFG, INT_EN_5, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field INT_EN_4 */

#define BP_SDMAARM_PRF_CFG_INT_EN_4      4
#define BM_SDMAARM_PRF_CFG_INT_EN_4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_INT_EN_4(v)   ((((reg32_t) v) << 4) & BM_SDMAARM_PRF_CFG_INT_EN_4)
#else
#define BF_SDMAARM_PRF_CFG_INT_EN_4(v)   (((v) << 4) & BM_SDMAARM_PRF_CFG_INT_EN_4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_INT_EN_4(v)   BF_CS1(SDMAARM_PRF_CFG, INT_EN_4, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field INT_EN_3 */

#define BP_SDMAARM_PRF_CFG_INT_EN_3      3
#define BM_SDMAARM_PRF_CFG_INT_EN_3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_INT_EN_3(v)   ((((reg32_t) v) << 3) & BM_SDMAARM_PRF_CFG_INT_EN_3)
#else
#define BF_SDMAARM_PRF_CFG_INT_EN_3(v)   (((v) << 3) & BM_SDMAARM_PRF_CFG_INT_EN_3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_INT_EN_3(v)   BF_CS1(SDMAARM_PRF_CFG, INT_EN_3, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field INT_EN_2 */

#define BP_SDMAARM_PRF_CFG_INT_EN_2      2
#define BM_SDMAARM_PRF_CFG_INT_EN_2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_INT_EN_2(v)   ((((reg32_t) v) << 2) & BM_SDMAARM_PRF_CFG_INT_EN_2)
#else
#define BF_SDMAARM_PRF_CFG_INT_EN_2(v)   (((v) << 2) & BM_SDMAARM_PRF_CFG_INT_EN_2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_INT_EN_2(v)   BF_CS1(SDMAARM_PRF_CFG, INT_EN_2, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field INT_EN_1 */

#define BP_SDMAARM_PRF_CFG_INT_EN_1      1
#define BM_SDMAARM_PRF_CFG_INT_EN_1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_INT_EN_1(v)   ((((reg32_t) v) << 1) & BM_SDMAARM_PRF_CFG_INT_EN_1)
#else
#define BF_SDMAARM_PRF_CFG_INT_EN_1(v)   (((v) << 1) & BM_SDMAARM_PRF_CFG_INT_EN_1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_INT_EN_1(v)   BF_CS1(SDMAARM_PRF_CFG, INT_EN_1, v)
#endif

/* --- Register HW_SDMAARM_PRF_CFG, field EN */

#define BP_SDMAARM_PRF_CFG_EN      0
#define BM_SDMAARM_PRF_CFG_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_PRF_CFG_EN(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_PRF_CFG_EN)
#else
#define BF_SDMAARM_PRF_CFG_EN(v)   (((v) << 0) & BM_SDMAARM_PRF_CFG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_PRF_CFG_EN(v)   BF_CS1(SDMAARM_PRF_CFG, EN, v)
#endif

/*
 * HW_SDMAARM_CHNENBL - Channel Enable RAM
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ENBLN : 32;

    } B;
} hw_sdmaarm_chnenbl_t;
#endif

/*
 * constants & macros for entire SDMAARM_CHNENBL register
 */
#define HW_SDMAARM_CHNENBL_ADDR      (REGS_SDMAARM_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_CHNENBL           (*(volatile hw_sdmaarm_chnenbl_t *) HW_SDMAARM_CHNENBL_ADDR)
#define HW_SDMAARM_CHNENBL_RD()      (HW_SDMAARM_CHNENBL.U)
#define HW_SDMAARM_CHNENBL_WR(v)     (HW_SDMAARM_CHNENBL.U = (v))
#define HW_SDMAARM_CHNENBL_SET(v)    (HW_SDMAARM_CHNENBL_WR(HW_SDMAARM_CHNENBL_RD() |  (v)))
#define HW_SDMAARM_CHNENBL_CLR(v)    (HW_SDMAARM_CHNENBL_WR(HW_SDMAARM_CHNENBL_RD() & ~(v)))
#define HW_SDMAARM_CHNENBL_TOG(v)    (HW_SDMAARM_CHNENBL_WR(HW_SDMAARM_CHNENBL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_CHNENBL bitfields
 */

/* --- Register HW_SDMAARM_CHNENBL, field ENBLN */

#define BP_SDMAARM_CHNENBL_ENBLN      0
#define BM_SDMAARM_CHNENBL_ENBLN      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CHNENBL_ENBLN(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_CHNENBL_ENBLN)
#else
#define BF_SDMAARM_CHNENBL_ENBLN(v)   (((v) << 0) & BM_SDMAARM_CHNENBL_ENBLN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_CHNENBL_ENBLN(v)   BF_CS1(SDMAARM_CHNENBL, ENBLN, v)
#endif

/*
 * HW_SDMAARM_SDMA_CHNPRI - Channel Priority Registers
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 29;
        unsigned CHNPRIN : 3;

    } B;
} hw_sdmaarm_sdma_chnpri_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI register
 */
#define HW_SDMAARM_SDMA_CHNPRI_ADDR      (REGS_SDMAARM_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI           (*(volatile hw_sdmaarm_sdma_chnpri_t *) HW_SDMAARM_SDMA_CHNPRI_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI_RD()      (HW_SDMAARM_SDMA_CHNPRI.U)
#define HW_SDMAARM_SDMA_CHNPRI_WR(v)     (HW_SDMAARM_SDMA_CHNPRI.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI_SET(v)    (HW_SDMAARM_SDMA_CHNPRI_WR(HW_SDMAARM_SDMA_CHNPRI_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI_WR(HW_SDMAARM_SDMA_CHNPRI_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI_WR(HW_SDMAARM_SDMA_CHNPRI_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI, field CHNPRIN */

#define BP_SDMAARM_SDMA_CHNPRI_CHNPRIN      0
#define BM_SDMAARM_SDMA_CHNPRI_CHNPRIN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_SDMA_CHNPRI_CHNPRIN(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_SDMA_CHNPRI_CHNPRIN)
#else
#define BF_SDMAARM_SDMA_CHNPRI_CHNPRIN(v)   (((v) << 0) & BM_SDMAARM_SDMA_CHNPRI_CHNPRIN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_SDMA_CHNPRI_CHNPRIN(v)   BF_CS1(SDMAARM_SDMA_CHNPRI, CHNPRIN, v)
#endif

/*
 * HW_SDMAARM_SDMA.CHNENBL - Channel Enable RAM
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ENBLN : 32;

    } B;
} hw_sdmaarm_sdma.chnenbl_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA.CHNENBL register
 */
#define HW_SDMAARM_SDMA.CHNENBL_ADDR      (REGS_SDMAARM_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA.CHNENBL           (*(volatile hw_sdmaarm_sdma.chnenbl_t *) HW_SDMAARM_SDMA.CHNENBL_ADDR)
#define HW_SDMAARM_SDMA.CHNENBL_RD()      (HW_SDMAARM_SDMA.CHNENBL.U)
#define HW_SDMAARM_SDMA.CHNENBL_WR(v)     (HW_SDMAARM_SDMA.CHNENBL.U = (v))
#define HW_SDMAARM_SDMA.CHNENBL_SET(v)    (HW_SDMAARM_SDMA.CHNENBL_WR(HW_SDMAARM_SDMA.CHNENBL_RD() |  (v)))
#define HW_SDMAARM_SDMA.CHNENBL_CLR(v)    (HW_SDMAARM_SDMA.CHNENBL_WR(HW_SDMAARM_SDMA.CHNENBL_RD() & ~(v)))
#define HW_SDMAARM_SDMA.CHNENBL_TOG(v)    (HW_SDMAARM_SDMA.CHNENBL_WR(HW_SDMAARM_SDMA.CHNENBL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMAARM_SDMA.CHNENBL bitfields
 */

/* --- Register HW_SDMAARM_SDMA.CHNENBL, field ENBLN */

#define BP_SDMAARM_SDMA.CHNENBL_ENBLN      0
#define BM_SDMAARM_SDMA.CHNENBL_ENBLN      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_SDMA.CHNENBL_ENBLN(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_SDMA.CHNENBL_ENBLN)
#else
#define BF_SDMAARM_SDMA.CHNENBL_ENBLN(v)   (((v) << 0) & BM_SDMAARM_SDMA.CHNENBL_ENBLN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMAARM_SDMA.CHNENBL_ENBLN(v)   BF_CS1(SDMAARM_SDMA.CHNENBL, ENBLN, v)
#endif


#endif // _SDMAARM_H

