/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CCM_H
#define _CCM_H

#include "regs.h"

#ifndef REGS_CCM_BASE
#define REGS_CCM_BASE (REGS_BASE + 0x020c4000)

#endif


/*
 * HW_CCM_CCR - CCM Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OSCNT : 8;
        unsigned RESERVED : 4;
        unsigned COSC_EN : 1;
        unsigned RESERVED0 : 3;
        unsigned WB_COUNT : 3;
        unsigned RESERVED1 : 2;
        unsigned REG_BYPASS_COUNT : 6;
        unsigned RBC_EN : 1;
        unsigned RESERVED2 : 4;

    } B;
} hw_ccm_ccr_t;
#endif

/*
 * constants & macros for entire CCM_CCR register
 */
#define HW_CCM_CCR_ADDR      (REGS_CCM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCR           (*(volatile hw_ccm_ccr_t *) HW_CCM_CCR_ADDR)
#define HW_CCM_CCR_RD()      (HW_CCM_CCR.U)
#define HW_CCM_CCR_WR(v)     (HW_CCM_CCR.U = (v))
#define HW_CCM_CCR_SET(v)    (HW_CCM_CCR_WR(HW_CCM_CCR_RD() |  (v)))
#define HW_CCM_CCR_CLR(v)    (HW_CCM_CCR_WR(HW_CCM_CCR_RD() & ~(v)))
#define HW_CCM_CCR_TOG(v)    (HW_CCM_CCR_WR(HW_CCM_CCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCR bitfields
 */

/* --- Register HW_CCM_CCR, field OSCNT */

#define BP_CCM_CCR_OSCNT      0
#define BM_CCM_CCR_OSCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_OSCNT(v)   ((((reg32_t) v) << 0) & BM_CCM_CCR_OSCNT)
#else
#define BF_CCM_CCR_OSCNT(v)   (((v) << 0) & BM_CCM_CCR_OSCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_OSCNT(v)   BF_CS1(CCM_CCR, OSCNT, v)
#endif

/* --- Register HW_CCM_CCR, field RESERVED */

#define BP_CCM_CCR_RESERVED      8
#define BM_CCM_CCR_RESERVED      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_RESERVED(v)   ((((reg32_t) v) << 8) & BM_CCM_CCR_RESERVED)
#else
#define BF_CCM_CCR_RESERVED(v)   (((v) << 8) & BM_CCM_CCR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_RESERVED(v)   BF_CS1(CCM_CCR, RESERVED, v)
#endif

/* --- Register HW_CCM_CCR, field COSC_EN */

#define BP_CCM_CCR_COSC_EN      12
#define BM_CCM_CCR_COSC_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_COSC_EN(v)   ((((reg32_t) v) << 12) & BM_CCM_CCR_COSC_EN)
#else
#define BF_CCM_CCR_COSC_EN(v)   (((v) << 12) & BM_CCM_CCR_COSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_COSC_EN(v)   BF_CS1(CCM_CCR, COSC_EN, v)
#endif

/* --- Register HW_CCM_CCR, field WB_COUNT */

#define BP_CCM_CCR_WB_COUNT      16
#define BM_CCM_CCR_WB_COUNT      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_WB_COUNT(v)   ((((reg32_t) v) << 16) & BM_CCM_CCR_WB_COUNT)
#else
#define BF_CCM_CCR_WB_COUNT(v)   (((v) << 16) & BM_CCM_CCR_WB_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_WB_COUNT(v)   BF_CS1(CCM_CCR, WB_COUNT, v)
#endif

/* --- Register HW_CCM_CCR, field REG_BYPASS_COUNT */

#define BP_CCM_CCR_REG_BYPASS_COUNT      21
#define BM_CCM_CCR_REG_BYPASS_COUNT      0x07e00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_REG_BYPASS_COUNT(v)   ((((reg32_t) v) << 21) & BM_CCM_CCR_REG_BYPASS_COUNT)
#else
#define BF_CCM_CCR_REG_BYPASS_COUNT(v)   (((v) << 21) & BM_CCM_CCR_REG_BYPASS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_REG_BYPASS_COUNT(v)   BF_CS1(CCM_CCR, REG_BYPASS_COUNT, v)
#endif

/* --- Register HW_CCM_CCR, field RBC_EN */

#define BP_CCM_CCR_RBC_EN      27
#define BM_CCM_CCR_RBC_EN      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_RBC_EN(v)   ((((reg32_t) v) << 27) & BM_CCM_CCR_RBC_EN)
#else
#define BF_CCM_CCR_RBC_EN(v)   (((v) << 27) & BM_CCM_CCR_RBC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_RBC_EN(v)   BF_CS1(CCM_CCR, RBC_EN, v)
#endif

/*
 * HW_CCM_CCDR - CCM Control Divider Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned MMDC_CH1_MASK : 1;
        unsigned MMDC_CH0_MASK : 1;
        unsigned RESERVED1 : 14;

    } B;
} hw_ccm_ccdr_t;
#endif

/*
 * constants & macros for entire CCM_CCDR register
 */
#define HW_CCM_CCDR_ADDR      (REGS_CCM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCDR           (*(volatile hw_ccm_ccdr_t *) HW_CCM_CCDR_ADDR)
#define HW_CCM_CCDR_RD()      (HW_CCM_CCDR.U)
#define HW_CCM_CCDR_WR(v)     (HW_CCM_CCDR.U = (v))
#define HW_CCM_CCDR_SET(v)    (HW_CCM_CCDR_WR(HW_CCM_CCDR_RD() |  (v)))
#define HW_CCM_CCDR_CLR(v)    (HW_CCM_CCDR_WR(HW_CCM_CCDR_RD() & ~(v)))
#define HW_CCM_CCDR_TOG(v)    (HW_CCM_CCDR_WR(HW_CCM_CCDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCDR bitfields
 */

/* --- Register HW_CCM_CCDR, field MMDC_CH1_MASK */

#define BP_CCM_CCDR_MMDC_CH1_MASK      16
#define BM_CCM_CCDR_MMDC_CH1_MASK      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCDR_MMDC_CH1_MASK(v)   ((((reg32_t) v) << 16) & BM_CCM_CCDR_MMDC_CH1_MASK)
#else
#define BF_CCM_CCDR_MMDC_CH1_MASK(v)   (((v) << 16) & BM_CCM_CCDR_MMDC_CH1_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCDR_MMDC_CH1_MASK(v)   BF_CS1(CCM_CCDR, MMDC_CH1_MASK, v)
#endif

/* --- Register HW_CCM_CCDR, field MMDC_CH0_MASK */

#define BP_CCM_CCDR_MMDC_CH0_MASK      17
#define BM_CCM_CCDR_MMDC_CH0_MASK      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCDR_MMDC_CH0_MASK(v)   ((((reg32_t) v) << 17) & BM_CCM_CCDR_MMDC_CH0_MASK)
#else
#define BF_CCM_CCDR_MMDC_CH0_MASK(v)   (((v) << 17) & BM_CCM_CCDR_MMDC_CH0_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCDR_MMDC_CH0_MASK(v)   BF_CS1(CCM_CCDR, MMDC_CH0_MASK, v)
#endif

/*
 * HW_CCM_CSR - CCM Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned REF_EN_B : 1;
        unsigned RESERVED0 : 3;
        unsigned RESERVED1 : 1;
        unsigned COSC_READY : 1;
        unsigned RESERVED2 : 26;

    } B;
} hw_ccm_csr_t;
#endif

/*
 * constants & macros for entire CCM_CSR register
 */
#define HW_CCM_CSR_ADDR      (REGS_CCM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSR           (*(volatile hw_ccm_csr_t *) HW_CCM_CSR_ADDR)
#define HW_CCM_CSR_RD()      (HW_CCM_CSR.U)
#define HW_CCM_CSR_WR(v)     (HW_CCM_CSR.U = (v))
#define HW_CCM_CSR_SET(v)    (HW_CCM_CSR_WR(HW_CCM_CSR_RD() |  (v)))
#define HW_CCM_CSR_CLR(v)    (HW_CCM_CSR_WR(HW_CCM_CSR_RD() & ~(v)))
#define HW_CCM_CSR_TOG(v)    (HW_CCM_CSR_WR(HW_CCM_CSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSR bitfields
 */

/* --- Register HW_CCM_CSR, field REF_EN_B */

#define BP_CCM_CSR_REF_EN_B      0
#define BM_CCM_CSR_REF_EN_B      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSR_REF_EN_B(v)   ((((reg32_t) v) << 0) & BM_CCM_CSR_REF_EN_B)
#else
#define BF_CCM_CSR_REF_EN_B(v)   (((v) << 0) & BM_CCM_CSR_REF_EN_B)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSR_REF_EN_B(v)   BF_CS1(CCM_CSR, REF_EN_B, v)
#endif

/* --- Register HW_CCM_CSR, field COSC_READY */

#define BP_CCM_CSR_COSC_READY      5
#define BM_CCM_CSR_COSC_READY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSR_COSC_READY(v)   ((((reg32_t) v) << 5) & BM_CCM_CSR_COSC_READY)
#else
#define BF_CCM_CSR_COSC_READY(v)   (((v) << 5) & BM_CCM_CSR_COSC_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSR_COSC_READY(v)   BF_CS1(CCM_CSR, COSC_READY, v)
#endif

/*
 * HW_CCM_CCSR - CCM Clock Swither Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PLL3_SW_CLK_SEL : 1;
        unsigned PLL2_SW_CLK_SEL : 1;
        unsigned PLL1_SW_CLK_SEL : 1;
        unsigned RESERVED0 : 5;
        unsigned STEP_SEL : 1;
        unsigned PDF_396M_DIS_MASK : 1;
        unsigned PDF_352M_DIS_MASK : 1;
        unsigned PDF_594M_DIS_MASK : 1;
        unsigned PDF_508M_DIS_MASK : 1;
        unsigned PDF_454M_DIS_MASK : 1;
        unsigned PDF_720M_DIS_MASK : 1;
        unsigned PDF_540M_DIS_MASK : 1;
        unsigned RESERVED1 : 16;

    } B;
} hw_ccm_ccsr_t;
#endif

/*
 * constants & macros for entire CCM_CCSR register
 */
#define HW_CCM_CCSR_ADDR      (REGS_CCM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCSR           (*(volatile hw_ccm_ccsr_t *) HW_CCM_CCSR_ADDR)
#define HW_CCM_CCSR_RD()      (HW_CCM_CCSR.U)
#define HW_CCM_CCSR_WR(v)     (HW_CCM_CCSR.U = (v))
#define HW_CCM_CCSR_SET(v)    (HW_CCM_CCSR_WR(HW_CCM_CCSR_RD() |  (v)))
#define HW_CCM_CCSR_CLR(v)    (HW_CCM_CCSR_WR(HW_CCM_CCSR_RD() & ~(v)))
#define HW_CCM_CCSR_TOG(v)    (HW_CCM_CCSR_WR(HW_CCM_CCSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCSR bitfields
 */

/* --- Register HW_CCM_CCSR, field PLL3_SW_CLK_SEL */

#define BP_CCM_CCSR_PLL3_SW_CLK_SEL      0
#define BM_CCM_CCSR_PLL3_SW_CLK_SEL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PLL3_SW_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CCSR_PLL3_SW_CLK_SEL)
#else
#define BF_CCM_CCSR_PLL3_SW_CLK_SEL(v)   (((v) << 0) & BM_CCM_CCSR_PLL3_SW_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PLL3_SW_CLK_SEL(v)   BF_CS1(CCM_CCSR, PLL3_SW_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CCSR, field PLL2_SW_CLK_SEL */

#define BP_CCM_CCSR_PLL2_SW_CLK_SEL      1
#define BM_CCM_CCSR_PLL2_SW_CLK_SEL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PLL2_SW_CLK_SEL(v)   ((((reg32_t) v) << 1) & BM_CCM_CCSR_PLL2_SW_CLK_SEL)
#else
#define BF_CCM_CCSR_PLL2_SW_CLK_SEL(v)   (((v) << 1) & BM_CCM_CCSR_PLL2_SW_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PLL2_SW_CLK_SEL(v)   BF_CS1(CCM_CCSR, PLL2_SW_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CCSR, field PLL1_SW_CLK_SEL */

#define BP_CCM_CCSR_PLL1_SW_CLK_SEL      2
#define BM_CCM_CCSR_PLL1_SW_CLK_SEL      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PLL1_SW_CLK_SEL(v)   ((((reg32_t) v) << 2) & BM_CCM_CCSR_PLL1_SW_CLK_SEL)
#else
#define BF_CCM_CCSR_PLL1_SW_CLK_SEL(v)   (((v) << 2) & BM_CCM_CCSR_PLL1_SW_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PLL1_SW_CLK_SEL(v)   BF_CS1(CCM_CCSR, PLL1_SW_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CCSR, field STEP_SEL */

#define BP_CCM_CCSR_STEP_SEL      8
#define BM_CCM_CCSR_STEP_SEL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_STEP_SEL(v)   ((((reg32_t) v) << 8) & BM_CCM_CCSR_STEP_SEL)
#else
#define BF_CCM_CCSR_STEP_SEL(v)   (((v) << 8) & BM_CCM_CCSR_STEP_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_STEP_SEL(v)   BF_CS1(CCM_CCSR, STEP_SEL, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_396M_DIS_MASK */

#define BP_CCM_CCSR_PDF_396M_DIS_MASK      9
#define BM_CCM_CCSR_PDF_396M_DIS_MASK      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_396M_DIS_MASK(v)   ((((reg32_t) v) << 9) & BM_CCM_CCSR_PDF_396M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_396M_DIS_MASK(v)   (((v) << 9) & BM_CCM_CCSR_PDF_396M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_396M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_396M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_352M_DIS_MASK */

#define BP_CCM_CCSR_PDF_352M_DIS_MASK      10
#define BM_CCM_CCSR_PDF_352M_DIS_MASK      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_352M_DIS_MASK(v)   ((((reg32_t) v) << 10) & BM_CCM_CCSR_PDF_352M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_352M_DIS_MASK(v)   (((v) << 10) & BM_CCM_CCSR_PDF_352M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_352M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_352M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_594M_DIS_MASK */

#define BP_CCM_CCSR_PDF_594M_DIS_MASK      11
#define BM_CCM_CCSR_PDF_594M_DIS_MASK      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_594M_DIS_MASK(v)   ((((reg32_t) v) << 11) & BM_CCM_CCSR_PDF_594M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_594M_DIS_MASK(v)   (((v) << 11) & BM_CCM_CCSR_PDF_594M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_594M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_594M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_508M_DIS_MASK */

#define BP_CCM_CCSR_PDF_508M_DIS_MASK      12
#define BM_CCM_CCSR_PDF_508M_DIS_MASK      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_508M_DIS_MASK(v)   ((((reg32_t) v) << 12) & BM_CCM_CCSR_PDF_508M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_508M_DIS_MASK(v)   (((v) << 12) & BM_CCM_CCSR_PDF_508M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_508M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_508M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_454M_DIS_MASK */

#define BP_CCM_CCSR_PDF_454M_DIS_MASK      13
#define BM_CCM_CCSR_PDF_454M_DIS_MASK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_454M_DIS_MASK(v)   ((((reg32_t) v) << 13) & BM_CCM_CCSR_PDF_454M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_454M_DIS_MASK(v)   (((v) << 13) & BM_CCM_CCSR_PDF_454M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_454M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_454M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_720M_DIS_MASK */

#define BP_CCM_CCSR_PDF_720M_DIS_MASK      14
#define BM_CCM_CCSR_PDF_720M_DIS_MASK      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_720M_DIS_MASK(v)   ((((reg32_t) v) << 14) & BM_CCM_CCSR_PDF_720M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_720M_DIS_MASK(v)   (((v) << 14) & BM_CCM_CCSR_PDF_720M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_720M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_720M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_540M_DIS_MASK */

#define BP_CCM_CCSR_PDF_540M_DIS_MASK      15
#define BM_CCM_CCSR_PDF_540M_DIS_MASK      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_540M_DIS_MASK(v)   ((((reg32_t) v) << 15) & BM_CCM_CCSR_PDF_540M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_540M_DIS_MASK(v)   (((v) << 15) & BM_CCM_CCSR_PDF_540M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_540M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_540M_DIS_MASK, v)
#endif

/*
 * HW_CCM_CACRR - CCM Arm Clock Root Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ARM_PODF : 3;
        unsigned RESERVED0 : 29;

    } B;
} hw_ccm_cacrr_t;
#endif

/*
 * constants & macros for entire CCM_CACRR register
 */
#define HW_CCM_CACRR_ADDR      (REGS_CCM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CACRR           (*(volatile hw_ccm_cacrr_t *) HW_CCM_CACRR_ADDR)
#define HW_CCM_CACRR_RD()      (HW_CCM_CACRR.U)
#define HW_CCM_CACRR_WR(v)     (HW_CCM_CACRR.U = (v))
#define HW_CCM_CACRR_SET(v)    (HW_CCM_CACRR_WR(HW_CCM_CACRR_RD() |  (v)))
#define HW_CCM_CACRR_CLR(v)    (HW_CCM_CACRR_WR(HW_CCM_CACRR_RD() & ~(v)))
#define HW_CCM_CACRR_TOG(v)    (HW_CCM_CACRR_WR(HW_CCM_CACRR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CACRR bitfields
 */

/* --- Register HW_CCM_CACRR, field ARM_PODF */

#define BP_CCM_CACRR_ARM_PODF      0
#define BM_CCM_CACRR_ARM_PODF      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CACRR_ARM_PODF(v)   ((((reg32_t) v) << 0) & BM_CCM_CACRR_ARM_PODF)
#else
#define BF_CCM_CACRR_ARM_PODF(v)   (((v) << 0) & BM_CCM_CACRR_ARM_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CACRR_ARM_PODF(v)   BF_CS1(CCM_CACRR, ARM_PODF, v)
#endif

/*
 * HW_CCM_CBCDR - CCM Bus Clock Divider Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PERIPH2_CLK2_PODF : 3;
        unsigned MMDC_CH1_AXI_PODF : 3;
        unsigned AXI_SEL : 1;
        unsigned AXI_ALT_SEL : 1;
        unsigned IPG_PODF : 2;
        unsigned AHB_PODF : 3;
        unsigned RESERVED0 : 3;
        unsigned AXI_PODF : 3;
        unsigned MMDC_CH0_AXI_PODF : 3;
        unsigned RESERVED1 : 3;
        unsigned PERIPH_CLK_SEL : 1;
        unsigned PERIPH2_CLK_SEL : 1;
        unsigned PERIPH_CLK2_PODF : 3;
        unsigned RESERVED2 : 2;

    } B;
} hw_ccm_cbcdr_t;
#endif

/*
 * constants & macros for entire CCM_CBCDR register
 */
#define HW_CCM_CBCDR_ADDR      (REGS_CCM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CBCDR           (*(volatile hw_ccm_cbcdr_t *) HW_CCM_CBCDR_ADDR)
#define HW_CCM_CBCDR_RD()      (HW_CCM_CBCDR.U)
#define HW_CCM_CBCDR_WR(v)     (HW_CCM_CBCDR.U = (v))
#define HW_CCM_CBCDR_SET(v)    (HW_CCM_CBCDR_WR(HW_CCM_CBCDR_RD() |  (v)))
#define HW_CCM_CBCDR_CLR(v)    (HW_CCM_CBCDR_WR(HW_CCM_CBCDR_RD() & ~(v)))
#define HW_CCM_CBCDR_TOG(v)    (HW_CCM_CBCDR_WR(HW_CCM_CBCDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CBCDR bitfields
 */

/* --- Register HW_CCM_CBCDR, field PERIPH2_CLK2_PODF */

#define BP_CCM_CBCDR_PERIPH2_CLK2_PODF      0
#define BM_CCM_CBCDR_PERIPH2_CLK2_PODF      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_PERIPH2_CLK2_PODF(v)   ((((reg32_t) v) << 0) & BM_CCM_CBCDR_PERIPH2_CLK2_PODF)
#else
#define BF_CCM_CBCDR_PERIPH2_CLK2_PODF(v)   (((v) << 0) & BM_CCM_CBCDR_PERIPH2_CLK2_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_PERIPH2_CLK2_PODF(v)   BF_CS1(CCM_CBCDR, PERIPH2_CLK2_PODF, v)
#endif

/* --- Register HW_CCM_CBCDR, field MMDC_CH1_AXI_PODF */

#define BP_CCM_CBCDR_MMDC_CH1_AXI_PODF      3
#define BM_CCM_CBCDR_MMDC_CH1_AXI_PODF      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   ((((reg32_t) v) << 3) & BM_CCM_CBCDR_MMDC_CH1_AXI_PODF)
#else
#define BF_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   (((v) << 3) & BM_CCM_CBCDR_MMDC_CH1_AXI_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   BF_CS1(CCM_CBCDR, MMDC_CH1_AXI_PODF, v)
#endif

/* --- Register HW_CCM_CBCDR, field AXI_SEL */

#define BP_CCM_CBCDR_AXI_SEL      6
#define BM_CCM_CBCDR_AXI_SEL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_AXI_SEL(v)   ((((reg32_t) v) << 6) & BM_CCM_CBCDR_AXI_SEL)
#else
#define BF_CCM_CBCDR_AXI_SEL(v)   (((v) << 6) & BM_CCM_CBCDR_AXI_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_AXI_SEL(v)   BF_CS1(CCM_CBCDR, AXI_SEL, v)
#endif

/* --- Register HW_CCM_CBCDR, field AXI_ALT_SEL */

#define BP_CCM_CBCDR_AXI_ALT_SEL      7
#define BM_CCM_CBCDR_AXI_ALT_SEL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_AXI_ALT_SEL(v)   ((((reg32_t) v) << 7) & BM_CCM_CBCDR_AXI_ALT_SEL)
#else
#define BF_CCM_CBCDR_AXI_ALT_SEL(v)   (((v) << 7) & BM_CCM_CBCDR_AXI_ALT_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_AXI_ALT_SEL(v)   BF_CS1(CCM_CBCDR, AXI_ALT_SEL, v)
#endif

/* --- Register HW_CCM_CBCDR, field IPG_PODF */

#define BP_CCM_CBCDR_IPG_PODF      8
#define BM_CCM_CBCDR_IPG_PODF      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_IPG_PODF(v)   ((((reg32_t) v) << 8) & BM_CCM_CBCDR_IPG_PODF)
#else
#define BF_CCM_CBCDR_IPG_PODF(v)   (((v) << 8) & BM_CCM_CBCDR_IPG_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_IPG_PODF(v)   BF_CS1(CCM_CBCDR, IPG_PODF, v)
#endif

/* --- Register HW_CCM_CBCDR, field AHB_PODF */

#define BP_CCM_CBCDR_AHB_PODF      10
#define BM_CCM_CBCDR_AHB_PODF      0x00001c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_AHB_PODF(v)   ((((reg32_t) v) << 10) & BM_CCM_CBCDR_AHB_PODF)
#else
#define BF_CCM_CBCDR_AHB_PODF(v)   (((v) << 10) & BM_CCM_CBCDR_AHB_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_AHB_PODF(v)   BF_CS1(CCM_CBCDR, AHB_PODF, v)
#endif

/* --- Register HW_CCM_CBCDR, field AXI_PODF */

#define BP_CCM_CBCDR_AXI_PODF      16
#define BM_CCM_CBCDR_AXI_PODF      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_AXI_PODF(v)   ((((reg32_t) v) << 16) & BM_CCM_CBCDR_AXI_PODF)
#else
#define BF_CCM_CBCDR_AXI_PODF(v)   (((v) << 16) & BM_CCM_CBCDR_AXI_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_AXI_PODF(v)   BF_CS1(CCM_CBCDR, AXI_PODF, v)
#endif

/* --- Register HW_CCM_CBCDR, field MMDC_CH0_AXI_PODF */

#define BP_CCM_CBCDR_MMDC_CH0_AXI_PODF      19
#define BM_CCM_CBCDR_MMDC_CH0_AXI_PODF      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_MMDC_CH0_AXI_PODF(v)   ((((reg32_t) v) << 19) & BM_CCM_CBCDR_MMDC_CH0_AXI_PODF)
#else
#define BF_CCM_CBCDR_MMDC_CH0_AXI_PODF(v)   (((v) << 19) & BM_CCM_CBCDR_MMDC_CH0_AXI_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_MMDC_CH0_AXI_PODF(v)   BF_CS1(CCM_CBCDR, MMDC_CH0_AXI_PODF, v)
#endif

/* --- Register HW_CCM_CBCDR, field PERIPH_CLK_SEL */

#define BP_CCM_CBCDR_PERIPH_CLK_SEL      25
#define BM_CCM_CBCDR_PERIPH_CLK_SEL      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_PERIPH_CLK_SEL(v)   ((((reg32_t) v) << 25) & BM_CCM_CBCDR_PERIPH_CLK_SEL)
#else
#define BF_CCM_CBCDR_PERIPH_CLK_SEL(v)   (((v) << 25) & BM_CCM_CBCDR_PERIPH_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_PERIPH_CLK_SEL(v)   BF_CS1(CCM_CBCDR, PERIPH_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCDR, field PERIPH2_CLK_SEL */

#define BP_CCM_CBCDR_PERIPH2_CLK_SEL      26
#define BM_CCM_CBCDR_PERIPH2_CLK_SEL      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_PERIPH2_CLK_SEL(v)   ((((reg32_t) v) << 26) & BM_CCM_CBCDR_PERIPH2_CLK_SEL)
#else
#define BF_CCM_CBCDR_PERIPH2_CLK_SEL(v)   (((v) << 26) & BM_CCM_CBCDR_PERIPH2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_PERIPH2_CLK_SEL(v)   BF_CS1(CCM_CBCDR, PERIPH2_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCDR, field PERIPH_CLK2_PODF */

#define BP_CCM_CBCDR_PERIPH_CLK2_PODF      27
#define BM_CCM_CBCDR_PERIPH_CLK2_PODF      0x38000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_PERIPH_CLK2_PODF(v)   ((((reg32_t) v) << 27) & BM_CCM_CBCDR_PERIPH_CLK2_PODF)
#else
#define BF_CCM_CBCDR_PERIPH_CLK2_PODF(v)   (((v) << 27) & BM_CCM_CBCDR_PERIPH_CLK2_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_PERIPH_CLK2_PODF(v)   BF_CS1(CCM_CBCDR, PERIPH_CLK2_PODF, v)
#endif

/*
 * HW_CCM_CBCMR - CCM Bus Clock Multiplexer Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPU2D_AXI_CLK_SEL : 1;
        unsigned GPU3D_AXI_CLK_SEL : 1;
        unsigned RESERVED0 : 2;
        unsigned GPU3D_CORE_CLK_SEL : 2;
        unsigned RESERVED1 : 2;
        unsigned GPU3D_SHADER_CLK_SEL : 2;
        unsigned PCIE_AXI_CLK_SEL : 1;
        unsigned VDOAXI_CLK_SEL : 1;
        unsigned PERIPH_CLK2_SEL : 2;
        unsigned VPU_AXI_CLK_SEL : 2;
        unsigned GPU2D_CLK_SEL : 2;
        unsigned PRE_PERIPH_CLK_SEL : 2;
        unsigned PERIPH2_CLK2_SEL : 1;
        unsigned PRE_PERIPH2_CLK_SEL : 2;
        unsigned GPU2D_CORE_CLK_PODF : 3;
        unsigned GPU3D_CORE_PODF : 3;
        unsigned GPU3D_SHADER_PODF : 3;

    } B;
} hw_ccm_cbcmr_t;
#endif

/*
 * constants & macros for entire CCM_CBCMR register
 */
#define HW_CCM_CBCMR_ADDR      (REGS_CCM_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CBCMR           (*(volatile hw_ccm_cbcmr_t *) HW_CCM_CBCMR_ADDR)
#define HW_CCM_CBCMR_RD()      (HW_CCM_CBCMR.U)
#define HW_CCM_CBCMR_WR(v)     (HW_CCM_CBCMR.U = (v))
#define HW_CCM_CBCMR_SET(v)    (HW_CCM_CBCMR_WR(HW_CCM_CBCMR_RD() |  (v)))
#define HW_CCM_CBCMR_CLR(v)    (HW_CCM_CBCMR_WR(HW_CCM_CBCMR_RD() & ~(v)))
#define HW_CCM_CBCMR_TOG(v)    (HW_CCM_CBCMR_WR(HW_CCM_CBCMR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CBCMR bitfields
 */

/* --- Register HW_CCM_CBCMR, field GPU2D_AXI_CLK_SEL */

#define BP_CCM_CBCMR_GPU2D_AXI_CLK_SEL      0
#define BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   (((v) << 0) & BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, GPU2D_AXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_AXI_CLK_SEL */

#define BP_CCM_CBCMR_GPU3D_AXI_CLK_SEL      1
#define BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   ((((reg32_t) v) << 1) & BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   (((v) << 1) & BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, GPU3D_AXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_CORE_CLK_SEL */

#define BP_CCM_CBCMR_GPU3D_CORE_CLK_SEL      4
#define BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_CORE_CLK_SEL(v)   ((((reg32_t) v) << 4) & BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL)
#else
#define BF_CCM_CBCMR_GPU3D_CORE_CLK_SEL(v)   (((v) << 4) & BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_CORE_CLK_SEL(v)   BF_CS1(CCM_CBCMR, GPU3D_CORE_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_SHADER_CLK_SEL */

#define BP_CCM_CBCMR_GPU3D_SHADER_CLK_SEL      8
#define BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_SHADER_CLK_SEL(v)   ((((reg32_t) v) << 8) & BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL)
#else
#define BF_CCM_CBCMR_GPU3D_SHADER_CLK_SEL(v)   (((v) << 8) & BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_SHADER_CLK_SEL(v)   BF_CS1(CCM_CBCMR, GPU3D_SHADER_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field PCIE_AXI_CLK_SEL */

#define BP_CCM_CBCMR_PCIE_AXI_CLK_SEL      10
#define BM_CCM_CBCMR_PCIE_AXI_CLK_SEL      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   ((((reg32_t) v) << 10) & BM_CCM_CBCMR_PCIE_AXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   (((v) << 10) & BM_CCM_CBCMR_PCIE_AXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, PCIE_AXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field VDOAXI_CLK_SEL */

#define BP_CCM_CBCMR_VDOAXI_CLK_SEL      11
#define BM_CCM_CBCMR_VDOAXI_CLK_SEL      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_VDOAXI_CLK_SEL(v)   ((((reg32_t) v) << 11) & BM_CCM_CBCMR_VDOAXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_VDOAXI_CLK_SEL(v)   (((v) << 11) & BM_CCM_CBCMR_VDOAXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_VDOAXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, VDOAXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field PERIPH_CLK2_SEL */

#define BP_CCM_CBCMR_PERIPH_CLK2_SEL      12
#define BM_CCM_CBCMR_PERIPH_CLK2_SEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PERIPH_CLK2_SEL(v)   ((((reg32_t) v) << 12) & BM_CCM_CBCMR_PERIPH_CLK2_SEL)
#else
#define BF_CCM_CBCMR_PERIPH_CLK2_SEL(v)   (((v) << 12) & BM_CCM_CBCMR_PERIPH_CLK2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PERIPH_CLK2_SEL(v)   BF_CS1(CCM_CBCMR, PERIPH_CLK2_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field VPU_AXI_CLK_SEL */

#define BP_CCM_CBCMR_VPU_AXI_CLK_SEL      14
#define BM_CCM_CBCMR_VPU_AXI_CLK_SEL      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   ((((reg32_t) v) << 14) & BM_CCM_CBCMR_VPU_AXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   (((v) << 14) & BM_CCM_CBCMR_VPU_AXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, VPU_AXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU2D_CLK_SEL */

#define BP_CCM_CBCMR_GPU2D_CLK_SEL      16
#define BM_CCM_CBCMR_GPU2D_CLK_SEL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU2D_CLK_SEL(v)   ((((reg32_t) v) << 16) & BM_CCM_CBCMR_GPU2D_CLK_SEL)
#else
#define BF_CCM_CBCMR_GPU2D_CLK_SEL(v)   (((v) << 16) & BM_CCM_CBCMR_GPU2D_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU2D_CLK_SEL(v)   BF_CS1(CCM_CBCMR, GPU2D_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field PRE_PERIPH_CLK_SEL */

#define BP_CCM_CBCMR_PRE_PERIPH_CLK_SEL      18
#define BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PRE_PERIPH_CLK_SEL(v)   ((((reg32_t) v) << 18) & BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL)
#else
#define BF_CCM_CBCMR_PRE_PERIPH_CLK_SEL(v)   (((v) << 18) & BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PRE_PERIPH_CLK_SEL(v)   BF_CS1(CCM_CBCMR, PRE_PERIPH_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field PERIPH2_CLK2_SEL */

#define BP_CCM_CBCMR_PERIPH2_CLK2_SEL      20
#define BM_CCM_CBCMR_PERIPH2_CLK2_SEL      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   ((((reg32_t) v) << 20) & BM_CCM_CBCMR_PERIPH2_CLK2_SEL)
#else
#define BF_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   (((v) << 20) & BM_CCM_CBCMR_PERIPH2_CLK2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   BF_CS1(CCM_CBCMR, PERIPH2_CLK2_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field PRE_PERIPH2_CLK_SEL */

#define BP_CCM_CBCMR_PRE_PERIPH2_CLK_SEL      21
#define BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL      0x00600000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   ((((reg32_t) v) << 21) & BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL)
#else
#define BF_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   (((v) << 21) & BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   BF_CS1(CCM_CBCMR, PRE_PERIPH2_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU2D_CORE_CLK_PODF */

#define BP_CCM_CBCMR_GPU2D_CORE_CLK_PODF      23
#define BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   ((((reg32_t) v) << 23) & BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF)
#else
#define BF_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   (((v) << 23) & BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   BF_CS1(CCM_CBCMR, GPU2D_CORE_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_CORE_PODF */

#define BP_CCM_CBCMR_GPU3D_CORE_PODF      26
#define BM_CCM_CBCMR_GPU3D_CORE_PODF      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_CORE_PODF(v)   ((((reg32_t) v) << 26) & BM_CCM_CBCMR_GPU3D_CORE_PODF)
#else
#define BF_CCM_CBCMR_GPU3D_CORE_PODF(v)   (((v) << 26) & BM_CCM_CBCMR_GPU3D_CORE_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_CORE_PODF(v)   BF_CS1(CCM_CBCMR, GPU3D_CORE_PODF, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_SHADER_PODF */

#define BP_CCM_CBCMR_GPU3D_SHADER_PODF      29
#define BM_CCM_CBCMR_GPU3D_SHADER_PODF      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_SHADER_PODF(v)   ((((reg32_t) v) << 29) & BM_CCM_CBCMR_GPU3D_SHADER_PODF)
#else
#define BF_CCM_CBCMR_GPU3D_SHADER_PODF(v)   (((v) << 29) & BM_CCM_CBCMR_GPU3D_SHADER_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_SHADER_PODF(v)   BF_CS1(CCM_CBCMR, GPU3D_SHADER_PODF, v)
#endif

/*
 * HW_CCM_CSCMR1 - CCM Serial Clock Multiplexer Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PERCLK_PODF : 6;
        unsigned RESERVED0 : 4;
        unsigned SSI1_CLK_SEL : 2;
        unsigned SSI2_CLK_SEL : 2;
        unsigned SSI3_CLK_SEL : 2;
        unsigned USDHC1_CLK_SEL : 1;
        unsigned USDHC2_CLK_SEL : 1;
        unsigned USDHC3_CLK_SEL : 1;
        unsigned USDHC4_CLK_SEL : 1;
        unsigned ACLK_EMI_PODF : 3;
        unsigned ACLK_EMI_SLOW_PODF : 3;
        unsigned RESERVED1 : 1;
        unsigned ACLK_EMI_SEL : 2;
        unsigned ACLK_EMI_SLOW_SEL : 2;
        unsigned RESERVED2 : 1;

    } B;
} hw_ccm_cscmr1_t;
#endif

/*
 * constants & macros for entire CCM_CSCMR1 register
 */
#define HW_CCM_CSCMR1_ADDR      (REGS_CCM_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCMR1           (*(volatile hw_ccm_cscmr1_t *) HW_CCM_CSCMR1_ADDR)
#define HW_CCM_CSCMR1_RD()      (HW_CCM_CSCMR1.U)
#define HW_CCM_CSCMR1_WR(v)     (HW_CCM_CSCMR1.U = (v))
#define HW_CCM_CSCMR1_SET(v)    (HW_CCM_CSCMR1_WR(HW_CCM_CSCMR1_RD() |  (v)))
#define HW_CCM_CSCMR1_CLR(v)    (HW_CCM_CSCMR1_WR(HW_CCM_CSCMR1_RD() & ~(v)))
#define HW_CCM_CSCMR1_TOG(v)    (HW_CCM_CSCMR1_WR(HW_CCM_CSCMR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCMR1 bitfields
 */

/* --- Register HW_CCM_CSCMR1, field PERCLK_PODF */

#define BP_CCM_CSCMR1_PERCLK_PODF      0
#define BM_CCM_CSCMR1_PERCLK_PODF      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_PERCLK_PODF(v)   ((((reg32_t) v) << 0) & BM_CCM_CSCMR1_PERCLK_PODF)
#else
#define BF_CCM_CSCMR1_PERCLK_PODF(v)   (((v) << 0) & BM_CCM_CSCMR1_PERCLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_PERCLK_PODF(v)   BF_CS1(CCM_CSCMR1, PERCLK_PODF, v)
#endif

/* --- Register HW_CCM_CSCMR1, field SSI1_CLK_SEL */

#define BP_CCM_CSCMR1_SSI1_CLK_SEL      10
#define BM_CCM_CSCMR1_SSI1_CLK_SEL      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_SSI1_CLK_SEL(v)   ((((reg32_t) v) << 10) & BM_CCM_CSCMR1_SSI1_CLK_SEL)
#else
#define BF_CCM_CSCMR1_SSI1_CLK_SEL(v)   (((v) << 10) & BM_CCM_CSCMR1_SSI1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_SSI1_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, SSI1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field SSI2_CLK_SEL */

#define BP_CCM_CSCMR1_SSI2_CLK_SEL      12
#define BM_CCM_CSCMR1_SSI2_CLK_SEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_SSI2_CLK_SEL(v)   ((((reg32_t) v) << 12) & BM_CCM_CSCMR1_SSI2_CLK_SEL)
#else
#define BF_CCM_CSCMR1_SSI2_CLK_SEL(v)   (((v) << 12) & BM_CCM_CSCMR1_SSI2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_SSI2_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, SSI2_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field SSI3_CLK_SEL */

#define BP_CCM_CSCMR1_SSI3_CLK_SEL      14
#define BM_CCM_CSCMR1_SSI3_CLK_SEL      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_SSI3_CLK_SEL(v)   ((((reg32_t) v) << 14) & BM_CCM_CSCMR1_SSI3_CLK_SEL)
#else
#define BF_CCM_CSCMR1_SSI3_CLK_SEL(v)   (((v) << 14) & BM_CCM_CSCMR1_SSI3_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_SSI3_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, SSI3_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field USDHC1_CLK_SEL */

#define BP_CCM_CSCMR1_USDHC1_CLK_SEL      16
#define BM_CCM_CSCMR1_USDHC1_CLK_SEL      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_USDHC1_CLK_SEL(v)   ((((reg32_t) v) << 16) & BM_CCM_CSCMR1_USDHC1_CLK_SEL)
#else
#define BF_CCM_CSCMR1_USDHC1_CLK_SEL(v)   (((v) << 16) & BM_CCM_CSCMR1_USDHC1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_USDHC1_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, USDHC1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field USDHC2_CLK_SEL */

#define BP_CCM_CSCMR1_USDHC2_CLK_SEL      17
#define BM_CCM_CSCMR1_USDHC2_CLK_SEL      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_USDHC2_CLK_SEL(v)   ((((reg32_t) v) << 17) & BM_CCM_CSCMR1_USDHC2_CLK_SEL)
#else
#define BF_CCM_CSCMR1_USDHC2_CLK_SEL(v)   (((v) << 17) & BM_CCM_CSCMR1_USDHC2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_USDHC2_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, USDHC2_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field USDHC3_CLK_SEL */

#define BP_CCM_CSCMR1_USDHC3_CLK_SEL      18
#define BM_CCM_CSCMR1_USDHC3_CLK_SEL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_USDHC3_CLK_SEL(v)   ((((reg32_t) v) << 18) & BM_CCM_CSCMR1_USDHC3_CLK_SEL)
#else
#define BF_CCM_CSCMR1_USDHC3_CLK_SEL(v)   (((v) << 18) & BM_CCM_CSCMR1_USDHC3_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_USDHC3_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, USDHC3_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field USDHC4_CLK_SEL */

#define BP_CCM_CSCMR1_USDHC4_CLK_SEL      19
#define BM_CCM_CSCMR1_USDHC4_CLK_SEL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_USDHC4_CLK_SEL(v)   ((((reg32_t) v) << 19) & BM_CCM_CSCMR1_USDHC4_CLK_SEL)
#else
#define BF_CCM_CSCMR1_USDHC4_CLK_SEL(v)   (((v) << 19) & BM_CCM_CSCMR1_USDHC4_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_USDHC4_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, USDHC4_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_PODF */

#define BP_CCM_CSCMR1_ACLK_EMI_PODF      20
#define BM_CCM_CSCMR1_ACLK_EMI_PODF      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_ACLK_EMI_PODF(v)   ((((reg32_t) v) << 20) & BM_CCM_CSCMR1_ACLK_EMI_PODF)
#else
#define BF_CCM_CSCMR1_ACLK_EMI_PODF(v)   (((v) << 20) & BM_CCM_CSCMR1_ACLK_EMI_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_ACLK_EMI_PODF(v)   BF_CS1(CCM_CSCMR1, ACLK_EMI_PODF, v)
#endif

/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SLOW_PODF */

#define BP_CCM_CSCMR1_ACLK_EMI_SLOW_PODF      23
#define BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   ((((reg32_t) v) << 23) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF)
#else
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   (((v) << 23) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   BF_CS1(CCM_CSCMR1, ACLK_EMI_SLOW_PODF, v)
#endif

/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SEL */

#define BP_CCM_CSCMR1_ACLK_EMI_SEL      27
#define BM_CCM_CSCMR1_ACLK_EMI_SEL      0x18000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_ACLK_EMI_SEL(v)   ((((reg32_t) v) << 27) & BM_CCM_CSCMR1_ACLK_EMI_SEL)
#else
#define BF_CCM_CSCMR1_ACLK_EMI_SEL(v)   (((v) << 27) & BM_CCM_CSCMR1_ACLK_EMI_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_ACLK_EMI_SEL(v)   BF_CS1(CCM_CSCMR1, ACLK_EMI_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SLOW_SEL */

#define BP_CCM_CSCMR1_ACLK_EMI_SLOW_SEL      29
#define BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL      0x60000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   ((((reg32_t) v) << 29) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL)
#else
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   (((v) << 29) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   BF_CS1(CCM_CSCMR1, ACLK_EMI_SLOW_SEL, v)
#endif

/*
 * HW_CCM_CSCMR2 - CCM Serial Clock Multiplexer Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2;
        unsigned CAN_CLK_PODF : 6;
        unsigned RESERVED1 : 2;
        unsigned LDB_DI0_IPU_DIV : 1;
        unsigned LDB_DI1_IPU_DIV : 1;
        unsigned RESERVED2 : 7;
        unsigned ESAI_CLK_SEL : 2;
        unsigned RESERVED3 : 11;

    } B;
} hw_ccm_cscmr2_t;
#endif

/*
 * constants & macros for entire CCM_CSCMR2 register
 */
#define HW_CCM_CSCMR2_ADDR      (REGS_CCM_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCMR2           (*(volatile hw_ccm_cscmr2_t *) HW_CCM_CSCMR2_ADDR)
#define HW_CCM_CSCMR2_RD()      (HW_CCM_CSCMR2.U)
#define HW_CCM_CSCMR2_WR(v)     (HW_CCM_CSCMR2.U = (v))
#define HW_CCM_CSCMR2_SET(v)    (HW_CCM_CSCMR2_WR(HW_CCM_CSCMR2_RD() |  (v)))
#define HW_CCM_CSCMR2_CLR(v)    (HW_CCM_CSCMR2_WR(HW_CCM_CSCMR2_RD() & ~(v)))
#define HW_CCM_CSCMR2_TOG(v)    (HW_CCM_CSCMR2_WR(HW_CCM_CSCMR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCMR2 bitfields
 */

/* --- Register HW_CCM_CSCMR2, field CAN_CLK_PODF */

#define BP_CCM_CSCMR2_CAN_CLK_PODF      2
#define BM_CCM_CSCMR2_CAN_CLK_PODF      0x000000fc

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR2_CAN_CLK_PODF(v)   ((((reg32_t) v) << 2) & BM_CCM_CSCMR2_CAN_CLK_PODF)
#else
#define BF_CCM_CSCMR2_CAN_CLK_PODF(v)   (((v) << 2) & BM_CCM_CSCMR2_CAN_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR2_CAN_CLK_PODF(v)   BF_CS1(CCM_CSCMR2, CAN_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CSCMR2, field LDB_DI0_IPU_DIV */

#define BP_CCM_CSCMR2_LDB_DI0_IPU_DIV      10
#define BM_CCM_CSCMR2_LDB_DI0_IPU_DIV      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   ((((reg32_t) v) << 10) & BM_CCM_CSCMR2_LDB_DI0_IPU_DIV)
#else
#define BF_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   (((v) << 10) & BM_CCM_CSCMR2_LDB_DI0_IPU_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   BF_CS1(CCM_CSCMR2, LDB_DI0_IPU_DIV, v)
#endif

/* --- Register HW_CCM_CSCMR2, field LDB_DI1_IPU_DIV */

#define BP_CCM_CSCMR2_LDB_DI1_IPU_DIV      11
#define BM_CCM_CSCMR2_LDB_DI1_IPU_DIV      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   ((((reg32_t) v) << 11) & BM_CCM_CSCMR2_LDB_DI1_IPU_DIV)
#else
#define BF_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   (((v) << 11) & BM_CCM_CSCMR2_LDB_DI1_IPU_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   BF_CS1(CCM_CSCMR2, LDB_DI1_IPU_DIV, v)
#endif

/* --- Register HW_CCM_CSCMR2, field ESAI_CLK_SEL */

#define BP_CCM_CSCMR2_ESAI_CLK_SEL      19
#define BM_CCM_CSCMR2_ESAI_CLK_SEL      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR2_ESAI_CLK_SEL(v)   ((((reg32_t) v) << 19) & BM_CCM_CSCMR2_ESAI_CLK_SEL)
#else
#define BF_CCM_CSCMR2_ESAI_CLK_SEL(v)   (((v) << 19) & BM_CCM_CSCMR2_ESAI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR2_ESAI_CLK_SEL(v)   BF_CS1(CCM_CSCMR2, ESAI_CLK_SEL, v)
#endif

/*
 * HW_CCM_CSCDR1 - CCM Serial Clock Divider Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned UART_CLK_PODF : 6;
        unsigned USBOH3_CLK_PODF : 2;
        unsigned RESERVED0 : 5;
        unsigned USBOH3_CLK_PRED : 3;
        unsigned USDHC1_PODF : 3;
        unsigned RESERVED1 : 2;
        unsigned USDHC2_PODF : 3;
        unsigned USDHC3_PODF : 3;
        unsigned USDHC4_PODF : 3;
        unsigned VPU_AXI_PODF : 3;
        unsigned RESERVED2 : 4;

    } B;
} hw_ccm_cscdr1_t;
#endif

/*
 * constants & macros for entire CCM_CSCDR1 register
 */
#define HW_CCM_CSCDR1_ADDR      (REGS_CCM_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCDR1           (*(volatile hw_ccm_cscdr1_t *) HW_CCM_CSCDR1_ADDR)
#define HW_CCM_CSCDR1_RD()      (HW_CCM_CSCDR1.U)
#define HW_CCM_CSCDR1_WR(v)     (HW_CCM_CSCDR1.U = (v))
#define HW_CCM_CSCDR1_SET(v)    (HW_CCM_CSCDR1_WR(HW_CCM_CSCDR1_RD() |  (v)))
#define HW_CCM_CSCDR1_CLR(v)    (HW_CCM_CSCDR1_WR(HW_CCM_CSCDR1_RD() & ~(v)))
#define HW_CCM_CSCDR1_TOG(v)    (HW_CCM_CSCDR1_WR(HW_CCM_CSCDR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCDR1 bitfields
 */

/* --- Register HW_CCM_CSCDR1, field UART_CLK_PODF */

#define BP_CCM_CSCDR1_UART_CLK_PODF      0
#define BM_CCM_CSCDR1_UART_CLK_PODF      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_UART_CLK_PODF(v)   ((((reg32_t) v) << 0) & BM_CCM_CSCDR1_UART_CLK_PODF)
#else
#define BF_CCM_CSCDR1_UART_CLK_PODF(v)   (((v) << 0) & BM_CCM_CSCDR1_UART_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_UART_CLK_PODF(v)   BF_CS1(CCM_CSCDR1, UART_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USBOH3_CLK_PODF */

#define BP_CCM_CSCDR1_USBOH3_CLK_PODF      6
#define BM_CCM_CSCDR1_USBOH3_CLK_PODF      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USBOH3_CLK_PODF(v)   ((((reg32_t) v) << 6) & BM_CCM_CSCDR1_USBOH3_CLK_PODF)
#else
#define BF_CCM_CSCDR1_USBOH3_CLK_PODF(v)   (((v) << 6) & BM_CCM_CSCDR1_USBOH3_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USBOH3_CLK_PODF(v)   BF_CS1(CCM_CSCDR1, USBOH3_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USBOH3_CLK_PRED */

#define BP_CCM_CSCDR1_USBOH3_CLK_PRED      8
#define BM_CCM_CSCDR1_USBOH3_CLK_PRED      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USBOH3_CLK_PRED(v)   ((((reg32_t) v) << 8) & BM_CCM_CSCDR1_USBOH3_CLK_PRED)
#else
#define BF_CCM_CSCDR1_USBOH3_CLK_PRED(v)   (((v) << 8) & BM_CCM_CSCDR1_USBOH3_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USBOH3_CLK_PRED(v)   BF_CS1(CCM_CSCDR1, USBOH3_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USDHC1_PODF */

#define BP_CCM_CSCDR1_USDHC1_PODF      11
#define BM_CCM_CSCDR1_USDHC1_PODF      0x00003800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USDHC1_PODF(v)   ((((reg32_t) v) << 11) & BM_CCM_CSCDR1_USDHC1_PODF)
#else
#define BF_CCM_CSCDR1_USDHC1_PODF(v)   (((v) << 11) & BM_CCM_CSCDR1_USDHC1_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USDHC1_PODF(v)   BF_CS1(CCM_CSCDR1, USDHC1_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USDHC2_PODF */

#define BP_CCM_CSCDR1_USDHC2_PODF      16
#define BM_CCM_CSCDR1_USDHC2_PODF      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USDHC2_PODF(v)   ((((reg32_t) v) << 16) & BM_CCM_CSCDR1_USDHC2_PODF)
#else
#define BF_CCM_CSCDR1_USDHC2_PODF(v)   (((v) << 16) & BM_CCM_CSCDR1_USDHC2_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USDHC2_PODF(v)   BF_CS1(CCM_CSCDR1, USDHC2_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USDHC3_PODF */

#define BP_CCM_CSCDR1_USDHC3_PODF      19
#define BM_CCM_CSCDR1_USDHC3_PODF      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USDHC3_PODF(v)   ((((reg32_t) v) << 19) & BM_CCM_CSCDR1_USDHC3_PODF)
#else
#define BF_CCM_CSCDR1_USDHC3_PODF(v)   (((v) << 19) & BM_CCM_CSCDR1_USDHC3_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USDHC3_PODF(v)   BF_CS1(CCM_CSCDR1, USDHC3_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USDHC4_PODF */

#define BP_CCM_CSCDR1_USDHC4_PODF      22
#define BM_CCM_CSCDR1_USDHC4_PODF      0x01c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USDHC4_PODF(v)   ((((reg32_t) v) << 22) & BM_CCM_CSCDR1_USDHC4_PODF)
#else
#define BF_CCM_CSCDR1_USDHC4_PODF(v)   (((v) << 22) & BM_CCM_CSCDR1_USDHC4_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USDHC4_PODF(v)   BF_CS1(CCM_CSCDR1, USDHC4_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR1, field VPU_AXI_PODF */

#define BP_CCM_CSCDR1_VPU_AXI_PODF      25
#define BM_CCM_CSCDR1_VPU_AXI_PODF      0x0e000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_VPU_AXI_PODF(v)   ((((reg32_t) v) << 25) & BM_CCM_CSCDR1_VPU_AXI_PODF)
#else
#define BF_CCM_CSCDR1_VPU_AXI_PODF(v)   (((v) << 25) & BM_CCM_CSCDR1_VPU_AXI_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_VPU_AXI_PODF(v)   BF_CS1(CCM_CSCDR1, VPU_AXI_PODF, v)
#endif

/*
 * HW_CCM_CS1CDR - CCM SSI1 Clock Divider Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SSI1_CLK_PODF : 6;
        unsigned SSI1_CLK_PRED : 3;
        unsigned ESAI_CLK_PRED : 3;
        unsigned RESERVED0 : 4;
        unsigned SSI3_CLK_PODF : 6;
        unsigned SSI3_CLK_PRED : 3;
        unsigned ESAI_CLK_PODF : 3;
        unsigned RESERVED1 : 4;

    } B;
} hw_ccm_cs1cdr_t;
#endif

/*
 * constants & macros for entire CCM_CS1CDR register
 */
#define HW_CCM_CS1CDR_ADDR      (REGS_CCM_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CS1CDR           (*(volatile hw_ccm_cs1cdr_t *) HW_CCM_CS1CDR_ADDR)
#define HW_CCM_CS1CDR_RD()      (HW_CCM_CS1CDR.U)
#define HW_CCM_CS1CDR_WR(v)     (HW_CCM_CS1CDR.U = (v))
#define HW_CCM_CS1CDR_SET(v)    (HW_CCM_CS1CDR_WR(HW_CCM_CS1CDR_RD() |  (v)))
#define HW_CCM_CS1CDR_CLR(v)    (HW_CCM_CS1CDR_WR(HW_CCM_CS1CDR_RD() & ~(v)))
#define HW_CCM_CS1CDR_TOG(v)    (HW_CCM_CS1CDR_WR(HW_CCM_CS1CDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CS1CDR bitfields
 */

/* --- Register HW_CCM_CS1CDR, field SSI1_CLK_PODF */

#define BP_CCM_CS1CDR_SSI1_CLK_PODF      0
#define BM_CCM_CS1CDR_SSI1_CLK_PODF      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_SSI1_CLK_PODF(v)   ((((reg32_t) v) << 0) & BM_CCM_CS1CDR_SSI1_CLK_PODF)
#else
#define BF_CCM_CS1CDR_SSI1_CLK_PODF(v)   (((v) << 0) & BM_CCM_CS1CDR_SSI1_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_SSI1_CLK_PODF(v)   BF_CS1(CCM_CS1CDR, SSI1_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CS1CDR, field SSI1_CLK_PRED */

#define BP_CCM_CS1CDR_SSI1_CLK_PRED      6
#define BM_CCM_CS1CDR_SSI1_CLK_PRED      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_SSI1_CLK_PRED(v)   ((((reg32_t) v) << 6) & BM_CCM_CS1CDR_SSI1_CLK_PRED)
#else
#define BF_CCM_CS1CDR_SSI1_CLK_PRED(v)   (((v) << 6) & BM_CCM_CS1CDR_SSI1_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_SSI1_CLK_PRED(v)   BF_CS1(CCM_CS1CDR, SSI1_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS1CDR, field ESAI_CLK_PRED */

#define BP_CCM_CS1CDR_ESAI_CLK_PRED      9
#define BM_CCM_CS1CDR_ESAI_CLK_PRED      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_ESAI_CLK_PRED(v)   ((((reg32_t) v) << 9) & BM_CCM_CS1CDR_ESAI_CLK_PRED)
#else
#define BF_CCM_CS1CDR_ESAI_CLK_PRED(v)   (((v) << 9) & BM_CCM_CS1CDR_ESAI_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_ESAI_CLK_PRED(v)   BF_CS1(CCM_CS1CDR, ESAI_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS1CDR, field SSI3_CLK_PODF */

#define BP_CCM_CS1CDR_SSI3_CLK_PODF      16
#define BM_CCM_CS1CDR_SSI3_CLK_PODF      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_SSI3_CLK_PODF(v)   ((((reg32_t) v) << 16) & BM_CCM_CS1CDR_SSI3_CLK_PODF)
#else
#define BF_CCM_CS1CDR_SSI3_CLK_PODF(v)   (((v) << 16) & BM_CCM_CS1CDR_SSI3_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_SSI3_CLK_PODF(v)   BF_CS1(CCM_CS1CDR, SSI3_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CS1CDR, field SSI3_CLK_PRED */

#define BP_CCM_CS1CDR_SSI3_CLK_PRED      22
#define BM_CCM_CS1CDR_SSI3_CLK_PRED      0x01c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_SSI3_CLK_PRED(v)   ((((reg32_t) v) << 22) & BM_CCM_CS1CDR_SSI3_CLK_PRED)
#else
#define BF_CCM_CS1CDR_SSI3_CLK_PRED(v)   (((v) << 22) & BM_CCM_CS1CDR_SSI3_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_SSI3_CLK_PRED(v)   BF_CS1(CCM_CS1CDR, SSI3_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS1CDR, field ESAI_CLK_PODF */

#define BP_CCM_CS1CDR_ESAI_CLK_PODF      25
#define BM_CCM_CS1CDR_ESAI_CLK_PODF      0x0e000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_ESAI_CLK_PODF(v)   ((((reg32_t) v) << 25) & BM_CCM_CS1CDR_ESAI_CLK_PODF)
#else
#define BF_CCM_CS1CDR_ESAI_CLK_PODF(v)   (((v) << 25) & BM_CCM_CS1CDR_ESAI_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_ESAI_CLK_PODF(v)   BF_CS1(CCM_CS1CDR, ESAI_CLK_PODF, v)
#endif

/*
 * HW_CCM_CS2CDR - CCM SSI2 Clock Divider Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SSI2_CLK_PODF : 6;
        unsigned SSI2_CLK_PRED : 3;
        unsigned LDB_DI0_CLK_SEL : 3;
        unsigned LDB_DI1_CLK_SEL : 3;
        unsigned RESERVED0 : 1;
        unsigned ENFC_CLK_SEL : 2;
        unsigned ENFC_CLK_PRED : 3;
        unsigned ENFC_CLK_PODF : 6;
        unsigned RESERVED1 : 5;

    } B;
} hw_ccm_cs2cdr_t;
#endif

/*
 * constants & macros for entire CCM_CS2CDR register
 */
#define HW_CCM_CS2CDR_ADDR      (REGS_CCM_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CS2CDR           (*(volatile hw_ccm_cs2cdr_t *) HW_CCM_CS2CDR_ADDR)
#define HW_CCM_CS2CDR_RD()      (HW_CCM_CS2CDR.U)
#define HW_CCM_CS2CDR_WR(v)     (HW_CCM_CS2CDR.U = (v))
#define HW_CCM_CS2CDR_SET(v)    (HW_CCM_CS2CDR_WR(HW_CCM_CS2CDR_RD() |  (v)))
#define HW_CCM_CS2CDR_CLR(v)    (HW_CCM_CS2CDR_WR(HW_CCM_CS2CDR_RD() & ~(v)))
#define HW_CCM_CS2CDR_TOG(v)    (HW_CCM_CS2CDR_WR(HW_CCM_CS2CDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CS2CDR bitfields
 */

/* --- Register HW_CCM_CS2CDR, field SSI2_CLK_PODF */

#define BP_CCM_CS2CDR_SSI2_CLK_PODF      0
#define BM_CCM_CS2CDR_SSI2_CLK_PODF      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_SSI2_CLK_PODF(v)   ((((reg32_t) v) << 0) & BM_CCM_CS2CDR_SSI2_CLK_PODF)
#else
#define BF_CCM_CS2CDR_SSI2_CLK_PODF(v)   (((v) << 0) & BM_CCM_CS2CDR_SSI2_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_SSI2_CLK_PODF(v)   BF_CS1(CCM_CS2CDR, SSI2_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CS2CDR, field SSI2_CLK_PRED */

#define BP_CCM_CS2CDR_SSI2_CLK_PRED      6
#define BM_CCM_CS2CDR_SSI2_CLK_PRED      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_SSI2_CLK_PRED(v)   ((((reg32_t) v) << 6) & BM_CCM_CS2CDR_SSI2_CLK_PRED)
#else
#define BF_CCM_CS2CDR_SSI2_CLK_PRED(v)   (((v) << 6) & BM_CCM_CS2CDR_SSI2_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_SSI2_CLK_PRED(v)   BF_CS1(CCM_CS2CDR, SSI2_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS2CDR, field LDB_DI0_CLK_SEL */

#define BP_CCM_CS2CDR_LDB_DI0_CLK_SEL      9
#define BM_CCM_CS2CDR_LDB_DI0_CLK_SEL      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_LDB_DI0_CLK_SEL(v)   ((((reg32_t) v) << 9) & BM_CCM_CS2CDR_LDB_DI0_CLK_SEL)
#else
#define BF_CCM_CS2CDR_LDB_DI0_CLK_SEL(v)   (((v) << 9) & BM_CCM_CS2CDR_LDB_DI0_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_LDB_DI0_CLK_SEL(v)   BF_CS1(CCM_CS2CDR, LDB_DI0_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CS2CDR, field LDB_DI1_CLK_SEL */

#define BP_CCM_CS2CDR_LDB_DI1_CLK_SEL      12
#define BM_CCM_CS2CDR_LDB_DI1_CLK_SEL      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_LDB_DI1_CLK_SEL(v)   ((((reg32_t) v) << 12) & BM_CCM_CS2CDR_LDB_DI1_CLK_SEL)
#else
#define BF_CCM_CS2CDR_LDB_DI1_CLK_SEL(v)   (((v) << 12) & BM_CCM_CS2CDR_LDB_DI1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_LDB_DI1_CLK_SEL(v)   BF_CS1(CCM_CS2CDR, LDB_DI1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_SEL */

#define BP_CCM_CS2CDR_ENFC_CLK_SEL      16
#define BM_CCM_CS2CDR_ENFC_CLK_SEL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_ENFC_CLK_SEL(v)   ((((reg32_t) v) << 16) & BM_CCM_CS2CDR_ENFC_CLK_SEL)
#else
#define BF_CCM_CS2CDR_ENFC_CLK_SEL(v)   (((v) << 16) & BM_CCM_CS2CDR_ENFC_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_ENFC_CLK_SEL(v)   BF_CS1(CCM_CS2CDR, ENFC_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_PRED */

#define BP_CCM_CS2CDR_ENFC_CLK_PRED      18
#define BM_CCM_CS2CDR_ENFC_CLK_PRED      0x001c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_ENFC_CLK_PRED(v)   ((((reg32_t) v) << 18) & BM_CCM_CS2CDR_ENFC_CLK_PRED)
#else
#define BF_CCM_CS2CDR_ENFC_CLK_PRED(v)   (((v) << 18) & BM_CCM_CS2CDR_ENFC_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_ENFC_CLK_PRED(v)   BF_CS1(CCM_CS2CDR, ENFC_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_PODF */

#define BP_CCM_CS2CDR_ENFC_CLK_PODF      21
#define BM_CCM_CS2CDR_ENFC_CLK_PODF      0x07e00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_ENFC_CLK_PODF(v)   ((((reg32_t) v) << 21) & BM_CCM_CS2CDR_ENFC_CLK_PODF)
#else
#define BF_CCM_CS2CDR_ENFC_CLK_PODF(v)   (((v) << 21) & BM_CCM_CS2CDR_ENFC_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_ENFC_CLK_PODF(v)   BF_CS1(CCM_CS2CDR, ENFC_CLK_PODF, v)
#endif

/*
 * HW_CCM_CDCDR - CCM D1 Clock Divider Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7;
        unsigned SPDIF1_CLK_SEL : 2;
        unsigned SPDIF1_CLK_PODF : 3;
        unsigned SPDIF1_CLK_PRED : 3;
        unsigned RESERVED1 : 1;
        unsigned RESERVED2 : 4;
        unsigned SPDIF0_CLK_SEL : 2;
        unsigned SPDIF0_CLK_PODF : 3;
        unsigned SPDIF0_CLK_PRED : 3;
        unsigned HSI_TX_CLK_SEL : 1;
        unsigned HSI_TX_PODF : 3;

    } B;
} hw_ccm_cdcdr_t;
#endif

/*
 * constants & macros for entire CCM_CDCDR register
 */
#define HW_CCM_CDCDR_ADDR      (REGS_CCM_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CDCDR           (*(volatile hw_ccm_cdcdr_t *) HW_CCM_CDCDR_ADDR)
#define HW_CCM_CDCDR_RD()      (HW_CCM_CDCDR.U)
#define HW_CCM_CDCDR_WR(v)     (HW_CCM_CDCDR.U = (v))
#define HW_CCM_CDCDR_SET(v)    (HW_CCM_CDCDR_WR(HW_CCM_CDCDR_RD() |  (v)))
#define HW_CCM_CDCDR_CLR(v)    (HW_CCM_CDCDR_WR(HW_CCM_CDCDR_RD() & ~(v)))
#define HW_CCM_CDCDR_TOG(v)    (HW_CCM_CDCDR_WR(HW_CCM_CDCDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CDCDR bitfields
 */

/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_SEL */

#define BP_CCM_CDCDR_SPDIF1_CLK_SEL      7
#define BM_CCM_CDCDR_SPDIF1_CLK_SEL      0x00000180

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF1_CLK_SEL(v)   ((((reg32_t) v) << 7) & BM_CCM_CDCDR_SPDIF1_CLK_SEL)
#else
#define BF_CCM_CDCDR_SPDIF1_CLK_SEL(v)   (((v) << 7) & BM_CCM_CDCDR_SPDIF1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF1_CLK_SEL(v)   BF_CS1(CCM_CDCDR, SPDIF1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_PODF */

#define BP_CCM_CDCDR_SPDIF1_CLK_PODF      9
#define BM_CCM_CDCDR_SPDIF1_CLK_PODF      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF1_CLK_PODF(v)   ((((reg32_t) v) << 9) & BM_CCM_CDCDR_SPDIF1_CLK_PODF)
#else
#define BF_CCM_CDCDR_SPDIF1_CLK_PODF(v)   (((v) << 9) & BM_CCM_CDCDR_SPDIF1_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF1_CLK_PODF(v)   BF_CS1(CCM_CDCDR, SPDIF1_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_PRED */

#define BP_CCM_CDCDR_SPDIF1_CLK_PRED      12
#define BM_CCM_CDCDR_SPDIF1_CLK_PRED      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF1_CLK_PRED(v)   ((((reg32_t) v) << 12) & BM_CCM_CDCDR_SPDIF1_CLK_PRED)
#else
#define BF_CCM_CDCDR_SPDIF1_CLK_PRED(v)   (((v) << 12) & BM_CCM_CDCDR_SPDIF1_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF1_CLK_PRED(v)   BF_CS1(CCM_CDCDR, SPDIF1_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_SEL */

#define BP_CCM_CDCDR_SPDIF0_CLK_SEL      20
#define BM_CCM_CDCDR_SPDIF0_CLK_SEL      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF0_CLK_SEL(v)   ((((reg32_t) v) << 20) & BM_CCM_CDCDR_SPDIF0_CLK_SEL)
#else
#define BF_CCM_CDCDR_SPDIF0_CLK_SEL(v)   (((v) << 20) & BM_CCM_CDCDR_SPDIF0_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF0_CLK_SEL(v)   BF_CS1(CCM_CDCDR, SPDIF0_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_PODF */

#define BP_CCM_CDCDR_SPDIF0_CLK_PODF      22
#define BM_CCM_CDCDR_SPDIF0_CLK_PODF      0x01c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF0_CLK_PODF(v)   ((((reg32_t) v) << 22) & BM_CCM_CDCDR_SPDIF0_CLK_PODF)
#else
#define BF_CCM_CDCDR_SPDIF0_CLK_PODF(v)   (((v) << 22) & BM_CCM_CDCDR_SPDIF0_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF0_CLK_PODF(v)   BF_CS1(CCM_CDCDR, SPDIF0_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_PRED */

#define BP_CCM_CDCDR_SPDIF0_CLK_PRED      25
#define BM_CCM_CDCDR_SPDIF0_CLK_PRED      0x0e000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF0_CLK_PRED(v)   ((((reg32_t) v) << 25) & BM_CCM_CDCDR_SPDIF0_CLK_PRED)
#else
#define BF_CCM_CDCDR_SPDIF0_CLK_PRED(v)   (((v) << 25) & BM_CCM_CDCDR_SPDIF0_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF0_CLK_PRED(v)   BF_CS1(CCM_CDCDR, SPDIF0_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CDCDR, field HSI_TX_CLK_SEL */

#define BP_CCM_CDCDR_HSI_TX_CLK_SEL      28
#define BM_CCM_CDCDR_HSI_TX_CLK_SEL      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_HSI_TX_CLK_SEL(v)   ((((reg32_t) v) << 28) & BM_CCM_CDCDR_HSI_TX_CLK_SEL)
#else
#define BF_CCM_CDCDR_HSI_TX_CLK_SEL(v)   (((v) << 28) & BM_CCM_CDCDR_HSI_TX_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_HSI_TX_CLK_SEL(v)   BF_CS1(CCM_CDCDR, HSI_TX_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CDCDR, field HSI_TX_PODF */

#define BP_CCM_CDCDR_HSI_TX_PODF      29
#define BM_CCM_CDCDR_HSI_TX_PODF      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_HSI_TX_PODF(v)   ((((reg32_t) v) << 29) & BM_CCM_CDCDR_HSI_TX_PODF)
#else
#define BF_CCM_CDCDR_HSI_TX_PODF(v)   (((v) << 29) & BM_CCM_CDCDR_HSI_TX_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_HSI_TX_PODF(v)   BF_CS1(CCM_CDCDR, HSI_TX_PODF, v)
#endif

/*
 * HW_CCM_CHSCCDR - CCM HSC Clock Divider Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPU1_DI0_CLK_SEL : 3;
        unsigned IPU1_DI0_PODF : 3;
        unsigned IPU1_DI0_PRE_CLK_SEL : 3;
        unsigned IPU1_DI1_CLK_SEL : 3;
        unsigned IPU1_DI1_PODF : 3;
        unsigned IPU1_DI1_PRE_CLK_SEL : 3;
        unsigned RESERVED0 : 14;

    } B;
} hw_ccm_chsccdr_t;
#endif

/*
 * constants & macros for entire CCM_CHSCCDR register
 */
#define HW_CCM_CHSCCDR_ADDR      (REGS_CCM_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CHSCCDR           (*(volatile hw_ccm_chsccdr_t *) HW_CCM_CHSCCDR_ADDR)
#define HW_CCM_CHSCCDR_RD()      (HW_CCM_CHSCCDR.U)
#define HW_CCM_CHSCCDR_WR(v)     (HW_CCM_CHSCCDR.U = (v))
#define HW_CCM_CHSCCDR_SET(v)    (HW_CCM_CHSCCDR_WR(HW_CCM_CHSCCDR_RD() |  (v)))
#define HW_CCM_CHSCCDR_CLR(v)    (HW_CCM_CHSCCDR_WR(HW_CCM_CHSCCDR_RD() & ~(v)))
#define HW_CCM_CHSCCDR_TOG(v)    (HW_CCM_CHSCCDR_WR(HW_CCM_CHSCCDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CHSCCDR bitfields
 */

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_CLK_SEL */

#define BP_CCM_CHSCCDR_IPU1_DI0_CLK_SEL      0
#define BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL)
#else
#define BF_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   (((v) << 0) & BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI0_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_PODF */

#define BP_CCM_CHSCCDR_IPU1_DI0_PODF      3
#define BM_CCM_CHSCCDR_IPU1_DI0_PODF      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI0_PODF(v)   ((((reg32_t) v) << 3) & BM_CCM_CHSCCDR_IPU1_DI0_PODF)
#else
#define BF_CCM_CHSCCDR_IPU1_DI0_PODF(v)   (((v) << 3) & BM_CCM_CHSCCDR_IPU1_DI0_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI0_PODF(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI0_PODF, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_PRE_CLK_SEL */

#define BP_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL      6
#define BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   ((((reg32_t) v) << 6) & BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL)
#else
#define BF_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   (((v) << 6) & BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI0_PRE_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_CLK_SEL */

#define BP_CCM_CHSCCDR_IPU1_DI1_CLK_SEL      9
#define BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   ((((reg32_t) v) << 9) & BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL)
#else
#define BF_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   (((v) << 9) & BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_PODF */

#define BP_CCM_CHSCCDR_IPU1_DI1_PODF      12
#define BM_CCM_CHSCCDR_IPU1_DI1_PODF      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI1_PODF(v)   ((((reg32_t) v) << 12) & BM_CCM_CHSCCDR_IPU1_DI1_PODF)
#else
#define BF_CCM_CHSCCDR_IPU1_DI1_PODF(v)   (((v) << 12) & BM_CCM_CHSCCDR_IPU1_DI1_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI1_PODF(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI1_PODF, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_PRE_CLK_SEL */

#define BP_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL      15
#define BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   ((((reg32_t) v) << 15) & BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL)
#else
#define BF_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   (((v) << 15) & BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI1_PRE_CLK_SEL, v)
#endif

/*
 * HW_CCM_CSCDR2 - CCM Serial Clock Divider Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPU2_DI0_CLK_SEL : 3;
        unsigned IPU2_DI0_PODF : 3;
        unsigned IPU2_DI0_PRE_CLK_SEL : 3;
        unsigned IPU2_DI1_CLK_SEL : 3;
        unsigned IPU2_DI1_PODF : 3;
        unsigned IPU2_DI1_PRE_CLK_SEL : 3;
        unsigned RESERVED0 : 1;
        unsigned ECSPI_CLK_PODF : 6;
        unsigned RESERVED1 : 6;
        unsigned RESERVED2 : 1;

    } B;
} hw_ccm_cscdr2_t;
#endif

/*
 * constants & macros for entire CCM_CSCDR2 register
 */
#define HW_CCM_CSCDR2_ADDR      (REGS_CCM_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCDR2           (*(volatile hw_ccm_cscdr2_t *) HW_CCM_CSCDR2_ADDR)
#define HW_CCM_CSCDR2_RD()      (HW_CCM_CSCDR2.U)
#define HW_CCM_CSCDR2_WR(v)     (HW_CCM_CSCDR2.U = (v))
#define HW_CCM_CSCDR2_SET(v)    (HW_CCM_CSCDR2_WR(HW_CCM_CSCDR2_RD() |  (v)))
#define HW_CCM_CSCDR2_CLR(v)    (HW_CCM_CSCDR2_WR(HW_CCM_CSCDR2_RD() & ~(v)))
#define HW_CCM_CSCDR2_TOG(v)    (HW_CCM_CSCDR2_WR(HW_CCM_CSCDR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCDR2 bitfields
 */

/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_CLK_SEL */

#define BP_CCM_CSCDR2_IPU2_DI0_CLK_SEL      0
#define BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL)
#else
#define BF_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   (((v) << 0) & BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   BF_CS1(CCM_CSCDR2, IPU2_DI0_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_PODF */

#define BP_CCM_CSCDR2_IPU2_DI0_PODF      3
#define BM_CCM_CSCDR2_IPU2_DI0_PODF      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI0_PODF(v)   ((((reg32_t) v) << 3) & BM_CCM_CSCDR2_IPU2_DI0_PODF)
#else
#define BF_CCM_CSCDR2_IPU2_DI0_PODF(v)   (((v) << 3) & BM_CCM_CSCDR2_IPU2_DI0_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI0_PODF(v)   BF_CS1(CCM_CSCDR2, IPU2_DI0_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_PRE_CLK_SEL */

#define BP_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL      6
#define BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   ((((reg32_t) v) << 6) & BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL)
#else
#define BF_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   (((v) << 6) & BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   BF_CS1(CCM_CSCDR2, IPU2_DI0_PRE_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_CLK_SEL */

#define BP_CCM_CSCDR2_IPU2_DI1_CLK_SEL      9
#define BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   ((((reg32_t) v) << 9) & BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL)
#else
#define BF_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   (((v) << 9) & BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   BF_CS1(CCM_CSCDR2, IPU2_DI1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_PODF */

#define BP_CCM_CSCDR2_IPU2_DI1_PODF      12
#define BM_CCM_CSCDR2_IPU2_DI1_PODF      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI1_PODF(v)   ((((reg32_t) v) << 12) & BM_CCM_CSCDR2_IPU2_DI1_PODF)
#else
#define BF_CCM_CSCDR2_IPU2_DI1_PODF(v)   (((v) << 12) & BM_CCM_CSCDR2_IPU2_DI1_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI1_PODF(v)   BF_CS1(CCM_CSCDR2, IPU2_DI1_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_PRE_CLK_SEL */

#define BP_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL      15
#define BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   ((((reg32_t) v) << 15) & BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL)
#else
#define BF_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   (((v) << 15) & BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   BF_CS1(CCM_CSCDR2, IPU2_DI1_PRE_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR2, field ECSPI_CLK_PODF */

#define BP_CCM_CSCDR2_ECSPI_CLK_PODF      19
#define BM_CCM_CSCDR2_ECSPI_CLK_PODF      0x01f80000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_ECSPI_CLK_PODF(v)   ((((reg32_t) v) << 19) & BM_CCM_CSCDR2_ECSPI_CLK_PODF)
#else
#define BF_CCM_CSCDR2_ECSPI_CLK_PODF(v)   (((v) << 19) & BM_CCM_CSCDR2_ECSPI_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_ECSPI_CLK_PODF(v)   BF_CS1(CCM_CSCDR2, ECSPI_CLK_PODF, v)
#endif

/*
 * HW_CCM_CSCDR3 - CCM Serial Clock Divider Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 9;
        unsigned IPU1_HSP_CLK_SEL : 2;
        unsigned IPU1_HSP_PODF : 3;
        unsigned IPU2_HSP_CLK_SEL : 2;
        unsigned IPU2_HSP_PODF : 3;
        unsigned RESERVED1 : 13;

    } B;
} hw_ccm_cscdr3_t;
#endif

/*
 * constants & macros for entire CCM_CSCDR3 register
 */
#define HW_CCM_CSCDR3_ADDR      (REGS_CCM_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCDR3           (*(volatile hw_ccm_cscdr3_t *) HW_CCM_CSCDR3_ADDR)
#define HW_CCM_CSCDR3_RD()      (HW_CCM_CSCDR3.U)
#define HW_CCM_CSCDR3_WR(v)     (HW_CCM_CSCDR3.U = (v))
#define HW_CCM_CSCDR3_SET(v)    (HW_CCM_CSCDR3_WR(HW_CCM_CSCDR3_RD() |  (v)))
#define HW_CCM_CSCDR3_CLR(v)    (HW_CCM_CSCDR3_WR(HW_CCM_CSCDR3_RD() & ~(v)))
#define HW_CCM_CSCDR3_TOG(v)    (HW_CCM_CSCDR3_WR(HW_CCM_CSCDR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCDR3 bitfields
 */

/* --- Register HW_CCM_CSCDR3, field IPU1_HSP_CLK_SEL */

#define BP_CCM_CSCDR3_IPU1_HSP_CLK_SEL      9
#define BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR3_IPU1_HSP_CLK_SEL(v)   ((((reg32_t) v) << 9) & BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL)
#else
#define BF_CCM_CSCDR3_IPU1_HSP_CLK_SEL(v)   (((v) << 9) & BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR3_IPU1_HSP_CLK_SEL(v)   BF_CS1(CCM_CSCDR3, IPU1_HSP_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR3, field IPU1_HSP_PODF */

#define BP_CCM_CSCDR3_IPU1_HSP_PODF      11
#define BM_CCM_CSCDR3_IPU1_HSP_PODF      0x00003800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR3_IPU1_HSP_PODF(v)   ((((reg32_t) v) << 11) & BM_CCM_CSCDR3_IPU1_HSP_PODF)
#else
#define BF_CCM_CSCDR3_IPU1_HSP_PODF(v)   (((v) << 11) & BM_CCM_CSCDR3_IPU1_HSP_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR3_IPU1_HSP_PODF(v)   BF_CS1(CCM_CSCDR3, IPU1_HSP_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR3, field IPU2_HSP_CLK_SEL */

#define BP_CCM_CSCDR3_IPU2_HSP_CLK_SEL      14
#define BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR3_IPU2_HSP_CLK_SEL(v)   ((((reg32_t) v) << 14) & BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL)
#else
#define BF_CCM_CSCDR3_IPU2_HSP_CLK_SEL(v)   (((v) << 14) & BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR3_IPU2_HSP_CLK_SEL(v)   BF_CS1(CCM_CSCDR3, IPU2_HSP_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR3, field IPU2_HSP_PODF */

#define BP_CCM_CSCDR3_IPU2_HSP_PODF      16
#define BM_CCM_CSCDR3_IPU2_HSP_PODF      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR3_IPU2_HSP_PODF(v)   ((((reg32_t) v) << 16) & BM_CCM_CSCDR3_IPU2_HSP_PODF)
#else
#define BF_CCM_CSCDR3_IPU2_HSP_PODF(v)   (((v) << 16) & BM_CCM_CSCDR3_IPU2_HSP_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR3_IPU2_HSP_PODF(v)   BF_CS1(CCM_CSCDR3, IPU2_HSP_PODF, v)
#endif

/*
 * HW_CCM_CSCDR4 - CCM Serial Clock Divider Register 4
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 6;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 6;
        unsigned RESERVED3 : 1;
        unsigned RESERVED4 : 3;
        unsigned RESERVED5 : 13;

    } B;
} hw_ccm_cscdr4_t;
#endif

/*
 * constants & macros for entire CCM_CSCDR4 register
 */
#define HW_CCM_CSCDR4_ADDR      (REGS_CCM_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCDR4           (*(volatile hw_ccm_cscdr4_t *) HW_CCM_CSCDR4_ADDR)
#define HW_CCM_CSCDR4_RD()      (HW_CCM_CSCDR4.U)
#define HW_CCM_CSCDR4_WR(v)     (HW_CCM_CSCDR4.U = (v))
#define HW_CCM_CSCDR4_SET(v)    (HW_CCM_CSCDR4_WR(HW_CCM_CSCDR4_RD() |  (v)))
#define HW_CCM_CSCDR4_CLR(v)    (HW_CCM_CSCDR4_WR(HW_CCM_CSCDR4_RD() & ~(v)))
#define HW_CCM_CSCDR4_TOG(v)    (HW_CCM_CSCDR4_WR(HW_CCM_CSCDR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCDR4 bitfields
 */

/*
 * HW_CCM_CWDR - CCM Wakeup Detector Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_ccm_cwdr_t;
#endif

/*
 * constants & macros for entire CCM_CWDR register
 */
#define HW_CCM_CWDR_ADDR      (REGS_CCM_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CWDR           (*(volatile hw_ccm_cwdr_t *) HW_CCM_CWDR_ADDR)
#define HW_CCM_CWDR_RD()      (HW_CCM_CWDR.U)
#define HW_CCM_CWDR_WR(v)     (HW_CCM_CWDR.U = (v))
#define HW_CCM_CWDR_SET(v)    (HW_CCM_CWDR_WR(HW_CCM_CWDR_RD() |  (v)))
#define HW_CCM_CWDR_CLR(v)    (HW_CCM_CWDR_WR(HW_CCM_CWDR_RD() & ~(v)))
#define HW_CCM_CWDR_TOG(v)    (HW_CCM_CWDR_WR(HW_CCM_CWDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CWDR bitfields
 */

/*
 * HW_CCM_CDHIPR - CCM Divider Handshake In-Process Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AXI_PODF_BUSY : 1;
        unsigned AHB_PODF_BUSY : 1;
        unsigned MMDC_CH1_PODF_BUSY : 1;
        unsigned PERIPH2_CLK_SEL_BUSY : 1;
        unsigned MMDC_CH0_PODF_BUSY : 1;
        unsigned PERIPH_CLK_SEL_BUSY : 1;
        unsigned RESERVED0 : 10;
        unsigned ARM_PODF_BUSY : 1;
        unsigned RESERVED1 : 15;

    } B;
} hw_ccm_cdhipr_t;
#endif

/*
 * constants & macros for entire CCM_CDHIPR register
 */
#define HW_CCM_CDHIPR_ADDR      (REGS_CCM_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CDHIPR           (*(volatile hw_ccm_cdhipr_t *) HW_CCM_CDHIPR_ADDR)
#define HW_CCM_CDHIPR_RD()      (HW_CCM_CDHIPR.U)
#define HW_CCM_CDHIPR_WR(v)     (HW_CCM_CDHIPR.U = (v))
#define HW_CCM_CDHIPR_SET(v)    (HW_CCM_CDHIPR_WR(HW_CCM_CDHIPR_RD() |  (v)))
#define HW_CCM_CDHIPR_CLR(v)    (HW_CCM_CDHIPR_WR(HW_CCM_CDHIPR_RD() & ~(v)))
#define HW_CCM_CDHIPR_TOG(v)    (HW_CCM_CDHIPR_WR(HW_CCM_CDHIPR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CDHIPR bitfields
 */

/* --- Register HW_CCM_CDHIPR, field AXI_PODF_BUSY */

#define BP_CCM_CDHIPR_AXI_PODF_BUSY      0
#define BM_CCM_CDHIPR_AXI_PODF_BUSY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_AXI_PODF_BUSY(v)   ((((reg32_t) v) << 0) & BM_CCM_CDHIPR_AXI_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_AXI_PODF_BUSY(v)   (((v) << 0) & BM_CCM_CDHIPR_AXI_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_AXI_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, AXI_PODF_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field AHB_PODF_BUSY */

#define BP_CCM_CDHIPR_AHB_PODF_BUSY      1
#define BM_CCM_CDHIPR_AHB_PODF_BUSY      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_AHB_PODF_BUSY(v)   ((((reg32_t) v) << 1) & BM_CCM_CDHIPR_AHB_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_AHB_PODF_BUSY(v)   (((v) << 1) & BM_CCM_CDHIPR_AHB_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_AHB_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, AHB_PODF_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field MMDC_CH1_PODF_BUSY */

#define BP_CCM_CDHIPR_MMDC_CH1_PODF_BUSY      2
#define BM_CCM_CDHIPR_MMDC_CH1_PODF_BUSY      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_MMDC_CH1_PODF_BUSY(v)   ((((reg32_t) v) << 2) & BM_CCM_CDHIPR_MMDC_CH1_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_MMDC_CH1_PODF_BUSY(v)   (((v) << 2) & BM_CCM_CDHIPR_MMDC_CH1_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_MMDC_CH1_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, MMDC_CH1_PODF_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field PERIPH2_CLK_SEL_BUSY */

#define BP_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY      3
#define BM_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY(v)   ((((reg32_t) v) << 3) & BM_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY)
#else
#define BF_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY(v)   (((v) << 3) & BM_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY(v)   BF_CS1(CCM_CDHIPR, PERIPH2_CLK_SEL_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field MMDC_CH0_PODF_BUSY */

#define BP_CCM_CDHIPR_MMDC_CH0_PODF_BUSY      4
#define BM_CCM_CDHIPR_MMDC_CH0_PODF_BUSY      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_MMDC_CH0_PODF_BUSY(v)   ((((reg32_t) v) << 4) & BM_CCM_CDHIPR_MMDC_CH0_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_MMDC_CH0_PODF_BUSY(v)   (((v) << 4) & BM_CCM_CDHIPR_MMDC_CH0_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_MMDC_CH0_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, MMDC_CH0_PODF_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field PERIPH_CLK_SEL_BUSY */

#define BP_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY      5
#define BM_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY(v)   ((((reg32_t) v) << 5) & BM_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY)
#else
#define BF_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY(v)   (((v) << 5) & BM_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY(v)   BF_CS1(CCM_CDHIPR, PERIPH_CLK_SEL_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field ARM_PODF_BUSY */

#define BP_CCM_CDHIPR_ARM_PODF_BUSY      16
#define BM_CCM_CDHIPR_ARM_PODF_BUSY      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_ARM_PODF_BUSY(v)   ((((reg32_t) v) << 16) & BM_CCM_CDHIPR_ARM_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_ARM_PODF_BUSY(v)   (((v) << 16) & BM_CCM_CDHIPR_ARM_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_ARM_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, ARM_PODF_BUSY, v)
#endif

/*
 * HW_CCM_CDCR - CCM DVFS Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2;
        unsigned RESERVED1 : 30;

    } B;
} hw_ccm_cdcr_t;
#endif

/*
 * constants & macros for entire CCM_CDCR register
 */
#define HW_CCM_CDCR_ADDR      (REGS_CCM_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CDCR           (*(volatile hw_ccm_cdcr_t *) HW_CCM_CDCR_ADDR)
#define HW_CCM_CDCR_RD()      (HW_CCM_CDCR.U)
#define HW_CCM_CDCR_WR(v)     (HW_CCM_CDCR.U = (v))
#define HW_CCM_CDCR_SET(v)    (HW_CCM_CDCR_WR(HW_CCM_CDCR_RD() |  (v)))
#define HW_CCM_CDCR_CLR(v)    (HW_CCM_CDCR_WR(HW_CCM_CDCR_RD() & ~(v)))
#define HW_CCM_CDCR_TOG(v)    (HW_CCM_CDCR_WR(HW_CCM_CDCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CDCR bitfields
 */

/*
 * HW_CCM_CTOR - CCM Testing Observability Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OBS_SPARE_OUTPUT_2_SEL : 4;
        unsigned OBS_SPARE_OUTPUT_1_SEL : 4;
        unsigned OBS_SPARE_OUTPUT_0_SEL : 5;
        unsigned OBS_EN : 1;
        unsigned RESERVED0 : 18;

    } B;
} hw_ccm_ctor_t;
#endif

/*
 * constants & macros for entire CCM_CTOR register
 */
#define HW_CCM_CTOR_ADDR      (REGS_CCM_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CTOR           (*(volatile hw_ccm_ctor_t *) HW_CCM_CTOR_ADDR)
#define HW_CCM_CTOR_RD()      (HW_CCM_CTOR.U)
#define HW_CCM_CTOR_WR(v)     (HW_CCM_CTOR.U = (v))
#define HW_CCM_CTOR_SET(v)    (HW_CCM_CTOR_WR(HW_CCM_CTOR_RD() |  (v)))
#define HW_CCM_CTOR_CLR(v)    (HW_CCM_CTOR_WR(HW_CCM_CTOR_RD() & ~(v)))
#define HW_CCM_CTOR_TOG(v)    (HW_CCM_CTOR_WR(HW_CCM_CTOR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CTOR bitfields
 */

/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_2_SEL */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL      0
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL)
#else
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   (((v) << 0) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   BF_CS1(CCM_CTOR, OBS_SPARE_OUTPUT_2_SEL, v)
#endif

/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_1_SEL */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL      4
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   ((((reg32_t) v) << 4) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL)
#else
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   (((v) << 4) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   BF_CS1(CCM_CTOR, OBS_SPARE_OUTPUT_1_SEL, v)
#endif

/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_0_SEL */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL      8
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   ((((reg32_t) v) << 8) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL)
#else
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   (((v) << 8) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   BF_CS1(CCM_CTOR, OBS_SPARE_OUTPUT_0_SEL, v)
#endif

/* --- Register HW_CCM_CTOR, field OBS_EN */

#define BP_CCM_CTOR_OBS_EN      13
#define BM_CCM_CTOR_OBS_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CTOR_OBS_EN(v)   ((((reg32_t) v) << 13) & BM_CCM_CTOR_OBS_EN)
#else
#define BF_CCM_CTOR_OBS_EN(v)   (((v) << 13) & BM_CCM_CTOR_OBS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CTOR_OBS_EN(v)   BF_CS1(CCM_CTOR, OBS_EN, v)
#endif

/*
 * HW_CCM_CLPCR - CCM Low Power Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LPM : 2;
        unsigned BYPASS_PMIC_VFUNCTIONAL_READY : 1;
        unsigned RESERVED0 : 2;
        unsigned ARM_CLK_DIS_ON_LPM : 1;
        unsigned SBYOS : 1;
        unsigned DIS_REF_OSC : 1;
        unsigned VSTBY : 1;
        unsigned STBY_COUNT : 2;
        unsigned COSC_PWRDOWN : 1;
        unsigned RESERVED1 : 4;
        unsigned WB_PER_AT_LPM : 1;
        unsigned WB_CORE_AT_LPM : 1;
        unsigned RESERVED2 : 1;
        unsigned BYPASS_MMDC_CH0_LPM_HS : 1;
        unsigned RESERVED3 : 1;
        unsigned BYPASS_MMDC_CH1_LPM_HS : 1;
        unsigned MASK_CORE0_WFI : 1;
        unsigned MASK_CORE1_WFI : 1;
        unsigned MASK_CORE2_WFI : 1;
        unsigned MASK_CORE3_WFI : 1;
        unsigned MASK_SCU_IDLE : 1;
        unsigned MASK_L2CC_IDLE : 1;
        unsigned RESERVED4 : 4;

    } B;
} hw_ccm_clpcr_t;
#endif

/*
 * constants & macros for entire CCM_CLPCR register
 */
#define HW_CCM_CLPCR_ADDR      (REGS_CCM_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CLPCR           (*(volatile hw_ccm_clpcr_t *) HW_CCM_CLPCR_ADDR)
#define HW_CCM_CLPCR_RD()      (HW_CCM_CLPCR.U)
#define HW_CCM_CLPCR_WR(v)     (HW_CCM_CLPCR.U = (v))
#define HW_CCM_CLPCR_SET(v)    (HW_CCM_CLPCR_WR(HW_CCM_CLPCR_RD() |  (v)))
#define HW_CCM_CLPCR_CLR(v)    (HW_CCM_CLPCR_WR(HW_CCM_CLPCR_RD() & ~(v)))
#define HW_CCM_CLPCR_TOG(v)    (HW_CCM_CLPCR_WR(HW_CCM_CLPCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CLPCR bitfields
 */

/* --- Register HW_CCM_CLPCR, field LPM */

#define BP_CCM_CLPCR_LPM      0
#define BM_CCM_CLPCR_LPM      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_LPM(v)   ((((reg32_t) v) << 0) & BM_CCM_CLPCR_LPM)
#else
#define BF_CCM_CLPCR_LPM(v)   (((v) << 0) & BM_CCM_CLPCR_LPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_LPM(v)   BF_CS1(CCM_CLPCR, LPM, v)
#endif

/* --- Register HW_CCM_CLPCR, field BYPASS_PMIC_VFUNCTIONAL_READY */

#define BP_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY      2
#define BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   ((((reg32_t) v) << 2) & BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY)
#else
#define BF_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   (((v) << 2) & BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   BF_CS1(CCM_CLPCR, BYPASS_PMIC_VFUNCTIONAL_READY, v)
#endif

/* --- Register HW_CCM_CLPCR, field ARM_CLK_DIS_ON_LPM */

#define BP_CCM_CLPCR_ARM_CLK_DIS_ON_LPM      5
#define BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   ((((reg32_t) v) << 5) & BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM)
#else
#define BF_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   (((v) << 5) & BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   BF_CS1(CCM_CLPCR, ARM_CLK_DIS_ON_LPM, v)
#endif

/* --- Register HW_CCM_CLPCR, field SBYOS */

#define BP_CCM_CLPCR_SBYOS      6
#define BM_CCM_CLPCR_SBYOS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_SBYOS(v)   ((((reg32_t) v) << 6) & BM_CCM_CLPCR_SBYOS)
#else
#define BF_CCM_CLPCR_SBYOS(v)   (((v) << 6) & BM_CCM_CLPCR_SBYOS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_SBYOS(v)   BF_CS1(CCM_CLPCR, SBYOS, v)
#endif

/* --- Register HW_CCM_CLPCR, field DIS_REF_OSC */

#define BP_CCM_CLPCR_DIS_REF_OSC      7
#define BM_CCM_CLPCR_DIS_REF_OSC      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_DIS_REF_OSC(v)   ((((reg32_t) v) << 7) & BM_CCM_CLPCR_DIS_REF_OSC)
#else
#define BF_CCM_CLPCR_DIS_REF_OSC(v)   (((v) << 7) & BM_CCM_CLPCR_DIS_REF_OSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_DIS_REF_OSC(v)   BF_CS1(CCM_CLPCR, DIS_REF_OSC, v)
#endif

/* --- Register HW_CCM_CLPCR, field VSTBY */

#define BP_CCM_CLPCR_VSTBY      8
#define BM_CCM_CLPCR_VSTBY      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_VSTBY(v)   ((((reg32_t) v) << 8) & BM_CCM_CLPCR_VSTBY)
#else
#define BF_CCM_CLPCR_VSTBY(v)   (((v) << 8) & BM_CCM_CLPCR_VSTBY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_VSTBY(v)   BF_CS1(CCM_CLPCR, VSTBY, v)
#endif

/* --- Register HW_CCM_CLPCR, field STBY_COUNT */

#define BP_CCM_CLPCR_STBY_COUNT      9
#define BM_CCM_CLPCR_STBY_COUNT      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_STBY_COUNT(v)   ((((reg32_t) v) << 9) & BM_CCM_CLPCR_STBY_COUNT)
#else
#define BF_CCM_CLPCR_STBY_COUNT(v)   (((v) << 9) & BM_CCM_CLPCR_STBY_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_STBY_COUNT(v)   BF_CS1(CCM_CLPCR, STBY_COUNT, v)
#endif

/* --- Register HW_CCM_CLPCR, field COSC_PWRDOWN */

#define BP_CCM_CLPCR_COSC_PWRDOWN      11
#define BM_CCM_CLPCR_COSC_PWRDOWN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_COSC_PWRDOWN(v)   ((((reg32_t) v) << 11) & BM_CCM_CLPCR_COSC_PWRDOWN)
#else
#define BF_CCM_CLPCR_COSC_PWRDOWN(v)   (((v) << 11) & BM_CCM_CLPCR_COSC_PWRDOWN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_COSC_PWRDOWN(v)   BF_CS1(CCM_CLPCR, COSC_PWRDOWN, v)
#endif

/* --- Register HW_CCM_CLPCR, field WB_PER_AT_LPM */

#define BP_CCM_CLPCR_WB_PER_AT_LPM      16
#define BM_CCM_CLPCR_WB_PER_AT_LPM      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_WB_PER_AT_LPM(v)   ((((reg32_t) v) << 16) & BM_CCM_CLPCR_WB_PER_AT_LPM)
#else
#define BF_CCM_CLPCR_WB_PER_AT_LPM(v)   (((v) << 16) & BM_CCM_CLPCR_WB_PER_AT_LPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_WB_PER_AT_LPM(v)   BF_CS1(CCM_CLPCR, WB_PER_AT_LPM, v)
#endif

/* --- Register HW_CCM_CLPCR, field WB_CORE_AT_LPM */

#define BP_CCM_CLPCR_WB_CORE_AT_LPM      17
#define BM_CCM_CLPCR_WB_CORE_AT_LPM      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_WB_CORE_AT_LPM(v)   ((((reg32_t) v) << 17) & BM_CCM_CLPCR_WB_CORE_AT_LPM)
#else
#define BF_CCM_CLPCR_WB_CORE_AT_LPM(v)   (((v) << 17) & BM_CCM_CLPCR_WB_CORE_AT_LPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_WB_CORE_AT_LPM(v)   BF_CS1(CCM_CLPCR, WB_CORE_AT_LPM, v)
#endif

/* --- Register HW_CCM_CLPCR, field BYPASS_MMDC_CH0_LPM_HS */

#define BP_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS      19
#define BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   ((((reg32_t) v) << 19) & BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS)
#else
#define BF_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   (((v) << 19) & BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   BF_CS1(CCM_CLPCR, BYPASS_MMDC_CH0_LPM_HS, v)
#endif

/* --- Register HW_CCM_CLPCR, field BYPASS_MMDC_CH1_LPM_HS */

#define BP_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS      21
#define BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   ((((reg32_t) v) << 21) & BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS)
#else
#define BF_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   (((v) << 21) & BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   BF_CS1(CCM_CLPCR, BYPASS_MMDC_CH1_LPM_HS, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_CORE0_WFI */

#define BP_CCM_CLPCR_MASK_CORE0_WFI      22
#define BM_CCM_CLPCR_MASK_CORE0_WFI      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_CORE0_WFI(v)   ((((reg32_t) v) << 22) & BM_CCM_CLPCR_MASK_CORE0_WFI)
#else
#define BF_CCM_CLPCR_MASK_CORE0_WFI(v)   (((v) << 22) & BM_CCM_CLPCR_MASK_CORE0_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_CORE0_WFI(v)   BF_CS1(CCM_CLPCR, MASK_CORE0_WFI, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_CORE1_WFI */

#define BP_CCM_CLPCR_MASK_CORE1_WFI      23
#define BM_CCM_CLPCR_MASK_CORE1_WFI      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_CORE1_WFI(v)   ((((reg32_t) v) << 23) & BM_CCM_CLPCR_MASK_CORE1_WFI)
#else
#define BF_CCM_CLPCR_MASK_CORE1_WFI(v)   (((v) << 23) & BM_CCM_CLPCR_MASK_CORE1_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_CORE1_WFI(v)   BF_CS1(CCM_CLPCR, MASK_CORE1_WFI, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_CORE2_WFI */

#define BP_CCM_CLPCR_MASK_CORE2_WFI      24
#define BM_CCM_CLPCR_MASK_CORE2_WFI      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_CORE2_WFI(v)   ((((reg32_t) v) << 24) & BM_CCM_CLPCR_MASK_CORE2_WFI)
#else
#define BF_CCM_CLPCR_MASK_CORE2_WFI(v)   (((v) << 24) & BM_CCM_CLPCR_MASK_CORE2_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_CORE2_WFI(v)   BF_CS1(CCM_CLPCR, MASK_CORE2_WFI, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_CORE3_WFI */

#define BP_CCM_CLPCR_MASK_CORE3_WFI      25
#define BM_CCM_CLPCR_MASK_CORE3_WFI      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_CORE3_WFI(v)   ((((reg32_t) v) << 25) & BM_CCM_CLPCR_MASK_CORE3_WFI)
#else
#define BF_CCM_CLPCR_MASK_CORE3_WFI(v)   (((v) << 25) & BM_CCM_CLPCR_MASK_CORE3_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_CORE3_WFI(v)   BF_CS1(CCM_CLPCR, MASK_CORE3_WFI, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_SCU_IDLE */

#define BP_CCM_CLPCR_MASK_SCU_IDLE      26
#define BM_CCM_CLPCR_MASK_SCU_IDLE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_SCU_IDLE(v)   ((((reg32_t) v) << 26) & BM_CCM_CLPCR_MASK_SCU_IDLE)
#else
#define BF_CCM_CLPCR_MASK_SCU_IDLE(v)   (((v) << 26) & BM_CCM_CLPCR_MASK_SCU_IDLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_SCU_IDLE(v)   BF_CS1(CCM_CLPCR, MASK_SCU_IDLE, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_L2CC_IDLE */

#define BP_CCM_CLPCR_MASK_L2CC_IDLE      27
#define BM_CCM_CLPCR_MASK_L2CC_IDLE      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_L2CC_IDLE(v)   ((((reg32_t) v) << 27) & BM_CCM_CLPCR_MASK_L2CC_IDLE)
#else
#define BF_CCM_CLPCR_MASK_L2CC_IDLE(v)   (((v) << 27) & BM_CCM_CLPCR_MASK_L2CC_IDLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_L2CC_IDLE(v)   BF_CS1(CCM_CLPCR, MASK_L2CC_IDLE, v)
#endif

/*
 * HW_CCM_CISR - CCM Interrupt Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LRF_PLL : 1;
        unsigned RESERVED0 : 5;
        unsigned COSC_READY : 1;
        unsigned RESERVED1 : 10;
        unsigned AXI_PODF_LOADED : 1;
        unsigned AXI_B_PODF_LOADED : 1;
        unsigned PERIPH2_CLK_SEL_LOADED : 1;
        unsigned AHB_PODF_LOADED : 1;
        unsigned MMDC_CH1_PODF_LOADED : 1;
        unsigned PERIPH_CLK_SEL_LOADED : 1;
        unsigned MMDC_CH0_PODF_LOADED : 1;
        unsigned RESERVED2 : 2;
        unsigned ARM_PODF_LOADED : 1;
        unsigned RESERVED3 : 5;

    } B;
} hw_ccm_cisr_t;
#endif

/*
 * constants & macros for entire CCM_CISR register
 */
#define HW_CCM_CISR_ADDR      (REGS_CCM_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CISR           (*(volatile hw_ccm_cisr_t *) HW_CCM_CISR_ADDR)
#define HW_CCM_CISR_RD()      (HW_CCM_CISR.U)
#define HW_CCM_CISR_WR(v)     (HW_CCM_CISR.U = (v))
#define HW_CCM_CISR_SET(v)    (HW_CCM_CISR_WR(HW_CCM_CISR_RD() |  (v)))
#define HW_CCM_CISR_CLR(v)    (HW_CCM_CISR_WR(HW_CCM_CISR_RD() & ~(v)))
#define HW_CCM_CISR_TOG(v)    (HW_CCM_CISR_WR(HW_CCM_CISR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CISR bitfields
 */

/* --- Register HW_CCM_CISR, field LRF_PLL */

#define BP_CCM_CISR_LRF_PLL      0
#define BM_CCM_CISR_LRF_PLL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_LRF_PLL(v)   ((((reg32_t) v) << 0) & BM_CCM_CISR_LRF_PLL)
#else
#define BF_CCM_CISR_LRF_PLL(v)   (((v) << 0) & BM_CCM_CISR_LRF_PLL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_LRF_PLL(v)   BF_CS1(CCM_CISR, LRF_PLL, v)
#endif

/* --- Register HW_CCM_CISR, field COSC_READY */

#define BP_CCM_CISR_COSC_READY      6
#define BM_CCM_CISR_COSC_READY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_COSC_READY(v)   ((((reg32_t) v) << 6) & BM_CCM_CISR_COSC_READY)
#else
#define BF_CCM_CISR_COSC_READY(v)   (((v) << 6) & BM_CCM_CISR_COSC_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_COSC_READY(v)   BF_CS1(CCM_CISR, COSC_READY, v)
#endif

/* --- Register HW_CCM_CISR, field AXI_PODF_LOADED */

#define BP_CCM_CISR_AXI_PODF_LOADED      17
#define BM_CCM_CISR_AXI_PODF_LOADED      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_AXI_PODF_LOADED(v)   ((((reg32_t) v) << 17) & BM_CCM_CISR_AXI_PODF_LOADED)
#else
#define BF_CCM_CISR_AXI_PODF_LOADED(v)   (((v) << 17) & BM_CCM_CISR_AXI_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_AXI_PODF_LOADED(v)   BF_CS1(CCM_CISR, AXI_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field AXI_B_PODF_LOADED */

#define BP_CCM_CISR_AXI_B_PODF_LOADED      18
#define BM_CCM_CISR_AXI_B_PODF_LOADED      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_AXI_B_PODF_LOADED(v)   ((((reg32_t) v) << 18) & BM_CCM_CISR_AXI_B_PODF_LOADED)
#else
#define BF_CCM_CISR_AXI_B_PODF_LOADED(v)   (((v) << 18) & BM_CCM_CISR_AXI_B_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_AXI_B_PODF_LOADED(v)   BF_CS1(CCM_CISR, AXI_B_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field PERIPH2_CLK_SEL_LOADED */

#define BP_CCM_CISR_PERIPH2_CLK_SEL_LOADED      19
#define BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   ((((reg32_t) v) << 19) & BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED)
#else
#define BF_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   (((v) << 19) & BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   BF_CS1(CCM_CISR, PERIPH2_CLK_SEL_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field AHB_PODF_LOADED */

#define BP_CCM_CISR_AHB_PODF_LOADED      20
#define BM_CCM_CISR_AHB_PODF_LOADED      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_AHB_PODF_LOADED(v)   ((((reg32_t) v) << 20) & BM_CCM_CISR_AHB_PODF_LOADED)
#else
#define BF_CCM_CISR_AHB_PODF_LOADED(v)   (((v) << 20) & BM_CCM_CISR_AHB_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_AHB_PODF_LOADED(v)   BF_CS1(CCM_CISR, AHB_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field MMDC_CH1_PODF_LOADED */

#define BP_CCM_CISR_MMDC_CH1_PODF_LOADED      21
#define BM_CCM_CISR_MMDC_CH1_PODF_LOADED      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   ((((reg32_t) v) << 21) & BM_CCM_CISR_MMDC_CH1_PODF_LOADED)
#else
#define BF_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   (((v) << 21) & BM_CCM_CISR_MMDC_CH1_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   BF_CS1(CCM_CISR, MMDC_CH1_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field PERIPH_CLK_SEL_LOADED */

#define BP_CCM_CISR_PERIPH_CLK_SEL_LOADED      22
#define BM_CCM_CISR_PERIPH_CLK_SEL_LOADED      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   ((((reg32_t) v) << 22) & BM_CCM_CISR_PERIPH_CLK_SEL_LOADED)
#else
#define BF_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   (((v) << 22) & BM_CCM_CISR_PERIPH_CLK_SEL_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   BF_CS1(CCM_CISR, PERIPH_CLK_SEL_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field MMDC_CH0_PODF_LOADED */

#define BP_CCM_CISR_MMDC_CH0_PODF_LOADED      23
#define BM_CCM_CISR_MMDC_CH0_PODF_LOADED      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   ((((reg32_t) v) << 23) & BM_CCM_CISR_MMDC_CH0_PODF_LOADED)
#else
#define BF_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   (((v) << 23) & BM_CCM_CISR_MMDC_CH0_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   BF_CS1(CCM_CISR, MMDC_CH0_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field ARM_PODF_LOADED */

#define BP_CCM_CISR_ARM_PODF_LOADED      26
#define BM_CCM_CISR_ARM_PODF_LOADED      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_ARM_PODF_LOADED(v)   ((((reg32_t) v) << 26) & BM_CCM_CISR_ARM_PODF_LOADED)
#else
#define BF_CCM_CISR_ARM_PODF_LOADED(v)   (((v) << 26) & BM_CCM_CISR_ARM_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_ARM_PODF_LOADED(v)   BF_CS1(CCM_CISR, ARM_PODF_LOADED, v)
#endif

/*
 * HW_CCM_CIMR - CCM Interrupt Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MASK_LRF_PLL : 1;
        unsigned RESERVED0 : 5;
        unsigned MASK_COSC_READY : 1;
        unsigned RESERVED1 : 10;
        unsigned MASK_AXI_PODF_LOADED : 1;
        unsigned MASK_AXI_B_PODF_LOADED : 1;
        unsigned MASK_PERIPH2_CLK_SEL_LOADED : 1;
        unsigned MASK_AHB_PODF_LOADED : 1;
        unsigned MASK_MMDC_CH1_PODF_LOADED : 1;
        unsigned MASK_PERIPH_CLK_SEL_LOADED : 1;
        unsigned MASK_MMDC_CH0_PODF_LOADED : 1;
        unsigned RESERVED2 : 2;
        unsigned ARM_PODF_LOADED : 1;
        unsigned RESERVED3 : 5;

    } B;
} hw_ccm_cimr_t;
#endif

/*
 * constants & macros for entire CCM_CIMR register
 */
#define HW_CCM_CIMR_ADDR      (REGS_CCM_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CIMR           (*(volatile hw_ccm_cimr_t *) HW_CCM_CIMR_ADDR)
#define HW_CCM_CIMR_RD()      (HW_CCM_CIMR.U)
#define HW_CCM_CIMR_WR(v)     (HW_CCM_CIMR.U = (v))
#define HW_CCM_CIMR_SET(v)    (HW_CCM_CIMR_WR(HW_CCM_CIMR_RD() |  (v)))
#define HW_CCM_CIMR_CLR(v)    (HW_CCM_CIMR_WR(HW_CCM_CIMR_RD() & ~(v)))
#define HW_CCM_CIMR_TOG(v)    (HW_CCM_CIMR_WR(HW_CCM_CIMR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CIMR bitfields
 */

/* --- Register HW_CCM_CIMR, field MASK_LRF_PLL */

#define BP_CCM_CIMR_MASK_LRF_PLL      0
#define BM_CCM_CIMR_MASK_LRF_PLL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_LRF_PLL(v)   ((((reg32_t) v) << 0) & BM_CCM_CIMR_MASK_LRF_PLL)
#else
#define BF_CCM_CIMR_MASK_LRF_PLL(v)   (((v) << 0) & BM_CCM_CIMR_MASK_LRF_PLL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_LRF_PLL(v)   BF_CS1(CCM_CIMR, MASK_LRF_PLL, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_COSC_READY */

#define BP_CCM_CIMR_MASK_COSC_READY      6
#define BM_CCM_CIMR_MASK_COSC_READY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_COSC_READY(v)   ((((reg32_t) v) << 6) & BM_CCM_CIMR_MASK_COSC_READY)
#else
#define BF_CCM_CIMR_MASK_COSC_READY(v)   (((v) << 6) & BM_CCM_CIMR_MASK_COSC_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_COSC_READY(v)   BF_CS1(CCM_CIMR, MASK_COSC_READY, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_AXI_PODF_LOADED */

#define BP_CCM_CIMR_MASK_AXI_PODF_LOADED      17
#define BM_CCM_CIMR_MASK_AXI_PODF_LOADED      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   ((((reg32_t) v) << 17) & BM_CCM_CIMR_MASK_AXI_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   (((v) << 17) & BM_CCM_CIMR_MASK_AXI_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_AXI_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_AXI_B_PODF_LOADED */

#define BP_CCM_CIMR_MASK_AXI_B_PODF_LOADED      18
#define BM_CCM_CIMR_MASK_AXI_B_PODF_LOADED      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_AXI_B_PODF_LOADED(v)   ((((reg32_t) v) << 18) & BM_CCM_CIMR_MASK_AXI_B_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_AXI_B_PODF_LOADED(v)   (((v) << 18) & BM_CCM_CIMR_MASK_AXI_B_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_AXI_B_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_AXI_B_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_PERIPH2_CLK_SEL_LOADED */

#define BP_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED      19
#define BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   ((((reg32_t) v) << 19) & BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED)
#else
#define BF_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   (((v) << 19) & BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   BF_CS1(CCM_CIMR, MASK_PERIPH2_CLK_SEL_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_AHB_PODF_LOADED */

#define BP_CCM_CIMR_MASK_AHB_PODF_LOADED      20
#define BM_CCM_CIMR_MASK_AHB_PODF_LOADED      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   ((((reg32_t) v) << 20) & BM_CCM_CIMR_MASK_AHB_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   (((v) << 20) & BM_CCM_CIMR_MASK_AHB_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_AHB_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_MMDC_CH1_PODF_LOADED */

#define BP_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED      21
#define BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   ((((reg32_t) v) << 21) & BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   (((v) << 21) & BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_MMDC_CH1_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_PERIPH_CLK_SEL_LOADED */

#define BP_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED      22
#define BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   ((((reg32_t) v) << 22) & BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED)
#else
#define BF_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   (((v) << 22) & BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   BF_CS1(CCM_CIMR, MASK_PERIPH_CLK_SEL_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_MMDC_CH0_PODF_LOADED */

#define BP_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED      23
#define BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   ((((reg32_t) v) << 23) & BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   (((v) << 23) & BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_MMDC_CH0_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field ARM_PODF_LOADED */

#define BP_CCM_CIMR_ARM_PODF_LOADED      26
#define BM_CCM_CIMR_ARM_PODF_LOADED      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_ARM_PODF_LOADED(v)   ((((reg32_t) v) << 26) & BM_CCM_CIMR_ARM_PODF_LOADED)
#else
#define BF_CCM_CIMR_ARM_PODF_LOADED(v)   (((v) << 26) & BM_CCM_CIMR_ARM_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_ARM_PODF_LOADED(v)   BF_CS1(CCM_CIMR, ARM_PODF_LOADED, v)
#endif

/*
 * HW_CCM_CCOSR - CCM Clock Output Source Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CKO1_SEL : 4;
        unsigned CKO1_DIV : 3;
        unsigned CKO1_EN : 1;
        unsigned CKO1_CKO2_SEL : 1;
        unsigned RESERVED0 : 7;
        unsigned CKO2_SEL : 5;
        unsigned CKO2_DIV : 3;
        unsigned CKO2_EN : 1;
        unsigned RESERVED1 : 7;

    } B;
} hw_ccm_ccosr_t;
#endif

/*
 * constants & macros for entire CCM_CCOSR register
 */
#define HW_CCM_CCOSR_ADDR      (REGS_CCM_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCOSR           (*(volatile hw_ccm_ccosr_t *) HW_CCM_CCOSR_ADDR)
#define HW_CCM_CCOSR_RD()      (HW_CCM_CCOSR.U)
#define HW_CCM_CCOSR_WR(v)     (HW_CCM_CCOSR.U = (v))
#define HW_CCM_CCOSR_SET(v)    (HW_CCM_CCOSR_WR(HW_CCM_CCOSR_RD() |  (v)))
#define HW_CCM_CCOSR_CLR(v)    (HW_CCM_CCOSR_WR(HW_CCM_CCOSR_RD() & ~(v)))
#define HW_CCM_CCOSR_TOG(v)    (HW_CCM_CCOSR_WR(HW_CCM_CCOSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCOSR bitfields
 */

/* --- Register HW_CCM_CCOSR, field CKO1_SEL */

#define BP_CCM_CCOSR_CKO1_SEL      0
#define BM_CCM_CCOSR_CKO1_SEL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO1_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CCOSR_CKO1_SEL)
#else
#define BF_CCM_CCOSR_CKO1_SEL(v)   (((v) << 0) & BM_CCM_CCOSR_CKO1_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO1_SEL(v)   BF_CS1(CCM_CCOSR, CKO1_SEL, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO1_DIV */

#define BP_CCM_CCOSR_CKO1_DIV      4
#define BM_CCM_CCOSR_CKO1_DIV      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO1_DIV(v)   ((((reg32_t) v) << 4) & BM_CCM_CCOSR_CKO1_DIV)
#else
#define BF_CCM_CCOSR_CKO1_DIV(v)   (((v) << 4) & BM_CCM_CCOSR_CKO1_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO1_DIV(v)   BF_CS1(CCM_CCOSR, CKO1_DIV, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO1_EN */

#define BP_CCM_CCOSR_CKO1_EN      7
#define BM_CCM_CCOSR_CKO1_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO1_EN(v)   ((((reg32_t) v) << 7) & BM_CCM_CCOSR_CKO1_EN)
#else
#define BF_CCM_CCOSR_CKO1_EN(v)   (((v) << 7) & BM_CCM_CCOSR_CKO1_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO1_EN(v)   BF_CS1(CCM_CCOSR, CKO1_EN, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO1_CKO2_SEL */

#define BP_CCM_CCOSR_CKO1_CKO2_SEL      8
#define BM_CCM_CCOSR_CKO1_CKO2_SEL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO1_CKO2_SEL(v)   ((((reg32_t) v) << 8) & BM_CCM_CCOSR_CKO1_CKO2_SEL)
#else
#define BF_CCM_CCOSR_CKO1_CKO2_SEL(v)   (((v) << 8) & BM_CCM_CCOSR_CKO1_CKO2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO1_CKO2_SEL(v)   BF_CS1(CCM_CCOSR, CKO1_CKO2_SEL, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO2_SEL */

#define BP_CCM_CCOSR_CKO2_SEL      16
#define BM_CCM_CCOSR_CKO2_SEL      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO2_SEL(v)   ((((reg32_t) v) << 16) & BM_CCM_CCOSR_CKO2_SEL)
#else
#define BF_CCM_CCOSR_CKO2_SEL(v)   (((v) << 16) & BM_CCM_CCOSR_CKO2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO2_SEL(v)   BF_CS1(CCM_CCOSR, CKO2_SEL, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO2_DIV */

#define BP_CCM_CCOSR_CKO2_DIV      21
#define BM_CCM_CCOSR_CKO2_DIV      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO2_DIV(v)   ((((reg32_t) v) << 21) & BM_CCM_CCOSR_CKO2_DIV)
#else
#define BF_CCM_CCOSR_CKO2_DIV(v)   (((v) << 21) & BM_CCM_CCOSR_CKO2_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO2_DIV(v)   BF_CS1(CCM_CCOSR, CKO2_DIV, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO2_EN */

#define BP_CCM_CCOSR_CKO2_EN      24
#define BM_CCM_CCOSR_CKO2_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO2_EN(v)   ((((reg32_t) v) << 24) & BM_CCM_CCOSR_CKO2_EN)
#else
#define BF_CCM_CCOSR_CKO2_EN(v)   (((v) << 24) & BM_CCM_CCOSR_CKO2_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO2_EN(v)   BF_CS1(CCM_CCOSR, CKO2_EN, v)
#endif

/*
 * HW_CCM_CGPR - CCM General Purpose Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PMIC_DELAY_SCALER : 1;
        unsigned RESERVED0 : 1;
        unsigned MMDC_EXT_CLK_DIS : 1;
        unsigned RESERVED1 : 1;
        unsigned EFUSE_PROG_SUPPLY_GATE : 1;
        unsigned RESERVED2 : 2;
        unsigned RESERVED3 : 2;
        unsigned RESERVED4 : 7;
        unsigned FPL : 1;
        unsigned RESERVED5 : 15;

    } B;
} hw_ccm_cgpr_t;
#endif

/*
 * constants & macros for entire CCM_CGPR register
 */
#define HW_CCM_CGPR_ADDR      (REGS_CCM_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CGPR           (*(volatile hw_ccm_cgpr_t *) HW_CCM_CGPR_ADDR)
#define HW_CCM_CGPR_RD()      (HW_CCM_CGPR.U)
#define HW_CCM_CGPR_WR(v)     (HW_CCM_CGPR.U = (v))
#define HW_CCM_CGPR_SET(v)    (HW_CCM_CGPR_WR(HW_CCM_CGPR_RD() |  (v)))
#define HW_CCM_CGPR_CLR(v)    (HW_CCM_CGPR_WR(HW_CCM_CGPR_RD() & ~(v)))
#define HW_CCM_CGPR_TOG(v)    (HW_CCM_CGPR_WR(HW_CCM_CGPR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CGPR bitfields
 */

/* --- Register HW_CCM_CGPR, field PMIC_DELAY_SCALER */

#define BP_CCM_CGPR_PMIC_DELAY_SCALER      0
#define BM_CCM_CGPR_PMIC_DELAY_SCALER      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CGPR_PMIC_DELAY_SCALER(v)   ((((reg32_t) v) << 0) & BM_CCM_CGPR_PMIC_DELAY_SCALER)
#else
#define BF_CCM_CGPR_PMIC_DELAY_SCALER(v)   (((v) << 0) & BM_CCM_CGPR_PMIC_DELAY_SCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CGPR_PMIC_DELAY_SCALER(v)   BF_CS1(CCM_CGPR, PMIC_DELAY_SCALER, v)
#endif

/* --- Register HW_CCM_CGPR, field MMDC_EXT_CLK_DIS */

#define BP_CCM_CGPR_MMDC_EXT_CLK_DIS      2
#define BM_CCM_CGPR_MMDC_EXT_CLK_DIS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   ((((reg32_t) v) << 2) & BM_CCM_CGPR_MMDC_EXT_CLK_DIS)
#else
#define BF_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   (((v) << 2) & BM_CCM_CGPR_MMDC_EXT_CLK_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   BF_CS1(CCM_CGPR, MMDC_EXT_CLK_DIS, v)
#endif

/* --- Register HW_CCM_CGPR, field EFUSE_PROG_SUPPLY_GATE */

#define BP_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE      4
#define BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   ((((reg32_t) v) << 4) & BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE)
#else
#define BF_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   (((v) << 4) & BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   BF_CS1(CCM_CGPR, EFUSE_PROG_SUPPLY_GATE, v)
#endif

/* --- Register HW_CCM_CGPR, field FPL */

#define BP_CCM_CGPR_FPL      16
#define BM_CCM_CGPR_FPL      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CGPR_FPL(v)   ((((reg32_t) v) << 16) & BM_CCM_CGPR_FPL)
#else
#define BF_CCM_CGPR_FPL(v)   (((v) << 16) & BM_CCM_CGPR_FPL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CGPR_FPL(v)   BF_CS1(CCM_CGPR, FPL, v)
#endif

/*
 * HW_CCM_CCGR0 - CCM Clock Gating Register 0
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2;
        unsigned CG1 : 2;
        unsigned CG2 : 2;
        unsigned CG3 : 2;
        unsigned CG4 : 2;
        unsigned CG5 : 2;
        unsigned CG6 : 2;
        unsigned CG7 : 2;
        unsigned CG8 : 2;
        unsigned CG9 : 2;
        unsigned CG10 : 2;
        unsigned CG11 : 2;
        unsigned CG12 : 2;
        unsigned CG13 : 2;
        unsigned CG14 : 2;
        unsigned CG15 : 2;

    } B;
} hw_ccm_ccgr0_t;
#endif

/*
 * constants & macros for entire CCM_CCGR0 register
 */
#define HW_CCM_CCGR0_ADDR      (REGS_CCM_BASE + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR0           (*(volatile hw_ccm_ccgr0_t *) HW_CCM_CCGR0_ADDR)
#define HW_CCM_CCGR0_RD()      (HW_CCM_CCGR0.U)
#define HW_CCM_CCGR0_WR(v)     (HW_CCM_CCGR0.U = (v))
#define HW_CCM_CCGR0_SET(v)    (HW_CCM_CCGR0_WR(HW_CCM_CCGR0_RD() |  (v)))
#define HW_CCM_CCGR0_CLR(v)    (HW_CCM_CCGR0_WR(HW_CCM_CCGR0_RD() & ~(v)))
#define HW_CCM_CCGR0_TOG(v)    (HW_CCM_CCGR0_WR(HW_CCM_CCGR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR0 bitfields
 */

/* --- Register HW_CCM_CCGR0, field CG0 */

#define BP_CCM_CCGR0_CG0      0
#define BM_CCM_CCGR0_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR0_CG0)
#else
#define BF_CCM_CCGR0_CG0(v)   (((v) << 0) & BM_CCM_CCGR0_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG0(v)   BF_CS1(CCM_CCGR0, CG0, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG1 */

#define BP_CCM_CCGR0_CG1      2
#define BM_CCM_CCGR0_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR0_CG1)
#else
#define BF_CCM_CCGR0_CG1(v)   (((v) << 2) & BM_CCM_CCGR0_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG1(v)   BF_CS1(CCM_CCGR0, CG1, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG2 */

#define BP_CCM_CCGR0_CG2      4
#define BM_CCM_CCGR0_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR0_CG2)
#else
#define BF_CCM_CCGR0_CG2(v)   (((v) << 4) & BM_CCM_CCGR0_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG2(v)   BF_CS1(CCM_CCGR0, CG2, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG3 */

#define BP_CCM_CCGR0_CG3      6
#define BM_CCM_CCGR0_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR0_CG3)
#else
#define BF_CCM_CCGR0_CG3(v)   (((v) << 6) & BM_CCM_CCGR0_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG3(v)   BF_CS1(CCM_CCGR0, CG3, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG4 */

#define BP_CCM_CCGR0_CG4      8
#define BM_CCM_CCGR0_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR0_CG4)
#else
#define BF_CCM_CCGR0_CG4(v)   (((v) << 8) & BM_CCM_CCGR0_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG4(v)   BF_CS1(CCM_CCGR0, CG4, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG5 */

#define BP_CCM_CCGR0_CG5      10
#define BM_CCM_CCGR0_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR0_CG5)
#else
#define BF_CCM_CCGR0_CG5(v)   (((v) << 10) & BM_CCM_CCGR0_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG5(v)   BF_CS1(CCM_CCGR0, CG5, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG6 */

#define BP_CCM_CCGR0_CG6      12
#define BM_CCM_CCGR0_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR0_CG6)
#else
#define BF_CCM_CCGR0_CG6(v)   (((v) << 12) & BM_CCM_CCGR0_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG6(v)   BF_CS1(CCM_CCGR0, CG6, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG7 */

#define BP_CCM_CCGR0_CG7      14
#define BM_CCM_CCGR0_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR0_CG7)
#else
#define BF_CCM_CCGR0_CG7(v)   (((v) << 14) & BM_CCM_CCGR0_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG7(v)   BF_CS1(CCM_CCGR0, CG7, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG8 */

#define BP_CCM_CCGR0_CG8      16
#define BM_CCM_CCGR0_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR0_CG8)
#else
#define BF_CCM_CCGR0_CG8(v)   (((v) << 16) & BM_CCM_CCGR0_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG8(v)   BF_CS1(CCM_CCGR0, CG8, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG9 */

#define BP_CCM_CCGR0_CG9      18
#define BM_CCM_CCGR0_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR0_CG9)
#else
#define BF_CCM_CCGR0_CG9(v)   (((v) << 18) & BM_CCM_CCGR0_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG9(v)   BF_CS1(CCM_CCGR0, CG9, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG10 */

#define BP_CCM_CCGR0_CG10      20
#define BM_CCM_CCGR0_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR0_CG10)
#else
#define BF_CCM_CCGR0_CG10(v)   (((v) << 20) & BM_CCM_CCGR0_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG10(v)   BF_CS1(CCM_CCGR0, CG10, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG11 */

#define BP_CCM_CCGR0_CG11      22
#define BM_CCM_CCGR0_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR0_CG11)
#else
#define BF_CCM_CCGR0_CG11(v)   (((v) << 22) & BM_CCM_CCGR0_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG11(v)   BF_CS1(CCM_CCGR0, CG11, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG12 */

#define BP_CCM_CCGR0_CG12      24
#define BM_CCM_CCGR0_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR0_CG12)
#else
#define BF_CCM_CCGR0_CG12(v)   (((v) << 24) & BM_CCM_CCGR0_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG12(v)   BF_CS1(CCM_CCGR0, CG12, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG13 */

#define BP_CCM_CCGR0_CG13      26
#define BM_CCM_CCGR0_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR0_CG13)
#else
#define BF_CCM_CCGR0_CG13(v)   (((v) << 26) & BM_CCM_CCGR0_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG13(v)   BF_CS1(CCM_CCGR0, CG13, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG14 */

#define BP_CCM_CCGR0_CG14      28
#define BM_CCM_CCGR0_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR0_CG14)
#else
#define BF_CCM_CCGR0_CG14(v)   (((v) << 28) & BM_CCM_CCGR0_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG14(v)   BF_CS1(CCM_CCGR0, CG14, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG15 */

#define BP_CCM_CCGR0_CG15      30
#define BM_CCM_CCGR0_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR0_CG15)
#else
#define BF_CCM_CCGR0_CG15(v)   (((v) << 30) & BM_CCM_CCGR0_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG15(v)   BF_CS1(CCM_CCGR0, CG15, v)
#endif

/*
 * HW_CCM_CCGR1 - CCM Clock Gating Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2;
        unsigned CG1 : 2;
        unsigned CG2 : 2;
        unsigned CG3 : 2;
        unsigned CG4 : 2;
        unsigned CG5 : 2;
        unsigned CG6 : 2;
        unsigned CG7 : 2;
        unsigned CG8 : 2;
        unsigned CG9 : 2;
        unsigned CG10 : 2;
        unsigned CG11 : 2;
        unsigned CG12 : 2;
        unsigned CG13 : 2;
        unsigned CG14 : 2;
        unsigned CG15 : 2;

    } B;
} hw_ccm_ccgr1_t;
#endif

/*
 * constants & macros for entire CCM_CCGR1 register
 */
#define HW_CCM_CCGR1_ADDR      (REGS_CCM_BASE + 0x6c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR1           (*(volatile hw_ccm_ccgr1_t *) HW_CCM_CCGR1_ADDR)
#define HW_CCM_CCGR1_RD()      (HW_CCM_CCGR1.U)
#define HW_CCM_CCGR1_WR(v)     (HW_CCM_CCGR1.U = (v))
#define HW_CCM_CCGR1_SET(v)    (HW_CCM_CCGR1_WR(HW_CCM_CCGR1_RD() |  (v)))
#define HW_CCM_CCGR1_CLR(v)    (HW_CCM_CCGR1_WR(HW_CCM_CCGR1_RD() & ~(v)))
#define HW_CCM_CCGR1_TOG(v)    (HW_CCM_CCGR1_WR(HW_CCM_CCGR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR1 bitfields
 */

/* --- Register HW_CCM_CCGR1, field CG0 */

#define BP_CCM_CCGR1_CG0      0
#define BM_CCM_CCGR1_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR1_CG0)
#else
#define BF_CCM_CCGR1_CG0(v)   (((v) << 0) & BM_CCM_CCGR1_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG0(v)   BF_CS1(CCM_CCGR1, CG0, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG1 */

#define BP_CCM_CCGR1_CG1      2
#define BM_CCM_CCGR1_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR1_CG1)
#else
#define BF_CCM_CCGR1_CG1(v)   (((v) << 2) & BM_CCM_CCGR1_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG1(v)   BF_CS1(CCM_CCGR1, CG1, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG2 */

#define BP_CCM_CCGR1_CG2      4
#define BM_CCM_CCGR1_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR1_CG2)
#else
#define BF_CCM_CCGR1_CG2(v)   (((v) << 4) & BM_CCM_CCGR1_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG2(v)   BF_CS1(CCM_CCGR1, CG2, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG3 */

#define BP_CCM_CCGR1_CG3      6
#define BM_CCM_CCGR1_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR1_CG3)
#else
#define BF_CCM_CCGR1_CG3(v)   (((v) << 6) & BM_CCM_CCGR1_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG3(v)   BF_CS1(CCM_CCGR1, CG3, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG4 */

#define BP_CCM_CCGR1_CG4      8
#define BM_CCM_CCGR1_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR1_CG4)
#else
#define BF_CCM_CCGR1_CG4(v)   (((v) << 8) & BM_CCM_CCGR1_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG4(v)   BF_CS1(CCM_CCGR1, CG4, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG5 */

#define BP_CCM_CCGR1_CG5      10
#define BM_CCM_CCGR1_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR1_CG5)
#else
#define BF_CCM_CCGR1_CG5(v)   (((v) << 10) & BM_CCM_CCGR1_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG5(v)   BF_CS1(CCM_CCGR1, CG5, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG6 */

#define BP_CCM_CCGR1_CG6      12
#define BM_CCM_CCGR1_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR1_CG6)
#else
#define BF_CCM_CCGR1_CG6(v)   (((v) << 12) & BM_CCM_CCGR1_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG6(v)   BF_CS1(CCM_CCGR1, CG6, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG7 */

#define BP_CCM_CCGR1_CG7      14
#define BM_CCM_CCGR1_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR1_CG7)
#else
#define BF_CCM_CCGR1_CG7(v)   (((v) << 14) & BM_CCM_CCGR1_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG7(v)   BF_CS1(CCM_CCGR1, CG7, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG8 */

#define BP_CCM_CCGR1_CG8      16
#define BM_CCM_CCGR1_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR1_CG8)
#else
#define BF_CCM_CCGR1_CG8(v)   (((v) << 16) & BM_CCM_CCGR1_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG8(v)   BF_CS1(CCM_CCGR1, CG8, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG9 */

#define BP_CCM_CCGR1_CG9      18
#define BM_CCM_CCGR1_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR1_CG9)
#else
#define BF_CCM_CCGR1_CG9(v)   (((v) << 18) & BM_CCM_CCGR1_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG9(v)   BF_CS1(CCM_CCGR1, CG9, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG10 */

#define BP_CCM_CCGR1_CG10      20
#define BM_CCM_CCGR1_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR1_CG10)
#else
#define BF_CCM_CCGR1_CG10(v)   (((v) << 20) & BM_CCM_CCGR1_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG10(v)   BF_CS1(CCM_CCGR1, CG10, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG11 */

#define BP_CCM_CCGR1_CG11      22
#define BM_CCM_CCGR1_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR1_CG11)
#else
#define BF_CCM_CCGR1_CG11(v)   (((v) << 22) & BM_CCM_CCGR1_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG11(v)   BF_CS1(CCM_CCGR1, CG11, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG12 */

#define BP_CCM_CCGR1_CG12      24
#define BM_CCM_CCGR1_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR1_CG12)
#else
#define BF_CCM_CCGR1_CG12(v)   (((v) << 24) & BM_CCM_CCGR1_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG12(v)   BF_CS1(CCM_CCGR1, CG12, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG13 */

#define BP_CCM_CCGR1_CG13      26
#define BM_CCM_CCGR1_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR1_CG13)
#else
#define BF_CCM_CCGR1_CG13(v)   (((v) << 26) & BM_CCM_CCGR1_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG13(v)   BF_CS1(CCM_CCGR1, CG13, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG14 */

#define BP_CCM_CCGR1_CG14      28
#define BM_CCM_CCGR1_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR1_CG14)
#else
#define BF_CCM_CCGR1_CG14(v)   (((v) << 28) & BM_CCM_CCGR1_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG14(v)   BF_CS1(CCM_CCGR1, CG14, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG15 */

#define BP_CCM_CCGR1_CG15      30
#define BM_CCM_CCGR1_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR1_CG15)
#else
#define BF_CCM_CCGR1_CG15(v)   (((v) << 30) & BM_CCM_CCGR1_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG15(v)   BF_CS1(CCM_CCGR1, CG15, v)
#endif

/*
 * HW_CCM_CCGR2 - CCM Clock Gating Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2;
        unsigned CG1 : 2;
        unsigned CG2 : 2;
        unsigned CG3 : 2;
        unsigned CG4 : 2;
        unsigned CG5 : 2;
        unsigned CG6 : 2;
        unsigned CG7 : 2;
        unsigned CG8 : 2;
        unsigned CG9 : 2;
        unsigned CG10 : 2;
        unsigned CG11 : 2;
        unsigned CG12 : 2;
        unsigned CG13 : 2;
        unsigned CG14 : 2;
        unsigned CG15 : 2;

    } B;
} hw_ccm_ccgr2_t;
#endif

/*
 * constants & macros for entire CCM_CCGR2 register
 */
#define HW_CCM_CCGR2_ADDR      (REGS_CCM_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR2           (*(volatile hw_ccm_ccgr2_t *) HW_CCM_CCGR2_ADDR)
#define HW_CCM_CCGR2_RD()      (HW_CCM_CCGR2.U)
#define HW_CCM_CCGR2_WR(v)     (HW_CCM_CCGR2.U = (v))
#define HW_CCM_CCGR2_SET(v)    (HW_CCM_CCGR2_WR(HW_CCM_CCGR2_RD() |  (v)))
#define HW_CCM_CCGR2_CLR(v)    (HW_CCM_CCGR2_WR(HW_CCM_CCGR2_RD() & ~(v)))
#define HW_CCM_CCGR2_TOG(v)    (HW_CCM_CCGR2_WR(HW_CCM_CCGR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR2 bitfields
 */

/* --- Register HW_CCM_CCGR2, field CG0 */

#define BP_CCM_CCGR2_CG0      0
#define BM_CCM_CCGR2_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR2_CG0)
#else
#define BF_CCM_CCGR2_CG0(v)   (((v) << 0) & BM_CCM_CCGR2_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG0(v)   BF_CS1(CCM_CCGR2, CG0, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG1 */

#define BP_CCM_CCGR2_CG1      2
#define BM_CCM_CCGR2_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR2_CG1)
#else
#define BF_CCM_CCGR2_CG1(v)   (((v) << 2) & BM_CCM_CCGR2_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG1(v)   BF_CS1(CCM_CCGR2, CG1, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG2 */

#define BP_CCM_CCGR2_CG2      4
#define BM_CCM_CCGR2_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR2_CG2)
#else
#define BF_CCM_CCGR2_CG2(v)   (((v) << 4) & BM_CCM_CCGR2_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG2(v)   BF_CS1(CCM_CCGR2, CG2, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG3 */

#define BP_CCM_CCGR2_CG3      6
#define BM_CCM_CCGR2_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR2_CG3)
#else
#define BF_CCM_CCGR2_CG3(v)   (((v) << 6) & BM_CCM_CCGR2_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG3(v)   BF_CS1(CCM_CCGR2, CG3, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG4 */

#define BP_CCM_CCGR2_CG4      8
#define BM_CCM_CCGR2_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR2_CG4)
#else
#define BF_CCM_CCGR2_CG4(v)   (((v) << 8) & BM_CCM_CCGR2_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG4(v)   BF_CS1(CCM_CCGR2, CG4, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG5 */

#define BP_CCM_CCGR2_CG5      10
#define BM_CCM_CCGR2_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR2_CG5)
#else
#define BF_CCM_CCGR2_CG5(v)   (((v) << 10) & BM_CCM_CCGR2_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG5(v)   BF_CS1(CCM_CCGR2, CG5, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG6 */

#define BP_CCM_CCGR2_CG6      12
#define BM_CCM_CCGR2_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR2_CG6)
#else
#define BF_CCM_CCGR2_CG6(v)   (((v) << 12) & BM_CCM_CCGR2_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG6(v)   BF_CS1(CCM_CCGR2, CG6, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG7 */

#define BP_CCM_CCGR2_CG7      14
#define BM_CCM_CCGR2_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR2_CG7)
#else
#define BF_CCM_CCGR2_CG7(v)   (((v) << 14) & BM_CCM_CCGR2_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG7(v)   BF_CS1(CCM_CCGR2, CG7, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG8 */

#define BP_CCM_CCGR2_CG8      16
#define BM_CCM_CCGR2_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR2_CG8)
#else
#define BF_CCM_CCGR2_CG8(v)   (((v) << 16) & BM_CCM_CCGR2_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG8(v)   BF_CS1(CCM_CCGR2, CG8, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG9 */

#define BP_CCM_CCGR2_CG9      18
#define BM_CCM_CCGR2_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR2_CG9)
#else
#define BF_CCM_CCGR2_CG9(v)   (((v) << 18) & BM_CCM_CCGR2_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG9(v)   BF_CS1(CCM_CCGR2, CG9, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG10 */

#define BP_CCM_CCGR2_CG10      20
#define BM_CCM_CCGR2_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR2_CG10)
#else
#define BF_CCM_CCGR2_CG10(v)   (((v) << 20) & BM_CCM_CCGR2_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG10(v)   BF_CS1(CCM_CCGR2, CG10, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG11 */

#define BP_CCM_CCGR2_CG11      22
#define BM_CCM_CCGR2_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR2_CG11)
#else
#define BF_CCM_CCGR2_CG11(v)   (((v) << 22) & BM_CCM_CCGR2_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG11(v)   BF_CS1(CCM_CCGR2, CG11, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG12 */

#define BP_CCM_CCGR2_CG12      24
#define BM_CCM_CCGR2_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR2_CG12)
#else
#define BF_CCM_CCGR2_CG12(v)   (((v) << 24) & BM_CCM_CCGR2_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG12(v)   BF_CS1(CCM_CCGR2, CG12, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG13 */

#define BP_CCM_CCGR2_CG13      26
#define BM_CCM_CCGR2_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR2_CG13)
#else
#define BF_CCM_CCGR2_CG13(v)   (((v) << 26) & BM_CCM_CCGR2_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG13(v)   BF_CS1(CCM_CCGR2, CG13, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG14 */

#define BP_CCM_CCGR2_CG14      28
#define BM_CCM_CCGR2_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR2_CG14)
#else
#define BF_CCM_CCGR2_CG14(v)   (((v) << 28) & BM_CCM_CCGR2_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG14(v)   BF_CS1(CCM_CCGR2, CG14, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG15 */

#define BP_CCM_CCGR2_CG15      30
#define BM_CCM_CCGR2_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR2_CG15)
#else
#define BF_CCM_CCGR2_CG15(v)   (((v) << 30) & BM_CCM_CCGR2_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG15(v)   BF_CS1(CCM_CCGR2, CG15, v)
#endif

/*
 * HW_CCM_CCGR3 - CCM Clock Gating Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2;
        unsigned CG1 : 2;
        unsigned CG2 : 2;
        unsigned CG3 : 2;
        unsigned CG4 : 2;
        unsigned CG5 : 2;
        unsigned CG6 : 2;
        unsigned CG7 : 2;
        unsigned CG8 : 2;
        unsigned CG9 : 2;
        unsigned CG10 : 2;
        unsigned CG11 : 2;
        unsigned CG12 : 2;
        unsigned CG13 : 2;
        unsigned CG14 : 2;
        unsigned CG15 : 2;

    } B;
} hw_ccm_ccgr3_t;
#endif

/*
 * constants & macros for entire CCM_CCGR3 register
 */
#define HW_CCM_CCGR3_ADDR      (REGS_CCM_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR3           (*(volatile hw_ccm_ccgr3_t *) HW_CCM_CCGR3_ADDR)
#define HW_CCM_CCGR3_RD()      (HW_CCM_CCGR3.U)
#define HW_CCM_CCGR3_WR(v)     (HW_CCM_CCGR3.U = (v))
#define HW_CCM_CCGR3_SET(v)    (HW_CCM_CCGR3_WR(HW_CCM_CCGR3_RD() |  (v)))
#define HW_CCM_CCGR3_CLR(v)    (HW_CCM_CCGR3_WR(HW_CCM_CCGR3_RD() & ~(v)))
#define HW_CCM_CCGR3_TOG(v)    (HW_CCM_CCGR3_WR(HW_CCM_CCGR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR3 bitfields
 */

/* --- Register HW_CCM_CCGR3, field CG0 */

#define BP_CCM_CCGR3_CG0      0
#define BM_CCM_CCGR3_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR3_CG0)
#else
#define BF_CCM_CCGR3_CG0(v)   (((v) << 0) & BM_CCM_CCGR3_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG0(v)   BF_CS1(CCM_CCGR3, CG0, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG1 */

#define BP_CCM_CCGR3_CG1      2
#define BM_CCM_CCGR3_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR3_CG1)
#else
#define BF_CCM_CCGR3_CG1(v)   (((v) << 2) & BM_CCM_CCGR3_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG1(v)   BF_CS1(CCM_CCGR3, CG1, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG2 */

#define BP_CCM_CCGR3_CG2      4
#define BM_CCM_CCGR3_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR3_CG2)
#else
#define BF_CCM_CCGR3_CG2(v)   (((v) << 4) & BM_CCM_CCGR3_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG2(v)   BF_CS1(CCM_CCGR3, CG2, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG3 */

#define BP_CCM_CCGR3_CG3      6
#define BM_CCM_CCGR3_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR3_CG3)
#else
#define BF_CCM_CCGR3_CG3(v)   (((v) << 6) & BM_CCM_CCGR3_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG3(v)   BF_CS1(CCM_CCGR3, CG3, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG4 */

#define BP_CCM_CCGR3_CG4      8
#define BM_CCM_CCGR3_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR3_CG4)
#else
#define BF_CCM_CCGR3_CG4(v)   (((v) << 8) & BM_CCM_CCGR3_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG4(v)   BF_CS1(CCM_CCGR3, CG4, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG5 */

#define BP_CCM_CCGR3_CG5      10
#define BM_CCM_CCGR3_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR3_CG5)
#else
#define BF_CCM_CCGR3_CG5(v)   (((v) << 10) & BM_CCM_CCGR3_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG5(v)   BF_CS1(CCM_CCGR3, CG5, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG6 */

#define BP_CCM_CCGR3_CG6      12
#define BM_CCM_CCGR3_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR3_CG6)
#else
#define BF_CCM_CCGR3_CG6(v)   (((v) << 12) & BM_CCM_CCGR3_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG6(v)   BF_CS1(CCM_CCGR3, CG6, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG7 */

#define BP_CCM_CCGR3_CG7      14
#define BM_CCM_CCGR3_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR3_CG7)
#else
#define BF_CCM_CCGR3_CG7(v)   (((v) << 14) & BM_CCM_CCGR3_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG7(v)   BF_CS1(CCM_CCGR3, CG7, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG8 */

#define BP_CCM_CCGR3_CG8      16
#define BM_CCM_CCGR3_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR3_CG8)
#else
#define BF_CCM_CCGR3_CG8(v)   (((v) << 16) & BM_CCM_CCGR3_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG8(v)   BF_CS1(CCM_CCGR3, CG8, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG9 */

#define BP_CCM_CCGR3_CG9      18
#define BM_CCM_CCGR3_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR3_CG9)
#else
#define BF_CCM_CCGR3_CG9(v)   (((v) << 18) & BM_CCM_CCGR3_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG9(v)   BF_CS1(CCM_CCGR3, CG9, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG10 */

#define BP_CCM_CCGR3_CG10      20
#define BM_CCM_CCGR3_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR3_CG10)
#else
#define BF_CCM_CCGR3_CG10(v)   (((v) << 20) & BM_CCM_CCGR3_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG10(v)   BF_CS1(CCM_CCGR3, CG10, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG11 */

#define BP_CCM_CCGR3_CG11      22
#define BM_CCM_CCGR3_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR3_CG11)
#else
#define BF_CCM_CCGR3_CG11(v)   (((v) << 22) & BM_CCM_CCGR3_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG11(v)   BF_CS1(CCM_CCGR3, CG11, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG12 */

#define BP_CCM_CCGR3_CG12      24
#define BM_CCM_CCGR3_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR3_CG12)
#else
#define BF_CCM_CCGR3_CG12(v)   (((v) << 24) & BM_CCM_CCGR3_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG12(v)   BF_CS1(CCM_CCGR3, CG12, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG13 */

#define BP_CCM_CCGR3_CG13      26
#define BM_CCM_CCGR3_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR3_CG13)
#else
#define BF_CCM_CCGR3_CG13(v)   (((v) << 26) & BM_CCM_CCGR3_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG13(v)   BF_CS1(CCM_CCGR3, CG13, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG14 */

#define BP_CCM_CCGR3_CG14      28
#define BM_CCM_CCGR3_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR3_CG14)
#else
#define BF_CCM_CCGR3_CG14(v)   (((v) << 28) & BM_CCM_CCGR3_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG14(v)   BF_CS1(CCM_CCGR3, CG14, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG15 */

#define BP_CCM_CCGR3_CG15      30
#define BM_CCM_CCGR3_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR3_CG15)
#else
#define BF_CCM_CCGR3_CG15(v)   (((v) << 30) & BM_CCM_CCGR3_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG15(v)   BF_CS1(CCM_CCGR3, CG15, v)
#endif

/*
 * HW_CCM_CCGR4 - CCM Clock Gating Register 4
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2;
        unsigned CG1 : 2;
        unsigned CG2 : 2;
        unsigned CG3 : 2;
        unsigned CG4 : 2;
        unsigned CG5 : 2;
        unsigned CG6 : 2;
        unsigned CG7 : 2;
        unsigned CG8 : 2;
        unsigned CG9 : 2;
        unsigned CG10 : 2;
        unsigned CG11 : 2;
        unsigned CG12 : 2;
        unsigned CG13 : 2;
        unsigned CG14 : 2;
        unsigned CG15 : 2;

    } B;
} hw_ccm_ccgr4_t;
#endif

/*
 * constants & macros for entire CCM_CCGR4 register
 */
#define HW_CCM_CCGR4_ADDR      (REGS_CCM_BASE + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR4           (*(volatile hw_ccm_ccgr4_t *) HW_CCM_CCGR4_ADDR)
#define HW_CCM_CCGR4_RD()      (HW_CCM_CCGR4.U)
#define HW_CCM_CCGR4_WR(v)     (HW_CCM_CCGR4.U = (v))
#define HW_CCM_CCGR4_SET(v)    (HW_CCM_CCGR4_WR(HW_CCM_CCGR4_RD() |  (v)))
#define HW_CCM_CCGR4_CLR(v)    (HW_CCM_CCGR4_WR(HW_CCM_CCGR4_RD() & ~(v)))
#define HW_CCM_CCGR4_TOG(v)    (HW_CCM_CCGR4_WR(HW_CCM_CCGR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR4 bitfields
 */

/* --- Register HW_CCM_CCGR4, field CG0 */

#define BP_CCM_CCGR4_CG0      0
#define BM_CCM_CCGR4_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR4_CG0)
#else
#define BF_CCM_CCGR4_CG0(v)   (((v) << 0) & BM_CCM_CCGR4_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG0(v)   BF_CS1(CCM_CCGR4, CG0, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG1 */

#define BP_CCM_CCGR4_CG1      2
#define BM_CCM_CCGR4_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR4_CG1)
#else
#define BF_CCM_CCGR4_CG1(v)   (((v) << 2) & BM_CCM_CCGR4_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG1(v)   BF_CS1(CCM_CCGR4, CG1, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG2 */

#define BP_CCM_CCGR4_CG2      4
#define BM_CCM_CCGR4_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR4_CG2)
#else
#define BF_CCM_CCGR4_CG2(v)   (((v) << 4) & BM_CCM_CCGR4_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG2(v)   BF_CS1(CCM_CCGR4, CG2, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG3 */

#define BP_CCM_CCGR4_CG3      6
#define BM_CCM_CCGR4_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR4_CG3)
#else
#define BF_CCM_CCGR4_CG3(v)   (((v) << 6) & BM_CCM_CCGR4_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG3(v)   BF_CS1(CCM_CCGR4, CG3, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG4 */

#define BP_CCM_CCGR4_CG4      8
#define BM_CCM_CCGR4_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR4_CG4)
#else
#define BF_CCM_CCGR4_CG4(v)   (((v) << 8) & BM_CCM_CCGR4_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG4(v)   BF_CS1(CCM_CCGR4, CG4, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG5 */

#define BP_CCM_CCGR4_CG5      10
#define BM_CCM_CCGR4_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR4_CG5)
#else
#define BF_CCM_CCGR4_CG5(v)   (((v) << 10) & BM_CCM_CCGR4_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG5(v)   BF_CS1(CCM_CCGR4, CG5, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG6 */

#define BP_CCM_CCGR4_CG6      12
#define BM_CCM_CCGR4_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR4_CG6)
#else
#define BF_CCM_CCGR4_CG6(v)   (((v) << 12) & BM_CCM_CCGR4_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG6(v)   BF_CS1(CCM_CCGR4, CG6, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG7 */

#define BP_CCM_CCGR4_CG7      14
#define BM_CCM_CCGR4_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR4_CG7)
#else
#define BF_CCM_CCGR4_CG7(v)   (((v) << 14) & BM_CCM_CCGR4_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG7(v)   BF_CS1(CCM_CCGR4, CG7, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG8 */

#define BP_CCM_CCGR4_CG8      16
#define BM_CCM_CCGR4_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR4_CG8)
#else
#define BF_CCM_CCGR4_CG8(v)   (((v) << 16) & BM_CCM_CCGR4_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG8(v)   BF_CS1(CCM_CCGR4, CG8, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG9 */

#define BP_CCM_CCGR4_CG9      18
#define BM_CCM_CCGR4_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR4_CG9)
#else
#define BF_CCM_CCGR4_CG9(v)   (((v) << 18) & BM_CCM_CCGR4_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG9(v)   BF_CS1(CCM_CCGR4, CG9, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG10 */

#define BP_CCM_CCGR4_CG10      20
#define BM_CCM_CCGR4_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR4_CG10)
#else
#define BF_CCM_CCGR4_CG10(v)   (((v) << 20) & BM_CCM_CCGR4_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG10(v)   BF_CS1(CCM_CCGR4, CG10, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG11 */

#define BP_CCM_CCGR4_CG11      22
#define BM_CCM_CCGR4_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR4_CG11)
#else
#define BF_CCM_CCGR4_CG11(v)   (((v) << 22) & BM_CCM_CCGR4_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG11(v)   BF_CS1(CCM_CCGR4, CG11, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG12 */

#define BP_CCM_CCGR4_CG12      24
#define BM_CCM_CCGR4_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR4_CG12)
#else
#define BF_CCM_CCGR4_CG12(v)   (((v) << 24) & BM_CCM_CCGR4_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG12(v)   BF_CS1(CCM_CCGR4, CG12, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG13 */

#define BP_CCM_CCGR4_CG13      26
#define BM_CCM_CCGR4_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR4_CG13)
#else
#define BF_CCM_CCGR4_CG13(v)   (((v) << 26) & BM_CCM_CCGR4_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG13(v)   BF_CS1(CCM_CCGR4, CG13, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG14 */

#define BP_CCM_CCGR4_CG14      28
#define BM_CCM_CCGR4_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR4_CG14)
#else
#define BF_CCM_CCGR4_CG14(v)   (((v) << 28) & BM_CCM_CCGR4_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG14(v)   BF_CS1(CCM_CCGR4, CG14, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG15 */

#define BP_CCM_CCGR4_CG15      30
#define BM_CCM_CCGR4_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR4_CG15)
#else
#define BF_CCM_CCGR4_CG15(v)   (((v) << 30) & BM_CCM_CCGR4_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG15(v)   BF_CS1(CCM_CCGR4, CG15, v)
#endif

/*
 * HW_CCM_CCGR5 - CCM Clock Gating Register 5
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2;
        unsigned CG1 : 2;
        unsigned CG2 : 2;
        unsigned CG3 : 2;
        unsigned CG4 : 2;
        unsigned CG5 : 2;
        unsigned CG6 : 2;
        unsigned CG7 : 2;
        unsigned CG8 : 2;
        unsigned CG9 : 2;
        unsigned CG10 : 2;
        unsigned CG11 : 2;
        unsigned CG12 : 2;
        unsigned CG13 : 2;
        unsigned CG14 : 2;
        unsigned CG15 : 2;

    } B;
} hw_ccm_ccgr5_t;
#endif

/*
 * constants & macros for entire CCM_CCGR5 register
 */
#define HW_CCM_CCGR5_ADDR      (REGS_CCM_BASE + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR5           (*(volatile hw_ccm_ccgr5_t *) HW_CCM_CCGR5_ADDR)
#define HW_CCM_CCGR5_RD()      (HW_CCM_CCGR5.U)
#define HW_CCM_CCGR5_WR(v)     (HW_CCM_CCGR5.U = (v))
#define HW_CCM_CCGR5_SET(v)    (HW_CCM_CCGR5_WR(HW_CCM_CCGR5_RD() |  (v)))
#define HW_CCM_CCGR5_CLR(v)    (HW_CCM_CCGR5_WR(HW_CCM_CCGR5_RD() & ~(v)))
#define HW_CCM_CCGR5_TOG(v)    (HW_CCM_CCGR5_WR(HW_CCM_CCGR5_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR5 bitfields
 */

/* --- Register HW_CCM_CCGR5, field CG0 */

#define BP_CCM_CCGR5_CG0      0
#define BM_CCM_CCGR5_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR5_CG0)
#else
#define BF_CCM_CCGR5_CG0(v)   (((v) << 0) & BM_CCM_CCGR5_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG0(v)   BF_CS1(CCM_CCGR5, CG0, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG1 */

#define BP_CCM_CCGR5_CG1      2
#define BM_CCM_CCGR5_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR5_CG1)
#else
#define BF_CCM_CCGR5_CG1(v)   (((v) << 2) & BM_CCM_CCGR5_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG1(v)   BF_CS1(CCM_CCGR5, CG1, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG2 */

#define BP_CCM_CCGR5_CG2      4
#define BM_CCM_CCGR5_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR5_CG2)
#else
#define BF_CCM_CCGR5_CG2(v)   (((v) << 4) & BM_CCM_CCGR5_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG2(v)   BF_CS1(CCM_CCGR5, CG2, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG3 */

#define BP_CCM_CCGR5_CG3      6
#define BM_CCM_CCGR5_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR5_CG3)
#else
#define BF_CCM_CCGR5_CG3(v)   (((v) << 6) & BM_CCM_CCGR5_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG3(v)   BF_CS1(CCM_CCGR5, CG3, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG4 */

#define BP_CCM_CCGR5_CG4      8
#define BM_CCM_CCGR5_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR5_CG4)
#else
#define BF_CCM_CCGR5_CG4(v)   (((v) << 8) & BM_CCM_CCGR5_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG4(v)   BF_CS1(CCM_CCGR5, CG4, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG5 */

#define BP_CCM_CCGR5_CG5      10
#define BM_CCM_CCGR5_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR5_CG5)
#else
#define BF_CCM_CCGR5_CG5(v)   (((v) << 10) & BM_CCM_CCGR5_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG5(v)   BF_CS1(CCM_CCGR5, CG5, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG6 */

#define BP_CCM_CCGR5_CG6      12
#define BM_CCM_CCGR5_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR5_CG6)
#else
#define BF_CCM_CCGR5_CG6(v)   (((v) << 12) & BM_CCM_CCGR5_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG6(v)   BF_CS1(CCM_CCGR5, CG6, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG7 */

#define BP_CCM_CCGR5_CG7      14
#define BM_CCM_CCGR5_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR5_CG7)
#else
#define BF_CCM_CCGR5_CG7(v)   (((v) << 14) & BM_CCM_CCGR5_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG7(v)   BF_CS1(CCM_CCGR5, CG7, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG8 */

#define BP_CCM_CCGR5_CG8      16
#define BM_CCM_CCGR5_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR5_CG8)
#else
#define BF_CCM_CCGR5_CG8(v)   (((v) << 16) & BM_CCM_CCGR5_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG8(v)   BF_CS1(CCM_CCGR5, CG8, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG9 */

#define BP_CCM_CCGR5_CG9      18
#define BM_CCM_CCGR5_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR5_CG9)
#else
#define BF_CCM_CCGR5_CG9(v)   (((v) << 18) & BM_CCM_CCGR5_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG9(v)   BF_CS1(CCM_CCGR5, CG9, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG10 */

#define BP_CCM_CCGR5_CG10      20
#define BM_CCM_CCGR5_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR5_CG10)
#else
#define BF_CCM_CCGR5_CG10(v)   (((v) << 20) & BM_CCM_CCGR5_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG10(v)   BF_CS1(CCM_CCGR5, CG10, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG11 */

#define BP_CCM_CCGR5_CG11      22
#define BM_CCM_CCGR5_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR5_CG11)
#else
#define BF_CCM_CCGR5_CG11(v)   (((v) << 22) & BM_CCM_CCGR5_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG11(v)   BF_CS1(CCM_CCGR5, CG11, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG12 */

#define BP_CCM_CCGR5_CG12      24
#define BM_CCM_CCGR5_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR5_CG12)
#else
#define BF_CCM_CCGR5_CG12(v)   (((v) << 24) & BM_CCM_CCGR5_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG12(v)   BF_CS1(CCM_CCGR5, CG12, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG13 */

#define BP_CCM_CCGR5_CG13      26
#define BM_CCM_CCGR5_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR5_CG13)
#else
#define BF_CCM_CCGR5_CG13(v)   (((v) << 26) & BM_CCM_CCGR5_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG13(v)   BF_CS1(CCM_CCGR5, CG13, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG14 */

#define BP_CCM_CCGR5_CG14      28
#define BM_CCM_CCGR5_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR5_CG14)
#else
#define BF_CCM_CCGR5_CG14(v)   (((v) << 28) & BM_CCM_CCGR5_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG14(v)   BF_CS1(CCM_CCGR5, CG14, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG15 */

#define BP_CCM_CCGR5_CG15      30
#define BM_CCM_CCGR5_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR5_CG15)
#else
#define BF_CCM_CCGR5_CG15(v)   (((v) << 30) & BM_CCM_CCGR5_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG15(v)   BF_CS1(CCM_CCGR5, CG15, v)
#endif

/*
 * HW_CCM_CCGR6 - CCM Clock Gating Register 6
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2;
        unsigned CG1 : 2;
        unsigned CG2 : 2;
        unsigned CG3 : 2;
        unsigned CG4 : 2;
        unsigned CG5 : 2;
        unsigned CG6 : 2;
        unsigned CG7 : 2;
        unsigned CG8 : 2;
        unsigned CG9 : 2;
        unsigned CG10 : 2;
        unsigned CG11 : 2;
        unsigned CG12 : 2;
        unsigned CG13 : 2;
        unsigned CG14 : 2;
        unsigned CG15 : 2;

    } B;
} hw_ccm_ccgr6_t;
#endif

/*
 * constants & macros for entire CCM_CCGR6 register
 */
#define HW_CCM_CCGR6_ADDR      (REGS_CCM_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR6           (*(volatile hw_ccm_ccgr6_t *) HW_CCM_CCGR6_ADDR)
#define HW_CCM_CCGR6_RD()      (HW_CCM_CCGR6.U)
#define HW_CCM_CCGR6_WR(v)     (HW_CCM_CCGR6.U = (v))
#define HW_CCM_CCGR6_SET(v)    (HW_CCM_CCGR6_WR(HW_CCM_CCGR6_RD() |  (v)))
#define HW_CCM_CCGR6_CLR(v)    (HW_CCM_CCGR6_WR(HW_CCM_CCGR6_RD() & ~(v)))
#define HW_CCM_CCGR6_TOG(v)    (HW_CCM_CCGR6_WR(HW_CCM_CCGR6_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR6 bitfields
 */

/* --- Register HW_CCM_CCGR6, field CG0 */

#define BP_CCM_CCGR6_CG0      0
#define BM_CCM_CCGR6_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR6_CG0)
#else
#define BF_CCM_CCGR6_CG0(v)   (((v) << 0) & BM_CCM_CCGR6_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG0(v)   BF_CS1(CCM_CCGR6, CG0, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG1 */

#define BP_CCM_CCGR6_CG1      2
#define BM_CCM_CCGR6_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR6_CG1)
#else
#define BF_CCM_CCGR6_CG1(v)   (((v) << 2) & BM_CCM_CCGR6_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG1(v)   BF_CS1(CCM_CCGR6, CG1, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG2 */

#define BP_CCM_CCGR6_CG2      4
#define BM_CCM_CCGR6_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR6_CG2)
#else
#define BF_CCM_CCGR6_CG2(v)   (((v) << 4) & BM_CCM_CCGR6_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG2(v)   BF_CS1(CCM_CCGR6, CG2, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG3 */

#define BP_CCM_CCGR6_CG3      6
#define BM_CCM_CCGR6_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR6_CG3)
#else
#define BF_CCM_CCGR6_CG3(v)   (((v) << 6) & BM_CCM_CCGR6_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG3(v)   BF_CS1(CCM_CCGR6, CG3, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG4 */

#define BP_CCM_CCGR6_CG4      8
#define BM_CCM_CCGR6_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR6_CG4)
#else
#define BF_CCM_CCGR6_CG4(v)   (((v) << 8) & BM_CCM_CCGR6_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG4(v)   BF_CS1(CCM_CCGR6, CG4, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG5 */

#define BP_CCM_CCGR6_CG5      10
#define BM_CCM_CCGR6_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR6_CG5)
#else
#define BF_CCM_CCGR6_CG5(v)   (((v) << 10) & BM_CCM_CCGR6_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG5(v)   BF_CS1(CCM_CCGR6, CG5, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG6 */

#define BP_CCM_CCGR6_CG6      12
#define BM_CCM_CCGR6_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR6_CG6)
#else
#define BF_CCM_CCGR6_CG6(v)   (((v) << 12) & BM_CCM_CCGR6_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG6(v)   BF_CS1(CCM_CCGR6, CG6, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG7 */

#define BP_CCM_CCGR6_CG7      14
#define BM_CCM_CCGR6_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR6_CG7)
#else
#define BF_CCM_CCGR6_CG7(v)   (((v) << 14) & BM_CCM_CCGR6_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG7(v)   BF_CS1(CCM_CCGR6, CG7, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG8 */

#define BP_CCM_CCGR6_CG8      16
#define BM_CCM_CCGR6_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR6_CG8)
#else
#define BF_CCM_CCGR6_CG8(v)   (((v) << 16) & BM_CCM_CCGR6_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG8(v)   BF_CS1(CCM_CCGR6, CG8, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG9 */

#define BP_CCM_CCGR6_CG9      18
#define BM_CCM_CCGR6_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR6_CG9)
#else
#define BF_CCM_CCGR6_CG9(v)   (((v) << 18) & BM_CCM_CCGR6_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG9(v)   BF_CS1(CCM_CCGR6, CG9, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG10 */

#define BP_CCM_CCGR6_CG10      20
#define BM_CCM_CCGR6_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR6_CG10)
#else
#define BF_CCM_CCGR6_CG10(v)   (((v) << 20) & BM_CCM_CCGR6_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG10(v)   BF_CS1(CCM_CCGR6, CG10, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG11 */

#define BP_CCM_CCGR6_CG11      22
#define BM_CCM_CCGR6_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR6_CG11)
#else
#define BF_CCM_CCGR6_CG11(v)   (((v) << 22) & BM_CCM_CCGR6_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG11(v)   BF_CS1(CCM_CCGR6, CG11, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG12 */

#define BP_CCM_CCGR6_CG12      24
#define BM_CCM_CCGR6_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR6_CG12)
#else
#define BF_CCM_CCGR6_CG12(v)   (((v) << 24) & BM_CCM_CCGR6_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG12(v)   BF_CS1(CCM_CCGR6, CG12, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG13 */

#define BP_CCM_CCGR6_CG13      26
#define BM_CCM_CCGR6_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR6_CG13)
#else
#define BF_CCM_CCGR6_CG13(v)   (((v) << 26) & BM_CCM_CCGR6_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG13(v)   BF_CS1(CCM_CCGR6, CG13, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG14 */

#define BP_CCM_CCGR6_CG14      28
#define BM_CCM_CCGR6_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR6_CG14)
#else
#define BF_CCM_CCGR6_CG14(v)   (((v) << 28) & BM_CCM_CCGR6_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG14(v)   BF_CS1(CCM_CCGR6, CG14, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG15 */

#define BP_CCM_CCGR6_CG15      30
#define BM_CCM_CCGR6_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR6_CG15)
#else
#define BF_CCM_CCGR6_CG15(v)   (((v) << 30) & BM_CCM_CCGR6_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG15(v)   BF_CS1(CCM_CCGR6, CG15, v)
#endif

/*
 * HW_CCM_CCGR7 - CCM Clock Gating Register 7
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2;
        unsigned CG1 : 2;
        unsigned CG2 : 2;
        unsigned CG3 : 2;
        unsigned CG4 : 2;
        unsigned CG5 : 2;
        unsigned CG6 : 2;
        unsigned CG7 : 2;
        unsigned CG8 : 2;
        unsigned CG9 : 2;
        unsigned CG10 : 2;
        unsigned CG11 : 2;
        unsigned CG12 : 2;
        unsigned CG13 : 2;
        unsigned CG14 : 2;
        unsigned CG15 : 2;

    } B;
} hw_ccm_ccgr7_t;
#endif

/*
 * constants & macros for entire CCM_CCGR7 register
 */
#define HW_CCM_CCGR7_ADDR      (REGS_CCM_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR7           (*(volatile hw_ccm_ccgr7_t *) HW_CCM_CCGR7_ADDR)
#define HW_CCM_CCGR7_RD()      (HW_CCM_CCGR7.U)
#define HW_CCM_CCGR7_WR(v)     (HW_CCM_CCGR7.U = (v))
#define HW_CCM_CCGR7_SET(v)    (HW_CCM_CCGR7_WR(HW_CCM_CCGR7_RD() |  (v)))
#define HW_CCM_CCGR7_CLR(v)    (HW_CCM_CCGR7_WR(HW_CCM_CCGR7_RD() & ~(v)))
#define HW_CCM_CCGR7_TOG(v)    (HW_CCM_CCGR7_WR(HW_CCM_CCGR7_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR7 bitfields
 */

/* --- Register HW_CCM_CCGR7, field CG0 */

#define BP_CCM_CCGR7_CG0      0
#define BM_CCM_CCGR7_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR7_CG0)
#else
#define BF_CCM_CCGR7_CG0(v)   (((v) << 0) & BM_CCM_CCGR7_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG0(v)   BF_CS1(CCM_CCGR7, CG0, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG1 */

#define BP_CCM_CCGR7_CG1      2
#define BM_CCM_CCGR7_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR7_CG1)
#else
#define BF_CCM_CCGR7_CG1(v)   (((v) << 2) & BM_CCM_CCGR7_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG1(v)   BF_CS1(CCM_CCGR7, CG1, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG2 */

#define BP_CCM_CCGR7_CG2      4
#define BM_CCM_CCGR7_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR7_CG2)
#else
#define BF_CCM_CCGR7_CG2(v)   (((v) << 4) & BM_CCM_CCGR7_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG2(v)   BF_CS1(CCM_CCGR7, CG2, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG3 */

#define BP_CCM_CCGR7_CG3      6
#define BM_CCM_CCGR7_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR7_CG3)
#else
#define BF_CCM_CCGR7_CG3(v)   (((v) << 6) & BM_CCM_CCGR7_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG3(v)   BF_CS1(CCM_CCGR7, CG3, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG4 */

#define BP_CCM_CCGR7_CG4      8
#define BM_CCM_CCGR7_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR7_CG4)
#else
#define BF_CCM_CCGR7_CG4(v)   (((v) << 8) & BM_CCM_CCGR7_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG4(v)   BF_CS1(CCM_CCGR7, CG4, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG5 */

#define BP_CCM_CCGR7_CG5      10
#define BM_CCM_CCGR7_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR7_CG5)
#else
#define BF_CCM_CCGR7_CG5(v)   (((v) << 10) & BM_CCM_CCGR7_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG5(v)   BF_CS1(CCM_CCGR7, CG5, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG6 */

#define BP_CCM_CCGR7_CG6      12
#define BM_CCM_CCGR7_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR7_CG6)
#else
#define BF_CCM_CCGR7_CG6(v)   (((v) << 12) & BM_CCM_CCGR7_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG6(v)   BF_CS1(CCM_CCGR7, CG6, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG7 */

#define BP_CCM_CCGR7_CG7      14
#define BM_CCM_CCGR7_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR7_CG7)
#else
#define BF_CCM_CCGR7_CG7(v)   (((v) << 14) & BM_CCM_CCGR7_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG7(v)   BF_CS1(CCM_CCGR7, CG7, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG8 */

#define BP_CCM_CCGR7_CG8      16
#define BM_CCM_CCGR7_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR7_CG8)
#else
#define BF_CCM_CCGR7_CG8(v)   (((v) << 16) & BM_CCM_CCGR7_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG8(v)   BF_CS1(CCM_CCGR7, CG8, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG9 */

#define BP_CCM_CCGR7_CG9      18
#define BM_CCM_CCGR7_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR7_CG9)
#else
#define BF_CCM_CCGR7_CG9(v)   (((v) << 18) & BM_CCM_CCGR7_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG9(v)   BF_CS1(CCM_CCGR7, CG9, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG10 */

#define BP_CCM_CCGR7_CG10      20
#define BM_CCM_CCGR7_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR7_CG10)
#else
#define BF_CCM_CCGR7_CG10(v)   (((v) << 20) & BM_CCM_CCGR7_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG10(v)   BF_CS1(CCM_CCGR7, CG10, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG11 */

#define BP_CCM_CCGR7_CG11      22
#define BM_CCM_CCGR7_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR7_CG11)
#else
#define BF_CCM_CCGR7_CG11(v)   (((v) << 22) & BM_CCM_CCGR7_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG11(v)   BF_CS1(CCM_CCGR7, CG11, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG12 */

#define BP_CCM_CCGR7_CG12      24
#define BM_CCM_CCGR7_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR7_CG12)
#else
#define BF_CCM_CCGR7_CG12(v)   (((v) << 24) & BM_CCM_CCGR7_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG12(v)   BF_CS1(CCM_CCGR7, CG12, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG13 */

#define BP_CCM_CCGR7_CG13      26
#define BM_CCM_CCGR7_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR7_CG13)
#else
#define BF_CCM_CCGR7_CG13(v)   (((v) << 26) & BM_CCM_CCGR7_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG13(v)   BF_CS1(CCM_CCGR7, CG13, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG14 */

#define BP_CCM_CCGR7_CG14      28
#define BM_CCM_CCGR7_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR7_CG14)
#else
#define BF_CCM_CCGR7_CG14(v)   (((v) << 28) & BM_CCM_CCGR7_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG14(v)   BF_CS1(CCM_CCGR7, CG14, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG15 */

#define BP_CCM_CCGR7_CG15      30
#define BM_CCM_CCGR7_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR7_CG15)
#else
#define BF_CCM_CCGR7_CG15(v)   (((v) << 30) & BM_CCM_CCGR7_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG15(v)   BF_CS1(CCM_CCGR7, CG15, v)
#endif

/*
 * HW_CCM_CMEOR - CCM Module Enable Overide Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 4;
        unsigned MOD_EN_OV_VDOA : 1;
        unsigned MOD_EN_OV_GPT : 1;
        unsigned MOD_EN_OV_EPIT : 1;
        unsigned MOD_EN_USDHC : 1;
        unsigned MOD_EN_OV_DAP : 1;
        unsigned MOD_EN_OV_VPU : 1;
        unsigned MOD_EN_OV_GPU2D : 1;
        unsigned MOD_EN_OV_GPU3D : 1;
        unsigned RESERVED1 : 16;
        unsigned MOD_EN_OV_CAN2_CPI : 1;
        unsigned RESERVED2 : 1;
        unsigned MOD_EN_OV_CAN1_CPI : 1;
        unsigned RESERVED3 : 1;

    } B;
} hw_ccm_cmeor_t;
#endif

/*
 * constants & macros for entire CCM_CMEOR register
 */
#define HW_CCM_CMEOR_ADDR      (REGS_CCM_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CMEOR           (*(volatile hw_ccm_cmeor_t *) HW_CCM_CMEOR_ADDR)
#define HW_CCM_CMEOR_RD()      (HW_CCM_CMEOR.U)
#define HW_CCM_CMEOR_WR(v)     (HW_CCM_CMEOR.U = (v))
#define HW_CCM_CMEOR_SET(v)    (HW_CCM_CMEOR_WR(HW_CCM_CMEOR_RD() |  (v)))
#define HW_CCM_CMEOR_CLR(v)    (HW_CCM_CMEOR_WR(HW_CCM_CMEOR_RD() & ~(v)))
#define HW_CCM_CMEOR_TOG(v)    (HW_CCM_CMEOR_WR(HW_CCM_CMEOR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CMEOR bitfields
 */

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_VDOA */

#define BP_CCM_CMEOR_MOD_EN_OV_VDOA      4
#define BM_CCM_CMEOR_MOD_EN_OV_VDOA      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_VDOA(v)   ((((reg32_t) v) << 4) & BM_CCM_CMEOR_MOD_EN_OV_VDOA)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_VDOA(v)   (((v) << 4) & BM_CCM_CMEOR_MOD_EN_OV_VDOA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_VDOA(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_VDOA, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPT */

#define BP_CCM_CMEOR_MOD_EN_OV_GPT      5
#define BM_CCM_CMEOR_MOD_EN_OV_GPT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_GPT(v)   ((((reg32_t) v) << 5) & BM_CCM_CMEOR_MOD_EN_OV_GPT)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_GPT(v)   (((v) << 5) & BM_CCM_CMEOR_MOD_EN_OV_GPT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_GPT(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_GPT, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_EPIT */

#define BP_CCM_CMEOR_MOD_EN_OV_EPIT      6
#define BM_CCM_CMEOR_MOD_EN_OV_EPIT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_EPIT(v)   ((((reg32_t) v) << 6) & BM_CCM_CMEOR_MOD_EN_OV_EPIT)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_EPIT(v)   (((v) << 6) & BM_CCM_CMEOR_MOD_EN_OV_EPIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_EPIT(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_EPIT, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_USDHC */

#define BP_CCM_CMEOR_MOD_EN_USDHC      7
#define BM_CCM_CMEOR_MOD_EN_USDHC      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_USDHC(v)   ((((reg32_t) v) << 7) & BM_CCM_CMEOR_MOD_EN_USDHC)
#else
#define BF_CCM_CMEOR_MOD_EN_USDHC(v)   (((v) << 7) & BM_CCM_CMEOR_MOD_EN_USDHC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_USDHC(v)   BF_CS1(CCM_CMEOR, MOD_EN_USDHC, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_DAP */

#define BP_CCM_CMEOR_MOD_EN_OV_DAP      8
#define BM_CCM_CMEOR_MOD_EN_OV_DAP      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_DAP(v)   ((((reg32_t) v) << 8) & BM_CCM_CMEOR_MOD_EN_OV_DAP)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_DAP(v)   (((v) << 8) & BM_CCM_CMEOR_MOD_EN_OV_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_DAP(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_DAP, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_VPU */

#define BP_CCM_CMEOR_MOD_EN_OV_VPU      9
#define BM_CCM_CMEOR_MOD_EN_OV_VPU      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_VPU(v)   ((((reg32_t) v) << 9) & BM_CCM_CMEOR_MOD_EN_OV_VPU)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_VPU(v)   (((v) << 9) & BM_CCM_CMEOR_MOD_EN_OV_VPU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_VPU(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_VPU, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPU2D */

#define BP_CCM_CMEOR_MOD_EN_OV_GPU2D      10
#define BM_CCM_CMEOR_MOD_EN_OV_GPU2D      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   ((((reg32_t) v) << 10) & BM_CCM_CMEOR_MOD_EN_OV_GPU2D)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   (((v) << 10) & BM_CCM_CMEOR_MOD_EN_OV_GPU2D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_GPU2D, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPU3D */

#define BP_CCM_CMEOR_MOD_EN_OV_GPU3D      11
#define BM_CCM_CMEOR_MOD_EN_OV_GPU3D      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   ((((reg32_t) v) << 11) & BM_CCM_CMEOR_MOD_EN_OV_GPU3D)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   (((v) << 11) & BM_CCM_CMEOR_MOD_EN_OV_GPU3D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_GPU3D, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_CAN2_CPI */

#define BP_CCM_CMEOR_MOD_EN_OV_CAN2_CPI      28
#define BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   ((((reg32_t) v) << 28) & BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   (((v) << 28) & BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_CAN2_CPI, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_CAN1_CPI */

#define BP_CCM_CMEOR_MOD_EN_OV_CAN1_CPI      30
#define BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   ((((reg32_t) v) << 30) & BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   (((v) << 30) & BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_CAN1_CPI, v)
#endif


#endif // _CCM_H

