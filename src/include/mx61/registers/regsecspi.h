/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _ECSPI_H
#define _ECSPI_H

#include "regs.h"

#ifndef REGS_ECSPI_BASE
#define REGS_ECSPI0_BASE (REGS_BASE + 0x02008000)
#define REGS_ECSPI1_BASE (REGS_BASE + 0x0200c000)
#define REGS_ECSPI2_BASE (REGS_BASE + 0x02010000)
#define REGS_ECSPI3_BASE (REGS_BASE + 0x02014000)
#define REGS_ECSPI4_BASE (REGS_BASE + 0x02018000)
#define REGS_ECSPI_BASE(x) ( x == 0 ? REGS_ECSPI0_BASE : x == 1 ? REGS_ECSPI1_BASE : x == 2 ? REGS_ECSPI2_BASE : x == 3 ? REGS_ECSPI3_BASE : x == 4 ? REGS_ECSPI4_BASE : 0xffff0000)
#endif


/*!
 * @brief HW_ECSPI_RXDATA - Receive Data Register
 *
 * The Receive Data register (ECSPI_RXDATA) is a read-only register that
 * forms the top word of the 8  64 x 32 receive FIFO. This                             register
 * holds the data received from an external SPI device during a                             data
 * transaction. Only word-sized read operations are allowed.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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
#define HW_ECSPI_RXDATA_WR(x, v)     (HW_ECSPI_RXDATA(x).U = (v))
#define HW_ECSPI_RXDATA_SET(x, v)    (HW_ECSPI_RXDATA_WR(x, HW_ECSPI_RXDATA_RD(x) |  (v)))
#define HW_ECSPI_RXDATA_CLR(x, v)    (HW_ECSPI_RXDATA_WR(x, HW_ECSPI_RXDATA_RD(x) & ~(v)))
#define HW_ECSPI_RXDATA_TOG(x, v)    (HW_ECSPI_RXDATA_WR(x, HW_ECSPI_RXDATA_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_RXDATA bitfields
 */

/* --- Register HW_ECSPI_RXDATA, field ECSPI_RXDATA
 *
 * Receive Data. This register holds the top word of the receive data
 * FIFO. The FIFO is advanced for each read of this register. The data
 * read is undefined when the Receive Data Ready (RR) bit in the
 * Interrupt Control/Status register is cleared. Zeros are read when
 * ECSPI is disabled.
 */

#define BP_ECSPI_RXDATA_ECSPI_RXDATA      0
#define BM_ECSPI_RXDATA_ECSPI_RXDATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_RXDATA_ECSPI_RXDATA(v)   ((((reg32_t) v) << 0) & BM_ECSPI_RXDATA_ECSPI_RXDATA)
#else
#define BF_ECSPI_RXDATA_ECSPI_RXDATA(v)   (((v) << 0) & BM_ECSPI_RXDATA_ECSPI_RXDATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_RXDATA_ECSPI_RXDATA(v)   BF_CS1(ECSPI_RXDATA, ECSPI_RXDATA, v)
#endif

/*!
 * @brief HW_ECSPI_TXDATA - Transmit Data Register
 *
 * The Transmit Data (ECSPI_TXDATA) register is a write-only data register
 * that forms the bottom word of the 8  64 x 32 TXFIFO.                             The TXFIFO can
 * be written to as long as it is not full, even when the                             SPI Exchange
 * bit (XCH) in ECSPI_CONREG is set. This allows software to                             write to
 * the TXFIFO during a SPI data exchange process. Writes to this
 * register are ignored when the ECSPI is disabled (ECSPI_CONREG[EN] bit is
 * cleared).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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
#define HW_ECSPI_TXDATA_RD(x)        (HW_ECSPI_TXDATA(x).U)
#define HW_ECSPI_TXDATA_WR(x, v)     (HW_ECSPI_TXDATA(x).U = (v))
#define HW_ECSPI_TXDATA_SET(x, v)    (HW_ECSPI_TXDATA_WR(x, HW_ECSPI_TXDATA_RD(x) |  (v)))
#define HW_ECSPI_TXDATA_CLR(x, v)    (HW_ECSPI_TXDATA_WR(x, HW_ECSPI_TXDATA_RD(x) & ~(v)))
#define HW_ECSPI_TXDATA_TOG(x, v)    (HW_ECSPI_TXDATA_WR(x, HW_ECSPI_TXDATA_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual ECSPI_TXDATA bitfields
 */

/* --- Register HW_ECSPI_TXDATA, field ECSPI_TXDATA
 *
 * Transmit Data. This register holds the top word of data loaded into
 * the FIFO. Data written to this register must be a word operation.
 * The number of bits actually transmitted is determined by the
 * BIT_COUNT field of the corresponding SPI Control register. If this
 * field contains more bits than the number specified by BIT_COUNT, the
 * extra bits are ignored. For example, to transfer 10 bits of data, a
 * 32-bit word must be written to this register. Bits 9-0 are shifted
 * out and bits 31-10 are ignored. When the ECSPI is operating in Slave
 * mode, zeros are shifted out when the FIFO is empty. Zeros are read
 * when ECSPI is disabled.
 */

#define BP_ECSPI_TXDATA_ECSPI_TXDATA      0
#define BM_ECSPI_TXDATA_ECSPI_TXDATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_TXDATA_ECSPI_TXDATA(v)   ((((reg32_t) v) << 0) & BM_ECSPI_TXDATA_ECSPI_TXDATA)
#else
#define BF_ECSPI_TXDATA_ECSPI_TXDATA(v)   (((v) << 0) & BM_ECSPI_TXDATA_ECSPI_TXDATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_TXDATA_ECSPI_TXDATA(v)   BF_CS1(ECSPI_TXDATA, ECSPI_TXDATA, v)
#endif

/*!
 * @brief HW_ECSPI_CONREG - Control Register
 *
 * The Control Register (CONREG)  (ECSPI_CONREG) allows software to enable the ECSPI , configure
 * its operating modes, specify the divider value, phase, and polarity of the clock,
 * configure the Chip Select (SS) and SPI_RDY control signal, and                             define
 * the transfer length.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EN : 1; //!< SPI Block Enable Control. This bit enables the ECSPI. This bit must be set before writing to other registers or initiating an exchange. Writing zero to this bit disables the block and resets the internal logic with the exception of the ECSPI_CONREG. The block's internal clocks are gated off whenever the block is disabled.
        unsigned RESERVED0 : 1; //!< 
        unsigned XCH : 1; //!< SPI Exchange Bit. This bit applies only when the module is configured in Master mode (MODE = 1).  This bit applies only to channels configured in Master mode (CHANNEL MODE = 1).   If the Start Mode Control (SMC) bit is cleared, writing a 1 to this bit starts one SPI burst or multiple SPI bursts according to the SPI SS Wave Form Select (SS_CTL). The XCH bit remains set while either the data exchange is in progress, or when the ECSPI is waiting for an active input if SPIRDY is enabled through DRCTL. This bit is cleared automatically when all data in the TXFIFO and the shift register has been shifted out.
        unsigned SMC : 1; //!< Start Mode Control. This bit applies only when the module is configured in Master mode (MODE = 1).  This bit applies only to channels configured in Master mode (CHANNEL MODE = 1).   It controls how the ECSPI starts a SPI burst, either through the SPI exchange bit, or immediately when the TXFIFO is written to.
        unsigned RESERVED1 : 16; //!< 
        unsigned BURST_LENGTH : 12; //!< Burst Length. This field defines the length of a SPI burst to be transferred. The Chip Select (SS) will remain asserted until all bits in a SPI burst are shifted out. A maximum of 2^12 bits can be transferred in a single SPI burst.  In master mode, it controls the number of bits per SPI burst. Since the shift register always loads 32-bit data from transmit FIFO, only the n least-significant (n = BURST LENGTH + 1) will be shifted out. The remaining bits will be ignored.  In slave mode, only when SS_CTL is cleared, this field will take effect in the transfer.  Number of Valid Bits in a SPI burst.
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

/* --- Register HW_ECSPI_CONREG, field EN
 *
 * SPI Block Enable Control. This bit enables the ECSPI. This bit must
 * be set before writing to other registers or initiating an exchange.
 * Writing zero to this bit disables the block and resets the internal
 * logic with the exception of the ECSPI_CONREG. The block's internal
 * clocks are gated off whenever the block is disabled.
 */

#define BP_ECSPI_CONREG_EN      0
#define BM_ECSPI_CONREG_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_EN(v)   ((((reg32_t) v) << 0) & BM_ECSPI_CONREG_EN)
#else
#define BF_ECSPI_CONREG_EN(v)   (((v) << 0) & BM_ECSPI_CONREG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_EN(v)   BF_CS1(ECSPI_CONREG, EN, v)
#endif

/* --- Register HW_ECSPI_CONREG, field XCH
 *
 * SPI Exchange Bit. This bit                                     applies only when the module is
 * configured in Master mode (MODE                                     = 1).  This bit applies
 * only to channels configured in Master mode (CHANNEL MODE =
 * 1).   If the Start Mode Control (SMC) bit is cleared, writing a 1 to this
 * bit starts one SPI burst or multiple SPI bursts according to the SPI
 * SS Wave Form Select (SS_CTL). The XCH bit remains set while either
 * the data exchange is in progress, or when the ECSPI is waiting for
 * an active input if SPIRDY is enabled through DRCTL. This bit is
 * cleared automatically when all data in the TXFIFO and the shift
 * register has been shifted out.
 */

#define BP_ECSPI_CONREG_XCH      2
#define BM_ECSPI_CONREG_XCH      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_XCH(v)   ((((reg32_t) v) << 2) & BM_ECSPI_CONREG_XCH)
#else
#define BF_ECSPI_CONREG_XCH(v)   (((v) << 2) & BM_ECSPI_CONREG_XCH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_XCH(v)   BF_CS1(ECSPI_CONREG, XCH, v)
#endif

/* --- Register HW_ECSPI_CONREG, field SMC
 *
 * Start Mode Control. This bit                                     applies only when the module is
 * configured in Master mode (MODE                                     = 1).  This bit applies
 * only to channels configured in Master mode (CHANNEL MODE =
 * 1).   It controls how the ECSPI starts a SPI burst, either through the SPI
 * exchange bit, or immediately when the TXFIFO is written to.
 */

#define BP_ECSPI_CONREG_SMC      3
#define BM_ECSPI_CONREG_SMC      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_SMC(v)   ((((reg32_t) v) << 3) & BM_ECSPI_CONREG_SMC)
#else
#define BF_ECSPI_CONREG_SMC(v)   (((v) << 3) & BM_ECSPI_CONREG_SMC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_SMC(v)   BF_CS1(ECSPI_CONREG, SMC, v)
#endif

/* --- Register HW_ECSPI_CONREG, field BURST_LENGTH
 *
 * Burst Length. This field defines the length of a SPI burst to be
 * transferred. The Chip Select (SS) will remain asserted until all
 * bits in a SPI burst are shifted out. A maximum of 2^12 bits can be
 * transferred in a single SPI burst.  In master mode, it controls the number of bits per SPI burst.
 * Since                                 the shift register always loads 32-bit data from transmit
 * FIFO, only                                 the n least-significant (n = BURST LENGTH + 1) will be
 * shifted out.                                 The remaining bits will be ignored.  In slave mode,
 * only when SS_CTL is cleared, this field will take                                 effect in the
 * transfer.  Number of Valid Bits in a SPI burst.
 */

#define BP_ECSPI_CONREG_BURST_LENGTH      20
#define BM_ECSPI_CONREG_BURST_LENGTH      0xfff00000

#ifndef __LANGUAGE_ASM__
#define BF_ECSPI_CONREG_BURST_LENGTH(v)   ((((reg32_t) v) << 20) & BM_ECSPI_CONREG_BURST_LENGTH)
#else
#define BF_ECSPI_CONREG_BURST_LENGTH(v)   (((v) << 20) & BM_ECSPI_CONREG_BURST_LENGTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ECSPI_CONREG_BURST_LENGTH(v)   BF_CS1(ECSPI_CONREG, BURST_LENGTH, v)
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
} hw_ecspi_t
#endif

//! @brief Macro to access all ECSPI registers.
//! @param x ECSPI instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ECSPI(0)</code>.
#define HW_ECSPI(x)     (*(volatile hw_ecspi_t *) REGS_ECSPI_BASE(x))


#endif // _ECSPI_H
