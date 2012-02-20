/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _ESAI_H
#define _ESAI_H

#include "regs.h"

#ifndef REGS_ESAI_BASE
#define REGS_ESAI_BASE (REGS_BASE + 0x02024000)

#endif


/*
 * HW_ESAI_ETDR - ESAI Transmit Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ETDR : 32;

    } B;
} hw_esai_etdr_t;
#endif

/*
 * constants & macros for entire ESAI_ETDR register
 */
#define HW_ESAI_ETDR_ADDR      (REGS_ESAI_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_ETDR           (*(volatile hw_esai_etdr_t *) HW_ESAI_ETDR_ADDR)
#define HW_ESAI_ETDR_RD()      (HW_ESAI_ETDR.U)
#define HW_ESAI_ETDR_WR(v)     (HW_ESAI_ETDR.U = (v))
#define HW_ESAI_ETDR_SET(v)    (HW_ESAI_ETDR_WR(HW_ESAI_ETDR_RD() |  (v)))
#define HW_ESAI_ETDR_CLR(v)    (HW_ESAI_ETDR_WR(HW_ESAI_ETDR_RD() & ~(v)))
#define HW_ESAI_ETDR_TOG(v)    (HW_ESAI_ETDR_WR(HW_ESAI_ETDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_ETDR bitfields
 */

/* --- Register HW_ESAI_ETDR, field ETDR */

#define BP_ESAI_ETDR_ETDR      0
#define BM_ESAI_ETDR_ETDR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ETDR_ETDR(v)   ((((reg32_t) v) << 0) & BM_ESAI_ETDR_ETDR)
#else
#define BF_ESAI_ETDR_ETDR(v)   (((v) << 0) & BM_ESAI_ETDR_ETDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ETDR_ETDR(v)   BF_CS1(ESAI_ETDR, ETDR, v)
#endif

/*
 * HW_ESAI_ERDR - ESAI Receive Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ERDR : 32;

    } B;
} hw_esai_erdr_t;
#endif

/*
 * constants & macros for entire ESAI_ERDR register
 */
#define HW_ESAI_ERDR_ADDR      (REGS_ESAI_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_ERDR           (*(volatile hw_esai_erdr_t *) HW_ESAI_ERDR_ADDR)
#define HW_ESAI_ERDR_RD()      (HW_ESAI_ERDR.U)
#define HW_ESAI_ERDR_WR(v)     (HW_ESAI_ERDR.U = (v))
#define HW_ESAI_ERDR_SET(v)    (HW_ESAI_ERDR_WR(HW_ESAI_ERDR_RD() |  (v)))
#define HW_ESAI_ERDR_CLR(v)    (HW_ESAI_ERDR_WR(HW_ESAI_ERDR_RD() & ~(v)))
#define HW_ESAI_ERDR_TOG(v)    (HW_ESAI_ERDR_WR(HW_ESAI_ERDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_ERDR bitfields
 */

/* --- Register HW_ESAI_ERDR, field ERDR */

#define BP_ESAI_ERDR_ERDR      0
#define BM_ESAI_ERDR_ERDR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ERDR_ERDR(v)   ((((reg32_t) v) << 0) & BM_ESAI_ERDR_ERDR)
#else
#define BF_ESAI_ERDR_ERDR(v)   (((v) << 0) & BM_ESAI_ERDR_ERDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ERDR_ERDR(v)   BF_CS1(ESAI_ERDR, ERDR, v)
#endif

/*
 * HW_ESAI_ECR - ESAI Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 12;
        unsigned ETI : 1;
        unsigned ETO : 1;
        unsigned ERI : 1;
        unsigned ERO : 1;
        unsigned RESERVED1 : 14;
        unsigned ERST : 1;
        unsigned ESAIEN : 1;

    } B;
} hw_esai_ecr_t;
#endif

/*
 * constants & macros for entire ESAI_ECR register
 */
#define HW_ESAI_ECR_ADDR      (REGS_ESAI_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_ECR           (*(volatile hw_esai_ecr_t *) HW_ESAI_ECR_ADDR)
#define HW_ESAI_ECR_RD()      (HW_ESAI_ECR.U)
#define HW_ESAI_ECR_WR(v)     (HW_ESAI_ECR.U = (v))
#define HW_ESAI_ECR_SET(v)    (HW_ESAI_ECR_WR(HW_ESAI_ECR_RD() |  (v)))
#define HW_ESAI_ECR_CLR(v)    (HW_ESAI_ECR_WR(HW_ESAI_ECR_RD() & ~(v)))
#define HW_ESAI_ECR_TOG(v)    (HW_ESAI_ECR_WR(HW_ESAI_ECR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_ECR bitfields
 */

/* --- Register HW_ESAI_ECR, field ETI */

#define BP_ESAI_ECR_ETI      19
#define BM_ESAI_ECR_ETI      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ECR_ETI(v)   ((((reg32_t) v) << 19) & BM_ESAI_ECR_ETI)
#else
#define BF_ESAI_ECR_ETI(v)   (((v) << 19) & BM_ESAI_ECR_ETI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ECR_ETI(v)   BF_CS1(ESAI_ECR, ETI, v)
#endif

/* --- Register HW_ESAI_ECR, field ETO */

#define BP_ESAI_ECR_ETO      18
#define BM_ESAI_ECR_ETO      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ECR_ETO(v)   ((((reg32_t) v) << 18) & BM_ESAI_ECR_ETO)
#else
#define BF_ESAI_ECR_ETO(v)   (((v) << 18) & BM_ESAI_ECR_ETO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ECR_ETO(v)   BF_CS1(ESAI_ECR, ETO, v)
#endif

/* --- Register HW_ESAI_ECR, field ERI */

#define BP_ESAI_ECR_ERI      17
#define BM_ESAI_ECR_ERI      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ECR_ERI(v)   ((((reg32_t) v) << 17) & BM_ESAI_ECR_ERI)
#else
#define BF_ESAI_ECR_ERI(v)   (((v) << 17) & BM_ESAI_ECR_ERI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ECR_ERI(v)   BF_CS1(ESAI_ECR, ERI, v)
#endif

/* --- Register HW_ESAI_ECR, field ERO */

#define BP_ESAI_ECR_ERO      16
#define BM_ESAI_ECR_ERO      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ECR_ERO(v)   ((((reg32_t) v) << 16) & BM_ESAI_ECR_ERO)
#else
#define BF_ESAI_ECR_ERO(v)   (((v) << 16) & BM_ESAI_ECR_ERO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ECR_ERO(v)   BF_CS1(ESAI_ECR, ERO, v)
#endif

/* --- Register HW_ESAI_ECR, field ERST */

#define BP_ESAI_ECR_ERST      1
#define BM_ESAI_ECR_ERST      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ECR_ERST(v)   ((((reg32_t) v) << 1) & BM_ESAI_ECR_ERST)
#else
#define BF_ESAI_ECR_ERST(v)   (((v) << 1) & BM_ESAI_ECR_ERST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ECR_ERST(v)   BF_CS1(ESAI_ECR, ERST, v)
#endif

/* --- Register HW_ESAI_ECR, field ESAIEN */

#define BP_ESAI_ECR_ESAIEN      0
#define BM_ESAI_ECR_ESAIEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ECR_ESAIEN(v)   ((((reg32_t) v) << 0) & BM_ESAI_ECR_ESAIEN)
#else
#define BF_ESAI_ECR_ESAIEN(v)   (((v) << 0) & BM_ESAI_ECR_ESAIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ECR_ESAIEN(v)   BF_CS1(ESAI_ECR, ESAIEN, v)
#endif

/*
 * HW_ESAI_ESR - ESAI Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 21;
        unsigned TINIT : 1;
        unsigned RFF : 1;
        unsigned TFE : 1;
        unsigned TLS : 1;
        unsigned TDE : 1;
        unsigned TED : 1;
        unsigned TD : 1;
        unsigned RLS : 1;
        unsigned RDE : 1;
        unsigned RED : 1;
        unsigned RD : 1;

    } B;
} hw_esai_esr_t;
#endif

/*
 * constants & macros for entire ESAI_ESR register
 */
#define HW_ESAI_ESR_ADDR      (REGS_ESAI_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_ESR           (*(volatile hw_esai_esr_t *) HW_ESAI_ESR_ADDR)
#define HW_ESAI_ESR_RD()      (HW_ESAI_ESR.U)
#define HW_ESAI_ESR_WR(v)     (HW_ESAI_ESR.U = (v))
#define HW_ESAI_ESR_SET(v)    (HW_ESAI_ESR_WR(HW_ESAI_ESR_RD() |  (v)))
#define HW_ESAI_ESR_CLR(v)    (HW_ESAI_ESR_WR(HW_ESAI_ESR_RD() & ~(v)))
#define HW_ESAI_ESR_TOG(v)    (HW_ESAI_ESR_WR(HW_ESAI_ESR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_ESR bitfields
 */

/* --- Register HW_ESAI_ESR, field TINIT */

#define BP_ESAI_ESR_TINIT      10
#define BM_ESAI_ESR_TINIT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_TINIT(v)   ((((reg32_t) v) << 10) & BM_ESAI_ESR_TINIT)
#else
#define BF_ESAI_ESR_TINIT(v)   (((v) << 10) & BM_ESAI_ESR_TINIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_TINIT(v)   BF_CS1(ESAI_ESR, TINIT, v)
#endif

/* --- Register HW_ESAI_ESR, field RFF */

#define BP_ESAI_ESR_RFF      9
#define BM_ESAI_ESR_RFF      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_RFF(v)   ((((reg32_t) v) << 9) & BM_ESAI_ESR_RFF)
#else
#define BF_ESAI_ESR_RFF(v)   (((v) << 9) & BM_ESAI_ESR_RFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_RFF(v)   BF_CS1(ESAI_ESR, RFF, v)
#endif

/* --- Register HW_ESAI_ESR, field TFE */

#define BP_ESAI_ESR_TFE      8
#define BM_ESAI_ESR_TFE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_TFE(v)   ((((reg32_t) v) << 8) & BM_ESAI_ESR_TFE)
#else
#define BF_ESAI_ESR_TFE(v)   (((v) << 8) & BM_ESAI_ESR_TFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_TFE(v)   BF_CS1(ESAI_ESR, TFE, v)
#endif

/* --- Register HW_ESAI_ESR, field TLS */

#define BP_ESAI_ESR_TLS      7
#define BM_ESAI_ESR_TLS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_TLS(v)   ((((reg32_t) v) << 7) & BM_ESAI_ESR_TLS)
#else
#define BF_ESAI_ESR_TLS(v)   (((v) << 7) & BM_ESAI_ESR_TLS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_TLS(v)   BF_CS1(ESAI_ESR, TLS, v)
#endif

/* --- Register HW_ESAI_ESR, field TDE */

#define BP_ESAI_ESR_TDE      6
#define BM_ESAI_ESR_TDE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_TDE(v)   ((((reg32_t) v) << 6) & BM_ESAI_ESR_TDE)
#else
#define BF_ESAI_ESR_TDE(v)   (((v) << 6) & BM_ESAI_ESR_TDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_TDE(v)   BF_CS1(ESAI_ESR, TDE, v)
#endif

/* --- Register HW_ESAI_ESR, field TED */

#define BP_ESAI_ESR_TED      5
#define BM_ESAI_ESR_TED      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_TED(v)   ((((reg32_t) v) << 5) & BM_ESAI_ESR_TED)
#else
#define BF_ESAI_ESR_TED(v)   (((v) << 5) & BM_ESAI_ESR_TED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_TED(v)   BF_CS1(ESAI_ESR, TED, v)
#endif

/* --- Register HW_ESAI_ESR, field TD */

#define BP_ESAI_ESR_TD      4
#define BM_ESAI_ESR_TD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_TD(v)   ((((reg32_t) v) << 4) & BM_ESAI_ESR_TD)
#else
#define BF_ESAI_ESR_TD(v)   (((v) << 4) & BM_ESAI_ESR_TD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_TD(v)   BF_CS1(ESAI_ESR, TD, v)
#endif

/* --- Register HW_ESAI_ESR, field RLS */

#define BP_ESAI_ESR_RLS      3
#define BM_ESAI_ESR_RLS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_RLS(v)   ((((reg32_t) v) << 3) & BM_ESAI_ESR_RLS)
#else
#define BF_ESAI_ESR_RLS(v)   (((v) << 3) & BM_ESAI_ESR_RLS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_RLS(v)   BF_CS1(ESAI_ESR, RLS, v)
#endif

/* --- Register HW_ESAI_ESR, field RDE */

#define BP_ESAI_ESR_RDE      2
#define BM_ESAI_ESR_RDE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_RDE(v)   ((((reg32_t) v) << 2) & BM_ESAI_ESR_RDE)
#else
#define BF_ESAI_ESR_RDE(v)   (((v) << 2) & BM_ESAI_ESR_RDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_RDE(v)   BF_CS1(ESAI_ESR, RDE, v)
#endif

/* --- Register HW_ESAI_ESR, field RED */

#define BP_ESAI_ESR_RED      1
#define BM_ESAI_ESR_RED      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_RED(v)   ((((reg32_t) v) << 1) & BM_ESAI_ESR_RED)
#else
#define BF_ESAI_ESR_RED(v)   (((v) << 1) & BM_ESAI_ESR_RED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_RED(v)   BF_CS1(ESAI_ESR, RED, v)
#endif

/* --- Register HW_ESAI_ESR, field RD */

#define BP_ESAI_ESR_RD      0
#define BM_ESAI_ESR_RD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_ESR_RD(v)   ((((reg32_t) v) << 0) & BM_ESAI_ESR_RD)
#else
#define BF_ESAI_ESR_RD(v)   (((v) << 0) & BM_ESAI_ESR_RD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_ESR_RD(v)   BF_CS1(ESAI_ESR, RD, v)
#endif

/*
 * HW_ESAI_TFCR - Transmit FIFO Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 12;
        unsigned TIEN : 1;
        unsigned TWA : 3;
        unsigned TFWM : 8;
        unsigned TE5 : 1;
        unsigned TE4 : 1;
        unsigned TE3 : 1;
        unsigned TE2 : 1;
        unsigned TE1 : 1;
        unsigned TE0 : 1;
        unsigned TFR : 1;
        unsigned TFE : 1;

    } B;
} hw_esai_tfcr_t;
#endif

/*
 * constants & macros for entire ESAI_TFCR register
 */
#define HW_ESAI_TFCR_ADDR      (REGS_ESAI_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TFCR           (*(volatile hw_esai_tfcr_t *) HW_ESAI_TFCR_ADDR)
#define HW_ESAI_TFCR_RD()      (HW_ESAI_TFCR.U)
#define HW_ESAI_TFCR_WR(v)     (HW_ESAI_TFCR.U = (v))
#define HW_ESAI_TFCR_SET(v)    (HW_ESAI_TFCR_WR(HW_ESAI_TFCR_RD() |  (v)))
#define HW_ESAI_TFCR_CLR(v)    (HW_ESAI_TFCR_WR(HW_ESAI_TFCR_RD() & ~(v)))
#define HW_ESAI_TFCR_TOG(v)    (HW_ESAI_TFCR_WR(HW_ESAI_TFCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_TFCR bitfields
 */

/* --- Register HW_ESAI_TFCR, field TIEN */

#define BP_ESAI_TFCR_TIEN      19
#define BM_ESAI_TFCR_TIEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TIEN(v)   ((((reg32_t) v) << 19) & BM_ESAI_TFCR_TIEN)
#else
#define BF_ESAI_TFCR_TIEN(v)   (((v) << 19) & BM_ESAI_TFCR_TIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TIEN(v)   BF_CS1(ESAI_TFCR, TIEN, v)
#endif

/* --- Register HW_ESAI_TFCR, field TWA */

#define BP_ESAI_TFCR_TWA      16
#define BM_ESAI_TFCR_TWA      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TWA(v)   ((((reg32_t) v) << 16) & BM_ESAI_TFCR_TWA)
#else
#define BF_ESAI_TFCR_TWA(v)   (((v) << 16) & BM_ESAI_TFCR_TWA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TWA(v)   BF_CS1(ESAI_TFCR, TWA, v)
#endif

/* --- Register HW_ESAI_TFCR, field TFWM */

#define BP_ESAI_TFCR_TFWM      8
#define BM_ESAI_TFCR_TFWM      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TFWM(v)   ((((reg32_t) v) << 8) & BM_ESAI_TFCR_TFWM)
#else
#define BF_ESAI_TFCR_TFWM(v)   (((v) << 8) & BM_ESAI_TFCR_TFWM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TFWM(v)   BF_CS1(ESAI_TFCR, TFWM, v)
#endif

/* --- Register HW_ESAI_TFCR, field TE5 */

#define BP_ESAI_TFCR_TE5      7
#define BM_ESAI_TFCR_TE5      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TE5(v)   ((((reg32_t) v) << 7) & BM_ESAI_TFCR_TE5)
#else
#define BF_ESAI_TFCR_TE5(v)   (((v) << 7) & BM_ESAI_TFCR_TE5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TE5(v)   BF_CS1(ESAI_TFCR, TE5, v)
#endif

/* --- Register HW_ESAI_TFCR, field TE4 */

#define BP_ESAI_TFCR_TE4      6
#define BM_ESAI_TFCR_TE4      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TE4(v)   ((((reg32_t) v) << 6) & BM_ESAI_TFCR_TE4)
#else
#define BF_ESAI_TFCR_TE4(v)   (((v) << 6) & BM_ESAI_TFCR_TE4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TE4(v)   BF_CS1(ESAI_TFCR, TE4, v)
#endif

/* --- Register HW_ESAI_TFCR, field TE3 */

#define BP_ESAI_TFCR_TE3      5
#define BM_ESAI_TFCR_TE3      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TE3(v)   ((((reg32_t) v) << 5) & BM_ESAI_TFCR_TE3)
#else
#define BF_ESAI_TFCR_TE3(v)   (((v) << 5) & BM_ESAI_TFCR_TE3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TE3(v)   BF_CS1(ESAI_TFCR, TE3, v)
#endif

/* --- Register HW_ESAI_TFCR, field TE2 */

#define BP_ESAI_TFCR_TE2      4
#define BM_ESAI_TFCR_TE2      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TE2(v)   ((((reg32_t) v) << 4) & BM_ESAI_TFCR_TE2)
#else
#define BF_ESAI_TFCR_TE2(v)   (((v) << 4) & BM_ESAI_TFCR_TE2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TE2(v)   BF_CS1(ESAI_TFCR, TE2, v)
#endif

/* --- Register HW_ESAI_TFCR, field TE1 */

#define BP_ESAI_TFCR_TE1      3
#define BM_ESAI_TFCR_TE1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TE1(v)   ((((reg32_t) v) << 3) & BM_ESAI_TFCR_TE1)
#else
#define BF_ESAI_TFCR_TE1(v)   (((v) << 3) & BM_ESAI_TFCR_TE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TE1(v)   BF_CS1(ESAI_TFCR, TE1, v)
#endif

/* --- Register HW_ESAI_TFCR, field TE0 */

#define BP_ESAI_TFCR_TE0      2
#define BM_ESAI_TFCR_TE0      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TE0(v)   ((((reg32_t) v) << 2) & BM_ESAI_TFCR_TE0)
#else
#define BF_ESAI_TFCR_TE0(v)   (((v) << 2) & BM_ESAI_TFCR_TE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TE0(v)   BF_CS1(ESAI_TFCR, TE0, v)
#endif

/* --- Register HW_ESAI_TFCR, field TFR */

#define BP_ESAI_TFCR_TFR      1
#define BM_ESAI_TFCR_TFR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TFR(v)   ((((reg32_t) v) << 1) & BM_ESAI_TFCR_TFR)
#else
#define BF_ESAI_TFCR_TFR(v)   (((v) << 1) & BM_ESAI_TFCR_TFR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TFR(v)   BF_CS1(ESAI_TFCR, TFR, v)
#endif

/* --- Register HW_ESAI_TFCR, field TFE */

#define BP_ESAI_TFCR_TFE      0
#define BM_ESAI_TFCR_TFE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFCR_TFE(v)   ((((reg32_t) v) << 0) & BM_ESAI_TFCR_TFE)
#else
#define BF_ESAI_TFCR_TFE(v)   (((v) << 0) & BM_ESAI_TFCR_TFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFCR_TFE(v)   BF_CS1(ESAI_TFCR, TFE, v)
#endif

/*
 * HW_ESAI_TFSR - Transmit FIFO Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 17;
        unsigned NTFO : 3;
        unsigned RESERVED1 : 1;
        unsigned NTFI : 3;
        unsigned TFCNT : 8;

    } B;
} hw_esai_tfsr_t;
#endif

/*
 * constants & macros for entire ESAI_TFSR register
 */
#define HW_ESAI_TFSR_ADDR      (REGS_ESAI_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TFSR           (*(volatile hw_esai_tfsr_t *) HW_ESAI_TFSR_ADDR)
#define HW_ESAI_TFSR_RD()      (HW_ESAI_TFSR.U)
#define HW_ESAI_TFSR_WR(v)     (HW_ESAI_TFSR.U = (v))
#define HW_ESAI_TFSR_SET(v)    (HW_ESAI_TFSR_WR(HW_ESAI_TFSR_RD() |  (v)))
#define HW_ESAI_TFSR_CLR(v)    (HW_ESAI_TFSR_WR(HW_ESAI_TFSR_RD() & ~(v)))
#define HW_ESAI_TFSR_TOG(v)    (HW_ESAI_TFSR_WR(HW_ESAI_TFSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_TFSR bitfields
 */

/* --- Register HW_ESAI_TFSR, field NTFO */

#define BP_ESAI_TFSR_NTFO      12
#define BM_ESAI_TFSR_NTFO      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFSR_NTFO(v)   ((((reg32_t) v) << 12) & BM_ESAI_TFSR_NTFO)
#else
#define BF_ESAI_TFSR_NTFO(v)   (((v) << 12) & BM_ESAI_TFSR_NTFO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFSR_NTFO(v)   BF_CS1(ESAI_TFSR, NTFO, v)
#endif

/* --- Register HW_ESAI_TFSR, field NTFI */

#define BP_ESAI_TFSR_NTFI      8
#define BM_ESAI_TFSR_NTFI      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFSR_NTFI(v)   ((((reg32_t) v) << 8) & BM_ESAI_TFSR_NTFI)
#else
#define BF_ESAI_TFSR_NTFI(v)   (((v) << 8) & BM_ESAI_TFSR_NTFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFSR_NTFI(v)   BF_CS1(ESAI_TFSR, NTFI, v)
#endif

/* --- Register HW_ESAI_TFSR, field TFCNT */

#define BP_ESAI_TFSR_TFCNT      0
#define BM_ESAI_TFSR_TFCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TFSR_TFCNT(v)   ((((reg32_t) v) << 0) & BM_ESAI_TFSR_TFCNT)
#else
#define BF_ESAI_TFSR_TFCNT(v)   (((v) << 0) & BM_ESAI_TFSR_TFCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TFSR_TFCNT(v)   BF_CS1(ESAI_TFSR, TFCNT, v)
#endif

/*
 * HW_ESAI_RFCR - Receive FIFO Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 12;
        unsigned REXT : 1;
        unsigned RWA : 3;
        unsigned RFWM : 8;
        unsigned RESERVED1 : 2;
        unsigned RE3 : 1;
        unsigned RE2 : 1;
        unsigned RE1 : 1;
        unsigned RE0 : 1;
        unsigned RFR : 1;
        unsigned RFE : 1;

    } B;
} hw_esai_rfcr_t;
#endif

/*
 * constants & macros for entire ESAI_RFCR register
 */
#define HW_ESAI_RFCR_ADDR      (REGS_ESAI_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RFCR           (*(volatile hw_esai_rfcr_t *) HW_ESAI_RFCR_ADDR)
#define HW_ESAI_RFCR_RD()      (HW_ESAI_RFCR.U)
#define HW_ESAI_RFCR_WR(v)     (HW_ESAI_RFCR.U = (v))
#define HW_ESAI_RFCR_SET(v)    (HW_ESAI_RFCR_WR(HW_ESAI_RFCR_RD() |  (v)))
#define HW_ESAI_RFCR_CLR(v)    (HW_ESAI_RFCR_WR(HW_ESAI_RFCR_RD() & ~(v)))
#define HW_ESAI_RFCR_TOG(v)    (HW_ESAI_RFCR_WR(HW_ESAI_RFCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_RFCR bitfields
 */

/* --- Register HW_ESAI_RFCR, field REXT */

#define BP_ESAI_RFCR_REXT      19
#define BM_ESAI_RFCR_REXT      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_REXT(v)   ((((reg32_t) v) << 19) & BM_ESAI_RFCR_REXT)
#else
#define BF_ESAI_RFCR_REXT(v)   (((v) << 19) & BM_ESAI_RFCR_REXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_REXT(v)   BF_CS1(ESAI_RFCR, REXT, v)
#endif

/* --- Register HW_ESAI_RFCR, field RWA */

#define BP_ESAI_RFCR_RWA      16
#define BM_ESAI_RFCR_RWA      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_RWA(v)   ((((reg32_t) v) << 16) & BM_ESAI_RFCR_RWA)
#else
#define BF_ESAI_RFCR_RWA(v)   (((v) << 16) & BM_ESAI_RFCR_RWA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_RWA(v)   BF_CS1(ESAI_RFCR, RWA, v)
#endif

/* --- Register HW_ESAI_RFCR, field RFWM */

#define BP_ESAI_RFCR_RFWM      8
#define BM_ESAI_RFCR_RFWM      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_RFWM(v)   ((((reg32_t) v) << 8) & BM_ESAI_RFCR_RFWM)
#else
#define BF_ESAI_RFCR_RFWM(v)   (((v) << 8) & BM_ESAI_RFCR_RFWM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_RFWM(v)   BF_CS1(ESAI_RFCR, RFWM, v)
#endif

/* --- Register HW_ESAI_RFCR, field RE3 */

#define BP_ESAI_RFCR_RE3      5
#define BM_ESAI_RFCR_RE3      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_RE3(v)   ((((reg32_t) v) << 5) & BM_ESAI_RFCR_RE3)
#else
#define BF_ESAI_RFCR_RE3(v)   (((v) << 5) & BM_ESAI_RFCR_RE3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_RE3(v)   BF_CS1(ESAI_RFCR, RE3, v)
#endif

/* --- Register HW_ESAI_RFCR, field RE2 */

#define BP_ESAI_RFCR_RE2      4
#define BM_ESAI_RFCR_RE2      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_RE2(v)   ((((reg32_t) v) << 4) & BM_ESAI_RFCR_RE2)
#else
#define BF_ESAI_RFCR_RE2(v)   (((v) << 4) & BM_ESAI_RFCR_RE2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_RE2(v)   BF_CS1(ESAI_RFCR, RE2, v)
#endif

/* --- Register HW_ESAI_RFCR, field RE1 */

#define BP_ESAI_RFCR_RE1      3
#define BM_ESAI_RFCR_RE1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_RE1(v)   ((((reg32_t) v) << 3) & BM_ESAI_RFCR_RE1)
#else
#define BF_ESAI_RFCR_RE1(v)   (((v) << 3) & BM_ESAI_RFCR_RE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_RE1(v)   BF_CS1(ESAI_RFCR, RE1, v)
#endif

/* --- Register HW_ESAI_RFCR, field RE0 */

#define BP_ESAI_RFCR_RE0      2
#define BM_ESAI_RFCR_RE0      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_RE0(v)   ((((reg32_t) v) << 2) & BM_ESAI_RFCR_RE0)
#else
#define BF_ESAI_RFCR_RE0(v)   (((v) << 2) & BM_ESAI_RFCR_RE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_RE0(v)   BF_CS1(ESAI_RFCR, RE0, v)
#endif

/* --- Register HW_ESAI_RFCR, field RFR */

#define BP_ESAI_RFCR_RFR      1
#define BM_ESAI_RFCR_RFR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_RFR(v)   ((((reg32_t) v) << 1) & BM_ESAI_RFCR_RFR)
#else
#define BF_ESAI_RFCR_RFR(v)   (((v) << 1) & BM_ESAI_RFCR_RFR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_RFR(v)   BF_CS1(ESAI_RFCR, RFR, v)
#endif

/* --- Register HW_ESAI_RFCR, field RFE */

#define BP_ESAI_RFCR_RFE      0
#define BM_ESAI_RFCR_RFE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFCR_RFE(v)   ((((reg32_t) v) << 0) & BM_ESAI_RFCR_RFE)
#else
#define BF_ESAI_RFCR_RFE(v)   (((v) << 0) & BM_ESAI_RFCR_RFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFCR_RFE(v)   BF_CS1(ESAI_RFCR, RFE, v)
#endif

/*
 * HW_ESAI_RFSR - Receive FIFO Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 18;
        unsigned NRFI : 2;
        unsigned RESERVED1 : 2;
        unsigned NRFO : 2;
        unsigned RFCNT : 8;

    } B;
} hw_esai_rfsr_t;
#endif

/*
 * constants & macros for entire ESAI_RFSR register
 */
#define HW_ESAI_RFSR_ADDR      (REGS_ESAI_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RFSR           (*(volatile hw_esai_rfsr_t *) HW_ESAI_RFSR_ADDR)
#define HW_ESAI_RFSR_RD()      (HW_ESAI_RFSR.U)
#define HW_ESAI_RFSR_WR(v)     (HW_ESAI_RFSR.U = (v))
#define HW_ESAI_RFSR_SET(v)    (HW_ESAI_RFSR_WR(HW_ESAI_RFSR_RD() |  (v)))
#define HW_ESAI_RFSR_CLR(v)    (HW_ESAI_RFSR_WR(HW_ESAI_RFSR_RD() & ~(v)))
#define HW_ESAI_RFSR_TOG(v)    (HW_ESAI_RFSR_WR(HW_ESAI_RFSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_RFSR bitfields
 */

/* --- Register HW_ESAI_RFSR, field NRFI */

#define BP_ESAI_RFSR_NRFI      12
#define BM_ESAI_RFSR_NRFI      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFSR_NRFI(v)   ((((reg32_t) v) << 12) & BM_ESAI_RFSR_NRFI)
#else
#define BF_ESAI_RFSR_NRFI(v)   (((v) << 12) & BM_ESAI_RFSR_NRFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFSR_NRFI(v)   BF_CS1(ESAI_RFSR, NRFI, v)
#endif

/* --- Register HW_ESAI_RFSR, field NRFO */

#define BP_ESAI_RFSR_NRFO      8
#define BM_ESAI_RFSR_NRFO      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFSR_NRFO(v)   ((((reg32_t) v) << 8) & BM_ESAI_RFSR_NRFO)
#else
#define BF_ESAI_RFSR_NRFO(v)   (((v) << 8) & BM_ESAI_RFSR_NRFO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFSR_NRFO(v)   BF_CS1(ESAI_RFSR, NRFO, v)
#endif

/* --- Register HW_ESAI_RFSR, field RFCNT */

#define BP_ESAI_RFSR_RFCNT      0
#define BM_ESAI_RFSR_RFCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RFSR_RFCNT(v)   ((((reg32_t) v) << 0) & BM_ESAI_RFSR_RFCNT)
#else
#define BF_ESAI_RFSR_RFCNT(v)   (((v) << 0) & BM_ESAI_RFSR_RFCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RFSR_RFCNT(v)   BF_CS1(ESAI_RFSR, RFCNT, v)
#endif

/*
 * HW_ESAI_TX - Transmit Data Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned TXN : 24;

    } B;
} hw_esai_tx_t;
#endif

/*
 * constants & macros for entire ESAI_TX register
 */
#define HW_ESAI_TX_ADDR      (REGS_ESAI_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TX           (*(volatile hw_esai_tx_t *) HW_ESAI_TX_ADDR)
#define HW_ESAI_TX_RD()      (HW_ESAI_TX.U)
#define HW_ESAI_TX_WR(v)     (HW_ESAI_TX.U = (v))
#define HW_ESAI_TX_SET(v)    (HW_ESAI_TX_WR(HW_ESAI_TX_RD() |  (v)))
#define HW_ESAI_TX_CLR(v)    (HW_ESAI_TX_WR(HW_ESAI_TX_RD() & ~(v)))
#define HW_ESAI_TX_TOG(v)    (HW_ESAI_TX_WR(HW_ESAI_TX_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_TX bitfields
 */

/* --- Register HW_ESAI_TX, field TXN */

#define BP_ESAI_TX_TXN      0
#define BM_ESAI_TX_TXN      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TX_TXN(v)   ((((reg32_t) v) << 0) & BM_ESAI_TX_TXN)
#else
#define BF_ESAI_TX_TXN(v)   (((v) << 0) & BM_ESAI_TX_TXN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TX_TXN(v)   BF_CS1(ESAI_TX, TXN, v)
#endif

/*
 * HW_ESAI_TSR - ESAI Transmit Slot Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned TSR : 24;

    } B;
} hw_esai_tsr_t;
#endif

/*
 * constants & macros for entire ESAI_TSR register
 */
#define HW_ESAI_TSR_ADDR      (REGS_ESAI_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TSR           (*(volatile hw_esai_tsr_t *) HW_ESAI_TSR_ADDR)
#define HW_ESAI_TSR_RD()      (HW_ESAI_TSR.U)
#define HW_ESAI_TSR_WR(v)     (HW_ESAI_TSR.U = (v))
#define HW_ESAI_TSR_SET(v)    (HW_ESAI_TSR_WR(HW_ESAI_TSR_RD() |  (v)))
#define HW_ESAI_TSR_CLR(v)    (HW_ESAI_TSR_WR(HW_ESAI_TSR_RD() & ~(v)))
#define HW_ESAI_TSR_TOG(v)    (HW_ESAI_TSR_WR(HW_ESAI_TSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_TSR bitfields
 */

/* --- Register HW_ESAI_TSR, field TSR */

#define BP_ESAI_TSR_TSR      0
#define BM_ESAI_TSR_TSR      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TSR_TSR(v)   ((((reg32_t) v) << 0) & BM_ESAI_TSR_TSR)
#else
#define BF_ESAI_TSR_TSR(v)   (((v) << 0) & BM_ESAI_TSR_TSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TSR_TSR(v)   BF_CS1(ESAI_TSR, TSR, v)
#endif

/*
 * HW_ESAI_RX - Receive Data Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RXN : 24;

    } B;
} hw_esai_rx_t;
#endif

/*
 * constants & macros for entire ESAI_RX register
 */
#define HW_ESAI_RX_ADDR      (REGS_ESAI_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RX           (*(volatile hw_esai_rx_t *) HW_ESAI_RX_ADDR)
#define HW_ESAI_RX_RD()      (HW_ESAI_RX.U)
#define HW_ESAI_RX_WR(v)     (HW_ESAI_RX.U = (v))
#define HW_ESAI_RX_SET(v)    (HW_ESAI_RX_WR(HW_ESAI_RX_RD() |  (v)))
#define HW_ESAI_RX_CLR(v)    (HW_ESAI_RX_WR(HW_ESAI_RX_RD() & ~(v)))
#define HW_ESAI_RX_TOG(v)    (HW_ESAI_RX_WR(HW_ESAI_RX_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_RX bitfields
 */

/* --- Register HW_ESAI_RX, field RXN */

#define BP_ESAI_RX_RXN      0
#define BM_ESAI_RX_RXN      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RX_RXN(v)   ((((reg32_t) v) << 0) & BM_ESAI_RX_RXN)
#else
#define BF_ESAI_RX_RXN(v)   (((v) << 0) & BM_ESAI_RX_RXN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RX_RXN(v)   BF_CS1(ESAI_RX, RXN, v)
#endif

/*
 * HW_ESAI_SAISR - Serial Audio Interface Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned TODFE : 1;
        unsigned TEDE : 1;
        unsigned TDE : 1;
        unsigned TUE : 1;
        unsigned TFS : 1;
        unsigned RESERVED1 : 2;
        unsigned RODF : 1;
        unsigned REDF : 1;
        unsigned RDF : 1;
        unsigned ROE : 1;
        unsigned RFS : 1;
        unsigned RESERVED2 : 3;
        unsigned IF2 : 1;
        unsigned IF1 : 1;
        unsigned IF0 : 1;

    } B;
} hw_esai_saisr_t;
#endif

/*
 * constants & macros for entire ESAI_SAISR register
 */
#define HW_ESAI_SAISR_ADDR      (REGS_ESAI_BASE + 0xcc)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_SAISR           (*(volatile hw_esai_saisr_t *) HW_ESAI_SAISR_ADDR)
#define HW_ESAI_SAISR_RD()      (HW_ESAI_SAISR.U)
#define HW_ESAI_SAISR_WR(v)     (HW_ESAI_SAISR.U = (v))
#define HW_ESAI_SAISR_SET(v)    (HW_ESAI_SAISR_WR(HW_ESAI_SAISR_RD() |  (v)))
#define HW_ESAI_SAISR_CLR(v)    (HW_ESAI_SAISR_WR(HW_ESAI_SAISR_RD() & ~(v)))
#define HW_ESAI_SAISR_TOG(v)    (HW_ESAI_SAISR_WR(HW_ESAI_SAISR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_SAISR bitfields
 */

/* --- Register HW_ESAI_SAISR, field TODFE */

#define BP_ESAI_SAISR_TODFE      17
#define BM_ESAI_SAISR_TODFE      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_TODFE(v)   ((((reg32_t) v) << 17) & BM_ESAI_SAISR_TODFE)
#else
#define BF_ESAI_SAISR_TODFE(v)   (((v) << 17) & BM_ESAI_SAISR_TODFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_TODFE(v)   BF_CS1(ESAI_SAISR, TODFE, v)
#endif

/* --- Register HW_ESAI_SAISR, field TEDE */

#define BP_ESAI_SAISR_TEDE      16
#define BM_ESAI_SAISR_TEDE      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_TEDE(v)   ((((reg32_t) v) << 16) & BM_ESAI_SAISR_TEDE)
#else
#define BF_ESAI_SAISR_TEDE(v)   (((v) << 16) & BM_ESAI_SAISR_TEDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_TEDE(v)   BF_CS1(ESAI_SAISR, TEDE, v)
#endif

/* --- Register HW_ESAI_SAISR, field TDE */

#define BP_ESAI_SAISR_TDE      15
#define BM_ESAI_SAISR_TDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_TDE(v)   ((((reg32_t) v) << 15) & BM_ESAI_SAISR_TDE)
#else
#define BF_ESAI_SAISR_TDE(v)   (((v) << 15) & BM_ESAI_SAISR_TDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_TDE(v)   BF_CS1(ESAI_SAISR, TDE, v)
#endif

/* --- Register HW_ESAI_SAISR, field TUE */

#define BP_ESAI_SAISR_TUE      14
#define BM_ESAI_SAISR_TUE      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_TUE(v)   ((((reg32_t) v) << 14) & BM_ESAI_SAISR_TUE)
#else
#define BF_ESAI_SAISR_TUE(v)   (((v) << 14) & BM_ESAI_SAISR_TUE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_TUE(v)   BF_CS1(ESAI_SAISR, TUE, v)
#endif

/* --- Register HW_ESAI_SAISR, field TFS */

#define BP_ESAI_SAISR_TFS      13
#define BM_ESAI_SAISR_TFS      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_TFS(v)   ((((reg32_t) v) << 13) & BM_ESAI_SAISR_TFS)
#else
#define BF_ESAI_SAISR_TFS(v)   (((v) << 13) & BM_ESAI_SAISR_TFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_TFS(v)   BF_CS1(ESAI_SAISR, TFS, v)
#endif

/* --- Register HW_ESAI_SAISR, field RODF */

#define BP_ESAI_SAISR_RODF      10
#define BM_ESAI_SAISR_RODF      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_RODF(v)   ((((reg32_t) v) << 10) & BM_ESAI_SAISR_RODF)
#else
#define BF_ESAI_SAISR_RODF(v)   (((v) << 10) & BM_ESAI_SAISR_RODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_RODF(v)   BF_CS1(ESAI_SAISR, RODF, v)
#endif

/* --- Register HW_ESAI_SAISR, field REDF */

#define BP_ESAI_SAISR_REDF      9
#define BM_ESAI_SAISR_REDF      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_REDF(v)   ((((reg32_t) v) << 9) & BM_ESAI_SAISR_REDF)
#else
#define BF_ESAI_SAISR_REDF(v)   (((v) << 9) & BM_ESAI_SAISR_REDF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_REDF(v)   BF_CS1(ESAI_SAISR, REDF, v)
#endif

/* --- Register HW_ESAI_SAISR, field RDF */

#define BP_ESAI_SAISR_RDF      8
#define BM_ESAI_SAISR_RDF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_RDF(v)   ((((reg32_t) v) << 8) & BM_ESAI_SAISR_RDF)
#else
#define BF_ESAI_SAISR_RDF(v)   (((v) << 8) & BM_ESAI_SAISR_RDF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_RDF(v)   BF_CS1(ESAI_SAISR, RDF, v)
#endif

/* --- Register HW_ESAI_SAISR, field ROE */

#define BP_ESAI_SAISR_ROE      7
#define BM_ESAI_SAISR_ROE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_ROE(v)   ((((reg32_t) v) << 7) & BM_ESAI_SAISR_ROE)
#else
#define BF_ESAI_SAISR_ROE(v)   (((v) << 7) & BM_ESAI_SAISR_ROE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_ROE(v)   BF_CS1(ESAI_SAISR, ROE, v)
#endif

/* --- Register HW_ESAI_SAISR, field RFS */

#define BP_ESAI_SAISR_RFS      6
#define BM_ESAI_SAISR_RFS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_RFS(v)   ((((reg32_t) v) << 6) & BM_ESAI_SAISR_RFS)
#else
#define BF_ESAI_SAISR_RFS(v)   (((v) << 6) & BM_ESAI_SAISR_RFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_RFS(v)   BF_CS1(ESAI_SAISR, RFS, v)
#endif

/* --- Register HW_ESAI_SAISR, field IF2 */

#define BP_ESAI_SAISR_IF2      2
#define BM_ESAI_SAISR_IF2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_IF2(v)   ((((reg32_t) v) << 2) & BM_ESAI_SAISR_IF2)
#else
#define BF_ESAI_SAISR_IF2(v)   (((v) << 2) & BM_ESAI_SAISR_IF2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_IF2(v)   BF_CS1(ESAI_SAISR, IF2, v)
#endif

/* --- Register HW_ESAI_SAISR, field IF1 */

#define BP_ESAI_SAISR_IF1      1
#define BM_ESAI_SAISR_IF1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_IF1(v)   ((((reg32_t) v) << 1) & BM_ESAI_SAISR_IF1)
#else
#define BF_ESAI_SAISR_IF1(v)   (((v) << 1) & BM_ESAI_SAISR_IF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_IF1(v)   BF_CS1(ESAI_SAISR, IF1, v)
#endif

/* --- Register HW_ESAI_SAISR, field IF0 */

#define BP_ESAI_SAISR_IF0      0
#define BM_ESAI_SAISR_IF0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAISR_IF0(v)   ((((reg32_t) v) << 0) & BM_ESAI_SAISR_IF0)
#else
#define BF_ESAI_SAISR_IF0(v)   (((v) << 0) & BM_ESAI_SAISR_IF0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAISR_IF0(v)   BF_CS1(ESAI_SAISR, IF0, v)
#endif

/*
 * HW_ESAI_SAICR - Serial Audio Interface Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 23;
        unsigned ALC : 1;
        unsigned TEBE : 1;
        unsigned SYN : 1;
        unsigned RESERVED1 : 3;
        unsigned OF2 : 1;
        unsigned OF1 : 1;
        unsigned OF0 : 1;

    } B;
} hw_esai_saicr_t;
#endif

/*
 * constants & macros for entire ESAI_SAICR register
 */
#define HW_ESAI_SAICR_ADDR      (REGS_ESAI_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_SAICR           (*(volatile hw_esai_saicr_t *) HW_ESAI_SAICR_ADDR)
#define HW_ESAI_SAICR_RD()      (HW_ESAI_SAICR.U)
#define HW_ESAI_SAICR_WR(v)     (HW_ESAI_SAICR.U = (v))
#define HW_ESAI_SAICR_SET(v)    (HW_ESAI_SAICR_WR(HW_ESAI_SAICR_RD() |  (v)))
#define HW_ESAI_SAICR_CLR(v)    (HW_ESAI_SAICR_WR(HW_ESAI_SAICR_RD() & ~(v)))
#define HW_ESAI_SAICR_TOG(v)    (HW_ESAI_SAICR_WR(HW_ESAI_SAICR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_SAICR bitfields
 */

/* --- Register HW_ESAI_SAICR, field ALC */

#define BP_ESAI_SAICR_ALC      8
#define BM_ESAI_SAICR_ALC      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAICR_ALC(v)   ((((reg32_t) v) << 8) & BM_ESAI_SAICR_ALC)
#else
#define BF_ESAI_SAICR_ALC(v)   (((v) << 8) & BM_ESAI_SAICR_ALC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAICR_ALC(v)   BF_CS1(ESAI_SAICR, ALC, v)
#endif

/* --- Register HW_ESAI_SAICR, field TEBE */

#define BP_ESAI_SAICR_TEBE      7
#define BM_ESAI_SAICR_TEBE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAICR_TEBE(v)   ((((reg32_t) v) << 7) & BM_ESAI_SAICR_TEBE)
#else
#define BF_ESAI_SAICR_TEBE(v)   (((v) << 7) & BM_ESAI_SAICR_TEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAICR_TEBE(v)   BF_CS1(ESAI_SAICR, TEBE, v)
#endif

/* --- Register HW_ESAI_SAICR, field SYN */

#define BP_ESAI_SAICR_SYN      6
#define BM_ESAI_SAICR_SYN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAICR_SYN(v)   ((((reg32_t) v) << 6) & BM_ESAI_SAICR_SYN)
#else
#define BF_ESAI_SAICR_SYN(v)   (((v) << 6) & BM_ESAI_SAICR_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAICR_SYN(v)   BF_CS1(ESAI_SAICR, SYN, v)
#endif

/* --- Register HW_ESAI_SAICR, field OF2 */

#define BP_ESAI_SAICR_OF2      2
#define BM_ESAI_SAICR_OF2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAICR_OF2(v)   ((((reg32_t) v) << 2) & BM_ESAI_SAICR_OF2)
#else
#define BF_ESAI_SAICR_OF2(v)   (((v) << 2) & BM_ESAI_SAICR_OF2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAICR_OF2(v)   BF_CS1(ESAI_SAICR, OF2, v)
#endif

/* --- Register HW_ESAI_SAICR, field OF1 */

#define BP_ESAI_SAICR_OF1      1
#define BM_ESAI_SAICR_OF1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAICR_OF1(v)   ((((reg32_t) v) << 1) & BM_ESAI_SAICR_OF1)
#else
#define BF_ESAI_SAICR_OF1(v)   (((v) << 1) & BM_ESAI_SAICR_OF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAICR_OF1(v)   BF_CS1(ESAI_SAICR, OF1, v)
#endif

/* --- Register HW_ESAI_SAICR, field OF0 */

#define BP_ESAI_SAICR_OF0      0
#define BM_ESAI_SAICR_OF0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_SAICR_OF0(v)   ((((reg32_t) v) << 0) & BM_ESAI_SAICR_OF0)
#else
#define BF_ESAI_SAICR_OF0(v)   (((v) << 0) & BM_ESAI_SAICR_OF0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_SAICR_OF0(v)   BF_CS1(ESAI_SAICR, OF0, v)
#endif

/*
 * HW_ESAI_TCR - Transmit Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned TLIE : 1;
        unsigned TIE : 1;
        unsigned TEDIE : 1;
        unsigned TEIE : 1;
        unsigned TPR : 1;
        unsigned RESERVED1 : 1;
        unsigned PADC : 1;
        unsigned TFSR : 1;
        unsigned TFSL : 1;
        unsigned TSWS : 5;
        unsigned TMOD : 2;
        unsigned TWA : 1;
        unsigned TSHFD : 1;
        unsigned TE5 : 1;
        unsigned TE4 : 1;
        unsigned TE3 : 1;
        unsigned TE2 : 1;
        unsigned TE1 : 1;
        unsigned TE0 : 1;

    } B;
} hw_esai_tcr_t;
#endif

/*
 * constants & macros for entire ESAI_TCR register
 */
#define HW_ESAI_TCR_ADDR      (REGS_ESAI_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TCR           (*(volatile hw_esai_tcr_t *) HW_ESAI_TCR_ADDR)
#define HW_ESAI_TCR_RD()      (HW_ESAI_TCR.U)
#define HW_ESAI_TCR_WR(v)     (HW_ESAI_TCR.U = (v))
#define HW_ESAI_TCR_SET(v)    (HW_ESAI_TCR_WR(HW_ESAI_TCR_RD() |  (v)))
#define HW_ESAI_TCR_CLR(v)    (HW_ESAI_TCR_WR(HW_ESAI_TCR_RD() & ~(v)))
#define HW_ESAI_TCR_TOG(v)    (HW_ESAI_TCR_WR(HW_ESAI_TCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_TCR bitfields
 */

/* --- Register HW_ESAI_TCR, field TLIE */

#define BP_ESAI_TCR_TLIE      23
#define BM_ESAI_TCR_TLIE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TLIE(v)   ((((reg32_t) v) << 23) & BM_ESAI_TCR_TLIE)
#else
#define BF_ESAI_TCR_TLIE(v)   (((v) << 23) & BM_ESAI_TCR_TLIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TLIE(v)   BF_CS1(ESAI_TCR, TLIE, v)
#endif

/* --- Register HW_ESAI_TCR, field TIE */

#define BP_ESAI_TCR_TIE      22
#define BM_ESAI_TCR_TIE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TIE(v)   ((((reg32_t) v) << 22) & BM_ESAI_TCR_TIE)
#else
#define BF_ESAI_TCR_TIE(v)   (((v) << 22) & BM_ESAI_TCR_TIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TIE(v)   BF_CS1(ESAI_TCR, TIE, v)
#endif

/* --- Register HW_ESAI_TCR, field TEDIE */

#define BP_ESAI_TCR_TEDIE      21
#define BM_ESAI_TCR_TEDIE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TEDIE(v)   ((((reg32_t) v) << 21) & BM_ESAI_TCR_TEDIE)
#else
#define BF_ESAI_TCR_TEDIE(v)   (((v) << 21) & BM_ESAI_TCR_TEDIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TEDIE(v)   BF_CS1(ESAI_TCR, TEDIE, v)
#endif

/* --- Register HW_ESAI_TCR, field TEIE */

#define BP_ESAI_TCR_TEIE      20
#define BM_ESAI_TCR_TEIE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TEIE(v)   ((((reg32_t) v) << 20) & BM_ESAI_TCR_TEIE)
#else
#define BF_ESAI_TCR_TEIE(v)   (((v) << 20) & BM_ESAI_TCR_TEIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TEIE(v)   BF_CS1(ESAI_TCR, TEIE, v)
#endif

/* --- Register HW_ESAI_TCR, field TPR */

#define BP_ESAI_TCR_TPR      19
#define BM_ESAI_TCR_TPR      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TPR(v)   ((((reg32_t) v) << 19) & BM_ESAI_TCR_TPR)
#else
#define BF_ESAI_TCR_TPR(v)   (((v) << 19) & BM_ESAI_TCR_TPR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TPR(v)   BF_CS1(ESAI_TCR, TPR, v)
#endif

/* --- Register HW_ESAI_TCR, field PADC */

#define BP_ESAI_TCR_PADC      17
#define BM_ESAI_TCR_PADC      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_PADC(v)   ((((reg32_t) v) << 17) & BM_ESAI_TCR_PADC)
#else
#define BF_ESAI_TCR_PADC(v)   (((v) << 17) & BM_ESAI_TCR_PADC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_PADC(v)   BF_CS1(ESAI_TCR, PADC, v)
#endif

/* --- Register HW_ESAI_TCR, field TFSR */

#define BP_ESAI_TCR_TFSR      16
#define BM_ESAI_TCR_TFSR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TFSR(v)   ((((reg32_t) v) << 16) & BM_ESAI_TCR_TFSR)
#else
#define BF_ESAI_TCR_TFSR(v)   (((v) << 16) & BM_ESAI_TCR_TFSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TFSR(v)   BF_CS1(ESAI_TCR, TFSR, v)
#endif

/* --- Register HW_ESAI_TCR, field TFSL */

#define BP_ESAI_TCR_TFSL      15
#define BM_ESAI_TCR_TFSL      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TFSL(v)   ((((reg32_t) v) << 15) & BM_ESAI_TCR_TFSL)
#else
#define BF_ESAI_TCR_TFSL(v)   (((v) << 15) & BM_ESAI_TCR_TFSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TFSL(v)   BF_CS1(ESAI_TCR, TFSL, v)
#endif

/* --- Register HW_ESAI_TCR, field TSWS */

#define BP_ESAI_TCR_TSWS      10
#define BM_ESAI_TCR_TSWS      0x00007c00

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TSWS(v)   ((((reg32_t) v) << 10) & BM_ESAI_TCR_TSWS)
#else
#define BF_ESAI_TCR_TSWS(v)   (((v) << 10) & BM_ESAI_TCR_TSWS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TSWS(v)   BF_CS1(ESAI_TCR, TSWS, v)
#endif

/* --- Register HW_ESAI_TCR, field TMOD */

#define BP_ESAI_TCR_TMOD      8
#define BM_ESAI_TCR_TMOD      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TMOD(v)   ((((reg32_t) v) << 8) & BM_ESAI_TCR_TMOD)
#else
#define BF_ESAI_TCR_TMOD(v)   (((v) << 8) & BM_ESAI_TCR_TMOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TMOD(v)   BF_CS1(ESAI_TCR, TMOD, v)
#endif

/* --- Register HW_ESAI_TCR, field TWA */

#define BP_ESAI_TCR_TWA      7
#define BM_ESAI_TCR_TWA      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TWA(v)   ((((reg32_t) v) << 7) & BM_ESAI_TCR_TWA)
#else
#define BF_ESAI_TCR_TWA(v)   (((v) << 7) & BM_ESAI_TCR_TWA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TWA(v)   BF_CS1(ESAI_TCR, TWA, v)
#endif

/* --- Register HW_ESAI_TCR, field TSHFD */

#define BP_ESAI_TCR_TSHFD      6
#define BM_ESAI_TCR_TSHFD      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TSHFD(v)   ((((reg32_t) v) << 6) & BM_ESAI_TCR_TSHFD)
#else
#define BF_ESAI_TCR_TSHFD(v)   (((v) << 6) & BM_ESAI_TCR_TSHFD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TSHFD(v)   BF_CS1(ESAI_TCR, TSHFD, v)
#endif

/* --- Register HW_ESAI_TCR, field TE5 */

#define BP_ESAI_TCR_TE5      5
#define BM_ESAI_TCR_TE5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TE5(v)   ((((reg32_t) v) << 5) & BM_ESAI_TCR_TE5)
#else
#define BF_ESAI_TCR_TE5(v)   (((v) << 5) & BM_ESAI_TCR_TE5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TE5(v)   BF_CS1(ESAI_TCR, TE5, v)
#endif

/* --- Register HW_ESAI_TCR, field TE4 */

#define BP_ESAI_TCR_TE4      4
#define BM_ESAI_TCR_TE4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TE4(v)   ((((reg32_t) v) << 4) & BM_ESAI_TCR_TE4)
#else
#define BF_ESAI_TCR_TE4(v)   (((v) << 4) & BM_ESAI_TCR_TE4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TE4(v)   BF_CS1(ESAI_TCR, TE4, v)
#endif

/* --- Register HW_ESAI_TCR, field TE3 */

#define BP_ESAI_TCR_TE3      3
#define BM_ESAI_TCR_TE3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TE3(v)   ((((reg32_t) v) << 3) & BM_ESAI_TCR_TE3)
#else
#define BF_ESAI_TCR_TE3(v)   (((v) << 3) & BM_ESAI_TCR_TE3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TE3(v)   BF_CS1(ESAI_TCR, TE3, v)
#endif

/* --- Register HW_ESAI_TCR, field TE2 */

#define BP_ESAI_TCR_TE2      2
#define BM_ESAI_TCR_TE2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TE2(v)   ((((reg32_t) v) << 2) & BM_ESAI_TCR_TE2)
#else
#define BF_ESAI_TCR_TE2(v)   (((v) << 2) & BM_ESAI_TCR_TE2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TE2(v)   BF_CS1(ESAI_TCR, TE2, v)
#endif

/* --- Register HW_ESAI_TCR, field TE1 */

#define BP_ESAI_TCR_TE1      1
#define BM_ESAI_TCR_TE1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TE1(v)   ((((reg32_t) v) << 1) & BM_ESAI_TCR_TE1)
#else
#define BF_ESAI_TCR_TE1(v)   (((v) << 1) & BM_ESAI_TCR_TE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TE1(v)   BF_CS1(ESAI_TCR, TE1, v)
#endif

/* --- Register HW_ESAI_TCR, field TE0 */

#define BP_ESAI_TCR_TE0      0
#define BM_ESAI_TCR_TE0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCR_TE0(v)   ((((reg32_t) v) << 0) & BM_ESAI_TCR_TE0)
#else
#define BF_ESAI_TCR_TE0(v)   (((v) << 0) & BM_ESAI_TCR_TE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCR_TE0(v)   BF_CS1(ESAI_TCR, TE0, v)
#endif

/*
 * HW_ESAI_TCCR - Transmit Clock Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned THCKD : 1;
        unsigned TFSD : 1;
        unsigned TCKD : 1;
        unsigned THCKP : 1;
        unsigned TFSP : 1;
        unsigned TCKP : 1;
        unsigned TFP : 4;
        unsigned TDC : 5;
        unsigned TPSR : 1;
        unsigned TPM : 8;

    } B;
} hw_esai_tccr_t;
#endif

/*
 * constants & macros for entire ESAI_TCCR register
 */
#define HW_ESAI_TCCR_ADDR      (REGS_ESAI_BASE + 0xd8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TCCR           (*(volatile hw_esai_tccr_t *) HW_ESAI_TCCR_ADDR)
#define HW_ESAI_TCCR_RD()      (HW_ESAI_TCCR.U)
#define HW_ESAI_TCCR_WR(v)     (HW_ESAI_TCCR.U = (v))
#define HW_ESAI_TCCR_SET(v)    (HW_ESAI_TCCR_WR(HW_ESAI_TCCR_RD() |  (v)))
#define HW_ESAI_TCCR_CLR(v)    (HW_ESAI_TCCR_WR(HW_ESAI_TCCR_RD() & ~(v)))
#define HW_ESAI_TCCR_TOG(v)    (HW_ESAI_TCCR_WR(HW_ESAI_TCCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_TCCR bitfields
 */

/* --- Register HW_ESAI_TCCR, field THCKD */

#define BP_ESAI_TCCR_THCKD      23
#define BM_ESAI_TCCR_THCKD      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_THCKD(v)   ((((reg32_t) v) << 23) & BM_ESAI_TCCR_THCKD)
#else
#define BF_ESAI_TCCR_THCKD(v)   (((v) << 23) & BM_ESAI_TCCR_THCKD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_THCKD(v)   BF_CS1(ESAI_TCCR, THCKD, v)
#endif

/* --- Register HW_ESAI_TCCR, field TFSD */

#define BP_ESAI_TCCR_TFSD      22
#define BM_ESAI_TCCR_TFSD      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_TFSD(v)   ((((reg32_t) v) << 22) & BM_ESAI_TCCR_TFSD)
#else
#define BF_ESAI_TCCR_TFSD(v)   (((v) << 22) & BM_ESAI_TCCR_TFSD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_TFSD(v)   BF_CS1(ESAI_TCCR, TFSD, v)
#endif

/* --- Register HW_ESAI_TCCR, field TCKD */

#define BP_ESAI_TCCR_TCKD      21
#define BM_ESAI_TCCR_TCKD      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_TCKD(v)   ((((reg32_t) v) << 21) & BM_ESAI_TCCR_TCKD)
#else
#define BF_ESAI_TCCR_TCKD(v)   (((v) << 21) & BM_ESAI_TCCR_TCKD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_TCKD(v)   BF_CS1(ESAI_TCCR, TCKD, v)
#endif

/* --- Register HW_ESAI_TCCR, field THCKP */

#define BP_ESAI_TCCR_THCKP      20
#define BM_ESAI_TCCR_THCKP      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_THCKP(v)   ((((reg32_t) v) << 20) & BM_ESAI_TCCR_THCKP)
#else
#define BF_ESAI_TCCR_THCKP(v)   (((v) << 20) & BM_ESAI_TCCR_THCKP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_THCKP(v)   BF_CS1(ESAI_TCCR, THCKP, v)
#endif

/* --- Register HW_ESAI_TCCR, field TFSP */

#define BP_ESAI_TCCR_TFSP      19
#define BM_ESAI_TCCR_TFSP      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_TFSP(v)   ((((reg32_t) v) << 19) & BM_ESAI_TCCR_TFSP)
#else
#define BF_ESAI_TCCR_TFSP(v)   (((v) << 19) & BM_ESAI_TCCR_TFSP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_TFSP(v)   BF_CS1(ESAI_TCCR, TFSP, v)
#endif

/* --- Register HW_ESAI_TCCR, field TCKP */

#define BP_ESAI_TCCR_TCKP      18
#define BM_ESAI_TCCR_TCKP      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_TCKP(v)   ((((reg32_t) v) << 18) & BM_ESAI_TCCR_TCKP)
#else
#define BF_ESAI_TCCR_TCKP(v)   (((v) << 18) & BM_ESAI_TCCR_TCKP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_TCKP(v)   BF_CS1(ESAI_TCCR, TCKP, v)
#endif

/* --- Register HW_ESAI_TCCR, field TFP */

#define BP_ESAI_TCCR_TFP      14
#define BM_ESAI_TCCR_TFP      0x0003c000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_TFP(v)   ((((reg32_t) v) << 14) & BM_ESAI_TCCR_TFP)
#else
#define BF_ESAI_TCCR_TFP(v)   (((v) << 14) & BM_ESAI_TCCR_TFP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_TFP(v)   BF_CS1(ESAI_TCCR, TFP, v)
#endif

/* --- Register HW_ESAI_TCCR, field TDC */

#define BP_ESAI_TCCR_TDC      9
#define BM_ESAI_TCCR_TDC      0x00003e00

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_TDC(v)   ((((reg32_t) v) << 9) & BM_ESAI_TCCR_TDC)
#else
#define BF_ESAI_TCCR_TDC(v)   (((v) << 9) & BM_ESAI_TCCR_TDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_TDC(v)   BF_CS1(ESAI_TCCR, TDC, v)
#endif

/* --- Register HW_ESAI_TCCR, field TPSR */

#define BP_ESAI_TCCR_TPSR      8
#define BM_ESAI_TCCR_TPSR      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_TPSR(v)   ((((reg32_t) v) << 8) & BM_ESAI_TCCR_TPSR)
#else
#define BF_ESAI_TCCR_TPSR(v)   (((v) << 8) & BM_ESAI_TCCR_TPSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_TPSR(v)   BF_CS1(ESAI_TCCR, TPSR, v)
#endif

/* --- Register HW_ESAI_TCCR, field TPM */

#define BP_ESAI_TCCR_TPM      0
#define BM_ESAI_TCCR_TPM      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TCCR_TPM(v)   ((((reg32_t) v) << 0) & BM_ESAI_TCCR_TPM)
#else
#define BF_ESAI_TCCR_TPM(v)   (((v) << 0) & BM_ESAI_TCCR_TPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TCCR_TPM(v)   BF_CS1(ESAI_TCCR, TPM, v)
#endif

/*
 * HW_ESAI_RCR - Receive Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RLIE : 1;
        unsigned RIE : 1;
        unsigned REDIE : 1;
        unsigned REIE : 1;
        unsigned RPR : 1;
        unsigned RESERVED1 : 2;
        unsigned RFSR : 1;
        unsigned RFSL : 1;
        unsigned RSWS : 5;
        unsigned RMOD : 2;
        unsigned RWA : 1;
        unsigned RSHFD : 1;
        unsigned RESERVED2 : 2;
        unsigned RE3 : 1;
        unsigned RE2 : 1;
        unsigned RE1 : 1;
        unsigned RE0 : 1;

    } B;
} hw_esai_rcr_t;
#endif

/*
 * constants & macros for entire ESAI_RCR register
 */
#define HW_ESAI_RCR_ADDR      (REGS_ESAI_BASE + 0xdc)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RCR           (*(volatile hw_esai_rcr_t *) HW_ESAI_RCR_ADDR)
#define HW_ESAI_RCR_RD()      (HW_ESAI_RCR.U)
#define HW_ESAI_RCR_WR(v)     (HW_ESAI_RCR.U = (v))
#define HW_ESAI_RCR_SET(v)    (HW_ESAI_RCR_WR(HW_ESAI_RCR_RD() |  (v)))
#define HW_ESAI_RCR_CLR(v)    (HW_ESAI_RCR_WR(HW_ESAI_RCR_RD() & ~(v)))
#define HW_ESAI_RCR_TOG(v)    (HW_ESAI_RCR_WR(HW_ESAI_RCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_RCR bitfields
 */

/* --- Register HW_ESAI_RCR, field RLIE */

#define BP_ESAI_RCR_RLIE      23
#define BM_ESAI_RCR_RLIE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RLIE(v)   ((((reg32_t) v) << 23) & BM_ESAI_RCR_RLIE)
#else
#define BF_ESAI_RCR_RLIE(v)   (((v) << 23) & BM_ESAI_RCR_RLIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RLIE(v)   BF_CS1(ESAI_RCR, RLIE, v)
#endif

/* --- Register HW_ESAI_RCR, field RIE */

#define BP_ESAI_RCR_RIE      22
#define BM_ESAI_RCR_RIE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RIE(v)   ((((reg32_t) v) << 22) & BM_ESAI_RCR_RIE)
#else
#define BF_ESAI_RCR_RIE(v)   (((v) << 22) & BM_ESAI_RCR_RIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RIE(v)   BF_CS1(ESAI_RCR, RIE, v)
#endif

/* --- Register HW_ESAI_RCR, field REDIE */

#define BP_ESAI_RCR_REDIE      21
#define BM_ESAI_RCR_REDIE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_REDIE(v)   ((((reg32_t) v) << 21) & BM_ESAI_RCR_REDIE)
#else
#define BF_ESAI_RCR_REDIE(v)   (((v) << 21) & BM_ESAI_RCR_REDIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_REDIE(v)   BF_CS1(ESAI_RCR, REDIE, v)
#endif

/* --- Register HW_ESAI_RCR, field REIE */

#define BP_ESAI_RCR_REIE      20
#define BM_ESAI_RCR_REIE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_REIE(v)   ((((reg32_t) v) << 20) & BM_ESAI_RCR_REIE)
#else
#define BF_ESAI_RCR_REIE(v)   (((v) << 20) & BM_ESAI_RCR_REIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_REIE(v)   BF_CS1(ESAI_RCR, REIE, v)
#endif

/* --- Register HW_ESAI_RCR, field RPR */

#define BP_ESAI_RCR_RPR      19
#define BM_ESAI_RCR_RPR      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RPR(v)   ((((reg32_t) v) << 19) & BM_ESAI_RCR_RPR)
#else
#define BF_ESAI_RCR_RPR(v)   (((v) << 19) & BM_ESAI_RCR_RPR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RPR(v)   BF_CS1(ESAI_RCR, RPR, v)
#endif

/* --- Register HW_ESAI_RCR, field RFSR */

#define BP_ESAI_RCR_RFSR      16
#define BM_ESAI_RCR_RFSR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RFSR(v)   ((((reg32_t) v) << 16) & BM_ESAI_RCR_RFSR)
#else
#define BF_ESAI_RCR_RFSR(v)   (((v) << 16) & BM_ESAI_RCR_RFSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RFSR(v)   BF_CS1(ESAI_RCR, RFSR, v)
#endif

/* --- Register HW_ESAI_RCR, field RFSL */

#define BP_ESAI_RCR_RFSL      15
#define BM_ESAI_RCR_RFSL      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RFSL(v)   ((((reg32_t) v) << 15) & BM_ESAI_RCR_RFSL)
#else
#define BF_ESAI_RCR_RFSL(v)   (((v) << 15) & BM_ESAI_RCR_RFSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RFSL(v)   BF_CS1(ESAI_RCR, RFSL, v)
#endif

/* --- Register HW_ESAI_RCR, field RSWS */

#define BP_ESAI_RCR_RSWS      10
#define BM_ESAI_RCR_RSWS      0x00007c00

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RSWS(v)   ((((reg32_t) v) << 10) & BM_ESAI_RCR_RSWS)
#else
#define BF_ESAI_RCR_RSWS(v)   (((v) << 10) & BM_ESAI_RCR_RSWS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RSWS(v)   BF_CS1(ESAI_RCR, RSWS, v)
#endif

/* --- Register HW_ESAI_RCR, field RMOD */

#define BP_ESAI_RCR_RMOD      8
#define BM_ESAI_RCR_RMOD      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RMOD(v)   ((((reg32_t) v) << 8) & BM_ESAI_RCR_RMOD)
#else
#define BF_ESAI_RCR_RMOD(v)   (((v) << 8) & BM_ESAI_RCR_RMOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RMOD(v)   BF_CS1(ESAI_RCR, RMOD, v)
#endif

/* --- Register HW_ESAI_RCR, field RWA */

#define BP_ESAI_RCR_RWA      7
#define BM_ESAI_RCR_RWA      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RWA(v)   ((((reg32_t) v) << 7) & BM_ESAI_RCR_RWA)
#else
#define BF_ESAI_RCR_RWA(v)   (((v) << 7) & BM_ESAI_RCR_RWA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RWA(v)   BF_CS1(ESAI_RCR, RWA, v)
#endif

/* --- Register HW_ESAI_RCR, field RSHFD */

#define BP_ESAI_RCR_RSHFD      6
#define BM_ESAI_RCR_RSHFD      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RSHFD(v)   ((((reg32_t) v) << 6) & BM_ESAI_RCR_RSHFD)
#else
#define BF_ESAI_RCR_RSHFD(v)   (((v) << 6) & BM_ESAI_RCR_RSHFD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RSHFD(v)   BF_CS1(ESAI_RCR, RSHFD, v)
#endif

/* --- Register HW_ESAI_RCR, field RE3 */

#define BP_ESAI_RCR_RE3      3
#define BM_ESAI_RCR_RE3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RE3(v)   ((((reg32_t) v) << 3) & BM_ESAI_RCR_RE3)
#else
#define BF_ESAI_RCR_RE3(v)   (((v) << 3) & BM_ESAI_RCR_RE3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RE3(v)   BF_CS1(ESAI_RCR, RE3, v)
#endif

/* --- Register HW_ESAI_RCR, field RE2 */

#define BP_ESAI_RCR_RE2      2
#define BM_ESAI_RCR_RE2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RE2(v)   ((((reg32_t) v) << 2) & BM_ESAI_RCR_RE2)
#else
#define BF_ESAI_RCR_RE2(v)   (((v) << 2) & BM_ESAI_RCR_RE2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RE2(v)   BF_CS1(ESAI_RCR, RE2, v)
#endif

/* --- Register HW_ESAI_RCR, field RE1 */

#define BP_ESAI_RCR_RE1      1
#define BM_ESAI_RCR_RE1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RE1(v)   ((((reg32_t) v) << 1) & BM_ESAI_RCR_RE1)
#else
#define BF_ESAI_RCR_RE1(v)   (((v) << 1) & BM_ESAI_RCR_RE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RE1(v)   BF_CS1(ESAI_RCR, RE1, v)
#endif

/* --- Register HW_ESAI_RCR, field RE0 */

#define BP_ESAI_RCR_RE0      0
#define BM_ESAI_RCR_RE0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCR_RE0(v)   ((((reg32_t) v) << 0) & BM_ESAI_RCR_RE0)
#else
#define BF_ESAI_RCR_RE0(v)   (((v) << 0) & BM_ESAI_RCR_RE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCR_RE0(v)   BF_CS1(ESAI_RCR, RE0, v)
#endif

/*
 * HW_ESAI_RCCR - Receive Clock Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RHCKD : 1;
        unsigned RFSD : 1;
        unsigned RCKD : 1;
        unsigned RHCKP : 1;
        unsigned RFSP : 1;
        unsigned RCKP : 1;
        unsigned RFP : 4;
        unsigned RDC : 5;
        unsigned RPSP : 1;
        unsigned RPM : 8;

    } B;
} hw_esai_rccr_t;
#endif

/*
 * constants & macros for entire ESAI_RCCR register
 */
#define HW_ESAI_RCCR_ADDR      (REGS_ESAI_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RCCR           (*(volatile hw_esai_rccr_t *) HW_ESAI_RCCR_ADDR)
#define HW_ESAI_RCCR_RD()      (HW_ESAI_RCCR.U)
#define HW_ESAI_RCCR_WR(v)     (HW_ESAI_RCCR.U = (v))
#define HW_ESAI_RCCR_SET(v)    (HW_ESAI_RCCR_WR(HW_ESAI_RCCR_RD() |  (v)))
#define HW_ESAI_RCCR_CLR(v)    (HW_ESAI_RCCR_WR(HW_ESAI_RCCR_RD() & ~(v)))
#define HW_ESAI_RCCR_TOG(v)    (HW_ESAI_RCCR_WR(HW_ESAI_RCCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_RCCR bitfields
 */

/* --- Register HW_ESAI_RCCR, field RHCKD */

#define BP_ESAI_RCCR_RHCKD      23
#define BM_ESAI_RCCR_RHCKD      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RHCKD(v)   ((((reg32_t) v) << 23) & BM_ESAI_RCCR_RHCKD)
#else
#define BF_ESAI_RCCR_RHCKD(v)   (((v) << 23) & BM_ESAI_RCCR_RHCKD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RHCKD(v)   BF_CS1(ESAI_RCCR, RHCKD, v)
#endif

/* --- Register HW_ESAI_RCCR, field RFSD */

#define BP_ESAI_RCCR_RFSD      22
#define BM_ESAI_RCCR_RFSD      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RFSD(v)   ((((reg32_t) v) << 22) & BM_ESAI_RCCR_RFSD)
#else
#define BF_ESAI_RCCR_RFSD(v)   (((v) << 22) & BM_ESAI_RCCR_RFSD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RFSD(v)   BF_CS1(ESAI_RCCR, RFSD, v)
#endif

/* --- Register HW_ESAI_RCCR, field RCKD */

#define BP_ESAI_RCCR_RCKD      21
#define BM_ESAI_RCCR_RCKD      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RCKD(v)   ((((reg32_t) v) << 21) & BM_ESAI_RCCR_RCKD)
#else
#define BF_ESAI_RCCR_RCKD(v)   (((v) << 21) & BM_ESAI_RCCR_RCKD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RCKD(v)   BF_CS1(ESAI_RCCR, RCKD, v)
#endif

/* --- Register HW_ESAI_RCCR, field RHCKP */

#define BP_ESAI_RCCR_RHCKP      20
#define BM_ESAI_RCCR_RHCKP      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RHCKP(v)   ((((reg32_t) v) << 20) & BM_ESAI_RCCR_RHCKP)
#else
#define BF_ESAI_RCCR_RHCKP(v)   (((v) << 20) & BM_ESAI_RCCR_RHCKP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RHCKP(v)   BF_CS1(ESAI_RCCR, RHCKP, v)
#endif

/* --- Register HW_ESAI_RCCR, field RFSP */

#define BP_ESAI_RCCR_RFSP      19
#define BM_ESAI_RCCR_RFSP      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RFSP(v)   ((((reg32_t) v) << 19) & BM_ESAI_RCCR_RFSP)
#else
#define BF_ESAI_RCCR_RFSP(v)   (((v) << 19) & BM_ESAI_RCCR_RFSP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RFSP(v)   BF_CS1(ESAI_RCCR, RFSP, v)
#endif

/* --- Register HW_ESAI_RCCR, field RCKP */

#define BP_ESAI_RCCR_RCKP      18
#define BM_ESAI_RCCR_RCKP      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RCKP(v)   ((((reg32_t) v) << 18) & BM_ESAI_RCCR_RCKP)
#else
#define BF_ESAI_RCCR_RCKP(v)   (((v) << 18) & BM_ESAI_RCCR_RCKP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RCKP(v)   BF_CS1(ESAI_RCCR, RCKP, v)
#endif

/* --- Register HW_ESAI_RCCR, field RFP */

#define BP_ESAI_RCCR_RFP      14
#define BM_ESAI_RCCR_RFP      0x0003c000

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RFP(v)   ((((reg32_t) v) << 14) & BM_ESAI_RCCR_RFP)
#else
#define BF_ESAI_RCCR_RFP(v)   (((v) << 14) & BM_ESAI_RCCR_RFP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RFP(v)   BF_CS1(ESAI_RCCR, RFP, v)
#endif

/* --- Register HW_ESAI_RCCR, field RDC */

#define BP_ESAI_RCCR_RDC      9
#define BM_ESAI_RCCR_RDC      0x00003e00

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RDC(v)   ((((reg32_t) v) << 9) & BM_ESAI_RCCR_RDC)
#else
#define BF_ESAI_RCCR_RDC(v)   (((v) << 9) & BM_ESAI_RCCR_RDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RDC(v)   BF_CS1(ESAI_RCCR, RDC, v)
#endif

/* --- Register HW_ESAI_RCCR, field RPSP */

#define BP_ESAI_RCCR_RPSP      8
#define BM_ESAI_RCCR_RPSP      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RPSP(v)   ((((reg32_t) v) << 8) & BM_ESAI_RCCR_RPSP)
#else
#define BF_ESAI_RCCR_RPSP(v)   (((v) << 8) & BM_ESAI_RCCR_RPSP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RPSP(v)   BF_CS1(ESAI_RCCR, RPSP, v)
#endif

/* --- Register HW_ESAI_RCCR, field RPM */

#define BP_ESAI_RCCR_RPM      0
#define BM_ESAI_RCCR_RPM      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RCCR_RPM(v)   ((((reg32_t) v) << 0) & BM_ESAI_RCCR_RPM)
#else
#define BF_ESAI_RCCR_RPM(v)   (((v) << 0) & BM_ESAI_RCCR_RPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RCCR_RPM(v)   BF_CS1(ESAI_RCCR, RPM, v)
#endif

/*
 * HW_ESAI_TSMA - Transmit Slot Mask Register A
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned TS : 16;

    } B;
} hw_esai_tsma_t;
#endif

/*
 * constants & macros for entire ESAI_TSMA register
 */
#define HW_ESAI_TSMA_ADDR      (REGS_ESAI_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TSMA           (*(volatile hw_esai_tsma_t *) HW_ESAI_TSMA_ADDR)
#define HW_ESAI_TSMA_RD()      (HW_ESAI_TSMA.U)
#define HW_ESAI_TSMA_WR(v)     (HW_ESAI_TSMA.U = (v))
#define HW_ESAI_TSMA_SET(v)    (HW_ESAI_TSMA_WR(HW_ESAI_TSMA_RD() |  (v)))
#define HW_ESAI_TSMA_CLR(v)    (HW_ESAI_TSMA_WR(HW_ESAI_TSMA_RD() & ~(v)))
#define HW_ESAI_TSMA_TOG(v)    (HW_ESAI_TSMA_WR(HW_ESAI_TSMA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_TSMA bitfields
 */

/* --- Register HW_ESAI_TSMA, field TS */

#define BP_ESAI_TSMA_TS      0
#define BM_ESAI_TSMA_TS      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TSMA_TS(v)   ((((reg32_t) v) << 0) & BM_ESAI_TSMA_TS)
#else
#define BF_ESAI_TSMA_TS(v)   (((v) << 0) & BM_ESAI_TSMA_TS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TSMA_TS(v)   BF_CS1(ESAI_TSMA, TS, v)
#endif

/*
 * HW_ESAI_TSMB - Transmit Slot Mask Register B
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned TS : 16;

    } B;
} hw_esai_tsmb_t;
#endif

/*
 * constants & macros for entire ESAI_TSMB register
 */
#define HW_ESAI_TSMB_ADDR      (REGS_ESAI_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TSMB           (*(volatile hw_esai_tsmb_t *) HW_ESAI_TSMB_ADDR)
#define HW_ESAI_TSMB_RD()      (HW_ESAI_TSMB.U)
#define HW_ESAI_TSMB_WR(v)     (HW_ESAI_TSMB.U = (v))
#define HW_ESAI_TSMB_SET(v)    (HW_ESAI_TSMB_WR(HW_ESAI_TSMB_RD() |  (v)))
#define HW_ESAI_TSMB_CLR(v)    (HW_ESAI_TSMB_WR(HW_ESAI_TSMB_RD() & ~(v)))
#define HW_ESAI_TSMB_TOG(v)    (HW_ESAI_TSMB_WR(HW_ESAI_TSMB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_TSMB bitfields
 */

/* --- Register HW_ESAI_TSMB, field TS */

#define BP_ESAI_TSMB_TS      0
#define BM_ESAI_TSMB_TS      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_TSMB_TS(v)   ((((reg32_t) v) << 0) & BM_ESAI_TSMB_TS)
#else
#define BF_ESAI_TSMB_TS(v)   (((v) << 0) & BM_ESAI_TSMB_TS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_TSMB_TS(v)   BF_CS1(ESAI_TSMB, TS, v)
#endif

/*
 * HW_ESAI_RSMA - Receive Slot Mask Register A
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RS : 16;

    } B;
} hw_esai_rsma_t;
#endif

/*
 * constants & macros for entire ESAI_RSMA register
 */
#define HW_ESAI_RSMA_ADDR      (REGS_ESAI_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RSMA           (*(volatile hw_esai_rsma_t *) HW_ESAI_RSMA_ADDR)
#define HW_ESAI_RSMA_RD()      (HW_ESAI_RSMA.U)
#define HW_ESAI_RSMA_WR(v)     (HW_ESAI_RSMA.U = (v))
#define HW_ESAI_RSMA_SET(v)    (HW_ESAI_RSMA_WR(HW_ESAI_RSMA_RD() |  (v)))
#define HW_ESAI_RSMA_CLR(v)    (HW_ESAI_RSMA_WR(HW_ESAI_RSMA_RD() & ~(v)))
#define HW_ESAI_RSMA_TOG(v)    (HW_ESAI_RSMA_WR(HW_ESAI_RSMA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_RSMA bitfields
 */

/* --- Register HW_ESAI_RSMA, field RS */

#define BP_ESAI_RSMA_RS      0
#define BM_ESAI_RSMA_RS      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RSMA_RS(v)   ((((reg32_t) v) << 0) & BM_ESAI_RSMA_RS)
#else
#define BF_ESAI_RSMA_RS(v)   (((v) << 0) & BM_ESAI_RSMA_RS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RSMA_RS(v)   BF_CS1(ESAI_RSMA, RS, v)
#endif

/*
 * HW_ESAI_RSMB - Receive Slot Mask Register B
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RS : 16;

    } B;
} hw_esai_rsmb_t;
#endif

/*
 * constants & macros for entire ESAI_RSMB register
 */
#define HW_ESAI_RSMB_ADDR      (REGS_ESAI_BASE + 0xf0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RSMB           (*(volatile hw_esai_rsmb_t *) HW_ESAI_RSMB_ADDR)
#define HW_ESAI_RSMB_RD()      (HW_ESAI_RSMB.U)
#define HW_ESAI_RSMB_WR(v)     (HW_ESAI_RSMB.U = (v))
#define HW_ESAI_RSMB_SET(v)    (HW_ESAI_RSMB_WR(HW_ESAI_RSMB_RD() |  (v)))
#define HW_ESAI_RSMB_CLR(v)    (HW_ESAI_RSMB_WR(HW_ESAI_RSMB_RD() & ~(v)))
#define HW_ESAI_RSMB_TOG(v)    (HW_ESAI_RSMB_WR(HW_ESAI_RSMB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_RSMB bitfields
 */

/* --- Register HW_ESAI_RSMB, field RS */

#define BP_ESAI_RSMB_RS      0
#define BM_ESAI_RSMB_RS      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_RSMB_RS(v)   ((((reg32_t) v) << 0) & BM_ESAI_RSMB_RS)
#else
#define BF_ESAI_RSMB_RS(v)   (((v) << 0) & BM_ESAI_RSMB_RS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_RSMB_RS(v)   BF_CS1(ESAI_RSMB, RS, v)
#endif

/*
 * HW_ESAI_PDRC - Port C Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20;
        unsigned PD : 12;

    } B;
} hw_esai_pdrc_t;
#endif

/*
 * constants & macros for entire ESAI_PDRC register
 */
#define HW_ESAI_PDRC_ADDR      (REGS_ESAI_BASE + 0xf4)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_PDRC           (*(volatile hw_esai_pdrc_t *) HW_ESAI_PDRC_ADDR)
#define HW_ESAI_PDRC_RD()      (HW_ESAI_PDRC.U)
#define HW_ESAI_PDRC_WR(v)     (HW_ESAI_PDRC.U = (v))
#define HW_ESAI_PDRC_SET(v)    (HW_ESAI_PDRC_WR(HW_ESAI_PDRC_RD() |  (v)))
#define HW_ESAI_PDRC_CLR(v)    (HW_ESAI_PDRC_WR(HW_ESAI_PDRC_RD() & ~(v)))
#define HW_ESAI_PDRC_TOG(v)    (HW_ESAI_PDRC_WR(HW_ESAI_PDRC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_PDRC bitfields
 */

/* --- Register HW_ESAI_PDRC, field PD */

#define BP_ESAI_PDRC_PD      0
#define BM_ESAI_PDRC_PD      0x00000fff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_PDRC_PD(v)   ((((reg32_t) v) << 0) & BM_ESAI_PDRC_PD)
#else
#define BF_ESAI_PDRC_PD(v)   (((v) << 0) & BM_ESAI_PDRC_PD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_PDRC_PD(v)   BF_CS1(ESAI_PDRC, PD, v)
#endif

/*
 * HW_ESAI_PRRC - Port C Direction Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20;
        unsigned PDC : 12;

    } B;
} hw_esai_prrc_t;
#endif

/*
 * constants & macros for entire ESAI_PRRC register
 */
#define HW_ESAI_PRRC_ADDR      (REGS_ESAI_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_PRRC           (*(volatile hw_esai_prrc_t *) HW_ESAI_PRRC_ADDR)
#define HW_ESAI_PRRC_RD()      (HW_ESAI_PRRC.U)
#define HW_ESAI_PRRC_WR(v)     (HW_ESAI_PRRC.U = (v))
#define HW_ESAI_PRRC_SET(v)    (HW_ESAI_PRRC_WR(HW_ESAI_PRRC_RD() |  (v)))
#define HW_ESAI_PRRC_CLR(v)    (HW_ESAI_PRRC_WR(HW_ESAI_PRRC_RD() & ~(v)))
#define HW_ESAI_PRRC_TOG(v)    (HW_ESAI_PRRC_WR(HW_ESAI_PRRC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_PRRC bitfields
 */

/* --- Register HW_ESAI_PRRC, field PDC */

#define BP_ESAI_PRRC_PDC      0
#define BM_ESAI_PRRC_PDC      0x00000fff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_PRRC_PDC(v)   ((((reg32_t) v) << 0) & BM_ESAI_PRRC_PDC)
#else
#define BF_ESAI_PRRC_PDC(v)   (((v) << 0) & BM_ESAI_PRRC_PDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_PRRC_PDC(v)   BF_CS1(ESAI_PRRC, PDC, v)
#endif

/*
 * HW_ESAI_PCRC - Port C Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20;
        unsigned PC : 12;

    } B;
} hw_esai_pcrc_t;
#endif

/*
 * constants & macros for entire ESAI_PCRC register
 */
#define HW_ESAI_PCRC_ADDR      (REGS_ESAI_BASE + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_PCRC           (*(volatile hw_esai_pcrc_t *) HW_ESAI_PCRC_ADDR)
#define HW_ESAI_PCRC_RD()      (HW_ESAI_PCRC.U)
#define HW_ESAI_PCRC_WR(v)     (HW_ESAI_PCRC.U = (v))
#define HW_ESAI_PCRC_SET(v)    (HW_ESAI_PCRC_WR(HW_ESAI_PCRC_RD() |  (v)))
#define HW_ESAI_PCRC_CLR(v)    (HW_ESAI_PCRC_WR(HW_ESAI_PCRC_RD() & ~(v)))
#define HW_ESAI_PCRC_TOG(v)    (HW_ESAI_PCRC_WR(HW_ESAI_PCRC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ESAI_PCRC bitfields
 */

/* --- Register HW_ESAI_PCRC, field PC */

#define BP_ESAI_PCRC_PC      0
#define BM_ESAI_PCRC_PC      0x00000fff

#ifndef __LANGUAGE_ASM__
#define BF_ESAI_PCRC_PC(v)   ((((reg32_t) v) << 0) & BM_ESAI_PCRC_PC)
#else
#define BF_ESAI_PCRC_PC(v)   (((v) << 0) & BM_ESAI_PCRC_PC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ESAI_PCRC_PC(v)   BF_CS1(ESAI_PCRC, PC, v)
#endif


#endif // _ESAI_H

