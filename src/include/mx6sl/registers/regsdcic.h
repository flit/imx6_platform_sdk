/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _DCIC_H
#define _DCIC_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_DCIC_DCICC - DCIC Control Register
 * - HW_DCIC_DCICIC - DCIC Interrupt Control Register
 * - HW_DCIC_DCICS - DCIC Status Register
 * - HW_DCIC_DCICRC - DCIC ROI Config Register m
 * - HW_DCIC_DCICRS - DCIC ROI Size Register m
 * - HW_DCIC_DCICRRS - DCIC ROI Reference Signature Register m
 * - HW_DCIC_DCICRCS - DCIC ROI Calculated Signature m
 *
 * hw_dcic_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_DCIC_BASE
#define REGS_DCIC_BASE (0x00000000) //!< Base address for DCIC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICC - DCIC Control Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IC_EN : 1; //!< Integrity Check enable. Main enable switch.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned DE_POL : 1; //!< DATA_EN_IN signal polarity.
        unsigned HSYNC_POL : 1; //!< HSYNC_IN signal polarity.
        unsigned VSYNC_POL : 1; //!< VSYNC_IN signal polarity.
        unsigned CLK_POL : 1; //!< DISP_CLK signal polarity.
        unsigned RESERVED1 : 24; //!< Reserved
    } B;
} hw_dcic_dcicc_t;
#endif

/*
 * constants & macros for entire DCIC_DCICC register
 */
#define HW_DCIC_DCICC_ADDR      (REGS_DCIC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICC           (*(volatile hw_dcic_dcicc_t *) HW_DCIC_DCICC_ADDR)
#define HW_DCIC_DCICC_RD()      (HW_DCIC_DCICC.U)
#define HW_DCIC_DCICC_WR(v)     (HW_DCIC_DCICC.U = (v))
#define HW_DCIC_DCICC_SET(v)    (HW_DCIC_DCICC_WR(HW_DCIC_DCICC_RD() |  (v)))
#define HW_DCIC_DCICC_CLR(v)    (HW_DCIC_DCICC_WR(HW_DCIC_DCICC_RD() & ~(v)))
#define HW_DCIC_DCICC_TOG(v)    (HW_DCIC_DCICC_WR(HW_DCIC_DCICC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICC bitfields
 */

/* --- Register HW_DCIC_DCICC, field IC_EN[0:0] (RW)
 *
 * Integrity Check enable. Main enable switch.
 *
 * Values:
 * 0 - Disabled
 * 1 - Enabled
 */

#define BP_DCIC_DCICC_IC_EN      (0)
#define BM_DCIC_DCICC_IC_EN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_IC_EN(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICC_IC_EN)
#else
#define BF_DCIC_DCICC_IC_EN(v)   (((v) << 0) & BM_DCIC_DCICC_IC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC_EN field to a new value.
#define BW_DCIC_DCICC_IC_EN(v)   BF_CS1(DCIC_DCICC, IC_EN, v)
#endif


/* --- Register HW_DCIC_DCICC, field DE_POL[4:4] (RW)
 *
 * DATA_EN_IN signal polarity.
 *
 * Values:
 * 0 - Active High.
 * 1 - Active Low (default).
 */

#define BP_DCIC_DCICC_DE_POL      (4)
#define BM_DCIC_DCICC_DE_POL      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_DE_POL(v)   ((((reg32_t) v) << 4) & BM_DCIC_DCICC_DE_POL)
#else
#define BF_DCIC_DCICC_DE_POL(v)   (((v) << 4) & BM_DCIC_DCICC_DE_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DE_POL field to a new value.
#define BW_DCIC_DCICC_DE_POL(v)   BF_CS1(DCIC_DCICC, DE_POL, v)
#endif


/* --- Register HW_DCIC_DCICC, field HSYNC_POL[5:5] (RW)
 *
 * HSYNC_IN signal polarity.
 *
 * Values:
 * 0 - Active High.
 * 1 - Active Low (default).
 */

#define BP_DCIC_DCICC_HSYNC_POL      (5)
#define BM_DCIC_DCICC_HSYNC_POL      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_HSYNC_POL(v)   ((((reg32_t) v) << 5) & BM_DCIC_DCICC_HSYNC_POL)
#else
#define BF_DCIC_DCICC_HSYNC_POL(v)   (((v) << 5) & BM_DCIC_DCICC_HSYNC_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNC_POL field to a new value.
#define BW_DCIC_DCICC_HSYNC_POL(v)   BF_CS1(DCIC_DCICC, HSYNC_POL, v)
#endif


/* --- Register HW_DCIC_DCICC, field VSYNC_POL[6:6] (RW)
 *
 * VSYNC_IN signal polarity.
 *
 * Values:
 * 0 - Active High.
 * 1 - Active Low (default).
 */

#define BP_DCIC_DCICC_VSYNC_POL      (6)
#define BM_DCIC_DCICC_VSYNC_POL      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_VSYNC_POL(v)   ((((reg32_t) v) << 6) & BM_DCIC_DCICC_VSYNC_POL)
#else
#define BF_DCIC_DCICC_VSYNC_POL(v)   (((v) << 6) & BM_DCIC_DCICC_VSYNC_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_POL field to a new value.
#define BW_DCIC_DCICC_VSYNC_POL(v)   BF_CS1(DCIC_DCICC, VSYNC_POL, v)
#endif


/* --- Register HW_DCIC_DCICC, field CLK_POL[7:7] (RW)
 *
 * DISP_CLK signal polarity.
 *
 * Values:
 * 0 - Not inverted (default).
 * 1 - Inverted.
 */

#define BP_DCIC_DCICC_CLK_POL      (7)
#define BM_DCIC_DCICC_CLK_POL      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICC_CLK_POL(v)   ((((reg32_t) v) << 7) & BM_DCIC_DCICC_CLK_POL)
#else
#define BF_DCIC_DCICC_CLK_POL(v)   (((v) << 7) & BM_DCIC_DCICC_CLK_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK_POL field to a new value.
#define BW_DCIC_DCICC_CLK_POL(v)   BF_CS1(DCIC_DCICC, CLK_POL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICIC - DCIC Interrupt Control Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EI_MASK : 1; //!< Error Interrupt mask. Can be changed only while FREEZE_MASK = 0.
        unsigned FI_MASK : 1; //!< Functional Interrupt mask. Can be changed only while FREEZE_MASK = 0.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned FREEZE_MASK : 1; //!< Disable change of interrupt masks. "Sticky" bit which can be set once and cleared by reset only.
        unsigned RESERVED1 : 12; //!< Reserved
        unsigned EXT_SIG_EN : 1; //!< External controller mismatch indication signal.
        unsigned RESERVED2 : 15; //!< Reserved
    } B;
} hw_dcic_dcicic_t;
#endif

/*
 * constants & macros for entire DCIC_DCICIC register
 */
#define HW_DCIC_DCICIC_ADDR      (REGS_DCIC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICIC           (*(volatile hw_dcic_dcicic_t *) HW_DCIC_DCICIC_ADDR)
#define HW_DCIC_DCICIC_RD()      (HW_DCIC_DCICIC.U)
#define HW_DCIC_DCICIC_WR(v)     (HW_DCIC_DCICIC.U = (v))
#define HW_DCIC_DCICIC_SET(v)    (HW_DCIC_DCICIC_WR(HW_DCIC_DCICIC_RD() |  (v)))
#define HW_DCIC_DCICIC_CLR(v)    (HW_DCIC_DCICIC_WR(HW_DCIC_DCICIC_RD() & ~(v)))
#define HW_DCIC_DCICIC_TOG(v)    (HW_DCIC_DCICIC_WR(HW_DCIC_DCICIC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICIC bitfields
 */

/* --- Register HW_DCIC_DCICIC, field EI_MASK[0:0] (RW)
 *
 * Error Interrupt mask. Can be changed only while FREEZE_MASK = 0.
 *
 * Values:
 * 0 - Mask disabled - Interrupt assertion enabled
 * 1 - Mask enabled - Interrupt assertion disabled (default)
 */

#define BP_DCIC_DCICIC_EI_MASK      (0)
#define BM_DCIC_DCICIC_EI_MASK      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICIC_EI_MASK(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICIC_EI_MASK)
#else
#define BF_DCIC_DCICIC_EI_MASK(v)   (((v) << 0) & BM_DCIC_DCICIC_EI_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EI_MASK field to a new value.
#define BW_DCIC_DCICIC_EI_MASK(v)   BF_CS1(DCIC_DCICIC, EI_MASK, v)
#endif


/* --- Register HW_DCIC_DCICIC, field FI_MASK[1:1] (RW)
 *
 * Functional Interrupt mask. Can be changed only while FREEZE_MASK = 0.
 *
 * Values:
 * 0 - Mask disabled - Interrupt assertion enabled
 * 1 - Mask enabled - Interrupt assertion disabled (default)
 */

#define BP_DCIC_DCICIC_FI_MASK      (1)
#define BM_DCIC_DCICIC_FI_MASK      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICIC_FI_MASK(v)   ((((reg32_t) v) << 1) & BM_DCIC_DCICIC_FI_MASK)
#else
#define BF_DCIC_DCICIC_FI_MASK(v)   (((v) << 1) & BM_DCIC_DCICIC_FI_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FI_MASK field to a new value.
#define BW_DCIC_DCICIC_FI_MASK(v)   BF_CS1(DCIC_DCICIC, FI_MASK, v)
#endif


/* --- Register HW_DCIC_DCICIC, field FREEZE_MASK[3:3] (RW)
 *
 * Disable change of interrupt masks. "Sticky" bit which can be set once and cleared by reset only.
 *
 * Values:
 * 0 - Masks change allowed (default)
 * 1 - Masks are frozen
 */

#define BP_DCIC_DCICIC_FREEZE_MASK      (3)
#define BM_DCIC_DCICIC_FREEZE_MASK      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICIC_FREEZE_MASK(v)   ((((reg32_t) v) << 3) & BM_DCIC_DCICIC_FREEZE_MASK)
#else
#define BF_DCIC_DCICIC_FREEZE_MASK(v)   (((v) << 3) & BM_DCIC_DCICIC_FREEZE_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FREEZE_MASK field to a new value.
#define BW_DCIC_DCICIC_FREEZE_MASK(v)   BF_CS1(DCIC_DCICIC, FREEZE_MASK, v)
#endif


/* --- Register HW_DCIC_DCICIC, field EXT_SIG_EN[16:16] (RW)
 *
 * External controller mismatch indication signal.
 *
 * Values:
 * 0 - Disabled (default)
 * 1 - Enabled
 */

#define BP_DCIC_DCICIC_EXT_SIG_EN      (16)
#define BM_DCIC_DCICIC_EXT_SIG_EN      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICIC_EXT_SIG_EN(v)   ((((reg32_t) v) << 16) & BM_DCIC_DCICIC_EXT_SIG_EN)
#else
#define BF_DCIC_DCICIC_EXT_SIG_EN(v)   (((v) << 16) & BM_DCIC_DCICIC_EXT_SIG_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EXT_SIG_EN field to a new value.
#define BW_DCIC_DCICIC_EXT_SIG_EN(v)   BF_CS1(DCIC_DCICIC, EXT_SIG_EN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICS - DCIC Status Register (W1C)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ROI_MATCH_STAT : 16; //!< Each set bit of this field indicates there was a mismatch at appropriate ROIs signature during the last frame. Valid only for active ROIs. Write "1" to clear.
        unsigned EI_STAT : 1; //!< Error Interrupt status. Result of "OR" operation on ROI_MATCH_STAT[15:0] bits. Cleared when these bits are clear.
        unsigned FI_STAT : 1; //!< Functional Interrupt status. Write "1" to clear.
        unsigned RESERVED0 : 14; //!< Reserved
    } B;
} hw_dcic_dcics_t;
#endif

/*
 * constants & macros for entire DCIC_DCICS register
 */
#define HW_DCIC_DCICS_ADDR      (REGS_DCIC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICS           (*(volatile hw_dcic_dcics_t *) HW_DCIC_DCICS_ADDR)
#define HW_DCIC_DCICS_RD()      (HW_DCIC_DCICS.U)
#define HW_DCIC_DCICS_WR(v)     (HW_DCIC_DCICS.U = (v))
#define HW_DCIC_DCICS_SET(v)    (HW_DCIC_DCICS_WR(HW_DCIC_DCICS_RD() |  (v)))
#define HW_DCIC_DCICS_CLR(v)    (HW_DCIC_DCICS_WR(HW_DCIC_DCICS_RD() & ~(v)))
#define HW_DCIC_DCICS_TOG(v)    (HW_DCIC_DCICS_WR(HW_DCIC_DCICS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICS bitfields
 */

/* --- Register HW_DCIC_DCICS, field ROI_MATCH_STAT[15:0] (W1C)
 *
 * Each set bit of this field indicates there was a mismatch at appropriate ROIs signature during
 * the last frame. Valid only for active ROIs. Write "1" to clear.
 *
 * Values:
 * 0 - ROI calculated CRC matches expected signature
 * 1 - Mismatch at ROI calculated CRC
 */

#define BP_DCIC_DCICS_ROI_MATCH_STAT      (0)
#define BM_DCIC_DCICS_ROI_MATCH_STAT      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICS_ROI_MATCH_STAT(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICS_ROI_MATCH_STAT)
#else
#define BF_DCIC_DCICS_ROI_MATCH_STAT(v)   (((v) << 0) & BM_DCIC_DCICS_ROI_MATCH_STAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROI_MATCH_STAT field to a new value.
#define BW_DCIC_DCICS_ROI_MATCH_STAT(v)   BF_CS1(DCIC_DCICS, ROI_MATCH_STAT, v)
#endif


/* --- Register HW_DCIC_DCICS, field EI_STAT[16:16] (RO)
 *
 * Error Interrupt status. Result of "OR" operation on ROI_MATCH_STAT[15:0] bits. Cleared when these
 * bits are clear.
 *
 * Values:
 * 0 - No pending Interrupt
 * 1 - Pending Interrupt
 */

#define BP_DCIC_DCICS_EI_STAT      (16)
#define BM_DCIC_DCICS_EI_STAT      (0x00010000)


/* --- Register HW_DCIC_DCICS, field FI_STAT[17:17] (W1C)
 *
 * Functional Interrupt status. Write "1" to clear.
 *
 * Values:
 * 0 - No pending Interrupt
 * 1 - Pending Interrupt
 */

#define BP_DCIC_DCICS_FI_STAT      (17)
#define BM_DCIC_DCICS_FI_STAT      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICS_FI_STAT(v)   ((((reg32_t) v) << 17) & BM_DCIC_DCICS_FI_STAT)
#else
#define BF_DCIC_DCICS_FI_STAT(v)   (((v) << 17) & BM_DCIC_DCICS_FI_STAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FI_STAT field to a new value.
#define BW_DCIC_DCICS_FI_STAT(v)   BF_CS1(DCIC_DCICS, FI_STAT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICRC - DCIC ROI Config Register m (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned START_OFFSET_X : 13; //!< Column number of ROIs upper-left corner (X coordinate) Range: 0 to 2^ 13 -1
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned START_OFFSET_Y : 12; //!< Row number of ROIs upper-left corner (Y coordinate) Range: 0 to 2^ 12 -1
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned ROI_FREEZE : 1; //!< When set, the only parameter of ROI #m that can be changed is reference signature. "Sticky" bit - can be set once and cleared by reset only.
        unsigned ROI_EN : 1; //!< ROI #m tracking enable
    } B;
} hw_dcic_dcicrc_t;
#endif

/*
 * constants & macros for entire DCIC_DCICRC register
 */
#define HW_DCIC_DCICRC_ADDR      (REGS_DCIC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRC           (*(volatile hw_dcic_dcicrc_t *) HW_DCIC_DCICRC_ADDR)
#define HW_DCIC_DCICRC_RD()      (HW_DCIC_DCICRC.U)
#define HW_DCIC_DCICRC_WR(v)     (HW_DCIC_DCICRC.U = (v))
#define HW_DCIC_DCICRC_SET(v)    (HW_DCIC_DCICRC_WR(HW_DCIC_DCICRC_RD() |  (v)))
#define HW_DCIC_DCICRC_CLR(v)    (HW_DCIC_DCICRC_WR(HW_DCIC_DCICRC_RD() & ~(v)))
#define HW_DCIC_DCICRC_TOG(v)    (HW_DCIC_DCICRC_WR(HW_DCIC_DCICRC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICRC bitfields
 */

/* --- Register HW_DCIC_DCICRC, field START_OFFSET_X[12:0] (RW)
 *
 * Column number of ROIs upper-left corner (X coordinate) Range: 0 to 2^ 13 -1
 */

#define BP_DCIC_DCICRC_START_OFFSET_X      (0)
#define BM_DCIC_DCICRC_START_OFFSET_X      (0x00001fff)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRC_START_OFFSET_X(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICRC_START_OFFSET_X)
#else
#define BF_DCIC_DCICRC_START_OFFSET_X(v)   (((v) << 0) & BM_DCIC_DCICRC_START_OFFSET_X)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the START_OFFSET_X field to a new value.
#define BW_DCIC_DCICRC_START_OFFSET_X(v)   BF_CS1(DCIC_DCICRC, START_OFFSET_X, v)
#endif

/* --- Register HW_DCIC_DCICRC, field START_OFFSET_Y[27:16] (RW)
 *
 * Row number of ROIs upper-left corner (Y coordinate) Range: 0 to 2^ 12 -1
 */

#define BP_DCIC_DCICRC_START_OFFSET_Y      (16)
#define BM_DCIC_DCICRC_START_OFFSET_Y      (0x0fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRC_START_OFFSET_Y(v)   ((((reg32_t) v) << 16) & BM_DCIC_DCICRC_START_OFFSET_Y)
#else
#define BF_DCIC_DCICRC_START_OFFSET_Y(v)   (((v) << 16) & BM_DCIC_DCICRC_START_OFFSET_Y)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the START_OFFSET_Y field to a new value.
#define BW_DCIC_DCICRC_START_OFFSET_Y(v)   BF_CS1(DCIC_DCICRC, START_OFFSET_Y, v)
#endif

/* --- Register HW_DCIC_DCICRC, field ROI_FREEZE[30:30] (RW)
 *
 * When set, the only parameter of ROI #m that can be changed is reference signature. "Sticky" bit -
 * can be set once and cleared by reset only.
 *
 * Values:
 * 0 - ROI configuration can be changed
 * 1 - ROI configuration is frozen
 */

#define BP_DCIC_DCICRC_ROI_FREEZE      (30)
#define BM_DCIC_DCICRC_ROI_FREEZE      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRC_ROI_FREEZE(v)   ((((reg32_t) v) << 30) & BM_DCIC_DCICRC_ROI_FREEZE)
#else
#define BF_DCIC_DCICRC_ROI_FREEZE(v)   (((v) << 30) & BM_DCIC_DCICRC_ROI_FREEZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROI_FREEZE field to a new value.
#define BW_DCIC_DCICRC_ROI_FREEZE(v)   BF_CS1(DCIC_DCICRC, ROI_FREEZE, v)
#endif


/* --- Register HW_DCIC_DCICRC, field ROI_EN[31:31] (RW)
 *
 * ROI #m tracking enable
 *
 * Values:
 * 0 - Disabled
 * 1 - Enabled
 */

#define BP_DCIC_DCICRC_ROI_EN      (31)
#define BM_DCIC_DCICRC_ROI_EN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRC_ROI_EN(v)   ((((reg32_t) v) << 31) & BM_DCIC_DCICRC_ROI_EN)
#else
#define BF_DCIC_DCICRC_ROI_EN(v)   (((v) << 31) & BM_DCIC_DCICRC_ROI_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROI_EN field to a new value.
#define BW_DCIC_DCICRC_ROI_EN(v)   BF_CS1(DCIC_DCICRC, ROI_EN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICRS - DCIC ROI Size Register m (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned END_OFFSET_X : 13; //!< Column number of ROIs lower-right corner (X coordinate) Range: 1 to 2^ 13 -1
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned END_OFFSET_Y : 12; //!< Row number of ROIs lower-right corner (Y coordinate) Range: 1 to 2^ 12 -1
        unsigned RESERVED1 : 4; //!< Reserved
    } B;
} hw_dcic_dcicrs_t;
#endif

/*
 * constants & macros for entire DCIC_DCICRS register
 */
#define HW_DCIC_DCICRS_ADDR      (REGS_DCIC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRS           (*(volatile hw_dcic_dcicrs_t *) HW_DCIC_DCICRS_ADDR)
#define HW_DCIC_DCICRS_RD()      (HW_DCIC_DCICRS.U)
#define HW_DCIC_DCICRS_WR(v)     (HW_DCIC_DCICRS.U = (v))
#define HW_DCIC_DCICRS_SET(v)    (HW_DCIC_DCICRS_WR(HW_DCIC_DCICRS_RD() |  (v)))
#define HW_DCIC_DCICRS_CLR(v)    (HW_DCIC_DCICRS_WR(HW_DCIC_DCICRS_RD() & ~(v)))
#define HW_DCIC_DCICRS_TOG(v)    (HW_DCIC_DCICRS_WR(HW_DCIC_DCICRS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICRS bitfields
 */

/* --- Register HW_DCIC_DCICRS, field END_OFFSET_X[12:0] (RW)
 *
 * Column number of ROIs lower-right corner (X coordinate) Range: 1 to 2^ 13 -1
 */

#define BP_DCIC_DCICRS_END_OFFSET_X      (0)
#define BM_DCIC_DCICRS_END_OFFSET_X      (0x00001fff)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRS_END_OFFSET_X(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICRS_END_OFFSET_X)
#else
#define BF_DCIC_DCICRS_END_OFFSET_X(v)   (((v) << 0) & BM_DCIC_DCICRS_END_OFFSET_X)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the END_OFFSET_X field to a new value.
#define BW_DCIC_DCICRS_END_OFFSET_X(v)   BF_CS1(DCIC_DCICRS, END_OFFSET_X, v)
#endif

/* --- Register HW_DCIC_DCICRS, field END_OFFSET_Y[27:16] (RW)
 *
 * Row number of ROIs lower-right corner (Y coordinate) Range: 1 to 2^ 12 -1
 */

#define BP_DCIC_DCICRS_END_OFFSET_Y      (16)
#define BM_DCIC_DCICRS_END_OFFSET_Y      (0x0fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRS_END_OFFSET_Y(v)   ((((reg32_t) v) << 16) & BM_DCIC_DCICRS_END_OFFSET_Y)
#else
#define BF_DCIC_DCICRS_END_OFFSET_Y(v)   (((v) << 16) & BM_DCIC_DCICRS_END_OFFSET_Y)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the END_OFFSET_Y field to a new value.
#define BW_DCIC_DCICRS_END_OFFSET_Y(v)   BF_CS1(DCIC_DCICRS, END_OFFSET_Y, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICRRS - DCIC ROI Reference Signature Register m (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned REFERENCE_SIGNATURE : 32; //!< 32-bit expected signature (CRC calculation result) for ROI #m
    } B;
} hw_dcic_dcicrrs_t;
#endif

/*
 * constants & macros for entire DCIC_DCICRRS register
 */
#define HW_DCIC_DCICRRS_ADDR      (REGS_DCIC_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRRS           (*(volatile hw_dcic_dcicrrs_t *) HW_DCIC_DCICRRS_ADDR)
#define HW_DCIC_DCICRRS_RD()      (HW_DCIC_DCICRRS.U)
#define HW_DCIC_DCICRRS_WR(v)     (HW_DCIC_DCICRRS.U = (v))
#define HW_DCIC_DCICRRS_SET(v)    (HW_DCIC_DCICRRS_WR(HW_DCIC_DCICRRS_RD() |  (v)))
#define HW_DCIC_DCICRRS_CLR(v)    (HW_DCIC_DCICRRS_WR(HW_DCIC_DCICRRS_RD() & ~(v)))
#define HW_DCIC_DCICRRS_TOG(v)    (HW_DCIC_DCICRRS_WR(HW_DCIC_DCICRRS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICRRS bitfields
 */

/* --- Register HW_DCIC_DCICRRS, field REFERENCE_SIGNATURE[31:0] (RW)
 *
 * 32-bit expected signature (CRC calculation result) for ROI #m
 */

#define BP_DCIC_DCICRRS_REFERENCE_SIGNATURE      (0)
#define BM_DCIC_DCICRRS_REFERENCE_SIGNATURE      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)   ((((reg32_t) v) << 0) & BM_DCIC_DCICRRS_REFERENCE_SIGNATURE)
#else
#define BF_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)   (((v) << 0) & BM_DCIC_DCICRRS_REFERENCE_SIGNATURE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REFERENCE_SIGNATURE field to a new value.
#define BW_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)   BF_CS1(DCIC_DCICRRS, REFERENCE_SIGNATURE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICRCS - DCIC ROI Calculated Signature m (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CALCULATED_SIGNATURE : 32; //!< 32-bit actual signature (CRC calculation result) for ROI #m during the last frame. Updated automatically at the beginning of a next frame.
    } B;
} hw_dcic_dcicrcs_t;
#endif

/*
 * constants & macros for entire DCIC_DCICRCS register
 */
#define HW_DCIC_DCICRCS_ADDR      (REGS_DCIC_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRCS           (*(volatile hw_dcic_dcicrcs_t *) HW_DCIC_DCICRCS_ADDR)
#define HW_DCIC_DCICRCS_RD()      (HW_DCIC_DCICRCS.U)
#endif

/*
 * constants & macros for individual DCIC_DCICRCS bitfields
 */

/* --- Register HW_DCIC_DCICRCS, field CALCULATED_SIGNATURE[31:0] (RO)
 *
 * 32-bit actual signature (CRC calculation result) for ROI #m during the last frame. Updated
 * automatically at the beginning of a next frame.
 */

#define BP_DCIC_DCICRCS_CALCULATED_SIGNATURE      (0)
#define BM_DCIC_DCICRCS_CALCULATED_SIGNATURE      (0xffffffff)


/*!
 * @brief All DCIC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_dcic_dcicc_t DCICC; //!< DCIC Control Register
    volatile hw_dcic_dcicic_t DCICIC; //!< DCIC Interrupt Control Register
    volatile hw_dcic_dcics_t DCICS; //!< DCIC Status Register
    reg32_t _reserved0;
    volatile hw_dcic_dcicrc_t DCICRC; //!< DCIC ROI Config Register m
    volatile hw_dcic_dcicrs_t DCICRS; //!< DCIC ROI Size Register m
    volatile hw_dcic_dcicrrs_t DCICRRS; //!< DCIC ROI Reference Signature Register m
    volatile hw_dcic_dcicrcs_t DCICRCS; //!< DCIC ROI Calculated Signature m
} hw_dcic_t;
#endif

//! @brief Macro to access all DCIC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_DCIC(0)</code>.
#define HW_DCIC     (*(volatile hw_dcic_t *) REGS_DCIC_BASE)


#endif // _DCIC_H
