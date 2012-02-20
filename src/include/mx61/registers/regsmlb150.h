/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _MLB_H
#define _MLB_H

#include "regs.h"

#ifndef REGS_MLB_BASE
#define REGS_MLB_BASE (REGS_BASE + 0x0218c000)

#endif


/*
 * HW_MLB_MLBC0 - MediaLB Control 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned FCNT : 3;
        unsigned RESERVED1 : 1;
        unsigned RESERVED2 : 1;
        unsigned RESERVED3 : 1;
        unsigned RESERVED4 : 4;
        unsigned RESERVED5 : 1;
        unsigned RESERVED6 : 1;
        unsigned RESERVED7 : 1;
        unsigned RESERVED8 : 3;
        unsigned RESERVED9 : 1;
        unsigned RESERVED10 : 1;

    } B;
} hw_mlb_mlbc0_t;
#endif

/*
 * constants & macros for entire MLB_MLBC0 register
 */
#define HW_MLB_MLBC0_ADDR      (REGS_MLB_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBC0           (*(volatile hw_mlb_mlbc0_t *) HW_MLB_MLBC0_ADDR)
#define HW_MLB_MLBC0_RD()      (HW_MLB_MLBC0.U)
#define HW_MLB_MLBC0_WR(v)     (HW_MLB_MLBC0.U = (v))
#define HW_MLB_MLBC0_SET(v)    (HW_MLB_MLBC0_WR(HW_MLB_MLBC0_RD() |  (v)))
#define HW_MLB_MLBC0_CLR(v)    (HW_MLB_MLBC0_WR(HW_MLB_MLBC0_RD() & ~(v)))
#define HW_MLB_MLBC0_TOG(v)    (HW_MLB_MLBC0_WR(HW_MLB_MLBC0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MLBC0 bitfields
 */

/* --- Register HW_MLB_MLBC0, field FCNT */

#define BP_MLB_MLBC0_FCNT      15
#define BM_MLB_MLBC0_FCNT      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_MLB_MLBC0_FCNT(v)   ((((reg32_t) v) << 15) & BM_MLB_MLBC0_FCNT)
#else
#define BF_MLB_MLBC0_FCNT(v)   (((v) << 15) & BM_MLB_MLBC0_FCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_MLBC0_FCNT(v)   BF_CS1(MLB_MLBC0, FCNT, v)
#endif

/*
 * HW_MLB_MLBPC0 - MediaLB 6-pin Control 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20;
        unsigned RESERVED1 : 1;
        unsigned RESERVED2 : 11;

    } B;
} hw_mlb_mlbpc0_t;
#endif

/*
 * constants & macros for entire MLB_MLBPC0 register
 */
#define HW_MLB_MLBPC0_ADDR      (REGS_MLB_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBPC0           (*(volatile hw_mlb_mlbpc0_t *) HW_MLB_MLBPC0_ADDR)
#define HW_MLB_MLBPC0_RD()      (HW_MLB_MLBPC0.U)
#define HW_MLB_MLBPC0_WR(v)     (HW_MLB_MLBPC0.U = (v))
#define HW_MLB_MLBPC0_SET(v)    (HW_MLB_MLBPC0_WR(HW_MLB_MLBPC0_RD() |  (v)))
#define HW_MLB_MLBPC0_CLR(v)    (HW_MLB_MLBPC0_WR(HW_MLB_MLBPC0_RD() & ~(v)))
#define HW_MLB_MLBPC0_TOG(v)    (HW_MLB_MLBPC0_WR(HW_MLB_MLBPC0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MLBPC0 bitfields
 */

/*
 * HW_MLB_MS0 - MediaLB Channel Status 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_ms0_t;
#endif

/*
 * constants & macros for entire MLB_MS0 register
 */
#define HW_MLB_MS0_ADDR      (REGS_MLB_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MS0           (*(volatile hw_mlb_ms0_t *) HW_MLB_MS0_ADDR)
#define HW_MLB_MS0_RD()      (HW_MLB_MS0.U)
#define HW_MLB_MS0_WR(v)     (HW_MLB_MS0.U = (v))
#define HW_MLB_MS0_SET(v)    (HW_MLB_MS0_WR(HW_MLB_MS0_RD() |  (v)))
#define HW_MLB_MS0_CLR(v)    (HW_MLB_MS0_WR(HW_MLB_MS0_RD() & ~(v)))
#define HW_MLB_MS0_TOG(v)    (HW_MLB_MS0_WR(HW_MLB_MS0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MS0 bitfields
 */

/*
 * HW_MLB_MS1 - MediaLB Channel Status1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_ms1_t;
#endif

/*
 * constants & macros for entire MLB_MS1 register
 */
#define HW_MLB_MS1_ADDR      (REGS_MLB_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MS1           (*(volatile hw_mlb_ms1_t *) HW_MLB_MS1_ADDR)
#define HW_MLB_MS1_RD()      (HW_MLB_MS1.U)
#define HW_MLB_MS1_WR(v)     (HW_MLB_MS1.U = (v))
#define HW_MLB_MS1_SET(v)    (HW_MLB_MS1_WR(HW_MLB_MS1_RD() |  (v)))
#define HW_MLB_MS1_CLR(v)    (HW_MLB_MS1_WR(HW_MLB_MS1_RD() & ~(v)))
#define HW_MLB_MS1_TOG(v)    (HW_MLB_MS1_WR(HW_MLB_MS1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MS1 bitfields
 */

/*
 * HW_MLB_MSS - MediaLB System Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 26;
        unsigned RESERVED1 : 1;
        unsigned RESERVED2 : 1;
        unsigned RESERVED3 : 1;
        unsigned RESERVED4 : 1;
        unsigned RESERVED5 : 1;
        unsigned RESERVED6 : 1;

    } B;
} hw_mlb_mss_t;
#endif

/*
 * constants & macros for entire MLB_MSS register
 */
#define HW_MLB_MSS_ADDR      (REGS_MLB_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MSS           (*(volatile hw_mlb_mss_t *) HW_MLB_MSS_ADDR)
#define HW_MLB_MSS_RD()      (HW_MLB_MSS.U)
#define HW_MLB_MSS_WR(v)     (HW_MLB_MSS.U = (v))
#define HW_MLB_MSS_SET(v)    (HW_MLB_MSS_WR(HW_MLB_MSS_RD() |  (v)))
#define HW_MLB_MSS_CLR(v)    (HW_MLB_MSS_WR(HW_MLB_MSS_RD() & ~(v)))
#define HW_MLB_MSS_TOG(v)    (HW_MLB_MSS_WR(HW_MLB_MSS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MSS bitfields
 */

/*
 * HW_MLB_MSD - MediaLB System Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 8;
        unsigned RESERVED2 : 8;
        unsigned RESERVED3 : 8;

    } B;
} hw_mlb_msd_t;
#endif

/*
 * constants & macros for entire MLB_MSD register
 */
#define HW_MLB_MSD_ADDR      (REGS_MLB_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MSD           (*(volatile hw_mlb_msd_t *) HW_MLB_MSD_ADDR)
#define HW_MLB_MSD_RD()      (HW_MLB_MSD.U)
#define HW_MLB_MSD_WR(v)     (HW_MLB_MSD.U = (v))
#define HW_MLB_MSD_SET(v)    (HW_MLB_MSD_WR(HW_MLB_MSD_RD() |  (v)))
#define HW_MLB_MSD_CLR(v)    (HW_MLB_MSD_WR(HW_MLB_MSD_RD() & ~(v)))
#define HW_MLB_MSD_TOG(v)    (HW_MLB_MSD_WR(HW_MLB_MSD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MSD bitfields
 */

/*
 * HW_MLB_MIEN - MediaLB Interrupt Enable Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2;
        unsigned RESERVED1 : 1;
        unsigned RESERVED2 : 1;
        unsigned RESERVED3 : 1;
        unsigned RESERVED4 : 1;
        unsigned RESERVED5 : 1;
        unsigned RESERVED6 : 1;
        unsigned RESERVED7 : 1;
        unsigned RESERVED8 : 1;
        unsigned RESERVED9 : 1;
        unsigned RESERVED10 : 1;
        unsigned RESERVED11 : 1;
        unsigned RESERVED12 : 1;
        unsigned RESERVED13 : 1;
        unsigned RESERVED14 : 1;
        unsigned RESERVED15 : 14;
        unsigned RESERVED16 : 1;
        unsigned RESERVED17 : 1;

    } B;
} hw_mlb_mien_t;
#endif

/*
 * constants & macros for entire MLB_MIEN register
 */
#define HW_MLB_MIEN_ADDR      (REGS_MLB_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MIEN           (*(volatile hw_mlb_mien_t *) HW_MLB_MIEN_ADDR)
#define HW_MLB_MIEN_RD()      (HW_MLB_MIEN.U)
#define HW_MLB_MIEN_WR(v)     (HW_MLB_MIEN.U = (v))
#define HW_MLB_MIEN_SET(v)    (HW_MLB_MIEN_WR(HW_MLB_MIEN_RD() |  (v)))
#define HW_MLB_MIEN_CLR(v)    (HW_MLB_MIEN_WR(HW_MLB_MIEN_RD() & ~(v)))
#define HW_MLB_MIEN_TOG(v)    (HW_MLB_MIEN_WR(HW_MLB_MIEN_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MIEN bitfields
 */

/*
 * HW_MLB_MLBPC2 - MediaLB 6-pin Control 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SDRTO : 2;
        unsigned SDOPC : 1;
        unsigned RESERVED0 : 29;

    } B;
} hw_mlb_mlbpc2_t;
#endif

/*
 * constants & macros for entire MLB_MLBPC2 register
 */
#define HW_MLB_MLBPC2_ADDR      (REGS_MLB_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBPC2           (*(volatile hw_mlb_mlbpc2_t *) HW_MLB_MLBPC2_ADDR)
#define HW_MLB_MLBPC2_RD()      (HW_MLB_MLBPC2.U)
#define HW_MLB_MLBPC2_WR(v)     (HW_MLB_MLBPC2.U = (v))
#define HW_MLB_MLBPC2_SET(v)    (HW_MLB_MLBPC2_WR(HW_MLB_MLBPC2_RD() |  (v)))
#define HW_MLB_MLBPC2_CLR(v)    (HW_MLB_MLBPC2_WR(HW_MLB_MLBPC2_RD() & ~(v)))
#define HW_MLB_MLBPC2_TOG(v)    (HW_MLB_MLBPC2_WR(HW_MLB_MLBPC2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MLBPC2 bitfields
 */

/* --- Register HW_MLB_MLBPC2, field SDRTO */

#define BP_MLB_MLBPC2_SDRTO      1
#define BM_MLB_MLBPC2_SDRTO      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_MLB_MLBPC2_SDRTO(v)   ((((reg32_t) v) << 1) & BM_MLB_MLBPC2_SDRTO)
#else
#define BF_MLB_MLBPC2_SDRTO(v)   (((v) << 1) & BM_MLB_MLBPC2_SDRTO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_MLBPC2_SDRTO(v)   BF_CS1(MLB_MLBPC2, SDRTO, v)
#endif

/* --- Register HW_MLB_MLBPC2, field SDOPC */

#define BP_MLB_MLBPC2_SDOPC      0
#define BM_MLB_MLBPC2_SDOPC      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MLB_MLBPC2_SDOPC(v)   ((((reg32_t) v) << 0) & BM_MLB_MLBPC2_SDOPC)
#else
#define BF_MLB_MLBPC2_SDOPC(v)   (((v) << 0) & BM_MLB_MLBPC2_SDOPC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_MLBPC2_SDOPC(v)   BF_CS1(MLB_MLBPC2, SDOPC, v)
#endif

/*
 * HW_MLB_MLBPC1 - MediaLB 6-pin Control 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20;
        unsigned RESERVED1 : 4;
        unsigned RESERVED2 : 4;
        unsigned RESERVED3 : 4;

    } B;
} hw_mlb_mlbpc1_t;
#endif

/*
 * constants & macros for entire MLB_MLBPC1 register
 */
#define HW_MLB_MLBPC1_ADDR      (REGS_MLB_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBPC1           (*(volatile hw_mlb_mlbpc1_t *) HW_MLB_MLBPC1_ADDR)
#define HW_MLB_MLBPC1_RD()      (HW_MLB_MLBPC1.U)
#define HW_MLB_MLBPC1_WR(v)     (HW_MLB_MLBPC1.U = (v))
#define HW_MLB_MLBPC1_SET(v)    (HW_MLB_MLBPC1_WR(HW_MLB_MLBPC1_RD() |  (v)))
#define HW_MLB_MLBPC1_CLR(v)    (HW_MLB_MLBPC1_WR(HW_MLB_MLBPC1_RD() & ~(v)))
#define HW_MLB_MLBPC1_TOG(v)    (HW_MLB_MLBPC1_WR(HW_MLB_MLBPC1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MLBPC1 bitfields
 */

/*
 * HW_MLB_MLBC1 - MediaLB Control 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RESERVED1 : 8;
        unsigned RESERVED2 : 1;
        unsigned RESERVED3 : 1;
        unsigned RESERVED4 : 6;

    } B;
} hw_mlb_mlbc1_t;
#endif

/*
 * constants & macros for entire MLB_MLBC1 register
 */
#define HW_MLB_MLBC1_ADDR      (REGS_MLB_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBC1           (*(volatile hw_mlb_mlbc1_t *) HW_MLB_MLBC1_ADDR)
#define HW_MLB_MLBC1_RD()      (HW_MLB_MLBC1.U)
#define HW_MLB_MLBC1_WR(v)     (HW_MLB_MLBC1.U = (v))
#define HW_MLB_MLBC1_SET(v)    (HW_MLB_MLBC1_WR(HW_MLB_MLBC1_RD() |  (v)))
#define HW_MLB_MLBC1_CLR(v)    (HW_MLB_MLBC1_WR(HW_MLB_MLBC1_RD() & ~(v)))
#define HW_MLB_MLBC1_TOG(v)    (HW_MLB_MLBC1_WR(HW_MLB_MLBC1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MLBC1 bitfields
 */

/*
 * HW_MLB_HCTL - HBI Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RESERVED1 : 1;
        unsigned RESERVED2 : 13;
        unsigned RESERVED3 : 1;
        unsigned RESERVED4 : 1;

    } B;
} hw_mlb_hctl_t;
#endif

/*
 * constants & macros for entire MLB_HCTL register
 */
#define HW_MLB_HCTL_ADDR      (REGS_MLB_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCTL           (*(volatile hw_mlb_hctl_t *) HW_MLB_HCTL_ADDR)
#define HW_MLB_HCTL_RD()      (HW_MLB_HCTL.U)
#define HW_MLB_HCTL_WR(v)     (HW_MLB_HCTL.U = (v))
#define HW_MLB_HCTL_SET(v)    (HW_MLB_HCTL_WR(HW_MLB_HCTL_RD() |  (v)))
#define HW_MLB_HCTL_CLR(v)    (HW_MLB_HCTL_WR(HW_MLB_HCTL_RD() & ~(v)))
#define HW_MLB_HCTL_TOG(v)    (HW_MLB_HCTL_WR(HW_MLB_HCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCTL bitfields
 */

/*
 * HW_MLB_HCMR0 - HBI Channel Mask 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_hcmr0_t;
#endif

/*
 * constants & macros for entire MLB_HCMR0 register
 */
#define HW_MLB_HCMR0_ADDR      (REGS_MLB_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCMR0           (*(volatile hw_mlb_hcmr0_t *) HW_MLB_HCMR0_ADDR)
#define HW_MLB_HCMR0_RD()      (HW_MLB_HCMR0.U)
#define HW_MLB_HCMR0_WR(v)     (HW_MLB_HCMR0.U = (v))
#define HW_MLB_HCMR0_SET(v)    (HW_MLB_HCMR0_WR(HW_MLB_HCMR0_RD() |  (v)))
#define HW_MLB_HCMR0_CLR(v)    (HW_MLB_HCMR0_WR(HW_MLB_HCMR0_RD() & ~(v)))
#define HW_MLB_HCMR0_TOG(v)    (HW_MLB_HCMR0_WR(HW_MLB_HCMR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCMR0 bitfields
 */

/*
 * HW_MLB_HCMR1 - HBI Channel Mask 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_hcmr1_t;
#endif

/*
 * constants & macros for entire MLB_HCMR1 register
 */
#define HW_MLB_HCMR1_ADDR      (REGS_MLB_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCMR1           (*(volatile hw_mlb_hcmr1_t *) HW_MLB_HCMR1_ADDR)
#define HW_MLB_HCMR1_RD()      (HW_MLB_HCMR1.U)
#define HW_MLB_HCMR1_WR(v)     (HW_MLB_HCMR1.U = (v))
#define HW_MLB_HCMR1_SET(v)    (HW_MLB_HCMR1_WR(HW_MLB_HCMR1_RD() |  (v)))
#define HW_MLB_HCMR1_CLR(v)    (HW_MLB_HCMR1_WR(HW_MLB_HCMR1_RD() & ~(v)))
#define HW_MLB_HCMR1_TOG(v)    (HW_MLB_HCMR1_WR(HW_MLB_HCMR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCMR1 bitfields
 */

/*
 * HW_MLB_HCER0 - HBI Channel Error 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_hcer0_t;
#endif

/*
 * constants & macros for entire MLB_HCER0 register
 */
#define HW_MLB_HCER0_ADDR      (REGS_MLB_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCER0           (*(volatile hw_mlb_hcer0_t *) HW_MLB_HCER0_ADDR)
#define HW_MLB_HCER0_RD()      (HW_MLB_HCER0.U)
#define HW_MLB_HCER0_WR(v)     (HW_MLB_HCER0.U = (v))
#define HW_MLB_HCER0_SET(v)    (HW_MLB_HCER0_WR(HW_MLB_HCER0_RD() |  (v)))
#define HW_MLB_HCER0_CLR(v)    (HW_MLB_HCER0_WR(HW_MLB_HCER0_RD() & ~(v)))
#define HW_MLB_HCER0_TOG(v)    (HW_MLB_HCER0_WR(HW_MLB_HCER0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCER0 bitfields
 */

/*
 * HW_MLB_HCER1 - HBI Channel Error 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_hcer1_t;
#endif

/*
 * constants & macros for entire MLB_HCER1 register
 */
#define HW_MLB_HCER1_ADDR      (REGS_MLB_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCER1           (*(volatile hw_mlb_hcer1_t *) HW_MLB_HCER1_ADDR)
#define HW_MLB_HCER1_RD()      (HW_MLB_HCER1.U)
#define HW_MLB_HCER1_WR(v)     (HW_MLB_HCER1.U = (v))
#define HW_MLB_HCER1_SET(v)    (HW_MLB_HCER1_WR(HW_MLB_HCER1_RD() |  (v)))
#define HW_MLB_HCER1_CLR(v)    (HW_MLB_HCER1_WR(HW_MLB_HCER1_RD() & ~(v)))
#define HW_MLB_HCER1_TOG(v)    (HW_MLB_HCER1_WR(HW_MLB_HCER1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCER1 bitfields
 */

/*
 * HW_MLB_HCBR0 - HBI Channel Busy 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_hcbr0_t;
#endif

/*
 * constants & macros for entire MLB_HCBR0 register
 */
#define HW_MLB_HCBR0_ADDR      (REGS_MLB_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCBR0           (*(volatile hw_mlb_hcbr0_t *) HW_MLB_HCBR0_ADDR)
#define HW_MLB_HCBR0_RD()      (HW_MLB_HCBR0.U)
#define HW_MLB_HCBR0_WR(v)     (HW_MLB_HCBR0.U = (v))
#define HW_MLB_HCBR0_SET(v)    (HW_MLB_HCBR0_WR(HW_MLB_HCBR0_RD() |  (v)))
#define HW_MLB_HCBR0_CLR(v)    (HW_MLB_HCBR0_WR(HW_MLB_HCBR0_RD() & ~(v)))
#define HW_MLB_HCBR0_TOG(v)    (HW_MLB_HCBR0_WR(HW_MLB_HCBR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCBR0 bitfields
 */

/*
 * HW_MLB_HCBR1 - HBI Channel Busy 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_hcbr1_t;
#endif

/*
 * constants & macros for entire MLB_HCBR1 register
 */
#define HW_MLB_HCBR1_ADDR      (REGS_MLB_BASE + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCBR1           (*(volatile hw_mlb_hcbr1_t *) HW_MLB_HCBR1_ADDR)
#define HW_MLB_HCBR1_RD()      (HW_MLB_HCBR1.U)
#define HW_MLB_HCBR1_WR(v)     (HW_MLB_HCBR1.U = (v))
#define HW_MLB_HCBR1_SET(v)    (HW_MLB_HCBR1_WR(HW_MLB_HCBR1_RD() |  (v)))
#define HW_MLB_HCBR1_CLR(v)    (HW_MLB_HCBR1_WR(HW_MLB_HCBR1_RD() & ~(v)))
#define HW_MLB_HCBR1_TOG(v)    (HW_MLB_HCBR1_WR(HW_MLB_HCBR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCBR1 bitfields
 */

/*
 * HW_MLB_MDAT0 - MIF Data 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_mdat0_t;
#endif

/*
 * constants & macros for entire MLB_MDAT0 register
 */
#define HW_MLB_MDAT0_ADDR      (REGS_MLB_BASE + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDAT0           (*(volatile hw_mlb_mdat0_t *) HW_MLB_MDAT0_ADDR)
#define HW_MLB_MDAT0_RD()      (HW_MLB_MDAT0.U)
#define HW_MLB_MDAT0_WR(v)     (HW_MLB_MDAT0.U = (v))
#define HW_MLB_MDAT0_SET(v)    (HW_MLB_MDAT0_WR(HW_MLB_MDAT0_RD() |  (v)))
#define HW_MLB_MDAT0_CLR(v)    (HW_MLB_MDAT0_WR(HW_MLB_MDAT0_RD() & ~(v)))
#define HW_MLB_MDAT0_TOG(v)    (HW_MLB_MDAT0_WR(HW_MLB_MDAT0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MDAT0 bitfields
 */

/*
 * HW_MLB_MDAT1 - MIF Data 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_mdat1_t;
#endif

/*
 * constants & macros for entire MLB_MDAT1 register
 */
#define HW_MLB_MDAT1_ADDR      (REGS_MLB_BASE + 0xc4)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDAT1           (*(volatile hw_mlb_mdat1_t *) HW_MLB_MDAT1_ADDR)
#define HW_MLB_MDAT1_RD()      (HW_MLB_MDAT1.U)
#define HW_MLB_MDAT1_WR(v)     (HW_MLB_MDAT1.U = (v))
#define HW_MLB_MDAT1_SET(v)    (HW_MLB_MDAT1_WR(HW_MLB_MDAT1_RD() |  (v)))
#define HW_MLB_MDAT1_CLR(v)    (HW_MLB_MDAT1_WR(HW_MLB_MDAT1_RD() & ~(v)))
#define HW_MLB_MDAT1_TOG(v)    (HW_MLB_MDAT1_WR(HW_MLB_MDAT1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MDAT1 bitfields
 */

/*
 * HW_MLB_MDAT2 - MIF Data 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_mdat2_t;
#endif

/*
 * constants & macros for entire MLB_MDAT2 register
 */
#define HW_MLB_MDAT2_ADDR      (REGS_MLB_BASE + 0xc8)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDAT2           (*(volatile hw_mlb_mdat2_t *) HW_MLB_MDAT2_ADDR)
#define HW_MLB_MDAT2_RD()      (HW_MLB_MDAT2.U)
#define HW_MLB_MDAT2_WR(v)     (HW_MLB_MDAT2.U = (v))
#define HW_MLB_MDAT2_SET(v)    (HW_MLB_MDAT2_WR(HW_MLB_MDAT2_RD() |  (v)))
#define HW_MLB_MDAT2_CLR(v)    (HW_MLB_MDAT2_WR(HW_MLB_MDAT2_RD() & ~(v)))
#define HW_MLB_MDAT2_TOG(v)    (HW_MLB_MDAT2_WR(HW_MLB_MDAT2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MDAT2 bitfields
 */

/*
 * HW_MLB_MDAT3 - MIF Data 3 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_mdat3_t;
#endif

/*
 * constants & macros for entire MLB_MDAT3 register
 */
#define HW_MLB_MDAT3_ADDR      (REGS_MLB_BASE + 0xcc)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDAT3           (*(volatile hw_mlb_mdat3_t *) HW_MLB_MDAT3_ADDR)
#define HW_MLB_MDAT3_RD()      (HW_MLB_MDAT3.U)
#define HW_MLB_MDAT3_WR(v)     (HW_MLB_MDAT3.U = (v))
#define HW_MLB_MDAT3_SET(v)    (HW_MLB_MDAT3_WR(HW_MLB_MDAT3_RD() |  (v)))
#define HW_MLB_MDAT3_CLR(v)    (HW_MLB_MDAT3_WR(HW_MLB_MDAT3_RD() & ~(v)))
#define HW_MLB_MDAT3_TOG(v)    (HW_MLB_MDAT3_WR(HW_MLB_MDAT3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MDAT3 bitfields
 */

/*
 * HW_MLB_MDWE0 - MIF Data Write Enable 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_mdwe0_t;
#endif

/*
 * constants & macros for entire MLB_MDWE0 register
 */
#define HW_MLB_MDWE0_ADDR      (REGS_MLB_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDWE0           (*(volatile hw_mlb_mdwe0_t *) HW_MLB_MDWE0_ADDR)
#define HW_MLB_MDWE0_RD()      (HW_MLB_MDWE0.U)
#define HW_MLB_MDWE0_WR(v)     (HW_MLB_MDWE0.U = (v))
#define HW_MLB_MDWE0_SET(v)    (HW_MLB_MDWE0_WR(HW_MLB_MDWE0_RD() |  (v)))
#define HW_MLB_MDWE0_CLR(v)    (HW_MLB_MDWE0_WR(HW_MLB_MDWE0_RD() & ~(v)))
#define HW_MLB_MDWE0_TOG(v)    (HW_MLB_MDWE0_WR(HW_MLB_MDWE0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MDWE0 bitfields
 */

/*
 * HW_MLB_MDWE1 - MIF Data Write Enable 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_mdwe1_t;
#endif

/*
 * constants & macros for entire MLB_MDWE1 register
 */
#define HW_MLB_MDWE1_ADDR      (REGS_MLB_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDWE1           (*(volatile hw_mlb_mdwe1_t *) HW_MLB_MDWE1_ADDR)
#define HW_MLB_MDWE1_RD()      (HW_MLB_MDWE1.U)
#define HW_MLB_MDWE1_WR(v)     (HW_MLB_MDWE1.U = (v))
#define HW_MLB_MDWE1_SET(v)    (HW_MLB_MDWE1_WR(HW_MLB_MDWE1_RD() |  (v)))
#define HW_MLB_MDWE1_CLR(v)    (HW_MLB_MDWE1_WR(HW_MLB_MDWE1_RD() & ~(v)))
#define HW_MLB_MDWE1_TOG(v)    (HW_MLB_MDWE1_WR(HW_MLB_MDWE1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MDWE1 bitfields
 */

/*
 * HW_MLB_MDWE2 - MIF Data Write Enable 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_mdwe2_t;
#endif

/*
 * constants & macros for entire MLB_MDWE2 register
 */
#define HW_MLB_MDWE2_ADDR      (REGS_MLB_BASE + 0xd8)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDWE2           (*(volatile hw_mlb_mdwe2_t *) HW_MLB_MDWE2_ADDR)
#define HW_MLB_MDWE2_RD()      (HW_MLB_MDWE2.U)
#define HW_MLB_MDWE2_WR(v)     (HW_MLB_MDWE2.U = (v))
#define HW_MLB_MDWE2_SET(v)    (HW_MLB_MDWE2_WR(HW_MLB_MDWE2_RD() |  (v)))
#define HW_MLB_MDWE2_CLR(v)    (HW_MLB_MDWE2_WR(HW_MLB_MDWE2_RD() & ~(v)))
#define HW_MLB_MDWE2_TOG(v)    (HW_MLB_MDWE2_WR(HW_MLB_MDWE2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MDWE2 bitfields
 */

/*
 * HW_MLB_MDWE3 - MIF Data Write Enable 3 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_mlb_mdwe3_t;
#endif

/*
 * constants & macros for entire MLB_MDWE3 register
 */
#define HW_MLB_MDWE3_ADDR      (REGS_MLB_BASE + 0xdc)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDWE3           (*(volatile hw_mlb_mdwe3_t *) HW_MLB_MDWE3_ADDR)
#define HW_MLB_MDWE3_RD()      (HW_MLB_MDWE3.U)
#define HW_MLB_MDWE3_WR(v)     (HW_MLB_MDWE3.U = (v))
#define HW_MLB_MDWE3_SET(v)    (HW_MLB_MDWE3_WR(HW_MLB_MDWE3_RD() |  (v)))
#define HW_MLB_MDWE3_CLR(v)    (HW_MLB_MDWE3_WR(HW_MLB_MDWE3_RD() & ~(v)))
#define HW_MLB_MDWE3_TOG(v)    (HW_MLB_MDWE3_WR(HW_MLB_MDWE3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MDWE3 bitfields
 */

/*
 * HW_MLB_MCTL - MIF Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned RESERVED1 : 1;

    } B;
} hw_mlb_mctl_t;
#endif

/*
 * constants & macros for entire MLB_MCTL register
 */
#define HW_MLB_MCTL_ADDR      (REGS_MLB_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MCTL           (*(volatile hw_mlb_mctl_t *) HW_MLB_MCTL_ADDR)
#define HW_MLB_MCTL_RD()      (HW_MLB_MCTL.U)
#define HW_MLB_MCTL_WR(v)     (HW_MLB_MCTL.U = (v))
#define HW_MLB_MCTL_SET(v)    (HW_MLB_MCTL_WR(HW_MLB_MCTL_RD() |  (v)))
#define HW_MLB_MCTL_CLR(v)    (HW_MLB_MCTL_WR(HW_MLB_MCTL_RD() & ~(v)))
#define HW_MLB_MCTL_TOG(v)    (HW_MLB_MCTL_WR(HW_MLB_MCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MCTL bitfields
 */

/*
 * HW_MLB_MADR - MIF Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1;
        unsigned RESERVED1 : 1;
        unsigned RESERVED2 : 16;
        unsigned RESERVED3 : 6;
        unsigned RESERVED4 : 8;

    } B;
} hw_mlb_madr_t;
#endif

/*
 * constants & macros for entire MLB_MADR register
 */
#define HW_MLB_MADR_ADDR      (REGS_MLB_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MADR           (*(volatile hw_mlb_madr_t *) HW_MLB_MADR_ADDR)
#define HW_MLB_MADR_RD()      (HW_MLB_MADR.U)
#define HW_MLB_MADR_WR(v)     (HW_MLB_MADR.U = (v))
#define HW_MLB_MADR_SET(v)    (HW_MLB_MADR_WR(HW_MLB_MADR_RD() |  (v)))
#define HW_MLB_MADR_CLR(v)    (HW_MLB_MADR_WR(HW_MLB_MADR_RD() & ~(v)))
#define HW_MLB_MADR_TOG(v)    (HW_MLB_MADR_WR(HW_MLB_MADR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MADR bitfields
 */

/*
 * HW_MLB_ACTL - AHB Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD : 27;
        unsigned MPB : 1;
        unsigned RESERVED0 : 1;
        unsigned DMA : 1;
        unsigned SMX : 1;
        unsigned SCE : 1;

    } B;
} hw_mlb_actl_t;
#endif

/*
 * constants & macros for entire MLB_ACTL register
 */
#define HW_MLB_ACTL_ADDR      (REGS_MLB_BASE + 0x3c0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACTL           (*(volatile hw_mlb_actl_t *) HW_MLB_ACTL_ADDR)
#define HW_MLB_ACTL_RD()      (HW_MLB_ACTL.U)
#define HW_MLB_ACTL_WR(v)     (HW_MLB_ACTL.U = (v))
#define HW_MLB_ACTL_SET(v)    (HW_MLB_ACTL_WR(HW_MLB_ACTL_RD() |  (v)))
#define HW_MLB_ACTL_CLR(v)    (HW_MLB_ACTL_WR(HW_MLB_ACTL_RD() & ~(v)))
#define HW_MLB_ACTL_TOG(v)    (HW_MLB_ACTL_WR(HW_MLB_ACTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_ACTL bitfields
 */

/* --- Register HW_MLB_ACTL, field RSVD */

#define BP_MLB_ACTL_RSVD      5
#define BM_MLB_ACTL_RSVD      0xffffffe0

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_RSVD(v)   ((((reg32_t) v) << 5) & BM_MLB_ACTL_RSVD)
#else
#define BF_MLB_ACTL_RSVD(v)   (((v) << 5) & BM_MLB_ACTL_RSVD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_RSVD(v)   BF_CS1(MLB_ACTL, RSVD, v)
#endif

/* --- Register HW_MLB_ACTL, field MPB */

#define BP_MLB_ACTL_MPB      4
#define BM_MLB_ACTL_MPB      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_MPB(v)   ((((reg32_t) v) << 4) & BM_MLB_ACTL_MPB)
#else
#define BF_MLB_ACTL_MPB(v)   (((v) << 4) & BM_MLB_ACTL_MPB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_MPB(v)   BF_CS1(MLB_ACTL, MPB, v)
#endif

/* --- Register HW_MLB_ACTL, field DMA */

#define BP_MLB_ACTL_DMA      2
#define BM_MLB_ACTL_DMA      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_DMA(v)   ((((reg32_t) v) << 2) & BM_MLB_ACTL_DMA)
#else
#define BF_MLB_ACTL_DMA(v)   (((v) << 2) & BM_MLB_ACTL_DMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_DMA(v)   BF_CS1(MLB_ACTL, DMA, v)
#endif

/* --- Register HW_MLB_ACTL, field SMX */

#define BP_MLB_ACTL_SMX      1
#define BM_MLB_ACTL_SMX      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_SMX(v)   ((((reg32_t) v) << 1) & BM_MLB_ACTL_SMX)
#else
#define BF_MLB_ACTL_SMX(v)   (((v) << 1) & BM_MLB_ACTL_SMX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_SMX(v)   BF_CS1(MLB_ACTL, SMX, v)
#endif

/* --- Register HW_MLB_ACTL, field SCE */

#define BP_MLB_ACTL_SCE      0
#define BM_MLB_ACTL_SCE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_SCE(v)   ((((reg32_t) v) << 0) & BM_MLB_ACTL_SCE)
#else
#define BF_MLB_ACTL_SCE(v)   (((v) << 0) & BM_MLB_ACTL_SCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_SCE(v)   BF_CS1(MLB_ACTL, SCE, v)
#endif

/*
 * HW_MLB_ACSR0 - AHB Channel Status 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned V : 32;

    } B;
} hw_mlb_acsr0_t;
#endif

/*
 * constants & macros for entire MLB_ACSR0 register
 */
#define HW_MLB_ACSR0_ADDR      (REGS_MLB_BASE + 0x3d0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACSR0           (*(volatile hw_mlb_acsr0_t *) HW_MLB_ACSR0_ADDR)
#define HW_MLB_ACSR0_RD()      (HW_MLB_ACSR0.U)
#define HW_MLB_ACSR0_WR(v)     (HW_MLB_ACSR0.U = (v))
#define HW_MLB_ACSR0_SET(v)    (HW_MLB_ACSR0_WR(HW_MLB_ACSR0_RD() |  (v)))
#define HW_MLB_ACSR0_CLR(v)    (HW_MLB_ACSR0_WR(HW_MLB_ACSR0_RD() & ~(v)))
#define HW_MLB_ACSR0_TOG(v)    (HW_MLB_ACSR0_WR(HW_MLB_ACSR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_ACSR0 bitfields
 */

/* --- Register HW_MLB_ACSR0, field V */

#define BP_MLB_ACSR0_V      0
#define BM_MLB_ACSR0_V      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACSR0_V(v)   ((((reg32_t) v) << 0) & BM_MLB_ACSR0_V)
#else
#define BF_MLB_ACSR0_V(v)   (((v) << 0) & BM_MLB_ACSR0_V)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACSR0_V(v)   BF_CS1(MLB_ACSR0, V, v)
#endif

/*
 * HW_MLB_ACSR1 - AHB Channel Status 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHS : 32;

    } B;
} hw_mlb_acsr1_t;
#endif

/*
 * constants & macros for entire MLB_ACSR1 register
 */
#define HW_MLB_ACSR1_ADDR      (REGS_MLB_BASE + 0x3d4)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACSR1           (*(volatile hw_mlb_acsr1_t *) HW_MLB_ACSR1_ADDR)
#define HW_MLB_ACSR1_RD()      (HW_MLB_ACSR1.U)
#define HW_MLB_ACSR1_WR(v)     (HW_MLB_ACSR1.U = (v))
#define HW_MLB_ACSR1_SET(v)    (HW_MLB_ACSR1_WR(HW_MLB_ACSR1_RD() |  (v)))
#define HW_MLB_ACSR1_CLR(v)    (HW_MLB_ACSR1_WR(HW_MLB_ACSR1_RD() & ~(v)))
#define HW_MLB_ACSR1_TOG(v)    (HW_MLB_ACSR1_WR(HW_MLB_ACSR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_ACSR1 bitfields
 */

/* --- Register HW_MLB_ACSR1, field CHS */

#define BP_MLB_ACSR1_CHS      0
#define BM_MLB_ACSR1_CHS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACSR1_CHS(v)   ((((reg32_t) v) << 0) & BM_MLB_ACSR1_CHS)
#else
#define BF_MLB_ACSR1_CHS(v)   (((v) << 0) & BM_MLB_ACSR1_CHS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACSR1_CHS(v)   BF_CS1(MLB_ACSR1, CHS, v)
#endif

/*
 * HW_MLB_ACMR0 - AHB Channel Mask 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHM : 32;

    } B;
} hw_mlb_acmr0_t;
#endif

/*
 * constants & macros for entire MLB_ACMR0 register
 */
#define HW_MLB_ACMR0_ADDR      (REGS_MLB_BASE + 0x3d8)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACMR0           (*(volatile hw_mlb_acmr0_t *) HW_MLB_ACMR0_ADDR)
#define HW_MLB_ACMR0_RD()      (HW_MLB_ACMR0.U)
#define HW_MLB_ACMR0_WR(v)     (HW_MLB_ACMR0.U = (v))
#define HW_MLB_ACMR0_SET(v)    (HW_MLB_ACMR0_WR(HW_MLB_ACMR0_RD() |  (v)))
#define HW_MLB_ACMR0_CLR(v)    (HW_MLB_ACMR0_WR(HW_MLB_ACMR0_RD() & ~(v)))
#define HW_MLB_ACMR0_TOG(v)    (HW_MLB_ACMR0_WR(HW_MLB_ACMR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_ACMR0 bitfields
 */

/* --- Register HW_MLB_ACMR0, field CHM */

#define BP_MLB_ACMR0_CHM      0
#define BM_MLB_ACMR0_CHM      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACMR0_CHM(v)   ((((reg32_t) v) << 0) & BM_MLB_ACMR0_CHM)
#else
#define BF_MLB_ACMR0_CHM(v)   (((v) << 0) & BM_MLB_ACMR0_CHM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACMR0_CHM(v)   BF_CS1(MLB_ACMR0, CHM, v)
#endif

/*
 * HW_MLB_ACMR1 - AHB Channel Mask 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHM : 32;

    } B;
} hw_mlb_acmr1_t;
#endif

/*
 * constants & macros for entire MLB_ACMR1 register
 */
#define HW_MLB_ACMR1_ADDR      (REGS_MLB_BASE + 0x3dc)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACMR1           (*(volatile hw_mlb_acmr1_t *) HW_MLB_ACMR1_ADDR)
#define HW_MLB_ACMR1_RD()      (HW_MLB_ACMR1.U)
#define HW_MLB_ACMR1_WR(v)     (HW_MLB_ACMR1.U = (v))
#define HW_MLB_ACMR1_SET(v)    (HW_MLB_ACMR1_WR(HW_MLB_ACMR1_RD() |  (v)))
#define HW_MLB_ACMR1_CLR(v)    (HW_MLB_ACMR1_WR(HW_MLB_ACMR1_RD() & ~(v)))
#define HW_MLB_ACMR1_TOG(v)    (HW_MLB_ACMR1_WR(HW_MLB_ACMR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_ACMR1 bitfields
 */

/* --- Register HW_MLB_ACMR1, field CHM */

#define BP_MLB_ACMR1_CHM      0
#define BM_MLB_ACMR1_CHM      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACMR1_CHM(v)   ((((reg32_t) v) << 0) & BM_MLB_ACMR1_CHM)
#else
#define BF_MLB_ACMR1_CHM(v)   (((v) << 0) & BM_MLB_ACMR1_CHM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACMR1_CHM(v)   BF_CS1(MLB_ACMR1, CHM, v)
#endif


#endif // _MLB_H

