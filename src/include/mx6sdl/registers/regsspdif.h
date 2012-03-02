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
 * i.MX6SDL SPDIF registers defined in this header file.
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
 * Reset value: 0x00000400
 *

 */
typedef union _hw_spdif_scr
{
    reg32_t U;
    struct _hw_spdif_scr_bitfields
    {
        unsigned USRC_SEL : 2; //!< [1:0] 
        unsigned TXSEL : 3; //!< [4:2] 
        unsigned VALCTRL : 1; //!< [5] 
        unsigned RESERVED0 : 2; //!< [7:6] Reserved
        unsigned DMA_TX_EN : 1; //!< [8] DMA Transmit Request Enable (Tx FIFO empty)
        unsigned DMA_RX_EN : 1; //!< [9] DMA Receive Request Enable (RX FIFO full)
        unsigned TXFIFO_CTRL : 2; //!< [11:10] 
        unsigned SOFT_RESET : 1; //!< [12] When write 1 to this bit, it will cause SPDIF software reset. The software reset will last 8 cycles. When in the reset process, return 1 when read. else return 0 when read.
        unsigned LOW_POWER : 1; //!< [13] When write 1 to this bit, it will cause SPDIF enter low-power mode. return 1 when SPDIF in Low-Power mode.
        unsigned RESERVED1 : 1; //!< [14] Reserved
        unsigned TXFIFOEMPTY_SEL : 2; //!< [16:15] 
        unsigned TXAUTOSYNC : 1; //!< [17] 
        unsigned RXAUTOSYNC : 1; //!< [18] 
        unsigned RXFIFOFULL_SEL : 2; //!< [20:19] 
        unsigned RXFIFO_RST : 1; //!< [21] 
        unsigned RXFIFO_OFF : 1; //!< [22] 
        unsigned RXFIFO_CTRL : 1; //!< [23] 
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SCR, field USRC_SEL[1:0] (RW)
 *

 *
 * Values:
 * 00 - No embedded U channel
 * 01 - U channel from SPDIF receive block (CD mode)
 * 10 - Reserved
 * 11 - U channel from on chip transmitter
 */

#define BP_SPDIF_SCR_USRC_SEL      (0)      //!< Bit position for SPDIF_SCR_USRC_SEL.
#define BM_SPDIF_SCR_USRC_SEL      (0x00000003)  //!< Bit mask for SPDIF_SCR_USRC_SEL.

//! @brief Get value of SPDIF_SCR_USRC_SEL from a register value.
#define BG_SPDIF_SCR_USRC_SEL(r)   (((r) & BM_SPDIF_SCR_USRC_SEL) >> BP_SPDIF_SCR_USRC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_USRC_SEL.
#define BF_SPDIF_SCR_USRC_SEL(v)   ((((reg32_t) v) << BP_SPDIF_SCR_USRC_SEL) & BM_SPDIF_SCR_USRC_SEL)
#else
//! @brief Format value for bitfield SPDIF_SCR_USRC_SEL.
#define BF_SPDIF_SCR_USRC_SEL(v)   (((v) << BP_SPDIF_SCR_USRC_SEL) & BM_SPDIF_SCR_USRC_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USRC_SEL field to a new value.
#define BW_SPDIF_SCR_USRC_SEL(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_USRC_SEL) | BF_SPDIF_SCR_USRC_SEL(v)))
#endif


/* --- Register HW_SPDIF_SCR, field TXSEL[4:2] (RW)
 *

 *
 * Values:
 * 000 - Off and output 0
 * 001 - Feed-through SPDIFIN
 * 101 - Tx Normal operation
 */

#define BP_SPDIF_SCR_TXSEL      (2)      //!< Bit position for SPDIF_SCR_TXSEL.
#define BM_SPDIF_SCR_TXSEL      (0x0000001c)  //!< Bit mask for SPDIF_SCR_TXSEL.

//! @brief Get value of SPDIF_SCR_TXSEL from a register value.
#define BG_SPDIF_SCR_TXSEL(r)   (((r) & BM_SPDIF_SCR_TXSEL) >> BP_SPDIF_SCR_TXSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_TXSEL.
#define BF_SPDIF_SCR_TXSEL(v)   ((((reg32_t) v) << BP_SPDIF_SCR_TXSEL) & BM_SPDIF_SCR_TXSEL)
#else
//! @brief Format value for bitfield SPDIF_SCR_TXSEL.
#define BF_SPDIF_SCR_TXSEL(v)   (((v) << BP_SPDIF_SCR_TXSEL) & BM_SPDIF_SCR_TXSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSEL field to a new value.
#define BW_SPDIF_SCR_TXSEL(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_TXSEL) | BF_SPDIF_SCR_TXSEL(v)))
#endif


/* --- Register HW_SPDIF_SCR, field VALCTRL[5] (RW)
 *

 *
 * Values:
 * 0 - Outgoing Validity always set
 * 1 - Outgoing Validity always clear
 */

#define BP_SPDIF_SCR_VALCTRL      (5)      //!< Bit position for SPDIF_SCR_VALCTRL.
#define BM_SPDIF_SCR_VALCTRL      (0x00000020)  //!< Bit mask for SPDIF_SCR_VALCTRL.

//! @brief Get value of SPDIF_SCR_VALCTRL from a register value.
#define BG_SPDIF_SCR_VALCTRL(r)   (((r) & BM_SPDIF_SCR_VALCTRL) >> BP_SPDIF_SCR_VALCTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_VALCTRL.
#define BF_SPDIF_SCR_VALCTRL(v)   ((((reg32_t) v) << BP_SPDIF_SCR_VALCTRL) & BM_SPDIF_SCR_VALCTRL)
#else
//! @brief Format value for bitfield SPDIF_SCR_VALCTRL.
#define BF_SPDIF_SCR_VALCTRL(v)   (((v) << BP_SPDIF_SCR_VALCTRL) & BM_SPDIF_SCR_VALCTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALCTRL field to a new value.
#define BW_SPDIF_SCR_VALCTRL(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_VALCTRL) | BF_SPDIF_SCR_VALCTRL(v)))
#endif


/* --- Register HW_SPDIF_SCR, field DMA_TX_EN[8] (RW)
 *
 * DMA Transmit Request Enable (Tx FIFO empty)
 */

#define BP_SPDIF_SCR_DMA_TX_EN      (8)      //!< Bit position for SPDIF_SCR_DMA_TX_EN.
#define BM_SPDIF_SCR_DMA_TX_EN      (0x00000100)  //!< Bit mask for SPDIF_SCR_DMA_TX_EN.

//! @brief Get value of SPDIF_SCR_DMA_TX_EN from a register value.
#define BG_SPDIF_SCR_DMA_TX_EN(r)   (((r) & BM_SPDIF_SCR_DMA_TX_EN) >> BP_SPDIF_SCR_DMA_TX_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_DMA_TX_EN.
#define BF_SPDIF_SCR_DMA_TX_EN(v)   ((((reg32_t) v) << BP_SPDIF_SCR_DMA_TX_EN) & BM_SPDIF_SCR_DMA_TX_EN)
#else
//! @brief Format value for bitfield SPDIF_SCR_DMA_TX_EN.
#define BF_SPDIF_SCR_DMA_TX_EN(v)   (((v) << BP_SPDIF_SCR_DMA_TX_EN) & BM_SPDIF_SCR_DMA_TX_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_TX_EN field to a new value.
#define BW_SPDIF_SCR_DMA_TX_EN(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_DMA_TX_EN) | BF_SPDIF_SCR_DMA_TX_EN(v)))
#endif

/* --- Register HW_SPDIF_SCR, field DMA_RX_EN[9] (RW)
 *
 * DMA Receive Request Enable (RX FIFO full)
 */

#define BP_SPDIF_SCR_DMA_RX_EN      (9)      //!< Bit position for SPDIF_SCR_DMA_RX_EN.
#define BM_SPDIF_SCR_DMA_RX_EN      (0x00000200)  //!< Bit mask for SPDIF_SCR_DMA_RX_EN.

//! @brief Get value of SPDIF_SCR_DMA_RX_EN from a register value.
#define BG_SPDIF_SCR_DMA_RX_EN(r)   (((r) & BM_SPDIF_SCR_DMA_RX_EN) >> BP_SPDIF_SCR_DMA_RX_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_DMA_RX_EN.
#define BF_SPDIF_SCR_DMA_RX_EN(v)   ((((reg32_t) v) << BP_SPDIF_SCR_DMA_RX_EN) & BM_SPDIF_SCR_DMA_RX_EN)
#else
//! @brief Format value for bitfield SPDIF_SCR_DMA_RX_EN.
#define BF_SPDIF_SCR_DMA_RX_EN(v)   (((v) << BP_SPDIF_SCR_DMA_RX_EN) & BM_SPDIF_SCR_DMA_RX_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_RX_EN field to a new value.
#define BW_SPDIF_SCR_DMA_RX_EN(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_DMA_RX_EN) | BF_SPDIF_SCR_DMA_RX_EN(v)))
#endif

/* --- Register HW_SPDIF_SCR, field TXFIFO_CTRL[11:10] (RW)
 *

 *
 * Values:
 * 00 - Send out digital zero on SPDIF Tx
 * 01 - Tx Normal operation
 * 10 - Reset to 1 sample remaining
 * 11 - Reserved
 */

#define BP_SPDIF_SCR_TXFIFO_CTRL      (10)      //!< Bit position for SPDIF_SCR_TXFIFO_CTRL.
#define BM_SPDIF_SCR_TXFIFO_CTRL      (0x00000c00)  //!< Bit mask for SPDIF_SCR_TXFIFO_CTRL.

//! @brief Get value of SPDIF_SCR_TXFIFO_CTRL from a register value.
#define BG_SPDIF_SCR_TXFIFO_CTRL(r)   (((r) & BM_SPDIF_SCR_TXFIFO_CTRL) >> BP_SPDIF_SCR_TXFIFO_CTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_TXFIFO_CTRL.
#define BF_SPDIF_SCR_TXFIFO_CTRL(v)   ((((reg32_t) v) << BP_SPDIF_SCR_TXFIFO_CTRL) & BM_SPDIF_SCR_TXFIFO_CTRL)
#else
//! @brief Format value for bitfield SPDIF_SCR_TXFIFO_CTRL.
#define BF_SPDIF_SCR_TXFIFO_CTRL(v)   (((v) << BP_SPDIF_SCR_TXFIFO_CTRL) & BM_SPDIF_SCR_TXFIFO_CTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFIFO_CTRL field to a new value.
#define BW_SPDIF_SCR_TXFIFO_CTRL(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_TXFIFO_CTRL) | BF_SPDIF_SCR_TXFIFO_CTRL(v)))
#endif


/* --- Register HW_SPDIF_SCR, field SOFT_RESET[12] (RW)
 *
 * When write 1 to this bit, it will cause SPDIF software reset. The software reset will last 8
 * cycles. When in the reset process, return 1 when read. else return 0 when read.
 */

#define BP_SPDIF_SCR_SOFT_RESET      (12)      //!< Bit position for SPDIF_SCR_SOFT_RESET.
#define BM_SPDIF_SCR_SOFT_RESET      (0x00001000)  //!< Bit mask for SPDIF_SCR_SOFT_RESET.

//! @brief Get value of SPDIF_SCR_SOFT_RESET from a register value.
#define BG_SPDIF_SCR_SOFT_RESET(r)   (((r) & BM_SPDIF_SCR_SOFT_RESET) >> BP_SPDIF_SCR_SOFT_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_SOFT_RESET.
#define BF_SPDIF_SCR_SOFT_RESET(v)   ((((reg32_t) v) << BP_SPDIF_SCR_SOFT_RESET) & BM_SPDIF_SCR_SOFT_RESET)
#else
//! @brief Format value for bitfield SPDIF_SCR_SOFT_RESET.
#define BF_SPDIF_SCR_SOFT_RESET(v)   (((v) << BP_SPDIF_SCR_SOFT_RESET) & BM_SPDIF_SCR_SOFT_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOFT_RESET field to a new value.
#define BW_SPDIF_SCR_SOFT_RESET(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_SOFT_RESET) | BF_SPDIF_SCR_SOFT_RESET(v)))
#endif

/* --- Register HW_SPDIF_SCR, field LOW_POWER[13] (RW)
 *
 * When write 1 to this bit, it will cause SPDIF enter low-power mode. return 1 when SPDIF in Low-
 * Power mode.
 */

#define BP_SPDIF_SCR_LOW_POWER      (13)      //!< Bit position for SPDIF_SCR_LOW_POWER.
#define BM_SPDIF_SCR_LOW_POWER      (0x00002000)  //!< Bit mask for SPDIF_SCR_LOW_POWER.

//! @brief Get value of SPDIF_SCR_LOW_POWER from a register value.
#define BG_SPDIF_SCR_LOW_POWER(r)   (((r) & BM_SPDIF_SCR_LOW_POWER) >> BP_SPDIF_SCR_LOW_POWER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_LOW_POWER.
#define BF_SPDIF_SCR_LOW_POWER(v)   ((((reg32_t) v) << BP_SPDIF_SCR_LOW_POWER) & BM_SPDIF_SCR_LOW_POWER)
#else
//! @brief Format value for bitfield SPDIF_SCR_LOW_POWER.
#define BF_SPDIF_SCR_LOW_POWER(v)   (((v) << BP_SPDIF_SCR_LOW_POWER) & BM_SPDIF_SCR_LOW_POWER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOW_POWER field to a new value.
#define BW_SPDIF_SCR_LOW_POWER(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_LOW_POWER) | BF_SPDIF_SCR_LOW_POWER(v)))
#endif

/* --- Register HW_SPDIF_SCR, field TXFIFOEMPTY_SEL[16:15] (RW)
 *

 *
 * Values:
 * 00 - Empty interrupt if 0 sample in Tx left and right FIFOs
 * 01 - Empty interrupt if at most 4 sample in Tx left and right FIFOs
 * 10 - Empty interrupt if at most 8 sample in Tx left and right FIFOs
 * 11 - Empty interrupt if at most 12 sample in Tx left and right FIFOs
 */

#define BP_SPDIF_SCR_TXFIFOEMPTY_SEL      (15)      //!< Bit position for SPDIF_SCR_TXFIFOEMPTY_SEL.
#define BM_SPDIF_SCR_TXFIFOEMPTY_SEL      (0x00018000)  //!< Bit mask for SPDIF_SCR_TXFIFOEMPTY_SEL.

//! @brief Get value of SPDIF_SCR_TXFIFOEMPTY_SEL from a register value.
#define BG_SPDIF_SCR_TXFIFOEMPTY_SEL(r)   (((r) & BM_SPDIF_SCR_TXFIFOEMPTY_SEL) >> BP_SPDIF_SCR_TXFIFOEMPTY_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_TXFIFOEMPTY_SEL.
#define BF_SPDIF_SCR_TXFIFOEMPTY_SEL(v)   ((((reg32_t) v) << BP_SPDIF_SCR_TXFIFOEMPTY_SEL) & BM_SPDIF_SCR_TXFIFOEMPTY_SEL)
#else
//! @brief Format value for bitfield SPDIF_SCR_TXFIFOEMPTY_SEL.
#define BF_SPDIF_SCR_TXFIFOEMPTY_SEL(v)   (((v) << BP_SPDIF_SCR_TXFIFOEMPTY_SEL) & BM_SPDIF_SCR_TXFIFOEMPTY_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFIFOEMPTY_SEL field to a new value.
#define BW_SPDIF_SCR_TXFIFOEMPTY_SEL(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_TXFIFOEMPTY_SEL) | BF_SPDIF_SCR_TXFIFOEMPTY_SEL(v)))
#endif


/* --- Register HW_SPDIF_SCR, field TXAUTOSYNC[17] (RW)
 *

 *
 * Values:
 * 0 - Tx FIFO auto sync off
 * 1 - Tx FIFO auto sync on
 */

#define BP_SPDIF_SCR_TXAUTOSYNC      (17)      //!< Bit position for SPDIF_SCR_TXAUTOSYNC.
#define BM_SPDIF_SCR_TXAUTOSYNC      (0x00020000)  //!< Bit mask for SPDIF_SCR_TXAUTOSYNC.

//! @brief Get value of SPDIF_SCR_TXAUTOSYNC from a register value.
#define BG_SPDIF_SCR_TXAUTOSYNC(r)   (((r) & BM_SPDIF_SCR_TXAUTOSYNC) >> BP_SPDIF_SCR_TXAUTOSYNC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_TXAUTOSYNC.
#define BF_SPDIF_SCR_TXAUTOSYNC(v)   ((((reg32_t) v) << BP_SPDIF_SCR_TXAUTOSYNC) & BM_SPDIF_SCR_TXAUTOSYNC)
#else
//! @brief Format value for bitfield SPDIF_SCR_TXAUTOSYNC.
#define BF_SPDIF_SCR_TXAUTOSYNC(v)   (((v) << BP_SPDIF_SCR_TXAUTOSYNC) & BM_SPDIF_SCR_TXAUTOSYNC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXAUTOSYNC field to a new value.
#define BW_SPDIF_SCR_TXAUTOSYNC(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_TXAUTOSYNC) | BF_SPDIF_SCR_TXAUTOSYNC(v)))
#endif


/* --- Register HW_SPDIF_SCR, field RXAUTOSYNC[18] (RW)
 *

 *
 * Values:
 * 0 - Rx FIFO auto sync off
 * 1 - RxFIFO auto sync on
 */

#define BP_SPDIF_SCR_RXAUTOSYNC      (18)      //!< Bit position for SPDIF_SCR_RXAUTOSYNC.
#define BM_SPDIF_SCR_RXAUTOSYNC      (0x00040000)  //!< Bit mask for SPDIF_SCR_RXAUTOSYNC.

//! @brief Get value of SPDIF_SCR_RXAUTOSYNC from a register value.
#define BG_SPDIF_SCR_RXAUTOSYNC(r)   (((r) & BM_SPDIF_SCR_RXAUTOSYNC) >> BP_SPDIF_SCR_RXAUTOSYNC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_RXAUTOSYNC.
#define BF_SPDIF_SCR_RXAUTOSYNC(v)   ((((reg32_t) v) << BP_SPDIF_SCR_RXAUTOSYNC) & BM_SPDIF_SCR_RXAUTOSYNC)
#else
//! @brief Format value for bitfield SPDIF_SCR_RXAUTOSYNC.
#define BF_SPDIF_SCR_RXAUTOSYNC(v)   (((v) << BP_SPDIF_SCR_RXAUTOSYNC) & BM_SPDIF_SCR_RXAUTOSYNC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXAUTOSYNC field to a new value.
#define BW_SPDIF_SCR_RXAUTOSYNC(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_RXAUTOSYNC) | BF_SPDIF_SCR_RXAUTOSYNC(v)))
#endif


/* --- Register HW_SPDIF_SCR, field RXFIFOFULL_SEL[20:19] (RW)
 *

 *
 * Values:
 * 00 - Full interrupt if at least 1 sample in Rx left and right FIFOs
 * 01 - Full interrupt if at least 4 sample in Rx left and right FIFOs
 * 10 - Full interrupt if at least 8 sample in Rx left and right FIFOs
 * 11 - Full interrupt if at least 16 sample in Rx left and right FIFO
 */

#define BP_SPDIF_SCR_RXFIFOFULL_SEL      (19)      //!< Bit position for SPDIF_SCR_RXFIFOFULL_SEL.
#define BM_SPDIF_SCR_RXFIFOFULL_SEL      (0x00180000)  //!< Bit mask for SPDIF_SCR_RXFIFOFULL_SEL.

//! @brief Get value of SPDIF_SCR_RXFIFOFULL_SEL from a register value.
#define BG_SPDIF_SCR_RXFIFOFULL_SEL(r)   (((r) & BM_SPDIF_SCR_RXFIFOFULL_SEL) >> BP_SPDIF_SCR_RXFIFOFULL_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_RXFIFOFULL_SEL.
#define BF_SPDIF_SCR_RXFIFOFULL_SEL(v)   ((((reg32_t) v) << BP_SPDIF_SCR_RXFIFOFULL_SEL) & BM_SPDIF_SCR_RXFIFOFULL_SEL)
#else
//! @brief Format value for bitfield SPDIF_SCR_RXFIFOFULL_SEL.
#define BF_SPDIF_SCR_RXFIFOFULL_SEL(v)   (((v) << BP_SPDIF_SCR_RXFIFOFULL_SEL) & BM_SPDIF_SCR_RXFIFOFULL_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFOFULL_SEL field to a new value.
#define BW_SPDIF_SCR_RXFIFOFULL_SEL(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_RXFIFOFULL_SEL) | BF_SPDIF_SCR_RXFIFOFULL_SEL(v)))
#endif


/* --- Register HW_SPDIF_SCR, field RXFIFO_RST[21] (RW)
 *

 *
 * Values:
 * 0 - Normal operation
 * 1 - Reset register to 1 sample remaining
 */

#define BP_SPDIF_SCR_RXFIFO_RST      (21)      //!< Bit position for SPDIF_SCR_RXFIFO_RST.
#define BM_SPDIF_SCR_RXFIFO_RST      (0x00200000)  //!< Bit mask for SPDIF_SCR_RXFIFO_RST.

//! @brief Get value of SPDIF_SCR_RXFIFO_RST from a register value.
#define BG_SPDIF_SCR_RXFIFO_RST(r)   (((r) & BM_SPDIF_SCR_RXFIFO_RST) >> BP_SPDIF_SCR_RXFIFO_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_RXFIFO_RST.
#define BF_SPDIF_SCR_RXFIFO_RST(v)   ((((reg32_t) v) << BP_SPDIF_SCR_RXFIFO_RST) & BM_SPDIF_SCR_RXFIFO_RST)
#else
//! @brief Format value for bitfield SPDIF_SCR_RXFIFO_RST.
#define BF_SPDIF_SCR_RXFIFO_RST(v)   (((v) << BP_SPDIF_SCR_RXFIFO_RST) & BM_SPDIF_SCR_RXFIFO_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFO_RST field to a new value.
#define BW_SPDIF_SCR_RXFIFO_RST(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_RXFIFO_RST) | BF_SPDIF_SCR_RXFIFO_RST(v)))
#endif


/* --- Register HW_SPDIF_SCR, field RXFIFO_OFF[22] (RW)
 *

 *
 * Values:
 * 0 - SPDIF Rx FIFO is on
 * 1 - SPDIF Rx FIFO is off. Does not accept data from interface
 */

#define BP_SPDIF_SCR_RXFIFO_OFF      (22)      //!< Bit position for SPDIF_SCR_RXFIFO_OFF.
#define BM_SPDIF_SCR_RXFIFO_OFF      (0x00400000)  //!< Bit mask for SPDIF_SCR_RXFIFO_OFF.

//! @brief Get value of SPDIF_SCR_RXFIFO_OFF from a register value.
#define BG_SPDIF_SCR_RXFIFO_OFF(r)   (((r) & BM_SPDIF_SCR_RXFIFO_OFF) >> BP_SPDIF_SCR_RXFIFO_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_RXFIFO_OFF.
#define BF_SPDIF_SCR_RXFIFO_OFF(v)   ((((reg32_t) v) << BP_SPDIF_SCR_RXFIFO_OFF) & BM_SPDIF_SCR_RXFIFO_OFF)
#else
//! @brief Format value for bitfield SPDIF_SCR_RXFIFO_OFF.
#define BF_SPDIF_SCR_RXFIFO_OFF(v)   (((v) << BP_SPDIF_SCR_RXFIFO_OFF) & BM_SPDIF_SCR_RXFIFO_OFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFO_OFF field to a new value.
#define BW_SPDIF_SCR_RXFIFO_OFF(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_RXFIFO_OFF) | BF_SPDIF_SCR_RXFIFO_OFF(v)))
#endif


/* --- Register HW_SPDIF_SCR, field RXFIFO_CTRL[23] (RW)
 *

 *
 * Values:
 * 0 - Normal operation
 * 1 - Always read zero from Rx data register
 */

#define BP_SPDIF_SCR_RXFIFO_CTRL      (23)      //!< Bit position for SPDIF_SCR_RXFIFO_CTRL.
#define BM_SPDIF_SCR_RXFIFO_CTRL      (0x00800000)  //!< Bit mask for SPDIF_SCR_RXFIFO_CTRL.

//! @brief Get value of SPDIF_SCR_RXFIFO_CTRL from a register value.
#define BG_SPDIF_SCR_RXFIFO_CTRL(r)   (((r) & BM_SPDIF_SCR_RXFIFO_CTRL) >> BP_SPDIF_SCR_RXFIFO_CTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SCR_RXFIFO_CTRL.
#define BF_SPDIF_SCR_RXFIFO_CTRL(v)   ((((reg32_t) v) << BP_SPDIF_SCR_RXFIFO_CTRL) & BM_SPDIF_SCR_RXFIFO_CTRL)
#else
//! @brief Format value for bitfield SPDIF_SCR_RXFIFO_CTRL.
#define BF_SPDIF_SCR_RXFIFO_CTRL(v)   (((v) << BP_SPDIF_SCR_RXFIFO_CTRL) & BM_SPDIF_SCR_RXFIFO_CTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFO_CTRL field to a new value.
#define BW_SPDIF_SCR_RXFIFO_CTRL(v)   (HW_SPDIF_SCR_WR((HW_SPDIF_SCR_RD() & ~BM_SPDIF_SCR_RXFIFO_CTRL) | BF_SPDIF_SCR_RXFIFO_CTRL(v)))
#endif


/* --- Register HW_SPDIF_SCR, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SCR_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SCR_UNIMPLEMENTED.
#define BM_SPDIF_SCR_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SCR_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SCR_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SCR_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SCR_UNIMPLEMENTED) >> BP_SPDIF_SCR_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRCD - CDText Control Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdif_srcd
{
    reg32_t U;
    struct _hw_spdif_srcd_bitfields
    {
        unsigned RESERVED0 : 1; //!< [0] Reserved
        unsigned USYNCMODE : 1; //!< [1] 
        unsigned RESERVED1 : 22; //!< [23:2] Reserved.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SRCD, field USYNCMODE[1] (RW)
 *

 *
 * Values:
 * 0 - Non-CD data
 * 1 - CD user channel subcode
 */

#define BP_SPDIF_SRCD_USYNCMODE      (1)      //!< Bit position for SPDIF_SRCD_USYNCMODE.
#define BM_SPDIF_SRCD_USYNCMODE      (0x00000002)  //!< Bit mask for SPDIF_SRCD_USYNCMODE.

//! @brief Get value of SPDIF_SRCD_USYNCMODE from a register value.
#define BG_SPDIF_SRCD_USYNCMODE(r)   (((r) & BM_SPDIF_SRCD_USYNCMODE) >> BP_SPDIF_SRCD_USYNCMODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SRCD_USYNCMODE.
#define BF_SPDIF_SRCD_USYNCMODE(v)   ((((reg32_t) v) << BP_SPDIF_SRCD_USYNCMODE) & BM_SPDIF_SRCD_USYNCMODE)
#else
//! @brief Format value for bitfield SPDIF_SRCD_USYNCMODE.
#define BF_SPDIF_SRCD_USYNCMODE(v)   (((v) << BP_SPDIF_SRCD_USYNCMODE) & BM_SPDIF_SRCD_USYNCMODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USYNCMODE field to a new value.
#define BW_SPDIF_SRCD_USYNCMODE(v)   (HW_SPDIF_SRCD_WR((HW_SPDIF_SRCD_RD() & ~BM_SPDIF_SRCD_USYNCMODE) | BF_SPDIF_SRCD_USYNCMODE(v)))
#endif


/* --- Register HW_SPDIF_SRCD, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SRCD_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRCD_UNIMPLEMENTED.
#define BM_SPDIF_SRCD_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRCD_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRCD_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRCD_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRCD_UNIMPLEMENTED) >> BP_SPDIF_SRCD_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRPC - PhaseConfig Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdif_srpc
{
    reg32_t U;
    struct _hw_spdif_srpc_bitfields
    {
        unsigned RESERVED0 : 3; //!< [2:0] Reserved, return zeros when read
        unsigned GAINSEL : 3; //!< [5:3] Gain selection:
        unsigned LOCK : 1; //!< [6] LOCK bit to show that the internal DPLL is locked, read only
        unsigned RESERVED1 : 17; //!< [23:7] Reserved.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SRPC, field GAINSEL[5:3] (RW)
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

#define BP_SPDIF_SRPC_GAINSEL      (3)      //!< Bit position for SPDIF_SRPC_GAINSEL.
#define BM_SPDIF_SRPC_GAINSEL      (0x00000038)  //!< Bit mask for SPDIF_SRPC_GAINSEL.

//! @brief Get value of SPDIF_SRPC_GAINSEL from a register value.
#define BG_SPDIF_SRPC_GAINSEL(r)   (((r) & BM_SPDIF_SRPC_GAINSEL) >> BP_SPDIF_SRPC_GAINSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SRPC_GAINSEL.
#define BF_SPDIF_SRPC_GAINSEL(v)   ((((reg32_t) v) << BP_SPDIF_SRPC_GAINSEL) & BM_SPDIF_SRPC_GAINSEL)
#else
//! @brief Format value for bitfield SPDIF_SRPC_GAINSEL.
#define BF_SPDIF_SRPC_GAINSEL(v)   (((v) << BP_SPDIF_SRPC_GAINSEL) & BM_SPDIF_SRPC_GAINSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GAINSEL field to a new value.
#define BW_SPDIF_SRPC_GAINSEL(v)   (HW_SPDIF_SRPC_WR((HW_SPDIF_SRPC_RD() & ~BM_SPDIF_SRPC_GAINSEL) | BF_SPDIF_SRPC_GAINSEL(v)))
#endif


/* --- Register HW_SPDIF_SRPC, field LOCK[6] (RO)
 *
 * LOCK bit to show that the internal DPLL is locked, read only
 */

#define BP_SPDIF_SRPC_LOCK      (6)      //!< Bit position for SPDIF_SRPC_LOCK.
#define BM_SPDIF_SRPC_LOCK      (0x00000040)  //!< Bit mask for SPDIF_SRPC_LOCK.

//! @brief Get value of SPDIF_SRPC_LOCK from a register value.
#define BG_SPDIF_SRPC_LOCK(r)   (((r) & BM_SPDIF_SRPC_LOCK) >> BP_SPDIF_SRPC_LOCK)

/* --- Register HW_SPDIF_SRPC, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SRPC_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRPC_UNIMPLEMENTED.
#define BM_SPDIF_SRPC_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRPC_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRPC_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRPC_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRPC_UNIMPLEMENTED) >> BP_SPDIF_SRPC_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SIE - InterruptEn Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The InterruptEn register (SPDIF_SIE) provides control over the enabling of interrupts.
 */
typedef union _hw_spdif_sie
{
    reg32_t U;
    struct _hw_spdif_sie_bitfields
    {
        unsigned RXFIFOFUL : 1; //!< [0] SPDIF Rx FIFO full, can't be cleared with reg. IntClear. To clear it, read from Rx FIFO.
        unsigned TXEM : 1; //!< [1] SPDIF Tx FIFO empty, can't be cleared with reg. IntClear. To clear it, write toTx FIFO.
        unsigned LOCKLOSS : 1; //!< [2] SPDIF receiver loss of lock
        unsigned RXFIFORESYN : 1; //!< [3] Rx FIFO resync
        unsigned RXFIFOUNOV : 1; //!< [4] Rx FIFO underrun/overrun
        unsigned UQERR : 1; //!< [5] U/Q Channel framing error
        unsigned UQSYNC : 1; //!< [6] U/Q Channel sync found
        unsigned QRXOV : 1; //!< [7] Q Channel receive register overrun
        unsigned QRXFUL : 1; //!< [8] Q Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from Q Rx reg.
        unsigned URXOV : 1; //!< [9] U Channel receive register overrun
        unsigned URXFUL : 1; //!< [10] U Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from U Rx reg.
        unsigned RESERVED0 : 3; //!< [13:11] Reserved. Return zeros when read
        unsigned BITERR : 1; //!< [14] SPDIF receiver found parity bit error
        unsigned SYMERR : 1; //!< [15] SPDIF receiver found illegal symbol
        unsigned VALNOGOOD : 1; //!< [16] SPDIF validity flag no good
        unsigned CNEW : 1; //!< [17] SPDIF receive change in value of control channel
        unsigned TXRESYN : 1; //!< [18] SPDIF Tx FIFO resync
        unsigned TXUNOV : 1; //!< [19] SPDIF Tx FIFO under/overrun
        unsigned LOCK : 1; //!< [20] SPDIF receiver's DPLL is locked
        unsigned RESERVED1 : 3; //!< [23:21] Reserved.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SIE, field RXFIFOFUL[0] (RW)
 *
 * SPDIF Rx FIFO full, can't be cleared with reg. IntClear. To clear it, read from Rx FIFO.
 */

#define BP_SPDIF_SIE_RXFIFOFUL      (0)      //!< Bit position for SPDIF_SIE_RXFIFOFUL.
#define BM_SPDIF_SIE_RXFIFOFUL      (0x00000001)  //!< Bit mask for SPDIF_SIE_RXFIFOFUL.

//! @brief Get value of SPDIF_SIE_RXFIFOFUL from a register value.
#define BG_SPDIF_SIE_RXFIFOFUL(r)   (((r) & BM_SPDIF_SIE_RXFIFOFUL) >> BP_SPDIF_SIE_RXFIFOFUL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_RXFIFOFUL.
#define BF_SPDIF_SIE_RXFIFOFUL(v)   ((((reg32_t) v) << BP_SPDIF_SIE_RXFIFOFUL) & BM_SPDIF_SIE_RXFIFOFUL)
#else
//! @brief Format value for bitfield SPDIF_SIE_RXFIFOFUL.
#define BF_SPDIF_SIE_RXFIFOFUL(v)   (((v) << BP_SPDIF_SIE_RXFIFOFUL) & BM_SPDIF_SIE_RXFIFOFUL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFOFUL field to a new value.
#define BW_SPDIF_SIE_RXFIFOFUL(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_RXFIFOFUL) | BF_SPDIF_SIE_RXFIFOFUL(v)))
#endif

/* --- Register HW_SPDIF_SIE, field TXEM[1] (RW)
 *
 * SPDIF Tx FIFO empty, can't be cleared with reg. IntClear. To clear it, write toTx FIFO.
 */

#define BP_SPDIF_SIE_TXEM      (1)      //!< Bit position for SPDIF_SIE_TXEM.
#define BM_SPDIF_SIE_TXEM      (0x00000002)  //!< Bit mask for SPDIF_SIE_TXEM.

//! @brief Get value of SPDIF_SIE_TXEM from a register value.
#define BG_SPDIF_SIE_TXEM(r)   (((r) & BM_SPDIF_SIE_TXEM) >> BP_SPDIF_SIE_TXEM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_TXEM.
#define BF_SPDIF_SIE_TXEM(v)   ((((reg32_t) v) << BP_SPDIF_SIE_TXEM) & BM_SPDIF_SIE_TXEM)
#else
//! @brief Format value for bitfield SPDIF_SIE_TXEM.
#define BF_SPDIF_SIE_TXEM(v)   (((v) << BP_SPDIF_SIE_TXEM) & BM_SPDIF_SIE_TXEM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXEM field to a new value.
#define BW_SPDIF_SIE_TXEM(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_TXEM) | BF_SPDIF_SIE_TXEM(v)))
#endif

/* --- Register HW_SPDIF_SIE, field LOCKLOSS[2] (RW)
 *
 * SPDIF receiver loss of lock
 */

#define BP_SPDIF_SIE_LOCKLOSS      (2)      //!< Bit position for SPDIF_SIE_LOCKLOSS.
#define BM_SPDIF_SIE_LOCKLOSS      (0x00000004)  //!< Bit mask for SPDIF_SIE_LOCKLOSS.

//! @brief Get value of SPDIF_SIE_LOCKLOSS from a register value.
#define BG_SPDIF_SIE_LOCKLOSS(r)   (((r) & BM_SPDIF_SIE_LOCKLOSS) >> BP_SPDIF_SIE_LOCKLOSS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_LOCKLOSS.
#define BF_SPDIF_SIE_LOCKLOSS(v)   ((((reg32_t) v) << BP_SPDIF_SIE_LOCKLOSS) & BM_SPDIF_SIE_LOCKLOSS)
#else
//! @brief Format value for bitfield SPDIF_SIE_LOCKLOSS.
#define BF_SPDIF_SIE_LOCKLOSS(v)   (((v) << BP_SPDIF_SIE_LOCKLOSS) & BM_SPDIF_SIE_LOCKLOSS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCKLOSS field to a new value.
#define BW_SPDIF_SIE_LOCKLOSS(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_LOCKLOSS) | BF_SPDIF_SIE_LOCKLOSS(v)))
#endif

/* --- Register HW_SPDIF_SIE, field RXFIFORESYN[3] (RW)
 *
 * Rx FIFO resync
 */

#define BP_SPDIF_SIE_RXFIFORESYN      (3)      //!< Bit position for SPDIF_SIE_RXFIFORESYN.
#define BM_SPDIF_SIE_RXFIFORESYN      (0x00000008)  //!< Bit mask for SPDIF_SIE_RXFIFORESYN.

//! @brief Get value of SPDIF_SIE_RXFIFORESYN from a register value.
#define BG_SPDIF_SIE_RXFIFORESYN(r)   (((r) & BM_SPDIF_SIE_RXFIFORESYN) >> BP_SPDIF_SIE_RXFIFORESYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_RXFIFORESYN.
#define BF_SPDIF_SIE_RXFIFORESYN(v)   ((((reg32_t) v) << BP_SPDIF_SIE_RXFIFORESYN) & BM_SPDIF_SIE_RXFIFORESYN)
#else
//! @brief Format value for bitfield SPDIF_SIE_RXFIFORESYN.
#define BF_SPDIF_SIE_RXFIFORESYN(v)   (((v) << BP_SPDIF_SIE_RXFIFORESYN) & BM_SPDIF_SIE_RXFIFORESYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFORESYN field to a new value.
#define BW_SPDIF_SIE_RXFIFORESYN(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_RXFIFORESYN) | BF_SPDIF_SIE_RXFIFORESYN(v)))
#endif

/* --- Register HW_SPDIF_SIE, field RXFIFOUNOV[4] (RW)
 *
 * Rx FIFO underrun/overrun
 */

#define BP_SPDIF_SIE_RXFIFOUNOV      (4)      //!< Bit position for SPDIF_SIE_RXFIFOUNOV.
#define BM_SPDIF_SIE_RXFIFOUNOV      (0x00000010)  //!< Bit mask for SPDIF_SIE_RXFIFOUNOV.

//! @brief Get value of SPDIF_SIE_RXFIFOUNOV from a register value.
#define BG_SPDIF_SIE_RXFIFOUNOV(r)   (((r) & BM_SPDIF_SIE_RXFIFOUNOV) >> BP_SPDIF_SIE_RXFIFOUNOV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_RXFIFOUNOV.
#define BF_SPDIF_SIE_RXFIFOUNOV(v)   ((((reg32_t) v) << BP_SPDIF_SIE_RXFIFOUNOV) & BM_SPDIF_SIE_RXFIFOUNOV)
#else
//! @brief Format value for bitfield SPDIF_SIE_RXFIFOUNOV.
#define BF_SPDIF_SIE_RXFIFOUNOV(v)   (((v) << BP_SPDIF_SIE_RXFIFOUNOV) & BM_SPDIF_SIE_RXFIFOUNOV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFIFOUNOV field to a new value.
#define BW_SPDIF_SIE_RXFIFOUNOV(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_RXFIFOUNOV) | BF_SPDIF_SIE_RXFIFOUNOV(v)))
#endif

/* --- Register HW_SPDIF_SIE, field UQERR[5] (RW)
 *
 * U/Q Channel framing error
 */

#define BP_SPDIF_SIE_UQERR      (5)      //!< Bit position for SPDIF_SIE_UQERR.
#define BM_SPDIF_SIE_UQERR      (0x00000020)  //!< Bit mask for SPDIF_SIE_UQERR.

//! @brief Get value of SPDIF_SIE_UQERR from a register value.
#define BG_SPDIF_SIE_UQERR(r)   (((r) & BM_SPDIF_SIE_UQERR) >> BP_SPDIF_SIE_UQERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_UQERR.
#define BF_SPDIF_SIE_UQERR(v)   ((((reg32_t) v) << BP_SPDIF_SIE_UQERR) & BM_SPDIF_SIE_UQERR)
#else
//! @brief Format value for bitfield SPDIF_SIE_UQERR.
#define BF_SPDIF_SIE_UQERR(v)   (((v) << BP_SPDIF_SIE_UQERR) & BM_SPDIF_SIE_UQERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UQERR field to a new value.
#define BW_SPDIF_SIE_UQERR(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_UQERR) | BF_SPDIF_SIE_UQERR(v)))
#endif

/* --- Register HW_SPDIF_SIE, field UQSYNC[6] (RW)
 *
 * U/Q Channel sync found
 */

#define BP_SPDIF_SIE_UQSYNC      (6)      //!< Bit position for SPDIF_SIE_UQSYNC.
#define BM_SPDIF_SIE_UQSYNC      (0x00000040)  //!< Bit mask for SPDIF_SIE_UQSYNC.

//! @brief Get value of SPDIF_SIE_UQSYNC from a register value.
#define BG_SPDIF_SIE_UQSYNC(r)   (((r) & BM_SPDIF_SIE_UQSYNC) >> BP_SPDIF_SIE_UQSYNC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_UQSYNC.
#define BF_SPDIF_SIE_UQSYNC(v)   ((((reg32_t) v) << BP_SPDIF_SIE_UQSYNC) & BM_SPDIF_SIE_UQSYNC)
#else
//! @brief Format value for bitfield SPDIF_SIE_UQSYNC.
#define BF_SPDIF_SIE_UQSYNC(v)   (((v) << BP_SPDIF_SIE_UQSYNC) & BM_SPDIF_SIE_UQSYNC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UQSYNC field to a new value.
#define BW_SPDIF_SIE_UQSYNC(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_UQSYNC) | BF_SPDIF_SIE_UQSYNC(v)))
#endif

/* --- Register HW_SPDIF_SIE, field QRXOV[7] (RW)
 *
 * Q Channel receive register overrun
 */

#define BP_SPDIF_SIE_QRXOV      (7)      //!< Bit position for SPDIF_SIE_QRXOV.
#define BM_SPDIF_SIE_QRXOV      (0x00000080)  //!< Bit mask for SPDIF_SIE_QRXOV.

//! @brief Get value of SPDIF_SIE_QRXOV from a register value.
#define BG_SPDIF_SIE_QRXOV(r)   (((r) & BM_SPDIF_SIE_QRXOV) >> BP_SPDIF_SIE_QRXOV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_QRXOV.
#define BF_SPDIF_SIE_QRXOV(v)   ((((reg32_t) v) << BP_SPDIF_SIE_QRXOV) & BM_SPDIF_SIE_QRXOV)
#else
//! @brief Format value for bitfield SPDIF_SIE_QRXOV.
#define BF_SPDIF_SIE_QRXOV(v)   (((v) << BP_SPDIF_SIE_QRXOV) & BM_SPDIF_SIE_QRXOV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the QRXOV field to a new value.
#define BW_SPDIF_SIE_QRXOV(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_QRXOV) | BF_SPDIF_SIE_QRXOV(v)))
#endif

/* --- Register HW_SPDIF_SIE, field QRXFUL[8] (RW)
 *
 * Q Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from Q Rx
 * reg.
 */

#define BP_SPDIF_SIE_QRXFUL      (8)      //!< Bit position for SPDIF_SIE_QRXFUL.
#define BM_SPDIF_SIE_QRXFUL      (0x00000100)  //!< Bit mask for SPDIF_SIE_QRXFUL.

//! @brief Get value of SPDIF_SIE_QRXFUL from a register value.
#define BG_SPDIF_SIE_QRXFUL(r)   (((r) & BM_SPDIF_SIE_QRXFUL) >> BP_SPDIF_SIE_QRXFUL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_QRXFUL.
#define BF_SPDIF_SIE_QRXFUL(v)   ((((reg32_t) v) << BP_SPDIF_SIE_QRXFUL) & BM_SPDIF_SIE_QRXFUL)
#else
//! @brief Format value for bitfield SPDIF_SIE_QRXFUL.
#define BF_SPDIF_SIE_QRXFUL(v)   (((v) << BP_SPDIF_SIE_QRXFUL) & BM_SPDIF_SIE_QRXFUL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the QRXFUL field to a new value.
#define BW_SPDIF_SIE_QRXFUL(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_QRXFUL) | BF_SPDIF_SIE_QRXFUL(v)))
#endif

/* --- Register HW_SPDIF_SIE, field URXOV[9] (RW)
 *
 * U Channel receive register overrun
 */

#define BP_SPDIF_SIE_URXOV      (9)      //!< Bit position for SPDIF_SIE_URXOV.
#define BM_SPDIF_SIE_URXOV      (0x00000200)  //!< Bit mask for SPDIF_SIE_URXOV.

//! @brief Get value of SPDIF_SIE_URXOV from a register value.
#define BG_SPDIF_SIE_URXOV(r)   (((r) & BM_SPDIF_SIE_URXOV) >> BP_SPDIF_SIE_URXOV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_URXOV.
#define BF_SPDIF_SIE_URXOV(v)   ((((reg32_t) v) << BP_SPDIF_SIE_URXOV) & BM_SPDIF_SIE_URXOV)
#else
//! @brief Format value for bitfield SPDIF_SIE_URXOV.
#define BF_SPDIF_SIE_URXOV(v)   (((v) << BP_SPDIF_SIE_URXOV) & BM_SPDIF_SIE_URXOV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the URXOV field to a new value.
#define BW_SPDIF_SIE_URXOV(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_URXOV) | BF_SPDIF_SIE_URXOV(v)))
#endif

/* --- Register HW_SPDIF_SIE, field URXFUL[10] (RW)
 *
 * U Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from U Rx
 * reg.
 */

#define BP_SPDIF_SIE_URXFUL      (10)      //!< Bit position for SPDIF_SIE_URXFUL.
#define BM_SPDIF_SIE_URXFUL      (0x00000400)  //!< Bit mask for SPDIF_SIE_URXFUL.

//! @brief Get value of SPDIF_SIE_URXFUL from a register value.
#define BG_SPDIF_SIE_URXFUL(r)   (((r) & BM_SPDIF_SIE_URXFUL) >> BP_SPDIF_SIE_URXFUL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_URXFUL.
#define BF_SPDIF_SIE_URXFUL(v)   ((((reg32_t) v) << BP_SPDIF_SIE_URXFUL) & BM_SPDIF_SIE_URXFUL)
#else
//! @brief Format value for bitfield SPDIF_SIE_URXFUL.
#define BF_SPDIF_SIE_URXFUL(v)   (((v) << BP_SPDIF_SIE_URXFUL) & BM_SPDIF_SIE_URXFUL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the URXFUL field to a new value.
#define BW_SPDIF_SIE_URXFUL(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_URXFUL) | BF_SPDIF_SIE_URXFUL(v)))
#endif

/* --- Register HW_SPDIF_SIE, field BITERR[14] (RW)
 *
 * SPDIF receiver found parity bit error
 */

#define BP_SPDIF_SIE_BITERR      (14)      //!< Bit position for SPDIF_SIE_BITERR.
#define BM_SPDIF_SIE_BITERR      (0x00004000)  //!< Bit mask for SPDIF_SIE_BITERR.

//! @brief Get value of SPDIF_SIE_BITERR from a register value.
#define BG_SPDIF_SIE_BITERR(r)   (((r) & BM_SPDIF_SIE_BITERR) >> BP_SPDIF_SIE_BITERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_BITERR.
#define BF_SPDIF_SIE_BITERR(v)   ((((reg32_t) v) << BP_SPDIF_SIE_BITERR) & BM_SPDIF_SIE_BITERR)
#else
//! @brief Format value for bitfield SPDIF_SIE_BITERR.
#define BF_SPDIF_SIE_BITERR(v)   (((v) << BP_SPDIF_SIE_BITERR) & BM_SPDIF_SIE_BITERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITERR field to a new value.
#define BW_SPDIF_SIE_BITERR(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_BITERR) | BF_SPDIF_SIE_BITERR(v)))
#endif

/* --- Register HW_SPDIF_SIE, field SYMERR[15] (RW)
 *
 * SPDIF receiver found illegal symbol
 */

#define BP_SPDIF_SIE_SYMERR      (15)      //!< Bit position for SPDIF_SIE_SYMERR.
#define BM_SPDIF_SIE_SYMERR      (0x00008000)  //!< Bit mask for SPDIF_SIE_SYMERR.

//! @brief Get value of SPDIF_SIE_SYMERR from a register value.
#define BG_SPDIF_SIE_SYMERR(r)   (((r) & BM_SPDIF_SIE_SYMERR) >> BP_SPDIF_SIE_SYMERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_SYMERR.
#define BF_SPDIF_SIE_SYMERR(v)   ((((reg32_t) v) << BP_SPDIF_SIE_SYMERR) & BM_SPDIF_SIE_SYMERR)
#else
//! @brief Format value for bitfield SPDIF_SIE_SYMERR.
#define BF_SPDIF_SIE_SYMERR(v)   (((v) << BP_SPDIF_SIE_SYMERR) & BM_SPDIF_SIE_SYMERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYMERR field to a new value.
#define BW_SPDIF_SIE_SYMERR(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_SYMERR) | BF_SPDIF_SIE_SYMERR(v)))
#endif

/* --- Register HW_SPDIF_SIE, field VALNOGOOD[16] (RW)
 *
 * SPDIF validity flag no good
 */

#define BP_SPDIF_SIE_VALNOGOOD      (16)      //!< Bit position for SPDIF_SIE_VALNOGOOD.
#define BM_SPDIF_SIE_VALNOGOOD      (0x00010000)  //!< Bit mask for SPDIF_SIE_VALNOGOOD.

//! @brief Get value of SPDIF_SIE_VALNOGOOD from a register value.
#define BG_SPDIF_SIE_VALNOGOOD(r)   (((r) & BM_SPDIF_SIE_VALNOGOOD) >> BP_SPDIF_SIE_VALNOGOOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_VALNOGOOD.
#define BF_SPDIF_SIE_VALNOGOOD(v)   ((((reg32_t) v) << BP_SPDIF_SIE_VALNOGOOD) & BM_SPDIF_SIE_VALNOGOOD)
#else
//! @brief Format value for bitfield SPDIF_SIE_VALNOGOOD.
#define BF_SPDIF_SIE_VALNOGOOD(v)   (((v) << BP_SPDIF_SIE_VALNOGOOD) & BM_SPDIF_SIE_VALNOGOOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALNOGOOD field to a new value.
#define BW_SPDIF_SIE_VALNOGOOD(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_VALNOGOOD) | BF_SPDIF_SIE_VALNOGOOD(v)))
#endif

/* --- Register HW_SPDIF_SIE, field CNEW[17] (RW)
 *
 * SPDIF receive change in value of control channel
 */

#define BP_SPDIF_SIE_CNEW      (17)      //!< Bit position for SPDIF_SIE_CNEW.
#define BM_SPDIF_SIE_CNEW      (0x00020000)  //!< Bit mask for SPDIF_SIE_CNEW.

//! @brief Get value of SPDIF_SIE_CNEW from a register value.
#define BG_SPDIF_SIE_CNEW(r)   (((r) & BM_SPDIF_SIE_CNEW) >> BP_SPDIF_SIE_CNEW)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_CNEW.
#define BF_SPDIF_SIE_CNEW(v)   ((((reg32_t) v) << BP_SPDIF_SIE_CNEW) & BM_SPDIF_SIE_CNEW)
#else
//! @brief Format value for bitfield SPDIF_SIE_CNEW.
#define BF_SPDIF_SIE_CNEW(v)   (((v) << BP_SPDIF_SIE_CNEW) & BM_SPDIF_SIE_CNEW)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNEW field to a new value.
#define BW_SPDIF_SIE_CNEW(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_CNEW) | BF_SPDIF_SIE_CNEW(v)))
#endif

/* --- Register HW_SPDIF_SIE, field TXRESYN[18] (RW)
 *
 * SPDIF Tx FIFO resync
 */

#define BP_SPDIF_SIE_TXRESYN      (18)      //!< Bit position for SPDIF_SIE_TXRESYN.
#define BM_SPDIF_SIE_TXRESYN      (0x00040000)  //!< Bit mask for SPDIF_SIE_TXRESYN.

//! @brief Get value of SPDIF_SIE_TXRESYN from a register value.
#define BG_SPDIF_SIE_TXRESYN(r)   (((r) & BM_SPDIF_SIE_TXRESYN) >> BP_SPDIF_SIE_TXRESYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_TXRESYN.
#define BF_SPDIF_SIE_TXRESYN(v)   ((((reg32_t) v) << BP_SPDIF_SIE_TXRESYN) & BM_SPDIF_SIE_TXRESYN)
#else
//! @brief Format value for bitfield SPDIF_SIE_TXRESYN.
#define BF_SPDIF_SIE_TXRESYN(v)   (((v) << BP_SPDIF_SIE_TXRESYN) & BM_SPDIF_SIE_TXRESYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRESYN field to a new value.
#define BW_SPDIF_SIE_TXRESYN(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_TXRESYN) | BF_SPDIF_SIE_TXRESYN(v)))
#endif

/* --- Register HW_SPDIF_SIE, field TXUNOV[19] (RW)
 *
 * SPDIF Tx FIFO under/overrun
 */

#define BP_SPDIF_SIE_TXUNOV      (19)      //!< Bit position for SPDIF_SIE_TXUNOV.
#define BM_SPDIF_SIE_TXUNOV      (0x00080000)  //!< Bit mask for SPDIF_SIE_TXUNOV.

//! @brief Get value of SPDIF_SIE_TXUNOV from a register value.
#define BG_SPDIF_SIE_TXUNOV(r)   (((r) & BM_SPDIF_SIE_TXUNOV) >> BP_SPDIF_SIE_TXUNOV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_TXUNOV.
#define BF_SPDIF_SIE_TXUNOV(v)   ((((reg32_t) v) << BP_SPDIF_SIE_TXUNOV) & BM_SPDIF_SIE_TXUNOV)
#else
//! @brief Format value for bitfield SPDIF_SIE_TXUNOV.
#define BF_SPDIF_SIE_TXUNOV(v)   (((v) << BP_SPDIF_SIE_TXUNOV) & BM_SPDIF_SIE_TXUNOV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXUNOV field to a new value.
#define BW_SPDIF_SIE_TXUNOV(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_TXUNOV) | BF_SPDIF_SIE_TXUNOV(v)))
#endif

/* --- Register HW_SPDIF_SIE, field LOCK[20] (RW)
 *
 * SPDIF receiver's DPLL is locked
 */

#define BP_SPDIF_SIE_LOCK      (20)      //!< Bit position for SPDIF_SIE_LOCK.
#define BM_SPDIF_SIE_LOCK      (0x00100000)  //!< Bit mask for SPDIF_SIE_LOCK.

//! @brief Get value of SPDIF_SIE_LOCK from a register value.
#define BG_SPDIF_SIE_LOCK(r)   (((r) & BM_SPDIF_SIE_LOCK) >> BP_SPDIF_SIE_LOCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_SIE_LOCK.
#define BF_SPDIF_SIE_LOCK(v)   ((((reg32_t) v) << BP_SPDIF_SIE_LOCK) & BM_SPDIF_SIE_LOCK)
#else
//! @brief Format value for bitfield SPDIF_SIE_LOCK.
#define BF_SPDIF_SIE_LOCK(v)   (((v) << BP_SPDIF_SIE_LOCK) & BM_SPDIF_SIE_LOCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK field to a new value.
#define BW_SPDIF_SIE_LOCK(v)   (HW_SPDIF_SIE_WR((HW_SPDIF_SIE_RD() & ~BM_SPDIF_SIE_LOCK) | BF_SPDIF_SIE_LOCK(v)))
#endif

/* --- Register HW_SPDIF_SIE, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SIE_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SIE_UNIMPLEMENTED.
#define BM_SPDIF_SIE_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SIE_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SIE_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SIE_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SIE_UNIMPLEMENTED) >> BP_SPDIF_SIE_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SIS - InterruptStat Register (RO)
 *
 * Reset value: 0x00000002
 *
 * The InterruptStat (SPDIF_SIS) register is a read only register that provides the status on
 * interrupt operations.
 */
typedef union _hw_spdif_sis
{
    reg32_t U;
    struct _hw_spdif_sis_bitfields
    {
        unsigned RXFIFOFUL : 1; //!< [0] SPDIF Rx FIFO full, can't be cleared with reg. IntClear. To clear it, read from Rx FIFO.
        unsigned TXEM : 1; //!< [1] SPDIF Tx FIFO empty, can't be cleared with reg. IntClear. To clear it, write toTx FIFO.
        unsigned LOCKLOSS : 1; //!< [2] SPDIF receiver loss of lock
        unsigned RXFIFORESYN : 1; //!< [3] Rx FIFO resync
        unsigned RXFIFOUNOV : 1; //!< [4] Rx FIFO underrun/overrun
        unsigned UQERR : 1; //!< [5] U/Q Channel framing error
        unsigned UQSYNC : 1; //!< [6] U/Q Channel sync found
        unsigned QRXOV : 1; //!< [7] Q Channel receive register overrun
        unsigned QRXFUL : 1; //!< [8] Q Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from Q Rx reg.
        unsigned URXOV : 1; //!< [9] U Channel receive register overrun
        unsigned URXFUL : 1; //!< [10] U Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from U Rx reg.
        unsigned RESERVED0 : 3; //!< [13:11] Reserved. Return zeros when read
        unsigned BITERR : 1; //!< [14] SPDIF receiver found parity bit error
        unsigned SYMERR : 1; //!< [15] SPDIF receiver found illegal symbol
        unsigned VALNOGOOD : 1; //!< [16] SPDIF validity flag no good
        unsigned CNEW : 1; //!< [17] SPDIF receive change in value of control channel
        unsigned TXRESYN : 1; //!< [18] SPDIF Tx FIFO resync
        unsigned TXUNOV : 1; //!< [19] SPDIF Tx FIFO under/overrun
        unsigned LOCK : 1; //!< [20] SPDIF receiver's DPLL is locked
        unsigned RESERVED1 : 3; //!< [23:21] Reserved, for InterruptStat/Clear return zeros when read.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SIS, field RXFIFOFUL[0] (RO)
 *
 * SPDIF Rx FIFO full, can't be cleared with reg. IntClear. To clear it, read from Rx FIFO.
 */

#define BP_SPDIF_SIS_RXFIFOFUL      (0)      //!< Bit position for SPDIF_SIS_RXFIFOFUL.
#define BM_SPDIF_SIS_RXFIFOFUL      (0x00000001)  //!< Bit mask for SPDIF_SIS_RXFIFOFUL.

//! @brief Get value of SPDIF_SIS_RXFIFOFUL from a register value.
#define BG_SPDIF_SIS_RXFIFOFUL(r)   (((r) & BM_SPDIF_SIS_RXFIFOFUL) >> BP_SPDIF_SIS_RXFIFOFUL)

/* --- Register HW_SPDIF_SIS, field TXEM[1] (RO)
 *
 * SPDIF Tx FIFO empty, can't be cleared with reg. IntClear. To clear it, write toTx FIFO.
 */

#define BP_SPDIF_SIS_TXEM      (1)      //!< Bit position for SPDIF_SIS_TXEM.
#define BM_SPDIF_SIS_TXEM      (0x00000002)  //!< Bit mask for SPDIF_SIS_TXEM.

//! @brief Get value of SPDIF_SIS_TXEM from a register value.
#define BG_SPDIF_SIS_TXEM(r)   (((r) & BM_SPDIF_SIS_TXEM) >> BP_SPDIF_SIS_TXEM)

/* --- Register HW_SPDIF_SIS, field LOCKLOSS[2] (RO)
 *
 * SPDIF receiver loss of lock
 */

#define BP_SPDIF_SIS_LOCKLOSS      (2)      //!< Bit position for SPDIF_SIS_LOCKLOSS.
#define BM_SPDIF_SIS_LOCKLOSS      (0x00000004)  //!< Bit mask for SPDIF_SIS_LOCKLOSS.

//! @brief Get value of SPDIF_SIS_LOCKLOSS from a register value.
#define BG_SPDIF_SIS_LOCKLOSS(r)   (((r) & BM_SPDIF_SIS_LOCKLOSS) >> BP_SPDIF_SIS_LOCKLOSS)

/* --- Register HW_SPDIF_SIS, field RXFIFORESYN[3] (RO)
 *
 * Rx FIFO resync
 */

#define BP_SPDIF_SIS_RXFIFORESYN      (3)      //!< Bit position for SPDIF_SIS_RXFIFORESYN.
#define BM_SPDIF_SIS_RXFIFORESYN      (0x00000008)  //!< Bit mask for SPDIF_SIS_RXFIFORESYN.

//! @brief Get value of SPDIF_SIS_RXFIFORESYN from a register value.
#define BG_SPDIF_SIS_RXFIFORESYN(r)   (((r) & BM_SPDIF_SIS_RXFIFORESYN) >> BP_SPDIF_SIS_RXFIFORESYN)

/* --- Register HW_SPDIF_SIS, field RXFIFOUNOV[4] (RO)
 *
 * Rx FIFO underrun/overrun
 */

#define BP_SPDIF_SIS_RXFIFOUNOV      (4)      //!< Bit position for SPDIF_SIS_RXFIFOUNOV.
#define BM_SPDIF_SIS_RXFIFOUNOV      (0x00000010)  //!< Bit mask for SPDIF_SIS_RXFIFOUNOV.

//! @brief Get value of SPDIF_SIS_RXFIFOUNOV from a register value.
#define BG_SPDIF_SIS_RXFIFOUNOV(r)   (((r) & BM_SPDIF_SIS_RXFIFOUNOV) >> BP_SPDIF_SIS_RXFIFOUNOV)

/* --- Register HW_SPDIF_SIS, field UQERR[5] (RO)
 *
 * U/Q Channel framing error
 */

#define BP_SPDIF_SIS_UQERR      (5)      //!< Bit position for SPDIF_SIS_UQERR.
#define BM_SPDIF_SIS_UQERR      (0x00000020)  //!< Bit mask for SPDIF_SIS_UQERR.

//! @brief Get value of SPDIF_SIS_UQERR from a register value.
#define BG_SPDIF_SIS_UQERR(r)   (((r) & BM_SPDIF_SIS_UQERR) >> BP_SPDIF_SIS_UQERR)

/* --- Register HW_SPDIF_SIS, field UQSYNC[6] (RO)
 *
 * U/Q Channel sync found
 */

#define BP_SPDIF_SIS_UQSYNC      (6)      //!< Bit position for SPDIF_SIS_UQSYNC.
#define BM_SPDIF_SIS_UQSYNC      (0x00000040)  //!< Bit mask for SPDIF_SIS_UQSYNC.

//! @brief Get value of SPDIF_SIS_UQSYNC from a register value.
#define BG_SPDIF_SIS_UQSYNC(r)   (((r) & BM_SPDIF_SIS_UQSYNC) >> BP_SPDIF_SIS_UQSYNC)

/* --- Register HW_SPDIF_SIS, field QRXOV[7] (RO)
 *
 * Q Channel receive register overrun
 */

#define BP_SPDIF_SIS_QRXOV      (7)      //!< Bit position for SPDIF_SIS_QRXOV.
#define BM_SPDIF_SIS_QRXOV      (0x00000080)  //!< Bit mask for SPDIF_SIS_QRXOV.

//! @brief Get value of SPDIF_SIS_QRXOV from a register value.
#define BG_SPDIF_SIS_QRXOV(r)   (((r) & BM_SPDIF_SIS_QRXOV) >> BP_SPDIF_SIS_QRXOV)

/* --- Register HW_SPDIF_SIS, field QRXFUL[8] (RO)
 *
 * Q Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from Q Rx
 * reg.
 */

#define BP_SPDIF_SIS_QRXFUL      (8)      //!< Bit position for SPDIF_SIS_QRXFUL.
#define BM_SPDIF_SIS_QRXFUL      (0x00000100)  //!< Bit mask for SPDIF_SIS_QRXFUL.

//! @brief Get value of SPDIF_SIS_QRXFUL from a register value.
#define BG_SPDIF_SIS_QRXFUL(r)   (((r) & BM_SPDIF_SIS_QRXFUL) >> BP_SPDIF_SIS_QRXFUL)

/* --- Register HW_SPDIF_SIS, field URXOV[9] (RO)
 *
 * U Channel receive register overrun
 */

#define BP_SPDIF_SIS_URXOV      (9)      //!< Bit position for SPDIF_SIS_URXOV.
#define BM_SPDIF_SIS_URXOV      (0x00000200)  //!< Bit mask for SPDIF_SIS_URXOV.

//! @brief Get value of SPDIF_SIS_URXOV from a register value.
#define BG_SPDIF_SIS_URXOV(r)   (((r) & BM_SPDIF_SIS_URXOV) >> BP_SPDIF_SIS_URXOV)

/* --- Register HW_SPDIF_SIS, field URXFUL[10] (RO)
 *
 * U Channel receive register full, can't be cleared with reg. IntClear. To clear it, read from U Rx
 * reg.
 */

#define BP_SPDIF_SIS_URXFUL      (10)      //!< Bit position for SPDIF_SIS_URXFUL.
#define BM_SPDIF_SIS_URXFUL      (0x00000400)  //!< Bit mask for SPDIF_SIS_URXFUL.

//! @brief Get value of SPDIF_SIS_URXFUL from a register value.
#define BG_SPDIF_SIS_URXFUL(r)   (((r) & BM_SPDIF_SIS_URXFUL) >> BP_SPDIF_SIS_URXFUL)

/* --- Register HW_SPDIF_SIS, field BITERR[14] (RO)
 *
 * SPDIF receiver found parity bit error
 */

#define BP_SPDIF_SIS_BITERR      (14)      //!< Bit position for SPDIF_SIS_BITERR.
#define BM_SPDIF_SIS_BITERR      (0x00004000)  //!< Bit mask for SPDIF_SIS_BITERR.

//! @brief Get value of SPDIF_SIS_BITERR from a register value.
#define BG_SPDIF_SIS_BITERR(r)   (((r) & BM_SPDIF_SIS_BITERR) >> BP_SPDIF_SIS_BITERR)

/* --- Register HW_SPDIF_SIS, field SYMERR[15] (RO)
 *
 * SPDIF receiver found illegal symbol
 */

#define BP_SPDIF_SIS_SYMERR      (15)      //!< Bit position for SPDIF_SIS_SYMERR.
#define BM_SPDIF_SIS_SYMERR      (0x00008000)  //!< Bit mask for SPDIF_SIS_SYMERR.

//! @brief Get value of SPDIF_SIS_SYMERR from a register value.
#define BG_SPDIF_SIS_SYMERR(r)   (((r) & BM_SPDIF_SIS_SYMERR) >> BP_SPDIF_SIS_SYMERR)

/* --- Register HW_SPDIF_SIS, field VALNOGOOD[16] (RO)
 *
 * SPDIF validity flag no good
 */

#define BP_SPDIF_SIS_VALNOGOOD      (16)      //!< Bit position for SPDIF_SIS_VALNOGOOD.
#define BM_SPDIF_SIS_VALNOGOOD      (0x00010000)  //!< Bit mask for SPDIF_SIS_VALNOGOOD.

//! @brief Get value of SPDIF_SIS_VALNOGOOD from a register value.
#define BG_SPDIF_SIS_VALNOGOOD(r)   (((r) & BM_SPDIF_SIS_VALNOGOOD) >> BP_SPDIF_SIS_VALNOGOOD)

/* --- Register HW_SPDIF_SIS, field CNEW[17] (RO)
 *
 * SPDIF receive change in value of control channel
 */

#define BP_SPDIF_SIS_CNEW      (17)      //!< Bit position for SPDIF_SIS_CNEW.
#define BM_SPDIF_SIS_CNEW      (0x00020000)  //!< Bit mask for SPDIF_SIS_CNEW.

//! @brief Get value of SPDIF_SIS_CNEW from a register value.
#define BG_SPDIF_SIS_CNEW(r)   (((r) & BM_SPDIF_SIS_CNEW) >> BP_SPDIF_SIS_CNEW)

/* --- Register HW_SPDIF_SIS, field TXRESYN[18] (RO)
 *
 * SPDIF Tx FIFO resync
 */

#define BP_SPDIF_SIS_TXRESYN      (18)      //!< Bit position for SPDIF_SIS_TXRESYN.
#define BM_SPDIF_SIS_TXRESYN      (0x00040000)  //!< Bit mask for SPDIF_SIS_TXRESYN.

//! @brief Get value of SPDIF_SIS_TXRESYN from a register value.
#define BG_SPDIF_SIS_TXRESYN(r)   (((r) & BM_SPDIF_SIS_TXRESYN) >> BP_SPDIF_SIS_TXRESYN)

/* --- Register HW_SPDIF_SIS, field TXUNOV[19] (RO)
 *
 * SPDIF Tx FIFO under/overrun
 */

#define BP_SPDIF_SIS_TXUNOV      (19)      //!< Bit position for SPDIF_SIS_TXUNOV.
#define BM_SPDIF_SIS_TXUNOV      (0x00080000)  //!< Bit mask for SPDIF_SIS_TXUNOV.

//! @brief Get value of SPDIF_SIS_TXUNOV from a register value.
#define BG_SPDIF_SIS_TXUNOV(r)   (((r) & BM_SPDIF_SIS_TXUNOV) >> BP_SPDIF_SIS_TXUNOV)

/* --- Register HW_SPDIF_SIS, field LOCK[20] (RO)
 *
 * SPDIF receiver's DPLL is locked
 */

#define BP_SPDIF_SIS_LOCK      (20)      //!< Bit position for SPDIF_SIS_LOCK.
#define BM_SPDIF_SIS_LOCK      (0x00100000)  //!< Bit mask for SPDIF_SIS_LOCK.

//! @brief Get value of SPDIF_SIS_LOCK from a register value.
#define BG_SPDIF_SIS_LOCK(r)   (((r) & BM_SPDIF_SIS_LOCK) >> BP_SPDIF_SIS_LOCK)

/* --- Register HW_SPDIF_SIS, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SIS_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SIS_UNIMPLEMENTED.
#define BM_SPDIF_SIS_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SIS_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SIS_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SIS_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SIS_UNIMPLEMENTED) >> BP_SPDIF_SIS_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRL - SPDIFRxLeft Register (RO)
 *
 * Reset value: 0x00000000
 *
 * SPDIFRxLeft register is an audio data reception register.
 */
typedef union _hw_spdif_srl
{
    reg32_t U;
    struct _hw_spdif_srl_bitfields
    {
        unsigned RXDATALEFT : 24; //!< [23:0] Processor receive SPDIF data left
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SRL, field RXDATALEFT[23:0] (RO)
 *
 * Processor receive SPDIF data left
 */

#define BP_SPDIF_SRL_RXDATALEFT      (0)      //!< Bit position for SPDIF_SRL_RXDATALEFT.
#define BM_SPDIF_SRL_RXDATALEFT      (0x00ffffff)  //!< Bit mask for SPDIF_SRL_RXDATALEFT.

//! @brief Get value of SPDIF_SRL_RXDATALEFT from a register value.
#define BG_SPDIF_SRL_RXDATALEFT(r)   (((r) & BM_SPDIF_SRL_RXDATALEFT) >> BP_SPDIF_SRL_RXDATALEFT)

/* --- Register HW_SPDIF_SRL, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SRL_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRL_UNIMPLEMENTED.
#define BM_SPDIF_SRL_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRL_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRL_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRL_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRL_UNIMPLEMENTED) >> BP_SPDIF_SRL_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRR - SPDIFRxRight Register (RO)
 *
 * Reset value: 0x00000000
 *
 * SPDIFRxRight register is an audio data reception register.
 */
typedef union _hw_spdif_srr
{
    reg32_t U;
    struct _hw_spdif_srr_bitfields
    {
        unsigned RXDATARIGHT : 24; //!< [23:0] Processor receive SPDIF data right
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SRR, field RXDATARIGHT[23:0] (RO)
 *
 * Processor receive SPDIF data right
 */

#define BP_SPDIF_SRR_RXDATARIGHT      (0)      //!< Bit position for SPDIF_SRR_RXDATARIGHT.
#define BM_SPDIF_SRR_RXDATARIGHT      (0x00ffffff)  //!< Bit mask for SPDIF_SRR_RXDATARIGHT.

//! @brief Get value of SPDIF_SRR_RXDATARIGHT from a register value.
#define BG_SPDIF_SRR_RXDATARIGHT(r)   (((r) & BM_SPDIF_SRR_RXDATARIGHT) >> BP_SPDIF_SRR_RXDATARIGHT)

/* --- Register HW_SPDIF_SRR, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SRR_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRR_UNIMPLEMENTED.
#define BM_SPDIF_SRR_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRR_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRR_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRR_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRR_UNIMPLEMENTED) >> BP_SPDIF_SRR_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRCSH - SPDIFRxCChannel_h Register (RO)
 *
 * Reset value: 0x00000000
 *
 * SPDIFRxCChannel_h register is a channel status reception register.
 */
typedef union _hw_spdif_srcsh
{
    reg32_t U;
    struct _hw_spdif_srcsh_bitfields
    {
        unsigned RXCCHANNEL_H : 24; //!< [23:0] SPDIF receive C channel register, contains first 24 bits of C channel without interpretation
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SRCSH, field RXCCHANNEL_H[23:0] (RO)
 *
 * SPDIF receive C channel register, contains first 24 bits of C channel without interpretation
 */

#define BP_SPDIF_SRCSH_RXCCHANNEL_H      (0)      //!< Bit position for SPDIF_SRCSH_RXCCHANNEL_H.
#define BM_SPDIF_SRCSH_RXCCHANNEL_H      (0x00ffffff)  //!< Bit mask for SPDIF_SRCSH_RXCCHANNEL_H.

//! @brief Get value of SPDIF_SRCSH_RXCCHANNEL_H from a register value.
#define BG_SPDIF_SRCSH_RXCCHANNEL_H(r)   (((r) & BM_SPDIF_SRCSH_RXCCHANNEL_H) >> BP_SPDIF_SRCSH_RXCCHANNEL_H)

/* --- Register HW_SPDIF_SRCSH, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SRCSH_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRCSH_UNIMPLEMENTED.
#define BM_SPDIF_SRCSH_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRCSH_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRCSH_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRCSH_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRCSH_UNIMPLEMENTED) >> BP_SPDIF_SRCSH_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRCSL - SPDIFRxCChannel_l Register (RO)
 *
 * Reset value: 0x00000000
 *
 * SPDIFRxCChannel_l register is a channel status reception register.
 */
typedef union _hw_spdif_srcsl
{
    reg32_t U;
    struct _hw_spdif_srcsl_bitfields
    {
        unsigned RXCCHANNEL_L : 24; //!< [23:0] SPDIF receive C channel register, contains next 24 bits of C channel without interpretation
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SRCSL, field RXCCHANNEL_L[23:0] (RO)
 *
 * SPDIF receive C channel register, contains next 24 bits of C channel without interpretation
 */

#define BP_SPDIF_SRCSL_RXCCHANNEL_L      (0)      //!< Bit position for SPDIF_SRCSL_RXCCHANNEL_L.
#define BM_SPDIF_SRCSL_RXCCHANNEL_L      (0x00ffffff)  //!< Bit mask for SPDIF_SRCSL_RXCCHANNEL_L.

//! @brief Get value of SPDIF_SRCSL_RXCCHANNEL_L from a register value.
#define BG_SPDIF_SRCSL_RXCCHANNEL_L(r)   (((r) & BM_SPDIF_SRCSL_RXCCHANNEL_L) >> BP_SPDIF_SRCSL_RXCCHANNEL_L)

/* --- Register HW_SPDIF_SRCSL, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SRCSL_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRCSL_UNIMPLEMENTED.
#define BM_SPDIF_SRCSL_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRCSL_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRCSL_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRCSL_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRCSL_UNIMPLEMENTED) >> BP_SPDIF_SRCSL_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRU - UchannelRx Register (RO)
 *
 * Reset value: 0x00000000
 *
 * UChannelRx register is a user bits reception register.
 */
typedef union _hw_spdif_sru
{
    reg32_t U;
    struct _hw_spdif_sru_bitfields
    {
        unsigned RXUCHANNEL : 24; //!< [23:0] SPDIF receive U channel register, contains next 3 U channel bytes
        unsigned UNIMPLEMENTED : 8; //!< [31:24] This is a 24-bit register the upper byte is unimplemented.
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

/* --- Register HW_SPDIF_SRU, field RXUCHANNEL[23:0] (RO)
 *
 * SPDIF receive U channel register, contains next 3 U channel bytes
 */

#define BP_SPDIF_SRU_RXUCHANNEL      (0)      //!< Bit position for SPDIF_SRU_RXUCHANNEL.
#define BM_SPDIF_SRU_RXUCHANNEL      (0x00ffffff)  //!< Bit mask for SPDIF_SRU_RXUCHANNEL.

//! @brief Get value of SPDIF_SRU_RXUCHANNEL from a register value.
#define BG_SPDIF_SRU_RXUCHANNEL(r)   (((r) & BM_SPDIF_SRU_RXUCHANNEL) >> BP_SPDIF_SRU_RXUCHANNEL)

/* --- Register HW_SPDIF_SRU, field UNIMPLEMENTED[31:24] (RU)
 *
 * This is a 24-bit register the upper byte is unimplemented.
 */

#define BP_SPDIF_SRU_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRU_UNIMPLEMENTED.
#define BM_SPDIF_SRU_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRU_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRU_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRU_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRU_UNIMPLEMENTED) >> BP_SPDIF_SRU_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRQ - QchannelRx Register (RO)
 *
 * Reset value: 0x00000000
 *
 * QChannelRx register is a user bits reception register.
 */
typedef union _hw_spdif_srq
{
    reg32_t U;
    struct _hw_spdif_srq_bitfields
    {
        unsigned RXQCHANNEL : 24; //!< [23:0] SPDIF receive Q channel register, contains next 3 Q channel bytes
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SRQ, field RXQCHANNEL[23:0] (RO)
 *
 * SPDIF receive Q channel register, contains next 3 Q channel bytes
 */

#define BP_SPDIF_SRQ_RXQCHANNEL      (0)      //!< Bit position for SPDIF_SRQ_RXQCHANNEL.
#define BM_SPDIF_SRQ_RXQCHANNEL      (0x00ffffff)  //!< Bit mask for SPDIF_SRQ_RXQCHANNEL.

//! @brief Get value of SPDIF_SRQ_RXQCHANNEL from a register value.
#define BG_SPDIF_SRQ_RXQCHANNEL(r)   (((r) & BM_SPDIF_SRQ_RXQCHANNEL) >> BP_SPDIF_SRQ_RXQCHANNEL)

/* --- Register HW_SPDIF_SRQ, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SRQ_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRQ_UNIMPLEMENTED.
#define BM_SPDIF_SRQ_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRQ_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRQ_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRQ_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRQ_UNIMPLEMENTED) >> BP_SPDIF_SRQ_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STL - SPDIFTxLeft Register (WO)
 *
 * Reset value: 0x00000000
 *
 * SPDIFTxLeft register is an audio data transmission register.
 */
typedef union _hw_spdif_stl
{
    reg32_t U;
    struct _hw_spdif_stl_bitfields
    {
        unsigned TXDATALEFT : 24; //!< [23:0] SPDIF transmit left channel data. It is write-only, and always returns zeros when read
        unsigned UNIMPLEMENTED : 8; //!< [31:24] This is a 24-bit register the upper byte is unimplemented.
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

/* --- Register HW_SPDIF_STL, field TXDATALEFT[23:0] (WO)
 *
 * SPDIF transmit left channel data. It is write-only, and always returns zeros when read
 */

#define BP_SPDIF_STL_TXDATALEFT      (0)      //!< Bit position for SPDIF_STL_TXDATALEFT.
#define BM_SPDIF_STL_TXDATALEFT      (0x00ffffff)  //!< Bit mask for SPDIF_STL_TXDATALEFT.

//! @brief Get value of SPDIF_STL_TXDATALEFT from a register value.
#define BG_SPDIF_STL_TXDATALEFT(r)   (((r) & BM_SPDIF_STL_TXDATALEFT) >> BP_SPDIF_STL_TXDATALEFT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_STL_TXDATALEFT.
#define BF_SPDIF_STL_TXDATALEFT(v)   ((((reg32_t) v) << BP_SPDIF_STL_TXDATALEFT) & BM_SPDIF_STL_TXDATALEFT)
#else
//! @brief Format value for bitfield SPDIF_STL_TXDATALEFT.
#define BF_SPDIF_STL_TXDATALEFT(v)   (((v) << BP_SPDIF_STL_TXDATALEFT) & BM_SPDIF_STL_TXDATALEFT)
#endif

/* --- Register HW_SPDIF_STL, field UNIMPLEMENTED[31:24] (RU)
 *
 * This is a 24-bit register the upper byte is unimplemented.
 */

#define BP_SPDIF_STL_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_STL_UNIMPLEMENTED.
#define BM_SPDIF_STL_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_STL_UNIMPLEMENTED.

//! @brief Get value of SPDIF_STL_UNIMPLEMENTED from a register value.
#define BG_SPDIF_STL_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_STL_UNIMPLEMENTED) >> BP_SPDIF_STL_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STR - SPDIFTxRight Register (WO)
 *
 * Reset value: 0x00000000
 *
 * SPDIFTxRight register is an audio data transmission register.
 */
typedef union _hw_spdif_str
{
    reg32_t U;
    struct _hw_spdif_str_bitfields
    {
        unsigned TXDATARIGHT : 24; //!< [23:0] SPDIF transmit right channel data. It is write-only, and always returns zeros when read
        unsigned UNIMPLEMENTED : 8; //!< [31:24] This is a 24-bit register the upper byte is unimplemented.
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

/* --- Register HW_SPDIF_STR, field TXDATARIGHT[23:0] (WO)
 *
 * SPDIF transmit right channel data. It is write-only, and always returns zeros when read
 */

#define BP_SPDIF_STR_TXDATARIGHT      (0)      //!< Bit position for SPDIF_STR_TXDATARIGHT.
#define BM_SPDIF_STR_TXDATARIGHT      (0x00ffffff)  //!< Bit mask for SPDIF_STR_TXDATARIGHT.

//! @brief Get value of SPDIF_STR_TXDATARIGHT from a register value.
#define BG_SPDIF_STR_TXDATARIGHT(r)   (((r) & BM_SPDIF_STR_TXDATARIGHT) >> BP_SPDIF_STR_TXDATARIGHT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_STR_TXDATARIGHT.
#define BF_SPDIF_STR_TXDATARIGHT(v)   ((((reg32_t) v) << BP_SPDIF_STR_TXDATARIGHT) & BM_SPDIF_STR_TXDATARIGHT)
#else
//! @brief Format value for bitfield SPDIF_STR_TXDATARIGHT.
#define BF_SPDIF_STR_TXDATARIGHT(v)   (((v) << BP_SPDIF_STR_TXDATARIGHT) & BM_SPDIF_STR_TXDATARIGHT)
#endif

/* --- Register HW_SPDIF_STR, field UNIMPLEMENTED[31:24] (RU)
 *
 * This is a 24-bit register the upper byte is unimplemented.
 */

#define BP_SPDIF_STR_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_STR_UNIMPLEMENTED.
#define BM_SPDIF_STR_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_STR_UNIMPLEMENTED.

//! @brief Get value of SPDIF_STR_UNIMPLEMENTED from a register value.
#define BG_SPDIF_STR_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_STR_UNIMPLEMENTED) >> BP_SPDIF_STR_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STCSCH - SPDIFTxCChannelCons_h Register (RW)
 *
 * Reset value: 0x00000000
 *
 * SPDIFTxCChannelCons_h register is a channel status transmission register.
 */
typedef union _hw_spdif_stcsch
{
    reg32_t U;
    struct _hw_spdif_stcsch_bitfields
    {
        unsigned TXCCHANNELCONS_H : 24; //!< [23:0] SPDIF transmit Cons. C channel data, contains first 24 bits without interpretation. When read, it returns the latest data written by the processor
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_STCSCH, field TXCCHANNELCONS_H[23:0] (RW)
 *
 * SPDIF transmit Cons. C channel data, contains first 24 bits without interpretation. When read, it
 * returns the latest data written by the processor
 */

#define BP_SPDIF_STCSCH_TXCCHANNELCONS_H      (0)      //!< Bit position for SPDIF_STCSCH_TXCCHANNELCONS_H.
#define BM_SPDIF_STCSCH_TXCCHANNELCONS_H      (0x00ffffff)  //!< Bit mask for SPDIF_STCSCH_TXCCHANNELCONS_H.

//! @brief Get value of SPDIF_STCSCH_TXCCHANNELCONS_H from a register value.
#define BG_SPDIF_STCSCH_TXCCHANNELCONS_H(r)   (((r) & BM_SPDIF_STCSCH_TXCCHANNELCONS_H) >> BP_SPDIF_STCSCH_TXCCHANNELCONS_H)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_STCSCH_TXCCHANNELCONS_H.
#define BF_SPDIF_STCSCH_TXCCHANNELCONS_H(v)   ((((reg32_t) v) << BP_SPDIF_STCSCH_TXCCHANNELCONS_H) & BM_SPDIF_STCSCH_TXCCHANNELCONS_H)
#else
//! @brief Format value for bitfield SPDIF_STCSCH_TXCCHANNELCONS_H.
#define BF_SPDIF_STCSCH_TXCCHANNELCONS_H(v)   (((v) << BP_SPDIF_STCSCH_TXCCHANNELCONS_H) & BM_SPDIF_STCSCH_TXCCHANNELCONS_H)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCCHANNELCONS_H field to a new value.
#define BW_SPDIF_STCSCH_TXCCHANNELCONS_H(v)   (HW_SPDIF_STCSCH_WR((HW_SPDIF_STCSCH_RD() & ~BM_SPDIF_STCSCH_TXCCHANNELCONS_H) | BF_SPDIF_STCSCH_TXCCHANNELCONS_H(v)))
#endif

/* --- Register HW_SPDIF_STCSCH, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_STCSCH_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_STCSCH_UNIMPLEMENTED.
#define BM_SPDIF_STCSCH_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_STCSCH_UNIMPLEMENTED.

//! @brief Get value of SPDIF_STCSCH_UNIMPLEMENTED from a register value.
#define BG_SPDIF_STCSCH_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_STCSCH_UNIMPLEMENTED) >> BP_SPDIF_STCSCH_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STCSCL - SPDIFTxCChannelCons_l Register (RW)
 *
 * Reset value: 0x00000000
 *
 * SPDIFTxCChannelCons_l register is a channel status transmission register.
 */
typedef union _hw_spdif_stcscl
{
    reg32_t U;
    struct _hw_spdif_stcscl_bitfields
    {
        unsigned TXCCHANNELCONS_L : 24; //!< [23:0] SPDIF transmit Cons. C channel data, contains next 24 bits without interpretation. When read, it returns the latest data written by the processor
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_STCSCL, field TXCCHANNELCONS_L[23:0] (RW)
 *
 * SPDIF transmit Cons. C channel data, contains next 24 bits without interpretation. When read, it
 * returns the latest data written by the processor
 */

#define BP_SPDIF_STCSCL_TXCCHANNELCONS_L      (0)      //!< Bit position for SPDIF_STCSCL_TXCCHANNELCONS_L.
#define BM_SPDIF_STCSCL_TXCCHANNELCONS_L      (0x00ffffff)  //!< Bit mask for SPDIF_STCSCL_TXCCHANNELCONS_L.

//! @brief Get value of SPDIF_STCSCL_TXCCHANNELCONS_L from a register value.
#define BG_SPDIF_STCSCL_TXCCHANNELCONS_L(r)   (((r) & BM_SPDIF_STCSCL_TXCCHANNELCONS_L) >> BP_SPDIF_STCSCL_TXCCHANNELCONS_L)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_STCSCL_TXCCHANNELCONS_L.
#define BF_SPDIF_STCSCL_TXCCHANNELCONS_L(v)   ((((reg32_t) v) << BP_SPDIF_STCSCL_TXCCHANNELCONS_L) & BM_SPDIF_STCSCL_TXCCHANNELCONS_L)
#else
//! @brief Format value for bitfield SPDIF_STCSCL_TXCCHANNELCONS_L.
#define BF_SPDIF_STCSCL_TXCCHANNELCONS_L(v)   (((v) << BP_SPDIF_STCSCL_TXCCHANNELCONS_L) & BM_SPDIF_STCSCL_TXCCHANNELCONS_L)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCCHANNELCONS_L field to a new value.
#define BW_SPDIF_STCSCL_TXCCHANNELCONS_L(v)   (HW_SPDIF_STCSCL_WR((HW_SPDIF_STCSCL_RD() & ~BM_SPDIF_STCSCL_TXCCHANNELCONS_L) | BF_SPDIF_STCSCL_TXCCHANNELCONS_L(v)))
#endif

/* --- Register HW_SPDIF_STCSCL, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_STCSCL_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_STCSCL_UNIMPLEMENTED.
#define BM_SPDIF_STCSCL_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_STCSCL_UNIMPLEMENTED.

//! @brief Get value of SPDIF_STCSCL_UNIMPLEMENTED from a register value.
#define BG_SPDIF_STCSCL_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_STCSCL_UNIMPLEMENTED) >> BP_SPDIF_STCSCL_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_SRFM - FreqMeas Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdif_srfm
{
    reg32_t U;
    struct _hw_spdif_srfm_bitfields
    {
        unsigned FREQMEAS : 24; //!< [23:0] Frequency measurement data
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_SRFM, field FREQMEAS[23:0] (RO)
 *
 * Frequency measurement data
 */

#define BP_SPDIF_SRFM_FREQMEAS      (0)      //!< Bit position for SPDIF_SRFM_FREQMEAS.
#define BM_SPDIF_SRFM_FREQMEAS      (0x00ffffff)  //!< Bit mask for SPDIF_SRFM_FREQMEAS.

//! @brief Get value of SPDIF_SRFM_FREQMEAS from a register value.
#define BG_SPDIF_SRFM_FREQMEAS(r)   (((r) & BM_SPDIF_SRFM_FREQMEAS) >> BP_SPDIF_SRFM_FREQMEAS)

/* --- Register HW_SPDIF_SRFM, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_SRFM_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_SRFM_UNIMPLEMENTED.
#define BM_SPDIF_SRFM_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_SRFM_UNIMPLEMENTED.

//! @brief Get value of SPDIF_SRFM_UNIMPLEMENTED from a register value.
#define BG_SPDIF_SRFM_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_SRFM_UNIMPLEMENTED) >> BP_SPDIF_SRFM_UNIMPLEMENTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDIF_STC - SPDIFTxClk Register (RW)
 *
 * Reset value: 0x00020f00
 *
 * The SPDIFTxClk Control register includes the means to select the transmit clock and frequency
 * division.
 */
typedef union _hw_spdif_stc
{
    reg32_t U;
    struct _hw_spdif_stc_bitfields
    {
        unsigned TXCLK_DF : 7; //!< [6:0] Divider factor (1-128)
        unsigned RESERVED0 : 4; //!< [10:7] Reserved.
        unsigned SYSCLK_DF : 9; //!< [19:11] system clock divider factor, 2~512.
        unsigned RESERVED1 : 4; //!< [23:20] Reserved, return zeros when read
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
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

/* --- Register HW_SPDIF_STC, field TXCLK_DF[6:0] (RW)
 *
 * Divider factor (1-128)
 *
 * Values:
 * 0 - divider factor is 1
 * 1 - divider factor is 2
 * 127 - divider factor is 128
 */

#define BP_SPDIF_STC_TXCLK_DF      (0)      //!< Bit position for SPDIF_STC_TXCLK_DF.
#define BM_SPDIF_STC_TXCLK_DF      (0x0000007f)  //!< Bit mask for SPDIF_STC_TXCLK_DF.

//! @brief Get value of SPDIF_STC_TXCLK_DF from a register value.
#define BG_SPDIF_STC_TXCLK_DF(r)   (((r) & BM_SPDIF_STC_TXCLK_DF) >> BP_SPDIF_STC_TXCLK_DF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_STC_TXCLK_DF.
#define BF_SPDIF_STC_TXCLK_DF(v)   ((((reg32_t) v) << BP_SPDIF_STC_TXCLK_DF) & BM_SPDIF_STC_TXCLK_DF)
#else
//! @brief Format value for bitfield SPDIF_STC_TXCLK_DF.
#define BF_SPDIF_STC_TXCLK_DF(v)   (((v) << BP_SPDIF_STC_TXCLK_DF) & BM_SPDIF_STC_TXCLK_DF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCLK_DF field to a new value.
#define BW_SPDIF_STC_TXCLK_DF(v)   (HW_SPDIF_STC_WR((HW_SPDIF_STC_RD() & ~BM_SPDIF_STC_TXCLK_DF) | BF_SPDIF_STC_TXCLK_DF(v)))
#endif


/* --- Register HW_SPDIF_STC, field SYSCLK_DF[19:11] (RW)
 *
 * system clock divider factor, 2~512.
 *
 * Values:
 * 0 - no clock signal
 * 1 - divider factor is 2
 * 511 - divider factor is 512
 */

#define BP_SPDIF_STC_SYSCLK_DF      (11)      //!< Bit position for SPDIF_STC_SYSCLK_DF.
#define BM_SPDIF_STC_SYSCLK_DF      (0x000ff800)  //!< Bit mask for SPDIF_STC_SYSCLK_DF.

//! @brief Get value of SPDIF_STC_SYSCLK_DF from a register value.
#define BG_SPDIF_STC_SYSCLK_DF(r)   (((r) & BM_SPDIF_STC_SYSCLK_DF) >> BP_SPDIF_STC_SYSCLK_DF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDIF_STC_SYSCLK_DF.
#define BF_SPDIF_STC_SYSCLK_DF(v)   ((((reg32_t) v) << BP_SPDIF_STC_SYSCLK_DF) & BM_SPDIF_STC_SYSCLK_DF)
#else
//! @brief Format value for bitfield SPDIF_STC_SYSCLK_DF.
#define BF_SPDIF_STC_SYSCLK_DF(v)   (((v) << BP_SPDIF_STC_SYSCLK_DF) & BM_SPDIF_STC_SYSCLK_DF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYSCLK_DF field to a new value.
#define BW_SPDIF_STC_SYSCLK_DF(v)   (HW_SPDIF_STC_WR((HW_SPDIF_STC_RD() & ~BM_SPDIF_STC_SYSCLK_DF) | BF_SPDIF_STC_SYSCLK_DF(v)))
#endif


/* --- Register HW_SPDIF_STC, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_SPDIF_STC_UNIMPLEMENTED      (24)      //!< Bit position for SPDIF_STC_UNIMPLEMENTED.
#define BM_SPDIF_STC_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for SPDIF_STC_UNIMPLEMENTED.

//! @brief Get value of SPDIF_STC_UNIMPLEMENTED from a register value.
#define BG_SPDIF_STC_UNIMPLEMENTED(r)   (((r) & BM_SPDIF_STC_UNIMPLEMENTED) >> BP_SPDIF_STC_UNIMPLEMENTED)


/*!
 * @brief All SPDIF module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_spdif
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
#pragma pack()
#endif

//! @brief Macro to access all SPDIF registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SPDIF(0)</code>.
#define HW_SPDIF     (*(volatile hw_spdif_t *) REGS_SPDIF_BASE)


#endif // _SPDIF_H
