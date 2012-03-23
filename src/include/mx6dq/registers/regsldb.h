/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_LDB_REGISTERS_H__
#define __HW_LDB_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ LDB registers defined in this header file.
 *
 * - HW_LDB_CTRL - LDB Control Register
 *
 * - hw_ldb_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_LDB_BASE
#define HW_LDB_INSTANCE_COUNT (1) //!< Number of instances of the LDB module.
#define REGS_LDB_BASE (0x00000000) //!< Base address for LDB.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_LDB_CTRL - LDB Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The register is implemented in the IOMUX Controller block (IOMUXC), as the register IOMUXC_GPR2.
 */
typedef union _hw_ldb_ctrl
{
    reg32_t U;
    struct _hw_ldb_ctrl_bitfields
    {
        unsigned CH0_MODE : 2; //!< [1:0] LVDS channel 0 operation mode
        unsigned CH1_MODE : 2; //!< [3:2] LVDS channel 1 operation mode
        unsigned SPLIT_MODE_EN : 1; //!< [4] Enable split mode. In this mode both channels should be enabled and working with the same DI (ch0_mode and ch1_mode should both be either '01' or '11')
        unsigned DATA_WIDTH_CH0 : 1; //!< [5] Data width for LVDS channel 0. This bit must be set when using JEIDA standard (bit_mapping_ch0 is set)
        unsigned BIT_MAPPING_CH0 : 1; //!< [6] Data mapping for LVDS channel 0.
        unsigned DATA_WIDTH_CH1 : 1; //!< [7] Data width for LVDS channel 1. This bit must be set when using JEIDA standard (bit_mapping_ch1 is set)
        unsigned BIT_MAPPING_CH1 : 1; //!< [8] Data mapping for LVDS channel 1.
        unsigned DI0_VS_POLARITY : 1; //!< [9] Vsync polarity for IPU's DI0 interface.
        unsigned DI1_VS_POLARITY : 1; //!< [10] Vsync polarity for IPU's DI1 interface.
        unsigned RESERVED0 : 4; //!< [14:11] Reserved
        unsigned BGREF_RRMODE : 1; //!< [15] Select reference resistor for bandgap
        unsigned LVDS_CLK_SHIFT : 3; //!< [18:16] Shifts the LVDS output clock in relation to the data. Used for debug purposes only. In normal functional operation must be '000'
        unsigned RESERVED1 : 1; //!< [19] Reserved
        unsigned COUNTER_RESET_VAL : 2; //!< [21:20] Reset value for the LDB counter which determines when the shift registers are loaded with data. Used for debug purposes only. In normal functional operation must be '00'
        unsigned RESERVED2 : 10; //!< [31:22] Reserved
    } B;
} hw_ldb_ctrl_t;
#endif

/*
 * constants & macros for entire LDB_CTRL register
 */
#define HW_LDB_CTRL_ADDR      (REGS_LDB_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_LDB_CTRL           (*(volatile hw_ldb_ctrl_t *) HW_LDB_CTRL_ADDR)
#define HW_LDB_CTRL_RD()      (HW_LDB_CTRL.U)
#define HW_LDB_CTRL_WR(v)     (HW_LDB_CTRL.U = (v))
#define HW_LDB_CTRL_SET(v)    (HW_LDB_CTRL_WR(HW_LDB_CTRL_RD() |  (v)))
#define HW_LDB_CTRL_CLR(v)    (HW_LDB_CTRL_WR(HW_LDB_CTRL_RD() & ~(v)))
#define HW_LDB_CTRL_TOG(v)    (HW_LDB_CTRL_WR(HW_LDB_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual LDB_CTRL bitfields
 */

/* --- Register HW_LDB_CTRL, field CH0_MODE[1:0] (RW)
 *
 * LVDS channel 0 operation mode
 *
 * Values:
 * 00 - Channel disabled.
 * 01 - Channel enabled, routed to DI0
 * 10 - Channel disabled.
 * 11 - Channel enabled, routed to DI1.
 */

#define BP_LDB_CTRL_CH0_MODE      (0)      //!< Bit position for LDB_CTRL_CH0_MODE.
#define BM_LDB_CTRL_CH0_MODE      (0x00000003)  //!< Bit mask for LDB_CTRL_CH0_MODE.

//! @brief Get value of LDB_CTRL_CH0_MODE from a register value.
#define BG_LDB_CTRL_CH0_MODE(r)   (((r) & BM_LDB_CTRL_CH0_MODE) >> BP_LDB_CTRL_CH0_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_CH0_MODE.
#define BF_LDB_CTRL_CH0_MODE(v)   ((((reg32_t) v) << BP_LDB_CTRL_CH0_MODE) & BM_LDB_CTRL_CH0_MODE)
#else
//! @brief Format value for bitfield LDB_CTRL_CH0_MODE.
#define BF_LDB_CTRL_CH0_MODE(v)   (((v) << BP_LDB_CTRL_CH0_MODE) & BM_LDB_CTRL_CH0_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0_MODE field to a new value.
#define BW_LDB_CTRL_CH0_MODE(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_CH0_MODE) | BF_LDB_CTRL_CH0_MODE(v)))
#endif


/* --- Register HW_LDB_CTRL, field CH1_MODE[3:2] (RW)
 *
 * LVDS channel 1 operation mode
 *
 * Values:
 * 00 - Channel disabled.
 * 01 - Channel enabled, routed to DI0
 * 10 - Channel disabled.
 * 11 - Channel enabled, routed to DI1.
 */

#define BP_LDB_CTRL_CH1_MODE      (2)      //!< Bit position for LDB_CTRL_CH1_MODE.
#define BM_LDB_CTRL_CH1_MODE      (0x0000000c)  //!< Bit mask for LDB_CTRL_CH1_MODE.

//! @brief Get value of LDB_CTRL_CH1_MODE from a register value.
#define BG_LDB_CTRL_CH1_MODE(r)   (((r) & BM_LDB_CTRL_CH1_MODE) >> BP_LDB_CTRL_CH1_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_CH1_MODE.
#define BF_LDB_CTRL_CH1_MODE(v)   ((((reg32_t) v) << BP_LDB_CTRL_CH1_MODE) & BM_LDB_CTRL_CH1_MODE)
#else
//! @brief Format value for bitfield LDB_CTRL_CH1_MODE.
#define BF_LDB_CTRL_CH1_MODE(v)   (((v) << BP_LDB_CTRL_CH1_MODE) & BM_LDB_CTRL_CH1_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CH1_MODE field to a new value.
#define BW_LDB_CTRL_CH1_MODE(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_CH1_MODE) | BF_LDB_CTRL_CH1_MODE(v)))
#endif


/* --- Register HW_LDB_CTRL, field SPLIT_MODE_EN[4] (RW)
 *
 * Enable split mode. In this mode both channels should be enabled and working with the same DI
 * (ch0_mode and ch1_mode should both be either '01' or '11')
 *
 * Values:
 * 0 - Split mode is disabled.
 * 1 - Split mode is enabled.
 */

#define BP_LDB_CTRL_SPLIT_MODE_EN      (4)      //!< Bit position for LDB_CTRL_SPLIT_MODE_EN.
#define BM_LDB_CTRL_SPLIT_MODE_EN      (0x00000010)  //!< Bit mask for LDB_CTRL_SPLIT_MODE_EN.

//! @brief Get value of LDB_CTRL_SPLIT_MODE_EN from a register value.
#define BG_LDB_CTRL_SPLIT_MODE_EN(r)   (((r) & BM_LDB_CTRL_SPLIT_MODE_EN) >> BP_LDB_CTRL_SPLIT_MODE_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_SPLIT_MODE_EN.
#define BF_LDB_CTRL_SPLIT_MODE_EN(v)   ((((reg32_t) v) << BP_LDB_CTRL_SPLIT_MODE_EN) & BM_LDB_CTRL_SPLIT_MODE_EN)
#else
//! @brief Format value for bitfield LDB_CTRL_SPLIT_MODE_EN.
#define BF_LDB_CTRL_SPLIT_MODE_EN(v)   (((v) << BP_LDB_CTRL_SPLIT_MODE_EN) & BM_LDB_CTRL_SPLIT_MODE_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPLIT_MODE_EN field to a new value.
#define BW_LDB_CTRL_SPLIT_MODE_EN(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_SPLIT_MODE_EN) | BF_LDB_CTRL_SPLIT_MODE_EN(v)))
#endif


/* --- Register HW_LDB_CTRL, field DATA_WIDTH_CH0[5] (RW)
 *
 * Data width for LVDS channel 0. This bit must be set when using JEIDA standard (bit_mapping_ch0 is
 * set)
 *
 * Values:
 * 0 - Data width is 18 bits wide (lvds0_tx3 is not used)
 * 1 - Data width is 24 bits wide.
 */

#define BP_LDB_CTRL_DATA_WIDTH_CH0      (5)      //!< Bit position for LDB_CTRL_DATA_WIDTH_CH0.
#define BM_LDB_CTRL_DATA_WIDTH_CH0      (0x00000020)  //!< Bit mask for LDB_CTRL_DATA_WIDTH_CH0.

//! @brief Get value of LDB_CTRL_DATA_WIDTH_CH0 from a register value.
#define BG_LDB_CTRL_DATA_WIDTH_CH0(r)   (((r) & BM_LDB_CTRL_DATA_WIDTH_CH0) >> BP_LDB_CTRL_DATA_WIDTH_CH0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_DATA_WIDTH_CH0.
#define BF_LDB_CTRL_DATA_WIDTH_CH0(v)   ((((reg32_t) v) << BP_LDB_CTRL_DATA_WIDTH_CH0) & BM_LDB_CTRL_DATA_WIDTH_CH0)
#else
//! @brief Format value for bitfield LDB_CTRL_DATA_WIDTH_CH0.
#define BF_LDB_CTRL_DATA_WIDTH_CH0(v)   (((v) << BP_LDB_CTRL_DATA_WIDTH_CH0) & BM_LDB_CTRL_DATA_WIDTH_CH0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_WIDTH_CH0 field to a new value.
#define BW_LDB_CTRL_DATA_WIDTH_CH0(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_DATA_WIDTH_CH0) | BF_LDB_CTRL_DATA_WIDTH_CH0(v)))
#endif


/* --- Register HW_LDB_CTRL, field BIT_MAPPING_CH0[6] (RW)
 *
 * Data mapping for LVDS channel 0.
 *
 * Values:
 * 0 - Use SPWG standard.
 * 1 - Use JEIDA standard.
 */

#define BP_LDB_CTRL_BIT_MAPPING_CH0      (6)      //!< Bit position for LDB_CTRL_BIT_MAPPING_CH0.
#define BM_LDB_CTRL_BIT_MAPPING_CH0      (0x00000040)  //!< Bit mask for LDB_CTRL_BIT_MAPPING_CH0.

//! @brief Get value of LDB_CTRL_BIT_MAPPING_CH0 from a register value.
#define BG_LDB_CTRL_BIT_MAPPING_CH0(r)   (((r) & BM_LDB_CTRL_BIT_MAPPING_CH0) >> BP_LDB_CTRL_BIT_MAPPING_CH0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_BIT_MAPPING_CH0.
#define BF_LDB_CTRL_BIT_MAPPING_CH0(v)   ((((reg32_t) v) << BP_LDB_CTRL_BIT_MAPPING_CH0) & BM_LDB_CTRL_BIT_MAPPING_CH0)
#else
//! @brief Format value for bitfield LDB_CTRL_BIT_MAPPING_CH0.
#define BF_LDB_CTRL_BIT_MAPPING_CH0(v)   (((v) << BP_LDB_CTRL_BIT_MAPPING_CH0) & BM_LDB_CTRL_BIT_MAPPING_CH0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BIT_MAPPING_CH0 field to a new value.
#define BW_LDB_CTRL_BIT_MAPPING_CH0(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_BIT_MAPPING_CH0) | BF_LDB_CTRL_BIT_MAPPING_CH0(v)))
#endif


/* --- Register HW_LDB_CTRL, field DATA_WIDTH_CH1[7] (RW)
 *
 * Data width for LVDS channel 1. This bit must be set when using JEIDA standard (bit_mapping_ch1 is
 * set)
 *
 * Values:
 * 0 - Data width is 18 bits wide (lvds1_tx3 is not used)
 * 1 - Data width is 24 bits wide.
 */

#define BP_LDB_CTRL_DATA_WIDTH_CH1      (7)      //!< Bit position for LDB_CTRL_DATA_WIDTH_CH1.
#define BM_LDB_CTRL_DATA_WIDTH_CH1      (0x00000080)  //!< Bit mask for LDB_CTRL_DATA_WIDTH_CH1.

//! @brief Get value of LDB_CTRL_DATA_WIDTH_CH1 from a register value.
#define BG_LDB_CTRL_DATA_WIDTH_CH1(r)   (((r) & BM_LDB_CTRL_DATA_WIDTH_CH1) >> BP_LDB_CTRL_DATA_WIDTH_CH1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_DATA_WIDTH_CH1.
#define BF_LDB_CTRL_DATA_WIDTH_CH1(v)   ((((reg32_t) v) << BP_LDB_CTRL_DATA_WIDTH_CH1) & BM_LDB_CTRL_DATA_WIDTH_CH1)
#else
//! @brief Format value for bitfield LDB_CTRL_DATA_WIDTH_CH1.
#define BF_LDB_CTRL_DATA_WIDTH_CH1(v)   (((v) << BP_LDB_CTRL_DATA_WIDTH_CH1) & BM_LDB_CTRL_DATA_WIDTH_CH1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_WIDTH_CH1 field to a new value.
#define BW_LDB_CTRL_DATA_WIDTH_CH1(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_DATA_WIDTH_CH1) | BF_LDB_CTRL_DATA_WIDTH_CH1(v)))
#endif


/* --- Register HW_LDB_CTRL, field BIT_MAPPING_CH1[8] (RW)
 *
 * Data mapping for LVDS channel 1.
 *
 * Values:
 * 0 - Use SPWG standard.
 * 1 - Use JEIDA standard.
 */

#define BP_LDB_CTRL_BIT_MAPPING_CH1      (8)      //!< Bit position for LDB_CTRL_BIT_MAPPING_CH1.
#define BM_LDB_CTRL_BIT_MAPPING_CH1      (0x00000100)  //!< Bit mask for LDB_CTRL_BIT_MAPPING_CH1.

//! @brief Get value of LDB_CTRL_BIT_MAPPING_CH1 from a register value.
#define BG_LDB_CTRL_BIT_MAPPING_CH1(r)   (((r) & BM_LDB_CTRL_BIT_MAPPING_CH1) >> BP_LDB_CTRL_BIT_MAPPING_CH1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_BIT_MAPPING_CH1.
#define BF_LDB_CTRL_BIT_MAPPING_CH1(v)   ((((reg32_t) v) << BP_LDB_CTRL_BIT_MAPPING_CH1) & BM_LDB_CTRL_BIT_MAPPING_CH1)
#else
//! @brief Format value for bitfield LDB_CTRL_BIT_MAPPING_CH1.
#define BF_LDB_CTRL_BIT_MAPPING_CH1(v)   (((v) << BP_LDB_CTRL_BIT_MAPPING_CH1) & BM_LDB_CTRL_BIT_MAPPING_CH1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BIT_MAPPING_CH1 field to a new value.
#define BW_LDB_CTRL_BIT_MAPPING_CH1(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_BIT_MAPPING_CH1) | BF_LDB_CTRL_BIT_MAPPING_CH1(v)))
#endif


/* --- Register HW_LDB_CTRL, field DI0_VS_POLARITY[9] (RW)
 *
 * Vsync polarity for IPU's DI0 interface.
 *
 * Values:
 * 0 - ipu_di0_vsync is active high.
 * 1 - ipu_di0_vsync is active low.
 */

#define BP_LDB_CTRL_DI0_VS_POLARITY      (9)      //!< Bit position for LDB_CTRL_DI0_VS_POLARITY.
#define BM_LDB_CTRL_DI0_VS_POLARITY      (0x00000200)  //!< Bit mask for LDB_CTRL_DI0_VS_POLARITY.

//! @brief Get value of LDB_CTRL_DI0_VS_POLARITY from a register value.
#define BG_LDB_CTRL_DI0_VS_POLARITY(r)   (((r) & BM_LDB_CTRL_DI0_VS_POLARITY) >> BP_LDB_CTRL_DI0_VS_POLARITY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_DI0_VS_POLARITY.
#define BF_LDB_CTRL_DI0_VS_POLARITY(v)   ((((reg32_t) v) << BP_LDB_CTRL_DI0_VS_POLARITY) & BM_LDB_CTRL_DI0_VS_POLARITY)
#else
//! @brief Format value for bitfield LDB_CTRL_DI0_VS_POLARITY.
#define BF_LDB_CTRL_DI0_VS_POLARITY(v)   (((v) << BP_LDB_CTRL_DI0_VS_POLARITY) & BM_LDB_CTRL_DI0_VS_POLARITY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DI0_VS_POLARITY field to a new value.
#define BW_LDB_CTRL_DI0_VS_POLARITY(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_DI0_VS_POLARITY) | BF_LDB_CTRL_DI0_VS_POLARITY(v)))
#endif


/* --- Register HW_LDB_CTRL, field DI1_VS_POLARITY[10] (RW)
 *
 * Vsync polarity for IPU's DI1 interface.
 *
 * Values:
 * 0 - ipu_di1_vsync is active high.
 * 1 - ipu_di1_vsync is active low.
 */

#define BP_LDB_CTRL_DI1_VS_POLARITY      (10)      //!< Bit position for LDB_CTRL_DI1_VS_POLARITY.
#define BM_LDB_CTRL_DI1_VS_POLARITY      (0x00000400)  //!< Bit mask for LDB_CTRL_DI1_VS_POLARITY.

//! @brief Get value of LDB_CTRL_DI1_VS_POLARITY from a register value.
#define BG_LDB_CTRL_DI1_VS_POLARITY(r)   (((r) & BM_LDB_CTRL_DI1_VS_POLARITY) >> BP_LDB_CTRL_DI1_VS_POLARITY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_DI1_VS_POLARITY.
#define BF_LDB_CTRL_DI1_VS_POLARITY(v)   ((((reg32_t) v) << BP_LDB_CTRL_DI1_VS_POLARITY) & BM_LDB_CTRL_DI1_VS_POLARITY)
#else
//! @brief Format value for bitfield LDB_CTRL_DI1_VS_POLARITY.
#define BF_LDB_CTRL_DI1_VS_POLARITY(v)   (((v) << BP_LDB_CTRL_DI1_VS_POLARITY) & BM_LDB_CTRL_DI1_VS_POLARITY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DI1_VS_POLARITY field to a new value.
#define BW_LDB_CTRL_DI1_VS_POLARITY(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_DI1_VS_POLARITY) | BF_LDB_CTRL_DI1_VS_POLARITY(v)))
#endif


/* --- Register HW_LDB_CTRL, field BGREF_RRMODE[15] (RW)
 *
 * Select reference resistor for bandgap
 *
 * Values:
 * 0 - External resistor of 29kOhm is selected
 * 1 - Internal resistor is selected
 */

#define BP_LDB_CTRL_BGREF_RRMODE      (15)      //!< Bit position for LDB_CTRL_BGREF_RRMODE.
#define BM_LDB_CTRL_BGREF_RRMODE      (0x00008000)  //!< Bit mask for LDB_CTRL_BGREF_RRMODE.

//! @brief Get value of LDB_CTRL_BGREF_RRMODE from a register value.
#define BG_LDB_CTRL_BGREF_RRMODE(r)   (((r) & BM_LDB_CTRL_BGREF_RRMODE) >> BP_LDB_CTRL_BGREF_RRMODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_BGREF_RRMODE.
#define BF_LDB_CTRL_BGREF_RRMODE(v)   ((((reg32_t) v) << BP_LDB_CTRL_BGREF_RRMODE) & BM_LDB_CTRL_BGREF_RRMODE)
#else
//! @brief Format value for bitfield LDB_CTRL_BGREF_RRMODE.
#define BF_LDB_CTRL_BGREF_RRMODE(v)   (((v) << BP_LDB_CTRL_BGREF_RRMODE) & BM_LDB_CTRL_BGREF_RRMODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BGREF_RRMODE field to a new value.
#define BW_LDB_CTRL_BGREF_RRMODE(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_BGREF_RRMODE) | BF_LDB_CTRL_BGREF_RRMODE(v)))
#endif


/* --- Register HW_LDB_CTRL, field LVDS_CLK_SHIFT[18:16] (RW)
 *
 * Shifts the LVDS output clock in relation to the data. Used for debug purposes only. In normal
 * functional operation must be '000'
 *
 * Values:
 * 000 - Output clock is '1100011' (normal operation)
 * 001 - Output clock is '1110001'
 * 010 - Output clock is '1111000'
 * 011 - Output clock is '1000111'
 * 100 - Output clock is '0001111'
 * 101 - Output clock is '0011111'
 * 110 - Output clock is '0111100'
 * 111 - Output clock is '1100011'
 */

#define BP_LDB_CTRL_LVDS_CLK_SHIFT      (16)      //!< Bit position for LDB_CTRL_LVDS_CLK_SHIFT.
#define BM_LDB_CTRL_LVDS_CLK_SHIFT      (0x00070000)  //!< Bit mask for LDB_CTRL_LVDS_CLK_SHIFT.

//! @brief Get value of LDB_CTRL_LVDS_CLK_SHIFT from a register value.
#define BG_LDB_CTRL_LVDS_CLK_SHIFT(r)   (((r) & BM_LDB_CTRL_LVDS_CLK_SHIFT) >> BP_LDB_CTRL_LVDS_CLK_SHIFT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_LVDS_CLK_SHIFT.
#define BF_LDB_CTRL_LVDS_CLK_SHIFT(v)   ((((reg32_t) v) << BP_LDB_CTRL_LVDS_CLK_SHIFT) & BM_LDB_CTRL_LVDS_CLK_SHIFT)
#else
//! @brief Format value for bitfield LDB_CTRL_LVDS_CLK_SHIFT.
#define BF_LDB_CTRL_LVDS_CLK_SHIFT(v)   (((v) << BP_LDB_CTRL_LVDS_CLK_SHIFT) & BM_LDB_CTRL_LVDS_CLK_SHIFT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_CLK_SHIFT field to a new value.
#define BW_LDB_CTRL_LVDS_CLK_SHIFT(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_LVDS_CLK_SHIFT) | BF_LDB_CTRL_LVDS_CLK_SHIFT(v)))
#endif


/* --- Register HW_LDB_CTRL, field COUNTER_RESET_VAL[21:20] (RW)
 *
 * Reset value for the LDB counter which determines when the shift registers are loaded with data.
 * Used for debug purposes only. In normal functional operation must be '00'
 *
 * Values:
 * 00 - Reset value is 5
 * 01 - Reset value is 3
 * 10 - Reset value is 4
 * 11 - Reset value is 6
 */

#define BP_LDB_CTRL_COUNTER_RESET_VAL      (20)      //!< Bit position for LDB_CTRL_COUNTER_RESET_VAL.
#define BM_LDB_CTRL_COUNTER_RESET_VAL      (0x00300000)  //!< Bit mask for LDB_CTRL_COUNTER_RESET_VAL.

//! @brief Get value of LDB_CTRL_COUNTER_RESET_VAL from a register value.
#define BG_LDB_CTRL_COUNTER_RESET_VAL(r)   (((r) & BM_LDB_CTRL_COUNTER_RESET_VAL) >> BP_LDB_CTRL_COUNTER_RESET_VAL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield LDB_CTRL_COUNTER_RESET_VAL.
#define BF_LDB_CTRL_COUNTER_RESET_VAL(v)   ((((reg32_t) v) << BP_LDB_CTRL_COUNTER_RESET_VAL) & BM_LDB_CTRL_COUNTER_RESET_VAL)
#else
//! @brief Format value for bitfield LDB_CTRL_COUNTER_RESET_VAL.
#define BF_LDB_CTRL_COUNTER_RESET_VAL(v)   (((v) << BP_LDB_CTRL_COUNTER_RESET_VAL) & BM_LDB_CTRL_COUNTER_RESET_VAL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNTER_RESET_VAL field to a new value.
#define BW_LDB_CTRL_COUNTER_RESET_VAL(v)   (HW_LDB_CTRL_WR((HW_LDB_CTRL_RD() & ~BM_LDB_CTRL_COUNTER_RESET_VAL) | BF_LDB_CTRL_COUNTER_RESET_VAL(v)))
#endif



/*!
 * @brief All LDB module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_ldb
{
    volatile hw_ldb_ctrl_t CTRL; //!< LDB Control Register
} hw_ldb_t;
#pragma pack()

//! @brief Macro to access all LDB registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_LDB(0)</code>.
#define HW_LDB     (*(volatile hw_ldb_t *) REGS_LDB_BASE)

#endif


#endif // __HW_LDB_REGISTERS_H__
