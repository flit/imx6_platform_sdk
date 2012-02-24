/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SPDIF_H
#define _SPDIF_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_SPDIF_SCR - SPDIF Configuration Register
 * - HW_SPDIF_SRCD - CDText Control Register
 * - HW_SPDIF_SRPC - PhaseConfig Register
 * - HW_SPDIF_SIE - InterruptEn Register
 * - HW_SPDIF_SIS - InterruptStat Register
 * - HW_SPDIF_SRL - SPDIFRxLeft Register
 * - HW_SPDIF_SRR - SPDIFRxRight Register
 * - HW_SPDIF_SRCSH - SPDIFRxCChannel_h Register
 * - HW_SPDIF_SRCSL - SPDIFRxCChannel_l Register
 * - HW_SPDIF_SRU - UchannelRx Register
 * - HW_SPDIF_SRQ - QchannelRx Register
 * - HW_SPDIF_STL - SPDIFTxLeft Register
 * - HW_SPDIF_STR - SPDIFTxRight Register
 * - HW_SPDIF_STCSCH - SPDIFTxCChannelCons_h Register
 * - HW_SPDIF_STCSCL - SPDIFTxCChannelCons_l Register
 * - HW_SPDIF_SRFM - FreqMeas Register
 * - HW_SPDIF_STC - SPDIFTxClk Register
 *
 * hw_spdif_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SPDIF_BASE
#define REGS_SPDIF_BASE (0x02004000) //!< Base address for SPDIF.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SCR - SPDIF Configuration Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned USRC_SEL : 2; //!< 
        unsigned TXSEL : 3; //!< 
        unsigned VALCTRL : 1; //!< 
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned DMA_TX_EN : 1; //!< DMA Transmit Request Enable (Tx FIFO empty)
        unsigned DMA_RX_EN : 1; //!< DMA Receive Request Enable (RX FIFO full)
        unsigned TXFIFO_CTRL : 2; //!< 
        unsigned SOFT_RESET : 1; //!< When write 1 to this bit, it will cause SPDIF software reset. The software reset will last 8 cycles. When in the reset process, return 1 when read. else return 0 when read.
        unsigned LOW_POWER : 1; //!< When write 1 to this bit, it will cause SPDIF enter low-power mode. return 1 when SPDIF in Low-Power mode.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned TXFIFOEMPTY_SEL : 2; //!< 
        unsigned TXAUTOSYNC : 1; //!< 
        unsigned RXAUTOSYNC : 1; //!< 
        unsigned RXFIFOFULL_SEL : 2; //!< 
        unsigned RXFIFO_RST : 1; //!< 
        unsigned RXFIFO_OFF : 1; //!< 
        unsigned RXFIFO_CTRL : 1; //!< 
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_scr_t;
#endif

/*
 * constants & macros for entire SPDIF_SCR register
 */
#define HW_SPDIF_SCR_ADDR      (REGS_SPDIF_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SCR           (*(volatile hw_spdif_scr_t *) HW_SPDIF_SCR_ADDR)
#define HW_SPDIF_SCR_RD()      (HW_SPDIF_SCR.U)
#define HW_SPDIF_SCR_WR(v)     (HW_SPDIF_SCR.U = (v))
#define HW_SPDIF_SCR_SET(v)    (HW_SPDIF_SCR_WR(HW_SPDIF_SCR_RD() |  (v)))
#define HW_SPDIF_SCR_CLR(v)    (HW_SPDIF_SCR_WR(HW_SPDIF_SCR_RD() & ~(v)))
#define HW_SPDIF_SCR_TOG(v)    (HW_SPDIF_SCR_WR(HW_SPDIF_SCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDIF_SCR bitfields
 */

/* --- Register HW_SPDIF_SCR, field USRC_SEL (RW)
 *

 *
 * Values:
 * 00 - No embedded U channel
 * 01 - U channel from SPDIF receive block (CD mode)
 * 10 - Reserved
 * 11 - U channel from on chip transmitter
 */

#define BP_SPDIF_SCR_USRC_SEL      0
#define BM_SPDIF_SCR_USRC_SEL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_USRC_SEL(v)   ((((reg32_t) v) << 0) & BM_SPDIF_SCR_USRC_SEL)
#else
#define BF_SPDIF_SCR_USRC_SEL(v)   (((v) << 0) & BM_SPDIF_SCR_USRC_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the USRC_SEL field to a new value.
#define BW_SPDIF_SCR_USRC_SEL(v)   BF_CS1(SPDIF_SCR, USRC_SEL, v)
#endif


/* --- Register HW_SPDIF_SCR, field TXSEL (RW)
 *

 *
 * Values:
 * 000 - Off and output 0
 * 001 - Feed-through SPDIFIN
 * 101 - Tx Normal operation
 */

#define BP_SPDIF_SCR_TXSEL      2
#define BM_SPDIF_SCR_TXSEL      0x0000001c

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_TXSEL(v)   ((((reg32_t) v) << 2) & BM_SPDIF_SCR_TXSEL)
#else
#define BF_SPDIF_SCR_TXSEL(v)   (((v) << 2) & BM_SPDIF_SCR_TXSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSEL field to a new value.
#define BW_SPDIF_SCR_TXSEL(v)   BF_CS1(SPDIF_SCR, TXSEL, v)
#endif


/* --- Register HW_SPDIF_SCR, field VALCTRL (RW)
 *

 *
 * Values:
 * 0 - Outgoing Validity always set
 * 1 - Outgoing Validity always clear
 */

#define BP_SPDIF_SCR_VALCTRL      5
#define BM_SPDIF_SCR_VALCTRL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_VALCTRL(v)   ((((reg32_t) v) << 5) & BM_SPDIF_SCR_VALCTRL)
#else
#define BF_SPDIF_SCR_VALCTRL(v)   (((v) << 5) & BM_SPDIF_SCR_VALCTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALCTRL field to a new value.
#define BW_SPDIF_SCR_VALCTRL(v)   BF_CS1(SPDIF_SCR, VALCTRL, v)
#endif


/* --- Register HW_SPDIF_SCR, field DMA_TX_EN (RW)
 *
 * DMA Transmit Request Enable (Tx FIFO empty)
 */

#define BP_SPDIF_SCR_DMA_TX_EN      8
#define BM_SPDIF_SCR_DMA_TX_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_DMA_TX_EN(v)   ((((reg32_t) v) << 8) & BM_SPDIF_SCR_DMA_TX_EN)
#else
#define BF_SPDIF_SCR_DMA_TX_EN(v)   (((v) << 8) & BM_SPDIF_SCR_DMA_TX_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_TX_EN field to a new value.
#define BW_SPDIF_SCR_DMA_TX_EN(v)   BF_CS1(SPDIF_SCR, DMA_TX_EN, v)
#endif

/* --- Register HW_SPDIF_SCR, field DMA_RX_EN (RW)
 *
 * DMA Receive Request Enable (RX FIFO full)
 */

#define BP_SPDIF_SCR_DMA_RX_EN      9
#define BM_SPDIF_SCR_DMA_RX_EN      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_DMA_RX_EN(v)   ((((reg32_t) v) << 9) & BM_SPDIF_SCR_DMA_RX_EN)
#else
#define BF_SPDIF_SCR_DMA_RX_EN(v)   (((v) << 9) & BM_SPDIF_SCR_DMA_RX_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_RX_EN field to a new value.
#define BW_SPDIF_SCR_DMA_RX_EN(v)   BF_CS1(SPDIF_SCR, DMA_RX_EN, v)
#endif

/* --- Register HW_SPDIF_SCR, field TXFIFO_CTRL (RW)
 *

 *
 * Values:
 * 00 - Send out digital zero on SPDIF Tx
 * 01 - Tx Normal operation
 * 10 - Reset to 1 sample remaining
 * 11 - Reserved
 */

#define BP_SPDIF_SCR_TXFIFO_CTRL      10
#define BM_SPDIF_SCR_TXFIFO_CTRL      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_TXFIFO_CTRL(v)   ((((reg32_t) v) << 10) & BM_SPDIF_SCR_TXFIFO_CTRL)
#else
#define BF_SPDIF_SCR_TXFIFO_CTRL(v)   (((v) << 10) & BM_SPDIF_SCR_TXFIFO_CTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFIFO_CTRL field to a new value.
#define BW_SPDIF_SCR_TXFIFO_CTRL(v)   BF_CS1(SPDIF_SCR, TXFIFO_CTRL, v)
#endif


/* --- Register HW_SPDIF_SCR, field SOFT_RESET (RW)
 *
 * When write 1 to this bit, it will cause SPDIF software reset. The software reset will last 8
 * cycles. When in the reset process, return 1 when read. else return 0 when read.
 */

#define BP_SPDIF_SCR_SOFT_RESET      12
#define BM_SPDIF_SCR_SOFT_RESET      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_SOFT_RESET(v)   ((((reg32_t) v) << 12) & BM_SPDIF_SCR_SOFT_RESET)
#else
#define BF_SPDIF_SCR_SOFT_RESET(v)   (((v) << 12) & BM_SPDIF_SCR_SOFT_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SOFT_RESET field to a new value.
#define BW_SPDIF_SCR_SOFT_RESET(v)   BF_CS1(SPDIF_SCR, SOFT_RESET, v)
#endif

/* --- Register HW_SPDIF_SCR, field LOW_POWER (RW)
 *
 * When write 1 to this bit, it will cause SPDIF enter low-power mode. return 1 when SPDIF in Low-
 * Power mode.
 */

#define BP_SPDIF_SCR_LOW_POWER      13
#define BM_SPDIF_SCR_LOW_POWER      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_LOW_POWER(v)   ((((reg32_t) v) << 13) & BM_SPDIF_SCR_LOW_POWER)
#else
#define BF_SPDIF_SCR_LOW_POWER(v)   (((v) << 13) & BM_SPDIF_SCR_LOW_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOW_POWER field to a new value.
#define BW_SPDIF_SCR_LOW_POWER(v)   BF_CS1(SPDIF_SCR, LOW_POWER, v)
#endif

/* --- Register HW_SPDIF_SCR, field TXFIFOEMPTY_SEL (RW)
 *

 *
 * Values:
 * 00 - Empty interrupt if 0 sample in Tx left and right FIFOs
 * 01 - Empty interrupt if at most 4 sample in Tx left and right FIFOs
 * 10 - Empty interrupt if at most 8 sample in Tx left and right FIFOs
 * 11 - Empty interrupt if at most 12 sample in Tx left and right FIFOs
 */

#define BP_SPDIF_SCR_TXFIFOEMPTY_SEL      15
#define BM_SPDIF_SCR_TXFIFOEMPTY_SEL      0x00018000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_TXFIFOEMPTY_SEL(v)   ((((reg32_t) v) << 15) & BM_SPDIF_SCR_TXFIFOEMPTY_SEL)
#else
#define BF_SPDIF_SCR_TXFIFOEMPTY_SEL(v)   (((v) << 15) & BM_SPDIF_SCR_TXFIFOEMPTY_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFIFOEMPTY_SEL field to a new value.
#define BW_SPDIF_SCR_TXFIFOEMPTY_SEL(v)   BF_CS1(SPDIF_SCR, TXFIFOEMPTY_SEL, v)
#endif


/* --- Register HW_SPDIF_SCR, field TXAUTOSYNC (RW)
 *

 *
 * Values:
 * 0 - Tx FIFO auto sync off
 * 1 - Tx FIFO auto sync on
 */

#define BP_SPDIF_SCR_TXAUTOSYNC      17
#define BM_SPDIF_SCR_TXAUTOSYNC      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_TXAUTOSYNC(v)   ((((reg32_t) v) << 17) & BM_SPDIF_SCR_TXAUTOSYNC)
#else
#define BF_SPDIF_SCR_TXAUTOSYNC(v)   (((v) << 17) & BM_SPDIF_SCR_TXAUTOSYNC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXAUTOSYNC field to a new value.
#define BW_SPDIF_SCR_TXAUTOSYNC(v)   BF_CS1(SPDIF_SCR, TXAUTOSYNC, v)
#endif


/* --- Register HW_SPDIF_SCR, field RXAUTOSYNC (RW)
 *

 *
 * Values:
 * 0 - Rx FIFO auto sync off
 * 1 - RxFIFO auto sync on
 */

#define BP_SPDIF_SCR_RXAUTOSYNC      18
#define BM_SPDIF_SCR_RXAUTOSYNC      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_RXAUTOSYNC(v)   ((((reg32_t) v) << 18) & BM_SPDIF_SCR_RXAUTOSYNC)
#else
#define BF_SPDIF_SCR_RXAUTOSYNC(v)   (((v) << 18) & BM_SPDIF_SCR_RXAUTOSYNC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXAUTOSYNC field to a new value.
#define BW_SPDIF_SCR_RXAUTOSYNC(v)   BF_CS1(SPDIF_SCR, RXAUTOSYNC, v)
#endif


/* --- Register HW_SPDIF_SCR, field RXFIFOFULL_SEL (RW)
 *

 *
 * Values:
 * 00 - Full interrupt if at least 1 sample in Rx left and right FIFOs
 * 01 - Full interrupt if at least 4 sample in Rx left and right FIFOs
 * 10 - Full interrupt if at least 8 sample in Rx left and right FIFOs
 * 11 - Full interrupt if at least 16 sample in Rx left and right FIFO
 */

#define BP_SPDIF_SCR_RXFIFOFULL_SEL      19
#define BM_SPDIF_SCR_RXFIFOFULL_SEL      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_RXFIFOFULL_SEL(v)   ((((reg32_t) v) << 19) & BM_SPDIF_SCR_RXFIFOFULL_SEL)
#else
#define BF_SPDIF_SCR_RXFIFOFULL_SEL(v)   (((v) << 19) & BM_SPDIF_SCR_RXFIFOFULL_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFOFULL_SEL field to a new value.
#define BW_SPDIF_SCR_RXFIFOFULL_SEL(v)   BF_CS1(SPDIF_SCR, RXFIFOFULL_SEL, v)
#endif


/* --- Register HW_SPDIF_SCR, field RXFIFO_RST (RW)
 *

 *
 * Values:
 * 0 - Normal operation
 * 1 - Reset register to 1 sample remaining
 */

#define BP_SPDIF_SCR_RXFIFO_RST      21
#define BM_SPDIF_SCR_RXFIFO_RST      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_RXFIFO_RST(v)   ((((reg32_t) v) << 21) & BM_SPDIF_SCR_RXFIFO_RST)
#else
#define BF_SPDIF_SCR_RXFIFO_RST(v)   (((v) << 21) & BM_SPDIF_SCR_RXFIFO_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFO_RST field to a new value.
#define BW_SPDIF_SCR_RXFIFO_RST(v)   BF_CS1(SPDIF_SCR, RXFIFO_RST, v)
#endif


/* --- Register HW_SPDIF_SCR, field RXFIFO_OFF (RW)
 *

 *
 * Values:
 * 0 - SPDIF Rx FIFO is on
 * 1 - SPDIF Rx FIFO is off. Does not accept data from interface
 */

#define BP_SPDIF_SCR_RXFIFO_OFF      22
#define BM_SPDIF_SCR_RXFIFO_OFF      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_RXFIFO_OFF(v)   ((((reg32_t) v) << 22) & BM_SPDIF_SCR_RXFIFO_OFF)
#else
#define BF_SPDIF_SCR_RXFIFO_OFF(v)   (((v) << 22) & BM_SPDIF_SCR_RXFIFO_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFO_OFF field to a new value.
#define BW_SPDIF_SCR_RXFIFO_OFF(v)   BF_CS1(SPDIF_SCR, RXFIFO_OFF, v)
#endif


/* --- Register HW_SPDIF_SCR, field RXFIFO_CTRL (RW)
 *

 *
 * Values:
 * 0 - Normal operation
 * 1 - Always read zero from Rx data register
 */

#define BP_SPDIF_SCR_RXFIFO_CTRL      23
#define BM_SPDIF_SCR_RXFIFO_CTRL      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SCR_RXFIFO_CTRL(v)   ((((reg32_t) v) << 23) & BM_SPDIF_SCR_RXFIFO_CTRL)
#else
#define BF_SPDIF_SCR_RXFIFO_CTRL(v)   (((v) << 23) & BM_SPDIF_SCR_RXFIFO_CTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFO_CTRL field to a new value.
#define BW_SPDIF_SCR_RXFIFO_CTRL(v)   BF_CS1(SPDIF_SCR, RXFIFO_CTRL, v)
#endif


/* --- Register HW_SPDIF_SCR, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SCR_UNIMPLEMENTED      24
#define BM_SPDIF_SCR_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRCD - CDText Control Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned USYNCMODE : 1; //!< 
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RESERVED2 : 5; //!< Return zeros when read
        unsigned RESERVED3 : 7; //!< Reserved
        unsigned RESERVED4 : 9; //!< Return zeros when read
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_srcd_t;
#endif

/*
 * constants & macros for entire SPDIF_SRCD register
 */
#define HW_SPDIF_SRCD_ADDR      (REGS_SPDIF_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRCD           (*(volatile hw_spdif_srcd_t *) HW_SPDIF_SRCD_ADDR)
#define HW_SPDIF_SRCD_RD()      (HW_SPDIF_SRCD.U)
#define HW_SPDIF_SRCD_WR(v)     (HW_SPDIF_SRCD.U = (v))
#define HW_SPDIF_SRCD_SET(v)    (HW_SPDIF_SRCD_WR(HW_SPDIF_SRCD_RD() |  (v)))
#define HW_SPDIF_SRCD_CLR(v)    (HW_SPDIF_SRCD_WR(HW_SPDIF_SRCD_RD() & ~(v)))
#define HW_SPDIF_SRCD_TOG(v)    (HW_SPDIF_SRCD_WR(HW_SPDIF_SRCD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDIF_SRCD bitfields
 */

/* --- Register HW_SPDIF_SRCD, field USYNCMODE (RW)
 *

 *
 * Values:
 * 0 - Non-CD data
 * 1 - CD user channel subcode
 */

#define BP_SPDIF_SRCD_USYNCMODE      1
#define BM_SPDIF_SRCD_USYNCMODE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SRCD_USYNCMODE(v)   ((((reg32_t) v) << 1) & BM_SPDIF_SRCD_USYNCMODE)
#else
#define BF_SPDIF_SRCD_USYNCMODE(v)   (((v) << 1) & BM_SPDIF_SRCD_USYNCMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the USYNCMODE field to a new value.
#define BW_SPDIF_SRCD_USYNCMODE(v)   BF_CS1(SPDIF_SRCD, USYNCMODE, v)
#endif


/* --- Register HW_SPDIF_SRCD, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SRCD_UNIMPLEMENTED      24
#define BM_SPDIF_SRCD_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRPC - PhaseConfig Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 3; //!< Reserved, return zeros when read
        unsigned GAINSEL : 3; //!< Gain selection:
        unsigned LOCK : 1; //!< LOCK bit to show that the internal DPLL is locked, read only
        unsigned CLKSRC_SEL : 4; //!< Clock source selection, all other settings not shown are reserved:
        unsigned RESERVED1 : 13; //!< Reserved, return zeros when read
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_srpc_t;
#endif

/*
 * constants & macros for entire SPDIF_SRPC register
 */
#define HW_SPDIF_SRPC_ADDR      (REGS_SPDIF_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRPC           (*(volatile hw_spdif_srpc_t *) HW_SPDIF_SRPC_ADDR)
#define HW_SPDIF_SRPC_RD()      (HW_SPDIF_SRPC.U)
#define HW_SPDIF_SRPC_WR(v)     (HW_SPDIF_SRPC.U = (v))
#define HW_SPDIF_SRPC_SET(v)    (HW_SPDIF_SRPC_WR(HW_SPDIF_SRPC_RD() |  (v)))
#define HW_SPDIF_SRPC_CLR(v)    (HW_SPDIF_SRPC_WR(HW_SPDIF_SRPC_RD() & ~(v)))
#define HW_SPDIF_SRPC_TOG(v)    (HW_SPDIF_SRPC_WR(HW_SPDIF_SRPC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDIF_SRPC bitfields
 */

/* --- Register HW_SPDIF_SRPC, field GAINSEL (RW)
 *
 * Gain selection:
 *
 * Values:
 * 000 - 24*2**10
 * 001 - 16*2**10
 * 010 - 12*2**10
 * 011 - 8*2**10
 * 100 - 6*2**10
 * 101 - 4*2**10
 * 110 - 3*2**10
 */

#define BP_SPDIF_SRPC_GAINSEL      3
#define BM_SPDIF_SRPC_GAINSEL      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SRPC_GAINSEL(v)   ((((reg32_t) v) << 3) & BM_SPDIF_SRPC_GAINSEL)
#else
#define BF_SPDIF_SRPC_GAINSEL(v)   (((v) << 3) & BM_SPDIF_SRPC_GAINSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GAINSEL field to a new value.
#define BW_SPDIF_SRPC_GAINSEL(v)   BF_CS1(SPDIF_SRPC, GAINSEL, v)
#endif


/* --- Register HW_SPDIF_SRPC, field LOCK (RO)
 *
 * LOCK bit to show that the internal DPLL is locked, read only
 */

#define BP_SPDIF_SRPC_LOCK      6
#define BM_SPDIF_SRPC_LOCK      0x00000040

/* --- Register HW_SPDIF_SRPC, field CLKSRC_SEL (RW)
 *
 * Clock source selection, all other settings not shown are reserved:
 *
 * Values:
 * 0000 - if (DPLL Locked) SPDIF_RxClk else extal
 * 0001 - if (DPLL Locked) SPDIF_RxClk else spdif_clk
 * 0010 - if (DPLL Locked) SPDIF_RxClk else asrc_clk
 * 0011 - if (DPLL Locked) SPDIF_RxClk else spdif_extclk
 * 0100 - if (DPLL Locked) SPDIF_Rxclk else esai_hckt
 * 0101 - extal_clk
 * 0110 - spdif_clk
 * 0111 - asrc_clk
 * 1000 - spdif_extclk
 * 1001 - esai_hckt
 * 1010 - if (DPLL Locked) SPDIF_RxClk else mlb_clk
 * 1011 - if (DPLL Locked) SPDIF_RxClk else mlb_phy_clk
 * 1100 - mkb_clk
 * 1101 - mlb_phy_clk
 */

#define BP_SPDIF_SRPC_CLKSRC_SEL      7
#define BM_SPDIF_SRPC_CLKSRC_SEL      0x00000780

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SRPC_CLKSRC_SEL(v)   ((((reg32_t) v) << 7) & BM_SPDIF_SRPC_CLKSRC_SEL)
#else
#define BF_SPDIF_SRPC_CLKSRC_SEL(v)   (((v) << 7) & BM_SPDIF_SRPC_CLKSRC_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKSRC_SEL field to a new value.
#define BW_SPDIF_SRPC_CLKSRC_SEL(v)   BF_CS1(SPDIF_SRPC, CLKSRC_SEL, v)
#endif


/* --- Register HW_SPDIF_SRPC, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SRPC_UNIMPLEMENTED      24
#define BM_SPDIF_SRPC_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SIE - InterruptEn Register (RW)
 *
 * The InterruptEn register (SPDIF_SIE) provides control over the enabling of interrupts.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXFIFOFUL : 1; //!< SPDIF Rx FIFO full, can't be cleared with reg. IntClear. To clear it, read from Rx FIFO.
        unsigned TXEM : 1; //!< SPDIF Tx FIFO empty, can't be cleared with reg. IntClear. To clear it, write toTx FIFO.
        unsigned LOCKLOSS : 1; //!< SPDIF receiver loss of lock
        unsigned RXFIFORESYN : 1; //!< Rx FIFO resync
        unsigned RXFIFOUNOV : 1; //!< Rx FIFO underrun/overrun
        unsigned UQERR : 1; //!< U/Q Channel framing error
        unsigned UQSYNC : 1; //!< U/Q Channel sync found
        unsigned QRXOV : 1; //!< Q Channel receive register overrun
        unsigned QRXFUL : 1; //!< Q Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from Q Rx reg.
        unsigned URXOV : 1; //!< U Channel receive register overrun
        unsigned URXFUL : 1; //!< U Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from U Rx reg.
        unsigned RESERVED0 : 3; //!< Reserved. Return zeros when read
        unsigned BITERR : 1; //!< SPDIF receiver found parity bit error
        unsigned SYMERR : 1; //!< SPDIF receiver found illegal symbol
        unsigned VALNOGOOD : 1; //!< SPDIF validity flag no good
        unsigned CNEW : 1; //!< SPDIF receive change in value of control channel
        unsigned TXRESYN : 1; //!< SPDIF Tx FIFO resync
        unsigned TXUNOV : 1; //!< SPDIF Tx FIFO under/overrun
        unsigned LOCK : 1; //!< SPDIF receiver's DPLL is locked
        unsigned RESERVED1 : 2; //!< Reserved, for InterruptStat/Clear return zeros when read, for InterruptEn, bit 23 also read zero
        unsigned RESERVED2 : 1; //!< Reserved, for InterruptStat/Clear return zeros when read, for InterruptEn, bit 23 also read zero
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_sie_t;
#endif

/*
 * constants & macros for entire SPDIF_SIE register
 */
#define HW_SPDIF_SIE_ADDR      (REGS_SPDIF_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SIE           (*(volatile hw_spdif_sie_t *) HW_SPDIF_SIE_ADDR)
#define HW_SPDIF_SIE_RD()      (HW_SPDIF_SIE.U)
#define HW_SPDIF_SIE_WR(v)     (HW_SPDIF_SIE.U = (v))
#define HW_SPDIF_SIE_SET(v)    (HW_SPDIF_SIE_WR(HW_SPDIF_SIE_RD() |  (v)))
#define HW_SPDIF_SIE_CLR(v)    (HW_SPDIF_SIE_WR(HW_SPDIF_SIE_RD() & ~(v)))
#define HW_SPDIF_SIE_TOG(v)    (HW_SPDIF_SIE_WR(HW_SPDIF_SIE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDIF_SIE bitfields
 */

/* --- Register HW_SPDIF_SIE, field RXFIFOFUL (RW)
 *
 * SPDIF Rx FIFO full, can't be cleared with reg. IntClear. To clear it, read from Rx FIFO.
 */

#define BP_SPDIF_SIE_RXFIFOFUL      0
#define BM_SPDIF_SIE_RXFIFOFUL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_RXFIFOFUL(v)   ((((reg32_t) v) << 0) & BM_SPDIF_SIE_RXFIFOFUL)
#else
#define BF_SPDIF_SIE_RXFIFOFUL(v)   (((v) << 0) & BM_SPDIF_SIE_RXFIFOFUL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFOFUL field to a new value.
#define BW_SPDIF_SIE_RXFIFOFUL(v)   BF_CS1(SPDIF_SIE, RXFIFOFUL, v)
#endif

/* --- Register HW_SPDIF_SIE, field TXEM (RW)
 *
 * SPDIF Tx FIFO empty, can't be cleared with reg. IntClear. To clear it, write toTx FIFO.
 */

#define BP_SPDIF_SIE_TXEM      1
#define BM_SPDIF_SIE_TXEM      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_TXEM(v)   ((((reg32_t) v) << 1) & BM_SPDIF_SIE_TXEM)
#else
#define BF_SPDIF_SIE_TXEM(v)   (((v) << 1) & BM_SPDIF_SIE_TXEM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXEM field to a new value.
#define BW_SPDIF_SIE_TXEM(v)   BF_CS1(SPDIF_SIE, TXEM, v)
#endif

/* --- Register HW_SPDIF_SIE, field LOCKLOSS (RW)
 *
 * SPDIF receiver loss of lock
 */

#define BP_SPDIF_SIE_LOCKLOSS      2
#define BM_SPDIF_SIE_LOCKLOSS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_LOCKLOSS(v)   ((((reg32_t) v) << 2) & BM_SPDIF_SIE_LOCKLOSS)
#else
#define BF_SPDIF_SIE_LOCKLOSS(v)   (((v) << 2) & BM_SPDIF_SIE_LOCKLOSS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCKLOSS field to a new value.
#define BW_SPDIF_SIE_LOCKLOSS(v)   BF_CS1(SPDIF_SIE, LOCKLOSS, v)
#endif

/* --- Register HW_SPDIF_SIE, field RXFIFORESYN (RW)
 *
 * Rx FIFO resync
 */

#define BP_SPDIF_SIE_RXFIFORESYN      3
#define BM_SPDIF_SIE_RXFIFORESYN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_RXFIFORESYN(v)   ((((reg32_t) v) << 3) & BM_SPDIF_SIE_RXFIFORESYN)
#else
#define BF_SPDIF_SIE_RXFIFORESYN(v)   (((v) << 3) & BM_SPDIF_SIE_RXFIFORESYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFORESYN field to a new value.
#define BW_SPDIF_SIE_RXFIFORESYN(v)   BF_CS1(SPDIF_SIE, RXFIFORESYN, v)
#endif

/* --- Register HW_SPDIF_SIE, field RXFIFOUNOV (RW)
 *
 * Rx FIFO underrun/overrun
 */

#define BP_SPDIF_SIE_RXFIFOUNOV      4
#define BM_SPDIF_SIE_RXFIFOUNOV      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_RXFIFOUNOV(v)   ((((reg32_t) v) << 4) & BM_SPDIF_SIE_RXFIFOUNOV)
#else
#define BF_SPDIF_SIE_RXFIFOUNOV(v)   (((v) << 4) & BM_SPDIF_SIE_RXFIFOUNOV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFOUNOV field to a new value.
#define BW_SPDIF_SIE_RXFIFOUNOV(v)   BF_CS1(SPDIF_SIE, RXFIFOUNOV, v)
#endif

/* --- Register HW_SPDIF_SIE, field UQERR (RW)
 *
 * U/Q Channel framing error
 */

#define BP_SPDIF_SIE_UQERR      5
#define BM_SPDIF_SIE_UQERR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_UQERR(v)   ((((reg32_t) v) << 5) & BM_SPDIF_SIE_UQERR)
#else
#define BF_SPDIF_SIE_UQERR(v)   (((v) << 5) & BM_SPDIF_SIE_UQERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UQERR field to a new value.
#define BW_SPDIF_SIE_UQERR(v)   BF_CS1(SPDIF_SIE, UQERR, v)
#endif

/* --- Register HW_SPDIF_SIE, field UQSYNC (RW)
 *
 * U/Q Channel sync found
 */

#define BP_SPDIF_SIE_UQSYNC      6
#define BM_SPDIF_SIE_UQSYNC      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_UQSYNC(v)   ((((reg32_t) v) << 6) & BM_SPDIF_SIE_UQSYNC)
#else
#define BF_SPDIF_SIE_UQSYNC(v)   (((v) << 6) & BM_SPDIF_SIE_UQSYNC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UQSYNC field to a new value.
#define BW_SPDIF_SIE_UQSYNC(v)   BF_CS1(SPDIF_SIE, UQSYNC, v)
#endif

/* --- Register HW_SPDIF_SIE, field QRXOV (RW)
 *
 * Q Channel receive register overrun
 */

#define BP_SPDIF_SIE_QRXOV      7
#define BM_SPDIF_SIE_QRXOV      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_QRXOV(v)   ((((reg32_t) v) << 7) & BM_SPDIF_SIE_QRXOV)
#else
#define BF_SPDIF_SIE_QRXOV(v)   (((v) << 7) & BM_SPDIF_SIE_QRXOV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the QRXOV field to a new value.
#define BW_SPDIF_SIE_QRXOV(v)   BF_CS1(SPDIF_SIE, QRXOV, v)
#endif

/* --- Register HW_SPDIF_SIE, field QRXFUL (RW)
 *
 * Q Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from Q Rx
 * reg.
 */

#define BP_SPDIF_SIE_QRXFUL      8
#define BM_SPDIF_SIE_QRXFUL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_QRXFUL(v)   ((((reg32_t) v) << 8) & BM_SPDIF_SIE_QRXFUL)
#else
#define BF_SPDIF_SIE_QRXFUL(v)   (((v) << 8) & BM_SPDIF_SIE_QRXFUL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the QRXFUL field to a new value.
#define BW_SPDIF_SIE_QRXFUL(v)   BF_CS1(SPDIF_SIE, QRXFUL, v)
#endif

/* --- Register HW_SPDIF_SIE, field URXOV (RW)
 *
 * U Channel receive register overrun
 */

#define BP_SPDIF_SIE_URXOV      9
#define BM_SPDIF_SIE_URXOV      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_URXOV(v)   ((((reg32_t) v) << 9) & BM_SPDIF_SIE_URXOV)
#else
#define BF_SPDIF_SIE_URXOV(v)   (((v) << 9) & BM_SPDIF_SIE_URXOV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URXOV field to a new value.
#define BW_SPDIF_SIE_URXOV(v)   BF_CS1(SPDIF_SIE, URXOV, v)
#endif

/* --- Register HW_SPDIF_SIE, field URXFUL (RW)
 *
 * U Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from U Rx
 * reg.
 */

#define BP_SPDIF_SIE_URXFUL      10
#define BM_SPDIF_SIE_URXFUL      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_URXFUL(v)   ((((reg32_t) v) << 10) & BM_SPDIF_SIE_URXFUL)
#else
#define BF_SPDIF_SIE_URXFUL(v)   (((v) << 10) & BM_SPDIF_SIE_URXFUL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URXFUL field to a new value.
#define BW_SPDIF_SIE_URXFUL(v)   BF_CS1(SPDIF_SIE, URXFUL, v)
#endif

/* --- Register HW_SPDIF_SIE, field BITERR (RW)
 *
 * SPDIF receiver found parity bit error
 */

#define BP_SPDIF_SIE_BITERR      14
#define BM_SPDIF_SIE_BITERR      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_BITERR(v)   ((((reg32_t) v) << 14) & BM_SPDIF_SIE_BITERR)
#else
#define BF_SPDIF_SIE_BITERR(v)   (((v) << 14) & BM_SPDIF_SIE_BITERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BITERR field to a new value.
#define BW_SPDIF_SIE_BITERR(v)   BF_CS1(SPDIF_SIE, BITERR, v)
#endif

/* --- Register HW_SPDIF_SIE, field SYMERR (RW)
 *
 * SPDIF receiver found illegal symbol
 */

#define BP_SPDIF_SIE_SYMERR      15
#define BM_SPDIF_SIE_SYMERR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_SYMERR(v)   ((((reg32_t) v) << 15) & BM_SPDIF_SIE_SYMERR)
#else
#define BF_SPDIF_SIE_SYMERR(v)   (((v) << 15) & BM_SPDIF_SIE_SYMERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYMERR field to a new value.
#define BW_SPDIF_SIE_SYMERR(v)   BF_CS1(SPDIF_SIE, SYMERR, v)
#endif

/* --- Register HW_SPDIF_SIE, field VALNOGOOD (RW)
 *
 * SPDIF validity flag no good
 */

#define BP_SPDIF_SIE_VALNOGOOD      16
#define BM_SPDIF_SIE_VALNOGOOD      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_VALNOGOOD(v)   ((((reg32_t) v) << 16) & BM_SPDIF_SIE_VALNOGOOD)
#else
#define BF_SPDIF_SIE_VALNOGOOD(v)   (((v) << 16) & BM_SPDIF_SIE_VALNOGOOD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALNOGOOD field to a new value.
#define BW_SPDIF_SIE_VALNOGOOD(v)   BF_CS1(SPDIF_SIE, VALNOGOOD, v)
#endif

/* --- Register HW_SPDIF_SIE, field CNEW (RW)
 *
 * SPDIF receive change in value of control channel
 */

#define BP_SPDIF_SIE_CNEW      17
#define BM_SPDIF_SIE_CNEW      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_CNEW(v)   ((((reg32_t) v) << 17) & BM_SPDIF_SIE_CNEW)
#else
#define BF_SPDIF_SIE_CNEW(v)   (((v) << 17) & BM_SPDIF_SIE_CNEW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNEW field to a new value.
#define BW_SPDIF_SIE_CNEW(v)   BF_CS1(SPDIF_SIE, CNEW, v)
#endif

/* --- Register HW_SPDIF_SIE, field TXRESYN (RW)
 *
 * SPDIF Tx FIFO resync
 */

#define BP_SPDIF_SIE_TXRESYN      18
#define BM_SPDIF_SIE_TXRESYN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_TXRESYN(v)   ((((reg32_t) v) << 18) & BM_SPDIF_SIE_TXRESYN)
#else
#define BF_SPDIF_SIE_TXRESYN(v)   (((v) << 18) & BM_SPDIF_SIE_TXRESYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRESYN field to a new value.
#define BW_SPDIF_SIE_TXRESYN(v)   BF_CS1(SPDIF_SIE, TXRESYN, v)
#endif

/* --- Register HW_SPDIF_SIE, field TXUNOV (RW)
 *
 * SPDIF Tx FIFO under/overrun
 */

#define BP_SPDIF_SIE_TXUNOV      19
#define BM_SPDIF_SIE_TXUNOV      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_TXUNOV(v)   ((((reg32_t) v) << 19) & BM_SPDIF_SIE_TXUNOV)
#else
#define BF_SPDIF_SIE_TXUNOV(v)   (((v) << 19) & BM_SPDIF_SIE_TXUNOV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXUNOV field to a new value.
#define BW_SPDIF_SIE_TXUNOV(v)   BF_CS1(SPDIF_SIE, TXUNOV, v)
#endif

/* --- Register HW_SPDIF_SIE, field LOCK (RW)
 *
 * SPDIF receiver's DPLL is locked
 */

#define BP_SPDIF_SIE_LOCK      20
#define BM_SPDIF_SIE_LOCK      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_SIE_LOCK(v)   ((((reg32_t) v) << 20) & BM_SPDIF_SIE_LOCK)
#else
#define BF_SPDIF_SIE_LOCK(v)   (((v) << 20) & BM_SPDIF_SIE_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK field to a new value.
#define BW_SPDIF_SIE_LOCK(v)   BF_CS1(SPDIF_SIE, LOCK, v)
#endif

/* --- Register HW_SPDIF_SIE, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SIE_UNIMPLEMENTED      24
#define BM_SPDIF_SIE_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SIS - InterruptStat Register (RO)
 *
 * The InterruptStat (SPDIF_SIS) register is a read only register that provides the status on
 * interrupt operations.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXFIFOFUL : 1; //!< SPDIF Rx FIFO full, can't be cleared with reg. IntClear. To clear it, read from Rx FIFO.
        unsigned TXEM : 1; //!< SPDIF Tx FIFO empty, can't be cleared with reg. IntClear. To clear it, write toTx FIFO.
        unsigned LOCKLOSS : 1; //!< SPDIF receiver loss of lock
        unsigned RXFIFORESYN : 1; //!< Rx FIFO resync
        unsigned RXFIFOUNOV : 1; //!< Rx FIFO underrun/overrun
        unsigned UQERR : 1; //!< U/Q Channel framing error
        unsigned UQSYNC : 1; //!< U/Q Channel sync found
        unsigned QRXOV : 1; //!< Q Channel receive register overrun
        unsigned QRXFUL : 1; //!< Q Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from Q Rx reg.
        unsigned URXOV : 1; //!< U Channel receive register overrun
        unsigned URXFUL : 1; //!< U Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from U Rx reg.
        unsigned RESERVED0 : 3; //!< Reserved. Return zeros when read
        unsigned BITERR : 1; //!< SPDIF receiver found parity bit error
        unsigned SYMERR : 1; //!< SPDIF receiver found illegal symbol
        unsigned VALNOGOOD : 1; //!< SPDIF validity flag no good
        unsigned CNEW : 1; //!< SPDIF receive change in value of control channel
        unsigned TXRESYN : 1; //!< SPDIF Tx FIFO resync
        unsigned TXUNOV : 1; //!< SPDIF Tx FIFO under/overrun
        unsigned LOCK : 1; //!< SPDIF receiver's DPLL is locked
        unsigned RESERVED1 : 3; //!< Reserved, for InterruptStat/Clear return zeros when read.
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_sis_t;
#endif

/*
 * constants & macros for entire SPDIF_SIS register
 */
#define HW_SPDIF_SIS_ADDR      (REGS_SPDIF_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SIS           (*(volatile hw_spdif_sis_t *) HW_SPDIF_SIS_ADDR)
#define HW_SPDIF_SIS_RD()      (HW_SPDIF_SIS.U)
#endif

/*
 * constants & macros for individual SPDIF_SIS bitfields
 */

/* --- Register HW_SPDIF_SIS, field RXFIFOFUL (RO)
 *
 * SPDIF Rx FIFO full, can't be cleared with reg. IntClear. To clear it, read from Rx FIFO.
 */

#define BP_SPDIF_SIS_RXFIFOFUL      0
#define BM_SPDIF_SIS_RXFIFOFUL      0x00000001

/* --- Register HW_SPDIF_SIS, field TXEM (RO)
 *
 * SPDIF Tx FIFO empty, can't be cleared with reg. IntClear. To clear it, write toTx FIFO.
 */

#define BP_SPDIF_SIS_TXEM      1
#define BM_SPDIF_SIS_TXEM      0x00000002

/* --- Register HW_SPDIF_SIS, field LOCKLOSS (RO)
 *
 * SPDIF receiver loss of lock
 */

#define BP_SPDIF_SIS_LOCKLOSS      2
#define BM_SPDIF_SIS_LOCKLOSS      0x00000004

/* --- Register HW_SPDIF_SIS, field RXFIFORESYN (RO)
 *
 * Rx FIFO resync
 */

#define BP_SPDIF_SIS_RXFIFORESYN      3
#define BM_SPDIF_SIS_RXFIFORESYN      0x00000008

/* --- Register HW_SPDIF_SIS, field RXFIFOUNOV (RO)
 *
 * Rx FIFO underrun/overrun
 */

#define BP_SPDIF_SIS_RXFIFOUNOV      4
#define BM_SPDIF_SIS_RXFIFOUNOV      0x00000010

/* --- Register HW_SPDIF_SIS, field UQERR (RO)
 *
 * U/Q Channel framing error
 */

#define BP_SPDIF_SIS_UQERR      5
#define BM_SPDIF_SIS_UQERR      0x00000020

/* --- Register HW_SPDIF_SIS, field UQSYNC (RO)
 *
 * U/Q Channel sync found
 */

#define BP_SPDIF_SIS_UQSYNC      6
#define BM_SPDIF_SIS_UQSYNC      0x00000040

/* --- Register HW_SPDIF_SIS, field QRXOV (RO)
 *
 * Q Channel receive register overrun
 */

#define BP_SPDIF_SIS_QRXOV      7
#define BM_SPDIF_SIS_QRXOV      0x00000080

/* --- Register HW_SPDIF_SIS, field QRXFUL (RO)
 *
 * Q Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from Q Rx
 * reg.
 */

#define BP_SPDIF_SIS_QRXFUL      8
#define BM_SPDIF_SIS_QRXFUL      0x00000100

/* --- Register HW_SPDIF_SIS, field URXOV (RO)
 *
 * U Channel receive register overrun
 */

#define BP_SPDIF_SIS_URXOV      9
#define BM_SPDIF_SIS_URXOV      0x00000200

/* --- Register HW_SPDIF_SIS, field URXFUL (RO)
 *
 * U Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from U Rx
 * reg.
 */

#define BP_SPDIF_SIS_URXFUL      10
#define BM_SPDIF_SIS_URXFUL      0x00000400

/* --- Register HW_SPDIF_SIS, field BITERR (RO)
 *
 * SPDIF receiver found parity bit error
 */

#define BP_SPDIF_SIS_BITERR      14
#define BM_SPDIF_SIS_BITERR      0x00004000

/* --- Register HW_SPDIF_SIS, field SYMERR (RO)
 *
 * SPDIF receiver found illegal symbol
 */

#define BP_SPDIF_SIS_SYMERR      15
#define BM_SPDIF_SIS_SYMERR      0x00008000

/* --- Register HW_SPDIF_SIS, field VALNOGOOD (RO)
 *
 * SPDIF validity flag no good
 */

#define BP_SPDIF_SIS_VALNOGOOD      16
#define BM_SPDIF_SIS_VALNOGOOD      0x00010000

/* --- Register HW_SPDIF_SIS, field CNEW (RO)
 *
 * SPDIF receive change in value of control channel
 */

#define BP_SPDIF_SIS_CNEW      17
#define BM_SPDIF_SIS_CNEW      0x00020000

/* --- Register HW_SPDIF_SIS, field TXRESYN (RO)
 *
 * SPDIF Tx FIFO resync
 */

#define BP_SPDIF_SIS_TXRESYN      18
#define BM_SPDIF_SIS_TXRESYN      0x00040000

/* --- Register HW_SPDIF_SIS, field TXUNOV (RO)
 *
 * SPDIF Tx FIFO under/overrun
 */

#define BP_SPDIF_SIS_TXUNOV      19
#define BM_SPDIF_SIS_TXUNOV      0x00080000

/* --- Register HW_SPDIF_SIS, field LOCK (RO)
 *
 * SPDIF receiver's DPLL is locked
 */

#define BP_SPDIF_SIS_LOCK      20
#define BM_SPDIF_SIS_LOCK      0x00100000

/* --- Register HW_SPDIF_SIS, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SIS_UNIMPLEMENTED      24
#define BM_SPDIF_SIS_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRL - SPDIFRxLeft Register (RO)
 *
 * SPDIFRxLeft register is an audio data reception register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXDATALEFT : 24; //!< Processor receive SPDIF data left
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_srl_t;
#endif

/*
 * constants & macros for entire SPDIF_SRL register
 */
#define HW_SPDIF_SRL_ADDR      (REGS_SPDIF_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRL           (*(volatile hw_spdif_srl_t *) HW_SPDIF_SRL_ADDR)
#define HW_SPDIF_SRL_RD()      (HW_SPDIF_SRL.U)
#endif

/*
 * constants & macros for individual SPDIF_SRL bitfields
 */

/* --- Register HW_SPDIF_SRL, field RXDATALEFT (RO)
 *
 * Processor receive SPDIF data left
 */

#define BP_SPDIF_SRL_RXDATALEFT      0
#define BM_SPDIF_SRL_RXDATALEFT      0x00ffffff

/* --- Register HW_SPDIF_SRL, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SRL_UNIMPLEMENTED      24
#define BM_SPDIF_SRL_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRR - SPDIFRxRight Register (RO)
 *
 * SPDIFRxRight register is an audio data reception register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXDATARIGHT : 24; //!< Processor receive SPDIF data right
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_srr_t;
#endif

/*
 * constants & macros for entire SPDIF_SRR register
 */
#define HW_SPDIF_SRR_ADDR      (REGS_SPDIF_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRR           (*(volatile hw_spdif_srr_t *) HW_SPDIF_SRR_ADDR)
#define HW_SPDIF_SRR_RD()      (HW_SPDIF_SRR.U)
#endif

/*
 * constants & macros for individual SPDIF_SRR bitfields
 */

/* --- Register HW_SPDIF_SRR, field RXDATARIGHT (RO)
 *
 * Processor receive SPDIF data right
 */

#define BP_SPDIF_SRR_RXDATARIGHT      0
#define BM_SPDIF_SRR_RXDATARIGHT      0x00ffffff

/* --- Register HW_SPDIF_SRR, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SRR_UNIMPLEMENTED      24
#define BM_SPDIF_SRR_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRCSH - SPDIFRxCChannel_h Register (RO)
 *
 * SPDIFRxCChannel_h register is a channel status reception register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXCCHANNEL_H : 24; //!< SPDIF receive C channel register, contains first 24 bits of C channel without interpretation
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_srcsh_t;
#endif

/*
 * constants & macros for entire SPDIF_SRCSH register
 */
#define HW_SPDIF_SRCSH_ADDR      (REGS_SPDIF_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRCSH           (*(volatile hw_spdif_srcsh_t *) HW_SPDIF_SRCSH_ADDR)
#define HW_SPDIF_SRCSH_RD()      (HW_SPDIF_SRCSH.U)
#endif

/*
 * constants & macros for individual SPDIF_SRCSH bitfields
 */

/* --- Register HW_SPDIF_SRCSH, field RXCCHANNEL_H (RO)
 *
 * SPDIF receive C channel register, contains first 24 bits of C channel without interpretation
 */

#define BP_SPDIF_SRCSH_RXCCHANNEL_H      0
#define BM_SPDIF_SRCSH_RXCCHANNEL_H      0x00ffffff

/* --- Register HW_SPDIF_SRCSH, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SRCSH_UNIMPLEMENTED      24
#define BM_SPDIF_SRCSH_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRCSL - SPDIFRxCChannel_l Register (RO)
 *
 * SPDIFRxCChannel_l register is a channel status reception register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXCCHANNEL_L : 24; //!< SPDIF receive C channel register, contains next 24 bits of C channel without interpretation
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_srcsl_t;
#endif

/*
 * constants & macros for entire SPDIF_SRCSL register
 */
#define HW_SPDIF_SRCSL_ADDR      (REGS_SPDIF_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRCSL           (*(volatile hw_spdif_srcsl_t *) HW_SPDIF_SRCSL_ADDR)
#define HW_SPDIF_SRCSL_RD()      (HW_SPDIF_SRCSL.U)
#endif

/*
 * constants & macros for individual SPDIF_SRCSL bitfields
 */

/* --- Register HW_SPDIF_SRCSL, field RXCCHANNEL_L (RO)
 *
 * SPDIF receive C channel register, contains next 24 bits of C channel without interpretation
 */

#define BP_SPDIF_SRCSL_RXCCHANNEL_L      0
#define BM_SPDIF_SRCSL_RXCCHANNEL_L      0x00ffffff

/* --- Register HW_SPDIF_SRCSL, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SRCSL_UNIMPLEMENTED      24
#define BM_SPDIF_SRCSL_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRU - UchannelRx Register (RO)
 *
 * UChannelRx register is a user bits reception register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXUCHANNEL : 24; //!< SPDIF receive U channel register, contains next 3 U channel bytes
        unsigned UNIMPLEMENTED : 8; //!< This is a 24-bit register the upper byte is unimplemented.
    } B;
} hw_spdif_sru_t;
#endif

/*
 * constants & macros for entire SPDIF_SRU register
 */
#define HW_SPDIF_SRU_ADDR      (REGS_SPDIF_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRU           (*(volatile hw_spdif_sru_t *) HW_SPDIF_SRU_ADDR)
#define HW_SPDIF_SRU_RD()      (HW_SPDIF_SRU.U)
#endif

/*
 * constants & macros for individual SPDIF_SRU bitfields
 */

/* --- Register HW_SPDIF_SRU, field RXUCHANNEL (RO)
 *
 * SPDIF receive U channel register, contains next 3 U channel bytes
 */

#define BP_SPDIF_SRU_RXUCHANNEL      0
#define BM_SPDIF_SRU_RXUCHANNEL      0x00ffffff

/* --- Register HW_SPDIF_SRU, field UNIMPLEMENTED (RU)
 *
 * This is a 24-bit register the upper byte is unimplemented.
 */

#define BP_SPDIF_SRU_UNIMPLEMENTED      24
#define BM_SPDIF_SRU_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRQ - QchannelRx Register (RO)
 *
 * QChannelRx register is a user bits reception register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXQCHANNEL : 24; //!< SPDIF receive Q channel register, contains next 3 Q channel bytes
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_srq_t;
#endif

/*
 * constants & macros for entire SPDIF_SRQ register
 */
#define HW_SPDIF_SRQ_ADDR      (REGS_SPDIF_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRQ           (*(volatile hw_spdif_srq_t *) HW_SPDIF_SRQ_ADDR)
#define HW_SPDIF_SRQ_RD()      (HW_SPDIF_SRQ.U)
#endif

/*
 * constants & macros for individual SPDIF_SRQ bitfields
 */

/* --- Register HW_SPDIF_SRQ, field RXQCHANNEL (RO)
 *
 * SPDIF receive Q channel register, contains next 3 Q channel bytes
 */

#define BP_SPDIF_SRQ_RXQCHANNEL      0
#define BM_SPDIF_SRQ_RXQCHANNEL      0x00ffffff

/* --- Register HW_SPDIF_SRQ, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SRQ_UNIMPLEMENTED      24
#define BM_SPDIF_SRQ_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STL - SPDIFTxLeft Register (WO)
 *
 * SPDIFTxLeft register is an audio data transmission register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXDATALEFT : 24; //!< SPDIF transmit left channel data. It is write-only, and always returns zeros when read
        unsigned UNIMPLEMENTED : 8; //!< This is a 24-bit register the upper byte is unimplemented.
    } B;
} hw_spdif_stl_t;
#endif

/*
 * constants & macros for entire SPDIF_STL register
 */
#define HW_SPDIF_STL_ADDR      (REGS_SPDIF_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_STL           (*(volatile hw_spdif_stl_t *) HW_SPDIF_STL_ADDR)
#define HW_SPDIF_STL_WR(v)     (HW_SPDIF_STL.U = (v))
#endif

/*
 * constants & macros for individual SPDIF_STL bitfields
 */

/* --- Register HW_SPDIF_STL, field TXDATALEFT (WO)
 *
 * SPDIF transmit left channel data. It is write-only, and always returns zeros when read
 */

#define BP_SPDIF_STL_TXDATALEFT      0
#define BM_SPDIF_STL_TXDATALEFT      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_STL_TXDATALEFT(v)   ((((reg32_t) v) << 0) & BM_SPDIF_STL_TXDATALEFT)
#else
#define BF_SPDIF_STL_TXDATALEFT(v)   (((v) << 0) & BM_SPDIF_STL_TXDATALEFT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXDATALEFT field to a new value.
#define BW_SPDIF_STL_TXDATALEFT(v)   BF_CS1(SPDIF_STL, TXDATALEFT, v)
#endif

/* --- Register HW_SPDIF_STL, field UNIMPLEMENTED (RU)
 *
 * This is a 24-bit register the upper byte is unimplemented.
 */

#define BP_SPDIF_STL_UNIMPLEMENTED      24
#define BM_SPDIF_STL_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STR - SPDIFTxRight Register (WO)
 *
 * SPDIFTxRight register is an audio data transmission register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXDATARIGHT : 24; //!< SPDIF transmit right channel data. It is write-only, and always returns zeros when read
        unsigned UNIMPLEMENTED : 8; //!< This is a 24-bit register the upper byte is unimplemented.
    } B;
} hw_spdif_str_t;
#endif

/*
 * constants & macros for entire SPDIF_STR register
 */
#define HW_SPDIF_STR_ADDR      (REGS_SPDIF_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_STR           (*(volatile hw_spdif_str_t *) HW_SPDIF_STR_ADDR)
#define HW_SPDIF_STR_WR(v)     (HW_SPDIF_STR.U = (v))
#endif

/*
 * constants & macros for individual SPDIF_STR bitfields
 */

/* --- Register HW_SPDIF_STR, field TXDATARIGHT (WO)
 *
 * SPDIF transmit right channel data. It is write-only, and always returns zeros when read
 */

#define BP_SPDIF_STR_TXDATARIGHT      0
#define BM_SPDIF_STR_TXDATARIGHT      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_STR_TXDATARIGHT(v)   ((((reg32_t) v) << 0) & BM_SPDIF_STR_TXDATARIGHT)
#else
#define BF_SPDIF_STR_TXDATARIGHT(v)   (((v) << 0) & BM_SPDIF_STR_TXDATARIGHT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXDATARIGHT field to a new value.
#define BW_SPDIF_STR_TXDATARIGHT(v)   BF_CS1(SPDIF_STR, TXDATARIGHT, v)
#endif

/* --- Register HW_SPDIF_STR, field UNIMPLEMENTED (RU)
 *
 * This is a 24-bit register the upper byte is unimplemented.
 */

#define BP_SPDIF_STR_UNIMPLEMENTED      24
#define BM_SPDIF_STR_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STCSCH - SPDIFTxCChannelCons_h Register (RW)
 *
 * SPDIFTxCChannelCons_h register is a channel status transmission register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXCCHANNELCONS_H : 24; //!< SPDIF transmit Cons. C channel data, contains first 24 bits without interpretation. When read, it returns the latest data written by the processor
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_stcsch_t;
#endif

/*
 * constants & macros for entire SPDIF_STCSCH register
 */
#define HW_SPDIF_STCSCH_ADDR      (REGS_SPDIF_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_STCSCH           (*(volatile hw_spdif_stcsch_t *) HW_SPDIF_STCSCH_ADDR)
#define HW_SPDIF_STCSCH_RD()      (HW_SPDIF_STCSCH.U)
#define HW_SPDIF_STCSCH_WR(v)     (HW_SPDIF_STCSCH.U = (v))
#define HW_SPDIF_STCSCH_SET(v)    (HW_SPDIF_STCSCH_WR(HW_SPDIF_STCSCH_RD() |  (v)))
#define HW_SPDIF_STCSCH_CLR(v)    (HW_SPDIF_STCSCH_WR(HW_SPDIF_STCSCH_RD() & ~(v)))
#define HW_SPDIF_STCSCH_TOG(v)    (HW_SPDIF_STCSCH_WR(HW_SPDIF_STCSCH_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDIF_STCSCH bitfields
 */

/* --- Register HW_SPDIF_STCSCH, field TXCCHANNELCONS_H (RW)
 *
 * SPDIF transmit Cons. C channel data, contains first 24 bits without interpretation. When read, it
 * returns the latest data written by the processor
 */

#define BP_SPDIF_STCSCH_TXCCHANNELCONS_H      0
#define BM_SPDIF_STCSCH_TXCCHANNELCONS_H      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_STCSCH_TXCCHANNELCONS_H(v)   ((((reg32_t) v) << 0) & BM_SPDIF_STCSCH_TXCCHANNELCONS_H)
#else
#define BF_SPDIF_STCSCH_TXCCHANNELCONS_H(v)   (((v) << 0) & BM_SPDIF_STCSCH_TXCCHANNELCONS_H)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCCHANNELCONS_H field to a new value.
#define BW_SPDIF_STCSCH_TXCCHANNELCONS_H(v)   BF_CS1(SPDIF_STCSCH, TXCCHANNELCONS_H, v)
#endif

/* --- Register HW_SPDIF_STCSCH, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_STCSCH_UNIMPLEMENTED      24
#define BM_SPDIF_STCSCH_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STCSCL - SPDIFTxCChannelCons_l Register (RW)
 *
 * SPDIFTxCChannelCons_l register is a channel status transmission register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXCCHANNELCONS_L : 24; //!< SPDIF transmit Cons. C channel data, contains next 24 bits without interpretation. When read, it returns the latest data written by the processor
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_stcscl_t;
#endif

/*
 * constants & macros for entire SPDIF_STCSCL register
 */
#define HW_SPDIF_STCSCL_ADDR      (REGS_SPDIF_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_STCSCL           (*(volatile hw_spdif_stcscl_t *) HW_SPDIF_STCSCL_ADDR)
#define HW_SPDIF_STCSCL_RD()      (HW_SPDIF_STCSCL.U)
#define HW_SPDIF_STCSCL_WR(v)     (HW_SPDIF_STCSCL.U = (v))
#define HW_SPDIF_STCSCL_SET(v)    (HW_SPDIF_STCSCL_WR(HW_SPDIF_STCSCL_RD() |  (v)))
#define HW_SPDIF_STCSCL_CLR(v)    (HW_SPDIF_STCSCL_WR(HW_SPDIF_STCSCL_RD() & ~(v)))
#define HW_SPDIF_STCSCL_TOG(v)    (HW_SPDIF_STCSCL_WR(HW_SPDIF_STCSCL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDIF_STCSCL bitfields
 */

/* --- Register HW_SPDIF_STCSCL, field TXCCHANNELCONS_L (RW)
 *
 * SPDIF transmit Cons. C channel data, contains next 24 bits without interpretation. When read, it
 * returns the latest data written by the processor
 */

#define BP_SPDIF_STCSCL_TXCCHANNELCONS_L      0
#define BM_SPDIF_STCSCL_TXCCHANNELCONS_L      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_STCSCL_TXCCHANNELCONS_L(v)   ((((reg32_t) v) << 0) & BM_SPDIF_STCSCL_TXCCHANNELCONS_L)
#else
#define BF_SPDIF_STCSCL_TXCCHANNELCONS_L(v)   (((v) << 0) & BM_SPDIF_STCSCL_TXCCHANNELCONS_L)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCCHANNELCONS_L field to a new value.
#define BW_SPDIF_STCSCL_TXCCHANNELCONS_L(v)   BF_CS1(SPDIF_STCSCL, TXCCHANNELCONS_L, v)
#endif

/* --- Register HW_SPDIF_STCSCL, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_STCSCL_UNIMPLEMENTED      24
#define BM_SPDIF_STCSCL_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRFM - FreqMeas Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FREQMEAS : 24; //!< Frequency measurement data
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_srfm_t;
#endif

/*
 * constants & macros for entire SPDIF_SRFM register
 */
#define HW_SPDIF_SRFM_ADDR      (REGS_SPDIF_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_SRFM           (*(volatile hw_spdif_srfm_t *) HW_SPDIF_SRFM_ADDR)
#define HW_SPDIF_SRFM_RD()      (HW_SPDIF_SRFM.U)
#endif

/*
 * constants & macros for individual SPDIF_SRFM bitfields
 */

/* --- Register HW_SPDIF_SRFM, field FREQMEAS (RO)
 *
 * Frequency measurement data
 */

#define BP_SPDIF_SRFM_FREQMEAS      0
#define BM_SPDIF_SRFM_FREQMEAS      0x00ffffff

/* --- Register HW_SPDIF_SRFM, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_SRFM_UNIMPLEMENTED      24
#define BM_SPDIF_SRFM_UNIMPLEMENTED      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STC - SPDIFTxClk Register (RW)
 *
 * The SPDIFTxClk Control register includes the means to select the transmit clock and frequency
 * division.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXCLK_DF : 7; //!< Divider factor (1-128)
        unsigned TX_ALL_CLK_EN : 1; //!< Spdif transfer clock enable.When data is going to be transfered, this bit should be set to1.
        unsigned TXCLK_SOURCE : 3; //!< 
        unsigned SYSCLK_DF : 9; //!< system clock divider factor, 2~512.
        unsigned RESERVED0 : 4; //!< Reserved, return zeros when read
        unsigned UNIMPLEMENTED : 8; //!< 
    } B;
} hw_spdif_stc_t;
#endif

/*
 * constants & macros for entire SPDIF_STC register
 */
#define HW_SPDIF_STC_ADDR      (REGS_SPDIF_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_SPDIF_STC           (*(volatile hw_spdif_stc_t *) HW_SPDIF_STC_ADDR)
#define HW_SPDIF_STC_RD()      (HW_SPDIF_STC.U)
#define HW_SPDIF_STC_WR(v)     (HW_SPDIF_STC.U = (v))
#define HW_SPDIF_STC_SET(v)    (HW_SPDIF_STC_WR(HW_SPDIF_STC_RD() |  (v)))
#define HW_SPDIF_STC_CLR(v)    (HW_SPDIF_STC_WR(HW_SPDIF_STC_RD() & ~(v)))
#define HW_SPDIF_STC_TOG(v)    (HW_SPDIF_STC_WR(HW_SPDIF_STC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDIF_STC bitfields
 */

/* --- Register HW_SPDIF_STC, field TXCLK_DF (RW)
 *
 * Divider factor (1-128)
 *
 * Values:
 * 0 - divider factor is 1
 * 1 - divider factor is 2
 * 127 - divider factor is 128
 */

#define BP_SPDIF_STC_TXCLK_DF      0
#define BM_SPDIF_STC_TXCLK_DF      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_STC_TXCLK_DF(v)   ((((reg32_t) v) << 0) & BM_SPDIF_STC_TXCLK_DF)
#else
#define BF_SPDIF_STC_TXCLK_DF(v)   (((v) << 0) & BM_SPDIF_STC_TXCLK_DF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCLK_DF field to a new value.
#define BW_SPDIF_STC_TXCLK_DF(v)   BF_CS1(SPDIF_STC, TXCLK_DF, v)
#endif


/* --- Register HW_SPDIF_STC, field TX_ALL_CLK_EN (RW)
 *
 * Spdif transfer clock enable.When data is going to be transfered, this bit should be set to1.
 *
 * Values:
 * 0 - disable transfer clock.
 * 1 - enable transfer clock.
 */

#define BP_SPDIF_STC_TX_ALL_CLK_EN      7
#define BM_SPDIF_STC_TX_ALL_CLK_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_STC_TX_ALL_CLK_EN(v)   ((((reg32_t) v) << 7) & BM_SPDIF_STC_TX_ALL_CLK_EN)
#else
#define BF_SPDIF_STC_TX_ALL_CLK_EN(v)   (((v) << 7) & BM_SPDIF_STC_TX_ALL_CLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_ALL_CLK_EN field to a new value.
#define BW_SPDIF_STC_TX_ALL_CLK_EN(v)   BF_CS1(SPDIF_STC, TX_ALL_CLK_EN, v)
#endif


/* --- Register HW_SPDIF_STC, field TXCLK_SOURCE (RW)
 *

 *
 * Values:
 * 000 - XTAL clk input
 * 001 - CCM spdif0_clk_root input
 * 010 - asrc_clk input
 * 011 - spdif_extclk input, from pads
 * 100 - esai_hckt input
 * 101 - frequency divided ipg_clk input
 * 110 - mlb_clk input
 * 111 - mlb phy clk input
 */

#define BP_SPDIF_STC_TXCLK_SOURCE      8
#define BM_SPDIF_STC_TXCLK_SOURCE      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_STC_TXCLK_SOURCE(v)   ((((reg32_t) v) << 8) & BM_SPDIF_STC_TXCLK_SOURCE)
#else
#define BF_SPDIF_STC_TXCLK_SOURCE(v)   (((v) << 8) & BM_SPDIF_STC_TXCLK_SOURCE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCLK_SOURCE field to a new value.
#define BW_SPDIF_STC_TXCLK_SOURCE(v)   BF_CS1(SPDIF_STC, TXCLK_SOURCE, v)
#endif


/* --- Register HW_SPDIF_STC, field SYSCLK_DF (RW)
 *
 * system clock divider factor, 2~512.
 *
 * Values:
 * 0 - no clock signal
 * 1 - divider factor is 2
 * 511 - divider factor is 512
 */

#define BP_SPDIF_STC_SYSCLK_DF      11
#define BM_SPDIF_STC_SYSCLK_DF      0x000ff800

#ifndef __LANGUAGE_ASM__
#define BF_SPDIF_STC_SYSCLK_DF(v)   ((((reg32_t) v) << 11) & BM_SPDIF_STC_SYSCLK_DF)
#else
#define BF_SPDIF_STC_SYSCLK_DF(v)   (((v) << 11) & BM_SPDIF_STC_SYSCLK_DF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYSCLK_DF field to a new value.
#define BW_SPDIF_STC_SYSCLK_DF(v)   BF_CS1(SPDIF_STC, SYSCLK_DF, v)
#endif


/* --- Register HW_SPDIF_STC, field UNIMPLEMENTED (RU)
 *

 */

#define BP_SPDIF_STC_UNIMPLEMENTED      24
#define BM_SPDIF_STC_UNIMPLEMENTED      0xff000000


/*!
 * @brief All SPDIF module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_spdif_scr_t SCR; //!< SPDIF Configuration Register
    volatile hw_spdif_srcd_t SRCD; //!< CDText Control Register
    volatile hw_spdif_srpc_t SRPC; //!< PhaseConfig Register
    volatile hw_spdif_sie_t SIE; //!< InterruptEn Register
    volatile hw_spdif_sis_t SIS; //!< InterruptStat Register
    volatile hw_spdif_srl_t SRL; //!< SPDIFRxLeft Register
    volatile hw_spdif_srr_t SRR; //!< SPDIFRxRight Register
    volatile hw_spdif_srcsh_t SRCSH; //!< SPDIFRxCChannel_h Register
    volatile hw_spdif_srcsl_t SRCSL; //!< SPDIFRxCChannel_l Register
    volatile hw_spdif_sru_t SRU; //!< UchannelRx Register
    volatile hw_spdif_srq_t SRQ; //!< QchannelRx Register
    volatile hw_spdif_stl_t STL; //!< SPDIFTxLeft Register
    volatile hw_spdif_str_t STR; //!< SPDIFTxRight Register
    volatile hw_spdif_stcsch_t STCSCH; //!< SPDIFTxCChannelCons_h Register
    volatile hw_spdif_stcscl_t STCSCL; //!< SPDIFTxCChannelCons_l Register
    reg32_t _reserved0[2];
    volatile hw_spdif_srfm_t SRFM; //!< FreqMeas Register
    reg32_t _reserved1[2];
    volatile hw_spdif_stc_t STC; //!< SPDIFTxClk Register
} hw_spdif_t;
#endif

//! @brief Macro to access all SPDIF registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SPDIF(0)</code>.
#define HW_SPDIF     (*(volatile hw_spdif_t *) REGS_SPDIF_BASE)


#endif // _SPDIF_H
