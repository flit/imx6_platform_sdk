/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _UARTV2_H
#define _UARTV2_H

#include "regs.h"

#ifndef REGS_UARTV2_BASE
#define REGS_UARTV20_BASE (REGS_BASE + 0x02020000)
#define REGS_UARTV21_BASE (REGS_BASE + 0x021e8000)
#define REGS_UARTV22_BASE (REGS_BASE + 0x021ec000)
#define REGS_UARTV23_BASE (REGS_BASE + 0x021f0000)
#define REGS_UARTV24_BASE (REGS_BASE + 0x021f4000)
#define REGS_UARTV2_BASE(x) ( x == 0 ? REGS_UARTV20_BASE : x == 1 ? REGS_UARTV21_BASE : x == 2 ? REGS_UARTV22_BASE : x == 3 ? REGS_UARTV23_BASE : x == 4 ? REGS_UARTV24_BASE : 0xffff0000)

#endif


/*
 * HW_UARTV2_URXD - UART Receiver Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned CHARRDY : 1;
        unsigned ERR : 1;
        unsigned OVRRUN : 1;
        unsigned FRMERR : 1;
        unsigned BRK : 1;
        unsigned PRERR : 1;
        unsigned RESERVED1 : 2;
        unsigned RX_DATA : 8;

    } B;
} hw_uartv2_urxd_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_URXD register
 */
#define HW_UARTV2_URXD_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_URXD(x)           (*(volatile hw_uartv2_urxd_t *) HW_UARTV2_URXD_ADDR(x))
#define HW_UARTV2_URXD_RD(x)        (HW_UARTV2_URXD(x).U)
#define HW_UARTV2_URXD_WR(x, v)     (HW_UARTV2_URXD(x).U = (v))
#define HW_UARTV2_URXD_SET(x, v)    (HW_UARTV2_URXD_WR(x, HW_UARTV2_URXD_RD(x) |  (v)))
#define HW_UARTV2_URXD_CLR(x, v)    (HW_UARTV2_URXD_WR(x, HW_UARTV2_URXD_RD(x) & ~(v)))
#define HW_UARTV2_URXD_TOG(x, v)    (HW_UARTV2_URXD_WR(x, HW_UARTV2_URXD_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_URXD bitfields
 */

/* --- Register HW_UARTV2_URXD, field CHARRDY */

#define BP_UARTV2_URXD_CHARRDY      15
#define BM_UARTV2_URXD_CHARRDY      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_URXD_CHARRDY(v)   ((((reg32_t) v) << 15) & BM_UARTV2_URXD_CHARRDY)
#else
#define BF_UARTV2_URXD_CHARRDY(v)   (((v) << 15) & BM_UARTV2_URXD_CHARRDY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_URXD_CHARRDY(v)   BF_CS1(UARTV2_URXD, CHARRDY, v)
#endif

/* --- Register HW_UARTV2_URXD, field ERR */

#define BP_UARTV2_URXD_ERR      14
#define BM_UARTV2_URXD_ERR      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_URXD_ERR(v)   ((((reg32_t) v) << 14) & BM_UARTV2_URXD_ERR)
#else
#define BF_UARTV2_URXD_ERR(v)   (((v) << 14) & BM_UARTV2_URXD_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_URXD_ERR(v)   BF_CS1(UARTV2_URXD, ERR, v)
#endif

/* --- Register HW_UARTV2_URXD, field OVRRUN */

#define BP_UARTV2_URXD_OVRRUN      13
#define BM_UARTV2_URXD_OVRRUN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_URXD_OVRRUN(v)   ((((reg32_t) v) << 13) & BM_UARTV2_URXD_OVRRUN)
#else
#define BF_UARTV2_URXD_OVRRUN(v)   (((v) << 13) & BM_UARTV2_URXD_OVRRUN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_URXD_OVRRUN(v)   BF_CS1(UARTV2_URXD, OVRRUN, v)
#endif

/* --- Register HW_UARTV2_URXD, field FRMERR */

#define BP_UARTV2_URXD_FRMERR      12
#define BM_UARTV2_URXD_FRMERR      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_URXD_FRMERR(v)   ((((reg32_t) v) << 12) & BM_UARTV2_URXD_FRMERR)
#else
#define BF_UARTV2_URXD_FRMERR(v)   (((v) << 12) & BM_UARTV2_URXD_FRMERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_URXD_FRMERR(v)   BF_CS1(UARTV2_URXD, FRMERR, v)
#endif

/* --- Register HW_UARTV2_URXD, field BRK */

#define BP_UARTV2_URXD_BRK      11
#define BM_UARTV2_URXD_BRK      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_URXD_BRK(v)   ((((reg32_t) v) << 11) & BM_UARTV2_URXD_BRK)
#else
#define BF_UARTV2_URXD_BRK(v)   (((v) << 11) & BM_UARTV2_URXD_BRK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_URXD_BRK(v)   BF_CS1(UARTV2_URXD, BRK, v)
#endif

/* --- Register HW_UARTV2_URXD, field PRERR */

#define BP_UARTV2_URXD_PRERR      10
#define BM_UARTV2_URXD_PRERR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_URXD_PRERR(v)   ((((reg32_t) v) << 10) & BM_UARTV2_URXD_PRERR)
#else
#define BF_UARTV2_URXD_PRERR(v)   (((v) << 10) & BM_UARTV2_URXD_PRERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_URXD_PRERR(v)   BF_CS1(UARTV2_URXD, PRERR, v)
#endif

/* --- Register HW_UARTV2_URXD, field RX_DATA */

#define BP_UARTV2_URXD_RX_DATA      0
#define BM_UARTV2_URXD_RX_DATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_URXD_RX_DATA(v)   ((((reg32_t) v) << 0) & BM_UARTV2_URXD_RX_DATA)
#else
#define BF_UARTV2_URXD_RX_DATA(v)   (((v) << 0) & BM_UARTV2_URXD_RX_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_URXD_RX_DATA(v)   BF_CS1(UARTV2_URXD, RX_DATA, v)
#endif

/*
 * HW_UARTV2_UTXD - UART Transmitter Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RESERVED1 : 8;
        unsigned TX_DATA : 8;

    } B;
} hw_uartv2_utxd_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UTXD register
 */
#define HW_UARTV2_UTXD_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UTXD(x)           (*(volatile hw_uartv2_utxd_t *) HW_UARTV2_UTXD_ADDR(x))
#define HW_UARTV2_UTXD_RD(x)        (HW_UARTV2_UTXD(x).U)
#define HW_UARTV2_UTXD_WR(x, v)     (HW_UARTV2_UTXD(x).U = (v))
#define HW_UARTV2_UTXD_SET(x, v)    (HW_UARTV2_UTXD_WR(x, HW_UARTV2_UTXD_RD(x) |  (v)))
#define HW_UARTV2_UTXD_CLR(x, v)    (HW_UARTV2_UTXD_WR(x, HW_UARTV2_UTXD_RD(x) & ~(v)))
#define HW_UARTV2_UTXD_TOG(x, v)    (HW_UARTV2_UTXD_WR(x, HW_UARTV2_UTXD_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UTXD bitfields
 */

/* --- Register HW_UARTV2_UTXD, field TX_DATA */

#define BP_UARTV2_UTXD_TX_DATA      0
#define BM_UARTV2_UTXD_TX_DATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTXD_TX_DATA(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UTXD_TX_DATA)
#else
#define BF_UARTV2_UTXD_TX_DATA(v)   (((v) << 0) & BM_UARTV2_UTXD_TX_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTXD_TX_DATA(v)   BF_CS1(UARTV2_UTXD, TX_DATA, v)
#endif

/*
 * HW_UARTV2_UCR1 - UART Control Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned ADEN : 1;
        unsigned ADBR : 1;
        unsigned TRDYEN : 1;
        unsigned IDEN : 1;
        unsigned ICD : 2;
        unsigned RRDYEN : 1;
        unsigned RXDMAEN : 1;
        unsigned IREN : 1;
        unsigned TXMPTYEN : 1;
        unsigned RTSDEN : 1;
        unsigned SNDBRK : 1;
        unsigned TXDMAEN : 1;
        unsigned ATDMAEN : 1;
        unsigned DOZE : 1;
        unsigned UARTEN : 1;

    } B;
} hw_uartv2_ucr1_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UCR1 register
 */
#define HW_UARTV2_UCR1_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UCR1(x)           (*(volatile hw_uartv2_ucr1_t *) HW_UARTV2_UCR1_ADDR(x))
#define HW_UARTV2_UCR1_RD(x)        (HW_UARTV2_UCR1(x).U)
#define HW_UARTV2_UCR1_WR(x, v)     (HW_UARTV2_UCR1(x).U = (v))
#define HW_UARTV2_UCR1_SET(x, v)    (HW_UARTV2_UCR1_WR(x, HW_UARTV2_UCR1_RD(x) |  (v)))
#define HW_UARTV2_UCR1_CLR(x, v)    (HW_UARTV2_UCR1_WR(x, HW_UARTV2_UCR1_RD(x) & ~(v)))
#define HW_UARTV2_UCR1_TOG(x, v)    (HW_UARTV2_UCR1_WR(x, HW_UARTV2_UCR1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UCR1 bitfields
 */

/* --- Register HW_UARTV2_UCR1, field ADEN */

#define BP_UARTV2_UCR1_ADEN      15
#define BM_UARTV2_UCR1_ADEN      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_ADEN(v)   ((((reg32_t) v) << 15) & BM_UARTV2_UCR1_ADEN)
#else
#define BF_UARTV2_UCR1_ADEN(v)   (((v) << 15) & BM_UARTV2_UCR1_ADEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_ADEN(v)   BF_CS1(UARTV2_UCR1, ADEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field ADBR */

#define BP_UARTV2_UCR1_ADBR      14
#define BM_UARTV2_UCR1_ADBR      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_ADBR(v)   ((((reg32_t) v) << 14) & BM_UARTV2_UCR1_ADBR)
#else
#define BF_UARTV2_UCR1_ADBR(v)   (((v) << 14) & BM_UARTV2_UCR1_ADBR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_ADBR(v)   BF_CS1(UARTV2_UCR1, ADBR, v)
#endif

/* --- Register HW_UARTV2_UCR1, field TRDYEN */

#define BP_UARTV2_UCR1_TRDYEN      13
#define BM_UARTV2_UCR1_TRDYEN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_TRDYEN(v)   ((((reg32_t) v) << 13) & BM_UARTV2_UCR1_TRDYEN)
#else
#define BF_UARTV2_UCR1_TRDYEN(v)   (((v) << 13) & BM_UARTV2_UCR1_TRDYEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_TRDYEN(v)   BF_CS1(UARTV2_UCR1, TRDYEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field IDEN */

#define BP_UARTV2_UCR1_IDEN      12
#define BM_UARTV2_UCR1_IDEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_IDEN(v)   ((((reg32_t) v) << 12) & BM_UARTV2_UCR1_IDEN)
#else
#define BF_UARTV2_UCR1_IDEN(v)   (((v) << 12) & BM_UARTV2_UCR1_IDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_IDEN(v)   BF_CS1(UARTV2_UCR1, IDEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field ICD */

#define BP_UARTV2_UCR1_ICD      10
#define BM_UARTV2_UCR1_ICD      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_ICD(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UCR1_ICD)
#else
#define BF_UARTV2_UCR1_ICD(v)   (((v) << 10) & BM_UARTV2_UCR1_ICD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_ICD(v)   BF_CS1(UARTV2_UCR1, ICD, v)
#endif

/* --- Register HW_UARTV2_UCR1, field RRDYEN */

#define BP_UARTV2_UCR1_RRDYEN      9
#define BM_UARTV2_UCR1_RRDYEN      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_RRDYEN(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UCR1_RRDYEN)
#else
#define BF_UARTV2_UCR1_RRDYEN(v)   (((v) << 9) & BM_UARTV2_UCR1_RRDYEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_RRDYEN(v)   BF_CS1(UARTV2_UCR1, RRDYEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field RXDMAEN */

#define BP_UARTV2_UCR1_RXDMAEN      8
#define BM_UARTV2_UCR1_RXDMAEN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_RXDMAEN(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UCR1_RXDMAEN)
#else
#define BF_UARTV2_UCR1_RXDMAEN(v)   (((v) << 8) & BM_UARTV2_UCR1_RXDMAEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_RXDMAEN(v)   BF_CS1(UARTV2_UCR1, RXDMAEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field IREN */

#define BP_UARTV2_UCR1_IREN      7
#define BM_UARTV2_UCR1_IREN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_IREN(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UCR1_IREN)
#else
#define BF_UARTV2_UCR1_IREN(v)   (((v) << 7) & BM_UARTV2_UCR1_IREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_IREN(v)   BF_CS1(UARTV2_UCR1, IREN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field TXMPTYEN */

#define BP_UARTV2_UCR1_TXMPTYEN      6
#define BM_UARTV2_UCR1_TXMPTYEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_TXMPTYEN(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UCR1_TXMPTYEN)
#else
#define BF_UARTV2_UCR1_TXMPTYEN(v)   (((v) << 6) & BM_UARTV2_UCR1_TXMPTYEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_TXMPTYEN(v)   BF_CS1(UARTV2_UCR1, TXMPTYEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field RTSDEN */

#define BP_UARTV2_UCR1_RTSDEN      5
#define BM_UARTV2_UCR1_RTSDEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_RTSDEN(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UCR1_RTSDEN)
#else
#define BF_UARTV2_UCR1_RTSDEN(v)   (((v) << 5) & BM_UARTV2_UCR1_RTSDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_RTSDEN(v)   BF_CS1(UARTV2_UCR1, RTSDEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field SNDBRK */

#define BP_UARTV2_UCR1_SNDBRK      4
#define BM_UARTV2_UCR1_SNDBRK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_SNDBRK(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UCR1_SNDBRK)
#else
#define BF_UARTV2_UCR1_SNDBRK(v)   (((v) << 4) & BM_UARTV2_UCR1_SNDBRK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_SNDBRK(v)   BF_CS1(UARTV2_UCR1, SNDBRK, v)
#endif

/* --- Register HW_UARTV2_UCR1, field TXDMAEN */

#define BP_UARTV2_UCR1_TXDMAEN      3
#define BM_UARTV2_UCR1_TXDMAEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_TXDMAEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UCR1_TXDMAEN)
#else
#define BF_UARTV2_UCR1_TXDMAEN(v)   (((v) << 3) & BM_UARTV2_UCR1_TXDMAEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_TXDMAEN(v)   BF_CS1(UARTV2_UCR1, TXDMAEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field ATDMAEN */

#define BP_UARTV2_UCR1_ATDMAEN      2
#define BM_UARTV2_UCR1_ATDMAEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_ATDMAEN(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UCR1_ATDMAEN)
#else
#define BF_UARTV2_UCR1_ATDMAEN(v)   (((v) << 2) & BM_UARTV2_UCR1_ATDMAEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_ATDMAEN(v)   BF_CS1(UARTV2_UCR1, ATDMAEN, v)
#endif

/* --- Register HW_UARTV2_UCR1, field DOZE */

#define BP_UARTV2_UCR1_DOZE      1
#define BM_UARTV2_UCR1_DOZE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_DOZE(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UCR1_DOZE)
#else
#define BF_UARTV2_UCR1_DOZE(v)   (((v) << 1) & BM_UARTV2_UCR1_DOZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_DOZE(v)   BF_CS1(UARTV2_UCR1, DOZE, v)
#endif

/* --- Register HW_UARTV2_UCR1, field UARTEN */

#define BP_UARTV2_UCR1_UARTEN      0
#define BM_UARTV2_UCR1_UARTEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_UARTEN(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UCR1_UARTEN)
#else
#define BF_UARTV2_UCR1_UARTEN(v)   (((v) << 0) & BM_UARTV2_UCR1_UARTEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR1_UARTEN(v)   BF_CS1(UARTV2_UCR1, UARTEN, v)
#endif

/*
 * HW_UARTV2_UCR2 - UART Control Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned ESCI : 1;
        unsigned IRTS : 1;
        unsigned CTSC : 1;
        unsigned CTS : 1;
        unsigned ESCEN : 1;
        unsigned RTEC : 2;
        unsigned PREN : 1;
        unsigned PROE : 1;
        unsigned STPB : 1;
        unsigned WS : 1;
        unsigned RTSEN : 1;
        unsigned ATEN : 1;
        unsigned TXEN : 1;
        unsigned RXEN : 1;
        unsigned SRST : 1;

    } B;
} hw_uartv2_ucr2_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UCR2 register
 */
#define HW_UARTV2_UCR2_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UCR2(x)           (*(volatile hw_uartv2_ucr2_t *) HW_UARTV2_UCR2_ADDR(x))
#define HW_UARTV2_UCR2_RD(x)        (HW_UARTV2_UCR2(x).U)
#define HW_UARTV2_UCR2_WR(x, v)     (HW_UARTV2_UCR2(x).U = (v))
#define HW_UARTV2_UCR2_SET(x, v)    (HW_UARTV2_UCR2_WR(x, HW_UARTV2_UCR2_RD(x) |  (v)))
#define HW_UARTV2_UCR2_CLR(x, v)    (HW_UARTV2_UCR2_WR(x, HW_UARTV2_UCR2_RD(x) & ~(v)))
#define HW_UARTV2_UCR2_TOG(x, v)    (HW_UARTV2_UCR2_WR(x, HW_UARTV2_UCR2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UCR2 bitfields
 */

/* --- Register HW_UARTV2_UCR2, field ESCI */

#define BP_UARTV2_UCR2_ESCI      15
#define BM_UARTV2_UCR2_ESCI      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_ESCI(v)   ((((reg32_t) v) << 15) & BM_UARTV2_UCR2_ESCI)
#else
#define BF_UARTV2_UCR2_ESCI(v)   (((v) << 15) & BM_UARTV2_UCR2_ESCI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_ESCI(v)   BF_CS1(UARTV2_UCR2, ESCI, v)
#endif

/* --- Register HW_UARTV2_UCR2, field IRTS */

#define BP_UARTV2_UCR2_IRTS      14
#define BM_UARTV2_UCR2_IRTS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_IRTS(v)   ((((reg32_t) v) << 14) & BM_UARTV2_UCR2_IRTS)
#else
#define BF_UARTV2_UCR2_IRTS(v)   (((v) << 14) & BM_UARTV2_UCR2_IRTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_IRTS(v)   BF_CS1(UARTV2_UCR2, IRTS, v)
#endif

/* --- Register HW_UARTV2_UCR2, field CTSC */

#define BP_UARTV2_UCR2_CTSC      13
#define BM_UARTV2_UCR2_CTSC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_CTSC(v)   ((((reg32_t) v) << 13) & BM_UARTV2_UCR2_CTSC)
#else
#define BF_UARTV2_UCR2_CTSC(v)   (((v) << 13) & BM_UARTV2_UCR2_CTSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_CTSC(v)   BF_CS1(UARTV2_UCR2, CTSC, v)
#endif

/* --- Register HW_UARTV2_UCR2, field CTS */

#define BP_UARTV2_UCR2_CTS      12
#define BM_UARTV2_UCR2_CTS      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_CTS(v)   ((((reg32_t) v) << 12) & BM_UARTV2_UCR2_CTS)
#else
#define BF_UARTV2_UCR2_CTS(v)   (((v) << 12) & BM_UARTV2_UCR2_CTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_CTS(v)   BF_CS1(UARTV2_UCR2, CTS, v)
#endif

/* --- Register HW_UARTV2_UCR2, field ESCEN */

#define BP_UARTV2_UCR2_ESCEN      11
#define BM_UARTV2_UCR2_ESCEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_ESCEN(v)   ((((reg32_t) v) << 11) & BM_UARTV2_UCR2_ESCEN)
#else
#define BF_UARTV2_UCR2_ESCEN(v)   (((v) << 11) & BM_UARTV2_UCR2_ESCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_ESCEN(v)   BF_CS1(UARTV2_UCR2, ESCEN, v)
#endif

/* --- Register HW_UARTV2_UCR2, field RTEC */

#define BP_UARTV2_UCR2_RTEC      9
#define BM_UARTV2_UCR2_RTEC      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_RTEC(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UCR2_RTEC)
#else
#define BF_UARTV2_UCR2_RTEC(v)   (((v) << 9) & BM_UARTV2_UCR2_RTEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_RTEC(v)   BF_CS1(UARTV2_UCR2, RTEC, v)
#endif

/* --- Register HW_UARTV2_UCR2, field PREN */

#define BP_UARTV2_UCR2_PREN      8
#define BM_UARTV2_UCR2_PREN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_PREN(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UCR2_PREN)
#else
#define BF_UARTV2_UCR2_PREN(v)   (((v) << 8) & BM_UARTV2_UCR2_PREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_PREN(v)   BF_CS1(UARTV2_UCR2, PREN, v)
#endif

/* --- Register HW_UARTV2_UCR2, field PROE */

#define BP_UARTV2_UCR2_PROE      7
#define BM_UARTV2_UCR2_PROE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_PROE(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UCR2_PROE)
#else
#define BF_UARTV2_UCR2_PROE(v)   (((v) << 7) & BM_UARTV2_UCR2_PROE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_PROE(v)   BF_CS1(UARTV2_UCR2, PROE, v)
#endif

/* --- Register HW_UARTV2_UCR2, field STPB */

#define BP_UARTV2_UCR2_STPB      6
#define BM_UARTV2_UCR2_STPB      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_STPB(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UCR2_STPB)
#else
#define BF_UARTV2_UCR2_STPB(v)   (((v) << 6) & BM_UARTV2_UCR2_STPB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_STPB(v)   BF_CS1(UARTV2_UCR2, STPB, v)
#endif

/* --- Register HW_UARTV2_UCR2, field WS */

#define BP_UARTV2_UCR2_WS      5
#define BM_UARTV2_UCR2_WS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_WS(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UCR2_WS)
#else
#define BF_UARTV2_UCR2_WS(v)   (((v) << 5) & BM_UARTV2_UCR2_WS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_WS(v)   BF_CS1(UARTV2_UCR2, WS, v)
#endif

/* --- Register HW_UARTV2_UCR2, field RTSEN */

#define BP_UARTV2_UCR2_RTSEN      4
#define BM_UARTV2_UCR2_RTSEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_RTSEN(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UCR2_RTSEN)
#else
#define BF_UARTV2_UCR2_RTSEN(v)   (((v) << 4) & BM_UARTV2_UCR2_RTSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_RTSEN(v)   BF_CS1(UARTV2_UCR2, RTSEN, v)
#endif

/* --- Register HW_UARTV2_UCR2, field ATEN */

#define BP_UARTV2_UCR2_ATEN      3
#define BM_UARTV2_UCR2_ATEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_ATEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UCR2_ATEN)
#else
#define BF_UARTV2_UCR2_ATEN(v)   (((v) << 3) & BM_UARTV2_UCR2_ATEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_ATEN(v)   BF_CS1(UARTV2_UCR2, ATEN, v)
#endif

/* --- Register HW_UARTV2_UCR2, field TXEN */

#define BP_UARTV2_UCR2_TXEN      2
#define BM_UARTV2_UCR2_TXEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_TXEN(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UCR2_TXEN)
#else
#define BF_UARTV2_UCR2_TXEN(v)   (((v) << 2) & BM_UARTV2_UCR2_TXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_TXEN(v)   BF_CS1(UARTV2_UCR2, TXEN, v)
#endif

/* --- Register HW_UARTV2_UCR2, field RXEN */

#define BP_UARTV2_UCR2_RXEN      1
#define BM_UARTV2_UCR2_RXEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_RXEN(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UCR2_RXEN)
#else
#define BF_UARTV2_UCR2_RXEN(v)   (((v) << 1) & BM_UARTV2_UCR2_RXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_RXEN(v)   BF_CS1(UARTV2_UCR2, RXEN, v)
#endif

/* --- Register HW_UARTV2_UCR2, field SRST */

#define BP_UARTV2_UCR2_SRST      0
#define BM_UARTV2_UCR2_SRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_SRST(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UCR2_SRST)
#else
#define BF_UARTV2_UCR2_SRST(v)   (((v) << 0) & BM_UARTV2_UCR2_SRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR2_SRST(v)   BF_CS1(UARTV2_UCR2, SRST, v)
#endif

/*
 * HW_UARTV2_UCR3 - UART Control Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned DPEC : 2;
        unsigned DTREN : 1;
        unsigned PARERREN : 1;
        unsigned FRAERREN : 1;
        unsigned DSR : 1;
        unsigned DCD : 1;
        unsigned RI : 1;
        unsigned ADNIMP : 1;
        unsigned RXDSEN : 1;
        unsigned AIRINTEN : 1;
        unsigned AWAKEN : 1;
        unsigned DTRDEN : 1;
        unsigned RXDMUXSEL : 1;
        unsigned INVT : 1;
        unsigned ACIEN : 1;

    } B;
} hw_uartv2_ucr3_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UCR3 register
 */
#define HW_UARTV2_UCR3_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UCR3(x)           (*(volatile hw_uartv2_ucr3_t *) HW_UARTV2_UCR3_ADDR(x))
#define HW_UARTV2_UCR3_RD(x)        (HW_UARTV2_UCR3(x).U)
#define HW_UARTV2_UCR3_WR(x, v)     (HW_UARTV2_UCR3(x).U = (v))
#define HW_UARTV2_UCR3_SET(x, v)    (HW_UARTV2_UCR3_WR(x, HW_UARTV2_UCR3_RD(x) |  (v)))
#define HW_UARTV2_UCR3_CLR(x, v)    (HW_UARTV2_UCR3_WR(x, HW_UARTV2_UCR3_RD(x) & ~(v)))
#define HW_UARTV2_UCR3_TOG(x, v)    (HW_UARTV2_UCR3_WR(x, HW_UARTV2_UCR3_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UCR3 bitfields
 */

/* --- Register HW_UARTV2_UCR3, field DPEC */

#define BP_UARTV2_UCR3_DPEC      14
#define BM_UARTV2_UCR3_DPEC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DPEC(v)   ((((reg32_t) v) << 14) & BM_UARTV2_UCR3_DPEC)
#else
#define BF_UARTV2_UCR3_DPEC(v)   (((v) << 14) & BM_UARTV2_UCR3_DPEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_DPEC(v)   BF_CS1(UARTV2_UCR3, DPEC, v)
#endif

/* --- Register HW_UARTV2_UCR3, field DTREN */

#define BP_UARTV2_UCR3_DTREN      13
#define BM_UARTV2_UCR3_DTREN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DTREN(v)   ((((reg32_t) v) << 13) & BM_UARTV2_UCR3_DTREN)
#else
#define BF_UARTV2_UCR3_DTREN(v)   (((v) << 13) & BM_UARTV2_UCR3_DTREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_DTREN(v)   BF_CS1(UARTV2_UCR3, DTREN, v)
#endif

/* --- Register HW_UARTV2_UCR3, field PARERREN */

#define BP_UARTV2_UCR3_PARERREN      12
#define BM_UARTV2_UCR3_PARERREN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_PARERREN(v)   ((((reg32_t) v) << 12) & BM_UARTV2_UCR3_PARERREN)
#else
#define BF_UARTV2_UCR3_PARERREN(v)   (((v) << 12) & BM_UARTV2_UCR3_PARERREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_PARERREN(v)   BF_CS1(UARTV2_UCR3, PARERREN, v)
#endif

/* --- Register HW_UARTV2_UCR3, field FRAERREN */

#define BP_UARTV2_UCR3_FRAERREN      11
#define BM_UARTV2_UCR3_FRAERREN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_FRAERREN(v)   ((((reg32_t) v) << 11) & BM_UARTV2_UCR3_FRAERREN)
#else
#define BF_UARTV2_UCR3_FRAERREN(v)   (((v) << 11) & BM_UARTV2_UCR3_FRAERREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_FRAERREN(v)   BF_CS1(UARTV2_UCR3, FRAERREN, v)
#endif

/* --- Register HW_UARTV2_UCR3, field DSR */

#define BP_UARTV2_UCR3_DSR      10
#define BM_UARTV2_UCR3_DSR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DSR(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UCR3_DSR)
#else
#define BF_UARTV2_UCR3_DSR(v)   (((v) << 10) & BM_UARTV2_UCR3_DSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_DSR(v)   BF_CS1(UARTV2_UCR3, DSR, v)
#endif

/* --- Register HW_UARTV2_UCR3, field DCD */

#define BP_UARTV2_UCR3_DCD      9
#define BM_UARTV2_UCR3_DCD      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DCD(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UCR3_DCD)
#else
#define BF_UARTV2_UCR3_DCD(v)   (((v) << 9) & BM_UARTV2_UCR3_DCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_DCD(v)   BF_CS1(UARTV2_UCR3, DCD, v)
#endif

/* --- Register HW_UARTV2_UCR3, field RI */

#define BP_UARTV2_UCR3_RI      8
#define BM_UARTV2_UCR3_RI      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_RI(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UCR3_RI)
#else
#define BF_UARTV2_UCR3_RI(v)   (((v) << 8) & BM_UARTV2_UCR3_RI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_RI(v)   BF_CS1(UARTV2_UCR3, RI, v)
#endif

/* --- Register HW_UARTV2_UCR3, field ADNIMP */

#define BP_UARTV2_UCR3_ADNIMP      7
#define BM_UARTV2_UCR3_ADNIMP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_ADNIMP(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UCR3_ADNIMP)
#else
#define BF_UARTV2_UCR3_ADNIMP(v)   (((v) << 7) & BM_UARTV2_UCR3_ADNIMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_ADNIMP(v)   BF_CS1(UARTV2_UCR3, ADNIMP, v)
#endif

/* --- Register HW_UARTV2_UCR3, field RXDSEN */

#define BP_UARTV2_UCR3_RXDSEN      6
#define BM_UARTV2_UCR3_RXDSEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_RXDSEN(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UCR3_RXDSEN)
#else
#define BF_UARTV2_UCR3_RXDSEN(v)   (((v) << 6) & BM_UARTV2_UCR3_RXDSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_RXDSEN(v)   BF_CS1(UARTV2_UCR3, RXDSEN, v)
#endif

/* --- Register HW_UARTV2_UCR3, field AIRINTEN */

#define BP_UARTV2_UCR3_AIRINTEN      5
#define BM_UARTV2_UCR3_AIRINTEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_AIRINTEN(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UCR3_AIRINTEN)
#else
#define BF_UARTV2_UCR3_AIRINTEN(v)   (((v) << 5) & BM_UARTV2_UCR3_AIRINTEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_AIRINTEN(v)   BF_CS1(UARTV2_UCR3, AIRINTEN, v)
#endif

/* --- Register HW_UARTV2_UCR3, field AWAKEN */

#define BP_UARTV2_UCR3_AWAKEN      4
#define BM_UARTV2_UCR3_AWAKEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_AWAKEN(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UCR3_AWAKEN)
#else
#define BF_UARTV2_UCR3_AWAKEN(v)   (((v) << 4) & BM_UARTV2_UCR3_AWAKEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_AWAKEN(v)   BF_CS1(UARTV2_UCR3, AWAKEN, v)
#endif

/* --- Register HW_UARTV2_UCR3, field DTRDEN */

#define BP_UARTV2_UCR3_DTRDEN      3
#define BM_UARTV2_UCR3_DTRDEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DTRDEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UCR3_DTRDEN)
#else
#define BF_UARTV2_UCR3_DTRDEN(v)   (((v) << 3) & BM_UARTV2_UCR3_DTRDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_DTRDEN(v)   BF_CS1(UARTV2_UCR3, DTRDEN, v)
#endif

/* --- Register HW_UARTV2_UCR3, field RXDMUXSEL */

#define BP_UARTV2_UCR3_RXDMUXSEL      2
#define BM_UARTV2_UCR3_RXDMUXSEL      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_RXDMUXSEL(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UCR3_RXDMUXSEL)
#else
#define BF_UARTV2_UCR3_RXDMUXSEL(v)   (((v) << 2) & BM_UARTV2_UCR3_RXDMUXSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_RXDMUXSEL(v)   BF_CS1(UARTV2_UCR3, RXDMUXSEL, v)
#endif

/* --- Register HW_UARTV2_UCR3, field INVT */

#define BP_UARTV2_UCR3_INVT      1
#define BM_UARTV2_UCR3_INVT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_INVT(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UCR3_INVT)
#else
#define BF_UARTV2_UCR3_INVT(v)   (((v) << 1) & BM_UARTV2_UCR3_INVT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_INVT(v)   BF_CS1(UARTV2_UCR3, INVT, v)
#endif

/* --- Register HW_UARTV2_UCR3, field ACIEN */

#define BP_UARTV2_UCR3_ACIEN      0
#define BM_UARTV2_UCR3_ACIEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_ACIEN(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UCR3_ACIEN)
#else
#define BF_UARTV2_UCR3_ACIEN(v)   (((v) << 0) & BM_UARTV2_UCR3_ACIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR3_ACIEN(v)   BF_CS1(UARTV2_UCR3, ACIEN, v)
#endif

/*
 * HW_UARTV2_UCR4 - UART Control Register 4
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned CTSTL : 6;
        unsigned INVR : 1;
        unsigned ENIRI : 1;
        unsigned WKEN : 1;
        unsigned IDDMAEN : 1;
        unsigned IRSC : 1;
        unsigned LPBYP : 1;
        unsigned TCEN : 1;
        unsigned BKEN : 1;
        unsigned OREN : 1;
        unsigned DREN : 1;

    } B;
} hw_uartv2_ucr4_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UCR4 register
 */
#define HW_UARTV2_UCR4_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UCR4(x)           (*(volatile hw_uartv2_ucr4_t *) HW_UARTV2_UCR4_ADDR(x))
#define HW_UARTV2_UCR4_RD(x)        (HW_UARTV2_UCR4(x).U)
#define HW_UARTV2_UCR4_WR(x, v)     (HW_UARTV2_UCR4(x).U = (v))
#define HW_UARTV2_UCR4_SET(x, v)    (HW_UARTV2_UCR4_WR(x, HW_UARTV2_UCR4_RD(x) |  (v)))
#define HW_UARTV2_UCR4_CLR(x, v)    (HW_UARTV2_UCR4_WR(x, HW_UARTV2_UCR4_RD(x) & ~(v)))
#define HW_UARTV2_UCR4_TOG(x, v)    (HW_UARTV2_UCR4_WR(x, HW_UARTV2_UCR4_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UCR4 bitfields
 */

/* --- Register HW_UARTV2_UCR4, field CTSTL */

#define BP_UARTV2_UCR4_CTSTL      10
#define BM_UARTV2_UCR4_CTSTL      0x0000fc00

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_CTSTL(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UCR4_CTSTL)
#else
#define BF_UARTV2_UCR4_CTSTL(v)   (((v) << 10) & BM_UARTV2_UCR4_CTSTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_CTSTL(v)   BF_CS1(UARTV2_UCR4, CTSTL, v)
#endif

/* --- Register HW_UARTV2_UCR4, field INVR */

#define BP_UARTV2_UCR4_INVR      9
#define BM_UARTV2_UCR4_INVR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_INVR(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UCR4_INVR)
#else
#define BF_UARTV2_UCR4_INVR(v)   (((v) << 9) & BM_UARTV2_UCR4_INVR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_INVR(v)   BF_CS1(UARTV2_UCR4, INVR, v)
#endif

/* --- Register HW_UARTV2_UCR4, field ENIRI */

#define BP_UARTV2_UCR4_ENIRI      8
#define BM_UARTV2_UCR4_ENIRI      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_ENIRI(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UCR4_ENIRI)
#else
#define BF_UARTV2_UCR4_ENIRI(v)   (((v) << 8) & BM_UARTV2_UCR4_ENIRI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_ENIRI(v)   BF_CS1(UARTV2_UCR4, ENIRI, v)
#endif

/* --- Register HW_UARTV2_UCR4, field WKEN */

#define BP_UARTV2_UCR4_WKEN      7
#define BM_UARTV2_UCR4_WKEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_WKEN(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UCR4_WKEN)
#else
#define BF_UARTV2_UCR4_WKEN(v)   (((v) << 7) & BM_UARTV2_UCR4_WKEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_WKEN(v)   BF_CS1(UARTV2_UCR4, WKEN, v)
#endif

/* --- Register HW_UARTV2_UCR4, field IDDMAEN */

#define BP_UARTV2_UCR4_IDDMAEN      6
#define BM_UARTV2_UCR4_IDDMAEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_IDDMAEN(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UCR4_IDDMAEN)
#else
#define BF_UARTV2_UCR4_IDDMAEN(v)   (((v) << 6) & BM_UARTV2_UCR4_IDDMAEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_IDDMAEN(v)   BF_CS1(UARTV2_UCR4, IDDMAEN, v)
#endif

/* --- Register HW_UARTV2_UCR4, field IRSC */

#define BP_UARTV2_UCR4_IRSC      5
#define BM_UARTV2_UCR4_IRSC      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_IRSC(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UCR4_IRSC)
#else
#define BF_UARTV2_UCR4_IRSC(v)   (((v) << 5) & BM_UARTV2_UCR4_IRSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_IRSC(v)   BF_CS1(UARTV2_UCR4, IRSC, v)
#endif

/* --- Register HW_UARTV2_UCR4, field LPBYP */

#define BP_UARTV2_UCR4_LPBYP      4
#define BM_UARTV2_UCR4_LPBYP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_LPBYP(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UCR4_LPBYP)
#else
#define BF_UARTV2_UCR4_LPBYP(v)   (((v) << 4) & BM_UARTV2_UCR4_LPBYP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_LPBYP(v)   BF_CS1(UARTV2_UCR4, LPBYP, v)
#endif

/* --- Register HW_UARTV2_UCR4, field TCEN */

#define BP_UARTV2_UCR4_TCEN      3
#define BM_UARTV2_UCR4_TCEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_TCEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UCR4_TCEN)
#else
#define BF_UARTV2_UCR4_TCEN(v)   (((v) << 3) & BM_UARTV2_UCR4_TCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_TCEN(v)   BF_CS1(UARTV2_UCR4, TCEN, v)
#endif

/* --- Register HW_UARTV2_UCR4, field BKEN */

#define BP_UARTV2_UCR4_BKEN      2
#define BM_UARTV2_UCR4_BKEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_BKEN(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UCR4_BKEN)
#else
#define BF_UARTV2_UCR4_BKEN(v)   (((v) << 2) & BM_UARTV2_UCR4_BKEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_BKEN(v)   BF_CS1(UARTV2_UCR4, BKEN, v)
#endif

/* --- Register HW_UARTV2_UCR4, field OREN */

#define BP_UARTV2_UCR4_OREN      1
#define BM_UARTV2_UCR4_OREN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_OREN(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UCR4_OREN)
#else
#define BF_UARTV2_UCR4_OREN(v)   (((v) << 1) & BM_UARTV2_UCR4_OREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_OREN(v)   BF_CS1(UARTV2_UCR4, OREN, v)
#endif

/* --- Register HW_UARTV2_UCR4, field DREN */

#define BP_UARTV2_UCR4_DREN      0
#define BM_UARTV2_UCR4_DREN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_DREN(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UCR4_DREN)
#else
#define BF_UARTV2_UCR4_DREN(v)   (((v) << 0) & BM_UARTV2_UCR4_DREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UCR4_DREN(v)   BF_CS1(UARTV2_UCR4, DREN, v)
#endif

/*
 * HW_UARTV2_UFCR - UART FIFO Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned TXTL : 6;
        unsigned RFDIV : 3;
        unsigned DCEDTE : 1;
        unsigned RXTL : 6;

    } B;
} hw_uartv2_ufcr_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UFCR register
 */
#define HW_UARTV2_UFCR_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UFCR(x)           (*(volatile hw_uartv2_ufcr_t *) HW_UARTV2_UFCR_ADDR(x))
#define HW_UARTV2_UFCR_RD(x)        (HW_UARTV2_UFCR(x).U)
#define HW_UARTV2_UFCR_WR(x, v)     (HW_UARTV2_UFCR(x).U = (v))
#define HW_UARTV2_UFCR_SET(x, v)    (HW_UARTV2_UFCR_WR(x, HW_UARTV2_UFCR_RD(x) |  (v)))
#define HW_UARTV2_UFCR_CLR(x, v)    (HW_UARTV2_UFCR_WR(x, HW_UARTV2_UFCR_RD(x) & ~(v)))
#define HW_UARTV2_UFCR_TOG(x, v)    (HW_UARTV2_UFCR_WR(x, HW_UARTV2_UFCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UFCR bitfields
 */

/* --- Register HW_UARTV2_UFCR, field TXTL */

#define BP_UARTV2_UFCR_TXTL      10
#define BM_UARTV2_UFCR_TXTL      0x0000fc00

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UFCR_TXTL(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UFCR_TXTL)
#else
#define BF_UARTV2_UFCR_TXTL(v)   (((v) << 10) & BM_UARTV2_UFCR_TXTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UFCR_TXTL(v)   BF_CS1(UARTV2_UFCR, TXTL, v)
#endif

/* --- Register HW_UARTV2_UFCR, field RFDIV */

#define BP_UARTV2_UFCR_RFDIV      7
#define BM_UARTV2_UFCR_RFDIV      0x00000380

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UFCR_RFDIV(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UFCR_RFDIV)
#else
#define BF_UARTV2_UFCR_RFDIV(v)   (((v) << 7) & BM_UARTV2_UFCR_RFDIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UFCR_RFDIV(v)   BF_CS1(UARTV2_UFCR, RFDIV, v)
#endif

/* --- Register HW_UARTV2_UFCR, field DCEDTE */

#define BP_UARTV2_UFCR_DCEDTE      6
#define BM_UARTV2_UFCR_DCEDTE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UFCR_DCEDTE(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UFCR_DCEDTE)
#else
#define BF_UARTV2_UFCR_DCEDTE(v)   (((v) << 6) & BM_UARTV2_UFCR_DCEDTE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UFCR_DCEDTE(v)   BF_CS1(UARTV2_UFCR, DCEDTE, v)
#endif

/* --- Register HW_UARTV2_UFCR, field RXTL */

#define BP_UARTV2_UFCR_RXTL      0
#define BM_UARTV2_UFCR_RXTL      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UFCR_RXTL(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UFCR_RXTL)
#else
#define BF_UARTV2_UFCR_RXTL(v)   (((v) << 0) & BM_UARTV2_UFCR_RXTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UFCR_RXTL(v)   BF_CS1(UARTV2_UFCR, RXTL, v)
#endif

/*
 * HW_UARTV2_USR1 - UART Status Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned PARITYERR : 1;
        unsigned RTSS : 1;
        unsigned TRDY : 1;
        unsigned RTSD : 1;
        unsigned ESCF : 1;
        unsigned FRAMERR : 1;
        unsigned RRDY : 1;
        unsigned AGTIM : 1;
        unsigned DTRD : 1;
        unsigned RXDS : 1;
        unsigned AIRINT : 1;
        unsigned AWAKE : 1;
        unsigned SAD : 1;
        unsigned RESERVED1 : 4;
        unsigned RESERVED2 : 3;

    } B;
} hw_uartv2_usr1_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_USR1 register
 */
#define HW_UARTV2_USR1_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_USR1(x)           (*(volatile hw_uartv2_usr1_t *) HW_UARTV2_USR1_ADDR(x))
#define HW_UARTV2_USR1_RD(x)        (HW_UARTV2_USR1(x).U)
#define HW_UARTV2_USR1_WR(x, v)     (HW_UARTV2_USR1(x).U = (v))
#define HW_UARTV2_USR1_SET(x, v)    (HW_UARTV2_USR1_WR(x, HW_UARTV2_USR1_RD(x) |  (v)))
#define HW_UARTV2_USR1_CLR(x, v)    (HW_UARTV2_USR1_WR(x, HW_UARTV2_USR1_RD(x) & ~(v)))
#define HW_UARTV2_USR1_TOG(x, v)    (HW_UARTV2_USR1_WR(x, HW_UARTV2_USR1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_USR1 bitfields
 */

/* --- Register HW_UARTV2_USR1, field PARITYERR */

#define BP_UARTV2_USR1_PARITYERR      15
#define BM_UARTV2_USR1_PARITYERR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_PARITYERR(v)   ((((reg32_t) v) << 15) & BM_UARTV2_USR1_PARITYERR)
#else
#define BF_UARTV2_USR1_PARITYERR(v)   (((v) << 15) & BM_UARTV2_USR1_PARITYERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_PARITYERR(v)   BF_CS1(UARTV2_USR1, PARITYERR, v)
#endif

/* --- Register HW_UARTV2_USR1, field RTSS */

#define BP_UARTV2_USR1_RTSS      14
#define BM_UARTV2_USR1_RTSS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_RTSS(v)   ((((reg32_t) v) << 14) & BM_UARTV2_USR1_RTSS)
#else
#define BF_UARTV2_USR1_RTSS(v)   (((v) << 14) & BM_UARTV2_USR1_RTSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_RTSS(v)   BF_CS1(UARTV2_USR1, RTSS, v)
#endif

/* --- Register HW_UARTV2_USR1, field TRDY */

#define BP_UARTV2_USR1_TRDY      13
#define BM_UARTV2_USR1_TRDY      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_TRDY(v)   ((((reg32_t) v) << 13) & BM_UARTV2_USR1_TRDY)
#else
#define BF_UARTV2_USR1_TRDY(v)   (((v) << 13) & BM_UARTV2_USR1_TRDY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_TRDY(v)   BF_CS1(UARTV2_USR1, TRDY, v)
#endif

/* --- Register HW_UARTV2_USR1, field RTSD */

#define BP_UARTV2_USR1_RTSD      12
#define BM_UARTV2_USR1_RTSD      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_RTSD(v)   ((((reg32_t) v) << 12) & BM_UARTV2_USR1_RTSD)
#else
#define BF_UARTV2_USR1_RTSD(v)   (((v) << 12) & BM_UARTV2_USR1_RTSD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_RTSD(v)   BF_CS1(UARTV2_USR1, RTSD, v)
#endif

/* --- Register HW_UARTV2_USR1, field ESCF */

#define BP_UARTV2_USR1_ESCF      11
#define BM_UARTV2_USR1_ESCF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_ESCF(v)   ((((reg32_t) v) << 11) & BM_UARTV2_USR1_ESCF)
#else
#define BF_UARTV2_USR1_ESCF(v)   (((v) << 11) & BM_UARTV2_USR1_ESCF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_ESCF(v)   BF_CS1(UARTV2_USR1, ESCF, v)
#endif

/* --- Register HW_UARTV2_USR1, field FRAMERR */

#define BP_UARTV2_USR1_FRAMERR      10
#define BM_UARTV2_USR1_FRAMERR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_FRAMERR(v)   ((((reg32_t) v) << 10) & BM_UARTV2_USR1_FRAMERR)
#else
#define BF_UARTV2_USR1_FRAMERR(v)   (((v) << 10) & BM_UARTV2_USR1_FRAMERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_FRAMERR(v)   BF_CS1(UARTV2_USR1, FRAMERR, v)
#endif

/* --- Register HW_UARTV2_USR1, field RRDY */

#define BP_UARTV2_USR1_RRDY      9
#define BM_UARTV2_USR1_RRDY      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_RRDY(v)   ((((reg32_t) v) << 9) & BM_UARTV2_USR1_RRDY)
#else
#define BF_UARTV2_USR1_RRDY(v)   (((v) << 9) & BM_UARTV2_USR1_RRDY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_RRDY(v)   BF_CS1(UARTV2_USR1, RRDY, v)
#endif

/* --- Register HW_UARTV2_USR1, field AGTIM */

#define BP_UARTV2_USR1_AGTIM      8
#define BM_UARTV2_USR1_AGTIM      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_AGTIM(v)   ((((reg32_t) v) << 8) & BM_UARTV2_USR1_AGTIM)
#else
#define BF_UARTV2_USR1_AGTIM(v)   (((v) << 8) & BM_UARTV2_USR1_AGTIM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_AGTIM(v)   BF_CS1(UARTV2_USR1, AGTIM, v)
#endif

/* --- Register HW_UARTV2_USR1, field DTRD */

#define BP_UARTV2_USR1_DTRD      7
#define BM_UARTV2_USR1_DTRD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_DTRD(v)   ((((reg32_t) v) << 7) & BM_UARTV2_USR1_DTRD)
#else
#define BF_UARTV2_USR1_DTRD(v)   (((v) << 7) & BM_UARTV2_USR1_DTRD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_DTRD(v)   BF_CS1(UARTV2_USR1, DTRD, v)
#endif

/* --- Register HW_UARTV2_USR1, field RXDS */

#define BP_UARTV2_USR1_RXDS      6
#define BM_UARTV2_USR1_RXDS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_RXDS(v)   ((((reg32_t) v) << 6) & BM_UARTV2_USR1_RXDS)
#else
#define BF_UARTV2_USR1_RXDS(v)   (((v) << 6) & BM_UARTV2_USR1_RXDS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_RXDS(v)   BF_CS1(UARTV2_USR1, RXDS, v)
#endif

/* --- Register HW_UARTV2_USR1, field AIRINT */

#define BP_UARTV2_USR1_AIRINT      5
#define BM_UARTV2_USR1_AIRINT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_AIRINT(v)   ((((reg32_t) v) << 5) & BM_UARTV2_USR1_AIRINT)
#else
#define BF_UARTV2_USR1_AIRINT(v)   (((v) << 5) & BM_UARTV2_USR1_AIRINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_AIRINT(v)   BF_CS1(UARTV2_USR1, AIRINT, v)
#endif

/* --- Register HW_UARTV2_USR1, field AWAKE */

#define BP_UARTV2_USR1_AWAKE      4
#define BM_UARTV2_USR1_AWAKE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_AWAKE(v)   ((((reg32_t) v) << 4) & BM_UARTV2_USR1_AWAKE)
#else
#define BF_UARTV2_USR1_AWAKE(v)   (((v) << 4) & BM_UARTV2_USR1_AWAKE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_AWAKE(v)   BF_CS1(UARTV2_USR1, AWAKE, v)
#endif

/* --- Register HW_UARTV2_USR1, field SAD */

#define BP_UARTV2_USR1_SAD      3
#define BM_UARTV2_USR1_SAD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_SAD(v)   ((((reg32_t) v) << 3) & BM_UARTV2_USR1_SAD)
#else
#define BF_UARTV2_USR1_SAD(v)   (((v) << 3) & BM_UARTV2_USR1_SAD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR1_SAD(v)   BF_CS1(UARTV2_USR1, SAD, v)
#endif

/*
 * HW_UARTV2_USR2 - UART Status Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned ADET : 1;
        unsigned TXFE : 1;
        unsigned DTRF : 1;
        unsigned IDLE : 1;
        unsigned ACST : 1;
        unsigned RIDELT : 1;
        unsigned RIIN : 1;
        unsigned IRINT : 1;
        unsigned WAKE : 1;
        unsigned DCDDELT : 1;
        unsigned DCDIN : 1;
        unsigned RTSF : 1;
        unsigned TXDC : 1;
        unsigned BRCD : 1;
        unsigned ORE : 1;
        unsigned RDR : 1;

    } B;
} hw_uartv2_usr2_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_USR2 register
 */
#define HW_UARTV2_USR2_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_USR2(x)           (*(volatile hw_uartv2_usr2_t *) HW_UARTV2_USR2_ADDR(x))
#define HW_UARTV2_USR2_RD(x)        (HW_UARTV2_USR2(x).U)
#define HW_UARTV2_USR2_WR(x, v)     (HW_UARTV2_USR2(x).U = (v))
#define HW_UARTV2_USR2_SET(x, v)    (HW_UARTV2_USR2_WR(x, HW_UARTV2_USR2_RD(x) |  (v)))
#define HW_UARTV2_USR2_CLR(x, v)    (HW_UARTV2_USR2_WR(x, HW_UARTV2_USR2_RD(x) & ~(v)))
#define HW_UARTV2_USR2_TOG(x, v)    (HW_UARTV2_USR2_WR(x, HW_UARTV2_USR2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_USR2 bitfields
 */

/* --- Register HW_UARTV2_USR2, field ADET */

#define BP_UARTV2_USR2_ADET      15
#define BM_UARTV2_USR2_ADET      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_ADET(v)   ((((reg32_t) v) << 15) & BM_UARTV2_USR2_ADET)
#else
#define BF_UARTV2_USR2_ADET(v)   (((v) << 15) & BM_UARTV2_USR2_ADET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_ADET(v)   BF_CS1(UARTV2_USR2, ADET, v)
#endif

/* --- Register HW_UARTV2_USR2, field TXFE */

#define BP_UARTV2_USR2_TXFE      14
#define BM_UARTV2_USR2_TXFE      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_TXFE(v)   ((((reg32_t) v) << 14) & BM_UARTV2_USR2_TXFE)
#else
#define BF_UARTV2_USR2_TXFE(v)   (((v) << 14) & BM_UARTV2_USR2_TXFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_TXFE(v)   BF_CS1(UARTV2_USR2, TXFE, v)
#endif

/* --- Register HW_UARTV2_USR2, field DTRF */

#define BP_UARTV2_USR2_DTRF      13
#define BM_UARTV2_USR2_DTRF      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_DTRF(v)   ((((reg32_t) v) << 13) & BM_UARTV2_USR2_DTRF)
#else
#define BF_UARTV2_USR2_DTRF(v)   (((v) << 13) & BM_UARTV2_USR2_DTRF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_DTRF(v)   BF_CS1(UARTV2_USR2, DTRF, v)
#endif

/* --- Register HW_UARTV2_USR2, field IDLE */

#define BP_UARTV2_USR2_IDLE      12
#define BM_UARTV2_USR2_IDLE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_IDLE(v)   ((((reg32_t) v) << 12) & BM_UARTV2_USR2_IDLE)
#else
#define BF_UARTV2_USR2_IDLE(v)   (((v) << 12) & BM_UARTV2_USR2_IDLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_IDLE(v)   BF_CS1(UARTV2_USR2, IDLE, v)
#endif

/* --- Register HW_UARTV2_USR2, field ACST */

#define BP_UARTV2_USR2_ACST      11
#define BM_UARTV2_USR2_ACST      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_ACST(v)   ((((reg32_t) v) << 11) & BM_UARTV2_USR2_ACST)
#else
#define BF_UARTV2_USR2_ACST(v)   (((v) << 11) & BM_UARTV2_USR2_ACST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_ACST(v)   BF_CS1(UARTV2_USR2, ACST, v)
#endif

/* --- Register HW_UARTV2_USR2, field RIDELT */

#define BP_UARTV2_USR2_RIDELT      10
#define BM_UARTV2_USR2_RIDELT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_RIDELT(v)   ((((reg32_t) v) << 10) & BM_UARTV2_USR2_RIDELT)
#else
#define BF_UARTV2_USR2_RIDELT(v)   (((v) << 10) & BM_UARTV2_USR2_RIDELT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_RIDELT(v)   BF_CS1(UARTV2_USR2, RIDELT, v)
#endif

/* --- Register HW_UARTV2_USR2, field RIIN */

#define BP_UARTV2_USR2_RIIN      9
#define BM_UARTV2_USR2_RIIN      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_RIIN(v)   ((((reg32_t) v) << 9) & BM_UARTV2_USR2_RIIN)
#else
#define BF_UARTV2_USR2_RIIN(v)   (((v) << 9) & BM_UARTV2_USR2_RIIN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_RIIN(v)   BF_CS1(UARTV2_USR2, RIIN, v)
#endif

/* --- Register HW_UARTV2_USR2, field IRINT */

#define BP_UARTV2_USR2_IRINT      8
#define BM_UARTV2_USR2_IRINT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_IRINT(v)   ((((reg32_t) v) << 8) & BM_UARTV2_USR2_IRINT)
#else
#define BF_UARTV2_USR2_IRINT(v)   (((v) << 8) & BM_UARTV2_USR2_IRINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_IRINT(v)   BF_CS1(UARTV2_USR2, IRINT, v)
#endif

/* --- Register HW_UARTV2_USR2, field WAKE */

#define BP_UARTV2_USR2_WAKE      7
#define BM_UARTV2_USR2_WAKE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_WAKE(v)   ((((reg32_t) v) << 7) & BM_UARTV2_USR2_WAKE)
#else
#define BF_UARTV2_USR2_WAKE(v)   (((v) << 7) & BM_UARTV2_USR2_WAKE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_WAKE(v)   BF_CS1(UARTV2_USR2, WAKE, v)
#endif

/* --- Register HW_UARTV2_USR2, field DCDDELT */

#define BP_UARTV2_USR2_DCDDELT      6
#define BM_UARTV2_USR2_DCDDELT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_DCDDELT(v)   ((((reg32_t) v) << 6) & BM_UARTV2_USR2_DCDDELT)
#else
#define BF_UARTV2_USR2_DCDDELT(v)   (((v) << 6) & BM_UARTV2_USR2_DCDDELT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_DCDDELT(v)   BF_CS1(UARTV2_USR2, DCDDELT, v)
#endif

/* --- Register HW_UARTV2_USR2, field DCDIN */

#define BP_UARTV2_USR2_DCDIN      5
#define BM_UARTV2_USR2_DCDIN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_DCDIN(v)   ((((reg32_t) v) << 5) & BM_UARTV2_USR2_DCDIN)
#else
#define BF_UARTV2_USR2_DCDIN(v)   (((v) << 5) & BM_UARTV2_USR2_DCDIN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_DCDIN(v)   BF_CS1(UARTV2_USR2, DCDIN, v)
#endif

/* --- Register HW_UARTV2_USR2, field RTSF */

#define BP_UARTV2_USR2_RTSF      4
#define BM_UARTV2_USR2_RTSF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_RTSF(v)   ((((reg32_t) v) << 4) & BM_UARTV2_USR2_RTSF)
#else
#define BF_UARTV2_USR2_RTSF(v)   (((v) << 4) & BM_UARTV2_USR2_RTSF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_RTSF(v)   BF_CS1(UARTV2_USR2, RTSF, v)
#endif

/* --- Register HW_UARTV2_USR2, field TXDC */

#define BP_UARTV2_USR2_TXDC      3
#define BM_UARTV2_USR2_TXDC      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_TXDC(v)   ((((reg32_t) v) << 3) & BM_UARTV2_USR2_TXDC)
#else
#define BF_UARTV2_USR2_TXDC(v)   (((v) << 3) & BM_UARTV2_USR2_TXDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_TXDC(v)   BF_CS1(UARTV2_USR2, TXDC, v)
#endif

/* --- Register HW_UARTV2_USR2, field BRCD */

#define BP_UARTV2_USR2_BRCD      2
#define BM_UARTV2_USR2_BRCD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_BRCD(v)   ((((reg32_t) v) << 2) & BM_UARTV2_USR2_BRCD)
#else
#define BF_UARTV2_USR2_BRCD(v)   (((v) << 2) & BM_UARTV2_USR2_BRCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_BRCD(v)   BF_CS1(UARTV2_USR2, BRCD, v)
#endif

/* --- Register HW_UARTV2_USR2, field ORE */

#define BP_UARTV2_USR2_ORE      1
#define BM_UARTV2_USR2_ORE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_ORE(v)   ((((reg32_t) v) << 1) & BM_UARTV2_USR2_ORE)
#else
#define BF_UARTV2_USR2_ORE(v)   (((v) << 1) & BM_UARTV2_USR2_ORE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_ORE(v)   BF_CS1(UARTV2_USR2, ORE, v)
#endif

/* --- Register HW_UARTV2_USR2, field RDR */

#define BP_UARTV2_USR2_RDR      0
#define BM_UARTV2_USR2_RDR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_RDR(v)   ((((reg32_t) v) << 0) & BM_UARTV2_USR2_RDR)
#else
#define BF_UARTV2_USR2_RDR(v)   (((v) << 0) & BM_UARTV2_USR2_RDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_USR2_RDR(v)   BF_CS1(UARTV2_USR2, RDR, v)
#endif

/*
 * HW_UARTV2_UESC - UART Escape Character Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 24;
        unsigned ESC_CHAR : 8;

    } B;
} hw_uartv2_uesc_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UESC register
 */
#define HW_UARTV2_UESC_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UESC(x)           (*(volatile hw_uartv2_uesc_t *) HW_UARTV2_UESC_ADDR(x))
#define HW_UARTV2_UESC_RD(x)        (HW_UARTV2_UESC(x).U)
#define HW_UARTV2_UESC_WR(x, v)     (HW_UARTV2_UESC(x).U = (v))
#define HW_UARTV2_UESC_SET(x, v)    (HW_UARTV2_UESC_WR(x, HW_UARTV2_UESC_RD(x) |  (v)))
#define HW_UARTV2_UESC_CLR(x, v)    (HW_UARTV2_UESC_WR(x, HW_UARTV2_UESC_RD(x) & ~(v)))
#define HW_UARTV2_UESC_TOG(x, v)    (HW_UARTV2_UESC_WR(x, HW_UARTV2_UESC_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UESC bitfields
 */

/* --- Register HW_UARTV2_UESC, field ESC_CHAR */

#define BP_UARTV2_UESC_ESC_CHAR      0
#define BM_UARTV2_UESC_ESC_CHAR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UESC_ESC_CHAR(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UESC_ESC_CHAR)
#else
#define BF_UARTV2_UESC_ESC_CHAR(v)   (((v) << 0) & BM_UARTV2_UESC_ESC_CHAR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UESC_ESC_CHAR(v)   BF_CS1(UARTV2_UESC, ESC_CHAR, v)
#endif

/*
 * HW_UARTV2_UTIM - UART Escape Timer Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20;
        unsigned TIM : 12;

    } B;
} hw_uartv2_utim_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UTIM register
 */
#define HW_UARTV2_UTIM_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UTIM(x)           (*(volatile hw_uartv2_utim_t *) HW_UARTV2_UTIM_ADDR(x))
#define HW_UARTV2_UTIM_RD(x)        (HW_UARTV2_UTIM(x).U)
#define HW_UARTV2_UTIM_WR(x, v)     (HW_UARTV2_UTIM(x).U = (v))
#define HW_UARTV2_UTIM_SET(x, v)    (HW_UARTV2_UTIM_WR(x, HW_UARTV2_UTIM_RD(x) |  (v)))
#define HW_UARTV2_UTIM_CLR(x, v)    (HW_UARTV2_UTIM_WR(x, HW_UARTV2_UTIM_RD(x) & ~(v)))
#define HW_UARTV2_UTIM_TOG(x, v)    (HW_UARTV2_UTIM_WR(x, HW_UARTV2_UTIM_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UTIM bitfields
 */

/* --- Register HW_UARTV2_UTIM, field TIM */

#define BP_UARTV2_UTIM_TIM      0
#define BM_UARTV2_UTIM_TIM      0x00000fff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTIM_TIM(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UTIM_TIM)
#else
#define BF_UARTV2_UTIM_TIM(v)   (((v) << 0) & BM_UARTV2_UTIM_TIM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTIM_TIM(v)   BF_CS1(UARTV2_UTIM, TIM, v)
#endif

/*
 * HW_UARTV2_UBIR - UART BRM Incremental Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned INC : 16;

    } B;
} hw_uartv2_ubir_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UBIR register
 */
#define HW_UARTV2_UBIR_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UBIR(x)           (*(volatile hw_uartv2_ubir_t *) HW_UARTV2_UBIR_ADDR(x))
#define HW_UARTV2_UBIR_RD(x)        (HW_UARTV2_UBIR(x).U)
#define HW_UARTV2_UBIR_WR(x, v)     (HW_UARTV2_UBIR(x).U = (v))
#define HW_UARTV2_UBIR_SET(x, v)    (HW_UARTV2_UBIR_WR(x, HW_UARTV2_UBIR_RD(x) |  (v)))
#define HW_UARTV2_UBIR_CLR(x, v)    (HW_UARTV2_UBIR_WR(x, HW_UARTV2_UBIR_RD(x) & ~(v)))
#define HW_UARTV2_UBIR_TOG(x, v)    (HW_UARTV2_UBIR_WR(x, HW_UARTV2_UBIR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UBIR bitfields
 */

/* --- Register HW_UARTV2_UBIR, field INC */

#define BP_UARTV2_UBIR_INC      0
#define BM_UARTV2_UBIR_INC      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UBIR_INC(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UBIR_INC)
#else
#define BF_UARTV2_UBIR_INC(v)   (((v) << 0) & BM_UARTV2_UBIR_INC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UBIR_INC(v)   BF_CS1(UARTV2_UBIR, INC, v)
#endif

/*
 * HW_UARTV2_UBMR - UART BRM Modulator Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned MOD : 16;

    } B;
} hw_uartv2_ubmr_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UBMR register
 */
#define HW_UARTV2_UBMR_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UBMR(x)           (*(volatile hw_uartv2_ubmr_t *) HW_UARTV2_UBMR_ADDR(x))
#define HW_UARTV2_UBMR_RD(x)        (HW_UARTV2_UBMR(x).U)
#define HW_UARTV2_UBMR_WR(x, v)     (HW_UARTV2_UBMR(x).U = (v))
#define HW_UARTV2_UBMR_SET(x, v)    (HW_UARTV2_UBMR_WR(x, HW_UARTV2_UBMR_RD(x) |  (v)))
#define HW_UARTV2_UBMR_CLR(x, v)    (HW_UARTV2_UBMR_WR(x, HW_UARTV2_UBMR_RD(x) & ~(v)))
#define HW_UARTV2_UBMR_TOG(x, v)    (HW_UARTV2_UBMR_WR(x, HW_UARTV2_UBMR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UBMR bitfields
 */

/* --- Register HW_UARTV2_UBMR, field MOD */

#define BP_UARTV2_UBMR_MOD      0
#define BM_UARTV2_UBMR_MOD      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UBMR_MOD(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UBMR_MOD)
#else
#define BF_UARTV2_UBMR_MOD(v)   (((v) << 0) & BM_UARTV2_UBMR_MOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UBMR_MOD(v)   BF_CS1(UARTV2_UBMR, MOD, v)
#endif

/*
 * HW_UARTV2_UBRC - UART Baud Rate Count Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned BCNT : 16;

    } B;
} hw_uartv2_ubrc_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UBRC register
 */
#define HW_UARTV2_UBRC_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UBRC(x)           (*(volatile hw_uartv2_ubrc_t *) HW_UARTV2_UBRC_ADDR(x))
#define HW_UARTV2_UBRC_RD(x)        (HW_UARTV2_UBRC(x).U)
#define HW_UARTV2_UBRC_WR(x, v)     (HW_UARTV2_UBRC(x).U = (v))
#define HW_UARTV2_UBRC_SET(x, v)    (HW_UARTV2_UBRC_WR(x, HW_UARTV2_UBRC_RD(x) |  (v)))
#define HW_UARTV2_UBRC_CLR(x, v)    (HW_UARTV2_UBRC_WR(x, HW_UARTV2_UBRC_RD(x) & ~(v)))
#define HW_UARTV2_UBRC_TOG(x, v)    (HW_UARTV2_UBRC_WR(x, HW_UARTV2_UBRC_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UBRC bitfields
 */

/* --- Register HW_UARTV2_UBRC, field BCNT */

#define BP_UARTV2_UBRC_BCNT      0
#define BM_UARTV2_UBRC_BCNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UBRC_BCNT(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UBRC_BCNT)
#else
#define BF_UARTV2_UBRC_BCNT(v)   (((v) << 0) & BM_UARTV2_UBRC_BCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UBRC_BCNT(v)   BF_CS1(UARTV2_UBRC, BCNT, v)
#endif

/*
 * HW_UARTV2_ONEMS - UART One Millisecond Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 16;
        unsigned ONEMS : 24;
        unsigned ONEMS : 16;

    } B;
} hw_uartv2_onems_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_ONEMS register
 */
#define HW_UARTV2_ONEMS_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_ONEMS(x)           (*(volatile hw_uartv2_onems_t *) HW_UARTV2_ONEMS_ADDR(x))
#define HW_UARTV2_ONEMS_RD(x)        (HW_UARTV2_ONEMS(x).U)
#define HW_UARTV2_ONEMS_WR(x, v)     (HW_UARTV2_ONEMS(x).U = (v))
#define HW_UARTV2_ONEMS_SET(x, v)    (HW_UARTV2_ONEMS_WR(x, HW_UARTV2_ONEMS_RD(x) |  (v)))
#define HW_UARTV2_ONEMS_CLR(x, v)    (HW_UARTV2_ONEMS_WR(x, HW_UARTV2_ONEMS_RD(x) & ~(v)))
#define HW_UARTV2_ONEMS_TOG(x, v)    (HW_UARTV2_ONEMS_WR(x, HW_UARTV2_ONEMS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_ONEMS bitfields
 */

/* --- Register HW_UARTV2_ONEMS, field ONEMS */

#define BP_UARTV2_ONEMS_ONEMS      0
#define BM_UARTV2_ONEMS_ONEMS      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_ONEMS_ONEMS(v)   ((((reg32_t) v) << 0) & BM_UARTV2_ONEMS_ONEMS)
#else
#define BF_UARTV2_ONEMS_ONEMS(v)   (((v) << 0) & BM_UARTV2_ONEMS_ONEMS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_ONEMS_ONEMS(v)   BF_CS1(UARTV2_ONEMS, ONEMS, v)
#endif

/* --- Register HW_UARTV2_ONEMS, field ONEMS */

#define BP_UARTV2_ONEMS_ONEMS      0
#define BM_UARTV2_ONEMS_ONEMS      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_ONEMS_ONEMS(v)   ((((reg32_t) v) << 0) & BM_UARTV2_ONEMS_ONEMS)
#else
#define BF_UARTV2_ONEMS_ONEMS(v)   (((v) << 0) & BM_UARTV2_ONEMS_ONEMS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_ONEMS_ONEMS(v)   BF_CS1(UARTV2_ONEMS, ONEMS, v)
#endif

/*
 * HW_UARTV2_UTS - UART Test Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 18;
        unsigned FRCPERR : 1;
        unsigned LOOP : 1;
        unsigned DBGEN : 1;
        unsigned LOOPIR : 1;
        unsigned RXDBG : 1;
        unsigned RESERVED1 : 2;
        unsigned TXEMPTY : 1;
        unsigned RXEMPTY : 1;
        unsigned TXFULL : 1;
        unsigned RXFULL : 1;
        unsigned RESERVED2 : 2;
        unsigned SOFTRST : 1;

    } B;
} hw_uartv2_uts_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UTS register
 */
#define HW_UARTV2_UTS_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xb4)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UTS(x)           (*(volatile hw_uartv2_uts_t *) HW_UARTV2_UTS_ADDR(x))
#define HW_UARTV2_UTS_RD(x)        (HW_UARTV2_UTS(x).U)
#define HW_UARTV2_UTS_WR(x, v)     (HW_UARTV2_UTS(x).U = (v))
#define HW_UARTV2_UTS_SET(x, v)    (HW_UARTV2_UTS_WR(x, HW_UARTV2_UTS_RD(x) |  (v)))
#define HW_UARTV2_UTS_CLR(x, v)    (HW_UARTV2_UTS_WR(x, HW_UARTV2_UTS_RD(x) & ~(v)))
#define HW_UARTV2_UTS_TOG(x, v)    (HW_UARTV2_UTS_WR(x, HW_UARTV2_UTS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UTS bitfields
 */

/* --- Register HW_UARTV2_UTS, field FRCPERR */

#define BP_UARTV2_UTS_FRCPERR      13
#define BM_UARTV2_UTS_FRCPERR      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_FRCPERR(v)   ((((reg32_t) v) << 13) & BM_UARTV2_UTS_FRCPERR)
#else
#define BF_UARTV2_UTS_FRCPERR(v)   (((v) << 13) & BM_UARTV2_UTS_FRCPERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_FRCPERR(v)   BF_CS1(UARTV2_UTS, FRCPERR, v)
#endif

/* --- Register HW_UARTV2_UTS, field LOOP */

#define BP_UARTV2_UTS_LOOP      12
#define BM_UARTV2_UTS_LOOP      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_LOOP(v)   ((((reg32_t) v) << 12) & BM_UARTV2_UTS_LOOP)
#else
#define BF_UARTV2_UTS_LOOP(v)   (((v) << 12) & BM_UARTV2_UTS_LOOP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_LOOP(v)   BF_CS1(UARTV2_UTS, LOOP, v)
#endif

/* --- Register HW_UARTV2_UTS, field DBGEN */

#define BP_UARTV2_UTS_DBGEN      11
#define BM_UARTV2_UTS_DBGEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_DBGEN(v)   ((((reg32_t) v) << 11) & BM_UARTV2_UTS_DBGEN)
#else
#define BF_UARTV2_UTS_DBGEN(v)   (((v) << 11) & BM_UARTV2_UTS_DBGEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_DBGEN(v)   BF_CS1(UARTV2_UTS, DBGEN, v)
#endif

/* --- Register HW_UARTV2_UTS, field LOOPIR */

#define BP_UARTV2_UTS_LOOPIR      10
#define BM_UARTV2_UTS_LOOPIR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_LOOPIR(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UTS_LOOPIR)
#else
#define BF_UARTV2_UTS_LOOPIR(v)   (((v) << 10) & BM_UARTV2_UTS_LOOPIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_LOOPIR(v)   BF_CS1(UARTV2_UTS, LOOPIR, v)
#endif

/* --- Register HW_UARTV2_UTS, field RXDBG */

#define BP_UARTV2_UTS_RXDBG      9
#define BM_UARTV2_UTS_RXDBG      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_RXDBG(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UTS_RXDBG)
#else
#define BF_UARTV2_UTS_RXDBG(v)   (((v) << 9) & BM_UARTV2_UTS_RXDBG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_RXDBG(v)   BF_CS1(UARTV2_UTS, RXDBG, v)
#endif

/* --- Register HW_UARTV2_UTS, field TXEMPTY */

#define BP_UARTV2_UTS_TXEMPTY      6
#define BM_UARTV2_UTS_TXEMPTY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_TXEMPTY(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UTS_TXEMPTY)
#else
#define BF_UARTV2_UTS_TXEMPTY(v)   (((v) << 6) & BM_UARTV2_UTS_TXEMPTY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_TXEMPTY(v)   BF_CS1(UARTV2_UTS, TXEMPTY, v)
#endif

/* --- Register HW_UARTV2_UTS, field RXEMPTY */

#define BP_UARTV2_UTS_RXEMPTY      5
#define BM_UARTV2_UTS_RXEMPTY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_RXEMPTY(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UTS_RXEMPTY)
#else
#define BF_UARTV2_UTS_RXEMPTY(v)   (((v) << 5) & BM_UARTV2_UTS_RXEMPTY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_RXEMPTY(v)   BF_CS1(UARTV2_UTS, RXEMPTY, v)
#endif

/* --- Register HW_UARTV2_UTS, field TXFULL */

#define BP_UARTV2_UTS_TXFULL      4
#define BM_UARTV2_UTS_TXFULL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_TXFULL(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UTS_TXFULL)
#else
#define BF_UARTV2_UTS_TXFULL(v)   (((v) << 4) & BM_UARTV2_UTS_TXFULL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_TXFULL(v)   BF_CS1(UARTV2_UTS, TXFULL, v)
#endif

/* --- Register HW_UARTV2_UTS, field RXFULL */

#define BP_UARTV2_UTS_RXFULL      3
#define BM_UARTV2_UTS_RXFULL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_RXFULL(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UTS_RXFULL)
#else
#define BF_UARTV2_UTS_RXFULL(v)   (((v) << 3) & BM_UARTV2_UTS_RXFULL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_RXFULL(v)   BF_CS1(UARTV2_UTS, RXFULL, v)
#endif

/* --- Register HW_UARTV2_UTS, field SOFTRST */

#define BP_UARTV2_UTS_SOFTRST      0
#define BM_UARTV2_UTS_SOFTRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_SOFTRST(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UTS_SOFTRST)
#else
#define BF_UARTV2_UTS_SOFTRST(v)   (((v) << 0) & BM_UARTV2_UTS_SOFTRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UTS_SOFTRST(v)   BF_CS1(UARTV2_UTS, SOFTRST, v)
#endif

/*
 * HW_UARTV2_UMCR - UART RS-485 Mode Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned SLADDR : 8;
        unsigned RESERVED1 : 4;
        unsigned SADEN : 1;
        unsigned TXB8 : 1;
        unsigned SLAM : 1;
        unsigned MDEN : 1;

    } B;
} hw_uartv2_umcr_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UMCR register
 */
#define HW_UARTV2_UMCR_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xb8)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UMCR(x)           (*(volatile hw_uartv2_umcr_t *) HW_UARTV2_UMCR_ADDR(x))
#define HW_UARTV2_UMCR_RD(x)        (HW_UARTV2_UMCR(x).U)
#define HW_UARTV2_UMCR_WR(x, v)     (HW_UARTV2_UMCR(x).U = (v))
#define HW_UARTV2_UMCR_SET(x, v)    (HW_UARTV2_UMCR_WR(x, HW_UARTV2_UMCR_RD(x) |  (v)))
#define HW_UARTV2_UMCR_CLR(x, v)    (HW_UARTV2_UMCR_WR(x, HW_UARTV2_UMCR_RD(x) & ~(v)))
#define HW_UARTV2_UMCR_TOG(x, v)    (HW_UARTV2_UMCR_WR(x, HW_UARTV2_UMCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual UARTV2_UMCR bitfields
 */

/* --- Register HW_UARTV2_UMCR, field SLADDR */

#define BP_UARTV2_UMCR_SLADDR      8
#define BM_UARTV2_UMCR_SLADDR      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_SLADDR(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UMCR_SLADDR)
#else
#define BF_UARTV2_UMCR_SLADDR(v)   (((v) << 8) & BM_UARTV2_UMCR_SLADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UMCR_SLADDR(v)   BF_CS1(UARTV2_UMCR, SLADDR, v)
#endif

/* --- Register HW_UARTV2_UMCR, field SADEN */

#define BP_UARTV2_UMCR_SADEN      3
#define BM_UARTV2_UMCR_SADEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_SADEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UMCR_SADEN)
#else
#define BF_UARTV2_UMCR_SADEN(v)   (((v) << 3) & BM_UARTV2_UMCR_SADEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UMCR_SADEN(v)   BF_CS1(UARTV2_UMCR, SADEN, v)
#endif

/* --- Register HW_UARTV2_UMCR, field TXB8 */

#define BP_UARTV2_UMCR_TXB8      2
#define BM_UARTV2_UMCR_TXB8      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_TXB8(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UMCR_TXB8)
#else
#define BF_UARTV2_UMCR_TXB8(v)   (((v) << 2) & BM_UARTV2_UMCR_TXB8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UMCR_TXB8(v)   BF_CS1(UARTV2_UMCR, TXB8, v)
#endif

/* --- Register HW_UARTV2_UMCR, field SLAM */

#define BP_UARTV2_UMCR_SLAM      1
#define BM_UARTV2_UMCR_SLAM      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_SLAM(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UMCR_SLAM)
#else
#define BF_UARTV2_UMCR_SLAM(v)   (((v) << 1) & BM_UARTV2_UMCR_SLAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UMCR_SLAM(v)   BF_CS1(UARTV2_UMCR, SLAM, v)
#endif

/* --- Register HW_UARTV2_UMCR, field MDEN */

#define BP_UARTV2_UMCR_MDEN      0
#define BM_UARTV2_UMCR_MDEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_MDEN(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UMCR_MDEN)
#else
#define BF_UARTV2_UMCR_MDEN(v)   (((v) << 0) & BM_UARTV2_UMCR_MDEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_UARTV2_UMCR_MDEN(v)   BF_CS1(UARTV2_UMCR, MDEN, v)
#endif


#endif // _UARTV2_H

