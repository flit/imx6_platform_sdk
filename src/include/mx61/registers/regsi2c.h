/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _I2C_H
#define _I2C_H

#include "regs.h"

#ifndef REGS_I2C_BASE
#define REGS_I2C0_BASE (REGS_BASE + 0x021a0000)
#define REGS_I2C1_BASE (REGS_BASE + 0x021a4000)
#define REGS_I2C2_BASE (REGS_BASE + 0x021a8000)
#define REGS_I2C_BASE(x) ( x == 0 ? REGS_I2C0_BASE : x == 1 ? REGS_I2C1_BASE : x == 2 ? REGS_I2C2_BASE : 0xffff0000)

#endif


/*
 * HW_I2C_IADR - I2C Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short RESERVED0 : 8;
        unsigned short ADR : 7;
        unsigned short RESERVED1 : 1;

    } B;
} hw_i2c_iadr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_IADR register
 */
#define HW_I2C_IADR_ADDR(x)      (REGS_I2C_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_IADR(x)           (*(volatile hw_i2c_iadr_t *) HW_I2C_IADR_ADDR(x))
#define HW_I2C_IADR_RD(x)        (HW_I2C_IADR(x).U)
#define HW_I2C_IADR_WR(x, v)     (HW_I2C_IADR(x).U = (v))
#define HW_I2C_IADR_SET(x, v)    (HW_I2C_IADR_WR(x, HW_I2C_IADR_RD(x) |  (v)))
#define HW_I2C_IADR_CLR(x, v)    (HW_I2C_IADR_WR(x, HW_I2C_IADR_RD(x) & ~(v)))
#define HW_I2C_IADR_TOG(x, v)    (HW_I2C_IADR_WR(x, HW_I2C_IADR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual I2C_IADR bitfields
 */

/* --- Register HW_I2C_IADR, field ADR */

#define BP_I2C_IADR_ADR      1
#define BM_I2C_IADR_ADR      0x000000fe

#ifndef __LANGUAGE_ASM__
#define BF_I2C_IADR_ADR(v)   ((((reg32_t) v) << 1) & BM_I2C_IADR_ADR)
#else
#define BF_I2C_IADR_ADR(v)   (((v) << 1) & BM_I2C_IADR_ADR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_IADR_ADR(v)   BF_CS1(I2C_IADR, ADR, v)
#endif

/*
 * HW_I2C_IFDR - I2C Frequency Divider Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short RESERVED0 : 10;
        unsigned short IC : 6;

    } B;
} hw_i2c_ifdr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_IFDR register
 */
#define HW_I2C_IFDR_ADDR(x)      (REGS_I2C_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_IFDR(x)           (*(volatile hw_i2c_ifdr_t *) HW_I2C_IFDR_ADDR(x))
#define HW_I2C_IFDR_RD(x)        (HW_I2C_IFDR(x).U)
#define HW_I2C_IFDR_WR(x, v)     (HW_I2C_IFDR(x).U = (v))
#define HW_I2C_IFDR_SET(x, v)    (HW_I2C_IFDR_WR(x, HW_I2C_IFDR_RD(x) |  (v)))
#define HW_I2C_IFDR_CLR(x, v)    (HW_I2C_IFDR_WR(x, HW_I2C_IFDR_RD(x) & ~(v)))
#define HW_I2C_IFDR_TOG(x, v)    (HW_I2C_IFDR_WR(x, HW_I2C_IFDR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual I2C_IFDR bitfields
 */

/* --- Register HW_I2C_IFDR, field IC */

#define BP_I2C_IFDR_IC      0
#define BM_I2C_IFDR_IC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_I2C_IFDR_IC(v)   ((((reg32_t) v) << 0) & BM_I2C_IFDR_IC)
#else
#define BF_I2C_IFDR_IC(v)   (((v) << 0) & BM_I2C_IFDR_IC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_IFDR_IC(v)   BF_CS1(I2C_IFDR, IC, v)
#endif

/*
 * HW_I2C_I2CR - I2C Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short RESERVED0 : 8;
        unsigned short IEN : 1;
        unsigned short IIEN : 1;
        unsigned short MSTA : 1;
        unsigned short MTX : 1;
        unsigned short TXAK : 1;
        unsigned short RSTA : 1;
        unsigned short RESERVED1 : 2;

    } B;
} hw_i2c_i2cr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_I2CR register
 */
#define HW_I2C_I2CR_ADDR(x)      (REGS_I2C_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_I2CR(x)           (*(volatile hw_i2c_i2cr_t *) HW_I2C_I2CR_ADDR(x))
#define HW_I2C_I2CR_RD(x)        (HW_I2C_I2CR(x).U)
#define HW_I2C_I2CR_WR(x, v)     (HW_I2C_I2CR(x).U = (v))
#define HW_I2C_I2CR_SET(x, v)    (HW_I2C_I2CR_WR(x, HW_I2C_I2CR_RD(x) |  (v)))
#define HW_I2C_I2CR_CLR(x, v)    (HW_I2C_I2CR_WR(x, HW_I2C_I2CR_RD(x) & ~(v)))
#define HW_I2C_I2CR_TOG(x, v)    (HW_I2C_I2CR_WR(x, HW_I2C_I2CR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual I2C_I2CR bitfields
 */

/* --- Register HW_I2C_I2CR, field IEN */

#define BP_I2C_I2CR_IEN      7
#define BM_I2C_I2CR_IEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2CR_IEN(v)   ((((reg32_t) v) << 7) & BM_I2C_I2CR_IEN)
#else
#define BF_I2C_I2CR_IEN(v)   (((v) << 7) & BM_I2C_I2CR_IEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2CR_IEN(v)   BF_CS1(I2C_I2CR, IEN, v)
#endif

/* --- Register HW_I2C_I2CR, field IIEN */

#define BP_I2C_I2CR_IIEN      6
#define BM_I2C_I2CR_IIEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2CR_IIEN(v)   ((((reg32_t) v) << 6) & BM_I2C_I2CR_IIEN)
#else
#define BF_I2C_I2CR_IIEN(v)   (((v) << 6) & BM_I2C_I2CR_IIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2CR_IIEN(v)   BF_CS1(I2C_I2CR, IIEN, v)
#endif

/* --- Register HW_I2C_I2CR, field MSTA */

#define BP_I2C_I2CR_MSTA      5
#define BM_I2C_I2CR_MSTA      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2CR_MSTA(v)   ((((reg32_t) v) << 5) & BM_I2C_I2CR_MSTA)
#else
#define BF_I2C_I2CR_MSTA(v)   (((v) << 5) & BM_I2C_I2CR_MSTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2CR_MSTA(v)   BF_CS1(I2C_I2CR, MSTA, v)
#endif

/* --- Register HW_I2C_I2CR, field MTX */

#define BP_I2C_I2CR_MTX      4
#define BM_I2C_I2CR_MTX      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2CR_MTX(v)   ((((reg32_t) v) << 4) & BM_I2C_I2CR_MTX)
#else
#define BF_I2C_I2CR_MTX(v)   (((v) << 4) & BM_I2C_I2CR_MTX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2CR_MTX(v)   BF_CS1(I2C_I2CR, MTX, v)
#endif

/* --- Register HW_I2C_I2CR, field TXAK */

#define BP_I2C_I2CR_TXAK      3
#define BM_I2C_I2CR_TXAK      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2CR_TXAK(v)   ((((reg32_t) v) << 3) & BM_I2C_I2CR_TXAK)
#else
#define BF_I2C_I2CR_TXAK(v)   (((v) << 3) & BM_I2C_I2CR_TXAK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2CR_TXAK(v)   BF_CS1(I2C_I2CR, TXAK, v)
#endif

/* --- Register HW_I2C_I2CR, field RSTA */

#define BP_I2C_I2CR_RSTA      2
#define BM_I2C_I2CR_RSTA      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2CR_RSTA(v)   ((((reg32_t) v) << 2) & BM_I2C_I2CR_RSTA)
#else
#define BF_I2C_I2CR_RSTA(v)   (((v) << 2) & BM_I2C_I2CR_RSTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2CR_RSTA(v)   BF_CS1(I2C_I2CR, RSTA, v)
#endif

/*
 * HW_I2C_I2SR - I2C Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short RESERVED0 : 8;
        unsigned short ICF : 1;
        unsigned short IAAS : 1;
        unsigned short IBB : 1;
        unsigned short IAL : 1;
        unsigned short RESERVED1 : 1;
        unsigned short SRW : 1;
        unsigned short IIF : 1;
        unsigned short RXAK : 1;

    } B;
} hw_i2c_i2sr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_I2SR register
 */
#define HW_I2C_I2SR_ADDR(x)      (REGS_I2C_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_I2SR(x)           (*(volatile hw_i2c_i2sr_t *) HW_I2C_I2SR_ADDR(x))
#define HW_I2C_I2SR_RD(x)        (HW_I2C_I2SR(x).U)
#define HW_I2C_I2SR_WR(x, v)     (HW_I2C_I2SR(x).U = (v))
#define HW_I2C_I2SR_SET(x, v)    (HW_I2C_I2SR_WR(x, HW_I2C_I2SR_RD(x) |  (v)))
#define HW_I2C_I2SR_CLR(x, v)    (HW_I2C_I2SR_WR(x, HW_I2C_I2SR_RD(x) & ~(v)))
#define HW_I2C_I2SR_TOG(x, v)    (HW_I2C_I2SR_WR(x, HW_I2C_I2SR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual I2C_I2SR bitfields
 */

/* --- Register HW_I2C_I2SR, field ICF */

#define BP_I2C_I2SR_ICF      7
#define BM_I2C_I2SR_ICF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2SR_ICF(v)   ((((reg32_t) v) << 7) & BM_I2C_I2SR_ICF)
#else
#define BF_I2C_I2SR_ICF(v)   (((v) << 7) & BM_I2C_I2SR_ICF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2SR_ICF(v)   BF_CS1(I2C_I2SR, ICF, v)
#endif

/* --- Register HW_I2C_I2SR, field IAAS */

#define BP_I2C_I2SR_IAAS      6
#define BM_I2C_I2SR_IAAS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2SR_IAAS(v)   ((((reg32_t) v) << 6) & BM_I2C_I2SR_IAAS)
#else
#define BF_I2C_I2SR_IAAS(v)   (((v) << 6) & BM_I2C_I2SR_IAAS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2SR_IAAS(v)   BF_CS1(I2C_I2SR, IAAS, v)
#endif

/* --- Register HW_I2C_I2SR, field IBB */

#define BP_I2C_I2SR_IBB      5
#define BM_I2C_I2SR_IBB      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2SR_IBB(v)   ((((reg32_t) v) << 5) & BM_I2C_I2SR_IBB)
#else
#define BF_I2C_I2SR_IBB(v)   (((v) << 5) & BM_I2C_I2SR_IBB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2SR_IBB(v)   BF_CS1(I2C_I2SR, IBB, v)
#endif

/* --- Register HW_I2C_I2SR, field IAL */

#define BP_I2C_I2SR_IAL      4
#define BM_I2C_I2SR_IAL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2SR_IAL(v)   ((((reg32_t) v) << 4) & BM_I2C_I2SR_IAL)
#else
#define BF_I2C_I2SR_IAL(v)   (((v) << 4) & BM_I2C_I2SR_IAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2SR_IAL(v)   BF_CS1(I2C_I2SR, IAL, v)
#endif

/* --- Register HW_I2C_I2SR, field SRW */

#define BP_I2C_I2SR_SRW      2
#define BM_I2C_I2SR_SRW      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2SR_SRW(v)   ((((reg32_t) v) << 2) & BM_I2C_I2SR_SRW)
#else
#define BF_I2C_I2SR_SRW(v)   (((v) << 2) & BM_I2C_I2SR_SRW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2SR_SRW(v)   BF_CS1(I2C_I2SR, SRW, v)
#endif

/* --- Register HW_I2C_I2SR, field IIF */

#define BP_I2C_I2SR_IIF      1
#define BM_I2C_I2SR_IIF      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2SR_IIF(v)   ((((reg32_t) v) << 1) & BM_I2C_I2SR_IIF)
#else
#define BF_I2C_I2SR_IIF(v)   (((v) << 1) & BM_I2C_I2SR_IIF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2SR_IIF(v)   BF_CS1(I2C_I2SR, IIF, v)
#endif

/* --- Register HW_I2C_I2SR, field RXAK */

#define BP_I2C_I2SR_RXAK      0
#define BM_I2C_I2SR_RXAK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2SR_RXAK(v)   ((((reg32_t) v) << 0) & BM_I2C_I2SR_RXAK)
#else
#define BF_I2C_I2SR_RXAK(v)   (((v) << 0) & BM_I2C_I2SR_RXAK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2SR_RXAK(v)   BF_CS1(I2C_I2SR, RXAK, v)
#endif

/*
 * HW_I2C_I2DR - I2C Data I/O Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short RESERVED0 : 8;
        unsigned short DATA : 8;

    } B;
} hw_i2c_i2dr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_I2DR register
 */
#define HW_I2C_I2DR_ADDR(x)      (REGS_I2C_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_I2DR(x)           (*(volatile hw_i2c_i2dr_t *) HW_I2C_I2DR_ADDR(x))
#define HW_I2C_I2DR_RD(x)        (HW_I2C_I2DR(x).U)
#define HW_I2C_I2DR_WR(x, v)     (HW_I2C_I2DR(x).U = (v))
#define HW_I2C_I2DR_SET(x, v)    (HW_I2C_I2DR_WR(x, HW_I2C_I2DR_RD(x) |  (v)))
#define HW_I2C_I2DR_CLR(x, v)    (HW_I2C_I2DR_WR(x, HW_I2C_I2DR_RD(x) & ~(v)))
#define HW_I2C_I2DR_TOG(x, v)    (HW_I2C_I2DR_WR(x, HW_I2C_I2DR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual I2C_I2DR bitfields
 */

/* --- Register HW_I2C_I2DR, field DATA */

#define BP_I2C_I2DR_DATA      0
#define BM_I2C_I2DR_DATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_I2C_I2DR_DATA(v)   ((((reg32_t) v) << 0) & BM_I2C_I2DR_DATA)
#else
#define BF_I2C_I2DR_DATA(v)   (((v) << 0) & BM_I2C_I2DR_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_I2C_I2DR_DATA(v)   BF_CS1(I2C_I2DR, DATA, v)
#endif


#endif // _I2C_H

