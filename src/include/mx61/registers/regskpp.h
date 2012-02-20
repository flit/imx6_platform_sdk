/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _KPP_H
#define _KPP_H

#include "regs.h"

#ifndef REGS_KPP_BASE
#define REGS_KPP_BASE (REGS_BASE + 0x020b8000)

#endif


/*
 * HW_KPP_KPCR - Keypad Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short KCO : 8;
        unsigned short KRE : 8;

    } B;
} hw_kpp_kpcr_t;
#endif

/*
 * constants & macros for entire KPP_KPCR register
 */
#define HW_KPP_KPCR_ADDR      (REGS_KPP_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_KPP_KPCR           (*(volatile hw_kpp_kpcr_t *) HW_KPP_KPCR_ADDR)
#define HW_KPP_KPCR_RD()      (HW_KPP_KPCR.U)
#define HW_KPP_KPCR_WR(v)     (HW_KPP_KPCR.U = (v))
#define HW_KPP_KPCR_SET(v)    (HW_KPP_KPCR_WR(HW_KPP_KPCR_RD() |  (v)))
#define HW_KPP_KPCR_CLR(v)    (HW_KPP_KPCR_WR(HW_KPP_KPCR_RD() & ~(v)))
#define HW_KPP_KPCR_TOG(v)    (HW_KPP_KPCR_WR(HW_KPP_KPCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual KPP_KPCR bitfields
 */

/* --- Register HW_KPP_KPCR, field KCO */

#define BP_KPP_KPCR_KCO      8
#define BM_KPP_KPCR_KCO      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPCR_KCO(v)   ((((reg32_t) v) << 8) & BM_KPP_KPCR_KCO)
#else
#define BF_KPP_KPCR_KCO(v)   (((v) << 8) & BM_KPP_KPCR_KCO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPCR_KCO(v)   BF_CS1(KPP_KPCR, KCO, v)
#endif

/* --- Register HW_KPP_KPCR, field KRE */

#define BP_KPP_KPCR_KRE      0
#define BM_KPP_KPCR_KRE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPCR_KRE(v)   ((((reg32_t) v) << 0) & BM_KPP_KPCR_KRE)
#else
#define BF_KPP_KPCR_KRE(v)   (((v) << 0) & BM_KPP_KPCR_KRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPCR_KRE(v)   BF_CS1(KPP_KPCR, KRE, v)
#endif

/*
 * HW_KPP_KPSR - Keypad Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short RESERVED0 : 6;
        unsigned short RESERVED1 : 5;
        unsigned short KPP_EN : 1;
        unsigned short KRIE : 1;
        unsigned short KDIE : 1;
        unsigned short RESERVED2 : 4;
        unsigned short KPP : 1;
        unsigned short KDSC : 1;
        unsigned short KPKR : 1;
        unsigned short KPKD : 1;

    } B;
} hw_kpp_kpsr_t;
#endif

/*
 * constants & macros for entire KPP_KPSR register
 */
#define HW_KPP_KPSR_ADDR      (REGS_KPP_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_KPP_KPSR           (*(volatile hw_kpp_kpsr_t *) HW_KPP_KPSR_ADDR)
#define HW_KPP_KPSR_RD()      (HW_KPP_KPSR.U)
#define HW_KPP_KPSR_WR(v)     (HW_KPP_KPSR.U = (v))
#define HW_KPP_KPSR_SET(v)    (HW_KPP_KPSR_WR(HW_KPP_KPSR_RD() |  (v)))
#define HW_KPP_KPSR_CLR(v)    (HW_KPP_KPSR_WR(HW_KPP_KPSR_RD() & ~(v)))
#define HW_KPP_KPSR_TOG(v)    (HW_KPP_KPSR_WR(HW_KPP_KPSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual KPP_KPSR bitfields
 */

/* --- Register HW_KPP_KPSR, field KPP_EN */

#define BP_KPP_KPSR_KPP_EN      10
#define BM_KPP_KPSR_KPP_EN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KPP_EN(v)   ((((reg32_t) v) << 10) & BM_KPP_KPSR_KPP_EN)
#else
#define BF_KPP_KPSR_KPP_EN(v)   (((v) << 10) & BM_KPP_KPSR_KPP_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KPP_EN(v)   BF_CS1(KPP_KPSR, KPP_EN, v)
#endif

/* --- Register HW_KPP_KPSR, field KRIE */

#define BP_KPP_KPSR_KRIE      9
#define BM_KPP_KPSR_KRIE      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KRIE(v)   ((((reg32_t) v) << 9) & BM_KPP_KPSR_KRIE)
#else
#define BF_KPP_KPSR_KRIE(v)   (((v) << 9) & BM_KPP_KPSR_KRIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KRIE(v)   BF_CS1(KPP_KPSR, KRIE, v)
#endif

/* --- Register HW_KPP_KPSR, field KDIE */

#define BP_KPP_KPSR_KDIE      8
#define BM_KPP_KPSR_KDIE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KDIE(v)   ((((reg32_t) v) << 8) & BM_KPP_KPSR_KDIE)
#else
#define BF_KPP_KPSR_KDIE(v)   (((v) << 8) & BM_KPP_KPSR_KDIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KDIE(v)   BF_CS1(KPP_KPSR, KDIE, v)
#endif

/* --- Register HW_KPP_KPSR, field KPP */

#define BP_KPP_KPSR_KPP      3
#define BM_KPP_KPSR_KPP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KPP(v)   ((((reg32_t) v) << 3) & BM_KPP_KPSR_KPP)
#else
#define BF_KPP_KPSR_KPP(v)   (((v) << 3) & BM_KPP_KPSR_KPP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KPP(v)   BF_CS1(KPP_KPSR, KPP, v)
#endif

/* --- Register HW_KPP_KPSR, field KDSC */

#define BP_KPP_KPSR_KDSC      2
#define BM_KPP_KPSR_KDSC      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KDSC(v)   ((((reg32_t) v) << 2) & BM_KPP_KPSR_KDSC)
#else
#define BF_KPP_KPSR_KDSC(v)   (((v) << 2) & BM_KPP_KPSR_KDSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KDSC(v)   BF_CS1(KPP_KPSR, KDSC, v)
#endif

/* --- Register HW_KPP_KPSR, field KPKR */

#define BP_KPP_KPSR_KPKR      1
#define BM_KPP_KPSR_KPKR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KPKR(v)   ((((reg32_t) v) << 1) & BM_KPP_KPSR_KPKR)
#else
#define BF_KPP_KPSR_KPKR(v)   (((v) << 1) & BM_KPP_KPSR_KPKR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KPKR(v)   BF_CS1(KPP_KPSR, KPKR, v)
#endif

/* --- Register HW_KPP_KPSR, field KPKD */

#define BP_KPP_KPSR_KPKD      0
#define BM_KPP_KPSR_KPKD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KPKD(v)   ((((reg32_t) v) << 0) & BM_KPP_KPSR_KPKD)
#else
#define BF_KPP_KPSR_KPKD(v)   (((v) << 0) & BM_KPP_KPSR_KPKD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KPKD(v)   BF_CS1(KPP_KPSR, KPKD, v)
#endif

/*
 * HW_KPP_KDDR - Keypad Data Direction Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short KCDD : 8;
        unsigned short KRDD : 8;

    } B;
} hw_kpp_kddr_t;
#endif

/*
 * constants & macros for entire KPP_KDDR register
 */
#define HW_KPP_KDDR_ADDR      (REGS_KPP_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_KPP_KDDR           (*(volatile hw_kpp_kddr_t *) HW_KPP_KDDR_ADDR)
#define HW_KPP_KDDR_RD()      (HW_KPP_KDDR.U)
#define HW_KPP_KDDR_WR(v)     (HW_KPP_KDDR.U = (v))
#define HW_KPP_KDDR_SET(v)    (HW_KPP_KDDR_WR(HW_KPP_KDDR_RD() |  (v)))
#define HW_KPP_KDDR_CLR(v)    (HW_KPP_KDDR_WR(HW_KPP_KDDR_RD() & ~(v)))
#define HW_KPP_KDDR_TOG(v)    (HW_KPP_KDDR_WR(HW_KPP_KDDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual KPP_KDDR bitfields
 */

/* --- Register HW_KPP_KDDR, field KCDD */

#define BP_KPP_KDDR_KCDD      8
#define BM_KPP_KDDR_KCDD      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KDDR_KCDD(v)   ((((reg32_t) v) << 8) & BM_KPP_KDDR_KCDD)
#else
#define BF_KPP_KDDR_KCDD(v)   (((v) << 8) & BM_KPP_KDDR_KCDD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KDDR_KCDD(v)   BF_CS1(KPP_KDDR, KCDD, v)
#endif

/* --- Register HW_KPP_KDDR, field KRDD */

#define BP_KPP_KDDR_KRDD      0
#define BM_KPP_KDDR_KRDD      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KDDR_KRDD(v)   ((((reg32_t) v) << 0) & BM_KPP_KDDR_KRDD)
#else
#define BF_KPP_KDDR_KRDD(v)   (((v) << 0) & BM_KPP_KDDR_KRDD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KDDR_KRDD(v)   BF_CS1(KPP_KDDR, KRDD, v)
#endif

/*
 * HW_KPP_KPDR - Keypad Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short KCD : 8;
        unsigned short KRD : 8;

    } B;
} hw_kpp_kpdr_t;
#endif

/*
 * constants & macros for entire KPP_KPDR register
 */
#define HW_KPP_KPDR_ADDR      (REGS_KPP_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_KPP_KPDR           (*(volatile hw_kpp_kpdr_t *) HW_KPP_KPDR_ADDR)
#define HW_KPP_KPDR_RD()      (HW_KPP_KPDR.U)
#define HW_KPP_KPDR_WR(v)     (HW_KPP_KPDR.U = (v))
#define HW_KPP_KPDR_SET(v)    (HW_KPP_KPDR_WR(HW_KPP_KPDR_RD() |  (v)))
#define HW_KPP_KPDR_CLR(v)    (HW_KPP_KPDR_WR(HW_KPP_KPDR_RD() & ~(v)))
#define HW_KPP_KPDR_TOG(v)    (HW_KPP_KPDR_WR(HW_KPP_KPDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual KPP_KPDR bitfields
 */

/* --- Register HW_KPP_KPDR, field KCD */

#define BP_KPP_KPDR_KCD      8
#define BM_KPP_KPDR_KCD      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPDR_KCD(v)   ((((reg32_t) v) << 8) & BM_KPP_KPDR_KCD)
#else
#define BF_KPP_KPDR_KCD(v)   (((v) << 8) & BM_KPP_KPDR_KCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPDR_KCD(v)   BF_CS1(KPP_KPDR, KCD, v)
#endif

/* --- Register HW_KPP_KPDR, field KRD */

#define BP_KPP_KPDR_KRD      0
#define BM_KPP_KPDR_KRD      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPDR_KRD(v)   ((((reg32_t) v) << 0) & BM_KPP_KPDR_KRD)
#else
#define BF_KPP_KPDR_KRD(v)   (((v) << 0) & BM_KPP_KPDR_KRD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPDR_KRD(v)   BF_CS1(KPP_KPDR, KRD, v)
#endif


#endif // _KPP_H

