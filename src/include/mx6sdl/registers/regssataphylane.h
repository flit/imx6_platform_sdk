/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SATAPHY_LANE0_H
#define _SATAPHY_LANE0_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_SATAPHY_LANE0_TX_STAT - Transmit Input Status Register
 * - HW_SATAPHY_LANE0_RX_STAT - Receiver Input Status Register
 * - HW_SATAPHY_LANE0_OUT_STAT - Output Status Register
 * - HW_SATAPHY_LANE0_TX_OVRD - Transmit Input Override Register
 * - HW_SATAPHY_LANE0_RX_OVRD - Receive Input Override Register
 * - HW_SATAPHY_LANE0_OUT_OVRD - Output Override Register
 * - HW_SATAPHY_LANE0_DBG_CTL - Debug Control Register
 * - HW_SATAPHY_LANE0_PG_CTL - Pattern Generator Control Register
 * - HW_SATAPHY_LANE0_PM_CTL - Pattern Matcher Control Register
 * - HW_SATAPHY_LANE0_PM_ERR - Pattern Matcher Error Register
 * - HW_SATAPHY_LANE0_DPLL_PHASE - DPLL Phase Register
 * - HW_SATAPHY_LANE0_DPLL_FREQ - DPLL Frequency Register
 * - HW_SATAPHY_LANE0_SCOPE_CTL - Scope Control Register
 * - HW_SATAPHY_LANE0_RX_CTL - Receiver Control Register
 * - HW_SATAPHY_LANE0_RX_DBG - Receiver Debug Register
 * - HW_SATAPHY_LANE0_RX_ANA_CONTROL - Receive Analog Control Register
 * - HW_SATAPHY_LANE0_RX_ANA_ATB - Receive ATB Register
 * - HW_SATAPHY_LANE0_PLL_PRG2 - Rx PLL Programming 2 Register
 * - HW_SATAPHY_LANE0_PLL_PRG1 - Rx PLL Programming 1 Register
 * - HW_SATAPHY_LANE0_PLL_PRG3 - Rx PLL Measurement Register
 * - HW_SATAPHY_LANE0_TX_ANA_ATBSEL1 - Transmit ATB 1 Control Register
 * - HW_SATAPHY_LANE0_TX_ANA_ATBSEL2 - Transmit ATB 2 Control Register
 * - HW_SATAPHY_LANE0_TX_ANA_CONTROL - Transmit Analog Control Register
 *
 * hw_sataphy_lane0_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SATAPHY_LANE0_BASE
#define REGS_SATAPHY_LANE0_BASE (0x00000000) //!< Base address for SATAPHY_LANE0.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_STAT - Transmit Input Status Register (RO)
 *
 * Address: 0x2001  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of transmit control inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short TX_CKO_EN : 1; //!< tx_cko clock enable
        unsigned short TX_EN : 3; //!< Transmit enable control
        unsigned short TX_CLK_ALIGN : 1; //!< Command to align clocks
        unsigned short RESERVED0 : 1; //!< Always reads as 0
        unsigned short TX_BOOST : 4; //!< Boost amount control
        unsigned short TX_ATTEN : 3; //!< Attenuation amount control
        unsigned short TX_EDGERATE : 2; //!< Edge rate control
        unsigned short RESERVED1 : 1; //!< Always reads as 1
    } B;
} hw_sataphy_lane0_tx_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_STAT register
 */
#define HW_SATAPHY_LANE0_TX_STAT_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2001)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_STAT           (*(volatile hw_sataphy_lane0_tx_stat_t *) HW_SATAPHY_LANE0_TX_STAT_ADDR)
#define HW_SATAPHY_LANE0_TX_STAT_RD()      (HW_SATAPHY_LANE0_TX_STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_STAT bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_CKO_EN[0:0] (RO)
 *
 * tx_cko clock enable
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_CKO_EN      (0)
#define BM_SATAPHY_LANE0_TX_STAT_TX_CKO_EN      (0x00000001)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_EN[3:1] (RO)
 *
 * Transmit enable control
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_EN      (1)
#define BM_SATAPHY_LANE0_TX_STAT_TX_EN      (0x0000000e)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_CLK_ALIGN[4:4] (RO)
 *
 * Command to align clocks
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN      (4)
#define BM_SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN      (0x00000010)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_BOOST[9:6] (RO)
 *
 * Boost amount control
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_BOOST      (6)
#define BM_SATAPHY_LANE0_TX_STAT_TX_BOOST      (0x000003c0)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_ATTEN[12:10] (RO)
 *
 * Attenuation amount control
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_ATTEN      (10)
#define BM_SATAPHY_LANE0_TX_STAT_TX_ATTEN      (0x00001c00)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_EDGERATE[14:13] (RO)
 *
 * Edge rate control
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_EDGERATE      (13)
#define BM_SATAPHY_LANE0_TX_STAT_TX_EDGERATE      (0x00006000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_STAT - Receiver Input Status Register (RO)
 *
 * Address: 0x2002  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of receiver control inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short HALF_RATE : 1; //!< Digital half-rate data control
        unsigned short RX_PLL_PWRON : 1; //!< PLL power state control
        unsigned short RX_EN : 1; //!< Receiver enable control
        unsigned short RX_ALIGN_EN : 1; //!< Receiver alignment enable
        unsigned short RX_TERM_EN : 1; //!< Receiver termination enable
        unsigned short RX_EQ_VAL : 3; //!< Equalization amount control
        unsigned short RX_DPLL_MODE : 3; //!< DPLL mode control
        unsigned short DPLL_RESET : 1; //!< DPLL reset control
        unsigned short LOS_CTL : 2; //!< LOS filtering mode control
        unsigned short RESERVED0 : 2; //!< Always reads as 1
    } B;
} hw_sataphy_lane0_rx_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_STAT register
 */
#define HW_SATAPHY_LANE0_RX_STAT_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2002)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_STAT           (*(volatile hw_sataphy_lane0_rx_stat_t *) HW_SATAPHY_LANE0_RX_STAT_ADDR)
#define HW_SATAPHY_LANE0_RX_STAT_RD()      (HW_SATAPHY_LANE0_RX_STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_STAT bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field HALF_RATE[0:0] (RO)
 *
 * Digital half-rate data control
 */

#define BP_SATAPHY_LANE0_RX_STAT_HALF_RATE      (0)
#define BM_SATAPHY_LANE0_RX_STAT_HALF_RATE      (0x00000001)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_PLL_PWRON[1:1] (RO)
 *
 * PLL power state control
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON      (1)
#define BM_SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON      (0x00000002)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_EN[2:2] (RO)
 *
 * Receiver enable control
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_EN      (2)
#define BM_SATAPHY_LANE0_RX_STAT_RX_EN      (0x00000004)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_ALIGN_EN[3:3] (RO)
 *
 * Receiver alignment enable
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN      (3)
#define BM_SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN      (0x00000008)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_TERM_EN[4:4] (RO)
 *
 * Receiver termination enable
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_TERM_EN      (4)
#define BM_SATAPHY_LANE0_RX_STAT_RX_TERM_EN      (0x00000010)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_EQ_VAL[7:5] (RO)
 *
 * Equalization amount control
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_EQ_VAL      (5)
#define BM_SATAPHY_LANE0_RX_STAT_RX_EQ_VAL      (0x000000e0)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_DPLL_MODE[10:8] (RO)
 *
 * DPLL mode control
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE      (8)
#define BM_SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE      (0x00000700)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field DPLL_RESET[11:11] (RO)
 *
 * DPLL reset control
 */

#define BP_SATAPHY_LANE0_RX_STAT_DPLL_RESET      (11)
#define BM_SATAPHY_LANE0_RX_STAT_DPLL_RESET      (0x00000800)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field LOS_CTL[13:12] (RO)
 *
 * LOS filtering mode control
 */

#define BP_SATAPHY_LANE0_RX_STAT_LOS_CTL      (12)
#define BM_SATAPHY_LANE0_RX_STAT_LOS_CTL      (0x00003000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_OUT_STAT - Output Status Register (RO)
 *
 * Address: 0x2003  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of output signals.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RX_VALID : 1; //!< Receiver valid output
        unsigned short RX_PLL_STATE : 1; //!< Current state of Rx PLL
        unsigned short LOS : 1; //!< Loss of signal output
        unsigned short TX_DONE : 1; //!< Transmit operation is complete output
        unsigned short TX_RXPRES : 1; //!< Transmit receiver detection result
        unsigned short RESERVED0 : 11; //!< Always reads as 1
    } B;
} hw_sataphy_lane0_out_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_OUT_STAT register
 */
#define HW_SATAPHY_LANE0_OUT_STAT_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2003)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_OUT_STAT           (*(volatile hw_sataphy_lane0_out_stat_t *) HW_SATAPHY_LANE0_OUT_STAT_ADDR)
#define HW_SATAPHY_LANE0_OUT_STAT_RD()      (HW_SATAPHY_LANE0_OUT_STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_OUT_STAT bitfields
 */

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field RX_VALID[0:0] (RO)
 *
 * Receiver valid output
 */

#define BP_SATAPHY_LANE0_OUT_STAT_RX_VALID      (0)
#define BM_SATAPHY_LANE0_OUT_STAT_RX_VALID      (0x00000001)

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field RX_PLL_STATE[1:1] (RO)
 *
 * Current state of Rx PLL
 */

#define BP_SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE      (1)
#define BM_SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE      (0x00000002)

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field LOS[2:2] (RO)
 *
 * Loss of signal output
 */

#define BP_SATAPHY_LANE0_OUT_STAT_LOS      (2)
#define BM_SATAPHY_LANE0_OUT_STAT_LOS      (0x00000004)

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field TX_DONE[3:3] (RO)
 *
 * Transmit operation is complete output
 */

#define BP_SATAPHY_LANE0_OUT_STAT_TX_DONE      (3)
#define BM_SATAPHY_LANE0_OUT_STAT_TX_DONE      (0x00000008)

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field TX_RXPRES[4:4] (RO)
 *
 * Transmit receiver detection result
 */

#define BP_SATAPHY_LANE0_OUT_STAT_TX_RXPRES      (4)
#define BM_SATAPHY_LANE0_OUT_STAT_TX_RXPRES      (0x00000010)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_OVRD - Transmit Input Override Register (RW)
 *
 * Address: 0x2004  Reset value: 16'b 0000 0000 0000 0111  This register contains the override
 * transmitter control inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short TX_CKO_EN : 1; //!< tx_cko clock enable
        unsigned short TX_EN : 3; //!< Transmit enable control
        unsigned short TX_CLK_ALIGN : 1; //!< Command to align clocks
        unsigned short TX_DIS_ALIGN : 1; //!< Disables clock alignment FSM
        unsigned short TX_BOOST : 4; //!< Boost amount control
        unsigned short TX_ATTEN : 3; //!< Attenuation amount control
        unsigned short TX_EDGERATE : 2; //!< Edge rate control
        unsigned short OVRD : 1; //!< Enables override of all bits in this register
    } B;
} hw_sataphy_lane0_tx_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_OVRD register
 */
#define HW_SATAPHY_LANE0_TX_OVRD_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2004)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_OVRD           (*(volatile hw_sataphy_lane0_tx_ovrd_t *) HW_SATAPHY_LANE0_TX_OVRD_ADDR)
#define HW_SATAPHY_LANE0_TX_OVRD_RD()      (HW_SATAPHY_LANE0_TX_OVRD.U)
#define HW_SATAPHY_LANE0_TX_OVRD_WR(v)     (HW_SATAPHY_LANE0_TX_OVRD.U = (v))
#define HW_SATAPHY_LANE0_TX_OVRD_SET(v)    (HW_SATAPHY_LANE0_TX_OVRD_WR(HW_SATAPHY_LANE0_TX_OVRD_RD() |  (v)))
#define HW_SATAPHY_LANE0_TX_OVRD_CLR(v)    (HW_SATAPHY_LANE0_TX_OVRD_WR(HW_SATAPHY_LANE0_TX_OVRD_RD() & ~(v)))
#define HW_SATAPHY_LANE0_TX_OVRD_TOG(v)    (HW_SATAPHY_LANE0_TX_OVRD_WR(HW_SATAPHY_LANE0_TX_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_OVRD bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_CKO_EN[0:0] (RW)
 *
 * tx_cko clock enable
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN      (0)
#define BM_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN)
#else
#define BF_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN(v)   (((v) << 0) & BM_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CKO_EN field to a new value.
#define BW_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN(v)   BF_CS1(SATAPHY_LANE0_TX_OVRD, TX_CKO_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_EN[3:1] (RW)
 *
 * Transmit enable control
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_EN      (1)
#define BM_SATAPHY_LANE0_TX_OVRD_TX_EN      (0x0000000e)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_OVRD_TX_EN(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_TX_OVRD_TX_EN)
#else
#define BF_SATAPHY_LANE0_TX_OVRD_TX_EN(v)   (((v) << 1) & BM_SATAPHY_LANE0_TX_OVRD_TX_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EN field to a new value.
#define BW_SATAPHY_LANE0_TX_OVRD_TX_EN(v)   BF_CS1(SATAPHY_LANE0_TX_OVRD, TX_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_CLK_ALIGN[4:4] (RW)
 *
 * Command to align clocks
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN      (4)
#define BM_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN)
#else
#define BF_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN(v)   (((v) << 4) & BM_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CLK_ALIGN field to a new value.
#define BW_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN(v)   BF_CS1(SATAPHY_LANE0_TX_OVRD, TX_CLK_ALIGN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_DIS_ALIGN[5:5] (RW)
 *
 * Disables clock alignment FSM
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN      (5)
#define BM_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN)
#else
#define BF_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN(v)   (((v) << 5) & BM_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DIS_ALIGN field to a new value.
#define BW_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN(v)   BF_CS1(SATAPHY_LANE0_TX_OVRD, TX_DIS_ALIGN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_BOOST[9:6] (RW)
 *
 * Boost amount control
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_BOOST      (6)
#define BM_SATAPHY_LANE0_TX_OVRD_TX_BOOST      (0x000003c0)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_OVRD_TX_BOOST(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_LANE0_TX_OVRD_TX_BOOST)
#else
#define BF_SATAPHY_LANE0_TX_OVRD_TX_BOOST(v)   (((v) << 6) & BM_SATAPHY_LANE0_TX_OVRD_TX_BOOST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_BOOST field to a new value.
#define BW_SATAPHY_LANE0_TX_OVRD_TX_BOOST(v)   BF_CS1(SATAPHY_LANE0_TX_OVRD, TX_BOOST, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_ATTEN[12:10] (RW)
 *
 * Attenuation amount control
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_ATTEN      (10)
#define BM_SATAPHY_LANE0_TX_OVRD_TX_ATTEN      (0x00001c00)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_OVRD_TX_ATTEN(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_LANE0_TX_OVRD_TX_ATTEN)
#else
#define BF_SATAPHY_LANE0_TX_OVRD_TX_ATTEN(v)   (((v) << 10) & BM_SATAPHY_LANE0_TX_OVRD_TX_ATTEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_ATTEN field to a new value.
#define BW_SATAPHY_LANE0_TX_OVRD_TX_ATTEN(v)   BF_CS1(SATAPHY_LANE0_TX_OVRD, TX_ATTEN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_EDGERATE[14:13] (RW)
 *
 * Edge rate control
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE      (13)
#define BM_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE      (0x00006000)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE(v)   ((((reg32_t) v) << 13) & BM_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE)
#else
#define BF_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE(v)   (((v) << 13) & BM_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EDGERATE field to a new value.
#define BW_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE(v)   BF_CS1(SATAPHY_LANE0_TX_OVRD, TX_EDGERATE, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field OVRD[15:15] (RW)
 *
 * Enables override of all bits in this register
 */

#define BP_SATAPHY_LANE0_TX_OVRD_OVRD      (15)
#define BM_SATAPHY_LANE0_TX_OVRD_OVRD      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_OVRD_OVRD(v)   ((((reg32_t) v) << 15) & BM_SATAPHY_LANE0_TX_OVRD_OVRD)
#else
#define BF_SATAPHY_LANE0_TX_OVRD_OVRD(v)   (((v) << 15) & BM_SATAPHY_LANE0_TX_OVRD_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD field to a new value.
#define BW_SATAPHY_LANE0_TX_OVRD_OVRD(v)   BF_CS1(SATAPHY_LANE0_TX_OVRD, OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_OVRD - Receive Input Override Register (RW)
 *
 * Address: 0x2005  Reset value: 16'b x001 0100 0001 1110  This register contains the override of
 * receiver control inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short HALF_RATE : 1; //!< Digital half-rate data control
        unsigned short RX_PLL_PWRON : 1; //!< PLL power state control
        unsigned short RX_EN : 1; //!< Receiver enable control
        unsigned short RX_ALIGN_EN : 1; //!< Receiver alignment enable
        unsigned short RX_TERM_EN : 1; //!< Receiver termination enable
        unsigned short RX_EQ_VAL : 3; //!< Equalization amount control
        unsigned short RX_DPLL_MODE : 3; //!< DPLL mode control
        unsigned short DPLL_RESET : 1; //!< DPLL reset control
        unsigned short LOS_CTL : 2; //!< LOS filtering mode control
        unsigned short OVRD : 1; //!< Enables override of all bits in this register
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_sataphy_lane0_rx_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_OVRD register
 */
#define HW_SATAPHY_LANE0_RX_OVRD_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2005)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_OVRD           (*(volatile hw_sataphy_lane0_rx_ovrd_t *) HW_SATAPHY_LANE0_RX_OVRD_ADDR)
#define HW_SATAPHY_LANE0_RX_OVRD_RD()      (HW_SATAPHY_LANE0_RX_OVRD.U)
#define HW_SATAPHY_LANE0_RX_OVRD_WR(v)     (HW_SATAPHY_LANE0_RX_OVRD.U = (v))
#define HW_SATAPHY_LANE0_RX_OVRD_SET(v)    (HW_SATAPHY_LANE0_RX_OVRD_WR(HW_SATAPHY_LANE0_RX_OVRD_RD() |  (v)))
#define HW_SATAPHY_LANE0_RX_OVRD_CLR(v)    (HW_SATAPHY_LANE0_RX_OVRD_WR(HW_SATAPHY_LANE0_RX_OVRD_RD() & ~(v)))
#define HW_SATAPHY_LANE0_RX_OVRD_TOG(v)    (HW_SATAPHY_LANE0_RX_OVRD_WR(HW_SATAPHY_LANE0_RX_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_OVRD bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field HALF_RATE[0:0] (RW)
 *
 * Digital half-rate data control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_HALF_RATE      (0)
#define BM_SATAPHY_LANE0_RX_OVRD_HALF_RATE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_HALF_RATE(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_RX_OVRD_HALF_RATE)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_HALF_RATE(v)   (((v) << 0) & BM_SATAPHY_LANE0_RX_OVRD_HALF_RATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_RATE field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_HALF_RATE(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, HALF_RATE, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_PLL_PWRON[1:1] (RW)
 *
 * PLL power state control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON      (1)
#define BM_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON(v)   (((v) << 1) & BM_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_PLL_PWRON field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, RX_PLL_PWRON, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_EN[2:2] (RW)
 *
 * Receiver enable control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_EN      (2)
#define BM_SATAPHY_LANE0_RX_OVRD_RX_EN      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_RX_EN(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_RX_OVRD_RX_EN)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_RX_EN(v)   (((v) << 2) & BM_SATAPHY_LANE0_RX_OVRD_RX_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_RX_EN(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, RX_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_ALIGN_EN[3:3] (RW)
 *
 * Receiver alignment enable
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN      (3)
#define BM_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN(v)   (((v) << 3) & BM_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ALIGN_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, RX_ALIGN_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_TERM_EN[4:4] (RW)
 *
 * Receiver termination enable
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN      (4)
#define BM_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN(v)   (((v) << 4) & BM_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_TERM_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, RX_TERM_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_EQ_VAL[7:5] (RW)
 *
 * Equalization amount control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL      (5)
#define BM_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL      (0x000000e0)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL(v)   (((v) << 5) & BM_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ_VAL field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, RX_EQ_VAL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_DPLL_MODE[10:8] (RW)
 *
 * DPLL mode control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE      (8)
#define BM_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE(v)   ((((reg32_t) v) << 8) & BM_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE(v)   (((v) << 8) & BM_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_DPLL_MODE field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, RX_DPLL_MODE, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field DPLL_RESET[11:11] (RW)
 *
 * DPLL reset control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_DPLL_RESET      (11)
#define BM_SATAPHY_LANE0_RX_OVRD_DPLL_RESET      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_DPLL_RESET(v)   ((((reg32_t) v) << 11) & BM_SATAPHY_LANE0_RX_OVRD_DPLL_RESET)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_DPLL_RESET(v)   (((v) << 11) & BM_SATAPHY_LANE0_RX_OVRD_DPLL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPLL_RESET field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_DPLL_RESET(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, DPLL_RESET, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field LOS_CTL[13:12] (RW)
 *
 * LOS filtering mode control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_LOS_CTL      (12)
#define BM_SATAPHY_LANE0_RX_OVRD_LOS_CTL      (0x00003000)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_LOS_CTL(v)   ((((reg32_t) v) << 12) & BM_SATAPHY_LANE0_RX_OVRD_LOS_CTL)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_LOS_CTL(v)   (((v) << 12) & BM_SATAPHY_LANE0_RX_OVRD_LOS_CTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS_CTL field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_LOS_CTL(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, LOS_CTL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field OVRD[14:14] (RW)
 *
 * Enables override of all bits in this register
 */

#define BP_SATAPHY_LANE0_RX_OVRD_OVRD      (14)
#define BM_SATAPHY_LANE0_RX_OVRD_OVRD      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_OVRD_OVRD(v)   ((((reg32_t) v) << 14) & BM_SATAPHY_LANE0_RX_OVRD_OVRD)
#else
#define BF_SATAPHY_LANE0_RX_OVRD_OVRD(v)   (((v) << 14) & BM_SATAPHY_LANE0_RX_OVRD_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD field to a new value.
#define BW_SATAPHY_LANE0_RX_OVRD_OVRD(v)   BF_CS1(SATAPHY_LANE0_RX_OVRD, OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_OUT_OVRD - Output Override Register (RW)
 *
 * Address: 0x2006  Reset value: 16'b xxxx xxxx xx01 0001  This register contains the override of
 * output signals.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RX_VALID : 1; //!< Receiver valid output
        unsigned short RX_PLL_STATE : 1; //!< Current state of Rx PLL
        unsigned short LOS : 1; //!< Loss of signal output
        unsigned short TX_DONE : 1; //!< Transmit operation is complete output
        unsigned short TX_RXPRES : 1; //!< Transmit receiver detection result
        unsigned short OVRD : 1; //!< Enables override of all bits in this register
        unsigned short RESERVED0 : 10; //!< Reserved
    } B;
} hw_sataphy_lane0_out_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_OUT_OVRD register
 */
#define HW_SATAPHY_LANE0_OUT_OVRD_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2006)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_OUT_OVRD           (*(volatile hw_sataphy_lane0_out_ovrd_t *) HW_SATAPHY_LANE0_OUT_OVRD_ADDR)
#define HW_SATAPHY_LANE0_OUT_OVRD_RD()      (HW_SATAPHY_LANE0_OUT_OVRD.U)
#define HW_SATAPHY_LANE0_OUT_OVRD_WR(v)     (HW_SATAPHY_LANE0_OUT_OVRD.U = (v))
#define HW_SATAPHY_LANE0_OUT_OVRD_SET(v)    (HW_SATAPHY_LANE0_OUT_OVRD_WR(HW_SATAPHY_LANE0_OUT_OVRD_RD() |  (v)))
#define HW_SATAPHY_LANE0_OUT_OVRD_CLR(v)    (HW_SATAPHY_LANE0_OUT_OVRD_WR(HW_SATAPHY_LANE0_OUT_OVRD_RD() & ~(v)))
#define HW_SATAPHY_LANE0_OUT_OVRD_TOG(v)    (HW_SATAPHY_LANE0_OUT_OVRD_WR(HW_SATAPHY_LANE0_OUT_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_OUT_OVRD bitfields
 */

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field RX_VALID[0:0] (RW)
 *
 * Receiver valid output
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_RX_VALID      (0)
#define BM_SATAPHY_LANE0_OUT_OVRD_RX_VALID      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_OUT_OVRD_RX_VALID(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_OUT_OVRD_RX_VALID)
#else
#define BF_SATAPHY_LANE0_OUT_OVRD_RX_VALID(v)   (((v) << 0) & BM_SATAPHY_LANE0_OUT_OVRD_RX_VALID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_VALID field to a new value.
#define BW_SATAPHY_LANE0_OUT_OVRD_RX_VALID(v)   BF_CS1(SATAPHY_LANE0_OUT_OVRD, RX_VALID, v)
#endif

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field RX_PLL_STATE[1:1] (RW)
 *
 * Current state of Rx PLL
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE      (1)
#define BM_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE)
#else
#define BF_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE(v)   (((v) << 1) & BM_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_PLL_STATE field to a new value.
#define BW_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE(v)   BF_CS1(SATAPHY_LANE0_OUT_OVRD, RX_PLL_STATE, v)
#endif

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field LOS[2:2] (RW)
 *
 * Loss of signal output
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_LOS      (2)
#define BM_SATAPHY_LANE0_OUT_OVRD_LOS      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_OUT_OVRD_LOS(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_OUT_OVRD_LOS)
#else
#define BF_SATAPHY_LANE0_OUT_OVRD_LOS(v)   (((v) << 2) & BM_SATAPHY_LANE0_OUT_OVRD_LOS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS field to a new value.
#define BW_SATAPHY_LANE0_OUT_OVRD_LOS(v)   BF_CS1(SATAPHY_LANE0_OUT_OVRD, LOS, v)
#endif

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field TX_DONE[3:3] (RW)
 *
 * Transmit operation is complete output
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_TX_DONE      (3)
#define BM_SATAPHY_LANE0_OUT_OVRD_TX_DONE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_OUT_OVRD_TX_DONE(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_OUT_OVRD_TX_DONE)
#else
#define BF_SATAPHY_LANE0_OUT_OVRD_TX_DONE(v)   (((v) << 3) & BM_SATAPHY_LANE0_OUT_OVRD_TX_DONE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DONE field to a new value.
#define BW_SATAPHY_LANE0_OUT_OVRD_TX_DONE(v)   BF_CS1(SATAPHY_LANE0_OUT_OVRD, TX_DONE, v)
#endif

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field TX_RXPRES[4:4] (RW)
 *
 * Transmit receiver detection result
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES      (4)
#define BM_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES)
#else
#define BF_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES(v)   (((v) << 4) & BM_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RXPRES field to a new value.
#define BW_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES(v)   BF_CS1(SATAPHY_LANE0_OUT_OVRD, TX_RXPRES, v)
#endif

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field OVRD[5:5] (RW)
 *
 * Enables override of all bits in this register
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_OVRD      (5)
#define BM_SATAPHY_LANE0_OUT_OVRD_OVRD      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_OUT_OVRD_OVRD(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_OUT_OVRD_OVRD)
#else
#define BF_SATAPHY_LANE0_OUT_OVRD_OVRD(v)   (((v) << 5) & BM_SATAPHY_LANE0_OUT_OVRD_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD field to a new value.
#define BW_SATAPHY_LANE0_OUT_OVRD_OVRD(v)   BF_CS1(SATAPHY_LANE0_OUT_OVRD, OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_DBG_CTL - Debug Control Register (RW)
 *
 * Address: 0x2007  Reset value: 16'b x000 0000 0000 0000  This register contains debug controls.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ZERO_TX_DATA : 1; //!< Overrides all transmit data to zeros
        unsigned short ZERO_RX_DATA : 1; //!< Overrides all receive data to zeros
        unsigned short INVERT_TX : 1; //!< Inverts transmit data (post-LBERT)
        unsigned short INVERT_RX : 1; //!< Inverts receive data (pre-LBERT)
        unsigned short DISABLE_RX_CK : 1; //!< Disables rx_ck output
        unsigned short DTB_SEL0 : 5; //!< All other bits: Disabled Selects wire to drive onto DTB bit 0:
        unsigned short DTB_SEL1 : 5; //!< All other bits: Disabled Selects wire to drive onto DTB bit 1:
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_sataphy_lane0_dbg_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_DBG_CTL register
 */
#define HW_SATAPHY_LANE0_DBG_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2007)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_DBG_CTL           (*(volatile hw_sataphy_lane0_dbg_ctl_t *) HW_SATAPHY_LANE0_DBG_CTL_ADDR)
#define HW_SATAPHY_LANE0_DBG_CTL_RD()      (HW_SATAPHY_LANE0_DBG_CTL.U)
#define HW_SATAPHY_LANE0_DBG_CTL_WR(v)     (HW_SATAPHY_LANE0_DBG_CTL.U = (v))
#define HW_SATAPHY_LANE0_DBG_CTL_SET(v)    (HW_SATAPHY_LANE0_DBG_CTL_WR(HW_SATAPHY_LANE0_DBG_CTL_RD() |  (v)))
#define HW_SATAPHY_LANE0_DBG_CTL_CLR(v)    (HW_SATAPHY_LANE0_DBG_CTL_WR(HW_SATAPHY_LANE0_DBG_CTL_RD() & ~(v)))
#define HW_SATAPHY_LANE0_DBG_CTL_TOG(v)    (HW_SATAPHY_LANE0_DBG_CTL_WR(HW_SATAPHY_LANE0_DBG_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_DBG_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field ZERO_TX_DATA[0:0] (RW)
 *
 * Overrides all transmit data to zeros
 */

#define BP_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA      (0)
#define BM_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA)
#else
#define BF_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA(v)   (((v) << 0) & BM_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ZERO_TX_DATA field to a new value.
#define BW_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA(v)   BF_CS1(SATAPHY_LANE0_DBG_CTL, ZERO_TX_DATA, v)
#endif

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field ZERO_RX_DATA[1:1] (RW)
 *
 * Overrides all receive data to zeros
 */

#define BP_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA      (1)
#define BM_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA)
#else
#define BF_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA(v)   (((v) << 1) & BM_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ZERO_RX_DATA field to a new value.
#define BW_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA(v)   BF_CS1(SATAPHY_LANE0_DBG_CTL, ZERO_RX_DATA, v)
#endif

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field INVERT_TX[2:2] (RW)
 *
 * Inverts transmit data (post-LBERT)
 */

#define BP_SATAPHY_LANE0_DBG_CTL_INVERT_TX      (2)
#define BM_SATAPHY_LANE0_DBG_CTL_INVERT_TX      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DBG_CTL_INVERT_TX(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_DBG_CTL_INVERT_TX)
#else
#define BF_SATAPHY_LANE0_DBG_CTL_INVERT_TX(v)   (((v) << 2) & BM_SATAPHY_LANE0_DBG_CTL_INVERT_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INVERT_TX field to a new value.
#define BW_SATAPHY_LANE0_DBG_CTL_INVERT_TX(v)   BF_CS1(SATAPHY_LANE0_DBG_CTL, INVERT_TX, v)
#endif

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field INVERT_RX[3:3] (RW)
 *
 * Inverts receive data (pre-LBERT)
 */

#define BP_SATAPHY_LANE0_DBG_CTL_INVERT_RX      (3)
#define BM_SATAPHY_LANE0_DBG_CTL_INVERT_RX      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DBG_CTL_INVERT_RX(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_DBG_CTL_INVERT_RX)
#else
#define BF_SATAPHY_LANE0_DBG_CTL_INVERT_RX(v)   (((v) << 3) & BM_SATAPHY_LANE0_DBG_CTL_INVERT_RX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INVERT_RX field to a new value.
#define BW_SATAPHY_LANE0_DBG_CTL_INVERT_RX(v)   BF_CS1(SATAPHY_LANE0_DBG_CTL, INVERT_RX, v)
#endif

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field DISABLE_RX_CK[4:4] (RW)
 *
 * Disables rx_ck output
 */

#define BP_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK      (4)
#define BM_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK)
#else
#define BF_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK(v)   (((v) << 4) & BM_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISABLE_RX_CK field to a new value.
#define BW_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK(v)   BF_CS1(SATAPHY_LANE0_DBG_CTL, DISABLE_RX_CK, v)
#endif

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field DTB_SEL0[9:5] (RW)
 *
 * All other bits: Disabled Selects wire to drive onto DTB bit 0:
 *
 * Values:
 * 00000 - Disabled
 * 00001 - half_rate
 * 00010 - tx_en[0]
 * 00011 - tx_en[1]
 * 00100 - tx_en[2]
 * 00101 - tx_clk_align
 * 00110 - n/a
 * 00111 - rx_pll_pwron
 * 01000 - rx_en
 * 01001 - dpll_reset
 * 01010 - rx_valid
 * 01011 - rx_pll_state
 * 01100 - los
 * 01101 - tx_done
 * 01110 - rx_ck (output to ASIC)
 * 01111 - ck_rx (PLL output)
 * 10000 - ck_los
 * 10001 - tx_ck (ASIC input)
 * 10010 - ck_tx_out (serializer output)
 * 10011 - pll_pwron (analog input)
 * 10100 - pll_reset
 * 10101 - ser_clk_kill
 * 10110 - LBERT pattern generator strobe
 * 10111 - rx_present_p (sampled)
 * 11000 - rx_present_m (sampled)
 * 11001 - acjt receiver o/p from rx_p
 * 11010 - acjt receiver o/p from rx_m
 */

#define BP_SATAPHY_LANE0_DBG_CTL_DTB_SEL0      (5)
#define BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL0      (0x000003e0)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DBG_CTL_DTB_SEL0(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL0)
#else
#define BF_SATAPHY_LANE0_DBG_CTL_DTB_SEL0(v)   (((v) << 5) & BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL0 field to a new value.
#define BW_SATAPHY_LANE0_DBG_CTL_DTB_SEL0(v)   BF_CS1(SATAPHY_LANE0_DBG_CTL, DTB_SEL0, v)
#endif


/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field DTB_SEL1[14:10] (RW)
 *
 * All other bits: Disabled Selects wire to drive onto DTB bit 1:
 *
 * Values:
 * 00000 - Disabled
 * 00001 - half_rate
 * 00010 - tx_en[0]
 * 00011 - tx_en[1]
 * 00100 - tx_en[2]
 * 00101 - tx_clk_align
 * 00110 - n/a
 * 00111 - rx_pll_pwron
 * 01000 - rx_en
 * 01001 - dpll_reset
 * 01010 - rx_valid
 * 01011 - rx_pll_state
 * 01100 - los
 * 01101 - tx_done
 * 01110 - rx_ck (output to ASIC)
 * 01111 - ck_rx (PLL output)
 * 10000 - ck_los
 * 10001 - tx_ck (ASIC input)
 * 10010 - ck_tx_out (serializer output)
 * 10011 - pll_pwron (analog input)
 * 10100 - pll_reset
 * 10101 - ser_clk_kill
 * 10110 - LBERT pg strobe
 * 10111 - rx_present_p (sampled)
 * 11000 - rx_present_m (sampled)
 * 11001 - acjt receiver o/p from rx_p
 * 11010 - acjt receiver o/p from rx_m
 */

#define BP_SATAPHY_LANE0_DBG_CTL_DTB_SEL1      (10)
#define BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL1      (0x00007c00)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DBG_CTL_DTB_SEL1(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL1)
#else
#define BF_SATAPHY_LANE0_DBG_CTL_DTB_SEL1(v)   (((v) << 10) & BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL1 field to a new value.
#define BW_SATAPHY_LANE0_DBG_CTL_DTB_SEL1(v)   BF_CS1(SATAPHY_LANE0_DBG_CTL, DTB_SEL1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PG_CTL - Pattern Generator Control Register (RW)
 *
 * Address: 0x2010  Reset value: 16'b xx00 0000 0000 0000 0000  This register contains pattern
 * generator controls.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MODE : 3; //!< Selects a pattern to generate:
        unsigned short TRIGGER_ERR : 1; //!< Inserts a single error into the LSB
        unsigned short PAT0 : 10; //!< Pattern for modes 3-5
        unsigned short RESERVED0 : 2; //!< Reserved
    } B;
} hw_sataphy_lane0_pg_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PG_CTL register
 */
#define HW_SATAPHY_LANE0_PG_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2010)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PG_CTL           (*(volatile hw_sataphy_lane0_pg_ctl_t *) HW_SATAPHY_LANE0_PG_CTL_ADDR)
#define HW_SATAPHY_LANE0_PG_CTL_RD()      (HW_SATAPHY_LANE0_PG_CTL.U)
#define HW_SATAPHY_LANE0_PG_CTL_WR(v)     (HW_SATAPHY_LANE0_PG_CTL.U = (v))
#define HW_SATAPHY_LANE0_PG_CTL_SET(v)    (HW_SATAPHY_LANE0_PG_CTL_WR(HW_SATAPHY_LANE0_PG_CTL_RD() |  (v)))
#define HW_SATAPHY_LANE0_PG_CTL_CLR(v)    (HW_SATAPHY_LANE0_PG_CTL_WR(HW_SATAPHY_LANE0_PG_CTL_RD() & ~(v)))
#define HW_SATAPHY_LANE0_PG_CTL_TOG(v)    (HW_SATAPHY_LANE0_PG_CTL_WR(HW_SATAPHY_LANE0_PG_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PG_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PG_CTL, field MODE[2:0] (RW)
 *
 * Selects a pattern to generate:
 *
 * Values:
 * 000 - Disabled
 * 001 - lfsr15. X^15 + X^14 + 1
 * 010 - lfsr7. X^7 + X^6 + 1
 * 011 - Fixed word (PAT0)3'b
 * 100 - DC balanced word (PAT0, ~PAT0)
 * 101 - Fixed pattern: (000, PAT0, 3ff, ~PAT0)
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_SATAPHY_LANE0_PG_CTL_MODE      (0)
#define BM_SATAPHY_LANE0_PG_CTL_MODE      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PG_CTL_MODE(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_PG_CTL_MODE)
#else
#define BF_SATAPHY_LANE0_PG_CTL_MODE(v)   (((v) << 0) & BM_SATAPHY_LANE0_PG_CTL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_SATAPHY_LANE0_PG_CTL_MODE(v)   BF_CS1(SATAPHY_LANE0_PG_CTL, MODE, v)
#endif


/* --- Register HW_SATAPHY_LANE0_PG_CTL, field TRIGGER_ERR[3:3] (RW)
 *
 * Inserts a single error into the LSB
 */

#define BP_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR      (3)
#define BM_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR)
#else
#define BF_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR(v)   (((v) << 3) & BM_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TRIGGER_ERR field to a new value.
#define BW_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR(v)   BF_CS1(SATAPHY_LANE0_PG_CTL, TRIGGER_ERR, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PG_CTL, field PAT0[13:4] (RW)
 *
 * Pattern for modes 3-5
 */

#define BP_SATAPHY_LANE0_PG_CTL_PAT0      (4)
#define BM_SATAPHY_LANE0_PG_CTL_PAT0      (0x00003ff0)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PG_CTL_PAT0(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_PG_CTL_PAT0)
#else
#define BF_SATAPHY_LANE0_PG_CTL_PAT0(v)   (((v) << 4) & BM_SATAPHY_LANE0_PG_CTL_PAT0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PAT0 field to a new value.
#define BW_SATAPHY_LANE0_PG_CTL_PAT0(v)   BF_CS1(SATAPHY_LANE0_PG_CTL, PAT0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PM_CTL - Pattern Matcher Control Register (RW)
 *
 * Address: 0x2018  Reset value: 16'b xxxx xxxx xxxx 0000  This register contains pattern matcher
 * controls.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MODE : 3; //!< All other bits: Reserved Pattern to match:
        unsigned short SYNC : 1; //!< To enable checking, "Synchronize pattern matcher LFSR with incoming data" must be turned on, then turned off.
        unsigned short RESERVED0 : 12; //!< Reserved
    } B;
} hw_sataphy_lane0_pm_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PM_CTL register
 */
#define HW_SATAPHY_LANE0_PM_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2018)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PM_CTL           (*(volatile hw_sataphy_lane0_pm_ctl_t *) HW_SATAPHY_LANE0_PM_CTL_ADDR)
#define HW_SATAPHY_LANE0_PM_CTL_RD()      (HW_SATAPHY_LANE0_PM_CTL.U)
#define HW_SATAPHY_LANE0_PM_CTL_WR(v)     (HW_SATAPHY_LANE0_PM_CTL.U = (v))
#define HW_SATAPHY_LANE0_PM_CTL_SET(v)    (HW_SATAPHY_LANE0_PM_CTL_WR(HW_SATAPHY_LANE0_PM_CTL_RD() |  (v)))
#define HW_SATAPHY_LANE0_PM_CTL_CLR(v)    (HW_SATAPHY_LANE0_PM_CTL_WR(HW_SATAPHY_LANE0_PM_CTL_RD() & ~(v)))
#define HW_SATAPHY_LANE0_PM_CTL_TOG(v)    (HW_SATAPHY_LANE0_PM_CTL_WR(HW_SATAPHY_LANE0_PM_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PM_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PM_CTL, field MODE[2:0] (RW)
 *
 * All other bits: Reserved Pattern to match:
 *
 * Values:
 * 000 - Disabled
 * 001 - lfsr15
 * 010 - lfsr7
 * 011 - d[n] = d[n-10]
 * 100 - d[n] = !d[n-10]
 */

#define BP_SATAPHY_LANE0_PM_CTL_MODE      (0)
#define BM_SATAPHY_LANE0_PM_CTL_MODE      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PM_CTL_MODE(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_PM_CTL_MODE)
#else
#define BF_SATAPHY_LANE0_PM_CTL_MODE(v)   (((v) << 0) & BM_SATAPHY_LANE0_PM_CTL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_SATAPHY_LANE0_PM_CTL_MODE(v)   BF_CS1(SATAPHY_LANE0_PM_CTL, MODE, v)
#endif


/* --- Register HW_SATAPHY_LANE0_PM_CTL, field SYNC[3:3] (RW)
 *
 * To enable checking, "Synchronize pattern matcher LFSR with incoming data" must be turned on, then
 * turned off.
 */

#define BP_SATAPHY_LANE0_PM_CTL_SYNC      (3)
#define BM_SATAPHY_LANE0_PM_CTL_SYNC      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PM_CTL_SYNC(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_PM_CTL_SYNC)
#else
#define BF_SATAPHY_LANE0_PM_CTL_SYNC(v)   (((v) << 3) & BM_SATAPHY_LANE0_PM_CTL_SYNC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYNC field to a new value.
#define BW_SATAPHY_LANE0_PM_CTL_SYNC(v)   BF_CS1(SATAPHY_LANE0_PM_CTL, SYNC, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PM_ERR - Pattern Matcher Error Register (RW)
 *
 * Address: 0x2019  Reset value: 16'b xxxx xxxx xxxx xxxx (a read resets the register)  This
 * register is the pattern match error counter. When the clock to the error counter is turned off,
 * reads and writes to the register are queued until the clock is turned back on.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short COUNT : 15; //!< Current error count If the ov14 field is active, the count is multiplied by 128.
        unsigned short OV14 : 1; //!< If this field is active, the count is multiplied by 128. If ov14 is set to 1 and count = 2^15 - 1, indicates overflow of counter.
    } B;
} hw_sataphy_lane0_pm_err_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PM_ERR register
 */
#define HW_SATAPHY_LANE0_PM_ERR_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2019)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PM_ERR           (*(volatile hw_sataphy_lane0_pm_err_t *) HW_SATAPHY_LANE0_PM_ERR_ADDR)
#define HW_SATAPHY_LANE0_PM_ERR_RD()      (HW_SATAPHY_LANE0_PM_ERR.U)
#define HW_SATAPHY_LANE0_PM_ERR_WR(v)     (HW_SATAPHY_LANE0_PM_ERR.U = (v))
#define HW_SATAPHY_LANE0_PM_ERR_SET(v)    (HW_SATAPHY_LANE0_PM_ERR_WR(HW_SATAPHY_LANE0_PM_ERR_RD() |  (v)))
#define HW_SATAPHY_LANE0_PM_ERR_CLR(v)    (HW_SATAPHY_LANE0_PM_ERR_WR(HW_SATAPHY_LANE0_PM_ERR_RD() & ~(v)))
#define HW_SATAPHY_LANE0_PM_ERR_TOG(v)    (HW_SATAPHY_LANE0_PM_ERR_WR(HW_SATAPHY_LANE0_PM_ERR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PM_ERR bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PM_ERR, field COUNT[14:0] (RW)
 *
 * Current error count If the ov14 field is active, the count is multiplied by 128.
 */

#define BP_SATAPHY_LANE0_PM_ERR_COUNT      (0)
#define BM_SATAPHY_LANE0_PM_ERR_COUNT      (0x00007fff)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PM_ERR_COUNT(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_PM_ERR_COUNT)
#else
#define BF_SATAPHY_LANE0_PM_ERR_COUNT(v)   (((v) << 0) & BM_SATAPHY_LANE0_PM_ERR_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_SATAPHY_LANE0_PM_ERR_COUNT(v)   BF_CS1(SATAPHY_LANE0_PM_ERR, COUNT, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PM_ERR, field OV14[15:15] (RW)
 *
 * If this field is active, the count is multiplied by 128. If ov14 is set to 1 and count = 2^15 -
 * 1, indicates overflow of counter.
 */

#define BP_SATAPHY_LANE0_PM_ERR_OV14      (15)
#define BM_SATAPHY_LANE0_PM_ERR_OV14      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PM_ERR_OV14(v)   ((((reg32_t) v) << 15) & BM_SATAPHY_LANE0_PM_ERR_OV14)
#else
#define BF_SATAPHY_LANE0_PM_ERR_OV14(v)   (((v) << 15) & BM_SATAPHY_LANE0_PM_ERR_OV14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OV14 field to a new value.
#define BW_SATAPHY_LANE0_PM_ERR_OV14(v)   BF_CS1(SATAPHY_LANE0_PM_ERR, OV14, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_DPLL_PHASE - DPLL Phase Register (RW)
 *
 * Address: 0x201A  Reset value: 16'b xxxx x000 0000 0000  This register contains the current phase
 * selector value.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DTHR : 1; //!< Bits below the useful resolution
        unsigned short VAL : 10; //!< Phase is .UI/512 x VAL ps from zero reference
        unsigned short RESERVED0 : 5; //!< Reserved
    } B;
} hw_sataphy_lane0_dpll_phase_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_DPLL_PHASE register
 */
#define HW_SATAPHY_LANE0_DPLL_PHASE_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201a)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_DPLL_PHASE           (*(volatile hw_sataphy_lane0_dpll_phase_t *) HW_SATAPHY_LANE0_DPLL_PHASE_ADDR)
#define HW_SATAPHY_LANE0_DPLL_PHASE_RD()      (HW_SATAPHY_LANE0_DPLL_PHASE.U)
#define HW_SATAPHY_LANE0_DPLL_PHASE_WR(v)     (HW_SATAPHY_LANE0_DPLL_PHASE.U = (v))
#define HW_SATAPHY_LANE0_DPLL_PHASE_SET(v)    (HW_SATAPHY_LANE0_DPLL_PHASE_WR(HW_SATAPHY_LANE0_DPLL_PHASE_RD() |  (v)))
#define HW_SATAPHY_LANE0_DPLL_PHASE_CLR(v)    (HW_SATAPHY_LANE0_DPLL_PHASE_WR(HW_SATAPHY_LANE0_DPLL_PHASE_RD() & ~(v)))
#define HW_SATAPHY_LANE0_DPLL_PHASE_TOG(v)    (HW_SATAPHY_LANE0_DPLL_PHASE_WR(HW_SATAPHY_LANE0_DPLL_PHASE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_DPLL_PHASE bitfields
 */

/* --- Register HW_SATAPHY_LANE0_DPLL_PHASE, field DTHR[0:0] (RW)
 *
 * Bits below the useful resolution
 */

#define BP_SATAPHY_LANE0_DPLL_PHASE_DTHR      (0)
#define BM_SATAPHY_LANE0_DPLL_PHASE_DTHR      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DPLL_PHASE_DTHR(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_DPLL_PHASE_DTHR)
#else
#define BF_SATAPHY_LANE0_DPLL_PHASE_DTHR(v)   (((v) << 0) & BM_SATAPHY_LANE0_DPLL_PHASE_DTHR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTHR field to a new value.
#define BW_SATAPHY_LANE0_DPLL_PHASE_DTHR(v)   BF_CS1(SATAPHY_LANE0_DPLL_PHASE, DTHR, v)
#endif

/* --- Register HW_SATAPHY_LANE0_DPLL_PHASE, field VAL[10:1] (RW)
 *
 * Phase is .UI/512 x VAL ps from zero reference
 */

#define BP_SATAPHY_LANE0_DPLL_PHASE_VAL      (1)
#define BM_SATAPHY_LANE0_DPLL_PHASE_VAL      (0x000007fe)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DPLL_PHASE_VAL(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_DPLL_PHASE_VAL)
#else
#define BF_SATAPHY_LANE0_DPLL_PHASE_VAL(v)   (((v) << 1) & BM_SATAPHY_LANE0_DPLL_PHASE_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VAL field to a new value.
#define BW_SATAPHY_LANE0_DPLL_PHASE_VAL(v)   BF_CS1(SATAPHY_LANE0_DPLL_PHASE, VAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_DPLL_FREQ - DPLL Frequency Register (RW)
 *
 * Address: 0x201B  Reset value: 16'b xx00 0000 0000 0000  This register contains the current
 * frequency integrator value.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DTHR : 1; //!< Bits below the useful resolution
        unsigned short VAL : 13; //!< Frequency is 1.526 x VAL ppm from the reference
        unsigned short RESERVED0 : 2; //!< Reserved
    } B;
} hw_sataphy_lane0_dpll_freq_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_DPLL_FREQ register
 */
#define HW_SATAPHY_LANE0_DPLL_FREQ_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201b)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_DPLL_FREQ           (*(volatile hw_sataphy_lane0_dpll_freq_t *) HW_SATAPHY_LANE0_DPLL_FREQ_ADDR)
#define HW_SATAPHY_LANE0_DPLL_FREQ_RD()      (HW_SATAPHY_LANE0_DPLL_FREQ.U)
#define HW_SATAPHY_LANE0_DPLL_FREQ_WR(v)     (HW_SATAPHY_LANE0_DPLL_FREQ.U = (v))
#define HW_SATAPHY_LANE0_DPLL_FREQ_SET(v)    (HW_SATAPHY_LANE0_DPLL_FREQ_WR(HW_SATAPHY_LANE0_DPLL_FREQ_RD() |  (v)))
#define HW_SATAPHY_LANE0_DPLL_FREQ_CLR(v)    (HW_SATAPHY_LANE0_DPLL_FREQ_WR(HW_SATAPHY_LANE0_DPLL_FREQ_RD() & ~(v)))
#define HW_SATAPHY_LANE0_DPLL_FREQ_TOG(v)    (HW_SATAPHY_LANE0_DPLL_FREQ_WR(HW_SATAPHY_LANE0_DPLL_FREQ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_DPLL_FREQ bitfields
 */

/* --- Register HW_SATAPHY_LANE0_DPLL_FREQ, field DTHR[0:0] (RW)
 *
 * Bits below the useful resolution
 */

#define BP_SATAPHY_LANE0_DPLL_FREQ_DTHR      (0)
#define BM_SATAPHY_LANE0_DPLL_FREQ_DTHR      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DPLL_FREQ_DTHR(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_DPLL_FREQ_DTHR)
#else
#define BF_SATAPHY_LANE0_DPLL_FREQ_DTHR(v)   (((v) << 0) & BM_SATAPHY_LANE0_DPLL_FREQ_DTHR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTHR field to a new value.
#define BW_SATAPHY_LANE0_DPLL_FREQ_DTHR(v)   BF_CS1(SATAPHY_LANE0_DPLL_FREQ, DTHR, v)
#endif

/* --- Register HW_SATAPHY_LANE0_DPLL_FREQ, field VAL[13:1] (RW)
 *
 * Frequency is 1.526 x VAL ppm from the reference
 */

#define BP_SATAPHY_LANE0_DPLL_FREQ_VAL      (1)
#define BM_SATAPHY_LANE0_DPLL_FREQ_VAL      (0x00003ffe)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_DPLL_FREQ_VAL(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_DPLL_FREQ_VAL)
#else
#define BF_SATAPHY_LANE0_DPLL_FREQ_VAL(v)   (((v) << 1) & BM_SATAPHY_LANE0_DPLL_FREQ_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VAL field to a new value.
#define BW_SATAPHY_LANE0_DPLL_FREQ_VAL(v)   BF_CS1(SATAPHY_LANE0_DPLL_FREQ, VAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_SCOPE_CTL - Scope Control Register (RW)
 *
 * Address: 0x201C  Reset value: 16'b x000 0000 0000 0000  This register contains control bits for
 * the per-transceiver scope portion.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MODE : 2; //!< Mode of counters:
        unsigned short DELAY : 9; //!< Number of symbols to skip between samples
        unsigned short BASE : 4; //!< The bit to be sampled when mode = 2'b01
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_sataphy_lane0_scope_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_SCOPE_CTL register
 */
#define HW_SATAPHY_LANE0_SCOPE_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201c)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_SCOPE_CTL           (*(volatile hw_sataphy_lane0_scope_ctl_t *) HW_SATAPHY_LANE0_SCOPE_CTL_ADDR)
#define HW_SATAPHY_LANE0_SCOPE_CTL_RD()      (HW_SATAPHY_LANE0_SCOPE_CTL.U)
#define HW_SATAPHY_LANE0_SCOPE_CTL_WR(v)     (HW_SATAPHY_LANE0_SCOPE_CTL.U = (v))
#define HW_SATAPHY_LANE0_SCOPE_CTL_SET(v)    (HW_SATAPHY_LANE0_SCOPE_CTL_WR(HW_SATAPHY_LANE0_SCOPE_CTL_RD() |  (v)))
#define HW_SATAPHY_LANE0_SCOPE_CTL_CLR(v)    (HW_SATAPHY_LANE0_SCOPE_CTL_WR(HW_SATAPHY_LANE0_SCOPE_CTL_RD() & ~(v)))
#define HW_SATAPHY_LANE0_SCOPE_CTL_TOG(v)    (HW_SATAPHY_LANE0_SCOPE_CTL_WR(HW_SATAPHY_LANE0_SCOPE_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_SCOPE_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_SCOPE_CTL, field MODE[1:0] (RW)
 *
 * Mode of counters:
 *
 * Values:
 * 00 - Off
 * 01 - Sample every 10 bits (see base)
 * 10 - Sample every 11 + 10 x delay bits
 * 11 - Sample every 12 + 10 x delay bits
 */

#define BP_SATAPHY_LANE0_SCOPE_CTL_MODE      (0)
#define BM_SATAPHY_LANE0_SCOPE_CTL_MODE      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_SCOPE_CTL_MODE(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_SCOPE_CTL_MODE)
#else
#define BF_SATAPHY_LANE0_SCOPE_CTL_MODE(v)   (((v) << 0) & BM_SATAPHY_LANE0_SCOPE_CTL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_SATAPHY_LANE0_SCOPE_CTL_MODE(v)   BF_CS1(SATAPHY_LANE0_SCOPE_CTL, MODE, v)
#endif


/* --- Register HW_SATAPHY_LANE0_SCOPE_CTL, field DELAY[10:2] (RW)
 *
 * Number of symbols to skip between samples
 */

#define BP_SATAPHY_LANE0_SCOPE_CTL_DELAY      (2)
#define BM_SATAPHY_LANE0_SCOPE_CTL_DELAY      (0x000007fc)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_SCOPE_CTL_DELAY(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_SCOPE_CTL_DELAY)
#else
#define BF_SATAPHY_LANE0_SCOPE_CTL_DELAY(v)   (((v) << 2) & BM_SATAPHY_LANE0_SCOPE_CTL_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DELAY field to a new value.
#define BW_SATAPHY_LANE0_SCOPE_CTL_DELAY(v)   BF_CS1(SATAPHY_LANE0_SCOPE_CTL, DELAY, v)
#endif

/* --- Register HW_SATAPHY_LANE0_SCOPE_CTL, field BASE[14:11] (RW)
 *
 * The bit to be sampled when mode = 2'b01
 */

#define BP_SATAPHY_LANE0_SCOPE_CTL_BASE      (11)
#define BM_SATAPHY_LANE0_SCOPE_CTL_BASE      (0x00007800)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_SCOPE_CTL_BASE(v)   ((((reg32_t) v) << 11) & BM_SATAPHY_LANE0_SCOPE_CTL_BASE)
#else
#define BF_SATAPHY_LANE0_SCOPE_CTL_BASE(v)   (((v) << 11) & BM_SATAPHY_LANE0_SCOPE_CTL_BASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BASE field to a new value.
#define BW_SATAPHY_LANE0_SCOPE_CTL_BASE(v)   BF_CS1(SATAPHY_LANE0_SCOPE_CTL, BASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_CTL - Receiver Control Register (RW)
 *
 * Address: 0x201D  Reset value: 16'b x000 0000 0000 1111  This register contains control bits for
 * the receiver in the recovered domain.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short PHDET_EN : 2; //!< Enables phase detector Top bit is odd slicers, bottom is even.
        unsigned short PHDET_EDGE : 2; //!< Edges to use for phase detection Top bit is rising edges, bottom is falling.
        unsigned short PHDET_POL : 1; //!< Reverses polarity of phase error
        unsigned short OVRD_DPLL_GAIN : 1; //!< Overrides phase update gain (PHUG) and frequency update gain (FRUG) values
        unsigned short PHUG_VALUE : 2; //!< Overrides value for phase update gain (PHUG)
        unsigned short FRUG_VALUE : 2; //!< Overrides value for frequency update gain (FRUG)
        unsigned short MODE_BP : 3; //!< Sets BP 2:0 to longer timescale (for FTS patterns):
        unsigned short OVRD_SWITCH : 1; //!< Overrides the value of the data/phase MUX
        unsigned short SWITCH_VAL : 1; //!< Value to override the data/phase MUX
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_sataphy_lane0_rx_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_CTL register
 */
#define HW_SATAPHY_LANE0_RX_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201d)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_CTL           (*(volatile hw_sataphy_lane0_rx_ctl_t *) HW_SATAPHY_LANE0_RX_CTL_ADDR)
#define HW_SATAPHY_LANE0_RX_CTL_RD()      (HW_SATAPHY_LANE0_RX_CTL.U)
#define HW_SATAPHY_LANE0_RX_CTL_WR(v)     (HW_SATAPHY_LANE0_RX_CTL.U = (v))
#define HW_SATAPHY_LANE0_RX_CTL_SET(v)    (HW_SATAPHY_LANE0_RX_CTL_WR(HW_SATAPHY_LANE0_RX_CTL_RD() |  (v)))
#define HW_SATAPHY_LANE0_RX_CTL_CLR(v)    (HW_SATAPHY_LANE0_RX_CTL_WR(HW_SATAPHY_LANE0_RX_CTL_RD() & ~(v)))
#define HW_SATAPHY_LANE0_RX_CTL_TOG(v)    (HW_SATAPHY_LANE0_RX_CTL_WR(HW_SATAPHY_LANE0_RX_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field PHDET_EN[1:0] (RW)
 *
 * Enables phase detector Top bit is odd slicers, bottom is even.
 */

#define BP_SATAPHY_LANE0_RX_CTL_PHDET_EN      (0)
#define BM_SATAPHY_LANE0_RX_CTL_PHDET_EN      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_EN(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_RX_CTL_PHDET_EN)
#else
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_EN(v)   (((v) << 0) & BM_SATAPHY_LANE0_RX_CTL_PHDET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_PHDET_EN(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, PHDET_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field PHDET_EDGE[3:2] (RW)
 *
 * Edges to use for phase detection Top bit is rising edges, bottom is falling.
 */

#define BP_SATAPHY_LANE0_RX_CTL_PHDET_EDGE      (2)
#define BM_SATAPHY_LANE0_RX_CTL_PHDET_EDGE      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_EDGE(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_RX_CTL_PHDET_EDGE)
#else
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_EDGE(v)   (((v) << 2) & BM_SATAPHY_LANE0_RX_CTL_PHDET_EDGE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_EDGE field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_PHDET_EDGE(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, PHDET_EDGE, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field PHDET_POL[4:4] (RW)
 *
 * Reverses polarity of phase error
 */

#define BP_SATAPHY_LANE0_RX_CTL_PHDET_POL      (4)
#define BM_SATAPHY_LANE0_RX_CTL_PHDET_POL      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_POL(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_RX_CTL_PHDET_POL)
#else
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_POL(v)   (((v) << 4) & BM_SATAPHY_LANE0_RX_CTL_PHDET_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_POL field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_PHDET_POL(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, PHDET_POL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field OVRD_DPLL_GAIN[5:5] (RW)
 *
 * Overrides phase update gain (PHUG) and frequency update gain (FRUG) values
 */

#define BP_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN      (5)
#define BM_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN)
#else
#define BF_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN(v)   (((v) << 5) & BM_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_DPLL_GAIN field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, OVRD_DPLL_GAIN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field PHUG_VALUE[7:6] (RW)
 *
 * Overrides value for phase update gain (PHUG)
 */

#define BP_SATAPHY_LANE0_RX_CTL_PHUG_VALUE      (6)
#define BM_SATAPHY_LANE0_RX_CTL_PHUG_VALUE      (0x000000c0)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_PHUG_VALUE(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_LANE0_RX_CTL_PHUG_VALUE)
#else
#define BF_SATAPHY_LANE0_RX_CTL_PHUG_VALUE(v)   (((v) << 6) & BM_SATAPHY_LANE0_RX_CTL_PHUG_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHUG_VALUE field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_PHUG_VALUE(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, PHUG_VALUE, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field FRUG_VALUE[9:8] (RW)
 *
 * Overrides value for frequency update gain (FRUG)
 */

#define BP_SATAPHY_LANE0_RX_CTL_FRUG_VALUE      (8)
#define BM_SATAPHY_LANE0_RX_CTL_FRUG_VALUE      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_FRUG_VALUE(v)   ((((reg32_t) v) << 8) & BM_SATAPHY_LANE0_RX_CTL_FRUG_VALUE)
#else
#define BF_SATAPHY_LANE0_RX_CTL_FRUG_VALUE(v)   (((v) << 8) & BM_SATAPHY_LANE0_RX_CTL_FRUG_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRUG_VALUE field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_FRUG_VALUE(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, FRUG_VALUE, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field MODE_BP[12:10] (RW)
 *
 * Sets BP 2:0 to longer timescale (for FTS patterns):
 *
 * Values:
 * 10 - Starts phase update gain (PHUG) profile at 4/3 cycles
 * 11 - Starts frequency update gain (FRUG) profile at 46/42 additional cycles
 * 12 - Ends frequency update gain (FRUG) profile at 142/110 additional cycles
 */

#define BP_SATAPHY_LANE0_RX_CTL_MODE_BP      (10)
#define BM_SATAPHY_LANE0_RX_CTL_MODE_BP      (0x00001c00)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_MODE_BP(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_LANE0_RX_CTL_MODE_BP)
#else
#define BF_SATAPHY_LANE0_RX_CTL_MODE_BP(v)   (((v) << 10) & BM_SATAPHY_LANE0_RX_CTL_MODE_BP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE_BP field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_MODE_BP(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, MODE_BP, v)
#endif


/* --- Register HW_SATAPHY_LANE0_RX_CTL, field OVRD_SWITCH[13:13] (RW)
 *
 * Overrides the value of the data/phase MUX
 */

#define BP_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH      (13)
#define BM_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH(v)   ((((reg32_t) v) << 13) & BM_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH)
#else
#define BF_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH(v)   (((v) << 13) & BM_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_SWITCH field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, OVRD_SWITCH, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field SWITCH_VAL[14:14] (RW)
 *
 * Value to override the data/phase MUX
 */

#define BP_SATAPHY_LANE0_RX_CTL_SWITCH_VAL      (14)
#define BM_SATAPHY_LANE0_RX_CTL_SWITCH_VAL      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_CTL_SWITCH_VAL(v)   ((((reg32_t) v) << 14) & BM_SATAPHY_LANE0_RX_CTL_SWITCH_VAL)
#else
#define BF_SATAPHY_LANE0_RX_CTL_SWITCH_VAL(v)   (((v) << 14) & BM_SATAPHY_LANE0_RX_CTL_SWITCH_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SWITCH_VAL field to a new value.
#define BW_SATAPHY_LANE0_RX_CTL_SWITCH_VAL(v)   BF_CS1(SATAPHY_LANE0_RX_CTL, SWITCH_VAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_DBG - Receiver Debug Register (RW)
 *
 * Address: 0x201E  Reset value: 16'b xxxx xxxx 0000 0000  This register contains control bits for
 * receiver debugging.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DTB_SEL0 : 4; //!< Selects wire to go on DTB bit 0
        unsigned short DTB_SEL1 : 4; //!< Selects wire to go on DTB bit 1
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_sataphy_lane0_rx_dbg_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_DBG register
 */
#define HW_SATAPHY_LANE0_RX_DBG_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201e)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_DBG           (*(volatile hw_sataphy_lane0_rx_dbg_t *) HW_SATAPHY_LANE0_RX_DBG_ADDR)
#define HW_SATAPHY_LANE0_RX_DBG_RD()      (HW_SATAPHY_LANE0_RX_DBG.U)
#define HW_SATAPHY_LANE0_RX_DBG_WR(v)     (HW_SATAPHY_LANE0_RX_DBG.U = (v))
#define HW_SATAPHY_LANE0_RX_DBG_SET(v)    (HW_SATAPHY_LANE0_RX_DBG_WR(HW_SATAPHY_LANE0_RX_DBG_RD() |  (v)))
#define HW_SATAPHY_LANE0_RX_DBG_CLR(v)    (HW_SATAPHY_LANE0_RX_DBG_WR(HW_SATAPHY_LANE0_RX_DBG_RD() & ~(v)))
#define HW_SATAPHY_LANE0_RX_DBG_TOG(v)    (HW_SATAPHY_LANE0_RX_DBG_WR(HW_SATAPHY_LANE0_RX_DBG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_DBG bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_DBG, field DTB_SEL0[3:0] (RW)
 *
 * Selects wire to go on DTB bit 0
 *
 * Values:
 * 0000 - Disabled
 * 0001 - ana_los
 * 0010 - los_ref_pos
 * 0011 - los_ref_neg_l
 * 0100 - sata_los
 * 0101 - los_rck
 * 0110 - eios_idle
 * 0111 - pcie_los
 * 1000 - coast_dpll
 * 1001 - misalign
 * 1010 - realign
 * 1011 - com_detect
 * 1100 - idl_detect
 * 1101 - fts_detect
 * 1110 - fts_err
 * 1111 - bp_state[1]
 */

#define BP_SATAPHY_LANE0_RX_DBG_DTB_SEL0      (0)
#define BM_SATAPHY_LANE0_RX_DBG_DTB_SEL0      (0x0000000f)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_DBG_DTB_SEL0(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_RX_DBG_DTB_SEL0)
#else
#define BF_SATAPHY_LANE0_RX_DBG_DTB_SEL0(v)   (((v) << 0) & BM_SATAPHY_LANE0_RX_DBG_DTB_SEL0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL0 field to a new value.
#define BW_SATAPHY_LANE0_RX_DBG_DTB_SEL0(v)   BF_CS1(SATAPHY_LANE0_RX_DBG, DTB_SEL0, v)
#endif


/* --- Register HW_SATAPHY_LANE0_RX_DBG, field DTB_SEL1[7:4] (RW)
 *
 * Selects wire to go on DTB bit 1
 *
 * Values:
 * 0000 - Disabled
 * 0001 - ana_los
 * 0010 - los_ref_pos
 * 0011 - los_ref_neg_l
 * 0100 - sata_los
 * 0101 - los_rck
 * 0110 - eios_idle
 * 0111 - pcie_los
 * 1000 - coast_dpll
 * 1001 - misalign
 * 1010 - realign
 * 1011 - com_detect
 * 1100 - idl_detect
 * 1101 - fts_detect
 * 1110 - fts_err
 * 1111 - bp_state[1]
 */

#define BP_SATAPHY_LANE0_RX_DBG_DTB_SEL1      (4)
#define BM_SATAPHY_LANE0_RX_DBG_DTB_SEL1      (0x000000f0)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_DBG_DTB_SEL1(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_RX_DBG_DTB_SEL1)
#else
#define BF_SATAPHY_LANE0_RX_DBG_DTB_SEL1(v)   (((v) << 4) & BM_SATAPHY_LANE0_RX_DBG_DTB_SEL1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL1 field to a new value.
#define BW_SATAPHY_LANE0_RX_DBG_DTB_SEL1(v)   BF_CS1(SATAPHY_LANE0_RX_DBG, DTB_SEL1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_ANA_CONTROL - Receive Analog Control Register (RW)
 *
 * Address: 0x203C  Reset value: 16'b xxxx xxxx xx10 0000  This register contains Rx control bits.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ATB_EN : 1; //!< ATB enable bit When this field is set to 1, internal atb_s_p,m = external atb_s_p,m.
        unsigned short MARGIN_EN : 1; //!< 1 RWCr Margin enable bit When this field is set to 1, margining is enabled. When doing margining, ensure that you set atb_en so that atb_s_p/m are connected.
        unsigned short RCK625_EN : 1; //!< rck625 enable bit When this field is set to 1, pll_alt_ref is driven by ck_i_p / 2.
        unsigned short RXLBE_EN : 1; //!< Wafer level (external) loopback enable bit When this field is set to 1, the lane's output (Tx) is connected to the lane's input (Rx) through pass gates.
        unsigned short RXLBI_EN : 1; //!< Digital serial (internal) loopback enable bit When this field is set to 1, an output from the serializer is connected to the first comparator stage.
        unsigned short RESERVED0 : 11; //!< Reserved
    } B;
} hw_sataphy_lane0_rx_ana_control_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_ANA_CONTROL register
 */
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2030)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL           (*(volatile hw_sataphy_lane0_rx_ana_control_t *) HW_SATAPHY_LANE0_RX_ANA_CONTROL_ADDR)
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL_RD()      (HW_SATAPHY_LANE0_RX_ANA_CONTROL.U)
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL_WR(v)     (HW_SATAPHY_LANE0_RX_ANA_CONTROL.U = (v))
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL_SET(v)    (HW_SATAPHY_LANE0_RX_ANA_CONTROL_WR(HW_SATAPHY_LANE0_RX_ANA_CONTROL_RD() |  (v)))
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL_CLR(v)    (HW_SATAPHY_LANE0_RX_ANA_CONTROL_WR(HW_SATAPHY_LANE0_RX_ANA_CONTROL_RD() & ~(v)))
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL_TOG(v)    (HW_SATAPHY_LANE0_RX_ANA_CONTROL_WR(HW_SATAPHY_LANE0_RX_ANA_CONTROL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_ANA_CONTROL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field ATB_EN[0:0] (RW)
 *
 * ATB enable bit When this field is set to 1, internal atb_s_p,m = external atb_s_p,m.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN      (0)
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN)
#else
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN(v)   (((v) << 0) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_CONTROL, ATB_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field MARGIN_EN[1:1] (RW)
 *
 * 1 RWCr Margin enable bit When this field is set to 1, margining is enabled. When doing margining,
 * ensure that you set atb_en so that atb_s_p/m are connected.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN      (1)
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN)
#else
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN(v)   (((v) << 1) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MARGIN_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_CONTROL, MARGIN_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field RCK625_EN[2:2] (RW)
 *
 * rck625 enable bit When this field is set to 1, pll_alt_ref is driven by ck_i_p / 2.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN      (2)
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN)
#else
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN(v)   (((v) << 2) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCK625_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_CONTROL, RCK625_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field RXLBE_EN[3:3] (RW)
 *
 * Wafer level (external) loopback enable bit When this field is set to 1, the lane's output (Tx) is
 * connected to the lane's input (Rx) through pass gates.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN      (3)
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN)
#else
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN(v)   (((v) << 3) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXLBE_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_CONTROL, RXLBE_EN, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field RXLBI_EN[4:4] (RW)
 *
 * Digital serial (internal) loopback enable bit When this field is set to 1, an output from the
 * serializer is connected to the first comparator stage.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN      (4)
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN)
#else
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN(v)   (((v) << 4) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXLBI_EN field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_CONTROL, RXLBI_EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_ANA_ATB - Receive ATB Register (RW)
 *
 * Address: 0x2031  Reset value: 16'b xxxx xxxx xx00 0000  This register contains Rx ATB bits.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short FORCEP_RX_P : 1; //!< Connects atb_f_p to rx_p Use for measuring Rx termination.
        unsigned short FORCEP_RX_M : 1; //!< Connects atb_f_p to rx_m Use for measuring Rx termination.
        unsigned short SENSEP_RX_P : 1; //!< Connects atb_s_p to rx_p Use for measuring Rx termination.
        unsigned short SENSEM_RX_M : 1; //!< Connects atb_s_m to rx_m Use for measuring Rx termination.
        unsigned short SENSEM_VCM : 1; //!< Connects atb_s_m to Rx vcm Use in margining.
        unsigned short SENSEM_VREF_LOS : 1; //!< Connects atb_s_m to vref_los (vref_rx / 14)
        unsigned short RESERVED0 : 10; //!< Reserved
    } B;
} hw_sataphy_lane0_rx_ana_atb_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_ANA_ATB register
 */
#define HW_SATAPHY_LANE0_RX_ANA_ATB_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2031)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_ANA_ATB           (*(volatile hw_sataphy_lane0_rx_ana_atb_t *) HW_SATAPHY_LANE0_RX_ANA_ATB_ADDR)
#define HW_SATAPHY_LANE0_RX_ANA_ATB_RD()      (HW_SATAPHY_LANE0_RX_ANA_ATB.U)
#define HW_SATAPHY_LANE0_RX_ANA_ATB_WR(v)     (HW_SATAPHY_LANE0_RX_ANA_ATB.U = (v))
#define HW_SATAPHY_LANE0_RX_ANA_ATB_SET(v)    (HW_SATAPHY_LANE0_RX_ANA_ATB_WR(HW_SATAPHY_LANE0_RX_ANA_ATB_RD() |  (v)))
#define HW_SATAPHY_LANE0_RX_ANA_ATB_CLR(v)    (HW_SATAPHY_LANE0_RX_ANA_ATB_WR(HW_SATAPHY_LANE0_RX_ANA_ATB_RD() & ~(v)))
#define HW_SATAPHY_LANE0_RX_ANA_ATB_TOG(v)    (HW_SATAPHY_LANE0_RX_ANA_ATB_WR(HW_SATAPHY_LANE0_RX_ANA_ATB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_ANA_ATB bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field FORCEP_RX_P[0:0] (RW)
 *
 * Connects atb_f_p to rx_p Use for measuring Rx termination.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P      (0)
#define BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P)
#else
#define BF_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P(v)   (((v) << 0) & BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FORCEP_RX_P field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_ATB, FORCEP_RX_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field FORCEP_RX_M[1:1] (RW)
 *
 * Connects atb_f_p to rx_m Use for measuring Rx termination.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M      (1)
#define BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M)
#else
#define BF_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M(v)   (((v) << 1) & BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FORCEP_RX_M field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_ATB, FORCEP_RX_M, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field SENSEP_RX_P[2:2] (RW)
 *
 * Connects atb_s_p to rx_p Use for measuring Rx termination.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P      (2)
#define BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P)
#else
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P(v)   (((v) << 2) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SENSEP_RX_P field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_ATB, SENSEP_RX_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field SENSEM_RX_M[3:3] (RW)
 *
 * Connects atb_s_m to rx_m Use for measuring Rx termination.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M      (3)
#define BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M)
#else
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M(v)   (((v) << 3) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SENSEM_RX_M field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_ATB, SENSEM_RX_M, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field SENSEM_VCM[4:4] (RW)
 *
 * Connects atb_s_m to Rx vcm Use in margining.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM      (4)
#define BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM)
#else
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM(v)   (((v) << 4) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SENSEM_VCM field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_ATB, SENSEM_VCM, v)
#endif

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field SENSEM_VREF_LOS[5:5] (RW)
 *
 * Connects atb_s_m to vref_los (vref_rx / 14)
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS      (5)
#define BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS)
#else
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS(v)   (((v) << 5) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SENSEM_VREF_LOS field to a new value.
#define BW_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS(v)   BF_CS1(SATAPHY_LANE0_RX_ANA_ATB, SENSEM_VREF_LOS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PLL_PRG2 - Rx PLL Programming 2 Register (RW)
 *
 * Address: 0x2032  Reset value: 16'b xxxx xxxx 0000 0000  This is an 8-bit programming register.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ENABLE_TEST_PD : 1; //!< Controls phase interpolator test mode:
        unsigned short RESET_LCL : 1; //!< Resets PLL: Field is valid only when frc_reset is set to 1'b1.
        unsigned short FRC_RESET : 1; //!< Enables override of default value of pll_pwron. Enables pwron_lcl to control PLL power-on.
        unsigned short PWRON_LCL : 1; //!< Controls power to PLL: Field is valid only when frc_pwron is set to 1'b1.
        unsigned short FRC_PWRON : 1; //!< Enables override of default value of pll_pwron. Enables pwron_lcl to control PLL power-on.
        unsigned short HCPL_LCL : 1; //!< Forces coupling in VCO: Field is valid only when frc_hcpl is set to 1'b1.
        unsigned short FRC_HCPL : 1; //!< Enables override of hcpl default value. Enables hcpl_lcl to control high-coupling mode.
        unsigned short ATB_SENSE_SEL : 1; //!< Controls proportional charge pump current:
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_sataphy_lane0_pll_prg2_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PLL_PRG2 register
 */
#define HW_SATAPHY_LANE0_PLL_PRG2_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2032)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PLL_PRG2           (*(volatile hw_sataphy_lane0_pll_prg2_t *) HW_SATAPHY_LANE0_PLL_PRG2_ADDR)
#define HW_SATAPHY_LANE0_PLL_PRG2_RD()      (HW_SATAPHY_LANE0_PLL_PRG2.U)
#define HW_SATAPHY_LANE0_PLL_PRG2_WR(v)     (HW_SATAPHY_LANE0_PLL_PRG2.U = (v))
#define HW_SATAPHY_LANE0_PLL_PRG2_SET(v)    (HW_SATAPHY_LANE0_PLL_PRG2_WR(HW_SATAPHY_LANE0_PLL_PRG2_RD() |  (v)))
#define HW_SATAPHY_LANE0_PLL_PRG2_CLR(v)    (HW_SATAPHY_LANE0_PLL_PRG2_WR(HW_SATAPHY_LANE0_PLL_PRG2_RD() & ~(v)))
#define HW_SATAPHY_LANE0_PLL_PRG2_TOG(v)    (HW_SATAPHY_LANE0_PLL_PRG2_WR(HW_SATAPHY_LANE0_PLL_PRG2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PLL_PRG2 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field ENABLE_TEST_PD[0:0] (RW)
 *
 * Controls phase interpolator test mode:
 *
 * Values:
 * 0 - Disables phase interpolator test mode.
 * 1 - Tests phase linearity of phase interpolator and VCO.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD      (0)
#define BM_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD)
#else
#define BF_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD(v)   (((v) << 0) & BM_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_TEST_PD field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG2, ENABLE_TEST_PD, v)
#endif


/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field RESET_LCL[1:1] (RW)
 *
 * Resets PLL: Field is valid only when frc_reset is set to 1'b1.
 *
 * Values:
 * 0 - PLL is in normal mode.
 * 1 - PLL is held/placed in reset.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_RESET_LCL      (1)
#define BM_SATAPHY_LANE0_PLL_PRG2_RESET_LCL      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG2_RESET_LCL(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_PLL_PRG2_RESET_LCL)
#else
#define BF_SATAPHY_LANE0_PLL_PRG2_RESET_LCL(v)   (((v) << 1) & BM_SATAPHY_LANE0_PLL_PRG2_RESET_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET_LCL field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG2_RESET_LCL(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG2, RESET_LCL, v)
#endif


/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field FRC_RESET[2:2] (RW)
 *
 * Enables override of default value of pll_pwron. Enables pwron_lcl to control PLL power-on.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_FRC_RESET      (2)
#define BM_SATAPHY_LANE0_PLL_PRG2_FRC_RESET      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_RESET(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_RESET)
#else
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_RESET(v)   (((v) << 2) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_RESET field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG2_FRC_RESET(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG2, FRC_RESET, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field PWRON_LCL[3:3] (RW)
 *
 * Controls power to PLL: Field is valid only when frc_pwron is set to 1'b1.
 *
 * Values:
 * 0 - Powers down PLL.
 * 1 - Supplies power to PLL.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL      (3)
#define BM_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL)
#else
#define BF_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL(v)   (((v) << 3) & BM_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PWRON_LCL field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG2, PWRON_LCL, v)
#endif


/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field FRC_PWRON[4:4] (RW)
 *
 * Enables override of default value of pll_pwron. Enables pwron_lcl to control PLL power-on.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON      (4)
#define BM_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON)
#else
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON(v)   (((v) << 4) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_PWRON field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG2, FRC_PWRON, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field HCPL_LCL[5:5] (RW)
 *
 * Forces coupling in VCO: Field is valid only when frc_hcpl is set to 1'b1.
 *
 * Values:
 * 0 - Forces coupling in VCO to minimum.
 * 1 - Forces coupling in VCO to maximum.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL      (5)
#define BM_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL)
#else
#define BF_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL(v)   (((v) << 5) & BM_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HCPL_LCL field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG2, HCPL_LCL, v)
#endif


/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field FRC_HCPL[6:6] (RW)
 *
 * Enables override of hcpl default value. Enables hcpl_lcl to control high-coupling mode.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL      (6)
#define BM_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL)
#else
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL(v)   (((v) << 6) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_HCPL field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG2, FRC_HCPL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field ATB_SENSE_SEL[7:7] (RW)
 *
 * Controls proportional charge pump current:
 *
 * Values:
 * 0 - Disconnects PLL from analog test bus. No PLL signals can be viewed on the ATB.
 * 1 - Enables signals internal to PLL to connect to the analog test bus.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL      (7)
#define BM_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL(v)   ((((reg32_t) v) << 7) & BM_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL)
#else
#define BF_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL(v)   (((v) << 7) & BM_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_SENSE_SEL field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG2, ATB_SENSE_SEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PLL_PRG1 - Rx PLL Programming 1 Register (RW)
 *
 * Address: 0x2033  Reset value: 16'b xxxx xx10 1010 1001  This is a 10-bit programming register.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RESERVED0 : 2; //!< Reserved
        unsigned short INT_CNTRL : 3; //!< Controls integral charge pump current Integral current = (n + 1) / 8 x full_scale Default value = 3'b010: 0.375 x full_scale
        unsigned short PROP_CNTRL : 3; //!< Controls proportional charge pump current Proportional current = (n + 1) / 8 x full_scale Default value = 3'b101: 0.75 x full_scale
        unsigned short SEL_RXCK : 1; //!< Uses recovered clock as reference to the PLL:
        unsigned short RESERVED1 : 7; //!< Reserved
    } B;
} hw_sataphy_lane0_pll_prg1_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PLL_PRG1 register
 */
#define HW_SATAPHY_LANE0_PLL_PRG1_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2033)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PLL_PRG1           (*(volatile hw_sataphy_lane0_pll_prg1_t *) HW_SATAPHY_LANE0_PLL_PRG1_ADDR)
#define HW_SATAPHY_LANE0_PLL_PRG1_RD()      (HW_SATAPHY_LANE0_PLL_PRG1.U)
#define HW_SATAPHY_LANE0_PLL_PRG1_WR(v)     (HW_SATAPHY_LANE0_PLL_PRG1.U = (v))
#define HW_SATAPHY_LANE0_PLL_PRG1_SET(v)    (HW_SATAPHY_LANE0_PLL_PRG1_WR(HW_SATAPHY_LANE0_PLL_PRG1_RD() |  (v)))
#define HW_SATAPHY_LANE0_PLL_PRG1_CLR(v)    (HW_SATAPHY_LANE0_PLL_PRG1_WR(HW_SATAPHY_LANE0_PLL_PRG1_RD() & ~(v)))
#define HW_SATAPHY_LANE0_PLL_PRG1_TOG(v)    (HW_SATAPHY_LANE0_PLL_PRG1_WR(HW_SATAPHY_LANE0_PLL_PRG1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PLL_PRG1 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PLL_PRG1, field INT_CNTRL[4:2] (RW)
 *
 * Controls integral charge pump current Integral current = (n + 1) / 8 x full_scale Default value =
 * 3'b010: 0.375 x full_scale
 */

#define BP_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL      (2)
#define BM_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL      (0x0000001c)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL)
#else
#define BF_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL(v)   (((v) << 2) & BM_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_CNTRL field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG1, INT_CNTRL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG1, field PROP_CNTRL[7:5] (RW)
 *
 * Controls proportional charge pump current Proportional current = (n + 1) / 8 x full_scale Default
 * value = 3'b101: 0.75 x full_scale
 */

#define BP_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL      (5)
#define BM_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL      (0x000000e0)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL)
#else
#define BF_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL(v)   (((v) << 5) & BM_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PROP_CNTRL field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG1, PROP_CNTRL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG1, field SEL_RXCK[8:8] (RW)
 *
 * Uses recovered clock as reference to the PLL:
 *
 * Values:
 * 0 - Uses MPLL output as reference to the PLL
 * 1 - Uses recovered clock as reference to PLL
 */

#define BP_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK      (8)
#define BM_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK(v)   ((((reg32_t) v) << 8) & BM_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK)
#else
#define BF_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK(v)   (((v) << 8) & BM_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEL_RXCK field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG1, SEL_RXCK, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PLL_PRG3 - Rx PLL Measurement Register (RW)
 *
 * Address: 0x2034  Reset value: 16'b xxxx xx00 0000 0000  This is a 10-bit programming register.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RESERVED0 : 1; //!< Reserved
        unsigned short MEAS_CROWBAR : 1; //!< Measures crowbar bias voltage on atb_sense_p; gd on atb_sense_m.
        unsigned short MEAS_1V : 1; //!< Measures 1-V supply voltage on atb_sense_m. If meas_vp_cp is also set, atb_sense_p,m measures vpcp - vp.
        unsigned short MEAS_VP_CP : 1; //!< Measures vp_cp voltage on atb_sense_p; gd on atb_sense_m. If meas_1v is also set, atb_sense_p,m measures vpcp - vp.
        unsigned short MEAS_VCO : 1; //!< Measures VCO supply voltage on atb_sense_p; gd on atb_sense_m.
        unsigned short MEAS_STARTUP : 1; //!< Measures startup voltage on atb_sense_p; gd on atb_sense_m.
        unsigned short MEAS_VP16 : 1; //!< Measures vp16 on atb_sense_p; gd on atb_sense_m.
        unsigned short MEAS_VREF : 1; //!< Measures vref on atb_sense_p; gd on atb_sense_m. If meas_vcntrl is also set, atb_sense_p,m measures vref - vcntrl.
        unsigned short MEAS_VCNTRL : 1; //!< Measures vcntrl on atb_sense_m. If meas_vref is also set, atb_sense_p,m measures vref - vcntrl.
        unsigned short MEAS_BIAS : 1; //!< Measures copy of bias current in oscillator on atb_force_m.
        unsigned short RESERVED1 : 6; //!< Reserved
    } B;
} hw_sataphy_lane0_pll_prg3_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PLL_PRG3 register
 */
#define HW_SATAPHY_LANE0_PLL_PRG3_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2034)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PLL_PRG3           (*(volatile hw_sataphy_lane0_pll_prg3_t *) HW_SATAPHY_LANE0_PLL_PRG3_ADDR)
#define HW_SATAPHY_LANE0_PLL_PRG3_RD()      (HW_SATAPHY_LANE0_PLL_PRG3.U)
#define HW_SATAPHY_LANE0_PLL_PRG3_WR(v)     (HW_SATAPHY_LANE0_PLL_PRG3.U = (v))
#define HW_SATAPHY_LANE0_PLL_PRG3_SET(v)    (HW_SATAPHY_LANE0_PLL_PRG3_WR(HW_SATAPHY_LANE0_PLL_PRG3_RD() |  (v)))
#define HW_SATAPHY_LANE0_PLL_PRG3_CLR(v)    (HW_SATAPHY_LANE0_PLL_PRG3_WR(HW_SATAPHY_LANE0_PLL_PRG3_RD() & ~(v)))
#define HW_SATAPHY_LANE0_PLL_PRG3_TOG(v)    (HW_SATAPHY_LANE0_PLL_PRG3_WR(HW_SATAPHY_LANE0_PLL_PRG3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PLL_PRG3 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_CROWBAR[1:1] (RW)
 *
 * Measures crowbar bias voltage on atb_sense_p; gd on atb_sense_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR      (1)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR(v)   (((v) << 1) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_CROWBAR field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_CROWBAR, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_1V[2:2] (RW)
 *
 * Measures 1-V supply voltage on atb_sense_m. If meas_vp_cp is also set, atb_sense_p,m measures
 * vpcp - vp.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_1V      (2)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_1V      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_1V(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_1V)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_1V(v)   (((v) << 2) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_1V)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_1V field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_1V(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_1V, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VP_CP[3:3] (RW)
 *
 * Measures vp_cp voltage on atb_sense_p; gd on atb_sense_m. If meas_1v is also set, atb_sense_p,m
 * measures vpcp - vp.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP      (3)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP(v)   (((v) << 3) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_VP_CP field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_VP_CP, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VCO[4:4] (RW)
 *
 * Measures VCO supply voltage on atb_sense_p; gd on atb_sense_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO      (4)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO(v)   (((v) << 4) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_VCO field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_VCO, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_STARTUP[5:5] (RW)
 *
 * Measures startup voltage on atb_sense_p; gd on atb_sense_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP      (5)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP(v)   (((v) << 5) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_STARTUP field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_STARTUP, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VP16[6:6] (RW)
 *
 * Measures vp16 on atb_sense_p; gd on atb_sense_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16      (6)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16(v)   (((v) << 6) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_VP16 field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_VP16, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VREF[7:7] (RW)
 *
 * Measures vref on atb_sense_p; gd on atb_sense_m. If meas_vcntrl is also set, atb_sense_p,m
 * measures vref - vcntrl.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF      (7)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF(v)   ((((reg32_t) v) << 7) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF(v)   (((v) << 7) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_VREF field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_VREF, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VCNTRL[8:8] (RW)
 *
 * Measures vcntrl on atb_sense_m. If meas_vref is also set, atb_sense_p,m measures vref - vcntrl.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL      (8)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL(v)   ((((reg32_t) v) << 8) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL(v)   (((v) << 8) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_VCNTRL field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_VCNTRL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_BIAS[9:9] (RW)
 *
 * Measures copy of bias current in oscillator on atb_force_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS      (9)
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS(v)   ((((reg32_t) v) << 9) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS)
#else
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS(v)   (((v) << 9) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_BIAS field to a new value.
#define BW_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS(v)   BF_CS1(SATAPHY_LANE0_PLL_PRG3, MEAS_BIAS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_ANA_ATBSEL1 - Transmit ATB 1 Control Register (RW)
 *
 * Address: 0x2035  Reset value: 16"b xxxx xxxx 0000 0000  This register contains Tx ATB control
 * bits.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short VGR_S_P : 1; //!< Regulator gate voltage on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short VREF_S_P : 1; //!< tx_vref voltage on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short VREG_S_M : 1; //!< Regulator output voltage on ATB_S_M To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short TXP_F_P : 1; //!< txp connected to ATB_F_P For termination resistance measurements.
        unsigned short TXP_S_P : 1; //!< txp connected to ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short TXM_F_P : 1; //!< txm connected to ATB_S_P For termination resistance measurements.
        unsigned short TXM_S_M : 1; //!< txm on ATB_S_M To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short VBPF_S_P : 1; //!< vbpf in edge rate control circuit on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_sataphy_lane0_tx_ana_atbsel1_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_ANA_ATBSEL1 register
 */
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2035)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1           (*(volatile hw_sataphy_lane0_tx_ana_atbsel1_t *) HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_ADDR)
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_RD()      (HW_SATAPHY_LANE0_TX_ANA_ATBSEL1.U)
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_WR(v)     (HW_SATAPHY_LANE0_TX_ANA_ATBSEL1.U = (v))
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_SET(v)    (HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_WR(HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_RD() |  (v)))
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_CLR(v)    (HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_WR(HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_RD() & ~(v)))
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_TOG(v)    (HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_WR(HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_ANA_ATBSEL1 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field VGR_S_P[0:0] (RW)
 *
 * Regulator gate voltage on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P      (0)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P(v)   (((v) << 0) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VGR_S_P field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL1, VGR_S_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field VREF_S_P[1:1] (RW)
 *
 * tx_vref voltage on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P      (1)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P(v)   (((v) << 1) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VREF_S_P field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL1, VREF_S_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field VREG_S_M[2:2] (RW)
 *
 * Regulator output voltage on ATB_S_M To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M      (2)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M(v)   (((v) << 2) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VREG_S_M field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL1, VREG_S_M, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field TXP_F_P[3:3] (RW)
 *
 * txp connected to ATB_F_P For termination resistance measurements.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P      (3)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P(v)   (((v) << 3) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXP_F_P field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL1, TXP_F_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field TXP_S_P[4:4] (RW)
 *
 * txp connected to ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P      (4)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P(v)   (((v) << 4) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXP_S_P field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL1, TXP_S_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field TXM_F_P[5:5] (RW)
 *
 * txm connected to ATB_S_P For termination resistance measurements.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P      (5)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P(v)   (((v) << 5) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXM_F_P field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL1, TXM_F_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field TXM_S_M[6:6] (RW)
 *
 * txm on ATB_S_M To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M      (6)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M(v)   (((v) << 6) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXM_S_M field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL1, TXM_S_M, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field VBPF_S_P[7:7] (RW)
 *
 * vbpf in edge rate control circuit on ATB_S_P To validate this field, set
 * lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P      (7)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P(v)   ((((reg32_t) v) << 7) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P(v)   (((v) << 7) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VBPF_S_P field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL1, VBPF_S_P, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_ANA_ATBSEL2 - Transmit ATB 2 Control Register (RW)
 *
 * Address: 0x2036  Reset value: 16'b xxxx xxxx 0000 0000  This register contains Tx ATB control
 * bits.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short EN_TXILPBK : 1; //!< Enables Tx internal loopback
        unsigned short ENLPBK : 1; //!< Enables Tx external loopback Ensure that internal loopback is not on.
        unsigned short VBNF_S_M : 1; //!< vbnf in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
        unsigned short VBPS_S_P : 1; //!< vbps in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
        unsigned short VBNS_S_M : 1; //!< vbps in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
        unsigned short VCM_S_P : 1; //!< Vcm replica on ATB_S_P To validate this field, set the atb_en field.
        unsigned short VREFRXD_S_M : 1; //!< Reference voltage for RX_DETECT on ATB_S_M To validate this field, set the atb_en field.
        unsigned short ATB_EN : 1; //!< RWCr 7 RWCr Connects internal and external ATB buses Required for all ATB measurements.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_sataphy_lane0_tx_ana_atbsel2_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_ANA_ATBSEL2 register
 */
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2036)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2           (*(volatile hw_sataphy_lane0_tx_ana_atbsel2_t *) HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_ADDR)
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_RD()      (HW_SATAPHY_LANE0_TX_ANA_ATBSEL2.U)
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_WR(v)     (HW_SATAPHY_LANE0_TX_ANA_ATBSEL2.U = (v))
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_SET(v)    (HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_WR(HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_RD() |  (v)))
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_CLR(v)    (HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_WR(HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_RD() & ~(v)))
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_TOG(v)    (HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_WR(HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_ANA_ATBSEL2 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field EN_TXILPBK[0:0] (RW)
 *
 * Enables Tx internal loopback
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK      (0)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK(v)   (((v) << 0) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_TXILPBK field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL2, EN_TXILPBK, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field ENLPBK[1:1] (RW)
 *
 * Enables Tx external loopback Ensure that internal loopback is not on.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK      (1)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK(v)   (((v) << 1) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENLPBK field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL2, ENLPBK, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VBNF_S_M[2:2] (RW)
 *
 * vbnf in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M      (2)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M(v)   (((v) << 2) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VBNF_S_M field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL2, VBNF_S_M, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VBPS_S_P[3:3] (RW)
 *
 * vbps in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P      (3)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P(v)   (((v) << 3) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VBPS_S_P field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL2, VBPS_S_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VBNS_S_M[4:4] (RW)
 *
 * vbps in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M      (4)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M(v)   (((v) << 4) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VBNS_S_M field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL2, VBNS_S_M, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VCM_S_P[5:5] (RW)
 *
 * Vcm replica on ATB_S_P To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P      (5)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P(v)   (((v) << 5) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VCM_S_P field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL2, VCM_S_P, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VREFRXD_S_M[6:6] (RW)
 *
 * Reference voltage for RX_DETECT on ATB_S_M To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M      (6)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M(v)   (((v) << 6) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VREFRXD_S_M field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL2, VREFRXD_S_M, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field ATB_EN[7:7] (RW)
 *
 * RWCr 7 RWCr Connects internal and external ATB buses Required for all ATB measurements.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN      (7)
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN(v)   ((((reg32_t) v) << 7) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN)
#else
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN(v)   (((v) << 7) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_EN field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_ATBSEL2, ATB_EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_ANA_CONTROL - Transmit Analog Control Register (RW)
 *
 * Address: 0x237  Reset value: 16"b xxxx xxxx 0000 0000  This register contains Tx power state
 * control bits.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RESERVED0 : 1; //!< Reserved
        unsigned short BCN_LCL : 1; //!< Local beacon on/off control value To validate this field, set lane0.tx_ana.control.frc_beacon.
        unsigned short FRC_BEACON : 1; //!< Forces beacon to local value (bcn_lcl) When this field is set to 1, BCN_LVL overrides input value.
        unsigned short DATAOVRD_LCL : 1; //!< RWCr Local dataovrd control value To validate this field, set lane0.tx_ana.control.frc_do.
        unsigned short FRC_DO : 1; //!< Forces dataovrd locally When set to 1, this field overrides the input data_ovrd value.
        unsigned short EN_LCL : 2; //!< Locally forces tx_en[1:0]:
        unsigned short FRC_PWRST : 1; //!< Locally forces power state When this field is set to 1, the tx_en[1:0] input is overridden by en_lcl.
        unsigned short RESERVED1 : 8; //!< Reserved
    } B;
} hw_sataphy_lane0_tx_ana_control_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_ANA_CONTROL register
 */
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2037)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL           (*(volatile hw_sataphy_lane0_tx_ana_control_t *) HW_SATAPHY_LANE0_TX_ANA_CONTROL_ADDR)
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL_RD()      (HW_SATAPHY_LANE0_TX_ANA_CONTROL.U)
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL_WR(v)     (HW_SATAPHY_LANE0_TX_ANA_CONTROL.U = (v))
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL_SET(v)    (HW_SATAPHY_LANE0_TX_ANA_CONTROL_WR(HW_SATAPHY_LANE0_TX_ANA_CONTROL_RD() |  (v)))
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL_CLR(v)    (HW_SATAPHY_LANE0_TX_ANA_CONTROL_WR(HW_SATAPHY_LANE0_TX_ANA_CONTROL_RD() & ~(v)))
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL_TOG(v)    (HW_SATAPHY_LANE0_TX_ANA_CONTROL_WR(HW_SATAPHY_LANE0_TX_ANA_CONTROL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_ANA_CONTROL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field BCN_LCL[1:1] (RW)
 *
 * Local beacon on/off control value To validate this field, set lane0.tx_ana.control.frc_beacon.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL      (1)
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL)
#else
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL(v)   (((v) << 1) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCN_LCL field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_CONTROL, BCN_LCL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field FRC_BEACON[2:2] (RW)
 *
 * Forces beacon to local value (bcn_lcl) When this field is set to 1, BCN_LVL overrides input
 * value.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON      (2)
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON)
#else
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON(v)   (((v) << 2) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_BEACON field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_CONTROL, FRC_BEACON, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field DATAOVRD_LCL[3:3] (RW)
 *
 * RWCr Local dataovrd control value To validate this field, set lane0.tx_ana.control.frc_do.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL      (3)
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL)
#else
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL(v)   (((v) << 3) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAOVRD_LCL field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_CONTROL, DATAOVRD_LCL, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field FRC_DO[4:4] (RW)
 *
 * Forces dataovrd locally When set to 1, this field overrides the input data_ovrd value.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO      (4)
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO)
#else
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO(v)   (((v) << 4) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_DO field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_CONTROL, FRC_DO, v)
#endif

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field EN_LCL[6:5] (RW)
 *
 * Locally forces tx_en[1:0]:
 *
 * Values:
 * 00 - Power off
 * 01 - Tx idle (slow)
 * 10 - Transmit data
 * 11 - Tx idle (fast)
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL      (5)
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL      (0x00000060)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL)
#else
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL(v)   (((v) << 5) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_LCL field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_CONTROL, EN_LCL, v)
#endif


/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field FRC_PWRST[7:7] (RW)
 *
 * Locally forces power state When this field is set to 1, the tx_en[1:0] input is overridden by
 * en_lcl.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST      (7)
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST(v)   ((((reg32_t) v) << 7) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST)
#else
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST(v)   (((v) << 7) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_PWRST field to a new value.
#define BW_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST(v)   BF_CS1(SATAPHY_LANE0_TX_ANA_CONTROL, FRC_PWRST, v)
#endif


/*!
 * @brief All SATAPHY_LANE0 module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg8_t _reserved0[8193];
    volatile hw_sataphy_lane0_tx_stat_t TX_STAT; //!< Transmit Input Status Register
    volatile hw_sataphy_lane0_rx_stat_t RX_STAT; //!< Receiver Input Status Register
    volatile hw_sataphy_lane0_out_stat_t OUT_STAT; //!< Output Status Register
    volatile hw_sataphy_lane0_tx_ovrd_t TX_OVRD; //!< Transmit Input Override Register
    volatile hw_sataphy_lane0_rx_ovrd_t RX_OVRD; //!< Receive Input Override Register
    volatile hw_sataphy_lane0_out_ovrd_t OUT_OVRD; //!< Output Override Register
    volatile hw_sataphy_lane0_dbg_ctl_t DBG_CTL; //!< Debug Control Register
    reg8_t _reserved1;
    volatile hw_sataphy_lane0_pg_ctl_t PG_CTL; //!< Pattern Generator Control Register
    reg16_t _reserved2[3];
    volatile hw_sataphy_lane0_pm_ctl_t PM_CTL; //!< Pattern Matcher Control Register
    volatile hw_sataphy_lane0_pm_err_t PM_ERR; //!< Pattern Matcher Error Register
    volatile hw_sataphy_lane0_dpll_phase_t DPLL_PHASE; //!< DPLL Phase Register
    volatile hw_sataphy_lane0_dpll_freq_t DPLL_FREQ; //!< DPLL Frequency Register
    volatile hw_sataphy_lane0_scope_ctl_t SCOPE_CTL; //!< Scope Control Register
    volatile hw_sataphy_lane0_rx_ctl_t RX_CTL; //!< Receiver Control Register
    volatile hw_sataphy_lane0_rx_dbg_t RX_DBG; //!< Receiver Debug Register
    reg16_t _reserved3[5];
    volatile hw_sataphy_lane0_rx_ana_control_t RX_ANA_CONTROL; //!< Receive Analog Control Register
    volatile hw_sataphy_lane0_rx_ana_atb_t RX_ANA_ATB; //!< Receive ATB Register
    volatile hw_sataphy_lane0_pll_prg2_t PLL_PRG2; //!< Rx PLL Programming 2 Register
    volatile hw_sataphy_lane0_pll_prg1_t PLL_PRG1; //!< Rx PLL Programming 1 Register
    volatile hw_sataphy_lane0_pll_prg3_t PLL_PRG3; //!< Rx PLL Measurement Register
    volatile hw_sataphy_lane0_tx_ana_atbsel1_t TX_ANA_ATBSEL1; //!< Transmit ATB 1 Control Register
    volatile hw_sataphy_lane0_tx_ana_atbsel2_t TX_ANA_ATBSEL2; //!< Transmit ATB 2 Control Register
    volatile hw_sataphy_lane0_tx_ana_control_t TX_ANA_CONTROL; //!< Transmit Analog Control Register
} hw_sataphy_lane0_t;
#endif

//! @brief Macro to access all SATAPHY_LANE0 registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SATAPHY_LANE0(0)</code>.
#define HW_SATAPHY_LANE0     (*(volatile hw_sataphy_lane0_t *) REGS_SATAPHY_LANE0_BASE)


#endif // _SATAPHY_LANE0_H
