/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _GPT_H
#define _GPT_H

#include "regs.h"

#ifndef REGS_GPT_BASE
#define REGS_GPT_BASE (REGS_BASE + 0x02098000)

#endif


/*
 * HW_GPT_CR - GPT Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FO3 : 1;
        unsigned FO2 : 1;
        unsigned FO1 : 1;
        unsigned OM3 : 3;
        unsigned OM2 : 3;
        unsigned OM1 : 3;
        unsigned IM2 : 2;
        unsigned IM1 : 2;
        unsigned SWR : 1;
        unsigned RESERVED0 : 5;
        unsigned FRR : 1;
        unsigned CLKSRC : 3;
        unsigned STOPEN : 1;
        unsigned DOZEEN : 1;
        unsigned WAITEN : 1;
        unsigned DBGEN : 1;
        unsigned ENMOD : 1;
        unsigned EN : 1;

    } B;
} hw_gpt_cr_t;
#endif

/*
 * constants & macros for entire GPT_CR register
 */
#define HW_GPT_CR_ADDR      (REGS_GPT_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_CR           (*(volatile hw_gpt_cr_t *) HW_GPT_CR_ADDR)
#define HW_GPT_CR_RD()      (HW_GPT_CR.U)
#define HW_GPT_CR_WR(v)     (HW_GPT_CR.U = (v))
#define HW_GPT_CR_SET(v)    (HW_GPT_CR_WR(HW_GPT_CR_RD() |  (v)))
#define HW_GPT_CR_CLR(v)    (HW_GPT_CR_WR(HW_GPT_CR_RD() & ~(v)))
#define HW_GPT_CR_TOG(v)    (HW_GPT_CR_WR(HW_GPT_CR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_CR bitfields
 */

/* --- Register HW_GPT_CR, field FO3 */

#define BP_GPT_CR_FO3      31
#define BM_GPT_CR_FO3      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_FO3(v)   ((((reg32_t) v) << 31) & BM_GPT_CR_FO3)
#else
#define BF_GPT_CR_FO3(v)   (((v) << 31) & BM_GPT_CR_FO3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_FO3(v)   BF_CS1(GPT_CR, FO3, v)
#endif

/* --- Register HW_GPT_CR, field FO2 */

#define BP_GPT_CR_FO2      30
#define BM_GPT_CR_FO2      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_FO2(v)   ((((reg32_t) v) << 30) & BM_GPT_CR_FO2)
#else
#define BF_GPT_CR_FO2(v)   (((v) << 30) & BM_GPT_CR_FO2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_FO2(v)   BF_CS1(GPT_CR, FO2, v)
#endif

/* --- Register HW_GPT_CR, field FO1 */

#define BP_GPT_CR_FO1      29
#define BM_GPT_CR_FO1      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_FO1(v)   ((((reg32_t) v) << 29) & BM_GPT_CR_FO1)
#else
#define BF_GPT_CR_FO1(v)   (((v) << 29) & BM_GPT_CR_FO1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_FO1(v)   BF_CS1(GPT_CR, FO1, v)
#endif

/* --- Register HW_GPT_CR, field OM3 */

#define BP_GPT_CR_OM3      26
#define BM_GPT_CR_OM3      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_OM3(v)   ((((reg32_t) v) << 26) & BM_GPT_CR_OM3)
#else
#define BF_GPT_CR_OM3(v)   (((v) << 26) & BM_GPT_CR_OM3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_OM3(v)   BF_CS1(GPT_CR, OM3, v)
#endif

/* --- Register HW_GPT_CR, field OM2 */

#define BP_GPT_CR_OM2      23
#define BM_GPT_CR_OM2      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_OM2(v)   ((((reg32_t) v) << 23) & BM_GPT_CR_OM2)
#else
#define BF_GPT_CR_OM2(v)   (((v) << 23) & BM_GPT_CR_OM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_OM2(v)   BF_CS1(GPT_CR, OM2, v)
#endif

/* --- Register HW_GPT_CR, field OM1 */

#define BP_GPT_CR_OM1      20
#define BM_GPT_CR_OM1      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_OM1(v)   ((((reg32_t) v) << 20) & BM_GPT_CR_OM1)
#else
#define BF_GPT_CR_OM1(v)   (((v) << 20) & BM_GPT_CR_OM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_OM1(v)   BF_CS1(GPT_CR, OM1, v)
#endif

/* --- Register HW_GPT_CR, field IM2 */

#define BP_GPT_CR_IM2      18
#define BM_GPT_CR_IM2      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_IM2(v)   ((((reg32_t) v) << 18) & BM_GPT_CR_IM2)
#else
#define BF_GPT_CR_IM2(v)   (((v) << 18) & BM_GPT_CR_IM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_IM2(v)   BF_CS1(GPT_CR, IM2, v)
#endif

/* --- Register HW_GPT_CR, field IM1 */

#define BP_GPT_CR_IM1      16
#define BM_GPT_CR_IM1      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_IM1(v)   ((((reg32_t) v) << 16) & BM_GPT_CR_IM1)
#else
#define BF_GPT_CR_IM1(v)   (((v) << 16) & BM_GPT_CR_IM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_IM1(v)   BF_CS1(GPT_CR, IM1, v)
#endif

/* --- Register HW_GPT_CR, field SWR */

#define BP_GPT_CR_SWR      15
#define BM_GPT_CR_SWR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_SWR(v)   ((((reg32_t) v) << 15) & BM_GPT_CR_SWR)
#else
#define BF_GPT_CR_SWR(v)   (((v) << 15) & BM_GPT_CR_SWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_SWR(v)   BF_CS1(GPT_CR, SWR, v)
#endif

/* --- Register HW_GPT_CR, field FRR */

#define BP_GPT_CR_FRR      9
#define BM_GPT_CR_FRR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_FRR(v)   ((((reg32_t) v) << 9) & BM_GPT_CR_FRR)
#else
#define BF_GPT_CR_FRR(v)   (((v) << 9) & BM_GPT_CR_FRR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_FRR(v)   BF_CS1(GPT_CR, FRR, v)
#endif

/* --- Register HW_GPT_CR, field CLKSRC */

#define BP_GPT_CR_CLKSRC      6
#define BM_GPT_CR_CLKSRC      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_CLKSRC(v)   ((((reg32_t) v) << 6) & BM_GPT_CR_CLKSRC)
#else
#define BF_GPT_CR_CLKSRC(v)   (((v) << 6) & BM_GPT_CR_CLKSRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_CLKSRC(v)   BF_CS1(GPT_CR, CLKSRC, v)
#endif

/* --- Register HW_GPT_CR, field STOPEN */

#define BP_GPT_CR_STOPEN      5
#define BM_GPT_CR_STOPEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_STOPEN(v)   ((((reg32_t) v) << 5) & BM_GPT_CR_STOPEN)
#else
#define BF_GPT_CR_STOPEN(v)   (((v) << 5) & BM_GPT_CR_STOPEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_STOPEN(v)   BF_CS1(GPT_CR, STOPEN, v)
#endif

/* --- Register HW_GPT_CR, field DOZEEN */

#define BP_GPT_CR_DOZEEN      4
#define BM_GPT_CR_DOZEEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_DOZEEN(v)   ((((reg32_t) v) << 4) & BM_GPT_CR_DOZEEN)
#else
#define BF_GPT_CR_DOZEEN(v)   (((v) << 4) & BM_GPT_CR_DOZEEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_DOZEEN(v)   BF_CS1(GPT_CR, DOZEEN, v)
#endif

/* --- Register HW_GPT_CR, field WAITEN */

#define BP_GPT_CR_WAITEN      3
#define BM_GPT_CR_WAITEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_WAITEN(v)   ((((reg32_t) v) << 3) & BM_GPT_CR_WAITEN)
#else
#define BF_GPT_CR_WAITEN(v)   (((v) << 3) & BM_GPT_CR_WAITEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_WAITEN(v)   BF_CS1(GPT_CR, WAITEN, v)
#endif

/* --- Register HW_GPT_CR, field DBGEN */

#define BP_GPT_CR_DBGEN      2
#define BM_GPT_CR_DBGEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_DBGEN(v)   ((((reg32_t) v) << 2) & BM_GPT_CR_DBGEN)
#else
#define BF_GPT_CR_DBGEN(v)   (((v) << 2) & BM_GPT_CR_DBGEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_DBGEN(v)   BF_CS1(GPT_CR, DBGEN, v)
#endif

/* --- Register HW_GPT_CR, field ENMOD */

#define BP_GPT_CR_ENMOD      1
#define BM_GPT_CR_ENMOD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_ENMOD(v)   ((((reg32_t) v) << 1) & BM_GPT_CR_ENMOD)
#else
#define BF_GPT_CR_ENMOD(v)   (((v) << 1) & BM_GPT_CR_ENMOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_ENMOD(v)   BF_CS1(GPT_CR, ENMOD, v)
#endif

/* --- Register HW_GPT_CR, field EN */

#define BP_GPT_CR_EN      0
#define BM_GPT_CR_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_EN(v)   ((((reg32_t) v) << 0) & BM_GPT_CR_EN)
#else
#define BF_GPT_CR_EN(v)   (((v) << 0) & BM_GPT_CR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_EN(v)   BF_CS1(GPT_CR, EN, v)
#endif

/*
 * HW_GPT_PR - GPT Prescaler Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20;
        unsigned PRESCALER : 12;

    } B;
} hw_gpt_pr_t;
#endif

/*
 * constants & macros for entire GPT_PR register
 */
#define HW_GPT_PR_ADDR      (REGS_GPT_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_PR           (*(volatile hw_gpt_pr_t *) HW_GPT_PR_ADDR)
#define HW_GPT_PR_RD()      (HW_GPT_PR.U)
#define HW_GPT_PR_WR(v)     (HW_GPT_PR.U = (v))
#define HW_GPT_PR_SET(v)    (HW_GPT_PR_WR(HW_GPT_PR_RD() |  (v)))
#define HW_GPT_PR_CLR(v)    (HW_GPT_PR_WR(HW_GPT_PR_RD() & ~(v)))
#define HW_GPT_PR_TOG(v)    (HW_GPT_PR_WR(HW_GPT_PR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_PR bitfields
 */

/* --- Register HW_GPT_PR, field PRESCALER */

#define BP_GPT_PR_PRESCALER      0
#define BM_GPT_PR_PRESCALER      0x00000fff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_PR_PRESCALER(v)   ((((reg32_t) v) << 0) & BM_GPT_PR_PRESCALER)
#else
#define BF_GPT_PR_PRESCALER(v)   (((v) << 0) & BM_GPT_PR_PRESCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_PR_PRESCALER(v)   BF_CS1(GPT_PR, PRESCALER, v)
#endif

/*
 * HW_GPT_SR - GPT Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 26;
        unsigned ROV : 1;
        unsigned IF2 : 1;
        unsigned IF1 : 1;
        unsigned OF3 : 1;
        unsigned OF2 : 1;
        unsigned OF1 : 1;

    } B;
} hw_gpt_sr_t;
#endif

/*
 * constants & macros for entire GPT_SR register
 */
#define HW_GPT_SR_ADDR      (REGS_GPT_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_SR           (*(volatile hw_gpt_sr_t *) HW_GPT_SR_ADDR)
#define HW_GPT_SR_RD()      (HW_GPT_SR.U)
#define HW_GPT_SR_WR(v)     (HW_GPT_SR.U = (v))
#define HW_GPT_SR_SET(v)    (HW_GPT_SR_WR(HW_GPT_SR_RD() |  (v)))
#define HW_GPT_SR_CLR(v)    (HW_GPT_SR_WR(HW_GPT_SR_RD() & ~(v)))
#define HW_GPT_SR_TOG(v)    (HW_GPT_SR_WR(HW_GPT_SR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_SR bitfields
 */

/* --- Register HW_GPT_SR, field ROV */

#define BP_GPT_SR_ROV      5
#define BM_GPT_SR_ROV      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_ROV(v)   ((((reg32_t) v) << 5) & BM_GPT_SR_ROV)
#else
#define BF_GPT_SR_ROV(v)   (((v) << 5) & BM_GPT_SR_ROV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_ROV(v)   BF_CS1(GPT_SR, ROV, v)
#endif

/* --- Register HW_GPT_SR, field IF2 */

#define BP_GPT_SR_IF2      4
#define BM_GPT_SR_IF2      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_IF2(v)   ((((reg32_t) v) << 4) & BM_GPT_SR_IF2)
#else
#define BF_GPT_SR_IF2(v)   (((v) << 4) & BM_GPT_SR_IF2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_IF2(v)   BF_CS1(GPT_SR, IF2, v)
#endif

/* --- Register HW_GPT_SR, field IF1 */

#define BP_GPT_SR_IF1      3
#define BM_GPT_SR_IF1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_IF1(v)   ((((reg32_t) v) << 3) & BM_GPT_SR_IF1)
#else
#define BF_GPT_SR_IF1(v)   (((v) << 3) & BM_GPT_SR_IF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_IF1(v)   BF_CS1(GPT_SR, IF1, v)
#endif

/* --- Register HW_GPT_SR, field OF3 */

#define BP_GPT_SR_OF3      2
#define BM_GPT_SR_OF3      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_OF3(v)   ((((reg32_t) v) << 2) & BM_GPT_SR_OF3)
#else
#define BF_GPT_SR_OF3(v)   (((v) << 2) & BM_GPT_SR_OF3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_OF3(v)   BF_CS1(GPT_SR, OF3, v)
#endif

/* --- Register HW_GPT_SR, field OF2 */

#define BP_GPT_SR_OF2      1
#define BM_GPT_SR_OF2      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_OF2(v)   ((((reg32_t) v) << 1) & BM_GPT_SR_OF2)
#else
#define BF_GPT_SR_OF2(v)   (((v) << 1) & BM_GPT_SR_OF2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_OF2(v)   BF_CS1(GPT_SR, OF2, v)
#endif

/* --- Register HW_GPT_SR, field OF1 */

#define BP_GPT_SR_OF1      0
#define BM_GPT_SR_OF1      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_OF1(v)   ((((reg32_t) v) << 0) & BM_GPT_SR_OF1)
#else
#define BF_GPT_SR_OF1(v)   (((v) << 0) & BM_GPT_SR_OF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_OF1(v)   BF_CS1(GPT_SR, OF1, v)
#endif

/*
 * HW_GPT_IR - GPT Interrupt Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 26;
        unsigned ROVIE : 1;
        unsigned IF2IE : 1;
        unsigned IF1IE : 1;
        unsigned OF3IE : 1;
        unsigned OF2IE : 1;
        unsigned OF1IE : 1;

    } B;
} hw_gpt_ir_t;
#endif

/*
 * constants & macros for entire GPT_IR register
 */
#define HW_GPT_IR_ADDR      (REGS_GPT_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_IR           (*(volatile hw_gpt_ir_t *) HW_GPT_IR_ADDR)
#define HW_GPT_IR_RD()      (HW_GPT_IR.U)
#define HW_GPT_IR_WR(v)     (HW_GPT_IR.U = (v))
#define HW_GPT_IR_SET(v)    (HW_GPT_IR_WR(HW_GPT_IR_RD() |  (v)))
#define HW_GPT_IR_CLR(v)    (HW_GPT_IR_WR(HW_GPT_IR_RD() & ~(v)))
#define HW_GPT_IR_TOG(v)    (HW_GPT_IR_WR(HW_GPT_IR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_IR bitfields
 */

/* --- Register HW_GPT_IR, field ROVIE */

#define BP_GPT_IR_ROVIE      5
#define BM_GPT_IR_ROVIE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_ROVIE(v)   ((((reg32_t) v) << 5) & BM_GPT_IR_ROVIE)
#else
#define BF_GPT_IR_ROVIE(v)   (((v) << 5) & BM_GPT_IR_ROVIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_ROVIE(v)   BF_CS1(GPT_IR, ROVIE, v)
#endif

/* --- Register HW_GPT_IR, field IF2IE */

#define BP_GPT_IR_IF2IE      4
#define BM_GPT_IR_IF2IE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_IF2IE(v)   ((((reg32_t) v) << 4) & BM_GPT_IR_IF2IE)
#else
#define BF_GPT_IR_IF2IE(v)   (((v) << 4) & BM_GPT_IR_IF2IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_IF2IE(v)   BF_CS1(GPT_IR, IF2IE, v)
#endif

/* --- Register HW_GPT_IR, field IF1IE */

#define BP_GPT_IR_IF1IE      3
#define BM_GPT_IR_IF1IE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_IF1IE(v)   ((((reg32_t) v) << 3) & BM_GPT_IR_IF1IE)
#else
#define BF_GPT_IR_IF1IE(v)   (((v) << 3) & BM_GPT_IR_IF1IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_IF1IE(v)   BF_CS1(GPT_IR, IF1IE, v)
#endif

/* --- Register HW_GPT_IR, field OF3IE */

#define BP_GPT_IR_OF3IE      2
#define BM_GPT_IR_OF3IE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_OF3IE(v)   ((((reg32_t) v) << 2) & BM_GPT_IR_OF3IE)
#else
#define BF_GPT_IR_OF3IE(v)   (((v) << 2) & BM_GPT_IR_OF3IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_OF3IE(v)   BF_CS1(GPT_IR, OF3IE, v)
#endif

/* --- Register HW_GPT_IR, field OF2IE */

#define BP_GPT_IR_OF2IE      1
#define BM_GPT_IR_OF2IE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_OF2IE(v)   ((((reg32_t) v) << 1) & BM_GPT_IR_OF2IE)
#else
#define BF_GPT_IR_OF2IE(v)   (((v) << 1) & BM_GPT_IR_OF2IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_OF2IE(v)   BF_CS1(GPT_IR, OF2IE, v)
#endif

/* --- Register HW_GPT_IR, field OF1IE */

#define BP_GPT_IR_OF1IE      0
#define BM_GPT_IR_OF1IE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_OF1IE(v)   ((((reg32_t) v) << 0) & BM_GPT_IR_OF1IE)
#else
#define BF_GPT_IR_OF1IE(v)   (((v) << 0) & BM_GPT_IR_OF1IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_OF1IE(v)   BF_CS1(GPT_IR, OF1IE, v)
#endif

/*
 * HW_GPT_OCR1 - GPT Output Compare Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COMP : 32;

    } B;
} hw_gpt_ocr1_t;
#endif

/*
 * constants & macros for entire GPT_OCR1 register
 */
#define HW_GPT_OCR1_ADDR      (REGS_GPT_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_OCR1           (*(volatile hw_gpt_ocr1_t *) HW_GPT_OCR1_ADDR)
#define HW_GPT_OCR1_RD()      (HW_GPT_OCR1.U)
#define HW_GPT_OCR1_WR(v)     (HW_GPT_OCR1.U = (v))
#define HW_GPT_OCR1_SET(v)    (HW_GPT_OCR1_WR(HW_GPT_OCR1_RD() |  (v)))
#define HW_GPT_OCR1_CLR(v)    (HW_GPT_OCR1_WR(HW_GPT_OCR1_RD() & ~(v)))
#define HW_GPT_OCR1_TOG(v)    (HW_GPT_OCR1_WR(HW_GPT_OCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_OCR1 bitfields
 */

/* --- Register HW_GPT_OCR1, field COMP */

#define BP_GPT_OCR1_COMP      0
#define BM_GPT_OCR1_COMP      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_OCR1_COMP(v)   ((((reg32_t) v) << 0) & BM_GPT_OCR1_COMP)
#else
#define BF_GPT_OCR1_COMP(v)   (((v) << 0) & BM_GPT_OCR1_COMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_OCR1_COMP(v)   BF_CS1(GPT_OCR1, COMP, v)
#endif

/*
 * HW_GPT_OCR2 - GPT Output Compare Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COMP : 32;

    } B;
} hw_gpt_ocr2_t;
#endif

/*
 * constants & macros for entire GPT_OCR2 register
 */
#define HW_GPT_OCR2_ADDR      (REGS_GPT_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_OCR2           (*(volatile hw_gpt_ocr2_t *) HW_GPT_OCR2_ADDR)
#define HW_GPT_OCR2_RD()      (HW_GPT_OCR2.U)
#define HW_GPT_OCR2_WR(v)     (HW_GPT_OCR2.U = (v))
#define HW_GPT_OCR2_SET(v)    (HW_GPT_OCR2_WR(HW_GPT_OCR2_RD() |  (v)))
#define HW_GPT_OCR2_CLR(v)    (HW_GPT_OCR2_WR(HW_GPT_OCR2_RD() & ~(v)))
#define HW_GPT_OCR2_TOG(v)    (HW_GPT_OCR2_WR(HW_GPT_OCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_OCR2 bitfields
 */

/* --- Register HW_GPT_OCR2, field COMP */

#define BP_GPT_OCR2_COMP      0
#define BM_GPT_OCR2_COMP      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_OCR2_COMP(v)   ((((reg32_t) v) << 0) & BM_GPT_OCR2_COMP)
#else
#define BF_GPT_OCR2_COMP(v)   (((v) << 0) & BM_GPT_OCR2_COMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_OCR2_COMP(v)   BF_CS1(GPT_OCR2, COMP, v)
#endif

/*
 * HW_GPT_OCR3 - GPT Output Compare Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COMP : 32;

    } B;
} hw_gpt_ocr3_t;
#endif

/*
 * constants & macros for entire GPT_OCR3 register
 */
#define HW_GPT_OCR3_ADDR      (REGS_GPT_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_OCR3           (*(volatile hw_gpt_ocr3_t *) HW_GPT_OCR3_ADDR)
#define HW_GPT_OCR3_RD()      (HW_GPT_OCR3.U)
#define HW_GPT_OCR3_WR(v)     (HW_GPT_OCR3.U = (v))
#define HW_GPT_OCR3_SET(v)    (HW_GPT_OCR3_WR(HW_GPT_OCR3_RD() |  (v)))
#define HW_GPT_OCR3_CLR(v)    (HW_GPT_OCR3_WR(HW_GPT_OCR3_RD() & ~(v)))
#define HW_GPT_OCR3_TOG(v)    (HW_GPT_OCR3_WR(HW_GPT_OCR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_OCR3 bitfields
 */

/* --- Register HW_GPT_OCR3, field COMP */

#define BP_GPT_OCR3_COMP      0
#define BM_GPT_OCR3_COMP      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_OCR3_COMP(v)   ((((reg32_t) v) << 0) & BM_GPT_OCR3_COMP)
#else
#define BF_GPT_OCR3_COMP(v)   (((v) << 0) & BM_GPT_OCR3_COMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_OCR3_COMP(v)   BF_CS1(GPT_OCR3, COMP, v)
#endif

/*
 * HW_GPT_ICR1 - GPT Input Capture Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CAPT : 32;

    } B;
} hw_gpt_icr1_t;
#endif

/*
 * constants & macros for entire GPT_ICR1 register
 */
#define HW_GPT_ICR1_ADDR      (REGS_GPT_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_ICR1           (*(volatile hw_gpt_icr1_t *) HW_GPT_ICR1_ADDR)
#define HW_GPT_ICR1_RD()      (HW_GPT_ICR1.U)
#define HW_GPT_ICR1_WR(v)     (HW_GPT_ICR1.U = (v))
#define HW_GPT_ICR1_SET(v)    (HW_GPT_ICR1_WR(HW_GPT_ICR1_RD() |  (v)))
#define HW_GPT_ICR1_CLR(v)    (HW_GPT_ICR1_WR(HW_GPT_ICR1_RD() & ~(v)))
#define HW_GPT_ICR1_TOG(v)    (HW_GPT_ICR1_WR(HW_GPT_ICR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_ICR1 bitfields
 */

/* --- Register HW_GPT_ICR1, field CAPT */

#define BP_GPT_ICR1_CAPT      0
#define BM_GPT_ICR1_CAPT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_ICR1_CAPT(v)   ((((reg32_t) v) << 0) & BM_GPT_ICR1_CAPT)
#else
#define BF_GPT_ICR1_CAPT(v)   (((v) << 0) & BM_GPT_ICR1_CAPT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_ICR1_CAPT(v)   BF_CS1(GPT_ICR1, CAPT, v)
#endif

/*
 * HW_GPT_ICR2 - GPT Input Capture Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CAPT : 32;

    } B;
} hw_gpt_icr2_t;
#endif

/*
 * constants & macros for entire GPT_ICR2 register
 */
#define HW_GPT_ICR2_ADDR      (REGS_GPT_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_ICR2           (*(volatile hw_gpt_icr2_t *) HW_GPT_ICR2_ADDR)
#define HW_GPT_ICR2_RD()      (HW_GPT_ICR2.U)
#define HW_GPT_ICR2_WR(v)     (HW_GPT_ICR2.U = (v))
#define HW_GPT_ICR2_SET(v)    (HW_GPT_ICR2_WR(HW_GPT_ICR2_RD() |  (v)))
#define HW_GPT_ICR2_CLR(v)    (HW_GPT_ICR2_WR(HW_GPT_ICR2_RD() & ~(v)))
#define HW_GPT_ICR2_TOG(v)    (HW_GPT_ICR2_WR(HW_GPT_ICR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_ICR2 bitfields
 */

/* --- Register HW_GPT_ICR2, field CAPT */

#define BP_GPT_ICR2_CAPT      0
#define BM_GPT_ICR2_CAPT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_ICR2_CAPT(v)   ((((reg32_t) v) << 0) & BM_GPT_ICR2_CAPT)
#else
#define BF_GPT_ICR2_CAPT(v)   (((v) << 0) & BM_GPT_ICR2_CAPT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_ICR2_CAPT(v)   BF_CS1(GPT_ICR2, CAPT, v)
#endif

/*
 * HW_GPT_CNT - GPT Counter Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32;

    } B;
} hw_gpt_cnt_t;
#endif

/*
 * constants & macros for entire GPT_CNT register
 */
#define HW_GPT_CNT_ADDR      (REGS_GPT_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_CNT           (*(volatile hw_gpt_cnt_t *) HW_GPT_CNT_ADDR)
#define HW_GPT_CNT_RD()      (HW_GPT_CNT.U)
#define HW_GPT_CNT_WR(v)     (HW_GPT_CNT.U = (v))
#define HW_GPT_CNT_SET(v)    (HW_GPT_CNT_WR(HW_GPT_CNT_RD() |  (v)))
#define HW_GPT_CNT_CLR(v)    (HW_GPT_CNT_WR(HW_GPT_CNT_RD() & ~(v)))
#define HW_GPT_CNT_TOG(v)    (HW_GPT_CNT_WR(HW_GPT_CNT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_CNT bitfields
 */

/* --- Register HW_GPT_CNT, field COUNT */

#define BP_GPT_CNT_COUNT      0
#define BM_GPT_CNT_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CNT_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPT_CNT_COUNT)
#else
#define BF_GPT_CNT_COUNT(v)   (((v) << 0) & BM_GPT_CNT_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CNT_COUNT(v)   BF_CS1(GPT_CNT, COUNT, v)
#endif


#endif // _GPT_H

