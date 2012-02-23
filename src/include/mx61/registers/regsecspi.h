/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _ECSPI_H
#define _ECSPI_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_ECSPI_RXDATA - Receive Data Register
 * - HW_ECSPI_TXDATA - Transmit Data Register
 * - HW_ECSPI_CONREG - Control Register
 * - HW_ECSPI_CONFIGREG - Config Register
 * - HW_ECSPI_INTREG - Interrupt Control Register
 * - HW_ECSPI_DMAREG - DMA Control Register
 * - HW_ECSPI_STATREG - Status Register
 * - HW_ECSPI_PERIODREG - Sample Period Control Register
 * - HW_ECSPI_TESTREG - Test Control Register
 * - HW_ECSPI_MSGDATA - Message Data Register
 *
 * hw_ecspi_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ECSPI_BASE
#define REGS_ECSPI0_BASE (0x02008000) //!< Base address for ECSPI instance number 0.
#define REGS_ECSPI1_BASE (0x0200c000) //!< Base address for ECSPI instance number 1.
#define REGS_ECSPI2_BASE (0x02010000) //!< Base address for ECSPI instance number 2.
#define REGS_ECSPI3_BASE (0x02014000) //!< Base address for ECSPI instance number 3.
#define REGS_ECSPI4_BASE (0x02018000) //!< Base address for ECSPI instance number 4.

//! @brief Get the base address of ECSPI by instance number.
//! @param x ECSPI instance number, from 0 through 5.
#define REGS_ECSPI_BASE(x) ( x == 0 ? REGS_ECSPI0_BASE : x == 1 ? REGS_ECSPI1_BASE : x == 2 ? REGS_ECSPI2_BASE : x == 3 ? REGS_ECSPI3_BASE : x == 4 ? REGS_ECSPI4_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_RXDATA - Receive Data Register (RO)
 *
 * The Receive Data register (ECSPI_RXDATA) is a read-only register that forms the top word of the 8
 * 64 x 32 receive FIFO. This register holds the data received from an external SPI device during a
 * data transaction. Only word-sized read operations are allowed.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ECSPI_RXDATA : 32; //!< Receive Data. This register holds the top word of the receive data FIFO. The FIFO is advanced for each read of this register. The data read is undefined when the Receive Data Ready (RR) bit in the Interrupt Control/Status register is cleared. Zeros are read when ECSPI is disabled.
    } B;
} hw_ecspi_rxdata_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_RXDATA register
 */
#define HW_ECSPI_RXDATA_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_RXDATA(x)           (*(volatile hw_ecspi_rxdata_t *) HW_ECSPI_RXDATA_ADDR(x))
#define HW_ECSPI_RXDATA_RD(x)        (HW_ECSPI_RXDATA(x).U)
#endif

/*
 * constants & macros for individual ECSPI_RXDATA bitfields
 */

/* --- Register HW_ECSPI_RXDATA, field ECSPI_RXDATA (RO)
 *
 * Receive Data. This register holds the top word of the receive data FIFO. The FIFO is advanced for
 * each read of this register. The data read is undefined when the Receive Data Ready (RR) bit in
 * the Interrupt Control/Status register is cleared. Zeros are read when ECSPI is disabled.
 */

#define BP_ECSPI_RXDATA_ECSPI_RXDATA      0
#define BM_ECSPI_RXDATA_ECSPI_RXDATA      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_TXDATA - Transmit Data Register (WO)
 *
 * The Transmit Data (ECSPI_TXDATA) register is a write-only data register that forms the bottom
 * word of the 8  64 x 32 TXFIFO. The TXFIFO can be written to as long as it is not full, even when
 * the SPI Exchange bit (XCH) in ECSPI_CONREG is set. This allows software to write to the TXFIFO
 * during a SPI data exchange process. Writes to this register are ignored when the ECSPI is
 * disabled (ECSPI_CONREG[EN] bit is cleared).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ECSPI_TXDATA : 32; //!< Transmit Data. This register holds the top word of data loaded into the FIFO. Data written to this register must be a word operation. The number of bits actually transmitted is determined by the BIT_COUNT field of the corresponding SPI Control register. If this field contains more bits than the number specified by BIT_COUNT, the extra bits are ignored. For example, to transfer 10 bits of data, a 32-bit word must be written to this register. Bits 9-0 are shifted out and bits 31-10 are ignored. When the ECSPI is operating in Slave mode, zeros are shifted out when the FIFO is empty. Zeros are read when ECSPI is disabled.
    } B;
} hw_ecspi_txdata_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_TXDATA register
 */
#define HW_ECSPI_TXDATA_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_TXDATA(x)           (*(volatile hw_ecspi_txdata_t *) HW_ECSPI_TXDATA_ADDR(x))
#define HW_ECSPI_TXDATA_WR(x, v)     (HW_ECSPI_TXDATA(x).U = (v))
#endif

/*
 * constants & macros for individual ECSPI_TXDATA bitfields
 */

/* --- Register HW_ECSPI_TXDATA, field ECSPI_TXDATA (WO)
 *
 * Transmit Data. This register holds the top word of data loaded into the FIFO. Data written to
 * this register must be a word operation. The number of bits actually transmitted is determined by
 * the BIT_COUNT field of the corresponding SPI Control register. If this field contains more bits
 * than the number specified by BIT_COUNT, the extra bits are ignored. For example, to transfer 10
 * bits of data, a 32-bit word must be written to this register. Bits 9-0 are shifted out and bits
 * 31-10 are ignored. When the ECSPI is operating in Slave mode, zeros are shifted out when the FIFO
 * is empty. Zeros are read when ECSPI is disabled.
 */

#define BP_ECSPI_TXDATA_ECSPI_TXDATA      0
#define BM_ECSPI_TXDATA_ECSPI_TXDATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TXDATA_ECSPI_TXDATA(v)   ((((reg32_t) v) << 0) & BM_ECSPI_TXDATA_ECSPI_TXDATA)
#else
#define BF_ECSPI_TXDATA_ECSPI_TXDATA(v)   (((v) << 0) & BM_ECSPI_TXDATA_ECSPI_TXDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ECSPI_TXDATA field to a new value.
#define BW_ECSPI_TXDATA_ECSPI_TXDATA(v)   BF_CS1(ECSPI_TXDATA, ECSPI_TXDATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_CONREG - Control Register (RW)
 *
 * The Control Register (CONREG)  (ECSPI_CONREG) allows software to enable the ECSPI , configure its
 * operating modes, specify the divider value, phase, and polarity of the clock, configure the Chip
 * Select (SS) and SPI_RDY control signal, and define the transfer length.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EN : 1; //!< SPI Block Enable Control. This bit enables the ECSPI. This bit must be set before writing to other registers or initiating an exchange. Writing zero to this bit disables the block and resets the internal logic with the exception of the ECSPI_CONREG. The block's internal clocks are gated off whenever the block is disabled.
        unsigned HT : 1; //!< Hardware Trigger Enable. This bit is used in master mode only. It enables hardware trigger (HT) mode.
        unsigned XCH : 1; //!< SPI Exchange Bit. This bit applies only when the module is configured in Master mode (MODE = 1). This bit applies only to channels configured in Master mode (CHANNEL MODE = 1). If the Start Mode Control (SMC) bit is cleared, writing a 1 to this bit starts one SPI burst or multiple SPI bursts according to the SPI SS Wave Form Select (SS_CTL). The XCH bit remains set while either the data exchange is in progress, or when the ECSPI is waiting for an active input if SPIRDY is enabled through DRCTL. This bit is cleared automatically when all data in the TXFIFO and the shift register has been shifted out.
        unsigned SMC : 1; //!< Start Mode Control. This bit applies only when the module is configured in Master mode (MODE = 1). This bit applies only to channels configured in Master mode (CHANNEL MODE = 1). It controls how the ECSPI starts a SPI burst, either through the SPI exchange bit, or immediately when the TXFIFO is written to.
        unsigned CHANNEL_MODE : 4; //!< SPI CHANNEL MODE selects the mode for each SPI channel. CHANNEL MODE[3] is for SPI channel 3. CHANNEL MODE[2] is for SPI channel 2. CHANNEL MODE[1] is for SPI channel 1. CHANNEL MODE[0] is for SPI channel 0.
        unsigned POST_DIVIDER : 4; //!< SPI Post Divider. ECSPI uses a two-stage divider to generate the SPI clock. This field defines the post-divider of the reference clock using the equation: 2 n .
        unsigned PRE_DIVIDER : 4; //!< SPI Pre Divider. ECSPI uses a two-stage divider to generate the SPI clock. This field defines the pre-divider of the reference clock.
        unsigned DRCTL : 2; //!< SPI Data Ready Control. This field selects the utilization of the SPI_RDY signal in master mode. ECSPI checks this field before it starts an SPI burst.
        unsigned CHANNEL_SELECT : 2; //!< SPI CHANNEL SELECT bits. Select one of four external SPI Master/Slave Devices. In master mode, these two bits select the external slave devices by asserting the Chip Select (SSn) outputs. Only the selected Chip Select (SSn) signal can be active at a given time; the remaining three signals will be negated.
        unsigned BURST_LENGTH : 12; //!< Burst Length. This field defines the length of a SPI burst to be transferred. The Chip Select (SS) will remain asserted until all bits in a SPI burst are shifted out. A maximum of 2^12 bits can be transferred in a single SPI burst. In master mode, it controls the number of bits per SPI burst. Since the shift register always loads 32-bit data from transmit FIFO, only the n least-significant (n = BURST LENGTH + 1) will be shifted out. The remaining bits will be ignored. In slave mode, only when SS_CTL is cleared, this field will take effect in the transfer. Number of Valid Bits in a SPI burst.
    } B;
} hw_ecspi_conreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_CONREG register
 */
#define HW_ECSPI_CONREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_CONREG(x)           (*(volatile hw_ecspi_conreg_t *) HW_ECSPI_CONREG_ADDR(x))
#define HW_ECSPI_CONREG_RD(x)        (HW_ECSPI_CONREG(x).U)
#define HW_ECSPI_CONREG_WR(x, v)     (HW_ECSPI_CONREG(x).U = (v))
#define HW_ECSPI_CONREG_SET(x, v)    (HW_ECSPI_CONREG_WR(x, HW_ECSPI_CONREG_RD(x) |  (v)))
#define HW_ECSPI_CONREG_CLR(x, v)    (HW_ECSPI_CONREG_WR(x, HW_ECSPI_CONREG_RD(x) & ~(v)))
#define HW_ECSPI_CONREG_TOG(x, v)    (HW_ECSPI_CONREG_WR(x, HW_ECSPI_CONREG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual ECSPI_CONREG bitfields
 */

/* --- Register HW_ECSPI_CONREG, field EN (RW)
 *
 * SPI Block Enable Control. This bit enables the ECSPI. This bit must be set before writing to
 * other registers or initiating an exchange. Writing zero to this bit disables the block and resets
 * the internal logic with the exception of the ECSPI_CONREG. The block's internal clocks are gated
 * off whenever the block is disabled.
 *
 * Values:
 * 0 - Disable the block.
 * 1 - Enable the block.
 */

#define BP_ECSPI_CONREG_EN      0
#define BM_ECSPI_CONREG_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_EN(v)   ((((reg32_t) v) << 0) & BM_ECSPI_CONREG_EN)
#else
#define BF_ECSPI_CONREG_EN(v)   (((v) << 0) & BM_ECSPI_CONREG_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_ECSPI_CONREG_EN(v)   BF_CS1(ECSPI_CONREG, EN, v)
#endif


/* --- Register HW_ECSPI_CONREG, field HT (RW)
 *
 * Hardware Trigger Enable. This bit is used in master mode only. It enables hardware trigger (HT)
 * mode.
 *
 * Values:
 * 0 - Disable HT mode.
 * 1 - Enable HT mode.
 */

#define BP_ECSPI_CONREG_HT      1
#define BM_ECSPI_CONREG_HT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_HT(v)   ((((reg32_t) v) << 1) & BM_ECSPI_CONREG_HT)
#else
#define BF_ECSPI_CONREG_HT(v)   (((v) << 1) & BM_ECSPI_CONREG_HT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HT field to a new value.
#define BW_ECSPI_CONREG_HT(v)   BF_CS1(ECSPI_CONREG, HT, v)
#endif


/* --- Register HW_ECSPI_CONREG, field XCH (RW)
 *
 * SPI Exchange Bit. This bit applies only when the module is configured in Master mode (MODE = 1).
 * This bit applies only to channels configured in Master mode (CHANNEL MODE = 1). If the Start Mode
 * Control (SMC) bit is cleared, writing a 1 to this bit starts one SPI burst or multiple SPI bursts
 * according to the SPI SS Wave Form Select (SS_CTL). The XCH bit remains set while either the data
 * exchange is in progress, or when the ECSPI is waiting for an active input if SPIRDY is enabled
 * through DRCTL. This bit is cleared automatically when all data in the TXFIFO and the shift
 * register has been shifted out.
 *
 * Values:
 * 0 - Idle.
 * 1 - Initiates exchange (write) or busy (read).
 */

#define BP_ECSPI_CONREG_XCH      2
#define BM_ECSPI_CONREG_XCH      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_XCH(v)   ((((reg32_t) v) << 2) & BM_ECSPI_CONREG_XCH)
#else
#define BF_ECSPI_CONREG_XCH(v)   (((v) << 2) & BM_ECSPI_CONREG_XCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the XCH field to a new value.
#define BW_ECSPI_CONREG_XCH(v)   BF_CS1(ECSPI_CONREG, XCH, v)
#endif


/* --- Register HW_ECSPI_CONREG, field SMC (RW)
 *
 * Start Mode Control. This bit applies only when the module is configured in Master mode (MODE =
 * 1). This bit applies only to channels configured in Master mode (CHANNEL MODE = 1). It controls
 * how the ECSPI starts a SPI burst, either through the SPI exchange bit, or immediately when the
 * TXFIFO is written to.
 *
 * Values:
 * 0 - SPI Exchange Bit (XCH) controls when a SPI burst can start. Setting the XCH bit will start a SPI
 *     burst or multiple bursts. This is controlled by the SPI SS Wave Form Select (SS_CTL). Refer
 *     to XCH and SS_CTL descriptions.
 * 1 - Immediately starts a SPI burst when data is written in TXFIFO.
 */

#define BP_ECSPI_CONREG_SMC      3
#define BM_ECSPI_CONREG_SMC      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_SMC(v)   ((((reg32_t) v) << 3) & BM_ECSPI_CONREG_SMC)
#else
#define BF_ECSPI_CONREG_SMC(v)   (((v) << 3) & BM_ECSPI_CONREG_SMC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SMC field to a new value.
#define BW_ECSPI_CONREG_SMC(v)   BF_CS1(ECSPI_CONREG, SMC, v)
#endif


/* --- Register HW_ECSPI_CONREG, field CHANNEL_MODE (RW)
 *
 * SPI CHANNEL MODE selects the mode for each SPI channel. CHANNEL MODE[3] is for SPI channel 3.
 * CHANNEL MODE[2] is for SPI channel 2. CHANNEL MODE[1] is for SPI channel 1. CHANNEL MODE[0] is
 * for SPI channel 0.
 *
 * Values:
 * 0 - Slave mode.
 * 1 - Master mode.
 */

#define BP_ECSPI_CONREG_CHANNEL_MODE      4
#define BM_ECSPI_CONREG_CHANNEL_MODE      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_CHANNEL_MODE(v)   ((((reg32_t) v) << 4) & BM_ECSPI_CONREG_CHANNEL_MODE)
#else
#define BF_ECSPI_CONREG_CHANNEL_MODE(v)   (((v) << 4) & BM_ECSPI_CONREG_CHANNEL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CHANNEL_MODE field to a new value.
#define BW_ECSPI_CONREG_CHANNEL_MODE(v)   BF_CS1(ECSPI_CONREG, CHANNEL_MODE, v)
#endif


/* --- Register HW_ECSPI_CONREG, field POST_DIVIDER (RW)
 *
 * SPI Post Divider. ECSPI uses a two-stage divider to generate the SPI clock. This field defines
 * the post-divider of the reference clock using the equation: 2 n .
 *
 * Values:
 * 0000 - Divide by 1.
 * 0001 - Divide by 2.
 * 0010 - Divide by 4.
 * 1110 - Divide by 2 14 .
 * 1111 - Divide by 2 15 .
 */

#define BP_ECSPI_CONREG_POST_DIVIDER      8
#define BM_ECSPI_CONREG_POST_DIVIDER      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_POST_DIVIDER(v)   ((((reg32_t) v) << 8) & BM_ECSPI_CONREG_POST_DIVIDER)
#else
#define BF_ECSPI_CONREG_POST_DIVIDER(v)   (((v) << 8) & BM_ECSPI_CONREG_POST_DIVIDER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIVIDER field to a new value.
#define BW_ECSPI_CONREG_POST_DIVIDER(v)   BF_CS1(ECSPI_CONREG, POST_DIVIDER, v)
#endif


/* --- Register HW_ECSPI_CONREG, field PRE_DIVIDER (RW)
 *
 * SPI Pre Divider. ECSPI uses a two-stage divider to generate the SPI clock. This field defines the
 * pre-divider of the reference clock.
 *
 * Values:
 * 0000 - Divide by 1.
 * 0001 - Divide by 2.
 * 0010 - Divide by 3.
 * 1101 - Divide by 14.
 * 1110 - Divide by 15.
 * 1111 - Divide by 16.
 */

#define BP_ECSPI_CONREG_PRE_DIVIDER      12
#define BM_ECSPI_CONREG_PRE_DIVIDER      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_PRE_DIVIDER(v)   ((((reg32_t) v) << 12) & BM_ECSPI_CONREG_PRE_DIVIDER)
#else
#define BF_ECSPI_CONREG_PRE_DIVIDER(v)   (((v) << 12) & BM_ECSPI_CONREG_PRE_DIVIDER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PRE_DIVIDER field to a new value.
#define BW_ECSPI_CONREG_PRE_DIVIDER(v)   BF_CS1(ECSPI_CONREG, PRE_DIVIDER, v)
#endif


/* --- Register HW_ECSPI_CONREG, field DRCTL (RW)
 *
 * SPI Data Ready Control. This field selects the utilization of the SPI_RDY signal in master mode.
 * ECSPI checks this field before it starts an SPI burst.
 *
 * Values:
 * 00 - The SPI_RDY signal is a don't care.
 * 01 - Burst will be triggered by the falling edge of the SPI_RDY signal (edge-triggered).
 * 10 - Burst will be triggered by a low level of the SPI_RDY signal (level-triggered).
 * 11 - Reserved.
 */

#define BP_ECSPI_CONREG_DRCTL      16
#define BM_ECSPI_CONREG_DRCTL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_DRCTL(v)   ((((reg32_t) v) << 16) & BM_ECSPI_CONREG_DRCTL)
#else
#define BF_ECSPI_CONREG_DRCTL(v)   (((v) << 16) & BM_ECSPI_CONREG_DRCTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DRCTL field to a new value.
#define BW_ECSPI_CONREG_DRCTL(v)   BF_CS1(ECSPI_CONREG, DRCTL, v)
#endif


/* --- Register HW_ECSPI_CONREG, field CHANNEL_SELECT (RW)
 *
 * SPI CHANNEL SELECT bits. Select one of four external SPI Master/Slave Devices. In master mode,
 * these two bits select the external slave devices by asserting the Chip Select (SSn) outputs. Only
 * the selected Chip Select (SSn) signal can be active at a given time; the remaining three signals
 * will be negated.
 *
 * Values:
 * 00 - Channel 0 is selected. Chip Select 0 (SS0) will be asserted.
 * 01 - Channel 1 is selected. Chip Select 1 (SS1) will be asserted.
 * 10 - Channel 2 is selected. Chip Select 2 (SS2) will be asserted.
 * 11 - Channel 3 is selected. Chip Select 3 (SS3) will be asserted.
 */

#define BP_ECSPI_CONREG_CHANNEL_SELECT      18
#define BM_ECSPI_CONREG_CHANNEL_SELECT      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_CHANNEL_SELECT(v)   ((((reg32_t) v) << 18) & BM_ECSPI_CONREG_CHANNEL_SELECT)
#else
#define BF_ECSPI_CONREG_CHANNEL_SELECT(v)   (((v) << 18) & BM_ECSPI_CONREG_CHANNEL_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CHANNEL_SELECT field to a new value.
#define BW_ECSPI_CONREG_CHANNEL_SELECT(v)   BF_CS1(ECSPI_CONREG, CHANNEL_SELECT, v)
#endif


/* --- Register HW_ECSPI_CONREG, field BURST_LENGTH (RW)
 *
 * Burst Length. This field defines the length of a SPI burst to be transferred. The Chip Select
 * (SS) will remain asserted until all bits in a SPI burst are shifted out. A maximum of 2^12 bits
 * can be transferred in a single SPI burst. In master mode, it controls the number of bits per SPI
 * burst. Since the shift register always loads 32-bit data from transmit FIFO, only the n least-
 * significant (n = BURST LENGTH + 1) will be shifted out. The remaining bits will be ignored. In
 * slave mode, only when SS_CTL is cleared, this field will take effect in the transfer. Number of
 * Valid Bits in a SPI burst.
 *
 * Values:
 * 0x000 - A SPI burst contains the 1 LSB in a word.
 * 0x001 - A SPI burst contains the 2 LSB in a word.
 * 0x002 - A SPI burst contains the 3 LSB in a word.
 * 0x01F - A SPI burst contains all 32 bits in a word.
 * 0x020 - A SPI burst contains the 1 LSB in first word and all 32 bits in second word.
 * 0x021 - A SPI burst contains the 2 LSB in first word and all 32 bits in second word.
 * 0xFFE - A SPI burst contains the 31 LSB in first word and 2^7 -1 words.
 * 0xFFF - A SPI burst contains 2^7 words.
 */

#define BP_ECSPI_CONREG_BURST_LENGTH      20
#define BM_ECSPI_CONREG_BURST_LENGTH      0xfff00000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_BURST_LENGTH(v)   ((((reg32_t) v) << 20) & BM_ECSPI_CONREG_BURST_LENGTH)
#else
#define BF_ECSPI_CONREG_BURST_LENGTH(v)   (((v) << 20) & BM_ECSPI_CONREG_BURST_LENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BURST_LENGTH field to a new value.
#define BW_ECSPI_CONREG_BURST_LENGTH(v)   BF_CS1(ECSPI_CONREG, BURST_LENGTH, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_CONFIGREG - Config Register (RW)
 *
 * The Config Register (ECSPI_CONFIGREG) allows software to configure each SPI channel, configure
 * its operating modes, specify the phase and polarity of the clock, configure the Chip Select (SS),
 * and define the HT transfer length.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SCLK_PHA : 4; //!< SPI Clock/Data Phase Control. This field controls the clock/data phase relationship. See for more information. SCLK PHA[3] is for SPI channel 3. SCLK PHA[2] is for SPI channel 2. SCLK PHA[1] is for SPI channel 1. SCLK PHA[0] is for SPI channel 0.
        unsigned SCLK_POL : 4; //!< SPI Clock Polarity Control. This field controls the polarity of the SCLK signal. See for more information. SCLK POL[3] is for SPI channel 3. SCLK POL[2] is for SPI channel 2. SCLK POL[1] is for SPI channel 1. SCLK POL[0] is for SPI channel 0.
        unsigned SS_CTL : 4; //!< SPI SS Wave Form Select. In master mode, this field controls the output wave form of the Chip Select (SS) signal when the SMC (Start Mode Control) bit is cleared. The SS_CTL are ignored if the SMC bit is set. SS CTL[3] is for SPI channel 3. SS CTL[2] is for SPI channel 2. SS CTL[1] is for SPI channel 1. SS CTL[0] is for SPI channel 0. In slave mode, this bit controls when the SPI burst is completed. 1 An SPI burst is completed by the Chip Select (SS) signal edges. (SSPOL = 0: rising edge; SSPOL = 1: falling edge) The RXFIFO is advanced whenever a Chip Select (SS) signal edge is detected or the shift register contains 32-bits of valid data.
        unsigned SS_POL : 4; //!< SPI SS Polarity Select. In both Master and Slave modes, this field selects the polarity of the Chip Select (SS) signal. SS POL[3] is for SPI channel 3. SS POL[2] is for SPI channel 2. SS POL[1] is for SPI channel 1. SS POL[0] is for SPI channel 0.
        unsigned DATA_CTL : 4; //!< DATA CTL. This field controls inactive state of the data line for each SPI channel. DATA CTL[3] is for SPI channel 3. DATA CTL[2] is for SPI channel 2. DATA CTL[1] is for SPI channel 1. DATA CTL[0] is for SPI channel 0.
        unsigned SCLK_CTL : 4; //!< SCLK CTL. This field controls the inactive state of SCLK for each SPI channel. SCLK CTL[3] is for SPI channel 3. SCLK CTL[2] is for SPI channel 2. SCLK CTL[1] is for SPI channel 1. SCLK CTL[0] is for SPI channel 0.
        unsigned HT_LENGTH : 5; //!< HT LENGTH. This field defines the message length in HT Mode. The length in bits of one message is (HT LENGTH + 1).
        unsigned RESERVED0 : 3; //!< Reserved
    } B;
} hw_ecspi_configreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_CONFIGREG register
 */
#define HW_ECSPI_CONFIGREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_CONFIGREG(x)           (*(volatile hw_ecspi_configreg_t *) HW_ECSPI_CONFIGREG_ADDR(x))
#define HW_ECSPI_CONFIGREG_RD(x)        (HW_ECSPI_CONFIGREG(x).U)
#define HW_ECSPI_CONFIGREG_WR(x, v)     (HW_ECSPI_CONFIGREG(x).U = (v))
#define HW_ECSPI_CONFIGREG_SET(x, v)    (HW_ECSPI_CONFIGREG_WR(x, HW_ECSPI_CONFIGREG_RD(x) |  (v)))
#define HW_ECSPI_CONFIGREG_CLR(x, v)    (HW_ECSPI_CONFIGREG_WR(x, HW_ECSPI_CONFIGREG_RD(x) & ~(v)))
#define HW_ECSPI_CONFIGREG_TOG(x, v)    (HW_ECSPI_CONFIGREG_WR(x, HW_ECSPI_CONFIGREG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual ECSPI_CONFIGREG bitfields
 */

/* --- Register HW_ECSPI_CONFIGREG, field SCLK_PHA (RW)
 *
 * SPI Clock/Data Phase Control. This field controls the clock/data phase relationship. See for more
 * information. SCLK PHA[3] is for SPI channel 3. SCLK PHA[2] is for SPI channel 2. SCLK PHA[1] is
 * for SPI channel 1. SCLK PHA[0] is for SPI channel 0.
 *
 * Values:
 * 0 - Phase 0 operation.
 * 1 - Phase 1 operation.
 */

#define BP_ECSPI_CONFIGREG_SCLK_PHA      0
#define BM_ECSPI_CONFIGREG_SCLK_PHA      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SCLK_PHA(v)   ((((reg32_t) v) << 0) & BM_ECSPI_CONFIGREG_SCLK_PHA)
#else
#define BF_ECSPI_CONFIGREG_SCLK_PHA(v)   (((v) << 0) & BM_ECSPI_CONFIGREG_SCLK_PHA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SCLK_PHA field to a new value.
#define BW_ECSPI_CONFIGREG_SCLK_PHA(v)   BF_CS1(ECSPI_CONFIGREG, SCLK_PHA, v)
#endif


/* --- Register HW_ECSPI_CONFIGREG, field SCLK_POL (RW)
 *
 * SPI Clock Polarity Control. This field controls the polarity of the SCLK signal. See for more
 * information. SCLK POL[3] is for SPI channel 3. SCLK POL[2] is for SPI channel 2. SCLK POL[1] is
 * for SPI channel 1. SCLK POL[0] is for SPI channel 0.
 *
 * Values:
 * 0 - Active high polarity (0 = Idle).
 * 1 - Active low polarity (1 = Idle).
 */

#define BP_ECSPI_CONFIGREG_SCLK_POL      4
#define BM_ECSPI_CONFIGREG_SCLK_POL      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SCLK_POL(v)   ((((reg32_t) v) << 4) & BM_ECSPI_CONFIGREG_SCLK_POL)
#else
#define BF_ECSPI_CONFIGREG_SCLK_POL(v)   (((v) << 4) & BM_ECSPI_CONFIGREG_SCLK_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SCLK_POL field to a new value.
#define BW_ECSPI_CONFIGREG_SCLK_POL(v)   BF_CS1(ECSPI_CONFIGREG, SCLK_POL, v)
#endif


/* --- Register HW_ECSPI_CONFIGREG, field SS_CTL (RW)
 *
 * SPI SS Wave Form Select. In master mode, this field controls the output wave form of the Chip
 * Select (SS) signal when the SMC (Start Mode Control) bit is cleared. The SS_CTL are ignored if
 * the SMC bit is set. SS CTL[3] is for SPI channel 3. SS CTL[2] is for SPI channel 2. SS CTL[1] is
 * for SPI channel 1. SS CTL[0] is for SPI channel 0. In slave mode, this bit controls when the SPI
 * burst is completed. 1 An SPI burst is completed by the Chip Select (SS) signal edges. (SSPOL = 0:
 * rising edge; SSPOL = 1: falling edge) The RXFIFO is advanced whenever a Chip Select (SS) signal
 * edge is detected or the shift register contains 32-bits of valid data.
 *
 * Values:
 * 0 - In master mode - only one SPI burst will be transmitted.
 * 0 - In slave mode - an SPI burst is completed when the number of bits received in the shift register is
 *     equal to (BURST LENGTH + 1). Only the n least-significant bits (n = BURST LENGTH[4:0] + 1) of
 *     the first received word are valid. All bits subsequent to the first received word in RXFIFO
 *     are valid.
 * 1 - In master mode - Negate Chip Select (SS) signal between SPI bursts. Multiple SPI bursts will be
 *     transmitted. The SPI transfer will automatically stop when the TXFIFO is empty.
 * 1 - In slave mode - an SPI burst is completed by the Chip Select (SS) signal edges. (SSPOL = 0: rising
 *     edge; SSPOL = 1: falling edge) The RXFIFO is advanced whenever a Chip Select (SS) signal edge
 *     is detected or the shift register contains 32-bits of valid data.
 */

#define BP_ECSPI_CONFIGREG_SS_CTL      8
#define BM_ECSPI_CONFIGREG_SS_CTL      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SS_CTL(v)   ((((reg32_t) v) << 8) & BM_ECSPI_CONFIGREG_SS_CTL)
#else
#define BF_ECSPI_CONFIGREG_SS_CTL(v)   (((v) << 8) & BM_ECSPI_CONFIGREG_SS_CTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SS_CTL field to a new value.
#define BW_ECSPI_CONFIGREG_SS_CTL(v)   BF_CS1(ECSPI_CONFIGREG, SS_CTL, v)
#endif


/* --- Register HW_ECSPI_CONFIGREG, field SS_POL (RW)
 *
 * SPI SS Polarity Select. In both Master and Slave modes, this field selects the polarity of the
 * Chip Select (SS) signal. SS POL[3] is for SPI channel 3. SS POL[2] is for SPI channel 2. SS
 * POL[1] is for SPI channel 1. SS POL[0] is for SPI channel 0.
 *
 * Values:
 * 0 - Active low.
 * 1 - Active high.
 */

#define BP_ECSPI_CONFIGREG_SS_POL      12
#define BM_ECSPI_CONFIGREG_SS_POL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SS_POL(v)   ((((reg32_t) v) << 12) & BM_ECSPI_CONFIGREG_SS_POL)
#else
#define BF_ECSPI_CONFIGREG_SS_POL(v)   (((v) << 12) & BM_ECSPI_CONFIGREG_SS_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SS_POL field to a new value.
#define BW_ECSPI_CONFIGREG_SS_POL(v)   BF_CS1(ECSPI_CONFIGREG, SS_POL, v)
#endif


/* --- Register HW_ECSPI_CONFIGREG, field DATA_CTL (RW)
 *
 * DATA CTL. This field controls inactive state of the data line for each SPI channel. DATA CTL[3]
 * is for SPI channel 3. DATA CTL[2] is for SPI channel 2. DATA CTL[1] is for SPI channel 1. DATA
 * CTL[0] is for SPI channel 0.
 *
 * Values:
 * 0 - Stay high.
 * 1 - Stay low.
 */

#define BP_ECSPI_CONFIGREG_DATA_CTL      16
#define BM_ECSPI_CONFIGREG_DATA_CTL      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_DATA_CTL(v)   ((((reg32_t) v) << 16) & BM_ECSPI_CONFIGREG_DATA_CTL)
#else
#define BF_ECSPI_CONFIGREG_DATA_CTL(v)   (((v) << 16) & BM_ECSPI_CONFIGREG_DATA_CTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_CTL field to a new value.
#define BW_ECSPI_CONFIGREG_DATA_CTL(v)   BF_CS1(ECSPI_CONFIGREG, DATA_CTL, v)
#endif


/* --- Register HW_ECSPI_CONFIGREG, field SCLK_CTL (RW)
 *
 * SCLK CTL. This field controls the inactive state of SCLK for each SPI channel. SCLK CTL[3] is for
 * SPI channel 3. SCLK CTL[2] is for SPI channel 2. SCLK CTL[1] is for SPI channel 1. SCLK CTL[0] is
 * for SPI channel 0.
 *
 * Values:
 * 0 - Stay low.
 * 1 - Stay high.
 */

#define BP_ECSPI_CONFIGREG_SCLK_CTL      20
#define BM_ECSPI_CONFIGREG_SCLK_CTL      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_SCLK_CTL(v)   ((((reg32_t) v) << 20) & BM_ECSPI_CONFIGREG_SCLK_CTL)
#else
#define BF_ECSPI_CONFIGREG_SCLK_CTL(v)   (((v) << 20) & BM_ECSPI_CONFIGREG_SCLK_CTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SCLK_CTL field to a new value.
#define BW_ECSPI_CONFIGREG_SCLK_CTL(v)   BF_CS1(ECSPI_CONFIGREG, SCLK_CTL, v)
#endif


/* --- Register HW_ECSPI_CONFIGREG, field HT_LENGTH (RW)
 *
 * HT LENGTH. This field defines the message length in HT Mode. The length in bits of one message is
 * (HT LENGTH + 1).
 */

#define BP_ECSPI_CONFIGREG_HT_LENGTH      24
#define BM_ECSPI_CONFIGREG_HT_LENGTH      0x1f000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONFIGREG_HT_LENGTH(v)   ((((reg32_t) v) << 24) & BM_ECSPI_CONFIGREG_HT_LENGTH)
#else
#define BF_ECSPI_CONFIGREG_HT_LENGTH(v)   (((v) << 24) & BM_ECSPI_CONFIGREG_HT_LENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HT_LENGTH field to a new value.
#define BW_ECSPI_CONFIGREG_HT_LENGTH(v)   BF_CS1(ECSPI_CONFIGREG, HT_LENGTH, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_INTREG - Interrupt Control Register (RW)
 *
 * The Interrupt Control Register (ECSPI_INTREG) enables the generation of interrupts to the host
 * processor. If the ECSPI is disabled, this register reads zero.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TEEN : 1; //!< TXFIFO Empty Interrupt enable. This bit enables the TXFIFO Empty Interrupt.
        unsigned TDREN : 1; //!< TXFIFO Data Request Interrupt enable. This bit enables the TXFIFO Data Request Interrupt when the number of data entries in the TXFIFO is less than or equal to TX THRESHOLD.
        unsigned TFEN : 1; //!< TXFIFO Full Interrupt enable. This bit enables the TXFIFO Full Interrupt.
        unsigned RREN : 1; //!< RXFIFO Ready Interrupt enable. This bit enables the RXFIFO Ready Interrupt.
        unsigned RDREN : 1; //!< RXFIFO Data Request Interrupt enable. This bit enables the RXFIFO Data Request Interrupt when the number of data entries in the RXFIFO is greater than RX THRESHOLD.
        unsigned RFEN : 1; //!< RXFIFO Full Interrupt enable. This bit enables the RXFIFO Full Interrupt.
        unsigned ROEN : 1; //!< RXFIFO Overflow Interrupt enable. This bit enables the RXFIFO Overflow Interrupt.
        unsigned TCEN : 1; //!< Transfer Completed Interrupt enable. This bit enables the Transfer Completed Interrupt.
        unsigned RESERVED0 : 24; //!< Reserved
    } B;
} hw_ecspi_intreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_INTREG register
 */
#define HW_ECSPI_INTREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_INTREG(x)           (*(volatile hw_ecspi_intreg_t *) HW_ECSPI_INTREG_ADDR(x))
#define HW_ECSPI_INTREG_RD(x)        (HW_ECSPI_INTREG(x).U)
#define HW_ECSPI_INTREG_WR(x, v)     (HW_ECSPI_INTREG(x).U = (v))
#define HW_ECSPI_INTREG_SET(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) |  (v)))
#define HW_ECSPI_INTREG_CLR(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) & ~(v)))
#define HW_ECSPI_INTREG_TOG(x, v)    (HW_ECSPI_INTREG_WR(x, HW_ECSPI_INTREG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual ECSPI_INTREG bitfields
 */

/* --- Register HW_ECSPI_INTREG, field TEEN (RW)
 *
 * TXFIFO Empty Interrupt enable. This bit enables the TXFIFO Empty Interrupt.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_INTREG_TEEN      0
#define BM_ECSPI_INTREG_TEEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TEEN(v)   ((((reg32_t) v) << 0) & BM_ECSPI_INTREG_TEEN)
#else
#define BF_ECSPI_INTREG_TEEN(v)   (((v) << 0) & BM_ECSPI_INTREG_TEEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TEEN field to a new value.
#define BW_ECSPI_INTREG_TEEN(v)   BF_CS1(ECSPI_INTREG, TEEN, v)
#endif


/* --- Register HW_ECSPI_INTREG, field TDREN (RW)
 *
 * TXFIFO Data Request Interrupt enable. This bit enables the TXFIFO Data Request Interrupt when the
 * number of data entries in the TXFIFO is less than or equal to TX THRESHOLD.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_INTREG_TDREN      1
#define BM_ECSPI_INTREG_TDREN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TDREN(v)   ((((reg32_t) v) << 1) & BM_ECSPI_INTREG_TDREN)
#else
#define BF_ECSPI_INTREG_TDREN(v)   (((v) << 1) & BM_ECSPI_INTREG_TDREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TDREN field to a new value.
#define BW_ECSPI_INTREG_TDREN(v)   BF_CS1(ECSPI_INTREG, TDREN, v)
#endif


/* --- Register HW_ECSPI_INTREG, field TFEN (RW)
 *
 * TXFIFO Full Interrupt enable. This bit enables the TXFIFO Full Interrupt.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_INTREG_TFEN      2
#define BM_ECSPI_INTREG_TFEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TFEN(v)   ((((reg32_t) v) << 2) & BM_ECSPI_INTREG_TFEN)
#else
#define BF_ECSPI_INTREG_TFEN(v)   (((v) << 2) & BM_ECSPI_INTREG_TFEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFEN field to a new value.
#define BW_ECSPI_INTREG_TFEN(v)   BF_CS1(ECSPI_INTREG, TFEN, v)
#endif


/* --- Register HW_ECSPI_INTREG, field RREN (RW)
 *
 * RXFIFO Ready Interrupt enable. This bit enables the RXFIFO Ready Interrupt.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_INTREG_RREN      3
#define BM_ECSPI_INTREG_RREN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RREN(v)   ((((reg32_t) v) << 3) & BM_ECSPI_INTREG_RREN)
#else
#define BF_ECSPI_INTREG_RREN(v)   (((v) << 3) & BM_ECSPI_INTREG_RREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RREN field to a new value.
#define BW_ECSPI_INTREG_RREN(v)   BF_CS1(ECSPI_INTREG, RREN, v)
#endif


/* --- Register HW_ECSPI_INTREG, field RDREN (RW)
 *
 * RXFIFO Data Request Interrupt enable. This bit enables the RXFIFO Data Request Interrupt when the
 * number of data entries in the RXFIFO is greater than RX THRESHOLD.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_INTREG_RDREN      4
#define BM_ECSPI_INTREG_RDREN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RDREN(v)   ((((reg32_t) v) << 4) & BM_ECSPI_INTREG_RDREN)
#else
#define BF_ECSPI_INTREG_RDREN(v)   (((v) << 4) & BM_ECSPI_INTREG_RDREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RDREN field to a new value.
#define BW_ECSPI_INTREG_RDREN(v)   BF_CS1(ECSPI_INTREG, RDREN, v)
#endif


/* --- Register HW_ECSPI_INTREG, field RFEN (RW)
 *
 * RXFIFO Full Interrupt enable. This bit enables the RXFIFO Full Interrupt.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_INTREG_RFEN      5
#define BM_ECSPI_INTREG_RFEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_RFEN(v)   ((((reg32_t) v) << 5) & BM_ECSPI_INTREG_RFEN)
#else
#define BF_ECSPI_INTREG_RFEN(v)   (((v) << 5) & BM_ECSPI_INTREG_RFEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFEN field to a new value.
#define BW_ECSPI_INTREG_RFEN(v)   BF_CS1(ECSPI_INTREG, RFEN, v)
#endif


/* --- Register HW_ECSPI_INTREG, field ROEN (RW)
 *
 * RXFIFO Overflow Interrupt enable. This bit enables the RXFIFO Overflow Interrupt.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_INTREG_ROEN      6
#define BM_ECSPI_INTREG_ROEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_ROEN(v)   ((((reg32_t) v) << 6) & BM_ECSPI_INTREG_ROEN)
#else
#define BF_ECSPI_INTREG_ROEN(v)   (((v) << 6) & BM_ECSPI_INTREG_ROEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROEN field to a new value.
#define BW_ECSPI_INTREG_ROEN(v)   BF_CS1(ECSPI_INTREG, ROEN, v)
#endif


/* --- Register HW_ECSPI_INTREG, field TCEN (RW)
 *
 * Transfer Completed Interrupt enable. This bit enables the Transfer Completed Interrupt.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_INTREG_TCEN      7
#define BM_ECSPI_INTREG_TCEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_INTREG_TCEN(v)   ((((reg32_t) v) << 7) & BM_ECSPI_INTREG_TCEN)
#else
#define BF_ECSPI_INTREG_TCEN(v)   (((v) << 7) & BM_ECSPI_INTREG_TCEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCEN field to a new value.
#define BW_ECSPI_INTREG_TCEN(v)   BF_CS1(ECSPI_INTREG, TCEN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_DMAREG - DMA Control Register (RW)
 *
 * The Direct Memory Access Control Register (ECSPI_DMAREG) provides software a way to use an on-
 * chip DMA controller for ECSPI data. Internal DMA request signals enable direct data transfers
 * between the ECSPI FIFOs and system memory. The ECSPI sends out DMA requests when the appropriate
 * FIFO conditions are matched.  If the ECSPI is disabled, this register is read as 0.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TX_THRESHOLD : 6; //!< TX THRESHOLD. This field defines the FIFO threshold that triggers a TX DMA/INT request. A TX DMA/INT request is issued when the number of data entries in the TXFIFO is greater than TX THRESHOLD.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned TEDEN : 1; //!< TXFIFO Empty DMA Request Enable. This bit enables/disables the TXFIFO Empty DMA Request.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned RX_THRESHOLD : 6; //!< RX THRESHOLD. This field defines the FIFO threshold that triggers a RX DMA/INT request. A RX DMA/INT request is issued when the number of data entries in the RXFIFO is greater than RX THRESHOLD.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned RXDEN : 1; //!< RXFIFO DMA Request Enable. This bit enables/disables the RXFIFO DMA Request.
        unsigned RX_DMA_LENGTH : 6; //!< RX DMA LENGTH. This field defines the burst length of a DMA operation. Applies only when RXTDEN is set.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned RXTDEN : 1; //!< RXFIFO TAIL DMA Request Enable. This bit enables an internal counter that is increased at each read of the RXFIFO. This counter is cleared automatically when it reaches RX DMA LENGTH. If the number of words remaining in the RXFIFO is greater than or equal to RX DMA LENGTH, a DMA request is generated even if it is less than or equal to RX THRESHOLD.
    } B;
} hw_ecspi_dmareg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_DMAREG register
 */
#define HW_ECSPI_DMAREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_DMAREG(x)           (*(volatile hw_ecspi_dmareg_t *) HW_ECSPI_DMAREG_ADDR(x))
#define HW_ECSPI_DMAREG_RD(x)        (HW_ECSPI_DMAREG(x).U)
#define HW_ECSPI_DMAREG_WR(x, v)     (HW_ECSPI_DMAREG(x).U = (v))
#define HW_ECSPI_DMAREG_SET(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) |  (v)))
#define HW_ECSPI_DMAREG_CLR(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) & ~(v)))
#define HW_ECSPI_DMAREG_TOG(x, v)    (HW_ECSPI_DMAREG_WR(x, HW_ECSPI_DMAREG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual ECSPI_DMAREG bitfields
 */

/* --- Register HW_ECSPI_DMAREG, field TX_THRESHOLD (RW)
 *
 * TX THRESHOLD. This field defines the FIFO threshold that triggers a TX DMA/INT request. A TX
 * DMA/INT request is issued when the number of data entries in the TXFIFO is greater than TX
 * THRESHOLD.
 */

#define BP_ECSPI_DMAREG_TX_THRESHOLD      0
#define BM_ECSPI_DMAREG_TX_THRESHOLD      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_TX_THRESHOLD(v)   ((((reg32_t) v) << 0) & BM_ECSPI_DMAREG_TX_THRESHOLD)
#else
#define BF_ECSPI_DMAREG_TX_THRESHOLD(v)   (((v) << 0) & BM_ECSPI_DMAREG_TX_THRESHOLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_THRESHOLD field to a new value.
#define BW_ECSPI_DMAREG_TX_THRESHOLD(v)   BF_CS1(ECSPI_DMAREG, TX_THRESHOLD, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field TEDEN (RW)
 *
 * TXFIFO Empty DMA Request Enable. This bit enables/disables the TXFIFO Empty DMA Request.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_DMAREG_TEDEN      7
#define BM_ECSPI_DMAREG_TEDEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_TEDEN(v)   ((((reg32_t) v) << 7) & BM_ECSPI_DMAREG_TEDEN)
#else
#define BF_ECSPI_DMAREG_TEDEN(v)   (((v) << 7) & BM_ECSPI_DMAREG_TEDEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TEDEN field to a new value.
#define BW_ECSPI_DMAREG_TEDEN(v)   BF_CS1(ECSPI_DMAREG, TEDEN, v)
#endif


/* --- Register HW_ECSPI_DMAREG, field RX_THRESHOLD (RW)
 *
 * RX THRESHOLD. This field defines the FIFO threshold that triggers a RX DMA/INT request. A RX
 * DMA/INT request is issued when the number of data entries in the RXFIFO is greater than RX
 * THRESHOLD.
 */

#define BP_ECSPI_DMAREG_RX_THRESHOLD      16
#define BM_ECSPI_DMAREG_RX_THRESHOLD      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RX_THRESHOLD(v)   ((((reg32_t) v) << 16) & BM_ECSPI_DMAREG_RX_THRESHOLD)
#else
#define BF_ECSPI_DMAREG_RX_THRESHOLD(v)   (((v) << 16) & BM_ECSPI_DMAREG_RX_THRESHOLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_THRESHOLD field to a new value.
#define BW_ECSPI_DMAREG_RX_THRESHOLD(v)   BF_CS1(ECSPI_DMAREG, RX_THRESHOLD, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field RXDEN (RW)
 *
 * RXFIFO DMA Request Enable. This bit enables/disables the RXFIFO DMA Request.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_DMAREG_RXDEN      23
#define BM_ECSPI_DMAREG_RXDEN      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RXDEN(v)   ((((reg32_t) v) << 23) & BM_ECSPI_DMAREG_RXDEN)
#else
#define BF_ECSPI_DMAREG_RXDEN(v)   (((v) << 23) & BM_ECSPI_DMAREG_RXDEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDEN field to a new value.
#define BW_ECSPI_DMAREG_RXDEN(v)   BF_CS1(ECSPI_DMAREG, RXDEN, v)
#endif


/* --- Register HW_ECSPI_DMAREG, field RX_DMA_LENGTH (RW)
 *
 * RX DMA LENGTH. This field defines the burst length of a DMA operation. Applies only when RXTDEN
 * is set.
 */

#define BP_ECSPI_DMAREG_RX_DMA_LENGTH      24
#define BM_ECSPI_DMAREG_RX_DMA_LENGTH      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RX_DMA_LENGTH(v)   ((((reg32_t) v) << 24) & BM_ECSPI_DMAREG_RX_DMA_LENGTH)
#else
#define BF_ECSPI_DMAREG_RX_DMA_LENGTH(v)   (((v) << 24) & BM_ECSPI_DMAREG_RX_DMA_LENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_DMA_LENGTH field to a new value.
#define BW_ECSPI_DMAREG_RX_DMA_LENGTH(v)   BF_CS1(ECSPI_DMAREG, RX_DMA_LENGTH, v)
#endif

/* --- Register HW_ECSPI_DMAREG, field RXTDEN (RW)
 *
 * RXFIFO TAIL DMA Request Enable. This bit enables an internal counter that is increased at each
 * read of the RXFIFO. This counter is cleared automatically when it reaches RX DMA LENGTH. If the
 * number of words remaining in the RXFIFO is greater than or equal to RX DMA LENGTH, a DMA request
 * is generated even if it is less than or equal to RX THRESHOLD.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_ECSPI_DMAREG_RXTDEN      31
#define BM_ECSPI_DMAREG_RXTDEN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_DMAREG_RXTDEN(v)   ((((reg32_t) v) << 31) & BM_ECSPI_DMAREG_RXTDEN)
#else
#define BF_ECSPI_DMAREG_RXTDEN(v)   (((v) << 31) & BM_ECSPI_DMAREG_RXTDEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXTDEN field to a new value.
#define BW_ECSPI_DMAREG_RXTDEN(v)   BF_CS1(ECSPI_DMAREG, RXTDEN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_STATREG - Status Register (RW)
 *
 * The ECSPI Status Register (ECSPI_STATREG) reflects the status of the ECSPI's operating condition.
 * If the ECSPI is disabled, this register reads 0x0000_0003.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TE : 1; //!< TXFIFO Empty. This bit is set if the TXFIFO is empty.
        unsigned TDR : 1; //!< TXFIFO Data Request.
        unsigned TF : 1; //!< TXFIFO Full. This bit is set when if the TXFIFO is full.
        unsigned RR : 1; //!< RXFIFO Ready. This bit is set when one or more words are stored in the RXFIFO.
        unsigned RDR : 1; //!< RXFIFO Data Request.
        unsigned RF : 1; //!< RXFIFO Full. This bit is set when the RXFIFO is full.
        unsigned RO : 1; //!< RXFIFO Overflow. When set, this bit indicates that RXFIFO has overflowed. Writing 1 to this bit clears it.
        unsigned TC : 1; //!< Transfer Completed Status bit. Writing 1 to this bit clears it.
        unsigned RESERVED0 : 24; //!< Reserved
    } B;
} hw_ecspi_statreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_STATREG register
 */
#define HW_ECSPI_STATREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_STATREG(x)           (*(volatile hw_ecspi_statreg_t *) HW_ECSPI_STATREG_ADDR(x))
#define HW_ECSPI_STATREG_RD(x)        (HW_ECSPI_STATREG(x).U)
#define HW_ECSPI_STATREG_WR(x, v)     (HW_ECSPI_STATREG(x).U = (v))
#define HW_ECSPI_STATREG_SET(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) |  (v)))
#define HW_ECSPI_STATREG_CLR(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) & ~(v)))
#define HW_ECSPI_STATREG_TOG(x, v)    (HW_ECSPI_STATREG_WR(x, HW_ECSPI_STATREG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual ECSPI_STATREG bitfields
 */

/* --- Register HW_ECSPI_STATREG, field TE (RO)
 *
 * TXFIFO Empty. This bit is set if the TXFIFO is empty.
 *
 * Values:
 * 0 - TXFIFO contains one or more words.
 * 1 - TXFIFO is empty.
 */

#define BP_ECSPI_STATREG_TE      0
#define BM_ECSPI_STATREG_TE      0x00000001


/* --- Register HW_ECSPI_STATREG, field TDR (RO)
 *
 * TXFIFO Data Request.
 *
 * Values:
 * 0 - Number of empty slots in TXFIFO is greater than TX THRESHOLD.
 * 1 - Number of empty slots in TXFIFO is not greater than TX THRESHOLD.
 */

#define BP_ECSPI_STATREG_TDR      1
#define BM_ECSPI_STATREG_TDR      0x00000002


/* --- Register HW_ECSPI_STATREG, field TF (RO)
 *
 * TXFIFO Full. This bit is set when if the TXFIFO is full.
 *
 * Values:
 * 0 - TXFIFO is not Full.
 * 1 - TXFIFO is Full.
 */

#define BP_ECSPI_STATREG_TF      2
#define BM_ECSPI_STATREG_TF      0x00000004


/* --- Register HW_ECSPI_STATREG, field RR (RO)
 *
 * RXFIFO Ready. This bit is set when one or more words are stored in the RXFIFO.
 *
 * Values:
 * 0 - No valid data in RXFIFO.
 * 1 - More than 1 word in RXFIFO.
 */

#define BP_ECSPI_STATREG_RR      3
#define BM_ECSPI_STATREG_RR      0x00000008


/* --- Register HW_ECSPI_STATREG, field RDR (RO)
 *
 * RXFIFO Data Request.
 *
 * Values:
 * 0 - When RXTDE is set - Number of data entries in the RXFIFO is not greater than RX THRESHOLD.
 * 1 - When RXTDE is set - Number of data entries in the RXFIFO is greater than RX THRESHOLD or a DMA TAIL
 *     DMA condition exists.
 * 0 - When RXTDE is clear - Number of data entries in the RXFIFO is not greater than RX THRESHOLD.
 * 1 - When RXTDE is clear - Number of data entries in the RXFIFO is greater than RX THRESHOLD.
 */

#define BP_ECSPI_STATREG_RDR      4
#define BM_ECSPI_STATREG_RDR      0x00000010


/* --- Register HW_ECSPI_STATREG, field RF (RO)
 *
 * RXFIFO Full. This bit is set when the RXFIFO is full.
 *
 * Values:
 * 0 - Not Full.
 * 1 - Full.
 */

#define BP_ECSPI_STATREG_RF      5
#define BM_ECSPI_STATREG_RF      0x00000020


/* --- Register HW_ECSPI_STATREG, field RO (W1C)
 *
 * RXFIFO Overflow. When set, this bit indicates that RXFIFO has overflowed. Writing 1 to this bit
 * clears it.
 *
 * Values:
 * 0 - RXFIFO has no overflow.
 * 1 - RXFIFO has overflowed.
 */

#define BP_ECSPI_STATREG_RO      6
#define BM_ECSPI_STATREG_RO      0x00000040


/* --- Register HW_ECSPI_STATREG, field TC (W1C)
 *
 * Transfer Completed Status bit. Writing 1 to this bit clears it.
 *
 * Values:
 * 0 - Transfer in progress.
 * 1 - Transfer completed.
 */

#define BP_ECSPI_STATREG_TC      7
#define BM_ECSPI_STATREG_TC      0x00000080


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_PERIODREG - Sample Period Control Register (RW)
 *
 * The Sample Period Control Register (ECSPI_PERIODREG) provides software a way to insert delays
 * (wait states) between consecutive SPI transfers. Control bits in this register select the clock
 * source for the sample period counter and the delay count indicating the number of wait states to
 * be inserted between data transfers.   The delay counts apply only when the module is configured
 * in Master mode (CONREG[MODE] = 1).  The delay counts apply only when the current channel is
 * operating in Master mode (ECSPI_CONREG[CHANNEL MODE] = 1).ECSPI_PERIODREG also contains the CSD
 * CTRL field used to insert a delay between the Chip Select's active edge and the first SPI Clock
 * edge.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SAMPLE_PERIOD : 15; //!< Sample Period Control. These bits control the number of wait states to be inserted in data transfers. During the idle clocks, the state of the SS output will operate according to the SS_CTL control field in the ECSPI_CONREG register.
        unsigned CSRC : 1; //!< Clock Source Control. This bit selects the clock source for the sample period counter.
        unsigned CSD_CTL : 6; //!< Chip Select Delay Control bits. This field defines how many SPI clocks will be inserted between the chip select's active edge and the first SPI clock edge. The range is from 0 to 63.
        unsigned RESERVED0 : 10; //!< Reserved
    } B;
} hw_ecspi_periodreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_PERIODREG register
 */
#define HW_ECSPI_PERIODREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_PERIODREG(x)           (*(volatile hw_ecspi_periodreg_t *) HW_ECSPI_PERIODREG_ADDR(x))
#define HW_ECSPI_PERIODREG_RD(x)        (HW_ECSPI_PERIODREG(x).U)
#define HW_ECSPI_PERIODREG_WR(x, v)     (HW_ECSPI_PERIODREG(x).U = (v))
#define HW_ECSPI_PERIODREG_SET(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) |  (v)))
#define HW_ECSPI_PERIODREG_CLR(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) & ~(v)))
#define HW_ECSPI_PERIODREG_TOG(x, v)    (HW_ECSPI_PERIODREG_WR(x, HW_ECSPI_PERIODREG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual ECSPI_PERIODREG bitfields
 */

/* --- Register HW_ECSPI_PERIODREG, field SAMPLE_PERIOD (RW)
 *
 * Sample Period Control. These bits control the number of wait states to be inserted in data
 * transfers. During the idle clocks, the state of the SS output will operate according to the
 * SS_CTL control field in the ECSPI_CONREG register.
 *
 * Values:
 * 0x0000 - 0 wait states inserted
 * ... - ...
 * 0x0001 - 1 wait state inserted
 * 0x7FFE - 32766 wait states inserted
 * 0x7FFF - 32767 wait states inserted
 */

#define BP_ECSPI_PERIODREG_SAMPLE_PERIOD      0
#define BM_ECSPI_PERIODREG_SAMPLE_PERIOD      0x00007fff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_PERIODREG_SAMPLE_PERIOD(v)   ((((reg32_t) v) << 0) & BM_ECSPI_PERIODREG_SAMPLE_PERIOD)
#else
#define BF_ECSPI_PERIODREG_SAMPLE_PERIOD(v)   (((v) << 0) & BM_ECSPI_PERIODREG_SAMPLE_PERIOD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SAMPLE_PERIOD field to a new value.
#define BW_ECSPI_PERIODREG_SAMPLE_PERIOD(v)   BF_CS1(ECSPI_PERIODREG, SAMPLE_PERIOD, v)
#endif


/* --- Register HW_ECSPI_PERIODREG, field CSRC (RW)
 *
 * Clock Source Control. This bit selects the clock source for the sample period counter.
 *
 * Values:
 * 0 - SPI Clock (SCLK)
 * 1 - Low-Frequency Reference Clock (32.768 KHz)
 */

#define BP_ECSPI_PERIODREG_CSRC      15
#define BM_ECSPI_PERIODREG_CSRC      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_PERIODREG_CSRC(v)   ((((reg32_t) v) << 15) & BM_ECSPI_PERIODREG_CSRC)
#else
#define BF_ECSPI_PERIODREG_CSRC(v)   (((v) << 15) & BM_ECSPI_PERIODREG_CSRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSRC field to a new value.
#define BW_ECSPI_PERIODREG_CSRC(v)   BF_CS1(ECSPI_PERIODREG, CSRC, v)
#endif


/* --- Register HW_ECSPI_PERIODREG, field CSD_CTL (RW)
 *
 * Chip Select Delay Control bits. This field defines how many SPI clocks will be inserted between
 * the chip select's active edge and the first SPI clock edge. The range is from 0 to 63.
 */

#define BP_ECSPI_PERIODREG_CSD_CTL      16
#define BM_ECSPI_PERIODREG_CSD_CTL      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_PERIODREG_CSD_CTL(v)   ((((reg32_t) v) << 16) & BM_ECSPI_PERIODREG_CSD_CTL)
#else
#define BF_ECSPI_PERIODREG_CSD_CTL(v)   (((v) << 16) & BM_ECSPI_PERIODREG_CSD_CTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSD_CTL field to a new value.
#define BW_ECSPI_PERIODREG_CSD_CTL(v)   BF_CS1(ECSPI_PERIODREG, CSD_CTL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_TESTREG - Test Control Register (RW)
 *
 * The Test Control Register (ECSPI_TESTREG) provides software a mechanism to internally connect the
 * receive and transmit devices of the ECSPI  , define the data latch delay  , and monitor the
 * contents of the receive and transmit FIFOs.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXCNT : 7; //!< TXFIFO Counter. This field indicates the number of words in the TXFIFO.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RXCNT : 7; //!< RXFIFO Counter. This field indicates the number of words in the RXFIFO.
        unsigned RESERVED1 : 13; //!< Reserved
        unsigned RESERVED2 : 3; //!< Reserved, all bits should be ignored.
        unsigned LBC : 1; //!< Loop Back Control. This bit is used in Master mode only. When this bit is set, the ECSPI connects the transmitter and receiver sections internally, and the data shifted out from the most-significant bit of the shift register is looped back into the least-significant bit of the Shift register. In this way, a self-test of the complete transmit/receive path can be made. The output pins are not affected, and the input pins are ignored.
    } B;
} hw_ecspi_testreg_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_TESTREG register
 */
#define HW_ECSPI_TESTREG_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_TESTREG(x)           (*(volatile hw_ecspi_testreg_t *) HW_ECSPI_TESTREG_ADDR(x))
#define HW_ECSPI_TESTREG_RD(x)        (HW_ECSPI_TESTREG(x).U)
#define HW_ECSPI_TESTREG_WR(x, v)     (HW_ECSPI_TESTREG(x).U = (v))
#define HW_ECSPI_TESTREG_SET(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) |  (v)))
#define HW_ECSPI_TESTREG_CLR(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) & ~(v)))
#define HW_ECSPI_TESTREG_TOG(x, v)    (HW_ECSPI_TESTREG_WR(x, HW_ECSPI_TESTREG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual ECSPI_TESTREG bitfields
 */

/* --- Register HW_ECSPI_TESTREG, field TXCNT (RW)
 *
 * TXFIFO Counter. This field indicates the number of words in the TXFIFO.
 */

#define BP_ECSPI_TESTREG_TXCNT      0
#define BM_ECSPI_TESTREG_TXCNT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_TXCNT(v)   ((((reg32_t) v) << 0) & BM_ECSPI_TESTREG_TXCNT)
#else
#define BF_ECSPI_TESTREG_TXCNT(v)   (((v) << 0) & BM_ECSPI_TESTREG_TXCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCNT field to a new value.
#define BW_ECSPI_TESTREG_TXCNT(v)   BF_CS1(ECSPI_TESTREG, TXCNT, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field RXCNT (RW)
 *
 * RXFIFO Counter. This field indicates the number of words in the RXFIFO.
 */

#define BP_ECSPI_TESTREG_RXCNT      8
#define BM_ECSPI_TESTREG_RXCNT      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_RXCNT(v)   ((((reg32_t) v) << 8) & BM_ECSPI_TESTREG_RXCNT)
#else
#define BF_ECSPI_TESTREG_RXCNT(v)   (((v) << 8) & BM_ECSPI_TESTREG_RXCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXCNT field to a new value.
#define BW_ECSPI_TESTREG_RXCNT(v)   BF_CS1(ECSPI_TESTREG, RXCNT, v)
#endif

/* --- Register HW_ECSPI_TESTREG, field LBC (RW)
 *
 * Loop Back Control. This bit is used in Master mode only. When this bit is set, the ECSPI connects
 * the transmitter and receiver sections internally, and the data shifted out from the most-
 * significant bit of the shift register is looped back into the least-significant bit of the Shift
 * register. In this way, a self-test of the complete transmit/receive path can be made. The output
 * pins are not affected, and the input pins are ignored.
 *
 * Values:
 * 0 - Not connected.
 * 1 - Transmitter and receiver sections internally connected for Loopback.
 */

#define BP_ECSPI_TESTREG_LBC      31
#define BM_ECSPI_TESTREG_LBC      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TESTREG_LBC(v)   ((((reg32_t) v) << 31) & BM_ECSPI_TESTREG_LBC)
#else
#define BF_ECSPI_TESTREG_LBC(v)   (((v) << 31) & BM_ECSPI_TESTREG_LBC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LBC field to a new value.
#define BW_ECSPI_TESTREG_LBC(v)   BF_CS1(ECSPI_TESTREG, LBC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ECSPI_MSGDATA - Message Data Register (WO)
 *
 * The Message Data Register (ECSPI_MSGDATA) forms the top word of the 16 x 32 MSG Data FIFO. Only
 * word-size accesses are allowed for this register. Reads to this register return zero, and writes
 * to this register store data in the MSG Data FIFO. See .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ECSPI_MSGDATA : 32; //!< ECSPI_MSGDATA holds the top word of MSG Data FIFO. The MSG Data FIFO is advanced for each write of this register. The data read is zero. The data written to this register is stored in the MSG Data FIFO.
    } B;
} hw_ecspi_msgdata_t;
#endif

/*
 * constants & macros for entire multi-block ECSPI_MSGDATA register
 */
#define HW_ECSPI_MSGDATA_ADDR(x)      (REGS_ECSPI_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_ECSPI_MSGDATA(x)           (*(volatile hw_ecspi_msgdata_t *) HW_ECSPI_MSGDATA_ADDR(x))
#define HW_ECSPI_MSGDATA_WR(x, v)     (HW_ECSPI_MSGDATA(x).U = (v))
#endif

/*
 * constants & macros for individual ECSPI_MSGDATA bitfields
 */

/* --- Register HW_ECSPI_MSGDATA, field ECSPI_MSGDATA (WO)
 *
 * ECSPI_MSGDATA holds the top word of MSG Data FIFO. The MSG Data FIFO is advanced for each write
 * of this register. The data read is zero. The data written to this register is stored in the MSG
 * Data FIFO.
 */

#define BP_ECSPI_MSGDATA_ECSPI_MSGDATA      0
#define BM_ECSPI_MSGDATA_ECSPI_MSGDATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_MSGDATA_ECSPI_MSGDATA(v)   ((((reg32_t) v) << 0) & BM_ECSPI_MSGDATA_ECSPI_MSGDATA)
#else
#define BF_ECSPI_MSGDATA_ECSPI_MSGDATA(v)   (((v) << 0) & BM_ECSPI_MSGDATA_ECSPI_MSGDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ECSPI_MSGDATA field to a new value.
#define BW_ECSPI_MSGDATA_ECSPI_MSGDATA(v)   BF_CS1(ECSPI_MSGDATA, ECSPI_MSGDATA, v)
#endif


/*!
 * @brief All ECSPI module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_ecspi_rxdata_t RXDATA; //!< Receive Data Register
    volatile hw_ecspi_txdata_t TXDATA; //!< Transmit Data Register
    volatile hw_ecspi_conreg_t CONREG; //!< Control Register
    volatile hw_ecspi_configreg_t CONFIGREG; //!< Config Register
    volatile hw_ecspi_intreg_t INTREG; //!< Interrupt Control Register
    volatile hw_ecspi_dmareg_t DMAREG; //!< DMA Control Register
    volatile hw_ecspi_statreg_t STATREG; //!< Status Register
    volatile hw_ecspi_periodreg_t PERIODREG; //!< Sample Period Control Register
    volatile hw_ecspi_testreg_t TESTREG; //!< Test Control Register
    reg32_t _reserved0[7];
    volatile hw_ecspi_msgdata_t MSGDATA; //!< Message Data Register
} hw_ecspi_t
#endif

//! @brief Macro to access all ECSPI registers.
//! @param x ECSPI instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ECSPI(0)</code>.
#define HW_ECSPI(x)     (*(volatile hw_ecspi_t *) REGS_ECSPI_BASE(x))


#endif // _ECSPI_H
