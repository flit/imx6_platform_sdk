/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _PWM_H
#define _PWM_H

#include "regs.h"

#ifndef REGS_PWM_BASE
#define REGS_PWM0_BASE (REGS_BASE + 0x02080000)
#define REGS_PWM1_BASE (REGS_BASE + 0x02084000)
#define REGS_PWM2_BASE (REGS_BASE + 0x02088000)
#define REGS_PWM3_BASE (REGS_BASE + 0x0208c000)
#define REGS_PWM_BASE(x) ( x == 0 ? REGS_PWM0_BASE : x == 1 ? REGS_PWM1_BASE : x == 2 ? REGS_PWM2_BASE : x == 3 ? REGS_PWM3_BASE : 0xffff0000)

#endif


/*
 * HW_PWM_PWMCR - PWM Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED : 4;
        unsigned FWM : 2;
        unsigned STOPEN : 1;
        unsigned DOZEN : 1;
        unsigned WAITEN : 1;
        unsigned RESERVED0 : 3;
        unsigned DBGEN : 1;
        unsigned RESERVED1 : 1;
        unsigned BCTR : 1;
        unsigned HCTR : 1;
        unsigned POUTC : 2;
        unsigned CLKSRC : 2;
        unsigned PRESCALER : 12;
        unsigned SWR : 1;
        unsigned REPEAT : 2;
        unsigned EN : 1;

    } B;
} hw_pwm_pwmcr_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMCR register
 */
#define HW_PWM_PWMCR_ADDR(x)      (REGS_PWM_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMCR(x)           (*(volatile hw_pwm_pwmcr_t *) HW_PWM_PWMCR_ADDR(x))
#define HW_PWM_PWMCR_RD(x)        (HW_PWM_PWMCR(x).U)
#define HW_PWM_PWMCR_WR(x, v)     (HW_PWM_PWMCR(x).U = (v))
#define HW_PWM_PWMCR_SET(x, v)    (HW_PWM_PWMCR_WR(x, HW_PWM_PWMCR_RD(x) |  (v)))
#define HW_PWM_PWMCR_CLR(x, v)    (HW_PWM_PWMCR_WR(x, HW_PWM_PWMCR_RD(x) & ~(v)))
#define HW_PWM_PWMCR_TOG(x, v)    (HW_PWM_PWMCR_WR(x, HW_PWM_PWMCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMCR bitfields
 */

/* --- Register HW_PWM_PWMCR, field RESERVED */

#define BP_PWM_PWMCR_RESERVED      28
#define BM_PWM_PWMCR_RESERVED      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_RESERVED(v)   ((((reg32_t) v) << 28) & BM_PWM_PWMCR_RESERVED)
#else
#define BF_PWM_PWMCR_RESERVED(v)   (((v) << 28) & BM_PWM_PWMCR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_RESERVED(v)   BF_CS1(PWM_PWMCR, RESERVED, v)
#endif

/* --- Register HW_PWM_PWMCR, field FWM */

#define BP_PWM_PWMCR_FWM      26
#define BM_PWM_PWMCR_FWM      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_FWM(v)   ((((reg32_t) v) << 26) & BM_PWM_PWMCR_FWM)
#else
#define BF_PWM_PWMCR_FWM(v)   (((v) << 26) & BM_PWM_PWMCR_FWM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_FWM(v)   BF_CS1(PWM_PWMCR, FWM, v)
#endif

/* --- Register HW_PWM_PWMCR, field STOPEN */

#define BP_PWM_PWMCR_STOPEN      25
#define BM_PWM_PWMCR_STOPEN      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_STOPEN(v)   ((((reg32_t) v) << 25) & BM_PWM_PWMCR_STOPEN)
#else
#define BF_PWM_PWMCR_STOPEN(v)   (((v) << 25) & BM_PWM_PWMCR_STOPEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_STOPEN(v)   BF_CS1(PWM_PWMCR, STOPEN, v)
#endif

/* --- Register HW_PWM_PWMCR, field DOZEN */

#define BP_PWM_PWMCR_DOZEN      24
#define BM_PWM_PWMCR_DOZEN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_DOZEN(v)   ((((reg32_t) v) << 24) & BM_PWM_PWMCR_DOZEN)
#else
#define BF_PWM_PWMCR_DOZEN(v)   (((v) << 24) & BM_PWM_PWMCR_DOZEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_DOZEN(v)   BF_CS1(PWM_PWMCR, DOZEN, v)
#endif

/* --- Register HW_PWM_PWMCR, field WAITEN */

#define BP_PWM_PWMCR_WAITEN      23
#define BM_PWM_PWMCR_WAITEN      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_WAITEN(v)   ((((reg32_t) v) << 23) & BM_PWM_PWMCR_WAITEN)
#else
#define BF_PWM_PWMCR_WAITEN(v)   (((v) << 23) & BM_PWM_PWMCR_WAITEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_WAITEN(v)   BF_CS1(PWM_PWMCR, WAITEN, v)
#endif

/* --- Register HW_PWM_PWMCR, field DBGEN */

#define BP_PWM_PWMCR_DBGEN      22
#define BM_PWM_PWMCR_DBGEN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_DBGEN(v)   ((((reg32_t) v) << 22) & BM_PWM_PWMCR_DBGEN)
#else
#define BF_PWM_PWMCR_DBGEN(v)   (((v) << 22) & BM_PWM_PWMCR_DBGEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_DBGEN(v)   BF_CS1(PWM_PWMCR, DBGEN, v)
#endif

/* --- Register HW_PWM_PWMCR, field BCTR */

#define BP_PWM_PWMCR_BCTR      21
#define BM_PWM_PWMCR_BCTR      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_BCTR(v)   ((((reg32_t) v) << 21) & BM_PWM_PWMCR_BCTR)
#else
#define BF_PWM_PWMCR_BCTR(v)   (((v) << 21) & BM_PWM_PWMCR_BCTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_BCTR(v)   BF_CS1(PWM_PWMCR, BCTR, v)
#endif

/* --- Register HW_PWM_PWMCR, field HCTR */

#define BP_PWM_PWMCR_HCTR      20
#define BM_PWM_PWMCR_HCTR      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_HCTR(v)   ((((reg32_t) v) << 20) & BM_PWM_PWMCR_HCTR)
#else
#define BF_PWM_PWMCR_HCTR(v)   (((v) << 20) & BM_PWM_PWMCR_HCTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_HCTR(v)   BF_CS1(PWM_PWMCR, HCTR, v)
#endif

/* --- Register HW_PWM_PWMCR, field POUTC */

#define BP_PWM_PWMCR_POUTC      18
#define BM_PWM_PWMCR_POUTC      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_POUTC(v)   ((((reg32_t) v) << 18) & BM_PWM_PWMCR_POUTC)
#else
#define BF_PWM_PWMCR_POUTC(v)   (((v) << 18) & BM_PWM_PWMCR_POUTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_POUTC(v)   BF_CS1(PWM_PWMCR, POUTC, v)
#endif

/* --- Register HW_PWM_PWMCR, field CLKSRC */

#define BP_PWM_PWMCR_CLKSRC      16
#define BM_PWM_PWMCR_CLKSRC      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_CLKSRC(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMCR_CLKSRC)
#else
#define BF_PWM_PWMCR_CLKSRC(v)   (((v) << 16) & BM_PWM_PWMCR_CLKSRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_CLKSRC(v)   BF_CS1(PWM_PWMCR, CLKSRC, v)
#endif

/* --- Register HW_PWM_PWMCR, field PRESCALER */

#define BP_PWM_PWMCR_PRESCALER      4
#define BM_PWM_PWMCR_PRESCALER      0x0000fff0

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_PRESCALER(v)   ((((reg32_t) v) << 4) & BM_PWM_PWMCR_PRESCALER)
#else
#define BF_PWM_PWMCR_PRESCALER(v)   (((v) << 4) & BM_PWM_PWMCR_PRESCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_PRESCALER(v)   BF_CS1(PWM_PWMCR, PRESCALER, v)
#endif

/* --- Register HW_PWM_PWMCR, field SWR */

#define BP_PWM_PWMCR_SWR      3
#define BM_PWM_PWMCR_SWR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_SWR(v)   ((((reg32_t) v) << 3) & BM_PWM_PWMCR_SWR)
#else
#define BF_PWM_PWMCR_SWR(v)   (((v) << 3) & BM_PWM_PWMCR_SWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_SWR(v)   BF_CS1(PWM_PWMCR, SWR, v)
#endif

/* --- Register HW_PWM_PWMCR, field REPEAT */

#define BP_PWM_PWMCR_REPEAT      1
#define BM_PWM_PWMCR_REPEAT      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_REPEAT(v)   ((((reg32_t) v) << 1) & BM_PWM_PWMCR_REPEAT)
#else
#define BF_PWM_PWMCR_REPEAT(v)   (((v) << 1) & BM_PWM_PWMCR_REPEAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_REPEAT(v)   BF_CS1(PWM_PWMCR, REPEAT, v)
#endif

/* --- Register HW_PWM_PWMCR, field EN */

#define BP_PWM_PWMCR_EN      0
#define BM_PWM_PWMCR_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_EN(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMCR_EN)
#else
#define BF_PWM_PWMCR_EN(v)   (((v) << 0) & BM_PWM_PWMCR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_EN(v)   BF_CS1(PWM_PWMCR, EN, v)
#endif

/*
 * HW_PWM_PWMSR - PWM Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED : 25;
        unsigned FWE : 1;
        unsigned CMP : 1;
        unsigned ROV : 1;
        unsigned FE : 1;
        unsigned FIFOAV : 3;

    } B;
} hw_pwm_pwmsr_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMSR register
 */
#define HW_PWM_PWMSR_ADDR(x)      (REGS_PWM_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMSR(x)           (*(volatile hw_pwm_pwmsr_t *) HW_PWM_PWMSR_ADDR(x))
#define HW_PWM_PWMSR_RD(x)        (HW_PWM_PWMSR(x).U)
#define HW_PWM_PWMSR_WR(x, v)     (HW_PWM_PWMSR(x).U = (v))
#define HW_PWM_PWMSR_SET(x, v)    (HW_PWM_PWMSR_WR(x, HW_PWM_PWMSR_RD(x) |  (v)))
#define HW_PWM_PWMSR_CLR(x, v)    (HW_PWM_PWMSR_WR(x, HW_PWM_PWMSR_RD(x) & ~(v)))
#define HW_PWM_PWMSR_TOG(x, v)    (HW_PWM_PWMSR_WR(x, HW_PWM_PWMSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMSR bitfields
 */

/* --- Register HW_PWM_PWMSR, field RESERVED */

#define BP_PWM_PWMSR_RESERVED      7
#define BM_PWM_PWMSR_RESERVED      0xffffff80

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_RESERVED(v)   ((((reg32_t) v) << 7) & BM_PWM_PWMSR_RESERVED)
#else
#define BF_PWM_PWMSR_RESERVED(v)   (((v) << 7) & BM_PWM_PWMSR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_RESERVED(v)   BF_CS1(PWM_PWMSR, RESERVED, v)
#endif

/* --- Register HW_PWM_PWMSR, field FWE */

#define BP_PWM_PWMSR_FWE      6
#define BM_PWM_PWMSR_FWE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_FWE(v)   ((((reg32_t) v) << 6) & BM_PWM_PWMSR_FWE)
#else
#define BF_PWM_PWMSR_FWE(v)   (((v) << 6) & BM_PWM_PWMSR_FWE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_FWE(v)   BF_CS1(PWM_PWMSR, FWE, v)
#endif

/* --- Register HW_PWM_PWMSR, field CMP */

#define BP_PWM_PWMSR_CMP      5
#define BM_PWM_PWMSR_CMP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_CMP(v)   ((((reg32_t) v) << 5) & BM_PWM_PWMSR_CMP)
#else
#define BF_PWM_PWMSR_CMP(v)   (((v) << 5) & BM_PWM_PWMSR_CMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_CMP(v)   BF_CS1(PWM_PWMSR, CMP, v)
#endif

/* --- Register HW_PWM_PWMSR, field ROV */

#define BP_PWM_PWMSR_ROV      4
#define BM_PWM_PWMSR_ROV      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_ROV(v)   ((((reg32_t) v) << 4) & BM_PWM_PWMSR_ROV)
#else
#define BF_PWM_PWMSR_ROV(v)   (((v) << 4) & BM_PWM_PWMSR_ROV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_ROV(v)   BF_CS1(PWM_PWMSR, ROV, v)
#endif

/* --- Register HW_PWM_PWMSR, field FE */

#define BP_PWM_PWMSR_FE      3
#define BM_PWM_PWMSR_FE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_FE(v)   ((((reg32_t) v) << 3) & BM_PWM_PWMSR_FE)
#else
#define BF_PWM_PWMSR_FE(v)   (((v) << 3) & BM_PWM_PWMSR_FE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_FE(v)   BF_CS1(PWM_PWMSR, FE, v)
#endif

/* --- Register HW_PWM_PWMSR, field FIFOAV */

#define BP_PWM_PWMSR_FIFOAV      0
#define BM_PWM_PWMSR_FIFOAV      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_FIFOAV(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMSR_FIFOAV)
#else
#define BF_PWM_PWMSR_FIFOAV(v)   (((v) << 0) & BM_PWM_PWMSR_FIFOAV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_FIFOAV(v)   BF_CS1(PWM_PWMSR, FIFOAV, v)
#endif

/*
 * HW_PWM_PWMIR - PWM Interrupt Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED : 29;
        unsigned CIE : 1;
        unsigned RIE : 1;
        unsigned FIE : 1;

    } B;
} hw_pwm_pwmir_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMIR register
 */
#define HW_PWM_PWMIR_ADDR(x)      (REGS_PWM_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMIR(x)           (*(volatile hw_pwm_pwmir_t *) HW_PWM_PWMIR_ADDR(x))
#define HW_PWM_PWMIR_RD(x)        (HW_PWM_PWMIR(x).U)
#define HW_PWM_PWMIR_WR(x, v)     (HW_PWM_PWMIR(x).U = (v))
#define HW_PWM_PWMIR_SET(x, v)    (HW_PWM_PWMIR_WR(x, HW_PWM_PWMIR_RD(x) |  (v)))
#define HW_PWM_PWMIR_CLR(x, v)    (HW_PWM_PWMIR_WR(x, HW_PWM_PWMIR_RD(x) & ~(v)))
#define HW_PWM_PWMIR_TOG(x, v)    (HW_PWM_PWMIR_WR(x, HW_PWM_PWMIR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMIR bitfields
 */

/* --- Register HW_PWM_PWMIR, field RESERVED */

#define BP_PWM_PWMIR_RESERVED      3
#define BM_PWM_PWMIR_RESERVED      0xfffffff8

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_RESERVED(v)   ((((reg32_t) v) << 3) & BM_PWM_PWMIR_RESERVED)
#else
#define BF_PWM_PWMIR_RESERVED(v)   (((v) << 3) & BM_PWM_PWMIR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMIR_RESERVED(v)   BF_CS1(PWM_PWMIR, RESERVED, v)
#endif

/* --- Register HW_PWM_PWMIR, field CIE */

#define BP_PWM_PWMIR_CIE      2
#define BM_PWM_PWMIR_CIE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_CIE(v)   ((((reg32_t) v) << 2) & BM_PWM_PWMIR_CIE)
#else
#define BF_PWM_PWMIR_CIE(v)   (((v) << 2) & BM_PWM_PWMIR_CIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMIR_CIE(v)   BF_CS1(PWM_PWMIR, CIE, v)
#endif

/* --- Register HW_PWM_PWMIR, field RIE */

#define BP_PWM_PWMIR_RIE      1
#define BM_PWM_PWMIR_RIE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_RIE(v)   ((((reg32_t) v) << 1) & BM_PWM_PWMIR_RIE)
#else
#define BF_PWM_PWMIR_RIE(v)   (((v) << 1) & BM_PWM_PWMIR_RIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMIR_RIE(v)   BF_CS1(PWM_PWMIR, RIE, v)
#endif

/* --- Register HW_PWM_PWMIR, field FIE */

#define BP_PWM_PWMIR_FIE      0
#define BM_PWM_PWMIR_FIE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_FIE(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMIR_FIE)
#else
#define BF_PWM_PWMIR_FIE(v)   (((v) << 0) & BM_PWM_PWMIR_FIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMIR_FIE(v)   BF_CS1(PWM_PWMIR, FIE, v)
#endif

/*
 * HW_PWM_PWMSAR - PWM Sample Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED : 16;
        unsigned SAMPLE : 16;

    } B;
} hw_pwm_pwmsar_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMSAR register
 */
#define HW_PWM_PWMSAR_ADDR(x)      (REGS_PWM_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMSAR(x)           (*(volatile hw_pwm_pwmsar_t *) HW_PWM_PWMSAR_ADDR(x))
#define HW_PWM_PWMSAR_RD(x)        (HW_PWM_PWMSAR(x).U)
#define HW_PWM_PWMSAR_WR(x, v)     (HW_PWM_PWMSAR(x).U = (v))
#define HW_PWM_PWMSAR_SET(x, v)    (HW_PWM_PWMSAR_WR(x, HW_PWM_PWMSAR_RD(x) |  (v)))
#define HW_PWM_PWMSAR_CLR(x, v)    (HW_PWM_PWMSAR_WR(x, HW_PWM_PWMSAR_RD(x) & ~(v)))
#define HW_PWM_PWMSAR_TOG(x, v)    (HW_PWM_PWMSAR_WR(x, HW_PWM_PWMSAR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMSAR bitfields
 */

/* --- Register HW_PWM_PWMSAR, field RESERVED */

#define BP_PWM_PWMSAR_RESERVED      16
#define BM_PWM_PWMSAR_RESERVED      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSAR_RESERVED(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMSAR_RESERVED)
#else
#define BF_PWM_PWMSAR_RESERVED(v)   (((v) << 16) & BM_PWM_PWMSAR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSAR_RESERVED(v)   BF_CS1(PWM_PWMSAR, RESERVED, v)
#endif

/* --- Register HW_PWM_PWMSAR, field SAMPLE */

#define BP_PWM_PWMSAR_SAMPLE      0
#define BM_PWM_PWMSAR_SAMPLE      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSAR_SAMPLE(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMSAR_SAMPLE)
#else
#define BF_PWM_PWMSAR_SAMPLE(v)   (((v) << 0) & BM_PWM_PWMSAR_SAMPLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSAR_SAMPLE(v)   BF_CS1(PWM_PWMSAR, SAMPLE, v)
#endif

/*
 * HW_PWM_PWMPR - PWM Period Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED : 16;
        unsigned PERIOD : 16;

    } B;
} hw_pwm_pwmpr_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMPR register
 */
#define HW_PWM_PWMPR_ADDR(x)      (REGS_PWM_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMPR(x)           (*(volatile hw_pwm_pwmpr_t *) HW_PWM_PWMPR_ADDR(x))
#define HW_PWM_PWMPR_RD(x)        (HW_PWM_PWMPR(x).U)
#define HW_PWM_PWMPR_WR(x, v)     (HW_PWM_PWMPR(x).U = (v))
#define HW_PWM_PWMPR_SET(x, v)    (HW_PWM_PWMPR_WR(x, HW_PWM_PWMPR_RD(x) |  (v)))
#define HW_PWM_PWMPR_CLR(x, v)    (HW_PWM_PWMPR_WR(x, HW_PWM_PWMPR_RD(x) & ~(v)))
#define HW_PWM_PWMPR_TOG(x, v)    (HW_PWM_PWMPR_WR(x, HW_PWM_PWMPR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMPR bitfields
 */

/* --- Register HW_PWM_PWMPR, field RESERVED */

#define BP_PWM_PWMPR_RESERVED      16
#define BM_PWM_PWMPR_RESERVED      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMPR_RESERVED(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMPR_RESERVED)
#else
#define BF_PWM_PWMPR_RESERVED(v)   (((v) << 16) & BM_PWM_PWMPR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMPR_RESERVED(v)   BF_CS1(PWM_PWMPR, RESERVED, v)
#endif

/* --- Register HW_PWM_PWMPR, field PERIOD */

#define BP_PWM_PWMPR_PERIOD      0
#define BM_PWM_PWMPR_PERIOD      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMPR_PERIOD(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMPR_PERIOD)
#else
#define BF_PWM_PWMPR_PERIOD(v)   (((v) << 0) & BM_PWM_PWMPR_PERIOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMPR_PERIOD(v)   BF_CS1(PWM_PWMPR, PERIOD, v)
#endif

/*
 * HW_PWM_PWMCNR - PWM Counter Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED : 16;
        unsigned COUNT : 16;

    } B;
} hw_pwm_pwmcnr_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMCNR register
 */
#define HW_PWM_PWMCNR_ADDR(x)      (REGS_PWM_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMCNR(x)           (*(volatile hw_pwm_pwmcnr_t *) HW_PWM_PWMCNR_ADDR(x))
#define HW_PWM_PWMCNR_RD(x)        (HW_PWM_PWMCNR(x).U)
#define HW_PWM_PWMCNR_WR(x, v)     (HW_PWM_PWMCNR(x).U = (v))
#define HW_PWM_PWMCNR_SET(x, v)    (HW_PWM_PWMCNR_WR(x, HW_PWM_PWMCNR_RD(x) |  (v)))
#define HW_PWM_PWMCNR_CLR(x, v)    (HW_PWM_PWMCNR_WR(x, HW_PWM_PWMCNR_RD(x) & ~(v)))
#define HW_PWM_PWMCNR_TOG(x, v)    (HW_PWM_PWMCNR_WR(x, HW_PWM_PWMCNR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMCNR bitfields
 */

/* --- Register HW_PWM_PWMCNR, field RESERVED */

#define BP_PWM_PWMCNR_RESERVED      16
#define BM_PWM_PWMCNR_RESERVED      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCNR_RESERVED(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMCNR_RESERVED)
#else
#define BF_PWM_PWMCNR_RESERVED(v)   (((v) << 16) & BM_PWM_PWMCNR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCNR_RESERVED(v)   BF_CS1(PWM_PWMCNR, RESERVED, v)
#endif

/* --- Register HW_PWM_PWMCNR, field COUNT */

#define BP_PWM_PWMCNR_COUNT      0
#define BM_PWM_PWMCNR_COUNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCNR_COUNT(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMCNR_COUNT)
#else
#define BF_PWM_PWMCNR_COUNT(v)   (((v) << 0) & BM_PWM_PWMCNR_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCNR_COUNT(v)   BF_CS1(PWM_PWMCNR, COUNT, v)
#endif


#endif // _PWM_H

