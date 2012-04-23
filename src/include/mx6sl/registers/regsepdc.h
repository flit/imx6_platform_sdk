/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_EPDC_REGISTERS_H__
#define __HW_EPDC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL EPDC registers defined in this header file.
 *
 * - HW_EPDC_HW_EPDC_CTRL - EPDC Control Register
 * - HW_EPDC_HW_EPDC_WVADDR - EPDC Waveform Address Pointer
 * - HW_EPDC_HW_EPDC_WB_ADDR - EPDC Working Buffer Address
 * - HW_EPDC_HW_EPDC_RES - EPDC Screen Resolution
 * - HW_EPDC_HW_EPDC_FORMAT - EPDC Format Control Register
 * - HW_EPDC_HW_EPDC_FIFOCTRL - EPDC FIFO control register
 * - HW_EPDC_HW_EPDC_UPD_ADDR - EPDC Update Region Address
 * - HW_EPDC_HW_EPDC_UPD_STRIDE - EPDC Update Region Stride
 * - HW_EPDC_HW_EPDC_UPD_CORD - EPDC Update Command Co-ordinate
 * - HW_EPDC_HW_EPDC_UPD_SIZE - EPDC Update Command Size
 * - HW_EPDC_HW_EPDC_UPD_CTRL - EPDC Update Command Control
 * - HW_EPDC_HW_EPDC_UPD_FIXED - EPDC Update Fixed Pixel Control
 * - HW_EPDC_HW_EPDC_TEMP - EPDC Temperature Register
 * - HW_EPDC_HW_EPDC_AUTOWV_LUT - Waveform Mode Lookup Table Control Register.
 * - HW_EPDC_HW_EPDC_TCE_CTRL - EPDC Timing Control Engine Control Register
 * - HW_EPDC_HW_EPDC_TCE_SDCFG - EPDC Timing Control Engine Source-Driver Config Register
 * - HW_EPDC_HW_EPDC_TCE_GDCFG - EPDC Timing Control Engine Gate-Driver Config Register
 * - HW_EPDC_HW_EPDC_TCE_HSCAN1 - EPDC Timing Control Engine Horizontal Timing Register 1
 * - HW_EPDC_HW_EPDC_TCE_HSCAN2 - EPDC Timing Control Engine Horizontal Timing Register 2
 * - HW_EPDC_HW_EPDC_TCE_VSCAN - EPDC Timing Control Engine Vertical Timing Register
 * - HW_EPDC_HW_EPDC_TCE_OE - EPDC Timing Control Engine OE timing control Register
 * - HW_EPDC_HW_EPDC_TCE_POLARITY - EPDC Timing Control Engine Driver Polarity Register
 * - HW_EPDC_HW_EPDC_TCE_TIMING1 - EPDC Timing Control Engine Timing Register 1
 * - HW_EPDC_HW_EPDC_TCE_TIMING2 - EPDC Timing Control Engine Timing Register 2
 * - HW_EPDC_HW_EPDC_TCE_TIMING3 - EPDC Timing Control Engine Timing Register 3
 * - HW_EPDC_HW_EPDC_PIGEON_CTRL0 - EPDC Pigeon Mode Control Register 0
 * - HW_EPDC_HW_EPDC_PIGEON_CTRL1 - EPDC Pigeon Mode Control Register 1
 * - HW_EPDC_HW_EPDC_IRQ_MASK1 - EPDC IRQ Mask Register for LUT 0~31
 * - HW_EPDC_HW_EPDC_IRQ_MASK2 - EPDC IRQ Mask Register for LUT 32~63
 * - HW_EPDC_HW_EPDC_IRQ1 - EPDC Interrupt Register for LUT 0~31
 * - HW_EPDC_HW_EPDC_IRQ2 - EPDC Interrupt Registerr for LUT 32~63
 * - HW_EPDC_HW_EPDC_IRQ_MASK - EPDC IRQ Mask Register
 * - HW_EPDC_HW_EPDC_IRQ - EPDC Interrupt Register
 * - HW_EPDC_HW_EPDC_STATUS_LUTS1 - EPDC Status Register - LUTs
 * - HW_EPDC_HW_EPDC_STATUS_LUTS2 - EPDC Status Register - LUTs
 * - HW_EPDC_HW_EPDC_STATUS_NEXTLUT - EPDC Status Register - Next Available LUT
 * - HW_EPDC_HW_EPDC_STATUS_COL1 - EPDC LUT Collision Status
 * - HW_EPDC_HW_EPDC_STATUS_COL2 - EPDC LUT Collision Status
 * - HW_EPDC_HW_EPDC_STATUS - EPDC General Status Register
 * - HW_EPDC_HW_EPDC_UPD_COL_CORD - EPDC Collision Region Co-ordinate
 * - HW_EPDC_HW_EPDC_UPD_COL_SIZE - EPDC Collision Region Size
 * - HW_EPDC_HW_EPDC_DEBUG - EPDC Debug register
 * - HW_EPDC_HW_EPDC_DEBUG_LUT - EPDC LUT Debug Information register
 * - HW_EPDC_HW_EPDC_HIST1_PARAM - 1-level Histogram Parameter Register.
 * - HW_EPDC_HW_EPDC_HIST2_PARAM - 2-level Histogram Parameter Register.
 * - HW_EPDC_HW_EPDC_HIST4_PARAM - 4-level Histogram Parameter Register.
 * - HW_EPDC_HW_EPDC_HIST8_PARAM0 - 8-level Histogram Parameter 0 Register.
 * - HW_EPDC_HW_EPDC_HIST8_PARAM1 - 8-level Histogram Parameter 1 Register.
 * - HW_EPDC_HW_EPDC_HIST16_PARAM0 - 16-level Histogram Parameter 0 Register.
 * - HW_EPDC_HW_EPDC_HIST16_PARAM1 - 16-level Histogram Parameter Register.
 * - HW_EPDC_HW_EPDC_HIST16_PARAM2 - 16-level Histogram Parameter Register.
 * - HW_EPDC_HW_EPDC_HIST16_PARAM3 - 16-level Histogram Parameter Register.
 * - HW_EPDC_HW_EPDC_GPIO - EPDC General Purpose I/O Debug register
 * - HW_EPDC_HW_EPDC_VERSION - EPDC Version Register
 * - HW_EPDC_HW_EPDC_PIGEON_0_0 - Panel Interface Signal Generator Register 0_0
 * - HW_EPDC_HW_EPDC_PIGEON_0_1 - Panel Interface Signal Generator Register 0_1
 * - HW_EPDC_HW_EPDC_PIGEON_0_2 - Panel Interface Signal Generator Register 0_1
 * - HW_EPDC_HW_EPDC_PIGEON_1_0 - Panel Interface Signal Generator Register 1_0
 * - HW_EPDC_HW_EPDC_PIGEON_1_1 - Panel Interface Signal Generator Register 1_1
 * - HW_EPDC_HW_EPDC_PIGEON_1_2 - Panel Interface Signal Generator Register 1_1
 * - HW_EPDC_HW_EPDC_PIGEON_2_0 - Panel Interface Signal Generator Register 2_0
 * - HW_EPDC_HW_EPDC_PIGEON_2_1 - Panel Interface Signal Generator Register 2_1
 * - HW_EPDC_HW_EPDC_PIGEON_2_2 - Panel Interface Signal Generator Register 2_1
 * - HW_EPDC_HW_EPDC_PIGEON_3_0 - Panel Interface Signal Generator Register 3_0
 * - HW_EPDC_HW_EPDC_PIGEON_3_1 - Panel Interface Signal Generator Register 3_1
 * - HW_EPDC_HW_EPDC_PIGEON_3_2 - Panel Interface Signal Generator Register 3_1
 * - HW_EPDC_HW_EPDC_PIGEON_4_0 - Panel Interface Signal Generator Register 4_0
 * - HW_EPDC_HW_EPDC_PIGEON_4_1 - Panel Interface Signal Generator Register 4_1
 * - HW_EPDC_HW_EPDC_PIGEON_4_2 - Panel Interface Signal Generator Register 4_1
 * - HW_EPDC_HW_EPDC_PIGEON_5_0 - Panel Interface Signal Generator Register 5_0
 * - HW_EPDC_HW_EPDC_PIGEON_5_1 - Panel Interface Signal Generator Register 5_1
 * - HW_EPDC_HW_EPDC_PIGEON_5_2 - Panel Interface Signal Generator Register 5_1
 * - HW_EPDC_HW_EPDC_PIGEON_6_0 - Panel Interface Signal Generator Register 6_0
 * - HW_EPDC_HW_EPDC_PIGEON_6_1 - Panel Interface Signal Generator Register 6_1
 * - HW_EPDC_HW_EPDC_PIGEON_6_2 - Panel Interface Signal Generator Register 6_1
 * - HW_EPDC_HW_EPDC_PIGEON_7_0 - Panel Interface Signal Generator Register 7_0
 * - HW_EPDC_HW_EPDC_PIGEON_7_1 - Panel Interface Signal Generator Register 7_1
 * - HW_EPDC_HW_EPDC_PIGEON_7_2 - Panel Interface Signal Generator Register 7_1
 * - HW_EPDC_HW_EPDC_PIGEON_8_0 - Panel Interface Signal Generator Register 8_0
 * - HW_EPDC_HW_EPDC_PIGEON_8_1 - Panel Interface Signal Generator Register 8_1
 * - HW_EPDC_HW_EPDC_PIGEON_8_2 - Panel Interface Signal Generator Register 8_1
 * - HW_EPDC_HW_EPDC_PIGEON_9_0 - Panel Interface Signal Generator Register 9_0
 * - HW_EPDC_HW_EPDC_PIGEON_9_1 - Panel Interface Signal Generator Register 9_1
 * - HW_EPDC_HW_EPDC_PIGEON_9_2 - Panel Interface Signal Generator Register 9_1
 * - HW_EPDC_HW_EPDC_PIGEON_10_0 - Panel Interface Signal Generator Register 10_0
 * - HW_EPDC_HW_EPDC_PIGEON_10_1 - Panel Interface Signal Generator Register 10_1
 * - HW_EPDC_HW_EPDC_PIGEON_10_2 - Panel Interface Signal Generator Register 10_1
 * - HW_EPDC_HW_EPDC_PIGEON_11_0 - Panel Interface Signal Generator Register 11_0
 * - HW_EPDC_HW_EPDC_PIGEON_11_1 - Panel Interface Signal Generator Register 11_1
 * - HW_EPDC_HW_EPDC_PIGEON_11_2 - Panel Interface Signal Generator Register 11_1
 * - HW_EPDC_HW_EPDC_PIGEON_12_0 - Panel Interface Signal Generator Register 12_0
 * - HW_EPDC_HW_EPDC_PIGEON_12_1 - Panel Interface Signal Generator Register 12_1
 * - HW_EPDC_HW_EPDC_PIGEON_12_2 - Panel Interface Signal Generator Register 12_1
 * - HW_EPDC_HW_EPDC_PIGEON_13_0 - Panel Interface Signal Generator Register 13_0
 * - HW_EPDC_HW_EPDC_PIGEON_13_1 - Panel Interface Signal Generator Register 13_1
 * - HW_EPDC_HW_EPDC_PIGEON_13_2 - Panel Interface Signal Generator Register 13_1
 * - HW_EPDC_HW_EPDC_PIGEON_14_0 - Panel Interface Signal Generator Register 14_0
 * - HW_EPDC_HW_EPDC_PIGEON_14_1 - Panel Interface Signal Generator Register 14_1
 * - HW_EPDC_HW_EPDC_PIGEON_14_2 - Panel Interface Signal Generator Register 14_1
 * - HW_EPDC_HW_EPDC_PIGEON_15_0 - Panel Interface Signal Generator Register 15_0
 * - HW_EPDC_HW_EPDC_PIGEON_15_1 - Panel Interface Signal Generator Register 15_1
 * - HW_EPDC_HW_EPDC_PIGEON_15_2 - Panel Interface Signal Generator Register 15_1
 * - HW_EPDC_HW_EPDC_PIGEON_16_0 - Panel Interface Signal Generator Register 16_0
 * - HW_EPDC_HW_EPDC_PIGEON_16_1 - Panel Interface Signal Generator Register 16_1
 * - HW_EPDC_HW_EPDC_PIGEON_16_2 - Panel Interface Signal Generator Register 16_1
 *
 * - hw_epdc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_EPDC_BASE
#define HW_EPDC_INSTANCE_COUNT (1) //!< Number of instances of the EPDC module.
#define REGS_EPDC_BASE (0x020f4000) //!< Base address for EPDC.
#endif
//@}

// Typecast macro for C or asm. In C, the cast is applied, while in asm it is excluded. This is
// used to simplify macro definitions below.
#ifndef __REG_VALUE_TYPE
#ifndef __LANGUAGE_ASM__
#define __REG_VALUE_TYPE(v, t) ((t)(v))
#else
#define __REG_VALUE_TYPE(v, t) (v)
#endif
#endif


//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_CTRL - EPDC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_CTRL - EPDC Control Register (RW)
 *
 * Reset value: 0xc0000000
 *
 * EPDC Main control register  HW_EPDC_CTRL: 0x000  HW_EPDC_CTRL_SET: 0x004  HW_EPDC_CTRL_CLR: 0x008
 * HW_EPDC_CTRL_TOG: 0x00C  This register controls various high-level functions of the EPDC
 * EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_ctrl
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_ctrl_bitfields
    {
        unsigned BURST_LEN_8 : 1; //!< [0] 0- EPDC display fifo logic will issue AXI bursts of length 16. When set to 1, the block will issue bursts of length 8.
        unsigned RESERVED0 : 3; //!< [3:1] Reserved.
        unsigned LUT_DATA_SWIZZLE : 2; //!< [5:4] Specifies how to swap the bytes for the LUT data before store to LUTRAM. Supported configurations:
        unsigned UPD_DATA_SWIZZLE : 2; //!< [7:6] Specifies how to swap the bytes for the UPD data before the WB construction. Plesae note this swizzle operate right after data fetch from bus, no matter it's aligned access or not. Supported configurations:
        unsigned SRAM_POWERDOWN : 1; //!< [8] Enable Power-down of embedded SRAM memories
        unsigned RESERVED1 : 21; //!< [29:9] Reserved.
        unsigned CLKGATE : 1; //!< [30] This bit must be set to zero for normal operation. When set to one it gates off the clocks to the block.
        unsigned SFTRST : 1; //!< [31] Set this bit to zero to enable normal EPDC operation. Set this bit to one (default) to disable clocking with the EPDC and hold it in its reset (lowest power) state. This bit can be turned on and then off to reset the EPDC block to its default state.
    } B;
} hw_epdc_hw_epdc_ctrl_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_CTRL register
 */
#define HW_EPDC_HW_EPDC_CTRL_ADDR      (REGS_EPDC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_CTRL           (*(volatile hw_epdc_hw_epdc_ctrl_t *) HW_EPDC_HW_EPDC_CTRL_ADDR)
#define HW_EPDC_HW_EPDC_CTRL_RD()      (HW_EPDC_HW_EPDC_CTRL.U)
#define HW_EPDC_HW_EPDC_CTRL_WR(v)     (HW_EPDC_HW_EPDC_CTRL.U = (v))
#define HW_EPDC_HW_EPDC_CTRL_SET(v)    (HW_EPDC_HW_EPDC_CTRL_WR(HW_EPDC_HW_EPDC_CTRL_RD() |  (v)))
#define HW_EPDC_HW_EPDC_CTRL_CLR(v)    (HW_EPDC_HW_EPDC_CTRL_WR(HW_EPDC_HW_EPDC_CTRL_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_CTRL_TOG(v)    (HW_EPDC_HW_EPDC_CTRL_WR(HW_EPDC_HW_EPDC_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_CTRL bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_CTRL, field BURST_LEN_8[0] (RW)
 *
 * 0- EPDC display fifo logic will issue AXI bursts of length 16. When set to 1, the block will
 * issue bursts of length 8.
 */

#define BP_EPDC_HW_EPDC_CTRL_BURST_LEN_8      (0)      //!< Bit position for EPDC_HW_EPDC_CTRL_BURST_LEN_8.
#define BM_EPDC_HW_EPDC_CTRL_BURST_LEN_8      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_CTRL_BURST_LEN_8.

//! @brief Get value of EPDC_HW_EPDC_CTRL_BURST_LEN_8 from a register value.
#define BG_EPDC_HW_EPDC_CTRL_BURST_LEN_8(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_CTRL_BURST_LEN_8) >> BP_EPDC_HW_EPDC_CTRL_BURST_LEN_8)

//! @brief Format value for bitfield EPDC_HW_EPDC_CTRL_BURST_LEN_8.
#define BF_EPDC_HW_EPDC_CTRL_BURST_LEN_8(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_CTRL_BURST_LEN_8) & BM_EPDC_HW_EPDC_CTRL_BURST_LEN_8)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BURST_LEN_8 field to a new value.
#define BW_EPDC_HW_EPDC_CTRL_BURST_LEN_8(v)   (HW_EPDC_HW_EPDC_CTRL_WR((HW_EPDC_HW_EPDC_CTRL_RD() & ~BM_EPDC_HW_EPDC_CTRL_BURST_LEN_8) | BF_EPDC_HW_EPDC_CTRL_BURST_LEN_8(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_CTRL, field LUT_DATA_SWIZZLE[5:4] (RW)
 *
 * Specifies how to swap the bytes for the LUT data before store to LUTRAM. Supported
 * configurations:
 *
 * Values:
 * NO_SWAP = 0x0 - No byte swapping.(Little endian)
 * ALL_BYTES_SWAP = 0x1 - Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 * HWD_SWAP = 0x2 - Swap half-words.
 * HWD_BYTE_SWAP = 0x3 - Swap bytes within each half-word.
 * HWD_BYTE_SWAP = 0x3 - Swap bytes within each half-word.
 */

#define BP_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE      (4)      //!< Bit position for EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE.
#define BM_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE      (0x00000030)  //!< Bit mask for EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE.

//! @brief Get value of EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE from a register value.
#define BG_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE) >> BP_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE)

//! @brief Format value for bitfield EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE.
#define BF_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE) & BM_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_DATA_SWIZZLE field to a new value.
#define BW_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE(v)   (HW_EPDC_HW_EPDC_CTRL_WR((HW_EPDC_HW_EPDC_CTRL_RD() & ~BM_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE) | BF_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE(v)))
#endif

#define BV_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE__NO_SWAP (0x0) //!< No byte swapping.(Little endian)
#define BV_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE__ALL_BYTES_SWAP (0x1) //!< Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
#define BV_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE__HWD_SWAP (0x2) //!< Swap half-words.
#define BV_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE__HWD_BYTE_SWAP (0x3) //!< Swap bytes within each half-word.
#define BV_EPDC_HW_EPDC_CTRL_LUT_DATA_SWIZZLE__HWD_BYTE_SWAP (0x3) //!< Swap bytes within each half-word.

/* --- Register HW_EPDC_HW_EPDC_CTRL, field UPD_DATA_SWIZZLE[7:6] (RW)
 *
 * Specifies how to swap the bytes for the UPD data before the WB construction. Plesae note this
 * swizzle operate right after data fetch from bus, no matter it's aligned access or not. Supported
 * configurations:
 *
 * Values:
 * NO_SWAP = 0x0 - No byte swapping.(Little endian)
 * ALL_BYTES_SWAP = 0x1 - Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 * HWD_SWAP = 0x2 - Swap half-words.
 * HWD_BYTE_SWAP = 0x3 - Swap bytes within each half-word.
 */

#define BP_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE      (6)      //!< Bit position for EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE.
#define BM_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE      (0x000000c0)  //!< Bit mask for EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE.

//! @brief Get value of EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE from a register value.
#define BG_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE) >> BP_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE)

//! @brief Format value for bitfield EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE.
#define BF_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE) & BM_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPD_DATA_SWIZZLE field to a new value.
#define BW_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE(v)   (HW_EPDC_HW_EPDC_CTRL_WR((HW_EPDC_HW_EPDC_CTRL_RD() & ~BM_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE) | BF_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE(v)))
#endif

#define BV_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE__NO_SWAP (0x0) //!< No byte swapping.(Little endian)
#define BV_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE__ALL_BYTES_SWAP (0x1) //!< Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
#define BV_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE__HWD_SWAP (0x2) //!< Swap half-words.
#define BV_EPDC_HW_EPDC_CTRL_UPD_DATA_SWIZZLE__HWD_BYTE_SWAP (0x3) //!< Swap bytes within each half-word.

/* --- Register HW_EPDC_HW_EPDC_CTRL, field SRAM_POWERDOWN[8] (RW)
 *
 * Enable Power-down of embedded SRAM memories
 */

#define BP_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN      (8)      //!< Bit position for EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN.
#define BM_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN      (0x00000100)  //!< Bit mask for EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN.

//! @brief Get value of EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN from a register value.
#define BG_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN) >> BP_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN)

//! @brief Format value for bitfield EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN.
#define BF_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN) & BM_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRAM_POWERDOWN field to a new value.
#define BW_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN(v)   (HW_EPDC_HW_EPDC_CTRL_WR((HW_EPDC_HW_EPDC_CTRL_RD() & ~BM_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN) | BF_EPDC_HW_EPDC_CTRL_SRAM_POWERDOWN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_CTRL, field CLKGATE[30] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one it gates off the clocks to the
 * block.
 */

#define BP_EPDC_HW_EPDC_CTRL_CLKGATE      (30)      //!< Bit position for EPDC_HW_EPDC_CTRL_CLKGATE.
#define BM_EPDC_HW_EPDC_CTRL_CLKGATE      (0x40000000)  //!< Bit mask for EPDC_HW_EPDC_CTRL_CLKGATE.

//! @brief Get value of EPDC_HW_EPDC_CTRL_CLKGATE from a register value.
#define BG_EPDC_HW_EPDC_CTRL_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_CTRL_CLKGATE) >> BP_EPDC_HW_EPDC_CTRL_CLKGATE)

//! @brief Format value for bitfield EPDC_HW_EPDC_CTRL_CLKGATE.
#define BF_EPDC_HW_EPDC_CTRL_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_CTRL_CLKGATE) & BM_EPDC_HW_EPDC_CTRL_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_EPDC_HW_EPDC_CTRL_CLKGATE(v)   (HW_EPDC_HW_EPDC_CTRL_WR((HW_EPDC_HW_EPDC_CTRL_RD() & ~BM_EPDC_HW_EPDC_CTRL_CLKGATE) | BF_EPDC_HW_EPDC_CTRL_CLKGATE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_CTRL, field SFTRST[31] (RW)
 *
 * Set this bit to zero to enable normal EPDC operation. Set this bit to one (default) to disable
 * clocking with the EPDC and hold it in its reset (lowest power) state. This bit can be turned on
 * and then off to reset the EPDC block to its default state.
 */

#define BP_EPDC_HW_EPDC_CTRL_SFTRST      (31)      //!< Bit position for EPDC_HW_EPDC_CTRL_SFTRST.
#define BM_EPDC_HW_EPDC_CTRL_SFTRST      (0x80000000)  //!< Bit mask for EPDC_HW_EPDC_CTRL_SFTRST.

//! @brief Get value of EPDC_HW_EPDC_CTRL_SFTRST from a register value.
#define BG_EPDC_HW_EPDC_CTRL_SFTRST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_CTRL_SFTRST) >> BP_EPDC_HW_EPDC_CTRL_SFTRST)

//! @brief Format value for bitfield EPDC_HW_EPDC_CTRL_SFTRST.
#define BF_EPDC_HW_EPDC_CTRL_SFTRST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_CTRL_SFTRST) & BM_EPDC_HW_EPDC_CTRL_SFTRST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_EPDC_HW_EPDC_CTRL_SFTRST(v)   (HW_EPDC_HW_EPDC_CTRL_WR((HW_EPDC_HW_EPDC_CTRL_RD() & ~BM_EPDC_HW_EPDC_CTRL_SFTRST) | BF_EPDC_HW_EPDC_CTRL_SFTRST(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_WVADDR - EPDC Waveform Address Pointer
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_WVADDR - EPDC Waveform Address Pointer (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Waveform Address Pointer  N/A   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_wvaddr
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_wvaddr_bitfields
    {
        unsigned ADDR : 32; //!< [31:0] Start address of waveform tables. This address needs to be aligned to a 64-bit word boundary.
    } B;
} hw_epdc_hw_epdc_wvaddr_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_WVADDR register
 */
#define HW_EPDC_HW_EPDC_WVADDR_ADDR      (REGS_EPDC_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_WVADDR           (*(volatile hw_epdc_hw_epdc_wvaddr_t *) HW_EPDC_HW_EPDC_WVADDR_ADDR)
#define HW_EPDC_HW_EPDC_WVADDR_RD()      (HW_EPDC_HW_EPDC_WVADDR.U)
#define HW_EPDC_HW_EPDC_WVADDR_WR(v)     (HW_EPDC_HW_EPDC_WVADDR.U = (v))
#define HW_EPDC_HW_EPDC_WVADDR_SET(v)    (HW_EPDC_HW_EPDC_WVADDR_WR(HW_EPDC_HW_EPDC_WVADDR_RD() |  (v)))
#define HW_EPDC_HW_EPDC_WVADDR_CLR(v)    (HW_EPDC_HW_EPDC_WVADDR_WR(HW_EPDC_HW_EPDC_WVADDR_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_WVADDR_TOG(v)    (HW_EPDC_HW_EPDC_WVADDR_WR(HW_EPDC_HW_EPDC_WVADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_WVADDR bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_WVADDR, field ADDR[31:0] (RW)
 *
 * Start address of waveform tables. This address needs to be aligned to a 64-bit word boundary.
 */

#define BP_EPDC_HW_EPDC_WVADDR_ADDR      (0)      //!< Bit position for EPDC_HW_EPDC_WVADDR_ADDR.
#define BM_EPDC_HW_EPDC_WVADDR_ADDR      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_WVADDR_ADDR.

//! @brief Get value of EPDC_HW_EPDC_WVADDR_ADDR from a register value.
#define BG_EPDC_HW_EPDC_WVADDR_ADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_WVADDR_ADDR) >> BP_EPDC_HW_EPDC_WVADDR_ADDR)

//! @brief Format value for bitfield EPDC_HW_EPDC_WVADDR_ADDR.
#define BF_EPDC_HW_EPDC_WVADDR_ADDR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_WVADDR_ADDR) & BM_EPDC_HW_EPDC_WVADDR_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPDC_HW_EPDC_WVADDR_ADDR(v)   (HW_EPDC_HW_EPDC_WVADDR_WR((HW_EPDC_HW_EPDC_WVADDR_RD() & ~BM_EPDC_HW_EPDC_WVADDR_ADDR) | BF_EPDC_HW_EPDC_WVADDR_ADDR(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_WB_ADDR - EPDC Working Buffer Address
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_WB_ADDR - EPDC Working Buffer Address (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Working Buffer Address  This register controls various functions throughout the digital
 * portion of the chip.   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_wb_addr
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_wb_addr_bitfields
    {
        unsigned ADDR : 32; //!< [31:0] Address for EPDC working buffer. This address must be a aligned to a 64-bit double-word boundary.
    } B;
} hw_epdc_hw_epdc_wb_addr_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_WB_ADDR register
 */
#define HW_EPDC_HW_EPDC_WB_ADDR_ADDR      (REGS_EPDC_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_WB_ADDR           (*(volatile hw_epdc_hw_epdc_wb_addr_t *) HW_EPDC_HW_EPDC_WB_ADDR_ADDR)
#define HW_EPDC_HW_EPDC_WB_ADDR_RD()      (HW_EPDC_HW_EPDC_WB_ADDR.U)
#define HW_EPDC_HW_EPDC_WB_ADDR_WR(v)     (HW_EPDC_HW_EPDC_WB_ADDR.U = (v))
#define HW_EPDC_HW_EPDC_WB_ADDR_SET(v)    (HW_EPDC_HW_EPDC_WB_ADDR_WR(HW_EPDC_HW_EPDC_WB_ADDR_RD() |  (v)))
#define HW_EPDC_HW_EPDC_WB_ADDR_CLR(v)    (HW_EPDC_HW_EPDC_WB_ADDR_WR(HW_EPDC_HW_EPDC_WB_ADDR_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_WB_ADDR_TOG(v)    (HW_EPDC_HW_EPDC_WB_ADDR_WR(HW_EPDC_HW_EPDC_WB_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_WB_ADDR bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_WB_ADDR, field ADDR[31:0] (RW)
 *
 * Address for EPDC working buffer. This address must be a aligned to a 64-bit double-word boundary.
 */

#define BP_EPDC_HW_EPDC_WB_ADDR_ADDR      (0)      //!< Bit position for EPDC_HW_EPDC_WB_ADDR_ADDR.
#define BM_EPDC_HW_EPDC_WB_ADDR_ADDR      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_WB_ADDR_ADDR.

//! @brief Get value of EPDC_HW_EPDC_WB_ADDR_ADDR from a register value.
#define BG_EPDC_HW_EPDC_WB_ADDR_ADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_WB_ADDR_ADDR) >> BP_EPDC_HW_EPDC_WB_ADDR_ADDR)

//! @brief Format value for bitfield EPDC_HW_EPDC_WB_ADDR_ADDR.
#define BF_EPDC_HW_EPDC_WB_ADDR_ADDR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_WB_ADDR_ADDR) & BM_EPDC_HW_EPDC_WB_ADDR_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPDC_HW_EPDC_WB_ADDR_ADDR(v)   (HW_EPDC_HW_EPDC_WB_ADDR_WR((HW_EPDC_HW_EPDC_WB_ADDR_RD() & ~BM_EPDC_HW_EPDC_WB_ADDR_ADDR) | BF_EPDC_HW_EPDC_WB_ADDR_ADDR(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_RES - EPDC Screen Resolution
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_RES - EPDC Screen Resolution (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Screen Resolution. This register defines the horizontal and vertical resolution of the
 * target display panel  N/A   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_res
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_res_bitfields
    {
        unsigned HORIZONTAL : 13; //!< [12:0] Horizontal Resolution (in pixels)
        unsigned RESERVED0 : 3; //!< [15:13] Reserved.
        unsigned VERTICAL : 13; //!< [28:16] Vertical Resoltion (in pixels)
        unsigned RESERVED1 : 3; //!< [31:29] Reserved.
    } B;
} hw_epdc_hw_epdc_res_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_RES register
 */
#define HW_EPDC_HW_EPDC_RES_ADDR      (REGS_EPDC_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_RES           (*(volatile hw_epdc_hw_epdc_res_t *) HW_EPDC_HW_EPDC_RES_ADDR)
#define HW_EPDC_HW_EPDC_RES_RD()      (HW_EPDC_HW_EPDC_RES.U)
#define HW_EPDC_HW_EPDC_RES_WR(v)     (HW_EPDC_HW_EPDC_RES.U = (v))
#define HW_EPDC_HW_EPDC_RES_SET(v)    (HW_EPDC_HW_EPDC_RES_WR(HW_EPDC_HW_EPDC_RES_RD() |  (v)))
#define HW_EPDC_HW_EPDC_RES_CLR(v)    (HW_EPDC_HW_EPDC_RES_WR(HW_EPDC_HW_EPDC_RES_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_RES_TOG(v)    (HW_EPDC_HW_EPDC_RES_WR(HW_EPDC_HW_EPDC_RES_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_RES bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_RES, field HORIZONTAL[12:0] (RW)
 *
 * Horizontal Resolution (in pixels)
 */

#define BP_EPDC_HW_EPDC_RES_HORIZONTAL      (0)      //!< Bit position for EPDC_HW_EPDC_RES_HORIZONTAL.
#define BM_EPDC_HW_EPDC_RES_HORIZONTAL      (0x00001fff)  //!< Bit mask for EPDC_HW_EPDC_RES_HORIZONTAL.

//! @brief Get value of EPDC_HW_EPDC_RES_HORIZONTAL from a register value.
#define BG_EPDC_HW_EPDC_RES_HORIZONTAL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_RES_HORIZONTAL) >> BP_EPDC_HW_EPDC_RES_HORIZONTAL)

//! @brief Format value for bitfield EPDC_HW_EPDC_RES_HORIZONTAL.
#define BF_EPDC_HW_EPDC_RES_HORIZONTAL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_RES_HORIZONTAL) & BM_EPDC_HW_EPDC_RES_HORIZONTAL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HORIZONTAL field to a new value.
#define BW_EPDC_HW_EPDC_RES_HORIZONTAL(v)   (HW_EPDC_HW_EPDC_RES_WR((HW_EPDC_HW_EPDC_RES_RD() & ~BM_EPDC_HW_EPDC_RES_HORIZONTAL) | BF_EPDC_HW_EPDC_RES_HORIZONTAL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_RES, field VERTICAL[28:16] (RW)
 *
 * Vertical Resoltion (in pixels)
 */

#define BP_EPDC_HW_EPDC_RES_VERTICAL      (16)      //!< Bit position for EPDC_HW_EPDC_RES_VERTICAL.
#define BM_EPDC_HW_EPDC_RES_VERTICAL      (0x1fff0000)  //!< Bit mask for EPDC_HW_EPDC_RES_VERTICAL.

//! @brief Get value of EPDC_HW_EPDC_RES_VERTICAL from a register value.
#define BG_EPDC_HW_EPDC_RES_VERTICAL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_RES_VERTICAL) >> BP_EPDC_HW_EPDC_RES_VERTICAL)

//! @brief Format value for bitfield EPDC_HW_EPDC_RES_VERTICAL.
#define BF_EPDC_HW_EPDC_RES_VERTICAL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_RES_VERTICAL) & BM_EPDC_HW_EPDC_RES_VERTICAL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VERTICAL field to a new value.
#define BW_EPDC_HW_EPDC_RES_VERTICAL(v)   (HW_EPDC_HW_EPDC_RES_WR((HW_EPDC_HW_EPDC_RES_RD() & ~BM_EPDC_HW_EPDC_RES_VERTICAL) | BF_EPDC_HW_EPDC_RES_VERTICAL(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_FORMAT - EPDC Format Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_FORMAT - EPDC Format Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Pixel format control register. Defines formats for buffer and TFT pixels.  HW_EPDC_FORMAT:
 * 0x050  HW_EPDC_FORMAT_SET: 0x054  HW_EPDC_FORMAT_CLR: 0x058  HW_EPDC_FORMAT_TOG: 0x05C  This
 * register controls various functions throughout the digital portion of the chip.   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_format
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_format_bitfields
    {
        unsigned TFT_PIXEL_FORMAT : 2; //!< [1:0] EPDC TFT Pixel Format. This defines how many bits of the SDDO bus are required per pixel. This field must be consistent with the waveform and panel architecture.
        unsigned RESERVED0 : 6; //!< [7:2] Reserved.
        unsigned BUF_PIXEL_FORMAT : 3; //!< [10:8] EPDC Input Buffer Pixel format. All update buffers are expected to have 8-bit grayscale pixels. This register defines which MSB's of those pixels are used. It must be noted that this format must match the waveform (e.g. P4N is not compatible with 3-bit waveforms)
        unsigned RESERVED1 : 5; //!< [15:11] Reserved.
        unsigned DEFAULT_TFT_PIXEL : 8; //!< [23:16] Default TFT pixel value. This value is used as the source-driver voltage value (TFT-pixel) for either partial-updates where a pixel has not changed or for any part of the screen which is not being updated during active frame scans.
        unsigned BUF_PIXEL_SCALE : 1; //!< [24] Selects method of conversion from 8-bit input
        unsigned RESERVED2 : 7; //!< [31:25] Reserved.
    } B;
} hw_epdc_hw_epdc_format_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_FORMAT register
 */
#define HW_EPDC_HW_EPDC_FORMAT_ADDR      (REGS_EPDC_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_FORMAT           (*(volatile hw_epdc_hw_epdc_format_t *) HW_EPDC_HW_EPDC_FORMAT_ADDR)
#define HW_EPDC_HW_EPDC_FORMAT_RD()      (HW_EPDC_HW_EPDC_FORMAT.U)
#define HW_EPDC_HW_EPDC_FORMAT_WR(v)     (HW_EPDC_HW_EPDC_FORMAT.U = (v))
#define HW_EPDC_HW_EPDC_FORMAT_SET(v)    (HW_EPDC_HW_EPDC_FORMAT_WR(HW_EPDC_HW_EPDC_FORMAT_RD() |  (v)))
#define HW_EPDC_HW_EPDC_FORMAT_CLR(v)    (HW_EPDC_HW_EPDC_FORMAT_WR(HW_EPDC_HW_EPDC_FORMAT_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_FORMAT_TOG(v)    (HW_EPDC_HW_EPDC_FORMAT_WR(HW_EPDC_HW_EPDC_FORMAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_FORMAT bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_FORMAT, field TFT_PIXEL_FORMAT[1:0] (RW)
 *
 * EPDC TFT Pixel Format. This defines how many bits of the SDDO bus are required per pixel. This
 * field must be consistent with the waveform and panel architecture.
 *
 * Values:
 * 2B = 0x0 - 2-bit
 * 2BV = 0x1 - 2-bit and VCOM
 * 4B = 0x2 - 4-bit
 * 4BV = 0x3 - 4-bit and VCOM
 */

#define BP_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT      (0)      //!< Bit position for EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT.
#define BM_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT      (0x00000003)  //!< Bit mask for EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT.

//! @brief Get value of EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT from a register value.
#define BG_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT) >> BP_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT)

//! @brief Format value for bitfield EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT.
#define BF_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT) & BM_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFT_PIXEL_FORMAT field to a new value.
#define BW_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT(v)   (HW_EPDC_HW_EPDC_FORMAT_WR((HW_EPDC_HW_EPDC_FORMAT_RD() & ~BM_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT) | BF_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT(v)))
#endif

#define BV_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT__2B (0x0) //!< 2-bit
#define BV_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT__2BV (0x1) //!< 2-bit and VCOM
#define BV_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT__4B (0x2) //!< 4-bit
#define BV_EPDC_HW_EPDC_FORMAT_TFT_PIXEL_FORMAT__4BV (0x3) //!< 4-bit and VCOM

/* --- Register HW_EPDC_HW_EPDC_FORMAT, field BUF_PIXEL_FORMAT[10:8] (RW)
 *
 * EPDC Input Buffer Pixel format. All update buffers are expected to have 8-bit grayscale pixels.
 * This register defines which MSB's of those pixels are used. It must be noted that this format
 * must match the waveform (e.g. P4N is not compatible with 3-bit waveforms)
 *
 * Values:
 * P2N = 0x2 - 2-bit pixel
 * P3N = 0x3 - 3-bit pixel
 * P4N = 0x4 - 4-bit pixel
 * P5N = 0x5 - 5-bit pixel
 */

#define BP_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT      (8)      //!< Bit position for EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT.
#define BM_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT      (0x00000700)  //!< Bit mask for EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT.

//! @brief Get value of EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT from a register value.
#define BG_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT) >> BP_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT)

//! @brief Format value for bitfield EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT.
#define BF_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT) & BM_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF_PIXEL_FORMAT field to a new value.
#define BW_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT(v)   (HW_EPDC_HW_EPDC_FORMAT_WR((HW_EPDC_HW_EPDC_FORMAT_RD() & ~BM_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT) | BF_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT(v)))
#endif

#define BV_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT__P2N (0x2) //!< 2-bit pixel
#define BV_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT__P3N (0x3) //!< 3-bit pixel
#define BV_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT__P4N (0x4) //!< 4-bit pixel
#define BV_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_FORMAT__P5N (0x5) //!< 5-bit pixel

/* --- Register HW_EPDC_HW_EPDC_FORMAT, field DEFAULT_TFT_PIXEL[23:16] (RW)
 *
 * Default TFT pixel value. This value is used as the source-driver voltage value (TFT-pixel) for
 * either partial-updates where a pixel has not changed or for any part of the screen which is not
 * being updated during active frame scans.
 */

#define BP_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL      (16)      //!< Bit position for EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL.
#define BM_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL      (0x00ff0000)  //!< Bit mask for EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL.

//! @brief Get value of EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL from a register value.
#define BG_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL) >> BP_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL.
#define BF_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL) & BM_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DEFAULT_TFT_PIXEL field to a new value.
#define BW_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL(v)   (HW_EPDC_HW_EPDC_FORMAT_WR((HW_EPDC_HW_EPDC_FORMAT_RD() & ~BM_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL) | BF_EPDC_HW_EPDC_FORMAT_DEFAULT_TFT_PIXEL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_FORMAT, field BUF_PIXEL_SCALE[24] (RW)
 *
 * Selects method of conversion from 8-bit input
 *
 * Values:
 * TRUNCATE = 0x0 - Use Truncate method (LSB)
 * ROUND = 0x1 - Use rounding method (with saturation)
 */

#define BP_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE      (24)      //!< Bit position for EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE.
#define BM_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE      (0x01000000)  //!< Bit mask for EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE.

//! @brief Get value of EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE from a register value.
#define BG_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE) >> BP_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE)

//! @brief Format value for bitfield EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE.
#define BF_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE) & BM_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF_PIXEL_SCALE field to a new value.
#define BW_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE(v)   (HW_EPDC_HW_EPDC_FORMAT_WR((HW_EPDC_HW_EPDC_FORMAT_RD() & ~BM_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE) | BF_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE(v)))
#endif

#define BV_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE__TRUNCATE (0x0) //!< Use Truncate method (LSB)
#define BV_EPDC_HW_EPDC_FORMAT_BUF_PIXEL_SCALE__ROUND (0x1) //!< Use rounding method (with saturation)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_FIFOCTRL - EPDC FIFO control register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_FIFOCTRL - EPDC FIFO control register (RW)
 *
 * Reset value: 0x00800000
 *
 * Allows for programmability of pixel FIFO watermarks used in conjunction with system arbitration
 * hardware  HW_EPDC_FIFOCTRL: 0x0A0  HW_EPDC_FIFOCTRL_SET: 0x0A4  HW_EPDC_FIFOCTRL_CLR: 0x0A8
 * HW_EPDC_FIFOCTRL_TOG: 0x0AC  This register houses FIFO control bits   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_fifoctrl
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_fifoctrl_bitfields
    {
        unsigned FIFO_L_LEVEL : 8; //!< [7:0] Lower level value of FIFO watermark. When the pixel FIFO reaches this level or below, the priority elevation request is asserted.
        unsigned FIFO_H_LEVEL : 8; //!< [15:8] Upper level value of FIFO watermark. Must be greater than FIFO_L_LEVEL. When the pixel FIFO reaches this level or above, the priority elevation request is negated
        unsigned FIFO_INIT_LEVEL : 8; //!< [23:16] This register sets the watermark for the pixel-fifo.
        unsigned RESERVED0 : 7; //!< [30:24] Reserved.
        unsigned ENABLE_PRIORITY : 1; //!< [31] Enable watermark-based priority elevation mechanism. 1=Enabled, 0=Disabled. (Only applies to FIFO_H_LEVEL and FIFO_L_LEVEL)
    } B;
} hw_epdc_hw_epdc_fifoctrl_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_FIFOCTRL register
 */
#define HW_EPDC_HW_EPDC_FIFOCTRL_ADDR      (REGS_EPDC_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_FIFOCTRL           (*(volatile hw_epdc_hw_epdc_fifoctrl_t *) HW_EPDC_HW_EPDC_FIFOCTRL_ADDR)
#define HW_EPDC_HW_EPDC_FIFOCTRL_RD()      (HW_EPDC_HW_EPDC_FIFOCTRL.U)
#define HW_EPDC_HW_EPDC_FIFOCTRL_WR(v)     (HW_EPDC_HW_EPDC_FIFOCTRL.U = (v))
#define HW_EPDC_HW_EPDC_FIFOCTRL_SET(v)    (HW_EPDC_HW_EPDC_FIFOCTRL_WR(HW_EPDC_HW_EPDC_FIFOCTRL_RD() |  (v)))
#define HW_EPDC_HW_EPDC_FIFOCTRL_CLR(v)    (HW_EPDC_HW_EPDC_FIFOCTRL_WR(HW_EPDC_HW_EPDC_FIFOCTRL_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_FIFOCTRL_TOG(v)    (HW_EPDC_HW_EPDC_FIFOCTRL_WR(HW_EPDC_HW_EPDC_FIFOCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_FIFOCTRL bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_FIFOCTRL, field FIFO_L_LEVEL[7:0] (RW)
 *
 * Lower level value of FIFO watermark. When the pixel FIFO reaches this level or below, the
 * priority elevation request is asserted.
 */

#define BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL      (0)      //!< Bit position for EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL.
#define BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL      (0x000000ff)  //!< Bit mask for EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL.

//! @brief Get value of EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL from a register value.
#define BG_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL) >> BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL.
#define BF_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL) & BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_L_LEVEL field to a new value.
#define BW_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL(v)   (HW_EPDC_HW_EPDC_FIFOCTRL_WR((HW_EPDC_HW_EPDC_FIFOCTRL_RD() & ~BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL) | BF_EPDC_HW_EPDC_FIFOCTRL_FIFO_L_LEVEL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_FIFOCTRL, field FIFO_H_LEVEL[15:8] (RW)
 *
 * Upper level value of FIFO watermark. Must be greater than FIFO_L_LEVEL. When the pixel FIFO
 * reaches this level or above, the priority elevation request is negated
 */

#define BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL      (8)      //!< Bit position for EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL.
#define BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL      (0x0000ff00)  //!< Bit mask for EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL.

//! @brief Get value of EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL from a register value.
#define BG_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL) >> BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL.
#define BF_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL) & BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_H_LEVEL field to a new value.
#define BW_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL(v)   (HW_EPDC_HW_EPDC_FIFOCTRL_WR((HW_EPDC_HW_EPDC_FIFOCTRL_RD() & ~BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL) | BF_EPDC_HW_EPDC_FIFOCTRL_FIFO_H_LEVEL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_FIFOCTRL, field FIFO_INIT_LEVEL[23:16] (RW)
 *
 * This register sets the watermark for the pixel-fifo.
 */

#define BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL      (16)      //!< Bit position for EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL.
#define BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL      (0x00ff0000)  //!< Bit mask for EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL.

//! @brief Get value of EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL from a register value.
#define BG_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL) >> BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL.
#define BF_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL) & BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_INIT_LEVEL field to a new value.
#define BW_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL(v)   (HW_EPDC_HW_EPDC_FIFOCTRL_WR((HW_EPDC_HW_EPDC_FIFOCTRL_RD() & ~BM_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL) | BF_EPDC_HW_EPDC_FIFOCTRL_FIFO_INIT_LEVEL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_FIFOCTRL, field ENABLE_PRIORITY[31] (RW)
 *
 * Enable watermark-based priority elevation mechanism. 1=Enabled, 0=Disabled. (Only applies to
 * FIFO_H_LEVEL and FIFO_L_LEVEL)
 */

#define BP_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY      (31)      //!< Bit position for EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY.
#define BM_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY      (0x80000000)  //!< Bit mask for EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY.

//! @brief Get value of EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY from a register value.
#define BG_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY) >> BP_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY)

//! @brief Format value for bitfield EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY.
#define BF_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY) & BM_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PRIORITY field to a new value.
#define BW_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY(v)   (HW_EPDC_HW_EPDC_FIFOCTRL_WR((HW_EPDC_HW_EPDC_FIFOCTRL_RD() & ~BM_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY) | BF_EPDC_HW_EPDC_FIFOCTRL_ENABLE_PRIORITY(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_UPD_ADDR - EPDC Update Region Address
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_UPD_ADDR - EPDC Update Region Address (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Update Region Address  When stride feature not enabled(HW_EPDC_UPD_STRIDE==0), it must be
 * aligned to 64-bit boundary, this is default behavior to keep compatible like before; When stride
 * feature is enabled(HW_EPDC_UPD_STRIDE!=0), it can start from any byte address, no alignment
 * requirement, but still recomended be aligned get best bus performance.   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_upd_addr
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_upd_addr_bitfields
    {
        unsigned ADDR : 32; //!< [31:0] Address for incoming region update. This address points to update region which will be processed into the working buffer.
    } B;
} hw_epdc_hw_epdc_upd_addr_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_UPD_ADDR register
 */
#define HW_EPDC_HW_EPDC_UPD_ADDR_ADDR      (REGS_EPDC_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_UPD_ADDR           (*(volatile hw_epdc_hw_epdc_upd_addr_t *) HW_EPDC_HW_EPDC_UPD_ADDR_ADDR)
#define HW_EPDC_HW_EPDC_UPD_ADDR_RD()      (HW_EPDC_HW_EPDC_UPD_ADDR.U)
#define HW_EPDC_HW_EPDC_UPD_ADDR_WR(v)     (HW_EPDC_HW_EPDC_UPD_ADDR.U = (v))
#define HW_EPDC_HW_EPDC_UPD_ADDR_SET(v)    (HW_EPDC_HW_EPDC_UPD_ADDR_WR(HW_EPDC_HW_EPDC_UPD_ADDR_RD() |  (v)))
#define HW_EPDC_HW_EPDC_UPD_ADDR_CLR(v)    (HW_EPDC_HW_EPDC_UPD_ADDR_WR(HW_EPDC_HW_EPDC_UPD_ADDR_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_UPD_ADDR_TOG(v)    (HW_EPDC_HW_EPDC_UPD_ADDR_WR(HW_EPDC_HW_EPDC_UPD_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_UPD_ADDR bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_UPD_ADDR, field ADDR[31:0] (RW)
 *
 * Address for incoming region update. This address points to update region which will be processed
 * into the working buffer.
 */

#define BP_EPDC_HW_EPDC_UPD_ADDR_ADDR      (0)      //!< Bit position for EPDC_HW_EPDC_UPD_ADDR_ADDR.
#define BM_EPDC_HW_EPDC_UPD_ADDR_ADDR      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_UPD_ADDR_ADDR.

//! @brief Get value of EPDC_HW_EPDC_UPD_ADDR_ADDR from a register value.
#define BG_EPDC_HW_EPDC_UPD_ADDR_ADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_ADDR_ADDR) >> BP_EPDC_HW_EPDC_UPD_ADDR_ADDR)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_ADDR_ADDR.
#define BF_EPDC_HW_EPDC_UPD_ADDR_ADDR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_ADDR_ADDR) & BM_EPDC_HW_EPDC_UPD_ADDR_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPDC_HW_EPDC_UPD_ADDR_ADDR(v)   (HW_EPDC_HW_EPDC_UPD_ADDR_WR((HW_EPDC_HW_EPDC_UPD_ADDR_RD() & ~BM_EPDC_HW_EPDC_UPD_ADDR_ADDR) | BF_EPDC_HW_EPDC_UPD_ADDR_ADDR(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_UPD_STRIDE - EPDC Update Region Stride
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_UPD_STRIDE - EPDC Update Region Stride (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Update Region Stride  When UPD_STRIDE==0 (stride feature disabled), UPD buffer line must
 * start from 64-bit boundary and end on 64-bit boundary(padding if not). When UPD_STRIDE!=0 (stride
 * feature enabled), UPD buffer line can start or end on any byte address, UPD_WIDTH should be set
 * to real line bytes count as normal, while UPD_STRIDE set to byte distance between two lines'
 * start.   EXAMPLE   see details on stride feature introduction
 */
typedef union _hw_epdc_hw_epdc_upd_stride
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_upd_stride_bitfields
    {
        unsigned STRIDE : 32; //!< [31:0] line stride for incoming region update
    } B;
} hw_epdc_hw_epdc_upd_stride_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_UPD_STRIDE register
 */
#define HW_EPDC_HW_EPDC_UPD_STRIDE_ADDR      (REGS_EPDC_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_UPD_STRIDE           (*(volatile hw_epdc_hw_epdc_upd_stride_t *) HW_EPDC_HW_EPDC_UPD_STRIDE_ADDR)
#define HW_EPDC_HW_EPDC_UPD_STRIDE_RD()      (HW_EPDC_HW_EPDC_UPD_STRIDE.U)
#define HW_EPDC_HW_EPDC_UPD_STRIDE_WR(v)     (HW_EPDC_HW_EPDC_UPD_STRIDE.U = (v))
#define HW_EPDC_HW_EPDC_UPD_STRIDE_SET(v)    (HW_EPDC_HW_EPDC_UPD_STRIDE_WR(HW_EPDC_HW_EPDC_UPD_STRIDE_RD() |  (v)))
#define HW_EPDC_HW_EPDC_UPD_STRIDE_CLR(v)    (HW_EPDC_HW_EPDC_UPD_STRIDE_WR(HW_EPDC_HW_EPDC_UPD_STRIDE_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_UPD_STRIDE_TOG(v)    (HW_EPDC_HW_EPDC_UPD_STRIDE_WR(HW_EPDC_HW_EPDC_UPD_STRIDE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_UPD_STRIDE bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_UPD_STRIDE, field STRIDE[31:0] (RW)
 *
 * line stride for incoming region update
 */

#define BP_EPDC_HW_EPDC_UPD_STRIDE_STRIDE      (0)      //!< Bit position for EPDC_HW_EPDC_UPD_STRIDE_STRIDE.
#define BM_EPDC_HW_EPDC_UPD_STRIDE_STRIDE      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_UPD_STRIDE_STRIDE.

//! @brief Get value of EPDC_HW_EPDC_UPD_STRIDE_STRIDE from a register value.
#define BG_EPDC_HW_EPDC_UPD_STRIDE_STRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_STRIDE_STRIDE) >> BP_EPDC_HW_EPDC_UPD_STRIDE_STRIDE)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_STRIDE_STRIDE.
#define BF_EPDC_HW_EPDC_UPD_STRIDE_STRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_STRIDE_STRIDE) & BM_EPDC_HW_EPDC_UPD_STRIDE_STRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STRIDE field to a new value.
#define BW_EPDC_HW_EPDC_UPD_STRIDE_STRIDE(v)   (HW_EPDC_HW_EPDC_UPD_STRIDE_WR((HW_EPDC_HW_EPDC_UPD_STRIDE_RD() & ~BM_EPDC_HW_EPDC_UPD_STRIDE_STRIDE) | BF_EPDC_HW_EPDC_UPD_STRIDE_STRIDE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_UPD_CORD - EPDC Update Command Co-ordinate
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_UPD_CORD - EPDC Update Command Co-ordinate (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Update Command Co-ordinate  N/A   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_upd_cord
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_upd_cord_bitfields
    {
        unsigned XCORD : 13; //!< [12:0] X co-ordinate for incoming region update
        unsigned RESERVED0 : 3; //!< [15:13] Reserved.
        unsigned YCORD : 13; //!< [28:16] Y co-ordinate for incoming region update
        unsigned RESERVED1 : 3; //!< [31:29] Reserved.
    } B;
} hw_epdc_hw_epdc_upd_cord_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_UPD_CORD register
 */
#define HW_EPDC_HW_EPDC_UPD_CORD_ADDR      (REGS_EPDC_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_UPD_CORD           (*(volatile hw_epdc_hw_epdc_upd_cord_t *) HW_EPDC_HW_EPDC_UPD_CORD_ADDR)
#define HW_EPDC_HW_EPDC_UPD_CORD_RD()      (HW_EPDC_HW_EPDC_UPD_CORD.U)
#define HW_EPDC_HW_EPDC_UPD_CORD_WR(v)     (HW_EPDC_HW_EPDC_UPD_CORD.U = (v))
#define HW_EPDC_HW_EPDC_UPD_CORD_SET(v)    (HW_EPDC_HW_EPDC_UPD_CORD_WR(HW_EPDC_HW_EPDC_UPD_CORD_RD() |  (v)))
#define HW_EPDC_HW_EPDC_UPD_CORD_CLR(v)    (HW_EPDC_HW_EPDC_UPD_CORD_WR(HW_EPDC_HW_EPDC_UPD_CORD_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_UPD_CORD_TOG(v)    (HW_EPDC_HW_EPDC_UPD_CORD_WR(HW_EPDC_HW_EPDC_UPD_CORD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_UPD_CORD bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_UPD_CORD, field XCORD[12:0] (RW)
 *
 * X co-ordinate for incoming region update
 */

#define BP_EPDC_HW_EPDC_UPD_CORD_XCORD      (0)      //!< Bit position for EPDC_HW_EPDC_UPD_CORD_XCORD.
#define BM_EPDC_HW_EPDC_UPD_CORD_XCORD      (0x00001fff)  //!< Bit mask for EPDC_HW_EPDC_UPD_CORD_XCORD.

//! @brief Get value of EPDC_HW_EPDC_UPD_CORD_XCORD from a register value.
#define BG_EPDC_HW_EPDC_UPD_CORD_XCORD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CORD_XCORD) >> BP_EPDC_HW_EPDC_UPD_CORD_XCORD)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CORD_XCORD.
#define BF_EPDC_HW_EPDC_UPD_CORD_XCORD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CORD_XCORD) & BM_EPDC_HW_EPDC_UPD_CORD_XCORD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the XCORD field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CORD_XCORD(v)   (HW_EPDC_HW_EPDC_UPD_CORD_WR((HW_EPDC_HW_EPDC_UPD_CORD_RD() & ~BM_EPDC_HW_EPDC_UPD_CORD_XCORD) | BF_EPDC_HW_EPDC_UPD_CORD_XCORD(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_CORD, field YCORD[28:16] (RW)
 *
 * Y co-ordinate for incoming region update
 */

#define BP_EPDC_HW_EPDC_UPD_CORD_YCORD      (16)      //!< Bit position for EPDC_HW_EPDC_UPD_CORD_YCORD.
#define BM_EPDC_HW_EPDC_UPD_CORD_YCORD      (0x1fff0000)  //!< Bit mask for EPDC_HW_EPDC_UPD_CORD_YCORD.

//! @brief Get value of EPDC_HW_EPDC_UPD_CORD_YCORD from a register value.
#define BG_EPDC_HW_EPDC_UPD_CORD_YCORD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CORD_YCORD) >> BP_EPDC_HW_EPDC_UPD_CORD_YCORD)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CORD_YCORD.
#define BF_EPDC_HW_EPDC_UPD_CORD_YCORD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CORD_YCORD) & BM_EPDC_HW_EPDC_UPD_CORD_YCORD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the YCORD field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CORD_YCORD(v)   (HW_EPDC_HW_EPDC_UPD_CORD_WR((HW_EPDC_HW_EPDC_UPD_CORD_RD() & ~BM_EPDC_HW_EPDC_UPD_CORD_YCORD) | BF_EPDC_HW_EPDC_UPD_CORD_YCORD(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_UPD_SIZE - EPDC Update Command Size
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_UPD_SIZE - EPDC Update Command Size (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Update Command Size  This register controls various functions throughout the digital portion
 * of the chip.   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_upd_size
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_upd_size_bitfields
    {
        unsigned WIDTH : 13; //!< [12:0] Width (in pixels)
        unsigned RESERVED0 : 3; //!< [15:13] Reserved.
        unsigned HEIGHT : 13; //!< [28:16] Height (in pixels)
        unsigned RESERVED1 : 3; //!< [31:29] Reserved.
    } B;
} hw_epdc_hw_epdc_upd_size_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_UPD_SIZE register
 */
#define HW_EPDC_HW_EPDC_UPD_SIZE_ADDR      (REGS_EPDC_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_UPD_SIZE           (*(volatile hw_epdc_hw_epdc_upd_size_t *) HW_EPDC_HW_EPDC_UPD_SIZE_ADDR)
#define HW_EPDC_HW_EPDC_UPD_SIZE_RD()      (HW_EPDC_HW_EPDC_UPD_SIZE.U)
#define HW_EPDC_HW_EPDC_UPD_SIZE_WR(v)     (HW_EPDC_HW_EPDC_UPD_SIZE.U = (v))
#define HW_EPDC_HW_EPDC_UPD_SIZE_SET(v)    (HW_EPDC_HW_EPDC_UPD_SIZE_WR(HW_EPDC_HW_EPDC_UPD_SIZE_RD() |  (v)))
#define HW_EPDC_HW_EPDC_UPD_SIZE_CLR(v)    (HW_EPDC_HW_EPDC_UPD_SIZE_WR(HW_EPDC_HW_EPDC_UPD_SIZE_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_UPD_SIZE_TOG(v)    (HW_EPDC_HW_EPDC_UPD_SIZE_WR(HW_EPDC_HW_EPDC_UPD_SIZE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_UPD_SIZE bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_UPD_SIZE, field WIDTH[12:0] (RW)
 *
 * Width (in pixels)
 */

#define BP_EPDC_HW_EPDC_UPD_SIZE_WIDTH      (0)      //!< Bit position for EPDC_HW_EPDC_UPD_SIZE_WIDTH.
#define BM_EPDC_HW_EPDC_UPD_SIZE_WIDTH      (0x00001fff)  //!< Bit mask for EPDC_HW_EPDC_UPD_SIZE_WIDTH.

//! @brief Get value of EPDC_HW_EPDC_UPD_SIZE_WIDTH from a register value.
#define BG_EPDC_HW_EPDC_UPD_SIZE_WIDTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_SIZE_WIDTH) >> BP_EPDC_HW_EPDC_UPD_SIZE_WIDTH)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_SIZE_WIDTH.
#define BF_EPDC_HW_EPDC_UPD_SIZE_WIDTH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_SIZE_WIDTH) & BM_EPDC_HW_EPDC_UPD_SIZE_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WIDTH field to a new value.
#define BW_EPDC_HW_EPDC_UPD_SIZE_WIDTH(v)   (HW_EPDC_HW_EPDC_UPD_SIZE_WR((HW_EPDC_HW_EPDC_UPD_SIZE_RD() & ~BM_EPDC_HW_EPDC_UPD_SIZE_WIDTH) | BF_EPDC_HW_EPDC_UPD_SIZE_WIDTH(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_SIZE, field HEIGHT[28:16] (RW)
 *
 * Height (in pixels)
 */

#define BP_EPDC_HW_EPDC_UPD_SIZE_HEIGHT      (16)      //!< Bit position for EPDC_HW_EPDC_UPD_SIZE_HEIGHT.
#define BM_EPDC_HW_EPDC_UPD_SIZE_HEIGHT      (0x1fff0000)  //!< Bit mask for EPDC_HW_EPDC_UPD_SIZE_HEIGHT.

//! @brief Get value of EPDC_HW_EPDC_UPD_SIZE_HEIGHT from a register value.
#define BG_EPDC_HW_EPDC_UPD_SIZE_HEIGHT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_SIZE_HEIGHT) >> BP_EPDC_HW_EPDC_UPD_SIZE_HEIGHT)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_SIZE_HEIGHT.
#define BF_EPDC_HW_EPDC_UPD_SIZE_HEIGHT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_SIZE_HEIGHT) & BM_EPDC_HW_EPDC_UPD_SIZE_HEIGHT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HEIGHT field to a new value.
#define BW_EPDC_HW_EPDC_UPD_SIZE_HEIGHT(v)   (HW_EPDC_HW_EPDC_UPD_SIZE_WR((HW_EPDC_HW_EPDC_UPD_SIZE_RD() & ~BM_EPDC_HW_EPDC_UPD_SIZE_HEIGHT) | BF_EPDC_HW_EPDC_UPD_SIZE_HEIGHT(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_UPD_CTRL - EPDC Update Command Control
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_UPD_CTRL - EPDC Update Command Control (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Update Command Control. Writing to this registers triggers and update request operation.
 * HW_EPDC_UPD_CTRL: 0x160  HW_EPDC_UPD_CTRL_SET: 0x164  HW_EPDC_UPD_CTRL_CLR: 0x168
 * HW_EPDC_UPD_CTRL_TOG: 0x16C  Update control register   EXAMPLE
 * HW_DIGCTL_CTRL_CLR(BM_DIGCTL_CTRL_USB_CLKGATE); // enable USB clock
 */
typedef union _hw_epdc_hw_epdc_upd_ctrl
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_upd_ctrl_bitfields
    {
        unsigned UPDATE_MODE : 1; //!< [0] Update Mode
        unsigned DRY_RUN : 1; //!< [1] Collision Detection. WB won't be updated in this mode, and lut_sel will be ignored, so actually you don't need to wait for LUT available to use this feature
        unsigned AUTOWV : 1; //!< [2] 
        unsigned AUTOWV_PAUSE : 1; //!< [3] 
        unsigned RESERVED0 : 4; //!< [7:4] Reserved.
        unsigned WAVEFORM_MODE : 8; //!< [15:8] Waveform Mode 0-255
        unsigned LUT_SEL : 6; //!< [21:16] LUT select 0-63
        unsigned RESERVED1 : 9; //!< [30:22] Reserved.
        unsigned USE_FIXED : 1; //!< [31] Use fixed pixel values (requires programming of HW_EPDC_UPD_FIXED)
    } B;
} hw_epdc_hw_epdc_upd_ctrl_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_UPD_CTRL register
 */
#define HW_EPDC_HW_EPDC_UPD_CTRL_ADDR      (REGS_EPDC_BASE + 0x160)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_UPD_CTRL           (*(volatile hw_epdc_hw_epdc_upd_ctrl_t *) HW_EPDC_HW_EPDC_UPD_CTRL_ADDR)
#define HW_EPDC_HW_EPDC_UPD_CTRL_RD()      (HW_EPDC_HW_EPDC_UPD_CTRL.U)
#define HW_EPDC_HW_EPDC_UPD_CTRL_WR(v)     (HW_EPDC_HW_EPDC_UPD_CTRL.U = (v))
#define HW_EPDC_HW_EPDC_UPD_CTRL_SET(v)    (HW_EPDC_HW_EPDC_UPD_CTRL_WR(HW_EPDC_HW_EPDC_UPD_CTRL_RD() |  (v)))
#define HW_EPDC_HW_EPDC_UPD_CTRL_CLR(v)    (HW_EPDC_HW_EPDC_UPD_CTRL_WR(HW_EPDC_HW_EPDC_UPD_CTRL_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_UPD_CTRL_TOG(v)    (HW_EPDC_HW_EPDC_UPD_CTRL_WR(HW_EPDC_HW_EPDC_UPD_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_UPD_CTRL bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_UPD_CTRL, field UPDATE_MODE[0] (RW)
 *
 * Update Mode
 *
 * Values:
 * PARTIAL = 0x0 - Partial Update : only process changed pixels in region
 * FULL = 0x1 - Full Update : process all pixels in region
 */

#define BP_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE      (0)      //!< Bit position for EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE.
#define BM_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE.

//! @brief Get value of EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE from a register value.
#define BG_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE) >> BP_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE.
#define BF_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE) & BM_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPDATE_MODE field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE(v)   (HW_EPDC_HW_EPDC_UPD_CTRL_WR((HW_EPDC_HW_EPDC_UPD_CTRL_RD() & ~BM_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE) | BF_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE(v)))
#endif

#define BV_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE__PARTIAL (0x0) //!< Partial Update : only process changed pixels in region
#define BV_EPDC_HW_EPDC_UPD_CTRL_UPDATE_MODE__FULL (0x1) //!< Full Update : process all pixels in region

/* --- Register HW_EPDC_HW_EPDC_UPD_CTRL, field DRY_RUN[1] (RW)
 *
 * Collision Detection. WB won't be updated in this mode, and lut_sel will be ignored, so actually
 * you don't need to wait for LUT available to use this feature
 */

#define BP_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN      (1)      //!< Bit position for EPDC_HW_EPDC_UPD_CTRL_DRY_RUN.
#define BM_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_UPD_CTRL_DRY_RUN.

//! @brief Get value of EPDC_HW_EPDC_UPD_CTRL_DRY_RUN from a register value.
#define BG_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN) >> BP_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CTRL_DRY_RUN.
#define BF_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN) & BM_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DRY_RUN field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN(v)   (HW_EPDC_HW_EPDC_UPD_CTRL_WR((HW_EPDC_HW_EPDC_UPD_CTRL_RD() & ~BM_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN) | BF_EPDC_HW_EPDC_UPD_CTRL_DRY_RUN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_CTRL, field AUTOWV[2] (RW)
 *

 */

#define BP_EPDC_HW_EPDC_UPD_CTRL_AUTOWV      (2)      //!< Bit position for EPDC_HW_EPDC_UPD_CTRL_AUTOWV.
#define BM_EPDC_HW_EPDC_UPD_CTRL_AUTOWV      (0x00000004)  //!< Bit mask for EPDC_HW_EPDC_UPD_CTRL_AUTOWV.

//! @brief Get value of EPDC_HW_EPDC_UPD_CTRL_AUTOWV from a register value.
#define BG_EPDC_HW_EPDC_UPD_CTRL_AUTOWV(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CTRL_AUTOWV) >> BP_EPDC_HW_EPDC_UPD_CTRL_AUTOWV)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CTRL_AUTOWV.
#define BF_EPDC_HW_EPDC_UPD_CTRL_AUTOWV(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CTRL_AUTOWV) & BM_EPDC_HW_EPDC_UPD_CTRL_AUTOWV)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AUTOWV field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CTRL_AUTOWV(v)   (HW_EPDC_HW_EPDC_UPD_CTRL_WR((HW_EPDC_HW_EPDC_UPD_CTRL_RD() & ~BM_EPDC_HW_EPDC_UPD_CTRL_AUTOWV) | BF_EPDC_HW_EPDC_UPD_CTRL_AUTOWV(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_CTRL, field AUTOWV_PAUSE[3] (RW)
 *

 */

#define BP_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE      (3)      //!< Bit position for EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE.
#define BM_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE      (0x00000008)  //!< Bit mask for EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE.

//! @brief Get value of EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE from a register value.
#define BG_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE) >> BP_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE.
#define BF_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE) & BM_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AUTOWV_PAUSE field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE(v)   (HW_EPDC_HW_EPDC_UPD_CTRL_WR((HW_EPDC_HW_EPDC_UPD_CTRL_RD() & ~BM_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE) | BF_EPDC_HW_EPDC_UPD_CTRL_AUTOWV_PAUSE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_CTRL, field WAVEFORM_MODE[15:8] (RW)
 *
 * Waveform Mode 0-255
 */

#define BP_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE      (8)      //!< Bit position for EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE.
#define BM_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE      (0x0000ff00)  //!< Bit mask for EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE.

//! @brief Get value of EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE from a register value.
#define BG_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE) >> BP_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE.
#define BF_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE) & BM_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAVEFORM_MODE field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE(v)   (HW_EPDC_HW_EPDC_UPD_CTRL_WR((HW_EPDC_HW_EPDC_UPD_CTRL_RD() & ~BM_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE) | BF_EPDC_HW_EPDC_UPD_CTRL_WAVEFORM_MODE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_CTRL, field LUT_SEL[21:16] (RW)
 *
 * LUT select 0-63
 */

#define BP_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL      (16)      //!< Bit position for EPDC_HW_EPDC_UPD_CTRL_LUT_SEL.
#define BM_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL      (0x003f0000)  //!< Bit mask for EPDC_HW_EPDC_UPD_CTRL_LUT_SEL.

//! @brief Get value of EPDC_HW_EPDC_UPD_CTRL_LUT_SEL from a register value.
#define BG_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL) >> BP_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CTRL_LUT_SEL.
#define BF_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL) & BM_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL(v)   (HW_EPDC_HW_EPDC_UPD_CTRL_WR((HW_EPDC_HW_EPDC_UPD_CTRL_RD() & ~BM_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL) | BF_EPDC_HW_EPDC_UPD_CTRL_LUT_SEL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_CTRL, field USE_FIXED[31] (RW)
 *
 * Use fixed pixel values (requires programming of HW_EPDC_UPD_FIXED)
 */

#define BP_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED      (31)      //!< Bit position for EPDC_HW_EPDC_UPD_CTRL_USE_FIXED.
#define BM_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED      (0x80000000)  //!< Bit mask for EPDC_HW_EPDC_UPD_CTRL_USE_FIXED.

//! @brief Get value of EPDC_HW_EPDC_UPD_CTRL_USE_FIXED from a register value.
#define BG_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED) >> BP_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_CTRL_USE_FIXED.
#define BF_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED) & BM_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the USE_FIXED field to a new value.
#define BW_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED(v)   (HW_EPDC_HW_EPDC_UPD_CTRL_WR((HW_EPDC_HW_EPDC_UPD_CTRL_RD() & ~BM_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED) | BF_EPDC_HW_EPDC_UPD_CTRL_USE_FIXED(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_UPD_FIXED - EPDC Update Fixed Pixel Control
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_UPD_FIXED - EPDC Update Fixed Pixel Control (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Update Control register for fixed-pixel updates (enabled via HW_EPDC_UPD_CTRL[USE_FIXED])
 * HW_EPDC_UPD_FIXED: 0x180  HW_EPDC_UPD_FIXED_SET: 0x184  HW_EPDC_UPD_FIXED_CLR: 0x188
 * HW_EPDC_UPD_FIXED_TOG: 0x18C  Update control register for fixed-pixel update values   EXAMPLE
 * TBD.
 */
typedef union _hw_epdc_hw_epdc_upd_fixed
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_upd_fixed_bitfields
    {
        unsigned FIXCP : 8; //!< [7:0] CP value if fixecp_en is set to 1. Data in Y8 format.
        unsigned FIXNP : 8; //!< [15:8] NP value if fixenp_en is set to 1. Data in Y8 format.
        unsigned RESERVED0 : 14; //!< [29:16] Reserved.
        unsigned FIXCP_EN : 1; //!< [30] If set to 1, current updated region has the CP value defined by FIXCP
        unsigned FIXNP_EN : 1; //!< [31] If set to 1, current updated region has the NP value defined by FIXNP
    } B;
} hw_epdc_hw_epdc_upd_fixed_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_UPD_FIXED register
 */
#define HW_EPDC_HW_EPDC_UPD_FIXED_ADDR      (REGS_EPDC_BASE + 0x180)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_UPD_FIXED           (*(volatile hw_epdc_hw_epdc_upd_fixed_t *) HW_EPDC_HW_EPDC_UPD_FIXED_ADDR)
#define HW_EPDC_HW_EPDC_UPD_FIXED_RD()      (HW_EPDC_HW_EPDC_UPD_FIXED.U)
#define HW_EPDC_HW_EPDC_UPD_FIXED_WR(v)     (HW_EPDC_HW_EPDC_UPD_FIXED.U = (v))
#define HW_EPDC_HW_EPDC_UPD_FIXED_SET(v)    (HW_EPDC_HW_EPDC_UPD_FIXED_WR(HW_EPDC_HW_EPDC_UPD_FIXED_RD() |  (v)))
#define HW_EPDC_HW_EPDC_UPD_FIXED_CLR(v)    (HW_EPDC_HW_EPDC_UPD_FIXED_WR(HW_EPDC_HW_EPDC_UPD_FIXED_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_UPD_FIXED_TOG(v)    (HW_EPDC_HW_EPDC_UPD_FIXED_WR(HW_EPDC_HW_EPDC_UPD_FIXED_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_UPD_FIXED bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_UPD_FIXED, field FIXCP[7:0] (RW)
 *
 * CP value if fixecp_en is set to 1. Data in Y8 format.
 */

#define BP_EPDC_HW_EPDC_UPD_FIXED_FIXCP      (0)      //!< Bit position for EPDC_HW_EPDC_UPD_FIXED_FIXCP.
#define BM_EPDC_HW_EPDC_UPD_FIXED_FIXCP      (0x000000ff)  //!< Bit mask for EPDC_HW_EPDC_UPD_FIXED_FIXCP.

//! @brief Get value of EPDC_HW_EPDC_UPD_FIXED_FIXCP from a register value.
#define BG_EPDC_HW_EPDC_UPD_FIXED_FIXCP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_FIXED_FIXCP) >> BP_EPDC_HW_EPDC_UPD_FIXED_FIXCP)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_FIXED_FIXCP.
#define BF_EPDC_HW_EPDC_UPD_FIXED_FIXCP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_FIXED_FIXCP) & BM_EPDC_HW_EPDC_UPD_FIXED_FIXCP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIXCP field to a new value.
#define BW_EPDC_HW_EPDC_UPD_FIXED_FIXCP(v)   (HW_EPDC_HW_EPDC_UPD_FIXED_WR((HW_EPDC_HW_EPDC_UPD_FIXED_RD() & ~BM_EPDC_HW_EPDC_UPD_FIXED_FIXCP) | BF_EPDC_HW_EPDC_UPD_FIXED_FIXCP(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_FIXED, field FIXNP[15:8] (RW)
 *
 * NP value if fixenp_en is set to 1. Data in Y8 format.
 */

#define BP_EPDC_HW_EPDC_UPD_FIXED_FIXNP      (8)      //!< Bit position for EPDC_HW_EPDC_UPD_FIXED_FIXNP.
#define BM_EPDC_HW_EPDC_UPD_FIXED_FIXNP      (0x0000ff00)  //!< Bit mask for EPDC_HW_EPDC_UPD_FIXED_FIXNP.

//! @brief Get value of EPDC_HW_EPDC_UPD_FIXED_FIXNP from a register value.
#define BG_EPDC_HW_EPDC_UPD_FIXED_FIXNP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_FIXED_FIXNP) >> BP_EPDC_HW_EPDC_UPD_FIXED_FIXNP)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_FIXED_FIXNP.
#define BF_EPDC_HW_EPDC_UPD_FIXED_FIXNP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_FIXED_FIXNP) & BM_EPDC_HW_EPDC_UPD_FIXED_FIXNP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIXNP field to a new value.
#define BW_EPDC_HW_EPDC_UPD_FIXED_FIXNP(v)   (HW_EPDC_HW_EPDC_UPD_FIXED_WR((HW_EPDC_HW_EPDC_UPD_FIXED_RD() & ~BM_EPDC_HW_EPDC_UPD_FIXED_FIXNP) | BF_EPDC_HW_EPDC_UPD_FIXED_FIXNP(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_FIXED, field FIXCP_EN[30] (RW)
 *
 * If set to 1, current updated region has the CP value defined by FIXCP
 */

#define BP_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN      (30)      //!< Bit position for EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN.
#define BM_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN      (0x40000000)  //!< Bit mask for EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN.

//! @brief Get value of EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN from a register value.
#define BG_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN) >> BP_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN.
#define BF_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN) & BM_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIXCP_EN field to a new value.
#define BW_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN(v)   (HW_EPDC_HW_EPDC_UPD_FIXED_WR((HW_EPDC_HW_EPDC_UPD_FIXED_RD() & ~BM_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN) | BF_EPDC_HW_EPDC_UPD_FIXED_FIXCP_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_UPD_FIXED, field FIXNP_EN[31] (RW)
 *
 * If set to 1, current updated region has the NP value defined by FIXNP
 */

#define BP_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN      (31)      //!< Bit position for EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN.
#define BM_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN      (0x80000000)  //!< Bit mask for EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN.

//! @brief Get value of EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN from a register value.
#define BG_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN) >> BP_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN.
#define BF_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN) & BM_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIXNP_EN field to a new value.
#define BW_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN(v)   (HW_EPDC_HW_EPDC_UPD_FIXED_WR((HW_EPDC_HW_EPDC_UPD_FIXED_RD() & ~BM_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN) | BF_EPDC_HW_EPDC_UPD_FIXED_FIXNP_EN(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TEMP - EPDC Temperature Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TEMP - EPDC Temperature Register (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Temperature Compensation Register  N/A   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_temp
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_temp_bitfields
    {
        unsigned TEMPERATURE : 32; //!< [31:0] Temperature Value. This value is simply an index (not a temperature value). The index is used by the EPDC to access the correct temperature compensated waveform.
    } B;
} hw_epdc_hw_epdc_temp_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TEMP register
 */
#define HW_EPDC_HW_EPDC_TEMP_ADDR      (REGS_EPDC_BASE + 0x1a0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TEMP           (*(volatile hw_epdc_hw_epdc_temp_t *) HW_EPDC_HW_EPDC_TEMP_ADDR)
#define HW_EPDC_HW_EPDC_TEMP_RD()      (HW_EPDC_HW_EPDC_TEMP.U)
#define HW_EPDC_HW_EPDC_TEMP_WR(v)     (HW_EPDC_HW_EPDC_TEMP.U = (v))
#define HW_EPDC_HW_EPDC_TEMP_SET(v)    (HW_EPDC_HW_EPDC_TEMP_WR(HW_EPDC_HW_EPDC_TEMP_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TEMP_CLR(v)    (HW_EPDC_HW_EPDC_TEMP_WR(HW_EPDC_HW_EPDC_TEMP_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TEMP_TOG(v)    (HW_EPDC_HW_EPDC_TEMP_WR(HW_EPDC_HW_EPDC_TEMP_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TEMP bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TEMP, field TEMPERATURE[31:0] (RW)
 *
 * Temperature Value. This value is simply an index (not a temperature value). The index is used by
 * the EPDC to access the correct temperature compensated waveform.
 */

#define BP_EPDC_HW_EPDC_TEMP_TEMPERATURE      (0)      //!< Bit position for EPDC_HW_EPDC_TEMP_TEMPERATURE.
#define BM_EPDC_HW_EPDC_TEMP_TEMPERATURE      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_TEMP_TEMPERATURE.

//! @brief Get value of EPDC_HW_EPDC_TEMP_TEMPERATURE from a register value.
#define BG_EPDC_HW_EPDC_TEMP_TEMPERATURE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TEMP_TEMPERATURE) >> BP_EPDC_HW_EPDC_TEMP_TEMPERATURE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TEMP_TEMPERATURE.
#define BF_EPDC_HW_EPDC_TEMP_TEMPERATURE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TEMP_TEMPERATURE) & BM_EPDC_HW_EPDC_TEMP_TEMPERATURE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEMPERATURE field to a new value.
#define BW_EPDC_HW_EPDC_TEMP_TEMPERATURE(v)   (HW_EPDC_HW_EPDC_TEMP_WR((HW_EPDC_HW_EPDC_TEMP_RD() & ~BM_EPDC_HW_EPDC_TEMP_TEMPERATURE) | BF_EPDC_HW_EPDC_TEMP_TEMPERATURE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_AUTOWV_LUT - Waveform Mode Lookup Table Control Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_AUTOWV_LUT - Waveform Mode Lookup Table Control Register. (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to access the waveform mode lookup table.  DATA -> AUTOWV_LUT[ADDR] :
 * Writing this reg with 'ADDR' and 'DATA' info will get 'DATA' written to AUTOWV_LUT mem indexed
 * with 'ADDR'   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_autowv_lut
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_autowv_lut_bitfields
    {
        unsigned ADDR : 8; //!< [7:0] ADDR
        unsigned RESERVED0 : 8; //!< [15:8] Reserved, always set to zero.
        unsigned DATA : 8; //!< [23:16] DATA
        unsigned RESERVED1 : 8; //!< [31:24] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_autowv_lut_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_AUTOWV_LUT register
 */
#define HW_EPDC_HW_EPDC_AUTOWV_LUT_ADDR      (REGS_EPDC_BASE + 0x1c0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_AUTOWV_LUT           (*(volatile hw_epdc_hw_epdc_autowv_lut_t *) HW_EPDC_HW_EPDC_AUTOWV_LUT_ADDR)
#define HW_EPDC_HW_EPDC_AUTOWV_LUT_RD()      (HW_EPDC_HW_EPDC_AUTOWV_LUT.U)
#define HW_EPDC_HW_EPDC_AUTOWV_LUT_WR(v)     (HW_EPDC_HW_EPDC_AUTOWV_LUT.U = (v))
#define HW_EPDC_HW_EPDC_AUTOWV_LUT_SET(v)    (HW_EPDC_HW_EPDC_AUTOWV_LUT_WR(HW_EPDC_HW_EPDC_AUTOWV_LUT_RD() |  (v)))
#define HW_EPDC_HW_EPDC_AUTOWV_LUT_CLR(v)    (HW_EPDC_HW_EPDC_AUTOWV_LUT_WR(HW_EPDC_HW_EPDC_AUTOWV_LUT_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_AUTOWV_LUT_TOG(v)    (HW_EPDC_HW_EPDC_AUTOWV_LUT_WR(HW_EPDC_HW_EPDC_AUTOWV_LUT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_AUTOWV_LUT bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_AUTOWV_LUT, field ADDR[7:0] (RW)
 *
 * ADDR
 */

#define BP_EPDC_HW_EPDC_AUTOWV_LUT_ADDR      (0)      //!< Bit position for EPDC_HW_EPDC_AUTOWV_LUT_ADDR.
#define BM_EPDC_HW_EPDC_AUTOWV_LUT_ADDR      (0x000000ff)  //!< Bit mask for EPDC_HW_EPDC_AUTOWV_LUT_ADDR.

//! @brief Get value of EPDC_HW_EPDC_AUTOWV_LUT_ADDR from a register value.
#define BG_EPDC_HW_EPDC_AUTOWV_LUT_ADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_AUTOWV_LUT_ADDR) >> BP_EPDC_HW_EPDC_AUTOWV_LUT_ADDR)

//! @brief Format value for bitfield EPDC_HW_EPDC_AUTOWV_LUT_ADDR.
#define BF_EPDC_HW_EPDC_AUTOWV_LUT_ADDR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_AUTOWV_LUT_ADDR) & BM_EPDC_HW_EPDC_AUTOWV_LUT_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPDC_HW_EPDC_AUTOWV_LUT_ADDR(v)   (HW_EPDC_HW_EPDC_AUTOWV_LUT_WR((HW_EPDC_HW_EPDC_AUTOWV_LUT_RD() & ~BM_EPDC_HW_EPDC_AUTOWV_LUT_ADDR) | BF_EPDC_HW_EPDC_AUTOWV_LUT_ADDR(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_AUTOWV_LUT, field DATA[23:16] (RW)
 *
 * DATA
 */

#define BP_EPDC_HW_EPDC_AUTOWV_LUT_DATA      (16)      //!< Bit position for EPDC_HW_EPDC_AUTOWV_LUT_DATA.
#define BM_EPDC_HW_EPDC_AUTOWV_LUT_DATA      (0x00ff0000)  //!< Bit mask for EPDC_HW_EPDC_AUTOWV_LUT_DATA.

//! @brief Get value of EPDC_HW_EPDC_AUTOWV_LUT_DATA from a register value.
#define BG_EPDC_HW_EPDC_AUTOWV_LUT_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_AUTOWV_LUT_DATA) >> BP_EPDC_HW_EPDC_AUTOWV_LUT_DATA)

//! @brief Format value for bitfield EPDC_HW_EPDC_AUTOWV_LUT_DATA.
#define BF_EPDC_HW_EPDC_AUTOWV_LUT_DATA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_AUTOWV_LUT_DATA) & BM_EPDC_HW_EPDC_AUTOWV_LUT_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_EPDC_HW_EPDC_AUTOWV_LUT_DATA(v)   (HW_EPDC_HW_EPDC_AUTOWV_LUT_WR((HW_EPDC_HW_EPDC_AUTOWV_LUT_RD() & ~BM_EPDC_HW_EPDC_AUTOWV_LUT_DATA) | BF_EPDC_HW_EPDC_AUTOWV_LUT_DATA(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_CTRL - EPDC Timing Control Engine Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_CTRL - EPDC Timing Control Engine Control Register (RW)
 *
 * Reset value: 0x00000010
 *
 * TCE general control register  HW_EPDC_TCE_CTRL: 0x200  HW_EPDC_TCE_CTRL_SET: 0x204
 * HW_EPDC_TCE_CTRL_CLR: 0x208  HW_EPDC_TCE_CTRL_TOG: 0x20C  This register houses Horizontal scan
 * timing. Note that line data length is derived from HW_EPDC_RES.   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_ctrl
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_ctrl_bitfields
    {
        unsigned PIXELS_PER_SDCLK : 2; //!< [1:0] Number of TFT pixels per SDCLK period. Note that this value forms the division of the PIXLK to generate the SDCLK such that SDCLK = PIXCLK/PIXELS_PER_SDCLK. For dual-scan mode (DUAL_SCAN=1), this applies to 8-bit half of the 16-bit SDDO. It should be noted that when DDR_MODE is enabled, both edges of the clock have to be accounted for in this value, so for example with an 8-bit SDDO, 2-bit TFT pixel, this field should be set to EIGHT (four pixels on the pos-edge and 4-pixels on the neg-edge)
        unsigned SDDO_WIDTH : 1; //!< [2] Selects either 8 or 16 bit SDDO bus format
        unsigned DUAL_SCAN : 1; //!< [3] Enables dual scan-mode. Note in this mode, SDDO_BUS_FORMAT=16BIT must be selected. and PIXELS_PER_CLK applies to each 8-bit segment of the SDDO bus.
        unsigned SCAN_DIR_0 : 1; //!< [4] Determines scan direction for each half of the TFT panel
        unsigned SCAN_DIR_1 : 1; //!< [5] Determines scan direction for each half of the TFT panel
        unsigned LVDS_MODE : 1; //!< [6] If set, the upper 8-bit of the SDDO bus are used for LVDS differential signalling. Note that this can only be used when SDDO_BUS_FORMAT is set to 16BIT, i.e. LVDS signaling is not supported with an 8-bit SDDO interface. Note that for LVDS_MODE, DDR_MODE must also be set.
        unsigned LVDS_MODE_CE : 1; //!< [7] If set (together with LVDS_MODE=1), SDCE[9:5] shall be driven as the differential inverse of SDCE[4:0]. In this mode the EPDC only supports 5 CE lines.
        unsigned DDR_MODE : 1; //!< [8] If set, SDDO data is driven on both positive and negative edges of SDCLK. Note that this mode is not supported when SDDO_BUS_FORMAT=16BIT and LVDS is not used. This must always be set when LVDS_MODE is set.
        unsigned VCOM_MODE : 1; //!< [9] This field determines the method used to drive the VCOM signal.
        unsigned VCOM_VAL : 2; //!< [11:10] When VCOM_MODE = MANUAL, this value is used to manually set the VCOM value for the VCOM[1:0] pins
        unsigned RESERVED0 : 4; //!< [15:12] Reserved.
        unsigned VSCAN_HOLDOFF : 9; //!< [24:16] This period (expressed in vertical lines), sets the portion of the vertical blanking available for new LUTs to be activated. The remainder of the blanking period is reserved for pre-filling the TCE pixel FIFOs. Increasing this value allows for multiple smaller updates to be intercepted by the current frame scan. This number should not exceed FRAME_END+FRAME_SYNC+FRAME_BEGIN. Increasing this value can improve the ability for any given update to intercept the next available frame-scan. Excessive values can result in TCE FIFO under-runs.
        unsigned RESERVED1 : 7; //!< [31:25] Reserved.
    } B;
} hw_epdc_hw_epdc_tce_ctrl_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_CTRL register
 */
#define HW_EPDC_HW_EPDC_TCE_CTRL_ADDR      (REGS_EPDC_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_CTRL           (*(volatile hw_epdc_hw_epdc_tce_ctrl_t *) HW_EPDC_HW_EPDC_TCE_CTRL_ADDR)
#define HW_EPDC_HW_EPDC_TCE_CTRL_RD()      (HW_EPDC_HW_EPDC_TCE_CTRL.U)
#define HW_EPDC_HW_EPDC_TCE_CTRL_WR(v)     (HW_EPDC_HW_EPDC_TCE_CTRL.U = (v))
#define HW_EPDC_HW_EPDC_TCE_CTRL_SET(v)    (HW_EPDC_HW_EPDC_TCE_CTRL_WR(HW_EPDC_HW_EPDC_TCE_CTRL_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_CTRL_CLR(v)    (HW_EPDC_HW_EPDC_TCE_CTRL_WR(HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_CTRL_TOG(v)    (HW_EPDC_HW_EPDC_TCE_CTRL_WR(HW_EPDC_HW_EPDC_TCE_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_CTRL bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field PIXELS_PER_SDCLK[1:0] (RW)
 *
 * Number of TFT pixels per SDCLK period. Note that this value forms the division of the PIXLK to
 * generate the SDCLK such that SDCLK = PIXCLK/PIXELS_PER_SDCLK. For dual-scan mode (DUAL_SCAN=1),
 * this applies to 8-bit half of the 16-bit SDDO. It should be noted that when DDR_MODE is enabled,
 * both edges of the clock have to be accounted for in this value, so for example with an 8-bit
 * SDDO, 2-bit TFT pixel, this field should be set to EIGHT (four pixels on the pos-edge and
 * 4-pixels on the neg-edge)
 *
 * Values:
 * RESERVED = 0x0 - Reserved
 * TWO = 0x1 - Two TFT-pixels per SDCLK
 * FOUR = 0x2 - Four TFT-pixels per SDCLK
 * EIGHT = 0x3 - Eight TFT-pixels per SDCLK
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK.
#define BM_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK      (0x00000003)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK) >> BP_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK.
#define BF_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK) & BM_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXELS_PER_SDCLK field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK) | BF_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK(v)))
#endif

#define BV_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK__RESERVED (0x0) //!< Reserved
#define BV_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK__TWO (0x1) //!< Two TFT-pixels per SDCLK
#define BV_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK__FOUR (0x2) //!< Four TFT-pixels per SDCLK
#define BV_EPDC_HW_EPDC_TCE_CTRL_PIXELS_PER_SDCLK__EIGHT (0x3) //!< Eight TFT-pixels per SDCLK

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field SDDO_WIDTH[2] (RW)
 *
 * Selects either 8 or 16 bit SDDO bus format
 *
 * Values:
 * 8BIT = 0x0 - Connect to 8-bit source driver
 * 16BIT = 0x1 - Connct to 16-bit source driver
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH      (2)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH.
#define BM_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH      (0x00000004)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH) >> BP_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH.
#define BF_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH) & BM_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDDO_WIDTH field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH) | BF_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH(v)))
#endif

#define BV_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH__8BIT (0x0) //!< Connect to 8-bit source driver
#define BV_EPDC_HW_EPDC_TCE_CTRL_SDDO_WIDTH__16BIT (0x1) //!< Connct to 16-bit source driver

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field DUAL_SCAN[3] (RW)
 *
 * Enables dual scan-mode. Note in this mode, SDDO_BUS_FORMAT=16BIT must be selected. and
 * PIXELS_PER_CLK applies to each 8-bit segment of the SDDO bus.
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN      (3)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN.
#define BM_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN      (0x00000008)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN) >> BP_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN.
#define BF_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN) & BM_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DUAL_SCAN field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN) | BF_EPDC_HW_EPDC_TCE_CTRL_DUAL_SCAN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field SCAN_DIR_0[4] (RW)
 *
 * Determines scan direction for each half of the TFT panel
 *
 * Values:
 * DOWN = 0x0 - Scan this region from top to bottom
 * UP = 0x1 - Scan this region from bottom to top
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0      (4)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0.
#define BM_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0      (0x00000010)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0 from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0) >> BP_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0.
#define BF_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0) & BM_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCAN_DIR_0 field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0) | BF_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0(v)))
#endif

#define BV_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0__DOWN (0x0) //!< Scan this region from top to bottom
#define BV_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_0__UP (0x1) //!< Scan this region from bottom to top

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field SCAN_DIR_1[5] (RW)
 *
 * Determines scan direction for each half of the TFT panel
 *
 * Values:
 * DOWN = 0x0 - Scan this region from top to bottom
 * UP = 0x1 - Scan this region from bottom to top
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1      (5)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1.
#define BM_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1      (0x00000020)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1 from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1) >> BP_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1.
#define BF_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1) & BM_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCAN_DIR_1 field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1) | BF_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1(v)))
#endif

#define BV_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1__DOWN (0x0) //!< Scan this region from top to bottom
#define BV_EPDC_HW_EPDC_TCE_CTRL_SCAN_DIR_1__UP (0x1) //!< Scan this region from bottom to top

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field LVDS_MODE[6] (RW)
 *
 * If set, the upper 8-bit of the SDDO bus are used for LVDS differential signalling. Note that this
 * can only be used when SDDO_BUS_FORMAT is set to 16BIT, i.e. LVDS signaling is not supported with
 * an 8-bit SDDO interface. Note that for LVDS_MODE, DDR_MODE must also be set.
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE      (6)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE.
#define BM_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE      (0x00000040)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE) >> BP_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE.
#define BF_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE) & BM_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_MODE field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE) | BF_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field LVDS_MODE_CE[7] (RW)
 *
 * If set (together with LVDS_MODE=1), SDCE[9:5] shall be driven as the differential inverse of
 * SDCE[4:0]. In this mode the EPDC only supports 5 CE lines.
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE      (7)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE.
#define BM_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE      (0x00000080)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE) >> BP_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE.
#define BF_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE) & BM_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_MODE_CE field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE) | BF_EPDC_HW_EPDC_TCE_CTRL_LVDS_MODE_CE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field DDR_MODE[8] (RW)
 *
 * If set, SDDO data is driven on both positive and negative edges of SDCLK. Note that this mode is
 * not supported when SDDO_BUS_FORMAT=16BIT and LVDS is not used. This must always be set when
 * LVDS_MODE is set.
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE      (8)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_DDR_MODE.
#define BM_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE      (0x00000100)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_DDR_MODE.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_DDR_MODE from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE) >> BP_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_DDR_MODE.
#define BF_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE) & BM_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DDR_MODE field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE) | BF_EPDC_HW_EPDC_TCE_CTRL_DDR_MODE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field VCOM_MODE[9] (RW)
 *
 * This field determines the method used to drive the VCOM signal.
 *
 * Values:
 * MANUAL = 0x0 - VCOM Value is set manually using VCOM_VAL field
 * AUTO = 0x1 - VCOM Value is used from waveform
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE      (9)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE.
#define BM_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE      (0x00000200)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE) >> BP_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE.
#define BF_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE) & BM_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VCOM_MODE field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE) | BF_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE(v)))
#endif

#define BV_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE__MANUAL (0x0) //!< VCOM Value is set manually using VCOM_VAL field
#define BV_EPDC_HW_EPDC_TCE_CTRL_VCOM_MODE__AUTO (0x1) //!< VCOM Value is used from waveform

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field VCOM_VAL[11:10] (RW)
 *
 * When VCOM_MODE = MANUAL, this value is used to manually set the VCOM value for the VCOM[1:0] pins
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL      (10)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL.
#define BM_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL      (0x00000c00)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL) >> BP_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL.
#define BF_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL) & BM_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VCOM_VAL field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL) | BF_EPDC_HW_EPDC_TCE_CTRL_VCOM_VAL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_CTRL, field VSCAN_HOLDOFF[24:16] (RW)
 *
 * This period (expressed in vertical lines), sets the portion of the vertical blanking available
 * for new LUTs to be activated. The remainder of the blanking period is reserved for pre-filling
 * the TCE pixel FIFOs. Increasing this value allows for multiple smaller updates to be intercepted
 * by the current frame scan. This number should not exceed FRAME_END+FRAME_SYNC+FRAME_BEGIN.
 * Increasing this value can improve the ability for any given update to intercept the next
 * available frame-scan. Excessive values can result in TCE FIFO under-runs.
 */

#define BP_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF.
#define BM_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF      (0x01ff0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF.

//! @brief Get value of EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF from a register value.
#define BG_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF) >> BP_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF.
#define BF_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF) & BM_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSCAN_HOLDOFF field to a new value.
#define BW_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF(v)   (HW_EPDC_HW_EPDC_TCE_CTRL_WR((HW_EPDC_HW_EPDC_TCE_CTRL_RD() & ~BM_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF) | BF_EPDC_HW_EPDC_TCE_CTRL_VSCAN_HOLDOFF(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_SDCFG - EPDC Timing Control Engine Source-Driver Config Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_SDCFG - EPDC Timing Control Engine Source-Driver Config Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Source-driver configuration register  HW_EPDC_TCE_SDCFG: 0x220  HW_EPDC_TCE_SDCFG_SET: 0x224
 * HW_EPDC_TCE_SDCFG_CLR: 0x228  HW_EPDC_TCE_SDCFG_TOG: 0x22C  This register houses source-driver
 * configuration.   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_sdcfg
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_sdcfg_bitfields
    {
        unsigned PIXELS_PER_CE : 13; //!< [12:0] Number of pixels (outputs) per source-driver IC. Please note that HW_EPDC_RES[HORIZONTAL] must be an integer multiple of PINS_PER_CE.
        unsigned SDDO_INVERT : 1; //!< [13] Setting this bit to 1 reverses the polarity of each SDDO bit so 0xAAAA in 16-bit mode for example becomes 0x5555. This setting can be made in addition to the SDDO_REFORMAT register setting.
        unsigned SDDO_REFORMAT : 2; //!< [15:14] This register defines the various re-formatting options to enable more flexibility in the source-driver interface:
        unsigned NUM_CE : 4; //!< [19:16] Number of source driver IC chip-enables. Must be 1-10
        unsigned SDSHR : 1; //!< [20] Value for source-driver shift direction output port
        unsigned SDCLK_HOLD : 1; //!< [21] Setting this bit to 1 holds the SDCLK low during LINE_BEGIN
        unsigned RESERVED0 : 10; //!< [31:22] Reserved.
    } B;
} hw_epdc_hw_epdc_tce_sdcfg_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_SDCFG register
 */
#define HW_EPDC_HW_EPDC_TCE_SDCFG_ADDR      (REGS_EPDC_BASE + 0x220)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_SDCFG           (*(volatile hw_epdc_hw_epdc_tce_sdcfg_t *) HW_EPDC_HW_EPDC_TCE_SDCFG_ADDR)
#define HW_EPDC_HW_EPDC_TCE_SDCFG_RD()      (HW_EPDC_HW_EPDC_TCE_SDCFG.U)
#define HW_EPDC_HW_EPDC_TCE_SDCFG_WR(v)     (HW_EPDC_HW_EPDC_TCE_SDCFG.U = (v))
#define HW_EPDC_HW_EPDC_TCE_SDCFG_SET(v)    (HW_EPDC_HW_EPDC_TCE_SDCFG_WR(HW_EPDC_HW_EPDC_TCE_SDCFG_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_SDCFG_CLR(v)    (HW_EPDC_HW_EPDC_TCE_SDCFG_WR(HW_EPDC_HW_EPDC_TCE_SDCFG_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_SDCFG_TOG(v)    (HW_EPDC_HW_EPDC_TCE_SDCFG_WR(HW_EPDC_HW_EPDC_TCE_SDCFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_SDCFG bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_SDCFG, field PIXELS_PER_CE[12:0] (RW)
 *
 * Number of pixels (outputs) per source-driver IC. Please note that HW_EPDC_RES[HORIZONTAL] must be
 * an integer multiple of PINS_PER_CE.
 */

#define BP_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE.
#define BM_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE      (0x00001fff)  //!< Bit mask for EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE.

//! @brief Get value of EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE from a register value.
#define BG_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE) >> BP_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE.
#define BF_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE) & BM_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXELS_PER_CE field to a new value.
#define BW_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE(v)   (HW_EPDC_HW_EPDC_TCE_SDCFG_WR((HW_EPDC_HW_EPDC_TCE_SDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE) | BF_EPDC_HW_EPDC_TCE_SDCFG_PIXELS_PER_CE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_SDCFG, field SDDO_INVERT[13] (RW)
 *
 * Setting this bit to 1 reverses the polarity of each SDDO bit so 0xAAAA in 16-bit mode for example
 * becomes 0x5555. This setting can be made in addition to the SDDO_REFORMAT register setting.
 */

#define BP_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT      (13)      //!< Bit position for EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT.
#define BM_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT      (0x00002000)  //!< Bit mask for EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT.

//! @brief Get value of EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT from a register value.
#define BG_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT) >> BP_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT.
#define BF_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT) & BM_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDDO_INVERT field to a new value.
#define BW_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT(v)   (HW_EPDC_HW_EPDC_TCE_SDCFG_WR((HW_EPDC_HW_EPDC_TCE_SDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT) | BF_EPDC_HW_EPDC_TCE_SDCFG_SDDO_INVERT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_SDCFG, field SDDO_REFORMAT[15:14] (RW)
 *
 * This register defines the various re-formatting options to enable more flexibility in the source-
 * driver interface:
 *
 * Values:
 * STANDARD = 0x0 - No change.
 * FLIP_PIXELS = 0x1 - Reverses the order of the pixels on SDDO. This register setting is sensitive to the TFT pixel width
 *     (TFT_PIXEL_FORMAT), e.g. for TFT_PIXEL_FORMAT=2B on an 8-bit bus P3,P2,P1,P0 becomes
 *     P0,P1,P2,P3, whereas with TFT_PIXEL_FORMAT=4B, on an 8-bit bus, P1,P0 becomes P0,P1
 */

#define BP_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT      (14)      //!< Bit position for EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT.
#define BM_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT      (0x0000c000)  //!< Bit mask for EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT.

//! @brief Get value of EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT from a register value.
#define BG_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT) >> BP_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT.
#define BF_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT) & BM_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDDO_REFORMAT field to a new value.
#define BW_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT(v)   (HW_EPDC_HW_EPDC_TCE_SDCFG_WR((HW_EPDC_HW_EPDC_TCE_SDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT) | BF_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT(v)))
#endif

#define BV_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT__STANDARD (0x0) //!< No change.
#define BV_EPDC_HW_EPDC_TCE_SDCFG_SDDO_REFORMAT__FLIP_PIXELS (0x1) //!< Reverses the order of the pixels on SDDO. This register setting is sensitive to the TFT pixel width (TFT_PIXEL_FORMAT), e.g. for TFT_PIXEL_FORMAT=2B on an 8-bit bus P3,P2,P1,P0 becomes P0,P1,P2,P3, whereas with TFT_PIXEL_FORMAT=4B, on an 8-bit bus, P1,P0 becomes P0,P1

/* --- Register HW_EPDC_HW_EPDC_TCE_SDCFG, field NUM_CE[19:16] (RW)
 *
 * Number of source driver IC chip-enables. Must be 1-10
 */

#define BP_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_SDCFG_NUM_CE.
#define BM_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE      (0x000f0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_SDCFG_NUM_CE.

//! @brief Get value of EPDC_HW_EPDC_TCE_SDCFG_NUM_CE from a register value.
#define BG_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE) >> BP_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_SDCFG_NUM_CE.
#define BF_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE) & BM_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM_CE field to a new value.
#define BW_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE(v)   (HW_EPDC_HW_EPDC_TCE_SDCFG_WR((HW_EPDC_HW_EPDC_TCE_SDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE) | BF_EPDC_HW_EPDC_TCE_SDCFG_NUM_CE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_SDCFG, field SDSHR[20] (RW)
 *
 * Value for source-driver shift direction output port
 */

#define BP_EPDC_HW_EPDC_TCE_SDCFG_SDSHR      (20)      //!< Bit position for EPDC_HW_EPDC_TCE_SDCFG_SDSHR.
#define BM_EPDC_HW_EPDC_TCE_SDCFG_SDSHR      (0x00100000)  //!< Bit mask for EPDC_HW_EPDC_TCE_SDCFG_SDSHR.

//! @brief Get value of EPDC_HW_EPDC_TCE_SDCFG_SDSHR from a register value.
#define BG_EPDC_HW_EPDC_TCE_SDCFG_SDSHR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_SDCFG_SDSHR) >> BP_EPDC_HW_EPDC_TCE_SDCFG_SDSHR)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_SDCFG_SDSHR.
#define BF_EPDC_HW_EPDC_TCE_SDCFG_SDSHR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_SDCFG_SDSHR) & BM_EPDC_HW_EPDC_TCE_SDCFG_SDSHR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDSHR field to a new value.
#define BW_EPDC_HW_EPDC_TCE_SDCFG_SDSHR(v)   (HW_EPDC_HW_EPDC_TCE_SDCFG_WR((HW_EPDC_HW_EPDC_TCE_SDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_SDCFG_SDSHR) | BF_EPDC_HW_EPDC_TCE_SDCFG_SDSHR(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_SDCFG, field SDCLK_HOLD[21] (RW)
 *
 * Setting this bit to 1 holds the SDCLK low during LINE_BEGIN
 */

#define BP_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD      (21)      //!< Bit position for EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD.
#define BM_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD      (0x00200000)  //!< Bit mask for EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD.

//! @brief Get value of EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD from a register value.
#define BG_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD) >> BP_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD.
#define BF_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD) & BM_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDCLK_HOLD field to a new value.
#define BW_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD(v)   (HW_EPDC_HW_EPDC_TCE_SDCFG_WR((HW_EPDC_HW_EPDC_TCE_SDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD) | BF_EPDC_HW_EPDC_TCE_SDCFG_SDCLK_HOLD(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_GDCFG - EPDC Timing Control Engine Gate-Driver Config Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_GDCFG - EPDC Timing Control Engine Gate-Driver Config Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Source-driver configuration register  HW_EPDC_TCE_GDCFG: 0x240  HW_EPDC_TCE_GDCFG_SET: 0x244
 * HW_EPDC_TCE_GDCFG_CLR: 0x248  HW_EPDC_TCE_GDCFG_TOG: 0x24C  This register houses gate-driver
 * configuration.   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_gdcfg
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_gdcfg_bitfields
    {
        unsigned GDSP_MODE : 1; //!< [0] Selects method for driving GDSP pulse. When set to 0, GDSP is is always fixed to have a pulse width of one line-time. When set to 1, GDSP has a pulse-width determined by the FRAME_SYNC setting. Note that GDSP_MODE=1 is not compatible with the GDSP_OFFSET function
        unsigned GDOE_MODE : 1; //!< [1] Selects method for driving GDOE signal. When set to 0, GDOE is driven at all times during the frame-scan except FRAME_SYNC. When set to 1, GDOE is driven as a delayed version of GDCLK delayed by HW_EPDC_TCE_TIMING3[GDOE_OFFSET].
        unsigned RESERVED0 : 2; //!< [3:2] Reserved.
        unsigned GDRL : 1; //!< [4] Value for gate-driver right/left shift output port
        unsigned RESERVED1 : 11; //!< [15:5] Reserved.
        unsigned PERIOD_VSCAN : 16; //!< [31:16] when vscan state is splited, this reg defines the counter period
    } B;
} hw_epdc_hw_epdc_tce_gdcfg_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_GDCFG register
 */
#define HW_EPDC_HW_EPDC_TCE_GDCFG_ADDR      (REGS_EPDC_BASE + 0x240)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_GDCFG           (*(volatile hw_epdc_hw_epdc_tce_gdcfg_t *) HW_EPDC_HW_EPDC_TCE_GDCFG_ADDR)
#define HW_EPDC_HW_EPDC_TCE_GDCFG_RD()      (HW_EPDC_HW_EPDC_TCE_GDCFG.U)
#define HW_EPDC_HW_EPDC_TCE_GDCFG_WR(v)     (HW_EPDC_HW_EPDC_TCE_GDCFG.U = (v))
#define HW_EPDC_HW_EPDC_TCE_GDCFG_SET(v)    (HW_EPDC_HW_EPDC_TCE_GDCFG_WR(HW_EPDC_HW_EPDC_TCE_GDCFG_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_GDCFG_CLR(v)    (HW_EPDC_HW_EPDC_TCE_GDCFG_WR(HW_EPDC_HW_EPDC_TCE_GDCFG_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_GDCFG_TOG(v)    (HW_EPDC_HW_EPDC_TCE_GDCFG_WR(HW_EPDC_HW_EPDC_TCE_GDCFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_GDCFG bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_GDCFG, field GDSP_MODE[0] (RW)
 *
 * Selects method for driving GDSP pulse. When set to 0, GDSP is is always fixed to have a pulse
 * width of one line-time. When set to 1, GDSP has a pulse-width determined by the FRAME_SYNC
 * setting. Note that GDSP_MODE=1 is not compatible with the GDSP_OFFSET function
 */

#define BP_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE.
#define BM_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE.

//! @brief Get value of EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE from a register value.
#define BG_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE) >> BP_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE.
#define BF_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE) & BM_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDSP_MODE field to a new value.
#define BW_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE(v)   (HW_EPDC_HW_EPDC_TCE_GDCFG_WR((HW_EPDC_HW_EPDC_TCE_GDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE) | BF_EPDC_HW_EPDC_TCE_GDCFG_GDSP_MODE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_GDCFG, field GDOE_MODE[1] (RW)
 *
 * Selects method for driving GDOE signal. When set to 0, GDOE is driven at all times during the
 * frame-scan except FRAME_SYNC. When set to 1, GDOE is driven as a delayed version of GDCLK delayed
 * by HW_EPDC_TCE_TIMING3[GDOE_OFFSET].
 */

#define BP_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE      (1)      //!< Bit position for EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE.
#define BM_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE.

//! @brief Get value of EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE from a register value.
#define BG_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE) >> BP_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE.
#define BF_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE) & BM_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDOE_MODE field to a new value.
#define BW_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE(v)   (HW_EPDC_HW_EPDC_TCE_GDCFG_WR((HW_EPDC_HW_EPDC_TCE_GDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE) | BF_EPDC_HW_EPDC_TCE_GDCFG_GDOE_MODE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_GDCFG, field GDRL[4] (RW)
 *
 * Value for gate-driver right/left shift output port
 */

#define BP_EPDC_HW_EPDC_TCE_GDCFG_GDRL      (4)      //!< Bit position for EPDC_HW_EPDC_TCE_GDCFG_GDRL.
#define BM_EPDC_HW_EPDC_TCE_GDCFG_GDRL      (0x00000010)  //!< Bit mask for EPDC_HW_EPDC_TCE_GDCFG_GDRL.

//! @brief Get value of EPDC_HW_EPDC_TCE_GDCFG_GDRL from a register value.
#define BG_EPDC_HW_EPDC_TCE_GDCFG_GDRL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_GDCFG_GDRL) >> BP_EPDC_HW_EPDC_TCE_GDCFG_GDRL)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_GDCFG_GDRL.
#define BF_EPDC_HW_EPDC_TCE_GDCFG_GDRL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_GDCFG_GDRL) & BM_EPDC_HW_EPDC_TCE_GDCFG_GDRL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDRL field to a new value.
#define BW_EPDC_HW_EPDC_TCE_GDCFG_GDRL(v)   (HW_EPDC_HW_EPDC_TCE_GDCFG_WR((HW_EPDC_HW_EPDC_TCE_GDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_GDCFG_GDRL) | BF_EPDC_HW_EPDC_TCE_GDCFG_GDRL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_GDCFG, field PERIOD_VSCAN[31:16] (RW)
 *
 * when vscan state is splited, this reg defines the counter period
 */

#define BP_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN.
#define BM_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN.

//! @brief Get value of EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN from a register value.
#define BG_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN) >> BP_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN.
#define BF_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN) & BM_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIOD_VSCAN field to a new value.
#define BW_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN(v)   (HW_EPDC_HW_EPDC_TCE_GDCFG_WR((HW_EPDC_HW_EPDC_TCE_GDCFG_RD() & ~BM_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN) | BF_EPDC_HW_EPDC_TCE_GDCFG_PERIOD_VSCAN(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_HSCAN1 - EPDC Timing Control Engine Horizontal Timing Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_HSCAN1 - EPDC Timing Control Engine Horizontal Timing Register 1 (RW)
 *
 * Reset value: 0x00000000
 *
 * Horizontal scan timing registers. Note that all timing values are expressed in terms of the
 * EPDC's internal PIXCLK, which depending on the PIXELS_PER_SDCLK register setting is either 2:1 or
 * 4:1  HW_EPDC_TCE_HSCAN1: 0x260  HW_EPDC_TCE_HSCAN1_SET: 0x264  HW_EPDC_TCE_HSCAN1_CLR: 0x268
 * HW_EPDC_TCE_HSCAN1_TOG: 0x26C  This register houses Horizontal scan timing. Note that line data
 * length is derived from HW_EPDC_RES.   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_hscan1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_hscan1_bitfields
    {
        unsigned LINE_SYNC : 12; //!< [11:0] Number of PIXCLK cycles for line sync duration. Note that this value encompasses the LINE_SYNC_WIDTH duration. This value must be programmed to a multiple of SDCLK cycles
        unsigned RESERVED0 : 4; //!< [15:12] Reserved.
        unsigned LINE_SYNC_WIDTH : 12; //!< [27:16] Number of PIXCLK cycles for the SDLE active time. Note that this value cannot be larger than LINE_SYNC and must be greater than 0. Typically it is recommended to set this value to be the same as LINE_SYNC
        unsigned RESERVED1 : 4; //!< [31:28] Reserved.
    } B;
} hw_epdc_hw_epdc_tce_hscan1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_HSCAN1 register
 */
#define HW_EPDC_HW_EPDC_TCE_HSCAN1_ADDR      (REGS_EPDC_BASE + 0x260)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_HSCAN1           (*(volatile hw_epdc_hw_epdc_tce_hscan1_t *) HW_EPDC_HW_EPDC_TCE_HSCAN1_ADDR)
#define HW_EPDC_HW_EPDC_TCE_HSCAN1_RD()      (HW_EPDC_HW_EPDC_TCE_HSCAN1.U)
#define HW_EPDC_HW_EPDC_TCE_HSCAN1_WR(v)     (HW_EPDC_HW_EPDC_TCE_HSCAN1.U = (v))
#define HW_EPDC_HW_EPDC_TCE_HSCAN1_SET(v)    (HW_EPDC_HW_EPDC_TCE_HSCAN1_WR(HW_EPDC_HW_EPDC_TCE_HSCAN1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_HSCAN1_CLR(v)    (HW_EPDC_HW_EPDC_TCE_HSCAN1_WR(HW_EPDC_HW_EPDC_TCE_HSCAN1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_HSCAN1_TOG(v)    (HW_EPDC_HW_EPDC_TCE_HSCAN1_WR(HW_EPDC_HW_EPDC_TCE_HSCAN1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_HSCAN1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_HSCAN1, field LINE_SYNC[11:0] (RW)
 *
 * Number of PIXCLK cycles for line sync duration. Note that this value encompasses the
 * LINE_SYNC_WIDTH duration. This value must be programmed to a multiple of SDCLK cycles
 */

#define BP_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC.
#define BM_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC      (0x00000fff)  //!< Bit mask for EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC.

//! @brief Get value of EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC from a register value.
#define BG_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC) >> BP_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC.
#define BF_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC) & BM_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINE_SYNC field to a new value.
#define BW_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC(v)   (HW_EPDC_HW_EPDC_TCE_HSCAN1_WR((HW_EPDC_HW_EPDC_TCE_HSCAN1_RD() & ~BM_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC) | BF_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_HSCAN1, field LINE_SYNC_WIDTH[27:16] (RW)
 *
 * Number of PIXCLK cycles for the SDLE active time. Note that this value cannot be larger than
 * LINE_SYNC and must be greater than 0. Typically it is recommended to set this value to be the
 * same as LINE_SYNC
 */

#define BP_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH.
#define BM_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH      (0x0fff0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH.

//! @brief Get value of EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH from a register value.
#define BG_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH) >> BP_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH.
#define BF_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH) & BM_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINE_SYNC_WIDTH field to a new value.
#define BW_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH(v)   (HW_EPDC_HW_EPDC_TCE_HSCAN1_WR((HW_EPDC_HW_EPDC_TCE_HSCAN1_RD() & ~BM_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH) | BF_EPDC_HW_EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_HSCAN2 - EPDC Timing Control Engine Horizontal Timing Register 2
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_HSCAN2 - EPDC Timing Control Engine Horizontal Timing Register 2 (RW)
 *
 * Reset value: 0x00000000
 *
 * Horizontal scan timing registers. Note that all timing values are expressed in terms of the
 * EPDC's internal PIXCLK, which depending on the PIXELS_PER_SDCLK register setting is either 2:1 or
 * 4:1  HW_EPDC_TCE_HSCAN2: 0x280  HW_EPDC_TCE_HSCAN2_SET: 0x284  HW_EPDC_TCE_HSCAN2_CLR: 0x288
 * HW_EPDC_TCE_HSCAN2_TOG: 0x28C  This register houses Horizontal scan timing. Note that line data
 * length is derived from HW_EPDC_RES.   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_hscan2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_hscan2_bitfields
    {
        unsigned LINE_BEGIN : 12; //!< [11:0] Number of PIXCLK cycles for line begin duration. This defines the interval between de-assertion of SDLE and assertion of the SDCE signals. This value must be programmed to a multiple of SDCLK cycles
        unsigned RESERVED0 : 4; //!< [15:12] Reserved.
        unsigned LINE_END : 12; //!< [27:16] Number of PIXCLK cycles for line end duration. This defines the duration from the de-assertion of SDCE and assertion of the next SDLE.
        unsigned RESERVED1 : 4; //!< [31:28] Reserved.
    } B;
} hw_epdc_hw_epdc_tce_hscan2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_HSCAN2 register
 */
#define HW_EPDC_HW_EPDC_TCE_HSCAN2_ADDR      (REGS_EPDC_BASE + 0x280)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_HSCAN2           (*(volatile hw_epdc_hw_epdc_tce_hscan2_t *) HW_EPDC_HW_EPDC_TCE_HSCAN2_ADDR)
#define HW_EPDC_HW_EPDC_TCE_HSCAN2_RD()      (HW_EPDC_HW_EPDC_TCE_HSCAN2.U)
#define HW_EPDC_HW_EPDC_TCE_HSCAN2_WR(v)     (HW_EPDC_HW_EPDC_TCE_HSCAN2.U = (v))
#define HW_EPDC_HW_EPDC_TCE_HSCAN2_SET(v)    (HW_EPDC_HW_EPDC_TCE_HSCAN2_WR(HW_EPDC_HW_EPDC_TCE_HSCAN2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_HSCAN2_CLR(v)    (HW_EPDC_HW_EPDC_TCE_HSCAN2_WR(HW_EPDC_HW_EPDC_TCE_HSCAN2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_HSCAN2_TOG(v)    (HW_EPDC_HW_EPDC_TCE_HSCAN2_WR(HW_EPDC_HW_EPDC_TCE_HSCAN2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_HSCAN2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_HSCAN2, field LINE_BEGIN[11:0] (RW)
 *
 * Number of PIXCLK cycles for line begin duration. This defines the interval between de-assertion
 * of SDLE and assertion of the SDCE signals. This value must be programmed to a multiple of SDCLK
 * cycles
 */

#define BP_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN.
#define BM_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN      (0x00000fff)  //!< Bit mask for EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN.

//! @brief Get value of EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN from a register value.
#define BG_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN) >> BP_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN.
#define BF_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN) & BM_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINE_BEGIN field to a new value.
#define BW_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN(v)   (HW_EPDC_HW_EPDC_TCE_HSCAN2_WR((HW_EPDC_HW_EPDC_TCE_HSCAN2_RD() & ~BM_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN) | BF_EPDC_HW_EPDC_TCE_HSCAN2_LINE_BEGIN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_HSCAN2, field LINE_END[27:16] (RW)
 *
 * Number of PIXCLK cycles for line end duration. This defines the duration from the de-assertion of
 * SDCE and assertion of the next SDLE.
 */

#define BP_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_HSCAN2_LINE_END.
#define BM_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END      (0x0fff0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_HSCAN2_LINE_END.

//! @brief Get value of EPDC_HW_EPDC_TCE_HSCAN2_LINE_END from a register value.
#define BG_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END) >> BP_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_HSCAN2_LINE_END.
#define BF_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END) & BM_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINE_END field to a new value.
#define BW_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END(v)   (HW_EPDC_HW_EPDC_TCE_HSCAN2_WR((HW_EPDC_HW_EPDC_TCE_HSCAN2_RD() & ~BM_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END) | BF_EPDC_HW_EPDC_TCE_HSCAN2_LINE_END(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_VSCAN - EPDC Timing Control Engine Vertical Timing Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_VSCAN - EPDC Timing Control Engine Vertical Timing Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Vertical scan timing registers  HW_EPDC_TCE_VSCAN: 0x2A0  HW_EPDC_TCE_VSCAN_SET: 0x2A4
 * HW_EPDC_TCE_VSCAN_CLR: 0x2A8  HW_EPDC_TCE_VSCAN_TOG: 0x2AC  This register houses vertical scan
 * timing. Note that frame data length is derived from HW_EPDC_RES.   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_vscan
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_vscan_bitfields
    {
        unsigned FRAME_SYNC : 8; //!< [7:0] Number of lines for frame sync duration.
        unsigned FRAME_BEGIN : 8; //!< [15:8] Number of lines for frame begin duration.
        unsigned FRAME_END : 8; //!< [23:16] Number of lines for frame end duration.
        unsigned RESERVED0 : 8; //!< [31:24] Reserved.
    } B;
} hw_epdc_hw_epdc_tce_vscan_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_VSCAN register
 */
#define HW_EPDC_HW_EPDC_TCE_VSCAN_ADDR      (REGS_EPDC_BASE + 0x2a0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_VSCAN           (*(volatile hw_epdc_hw_epdc_tce_vscan_t *) HW_EPDC_HW_EPDC_TCE_VSCAN_ADDR)
#define HW_EPDC_HW_EPDC_TCE_VSCAN_RD()      (HW_EPDC_HW_EPDC_TCE_VSCAN.U)
#define HW_EPDC_HW_EPDC_TCE_VSCAN_WR(v)     (HW_EPDC_HW_EPDC_TCE_VSCAN.U = (v))
#define HW_EPDC_HW_EPDC_TCE_VSCAN_SET(v)    (HW_EPDC_HW_EPDC_TCE_VSCAN_WR(HW_EPDC_HW_EPDC_TCE_VSCAN_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_VSCAN_CLR(v)    (HW_EPDC_HW_EPDC_TCE_VSCAN_WR(HW_EPDC_HW_EPDC_TCE_VSCAN_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_VSCAN_TOG(v)    (HW_EPDC_HW_EPDC_TCE_VSCAN_WR(HW_EPDC_HW_EPDC_TCE_VSCAN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_VSCAN bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_VSCAN, field FRAME_SYNC[7:0] (RW)
 *
 * Number of lines for frame sync duration.
 */

#define BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC.
#define BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC      (0x000000ff)  //!< Bit mask for EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC.

//! @brief Get value of EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC from a register value.
#define BG_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC) >> BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC.
#define BF_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC) & BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_SYNC field to a new value.
#define BW_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC(v)   (HW_EPDC_HW_EPDC_TCE_VSCAN_WR((HW_EPDC_HW_EPDC_TCE_VSCAN_RD() & ~BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC) | BF_EPDC_HW_EPDC_TCE_VSCAN_FRAME_SYNC(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_VSCAN, field FRAME_BEGIN[15:8] (RW)
 *
 * Number of lines for frame begin duration.
 */

#define BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN      (8)      //!< Bit position for EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN.
#define BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN      (0x0000ff00)  //!< Bit mask for EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN.

//! @brief Get value of EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN from a register value.
#define BG_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN) >> BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN.
#define BF_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN) & BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_BEGIN field to a new value.
#define BW_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN(v)   (HW_EPDC_HW_EPDC_TCE_VSCAN_WR((HW_EPDC_HW_EPDC_TCE_VSCAN_RD() & ~BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN) | BF_EPDC_HW_EPDC_TCE_VSCAN_FRAME_BEGIN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_VSCAN, field FRAME_END[23:16] (RW)
 *
 * Number of lines for frame end duration.
 */

#define BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_VSCAN_FRAME_END.
#define BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END      (0x00ff0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_VSCAN_FRAME_END.

//! @brief Get value of EPDC_HW_EPDC_TCE_VSCAN_FRAME_END from a register value.
#define BG_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END) >> BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_VSCAN_FRAME_END.
#define BF_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END) & BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_END field to a new value.
#define BW_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END(v)   (HW_EPDC_HW_EPDC_TCE_VSCAN_WR((HW_EPDC_HW_EPDC_TCE_VSCAN_RD() & ~BM_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END) | BF_EPDC_HW_EPDC_TCE_VSCAN_FRAME_END(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_OE - EPDC Timing Control Engine OE timing control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_OE - EPDC Timing Control Engine OE timing control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register contain delay programming values for the SDOEZ and SDOED source driver control
 * signals  HW_EPDC_TCE_OE: 0x2C0  HW_EPDC_TCE_OE_SET: 0x2C4  HW_EPDC_TCE_OE_CLR: 0x2C8
 * HW_EPDC_TCE_OE_TOG: 0x2CC  This register contain delay programming values for the SDOZ and SDOE
 * source driver control signals   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_oe
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_oe_bitfields
    {
        unsigned SDOEZ_DLY : 8; //!< [7:0] Number of PIXCLK cycles from SDLE falling edge to SDOEZ rising (Must be greater than 0)
        unsigned SDOEZ_WIDTH : 8; //!< [15:8] Number of PIXCLK cycles from SDOEZ high to SDOEZ falling (Must be greater than 0)
        unsigned SDOED_DLY : 8; //!< [23:16] Number of PIXCLK cycles from SDOEZ low to SDOED rising (Must be greater than 0)
        unsigned SDOED_WIDTH : 8; //!< [31:24] Number of PIXCLK cycles from SDOED high to SDOED falling (Must be greater than 0)
    } B;
} hw_epdc_hw_epdc_tce_oe_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_OE register
 */
#define HW_EPDC_HW_EPDC_TCE_OE_ADDR      (REGS_EPDC_BASE + 0x2c0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_OE           (*(volatile hw_epdc_hw_epdc_tce_oe_t *) HW_EPDC_HW_EPDC_TCE_OE_ADDR)
#define HW_EPDC_HW_EPDC_TCE_OE_RD()      (HW_EPDC_HW_EPDC_TCE_OE.U)
#define HW_EPDC_HW_EPDC_TCE_OE_WR(v)     (HW_EPDC_HW_EPDC_TCE_OE.U = (v))
#define HW_EPDC_HW_EPDC_TCE_OE_SET(v)    (HW_EPDC_HW_EPDC_TCE_OE_WR(HW_EPDC_HW_EPDC_TCE_OE_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_OE_CLR(v)    (HW_EPDC_HW_EPDC_TCE_OE_WR(HW_EPDC_HW_EPDC_TCE_OE_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_OE_TOG(v)    (HW_EPDC_HW_EPDC_TCE_OE_WR(HW_EPDC_HW_EPDC_TCE_OE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_OE bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_OE, field SDOEZ_DLY[7:0] (RW)
 *
 * Number of PIXCLK cycles from SDLE falling edge to SDOEZ rising (Must be greater than 0)
 */

#define BP_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY.
#define BM_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY      (0x000000ff)  //!< Bit mask for EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY.

//! @brief Get value of EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY from a register value.
#define BG_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY) >> BP_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY.
#define BF_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY) & BM_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDOEZ_DLY field to a new value.
#define BW_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY(v)   (HW_EPDC_HW_EPDC_TCE_OE_WR((HW_EPDC_HW_EPDC_TCE_OE_RD() & ~BM_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY) | BF_EPDC_HW_EPDC_TCE_OE_SDOEZ_DLY(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_OE, field SDOEZ_WIDTH[15:8] (RW)
 *
 * Number of PIXCLK cycles from SDOEZ high to SDOEZ falling (Must be greater than 0)
 */

#define BP_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH      (8)      //!< Bit position for EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH.
#define BM_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH      (0x0000ff00)  //!< Bit mask for EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH.

//! @brief Get value of EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH from a register value.
#define BG_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH) >> BP_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH.
#define BF_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH) & BM_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDOEZ_WIDTH field to a new value.
#define BW_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH(v)   (HW_EPDC_HW_EPDC_TCE_OE_WR((HW_EPDC_HW_EPDC_TCE_OE_RD() & ~BM_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH) | BF_EPDC_HW_EPDC_TCE_OE_SDOEZ_WIDTH(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_OE, field SDOED_DLY[23:16] (RW)
 *
 * Number of PIXCLK cycles from SDOEZ low to SDOED rising (Must be greater than 0)
 */

#define BP_EPDC_HW_EPDC_TCE_OE_SDOED_DLY      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_OE_SDOED_DLY.
#define BM_EPDC_HW_EPDC_TCE_OE_SDOED_DLY      (0x00ff0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_OE_SDOED_DLY.

//! @brief Get value of EPDC_HW_EPDC_TCE_OE_SDOED_DLY from a register value.
#define BG_EPDC_HW_EPDC_TCE_OE_SDOED_DLY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_OE_SDOED_DLY) >> BP_EPDC_HW_EPDC_TCE_OE_SDOED_DLY)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_OE_SDOED_DLY.
#define BF_EPDC_HW_EPDC_TCE_OE_SDOED_DLY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_OE_SDOED_DLY) & BM_EPDC_HW_EPDC_TCE_OE_SDOED_DLY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDOED_DLY field to a new value.
#define BW_EPDC_HW_EPDC_TCE_OE_SDOED_DLY(v)   (HW_EPDC_HW_EPDC_TCE_OE_WR((HW_EPDC_HW_EPDC_TCE_OE_RD() & ~BM_EPDC_HW_EPDC_TCE_OE_SDOED_DLY) | BF_EPDC_HW_EPDC_TCE_OE_SDOED_DLY(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_OE, field SDOED_WIDTH[31:24] (RW)
 *
 * Number of PIXCLK cycles from SDOED high to SDOED falling (Must be greater than 0)
 */

#define BP_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH      (24)      //!< Bit position for EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH.
#define BM_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH.

//! @brief Get value of EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH from a register value.
#define BG_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH) >> BP_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH.
#define BF_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH) & BM_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDOED_WIDTH field to a new value.
#define BW_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH(v)   (HW_EPDC_HW_EPDC_TCE_OE_WR((HW_EPDC_HW_EPDC_TCE_OE_RD() & ~BM_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH) | BF_EPDC_HW_EPDC_TCE_OE_SDOED_WIDTH(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_POLARITY - EPDC Timing Control Engine Driver Polarity Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_POLARITY - EPDC Timing Control Engine Driver Polarity Register (RW)
 *
 * Reset value: 0x0000001e
 *
 * This registers allows for programming the polarity of source/gate driver control signals
 * HW_EPDC_TCE_POLARITY: 0x2E0  HW_EPDC_TCE_POLARITY_SET: 0x2E4  HW_EPDC_TCE_POLARITY_CLR: 0x2E8
 * HW_EPDC_TCE_POLARITY_TOG: 0x2EC  This register houses FIFO control bits   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_polarity
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_polarity_bitfields
    {
        unsigned SDCE_POL : 1; //!< [0] 0 = Active Low, 1 = Active High. Applies to all 10 SDCE outputs
        unsigned SDLE_POL : 1; //!< [1] 0 = Active Low, 1 = Active High. Applies to the SDLE output
        unsigned SDOE_POL : 1; //!< [2] 0 = Active Low, 1 = Active High. Applies to the SDOE. Does not apply to SDOEZ and SDOED outputs
        unsigned GDOE_POL : 1; //!< [3] 0 = Active Low, 1 = Active High. Applies to the GDOE output
        unsigned GDSP_POL : 1; //!< [4] 0 = Active Low, 1 = Active High. Applies to the GDSP output
        unsigned RESERVED0 : 27; //!< [31:5] Reserved.
    } B;
} hw_epdc_hw_epdc_tce_polarity_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_POLARITY register
 */
#define HW_EPDC_HW_EPDC_TCE_POLARITY_ADDR      (REGS_EPDC_BASE + 0x2e0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_POLARITY           (*(volatile hw_epdc_hw_epdc_tce_polarity_t *) HW_EPDC_HW_EPDC_TCE_POLARITY_ADDR)
#define HW_EPDC_HW_EPDC_TCE_POLARITY_RD()      (HW_EPDC_HW_EPDC_TCE_POLARITY.U)
#define HW_EPDC_HW_EPDC_TCE_POLARITY_WR(v)     (HW_EPDC_HW_EPDC_TCE_POLARITY.U = (v))
#define HW_EPDC_HW_EPDC_TCE_POLARITY_SET(v)    (HW_EPDC_HW_EPDC_TCE_POLARITY_WR(HW_EPDC_HW_EPDC_TCE_POLARITY_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_POLARITY_CLR(v)    (HW_EPDC_HW_EPDC_TCE_POLARITY_WR(HW_EPDC_HW_EPDC_TCE_POLARITY_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_POLARITY_TOG(v)    (HW_EPDC_HW_EPDC_TCE_POLARITY_WR(HW_EPDC_HW_EPDC_TCE_POLARITY_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_POLARITY bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_POLARITY, field SDCE_POL[0] (RW)
 *
 * 0 = Active Low, 1 = Active High. Applies to all 10 SDCE outputs
 */

#define BP_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL.
#define BM_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL.

//! @brief Get value of EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL from a register value.
#define BG_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL) >> BP_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL.
#define BF_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL) & BM_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDCE_POL field to a new value.
#define BW_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL(v)   (HW_EPDC_HW_EPDC_TCE_POLARITY_WR((HW_EPDC_HW_EPDC_TCE_POLARITY_RD() & ~BM_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL) | BF_EPDC_HW_EPDC_TCE_POLARITY_SDCE_POL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_POLARITY, field SDLE_POL[1] (RW)
 *
 * 0 = Active Low, 1 = Active High. Applies to the SDLE output
 */

#define BP_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL      (1)      //!< Bit position for EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL.
#define BM_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL.

//! @brief Get value of EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL from a register value.
#define BG_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL) >> BP_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL.
#define BF_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL) & BM_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDLE_POL field to a new value.
#define BW_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL(v)   (HW_EPDC_HW_EPDC_TCE_POLARITY_WR((HW_EPDC_HW_EPDC_TCE_POLARITY_RD() & ~BM_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL) | BF_EPDC_HW_EPDC_TCE_POLARITY_SDLE_POL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_POLARITY, field SDOE_POL[2] (RW)
 *
 * 0 = Active Low, 1 = Active High. Applies to the SDOE. Does not apply to SDOEZ and SDOED outputs
 */

#define BP_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL      (2)      //!< Bit position for EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL.
#define BM_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL      (0x00000004)  //!< Bit mask for EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL.

//! @brief Get value of EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL from a register value.
#define BG_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL) >> BP_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL.
#define BF_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL) & BM_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDOE_POL field to a new value.
#define BW_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL(v)   (HW_EPDC_HW_EPDC_TCE_POLARITY_WR((HW_EPDC_HW_EPDC_TCE_POLARITY_RD() & ~BM_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL) | BF_EPDC_HW_EPDC_TCE_POLARITY_SDOE_POL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_POLARITY, field GDOE_POL[3] (RW)
 *
 * 0 = Active Low, 1 = Active High. Applies to the GDOE output
 */

#define BP_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL      (3)      //!< Bit position for EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL.
#define BM_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL      (0x00000008)  //!< Bit mask for EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL.

//! @brief Get value of EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL from a register value.
#define BG_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL) >> BP_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL.
#define BF_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL) & BM_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDOE_POL field to a new value.
#define BW_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL(v)   (HW_EPDC_HW_EPDC_TCE_POLARITY_WR((HW_EPDC_HW_EPDC_TCE_POLARITY_RD() & ~BM_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL) | BF_EPDC_HW_EPDC_TCE_POLARITY_GDOE_POL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_POLARITY, field GDSP_POL[4] (RW)
 *
 * 0 = Active Low, 1 = Active High. Applies to the GDSP output
 */

#define BP_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL      (4)      //!< Bit position for EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL.
#define BM_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL      (0x00000010)  //!< Bit mask for EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL.

//! @brief Get value of EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL from a register value.
#define BG_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL) >> BP_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL.
#define BF_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL) & BM_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDSP_POL field to a new value.
#define BW_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL(v)   (HW_EPDC_HW_EPDC_TCE_POLARITY_WR((HW_EPDC_HW_EPDC_TCE_POLARITY_RD() & ~BM_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL) | BF_EPDC_HW_EPDC_TCE_POLARITY_GDSP_POL(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_TIMING1 - EPDC Timing Control Engine Timing Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_TIMING1 - EPDC Timing Control Engine Timing Register 1 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register contains various timing adjustment controls  HW_EPDC_TCE_TIMING1: 0x300
 * HW_EPDC_TCE_TIMING1_SET: 0x304  HW_EPDC_TCE_TIMING1_CLR: 0x308  HW_EPDC_TCE_TIMING1_TOG: 0x30C
 * This register houses general purpose timing adjustment registers   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_timing1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_timing1_bitfields
    {
        unsigned SDCLK_SHIFT : 2; //!< [1:0] This register can be used to implement additional timing setup/hold adjustment of source driver signals by adjusting the SDCLK up to 4 cycles
        unsigned RESERVED0 : 1; //!< [2] Reserved.
        unsigned SDCLK_INVERT : 1; //!< [3] Invert phase of SDCLK
        unsigned SDLE_SHIFT : 2; //!< [5:4] This register can be used to implement additional timing setup/hold adjustment of source driver signals by adjusting the SDCLK up to 3 PIXCLK cycles
        unsigned RESERVED1 : 26; //!< [31:6] Reserved.
    } B;
} hw_epdc_hw_epdc_tce_timing1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_TIMING1 register
 */
#define HW_EPDC_HW_EPDC_TCE_TIMING1_ADDR      (REGS_EPDC_BASE + 0x300)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_TIMING1           (*(volatile hw_epdc_hw_epdc_tce_timing1_t *) HW_EPDC_HW_EPDC_TCE_TIMING1_ADDR)
#define HW_EPDC_HW_EPDC_TCE_TIMING1_RD()      (HW_EPDC_HW_EPDC_TCE_TIMING1.U)
#define HW_EPDC_HW_EPDC_TCE_TIMING1_WR(v)     (HW_EPDC_HW_EPDC_TCE_TIMING1.U = (v))
#define HW_EPDC_HW_EPDC_TCE_TIMING1_SET(v)    (HW_EPDC_HW_EPDC_TCE_TIMING1_WR(HW_EPDC_HW_EPDC_TCE_TIMING1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_TIMING1_CLR(v)    (HW_EPDC_HW_EPDC_TCE_TIMING1_WR(HW_EPDC_HW_EPDC_TCE_TIMING1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_TIMING1_TOG(v)    (HW_EPDC_HW_EPDC_TCE_TIMING1_WR(HW_EPDC_HW_EPDC_TCE_TIMING1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_TIMING1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_TIMING1, field SDCLK_SHIFT[1:0] (RW)
 *
 * This register can be used to implement additional timing setup/hold adjustment of source driver
 * signals by adjusting the SDCLK up to 4 cycles
 *
 * Values:
 * NONE = 0x0 - No shift of SDCLK
 * ONE = 0x1 - Shift SDCLK 1 pixclk cycle
 * TWO = 0x2 - Shift SDCLK 2 pixclk cycles
 * THREE = 0x3 - Shift SDCLK 3 pixclk cycles
 */

#define BP_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT.
#define BM_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT      (0x00000003)  //!< Bit mask for EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT.

//! @brief Get value of EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT from a register value.
#define BG_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT) >> BP_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT.
#define BF_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT) & BM_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDCLK_SHIFT field to a new value.
#define BW_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT(v)   (HW_EPDC_HW_EPDC_TCE_TIMING1_WR((HW_EPDC_HW_EPDC_TCE_TIMING1_RD() & ~BM_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT) | BF_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT(v)))
#endif

#define BV_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT__NONE (0x0) //!< No shift of SDCLK
#define BV_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT__ONE (0x1) //!< Shift SDCLK 1 pixclk cycle
#define BV_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT__TWO (0x2) //!< Shift SDCLK 2 pixclk cycles
#define BV_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_SHIFT__THREE (0x3) //!< Shift SDCLK 3 pixclk cycles

/* --- Register HW_EPDC_HW_EPDC_TCE_TIMING1, field SDCLK_INVERT[3] (RW)
 *
 * Invert phase of SDCLK
 */

#define BP_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT      (3)      //!< Bit position for EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT.
#define BM_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT      (0x00000008)  //!< Bit mask for EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT.

//! @brief Get value of EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT from a register value.
#define BG_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT) >> BP_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT.
#define BF_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT) & BM_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDCLK_INVERT field to a new value.
#define BW_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT(v)   (HW_EPDC_HW_EPDC_TCE_TIMING1_WR((HW_EPDC_HW_EPDC_TCE_TIMING1_RD() & ~BM_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT) | BF_EPDC_HW_EPDC_TCE_TIMING1_SDCLK_INVERT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_TIMING1, field SDLE_SHIFT[5:4] (RW)
 *
 * This register can be used to implement additional timing setup/hold adjustment of source driver
 * signals by adjusting the SDCLK up to 3 PIXCLK cycles
 *
 * Values:
 * NONE = 0x0 - No shift of SDLE
 * ONE = 0x1 - Shift SDLE 1 pixclk cycle
 * TWO = 0x2 - Shift SDLE 2 pixclk cycles
 * THREE = 0x3 - Shift SDLE 3 pixclk cycles
 */

#define BP_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT      (4)      //!< Bit position for EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT.
#define BM_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT      (0x00000030)  //!< Bit mask for EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT.

//! @brief Get value of EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT from a register value.
#define BG_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT) >> BP_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT.
#define BF_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT) & BM_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDLE_SHIFT field to a new value.
#define BW_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT(v)   (HW_EPDC_HW_EPDC_TCE_TIMING1_WR((HW_EPDC_HW_EPDC_TCE_TIMING1_RD() & ~BM_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT) | BF_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT(v)))
#endif

#define BV_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT__NONE (0x0) //!< No shift of SDLE
#define BV_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT__ONE (0x1) //!< Shift SDLE 1 pixclk cycle
#define BV_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT__TWO (0x2) //!< Shift SDLE 2 pixclk cycles
#define BV_EPDC_HW_EPDC_TCE_TIMING1_SDLE_SHIFT__THREE (0x3) //!< Shift SDLE 3 pixclk cycles

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_TIMING2 - EPDC Timing Control Engine Timing Register 2
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_TIMING2 - EPDC Timing Control Engine Timing Register 2 (RW)
 *
 * Reset value: 0x00000001
 *
 * This register contains various timing adjustment controls  HW_EPDC_TCE_TIMING2: 0x310
 * HW_EPDC_TCE_TIMING2_SET: 0x314  HW_EPDC_TCE_TIMING2_CLR: 0x318  HW_EPDC_TCE_TIMING2_TOG: 0x31C
 * This register houses general purpose timing adjustment registers   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_timing2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_timing2_bitfields
    {
        unsigned GDSP_OFFSET : 16; //!< [15:0] This register allows the user to shift the GDSP pulse by N PIXCLKs where N=1 to 65535. Note that GDSP will always have a pulse width equivalent to the line-clock timing. A value of 0 is not supported.
        unsigned GDCLK_HP : 16; //!< [31:16] This register controls the GDCLK high-pulse width. It is expressed by N PIXCLKs where N=1 to 65535. Note that GDCLK will always have a period equal to the line-clock timing. A value of 0 is not supported. It is recommended that this value be set to at least a half line-clock time. For panels which use GDCLK to drive GDOE, this high-pulse width should be set to cover tha majority of the line timing
    } B;
} hw_epdc_hw_epdc_tce_timing2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_TIMING2 register
 */
#define HW_EPDC_HW_EPDC_TCE_TIMING2_ADDR      (REGS_EPDC_BASE + 0x310)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_TIMING2           (*(volatile hw_epdc_hw_epdc_tce_timing2_t *) HW_EPDC_HW_EPDC_TCE_TIMING2_ADDR)
#define HW_EPDC_HW_EPDC_TCE_TIMING2_RD()      (HW_EPDC_HW_EPDC_TCE_TIMING2.U)
#define HW_EPDC_HW_EPDC_TCE_TIMING2_WR(v)     (HW_EPDC_HW_EPDC_TCE_TIMING2.U = (v))
#define HW_EPDC_HW_EPDC_TCE_TIMING2_SET(v)    (HW_EPDC_HW_EPDC_TCE_TIMING2_WR(HW_EPDC_HW_EPDC_TCE_TIMING2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_TIMING2_CLR(v)    (HW_EPDC_HW_EPDC_TCE_TIMING2_WR(HW_EPDC_HW_EPDC_TCE_TIMING2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_TIMING2_TOG(v)    (HW_EPDC_HW_EPDC_TCE_TIMING2_WR(HW_EPDC_HW_EPDC_TCE_TIMING2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_TIMING2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_TIMING2, field GDSP_OFFSET[15:0] (RW)
 *
 * This register allows the user to shift the GDSP pulse by N PIXCLKs where N=1 to 65535. Note that
 * GDSP will always have a pulse width equivalent to the line-clock timing. A value of 0 is not
 * supported.
 */

#define BP_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET.
#define BM_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET) >> BP_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET.
#define BF_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET) & BM_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDSP_OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET(v)   (HW_EPDC_HW_EPDC_TCE_TIMING2_WR((HW_EPDC_HW_EPDC_TCE_TIMING2_RD() & ~BM_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET) | BF_EPDC_HW_EPDC_TCE_TIMING2_GDSP_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_TIMING2, field GDCLK_HP[31:16] (RW)
 *
 * This register controls the GDCLK high-pulse width. It is expressed by N PIXCLKs where N=1 to
 * 65535. Note that GDCLK will always have a period equal to the line-clock timing. A value of 0 is
 * not supported. It is recommended that this value be set to at least a half line-clock time. For
 * panels which use GDCLK to drive GDOE, this high-pulse width should be set to cover tha majority
 * of the line timing
 */

#define BP_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP.
#define BM_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP.

//! @brief Get value of EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP from a register value.
#define BG_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP) >> BP_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP.
#define BF_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP) & BM_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDCLK_HP field to a new value.
#define BW_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP(v)   (HW_EPDC_HW_EPDC_TCE_TIMING2_WR((HW_EPDC_HW_EPDC_TCE_TIMING2_RD() & ~BM_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP) | BF_EPDC_HW_EPDC_TCE_TIMING2_GDCLK_HP(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_TCE_TIMING3 - EPDC Timing Control Engine Timing Register 3
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_TCE_TIMING3 - EPDC Timing Control Engine Timing Register 3 (RW)
 *
 * Reset value: 0x00000001
 *
 * This register contains various timing adjustment controls  HW_EPDC_TCE_TIMING3: 0x320
 * HW_EPDC_TCE_TIMING3_SET: 0x324  HW_EPDC_TCE_TIMING3_CLR: 0x328  HW_EPDC_TCE_TIMING3_TOG: 0x32C
 * This register houses general purpose timing adjustment registers   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_tce_timing3
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_tce_timing3_bitfields
    {
        unsigned GDCLK_OFFSET : 16; //!< [15:0] This register allows the user to shift the GDCLK from the line time by N PIXCLK cycles.
        unsigned GDOE_OFFSET : 16; //!< [31:16] When using GDOE_MODE=1, this register sets the delay from GDCLK to the GDOE in terms of N PIXCLK cycles
    } B;
} hw_epdc_hw_epdc_tce_timing3_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_TCE_TIMING3 register
 */
#define HW_EPDC_HW_EPDC_TCE_TIMING3_ADDR      (REGS_EPDC_BASE + 0x320)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_TCE_TIMING3           (*(volatile hw_epdc_hw_epdc_tce_timing3_t *) HW_EPDC_HW_EPDC_TCE_TIMING3_ADDR)
#define HW_EPDC_HW_EPDC_TCE_TIMING3_RD()      (HW_EPDC_HW_EPDC_TCE_TIMING3.U)
#define HW_EPDC_HW_EPDC_TCE_TIMING3_WR(v)     (HW_EPDC_HW_EPDC_TCE_TIMING3.U = (v))
#define HW_EPDC_HW_EPDC_TCE_TIMING3_SET(v)    (HW_EPDC_HW_EPDC_TCE_TIMING3_WR(HW_EPDC_HW_EPDC_TCE_TIMING3_RD() |  (v)))
#define HW_EPDC_HW_EPDC_TCE_TIMING3_CLR(v)    (HW_EPDC_HW_EPDC_TCE_TIMING3_WR(HW_EPDC_HW_EPDC_TCE_TIMING3_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_TCE_TIMING3_TOG(v)    (HW_EPDC_HW_EPDC_TCE_TIMING3_WR(HW_EPDC_HW_EPDC_TCE_TIMING3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_TCE_TIMING3 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_TCE_TIMING3, field GDCLK_OFFSET[15:0] (RW)
 *
 * This register allows the user to shift the GDCLK from the line time by N PIXCLK cycles.
 */

#define BP_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET      (0)      //!< Bit position for EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET.
#define BM_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET) >> BP_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET.
#define BF_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET) & BM_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDCLK_OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET(v)   (HW_EPDC_HW_EPDC_TCE_TIMING3_WR((HW_EPDC_HW_EPDC_TCE_TIMING3_RD() & ~BM_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET) | BF_EPDC_HW_EPDC_TCE_TIMING3_GDCLK_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_TCE_TIMING3, field GDOE_OFFSET[31:16] (RW)
 *
 * When using GDOE_MODE=1, this register sets the delay from GDCLK to the GDOE in terms of N PIXCLK
 * cycles
 */

#define BP_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET      (16)      //!< Bit position for EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET.
#define BM_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET) >> BP_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET.
#define BF_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET) & BM_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GDOE_OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET(v)   (HW_EPDC_HW_EPDC_TCE_TIMING3_WR((HW_EPDC_HW_EPDC_TCE_TIMING3_RD() & ~BM_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET) | BF_EPDC_HW_EPDC_TCE_TIMING3_GDOE_OFFSET(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_CTRL0 - EPDC Pigeon Mode Control Register 0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_CTRL0 - EPDC Pigeon Mode Control Register 0 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register contains global counter settings for Pigeon Mode  HW_EPDC_PIGEON_CTRL0: 0x380
 * HW_EPDC_PIGEON_CTRL0_SET: 0x384  HW_EPDC_PIGEON_CTRL0_CLR: 0x388  HW_EPDC_PIGEON_CTRL0_TOG: 0x38C
 * This register houses general purpose timing adjustment registers   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_pigeon_ctrl0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_ctrl0_bitfields
    {
        unsigned FD_PERIOD : 12; //!< [11:0] period of line counter during FD phase
        unsigned RESERVED0 : 4; //!< [15:12] Reserved.
        unsigned LD_PERIOD : 12; //!< [27:16] period of pclk counter during LD phase
        unsigned RESERVED1 : 4; //!< [31:28] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_ctrl0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_CTRL0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_CTRL0_ADDR      (REGS_EPDC_BASE + 0x380)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_CTRL0           (*(volatile hw_epdc_hw_epdc_pigeon_ctrl0_t *) HW_EPDC_HW_EPDC_PIGEON_CTRL0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_CTRL0_RD()      (HW_EPDC_HW_EPDC_PIGEON_CTRL0.U)
#define HW_EPDC_HW_EPDC_PIGEON_CTRL0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_CTRL0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_CTRL0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_CTRL0_WR(HW_EPDC_HW_EPDC_PIGEON_CTRL0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_CTRL0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_CTRL0_WR(HW_EPDC_HW_EPDC_PIGEON_CTRL0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_CTRL0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_CTRL0_WR(HW_EPDC_HW_EPDC_PIGEON_CTRL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_CTRL0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_CTRL0, field FD_PERIOD[11:0] (RW)
 *
 * period of line counter during FD phase
 */

#define BP_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD.
#define BM_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD      (0x00000fff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD) >> BP_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD.
#define BF_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD) & BM_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FD_PERIOD field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD(v)   (HW_EPDC_HW_EPDC_PIGEON_CTRL0_WR((HW_EPDC_HW_EPDC_PIGEON_CTRL0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD) | BF_EPDC_HW_EPDC_PIGEON_CTRL0_FD_PERIOD(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_CTRL0, field LD_PERIOD[27:16] (RW)
 *
 * period of pclk counter during LD phase
 */

#define BP_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD.
#define BM_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD      (0x0fff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD) >> BP_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD.
#define BF_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD) & BM_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LD_PERIOD field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD(v)   (HW_EPDC_HW_EPDC_PIGEON_CTRL0_WR((HW_EPDC_HW_EPDC_PIGEON_CTRL0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD) | BF_EPDC_HW_EPDC_PIGEON_CTRL0_LD_PERIOD(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_CTRL1 - EPDC Pigeon Mode Control Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_CTRL1 - EPDC Pigeon Mode Control Register 1 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register contains global counter setting for pigeon mode  HW_EPDC_PIGEON_CTRL1: 0x390
 * HW_EPDC_PIGEON_CTRL1_SET: 0x394  HW_EPDC_PIGEON_CTRL1_CLR: 0x398  HW_EPDC_PIGEON_CTRL1_TOG: 0x39C
 * This register houses general purpose timing adjustment registers   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_pigeon_ctrl1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_ctrl1_bitfields
    {
        unsigned FRAME_CNT_PERIOD : 12; //!< [11:0] period of frame counter
        unsigned RESERVED0 : 4; //!< [15:12] Reserved.
        unsigned FRAME_CNT_CYCLES : 12; //!< [27:16] max cycles of frame counter
        unsigned RESERVED1 : 4; //!< [31:28] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_ctrl1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_CTRL1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_CTRL1_ADDR      (REGS_EPDC_BASE + 0x390)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_CTRL1           (*(volatile hw_epdc_hw_epdc_pigeon_ctrl1_t *) HW_EPDC_HW_EPDC_PIGEON_CTRL1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_CTRL1_RD()      (HW_EPDC_HW_EPDC_PIGEON_CTRL1.U)
#define HW_EPDC_HW_EPDC_PIGEON_CTRL1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_CTRL1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_CTRL1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_CTRL1_WR(HW_EPDC_HW_EPDC_PIGEON_CTRL1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_CTRL1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_CTRL1_WR(HW_EPDC_HW_EPDC_PIGEON_CTRL1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_CTRL1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_CTRL1_WR(HW_EPDC_HW_EPDC_PIGEON_CTRL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_CTRL1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_CTRL1, field FRAME_CNT_PERIOD[11:0] (RW)
 *
 * period of frame counter
 */

#define BP_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD.
#define BM_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD      (0x00000fff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD) >> BP_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD.
#define BF_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD) & BM_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_CNT_PERIOD field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD(v)   (HW_EPDC_HW_EPDC_PIGEON_CTRL1_WR((HW_EPDC_HW_EPDC_PIGEON_CTRL1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD) | BF_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_CTRL1, field FRAME_CNT_CYCLES[27:16] (RW)
 *
 * max cycles of frame counter
 */

#define BP_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES.
#define BM_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES      (0x0fff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES) >> BP_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES.
#define BF_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES) & BM_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_CNT_CYCLES field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES(v)   (HW_EPDC_HW_EPDC_PIGEON_CTRL1_WR((HW_EPDC_HW_EPDC_PIGEON_CTRL1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES) | BF_EPDC_HW_EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_IRQ_MASK1 - EPDC IRQ Mask Register for LUT 0~31
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_IRQ_MASK1 - EPDC IRQ Mask Register for LUT 0~31 (RW)
 *
 * Reset value: 0x00000000
 *
 * Controls masking EPDC LUT complete interrupts  HW_EPDC_IRQ_MASK1: 0x3C0  HW_EPDC_IRQ_MASK1_SET:
 * 0x3C4  HW_EPDC_IRQ_MASK1_CLR: 0x3C8  HW_EPDC_IRQ_MASK1_TOG: 0x3CC  This register controls LUT0~31
 * IRQ masks for EPDC interrupts   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_irq_mask1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_irq_mask1_bitfields
    {
        unsigned LUTN_CMPLT_IRQ_EN : 32; //!< [31:0] LUT0~31 Complete Interrupt Enable
    } B;
} hw_epdc_hw_epdc_irq_mask1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_IRQ_MASK1 register
 */
#define HW_EPDC_HW_EPDC_IRQ_MASK1_ADDR      (REGS_EPDC_BASE + 0x3c0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_IRQ_MASK1           (*(volatile hw_epdc_hw_epdc_irq_mask1_t *) HW_EPDC_HW_EPDC_IRQ_MASK1_ADDR)
#define HW_EPDC_HW_EPDC_IRQ_MASK1_RD()      (HW_EPDC_HW_EPDC_IRQ_MASK1.U)
#define HW_EPDC_HW_EPDC_IRQ_MASK1_WR(v)     (HW_EPDC_HW_EPDC_IRQ_MASK1.U = (v))
#define HW_EPDC_HW_EPDC_IRQ_MASK1_SET(v)    (HW_EPDC_HW_EPDC_IRQ_MASK1_WR(HW_EPDC_HW_EPDC_IRQ_MASK1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_IRQ_MASK1_CLR(v)    (HW_EPDC_HW_EPDC_IRQ_MASK1_WR(HW_EPDC_HW_EPDC_IRQ_MASK1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_IRQ_MASK1_TOG(v)    (HW_EPDC_HW_EPDC_IRQ_MASK1_WR(HW_EPDC_HW_EPDC_IRQ_MASK1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_IRQ_MASK1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK1, field LUTN_CMPLT_IRQ_EN[31:0] (RW)
 *
 * LUT0~31 Complete Interrupt Enable
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN      (0)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUTN_CMPLT_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK1_WR((HW_EPDC_HW_EPDC_IRQ_MASK1_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_IRQ_MASK2 - EPDC IRQ Mask Register for LUT 32~63
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_IRQ_MASK2 - EPDC IRQ Mask Register for LUT 32~63 (RW)
 *
 * Reset value: 0x00000000
 *
 * Controls masking EPDC LUT complete interrupts  HW_EPDC_IRQ_MASK2: 0x3D0  HW_EPDC_IRQ_MASK2_SET:
 * 0x3D4  HW_EPDC_IRQ_MASK2_CLR: 0x3D8  HW_EPDC_IRQ_MASK2_TOG: 0x3DC  This register controls LUT0~31
 * IRQ masks for EPDC interrupts   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_irq_mask2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_irq_mask2_bitfields
    {
        unsigned LUTN_CMPLT_IRQ_EN : 32; //!< [31:0] LUT32~64 Complete Interrupt Enable
    } B;
} hw_epdc_hw_epdc_irq_mask2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_IRQ_MASK2 register
 */
#define HW_EPDC_HW_EPDC_IRQ_MASK2_ADDR      (REGS_EPDC_BASE + 0x3d0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_IRQ_MASK2           (*(volatile hw_epdc_hw_epdc_irq_mask2_t *) HW_EPDC_HW_EPDC_IRQ_MASK2_ADDR)
#define HW_EPDC_HW_EPDC_IRQ_MASK2_RD()      (HW_EPDC_HW_EPDC_IRQ_MASK2.U)
#define HW_EPDC_HW_EPDC_IRQ_MASK2_WR(v)     (HW_EPDC_HW_EPDC_IRQ_MASK2.U = (v))
#define HW_EPDC_HW_EPDC_IRQ_MASK2_SET(v)    (HW_EPDC_HW_EPDC_IRQ_MASK2_WR(HW_EPDC_HW_EPDC_IRQ_MASK2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_IRQ_MASK2_CLR(v)    (HW_EPDC_HW_EPDC_IRQ_MASK2_WR(HW_EPDC_HW_EPDC_IRQ_MASK2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_IRQ_MASK2_TOG(v)    (HW_EPDC_HW_EPDC_IRQ_MASK2_WR(HW_EPDC_HW_EPDC_IRQ_MASK2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_IRQ_MASK2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK2, field LUTN_CMPLT_IRQ_EN[31:0] (RW)
 *
 * LUT32~64 Complete Interrupt Enable
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN      (0)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUTN_CMPLT_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK2_WR((HW_EPDC_HW_EPDC_IRQ_MASK2_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_IRQ1 - EPDC Interrupt Register for LUT 0~31
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_IRQ1 - EPDC Interrupt Register for LUT 0~31 (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC LUT Completion IRQs. The IRQ for a specific LUT is triggered when it's corrrsponding
 * physical update is competed on the screen. Each interrupt has a corresponding mask register in
 * HW_EPDC_IRQ_MASK  HW_EPDC_IRQ1: 0x3E0  HW_EPDC_IRQ1_SET: 0x3E4  HW_EPDC_IRQ1_CLR: 0x3E8
 * HW_EPDC_IRQ1_TOG: 0x3EC  This register houses the interrupt bits for the LUT Completions
 * EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_irq1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_irq1_bitfields
    {
        unsigned LUTN_CMPLT_IRQ : 32; //!< [31:0] LUT 0~31 Complete Interrupt
    } B;
} hw_epdc_hw_epdc_irq1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_IRQ1 register
 */
#define HW_EPDC_HW_EPDC_IRQ1_ADDR      (REGS_EPDC_BASE + 0x3e0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_IRQ1           (*(volatile hw_epdc_hw_epdc_irq1_t *) HW_EPDC_HW_EPDC_IRQ1_ADDR)
#define HW_EPDC_HW_EPDC_IRQ1_RD()      (HW_EPDC_HW_EPDC_IRQ1.U)
#define HW_EPDC_HW_EPDC_IRQ1_WR(v)     (HW_EPDC_HW_EPDC_IRQ1.U = (v))
#define HW_EPDC_HW_EPDC_IRQ1_SET(v)    (HW_EPDC_HW_EPDC_IRQ1_WR(HW_EPDC_HW_EPDC_IRQ1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_IRQ1_CLR(v)    (HW_EPDC_HW_EPDC_IRQ1_WR(HW_EPDC_HW_EPDC_IRQ1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_IRQ1_TOG(v)    (HW_EPDC_HW_EPDC_IRQ1_WR(HW_EPDC_HW_EPDC_IRQ1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_IRQ1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_IRQ1, field LUTN_CMPLT_IRQ[31:0] (RW)
 *
 * LUT 0~31 Complete Interrupt
 */

#define BP_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ      (0)      //!< Bit position for EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ.
#define BM_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ) >> BP_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ.
#define BF_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ) & BM_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUTN_CMPLT_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ1_WR((HW_EPDC_HW_EPDC_IRQ1_RD() & ~BM_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ) | BF_EPDC_HW_EPDC_IRQ1_LUTN_CMPLT_IRQ(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_IRQ2 - EPDC Interrupt Registerr for LUT 32~63
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_IRQ2 - EPDC Interrupt Registerr for LUT 32~63 (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC LUT Completion IRQs. The IRQ for a specific LUT is triggered when it's corrrsponding
 * physical update is competed on the screen. Each interrupt has a corresponding mask register in
 * HW_EPDC_IRQ_MASK  HW_EPDC_IRQ2: 0x3F0  HW_EPDC_IRQ2_SET: 0x3F4  HW_EPDC_IRQ2_CLR: 0x3F8
 * HW_EPDC_IRQ2_TOG: 0x3FC  This register houses the interrupt bits for the LUT Completions
 * EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_irq2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_irq2_bitfields
    {
        unsigned LUTN_CMPLT_IRQ : 32; //!< [31:0] LUT 32~64 Complete Interrupt
    } B;
} hw_epdc_hw_epdc_irq2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_IRQ2 register
 */
#define HW_EPDC_HW_EPDC_IRQ2_ADDR      (REGS_EPDC_BASE + 0x3f0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_IRQ2           (*(volatile hw_epdc_hw_epdc_irq2_t *) HW_EPDC_HW_EPDC_IRQ2_ADDR)
#define HW_EPDC_HW_EPDC_IRQ2_RD()      (HW_EPDC_HW_EPDC_IRQ2.U)
#define HW_EPDC_HW_EPDC_IRQ2_WR(v)     (HW_EPDC_HW_EPDC_IRQ2.U = (v))
#define HW_EPDC_HW_EPDC_IRQ2_SET(v)    (HW_EPDC_HW_EPDC_IRQ2_WR(HW_EPDC_HW_EPDC_IRQ2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_IRQ2_CLR(v)    (HW_EPDC_HW_EPDC_IRQ2_WR(HW_EPDC_HW_EPDC_IRQ2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_IRQ2_TOG(v)    (HW_EPDC_HW_EPDC_IRQ2_WR(HW_EPDC_HW_EPDC_IRQ2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_IRQ2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_IRQ2, field LUTN_CMPLT_IRQ[31:0] (RW)
 *
 * LUT 32~64 Complete Interrupt
 */

#define BP_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ      (0)      //!< Bit position for EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ.
#define BM_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ) >> BP_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ.
#define BF_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ) & BM_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUTN_CMPLT_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ2_WR((HW_EPDC_HW_EPDC_IRQ2_RD() & ~BM_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ) | BF_EPDC_HW_EPDC_IRQ2_LUTN_CMPLT_IRQ(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_IRQ_MASK - EPDC IRQ Mask Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_IRQ_MASK - EPDC IRQ Mask Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Controls masking for all EPDC interrupts  HW_EPDC_IRQ_MASK: 0x400  HW_EPDC_IRQ_MASK_SET: 0x404
 * HW_EPDC_IRQ_MASK_CLR: 0x408  HW_EPDC_IRQ_MASK_TOG: 0x40C  This register controls IRQ masks for
 * all EPDC interrupts   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_irq_mask
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_irq_mask_bitfields
    {
        unsigned RESERVED0 : 16; //!< [15:0] Reserved.
        unsigned WB_CMPLT_IRQ_EN : 1; //!< [16] Enable WB complete interrupt
        unsigned COL_IRQ_EN : 1; //!< [17] Enable collision detection interrupts for all LUTs
        unsigned TCE_UNDERRUN_IRQ_EN : 1; //!< [18] Enable pixel FIFO under-run condition detection.
        unsigned FRAME_END_IRQ_EN : 1; //!< [19] If this bit is set, EPDC will assert the current frame end interrupt. This irq is only available during updating period.
        unsigned BUS_ERROR_IRQ_EN : 1; //!< [20] Enable AXI BUS ERROR interrupt detection.
        unsigned TCE_IDLE_IRQ_EN : 1; //!< [21] Enable TCE Idle interrupt detection.
        unsigned UPD_DONE_IRQ_EN : 1; //!< [22] Enable UPD complete interrupt
        unsigned PWR_IRQ_EN : 1; //!< [23] Enable power interrupt
        unsigned RESERVED1 : 8; //!< [31:24] Reserved.
    } B;
} hw_epdc_hw_epdc_irq_mask_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_IRQ_MASK register
 */
#define HW_EPDC_HW_EPDC_IRQ_MASK_ADDR      (REGS_EPDC_BASE + 0x400)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_IRQ_MASK           (*(volatile hw_epdc_hw_epdc_irq_mask_t *) HW_EPDC_HW_EPDC_IRQ_MASK_ADDR)
#define HW_EPDC_HW_EPDC_IRQ_MASK_RD()      (HW_EPDC_HW_EPDC_IRQ_MASK.U)
#define HW_EPDC_HW_EPDC_IRQ_MASK_WR(v)     (HW_EPDC_HW_EPDC_IRQ_MASK.U = (v))
#define HW_EPDC_HW_EPDC_IRQ_MASK_SET(v)    (HW_EPDC_HW_EPDC_IRQ_MASK_WR(HW_EPDC_HW_EPDC_IRQ_MASK_RD() |  (v)))
#define HW_EPDC_HW_EPDC_IRQ_MASK_CLR(v)    (HW_EPDC_HW_EPDC_IRQ_MASK_WR(HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_IRQ_MASK_TOG(v)    (HW_EPDC_HW_EPDC_IRQ_MASK_WR(HW_EPDC_HW_EPDC_IRQ_MASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_IRQ_MASK bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK, field WB_CMPLT_IRQ_EN[16] (RW)
 *
 * Enable WB complete interrupt
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN      (16)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN      (0x00010000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WB_CMPLT_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK_WR((HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK, field COL_IRQ_EN[17] (RW)
 *
 * Enable collision detection interrupts for all LUTs
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN      (17)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN      (0x00020000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COL_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK_WR((HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK_COL_IRQ_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK, field TCE_UNDERRUN_IRQ_EN[18] (RW)
 *
 * Enable pixel FIFO under-run condition detection.
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN      (18)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN      (0x00040000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCE_UNDERRUN_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK_WR((HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK, field FRAME_END_IRQ_EN[19] (RW)
 *
 * If this bit is set, EPDC will assert the current frame end interrupt. This irq is only available
 * during updating period.
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN      (19)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN      (0x00080000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_END_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK_WR((HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK_FRAME_END_IRQ_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK, field BUS_ERROR_IRQ_EN[20] (RW)
 *
 * Enable AXI BUS ERROR interrupt detection.
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN      (20)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN      (0x00100000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUS_ERROR_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK_WR((HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK, field TCE_IDLE_IRQ_EN[21] (RW)
 *
 * Enable TCE Idle interrupt detection.
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN      (21)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN      (0x00200000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCE_IDLE_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK_WR((HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK, field UPD_DONE_IRQ_EN[22] (RW)
 *
 * Enable UPD complete interrupt
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN      (22)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN      (0x00400000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPD_DONE_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK_WR((HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK_UPD_DONE_IRQ_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ_MASK, field PWR_IRQ_EN[23] (RW)
 *
 * Enable power interrupt
 */

#define BP_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN      (23)      //!< Bit position for EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN.
#define BM_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN      (0x00800000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN.

//! @brief Get value of EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN from a register value.
#define BG_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN) >> BP_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN.
#define BF_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN) & BM_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PWR_IRQ_EN field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN(v)   (HW_EPDC_HW_EPDC_IRQ_MASK_WR((HW_EPDC_HW_EPDC_IRQ_MASK_RD() & ~BM_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN) | BF_EPDC_HW_EPDC_IRQ_MASK_PWR_IRQ_EN(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_IRQ - EPDC Interrupt Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_IRQ - EPDC Interrupt Register (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC LUT Completion IRQs. The IRQ for a specific LUT is triggered when it's corrrsponding
 * physical update is competed on the screen. Each interrupt has a corresponding mask register in
 * HW_EPDC_IRQ_MASK  HW_EPDC_IRQ: 0x420  HW_EPDC_IRQ_SET: 0x424  HW_EPDC_IRQ_CLR: 0x428
 * HW_EPDC_IRQ_TOG: 0x42C  This register houses the interrupt bits for the LUT Completions   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_irq
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_irq_bitfields
    {
        unsigned RESERVED0 : 16; //!< [15:0] Reserved.
        unsigned WB_CMPLT_IRQ : 1; //!< [16] Working buffer process complete Interrupt
        unsigned LUT_COL_IRQ : 1; //!< [17] Collision detection interrupt. Check HW_EPDC_STATUS_COL.
        unsigned TCE_UNDERRUN_IRQ : 1; //!< [18] Interrupt to signify that a pixel FIFO under-run has occured.
        unsigned FRAME_END_IRQ : 1; //!< [19] Interrupt to indicate EPDC has completed the current frame and is in the vertical blanking period.
        unsigned BUS_ERROR_IRQ : 1; //!< [20] Interrupt to indicate AXI BUS error occurs.
        unsigned TCE_IDLE_IRQ : 1; //!< [21] Interrupt to indicate that the TCE has completed TFT frame scans and is in an idle state.
        unsigned UPD_DONE_IRQ : 1; //!< [22] Working buffer process complete Interrupt
        unsigned PWR_IRQ : 1; //!< [23] Power Interrupt
        unsigned RESERVED1 : 8; //!< [31:24] Reserved.
    } B;
} hw_epdc_hw_epdc_irq_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_IRQ register
 */
#define HW_EPDC_HW_EPDC_IRQ_ADDR      (REGS_EPDC_BASE + 0x420)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_IRQ           (*(volatile hw_epdc_hw_epdc_irq_t *) HW_EPDC_HW_EPDC_IRQ_ADDR)
#define HW_EPDC_HW_EPDC_IRQ_RD()      (HW_EPDC_HW_EPDC_IRQ.U)
#define HW_EPDC_HW_EPDC_IRQ_WR(v)     (HW_EPDC_HW_EPDC_IRQ.U = (v))
#define HW_EPDC_HW_EPDC_IRQ_SET(v)    (HW_EPDC_HW_EPDC_IRQ_WR(HW_EPDC_HW_EPDC_IRQ_RD() |  (v)))
#define HW_EPDC_HW_EPDC_IRQ_CLR(v)    (HW_EPDC_HW_EPDC_IRQ_WR(HW_EPDC_HW_EPDC_IRQ_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_IRQ_TOG(v)    (HW_EPDC_HW_EPDC_IRQ_WR(HW_EPDC_HW_EPDC_IRQ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_IRQ bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_IRQ, field WB_CMPLT_IRQ[16] (RW)
 *
 * Working buffer process complete Interrupt
 */

#define BP_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ      (16)      //!< Bit position for EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ.
#define BM_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ      (0x00010000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ) >> BP_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ.
#define BF_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ) & BM_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WB_CMPLT_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ_WR((HW_EPDC_HW_EPDC_IRQ_RD() & ~BM_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ) | BF_EPDC_HW_EPDC_IRQ_WB_CMPLT_IRQ(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ, field LUT_COL_IRQ[17] (RW)
 *
 * Collision detection interrupt. Check HW_EPDC_STATUS_COL.
 */

#define BP_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ      (17)      //!< Bit position for EPDC_HW_EPDC_IRQ_LUT_COL_IRQ.
#define BM_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ      (0x00020000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_LUT_COL_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ_LUT_COL_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ) >> BP_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_LUT_COL_IRQ.
#define BF_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ) & BM_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_COL_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ_WR((HW_EPDC_HW_EPDC_IRQ_RD() & ~BM_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ) | BF_EPDC_HW_EPDC_IRQ_LUT_COL_IRQ(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ, field TCE_UNDERRUN_IRQ[18] (RW)
 *
 * Interrupt to signify that a pixel FIFO under-run has occured.
 */

#define BP_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ      (18)      //!< Bit position for EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ.
#define BM_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ      (0x00040000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ) >> BP_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ.
#define BF_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ) & BM_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCE_UNDERRUN_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ_WR((HW_EPDC_HW_EPDC_IRQ_RD() & ~BM_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ) | BF_EPDC_HW_EPDC_IRQ_TCE_UNDERRUN_IRQ(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ, field FRAME_END_IRQ[19] (RW)
 *
 * Interrupt to indicate EPDC has completed the current frame and is in the vertical blanking
 * period.
 */

#define BP_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ      (19)      //!< Bit position for EPDC_HW_EPDC_IRQ_FRAME_END_IRQ.
#define BM_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ      (0x00080000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_FRAME_END_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ_FRAME_END_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ) >> BP_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_FRAME_END_IRQ.
#define BF_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ) & BM_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_END_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ_WR((HW_EPDC_HW_EPDC_IRQ_RD() & ~BM_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ) | BF_EPDC_HW_EPDC_IRQ_FRAME_END_IRQ(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ, field BUS_ERROR_IRQ[20] (RW)
 *
 * Interrupt to indicate AXI BUS error occurs.
 */

#define BP_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ      (20)      //!< Bit position for EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ.
#define BM_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ      (0x00100000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ) >> BP_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ.
#define BF_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ) & BM_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUS_ERROR_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ_WR((HW_EPDC_HW_EPDC_IRQ_RD() & ~BM_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ) | BF_EPDC_HW_EPDC_IRQ_BUS_ERROR_IRQ(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ, field TCE_IDLE_IRQ[21] (RW)
 *
 * Interrupt to indicate that the TCE has completed TFT frame scans and is in an idle state.
 */

#define BP_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ      (21)      //!< Bit position for EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ.
#define BM_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ      (0x00200000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ) >> BP_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ.
#define BF_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ) & BM_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCE_IDLE_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ_WR((HW_EPDC_HW_EPDC_IRQ_RD() & ~BM_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ) | BF_EPDC_HW_EPDC_IRQ_TCE_IDLE_IRQ(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ, field UPD_DONE_IRQ[22] (RW)
 *
 * Working buffer process complete Interrupt
 */

#define BP_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ      (22)      //!< Bit position for EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ.
#define BM_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ      (0x00400000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ) >> BP_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ.
#define BF_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ) & BM_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPD_DONE_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ_WR((HW_EPDC_HW_EPDC_IRQ_RD() & ~BM_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ) | BF_EPDC_HW_EPDC_IRQ_UPD_DONE_IRQ(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_IRQ, field PWR_IRQ[23] (RW)
 *
 * Power Interrupt
 */

#define BP_EPDC_HW_EPDC_IRQ_PWR_IRQ      (23)      //!< Bit position for EPDC_HW_EPDC_IRQ_PWR_IRQ.
#define BM_EPDC_HW_EPDC_IRQ_PWR_IRQ      (0x00800000)  //!< Bit mask for EPDC_HW_EPDC_IRQ_PWR_IRQ.

//! @brief Get value of EPDC_HW_EPDC_IRQ_PWR_IRQ from a register value.
#define BG_EPDC_HW_EPDC_IRQ_PWR_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_IRQ_PWR_IRQ) >> BP_EPDC_HW_EPDC_IRQ_PWR_IRQ)

//! @brief Format value for bitfield EPDC_HW_EPDC_IRQ_PWR_IRQ.
#define BF_EPDC_HW_EPDC_IRQ_PWR_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_IRQ_PWR_IRQ) & BM_EPDC_HW_EPDC_IRQ_PWR_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PWR_IRQ field to a new value.
#define BW_EPDC_HW_EPDC_IRQ_PWR_IRQ(v)   (HW_EPDC_HW_EPDC_IRQ_WR((HW_EPDC_HW_EPDC_IRQ_RD() & ~BM_EPDC_HW_EPDC_IRQ_PWR_IRQ) | BF_EPDC_HW_EPDC_IRQ_PWR_IRQ(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_STATUS_LUTS1 - EPDC Status Register - LUTs
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_STATUS_LUTS1 - EPDC Status Register - LUTs (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Status Register - LUTS 0~31  HW_EPDC_STATUS_LUTS1: 0x440  HW_EPDC_STATUS_LUTS1_SET: 0x444
 * HW_EPDC_STATUS_LUTS1_CLR: 0x448  HW_EPDC_STATUS_LUTS1_TOG: 0x44C    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_status_luts1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_status_luts1_bitfields
    {
        unsigned LUTN_STS : 32; //!< [31:0] LUT 0~31 Status : 1=ACTIVE, 0=IDLE
    } B;
} hw_epdc_hw_epdc_status_luts1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_STATUS_LUTS1 register
 */
#define HW_EPDC_HW_EPDC_STATUS_LUTS1_ADDR      (REGS_EPDC_BASE + 0x440)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_STATUS_LUTS1           (*(volatile hw_epdc_hw_epdc_status_luts1_t *) HW_EPDC_HW_EPDC_STATUS_LUTS1_ADDR)
#define HW_EPDC_HW_EPDC_STATUS_LUTS1_RD()      (HW_EPDC_HW_EPDC_STATUS_LUTS1.U)
#define HW_EPDC_HW_EPDC_STATUS_LUTS1_WR(v)     (HW_EPDC_HW_EPDC_STATUS_LUTS1.U = (v))
#define HW_EPDC_HW_EPDC_STATUS_LUTS1_SET(v)    (HW_EPDC_HW_EPDC_STATUS_LUTS1_WR(HW_EPDC_HW_EPDC_STATUS_LUTS1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_STATUS_LUTS1_CLR(v)    (HW_EPDC_HW_EPDC_STATUS_LUTS1_WR(HW_EPDC_HW_EPDC_STATUS_LUTS1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_STATUS_LUTS1_TOG(v)    (HW_EPDC_HW_EPDC_STATUS_LUTS1_WR(HW_EPDC_HW_EPDC_STATUS_LUTS1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_STATUS_LUTS1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_STATUS_LUTS1, field LUTN_STS[31:0] (RO)
 *
 * LUT 0~31 Status : 1=ACTIVE, 0=IDLE
 */

#define BP_EPDC_HW_EPDC_STATUS_LUTS1_LUTN_STS      (0)      //!< Bit position for EPDC_HW_EPDC_STATUS_LUTS1_LUTN_STS.
#define BM_EPDC_HW_EPDC_STATUS_LUTS1_LUTN_STS      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_STATUS_LUTS1_LUTN_STS.

//! @brief Get value of EPDC_HW_EPDC_STATUS_LUTS1_LUTN_STS from a register value.
#define BG_EPDC_HW_EPDC_STATUS_LUTS1_LUTN_STS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_LUTS1_LUTN_STS) >> BP_EPDC_HW_EPDC_STATUS_LUTS1_LUTN_STS)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_STATUS_LUTS2 - EPDC Status Register - LUTs
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_STATUS_LUTS2 - EPDC Status Register - LUTs (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Status Register - LUTS 0~31  HW_EPDC_STATUS_LUTS2: 0x450  HW_EPDC_STATUS_LUTS2_SET: 0x454
 * HW_EPDC_STATUS_LUTS2_CLR: 0x458  HW_EPDC_STATUS_LUTS2_TOG: 0x45C    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_status_luts2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_status_luts2_bitfields
    {
        unsigned LUTN_STS : 32; //!< [31:0] LUT 32~63 Status : 1=ACTIVE, 0=IDLE
    } B;
} hw_epdc_hw_epdc_status_luts2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_STATUS_LUTS2 register
 */
#define HW_EPDC_HW_EPDC_STATUS_LUTS2_ADDR      (REGS_EPDC_BASE + 0x450)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_STATUS_LUTS2           (*(volatile hw_epdc_hw_epdc_status_luts2_t *) HW_EPDC_HW_EPDC_STATUS_LUTS2_ADDR)
#define HW_EPDC_HW_EPDC_STATUS_LUTS2_RD()      (HW_EPDC_HW_EPDC_STATUS_LUTS2.U)
#define HW_EPDC_HW_EPDC_STATUS_LUTS2_WR(v)     (HW_EPDC_HW_EPDC_STATUS_LUTS2.U = (v))
#define HW_EPDC_HW_EPDC_STATUS_LUTS2_SET(v)    (HW_EPDC_HW_EPDC_STATUS_LUTS2_WR(HW_EPDC_HW_EPDC_STATUS_LUTS2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_STATUS_LUTS2_CLR(v)    (HW_EPDC_HW_EPDC_STATUS_LUTS2_WR(HW_EPDC_HW_EPDC_STATUS_LUTS2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_STATUS_LUTS2_TOG(v)    (HW_EPDC_HW_EPDC_STATUS_LUTS2_WR(HW_EPDC_HW_EPDC_STATUS_LUTS2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_STATUS_LUTS2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_STATUS_LUTS2, field LUTN_STS[31:0] (RO)
 *
 * LUT 32~63 Status : 1=ACTIVE, 0=IDLE
 */

#define BP_EPDC_HW_EPDC_STATUS_LUTS2_LUTN_STS      (0)      //!< Bit position for EPDC_HW_EPDC_STATUS_LUTS2_LUTN_STS.
#define BM_EPDC_HW_EPDC_STATUS_LUTS2_LUTN_STS      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_STATUS_LUTS2_LUTN_STS.

//! @brief Get value of EPDC_HW_EPDC_STATUS_LUTS2_LUTN_STS from a register value.
#define BG_EPDC_HW_EPDC_STATUS_LUTS2_LUTN_STS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_LUTS2_LUTN_STS) >> BP_EPDC_HW_EPDC_STATUS_LUTS2_LUTN_STS)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_STATUS_NEXTLUT - EPDC Status Register - Next Available LUT
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_STATUS_NEXTLUT - EPDC Status Register - Next Available LUT (RW)
 *
 * Reset value: 0x0000013f
 *
 * Holds value of next available LUT. Can be used for fast LUT assignment. This value can be read
 * and then used in an update command as part of the HW_EPDC_UPD_CTRL register write  The DIGCTL
 * Status Register provides a read-only view to various input conditions and internal states.
 * EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_status_nextlut
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_status_nextlut_bitfields
    {
        unsigned NEXT_LUT : 6; //!< [5:0] Next available LUT value
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned NEXT_LUT_VALID : 1; //!< [8] This bitfield can be used to check against a LUTs full condition
        unsigned RESERVED1 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_status_nextlut_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_STATUS_NEXTLUT register
 */
#define HW_EPDC_HW_EPDC_STATUS_NEXTLUT_ADDR      (REGS_EPDC_BASE + 0x460)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_STATUS_NEXTLUT           (*(volatile hw_epdc_hw_epdc_status_nextlut_t *) HW_EPDC_HW_EPDC_STATUS_NEXTLUT_ADDR)
#define HW_EPDC_HW_EPDC_STATUS_NEXTLUT_RD()      (HW_EPDC_HW_EPDC_STATUS_NEXTLUT.U)
#define HW_EPDC_HW_EPDC_STATUS_NEXTLUT_WR(v)     (HW_EPDC_HW_EPDC_STATUS_NEXTLUT.U = (v))
#define HW_EPDC_HW_EPDC_STATUS_NEXTLUT_SET(v)    (HW_EPDC_HW_EPDC_STATUS_NEXTLUT_WR(HW_EPDC_HW_EPDC_STATUS_NEXTLUT_RD() |  (v)))
#define HW_EPDC_HW_EPDC_STATUS_NEXTLUT_CLR(v)    (HW_EPDC_HW_EPDC_STATUS_NEXTLUT_WR(HW_EPDC_HW_EPDC_STATUS_NEXTLUT_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_STATUS_NEXTLUT_TOG(v)    (HW_EPDC_HW_EPDC_STATUS_NEXTLUT_WR(HW_EPDC_HW_EPDC_STATUS_NEXTLUT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_STATUS_NEXTLUT bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_STATUS_NEXTLUT, field NEXT_LUT[5:0] (RO)
 *
 * Next available LUT value
 */

#define BP_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT      (0)      //!< Bit position for EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT.
#define BM_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT      (0x0000003f)  //!< Bit mask for EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT.

//! @brief Get value of EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT from a register value.
#define BG_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT) >> BP_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT)

/* --- Register HW_EPDC_HW_EPDC_STATUS_NEXTLUT, field NEXT_LUT_VALID[8] (RO)
 *
 * This bitfield can be used to check against a LUTs full condition
 */

#define BP_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID      (8)      //!< Bit position for EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID.
#define BM_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID      (0x00000100)  //!< Bit mask for EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID.

//! @brief Get value of EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID from a register value.
#define BG_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID) >> BP_EPDC_HW_EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_STATUS_COL1 - EPDC LUT Collision Status
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_STATUS_COL1 - EPDC LUT Collision Status (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC LUT Collision Status Register and works in conjuction with HW_EPDC_IRQ[LUT_COL_IRQ]. When a
 * collision occurs the interrupt is set and all status bits are set for LUTs which were touched by
 * the collision. It does not set the bit for the LUT which caused the collision. There is a single
 * interrupt mask which is used to control all the IRQ bits in this register (in HW_EPDC_IRQ_MASK).
 * Note that a collision caused by a LUT which was set-up for no collision detection will not
 * trigger any collision LUT IRQ or status update. Note that clearing the interrupt bit
 * HW_EPDC_IRQ[LUT_COL_IRQ] clears this register  HW_EPDC_STATUS_COL1: 0x480
 * HW_EPDC_STATUS_COL1_SET: 0x484  HW_EPDC_STATUS_COL1_CLR: 0x488  HW_EPDC_STATUS_COL1_TOG: 0x48C
 * This register houses the status bits for the LUT Collisions   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_status_col1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_status_col1_bitfields
    {
        unsigned LUTN_COL_STS : 32; //!< [31:0] LUTn Collision Status
    } B;
} hw_epdc_hw_epdc_status_col1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_STATUS_COL1 register
 */
#define HW_EPDC_HW_EPDC_STATUS_COL1_ADDR      (REGS_EPDC_BASE + 0x480)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_STATUS_COL1           (*(volatile hw_epdc_hw_epdc_status_col1_t *) HW_EPDC_HW_EPDC_STATUS_COL1_ADDR)
#define HW_EPDC_HW_EPDC_STATUS_COL1_RD()      (HW_EPDC_HW_EPDC_STATUS_COL1.U)
#define HW_EPDC_HW_EPDC_STATUS_COL1_WR(v)     (HW_EPDC_HW_EPDC_STATUS_COL1.U = (v))
#define HW_EPDC_HW_EPDC_STATUS_COL1_SET(v)    (HW_EPDC_HW_EPDC_STATUS_COL1_WR(HW_EPDC_HW_EPDC_STATUS_COL1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_STATUS_COL1_CLR(v)    (HW_EPDC_HW_EPDC_STATUS_COL1_WR(HW_EPDC_HW_EPDC_STATUS_COL1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_STATUS_COL1_TOG(v)    (HW_EPDC_HW_EPDC_STATUS_COL1_WR(HW_EPDC_HW_EPDC_STATUS_COL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_STATUS_COL1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_STATUS_COL1, field LUTN_COL_STS[31:0] (RO)
 *
 * LUTn Collision Status
 */

#define BP_EPDC_HW_EPDC_STATUS_COL1_LUTN_COL_STS      (0)      //!< Bit position for EPDC_HW_EPDC_STATUS_COL1_LUTN_COL_STS.
#define BM_EPDC_HW_EPDC_STATUS_COL1_LUTN_COL_STS      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_STATUS_COL1_LUTN_COL_STS.

//! @brief Get value of EPDC_HW_EPDC_STATUS_COL1_LUTN_COL_STS from a register value.
#define BG_EPDC_HW_EPDC_STATUS_COL1_LUTN_COL_STS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_COL1_LUTN_COL_STS) >> BP_EPDC_HW_EPDC_STATUS_COL1_LUTN_COL_STS)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_STATUS_COL2 - EPDC LUT Collision Status
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_STATUS_COL2 - EPDC LUT Collision Status (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC LUT Collision Status Register and works in conjuction with HW_EPDC_IRQ[LUT_COL_IRQ]. When a
 * collision occurs the interrupt is set and all status bits are set for LUTs which were touched by
 * the collision. It does not set the bit for the LUT which caused the collision. There is a single
 * interrupt mask which is used to control all the IRQ bits in this register (in HW_EPDC_IRQ_MASK).
 * Note that a collision caused by a LUT which was set-up for no collision detection will not
 * trigger any collision LUT IRQ or status update. Note that clearing the interrupt bit
 * HW_EPDC_IRQ[LUT_COL_IRQ] clears this register  HW_EPDC_STATUS_COL2: 0x490
 * HW_EPDC_STATUS_COL2_SET: 0x494  HW_EPDC_STATUS_COL2_CLR: 0x498  HW_EPDC_STATUS_COL2_TOG: 0x49C
 * This register houses the status bits for the LUT Collisions   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_status_col2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_status_col2_bitfields
    {
        unsigned LUTN_COL_STS : 32; //!< [31:0] LUTn Collision Status
    } B;
} hw_epdc_hw_epdc_status_col2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_STATUS_COL2 register
 */
#define HW_EPDC_HW_EPDC_STATUS_COL2_ADDR      (REGS_EPDC_BASE + 0x490)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_STATUS_COL2           (*(volatile hw_epdc_hw_epdc_status_col2_t *) HW_EPDC_HW_EPDC_STATUS_COL2_ADDR)
#define HW_EPDC_HW_EPDC_STATUS_COL2_RD()      (HW_EPDC_HW_EPDC_STATUS_COL2.U)
#define HW_EPDC_HW_EPDC_STATUS_COL2_WR(v)     (HW_EPDC_HW_EPDC_STATUS_COL2.U = (v))
#define HW_EPDC_HW_EPDC_STATUS_COL2_SET(v)    (HW_EPDC_HW_EPDC_STATUS_COL2_WR(HW_EPDC_HW_EPDC_STATUS_COL2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_STATUS_COL2_CLR(v)    (HW_EPDC_HW_EPDC_STATUS_COL2_WR(HW_EPDC_HW_EPDC_STATUS_COL2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_STATUS_COL2_TOG(v)    (HW_EPDC_HW_EPDC_STATUS_COL2_WR(HW_EPDC_HW_EPDC_STATUS_COL2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_STATUS_COL2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_STATUS_COL2, field LUTN_COL_STS[31:0] (RO)
 *
 * LUTn Collision Status
 */

#define BP_EPDC_HW_EPDC_STATUS_COL2_LUTN_COL_STS      (0)      //!< Bit position for EPDC_HW_EPDC_STATUS_COL2_LUTN_COL_STS.
#define BM_EPDC_HW_EPDC_STATUS_COL2_LUTN_COL_STS      (0xffffffff)  //!< Bit mask for EPDC_HW_EPDC_STATUS_COL2_LUTN_COL_STS.

//! @brief Get value of EPDC_HW_EPDC_STATUS_COL2_LUTN_COL_STS from a register value.
#define BG_EPDC_HW_EPDC_STATUS_COL2_LUTN_COL_STS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_COL2_LUTN_COL_STS) >> BP_EPDC_HW_EPDC_STATUS_COL2_LUTN_COL_STS)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_STATUS - EPDC General Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_STATUS - EPDC General Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Register to house non LUT specific status bits  HW_EPDC_STATUS: 0x4A0  HW_EPDC_STATUS_SET: 0x4A4
 * HW_EPDC_STATUS_CLR: 0x4A8  HW_EPDC_STATUS_TOG: 0x4AC  This register houses general status bits
 * EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_status
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_status_bitfields
    {
        unsigned WB_BUSY : 1; //!< [0] Working buffer process is busy cannot accept new update requests. When WB_BUSY is 1, software should wait for the WB_CMPLT_IRQ interrupt. When this interrupt occurs WB_BUSY is cleared immediately. This is a real-time status of the process.
        unsigned LUTS_BUSY : 1; //!< [1] Provides a summary status of LUTs. 1= All LUTs are busy, 0= LUTs are available
        unsigned LUTS_UNDERRUN : 1; //!< [2] Provides a summary status of LUT fill. 1= not enough time for active luts read during blanking period before vscan_holdoff. 0=complete all active luts fill during blanking period before VSCAN_HOLDOFF.
        unsigned RESERVED0 : 5; //!< [7:3] Reserved.
        unsigned HISTOGRAM_NP : 5; //!< [12:8] Indicates which histogram matched the processed bitmap(NP). Bit[0] indicates that the bitmap pixels were fully contained within the HIST1 (single color ) histogram. Bit[1] indicates that the bitmap pixels were fully contained within the HIST2 (black / white ) histogram. Bit[2] indicates that the bitmap pixels were fully contained within the HIST4 (2-bit grayscale) histogram. Bit[3] indicates that the bitmap pixels were fully contained within the HIST8 (3-bit grayscale) histogram. Bit[4] indicates that the bitmap pixels were fully contained within the HIST16 (4-bit grayscale) histogram.
        unsigned RESERVED1 : 3; //!< [15:13] Reserved.
        unsigned HISTOGRAM_CP : 5; //!< [20:16] Indicates which histogram matched the existing bitmap(CP). Bit[0] indicates that the bitmap pixels were fully contained within the HIST1 (single color ) histogram. Bit[1] indicates that the bitmap pixels were fully contained within the HIST2 (black / white ) histogram. Bit[2] indicates that the bitmap pixels were fully contained within the HIST4 (2-bit grayscale) histogram. Bit[3] indicates that the bitmap pixels were fully contained within the HIST8 (3-bit grayscale) histogram. Bit[4] indicates that the bitmap pixels were fully contained within the HIST16 (4-bit grayscale) histogram.
        unsigned RESERVED2 : 11; //!< [31:21] Reserved.
    } B;
} hw_epdc_hw_epdc_status_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_STATUS register
 */
#define HW_EPDC_HW_EPDC_STATUS_ADDR      (REGS_EPDC_BASE + 0x4a0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_STATUS           (*(volatile hw_epdc_hw_epdc_status_t *) HW_EPDC_HW_EPDC_STATUS_ADDR)
#define HW_EPDC_HW_EPDC_STATUS_RD()      (HW_EPDC_HW_EPDC_STATUS.U)
#define HW_EPDC_HW_EPDC_STATUS_WR(v)     (HW_EPDC_HW_EPDC_STATUS.U = (v))
#define HW_EPDC_HW_EPDC_STATUS_SET(v)    (HW_EPDC_HW_EPDC_STATUS_WR(HW_EPDC_HW_EPDC_STATUS_RD() |  (v)))
#define HW_EPDC_HW_EPDC_STATUS_CLR(v)    (HW_EPDC_HW_EPDC_STATUS_WR(HW_EPDC_HW_EPDC_STATUS_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_STATUS_TOG(v)    (HW_EPDC_HW_EPDC_STATUS_WR(HW_EPDC_HW_EPDC_STATUS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_STATUS bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_STATUS, field WB_BUSY[0] (RO)
 *
 * Working buffer process is busy cannot accept new update requests. When WB_BUSY is 1, software
 * should wait for the WB_CMPLT_IRQ interrupt. When this interrupt occurs WB_BUSY is cleared
 * immediately. This is a real-time status of the process.
 */

#define BP_EPDC_HW_EPDC_STATUS_WB_BUSY      (0)      //!< Bit position for EPDC_HW_EPDC_STATUS_WB_BUSY.
#define BM_EPDC_HW_EPDC_STATUS_WB_BUSY      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_STATUS_WB_BUSY.

//! @brief Get value of EPDC_HW_EPDC_STATUS_WB_BUSY from a register value.
#define BG_EPDC_HW_EPDC_STATUS_WB_BUSY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_WB_BUSY) >> BP_EPDC_HW_EPDC_STATUS_WB_BUSY)

/* --- Register HW_EPDC_HW_EPDC_STATUS, field LUTS_BUSY[1] (RO)
 *
 * Provides a summary status of LUTs. 1= All LUTs are busy, 0= LUTs are available
 */

#define BP_EPDC_HW_EPDC_STATUS_LUTS_BUSY      (1)      //!< Bit position for EPDC_HW_EPDC_STATUS_LUTS_BUSY.
#define BM_EPDC_HW_EPDC_STATUS_LUTS_BUSY      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_STATUS_LUTS_BUSY.

//! @brief Get value of EPDC_HW_EPDC_STATUS_LUTS_BUSY from a register value.
#define BG_EPDC_HW_EPDC_STATUS_LUTS_BUSY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_LUTS_BUSY) >> BP_EPDC_HW_EPDC_STATUS_LUTS_BUSY)

/* --- Register HW_EPDC_HW_EPDC_STATUS, field LUTS_UNDERRUN[2] (RO)
 *
 * Provides a summary status of LUT fill. 1= not enough time for active luts read during blanking
 * period before vscan_holdoff. 0=complete all active luts fill during blanking period before
 * VSCAN_HOLDOFF.
 */

#define BP_EPDC_HW_EPDC_STATUS_LUTS_UNDERRUN      (2)      //!< Bit position for EPDC_HW_EPDC_STATUS_LUTS_UNDERRUN.
#define BM_EPDC_HW_EPDC_STATUS_LUTS_UNDERRUN      (0x00000004)  //!< Bit mask for EPDC_HW_EPDC_STATUS_LUTS_UNDERRUN.

//! @brief Get value of EPDC_HW_EPDC_STATUS_LUTS_UNDERRUN from a register value.
#define BG_EPDC_HW_EPDC_STATUS_LUTS_UNDERRUN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_LUTS_UNDERRUN) >> BP_EPDC_HW_EPDC_STATUS_LUTS_UNDERRUN)

/* --- Register HW_EPDC_HW_EPDC_STATUS, field HISTOGRAM_NP[12:8] (RW)
 *
 * Indicates which histogram matched the processed bitmap(NP). Bit[0] indicates that the bitmap
 * pixels were fully contained within the HIST1 (single color ) histogram. Bit[1] indicates that the
 * bitmap pixels were fully contained within the HIST2 (black / white ) histogram. Bit[2] indicates
 * that the bitmap pixels were fully contained within the HIST4 (2-bit grayscale) histogram. Bit[3]
 * indicates that the bitmap pixels were fully contained within the HIST8 (3-bit grayscale)
 * histogram. Bit[4] indicates that the bitmap pixels were fully contained within the HIST16 (4-bit
 * grayscale) histogram.
 */

#define BP_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP      (8)      //!< Bit position for EPDC_HW_EPDC_STATUS_HISTOGRAM_NP.
#define BM_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_STATUS_HISTOGRAM_NP.

//! @brief Get value of EPDC_HW_EPDC_STATUS_HISTOGRAM_NP from a register value.
#define BG_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP) >> BP_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP)

//! @brief Format value for bitfield EPDC_HW_EPDC_STATUS_HISTOGRAM_NP.
#define BF_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP) & BM_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HISTOGRAM_NP field to a new value.
#define BW_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP(v)   (HW_EPDC_HW_EPDC_STATUS_WR((HW_EPDC_HW_EPDC_STATUS_RD() & ~BM_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP) | BF_EPDC_HW_EPDC_STATUS_HISTOGRAM_NP(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_STATUS, field HISTOGRAM_CP[20:16] (RW)
 *
 * Indicates which histogram matched the existing bitmap(CP). Bit[0] indicates that the bitmap
 * pixels were fully contained within the HIST1 (single color ) histogram. Bit[1] indicates that the
 * bitmap pixels were fully contained within the HIST2 (black / white ) histogram. Bit[2] indicates
 * that the bitmap pixels were fully contained within the HIST4 (2-bit grayscale) histogram. Bit[3]
 * indicates that the bitmap pixels were fully contained within the HIST8 (3-bit grayscale)
 * histogram. Bit[4] indicates that the bitmap pixels were fully contained within the HIST16 (4-bit
 * grayscale) histogram.
 */

#define BP_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP      (16)      //!< Bit position for EPDC_HW_EPDC_STATUS_HISTOGRAM_CP.
#define BM_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP      (0x001f0000)  //!< Bit mask for EPDC_HW_EPDC_STATUS_HISTOGRAM_CP.

//! @brief Get value of EPDC_HW_EPDC_STATUS_HISTOGRAM_CP from a register value.
#define BG_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP) >> BP_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP)

//! @brief Format value for bitfield EPDC_HW_EPDC_STATUS_HISTOGRAM_CP.
#define BF_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP) & BM_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HISTOGRAM_CP field to a new value.
#define BW_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP(v)   (HW_EPDC_HW_EPDC_STATUS_WR((HW_EPDC_HW_EPDC_STATUS_RD() & ~BM_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP) | BF_EPDC_HW_EPDC_STATUS_HISTOGRAM_CP(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_UPD_COL_CORD - EPDC Collision Region Co-ordinate
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_UPD_COL_CORD - EPDC Collision Region Co-ordinate (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Collision Region Co-ordinate, cleared when new update issued  This register only valid after
 * WB completion and collision happens.   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_upd_col_cord
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_upd_col_cord_bitfields
    {
        unsigned XCORD : 13; //!< [12:0] X co-ordinate for collision region of the latest completed update
        unsigned RESERVED0 : 3; //!< [15:13] Reserved.
        unsigned YCORD : 13; //!< [28:16] Y co-ordinate for collision region of the latest completed update
        unsigned RESERVED1 : 3; //!< [31:29] Reserved.
    } B;
} hw_epdc_hw_epdc_upd_col_cord_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_UPD_COL_CORD register
 */
#define HW_EPDC_HW_EPDC_UPD_COL_CORD_ADDR      (REGS_EPDC_BASE + 0x4c0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_UPD_COL_CORD           (*(volatile hw_epdc_hw_epdc_upd_col_cord_t *) HW_EPDC_HW_EPDC_UPD_COL_CORD_ADDR)
#define HW_EPDC_HW_EPDC_UPD_COL_CORD_RD()      (HW_EPDC_HW_EPDC_UPD_COL_CORD.U)
#define HW_EPDC_HW_EPDC_UPD_COL_CORD_WR(v)     (HW_EPDC_HW_EPDC_UPD_COL_CORD.U = (v))
#define HW_EPDC_HW_EPDC_UPD_COL_CORD_SET(v)    (HW_EPDC_HW_EPDC_UPD_COL_CORD_WR(HW_EPDC_HW_EPDC_UPD_COL_CORD_RD() |  (v)))
#define HW_EPDC_HW_EPDC_UPD_COL_CORD_CLR(v)    (HW_EPDC_HW_EPDC_UPD_COL_CORD_WR(HW_EPDC_HW_EPDC_UPD_COL_CORD_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_UPD_COL_CORD_TOG(v)    (HW_EPDC_HW_EPDC_UPD_COL_CORD_WR(HW_EPDC_HW_EPDC_UPD_COL_CORD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_UPD_COL_CORD bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_UPD_COL_CORD, field XCORD[12:0] (RO)
 *
 * X co-ordinate for collision region of the latest completed update
 */

#define BP_EPDC_HW_EPDC_UPD_COL_CORD_XCORD      (0)      //!< Bit position for EPDC_HW_EPDC_UPD_COL_CORD_XCORD.
#define BM_EPDC_HW_EPDC_UPD_COL_CORD_XCORD      (0x00001fff)  //!< Bit mask for EPDC_HW_EPDC_UPD_COL_CORD_XCORD.

//! @brief Get value of EPDC_HW_EPDC_UPD_COL_CORD_XCORD from a register value.
#define BG_EPDC_HW_EPDC_UPD_COL_CORD_XCORD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_COL_CORD_XCORD) >> BP_EPDC_HW_EPDC_UPD_COL_CORD_XCORD)

/* --- Register HW_EPDC_HW_EPDC_UPD_COL_CORD, field YCORD[28:16] (RO)
 *
 * Y co-ordinate for collision region of the latest completed update
 */

#define BP_EPDC_HW_EPDC_UPD_COL_CORD_YCORD      (16)      //!< Bit position for EPDC_HW_EPDC_UPD_COL_CORD_YCORD.
#define BM_EPDC_HW_EPDC_UPD_COL_CORD_YCORD      (0x1fff0000)  //!< Bit mask for EPDC_HW_EPDC_UPD_COL_CORD_YCORD.

//! @brief Get value of EPDC_HW_EPDC_UPD_COL_CORD_YCORD from a register value.
#define BG_EPDC_HW_EPDC_UPD_COL_CORD_YCORD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_COL_CORD_YCORD) >> BP_EPDC_HW_EPDC_UPD_COL_CORD_YCORD)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_UPD_COL_SIZE - EPDC Collision Region Size
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_UPD_COL_SIZE - EPDC Collision Region Size (RW)
 *
 * Reset value: 0x00000000
 *
 * EPDC Collision Region Size of the latest completed update cleared when new update issued  This
 * register only valid after WB completion and collision happens.   EXAMPLE   N/A
 */
typedef union _hw_epdc_hw_epdc_upd_col_size
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_upd_col_size_bitfields
    {
        unsigned WIDTH : 13; //!< [12:0] Width (in pixels)
        unsigned RESERVED0 : 3; //!< [15:13] Reserved.
        unsigned HEIGHT : 13; //!< [28:16] Height (in pixels)
        unsigned RESERVED1 : 3; //!< [31:29] Reserved.
    } B;
} hw_epdc_hw_epdc_upd_col_size_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_UPD_COL_SIZE register
 */
#define HW_EPDC_HW_EPDC_UPD_COL_SIZE_ADDR      (REGS_EPDC_BASE + 0x4e0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_UPD_COL_SIZE           (*(volatile hw_epdc_hw_epdc_upd_col_size_t *) HW_EPDC_HW_EPDC_UPD_COL_SIZE_ADDR)
#define HW_EPDC_HW_EPDC_UPD_COL_SIZE_RD()      (HW_EPDC_HW_EPDC_UPD_COL_SIZE.U)
#define HW_EPDC_HW_EPDC_UPD_COL_SIZE_WR(v)     (HW_EPDC_HW_EPDC_UPD_COL_SIZE.U = (v))
#define HW_EPDC_HW_EPDC_UPD_COL_SIZE_SET(v)    (HW_EPDC_HW_EPDC_UPD_COL_SIZE_WR(HW_EPDC_HW_EPDC_UPD_COL_SIZE_RD() |  (v)))
#define HW_EPDC_HW_EPDC_UPD_COL_SIZE_CLR(v)    (HW_EPDC_HW_EPDC_UPD_COL_SIZE_WR(HW_EPDC_HW_EPDC_UPD_COL_SIZE_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_UPD_COL_SIZE_TOG(v)    (HW_EPDC_HW_EPDC_UPD_COL_SIZE_WR(HW_EPDC_HW_EPDC_UPD_COL_SIZE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_UPD_COL_SIZE bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_UPD_COL_SIZE, field WIDTH[12:0] (RO)
 *
 * Width (in pixels)
 */

#define BP_EPDC_HW_EPDC_UPD_COL_SIZE_WIDTH      (0)      //!< Bit position for EPDC_HW_EPDC_UPD_COL_SIZE_WIDTH.
#define BM_EPDC_HW_EPDC_UPD_COL_SIZE_WIDTH      (0x00001fff)  //!< Bit mask for EPDC_HW_EPDC_UPD_COL_SIZE_WIDTH.

//! @brief Get value of EPDC_HW_EPDC_UPD_COL_SIZE_WIDTH from a register value.
#define BG_EPDC_HW_EPDC_UPD_COL_SIZE_WIDTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_COL_SIZE_WIDTH) >> BP_EPDC_HW_EPDC_UPD_COL_SIZE_WIDTH)

/* --- Register HW_EPDC_HW_EPDC_UPD_COL_SIZE, field HEIGHT[28:16] (RO)
 *
 * Height (in pixels)
 */

#define BP_EPDC_HW_EPDC_UPD_COL_SIZE_HEIGHT      (16)      //!< Bit position for EPDC_HW_EPDC_UPD_COL_SIZE_HEIGHT.
#define BM_EPDC_HW_EPDC_UPD_COL_SIZE_HEIGHT      (0x1fff0000)  //!< Bit mask for EPDC_HW_EPDC_UPD_COL_SIZE_HEIGHT.

//! @brief Get value of EPDC_HW_EPDC_UPD_COL_SIZE_HEIGHT from a register value.
#define BG_EPDC_HW_EPDC_UPD_COL_SIZE_HEIGHT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_UPD_COL_SIZE_HEIGHT) >> BP_EPDC_HW_EPDC_UPD_COL_SIZE_HEIGHT)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_DEBUG - EPDC Debug register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_DEBUG - EPDC Debug register (RW)
 *
 * Reset value: 0x00007f70
 *
 * Debug register for testing purpose. Write one to this register may damage the display panel.
 * HW_EPDC_DEBUG: 0x500  HW_EPDC_DEBUG_SET: 0x504  HW_EPDC_DEBUG_CLR: 0x508  HW_EPDC_DEBUG_TOG:
 * 0x50C  This register is for debug purpose only.   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_debug
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_debug_bitfields
    {
        unsigned COLLISION_OFF : 1; //!< [0] Set 1 to allow update to take effect even when collision is detected.
        unsigned UNDERRUN_RECOVER : 1; //!< [1] Set 1 to enable EPDC to recover the display at the next vsync when display fifo underrun happens.
        unsigned RESERVED0 : 2; //!< [3:2] Reserved.
        unsigned UPD_BURST_LEN : 4; //!< [7:4] UPD burst length
        unsigned UBR_BURST_LEN : 4; //!< [11:8] UBR burst length
        unsigned UBW_BURST_LEN : 4; //!< [15:12] UBW burst length
        unsigned RESERVED1 : 8; //!< [23:16] Reserved.
        unsigned DEBUG_LUT_SEL : 6; //!< [29:24] select which lut to be present in DEBUG_LUT register
        unsigned RESERVED2 : 2; //!< [31:30] Reserved.
    } B;
} hw_epdc_hw_epdc_debug_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_DEBUG register
 */
#define HW_EPDC_HW_EPDC_DEBUG_ADDR      (REGS_EPDC_BASE + 0x500)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_DEBUG           (*(volatile hw_epdc_hw_epdc_debug_t *) HW_EPDC_HW_EPDC_DEBUG_ADDR)
#define HW_EPDC_HW_EPDC_DEBUG_RD()      (HW_EPDC_HW_EPDC_DEBUG.U)
#define HW_EPDC_HW_EPDC_DEBUG_WR(v)     (HW_EPDC_HW_EPDC_DEBUG.U = (v))
#define HW_EPDC_HW_EPDC_DEBUG_SET(v)    (HW_EPDC_HW_EPDC_DEBUG_WR(HW_EPDC_HW_EPDC_DEBUG_RD() |  (v)))
#define HW_EPDC_HW_EPDC_DEBUG_CLR(v)    (HW_EPDC_HW_EPDC_DEBUG_WR(HW_EPDC_HW_EPDC_DEBUG_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_DEBUG_TOG(v)    (HW_EPDC_HW_EPDC_DEBUG_WR(HW_EPDC_HW_EPDC_DEBUG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_DEBUG bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_DEBUG, field COLLISION_OFF[0] (RW)
 *
 * Set 1 to allow update to take effect even when collision is detected.
 */

#define BP_EPDC_HW_EPDC_DEBUG_COLLISION_OFF      (0)      //!< Bit position for EPDC_HW_EPDC_DEBUG_COLLISION_OFF.
#define BM_EPDC_HW_EPDC_DEBUG_COLLISION_OFF      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_COLLISION_OFF.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_COLLISION_OFF from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_COLLISION_OFF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_COLLISION_OFF) >> BP_EPDC_HW_EPDC_DEBUG_COLLISION_OFF)

//! @brief Format value for bitfield EPDC_HW_EPDC_DEBUG_COLLISION_OFF.
#define BF_EPDC_HW_EPDC_DEBUG_COLLISION_OFF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_DEBUG_COLLISION_OFF) & BM_EPDC_HW_EPDC_DEBUG_COLLISION_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COLLISION_OFF field to a new value.
#define BW_EPDC_HW_EPDC_DEBUG_COLLISION_OFF(v)   (HW_EPDC_HW_EPDC_DEBUG_WR((HW_EPDC_HW_EPDC_DEBUG_RD() & ~BM_EPDC_HW_EPDC_DEBUG_COLLISION_OFF) | BF_EPDC_HW_EPDC_DEBUG_COLLISION_OFF(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_DEBUG, field UNDERRUN_RECOVER[1] (RW)
 *
 * Set 1 to enable EPDC to recover the display at the next vsync when display fifo underrun happens.
 */

#define BP_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER      (1)      //!< Bit position for EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER.
#define BM_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER) >> BP_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER)

//! @brief Format value for bitfield EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER.
#define BF_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER) & BM_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNDERRUN_RECOVER field to a new value.
#define BW_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER(v)   (HW_EPDC_HW_EPDC_DEBUG_WR((HW_EPDC_HW_EPDC_DEBUG_RD() & ~BM_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER) | BF_EPDC_HW_EPDC_DEBUG_UNDERRUN_RECOVER(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_DEBUG, field UPD_BURST_LEN[7:4] (RW)
 *
 * UPD burst length
 */

#define BP_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN      (4)      //!< Bit position for EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN.
#define BM_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN) >> BP_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN)

//! @brief Format value for bitfield EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN.
#define BF_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN) & BM_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPD_BURST_LEN field to a new value.
#define BW_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN(v)   (HW_EPDC_HW_EPDC_DEBUG_WR((HW_EPDC_HW_EPDC_DEBUG_RD() & ~BM_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN) | BF_EPDC_HW_EPDC_DEBUG_UPD_BURST_LEN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_DEBUG, field UBR_BURST_LEN[11:8] (RW)
 *
 * UBR burst length
 */

#define BP_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN      (8)      //!< Bit position for EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN.
#define BM_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN) >> BP_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN)

//! @brief Format value for bitfield EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN.
#define BF_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN) & BM_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UBR_BURST_LEN field to a new value.
#define BW_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN(v)   (HW_EPDC_HW_EPDC_DEBUG_WR((HW_EPDC_HW_EPDC_DEBUG_RD() & ~BM_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN) | BF_EPDC_HW_EPDC_DEBUG_UBR_BURST_LEN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_DEBUG, field UBW_BURST_LEN[15:12] (RW)
 *
 * UBW burst length
 */

#define BP_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN      (12)      //!< Bit position for EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN.
#define BM_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN      (0x0000f000)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN) >> BP_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN)

//! @brief Format value for bitfield EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN.
#define BF_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN) & BM_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UBW_BURST_LEN field to a new value.
#define BW_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN(v)   (HW_EPDC_HW_EPDC_DEBUG_WR((HW_EPDC_HW_EPDC_DEBUG_RD() & ~BM_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN) | BF_EPDC_HW_EPDC_DEBUG_UBW_BURST_LEN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_DEBUG, field DEBUG_LUT_SEL[29:24] (RW)
 *
 * select which lut to be present in DEBUG_LUT register
 */

#define BP_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL      (24)      //!< Bit position for EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL.
#define BM_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL      (0x3f000000)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL) >> BP_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL.
#define BF_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL) & BM_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DEBUG_LUT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL(v)   (HW_EPDC_HW_EPDC_DEBUG_WR((HW_EPDC_HW_EPDC_DEBUG_RD() & ~BM_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL) | BF_EPDC_HW_EPDC_DEBUG_DEBUG_LUT_SEL(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_DEBUG_LUT - EPDC LUT Debug Information register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_DEBUG_LUT - EPDC LUT Debug Information register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register gives debug visibility for LUT0  This register houses LUT debug bits   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_debug_lut
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_debug_lut_bitfields
    {
        unsigned STATEMACHINE : 5; //!< [4:0] LUT0 state machine
        unsigned FRAME : 10; //!< [14:5] The remaining number of frames for this update.
        unsigned RESERVED0 : 1; //!< [15] Reserved..
        unsigned LUTADDR : 10; //!< [25:16] LUT address to be filled.
        unsigned RESERVED1 : 6; //!< [31:26] Reserved..
    } B;
} hw_epdc_hw_epdc_debug_lut_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_DEBUG_LUT register
 */
#define HW_EPDC_HW_EPDC_DEBUG_LUT_ADDR      (REGS_EPDC_BASE + 0x530)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_DEBUG_LUT           (*(volatile hw_epdc_hw_epdc_debug_lut_t *) HW_EPDC_HW_EPDC_DEBUG_LUT_ADDR)
#define HW_EPDC_HW_EPDC_DEBUG_LUT_RD()      (HW_EPDC_HW_EPDC_DEBUG_LUT.U)
#define HW_EPDC_HW_EPDC_DEBUG_LUT_WR(v)     (HW_EPDC_HW_EPDC_DEBUG_LUT.U = (v))
#define HW_EPDC_HW_EPDC_DEBUG_LUT_SET(v)    (HW_EPDC_HW_EPDC_DEBUG_LUT_WR(HW_EPDC_HW_EPDC_DEBUG_LUT_RD() |  (v)))
#define HW_EPDC_HW_EPDC_DEBUG_LUT_CLR(v)    (HW_EPDC_HW_EPDC_DEBUG_LUT_WR(HW_EPDC_HW_EPDC_DEBUG_LUT_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_DEBUG_LUT_TOG(v)    (HW_EPDC_HW_EPDC_DEBUG_LUT_WR(HW_EPDC_HW_EPDC_DEBUG_LUT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_DEBUG_LUT bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_DEBUG_LUT, field STATEMACHINE[4:0] (RO)
 *
 * LUT0 state machine
 */

#define BP_EPDC_HW_EPDC_DEBUG_LUT_STATEMACHINE      (0)      //!< Bit position for EPDC_HW_EPDC_DEBUG_LUT_STATEMACHINE.
#define BM_EPDC_HW_EPDC_DEBUG_LUT_STATEMACHINE      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_LUT_STATEMACHINE.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_LUT_STATEMACHINE from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_LUT_STATEMACHINE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_LUT_STATEMACHINE) >> BP_EPDC_HW_EPDC_DEBUG_LUT_STATEMACHINE)

/* --- Register HW_EPDC_HW_EPDC_DEBUG_LUT, field FRAME[14:5] (RO)
 *
 * The remaining number of frames for this update.
 */

#define BP_EPDC_HW_EPDC_DEBUG_LUT_FRAME      (5)      //!< Bit position for EPDC_HW_EPDC_DEBUG_LUT_FRAME.
#define BM_EPDC_HW_EPDC_DEBUG_LUT_FRAME      (0x00007fe0)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_LUT_FRAME.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_LUT_FRAME from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_LUT_FRAME(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_LUT_FRAME) >> BP_EPDC_HW_EPDC_DEBUG_LUT_FRAME)

/* --- Register HW_EPDC_HW_EPDC_DEBUG_LUT, field LUTADDR[25:16] (RO)
 *
 * LUT address to be filled.
 */

#define BP_EPDC_HW_EPDC_DEBUG_LUT_LUTADDR      (16)      //!< Bit position for EPDC_HW_EPDC_DEBUG_LUT_LUTADDR.
#define BM_EPDC_HW_EPDC_DEBUG_LUT_LUTADDR      (0x03ff0000)  //!< Bit mask for EPDC_HW_EPDC_DEBUG_LUT_LUTADDR.

//! @brief Get value of EPDC_HW_EPDC_DEBUG_LUT_LUTADDR from a register value.
#define BG_EPDC_HW_EPDC_DEBUG_LUT_LUTADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_DEBUG_LUT_LUTADDR) >> BP_EPDC_HW_EPDC_DEBUG_LUT_LUTADDR)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST1_PARAM - 1-level Histogram Parameter Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST1_PARAM - 1-level Histogram Parameter Register. (RW)
 *
 * Reset value: 0x00000000
 *
 * This register specifies the valid values for a 1-level(single color) histogram. If all pixels in
 * a bitmap is only one color, STATUS[0] will be set at the end of frame processing. All comparator
 * values should be programmed such that they are consistent with the TFT_PIXEL_FORMAT control
 * field.    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist1_param
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist1_param_bitfields
    {
        unsigned VALUE0 : 5; //!< [4:0] value for 1-level histogram
        unsigned RESERVED0 : 27; //!< [31:5] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_hist1_param_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST1_PARAM register
 */
#define HW_EPDC_HW_EPDC_HIST1_PARAM_ADDR      (REGS_EPDC_BASE + 0x600)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST1_PARAM           (*(volatile hw_epdc_hw_epdc_hist1_param_t *) HW_EPDC_HW_EPDC_HIST1_PARAM_ADDR)
#define HW_EPDC_HW_EPDC_HIST1_PARAM_RD()      (HW_EPDC_HW_EPDC_HIST1_PARAM.U)
#define HW_EPDC_HW_EPDC_HIST1_PARAM_WR(v)     (HW_EPDC_HW_EPDC_HIST1_PARAM.U = (v))
#define HW_EPDC_HW_EPDC_HIST1_PARAM_SET(v)    (HW_EPDC_HW_EPDC_HIST1_PARAM_WR(HW_EPDC_HW_EPDC_HIST1_PARAM_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST1_PARAM_CLR(v)    (HW_EPDC_HW_EPDC_HIST1_PARAM_WR(HW_EPDC_HW_EPDC_HIST1_PARAM_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST1_PARAM_TOG(v)    (HW_EPDC_HW_EPDC_HIST1_PARAM_WR(HW_EPDC_HW_EPDC_HIST1_PARAM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST1_PARAM bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST1_PARAM, field VALUE0[4:0] (RW)
 *
 * value for 1-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST1_PARAM_VALUE0      (0)      //!< Bit position for EPDC_HW_EPDC_HIST1_PARAM_VALUE0.
#define BM_EPDC_HW_EPDC_HIST1_PARAM_VALUE0      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST1_PARAM_VALUE0.

//! @brief Get value of EPDC_HW_EPDC_HIST1_PARAM_VALUE0 from a register value.
#define BG_EPDC_HW_EPDC_HIST1_PARAM_VALUE0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST1_PARAM_VALUE0) >> BP_EPDC_HW_EPDC_HIST1_PARAM_VALUE0)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST1_PARAM_VALUE0.
#define BF_EPDC_HW_EPDC_HIST1_PARAM_VALUE0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST1_PARAM_VALUE0) & BM_EPDC_HW_EPDC_HIST1_PARAM_VALUE0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPDC_HW_EPDC_HIST1_PARAM_VALUE0(v)   (HW_EPDC_HW_EPDC_HIST1_PARAM_WR((HW_EPDC_HW_EPDC_HIST1_PARAM_RD() & ~BM_EPDC_HW_EPDC_HIST1_PARAM_VALUE0) | BF_EPDC_HW_EPDC_HIST1_PARAM_VALUE0(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST2_PARAM - 2-level Histogram Parameter Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST2_PARAM - 2-level Histogram Parameter Register. (RW)
 *
 * Reset value: 0x00000f00
 *
 * This register specifies the valid values for a 2-level histogram. If all pixels in a bitmap match
 * these two values, STATUS[0] will be set at the end of frame processing. All comparator values
 * should be programmed such that they are consistent with the TFT_PIXEL_FORMAT control field.
 * EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist2_param
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist2_param_bitfields
    {
        unsigned VALUE0 : 5; //!< [4:0] Black value for 2-level histogram
        unsigned RESERVED0 : 3; //!< [7:5] Reserved, always set to zero.
        unsigned VALUE1 : 5; //!< [12:8] White value for 2-level histogram
        unsigned RESERVED1 : 19; //!< [31:13] Reserved.
    } B;
} hw_epdc_hw_epdc_hist2_param_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST2_PARAM register
 */
#define HW_EPDC_HW_EPDC_HIST2_PARAM_ADDR      (REGS_EPDC_BASE + 0x610)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST2_PARAM           (*(volatile hw_epdc_hw_epdc_hist2_param_t *) HW_EPDC_HW_EPDC_HIST2_PARAM_ADDR)
#define HW_EPDC_HW_EPDC_HIST2_PARAM_RD()      (HW_EPDC_HW_EPDC_HIST2_PARAM.U)
#define HW_EPDC_HW_EPDC_HIST2_PARAM_WR(v)     (HW_EPDC_HW_EPDC_HIST2_PARAM.U = (v))
#define HW_EPDC_HW_EPDC_HIST2_PARAM_SET(v)    (HW_EPDC_HW_EPDC_HIST2_PARAM_WR(HW_EPDC_HW_EPDC_HIST2_PARAM_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST2_PARAM_CLR(v)    (HW_EPDC_HW_EPDC_HIST2_PARAM_WR(HW_EPDC_HW_EPDC_HIST2_PARAM_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST2_PARAM_TOG(v)    (HW_EPDC_HW_EPDC_HIST2_PARAM_WR(HW_EPDC_HW_EPDC_HIST2_PARAM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST2_PARAM bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST2_PARAM, field VALUE0[4:0] (RW)
 *
 * Black value for 2-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST2_PARAM_VALUE0      (0)      //!< Bit position for EPDC_HW_EPDC_HIST2_PARAM_VALUE0.
#define BM_EPDC_HW_EPDC_HIST2_PARAM_VALUE0      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST2_PARAM_VALUE0.

//! @brief Get value of EPDC_HW_EPDC_HIST2_PARAM_VALUE0 from a register value.
#define BG_EPDC_HW_EPDC_HIST2_PARAM_VALUE0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST2_PARAM_VALUE0) >> BP_EPDC_HW_EPDC_HIST2_PARAM_VALUE0)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST2_PARAM_VALUE0.
#define BF_EPDC_HW_EPDC_HIST2_PARAM_VALUE0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST2_PARAM_VALUE0) & BM_EPDC_HW_EPDC_HIST2_PARAM_VALUE0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPDC_HW_EPDC_HIST2_PARAM_VALUE0(v)   (HW_EPDC_HW_EPDC_HIST2_PARAM_WR((HW_EPDC_HW_EPDC_HIST2_PARAM_RD() & ~BM_EPDC_HW_EPDC_HIST2_PARAM_VALUE0) | BF_EPDC_HW_EPDC_HIST2_PARAM_VALUE0(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST2_PARAM, field VALUE1[12:8] (RW)
 *
 * White value for 2-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST2_PARAM_VALUE1      (8)      //!< Bit position for EPDC_HW_EPDC_HIST2_PARAM_VALUE1.
#define BM_EPDC_HW_EPDC_HIST2_PARAM_VALUE1      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_HIST2_PARAM_VALUE1.

//! @brief Get value of EPDC_HW_EPDC_HIST2_PARAM_VALUE1 from a register value.
#define BG_EPDC_HW_EPDC_HIST2_PARAM_VALUE1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST2_PARAM_VALUE1) >> BP_EPDC_HW_EPDC_HIST2_PARAM_VALUE1)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST2_PARAM_VALUE1.
#define BF_EPDC_HW_EPDC_HIST2_PARAM_VALUE1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST2_PARAM_VALUE1) & BM_EPDC_HW_EPDC_HIST2_PARAM_VALUE1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE1 field to a new value.
#define BW_EPDC_HW_EPDC_HIST2_PARAM_VALUE1(v)   (HW_EPDC_HW_EPDC_HIST2_PARAM_WR((HW_EPDC_HW_EPDC_HIST2_PARAM_RD() & ~BM_EPDC_HW_EPDC_HIST2_PARAM_VALUE1) | BF_EPDC_HW_EPDC_HIST2_PARAM_VALUE1(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST4_PARAM - 4-level Histogram Parameter Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST4_PARAM - 4-level Histogram Parameter Register. (RW)
 *
 * Reset value: 0x0f0a0500
 *
 * This register specifies the valid values for a 4-level histogram. If all pixels in a bitmap match
 * these two values, STATUS[1] will be set at the end of frame processing. All comparator values
 * should be programmed such that they are consistent with the TFT_PIXEL_FORMAT control field.
 * EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist4_param
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist4_param_bitfields
    {
        unsigned VALUE0 : 5; //!< [4:0] GRAY0 (Black) value for 4-level histogram
        unsigned RESERVED0 : 3; //!< [7:5] Reserved, always set to zero.
        unsigned VALUE1 : 5; //!< [12:8] GRAY1 value for 4-level histogram
        unsigned RESERVED1 : 3; //!< [15:13] Reserved, always set to zero.
        unsigned VALUE2 : 5; //!< [20:16] GRAY2 value for 4-level histogram
        unsigned RESERVED2 : 3; //!< [23:21] Reserved, always set to zero.
        unsigned VALUE3 : 5; //!< [28:24] GRAY3 (White) value for 4-level histogram
        unsigned RESERVED3 : 3; //!< [31:29] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_hist4_param_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST4_PARAM register
 */
#define HW_EPDC_HW_EPDC_HIST4_PARAM_ADDR      (REGS_EPDC_BASE + 0x620)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST4_PARAM           (*(volatile hw_epdc_hw_epdc_hist4_param_t *) HW_EPDC_HW_EPDC_HIST4_PARAM_ADDR)
#define HW_EPDC_HW_EPDC_HIST4_PARAM_RD()      (HW_EPDC_HW_EPDC_HIST4_PARAM.U)
#define HW_EPDC_HW_EPDC_HIST4_PARAM_WR(v)     (HW_EPDC_HW_EPDC_HIST4_PARAM.U = (v))
#define HW_EPDC_HW_EPDC_HIST4_PARAM_SET(v)    (HW_EPDC_HW_EPDC_HIST4_PARAM_WR(HW_EPDC_HW_EPDC_HIST4_PARAM_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST4_PARAM_CLR(v)    (HW_EPDC_HW_EPDC_HIST4_PARAM_WR(HW_EPDC_HW_EPDC_HIST4_PARAM_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST4_PARAM_TOG(v)    (HW_EPDC_HW_EPDC_HIST4_PARAM_WR(HW_EPDC_HW_EPDC_HIST4_PARAM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST4_PARAM bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST4_PARAM, field VALUE0[4:0] (RW)
 *
 * GRAY0 (Black) value for 4-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE0      (0)      //!< Bit position for EPDC_HW_EPDC_HIST4_PARAM_VALUE0.
#define BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE0      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST4_PARAM_VALUE0.

//! @brief Get value of EPDC_HW_EPDC_HIST4_PARAM_VALUE0 from a register value.
#define BG_EPDC_HW_EPDC_HIST4_PARAM_VALUE0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE0) >> BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE0)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST4_PARAM_VALUE0.
#define BF_EPDC_HW_EPDC_HIST4_PARAM_VALUE0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE0) & BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPDC_HW_EPDC_HIST4_PARAM_VALUE0(v)   (HW_EPDC_HW_EPDC_HIST4_PARAM_WR((HW_EPDC_HW_EPDC_HIST4_PARAM_RD() & ~BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE0) | BF_EPDC_HW_EPDC_HIST4_PARAM_VALUE0(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST4_PARAM, field VALUE1[12:8] (RW)
 *
 * GRAY1 value for 4-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE1      (8)      //!< Bit position for EPDC_HW_EPDC_HIST4_PARAM_VALUE1.
#define BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE1      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_HIST4_PARAM_VALUE1.

//! @brief Get value of EPDC_HW_EPDC_HIST4_PARAM_VALUE1 from a register value.
#define BG_EPDC_HW_EPDC_HIST4_PARAM_VALUE1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE1) >> BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE1)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST4_PARAM_VALUE1.
#define BF_EPDC_HW_EPDC_HIST4_PARAM_VALUE1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE1) & BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE1 field to a new value.
#define BW_EPDC_HW_EPDC_HIST4_PARAM_VALUE1(v)   (HW_EPDC_HW_EPDC_HIST4_PARAM_WR((HW_EPDC_HW_EPDC_HIST4_PARAM_RD() & ~BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE1) | BF_EPDC_HW_EPDC_HIST4_PARAM_VALUE1(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST4_PARAM, field VALUE2[20:16] (RW)
 *
 * GRAY2 value for 4-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE2      (16)      //!< Bit position for EPDC_HW_EPDC_HIST4_PARAM_VALUE2.
#define BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE2      (0x001f0000)  //!< Bit mask for EPDC_HW_EPDC_HIST4_PARAM_VALUE2.

//! @brief Get value of EPDC_HW_EPDC_HIST4_PARAM_VALUE2 from a register value.
#define BG_EPDC_HW_EPDC_HIST4_PARAM_VALUE2(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE2) >> BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE2)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST4_PARAM_VALUE2.
#define BF_EPDC_HW_EPDC_HIST4_PARAM_VALUE2(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE2) & BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE2)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE2 field to a new value.
#define BW_EPDC_HW_EPDC_HIST4_PARAM_VALUE2(v)   (HW_EPDC_HW_EPDC_HIST4_PARAM_WR((HW_EPDC_HW_EPDC_HIST4_PARAM_RD() & ~BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE2) | BF_EPDC_HW_EPDC_HIST4_PARAM_VALUE2(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST4_PARAM, field VALUE3[28:24] (RW)
 *
 * GRAY3 (White) value for 4-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE3      (24)      //!< Bit position for EPDC_HW_EPDC_HIST4_PARAM_VALUE3.
#define BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE3      (0x1f000000)  //!< Bit mask for EPDC_HW_EPDC_HIST4_PARAM_VALUE3.

//! @brief Get value of EPDC_HW_EPDC_HIST4_PARAM_VALUE3 from a register value.
#define BG_EPDC_HW_EPDC_HIST4_PARAM_VALUE3(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE3) >> BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE3)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST4_PARAM_VALUE3.
#define BF_EPDC_HW_EPDC_HIST4_PARAM_VALUE3(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST4_PARAM_VALUE3) & BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE3)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE3 field to a new value.
#define BW_EPDC_HW_EPDC_HIST4_PARAM_VALUE3(v)   (HW_EPDC_HW_EPDC_HIST4_PARAM_WR((HW_EPDC_HW_EPDC_HIST4_PARAM_RD() & ~BM_EPDC_HW_EPDC_HIST4_PARAM_VALUE3) | BF_EPDC_HW_EPDC_HIST4_PARAM_VALUE3(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST8_PARAM0 - 8-level Histogram Parameter 0 Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST8_PARAM0 - 8-level Histogram Parameter 0 Register. (RW)
 *
 * Reset value: 0x06044000
 *
 * This register specifies four of the valid values for an 8-level histogram. If all pixels in a
 * bitmap match these two values, STATUS[2] will be set at the end of frame processing. All
 * comparator values should be programmed such that they are consistent with the TFT_PIXEL_FORMAT
 * control field.    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist8_param0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist8_param0_bitfields
    {
        unsigned VALUE0 : 5; //!< [4:0] GRAY0 (Black) value for 8-level histogram
        unsigned RESERVED0 : 3; //!< [7:5] Reserved, always set to zero.
        unsigned VALUE1 : 5; //!< [12:8] GRAY1 value for 8-level histogram
        unsigned RESERVED1 : 3; //!< [15:13] Reserved, always set to zero.
        unsigned VALUE2 : 5; //!< [20:16] GRAY2 value for 8-level histogram
        unsigned RESERVED2 : 3; //!< [23:21] Reserved, always set to zero.
        unsigned VALUE3 : 5; //!< [28:24] GRAY3 value for 8-level histogram
        unsigned RESERVED3 : 3; //!< [31:29] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_hist8_param0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST8_PARAM0 register
 */
#define HW_EPDC_HW_EPDC_HIST8_PARAM0_ADDR      (REGS_EPDC_BASE + 0x630)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST8_PARAM0           (*(volatile hw_epdc_hw_epdc_hist8_param0_t *) HW_EPDC_HW_EPDC_HIST8_PARAM0_ADDR)
#define HW_EPDC_HW_EPDC_HIST8_PARAM0_RD()      (HW_EPDC_HW_EPDC_HIST8_PARAM0.U)
#define HW_EPDC_HW_EPDC_HIST8_PARAM0_WR(v)     (HW_EPDC_HW_EPDC_HIST8_PARAM0.U = (v))
#define HW_EPDC_HW_EPDC_HIST8_PARAM0_SET(v)    (HW_EPDC_HW_EPDC_HIST8_PARAM0_WR(HW_EPDC_HW_EPDC_HIST8_PARAM0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST8_PARAM0_CLR(v)    (HW_EPDC_HW_EPDC_HIST8_PARAM0_WR(HW_EPDC_HW_EPDC_HIST8_PARAM0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST8_PARAM0_TOG(v)    (HW_EPDC_HW_EPDC_HIST8_PARAM0_WR(HW_EPDC_HW_EPDC_HIST8_PARAM0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST8_PARAM0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST8_PARAM0, field VALUE0[4:0] (RW)
 *
 * GRAY0 (Black) value for 8-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0      (0)      //!< Bit position for EPDC_HW_EPDC_HIST8_PARAM0_VALUE0.
#define BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST8_PARAM0_VALUE0.

//! @brief Get value of EPDC_HW_EPDC_HIST8_PARAM0_VALUE0 from a register value.
#define BG_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0) >> BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST8_PARAM0_VALUE0.
#define BF_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0) & BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0(v)   (HW_EPDC_HW_EPDC_HIST8_PARAM0_WR((HW_EPDC_HW_EPDC_HIST8_PARAM0_RD() & ~BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0) | BF_EPDC_HW_EPDC_HIST8_PARAM0_VALUE0(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST8_PARAM0, field VALUE1[12:8] (RW)
 *
 * GRAY1 value for 8-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1      (8)      //!< Bit position for EPDC_HW_EPDC_HIST8_PARAM0_VALUE1.
#define BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_HIST8_PARAM0_VALUE1.

//! @brief Get value of EPDC_HW_EPDC_HIST8_PARAM0_VALUE1 from a register value.
#define BG_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1) >> BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST8_PARAM0_VALUE1.
#define BF_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1) & BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE1 field to a new value.
#define BW_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1(v)   (HW_EPDC_HW_EPDC_HIST8_PARAM0_WR((HW_EPDC_HW_EPDC_HIST8_PARAM0_RD() & ~BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1) | BF_EPDC_HW_EPDC_HIST8_PARAM0_VALUE1(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST8_PARAM0, field VALUE2[20:16] (RW)
 *
 * GRAY2 value for 8-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2      (16)      //!< Bit position for EPDC_HW_EPDC_HIST8_PARAM0_VALUE2.
#define BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2      (0x001f0000)  //!< Bit mask for EPDC_HW_EPDC_HIST8_PARAM0_VALUE2.

//! @brief Get value of EPDC_HW_EPDC_HIST8_PARAM0_VALUE2 from a register value.
#define BG_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2) >> BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST8_PARAM0_VALUE2.
#define BF_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2) & BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE2 field to a new value.
#define BW_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2(v)   (HW_EPDC_HW_EPDC_HIST8_PARAM0_WR((HW_EPDC_HW_EPDC_HIST8_PARAM0_RD() & ~BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2) | BF_EPDC_HW_EPDC_HIST8_PARAM0_VALUE2(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST8_PARAM0, field VALUE3[28:24] (RW)
 *
 * GRAY3 value for 8-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3      (24)      //!< Bit position for EPDC_HW_EPDC_HIST8_PARAM0_VALUE3.
#define BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3      (0x1f000000)  //!< Bit mask for EPDC_HW_EPDC_HIST8_PARAM0_VALUE3.

//! @brief Get value of EPDC_HW_EPDC_HIST8_PARAM0_VALUE3 from a register value.
#define BG_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3) >> BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST8_PARAM0_VALUE3.
#define BF_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3) & BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE3 field to a new value.
#define BW_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3(v)   (HW_EPDC_HW_EPDC_HIST8_PARAM0_WR((HW_EPDC_HW_EPDC_HIST8_PARAM0_RD() & ~BM_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3) | BF_EPDC_HW_EPDC_HIST8_PARAM0_VALUE3(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST8_PARAM1 - 8-level Histogram Parameter 1 Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST8_PARAM1 - 8-level Histogram Parameter 1 Register. (RW)
 *
 * Reset value: 0x0f0d0b09
 *
 * This register specifies four of the valid values for an 8-level histogram. If all pixels in a
 * bitmap match these two values, STATUS[2] will be set at the end of frame processing. All
 * comparator values should be programmed such that they are consistent with the TFT_PIXEL_FORMAT
 * control field.    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist8_param1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist8_param1_bitfields
    {
        unsigned VALUE4 : 5; //!< [4:0] GRAY4 value for 8-level histogram
        unsigned RESERVED0 : 3; //!< [7:5] Reserved, always set to zero.
        unsigned VALUE5 : 5; //!< [12:8] GRAY5 value for 8-level histogram
        unsigned RESERVED1 : 3; //!< [15:13] Reserved, always set to zero.
        unsigned VALUE6 : 5; //!< [20:16] GRAY6 value for 8-level histogram
        unsigned RESERVED2 : 3; //!< [23:21] Reserved, always set to zero.
        unsigned VALUE7 : 5; //!< [28:24] GRAY7 (White) value for 8-level histogram
        unsigned RESERVED3 : 3; //!< [31:29] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_hist8_param1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST8_PARAM1 register
 */
#define HW_EPDC_HW_EPDC_HIST8_PARAM1_ADDR      (REGS_EPDC_BASE + 0x640)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST8_PARAM1           (*(volatile hw_epdc_hw_epdc_hist8_param1_t *) HW_EPDC_HW_EPDC_HIST8_PARAM1_ADDR)
#define HW_EPDC_HW_EPDC_HIST8_PARAM1_RD()      (HW_EPDC_HW_EPDC_HIST8_PARAM1.U)
#define HW_EPDC_HW_EPDC_HIST8_PARAM1_WR(v)     (HW_EPDC_HW_EPDC_HIST8_PARAM1.U = (v))
#define HW_EPDC_HW_EPDC_HIST8_PARAM1_SET(v)    (HW_EPDC_HW_EPDC_HIST8_PARAM1_WR(HW_EPDC_HW_EPDC_HIST8_PARAM1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST8_PARAM1_CLR(v)    (HW_EPDC_HW_EPDC_HIST8_PARAM1_WR(HW_EPDC_HW_EPDC_HIST8_PARAM1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST8_PARAM1_TOG(v)    (HW_EPDC_HW_EPDC_HIST8_PARAM1_WR(HW_EPDC_HW_EPDC_HIST8_PARAM1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST8_PARAM1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST8_PARAM1, field VALUE4[4:0] (RW)
 *
 * GRAY4 value for 8-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4      (0)      //!< Bit position for EPDC_HW_EPDC_HIST8_PARAM1_VALUE4.
#define BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST8_PARAM1_VALUE4.

//! @brief Get value of EPDC_HW_EPDC_HIST8_PARAM1_VALUE4 from a register value.
#define BG_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4) >> BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST8_PARAM1_VALUE4.
#define BF_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4) & BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE4 field to a new value.
#define BW_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4(v)   (HW_EPDC_HW_EPDC_HIST8_PARAM1_WR((HW_EPDC_HW_EPDC_HIST8_PARAM1_RD() & ~BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4) | BF_EPDC_HW_EPDC_HIST8_PARAM1_VALUE4(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST8_PARAM1, field VALUE5[12:8] (RW)
 *
 * GRAY5 value for 8-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5      (8)      //!< Bit position for EPDC_HW_EPDC_HIST8_PARAM1_VALUE5.
#define BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_HIST8_PARAM1_VALUE5.

//! @brief Get value of EPDC_HW_EPDC_HIST8_PARAM1_VALUE5 from a register value.
#define BG_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5) >> BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST8_PARAM1_VALUE5.
#define BF_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5) & BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE5 field to a new value.
#define BW_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5(v)   (HW_EPDC_HW_EPDC_HIST8_PARAM1_WR((HW_EPDC_HW_EPDC_HIST8_PARAM1_RD() & ~BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5) | BF_EPDC_HW_EPDC_HIST8_PARAM1_VALUE5(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST8_PARAM1, field VALUE6[20:16] (RW)
 *
 * GRAY6 value for 8-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6      (16)      //!< Bit position for EPDC_HW_EPDC_HIST8_PARAM1_VALUE6.
#define BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6      (0x001f0000)  //!< Bit mask for EPDC_HW_EPDC_HIST8_PARAM1_VALUE6.

//! @brief Get value of EPDC_HW_EPDC_HIST8_PARAM1_VALUE6 from a register value.
#define BG_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6) >> BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST8_PARAM1_VALUE6.
#define BF_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6) & BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE6 field to a new value.
#define BW_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6(v)   (HW_EPDC_HW_EPDC_HIST8_PARAM1_WR((HW_EPDC_HW_EPDC_HIST8_PARAM1_RD() & ~BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6) | BF_EPDC_HW_EPDC_HIST8_PARAM1_VALUE6(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST8_PARAM1, field VALUE7[28:24] (RW)
 *
 * GRAY7 (White) value for 8-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7      (24)      //!< Bit position for EPDC_HW_EPDC_HIST8_PARAM1_VALUE7.
#define BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7      (0x1f000000)  //!< Bit mask for EPDC_HW_EPDC_HIST8_PARAM1_VALUE7.

//! @brief Get value of EPDC_HW_EPDC_HIST8_PARAM1_VALUE7 from a register value.
#define BG_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7) >> BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST8_PARAM1_VALUE7.
#define BF_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7) & BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE7 field to a new value.
#define BW_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7(v)   (HW_EPDC_HW_EPDC_HIST8_PARAM1_WR((HW_EPDC_HW_EPDC_HIST8_PARAM1_RD() & ~BM_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7) | BF_EPDC_HW_EPDC_HIST8_PARAM1_VALUE7(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST16_PARAM0 - 16-level Histogram Parameter 0 Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST16_PARAM0 - 16-level Histogram Parameter 0 Register. (RW)
 *
 * Reset value: 0x03020100
 *
 * This register specifies four of the valid values for a 16-level histogram. If all pixels in a
 * bitmap match these two values, STATUS[3] will be set at the end of frame processing. All
 * comparator values should be programmed such that they are consistent with the TFT_PIXEL_FORMAT
 * control field.    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist16_param0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist16_param0_bitfields
    {
        unsigned VALUE0 : 5; //!< [4:0] GRAY0 (Black) value for 16-level histogram
        unsigned RESERVED0 : 3; //!< [7:5] Reserved, always set to zero.
        unsigned VALUE1 : 5; //!< [12:8] GRAY1 value for 16-level histogram
        unsigned RESERVED1 : 3; //!< [15:13] Reserved, always set to zero.
        unsigned VALUE2 : 5; //!< [20:16] GRAY2 value for 16-level histogram
        unsigned RESERVED2 : 3; //!< [23:21] Reserved, always set to zero.
        unsigned VALUE3 : 5; //!< [28:24] GRAY3 value for 16-level histogram
        unsigned RESERVED3 : 3; //!< [31:29] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_hist16_param0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST16_PARAM0 register
 */
#define HW_EPDC_HW_EPDC_HIST16_PARAM0_ADDR      (REGS_EPDC_BASE + 0x650)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST16_PARAM0           (*(volatile hw_epdc_hw_epdc_hist16_param0_t *) HW_EPDC_HW_EPDC_HIST16_PARAM0_ADDR)
#define HW_EPDC_HW_EPDC_HIST16_PARAM0_RD()      (HW_EPDC_HW_EPDC_HIST16_PARAM0.U)
#define HW_EPDC_HW_EPDC_HIST16_PARAM0_WR(v)     (HW_EPDC_HW_EPDC_HIST16_PARAM0.U = (v))
#define HW_EPDC_HW_EPDC_HIST16_PARAM0_SET(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM0_WR(HW_EPDC_HW_EPDC_HIST16_PARAM0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST16_PARAM0_CLR(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM0_WR(HW_EPDC_HW_EPDC_HIST16_PARAM0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST16_PARAM0_TOG(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM0_WR(HW_EPDC_HW_EPDC_HIST16_PARAM0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST16_PARAM0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM0, field VALUE0[4:0] (RW)
 *
 * GRAY0 (Black) value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0      (0)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM0_VALUE0.
#define BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM0_VALUE0.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM0_VALUE0 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0) >> BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM0_VALUE0.
#define BF_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0) & BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM0_WR((HW_EPDC_HW_EPDC_HIST16_PARAM0_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0) | BF_EPDC_HW_EPDC_HIST16_PARAM0_VALUE0(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM0, field VALUE1[12:8] (RW)
 *
 * GRAY1 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1      (8)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM0_VALUE1.
#define BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM0_VALUE1.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM0_VALUE1 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1) >> BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM0_VALUE1.
#define BF_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1) & BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE1 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM0_WR((HW_EPDC_HW_EPDC_HIST16_PARAM0_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1) | BF_EPDC_HW_EPDC_HIST16_PARAM0_VALUE1(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM0, field VALUE2[20:16] (RW)
 *
 * GRAY2 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2      (16)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM0_VALUE2.
#define BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2      (0x001f0000)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM0_VALUE2.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM0_VALUE2 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2) >> BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM0_VALUE2.
#define BF_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2) & BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE2 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM0_WR((HW_EPDC_HW_EPDC_HIST16_PARAM0_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2) | BF_EPDC_HW_EPDC_HIST16_PARAM0_VALUE2(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM0, field VALUE3[28:24] (RW)
 *
 * GRAY3 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3      (24)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM0_VALUE3.
#define BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3      (0x1f000000)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM0_VALUE3.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM0_VALUE3 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3) >> BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM0_VALUE3.
#define BF_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3) & BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE3 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM0_WR((HW_EPDC_HW_EPDC_HIST16_PARAM0_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3) | BF_EPDC_HW_EPDC_HIST16_PARAM0_VALUE3(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST16_PARAM1 - 16-level Histogram Parameter Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST16_PARAM1 - 16-level Histogram Parameter Register. (RW)
 *
 * Reset value: 0x07060504
 *
 * This register specifies four of the valid values for a 16-level histogram. If all pixels in a
 * bitmap match these two values, STATUS[3] will be set at the end of frame processing. All
 * comparator values should be programmed such that they are consistent with the TFT_PIXEL_FORMAT
 * control field.    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist16_param1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist16_param1_bitfields
    {
        unsigned VALUE4 : 5; //!< [4:0] GRAY4 value for 16-level histogram
        unsigned RESERVED0 : 3; //!< [7:5] Reserved, always set to zero.
        unsigned VALUE5 : 5; //!< [12:8] GRAY5 value for 16-level histogram
        unsigned RESERVED1 : 3; //!< [15:13] Reserved, always set to zero.
        unsigned VALUE6 : 5; //!< [20:16] GRAY6 value for 16-level histogram
        unsigned RESERVED2 : 3; //!< [23:21] Reserved, always set to zero.
        unsigned VALUE7 : 5; //!< [28:24] GRAY7 value for 16-level histogram
        unsigned RESERVED3 : 3; //!< [31:29] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_hist16_param1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST16_PARAM1 register
 */
#define HW_EPDC_HW_EPDC_HIST16_PARAM1_ADDR      (REGS_EPDC_BASE + 0x660)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST16_PARAM1           (*(volatile hw_epdc_hw_epdc_hist16_param1_t *) HW_EPDC_HW_EPDC_HIST16_PARAM1_ADDR)
#define HW_EPDC_HW_EPDC_HIST16_PARAM1_RD()      (HW_EPDC_HW_EPDC_HIST16_PARAM1.U)
#define HW_EPDC_HW_EPDC_HIST16_PARAM1_WR(v)     (HW_EPDC_HW_EPDC_HIST16_PARAM1.U = (v))
#define HW_EPDC_HW_EPDC_HIST16_PARAM1_SET(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM1_WR(HW_EPDC_HW_EPDC_HIST16_PARAM1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST16_PARAM1_CLR(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM1_WR(HW_EPDC_HW_EPDC_HIST16_PARAM1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST16_PARAM1_TOG(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM1_WR(HW_EPDC_HW_EPDC_HIST16_PARAM1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST16_PARAM1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM1, field VALUE4[4:0] (RW)
 *
 * GRAY4 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4      (0)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM1_VALUE4.
#define BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM1_VALUE4.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM1_VALUE4 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4) >> BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM1_VALUE4.
#define BF_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4) & BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE4 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM1_WR((HW_EPDC_HW_EPDC_HIST16_PARAM1_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4) | BF_EPDC_HW_EPDC_HIST16_PARAM1_VALUE4(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM1, field VALUE5[12:8] (RW)
 *
 * GRAY5 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5      (8)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM1_VALUE5.
#define BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM1_VALUE5.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM1_VALUE5 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5) >> BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM1_VALUE5.
#define BF_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5) & BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE5 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM1_WR((HW_EPDC_HW_EPDC_HIST16_PARAM1_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5) | BF_EPDC_HW_EPDC_HIST16_PARAM1_VALUE5(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM1, field VALUE6[20:16] (RW)
 *
 * GRAY6 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6      (16)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM1_VALUE6.
#define BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6      (0x001f0000)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM1_VALUE6.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM1_VALUE6 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6) >> BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM1_VALUE6.
#define BF_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6) & BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE6 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM1_WR((HW_EPDC_HW_EPDC_HIST16_PARAM1_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6) | BF_EPDC_HW_EPDC_HIST16_PARAM1_VALUE6(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM1, field VALUE7[28:24] (RW)
 *
 * GRAY7 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7      (24)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM1_VALUE7.
#define BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7      (0x1f000000)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM1_VALUE7.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM1_VALUE7 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7) >> BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM1_VALUE7.
#define BF_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7) & BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE7 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM1_WR((HW_EPDC_HW_EPDC_HIST16_PARAM1_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7) | BF_EPDC_HW_EPDC_HIST16_PARAM1_VALUE7(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST16_PARAM2 - 16-level Histogram Parameter Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST16_PARAM2 - 16-level Histogram Parameter Register. (RW)
 *
 * Reset value: 0x0b0a0908
 *
 * This register specifies four of the valid values for a 16-level histogram. If all pixels in a
 * bitmap match these two values, STATUS[3] will be set at the end of frame processing. All
 * comparator values should be programmed such that they are consistent with the TFT_PIXEL_FORMAT
 * control field.    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist16_param2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist16_param2_bitfields
    {
        unsigned VALUE8 : 5; //!< [4:0] GRAY8 value for 16-level histogram
        unsigned RESERVED0 : 3; //!< [7:5] Reserved, always set to zero.
        unsigned VALUE9 : 5; //!< [12:8] GRAY9 value for 16-level histogram
        unsigned RESERVED1 : 3; //!< [15:13] Reserved, always set to zero.
        unsigned VALUE10 : 5; //!< [20:16] GRAY10 value for 16-level histogram
        unsigned RESERVED2 : 3; //!< [23:21] Reserved, always set to zero.
        unsigned VALUE11 : 5; //!< [28:24] GRAY11 value for 16-level histogram
        unsigned RESERVED3 : 3; //!< [31:29] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_hist16_param2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST16_PARAM2 register
 */
#define HW_EPDC_HW_EPDC_HIST16_PARAM2_ADDR      (REGS_EPDC_BASE + 0x670)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST16_PARAM2           (*(volatile hw_epdc_hw_epdc_hist16_param2_t *) HW_EPDC_HW_EPDC_HIST16_PARAM2_ADDR)
#define HW_EPDC_HW_EPDC_HIST16_PARAM2_RD()      (HW_EPDC_HW_EPDC_HIST16_PARAM2.U)
#define HW_EPDC_HW_EPDC_HIST16_PARAM2_WR(v)     (HW_EPDC_HW_EPDC_HIST16_PARAM2.U = (v))
#define HW_EPDC_HW_EPDC_HIST16_PARAM2_SET(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM2_WR(HW_EPDC_HW_EPDC_HIST16_PARAM2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST16_PARAM2_CLR(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM2_WR(HW_EPDC_HW_EPDC_HIST16_PARAM2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST16_PARAM2_TOG(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM2_WR(HW_EPDC_HW_EPDC_HIST16_PARAM2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST16_PARAM2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM2, field VALUE8[4:0] (RW)
 *
 * GRAY8 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8      (0)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM2_VALUE8.
#define BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM2_VALUE8.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM2_VALUE8 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8) >> BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM2_VALUE8.
#define BF_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8) & BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE8 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM2_WR((HW_EPDC_HW_EPDC_HIST16_PARAM2_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8) | BF_EPDC_HW_EPDC_HIST16_PARAM2_VALUE8(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM2, field VALUE9[12:8] (RW)
 *
 * GRAY9 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9      (8)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM2_VALUE9.
#define BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM2_VALUE9.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM2_VALUE9 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9) >> BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM2_VALUE9.
#define BF_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9) & BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE9 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM2_WR((HW_EPDC_HW_EPDC_HIST16_PARAM2_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9) | BF_EPDC_HW_EPDC_HIST16_PARAM2_VALUE9(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM2, field VALUE10[20:16] (RW)
 *
 * GRAY10 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10      (16)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM2_VALUE10.
#define BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10      (0x001f0000)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM2_VALUE10.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM2_VALUE10 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10) >> BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM2_VALUE10.
#define BF_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10) & BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE10 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM2_WR((HW_EPDC_HW_EPDC_HIST16_PARAM2_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10) | BF_EPDC_HW_EPDC_HIST16_PARAM2_VALUE10(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM2, field VALUE11[28:24] (RW)
 *
 * GRAY11 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11      (24)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM2_VALUE11.
#define BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11      (0x1f000000)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM2_VALUE11.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM2_VALUE11 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11) >> BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM2_VALUE11.
#define BF_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11) & BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE11 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM2_WR((HW_EPDC_HW_EPDC_HIST16_PARAM2_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11) | BF_EPDC_HW_EPDC_HIST16_PARAM2_VALUE11(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_HIST16_PARAM3 - 16-level Histogram Parameter Register.
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_HIST16_PARAM3 - 16-level Histogram Parameter Register. (RW)
 *
 * Reset value: 0x0f0e0d0c
 *
 * This register specifies four of the valid values for a 16-level histogram. If all pixels in a
 * bitmap match these two values, STATUS[3] will be set at the end of frame processing. All
 * comparator values should be programmed such that they are consistent with the TFT_PIXEL_FORMAT
 * control field.    EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_hist16_param3
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_hist16_param3_bitfields
    {
        unsigned VALUE12 : 5; //!< [4:0] GRAY12 value for 16-level histogram
        unsigned RESERVED0 : 3; //!< [7:5] Reserved, always set to zero.
        unsigned VALUE13 : 5; //!< [12:8] GRAY13 value for 16-level histogram
        unsigned RESERVED1 : 3; //!< [15:13] Reserved, always set to zero.
        unsigned VALUE14 : 5; //!< [20:16] GRAY14 value for 16-level histogram
        unsigned RESERVED2 : 3; //!< [23:21] Reserved, always set to zero.
        unsigned VALUE15 : 5; //!< [28:24] GRAY15 (White) value for 16-level histogram
        unsigned RESERVED3 : 3; //!< [31:29] Reserved, always set to zero.
    } B;
} hw_epdc_hw_epdc_hist16_param3_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_HIST16_PARAM3 register
 */
#define HW_EPDC_HW_EPDC_HIST16_PARAM3_ADDR      (REGS_EPDC_BASE + 0x680)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_HIST16_PARAM3           (*(volatile hw_epdc_hw_epdc_hist16_param3_t *) HW_EPDC_HW_EPDC_HIST16_PARAM3_ADDR)
#define HW_EPDC_HW_EPDC_HIST16_PARAM3_RD()      (HW_EPDC_HW_EPDC_HIST16_PARAM3.U)
#define HW_EPDC_HW_EPDC_HIST16_PARAM3_WR(v)     (HW_EPDC_HW_EPDC_HIST16_PARAM3.U = (v))
#define HW_EPDC_HW_EPDC_HIST16_PARAM3_SET(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM3_WR(HW_EPDC_HW_EPDC_HIST16_PARAM3_RD() |  (v)))
#define HW_EPDC_HW_EPDC_HIST16_PARAM3_CLR(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM3_WR(HW_EPDC_HW_EPDC_HIST16_PARAM3_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_HIST16_PARAM3_TOG(v)    (HW_EPDC_HW_EPDC_HIST16_PARAM3_WR(HW_EPDC_HW_EPDC_HIST16_PARAM3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_HIST16_PARAM3 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM3, field VALUE12[4:0] (RW)
 *
 * GRAY12 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12      (0)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM3_VALUE12.
#define BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12      (0x0000001f)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM3_VALUE12.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM3_VALUE12 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12) >> BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM3_VALUE12.
#define BF_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12) & BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE12 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM3_WR((HW_EPDC_HW_EPDC_HIST16_PARAM3_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12) | BF_EPDC_HW_EPDC_HIST16_PARAM3_VALUE12(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM3, field VALUE13[12:8] (RW)
 *
 * GRAY13 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13      (8)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM3_VALUE13.
#define BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13      (0x00001f00)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM3_VALUE13.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM3_VALUE13 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13) >> BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM3_VALUE13.
#define BF_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13) & BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE13 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM3_WR((HW_EPDC_HW_EPDC_HIST16_PARAM3_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13) | BF_EPDC_HW_EPDC_HIST16_PARAM3_VALUE13(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM3, field VALUE14[20:16] (RW)
 *
 * GRAY14 value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14      (16)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM3_VALUE14.
#define BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14      (0x001f0000)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM3_VALUE14.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM3_VALUE14 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14) >> BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM3_VALUE14.
#define BF_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14) & BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE14 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM3_WR((HW_EPDC_HW_EPDC_HIST16_PARAM3_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14) | BF_EPDC_HW_EPDC_HIST16_PARAM3_VALUE14(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_HIST16_PARAM3, field VALUE15[28:24] (RW)
 *
 * GRAY15 (White) value for 16-level histogram
 */

#define BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15      (24)      //!< Bit position for EPDC_HW_EPDC_HIST16_PARAM3_VALUE15.
#define BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15      (0x1f000000)  //!< Bit mask for EPDC_HW_EPDC_HIST16_PARAM3_VALUE15.

//! @brief Get value of EPDC_HW_EPDC_HIST16_PARAM3_VALUE15 from a register value.
#define BG_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15) >> BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15)

//! @brief Format value for bitfield EPDC_HW_EPDC_HIST16_PARAM3_VALUE15.
#define BF_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15) & BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE15 field to a new value.
#define BW_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15(v)   (HW_EPDC_HW_EPDC_HIST16_PARAM3_WR((HW_EPDC_HW_EPDC_HIST16_PARAM3_RD() & ~BM_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15) | BF_EPDC_HW_EPDC_HIST16_PARAM3_VALUE15(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_GPIO - EPDC General Purpose I/O Debug register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_GPIO - EPDC General Purpose I/O Debug register (RW)
 *
 * Reset value: 0x00000000
 *
 * GPIO register to control ipp_epdc_bdr[1:0], ipp_epdc_pwr[3:0] and ipp_epdc_pwrcom output signals
 * HW_EPDC_GPIO: 0x700  HW_EPDC_GPIO_SET: 0x704  HW_EPDC_GPIO_CLR: 0x708  HW_EPDC_GPIO_TOG: 0x70C
 * Houses software control signal reisters   EXAMPLE
 */
typedef union _hw_epdc_hw_epdc_gpio
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_gpio_bitfields
    {
        unsigned BDR : 2; //!< [1:0] Controls ipp_epdc_bdr[1:0] output
        unsigned PWRCTRL : 4; //!< [5:2] Controls ipp_epdc_pwrctrl[3:0] output
        unsigned PWRCOM : 1; //!< [6] Controls ipp_epdc_pwrcom output
        unsigned PWRWAKE : 1; //!< [7] Controls ipp_epdc_pwrwake output
        unsigned PWRSTAT : 1; //!< [8] reflect ipp_epdc_pwrstat input
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_gpio_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_GPIO register
 */
#define HW_EPDC_HW_EPDC_GPIO_ADDR      (REGS_EPDC_BASE + 0x700)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_GPIO           (*(volatile hw_epdc_hw_epdc_gpio_t *) HW_EPDC_HW_EPDC_GPIO_ADDR)
#define HW_EPDC_HW_EPDC_GPIO_RD()      (HW_EPDC_HW_EPDC_GPIO.U)
#define HW_EPDC_HW_EPDC_GPIO_WR(v)     (HW_EPDC_HW_EPDC_GPIO.U = (v))
#define HW_EPDC_HW_EPDC_GPIO_SET(v)    (HW_EPDC_HW_EPDC_GPIO_WR(HW_EPDC_HW_EPDC_GPIO_RD() |  (v)))
#define HW_EPDC_HW_EPDC_GPIO_CLR(v)    (HW_EPDC_HW_EPDC_GPIO_WR(HW_EPDC_HW_EPDC_GPIO_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_GPIO_TOG(v)    (HW_EPDC_HW_EPDC_GPIO_WR(HW_EPDC_HW_EPDC_GPIO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_GPIO bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_GPIO, field BDR[1:0] (RW)
 *
 * Controls ipp_epdc_bdr[1:0] output
 */

#define BP_EPDC_HW_EPDC_GPIO_BDR      (0)      //!< Bit position for EPDC_HW_EPDC_GPIO_BDR.
#define BM_EPDC_HW_EPDC_GPIO_BDR      (0x00000003)  //!< Bit mask for EPDC_HW_EPDC_GPIO_BDR.

//! @brief Get value of EPDC_HW_EPDC_GPIO_BDR from a register value.
#define BG_EPDC_HW_EPDC_GPIO_BDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_GPIO_BDR) >> BP_EPDC_HW_EPDC_GPIO_BDR)

//! @brief Format value for bitfield EPDC_HW_EPDC_GPIO_BDR.
#define BF_EPDC_HW_EPDC_GPIO_BDR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_GPIO_BDR) & BM_EPDC_HW_EPDC_GPIO_BDR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BDR field to a new value.
#define BW_EPDC_HW_EPDC_GPIO_BDR(v)   (HW_EPDC_HW_EPDC_GPIO_WR((HW_EPDC_HW_EPDC_GPIO_RD() & ~BM_EPDC_HW_EPDC_GPIO_BDR) | BF_EPDC_HW_EPDC_GPIO_BDR(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_GPIO, field PWRCTRL[5:2] (RW)
 *
 * Controls ipp_epdc_pwrctrl[3:0] output
 */

#define BP_EPDC_HW_EPDC_GPIO_PWRCTRL      (2)      //!< Bit position for EPDC_HW_EPDC_GPIO_PWRCTRL.
#define BM_EPDC_HW_EPDC_GPIO_PWRCTRL      (0x0000003c)  //!< Bit mask for EPDC_HW_EPDC_GPIO_PWRCTRL.

//! @brief Get value of EPDC_HW_EPDC_GPIO_PWRCTRL from a register value.
#define BG_EPDC_HW_EPDC_GPIO_PWRCTRL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_GPIO_PWRCTRL) >> BP_EPDC_HW_EPDC_GPIO_PWRCTRL)

//! @brief Format value for bitfield EPDC_HW_EPDC_GPIO_PWRCTRL.
#define BF_EPDC_HW_EPDC_GPIO_PWRCTRL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_GPIO_PWRCTRL) & BM_EPDC_HW_EPDC_GPIO_PWRCTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PWRCTRL field to a new value.
#define BW_EPDC_HW_EPDC_GPIO_PWRCTRL(v)   (HW_EPDC_HW_EPDC_GPIO_WR((HW_EPDC_HW_EPDC_GPIO_RD() & ~BM_EPDC_HW_EPDC_GPIO_PWRCTRL) | BF_EPDC_HW_EPDC_GPIO_PWRCTRL(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_GPIO, field PWRCOM[6] (RW)
 *
 * Controls ipp_epdc_pwrcom output
 */

#define BP_EPDC_HW_EPDC_GPIO_PWRCOM      (6)      //!< Bit position for EPDC_HW_EPDC_GPIO_PWRCOM.
#define BM_EPDC_HW_EPDC_GPIO_PWRCOM      (0x00000040)  //!< Bit mask for EPDC_HW_EPDC_GPIO_PWRCOM.

//! @brief Get value of EPDC_HW_EPDC_GPIO_PWRCOM from a register value.
#define BG_EPDC_HW_EPDC_GPIO_PWRCOM(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_GPIO_PWRCOM) >> BP_EPDC_HW_EPDC_GPIO_PWRCOM)

//! @brief Format value for bitfield EPDC_HW_EPDC_GPIO_PWRCOM.
#define BF_EPDC_HW_EPDC_GPIO_PWRCOM(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_GPIO_PWRCOM) & BM_EPDC_HW_EPDC_GPIO_PWRCOM)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PWRCOM field to a new value.
#define BW_EPDC_HW_EPDC_GPIO_PWRCOM(v)   (HW_EPDC_HW_EPDC_GPIO_WR((HW_EPDC_HW_EPDC_GPIO_RD() & ~BM_EPDC_HW_EPDC_GPIO_PWRCOM) | BF_EPDC_HW_EPDC_GPIO_PWRCOM(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_GPIO, field PWRWAKE[7] (RW)
 *
 * Controls ipp_epdc_pwrwake output
 */

#define BP_EPDC_HW_EPDC_GPIO_PWRWAKE      (7)      //!< Bit position for EPDC_HW_EPDC_GPIO_PWRWAKE.
#define BM_EPDC_HW_EPDC_GPIO_PWRWAKE      (0x00000080)  //!< Bit mask for EPDC_HW_EPDC_GPIO_PWRWAKE.

//! @brief Get value of EPDC_HW_EPDC_GPIO_PWRWAKE from a register value.
#define BG_EPDC_HW_EPDC_GPIO_PWRWAKE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_GPIO_PWRWAKE) >> BP_EPDC_HW_EPDC_GPIO_PWRWAKE)

//! @brief Format value for bitfield EPDC_HW_EPDC_GPIO_PWRWAKE.
#define BF_EPDC_HW_EPDC_GPIO_PWRWAKE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_GPIO_PWRWAKE) & BM_EPDC_HW_EPDC_GPIO_PWRWAKE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PWRWAKE field to a new value.
#define BW_EPDC_HW_EPDC_GPIO_PWRWAKE(v)   (HW_EPDC_HW_EPDC_GPIO_WR((HW_EPDC_HW_EPDC_GPIO_RD() & ~BM_EPDC_HW_EPDC_GPIO_PWRWAKE) | BF_EPDC_HW_EPDC_GPIO_PWRWAKE(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_GPIO, field PWRSTAT[8] (RO)
 *
 * reflect ipp_epdc_pwrstat input
 */

#define BP_EPDC_HW_EPDC_GPIO_PWRSTAT      (8)      //!< Bit position for EPDC_HW_EPDC_GPIO_PWRSTAT.
#define BM_EPDC_HW_EPDC_GPIO_PWRSTAT      (0x00000100)  //!< Bit mask for EPDC_HW_EPDC_GPIO_PWRSTAT.

//! @brief Get value of EPDC_HW_EPDC_GPIO_PWRSTAT from a register value.
#define BG_EPDC_HW_EPDC_GPIO_PWRSTAT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_GPIO_PWRSTAT) >> BP_EPDC_HW_EPDC_GPIO_PWRSTAT)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_VERSION - EPDC Version Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_VERSION - EPDC Version Register (RW)
 *
 * Reset value: 0x02000000
 *
 * This register reflects the version number for the EPDC.   EXAMPLE   No Example.
 */
typedef union _hw_epdc_hw_epdc_version
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_version_bitfields
    {
        unsigned STEP : 16; //!< [15:0] Fixed read-only value reflecting the stepping of the RTL version.
        unsigned MINOR : 8; //!< [23:16] Fixed read-only value reflecting the MINOR field of the RTL version.
        unsigned MAJOR : 8; //!< [31:24] Fixed read-only value reflecting the MAJOR field of the RTL version.
    } B;
} hw_epdc_hw_epdc_version_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_VERSION register
 */
#define HW_EPDC_HW_EPDC_VERSION_ADDR      (REGS_EPDC_BASE + 0x7f0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_VERSION           (*(volatile hw_epdc_hw_epdc_version_t *) HW_EPDC_HW_EPDC_VERSION_ADDR)
#define HW_EPDC_HW_EPDC_VERSION_RD()      (HW_EPDC_HW_EPDC_VERSION.U)
#define HW_EPDC_HW_EPDC_VERSION_WR(v)     (HW_EPDC_HW_EPDC_VERSION.U = (v))
#define HW_EPDC_HW_EPDC_VERSION_SET(v)    (HW_EPDC_HW_EPDC_VERSION_WR(HW_EPDC_HW_EPDC_VERSION_RD() |  (v)))
#define HW_EPDC_HW_EPDC_VERSION_CLR(v)    (HW_EPDC_HW_EPDC_VERSION_WR(HW_EPDC_HW_EPDC_VERSION_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_VERSION_TOG(v)    (HW_EPDC_HW_EPDC_VERSION_WR(HW_EPDC_HW_EPDC_VERSION_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_VERSION bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_VERSION, field STEP[15:0] (RO)
 *
 * Fixed read-only value reflecting the stepping of the RTL version.
 */

#define BP_EPDC_HW_EPDC_VERSION_STEP      (0)      //!< Bit position for EPDC_HW_EPDC_VERSION_STEP.
#define BM_EPDC_HW_EPDC_VERSION_STEP      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_VERSION_STEP.

//! @brief Get value of EPDC_HW_EPDC_VERSION_STEP from a register value.
#define BG_EPDC_HW_EPDC_VERSION_STEP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_VERSION_STEP) >> BP_EPDC_HW_EPDC_VERSION_STEP)

/* --- Register HW_EPDC_HW_EPDC_VERSION, field MINOR[23:16] (RO)
 *
 * Fixed read-only value reflecting the MINOR field of the RTL version.
 */

#define BP_EPDC_HW_EPDC_VERSION_MINOR      (16)      //!< Bit position for EPDC_HW_EPDC_VERSION_MINOR.
#define BM_EPDC_HW_EPDC_VERSION_MINOR      (0x00ff0000)  //!< Bit mask for EPDC_HW_EPDC_VERSION_MINOR.

//! @brief Get value of EPDC_HW_EPDC_VERSION_MINOR from a register value.
#define BG_EPDC_HW_EPDC_VERSION_MINOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_VERSION_MINOR) >> BP_EPDC_HW_EPDC_VERSION_MINOR)

/* --- Register HW_EPDC_HW_EPDC_VERSION, field MAJOR[31:24] (RO)
 *
 * Fixed read-only value reflecting the MAJOR field of the RTL version.
 */

#define BP_EPDC_HW_EPDC_VERSION_MAJOR      (24)      //!< Bit position for EPDC_HW_EPDC_VERSION_MAJOR.
#define BM_EPDC_HW_EPDC_VERSION_MAJOR      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_VERSION_MAJOR.

//! @brief Get value of EPDC_HW_EPDC_VERSION_MAJOR from a register value.
#define BG_EPDC_HW_EPDC_VERSION_MAJOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_VERSION_MAJOR) >> BP_EPDC_HW_EPDC_VERSION_MAJOR)

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_0_0 - Panel Interface Signal Generator Register 0_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_0_0 - Panel Interface Signal Generator Register 0_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_0_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_0_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_0_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_0_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_0_0_ADDR      (REGS_EPDC_BASE + 0x800)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_0_0           (*(volatile hw_epdc_hw_epdc_pigeon_0_0_t *) HW_EPDC_HW_EPDC_PIGEON_0_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_0_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_0_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_0_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_0_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_0_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_0_0_WR(HW_EPDC_HW_EPDC_PIGEON_0_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_0_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_0_0_WR(HW_EPDC_HW_EPDC_PIGEON_0_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_0_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_0_0_WR(HW_EPDC_HW_EPDC_PIGEON_0_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_0_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_0_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_0_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_0_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_0_EN) & BM_EPDC_HW_EPDC_PIGEON_0_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_0_0_WR((HW_EPDC_HW_EPDC_PIGEON_0_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_0_EN) | BF_EPDC_HW_EPDC_PIGEON_0_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_0_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_0_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_0_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_0_POL) & BM_EPDC_HW_EPDC_PIGEON_0_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_0_0_WR((HW_EPDC_HW_EPDC_PIGEON_0_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_0_POL) | BF_EPDC_HW_EPDC_PIGEON_0_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_0_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_0_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_0_0_WR((HW_EPDC_HW_EPDC_PIGEON_0_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_0_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_0_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_0_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_0_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_0_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_0_0_WR((HW_EPDC_HW_EPDC_PIGEON_0_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_0_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_0_0_WR((HW_EPDC_HW_EPDC_PIGEON_0_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_0_0_WR((HW_EPDC_HW_EPDC_PIGEON_0_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_0_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_0_0_WR((HW_EPDC_HW_EPDC_PIGEON_0_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_0_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_0_1 - Panel Interface Signal Generator Register 0_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_0_1 - Panel Interface Signal Generator Register 0_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_0_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_0_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_0_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_0_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_0_1_ADDR      (REGS_EPDC_BASE + 0x810)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_0_1           (*(volatile hw_epdc_hw_epdc_pigeon_0_1_t *) HW_EPDC_HW_EPDC_PIGEON_0_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_0_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_0_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_0_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_0_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_0_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_0_1_WR(HW_EPDC_HW_EPDC_PIGEON_0_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_0_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_0_1_WR(HW_EPDC_HW_EPDC_PIGEON_0_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_0_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_0_1_WR(HW_EPDC_HW_EPDC_PIGEON_0_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_0_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_0_1_WR((HW_EPDC_HW_EPDC_PIGEON_0_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_0_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_0_1_WR((HW_EPDC_HW_EPDC_PIGEON_0_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_0_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_0_2 - Panel Interface Signal Generator Register 0_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_0_2 - Panel Interface Signal Generator Register 0_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_0_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_0_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_0_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_0_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_0_2_ADDR      (REGS_EPDC_BASE + 0x820)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_0_2           (*(volatile hw_epdc_hw_epdc_pigeon_0_2_t *) HW_EPDC_HW_EPDC_PIGEON_0_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_0_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_0_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_0_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_0_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_0_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_0_2_WR(HW_EPDC_HW_EPDC_PIGEON_0_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_0_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_0_2_WR(HW_EPDC_HW_EPDC_PIGEON_0_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_0_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_0_2_WR(HW_EPDC_HW_EPDC_PIGEON_0_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_0_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_0_2_WR((HW_EPDC_HW_EPDC_PIGEON_0_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_0_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_0_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_0_2_WR((HW_EPDC_HW_EPDC_PIGEON_0_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_0_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_1_0 - Panel Interface Signal Generator Register 1_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_1_0 - Panel Interface Signal Generator Register 1_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_1_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_1_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_1_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_1_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_1_0_ADDR      (REGS_EPDC_BASE + 0x840)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_1_0           (*(volatile hw_epdc_hw_epdc_pigeon_1_0_t *) HW_EPDC_HW_EPDC_PIGEON_1_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_1_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_1_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_1_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_1_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_1_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_1_0_WR(HW_EPDC_HW_EPDC_PIGEON_1_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_1_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_1_0_WR(HW_EPDC_HW_EPDC_PIGEON_1_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_1_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_1_0_WR(HW_EPDC_HW_EPDC_PIGEON_1_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_1_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_1_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_1_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_1_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_0_EN) & BM_EPDC_HW_EPDC_PIGEON_1_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_1_0_WR((HW_EPDC_HW_EPDC_PIGEON_1_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_0_EN) | BF_EPDC_HW_EPDC_PIGEON_1_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_1_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_1_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_1_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_0_POL) & BM_EPDC_HW_EPDC_PIGEON_1_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_1_0_WR((HW_EPDC_HW_EPDC_PIGEON_1_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_0_POL) | BF_EPDC_HW_EPDC_PIGEON_1_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_1_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_1_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_1_0_WR((HW_EPDC_HW_EPDC_PIGEON_1_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_1_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_1_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_1_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_1_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_1_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_1_0_WR((HW_EPDC_HW_EPDC_PIGEON_1_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_1_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_1_0_WR((HW_EPDC_HW_EPDC_PIGEON_1_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_1_0_WR((HW_EPDC_HW_EPDC_PIGEON_1_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_1_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_1_0_WR((HW_EPDC_HW_EPDC_PIGEON_1_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_1_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_1_1 - Panel Interface Signal Generator Register 1_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_1_1 - Panel Interface Signal Generator Register 1_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_1_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_1_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_1_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_1_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_1_1_ADDR      (REGS_EPDC_BASE + 0x850)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_1_1           (*(volatile hw_epdc_hw_epdc_pigeon_1_1_t *) HW_EPDC_HW_EPDC_PIGEON_1_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_1_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_1_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_1_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_1_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_1_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_1_1_WR(HW_EPDC_HW_EPDC_PIGEON_1_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_1_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_1_1_WR(HW_EPDC_HW_EPDC_PIGEON_1_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_1_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_1_1_WR(HW_EPDC_HW_EPDC_PIGEON_1_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_1_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_1_1_WR((HW_EPDC_HW_EPDC_PIGEON_1_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_1_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_1_1_WR((HW_EPDC_HW_EPDC_PIGEON_1_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_1_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_1_2 - Panel Interface Signal Generator Register 1_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_1_2 - Panel Interface Signal Generator Register 1_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_1_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_1_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_1_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_1_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_1_2_ADDR      (REGS_EPDC_BASE + 0x860)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_1_2           (*(volatile hw_epdc_hw_epdc_pigeon_1_2_t *) HW_EPDC_HW_EPDC_PIGEON_1_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_1_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_1_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_1_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_1_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_1_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_1_2_WR(HW_EPDC_HW_EPDC_PIGEON_1_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_1_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_1_2_WR(HW_EPDC_HW_EPDC_PIGEON_1_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_1_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_1_2_WR(HW_EPDC_HW_EPDC_PIGEON_1_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_1_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_1_2_WR((HW_EPDC_HW_EPDC_PIGEON_1_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_1_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_1_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_1_2_WR((HW_EPDC_HW_EPDC_PIGEON_1_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_1_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_2_0 - Panel Interface Signal Generator Register 2_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_2_0 - Panel Interface Signal Generator Register 2_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_2_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_2_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_2_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_2_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_2_0_ADDR      (REGS_EPDC_BASE + 0x880)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_2_0           (*(volatile hw_epdc_hw_epdc_pigeon_2_0_t *) HW_EPDC_HW_EPDC_PIGEON_2_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_2_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_2_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_2_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_2_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_2_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_2_0_WR(HW_EPDC_HW_EPDC_PIGEON_2_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_2_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_2_0_WR(HW_EPDC_HW_EPDC_PIGEON_2_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_2_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_2_0_WR(HW_EPDC_HW_EPDC_PIGEON_2_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_2_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_2_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_2_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_2_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_0_EN) & BM_EPDC_HW_EPDC_PIGEON_2_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_2_0_WR((HW_EPDC_HW_EPDC_PIGEON_2_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_0_EN) | BF_EPDC_HW_EPDC_PIGEON_2_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_2_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_2_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_2_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_0_POL) & BM_EPDC_HW_EPDC_PIGEON_2_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_2_0_WR((HW_EPDC_HW_EPDC_PIGEON_2_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_0_POL) | BF_EPDC_HW_EPDC_PIGEON_2_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_2_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_2_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_2_0_WR((HW_EPDC_HW_EPDC_PIGEON_2_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_2_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_2_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_2_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_2_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_2_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_2_0_WR((HW_EPDC_HW_EPDC_PIGEON_2_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_2_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_2_0_WR((HW_EPDC_HW_EPDC_PIGEON_2_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_2_0_WR((HW_EPDC_HW_EPDC_PIGEON_2_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_2_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_2_0_WR((HW_EPDC_HW_EPDC_PIGEON_2_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_2_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_2_1 - Panel Interface Signal Generator Register 2_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_2_1 - Panel Interface Signal Generator Register 2_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_2_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_2_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_2_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_2_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_2_1_ADDR      (REGS_EPDC_BASE + 0x890)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_2_1           (*(volatile hw_epdc_hw_epdc_pigeon_2_1_t *) HW_EPDC_HW_EPDC_PIGEON_2_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_2_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_2_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_2_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_2_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_2_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_2_1_WR(HW_EPDC_HW_EPDC_PIGEON_2_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_2_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_2_1_WR(HW_EPDC_HW_EPDC_PIGEON_2_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_2_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_2_1_WR(HW_EPDC_HW_EPDC_PIGEON_2_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_2_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_2_1_WR((HW_EPDC_HW_EPDC_PIGEON_2_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_2_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_2_1_WR((HW_EPDC_HW_EPDC_PIGEON_2_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_2_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_2_2 - Panel Interface Signal Generator Register 2_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_2_2 - Panel Interface Signal Generator Register 2_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_2_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_2_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_2_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_2_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_2_2_ADDR      (REGS_EPDC_BASE + 0x8a0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_2_2           (*(volatile hw_epdc_hw_epdc_pigeon_2_2_t *) HW_EPDC_HW_EPDC_PIGEON_2_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_2_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_2_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_2_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_2_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_2_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_2_2_WR(HW_EPDC_HW_EPDC_PIGEON_2_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_2_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_2_2_WR(HW_EPDC_HW_EPDC_PIGEON_2_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_2_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_2_2_WR(HW_EPDC_HW_EPDC_PIGEON_2_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_2_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_2_2_WR((HW_EPDC_HW_EPDC_PIGEON_2_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_2_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_2_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_2_2_WR((HW_EPDC_HW_EPDC_PIGEON_2_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_2_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_3_0 - Panel Interface Signal Generator Register 3_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_3_0 - Panel Interface Signal Generator Register 3_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_3_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_3_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_3_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_3_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_3_0_ADDR      (REGS_EPDC_BASE + 0x8c0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_3_0           (*(volatile hw_epdc_hw_epdc_pigeon_3_0_t *) HW_EPDC_HW_EPDC_PIGEON_3_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_3_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_3_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_3_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_3_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_3_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_3_0_WR(HW_EPDC_HW_EPDC_PIGEON_3_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_3_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_3_0_WR(HW_EPDC_HW_EPDC_PIGEON_3_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_3_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_3_0_WR(HW_EPDC_HW_EPDC_PIGEON_3_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_3_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_3_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_3_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_3_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_0_EN) & BM_EPDC_HW_EPDC_PIGEON_3_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_3_0_WR((HW_EPDC_HW_EPDC_PIGEON_3_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_0_EN) | BF_EPDC_HW_EPDC_PIGEON_3_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_3_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_3_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_3_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_0_POL) & BM_EPDC_HW_EPDC_PIGEON_3_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_3_0_WR((HW_EPDC_HW_EPDC_PIGEON_3_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_0_POL) | BF_EPDC_HW_EPDC_PIGEON_3_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_3_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_3_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_3_0_WR((HW_EPDC_HW_EPDC_PIGEON_3_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_3_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_3_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_3_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_3_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_3_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_3_0_WR((HW_EPDC_HW_EPDC_PIGEON_3_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_3_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_3_0_WR((HW_EPDC_HW_EPDC_PIGEON_3_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_3_0_WR((HW_EPDC_HW_EPDC_PIGEON_3_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_3_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_3_0_WR((HW_EPDC_HW_EPDC_PIGEON_3_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_3_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_3_1 - Panel Interface Signal Generator Register 3_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_3_1 - Panel Interface Signal Generator Register 3_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_3_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_3_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_3_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_3_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_3_1_ADDR      (REGS_EPDC_BASE + 0x8d0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_3_1           (*(volatile hw_epdc_hw_epdc_pigeon_3_1_t *) HW_EPDC_HW_EPDC_PIGEON_3_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_3_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_3_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_3_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_3_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_3_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_3_1_WR(HW_EPDC_HW_EPDC_PIGEON_3_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_3_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_3_1_WR(HW_EPDC_HW_EPDC_PIGEON_3_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_3_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_3_1_WR(HW_EPDC_HW_EPDC_PIGEON_3_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_3_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_3_1_WR((HW_EPDC_HW_EPDC_PIGEON_3_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_3_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_3_1_WR((HW_EPDC_HW_EPDC_PIGEON_3_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_3_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_3_2 - Panel Interface Signal Generator Register 3_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_3_2 - Panel Interface Signal Generator Register 3_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_3_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_3_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_3_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_3_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_3_2_ADDR      (REGS_EPDC_BASE + 0x8e0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_3_2           (*(volatile hw_epdc_hw_epdc_pigeon_3_2_t *) HW_EPDC_HW_EPDC_PIGEON_3_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_3_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_3_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_3_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_3_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_3_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_3_2_WR(HW_EPDC_HW_EPDC_PIGEON_3_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_3_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_3_2_WR(HW_EPDC_HW_EPDC_PIGEON_3_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_3_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_3_2_WR(HW_EPDC_HW_EPDC_PIGEON_3_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_3_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_3_2_WR((HW_EPDC_HW_EPDC_PIGEON_3_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_3_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_3_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_3_2_WR((HW_EPDC_HW_EPDC_PIGEON_3_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_3_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_4_0 - Panel Interface Signal Generator Register 4_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_4_0 - Panel Interface Signal Generator Register 4_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_4_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_4_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_4_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_4_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_4_0_ADDR      (REGS_EPDC_BASE + 0x900)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_4_0           (*(volatile hw_epdc_hw_epdc_pigeon_4_0_t *) HW_EPDC_HW_EPDC_PIGEON_4_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_4_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_4_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_4_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_4_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_4_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_4_0_WR(HW_EPDC_HW_EPDC_PIGEON_4_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_4_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_4_0_WR(HW_EPDC_HW_EPDC_PIGEON_4_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_4_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_4_0_WR(HW_EPDC_HW_EPDC_PIGEON_4_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_4_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_4_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_4_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_4_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_0_EN) & BM_EPDC_HW_EPDC_PIGEON_4_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_4_0_WR((HW_EPDC_HW_EPDC_PIGEON_4_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_0_EN) | BF_EPDC_HW_EPDC_PIGEON_4_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_4_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_4_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_4_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_0_POL) & BM_EPDC_HW_EPDC_PIGEON_4_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_4_0_WR((HW_EPDC_HW_EPDC_PIGEON_4_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_0_POL) | BF_EPDC_HW_EPDC_PIGEON_4_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_4_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_4_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_4_0_WR((HW_EPDC_HW_EPDC_PIGEON_4_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_4_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_4_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_4_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_4_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_4_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_4_0_WR((HW_EPDC_HW_EPDC_PIGEON_4_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_4_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_4_0_WR((HW_EPDC_HW_EPDC_PIGEON_4_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_4_0_WR((HW_EPDC_HW_EPDC_PIGEON_4_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_4_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_4_0_WR((HW_EPDC_HW_EPDC_PIGEON_4_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_4_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_4_1 - Panel Interface Signal Generator Register 4_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_4_1 - Panel Interface Signal Generator Register 4_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_4_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_4_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_4_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_4_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_4_1_ADDR      (REGS_EPDC_BASE + 0x910)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_4_1           (*(volatile hw_epdc_hw_epdc_pigeon_4_1_t *) HW_EPDC_HW_EPDC_PIGEON_4_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_4_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_4_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_4_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_4_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_4_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_4_1_WR(HW_EPDC_HW_EPDC_PIGEON_4_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_4_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_4_1_WR(HW_EPDC_HW_EPDC_PIGEON_4_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_4_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_4_1_WR(HW_EPDC_HW_EPDC_PIGEON_4_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_4_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_4_1_WR((HW_EPDC_HW_EPDC_PIGEON_4_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_4_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_4_1_WR((HW_EPDC_HW_EPDC_PIGEON_4_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_4_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_4_2 - Panel Interface Signal Generator Register 4_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_4_2 - Panel Interface Signal Generator Register 4_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_4_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_4_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_4_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_4_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_4_2_ADDR      (REGS_EPDC_BASE + 0x920)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_4_2           (*(volatile hw_epdc_hw_epdc_pigeon_4_2_t *) HW_EPDC_HW_EPDC_PIGEON_4_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_4_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_4_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_4_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_4_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_4_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_4_2_WR(HW_EPDC_HW_EPDC_PIGEON_4_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_4_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_4_2_WR(HW_EPDC_HW_EPDC_PIGEON_4_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_4_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_4_2_WR(HW_EPDC_HW_EPDC_PIGEON_4_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_4_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_4_2_WR((HW_EPDC_HW_EPDC_PIGEON_4_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_4_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_4_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_4_2_WR((HW_EPDC_HW_EPDC_PIGEON_4_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_4_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_5_0 - Panel Interface Signal Generator Register 5_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_5_0 - Panel Interface Signal Generator Register 5_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_5_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_5_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_5_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_5_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_5_0_ADDR      (REGS_EPDC_BASE + 0x940)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_5_0           (*(volatile hw_epdc_hw_epdc_pigeon_5_0_t *) HW_EPDC_HW_EPDC_PIGEON_5_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_5_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_5_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_5_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_5_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_5_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_5_0_WR(HW_EPDC_HW_EPDC_PIGEON_5_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_5_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_5_0_WR(HW_EPDC_HW_EPDC_PIGEON_5_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_5_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_5_0_WR(HW_EPDC_HW_EPDC_PIGEON_5_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_5_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_5_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_5_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_5_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_0_EN) & BM_EPDC_HW_EPDC_PIGEON_5_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_5_0_WR((HW_EPDC_HW_EPDC_PIGEON_5_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_0_EN) | BF_EPDC_HW_EPDC_PIGEON_5_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_5_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_5_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_5_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_0_POL) & BM_EPDC_HW_EPDC_PIGEON_5_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_5_0_WR((HW_EPDC_HW_EPDC_PIGEON_5_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_0_POL) | BF_EPDC_HW_EPDC_PIGEON_5_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_5_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_5_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_5_0_WR((HW_EPDC_HW_EPDC_PIGEON_5_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_5_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_5_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_5_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_5_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_5_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_5_0_WR((HW_EPDC_HW_EPDC_PIGEON_5_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_5_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_5_0_WR((HW_EPDC_HW_EPDC_PIGEON_5_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_5_0_WR((HW_EPDC_HW_EPDC_PIGEON_5_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_5_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_5_0_WR((HW_EPDC_HW_EPDC_PIGEON_5_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_5_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_5_1 - Panel Interface Signal Generator Register 5_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_5_1 - Panel Interface Signal Generator Register 5_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_5_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_5_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_5_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_5_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_5_1_ADDR      (REGS_EPDC_BASE + 0x950)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_5_1           (*(volatile hw_epdc_hw_epdc_pigeon_5_1_t *) HW_EPDC_HW_EPDC_PIGEON_5_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_5_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_5_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_5_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_5_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_5_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_5_1_WR(HW_EPDC_HW_EPDC_PIGEON_5_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_5_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_5_1_WR(HW_EPDC_HW_EPDC_PIGEON_5_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_5_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_5_1_WR(HW_EPDC_HW_EPDC_PIGEON_5_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_5_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_5_1_WR((HW_EPDC_HW_EPDC_PIGEON_5_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_5_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_5_1_WR((HW_EPDC_HW_EPDC_PIGEON_5_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_5_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_5_2 - Panel Interface Signal Generator Register 5_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_5_2 - Panel Interface Signal Generator Register 5_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_5_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_5_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_5_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_5_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_5_2_ADDR      (REGS_EPDC_BASE + 0x960)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_5_2           (*(volatile hw_epdc_hw_epdc_pigeon_5_2_t *) HW_EPDC_HW_EPDC_PIGEON_5_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_5_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_5_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_5_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_5_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_5_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_5_2_WR(HW_EPDC_HW_EPDC_PIGEON_5_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_5_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_5_2_WR(HW_EPDC_HW_EPDC_PIGEON_5_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_5_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_5_2_WR(HW_EPDC_HW_EPDC_PIGEON_5_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_5_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_5_2_WR((HW_EPDC_HW_EPDC_PIGEON_5_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_5_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_5_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_5_2_WR((HW_EPDC_HW_EPDC_PIGEON_5_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_5_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_6_0 - Panel Interface Signal Generator Register 6_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_6_0 - Panel Interface Signal Generator Register 6_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_6_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_6_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_6_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_6_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_6_0_ADDR      (REGS_EPDC_BASE + 0x980)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_6_0           (*(volatile hw_epdc_hw_epdc_pigeon_6_0_t *) HW_EPDC_HW_EPDC_PIGEON_6_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_6_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_6_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_6_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_6_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_6_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_6_0_WR(HW_EPDC_HW_EPDC_PIGEON_6_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_6_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_6_0_WR(HW_EPDC_HW_EPDC_PIGEON_6_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_6_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_6_0_WR(HW_EPDC_HW_EPDC_PIGEON_6_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_6_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_6_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_6_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_6_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_0_EN) & BM_EPDC_HW_EPDC_PIGEON_6_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_6_0_WR((HW_EPDC_HW_EPDC_PIGEON_6_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_0_EN) | BF_EPDC_HW_EPDC_PIGEON_6_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_6_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_6_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_6_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_0_POL) & BM_EPDC_HW_EPDC_PIGEON_6_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_6_0_WR((HW_EPDC_HW_EPDC_PIGEON_6_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_0_POL) | BF_EPDC_HW_EPDC_PIGEON_6_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_6_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_6_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_6_0_WR((HW_EPDC_HW_EPDC_PIGEON_6_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_6_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_6_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_6_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_6_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_6_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_6_0_WR((HW_EPDC_HW_EPDC_PIGEON_6_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_6_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_6_0_WR((HW_EPDC_HW_EPDC_PIGEON_6_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_6_0_WR((HW_EPDC_HW_EPDC_PIGEON_6_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_6_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_6_0_WR((HW_EPDC_HW_EPDC_PIGEON_6_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_6_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_6_1 - Panel Interface Signal Generator Register 6_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_6_1 - Panel Interface Signal Generator Register 6_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_6_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_6_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_6_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_6_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_6_1_ADDR      (REGS_EPDC_BASE + 0x990)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_6_1           (*(volatile hw_epdc_hw_epdc_pigeon_6_1_t *) HW_EPDC_HW_EPDC_PIGEON_6_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_6_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_6_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_6_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_6_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_6_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_6_1_WR(HW_EPDC_HW_EPDC_PIGEON_6_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_6_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_6_1_WR(HW_EPDC_HW_EPDC_PIGEON_6_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_6_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_6_1_WR(HW_EPDC_HW_EPDC_PIGEON_6_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_6_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_6_1_WR((HW_EPDC_HW_EPDC_PIGEON_6_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_6_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_6_1_WR((HW_EPDC_HW_EPDC_PIGEON_6_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_6_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_6_2 - Panel Interface Signal Generator Register 6_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_6_2 - Panel Interface Signal Generator Register 6_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_6_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_6_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_6_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_6_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_6_2_ADDR      (REGS_EPDC_BASE + 0x9a0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_6_2           (*(volatile hw_epdc_hw_epdc_pigeon_6_2_t *) HW_EPDC_HW_EPDC_PIGEON_6_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_6_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_6_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_6_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_6_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_6_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_6_2_WR(HW_EPDC_HW_EPDC_PIGEON_6_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_6_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_6_2_WR(HW_EPDC_HW_EPDC_PIGEON_6_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_6_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_6_2_WR(HW_EPDC_HW_EPDC_PIGEON_6_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_6_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_6_2_WR((HW_EPDC_HW_EPDC_PIGEON_6_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_6_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_6_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_6_2_WR((HW_EPDC_HW_EPDC_PIGEON_6_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_6_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_7_0 - Panel Interface Signal Generator Register 7_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_7_0 - Panel Interface Signal Generator Register 7_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_7_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_7_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_7_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_7_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_7_0_ADDR      (REGS_EPDC_BASE + 0x9c0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_7_0           (*(volatile hw_epdc_hw_epdc_pigeon_7_0_t *) HW_EPDC_HW_EPDC_PIGEON_7_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_7_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_7_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_7_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_7_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_7_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_7_0_WR(HW_EPDC_HW_EPDC_PIGEON_7_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_7_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_7_0_WR(HW_EPDC_HW_EPDC_PIGEON_7_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_7_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_7_0_WR(HW_EPDC_HW_EPDC_PIGEON_7_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_7_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_7_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_7_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_7_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_0_EN) & BM_EPDC_HW_EPDC_PIGEON_7_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_7_0_WR((HW_EPDC_HW_EPDC_PIGEON_7_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_0_EN) | BF_EPDC_HW_EPDC_PIGEON_7_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_7_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_7_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_7_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_0_POL) & BM_EPDC_HW_EPDC_PIGEON_7_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_7_0_WR((HW_EPDC_HW_EPDC_PIGEON_7_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_0_POL) | BF_EPDC_HW_EPDC_PIGEON_7_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_7_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_7_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_7_0_WR((HW_EPDC_HW_EPDC_PIGEON_7_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_7_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_7_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_7_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_7_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_7_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_7_0_WR((HW_EPDC_HW_EPDC_PIGEON_7_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_7_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_7_0_WR((HW_EPDC_HW_EPDC_PIGEON_7_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_7_0_WR((HW_EPDC_HW_EPDC_PIGEON_7_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_7_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_7_0_WR((HW_EPDC_HW_EPDC_PIGEON_7_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_7_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_7_1 - Panel Interface Signal Generator Register 7_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_7_1 - Panel Interface Signal Generator Register 7_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_7_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_7_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_7_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_7_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_7_1_ADDR      (REGS_EPDC_BASE + 0x9d0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_7_1           (*(volatile hw_epdc_hw_epdc_pigeon_7_1_t *) HW_EPDC_HW_EPDC_PIGEON_7_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_7_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_7_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_7_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_7_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_7_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_7_1_WR(HW_EPDC_HW_EPDC_PIGEON_7_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_7_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_7_1_WR(HW_EPDC_HW_EPDC_PIGEON_7_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_7_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_7_1_WR(HW_EPDC_HW_EPDC_PIGEON_7_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_7_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_7_1_WR((HW_EPDC_HW_EPDC_PIGEON_7_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_7_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_7_1_WR((HW_EPDC_HW_EPDC_PIGEON_7_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_7_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_7_2 - Panel Interface Signal Generator Register 7_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_7_2 - Panel Interface Signal Generator Register 7_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_7_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_7_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_7_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_7_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_7_2_ADDR      (REGS_EPDC_BASE + 0x9e0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_7_2           (*(volatile hw_epdc_hw_epdc_pigeon_7_2_t *) HW_EPDC_HW_EPDC_PIGEON_7_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_7_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_7_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_7_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_7_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_7_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_7_2_WR(HW_EPDC_HW_EPDC_PIGEON_7_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_7_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_7_2_WR(HW_EPDC_HW_EPDC_PIGEON_7_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_7_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_7_2_WR(HW_EPDC_HW_EPDC_PIGEON_7_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_7_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_7_2_WR((HW_EPDC_HW_EPDC_PIGEON_7_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_7_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_7_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_7_2_WR((HW_EPDC_HW_EPDC_PIGEON_7_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_7_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_8_0 - Panel Interface Signal Generator Register 8_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_8_0 - Panel Interface Signal Generator Register 8_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_8_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_8_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_8_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_8_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_8_0_ADDR      (REGS_EPDC_BASE + 0xa00)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_8_0           (*(volatile hw_epdc_hw_epdc_pigeon_8_0_t *) HW_EPDC_HW_EPDC_PIGEON_8_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_8_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_8_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_8_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_8_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_8_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_8_0_WR(HW_EPDC_HW_EPDC_PIGEON_8_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_8_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_8_0_WR(HW_EPDC_HW_EPDC_PIGEON_8_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_8_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_8_0_WR(HW_EPDC_HW_EPDC_PIGEON_8_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_8_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_8_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_8_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_8_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_0_EN) & BM_EPDC_HW_EPDC_PIGEON_8_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_8_0_WR((HW_EPDC_HW_EPDC_PIGEON_8_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_0_EN) | BF_EPDC_HW_EPDC_PIGEON_8_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_8_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_8_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_8_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_0_POL) & BM_EPDC_HW_EPDC_PIGEON_8_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_8_0_WR((HW_EPDC_HW_EPDC_PIGEON_8_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_0_POL) | BF_EPDC_HW_EPDC_PIGEON_8_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_8_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_8_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_8_0_WR((HW_EPDC_HW_EPDC_PIGEON_8_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_8_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_8_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_8_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_8_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_8_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_8_0_WR((HW_EPDC_HW_EPDC_PIGEON_8_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_8_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_8_0_WR((HW_EPDC_HW_EPDC_PIGEON_8_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_8_0_WR((HW_EPDC_HW_EPDC_PIGEON_8_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_8_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_8_0_WR((HW_EPDC_HW_EPDC_PIGEON_8_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_8_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_8_1 - Panel Interface Signal Generator Register 8_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_8_1 - Panel Interface Signal Generator Register 8_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_8_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_8_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_8_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_8_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_8_1_ADDR      (REGS_EPDC_BASE + 0xa10)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_8_1           (*(volatile hw_epdc_hw_epdc_pigeon_8_1_t *) HW_EPDC_HW_EPDC_PIGEON_8_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_8_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_8_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_8_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_8_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_8_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_8_1_WR(HW_EPDC_HW_EPDC_PIGEON_8_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_8_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_8_1_WR(HW_EPDC_HW_EPDC_PIGEON_8_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_8_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_8_1_WR(HW_EPDC_HW_EPDC_PIGEON_8_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_8_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_8_1_WR((HW_EPDC_HW_EPDC_PIGEON_8_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_8_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_8_1_WR((HW_EPDC_HW_EPDC_PIGEON_8_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_8_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_8_2 - Panel Interface Signal Generator Register 8_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_8_2 - Panel Interface Signal Generator Register 8_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_8_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_8_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_8_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_8_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_8_2_ADDR      (REGS_EPDC_BASE + 0xa20)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_8_2           (*(volatile hw_epdc_hw_epdc_pigeon_8_2_t *) HW_EPDC_HW_EPDC_PIGEON_8_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_8_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_8_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_8_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_8_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_8_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_8_2_WR(HW_EPDC_HW_EPDC_PIGEON_8_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_8_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_8_2_WR(HW_EPDC_HW_EPDC_PIGEON_8_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_8_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_8_2_WR(HW_EPDC_HW_EPDC_PIGEON_8_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_8_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_8_2_WR((HW_EPDC_HW_EPDC_PIGEON_8_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_8_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_8_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_8_2_WR((HW_EPDC_HW_EPDC_PIGEON_8_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_8_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_9_0 - Panel Interface Signal Generator Register 9_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_9_0 - Panel Interface Signal Generator Register 9_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_9_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_9_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_9_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_9_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_9_0_ADDR      (REGS_EPDC_BASE + 0xa40)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_9_0           (*(volatile hw_epdc_hw_epdc_pigeon_9_0_t *) HW_EPDC_HW_EPDC_PIGEON_9_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_9_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_9_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_9_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_9_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_9_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_9_0_WR(HW_EPDC_HW_EPDC_PIGEON_9_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_9_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_9_0_WR(HW_EPDC_HW_EPDC_PIGEON_9_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_9_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_9_0_WR(HW_EPDC_HW_EPDC_PIGEON_9_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_9_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_9_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_9_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_9_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_0_EN) & BM_EPDC_HW_EPDC_PIGEON_9_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_9_0_WR((HW_EPDC_HW_EPDC_PIGEON_9_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_0_EN) | BF_EPDC_HW_EPDC_PIGEON_9_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_9_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_9_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_9_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_0_POL) & BM_EPDC_HW_EPDC_PIGEON_9_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_9_0_WR((HW_EPDC_HW_EPDC_PIGEON_9_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_0_POL) | BF_EPDC_HW_EPDC_PIGEON_9_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_9_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_9_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_9_0_WR((HW_EPDC_HW_EPDC_PIGEON_9_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_9_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_9_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_9_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_9_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_9_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_9_0_WR((HW_EPDC_HW_EPDC_PIGEON_9_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_9_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_9_0_WR((HW_EPDC_HW_EPDC_PIGEON_9_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_9_0_WR((HW_EPDC_HW_EPDC_PIGEON_9_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_9_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_9_0_WR((HW_EPDC_HW_EPDC_PIGEON_9_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_9_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_9_1 - Panel Interface Signal Generator Register 9_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_9_1 - Panel Interface Signal Generator Register 9_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_9_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_9_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_9_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_9_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_9_1_ADDR      (REGS_EPDC_BASE + 0xa50)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_9_1           (*(volatile hw_epdc_hw_epdc_pigeon_9_1_t *) HW_EPDC_HW_EPDC_PIGEON_9_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_9_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_9_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_9_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_9_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_9_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_9_1_WR(HW_EPDC_HW_EPDC_PIGEON_9_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_9_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_9_1_WR(HW_EPDC_HW_EPDC_PIGEON_9_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_9_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_9_1_WR(HW_EPDC_HW_EPDC_PIGEON_9_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_9_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_9_1_WR((HW_EPDC_HW_EPDC_PIGEON_9_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_9_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_9_1_WR((HW_EPDC_HW_EPDC_PIGEON_9_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_9_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_9_2 - Panel Interface Signal Generator Register 9_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_9_2 - Panel Interface Signal Generator Register 9_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_9_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_9_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_9_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_9_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_9_2_ADDR      (REGS_EPDC_BASE + 0xa60)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_9_2           (*(volatile hw_epdc_hw_epdc_pigeon_9_2_t *) HW_EPDC_HW_EPDC_PIGEON_9_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_9_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_9_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_9_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_9_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_9_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_9_2_WR(HW_EPDC_HW_EPDC_PIGEON_9_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_9_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_9_2_WR(HW_EPDC_HW_EPDC_PIGEON_9_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_9_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_9_2_WR(HW_EPDC_HW_EPDC_PIGEON_9_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_9_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_9_2_WR((HW_EPDC_HW_EPDC_PIGEON_9_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_9_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_9_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_9_2_WR((HW_EPDC_HW_EPDC_PIGEON_9_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_9_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_10_0 - Panel Interface Signal Generator Register 10_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_10_0 - Panel Interface Signal Generator Register 10_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_10_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_10_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_10_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_10_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_10_0_ADDR      (REGS_EPDC_BASE + 0xa80)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_10_0           (*(volatile hw_epdc_hw_epdc_pigeon_10_0_t *) HW_EPDC_HW_EPDC_PIGEON_10_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_10_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_10_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_10_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_10_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_10_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_10_0_WR(HW_EPDC_HW_EPDC_PIGEON_10_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_10_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_10_0_WR(HW_EPDC_HW_EPDC_PIGEON_10_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_10_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_10_0_WR(HW_EPDC_HW_EPDC_PIGEON_10_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_10_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_10_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_10_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_10_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_0_EN) & BM_EPDC_HW_EPDC_PIGEON_10_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_10_0_WR((HW_EPDC_HW_EPDC_PIGEON_10_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_0_EN) | BF_EPDC_HW_EPDC_PIGEON_10_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_10_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_10_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_10_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_0_POL) & BM_EPDC_HW_EPDC_PIGEON_10_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_10_0_WR((HW_EPDC_HW_EPDC_PIGEON_10_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_0_POL) | BF_EPDC_HW_EPDC_PIGEON_10_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_10_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_10_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_10_0_WR((HW_EPDC_HW_EPDC_PIGEON_10_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_10_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_10_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_10_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_10_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_10_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_10_0_WR((HW_EPDC_HW_EPDC_PIGEON_10_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_10_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_10_0_WR((HW_EPDC_HW_EPDC_PIGEON_10_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_10_0_WR((HW_EPDC_HW_EPDC_PIGEON_10_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_10_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_10_0_WR((HW_EPDC_HW_EPDC_PIGEON_10_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_10_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_10_1 - Panel Interface Signal Generator Register 10_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_10_1 - Panel Interface Signal Generator Register 10_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_10_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_10_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_10_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_10_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_10_1_ADDR      (REGS_EPDC_BASE + 0xa90)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_10_1           (*(volatile hw_epdc_hw_epdc_pigeon_10_1_t *) HW_EPDC_HW_EPDC_PIGEON_10_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_10_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_10_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_10_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_10_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_10_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_10_1_WR(HW_EPDC_HW_EPDC_PIGEON_10_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_10_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_10_1_WR(HW_EPDC_HW_EPDC_PIGEON_10_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_10_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_10_1_WR(HW_EPDC_HW_EPDC_PIGEON_10_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_10_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_10_1_WR((HW_EPDC_HW_EPDC_PIGEON_10_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_10_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_10_1_WR((HW_EPDC_HW_EPDC_PIGEON_10_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_10_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_10_2 - Panel Interface Signal Generator Register 10_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_10_2 - Panel Interface Signal Generator Register 10_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_10_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_10_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_10_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_10_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_10_2_ADDR      (REGS_EPDC_BASE + 0xaa0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_10_2           (*(volatile hw_epdc_hw_epdc_pigeon_10_2_t *) HW_EPDC_HW_EPDC_PIGEON_10_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_10_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_10_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_10_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_10_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_10_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_10_2_WR(HW_EPDC_HW_EPDC_PIGEON_10_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_10_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_10_2_WR(HW_EPDC_HW_EPDC_PIGEON_10_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_10_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_10_2_WR(HW_EPDC_HW_EPDC_PIGEON_10_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_10_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_10_2_WR((HW_EPDC_HW_EPDC_PIGEON_10_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_10_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_10_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_10_2_WR((HW_EPDC_HW_EPDC_PIGEON_10_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_10_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_11_0 - Panel Interface Signal Generator Register 11_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_11_0 - Panel Interface Signal Generator Register 11_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_11_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_11_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_11_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_11_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_11_0_ADDR      (REGS_EPDC_BASE + 0xac0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_11_0           (*(volatile hw_epdc_hw_epdc_pigeon_11_0_t *) HW_EPDC_HW_EPDC_PIGEON_11_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_11_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_11_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_11_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_11_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_11_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_11_0_WR(HW_EPDC_HW_EPDC_PIGEON_11_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_11_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_11_0_WR(HW_EPDC_HW_EPDC_PIGEON_11_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_11_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_11_0_WR(HW_EPDC_HW_EPDC_PIGEON_11_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_11_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_11_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_11_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_11_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_0_EN) & BM_EPDC_HW_EPDC_PIGEON_11_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_11_0_WR((HW_EPDC_HW_EPDC_PIGEON_11_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_0_EN) | BF_EPDC_HW_EPDC_PIGEON_11_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_11_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_11_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_11_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_0_POL) & BM_EPDC_HW_EPDC_PIGEON_11_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_11_0_WR((HW_EPDC_HW_EPDC_PIGEON_11_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_0_POL) | BF_EPDC_HW_EPDC_PIGEON_11_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_11_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_11_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_11_0_WR((HW_EPDC_HW_EPDC_PIGEON_11_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_11_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_11_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_11_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_11_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_11_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_11_0_WR((HW_EPDC_HW_EPDC_PIGEON_11_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_11_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_11_0_WR((HW_EPDC_HW_EPDC_PIGEON_11_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_11_0_WR((HW_EPDC_HW_EPDC_PIGEON_11_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_11_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_11_0_WR((HW_EPDC_HW_EPDC_PIGEON_11_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_11_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_11_1 - Panel Interface Signal Generator Register 11_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_11_1 - Panel Interface Signal Generator Register 11_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_11_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_11_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_11_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_11_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_11_1_ADDR      (REGS_EPDC_BASE + 0xad0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_11_1           (*(volatile hw_epdc_hw_epdc_pigeon_11_1_t *) HW_EPDC_HW_EPDC_PIGEON_11_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_11_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_11_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_11_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_11_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_11_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_11_1_WR(HW_EPDC_HW_EPDC_PIGEON_11_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_11_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_11_1_WR(HW_EPDC_HW_EPDC_PIGEON_11_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_11_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_11_1_WR(HW_EPDC_HW_EPDC_PIGEON_11_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_11_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_11_1_WR((HW_EPDC_HW_EPDC_PIGEON_11_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_11_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_11_1_WR((HW_EPDC_HW_EPDC_PIGEON_11_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_11_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_11_2 - Panel Interface Signal Generator Register 11_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_11_2 - Panel Interface Signal Generator Register 11_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_11_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_11_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_11_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_11_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_11_2_ADDR      (REGS_EPDC_BASE + 0xae0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_11_2           (*(volatile hw_epdc_hw_epdc_pigeon_11_2_t *) HW_EPDC_HW_EPDC_PIGEON_11_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_11_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_11_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_11_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_11_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_11_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_11_2_WR(HW_EPDC_HW_EPDC_PIGEON_11_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_11_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_11_2_WR(HW_EPDC_HW_EPDC_PIGEON_11_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_11_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_11_2_WR(HW_EPDC_HW_EPDC_PIGEON_11_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_11_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_11_2_WR((HW_EPDC_HW_EPDC_PIGEON_11_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_11_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_11_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_11_2_WR((HW_EPDC_HW_EPDC_PIGEON_11_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_11_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_12_0 - Panel Interface Signal Generator Register 12_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_12_0 - Panel Interface Signal Generator Register 12_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_12_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_12_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_12_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_12_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_12_0_ADDR      (REGS_EPDC_BASE + 0xb00)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_12_0           (*(volatile hw_epdc_hw_epdc_pigeon_12_0_t *) HW_EPDC_HW_EPDC_PIGEON_12_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_12_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_12_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_12_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_12_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_12_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_12_0_WR(HW_EPDC_HW_EPDC_PIGEON_12_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_12_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_12_0_WR(HW_EPDC_HW_EPDC_PIGEON_12_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_12_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_12_0_WR(HW_EPDC_HW_EPDC_PIGEON_12_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_12_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_12_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_12_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_12_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_0_EN) & BM_EPDC_HW_EPDC_PIGEON_12_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_12_0_WR((HW_EPDC_HW_EPDC_PIGEON_12_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_0_EN) | BF_EPDC_HW_EPDC_PIGEON_12_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_12_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_12_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_12_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_0_POL) & BM_EPDC_HW_EPDC_PIGEON_12_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_12_0_WR((HW_EPDC_HW_EPDC_PIGEON_12_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_0_POL) | BF_EPDC_HW_EPDC_PIGEON_12_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_12_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_12_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_12_0_WR((HW_EPDC_HW_EPDC_PIGEON_12_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_12_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_12_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_12_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_12_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_12_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_12_0_WR((HW_EPDC_HW_EPDC_PIGEON_12_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_12_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_12_0_WR((HW_EPDC_HW_EPDC_PIGEON_12_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_12_0_WR((HW_EPDC_HW_EPDC_PIGEON_12_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_12_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_12_0_WR((HW_EPDC_HW_EPDC_PIGEON_12_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_12_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_12_1 - Panel Interface Signal Generator Register 12_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_12_1 - Panel Interface Signal Generator Register 12_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_12_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_12_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_12_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_12_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_12_1_ADDR      (REGS_EPDC_BASE + 0xb10)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_12_1           (*(volatile hw_epdc_hw_epdc_pigeon_12_1_t *) HW_EPDC_HW_EPDC_PIGEON_12_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_12_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_12_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_12_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_12_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_12_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_12_1_WR(HW_EPDC_HW_EPDC_PIGEON_12_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_12_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_12_1_WR(HW_EPDC_HW_EPDC_PIGEON_12_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_12_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_12_1_WR(HW_EPDC_HW_EPDC_PIGEON_12_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_12_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_12_1_WR((HW_EPDC_HW_EPDC_PIGEON_12_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_12_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_12_1_WR((HW_EPDC_HW_EPDC_PIGEON_12_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_12_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_12_2 - Panel Interface Signal Generator Register 12_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_12_2 - Panel Interface Signal Generator Register 12_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_12_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_12_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_12_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_12_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_12_2_ADDR      (REGS_EPDC_BASE + 0xb20)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_12_2           (*(volatile hw_epdc_hw_epdc_pigeon_12_2_t *) HW_EPDC_HW_EPDC_PIGEON_12_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_12_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_12_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_12_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_12_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_12_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_12_2_WR(HW_EPDC_HW_EPDC_PIGEON_12_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_12_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_12_2_WR(HW_EPDC_HW_EPDC_PIGEON_12_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_12_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_12_2_WR(HW_EPDC_HW_EPDC_PIGEON_12_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_12_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_12_2_WR((HW_EPDC_HW_EPDC_PIGEON_12_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_12_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_12_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_12_2_WR((HW_EPDC_HW_EPDC_PIGEON_12_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_12_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_13_0 - Panel Interface Signal Generator Register 13_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_13_0 - Panel Interface Signal Generator Register 13_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_13_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_13_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_13_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_13_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_13_0_ADDR      (REGS_EPDC_BASE + 0xb40)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_13_0           (*(volatile hw_epdc_hw_epdc_pigeon_13_0_t *) HW_EPDC_HW_EPDC_PIGEON_13_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_13_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_13_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_13_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_13_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_13_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_13_0_WR(HW_EPDC_HW_EPDC_PIGEON_13_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_13_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_13_0_WR(HW_EPDC_HW_EPDC_PIGEON_13_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_13_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_13_0_WR(HW_EPDC_HW_EPDC_PIGEON_13_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_13_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_13_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_13_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_13_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_0_EN) & BM_EPDC_HW_EPDC_PIGEON_13_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_13_0_WR((HW_EPDC_HW_EPDC_PIGEON_13_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_0_EN) | BF_EPDC_HW_EPDC_PIGEON_13_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_13_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_13_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_13_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_0_POL) & BM_EPDC_HW_EPDC_PIGEON_13_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_13_0_WR((HW_EPDC_HW_EPDC_PIGEON_13_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_0_POL) | BF_EPDC_HW_EPDC_PIGEON_13_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_13_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_13_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_13_0_WR((HW_EPDC_HW_EPDC_PIGEON_13_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_13_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_13_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_13_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_13_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_13_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_13_0_WR((HW_EPDC_HW_EPDC_PIGEON_13_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_13_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_13_0_WR((HW_EPDC_HW_EPDC_PIGEON_13_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_13_0_WR((HW_EPDC_HW_EPDC_PIGEON_13_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_13_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_13_0_WR((HW_EPDC_HW_EPDC_PIGEON_13_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_13_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_13_1 - Panel Interface Signal Generator Register 13_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_13_1 - Panel Interface Signal Generator Register 13_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_13_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_13_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_13_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_13_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_13_1_ADDR      (REGS_EPDC_BASE + 0xb50)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_13_1           (*(volatile hw_epdc_hw_epdc_pigeon_13_1_t *) HW_EPDC_HW_EPDC_PIGEON_13_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_13_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_13_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_13_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_13_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_13_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_13_1_WR(HW_EPDC_HW_EPDC_PIGEON_13_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_13_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_13_1_WR(HW_EPDC_HW_EPDC_PIGEON_13_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_13_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_13_1_WR(HW_EPDC_HW_EPDC_PIGEON_13_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_13_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_13_1_WR((HW_EPDC_HW_EPDC_PIGEON_13_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_13_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_13_1_WR((HW_EPDC_HW_EPDC_PIGEON_13_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_13_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_13_2 - Panel Interface Signal Generator Register 13_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_13_2 - Panel Interface Signal Generator Register 13_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_13_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_13_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_13_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_13_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_13_2_ADDR      (REGS_EPDC_BASE + 0xb60)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_13_2           (*(volatile hw_epdc_hw_epdc_pigeon_13_2_t *) HW_EPDC_HW_EPDC_PIGEON_13_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_13_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_13_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_13_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_13_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_13_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_13_2_WR(HW_EPDC_HW_EPDC_PIGEON_13_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_13_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_13_2_WR(HW_EPDC_HW_EPDC_PIGEON_13_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_13_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_13_2_WR(HW_EPDC_HW_EPDC_PIGEON_13_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_13_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_13_2_WR((HW_EPDC_HW_EPDC_PIGEON_13_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_13_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_13_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_13_2_WR((HW_EPDC_HW_EPDC_PIGEON_13_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_13_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_14_0 - Panel Interface Signal Generator Register 14_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_14_0 - Panel Interface Signal Generator Register 14_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_14_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_14_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_14_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_14_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_14_0_ADDR      (REGS_EPDC_BASE + 0xb80)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_14_0           (*(volatile hw_epdc_hw_epdc_pigeon_14_0_t *) HW_EPDC_HW_EPDC_PIGEON_14_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_14_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_14_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_14_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_14_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_14_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_14_0_WR(HW_EPDC_HW_EPDC_PIGEON_14_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_14_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_14_0_WR(HW_EPDC_HW_EPDC_PIGEON_14_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_14_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_14_0_WR(HW_EPDC_HW_EPDC_PIGEON_14_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_14_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_14_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_14_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_14_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_0_EN) & BM_EPDC_HW_EPDC_PIGEON_14_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_14_0_WR((HW_EPDC_HW_EPDC_PIGEON_14_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_0_EN) | BF_EPDC_HW_EPDC_PIGEON_14_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_14_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_14_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_14_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_0_POL) & BM_EPDC_HW_EPDC_PIGEON_14_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_14_0_WR((HW_EPDC_HW_EPDC_PIGEON_14_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_0_POL) | BF_EPDC_HW_EPDC_PIGEON_14_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_14_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_14_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_14_0_WR((HW_EPDC_HW_EPDC_PIGEON_14_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_14_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_14_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_14_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_14_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_14_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_14_0_WR((HW_EPDC_HW_EPDC_PIGEON_14_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_14_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_14_0_WR((HW_EPDC_HW_EPDC_PIGEON_14_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_14_0_WR((HW_EPDC_HW_EPDC_PIGEON_14_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_14_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_14_0_WR((HW_EPDC_HW_EPDC_PIGEON_14_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_14_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_14_1 - Panel Interface Signal Generator Register 14_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_14_1 - Panel Interface Signal Generator Register 14_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_14_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_14_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_14_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_14_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_14_1_ADDR      (REGS_EPDC_BASE + 0xb90)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_14_1           (*(volatile hw_epdc_hw_epdc_pigeon_14_1_t *) HW_EPDC_HW_EPDC_PIGEON_14_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_14_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_14_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_14_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_14_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_14_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_14_1_WR(HW_EPDC_HW_EPDC_PIGEON_14_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_14_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_14_1_WR(HW_EPDC_HW_EPDC_PIGEON_14_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_14_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_14_1_WR(HW_EPDC_HW_EPDC_PIGEON_14_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_14_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_14_1_WR((HW_EPDC_HW_EPDC_PIGEON_14_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_14_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_14_1_WR((HW_EPDC_HW_EPDC_PIGEON_14_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_14_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_14_2 - Panel Interface Signal Generator Register 14_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_14_2 - Panel Interface Signal Generator Register 14_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_14_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_14_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_14_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_14_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_14_2_ADDR      (REGS_EPDC_BASE + 0xba0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_14_2           (*(volatile hw_epdc_hw_epdc_pigeon_14_2_t *) HW_EPDC_HW_EPDC_PIGEON_14_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_14_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_14_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_14_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_14_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_14_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_14_2_WR(HW_EPDC_HW_EPDC_PIGEON_14_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_14_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_14_2_WR(HW_EPDC_HW_EPDC_PIGEON_14_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_14_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_14_2_WR(HW_EPDC_HW_EPDC_PIGEON_14_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_14_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_14_2_WR((HW_EPDC_HW_EPDC_PIGEON_14_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_14_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_14_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_14_2_WR((HW_EPDC_HW_EPDC_PIGEON_14_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_14_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_15_0 - Panel Interface Signal Generator Register 15_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_15_0 - Panel Interface Signal Generator Register 15_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_15_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_15_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_15_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_15_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_15_0_ADDR      (REGS_EPDC_BASE + 0xbc0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_15_0           (*(volatile hw_epdc_hw_epdc_pigeon_15_0_t *) HW_EPDC_HW_EPDC_PIGEON_15_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_15_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_15_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_15_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_15_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_15_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_15_0_WR(HW_EPDC_HW_EPDC_PIGEON_15_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_15_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_15_0_WR(HW_EPDC_HW_EPDC_PIGEON_15_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_15_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_15_0_WR(HW_EPDC_HW_EPDC_PIGEON_15_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_15_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_15_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_15_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_15_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_0_EN) & BM_EPDC_HW_EPDC_PIGEON_15_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_15_0_WR((HW_EPDC_HW_EPDC_PIGEON_15_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_0_EN) | BF_EPDC_HW_EPDC_PIGEON_15_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_15_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_15_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_15_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_0_POL) & BM_EPDC_HW_EPDC_PIGEON_15_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_15_0_WR((HW_EPDC_HW_EPDC_PIGEON_15_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_0_POL) | BF_EPDC_HW_EPDC_PIGEON_15_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_15_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_15_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_15_0_WR((HW_EPDC_HW_EPDC_PIGEON_15_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_15_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_15_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_15_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_15_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_15_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_15_0_WR((HW_EPDC_HW_EPDC_PIGEON_15_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_15_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_15_0_WR((HW_EPDC_HW_EPDC_PIGEON_15_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_15_0_WR((HW_EPDC_HW_EPDC_PIGEON_15_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_15_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_15_0_WR((HW_EPDC_HW_EPDC_PIGEON_15_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_15_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_15_1 - Panel Interface Signal Generator Register 15_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_15_1 - Panel Interface Signal Generator Register 15_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_15_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_15_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_15_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_15_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_15_1_ADDR      (REGS_EPDC_BASE + 0xbd0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_15_1           (*(volatile hw_epdc_hw_epdc_pigeon_15_1_t *) HW_EPDC_HW_EPDC_PIGEON_15_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_15_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_15_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_15_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_15_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_15_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_15_1_WR(HW_EPDC_HW_EPDC_PIGEON_15_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_15_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_15_1_WR(HW_EPDC_HW_EPDC_PIGEON_15_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_15_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_15_1_WR(HW_EPDC_HW_EPDC_PIGEON_15_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_15_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_15_1_WR((HW_EPDC_HW_EPDC_PIGEON_15_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_15_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_15_1_WR((HW_EPDC_HW_EPDC_PIGEON_15_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_15_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_15_2 - Panel Interface Signal Generator Register 15_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_15_2 - Panel Interface Signal Generator Register 15_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_15_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_15_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_15_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_15_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_15_2_ADDR      (REGS_EPDC_BASE + 0xbe0)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_15_2           (*(volatile hw_epdc_hw_epdc_pigeon_15_2_t *) HW_EPDC_HW_EPDC_PIGEON_15_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_15_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_15_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_15_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_15_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_15_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_15_2_WR(HW_EPDC_HW_EPDC_PIGEON_15_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_15_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_15_2_WR(HW_EPDC_HW_EPDC_PIGEON_15_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_15_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_15_2_WR(HW_EPDC_HW_EPDC_PIGEON_15_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_15_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_15_2_WR((HW_EPDC_HW_EPDC_PIGEON_15_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_15_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_15_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_15_2_WR((HW_EPDC_HW_EPDC_PIGEON_15_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_15_2_SIG_ANOTHER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_16_0 - Panel Interface Signal Generator Register 16_0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_16_0 - Panel Interface Signal Generator Register 16_0 (RW)
 *
 * Reset value: 0x00000f00
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_16_0
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_16_0_bitfields
    {
        unsigned EN : 1; //!< [0] enable pigeon mode on this signal
        unsigned POL : 1; //!< [1] polarity of signal output
        unsigned INC_SEL : 2; //!< [3:2] event to incrment local counter
        unsigned OFFSET : 4; //!< [7:4] offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead. Supported range depends on panel mode
        unsigned MASK_CNT_SEL : 4; //!< [11:8] select global counters as mask condition, use together with MASK_CNT
        unsigned MASK_CNT : 12; //!< [23:12] When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start ticking. 0=disable
        unsigned STATE_MASK : 8; //!< [31:24] state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for local counter to start ticking
    } B;
} hw_epdc_hw_epdc_pigeon_16_0_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_16_0 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_16_0_ADDR      (REGS_EPDC_BASE + 0xc00)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_16_0           (*(volatile hw_epdc_hw_epdc_pigeon_16_0_t *) HW_EPDC_HW_EPDC_PIGEON_16_0_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_16_0_RD()      (HW_EPDC_HW_EPDC_PIGEON_16_0.U)
#define HW_EPDC_HW_EPDC_PIGEON_16_0_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_16_0.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_16_0_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_16_0_WR(HW_EPDC_HW_EPDC_PIGEON_16_0_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_16_0_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_16_0_WR(HW_EPDC_HW_EPDC_PIGEON_16_0_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_16_0_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_16_0_WR(HW_EPDC_HW_EPDC_PIGEON_16_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_16_0 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_0, field EN[0] (RW)
 *
 * enable pigeon mode on this signal
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_0_EN      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_0_EN.
#define BM_EPDC_HW_EPDC_PIGEON_16_0_EN      (0x00000001)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_0_EN.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_0_EN from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_0_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_0_EN) >> BP_EPDC_HW_EPDC_PIGEON_16_0_EN)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_0_EN.
#define BF_EPDC_HW_EPDC_PIGEON_16_0_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_0_EN) & BM_EPDC_HW_EPDC_PIGEON_16_0_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_0_EN(v)   (HW_EPDC_HW_EPDC_PIGEON_16_0_WR((HW_EPDC_HW_EPDC_PIGEON_16_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_0_EN) | BF_EPDC_HW_EPDC_PIGEON_16_0_EN(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_0, field POL[1] (RW)
 *
 * polarity of signal output
 *
 * Values:
 * ACTIVE_HIGH = 0x0 - normal signal (active high)
 * ACTIVE_LOW = 0x1 - inverted signal (active low)
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_0_POL      (1)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_0_POL.
#define BM_EPDC_HW_EPDC_PIGEON_16_0_POL      (0x00000002)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_0_POL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_0_POL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_0_POL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_0_POL) >> BP_EPDC_HW_EPDC_PIGEON_16_0_POL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_0_POL.
#define BF_EPDC_HW_EPDC_PIGEON_16_0_POL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_0_POL) & BM_EPDC_HW_EPDC_PIGEON_16_0_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_0_POL(v)   (HW_EPDC_HW_EPDC_PIGEON_16_0_WR((HW_EPDC_HW_EPDC_PIGEON_16_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_0_POL) | BF_EPDC_HW_EPDC_PIGEON_16_0_POL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_16_0_POL__ACTIVE_HIGH (0x0) //!< normal signal (active high)
#define BV_EPDC_HW_EPDC_PIGEON_16_0_POL__ACTIVE_LOW (0x1) //!< inverted signal (active low)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_0, field INC_SEL[3:2] (RW)
 *
 * event to incrment local counter
 *
 * Values:
 * PCLK = 0x0 - pclk
 * LINE = 0x1 - line start pulse
 * FRAME = 0x2 - frame start pulse
 * SIG_ANOTHER = 0x3 - use another signal as tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL      (2)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_0_INC_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL      (0x0000000c)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_0_INC_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_0_INC_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL) >> BP_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_0_INC_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL) & BM_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_16_0_WR((HW_EPDC_HW_EPDC_PIGEON_16_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL) | BF_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL__PCLK (0x0) //!< pclk
#define BV_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL__LINE (0x1) //!< line start pulse
#define BV_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL__FRAME (0x2) //!< frame start pulse
#define BV_EPDC_HW_EPDC_PIGEON_16_0_INC_SEL__SIG_ANOTHER (0x3) //!< use another signal as tick event

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_0, field OFFSET[7:4] (RW)
 *
 * offset on pclk unit. 0=aligne with data, positive value means delay, minus value mean ahead.
 * Supported range depends on panel mode
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_0_OFFSET      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_0_OFFSET.
#define BM_EPDC_HW_EPDC_PIGEON_16_0_OFFSET      (0x000000f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_0_OFFSET.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_0_OFFSET from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_0_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_0_OFFSET) >> BP_EPDC_HW_EPDC_PIGEON_16_0_OFFSET)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_0_OFFSET.
#define BF_EPDC_HW_EPDC_PIGEON_16_0_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_0_OFFSET) & BM_EPDC_HW_EPDC_PIGEON_16_0_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_0_OFFSET(v)   (HW_EPDC_HW_EPDC_PIGEON_16_0_WR((HW_EPDC_HW_EPDC_PIGEON_16_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_0_OFFSET) | BF_EPDC_HW_EPDC_PIGEON_16_0_OFFSET(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_0, field MASK_CNT_SEL[11:8] (RW)
 *
 * select global counters as mask condition, use together with MASK_CNT
 *
 * Values:
 * HSTATE_CNT = 0x0 - pclk counter within one hscan state
 * HSTATE_CYCLE = 0x1 - pclk cycle within one hscan state
 * VSTATE_CNT = 0x2 - line counter within one vscan state
 * VSTATE_CYCLE = 0x3 - line cycle within one vscan state
 * FRAME_CNT = 0x4 - frame counter
 * FRAME_CYCLE = 0x5 - frame cycle
 * HCNT = 0x6 - horizontal counter (pclk counter within one line )
 * VCNT = 0x7 - vertical counter (line counter within one frame)
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL      (8)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL.
#define BM_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL      (0x00000f00)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL) >> BP_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL.
#define BF_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL) & BM_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT_SEL field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL(v)   (HW_EPDC_HW_EPDC_PIGEON_16_0_WR((HW_EPDC_HW_EPDC_PIGEON_16_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL) | BF_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL__HSTATE_CNT (0x0) //!< pclk counter within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL__HSTATE_CYCLE (0x1) //!< pclk cycle within one hscan state
#define BV_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL__VSTATE_CNT (0x2) //!< line counter within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL__VSTATE_CYCLE (0x3) //!< line cycle within one vscan state
#define BV_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL__FRAME_CNT (0x4) //!< frame counter
#define BV_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL__FRAME_CYCLE (0x5) //!< frame cycle
#define BV_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL__HCNT (0x6) //!< horizontal counter (pclk counter within one line )
#define BV_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT_SEL__VCNT (0x7) //!< vertical counter (line counter within one frame)

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_0, field MASK_CNT[23:12] (RW)
 *
 * When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local
 * counter start ticking. 0=disable
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT      (12)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT      (0x00fff000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT) >> BP_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT) & BM_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_16_0_WR((HW_EPDC_HW_EPDC_PIGEON_16_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT) | BF_EPDC_HW_EPDC_PIGEON_16_0_MASK_CNT(v)))
#endif

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_0, field STATE_MASK[31:24] (RW)
 *
 * state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference
 * point for local counter to start ticking
 *
 * Values:
 * FS = 0x1 - FRAME SYNC
 * FB = 0x2 - FRAME BEGIN
 * FD = 0x4 - FRAME DATA
 * FE = 0x8 - FRAME END
 * LS = 0x10 - LINE SYNC
 * LB = 0x20 - LINE BEGIN
 * LD = 0x40 - LINE DATA
 * LE = 0x80 - LINE END
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK      (24)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK.
#define BM_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK      (0xff000000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK) >> BP_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK.
#define BF_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK) & BM_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATE_MASK field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK(v)   (HW_EPDC_HW_EPDC_PIGEON_16_0_WR((HW_EPDC_HW_EPDC_PIGEON_16_0_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK) | BF_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK__FS (0x1) //!< FRAME SYNC
#define BV_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK__FB (0x2) //!< FRAME BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK__FD (0x4) //!< FRAME DATA
#define BV_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK__FE (0x8) //!< FRAME END
#define BV_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK__LS (0x10) //!< LINE SYNC
#define BV_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK__LB (0x20) //!< LINE BEGIN
#define BV_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK__LD (0x40) //!< LINE DATA
#define BV_EPDC_HW_EPDC_PIGEON_16_0_STATE_MASK__LE (0x80) //!< LINE END

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_16_1 - Panel Interface Signal Generator Register 16_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_16_1 - Panel Interface Signal Generator Register 16_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_16_1
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_16_1_bitfields
    {
        unsigned SET_CNT : 16; //!< [15:0] assert signal output when counter match this value
        unsigned CLR_CNT : 16; //!< [31:16] deassert signal output when counter match this value
    } B;
} hw_epdc_hw_epdc_pigeon_16_1_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_16_1 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_16_1_ADDR      (REGS_EPDC_BASE + 0xc10)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_16_1           (*(volatile hw_epdc_hw_epdc_pigeon_16_1_t *) HW_EPDC_HW_EPDC_PIGEON_16_1_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_16_1_RD()      (HW_EPDC_HW_EPDC_PIGEON_16_1.U)
#define HW_EPDC_HW_EPDC_PIGEON_16_1_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_16_1.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_16_1_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_16_1_WR(HW_EPDC_HW_EPDC_PIGEON_16_1_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_16_1_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_16_1_WR(HW_EPDC_HW_EPDC_PIGEON_16_1_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_16_1_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_16_1_WR(HW_EPDC_HW_EPDC_PIGEON_16_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_16_1 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_1, field SET_CNT[15:0] (RW)
 *
 * assert signal output when counter match this value
 *
 * Values:
 * START_ACTIVE = 0x0 - start as active
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_1_SET_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT      (0x0000ffff)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_1_SET_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_1_SET_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT) >> BP_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_1_SET_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT) & BM_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_16_1_WR((HW_EPDC_HW_EPDC_PIGEON_16_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT) | BF_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_16_1_SET_CNT__START_ACTIVE (0x0) //!< start as active

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_1, field CLR_CNT[31:16] (RW)
 *
 * deassert signal output when counter match this value
 *
 * Values:
 * CLEAR_USING_MASK = 0x0 - keep active until mask off
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT      (16)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT.
#define BM_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT      (0xffff0000)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT) >> BP_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT.
#define BF_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT) & BM_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_CNT field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT(v)   (HW_EPDC_HW_EPDC_PIGEON_16_1_WR((HW_EPDC_HW_EPDC_PIGEON_16_1_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT) | BF_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_16_1_CLR_CNT__CLEAR_USING_MASK (0x0) //!< keep active until mask off

//-------------------------------------------------------------------------------------------
// HW_EPDC_HW_EPDC_PIGEON_16_2 - Panel Interface Signal Generator Register 16_1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPDC_HW_EPDC_PIGEON_16_2 - Panel Interface Signal Generator Register 16_1 (RW)
 *
 * Reset value: 0x00000000
 *
 * parameters for timing signal generation
 */
typedef union _hw_epdc_hw_epdc_pigeon_16_2
{
    reg32_t U;
    struct _hw_epdc_hw_epdc_pigeon_16_2_bitfields
    {
        unsigned SIG_LOGIC : 4; //!< [3:0] logic operation with another signal: DIS/AND/OR/COND
        unsigned SIG_ANOTHER : 5; //!< [8:4] select another signal for logic operation or as mask or counter tick event
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_epdc_hw_epdc_pigeon_16_2_t;
#endif

/*
 * constants & macros for entire EPDC_HW_EPDC_PIGEON_16_2 register
 */
#define HW_EPDC_HW_EPDC_PIGEON_16_2_ADDR      (REGS_EPDC_BASE + 0xc20)

#ifndef __LANGUAGE_ASM__
#define HW_EPDC_HW_EPDC_PIGEON_16_2           (*(volatile hw_epdc_hw_epdc_pigeon_16_2_t *) HW_EPDC_HW_EPDC_PIGEON_16_2_ADDR)
#define HW_EPDC_HW_EPDC_PIGEON_16_2_RD()      (HW_EPDC_HW_EPDC_PIGEON_16_2.U)
#define HW_EPDC_HW_EPDC_PIGEON_16_2_WR(v)     (HW_EPDC_HW_EPDC_PIGEON_16_2.U = (v))
#define HW_EPDC_HW_EPDC_PIGEON_16_2_SET(v)    (HW_EPDC_HW_EPDC_PIGEON_16_2_WR(HW_EPDC_HW_EPDC_PIGEON_16_2_RD() |  (v)))
#define HW_EPDC_HW_EPDC_PIGEON_16_2_CLR(v)    (HW_EPDC_HW_EPDC_PIGEON_16_2_WR(HW_EPDC_HW_EPDC_PIGEON_16_2_RD() & ~(v)))
#define HW_EPDC_HW_EPDC_PIGEON_16_2_TOG(v)    (HW_EPDC_HW_EPDC_PIGEON_16_2_WR(HW_EPDC_HW_EPDC_PIGEON_16_2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EPDC_HW_EPDC_PIGEON_16_2 bitfields
 */

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_2, field SIG_LOGIC[3:0] (RW)
 *
 * logic operation with another signal: DIS/AND/OR/COND
 *
 * Values:
 * DIS = 0x0 - no logic operation
 * AND = 0x1 - sigout = sig_another AND this_sig
 * OR = 0x2 - sigout = sig_another OR this_sig
 * MASK = 0x3 - mask = sig_another AND other_masks
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC      (0)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC.
#define BM_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC      (0x0000000f)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC) >> BP_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC.
#define BF_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC) & BM_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_LOGIC field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC(v)   (HW_EPDC_HW_EPDC_PIGEON_16_2_WR((HW_EPDC_HW_EPDC_PIGEON_16_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC) | BF_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC(v)))
#endif

#define BV_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC__DIS (0x0) //!< no logic operation
#define BV_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC__AND (0x1) //!< sigout = sig_another AND this_sig
#define BV_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC__OR (0x2) //!< sigout = sig_another OR this_sig
#define BV_EPDC_HW_EPDC_PIGEON_16_2_SIG_LOGIC__MASK (0x3) //!< mask = sig_another AND other_masks

/* --- Register HW_EPDC_HW_EPDC_PIGEON_16_2, field SIG_ANOTHER[8:4] (RW)
 *
 * select another signal for logic operation or as mask or counter tick event
 */

#define BP_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER      (4)      //!< Bit position for EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER.
#define BM_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER      (0x000001f0)  //!< Bit mask for EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER.

//! @brief Get value of EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER from a register value.
#define BG_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER) >> BP_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER)

//! @brief Format value for bitfield EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER.
#define BF_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER) & BM_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIG_ANOTHER field to a new value.
#define BW_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER(v)   (HW_EPDC_HW_EPDC_PIGEON_16_2_WR((HW_EPDC_HW_EPDC_PIGEON_16_2_RD() & ~BM_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER) | BF_EPDC_HW_EPDC_PIGEON_16_2_SIG_ANOTHER(v)))
#endif


/*!
 * @brief All EPDC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_epdc
{
    volatile hw_epdc_hw_epdc_ctrl_t HW_EPDC_CTRL; //!< EPDC Control Register
    reg32_t _reserved0[7];
    volatile hw_epdc_hw_epdc_wvaddr_t HW_EPDC_WVADDR; //!< EPDC Waveform Address Pointer
    reg32_t _reserved1[3];
    volatile hw_epdc_hw_epdc_wb_addr_t HW_EPDC_WB_ADDR; //!< EPDC Working Buffer Address
    reg32_t _reserved2[3];
    volatile hw_epdc_hw_epdc_res_t HW_EPDC_RES; //!< EPDC Screen Resolution
    reg32_t _reserved3[3];
    volatile hw_epdc_hw_epdc_format_t HW_EPDC_FORMAT; //!< EPDC Format Control Register
    reg32_t _reserved4[19];
    volatile hw_epdc_hw_epdc_fifoctrl_t HW_EPDC_FIFOCTRL; //!< EPDC FIFO control register
    reg32_t _reserved5[23];
    volatile hw_epdc_hw_epdc_upd_addr_t HW_EPDC_UPD_ADDR; //!< EPDC Update Region Address
    reg32_t _reserved6[3];
    volatile hw_epdc_hw_epdc_upd_stride_t HW_EPDC_UPD_STRIDE; //!< EPDC Update Region Stride
    reg32_t _reserved7[3];
    volatile hw_epdc_hw_epdc_upd_cord_t HW_EPDC_UPD_CORD; //!< EPDC Update Command Co-ordinate
    reg32_t _reserved8[7];
    volatile hw_epdc_hw_epdc_upd_size_t HW_EPDC_UPD_SIZE; //!< EPDC Update Command Size
    reg32_t _reserved9[7];
    volatile hw_epdc_hw_epdc_upd_ctrl_t HW_EPDC_UPD_CTRL; //!< EPDC Update Command Control
    reg32_t _reserved10[7];
    volatile hw_epdc_hw_epdc_upd_fixed_t HW_EPDC_UPD_FIXED; //!< EPDC Update Fixed Pixel Control
    reg32_t _reserved11[7];
    volatile hw_epdc_hw_epdc_temp_t HW_EPDC_TEMP; //!< EPDC Temperature Register
    reg32_t _reserved12[7];
    volatile hw_epdc_hw_epdc_autowv_lut_t HW_EPDC_AUTOWV_LUT; //!< Waveform Mode Lookup Table Control Register.
    reg32_t _reserved13[15];
    volatile hw_epdc_hw_epdc_tce_ctrl_t HW_EPDC_TCE_CTRL; //!< EPDC Timing Control Engine Control Register
    reg32_t _reserved14[7];
    volatile hw_epdc_hw_epdc_tce_sdcfg_t HW_EPDC_TCE_SDCFG; //!< EPDC Timing Control Engine Source-Driver Config Register
    reg32_t _reserved15[7];
    volatile hw_epdc_hw_epdc_tce_gdcfg_t HW_EPDC_TCE_GDCFG; //!< EPDC Timing Control Engine Gate-Driver Config Register
    reg32_t _reserved16[7];
    volatile hw_epdc_hw_epdc_tce_hscan1_t HW_EPDC_TCE_HSCAN1; //!< EPDC Timing Control Engine Horizontal Timing Register 1
    reg32_t _reserved17[7];
    volatile hw_epdc_hw_epdc_tce_hscan2_t HW_EPDC_TCE_HSCAN2; //!< EPDC Timing Control Engine Horizontal Timing Register 2
    reg32_t _reserved18[7];
    volatile hw_epdc_hw_epdc_tce_vscan_t HW_EPDC_TCE_VSCAN; //!< EPDC Timing Control Engine Vertical Timing Register
    reg32_t _reserved19[7];
    volatile hw_epdc_hw_epdc_tce_oe_t HW_EPDC_TCE_OE; //!< EPDC Timing Control Engine OE timing control Register
    reg32_t _reserved20[7];
    volatile hw_epdc_hw_epdc_tce_polarity_t HW_EPDC_TCE_POLARITY; //!< EPDC Timing Control Engine Driver Polarity Register
    reg32_t _reserved21[7];
    volatile hw_epdc_hw_epdc_tce_timing1_t HW_EPDC_TCE_TIMING1; //!< EPDC Timing Control Engine Timing Register 1
    reg32_t _reserved22[3];
    volatile hw_epdc_hw_epdc_tce_timing2_t HW_EPDC_TCE_TIMING2; //!< EPDC Timing Control Engine Timing Register 2
    reg32_t _reserved23[3];
    volatile hw_epdc_hw_epdc_tce_timing3_t HW_EPDC_TCE_TIMING3; //!< EPDC Timing Control Engine Timing Register 3
    reg32_t _reserved24[23];
    volatile hw_epdc_hw_epdc_pigeon_ctrl0_t HW_EPDC_PIGEON_CTRL0; //!< EPDC Pigeon Mode Control Register 0
    reg32_t _reserved25[3];
    volatile hw_epdc_hw_epdc_pigeon_ctrl1_t HW_EPDC_PIGEON_CTRL1; //!< EPDC Pigeon Mode Control Register 1
    reg32_t _reserved26[11];
    volatile hw_epdc_hw_epdc_irq_mask1_t HW_EPDC_IRQ_MASK1; //!< EPDC IRQ Mask Register for LUT 0~31
    reg32_t _reserved27[3];
    volatile hw_epdc_hw_epdc_irq_mask2_t HW_EPDC_IRQ_MASK2; //!< EPDC IRQ Mask Register for LUT 32~63
    reg32_t _reserved28[3];
    volatile hw_epdc_hw_epdc_irq1_t HW_EPDC_IRQ1; //!< EPDC Interrupt Register for LUT 0~31
    reg32_t _reserved29[3];
    volatile hw_epdc_hw_epdc_irq2_t HW_EPDC_IRQ2; //!< EPDC Interrupt Registerr for LUT 32~63
    reg32_t _reserved30[3];
    volatile hw_epdc_hw_epdc_irq_mask_t HW_EPDC_IRQ_MASK; //!< EPDC IRQ Mask Register
    reg32_t _reserved31[7];
    volatile hw_epdc_hw_epdc_irq_t HW_EPDC_IRQ; //!< EPDC Interrupt Register
    reg32_t _reserved32[7];
    volatile hw_epdc_hw_epdc_status_luts1_t HW_EPDC_STATUS_LUTS1; //!< EPDC Status Register - LUTs
    reg32_t _reserved33[3];
    volatile hw_epdc_hw_epdc_status_luts2_t HW_EPDC_STATUS_LUTS2; //!< EPDC Status Register - LUTs
    reg32_t _reserved34[3];
    volatile hw_epdc_hw_epdc_status_nextlut_t HW_EPDC_STATUS_NEXTLUT; //!< EPDC Status Register - Next Available LUT
    reg32_t _reserved35[7];
    volatile hw_epdc_hw_epdc_status_col1_t HW_EPDC_STATUS_COL1; //!< EPDC LUT Collision Status
    reg32_t _reserved36[3];
    volatile hw_epdc_hw_epdc_status_col2_t HW_EPDC_STATUS_COL2; //!< EPDC LUT Collision Status
    reg32_t _reserved37[3];
    volatile hw_epdc_hw_epdc_status_t HW_EPDC_STATUS; //!< EPDC General Status Register
    reg32_t _reserved38[7];
    volatile hw_epdc_hw_epdc_upd_col_cord_t HW_EPDC_UPD_COL_CORD; //!< EPDC Collision Region Co-ordinate
    reg32_t _reserved39[7];
    volatile hw_epdc_hw_epdc_upd_col_size_t HW_EPDC_UPD_COL_SIZE; //!< EPDC Collision Region Size
    reg32_t _reserved40[7];
    volatile hw_epdc_hw_epdc_debug_t HW_EPDC_DEBUG; //!< EPDC Debug register
    reg32_t _reserved41[11];
    volatile hw_epdc_hw_epdc_debug_lut_t HW_EPDC_DEBUG_LUT; //!< EPDC LUT Debug Information register
    reg32_t _reserved42[51];
    volatile hw_epdc_hw_epdc_hist1_param_t HW_EPDC_HIST1_PARAM; //!< 1-level Histogram Parameter Register.
    reg32_t _reserved43[3];
    volatile hw_epdc_hw_epdc_hist2_param_t HW_EPDC_HIST2_PARAM; //!< 2-level Histogram Parameter Register.
    reg32_t _reserved44[3];
    volatile hw_epdc_hw_epdc_hist4_param_t HW_EPDC_HIST4_PARAM; //!< 4-level Histogram Parameter Register.
    reg32_t _reserved45[3];
    volatile hw_epdc_hw_epdc_hist8_param0_t HW_EPDC_HIST8_PARAM0; //!< 8-level Histogram Parameter 0 Register.
    reg32_t _reserved46[3];
    volatile hw_epdc_hw_epdc_hist8_param1_t HW_EPDC_HIST8_PARAM1; //!< 8-level Histogram Parameter 1 Register.
    reg32_t _reserved47[3];
    volatile hw_epdc_hw_epdc_hist16_param0_t HW_EPDC_HIST16_PARAM0; //!< 16-level Histogram Parameter 0 Register.
    reg32_t _reserved48[3];
    volatile hw_epdc_hw_epdc_hist16_param1_t HW_EPDC_HIST16_PARAM1; //!< 16-level Histogram Parameter Register.
    reg32_t _reserved49[3];
    volatile hw_epdc_hw_epdc_hist16_param2_t HW_EPDC_HIST16_PARAM2; //!< 16-level Histogram Parameter Register.
    reg32_t _reserved50[3];
    volatile hw_epdc_hw_epdc_hist16_param3_t HW_EPDC_HIST16_PARAM3; //!< 16-level Histogram Parameter Register.
    reg32_t _reserved51[31];
    volatile hw_epdc_hw_epdc_gpio_t HW_EPDC_GPIO; //!< EPDC General Purpose I/O Debug register
    reg32_t _reserved52[59];
    volatile hw_epdc_hw_epdc_version_t HW_EPDC_VERSION; //!< EPDC Version Register
    reg32_t _reserved53[3];
    volatile hw_epdc_hw_epdc_pigeon_0_0_t HW_EPDC_PIGEON_0_0; //!< Panel Interface Signal Generator Register 0_0
    reg32_t _reserved54[3];
    volatile hw_epdc_hw_epdc_pigeon_0_1_t HW_EPDC_PIGEON_0_1; //!< Panel Interface Signal Generator Register 0_1
    reg32_t _reserved55[3];
    volatile hw_epdc_hw_epdc_pigeon_0_2_t HW_EPDC_PIGEON_0_2; //!< Panel Interface Signal Generator Register 0_1
    reg32_t _reserved56[7];
    volatile hw_epdc_hw_epdc_pigeon_1_0_t HW_EPDC_PIGEON_1_0; //!< Panel Interface Signal Generator Register 1_0
    reg32_t _reserved57[3];
    volatile hw_epdc_hw_epdc_pigeon_1_1_t HW_EPDC_PIGEON_1_1; //!< Panel Interface Signal Generator Register 1_1
    reg32_t _reserved58[3];
    volatile hw_epdc_hw_epdc_pigeon_1_2_t HW_EPDC_PIGEON_1_2; //!< Panel Interface Signal Generator Register 1_1
    reg32_t _reserved59[7];
    volatile hw_epdc_hw_epdc_pigeon_2_0_t HW_EPDC_PIGEON_2_0; //!< Panel Interface Signal Generator Register 2_0
    reg32_t _reserved60[3];
    volatile hw_epdc_hw_epdc_pigeon_2_1_t HW_EPDC_PIGEON_2_1; //!< Panel Interface Signal Generator Register 2_1
    reg32_t _reserved61[3];
    volatile hw_epdc_hw_epdc_pigeon_2_2_t HW_EPDC_PIGEON_2_2; //!< Panel Interface Signal Generator Register 2_1
    reg32_t _reserved62[7];
    volatile hw_epdc_hw_epdc_pigeon_3_0_t HW_EPDC_PIGEON_3_0; //!< Panel Interface Signal Generator Register 3_0
    reg32_t _reserved63[3];
    volatile hw_epdc_hw_epdc_pigeon_3_1_t HW_EPDC_PIGEON_3_1; //!< Panel Interface Signal Generator Register 3_1
    reg32_t _reserved64[3];
    volatile hw_epdc_hw_epdc_pigeon_3_2_t HW_EPDC_PIGEON_3_2; //!< Panel Interface Signal Generator Register 3_1
    reg32_t _reserved65[7];
    volatile hw_epdc_hw_epdc_pigeon_4_0_t HW_EPDC_PIGEON_4_0; //!< Panel Interface Signal Generator Register 4_0
    reg32_t _reserved66[3];
    volatile hw_epdc_hw_epdc_pigeon_4_1_t HW_EPDC_PIGEON_4_1; //!< Panel Interface Signal Generator Register 4_1
    reg32_t _reserved67[3];
    volatile hw_epdc_hw_epdc_pigeon_4_2_t HW_EPDC_PIGEON_4_2; //!< Panel Interface Signal Generator Register 4_1
    reg32_t _reserved68[7];
    volatile hw_epdc_hw_epdc_pigeon_5_0_t HW_EPDC_PIGEON_5_0; //!< Panel Interface Signal Generator Register 5_0
    reg32_t _reserved69[3];
    volatile hw_epdc_hw_epdc_pigeon_5_1_t HW_EPDC_PIGEON_5_1; //!< Panel Interface Signal Generator Register 5_1
    reg32_t _reserved70[3];
    volatile hw_epdc_hw_epdc_pigeon_5_2_t HW_EPDC_PIGEON_5_2; //!< Panel Interface Signal Generator Register 5_1
    reg32_t _reserved71[7];
    volatile hw_epdc_hw_epdc_pigeon_6_0_t HW_EPDC_PIGEON_6_0; //!< Panel Interface Signal Generator Register 6_0
    reg32_t _reserved72[3];
    volatile hw_epdc_hw_epdc_pigeon_6_1_t HW_EPDC_PIGEON_6_1; //!< Panel Interface Signal Generator Register 6_1
    reg32_t _reserved73[3];
    volatile hw_epdc_hw_epdc_pigeon_6_2_t HW_EPDC_PIGEON_6_2; //!< Panel Interface Signal Generator Register 6_1
    reg32_t _reserved74[7];
    volatile hw_epdc_hw_epdc_pigeon_7_0_t HW_EPDC_PIGEON_7_0; //!< Panel Interface Signal Generator Register 7_0
    reg32_t _reserved75[3];
    volatile hw_epdc_hw_epdc_pigeon_7_1_t HW_EPDC_PIGEON_7_1; //!< Panel Interface Signal Generator Register 7_1
    reg32_t _reserved76[3];
    volatile hw_epdc_hw_epdc_pigeon_7_2_t HW_EPDC_PIGEON_7_2; //!< Panel Interface Signal Generator Register 7_1
    reg32_t _reserved77[7];
    volatile hw_epdc_hw_epdc_pigeon_8_0_t HW_EPDC_PIGEON_8_0; //!< Panel Interface Signal Generator Register 8_0
    reg32_t _reserved78[3];
    volatile hw_epdc_hw_epdc_pigeon_8_1_t HW_EPDC_PIGEON_8_1; //!< Panel Interface Signal Generator Register 8_1
    reg32_t _reserved79[3];
    volatile hw_epdc_hw_epdc_pigeon_8_2_t HW_EPDC_PIGEON_8_2; //!< Panel Interface Signal Generator Register 8_1
    reg32_t _reserved80[7];
    volatile hw_epdc_hw_epdc_pigeon_9_0_t HW_EPDC_PIGEON_9_0; //!< Panel Interface Signal Generator Register 9_0
    reg32_t _reserved81[3];
    volatile hw_epdc_hw_epdc_pigeon_9_1_t HW_EPDC_PIGEON_9_1; //!< Panel Interface Signal Generator Register 9_1
    reg32_t _reserved82[3];
    volatile hw_epdc_hw_epdc_pigeon_9_2_t HW_EPDC_PIGEON_9_2; //!< Panel Interface Signal Generator Register 9_1
    reg32_t _reserved83[7];
    volatile hw_epdc_hw_epdc_pigeon_10_0_t HW_EPDC_PIGEON_10_0; //!< Panel Interface Signal Generator Register 10_0
    reg32_t _reserved84[3];
    volatile hw_epdc_hw_epdc_pigeon_10_1_t HW_EPDC_PIGEON_10_1; //!< Panel Interface Signal Generator Register 10_1
    reg32_t _reserved85[3];
    volatile hw_epdc_hw_epdc_pigeon_10_2_t HW_EPDC_PIGEON_10_2; //!< Panel Interface Signal Generator Register 10_1
    reg32_t _reserved86[7];
    volatile hw_epdc_hw_epdc_pigeon_11_0_t HW_EPDC_PIGEON_11_0; //!< Panel Interface Signal Generator Register 11_0
    reg32_t _reserved87[3];
    volatile hw_epdc_hw_epdc_pigeon_11_1_t HW_EPDC_PIGEON_11_1; //!< Panel Interface Signal Generator Register 11_1
    reg32_t _reserved88[3];
    volatile hw_epdc_hw_epdc_pigeon_11_2_t HW_EPDC_PIGEON_11_2; //!< Panel Interface Signal Generator Register 11_1
    reg32_t _reserved89[7];
    volatile hw_epdc_hw_epdc_pigeon_12_0_t HW_EPDC_PIGEON_12_0; //!< Panel Interface Signal Generator Register 12_0
    reg32_t _reserved90[3];
    volatile hw_epdc_hw_epdc_pigeon_12_1_t HW_EPDC_PIGEON_12_1; //!< Panel Interface Signal Generator Register 12_1
    reg32_t _reserved91[3];
    volatile hw_epdc_hw_epdc_pigeon_12_2_t HW_EPDC_PIGEON_12_2; //!< Panel Interface Signal Generator Register 12_1
    reg32_t _reserved92[7];
    volatile hw_epdc_hw_epdc_pigeon_13_0_t HW_EPDC_PIGEON_13_0; //!< Panel Interface Signal Generator Register 13_0
    reg32_t _reserved93[3];
    volatile hw_epdc_hw_epdc_pigeon_13_1_t HW_EPDC_PIGEON_13_1; //!< Panel Interface Signal Generator Register 13_1
    reg32_t _reserved94[3];
    volatile hw_epdc_hw_epdc_pigeon_13_2_t HW_EPDC_PIGEON_13_2; //!< Panel Interface Signal Generator Register 13_1
    reg32_t _reserved95[7];
    volatile hw_epdc_hw_epdc_pigeon_14_0_t HW_EPDC_PIGEON_14_0; //!< Panel Interface Signal Generator Register 14_0
    reg32_t _reserved96[3];
    volatile hw_epdc_hw_epdc_pigeon_14_1_t HW_EPDC_PIGEON_14_1; //!< Panel Interface Signal Generator Register 14_1
    reg32_t _reserved97[3];
    volatile hw_epdc_hw_epdc_pigeon_14_2_t HW_EPDC_PIGEON_14_2; //!< Panel Interface Signal Generator Register 14_1
    reg32_t _reserved98[7];
    volatile hw_epdc_hw_epdc_pigeon_15_0_t HW_EPDC_PIGEON_15_0; //!< Panel Interface Signal Generator Register 15_0
    reg32_t _reserved99[3];
    volatile hw_epdc_hw_epdc_pigeon_15_1_t HW_EPDC_PIGEON_15_1; //!< Panel Interface Signal Generator Register 15_1
    reg32_t _reserved100[3];
    volatile hw_epdc_hw_epdc_pigeon_15_2_t HW_EPDC_PIGEON_15_2; //!< Panel Interface Signal Generator Register 15_1
    reg32_t _reserved101[7];
    volatile hw_epdc_hw_epdc_pigeon_16_0_t HW_EPDC_PIGEON_16_0; //!< Panel Interface Signal Generator Register 16_0
    reg32_t _reserved102[3];
    volatile hw_epdc_hw_epdc_pigeon_16_1_t HW_EPDC_PIGEON_16_1; //!< Panel Interface Signal Generator Register 16_1
    reg32_t _reserved103[3];
    volatile hw_epdc_hw_epdc_pigeon_16_2_t HW_EPDC_PIGEON_16_2; //!< Panel Interface Signal Generator Register 16_1
} hw_epdc_t;
#pragma pack()

//! @brief Macro to access all EPDC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_EPDC(0)</code>.
#define HW_EPDC     (*(volatile hw_epdc_t *) REGS_EPDC_BASE)

#endif


#endif // __HW_EPDC_REGISTERS_H__
