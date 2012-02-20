/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SSI_H
#define _SSI_H

#include "regs.h"

#ifndef REGS_SSI_BASE
#define REGS_SSI0_BASE (REGS_BASE + 0x02028000)
#define REGS_SSI1_BASE (REGS_BASE + 0x0202c000)
#define REGS_SSI2_BASE (REGS_BASE + 0x02030000)
#define REGS_SSI_BASE(x) ( x == 0 ? REGS_SSI0_BASE : x == 1 ? REGS_SSI1_BASE : x == 2 ? REGS_SSI2_BASE : 0xffff0000)

#endif


/*
 * HW_SSI_SSI_STX - SSI Transmit Data Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned STXN : 32;

    } B;
} hw_ssi_ssi_stx_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STX register
 */
#define HW_SSI_SSI_STX_ADDR(x)      (REGS_SSI_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STX(x)           (*(volatile hw_ssi_ssi_stx_t *) HW_SSI_SSI_STX_ADDR(x))
#define HW_SSI_SSI_STX_RD(x)        (HW_SSI_SSI_STX(x).U)
#define HW_SSI_SSI_STX_WR(x, v)     (HW_SSI_SSI_STX(x).U = (v))
#define HW_SSI_SSI_STX_SET(x, v)    (HW_SSI_SSI_STX_WR(x, HW_SSI_SSI_STX_RD(x) |  (v)))
#define HW_SSI_SSI_STX_CLR(x, v)    (HW_SSI_SSI_STX_WR(x, HW_SSI_SSI_STX_RD(x) & ~(v)))
#define HW_SSI_SSI_STX_TOG(x, v)    (HW_SSI_SSI_STX_WR(x, HW_SSI_SSI_STX_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STX bitfields
 */

/* --- Register HW_SSI_SSI_STX, field STXN */

#define BP_SSI_SSI_STX_STXN      0
#define BM_SSI_SSI_STX_STXN      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STX_STXN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STX_STXN)
#else
#define BF_SSI_SSI_STX_STXN(v)   (((v) << 0) & BM_SSI_SSI_STX_STXN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STX_STXN(v)   BF_CS1(SSI_SSI_STX, STXN, v)
#endif

/*
 * HW_SSI_SSI_SRX - SSI Receive Data Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SRXN : 32;

    } B;
} hw_ssi_ssi_srx_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SRX register
 */
#define HW_SSI_SSI_SRX_ADDR(x)      (REGS_SSI_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SRX(x)           (*(volatile hw_ssi_ssi_srx_t *) HW_SSI_SSI_SRX_ADDR(x))
#define HW_SSI_SSI_SRX_RD(x)        (HW_SSI_SSI_SRX(x).U)
#define HW_SSI_SSI_SRX_WR(x, v)     (HW_SSI_SSI_SRX(x).U = (v))
#define HW_SSI_SSI_SRX_SET(x, v)    (HW_SSI_SSI_SRX_WR(x, HW_SSI_SSI_SRX_RD(x) |  (v)))
#define HW_SSI_SSI_SRX_CLR(x, v)    (HW_SSI_SSI_SRX_WR(x, HW_SSI_SSI_SRX_RD(x) & ~(v)))
#define HW_SSI_SSI_SRX_TOG(x, v)    (HW_SSI_SSI_SRX_WR(x, HW_SSI_SSI_SRX_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SRX bitfields
 */

/* --- Register HW_SSI_SSI_SRX, field SRXN */

#define BP_SSI_SSI_SRX_SRXN      0
#define BM_SSI_SSI_SRX_SRXN      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRX_SRXN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SRX_SRXN)
#else
#define BF_SSI_SSI_SRX_SRXN(v)   (((v) << 0) & BM_SSI_SSI_SRX_SRXN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRX_SRXN(v)   BF_CS1(SSI_SSI_SRX, SRXN, v)
#endif

/*
 * HW_SSI_SSI_SCR - SSI Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 19;
        unsigned SYNC_TX_FS : 1;
        unsigned RESERVED1 : 20;
        unsigned RFR_CLK_DIS : 1;
        unsigned TFR_CLK_DIS : 1;
        unsigned CLK_IST : 1;
        unsigned TCH_EN : 1;
        unsigned SYS_CLK_EN : 1;
        unsigned I2S : 2;
        unsigned SYN : 1;
        unsigned NET : 1;
        unsigned RE : 1;
        unsigned TE : 1;
        unsigned SSIEN : 1;

    } B;
} hw_ssi_ssi_scr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SCR register
 */
#define HW_SSI_SSI_SCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SCR(x)           (*(volatile hw_ssi_ssi_scr_t *) HW_SSI_SSI_SCR_ADDR(x))
#define HW_SSI_SSI_SCR_RD(x)        (HW_SSI_SSI_SCR(x).U)
#define HW_SSI_SSI_SCR_WR(x, v)     (HW_SSI_SSI_SCR(x).U = (v))
#define HW_SSI_SSI_SCR_SET(x, v)    (HW_SSI_SSI_SCR_WR(x, HW_SSI_SSI_SCR_RD(x) |  (v)))
#define HW_SSI_SSI_SCR_CLR(x, v)    (HW_SSI_SSI_SCR_WR(x, HW_SSI_SSI_SCR_RD(x) & ~(v)))
#define HW_SSI_SSI_SCR_TOG(x, v)    (HW_SSI_SSI_SCR_WR(x, HW_SSI_SSI_SCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SCR bitfields
 */

/* --- Register HW_SSI_SSI_SCR, field SYNC_TX_FS */

#define BP_SSI_SSI_SCR_SYNC_TX_FS      12
#define BM_SSI_SSI_SCR_SYNC_TX_FS      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_SYNC_TX_FS(v)   ((((reg32_t) v) << 12) & BM_SSI_SSI_SCR_SYNC_TX_FS)
#else
#define BF_SSI_SSI_SCR_SYNC_TX_FS(v)   (((v) << 12) & BM_SSI_SSI_SCR_SYNC_TX_FS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_SYNC_TX_FS(v)   BF_CS1(SSI_SSI_SCR, SYNC_TX_FS, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field RFR_CLK_DIS */

#define BP_SSI_SSI_SCR_RFR_CLK_DIS      11
#define BM_SSI_SSI_SCR_RFR_CLK_DIS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_RFR_CLK_DIS(v)   ((((reg32_t) v) << 11) & BM_SSI_SSI_SCR_RFR_CLK_DIS)
#else
#define BF_SSI_SSI_SCR_RFR_CLK_DIS(v)   (((v) << 11) & BM_SSI_SSI_SCR_RFR_CLK_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_RFR_CLK_DIS(v)   BF_CS1(SSI_SSI_SCR, RFR_CLK_DIS, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field TFR_CLK_DIS */

#define BP_SSI_SSI_SCR_TFR_CLK_DIS      10
#define BM_SSI_SSI_SCR_TFR_CLK_DIS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_TFR_CLK_DIS(v)   ((((reg32_t) v) << 10) & BM_SSI_SSI_SCR_TFR_CLK_DIS)
#else
#define BF_SSI_SSI_SCR_TFR_CLK_DIS(v)   (((v) << 10) & BM_SSI_SSI_SCR_TFR_CLK_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_TFR_CLK_DIS(v)   BF_CS1(SSI_SSI_SCR, TFR_CLK_DIS, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field CLK_IST */

#define BP_SSI_SSI_SCR_CLK_IST      9
#define BM_SSI_SSI_SCR_CLK_IST      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_CLK_IST(v)   ((((reg32_t) v) << 9) & BM_SSI_SSI_SCR_CLK_IST)
#else
#define BF_SSI_SSI_SCR_CLK_IST(v)   (((v) << 9) & BM_SSI_SSI_SCR_CLK_IST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_CLK_IST(v)   BF_CS1(SSI_SSI_SCR, CLK_IST, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field TCH_EN */

#define BP_SSI_SSI_SCR_TCH_EN      8
#define BM_SSI_SSI_SCR_TCH_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_TCH_EN(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_SCR_TCH_EN)
#else
#define BF_SSI_SSI_SCR_TCH_EN(v)   (((v) << 8) & BM_SSI_SSI_SCR_TCH_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_TCH_EN(v)   BF_CS1(SSI_SSI_SCR, TCH_EN, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field SYS_CLK_EN */

#define BP_SSI_SSI_SCR_SYS_CLK_EN      7
#define BM_SSI_SSI_SCR_SYS_CLK_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_SYS_CLK_EN(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_SCR_SYS_CLK_EN)
#else
#define BF_SSI_SSI_SCR_SYS_CLK_EN(v)   (((v) << 7) & BM_SSI_SSI_SCR_SYS_CLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_SYS_CLK_EN(v)   BF_CS1(SSI_SSI_SCR, SYS_CLK_EN, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field I2S */

#define BP_SSI_SSI_SCR_I2S      5
#define BM_SSI_SSI_SCR_I2S      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_I2S(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SCR_I2S)
#else
#define BF_SSI_SSI_SCR_I2S(v)   (((v) << 5) & BM_SSI_SSI_SCR_I2S)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_I2S(v)   BF_CS1(SSI_SSI_SCR, I2S, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field SYN */

#define BP_SSI_SSI_SCR_SYN      4
#define BM_SSI_SSI_SCR_SYN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_SYN(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SCR_SYN)
#else
#define BF_SSI_SSI_SCR_SYN(v)   (((v) << 4) & BM_SSI_SSI_SCR_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_SYN(v)   BF_CS1(SSI_SSI_SCR, SYN, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field NET */

#define BP_SSI_SSI_SCR_NET      3
#define BM_SSI_SSI_SCR_NET      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_NET(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SCR_NET)
#else
#define BF_SSI_SSI_SCR_NET(v)   (((v) << 3) & BM_SSI_SSI_SCR_NET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_NET(v)   BF_CS1(SSI_SSI_SCR, NET, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field RE */

#define BP_SSI_SSI_SCR_RE      2
#define BM_SSI_SSI_SCR_RE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_RE(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_SCR_RE)
#else
#define BF_SSI_SSI_SCR_RE(v)   (((v) << 2) & BM_SSI_SSI_SCR_RE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_RE(v)   BF_CS1(SSI_SSI_SCR, RE, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field TE */

#define BP_SSI_SSI_SCR_TE      1
#define BM_SSI_SSI_SCR_TE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_TE(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SCR_TE)
#else
#define BF_SSI_SSI_SCR_TE(v)   (((v) << 1) & BM_SSI_SSI_SCR_TE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_TE(v)   BF_CS1(SSI_SSI_SCR, TE, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field SSIEN */

#define BP_SSI_SSI_SCR_SSIEN      0
#define BM_SSI_SSI_SCR_SSIEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_SSIEN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SCR_SSIEN)
#else
#define BF_SSI_SSI_SCR_SSIEN(v)   (((v) << 0) & BM_SSI_SSI_SCR_SSIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_SSIEN(v)   BF_CS1(SSI_SSI_SCR, SSIEN, v)
#endif

/*
 * HW_SSI_SSI_SISR - SSI Interrupt Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7;
        unsigned RFRC : 1;
        unsigned TFRC : 1;
        unsigned RESERVED1 : 4;
        unsigned CMDAU : 1;
        unsigned CMDDU : 1;
        unsigned RXT : 1;
        unsigned RDR1 : 1;
        unsigned RDR0 : 1;
        unsigned TDE1 : 1;
        unsigned TDE0 : 1;
        unsigned ROE1 : 1;
        unsigned ROE0 : 1;
        unsigned TUE1 : 1;
        unsigned TUE0 : 1;
        unsigned TFS : 1;
        unsigned RFS : 1;
        unsigned TLS : 1;
        unsigned RLS : 1;
        unsigned RFF1 : 1;
        unsigned RFF0 : 1;
        unsigned TFE1 : 1;
        unsigned TFE0 : 1;

    } B;
} hw_ssi_ssi_sisr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SISR register
 */
#define HW_SSI_SSI_SISR_ADDR(x)      (REGS_SSI_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SISR(x)           (*(volatile hw_ssi_ssi_sisr_t *) HW_SSI_SSI_SISR_ADDR(x))
#define HW_SSI_SSI_SISR_RD(x)        (HW_SSI_SSI_SISR(x).U)
#define HW_SSI_SSI_SISR_WR(x, v)     (HW_SSI_SSI_SISR(x).U = (v))
#define HW_SSI_SSI_SISR_SET(x, v)    (HW_SSI_SSI_SISR_WR(x, HW_SSI_SSI_SISR_RD(x) |  (v)))
#define HW_SSI_SSI_SISR_CLR(x, v)    (HW_SSI_SSI_SISR_WR(x, HW_SSI_SSI_SISR_RD(x) & ~(v)))
#define HW_SSI_SSI_SISR_TOG(x, v)    (HW_SSI_SSI_SISR_WR(x, HW_SSI_SSI_SISR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SISR bitfields
 */

/* --- Register HW_SSI_SSI_SISR, field RFRC */

#define BP_SSI_SSI_SISR_RFRC      24
#define BM_SSI_SSI_SISR_RFRC      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RFRC(v)   ((((reg32_t) v) << 24) & BM_SSI_SSI_SISR_RFRC)
#else
#define BF_SSI_SSI_SISR_RFRC(v)   (((v) << 24) & BM_SSI_SSI_SISR_RFRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RFRC(v)   BF_CS1(SSI_SSI_SISR, RFRC, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TFRC */

#define BP_SSI_SSI_SISR_TFRC      23
#define BM_SSI_SSI_SISR_TFRC      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TFRC(v)   ((((reg32_t) v) << 23) & BM_SSI_SSI_SISR_TFRC)
#else
#define BF_SSI_SSI_SISR_TFRC(v)   (((v) << 23) & BM_SSI_SSI_SISR_TFRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TFRC(v)   BF_CS1(SSI_SSI_SISR, TFRC, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field CMDAU */

#define BP_SSI_SSI_SISR_CMDAU      18
#define BM_SSI_SSI_SISR_CMDAU      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_CMDAU(v)   ((((reg32_t) v) << 18) & BM_SSI_SSI_SISR_CMDAU)
#else
#define BF_SSI_SSI_SISR_CMDAU(v)   (((v) << 18) & BM_SSI_SSI_SISR_CMDAU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_CMDAU(v)   BF_CS1(SSI_SSI_SISR, CMDAU, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field CMDDU */

#define BP_SSI_SSI_SISR_CMDDU      17
#define BM_SSI_SSI_SISR_CMDDU      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_CMDDU(v)   ((((reg32_t) v) << 17) & BM_SSI_SSI_SISR_CMDDU)
#else
#define BF_SSI_SSI_SISR_CMDDU(v)   (((v) << 17) & BM_SSI_SSI_SISR_CMDDU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_CMDDU(v)   BF_CS1(SSI_SSI_SISR, CMDDU, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RXT */

#define BP_SSI_SSI_SISR_RXT      16
#define BM_SSI_SSI_SISR_RXT      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RXT(v)   ((((reg32_t) v) << 16) & BM_SSI_SSI_SISR_RXT)
#else
#define BF_SSI_SSI_SISR_RXT(v)   (((v) << 16) & BM_SSI_SSI_SISR_RXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RXT(v)   BF_CS1(SSI_SSI_SISR, RXT, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RDR1 */

#define BP_SSI_SSI_SISR_RDR1      15
#define BM_SSI_SSI_SISR_RDR1      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RDR1(v)   ((((reg32_t) v) << 15) & BM_SSI_SSI_SISR_RDR1)
#else
#define BF_SSI_SSI_SISR_RDR1(v)   (((v) << 15) & BM_SSI_SSI_SISR_RDR1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RDR1(v)   BF_CS1(SSI_SSI_SISR, RDR1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RDR0 */

#define BP_SSI_SSI_SISR_RDR0      14
#define BM_SSI_SSI_SISR_RDR0      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RDR0(v)   ((((reg32_t) v) << 14) & BM_SSI_SSI_SISR_RDR0)
#else
#define BF_SSI_SSI_SISR_RDR0(v)   (((v) << 14) & BM_SSI_SSI_SISR_RDR0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RDR0(v)   BF_CS1(SSI_SSI_SISR, RDR0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TDE1 */

#define BP_SSI_SSI_SISR_TDE1      13
#define BM_SSI_SSI_SISR_TDE1      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TDE1(v)   ((((reg32_t) v) << 13) & BM_SSI_SSI_SISR_TDE1)
#else
#define BF_SSI_SSI_SISR_TDE1(v)   (((v) << 13) & BM_SSI_SSI_SISR_TDE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TDE1(v)   BF_CS1(SSI_SSI_SISR, TDE1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TDE0 */

#define BP_SSI_SSI_SISR_TDE0      12
#define BM_SSI_SSI_SISR_TDE0      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TDE0(v)   ((((reg32_t) v) << 12) & BM_SSI_SSI_SISR_TDE0)
#else
#define BF_SSI_SSI_SISR_TDE0(v)   (((v) << 12) & BM_SSI_SSI_SISR_TDE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TDE0(v)   BF_CS1(SSI_SSI_SISR, TDE0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field ROE1 */

#define BP_SSI_SSI_SISR_ROE1      11
#define BM_SSI_SSI_SISR_ROE1      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_ROE1(v)   ((((reg32_t) v) << 11) & BM_SSI_SSI_SISR_ROE1)
#else
#define BF_SSI_SSI_SISR_ROE1(v)   (((v) << 11) & BM_SSI_SSI_SISR_ROE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_ROE1(v)   BF_CS1(SSI_SSI_SISR, ROE1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field ROE0 */

#define BP_SSI_SSI_SISR_ROE0      10
#define BM_SSI_SSI_SISR_ROE0      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_ROE0(v)   ((((reg32_t) v) << 10) & BM_SSI_SSI_SISR_ROE0)
#else
#define BF_SSI_SSI_SISR_ROE0(v)   (((v) << 10) & BM_SSI_SSI_SISR_ROE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_ROE0(v)   BF_CS1(SSI_SSI_SISR, ROE0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TUE1 */

#define BP_SSI_SSI_SISR_TUE1      9
#define BM_SSI_SSI_SISR_TUE1      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TUE1(v)   ((((reg32_t) v) << 9) & BM_SSI_SSI_SISR_TUE1)
#else
#define BF_SSI_SSI_SISR_TUE1(v)   (((v) << 9) & BM_SSI_SSI_SISR_TUE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TUE1(v)   BF_CS1(SSI_SSI_SISR, TUE1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TUE0 */

#define BP_SSI_SSI_SISR_TUE0      8
#define BM_SSI_SSI_SISR_TUE0      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TUE0(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_SISR_TUE0)
#else
#define BF_SSI_SSI_SISR_TUE0(v)   (((v) << 8) & BM_SSI_SSI_SISR_TUE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TUE0(v)   BF_CS1(SSI_SSI_SISR, TUE0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TFS */

#define BP_SSI_SSI_SISR_TFS      7
#define BM_SSI_SSI_SISR_TFS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TFS(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_SISR_TFS)
#else
#define BF_SSI_SSI_SISR_TFS(v)   (((v) << 7) & BM_SSI_SSI_SISR_TFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TFS(v)   BF_CS1(SSI_SSI_SISR, TFS, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RFS */

#define BP_SSI_SSI_SISR_RFS      6
#define BM_SSI_SSI_SISR_RFS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RFS(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_SISR_RFS)
#else
#define BF_SSI_SSI_SISR_RFS(v)   (((v) << 6) & BM_SSI_SSI_SISR_RFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RFS(v)   BF_CS1(SSI_SSI_SISR, RFS, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TLS */

#define BP_SSI_SSI_SISR_TLS      5
#define BM_SSI_SSI_SISR_TLS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TLS(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SISR_TLS)
#else
#define BF_SSI_SSI_SISR_TLS(v)   (((v) << 5) & BM_SSI_SSI_SISR_TLS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TLS(v)   BF_CS1(SSI_SSI_SISR, TLS, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RLS */

#define BP_SSI_SSI_SISR_RLS      4
#define BM_SSI_SSI_SISR_RLS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RLS(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SISR_RLS)
#else
#define BF_SSI_SSI_SISR_RLS(v)   (((v) << 4) & BM_SSI_SSI_SISR_RLS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RLS(v)   BF_CS1(SSI_SSI_SISR, RLS, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RFF1 */

#define BP_SSI_SSI_SISR_RFF1      3
#define BM_SSI_SSI_SISR_RFF1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RFF1(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SISR_RFF1)
#else
#define BF_SSI_SSI_SISR_RFF1(v)   (((v) << 3) & BM_SSI_SSI_SISR_RFF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RFF1(v)   BF_CS1(SSI_SSI_SISR, RFF1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RFF0 */

#define BP_SSI_SSI_SISR_RFF0      2
#define BM_SSI_SSI_SISR_RFF0      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RFF0(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_SISR_RFF0)
#else
#define BF_SSI_SSI_SISR_RFF0(v)   (((v) << 2) & BM_SSI_SSI_SISR_RFF0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RFF0(v)   BF_CS1(SSI_SSI_SISR, RFF0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TFE1 */

#define BP_SSI_SSI_SISR_TFE1      1
#define BM_SSI_SSI_SISR_TFE1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TFE1(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SISR_TFE1)
#else
#define BF_SSI_SSI_SISR_TFE1(v)   (((v) << 1) & BM_SSI_SSI_SISR_TFE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TFE1(v)   BF_CS1(SSI_SSI_SISR, TFE1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TFE0 */

#define BP_SSI_SSI_SISR_TFE0      0
#define BM_SSI_SSI_SISR_TFE0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TFE0(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SISR_TFE0)
#else
#define BF_SSI_SSI_SISR_TFE0(v)   (((v) << 0) & BM_SSI_SSI_SISR_TFE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TFE0(v)   BF_CS1(SSI_SSI_SISR, TFE0, v)
#endif

/*
 * HW_SSI_SIER - SSI Interrupt Enable Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7;
        unsigned ENABLE : 2;
        unsigned RDMAE : 1;
        unsigned RIE : 1;
        unsigned TDMAE : 1;
        unsigned TIE : 1;
        unsigned ENABLE : 19;

    } B;
} hw_ssi_sier_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SIER register
 */
#define HW_SSI_SIER_ADDR(x)      (REGS_SSI_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SIER(x)           (*(volatile hw_ssi_sier_t *) HW_SSI_SIER_ADDR(x))
#define HW_SSI_SIER_RD(x)        (HW_SSI_SIER(x).U)
#define HW_SSI_SIER_WR(x, v)     (HW_SSI_SIER(x).U = (v))
#define HW_SSI_SIER_SET(x, v)    (HW_SSI_SIER_WR(x, HW_SSI_SIER_RD(x) |  (v)))
#define HW_SSI_SIER_CLR(x, v)    (HW_SSI_SIER_WR(x, HW_SSI_SIER_RD(x) & ~(v)))
#define HW_SSI_SIER_TOG(x, v)    (HW_SSI_SIER_WR(x, HW_SSI_SIER_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SIER bitfields
 */

/* --- Register HW_SSI_SIER, field ENABLE */

#define BP_SSI_SIER_ENABLE      23
#define BM_SSI_SIER_ENABLE      0x01800000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_ENABLE(v)   ((((reg32_t) v) << 23) & BM_SSI_SIER_ENABLE)
#else
#define BF_SSI_SIER_ENABLE(v)   (((v) << 23) & BM_SSI_SIER_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_ENABLE(v)   BF_CS1(SSI_SIER, ENABLE, v)
#endif

/* --- Register HW_SSI_SIER, field RDMAE */

#define BP_SSI_SIER_RDMAE      22
#define BM_SSI_SIER_RDMAE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_RDMAE(v)   ((((reg32_t) v) << 22) & BM_SSI_SIER_RDMAE)
#else
#define BF_SSI_SIER_RDMAE(v)   (((v) << 22) & BM_SSI_SIER_RDMAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_RDMAE(v)   BF_CS1(SSI_SIER, RDMAE, v)
#endif

/* --- Register HW_SSI_SIER, field RIE */

#define BP_SSI_SIER_RIE      21
#define BM_SSI_SIER_RIE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_RIE(v)   ((((reg32_t) v) << 21) & BM_SSI_SIER_RIE)
#else
#define BF_SSI_SIER_RIE(v)   (((v) << 21) & BM_SSI_SIER_RIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_RIE(v)   BF_CS1(SSI_SIER, RIE, v)
#endif

/* --- Register HW_SSI_SIER, field TDMAE */

#define BP_SSI_SIER_TDMAE      20
#define BM_SSI_SIER_TDMAE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_TDMAE(v)   ((((reg32_t) v) << 20) & BM_SSI_SIER_TDMAE)
#else
#define BF_SSI_SIER_TDMAE(v)   (((v) << 20) & BM_SSI_SIER_TDMAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_TDMAE(v)   BF_CS1(SSI_SIER, TDMAE, v)
#endif

/* --- Register HW_SSI_SIER, field TIE */

#define BP_SSI_SIER_TIE      19
#define BM_SSI_SIER_TIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_TIE(v)   ((((reg32_t) v) << 19) & BM_SSI_SIER_TIE)
#else
#define BF_SSI_SIER_TIE(v)   (((v) << 19) & BM_SSI_SIER_TIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_TIE(v)   BF_CS1(SSI_SIER, TIE, v)
#endif

/* --- Register HW_SSI_SIER, field ENABLE */

#define BP_SSI_SIER_ENABLE      0
#define BM_SSI_SIER_ENABLE      0x0007ffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_ENABLE(v)   ((((reg32_t) v) << 0) & BM_SSI_SIER_ENABLE)
#else
#define BF_SSI_SIER_ENABLE(v)   (((v) << 0) & BM_SSI_SIER_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_ENABLE(v)   BF_CS1(SSI_SIER, ENABLE, v)
#endif

/*
 * HW_SSI_SSI_STCR - SSI Transmit Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 22;
        unsigned TXBIT0 : 1;
        unsigned TFEN1 : 1;
        unsigned TFEN0 : 1;
        unsigned TFDIR : 1;
        unsigned TXDIR : 1;
        unsigned TSHFD : 1;
        unsigned TSCKP : 1;
        unsigned TFSI : 1;
        unsigned TFSL : 1;
        unsigned TEFS : 1;

    } B;
} hw_ssi_ssi_stcr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STCR register
 */
#define HW_SSI_SSI_STCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STCR(x)           (*(volatile hw_ssi_ssi_stcr_t *) HW_SSI_SSI_STCR_ADDR(x))
#define HW_SSI_SSI_STCR_RD(x)        (HW_SSI_SSI_STCR(x).U)
#define HW_SSI_SSI_STCR_WR(x, v)     (HW_SSI_SSI_STCR(x).U = (v))
#define HW_SSI_SSI_STCR_SET(x, v)    (HW_SSI_SSI_STCR_WR(x, HW_SSI_SSI_STCR_RD(x) |  (v)))
#define HW_SSI_SSI_STCR_CLR(x, v)    (HW_SSI_SSI_STCR_WR(x, HW_SSI_SSI_STCR_RD(x) & ~(v)))
#define HW_SSI_SSI_STCR_TOG(x, v)    (HW_SSI_SSI_STCR_WR(x, HW_SSI_SSI_STCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STCR bitfields
 */

/* --- Register HW_SSI_SSI_STCR, field TXBIT0 */

#define BP_SSI_SSI_STCR_TXBIT0      9
#define BM_SSI_SSI_STCR_TXBIT0      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TXBIT0(v)   ((((reg32_t) v) << 9) & BM_SSI_SSI_STCR_TXBIT0)
#else
#define BF_SSI_SSI_STCR_TXBIT0(v)   (((v) << 9) & BM_SSI_SSI_STCR_TXBIT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TXBIT0(v)   BF_CS1(SSI_SSI_STCR, TXBIT0, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFEN1 */

#define BP_SSI_SSI_STCR_TFEN1      8
#define BM_SSI_SSI_STCR_TFEN1      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFEN1(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_STCR_TFEN1)
#else
#define BF_SSI_SSI_STCR_TFEN1(v)   (((v) << 8) & BM_SSI_SSI_STCR_TFEN1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFEN1(v)   BF_CS1(SSI_SSI_STCR, TFEN1, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFEN0 */

#define BP_SSI_SSI_STCR_TFEN0      7
#define BM_SSI_SSI_STCR_TFEN0      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFEN0(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_STCR_TFEN0)
#else
#define BF_SSI_SSI_STCR_TFEN0(v)   (((v) << 7) & BM_SSI_SSI_STCR_TFEN0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFEN0(v)   BF_CS1(SSI_SSI_STCR, TFEN0, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFDIR */

#define BP_SSI_SSI_STCR_TFDIR      6
#define BM_SSI_SSI_STCR_TFDIR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFDIR(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_STCR_TFDIR)
#else
#define BF_SSI_SSI_STCR_TFDIR(v)   (((v) << 6) & BM_SSI_SSI_STCR_TFDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFDIR(v)   BF_CS1(SSI_SSI_STCR, TFDIR, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TXDIR */

#define BP_SSI_SSI_STCR_TXDIR      5
#define BM_SSI_SSI_STCR_TXDIR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TXDIR(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_STCR_TXDIR)
#else
#define BF_SSI_SSI_STCR_TXDIR(v)   (((v) << 5) & BM_SSI_SSI_STCR_TXDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TXDIR(v)   BF_CS1(SSI_SSI_STCR, TXDIR, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TSHFD */

#define BP_SSI_SSI_STCR_TSHFD      4
#define BM_SSI_SSI_STCR_TSHFD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TSHFD(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_STCR_TSHFD)
#else
#define BF_SSI_SSI_STCR_TSHFD(v)   (((v) << 4) & BM_SSI_SSI_STCR_TSHFD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TSHFD(v)   BF_CS1(SSI_SSI_STCR, TSHFD, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TSCKP */

#define BP_SSI_SSI_STCR_TSCKP      3
#define BM_SSI_SSI_STCR_TSCKP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TSCKP(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_STCR_TSCKP)
#else
#define BF_SSI_SSI_STCR_TSCKP(v)   (((v) << 3) & BM_SSI_SSI_STCR_TSCKP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TSCKP(v)   BF_CS1(SSI_SSI_STCR, TSCKP, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFSI */

#define BP_SSI_SSI_STCR_TFSI      2
#define BM_SSI_SSI_STCR_TFSI      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFSI(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_STCR_TFSI)
#else
#define BF_SSI_SSI_STCR_TFSI(v)   (((v) << 2) & BM_SSI_SSI_STCR_TFSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFSI(v)   BF_CS1(SSI_SSI_STCR, TFSI, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFSL */

#define BP_SSI_SSI_STCR_TFSL      1
#define BM_SSI_SSI_STCR_TFSL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFSL(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_STCR_TFSL)
#else
#define BF_SSI_SSI_STCR_TFSL(v)   (((v) << 1) & BM_SSI_SSI_STCR_TFSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFSL(v)   BF_CS1(SSI_SSI_STCR, TFSL, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TEFS */

#define BP_SSI_SSI_STCR_TEFS      0
#define BM_SSI_SSI_STCR_TEFS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TEFS(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STCR_TEFS)
#else
#define BF_SSI_SSI_STCR_TEFS(v)   (((v) << 0) & BM_SSI_SSI_STCR_TEFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TEFS(v)   BF_CS1(SSI_SSI_STCR, TEFS, v)
#endif

/*
 * HW_SSI_SSI_SRCR - SSI Receive Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 21;
        unsigned RXEXT : 1;
        unsigned RXBIT0 : 1;
        unsigned RFEN1 : 1;
        unsigned RFEN0 : 1;
        unsigned RFDIR : 1;
        unsigned RXDIR : 1;
        unsigned RSHFD : 1;
        unsigned RSCKP : 1;
        unsigned RFSI : 1;
        unsigned RFSL : 1;
        unsigned REFS : 1;

    } B;
} hw_ssi_ssi_srcr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SRCR register
 */
#define HW_SSI_SSI_SRCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SRCR(x)           (*(volatile hw_ssi_ssi_srcr_t *) HW_SSI_SSI_SRCR_ADDR(x))
#define HW_SSI_SSI_SRCR_RD(x)        (HW_SSI_SSI_SRCR(x).U)
#define HW_SSI_SSI_SRCR_WR(x, v)     (HW_SSI_SSI_SRCR(x).U = (v))
#define HW_SSI_SSI_SRCR_SET(x, v)    (HW_SSI_SSI_SRCR_WR(x, HW_SSI_SSI_SRCR_RD(x) |  (v)))
#define HW_SSI_SSI_SRCR_CLR(x, v)    (HW_SSI_SSI_SRCR_WR(x, HW_SSI_SSI_SRCR_RD(x) & ~(v)))
#define HW_SSI_SSI_SRCR_TOG(x, v)    (HW_SSI_SSI_SRCR_WR(x, HW_SSI_SSI_SRCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SRCR bitfields
 */

/* --- Register HW_SSI_SSI_SRCR, field RXEXT */

#define BP_SSI_SSI_SRCR_RXEXT      10
#define BM_SSI_SSI_SRCR_RXEXT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RXEXT(v)   ((((reg32_t) v) << 10) & BM_SSI_SSI_SRCR_RXEXT)
#else
#define BF_SSI_SSI_SRCR_RXEXT(v)   (((v) << 10) & BM_SSI_SSI_SRCR_RXEXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RXEXT(v)   BF_CS1(SSI_SSI_SRCR, RXEXT, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RXBIT0 */

#define BP_SSI_SSI_SRCR_RXBIT0      9
#define BM_SSI_SSI_SRCR_RXBIT0      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RXBIT0(v)   ((((reg32_t) v) << 9) & BM_SSI_SSI_SRCR_RXBIT0)
#else
#define BF_SSI_SSI_SRCR_RXBIT0(v)   (((v) << 9) & BM_SSI_SSI_SRCR_RXBIT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RXBIT0(v)   BF_CS1(SSI_SSI_SRCR, RXBIT0, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFEN1 */

#define BP_SSI_SSI_SRCR_RFEN1      8
#define BM_SSI_SSI_SRCR_RFEN1      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFEN1(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_SRCR_RFEN1)
#else
#define BF_SSI_SSI_SRCR_RFEN1(v)   (((v) << 8) & BM_SSI_SSI_SRCR_RFEN1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFEN1(v)   BF_CS1(SSI_SSI_SRCR, RFEN1, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFEN0 */

#define BP_SSI_SSI_SRCR_RFEN0      7
#define BM_SSI_SSI_SRCR_RFEN0      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFEN0(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_SRCR_RFEN0)
#else
#define BF_SSI_SSI_SRCR_RFEN0(v)   (((v) << 7) & BM_SSI_SSI_SRCR_RFEN0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFEN0(v)   BF_CS1(SSI_SSI_SRCR, RFEN0, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFDIR */

#define BP_SSI_SSI_SRCR_RFDIR      6
#define BM_SSI_SSI_SRCR_RFDIR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFDIR(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_SRCR_RFDIR)
#else
#define BF_SSI_SSI_SRCR_RFDIR(v)   (((v) << 6) & BM_SSI_SSI_SRCR_RFDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFDIR(v)   BF_CS1(SSI_SSI_SRCR, RFDIR, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RXDIR */

#define BP_SSI_SSI_SRCR_RXDIR      5
#define BM_SSI_SSI_SRCR_RXDIR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RXDIR(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SRCR_RXDIR)
#else
#define BF_SSI_SSI_SRCR_RXDIR(v)   (((v) << 5) & BM_SSI_SSI_SRCR_RXDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RXDIR(v)   BF_CS1(SSI_SSI_SRCR, RXDIR, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RSHFD */

#define BP_SSI_SSI_SRCR_RSHFD      4
#define BM_SSI_SSI_SRCR_RSHFD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RSHFD(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SRCR_RSHFD)
#else
#define BF_SSI_SSI_SRCR_RSHFD(v)   (((v) << 4) & BM_SSI_SSI_SRCR_RSHFD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RSHFD(v)   BF_CS1(SSI_SSI_SRCR, RSHFD, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RSCKP */

#define BP_SSI_SSI_SRCR_RSCKP      3
#define BM_SSI_SSI_SRCR_RSCKP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RSCKP(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SRCR_RSCKP)
#else
#define BF_SSI_SSI_SRCR_RSCKP(v)   (((v) << 3) & BM_SSI_SSI_SRCR_RSCKP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RSCKP(v)   BF_CS1(SSI_SSI_SRCR, RSCKP, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFSI */

#define BP_SSI_SSI_SRCR_RFSI      2
#define BM_SSI_SSI_SRCR_RFSI      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFSI(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_SRCR_RFSI)
#else
#define BF_SSI_SSI_SRCR_RFSI(v)   (((v) << 2) & BM_SSI_SSI_SRCR_RFSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFSI(v)   BF_CS1(SSI_SSI_SRCR, RFSI, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFSL */

#define BP_SSI_SSI_SRCR_RFSL      1
#define BM_SSI_SSI_SRCR_RFSL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFSL(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SRCR_RFSL)
#else
#define BF_SSI_SSI_SRCR_RFSL(v)   (((v) << 1) & BM_SSI_SSI_SRCR_RFSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFSL(v)   BF_CS1(SSI_SSI_SRCR, RFSL, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field REFS */

#define BP_SSI_SSI_SRCR_REFS      0
#define BM_SSI_SSI_SRCR_REFS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_REFS(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SRCR_REFS)
#else
#define BF_SSI_SSI_SRCR_REFS(v)   (((v) << 0) & BM_SSI_SSI_SRCR_REFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_REFS(v)   BF_CS1(SSI_SSI_SRCR, REFS, v)
#endif

/*
 * HW_SSI_SSI_STCCR - SSI Transmit Clock Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 13;
        unsigned DIV2 : 1;
        unsigned PSR : 1;
        unsigned WL3 : 4;
        unsigned DC4 : 5;
        unsigned PM7 : 8;

    } B;
} hw_ssi_ssi_stccr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STCCR register
 */
#define HW_SSI_SSI_STCCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STCCR(x)           (*(volatile hw_ssi_ssi_stccr_t *) HW_SSI_SSI_STCCR_ADDR(x))
#define HW_SSI_SSI_STCCR_RD(x)        (HW_SSI_SSI_STCCR(x).U)
#define HW_SSI_SSI_STCCR_WR(x, v)     (HW_SSI_SSI_STCCR(x).U = (v))
#define HW_SSI_SSI_STCCR_SET(x, v)    (HW_SSI_SSI_STCCR_WR(x, HW_SSI_SSI_STCCR_RD(x) |  (v)))
#define HW_SSI_SSI_STCCR_CLR(x, v)    (HW_SSI_SSI_STCCR_WR(x, HW_SSI_SSI_STCCR_RD(x) & ~(v)))
#define HW_SSI_SSI_STCCR_TOG(x, v)    (HW_SSI_SSI_STCCR_WR(x, HW_SSI_SSI_STCCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STCCR bitfields
 */

/* --- Register HW_SSI_SSI_STCCR, field DIV2 */

#define BP_SSI_SSI_STCCR_DIV2      18
#define BM_SSI_SSI_STCCR_DIV2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_DIV2(v)   ((((reg32_t) v) << 18) & BM_SSI_SSI_STCCR_DIV2)
#else
#define BF_SSI_SSI_STCCR_DIV2(v)   (((v) << 18) & BM_SSI_SSI_STCCR_DIV2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_DIV2(v)   BF_CS1(SSI_SSI_STCCR, DIV2, v)
#endif

/* --- Register HW_SSI_SSI_STCCR, field PSR */

#define BP_SSI_SSI_STCCR_PSR      17
#define BM_SSI_SSI_STCCR_PSR      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_PSR(v)   ((((reg32_t) v) << 17) & BM_SSI_SSI_STCCR_PSR)
#else
#define BF_SSI_SSI_STCCR_PSR(v)   (((v) << 17) & BM_SSI_SSI_STCCR_PSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_PSR(v)   BF_CS1(SSI_SSI_STCCR, PSR, v)
#endif

/* --- Register HW_SSI_SSI_STCCR, field WL3 */

#define BP_SSI_SSI_STCCR_WL3      13
#define BM_SSI_SSI_STCCR_WL3      0x0001e000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_WL3(v)   ((((reg32_t) v) << 13) & BM_SSI_SSI_STCCR_WL3)
#else
#define BF_SSI_SSI_STCCR_WL3(v)   (((v) << 13) & BM_SSI_SSI_STCCR_WL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_WL3(v)   BF_CS1(SSI_SSI_STCCR, WL3, v)
#endif

/* --- Register HW_SSI_SSI_STCCR, field DC4 */

#define BP_SSI_SSI_STCCR_DC4      8
#define BM_SSI_SSI_STCCR_DC4      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_DC4(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_STCCR_DC4)
#else
#define BF_SSI_SSI_STCCR_DC4(v)   (((v) << 8) & BM_SSI_SSI_STCCR_DC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_DC4(v)   BF_CS1(SSI_SSI_STCCR, DC4, v)
#endif

/* --- Register HW_SSI_SSI_STCCR, field PM7 */

#define BP_SSI_SSI_STCCR_PM7      0
#define BM_SSI_SSI_STCCR_PM7      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_PM7(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STCCR_PM7)
#else
#define BF_SSI_SSI_STCCR_PM7(v)   (((v) << 0) & BM_SSI_SSI_STCCR_PM7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_PM7(v)   BF_CS1(SSI_SSI_STCCR, PM7, v)
#endif

/*
 * HW_SSI_SRCCR - SSI Receive Clock Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 13;
        unsigned DIV2 : 1;
        unsigned PSR : 1;
        unsigned WL3 : 4;
        unsigned DC4 : 5;
        unsigned PM7 : 8;

    } B;
} hw_ssi_srccr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SRCCR register
 */
#define HW_SSI_SRCCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SRCCR(x)           (*(volatile hw_ssi_srccr_t *) HW_SSI_SRCCR_ADDR(x))
#define HW_SSI_SRCCR_RD(x)        (HW_SSI_SRCCR(x).U)
#define HW_SSI_SRCCR_WR(x, v)     (HW_SSI_SRCCR(x).U = (v))
#define HW_SSI_SRCCR_SET(x, v)    (HW_SSI_SRCCR_WR(x, HW_SSI_SRCCR_RD(x) |  (v)))
#define HW_SSI_SRCCR_CLR(x, v)    (HW_SSI_SRCCR_WR(x, HW_SSI_SRCCR_RD(x) & ~(v)))
#define HW_SSI_SRCCR_TOG(x, v)    (HW_SSI_SRCCR_WR(x, HW_SSI_SRCCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SRCCR bitfields
 */

/* --- Register HW_SSI_SRCCR, field DIV2 */

#define BP_SSI_SRCCR_DIV2      18
#define BM_SSI_SRCCR_DIV2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_DIV2(v)   ((((reg32_t) v) << 18) & BM_SSI_SRCCR_DIV2)
#else
#define BF_SSI_SRCCR_DIV2(v)   (((v) << 18) & BM_SSI_SRCCR_DIV2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_DIV2(v)   BF_CS1(SSI_SRCCR, DIV2, v)
#endif

/* --- Register HW_SSI_SRCCR, field PSR */

#define BP_SSI_SRCCR_PSR      17
#define BM_SSI_SRCCR_PSR      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_PSR(v)   ((((reg32_t) v) << 17) & BM_SSI_SRCCR_PSR)
#else
#define BF_SSI_SRCCR_PSR(v)   (((v) << 17) & BM_SSI_SRCCR_PSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_PSR(v)   BF_CS1(SSI_SRCCR, PSR, v)
#endif

/* --- Register HW_SSI_SRCCR, field WL3 */

#define BP_SSI_SRCCR_WL3      13
#define BM_SSI_SRCCR_WL3      0x0001e000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_WL3(v)   ((((reg32_t) v) << 13) & BM_SSI_SRCCR_WL3)
#else
#define BF_SSI_SRCCR_WL3(v)   (((v) << 13) & BM_SSI_SRCCR_WL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_WL3(v)   BF_CS1(SSI_SRCCR, WL3, v)
#endif

/* --- Register HW_SSI_SRCCR, field DC4 */

#define BP_SSI_SRCCR_DC4      8
#define BM_SSI_SRCCR_DC4      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_DC4(v)   ((((reg32_t) v) << 8) & BM_SSI_SRCCR_DC4)
#else
#define BF_SSI_SRCCR_DC4(v)   (((v) << 8) & BM_SSI_SRCCR_DC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_DC4(v)   BF_CS1(SSI_SRCCR, DC4, v)
#endif

/* --- Register HW_SSI_SRCCR, field PM7 */

#define BP_SSI_SRCCR_PM7      0
#define BM_SSI_SRCCR_PM7      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_PM7(v)   ((((reg32_t) v) << 0) & BM_SSI_SRCCR_PM7)
#else
#define BF_SSI_SRCCR_PM7(v)   (((v) << 0) & BM_SSI_SRCCR_PM7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_PM7(v)   BF_CS1(SSI_SRCCR, PM7, v)
#endif

/*
 * HW_SSI_SSI_SFCSR - SSI FIFO Control/Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RFCNT1 : 4;
        unsigned TFCNT1 : 4;
        unsigned RFWM1 : 4;
        unsigned TFWM1 : 4;
        unsigned RFCNT0 : 4;
        unsigned TFCNT0 : 4;
        unsigned RFWM0 : 4;
        unsigned TFWM0 : 4;

    } B;
} hw_ssi_ssi_sfcsr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SFCSR register
 */
#define HW_SSI_SSI_SFCSR_ADDR(x)      (REGS_SSI_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SFCSR(x)           (*(volatile hw_ssi_ssi_sfcsr_t *) HW_SSI_SSI_SFCSR_ADDR(x))
#define HW_SSI_SSI_SFCSR_RD(x)        (HW_SSI_SSI_SFCSR(x).U)
#define HW_SSI_SSI_SFCSR_WR(x, v)     (HW_SSI_SSI_SFCSR(x).U = (v))
#define HW_SSI_SSI_SFCSR_SET(x, v)    (HW_SSI_SSI_SFCSR_WR(x, HW_SSI_SSI_SFCSR_RD(x) |  (v)))
#define HW_SSI_SSI_SFCSR_CLR(x, v)    (HW_SSI_SSI_SFCSR_WR(x, HW_SSI_SSI_SFCSR_RD(x) & ~(v)))
#define HW_SSI_SSI_SFCSR_TOG(x, v)    (HW_SSI_SSI_SFCSR_WR(x, HW_SSI_SSI_SFCSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SFCSR bitfields
 */

/* --- Register HW_SSI_SSI_SFCSR, field RFCNT1 */

#define BP_SSI_SSI_SFCSR_RFCNT1      28
#define BM_SSI_SSI_SFCSR_RFCNT1      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_RFCNT1(v)   ((((reg32_t) v) << 28) & BM_SSI_SSI_SFCSR_RFCNT1)
#else
#define BF_SSI_SSI_SFCSR_RFCNT1(v)   (((v) << 28) & BM_SSI_SSI_SFCSR_RFCNT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_RFCNT1(v)   BF_CS1(SSI_SSI_SFCSR, RFCNT1, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFCNT1 */

#define BP_SSI_SSI_SFCSR_TFCNT1      24
#define BM_SSI_SSI_SFCSR_TFCNT1      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_TFCNT1(v)   ((((reg32_t) v) << 24) & BM_SSI_SSI_SFCSR_TFCNT1)
#else
#define BF_SSI_SSI_SFCSR_TFCNT1(v)   (((v) << 24) & BM_SSI_SSI_SFCSR_TFCNT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_TFCNT1(v)   BF_CS1(SSI_SSI_SFCSR, TFCNT1, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFWM1 */

#define BP_SSI_SSI_SFCSR_RFWM1      20
#define BM_SSI_SSI_SFCSR_RFWM1      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_RFWM1(v)   ((((reg32_t) v) << 20) & BM_SSI_SSI_SFCSR_RFWM1)
#else
#define BF_SSI_SSI_SFCSR_RFWM1(v)   (((v) << 20) & BM_SSI_SSI_SFCSR_RFWM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_RFWM1(v)   BF_CS1(SSI_SSI_SFCSR, RFWM1, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFWM1 */

#define BP_SSI_SSI_SFCSR_TFWM1      16
#define BM_SSI_SSI_SFCSR_TFWM1      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_TFWM1(v)   ((((reg32_t) v) << 16) & BM_SSI_SSI_SFCSR_TFWM1)
#else
#define BF_SSI_SSI_SFCSR_TFWM1(v)   (((v) << 16) & BM_SSI_SSI_SFCSR_TFWM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_TFWM1(v)   BF_CS1(SSI_SSI_SFCSR, TFWM1, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFCNT0 */

#define BP_SSI_SSI_SFCSR_RFCNT0      12
#define BM_SSI_SSI_SFCSR_RFCNT0      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_RFCNT0(v)   ((((reg32_t) v) << 12) & BM_SSI_SSI_SFCSR_RFCNT0)
#else
#define BF_SSI_SSI_SFCSR_RFCNT0(v)   (((v) << 12) & BM_SSI_SSI_SFCSR_RFCNT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_RFCNT0(v)   BF_CS1(SSI_SSI_SFCSR, RFCNT0, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFCNT0 */

#define BP_SSI_SSI_SFCSR_TFCNT0      8
#define BM_SSI_SSI_SFCSR_TFCNT0      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_TFCNT0(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_SFCSR_TFCNT0)
#else
#define BF_SSI_SSI_SFCSR_TFCNT0(v)   (((v) << 8) & BM_SSI_SSI_SFCSR_TFCNT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_TFCNT0(v)   BF_CS1(SSI_SSI_SFCSR, TFCNT0, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFWM0 */

#define BP_SSI_SSI_SFCSR_RFWM0      4
#define BM_SSI_SSI_SFCSR_RFWM0      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_RFWM0(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SFCSR_RFWM0)
#else
#define BF_SSI_SSI_SFCSR_RFWM0(v)   (((v) << 4) & BM_SSI_SSI_SFCSR_RFWM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_RFWM0(v)   BF_CS1(SSI_SSI_SFCSR, RFWM0, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFWM0 */

#define BP_SSI_SSI_SFCSR_TFWM0      0
#define BM_SSI_SSI_SFCSR_TFWM0      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_TFWM0(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SFCSR_TFWM0)
#else
#define BF_SSI_SSI_SFCSR_TFWM0(v)   (((v) << 0) & BM_SSI_SSI_SFCSR_TFWM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_TFWM0(v)   BF_CS1(SSI_SSI_SFCSR, TFWM0, v)
#endif

/*
 * HW_SSI_SSI_STR - SSI Test Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned TEST : 1;
        unsigned RCK2TCK : 1;
        unsigned RFS2TFS : 1;
        unsigned RXSTATE : 5;
        unsigned TXD2RXD : 1;
        unsigned TCK2RCK : 1;
        unsigned TFS2RFS : 1;
        unsigned TXSTATE : 5;

    } B;
} hw_ssi_ssi_str_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STR register
 */
#define HW_SSI_SSI_STR_ADDR(x)      (REGS_SSI_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STR(x)           (*(volatile hw_ssi_ssi_str_t *) HW_SSI_SSI_STR_ADDR(x))
#define HW_SSI_SSI_STR_RD(x)        (HW_SSI_SSI_STR(x).U)
#define HW_SSI_SSI_STR_WR(x, v)     (HW_SSI_SSI_STR(x).U = (v))
#define HW_SSI_SSI_STR_SET(x, v)    (HW_SSI_SSI_STR_WR(x, HW_SSI_SSI_STR_RD(x) |  (v)))
#define HW_SSI_SSI_STR_CLR(x, v)    (HW_SSI_SSI_STR_WR(x, HW_SSI_SSI_STR_RD(x) & ~(v)))
#define HW_SSI_SSI_STR_TOG(x, v)    (HW_SSI_SSI_STR_WR(x, HW_SSI_SSI_STR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STR bitfields
 */

/* --- Register HW_SSI_SSI_STR, field TEST */

#define BP_SSI_SSI_STR_TEST      15
#define BM_SSI_SSI_STR_TEST      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STR_TEST(v)   ((((reg32_t) v) << 15) & BM_SSI_SSI_STR_TEST)
#else
#define BF_SSI_SSI_STR_TEST(v)   (((v) << 15) & BM_SSI_SSI_STR_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STR_TEST(v)   BF_CS1(SSI_SSI_STR, TEST, v)
#endif

/* --- Register HW_SSI_SSI_STR, field RCK2TCK */

#define BP_SSI_SSI_STR_RCK2TCK      14
#define BM_SSI_SSI_STR_RCK2TCK      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STR_RCK2TCK(v)   ((((reg32_t) v) << 14) & BM_SSI_SSI_STR_RCK2TCK)
#else
#define BF_SSI_SSI_STR_RCK2TCK(v)   (((v) << 14) & BM_SSI_SSI_STR_RCK2TCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STR_RCK2TCK(v)   BF_CS1(SSI_SSI_STR, RCK2TCK, v)
#endif

/* --- Register HW_SSI_SSI_STR, field RFS2TFS */

#define BP_SSI_SSI_STR_RFS2TFS      13
#define BM_SSI_SSI_STR_RFS2TFS      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STR_RFS2TFS(v)   ((((reg32_t) v) << 13) & BM_SSI_SSI_STR_RFS2TFS)
#else
#define BF_SSI_SSI_STR_RFS2TFS(v)   (((v) << 13) & BM_SSI_SSI_STR_RFS2TFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STR_RFS2TFS(v)   BF_CS1(SSI_SSI_STR, RFS2TFS, v)
#endif

/* --- Register HW_SSI_SSI_STR, field RXSTATE */

#define BP_SSI_SSI_STR_RXSTATE      8
#define BM_SSI_SSI_STR_RXSTATE      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STR_RXSTATE(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_STR_RXSTATE)
#else
#define BF_SSI_SSI_STR_RXSTATE(v)   (((v) << 8) & BM_SSI_SSI_STR_RXSTATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STR_RXSTATE(v)   BF_CS1(SSI_SSI_STR, RXSTATE, v)
#endif

/* --- Register HW_SSI_SSI_STR, field TXD2RXD */

#define BP_SSI_SSI_STR_TXD2RXD      7
#define BM_SSI_SSI_STR_TXD2RXD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STR_TXD2RXD(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_STR_TXD2RXD)
#else
#define BF_SSI_SSI_STR_TXD2RXD(v)   (((v) << 7) & BM_SSI_SSI_STR_TXD2RXD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STR_TXD2RXD(v)   BF_CS1(SSI_SSI_STR, TXD2RXD, v)
#endif

/* --- Register HW_SSI_SSI_STR, field TCK2RCK */

#define BP_SSI_SSI_STR_TCK2RCK      6
#define BM_SSI_SSI_STR_TCK2RCK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STR_TCK2RCK(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_STR_TCK2RCK)
#else
#define BF_SSI_SSI_STR_TCK2RCK(v)   (((v) << 6) & BM_SSI_SSI_STR_TCK2RCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STR_TCK2RCK(v)   BF_CS1(SSI_SSI_STR, TCK2RCK, v)
#endif

/* --- Register HW_SSI_SSI_STR, field TFS2RFS */

#define BP_SSI_SSI_STR_TFS2RFS      5
#define BM_SSI_SSI_STR_TFS2RFS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STR_TFS2RFS(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_STR_TFS2RFS)
#else
#define BF_SSI_SSI_STR_TFS2RFS(v)   (((v) << 5) & BM_SSI_SSI_STR_TFS2RFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STR_TFS2RFS(v)   BF_CS1(SSI_SSI_STR, TFS2RFS, v)
#endif

/* --- Register HW_SSI_SSI_STR, field TXSTATE */

#define BP_SSI_SSI_STR_TXSTATE      0
#define BM_SSI_SSI_STR_TXSTATE      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STR_TXSTATE(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STR_TXSTATE)
#else
#define BF_SSI_SSI_STR_TXSTATE(v)   (((v) << 0) & BM_SSI_SSI_STR_TXSTATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STR_TXSTATE(v)   BF_CS1(SSI_SSI_STR, TXSTATE, v)
#endif

/*
 * HW_SSI_SSI_SOR - SSI Option Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 25;
        unsigned CLKOFF : 1;
        unsigned RX_CLR : 1;
        unsigned TX_CLR : 1;
        unsigned INIT : 1;
        unsigned WAIT : 2;
        unsigned SYNRST : 1;

    } B;
} hw_ssi_ssi_sor_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SOR register
 */
#define HW_SSI_SSI_SOR_ADDR(x)      (REGS_SSI_BASE(x) + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SOR(x)           (*(volatile hw_ssi_ssi_sor_t *) HW_SSI_SSI_SOR_ADDR(x))
#define HW_SSI_SSI_SOR_RD(x)        (HW_SSI_SSI_SOR(x).U)
#define HW_SSI_SSI_SOR_WR(x, v)     (HW_SSI_SSI_SOR(x).U = (v))
#define HW_SSI_SSI_SOR_SET(x, v)    (HW_SSI_SSI_SOR_WR(x, HW_SSI_SSI_SOR_RD(x) |  (v)))
#define HW_SSI_SSI_SOR_CLR(x, v)    (HW_SSI_SSI_SOR_WR(x, HW_SSI_SSI_SOR_RD(x) & ~(v)))
#define HW_SSI_SSI_SOR_TOG(x, v)    (HW_SSI_SSI_SOR_WR(x, HW_SSI_SSI_SOR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SOR bitfields
 */

/* --- Register HW_SSI_SSI_SOR, field CLKOFF */

#define BP_SSI_SSI_SOR_CLKOFF      6
#define BM_SSI_SSI_SOR_CLKOFF      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SOR_CLKOFF(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_SOR_CLKOFF)
#else
#define BF_SSI_SSI_SOR_CLKOFF(v)   (((v) << 6) & BM_SSI_SSI_SOR_CLKOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SOR_CLKOFF(v)   BF_CS1(SSI_SSI_SOR, CLKOFF, v)
#endif

/* --- Register HW_SSI_SSI_SOR, field RX_CLR */

#define BP_SSI_SSI_SOR_RX_CLR      5
#define BM_SSI_SSI_SOR_RX_CLR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SOR_RX_CLR(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SOR_RX_CLR)
#else
#define BF_SSI_SSI_SOR_RX_CLR(v)   (((v) << 5) & BM_SSI_SSI_SOR_RX_CLR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SOR_RX_CLR(v)   BF_CS1(SSI_SSI_SOR, RX_CLR, v)
#endif

/* --- Register HW_SSI_SSI_SOR, field TX_CLR */

#define BP_SSI_SSI_SOR_TX_CLR      4
#define BM_SSI_SSI_SOR_TX_CLR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SOR_TX_CLR(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SOR_TX_CLR)
#else
#define BF_SSI_SSI_SOR_TX_CLR(v)   (((v) << 4) & BM_SSI_SSI_SOR_TX_CLR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SOR_TX_CLR(v)   BF_CS1(SSI_SSI_SOR, TX_CLR, v)
#endif

/* --- Register HW_SSI_SSI_SOR, field INIT */

#define BP_SSI_SSI_SOR_INIT      3
#define BM_SSI_SSI_SOR_INIT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SOR_INIT(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SOR_INIT)
#else
#define BF_SSI_SSI_SOR_INIT(v)   (((v) << 3) & BM_SSI_SSI_SOR_INIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SOR_INIT(v)   BF_CS1(SSI_SSI_SOR, INIT, v)
#endif

/* --- Register HW_SSI_SSI_SOR, field WAIT */

#define BP_SSI_SSI_SOR_WAIT      1
#define BM_SSI_SSI_SOR_WAIT      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SOR_WAIT(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SOR_WAIT)
#else
#define BF_SSI_SSI_SOR_WAIT(v)   (((v) << 1) & BM_SSI_SSI_SOR_WAIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SOR_WAIT(v)   BF_CS1(SSI_SSI_SOR, WAIT, v)
#endif

/* --- Register HW_SSI_SSI_SOR, field SYNRST */

#define BP_SSI_SSI_SOR_SYNRST      0
#define BM_SSI_SSI_SOR_SYNRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SOR_SYNRST(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SOR_SYNRST)
#else
#define BF_SSI_SSI_SOR_SYNRST(v)   (((v) << 0) & BM_SSI_SSI_SOR_SYNRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SOR_SYNRST(v)   BF_CS1(SSI_SSI_SOR, SYNRST, v)
#endif

/*
 * HW_SSI_SSI_SACNT - SSI AC97 Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 21;
        unsigned FRDIV : 6;
        unsigned WR : 1;
        unsigned RD : 1;
        unsigned TIF : 1;
        unsigned FV : 1;
        unsigned AC97EN : 1;

    } B;
} hw_ssi_ssi_sacnt_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACNT register
 */
#define HW_SSI_SSI_SACNT_ADDR(x)      (REGS_SSI_BASE(x) + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACNT(x)           (*(volatile hw_ssi_ssi_sacnt_t *) HW_SSI_SSI_SACNT_ADDR(x))
#define HW_SSI_SSI_SACNT_RD(x)        (HW_SSI_SSI_SACNT(x).U)
#define HW_SSI_SSI_SACNT_WR(x, v)     (HW_SSI_SSI_SACNT(x).U = (v))
#define HW_SSI_SSI_SACNT_SET(x, v)    (HW_SSI_SSI_SACNT_WR(x, HW_SSI_SSI_SACNT_RD(x) |  (v)))
#define HW_SSI_SSI_SACNT_CLR(x, v)    (HW_SSI_SSI_SACNT_WR(x, HW_SSI_SSI_SACNT_RD(x) & ~(v)))
#define HW_SSI_SSI_SACNT_TOG(x, v)    (HW_SSI_SSI_SACNT_WR(x, HW_SSI_SSI_SACNT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACNT bitfields
 */

/* --- Register HW_SSI_SSI_SACNT, field FRDIV */

#define BP_SSI_SSI_SACNT_FRDIV      5
#define BM_SSI_SSI_SACNT_FRDIV      0x000007e0

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_FRDIV(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SACNT_FRDIV)
#else
#define BF_SSI_SSI_SACNT_FRDIV(v)   (((v) << 5) & BM_SSI_SSI_SACNT_FRDIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_FRDIV(v)   BF_CS1(SSI_SSI_SACNT, FRDIV, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field WR */

#define BP_SSI_SSI_SACNT_WR      4
#define BM_SSI_SSI_SACNT_WR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_WR(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SACNT_WR)
#else
#define BF_SSI_SSI_SACNT_WR(v)   (((v) << 4) & BM_SSI_SSI_SACNT_WR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_WR(v)   BF_CS1(SSI_SSI_SACNT, WR, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field RD */

#define BP_SSI_SSI_SACNT_RD      3
#define BM_SSI_SSI_SACNT_RD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_RD(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SACNT_RD)
#else
#define BF_SSI_SSI_SACNT_RD(v)   (((v) << 3) & BM_SSI_SSI_SACNT_RD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_RD(v)   BF_CS1(SSI_SSI_SACNT, RD, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field TIF */

#define BP_SSI_SSI_SACNT_TIF      2
#define BM_SSI_SSI_SACNT_TIF      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_TIF(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_SACNT_TIF)
#else
#define BF_SSI_SSI_SACNT_TIF(v)   (((v) << 2) & BM_SSI_SSI_SACNT_TIF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_TIF(v)   BF_CS1(SSI_SSI_SACNT, TIF, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field FV */

#define BP_SSI_SSI_SACNT_FV      1
#define BM_SSI_SSI_SACNT_FV      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_FV(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SACNT_FV)
#else
#define BF_SSI_SSI_SACNT_FV(v)   (((v) << 1) & BM_SSI_SSI_SACNT_FV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_FV(v)   BF_CS1(SSI_SSI_SACNT, FV, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field AC97EN */

#define BP_SSI_SSI_SACNT_AC97EN      0
#define BM_SSI_SSI_SACNT_AC97EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_AC97EN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACNT_AC97EN)
#else
#define BF_SSI_SSI_SACNT_AC97EN(v)   (((v) << 0) & BM_SSI_SSI_SACNT_AC97EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_AC97EN(v)   BF_CS1(SSI_SSI_SACNT, AC97EN, v)
#endif

/*
 * HW_SSI_SSI_SACADD - SSI AC97 Command Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 13;
        unsigned SACADD : 19;

    } B;
} hw_ssi_ssi_sacadd_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACADD register
 */
#define HW_SSI_SSI_SACADD_ADDR(x)      (REGS_SSI_BASE(x) + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACADD(x)           (*(volatile hw_ssi_ssi_sacadd_t *) HW_SSI_SSI_SACADD_ADDR(x))
#define HW_SSI_SSI_SACADD_RD(x)        (HW_SSI_SSI_SACADD(x).U)
#define HW_SSI_SSI_SACADD_WR(x, v)     (HW_SSI_SSI_SACADD(x).U = (v))
#define HW_SSI_SSI_SACADD_SET(x, v)    (HW_SSI_SSI_SACADD_WR(x, HW_SSI_SSI_SACADD_RD(x) |  (v)))
#define HW_SSI_SSI_SACADD_CLR(x, v)    (HW_SSI_SSI_SACADD_WR(x, HW_SSI_SSI_SACADD_RD(x) & ~(v)))
#define HW_SSI_SSI_SACADD_TOG(x, v)    (HW_SSI_SSI_SACADD_WR(x, HW_SSI_SSI_SACADD_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACADD bitfields
 */

/* --- Register HW_SSI_SSI_SACADD, field SACADD */

#define BP_SSI_SSI_SACADD_SACADD      0
#define BM_SSI_SSI_SACADD_SACADD      0x0007ffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACADD_SACADD(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACADD_SACADD)
#else
#define BF_SSI_SSI_SACADD_SACADD(v)   (((v) << 0) & BM_SSI_SSI_SACADD_SACADD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACADD_SACADD(v)   BF_CS1(SSI_SSI_SACADD, SACADD, v)
#endif

/*
 * HW_SSI_SSI_SACDAT - SSI AC97 Command Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 12;
        unsigned SACDAT : 20;

    } B;
} hw_ssi_ssi_sacdat_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACDAT register
 */
#define HW_SSI_SSI_SACDAT_ADDR(x)      (REGS_SSI_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACDAT(x)           (*(volatile hw_ssi_ssi_sacdat_t *) HW_SSI_SSI_SACDAT_ADDR(x))
#define HW_SSI_SSI_SACDAT_RD(x)        (HW_SSI_SSI_SACDAT(x).U)
#define HW_SSI_SSI_SACDAT_WR(x, v)     (HW_SSI_SSI_SACDAT(x).U = (v))
#define HW_SSI_SSI_SACDAT_SET(x, v)    (HW_SSI_SSI_SACDAT_WR(x, HW_SSI_SSI_SACDAT_RD(x) |  (v)))
#define HW_SSI_SSI_SACDAT_CLR(x, v)    (HW_SSI_SSI_SACDAT_WR(x, HW_SSI_SSI_SACDAT_RD(x) & ~(v)))
#define HW_SSI_SSI_SACDAT_TOG(x, v)    (HW_SSI_SSI_SACDAT_WR(x, HW_SSI_SSI_SACDAT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACDAT bitfields
 */

/* --- Register HW_SSI_SSI_SACDAT, field SACDAT */

#define BP_SSI_SSI_SACDAT_SACDAT      0
#define BM_SSI_SSI_SACDAT_SACDAT      0x000fffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACDAT_SACDAT(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACDAT_SACDAT)
#else
#define BF_SSI_SSI_SACDAT_SACDAT(v)   (((v) << 0) & BM_SSI_SSI_SACDAT_SACDAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACDAT_SACDAT(v)   BF_CS1(SSI_SSI_SACDAT, SACDAT, v)
#endif

/*
 * HW_SSI_SATAG - SSI AC97 Tag Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned SATAG : 16;

    } B;
} hw_ssi_satag_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SATAG register
 */
#define HW_SSI_SATAG_ADDR(x)      (REGS_SSI_BASE(x) + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SATAG(x)           (*(volatile hw_ssi_satag_t *) HW_SSI_SATAG_ADDR(x))
#define HW_SSI_SATAG_RD(x)        (HW_SSI_SATAG(x).U)
#define HW_SSI_SATAG_WR(x, v)     (HW_SSI_SATAG(x).U = (v))
#define HW_SSI_SATAG_SET(x, v)    (HW_SSI_SATAG_WR(x, HW_SSI_SATAG_RD(x) |  (v)))
#define HW_SSI_SATAG_CLR(x, v)    (HW_SSI_SATAG_WR(x, HW_SSI_SATAG_RD(x) & ~(v)))
#define HW_SSI_SATAG_TOG(x, v)    (HW_SSI_SATAG_WR(x, HW_SSI_SATAG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SATAG bitfields
 */

/* --- Register HW_SSI_SATAG, field SATAG */

#define BP_SSI_SATAG_SATAG      0
#define BM_SSI_SATAG_SATAG      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SATAG_SATAG(v)   ((((reg32_t) v) << 0) & BM_SSI_SATAG_SATAG)
#else
#define BF_SSI_SATAG_SATAG(v)   (((v) << 0) & BM_SSI_SATAG_SATAG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SATAG_SATAG(v)   BF_CS1(SSI_SATAG, SATAG, v)
#endif

/*
 * HW_SSI_SSI_STMSK - SSI Transmit Time Slot Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned STMSK : 32;

    } B;
} hw_ssi_ssi_stmsk_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STMSK register
 */
#define HW_SSI_SSI_STMSK_ADDR(x)      (REGS_SSI_BASE(x) + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STMSK(x)           (*(volatile hw_ssi_ssi_stmsk_t *) HW_SSI_SSI_STMSK_ADDR(x))
#define HW_SSI_SSI_STMSK_RD(x)        (HW_SSI_SSI_STMSK(x).U)
#define HW_SSI_SSI_STMSK_WR(x, v)     (HW_SSI_SSI_STMSK(x).U = (v))
#define HW_SSI_SSI_STMSK_SET(x, v)    (HW_SSI_SSI_STMSK_WR(x, HW_SSI_SSI_STMSK_RD(x) |  (v)))
#define HW_SSI_SSI_STMSK_CLR(x, v)    (HW_SSI_SSI_STMSK_WR(x, HW_SSI_SSI_STMSK_RD(x) & ~(v)))
#define HW_SSI_SSI_STMSK_TOG(x, v)    (HW_SSI_SSI_STMSK_WR(x, HW_SSI_SSI_STMSK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STMSK bitfields
 */

/* --- Register HW_SSI_SSI_STMSK, field STMSK */

#define BP_SSI_SSI_STMSK_STMSK      0
#define BM_SSI_SSI_STMSK_STMSK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STMSK_STMSK(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STMSK_STMSK)
#else
#define BF_SSI_SSI_STMSK_STMSK(v)   (((v) << 0) & BM_SSI_SSI_STMSK_STMSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STMSK_STMSK(v)   BF_CS1(SSI_SSI_STMSK, STMSK, v)
#endif

/*
 * HW_SSI_SSI_SRMSK - SSI Receive Time Slot Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SRMSK : 32;

    } B;
} hw_ssi_ssi_srmsk_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SRMSK register
 */
#define HW_SSI_SSI_SRMSK_ADDR(x)      (REGS_SSI_BASE(x) + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SRMSK(x)           (*(volatile hw_ssi_ssi_srmsk_t *) HW_SSI_SSI_SRMSK_ADDR(x))
#define HW_SSI_SSI_SRMSK_RD(x)        (HW_SSI_SSI_SRMSK(x).U)
#define HW_SSI_SSI_SRMSK_WR(x, v)     (HW_SSI_SSI_SRMSK(x).U = (v))
#define HW_SSI_SSI_SRMSK_SET(x, v)    (HW_SSI_SSI_SRMSK_WR(x, HW_SSI_SSI_SRMSK_RD(x) |  (v)))
#define HW_SSI_SSI_SRMSK_CLR(x, v)    (HW_SSI_SSI_SRMSK_WR(x, HW_SSI_SSI_SRMSK_RD(x) & ~(v)))
#define HW_SSI_SSI_SRMSK_TOG(x, v)    (HW_SSI_SSI_SRMSK_WR(x, HW_SSI_SSI_SRMSK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SRMSK bitfields
 */

/* --- Register HW_SSI_SSI_SRMSK, field SRMSK */

#define BP_SSI_SSI_SRMSK_SRMSK      0
#define BM_SSI_SSI_SRMSK_SRMSK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRMSK_SRMSK(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SRMSK_SRMSK)
#else
#define BF_SSI_SSI_SRMSK_SRMSK(v)   (((v) << 0) & BM_SSI_SSI_SRMSK_SRMSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRMSK_SRMSK(v)   BF_CS1(SSI_SSI_SRMSK, SRMSK, v)
#endif

/*
 * HW_SSI_SSI_SACCST - SSI AC97 Channel Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 22;
        unsigned SACCST : 10;

    } B;
} hw_ssi_ssi_saccst_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACCST register
 */
#define HW_SSI_SSI_SACCST_ADDR(x)      (REGS_SSI_BASE(x) + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACCST(x)           (*(volatile hw_ssi_ssi_saccst_t *) HW_SSI_SSI_SACCST_ADDR(x))
#define HW_SSI_SSI_SACCST_RD(x)        (HW_SSI_SSI_SACCST(x).U)
#define HW_SSI_SSI_SACCST_WR(x, v)     (HW_SSI_SSI_SACCST(x).U = (v))
#define HW_SSI_SSI_SACCST_SET(x, v)    (HW_SSI_SSI_SACCST_WR(x, HW_SSI_SSI_SACCST_RD(x) |  (v)))
#define HW_SSI_SSI_SACCST_CLR(x, v)    (HW_SSI_SSI_SACCST_WR(x, HW_SSI_SSI_SACCST_RD(x) & ~(v)))
#define HW_SSI_SSI_SACCST_TOG(x, v)    (HW_SSI_SSI_SACCST_WR(x, HW_SSI_SSI_SACCST_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACCST bitfields
 */

/* --- Register HW_SSI_SSI_SACCST, field SACCST */

#define BP_SSI_SSI_SACCST_SACCST      0
#define BM_SSI_SSI_SACCST_SACCST      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACCST_SACCST(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACCST_SACCST)
#else
#define BF_SSI_SSI_SACCST_SACCST(v)   (((v) << 0) & BM_SSI_SSI_SACCST_SACCST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACCST_SACCST(v)   BF_CS1(SSI_SSI_SACCST, SACCST, v)
#endif

/*
 * HW_SSI_SSI_SACCEN - SSI AC97 Channel Enable Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 22;
        unsigned SACCEN : 10;

    } B;
} hw_ssi_ssi_saccen_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACCEN register
 */
#define HW_SSI_SSI_SACCEN_ADDR(x)      (REGS_SSI_BASE(x) + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACCEN(x)           (*(volatile hw_ssi_ssi_saccen_t *) HW_SSI_SSI_SACCEN_ADDR(x))
#define HW_SSI_SSI_SACCEN_RD(x)        (HW_SSI_SSI_SACCEN(x).U)
#define HW_SSI_SSI_SACCEN_WR(x, v)     (HW_SSI_SSI_SACCEN(x).U = (v))
#define HW_SSI_SSI_SACCEN_SET(x, v)    (HW_SSI_SSI_SACCEN_WR(x, HW_SSI_SSI_SACCEN_RD(x) |  (v)))
#define HW_SSI_SSI_SACCEN_CLR(x, v)    (HW_SSI_SSI_SACCEN_WR(x, HW_SSI_SSI_SACCEN_RD(x) & ~(v)))
#define HW_SSI_SSI_SACCEN_TOG(x, v)    (HW_SSI_SSI_SACCEN_WR(x, HW_SSI_SSI_SACCEN_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACCEN bitfields
 */

/* --- Register HW_SSI_SSI_SACCEN, field SACCEN */

#define BP_SSI_SSI_SACCEN_SACCEN      0
#define BM_SSI_SSI_SACCEN_SACCEN      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACCEN_SACCEN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACCEN_SACCEN)
#else
#define BF_SSI_SSI_SACCEN_SACCEN(v)   (((v) << 0) & BM_SSI_SSI_SACCEN_SACCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACCEN_SACCEN(v)   BF_CS1(SSI_SSI_SACCEN, SACCEN, v)
#endif

/*
 * HW_SSI_SSI_SACCDIS - SSI AC97 Channel Disable Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 22;
        unsigned SACCDIS : 10;

    } B;
} hw_ssi_ssi_saccdis_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACCDIS register
 */
#define HW_SSI_SSI_SACCDIS_ADDR(x)      (REGS_SSI_BASE(x) + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACCDIS(x)           (*(volatile hw_ssi_ssi_saccdis_t *) HW_SSI_SSI_SACCDIS_ADDR(x))
#define HW_SSI_SSI_SACCDIS_RD(x)        (HW_SSI_SSI_SACCDIS(x).U)
#define HW_SSI_SSI_SACCDIS_WR(x, v)     (HW_SSI_SSI_SACCDIS(x).U = (v))
#define HW_SSI_SSI_SACCDIS_SET(x, v)    (HW_SSI_SSI_SACCDIS_WR(x, HW_SSI_SSI_SACCDIS_RD(x) |  (v)))
#define HW_SSI_SSI_SACCDIS_CLR(x, v)    (HW_SSI_SSI_SACCDIS_WR(x, HW_SSI_SSI_SACCDIS_RD(x) & ~(v)))
#define HW_SSI_SSI_SACCDIS_TOG(x, v)    (HW_SSI_SSI_SACCDIS_WR(x, HW_SSI_SSI_SACCDIS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACCDIS bitfields
 */

/* --- Register HW_SSI_SSI_SACCDIS, field SACCDIS */

#define BP_SSI_SSI_SACCDIS_SACCDIS      0
#define BM_SSI_SSI_SACCDIS_SACCDIS      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACCDIS_SACCDIS(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACCDIS_SACCDIS)
#else
#define BF_SSI_SSI_SACCDIS_SACCDIS(v)   (((v) << 0) & BM_SSI_SSI_SACCDIS_SACCDIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACCDIS_SACCDIS(v)   BF_CS1(SSI_SSI_SACCDIS, SACCDIS, v)
#endif

/*
 * HW_SSI_SSI_PHCONFIG - SSI Phase Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 21;
        unsigned CLKSRCSEL : 4;
        unsigned LOCK : 1;
        unsigned RESERVED1 : 3;
        unsigned GAINSEL : 3;

    } B;
} hw_ssi_ssi_phconfig_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_PHCONFIG register
 */
#define HW_SSI_SSI_PHCONFIG_ADDR(x)      (REGS_SSI_BASE(x) + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_PHCONFIG(x)           (*(volatile hw_ssi_ssi_phconfig_t *) HW_SSI_SSI_PHCONFIG_ADDR(x))
#define HW_SSI_SSI_PHCONFIG_RD(x)        (HW_SSI_SSI_PHCONFIG(x).U)
#define HW_SSI_SSI_PHCONFIG_WR(x, v)     (HW_SSI_SSI_PHCONFIG(x).U = (v))
#define HW_SSI_SSI_PHCONFIG_SET(x, v)    (HW_SSI_SSI_PHCONFIG_WR(x, HW_SSI_SSI_PHCONFIG_RD(x) |  (v)))
#define HW_SSI_SSI_PHCONFIG_CLR(x, v)    (HW_SSI_SSI_PHCONFIG_WR(x, HW_SSI_SSI_PHCONFIG_RD(x) & ~(v)))
#define HW_SSI_SSI_PHCONFIG_TOG(x, v)    (HW_SSI_SSI_PHCONFIG_WR(x, HW_SSI_SSI_PHCONFIG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_PHCONFIG bitfields
 */

/* --- Register HW_SSI_SSI_PHCONFIG, field CLKSRCSEL */

#define BP_SSI_SSI_PHCONFIG_CLKSRCSEL      7
#define BM_SSI_SSI_PHCONFIG_CLKSRCSEL      0x00000780

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_PHCONFIG_CLKSRCSEL(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_PHCONFIG_CLKSRCSEL)
#else
#define BF_SSI_SSI_PHCONFIG_CLKSRCSEL(v)   (((v) << 7) & BM_SSI_SSI_PHCONFIG_CLKSRCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_PHCONFIG_CLKSRCSEL(v)   BF_CS1(SSI_SSI_PHCONFIG, CLKSRCSEL, v)
#endif

/* --- Register HW_SSI_SSI_PHCONFIG, field LOCK */

#define BP_SSI_SSI_PHCONFIG_LOCK      6
#define BM_SSI_SSI_PHCONFIG_LOCK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_PHCONFIG_LOCK(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_PHCONFIG_LOCK)
#else
#define BF_SSI_SSI_PHCONFIG_LOCK(v)   (((v) << 6) & BM_SSI_SSI_PHCONFIG_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_PHCONFIG_LOCK(v)   BF_CS1(SSI_SSI_PHCONFIG, LOCK, v)
#endif

/* --- Register HW_SSI_SSI_PHCONFIG, field GAINSEL */

#define BP_SSI_SSI_PHCONFIG_GAINSEL      0
#define BM_SSI_SSI_PHCONFIG_GAINSEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_PHCONFIG_GAINSEL(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_PHCONFIG_GAINSEL)
#else
#define BF_SSI_SSI_PHCONFIG_GAINSEL(v)   (((v) << 0) & BM_SSI_SSI_PHCONFIG_GAINSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_PHCONFIG_GAINSEL(v)   BF_CS1(SSI_SSI_PHCONFIG, GAINSEL, v)
#endif

/*
 * HW_SSI_FREQMEAS - SSI Frequency Measurement Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned FREQMEAS : 24;

    } B;
} hw_ssi_freqmeas_t;
#endif

/*
 * constants & macros for entire multi-block SSI_FREQMEAS register
 */
#define HW_SSI_FREQMEAS_ADDR(x)      (REGS_SSI_BASE(x) + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_FREQMEAS(x)           (*(volatile hw_ssi_freqmeas_t *) HW_SSI_FREQMEAS_ADDR(x))
#define HW_SSI_FREQMEAS_RD(x)        (HW_SSI_FREQMEAS(x).U)
#define HW_SSI_FREQMEAS_WR(x, v)     (HW_SSI_FREQMEAS(x).U = (v))
#define HW_SSI_FREQMEAS_SET(x, v)    (HW_SSI_FREQMEAS_WR(x, HW_SSI_FREQMEAS_RD(x) |  (v)))
#define HW_SSI_FREQMEAS_CLR(x, v)    (HW_SSI_FREQMEAS_WR(x, HW_SSI_FREQMEAS_RD(x) & ~(v)))
#define HW_SSI_FREQMEAS_TOG(x, v)    (HW_SSI_FREQMEAS_WR(x, HW_SSI_FREQMEAS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_FREQMEAS bitfields
 */

/* --- Register HW_SSI_FREQMEAS, field FREQMEAS */

#define BP_SSI_FREQMEAS_FREQMEAS      0
#define BM_SSI_FREQMEAS_FREQMEAS      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_FREQMEAS_FREQMEAS(v)   ((((reg32_t) v) << 0) & BM_SSI_FREQMEAS_FREQMEAS)
#else
#define BF_SSI_FREQMEAS_FREQMEAS(v)   (((v) << 0) & BM_SSI_FREQMEAS_FREQMEAS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_FREQMEAS_FREQMEAS(v)   BF_CS1(SSI_FREQMEAS, FREQMEAS, v)
#endif


#endif // _SSI_H

