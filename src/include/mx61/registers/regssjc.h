/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SJC_H
#define _SJC_H

#include "regs.h"

#ifndef REGS_SJC_BASE
#define REGS_SJC_BASE (REGS_BASE + 0x00000000)

#endif


/*
 * HW_SJC_GPUSR1 - General Purpose Unsecured Status Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned A_DBG : 1;
        unsigned A_WFI : 1;
        unsigned S_STAT : 3;
        unsigned RESERVED0 : 2;
        unsigned RESERVED1 : 1;
        unsigned PLL_LOCK : 1;
        unsigned RESERVED2 : 23;

    } B;
} hw_sjc_gpusr1_t;
#endif

/*
 * constants & macros for entire SJC_GPUSR1 register
 */
#define HW_SJC_GPUSR1_ADDR      (REGS_SJC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUSR1           (*(volatile hw_sjc_gpusr1_t *) HW_SJC_GPUSR1_ADDR)
#define HW_SJC_GPUSR1_RD()      (HW_SJC_GPUSR1.U)
#define HW_SJC_GPUSR1_WR(v)     (HW_SJC_GPUSR1.U = (v))
#define HW_SJC_GPUSR1_SET(v)    (HW_SJC_GPUSR1_WR(HW_SJC_GPUSR1_RD() |  (v)))
#define HW_SJC_GPUSR1_CLR(v)    (HW_SJC_GPUSR1_WR(HW_SJC_GPUSR1_RD() & ~(v)))
#define HW_SJC_GPUSR1_TOG(v)    (HW_SJC_GPUSR1_WR(HW_SJC_GPUSR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPUSR1 bitfields
 */

/* --- Register HW_SJC_GPUSR1, field A_DBG */

#define BP_SJC_GPUSR1_A_DBG      0
#define BM_SJC_GPUSR1_A_DBG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR1_A_DBG(v)   ((((reg32_t) v) << 0) & BM_SJC_GPUSR1_A_DBG)
#else
#define BF_SJC_GPUSR1_A_DBG(v)   (((v) << 0) & BM_SJC_GPUSR1_A_DBG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR1_A_DBG(v)   BF_CS1(SJC_GPUSR1, A_DBG, v)
#endif

/* --- Register HW_SJC_GPUSR1, field A_WFI */

#define BP_SJC_GPUSR1_A_WFI      1
#define BM_SJC_GPUSR1_A_WFI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR1_A_WFI(v)   ((((reg32_t) v) << 1) & BM_SJC_GPUSR1_A_WFI)
#else
#define BF_SJC_GPUSR1_A_WFI(v)   (((v) << 1) & BM_SJC_GPUSR1_A_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR1_A_WFI(v)   BF_CS1(SJC_GPUSR1, A_WFI, v)
#endif

/* --- Register HW_SJC_GPUSR1, field S_STAT */

#define BP_SJC_GPUSR1_S_STAT      2
#define BM_SJC_GPUSR1_S_STAT      0x0000001c

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR1_S_STAT(v)   ((((reg32_t) v) << 2) & BM_SJC_GPUSR1_S_STAT)
#else
#define BF_SJC_GPUSR1_S_STAT(v)   (((v) << 2) & BM_SJC_GPUSR1_S_STAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR1_S_STAT(v)   BF_CS1(SJC_GPUSR1, S_STAT, v)
#endif

/* --- Register HW_SJC_GPUSR1, field PLL_LOCK */

#define BP_SJC_GPUSR1_PLL_LOCK      8
#define BM_SJC_GPUSR1_PLL_LOCK      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR1_PLL_LOCK(v)   ((((reg32_t) v) << 8) & BM_SJC_GPUSR1_PLL_LOCK)
#else
#define BF_SJC_GPUSR1_PLL_LOCK(v)   (((v) << 8) & BM_SJC_GPUSR1_PLL_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR1_PLL_LOCK(v)   BF_CS1(SJC_GPUSR1, PLL_LOCK, v)
#endif

/*
 * HW_SJC_GPUSR2 - General Purpose Unsecured Status Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned STBYWFI : 4;
        unsigned S_STAT : 4;
        unsigned STBYWFE : 4;
        unsigned RESERVED0 : 20;

    } B;
} hw_sjc_gpusr2_t;
#endif

/*
 * constants & macros for entire SJC_GPUSR2 register
 */
#define HW_SJC_GPUSR2_ADDR      (REGS_SJC_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUSR2           (*(volatile hw_sjc_gpusr2_t *) HW_SJC_GPUSR2_ADDR)
#define HW_SJC_GPUSR2_RD()      (HW_SJC_GPUSR2.U)
#define HW_SJC_GPUSR2_WR(v)     (HW_SJC_GPUSR2.U = (v))
#define HW_SJC_GPUSR2_SET(v)    (HW_SJC_GPUSR2_WR(HW_SJC_GPUSR2_RD() |  (v)))
#define HW_SJC_GPUSR2_CLR(v)    (HW_SJC_GPUSR2_WR(HW_SJC_GPUSR2_RD() & ~(v)))
#define HW_SJC_GPUSR2_TOG(v)    (HW_SJC_GPUSR2_WR(HW_SJC_GPUSR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPUSR2 bitfields
 */

/* --- Register HW_SJC_GPUSR2, field STBYWFI */

#define BP_SJC_GPUSR2_STBYWFI      0
#define BM_SJC_GPUSR2_STBYWFI      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR2_STBYWFI(v)   ((((reg32_t) v) << 0) & BM_SJC_GPUSR2_STBYWFI)
#else
#define BF_SJC_GPUSR2_STBYWFI(v)   (((v) << 0) & BM_SJC_GPUSR2_STBYWFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR2_STBYWFI(v)   BF_CS1(SJC_GPUSR2, STBYWFI, v)
#endif

/* --- Register HW_SJC_GPUSR2, field S_STAT */

#define BP_SJC_GPUSR2_S_STAT      4
#define BM_SJC_GPUSR2_S_STAT      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR2_S_STAT(v)   ((((reg32_t) v) << 4) & BM_SJC_GPUSR2_S_STAT)
#else
#define BF_SJC_GPUSR2_S_STAT(v)   (((v) << 4) & BM_SJC_GPUSR2_S_STAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR2_S_STAT(v)   BF_CS1(SJC_GPUSR2, S_STAT, v)
#endif

/* --- Register HW_SJC_GPUSR2, field STBYWFE */

#define BP_SJC_GPUSR2_STBYWFE      8
#define BM_SJC_GPUSR2_STBYWFE      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR2_STBYWFE(v)   ((((reg32_t) v) << 8) & BM_SJC_GPUSR2_STBYWFE)
#else
#define BF_SJC_GPUSR2_STBYWFE(v)   (((v) << 8) & BM_SJC_GPUSR2_STBYWFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR2_STBYWFE(v)   BF_CS1(SJC_GPUSR2, STBYWFE, v)
#endif

/*
 * HW_SJC_GPUSR3 - General Purpose Unsecured Status Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPG_WAIT : 1;
        unsigned IPG_STOP : 1;
        unsigned SYS_WAIT : 1;
        unsigned RESERVED0 : 29;

    } B;
} hw_sjc_gpusr3_t;
#endif

/*
 * constants & macros for entire SJC_GPUSR3 register
 */
#define HW_SJC_GPUSR3_ADDR      (REGS_SJC_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUSR3           (*(volatile hw_sjc_gpusr3_t *) HW_SJC_GPUSR3_ADDR)
#define HW_SJC_GPUSR3_RD()      (HW_SJC_GPUSR3.U)
#define HW_SJC_GPUSR3_WR(v)     (HW_SJC_GPUSR3.U = (v))
#define HW_SJC_GPUSR3_SET(v)    (HW_SJC_GPUSR3_WR(HW_SJC_GPUSR3_RD() |  (v)))
#define HW_SJC_GPUSR3_CLR(v)    (HW_SJC_GPUSR3_WR(HW_SJC_GPUSR3_RD() & ~(v)))
#define HW_SJC_GPUSR3_TOG(v)    (HW_SJC_GPUSR3_WR(HW_SJC_GPUSR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPUSR3 bitfields
 */

/* --- Register HW_SJC_GPUSR3, field IPG_WAIT */

#define BP_SJC_GPUSR3_IPG_WAIT      0
#define BM_SJC_GPUSR3_IPG_WAIT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR3_IPG_WAIT(v)   ((((reg32_t) v) << 0) & BM_SJC_GPUSR3_IPG_WAIT)
#else
#define BF_SJC_GPUSR3_IPG_WAIT(v)   (((v) << 0) & BM_SJC_GPUSR3_IPG_WAIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR3_IPG_WAIT(v)   BF_CS1(SJC_GPUSR3, IPG_WAIT, v)
#endif

/* --- Register HW_SJC_GPUSR3, field IPG_STOP */

#define BP_SJC_GPUSR3_IPG_STOP      1
#define BM_SJC_GPUSR3_IPG_STOP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR3_IPG_STOP(v)   ((((reg32_t) v) << 1) & BM_SJC_GPUSR3_IPG_STOP)
#else
#define BF_SJC_GPUSR3_IPG_STOP(v)   (((v) << 1) & BM_SJC_GPUSR3_IPG_STOP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR3_IPG_STOP(v)   BF_CS1(SJC_GPUSR3, IPG_STOP, v)
#endif

/* --- Register HW_SJC_GPUSR3, field SYS_WAIT */

#define BP_SJC_GPUSR3_SYS_WAIT      2
#define BM_SJC_GPUSR3_SYS_WAIT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR3_SYS_WAIT(v)   ((((reg32_t) v) << 2) & BM_SJC_GPUSR3_SYS_WAIT)
#else
#define BF_SJC_GPUSR3_SYS_WAIT(v)   (((v) << 2) & BM_SJC_GPUSR3_SYS_WAIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR3_SYS_WAIT(v)   BF_CS1(SJC_GPUSR3, SYS_WAIT, v)
#endif

/*
 * HW_SJC_GPSSR - General Purpose Secured Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPSSR : 32;

    } B;
} hw_sjc_gpssr_t;
#endif

/*
 * constants & macros for entire SJC_GPSSR register
 */
#define HW_SJC_GPSSR_ADDR      (REGS_SJC_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPSSR           (*(volatile hw_sjc_gpssr_t *) HW_SJC_GPSSR_ADDR)
#define HW_SJC_GPSSR_RD()      (HW_SJC_GPSSR.U)
#define HW_SJC_GPSSR_WR(v)     (HW_SJC_GPSSR.U = (v))
#define HW_SJC_GPSSR_SET(v)    (HW_SJC_GPSSR_WR(HW_SJC_GPSSR_RD() |  (v)))
#define HW_SJC_GPSSR_CLR(v)    (HW_SJC_GPSSR_WR(HW_SJC_GPSSR_RD() & ~(v)))
#define HW_SJC_GPSSR_TOG(v)    (HW_SJC_GPSSR_WR(HW_SJC_GPSSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPSSR bitfields
 */

/* --- Register HW_SJC_GPSSR, field GPSSR */

#define BP_SJC_GPSSR_GPSSR      0
#define BM_SJC_GPSSR_GPSSR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPSSR_GPSSR(v)   ((((reg32_t) v) << 0) & BM_SJC_GPSSR_GPSSR)
#else
#define BF_SJC_GPSSR_GPSSR(v)   (((v) << 0) & BM_SJC_GPSSR_GPSSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPSSR_GPSSR(v)   BF_CS1(SJC_GPSSR, GPSSR, v)
#endif

/*
 * HW_SJC_DCR - Debug Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DE_TO_ARM : 1;
        unsigned DE_TO_SDMA : 1;
        unsigned RESERVED0 : 1;
        unsigned DEBUG_OBS : 1;
        unsigned RESERVED1 : 1;
        unsigned DIRECT_SDMA_REQ_EN : 1;
        unsigned DIRECT_ARM_REQ_EN : 1;
        unsigned RESERVED2 : 25;

    } B;
} hw_sjc_dcr_t;
#endif

/*
 * constants & macros for entire SJC_DCR register
 */
#define HW_SJC_DCR_ADDR      (REGS_SJC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_DCR           (*(volatile hw_sjc_dcr_t *) HW_SJC_DCR_ADDR)
#define HW_SJC_DCR_RD()      (HW_SJC_DCR.U)
#define HW_SJC_DCR_WR(v)     (HW_SJC_DCR.U = (v))
#define HW_SJC_DCR_SET(v)    (HW_SJC_DCR_WR(HW_SJC_DCR_RD() |  (v)))
#define HW_SJC_DCR_CLR(v)    (HW_SJC_DCR_WR(HW_SJC_DCR_RD() & ~(v)))
#define HW_SJC_DCR_TOG(v)    (HW_SJC_DCR_WR(HW_SJC_DCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_DCR bitfields
 */

/* --- Register HW_SJC_DCR, field DE_TO_ARM */

#define BP_SJC_DCR_DE_TO_ARM      0
#define BM_SJC_DCR_DE_TO_ARM      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DE_TO_ARM(v)   ((((reg32_t) v) << 0) & BM_SJC_DCR_DE_TO_ARM)
#else
#define BF_SJC_DCR_DE_TO_ARM(v)   (((v) << 0) & BM_SJC_DCR_DE_TO_ARM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DE_TO_ARM(v)   BF_CS1(SJC_DCR, DE_TO_ARM, v)
#endif

/* --- Register HW_SJC_DCR, field DE_TO_SDMA */

#define BP_SJC_DCR_DE_TO_SDMA      1
#define BM_SJC_DCR_DE_TO_SDMA      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DE_TO_SDMA(v)   ((((reg32_t) v) << 1) & BM_SJC_DCR_DE_TO_SDMA)
#else
#define BF_SJC_DCR_DE_TO_SDMA(v)   (((v) << 1) & BM_SJC_DCR_DE_TO_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DE_TO_SDMA(v)   BF_CS1(SJC_DCR, DE_TO_SDMA, v)
#endif

/* --- Register HW_SJC_DCR, field DEBUG_OBS */

#define BP_SJC_DCR_DEBUG_OBS      3
#define BM_SJC_DCR_DEBUG_OBS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DEBUG_OBS(v)   ((((reg32_t) v) << 3) & BM_SJC_DCR_DEBUG_OBS)
#else
#define BF_SJC_DCR_DEBUG_OBS(v)   (((v) << 3) & BM_SJC_DCR_DEBUG_OBS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DEBUG_OBS(v)   BF_CS1(SJC_DCR, DEBUG_OBS, v)
#endif

/* --- Register HW_SJC_DCR, field DIRECT_SDMA_REQ_EN */

#define BP_SJC_DCR_DIRECT_SDMA_REQ_EN      5
#define BM_SJC_DCR_DIRECT_SDMA_REQ_EN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   ((((reg32_t) v) << 5) & BM_SJC_DCR_DIRECT_SDMA_REQ_EN)
#else
#define BF_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   (((v) << 5) & BM_SJC_DCR_DIRECT_SDMA_REQ_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   BF_CS1(SJC_DCR, DIRECT_SDMA_REQ_EN, v)
#endif

/* --- Register HW_SJC_DCR, field DIRECT_ARM_REQ_EN */

#define BP_SJC_DCR_DIRECT_ARM_REQ_EN      6
#define BM_SJC_DCR_DIRECT_ARM_REQ_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DIRECT_ARM_REQ_EN(v)   ((((reg32_t) v) << 6) & BM_SJC_DCR_DIRECT_ARM_REQ_EN)
#else
#define BF_SJC_DCR_DIRECT_ARM_REQ_EN(v)   (((v) << 6) & BM_SJC_DCR_DIRECT_ARM_REQ_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DIRECT_ARM_REQ_EN(v)   BF_CS1(SJC_DCR, DIRECT_ARM_REQ_EN, v)
#endif

/*
 * HW_SJC_SSR - Security Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned KTF : 1;
        unsigned KTA : 1;
        unsigned SWF : 1;
        unsigned SWE : 1;
        unsigned EBF : 1;
        unsigned EBG : 1;
        unsigned RESERVED0 : 1;
        unsigned RESERVED1 : 1;
        unsigned FT : 1;
        unsigned SJM : 2;
        unsigned RSSTAT : 2;
        unsigned SECBLK : 1;
        unsigned RESERVED2 : 1;
        unsigned BOOTIND : 1;
        unsigned RESERVED3 : 2;
        unsigned RESERVED4 : 1;
        unsigned F_LATCH : 1;
        unsigned RESERVED5 : 15;

    } B;
} hw_sjc_ssr_t;
#endif

/*
 * constants & macros for entire SJC_SSR register
 */
#define HW_SJC_SSR_ADDR      (REGS_SJC_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_SSR           (*(volatile hw_sjc_ssr_t *) HW_SJC_SSR_ADDR)
#define HW_SJC_SSR_RD()      (HW_SJC_SSR.U)
#define HW_SJC_SSR_WR(v)     (HW_SJC_SSR.U = (v))
#define HW_SJC_SSR_SET(v)    (HW_SJC_SSR_WR(HW_SJC_SSR_RD() |  (v)))
#define HW_SJC_SSR_CLR(v)    (HW_SJC_SSR_WR(HW_SJC_SSR_RD() & ~(v)))
#define HW_SJC_SSR_TOG(v)    (HW_SJC_SSR_WR(HW_SJC_SSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_SSR bitfields
 */

/* --- Register HW_SJC_SSR, field KTF */

#define BP_SJC_SSR_KTF      0
#define BM_SJC_SSR_KTF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_KTF(v)   ((((reg32_t) v) << 0) & BM_SJC_SSR_KTF)
#else
#define BF_SJC_SSR_KTF(v)   (((v) << 0) & BM_SJC_SSR_KTF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_KTF(v)   BF_CS1(SJC_SSR, KTF, v)
#endif

/* --- Register HW_SJC_SSR, field KTA */

#define BP_SJC_SSR_KTA      1
#define BM_SJC_SSR_KTA      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_KTA(v)   ((((reg32_t) v) << 1) & BM_SJC_SSR_KTA)
#else
#define BF_SJC_SSR_KTA(v)   (((v) << 1) & BM_SJC_SSR_KTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_KTA(v)   BF_CS1(SJC_SSR, KTA, v)
#endif

/* --- Register HW_SJC_SSR, field SWF */

#define BP_SJC_SSR_SWF      2
#define BM_SJC_SSR_SWF      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_SWF(v)   ((((reg32_t) v) << 2) & BM_SJC_SSR_SWF)
#else
#define BF_SJC_SSR_SWF(v)   (((v) << 2) & BM_SJC_SSR_SWF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_SWF(v)   BF_CS1(SJC_SSR, SWF, v)
#endif

/* --- Register HW_SJC_SSR, field SWE */

#define BP_SJC_SSR_SWE      3
#define BM_SJC_SSR_SWE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_SWE(v)   ((((reg32_t) v) << 3) & BM_SJC_SSR_SWE)
#else
#define BF_SJC_SSR_SWE(v)   (((v) << 3) & BM_SJC_SSR_SWE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_SWE(v)   BF_CS1(SJC_SSR, SWE, v)
#endif

/* --- Register HW_SJC_SSR, field EBF */

#define BP_SJC_SSR_EBF      4
#define BM_SJC_SSR_EBF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_EBF(v)   ((((reg32_t) v) << 4) & BM_SJC_SSR_EBF)
#else
#define BF_SJC_SSR_EBF(v)   (((v) << 4) & BM_SJC_SSR_EBF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_EBF(v)   BF_CS1(SJC_SSR, EBF, v)
#endif

/* --- Register HW_SJC_SSR, field EBG */

#define BP_SJC_SSR_EBG      5
#define BM_SJC_SSR_EBG      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_EBG(v)   ((((reg32_t) v) << 5) & BM_SJC_SSR_EBG)
#else
#define BF_SJC_SSR_EBG(v)   (((v) << 5) & BM_SJC_SSR_EBG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_EBG(v)   BF_CS1(SJC_SSR, EBG, v)
#endif

/* --- Register HW_SJC_SSR, field FT */

#define BP_SJC_SSR_FT      8
#define BM_SJC_SSR_FT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_FT(v)   ((((reg32_t) v) << 8) & BM_SJC_SSR_FT)
#else
#define BF_SJC_SSR_FT(v)   (((v) << 8) & BM_SJC_SSR_FT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_FT(v)   BF_CS1(SJC_SSR, FT, v)
#endif

/* --- Register HW_SJC_SSR, field SJM */

#define BP_SJC_SSR_SJM      9
#define BM_SJC_SSR_SJM      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_SJM(v)   ((((reg32_t) v) << 9) & BM_SJC_SSR_SJM)
#else
#define BF_SJC_SSR_SJM(v)   (((v) << 9) & BM_SJC_SSR_SJM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_SJM(v)   BF_CS1(SJC_SSR, SJM, v)
#endif

/* --- Register HW_SJC_SSR, field RSSTAT */

#define BP_SJC_SSR_RSSTAT      11
#define BM_SJC_SSR_RSSTAT      0x00001800

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_RSSTAT(v)   ((((reg32_t) v) << 11) & BM_SJC_SSR_RSSTAT)
#else
#define BF_SJC_SSR_RSSTAT(v)   (((v) << 11) & BM_SJC_SSR_RSSTAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_RSSTAT(v)   BF_CS1(SJC_SSR, RSSTAT, v)
#endif

/* --- Register HW_SJC_SSR, field SECBLK */

#define BP_SJC_SSR_SECBLK      13
#define BM_SJC_SSR_SECBLK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_SECBLK(v)   ((((reg32_t) v) << 13) & BM_SJC_SSR_SECBLK)
#else
#define BF_SJC_SSR_SECBLK(v)   (((v) << 13) & BM_SJC_SSR_SECBLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_SECBLK(v)   BF_CS1(SJC_SSR, SECBLK, v)
#endif

/* --- Register HW_SJC_SSR, field BOOTIND */

#define BP_SJC_SSR_BOOTIND      14
#define BM_SJC_SSR_BOOTIND      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_BOOTIND(v)   ((((reg32_t) v) << 14) & BM_SJC_SSR_BOOTIND)
#else
#define BF_SJC_SSR_BOOTIND(v)   (((v) << 14) & BM_SJC_SSR_BOOTIND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_BOOTIND(v)   BF_CS1(SJC_SSR, BOOTIND, v)
#endif

/* --- Register HW_SJC_SSR, field F_LATCH */

#define BP_SJC_SSR_F_LATCH      16
#define BM_SJC_SSR_F_LATCH      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_F_LATCH(v)   ((((reg32_t) v) << 16) & BM_SJC_SSR_F_LATCH)
#else
#define BF_SJC_SSR_F_LATCH(v)   (((v) << 16) & BM_SJC_SSR_F_LATCH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_F_LATCH(v)   BF_CS1(SJC_SSR, F_LATCH, v)
#endif

/*
 * HW_SJC_CPCR - Charge Pump Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CPCR : 32;

    } B;
} hw_sjc_cpcr_t;
#endif

/*
 * constants & macros for entire SJC_CPCR register
 */
#define HW_SJC_CPCR_ADDR      (REGS_SJC_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_CPCR           (*(volatile hw_sjc_cpcr_t *) HW_SJC_CPCR_ADDR)
#define HW_SJC_CPCR_RD()      (HW_SJC_CPCR.U)
#define HW_SJC_CPCR_WR(v)     (HW_SJC_CPCR.U = (v))
#define HW_SJC_CPCR_SET(v)    (HW_SJC_CPCR_WR(HW_SJC_CPCR_RD() |  (v)))
#define HW_SJC_CPCR_CLR(v)    (HW_SJC_CPCR_WR(HW_SJC_CPCR_RD() & ~(v)))
#define HW_SJC_CPCR_TOG(v)    (HW_SJC_CPCR_WR(HW_SJC_CPCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_CPCR bitfields
 */

/* --- Register HW_SJC_CPCR, field CPCR */

#define BP_SJC_CPCR_CPCR      0
#define BM_SJC_CPCR_CPCR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_CPCR_CPCR(v)   ((((reg32_t) v) << 0) & BM_SJC_CPCR_CPCR)
#else
#define BF_SJC_CPCR_CPCR(v)   (((v) << 0) & BM_SJC_CPCR_CPCR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_CPCR_CPCR(v)   BF_CS1(SJC_CPCR, CPCR, v)
#endif

/*
 * HW_SJC_GPCCR - General Purpose Clocks Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;

    } B;
} hw_sjc_gpccr_t;
#endif

/*
 * constants & macros for entire SJC_GPCCR register
 */
#define HW_SJC_GPCCR_ADDR      (REGS_SJC_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPCCR           (*(volatile hw_sjc_gpccr_t *) HW_SJC_GPCCR_ADDR)
#define HW_SJC_GPCCR_RD()      (HW_SJC_GPCCR.U)
#define HW_SJC_GPCCR_WR(v)     (HW_SJC_GPCCR.U = (v))
#define HW_SJC_GPCCR_SET(v)    (HW_SJC_GPCCR_WR(HW_SJC_GPCCR_RD() |  (v)))
#define HW_SJC_GPCCR_CLR(v)    (HW_SJC_GPCCR_WR(HW_SJC_GPCCR_RD() & ~(v)))
#define HW_SJC_GPCCR_TOG(v)    (HW_SJC_GPCCR_WR(HW_SJC_GPCCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPCCR bitfields
 */

/*
 * HW_SJC_PLLBR - PLL Bypass Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {

    } B;
} hw_sjc_pllbr_t;
#endif

/*
 * constants & macros for entire SJC_PLLBR register
 */
#define HW_SJC_PLLBR_ADDR      (REGS_SJC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_PLLBR           (*(volatile hw_sjc_pllbr_t *) HW_SJC_PLLBR_ADDR)
#define HW_SJC_PLLBR_RD()      (HW_SJC_PLLBR.U)
#define HW_SJC_PLLBR_WR(v)     (HW_SJC_PLLBR.U = (v))
#define HW_SJC_PLLBR_SET(v)    (HW_SJC_PLLBR_WR(HW_SJC_PLLBR_RD() |  (v)))
#define HW_SJC_PLLBR_CLR(v)    (HW_SJC_PLLBR_WR(HW_SJC_PLLBR_RD() & ~(v)))
#define HW_SJC_PLLBR_TOG(v)    (HW_SJC_PLLBR_WR(HW_SJC_PLLBR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_PLLBR bitfields
 */

/*
 * HW_SJC_GPUCR - General Purpose Unsecured Control Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_sjc_gpucr_t;
#endif

/*
 * constants & macros for entire SJC_GPUCR register
 */
#define HW_SJC_GPUCR_ADDR      (REGS_SJC_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUCR           (*(volatile hw_sjc_gpucr_t *) HW_SJC_GPUCR_ADDR)
#define HW_SJC_GPUCR_RD()      (HW_SJC_GPUCR.U)
#define HW_SJC_GPUCR_WR(v)     (HW_SJC_GPUCR.U = (v))
#define HW_SJC_GPUCR_SET(v)    (HW_SJC_GPUCR_WR(HW_SJC_GPUCR_RD() |  (v)))
#define HW_SJC_GPUCR_CLR(v)    (HW_SJC_GPUCR_WR(HW_SJC_GPUCR_RD() & ~(v)))
#define HW_SJC_GPUCR_TOG(v)    (HW_SJC_GPUCR_WR(HW_SJC_GPUCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPUCR bitfields
 */

/*
 * HW_SJC_GPSCR - General Purpose Secured Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_sjc_gpscr_t;
#endif

/*
 * constants & macros for entire SJC_GPSCR register
 */
#define HW_SJC_GPSCR_ADDR      (REGS_SJC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPSCR           (*(volatile hw_sjc_gpscr_t *) HW_SJC_GPSCR_ADDR)
#define HW_SJC_GPSCR_RD()      (HW_SJC_GPSCR.U)
#define HW_SJC_GPSCR_WR(v)     (HW_SJC_GPSCR.U = (v))
#define HW_SJC_GPSCR_SET(v)    (HW_SJC_GPSCR_WR(HW_SJC_GPSCR_RD() |  (v)))
#define HW_SJC_GPSCR_CLR(v)    (HW_SJC_GPSCR_WR(HW_SJC_GPSCR_RD() & ~(v)))
#define HW_SJC_GPSCR_TOG(v)    (HW_SJC_GPSCR_WR(HW_SJC_GPSCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPSCR bitfields
 */

/*
 * HW_SJC_TESTREG - Test Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short TESTREG : 16;

    } B;
} hw_sjc_testreg_t;
#endif

/*
 * constants & macros for entire SJC_TESTREG register
 */
#define HW_SJC_TESTREG_ADDR      (REGS_SJC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_TESTREG           (*(volatile hw_sjc_testreg_t *) HW_SJC_TESTREG_ADDR)
#define HW_SJC_TESTREG_RD()      (HW_SJC_TESTREG.U)
#define HW_SJC_TESTREG_WR(v)     (HW_SJC_TESTREG.U = (v))
#define HW_SJC_TESTREG_SET(v)    (HW_SJC_TESTREG_WR(HW_SJC_TESTREG_RD() |  (v)))
#define HW_SJC_TESTREG_CLR(v)    (HW_SJC_TESTREG_WR(HW_SJC_TESTREG_RD() & ~(v)))
#define HW_SJC_TESTREG_TOG(v)    (HW_SJC_TESTREG_WR(HW_SJC_TESTREG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_TESTREG bitfields
 */

/* --- Register HW_SJC_TESTREG, field TESTREG */

#define BP_SJC_TESTREG_TESTREG      0
#define BM_SJC_TESTREG_TESTREG      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_TESTREG_TESTREG(v)   ((((reg32_t) v) << 0) & BM_SJC_TESTREG_TESTREG)
#else
#define BF_SJC_TESTREG_TESTREG(v)   (((v) << 0) & BM_SJC_TESTREG_TESTREG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_TESTREG_TESTREG(v)   BF_CS1(SJC_TESTREG, TESTREG, v)
#endif

/*
 * HW_SJC_SASR - Serial Access Select Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SASR : 6;
        unsigned short RESERVED0 : 10;

    } B;
} hw_sjc_sasr_t;
#endif

/*
 * constants & macros for entire SJC_SASR register
 */
#define HW_SJC_SASR_ADDR      (REGS_SJC_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_SASR           (*(volatile hw_sjc_sasr_t *) HW_SJC_SASR_ADDR)
#define HW_SJC_SASR_RD()      (HW_SJC_SASR.U)
#define HW_SJC_SASR_WR(v)     (HW_SJC_SASR.U = (v))
#define HW_SJC_SASR_SET(v)    (HW_SJC_SASR_WR(HW_SJC_SASR_RD() |  (v)))
#define HW_SJC_SASR_CLR(v)    (HW_SJC_SASR_WR(HW_SJC_SASR_RD() & ~(v)))
#define HW_SJC_SASR_TOG(v)    (HW_SJC_SASR_WR(HW_SJC_SASR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_SASR bitfields
 */

/* --- Register HW_SJC_SASR, field SASR */

#define BP_SJC_SASR_SASR      0
#define BM_SJC_SASR_SASR      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SASR_SASR(v)   ((((reg32_t) v) << 0) & BM_SJC_SASR_SASR)
#else
#define BF_SJC_SASR_SASR(v)   (((v) << 0) & BM_SJC_SASR_SASR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SASR_SASR(v)   BF_CS1(SJC_SASR, SASR, v)
#endif

/*
 * HW_SJC_BISTCR1 - BIST Configuration Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RELEASE_EN : 1;
        unsigned INVOKE : 1;
        unsigned BIST_SELECT : 10;
        unsigned BCR : 20;

    } B;
} hw_sjc_bistcr1_t;
#endif

/*
 * constants & macros for entire SJC_BISTCR1 register
 */
#define HW_SJC_BISTCR1_ADDR      (REGS_SJC_BASE + 0xe)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_BISTCR1           (*(volatile hw_sjc_bistcr1_t *) HW_SJC_BISTCR1_ADDR)
#define HW_SJC_BISTCR1_RD()      (HW_SJC_BISTCR1.U)
#define HW_SJC_BISTCR1_WR(v)     (HW_SJC_BISTCR1.U = (v))
#define HW_SJC_BISTCR1_SET(v)    (HW_SJC_BISTCR1_WR(HW_SJC_BISTCR1_RD() |  (v)))
#define HW_SJC_BISTCR1_CLR(v)    (HW_SJC_BISTCR1_WR(HW_SJC_BISTCR1_RD() & ~(v)))
#define HW_SJC_BISTCR1_TOG(v)    (HW_SJC_BISTCR1_WR(HW_SJC_BISTCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_BISTCR1 bitfields
 */

/* --- Register HW_SJC_BISTCR1, field RELEASE_EN */

#define BP_SJC_BISTCR1_RELEASE_EN      0
#define BM_SJC_BISTCR1_RELEASE_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR1_RELEASE_EN(v)   ((((reg32_t) v) << 0) & BM_SJC_BISTCR1_RELEASE_EN)
#else
#define BF_SJC_BISTCR1_RELEASE_EN(v)   (((v) << 0) & BM_SJC_BISTCR1_RELEASE_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR1_RELEASE_EN(v)   BF_CS1(SJC_BISTCR1, RELEASE_EN, v)
#endif

/* --- Register HW_SJC_BISTCR1, field INVOKE */

#define BP_SJC_BISTCR1_INVOKE      1
#define BM_SJC_BISTCR1_INVOKE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR1_INVOKE(v)   ((((reg32_t) v) << 1) & BM_SJC_BISTCR1_INVOKE)
#else
#define BF_SJC_BISTCR1_INVOKE(v)   (((v) << 1) & BM_SJC_BISTCR1_INVOKE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR1_INVOKE(v)   BF_CS1(SJC_BISTCR1, INVOKE, v)
#endif

/* --- Register HW_SJC_BISTCR1, field BIST_SELECT */

#define BP_SJC_BISTCR1_BIST_SELECT      2
#define BM_SJC_BISTCR1_BIST_SELECT      0x00000ffc

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR1_BIST_SELECT(v)   ((((reg32_t) v) << 2) & BM_SJC_BISTCR1_BIST_SELECT)
#else
#define BF_SJC_BISTCR1_BIST_SELECT(v)   (((v) << 2) & BM_SJC_BISTCR1_BIST_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR1_BIST_SELECT(v)   BF_CS1(SJC_BISTCR1, BIST_SELECT, v)
#endif

/* --- Register HW_SJC_BISTCR1, field BCR */

#define BP_SJC_BISTCR1_BCR      12
#define BM_SJC_BISTCR1_BCR      0xfffff000

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR1_BCR(v)   ((((reg32_t) v) << 12) & BM_SJC_BISTCR1_BCR)
#else
#define BF_SJC_BISTCR1_BCR(v)   (((v) << 12) & BM_SJC_BISTCR1_BCR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR1_BCR(v)   BF_CS1(SJC_BISTCR1, BCR, v)
#endif

/*
 * HW_SJC_BISTCR3 - BIST Configuration Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RELEASE_EN : 1;
        unsigned SELECT : 2;
        unsigned BCR3 : 29;

    } B;
} hw_sjc_bistcr3_t;
#endif

/*
 * constants & macros for entire SJC_BISTCR3 register
 */
#define HW_SJC_BISTCR3_ADDR      (REGS_SJC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_BISTCR3           (*(volatile hw_sjc_bistcr3_t *) HW_SJC_BISTCR3_ADDR)
#define HW_SJC_BISTCR3_RD()      (HW_SJC_BISTCR3.U)
#define HW_SJC_BISTCR3_WR(v)     (HW_SJC_BISTCR3.U = (v))
#define HW_SJC_BISTCR3_SET(v)    (HW_SJC_BISTCR3_WR(HW_SJC_BISTCR3_RD() |  (v)))
#define HW_SJC_BISTCR3_CLR(v)    (HW_SJC_BISTCR3_WR(HW_SJC_BISTCR3_RD() & ~(v)))
#define HW_SJC_BISTCR3_TOG(v)    (HW_SJC_BISTCR3_WR(HW_SJC_BISTCR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_BISTCR3 bitfields
 */

/* --- Register HW_SJC_BISTCR3, field RELEASE_EN */

#define BP_SJC_BISTCR3_RELEASE_EN      0
#define BM_SJC_BISTCR3_RELEASE_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR3_RELEASE_EN(v)   ((((reg32_t) v) << 0) & BM_SJC_BISTCR3_RELEASE_EN)
#else
#define BF_SJC_BISTCR3_RELEASE_EN(v)   (((v) << 0) & BM_SJC_BISTCR3_RELEASE_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR3_RELEASE_EN(v)   BF_CS1(SJC_BISTCR3, RELEASE_EN, v)
#endif

/* --- Register HW_SJC_BISTCR3, field SELECT */

#define BP_SJC_BISTCR3_SELECT      1
#define BM_SJC_BISTCR3_SELECT      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR3_SELECT(v)   ((((reg32_t) v) << 1) & BM_SJC_BISTCR3_SELECT)
#else
#define BF_SJC_BISTCR3_SELECT(v)   (((v) << 1) & BM_SJC_BISTCR3_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR3_SELECT(v)   BF_CS1(SJC_BISTCR3, SELECT, v)
#endif

/* --- Register HW_SJC_BISTCR3, field BCR3 */

#define BP_SJC_BISTCR3_BCR3      3
#define BM_SJC_BISTCR3_BCR3      0xfffffff8

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR3_BCR3(v)   ((((reg32_t) v) << 3) & BM_SJC_BISTCR3_BCR3)
#else
#define BF_SJC_BISTCR3_BCR3(v)   (((v) << 3) & BM_SJC_BISTCR3_BCR3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR3_BCR3(v)   BF_CS1(SJC_BISTCR3, BCR3, v)
#endif

/*
 * HW_SJC_BISTCR4 - BIST Configuration Register 4
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RELEASE_EN : 1;
        unsigned BCR4 : 31;

    } B;
} hw_sjc_bistcr4_t;
#endif

/*
 * constants & macros for entire SJC_BISTCR4 register
 */
#define HW_SJC_BISTCR4_ADDR      (REGS_SJC_BASE + 0x11)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_BISTCR4           (*(volatile hw_sjc_bistcr4_t *) HW_SJC_BISTCR4_ADDR)
#define HW_SJC_BISTCR4_RD()      (HW_SJC_BISTCR4.U)
#define HW_SJC_BISTCR4_WR(v)     (HW_SJC_BISTCR4.U = (v))
#define HW_SJC_BISTCR4_SET(v)    (HW_SJC_BISTCR4_WR(HW_SJC_BISTCR4_RD() |  (v)))
#define HW_SJC_BISTCR4_CLR(v)    (HW_SJC_BISTCR4_WR(HW_SJC_BISTCR4_RD() & ~(v)))
#define HW_SJC_BISTCR4_TOG(v)    (HW_SJC_BISTCR4_WR(HW_SJC_BISTCR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_BISTCR4 bitfields
 */

/* --- Register HW_SJC_BISTCR4, field RELEASE_EN */

#define BP_SJC_BISTCR4_RELEASE_EN      0
#define BM_SJC_BISTCR4_RELEASE_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR4_RELEASE_EN(v)   ((((reg32_t) v) << 0) & BM_SJC_BISTCR4_RELEASE_EN)
#else
#define BF_SJC_BISTCR4_RELEASE_EN(v)   (((v) << 0) & BM_SJC_BISTCR4_RELEASE_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR4_RELEASE_EN(v)   BF_CS1(SJC_BISTCR4, RELEASE_EN, v)
#endif

/* --- Register HW_SJC_BISTCR4, field BCR4 */

#define BP_SJC_BISTCR4_BCR4      1
#define BM_SJC_BISTCR4_BCR4      0xfffffffe

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTCR4_BCR4(v)   ((((reg32_t) v) << 1) & BM_SJC_BISTCR4_BCR4)
#else
#define BF_SJC_BISTCR4_BCR4(v)   (((v) << 1) & BM_SJC_BISTCR4_BCR4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTCR4_BCR4(v)   BF_CS1(SJC_BISTCR4, BCR4, v)
#endif

/*
 * HW_SJC_MBISTPASSR1 - Memory BIST Pass-Fail Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MBISTPASSR : 32;

    } B;
} hw_sjc_mbistpassr1_t;
#endif

/*
 * constants & macros for entire SJC_MBISTPASSR1 register
 */
#define HW_SJC_MBISTPASSR1_ADDR      (REGS_SJC_BASE + 0x15)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_MBISTPASSR1           (*(volatile hw_sjc_mbistpassr1_t *) HW_SJC_MBISTPASSR1_ADDR)
#define HW_SJC_MBISTPASSR1_RD()      (HW_SJC_MBISTPASSR1.U)
#define HW_SJC_MBISTPASSR1_WR(v)     (HW_SJC_MBISTPASSR1.U = (v))
#define HW_SJC_MBISTPASSR1_SET(v)    (HW_SJC_MBISTPASSR1_WR(HW_SJC_MBISTPASSR1_RD() |  (v)))
#define HW_SJC_MBISTPASSR1_CLR(v)    (HW_SJC_MBISTPASSR1_WR(HW_SJC_MBISTPASSR1_RD() & ~(v)))
#define HW_SJC_MBISTPASSR1_TOG(v)    (HW_SJC_MBISTPASSR1_WR(HW_SJC_MBISTPASSR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_MBISTPASSR1 bitfields
 */

/* --- Register HW_SJC_MBISTPASSR1, field MBISTPASSR */

#define BP_SJC_MBISTPASSR1_MBISTPASSR      0
#define BM_SJC_MBISTPASSR1_MBISTPASSR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_MBISTPASSR1_MBISTPASSR(v)   ((((reg32_t) v) << 0) & BM_SJC_MBISTPASSR1_MBISTPASSR)
#else
#define BF_SJC_MBISTPASSR1_MBISTPASSR(v)   (((v) << 0) & BM_SJC_MBISTPASSR1_MBISTPASSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_MBISTPASSR1_MBISTPASSR(v)   BF_CS1(SJC_MBISTPASSR1, MBISTPASSR, v)
#endif

/*
 * HW_SJC_MBISTDONER1 - Memory BIST Done Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MBISTDONER1 : 32;

    } B;
} hw_sjc_mbistdoner1_t;
#endif

/*
 * constants & macros for entire SJC_MBISTDONER1 register
 */
#define HW_SJC_MBISTDONER1_ADDR      (REGS_SJC_BASE + 0x17)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_MBISTDONER1           (*(volatile hw_sjc_mbistdoner1_t *) HW_SJC_MBISTDONER1_ADDR)
#define HW_SJC_MBISTDONER1_RD()      (HW_SJC_MBISTDONER1.U)
#define HW_SJC_MBISTDONER1_WR(v)     (HW_SJC_MBISTDONER1.U = (v))
#define HW_SJC_MBISTDONER1_SET(v)    (HW_SJC_MBISTDONER1_WR(HW_SJC_MBISTDONER1_RD() |  (v)))
#define HW_SJC_MBISTDONER1_CLR(v)    (HW_SJC_MBISTDONER1_WR(HW_SJC_MBISTDONER1_RD() & ~(v)))
#define HW_SJC_MBISTDONER1_TOG(v)    (HW_SJC_MBISTDONER1_WR(HW_SJC_MBISTDONER1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_MBISTDONER1 bitfields
 */

/* --- Register HW_SJC_MBISTDONER1, field MBISTDONER1 */

#define BP_SJC_MBISTDONER1_MBISTDONER1      0
#define BM_SJC_MBISTDONER1_MBISTDONER1      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_MBISTDONER1_MBISTDONER1(v)   ((((reg32_t) v) << 0) & BM_SJC_MBISTDONER1_MBISTDONER1)
#else
#define BF_SJC_MBISTDONER1_MBISTDONER1(v)   (((v) << 0) & BM_SJC_MBISTDONER1_MBISTDONER1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_MBISTDONER1_MBISTDONER1(v)   BF_CS1(SJC_MBISTDONER1, MBISTDONER1, v)
#endif

/*
 * HW_SJC_MBISTMASRR1 - Memory BIST Mask Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MBISTMASKR1 : 32;

    } B;
} hw_sjc_mbistmasrr1_t;
#endif

/*
 * constants & macros for entire SJC_MBISTMASRR1 register
 */
#define HW_SJC_MBISTMASRR1_ADDR      (REGS_SJC_BASE + 0x19)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_MBISTMASRR1           (*(volatile hw_sjc_mbistmasrr1_t *) HW_SJC_MBISTMASRR1_ADDR)
#define HW_SJC_MBISTMASRR1_RD()      (HW_SJC_MBISTMASRR1.U)
#define HW_SJC_MBISTMASRR1_WR(v)     (HW_SJC_MBISTMASRR1.U = (v))
#define HW_SJC_MBISTMASRR1_SET(v)    (HW_SJC_MBISTMASRR1_WR(HW_SJC_MBISTMASRR1_RD() |  (v)))
#define HW_SJC_MBISTMASRR1_CLR(v)    (HW_SJC_MBISTMASRR1_WR(HW_SJC_MBISTMASRR1_RD() & ~(v)))
#define HW_SJC_MBISTMASRR1_TOG(v)    (HW_SJC_MBISTMASRR1_WR(HW_SJC_MBISTMASRR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_MBISTMASRR1 bitfields
 */

/* --- Register HW_SJC_MBISTMASRR1, field MBISTMASKR1 */

#define BP_SJC_MBISTMASRR1_MBISTMASKR1      0
#define BM_SJC_MBISTMASRR1_MBISTMASKR1      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_MBISTMASRR1_MBISTMASKR1(v)   ((((reg32_t) v) << 0) & BM_SJC_MBISTMASRR1_MBISTMASKR1)
#else
#define BF_SJC_MBISTMASRR1_MBISTMASKR1(v)   (((v) << 0) & BM_SJC_MBISTMASRR1_MBISTMASKR1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_MBISTMASRR1_MBISTMASKR1(v)   BF_CS1(SJC_MBISTMASRR1, MBISTMASKR1, v)
#endif

/*
 * HW_SJC_BISTPASSR - BIST Pass-Fail Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BISTPASSR : 32;

    } B;
} hw_sjc_bistpassr_t;
#endif

/*
 * constants & macros for entire SJC_BISTPASSR register
 */
#define HW_SJC_BISTPASSR_ADDR      (REGS_SJC_BASE + 0x21)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_BISTPASSR           (*(volatile hw_sjc_bistpassr_t *) HW_SJC_BISTPASSR_ADDR)
#define HW_SJC_BISTPASSR_RD()      (HW_SJC_BISTPASSR.U)
#define HW_SJC_BISTPASSR_WR(v)     (HW_SJC_BISTPASSR.U = (v))
#define HW_SJC_BISTPASSR_SET(v)    (HW_SJC_BISTPASSR_WR(HW_SJC_BISTPASSR_RD() |  (v)))
#define HW_SJC_BISTPASSR_CLR(v)    (HW_SJC_BISTPASSR_WR(HW_SJC_BISTPASSR_RD() & ~(v)))
#define HW_SJC_BISTPASSR_TOG(v)    (HW_SJC_BISTPASSR_WR(HW_SJC_BISTPASSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_BISTPASSR bitfields
 */

/* --- Register HW_SJC_BISTPASSR, field BISTPASSR */

#define BP_SJC_BISTPASSR_BISTPASSR      0
#define BM_SJC_BISTPASSR_BISTPASSR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTPASSR_BISTPASSR(v)   ((((reg32_t) v) << 0) & BM_SJC_BISTPASSR_BISTPASSR)
#else
#define BF_SJC_BISTPASSR_BISTPASSR(v)   (((v) << 0) & BM_SJC_BISTPASSR_BISTPASSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTPASSR_BISTPASSR(v)   BF_CS1(SJC_BISTPASSR, BISTPASSR, v)
#endif

/*
 * HW_SJC_BISTDONER - BIST DOne Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BISTDONER : 32;

    } B;
} hw_sjc_bistdoner_t;
#endif

/*
 * constants & macros for entire SJC_BISTDONER register
 */
#define HW_SJC_BISTDONER_ADDR      (REGS_SJC_BASE + 0x22)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_BISTDONER           (*(volatile hw_sjc_bistdoner_t *) HW_SJC_BISTDONER_ADDR)
#define HW_SJC_BISTDONER_RD()      (HW_SJC_BISTDONER.U)
#define HW_SJC_BISTDONER_WR(v)     (HW_SJC_BISTDONER.U = (v))
#define HW_SJC_BISTDONER_SET(v)    (HW_SJC_BISTDONER_WR(HW_SJC_BISTDONER_RD() |  (v)))
#define HW_SJC_BISTDONER_CLR(v)    (HW_SJC_BISTDONER_WR(HW_SJC_BISTDONER_RD() & ~(v)))
#define HW_SJC_BISTDONER_TOG(v)    (HW_SJC_BISTDONER_WR(HW_SJC_BISTDONER_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_BISTDONER bitfields
 */

/* --- Register HW_SJC_BISTDONER, field BISTDONER */

#define BP_SJC_BISTDONER_BISTDONER      0
#define BM_SJC_BISTDONER_BISTDONER      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_BISTDONER_BISTDONER(v)   ((((reg32_t) v) << 0) & BM_SJC_BISTDONER_BISTDONER)
#else
#define BF_SJC_BISTDONER_BISTDONER(v)   (((v) << 0) & BM_SJC_BISTDONER_BISTDONER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_BISTDONER_BISTDONER(v)   BF_CS1(SJC_BISTDONER, BISTDONER, v)
#endif

/*
 * HW_SJC_MONBISTSELR - Monitor BIST Select Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short MONBISTSELR : 3;
        unsigned short RESERVED0 : 13;

    } B;
} hw_sjc_monbistselr_t;
#endif

/*
 * constants & macros for entire SJC_MONBISTSELR register
 */
#define HW_SJC_MONBISTSELR_ADDR      (REGS_SJC_BASE + 0x23)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_MONBISTSELR           (*(volatile hw_sjc_monbistselr_t *) HW_SJC_MONBISTSELR_ADDR)
#define HW_SJC_MONBISTSELR_RD()      (HW_SJC_MONBISTSELR.U)
#define HW_SJC_MONBISTSELR_WR(v)     (HW_SJC_MONBISTSELR.U = (v))
#define HW_SJC_MONBISTSELR_SET(v)    (HW_SJC_MONBISTSELR_WR(HW_SJC_MONBISTSELR_RD() |  (v)))
#define HW_SJC_MONBISTSELR_CLR(v)    (HW_SJC_MONBISTSELR_WR(HW_SJC_MONBISTSELR_RD() & ~(v)))
#define HW_SJC_MONBISTSELR_TOG(v)    (HW_SJC_MONBISTSELR_WR(HW_SJC_MONBISTSELR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_MONBISTSELR bitfields
 */

/* --- Register HW_SJC_MONBISTSELR, field MONBISTSELR */

#define BP_SJC_MONBISTSELR_MONBISTSELR      0
#define BM_SJC_MONBISTSELR_MONBISTSELR      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SJC_MONBISTSELR_MONBISTSELR(v)   ((((reg32_t) v) << 0) & BM_SJC_MONBISTSELR_MONBISTSELR)
#else
#define BF_SJC_MONBISTSELR_MONBISTSELR(v)   (((v) << 0) & BM_SJC_MONBISTSELR_MONBISTSELR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_MONBISTSELR_MONBISTSELR(v)   BF_CS1(SJC_MONBISTSELR, MONBISTSELR, v)
#endif

/*
 * HW_SJC_RWCVALCR - Rval / Wval Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WVAL : 4;
        unsigned RESERVED0 : 4;
        unsigned RVAL : 4;
        unsigned RESERVED1 : 4;
        unsigned VAL_SEL : 4;
        unsigned RESERVED2 : 12;

    } B;
} hw_sjc_rwcvalcr_t;
#endif

/*
 * constants & macros for entire SJC_RWCVALCR register
 */
#define HW_SJC_RWCVALCR_ADDR      (REGS_SJC_BASE + 0x23)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_RWCVALCR           (*(volatile hw_sjc_rwcvalcr_t *) HW_SJC_RWCVALCR_ADDR)
#define HW_SJC_RWCVALCR_RD()      (HW_SJC_RWCVALCR.U)
#define HW_SJC_RWCVALCR_WR(v)     (HW_SJC_RWCVALCR.U = (v))
#define HW_SJC_RWCVALCR_SET(v)    (HW_SJC_RWCVALCR_WR(HW_SJC_RWCVALCR_RD() |  (v)))
#define HW_SJC_RWCVALCR_CLR(v)    (HW_SJC_RWCVALCR_WR(HW_SJC_RWCVALCR_RD() & ~(v)))
#define HW_SJC_RWCVALCR_TOG(v)    (HW_SJC_RWCVALCR_WR(HW_SJC_RWCVALCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_RWCVALCR bitfields
 */

/* --- Register HW_SJC_RWCVALCR, field WVAL */

#define BP_SJC_RWCVALCR_WVAL      0
#define BM_SJC_RWCVALCR_WVAL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SJC_RWCVALCR_WVAL(v)   ((((reg32_t) v) << 0) & BM_SJC_RWCVALCR_WVAL)
#else
#define BF_SJC_RWCVALCR_WVAL(v)   (((v) << 0) & BM_SJC_RWCVALCR_WVAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_RWCVALCR_WVAL(v)   BF_CS1(SJC_RWCVALCR, WVAL, v)
#endif

/* --- Register HW_SJC_RWCVALCR, field RVAL */

#define BP_SJC_RWCVALCR_RVAL      8
#define BM_SJC_RWCVALCR_RVAL      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_SJC_RWCVALCR_RVAL(v)   ((((reg32_t) v) << 8) & BM_SJC_RWCVALCR_RVAL)
#else
#define BF_SJC_RWCVALCR_RVAL(v)   (((v) << 8) & BM_SJC_RWCVALCR_RVAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_RWCVALCR_RVAL(v)   BF_CS1(SJC_RWCVALCR, RVAL, v)
#endif

/* --- Register HW_SJC_RWCVALCR, field VAL_SEL */

#define BP_SJC_RWCVALCR_VAL_SEL      16
#define BM_SJC_RWCVALCR_VAL_SEL      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_SJC_RWCVALCR_VAL_SEL(v)   ((((reg32_t) v) << 16) & BM_SJC_RWCVALCR_VAL_SEL)
#else
#define BF_SJC_RWCVALCR_VAL_SEL(v)   (((v) << 16) & BM_SJC_RWCVALCR_VAL_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_RWCVALCR_VAL_SEL(v)   BF_CS1(SJC_RWCVALCR, VAL_SEL, v)
#endif


#endif // _SJC_H

