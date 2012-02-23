/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _MIPI_HSI_H
#define _MIPI_HSI_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_MIPI_HSI_CTRL - HSI Control Register
 * - HW_MIPI_HSI_TX_CONF - HSI Tx Config Register
 * - HW_MIPI_HSI_RX_CONF - HSI Rx Config Register
 * - HW_MIPI_HSI_CAP - HSI Capability Register
 * - HW_MIPI_HSI_TX_WML0 - HSI Tx Water Mark Level 0 Register
 * - HW_MIPI_HSI_TX_TML1 - HSI Tx Water Mark Level 1 Register
 * - HW_MIPI_HSI_TX_ARB_PRI0 - HSI Tx Arbiter Priority 0 Register
 * - HW_MIPI_HSI_TX_ARB_PRI1 - HSI Tx Arbiter Priority 1 Register
 * - HW_MIPI_HSI_LINE_ST - HSI Line Status Register
 * - HW_MIPI_HSI_ID_BIT - HSI ID Bits Register
 * - HW_MIPI_HSI_FIFO_THR_CONF - Tx and Rx Fif0 Threshold Configuration Register
 * - HW_MIPI_HSI_CH_SFTRST - Tx and Rx Channel Soft Reset Register
 * - HW_MIPI_HSI_IRQSTAT - HSI Interrupt Status Register
 * - HW_MIPI_HSI_IRQSTAT_EN - HSI Interrupt Status Enable Register
 * - HW_MIPI_HSI_IRQSIG_EN - HSI Interrupt Signal Enable Register
 * - HW_MIPI_HSI_FIFO_THR_IRQSTAT - HSI FIFO Threshold Interrupt Status Register
 * - HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN - HSI FIFO Threshold Interrupt Status Enable Register
 * - HW_MIPI_HSI_FIFO_THR_IRQSIG_EN - HSI FIFO Threshold Interrupt Signal Enable Register
 * - HW_MIPI_HSI_TX_CH_DP - Tx Channel n Data Port Register
 * - HW_MIPI_HSI_RX_CH_DP - Rx Channel n Data Port Register
 * - HW_MIPI_HSI_ERR_IRQSTAT - HSI Error Interrupt Status Register
 * - HW_MIPI_HSI_ERR_IRQSTAT_EN - HSI Error Interrupt Status Enable Register
 * - HW_MIPI_HSI_ERR_IRQSIG_EN - HSI Error Interrupt Signal Enable Register
 * - HW_MIPI_HSI_TDMA_CONF - Tx DMA Channel n Configuration Register
 * - HW_MIPI_HSI_RDMA_CONF - Rx DMA Channel n Configuration Register
 * - HW_MIPI_HSI_TDMA_STA_ADDR - Tx DMA Channel n Start Address Register
 * - HW_MIPI_HSI_RDMA_STA_ADDR - Rx DMA Channel n Start Address Register
 * - HW_MIPI_HSI_DMA_IRQSTAT - DMA Interrupt Status Register
 * - HW_MIPI_HSI_DMA_IRQSTAT_EN - DMA Interrupt Enable Register
 * - HW_MIPI_HSI_DMA_IRQSIG_EN - DMA Interrupt Status Signal Enable Register
 * - HW_MIPI_HSI_DMA_ERR_IRQSTAT - DMA Error Interrupt Status Register
 * - HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN - DMA Error Interrupt Enable Register
 * - HW_MIPI_HSI_DMA_ERR_IRQSIG_EN - DMA Error Interrupt Signal Enable Register
 * - HW_MIPI_HSI_DMA_SINGLE_REQ_EN - DMA Single Request Enable Register
 * - HW_MIPI_HSI_TX_FIFO_SIZE_CONF0 - Tx Fifo Size Configuration Register 0
 * - HW_MIPI_HSI_TX_FIFO_SIZE_CONF1 - Tx Fifo Size Configuration Register 1
 * - HW_MIPI_HSI_RX_FIFO_SIZE_CONF0 - Rx Fifo Size Configuration Register 0
 * - HW_MIPI_HSI_RX_FIFO_SIZE_CONF1 - Rx Fifo Size Configuration Register 1
 * - HW_MIPI_HSI_TX_FIFO_STAT - Tx Fifo Status Register
 * - HW_MIPI_HSI_RX_FIFO_STAT - Rx Fifo Status Register
 * - HW_MIPI_HSI_AHB_MASTER_CONF - Ahb Master Config Register
 * - HW_MIPI_HSI_TX_BREAK_LEN - TX Break Length Register
 *
 * hw_mipi_hsi_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_MIPI_HSI_BASE
#define REGS_MIPI_HSI_BASE (0x02208000) //!< Base address for MIPI_HSI.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_CTRL - HSI Control Register (RW)
 *
 * This register contains module soft reset, clock gating, clock divisor and so on.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TX_CLK_DIVISOR : 4; //!< This register holds the divisor of the base clock (tx_refclk) frequency for HSI Tx clock (internal clock used to drive Transmitter interface).
        unsigned TX_BREAK : 1; //!< Seeting this bit to one trigger a transmission break at HSI Tx. Once this bit is set to one, the HSI controller will send a serise zeros on "tx_data" port according to the tx break co unt. It will be automatically cleared, when the send is finished.
        unsigned RESERVED : 3; //!< Reserved.
        unsigned DATA_TIMEOUT_CNT : 4; //!< This value determines the interval by which DATA timeouts are detected. This data timeout counter logic is used only for Receive operations. The counter should start counting when data in any of the RX channel fifo is less than the threshold value and resets to zero when there is a threshold reached interrupt from any of the RX buffers. The counter value should be zero, when RX fifo is empty. An interrupt will be asserted to the host driver, when the counter value reaches the data timeout counter value.
        unsigned RX_TAIL_BIT_CNT : 2; //!< The value determines the length of the Tailing bit counter. The receiver shall start Receiver Tailing bit counter after the nth frame programmed in Rx Frame Burst counter is received. The receiver shall then drive ready to logic one if the receiver Tailing-bit counter has completed with no errors detected, and the receiver has enough room for at least one new frame.
        unsigned RESERVED1 : 2; //!< Reserved.
        unsigned RX_FRAME_BRST_CNT : 8; //!< This value is to limit the continous Frame transmission count in Pipelined Data flow. The Receiver Frame Burst counter shall be able to support upto 256 frames of continous transfer. 7'h00 256 frames transmission count is set. 7'h01 1 frames transmission count is set. 7'h02 2 frames transmission count is set. 7'hff 255 frames transmission count is set.
        unsigned RX_DLY_SEL : 3; //!< These values denote the tap delay values for reception of data and flag.
        unsigned DMA_DISABLE : 1; //!< This bit must be set to zero for any DMA operation. When set to one it disabel all the DMA channels.
        unsigned RESERVED2 : 2; //!< Reserved, always set to zero.
        unsigned CLKGATE : 1; //!< This bit must be set to zero for normal operation. When set to one it gates off the clocks to the block.
        unsigned SFTRST : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one (default) to disable clocking with the HSI and hold it in its reset (lowest power) state. This bit can be turned on and then off to reset the HSI block to its default state.
    } B;
} hw_mipi_hsi_ctrl_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_CTRL register
 */
#define HW_MIPI_HSI_CTRL_ADDR      (REGS_MIPI_HSI_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_CTRL           (*(volatile hw_mipi_hsi_ctrl_t *) HW_MIPI_HSI_CTRL_ADDR)
#define HW_MIPI_HSI_CTRL_RD()      (HW_MIPI_HSI_CTRL.U)
#define HW_MIPI_HSI_CTRL_WR(v)     (HW_MIPI_HSI_CTRL.U = (v))
#define HW_MIPI_HSI_CTRL_SET(v)    (HW_MIPI_HSI_CTRL_WR(HW_MIPI_HSI_CTRL_RD() |  (v)))
#define HW_MIPI_HSI_CTRL_CLR(v)    (HW_MIPI_HSI_CTRL_WR(HW_MIPI_HSI_CTRL_RD() & ~(v)))
#define HW_MIPI_HSI_CTRL_TOG(v)    (HW_MIPI_HSI_CTRL_WR(HW_MIPI_HSI_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_CTRL bitfields
 */

/* --- Register HW_MIPI_HSI_CTRL, field TX_CLK_DIVISOR (RW)
 *
 * This register holds the divisor of the base clock (tx_refclk) frequency for HSI Tx clock
 * (internal clock used to drive Transmitter interface).
 *
 * Values:
 * 1000 - tx_refclk divided by 256
 * 0111 - tx_refclk divided by 128
 * 0110 - tx_refclk divided by 64
 * 0101 - tx_refclkdivided by 32
 * 0100 - tx_refclk divided by 16
 * 0011 - tx_refclk divided by 8
 * 0010 - tx_refclk divided by 4
 * 0001 - tx_refclk divided by 2
 * 0000 - tx_refclk divided by 1
 */

#define BP_MIPI_HSI_CTRL_TX_CLK_DIVISOR      0
#define BM_MIPI_HSI_CTRL_TX_CLK_DIVISOR      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_TX_CLK_DIVISOR(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_CTRL_TX_CLK_DIVISOR)
#else
#define BF_MIPI_HSI_CTRL_TX_CLK_DIVISOR(v)   (((v) << 0) & BM_MIPI_HSI_CTRL_TX_CLK_DIVISOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CLK_DIVISOR field to a new value.
#define BW_MIPI_HSI_CTRL_TX_CLK_DIVISOR(v)   BF_CS1(MIPI_HSI_CTRL, TX_CLK_DIVISOR, v)
#endif


/* --- Register HW_MIPI_HSI_CTRL, field TX_BREAK (RW)
 *
 * Seeting this bit to one trigger a transmission break at HSI Tx. Once this bit is set to one, the
 * HSI controller will send a serise zeros on "tx_data" port according to the tx break co unt. It
 * will be automatically cleared, when the send is finished.
 */

#define BP_MIPI_HSI_CTRL_TX_BREAK      4
#define BM_MIPI_HSI_CTRL_TX_BREAK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_TX_BREAK(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_CTRL_TX_BREAK)
#else
#define BF_MIPI_HSI_CTRL_TX_BREAK(v)   (((v) << 4) & BM_MIPI_HSI_CTRL_TX_BREAK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_BREAK field to a new value.
#define BW_MIPI_HSI_CTRL_TX_BREAK(v)   BF_CS1(MIPI_HSI_CTRL, TX_BREAK, v)
#endif

/* --- Register HW_MIPI_HSI_CTRL, field RESERVED (RU)
 *
 * Reserved.
 */

#define BP_MIPI_HSI_CTRL_RESERVED      5
#define BM_MIPI_HSI_CTRL_RESERVED      0x000000e0

/* --- Register HW_MIPI_HSI_CTRL, field DATA_TIMEOUT_CNT (RW)
 *
 * This value determines the interval by which DATA timeouts are detected. This data timeout counter
 * logic is used only for Receive operations. The counter should start counting when data in any of
 * the RX channel fifo is less than the threshold value and resets to zero when there is a threshold
 * reached interrupt from any of the RX buffers. The counter value should be zero, when RX fifo is
 * empty. An interrupt will be asserted to the host driver, when the counter value reaches the data
 * timeout counter value.
 *
 * Values:
 * 1110 - HSI Tx Clock x 2 ^ 27
 * 0001 - HSI Tx Clock x 2 ^ 14
 * 0000 - HSI Tx Clock x 2 ^ 13
 */

#define BP_MIPI_HSI_CTRL_DATA_TIMEOUT_CNT      8
#define BM_MIPI_HSI_CTRL_DATA_TIMEOUT_CNT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_DATA_TIMEOUT_CNT(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_CTRL_DATA_TIMEOUT_CNT)
#else
#define BF_MIPI_HSI_CTRL_DATA_TIMEOUT_CNT(v)   (((v) << 8) & BM_MIPI_HSI_CTRL_DATA_TIMEOUT_CNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_TIMEOUT_CNT field to a new value.
#define BW_MIPI_HSI_CTRL_DATA_TIMEOUT_CNT(v)   BF_CS1(MIPI_HSI_CTRL, DATA_TIMEOUT_CNT, v)
#endif


/* --- Register HW_MIPI_HSI_CTRL, field RX_TAIL_BIT_CNT (RW)
 *
 * The value determines the length of the Tailing bit counter. The receiver shall start Receiver
 * Tailing bit counter after the nth frame programmed in Rx Frame Burst counter is received. The
 * receiver shall then drive ready to logic one if the receiver Tailing-bit counter has completed
 * with no errors detected, and the receiver has enough room for at least one new frame.
 *
 * Values:
 * 00 - 800-> tx_refclk
 * 01 - 400-> tx_refclk
 * 10 - 200-> tx_refclk
 * 11 - 100-> tx_refclk
 */

#define BP_MIPI_HSI_CTRL_RX_TAIL_BIT_CNT      12
#define BM_MIPI_HSI_CTRL_RX_TAIL_BIT_CNT      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_RX_TAIL_BIT_CNT(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_CTRL_RX_TAIL_BIT_CNT)
#else
#define BF_MIPI_HSI_CTRL_RX_TAIL_BIT_CNT(v)   (((v) << 12) & BM_MIPI_HSI_CTRL_RX_TAIL_BIT_CNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_TAIL_BIT_CNT field to a new value.
#define BW_MIPI_HSI_CTRL_RX_TAIL_BIT_CNT(v)   BF_CS1(MIPI_HSI_CTRL, RX_TAIL_BIT_CNT, v)
#endif


/* --- Register HW_MIPI_HSI_CTRL, field RESERVED (RU)
 *
 * Reserved.
 */

#define BP_MIPI_HSI_CTRL_RESERVED      14
#define BM_MIPI_HSI_CTRL_RESERVED      0x0000c000

/* --- Register HW_MIPI_HSI_CTRL, field RX_FRAME_BRST_CNT (RW)
 *
 * This value is to limit the continous Frame transmission count in Pipelined Data flow. The
 * Receiver Frame Burst counter shall be able to support upto 256 frames of continous transfer.
 * 7'h00 256 frames transmission count is set. 7'h01 1 frames transmission count is set. 7'h02 2
 * frames transmission count is set. 7'hff 255 frames transmission count is set.
 */

#define BP_MIPI_HSI_CTRL_RX_FRAME_BRST_CNT      16
#define BM_MIPI_HSI_CTRL_RX_FRAME_BRST_CNT      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_RX_FRAME_BRST_CNT(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_CTRL_RX_FRAME_BRST_CNT)
#else
#define BF_MIPI_HSI_CTRL_RX_FRAME_BRST_CNT(v)   (((v) << 16) & BM_MIPI_HSI_CTRL_RX_FRAME_BRST_CNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_FRAME_BRST_CNT field to a new value.
#define BW_MIPI_HSI_CTRL_RX_FRAME_BRST_CNT(v)   BF_CS1(MIPI_HSI_CTRL, RX_FRAME_BRST_CNT, v)
#endif

/* --- Register HW_MIPI_HSI_CTRL, field RX_DLY_SEL (RW)
 *
 * These values denote the tap delay values for reception of data and flag.
 *
 * Values:
 * 000 - 0ns ;
 * 001 - 1ns ;
 * 010 - 2ns ;
 * 011 - 3ns ;
 * 100 - 4ns ;
 * 101 - 5ns ;
 * 110 - 6ns ;
 * 111 - 7ns ;
 */

#define BP_MIPI_HSI_CTRL_RX_DLY_SEL      24
#define BM_MIPI_HSI_CTRL_RX_DLY_SEL      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_RX_DLY_SEL(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_CTRL_RX_DLY_SEL)
#else
#define BF_MIPI_HSI_CTRL_RX_DLY_SEL(v)   (((v) << 24) & BM_MIPI_HSI_CTRL_RX_DLY_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_DLY_SEL field to a new value.
#define BW_MIPI_HSI_CTRL_RX_DLY_SEL(v)   BF_CS1(MIPI_HSI_CTRL, RX_DLY_SEL, v)
#endif


/* --- Register HW_MIPI_HSI_CTRL, field DMA_DISABLE (RW)
 *
 * This bit must be set to zero for any DMA operation. When set to one it disabel all the DMA
 * channels.
 */

#define BP_MIPI_HSI_CTRL_DMA_DISABLE      27
#define BM_MIPI_HSI_CTRL_DMA_DISABLE      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_DMA_DISABLE(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_CTRL_DMA_DISABLE)
#else
#define BF_MIPI_HSI_CTRL_DMA_DISABLE(v)   (((v) << 27) & BM_MIPI_HSI_CTRL_DMA_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_DISABLE field to a new value.
#define BW_MIPI_HSI_CTRL_DMA_DISABLE(v)   BF_CS1(MIPI_HSI_CTRL, DMA_DISABLE, v)
#endif

/* --- Register HW_MIPI_HSI_CTRL, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_CTRL_RESERVED      28
#define BM_MIPI_HSI_CTRL_RESERVED      0x30000000

/* --- Register HW_MIPI_HSI_CTRL, field CLKGATE (RW)
 *
 * This bit must be set to zero for normal operation. When set to one it gates off the clocks to the
 * block.
 */

#define BP_MIPI_HSI_CTRL_CLKGATE      30
#define BM_MIPI_HSI_CTRL_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_CTRL_CLKGATE)
#else
#define BF_MIPI_HSI_CTRL_CLKGATE(v)   (((v) << 30) & BM_MIPI_HSI_CTRL_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_MIPI_HSI_CTRL_CLKGATE(v)   BF_CS1(MIPI_HSI_CTRL, CLKGATE, v)
#endif

/* --- Register HW_MIPI_HSI_CTRL, field SFTRST (RW)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one (default) to disable
 * clocking with the HSI and hold it in its reset (lowest power) state. This bit can be turned on
 * and then off to reset the HSI block to its default state.
 */

#define BP_MIPI_HSI_CTRL_SFTRST      31
#define BM_MIPI_HSI_CTRL_SFTRST      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CTRL_SFTRST(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_CTRL_SFTRST)
#else
#define BF_MIPI_HSI_CTRL_SFTRST(v)   (((v) << 31) & BM_MIPI_HSI_CTRL_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_MIPI_HSI_CTRL_SFTRST(v)   BF_CS1(MIPI_HSI_CTRL, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_CONF - HSI Tx Config Register (RW)
 *
 * This register contains the configurations of tx channel enable/disable, tx wakup and tx trans
 * mode.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TRANS_MODE : 1; //!< 
        unsigned WAKEUP : 1; //!< When this bit gets set to one, HSI transmitter sends "tx_wake" signal to Rx of other device. For a transmit operation this bit should be one.
        unsigned RESERVED : 6; //!< Reserved.
        unsigned TIMEOUT_CNT : 4; //!< 
        unsigned RESERVED1 : 4; //!< Reserved.
        unsigned CH0_EN : 1; //!< 
        unsigned CH1_EN : 1; //!< 
        unsigned CH2_EN : 1; //!< 
        unsigned CH3_EN : 1; //!< 
        unsigned CH4_EN : 1; //!< 
        unsigned CH5_EN : 1; //!< 
        unsigned CH6_EN : 1; //!< 
        unsigned CH7_EN : 1; //!< 
        unsigned CH8_EN : 1; //!< 
        unsigned CH9_EN : 1; //!< 
        unsigned CH10_EN : 1; //!< 
        unsigned CH11_EN : 1; //!< 
        unsigned CH12_EN : 1; //!< 
        unsigned CH13_EN : 1; //!< 
        unsigned CH14_EN : 1; //!< 
        unsigned CH15_EN : 1; //!< 
    } B;
} hw_mipi_hsi_tx_conf_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_CONF register
 */
#define HW_MIPI_HSI_TX_CONF_ADDR      (REGS_MIPI_HSI_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_CONF           (*(volatile hw_mipi_hsi_tx_conf_t *) HW_MIPI_HSI_TX_CONF_ADDR)
#define HW_MIPI_HSI_TX_CONF_RD()      (HW_MIPI_HSI_TX_CONF.U)
#define HW_MIPI_HSI_TX_CONF_WR(v)     (HW_MIPI_HSI_TX_CONF.U = (v))
#define HW_MIPI_HSI_TX_CONF_SET(v)    (HW_MIPI_HSI_TX_CONF_WR(HW_MIPI_HSI_TX_CONF_RD() |  (v)))
#define HW_MIPI_HSI_TX_CONF_CLR(v)    (HW_MIPI_HSI_TX_CONF_WR(HW_MIPI_HSI_TX_CONF_RD() & ~(v)))
#define HW_MIPI_HSI_TX_CONF_TOG(v)    (HW_MIPI_HSI_TX_CONF_WR(HW_MIPI_HSI_TX_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_CONF bitfields
 */

/* --- Register HW_MIPI_HSI_TX_CONF, field TRANS_MODE (RW)
 *

 *
 * Values:
 * 0 - Stream Transmission Mode
 * 1 - Frame Transmission Mode
 */

#define BP_MIPI_HSI_TX_CONF_TRANS_MODE      0
#define BM_MIPI_HSI_TX_CONF_TRANS_MODE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_TRANS_MODE(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_CONF_TRANS_MODE)
#else
#define BF_MIPI_HSI_TX_CONF_TRANS_MODE(v)   (((v) << 0) & BM_MIPI_HSI_TX_CONF_TRANS_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TRANS_MODE field to a new value.
#define BW_MIPI_HSI_TX_CONF_TRANS_MODE(v)   BF_CS1(MIPI_HSI_TX_CONF, TRANS_MODE, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field WAKEUP (RW)
 *
 * When this bit gets set to one, HSI transmitter sends "tx_wake" signal to Rx of other device. For
 * a transmit operation this bit should be one.
 *
 * Values:
 * 0 - Transmitter is in Sleep State
 * 1 - Transmitter is in Wakeup State.
 */

#define BP_MIPI_HSI_TX_CONF_WAKEUP      1
#define BM_MIPI_HSI_TX_CONF_WAKEUP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_WAKEUP(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_TX_CONF_WAKEUP)
#else
#define BF_MIPI_HSI_TX_CONF_WAKEUP(v)   (((v) << 1) & BM_MIPI_HSI_TX_CONF_WAKEUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP field to a new value.
#define BW_MIPI_HSI_TX_CONF_WAKEUP(v)   BF_CS1(MIPI_HSI_TX_CONF, WAKEUP, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field RESERVED (RU)
 *
 * Reserved.
 */

#define BP_MIPI_HSI_TX_CONF_RESERVED      2
#define BM_MIPI_HSI_TX_CONF_RESERVED      0x000000fc

/* --- Register HW_MIPI_HSI_TX_CONF, field TIMEOUT_CNT (RW)
 *

 *
 * Values:
 * 0000 - tx timeout value 2^14 tx_refclk
 * 0001 - tx timeout value 2^15 tx_refclk
 * 0010 - tx timeout value 2^16 tx_refclk
 * 0011 - tx timeout value 2^17 tx_refclk
 * 1110 - tx timeout value 2^28 tx_refclk
 * 1111 - tx timeout value 2^29 tx_refclk
 */

#define BP_MIPI_HSI_TX_CONF_TIMEOUT_CNT      8
#define BM_MIPI_HSI_TX_CONF_TIMEOUT_CNT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_TIMEOUT_CNT(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_TX_CONF_TIMEOUT_CNT)
#else
#define BF_MIPI_HSI_TX_CONF_TIMEOUT_CNT(v)   (((v) << 8) & BM_MIPI_HSI_TX_CONF_TIMEOUT_CNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIMEOUT_CNT field to a new value.
#define BW_MIPI_HSI_TX_CONF_TIMEOUT_CNT(v)   BF_CS1(MIPI_HSI_TX_CONF, TIMEOUT_CNT, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field RESERVED (RU)
 *
 * Reserved.
 */

#define BP_MIPI_HSI_TX_CONF_RESERVED      12
#define BM_MIPI_HSI_TX_CONF_RESERVED      0x0000f000

/* --- Register HW_MIPI_HSI_TX_CONF, field CH0_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch0 is Enabled.
 * 0 - Tx Ch0 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH0_EN      16
#define BM_MIPI_HSI_TX_CONF_CH0_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH0_EN(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_TX_CONF_CH0_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH0_EN(v)   (((v) << 16) & BM_MIPI_HSI_TX_CONF_CH0_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH0_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH0_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH1_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch1 is Enabled.
 * 0 - Tx Ch1 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH1_EN      17
#define BM_MIPI_HSI_TX_CONF_CH1_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH1_EN(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_TX_CONF_CH1_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH1_EN(v)   (((v) << 17) & BM_MIPI_HSI_TX_CONF_CH1_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH1_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH1_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH1_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH2_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch2 is Enabled.
 * 0 - Tx Ch2 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH2_EN      18
#define BM_MIPI_HSI_TX_CONF_CH2_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH2_EN(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_TX_CONF_CH2_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH2_EN(v)   (((v) << 18) & BM_MIPI_HSI_TX_CONF_CH2_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH2_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH2_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH2_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH3_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch3 is Enabled.
 * 0 - Tx Ch3 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH3_EN      19
#define BM_MIPI_HSI_TX_CONF_CH3_EN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH3_EN(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_TX_CONF_CH3_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH3_EN(v)   (((v) << 19) & BM_MIPI_HSI_TX_CONF_CH3_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH3_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH3_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH3_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH4_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch4 is Enabled.
 * 0 - Tx Ch4 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH4_EN      20
#define BM_MIPI_HSI_TX_CONF_CH4_EN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH4_EN(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_TX_CONF_CH4_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH4_EN(v)   (((v) << 20) & BM_MIPI_HSI_TX_CONF_CH4_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH4_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH4_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH4_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH5_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch5 is Enabled.
 * 0 - Tx Ch5 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH5_EN      21
#define BM_MIPI_HSI_TX_CONF_CH5_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH5_EN(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_TX_CONF_CH5_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH5_EN(v)   (((v) << 21) & BM_MIPI_HSI_TX_CONF_CH5_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH5_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH5_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH5_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH6_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch6 is Enabled.
 * 0 - Tx Ch6 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH6_EN      22
#define BM_MIPI_HSI_TX_CONF_CH6_EN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH6_EN(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_TX_CONF_CH6_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH6_EN(v)   (((v) << 22) & BM_MIPI_HSI_TX_CONF_CH6_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH6_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH6_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH6_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH7_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch7 is Enabled.
 * 0 - Tx Ch7 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH7_EN      23
#define BM_MIPI_HSI_TX_CONF_CH7_EN      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH7_EN(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_TX_CONF_CH7_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH7_EN(v)   (((v) << 23) & BM_MIPI_HSI_TX_CONF_CH7_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH7_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH7_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH7_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH8_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch8 is Enabled.
 * 0 - Tx Ch8 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH8_EN      24
#define BM_MIPI_HSI_TX_CONF_CH8_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH8_EN(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_TX_CONF_CH8_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH8_EN(v)   (((v) << 24) & BM_MIPI_HSI_TX_CONF_CH8_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH8_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH8_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH8_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH9_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch9 is Enabled.
 * 0 - Tx Ch9 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH9_EN      25
#define BM_MIPI_HSI_TX_CONF_CH9_EN      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH9_EN(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_TX_CONF_CH9_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH9_EN(v)   (((v) << 25) & BM_MIPI_HSI_TX_CONF_CH9_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH9_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH9_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH9_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH10_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch10 is Enabled.
 * 0 - Tx Ch10 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH10_EN      26
#define BM_MIPI_HSI_TX_CONF_CH10_EN      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH10_EN(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_TX_CONF_CH10_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH10_EN(v)   (((v) << 26) & BM_MIPI_HSI_TX_CONF_CH10_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH10_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH10_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH10_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH11_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch11 is Enabled.
 * 0 - Tx Ch11 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH11_EN      27
#define BM_MIPI_HSI_TX_CONF_CH11_EN      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH11_EN(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_TX_CONF_CH11_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH11_EN(v)   (((v) << 27) & BM_MIPI_HSI_TX_CONF_CH11_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH11_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH11_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH11_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH12_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch12 is Enabled.
 * 0 - Tx Ch12 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH12_EN      28
#define BM_MIPI_HSI_TX_CONF_CH12_EN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH12_EN(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_TX_CONF_CH12_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH12_EN(v)   (((v) << 28) & BM_MIPI_HSI_TX_CONF_CH12_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH12_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH12_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH12_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH13_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch13 is Enabled.
 * 0 - Tx Ch13 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH13_EN      29
#define BM_MIPI_HSI_TX_CONF_CH13_EN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH13_EN(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_TX_CONF_CH13_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH13_EN(v)   (((v) << 29) & BM_MIPI_HSI_TX_CONF_CH13_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH13_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH13_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH13_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH14_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch14 is Enabled.
 * 0 - Tx Ch14 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH14_EN      30
#define BM_MIPI_HSI_TX_CONF_CH14_EN      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH14_EN(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_TX_CONF_CH14_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH14_EN(v)   (((v) << 30) & BM_MIPI_HSI_TX_CONF_CH14_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH14_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH14_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH14_EN, v)
#endif


/* --- Register HW_MIPI_HSI_TX_CONF, field CH15_EN (RW)
 *

 *
 * Values:
 * 1 - Tx Ch15 is Enabled.
 * 0 - Tx Ch15 is Disabled.
 */

#define BP_MIPI_HSI_TX_CONF_CH15_EN      31
#define BM_MIPI_HSI_TX_CONF_CH15_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CONF_CH15_EN(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_TX_CONF_CH15_EN)
#else
#define BF_MIPI_HSI_TX_CONF_CH15_EN(v)   (((v) << 31) & BM_MIPI_HSI_TX_CONF_CH15_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH15_EN field to a new value.
#define BW_MIPI_HSI_TX_CONF_CH15_EN(v)   BF_CS1(MIPI_HSI_TX_CONF, CH15_EN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_RX_CONF - HSI Rx Config Register (RW)
 *
 * This register contains the configurations of rx channel enable/disable, rx wakup and rx trans
 * mode, rx data flow.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA_FLOW : 2; //!< 
        unsigned WAKE : 1; //!< 
        unsigned REC_MODE : 1; //!< 
        unsigned TAIL_BIT_CNT_EN : 1; //!< 
        unsigned RESERVED : 3; //!< Reserved.
        unsigned TIMEOUT_CNT : 7; //!< Receive Frame Timeout Counter: The counter shall be started when the first bit of the Frame has been found. The counter shall be stopped once the receiver has received the correct number of bits for a Frame. If the counter expires before Frame reception is completed, the receiver shall signal to the protocol layer that it has found an incomplete Frame and asserts Rx Error Interrupt. 7'h0 14800 ---> tx_refclk 7'h1 16400 ---> tx_refclk 7'h2 18000 ---> tx_refclk 7'h4 19600 ---> tx_refclk 7'h8 21200 ---> tx_refclk 7'h10 22800 ---> tx_refclk 7'h20 24400 ---> tx_refclk 7'h40 26000 ---> tx_refclk
        unsigned RESERVED1 : 1; //!< Reserved.
        unsigned CH0_EN : 1; //!< 
        unsigned CH1_EN : 1; //!< 
        unsigned CH2_EN : 1; //!< 
        unsigned CH3_EN : 1; //!< 
        unsigned CH4_EN : 1; //!< 
        unsigned CH5_EN : 1; //!< 
        unsigned CH6_EN : 1; //!< 
        unsigned CH7_EN : 1; //!< 
        unsigned CH8_EN : 1; //!< 
        unsigned CH9_EN : 1; //!< 
        unsigned CH10_EN : 1; //!< 
        unsigned CH11_EN : 1; //!< 
        unsigned CH12_EN : 1; //!< 
        unsigned CH13_EN : 1; //!< 
        unsigned CH14_EN : 1; //!< 
        unsigned CH15_EN : 1; //!< 
    } B;
} hw_mipi_hsi_rx_conf_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_RX_CONF register
 */
#define HW_MIPI_HSI_RX_CONF_ADDR      (REGS_MIPI_HSI_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_RX_CONF           (*(volatile hw_mipi_hsi_rx_conf_t *) HW_MIPI_HSI_RX_CONF_ADDR)
#define HW_MIPI_HSI_RX_CONF_RD()      (HW_MIPI_HSI_RX_CONF.U)
#define HW_MIPI_HSI_RX_CONF_WR(v)     (HW_MIPI_HSI_RX_CONF.U = (v))
#define HW_MIPI_HSI_RX_CONF_SET(v)    (HW_MIPI_HSI_RX_CONF_WR(HW_MIPI_HSI_RX_CONF_RD() |  (v)))
#define HW_MIPI_HSI_RX_CONF_CLR(v)    (HW_MIPI_HSI_RX_CONF_WR(HW_MIPI_HSI_RX_CONF_RD() & ~(v)))
#define HW_MIPI_HSI_RX_CONF_TOG(v)    (HW_MIPI_HSI_RX_CONF_WR(HW_MIPI_HSI_RX_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_RX_CONF bitfields
 */

/* --- Register HW_MIPI_HSI_RX_CONF, field DATA_FLOW (RW)
 *

 *
 * Values:
 * 00 - Synchronized Data Flow
 * 01 - Pipelined Data Flow
 * 10 - Receiver Real-time Data Flow
 * 11 - Reserved
 */

#define BP_MIPI_HSI_RX_CONF_DATA_FLOW      0
#define BM_MIPI_HSI_RX_CONF_DATA_FLOW      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_DATA_FLOW(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_RX_CONF_DATA_FLOW)
#else
#define BF_MIPI_HSI_RX_CONF_DATA_FLOW(v)   (((v) << 0) & BM_MIPI_HSI_RX_CONF_DATA_FLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_FLOW field to a new value.
#define BW_MIPI_HSI_RX_CONF_DATA_FLOW(v)   BF_CS1(MIPI_HSI_RX_CONF, DATA_FLOW, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field WAKE (RW)
 *

 *
 * Values:
 * 0 - Receiver is in Sleep State
 * 1 - Receiver is in Wakeup State
 */

#define BP_MIPI_HSI_RX_CONF_WAKE      2
#define BM_MIPI_HSI_RX_CONF_WAKE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_WAKE(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_RX_CONF_WAKE)
#else
#define BF_MIPI_HSI_RX_CONF_WAKE(v)   (((v) << 2) & BM_MIPI_HSI_RX_CONF_WAKE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKE field to a new value.
#define BW_MIPI_HSI_RX_CONF_WAKE(v)   BF_CS1(MIPI_HSI_RX_CONF, WAKE, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field REC_MODE (RW)
 *

 *
 * Values:
 * 0 - Stream Receive Mode
 * 1 - Frame Receive Mode
 */

#define BP_MIPI_HSI_RX_CONF_REC_MODE      3
#define BM_MIPI_HSI_RX_CONF_REC_MODE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_REC_MODE(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_RX_CONF_REC_MODE)
#else
#define BF_MIPI_HSI_RX_CONF_REC_MODE(v)   (((v) << 3) & BM_MIPI_HSI_RX_CONF_REC_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REC_MODE field to a new value.
#define BW_MIPI_HSI_RX_CONF_REC_MODE(v)   BF_CS1(MIPI_HSI_RX_CONF, REC_MODE, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field TAIL_BIT_CNT_EN (RW)
 *

 *
 * Values:
 * 0 - Tailing bit counter disable
 * 1 - Tailing bit counter Enable
 */

#define BP_MIPI_HSI_RX_CONF_TAIL_BIT_CNT_EN      4
#define BM_MIPI_HSI_RX_CONF_TAIL_BIT_CNT_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_TAIL_BIT_CNT_EN(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_RX_CONF_TAIL_BIT_CNT_EN)
#else
#define BF_MIPI_HSI_RX_CONF_TAIL_BIT_CNT_EN(v)   (((v) << 4) & BM_MIPI_HSI_RX_CONF_TAIL_BIT_CNT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TAIL_BIT_CNT_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_TAIL_BIT_CNT_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, TAIL_BIT_CNT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field RESERVED (RU)
 *
 * Reserved.
 */

#define BP_MIPI_HSI_RX_CONF_RESERVED      5
#define BM_MIPI_HSI_RX_CONF_RESERVED      0x000000e0

/* --- Register HW_MIPI_HSI_RX_CONF, field TIMEOUT_CNT (RW)
 *
 * Receive Frame Timeout Counter: The counter shall be started when the first bit of the Frame has
 * been found. The counter shall be stopped once the receiver has received the correct number of
 * bits for a Frame. If the counter expires before Frame reception is completed, the receiver shall
 * signal to the protocol layer that it has found an incomplete Frame and asserts Rx Error
 * Interrupt. 7'h0 14800 ---> tx_refclk 7'h1 16400 ---> tx_refclk 7'h2 18000 ---> tx_refclk 7'h4
 * 19600 ---> tx_refclk 7'h8 21200 ---> tx_refclk 7'h10 22800 ---> tx_refclk 7'h20 24400 --->
 * tx_refclk 7'h40 26000 ---> tx_refclk
 */

#define BP_MIPI_HSI_RX_CONF_TIMEOUT_CNT      8
#define BM_MIPI_HSI_RX_CONF_TIMEOUT_CNT      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_TIMEOUT_CNT(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_RX_CONF_TIMEOUT_CNT)
#else
#define BF_MIPI_HSI_RX_CONF_TIMEOUT_CNT(v)   (((v) << 8) & BM_MIPI_HSI_RX_CONF_TIMEOUT_CNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIMEOUT_CNT field to a new value.
#define BW_MIPI_HSI_RX_CONF_TIMEOUT_CNT(v)   BF_CS1(MIPI_HSI_RX_CONF, TIMEOUT_CNT, v)
#endif

/* --- Register HW_MIPI_HSI_RX_CONF, field RESERVED (RU)
 *
 * Reserved.
 */

#define BP_MIPI_HSI_RX_CONF_RESERVED      15
#define BM_MIPI_HSI_RX_CONF_RESERVED      0x00008000

/* --- Register HW_MIPI_HSI_RX_CONF, field CH0_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch0 is Enabled.
 * 0 - Rx Ch0 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH0_EN      16
#define BM_MIPI_HSI_RX_CONF_CH0_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH0_EN(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_RX_CONF_CH0_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH0_EN(v)   (((v) << 16) & BM_MIPI_HSI_RX_CONF_CH0_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH0_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH0_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH1_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch1 is Enabled.
 * 0 - Rx Ch1 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH1_EN      17
#define BM_MIPI_HSI_RX_CONF_CH1_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH1_EN(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_RX_CONF_CH1_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH1_EN(v)   (((v) << 17) & BM_MIPI_HSI_RX_CONF_CH1_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH1_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH1_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH1_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH2_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch2 is Enabled.
 * 0 - Rx Ch2 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH2_EN      18
#define BM_MIPI_HSI_RX_CONF_CH2_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH2_EN(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_RX_CONF_CH2_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH2_EN(v)   (((v) << 18) & BM_MIPI_HSI_RX_CONF_CH2_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH2_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH2_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH2_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH3_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch3 is Enabled.
 * 0 - Rx Ch3 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH3_EN      19
#define BM_MIPI_HSI_RX_CONF_CH3_EN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH3_EN(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_RX_CONF_CH3_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH3_EN(v)   (((v) << 19) & BM_MIPI_HSI_RX_CONF_CH3_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH3_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH3_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH3_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH4_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch4 is Enabled.
 * 0 - Rx Ch4 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH4_EN      20
#define BM_MIPI_HSI_RX_CONF_CH4_EN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH4_EN(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_RX_CONF_CH4_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH4_EN(v)   (((v) << 20) & BM_MIPI_HSI_RX_CONF_CH4_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH4_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH4_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH4_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH5_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch5 is Enabled.
 * 0 - Rx Ch5 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH5_EN      21
#define BM_MIPI_HSI_RX_CONF_CH5_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH5_EN(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_RX_CONF_CH5_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH5_EN(v)   (((v) << 21) & BM_MIPI_HSI_RX_CONF_CH5_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH5_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH5_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH5_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH6_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch6 is Enabled.
 * 0 - Rx Ch6 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH6_EN      22
#define BM_MIPI_HSI_RX_CONF_CH6_EN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH6_EN(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_RX_CONF_CH6_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH6_EN(v)   (((v) << 22) & BM_MIPI_HSI_RX_CONF_CH6_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH6_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH6_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH6_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH7_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch7 is Enabled.
 * 0 - Rx Ch7 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH7_EN      23
#define BM_MIPI_HSI_RX_CONF_CH7_EN      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH7_EN(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_RX_CONF_CH7_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH7_EN(v)   (((v) << 23) & BM_MIPI_HSI_RX_CONF_CH7_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH7_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH7_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH7_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH8_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch8 is Enabled.
 * 0 - Rx Ch8 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH8_EN      24
#define BM_MIPI_HSI_RX_CONF_CH8_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH8_EN(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_RX_CONF_CH8_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH8_EN(v)   (((v) << 24) & BM_MIPI_HSI_RX_CONF_CH8_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH8_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH8_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH8_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH9_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch9 is Enabled.
 * 0 - Rx Ch9 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH9_EN      25
#define BM_MIPI_HSI_RX_CONF_CH9_EN      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH9_EN(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_RX_CONF_CH9_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH9_EN(v)   (((v) << 25) & BM_MIPI_HSI_RX_CONF_CH9_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH9_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH9_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH9_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH10_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch10 is Enabled.
 * 0 - Rx Ch10 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH10_EN      26
#define BM_MIPI_HSI_RX_CONF_CH10_EN      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH10_EN(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_RX_CONF_CH10_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH10_EN(v)   (((v) << 26) & BM_MIPI_HSI_RX_CONF_CH10_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH10_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH10_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH10_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH11_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch11 is Enabled.
 * 0 - Rx Ch11 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH11_EN      27
#define BM_MIPI_HSI_RX_CONF_CH11_EN      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH11_EN(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_RX_CONF_CH11_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH11_EN(v)   (((v) << 27) & BM_MIPI_HSI_RX_CONF_CH11_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH11_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH11_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH11_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH12_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch12 is Enabled.
 * 0 - Rx Ch12 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH12_EN      28
#define BM_MIPI_HSI_RX_CONF_CH12_EN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH12_EN(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_RX_CONF_CH12_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH12_EN(v)   (((v) << 28) & BM_MIPI_HSI_RX_CONF_CH12_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH12_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH12_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH12_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH13_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch13 is Enabled.
 * 0 - Rx Ch13 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH13_EN      29
#define BM_MIPI_HSI_RX_CONF_CH13_EN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH13_EN(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_RX_CONF_CH13_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH13_EN(v)   (((v) << 29) & BM_MIPI_HSI_RX_CONF_CH13_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH13_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH13_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH13_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH14_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch14 is Enabled.
 * 0 - Rx Ch14 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH14_EN      30
#define BM_MIPI_HSI_RX_CONF_CH14_EN      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH14_EN(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_RX_CONF_CH14_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH14_EN(v)   (((v) << 30) & BM_MIPI_HSI_RX_CONF_CH14_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH14_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH14_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH14_EN, v)
#endif


/* --- Register HW_MIPI_HSI_RX_CONF, field CH15_EN (RW)
 *

 *
 * Values:
 * 1 - Rx Ch15 is Enabled.
 * 0 - Rx Ch15 is Disabled.
 */

#define BP_MIPI_HSI_RX_CONF_CH15_EN      31
#define BM_MIPI_HSI_RX_CONF_CH15_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CONF_CH15_EN(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_RX_CONF_CH15_EN)
#else
#define BF_MIPI_HSI_RX_CONF_CH15_EN(v)   (((v) << 31) & BM_MIPI_HSI_RX_CONF_CH15_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH15_EN field to a new value.
#define BW_MIPI_HSI_RX_CONF_CH15_EN(v)   BF_CS1(MIPI_HSI_RX_CONF, CH15_EN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_CAP - HSI Capability Register (RO)
 *
 * This register contains the HSI controller Capability information.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TX_CH_NU_SUPPORTE : 4; //!< 
        unsigned RX_CH_NU_SUPPORTE : 4; //!< 
        unsigned DMA_CH_NU_SUPPORT : 5; //!< 
        unsigned RESERVED : 3; //!< Reserved.
        unsigned TX_DMA_SUPPORT : 1; //!< 
        unsigned RX_DMA_SUPPORT : 1; //!< 
        unsigned WAKEUP_EVENT : 1; //!< 
        unsigned RESERVED1 : 13; //!< Reserved.
    } B;
} hw_mipi_hsi_cap_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_CAP register
 */
#define HW_MIPI_HSI_CAP_ADDR      (REGS_MIPI_HSI_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_CAP           (*(volatile hw_mipi_hsi_cap_t *) HW_MIPI_HSI_CAP_ADDR)
#define HW_MIPI_HSI_CAP_RD()      (HW_MIPI_HSI_CAP.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_CAP bitfields
 */

/* --- Register HW_MIPI_HSI_CAP, field TX_CH_NU_SUPPORTE (RO)
 *

 *
 * Values:
 * 0000 - 1 Tx channel supported
 * 0001 - 2 Tx channels supported
 * 1111 - 16 Tx channels supported
 */

#define BP_MIPI_HSI_CAP_TX_CH_NU_SUPPORTE      0
#define BM_MIPI_HSI_CAP_TX_CH_NU_SUPPORTE      0x0000000f


/* --- Register HW_MIPI_HSI_CAP, field RX_CH_NU_SUPPORTE (RO)
 *

 *
 * Values:
 * 0000 - 1 Rx channel supported
 * 0001 - 2 Rx channels supported
 * 1111 - 16 Rx channels supported
 */

#define BP_MIPI_HSI_CAP_RX_CH_NU_SUPPORTE      4
#define BM_MIPI_HSI_CAP_RX_CH_NU_SUPPORTE      0x000000f0


/* --- Register HW_MIPI_HSI_CAP, field DMA_CH_NU_SUPPORT (RO)
 *

 *
 * Values:
 * 00000 - 1 DMA supported
 * 00001 - 2 DMA supported
 * 00010 - 3 DMA supported
 * 00011 - 4 DMA supported
 * 00100 - 5 DMA supported
 * 00101 - 6 DMA supported
 * 11110 - 31 DMA supported
 * 11111 - 32 DMA supported
 */

#define BP_MIPI_HSI_CAP_DMA_CH_NU_SUPPORT      8
#define BM_MIPI_HSI_CAP_DMA_CH_NU_SUPPORT      0x00001f00


/* --- Register HW_MIPI_HSI_CAP, field RESERVED (RU)
 *
 * Reserved.
 */

#define BP_MIPI_HSI_CAP_RESERVED      13
#define BM_MIPI_HSI_CAP_RESERVED      0x0000e000

/* --- Register HW_MIPI_HSI_CAP, field TX_DMA_SUPPORT (RO)
 *

 *
 * Values:
 * 1 - DMA is supported.
 * 0 - Not supported
 */

#define BP_MIPI_HSI_CAP_TX_DMA_SUPPORT      16
#define BM_MIPI_HSI_CAP_TX_DMA_SUPPORT      0x00010000


/* --- Register HW_MIPI_HSI_CAP, field RX_DMA_SUPPORT (RO)
 *

 *
 * Values:
 * 1 - DMA is supported.
 * 0 - Not supported
 */

#define BP_MIPI_HSI_CAP_RX_DMA_SUPPORT      17
#define BM_MIPI_HSI_CAP_RX_DMA_SUPPORT      0x00020000


/* --- Register HW_MIPI_HSI_CAP, field WAKEUP_EVENT (RO)
 *

 *
 * Values:
 * 0 - Wakeup Event is supported
 * 1 - Wakeup Event is not supported.
 */

#define BP_MIPI_HSI_CAP_WAKEUP_EVENT      18
#define BM_MIPI_HSI_CAP_WAKEUP_EVENT      0x00040000


/* --- Register HW_MIPI_HSI_CAP, field RESERVED (RU)
 *
 * Reserved.
 */

#define BP_MIPI_HSI_CAP_RESERVED      19
#define BM_MIPI_HSI_CAP_RESERVED      0xfff80000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_WML0 - HSI Tx Water Mark Level 0 Register (RW)
 *
 * This register contains HSI controller Tx channel Water Mark Level information.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH8 : 4; //!< This value denotes the WML of Tx Channel 8. When > 1010 reserved
        unsigned CH9 : 4; //!< This value denotes the WML of Tx Channel 9. When > 1010 reserved
        unsigned CH10 : 4; //!< This value denotes the WML of Tx Channel 10. When > 1010 reserved
        unsigned CH11 : 4; //!< This value denotes the WML of Tx Channel 11. When > 1010 reserved
        unsigned CH12 : 4; //!< This value denotes the WML of Tx Channel 12. When > 1010 reserved
        unsigned CH13 : 4; //!< This value denotes the WML of Tx Channel 13. When > 1010 reserved
        unsigned CH14 : 4; //!< This value denotes the WML of Tx Channel 14. When > 1010 reserved
        unsigned CH15 : 4; //!< This value denotes the WML of Tx Channel 15. When > 1010 Reserved
    } B;
} hw_mipi_hsi_tx_wml0_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_WML0 register
 */
#define HW_MIPI_HSI_TX_WML0_ADDR      (REGS_MIPI_HSI_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_WML0           (*(volatile hw_mipi_hsi_tx_wml0_t *) HW_MIPI_HSI_TX_WML0_ADDR)
#define HW_MIPI_HSI_TX_WML0_RD()      (HW_MIPI_HSI_TX_WML0.U)
#define HW_MIPI_HSI_TX_WML0_WR(v)     (HW_MIPI_HSI_TX_WML0.U = (v))
#define HW_MIPI_HSI_TX_WML0_SET(v)    (HW_MIPI_HSI_TX_WML0_WR(HW_MIPI_HSI_TX_WML0_RD() |  (v)))
#define HW_MIPI_HSI_TX_WML0_CLR(v)    (HW_MIPI_HSI_TX_WML0_WR(HW_MIPI_HSI_TX_WML0_RD() & ~(v)))
#define HW_MIPI_HSI_TX_WML0_TOG(v)    (HW_MIPI_HSI_TX_WML0_WR(HW_MIPI_HSI_TX_WML0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_WML0 bitfields
 */

/* --- Register HW_MIPI_HSI_TX_WML0, field CH8 (RW)
 *
 * This value denotes the WML of Tx Channel 8. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_WML0_CH8      0
#define BM_MIPI_HSI_TX_WML0_CH8      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_WML0_CH8(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_WML0_CH8)
#else
#define BF_MIPI_HSI_TX_WML0_CH8(v)   (((v) << 0) & BM_MIPI_HSI_TX_WML0_CH8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH8 field to a new value.
#define BW_MIPI_HSI_TX_WML0_CH8(v)   BF_CS1(MIPI_HSI_TX_WML0, CH8, v)
#endif


/* --- Register HW_MIPI_HSI_TX_WML0, field CH9 (RW)
 *
 * This value denotes the WML of Tx Channel 9. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_WML0_CH9      4
#define BM_MIPI_HSI_TX_WML0_CH9      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_WML0_CH9(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_TX_WML0_CH9)
#else
#define BF_MIPI_HSI_TX_WML0_CH9(v)   (((v) << 4) & BM_MIPI_HSI_TX_WML0_CH9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH9 field to a new value.
#define BW_MIPI_HSI_TX_WML0_CH9(v)   BF_CS1(MIPI_HSI_TX_WML0, CH9, v)
#endif


/* --- Register HW_MIPI_HSI_TX_WML0, field CH10 (RW)
 *
 * This value denotes the WML of Tx Channel 10. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_WML0_CH10      8
#define BM_MIPI_HSI_TX_WML0_CH10      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_WML0_CH10(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_TX_WML0_CH10)
#else
#define BF_MIPI_HSI_TX_WML0_CH10(v)   (((v) << 8) & BM_MIPI_HSI_TX_WML0_CH10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH10 field to a new value.
#define BW_MIPI_HSI_TX_WML0_CH10(v)   BF_CS1(MIPI_HSI_TX_WML0, CH10, v)
#endif


/* --- Register HW_MIPI_HSI_TX_WML0, field CH11 (RW)
 *
 * This value denotes the WML of Tx Channel 11. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_WML0_CH11      12
#define BM_MIPI_HSI_TX_WML0_CH11      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_WML0_CH11(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_TX_WML0_CH11)
#else
#define BF_MIPI_HSI_TX_WML0_CH11(v)   (((v) << 12) & BM_MIPI_HSI_TX_WML0_CH11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH11 field to a new value.
#define BW_MIPI_HSI_TX_WML0_CH11(v)   BF_CS1(MIPI_HSI_TX_WML0, CH11, v)
#endif


/* --- Register HW_MIPI_HSI_TX_WML0, field CH12 (RW)
 *
 * This value denotes the WML of Tx Channel 12. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_WML0_CH12      16
#define BM_MIPI_HSI_TX_WML0_CH12      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_WML0_CH12(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_TX_WML0_CH12)
#else
#define BF_MIPI_HSI_TX_WML0_CH12(v)   (((v) << 16) & BM_MIPI_HSI_TX_WML0_CH12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH12 field to a new value.
#define BW_MIPI_HSI_TX_WML0_CH12(v)   BF_CS1(MIPI_HSI_TX_WML0, CH12, v)
#endif


/* --- Register HW_MIPI_HSI_TX_WML0, field CH13 (RW)
 *
 * This value denotes the WML of Tx Channel 13. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_WML0_CH13      20
#define BM_MIPI_HSI_TX_WML0_CH13      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_WML0_CH13(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_TX_WML0_CH13)
#else
#define BF_MIPI_HSI_TX_WML0_CH13(v)   (((v) << 20) & BM_MIPI_HSI_TX_WML0_CH13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH13 field to a new value.
#define BW_MIPI_HSI_TX_WML0_CH13(v)   BF_CS1(MIPI_HSI_TX_WML0, CH13, v)
#endif


/* --- Register HW_MIPI_HSI_TX_WML0, field CH14 (RW)
 *
 * This value denotes the WML of Tx Channel 14. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_WML0_CH14      24
#define BM_MIPI_HSI_TX_WML0_CH14      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_WML0_CH14(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_TX_WML0_CH14)
#else
#define BF_MIPI_HSI_TX_WML0_CH14(v)   (((v) << 24) & BM_MIPI_HSI_TX_WML0_CH14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH14 field to a new value.
#define BW_MIPI_HSI_TX_WML0_CH14(v)   BF_CS1(MIPI_HSI_TX_WML0, CH14, v)
#endif


/* --- Register HW_MIPI_HSI_TX_WML0, field CH15 (RW)
 *
 * This value denotes the WML of Tx Channel 15. When > 1010 Reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_WML0_CH15      28
#define BM_MIPI_HSI_TX_WML0_CH15      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_WML0_CH15(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_TX_WML0_CH15)
#else
#define BF_MIPI_HSI_TX_WML0_CH15(v)   (((v) << 28) & BM_MIPI_HSI_TX_WML0_CH15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH15 field to a new value.
#define BW_MIPI_HSI_TX_WML0_CH15(v)   BF_CS1(MIPI_HSI_TX_WML0, CH15, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_TML1 - HSI Tx Water Mark Level 1 Register (RW)
 *
 * This register contains HSI controller Tx channel Water Mark Level information.  This register
 * contains HSI controller Tx channel bandwidth information.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH0 : 4; //!< This value denotes the WML of Tx Channel 0. When > 1010 reserved
        unsigned CH1 : 4; //!< This value denotes the WML of Tx Channel 1. When > 1010 reserved
        unsigned CH2 : 4; //!< This value denotes the WML of Tx Channel 2. When > 1010 reserved
        unsigned CH3 : 4; //!< This value denotes the WML of Tx Channel 3. When > 1010 reserved
        unsigned CH4 : 4; //!< This value denotes the WML of Tx Channel 4. When > 1010 reserved
        unsigned CH5 : 4; //!< This value denotes the WML of Tx Channel 5. When > 1010 reserved
        unsigned CH6 : 4; //!< This value denotes the WML of Tx Channel 6. When > 1010 reserved
        unsigned CH7 : 4; //!< This value denotes the WML of Tx Channel 7. When > 1010 reserved
    } B;
} hw_mipi_hsi_tx_tml1_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_TML1 register
 */
#define HW_MIPI_HSI_TX_TML1_ADDR      (REGS_MIPI_HSI_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_TML1           (*(volatile hw_mipi_hsi_tx_tml1_t *) HW_MIPI_HSI_TX_TML1_ADDR)
#define HW_MIPI_HSI_TX_TML1_RD()      (HW_MIPI_HSI_TX_TML1.U)
#define HW_MIPI_HSI_TX_TML1_WR(v)     (HW_MIPI_HSI_TX_TML1.U = (v))
#define HW_MIPI_HSI_TX_TML1_SET(v)    (HW_MIPI_HSI_TX_TML1_WR(HW_MIPI_HSI_TX_TML1_RD() |  (v)))
#define HW_MIPI_HSI_TX_TML1_CLR(v)    (HW_MIPI_HSI_TX_TML1_WR(HW_MIPI_HSI_TX_TML1_RD() & ~(v)))
#define HW_MIPI_HSI_TX_TML1_TOG(v)    (HW_MIPI_HSI_TX_TML1_WR(HW_MIPI_HSI_TX_TML1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_TML1 bitfields
 */

/* --- Register HW_MIPI_HSI_TX_TML1, field CH0 (RW)
 *
 * This value denotes the WML of Tx Channel 0. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_TML1_CH0      0
#define BM_MIPI_HSI_TX_TML1_CH0      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_TML1_CH0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_TML1_CH0)
#else
#define BF_MIPI_HSI_TX_TML1_CH0(v)   (((v) << 0) & BM_MIPI_HSI_TX_TML1_CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0 field to a new value.
#define BW_MIPI_HSI_TX_TML1_CH0(v)   BF_CS1(MIPI_HSI_TX_TML1, CH0, v)
#endif


/* --- Register HW_MIPI_HSI_TX_TML1, field CH1 (RW)
 *
 * This value denotes the WML of Tx Channel 1. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_TML1_CH1      4
#define BM_MIPI_HSI_TX_TML1_CH1      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_TML1_CH1(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_TX_TML1_CH1)
#else
#define BF_MIPI_HSI_TX_TML1_CH1(v)   (((v) << 4) & BM_MIPI_HSI_TX_TML1_CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH1 field to a new value.
#define BW_MIPI_HSI_TX_TML1_CH1(v)   BF_CS1(MIPI_HSI_TX_TML1, CH1, v)
#endif


/* --- Register HW_MIPI_HSI_TX_TML1, field CH2 (RW)
 *
 * This value denotes the WML of Tx Channel 2. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_TML1_CH2      8
#define BM_MIPI_HSI_TX_TML1_CH2      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_TML1_CH2(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_TX_TML1_CH2)
#else
#define BF_MIPI_HSI_TX_TML1_CH2(v)   (((v) << 8) & BM_MIPI_HSI_TX_TML1_CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH2 field to a new value.
#define BW_MIPI_HSI_TX_TML1_CH2(v)   BF_CS1(MIPI_HSI_TX_TML1, CH2, v)
#endif


/* --- Register HW_MIPI_HSI_TX_TML1, field CH3 (RW)
 *
 * This value denotes the WML of Tx Channel 3. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_TML1_CH3      12
#define BM_MIPI_HSI_TX_TML1_CH3      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_TML1_CH3(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_TX_TML1_CH3)
#else
#define BF_MIPI_HSI_TX_TML1_CH3(v)   (((v) << 12) & BM_MIPI_HSI_TX_TML1_CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH3 field to a new value.
#define BW_MIPI_HSI_TX_TML1_CH3(v)   BF_CS1(MIPI_HSI_TX_TML1, CH3, v)
#endif


/* --- Register HW_MIPI_HSI_TX_TML1, field CH4 (RW)
 *
 * This value denotes the WML of Tx Channel 4. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_TML1_CH4      16
#define BM_MIPI_HSI_TX_TML1_CH4      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_TML1_CH4(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_TX_TML1_CH4)
#else
#define BF_MIPI_HSI_TX_TML1_CH4(v)   (((v) << 16) & BM_MIPI_HSI_TX_TML1_CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH4 field to a new value.
#define BW_MIPI_HSI_TX_TML1_CH4(v)   BF_CS1(MIPI_HSI_TX_TML1, CH4, v)
#endif


/* --- Register HW_MIPI_HSI_TX_TML1, field CH5 (RW)
 *
 * This value denotes the WML of Tx Channel 5. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_TML1_CH5      20
#define BM_MIPI_HSI_TX_TML1_CH5      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_TML1_CH5(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_TX_TML1_CH5)
#else
#define BF_MIPI_HSI_TX_TML1_CH5(v)   (((v) << 20) & BM_MIPI_HSI_TX_TML1_CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH5 field to a new value.
#define BW_MIPI_HSI_TX_TML1_CH5(v)   BF_CS1(MIPI_HSI_TX_TML1, CH5, v)
#endif


/* --- Register HW_MIPI_HSI_TX_TML1, field CH6 (RW)
 *
 * This value denotes the WML of Tx Channel 6. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_TML1_CH6      24
#define BM_MIPI_HSI_TX_TML1_CH6      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_TML1_CH6(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_TX_TML1_CH6)
#else
#define BF_MIPI_HSI_TX_TML1_CH6(v)   (((v) << 24) & BM_MIPI_HSI_TX_TML1_CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH6 field to a new value.
#define BW_MIPI_HSI_TX_TML1_CH6(v)   BF_CS1(MIPI_HSI_TX_TML1, CH6, v)
#endif


/* --- Register HW_MIPI_HSI_TX_TML1, field CH7 (RW)
 *
 * This value denotes the WML of Tx Channel 7. When > 1010 reserved
 *
 * Values:
 * 0000 - 1
 * 0001 - 2
 * 0010 - 4
 * 1000 - 256
 * 1001 - 512
 * 1010 - 1024
 */

#define BP_MIPI_HSI_TX_TML1_CH7      28
#define BM_MIPI_HSI_TX_TML1_CH7      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_TML1_CH7(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_TX_TML1_CH7)
#else
#define BF_MIPI_HSI_TX_TML1_CH7(v)   (((v) << 28) & BM_MIPI_HSI_TX_TML1_CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH7 field to a new value.
#define BW_MIPI_HSI_TX_TML1_CH7(v)   BF_CS1(MIPI_HSI_TX_TML1, CH7, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_ARB_PRI0 - HSI Tx Arbiter Priority 0 Register (RW)
 *
 * This is HSI Tx Arbiter Priority Register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH0 : 4; //!< This value denotes the priority of Tx Channel 0. When > 1010 reserved
        unsigned CH1 : 4; //!< This value denotes the priority of Tx Channel 1. When > 1010 reserved
        unsigned CH2 : 4; //!< This value denotes the priority of Tx Channel 2. When > 1010 reserved
        unsigned CH3 : 4; //!< This value denotes the priority of Tx Channel 3. When > 1010 reserved
        unsigned CH4 : 4; //!< This value denotes the priority of Tx Channel 4. When > 1010 reserved
        unsigned CH5 : 4; //!< This value denotes the priority of Tx Channel 5. When > 1010 reserved
        unsigned CH6 : 4; //!< This value denotes the priority of Tx Channel 6. When > 1010 reserved
        unsigned CH7 : 4; //!< This value denotes the priority of Tx Channel 7. When > 1010 reserved
    } B;
} hw_mipi_hsi_tx_arb_pri0_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_ARB_PRI0 register
 */
#define HW_MIPI_HSI_TX_ARB_PRI0_ADDR      (REGS_MIPI_HSI_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_ARB_PRI0           (*(volatile hw_mipi_hsi_tx_arb_pri0_t *) HW_MIPI_HSI_TX_ARB_PRI0_ADDR)
#define HW_MIPI_HSI_TX_ARB_PRI0_RD()      (HW_MIPI_HSI_TX_ARB_PRI0.U)
#define HW_MIPI_HSI_TX_ARB_PRI0_WR(v)     (HW_MIPI_HSI_TX_ARB_PRI0.U = (v))
#define HW_MIPI_HSI_TX_ARB_PRI0_SET(v)    (HW_MIPI_HSI_TX_ARB_PRI0_WR(HW_MIPI_HSI_TX_ARB_PRI0_RD() |  (v)))
#define HW_MIPI_HSI_TX_ARB_PRI0_CLR(v)    (HW_MIPI_HSI_TX_ARB_PRI0_WR(HW_MIPI_HSI_TX_ARB_PRI0_RD() & ~(v)))
#define HW_MIPI_HSI_TX_ARB_PRI0_TOG(v)    (HW_MIPI_HSI_TX_ARB_PRI0_WR(HW_MIPI_HSI_TX_ARB_PRI0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_ARB_PRI0 bitfields
 */

/* --- Register HW_MIPI_HSI_TX_ARB_PRI0, field CH0 (RW)
 *
 * This value denotes the priority of Tx Channel 0. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI0_CH0      0
#define BM_MIPI_HSI_TX_ARB_PRI0_CH0      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI0_CH0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_ARB_PRI0_CH0)
#else
#define BF_MIPI_HSI_TX_ARB_PRI0_CH0(v)   (((v) << 0) & BM_MIPI_HSI_TX_ARB_PRI0_CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI0_CH0(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI0, CH0, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI0, field CH1 (RW)
 *
 * This value denotes the priority of Tx Channel 1. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI0_CH1      4
#define BM_MIPI_HSI_TX_ARB_PRI0_CH1      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI0_CH1(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_TX_ARB_PRI0_CH1)
#else
#define BF_MIPI_HSI_TX_ARB_PRI0_CH1(v)   (((v) << 4) & BM_MIPI_HSI_TX_ARB_PRI0_CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH1 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI0_CH1(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI0, CH1, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI0, field CH2 (RW)
 *
 * This value denotes the priority of Tx Channel 2. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI0_CH2      8
#define BM_MIPI_HSI_TX_ARB_PRI0_CH2      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI0_CH2(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_TX_ARB_PRI0_CH2)
#else
#define BF_MIPI_HSI_TX_ARB_PRI0_CH2(v)   (((v) << 8) & BM_MIPI_HSI_TX_ARB_PRI0_CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH2 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI0_CH2(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI0, CH2, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI0, field CH3 (RW)
 *
 * This value denotes the priority of Tx Channel 3. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI0_CH3      12
#define BM_MIPI_HSI_TX_ARB_PRI0_CH3      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI0_CH3(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_TX_ARB_PRI0_CH3)
#else
#define BF_MIPI_HSI_TX_ARB_PRI0_CH3(v)   (((v) << 12) & BM_MIPI_HSI_TX_ARB_PRI0_CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH3 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI0_CH3(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI0, CH3, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI0, field CH4 (RW)
 *
 * This value denotes the priority of Tx Channel 4. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI0_CH4      16
#define BM_MIPI_HSI_TX_ARB_PRI0_CH4      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI0_CH4(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_TX_ARB_PRI0_CH4)
#else
#define BF_MIPI_HSI_TX_ARB_PRI0_CH4(v)   (((v) << 16) & BM_MIPI_HSI_TX_ARB_PRI0_CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH4 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI0_CH4(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI0, CH4, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI0, field CH5 (RW)
 *
 * This value denotes the priority of Tx Channel 5. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI0_CH5      20
#define BM_MIPI_HSI_TX_ARB_PRI0_CH5      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI0_CH5(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_TX_ARB_PRI0_CH5)
#else
#define BF_MIPI_HSI_TX_ARB_PRI0_CH5(v)   (((v) << 20) & BM_MIPI_HSI_TX_ARB_PRI0_CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH5 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI0_CH5(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI0, CH5, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI0, field CH6 (RW)
 *
 * This value denotes the priority of Tx Channel 6. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI0_CH6      24
#define BM_MIPI_HSI_TX_ARB_PRI0_CH6      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI0_CH6(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_TX_ARB_PRI0_CH6)
#else
#define BF_MIPI_HSI_TX_ARB_PRI0_CH6(v)   (((v) << 24) & BM_MIPI_HSI_TX_ARB_PRI0_CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH6 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI0_CH6(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI0, CH6, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI0, field CH7 (RW)
 *
 * This value denotes the priority of Tx Channel 7. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI0_CH7      28
#define BM_MIPI_HSI_TX_ARB_PRI0_CH7      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI0_CH7(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_TX_ARB_PRI0_CH7)
#else
#define BF_MIPI_HSI_TX_ARB_PRI0_CH7(v)   (((v) << 28) & BM_MIPI_HSI_TX_ARB_PRI0_CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH7 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI0_CH7(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI0, CH7, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_ARB_PRI1 - HSI Tx Arbiter Priority 1 Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH8 : 4; //!< This value denotes the priority of Tx Channel 8. When > 1010 reserved
        unsigned CH9 : 4; //!< This value denotes the priority of Tx Channel 9. When > 1010 reserved
        unsigned CH10 : 4; //!< This value denotes the priority of Tx Channel 10. When > 1010 reserved
        unsigned CH11 : 4; //!< This value denotes the priority of Tx Channel 11. When > 1010 reserved
        unsigned CH12 : 4; //!< This value denotes the priority of Tx Channel 12. When > 1010 reserved
        unsigned CH13 : 4; //!< This value denotes the priority of Tx Channel 13. When > 1010 reserved
        unsigned CH14 : 4; //!< This value denotes the priority of Tx Channel 14. When > 1010 reserved
        unsigned CH15 : 4; //!< This value denotes the priority of Tx Channel 15. When > 1010 Reserved
    } B;
} hw_mipi_hsi_tx_arb_pri1_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_ARB_PRI1 register
 */
#define HW_MIPI_HSI_TX_ARB_PRI1_ADDR      (REGS_MIPI_HSI_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_ARB_PRI1           (*(volatile hw_mipi_hsi_tx_arb_pri1_t *) HW_MIPI_HSI_TX_ARB_PRI1_ADDR)
#define HW_MIPI_HSI_TX_ARB_PRI1_RD()      (HW_MIPI_HSI_TX_ARB_PRI1.U)
#define HW_MIPI_HSI_TX_ARB_PRI1_WR(v)     (HW_MIPI_HSI_TX_ARB_PRI1.U = (v))
#define HW_MIPI_HSI_TX_ARB_PRI1_SET(v)    (HW_MIPI_HSI_TX_ARB_PRI1_WR(HW_MIPI_HSI_TX_ARB_PRI1_RD() |  (v)))
#define HW_MIPI_HSI_TX_ARB_PRI1_CLR(v)    (HW_MIPI_HSI_TX_ARB_PRI1_WR(HW_MIPI_HSI_TX_ARB_PRI1_RD() & ~(v)))
#define HW_MIPI_HSI_TX_ARB_PRI1_TOG(v)    (HW_MIPI_HSI_TX_ARB_PRI1_WR(HW_MIPI_HSI_TX_ARB_PRI1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_ARB_PRI1 bitfields
 */

/* --- Register HW_MIPI_HSI_TX_ARB_PRI1, field CH8 (RW)
 *
 * This value denotes the priority of Tx Channel 8. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI1_CH8      0
#define BM_MIPI_HSI_TX_ARB_PRI1_CH8      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI1_CH8(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_ARB_PRI1_CH8)
#else
#define BF_MIPI_HSI_TX_ARB_PRI1_CH8(v)   (((v) << 0) & BM_MIPI_HSI_TX_ARB_PRI1_CH8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH8 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI1_CH8(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI1, CH8, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI1, field CH9 (RW)
 *
 * This value denotes the priority of Tx Channel 9. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI1_CH9      4
#define BM_MIPI_HSI_TX_ARB_PRI1_CH9      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI1_CH9(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_TX_ARB_PRI1_CH9)
#else
#define BF_MIPI_HSI_TX_ARB_PRI1_CH9(v)   (((v) << 4) & BM_MIPI_HSI_TX_ARB_PRI1_CH9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH9 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI1_CH9(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI1, CH9, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI1, field CH10 (RW)
 *
 * This value denotes the priority of Tx Channel 10. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI1_CH10      8
#define BM_MIPI_HSI_TX_ARB_PRI1_CH10      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI1_CH10(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_TX_ARB_PRI1_CH10)
#else
#define BF_MIPI_HSI_TX_ARB_PRI1_CH10(v)   (((v) << 8) & BM_MIPI_HSI_TX_ARB_PRI1_CH10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH10 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI1_CH10(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI1, CH10, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI1, field CH11 (RW)
 *
 * This value denotes the priority of Tx Channel 11. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI1_CH11      12
#define BM_MIPI_HSI_TX_ARB_PRI1_CH11      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI1_CH11(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_TX_ARB_PRI1_CH11)
#else
#define BF_MIPI_HSI_TX_ARB_PRI1_CH11(v)   (((v) << 12) & BM_MIPI_HSI_TX_ARB_PRI1_CH11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH11 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI1_CH11(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI1, CH11, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI1, field CH12 (RW)
 *
 * This value denotes the priority of Tx Channel 12. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI1_CH12      16
#define BM_MIPI_HSI_TX_ARB_PRI1_CH12      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI1_CH12(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_TX_ARB_PRI1_CH12)
#else
#define BF_MIPI_HSI_TX_ARB_PRI1_CH12(v)   (((v) << 16) & BM_MIPI_HSI_TX_ARB_PRI1_CH12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH12 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI1_CH12(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI1, CH12, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI1, field CH13 (RW)
 *
 * This value denotes the priority of Tx Channel 13. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI1_CH13      20
#define BM_MIPI_HSI_TX_ARB_PRI1_CH13      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI1_CH13(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_TX_ARB_PRI1_CH13)
#else
#define BF_MIPI_HSI_TX_ARB_PRI1_CH13(v)   (((v) << 20) & BM_MIPI_HSI_TX_ARB_PRI1_CH13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH13 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI1_CH13(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI1, CH13, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI1, field CH14 (RW)
 *
 * This value denotes the priority of Tx Channel 14. When > 1010 reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI1_CH14      24
#define BM_MIPI_HSI_TX_ARB_PRI1_CH14      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI1_CH14(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_TX_ARB_PRI1_CH14)
#else
#define BF_MIPI_HSI_TX_ARB_PRI1_CH14(v)   (((v) << 24) & BM_MIPI_HSI_TX_ARB_PRI1_CH14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH14 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI1_CH14(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI1, CH14, v)
#endif


/* --- Register HW_MIPI_HSI_TX_ARB_PRI1, field CH15 (RW)
 *
 * This value denotes the priority of Tx Channel 15. When > 1010 Reserved
 *
 * Values:
 * 0000 - 1st prioirity
 * 0001 - 2nd priority
 * 0010 - 3rd priority
 * 1101 - 14th priority
 * 1110 - 15th priority
 * 1111 - 16th priority
 */

#define BP_MIPI_HSI_TX_ARB_PRI1_CH15      28
#define BM_MIPI_HSI_TX_ARB_PRI1_CH15      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_ARB_PRI1_CH15(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_TX_ARB_PRI1_CH15)
#else
#define BF_MIPI_HSI_TX_ARB_PRI1_CH15(v)   (((v) << 28) & BM_MIPI_HSI_TX_ARB_PRI1_CH15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH15 field to a new value.
#define BW_MIPI_HSI_TX_ARB_PRI1_CH15(v)   BF_CS1(MIPI_HSI_TX_ARB_PRI1, CH15, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_LINE_ST - HSI Line Status Register (RO)
 *
 * This register contains the HSI controller line status for debug.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TX_DATA_STATUS : 1; //!< This field reflects the tx_data pin(only for debug).
        unsigned TX_FLAG_STATUS : 1; //!< This field reflects the tx_flag pin(only for debug).
        unsigned TX_READY_STATUS : 1; //!< This field reflects the tx_ready pin(only for debug).
        unsigned TX_WAKEUP_STATUS : 1; //!< This field reflects the tx_wake pin(only for debug).
        unsigned RX_DATA_STATUS : 1; //!< This field reflects the rx_data pin(only for debug).
        unsigned RX_FLAG_STATUS : 1; //!< This field reflects the rx_flag pin(only for debug).
        unsigned RX_READY_STATUS : 1; //!< This field reflects the rx_rdy pin(only for debug).
        unsigned RX_WAKEUP_STATUS : 1; //!< This field reflects the rx_wake pin(only for debug).
        unsigned RESERVED : 24; //!< Reserved, always set to zero.
    } B;
} hw_mipi_hsi_line_st_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_LINE_ST register
 */
#define HW_MIPI_HSI_LINE_ST_ADDR      (REGS_MIPI_HSI_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_LINE_ST           (*(volatile hw_mipi_hsi_line_st_t *) HW_MIPI_HSI_LINE_ST_ADDR)
#define HW_MIPI_HSI_LINE_ST_RD()      (HW_MIPI_HSI_LINE_ST.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_LINE_ST bitfields
 */

/* --- Register HW_MIPI_HSI_LINE_ST, field TX_DATA_STATUS (RO)
 *
 * This field reflects the tx_data pin(only for debug).
 */

#define BP_MIPI_HSI_LINE_ST_TX_DATA_STATUS      0
#define BM_MIPI_HSI_LINE_ST_TX_DATA_STATUS      0x00000001

/* --- Register HW_MIPI_HSI_LINE_ST, field TX_FLAG_STATUS (RO)
 *
 * This field reflects the tx_flag pin(only for debug).
 */

#define BP_MIPI_HSI_LINE_ST_TX_FLAG_STATUS      1
#define BM_MIPI_HSI_LINE_ST_TX_FLAG_STATUS      0x00000002

/* --- Register HW_MIPI_HSI_LINE_ST, field TX_READY_STATUS (RO)
 *
 * This field reflects the tx_ready pin(only for debug).
 */

#define BP_MIPI_HSI_LINE_ST_TX_READY_STATUS      2
#define BM_MIPI_HSI_LINE_ST_TX_READY_STATUS      0x00000004

/* --- Register HW_MIPI_HSI_LINE_ST, field TX_WAKEUP_STATUS (RO)
 *
 * This field reflects the tx_wake pin(only for debug).
 */

#define BP_MIPI_HSI_LINE_ST_TX_WAKEUP_STATUS      3
#define BM_MIPI_HSI_LINE_ST_TX_WAKEUP_STATUS      0x00000008

/* --- Register HW_MIPI_HSI_LINE_ST, field RX_DATA_STATUS (RO)
 *
 * This field reflects the rx_data pin(only for debug).
 */

#define BP_MIPI_HSI_LINE_ST_RX_DATA_STATUS      4
#define BM_MIPI_HSI_LINE_ST_RX_DATA_STATUS      0x00000010

/* --- Register HW_MIPI_HSI_LINE_ST, field RX_FLAG_STATUS (RO)
 *
 * This field reflects the rx_flag pin(only for debug).
 */

#define BP_MIPI_HSI_LINE_ST_RX_FLAG_STATUS      5
#define BM_MIPI_HSI_LINE_ST_RX_FLAG_STATUS      0x00000020

/* --- Register HW_MIPI_HSI_LINE_ST, field RX_READY_STATUS (RO)
 *
 * This field reflects the rx_rdy pin(only for debug).
 */

#define BP_MIPI_HSI_LINE_ST_RX_READY_STATUS      6
#define BM_MIPI_HSI_LINE_ST_RX_READY_STATUS      0x00000040

/* --- Register HW_MIPI_HSI_LINE_ST, field RX_WAKEUP_STATUS (RO)
 *
 * This field reflects the rx_wake pin(only for debug).
 */

#define BP_MIPI_HSI_LINE_ST_RX_WAKEUP_STATUS      7
#define BM_MIPI_HSI_LINE_ST_RX_WAKEUP_STATUS      0x00000080

/* --- Register HW_MIPI_HSI_LINE_ST, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_LINE_ST_RESERVED      8
#define BM_MIPI_HSI_LINE_ST_RESERVED      0xffffff00

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_ID_BIT - HSI ID Bits Register (RW)
 *
 * This register contains the configurations of tx channel enable/disable, , tx wakup and tx trans
 * mode.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TX_CH : 3; //!< This bit sets the number of channel ID bits per frame or stream for a transmit operation.
        unsigned RESERVED : 1; //!< Reserved, always set to zero.
        unsigned RX_CH : 3; //!< This bit sets the number of channel ID bits per frame or stream for a Receive operation.
        unsigned RESERVED1 : 25; //!< Reserved, always set to zero.
    } B;
} hw_mipi_hsi_id_bit_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_ID_BIT register
 */
#define HW_MIPI_HSI_ID_BIT_ADDR      (REGS_MIPI_HSI_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_ID_BIT           (*(volatile hw_mipi_hsi_id_bit_t *) HW_MIPI_HSI_ID_BIT_ADDR)
#define HW_MIPI_HSI_ID_BIT_RD()      (HW_MIPI_HSI_ID_BIT.U)
#define HW_MIPI_HSI_ID_BIT_WR(v)     (HW_MIPI_HSI_ID_BIT.U = (v))
#define HW_MIPI_HSI_ID_BIT_SET(v)    (HW_MIPI_HSI_ID_BIT_WR(HW_MIPI_HSI_ID_BIT_RD() |  (v)))
#define HW_MIPI_HSI_ID_BIT_CLR(v)    (HW_MIPI_HSI_ID_BIT_WR(HW_MIPI_HSI_ID_BIT_RD() & ~(v)))
#define HW_MIPI_HSI_ID_BIT_TOG(v)    (HW_MIPI_HSI_ID_BIT_WR(HW_MIPI_HSI_ID_BIT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_ID_BIT bitfields
 */

/* --- Register HW_MIPI_HSI_ID_BIT, field TX_CH (RW)
 *
 * This bit sets the number of channel ID bits per frame or stream for a transmit operation.
 *
 * Values:
 * 0 - 0 bit
 * 1 - 1 bit
 * 2 - 2 bits
 * 3 - 3 bits
 * 4 - 4 bits
 */

#define BP_MIPI_HSI_ID_BIT_TX_CH      0
#define BM_MIPI_HSI_ID_BIT_TX_CH      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ID_BIT_TX_CH(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_ID_BIT_TX_CH)
#else
#define BF_MIPI_HSI_ID_BIT_TX_CH(v)   (((v) << 0) & BM_MIPI_HSI_ID_BIT_TX_CH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH field to a new value.
#define BW_MIPI_HSI_ID_BIT_TX_CH(v)   BF_CS1(MIPI_HSI_ID_BIT, TX_CH, v)
#endif


/* --- Register HW_MIPI_HSI_ID_BIT, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_ID_BIT_RESERVED      3
#define BM_MIPI_HSI_ID_BIT_RESERVED      0x00000008

/* --- Register HW_MIPI_HSI_ID_BIT, field RX_CH (RW)
 *
 * This bit sets the number of channel ID bits per frame or stream for a Receive operation.
 *
 * Values:
 * 0 - 0 bit
 * 1 - 1 bit
 * 2 - 2 bits
 * 3 - 3 bits
 * 4 - 4 bits
 */

#define BP_MIPI_HSI_ID_BIT_RX_CH      4
#define BM_MIPI_HSI_ID_BIT_RX_CH      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ID_BIT_RX_CH(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_ID_BIT_RX_CH)
#else
#define BF_MIPI_HSI_ID_BIT_RX_CH(v)   (((v) << 4) & BM_MIPI_HSI_ID_BIT_RX_CH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH field to a new value.
#define BW_MIPI_HSI_ID_BIT_RX_CH(v)   BF_CS1(MIPI_HSI_ID_BIT, RX_CH, v)
#endif


/* --- Register HW_MIPI_HSI_ID_BIT, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_ID_BIT_RESERVED      7
#define BM_MIPI_HSI_ID_BIT_RESERVED      0xffffff80

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_FIFO_THR_CONF - Tx and Rx Fif0 Threshold Configuration Register (RW)
 *
 * This register sets the threshold level for each Tx and Rx channel fifo
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RX_CH0 : 1; //!< 
        unsigned RX_CH1 : 1; //!< 
        unsigned RX_CH2 : 1; //!< 
        unsigned RX_CH3 : 1; //!< 
        unsigned RX_CH4 : 1; //!< 
        unsigned RX_CH5 : 1; //!< 
        unsigned RX_CH6 : 1; //!< 
        unsigned RX_CH7 : 1; //!< 
        unsigned RX_CH8 : 1; //!< 
        unsigned RX_CH9 : 1; //!< 
        unsigned RX_CH10 : 1; //!< 
        unsigned RX_CH11 : 1; //!< 
        unsigned RX_CH12 : 1; //!< 
        unsigned RX_CH13 : 1; //!< 
        unsigned RX_CH14 : 1; //!< 
        unsigned RX_CH15 : 1; //!< 
        unsigned TX_CH0 : 1; //!< 
        unsigned TX_CH1 : 1; //!< 
        unsigned TX_CH2 : 1; //!< 
        unsigned TX_CH3 : 1; //!< 
        unsigned TX_CH4 : 1; //!< 
        unsigned TX_CH5 : 1; //!< 
        unsigned TX_CH6 : 1; //!< 
        unsigned TX_CH7 : 1; //!< 
        unsigned TX_CH8 : 1; //!< 
        unsigned TX_CH9 : 1; //!< 
        unsigned TX_CH10 : 1; //!< 
        unsigned TX_CH11 : 1; //!< 
        unsigned TX_CH12 : 1; //!< 
        unsigned TX_CH13 : 1; //!< 
        unsigned TX_CH14 : 1; //!< 
        unsigned TX_CH15 : 1; //!< 
    } B;
} hw_mipi_hsi_fifo_thr_conf_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_FIFO_THR_CONF register
 */
#define HW_MIPI_HSI_FIFO_THR_CONF_ADDR      (REGS_MIPI_HSI_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_FIFO_THR_CONF           (*(volatile hw_mipi_hsi_fifo_thr_conf_t *) HW_MIPI_HSI_FIFO_THR_CONF_ADDR)
#define HW_MIPI_HSI_FIFO_THR_CONF_RD()      (HW_MIPI_HSI_FIFO_THR_CONF.U)
#define HW_MIPI_HSI_FIFO_THR_CONF_WR(v)     (HW_MIPI_HSI_FIFO_THR_CONF.U = (v))
#define HW_MIPI_HSI_FIFO_THR_CONF_SET(v)    (HW_MIPI_HSI_FIFO_THR_CONF_WR(HW_MIPI_HSI_FIFO_THR_CONF_RD() |  (v)))
#define HW_MIPI_HSI_FIFO_THR_CONF_CLR(v)    (HW_MIPI_HSI_FIFO_THR_CONF_WR(HW_MIPI_HSI_FIFO_THR_CONF_RD() & ~(v)))
#define HW_MIPI_HSI_FIFO_THR_CONF_TOG(v)    (HW_MIPI_HSI_FIFO_THR_CONF_WR(HW_MIPI_HSI_FIFO_THR_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_FIFO_THR_CONF bitfields
 */

/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH0 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH0      0
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH0)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH0(v)   (((v) << 0) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH0 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH0(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH0, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH1 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH1      1
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH1(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH1)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH1(v)   (((v) << 1) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH1 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH1(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH1, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH2 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH2      2
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH2(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH2)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH2(v)   (((v) << 2) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH2 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH2(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH2, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH3 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH3      3
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH3(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH3)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH3(v)   (((v) << 3) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH3 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH3(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH3, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH4 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH4      4
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH4(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH4)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH4(v)   (((v) << 4) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH4 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH4(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH4, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH5 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH5      5
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH5(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH5)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH5(v)   (((v) << 5) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH5 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH5(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH5, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH6 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH6      6
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH6(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH6)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH6(v)   (((v) << 6) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH6 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH6(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH6, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH7 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH7      7
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH7(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH7)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH7(v)   (((v) << 7) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH7 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH7(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH7, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH8 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH8      8
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH8(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH8)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH8(v)   (((v) << 8) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH8 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH8(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH8, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH9 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH9      9
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH9(v)   ((((reg32_t) v) << 9) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH9)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH9(v)   (((v) << 9) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH9 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH9(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH9, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH10 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH10      10
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH10(v)   ((((reg32_t) v) << 10) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH10)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH10(v)   (((v) << 10) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH10 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH10(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH10, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH11 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH11      11
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH11(v)   ((((reg32_t) v) << 11) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH11)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH11(v)   (((v) << 11) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH11 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH11(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH11, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH12 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH12      12
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH12(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH12)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH12(v)   (((v) << 12) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH12 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH12(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH12, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH13 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH13      13
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH13(v)   ((((reg32_t) v) << 13) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH13)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH13(v)   (((v) << 13) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH13 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH13(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH13, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH14 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH14      14
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH14(v)   ((((reg32_t) v) << 14) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH14)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH14(v)   (((v) << 14) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH14 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH14(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH14, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field RX_CH15 (RW)
 *

 *
 * Values:
 * 0 - Half Full (fifo size / 2)
 * 1 - Almost Full (3/4th of fifo size)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_RX_CH15      15
#define BM_MIPI_HSI_FIFO_THR_CONF_RX_CH15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH15(v)   ((((reg32_t) v) << 15) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH15)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_RX_CH15(v)   (((v) << 15) & BM_MIPI_HSI_FIFO_THR_CONF_RX_CH15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH15 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_RX_CH15(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, RX_CH15, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH0 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH0      16
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH0(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH0)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH0(v)   (((v) << 16) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH0 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH0(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH0, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH1 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH1      17
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH1(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH1)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH1(v)   (((v) << 17) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH1 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH1(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH1, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH2 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH2      18
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH2(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH2)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH2(v)   (((v) << 18) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH2 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH2(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH2, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH3 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH3      19
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH3      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH3(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH3)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH3(v)   (((v) << 19) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH3 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH3(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH3, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH4 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH4      20
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH4      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH4(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH4)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH4(v)   (((v) << 20) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH4 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH4(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH4, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH5 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH5      21
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH5      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH5(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH5)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH5(v)   (((v) << 21) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH5 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH5(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH5, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH6 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH6      22
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH6      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH6(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH6)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH6(v)   (((v) << 22) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH6 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH6(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH6, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH7 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH7      23
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH7      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH7(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH7)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH7(v)   (((v) << 23) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH7 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH7(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH7, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH8 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH8      24
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH8      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH8(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH8)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH8(v)   (((v) << 24) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH8 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH8(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH8, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH9 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH9      25
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH9      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH9(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH9)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH9(v)   (((v) << 25) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH9 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH9(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH9, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH10 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH10      26
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH10      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH10(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH10)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH10(v)   (((v) << 26) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH10 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH10(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH10, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH11 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH11      27
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH11      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH11(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH11)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH11(v)   (((v) << 27) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH11 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH11(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH11, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH12 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH12      28
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH12      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH12(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH12)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH12(v)   (((v) << 28) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH12 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH12(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH12, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH13 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH13      29
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH13      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH13(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH13)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH13(v)   (((v) << 29) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH13 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH13(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH13, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH14 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH14      30
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH14      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH14(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH14)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH14(v)   (((v) << 30) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH14 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH14(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH14, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_CONF, field TX_CH15 (RW)
 *

 *
 * Values:
 * 0 - Half Empty (fifo size / 2)
 * 1 - Almost Empty (fifo size / 4)
 */

#define BP_MIPI_HSI_FIFO_THR_CONF_TX_CH15      31
#define BM_MIPI_HSI_FIFO_THR_CONF_TX_CH15      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH15(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH15)
#else
#define BF_MIPI_HSI_FIFO_THR_CONF_TX_CH15(v)   (((v) << 31) & BM_MIPI_HSI_FIFO_THR_CONF_TX_CH15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH15 field to a new value.
#define BW_MIPI_HSI_FIFO_THR_CONF_TX_CH15(v)   BF_CS1(MIPI_HSI_FIFO_THR_CONF, TX_CH15, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_CH_SFTRST - Tx and Rx Channel Soft Reset Register (WO)
 *
 * This register is used to reset each Tx and Rx Channel
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RX_CH0 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 0 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH1 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 1 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH2 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 2 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH3 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 3 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH4 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 4 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH5 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 5 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH6 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 6 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH7 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 7 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH8 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 8 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH9 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 9 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH10 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 10 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH11 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 11 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH12 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 12 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH13 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 13 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH14 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 14 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned RX_CH15 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 15 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH0 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 0 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH1 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 1 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH2 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 2 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH3 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 3 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH4 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 4 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH5 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 5 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH6 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 6 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH7 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 7 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH8 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 8 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH9 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 9 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH10 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 10 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH11 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 11 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH12 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 12 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH13 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 13 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH14 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 14 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
        unsigned TX_CH15 : 1; //!< Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 15 (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
    } B;
} hw_mipi_hsi_ch_sftrst_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_CH_SFTRST register
 */
#define HW_MIPI_HSI_CH_SFTRST_ADDR      (REGS_MIPI_HSI_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_CH_SFTRST           (*(volatile hw_mipi_hsi_ch_sftrst_t *) HW_MIPI_HSI_CH_SFTRST_ADDR)
#define HW_MIPI_HSI_CH_SFTRST_WR(v)     (HW_MIPI_HSI_CH_SFTRST.U = (v))
#endif

/*
 * constants & macros for individual MIPI_HSI_CH_SFTRST bitfields
 */

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH0 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 0
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH0      0
#define BM_MIPI_HSI_CH_SFTRST_RX_CH0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_CH_SFTRST_RX_CH0)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH0(v)   (((v) << 0) & BM_MIPI_HSI_CH_SFTRST_RX_CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH0 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH0(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH0, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH1 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 1
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH1      1
#define BM_MIPI_HSI_CH_SFTRST_RX_CH1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH1(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_CH_SFTRST_RX_CH1)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH1(v)   (((v) << 1) & BM_MIPI_HSI_CH_SFTRST_RX_CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH1 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH1(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH1, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH2 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 2
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH2      2
#define BM_MIPI_HSI_CH_SFTRST_RX_CH2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH2(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_CH_SFTRST_RX_CH2)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH2(v)   (((v) << 2) & BM_MIPI_HSI_CH_SFTRST_RX_CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH2 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH2(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH2, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH3 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 3
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH3      3
#define BM_MIPI_HSI_CH_SFTRST_RX_CH3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH3(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_CH_SFTRST_RX_CH3)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH3(v)   (((v) << 3) & BM_MIPI_HSI_CH_SFTRST_RX_CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH3 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH3(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH3, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH4 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 4
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH4      4
#define BM_MIPI_HSI_CH_SFTRST_RX_CH4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH4(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_CH_SFTRST_RX_CH4)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH4(v)   (((v) << 4) & BM_MIPI_HSI_CH_SFTRST_RX_CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH4 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH4(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH4, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH5 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 5
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH5      5
#define BM_MIPI_HSI_CH_SFTRST_RX_CH5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH5(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_CH_SFTRST_RX_CH5)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH5(v)   (((v) << 5) & BM_MIPI_HSI_CH_SFTRST_RX_CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH5 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH5(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH5, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH6 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 6
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH6      6
#define BM_MIPI_HSI_CH_SFTRST_RX_CH6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH6(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_CH_SFTRST_RX_CH6)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH6(v)   (((v) << 6) & BM_MIPI_HSI_CH_SFTRST_RX_CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH6 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH6(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH6, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH7 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 7
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH7      7
#define BM_MIPI_HSI_CH_SFTRST_RX_CH7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH7(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_CH_SFTRST_RX_CH7)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH7(v)   (((v) << 7) & BM_MIPI_HSI_CH_SFTRST_RX_CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH7 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH7(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH7, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH8 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 8
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH8      8
#define BM_MIPI_HSI_CH_SFTRST_RX_CH8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH8(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_CH_SFTRST_RX_CH8)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH8(v)   (((v) << 8) & BM_MIPI_HSI_CH_SFTRST_RX_CH8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH8 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH8(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH8, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH9 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 9
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH9      9
#define BM_MIPI_HSI_CH_SFTRST_RX_CH9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH9(v)   ((((reg32_t) v) << 9) & BM_MIPI_HSI_CH_SFTRST_RX_CH9)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH9(v)   (((v) << 9) & BM_MIPI_HSI_CH_SFTRST_RX_CH9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH9 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH9(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH9, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH10 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 10
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH10      10
#define BM_MIPI_HSI_CH_SFTRST_RX_CH10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH10(v)   ((((reg32_t) v) << 10) & BM_MIPI_HSI_CH_SFTRST_RX_CH10)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH10(v)   (((v) << 10) & BM_MIPI_HSI_CH_SFTRST_RX_CH10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH10 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH10(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH10, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH11 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 11
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH11      11
#define BM_MIPI_HSI_CH_SFTRST_RX_CH11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH11(v)   ((((reg32_t) v) << 11) & BM_MIPI_HSI_CH_SFTRST_RX_CH11)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH11(v)   (((v) << 11) & BM_MIPI_HSI_CH_SFTRST_RX_CH11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH11 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH11(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH11, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH12 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 12
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH12      12
#define BM_MIPI_HSI_CH_SFTRST_RX_CH12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH12(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_CH_SFTRST_RX_CH12)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH12(v)   (((v) << 12) & BM_MIPI_HSI_CH_SFTRST_RX_CH12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH12 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH12(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH12, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH13 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 13
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH13      13
#define BM_MIPI_HSI_CH_SFTRST_RX_CH13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH13(v)   ((((reg32_t) v) << 13) & BM_MIPI_HSI_CH_SFTRST_RX_CH13)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH13(v)   (((v) << 13) & BM_MIPI_HSI_CH_SFTRST_RX_CH13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH13 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH13(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH13, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH14 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 14
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH14      14
#define BM_MIPI_HSI_CH_SFTRST_RX_CH14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH14(v)   ((((reg32_t) v) << 14) & BM_MIPI_HSI_CH_SFTRST_RX_CH14)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH14(v)   (((v) << 14) & BM_MIPI_HSI_CH_SFTRST_RX_CH14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH14 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH14(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH14, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field RX_CH15 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Rx Channel 15
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_RX_CH15      15
#define BM_MIPI_HSI_CH_SFTRST_RX_CH15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_RX_CH15(v)   ((((reg32_t) v) << 15) & BM_MIPI_HSI_CH_SFTRST_RX_CH15)
#else
#define BF_MIPI_HSI_CH_SFTRST_RX_CH15(v)   (((v) << 15) & BM_MIPI_HSI_CH_SFTRST_RX_CH15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH15 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_RX_CH15(v)   BF_CS1(MIPI_HSI_CH_SFTRST, RX_CH15, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH0 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 0
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH0      16
#define BM_MIPI_HSI_CH_SFTRST_TX_CH0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH0(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_CH_SFTRST_TX_CH0)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH0(v)   (((v) << 16) & BM_MIPI_HSI_CH_SFTRST_TX_CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH0 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH0(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH0, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH1 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 1
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH1      17
#define BM_MIPI_HSI_CH_SFTRST_TX_CH1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH1(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_CH_SFTRST_TX_CH1)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH1(v)   (((v) << 17) & BM_MIPI_HSI_CH_SFTRST_TX_CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH1 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH1(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH1, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH2 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 2
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH2      18
#define BM_MIPI_HSI_CH_SFTRST_TX_CH2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH2(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_CH_SFTRST_TX_CH2)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH2(v)   (((v) << 18) & BM_MIPI_HSI_CH_SFTRST_TX_CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH2 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH2(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH2, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH3 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 3
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH3      19
#define BM_MIPI_HSI_CH_SFTRST_TX_CH3      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH3(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_CH_SFTRST_TX_CH3)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH3(v)   (((v) << 19) & BM_MIPI_HSI_CH_SFTRST_TX_CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH3 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH3(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH3, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH4 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 4
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH4      20
#define BM_MIPI_HSI_CH_SFTRST_TX_CH4      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH4(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_CH_SFTRST_TX_CH4)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH4(v)   (((v) << 20) & BM_MIPI_HSI_CH_SFTRST_TX_CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH4 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH4(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH4, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH5 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 5
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH5      21
#define BM_MIPI_HSI_CH_SFTRST_TX_CH5      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH5(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_CH_SFTRST_TX_CH5)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH5(v)   (((v) << 21) & BM_MIPI_HSI_CH_SFTRST_TX_CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH5 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH5(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH5, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH6 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 6
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH6      22
#define BM_MIPI_HSI_CH_SFTRST_TX_CH6      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH6(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_CH_SFTRST_TX_CH6)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH6(v)   (((v) << 22) & BM_MIPI_HSI_CH_SFTRST_TX_CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH6 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH6(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH6, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH7 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 7
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH7      23
#define BM_MIPI_HSI_CH_SFTRST_TX_CH7      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH7(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_CH_SFTRST_TX_CH7)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH7(v)   (((v) << 23) & BM_MIPI_HSI_CH_SFTRST_TX_CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH7 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH7(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH7, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH8 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 8
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH8      24
#define BM_MIPI_HSI_CH_SFTRST_TX_CH8      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH8(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_CH_SFTRST_TX_CH8)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH8(v)   (((v) << 24) & BM_MIPI_HSI_CH_SFTRST_TX_CH8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH8 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH8(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH8, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH9 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 9
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH9      25
#define BM_MIPI_HSI_CH_SFTRST_TX_CH9      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH9(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_CH_SFTRST_TX_CH9)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH9(v)   (((v) << 25) & BM_MIPI_HSI_CH_SFTRST_TX_CH9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH9 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH9(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH9, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH10 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 10
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH10      26
#define BM_MIPI_HSI_CH_SFTRST_TX_CH10      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH10(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_CH_SFTRST_TX_CH10)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH10(v)   (((v) << 26) & BM_MIPI_HSI_CH_SFTRST_TX_CH10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH10 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH10(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH10, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH11 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 11
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH11      27
#define BM_MIPI_HSI_CH_SFTRST_TX_CH11      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH11(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_CH_SFTRST_TX_CH11)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH11(v)   (((v) << 27) & BM_MIPI_HSI_CH_SFTRST_TX_CH11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH11 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH11(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH11, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH12 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 12
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH12      28
#define BM_MIPI_HSI_CH_SFTRST_TX_CH12      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH12(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_CH_SFTRST_TX_CH12)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH12(v)   (((v) << 28) & BM_MIPI_HSI_CH_SFTRST_TX_CH12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH12 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH12(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH12, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH13 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 13
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH13      29
#define BM_MIPI_HSI_CH_SFTRST_TX_CH13      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH13(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_CH_SFTRST_TX_CH13)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH13(v)   (((v) << 29) & BM_MIPI_HSI_CH_SFTRST_TX_CH13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH13 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH13(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH13, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH14 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 14
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH14      30
#define BM_MIPI_HSI_CH_SFTRST_TX_CH14      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH14(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_CH_SFTRST_TX_CH14)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH14(v)   (((v) << 30) & BM_MIPI_HSI_CH_SFTRST_TX_CH14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH14 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH14(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH14, v)
#endif

/* --- Register HW_MIPI_HSI_CH_SFTRST, field TX_CH15 (WO)
 *
 * Set this bit to zero to enable normal HSI operation. Set this bit to one to reset Tx Channel 15
 * (DMA and Fifo). When the reset operation complete, this bit will turn to zero automatically.
 */

#define BP_MIPI_HSI_CH_SFTRST_TX_CH15      31
#define BM_MIPI_HSI_CH_SFTRST_TX_CH15      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_CH_SFTRST_TX_CH15(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_CH_SFTRST_TX_CH15)
#else
#define BF_MIPI_HSI_CH_SFTRST_TX_CH15(v)   (((v) << 31) & BM_MIPI_HSI_CH_SFTRST_TX_CH15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH15 field to a new value.
#define BW_MIPI_HSI_CH_SFTRST_TX_CH15(v)   BF_CS1(MIPI_HSI_CH_SFTRST, TX_CH15, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_IRQSTAT - HSI Interrupt Status Register (RW)
 *
 * This is HSI controller Interrupt Status Register.  This register contains the HSI controller
 * Interrupt Status.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FIFO_THRESHOLD_INT : 1; //!< 
        unsigned RX_WAKEUP_INT : 1; //!< 
        unsigned RX_TIMEOUT_INT : 1; //!< If any bit in the HSI Error Interrupt Status Register is set, then this bit is set. on seeing this bit set, the ocp driver will read the Error Interrupt Staus Register.
        unsigned DMA_INT : 1; //!< This bit is set when a Transmit or Receive Operation is completed for DMA.
        unsigned DMA_ERR_INT : 1; //!< If any bit in the DMA Error Interrupt Status Register is set, then this bit is set. on seeing this bit set, the ocp driver will read the Error Interrupt Staus Register.
        unsigned TX_TIMEOUT_ERR_INT : 1; //!< 
        unsigned RX_ERROR_INT : 1; //!< 
        unsigned RX_BREAK_INT : 1; //!< 
        unsigned TX_EMPTY_INT : 1; //!< 
        unsigned RESERVED : 23; //!< Reserved, always set to zero.
    } B;
} hw_mipi_hsi_irqstat_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_IRQSTAT register
 */
#define HW_MIPI_HSI_IRQSTAT_ADDR      (REGS_MIPI_HSI_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_IRQSTAT           (*(volatile hw_mipi_hsi_irqstat_t *) HW_MIPI_HSI_IRQSTAT_ADDR)
#define HW_MIPI_HSI_IRQSTAT_RD()      (HW_MIPI_HSI_IRQSTAT.U)
#define HW_MIPI_HSI_IRQSTAT_WR(v)     (HW_MIPI_HSI_IRQSTAT.U = (v))
#define HW_MIPI_HSI_IRQSTAT_SET(v)    (HW_MIPI_HSI_IRQSTAT_WR(HW_MIPI_HSI_IRQSTAT_RD() |  (v)))
#define HW_MIPI_HSI_IRQSTAT_CLR(v)    (HW_MIPI_HSI_IRQSTAT_WR(HW_MIPI_HSI_IRQSTAT_RD() & ~(v)))
#define HW_MIPI_HSI_IRQSTAT_TOG(v)    (HW_MIPI_HSI_IRQSTAT_WR(HW_MIPI_HSI_IRQSTAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_IRQSTAT bitfields
 */

/* --- Register HW_MIPI_HSI_IRQSTAT, field FIFO_THRESHOLD_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in TX/Rx FIFO Interrupt Status
 * 0 - Threshold amount of data not reached in TX/Rx FIFO Interrupt Status
 */

#define BP_MIPI_HSI_IRQSTAT_FIFO_THRESHOLD_INT      0
#define BM_MIPI_HSI_IRQSTAT_FIFO_THRESHOLD_INT      0x00000001


/* --- Register HW_MIPI_HSI_IRQSTAT, field RX_WAKEUP_INT (WO)
 *

 *
 * Values:
 * 1 - Receiver Wakeup event is occurred
 * 0 - Receiver Wakeup event is not occurred
 */

#define BP_MIPI_HSI_IRQSTAT_RX_WAKEUP_INT      1
#define BM_MIPI_HSI_IRQSTAT_RX_WAKEUP_INT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_RX_WAKEUP_INT(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_IRQSTAT_RX_WAKEUP_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_RX_WAKEUP_INT(v)   (((v) << 1) & BM_MIPI_HSI_IRQSTAT_RX_WAKEUP_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_WAKEUP_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_RX_WAKEUP_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT, RX_WAKEUP_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT, field RX_TIMEOUT_INT (RO)
 *
 * If any bit in the HSI Error Interrupt Status Register is set, then this bit is set. on seeing
 * this bit set, the ocp driver will read the Error Interrupt Staus Register.
 *
 * Values:
 * 0 - No Error.
 * 1 - Error.
 */

#define BP_MIPI_HSI_IRQSTAT_RX_TIMEOUT_INT      2
#define BM_MIPI_HSI_IRQSTAT_RX_TIMEOUT_INT      0x00000004


/* --- Register HW_MIPI_HSI_IRQSTAT, field DMA_INT (RO)
 *
 * This bit is set when a Transmit or Receive Operation is completed for DMA.
 */

#define BP_MIPI_HSI_IRQSTAT_DMA_INT      3
#define BM_MIPI_HSI_IRQSTAT_DMA_INT      0x00000008

/* --- Register HW_MIPI_HSI_IRQSTAT, field DMA_ERR_INT (RO)
 *
 * If any bit in the DMA Error Interrupt Status Register is set, then this bit is set. on seeing
 * this bit set, the ocp driver will read the Error Interrupt Staus Register.
 *
 * Values:
 * 0 - No Error.
 * 1 - Error.
 */

#define BP_MIPI_HSI_IRQSTAT_DMA_ERR_INT      4
#define BM_MIPI_HSI_IRQSTAT_DMA_ERR_INT      0x00000010


/* --- Register HW_MIPI_HSI_IRQSTAT, field TX_TIMEOUT_ERR_INT (WO)
 *

 *
 * Values:
 * 0 - No Error.
 * 1 - Error.
 */

#define BP_MIPI_HSI_IRQSTAT_TX_TIMEOUT_ERR_INT      5
#define BM_MIPI_HSI_IRQSTAT_TX_TIMEOUT_ERR_INT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_TX_TIMEOUT_ERR_INT(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_IRQSTAT_TX_TIMEOUT_ERR_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_TX_TIMEOUT_ERR_INT(v)   (((v) << 5) & BM_MIPI_HSI_IRQSTAT_TX_TIMEOUT_ERR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_TIMEOUT_ERR_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_TX_TIMEOUT_ERR_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT, TX_TIMEOUT_ERR_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT, field RX_ERROR_INT (WO)
 *

 *
 * Values:
 * 0 - No Error.
 * 1 - Error.
 */

#define BP_MIPI_HSI_IRQSTAT_RX_ERROR_INT      6
#define BM_MIPI_HSI_IRQSTAT_RX_ERROR_INT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_RX_ERROR_INT(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_IRQSTAT_RX_ERROR_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_RX_ERROR_INT(v)   (((v) << 6) & BM_MIPI_HSI_IRQSTAT_RX_ERROR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ERROR_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_RX_ERROR_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT, RX_ERROR_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT, field RX_BREAK_INT (WO)
 *

 *
 * Values:
 * 0 - No Error.
 * 1 - Error.
 */

#define BP_MIPI_HSI_IRQSTAT_RX_BREAK_INT      7
#define BM_MIPI_HSI_IRQSTAT_RX_BREAK_INT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_RX_BREAK_INT(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_IRQSTAT_RX_BREAK_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_RX_BREAK_INT(v)   (((v) << 7) & BM_MIPI_HSI_IRQSTAT_RX_BREAK_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_BREAK_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_RX_BREAK_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT, RX_BREAK_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT, field TX_EMPTY_INT (RO)
 *

 *
 * Values:
 * 1 - All tx channel empty and tx state IDLE Interrupt Status
 * 0 - not All tx channel empty and tx state IDLE Interrupt Status
 */

#define BP_MIPI_HSI_IRQSTAT_TX_EMPTY_INT      8
#define BM_MIPI_HSI_IRQSTAT_TX_EMPTY_INT      0x00000100


/* --- Register HW_MIPI_HSI_IRQSTAT, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_IRQSTAT_RESERVED      9
#define BM_MIPI_HSI_IRQSTAT_RESERVED      0xfffffe00

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_IRQSTAT_EN - HSI Interrupt Status Enable Register (RW)
 *
 * This register contains the HSI controller Interrupt Status Enable.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FIFO_THRESHOLD_INT : 1; //!< 
        unsigned RX_WAKEUP_INT : 1; //!< 
        unsigned RX_TIMEOUT_INT : 1; //!< 
        unsigned DMA_INT : 1; //!< 
        unsigned DMA_ERR_INT : 1; //!< 
        unsigned TX_TIMEOUT_ERR_INT : 1; //!< 
        unsigned RX_ERROR_INT : 1; //!< 
        unsigned RX_BREAK_INT : 1; //!< 
        unsigned TX_EMPTY_INT : 1; //!< 
        unsigned RESERVED : 23; //!< Reserved, always set to zero.
    } B;
} hw_mipi_hsi_irqstat_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_IRQSTAT_EN register
 */
#define HW_MIPI_HSI_IRQSTAT_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_IRQSTAT_EN           (*(volatile hw_mipi_hsi_irqstat_en_t *) HW_MIPI_HSI_IRQSTAT_EN_ADDR)
#define HW_MIPI_HSI_IRQSTAT_EN_RD()      (HW_MIPI_HSI_IRQSTAT_EN.U)
#define HW_MIPI_HSI_IRQSTAT_EN_WR(v)     (HW_MIPI_HSI_IRQSTAT_EN.U = (v))
#define HW_MIPI_HSI_IRQSTAT_EN_SET(v)    (HW_MIPI_HSI_IRQSTAT_EN_WR(HW_MIPI_HSI_IRQSTAT_EN_RD() |  (v)))
#define HW_MIPI_HSI_IRQSTAT_EN_CLR(v)    (HW_MIPI_HSI_IRQSTAT_EN_WR(HW_MIPI_HSI_IRQSTAT_EN_RD() & ~(v)))
#define HW_MIPI_HSI_IRQSTAT_EN_TOG(v)    (HW_MIPI_HSI_IRQSTAT_EN_WR(HW_MIPI_HSI_IRQSTAT_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_IRQSTAT_EN bitfields
 */

/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field FIFO_THRESHOLD_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for FIFO_THRESHOLD_INT_STATUS interrupt.
 * 0 - Interrupt status masked FIFO_THRESHOLD_INT_STATUS interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_FIFO_THRESHOLD_INT      0
#define BM_MIPI_HSI_IRQSTAT_EN_FIFO_THRESHOLD_INT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_FIFO_THRESHOLD_INT(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_IRQSTAT_EN_FIFO_THRESHOLD_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_FIFO_THRESHOLD_INT(v)   (((v) << 0) & BM_MIPI_HSI_IRQSTAT_EN_FIFO_THRESHOLD_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_THRESHOLD_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_FIFO_THRESHOLD_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, FIFO_THRESHOLD_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field RX_WAKEUP_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for RX_WAKEUP_INT_STATUS interrupt.
 * 0 - Interrupt status masked RX_WAKEUP_INT_STATUS interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_RX_WAKEUP_INT      1
#define BM_MIPI_HSI_IRQSTAT_EN_RX_WAKEUP_INT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_RX_WAKEUP_INT(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_IRQSTAT_EN_RX_WAKEUP_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_RX_WAKEUP_INT(v)   (((v) << 1) & BM_MIPI_HSI_IRQSTAT_EN_RX_WAKEUP_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_WAKEUP_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_RX_WAKEUP_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, RX_WAKEUP_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field RX_TIMEOUT_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for RX_TIMEOUT_INT_STATUS interrupt.
 * 0 - Interrupt status masked RX_TIMEOUT_INT_STATUS interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_RX_TIMEOUT_INT      2
#define BM_MIPI_HSI_IRQSTAT_EN_RX_TIMEOUT_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_RX_TIMEOUT_INT(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_IRQSTAT_EN_RX_TIMEOUT_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_RX_TIMEOUT_INT(v)   (((v) << 2) & BM_MIPI_HSI_IRQSTAT_EN_RX_TIMEOUT_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_TIMEOUT_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_RX_TIMEOUT_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, RX_TIMEOUT_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field DMA_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for DMA_INT_STATUS interrupt.
 * 0 - Interrupt status masked DMA_INT_STATUS interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_DMA_INT      3
#define BM_MIPI_HSI_IRQSTAT_EN_DMA_INT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_DMA_INT(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_IRQSTAT_EN_DMA_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_DMA_INT(v)   (((v) << 3) & BM_MIPI_HSI_IRQSTAT_EN_DMA_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_DMA_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, DMA_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field DMA_ERR_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for DMA_ERROR_INT_STATUS interrupt.
 * 0 - Interrupt status masked DMA_ERROR_INT_STATUS interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_DMA_ERR_INT      4
#define BM_MIPI_HSI_IRQSTAT_EN_DMA_ERR_INT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_DMA_ERR_INT(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_IRQSTAT_EN_DMA_ERR_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_DMA_ERR_INT(v)   (((v) << 4) & BM_MIPI_HSI_IRQSTAT_EN_DMA_ERR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_ERR_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_DMA_ERR_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, DMA_ERR_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field TX_TIMEOUT_ERR_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for TX_TIMEOUT_ERR status interrupt.
 * 0 - Interrupt status masked TX_TIMEOUT_ERR status interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_TX_TIMEOUT_ERR_INT      5
#define BM_MIPI_HSI_IRQSTAT_EN_TX_TIMEOUT_ERR_INT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_TX_TIMEOUT_ERR_INT(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_IRQSTAT_EN_TX_TIMEOUT_ERR_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_TX_TIMEOUT_ERR_INT(v)   (((v) << 5) & BM_MIPI_HSI_IRQSTAT_EN_TX_TIMEOUT_ERR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_TIMEOUT_ERR_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_TX_TIMEOUT_ERR_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, TX_TIMEOUT_ERR_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field RX_ERROR_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for RX_ERROR status interrupt.
 * 0 - Interrupt status masked RX_ERROR status interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_RX_ERROR_INT      6
#define BM_MIPI_HSI_IRQSTAT_EN_RX_ERROR_INT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_RX_ERROR_INT(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_IRQSTAT_EN_RX_ERROR_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_RX_ERROR_INT(v)   (((v) << 6) & BM_MIPI_HSI_IRQSTAT_EN_RX_ERROR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ERROR_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_RX_ERROR_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, RX_ERROR_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field RX_BREAK_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for RX_BREAK status interrupt.
 * 0 - Interrupt status masked RX_BREAK status interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_RX_BREAK_INT      7
#define BM_MIPI_HSI_IRQSTAT_EN_RX_BREAK_INT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_RX_BREAK_INT(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_IRQSTAT_EN_RX_BREAK_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_RX_BREAK_INT(v)   (((v) << 7) & BM_MIPI_HSI_IRQSTAT_EN_RX_BREAK_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_BREAK_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_RX_BREAK_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, RX_BREAK_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field TX_EMPTY_INT (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for TX_EMPTY_INT_STATUS interrupt.
 * 0 - Interrupt status masked TX_EMPTY_INT_STATUS interrupt.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_TX_EMPTY_INT      8
#define BM_MIPI_HSI_IRQSTAT_EN_TX_EMPTY_INT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSTAT_EN_TX_EMPTY_INT(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_IRQSTAT_EN_TX_EMPTY_INT)
#else
#define BF_MIPI_HSI_IRQSTAT_EN_TX_EMPTY_INT(v)   (((v) << 8) & BM_MIPI_HSI_IRQSTAT_EN_TX_EMPTY_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EMPTY_INT field to a new value.
#define BW_MIPI_HSI_IRQSTAT_EN_TX_EMPTY_INT(v)   BF_CS1(MIPI_HSI_IRQSTAT_EN, TX_EMPTY_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSTAT_EN, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_IRQSTAT_EN_RESERVED      9
#define BM_MIPI_HSI_IRQSTAT_EN_RESERVED      0xfffffe00

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_IRQSIG_EN - HSI Interrupt Signal Enable Register (RW)
 *
 * This register contains the HSI controller Interrupt Signal Enable.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FIFO_THRESHOLD_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_WAKEUP_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_TIMEOUT_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned DMA_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned DMA_ERR_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_TIMEOUT_ERR_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_ERROR_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_BREAK_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_EMPTY_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RESERVED : 23; //!< Reserved, always set to zero.
    } B;
} hw_mipi_hsi_irqsig_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_IRQSIG_EN register
 */
#define HW_MIPI_HSI_IRQSIG_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_IRQSIG_EN           (*(volatile hw_mipi_hsi_irqsig_en_t *) HW_MIPI_HSI_IRQSIG_EN_ADDR)
#define HW_MIPI_HSI_IRQSIG_EN_RD()      (HW_MIPI_HSI_IRQSIG_EN.U)
#define HW_MIPI_HSI_IRQSIG_EN_WR(v)     (HW_MIPI_HSI_IRQSIG_EN.U = (v))
#define HW_MIPI_HSI_IRQSIG_EN_SET(v)    (HW_MIPI_HSI_IRQSIG_EN_WR(HW_MIPI_HSI_IRQSIG_EN_RD() |  (v)))
#define HW_MIPI_HSI_IRQSIG_EN_CLR(v)    (HW_MIPI_HSI_IRQSIG_EN_WR(HW_MIPI_HSI_IRQSIG_EN_RD() & ~(v)))
#define HW_MIPI_HSI_IRQSIG_EN_TOG(v)    (HW_MIPI_HSI_IRQSIG_EN_WR(HW_MIPI_HSI_IRQSIG_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_IRQSIG_EN bitfields
 */

/* --- Register HW_MIPI_HSI_IRQSIG_EN, field FIFO_THRESHOLD_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for HSI FIFO_THRESHOLD interrupt.
 * 0 - Interrupt signal masked for HSI FIFO_THRESHOLD interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_FIFO_THRESHOLD_INT      0
#define BM_MIPI_HSI_IRQSIG_EN_FIFO_THRESHOLD_INT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_FIFO_THRESHOLD_INT(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_IRQSIG_EN_FIFO_THRESHOLD_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_FIFO_THRESHOLD_INT(v)   (((v) << 0) & BM_MIPI_HSI_IRQSIG_EN_FIFO_THRESHOLD_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_THRESHOLD_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_FIFO_THRESHOLD_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, FIFO_THRESHOLD_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field RX_WAKEUP_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for HSI RX Wakeup interrupt.
 * 0 - Interrupt signal masked for HSI RX Wakeup interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_RX_WAKEUP_INT      1
#define BM_MIPI_HSI_IRQSIG_EN_RX_WAKEUP_INT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_RX_WAKEUP_INT(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_IRQSIG_EN_RX_WAKEUP_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_RX_WAKEUP_INT(v)   (((v) << 1) & BM_MIPI_HSI_IRQSIG_EN_RX_WAKEUP_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_WAKEUP_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_RX_WAKEUP_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, RX_WAKEUP_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field RX_TIMEOUT_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for RX TIMEOUT interrupt.
 * 0 - Interrupt signal masked for RX TIMEOUT interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_RX_TIMEOUT_INT      2
#define BM_MIPI_HSI_IRQSIG_EN_RX_TIMEOUT_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_RX_TIMEOUT_INT(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_IRQSIG_EN_RX_TIMEOUT_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_RX_TIMEOUT_INT(v)   (((v) << 2) & BM_MIPI_HSI_IRQSIG_EN_RX_TIMEOUT_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_TIMEOUT_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_RX_TIMEOUT_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, RX_TIMEOUT_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field DMA_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for DMA Completed interrupt.
 * 0 - Interrupt signal masked for DMA Completed interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_DMA_INT      3
#define BM_MIPI_HSI_IRQSIG_EN_DMA_INT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_DMA_INT(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_IRQSIG_EN_DMA_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_DMA_INT(v)   (((v) << 3) & BM_MIPI_HSI_IRQSIG_EN_DMA_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_DMA_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, DMA_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field DMA_ERR_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for DMA Error interrupt.
 * 0 - Interrupt signal masked for DMA Error interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_DMA_ERR_INT      4
#define BM_MIPI_HSI_IRQSIG_EN_DMA_ERR_INT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_DMA_ERR_INT(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_IRQSIG_EN_DMA_ERR_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_DMA_ERR_INT(v)   (((v) << 4) & BM_MIPI_HSI_IRQSIG_EN_DMA_ERR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_ERR_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_DMA_ERR_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, DMA_ERR_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field TX_TIMEOUT_ERR_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for TX Timeout Error interrupt.
 * 0 - Interrupt signal masked for TX Timeout Error interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_TX_TIMEOUT_ERR_INT      5
#define BM_MIPI_HSI_IRQSIG_EN_TX_TIMEOUT_ERR_INT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_TX_TIMEOUT_ERR_INT(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_IRQSIG_EN_TX_TIMEOUT_ERR_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_TX_TIMEOUT_ERR_INT(v)   (((v) << 5) & BM_MIPI_HSI_IRQSIG_EN_TX_TIMEOUT_ERR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_TIMEOUT_ERR_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_TX_TIMEOUT_ERR_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, TX_TIMEOUT_ERR_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field RX_ERROR_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for RX Error interrupt.
 * 0 - Interrupt signal masked for RX Error interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_RX_ERROR_INT      6
#define BM_MIPI_HSI_IRQSIG_EN_RX_ERROR_INT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_RX_ERROR_INT(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_IRQSIG_EN_RX_ERROR_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_RX_ERROR_INT(v)   (((v) << 6) & BM_MIPI_HSI_IRQSIG_EN_RX_ERROR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ERROR_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_RX_ERROR_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, RX_ERROR_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field RX_BREAK_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for RX_BREAK interrupt.
 * 0 - Interrupt signal masked for RX_BREAK interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_RX_BREAK_INT      7
#define BM_MIPI_HSI_IRQSIG_EN_RX_BREAK_INT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_RX_BREAK_INT(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_IRQSIG_EN_RX_BREAK_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_RX_BREAK_INT(v)   (((v) << 7) & BM_MIPI_HSI_IRQSIG_EN_RX_BREAK_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_BREAK_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_RX_BREAK_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, RX_BREAK_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field TX_EMPTY_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for HSI TX_EMPTY interrupt.
 * 0 - Interrupt signal masked for HSI TX_EMPTY interrupt.
 */

#define BP_MIPI_HSI_IRQSIG_EN_TX_EMPTY_INT      8
#define BM_MIPI_HSI_IRQSIG_EN_TX_EMPTY_INT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_IRQSIG_EN_TX_EMPTY_INT(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_IRQSIG_EN_TX_EMPTY_INT)
#else
#define BF_MIPI_HSI_IRQSIG_EN_TX_EMPTY_INT(v)   (((v) << 8) & BM_MIPI_HSI_IRQSIG_EN_TX_EMPTY_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EMPTY_INT field to a new value.
#define BW_MIPI_HSI_IRQSIG_EN_TX_EMPTY_INT(v)   BF_CS1(MIPI_HSI_IRQSIG_EN, TX_EMPTY_INT, v)
#endif


/* --- Register HW_MIPI_HSI_IRQSIG_EN, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_IRQSIG_EN_RESERVED      9
#define BM_MIPI_HSI_IRQSIG_EN_RESERVED      0xfffffe00

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_FIFO_THR_IRQSTAT - HSI FIFO Threshold Interrupt Status Register (RO)
 *
 * This register contains the HSI controller FIFO Threshold Interrupt Status.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RX_CH0_INT : 1; //!< 
        unsigned RX_CH1_INT : 1; //!< 
        unsigned RX_CH2_INT : 1; //!< 
        unsigned RX_CH3_INT : 1; //!< 
        unsigned RX_CH4_INT : 1; //!< 
        unsigned RX_CH5_INT : 1; //!< 
        unsigned RX_CH6_INT : 1; //!< 
        unsigned RX_CH7_INT : 1; //!< 
        unsigned RX_CH8_INT : 1; //!< 
        unsigned RX_CH9_INT : 1; //!< 
        unsigned RX_CH10_INT : 1; //!< 
        unsigned RX_CH11_INT : 1; //!< 
        unsigned RX_CH12_INT : 1; //!< 
        unsigned RX_CH13_INT : 1; //!< 
        unsigned RX_CH14_INT : 1; //!< 
        unsigned RX_CH15_INT : 1; //!< 
        unsigned TX_CH0_INT : 1; //!< 
        unsigned TX_CH1_INT : 1; //!< 
        unsigned TX_CH2_INT : 1; //!< 
        unsigned TX_CH3_INT : 1; //!< 
        unsigned TX_CH4_INT : 1; //!< 
        unsigned TX_CH5_INT : 1; //!< 
        unsigned TX_CH6_INT : 1; //!< 
        unsigned TX_CH7_INT : 1; //!< 
        unsigned TX_CH8_INT : 1; //!< 
        unsigned TX_CH9_INT : 1; //!< 
        unsigned TX_CH10_INT : 1; //!< 
        unsigned TX_CH11_INT : 1; //!< 
        unsigned TX_CH12_INT : 1; //!< 
        unsigned TX_CH13_INT : 1; //!< 
        unsigned TX_CH14_INT : 1; //!< 
        unsigned TX_CH15_INT : 1; //!< 
    } B;
} hw_mipi_hsi_fifo_thr_irqstat_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_FIFO_THR_IRQSTAT register
 */
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_ADDR      (REGS_MIPI_HSI_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT           (*(volatile hw_mipi_hsi_fifo_thr_irqstat_t *) HW_MIPI_HSI_FIFO_THR_IRQSTAT_ADDR)
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_RD()      (HW_MIPI_HSI_FIFO_THR_IRQSTAT.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_FIFO_THR_IRQSTAT bitfields
 */

/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH0_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 0 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 0 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH0_INT      0
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH0_INT      0x00000001


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH1_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 1 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 1 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH1_INT      1
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH1_INT      0x00000002


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH2_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 2 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 2 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH2_INT      2
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH2_INT      0x00000004


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH3_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 3 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 3 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH3_INT      3
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH3_INT      0x00000008


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH4_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 4 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 4 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH4_INT      4
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH4_INT      0x00000010


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH5_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 5 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 5 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH5_INT      5
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH5_INT      0x00000020


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH6_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 6 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 6 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH6_INT      6
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH6_INT      0x00000040


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH7_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 7 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 7 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH7_INT      7
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH7_INT      0x00000080


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH8_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 8 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 8 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH8_INT      8
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH8_INT      0x00000100


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH9_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 9 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 9 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH9_INT      9
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH9_INT      0x00000200


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH10_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 10 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 10 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH10_INT      10
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH10_INT      0x00000400


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH11_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 11 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 11 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH11_INT      11
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH11_INT      0x00000800


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH12_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 12 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 12 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH12_INT      12
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH12_INT      0x00001000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH13_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 13 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 13 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH13_INT      13
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH13_INT      0x00002000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH14_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 14 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 14 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH14_INT      14
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH14_INT      0x00004000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field RX_CH15_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Rx Channel 15 FIFO
 * 0 - Threshold amount of data not reached in Rx Channel 15 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH15_INT      15
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_RX_CH15_INT      0x00008000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH0_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 0 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 0 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH0_INT      16
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH0_INT      0x00010000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH1_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 1 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 1 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH1_INT      17
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH1_INT      0x00020000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH2_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 2 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 2 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH2_INT      18
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH2_INT      0x00040000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH3_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 3 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 3 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH3_INT      19
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH3_INT      0x00080000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH4_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 4 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 4 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH4_INT      20
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH4_INT      0x00100000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH5_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 5 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 5 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH5_INT      21
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH5_INT      0x00200000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH6_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 6 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 6 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH6_INT      22
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH6_INT      0x00400000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH7_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 7 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 7 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH7_INT      23
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH7_INT      0x00800000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH8_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 8 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 8 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH8_INT      24
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH8_INT      0x01000000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH9_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 9 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 9 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH9_INT      25
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH9_INT      0x02000000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH10_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 10 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 10 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH10_INT      26
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH10_INT      0x04000000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH11_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 11 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 11 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH11_INT      27
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH11_INT      0x08000000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH12_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 12 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 12 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH12_INT      28
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH12_INT      0x10000000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH13_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 13 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 13 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH13_INT      29
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH13_INT      0x20000000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH14_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 14 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 14 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH14_INT      30
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH14_INT      0x40000000


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT, field TX_CH15_INT (RO)
 *

 *
 * Values:
 * 1 - Threshold amount of data reached in Tx Channel 15 FIFO
 * 0 - Threshold amount of data not reached in Tx Channel 15 FIFO
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH15_INT      31
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_TX_CH15_INT      0x80000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN - HSI FIFO Threshold Interrupt Status Enable Register (RW)
 *
 * This register contains the HSI controller FIFO Threshold Interrupt Status Enable.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RX_CH0_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH1_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH2_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH3_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH4_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH5_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH6_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH7_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH8_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH9_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH10_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH11_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH12_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH13_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH14_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH15_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH0_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH1_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH2_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH3_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH4_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH5_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH6_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH7_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH8_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH9_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH10_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH11_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH12_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH13_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH14_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH15_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
    } B;
} hw_mipi_hsi_fifo_thr_irqstat_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_FIFO_THR_IRQSTAT_EN register
 */
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN           (*(volatile hw_mipi_hsi_fifo_thr_irqstat_en_t *) HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_ADDR)
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RD()      (HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN.U)
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_WR(v)     (HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN.U = (v))
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_SET(v)    (HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_WR(HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RD() |  (v)))
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_CLR(v)    (HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_WR(HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RD() & ~(v)))
#define HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TOG(v)    (HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_WR(HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_FIFO_THR_IRQSTAT_EN bitfields
 */

/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH0_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch0 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch0 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH0_INT      0
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH0_INT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH0_INT(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH0_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH0_INT(v)   (((v) << 0) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH0_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH0_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH0_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH0_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH1_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch1 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch1 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH1_INT      1
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH1_INT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH1_INT(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH1_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH1_INT(v)   (((v) << 1) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH1_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH1_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH1_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH1_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH2_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch2 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch2 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH2_INT      2
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH2_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH2_INT(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH2_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH2_INT(v)   (((v) << 2) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH2_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH2_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH2_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH2_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH3_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch3 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch3 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH3_INT      3
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH3_INT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH3_INT(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH3_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH3_INT(v)   (((v) << 3) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH3_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH3_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH3_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH3_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH4_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch4 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch4 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH4_INT      4
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH4_INT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH4_INT(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH4_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH4_INT(v)   (((v) << 4) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH4_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH4_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH4_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH4_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH5_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch5 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch5 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH5_INT      5
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH5_INT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH5_INT(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH5_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH5_INT(v)   (((v) << 5) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH5_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH5_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH5_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH5_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH6_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch6 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch6 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH6_INT      6
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH6_INT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH6_INT(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH6_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH6_INT(v)   (((v) << 6) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH6_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH6_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH6_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH6_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH7_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch7 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch7 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH7_INT      7
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH7_INT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH7_INT(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH7_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH7_INT(v)   (((v) << 7) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH7_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH7_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH7_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH7_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH8_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch8 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch8 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH8_INT      8
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH8_INT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH8_INT(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH8_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH8_INT(v)   (((v) << 8) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH8_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH8_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH8_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH8_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH9_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch9 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch9 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH9_INT      9
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH9_INT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH9_INT(v)   ((((reg32_t) v) << 9) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH9_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH9_INT(v)   (((v) << 9) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH9_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH9_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH9_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH9_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH10_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch10 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch10 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH10_INT      10
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH10_INT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH10_INT(v)   ((((reg32_t) v) << 10) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH10_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH10_INT(v)   (((v) << 10) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH10_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH10_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH10_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH10_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH11_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch11 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch11 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH11_INT      11
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH11_INT      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH11_INT(v)   ((((reg32_t) v) << 11) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH11_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH11_INT(v)   (((v) << 11) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH11_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH11_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH11_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH11_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH12_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch12 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch12 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH12_INT      12
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH12_INT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH12_INT(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH12_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH12_INT(v)   (((v) << 12) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH12_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH12_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH12_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH12_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH13_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch13 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch13 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH13_INT      13
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH13_INT      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH13_INT(v)   ((((reg32_t) v) << 13) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH13_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH13_INT(v)   (((v) << 13) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH13_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH13_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH13_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH13_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH14_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch14 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch14 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH14_INT      14
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH14_INT      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH14_INT(v)   ((((reg32_t) v) << 14) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH14_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH14_INT(v)   (((v) << 14) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH14_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH14_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH14_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH14_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field RX_CH15_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch15 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch15 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH15_INT      15
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH15_INT      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH15_INT(v)   ((((reg32_t) v) << 15) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH15_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH15_INT(v)   (((v) << 15) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH15_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH15_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_RX_CH15_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, RX_CH15_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH0_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch0 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch0 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH0_INT      16
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH0_INT      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH0_INT(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH0_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH0_INT(v)   (((v) << 16) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH0_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH0_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH0_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH0_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH1_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch1 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch1 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH1_INT      17
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH1_INT      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH1_INT(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH1_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH1_INT(v)   (((v) << 17) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH1_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH1_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH1_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH1_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH2_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch2 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch2 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH2_INT      18
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH2_INT      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH2_INT(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH2_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH2_INT(v)   (((v) << 18) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH2_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH2_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH2_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH2_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH3_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch3 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch3 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH3_INT      19
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH3_INT      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH3_INT(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH3_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH3_INT(v)   (((v) << 19) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH3_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH3_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH3_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH3_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH4_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch4 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch4 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH4_INT      20
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH4_INT      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH4_INT(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH4_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH4_INT(v)   (((v) << 20) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH4_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH4_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH4_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH4_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH5_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch5 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch5 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH5_INT      21
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH5_INT      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH5_INT(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH5_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH5_INT(v)   (((v) << 21) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH5_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH5_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH5_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH5_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH6_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch6 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch6 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH6_INT      22
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH6_INT      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH6_INT(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH6_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH6_INT(v)   (((v) << 22) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH6_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH6_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH6_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH6_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH7_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch7 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch7 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH7_INT      23
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH7_INT      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH7_INT(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH7_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH7_INT(v)   (((v) << 23) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH7_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH7_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH7_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH7_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH8_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch8 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch8 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH8_INT      24
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH8_INT      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH8_INT(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH8_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH8_INT(v)   (((v) << 24) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH8_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH8_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH8_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH8_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH9_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch9 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch9 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH9_INT      25
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH9_INT      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH9_INT(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH9_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH9_INT(v)   (((v) << 25) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH9_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH9_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH9_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH9_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH10_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch10 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch10 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH10_INT      26
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH10_INT      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH10_INT(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH10_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH10_INT(v)   (((v) << 26) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH10_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH10_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH10_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH10_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH11_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch11 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch11 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH11_INT      27
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH11_INT      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH11_INT(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH11_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH11_INT(v)   (((v) << 27) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH11_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH11_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH11_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH11_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH12_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch12 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch12 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH12_INT      28
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH12_INT      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH12_INT(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH12_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH12_INT(v)   (((v) << 28) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH12_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH12_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH12_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH12_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH13_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch13 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch13 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH13_INT      29
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH13_INT      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH13_INT(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH13_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH13_INT(v)   (((v) << 29) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH13_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH13_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH13_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH13_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH14_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch14 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch14 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH14_INT      30
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH14_INT      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH14_INT(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH14_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH14_INT(v)   (((v) << 30) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH14_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH14_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH14_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH14_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSTAT_EN, field TX_CH15_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch15 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch15 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH15_INT      31
#define BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH15_INT      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH15_INT(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH15_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH15_INT(v)   (((v) << 31) & BM_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH15_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH15_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSTAT_EN_TX_CH15_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSTAT_EN, TX_CH15_INT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_FIFO_THR_IRQSIG_EN - HSI FIFO Threshold Interrupt Signal Enable Register (RW)
 *
 * This register contains the HSI controller FIFO Threshold Interrupt Enable.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RX_CH0_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH1_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH2_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH3_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH4_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH5_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH6_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH7_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH8_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH9_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH10_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH11_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH12_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH13_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH14_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH15_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH0_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH1_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH2_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH3_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH4_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH5_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH6_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH7_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH8_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH9_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH10_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH11_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH12_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH13_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH14_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned TX_CH15_INT : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
    } B;
} hw_mipi_hsi_fifo_thr_irqsig_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_FIFO_THR_IRQSIG_EN register
 */
#define HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_FIFO_THR_IRQSIG_EN           (*(volatile hw_mipi_hsi_fifo_thr_irqsig_en_t *) HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_ADDR)
#define HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RD()      (HW_MIPI_HSI_FIFO_THR_IRQSIG_EN.U)
#define HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_WR(v)     (HW_MIPI_HSI_FIFO_THR_IRQSIG_EN.U = (v))
#define HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_SET(v)    (HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_WR(HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RD() |  (v)))
#define HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_CLR(v)    (HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_WR(HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RD() & ~(v)))
#define HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TOG(v)    (HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_WR(HW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_FIFO_THR_IRQSIG_EN bitfields
 */

/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH0_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch0 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch0 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH0_INT      0
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH0_INT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH0_INT(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH0_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH0_INT(v)   (((v) << 0) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH0_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH0_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH0_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH0_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH1_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch1 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch1 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH1_INT      1
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH1_INT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH1_INT(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH1_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH1_INT(v)   (((v) << 1) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH1_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH1_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH1_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH1_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH2_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch2 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch2 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH2_INT      2
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH2_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH2_INT(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH2_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH2_INT(v)   (((v) << 2) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH2_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH2_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH2_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH2_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH3_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch3 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch3 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH3_INT      3
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH3_INT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH3_INT(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH3_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH3_INT(v)   (((v) << 3) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH3_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH3_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH3_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH3_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH4_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch4 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch4 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH4_INT      4
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH4_INT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH4_INT(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH4_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH4_INT(v)   (((v) << 4) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH4_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH4_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH4_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH4_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH5_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch5 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch5 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH5_INT      5
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH5_INT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH5_INT(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH5_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH5_INT(v)   (((v) << 5) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH5_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH5_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH5_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH5_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH6_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch6 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch6 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH6_INT      6
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH6_INT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH6_INT(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH6_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH6_INT(v)   (((v) << 6) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH6_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH6_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH6_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH6_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH7_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch7 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch7 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH7_INT      7
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH7_INT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH7_INT(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH7_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH7_INT(v)   (((v) << 7) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH7_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH7_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH7_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH7_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH8_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch8 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch8 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH8_INT      8
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH8_INT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH8_INT(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH8_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH8_INT(v)   (((v) << 8) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH8_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH8_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH8_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH8_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH9_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch9 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch9 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH9_INT      9
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH9_INT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH9_INT(v)   ((((reg32_t) v) << 9) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH9_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH9_INT(v)   (((v) << 9) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH9_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH9_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH9_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH9_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH10_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch10 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch10 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH10_INT      10
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH10_INT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH10_INT(v)   ((((reg32_t) v) << 10) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH10_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH10_INT(v)   (((v) << 10) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH10_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH10_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH10_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH10_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH11_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch11 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch11 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH11_INT      11
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH11_INT      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH11_INT(v)   ((((reg32_t) v) << 11) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH11_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH11_INT(v)   (((v) << 11) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH11_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH11_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH11_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH11_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH12_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch12 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch12 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH12_INT      12
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH12_INT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH12_INT(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH12_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH12_INT(v)   (((v) << 12) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH12_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH12_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH12_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH12_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH13_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch13 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch13 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH13_INT      13
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH13_INT      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH13_INT(v)   ((((reg32_t) v) << 13) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH13_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH13_INT(v)   (((v) << 13) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH13_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH13_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH13_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH13_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH14_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch14 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch14 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH14_INT      14
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH14_INT      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH14_INT(v)   ((((reg32_t) v) << 14) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH14_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH14_INT(v)   (((v) << 14) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH14_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH14_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH14_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH14_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field RX_CH15_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Rx Ch15 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Rx Ch15 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH15_INT      15
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH15_INT      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH15_INT(v)   ((((reg32_t) v) << 15) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH15_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH15_INT(v)   (((v) << 15) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH15_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH15_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_RX_CH15_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, RX_CH15_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH0_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch0 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch0 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH0_INT      16
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH0_INT      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH0_INT(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH0_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH0_INT(v)   (((v) << 16) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH0_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH0_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH0_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH0_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH1_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch1 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch1 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH1_INT      17
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH1_INT      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH1_INT(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH1_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH1_INT(v)   (((v) << 17) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH1_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH1_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH1_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH1_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH2_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch2 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch2 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH2_INT      18
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH2_INT      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH2_INT(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH2_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH2_INT(v)   (((v) << 18) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH2_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH2_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH2_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH2_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH3_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch3 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch3 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH3_INT      19
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH3_INT      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH3_INT(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH3_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH3_INT(v)   (((v) << 19) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH3_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH3_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH3_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH3_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH4_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch4 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch4 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH4_INT      20
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH4_INT      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH4_INT(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH4_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH4_INT(v)   (((v) << 20) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH4_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH4_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH4_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH4_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH5_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch5 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch5 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH5_INT      21
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH5_INT      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH5_INT(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH5_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH5_INT(v)   (((v) << 21) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH5_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH5_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH5_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH5_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH6_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch6 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch6 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH6_INT      22
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH6_INT      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH6_INT(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH6_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH6_INT(v)   (((v) << 22) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH6_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH6_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH6_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH6_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH7_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch7 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch7 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH7_INT      23
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH7_INT      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH7_INT(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH7_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH7_INT(v)   (((v) << 23) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH7_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH7_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH7_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH7_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH8_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch8 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch8 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH8_INT      24
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH8_INT      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH8_INT(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH8_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH8_INT(v)   (((v) << 24) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH8_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH8_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH8_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH8_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH9_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch9 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch9 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH9_INT      25
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH9_INT      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH9_INT(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH9_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH9_INT(v)   (((v) << 25) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH9_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH9_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH9_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH9_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH10_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch10 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch10 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH10_INT      26
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH10_INT      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH10_INT(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH10_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH10_INT(v)   (((v) << 26) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH10_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH10_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH10_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH10_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH11_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch11 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch11 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH11_INT      27
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH11_INT      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH11_INT(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH11_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH11_INT(v)   (((v) << 27) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH11_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH11_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH11_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH11_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH12_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch12 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch12 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH12_INT      28
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH12_INT      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH12_INT(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH12_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH12_INT(v)   (((v) << 28) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH12_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH12_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH12_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH12_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH13_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch13 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch13 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH13_INT      29
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH13_INT      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH13_INT(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH13_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH13_INT(v)   (((v) << 29) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH13_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH13_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH13_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH13_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH14_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch14 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch14 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH14_INT      30
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH14_INT      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH14_INT(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH14_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH14_INT(v)   (((v) << 30) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH14_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH14_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH14_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH14_INT, v)
#endif


/* --- Register HW_MIPI_HSI_FIFO_THR_IRQSIG_EN, field TX_CH15_INT (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for Tx Ch15 threshold Reached interrupt.
 * 0 - Interrupt signal masked for Tx Ch15 threshold Reached interrupt.
 */

#define BP_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH15_INT      31
#define BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH15_INT      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH15_INT(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH15_INT)
#else
#define BF_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH15_INT(v)   (((v) << 31) & BM_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH15_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CH15_INT field to a new value.
#define BW_MIPI_HSI_FIFO_THR_IRQSIG_EN_TX_CH15_INT(v)   BF_CS1(MIPI_HSI_FIFO_THR_IRQSIG_EN, TX_CH15_INT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_CH_DP - Tx Channel n Data Port Register (RW)
 *
 * This Register is connected to fifo data port for Tx Channel n.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 32; //!< Software could Write/Read this bits to access Tx Channel n.
    } B;
} hw_mipi_hsi_tx_ch_dp_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_CH_DP register
 */
#define HW_MIPI_HSI_TX_CH_DP_ADDR      (REGS_MIPI_HSI_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_CH_DP           (*(volatile hw_mipi_hsi_tx_ch_dp_t *) HW_MIPI_HSI_TX_CH_DP_ADDR)
#define HW_MIPI_HSI_TX_CH_DP_RD()      (HW_MIPI_HSI_TX_CH_DP.U)
#define HW_MIPI_HSI_TX_CH_DP_WR(v)     (HW_MIPI_HSI_TX_CH_DP.U = (v))
#define HW_MIPI_HSI_TX_CH_DP_SET(v)    (HW_MIPI_HSI_TX_CH_DP_WR(HW_MIPI_HSI_TX_CH_DP_RD() |  (v)))
#define HW_MIPI_HSI_TX_CH_DP_CLR(v)    (HW_MIPI_HSI_TX_CH_DP_WR(HW_MIPI_HSI_TX_CH_DP_RD() & ~(v)))
#define HW_MIPI_HSI_TX_CH_DP_TOG(v)    (HW_MIPI_HSI_TX_CH_DP_WR(HW_MIPI_HSI_TX_CH_DP_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_CH_DP bitfields
 */

/* --- Register HW_MIPI_HSI_TX_CH_DP, field DATA (RW)
 *
 * Software could Write/Read this bits to access Tx Channel n.
 */

#define BP_MIPI_HSI_TX_CH_DP_DATA      0
#define BM_MIPI_HSI_TX_CH_DP_DATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_CH_DP_DATA(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_CH_DP_DATA)
#else
#define BF_MIPI_HSI_TX_CH_DP_DATA(v)   (((v) << 0) & BM_MIPI_HSI_TX_CH_DP_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_MIPI_HSI_TX_CH_DP_DATA(v)   BF_CS1(MIPI_HSI_TX_CH_DP, DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_RX_CH_DP - Rx Channel n Data Port Register (RW)
 *
 * This Register is connected to fifo data port for Rx Channel n.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 32; //!< Software could Write/Read this bits to access Rx Channel n.
    } B;
} hw_mipi_hsi_rx_ch_dp_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_RX_CH_DP register
 */
#define HW_MIPI_HSI_RX_CH_DP_ADDR      (REGS_MIPI_HSI_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_RX_CH_DP           (*(volatile hw_mipi_hsi_rx_ch_dp_t *) HW_MIPI_HSI_RX_CH_DP_ADDR)
#define HW_MIPI_HSI_RX_CH_DP_RD()      (HW_MIPI_HSI_RX_CH_DP.U)
#define HW_MIPI_HSI_RX_CH_DP_WR(v)     (HW_MIPI_HSI_RX_CH_DP.U = (v))
#define HW_MIPI_HSI_RX_CH_DP_SET(v)    (HW_MIPI_HSI_RX_CH_DP_WR(HW_MIPI_HSI_RX_CH_DP_RD() |  (v)))
#define HW_MIPI_HSI_RX_CH_DP_CLR(v)    (HW_MIPI_HSI_RX_CH_DP_WR(HW_MIPI_HSI_RX_CH_DP_RD() & ~(v)))
#define HW_MIPI_HSI_RX_CH_DP_TOG(v)    (HW_MIPI_HSI_RX_CH_DP_WR(HW_MIPI_HSI_RX_CH_DP_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_RX_CH_DP bitfields
 */

/* --- Register HW_MIPI_HSI_RX_CH_DP, field DATA (RW)
 *
 * Software could Write/Read this bits to access Rx Channel n.
 */

#define BP_MIPI_HSI_RX_CH_DP_DATA      0
#define BM_MIPI_HSI_RX_CH_DP_DATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_CH_DP_DATA(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_RX_CH_DP_DATA)
#else
#define BF_MIPI_HSI_RX_CH_DP_DATA(v)   (((v) << 0) & BM_MIPI_HSI_RX_CH_DP_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_MIPI_HSI_RX_CH_DP_DATA(v)   BF_CS1(MIPI_HSI_RX_CH_DP, DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_ERR_IRQSTAT - HSI Error Interrupt Status Register (RO)
 *
 * This register contains the HSI controller Error Interrupt Status.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED : 16; //!< Reserved, always set to zero.
        unsigned RX_CH0_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch0 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch0 buffer and then read HSI Status register to find the further status of the Rx ch0 Buffer. The host driver has to read the Rx ch0 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH1_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch1 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch1 buffer and then read HSI Status register to find the further status of the Rx ch1 Buffer. The host driver has to read the Rx ch1 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH2_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch2 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch2 buffer and then read HSI Status register to find the further status of the Rx ch2 Buffer. The host driver has to read the Rx ch2 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH3_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch3 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch3 buffer and then read HSI Status register to find the further status of the Rx ch3 Buffer. The host driver has to read the Rx ch3 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH4_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch4 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch4 buffer and then read HSI Status register to find the further status of the Rx ch4 Buffer. The host driver has to read the Rx ch4 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH5_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch5 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch5 buffer and then read HSI Status register to find the further status of the Rx ch5 Buffer. The host driver has to read the Rx ch5 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH6_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch6 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch6 buffer and then read HSI Status register to find the further status of the Rx ch6 Buffer. The host driver has to read the Rx ch6 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH7_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch7 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch7 buffer and then read HSI Status register to find the further status of the Rx ch7 Buffer. The host driver has to read the Rx ch7 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH8_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch8 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch8 buffer and then read HSI Status register to find the further status of the Rx ch8 Buffer. The host driver has to read the Rx ch8 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH9_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch9 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch9 buffer and then read HSI Status register to find the further status of the Rx ch9 Buffer. The host driver has to read the Rx ch9 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH10_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch10 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch10 buffer and then read HSI Status register to find the further status of the Rx ch10 Buffer. The host driver has to read the Rx ch10 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH11_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch11 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch11 buffer and then read HSI Status register to find the further status of the Rx ch11 Buffer. The host driver has to read the Rx ch11 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH12_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch12 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch12 buffer and then read HSI Status register to find the further status of the Rx ch12 Buffer. The host driver has to read the Rx ch12 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH13_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch13 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch13 buffer and then read HSI Status register to find the further status of the Rx ch13 Buffer. The host driver has to read the Rx ch13 fifo on Dword basis, till thefifo is completely empty.
        unsigned RX_CH14_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch14 reaches the data timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch14 buffer and then read HSI Status register to find the further status of the Rx ch14 Buffer. The host driver has to read the Rx ch14 fifo on Dword basis, till the fifo is completely empty.
        unsigned RX_CH15_TIMEOUT_INT : 1; //!< This status bit is set when data timeout counter for ch15 reaches thedata timeout counter value. On receiving the interrupt the host driver should read 1Dword of data from Rx ch15 buffer and then read HSI Status register to find the further status of the Rx ch15 Buffer. The host driver has to read the Rx ch15 fifo on Dword basis, till the fifo is completely empty.
    } B;
} hw_mipi_hsi_err_irqstat_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_ERR_IRQSTAT register
 */
#define HW_MIPI_HSI_ERR_IRQSTAT_ADDR      (REGS_MIPI_HSI_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_ERR_IRQSTAT           (*(volatile hw_mipi_hsi_err_irqstat_t *) HW_MIPI_HSI_ERR_IRQSTAT_ADDR)
#define HW_MIPI_HSI_ERR_IRQSTAT_RD()      (HW_MIPI_HSI_ERR_IRQSTAT.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_ERR_IRQSTAT bitfields
 */

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RESERVED      0
#define BM_MIPI_HSI_ERR_IRQSTAT_RESERVED      0x0000ffff

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH0_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch0 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch0 buffer and then
 * read HSI Status register to find the further status of the Rx ch0 Buffer. The host driver has to
 * read the Rx ch0 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH0_TIMEOUT_INT      16
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH0_TIMEOUT_INT      0x00010000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH1_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch1 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch1 buffer and then
 * read HSI Status register to find the further status of the Rx ch1 Buffer. The host driver has to
 * read the Rx ch1 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH1_TIMEOUT_INT      17
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH1_TIMEOUT_INT      0x00020000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH2_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch2 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch2 buffer and then
 * read HSI Status register to find the further status of the Rx ch2 Buffer. The host driver has to
 * read the Rx ch2 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH2_TIMEOUT_INT      18
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH2_TIMEOUT_INT      0x00040000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH3_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch3 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch3 buffer and then
 * read HSI Status register to find the further status of the Rx ch3 Buffer. The host driver has to
 * read the Rx ch3 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH3_TIMEOUT_INT      19
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH3_TIMEOUT_INT      0x00080000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH4_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch4 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch4 buffer and then
 * read HSI Status register to find the further status of the Rx ch4 Buffer. The host driver has to
 * read the Rx ch4 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH4_TIMEOUT_INT      20
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH4_TIMEOUT_INT      0x00100000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH5_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch5 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch5 buffer and then
 * read HSI Status register to find the further status of the Rx ch5 Buffer. The host driver has to
 * read the Rx ch5 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH5_TIMEOUT_INT      21
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH5_TIMEOUT_INT      0x00200000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH6_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch6 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch6 buffer and then
 * read HSI Status register to find the further status of the Rx ch6 Buffer. The host driver has to
 * read the Rx ch6 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH6_TIMEOUT_INT      22
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH6_TIMEOUT_INT      0x00400000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH7_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch7 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch7 buffer and then
 * read HSI Status register to find the further status of the Rx ch7 Buffer. The host driver has to
 * read the Rx ch7 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH7_TIMEOUT_INT      23
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH7_TIMEOUT_INT      0x00800000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH8_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch8 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch8 buffer and then
 * read HSI Status register to find the further status of the Rx ch8 Buffer. The host driver has to
 * read the Rx ch8 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH8_TIMEOUT_INT      24
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH8_TIMEOUT_INT      0x01000000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH9_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch9 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch9 buffer and then
 * read HSI Status register to find the further status of the Rx ch9 Buffer. The host driver has to
 * read the Rx ch9 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH9_TIMEOUT_INT      25
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH9_TIMEOUT_INT      0x02000000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH10_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch10 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch10 buffer and
 * then read HSI Status register to find the further status of the Rx ch10 Buffer. The host driver
 * has to read the Rx ch10 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH10_TIMEOUT_INT      26
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH10_TIMEOUT_INT      0x04000000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH11_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch11 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch11 buffer and
 * then read HSI Status register to find the further status of the Rx ch11 Buffer. The host driver
 * has to read the Rx ch11 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH11_TIMEOUT_INT      27
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH11_TIMEOUT_INT      0x08000000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH12_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch12 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch12 buffer and
 * then read HSI Status register to find the further status of the Rx ch12 Buffer. The host driver
 * has to read the Rx ch12 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH12_TIMEOUT_INT      28
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH12_TIMEOUT_INT      0x10000000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH13_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch13 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch13 buffer and
 * then read HSI Status register to find the further status of the Rx ch13 Buffer. The host driver
 * has to read the Rx ch13 fifo on Dword basis, till thefifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH13_TIMEOUT_INT      29
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH13_TIMEOUT_INT      0x20000000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH14_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch14 reaches the data timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch14 buffer and
 * then read HSI Status register to find the further status of the Rx ch14 Buffer. The host driver
 * has to read the Rx ch14 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH14_TIMEOUT_INT      30
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH14_TIMEOUT_INT      0x40000000

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT, field RX_CH15_TIMEOUT_INT (RO)
 *
 * This status bit is set when data timeout counter for ch15 reaches thedata timeout counter value.
 * On receiving the interrupt the host driver should read 1Dword of data from Rx ch15 buffer and
 * then read HSI Status register to find the further status of the Rx ch15 Buffer. The host driver
 * has to read the Rx ch15 fifo on Dword basis, till the fifo is completely empty.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_RX_CH15_TIMEOUT_INT      31
#define BM_MIPI_HSI_ERR_IRQSTAT_RX_CH15_TIMEOUT_INT      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_ERR_IRQSTAT_EN - HSI Error Interrupt Status Enable Register (RW)
 *
 * This register contains the HSI controller Error Interrupt Status Enable.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED : 16; //!< Reserved, always set to zero.
        unsigned RX_CH0_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH1_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH2_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH3_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH4_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH5_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH6_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH7_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH8_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH9_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH10_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH11_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH12_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH13_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH14_TIMEOUT_INT_EN : 1; //!< 
        unsigned RX_CH15_TIMEOUT_INT_EN : 1; //!< 
    } B;
} hw_mipi_hsi_err_irqstat_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_ERR_IRQSTAT_EN register
 */
#define HW_MIPI_HSI_ERR_IRQSTAT_EN_ADDR      (REGS_MIPI_HSI_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_ERR_IRQSTAT_EN           (*(volatile hw_mipi_hsi_err_irqstat_en_t *) HW_MIPI_HSI_ERR_IRQSTAT_EN_ADDR)
#define HW_MIPI_HSI_ERR_IRQSTAT_EN_RD()      (HW_MIPI_HSI_ERR_IRQSTAT_EN.U)
#define HW_MIPI_HSI_ERR_IRQSTAT_EN_WR(v)     (HW_MIPI_HSI_ERR_IRQSTAT_EN.U = (v))
#define HW_MIPI_HSI_ERR_IRQSTAT_EN_SET(v)    (HW_MIPI_HSI_ERR_IRQSTAT_EN_WR(HW_MIPI_HSI_ERR_IRQSTAT_EN_RD() |  (v)))
#define HW_MIPI_HSI_ERR_IRQSTAT_EN_CLR(v)    (HW_MIPI_HSI_ERR_IRQSTAT_EN_WR(HW_MIPI_HSI_ERR_IRQSTAT_EN_RD() & ~(v)))
#define HW_MIPI_HSI_ERR_IRQSTAT_EN_TOG(v)    (HW_MIPI_HSI_ERR_IRQSTAT_EN_WR(HW_MIPI_HSI_ERR_IRQSTAT_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_ERR_IRQSTAT_EN bitfields
 */

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RESERVED      0
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RESERVED      0x0000ffff

/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH0_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch0 interrupt.
 * 0 - Interrupt status masked for data timeout for ch0 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH0_TIMEOUT_INT_EN      16
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH0_TIMEOUT_INT_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH0_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH0_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH0_TIMEOUT_INT_EN(v)   (((v) << 16) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH0_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH0_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH0_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH0_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH1_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch1 interrupt.
 * 0 - Interrupt status masked for data timeout for ch1 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH1_TIMEOUT_INT_EN      17
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH1_TIMEOUT_INT_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH1_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH1_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH1_TIMEOUT_INT_EN(v)   (((v) << 17) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH1_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH1_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH1_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH1_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH2_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch2 interrupt.
 * 0 - Interrupt status masked for data timeout for ch2 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH2_TIMEOUT_INT_EN      18
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH2_TIMEOUT_INT_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH2_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH2_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH2_TIMEOUT_INT_EN(v)   (((v) << 18) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH2_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH2_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH2_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH2_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH3_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch3 interrupt.
 * 0 - Interrupt status masked for data timeout for ch3 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH3_TIMEOUT_INT_EN      19
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH3_TIMEOUT_INT_EN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH3_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH3_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH3_TIMEOUT_INT_EN(v)   (((v) << 19) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH3_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH3_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH3_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH3_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH4_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch4 interrupt.
 * 0 - Interrupt status masked for data timeout for ch4 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH4_TIMEOUT_INT_EN      20
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH4_TIMEOUT_INT_EN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH4_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH4_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH4_TIMEOUT_INT_EN(v)   (((v) << 20) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH4_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH4_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH4_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH4_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH5_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch5 interrupt.
 * 0 - Interrupt status masked for data timeout for ch5 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH5_TIMEOUT_INT_EN      21
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH5_TIMEOUT_INT_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH5_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH5_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH5_TIMEOUT_INT_EN(v)   (((v) << 21) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH5_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH5_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH5_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH5_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH6_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch6 interrupt.
 * 0 - Interrupt status masked for data timeout for ch6 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH6_TIMEOUT_INT_EN      22
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH6_TIMEOUT_INT_EN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH6_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH6_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH6_TIMEOUT_INT_EN(v)   (((v) << 22) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH6_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH6_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH6_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH6_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH7_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch7 interrupt.
 * 0 - Interrupt status masked for data timeout for ch7 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH7_TIMEOUT_INT_EN      23
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH7_TIMEOUT_INT_EN      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH7_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH7_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH7_TIMEOUT_INT_EN(v)   (((v) << 23) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH7_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH7_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH7_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH7_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH8_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch8 interrupt.
 * 0 - Interrupt status masked for data timeout for ch8 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH8_TIMEOUT_INT_EN      24
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH8_TIMEOUT_INT_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH8_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH8_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH8_TIMEOUT_INT_EN(v)   (((v) << 24) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH8_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH8_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH8_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH8_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH9_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch9 interrupt.
 * 0 - Interrupt status masked for data timeout for ch9 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH9_TIMEOUT_INT_EN      25
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH9_TIMEOUT_INT_EN      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH9_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH9_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH9_TIMEOUT_INT_EN(v)   (((v) << 25) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH9_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH9_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH9_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH9_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH10_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch10 interrupt.
 * 0 - Interrupt status masked for data timeout for ch10 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH10_TIMEOUT_INT_EN      26
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH10_TIMEOUT_INT_EN      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH10_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH10_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH10_TIMEOUT_INT_EN(v)   (((v) << 26) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH10_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH10_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH10_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH10_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH11_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch11 interrupt.
 * 0 - Interrupt status masked for data timeout for ch11 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH11_TIMEOUT_INT_EN      27
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH11_TIMEOUT_INT_EN      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH11_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH11_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH11_TIMEOUT_INT_EN(v)   (((v) << 27) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH11_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH11_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH11_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH11_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH12_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch12 interrupt.
 * 0 - Interrupt status masked for data timeout for ch12 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH12_TIMEOUT_INT_EN      28
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH12_TIMEOUT_INT_EN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH12_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH12_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH12_TIMEOUT_INT_EN(v)   (((v) << 28) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH12_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH12_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH12_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH12_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH13_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch13 interrupt.
 * 0 - Interrupt status masked for data timeout for ch13 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH13_TIMEOUT_INT_EN      29
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH13_TIMEOUT_INT_EN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH13_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH13_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH13_TIMEOUT_INT_EN(v)   (((v) << 29) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH13_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH13_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH13_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH13_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH14_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch14 interrupt.
 * 0 - Interrupt status masked for data timeout for ch14 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH14_TIMEOUT_INT_EN      30
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH14_TIMEOUT_INT_EN      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH14_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH14_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH14_TIMEOUT_INT_EN(v)   (((v) << 30) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH14_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH14_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH14_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH14_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSTAT_EN, field RX_CH15_TIMEOUT_INT_EN (RW)
 *

 *
 * Values:
 * 1 - Interrupt status enabled for data timeout for ch15 interrupt.
 * 0 - Interrupt status masked for data timeout for ch15 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH15_TIMEOUT_INT_EN      31
#define BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH15_TIMEOUT_INT_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH15_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH15_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH15_TIMEOUT_INT_EN(v)   (((v) << 31) & BM_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH15_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH15_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSTAT_EN_RX_CH15_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSTAT_EN, RX_CH15_TIMEOUT_INT_EN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_ERR_IRQSIG_EN - HSI Error Interrupt Signal Enable Register (RW)
 *
 * This register contains the HSI controller Error Interrupt Signal Enable.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED : 16; //!< Reserved, always set to zero.
        unsigned RX_CH0_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH1_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH2_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH3_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH4_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH5_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH6_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH7_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH8_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH9_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH10_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH11_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH12_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH13_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH14_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
        unsigned RX_CH15_TIMEOUT_INT_EN : 1; //!< Setting this bit will enable interrupt generation on interrupt line.
    } B;
} hw_mipi_hsi_err_irqsig_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_ERR_IRQSIG_EN register
 */
#define HW_MIPI_HSI_ERR_IRQSIG_EN_ADDR      (REGS_MIPI_HSI_BASE + 0xd8)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_ERR_IRQSIG_EN           (*(volatile hw_mipi_hsi_err_irqsig_en_t *) HW_MIPI_HSI_ERR_IRQSIG_EN_ADDR)
#define HW_MIPI_HSI_ERR_IRQSIG_EN_RD()      (HW_MIPI_HSI_ERR_IRQSIG_EN.U)
#define HW_MIPI_HSI_ERR_IRQSIG_EN_WR(v)     (HW_MIPI_HSI_ERR_IRQSIG_EN.U = (v))
#define HW_MIPI_HSI_ERR_IRQSIG_EN_SET(v)    (HW_MIPI_HSI_ERR_IRQSIG_EN_WR(HW_MIPI_HSI_ERR_IRQSIG_EN_RD() |  (v)))
#define HW_MIPI_HSI_ERR_IRQSIG_EN_CLR(v)    (HW_MIPI_HSI_ERR_IRQSIG_EN_WR(HW_MIPI_HSI_ERR_IRQSIG_EN_RD() & ~(v)))
#define HW_MIPI_HSI_ERR_IRQSIG_EN_TOG(v)    (HW_MIPI_HSI_ERR_IRQSIG_EN_WR(HW_MIPI_HSI_ERR_IRQSIG_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_ERR_IRQSIG_EN bitfields
 */

/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RESERVED      0
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RESERVED      0x0000ffff

/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH0_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch0 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch0 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH0_TIMEOUT_INT_EN      16
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH0_TIMEOUT_INT_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH0_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH0_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH0_TIMEOUT_INT_EN(v)   (((v) << 16) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH0_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH0_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH0_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH0_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH1_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch1 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch1interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH1_TIMEOUT_INT_EN      17
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH1_TIMEOUT_INT_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH1_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH1_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH1_TIMEOUT_INT_EN(v)   (((v) << 17) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH1_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH1_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH1_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH1_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH2_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch2 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch2 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH2_TIMEOUT_INT_EN      18
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH2_TIMEOUT_INT_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH2_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH2_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH2_TIMEOUT_INT_EN(v)   (((v) << 18) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH2_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH2_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH2_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH2_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH3_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch3 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch3 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH3_TIMEOUT_INT_EN      19
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH3_TIMEOUT_INT_EN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH3_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH3_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH3_TIMEOUT_INT_EN(v)   (((v) << 19) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH3_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH3_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH3_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH3_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH4_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch4 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch4 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH4_TIMEOUT_INT_EN      20
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH4_TIMEOUT_INT_EN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH4_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH4_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH4_TIMEOUT_INT_EN(v)   (((v) << 20) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH4_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH4_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH4_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH4_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH5_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch5 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch5 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH5_TIMEOUT_INT_EN      21
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH5_TIMEOUT_INT_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH5_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH5_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH5_TIMEOUT_INT_EN(v)   (((v) << 21) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH5_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH5_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH5_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH5_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH6_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch6 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch6 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH6_TIMEOUT_INT_EN      22
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH6_TIMEOUT_INT_EN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH6_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH6_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH6_TIMEOUT_INT_EN(v)   (((v) << 22) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH6_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH6_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH6_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH6_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH7_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch7 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch7 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH7_TIMEOUT_INT_EN      23
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH7_TIMEOUT_INT_EN      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH7_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH7_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH7_TIMEOUT_INT_EN(v)   (((v) << 23) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH7_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH7_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH7_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH7_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH8_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch8 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch8 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH8_TIMEOUT_INT_EN      24
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH8_TIMEOUT_INT_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH8_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH8_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH8_TIMEOUT_INT_EN(v)   (((v) << 24) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH8_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH8_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH8_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH8_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH9_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch9 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch9 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH9_TIMEOUT_INT_EN      25
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH9_TIMEOUT_INT_EN      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH9_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH9_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH9_TIMEOUT_INT_EN(v)   (((v) << 25) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH9_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH9_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH9_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH9_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH10_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch10 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch10 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH10_TIMEOUT_INT_EN      26
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH10_TIMEOUT_INT_EN      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH10_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH10_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH10_TIMEOUT_INT_EN(v)   (((v) << 26) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH10_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH10_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH10_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH10_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH11_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch11 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch11 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH11_TIMEOUT_INT_EN      27
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH11_TIMEOUT_INT_EN      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH11_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH11_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH11_TIMEOUT_INT_EN(v)   (((v) << 27) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH11_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH11_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH11_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH11_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH12_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch12 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch12 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH12_TIMEOUT_INT_EN      28
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH12_TIMEOUT_INT_EN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH12_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH12_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH12_TIMEOUT_INT_EN(v)   (((v) << 28) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH12_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH12_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH12_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH12_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH13_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch13 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch13 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH13_TIMEOUT_INT_EN      29
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH13_TIMEOUT_INT_EN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH13_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH13_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH13_TIMEOUT_INT_EN(v)   (((v) << 29) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH13_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH13_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH13_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH13_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH14_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch14 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch14 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH14_TIMEOUT_INT_EN      30
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH14_TIMEOUT_INT_EN      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH14_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH14_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH14_TIMEOUT_INT_EN(v)   (((v) << 30) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH14_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH14_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH14_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH14_TIMEOUT_INT_EN, v)
#endif


/* --- Register HW_MIPI_HSI_ERR_IRQSIG_EN, field RX_CH15_TIMEOUT_INT_EN (RW)
 *
 * Setting this bit will enable interrupt generation on interrupt line.
 *
 * Values:
 * 1 - Interrupt signal enabled for data timeout for ch15 interrupt.
 * 0 - Interrupt signal masked for data timeout for ch15 interrupt.
 */

#define BP_MIPI_HSI_ERR_IRQSIG_EN_RX_CH15_TIMEOUT_INT_EN      31
#define BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH15_TIMEOUT_INT_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH15_TIMEOUT_INT_EN(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH15_TIMEOUT_INT_EN)
#else
#define BF_MIPI_HSI_ERR_IRQSIG_EN_RX_CH15_TIMEOUT_INT_EN(v)   (((v) << 31) & BM_MIPI_HSI_ERR_IRQSIG_EN_RX_CH15_TIMEOUT_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CH15_TIMEOUT_INT_EN field to a new value.
#define BW_MIPI_HSI_ERR_IRQSIG_EN_RX_CH15_TIMEOUT_INT_EN(v)   BF_CS1(MIPI_HSI_ERR_IRQSIG_EN, RX_CH15_TIMEOUT_INT_EN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TDMA_CONF - Tx DMA Channel n Configuration Register (RW)
 *
 * This register contains the configurations of enable/disable, burst size and transfer count for Tx
 * DMA channel n.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned TRANS_LENGTH : 20; //!< Transfer data length for Tx DMA channel n. The unit is Dword. h1 1Dword to transfer h2 2Dwords to transfer hfffff 1048575Dwords to transfer
        unsigned BURST_SIZE : 4; //!< Burst size for Tx DMA channel n. The unit is Dword. The burst size should not be larger than relevant TRANS_LENGTH and FIFO_SIZE. h0 1Dword to transfer for each burst h1 2Dword to transfer for each burst h2 4Dword to transfer for each burst h10 1024Dword to transfer for each burst
        unsigned RESERVED1 : 2; //!< Reserved, always set to zero.
        unsigned ENABLE : 1; //!< Setting this bit enables the inernal Tx DMA channel n.
    } B;
} hw_mipi_hsi_tdma_conf_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TDMA_CONF register
 */
#define HW_MIPI_HSI_TDMA_CONF_ADDR      (REGS_MIPI_HSI_BASE + 0xdc)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TDMA_CONF           (*(volatile hw_mipi_hsi_tdma_conf_t *) HW_MIPI_HSI_TDMA_CONF_ADDR)
#define HW_MIPI_HSI_TDMA_CONF_RD()      (HW_MIPI_HSI_TDMA_CONF.U)
#define HW_MIPI_HSI_TDMA_CONF_WR(v)     (HW_MIPI_HSI_TDMA_CONF.U = (v))
#define HW_MIPI_HSI_TDMA_CONF_SET(v)    (HW_MIPI_HSI_TDMA_CONF_WR(HW_MIPI_HSI_TDMA_CONF_RD() |  (v)))
#define HW_MIPI_HSI_TDMA_CONF_CLR(v)    (HW_MIPI_HSI_TDMA_CONF_WR(HW_MIPI_HSI_TDMA_CONF_RD() & ~(v)))
#define HW_MIPI_HSI_TDMA_CONF_TOG(v)    (HW_MIPI_HSI_TDMA_CONF_WR(HW_MIPI_HSI_TDMA_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TDMA_CONF bitfields
 */

/* --- Register HW_MIPI_HSI_TDMA_CONF, field TRANS_LENGTH (RW)
 *
 * Transfer data length for Tx DMA channel n. The unit is Dword. h1 1Dword to transfer h2 2Dwords to
 * transfer hfffff 1048575Dwords to transfer
 */

#define BP_MIPI_HSI_TDMA_CONF_TRANS_LENGTH      5
#define BM_MIPI_HSI_TDMA_CONF_TRANS_LENGTH      0x01ffffe0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TDMA_CONF_TRANS_LENGTH(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_TDMA_CONF_TRANS_LENGTH)
#else
#define BF_MIPI_HSI_TDMA_CONF_TRANS_LENGTH(v)   (((v) << 5) & BM_MIPI_HSI_TDMA_CONF_TRANS_LENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TRANS_LENGTH field to a new value.
#define BW_MIPI_HSI_TDMA_CONF_TRANS_LENGTH(v)   BF_CS1(MIPI_HSI_TDMA_CONF, TRANS_LENGTH, v)
#endif

/* --- Register HW_MIPI_HSI_TDMA_CONF, field BURST_SIZE (RW)
 *
 * Burst size for Tx DMA channel n. The unit is Dword. The burst size should not be larger than
 * relevant TRANS_LENGTH and FIFO_SIZE. h0 1Dword to transfer for each burst h1 2Dword to transfer
 * for each burst h2 4Dword to transfer for each burst h10 1024Dword to transfer for each burst
 */

#define BP_MIPI_HSI_TDMA_CONF_BURST_SIZE      25
#define BM_MIPI_HSI_TDMA_CONF_BURST_SIZE      0x1e000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TDMA_CONF_BURST_SIZE(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_TDMA_CONF_BURST_SIZE)
#else
#define BF_MIPI_HSI_TDMA_CONF_BURST_SIZE(v)   (((v) << 25) & BM_MIPI_HSI_TDMA_CONF_BURST_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BURST_SIZE field to a new value.
#define BW_MIPI_HSI_TDMA_CONF_BURST_SIZE(v)   BF_CS1(MIPI_HSI_TDMA_CONF, BURST_SIZE, v)
#endif

/* --- Register HW_MIPI_HSI_TDMA_CONF, field ENABLE (RW)
 *
 * Setting this bit enables the inernal Tx DMA channel n.
 */

#define BP_MIPI_HSI_TDMA_CONF_ENABLE      31
#define BM_MIPI_HSI_TDMA_CONF_ENABLE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TDMA_CONF_ENABLE(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_TDMA_CONF_ENABLE)
#else
#define BF_MIPI_HSI_TDMA_CONF_ENABLE(v)   (((v) << 31) & BM_MIPI_HSI_TDMA_CONF_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_MIPI_HSI_TDMA_CONF_ENABLE(v)   BF_CS1(MIPI_HSI_TDMA_CONF, ENABLE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_RDMA_CONF - Rx DMA Channel n Configuration Register (RW)
 *
 * This register contains the configurations of enable/disable, burst size and transfer count for Rx
 * DMA channel n.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned TRANS_LENGTH : 20; //!< Transfer data length for Rx DMA channel 0. The unit is Dword. h1 1Dword to transfer h2 2Dwords to transfer hfffff 1048575Dwords to transfer
        unsigned BURST_SIZE : 4; //!< Burst size for Rx DMA channel n. The unit is Dword. The burst size should not be larger than relevant TRANS_LENGTH and FIFO_SIZE. h0 1Dword to transfer for each burst h1 2Dword to transfer for each burst h2 4Dword to transfer for each burst h10 1024Dword to transfer for each burst
        unsigned RESERVED1 : 2; //!< Reserved, always set to zero.
        unsigned ENABLE : 1; //!< Setting this bit enables the inernal Rx DMA channel n.
    } B;
} hw_mipi_hsi_rdma_conf_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_RDMA_CONF register
 */
#define HW_MIPI_HSI_RDMA_CONF_ADDR      (REGS_MIPI_HSI_BASE + 0x11c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_RDMA_CONF           (*(volatile hw_mipi_hsi_rdma_conf_t *) HW_MIPI_HSI_RDMA_CONF_ADDR)
#define HW_MIPI_HSI_RDMA_CONF_RD()      (HW_MIPI_HSI_RDMA_CONF.U)
#define HW_MIPI_HSI_RDMA_CONF_WR(v)     (HW_MIPI_HSI_RDMA_CONF.U = (v))
#define HW_MIPI_HSI_RDMA_CONF_SET(v)    (HW_MIPI_HSI_RDMA_CONF_WR(HW_MIPI_HSI_RDMA_CONF_RD() |  (v)))
#define HW_MIPI_HSI_RDMA_CONF_CLR(v)    (HW_MIPI_HSI_RDMA_CONF_WR(HW_MIPI_HSI_RDMA_CONF_RD() & ~(v)))
#define HW_MIPI_HSI_RDMA_CONF_TOG(v)    (HW_MIPI_HSI_RDMA_CONF_WR(HW_MIPI_HSI_RDMA_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_RDMA_CONF bitfields
 */

/* --- Register HW_MIPI_HSI_RDMA_CONF, field TRANS_LENGTH (RW)
 *
 * Transfer data length for Rx DMA channel 0. The unit is Dword. h1 1Dword to transfer h2 2Dwords to
 * transfer hfffff 1048575Dwords to transfer
 */

#define BP_MIPI_HSI_RDMA_CONF_TRANS_LENGTH      5
#define BM_MIPI_HSI_RDMA_CONF_TRANS_LENGTH      0x01ffffe0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RDMA_CONF_TRANS_LENGTH(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_RDMA_CONF_TRANS_LENGTH)
#else
#define BF_MIPI_HSI_RDMA_CONF_TRANS_LENGTH(v)   (((v) << 5) & BM_MIPI_HSI_RDMA_CONF_TRANS_LENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TRANS_LENGTH field to a new value.
#define BW_MIPI_HSI_RDMA_CONF_TRANS_LENGTH(v)   BF_CS1(MIPI_HSI_RDMA_CONF, TRANS_LENGTH, v)
#endif

/* --- Register HW_MIPI_HSI_RDMA_CONF, field BURST_SIZE (RW)
 *
 * Burst size for Rx DMA channel n. The unit is Dword. The burst size should not be larger than
 * relevant TRANS_LENGTH and FIFO_SIZE. h0 1Dword to transfer for each burst h1 2Dword to transfer
 * for each burst h2 4Dword to transfer for each burst h10 1024Dword to transfer for each burst
 */

#define BP_MIPI_HSI_RDMA_CONF_BURST_SIZE      25
#define BM_MIPI_HSI_RDMA_CONF_BURST_SIZE      0x1e000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RDMA_CONF_BURST_SIZE(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_RDMA_CONF_BURST_SIZE)
#else
#define BF_MIPI_HSI_RDMA_CONF_BURST_SIZE(v)   (((v) << 25) & BM_MIPI_HSI_RDMA_CONF_BURST_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BURST_SIZE field to a new value.
#define BW_MIPI_HSI_RDMA_CONF_BURST_SIZE(v)   BF_CS1(MIPI_HSI_RDMA_CONF, BURST_SIZE, v)
#endif

/* --- Register HW_MIPI_HSI_RDMA_CONF, field ENABLE (RW)
 *
 * Setting this bit enables the inernal Rx DMA channel n.
 */

#define BP_MIPI_HSI_RDMA_CONF_ENABLE      31
#define BM_MIPI_HSI_RDMA_CONF_ENABLE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RDMA_CONF_ENABLE(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_RDMA_CONF_ENABLE)
#else
#define BF_MIPI_HSI_RDMA_CONF_ENABLE(v)   (((v) << 31) & BM_MIPI_HSI_RDMA_CONF_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_MIPI_HSI_RDMA_CONF_ENABLE(v)   BF_CS1(MIPI_HSI_RDMA_CONF, ENABLE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TDMA_STA_ADDR - Tx DMA Channel n Start Address Register (RW)
 *
 * This Register containts the physical Start Address HSI for Tx DMA Channel n.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned DS_ADDR : 30; //!< The Physical Start Address for Tx DMA Channel n. DWord aligned
    } B;
} hw_mipi_hsi_tdma_sta_addr_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TDMA_STA_ADDR register
 */
#define HW_MIPI_HSI_TDMA_STA_ADDR_ADDR      (REGS_MIPI_HSI_BASE + 0x15c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TDMA_STA_ADDR           (*(volatile hw_mipi_hsi_tdma_sta_addr_t *) HW_MIPI_HSI_TDMA_STA_ADDR_ADDR)
#define HW_MIPI_HSI_TDMA_STA_ADDR_RD()      (HW_MIPI_HSI_TDMA_STA_ADDR.U)
#define HW_MIPI_HSI_TDMA_STA_ADDR_WR(v)     (HW_MIPI_HSI_TDMA_STA_ADDR.U = (v))
#define HW_MIPI_HSI_TDMA_STA_ADDR_SET(v)    (HW_MIPI_HSI_TDMA_STA_ADDR_WR(HW_MIPI_HSI_TDMA_STA_ADDR_RD() |  (v)))
#define HW_MIPI_HSI_TDMA_STA_ADDR_CLR(v)    (HW_MIPI_HSI_TDMA_STA_ADDR_WR(HW_MIPI_HSI_TDMA_STA_ADDR_RD() & ~(v)))
#define HW_MIPI_HSI_TDMA_STA_ADDR_TOG(v)    (HW_MIPI_HSI_TDMA_STA_ADDR_WR(HW_MIPI_HSI_TDMA_STA_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TDMA_STA_ADDR bitfields
 */

/* --- Register HW_MIPI_HSI_TDMA_STA_ADDR, field DS_ADDR (RW)
 *
 * The Physical Start Address for Tx DMA Channel n. DWord aligned
 */

#define BP_MIPI_HSI_TDMA_STA_ADDR_DS_ADDR      2
#define BM_MIPI_HSI_TDMA_STA_ADDR_DS_ADDR      0xfffffffc

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TDMA_STA_ADDR_DS_ADDR(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_TDMA_STA_ADDR_DS_ADDR)
#else
#define BF_MIPI_HSI_TDMA_STA_ADDR_DS_ADDR(v)   (((v) << 2) & BM_MIPI_HSI_TDMA_STA_ADDR_DS_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DS_ADDR field to a new value.
#define BW_MIPI_HSI_TDMA_STA_ADDR_DS_ADDR(v)   BF_CS1(MIPI_HSI_TDMA_STA_ADDR, DS_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_RDMA_STA_ADDR - Rx DMA Channel n Start Address Register (RW)
 *
 * This Register containts the physical Start Address HSI for Rx DMA Channel n.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned DS_ADDR : 30; //!< The Physical Start Address for Rx DMA Channel n. DWord aligned
    } B;
} hw_mipi_hsi_rdma_sta_addr_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_RDMA_STA_ADDR register
 */
#define HW_MIPI_HSI_RDMA_STA_ADDR_ADDR      (REGS_MIPI_HSI_BASE + 0x19c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_RDMA_STA_ADDR           (*(volatile hw_mipi_hsi_rdma_sta_addr_t *) HW_MIPI_HSI_RDMA_STA_ADDR_ADDR)
#define HW_MIPI_HSI_RDMA_STA_ADDR_RD()      (HW_MIPI_HSI_RDMA_STA_ADDR.U)
#define HW_MIPI_HSI_RDMA_STA_ADDR_WR(v)     (HW_MIPI_HSI_RDMA_STA_ADDR.U = (v))
#define HW_MIPI_HSI_RDMA_STA_ADDR_SET(v)    (HW_MIPI_HSI_RDMA_STA_ADDR_WR(HW_MIPI_HSI_RDMA_STA_ADDR_RD() |  (v)))
#define HW_MIPI_HSI_RDMA_STA_ADDR_CLR(v)    (HW_MIPI_HSI_RDMA_STA_ADDR_WR(HW_MIPI_HSI_RDMA_STA_ADDR_RD() & ~(v)))
#define HW_MIPI_HSI_RDMA_STA_ADDR_TOG(v)    (HW_MIPI_HSI_RDMA_STA_ADDR_WR(HW_MIPI_HSI_RDMA_STA_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_RDMA_STA_ADDR bitfields
 */

/* --- Register HW_MIPI_HSI_RDMA_STA_ADDR, field DS_ADDR (RW)
 *
 * The Physical Start Address for Rx DMA Channel n. DWord aligned
 */

#define BP_MIPI_HSI_RDMA_STA_ADDR_DS_ADDR      2
#define BM_MIPI_HSI_RDMA_STA_ADDR_DS_ADDR      0xfffffffc

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RDMA_STA_ADDR_DS_ADDR(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_RDMA_STA_ADDR_DS_ADDR)
#else
#define BF_MIPI_HSI_RDMA_STA_ADDR_DS_ADDR(v)   (((v) << 2) & BM_MIPI_HSI_RDMA_STA_ADDR_DS_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DS_ADDR field to a new value.
#define BW_MIPI_HSI_RDMA_STA_ADDR_DS_ADDR(v)   BF_CS1(MIPI_HSI_RDMA_STA_ADDR, DS_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_DMA_IRQSTAT - DMA Interrupt Status Register (RO)
 *
 * This register contains all the interrupt status for HSI internal DMA
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RDMA0 : 1; //!< RDMA Channel 0 interrupt status
        unsigned RDMA1 : 1; //!< RDMA Channel 1 interrupt status
        unsigned RDMA2 : 1; //!< RDMA Channel 2 interrupt status
        unsigned RDMA3 : 1; //!< RDMA Channel 3 interrupt status
        unsigned RDMA4 : 1; //!< RDMA Channel 4 interrupt status
        unsigned RDMA5 : 1; //!< RDMA Channel 5 interrupt status
        unsigned RDMA6 : 1; //!< RDMA Channel 6 interrupt status
        unsigned RDMA7 : 1; //!< RDMA Channel 7 interrupt status
        unsigned RDMA8 : 1; //!< RDMA Channel 8 interrupt status
        unsigned RDMA9 : 1; //!< RDMA Channel 9 interrupt status
        unsigned RDMA10 : 1; //!< RDMA Channel 10 interrupt status
        unsigned RDMA11 : 1; //!< RDMA Channel 11 interrupt status
        unsigned RDMA12 : 1; //!< RDMA Channel 12 interrupt status
        unsigned RDMA13 : 1; //!< RDMA Channel 13 interrupt status
        unsigned RDMA14 : 1; //!< RDMA Channel 14 interrupt status
        unsigned RDMA15 : 1; //!< RDMA Channel 15 interrupt status
        unsigned TDMA0 : 1; //!< TDMA Channel 0 interrupt status
        unsigned TDMA1 : 1; //!< TDMA Channel 1 interrupt status
        unsigned TDMA2 : 1; //!< TDMA Channel 2 interrupt status
        unsigned TDMA3 : 1; //!< TDMA Channel 3 interrupt status
        unsigned TDMA4 : 1; //!< TDMA Channel 4 interrupt status
        unsigned TDMA5 : 1; //!< TDMA Channel 5 interrupt status
        unsigned TDMA6 : 1; //!< TDMA Channel 6 interrupt status
        unsigned TDMA7 : 1; //!< TDMA Channel 7 interrupt status
        unsigned TDMA8 : 1; //!< TDMA Channel 8 interrupt status
        unsigned TDMA9 : 1; //!< TDMA Channel 9 interrupt status
        unsigned TDMA10 : 1; //!< TDMA Channel 10 interrupt status
        unsigned TDMA11 : 1; //!< TDMA Channel 11 interrupt status
        unsigned TDMA12 : 1; //!< TDMA Channel 12 interrupt status
        unsigned TDMA13 : 1; //!< TDMA Channel 13 interrupt status
        unsigned TDMA14 : 1; //!< TDMA Channel 14 interrupt status
        unsigned TDMA15 : 1; //!< TDMA Channel 15 interrupt status
    } B;
} hw_mipi_hsi_dma_irqstat_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_DMA_IRQSTAT register
 */
#define HW_MIPI_HSI_DMA_IRQSTAT_ADDR      (REGS_MIPI_HSI_BASE + 0x1dc)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_DMA_IRQSTAT           (*(volatile hw_mipi_hsi_dma_irqstat_t *) HW_MIPI_HSI_DMA_IRQSTAT_ADDR)
#define HW_MIPI_HSI_DMA_IRQSTAT_RD()      (HW_MIPI_HSI_DMA_IRQSTAT.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_DMA_IRQSTAT bitfields
 */

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA0 (RO)
 *
 * RDMA Channel 0 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA0      0
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA0      0x00000001

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA1 (RO)
 *
 * RDMA Channel 1 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA1      1
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA1      0x00000002

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA2 (RO)
 *
 * RDMA Channel 2 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA2      2
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA2      0x00000004

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA3 (RO)
 *
 * RDMA Channel 3 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA3      3
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA3      0x00000008

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA4 (RO)
 *
 * RDMA Channel 4 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA4      4
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA4      0x00000010

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA5 (RO)
 *
 * RDMA Channel 5 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA5      5
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA5      0x00000020

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA6 (RO)
 *
 * RDMA Channel 6 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA6      6
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA6      0x00000040

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA7 (RO)
 *
 * RDMA Channel 7 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA7      7
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA7      0x00000080

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA8 (RO)
 *
 * RDMA Channel 8 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA8      8
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA8      0x00000100

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA9 (RO)
 *
 * RDMA Channel 9 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA9      9
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA9      0x00000200

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA10 (RO)
 *
 * RDMA Channel 10 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA10      10
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA10      0x00000400

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA11 (RO)
 *
 * RDMA Channel 11 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA11      11
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA11      0x00000800

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA12 (RO)
 *
 * RDMA Channel 12 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA12      12
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA12      0x00001000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA13 (RO)
 *
 * RDMA Channel 13 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA13      13
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA13      0x00002000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA14 (RO)
 *
 * RDMA Channel 14 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA14      14
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA14      0x00004000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field RDMA15 (RO)
 *
 * RDMA Channel 15 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_RDMA15      15
#define BM_MIPI_HSI_DMA_IRQSTAT_RDMA15      0x00008000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA0 (RO)
 *
 * TDMA Channel 0 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA0      16
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA0      0x00010000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA1 (RO)
 *
 * TDMA Channel 1 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA1      17
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA1      0x00020000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA2 (RO)
 *
 * TDMA Channel 2 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA2      18
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA2      0x00040000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA3 (RO)
 *
 * TDMA Channel 3 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA3      19
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA3      0x00080000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA4 (RO)
 *
 * TDMA Channel 4 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA4      20
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA4      0x00100000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA5 (RO)
 *
 * TDMA Channel 5 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA5      21
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA5      0x00200000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA6 (RO)
 *
 * TDMA Channel 6 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA6      22
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA6      0x00400000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA7 (RO)
 *
 * TDMA Channel 7 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA7      23
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA7      0x00800000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA8 (RO)
 *
 * TDMA Channel 8 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA8      24
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA8      0x01000000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA9 (RO)
 *
 * TDMA Channel 9 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA9      25
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA9      0x02000000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA10 (RO)
 *
 * TDMA Channel 10 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA10      26
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA10      0x04000000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA11 (RO)
 *
 * TDMA Channel 11 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA11      27
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA11      0x08000000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA12 (RO)
 *
 * TDMA Channel 12 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA12      28
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA12      0x10000000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA13 (RO)
 *
 * TDMA Channel 13 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA13      29
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA13      0x20000000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA14 (RO)
 *
 * TDMA Channel 14 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA14      30
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA14      0x40000000

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT, field TDMA15 (RO)
 *
 * TDMA Channel 15 interrupt status
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_TDMA15      31
#define BM_MIPI_HSI_DMA_IRQSTAT_TDMA15      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_DMA_IRQSTAT_EN - DMA Interrupt Enable Register (RW)
 *
 * This Register is used to select which DMA interrupt could send to HIS Interrupt Status Register
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RDMA0 : 1; //!< RDMA Channel 0 interrupt Enable
        unsigned RDMA1 : 1; //!< RDMA Channel 1 interrupt Enable
        unsigned RDMA2 : 1; //!< RDMA Channel 2 interrupt Enable
        unsigned RDMA3 : 1; //!< RDMA Channel 3 interrupt Enable
        unsigned RDMA4 : 1; //!< RDMA Channel 4 interrupt Enable
        unsigned RDMA5 : 1; //!< RDMA Channel 5 interrupt Enable
        unsigned RDMA6 : 1; //!< RDMA Channel 6 interrupt Enable
        unsigned RDMA7 : 1; //!< RDMA Channel 7 interrupt Enable
        unsigned RDMA8 : 1; //!< RDMA Channel 8 interrupt Enable
        unsigned RDMA9 : 1; //!< RDMA Channel 9 interrupt Enable
        unsigned RDMA10 : 1; //!< RDMA Channel 10 interrupt Enable
        unsigned RDMA11 : 1; //!< RDMA Channel 11 interrupt Enable
        unsigned RDMA12 : 1; //!< RDMA Channel 12 interrupt Enable
        unsigned RDMA13 : 1; //!< RDMA Channel 13 interrupt Enable
        unsigned RDMA14 : 1; //!< RDMA Channel 14 interrupt Enable
        unsigned RDMA15 : 1; //!< RDMA Channel 15 interrupt Enable
        unsigned TDMA0 : 1; //!< TDMA Channel 0 interrupt Enable
        unsigned TDMA1 : 1; //!< TDMA Channel 1 interrupt Enable
        unsigned TDMA2 : 1; //!< TDMA Channel 2 interrupt Enable
        unsigned TDMA3 : 1; //!< TDMA Channel 3 interrupt Enable
        unsigned TDMA4 : 1; //!< TDMA Channel 4 interrupt Enable
        unsigned TDMA5 : 1; //!< TDMA Channel 5 interrupt Enable
        unsigned TDMA6 : 1; //!< TDMA Channel 6 interrupt Enable
        unsigned TDMA7 : 1; //!< TDMA Channel 7 interrupt Enable
        unsigned TDMA8 : 1; //!< TDMA Channel 8 interrupt Enable
        unsigned TDMA9 : 1; //!< TDMA Channel 9 interrupt Enable
        unsigned TDMA10 : 1; //!< TDMA Channel 10 interrupt Enable
        unsigned TDMA11 : 1; //!< TDMA Channel 11 interrupt Enable
        unsigned TDMA12 : 1; //!< TDMA Channel 12 interrupt Enable
        unsigned TDMA13 : 1; //!< TDMA Channel 13 interrupt Enable
        unsigned TDMA14 : 1; //!< TDMA Channel 14 interrupt Enable
        unsigned TDMA15 : 1; //!< TDMA Channel 15 interrupt Enable
    } B;
} hw_mipi_hsi_dma_irqstat_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_DMA_IRQSTAT_EN register
 */
#define HW_MIPI_HSI_DMA_IRQSTAT_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x1e0)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_DMA_IRQSTAT_EN           (*(volatile hw_mipi_hsi_dma_irqstat_en_t *) HW_MIPI_HSI_DMA_IRQSTAT_EN_ADDR)
#define HW_MIPI_HSI_DMA_IRQSTAT_EN_RD()      (HW_MIPI_HSI_DMA_IRQSTAT_EN.U)
#define HW_MIPI_HSI_DMA_IRQSTAT_EN_WR(v)     (HW_MIPI_HSI_DMA_IRQSTAT_EN.U = (v))
#define HW_MIPI_HSI_DMA_IRQSTAT_EN_SET(v)    (HW_MIPI_HSI_DMA_IRQSTAT_EN_WR(HW_MIPI_HSI_DMA_IRQSTAT_EN_RD() |  (v)))
#define HW_MIPI_HSI_DMA_IRQSTAT_EN_CLR(v)    (HW_MIPI_HSI_DMA_IRQSTAT_EN_WR(HW_MIPI_HSI_DMA_IRQSTAT_EN_RD() & ~(v)))
#define HW_MIPI_HSI_DMA_IRQSTAT_EN_TOG(v)    (HW_MIPI_HSI_DMA_IRQSTAT_EN_WR(HW_MIPI_HSI_DMA_IRQSTAT_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_DMA_IRQSTAT_EN bitfields
 */

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA0 (RW)
 *
 * RDMA Channel 0 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA0      0
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA0)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA0(v)   (((v) << 0) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA0 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA0(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA0, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA1 (RW)
 *
 * RDMA Channel 1 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA1      1
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA1(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA1)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA1(v)   (((v) << 1) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA1 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA1(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA1, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA2 (RW)
 *
 * RDMA Channel 2 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA2      2
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA2(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA2)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA2(v)   (((v) << 2) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA2 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA2(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA2, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA3 (RW)
 *
 * RDMA Channel 3 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA3      3
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA3(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA3)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA3(v)   (((v) << 3) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA3 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA3(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA3, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA4 (RW)
 *
 * RDMA Channel 4 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA4      4
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA4(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA4)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA4(v)   (((v) << 4) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA4 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA4(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA4, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA5 (RW)
 *
 * RDMA Channel 5 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA5      5
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA5(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA5)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA5(v)   (((v) << 5) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA5 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA5(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA5, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA6 (RW)
 *
 * RDMA Channel 6 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA6      6
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA6(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA6)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA6(v)   (((v) << 6) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA6 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA6(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA6, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA7 (RW)
 *
 * RDMA Channel 7 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA7      7
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA7(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA7)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA7(v)   (((v) << 7) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA7 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA7(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA7, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA8 (RW)
 *
 * RDMA Channel 8 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA8      8
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA8(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA8)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA8(v)   (((v) << 8) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA8 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA8(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA8, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA9 (RW)
 *
 * RDMA Channel 9 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA9      9
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA9(v)   ((((reg32_t) v) << 9) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA9)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA9(v)   (((v) << 9) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA9 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA9(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA9, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA10 (RW)
 *
 * RDMA Channel 10 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA10      10
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA10(v)   ((((reg32_t) v) << 10) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA10)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA10(v)   (((v) << 10) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA10 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA10(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA10, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA11 (RW)
 *
 * RDMA Channel 11 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA11      11
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA11(v)   ((((reg32_t) v) << 11) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA11)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA11(v)   (((v) << 11) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA11 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA11(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA11, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA12 (RW)
 *
 * RDMA Channel 12 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA12      12
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA12(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA12)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA12(v)   (((v) << 12) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA12 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA12(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA12, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA13 (RW)
 *
 * RDMA Channel 13 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA13      13
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA13(v)   ((((reg32_t) v) << 13) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA13)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA13(v)   (((v) << 13) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA13 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA13(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA13, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA14 (RW)
 *
 * RDMA Channel 14 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA14      14
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA14(v)   ((((reg32_t) v) << 14) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA14)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA14(v)   (((v) << 14) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA14 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA14(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA14, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field RDMA15 (RW)
 *
 * RDMA Channel 15 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_RDMA15      15
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA15(v)   ((((reg32_t) v) << 15) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA15)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_RDMA15(v)   (((v) << 15) & BM_MIPI_HSI_DMA_IRQSTAT_EN_RDMA15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA15 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_RDMA15(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, RDMA15, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA0 (RW)
 *
 * TDMA Channel 0 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA0      16
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA0(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA0)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA0(v)   (((v) << 16) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA0 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA0(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA0, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA1 (RW)
 *
 * TDMA Channel 1 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA1      17
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA1(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA1)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA1(v)   (((v) << 17) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA1 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA1(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA1, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA2 (RW)
 *
 * TDMA Channel 2 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA2      18
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA2(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA2)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA2(v)   (((v) << 18) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA2 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA2(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA2, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA3 (RW)
 *
 * TDMA Channel 3 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA3      19
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA3      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA3(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA3)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA3(v)   (((v) << 19) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA3 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA3(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA3, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA4 (RW)
 *
 * TDMA Channel 4 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA4      20
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA4      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA4(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA4)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA4(v)   (((v) << 20) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA4 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA4(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA4, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA5 (RW)
 *
 * TDMA Channel 5 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA5      21
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA5      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA5(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA5)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA5(v)   (((v) << 21) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA5 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA5(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA5, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA6 (RW)
 *
 * TDMA Channel 6 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA6      22
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA6      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA6(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA6)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA6(v)   (((v) << 22) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA6 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA6(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA6, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA7 (RW)
 *
 * TDMA Channel 7 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA7      23
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA7      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA7(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA7)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA7(v)   (((v) << 23) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA7 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA7(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA7, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA8 (RW)
 *
 * TDMA Channel 8 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA8      24
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA8      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA8(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA8)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA8(v)   (((v) << 24) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA8 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA8(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA8, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA9 (RW)
 *
 * TDMA Channel 9 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA9      25
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA9      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA9(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA9)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA9(v)   (((v) << 25) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA9 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA9(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA9, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA10 (RW)
 *
 * TDMA Channel 10 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA10      26
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA10      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA10(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA10)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA10(v)   (((v) << 26) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA10 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA10(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA10, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA11 (RW)
 *
 * TDMA Channel 11 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA11      27
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA11      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA11(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA11)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA11(v)   (((v) << 27) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA11 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA11(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA11, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA12 (RW)
 *
 * TDMA Channel 12 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA12      28
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA12      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA12(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA12)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA12(v)   (((v) << 28) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA12 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA12(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA12, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA13 (RW)
 *
 * TDMA Channel 13 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA13      29
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA13      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA13(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA13)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA13(v)   (((v) << 29) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA13 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA13(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA13, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA14 (RW)
 *
 * TDMA Channel 14 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA14      30
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA14      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA14(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA14)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA14(v)   (((v) << 30) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA14 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA14(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA14, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSTAT_EN, field TDMA15 (RW)
 *
 * TDMA Channel 15 interrupt Enable
 */

#define BP_MIPI_HSI_DMA_IRQSTAT_EN_TDMA15      31
#define BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA15      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA15(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA15)
#else
#define BF_MIPI_HSI_DMA_IRQSTAT_EN_TDMA15(v)   (((v) << 31) & BM_MIPI_HSI_DMA_IRQSTAT_EN_TDMA15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA15 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSTAT_EN_TDMA15(v)   BF_CS1(MIPI_HSI_DMA_IRQSTAT_EN, TDMA15, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_DMA_IRQSIG_EN - DMA Interrupt Status Signal Enable Register (RW)
 *
 * This Register is used to select which DMA interrupt status could send to HIS Interrupt Status
 * Register
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RDMA0 : 1; //!< RDMA Channel 0 interrupt status enable
        unsigned RDMA1 : 1; //!< RDMA Channel 1 interrupt status enable
        unsigned RDMA2 : 1; //!< RDMA Channel 2 interrupt status enable
        unsigned RDMA3 : 1; //!< RDMA Channel 3 interrupt status enable
        unsigned RDMA4 : 1; //!< RDMA Channel 4 interrupt status enable
        unsigned RDMA5 : 1; //!< RDMA Channel 5 interrupt status enable
        unsigned RDMA6 : 1; //!< RDMA Channel 6 interrupt status enable
        unsigned RDMA7 : 1; //!< RDMA Channel 7 interrupt status enable
        unsigned RDMA8 : 1; //!< RDMA Channel 8 interrupt status enable
        unsigned RDMA9 : 1; //!< RDMA Channel 9 interrupt status enable
        unsigned RDMA10 : 1; //!< RDMA Channel 10 interrupt status enable
        unsigned RDMA11 : 1; //!< RDMA Channel 11 interrupt status enable
        unsigned RDMA12 : 1; //!< RDMA Channel 12 interrupt status enable
        unsigned RDMA13 : 1; //!< RDMA Channel 13 interrupt status enable
        unsigned RDMA14 : 1; //!< RDMA Channel 14 interrupt status enable
        unsigned RDMA15 : 1; //!< RDMA Channel 15 interrupt status enable
        unsigned TDMA0 : 1; //!< TDMA Channel 0 interrupt status enable
        unsigned TDMA1 : 1; //!< TDMA Channel 1 interrupt status enable
        unsigned TDMA2 : 1; //!< TDMA Channel 2 interrupt status enable
        unsigned TDMA3 : 1; //!< TDMA Channel 3 interrupt status enable
        unsigned TDMA4 : 1; //!< TDMA Channel 4 interrupt status enable
        unsigned TDMA5 : 1; //!< TDMA Channel 5 interrupt status enable
        unsigned TDMA6 : 1; //!< TDMA Channel 6 interrupt status enable
        unsigned TDMA7 : 1; //!< TDMA Channel 7 interrupt status enable
        unsigned TDMA8 : 1; //!< TDMA Channel 8 interrupt status enable
        unsigned TDMA9 : 1; //!< TDMA Channel 9 interrupt status enable
        unsigned TDMA10 : 1; //!< TDMA Channel 10 interrupt status enable
        unsigned TDMA11 : 1; //!< TDMA Channel 11 interrupt status enable
        unsigned TDMA12 : 1; //!< TDMA Channel 12 interrupt status enable
        unsigned TDMA13 : 1; //!< TDMA Channel 13 interrupt status enable
        unsigned TDMA14 : 1; //!< TDMA Channel 14 interrupt status enable
        unsigned TDMA15 : 1; //!< TDMA Channel 15 interrupt status enable
    } B;
} hw_mipi_hsi_dma_irqsig_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_DMA_IRQSIG_EN register
 */
#define HW_MIPI_HSI_DMA_IRQSIG_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x1e4)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_DMA_IRQSIG_EN           (*(volatile hw_mipi_hsi_dma_irqsig_en_t *) HW_MIPI_HSI_DMA_IRQSIG_EN_ADDR)
#define HW_MIPI_HSI_DMA_IRQSIG_EN_RD()      (HW_MIPI_HSI_DMA_IRQSIG_EN.U)
#define HW_MIPI_HSI_DMA_IRQSIG_EN_WR(v)     (HW_MIPI_HSI_DMA_IRQSIG_EN.U = (v))
#define HW_MIPI_HSI_DMA_IRQSIG_EN_SET(v)    (HW_MIPI_HSI_DMA_IRQSIG_EN_WR(HW_MIPI_HSI_DMA_IRQSIG_EN_RD() |  (v)))
#define HW_MIPI_HSI_DMA_IRQSIG_EN_CLR(v)    (HW_MIPI_HSI_DMA_IRQSIG_EN_WR(HW_MIPI_HSI_DMA_IRQSIG_EN_RD() & ~(v)))
#define HW_MIPI_HSI_DMA_IRQSIG_EN_TOG(v)    (HW_MIPI_HSI_DMA_IRQSIG_EN_WR(HW_MIPI_HSI_DMA_IRQSIG_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_DMA_IRQSIG_EN bitfields
 */

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA0 (RW)
 *
 * RDMA Channel 0 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA0      0
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA0)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA0(v)   (((v) << 0) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA0 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA0(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA0, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA1 (RW)
 *
 * RDMA Channel 1 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA1      1
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA1(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA1)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA1(v)   (((v) << 1) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA1 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA1(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA1, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA2 (RW)
 *
 * RDMA Channel 2 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA2      2
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA2(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA2)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA2(v)   (((v) << 2) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA2 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA2(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA2, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA3 (RW)
 *
 * RDMA Channel 3 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA3      3
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA3(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA3)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA3(v)   (((v) << 3) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA3 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA3(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA3, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA4 (RW)
 *
 * RDMA Channel 4 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA4      4
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA4(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA4)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA4(v)   (((v) << 4) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA4 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA4(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA4, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA5 (RW)
 *
 * RDMA Channel 5 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA5      5
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA5(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA5)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA5(v)   (((v) << 5) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA5 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA5(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA5, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA6 (RW)
 *
 * RDMA Channel 6 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA6      6
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA6(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA6)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA6(v)   (((v) << 6) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA6 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA6(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA6, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA7 (RW)
 *
 * RDMA Channel 7 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA7      7
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA7(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA7)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA7(v)   (((v) << 7) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA7 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA7(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA7, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA8 (RW)
 *
 * RDMA Channel 8 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA8      8
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA8(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA8)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA8(v)   (((v) << 8) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA8 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA8(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA8, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA9 (RW)
 *
 * RDMA Channel 9 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA9      9
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA9(v)   ((((reg32_t) v) << 9) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA9)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA9(v)   (((v) << 9) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA9 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA9(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA9, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA10 (RW)
 *
 * RDMA Channel 10 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA10      10
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA10(v)   ((((reg32_t) v) << 10) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA10)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA10(v)   (((v) << 10) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA10 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA10(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA10, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA11 (RW)
 *
 * RDMA Channel 11 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA11      11
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA11(v)   ((((reg32_t) v) << 11) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA11)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA11(v)   (((v) << 11) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA11 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA11(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA11, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA12 (RW)
 *
 * RDMA Channel 12 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA12      12
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA12(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA12)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA12(v)   (((v) << 12) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA12 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA12(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA12, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA13 (RW)
 *
 * RDMA Channel 13 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA13      13
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA13(v)   ((((reg32_t) v) << 13) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA13)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA13(v)   (((v) << 13) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA13 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA13(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA13, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA14 (RW)
 *
 * RDMA Channel 14 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA14      14
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA14(v)   ((((reg32_t) v) << 14) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA14)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA14(v)   (((v) << 14) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA14 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA14(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA14, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field RDMA15 (RW)
 *
 * RDMA Channel 15 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_RDMA15      15
#define BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA15(v)   ((((reg32_t) v) << 15) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA15)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_RDMA15(v)   (((v) << 15) & BM_MIPI_HSI_DMA_IRQSIG_EN_RDMA15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA15 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_RDMA15(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, RDMA15, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA0 (RW)
 *
 * TDMA Channel 0 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA0      16
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA0(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA0)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA0(v)   (((v) << 16) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA0 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA0(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA0, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA1 (RW)
 *
 * TDMA Channel 1 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA1      17
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA1(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA1)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA1(v)   (((v) << 17) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA1 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA1(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA1, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA2 (RW)
 *
 * TDMA Channel 2 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA2      18
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA2(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA2)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA2(v)   (((v) << 18) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA2 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA2(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA2, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA3 (RW)
 *
 * TDMA Channel 3 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA3      19
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA3      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA3(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA3)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA3(v)   (((v) << 19) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA3 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA3(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA3, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA4 (RW)
 *
 * TDMA Channel 4 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA4      20
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA4      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA4(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA4)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA4(v)   (((v) << 20) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA4 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA4(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA4, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA5 (RW)
 *
 * TDMA Channel 5 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA5      21
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA5      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA5(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA5)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA5(v)   (((v) << 21) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA5 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA5(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA5, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA6 (RW)
 *
 * TDMA Channel 6 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA6      22
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA6      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA6(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA6)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA6(v)   (((v) << 22) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA6 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA6(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA6, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA7 (RW)
 *
 * TDMA Channel 7 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA7      23
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA7      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA7(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA7)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA7(v)   (((v) << 23) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA7 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA7(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA7, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA8 (RW)
 *
 * TDMA Channel 8 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA8      24
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA8      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA8(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA8)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA8(v)   (((v) << 24) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA8 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA8(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA8, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA9 (RW)
 *
 * TDMA Channel 9 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA9      25
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA9      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA9(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA9)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA9(v)   (((v) << 25) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA9 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA9(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA9, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA10 (RW)
 *
 * TDMA Channel 10 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA10      26
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA10      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA10(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA10)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA10(v)   (((v) << 26) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA10 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA10(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA10, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA11 (RW)
 *
 * TDMA Channel 11 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA11      27
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA11      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA11(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA11)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA11(v)   (((v) << 27) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA11 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA11(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA11, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA12 (RW)
 *
 * TDMA Channel 12 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA12      28
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA12      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA12(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA12)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA12(v)   (((v) << 28) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA12 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA12(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA12, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA13 (RW)
 *
 * TDMA Channel 13 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA13      29
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA13      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA13(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA13)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA13(v)   (((v) << 29) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA13 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA13(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA13, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA14 (RW)
 *
 * TDMA Channel 14 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA14      30
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA14      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA14(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA14)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA14(v)   (((v) << 30) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA14 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA14(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA14, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_IRQSIG_EN, field TDMA15 (RW)
 *
 * TDMA Channel 15 interrupt status enable
 */

#define BP_MIPI_HSI_DMA_IRQSIG_EN_TDMA15      31
#define BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA15      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA15(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA15)
#else
#define BF_MIPI_HSI_DMA_IRQSIG_EN_TDMA15(v)   (((v) << 31) & BM_MIPI_HSI_DMA_IRQSIG_EN_TDMA15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA15 field to a new value.
#define BW_MIPI_HSI_DMA_IRQSIG_EN_TDMA15(v)   BF_CS1(MIPI_HSI_DMA_IRQSIG_EN, TDMA15, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_DMA_ERR_IRQSTAT - DMA Error Interrupt Status Register (RO)
 *
 * This register contains all the error interrupt status for HSI internal DMA
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RDMA0 : 1; //!< RDMA Channel 0 error interrupt status
        unsigned RDMA1 : 1; //!< RDMA Channel 1 error interrupt status
        unsigned RDMA2 : 1; //!< RDMA Channel 2 error interrupt status
        unsigned RDMA3 : 1; //!< RDMA Channel 3 error interrupt status
        unsigned RDMA4 : 1; //!< RDMA Channel 4 error interrupt status
        unsigned RDMA5 : 1; //!< RDMA Channel 5 error interrupt status
        unsigned RDMA6 : 1; //!< RDMA Channel 6 error interrupt status
        unsigned RDMA7 : 1; //!< RDMA Channel 7 error interrupt status
        unsigned RDMA8 : 1; //!< RDMA Channel 8 error interrupt status
        unsigned RDMA9 : 1; //!< RDMA Channel 9 error interrupt status
        unsigned RDMA10 : 1; //!< RDMA Channel 10 error interrupt status
        unsigned RDMA11 : 1; //!< RDMA Channel 11 error interrupt status
        unsigned RDMA12 : 1; //!< RDMA Channel 12 error interrupt status
        unsigned RDMA13 : 1; //!< RDMA Channel 13 error interrupt status
        unsigned RDMA14 : 1; //!< RDMA Channel 14 error interrupt status
        unsigned RDMA15 : 1; //!< RDMA Channel 15 error interrupt status
        unsigned TDMA0 : 1; //!< TDMA Channel 0 error interrupt status
        unsigned TDMA1 : 1; //!< TDMA Channel 1 error interrupt status
        unsigned TDMA2 : 1; //!< TDMA Channel 2 error interrupt status
        unsigned TDMA3 : 1; //!< TDMA Channel 3 error interrupt status
        unsigned TDMA4 : 1; //!< TDMA Channel 4 error interrupt status
        unsigned TDMA5 : 1; //!< TDMA Channel 5 error interrupt status
        unsigned TDMA6 : 1; //!< TDMA Channel 6 error interrupt status
        unsigned TDMA7 : 1; //!< TDMA Channel 7 error interrupt status
        unsigned TDMA8 : 1; //!< TDMA Channel 8 error interrupt status
        unsigned TDMA9 : 1; //!< TDMA Channel 9 error interrupt status
        unsigned TDMA10 : 1; //!< TDMA Channel 10 error interrupt status
        unsigned TDMA11 : 1; //!< TDMA Channel 11 error interrupt status
        unsigned TDMA12 : 1; //!< TDMA Channel 12 error interrupt status
        unsigned TDMA13 : 1; //!< TDMA Channel 13 error interrupt status
        unsigned TDMA14 : 1; //!< TDMA Channel 14 error interrupt status
        unsigned TDMA15 : 1; //!< TDMA Channel 15 error interrupt status
    } B;
} hw_mipi_hsi_dma_err_irqstat_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_DMA_ERR_IRQSTAT register
 */
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_ADDR      (REGS_MIPI_HSI_BASE + 0x1e8)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT           (*(volatile hw_mipi_hsi_dma_err_irqstat_t *) HW_MIPI_HSI_DMA_ERR_IRQSTAT_ADDR)
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_RD()      (HW_MIPI_HSI_DMA_ERR_IRQSTAT.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_DMA_ERR_IRQSTAT bitfields
 */

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA0 (RO)
 *
 * RDMA Channel 0 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA0      0
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA0      0x00000001

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA1 (RO)
 *
 * RDMA Channel 1 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA1      1
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA1      0x00000002

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA2 (RO)
 *
 * RDMA Channel 2 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA2      2
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA2      0x00000004

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA3 (RO)
 *
 * RDMA Channel 3 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA3      3
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA3      0x00000008

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA4 (RO)
 *
 * RDMA Channel 4 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA4      4
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA4      0x00000010

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA5 (RO)
 *
 * RDMA Channel 5 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA5      5
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA5      0x00000020

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA6 (RO)
 *
 * RDMA Channel 6 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA6      6
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA6      0x00000040

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA7 (RO)
 *
 * RDMA Channel 7 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA7      7
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA7      0x00000080

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA8 (RO)
 *
 * RDMA Channel 8 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA8      8
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA8      0x00000100

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA9 (RO)
 *
 * RDMA Channel 9 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA9      9
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA9      0x00000200

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA10 (RO)
 *
 * RDMA Channel 10 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA10      10
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA10      0x00000400

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA11 (RO)
 *
 * RDMA Channel 11 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA11      11
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA11      0x00000800

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA12 (RO)
 *
 * RDMA Channel 12 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA12      12
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA12      0x00001000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA13 (RO)
 *
 * RDMA Channel 13 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA13      13
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA13      0x00002000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA14 (RO)
 *
 * RDMA Channel 14 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA14      14
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA14      0x00004000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field RDMA15 (RO)
 *
 * RDMA Channel 15 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA15      15
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_RDMA15      0x00008000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA0 (RO)
 *
 * TDMA Channel 0 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA0      16
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA0      0x00010000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA1 (RO)
 *
 * TDMA Channel 1 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA1      17
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA1      0x00020000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA2 (RO)
 *
 * TDMA Channel 2 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA2      18
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA2      0x00040000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA3 (RO)
 *
 * TDMA Channel 3 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA3      19
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA3      0x00080000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA4 (RO)
 *
 * TDMA Channel 4 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA4      20
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA4      0x00100000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA5 (RO)
 *
 * TDMA Channel 5 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA5      21
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA5      0x00200000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA6 (RO)
 *
 * TDMA Channel 6 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA6      22
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA6      0x00400000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA7 (RO)
 *
 * TDMA Channel 7 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA7      23
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA7      0x00800000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA8 (RO)
 *
 * TDMA Channel 8 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA8      24
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA8      0x01000000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA9 (RO)
 *
 * TDMA Channel 9 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA9      25
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA9      0x02000000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA10 (RO)
 *
 * TDMA Channel 10 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA10      26
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA10      0x04000000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA11 (RO)
 *
 * TDMA Channel 11 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA11      27
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA11      0x08000000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA12 (RO)
 *
 * TDMA Channel 12 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA12      28
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA12      0x10000000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA13 (RO)
 *
 * TDMA Channel 13 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA13      29
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA13      0x20000000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA14 (RO)
 *
 * TDMA Channel 14 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA14      30
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA14      0x40000000

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT, field TDMA15 (RO)
 *
 * TDMA Channel 15 error interrupt status
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA15      31
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_TDMA15      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN - DMA Error Interrupt Enable Register (RW)
 *
 * This register is used to select which DMA error interrupt could send to HIS Interrupt Status
 * Register
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RDMA0 : 1; //!< RDMA Channel 0 error interrupt enable
        unsigned RDMA1 : 1; //!< RDMA Channel 1 error interrupt enable
        unsigned RDMA2 : 1; //!< RDMA Channel 2 error interrupt enable
        unsigned RDMA3 : 1; //!< RDMA Channel 3 error interrupt enable
        unsigned RDMA4 : 1; //!< RDMA Channel 4 error interrupt enable
        unsigned RDMA5 : 1; //!< RDMA Channel 5 error interrupt enable
        unsigned RDMA6 : 1; //!< RDMA Channel 6 error interrupt enable
        unsigned RDMA7 : 1; //!< RDMA Channel 7 error interrupt enable
        unsigned RDMA8 : 1; //!< RDMA Channel 8 error interrupt enable
        unsigned RDMA9 : 1; //!< RDMA Channel 9 error interrupt enable
        unsigned RDMA10 : 1; //!< RDMA Channel 10 error interrupt enable
        unsigned RDMA11 : 1; //!< RDMA Channel 11 error interrupt enable
        unsigned RDMA12 : 1; //!< RDMA Channel 12 error interrupt enable
        unsigned RDMA13 : 1; //!< RDMA Channel 13 error interrupt enable
        unsigned RDMA14 : 1; //!< RDMA Channel 14 error interrupt enable
        unsigned RDMA15 : 1; //!< RDMA Channel 15 error interrupt enable
        unsigned TDMA0 : 1; //!< TDMA Channel 0 error interrupt enable
        unsigned TDMA1 : 1; //!< TDMA Channel 1 error interrupt enable
        unsigned TDMA2 : 1; //!< TDMA Channel 2 error interrupt enable
        unsigned TDMA3 : 1; //!< TDMA Channel 3 error interrupt enable
        unsigned TDMA4 : 1; //!< TDMA Channel 4 error interrupt enable
        unsigned TDMA5 : 1; //!< TDMA Channel 5 error interrupt enable
        unsigned TDMA6 : 1; //!< TDMA Channel 6 error interrupt enable
        unsigned TDMA7 : 1; //!< TDMA Channel 7 error interrupt enable
        unsigned TDMA8 : 1; //!< TDMA Channel 8 error interrupt enable
        unsigned TDMA9 : 1; //!< TDMA Channel 9 error interrupt enable
        unsigned TDMA10 : 1; //!< TDMA Channel 10 error interrupt enable
        unsigned TDMA11 : 1; //!< TDMA Channel 11 error interrupt enable
        unsigned TDMA12 : 1; //!< TDMA Channel 12 error interrupt enable
        unsigned TDMA13 : 1; //!< TDMA Channel 13 error interrupt enable
        unsigned TDMA14 : 1; //!< TDMA Channel 14 error interrupt enable
        unsigned TDMA15 : 1; //!< TDMA Channel 15 error interrupt enable
    } B;
} hw_mipi_hsi_dma_err_irqstat_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_DMA_ERR_IRQSTAT_EN register
 */
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x1ec)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN           (*(volatile hw_mipi_hsi_dma_err_irqstat_en_t *) HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_ADDR)
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RD()      (HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN.U)
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_WR(v)     (HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN.U = (v))
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_SET(v)    (HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_WR(HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RD() |  (v)))
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_CLR(v)    (HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_WR(HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RD() & ~(v)))
#define HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TOG(v)    (HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_WR(HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_DMA_ERR_IRQSTAT_EN bitfields
 */

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA0 (RW)
 *
 * RDMA Channel 0 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA0      0
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA0)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA0(v)   (((v) << 0) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA0 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA0(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA0, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA1 (RW)
 *
 * RDMA Channel 1 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA1      1
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA1(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA1)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA1(v)   (((v) << 1) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA1 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA1(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA1, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA2 (RW)
 *
 * RDMA Channel 2 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA2      2
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA2(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA2)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA2(v)   (((v) << 2) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA2 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA2(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA2, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA3 (RW)
 *
 * RDMA Channel 3 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA3      3
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA3(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA3)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA3(v)   (((v) << 3) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA3 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA3(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA3, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA4 (RW)
 *
 * RDMA Channel 4 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA4      4
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA4(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA4)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA4(v)   (((v) << 4) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA4 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA4(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA4, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA5 (RW)
 *
 * RDMA Channel 5 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA5      5
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA5(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA5)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA5(v)   (((v) << 5) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA5 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA5(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA5, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA6 (RW)
 *
 * RDMA Channel 6 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA6      6
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA6(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA6)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA6(v)   (((v) << 6) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA6 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA6(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA6, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA7 (RW)
 *
 * RDMA Channel 7 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA7      7
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA7(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA7)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA7(v)   (((v) << 7) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA7 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA7(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA7, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA8 (RW)
 *
 * RDMA Channel 8 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA8      8
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA8(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA8)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA8(v)   (((v) << 8) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA8 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA8(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA8, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA9 (RW)
 *
 * RDMA Channel 9 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA9      9
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA9(v)   ((((reg32_t) v) << 9) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA9)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA9(v)   (((v) << 9) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA9 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA9(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA9, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA10 (RW)
 *
 * RDMA Channel 10 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA10      10
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA10(v)   ((((reg32_t) v) << 10) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA10)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA10(v)   (((v) << 10) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA10 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA10(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA10, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA11 (RW)
 *
 * RDMA Channel 11 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA11      11
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA11(v)   ((((reg32_t) v) << 11) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA11)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA11(v)   (((v) << 11) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA11 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA11(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA11, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA12 (RW)
 *
 * RDMA Channel 12 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA12      12
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA12(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA12)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA12(v)   (((v) << 12) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA12 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA12(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA12, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA13 (RW)
 *
 * RDMA Channel 13 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA13      13
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA13(v)   ((((reg32_t) v) << 13) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA13)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA13(v)   (((v) << 13) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA13 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA13(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA13, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA14 (RW)
 *
 * RDMA Channel 14 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA14      14
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA14(v)   ((((reg32_t) v) << 14) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA14)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA14(v)   (((v) << 14) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA14 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA14(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA14, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field RDMA15 (RW)
 *
 * RDMA Channel 15 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA15      15
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA15(v)   ((((reg32_t) v) << 15) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA15)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA15(v)   (((v) << 15) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA15 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_RDMA15(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, RDMA15, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA0 (RW)
 *
 * TDMA Channel 0 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA0      16
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA0(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA0)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA0(v)   (((v) << 16) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA0 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA0(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA0, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA1 (RW)
 *
 * TDMA Channel 1 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA1      17
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA1(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA1)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA1(v)   (((v) << 17) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA1 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA1(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA1, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA2 (RW)
 *
 * TDMA Channel 2 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA2      18
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA2(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA2)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA2(v)   (((v) << 18) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA2 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA2(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA2, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA3 (RW)
 *
 * TDMA Channel 3 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA3      19
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA3      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA3(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA3)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA3(v)   (((v) << 19) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA3 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA3(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA3, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA4 (RW)
 *
 * TDMA Channel 4 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA4      20
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA4      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA4(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA4)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA4(v)   (((v) << 20) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA4 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA4(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA4, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA5 (RW)
 *
 * TDMA Channel 5 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA5      21
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA5      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA5(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA5)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA5(v)   (((v) << 21) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA5 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA5(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA5, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA6 (RW)
 *
 * TDMA Channel 6 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA6      22
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA6      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA6(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA6)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA6(v)   (((v) << 22) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA6 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA6(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA6, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA7 (RW)
 *
 * TDMA Channel 7 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA7      23
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA7      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA7(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA7)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA7(v)   (((v) << 23) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA7 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA7(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA7, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA8 (RW)
 *
 * TDMA Channel 8 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA8      24
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA8      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA8(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA8)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA8(v)   (((v) << 24) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA8 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA8(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA8, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA9 (RW)
 *
 * TDMA Channel 9 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA9      25
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA9      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA9(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA9)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA9(v)   (((v) << 25) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA9 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA9(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA9, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA10 (RW)
 *
 * TDMA Channel 10 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA10      26
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA10      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA10(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA10)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA10(v)   (((v) << 26) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA10 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA10(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA10, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA11 (RW)
 *
 * TDMA Channel 11 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA11      27
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA11      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA11(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA11)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA11(v)   (((v) << 27) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA11 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA11(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA11, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA12 (RW)
 *
 * TDMA Channel 12 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA12      28
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA12      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA12(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA12)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA12(v)   (((v) << 28) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA12 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA12(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA12, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA13 (RW)
 *
 * TDMA Channel 13 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA13      29
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA13      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA13(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA13)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA13(v)   (((v) << 29) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA13 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA13(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA13, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA14 (RW)
 *
 * TDMA Channel 14 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA14      30
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA14      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA14(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA14)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA14(v)   (((v) << 30) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA14 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA14(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA14, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSTAT_EN, field TDMA15 (RW)
 *
 * TDMA Channel 15 error interrupt enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA15      31
#define BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA15      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA15(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA15)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA15(v)   (((v) << 31) & BM_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA15 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSTAT_EN_TDMA15(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSTAT_EN, TDMA15, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_DMA_ERR_IRQSIG_EN - DMA Error Interrupt Signal Enable Register (RW)
 *
 * This Register is used to select which DMA error interrupt status could send to HIS Interrupt
 * Status Register
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RDMA0 : 1; //!< RDMA Channel 0 error interrupt status enable
        unsigned RDMA1 : 1; //!< RDMA Channel 1 error interrupt status enable
        unsigned RDMA2 : 1; //!< RDMA Channel 2 error interrupt status enable
        unsigned RDMA3 : 1; //!< RDMA Channel 3 error interrupt status enable
        unsigned RDMA4 : 1; //!< RDMA Channel 4 error interrupt status enable
        unsigned RDMA5 : 1; //!< RDMA Channel 5 error interrupt status enable
        unsigned RDMA6 : 1; //!< RDMA Channel 6 error interrupt status enable
        unsigned RDMA7 : 1; //!< RDMA Channel 7 error interrupt status enable
        unsigned RDMA8 : 1; //!< RDMA Channel 8 error interrupt status enable
        unsigned RDMA9 : 1; //!< RDMA Channel 9 error interrupt status enable
        unsigned RDMA10 : 1; //!< RDMA Channel 10 error interrupt status enable
        unsigned RDMA11 : 1; //!< RDMA Channel 11 error interrupt status enable
        unsigned RDMA12 : 1; //!< RDMA Channel 12 error interrupt status enable
        unsigned RDMA13 : 1; //!< RDMA Channel 13 error interrupt status enable
        unsigned RDMA14 : 1; //!< RDMA Channel 14 error interrupt status enable
        unsigned RDMA15 : 1; //!< RDMA Channel 15 error interrupt status enable
        unsigned TDMA0 : 1; //!< TDMA Channel 0 error interrupt status enable
        unsigned TDMA1 : 1; //!< TDMA Channel 1 error interrupt status enable
        unsigned TDMA2 : 1; //!< TDMA Channel 2 error interrupt status enable
        unsigned TDMA3 : 1; //!< TDMA Channel 3 error interrupt status enable
        unsigned TDMA4 : 1; //!< TDMA Channel 4 error interrupt status enable
        unsigned TDMA5 : 1; //!< TDMA Channel 5 error interrupt status enable
        unsigned TDMA6 : 1; //!< TDMA Channel 6 error interrupt status enable
        unsigned TDMA7 : 1; //!< TDMA Channel 7 error interrupt status enable
        unsigned TDMA8 : 1; //!< TDMA Channel 8 error interrupt status enable
        unsigned TDMA9 : 1; //!< TDMA Channel 9 error interrupt status enable
        unsigned TDMA10 : 1; //!< TDMA Channel 10 error interrupt status enable
        unsigned TDMA11 : 1; //!< TDMA Channel 11 error interrupt status enable
        unsigned TDMA12 : 1; //!< TDMA Channel 12 error interrupt status enable
        unsigned TDMA13 : 1; //!< TDMA Channel 13 error interrupt status enable
        unsigned TDMA14 : 1; //!< TDMA Channel 14 error interrupt status enable
        unsigned TDMA15 : 1; //!< TDMA Channel 15 error interrupt status enable
    } B;
} hw_mipi_hsi_dma_err_irqsig_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_DMA_ERR_IRQSIG_EN register
 */
#define HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x1f0)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_DMA_ERR_IRQSIG_EN           (*(volatile hw_mipi_hsi_dma_err_irqsig_en_t *) HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_ADDR)
#define HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RD()      (HW_MIPI_HSI_DMA_ERR_IRQSIG_EN.U)
#define HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_WR(v)     (HW_MIPI_HSI_DMA_ERR_IRQSIG_EN.U = (v))
#define HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_SET(v)    (HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_WR(HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RD() |  (v)))
#define HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_CLR(v)    (HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_WR(HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RD() & ~(v)))
#define HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TOG(v)    (HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_WR(HW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_DMA_ERR_IRQSIG_EN bitfields
 */

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA0 (RW)
 *
 * RDMA Channel 0 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA0      0
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA0)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA0(v)   (((v) << 0) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA0 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA0(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA0, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA1 (RW)
 *
 * RDMA Channel 1 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA1      1
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA1(v)   ((((reg32_t) v) << 1) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA1)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA1(v)   (((v) << 1) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA1 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA1(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA1, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA2 (RW)
 *
 * RDMA Channel 2 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA2      2
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA2(v)   ((((reg32_t) v) << 2) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA2)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA2(v)   (((v) << 2) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA2 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA2(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA2, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA3 (RW)
 *
 * RDMA Channel 3 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA3      3
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA3(v)   ((((reg32_t) v) << 3) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA3)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA3(v)   (((v) << 3) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA3 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA3(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA3, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA4 (RW)
 *
 * RDMA Channel 4 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA4      4
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA4(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA4)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA4(v)   (((v) << 4) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA4 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA4(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA4, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA5 (RW)
 *
 * RDMA Channel 5 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA5      5
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA5(v)   ((((reg32_t) v) << 5) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA5)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA5(v)   (((v) << 5) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA5 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA5(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA5, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA6 (RW)
 *
 * RDMA Channel 6 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA6      6
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA6(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA6)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA6(v)   (((v) << 6) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA6 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA6(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA6, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA7 (RW)
 *
 * RDMA Channel 7 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA7      7
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA7(v)   ((((reg32_t) v) << 7) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA7)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA7(v)   (((v) << 7) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA7 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA7(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA7, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA8 (RW)
 *
 * RDMA Channel 8 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA8      8
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA8(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA8)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA8(v)   (((v) << 8) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA8 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA8(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA8, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA9 (RW)
 *
 * RDMA Channel 9 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA9      9
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA9(v)   ((((reg32_t) v) << 9) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA9)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA9(v)   (((v) << 9) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA9 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA9(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA9, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA10 (RW)
 *
 * RDMA Channel 10 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA10      10
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA10(v)   ((((reg32_t) v) << 10) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA10)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA10(v)   (((v) << 10) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA10 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA10(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA10, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA11 (RW)
 *
 * RDMA Channel 11 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA11      11
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA11(v)   ((((reg32_t) v) << 11) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA11)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA11(v)   (((v) << 11) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA11 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA11(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA11, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA12 (RW)
 *
 * RDMA Channel 12 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA12      12
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA12(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA12)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA12(v)   (((v) << 12) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA12 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA12(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA12, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA13 (RW)
 *
 * RDMA Channel 13 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA13      13
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA13(v)   ((((reg32_t) v) << 13) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA13)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA13(v)   (((v) << 13) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA13 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA13(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA13, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA14 (RW)
 *
 * RDMA Channel 14 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA14      14
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA14(v)   ((((reg32_t) v) << 14) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA14)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA14(v)   (((v) << 14) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA14 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA14(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA14, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field RDMA15 (RW)
 *
 * RDMA Channel 15 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA15      15
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA15(v)   ((((reg32_t) v) << 15) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA15)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA15(v)   (((v) << 15) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMA15 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_RDMA15(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, RDMA15, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA0 (RW)
 *
 * TDMA Channel 0 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA0      16
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA0(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA0)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA0(v)   (((v) << 16) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA0 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA0(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA0, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA1 (RW)
 *
 * TDMA Channel 1 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA1      17
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA1(v)   ((((reg32_t) v) << 17) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA1)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA1(v)   (((v) << 17) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA1 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA1(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA1, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA2 (RW)
 *
 * TDMA Channel 2 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA2      18
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA2(v)   ((((reg32_t) v) << 18) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA2)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA2(v)   (((v) << 18) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA2 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA2(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA2, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA3 (RW)
 *
 * TDMA Channel 3 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA3      19
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA3      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA3(v)   ((((reg32_t) v) << 19) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA3)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA3(v)   (((v) << 19) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA3 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA3(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA3, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA4 (RW)
 *
 * TDMA Channel 4 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA4      20
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA4      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA4(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA4)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA4(v)   (((v) << 20) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA4 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA4(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA4, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA5 (RW)
 *
 * TDMA Channel 5 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA5      21
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA5      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA5(v)   ((((reg32_t) v) << 21) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA5)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA5(v)   (((v) << 21) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA5 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA5(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA5, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA6 (RW)
 *
 * TDMA Channel 6 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA6      22
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA6      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA6(v)   ((((reg32_t) v) << 22) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA6)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA6(v)   (((v) << 22) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA6 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA6(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA6, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA7 (RW)
 *
 * TDMA Channel 7 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA7      23
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA7      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA7(v)   ((((reg32_t) v) << 23) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA7)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA7(v)   (((v) << 23) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA7 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA7(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA7, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA8 (RW)
 *
 * TDMA Channel 8 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA8      24
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA8      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA8(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA8)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA8(v)   (((v) << 24) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA8 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA8(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA8, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA9 (RW)
 *
 * TDMA Channel 9 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA9      25
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA9      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA9(v)   ((((reg32_t) v) << 25) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA9)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA9(v)   (((v) << 25) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA9 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA9(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA9, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA10 (RW)
 *
 * TDMA Channel 10 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA10      26
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA10      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA10(v)   ((((reg32_t) v) << 26) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA10)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA10(v)   (((v) << 26) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA10 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA10(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA10, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA11 (RW)
 *
 * TDMA Channel 11 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA11      27
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA11      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA11(v)   ((((reg32_t) v) << 27) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA11)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA11(v)   (((v) << 27) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA11 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA11(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA11, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA12 (RW)
 *
 * TDMA Channel 12 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA12      28
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA12      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA12(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA12)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA12(v)   (((v) << 28) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA12 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA12(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA12, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA13 (RW)
 *
 * TDMA Channel 13 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA13      29
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA13      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA13(v)   ((((reg32_t) v) << 29) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA13)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA13(v)   (((v) << 29) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA13 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA13(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA13, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA14 (RW)
 *
 * TDMA Channel 14 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA14      30
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA14      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA14(v)   ((((reg32_t) v) << 30) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA14)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA14(v)   (((v) << 30) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA14 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA14(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA14, v)
#endif

/* --- Register HW_MIPI_HSI_DMA_ERR_IRQSIG_EN, field TDMA15 (RW)
 *
 * TDMA Channel 15 error interrupt status enable
 */

#define BP_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA15      31
#define BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA15      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA15(v)   ((((reg32_t) v) << 31) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA15)
#else
#define BF_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA15(v)   (((v) << 31) & BM_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMA15 field to a new value.
#define BW_MIPI_HSI_DMA_ERR_IRQSIG_EN_TDMA15(v)   BF_CS1(MIPI_HSI_DMA_ERR_IRQSIG_EN, TDMA15, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_DMA_SINGLE_REQ_EN - DMA Single Request Enable Register (RO)
 *
 * This Register is used to debug
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RDMA0 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 0, this bit will be set automatically
        unsigned RDMA1 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 1, this bit will be set automatically
        unsigned RDMA2 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 2, this bit will be set automatically
        unsigned RDMA3 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 3, this bit will be set automatically
        unsigned RDMA4 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 4, this bit will be set automatically
        unsigned RDMA5 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 5, this bit will be set automatically
        unsigned RDMA6 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 6, this bit will be set automatically
        unsigned RDMA7 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 7, this bit will be set automatically
        unsigned RDMA8 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 8, this bit will be set automatically
        unsigned RDMA9 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 9, this bit will be set automatically
        unsigned RDMA10 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 10, this bit will be set automatically
        unsigned RDMA11 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 11, this bit will be set automatically
        unsigned RDMA12 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 12, this bit will be set automatically
        unsigned RDMA13 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 13, this bit will be set automatically
        unsigned RDMA14 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 14, this bit will be set automatically
        unsigned RDMA15 : 1; //!< When the remain DMA data less than one DMA burst size in Rx Dma Channle 15, this bit will be set automatically
        unsigned TDMA0 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 0, this bit will be set automatically
        unsigned TDMA1 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 1, this bit will be set automatically
        unsigned TDMA2 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 2, this bit will be set automatically
        unsigned TDMA3 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 3, this bit will be set automatically
        unsigned TDMA4 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 4, this bit will be set automatically
        unsigned TDMA5 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 5, this bit will be set automatically
        unsigned TDMA6 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 6, this bit will be set automatically
        unsigned TDMA7 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 7, this bit will be set automatically
        unsigned TDMA8 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 8, this bit will be set automatically
        unsigned TDMA9 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 9, this bit will be set automatically
        unsigned TDMA10 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 10, this bit will be set automatically
        unsigned TDMA11 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 11, this bit will be set automatically
        unsigned TDMA12 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 12, this bit will be set automatically
        unsigned TDMA13 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 13, this bit will be set automatically
        unsigned TDMA14 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 14, this bit will be set automatically
        unsigned TDMA15 : 1; //!< When the remain DMA data less than one DMA burst size in Tx Dma Channle 15, this bit will be set automatically
    } B;
} hw_mipi_hsi_dma_single_req_en_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_DMA_SINGLE_REQ_EN register
 */
#define HW_MIPI_HSI_DMA_SINGLE_REQ_EN_ADDR      (REGS_MIPI_HSI_BASE + 0x1f4)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_DMA_SINGLE_REQ_EN           (*(volatile hw_mipi_hsi_dma_single_req_en_t *) HW_MIPI_HSI_DMA_SINGLE_REQ_EN_ADDR)
#define HW_MIPI_HSI_DMA_SINGLE_REQ_EN_RD()      (HW_MIPI_HSI_DMA_SINGLE_REQ_EN.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_DMA_SINGLE_REQ_EN bitfields
 */

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA0 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 0, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA0      0
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA0      0x00000001

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA1 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 1, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA1      1
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA1      0x00000002

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA2 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 2, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA2      2
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA2      0x00000004

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA3 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 3, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA3      3
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA3      0x00000008

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA4 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 4, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA4      4
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA4      0x00000010

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA5 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 5, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA5      5
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA5      0x00000020

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA6 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 6, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA6      6
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA6      0x00000040

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA7 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 7, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA7      7
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA7      0x00000080

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA8 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 8, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA8      8
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA8      0x00000100

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA9 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 9, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA9      9
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA9      0x00000200

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA10 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 10, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA10      10
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA10      0x00000400

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA11 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 11, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA11      11
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA11      0x00000800

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA12 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 12, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA12      12
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA12      0x00001000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA13 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 13, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA13      13
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA13      0x00002000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA14 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 14, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA14      14
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA14      0x00004000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field RDMA15 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Rx Dma Channle 15, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA15      15
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_RDMA15      0x00008000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA0 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 0, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA0      16
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA0      0x00010000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA1 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 1, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA1      17
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA1      0x00020000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA2 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 2, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA2      18
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA2      0x00040000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA3 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 3, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA3      19
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA3      0x00080000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA4 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 4, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA4      20
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA4      0x00100000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA5 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 5, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA5      21
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA5      0x00200000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA6 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 6, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA6      22
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA6      0x00400000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA7 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 7, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA7      23
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA7      0x00800000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA8 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 8, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA8      24
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA8      0x01000000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA9 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 9, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA9      25
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA9      0x02000000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA10 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 10, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA10      26
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA10      0x04000000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA11 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 11, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA11      27
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA11      0x08000000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA12 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 12, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA12      28
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA12      0x10000000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA13 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 13, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA13      29
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA13      0x20000000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA14 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 14, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA14      30
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA14      0x40000000

/* --- Register HW_MIPI_HSI_DMA_SINGLE_REQ_EN, field TDMA15 (RO)
 *
 * When the remain DMA data less than one DMA burst size in Tx Dma Channle 15, this bit will be set
 * automatically
 */

#define BP_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA15      31
#define BM_MIPI_HSI_DMA_SINGLE_REQ_EN_TDMA15      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_FIFO_SIZE_CONF0 - Tx Fifo Size Configuration Register 0 (RW)
 *
 * This register is used to config each Tx fifo size
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH8 : 4; //!< This field is used to set the buffer size for channel 8. All the allowed combinations of bit setting are listed here .
        unsigned CH9 : 4; //!< This field is used to set the buffer size for channel 9. All the allowed combinations of bit setting are listed here .
        unsigned CH10 : 4; //!< This field is used to set the buffer size for channel 10. All the allowed combinations of bit setting are listed here .
        unsigned CH11 : 4; //!< This field is used to set the buffer size for channel 11. All the allowed combinations of bit setting are listed here .
        unsigned CH12 : 4; //!< This field is used to set the buffer size for channel 12. All the allowed combinations of bit setting are listed here .
        unsigned CH13 : 4; //!< This field is used to set the buffer size for channel 13. All the allowed combinations of bit setting are listed here .
        unsigned CH14 : 4; //!< This field is used to set the buffer size for channel 14. All the allowed combinations of bit setting are listed here .
        unsigned CH15 : 4; //!< This field is used to set the buffer size for channel 15. All the allowed combinations of bit setting are listed here .
    } B;
} hw_mipi_hsi_tx_fifo_size_conf0_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_FIFO_SIZE_CONF0 register
 */
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_ADDR      (REGS_MIPI_HSI_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF0           (*(volatile hw_mipi_hsi_tx_fifo_size_conf0_t *) HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_ADDR)
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_RD()      (HW_MIPI_HSI_TX_FIFO_SIZE_CONF0.U)
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_WR(v)     (HW_MIPI_HSI_TX_FIFO_SIZE_CONF0.U = (v))
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_SET(v)    (HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_WR(HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_RD() |  (v)))
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CLR(v)    (HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_WR(HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_RD() & ~(v)))
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_TOG(v)    (HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_WR(HW_MIPI_HSI_TX_FIFO_SIZE_CONF0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_FIFO_SIZE_CONF0 bitfields
 */

/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF0, field CH8 (RW)
 *
 * This field is used to set the buffer size for channel 8. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 8 buffer size is 1Dword
 * 0001 - channel 8 buffer size is 2Dwords
 * 0010 - channel 8 buffer size is 4Dwords
 * 0011 - channel 8 buffer size is 8Dwords
 * 0100 - channel 8 buffer size is 16Dwords
 * 0101 - channel 8 buffer size is 32Dwords
 * 0110 - channel 8 buffer size is 64Dwords
 * 0111 - channel 8 buffer size is 128Dwords
 * 1000 - channel 8 buffer size is 256Dwords
 * 1001 - channel 8 buffer size is 512Dwords
 * 1010 - channel 8 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH8      0
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH8      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH8(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH8)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH8(v)   (((v) << 0) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH8 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH8(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF0, CH8, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF0, field CH9 (RW)
 *
 * This field is used to set the buffer size for channel 9. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 9 buffer size is 1Dword
 * 0001 - channel 9 buffer size is 2Dwords
 * 0010 - channel 9 buffer size is 4Dwords
 * 0011 - channel 9 buffer size is 8Dwords
 * 0100 - channel 9 buffer size is 16Dwords
 * 0101 - channel 9 buffer size is 32Dwords
 * 0110 - channel 9 buffer size is 64Dwords
 * 0111 - channel 9 buffer size is 128Dwords
 * 1000 - channel 9 buffer size is 256Dwords
 * 1001 - channel 9 buffer size is 512Dwords
 * 1010 - channel 9 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH9      4
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH9      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH9(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH9)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH9(v)   (((v) << 4) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH9 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH9(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF0, CH9, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF0, field CH10 (RW)
 *
 * This field is used to set the buffer size for channel 10. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 10 buffer size is 1Dword
 * 0001 - channel 10 buffer size is 2Dwords
 * 0010 - channel 10 buffer size is 4Dwords
 * 0011 - channel 10 buffer size is 8Dwords
 * 0100 - channel 10 buffer size is 16Dwords
 * 0101 - channel 10 buffer size is 32Dwords
 * 0110 - channel 10 buffer size is 64Dwords
 * 0111 - channel 10 buffer size is 128Dwords
 * 1000 - channel 10 buffer size is 256Dwords
 * 1001 - channel 10 buffer size is 512Dwords
 * 1010 - channel 10 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH10      8
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH10      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH10(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH10)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH10(v)   (((v) << 8) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH10 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH10(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF0, CH10, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF0, field CH11 (RW)
 *
 * This field is used to set the buffer size for channel 11. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 11 buffer size is 1Dword
 * 0001 - channel 11 buffer size is 2Dwords
 * 0010 - channel 11 buffer size is 4Dwords
 * 0011 - channel 11 buffer size is 8Dwords
 * 0100 - channel 11 buffer size is 16Dwords
 * 0101 - channel 11 buffer size is 32Dwords
 * 0110 - channel 11 buffer size is 64Dwords
 * 0111 - channel 11 buffer size is 128Dwords
 * 1000 - channel 11 buffer size is 256Dwords
 * 1001 - channel 11 buffer size is 512Dwords
 * 1010 - channel 11 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH11      12
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH11      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH11(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH11)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH11(v)   (((v) << 12) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH11 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH11(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF0, CH11, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF0, field CH12 (RW)
 *
 * This field is used to set the buffer size for channel 12. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 12 buffer size is 1Dword
 * 0001 - channel 12 buffer size is 2Dwords
 * 0010 - channel 12 buffer size is 4Dwords
 * 0011 - channel 12 buffer size is 8Dwords
 * 0100 - channel 12 buffer size is 16Dwords
 * 0101 - channel 12 buffer size is 32Dwords
 * 0110 - channel 12 buffer size is 64Dwords
 * 0111 - channel 12 buffer size is 128Dwords
 * 1000 - channel 12 buffer size is 256Dwords
 * 1001 - channel 12 buffer size is 512Dwords
 * 1010 - channel 12 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH12      16
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH12      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH12(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH12)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH12(v)   (((v) << 16) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH12 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH12(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF0, CH12, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF0, field CH13 (RW)
 *
 * This field is used to set the buffer size for channel 13. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 13 buffer size is 1Dword
 * 0001 - channel 13 buffer size is 2Dwords
 * 0010 - channel 13 buffer size is 4Dwords
 * 0011 - channel 13 buffer size is 8Dwords
 * 0100 - channel 13 buffer size is 16Dwords
 * 0101 - channel 13 buffer size is 32Dwords
 * 0110 - channel 13 buffer size is 64Dwords
 * 0111 - channel 13 buffer size is 128Dwords
 * 1000 - channel 13 buffer size is 256Dwords
 * 1001 - channel 13 buffer size is 512Dwords
 * 1010 - channel 13 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH13      20
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH13      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH13(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH13)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH13(v)   (((v) << 20) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH13 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH13(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF0, CH13, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF0, field CH14 (RW)
 *
 * This field is used to set the buffer size for channel 14. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 14 buffer size is 1Dword
 * 0001 - channel 14 buffer size is 2Dwords
 * 0010 - channel 14 buffer size is 4Dwords
 * 0011 - channel 14 buffer size is 8Dwords
 * 0100 - channel 14 buffer size is 16Dwords
 * 0101 - channel 14 buffer size is 32Dwords
 * 0110 - channel 14 buffer size is 64Dwords
 * 0111 - channel 14 buffer size is 128Dwords
 * 1000 - channel 14 buffer size is 256Dwords
 * 1001 - channel 14 buffer size is 512Dwords
 * 1010 - channel 14 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH14      24
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH14      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH14(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH14)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH14(v)   (((v) << 24) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH14 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH14(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF0, CH14, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF0, field CH15 (RW)
 *
 * This field is used to set the buffer size for channel 15. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 15 buffer size is 1Dword
 * 0001 - channel 15 buffer size is 2Dwords
 * 0010 - channel 15 buffer size is 4Dwords
 * 0011 - channel 15 buffer size is 8Dwords
 * 0100 - channel 15 buffer size is 16Dwords
 * 0101 - channel 15 buffer size is 32Dwords
 * 0110 - channel 15 buffer size is 64Dwords
 * 0111 - channel 15 buffer size is 128Dwords
 * 1000 - channel 15 buffer size is 256Dwords
 * 1001 - channel 15 buffer size is 512Dwords
 * 1010 - channel 15 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH15      28
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH15      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH15(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH15)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH15(v)   (((v) << 28) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH15 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF0_CH15(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF0, CH15, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_FIFO_SIZE_CONF1 - Tx Fifo Size Configuration Register 1 (RW)
 *
 * This register is used to config each Tx fifo size
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH0 : 4; //!< This field is used to set the buffer size for channel 0. All the allowed combinations of bit setting are listed here .
        unsigned CH1 : 4; //!< This field is used to set the buffer size for channel 1. All the allowed combinations of bit setting are listed here .
        unsigned CH2 : 4; //!< This field is used to set the buffer size for channel 2. All the allowed combinations of bit setting are listed here .
        unsigned CH3 : 4; //!< This field is used to set the buffer size for channel 3. All the allowed combinations of bit setting are listed here .
        unsigned CH4 : 4; //!< This field is used to set the buffer size for channel 4. All the allowed combinations of bit setting are listed here .
        unsigned CH5 : 4; //!< This field is used to set the buffer size for channel 5. All the allowed combinations of bit setting are listed here .
        unsigned CH6 : 4; //!< This field is used to set the buffer size for channel 6. All the allowed combinations of bit setting are listed here .
        unsigned CH7 : 4; //!< This field is used to set the buffer size for channel 7. All the allowed combinations of bit setting are listed here .
    } B;
} hw_mipi_hsi_tx_fifo_size_conf1_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_FIFO_SIZE_CONF1 register
 */
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_ADDR      (REGS_MIPI_HSI_BASE + 0x204)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF1           (*(volatile hw_mipi_hsi_tx_fifo_size_conf1_t *) HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_ADDR)
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_RD()      (HW_MIPI_HSI_TX_FIFO_SIZE_CONF1.U)
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_WR(v)     (HW_MIPI_HSI_TX_FIFO_SIZE_CONF1.U = (v))
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_SET(v)    (HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_WR(HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_RD() |  (v)))
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CLR(v)    (HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_WR(HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_RD() & ~(v)))
#define HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_TOG(v)    (HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_WR(HW_MIPI_HSI_TX_FIFO_SIZE_CONF1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_FIFO_SIZE_CONF1 bitfields
 */

/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF1, field CH0 (RW)
 *
 * This field is used to set the buffer size for channel 0. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 0 buffer size is 1Dword
 * 0001 - channel 0 buffer size is 2Dwords
 * 0010 - channel 0 buffer size is 4Dwords
 * 0011 - channel 0 buffer size is 8Dwords
 * 0100 - channel 0 buffer size is 16Dwords
 * 0101 - channel 0 buffer size is 32Dwords
 * 0110 - channel 0 buffer size is 64Dwords
 * 0111 - channel 0 buffer size is 128Dwords
 * 1000 - channel 0 buffer size is 256Dwords
 * 1001 - channel 0 buffer size is 512Dwords
 * 1010 - channel 0 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH0      0
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH0      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH0)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH0(v)   (((v) << 0) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH0(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF1, CH0, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF1, field CH1 (RW)
 *
 * This field is used to set the buffer size for channel 1. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 1 buffer size is 1Dword
 * 0001 - channel 1 buffer size is 2Dwords
 * 0010 - channel 1 buffer size is 4Dwords
 * 0011 - channel 1 buffer size is 8Dwords
 * 0100 - channel 1 buffer size is 16Dwords
 * 0101 - channel 1 buffer size is 32Dwords
 * 0110 - channel 1 buffer size is 64Dwords
 * 0111 - channel 1 buffer size is 128Dwords
 * 1000 - channel 1 buffer size is 256Dwords
 * 1001 - channel 1 buffer size is 512Dwords
 * 1010 - channel 1 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH1      4
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH1      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH1(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH1)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH1(v)   (((v) << 4) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH1 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH1(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF1, CH1, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF1, field CH2 (RW)
 *
 * This field is used to set the buffer size for channel 2. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 2 buffer size is 1Dword
 * 0001 - channel 2 buffer size is 2Dwords
 * 0010 - channel 2 buffer size is 4Dwords
 * 0011 - channel 2 buffer size is 8Dwords
 * 0100 - channel 2 buffer size is 16Dwords
 * 0101 - channel 2 buffer size is 32Dwords
 * 0110 - channel 2 buffer size is 64Dwords
 * 0111 - channel 2 buffer size is 128Dwords
 * 1000 - channel 2 buffer size is 256Dwords
 * 1001 - channel 2 buffer size is 512Dwords
 * 1010 - channel 2 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH2      8
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH2      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH2(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH2)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH2(v)   (((v) << 8) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH2 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH2(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF1, CH2, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF1, field CH3 (RW)
 *
 * This field is used to set the buffer size for channel 3. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 3 buffer size is 1Dword
 * 0001 - channel 3 buffer size is 2Dwords
 * 0010 - channel 3 buffer size is 4Dwords
 * 0011 - channel 3 buffer size is 8Dwords
 * 0100 - channel 3 buffer size is 16Dwords
 * 0101 - channel 3 buffer size is 32Dwords
 * 0110 - channel 3 buffer size is 64Dwords
 * 0111 - channel 3 buffer size is 128Dwords
 * 1000 - channel 3 buffer size is 256Dwords
 * 1001 - channel 3 buffer size is 512Dwords
 * 1010 - channel 3 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH3      12
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH3      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH3(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH3)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH3(v)   (((v) << 12) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH3 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH3(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF1, CH3, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF1, field CH4 (RW)
 *
 * This field is used to set the buffer size for channel 4. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 4 buffer size is 1Dword
 * 0001 - channel 4 buffer size is 2Dwords
 * 0010 - channel 4 buffer size is 4Dwords
 * 0011 - channel 4 buffer size is 8Dwords
 * 0100 - channel 4 buffer size is 16Dwords
 * 0101 - channel 4 buffer size is 32Dwords
 * 0110 - channel 4 buffer size is 64Dwords
 * 0111 - channel 4 buffer size is 128Dwords
 * 1000 - channel 4 buffer size is 256Dwords
 * 1001 - channel 4 buffer size is 512Dwords
 * 1010 - channel 4 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH4      16
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH4      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH4(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH4)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH4(v)   (((v) << 16) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH4 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH4(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF1, CH4, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF1, field CH5 (RW)
 *
 * This field is used to set the buffer size for channel 5. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 5 buffer size is 1Dword
 * 0001 - channel 5 buffer size is 2Dwords
 * 0010 - channel 5 buffer size is 4Dwords
 * 0011 - channel 5 buffer size is 8Dwords
 * 0100 - channel 5 buffer size is 16Dwords
 * 0101 - channel 5 buffer size is 32Dwords
 * 0110 - channel 5 buffer size is 64Dwords
 * 0111 - channel 5 buffer size is 128Dwords
 * 1000 - channel 5 buffer size is 256Dwords
 * 1001 - channel 5 buffer size is 512Dwords
 * 1010 - channel 5 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH5      20
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH5      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH5(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH5)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH5(v)   (((v) << 20) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH5 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH5(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF1, CH5, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF1, field CH6 (RW)
 *
 * This field is used to set the buffer size for channel 6. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 6 buffer size is 1Dword
 * 0001 - channel 6 buffer size is 2Dwords
 * 0010 - channel 6 buffer size is 4Dwords
 * 0011 - channel 6 buffer size is 8Dwords
 * 0100 - channel 6 buffer size is 16Dwords
 * 0101 - channel 6 buffer size is 32Dwords
 * 0110 - channel 6 buffer size is 64Dwords
 * 0111 - channel 6 buffer size is 128Dwords
 * 1000 - channel 6 buffer size is 256Dwords
 * 1001 - channel 6 buffer size is 512Dwords
 * 1010 - channel 6 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH6      24
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH6      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH6(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH6)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH6(v)   (((v) << 24) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH6 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH6(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF1, CH6, v)
#endif


/* --- Register HW_MIPI_HSI_TX_FIFO_SIZE_CONF1, field CH7 (RW)
 *
 * This field is used to set the buffer size for channel 7. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 7 buffer size is 1Dword
 * 0001 - channel 7 buffer size is 2Dwords
 * 0010 - channel 7 buffer size is 4Dwords
 * 0011 - channel 7 buffer size is 8Dwords
 * 0100 - channel 7 buffer size is 16Dwords
 * 0101 - channel 7 buffer size is 32Dwords
 * 0110 - channel 7 buffer size is 64Dwords
 * 0111 - channel 7 buffer size is 128Dwords
 * 1000 - channel 7 buffer size is 256Dwords
 * 1001 - channel 7 buffer size is 512Dwords
 * 1010 - channel 7 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH7      28
#define BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH7      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH7(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH7)
#else
#define BF_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH7(v)   (((v) << 28) & BM_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH7 field to a new value.
#define BW_MIPI_HSI_TX_FIFO_SIZE_CONF1_CH7(v)   BF_CS1(MIPI_HSI_TX_FIFO_SIZE_CONF1, CH7, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_RX_FIFO_SIZE_CONF0 - Rx Fifo Size Configuration Register 0 (RW)
 *
 * This register is used to config each Rx fifo size
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH8 : 4; //!< This field is used to set the buffer size for channel 8. All the allowed combinations of bit setting are listed here .
        unsigned CH9 : 4; //!< This field is used to set the buffer size for channel 9. All the allowed combinations of bit setting are listed here .
        unsigned CH10 : 4; //!< This field is used to set the buffer size for channel 10. All the allowed combinations of bit setting are listed here .
        unsigned CH11 : 4; //!< This field is used to set the buffer size for channel 11. All the allowed combinations of bit setting are listed here .
        unsigned CH12 : 4; //!< This field is used to set the buffer size for channel 12. All the allowed combinations of bit setting are listed here .
        unsigned CH13 : 4; //!< This field is used to set the buffer size for channel 13. All the allowed combinations of bit setting are listed here .
        unsigned CH14 : 4; //!< This field is used to set the buffer size for channel 14. All the allowed combinations of bit setting are listed here .
        unsigned CH15 : 4; //!< This field is used to set the buffer size for channel 15. All the allowed combinations of bit setting are listed here .
    } B;
} hw_mipi_hsi_rx_fifo_size_conf0_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_RX_FIFO_SIZE_CONF0 register
 */
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_ADDR      (REGS_MIPI_HSI_BASE + 0x208)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF0           (*(volatile hw_mipi_hsi_rx_fifo_size_conf0_t *) HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_ADDR)
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_RD()      (HW_MIPI_HSI_RX_FIFO_SIZE_CONF0.U)
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_WR(v)     (HW_MIPI_HSI_RX_FIFO_SIZE_CONF0.U = (v))
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_SET(v)    (HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_WR(HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_RD() |  (v)))
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CLR(v)    (HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_WR(HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_RD() & ~(v)))
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_TOG(v)    (HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_WR(HW_MIPI_HSI_RX_FIFO_SIZE_CONF0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_RX_FIFO_SIZE_CONF0 bitfields
 */

/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF0, field CH8 (RW)
 *
 * This field is used to set the buffer size for channel 8. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 8 buffer size is 1Dword
 * 0001 - channel 8 buffer size is 2Dwords
 * 0010 - channel 8 buffer size is 4Dwords
 * 0011 - channel 8 buffer size is 8Dwords
 * 0100 - channel 8 buffer size is 16Dwords
 * 0101 - channel 8 buffer size is 32Dwords
 * 0110 - channel 8 buffer size is 64Dwords
 * 0111 - channel 8 buffer size is 128Dwords
 * 1000 - channel 8 buffer size is 256Dwords
 * 1001 - channel 8 buffer size is 512Dwords
 * 1010 - channel 8 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH8      0
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH8      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH8(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH8)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH8(v)   (((v) << 0) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH8 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH8(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF0, CH8, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF0, field CH9 (RW)
 *
 * This field is used to set the buffer size for channel 9. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 9 buffer size is 1Dword
 * 0001 - channel 9 buffer size is 2Dwords
 * 0010 - channel 9 buffer size is 4Dwords
 * 0011 - channel 9 buffer size is 8Dwords
 * 0100 - channel 9 buffer size is 16Dwords
 * 0101 - channel 9 buffer size is 32Dwords
 * 0110 - channel 9 buffer size is 64Dwords
 * 0111 - channel 9 buffer size is 128Dwords
 * 1000 - channel 9 buffer size is 256Dwords
 * 1001 - channel 9 buffer size is 512Dwords
 * 1010 - channel 9 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH9      4
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH9      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH9(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH9)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH9(v)   (((v) << 4) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH9 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH9(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF0, CH9, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF0, field CH10 (RW)
 *
 * This field is used to set the buffer size for channel 10. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 10 buffer size is 1Dword
 * 0001 - channel 10 buffer size is 2Dwords
 * 0010 - channel 10 buffer size is 4Dwords
 * 0011 - channel 10 buffer size is 8Dwords
 * 0100 - channel 10 buffer size is 16Dwords
 * 0101 - channel 10 buffer size is 32Dwords
 * 0110 - channel 10 buffer size is 64Dwords
 * 0111 - channel 10 buffer size is 128Dwords
 * 1000 - channel 10 buffer size is 256Dwords
 * 1001 - channel 10 buffer size is 512Dwords
 * 1010 - channel 10 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH10      8
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH10      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH10(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH10)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH10(v)   (((v) << 8) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH10 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH10(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF0, CH10, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF0, field CH11 (RW)
 *
 * This field is used to set the buffer size for channel 11. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 11 buffer size is 1Dword
 * 0001 - channel 11 buffer size is 2Dwords
 * 0010 - channel 11 buffer size is 4Dwords
 * 0011 - channel 11 buffer size is 8Dwords
 * 0100 - channel 11 buffer size is 16Dwords
 * 0101 - channel 11 buffer size is 32Dwords
 * 0110 - channel 11 buffer size is 64Dwords
 * 0111 - channel 11 buffer size is 128Dwords
 * 1000 - channel 11 buffer size is 256Dwords
 * 1001 - channel 11 buffer size is 512Dwords
 * 1010 - channel 11 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH11      12
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH11      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH11(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH11)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH11(v)   (((v) << 12) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH11 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH11(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF0, CH11, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF0, field CH12 (RW)
 *
 * This field is used to set the buffer size for channel 12. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 12 buffer size is 1Dword
 * 0001 - channel 12 buffer size is 2Dwords
 * 0010 - channel 12 buffer size is 4Dwords
 * 0011 - channel 12 buffer size is 8Dwords
 * 0100 - channel 12 buffer size is 16Dwords
 * 0101 - channel 12 buffer size is 32Dwords
 * 0110 - channel 12 buffer size is 64Dwords
 * 0111 - channel 12 buffer size is 128Dwords
 * 1000 - channel 12 buffer size is 256Dwords
 * 1001 - channel 12 buffer size is 512Dwords
 * 1010 - channel 12 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH12      16
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH12      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH12(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH12)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH12(v)   (((v) << 16) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH12 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH12(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF0, CH12, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF0, field CH13 (RW)
 *
 * This field is used to set the buffer size for channel 13. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 13 buffer size is 1Dword
 * 0001 - channel 13 buffer size is 2Dwords
 * 0010 - channel 13 buffer size is 4Dwords
 * 0011 - channel 13 buffer size is 8Dwords
 * 0100 - channel 13 buffer size is 16Dwords
 * 0101 - channel 13 buffer size is 32Dwords
 * 0110 - channel 13 buffer size is 64Dwords
 * 0111 - channel 13 buffer size is 128Dwords
 * 1000 - channel 13 buffer size is 256Dwords
 * 1001 - channel 13 buffer size is 512Dwords
 * 1010 - channel 13 buffer size is 1024Dwords
 * 1111 - b1011 Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH13      20
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH13      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH13(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH13)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH13(v)   (((v) << 20) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH13 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH13(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF0, CH13, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF0, field CH14 (RW)
 *
 * This field is used to set the buffer size for channel 14. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 14 buffer size is 1Dword
 * 0001 - channel 14 buffer size is 2Dwords
 * 0010 - channel 14 buffer size is 4Dwords
 * 0011 - channel 14 buffer size is 8Dwords
 * 0100 - channel 14 buffer size is 16Dwords
 * 0101 - channel 14 buffer size is 32Dwords
 * 0110 - channel 14 buffer size is 64Dwords
 * 0111 - channel 14 buffer size is 128Dwords
 * 1000 - channel 14 buffer size is 256Dwords
 * 1001 - channel 14 buffer size is 512Dwords
 * 1010 - channel 14 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH14      24
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH14      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH14(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH14)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH14(v)   (((v) << 24) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH14 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH14(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF0, CH14, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF0, field CH15 (RW)
 *
 * This field is used to set the buffer size for channel 15. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 15 buffer size is 1Dword
 * 0001 - channel 15 buffer size is 2Dwords
 * 0010 - channel 15 buffer size is 4Dwords
 * 0011 - channel 15 buffer size is 8Dwords
 * 0100 - channel 15 buffer size is 16Dwords
 * 0101 - channel 15 buffer size is 32Dwords
 * 0110 - channel 15 buffer size is 64Dwords
 * 0111 - channel 15 buffer size is 128Dwords
 * 1000 - channel 15 buffer size is 256Dwords
 * 1001 - channel 15 buffer size is 512Dwords
 * 1010 - channel 15 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH15      28
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH15      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH15(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH15)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH15(v)   (((v) << 28) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH15 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF0_CH15(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF0, CH15, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_RX_FIFO_SIZE_CONF1 - Rx Fifo Size Configuration Register 1 (RW)
 *
 * This register is used to config each Rx fifo size
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH0 : 4; //!< This field is used to set the buffer size for channel 0. All the allowed combinations of bit setting are listed here .
        unsigned CH1 : 4; //!< This field is used to set the buffer size for channel 1. All the allowed combinations of bit setting are listed here .
        unsigned CH2 : 4; //!< This field is used to set the buffer size for channel 2. All the allowed combinations of bit setting are listed here .
        unsigned CH3 : 4; //!< This field is used to set the buffer size for channel 3. All the allowed combinations of bit setting are listed here .
        unsigned CH4 : 4; //!< This field is used to set the buffer size for channel 4. All the allowed combinations of bit setting are listed here .
        unsigned CH5 : 4; //!< This field is used to set the buffer size for channel 5. All the allowed combinations of bit setting are listed here .
        unsigned CH6 : 4; //!< This field is used to set the buffer size for channel 6. All the allowed combinations of bit setting are listed here .
        unsigned CH7 : 4; //!< This field is used to set the buffer size for channel 7. All the allowed combinations of bit setting are listed here .
    } B;
} hw_mipi_hsi_rx_fifo_size_conf1_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_RX_FIFO_SIZE_CONF1 register
 */
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_ADDR      (REGS_MIPI_HSI_BASE + 0x20c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF1           (*(volatile hw_mipi_hsi_rx_fifo_size_conf1_t *) HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_ADDR)
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_RD()      (HW_MIPI_HSI_RX_FIFO_SIZE_CONF1.U)
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_WR(v)     (HW_MIPI_HSI_RX_FIFO_SIZE_CONF1.U = (v))
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_SET(v)    (HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_WR(HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_RD() |  (v)))
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CLR(v)    (HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_WR(HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_RD() & ~(v)))
#define HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_TOG(v)    (HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_WR(HW_MIPI_HSI_RX_FIFO_SIZE_CONF1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_RX_FIFO_SIZE_CONF1 bitfields
 */

/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF1, field CH0 (RW)
 *
 * This field is used to set the buffer size for channel 0. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 0 buffer size is 1Dword
 * 0001 - channel 0 buffer size is 2Dwords
 * 0010 - channel 0 buffer size is 4Dwords
 * 0011 - channel 0 buffer size is 8Dwords
 * 0100 - channel 0 buffer size is 16Dwords
 * 0101 - channel 0 buffer size is 32Dwords
 * 0110 - channel 0 buffer size is 64Dwords
 * 0111 - channel 0 buffer size is 128Dwords
 * 1000 - channel 0 buffer size is 256Dwords
 * 1001 - channel 0 buffer size is 512Dwords
 * 1010 - channel 0 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH0      0
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH0      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH0(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH0)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH0(v)   (((v) << 0) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH0(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF1, CH0, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF1, field CH1 (RW)
 *
 * This field is used to set the buffer size for channel 1. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 1 buffer size is 1Dword
 * 0001 - channel 1 buffer size is 2Dwords
 * 0010 - channel 1 buffer size is 4Dwords
 * 0011 - channel 1 buffer size is 8Dwords
 * 0100 - channel 1 buffer size is 16Dwords
 * 0101 - channel 1 buffer size is 32Dwords
 * 0110 - channel 1 buffer size is 64Dwords
 * 0111 - channel 1 buffer size is 128Dwords
 * 1000 - channel 1 buffer size is 256Dwords
 * 1001 - channel 1 buffer size is 512Dwords
 * 1010 - channel 1 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH1      4
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH1      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH1(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH1)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH1(v)   (((v) << 4) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH1 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH1(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF1, CH1, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF1, field CH2 (RW)
 *
 * This field is used to set the buffer size for channel 2. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 2 buffer size is 1Dword
 * 0001 - channel 2 buffer size is 2Dwords
 * 0010 - channel 2 buffer size is 4Dwords
 * 0011 - channel 2 buffer size is 8Dwords
 * 0100 - channel 2 buffer size is 16Dwords
 * 0101 - channel 2 buffer size is 32Dwords
 * 0110 - channel 2 buffer size is 64Dwords
 * 0111 - channel 2 buffer size is 128Dwords
 * 1000 - channel 2 buffer size is 256Dwords
 * 1001 - channel 2 buffer size is 512Dwords
 * 1010 - channel 2 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH2      8
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH2      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH2(v)   ((((reg32_t) v) << 8) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH2)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH2(v)   (((v) << 8) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH2 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH2(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF1, CH2, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF1, field CH3 (RW)
 *
 * This field is used to set the buffer size for channel 3. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 3 buffer size is 1Dword
 * 0001 - channel 3 buffer size is 2Dwords
 * 0010 - channel 3 buffer size is 4Dwords
 * 0011 - channel 3 buffer size is 8Dwords
 * 0100 - channel 3 buffer size is 16Dwords
 * 0101 - channel 3 buffer size is 32Dwords
 * 0110 - channel 3 buffer size is 64Dwords
 * 0111 - channel 3 buffer size is 128Dwords
 * 1000 - channel 3 buffer size is 256Dwords
 * 1001 - channel 3 buffer size is 512Dwords
 * 1010 - channel 3 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH3      12
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH3      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH3(v)   ((((reg32_t) v) << 12) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH3)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH3(v)   (((v) << 12) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH3 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH3(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF1, CH3, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF1, field CH4 (RW)
 *
 * This field is used to set the buffer size for channel 4. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 4 buffer size is 1Dword
 * 0001 - channel 4 buffer size is 2Dwords
 * 0010 - channel 4 buffer size is 4Dwords
 * 0011 - channel 4 buffer size is 8Dwords
 * 0100 - channel 4 buffer size is 16Dwords
 * 0101 - channel 4 buffer size is 32Dwords
 * 0110 - channel 4 buffer size is 64Dwords
 * 0111 - channel 4 buffer size is 128Dwords
 * 1000 - channel 4 buffer size is 256Dwords
 * 1001 - channel 4 buffer size is 512Dwords
 * 1010 - channel 4 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH4      16
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH4      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH4(v)   ((((reg32_t) v) << 16) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH4)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH4(v)   (((v) << 16) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH4 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH4(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF1, CH4, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF1, field CH5 (RW)
 *
 * This field is used to set the buffer size for channel 5. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 5 buffer size is 1Dword
 * 0001 - channel 5 buffer size is 2Dwords
 * 0010 - channel 5 buffer size is 4Dwords
 * 0011 - channel 5 buffer size is 8Dwords
 * 0100 - channel 5 buffer size is 16Dwords
 * 0101 - channel 5 buffer size is 32Dwords
 * 0110 - channel 5 buffer size is 64Dwords
 * 0111 - channel 5 buffer size is 128Dwords
 * 1000 - channel 5 buffer size is 256Dwords
 * 1001 - channel 5 buffer size is 512Dwords
 * 1010 - channel 5 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH5      20
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH5      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH5(v)   ((((reg32_t) v) << 20) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH5)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH5(v)   (((v) << 20) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH5 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH5(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF1, CH5, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF1, field CH6 (RW)
 *
 * This field is used to set the buffer size for channel 6. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 6 buffer size is 1Dword
 * 0001 - channel 6 buffer size is 2Dwords
 * 0010 - channel 6 buffer size is 4Dwords
 * 0011 - channel 6 buffer size is 8Dwords
 * 0100 - channel 6 buffer size is 16Dwords
 * 0101 - channel 6 buffer size is 32Dwords
 * 0110 - channel 6 buffer size is 64Dwords
 * 0111 - channel 6 buffer size is 128Dwords
 * 1000 - channel 6 buffer size is 256Dwords
 * 1001 - channel 6 buffer size is 512Dwords
 * 1010 - channel 6 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH6      24
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH6      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH6(v)   ((((reg32_t) v) << 24) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH6)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH6(v)   (((v) << 24) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH6 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH6(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF1, CH6, v)
#endif


/* --- Register HW_MIPI_HSI_RX_FIFO_SIZE_CONF1, field CH7 (RW)
 *
 * This field is used to set the buffer size for channel 7. All the allowed combinations of bit
 * setting are listed here .
 *
 * Values:
 * 0000 - channel 7 buffer size is 1Dword
 * 0001 - channel 7 buffer size is 2Dwords
 * 0010 - channel 7 buffer size is 4Dwords
 * 0011 - channel 7 buffer size is 8Dwords
 * 0100 - channel 7 buffer size is 16Dwords
 * 0101 - channel 7 buffer size is 32Dwords
 * 0110 - channel 7 buffer size is 64Dwords
 * 0111 - channel 7 buffer size is 128Dwords
 * 1000 - channel 7 buffer size is 256Dwords
 * 1001 - channel 7 buffer size is 512Dwords
 * 1010 - channel 7 buffer size is 1024Dwords
 * 1111-1011 - Reserved
 */

#define BP_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH7      28
#define BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH7      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH7(v)   ((((reg32_t) v) << 28) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH7)
#else
#define BF_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH7(v)   (((v) << 28) & BM_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH7 field to a new value.
#define BW_MIPI_HSI_RX_FIFO_SIZE_CONF1_CH7(v)   BF_CS1(MIPI_HSI_RX_FIFO_SIZE_CONF1, CH7, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_FIFO_STAT - Tx Fifo Status Register (RO)
 *
 * This register containts full and empty status for each Tx channel fifo
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH0 : 2; //!< 
        unsigned CH1 : 2; //!< 
        unsigned CH2 : 2; //!< 
        unsigned CH3 : 2; //!< 
        unsigned CH4 : 2; //!< 
        unsigned CH5 : 2; //!< 
        unsigned CH6 : 2; //!< 
        unsigned CH7 : 2; //!< 
        unsigned CH8 : 2; //!< 
        unsigned CH9 : 2; //!< 
        unsigned CH10 : 2; //!< 
        unsigned CH11 : 2; //!< 
        unsigned CH12 : 2; //!< 
        unsigned CH13 : 2; //!< 
        unsigned CH14 : 2; //!< 
        unsigned CH15 : 2; //!< 
    } B;
} hw_mipi_hsi_tx_fifo_stat_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_FIFO_STAT register
 */
#define HW_MIPI_HSI_TX_FIFO_STAT_ADDR      (REGS_MIPI_HSI_BASE + 0x210)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_FIFO_STAT           (*(volatile hw_mipi_hsi_tx_fifo_stat_t *) HW_MIPI_HSI_TX_FIFO_STAT_ADDR)
#define HW_MIPI_HSI_TX_FIFO_STAT_RD()      (HW_MIPI_HSI_TX_FIFO_STAT.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_FIFO_STAT bitfields
 */

/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH0 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 0 fifo not Empty and Full;
 * 01 - Tx channel 0 fifo Empty;
 * 10 - Tx channel 0 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH0      0
#define BM_MIPI_HSI_TX_FIFO_STAT_CH0      0x00000003


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH1 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 1 fifo not Empty and Full;
 * 01 - Tx channel 1 fifo Empty;
 * 10 - Tx channel 1 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH1      2
#define BM_MIPI_HSI_TX_FIFO_STAT_CH1      0x0000000c


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH2 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 2 fifo not Empty and Full;
 * 01 - Tx channel 2 fifo Empty;
 * 10 - Tx channel 2 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH2      4
#define BM_MIPI_HSI_TX_FIFO_STAT_CH2      0x00000030


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH3 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 3 fifo not Empty and Full;
 * 01 - Tx channel 3 fifo Empty;
 * 10 - Tx channel 3 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH3      6
#define BM_MIPI_HSI_TX_FIFO_STAT_CH3      0x000000c0


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH4 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 4 fifo not Empty and Full;
 * 01 - Tx channel 4 fifo Empty;
 * 10 - Tx channel 4 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH4      8
#define BM_MIPI_HSI_TX_FIFO_STAT_CH4      0x00000300


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH5 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 5 fifo not Empty and Full;
 * 01 - Tx channel 5 fifo Empty;
 * 10 - Tx channel 5 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH5      10
#define BM_MIPI_HSI_TX_FIFO_STAT_CH5      0x00000c00


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH6 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 6 fifo not Empty and Full;
 * 01 - Tx channel 6 fifo Empty;
 * 10 - Tx channel 6 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH6      12
#define BM_MIPI_HSI_TX_FIFO_STAT_CH6      0x00003000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH7 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 7 fifo not Empty and Full;
 * 01 - Tx channel 7 fifo Empty;
 * 10 - Tx channel 7 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH7      14
#define BM_MIPI_HSI_TX_FIFO_STAT_CH7      0x0000c000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH8 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 8 fifo not Empty and Full;
 * 01 - Tx channel 8 fifo Empty;
 * 10 - Tx channel 8 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH8      16
#define BM_MIPI_HSI_TX_FIFO_STAT_CH8      0x00030000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH9 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 9 fifo not Empty and Full;
 * 01 - Tx channel 9 fifo Empty;
 * 10 - Tx channel 9 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH9      18
#define BM_MIPI_HSI_TX_FIFO_STAT_CH9      0x000c0000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH10 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 10 fifo not Empty and Full;
 * 01 - Tx channel 10 fifo Empty;
 * 10 - Tx channel 10 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH10      20
#define BM_MIPI_HSI_TX_FIFO_STAT_CH10      0x00300000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH11 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 11 fifo not Empty and Full;
 * 01 - Tx channel 11 fifo Empty;
 * 10 - Tx channel 11 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH11      22
#define BM_MIPI_HSI_TX_FIFO_STAT_CH11      0x00c00000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH12 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 12 fifo not Empty and Full;
 * 01 - Tx channel 12 fifo Empty;
 * 10 - Tx channel 12 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH12      24
#define BM_MIPI_HSI_TX_FIFO_STAT_CH12      0x03000000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH13 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 13 fifo not Empty and Full;
 * 01 - Tx channel 13 fifo Empty;
 * 10 - Tx channel 13 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH13      26
#define BM_MIPI_HSI_TX_FIFO_STAT_CH13      0x0c000000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH14 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 14 fifo not Empty and Full;
 * 01 - Tx channel 14 fifo Empty;
 * 10 - Tx channel 14 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH14      28
#define BM_MIPI_HSI_TX_FIFO_STAT_CH14      0x30000000


/* --- Register HW_MIPI_HSI_TX_FIFO_STAT, field CH15 (RO)
 *

 *
 * Values:
 * 00 - Tx channel 15 fifo not Empty and Full;
 * 01 - Tx channel 15 fifo Empty;
 * 10 - Tx channel 15 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_TX_FIFO_STAT_CH15      30
#define BM_MIPI_HSI_TX_FIFO_STAT_CH15      0xc0000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_RX_FIFO_STAT - Rx Fifo Status Register (RO)
 *
 * This register containts full and empty status for each Rx channel fifo
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CH0 : 2; //!< 
        unsigned CH1 : 2; //!< 
        unsigned CH2 : 2; //!< 
        unsigned CH3 : 2; //!< 
        unsigned CH4 : 2; //!< 
        unsigned CH5 : 2; //!< 
        unsigned CH6 : 2; //!< 
        unsigned CH7 : 2; //!< 
        unsigned CH8 : 2; //!< 
        unsigned CH9 : 2; //!< 
        unsigned CH10 : 2; //!< 
        unsigned CH11 : 2; //!< 
        unsigned CH12 : 2; //!< 
        unsigned CH13 : 2; //!< 
        unsigned CH14 : 2; //!< 
        unsigned CH15 : 2; //!< 
    } B;
} hw_mipi_hsi_rx_fifo_stat_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_RX_FIFO_STAT register
 */
#define HW_MIPI_HSI_RX_FIFO_STAT_ADDR      (REGS_MIPI_HSI_BASE + 0x214)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_RX_FIFO_STAT           (*(volatile hw_mipi_hsi_rx_fifo_stat_t *) HW_MIPI_HSI_RX_FIFO_STAT_ADDR)
#define HW_MIPI_HSI_RX_FIFO_STAT_RD()      (HW_MIPI_HSI_RX_FIFO_STAT.U)
#endif

/*
 * constants & macros for individual MIPI_HSI_RX_FIFO_STAT bitfields
 */

/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH0 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 0 fifo not Empty and Full;
 * 01 - Rx channel 0 fifo Empty;
 * 10 - Rx channel 0 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH0      0
#define BM_MIPI_HSI_RX_FIFO_STAT_CH0      0x00000003


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH1 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 1 fifo not Empty and Full;
 * 01 - Rx channel 1 fifo Empty;
 * 10 - Rx channel 1 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH1      2
#define BM_MIPI_HSI_RX_FIFO_STAT_CH1      0x0000000c


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH2 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 2 fifo not Empty and Full;
 * 01 - Rx channel 2 fifo Empty;
 * 10 - Rx channel 2 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH2      4
#define BM_MIPI_HSI_RX_FIFO_STAT_CH2      0x00000030


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH3 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 3 fifo not Empty and Full;
 * 01 - Rx channel 3 fifo Empty;
 * 10 - Rx channel 3 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH3      6
#define BM_MIPI_HSI_RX_FIFO_STAT_CH3      0x000000c0


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH4 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 4 fifo not Empty and Full;
 * 01 - Rx channel 4 fifo Empty;
 * 10 - Rx channel 4 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH4      8
#define BM_MIPI_HSI_RX_FIFO_STAT_CH4      0x00000300


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH5 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 5 fifo not Empty and Full;
 * 01 - Rx channel 5 fifo Empty;
 * 10 - Rx channel 5 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH5      10
#define BM_MIPI_HSI_RX_FIFO_STAT_CH5      0x00000c00


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH6 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 6 fifo not Empty and Full;
 * 01 - Rx channel 6 fifo Empty;
 * 10 - Rx channel 6 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH6      12
#define BM_MIPI_HSI_RX_FIFO_STAT_CH6      0x00003000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH7 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 7 fifo not Empty and Full;
 * 01 - Rx channel 7 fifo Empty;
 * 10 - Rx channel 7 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH7      14
#define BM_MIPI_HSI_RX_FIFO_STAT_CH7      0x0000c000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH8 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 8 fifo not Empty and Full;
 * 01 - Rx channel 8 fifo Empty;
 * 10 - Rx channel 8 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH8      16
#define BM_MIPI_HSI_RX_FIFO_STAT_CH8      0x00030000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH9 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 9 fifo not Empty and Full;
 * 01 - Rx channel 9 fifo Empty;
 * 10 - Rx channel 9 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH9      18
#define BM_MIPI_HSI_RX_FIFO_STAT_CH9      0x000c0000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH10 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 10 fifo not Empty and Full;
 * 01 - Rx channel 10 fifo Empty;
 * 10 - Rx channel 10 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH10      20
#define BM_MIPI_HSI_RX_FIFO_STAT_CH10      0x00300000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH11 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 11 fifo not Empty and Full;
 * 01 - Rx channel 11 fifo Empty;
 * 10 - Rx channel 11 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH11      22
#define BM_MIPI_HSI_RX_FIFO_STAT_CH11      0x00c00000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH12 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 12 fifo not Empty and Full;
 * 01 - Rx channel 12 fifo Empty;
 * 10 - Rx channel 12 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH12      24
#define BM_MIPI_HSI_RX_FIFO_STAT_CH12      0x03000000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH13 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 13 fifo not Empty and Full;
 * 01 - Rx channel 13 fifo Empty;
 * 10 - Rx channel 13 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH13      26
#define BM_MIPI_HSI_RX_FIFO_STAT_CH13      0x0c000000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH14 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 14 fifo not Empty and Full;
 * 01 - Rx channel 14 fifo Empty;
 * 10 - Rx channel 14 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH14      28
#define BM_MIPI_HSI_RX_FIFO_STAT_CH14      0x30000000


/* --- Register HW_MIPI_HSI_RX_FIFO_STAT, field CH15 (RO)
 *

 *
 * Values:
 * 00 - Rx channel 15 fifo not Empty and Full;
 * 01 - Rx channel 15 fifo Empty;
 * 10 - Rx channel 15 fifo Full;
 * 11 - Reserved.
 */

#define BP_MIPI_HSI_RX_FIFO_STAT_CH15      30
#define BM_MIPI_HSI_RX_FIFO_STAT_CH15      0xc0000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_AHB_MASTER_CONF - Ahb Master Config Register (RW)
 *
 * This register used to config hsi internal ahb master
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DMA_INSERT_IDLE_NUM : 4; //!< These bits used to set the number of "IDLE" cycles when DMA_MODE == 2'b0x.
        unsigned DMA_MODE : 2; //!< 
        unsigned DP_HOLD_CYCLE : 4; //!< These bits used to set the number of cycles for DP access fifo.
        unsigned RESERVED : 22; //!< Reserved, always set to zero.
    } B;
} hw_mipi_hsi_ahb_master_conf_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_AHB_MASTER_CONF register
 */
#define HW_MIPI_HSI_AHB_MASTER_CONF_ADDR      (REGS_MIPI_HSI_BASE + 0x228)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_AHB_MASTER_CONF           (*(volatile hw_mipi_hsi_ahb_master_conf_t *) HW_MIPI_HSI_AHB_MASTER_CONF_ADDR)
#define HW_MIPI_HSI_AHB_MASTER_CONF_RD()      (HW_MIPI_HSI_AHB_MASTER_CONF.U)
#define HW_MIPI_HSI_AHB_MASTER_CONF_WR(v)     (HW_MIPI_HSI_AHB_MASTER_CONF.U = (v))
#define HW_MIPI_HSI_AHB_MASTER_CONF_SET(v)    (HW_MIPI_HSI_AHB_MASTER_CONF_WR(HW_MIPI_HSI_AHB_MASTER_CONF_RD() |  (v)))
#define HW_MIPI_HSI_AHB_MASTER_CONF_CLR(v)    (HW_MIPI_HSI_AHB_MASTER_CONF_WR(HW_MIPI_HSI_AHB_MASTER_CONF_RD() & ~(v)))
#define HW_MIPI_HSI_AHB_MASTER_CONF_TOG(v)    (HW_MIPI_HSI_AHB_MASTER_CONF_WR(HW_MIPI_HSI_AHB_MASTER_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_AHB_MASTER_CONF bitfields
 */

/* --- Register HW_MIPI_HSI_AHB_MASTER_CONF, field DMA_INSERT_IDLE_NUM (RW)
 *
 * These bits used to set the number of "IDLE" cycles when DMA_MODE == 2'b0x.
 */

#define BP_MIPI_HSI_AHB_MASTER_CONF_DMA_INSERT_IDLE_NUM      0
#define BM_MIPI_HSI_AHB_MASTER_CONF_DMA_INSERT_IDLE_NUM      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_AHB_MASTER_CONF_DMA_INSERT_IDLE_NUM(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_AHB_MASTER_CONF_DMA_INSERT_IDLE_NUM)
#else
#define BF_MIPI_HSI_AHB_MASTER_CONF_DMA_INSERT_IDLE_NUM(v)   (((v) << 0) & BM_MIPI_HSI_AHB_MASTER_CONF_DMA_INSERT_IDLE_NUM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_INSERT_IDLE_NUM field to a new value.
#define BW_MIPI_HSI_AHB_MASTER_CONF_DMA_INSERT_IDLE_NUM(v)   BF_CS1(MIPI_HSI_AHB_MASTER_CONF, DMA_INSERT_IDLE_NUM, v)
#endif

/* --- Register HW_MIPI_HSI_AHB_MASTER_CONF, field DMA_MODE (RW)
 *

 *
 * Values:
 * 00 - Once AHB master get hgrant from bus, it will set htrans "IDLE" for serval ahb cycles.In the serval
 *     cycles, once it found dataport is accessing fifo, it will release bus.
 * 01 - Once AHB master get hgrant from bus, it will set htrans "IDLE" for serval ahb cycles.After the
 *     serval cycles, once it found dataport is accessing fifo, it will keep on sending "IDLE" out
 *     untill dataport finish accessing fifo.
 * 1x - Once AHB master get hgrant from bus, dataport can not access fifo untill a dma operation done.
 */

#define BP_MIPI_HSI_AHB_MASTER_CONF_DMA_MODE      4
#define BM_MIPI_HSI_AHB_MASTER_CONF_DMA_MODE      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_AHB_MASTER_CONF_DMA_MODE(v)   ((((reg32_t) v) << 4) & BM_MIPI_HSI_AHB_MASTER_CONF_DMA_MODE)
#else
#define BF_MIPI_HSI_AHB_MASTER_CONF_DMA_MODE(v)   (((v) << 4) & BM_MIPI_HSI_AHB_MASTER_CONF_DMA_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_MODE field to a new value.
#define BW_MIPI_HSI_AHB_MASTER_CONF_DMA_MODE(v)   BF_CS1(MIPI_HSI_AHB_MASTER_CONF, DMA_MODE, v)
#endif


/* --- Register HW_MIPI_HSI_AHB_MASTER_CONF, field DP_HOLD_CYCLE (RW)
 *
 * These bits used to set the number of cycles for DP access fifo.
 */

#define BP_MIPI_HSI_AHB_MASTER_CONF_DP_HOLD_CYCLE      6
#define BM_MIPI_HSI_AHB_MASTER_CONF_DP_HOLD_CYCLE      0x000003c0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_AHB_MASTER_CONF_DP_HOLD_CYCLE(v)   ((((reg32_t) v) << 6) & BM_MIPI_HSI_AHB_MASTER_CONF_DP_HOLD_CYCLE)
#else
#define BF_MIPI_HSI_AHB_MASTER_CONF_DP_HOLD_CYCLE(v)   (((v) << 6) & BM_MIPI_HSI_AHB_MASTER_CONF_DP_HOLD_CYCLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DP_HOLD_CYCLE field to a new value.
#define BW_MIPI_HSI_AHB_MASTER_CONF_DP_HOLD_CYCLE(v)   BF_CS1(MIPI_HSI_AHB_MASTER_CONF, DP_HOLD_CYCLE, v)
#endif

/* --- Register HW_MIPI_HSI_AHB_MASTER_CONF, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_AHB_MASTER_CONF_RESERVED      10
#define BM_MIPI_HSI_AHB_MASTER_CONF_RESERVED      0xfffffc00

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_HSI_TX_BREAK_LEN - TX Break Length Register (RW)
 *
 * This register used to set tx break length
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned COUNT : 6; //!< The tx break length count. 6'h00 64 6'h01 1 6'h3f 63
        unsigned RESERVED : 26; //!< Reserved, always set to zero.
    } B;
} hw_mipi_hsi_tx_break_len_t;
#endif

/*
 * constants & macros for entire MIPI_HSI_TX_BREAK_LEN register
 */
#define HW_MIPI_HSI_TX_BREAK_LEN_ADDR      (REGS_MIPI_HSI_BASE + 0x22c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_HSI_TX_BREAK_LEN           (*(volatile hw_mipi_hsi_tx_break_len_t *) HW_MIPI_HSI_TX_BREAK_LEN_ADDR)
#define HW_MIPI_HSI_TX_BREAK_LEN_RD()      (HW_MIPI_HSI_TX_BREAK_LEN.U)
#define HW_MIPI_HSI_TX_BREAK_LEN_WR(v)     (HW_MIPI_HSI_TX_BREAK_LEN.U = (v))
#define HW_MIPI_HSI_TX_BREAK_LEN_SET(v)    (HW_MIPI_HSI_TX_BREAK_LEN_WR(HW_MIPI_HSI_TX_BREAK_LEN_RD() |  (v)))
#define HW_MIPI_HSI_TX_BREAK_LEN_CLR(v)    (HW_MIPI_HSI_TX_BREAK_LEN_WR(HW_MIPI_HSI_TX_BREAK_LEN_RD() & ~(v)))
#define HW_MIPI_HSI_TX_BREAK_LEN_TOG(v)    (HW_MIPI_HSI_TX_BREAK_LEN_WR(HW_MIPI_HSI_TX_BREAK_LEN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_HSI_TX_BREAK_LEN bitfields
 */

/* --- Register HW_MIPI_HSI_TX_BREAK_LEN, field COUNT (RW)
 *
 * The tx break length count. 6'h00 64 6'h01 1 6'h3f 63
 */

#define BP_MIPI_HSI_TX_BREAK_LEN_COUNT      0
#define BM_MIPI_HSI_TX_BREAK_LEN_COUNT      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_HSI_TX_BREAK_LEN_COUNT(v)   ((((reg32_t) v) << 0) & BM_MIPI_HSI_TX_BREAK_LEN_COUNT)
#else
#define BF_MIPI_HSI_TX_BREAK_LEN_COUNT(v)   (((v) << 0) & BM_MIPI_HSI_TX_BREAK_LEN_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_MIPI_HSI_TX_BREAK_LEN_COUNT(v)   BF_CS1(MIPI_HSI_TX_BREAK_LEN, COUNT, v)
#endif

/* --- Register HW_MIPI_HSI_TX_BREAK_LEN, field RESERVED (RU)
 *
 * Reserved, always set to zero.
 */

#define BP_MIPI_HSI_TX_BREAK_LEN_RESERVED      6
#define BM_MIPI_HSI_TX_BREAK_LEN_RESERVED      0xffffffc0


/*!
 * @brief All MIPI_HSI module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_mipi_hsi_ctrl_t CTRL; //!< HSI Control Register
    volatile hw_mipi_hsi_tx_conf_t TX_CONF; //!< HSI Tx Config Register
    volatile hw_mipi_hsi_rx_conf_t RX_CONF; //!< HSI Rx Config Register
    volatile hw_mipi_hsi_cap_t CAP; //!< HSI Capability Register
    volatile hw_mipi_hsi_tx_wml0_t TX_WML0; //!< HSI Tx Water Mark Level 0 Register
    volatile hw_mipi_hsi_tx_tml1_t TX_TML1; //!< HSI Tx Water Mark Level 1 Register
    volatile hw_mipi_hsi_tx_arb_pri0_t TX_ARB_PRI0; //!< HSI Tx Arbiter Priority 0 Register
    volatile hw_mipi_hsi_tx_arb_pri1_t TX_ARB_PRI1; //!< HSI Tx Arbiter Priority 1 Register
    volatile hw_mipi_hsi_line_st_t LINE_ST; //!< HSI Line Status Register
    volatile hw_mipi_hsi_id_bit_t ID_BIT; //!< HSI ID Bits Register
    volatile hw_mipi_hsi_fifo_thr_conf_t FIFO_THR_CONF; //!< Tx and Rx Fif0 Threshold Configuration Register
    volatile hw_mipi_hsi_ch_sftrst_t CH_SFTRST; //!< Tx and Rx Channel Soft Reset Register
    volatile hw_mipi_hsi_irqstat_t IRQSTAT; //!< HSI Interrupt Status Register
    volatile hw_mipi_hsi_irqstat_en_t IRQSTAT_EN; //!< HSI Interrupt Status Enable Register
    volatile hw_mipi_hsi_irqsig_en_t IRQSIG_EN; //!< HSI Interrupt Signal Enable Register
    volatile hw_mipi_hsi_fifo_thr_irqstat_t FIFO_THR_IRQSTAT; //!< HSI FIFO Threshold Interrupt Status Register
    volatile hw_mipi_hsi_fifo_thr_irqstat_en_t FIFO_THR_IRQSTAT_EN; //!< HSI FIFO Threshold Interrupt Status Enable Register
    volatile hw_mipi_hsi_fifo_thr_irqsig_en_t FIFO_THR_IRQSIG_EN; //!< HSI FIFO Threshold Interrupt Signal Enable Register
    reg32_t _reserved0[2];
    volatile hw_mipi_hsi_tx_ch_dp_t TX_CH_DP; //!< Tx Channel n Data Port Register
    reg32_t _reserved1[15];
    volatile hw_mipi_hsi_rx_ch_dp_t RX_CH_DP; //!< Rx Channel n Data Port Register
    reg32_t _reserved2[15];
    volatile hw_mipi_hsi_err_irqstat_t ERR_IRQSTAT; //!< HSI Error Interrupt Status Register
    volatile hw_mipi_hsi_err_irqstat_en_t ERR_IRQSTAT_EN; //!< HSI Error Interrupt Status Enable Register
    volatile hw_mipi_hsi_err_irqsig_en_t ERR_IRQSIG_EN; //!< HSI Error Interrupt Signal Enable Register
    volatile hw_mipi_hsi_tdma_conf_t TDMA_CONF; //!< Tx DMA Channel n Configuration Register
    reg32_t _reserved3[15];
    volatile hw_mipi_hsi_rdma_conf_t RDMA_CONF; //!< Rx DMA Channel n Configuration Register
    reg32_t _reserved4[15];
    volatile hw_mipi_hsi_tdma_sta_addr_t TDMA_STA_ADDR; //!< Tx DMA Channel n Start Address Register
    reg32_t _reserved5[15];
    volatile hw_mipi_hsi_rdma_sta_addr_t RDMA_STA_ADDR; //!< Rx DMA Channel n Start Address Register
    reg32_t _reserved6[15];
    volatile hw_mipi_hsi_dma_irqstat_t DMA_IRQSTAT; //!< DMA Interrupt Status Register
    volatile hw_mipi_hsi_dma_irqstat_en_t DMA_IRQSTAT_EN; //!< DMA Interrupt Enable Register
    volatile hw_mipi_hsi_dma_irqsig_en_t DMA_IRQSIG_EN; //!< DMA Interrupt Status Signal Enable Register
    volatile hw_mipi_hsi_dma_err_irqstat_t DMA_ERR_IRQSTAT; //!< DMA Error Interrupt Status Register
    volatile hw_mipi_hsi_dma_err_irqstat_en_t DMA_ERR_IRQSTAT_EN; //!< DMA Error Interrupt Enable Register
    volatile hw_mipi_hsi_dma_err_irqsig_en_t DMA_ERR_IRQSIG_EN; //!< DMA Error Interrupt Signal Enable Register
    volatile hw_mipi_hsi_dma_single_req_en_t DMA_SINGLE_REQ_EN; //!< DMA Single Request Enable Register
    reg32_t _reserved7[2];
    volatile hw_mipi_hsi_tx_fifo_size_conf0_t TX_FIFO_SIZE_CONF0; //!< Tx Fifo Size Configuration Register 0
    volatile hw_mipi_hsi_tx_fifo_size_conf1_t TX_FIFO_SIZE_CONF1; //!< Tx Fifo Size Configuration Register 1
    volatile hw_mipi_hsi_rx_fifo_size_conf0_t RX_FIFO_SIZE_CONF0; //!< Rx Fifo Size Configuration Register 0
    volatile hw_mipi_hsi_rx_fifo_size_conf1_t RX_FIFO_SIZE_CONF1; //!< Rx Fifo Size Configuration Register 1
    volatile hw_mipi_hsi_tx_fifo_stat_t TX_FIFO_STAT; //!< Tx Fifo Status Register
    volatile hw_mipi_hsi_rx_fifo_stat_t RX_FIFO_STAT; //!< Rx Fifo Status Register
    reg32_t _reserved8[4];
    volatile hw_mipi_hsi_ahb_master_conf_t AHB_MASTER_CONF; //!< Ahb Master Config Register
    volatile hw_mipi_hsi_tx_break_len_t TX_BREAK_LEN; //!< TX Break Length Register
} hw_mipi_hsi_t
#endif

//! @brief Macro to access all MIPI_HSI registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_MIPI_HSI(0)</code>.
#define HW_MIPI_HSI     (*(volatile hw_mipi_hsi_t *) REGS_MIPI_HSI_BASE)


#endif // _MIPI_HSI_H
