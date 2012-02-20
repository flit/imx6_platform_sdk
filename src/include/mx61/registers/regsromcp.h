/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _ROMC_H
#define _ROMC_H

#include "regs.h"

#ifndef REGS_ROMC_BASE
#define REGS_ROMC_BASE (REGS_BASE + 0x021ac000)

#endif


/*
 * HW_ROMC_ROMPATCHD - ROMC Data Registers
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATAX : 32;

    } B;
} hw_romc_rompatchd_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD register
 */
#define HW_ROMC_ROMPATCHD_ADDR      (REGS_ROMC_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD           (*(volatile hw_romc_rompatchd_t *) HW_ROMC_ROMPATCHD_ADDR)
#define HW_ROMC_ROMPATCHD_RD()      (HW_ROMC_ROMPATCHD.U)
#define HW_ROMC_ROMPATCHD_WR(v)     (HW_ROMC_ROMPATCHD.U = (v))
#define HW_ROMC_ROMPATCHD_SET(v)    (HW_ROMC_ROMPATCHD_WR(HW_ROMC_ROMPATCHD_RD() |  (v)))
#define HW_ROMC_ROMPATCHD_CLR(v)    (HW_ROMC_ROMPATCHD_WR(HW_ROMC_ROMPATCHD_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD_TOG(v)    (HW_ROMC_ROMPATCHD_WR(HW_ROMC_ROMPATCHD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ROMC_ROMPATCHD bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD, field DATAX */

#define BP_ROMC_ROMPATCHD_DATAX      0
#define BM_ROMC_ROMPATCHD_DATAX      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD_DATAX)
#else
#define BF_ROMC_ROMPATCHD_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHD_DATAX(v)   BF_CS1(ROMC_ROMPATCHD, DATAX, v)
#endif

/*
 * HW_ROMC_ROMPATCHCNTL - ROMC Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2;
        unsigned DIS : 1;
        unsigned RESERVED1 : 21;
        unsigned DATAFIX : 8;

    } B;
} hw_romc_rompatchcntl_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHCNTL register
 */
#define HW_ROMC_ROMPATCHCNTL_ADDR      (REGS_ROMC_BASE + 0xf4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHCNTL           (*(volatile hw_romc_rompatchcntl_t *) HW_ROMC_ROMPATCHCNTL_ADDR)
#define HW_ROMC_ROMPATCHCNTL_RD()      (HW_ROMC_ROMPATCHCNTL.U)
#define HW_ROMC_ROMPATCHCNTL_WR(v)     (HW_ROMC_ROMPATCHCNTL.U = (v))
#define HW_ROMC_ROMPATCHCNTL_SET(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() |  (v)))
#define HW_ROMC_ROMPATCHCNTL_CLR(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() & ~(v)))
#define HW_ROMC_ROMPATCHCNTL_TOG(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ROMC_ROMPATCHCNTL bitfields
 */

/* --- Register HW_ROMC_ROMPATCHCNTL, field DIS */

#define BP_ROMC_ROMPATCHCNTL_DIS      29
#define BM_ROMC_ROMPATCHCNTL_DIS      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHCNTL_DIS(v)   ((((reg32_t) v) << 29) & BM_ROMC_ROMPATCHCNTL_DIS)
#else
#define BF_ROMC_ROMPATCHCNTL_DIS(v)   (((v) << 29) & BM_ROMC_ROMPATCHCNTL_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHCNTL_DIS(v)   BF_CS1(ROMC_ROMPATCHCNTL, DIS, v)
#endif

/* --- Register HW_ROMC_ROMPATCHCNTL, field DATAFIX */

#define BP_ROMC_ROMPATCHCNTL_DATAFIX      0
#define BM_ROMC_ROMPATCHCNTL_DATAFIX      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHCNTL_DATAFIX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHCNTL_DATAFIX)
#else
#define BF_ROMC_ROMPATCHCNTL_DATAFIX(v)   (((v) << 0) & BM_ROMC_ROMPATCHCNTL_DATAFIX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHCNTL_DATAFIX(v)   BF_CS1(ROMC_ROMPATCHCNTL, DATAFIX, v)
#endif

/*
 * HW_ROMC_ROMPATCHENH - ROMC Enable Register High
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_romc_rompatchenh_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHENH register
 */
#define HW_ROMC_ROMPATCHENH_ADDR      (REGS_ROMC_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHENH           (*(volatile hw_romc_rompatchenh_t *) HW_ROMC_ROMPATCHENH_ADDR)
#define HW_ROMC_ROMPATCHENH_RD()      (HW_ROMC_ROMPATCHENH.U)
#define HW_ROMC_ROMPATCHENH_WR(v)     (HW_ROMC_ROMPATCHENH.U = (v))
#define HW_ROMC_ROMPATCHENH_SET(v)    (HW_ROMC_ROMPATCHENH_WR(HW_ROMC_ROMPATCHENH_RD() |  (v)))
#define HW_ROMC_ROMPATCHENH_CLR(v)    (HW_ROMC_ROMPATCHENH_WR(HW_ROMC_ROMPATCHENH_RD() & ~(v)))
#define HW_ROMC_ROMPATCHENH_TOG(v)    (HW_ROMC_ROMPATCHENH_WR(HW_ROMC_ROMPATCHENH_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ROMC_ROMPATCHENH bitfields
 */

/*
 * HW_ROMC_ROMPATCHENL - ROMC Enable Register Low
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED : 16;
        unsigned ENABLE : 16;

    } B;
} hw_romc_rompatchenl_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHENL register
 */
#define HW_ROMC_ROMPATCHENL_ADDR      (REGS_ROMC_BASE + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHENL           (*(volatile hw_romc_rompatchenl_t *) HW_ROMC_ROMPATCHENL_ADDR)
#define HW_ROMC_ROMPATCHENL_RD()      (HW_ROMC_ROMPATCHENL.U)
#define HW_ROMC_ROMPATCHENL_WR(v)     (HW_ROMC_ROMPATCHENL.U = (v))
#define HW_ROMC_ROMPATCHENL_SET(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() |  (v)))
#define HW_ROMC_ROMPATCHENL_CLR(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() & ~(v)))
#define HW_ROMC_ROMPATCHENL_TOG(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ROMC_ROMPATCHENL bitfields
 */

/* --- Register HW_ROMC_ROMPATCHENL, field RESERVED */

#define BP_ROMC_ROMPATCHENL_RESERVED      16
#define BM_ROMC_ROMPATCHENL_RESERVED      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHENL_RESERVED(v)   ((((reg32_t) v) << 16) & BM_ROMC_ROMPATCHENL_RESERVED)
#else
#define BF_ROMC_ROMPATCHENL_RESERVED(v)   (((v) << 16) & BM_ROMC_ROMPATCHENL_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHENL_RESERVED(v)   BF_CS1(ROMC_ROMPATCHENL, RESERVED, v)
#endif

/* --- Register HW_ROMC_ROMPATCHENL, field ENABLE */

#define BP_ROMC_ROMPATCHENL_ENABLE      0
#define BM_ROMC_ROMPATCHENL_ENABLE      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHENL_ENABLE(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHENL_ENABLE)
#else
#define BF_ROMC_ROMPATCHENL_ENABLE(v)   (((v) << 0) & BM_ROMC_ROMPATCHENL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHENL_ENABLE(v)   BF_CS1(ROMC_ROMPATCHENL, ENABLE, v)
#endif

/*
 * HW_ROMC_ROMPATCHA - ROMC Address Registers
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 9;
        unsigned ADDRX : 22;
        unsigned THUMBX : 1;

    } B;
} hw_romc_rompatcha_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA register
 */
#define HW_ROMC_ROMPATCHA_ADDR      (REGS_ROMC_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA           (*(volatile hw_romc_rompatcha_t *) HW_ROMC_ROMPATCHA_ADDR)
#define HW_ROMC_ROMPATCHA_RD()      (HW_ROMC_ROMPATCHA.U)
#define HW_ROMC_ROMPATCHA_WR(v)     (HW_ROMC_ROMPATCHA.U = (v))
#define HW_ROMC_ROMPATCHA_SET(v)    (HW_ROMC_ROMPATCHA_WR(HW_ROMC_ROMPATCHA_RD() |  (v)))
#define HW_ROMC_ROMPATCHA_CLR(v)    (HW_ROMC_ROMPATCHA_WR(HW_ROMC_ROMPATCHA_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA_TOG(v)    (HW_ROMC_ROMPATCHA_WR(HW_ROMC_ROMPATCHA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ROMC_ROMPATCHA bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA, field ADDRX */

#define BP_ROMC_ROMPATCHA_ADDRX      1
#define BM_ROMC_ROMPATCHA_ADDRX      0x007ffffe

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA_ADDRX)
#else
#define BF_ROMC_ROMPATCHA_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHA_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA, ADDRX, v)
#endif

/* --- Register HW_ROMC_ROMPATCHA, field THUMBX */

#define BP_ROMC_ROMPATCHA_THUMBX      0
#define BM_ROMC_ROMPATCHA_THUMBX      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA_THUMBX)
#else
#define BF_ROMC_ROMPATCHA_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHA_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA, THUMBX, v)
#endif

/*
 * HW_ROMC_ROMPATCHSR - ROMC Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned SW : 1;
        unsigned RESERVED1 : 11;
        unsigned SOURCE : 6;

    } B;
} hw_romc_rompatchsr_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHSR register
 */
#define HW_ROMC_ROMPATCHSR_ADDR      (REGS_ROMC_BASE + 0x208)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHSR           (*(volatile hw_romc_rompatchsr_t *) HW_ROMC_ROMPATCHSR_ADDR)
#define HW_ROMC_ROMPATCHSR_RD()      (HW_ROMC_ROMPATCHSR.U)
#define HW_ROMC_ROMPATCHSR_WR(v)     (HW_ROMC_ROMPATCHSR.U = (v))
#define HW_ROMC_ROMPATCHSR_SET(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() |  (v)))
#define HW_ROMC_ROMPATCHSR_CLR(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() & ~(v)))
#define HW_ROMC_ROMPATCHSR_TOG(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ROMC_ROMPATCHSR bitfields
 */

/* --- Register HW_ROMC_ROMPATCHSR, field SW */

#define BP_ROMC_ROMPATCHSR_SW      17
#define BM_ROMC_ROMPATCHSR_SW      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHSR_SW(v)   ((((reg32_t) v) << 17) & BM_ROMC_ROMPATCHSR_SW)
#else
#define BF_ROMC_ROMPATCHSR_SW(v)   (((v) << 17) & BM_ROMC_ROMPATCHSR_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHSR_SW(v)   BF_CS1(ROMC_ROMPATCHSR, SW, v)
#endif

/* --- Register HW_ROMC_ROMPATCHSR, field SOURCE */

#define BP_ROMC_ROMPATCHSR_SOURCE      0
#define BM_ROMC_ROMPATCHSR_SOURCE      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHSR_SOURCE(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHSR_SOURCE)
#else
#define BF_ROMC_ROMPATCHSR_SOURCE(v)   (((v) << 0) & BM_ROMC_ROMPATCHSR_SOURCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ROMC_ROMPATCHSR_SOURCE(v)   BF_CS1(ROMC_ROMPATCHSR, SOURCE, v)
#endif


#endif // _ROMC_H


