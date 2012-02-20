/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _FLEXCAN_H
#define _FLEXCAN_H

#include "regs.h"

#ifndef REGS_FLEXCAN_BASE
#define REGS_FLEXCAN0_BASE (REGS_BASE + 0x02090000)
#define REGS_FLEXCAN1_BASE (REGS_BASE + 0x02094000)
#define REGS_FLEXCAN_BASE(x) ( x == 0 ? REGS_FLEXCAN0_BASE : x == 1 ? REGS_FLEXCAN1_BASE : 0xffff0000)

#endif


/*
 * HW_FLEXCAN_MCR - Module Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MDIS : 1;
        unsigned FRZ : 1;
        unsigned RFEN : 1;
        unsigned HALT : 1;
        unsigned NOT_RDY : 1;
        unsigned WAK_MSK : 1;
        unsigned SOFT_RST : 1;
        unsigned FRZ_ACK : 1;
        unsigned SUPV : 1;
        unsigned SLF_WAK : 1;
        unsigned WRN_EN : 1;
        unsigned LPM_ACK : 1;
        unsigned WAK_SRC : 1;
        unsigned RESERVED0 : 1;
        unsigned SRX_DIS : 1;
        unsigned IRMQ : 1;
        unsigned RESERVED1 : 2;
        unsigned LPRIO_EN : 1;
        unsigned AEN : 1;
        unsigned RESERVED2 : 2;
        unsigned IDAM : 2;
        unsigned RESERVED3 : 1;
        unsigned MAXMB : 7;

    } B;
} hw_flexcan_mcr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_MCR register
 */
#define HW_FLEXCAN_MCR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_MCR(x)           (*(volatile hw_flexcan_mcr_t *) HW_FLEXCAN_MCR_ADDR(x))
#define HW_FLEXCAN_MCR_RD(x)        (HW_FLEXCAN_MCR(x).U)
#define HW_FLEXCAN_MCR_WR(x, v)     (HW_FLEXCAN_MCR(x).U = (v))
#define HW_FLEXCAN_MCR_SET(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) |  (v)))
#define HW_FLEXCAN_MCR_CLR(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) & ~(v)))
#define HW_FLEXCAN_MCR_TOG(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_MCR bitfields
 */

/* --- Register HW_FLEXCAN_MCR, field MDIS */

#define BP_FLEXCAN_MCR_MDIS      31
#define BM_FLEXCAN_MCR_MDIS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_MDIS(v)   ((((reg32_t) v) << 31) & BM_FLEXCAN_MCR_MDIS)
#else
#define BF_FLEXCAN_MCR_MDIS(v)   (((v) << 31) & BM_FLEXCAN_MCR_MDIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_MDIS(v)   BF_CS1(FLEXCAN_MCR, MDIS, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field FRZ */

#define BP_FLEXCAN_MCR_FRZ      30
#define BM_FLEXCAN_MCR_FRZ      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_FRZ(v)   ((((reg32_t) v) << 30) & BM_FLEXCAN_MCR_FRZ)
#else
#define BF_FLEXCAN_MCR_FRZ(v)   (((v) << 30) & BM_FLEXCAN_MCR_FRZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_FRZ(v)   BF_CS1(FLEXCAN_MCR, FRZ, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field RFEN */

#define BP_FLEXCAN_MCR_RFEN      29
#define BM_FLEXCAN_MCR_RFEN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_RFEN(v)   ((((reg32_t) v) << 29) & BM_FLEXCAN_MCR_RFEN)
#else
#define BF_FLEXCAN_MCR_RFEN(v)   (((v) << 29) & BM_FLEXCAN_MCR_RFEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_RFEN(v)   BF_CS1(FLEXCAN_MCR, RFEN, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field HALT */

#define BP_FLEXCAN_MCR_HALT      28
#define BM_FLEXCAN_MCR_HALT      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_HALT(v)   ((((reg32_t) v) << 28) & BM_FLEXCAN_MCR_HALT)
#else
#define BF_FLEXCAN_MCR_HALT(v)   (((v) << 28) & BM_FLEXCAN_MCR_HALT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_HALT(v)   BF_CS1(FLEXCAN_MCR, HALT, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field NOT_RDY */

#define BP_FLEXCAN_MCR_NOT_RDY      27
#define BM_FLEXCAN_MCR_NOT_RDY      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_NOT_RDY(v)   ((((reg32_t) v) << 27) & BM_FLEXCAN_MCR_NOT_RDY)
#else
#define BF_FLEXCAN_MCR_NOT_RDY(v)   (((v) << 27) & BM_FLEXCAN_MCR_NOT_RDY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_NOT_RDY(v)   BF_CS1(FLEXCAN_MCR, NOT_RDY, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field WAK_MSK */

#define BP_FLEXCAN_MCR_WAK_MSK      26
#define BM_FLEXCAN_MCR_WAK_MSK      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_WAK_MSK(v)   ((((reg32_t) v) << 26) & BM_FLEXCAN_MCR_WAK_MSK)
#else
#define BF_FLEXCAN_MCR_WAK_MSK(v)   (((v) << 26) & BM_FLEXCAN_MCR_WAK_MSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_WAK_MSK(v)   BF_CS1(FLEXCAN_MCR, WAK_MSK, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field SOFT_RST */

#define BP_FLEXCAN_MCR_SOFT_RST      25
#define BM_FLEXCAN_MCR_SOFT_RST      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_SOFT_RST(v)   ((((reg32_t) v) << 25) & BM_FLEXCAN_MCR_SOFT_RST)
#else
#define BF_FLEXCAN_MCR_SOFT_RST(v)   (((v) << 25) & BM_FLEXCAN_MCR_SOFT_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_SOFT_RST(v)   BF_CS1(FLEXCAN_MCR, SOFT_RST, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field FRZ_ACK */

#define BP_FLEXCAN_MCR_FRZ_ACK      24
#define BM_FLEXCAN_MCR_FRZ_ACK      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_FRZ_ACK(v)   ((((reg32_t) v) << 24) & BM_FLEXCAN_MCR_FRZ_ACK)
#else
#define BF_FLEXCAN_MCR_FRZ_ACK(v)   (((v) << 24) & BM_FLEXCAN_MCR_FRZ_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_FRZ_ACK(v)   BF_CS1(FLEXCAN_MCR, FRZ_ACK, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field SUPV */

#define BP_FLEXCAN_MCR_SUPV      23
#define BM_FLEXCAN_MCR_SUPV      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_SUPV(v)   ((((reg32_t) v) << 23) & BM_FLEXCAN_MCR_SUPV)
#else
#define BF_FLEXCAN_MCR_SUPV(v)   (((v) << 23) & BM_FLEXCAN_MCR_SUPV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_SUPV(v)   BF_CS1(FLEXCAN_MCR, SUPV, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field SLF_WAK */

#define BP_FLEXCAN_MCR_SLF_WAK      22
#define BM_FLEXCAN_MCR_SLF_WAK      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_SLF_WAK(v)   ((((reg32_t) v) << 22) & BM_FLEXCAN_MCR_SLF_WAK)
#else
#define BF_FLEXCAN_MCR_SLF_WAK(v)   (((v) << 22) & BM_FLEXCAN_MCR_SLF_WAK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_SLF_WAK(v)   BF_CS1(FLEXCAN_MCR, SLF_WAK, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field WRN_EN */

#define BP_FLEXCAN_MCR_WRN_EN      21
#define BM_FLEXCAN_MCR_WRN_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_WRN_EN(v)   ((((reg32_t) v) << 21) & BM_FLEXCAN_MCR_WRN_EN)
#else
#define BF_FLEXCAN_MCR_WRN_EN(v)   (((v) << 21) & BM_FLEXCAN_MCR_WRN_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_WRN_EN(v)   BF_CS1(FLEXCAN_MCR, WRN_EN, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field LPM_ACK */

#define BP_FLEXCAN_MCR_LPM_ACK      20
#define BM_FLEXCAN_MCR_LPM_ACK      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_LPM_ACK(v)   ((((reg32_t) v) << 20) & BM_FLEXCAN_MCR_LPM_ACK)
#else
#define BF_FLEXCAN_MCR_LPM_ACK(v)   (((v) << 20) & BM_FLEXCAN_MCR_LPM_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_LPM_ACK(v)   BF_CS1(FLEXCAN_MCR, LPM_ACK, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field WAK_SRC */

#define BP_FLEXCAN_MCR_WAK_SRC      19
#define BM_FLEXCAN_MCR_WAK_SRC      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_WAK_SRC(v)   ((((reg32_t) v) << 19) & BM_FLEXCAN_MCR_WAK_SRC)
#else
#define BF_FLEXCAN_MCR_WAK_SRC(v)   (((v) << 19) & BM_FLEXCAN_MCR_WAK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_WAK_SRC(v)   BF_CS1(FLEXCAN_MCR, WAK_SRC, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field SRX_DIS */

#define BP_FLEXCAN_MCR_SRX_DIS      17
#define BM_FLEXCAN_MCR_SRX_DIS      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_SRX_DIS(v)   ((((reg32_t) v) << 17) & BM_FLEXCAN_MCR_SRX_DIS)
#else
#define BF_FLEXCAN_MCR_SRX_DIS(v)   (((v) << 17) & BM_FLEXCAN_MCR_SRX_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_SRX_DIS(v)   BF_CS1(FLEXCAN_MCR, SRX_DIS, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field IRMQ */

#define BP_FLEXCAN_MCR_IRMQ      16
#define BM_FLEXCAN_MCR_IRMQ      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_IRMQ(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_MCR_IRMQ)
#else
#define BF_FLEXCAN_MCR_IRMQ(v)   (((v) << 16) & BM_FLEXCAN_MCR_IRMQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_IRMQ(v)   BF_CS1(FLEXCAN_MCR, IRMQ, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field LPRIO_EN */

#define BP_FLEXCAN_MCR_LPRIO_EN      13
#define BM_FLEXCAN_MCR_LPRIO_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_LPRIO_EN(v)   ((((reg32_t) v) << 13) & BM_FLEXCAN_MCR_LPRIO_EN)
#else
#define BF_FLEXCAN_MCR_LPRIO_EN(v)   (((v) << 13) & BM_FLEXCAN_MCR_LPRIO_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_LPRIO_EN(v)   BF_CS1(FLEXCAN_MCR, LPRIO_EN, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field AEN */

#define BP_FLEXCAN_MCR_AEN      12
#define BM_FLEXCAN_MCR_AEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_AEN(v)   ((((reg32_t) v) << 12) & BM_FLEXCAN_MCR_AEN)
#else
#define BF_FLEXCAN_MCR_AEN(v)   (((v) << 12) & BM_FLEXCAN_MCR_AEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_AEN(v)   BF_CS1(FLEXCAN_MCR, AEN, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field IDAM */

#define BP_FLEXCAN_MCR_IDAM      8
#define BM_FLEXCAN_MCR_IDAM      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_IDAM(v)   ((((reg32_t) v) << 8) & BM_FLEXCAN_MCR_IDAM)
#else
#define BF_FLEXCAN_MCR_IDAM(v)   (((v) << 8) & BM_FLEXCAN_MCR_IDAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_IDAM(v)   BF_CS1(FLEXCAN_MCR, IDAM, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field MAXMB */

#define BP_FLEXCAN_MCR_MAXMB      0
#define BM_FLEXCAN_MCR_MAXMB      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_MAXMB(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_MCR_MAXMB)
#else
#define BF_FLEXCAN_MCR_MAXMB(v)   (((v) << 0) & BM_FLEXCAN_MCR_MAXMB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_MCR_MAXMB(v)   BF_CS1(FLEXCAN_MCR, MAXMB, v)
#endif

/*
 * HW_FLEXCAN_CTRL1 - Control 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PRESDIV : 8;
        unsigned RJW : 2;
        unsigned PSEG1 : 3;
        unsigned PSEG2 : 3;
        unsigned BOFF_MSK : 1;
        unsigned ERR_MSK : 1;
        unsigned RESERVED0 : 1;
        unsigned LPB : 1;
        unsigned TWRN_MSK : 1;
        unsigned RWRN_MSK : 1;
        unsigned RESERVED1 : 2;
        unsigned SMP : 1;
        unsigned BOFF_REC : 1;
        unsigned TSYN : 1;
        unsigned LBUF : 1;
        unsigned LOM : 1;
        unsigned PROP_SEG : 3;

    } B;
} hw_flexcan_ctrl1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_CTRL1 register
 */
#define HW_FLEXCAN_CTRL1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_CTRL1(x)           (*(volatile hw_flexcan_ctrl1_t *) HW_FLEXCAN_CTRL1_ADDR(x))
#define HW_FLEXCAN_CTRL1_RD(x)        (HW_FLEXCAN_CTRL1(x).U)
#define HW_FLEXCAN_CTRL1_WR(x, v)     (HW_FLEXCAN_CTRL1(x).U = (v))
#define HW_FLEXCAN_CTRL1_SET(x, v)    (HW_FLEXCAN_CTRL1_WR(x, HW_FLEXCAN_CTRL1_RD(x) |  (v)))
#define HW_FLEXCAN_CTRL1_CLR(x, v)    (HW_FLEXCAN_CTRL1_WR(x, HW_FLEXCAN_CTRL1_RD(x) & ~(v)))
#define HW_FLEXCAN_CTRL1_TOG(x, v)    (HW_FLEXCAN_CTRL1_WR(x, HW_FLEXCAN_CTRL1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_CTRL1 bitfields
 */

/* --- Register HW_FLEXCAN_CTRL1, field PRESDIV */

#define BP_FLEXCAN_CTRL1_PRESDIV      24
#define BM_FLEXCAN_CTRL1_PRESDIV      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_PRESDIV(v)   ((((reg32_t) v) << 24) & BM_FLEXCAN_CTRL1_PRESDIV)
#else
#define BF_FLEXCAN_CTRL1_PRESDIV(v)   (((v) << 24) & BM_FLEXCAN_CTRL1_PRESDIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_PRESDIV(v)   BF_CS1(FLEXCAN_CTRL1, PRESDIV, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field RJW */

#define BP_FLEXCAN_CTRL1_RJW      22
#define BM_FLEXCAN_CTRL1_RJW      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_RJW(v)   ((((reg32_t) v) << 22) & BM_FLEXCAN_CTRL1_RJW)
#else
#define BF_FLEXCAN_CTRL1_RJW(v)   (((v) << 22) & BM_FLEXCAN_CTRL1_RJW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_RJW(v)   BF_CS1(FLEXCAN_CTRL1, RJW, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field PSEG1 */

#define BP_FLEXCAN_CTRL1_PSEG1      19
#define BM_FLEXCAN_CTRL1_PSEG1      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_PSEG1(v)   ((((reg32_t) v) << 19) & BM_FLEXCAN_CTRL1_PSEG1)
#else
#define BF_FLEXCAN_CTRL1_PSEG1(v)   (((v) << 19) & BM_FLEXCAN_CTRL1_PSEG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_PSEG1(v)   BF_CS1(FLEXCAN_CTRL1, PSEG1, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field PSEG2 */

#define BP_FLEXCAN_CTRL1_PSEG2      16
#define BM_FLEXCAN_CTRL1_PSEG2      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_PSEG2(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_CTRL1_PSEG2)
#else
#define BF_FLEXCAN_CTRL1_PSEG2(v)   (((v) << 16) & BM_FLEXCAN_CTRL1_PSEG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_PSEG2(v)   BF_CS1(FLEXCAN_CTRL1, PSEG2, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field BOFF_MSK */

#define BP_FLEXCAN_CTRL1_BOFF_MSK      15
#define BM_FLEXCAN_CTRL1_BOFF_MSK      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_BOFF_MSK(v)   ((((reg32_t) v) << 15) & BM_FLEXCAN_CTRL1_BOFF_MSK)
#else
#define BF_FLEXCAN_CTRL1_BOFF_MSK(v)   (((v) << 15) & BM_FLEXCAN_CTRL1_BOFF_MSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_BOFF_MSK(v)   BF_CS1(FLEXCAN_CTRL1, BOFF_MSK, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field ERR_MSK */

#define BP_FLEXCAN_CTRL1_ERR_MSK      14
#define BM_FLEXCAN_CTRL1_ERR_MSK      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_ERR_MSK(v)   ((((reg32_t) v) << 14) & BM_FLEXCAN_CTRL1_ERR_MSK)
#else
#define BF_FLEXCAN_CTRL1_ERR_MSK(v)   (((v) << 14) & BM_FLEXCAN_CTRL1_ERR_MSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_ERR_MSK(v)   BF_CS1(FLEXCAN_CTRL1, ERR_MSK, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field LPB */

#define BP_FLEXCAN_CTRL1_LPB      12
#define BM_FLEXCAN_CTRL1_LPB      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_LPB(v)   ((((reg32_t) v) << 12) & BM_FLEXCAN_CTRL1_LPB)
#else
#define BF_FLEXCAN_CTRL1_LPB(v)   (((v) << 12) & BM_FLEXCAN_CTRL1_LPB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_LPB(v)   BF_CS1(FLEXCAN_CTRL1, LPB, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field TWRN_MSK */

#define BP_FLEXCAN_CTRL1_TWRN_MSK      11
#define BM_FLEXCAN_CTRL1_TWRN_MSK      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_TWRN_MSK(v)   ((((reg32_t) v) << 11) & BM_FLEXCAN_CTRL1_TWRN_MSK)
#else
#define BF_FLEXCAN_CTRL1_TWRN_MSK(v)   (((v) << 11) & BM_FLEXCAN_CTRL1_TWRN_MSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_TWRN_MSK(v)   BF_CS1(FLEXCAN_CTRL1, TWRN_MSK, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field RWRN_MSK */

#define BP_FLEXCAN_CTRL1_RWRN_MSK      10
#define BM_FLEXCAN_CTRL1_RWRN_MSK      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_RWRN_MSK(v)   ((((reg32_t) v) << 10) & BM_FLEXCAN_CTRL1_RWRN_MSK)
#else
#define BF_FLEXCAN_CTRL1_RWRN_MSK(v)   (((v) << 10) & BM_FLEXCAN_CTRL1_RWRN_MSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_RWRN_MSK(v)   BF_CS1(FLEXCAN_CTRL1, RWRN_MSK, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field SMP */

#define BP_FLEXCAN_CTRL1_SMP      7
#define BM_FLEXCAN_CTRL1_SMP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_SMP(v)   ((((reg32_t) v) << 7) & BM_FLEXCAN_CTRL1_SMP)
#else
#define BF_FLEXCAN_CTRL1_SMP(v)   (((v) << 7) & BM_FLEXCAN_CTRL1_SMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_SMP(v)   BF_CS1(FLEXCAN_CTRL1, SMP, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field BOFF_REC */

#define BP_FLEXCAN_CTRL1_BOFF_REC      6
#define BM_FLEXCAN_CTRL1_BOFF_REC      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_BOFF_REC(v)   ((((reg32_t) v) << 6) & BM_FLEXCAN_CTRL1_BOFF_REC)
#else
#define BF_FLEXCAN_CTRL1_BOFF_REC(v)   (((v) << 6) & BM_FLEXCAN_CTRL1_BOFF_REC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_BOFF_REC(v)   BF_CS1(FLEXCAN_CTRL1, BOFF_REC, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field TSYN */

#define BP_FLEXCAN_CTRL1_TSYN      5
#define BM_FLEXCAN_CTRL1_TSYN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_TSYN(v)   ((((reg32_t) v) << 5) & BM_FLEXCAN_CTRL1_TSYN)
#else
#define BF_FLEXCAN_CTRL1_TSYN(v)   (((v) << 5) & BM_FLEXCAN_CTRL1_TSYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_TSYN(v)   BF_CS1(FLEXCAN_CTRL1, TSYN, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field LBUF */

#define BP_FLEXCAN_CTRL1_LBUF      4
#define BM_FLEXCAN_CTRL1_LBUF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_LBUF(v)   ((((reg32_t) v) << 4) & BM_FLEXCAN_CTRL1_LBUF)
#else
#define BF_FLEXCAN_CTRL1_LBUF(v)   (((v) << 4) & BM_FLEXCAN_CTRL1_LBUF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_LBUF(v)   BF_CS1(FLEXCAN_CTRL1, LBUF, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field LOM */

#define BP_FLEXCAN_CTRL1_LOM      3
#define BM_FLEXCAN_CTRL1_LOM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_LOM(v)   ((((reg32_t) v) << 3) & BM_FLEXCAN_CTRL1_LOM)
#else
#define BF_FLEXCAN_CTRL1_LOM(v)   (((v) << 3) & BM_FLEXCAN_CTRL1_LOM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_LOM(v)   BF_CS1(FLEXCAN_CTRL1, LOM, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field PROP_SEG */

#define BP_FLEXCAN_CTRL1_PROP_SEG      0
#define BM_FLEXCAN_CTRL1_PROP_SEG      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_PROP_SEG(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_CTRL1_PROP_SEG)
#else
#define BF_FLEXCAN_CTRL1_PROP_SEG(v)   (((v) << 0) & BM_FLEXCAN_CTRL1_PROP_SEG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL1_PROP_SEG(v)   BF_CS1(FLEXCAN_CTRL1, PROP_SEG, v)
#endif

/*
 * HW_FLEXCAN_TIMER - Free Running Timer Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned TIMER : 16;

    } B;
} hw_flexcan_timer_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_TIMER register
 */
#define HW_FLEXCAN_TIMER_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_TIMER(x)           (*(volatile hw_flexcan_timer_t *) HW_FLEXCAN_TIMER_ADDR(x))
#define HW_FLEXCAN_TIMER_RD(x)        (HW_FLEXCAN_TIMER(x).U)
#define HW_FLEXCAN_TIMER_WR(x, v)     (HW_FLEXCAN_TIMER(x).U = (v))
#define HW_FLEXCAN_TIMER_SET(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) |  (v)))
#define HW_FLEXCAN_TIMER_CLR(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) & ~(v)))
#define HW_FLEXCAN_TIMER_TOG(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_TIMER bitfields
 */

/* --- Register HW_FLEXCAN_TIMER, field TIMER */

#define BP_FLEXCAN_TIMER_TIMER      0
#define BM_FLEXCAN_TIMER_TIMER      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_TIMER_TIMER(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_TIMER_TIMER)
#else
#define BF_FLEXCAN_TIMER_TIMER(v)   (((v) << 0) & BM_FLEXCAN_TIMER_TIMER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_TIMER_TIMER(v)   BF_CS1(FLEXCAN_TIMER, TIMER, v)
#endif

/*
 * HW_FLEXCAN_RXMGMASK - Rx Mailboxes Global Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MG31 : 32;

    } B;
} hw_flexcan_rxmgmask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXMGMASK register
 */
#define HW_FLEXCAN_RXMGMASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXMGMASK(x)           (*(volatile hw_flexcan_rxmgmask_t *) HW_FLEXCAN_RXMGMASK_ADDR(x))
#define HW_FLEXCAN_RXMGMASK_RD(x)        (HW_FLEXCAN_RXMGMASK(x).U)
#define HW_FLEXCAN_RXMGMASK_WR(x, v)     (HW_FLEXCAN_RXMGMASK(x).U = (v))
#define HW_FLEXCAN_RXMGMASK_SET(x, v)    (HW_FLEXCAN_RXMGMASK_WR(x, HW_FLEXCAN_RXMGMASK_RD(x) |  (v)))
#define HW_FLEXCAN_RXMGMASK_CLR(x, v)    (HW_FLEXCAN_RXMGMASK_WR(x, HW_FLEXCAN_RXMGMASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RXMGMASK_TOG(x, v)    (HW_FLEXCAN_RXMGMASK_WR(x, HW_FLEXCAN_RXMGMASK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_RXMGMASK bitfields
 */

/* --- Register HW_FLEXCAN_RXMGMASK, field MG31 */

#define BP_FLEXCAN_RXMGMASK_MG31      0
#define BM_FLEXCAN_RXMGMASK_MG31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RXMGMASK_MG31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RXMGMASK_MG31)
#else
#define BF_FLEXCAN_RXMGMASK_MG31(v)   (((v) << 0) & BM_FLEXCAN_RXMGMASK_MG31)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_RXMGMASK_MG31(v)   BF_CS1(FLEXCAN_RXMGMASK, MG31, v)
#endif

/*
 * HW_FLEXCAN_RX14MASK - Rx Buffer 14 Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RX14M31 : 32;

    } B;
} hw_flexcan_rx14mask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RX14MASK register
 */
#define HW_FLEXCAN_RX14MASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RX14MASK(x)           (*(volatile hw_flexcan_rx14mask_t *) HW_FLEXCAN_RX14MASK_ADDR(x))
#define HW_FLEXCAN_RX14MASK_RD(x)        (HW_FLEXCAN_RX14MASK(x).U)
#define HW_FLEXCAN_RX14MASK_WR(x, v)     (HW_FLEXCAN_RX14MASK(x).U = (v))
#define HW_FLEXCAN_RX14MASK_SET(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) |  (v)))
#define HW_FLEXCAN_RX14MASK_CLR(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RX14MASK_TOG(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_RX14MASK bitfields
 */

/* --- Register HW_FLEXCAN_RX14MASK, field RX14M31 */

#define BP_FLEXCAN_RX14MASK_RX14M31      0
#define BM_FLEXCAN_RX14MASK_RX14M31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RX14MASK_RX14M31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RX14MASK_RX14M31)
#else
#define BF_FLEXCAN_RX14MASK_RX14M31(v)   (((v) << 0) & BM_FLEXCAN_RX14MASK_RX14M31)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_RX14MASK_RX14M31(v)   BF_CS1(FLEXCAN_RX14MASK, RX14M31, v)
#endif

/*
 * HW_FLEXCAN_RX15MASK - Rx Buffer 15 Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RX15M31 : 32;

    } B;
} hw_flexcan_rx15mask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RX15MASK register
 */
#define HW_FLEXCAN_RX15MASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RX15MASK(x)           (*(volatile hw_flexcan_rx15mask_t *) HW_FLEXCAN_RX15MASK_ADDR(x))
#define HW_FLEXCAN_RX15MASK_RD(x)        (HW_FLEXCAN_RX15MASK(x).U)
#define HW_FLEXCAN_RX15MASK_WR(x, v)     (HW_FLEXCAN_RX15MASK(x).U = (v))
#define HW_FLEXCAN_RX15MASK_SET(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) |  (v)))
#define HW_FLEXCAN_RX15MASK_CLR(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RX15MASK_TOG(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_RX15MASK bitfields
 */

/* --- Register HW_FLEXCAN_RX15MASK, field RX15M31 */

#define BP_FLEXCAN_RX15MASK_RX15M31      0
#define BM_FLEXCAN_RX15MASK_RX15M31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RX15MASK_RX15M31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RX15MASK_RX15M31)
#else
#define BF_FLEXCAN_RX15MASK_RX15M31(v)   (((v) << 0) & BM_FLEXCAN_RX15MASK_RX15M31)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_RX15MASK_RX15M31(v)   BF_CS1(FLEXCAN_RX15MASK, RX15M31, v)
#endif

/*
 * HW_FLEXCAN_ECR - Error Counter Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RX_ERR_COUNTER : 8;
        unsigned TX_ERR_COUNTER : 8;

    } B;
} hw_flexcan_ecr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_ECR register
 */
#define HW_FLEXCAN_ECR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_ECR(x)           (*(volatile hw_flexcan_ecr_t *) HW_FLEXCAN_ECR_ADDR(x))
#define HW_FLEXCAN_ECR_RD(x)        (HW_FLEXCAN_ECR(x).U)
#define HW_FLEXCAN_ECR_WR(x, v)     (HW_FLEXCAN_ECR(x).U = (v))
#define HW_FLEXCAN_ECR_SET(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) |  (v)))
#define HW_FLEXCAN_ECR_CLR(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) & ~(v)))
#define HW_FLEXCAN_ECR_TOG(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_ECR bitfields
 */

/* --- Register HW_FLEXCAN_ECR, field RX_ERR_COUNTER */

#define BP_FLEXCAN_ECR_RX_ERR_COUNTER      8
#define BM_FLEXCAN_ECR_RX_ERR_COUNTER      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ECR_RX_ERR_COUNTER(v)   ((((reg32_t) v) << 8) & BM_FLEXCAN_ECR_RX_ERR_COUNTER)
#else
#define BF_FLEXCAN_ECR_RX_ERR_COUNTER(v)   (((v) << 8) & BM_FLEXCAN_ECR_RX_ERR_COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ECR_RX_ERR_COUNTER(v)   BF_CS1(FLEXCAN_ECR, RX_ERR_COUNTER, v)
#endif

/* --- Register HW_FLEXCAN_ECR, field TX_ERR_COUNTER */

#define BP_FLEXCAN_ECR_TX_ERR_COUNTER      0
#define BM_FLEXCAN_ECR_TX_ERR_COUNTER      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ECR_TX_ERR_COUNTER(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_ECR_TX_ERR_COUNTER)
#else
#define BF_FLEXCAN_ECR_TX_ERR_COUNTER(v)   (((v) << 0) & BM_FLEXCAN_ECR_TX_ERR_COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ECR_TX_ERR_COUNTER(v)   BF_CS1(FLEXCAN_ECR, TX_ERR_COUNTER, v)
#endif

/*
 * HW_FLEXCAN_ESR1 - Error and Status 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 13;
        unsigned SYNCH : 1;
        unsigned TWRN_INT : 1;
        unsigned RWRN_INT : 1;
        unsigned BIT1_ERR : 1;
        unsigned BIT0_ERR : 1;
        unsigned ACK_ERR : 1;
        unsigned CRC_ERR : 1;
        unsigned FRM_ERR : 1;
        unsigned STF_ERR : 1;
        unsigned TX_WRN : 1;
        unsigned RX_WRN : 1;
        unsigned IDLE : 1;
        unsigned TX : 1;
        unsigned FLT_CONF : 2;
        unsigned RX : 1;
        unsigned BOFF_INT : 1;
        unsigned ERR_INT : 1;
        unsigned WAK_INT : 1;

    } B;
} hw_flexcan_esr1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_ESR1 register
 */
#define HW_FLEXCAN_ESR1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_ESR1(x)           (*(volatile hw_flexcan_esr1_t *) HW_FLEXCAN_ESR1_ADDR(x))
#define HW_FLEXCAN_ESR1_RD(x)        (HW_FLEXCAN_ESR1(x).U)
#define HW_FLEXCAN_ESR1_WR(x, v)     (HW_FLEXCAN_ESR1(x).U = (v))
#define HW_FLEXCAN_ESR1_SET(x, v)    (HW_FLEXCAN_ESR1_WR(x, HW_FLEXCAN_ESR1_RD(x) |  (v)))
#define HW_FLEXCAN_ESR1_CLR(x, v)    (HW_FLEXCAN_ESR1_WR(x, HW_FLEXCAN_ESR1_RD(x) & ~(v)))
#define HW_FLEXCAN_ESR1_TOG(x, v)    (HW_FLEXCAN_ESR1_WR(x, HW_FLEXCAN_ESR1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_ESR1 bitfields
 */

/* --- Register HW_FLEXCAN_ESR1, field SYNCH */

#define BP_FLEXCAN_ESR1_SYNCH      18
#define BM_FLEXCAN_ESR1_SYNCH      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_SYNCH(v)   ((((reg32_t) v) << 18) & BM_FLEXCAN_ESR1_SYNCH)
#else
#define BF_FLEXCAN_ESR1_SYNCH(v)   (((v) << 18) & BM_FLEXCAN_ESR1_SYNCH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_SYNCH(v)   BF_CS1(FLEXCAN_ESR1, SYNCH, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field TWRN_INT */

#define BP_FLEXCAN_ESR1_TWRN_INT      17
#define BM_FLEXCAN_ESR1_TWRN_INT      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_TWRN_INT(v)   ((((reg32_t) v) << 17) & BM_FLEXCAN_ESR1_TWRN_INT)
#else
#define BF_FLEXCAN_ESR1_TWRN_INT(v)   (((v) << 17) & BM_FLEXCAN_ESR1_TWRN_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_TWRN_INT(v)   BF_CS1(FLEXCAN_ESR1, TWRN_INT, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field RWRN_INT */

#define BP_FLEXCAN_ESR1_RWRN_INT      16
#define BM_FLEXCAN_ESR1_RWRN_INT      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_RWRN_INT(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_ESR1_RWRN_INT)
#else
#define BF_FLEXCAN_ESR1_RWRN_INT(v)   (((v) << 16) & BM_FLEXCAN_ESR1_RWRN_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_RWRN_INT(v)   BF_CS1(FLEXCAN_ESR1, RWRN_INT, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field BIT1_ERR */

#define BP_FLEXCAN_ESR1_BIT1_ERR      15
#define BM_FLEXCAN_ESR1_BIT1_ERR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_BIT1_ERR(v)   ((((reg32_t) v) << 15) & BM_FLEXCAN_ESR1_BIT1_ERR)
#else
#define BF_FLEXCAN_ESR1_BIT1_ERR(v)   (((v) << 15) & BM_FLEXCAN_ESR1_BIT1_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_BIT1_ERR(v)   BF_CS1(FLEXCAN_ESR1, BIT1_ERR, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field BIT0_ERR */

#define BP_FLEXCAN_ESR1_BIT0_ERR      14
#define BM_FLEXCAN_ESR1_BIT0_ERR      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_BIT0_ERR(v)   ((((reg32_t) v) << 14) & BM_FLEXCAN_ESR1_BIT0_ERR)
#else
#define BF_FLEXCAN_ESR1_BIT0_ERR(v)   (((v) << 14) & BM_FLEXCAN_ESR1_BIT0_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_BIT0_ERR(v)   BF_CS1(FLEXCAN_ESR1, BIT0_ERR, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field ACK_ERR */

#define BP_FLEXCAN_ESR1_ACK_ERR      13
#define BM_FLEXCAN_ESR1_ACK_ERR      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_ACK_ERR(v)   ((((reg32_t) v) << 13) & BM_FLEXCAN_ESR1_ACK_ERR)
#else
#define BF_FLEXCAN_ESR1_ACK_ERR(v)   (((v) << 13) & BM_FLEXCAN_ESR1_ACK_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_ACK_ERR(v)   BF_CS1(FLEXCAN_ESR1, ACK_ERR, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field CRC_ERR */

#define BP_FLEXCAN_ESR1_CRC_ERR      12
#define BM_FLEXCAN_ESR1_CRC_ERR      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_CRC_ERR(v)   ((((reg32_t) v) << 12) & BM_FLEXCAN_ESR1_CRC_ERR)
#else
#define BF_FLEXCAN_ESR1_CRC_ERR(v)   (((v) << 12) & BM_FLEXCAN_ESR1_CRC_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_CRC_ERR(v)   BF_CS1(FLEXCAN_ESR1, CRC_ERR, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field FRM_ERR */

#define BP_FLEXCAN_ESR1_FRM_ERR      11
#define BM_FLEXCAN_ESR1_FRM_ERR      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_FRM_ERR(v)   ((((reg32_t) v) << 11) & BM_FLEXCAN_ESR1_FRM_ERR)
#else
#define BF_FLEXCAN_ESR1_FRM_ERR(v)   (((v) << 11) & BM_FLEXCAN_ESR1_FRM_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_FRM_ERR(v)   BF_CS1(FLEXCAN_ESR1, FRM_ERR, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field STF_ERR */

#define BP_FLEXCAN_ESR1_STF_ERR      10
#define BM_FLEXCAN_ESR1_STF_ERR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_STF_ERR(v)   ((((reg32_t) v) << 10) & BM_FLEXCAN_ESR1_STF_ERR)
#else
#define BF_FLEXCAN_ESR1_STF_ERR(v)   (((v) << 10) & BM_FLEXCAN_ESR1_STF_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_STF_ERR(v)   BF_CS1(FLEXCAN_ESR1, STF_ERR, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field TX_WRN */

#define BP_FLEXCAN_ESR1_TX_WRN      9
#define BM_FLEXCAN_ESR1_TX_WRN      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_TX_WRN(v)   ((((reg32_t) v) << 9) & BM_FLEXCAN_ESR1_TX_WRN)
#else
#define BF_FLEXCAN_ESR1_TX_WRN(v)   (((v) << 9) & BM_FLEXCAN_ESR1_TX_WRN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_TX_WRN(v)   BF_CS1(FLEXCAN_ESR1, TX_WRN, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field RX_WRN */

#define BP_FLEXCAN_ESR1_RX_WRN      8
#define BM_FLEXCAN_ESR1_RX_WRN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_RX_WRN(v)   ((((reg32_t) v) << 8) & BM_FLEXCAN_ESR1_RX_WRN)
#else
#define BF_FLEXCAN_ESR1_RX_WRN(v)   (((v) << 8) & BM_FLEXCAN_ESR1_RX_WRN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_RX_WRN(v)   BF_CS1(FLEXCAN_ESR1, RX_WRN, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field IDLE */

#define BP_FLEXCAN_ESR1_IDLE      7
#define BM_FLEXCAN_ESR1_IDLE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_IDLE(v)   ((((reg32_t) v) << 7) & BM_FLEXCAN_ESR1_IDLE)
#else
#define BF_FLEXCAN_ESR1_IDLE(v)   (((v) << 7) & BM_FLEXCAN_ESR1_IDLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_IDLE(v)   BF_CS1(FLEXCAN_ESR1, IDLE, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field TX */

#define BP_FLEXCAN_ESR1_TX      6
#define BM_FLEXCAN_ESR1_TX      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_TX(v)   ((((reg32_t) v) << 6) & BM_FLEXCAN_ESR1_TX)
#else
#define BF_FLEXCAN_ESR1_TX(v)   (((v) << 6) & BM_FLEXCAN_ESR1_TX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_TX(v)   BF_CS1(FLEXCAN_ESR1, TX, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field FLT_CONF */

#define BP_FLEXCAN_ESR1_FLT_CONF      4
#define BM_FLEXCAN_ESR1_FLT_CONF      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_FLT_CONF(v)   ((((reg32_t) v) << 4) & BM_FLEXCAN_ESR1_FLT_CONF)
#else
#define BF_FLEXCAN_ESR1_FLT_CONF(v)   (((v) << 4) & BM_FLEXCAN_ESR1_FLT_CONF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_FLT_CONF(v)   BF_CS1(FLEXCAN_ESR1, FLT_CONF, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field RX */

#define BP_FLEXCAN_ESR1_RX      3
#define BM_FLEXCAN_ESR1_RX      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_RX(v)   ((((reg32_t) v) << 3) & BM_FLEXCAN_ESR1_RX)
#else
#define BF_FLEXCAN_ESR1_RX(v)   (((v) << 3) & BM_FLEXCAN_ESR1_RX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_RX(v)   BF_CS1(FLEXCAN_ESR1, RX, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field BOFF_INT */

#define BP_FLEXCAN_ESR1_BOFF_INT      2
#define BM_FLEXCAN_ESR1_BOFF_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_BOFF_INT(v)   ((((reg32_t) v) << 2) & BM_FLEXCAN_ESR1_BOFF_INT)
#else
#define BF_FLEXCAN_ESR1_BOFF_INT(v)   (((v) << 2) & BM_FLEXCAN_ESR1_BOFF_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_BOFF_INT(v)   BF_CS1(FLEXCAN_ESR1, BOFF_INT, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field ERR_INT */

#define BP_FLEXCAN_ESR1_ERR_INT      1
#define BM_FLEXCAN_ESR1_ERR_INT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_ERR_INT(v)   ((((reg32_t) v) << 1) & BM_FLEXCAN_ESR1_ERR_INT)
#else
#define BF_FLEXCAN_ESR1_ERR_INT(v)   (((v) << 1) & BM_FLEXCAN_ESR1_ERR_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_ERR_INT(v)   BF_CS1(FLEXCAN_ESR1, ERR_INT, v)
#endif

/* --- Register HW_FLEXCAN_ESR1, field WAK_INT */

#define BP_FLEXCAN_ESR1_WAK_INT      0
#define BM_FLEXCAN_ESR1_WAK_INT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_WAK_INT(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_ESR1_WAK_INT)
#else
#define BF_FLEXCAN_ESR1_WAK_INT(v)   (((v) << 0) & BM_FLEXCAN_ESR1_WAK_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR1_WAK_INT(v)   BF_CS1(FLEXCAN_ESR1, WAK_INT, v)
#endif

/*
 * HW_FLEXCAN_IMASK2 - Interrupt Masks 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUF63M : 32;

    } B;
} hw_flexcan_imask2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IMASK2 register
 */
#define HW_FLEXCAN_IMASK2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IMASK2(x)           (*(volatile hw_flexcan_imask2_t *) HW_FLEXCAN_IMASK2_ADDR(x))
#define HW_FLEXCAN_IMASK2_RD(x)        (HW_FLEXCAN_IMASK2(x).U)
#define HW_FLEXCAN_IMASK2_WR(x, v)     (HW_FLEXCAN_IMASK2(x).U = (v))
#define HW_FLEXCAN_IMASK2_SET(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) |  (v)))
#define HW_FLEXCAN_IMASK2_CLR(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) & ~(v)))
#define HW_FLEXCAN_IMASK2_TOG(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_IMASK2 bitfields
 */

/* --- Register HW_FLEXCAN_IMASK2, field BUF63M */

#define BP_FLEXCAN_IMASK2_BUF63M      0
#define BM_FLEXCAN_IMASK2_BUF63M      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IMASK2_BUF63M(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IMASK2_BUF63M)
#else
#define BF_FLEXCAN_IMASK2_BUF63M(v)   (((v) << 0) & BM_FLEXCAN_IMASK2_BUF63M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IMASK2_BUF63M(v)   BF_CS1(FLEXCAN_IMASK2, BUF63M, v)
#endif

/*
 * HW_FLEXCAN_IMASK1 - Interrupt Masks 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUF31M : 32;

    } B;
} hw_flexcan_imask1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IMASK1 register
 */
#define HW_FLEXCAN_IMASK1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IMASK1(x)           (*(volatile hw_flexcan_imask1_t *) HW_FLEXCAN_IMASK1_ADDR(x))
#define HW_FLEXCAN_IMASK1_RD(x)        (HW_FLEXCAN_IMASK1(x).U)
#define HW_FLEXCAN_IMASK1_WR(x, v)     (HW_FLEXCAN_IMASK1(x).U = (v))
#define HW_FLEXCAN_IMASK1_SET(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) |  (v)))
#define HW_FLEXCAN_IMASK1_CLR(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) & ~(v)))
#define HW_FLEXCAN_IMASK1_TOG(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_IMASK1 bitfields
 */

/* --- Register HW_FLEXCAN_IMASK1, field BUF31M */

#define BP_FLEXCAN_IMASK1_BUF31M      0
#define BM_FLEXCAN_IMASK1_BUF31M      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IMASK1_BUF31M(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IMASK1_BUF31M)
#else
#define BF_FLEXCAN_IMASK1_BUF31M(v)   (((v) << 0) & BM_FLEXCAN_IMASK1_BUF31M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IMASK1_BUF31M(v)   BF_CS1(FLEXCAN_IMASK1, BUF31M, v)
#endif

/*
 * HW_FLEXCAN_IFLAG2 - Interrupt Flags 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUF63I : 32;

    } B;
} hw_flexcan_iflag2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IFLAG2 register
 */
#define HW_FLEXCAN_IFLAG2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IFLAG2(x)           (*(volatile hw_flexcan_iflag2_t *) HW_FLEXCAN_IFLAG2_ADDR(x))
#define HW_FLEXCAN_IFLAG2_RD(x)        (HW_FLEXCAN_IFLAG2(x).U)
#define HW_FLEXCAN_IFLAG2_WR(x, v)     (HW_FLEXCAN_IFLAG2(x).U = (v))
#define HW_FLEXCAN_IFLAG2_SET(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) |  (v)))
#define HW_FLEXCAN_IFLAG2_CLR(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) & ~(v)))
#define HW_FLEXCAN_IFLAG2_TOG(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_IFLAG2 bitfields
 */

/* --- Register HW_FLEXCAN_IFLAG2, field BUF63I */

#define BP_FLEXCAN_IFLAG2_BUF63I      0
#define BM_FLEXCAN_IFLAG2_BUF63I      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG2_BUF63I(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IFLAG2_BUF63I)
#else
#define BF_FLEXCAN_IFLAG2_BUF63I(v)   (((v) << 0) & BM_FLEXCAN_IFLAG2_BUF63I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IFLAG2_BUF63I(v)   BF_CS1(FLEXCAN_IFLAG2, BUF63I, v)
#endif

/*
 * HW_FLEXCAN_IFLAG1 - Interrupt Flags 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUF31I : 24;
        unsigned BUF7I : 1;
        unsigned BUF6I : 1;
        unsigned BUF5I : 1;
        unsigned BUF4I : 5;

    } B;
} hw_flexcan_iflag1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IFLAG1 register
 */
#define HW_FLEXCAN_IFLAG1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IFLAG1(x)           (*(volatile hw_flexcan_iflag1_t *) HW_FLEXCAN_IFLAG1_ADDR(x))
#define HW_FLEXCAN_IFLAG1_RD(x)        (HW_FLEXCAN_IFLAG1(x).U)
#define HW_FLEXCAN_IFLAG1_WR(x, v)     (HW_FLEXCAN_IFLAG1(x).U = (v))
#define HW_FLEXCAN_IFLAG1_SET(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) |  (v)))
#define HW_FLEXCAN_IFLAG1_CLR(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) & ~(v)))
#define HW_FLEXCAN_IFLAG1_TOG(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_IFLAG1 bitfields
 */

/* --- Register HW_FLEXCAN_IFLAG1, field BUF31I */

#define BP_FLEXCAN_IFLAG1_BUF31I      8
#define BM_FLEXCAN_IFLAG1_BUF31I      0xffffff00

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF31I(v)   ((((reg32_t) v) << 8) & BM_FLEXCAN_IFLAG1_BUF31I)
#else
#define BF_FLEXCAN_IFLAG1_BUF31I(v)   (((v) << 8) & BM_FLEXCAN_IFLAG1_BUF31I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IFLAG1_BUF31I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF31I, v)
#endif

/* --- Register HW_FLEXCAN_IFLAG1, field BUF7I */

#define BP_FLEXCAN_IFLAG1_BUF7I      7
#define BM_FLEXCAN_IFLAG1_BUF7I      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF7I(v)   ((((reg32_t) v) << 7) & BM_FLEXCAN_IFLAG1_BUF7I)
#else
#define BF_FLEXCAN_IFLAG1_BUF7I(v)   (((v) << 7) & BM_FLEXCAN_IFLAG1_BUF7I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IFLAG1_BUF7I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF7I, v)
#endif

/* --- Register HW_FLEXCAN_IFLAG1, field BUF6I */

#define BP_FLEXCAN_IFLAG1_BUF6I      6
#define BM_FLEXCAN_IFLAG1_BUF6I      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF6I(v)   ((((reg32_t) v) << 6) & BM_FLEXCAN_IFLAG1_BUF6I)
#else
#define BF_FLEXCAN_IFLAG1_BUF6I(v)   (((v) << 6) & BM_FLEXCAN_IFLAG1_BUF6I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IFLAG1_BUF6I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF6I, v)
#endif

/* --- Register HW_FLEXCAN_IFLAG1, field BUF5I */

#define BP_FLEXCAN_IFLAG1_BUF5I      5
#define BM_FLEXCAN_IFLAG1_BUF5I      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF5I(v)   ((((reg32_t) v) << 5) & BM_FLEXCAN_IFLAG1_BUF5I)
#else
#define BF_FLEXCAN_IFLAG1_BUF5I(v)   (((v) << 5) & BM_FLEXCAN_IFLAG1_BUF5I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IFLAG1_BUF5I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF5I, v)
#endif

/* --- Register HW_FLEXCAN_IFLAG1, field BUF4I */

#define BP_FLEXCAN_IFLAG1_BUF4I      0
#define BM_FLEXCAN_IFLAG1_BUF4I      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF4I(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IFLAG1_BUF4I)
#else
#define BF_FLEXCAN_IFLAG1_BUF4I(v)   (((v) << 0) & BM_FLEXCAN_IFLAG1_BUF4I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IFLAG1_BUF4I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF4I, v)
#endif

/*
 * HW_FLEXCAN_CTRL2 - Control 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1;
        unsigned RESERVED1 : 2;
        unsigned WRMFRZ : 1;
        unsigned RFEN : 4;
        unsigned TASD : 5;
        unsigned MRP : 1;
        unsigned RRS : 1;
        unsigned RESERVED2 : 16;
        unsigned EACEN : 1;

    } B;
} hw_flexcan_ctrl2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_CTRL2 register
 */
#define HW_FLEXCAN_CTRL2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_CTRL2(x)           (*(volatile hw_flexcan_ctrl2_t *) HW_FLEXCAN_CTRL2_ADDR(x))
#define HW_FLEXCAN_CTRL2_RD(x)        (HW_FLEXCAN_CTRL2(x).U)
#define HW_FLEXCAN_CTRL2_WR(x, v)     (HW_FLEXCAN_CTRL2(x).U = (v))
#define HW_FLEXCAN_CTRL2_SET(x, v)    (HW_FLEXCAN_CTRL2_WR(x, HW_FLEXCAN_CTRL2_RD(x) |  (v)))
#define HW_FLEXCAN_CTRL2_CLR(x, v)    (HW_FLEXCAN_CTRL2_WR(x, HW_FLEXCAN_CTRL2_RD(x) & ~(v)))
#define HW_FLEXCAN_CTRL2_TOG(x, v)    (HW_FLEXCAN_CTRL2_WR(x, HW_FLEXCAN_CTRL2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_CTRL2 bitfields
 */

/* --- Register HW_FLEXCAN_CTRL2, field WRMFRZ */

#define BP_FLEXCAN_CTRL2_WRMFRZ      28
#define BM_FLEXCAN_CTRL2_WRMFRZ      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_WRMFRZ(v)   ((((reg32_t) v) << 28) & BM_FLEXCAN_CTRL2_WRMFRZ)
#else
#define BF_FLEXCAN_CTRL2_WRMFRZ(v)   (((v) << 28) & BM_FLEXCAN_CTRL2_WRMFRZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL2_WRMFRZ(v)   BF_CS1(FLEXCAN_CTRL2, WRMFRZ, v)
#endif

/* --- Register HW_FLEXCAN_CTRL2, field RFEN */

#define BP_FLEXCAN_CTRL2_RFEN      24
#define BM_FLEXCAN_CTRL2_RFEN      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_RFEN(v)   ((((reg32_t) v) << 24) & BM_FLEXCAN_CTRL2_RFEN)
#else
#define BF_FLEXCAN_CTRL2_RFEN(v)   (((v) << 24) & BM_FLEXCAN_CTRL2_RFEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL2_RFEN(v)   BF_CS1(FLEXCAN_CTRL2, RFEN, v)
#endif

/* --- Register HW_FLEXCAN_CTRL2, field TASD */

#define BP_FLEXCAN_CTRL2_TASD      19
#define BM_FLEXCAN_CTRL2_TASD      0x00f80000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_TASD(v)   ((((reg32_t) v) << 19) & BM_FLEXCAN_CTRL2_TASD)
#else
#define BF_FLEXCAN_CTRL2_TASD(v)   (((v) << 19) & BM_FLEXCAN_CTRL2_TASD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL2_TASD(v)   BF_CS1(FLEXCAN_CTRL2, TASD, v)
#endif

/* --- Register HW_FLEXCAN_CTRL2, field MRP */

#define BP_FLEXCAN_CTRL2_MRP      18
#define BM_FLEXCAN_CTRL2_MRP      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_MRP(v)   ((((reg32_t) v) << 18) & BM_FLEXCAN_CTRL2_MRP)
#else
#define BF_FLEXCAN_CTRL2_MRP(v)   (((v) << 18) & BM_FLEXCAN_CTRL2_MRP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL2_MRP(v)   BF_CS1(FLEXCAN_CTRL2, MRP, v)
#endif

/* --- Register HW_FLEXCAN_CTRL2, field RRS */

#define BP_FLEXCAN_CTRL2_RRS      17
#define BM_FLEXCAN_CTRL2_RRS      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_RRS(v)   ((((reg32_t) v) << 17) & BM_FLEXCAN_CTRL2_RRS)
#else
#define BF_FLEXCAN_CTRL2_RRS(v)   (((v) << 17) & BM_FLEXCAN_CTRL2_RRS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL2_RRS(v)   BF_CS1(FLEXCAN_CTRL2, RRS, v)
#endif

/* --- Register HW_FLEXCAN_CTRL2, field EACEN */

#define BP_FLEXCAN_CTRL2_EACEN      16
#define BM_FLEXCAN_CTRL2_EACEN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_EACEN(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_CTRL2_EACEN)
#else
#define BF_FLEXCAN_CTRL2_EACEN(v)   (((v) << 16) & BM_FLEXCAN_CTRL2_EACEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CTRL2_EACEN(v)   BF_CS1(FLEXCAN_CTRL2, EACEN, v)
#endif

/*
 * HW_FLEXCAN_ESR2 - Error and Status 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 9;
        unsigned LPTM : 7;
        unsigned RESERVED1 : 1;
        unsigned VPS : 1;
        unsigned IMB : 1;
        unsigned RESERVED2 : 13;

    } B;
} hw_flexcan_esr2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_ESR2 register
 */
#define HW_FLEXCAN_ESR2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_ESR2(x)           (*(volatile hw_flexcan_esr2_t *) HW_FLEXCAN_ESR2_ADDR(x))
#define HW_FLEXCAN_ESR2_RD(x)        (HW_FLEXCAN_ESR2(x).U)
#define HW_FLEXCAN_ESR2_WR(x, v)     (HW_FLEXCAN_ESR2(x).U = (v))
#define HW_FLEXCAN_ESR2_SET(x, v)    (HW_FLEXCAN_ESR2_WR(x, HW_FLEXCAN_ESR2_RD(x) |  (v)))
#define HW_FLEXCAN_ESR2_CLR(x, v)    (HW_FLEXCAN_ESR2_WR(x, HW_FLEXCAN_ESR2_RD(x) & ~(v)))
#define HW_FLEXCAN_ESR2_TOG(x, v)    (HW_FLEXCAN_ESR2_WR(x, HW_FLEXCAN_ESR2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_ESR2 bitfields
 */

/* --- Register HW_FLEXCAN_ESR2, field LPTM */

#define BP_FLEXCAN_ESR2_LPTM      16
#define BM_FLEXCAN_ESR2_LPTM      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR2_LPTM(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_ESR2_LPTM)
#else
#define BF_FLEXCAN_ESR2_LPTM(v)   (((v) << 16) & BM_FLEXCAN_ESR2_LPTM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR2_LPTM(v)   BF_CS1(FLEXCAN_ESR2, LPTM, v)
#endif

/* --- Register HW_FLEXCAN_ESR2, field VPS */

#define BP_FLEXCAN_ESR2_VPS      14
#define BM_FLEXCAN_ESR2_VPS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR2_VPS(v)   ((((reg32_t) v) << 14) & BM_FLEXCAN_ESR2_VPS)
#else
#define BF_FLEXCAN_ESR2_VPS(v)   (((v) << 14) & BM_FLEXCAN_ESR2_VPS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR2_VPS(v)   BF_CS1(FLEXCAN_ESR2, VPS, v)
#endif

/* --- Register HW_FLEXCAN_ESR2, field IMB */

#define BP_FLEXCAN_ESR2_IMB      13
#define BM_FLEXCAN_ESR2_IMB      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR2_IMB(v)   ((((reg32_t) v) << 13) & BM_FLEXCAN_ESR2_IMB)
#else
#define BF_FLEXCAN_ESR2_IMB(v)   (((v) << 13) & BM_FLEXCAN_ESR2_IMB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_ESR2_IMB(v)   BF_CS1(FLEXCAN_ESR2, IMB, v)
#endif

/*
 * HW_FLEXCAN_IMEUR - Individual Matching Elements Update
                        Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 22;
        unsigned IMEUACK : 1;
        unsigned IMEUREQ : 1;
        unsigned RESERVED1 : 1;
        unsigned IMEUP : 7;

    } B;
} hw_flexcan_imeur_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IMEUR register
 */
#define HW_FLEXCAN_IMEUR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IMEUR(x)           (*(volatile hw_flexcan_imeur_t *) HW_FLEXCAN_IMEUR_ADDR(x))
#define HW_FLEXCAN_IMEUR_RD(x)        (HW_FLEXCAN_IMEUR(x).U)
#define HW_FLEXCAN_IMEUR_WR(x, v)     (HW_FLEXCAN_IMEUR(x).U = (v))
#define HW_FLEXCAN_IMEUR_SET(x, v)    (HW_FLEXCAN_IMEUR_WR(x, HW_FLEXCAN_IMEUR_RD(x) |  (v)))
#define HW_FLEXCAN_IMEUR_CLR(x, v)    (HW_FLEXCAN_IMEUR_WR(x, HW_FLEXCAN_IMEUR_RD(x) & ~(v)))
#define HW_FLEXCAN_IMEUR_TOG(x, v)    (HW_FLEXCAN_IMEUR_WR(x, HW_FLEXCAN_IMEUR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_IMEUR bitfields
 */

/* --- Register HW_FLEXCAN_IMEUR, field IMEUACK */

#define BP_FLEXCAN_IMEUR_IMEUACK      9
#define BM_FLEXCAN_IMEUR_IMEUACK      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IMEUR_IMEUACK(v)   ((((reg32_t) v) << 9) & BM_FLEXCAN_IMEUR_IMEUACK)
#else
#define BF_FLEXCAN_IMEUR_IMEUACK(v)   (((v) << 9) & BM_FLEXCAN_IMEUR_IMEUACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IMEUR_IMEUACK(v)   BF_CS1(FLEXCAN_IMEUR, IMEUACK, v)
#endif

/* --- Register HW_FLEXCAN_IMEUR, field IMEUREQ */

#define BP_FLEXCAN_IMEUR_IMEUREQ      8
#define BM_FLEXCAN_IMEUR_IMEUREQ      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IMEUR_IMEUREQ(v)   ((((reg32_t) v) << 8) & BM_FLEXCAN_IMEUR_IMEUREQ)
#else
#define BF_FLEXCAN_IMEUR_IMEUREQ(v)   (((v) << 8) & BM_FLEXCAN_IMEUR_IMEUREQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IMEUR_IMEUREQ(v)   BF_CS1(FLEXCAN_IMEUR, IMEUREQ, v)
#endif

/* --- Register HW_FLEXCAN_IMEUR, field IMEUP */

#define BP_FLEXCAN_IMEUR_IMEUP      0
#define BM_FLEXCAN_IMEUR_IMEUP      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IMEUR_IMEUP(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IMEUR_IMEUP)
#else
#define BF_FLEXCAN_IMEUR_IMEUP(v)   (((v) << 0) & BM_FLEXCAN_IMEUR_IMEUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_IMEUR_IMEUP(v)   BF_CS1(FLEXCAN_IMEUR, IMEUP, v)
#endif

/*
 * HW_FLEXCAN_LRFR - Lost Rx Frames Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 9;
        unsigned LOSTRLP : 7;
        unsigned LFIFOMTC : 1;
        unsigned RESERVED1 : 6;
        unsigned LOSTRMP : 9;

    } B;
} hw_flexcan_lrfr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_LRFR register
 */
#define HW_FLEXCAN_LRFR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_LRFR(x)           (*(volatile hw_flexcan_lrfr_t *) HW_FLEXCAN_LRFR_ADDR(x))
#define HW_FLEXCAN_LRFR_RD(x)        (HW_FLEXCAN_LRFR(x).U)
#define HW_FLEXCAN_LRFR_WR(x, v)     (HW_FLEXCAN_LRFR(x).U = (v))
#define HW_FLEXCAN_LRFR_SET(x, v)    (HW_FLEXCAN_LRFR_WR(x, HW_FLEXCAN_LRFR_RD(x) |  (v)))
#define HW_FLEXCAN_LRFR_CLR(x, v)    (HW_FLEXCAN_LRFR_WR(x, HW_FLEXCAN_LRFR_RD(x) & ~(v)))
#define HW_FLEXCAN_LRFR_TOG(x, v)    (HW_FLEXCAN_LRFR_WR(x, HW_FLEXCAN_LRFR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_LRFR bitfields
 */

/* --- Register HW_FLEXCAN_LRFR, field LOSTRLP */

#define BP_FLEXCAN_LRFR_LOSTRLP      16
#define BM_FLEXCAN_LRFR_LOSTRLP      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_LRFR_LOSTRLP(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_LRFR_LOSTRLP)
#else
#define BF_FLEXCAN_LRFR_LOSTRLP(v)   (((v) << 16) & BM_FLEXCAN_LRFR_LOSTRLP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_LRFR_LOSTRLP(v)   BF_CS1(FLEXCAN_LRFR, LOSTRLP, v)
#endif

/* --- Register HW_FLEXCAN_LRFR, field LFIFOMTC */

#define BP_FLEXCAN_LRFR_LFIFOMTC      15
#define BM_FLEXCAN_LRFR_LFIFOMTC      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_LRFR_LFIFOMTC(v)   ((((reg32_t) v) << 15) & BM_FLEXCAN_LRFR_LFIFOMTC)
#else
#define BF_FLEXCAN_LRFR_LFIFOMTC(v)   (((v) << 15) & BM_FLEXCAN_LRFR_LFIFOMTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_LRFR_LFIFOMTC(v)   BF_CS1(FLEXCAN_LRFR, LFIFOMTC, v)
#endif

/* --- Register HW_FLEXCAN_LRFR, field LOSTRMP */

#define BP_FLEXCAN_LRFR_LOSTRMP      0
#define BM_FLEXCAN_LRFR_LOSTRMP      0x000001ff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_LRFR_LOSTRMP(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_LRFR_LOSTRMP)
#else
#define BF_FLEXCAN_LRFR_LOSTRMP(v)   (((v) << 0) & BM_FLEXCAN_LRFR_LOSTRMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_LRFR_LOSTRMP(v)   BF_CS1(FLEXCAN_LRFR, LOSTRMP, v)
#endif

/*
 * HW_FLEXCAN_CRCR - CRC Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7;
        unsigned FCRC : 1;
        unsigned RESERVED1 : 1;
        unsigned RESERVED2 : 9;
        unsigned MBCRC : 7;
        unsigned RESERVED3 : 1;
        unsigned TXCRC : 15;

    } B;
} hw_flexcan_crcr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_CRCR register
 */
#define HW_FLEXCAN_CRCR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_CRCR(x)           (*(volatile hw_flexcan_crcr_t *) HW_FLEXCAN_CRCR_ADDR(x))
#define HW_FLEXCAN_CRCR_RD(x)        (HW_FLEXCAN_CRCR(x).U)
#define HW_FLEXCAN_CRCR_WR(x, v)     (HW_FLEXCAN_CRCR(x).U = (v))
#define HW_FLEXCAN_CRCR_SET(x, v)    (HW_FLEXCAN_CRCR_WR(x, HW_FLEXCAN_CRCR_RD(x) |  (v)))
#define HW_FLEXCAN_CRCR_CLR(x, v)    (HW_FLEXCAN_CRCR_WR(x, HW_FLEXCAN_CRCR_RD(x) & ~(v)))
#define HW_FLEXCAN_CRCR_TOG(x, v)    (HW_FLEXCAN_CRCR_WR(x, HW_FLEXCAN_CRCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_CRCR bitfields
 */

/* --- Register HW_FLEXCAN_CRCR, field FCRC */

#define BP_FLEXCAN_CRCR_FCRC      24
#define BM_FLEXCAN_CRCR_FCRC      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CRCR_FCRC(v)   ((((reg32_t) v) << 24) & BM_FLEXCAN_CRCR_FCRC)
#else
#define BF_FLEXCAN_CRCR_FCRC(v)   (((v) << 24) & BM_FLEXCAN_CRCR_FCRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CRCR_FCRC(v)   BF_CS1(FLEXCAN_CRCR, FCRC, v)
#endif

/* --- Register HW_FLEXCAN_CRCR, field MBCRC */

#define BP_FLEXCAN_CRCR_MBCRC      16
#define BM_FLEXCAN_CRCR_MBCRC      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CRCR_MBCRC(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_CRCR_MBCRC)
#else
#define BF_FLEXCAN_CRCR_MBCRC(v)   (((v) << 16) & BM_FLEXCAN_CRCR_MBCRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CRCR_MBCRC(v)   BF_CS1(FLEXCAN_CRCR, MBCRC, v)
#endif

/* --- Register HW_FLEXCAN_CRCR, field TXCRC */

#define BP_FLEXCAN_CRCR_TXCRC      0
#define BM_FLEXCAN_CRCR_TXCRC      0x00007fff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CRCR_TXCRC(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_CRCR_TXCRC)
#else
#define BF_FLEXCAN_CRCR_TXCRC(v)   (((v) << 0) & BM_FLEXCAN_CRCR_TXCRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_CRCR_TXCRC(v)   BF_CS1(FLEXCAN_CRCR, TXCRC, v)
#endif

/*
 * HW_FLEXCAN_RXFGMASK - Rx FIFO Global Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FGM31 : 32;

    } B;
} hw_flexcan_rxfgmask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXFGMASK register
 */
#define HW_FLEXCAN_RXFGMASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXFGMASK(x)           (*(volatile hw_flexcan_rxfgmask_t *) HW_FLEXCAN_RXFGMASK_ADDR(x))
#define HW_FLEXCAN_RXFGMASK_RD(x)        (HW_FLEXCAN_RXFGMASK(x).U)
#define HW_FLEXCAN_RXFGMASK_WR(x, v)     (HW_FLEXCAN_RXFGMASK(x).U = (v))
#define HW_FLEXCAN_RXFGMASK_SET(x, v)    (HW_FLEXCAN_RXFGMASK_WR(x, HW_FLEXCAN_RXFGMASK_RD(x) |  (v)))
#define HW_FLEXCAN_RXFGMASK_CLR(x, v)    (HW_FLEXCAN_RXFGMASK_WR(x, HW_FLEXCAN_RXFGMASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RXFGMASK_TOG(x, v)    (HW_FLEXCAN_RXFGMASK_WR(x, HW_FLEXCAN_RXFGMASK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_RXFGMASK bitfields
 */

/* --- Register HW_FLEXCAN_RXFGMASK, field FGM31 */

#define BP_FLEXCAN_RXFGMASK_FGM31      0
#define BM_FLEXCAN_RXFGMASK_FGM31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RXFGMASK_FGM31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RXFGMASK_FGM31)
#else
#define BF_FLEXCAN_RXFGMASK_FGM31(v)   (((v) << 0) & BM_FLEXCAN_RXFGMASK_FGM31)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_RXFGMASK_FGM31(v)   BF_CS1(FLEXCAN_RXFGMASK, FGM31, v)
#endif

/*
 * HW_FLEXCAN_RXFIR - Rx FIFO Information Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 23;
        unsigned IDHIT : 9;

    } B;
} hw_flexcan_rxfir_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXFIR register
 */
#define HW_FLEXCAN_RXFIR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXFIR(x)           (*(volatile hw_flexcan_rxfir_t *) HW_FLEXCAN_RXFIR_ADDR(x))
#define HW_FLEXCAN_RXFIR_RD(x)        (HW_FLEXCAN_RXFIR(x).U)
#define HW_FLEXCAN_RXFIR_WR(x, v)     (HW_FLEXCAN_RXFIR(x).U = (v))
#define HW_FLEXCAN_RXFIR_SET(x, v)    (HW_FLEXCAN_RXFIR_WR(x, HW_FLEXCAN_RXFIR_RD(x) |  (v)))
#define HW_FLEXCAN_RXFIR_CLR(x, v)    (HW_FLEXCAN_RXFIR_WR(x, HW_FLEXCAN_RXFIR_RD(x) & ~(v)))
#define HW_FLEXCAN_RXFIR_TOG(x, v)    (HW_FLEXCAN_RXFIR_WR(x, HW_FLEXCAN_RXFIR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_RXFIR bitfields
 */

/* --- Register HW_FLEXCAN_RXFIR, field IDHIT */

#define BP_FLEXCAN_RXFIR_IDHIT      0
#define BM_FLEXCAN_RXFIR_IDHIT      0x000001ff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RXFIR_IDHIT(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RXFIR_IDHIT)
#else
#define BF_FLEXCAN_RXFIR_IDHIT(v)   (((v) << 0) & BM_FLEXCAN_RXFIR_IDHIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_RXFIR_IDHIT(v)   BF_CS1(FLEXCAN_RXFIR, IDHIT, v)
#endif

/*
 * HW_FLEXCAN_RXIMR0-RXIMR63 - Rx Individual Mask Registers
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MI31 : 32;

    } B;
} hw_flexcan_rximr0-rximr63_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXIMR0-RXIMR63 register
 */
#define HW_FLEXCAN_RXIMR0-RXIMR63_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x880)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXIMR0-RXIMR63(x)           (*(volatile hw_flexcan_rximr0-rximr63_t *) HW_FLEXCAN_RXIMR0-RXIMR63_ADDR(x))
#define HW_FLEXCAN_RXIMR0-RXIMR63_RD(x)        (HW_FLEXCAN_RXIMR0-RXIMR63(x).U)
#define HW_FLEXCAN_RXIMR0-RXIMR63_WR(x, v)     (HW_FLEXCAN_RXIMR0-RXIMR63(x).U = (v))
#define HW_FLEXCAN_RXIMR0-RXIMR63_SET(x, v)    (HW_FLEXCAN_RXIMR0-RXIMR63_WR(x, HW_FLEXCAN_RXIMR0-RXIMR63_RD(x) |  (v)))
#define HW_FLEXCAN_RXIMR0-RXIMR63_CLR(x, v)    (HW_FLEXCAN_RXIMR0-RXIMR63_WR(x, HW_FLEXCAN_RXIMR0-RXIMR63_RD(x) & ~(v)))
#define HW_FLEXCAN_RXIMR0-RXIMR63_TOG(x, v)    (HW_FLEXCAN_RXIMR0-RXIMR63_WR(x, HW_FLEXCAN_RXIMR0-RXIMR63_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_RXIMR0-RXIMR63 bitfields
 */

/* --- Register HW_FLEXCAN_RXIMR0-RXIMR63, field MI31 */

#define BP_FLEXCAN_RXIMR0-RXIMR63_MI31      0
#define BM_FLEXCAN_RXIMR0-RXIMR63_MI31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RXIMR0-RXIMR63_MI31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RXIMR0-RXIMR63_MI31)
#else
#define BF_FLEXCAN_RXIMR0-RXIMR63_MI31(v)   (((v) << 0) & BM_FLEXCAN_RXIMR0-RXIMR63_MI31)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_RXIMR0-RXIMR63_MI31(v)   BF_CS1(FLEXCAN_RXIMR0-RXIMR63, MI31, v)
#endif

/*
 * HW_FLEXCAN_GFWR - Glitch Filter Width Registers
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 24;
        unsigned GFWR : 8;

    } B;
} hw_flexcan_gfwr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_GFWR register
 */
#define HW_FLEXCAN_GFWR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x9e0)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_GFWR(x)           (*(volatile hw_flexcan_gfwr_t *) HW_FLEXCAN_GFWR_ADDR(x))
#define HW_FLEXCAN_GFWR_RD(x)        (HW_FLEXCAN_GFWR(x).U)
#define HW_FLEXCAN_GFWR_WR(x, v)     (HW_FLEXCAN_GFWR(x).U = (v))
#define HW_FLEXCAN_GFWR_SET(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) |  (v)))
#define HW_FLEXCAN_GFWR_CLR(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) & ~(v)))
#define HW_FLEXCAN_GFWR_TOG(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual FLEXCAN_GFWR bitfields
 */

/* --- Register HW_FLEXCAN_GFWR, field GFWR */

#define BP_FLEXCAN_GFWR_GFWR      0
#define BM_FLEXCAN_GFWR_GFWR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_GFWR_GFWR(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_GFWR_GFWR)
#else
#define BF_FLEXCAN_GFWR_GFWR(v)   (((v) << 0) & BM_FLEXCAN_GFWR_GFWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_FLEXCAN_GFWR_GFWR(v)   BF_CS1(FLEXCAN_GFWR, GFWR, v)
#endif


#endif // _FLEXCAN_H

