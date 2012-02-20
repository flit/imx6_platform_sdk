/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _PMU_H
#define _PMU_H

#include "regs.h"

#ifndef REGS_PMU_BASE
#define REGS_PMU_BASE (REGS_BASE + 0x020c8000)

#endif


/*
 * HW_PMU_REG_CORE - Digital Regulator Core Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned REF_SHIFT : 1;
        unsigned RESERVED0 : 1;
        unsigned RESERVED1 : 2;
        unsigned FET_ODRIVE : 1;
        unsigned RAMP_RATE : 2;
        unsigned REG2_ADJ : 4;
        unsigned REG2_TRIG : 5;
        unsigned REG1_ADJ : 4;
        unsigned REG1_TRIG : 5;
        unsigned REG0_ADJ : 4;
        unsigned REG0_TRIG : 5;

    } B;
} hw_pmu_reg_core_t;
#endif

/*
 * constants & macros for entire PMU_REG_CORE register
 */
#define HW_PMU_REG_CORE_ADDR      (REGS_PMU_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_CORE           (*(volatile hw_pmu_reg_core_t *) HW_PMU_REG_CORE_ADDR)
#define HW_PMU_REG_CORE_RD()      (HW_PMU_REG_CORE.U)
#define HW_PMU_REG_CORE_WR(v)     (HW_PMU_REG_CORE.U = (v))
#define HW_PMU_REG_CORE_SET(v)    (HW_PMU_REG_CORE_WR(HW_PMU_REG_CORE_RD() |  (v)))
#define HW_PMU_REG_CORE_CLR(v)    (HW_PMU_REG_CORE_WR(HW_PMU_REG_CORE_RD() & ~(v)))
#define HW_PMU_REG_CORE_TOG(v)    (HW_PMU_REG_CORE_WR(HW_PMU_REG_CORE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PMU_REG_CORE bitfields
 */

/* --- Register HW_PMU_REG_CORE, field REF_SHIFT */

#define BP_PMU_REG_CORE_REF_SHIFT      31
#define BM_PMU_REG_CORE_REF_SHIFT      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REF_SHIFT(v)   ((((reg32_t) v) << 31) & BM_PMU_REG_CORE_REF_SHIFT)
#else
#define BF_PMU_REG_CORE_REF_SHIFT(v)   (((v) << 31) & BM_PMU_REG_CORE_REF_SHIFT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_REF_SHIFT(v)   BF_CS1(PMU_REG_CORE, REF_SHIFT, v)
#endif

/* --- Register HW_PMU_REG_CORE, field FET_ODRIVE */

#define BP_PMU_REG_CORE_FET_ODRIVE      29
#define BM_PMU_REG_CORE_FET_ODRIVE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_FET_ODRIVE(v)   ((((reg32_t) v) << 29) & BM_PMU_REG_CORE_FET_ODRIVE)
#else
#define BF_PMU_REG_CORE_FET_ODRIVE(v)   (((v) << 29) & BM_PMU_REG_CORE_FET_ODRIVE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_FET_ODRIVE(v)   BF_CS1(PMU_REG_CORE, FET_ODRIVE, v)
#endif

/* --- Register HW_PMU_REG_CORE, field RAMP_RATE */

#define BP_PMU_REG_CORE_RAMP_RATE      27
#define BM_PMU_REG_CORE_RAMP_RATE      0x18000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_RAMP_RATE(v)   ((((reg32_t) v) << 27) & BM_PMU_REG_CORE_RAMP_RATE)
#else
#define BF_PMU_REG_CORE_RAMP_RATE(v)   (((v) << 27) & BM_PMU_REG_CORE_RAMP_RATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_RAMP_RATE(v)   BF_CS1(PMU_REG_CORE, RAMP_RATE, v)
#endif

/* --- Register HW_PMU_REG_CORE, field REG2_ADJ */

#define BP_PMU_REG_CORE_REG2_ADJ      23
#define BM_PMU_REG_CORE_REG2_ADJ      0x07800000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG2_ADJ(v)   ((((reg32_t) v) << 23) & BM_PMU_REG_CORE_REG2_ADJ)
#else
#define BF_PMU_REG_CORE_REG2_ADJ(v)   (((v) << 23) & BM_PMU_REG_CORE_REG2_ADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_REG2_ADJ(v)   BF_CS1(PMU_REG_CORE, REG2_ADJ, v)
#endif

/* --- Register HW_PMU_REG_CORE, field REG2_TRIG */

#define BP_PMU_REG_CORE_REG2_TRIG      18
#define BM_PMU_REG_CORE_REG2_TRIG      0x007c0000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG2_TRIG(v)   ((((reg32_t) v) << 18) & BM_PMU_REG_CORE_REG2_TRIG)
#else
#define BF_PMU_REG_CORE_REG2_TRIG(v)   (((v) << 18) & BM_PMU_REG_CORE_REG2_TRIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_REG2_TRIG(v)   BF_CS1(PMU_REG_CORE, REG2_TRIG, v)
#endif

/* --- Register HW_PMU_REG_CORE, field REG1_ADJ */

#define BP_PMU_REG_CORE_REG1_ADJ      14
#define BM_PMU_REG_CORE_REG1_ADJ      0x0003c000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG1_ADJ(v)   ((((reg32_t) v) << 14) & BM_PMU_REG_CORE_REG1_ADJ)
#else
#define BF_PMU_REG_CORE_REG1_ADJ(v)   (((v) << 14) & BM_PMU_REG_CORE_REG1_ADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_REG1_ADJ(v)   BF_CS1(PMU_REG_CORE, REG1_ADJ, v)
#endif

/* --- Register HW_PMU_REG_CORE, field REG1_TRIG */

#define BP_PMU_REG_CORE_REG1_TRIG      9
#define BM_PMU_REG_CORE_REG1_TRIG      0x00003e00

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG1_TRIG(v)   ((((reg32_t) v) << 9) & BM_PMU_REG_CORE_REG1_TRIG)
#else
#define BF_PMU_REG_CORE_REG1_TRIG(v)   (((v) << 9) & BM_PMU_REG_CORE_REG1_TRIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_REG1_TRIG(v)   BF_CS1(PMU_REG_CORE, REG1_TRIG, v)
#endif

/* --- Register HW_PMU_REG_CORE, field REG0_ADJ */

#define BP_PMU_REG_CORE_REG0_ADJ      5
#define BM_PMU_REG_CORE_REG0_ADJ      0x000001e0

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG0_ADJ(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_CORE_REG0_ADJ)
#else
#define BF_PMU_REG_CORE_REG0_ADJ(v)   (((v) << 5) & BM_PMU_REG_CORE_REG0_ADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_REG0_ADJ(v)   BF_CS1(PMU_REG_CORE, REG0_ADJ, v)
#endif

/* --- Register HW_PMU_REG_CORE, field REG0_TRIG */

#define BP_PMU_REG_CORE_REG0_TRIG      0
#define BM_PMU_REG_CORE_REG0_TRIG      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG0_TRIG(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_CORE_REG0_TRIG)
#else
#define BF_PMU_REG_CORE_REG0_TRIG(v)   (((v) << 0) & BM_PMU_REG_CORE_REG0_TRIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_CORE_REG0_TRIG(v)   BF_CS1(PMU_REG_CORE, REG0_TRIG, v)
#endif

/*
 * HW_PMU_MISC0 - Miscellaneous Register 0
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 3;
        unsigned CLKGATE_DELAY : 3;
        unsigned CLKGATE_CTRL : 1;
        unsigned ANAMUX : 4;
        unsigned ANAMUX_EN : 1;
        unsigned RESERVED1 : 5;
        unsigned WBCP_VPW_THRESH : 2;
        unsigned OSC_XTALOK_EN : 1;
        unsigned OSC_XTALOK : 1;
        unsigned OSC_I : 2;
        unsigned RTC_RINGOSC_EN : 1;
        unsigned RESERVED2 : 1;
        unsigned STOP_MODE_CONFIG : 1;
        unsigned RESERVED3 : 2;
        unsigned REFTOP_BIAS_TST : 2;
        unsigned RESERVED4 : 4;
        unsigned REFTOP_VBGUP : 1;
        unsigned REFTOP_VBGADJ : 3;
        unsigned REFTOP_SELFBIASOFF : 1;
        unsigned REFTOP_LOWPOWER : 1;
        unsigned REFTOP_PWDVBGUP : 1;
        unsigned RESERVED5 : 2;
        unsigned REFTOP_PWD : 1;

    } B;
} hw_pmu_misc0_t;
#endif

/*
 * constants & macros for entire PMU_MISC0 register
 */
#define HW_PMU_MISC0_ADDR      (REGS_PMU_BASE + 0x150)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_MISC0           (*(volatile hw_pmu_misc0_t *) HW_PMU_MISC0_ADDR)
#define HW_PMU_MISC0_RD()      (HW_PMU_MISC0.U)
#define HW_PMU_MISC0_WR(v)     (HW_PMU_MISC0.U = (v))
#define HW_PMU_MISC0_SET(v)    (HW_PMU_MISC0_WR(HW_PMU_MISC0_RD() |  (v)))
#define HW_PMU_MISC0_CLR(v)    (HW_PMU_MISC0_WR(HW_PMU_MISC0_RD() & ~(v)))
#define HW_PMU_MISC0_TOG(v)    (HW_PMU_MISC0_WR(HW_PMU_MISC0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PMU_MISC0 bitfields
 */

/* --- Register HW_PMU_MISC0, field CLKGATE_DELAY */

#define BP_PMU_MISC0_CLKGATE_DELAY      26
#define BM_PMU_MISC0_CLKGATE_DELAY      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_CLKGATE_DELAY(v)   ((((reg32_t) v) << 26) & BM_PMU_MISC0_CLKGATE_DELAY)
#else
#define BF_PMU_MISC0_CLKGATE_DELAY(v)   (((v) << 26) & BM_PMU_MISC0_CLKGATE_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_CLKGATE_DELAY(v)   BF_CS1(PMU_MISC0, CLKGATE_DELAY, v)
#endif

/* --- Register HW_PMU_MISC0, field CLKGATE_CTRL */

#define BP_PMU_MISC0_CLKGATE_CTRL      25
#define BM_PMU_MISC0_CLKGATE_CTRL      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_CLKGATE_CTRL(v)   ((((reg32_t) v) << 25) & BM_PMU_MISC0_CLKGATE_CTRL)
#else
#define BF_PMU_MISC0_CLKGATE_CTRL(v)   (((v) << 25) & BM_PMU_MISC0_CLKGATE_CTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_CLKGATE_CTRL(v)   BF_CS1(PMU_MISC0, CLKGATE_CTRL, v)
#endif

/* --- Register HW_PMU_MISC0, field ANAMUX */

#define BP_PMU_MISC0_ANAMUX      21
#define BM_PMU_MISC0_ANAMUX      0x01e00000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_ANAMUX(v)   ((((reg32_t) v) << 21) & BM_PMU_MISC0_ANAMUX)
#else
#define BF_PMU_MISC0_ANAMUX(v)   (((v) << 21) & BM_PMU_MISC0_ANAMUX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_ANAMUX(v)   BF_CS1(PMU_MISC0, ANAMUX, v)
#endif

/* --- Register HW_PMU_MISC0, field ANAMUX_EN */

#define BP_PMU_MISC0_ANAMUX_EN      20
#define BM_PMU_MISC0_ANAMUX_EN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_ANAMUX_EN(v)   ((((reg32_t) v) << 20) & BM_PMU_MISC0_ANAMUX_EN)
#else
#define BF_PMU_MISC0_ANAMUX_EN(v)   (((v) << 20) & BM_PMU_MISC0_ANAMUX_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_ANAMUX_EN(v)   BF_CS1(PMU_MISC0, ANAMUX_EN, v)
#endif

/* --- Register HW_PMU_MISC0, field WBCP_VPW_THRESH */

#define BP_PMU_MISC0_WBCP_VPW_THRESH      18
#define BM_PMU_MISC0_WBCP_VPW_THRESH      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_WBCP_VPW_THRESH(v)   ((((reg32_t) v) << 18) & BM_PMU_MISC0_WBCP_VPW_THRESH)
#else
#define BF_PMU_MISC0_WBCP_VPW_THRESH(v)   (((v) << 18) & BM_PMU_MISC0_WBCP_VPW_THRESH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_WBCP_VPW_THRESH(v)   BF_CS1(PMU_MISC0, WBCP_VPW_THRESH, v)
#endif

/* --- Register HW_PMU_MISC0, field OSC_XTALOK_EN */

#define BP_PMU_MISC0_OSC_XTALOK_EN      17
#define BM_PMU_MISC0_OSC_XTALOK_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_OSC_XTALOK_EN(v)   ((((reg32_t) v) << 17) & BM_PMU_MISC0_OSC_XTALOK_EN)
#else
#define BF_PMU_MISC0_OSC_XTALOK_EN(v)   (((v) << 17) & BM_PMU_MISC0_OSC_XTALOK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_OSC_XTALOK_EN(v)   BF_CS1(PMU_MISC0, OSC_XTALOK_EN, v)
#endif

/* --- Register HW_PMU_MISC0, field OSC_XTALOK */

#define BP_PMU_MISC0_OSC_XTALOK      16
#define BM_PMU_MISC0_OSC_XTALOK      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_OSC_XTALOK(v)   ((((reg32_t) v) << 16) & BM_PMU_MISC0_OSC_XTALOK)
#else
#define BF_PMU_MISC0_OSC_XTALOK(v)   (((v) << 16) & BM_PMU_MISC0_OSC_XTALOK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_OSC_XTALOK(v)   BF_CS1(PMU_MISC0, OSC_XTALOK, v)
#endif

/* --- Register HW_PMU_MISC0, field OSC_I */

#define BP_PMU_MISC0_OSC_I      14
#define BM_PMU_MISC0_OSC_I      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_OSC_I(v)   ((((reg32_t) v) << 14) & BM_PMU_MISC0_OSC_I)
#else
#define BF_PMU_MISC0_OSC_I(v)   (((v) << 14) & BM_PMU_MISC0_OSC_I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_OSC_I(v)   BF_CS1(PMU_MISC0, OSC_I, v)
#endif

/* --- Register HW_PMU_MISC0, field RTC_RINGOSC_EN */

#define BP_PMU_MISC0_RTC_RINGOSC_EN      13
#define BM_PMU_MISC0_RTC_RINGOSC_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_RTC_RINGOSC_EN(v)   ((((reg32_t) v) << 13) & BM_PMU_MISC0_RTC_RINGOSC_EN)
#else
#define BF_PMU_MISC0_RTC_RINGOSC_EN(v)   (((v) << 13) & BM_PMU_MISC0_RTC_RINGOSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_RTC_RINGOSC_EN(v)   BF_CS1(PMU_MISC0, RTC_RINGOSC_EN, v)
#endif

/* --- Register HW_PMU_MISC0, field STOP_MODE_CONFIG */

#define BP_PMU_MISC0_STOP_MODE_CONFIG      12
#define BM_PMU_MISC0_STOP_MODE_CONFIG      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_STOP_MODE_CONFIG(v)   ((((reg32_t) v) << 12) & BM_PMU_MISC0_STOP_MODE_CONFIG)
#else
#define BF_PMU_MISC0_STOP_MODE_CONFIG(v)   (((v) << 12) & BM_PMU_MISC0_STOP_MODE_CONFIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_STOP_MODE_CONFIG(v)   BF_CS1(PMU_MISC0, STOP_MODE_CONFIG, v)
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_BIAS_TST */

#define BP_PMU_MISC0_REFTOP_BIAS_TST      8
#define BM_PMU_MISC0_REFTOP_BIAS_TST      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_BIAS_TST(v)   ((((reg32_t) v) << 8) & BM_PMU_MISC0_REFTOP_BIAS_TST)
#else
#define BF_PMU_MISC0_REFTOP_BIAS_TST(v)   (((v) << 8) & BM_PMU_MISC0_REFTOP_BIAS_TST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_REFTOP_BIAS_TST(v)   BF_CS1(PMU_MISC0, REFTOP_BIAS_TST, v)
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_VBGUP */

#define BP_PMU_MISC0_REFTOP_VBGUP      7
#define BM_PMU_MISC0_REFTOP_VBGUP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_VBGUP(v)   ((((reg32_t) v) << 7) & BM_PMU_MISC0_REFTOP_VBGUP)
#else
#define BF_PMU_MISC0_REFTOP_VBGUP(v)   (((v) << 7) & BM_PMU_MISC0_REFTOP_VBGUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_REFTOP_VBGUP(v)   BF_CS1(PMU_MISC0, REFTOP_VBGUP, v)
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_VBGADJ */

#define BP_PMU_MISC0_REFTOP_VBGADJ      4
#define BM_PMU_MISC0_REFTOP_VBGADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_VBGADJ(v)   ((((reg32_t) v) << 4) & BM_PMU_MISC0_REFTOP_VBGADJ)
#else
#define BF_PMU_MISC0_REFTOP_VBGADJ(v)   (((v) << 4) & BM_PMU_MISC0_REFTOP_VBGADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_REFTOP_VBGADJ(v)   BF_CS1(PMU_MISC0, REFTOP_VBGADJ, v)
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_SELFBIASOFF */

#define BP_PMU_MISC0_REFTOP_SELFBIASOFF      3
#define BM_PMU_MISC0_REFTOP_SELFBIASOFF      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_SELFBIASOFF(v)   ((((reg32_t) v) << 3) & BM_PMU_MISC0_REFTOP_SELFBIASOFF)
#else
#define BF_PMU_MISC0_REFTOP_SELFBIASOFF(v)   (((v) << 3) & BM_PMU_MISC0_REFTOP_SELFBIASOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_REFTOP_SELFBIASOFF(v)   BF_CS1(PMU_MISC0, REFTOP_SELFBIASOFF, v)
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_LOWPOWER */

#define BP_PMU_MISC0_REFTOP_LOWPOWER      2
#define BM_PMU_MISC0_REFTOP_LOWPOWER      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_LOWPOWER(v)   ((((reg32_t) v) << 2) & BM_PMU_MISC0_REFTOP_LOWPOWER)
#else
#define BF_PMU_MISC0_REFTOP_LOWPOWER(v)   (((v) << 2) & BM_PMU_MISC0_REFTOP_LOWPOWER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_REFTOP_LOWPOWER(v)   BF_CS1(PMU_MISC0, REFTOP_LOWPOWER, v)
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_PWDVBGUP */

#define BP_PMU_MISC0_REFTOP_PWDVBGUP      1
#define BM_PMU_MISC0_REFTOP_PWDVBGUP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_PWDVBGUP(v)   ((((reg32_t) v) << 1) & BM_PMU_MISC0_REFTOP_PWDVBGUP)
#else
#define BF_PMU_MISC0_REFTOP_PWDVBGUP(v)   (((v) << 1) & BM_PMU_MISC0_REFTOP_PWDVBGUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_REFTOP_PWDVBGUP(v)   BF_CS1(PMU_MISC0, REFTOP_PWDVBGUP, v)
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_PWD */

#define BP_PMU_MISC0_REFTOP_PWD      0
#define BM_PMU_MISC0_REFTOP_PWD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_PWD(v)   ((((reg32_t) v) << 0) & BM_PMU_MISC0_REFTOP_PWD)
#else
#define BF_PMU_MISC0_REFTOP_PWD(v)   (((v) << 0) & BM_PMU_MISC0_REFTOP_PWD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_MISC0_REFTOP_PWD(v)   BF_CS1(PMU_MISC0, REFTOP_PWD, v)
#endif

/*
 * HW_PMU_REG_MISC1 - Miscellaneous Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IRQ_DIG_BO : 1;
        unsigned IRQ_ANA_BO : 1;
        unsigned IRQ_TEMPSENSE : 1;
        unsigned RESERVED0 : 15;
        unsigned LVDSCLK2_IBEN : 1;
        unsigned LVDSCLK1_IBEN : 1;
        unsigned LVDSCLK2_OBEN : 1;
        unsigned LVDSCLK1_OBEN : 1;
        unsigned LVDS2_CLK_SEL : 5;
        unsigned LVDS1_CLK_SEL : 5;

    } B;
} hw_pmu_reg_misc1_t;
#endif

/*
 * constants & macros for entire PMU_REG_MISC1 register
 */
#define HW_PMU_REG_MISC1_ADDR      (REGS_PMU_BASE + 0x160)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_MISC1           (*(volatile hw_pmu_reg_misc1_t *) HW_PMU_REG_MISC1_ADDR)
#define HW_PMU_REG_MISC1_RD()      (HW_PMU_REG_MISC1.U)
#define HW_PMU_REG_MISC1_WR(v)     (HW_PMU_REG_MISC1.U = (v))
#define HW_PMU_REG_MISC1_SET(v)    (HW_PMU_REG_MISC1_WR(HW_PMU_REG_MISC1_RD() |  (v)))
#define HW_PMU_REG_MISC1_CLR(v)    (HW_PMU_REG_MISC1_WR(HW_PMU_REG_MISC1_RD() & ~(v)))
#define HW_PMU_REG_MISC1_TOG(v)    (HW_PMU_REG_MISC1_WR(HW_PMU_REG_MISC1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PMU_REG_MISC1 bitfields
 */

/* --- Register HW_PMU_REG_MISC1, field IRQ_DIG_BO */

#define BP_PMU_REG_MISC1_IRQ_DIG_BO      31
#define BM_PMU_REG_MISC1_IRQ_DIG_BO      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_IRQ_DIG_BO(v)   ((((reg32_t) v) << 31) & BM_PMU_REG_MISC1_IRQ_DIG_BO)
#else
#define BF_PMU_REG_MISC1_IRQ_DIG_BO(v)   (((v) << 31) & BM_PMU_REG_MISC1_IRQ_DIG_BO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_IRQ_DIG_BO(v)   BF_CS1(PMU_REG_MISC1, IRQ_DIG_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field IRQ_ANA_BO */

#define BP_PMU_REG_MISC1_IRQ_ANA_BO      30
#define BM_PMU_REG_MISC1_IRQ_ANA_BO      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_IRQ_ANA_BO(v)   ((((reg32_t) v) << 30) & BM_PMU_REG_MISC1_IRQ_ANA_BO)
#else
#define BF_PMU_REG_MISC1_IRQ_ANA_BO(v)   (((v) << 30) & BM_PMU_REG_MISC1_IRQ_ANA_BO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_IRQ_ANA_BO(v)   BF_CS1(PMU_REG_MISC1, IRQ_ANA_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field IRQ_TEMPSENSE */

#define BP_PMU_REG_MISC1_IRQ_TEMPSENSE      29
#define BM_PMU_REG_MISC1_IRQ_TEMPSENSE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   ((((reg32_t) v) << 29) & BM_PMU_REG_MISC1_IRQ_TEMPSENSE)
#else
#define BF_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   (((v) << 29) & BM_PMU_REG_MISC1_IRQ_TEMPSENSE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   BF_CS1(PMU_REG_MISC1, IRQ_TEMPSENSE, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK2_IBEN */

#define BP_PMU_REG_MISC1_LVDSCLK2_IBEN      13
#define BM_PMU_REG_MISC1_LVDSCLK2_IBEN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   ((((reg32_t) v) << 13) & BM_PMU_REG_MISC1_LVDSCLK2_IBEN)
#else
#define BF_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   (((v) << 13) & BM_PMU_REG_MISC1_LVDSCLK2_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK2_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK1_IBEN */

#define BP_PMU_REG_MISC1_LVDSCLK1_IBEN      12
#define BM_PMU_REG_MISC1_LVDSCLK1_IBEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   ((((reg32_t) v) << 12) & BM_PMU_REG_MISC1_LVDSCLK1_IBEN)
#else
#define BF_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   (((v) << 12) & BM_PMU_REG_MISC1_LVDSCLK1_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK1_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK2_OBEN */

#define BP_PMU_REG_MISC1_LVDSCLK2_OBEN      11
#define BM_PMU_REG_MISC1_LVDSCLK2_OBEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   ((((reg32_t) v) << 11) & BM_PMU_REG_MISC1_LVDSCLK2_OBEN)
#else
#define BF_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   (((v) << 11) & BM_PMU_REG_MISC1_LVDSCLK2_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK2_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK1_OBEN */

#define BP_PMU_REG_MISC1_LVDSCLK1_OBEN      10
#define BM_PMU_REG_MISC1_LVDSCLK1_OBEN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   ((((reg32_t) v) << 10) & BM_PMU_REG_MISC1_LVDSCLK1_OBEN)
#else
#define BF_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   (((v) << 10) & BM_PMU_REG_MISC1_LVDSCLK1_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK1_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDS2_CLK_SEL */

#define BP_PMU_REG_MISC1_LVDS2_CLK_SEL      5
#define BM_PMU_REG_MISC1_LVDS2_CLK_SEL      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_MISC1_LVDS2_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   (((v) << 5) & BM_PMU_REG_MISC1_LVDS2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1, LVDS2_CLK_SEL, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDS1_CLK_SEL */

#define BP_PMU_REG_MISC1_LVDS1_CLK_SEL      0
#define BM_PMU_REG_MISC1_LVDS1_CLK_SEL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_MISC1_LVDS1_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   (((v) << 0) & BM_PMU_REG_MISC1_LVDS1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1, LVDS1_CLK_SEL, v)
#endif

/*
 * HW_PMU_REG_MISC2 - Miscellaneous Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CONTROL3 : 2;
        unsigned REG2_STEP_TIME : 2;
        unsigned REG1_STEP_TIME : 2;
        unsigned REG0_STEP_TIME : 2;
        unsigned CONTROL2 : 1;
        unsigned RESERVED0 : 1;
        unsigned REG2_OK : 1;
        unsigned REG2_ENABLE_BO : 1;
        unsigned RESERVED1 : 1;
        unsigned REG2_BO_STATUS : 1;
        unsigned REG2_BO_OFFSET : 3;
        unsigned CONTROL1 : 1;
        unsigned RESERVED2 : 1;
        unsigned REG1_OK : 1;
        unsigned RESERVED3 : 1;
        unsigned REG1_ENABLE_BO : 1;
        unsigned RESERVED4 : 1;
        unsigned REG1_BO_STATUS : 1;
        unsigned REG1_BO_OFFSET : 3;
        unsigned CONTROL0 : 1;
        unsigned REG0_OK : 1;
        unsigned RESERVED5 : 1;
        unsigned REG0_ENABLE_BO : 1;
        unsigned RESERVED6 : 1;
        unsigned REG1_BO_STATUS : 1;
        unsigned REG0_BO_OFFSET : 3;

    } B;
} hw_pmu_reg_misc2_t;
#endif

/*
 * constants & macros for entire PMU_REG_MISC2 register
 */
#define HW_PMU_REG_MISC2_ADDR      (REGS_PMU_BASE + 0x170)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_MISC2           (*(volatile hw_pmu_reg_misc2_t *) HW_PMU_REG_MISC2_ADDR)
#define HW_PMU_REG_MISC2_RD()      (HW_PMU_REG_MISC2.U)
#define HW_PMU_REG_MISC2_WR(v)     (HW_PMU_REG_MISC2.U = (v))
#define HW_PMU_REG_MISC2_SET(v)    (HW_PMU_REG_MISC2_WR(HW_PMU_REG_MISC2_RD() |  (v)))
#define HW_PMU_REG_MISC2_CLR(v)    (HW_PMU_REG_MISC2_WR(HW_PMU_REG_MISC2_RD() & ~(v)))
#define HW_PMU_REG_MISC2_TOG(v)    (HW_PMU_REG_MISC2_WR(HW_PMU_REG_MISC2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PMU_REG_MISC2 bitfields
 */

/* --- Register HW_PMU_REG_MISC2, field CONTROL3 */

#define BP_PMU_REG_MISC2_CONTROL3      30
#define BM_PMU_REG_MISC2_CONTROL3      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_CONTROL3(v)   ((((reg32_t) v) << 30) & BM_PMU_REG_MISC2_CONTROL3)
#else
#define BF_PMU_REG_MISC2_CONTROL3(v)   (((v) << 30) & BM_PMU_REG_MISC2_CONTROL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_CONTROL3(v)   BF_CS1(PMU_REG_MISC2, CONTROL3, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_STEP_TIME */

#define BP_PMU_REG_MISC2_REG2_STEP_TIME      28
#define BM_PMU_REG_MISC2_REG2_STEP_TIME      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG2_STEP_TIME(v)   ((((reg32_t) v) << 28) & BM_PMU_REG_MISC2_REG2_STEP_TIME)
#else
#define BF_PMU_REG_MISC2_REG2_STEP_TIME(v)   (((v) << 28) & BM_PMU_REG_MISC2_REG2_STEP_TIME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG2_STEP_TIME(v)   BF_CS1(PMU_REG_MISC2, REG2_STEP_TIME, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG1_STEP_TIME */

#define BP_PMU_REG_MISC2_REG1_STEP_TIME      26
#define BM_PMU_REG_MISC2_REG1_STEP_TIME      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG1_STEP_TIME(v)   ((((reg32_t) v) << 26) & BM_PMU_REG_MISC2_REG1_STEP_TIME)
#else
#define BF_PMU_REG_MISC2_REG1_STEP_TIME(v)   (((v) << 26) & BM_PMU_REG_MISC2_REG1_STEP_TIME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG1_STEP_TIME(v)   BF_CS1(PMU_REG_MISC2, REG1_STEP_TIME, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG0_STEP_TIME */

#define BP_PMU_REG_MISC2_REG0_STEP_TIME      24
#define BM_PMU_REG_MISC2_REG0_STEP_TIME      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG0_STEP_TIME(v)   ((((reg32_t) v) << 24) & BM_PMU_REG_MISC2_REG0_STEP_TIME)
#else
#define BF_PMU_REG_MISC2_REG0_STEP_TIME(v)   (((v) << 24) & BM_PMU_REG_MISC2_REG0_STEP_TIME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG0_STEP_TIME(v)   BF_CS1(PMU_REG_MISC2, REG0_STEP_TIME, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field CONTROL2 */

#define BP_PMU_REG_MISC2_CONTROL2      23
#define BM_PMU_REG_MISC2_CONTROL2      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_CONTROL2(v)   ((((reg32_t) v) << 23) & BM_PMU_REG_MISC2_CONTROL2)
#else
#define BF_PMU_REG_MISC2_CONTROL2(v)   (((v) << 23) & BM_PMU_REG_MISC2_CONTROL2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_CONTROL2(v)   BF_CS1(PMU_REG_MISC2, CONTROL2, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_OK */

#define BP_PMU_REG_MISC2_REG2_OK      22
#define BM_PMU_REG_MISC2_REG2_OK      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG2_OK(v)   ((((reg32_t) v) << 22) & BM_PMU_REG_MISC2_REG2_OK)
#else
#define BF_PMU_REG_MISC2_REG2_OK(v)   (((v) << 22) & BM_PMU_REG_MISC2_REG2_OK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG2_OK(v)   BF_CS1(PMU_REG_MISC2, REG2_OK, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_ENABLE_BO */

#define BP_PMU_REG_MISC2_REG2_ENABLE_BO      21
#define BM_PMU_REG_MISC2_REG2_ENABLE_BO      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG2_ENABLE_BO(v)   ((((reg32_t) v) << 21) & BM_PMU_REG_MISC2_REG2_ENABLE_BO)
#else
#define BF_PMU_REG_MISC2_REG2_ENABLE_BO(v)   (((v) << 21) & BM_PMU_REG_MISC2_REG2_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG2_ENABLE_BO(v)   BF_CS1(PMU_REG_MISC2, REG2_ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_BO_STATUS */

#define BP_PMU_REG_MISC2_REG2_BO_STATUS      19
#define BM_PMU_REG_MISC2_REG2_BO_STATUS      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG2_BO_STATUS(v)   ((((reg32_t) v) << 19) & BM_PMU_REG_MISC2_REG2_BO_STATUS)
#else
#define BF_PMU_REG_MISC2_REG2_BO_STATUS(v)   (((v) << 19) & BM_PMU_REG_MISC2_REG2_BO_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG2_BO_STATUS(v)   BF_CS1(PMU_REG_MISC2, REG2_BO_STATUS, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_BO_OFFSET */

#define BP_PMU_REG_MISC2_REG2_BO_OFFSET      16
#define BM_PMU_REG_MISC2_REG2_BO_OFFSET      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG2_BO_OFFSET(v)   ((((reg32_t) v) << 16) & BM_PMU_REG_MISC2_REG2_BO_OFFSET)
#else
#define BF_PMU_REG_MISC2_REG2_BO_OFFSET(v)   (((v) << 16) & BM_PMU_REG_MISC2_REG2_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG2_BO_OFFSET(v)   BF_CS1(PMU_REG_MISC2, REG2_BO_OFFSET, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field CONTROL1 */

#define BP_PMU_REG_MISC2_CONTROL1      15
#define BM_PMU_REG_MISC2_CONTROL1      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_CONTROL1(v)   ((((reg32_t) v) << 15) & BM_PMU_REG_MISC2_CONTROL1)
#else
#define BF_PMU_REG_MISC2_CONTROL1(v)   (((v) << 15) & BM_PMU_REG_MISC2_CONTROL1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_CONTROL1(v)   BF_CS1(PMU_REG_MISC2, CONTROL1, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG1_OK */

#define BP_PMU_REG_MISC2_REG1_OK      14
#define BM_PMU_REG_MISC2_REG1_OK      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG1_OK(v)   ((((reg32_t) v) << 14) & BM_PMU_REG_MISC2_REG1_OK)
#else
#define BF_PMU_REG_MISC2_REG1_OK(v)   (((v) << 14) & BM_PMU_REG_MISC2_REG1_OK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG1_OK(v)   BF_CS1(PMU_REG_MISC2, REG1_OK, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG1_ENABLE_BO */

#define BP_PMU_REG_MISC2_REG1_ENABLE_BO      13
#define BM_PMU_REG_MISC2_REG1_ENABLE_BO      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG1_ENABLE_BO(v)   ((((reg32_t) v) << 13) & BM_PMU_REG_MISC2_REG1_ENABLE_BO)
#else
#define BF_PMU_REG_MISC2_REG1_ENABLE_BO(v)   (((v) << 13) & BM_PMU_REG_MISC2_REG1_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG1_ENABLE_BO(v)   BF_CS1(PMU_REG_MISC2, REG1_ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG1_BO_STATUS */

#define BP_PMU_REG_MISC2_REG1_BO_STATUS      11
#define BM_PMU_REG_MISC2_REG1_BO_STATUS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG1_BO_STATUS(v)   ((((reg32_t) v) << 11) & BM_PMU_REG_MISC2_REG1_BO_STATUS)
#else
#define BF_PMU_REG_MISC2_REG1_BO_STATUS(v)   (((v) << 11) & BM_PMU_REG_MISC2_REG1_BO_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG1_BO_STATUS(v)   BF_CS1(PMU_REG_MISC2, REG1_BO_STATUS, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG1_BO_OFFSET */

#define BP_PMU_REG_MISC2_REG1_BO_OFFSET      8
#define BM_PMU_REG_MISC2_REG1_BO_OFFSET      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG1_BO_OFFSET(v)   ((((reg32_t) v) << 8) & BM_PMU_REG_MISC2_REG1_BO_OFFSET)
#else
#define BF_PMU_REG_MISC2_REG1_BO_OFFSET(v)   (((v) << 8) & BM_PMU_REG_MISC2_REG1_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG1_BO_OFFSET(v)   BF_CS1(PMU_REG_MISC2, REG1_BO_OFFSET, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field CONTROL0 */

#define BP_PMU_REG_MISC2_CONTROL0      7
#define BM_PMU_REG_MISC2_CONTROL0      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_CONTROL0(v)   ((((reg32_t) v) << 7) & BM_PMU_REG_MISC2_CONTROL0)
#else
#define BF_PMU_REG_MISC2_CONTROL0(v)   (((v) << 7) & BM_PMU_REG_MISC2_CONTROL0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_CONTROL0(v)   BF_CS1(PMU_REG_MISC2, CONTROL0, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG0_OK */

#define BP_PMU_REG_MISC2_REG0_OK      6
#define BM_PMU_REG_MISC2_REG0_OK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG0_OK(v)   ((((reg32_t) v) << 6) & BM_PMU_REG_MISC2_REG0_OK)
#else
#define BF_PMU_REG_MISC2_REG0_OK(v)   (((v) << 6) & BM_PMU_REG_MISC2_REG0_OK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG0_OK(v)   BF_CS1(PMU_REG_MISC2, REG0_OK, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG0_ENABLE_BO */

#define BP_PMU_REG_MISC2_REG0_ENABLE_BO      5
#define BM_PMU_REG_MISC2_REG0_ENABLE_BO      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG0_ENABLE_BO(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_MISC2_REG0_ENABLE_BO)
#else
#define BF_PMU_REG_MISC2_REG0_ENABLE_BO(v)   (((v) << 5) & BM_PMU_REG_MISC2_REG0_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG0_ENABLE_BO(v)   BF_CS1(PMU_REG_MISC2, REG0_ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG1_BO_STATUS */

#define BP_PMU_REG_MISC2_REG1_BO_STATUS      3
#define BM_PMU_REG_MISC2_REG1_BO_STATUS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG1_BO_STATUS(v)   ((((reg32_t) v) << 3) & BM_PMU_REG_MISC2_REG1_BO_STATUS)
#else
#define BF_PMU_REG_MISC2_REG1_BO_STATUS(v)   (((v) << 3) & BM_PMU_REG_MISC2_REG1_BO_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG1_BO_STATUS(v)   BF_CS1(PMU_REG_MISC2, REG1_BO_STATUS, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG0_BO_OFFSET */

#define BP_PMU_REG_MISC2_REG0_BO_OFFSET      0
#define BM_PMU_REG_MISC2_REG0_BO_OFFSET      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG0_BO_OFFSET(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_MISC2_REG0_BO_OFFSET)
#else
#define BF_PMU_REG_MISC2_REG0_BO_OFFSET(v)   (((v) << 0) & BM_PMU_REG_MISC2_REG0_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_MISC2_REG0_BO_OFFSET(v)   BF_CS1(PMU_REG_MISC2, REG0_BO_OFFSET, v)
#endif

/*
 * HW_PMU_REG_1P1 - Regulator 1P1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned OK_VDD1P1 : 1;
        unsigned BO_VDD1P1 : 1;
        unsigned RESERVED1 : 3;
        unsigned OUTPUT_TRG : 5;
        unsigned RESERVED2 : 1;
        unsigned BO_OFFSET : 3;
        unsigned ENABLE_PULLDOWN : 1;
        unsigned ENABLE_ILIMIT : 1;
        unsigned ENABLE_BO : 1;
        unsigned ENABLE_LINREG : 1;

    } B;
} hw_pmu_reg_1p1_t;
#endif

/*
 * constants & macros for entire PMU_REG_1P1 register
 */
#define HW_PMU_REG_1P1_ADDR      (REGS_PMU_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_1P1           (*(volatile hw_pmu_reg_1p1_t *) HW_PMU_REG_1P1_ADDR)
#define HW_PMU_REG_1P1_RD()      (HW_PMU_REG_1P1.U)
#define HW_PMU_REG_1P1_WR(v)     (HW_PMU_REG_1P1.U = (v))
#define HW_PMU_REG_1P1_SET(v)    (HW_PMU_REG_1P1_WR(HW_PMU_REG_1P1_RD() |  (v)))
#define HW_PMU_REG_1P1_CLR(v)    (HW_PMU_REG_1P1_WR(HW_PMU_REG_1P1_RD() & ~(v)))
#define HW_PMU_REG_1P1_TOG(v)    (HW_PMU_REG_1P1_WR(HW_PMU_REG_1P1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PMU_REG_1P1 bitfields
 */

/* --- Register HW_PMU_REG_1P1, field OK_VDD1P1 */

#define BP_PMU_REG_1P1_OK_VDD1P1      17
#define BM_PMU_REG_1P1_OK_VDD1P1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_OK_VDD1P1(v)   ((((reg32_t) v) << 17) & BM_PMU_REG_1P1_OK_VDD1P1)
#else
#define BF_PMU_REG_1P1_OK_VDD1P1(v)   (((v) << 17) & BM_PMU_REG_1P1_OK_VDD1P1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_1P1_OK_VDD1P1(v)   BF_CS1(PMU_REG_1P1, OK_VDD1P1, v)
#endif

/* --- Register HW_PMU_REG_1P1, field BO_VDD1P1 */

#define BP_PMU_REG_1P1_BO_VDD1P1      16
#define BM_PMU_REG_1P1_BO_VDD1P1      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_BO_VDD1P1(v)   ((((reg32_t) v) << 16) & BM_PMU_REG_1P1_BO_VDD1P1)
#else
#define BF_PMU_REG_1P1_BO_VDD1P1(v)   (((v) << 16) & BM_PMU_REG_1P1_BO_VDD1P1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_1P1_BO_VDD1P1(v)   BF_CS1(PMU_REG_1P1, BO_VDD1P1, v)
#endif

/* --- Register HW_PMU_REG_1P1, field OUTPUT_TRG */

#define BP_PMU_REG_1P1_OUTPUT_TRG      8
#define BM_PMU_REG_1P1_OUTPUT_TRG      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_OUTPUT_TRG(v)   ((((reg32_t) v) << 8) & BM_PMU_REG_1P1_OUTPUT_TRG)
#else
#define BF_PMU_REG_1P1_OUTPUT_TRG(v)   (((v) << 8) & BM_PMU_REG_1P1_OUTPUT_TRG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_1P1_OUTPUT_TRG(v)   BF_CS1(PMU_REG_1P1, OUTPUT_TRG, v)
#endif

/* --- Register HW_PMU_REG_1P1, field BO_OFFSET */

#define BP_PMU_REG_1P1_BO_OFFSET      4
#define BM_PMU_REG_1P1_BO_OFFSET      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_BO_OFFSET(v)   ((((reg32_t) v) << 4) & BM_PMU_REG_1P1_BO_OFFSET)
#else
#define BF_PMU_REG_1P1_BO_OFFSET(v)   (((v) << 4) & BM_PMU_REG_1P1_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_1P1_BO_OFFSET(v)   BF_CS1(PMU_REG_1P1, BO_OFFSET, v)
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_PULLDOWN */

#define BP_PMU_REG_1P1_ENABLE_PULLDOWN      3
#define BM_PMU_REG_1P1_ENABLE_PULLDOWN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_ENABLE_PULLDOWN(v)   ((((reg32_t) v) << 3) & BM_PMU_REG_1P1_ENABLE_PULLDOWN)
#else
#define BF_PMU_REG_1P1_ENABLE_PULLDOWN(v)   (((v) << 3) & BM_PMU_REG_1P1_ENABLE_PULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_1P1_ENABLE_PULLDOWN(v)   BF_CS1(PMU_REG_1P1, ENABLE_PULLDOWN, v)
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_ILIMIT */

#define BP_PMU_REG_1P1_ENABLE_ILIMIT      2
#define BM_PMU_REG_1P1_ENABLE_ILIMIT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_ENABLE_ILIMIT(v)   ((((reg32_t) v) << 2) & BM_PMU_REG_1P1_ENABLE_ILIMIT)
#else
#define BF_PMU_REG_1P1_ENABLE_ILIMIT(v)   (((v) << 2) & BM_PMU_REG_1P1_ENABLE_ILIMIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_1P1_ENABLE_ILIMIT(v)   BF_CS1(PMU_REG_1P1, ENABLE_ILIMIT, v)
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_BO */

#define BP_PMU_REG_1P1_ENABLE_BO      1
#define BM_PMU_REG_1P1_ENABLE_BO      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_ENABLE_BO(v)   ((((reg32_t) v) << 1) & BM_PMU_REG_1P1_ENABLE_BO)
#else
#define BF_PMU_REG_1P1_ENABLE_BO(v)   (((v) << 1) & BM_PMU_REG_1P1_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_1P1_ENABLE_BO(v)   BF_CS1(PMU_REG_1P1, ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_LINREG */

#define BP_PMU_REG_1P1_ENABLE_LINREG      0
#define BM_PMU_REG_1P1_ENABLE_LINREG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_ENABLE_LINREG(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_1P1_ENABLE_LINREG)
#else
#define BF_PMU_REG_1P1_ENABLE_LINREG(v)   (((v) << 0) & BM_PMU_REG_1P1_ENABLE_LINREG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_1P1_ENABLE_LINREG(v)   BF_CS1(PMU_REG_1P1, ENABLE_LINREG, v)
#endif

/*
 * HW_PMU_REG_2P5 - Regulator 2P5 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned ENABLE_WEAK_LINREG : 1;
        unsigned OK_VDD2P5 : 1;
        unsigned BO_VDD2P5 : 1;
        unsigned RESERVED1 : 3;
        unsigned OUTPUT_TRG : 5;
        unsigned RESERVED2 : 1;
        unsigned BO_OFFSET : 3;
        unsigned ENABLE_PULLDOWN : 1;
        unsigned ENABLE_ILIMIT : 1;
        unsigned ENABLE_BO : 1;
        unsigned ENABLE_LINREG : 1;

    } B;
} hw_pmu_reg_2p5_t;
#endif

/*
 * constants & macros for entire PMU_REG_2P5 register
 */
#define HW_PMU_REG_2P5_ADDR      (REGS_PMU_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_2P5           (*(volatile hw_pmu_reg_2p5_t *) HW_PMU_REG_2P5_ADDR)
#define HW_PMU_REG_2P5_RD()      (HW_PMU_REG_2P5.U)
#define HW_PMU_REG_2P5_WR(v)     (HW_PMU_REG_2P5.U = (v))
#define HW_PMU_REG_2P5_SET(v)    (HW_PMU_REG_2P5_WR(HW_PMU_REG_2P5_RD() |  (v)))
#define HW_PMU_REG_2P5_CLR(v)    (HW_PMU_REG_2P5_WR(HW_PMU_REG_2P5_RD() & ~(v)))
#define HW_PMU_REG_2P5_TOG(v)    (HW_PMU_REG_2P5_WR(HW_PMU_REG_2P5_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PMU_REG_2P5 bitfields
 */

/* --- Register HW_PMU_REG_2P5, field ENABLE_WEAK_LINREG */

#define BP_PMU_REG_2P5_ENABLE_WEAK_LINREG      18
#define BM_PMU_REG_2P5_ENABLE_WEAK_LINREG      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   ((((reg32_t) v) << 18) & BM_PMU_REG_2P5_ENABLE_WEAK_LINREG)
#else
#define BF_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   (((v) << 18) & BM_PMU_REG_2P5_ENABLE_WEAK_LINREG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   BF_CS1(PMU_REG_2P5, ENABLE_WEAK_LINREG, v)
#endif

/* --- Register HW_PMU_REG_2P5, field OK_VDD2P5 */

#define BP_PMU_REG_2P5_OK_VDD2P5      17
#define BM_PMU_REG_2P5_OK_VDD2P5      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_OK_VDD2P5(v)   ((((reg32_t) v) << 17) & BM_PMU_REG_2P5_OK_VDD2P5)
#else
#define BF_PMU_REG_2P5_OK_VDD2P5(v)   (((v) << 17) & BM_PMU_REG_2P5_OK_VDD2P5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_OK_VDD2P5(v)   BF_CS1(PMU_REG_2P5, OK_VDD2P5, v)
#endif

/* --- Register HW_PMU_REG_2P5, field BO_VDD2P5 */

#define BP_PMU_REG_2P5_BO_VDD2P5      16
#define BM_PMU_REG_2P5_BO_VDD2P5      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_BO_VDD2P5(v)   ((((reg32_t) v) << 16) & BM_PMU_REG_2P5_BO_VDD2P5)
#else
#define BF_PMU_REG_2P5_BO_VDD2P5(v)   (((v) << 16) & BM_PMU_REG_2P5_BO_VDD2P5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_BO_VDD2P5(v)   BF_CS1(PMU_REG_2P5, BO_VDD2P5, v)
#endif

/* --- Register HW_PMU_REG_2P5, field OUTPUT_TRG */

#define BP_PMU_REG_2P5_OUTPUT_TRG      8
#define BM_PMU_REG_2P5_OUTPUT_TRG      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_OUTPUT_TRG(v)   ((((reg32_t) v) << 8) & BM_PMU_REG_2P5_OUTPUT_TRG)
#else
#define BF_PMU_REG_2P5_OUTPUT_TRG(v)   (((v) << 8) & BM_PMU_REG_2P5_OUTPUT_TRG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_OUTPUT_TRG(v)   BF_CS1(PMU_REG_2P5, OUTPUT_TRG, v)
#endif

/* --- Register HW_PMU_REG_2P5, field BO_OFFSET */

#define BP_PMU_REG_2P5_BO_OFFSET      4
#define BM_PMU_REG_2P5_BO_OFFSET      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_BO_OFFSET(v)   ((((reg32_t) v) << 4) & BM_PMU_REG_2P5_BO_OFFSET)
#else
#define BF_PMU_REG_2P5_BO_OFFSET(v)   (((v) << 4) & BM_PMU_REG_2P5_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_BO_OFFSET(v)   BF_CS1(PMU_REG_2P5, BO_OFFSET, v)
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_PULLDOWN */

#define BP_PMU_REG_2P5_ENABLE_PULLDOWN      3
#define BM_PMU_REG_2P5_ENABLE_PULLDOWN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_PULLDOWN(v)   ((((reg32_t) v) << 3) & BM_PMU_REG_2P5_ENABLE_PULLDOWN)
#else
#define BF_PMU_REG_2P5_ENABLE_PULLDOWN(v)   (((v) << 3) & BM_PMU_REG_2P5_ENABLE_PULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_ENABLE_PULLDOWN(v)   BF_CS1(PMU_REG_2P5, ENABLE_PULLDOWN, v)
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_ILIMIT */

#define BP_PMU_REG_2P5_ENABLE_ILIMIT      2
#define BM_PMU_REG_2P5_ENABLE_ILIMIT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_ILIMIT(v)   ((((reg32_t) v) << 2) & BM_PMU_REG_2P5_ENABLE_ILIMIT)
#else
#define BF_PMU_REG_2P5_ENABLE_ILIMIT(v)   (((v) << 2) & BM_PMU_REG_2P5_ENABLE_ILIMIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_ENABLE_ILIMIT(v)   BF_CS1(PMU_REG_2P5, ENABLE_ILIMIT, v)
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_BO */

#define BP_PMU_REG_2P5_ENABLE_BO      1
#define BM_PMU_REG_2P5_ENABLE_BO      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_BO(v)   ((((reg32_t) v) << 1) & BM_PMU_REG_2P5_ENABLE_BO)
#else
#define BF_PMU_REG_2P5_ENABLE_BO(v)   (((v) << 1) & BM_PMU_REG_2P5_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_ENABLE_BO(v)   BF_CS1(PMU_REG_2P5, ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_LINREG */

#define BP_PMU_REG_2P5_ENABLE_LINREG      0
#define BM_PMU_REG_2P5_ENABLE_LINREG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_LINREG(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_2P5_ENABLE_LINREG)
#else
#define BF_PMU_REG_2P5_ENABLE_LINREG(v)   (((v) << 0) & BM_PMU_REG_2P5_ENABLE_LINREG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_2P5_ENABLE_LINREG(v)   BF_CS1(PMU_REG_2P5, ENABLE_LINREG, v)
#endif

/*
 * HW_PMU_REG_3P0 - Regulator 3P0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned OK_VDD3P0 : 1;
        unsigned BO_VDD3P0 : 1;
        unsigned RESERVED1 : 3;
        unsigned OUTPUT_TRG : 5;
        unsigned REG_3P0_VBUS_SEL : 1;
        unsigned BO_OFFSET : 3;
        unsigned RESERVED2 : 1;
        unsigned ENABLE_ILIMIT : 1;
        unsigned ENABLE_BO : 1;
        unsigned ENABLE_LINREG : 1;

    } B;
} hw_pmu_reg_3p0_t;
#endif

/*
 * constants & macros for entire PMU_REG_3P0 register
 */
#define HW_PMU_REG_3P0_ADDR      (REGS_PMU_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_3P0           (*(volatile hw_pmu_reg_3p0_t *) HW_PMU_REG_3P0_ADDR)
#define HW_PMU_REG_3P0_RD()      (HW_PMU_REG_3P0.U)
#define HW_PMU_REG_3P0_WR(v)     (HW_PMU_REG_3P0.U = (v))
#define HW_PMU_REG_3P0_SET(v)    (HW_PMU_REG_3P0_WR(HW_PMU_REG_3P0_RD() |  (v)))
#define HW_PMU_REG_3P0_CLR(v)    (HW_PMU_REG_3P0_WR(HW_PMU_REG_3P0_RD() & ~(v)))
#define HW_PMU_REG_3P0_TOG(v)    (HW_PMU_REG_3P0_WR(HW_PMU_REG_3P0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PMU_REG_3P0 bitfields
 */

/* --- Register HW_PMU_REG_3P0, field OK_VDD3P0 */

#define BP_PMU_REG_3P0_OK_VDD3P0      17
#define BM_PMU_REG_3P0_OK_VDD3P0      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_OK_VDD3P0(v)   ((((reg32_t) v) << 17) & BM_PMU_REG_3P0_OK_VDD3P0)
#else
#define BF_PMU_REG_3P0_OK_VDD3P0(v)   (((v) << 17) & BM_PMU_REG_3P0_OK_VDD3P0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_3P0_OK_VDD3P0(v)   BF_CS1(PMU_REG_3P0, OK_VDD3P0, v)
#endif

/* --- Register HW_PMU_REG_3P0, field BO_VDD3P0 */

#define BP_PMU_REG_3P0_BO_VDD3P0      16
#define BM_PMU_REG_3P0_BO_VDD3P0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_BO_VDD3P0(v)   ((((reg32_t) v) << 16) & BM_PMU_REG_3P0_BO_VDD3P0)
#else
#define BF_PMU_REG_3P0_BO_VDD3P0(v)   (((v) << 16) & BM_PMU_REG_3P0_BO_VDD3P0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_3P0_BO_VDD3P0(v)   BF_CS1(PMU_REG_3P0, BO_VDD3P0, v)
#endif

/* --- Register HW_PMU_REG_3P0, field OUTPUT_TRG */

#define BP_PMU_REG_3P0_OUTPUT_TRG      8
#define BM_PMU_REG_3P0_OUTPUT_TRG      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_OUTPUT_TRG(v)   ((((reg32_t) v) << 8) & BM_PMU_REG_3P0_OUTPUT_TRG)
#else
#define BF_PMU_REG_3P0_OUTPUT_TRG(v)   (((v) << 8) & BM_PMU_REG_3P0_OUTPUT_TRG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_3P0_OUTPUT_TRG(v)   BF_CS1(PMU_REG_3P0, OUTPUT_TRG, v)
#endif

/* --- Register HW_PMU_REG_3P0, field REG_3P0_VBUS_SEL */

#define BP_PMU_REG_3P0_REG_3P0_VBUS_SEL      7
#define BM_PMU_REG_3P0_REG_3P0_VBUS_SEL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   ((((reg32_t) v) << 7) & BM_PMU_REG_3P0_REG_3P0_VBUS_SEL)
#else
#define BF_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   (((v) << 7) & BM_PMU_REG_3P0_REG_3P0_VBUS_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   BF_CS1(PMU_REG_3P0, REG_3P0_VBUS_SEL, v)
#endif

/* --- Register HW_PMU_REG_3P0, field BO_OFFSET */

#define BP_PMU_REG_3P0_BO_OFFSET      4
#define BM_PMU_REG_3P0_BO_OFFSET      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_BO_OFFSET(v)   ((((reg32_t) v) << 4) & BM_PMU_REG_3P0_BO_OFFSET)
#else
#define BF_PMU_REG_3P0_BO_OFFSET(v)   (((v) << 4) & BM_PMU_REG_3P0_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_3P0_BO_OFFSET(v)   BF_CS1(PMU_REG_3P0, BO_OFFSET, v)
#endif

/* --- Register HW_PMU_REG_3P0, field ENABLE_ILIMIT */

#define BP_PMU_REG_3P0_ENABLE_ILIMIT      2
#define BM_PMU_REG_3P0_ENABLE_ILIMIT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_ENABLE_ILIMIT(v)   ((((reg32_t) v) << 2) & BM_PMU_REG_3P0_ENABLE_ILIMIT)
#else
#define BF_PMU_REG_3P0_ENABLE_ILIMIT(v)   (((v) << 2) & BM_PMU_REG_3P0_ENABLE_ILIMIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_3P0_ENABLE_ILIMIT(v)   BF_CS1(PMU_REG_3P0, ENABLE_ILIMIT, v)
#endif

/* --- Register HW_PMU_REG_3P0, field ENABLE_BO */

#define BP_PMU_REG_3P0_ENABLE_BO      1
#define BM_PMU_REG_3P0_ENABLE_BO      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_ENABLE_BO(v)   ((((reg32_t) v) << 1) & BM_PMU_REG_3P0_ENABLE_BO)
#else
#define BF_PMU_REG_3P0_ENABLE_BO(v)   (((v) << 1) & BM_PMU_REG_3P0_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_3P0_ENABLE_BO(v)   BF_CS1(PMU_REG_3P0, ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_3P0, field ENABLE_LINREG */

#define BP_PMU_REG_3P0_ENABLE_LINREG      0
#define BM_PMU_REG_3P0_ENABLE_LINREG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_ENABLE_LINREG(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_3P0_ENABLE_LINREG)
#else
#define BF_PMU_REG_3P0_ENABLE_LINREG(v)   (((v) << 0) & BM_PMU_REG_3P0_ENABLE_LINREG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PMU_REG_3P0_ENABLE_LINREG(v)   BF_CS1(PMU_REG_3P0, ENABLE_LINREG, v)
#endif


#endif // _PMU_H

