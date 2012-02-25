/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _EPXP_H
#define _EPXP_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_EPXP_CTRL - Control Register 0
 * - HW_EPXP_STAT - Status Register
 * - HW_EPXP_OUT_CTRL - Output Buffer Control Register
 * - HW_EPXP_OUT_BUF - Output Frame Buffer Pointer
 * - HW_EPXP_OUT_BUF2 - Output Frame Buffer Pointer #2
 * - HW_EPXP_OUT_PITCH - Output Buffer Pitch
 * - HW_EPXP_OUT_LRC - Output Surface Lower Right Coordinate
 * - HW_EPXP_OUT_PS_ULC - Processed Surface Upper Left Coordinate
 * - HW_EPXP_OUT_PS_LRC - Processed Surface Lower Right Coordinate
 * - HW_EPXP_OUT_AS_ULC - Alpha Surface Upper Left Coordinate
 * - HW_EPXP_OUT_AS_LRC - Alpha Surface Lower Right Coordinate
 * - HW_EPXP_PS_CTRL - Processed Surface (PS) Control Register
 * - HW_EPXP_PS_BUF - PS Input Buffer Address
 * - HW_EPXP_PS_UBUF - PS U/Cb or 2 Plane UV Input Buffer Address
 * - HW_EPXP_PS_VBUF - PS V/Cr Input Buffer Address
 * - HW_EPXP_PS_PITCH - Processed Surface Pitch
 * - HW_EPXP_PS_BACKGROUND - PS Background Color
 * - HW_EPXP_PS_SCALE - PS Scale Factor Register
 * - HW_EPXP_PS_OFFSET - PS Scale Offset Register
 * - HW_EPXP_PS_CLRKEYLOW - PS Color Key Low
 * - HW_EPXP_PS_CLRKEYHIGH - PS Color Key High
 * - HW_EPXP_AS_CTRL - Alpha Surface Control
 * - HW_EPXP_AS_BUF - Alpha Surface Buffer Pointer
 * - HW_EPXP_AS_PITCH - Alpha Surface Pitch
 * - HW_EPXP_AS_CLRKEYLOW - Overlay Color Key Low
 * - HW_EPXP_AS_CLRKEYHIGH - Overlay Color Key High
 * - HW_EPXP_CSC1_COEF0 - Color Space Conversion Coefficient Register 0
 * - HW_EPXP_CSC1_COEF1 - Color Space Conversion Coefficient Register 1
 * - HW_EPXP_CSC1_COEF2 - Color Space Conversion Coefficient Register 2
 * - HW_EPXP_CSC2_CTRL - Color Space Conversion Control Register.
 * - HW_EPXP_CSC2_COEF0 - Color Space Conversion Coefficient Register 0
 * - HW_EPXP_CSC2_COEF1 - Color Space Conversion Coefficient Register 1
 * - HW_EPXP_CSC2_COEF2 - Color Space Conversion Coefficient Register 2
 * - HW_EPXP_CSC2_COEF3 - Color Space Conversion Coefficient Register 3
 * - HW_EPXP_CSC2_COEF4 - Color Space Conversion Coefficient Register 4
 * - HW_EPXP_CSC2_COEF5 - Color Space Conversion Coefficient Register 5
 * - HW_EPXP_LUT_CTRL - Lookup Table Control Register.
 * - HW_EPXP_LUT_ADDR - Lookup Table Control Register.
 * - HW_EPXP_LUT_DATA - Lookup Table Data Register.
 * - HW_EPXP_LUT_EXTMEM - Lookup Table External Memory Address Register.
 * - HW_EPXP_CFA - Color Filter Array Register.
 * - HW_EPXP_HIST_CTRL - Histogram Control Register.
 * - HW_EPXP_HIST2_PARAM - 2-level Histogram Parameter Register.
 * - HW_EPXP_HIST4_PARAM - 4-level Histogram Parameter Register.
 * - HW_EPXP_HIST8_PARAM0 - 8-level Histogram Parameter 0 Register.
 * - HW_EPXP_HIST8_PARAM1 - 8-level Histogram Parameter 1 Register.
 * - HW_EPXP_HIST16_PARAM0 - 16-level Histogram Parameter 0 Register.
 * - HW_EPXP_HIST16_PARAM1 - 16-level Histogram Parameter 1 Register.
 * - HW_EPXP_HIST16_PARAM2 - 16-level Histogram Parameter 2 Register.
 * - HW_EPXP_HIST16_PARAM3 - 16-level Histogram Parameter 3 Register.
 * - HW_EPXP_POWER - PXP Power Control Register.
 * - HW_EPXP_NEXT - Next Frame Pointer
 *
 * hw_epxp_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_EPXP_BASE
#define REGS_EPXP_BASE (0x020f4000) //!< Base address for EPXP.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CTRL - Control Register 0 (RW)
 *
 * The CTRL register contains controls for the PXP module.  PXP_CTRL: 0x000  PXP_CTRL_SET: 0x004
 * PXP_CTRL_CLR: 0x008  PXP_CTRL_TOG: 0x00C  The Control register contains the primary controls for
 * the PXP block. The present bits indicate which of the sub-features of the block are present in
 * the hardware.   EXAMPLE   PXP_CTRL_SET(BM_PXP_CTRL_SFTRST); PXP_CTRL_CLR(BM_PXP_CTRL_SFTRST |
 * BM_PXP_CTRL_CLKGATE);
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENABLE : 1; //!< Enables PXP operation with specified parameters. The ENABLE bit will remain set while the PXP is active and will be cleared once the current operation completes. Software should use the IRQ bit in the PXP_STAT when polling for PXP completion.
        unsigned IRQ_ENABLE : 1; //!< Interrupt enable. NOTE: When using the PXP_NEXT functionality to reprogram the PXP, the new value of this bit will be used and may therefore enable or disable an interrupt unintentionally.
        unsigned NEXT_IRQ_ENABLE : 1; //!< Next command interrupt enable. When set, the PXP will issue an interrupt when a queued command initiated by a write to the PXP_NEXT register has been loaded into the PXP's registers. This interrupt also indicates that a new command may now be queued.
        unsigned LUT_DMA_IRQ_ENABLE : 1; //!< LUT DMA interrupt enable. When set, the PXP will issue an interrupt when the LUT DMA has finished transferring data.
        unsigned ENABLE_LCD_HANDSHAKE : 1; //!< Enable handshake with LCD controller. When this is set, the PXP will not process an entire framebuffer, but will instead process rows of NxN blocks in a double-buffer handshake with the LCDIF. This enables the use of the onboard SRAM for a partial frame buffer.
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned ROTATE : 2; //!< Indicates the clockwise rotation to be applied at the output buffer. The rotation effect is defined as occurring after the FLIP_X and FLIP_Y permutation.
        unsigned HFLIP : 1; //!< Indicates that the output buffer should be flipped horizontally (effect applied before rotation).
        unsigned VFLIP : 1; //!< Indicates that the output buffer should be flipped vertically (effect applied before rotation).
        unsigned RESERVED1 : 10; //!< Reserved, always set to zero.
        unsigned ROT_POS : 1; //!< This bit controls where rotation will occur in the PXP datapath. Setting this bit to 1'b0 will place the rotation resources at the output stage of the PXP data path. Image compositing will occur before pixels are processed for rotation. Setting this bit to a 1'b1 will place the rotation resources before image composition. Only the PS can be rotated in this configuration and AS will not be rotated.
        unsigned BLOCK_SIZE : 1; //!< Select the block size to process.
        unsigned RESERVED2 : 4; //!< Reserved, always set to zero.
        unsigned EN_REPEAT : 1; //!< Enable the PXP to run continuously. When this bit is set, the PXP will repeat based on the current configuration register settings. If this bit is not set, the PXP will complete the process and enter the idle state ready to accept the next frame to be processed. This bit should be set when the LCDIF handshake mode is enabled so that the next frame is automatically generated for the next screen refresh cycle. If it not set and the handshake mode is enabled, the CPU will have to initiate the PXP for the next refresh cycle. When the PXP NEXT feature is used, it has priority over the REPEAT mode, in that the new register settings are fetched first, and then the next PXP operation will continue.
        unsigned RESERVED3 : 1; //!< Reserved, always set to zero.
        unsigned CLKGATE : 1; //!< This bit must be set to zero for normal operation. When set to one it gates off the clocks to the block.
        unsigned SFTRST : 1; //!< Set this bit to zero to enable normal PXP operation. Set this bit to one (default) to disable clocking with the PXP and hold it in its reset (lowest power) state. This bit can be turned on and then off to reset the PXP block to its default state.
    } B;
} hw_epxp_ctrl_t;
#endif

/*
 * constants & macros for entire EPXP_CTRL register
 */
#define HW_EPXP_CTRL_ADDR      (REGS_EPXP_BASE + 0x0)
#define HW_EPXP_CTRL_SET_ADDR  (HW_EPXP_CTRL_ADDR + 0x4)
#define HW_EPXP_CTRL_CLR_ADDR  (HW_EPXP_CTRL_ADDR + 0x8)
#define HW_EPXP_CTRL_TOG_ADDR  (HW_EPXP_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CTRL           (*(volatile hw_epxp_ctrl_t *) HW_EPXP_CTRL_ADDR)
#define HW_EPXP_CTRL_RD()      (HW_EPXP_CTRL.U)
#define HW_EPXP_CTRL_WR(v)     (HW_EPXP_CTRL.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CTRL_SET_ADDR) = (v))
#define HW_EPXP_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CTRL_CLR_ADDR) = (v))
#define HW_EPXP_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CTRL bitfields
 */

/* --- Register HW_EPXP_CTRL, field ENABLE[0:0] (RW)
 *
 * Enables PXP operation with specified parameters. The ENABLE bit will remain set while the PXP is
 * active and will be cleared once the current operation completes. Software should use the IRQ bit
 * in the PXP_STAT when polling for PXP completion.
 */

#define BP_EPXP_CTRL_ENABLE      (0)
#define BM_EPXP_CTRL_ENABLE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_ENABLE(v)   ((((reg32_t) v) << 0) & BM_EPXP_CTRL_ENABLE)
#else
#define BF_EPXP_CTRL_ENABLE(v)   (((v) << 0) & BM_EPXP_CTRL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_EPXP_CTRL_ENABLE(v)   BF_CS1(EPXP_CTRL, ENABLE, v)
#endif

/* --- Register HW_EPXP_CTRL, field IRQ_ENABLE[1:1] (RW)
 *
 * Interrupt enable. NOTE: When using the PXP_NEXT functionality to reprogram the PXP, the new value
 * of this bit will be used and may therefore enable or disable an interrupt unintentionally.
 */

#define BP_EPXP_CTRL_IRQ_ENABLE      (1)
#define BM_EPXP_CTRL_IRQ_ENABLE      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_IRQ_ENABLE(v)   ((((reg32_t) v) << 1) & BM_EPXP_CTRL_IRQ_ENABLE)
#else
#define BF_EPXP_CTRL_IRQ_ENABLE(v)   (((v) << 1) & BM_EPXP_CTRL_IRQ_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_ENABLE field to a new value.
#define BW_EPXP_CTRL_IRQ_ENABLE(v)   BF_CS1(EPXP_CTRL, IRQ_ENABLE, v)
#endif

/* --- Register HW_EPXP_CTRL, field NEXT_IRQ_ENABLE[2:2] (RW)
 *
 * Next command interrupt enable. When set, the PXP will issue an interrupt when a queued command
 * initiated by a write to the PXP_NEXT register has been loaded into the PXP's registers. This
 * interrupt also indicates that a new command may now be queued.
 */

#define BP_EPXP_CTRL_NEXT_IRQ_ENABLE      (2)
#define BM_EPXP_CTRL_NEXT_IRQ_ENABLE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_NEXT_IRQ_ENABLE(v)   ((((reg32_t) v) << 2) & BM_EPXP_CTRL_NEXT_IRQ_ENABLE)
#else
#define BF_EPXP_CTRL_NEXT_IRQ_ENABLE(v)   (((v) << 2) & BM_EPXP_CTRL_NEXT_IRQ_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NEXT_IRQ_ENABLE field to a new value.
#define BW_EPXP_CTRL_NEXT_IRQ_ENABLE(v)   BF_CS1(EPXP_CTRL, NEXT_IRQ_ENABLE, v)
#endif

/* --- Register HW_EPXP_CTRL, field LUT_DMA_IRQ_ENABLE[3:3] (RW)
 *
 * LUT DMA interrupt enable. When set, the PXP will issue an interrupt when the LUT DMA has finished
 * transferring data.
 */

#define BP_EPXP_CTRL_LUT_DMA_IRQ_ENABLE      (3)
#define BM_EPXP_CTRL_LUT_DMA_IRQ_ENABLE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_LUT_DMA_IRQ_ENABLE(v)   ((((reg32_t) v) << 3) & BM_EPXP_CTRL_LUT_DMA_IRQ_ENABLE)
#else
#define BF_EPXP_CTRL_LUT_DMA_IRQ_ENABLE(v)   (((v) << 3) & BM_EPXP_CTRL_LUT_DMA_IRQ_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_DMA_IRQ_ENABLE field to a new value.
#define BW_EPXP_CTRL_LUT_DMA_IRQ_ENABLE(v)   BF_CS1(EPXP_CTRL, LUT_DMA_IRQ_ENABLE, v)
#endif

/* --- Register HW_EPXP_CTRL, field ENABLE_LCD_HANDSHAKE[4:4] (RW)
 *
 * Enable handshake with LCD controller. When this is set, the PXP will not process an entire
 * framebuffer, but will instead process rows of NxN blocks in a double-buffer handshake with the
 * LCDIF. This enables the use of the onboard SRAM for a partial frame buffer.
 */

#define BP_EPXP_CTRL_ENABLE_LCD_HANDSHAKE      (4)
#define BM_EPXP_CTRL_ENABLE_LCD_HANDSHAKE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_ENABLE_LCD_HANDSHAKE(v)   ((((reg32_t) v) << 4) & BM_EPXP_CTRL_ENABLE_LCD_HANDSHAKE)
#else
#define BF_EPXP_CTRL_ENABLE_LCD_HANDSHAKE(v)   (((v) << 4) & BM_EPXP_CTRL_ENABLE_LCD_HANDSHAKE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_LCD_HANDSHAKE field to a new value.
#define BW_EPXP_CTRL_ENABLE_LCD_HANDSHAKE(v)   BF_CS1(EPXP_CTRL, ENABLE_LCD_HANDSHAKE, v)
#endif

/* --- Register HW_EPXP_CTRL, field ROTATE[9:8] (RW)
 *
 * Indicates the clockwise rotation to be applied at the output buffer. The rotation effect is
 * defined as occurring after the FLIP_X and FLIP_Y permutation.
 *
 * Values:
 * ROT_0 = 0x0 - 
 * ROT_90 = 0x1 - 
 * ROT_180 = 0x2 - 
 * ROT_270 = 0x3 - 
 */

#define BP_EPXP_CTRL_ROTATE      (8)
#define BM_EPXP_CTRL_ROTATE      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_ROTATE(v)   ((((reg32_t) v) << 8) & BM_EPXP_CTRL_ROTATE)
#else
#define BF_EPXP_CTRL_ROTATE(v)   (((v) << 8) & BM_EPXP_CTRL_ROTATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROTATE field to a new value.
#define BW_EPXP_CTRL_ROTATE(v)   BF_CS1(EPXP_CTRL, ROTATE, v)
#endif

#define BV_EPXP_CTRL_ROTATE__ROT_0 (0x0) //!< 
#define BV_EPXP_CTRL_ROTATE__ROT_90 (0x1) //!< 
#define BV_EPXP_CTRL_ROTATE__ROT_180 (0x2) //!< 
#define BV_EPXP_CTRL_ROTATE__ROT_270 (0x3) //!< 

/* --- Register HW_EPXP_CTRL, field HFLIP[10:10] (RW)
 *
 * Indicates that the output buffer should be flipped horizontally (effect applied before rotation).
 */

#define BP_EPXP_CTRL_HFLIP      (10)
#define BM_EPXP_CTRL_HFLIP      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_HFLIP(v)   ((((reg32_t) v) << 10) & BM_EPXP_CTRL_HFLIP)
#else
#define BF_EPXP_CTRL_HFLIP(v)   (((v) << 10) & BM_EPXP_CTRL_HFLIP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HFLIP field to a new value.
#define BW_EPXP_CTRL_HFLIP(v)   BF_CS1(EPXP_CTRL, HFLIP, v)
#endif

/* --- Register HW_EPXP_CTRL, field VFLIP[11:11] (RW)
 *
 * Indicates that the output buffer should be flipped vertically (effect applied before rotation).
 */

#define BP_EPXP_CTRL_VFLIP      (11)
#define BM_EPXP_CTRL_VFLIP      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_VFLIP(v)   ((((reg32_t) v) << 11) & BM_EPXP_CTRL_VFLIP)
#else
#define BF_EPXP_CTRL_VFLIP(v)   (((v) << 11) & BM_EPXP_CTRL_VFLIP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VFLIP field to a new value.
#define BW_EPXP_CTRL_VFLIP(v)   BF_CS1(EPXP_CTRL, VFLIP, v)
#endif

/* --- Register HW_EPXP_CTRL, field ROT_POS[22:22] (RW)
 *
 * This bit controls where rotation will occur in the PXP datapath. Setting this bit to 1'b0 will
 * place the rotation resources at the output stage of the PXP data path. Image compositing will
 * occur before pixels are processed for rotation. Setting this bit to a 1'b1 will place the
 * rotation resources before image composition. Only the PS can be rotated in this configuration and
 * AS will not be rotated.
 */

#define BP_EPXP_CTRL_ROT_POS      (22)
#define BM_EPXP_CTRL_ROT_POS      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_ROT_POS(v)   ((((reg32_t) v) << 22) & BM_EPXP_CTRL_ROT_POS)
#else
#define BF_EPXP_CTRL_ROT_POS(v)   (((v) << 22) & BM_EPXP_CTRL_ROT_POS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROT_POS field to a new value.
#define BW_EPXP_CTRL_ROT_POS(v)   BF_CS1(EPXP_CTRL, ROT_POS, v)
#endif

/* --- Register HW_EPXP_CTRL, field BLOCK_SIZE[23:23] (RW)
 *
 * Select the block size to process.
 *
 * Values:
 * 8X8 = 0x0 - Process 8x8 pixel blocks.
 * 16X16 = 0x1 - Process 16x16 pixel blocks.
 */

#define BP_EPXP_CTRL_BLOCK_SIZE      (23)
#define BM_EPXP_CTRL_BLOCK_SIZE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_BLOCK_SIZE(v)   ((((reg32_t) v) << 23) & BM_EPXP_CTRL_BLOCK_SIZE)
#else
#define BF_EPXP_CTRL_BLOCK_SIZE(v)   (((v) << 23) & BM_EPXP_CTRL_BLOCK_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BLOCK_SIZE field to a new value.
#define BW_EPXP_CTRL_BLOCK_SIZE(v)   BF_CS1(EPXP_CTRL, BLOCK_SIZE, v)
#endif

#define BV_EPXP_CTRL_BLOCK_SIZE__8X8 (0x0) //!< Process 8x8 pixel blocks.
#define BV_EPXP_CTRL_BLOCK_SIZE__16X16 (0x1) //!< Process 16x16 pixel blocks.

/* --- Register HW_EPXP_CTRL, field EN_REPEAT[28:28] (RW)
 *
 * Enable the PXP to run continuously. When this bit is set, the PXP will repeat based on the
 * current configuration register settings. If this bit is not set, the PXP will complete the
 * process and enter the idle state ready to accept the next frame to be processed. This bit should
 * be set when the LCDIF handshake mode is enabled so that the next frame is automatically generated
 * for the next screen refresh cycle. If it not set and the handshake mode is enabled, the CPU will
 * have to initiate the PXP for the next refresh cycle. When the PXP NEXT feature is used, it has
 * priority over the REPEAT mode, in that the new register settings are fetched first, and then the
 * next PXP operation will continue.
 */

#define BP_EPXP_CTRL_EN_REPEAT      (28)
#define BM_EPXP_CTRL_EN_REPEAT      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_EN_REPEAT(v)   ((((reg32_t) v) << 28) & BM_EPXP_CTRL_EN_REPEAT)
#else
#define BF_EPXP_CTRL_EN_REPEAT(v)   (((v) << 28) & BM_EPXP_CTRL_EN_REPEAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_REPEAT field to a new value.
#define BW_EPXP_CTRL_EN_REPEAT(v)   BF_CS1(EPXP_CTRL, EN_REPEAT, v)
#endif

/* --- Register HW_EPXP_CTRL, field CLKGATE[30:30] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one it gates off the clocks to the
 * block.
 */

#define BP_EPXP_CTRL_CLKGATE      (30)
#define BM_EPXP_CTRL_CLKGATE      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_EPXP_CTRL_CLKGATE)
#else
#define BF_EPXP_CTRL_CLKGATE(v)   (((v) << 30) & BM_EPXP_CTRL_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_EPXP_CTRL_CLKGATE(v)   BF_CS1(EPXP_CTRL, CLKGATE, v)
#endif

/* --- Register HW_EPXP_CTRL, field SFTRST[31:31] (RW)
 *
 * Set this bit to zero to enable normal PXP operation. Set this bit to one (default) to disable
 * clocking with the PXP and hold it in its reset (lowest power) state. This bit can be turned on
 * and then off to reset the PXP block to its default state.
 */

#define BP_EPXP_CTRL_SFTRST      (31)
#define BM_EPXP_CTRL_SFTRST      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CTRL_SFTRST(v)   ((((reg32_t) v) << 31) & BM_EPXP_CTRL_SFTRST)
#else
#define BF_EPXP_CTRL_SFTRST(v)   (((v) << 31) & BM_EPXP_CTRL_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_EPXP_CTRL_SFTRST(v)   BF_CS1(EPXP_CTRL, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_STAT - Status Register (RW)
 *
 * The PXP Interrupt Status register provides interrupt status information.  PXP_STAT: 0x010
 * PXP_STAT_SET: 0x014  PXP_STAT_CLR: 0x018  PXP_STAT_TOG: 0x01C  This register provides PXP
 * interrupt status and the current X/Y block coordinate that is being processed.   EXAMPLE
 * PXP_STAT_CLR(BM_PXP_STAT_IRQ); // clear CSC interrupt
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IRQ : 1; //!< Indicates current PXP interrupt status. The IRQ is routed through the pxp_irq when the IRQ_ENABLE bit in the control register is set.
        unsigned AXI_WRITE_ERROR : 1; //!< Indicates PXP encountered an AXI write error and processing has been terminated.
        unsigned AXI_READ_ERROR : 1; //!< Indicates PXP encountered an AXI read error and processing has been terminated.
        unsigned NEXT_IRQ : 1; //!< Indicates that a command issued with the "Next Command" functionality has been issued and that a new command may be initiated with a write to the PXP_NEXT register.
        unsigned AXI_ERROR_ID : 4; //!< Indicates the AXI ID of the failing bus operation.
        unsigned LUT_DMA_LOAD_DONE_IRQ : 1; //!< Indicates that the LUT DMA transfer has completed.
        unsigned RESERVED0 : 7; //!< Reserved, always set to zero.
        unsigned BLOCKY : 8; //!< Indicates the X coordinate of the block currently being rendered.
        unsigned BLOCKX : 8; //!< Indicates the X coordinate of the block currently being rendered.
    } B;
} hw_epxp_stat_t;
#endif

/*
 * constants & macros for entire EPXP_STAT register
 */
#define HW_EPXP_STAT_ADDR      (REGS_EPXP_BASE + 0x10)
#define HW_EPXP_STAT_SET_ADDR  (HW_EPXP_STAT_ADDR + 0x4)
#define HW_EPXP_STAT_CLR_ADDR  (HW_EPXP_STAT_ADDR + 0x8)
#define HW_EPXP_STAT_TOG_ADDR  (HW_EPXP_STAT_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_STAT           (*(volatile hw_epxp_stat_t *) HW_EPXP_STAT_ADDR)
#define HW_EPXP_STAT_RD()      (HW_EPXP_STAT.U)
#define HW_EPXP_STAT_WR(v)     (HW_EPXP_STAT.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_STAT_SET_ADDR) = (v))
#define HW_EPXP_STAT_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_STAT_CLR_ADDR) = (v))
#define HW_EPXP_STAT_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_STAT_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_STAT bitfields
 */

/* --- Register HW_EPXP_STAT, field IRQ[0:0] (RW)
 *
 * Indicates current PXP interrupt status. The IRQ is routed through the pxp_irq when the IRQ_ENABLE
 * bit in the control register is set.
 */

#define BP_EPXP_STAT_IRQ      (0)
#define BM_EPXP_STAT_IRQ      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_STAT_IRQ(v)   ((((reg32_t) v) << 0) & BM_EPXP_STAT_IRQ)
#else
#define BF_EPXP_STAT_IRQ(v)   (((v) << 0) & BM_EPXP_STAT_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ field to a new value.
#define BW_EPXP_STAT_IRQ(v)   BF_CS1(EPXP_STAT, IRQ, v)
#endif

/* --- Register HW_EPXP_STAT, field AXI_WRITE_ERROR[1:1] (RW)
 *
 * Indicates PXP encountered an AXI write error and processing has been terminated.
 */

#define BP_EPXP_STAT_AXI_WRITE_ERROR      (1)
#define BM_EPXP_STAT_AXI_WRITE_ERROR      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_STAT_AXI_WRITE_ERROR(v)   ((((reg32_t) v) << 1) & BM_EPXP_STAT_AXI_WRITE_ERROR)
#else
#define BF_EPXP_STAT_AXI_WRITE_ERROR(v)   (((v) << 1) & BM_EPXP_STAT_AXI_WRITE_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AXI_WRITE_ERROR field to a new value.
#define BW_EPXP_STAT_AXI_WRITE_ERROR(v)   BF_CS1(EPXP_STAT, AXI_WRITE_ERROR, v)
#endif

/* --- Register HW_EPXP_STAT, field AXI_READ_ERROR[2:2] (RW)
 *
 * Indicates PXP encountered an AXI read error and processing has been terminated.
 */

#define BP_EPXP_STAT_AXI_READ_ERROR      (2)
#define BM_EPXP_STAT_AXI_READ_ERROR      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_STAT_AXI_READ_ERROR(v)   ((((reg32_t) v) << 2) & BM_EPXP_STAT_AXI_READ_ERROR)
#else
#define BF_EPXP_STAT_AXI_READ_ERROR(v)   (((v) << 2) & BM_EPXP_STAT_AXI_READ_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AXI_READ_ERROR field to a new value.
#define BW_EPXP_STAT_AXI_READ_ERROR(v)   BF_CS1(EPXP_STAT, AXI_READ_ERROR, v)
#endif

/* --- Register HW_EPXP_STAT, field NEXT_IRQ[3:3] (RW)
 *
 * Indicates that a command issued with the "Next Command" functionality has been issued and that a
 * new command may be initiated with a write to the PXP_NEXT register.
 */

#define BP_EPXP_STAT_NEXT_IRQ      (3)
#define BM_EPXP_STAT_NEXT_IRQ      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_STAT_NEXT_IRQ(v)   ((((reg32_t) v) << 3) & BM_EPXP_STAT_NEXT_IRQ)
#else
#define BF_EPXP_STAT_NEXT_IRQ(v)   (((v) << 3) & BM_EPXP_STAT_NEXT_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NEXT_IRQ field to a new value.
#define BW_EPXP_STAT_NEXT_IRQ(v)   BF_CS1(EPXP_STAT, NEXT_IRQ, v)
#endif

/* --- Register HW_EPXP_STAT, field AXI_ERROR_ID[7:4] (RO)
 *
 * Indicates the AXI ID of the failing bus operation.
 */

#define BP_EPXP_STAT_AXI_ERROR_ID      (4)
#define BM_EPXP_STAT_AXI_ERROR_ID      (0x000000f0)

/* --- Register HW_EPXP_STAT, field LUT_DMA_LOAD_DONE_IRQ[8:8] (RW)
 *
 * Indicates that the LUT DMA transfer has completed.
 */

#define BP_EPXP_STAT_LUT_DMA_LOAD_DONE_IRQ      (8)
#define BM_EPXP_STAT_LUT_DMA_LOAD_DONE_IRQ      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_STAT_LUT_DMA_LOAD_DONE_IRQ(v)   ((((reg32_t) v) << 8) & BM_EPXP_STAT_LUT_DMA_LOAD_DONE_IRQ)
#else
#define BF_EPXP_STAT_LUT_DMA_LOAD_DONE_IRQ(v)   (((v) << 8) & BM_EPXP_STAT_LUT_DMA_LOAD_DONE_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_DMA_LOAD_DONE_IRQ field to a new value.
#define BW_EPXP_STAT_LUT_DMA_LOAD_DONE_IRQ(v)   BF_CS1(EPXP_STAT, LUT_DMA_LOAD_DONE_IRQ, v)
#endif

/* --- Register HW_EPXP_STAT, field BLOCKY[23:16] (RO)
 *
 * Indicates the X coordinate of the block currently being rendered.
 */

#define BP_EPXP_STAT_BLOCKY      (16)
#define BM_EPXP_STAT_BLOCKY      (0x00ff0000)

/* --- Register HW_EPXP_STAT, field BLOCKX[31:24] (RO)
 *
 * Indicates the X coordinate of the block currently being rendered.
 */

#define BP_EPXP_STAT_BLOCKX      (24)
#define BM_EPXP_STAT_BLOCKX      (0xff000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_CTRL - Output Buffer Control Register (RW)
 *
 * The OUT_CTRL register contains controls for the Output Buffer.  PXP_OUT_CTRL: 0x020
 * PXP_OUT_CTRL_SET: 0x024  PXP_OUT_CTRL_CLR: 0x028  PXP_OUT_CTRL_TOG: 0x02C  The Control register
 * contains the primary controls for the PXP block. The present bits indicate which of the sub-
 * features of the block are present in the hardware.   EXAMPLE   PXP_CTRL_SET(BM_PXP_CTRL_SFTRST);
 * PXP_CTRL_CLR(BM_PXP_CTRL_SFTRST | BM_PXP_CTRL_CLKGATE);
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FORMAT : 5; //!< Output framebuffer format. The UV byte lanes are synonymous with CbCr byte lanes for YUV output pixel formats. For example, the YUV2P420 format should be selected when the output is YCbCr 2-plane 420 output format.
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned INTERLACED_OUTPUT : 2; //!< Determines how the PXP writes it's output data. Output interlacing should not be used in conjunction with input interlacing. Splitting frames into fields is most efficient using output interlacing. 2-plane output formats AND interlaced output is NOT supported.
        unsigned RESERVED1 : 13; //!< Reserved, always set to zero.
        unsigned ALPHA_OUTPUT : 1; //!< Indicates that alpha component in output buffer pixels should be overwritten by PXP_OUT_CTRL[ALPHA]. If 0, retain their alpha value from the computed alpha for that pixel.
        unsigned ALPHA : 8; //!< When generating an output buffer with an alpha component, the value in this field will be used when enabled to override the alpha passed through the pixel data pipeline.
    } B;
} hw_epxp_out_ctrl_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_CTRL register
 */
#define HW_EPXP_OUT_CTRL_ADDR      (REGS_EPXP_BASE + 0x20)
#define HW_EPXP_OUT_CTRL_SET_ADDR  (HW_EPXP_OUT_CTRL_ADDR + 0x4)
#define HW_EPXP_OUT_CTRL_CLR_ADDR  (HW_EPXP_OUT_CTRL_ADDR + 0x8)
#define HW_EPXP_OUT_CTRL_TOG_ADDR  (HW_EPXP_OUT_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_CTRL           (*(volatile hw_epxp_out_ctrl_t *) HW_EPXP_OUT_CTRL_ADDR)
#define HW_EPXP_OUT_CTRL_RD()      (HW_EPXP_OUT_CTRL.U)
#define HW_EPXP_OUT_CTRL_WR(v)     (HW_EPXP_OUT_CTRL.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_CTRL_SET_ADDR) = (v))
#define HW_EPXP_OUT_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_CTRL_CLR_ADDR) = (v))
#define HW_EPXP_OUT_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_CTRL bitfields
 */

/* --- Register HW_EPXP_OUT_CTRL, field FORMAT[4:0] (RW)
 *
 * Output framebuffer format. The UV byte lanes are synonymous with CbCr byte lanes for YUV output
 * pixel formats. For example, the YUV2P420 format should be selected when the output is YCbCr
 * 2-plane 420 output format.
 *
 * Values:
 * ARGB8888 = 0x0 - 32-bit pixels
 * RGB888 = 0x4 - 32-bit pixels (unpacked 24-bit pixel in 32 bit DWORD.)
 * RGB888P = 0x5 - 24-bit pixels (packed 24-bit format)
 * ARGB1555 = 0x8 - 16-bit pixels
 * ARGB4444 = 0x9 - 16-bit pixels
 * RGB555 = 0xC - 16-bit pixels
 * RGB444 = 0xD - 16-bit pixels
 * RGB565 = 0xE - 16-bit pixels
 * YUV1P444 = 0x10 - 32-bit pixels (1-plane XYUV unpacked)
 * UYVY1P422 = 0x12 - 16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
 * VYUY1P422 = 0x13 - 16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
 * Y8 = 0x14 - 8-bit monochrome pixels (1-plane Y luma output)
 * Y4 = 0x15 - 4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
 * YUV2P422 = 0x18 - 16-bit pixels (2-plane UV interleaved bytes)
 * YUV2P420 = 0x19 - 16-bit pixels (2-plane UV)
 * YVU2P422 = 0x1A - 16-bit pixels (2-plane VU interleaved bytes)
 * YVU2P420 = 0x1B - 16-bit pixels (2-plane VU)
 */

#define BP_EPXP_OUT_CTRL_FORMAT      (0)
#define BM_EPXP_OUT_CTRL_FORMAT      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_CTRL_FORMAT(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_CTRL_FORMAT)
#else
#define BF_EPXP_OUT_CTRL_FORMAT(v)   (((v) << 0) & BM_EPXP_OUT_CTRL_FORMAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FORMAT field to a new value.
#define BW_EPXP_OUT_CTRL_FORMAT(v)   BF_CS1(EPXP_OUT_CTRL, FORMAT, v)
#endif

#define BV_EPXP_OUT_CTRL_FORMAT__ARGB8888 (0x0) //!< 32-bit pixels
#define BV_EPXP_OUT_CTRL_FORMAT__RGB888 (0x4) //!< 32-bit pixels (unpacked 24-bit pixel in 32 bit DWORD.)
#define BV_EPXP_OUT_CTRL_FORMAT__RGB888P (0x5) //!< 24-bit pixels (packed 24-bit format)
#define BV_EPXP_OUT_CTRL_FORMAT__ARGB1555 (0x8) //!< 16-bit pixels
#define BV_EPXP_OUT_CTRL_FORMAT__ARGB4444 (0x9) //!< 16-bit pixels
#define BV_EPXP_OUT_CTRL_FORMAT__RGB555 (0xc) //!< 16-bit pixels
#define BV_EPXP_OUT_CTRL_FORMAT__RGB444 (0xd) //!< 16-bit pixels
#define BV_EPXP_OUT_CTRL_FORMAT__RGB565 (0xe) //!< 16-bit pixels
#define BV_EPXP_OUT_CTRL_FORMAT__YUV1P444 (0x10) //!< 32-bit pixels (1-plane XYUV unpacked)
#define BV_EPXP_OUT_CTRL_FORMAT__UYVY1P422 (0x12) //!< 16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
#define BV_EPXP_OUT_CTRL_FORMAT__VYUY1P422 (0x13) //!< 16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
#define BV_EPXP_OUT_CTRL_FORMAT__Y8 (0x14) //!< 8-bit monochrome pixels (1-plane Y luma output)
#define BV_EPXP_OUT_CTRL_FORMAT__Y4 (0x15) //!< 4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
#define BV_EPXP_OUT_CTRL_FORMAT__YUV2P422 (0x18) //!< 16-bit pixels (2-plane UV interleaved bytes)
#define BV_EPXP_OUT_CTRL_FORMAT__YUV2P420 (0x19) //!< 16-bit pixels (2-plane UV)
#define BV_EPXP_OUT_CTRL_FORMAT__YVU2P422 (0x1a) //!< 16-bit pixels (2-plane VU interleaved bytes)
#define BV_EPXP_OUT_CTRL_FORMAT__YVU2P420 (0x1b) //!< 16-bit pixels (2-plane VU)

/* --- Register HW_EPXP_OUT_CTRL, field INTERLACED_OUTPUT[9:8] (RW)
 *
 * Determines how the PXP writes it's output data. Output interlacing should not be used in
 * conjunction with input interlacing. Splitting frames into fields is most efficient using output
 * interlacing. 2-plane output formats AND interlaced output is NOT supported.
 *
 * Values:
 * PROGRESSIVE = 0x0 - All data written in progressive format to the OUTBUF Pointer.
 * FIELD0 = 0x1 - Interlaced output: only data for field 0 is written to the OUTBUF Pointer.
 * FIELD1 = 0x2 - Interlaced output: only data for field 1 is written to the OUTBUF2 Pointer.
 * INTERLACED = 0x3 - Interlaced output: data for field 0 is written to OUTBUF and data for field 1 is written to OUTBUF2.
 */

#define BP_EPXP_OUT_CTRL_INTERLACED_OUTPUT      (8)
#define BM_EPXP_OUT_CTRL_INTERLACED_OUTPUT      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_CTRL_INTERLACED_OUTPUT(v)   ((((reg32_t) v) << 8) & BM_EPXP_OUT_CTRL_INTERLACED_OUTPUT)
#else
#define BF_EPXP_OUT_CTRL_INTERLACED_OUTPUT(v)   (((v) << 8) & BM_EPXP_OUT_CTRL_INTERLACED_OUTPUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTERLACED_OUTPUT field to a new value.
#define BW_EPXP_OUT_CTRL_INTERLACED_OUTPUT(v)   BF_CS1(EPXP_OUT_CTRL, INTERLACED_OUTPUT, v)
#endif

#define BV_EPXP_OUT_CTRL_INTERLACED_OUTPUT__PROGRESSIVE (0x0) //!< All data written in progressive format to the OUTBUF Pointer.
#define BV_EPXP_OUT_CTRL_INTERLACED_OUTPUT__FIELD0 (0x1) //!< Interlaced output: only data for field 0 is written to the OUTBUF Pointer.
#define BV_EPXP_OUT_CTRL_INTERLACED_OUTPUT__FIELD1 (0x2) //!< Interlaced output: only data for field 1 is written to the OUTBUF2 Pointer.
#define BV_EPXP_OUT_CTRL_INTERLACED_OUTPUT__INTERLACED (0x3) //!< Interlaced output: data for field 0 is written to OUTBUF and data for field 1 is written to OUTBUF2.

/* --- Register HW_EPXP_OUT_CTRL, field ALPHA_OUTPUT[23:23] (RW)
 *
 * Indicates that alpha component in output buffer pixels should be overwritten by
 * PXP_OUT_CTRL[ALPHA]. If 0, retain their alpha value from the computed alpha for that pixel.
 */

#define BP_EPXP_OUT_CTRL_ALPHA_OUTPUT      (23)
#define BM_EPXP_OUT_CTRL_ALPHA_OUTPUT      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_CTRL_ALPHA_OUTPUT(v)   ((((reg32_t) v) << 23) & BM_EPXP_OUT_CTRL_ALPHA_OUTPUT)
#else
#define BF_EPXP_OUT_CTRL_ALPHA_OUTPUT(v)   (((v) << 23) & BM_EPXP_OUT_CTRL_ALPHA_OUTPUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALPHA_OUTPUT field to a new value.
#define BW_EPXP_OUT_CTRL_ALPHA_OUTPUT(v)   BF_CS1(EPXP_OUT_CTRL, ALPHA_OUTPUT, v)
#endif

/* --- Register HW_EPXP_OUT_CTRL, field ALPHA[31:24] (RW)
 *
 * When generating an output buffer with an alpha component, the value in this field will be used
 * when enabled to override the alpha passed through the pixel data pipeline.
 */

#define BP_EPXP_OUT_CTRL_ALPHA      (24)
#define BM_EPXP_OUT_CTRL_ALPHA      (0xff000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_CTRL_ALPHA(v)   ((((reg32_t) v) << 24) & BM_EPXP_OUT_CTRL_ALPHA)
#else
#define BF_EPXP_OUT_CTRL_ALPHA(v)   (((v) << 24) & BM_EPXP_OUT_CTRL_ALPHA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALPHA field to a new value.
#define BW_EPXP_OUT_CTRL_ALPHA(v)   BF_CS1(EPXP_OUT_CTRL, ALPHA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_BUF - Output Frame Buffer Pointer (RW)
 *
 * Output Framebuffer Pointer. This register points to the beginning of the output frame buffer.
 * This pointer is used for progressive format and field 0 when generating interlaced output.  This
 * register is used by the logic to point to the current output location for the output frame
 * buffer.   EXAMPLE   PXP_OUT_BUF_WR( buffer );
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Current address pointer for the output frame buffer. The address can have any byte alignment. 64B alignment is recommended for optimal performance.
    } B;
} hw_epxp_out_buf_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_BUF register
 */
#define HW_EPXP_OUT_BUF_ADDR      (REGS_EPXP_BASE + 0x30)
#define HW_EPXP_OUT_BUF_SET_ADDR  (HW_EPXP_OUT_BUF_ADDR + 0x4)
#define HW_EPXP_OUT_BUF_CLR_ADDR  (HW_EPXP_OUT_BUF_ADDR + 0x8)
#define HW_EPXP_OUT_BUF_TOG_ADDR  (HW_EPXP_OUT_BUF_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_BUF           (*(volatile hw_epxp_out_buf_t *) HW_EPXP_OUT_BUF_ADDR)
#define HW_EPXP_OUT_BUF_RD()      (HW_EPXP_OUT_BUF.U)
#define HW_EPXP_OUT_BUF_WR(v)     (HW_EPXP_OUT_BUF.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_BUF_SET_ADDR) = (v))
#define HW_EPXP_OUT_BUF_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_BUF_CLR_ADDR) = (v))
#define HW_EPXP_OUT_BUF_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_BUF_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_BUF bitfields
 */

/* --- Register HW_EPXP_OUT_BUF, field ADDR[31:0] (RW)
 *
 * Current address pointer for the output frame buffer. The address can have any byte alignment. 64B
 * alignment is recommended for optimal performance.
 */

#define BP_EPXP_OUT_BUF_ADDR      (0)
#define BM_EPXP_OUT_BUF_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_BUF_ADDR(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_BUF_ADDR)
#else
#define BF_EPXP_OUT_BUF_ADDR(v)   (((v) << 0) & BM_EPXP_OUT_BUF_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPXP_OUT_BUF_ADDR(v)   BF_CS1(EPXP_OUT_BUF, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_BUF2 - Output Frame Buffer Pointer #2 (RW)
 *
 * Output Framebuffer Pointer #2. This register points to the beginning of the output frame buffer
 * for either field 1 when generating interlaced output or for the UV buffer when in YUV 2-plane
 * output modes. Both interlaced output AND 2-plane output modes are not supported in a single PXP
 * operation. This register is NOT used as the pointer to the 2nd buffer when in LCDIF_HANDSHAKE
 * mode.  This register is used by the logic to point to the current output location for the field 1
 * or UV output frame buffer.   EXAMPLE   PXP_OUT_BUF_WR( field0 ); // buffer for interlaced field 0
 * PXP_OUT_BUF2_WR( field1 ); // buffer for interlaced field 1
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Current address pointer for the output frame buffer. The address can have any byte alignment. 64B alignment is recommended for optimal performance.
    } B;
} hw_epxp_out_buf2_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_BUF2 register
 */
#define HW_EPXP_OUT_BUF2_ADDR      (REGS_EPXP_BASE + 0x40)
#define HW_EPXP_OUT_BUF2_SET_ADDR  (HW_EPXP_OUT_BUF2_ADDR + 0x4)
#define HW_EPXP_OUT_BUF2_CLR_ADDR  (HW_EPXP_OUT_BUF2_ADDR + 0x8)
#define HW_EPXP_OUT_BUF2_TOG_ADDR  (HW_EPXP_OUT_BUF2_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_BUF2           (*(volatile hw_epxp_out_buf2_t *) HW_EPXP_OUT_BUF2_ADDR)
#define HW_EPXP_OUT_BUF2_RD()      (HW_EPXP_OUT_BUF2.U)
#define HW_EPXP_OUT_BUF2_WR(v)     (HW_EPXP_OUT_BUF2.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_BUF2_SET_ADDR) = (v))
#define HW_EPXP_OUT_BUF2_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_BUF2_CLR_ADDR) = (v))
#define HW_EPXP_OUT_BUF2_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_BUF2_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_BUF2 bitfields
 */

/* --- Register HW_EPXP_OUT_BUF2, field ADDR[31:0] (RW)
 *
 * Current address pointer for the output frame buffer. The address can have any byte alignment. 64B
 * alignment is recommended for optimal performance.
 */

#define BP_EPXP_OUT_BUF2_ADDR      (0)
#define BM_EPXP_OUT_BUF2_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_BUF2_ADDR(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_BUF2_ADDR)
#else
#define BF_EPXP_OUT_BUF2_ADDR(v)   (((v) << 0) & BM_EPXP_OUT_BUF2_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPXP_OUT_BUF2_ADDR(v)   BF_CS1(EPXP_OUT_BUF2, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_PITCH - Output Buffer Pitch (RW)
 *
 * This register contains the output buffer pitch in bytes.  Any byte value will indicate the
 * vertical pitch. This value will be used in output pixel address calculations.   EXAMPLE
 * PXP_OUT_PITCH_WR( 68 * 4 ); // The output buffer pitch is 68 pixels times 32 bits per pixel
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PITCH : 16; //!< Indicates the number of bytes in memory between two vertically adjacent pixels.
        unsigned RESERVED0 : 16; //!< Reserved, always set to zero.
    } B;
} hw_epxp_out_pitch_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_PITCH register
 */
#define HW_EPXP_OUT_PITCH_ADDR      (REGS_EPXP_BASE + 0x50)
#define HW_EPXP_OUT_PITCH_SET_ADDR  (HW_EPXP_OUT_PITCH_ADDR + 0x4)
#define HW_EPXP_OUT_PITCH_CLR_ADDR  (HW_EPXP_OUT_PITCH_ADDR + 0x8)
#define HW_EPXP_OUT_PITCH_TOG_ADDR  (HW_EPXP_OUT_PITCH_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_PITCH           (*(volatile hw_epxp_out_pitch_t *) HW_EPXP_OUT_PITCH_ADDR)
#define HW_EPXP_OUT_PITCH_RD()      (HW_EPXP_OUT_PITCH.U)
#define HW_EPXP_OUT_PITCH_WR(v)     (HW_EPXP_OUT_PITCH.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PITCH_SET_ADDR) = (v))
#define HW_EPXP_OUT_PITCH_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PITCH_CLR_ADDR) = (v))
#define HW_EPXP_OUT_PITCH_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PITCH_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_PITCH bitfields
 */

/* --- Register HW_EPXP_OUT_PITCH, field PITCH[15:0] (RW)
 *
 * Indicates the number of bytes in memory between two vertically adjacent pixels.
 */

#define BP_EPXP_OUT_PITCH_PITCH      (0)
#define BM_EPXP_OUT_PITCH_PITCH      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_PITCH_PITCH(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_PITCH_PITCH)
#else
#define BF_EPXP_OUT_PITCH_PITCH(v)   (((v) << 0) & BM_EPXP_OUT_PITCH_PITCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PITCH field to a new value.
#define BW_EPXP_OUT_PITCH_PITCH(v)   BF_CS1(EPXP_OUT_PITCH, PITCH, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_LRC - Output Surface Lower Right Coordinate (RW)
 *
 * This register contains the size, or lower right coordinate, of the output buffer NOT rotated. It
 * is implied that the upper left coordinate of the output surface is always [0,0]. When rotating
 * the framebuffer, the PXP will automatically swap the X/Y, or WIDTH/HEIGHT, to accomodate the
 * rotated size.  This register sets the size of the output frame buffer in pixels, not blocks. The
 * frame buffer need not be a multiple of NxN pixels. Partial blocks will be written for output
 * frame buffer sizes that are not divisable by N pixels in either dimension.   EXAMPLE
 * PXP_OUT_LRC[X]=319; // set width of output frame buffer to 320 pixels PXP_OUT_LRC[Y]=243; // set
 * height of output frame buffer to 244 pixels which is not divisible by block size N
 * PXP_OUT_LRC_WR( BF_PXP_OUT_LRC_X(319) | BF_PXP_OUT_LRC_Y(243) );
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned Y : 14; //!< Indicates the number of vertical PIXELS in the output surface (non-rotated). The output buffer pixel height minus 1 should be programmed. The image size is not required to be a multiple of 8 pixels. The PXP will clip the pixel output at this boundary.
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned X : 14; //!< Indicates number of horizontal PIXELS in the output surface (non-rotated). The output buffer pixel width minus 1 should be programmed. The image size is not required to be a multiple of 8 pixels. The PXP will clip the pixel output at this boundary.
        unsigned RESERVED1 : 2; //!< Reserved, always set to zero.
    } B;
} hw_epxp_out_lrc_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_LRC register
 */
#define HW_EPXP_OUT_LRC_ADDR      (REGS_EPXP_BASE + 0x60)
#define HW_EPXP_OUT_LRC_SET_ADDR  (HW_EPXP_OUT_LRC_ADDR + 0x4)
#define HW_EPXP_OUT_LRC_CLR_ADDR  (HW_EPXP_OUT_LRC_ADDR + 0x8)
#define HW_EPXP_OUT_LRC_TOG_ADDR  (HW_EPXP_OUT_LRC_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_LRC           (*(volatile hw_epxp_out_lrc_t *) HW_EPXP_OUT_LRC_ADDR)
#define HW_EPXP_OUT_LRC_RD()      (HW_EPXP_OUT_LRC.U)
#define HW_EPXP_OUT_LRC_WR(v)     (HW_EPXP_OUT_LRC.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_LRC_SET_ADDR) = (v))
#define HW_EPXP_OUT_LRC_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_LRC_CLR_ADDR) = (v))
#define HW_EPXP_OUT_LRC_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_LRC_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_LRC bitfields
 */

/* --- Register HW_EPXP_OUT_LRC, field Y[13:0] (RW)
 *
 * Indicates the number of vertical PIXELS in the output surface (non-rotated). The output buffer
 * pixel height minus 1 should be programmed. The image size is not required to be a multiple of 8
 * pixels. The PXP will clip the pixel output at this boundary.
 */

#define BP_EPXP_OUT_LRC_Y      (0)
#define BM_EPXP_OUT_LRC_Y      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_LRC_Y(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_LRC_Y)
#else
#define BF_EPXP_OUT_LRC_Y(v)   (((v) << 0) & BM_EPXP_OUT_LRC_Y)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the Y field to a new value.
#define BW_EPXP_OUT_LRC_Y(v)   BF_CS1(EPXP_OUT_LRC, Y, v)
#endif

/* --- Register HW_EPXP_OUT_LRC, field X[29:16] (RW)
 *
 * Indicates number of horizontal PIXELS in the output surface (non-rotated). The output buffer
 * pixel width minus 1 should be programmed. The image size is not required to be a multiple of 8
 * pixels. The PXP will clip the pixel output at this boundary.
 */

#define BP_EPXP_OUT_LRC_X      (16)
#define BM_EPXP_OUT_LRC_X      (0x3fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_LRC_X(v)   ((((reg32_t) v) << 16) & BM_EPXP_OUT_LRC_X)
#else
#define BF_EPXP_OUT_LRC_X(v)   (((v) << 16) & BM_EPXP_OUT_LRC_X)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X field to a new value.
#define BW_EPXP_OUT_LRC_X(v)   BF_CS1(EPXP_OUT_LRC, X, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_PS_ULC - Processed Surface Upper Left Coordinate (RW)
 *
 * This register contains the upper left pixel coordinate for the Processed Surface in the OUTPUT
 * buffer.  This register contains the upper left coordinate of the Processed Surface in the output
 * frame buffer (in pixels). Values that are within the PXP_OUT_LRC X,Y extents are valid. The
 * lowest valid value for these fields is 0,0. If the value of the PXP_OUT_PS_ULC is greater than
 * the PXP_OUT_LRC, then no PS pixels will be fetched from memory, but only PXP_PS_BACKGROUND pixels
 * will be processed by the PS engine. Pixel locations that are greater than or equal to the PS
 * upper left coordinates, less than or equal to the PS lower right coordinates, and within the
 * PXP_OUT_LRC extents will use the PS to render pixels into the output buffer.   EXAMPLE
 * PXP_OUT_PS_ULC_WR(0,0x0002_0002); // Processed Surface upper left coordinate at (X,Y) = 2,2. The
 * PS surface will not effect pixels in the first and second row and column of the output buffer.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned Y : 14; //!< This field indicates the upper left Y-coordinate (in pixels) of the processed surface in the output buffer.
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned X : 14; //!< This field indicates the upper left X-coordinate (in pixels) of the processed surface (PS) in the output buffer.
        unsigned RESERVED1 : 2; //!< Reserved, always set to zero.
    } B;
} hw_epxp_out_ps_ulc_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_PS_ULC register
 */
#define HW_EPXP_OUT_PS_ULC_ADDR      (REGS_EPXP_BASE + 0x70)
#define HW_EPXP_OUT_PS_ULC_SET_ADDR  (HW_EPXP_OUT_PS_ULC_ADDR + 0x4)
#define HW_EPXP_OUT_PS_ULC_CLR_ADDR  (HW_EPXP_OUT_PS_ULC_ADDR + 0x8)
#define HW_EPXP_OUT_PS_ULC_TOG_ADDR  (HW_EPXP_OUT_PS_ULC_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_PS_ULC           (*(volatile hw_epxp_out_ps_ulc_t *) HW_EPXP_OUT_PS_ULC_ADDR)
#define HW_EPXP_OUT_PS_ULC_RD()      (HW_EPXP_OUT_PS_ULC.U)
#define HW_EPXP_OUT_PS_ULC_WR(v)     (HW_EPXP_OUT_PS_ULC.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PS_ULC_SET_ADDR) = (v))
#define HW_EPXP_OUT_PS_ULC_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PS_ULC_CLR_ADDR) = (v))
#define HW_EPXP_OUT_PS_ULC_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PS_ULC_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_PS_ULC bitfields
 */

/* --- Register HW_EPXP_OUT_PS_ULC, field Y[13:0] (RW)
 *
 * This field indicates the upper left Y-coordinate (in pixels) of the processed surface in the
 * output buffer.
 */

#define BP_EPXP_OUT_PS_ULC_Y      (0)
#define BM_EPXP_OUT_PS_ULC_Y      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_PS_ULC_Y(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_PS_ULC_Y)
#else
#define BF_EPXP_OUT_PS_ULC_Y(v)   (((v) << 0) & BM_EPXP_OUT_PS_ULC_Y)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the Y field to a new value.
#define BW_EPXP_OUT_PS_ULC_Y(v)   BF_CS1(EPXP_OUT_PS_ULC, Y, v)
#endif

/* --- Register HW_EPXP_OUT_PS_ULC, field X[29:16] (RW)
 *
 * This field indicates the upper left X-coordinate (in pixels) of the processed surface (PS) in the
 * output buffer.
 */

#define BP_EPXP_OUT_PS_ULC_X      (16)
#define BM_EPXP_OUT_PS_ULC_X      (0x3fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_PS_ULC_X(v)   ((((reg32_t) v) << 16) & BM_EPXP_OUT_PS_ULC_X)
#else
#define BF_EPXP_OUT_PS_ULC_X(v)   (((v) << 16) & BM_EPXP_OUT_PS_ULC_X)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X field to a new value.
#define BW_EPXP_OUT_PS_ULC_X(v)   BF_CS1(EPXP_OUT_PS_ULC, X, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_PS_LRC - Processed Surface Lower Right Coordinate (RW)
 *
 * This register contains the lower right extent for the Processed Surface in the OUTPUT buffer.
 * This register contains the lower right coordinate of the Processed Surface in the output frame
 * buffer (in pixels). Values that are within the PXP_OUT_LRC X,Y extents are valid. The lowest
 * valid value for these fields is 0,0. Pixel locations that are greater than or equal to the PS
 * upper left coordinates, less than or equal to the PS lower right coordinates, and within the
 * PXP_OUT_LRC extents will use the PS to render pixels into the output buffer.   EXAMPLE
 * PXP_OUT_PS_ULC_WR(0,0x03FF_03FF); // With this UL/LR pair of pixel coordinates, only one pixel at
 * OUT[X,Y]=1023,1023 will use the PS to contribute to its value. PXP_OUT_PS_LRC_WR(0,0x03FF_03FF);
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned Y : 14; //!< This field indicates the lower right Y-coordinate (in pixels) of the processed surface in the output frame buffer.
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned X : 14; //!< This field indicates the lower right X-coordinate (in pixels) of the processed surface (PS) in the output frame buffer.
        unsigned RESERVED1 : 2; //!< Reserved, always set to zero.
    } B;
} hw_epxp_out_ps_lrc_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_PS_LRC register
 */
#define HW_EPXP_OUT_PS_LRC_ADDR      (REGS_EPXP_BASE + 0x80)
#define HW_EPXP_OUT_PS_LRC_SET_ADDR  (HW_EPXP_OUT_PS_LRC_ADDR + 0x4)
#define HW_EPXP_OUT_PS_LRC_CLR_ADDR  (HW_EPXP_OUT_PS_LRC_ADDR + 0x8)
#define HW_EPXP_OUT_PS_LRC_TOG_ADDR  (HW_EPXP_OUT_PS_LRC_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_PS_LRC           (*(volatile hw_epxp_out_ps_lrc_t *) HW_EPXP_OUT_PS_LRC_ADDR)
#define HW_EPXP_OUT_PS_LRC_RD()      (HW_EPXP_OUT_PS_LRC.U)
#define HW_EPXP_OUT_PS_LRC_WR(v)     (HW_EPXP_OUT_PS_LRC.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PS_LRC_SET_ADDR) = (v))
#define HW_EPXP_OUT_PS_LRC_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PS_LRC_CLR_ADDR) = (v))
#define HW_EPXP_OUT_PS_LRC_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_PS_LRC_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_PS_LRC bitfields
 */

/* --- Register HW_EPXP_OUT_PS_LRC, field Y[13:0] (RW)
 *
 * This field indicates the lower right Y-coordinate (in pixels) of the processed surface in the
 * output frame buffer.
 */

#define BP_EPXP_OUT_PS_LRC_Y      (0)
#define BM_EPXP_OUT_PS_LRC_Y      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_PS_LRC_Y(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_PS_LRC_Y)
#else
#define BF_EPXP_OUT_PS_LRC_Y(v)   (((v) << 0) & BM_EPXP_OUT_PS_LRC_Y)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the Y field to a new value.
#define BW_EPXP_OUT_PS_LRC_Y(v)   BF_CS1(EPXP_OUT_PS_LRC, Y, v)
#endif

/* --- Register HW_EPXP_OUT_PS_LRC, field X[29:16] (RW)
 *
 * This field indicates the lower right X-coordinate (in pixels) of the processed surface (PS) in
 * the output frame buffer.
 */

#define BP_EPXP_OUT_PS_LRC_X      (16)
#define BM_EPXP_OUT_PS_LRC_X      (0x3fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_PS_LRC_X(v)   ((((reg32_t) v) << 16) & BM_EPXP_OUT_PS_LRC_X)
#else
#define BF_EPXP_OUT_PS_LRC_X(v)   (((v) << 16) & BM_EPXP_OUT_PS_LRC_X)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X field to a new value.
#define BW_EPXP_OUT_PS_LRC_X(v)   BF_CS1(EPXP_OUT_PS_LRC, X, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_AS_ULC - Alpha Surface Upper Left Coordinate (RW)
 *
 * This register contains the upper left location for the Alpha Surface in the output buffer.  This
 * register contains the upper left coordinate of AS in the output frame buffer (in pixels). Values
 * that are within the PXP_OUT_LRC X,Y extents are valid. The lowest valid value for these fields is
 * 0,0. Pixel locations that are greater than or equal to the upper left coordinates will use the AS
 * to render pixels in the output buffer.   EXAMPLE   PXP_OUT_AS_ULC_WR(0,0x0001_0001); // Alpha
 * Surface upper left coordinate at (X,Y) = 1,1. The AS surface will not effect pixels in the first
 * row or first column of the output buffer.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned Y : 14; //!< This field indicates the upper left Y-coordinate (in pixels) of the alpha surface in the output frame buffer.
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned X : 14; //!< This field indicates the upper left X-coordinate (in pixels) of the alpha surface (AS) in the output frame buffer.
        unsigned RESERVED1 : 2; //!< Reserved, always set to zero.
    } B;
} hw_epxp_out_as_ulc_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_AS_ULC register
 */
#define HW_EPXP_OUT_AS_ULC_ADDR      (REGS_EPXP_BASE + 0x90)
#define HW_EPXP_OUT_AS_ULC_SET_ADDR  (HW_EPXP_OUT_AS_ULC_ADDR + 0x4)
#define HW_EPXP_OUT_AS_ULC_CLR_ADDR  (HW_EPXP_OUT_AS_ULC_ADDR + 0x8)
#define HW_EPXP_OUT_AS_ULC_TOG_ADDR  (HW_EPXP_OUT_AS_ULC_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_AS_ULC           (*(volatile hw_epxp_out_as_ulc_t *) HW_EPXP_OUT_AS_ULC_ADDR)
#define HW_EPXP_OUT_AS_ULC_RD()      (HW_EPXP_OUT_AS_ULC.U)
#define HW_EPXP_OUT_AS_ULC_WR(v)     (HW_EPXP_OUT_AS_ULC.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_AS_ULC_SET_ADDR) = (v))
#define HW_EPXP_OUT_AS_ULC_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_AS_ULC_CLR_ADDR) = (v))
#define HW_EPXP_OUT_AS_ULC_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_AS_ULC_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_AS_ULC bitfields
 */

/* --- Register HW_EPXP_OUT_AS_ULC, field Y[13:0] (RW)
 *
 * This field indicates the upper left Y-coordinate (in pixels) of the alpha surface in the output
 * frame buffer.
 */

#define BP_EPXP_OUT_AS_ULC_Y      (0)
#define BM_EPXP_OUT_AS_ULC_Y      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_AS_ULC_Y(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_AS_ULC_Y)
#else
#define BF_EPXP_OUT_AS_ULC_Y(v)   (((v) << 0) & BM_EPXP_OUT_AS_ULC_Y)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the Y field to a new value.
#define BW_EPXP_OUT_AS_ULC_Y(v)   BF_CS1(EPXP_OUT_AS_ULC, Y, v)
#endif

/* --- Register HW_EPXP_OUT_AS_ULC, field X[29:16] (RW)
 *
 * This field indicates the upper left X-coordinate (in pixels) of the alpha surface (AS) in the
 * output frame buffer.
 */

#define BP_EPXP_OUT_AS_ULC_X      (16)
#define BM_EPXP_OUT_AS_ULC_X      (0x3fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_AS_ULC_X(v)   ((((reg32_t) v) << 16) & BM_EPXP_OUT_AS_ULC_X)
#else
#define BF_EPXP_OUT_AS_ULC_X(v)   (((v) << 16) & BM_EPXP_OUT_AS_ULC_X)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X field to a new value.
#define BW_EPXP_OUT_AS_ULC_X(v)   BF_CS1(EPXP_OUT_AS_ULC, X, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_OUT_AS_LRC - Alpha Surface Lower Right Coordinate (RW)
 *
 * This register contains the lower right extent for Alpha Surface in the output buffer.  This
 * register contains the lower right coordinate of AS in the output frame buffer (in pixels). Values
 * that are within the PXP_OUT_LRC X,Y extents are valid. The lowest valid value for these fields is
 * 0,0. Pixel locations that are less than or equal to the lower right coordinates will use the AS
 * to render pixels in the output buffer.   EXAMPLE   PXP_AS_LRC_WR(0,0x03FF_03FF); // Alpha Surface
 * lower right coordinate at (X,Y) = 1023,1023.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned Y : 14; //!< This field indicates the lower right Y-coordinate (in pixels) of the alpha surface in the output frame buffer.
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned X : 14; //!< This field indicates the lower right X-coordinate (in pixels) of the alpha surface (AS) in the output frame buffer.
        unsigned RESERVED1 : 2; //!< Reserved, always set to zero.
    } B;
} hw_epxp_out_as_lrc_t;
#endif

/*
 * constants & macros for entire EPXP_OUT_AS_LRC register
 */
#define HW_EPXP_OUT_AS_LRC_ADDR      (REGS_EPXP_BASE + 0xa0)
#define HW_EPXP_OUT_AS_LRC_SET_ADDR  (HW_EPXP_OUT_AS_LRC_ADDR + 0x4)
#define HW_EPXP_OUT_AS_LRC_CLR_ADDR  (HW_EPXP_OUT_AS_LRC_ADDR + 0x8)
#define HW_EPXP_OUT_AS_LRC_TOG_ADDR  (HW_EPXP_OUT_AS_LRC_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_OUT_AS_LRC           (*(volatile hw_epxp_out_as_lrc_t *) HW_EPXP_OUT_AS_LRC_ADDR)
#define HW_EPXP_OUT_AS_LRC_RD()      (HW_EPXP_OUT_AS_LRC.U)
#define HW_EPXP_OUT_AS_LRC_WR(v)     (HW_EPXP_OUT_AS_LRC.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_AS_LRC_SET_ADDR) = (v))
#define HW_EPXP_OUT_AS_LRC_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_AS_LRC_CLR_ADDR) = (v))
#define HW_EPXP_OUT_AS_LRC_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_OUT_AS_LRC_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_OUT_AS_LRC bitfields
 */

/* --- Register HW_EPXP_OUT_AS_LRC, field Y[13:0] (RW)
 *
 * This field indicates the lower right Y-coordinate (in pixels) of the alpha surface in the output
 * frame buffer.
 */

#define BP_EPXP_OUT_AS_LRC_Y      (0)
#define BM_EPXP_OUT_AS_LRC_Y      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_AS_LRC_Y(v)   ((((reg32_t) v) << 0) & BM_EPXP_OUT_AS_LRC_Y)
#else
#define BF_EPXP_OUT_AS_LRC_Y(v)   (((v) << 0) & BM_EPXP_OUT_AS_LRC_Y)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the Y field to a new value.
#define BW_EPXP_OUT_AS_LRC_Y(v)   BF_CS1(EPXP_OUT_AS_LRC, Y, v)
#endif

/* --- Register HW_EPXP_OUT_AS_LRC, field X[29:16] (RW)
 *
 * This field indicates the lower right X-coordinate (in pixels) of the alpha surface (AS) in the
 * output frame buffer.
 */

#define BP_EPXP_OUT_AS_LRC_X      (16)
#define BM_EPXP_OUT_AS_LRC_X      (0x3fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_OUT_AS_LRC_X(v)   ((((reg32_t) v) << 16) & BM_EPXP_OUT_AS_LRC_X)
#else
#define BF_EPXP_OUT_AS_LRC_X(v)   (((v) << 16) & BM_EPXP_OUT_AS_LRC_X)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X field to a new value.
#define BW_EPXP_OUT_AS_LRC_X(v)   BF_CS1(EPXP_OUT_AS_LRC, X, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_CTRL - Processed Surface (PS) Control Register (RW)
 *
 * The PS_CTRL register contains controls for the Processed Surface Buffer.  PXP_PS_CTRL: 0x0B0
 * PXP_PS_CTRL_SET: 0x0b4  PXP_PS_CTRL_CLR: 0x0B8  PXP_PS_CTRL_TOG: 0x0BC  The Control register
 * contains the primary controls for the PXP block. The present bits indicate which of the sub-
 * features of the block are present in the hardware.   EXAMPLE   PXP_CTRL_SET(BM_PXP_CTRL_SFTRST);
 * PXP_CTRL_CLR(BM_PXP_CTRL_SFTRST | BM_PXP_CTRL_CLKGATE);
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FORMAT : 5; //!< PS buffer format. To select between YUV and YCbCr formats, see bit 31 of the CSC1_COEF0 register.
        unsigned WB_SWAP : 1; //!< Swap bytes in words. For each 16 bit word, the two bytes will be swapped.
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned DECY : 2; //!< Verticle pre decimation filter control.
        unsigned DECX : 2; //!< Horizontal pre decimation filter control.
        unsigned RESERVED1 : 20; //!< Reserved, always set to zero.
    } B;
} hw_epxp_ps_ctrl_t;
#endif

/*
 * constants & macros for entire EPXP_PS_CTRL register
 */
#define HW_EPXP_PS_CTRL_ADDR      (REGS_EPXP_BASE + 0xb0)
#define HW_EPXP_PS_CTRL_SET_ADDR  (HW_EPXP_PS_CTRL_ADDR + 0x4)
#define HW_EPXP_PS_CTRL_CLR_ADDR  (HW_EPXP_PS_CTRL_ADDR + 0x8)
#define HW_EPXP_PS_CTRL_TOG_ADDR  (HW_EPXP_PS_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_CTRL           (*(volatile hw_epxp_ps_ctrl_t *) HW_EPXP_PS_CTRL_ADDR)
#define HW_EPXP_PS_CTRL_RD()      (HW_EPXP_PS_CTRL.U)
#define HW_EPXP_PS_CTRL_WR(v)     (HW_EPXP_PS_CTRL.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CTRL_SET_ADDR) = (v))
#define HW_EPXP_PS_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CTRL_CLR_ADDR) = (v))
#define HW_EPXP_PS_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_CTRL bitfields
 */

/* --- Register HW_EPXP_PS_CTRL, field FORMAT[4:0] (RW)
 *
 * PS buffer format. To select between YUV and YCbCr formats, see bit 31 of the CSC1_COEF0 register.
 *
 * Values:
 * RGB888 = 0x4 - 32-bit pixels (unpacked 24-bit format)
 * RGB555 = 0xC - 16-bit pixels
 * RGB444 = 0xD - 16-bit pixels
 * RGB565 = 0xE - 16-bit pixels
 * YUV1P444 = 0x10 - 32-bit pixels (1-plane XYUV unpacked)
 * UYVY1P422 = 0x12 - 16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
 * VYUY1P422 = 0x13 - 16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
 * Y8 = 0x14 - 8-bit monochrome pixels (1-plane Y luma output)
 * Y4 = 0x15 - 4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
 * YUV2P422 = 0x18 - 16-bit pixels (2-plane UV interleaved bytes)
 * YUV2P420 = 0x19 - 16-bit pixels (2-plane UV)
 * YVU2P422 = 0x1A - 16-bit pixels (2-plane VU interleaved bytes)
 * YVU2P420 = 0x1B - 16-bit pixels (2-plane VU)
 * YUV422 = 0x1E - 16-bit pixels (3-plane format)
 * YUV420 = 0x1F - 16-bit pixels (3-plane format)
 */

#define BP_EPXP_PS_CTRL_FORMAT      (0)
#define BM_EPXP_PS_CTRL_FORMAT      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_CTRL_FORMAT(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_CTRL_FORMAT)
#else
#define BF_EPXP_PS_CTRL_FORMAT(v)   (((v) << 0) & BM_EPXP_PS_CTRL_FORMAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FORMAT field to a new value.
#define BW_EPXP_PS_CTRL_FORMAT(v)   BF_CS1(EPXP_PS_CTRL, FORMAT, v)
#endif

#define BV_EPXP_PS_CTRL_FORMAT__RGB888 (0x4) //!< 32-bit pixels (unpacked 24-bit format)
#define BV_EPXP_PS_CTRL_FORMAT__RGB555 (0xc) //!< 16-bit pixels
#define BV_EPXP_PS_CTRL_FORMAT__RGB444 (0xd) //!< 16-bit pixels
#define BV_EPXP_PS_CTRL_FORMAT__RGB565 (0xe) //!< 16-bit pixels
#define BV_EPXP_PS_CTRL_FORMAT__YUV1P444 (0x10) //!< 32-bit pixels (1-plane XYUV unpacked)
#define BV_EPXP_PS_CTRL_FORMAT__UYVY1P422 (0x12) //!< 16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
#define BV_EPXP_PS_CTRL_FORMAT__VYUY1P422 (0x13) //!< 16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
#define BV_EPXP_PS_CTRL_FORMAT__Y8 (0x14) //!< 8-bit monochrome pixels (1-plane Y luma output)
#define BV_EPXP_PS_CTRL_FORMAT__Y4 (0x15) //!< 4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
#define BV_EPXP_PS_CTRL_FORMAT__YUV2P422 (0x18) //!< 16-bit pixels (2-plane UV interleaved bytes)
#define BV_EPXP_PS_CTRL_FORMAT__YUV2P420 (0x19) //!< 16-bit pixels (2-plane UV)
#define BV_EPXP_PS_CTRL_FORMAT__YVU2P422 (0x1a) //!< 16-bit pixels (2-plane VU interleaved bytes)
#define BV_EPXP_PS_CTRL_FORMAT__YVU2P420 (0x1b) //!< 16-bit pixels (2-plane VU)
#define BV_EPXP_PS_CTRL_FORMAT__YUV422 (0x1e) //!< 16-bit pixels (3-plane format)
#define BV_EPXP_PS_CTRL_FORMAT__YUV420 (0x1f) //!< 16-bit pixels (3-plane format)

/* --- Register HW_EPXP_PS_CTRL, field WB_SWAP[5:5] (RW)
 *
 * Swap bytes in words. For each 16 bit word, the two bytes will be swapped.
 */

#define BP_EPXP_PS_CTRL_WB_SWAP      (5)
#define BM_EPXP_PS_CTRL_WB_SWAP      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_CTRL_WB_SWAP(v)   ((((reg32_t) v) << 5) & BM_EPXP_PS_CTRL_WB_SWAP)
#else
#define BF_EPXP_PS_CTRL_WB_SWAP(v)   (((v) << 5) & BM_EPXP_PS_CTRL_WB_SWAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WB_SWAP field to a new value.
#define BW_EPXP_PS_CTRL_WB_SWAP(v)   BF_CS1(EPXP_PS_CTRL, WB_SWAP, v)
#endif

/* --- Register HW_EPXP_PS_CTRL, field DECY[9:8] (RW)
 *
 * Verticle pre decimation filter control.
 *
 * Values:
 * DISABLE = 0x0 - Disable pre-decimation filter.
 * DECY2 = 0x1 - Decimate PS by 2.
 * DECY4 = 0x2 - Decimate PS by 4.
 * DECY8 = 0x3 - Decimate PS by 8.
 */

#define BP_EPXP_PS_CTRL_DECY      (8)
#define BM_EPXP_PS_CTRL_DECY      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_CTRL_DECY(v)   ((((reg32_t) v) << 8) & BM_EPXP_PS_CTRL_DECY)
#else
#define BF_EPXP_PS_CTRL_DECY(v)   (((v) << 8) & BM_EPXP_PS_CTRL_DECY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DECY field to a new value.
#define BW_EPXP_PS_CTRL_DECY(v)   BF_CS1(EPXP_PS_CTRL, DECY, v)
#endif

#define BV_EPXP_PS_CTRL_DECY__DISABLE (0x0) //!< Disable pre-decimation filter.
#define BV_EPXP_PS_CTRL_DECY__DECY2 (0x1) //!< Decimate PS by 2.
#define BV_EPXP_PS_CTRL_DECY__DECY4 (0x2) //!< Decimate PS by 4.
#define BV_EPXP_PS_CTRL_DECY__DECY8 (0x3) //!< Decimate PS by 8.

/* --- Register HW_EPXP_PS_CTRL, field DECX[11:10] (RW)
 *
 * Horizontal pre decimation filter control.
 *
 * Values:
 * DISABLE = 0x0 - Disable pre-decimation filter.
 * DECX2 = 0x1 - Decimate PS by 2.
 * DECX4 = 0x2 - Decimate PS by 4.
 * DECX8 = 0x3 - Decimate PS by 8.
 */

#define BP_EPXP_PS_CTRL_DECX      (10)
#define BM_EPXP_PS_CTRL_DECX      (0x00000c00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_CTRL_DECX(v)   ((((reg32_t) v) << 10) & BM_EPXP_PS_CTRL_DECX)
#else
#define BF_EPXP_PS_CTRL_DECX(v)   (((v) << 10) & BM_EPXP_PS_CTRL_DECX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DECX field to a new value.
#define BW_EPXP_PS_CTRL_DECX(v)   BF_CS1(EPXP_PS_CTRL, DECX, v)
#endif

#define BV_EPXP_PS_CTRL_DECX__DISABLE (0x0) //!< Disable pre-decimation filter.
#define BV_EPXP_PS_CTRL_DECX__DECX2 (0x1) //!< Decimate PS by 2.
#define BV_EPXP_PS_CTRL_DECX__DECX4 (0x2) //!< Decimate PS by 4.
#define BV_EPXP_PS_CTRL_DECX__DECX8 (0x3) //!< Decimate PS by 8.

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_BUF - PS Input Buffer Address (RW)
 *
 * PS Input Buffer Address. This should be programmed to the starting address of the RGB data or Y
 * (luma) data for the PS plane.  This register contains the pointer to the Luma/RGB buffer. If the
 * application requires an offset into the PS buffer, then this address can be set so that the
 * desired offset is achieved. Any byte address is valid. For best performance, 64B alignment is
 * recommended.   EXAMPLE   PXP_PS_BUF_WR(image_rgb); // RGB image PXP_PS_BUF_WR(image_y); // Y
 * (luma) image data PXP_PS_UBUF_WR(image_u); // U (Cb) image data PXP_PS_VBUF_WR(image_v); // V
 * (Cr) image data
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Address pointer for the PS RGB or Y (luma) input buffer.
    } B;
} hw_epxp_ps_buf_t;
#endif

/*
 * constants & macros for entire EPXP_PS_BUF register
 */
#define HW_EPXP_PS_BUF_ADDR      (REGS_EPXP_BASE + 0xc0)
#define HW_EPXP_PS_BUF_SET_ADDR  (HW_EPXP_PS_BUF_ADDR + 0x4)
#define HW_EPXP_PS_BUF_CLR_ADDR  (HW_EPXP_PS_BUF_ADDR + 0x8)
#define HW_EPXP_PS_BUF_TOG_ADDR  (HW_EPXP_PS_BUF_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_BUF           (*(volatile hw_epxp_ps_buf_t *) HW_EPXP_PS_BUF_ADDR)
#define HW_EPXP_PS_BUF_RD()      (HW_EPXP_PS_BUF.U)
#define HW_EPXP_PS_BUF_WR(v)     (HW_EPXP_PS_BUF.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_BUF_SET_ADDR) = (v))
#define HW_EPXP_PS_BUF_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_BUF_CLR_ADDR) = (v))
#define HW_EPXP_PS_BUF_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_BUF_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_BUF bitfields
 */

/* --- Register HW_EPXP_PS_BUF, field ADDR[31:0] (RW)
 *
 * Address pointer for the PS RGB or Y (luma) input buffer.
 */

#define BP_EPXP_PS_BUF_ADDR      (0)
#define BM_EPXP_PS_BUF_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_BUF_ADDR(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_BUF_ADDR)
#else
#define BF_EPXP_PS_BUF_ADDR(v)   (((v) << 0) & BM_EPXP_PS_BUF_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPXP_PS_BUF_ADDR(v)   BF_CS1(EPXP_PS_BUF, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_UBUF - PS U/Cb or 2 Plane UV Input Buffer Address (RW)
 *
 * PS Chroma (U/Cb/UV) Input Buffer Address. This register points to the beginning of the PS U/Cb
 * input buffer. In two plane operation, this register points to the beginning of the PS UV chroma
 * input buffer.  This register contains the pointer to the Chroma U/Cb or 2 plane UV buffer. This
 * register is unused when processing 1-plane buffer formats. If the application requires an offset
 * into the PS buffer, then this address can be set so that the desired offset is achieved. Any byte
 * address is valid. For best performance, 64B alignment is recommended.   EXAMPLE
 * PXP_PS_BUF_WR(image_y); // Y (luma) image data PXP_PS_UBUF_WR(image_u); // U (Cb) image data
 * PXP_PS_VBUF_WR(image_v); // V (Cr) image data
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Address pointer for the PS U/Cb or 2 plane UV Chroma input buffer.
    } B;
} hw_epxp_ps_ubuf_t;
#endif

/*
 * constants & macros for entire EPXP_PS_UBUF register
 */
#define HW_EPXP_PS_UBUF_ADDR      (REGS_EPXP_BASE + 0xd0)
#define HW_EPXP_PS_UBUF_SET_ADDR  (HW_EPXP_PS_UBUF_ADDR + 0x4)
#define HW_EPXP_PS_UBUF_CLR_ADDR  (HW_EPXP_PS_UBUF_ADDR + 0x8)
#define HW_EPXP_PS_UBUF_TOG_ADDR  (HW_EPXP_PS_UBUF_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_UBUF           (*(volatile hw_epxp_ps_ubuf_t *) HW_EPXP_PS_UBUF_ADDR)
#define HW_EPXP_PS_UBUF_RD()      (HW_EPXP_PS_UBUF.U)
#define HW_EPXP_PS_UBUF_WR(v)     (HW_EPXP_PS_UBUF.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_UBUF_SET_ADDR) = (v))
#define HW_EPXP_PS_UBUF_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_UBUF_CLR_ADDR) = (v))
#define HW_EPXP_PS_UBUF_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_UBUF_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_UBUF bitfields
 */

/* --- Register HW_EPXP_PS_UBUF, field ADDR[31:0] (RW)
 *
 * Address pointer for the PS U/Cb or 2 plane UV Chroma input buffer.
 */

#define BP_EPXP_PS_UBUF_ADDR      (0)
#define BM_EPXP_PS_UBUF_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_UBUF_ADDR(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_UBUF_ADDR)
#else
#define BF_EPXP_PS_UBUF_ADDR(v)   (((v) << 0) & BM_EPXP_PS_UBUF_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPXP_PS_UBUF_ADDR(v)   BF_CS1(EPXP_PS_UBUF, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_VBUF - PS V/Cr Input Buffer Address (RW)
 *
 * PS Chroma (V/Cr) Input Buffer Address. This register points to the beginning of the PS V/Cr input
 * buffer. In one or two plane operation, this register is not used. In monochrome modes Y8 and Y4,
 * the low 16 bits are used as the U/V data in the datapath instead of sourcing U/V data from
 * external buffers. In this case, it represents a fixed value for U/V data.  This register contains
 * the pointer to the Chroma V/Cr buffer. For Y8/Y4 modes, the low 16 bits are used as the
 * monochrome U and V values in the data path. Bits [15:8] represent the U data byte, and bits ]7:0]
 * represent the V data byte. Other than with Y8/Y4 input buffer formats, this register is unused
 * when processing 1 or 2-plane buffer formats. If the application requires an offset into the PS
 * buffer, then this address can be set so that the desired offset is achieved. Any byte address is
 * valid. For best performance, 64B alignment is recommended.   EXAMPLE   PXP_PS_BUF_WR(image_y); //
 * Y (luma) image data PXP_PS_UBUF_WR(image_u); // U (Cb) image data PXP_PS_VBUF_WR(image_v); // V
 * (Cr) image data
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Address pointer for the PS V/Cr Chroma input buffer.
    } B;
} hw_epxp_ps_vbuf_t;
#endif

/*
 * constants & macros for entire EPXP_PS_VBUF register
 */
#define HW_EPXP_PS_VBUF_ADDR      (REGS_EPXP_BASE + 0xe0)
#define HW_EPXP_PS_VBUF_SET_ADDR  (HW_EPXP_PS_VBUF_ADDR + 0x4)
#define HW_EPXP_PS_VBUF_CLR_ADDR  (HW_EPXP_PS_VBUF_ADDR + 0x8)
#define HW_EPXP_PS_VBUF_TOG_ADDR  (HW_EPXP_PS_VBUF_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_VBUF           (*(volatile hw_epxp_ps_vbuf_t *) HW_EPXP_PS_VBUF_ADDR)
#define HW_EPXP_PS_VBUF_RD()      (HW_EPXP_PS_VBUF.U)
#define HW_EPXP_PS_VBUF_WR(v)     (HW_EPXP_PS_VBUF.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_VBUF_SET_ADDR) = (v))
#define HW_EPXP_PS_VBUF_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_VBUF_CLR_ADDR) = (v))
#define HW_EPXP_PS_VBUF_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_VBUF_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_VBUF bitfields
 */

/* --- Register HW_EPXP_PS_VBUF, field ADDR[31:0] (RW)
 *
 * Address pointer for the PS V/Cr Chroma input buffer.
 */

#define BP_EPXP_PS_VBUF_ADDR      (0)
#define BM_EPXP_PS_VBUF_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_VBUF_ADDR(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_VBUF_ADDR)
#else
#define BF_EPXP_PS_VBUF_ADDR(v)   (((v) << 0) & BM_EPXP_PS_VBUF_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPXP_PS_VBUF_ADDR(v)   BF_CS1(EPXP_PS_VBUF, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_PITCH - Processed Surface Pitch (RW)
 *
 * This register contains the processed surface pitch in bytes.  Any byte value will indicate the
 * vertical pitch of the PS source frame buffer. This value will be used in PS pixel address
 * calculations. This value has no relation to the UL and LR registers. It specifies how many bytes
 * are between two vertically adjacent pixels in the input PS surface. For multi-plane formats, the
 * Y buffer pitch should be programmed. For 2-plane YUV422, the UV pitch is the same as the Y pitch.
 * For 3-plane YUV422, the U and V pitch is 1/2 the Y pitch. For 2-plane YUV420, the UV pitch is 1/2
 * the Y pitch. For 3-plane YUV420, the U and V pitch is 1/4 the Y pitch. All source buffers should
 * comply with these U and V resolution reductions with respect to their Y source buffers.   EXAMPLE
 * PXP_PS_PITCH_WR( 64 * 4 ); // The output buffer pitch is 64 pixels times 32 bits per pixel
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PITCH : 16; //!< Indicates the number of bytes in memory between two vertically adjacent pixels.
        unsigned RESERVED0 : 16; //!< Reserved, always set to zero.
    } B;
} hw_epxp_ps_pitch_t;
#endif

/*
 * constants & macros for entire EPXP_PS_PITCH register
 */
#define HW_EPXP_PS_PITCH_ADDR      (REGS_EPXP_BASE + 0xf0)
#define HW_EPXP_PS_PITCH_SET_ADDR  (HW_EPXP_PS_PITCH_ADDR + 0x4)
#define HW_EPXP_PS_PITCH_CLR_ADDR  (HW_EPXP_PS_PITCH_ADDR + 0x8)
#define HW_EPXP_PS_PITCH_TOG_ADDR  (HW_EPXP_PS_PITCH_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_PITCH           (*(volatile hw_epxp_ps_pitch_t *) HW_EPXP_PS_PITCH_ADDR)
#define HW_EPXP_PS_PITCH_RD()      (HW_EPXP_PS_PITCH.U)
#define HW_EPXP_PS_PITCH_WR(v)     (HW_EPXP_PS_PITCH.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_PITCH_SET_ADDR) = (v))
#define HW_EPXP_PS_PITCH_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_PITCH_CLR_ADDR) = (v))
#define HW_EPXP_PS_PITCH_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_PITCH_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_PITCH bitfields
 */

/* --- Register HW_EPXP_PS_PITCH, field PITCH[15:0] (RW)
 *
 * Indicates the number of bytes in memory between two vertically adjacent pixels.
 */

#define BP_EPXP_PS_PITCH_PITCH      (0)
#define BM_EPXP_PS_PITCH_PITCH      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_PITCH_PITCH(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_PITCH_PITCH)
#else
#define BF_EPXP_PS_PITCH_PITCH(v)   (((v) << 0) & BM_EPXP_PS_PITCH_PITCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PITCH field to a new value.
#define BW_EPXP_PS_PITCH_PITCH(v)   BF_CS1(EPXP_PS_PITCH, PITCH, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_BACKGROUND - PS Background Color (RW)
 *
 * PS Background Pixel Color. This register provides a pixel value used when processing pixels
 * outside of the region specified by the PS Coordinate registers. This value can effectively be
 * used to set the color of the letterboxing region around the PS image.  This register contains a
 * pixel value to be used for any PS pixels that fall outside the PS extents. This is effectively a
 * background or letterbox color. The CSC1 control and datapath pixel format should be considered
 * when selecting the background color.   EXAMPLE   PXP_PS_BACKGROUND_WR(0x00000000); // letterbox
 * is black PXP_PS_BACKGROUND_WR(0x00800000); // letterbox is dark red
 * PXP_PS_BACKGROUND_WR(0x00008000); // letterbox is dark green PXP_PS_BACKGROUND_WR(0x00000080); //
 * letterbox is dark blue
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned COLOR : 24; //!< Background color (in 24bpp format) for any pixels not within the buffer range specified by the PS ULC/LRC.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
    } B;
} hw_epxp_ps_background_t;
#endif

/*
 * constants & macros for entire EPXP_PS_BACKGROUND register
 */
#define HW_EPXP_PS_BACKGROUND_ADDR      (REGS_EPXP_BASE + 0x100)
#define HW_EPXP_PS_BACKGROUND_SET_ADDR  (HW_EPXP_PS_BACKGROUND_ADDR + 0x4)
#define HW_EPXP_PS_BACKGROUND_CLR_ADDR  (HW_EPXP_PS_BACKGROUND_ADDR + 0x8)
#define HW_EPXP_PS_BACKGROUND_TOG_ADDR  (HW_EPXP_PS_BACKGROUND_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_BACKGROUND           (*(volatile hw_epxp_ps_background_t *) HW_EPXP_PS_BACKGROUND_ADDR)
#define HW_EPXP_PS_BACKGROUND_RD()      (HW_EPXP_PS_BACKGROUND.U)
#define HW_EPXP_PS_BACKGROUND_WR(v)     (HW_EPXP_PS_BACKGROUND.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_BACKGROUND_SET_ADDR) = (v))
#define HW_EPXP_PS_BACKGROUND_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_BACKGROUND_CLR_ADDR) = (v))
#define HW_EPXP_PS_BACKGROUND_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_BACKGROUND_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_BACKGROUND bitfields
 */

/* --- Register HW_EPXP_PS_BACKGROUND, field COLOR[23:0] (RW)
 *
 * Background color (in 24bpp format) for any pixels not within the buffer range specified by the PS
 * ULC/LRC.
 */

#define BP_EPXP_PS_BACKGROUND_COLOR      (0)
#define BM_EPXP_PS_BACKGROUND_COLOR      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_BACKGROUND_COLOR(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_BACKGROUND_COLOR)
#else
#define BF_EPXP_PS_BACKGROUND_COLOR(v)   (((v) << 0) & BM_EPXP_PS_BACKGROUND_COLOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the COLOR field to a new value.
#define BW_EPXP_PS_BACKGROUND_COLOR(v)   BF_CS1(EPXP_PS_BACKGROUND, COLOR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_SCALE - PS Scale Factor Register (RW)
 *
 * PS Scale Factor. This register provides the scale factor for the PS buffer.  The maximum down
 * scaling factor is 1/2 such that the output image in either axis is 1/2 the size of the source.
 * The maximum up scaling factor is 2^12 for either axis. The reciprocal of the scale factor should
 * be loaded into this register. To reduce the PS buffer by a factor of two in the output frame
 * buffer, a value of 10.0000_0000_0000 should be loaded into this register. To scale up by a factor
 * of 4, the value of 1/4, or 00.0100_0000_0000, should be loaded into this register. To scale up by
 * 8/5, the value of 00.1010_0000_0000 should be loaded.   EXAMPLE   PXP_PS_SCALE_WR(0x10001000); //
 * 1:1 scaling (0x1.000) PXP_PS_SCALE_WR(0x08000800); // 2x scaling (0x0.800)
 * PXP_PS_SCALE_WR(0x20002000); // 1/2x scaling (0x2.000)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned XSCALE : 15; //!< This is a two bit integer and 12 bit fractional representation (##.####_####_####) of the X scaling factor for the PS source buffer. The maximum value programmed should be 2 since scaling down by a factor greater than 2 is not supported with the bilinear filter. Decimation and the bilinear filter should be used together to achieve scaling by more than a factor of 2.
        unsigned RESERVED0 : 1; //!< Reserved, always set to zero.
        unsigned YSCALE : 15; //!< This is a two bit integer and 12 bit fractional representation (##.####_####_####) of the Y scaling factor for the PS source buffer. The maximum value programmed should be 2 since scaling down by a factor greater than 2 is not supported with the bilinear filter. Decimation and the bilinear filter should be used together to achieve scaling by more than a factor of 2.
        unsigned RESERVED1 : 1; //!< Reserved, always set to zero.
    } B;
} hw_epxp_ps_scale_t;
#endif

/*
 * constants & macros for entire EPXP_PS_SCALE register
 */
#define HW_EPXP_PS_SCALE_ADDR      (REGS_EPXP_BASE + 0x110)
#define HW_EPXP_PS_SCALE_SET_ADDR  (HW_EPXP_PS_SCALE_ADDR + 0x4)
#define HW_EPXP_PS_SCALE_CLR_ADDR  (HW_EPXP_PS_SCALE_ADDR + 0x8)
#define HW_EPXP_PS_SCALE_TOG_ADDR  (HW_EPXP_PS_SCALE_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_SCALE           (*(volatile hw_epxp_ps_scale_t *) HW_EPXP_PS_SCALE_ADDR)
#define HW_EPXP_PS_SCALE_RD()      (HW_EPXP_PS_SCALE.U)
#define HW_EPXP_PS_SCALE_WR(v)     (HW_EPXP_PS_SCALE.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_SCALE_SET_ADDR) = (v))
#define HW_EPXP_PS_SCALE_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_SCALE_CLR_ADDR) = (v))
#define HW_EPXP_PS_SCALE_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_SCALE_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_SCALE bitfields
 */

/* --- Register HW_EPXP_PS_SCALE, field XSCALE[14:0] (RW)
 *
 * This is a two bit integer and 12 bit fractional representation (##.####_####_####) of the X
 * scaling factor for the PS source buffer. The maximum value programmed should be 2 since scaling
 * down by a factor greater than 2 is not supported with the bilinear filter. Decimation and the
 * bilinear filter should be used together to achieve scaling by more than a factor of 2.
 */

#define BP_EPXP_PS_SCALE_XSCALE      (0)
#define BM_EPXP_PS_SCALE_XSCALE      (0x00007fff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_SCALE_XSCALE(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_SCALE_XSCALE)
#else
#define BF_EPXP_PS_SCALE_XSCALE(v)   (((v) << 0) & BM_EPXP_PS_SCALE_XSCALE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the XSCALE field to a new value.
#define BW_EPXP_PS_SCALE_XSCALE(v)   BF_CS1(EPXP_PS_SCALE, XSCALE, v)
#endif

/* --- Register HW_EPXP_PS_SCALE, field YSCALE[30:16] (RW)
 *
 * This is a two bit integer and 12 bit fractional representation (##.####_####_####) of the Y
 * scaling factor for the PS source buffer. The maximum value programmed should be 2 since scaling
 * down by a factor greater than 2 is not supported with the bilinear filter. Decimation and the
 * bilinear filter should be used together to achieve scaling by more than a factor of 2.
 */

#define BP_EPXP_PS_SCALE_YSCALE      (16)
#define BM_EPXP_PS_SCALE_YSCALE      (0x7fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_SCALE_YSCALE(v)   ((((reg32_t) v) << 16) & BM_EPXP_PS_SCALE_YSCALE)
#else
#define BF_EPXP_PS_SCALE_YSCALE(v)   (((v) << 16) & BM_EPXP_PS_SCALE_YSCALE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the YSCALE field to a new value.
#define BW_EPXP_PS_SCALE_YSCALE(v)   BF_CS1(EPXP_PS_SCALE, YSCALE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_OFFSET - PS Scale Offset Register (RW)
 *
 * PS Scale Offset. This register provides the initial scale offset for the PS buffer.  The X and Y
 * offset provides the ability to access the source image with a per sub-pixel granularity. This
 * provides the capability to use all source pixels to effect the output PS image. The fixed offset
 * values can be used for sub-pixel adjustments in the bilinear scaling filter. For example, when
 * scaling an image down by a factor of 2, an initial offset of 0x0 would result in sub-sampling
 * every other pixel. If a fixed offset of 0x800 (1/2), all pixels are used in scaling the final
 * output pixel value. In this case, the first output pixel would be the sum of (1/2*P0) + (1/2*P1).
 * This fixed offset is applied after the decimation filter stage, and before the bilinear filter
 * stage.   EXAMPLE   PXP_PS_SCALE_WR(0x2000_2000); // 1/2x scaling (0x2.000)
 * PXP_PS_OFFSET_WR(0x0800_0800); // half-pixel offset in both X and Y to ensure averaging versus
 * pixel decimation
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned XOFFSET : 12; //!< This is a 12 bit fractional representation (0.####_####_####) of the X scaling offset. This represents a fixed pixel offset which gets added to the scaled address to determine source data for the scaling engine.
        unsigned RESERVED0 : 4; //!< Reserved, always set to zero.
        unsigned YOFFSET : 12; //!< This is a 12 bit fractional representation (0.####_####_####) of the Y scaling offset. This represents a fixed pixel offset which gets added to the scaled address to determine source data for the scaling engine.
        unsigned RESERVED1 : 4; //!< Reserved, always set to zero.
    } B;
} hw_epxp_ps_offset_t;
#endif

/*
 * constants & macros for entire EPXP_PS_OFFSET register
 */
#define HW_EPXP_PS_OFFSET_ADDR      (REGS_EPXP_BASE + 0x120)
#define HW_EPXP_PS_OFFSET_SET_ADDR  (HW_EPXP_PS_OFFSET_ADDR + 0x4)
#define HW_EPXP_PS_OFFSET_CLR_ADDR  (HW_EPXP_PS_OFFSET_ADDR + 0x8)
#define HW_EPXP_PS_OFFSET_TOG_ADDR  (HW_EPXP_PS_OFFSET_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_OFFSET           (*(volatile hw_epxp_ps_offset_t *) HW_EPXP_PS_OFFSET_ADDR)
#define HW_EPXP_PS_OFFSET_RD()      (HW_EPXP_PS_OFFSET.U)
#define HW_EPXP_PS_OFFSET_WR(v)     (HW_EPXP_PS_OFFSET.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_OFFSET_SET_ADDR) = (v))
#define HW_EPXP_PS_OFFSET_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_OFFSET_CLR_ADDR) = (v))
#define HW_EPXP_PS_OFFSET_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_OFFSET_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_OFFSET bitfields
 */

/* --- Register HW_EPXP_PS_OFFSET, field XOFFSET[11:0] (RW)
 *
 * This is a 12 bit fractional representation (0.####_####_####) of the X scaling offset. This
 * represents a fixed pixel offset which gets added to the scaled address to determine source data
 * for the scaling engine.
 */

#define BP_EPXP_PS_OFFSET_XOFFSET      (0)
#define BM_EPXP_PS_OFFSET_XOFFSET      (0x00000fff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_OFFSET_XOFFSET(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_OFFSET_XOFFSET)
#else
#define BF_EPXP_PS_OFFSET_XOFFSET(v)   (((v) << 0) & BM_EPXP_PS_OFFSET_XOFFSET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the XOFFSET field to a new value.
#define BW_EPXP_PS_OFFSET_XOFFSET(v)   BF_CS1(EPXP_PS_OFFSET, XOFFSET, v)
#endif

/* --- Register HW_EPXP_PS_OFFSET, field YOFFSET[27:16] (RW)
 *
 * This is a 12 bit fractional representation (0.####_####_####) of the Y scaling offset. This
 * represents a fixed pixel offset which gets added to the scaled address to determine source data
 * for the scaling engine.
 */

#define BP_EPXP_PS_OFFSET_YOFFSET      (16)
#define BM_EPXP_PS_OFFSET_YOFFSET      (0x0fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_OFFSET_YOFFSET(v)   ((((reg32_t) v) << 16) & BM_EPXP_PS_OFFSET_YOFFSET)
#else
#define BF_EPXP_PS_OFFSET_YOFFSET(v)   (((v) << 16) & BM_EPXP_PS_OFFSET_YOFFSET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the YOFFSET field to a new value.
#define BW_EPXP_PS_OFFSET_YOFFSET(v)   BF_CS1(EPXP_PS_OFFSET, YOFFSET, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_CLRKEYLOW - PS Color Key Low (RW)
 *
 * This register contains the color key low value for the PS buffer.  When processing an image, if
 * the PXP finds a pixel in the PS buffer with a color that falls in the range between
 * PXP_PS_CLRKEYLOW and PXP_PS_CLRKEYHIGH, it will insert the pixel from the AS channel. If the
 * current AS pixel is letterboxed or if the AS also matches its colorkey range, the
 * PXP_PS_BACKGROUND color is passed down the pixel pipeline.   EXAMPLE   // colorkey values between
 * PXP_PS_CLRKEYLOW_WR (0x008000); // medium green and PXP_PS_CLRKEYHIGH_WR(0x00FF00); // light
 * green
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PIXEL : 24; //!< Low range of color key applied to PS buffer. To disable PS colorkeying, set the low colorkey to 0xFFFFFF and the high colorkey to 0x000000.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
    } B;
} hw_epxp_ps_clrkeylow_t;
#endif

/*
 * constants & macros for entire EPXP_PS_CLRKEYLOW register
 */
#define HW_EPXP_PS_CLRKEYLOW_ADDR      (REGS_EPXP_BASE + 0x130)
#define HW_EPXP_PS_CLRKEYLOW_SET_ADDR  (HW_EPXP_PS_CLRKEYLOW_ADDR + 0x4)
#define HW_EPXP_PS_CLRKEYLOW_CLR_ADDR  (HW_EPXP_PS_CLRKEYLOW_ADDR + 0x8)
#define HW_EPXP_PS_CLRKEYLOW_TOG_ADDR  (HW_EPXP_PS_CLRKEYLOW_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_CLRKEYLOW           (*(volatile hw_epxp_ps_clrkeylow_t *) HW_EPXP_PS_CLRKEYLOW_ADDR)
#define HW_EPXP_PS_CLRKEYLOW_RD()      (HW_EPXP_PS_CLRKEYLOW.U)
#define HW_EPXP_PS_CLRKEYLOW_WR(v)     (HW_EPXP_PS_CLRKEYLOW.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CLRKEYLOW_SET_ADDR) = (v))
#define HW_EPXP_PS_CLRKEYLOW_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CLRKEYLOW_CLR_ADDR) = (v))
#define HW_EPXP_PS_CLRKEYLOW_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CLRKEYLOW_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_CLRKEYLOW bitfields
 */

/* --- Register HW_EPXP_PS_CLRKEYLOW, field PIXEL[23:0] (RW)
 *
 * Low range of color key applied to PS buffer. To disable PS colorkeying, set the low colorkey to
 * 0xFFFFFF and the high colorkey to 0x000000.
 */

#define BP_EPXP_PS_CLRKEYLOW_PIXEL      (0)
#define BM_EPXP_PS_CLRKEYLOW_PIXEL      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_CLRKEYLOW_PIXEL(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_CLRKEYLOW_PIXEL)
#else
#define BF_EPXP_PS_CLRKEYLOW_PIXEL(v)   (((v) << 0) & BM_EPXP_PS_CLRKEYLOW_PIXEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXEL field to a new value.
#define BW_EPXP_PS_CLRKEYLOW_PIXEL(v)   BF_CS1(EPXP_PS_CLRKEYLOW, PIXEL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_PS_CLRKEYHIGH - PS Color Key High (RW)
 *
 * This register contains the color key high value for the PS buffer.  When processing an image, if
 * the PXP finds a pixel in the PS buffer with a color that falls in the range between
 * PXP_PS_CLRKEYLOW and PXP_PS_CLRKEYHIGH, it will insert the pixel from the AS channel. If the
 * current AS pixel is letterboxed or if the AS also matches its colorkey range, the
 * PXP_PS_BACKGROUND color is passed down the pixel pipeline.   EXAMPLE   // colorkey values between
 * PXP_PS_CLRKEYLOW_WR (0x008000); // medium green and PXP_PS_CLRKEYHIGH_WR(0x00FF00); // light
 * green
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PIXEL : 24; //!< High range of color key applied to PS buffer. To disable PS colorkeying, set the low colorkey to 0xFFFFFF and the high colorkey to 0x000000.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
    } B;
} hw_epxp_ps_clrkeyhigh_t;
#endif

/*
 * constants & macros for entire EPXP_PS_CLRKEYHIGH register
 */
#define HW_EPXP_PS_CLRKEYHIGH_ADDR      (REGS_EPXP_BASE + 0x140)
#define HW_EPXP_PS_CLRKEYHIGH_SET_ADDR  (HW_EPXP_PS_CLRKEYHIGH_ADDR + 0x4)
#define HW_EPXP_PS_CLRKEYHIGH_CLR_ADDR  (HW_EPXP_PS_CLRKEYHIGH_ADDR + 0x8)
#define HW_EPXP_PS_CLRKEYHIGH_TOG_ADDR  (HW_EPXP_PS_CLRKEYHIGH_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_PS_CLRKEYHIGH           (*(volatile hw_epxp_ps_clrkeyhigh_t *) HW_EPXP_PS_CLRKEYHIGH_ADDR)
#define HW_EPXP_PS_CLRKEYHIGH_RD()      (HW_EPXP_PS_CLRKEYHIGH.U)
#define HW_EPXP_PS_CLRKEYHIGH_WR(v)     (HW_EPXP_PS_CLRKEYHIGH.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CLRKEYHIGH_SET_ADDR) = (v))
#define HW_EPXP_PS_CLRKEYHIGH_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CLRKEYHIGH_CLR_ADDR) = (v))
#define HW_EPXP_PS_CLRKEYHIGH_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_PS_CLRKEYHIGH_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_PS_CLRKEYHIGH bitfields
 */

/* --- Register HW_EPXP_PS_CLRKEYHIGH, field PIXEL[23:0] (RW)
 *
 * High range of color key applied to PS buffer. To disable PS colorkeying, set the low colorkey to
 * 0xFFFFFF and the high colorkey to 0x000000.
 */

#define BP_EPXP_PS_CLRKEYHIGH_PIXEL      (0)
#define BM_EPXP_PS_CLRKEYHIGH_PIXEL      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_PS_CLRKEYHIGH_PIXEL(v)   ((((reg32_t) v) << 0) & BM_EPXP_PS_CLRKEYHIGH_PIXEL)
#else
#define BF_EPXP_PS_CLRKEYHIGH_PIXEL(v)   (((v) << 0) & BM_EPXP_PS_CLRKEYHIGH_PIXEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXEL field to a new value.
#define BW_EPXP_PS_CLRKEYHIGH_PIXEL(v)   BF_CS1(EPXP_PS_CLRKEYHIGH, PIXEL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_AS_CTRL - Alpha Surface Control (RW)
 *
 * This register contains buffer control for the Alpha Surface 0 input buffer.  The Alpha Surface
 * Parameter register provides additional controls for AS.   EXAMPLE   u32 asparam; asparam =
 * BF_PXP_ASPARAM_ENABLE (1); asparam |= BF_PXP_ASPARAM_ALPHA_CTRL(BV_PXP_ASPARAM_ALPHA_CTRL__ROPs);
 * asparam |= BF_PXP_ASPARAM_FORMAT (BV_PXP_ASPARAM_FORMAT__ARGB8888); asparam |= BF_PXP_ASPARAM_ROP
 * (BV_PXP_ASPARAM_ROP__XORAS); PXP_ASPARAM_WR(0,asparam); // enable alpha surface to perform XOR
 * ROP using RGB8888 AS pixel format
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 1; //!< Reserved, always set to zero.
        unsigned ALPHA_CTRL : 2; //!< Determines how the alpha value is constructed for this alpha surface. Indicates that the value in the ALPHA field should be used instead of the alpha values present in the input pixels.
        unsigned ENABLE_COLORKEY : 1; //!< Indicates that colorkey functionality is enabled for this alpha surface. Pixels found in the alpha surface colorkey range will be displayed as transparent (the PS pixel will be used).
        unsigned FORMAT : 4; //!< Indicates the input buffer format for AS.
        unsigned ALPHA : 8; //!< Alpha modifier used when the ALPHA_MULTIPLY or ALPHA_OVERRIDE values are programmed in PXP_AS_CTRL[ALPHA_CTRL]. The output alpha value will either be replaced (ALPHA_OVERRIDE) or scaled (ALPHA_MULTIPLY) when selected.
        unsigned ROP : 4; //!< Indicates a raster operation to perform when enabled. Raster operations are enabled through the ALPHA_CTRL field.
        unsigned ALPHA_INVERT : 1; //!< Setting this bit to logic 0 will not alter the alpha value. A logic 1 will invert the alpha value and apply (1-alpha) for image composition.
        unsigned RESERVED1 : 11; //!< Reserved, always set to zero.
    } B;
} hw_epxp_as_ctrl_t;
#endif

/*
 * constants & macros for entire EPXP_AS_CTRL register
 */
#define HW_EPXP_AS_CTRL_ADDR      (REGS_EPXP_BASE + 0x150)
#define HW_EPXP_AS_CTRL_SET_ADDR  (HW_EPXP_AS_CTRL_ADDR + 0x4)
#define HW_EPXP_AS_CTRL_CLR_ADDR  (HW_EPXP_AS_CTRL_ADDR + 0x8)
#define HW_EPXP_AS_CTRL_TOG_ADDR  (HW_EPXP_AS_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_AS_CTRL           (*(volatile hw_epxp_as_ctrl_t *) HW_EPXP_AS_CTRL_ADDR)
#define HW_EPXP_AS_CTRL_RD()      (HW_EPXP_AS_CTRL.U)
#define HW_EPXP_AS_CTRL_WR(v)     (HW_EPXP_AS_CTRL.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CTRL_SET_ADDR) = (v))
#define HW_EPXP_AS_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CTRL_CLR_ADDR) = (v))
#define HW_EPXP_AS_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_AS_CTRL bitfields
 */

/* --- Register HW_EPXP_AS_CTRL, field ALPHA_CTRL[2:1] (RW)
 *
 * Determines how the alpha value is constructed for this alpha surface. Indicates that the value in
 * the ALPHA field should be used instead of the alpha values present in the input pixels.
 *
 * Values:
 * Embedded = 0x0 - Indicates that the AS pixel alpha value will be used to blend the AS with PS. The ALPHA field is
 *     ignored.
 * Override = 0x1 - Indicates that the value in the ALPHA field should be used instead of the alpha values present in
 *     the input pixels.
 * Multiply = 0x2 - Indicates that the value in the ALPHA field should be used to scale all pixel alpha values. Each
 *     pixel alpha is multiplied by the value in the ALPHA field.
 * ROPs = 0x3 - Enable ROPs. The ROP field indicates an operation to be performed on the alpha surface and PS
 *     pixels.
 */

#define BP_EPXP_AS_CTRL_ALPHA_CTRL      (1)
#define BM_EPXP_AS_CTRL_ALPHA_CTRL      (0x00000006)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_CTRL_ALPHA_CTRL(v)   ((((reg32_t) v) << 1) & BM_EPXP_AS_CTRL_ALPHA_CTRL)
#else
#define BF_EPXP_AS_CTRL_ALPHA_CTRL(v)   (((v) << 1) & BM_EPXP_AS_CTRL_ALPHA_CTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALPHA_CTRL field to a new value.
#define BW_EPXP_AS_CTRL_ALPHA_CTRL(v)   BF_CS1(EPXP_AS_CTRL, ALPHA_CTRL, v)
#endif

#define BV_EPXP_AS_CTRL_ALPHA_CTRL__Embedded (0x0) //!< Indicates that the AS pixel alpha value will be used to blend the AS with PS. The ALPHA field is ignored.
#define BV_EPXP_AS_CTRL_ALPHA_CTRL__Override (0x1) //!< Indicates that the value in the ALPHA field should be used instead of the alpha values present in the input pixels.
#define BV_EPXP_AS_CTRL_ALPHA_CTRL__Multiply (0x2) //!< Indicates that the value in the ALPHA field should be used to scale all pixel alpha values. Each pixel alpha is multiplied by the value in the ALPHA field.
#define BV_EPXP_AS_CTRL_ALPHA_CTRL__ROPs (0x3) //!< Enable ROPs. The ROP field indicates an operation to be performed on the alpha surface and PS pixels.

/* --- Register HW_EPXP_AS_CTRL, field ENABLE_COLORKEY[3:3] (RW)
 *
 * Indicates that colorkey functionality is enabled for this alpha surface. Pixels found in the
 * alpha surface colorkey range will be displayed as transparent (the PS pixel will be used).
 */

#define BP_EPXP_AS_CTRL_ENABLE_COLORKEY      (3)
#define BM_EPXP_AS_CTRL_ENABLE_COLORKEY      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_CTRL_ENABLE_COLORKEY(v)   ((((reg32_t) v) << 3) & BM_EPXP_AS_CTRL_ENABLE_COLORKEY)
#else
#define BF_EPXP_AS_CTRL_ENABLE_COLORKEY(v)   (((v) << 3) & BM_EPXP_AS_CTRL_ENABLE_COLORKEY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_COLORKEY field to a new value.
#define BW_EPXP_AS_CTRL_ENABLE_COLORKEY(v)   BF_CS1(EPXP_AS_CTRL, ENABLE_COLORKEY, v)
#endif

/* --- Register HW_EPXP_AS_CTRL, field FORMAT[7:4] (RW)
 *
 * Indicates the input buffer format for AS.
 *
 * Values:
 * ARGB8888 = 0x0 - 32-bit pixels with alpha
 * RGB888 = 0x4 - 32-bit pixels without alpha (unpacked 24-bit format)
 * ARGB1555 = 0x8 - 16-bit pixels with alpha
 * ARGB4444 = 0x9 - 16-bit pixels with alpha
 * RGB555 = 0xC - 16-bit pixels without alpha
 * RGB444 = 0xD - 16-bit pixels without alpha
 * RGB565 = 0xE - 16-bit pixels without alpha
 */

#define BP_EPXP_AS_CTRL_FORMAT      (4)
#define BM_EPXP_AS_CTRL_FORMAT      (0x000000f0)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_CTRL_FORMAT(v)   ((((reg32_t) v) << 4) & BM_EPXP_AS_CTRL_FORMAT)
#else
#define BF_EPXP_AS_CTRL_FORMAT(v)   (((v) << 4) & BM_EPXP_AS_CTRL_FORMAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FORMAT field to a new value.
#define BW_EPXP_AS_CTRL_FORMAT(v)   BF_CS1(EPXP_AS_CTRL, FORMAT, v)
#endif

#define BV_EPXP_AS_CTRL_FORMAT__ARGB8888 (0x0) //!< 32-bit pixels with alpha
#define BV_EPXP_AS_CTRL_FORMAT__RGB888 (0x4) //!< 32-bit pixels without alpha (unpacked 24-bit format)
#define BV_EPXP_AS_CTRL_FORMAT__ARGB1555 (0x8) //!< 16-bit pixels with alpha
#define BV_EPXP_AS_CTRL_FORMAT__ARGB4444 (0x9) //!< 16-bit pixels with alpha
#define BV_EPXP_AS_CTRL_FORMAT__RGB555 (0xc) //!< 16-bit pixels without alpha
#define BV_EPXP_AS_CTRL_FORMAT__RGB444 (0xd) //!< 16-bit pixels without alpha
#define BV_EPXP_AS_CTRL_FORMAT__RGB565 (0xe) //!< 16-bit pixels without alpha

/* --- Register HW_EPXP_AS_CTRL, field ALPHA[15:8] (RW)
 *
 * Alpha modifier used when the ALPHA_MULTIPLY or ALPHA_OVERRIDE values are programmed in
 * PXP_AS_CTRL[ALPHA_CTRL]. The output alpha value will either be replaced (ALPHA_OVERRIDE) or
 * scaled (ALPHA_MULTIPLY) when selected.
 */

#define BP_EPXP_AS_CTRL_ALPHA      (8)
#define BM_EPXP_AS_CTRL_ALPHA      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_CTRL_ALPHA(v)   ((((reg32_t) v) << 8) & BM_EPXP_AS_CTRL_ALPHA)
#else
#define BF_EPXP_AS_CTRL_ALPHA(v)   (((v) << 8) & BM_EPXP_AS_CTRL_ALPHA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALPHA field to a new value.
#define BW_EPXP_AS_CTRL_ALPHA(v)   BF_CS1(EPXP_AS_CTRL, ALPHA, v)
#endif

/* --- Register HW_EPXP_AS_CTRL, field ROP[19:16] (RW)
 *
 * Indicates a raster operation to perform when enabled. Raster operations are enabled through the
 * ALPHA_CTRL field.
 *
 * Values:
 * MASKAS = 0x0 - AS AND PS
 * MASKNOTAS = 0x1 - nAS AND PS
 * MASKASNOT = 0x2 - AS AND nPS
 * MERGEAS = 0x3 - AS OR PS
 * MERGENOTAS = 0x4 - nAS OR PS
 * MERGEASNOT = 0x5 - AS OR nPS
 * NOTCOPYAS = 0x6 - nAS
 * NOT = 0x7 - nPS
 * NOTMASKAS = 0x8 - AS NAND PS
 * NOTMERGEAS = 0x9 - AS NOR PS
 * XORAS = 0xA - AS XOR PS
 * NOTXORAS = 0xB - AS XNOR PS
 */

#define BP_EPXP_AS_CTRL_ROP      (16)
#define BM_EPXP_AS_CTRL_ROP      (0x000f0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_CTRL_ROP(v)   ((((reg32_t) v) << 16) & BM_EPXP_AS_CTRL_ROP)
#else
#define BF_EPXP_AS_CTRL_ROP(v)   (((v) << 16) & BM_EPXP_AS_CTRL_ROP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROP field to a new value.
#define BW_EPXP_AS_CTRL_ROP(v)   BF_CS1(EPXP_AS_CTRL, ROP, v)
#endif

#define BV_EPXP_AS_CTRL_ROP__MASKAS (0x0) //!< AS AND PS
#define BV_EPXP_AS_CTRL_ROP__MASKNOTAS (0x1) //!< nAS AND PS
#define BV_EPXP_AS_CTRL_ROP__MASKASNOT (0x2) //!< AS AND nPS
#define BV_EPXP_AS_CTRL_ROP__MERGEAS (0x3) //!< AS OR PS
#define BV_EPXP_AS_CTRL_ROP__MERGENOTAS (0x4) //!< nAS OR PS
#define BV_EPXP_AS_CTRL_ROP__MERGEASNOT (0x5) //!< AS OR nPS
#define BV_EPXP_AS_CTRL_ROP__NOTCOPYAS (0x6) //!< nAS
#define BV_EPXP_AS_CTRL_ROP__NOT (0x7) //!< nPS
#define BV_EPXP_AS_CTRL_ROP__NOTMASKAS (0x8) //!< AS NAND PS
#define BV_EPXP_AS_CTRL_ROP__NOTMERGEAS (0x9) //!< AS NOR PS
#define BV_EPXP_AS_CTRL_ROP__XORAS (0xa) //!< AS XOR PS
#define BV_EPXP_AS_CTRL_ROP__NOTXORAS (0xb) //!< AS XNOR PS

/* --- Register HW_EPXP_AS_CTRL, field ALPHA_INVERT[20:20] (RW)
 *
 * Setting this bit to logic 0 will not alter the alpha value. A logic 1 will invert the alpha value
 * and apply (1-alpha) for image composition.
 */

#define BP_EPXP_AS_CTRL_ALPHA_INVERT      (20)
#define BM_EPXP_AS_CTRL_ALPHA_INVERT      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_CTRL_ALPHA_INVERT(v)   ((((reg32_t) v) << 20) & BM_EPXP_AS_CTRL_ALPHA_INVERT)
#else
#define BF_EPXP_AS_CTRL_ALPHA_INVERT(v)   (((v) << 20) & BM_EPXP_AS_CTRL_ALPHA_INVERT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALPHA_INVERT field to a new value.
#define BW_EPXP_AS_CTRL_ALPHA_INVERT(v)   BF_CS1(EPXP_AS_CTRL, ALPHA_INVERT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_AS_BUF - Alpha Surface Buffer Pointer (RW)
 *
 * Alpha Surface 0 Buffer Address Pointer. This register points to the beginning of the Alpha
 * Surface 0 input buffer.  This register is used to indicate the base address of the AS buffer.
 * EXAMPLE   u32* alpha_ptr; PXP_ASn_WR(0,alpha_ptr);
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Address pointer for the alpha surface 0 buffer.
    } B;
} hw_epxp_as_buf_t;
#endif

/*
 * constants & macros for entire EPXP_AS_BUF register
 */
#define HW_EPXP_AS_BUF_ADDR      (REGS_EPXP_BASE + 0x160)
#define HW_EPXP_AS_BUF_SET_ADDR  (HW_EPXP_AS_BUF_ADDR + 0x4)
#define HW_EPXP_AS_BUF_CLR_ADDR  (HW_EPXP_AS_BUF_ADDR + 0x8)
#define HW_EPXP_AS_BUF_TOG_ADDR  (HW_EPXP_AS_BUF_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_AS_BUF           (*(volatile hw_epxp_as_buf_t *) HW_EPXP_AS_BUF_ADDR)
#define HW_EPXP_AS_BUF_RD()      (HW_EPXP_AS_BUF.U)
#define HW_EPXP_AS_BUF_WR(v)     (HW_EPXP_AS_BUF.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_AS_BUF_SET_ADDR) = (v))
#define HW_EPXP_AS_BUF_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_AS_BUF_CLR_ADDR) = (v))
#define HW_EPXP_AS_BUF_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_AS_BUF_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_AS_BUF bitfields
 */

/* --- Register HW_EPXP_AS_BUF, field ADDR[31:0] (RW)
 *
 * Address pointer for the alpha surface 0 buffer.
 */

#define BP_EPXP_AS_BUF_ADDR      (0)
#define BM_EPXP_AS_BUF_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_BUF_ADDR(v)   ((((reg32_t) v) << 0) & BM_EPXP_AS_BUF_ADDR)
#else
#define BF_EPXP_AS_BUF_ADDR(v)   (((v) << 0) & BM_EPXP_AS_BUF_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPXP_AS_BUF_ADDR(v)   BF_CS1(EPXP_AS_BUF, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_AS_PITCH - Alpha Surface Pitch (RW)
 *
 * This register contains the alpha surface pitch in bytes.  Any byte value will indicate the
 * vertical pitch. This value will be used in AS pixel address calculations. This value has no
 * relation to the UL and LR registers. It specifies how many bytes are between two vertically
 * adjacent pixels in the input AS surface.   EXAMPLE   PXP_AS_PITCH_WR( 1920 * 4 ); // The output
 * buffer pitch is HD resolution at 32 bits per pixel
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PITCH : 16; //!< Indicates the number of bytes in memory between two vertically adjacent pixels.
        unsigned RESERVED0 : 16; //!< Reserved, always set to zero.
    } B;
} hw_epxp_as_pitch_t;
#endif

/*
 * constants & macros for entire EPXP_AS_PITCH register
 */
#define HW_EPXP_AS_PITCH_ADDR      (REGS_EPXP_BASE + 0x170)
#define HW_EPXP_AS_PITCH_SET_ADDR  (HW_EPXP_AS_PITCH_ADDR + 0x4)
#define HW_EPXP_AS_PITCH_CLR_ADDR  (HW_EPXP_AS_PITCH_ADDR + 0x8)
#define HW_EPXP_AS_PITCH_TOG_ADDR  (HW_EPXP_AS_PITCH_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_AS_PITCH           (*(volatile hw_epxp_as_pitch_t *) HW_EPXP_AS_PITCH_ADDR)
#define HW_EPXP_AS_PITCH_RD()      (HW_EPXP_AS_PITCH.U)
#define HW_EPXP_AS_PITCH_WR(v)     (HW_EPXP_AS_PITCH.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_AS_PITCH_SET_ADDR) = (v))
#define HW_EPXP_AS_PITCH_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_AS_PITCH_CLR_ADDR) = (v))
#define HW_EPXP_AS_PITCH_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_AS_PITCH_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_AS_PITCH bitfields
 */

/* --- Register HW_EPXP_AS_PITCH, field PITCH[15:0] (RW)
 *
 * Indicates the number of bytes in memory between two vertically adjacent pixels.
 */

#define BP_EPXP_AS_PITCH_PITCH      (0)
#define BM_EPXP_AS_PITCH_PITCH      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_PITCH_PITCH(v)   ((((reg32_t) v) << 0) & BM_EPXP_AS_PITCH_PITCH)
#else
#define BF_EPXP_AS_PITCH_PITCH(v)   (((v) << 0) & BM_EPXP_AS_PITCH_PITCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PITCH field to a new value.
#define BW_EPXP_AS_PITCH_PITCH(v)   BF_CS1(EPXP_AS_PITCH, PITCH, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_AS_CLRKEYLOW - Overlay Color Key Low (RW)
 *
 * This register contains the color key low value for the AS buffer.  When processing an image, the
 * if the PXP finds a pixel in the current overlay image with a color that falls in the range from
 * the ASCOLORKEYLOW to ASCOLORKEYHIGH range, it will use the PS pixel value for that location. If
 * no PS image is present or if the PS image also matches its colorkey range, the PS background
 * color is used. Colorkey operations are higher priority than alpha or ROP operations.   EXAMPLE
 * // colorkey values between PXP_AS_CLRKEYLOW_WR (0x000000); // black and
 * PXP_AS_CLRKEYHIGH_WR(0x800000); // medium red
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PIXEL : 24; //!< Low range of RGB color key applied to AS buffer. Each overlay has an independent colorkey enable.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
    } B;
} hw_epxp_as_clrkeylow_t;
#endif

/*
 * constants & macros for entire EPXP_AS_CLRKEYLOW register
 */
#define HW_EPXP_AS_CLRKEYLOW_ADDR      (REGS_EPXP_BASE + 0x180)
#define HW_EPXP_AS_CLRKEYLOW_SET_ADDR  (HW_EPXP_AS_CLRKEYLOW_ADDR + 0x4)
#define HW_EPXP_AS_CLRKEYLOW_CLR_ADDR  (HW_EPXP_AS_CLRKEYLOW_ADDR + 0x8)
#define HW_EPXP_AS_CLRKEYLOW_TOG_ADDR  (HW_EPXP_AS_CLRKEYLOW_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_AS_CLRKEYLOW           (*(volatile hw_epxp_as_clrkeylow_t *) HW_EPXP_AS_CLRKEYLOW_ADDR)
#define HW_EPXP_AS_CLRKEYLOW_RD()      (HW_EPXP_AS_CLRKEYLOW.U)
#define HW_EPXP_AS_CLRKEYLOW_WR(v)     (HW_EPXP_AS_CLRKEYLOW.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CLRKEYLOW_SET_ADDR) = (v))
#define HW_EPXP_AS_CLRKEYLOW_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CLRKEYLOW_CLR_ADDR) = (v))
#define HW_EPXP_AS_CLRKEYLOW_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CLRKEYLOW_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_AS_CLRKEYLOW bitfields
 */

/* --- Register HW_EPXP_AS_CLRKEYLOW, field PIXEL[23:0] (RW)
 *
 * Low range of RGB color key applied to AS buffer. Each overlay has an independent colorkey enable.
 */

#define BP_EPXP_AS_CLRKEYLOW_PIXEL      (0)
#define BM_EPXP_AS_CLRKEYLOW_PIXEL      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_CLRKEYLOW_PIXEL(v)   ((((reg32_t) v) << 0) & BM_EPXP_AS_CLRKEYLOW_PIXEL)
#else
#define BF_EPXP_AS_CLRKEYLOW_PIXEL(v)   (((v) << 0) & BM_EPXP_AS_CLRKEYLOW_PIXEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXEL field to a new value.
#define BW_EPXP_AS_CLRKEYLOW_PIXEL(v)   BF_CS1(EPXP_AS_CLRKEYLOW, PIXEL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_AS_CLRKEYHIGH - Overlay Color Key High (RW)
 *
 * This register contains the color key high value for the AS buffer.  When processing an image, the
 * if the PXP finds a pixel in the current overlay image with a color that falls in the range from
 * the ASCOLORKEYLOW to ASCOLORKEYHIGH range, it will use the PS pixel value for that location. If
 * no PS image is present or if the PS image also matches its colorkey range, the PS background
 * color is used. Colorkey operations are higher priority than alpha or ROP operations.   EXAMPLE
 * // colorkey values between PXP_AS_CLRKEYLOW_WR (0x000000); // black and
 * PXP_AS_CLRKEYHIGH_WR(0x800000); // medium red
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PIXEL : 24; //!< High range of RGB color key applied to AS buffer. Each overlay has an independent colorkey enable.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
    } B;
} hw_epxp_as_clrkeyhigh_t;
#endif

/*
 * constants & macros for entire EPXP_AS_CLRKEYHIGH register
 */
#define HW_EPXP_AS_CLRKEYHIGH_ADDR      (REGS_EPXP_BASE + 0x190)
#define HW_EPXP_AS_CLRKEYHIGH_SET_ADDR  (HW_EPXP_AS_CLRKEYHIGH_ADDR + 0x4)
#define HW_EPXP_AS_CLRKEYHIGH_CLR_ADDR  (HW_EPXP_AS_CLRKEYHIGH_ADDR + 0x8)
#define HW_EPXP_AS_CLRKEYHIGH_TOG_ADDR  (HW_EPXP_AS_CLRKEYHIGH_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_AS_CLRKEYHIGH           (*(volatile hw_epxp_as_clrkeyhigh_t *) HW_EPXP_AS_CLRKEYHIGH_ADDR)
#define HW_EPXP_AS_CLRKEYHIGH_RD()      (HW_EPXP_AS_CLRKEYHIGH.U)
#define HW_EPXP_AS_CLRKEYHIGH_WR(v)     (HW_EPXP_AS_CLRKEYHIGH.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CLRKEYHIGH_SET_ADDR) = (v))
#define HW_EPXP_AS_CLRKEYHIGH_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CLRKEYHIGH_CLR_ADDR) = (v))
#define HW_EPXP_AS_CLRKEYHIGH_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_AS_CLRKEYHIGH_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_AS_CLRKEYHIGH bitfields
 */

/* --- Register HW_EPXP_AS_CLRKEYHIGH, field PIXEL[23:0] (RW)
 *
 * High range of RGB color key applied to AS buffer. Each overlay has an independent colorkey
 * enable.
 */

#define BP_EPXP_AS_CLRKEYHIGH_PIXEL      (0)
#define BM_EPXP_AS_CLRKEYHIGH_PIXEL      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_AS_CLRKEYHIGH_PIXEL(v)   ((((reg32_t) v) << 0) & BM_EPXP_AS_CLRKEYHIGH_PIXEL)
#else
#define BF_EPXP_AS_CLRKEYHIGH_PIXEL(v)   (((v) << 0) & BM_EPXP_AS_CLRKEYHIGH_PIXEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXEL field to a new value.
#define BW_EPXP_AS_CLRKEYHIGH_PIXEL(v)   BF_CS1(EPXP_AS_CLRKEYHIGH, PIXEL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC1_COEF0 - Color Space Conversion Coefficient Register 0 (RW)
 *
 * This register contains color space conversion coefficients in two's compliment notation.  The
 * coefficient 0 register contains coefficients used in the color space conversion algorithm. The Y
 * and UV offsets are added to the source buffer to normalize them before the conversion. C0 is the
 * coefficient that is used to multiply the luma component of the data for all three RGB components.
 * EXAMPLE   // The equations used for Colorspace conversion are: // R = C0*(Y+YOFFSET) +
 * C1(V+UV_OFFSET) // G = C0*(Y+YOFFSET) + C3(U+UV_OFFSET) + C2(V+UV_OFFSET) // R = C0*(Y+YOFFSET) +
 * C4(U+UV_OFFSET) PXP_CSCCOEF0_WR(0x04030000); // YUV coefficients: C0, Yoffset, UVoffset
 * PXP_CSCCOEF1_WR(0x01230208); // YUV coefficients: C1, C4 PXP_CSCCOEF2_WR(0x076B079b); // YUV
 * coefficients: C2, C3
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned Y_OFFSET : 9; //!< Two's compliment amplitude offset implicit in the Y data. For YUV, this is typically 0 and for YCbCr, this is typically -16 (0x1F0)
        unsigned UV_OFFSET : 9; //!< Two's compliment phase offset implicit for CbCr data. Generally used for YCbCr to RGB conversion. YCbCr=0x180, YUV=0x000 (typically -128 or 0x180 to indicate normalized -0.5 to 0.5 range)
        unsigned C0 : 11; //!< Two's compliment Y multiplier coefficient. YUV=0x100 (1.000) YCbCr=0x12A (1.164)
        unsigned RESERVED0 : 1; //!< Reserved, always set to zero.
        unsigned BYPASS : 1; //!< Bypass the CSC unit in the scaling engine. When set to logic 1, bypass is enabled and the output pixels will be in the YUV/YCbCr color space. When set to logic 0, the CSC unit is enabled and the pixels will be converted based on the programmed coefficients.
        unsigned YCBCR_MODE : 1; //!< Set to 1 when performing YCbCr conversion to RGB. Set to 0 when converting YUV to RGB data. This bit changes the behavior of the scaler when performing U/V scaling.
    } B;
} hw_epxp_csc1_coef0_t;
#endif

/*
 * constants & macros for entire EPXP_CSC1_COEF0 register
 */
#define HW_EPXP_CSC1_COEF0_ADDR      (REGS_EPXP_BASE + 0x1a0)
#define HW_EPXP_CSC1_COEF0_SET_ADDR  (HW_EPXP_CSC1_COEF0_ADDR + 0x4)
#define HW_EPXP_CSC1_COEF0_CLR_ADDR  (HW_EPXP_CSC1_COEF0_ADDR + 0x8)
#define HW_EPXP_CSC1_COEF0_TOG_ADDR  (HW_EPXP_CSC1_COEF0_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC1_COEF0           (*(volatile hw_epxp_csc1_coef0_t *) HW_EPXP_CSC1_COEF0_ADDR)
#define HW_EPXP_CSC1_COEF0_RD()      (HW_EPXP_CSC1_COEF0.U)
#define HW_EPXP_CSC1_COEF0_WR(v)     (HW_EPXP_CSC1_COEF0.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF0_SET_ADDR) = (v))
#define HW_EPXP_CSC1_COEF0_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF0_CLR_ADDR) = (v))
#define HW_EPXP_CSC1_COEF0_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF0_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC1_COEF0 bitfields
 */

/* --- Register HW_EPXP_CSC1_COEF0, field Y_OFFSET[8:0] (RW)
 *
 * Two's compliment amplitude offset implicit in the Y data. For YUV, this is typically 0 and for
 * YCbCr, this is typically -16 (0x1F0)
 */

#define BP_EPXP_CSC1_COEF0_Y_OFFSET      (0)
#define BM_EPXP_CSC1_COEF0_Y_OFFSET      (0x000001ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF0_Y_OFFSET(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC1_COEF0_Y_OFFSET)
#else
#define BF_EPXP_CSC1_COEF0_Y_OFFSET(v)   (((v) << 0) & BM_EPXP_CSC1_COEF0_Y_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the Y_OFFSET field to a new value.
#define BW_EPXP_CSC1_COEF0_Y_OFFSET(v)   BF_CS1(EPXP_CSC1_COEF0, Y_OFFSET, v)
#endif

/* --- Register HW_EPXP_CSC1_COEF0, field UV_OFFSET[17:9] (RW)
 *
 * Two's compliment phase offset implicit for CbCr data. Generally used for YCbCr to RGB conversion.
 * YCbCr=0x180, YUV=0x000 (typically -128 or 0x180 to indicate normalized -0.5 to 0.5 range)
 */

#define BP_EPXP_CSC1_COEF0_UV_OFFSET      (9)
#define BM_EPXP_CSC1_COEF0_UV_OFFSET      (0x0003fe00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF0_UV_OFFSET(v)   ((((reg32_t) v) << 9) & BM_EPXP_CSC1_COEF0_UV_OFFSET)
#else
#define BF_EPXP_CSC1_COEF0_UV_OFFSET(v)   (((v) << 9) & BM_EPXP_CSC1_COEF0_UV_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UV_OFFSET field to a new value.
#define BW_EPXP_CSC1_COEF0_UV_OFFSET(v)   BF_CS1(EPXP_CSC1_COEF0, UV_OFFSET, v)
#endif

/* --- Register HW_EPXP_CSC1_COEF0, field C0[28:18] (RW)
 *
 * Two's compliment Y multiplier coefficient. YUV=0x100 (1.000) YCbCr=0x12A (1.164)
 */

#define BP_EPXP_CSC1_COEF0_C0      (18)
#define BM_EPXP_CSC1_COEF0_C0      (0x1ffc0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF0_C0(v)   ((((reg32_t) v) << 18) & BM_EPXP_CSC1_COEF0_C0)
#else
#define BF_EPXP_CSC1_COEF0_C0(v)   (((v) << 18) & BM_EPXP_CSC1_COEF0_C0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the C0 field to a new value.
#define BW_EPXP_CSC1_COEF0_C0(v)   BF_CS1(EPXP_CSC1_COEF0, C0, v)
#endif

/* --- Register HW_EPXP_CSC1_COEF0, field BYPASS[30:30] (RW)
 *
 * Bypass the CSC unit in the scaling engine. When set to logic 1, bypass is enabled and the output
 * pixels will be in the YUV/YCbCr color space. When set to logic 0, the CSC unit is enabled and the
 * pixels will be converted based on the programmed coefficients.
 */

#define BP_EPXP_CSC1_COEF0_BYPASS      (30)
#define BM_EPXP_CSC1_COEF0_BYPASS      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF0_BYPASS(v)   ((((reg32_t) v) << 30) & BM_EPXP_CSC1_COEF0_BYPASS)
#else
#define BF_EPXP_CSC1_COEF0_BYPASS(v)   (((v) << 30) & BM_EPXP_CSC1_COEF0_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_EPXP_CSC1_COEF0_BYPASS(v)   BF_CS1(EPXP_CSC1_COEF0, BYPASS, v)
#endif

/* --- Register HW_EPXP_CSC1_COEF0, field YCBCR_MODE[31:31] (RW)
 *
 * Set to 1 when performing YCbCr conversion to RGB. Set to 0 when converting YUV to RGB data. This
 * bit changes the behavior of the scaler when performing U/V scaling.
 */

#define BP_EPXP_CSC1_COEF0_YCBCR_MODE      (31)
#define BM_EPXP_CSC1_COEF0_YCBCR_MODE      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF0_YCBCR_MODE(v)   ((((reg32_t) v) << 31) & BM_EPXP_CSC1_COEF0_YCBCR_MODE)
#else
#define BF_EPXP_CSC1_COEF0_YCBCR_MODE(v)   (((v) << 31) & BM_EPXP_CSC1_COEF0_YCBCR_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the YCBCR_MODE field to a new value.
#define BW_EPXP_CSC1_COEF0_YCBCR_MODE(v)   BF_CS1(EPXP_CSC1_COEF0, YCBCR_MODE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC1_COEF1 - Color Space Conversion Coefficient Register 1 (RW)
 *
 * This register contains color space conversion coefficients in two's compliment notation.  The
 * Coeffient 1 register contains coefficients used in the color space conversion algorithm. C1 is
 * the coefficient that is used to multiply the chroma (Cr/V) component of the data for the red
 * component. C4 is the coefficient that is used to multiply the chroma (Cb/U) component of the data
 * for the blue component. Both values should be coded as a two's compliment fixed point number with
 * 8 bits right of the decimal.   EXAMPLE   PXP_CSCCOEF0_WR(0x04030000); // YUV coefficients: C0,
 * Yoffset, UVoffset PXP_CSCCOEF1_WR(0x01230208); // YUV coefficients: C1, C4
 * PXP_CSCCOEF2_WR(0x076B079b); // YUV coefficients: C2, C3
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned C4 : 11; //!< Two's compliment Blue U/Cb multiplier coefficient. YUV=0x208 (2.032) YCbCr=0x204 (2.017)
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned C1 : 11; //!< Two's compliment Red V/Cr multiplier coefficient. YUV=0x123 (1.140) YCbCr=0x198 (1.596)
        unsigned RESERVED1 : 5; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc1_coef1_t;
#endif

/*
 * constants & macros for entire EPXP_CSC1_COEF1 register
 */
#define HW_EPXP_CSC1_COEF1_ADDR      (REGS_EPXP_BASE + 0x1b0)
#define HW_EPXP_CSC1_COEF1_SET_ADDR  (HW_EPXP_CSC1_COEF1_ADDR + 0x4)
#define HW_EPXP_CSC1_COEF1_CLR_ADDR  (HW_EPXP_CSC1_COEF1_ADDR + 0x8)
#define HW_EPXP_CSC1_COEF1_TOG_ADDR  (HW_EPXP_CSC1_COEF1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC1_COEF1           (*(volatile hw_epxp_csc1_coef1_t *) HW_EPXP_CSC1_COEF1_ADDR)
#define HW_EPXP_CSC1_COEF1_RD()      (HW_EPXP_CSC1_COEF1.U)
#define HW_EPXP_CSC1_COEF1_WR(v)     (HW_EPXP_CSC1_COEF1.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF1_SET_ADDR) = (v))
#define HW_EPXP_CSC1_COEF1_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF1_CLR_ADDR) = (v))
#define HW_EPXP_CSC1_COEF1_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF1_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC1_COEF1 bitfields
 */

/* --- Register HW_EPXP_CSC1_COEF1, field C4[10:0] (RW)
 *
 * Two's compliment Blue U/Cb multiplier coefficient. YUV=0x208 (2.032) YCbCr=0x204 (2.017)
 */

#define BP_EPXP_CSC1_COEF1_C4      (0)
#define BM_EPXP_CSC1_COEF1_C4      (0x000007ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF1_C4(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC1_COEF1_C4)
#else
#define BF_EPXP_CSC1_COEF1_C4(v)   (((v) << 0) & BM_EPXP_CSC1_COEF1_C4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the C4 field to a new value.
#define BW_EPXP_CSC1_COEF1_C4(v)   BF_CS1(EPXP_CSC1_COEF1, C4, v)
#endif

/* --- Register HW_EPXP_CSC1_COEF1, field C1[26:16] (RW)
 *
 * Two's compliment Red V/Cr multiplier coefficient. YUV=0x123 (1.140) YCbCr=0x198 (1.596)
 */

#define BP_EPXP_CSC1_COEF1_C1      (16)
#define BM_EPXP_CSC1_COEF1_C1      (0x07ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF1_C1(v)   ((((reg32_t) v) << 16) & BM_EPXP_CSC1_COEF1_C1)
#else
#define BF_EPXP_CSC1_COEF1_C1(v)   (((v) << 16) & BM_EPXP_CSC1_COEF1_C1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the C1 field to a new value.
#define BW_EPXP_CSC1_COEF1_C1(v)   BF_CS1(EPXP_CSC1_COEF1, C1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC1_COEF2 - Color Space Conversion Coefficient Register 2 (RW)
 *
 * This register contains color space conversion coefficients in two's compliment notation.  The
 * Coefficient 2 register contains coefficients used in the color space conversion algorithm. C2 is
 * the coefficient that is used to multiply the chroma (Cr/V) component of the data for the green
 * component. C3 is the coefficient that is used to multiply the chroma (Cb/U) component of the data
 * for the green component. Both values should be coded as a two's compliment fixed point number
 * with 8 bits right of the decimal.   EXAMPLE   // NOTE: The default values for the CSCCOEF2
 * register are incorrect. C2 should be 0x76B and C3 should be 0x79C for proper operation.
 * PXP_CSCCOEF0_WR(0x04030000); // YUV coefficients: C0, Yoffset, UVoffset
 * PXP_CSCCOEF1_WR(0x01230208); // YUV coefficients: C1, C4 PXP_CSCCOEF2_WR(0x076B079b); // YUV
 * coefficients: C2, C3
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned C3 : 11; //!< Two's complement Green U/Cb multiplier coefficient. YUV=0x79C (-0.394) YCbCr=0x79C (-0.392)
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned C2 : 11; //!< Two's complement Green V/Cr multiplier coefficient. YUV=0x76B (-0.581) YCbCr=0x730 (-0.813)
        unsigned RESERVED1 : 5; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc1_coef2_t;
#endif

/*
 * constants & macros for entire EPXP_CSC1_COEF2 register
 */
#define HW_EPXP_CSC1_COEF2_ADDR      (REGS_EPXP_BASE + 0x1c0)
#define HW_EPXP_CSC1_COEF2_SET_ADDR  (HW_EPXP_CSC1_COEF2_ADDR + 0x4)
#define HW_EPXP_CSC1_COEF2_CLR_ADDR  (HW_EPXP_CSC1_COEF2_ADDR + 0x8)
#define HW_EPXP_CSC1_COEF2_TOG_ADDR  (HW_EPXP_CSC1_COEF2_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC1_COEF2           (*(volatile hw_epxp_csc1_coef2_t *) HW_EPXP_CSC1_COEF2_ADDR)
#define HW_EPXP_CSC1_COEF2_RD()      (HW_EPXP_CSC1_COEF2.U)
#define HW_EPXP_CSC1_COEF2_WR(v)     (HW_EPXP_CSC1_COEF2.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF2_SET_ADDR) = (v))
#define HW_EPXP_CSC1_COEF2_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF2_CLR_ADDR) = (v))
#define HW_EPXP_CSC1_COEF2_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC1_COEF2_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC1_COEF2 bitfields
 */

/* --- Register HW_EPXP_CSC1_COEF2, field C3[10:0] (RW)
 *
 * Two's complement Green U/Cb multiplier coefficient. YUV=0x79C (-0.394) YCbCr=0x79C (-0.392)
 */

#define BP_EPXP_CSC1_COEF2_C3      (0)
#define BM_EPXP_CSC1_COEF2_C3      (0x000007ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF2_C3(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC1_COEF2_C3)
#else
#define BF_EPXP_CSC1_COEF2_C3(v)   (((v) << 0) & BM_EPXP_CSC1_COEF2_C3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the C3 field to a new value.
#define BW_EPXP_CSC1_COEF2_C3(v)   BF_CS1(EPXP_CSC1_COEF2, C3, v)
#endif

/* --- Register HW_EPXP_CSC1_COEF2, field C2[26:16] (RW)
 *
 * Two's complement Green V/Cr multiplier coefficient. YUV=0x76B (-0.581) YCbCr=0x730 (-0.813)
 */

#define BP_EPXP_CSC1_COEF2_C2      (16)
#define BM_EPXP_CSC1_COEF2_C2      (0x07ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC1_COEF2_C2(v)   ((((reg32_t) v) << 16) & BM_EPXP_CSC1_COEF2_C2)
#else
#define BF_EPXP_CSC1_COEF2_C2(v)   (((v) << 16) & BM_EPXP_CSC1_COEF2_C2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the C2 field to a new value.
#define BW_EPXP_CSC1_COEF2_C2(v)   BF_CS1(EPXP_CSC1_COEF2, C2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC2_CTRL - Color Space Conversion Control Register. (RW)
 *
 * This register contains the control registers to configure the CSC module.  The CSC control
 * register will configure the CSC module to perform color space conversion between the
 * RGB/YUV/YCbCr color spaces.   EXAMPLE   //Converting from YUV/YCbCr color spaces to the RGB color
 * space uses the //following equation structure: // // R = A1(Y-D1) + A2(U-D2) + A3(V-D3) // G =
 * B1(Y-D1) + B2(U-D2) + B3(V-D3) // B = C1(Y-D1) + C2(U-D2) + C3(V-D3) // //Converting from the RGB
 * color space to YUV/YCbCr color spaces uses the //following equation structure: // // Y = A1*R +
 * A2*G + A3*B + D1 // U = B1*R + B2*G + B3*B + D2 // V = C1*R + C2*G + C3*B + D3 // //All math is
 * signed, so all coefficients come in as two's comp numbers //
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BYPASS : 1; //!< This bit controls whether the pixels entering the CSC2 unit get converted or not. When BYPASS is set, no operations occur on the pixels. When BYPASS is cleared, the selected CSC operation takes place.
        unsigned CSC_MODE : 2; //!< This field controls how the CSC unit operates on pixels when the CSC is not bypassed.
        unsigned RESERVED0 : 29; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc2_ctrl_t;
#endif

/*
 * constants & macros for entire EPXP_CSC2_CTRL register
 */
#define HW_EPXP_CSC2_CTRL_ADDR      (REGS_EPXP_BASE + 0x1d0)
#define HW_EPXP_CSC2_CTRL_SET_ADDR  (HW_EPXP_CSC2_CTRL_ADDR + 0x4)
#define HW_EPXP_CSC2_CTRL_CLR_ADDR  (HW_EPXP_CSC2_CTRL_ADDR + 0x8)
#define HW_EPXP_CSC2_CTRL_TOG_ADDR  (HW_EPXP_CSC2_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC2_CTRL           (*(volatile hw_epxp_csc2_ctrl_t *) HW_EPXP_CSC2_CTRL_ADDR)
#define HW_EPXP_CSC2_CTRL_RD()      (HW_EPXP_CSC2_CTRL.U)
#define HW_EPXP_CSC2_CTRL_WR(v)     (HW_EPXP_CSC2_CTRL.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_CTRL_SET_ADDR) = (v))
#define HW_EPXP_CSC2_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_CTRL_CLR_ADDR) = (v))
#define HW_EPXP_CSC2_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC2_CTRL bitfields
 */

/* --- Register HW_EPXP_CSC2_CTRL, field BYPASS[0:0] (RW)
 *
 * This bit controls whether the pixels entering the CSC2 unit get converted or not. When BYPASS is
 * set, no operations occur on the pixels. When BYPASS is cleared, the selected CSC operation takes
 * place.
 */

#define BP_EPXP_CSC2_CTRL_BYPASS      (0)
#define BM_EPXP_CSC2_CTRL_BYPASS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_CTRL_BYPASS(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC2_CTRL_BYPASS)
#else
#define BF_EPXP_CSC2_CTRL_BYPASS(v)   (((v) << 0) & BM_EPXP_CSC2_CTRL_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_EPXP_CSC2_CTRL_BYPASS(v)   BF_CS1(EPXP_CSC2_CTRL, BYPASS, v)
#endif

/* --- Register HW_EPXP_CSC2_CTRL, field CSC_MODE[2:1] (RW)
 *
 * This field controls how the CSC unit operates on pixels when the CSC is not bypassed.
 *
 * Values:
 * YUV2RGB = 0x0 - Convert from YUV to RGB.
 * YCbCr2RGB = 0x1 - Convert from YCbCr to RGB.
 * RGB2YUV = 0x2 - Convert from RGB to YUV.
 * RGB2YCbCr = 0x3 - Convert from RGB to YCbCr.
 */

#define BP_EPXP_CSC2_CTRL_CSC_MODE      (1)
#define BM_EPXP_CSC2_CTRL_CSC_MODE      (0x00000006)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_CTRL_CSC_MODE(v)   ((((reg32_t) v) << 1) & BM_EPXP_CSC2_CTRL_CSC_MODE)
#else
#define BF_EPXP_CSC2_CTRL_CSC_MODE(v)   (((v) << 1) & BM_EPXP_CSC2_CTRL_CSC_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_MODE field to a new value.
#define BW_EPXP_CSC2_CTRL_CSC_MODE(v)   BF_CS1(EPXP_CSC2_CTRL, CSC_MODE, v)
#endif

#define BV_EPXP_CSC2_CTRL_CSC_MODE__YUV2RGB (0x0) //!< Convert from YUV to RGB.
#define BV_EPXP_CSC2_CTRL_CSC_MODE__YCbCr2RGB (0x1) //!< Convert from YCbCr to RGB.
#define BV_EPXP_CSC2_CTRL_CSC_MODE__RGB2YUV (0x2) //!< Convert from RGB to YUV.
#define BV_EPXP_CSC2_CTRL_CSC_MODE__RGB2YCbCr (0x3) //!< Convert from RGB to YCbCr.

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC2_COEF0 - Color Space Conversion Coefficient Register 0 (RW)
 *
 * This register contains color space conversion coefficients in two's complement notation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned A1 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned A2 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED1 : 5; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc2_coef0_t;
#endif

/*
 * constants & macros for entire EPXP_CSC2_COEF0 register
 */
#define HW_EPXP_CSC2_COEF0_ADDR      (REGS_EPXP_BASE + 0x1e0)
#define HW_EPXP_CSC2_COEF0_SET_ADDR  (HW_EPXP_CSC2_COEF0_ADDR + 0x4)
#define HW_EPXP_CSC2_COEF0_CLR_ADDR  (HW_EPXP_CSC2_COEF0_ADDR + 0x8)
#define HW_EPXP_CSC2_COEF0_TOG_ADDR  (HW_EPXP_CSC2_COEF0_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC2_COEF0           (*(volatile hw_epxp_csc2_coef0_t *) HW_EPXP_CSC2_COEF0_ADDR)
#define HW_EPXP_CSC2_COEF0_RD()      (HW_EPXP_CSC2_COEF0.U)
#define HW_EPXP_CSC2_COEF0_WR(v)     (HW_EPXP_CSC2_COEF0.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF0_SET_ADDR) = (v))
#define HW_EPXP_CSC2_COEF0_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF0_CLR_ADDR) = (v))
#define HW_EPXP_CSC2_COEF0_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF0_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC2_COEF0 bitfields
 */

/* --- Register HW_EPXP_CSC2_COEF0, field A1[10:0] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF0_A1      (0)
#define BM_EPXP_CSC2_COEF0_A1      (0x000007ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF0_A1(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC2_COEF0_A1)
#else
#define BF_EPXP_CSC2_COEF0_A1(v)   (((v) << 0) & BM_EPXP_CSC2_COEF0_A1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the A1 field to a new value.
#define BW_EPXP_CSC2_COEF0_A1(v)   BF_CS1(EPXP_CSC2_COEF0, A1, v)
#endif

/* --- Register HW_EPXP_CSC2_COEF0, field A2[26:16] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF0_A2      (16)
#define BM_EPXP_CSC2_COEF0_A2      (0x07ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF0_A2(v)   ((((reg32_t) v) << 16) & BM_EPXP_CSC2_COEF0_A2)
#else
#define BF_EPXP_CSC2_COEF0_A2(v)   (((v) << 16) & BM_EPXP_CSC2_COEF0_A2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the A2 field to a new value.
#define BW_EPXP_CSC2_COEF0_A2(v)   BF_CS1(EPXP_CSC2_COEF0, A2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC2_COEF1 - Color Space Conversion Coefficient Register 1 (RW)
 *
 * This register contains color space conversion coefficients in two's complement notation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned A3 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned B1 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED1 : 5; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc2_coef1_t;
#endif

/*
 * constants & macros for entire EPXP_CSC2_COEF1 register
 */
#define HW_EPXP_CSC2_COEF1_ADDR      (REGS_EPXP_BASE + 0x1f0)
#define HW_EPXP_CSC2_COEF1_SET_ADDR  (HW_EPXP_CSC2_COEF1_ADDR + 0x4)
#define HW_EPXP_CSC2_COEF1_CLR_ADDR  (HW_EPXP_CSC2_COEF1_ADDR + 0x8)
#define HW_EPXP_CSC2_COEF1_TOG_ADDR  (HW_EPXP_CSC2_COEF1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC2_COEF1           (*(volatile hw_epxp_csc2_coef1_t *) HW_EPXP_CSC2_COEF1_ADDR)
#define HW_EPXP_CSC2_COEF1_RD()      (HW_EPXP_CSC2_COEF1.U)
#define HW_EPXP_CSC2_COEF1_WR(v)     (HW_EPXP_CSC2_COEF1.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF1_SET_ADDR) = (v))
#define HW_EPXP_CSC2_COEF1_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF1_CLR_ADDR) = (v))
#define HW_EPXP_CSC2_COEF1_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF1_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC2_COEF1 bitfields
 */

/* --- Register HW_EPXP_CSC2_COEF1, field A3[10:0] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF1_A3      (0)
#define BM_EPXP_CSC2_COEF1_A3      (0x000007ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF1_A3(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC2_COEF1_A3)
#else
#define BF_EPXP_CSC2_COEF1_A3(v)   (((v) << 0) & BM_EPXP_CSC2_COEF1_A3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the A3 field to a new value.
#define BW_EPXP_CSC2_COEF1_A3(v)   BF_CS1(EPXP_CSC2_COEF1, A3, v)
#endif

/* --- Register HW_EPXP_CSC2_COEF1, field B1[26:16] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF1_B1      (16)
#define BM_EPXP_CSC2_COEF1_B1      (0x07ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF1_B1(v)   ((((reg32_t) v) << 16) & BM_EPXP_CSC2_COEF1_B1)
#else
#define BF_EPXP_CSC2_COEF1_B1(v)   (((v) << 16) & BM_EPXP_CSC2_COEF1_B1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the B1 field to a new value.
#define BW_EPXP_CSC2_COEF1_B1(v)   BF_CS1(EPXP_CSC2_COEF1, B1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC2_COEF2 - Color Space Conversion Coefficient Register 2 (RW)
 *
 * This register contains color space conversion coefficients in two's complement notation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned B2 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned B3 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED1 : 5; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc2_coef2_t;
#endif

/*
 * constants & macros for entire EPXP_CSC2_COEF2 register
 */
#define HW_EPXP_CSC2_COEF2_ADDR      (REGS_EPXP_BASE + 0x200)
#define HW_EPXP_CSC2_COEF2_SET_ADDR  (HW_EPXP_CSC2_COEF2_ADDR + 0x4)
#define HW_EPXP_CSC2_COEF2_CLR_ADDR  (HW_EPXP_CSC2_COEF2_ADDR + 0x8)
#define HW_EPXP_CSC2_COEF2_TOG_ADDR  (HW_EPXP_CSC2_COEF2_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC2_COEF2           (*(volatile hw_epxp_csc2_coef2_t *) HW_EPXP_CSC2_COEF2_ADDR)
#define HW_EPXP_CSC2_COEF2_RD()      (HW_EPXP_CSC2_COEF2.U)
#define HW_EPXP_CSC2_COEF2_WR(v)     (HW_EPXP_CSC2_COEF2.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF2_SET_ADDR) = (v))
#define HW_EPXP_CSC2_COEF2_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF2_CLR_ADDR) = (v))
#define HW_EPXP_CSC2_COEF2_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF2_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC2_COEF2 bitfields
 */

/* --- Register HW_EPXP_CSC2_COEF2, field B2[10:0] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF2_B2      (0)
#define BM_EPXP_CSC2_COEF2_B2      (0x000007ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF2_B2(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC2_COEF2_B2)
#else
#define BF_EPXP_CSC2_COEF2_B2(v)   (((v) << 0) & BM_EPXP_CSC2_COEF2_B2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the B2 field to a new value.
#define BW_EPXP_CSC2_COEF2_B2(v)   BF_CS1(EPXP_CSC2_COEF2, B2, v)
#endif

/* --- Register HW_EPXP_CSC2_COEF2, field B3[26:16] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF2_B3      (16)
#define BM_EPXP_CSC2_COEF2_B3      (0x07ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF2_B3(v)   ((((reg32_t) v) << 16) & BM_EPXP_CSC2_COEF2_B3)
#else
#define BF_EPXP_CSC2_COEF2_B3(v)   (((v) << 16) & BM_EPXP_CSC2_COEF2_B3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the B3 field to a new value.
#define BW_EPXP_CSC2_COEF2_B3(v)   BF_CS1(EPXP_CSC2_COEF2, B3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC2_COEF3 - Color Space Conversion Coefficient Register 3 (RW)
 *
 * This register contains color space conversion coefficients in two's complement notation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned C1 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned C2 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED1 : 5; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc2_coef3_t;
#endif

/*
 * constants & macros for entire EPXP_CSC2_COEF3 register
 */
#define HW_EPXP_CSC2_COEF3_ADDR      (REGS_EPXP_BASE + 0x210)
#define HW_EPXP_CSC2_COEF3_SET_ADDR  (HW_EPXP_CSC2_COEF3_ADDR + 0x4)
#define HW_EPXP_CSC2_COEF3_CLR_ADDR  (HW_EPXP_CSC2_COEF3_ADDR + 0x8)
#define HW_EPXP_CSC2_COEF3_TOG_ADDR  (HW_EPXP_CSC2_COEF3_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC2_COEF3           (*(volatile hw_epxp_csc2_coef3_t *) HW_EPXP_CSC2_COEF3_ADDR)
#define HW_EPXP_CSC2_COEF3_RD()      (HW_EPXP_CSC2_COEF3.U)
#define HW_EPXP_CSC2_COEF3_WR(v)     (HW_EPXP_CSC2_COEF3.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF3_SET_ADDR) = (v))
#define HW_EPXP_CSC2_COEF3_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF3_CLR_ADDR) = (v))
#define HW_EPXP_CSC2_COEF3_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF3_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC2_COEF3 bitfields
 */

/* --- Register HW_EPXP_CSC2_COEF3, field C1[10:0] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF3_C1      (0)
#define BM_EPXP_CSC2_COEF3_C1      (0x000007ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF3_C1(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC2_COEF3_C1)
#else
#define BF_EPXP_CSC2_COEF3_C1(v)   (((v) << 0) & BM_EPXP_CSC2_COEF3_C1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the C1 field to a new value.
#define BW_EPXP_CSC2_COEF3_C1(v)   BF_CS1(EPXP_CSC2_COEF3, C1, v)
#endif

/* --- Register HW_EPXP_CSC2_COEF3, field C2[26:16] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF3_C2      (16)
#define BM_EPXP_CSC2_COEF3_C2      (0x07ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF3_C2(v)   ((((reg32_t) v) << 16) & BM_EPXP_CSC2_COEF3_C2)
#else
#define BF_EPXP_CSC2_COEF3_C2(v)   (((v) << 16) & BM_EPXP_CSC2_COEF3_C2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the C2 field to a new value.
#define BW_EPXP_CSC2_COEF3_C2(v)   BF_CS1(EPXP_CSC2_COEF3, C2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC2_COEF4 - Color Space Conversion Coefficient Register 4 (RW)
 *
 * This register contains color space conversion coefficients in two's complement notation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned C3 : 11; //!< Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits of fraction as ###.####_####.
        unsigned RESERVED0 : 5; //!< Reserved, always set to zero.
        unsigned D1 : 9; //!< Two's complement coefficient integer offset to be added.
        unsigned RESERVED1 : 7; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc2_coef4_t;
#endif

/*
 * constants & macros for entire EPXP_CSC2_COEF4 register
 */
#define HW_EPXP_CSC2_COEF4_ADDR      (REGS_EPXP_BASE + 0x220)
#define HW_EPXP_CSC2_COEF4_SET_ADDR  (HW_EPXP_CSC2_COEF4_ADDR + 0x4)
#define HW_EPXP_CSC2_COEF4_CLR_ADDR  (HW_EPXP_CSC2_COEF4_ADDR + 0x8)
#define HW_EPXP_CSC2_COEF4_TOG_ADDR  (HW_EPXP_CSC2_COEF4_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC2_COEF4           (*(volatile hw_epxp_csc2_coef4_t *) HW_EPXP_CSC2_COEF4_ADDR)
#define HW_EPXP_CSC2_COEF4_RD()      (HW_EPXP_CSC2_COEF4.U)
#define HW_EPXP_CSC2_COEF4_WR(v)     (HW_EPXP_CSC2_COEF4.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF4_SET_ADDR) = (v))
#define HW_EPXP_CSC2_COEF4_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF4_CLR_ADDR) = (v))
#define HW_EPXP_CSC2_COEF4_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF4_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC2_COEF4 bitfields
 */

/* --- Register HW_EPXP_CSC2_COEF4, field C3[10:0] (RW)
 *
 * Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8 bits
 * of fraction as ###.####_####.
 */

#define BP_EPXP_CSC2_COEF4_C3      (0)
#define BM_EPXP_CSC2_COEF4_C3      (0x000007ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF4_C3(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC2_COEF4_C3)
#else
#define BF_EPXP_CSC2_COEF4_C3(v)   (((v) << 0) & BM_EPXP_CSC2_COEF4_C3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the C3 field to a new value.
#define BW_EPXP_CSC2_COEF4_C3(v)   BF_CS1(EPXP_CSC2_COEF4, C3, v)
#endif

/* --- Register HW_EPXP_CSC2_COEF4, field D1[24:16] (RW)
 *
 * Two's complement coefficient integer offset to be added.
 */

#define BP_EPXP_CSC2_COEF4_D1      (16)
#define BM_EPXP_CSC2_COEF4_D1      (0x01ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF4_D1(v)   ((((reg32_t) v) << 16) & BM_EPXP_CSC2_COEF4_D1)
#else
#define BF_EPXP_CSC2_COEF4_D1(v)   (((v) << 16) & BM_EPXP_CSC2_COEF4_D1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the D1 field to a new value.
#define BW_EPXP_CSC2_COEF4_D1(v)   BF_CS1(EPXP_CSC2_COEF4, D1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CSC2_COEF5 - Color Space Conversion Coefficient Register 5 (RW)
 *
 * This register contains color space conversion coefficients in two's complement notation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned D2 : 9; //!< Two's complement D1 coefficient integer offset to be added.
        unsigned RESERVED0 : 7; //!< Reserved, always set to zero.
        unsigned D3 : 9; //!< Two's complement coefficient integer offset to be added.
        unsigned RESERVED1 : 7; //!< Reserved, always set to zero.
    } B;
} hw_epxp_csc2_coef5_t;
#endif

/*
 * constants & macros for entire EPXP_CSC2_COEF5 register
 */
#define HW_EPXP_CSC2_COEF5_ADDR      (REGS_EPXP_BASE + 0x230)
#define HW_EPXP_CSC2_COEF5_SET_ADDR  (HW_EPXP_CSC2_COEF5_ADDR + 0x4)
#define HW_EPXP_CSC2_COEF5_CLR_ADDR  (HW_EPXP_CSC2_COEF5_ADDR + 0x8)
#define HW_EPXP_CSC2_COEF5_TOG_ADDR  (HW_EPXP_CSC2_COEF5_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CSC2_COEF5           (*(volatile hw_epxp_csc2_coef5_t *) HW_EPXP_CSC2_COEF5_ADDR)
#define HW_EPXP_CSC2_COEF5_RD()      (HW_EPXP_CSC2_COEF5.U)
#define HW_EPXP_CSC2_COEF5_WR(v)     (HW_EPXP_CSC2_COEF5.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF5_SET_ADDR) = (v))
#define HW_EPXP_CSC2_COEF5_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF5_CLR_ADDR) = (v))
#define HW_EPXP_CSC2_COEF5_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CSC2_COEF5_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CSC2_COEF5 bitfields
 */

/* --- Register HW_EPXP_CSC2_COEF5, field D2[8:0] (RW)
 *
 * Two's complement D1 coefficient integer offset to be added.
 */

#define BP_EPXP_CSC2_COEF5_D2      (0)
#define BM_EPXP_CSC2_COEF5_D2      (0x000001ff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF5_D2(v)   ((((reg32_t) v) << 0) & BM_EPXP_CSC2_COEF5_D2)
#else
#define BF_EPXP_CSC2_COEF5_D2(v)   (((v) << 0) & BM_EPXP_CSC2_COEF5_D2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the D2 field to a new value.
#define BW_EPXP_CSC2_COEF5_D2(v)   BF_CS1(EPXP_CSC2_COEF5, D2, v)
#endif

/* --- Register HW_EPXP_CSC2_COEF5, field D3[24:16] (RW)
 *
 * Two's complement coefficient integer offset to be added.
 */

#define BP_EPXP_CSC2_COEF5_D3      (16)
#define BM_EPXP_CSC2_COEF5_D3      (0x01ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CSC2_COEF5_D3(v)   ((((reg32_t) v) << 16) & BM_EPXP_CSC2_COEF5_D3)
#else
#define BF_EPXP_CSC2_COEF5_D3(v)   (((v) << 16) & BM_EPXP_CSC2_COEF5_D3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the D3 field to a new value.
#define BW_EPXP_CSC2_COEF5_D3(v)   BF_CS1(EPXP_CSC2_COEF5, D3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_LUT_CTRL - Lookup Table Control Register. (RW)
 *
 * This register is used to access/control the Monochrome Lookup table.  The Y8 LUT input mode will
 * take the high order data path byte and transform it using the LUT memory. This is an 8-bit to
 * 8-bit transformation. The two low order bytes bypass the LUT and are not transformed, but
 * bypassed without modification. This option can be used for monochrome gamma correction. The
 * Direct Lookup mode will use the high nibble of each data byte and truncate the low nibble to
 * generate the lookup address, i.e. R[7:0]G[7:0]B[7:0] -> R[7:4]G[7:4]B[7:4]. 4K pixels (12-bit
 * address) with 2 bytes per pixel is supported in this mode. Cached Lookup mode will use the high
 * order bits, R[7:3],G[7:2],B[7:3] or RGB565, to address the cached LUT memory. 64KB LUT tables,
 * using 16KB of internal LUT memory, can be indirectly transformed to 16-bit output pixels (as in
 * RGBW4444/RGB565). This is used for 16bpp gamma correction or EPD color panel support. Cache
 * misses are internally managed by the PXP LUT Cache controller.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DMA_START : 1; //!< Setting this bit will result in the DMA operation to load the PXP LUT memory based on PXP_LUT_ADDR_NUM_BYTES, PXP_LUT_ADDR_ADDR, and PXP_LUT_MEM_ADDR. This bit will automatically reset when set to a logic 1. Note: The LOOKUP_MODE must not be set to CACHE_RGB565 when starting and performing DMA transfers.
        unsigned RESERVED0 : 7; //!< Reserved, always set to zero.
        unsigned INVALID : 1; //!< Invalidate the cache LRU and valid bits. This bit will automatically reset when set to a logic 1.
        unsigned LRU_UPD : 1; //!< Least Recently Used Policy Update Control: 1=> block LRU update for hit after miss. 0=> update LRU for all hits including hit after miss.
        unsigned SEL_8KB : 1; //!< Selects which 8KB bank of memory to use for direct 12bpp lookup modes. Logic 0 indicates first 8KB, logic 1 indicates second 8KB. Two direct LUT arrays can be stored and one can be selected for a given PXP operation.
        unsigned RESERVED1 : 5; //!< Reserved, always set to zero.
        unsigned OUT_MODE : 2; //!< Select the output mode of operation for the LUT resource. There are four bytes [3-0] in the data path at the output of the LUT resource. Byte lane 3 is always bypassed and usually contains an alpha value. The LUT can be programmed to transform bytes 2,1,0 according to the options available in this field.
        unsigned RESERVED2 : 6; //!< Reserved, always set to zero.
        unsigned LOOKUP_MODE : 2; //!< Configure the input address for the 16KB LUT memory. The address into the LUT uses different parts of the pixel data path bytes. The data path is defined as three bytes, conceptually as RGB/YUV/YCbCr[23:0]. Also referred to as R/Y[7:0],G/U[7:0],B/V[7:0]
        unsigned RESERVED3 : 5; //!< Reserved, always set to zero.
        unsigned BYPASS : 1; //!< Setting this bit will bypass the LUT memory resource completely. No pixel transfermations will occur at this stage of the PXP pixel rpocessing pipeline.
    } B;
} hw_epxp_lut_ctrl_t;
#endif

/*
 * constants & macros for entire EPXP_LUT_CTRL register
 */
#define HW_EPXP_LUT_CTRL_ADDR      (REGS_EPXP_BASE + 0x240)
#define HW_EPXP_LUT_CTRL_SET_ADDR  (HW_EPXP_LUT_CTRL_ADDR + 0x4)
#define HW_EPXP_LUT_CTRL_CLR_ADDR  (HW_EPXP_LUT_CTRL_ADDR + 0x8)
#define HW_EPXP_LUT_CTRL_TOG_ADDR  (HW_EPXP_LUT_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_LUT_CTRL           (*(volatile hw_epxp_lut_ctrl_t *) HW_EPXP_LUT_CTRL_ADDR)
#define HW_EPXP_LUT_CTRL_RD()      (HW_EPXP_LUT_CTRL.U)
#define HW_EPXP_LUT_CTRL_WR(v)     (HW_EPXP_LUT_CTRL.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_CTRL_SET_ADDR) = (v))
#define HW_EPXP_LUT_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_CTRL_CLR_ADDR) = (v))
#define HW_EPXP_LUT_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_LUT_CTRL bitfields
 */

/* --- Register HW_EPXP_LUT_CTRL, field DMA_START[0:0] (RW)
 *
 * Setting this bit will result in the DMA operation to load the PXP LUT memory based on
 * PXP_LUT_ADDR_NUM_BYTES, PXP_LUT_ADDR_ADDR, and PXP_LUT_MEM_ADDR. This bit will automatically
 * reset when set to a logic 1. Note: The LOOKUP_MODE must not be set to CACHE_RGB565 when starting
 * and performing DMA transfers.
 */

#define BP_EPXP_LUT_CTRL_DMA_START      (0)
#define BM_EPXP_LUT_CTRL_DMA_START      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_CTRL_DMA_START(v)   ((((reg32_t) v) << 0) & BM_EPXP_LUT_CTRL_DMA_START)
#else
#define BF_EPXP_LUT_CTRL_DMA_START(v)   (((v) << 0) & BM_EPXP_LUT_CTRL_DMA_START)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_START field to a new value.
#define BW_EPXP_LUT_CTRL_DMA_START(v)   BF_CS1(EPXP_LUT_CTRL, DMA_START, v)
#endif

/* --- Register HW_EPXP_LUT_CTRL, field INVALID[8:8] (RW)
 *
 * Invalidate the cache LRU and valid bits. This bit will automatically reset when set to a logic 1.
 */

#define BP_EPXP_LUT_CTRL_INVALID      (8)
#define BM_EPXP_LUT_CTRL_INVALID      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_CTRL_INVALID(v)   ((((reg32_t) v) << 8) & BM_EPXP_LUT_CTRL_INVALID)
#else
#define BF_EPXP_LUT_CTRL_INVALID(v)   (((v) << 8) & BM_EPXP_LUT_CTRL_INVALID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INVALID field to a new value.
#define BW_EPXP_LUT_CTRL_INVALID(v)   BF_CS1(EPXP_LUT_CTRL, INVALID, v)
#endif

/* --- Register HW_EPXP_LUT_CTRL, field LRU_UPD[9:9] (RW)
 *
 * Least Recently Used Policy Update Control: 1=> block LRU update for hit after miss. 0=> update
 * LRU for all hits including hit after miss.
 */

#define BP_EPXP_LUT_CTRL_LRU_UPD      (9)
#define BM_EPXP_LUT_CTRL_LRU_UPD      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_CTRL_LRU_UPD(v)   ((((reg32_t) v) << 9) & BM_EPXP_LUT_CTRL_LRU_UPD)
#else
#define BF_EPXP_LUT_CTRL_LRU_UPD(v)   (((v) << 9) & BM_EPXP_LUT_CTRL_LRU_UPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LRU_UPD field to a new value.
#define BW_EPXP_LUT_CTRL_LRU_UPD(v)   BF_CS1(EPXP_LUT_CTRL, LRU_UPD, v)
#endif

/* --- Register HW_EPXP_LUT_CTRL, field SEL_8KB[10:10] (RW)
 *
 * Selects which 8KB bank of memory to use for direct 12bpp lookup modes. Logic 0 indicates first
 * 8KB, logic 1 indicates second 8KB. Two direct LUT arrays can be stored and one can be selected
 * for a given PXP operation.
 */

#define BP_EPXP_LUT_CTRL_SEL_8KB      (10)
#define BM_EPXP_LUT_CTRL_SEL_8KB      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_CTRL_SEL_8KB(v)   ((((reg32_t) v) << 10) & BM_EPXP_LUT_CTRL_SEL_8KB)
#else
#define BF_EPXP_LUT_CTRL_SEL_8KB(v)   (((v) << 10) & BM_EPXP_LUT_CTRL_SEL_8KB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEL_8KB field to a new value.
#define BW_EPXP_LUT_CTRL_SEL_8KB(v)   BF_CS1(EPXP_LUT_CTRL, SEL_8KB, v)
#endif

/* --- Register HW_EPXP_LUT_CTRL, field OUT_MODE[17:16] (RW)
 *
 * Select the output mode of operation for the LUT resource. There are four bytes [3-0] in the data
 * path at the output of the LUT resource. Byte lane 3 is always bypassed and usually contains an
 * alpha value. The LUT can be programmed to transform bytes 2,1,0 according to the options
 * available in this field.
 *
 * Values:
 * RESERVED = 0x0 - Reserved, not valid when using the LUT to transform pixels.
 * Y8 = 0x1 - R/Y byte lane 2 lookup, bytes 1,0 bypassed.
 * RGBW4444CFA = 0x2 - Byte lane 2 = CFA_Y8, byte lane 1,0 = RGBW4444.
 * RGB888 = 0x3 - RGB565->RGB888 conversion for Gamma correction.
 */

#define BP_EPXP_LUT_CTRL_OUT_MODE      (16)
#define BM_EPXP_LUT_CTRL_OUT_MODE      (0x00030000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_CTRL_OUT_MODE(v)   ((((reg32_t) v) << 16) & BM_EPXP_LUT_CTRL_OUT_MODE)
#else
#define BF_EPXP_LUT_CTRL_OUT_MODE(v)   (((v) << 16) & BM_EPXP_LUT_CTRL_OUT_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OUT_MODE field to a new value.
#define BW_EPXP_LUT_CTRL_OUT_MODE(v)   BF_CS1(EPXP_LUT_CTRL, OUT_MODE, v)
#endif

#define BV_EPXP_LUT_CTRL_OUT_MODE__RESERVED (0x0) //!< Reserved, not valid when using the LUT to transform pixels.
#define BV_EPXP_LUT_CTRL_OUT_MODE__Y8 (0x1) //!< R/Y byte lane 2 lookup, bytes 1,0 bypassed.
#define BV_EPXP_LUT_CTRL_OUT_MODE__RGBW4444CFA (0x2) //!< Byte lane 2 = CFA_Y8, byte lane 1,0 = RGBW4444.
#define BV_EPXP_LUT_CTRL_OUT_MODE__RGB888 (0x3) //!< RGB565->RGB888 conversion for Gamma correction.

/* --- Register HW_EPXP_LUT_CTRL, field LOOKUP_MODE[25:24] (RW)
 *
 * Configure the input address for the 16KB LUT memory. The address into the LUT uses different
 * parts of the pixel data path bytes. The data path is defined as three bytes, conceptually as
 * RGB/YUV/YCbCr[23:0]. Also referred to as R/Y[7:0],G/U[7:0],B/V[7:0]
 *
 * Values:
 * CACHE_RGB565 = 0x0 - LUT ADDR = R[7:3],G[7:2],B[7:3]. Use all 16KB of LUT for indirect cached 128KB lookup.
 * DIRECT_Y8 = 0x1 - LUT ADDR = 16'b0,Y[7:0]. Use only the first 256 bytes of LUT. Only the Y, or third data path byte,
 *     is tranformed.
 * DIRECT_RGB444 = 0x2 - LUT ADDR = R[7:4],G[7:4],B[7:4]. Use one 8KB bank of LUT selected by SEL_8KB.
 * DIRECT_RGB454 = 0x3 - LUT ADDR = R[7:4],G[7:3],B[7:4]. Use all 16KB of LUT.
 */

#define BP_EPXP_LUT_CTRL_LOOKUP_MODE      (24)
#define BM_EPXP_LUT_CTRL_LOOKUP_MODE      (0x03000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_CTRL_LOOKUP_MODE(v)   ((((reg32_t) v) << 24) & BM_EPXP_LUT_CTRL_LOOKUP_MODE)
#else
#define BF_EPXP_LUT_CTRL_LOOKUP_MODE(v)   (((v) << 24) & BM_EPXP_LUT_CTRL_LOOKUP_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOKUP_MODE field to a new value.
#define BW_EPXP_LUT_CTRL_LOOKUP_MODE(v)   BF_CS1(EPXP_LUT_CTRL, LOOKUP_MODE, v)
#endif

#define BV_EPXP_LUT_CTRL_LOOKUP_MODE__CACHE_RGB565 (0x0) //!< LUT ADDR = R[7:3],G[7:2],B[7:3]. Use all 16KB of LUT for indirect cached 128KB lookup.
#define BV_EPXP_LUT_CTRL_LOOKUP_MODE__DIRECT_Y8 (0x1) //!< LUT ADDR = 16'b0,Y[7:0]. Use only the first 256 bytes of LUT. Only the Y, or third data path byte, is tranformed.
#define BV_EPXP_LUT_CTRL_LOOKUP_MODE__DIRECT_RGB444 (0x2) //!< LUT ADDR = R[7:4],G[7:4],B[7:4]. Use one 8KB bank of LUT selected by SEL_8KB.
#define BV_EPXP_LUT_CTRL_LOOKUP_MODE__DIRECT_RGB454 (0x3) //!< LUT ADDR = R[7:4],G[7:3],B[7:4]. Use all 16KB of LUT.

/* --- Register HW_EPXP_LUT_CTRL, field BYPASS[31:31] (RW)
 *
 * Setting this bit will bypass the LUT memory resource completely. No pixel transfermations will
 * occur at this stage of the PXP pixel rpocessing pipeline.
 */

#define BP_EPXP_LUT_CTRL_BYPASS      (31)
#define BM_EPXP_LUT_CTRL_BYPASS      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_CTRL_BYPASS(v)   ((((reg32_t) v) << 31) & BM_EPXP_LUT_CTRL_BYPASS)
#else
#define BF_EPXP_LUT_CTRL_BYPASS(v)   (((v) << 31) & BM_EPXP_LUT_CTRL_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_EPXP_LUT_CTRL_BYPASS(v)   BF_CS1(EPXP_LUT_CTRL, BYPASS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_LUT_ADDR - Lookup Table Control Register. (RW)
 *
 * This register is used to access/control the Monochrome Lookup table.  The Y8 LUT input mode will
 * take the high order data path byte and transform it using the LUT memory. This is an 8-bit to
 * 8-bit transformation. The two low order bytes bypass the LUT and are not transformed, but
 * bypassed without modification. This option can be used for monochrome gamma correction. The
 * Direct Lookup mode will use the high nibble of each data byte and truncate the low nibble to
 * generate the lookup address, i.e. R[7:0]G[7:0]B[7:0] -> R[7:4]G[7:4]B[7:4]. 4K pixels (12-bit
 * address) with 2 bytes per pixel is supported in this mode. Cached Lookup mode will use the high
 * order bits, R[7:3],G[7:2],B[7:3] or RGB565, to address the cached LUT memory. 64KB LUT tables,
 * using 16KB of internal LUT memory, can be indirectly transformed to 16-bit output pixels (as in
 * RGBW4444/RGB565). This is used for 16bpp gamma correction or EPD color panel support. Cache
 * misses are internally managed by the PXP LUT Cache controller.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 14; //!< LUT indexed address pointer. This address into the LUT memory is always four byte aligned for PIO access, and eight byte aligned for DMA access. The least two significant bits are not used to drive the LUT memory array. For PIO LUT access, when the LUT data register is written, the contents of the LUT at the address specified by this address field will be loaded with a 32-bit DWORD. This address pointer will be incremented after the LUT data is written. This will provide recursive writes to the LUT data register to initialize the entire LUT array with recursive writes to the LUT data register. For DMA access, this register indicates the LUT memory address of the 8 byte QWORD to be loaded. When using the NUM_BYTES field to load more than 8 bytes, the register should be programmed with the first LUT memory location to be filled and each load of the LUT memory will increment this address field until NUM_BYTES has been loaded.
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned NUM_BYTES : 15; //!< Indicates the number of bytes to load via a DMA operation. This field must be divisable by 8 and the least significant 3 bits must be 0. The value 8 indicates load 8 bytes from the external address indicated by PXP_LUT_MEM_ADDR to the LUT memory location indicated by PXP_LUT_CTRL_ADDR.
        unsigned RESERVED1 : 1; //!< Reserved, always set to zero.
    } B;
} hw_epxp_lut_addr_t;
#endif

/*
 * constants & macros for entire EPXP_LUT_ADDR register
 */
#define HW_EPXP_LUT_ADDR_ADDR      (REGS_EPXP_BASE + 0x250)
#define HW_EPXP_LUT_ADDR_SET_ADDR  (HW_EPXP_LUT_ADDR_ADDR + 0x4)
#define HW_EPXP_LUT_ADDR_CLR_ADDR  (HW_EPXP_LUT_ADDR_ADDR + 0x8)
#define HW_EPXP_LUT_ADDR_TOG_ADDR  (HW_EPXP_LUT_ADDR_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_LUT_ADDR           (*(volatile hw_epxp_lut_addr_t *) HW_EPXP_LUT_ADDR_ADDR)
#define HW_EPXP_LUT_ADDR_RD()      (HW_EPXP_LUT_ADDR.U)
#define HW_EPXP_LUT_ADDR_WR(v)     (HW_EPXP_LUT_ADDR.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_ADDR_SET_ADDR) = (v))
#define HW_EPXP_LUT_ADDR_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_ADDR_CLR_ADDR) = (v))
#define HW_EPXP_LUT_ADDR_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_ADDR_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_LUT_ADDR bitfields
 */

/* --- Register HW_EPXP_LUT_ADDR, field ADDR[13:0] (RW)
 *
 * LUT indexed address pointer. This address into the LUT memory is always four byte aligned for PIO
 * access, and eight byte aligned for DMA access. The least two significant bits are not used to
 * drive the LUT memory array. For PIO LUT access, when the LUT data register is written, the
 * contents of the LUT at the address specified by this address field will be loaded with a 32-bit
 * DWORD. This address pointer will be incremented after the LUT data is written. This will provide
 * recursive writes to the LUT data register to initialize the entire LUT array with recursive
 * writes to the LUT data register. For DMA access, this register indicates the LUT memory address
 * of the 8 byte QWORD to be loaded. When using the NUM_BYTES field to load more than 8 bytes, the
 * register should be programmed with the first LUT memory location to be filled and each load of
 * the LUT memory will increment this address field until NUM_BYTES has been loaded.
 */

#define BP_EPXP_LUT_ADDR_ADDR      (0)
#define BM_EPXP_LUT_ADDR_ADDR      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_ADDR_ADDR(v)   ((((reg32_t) v) << 0) & BM_EPXP_LUT_ADDR_ADDR)
#else
#define BF_EPXP_LUT_ADDR_ADDR(v)   (((v) << 0) & BM_EPXP_LUT_ADDR_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPXP_LUT_ADDR_ADDR(v)   BF_CS1(EPXP_LUT_ADDR, ADDR, v)
#endif

/* --- Register HW_EPXP_LUT_ADDR, field NUM_BYTES[30:16] (RW)
 *
 * Indicates the number of bytes to load via a DMA operation. This field must be divisable by 8 and
 * the least significant 3 bits must be 0. The value 8 indicates load 8 bytes from the external
 * address indicated by PXP_LUT_MEM_ADDR to the LUT memory location indicated by PXP_LUT_CTRL_ADDR.
 */

#define BP_EPXP_LUT_ADDR_NUM_BYTES      (16)
#define BM_EPXP_LUT_ADDR_NUM_BYTES      (0x7fff0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_ADDR_NUM_BYTES(v)   ((((reg32_t) v) << 16) & BM_EPXP_LUT_ADDR_NUM_BYTES)
#else
#define BF_EPXP_LUT_ADDR_NUM_BYTES(v)   (((v) << 16) & BM_EPXP_LUT_ADDR_NUM_BYTES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM_BYTES field to a new value.
#define BW_EPXP_LUT_ADDR_NUM_BYTES(v)   BF_CS1(EPXP_LUT_ADDR, NUM_BYTES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_LUT_DATA - Lookup Table Data Register. (RW)
 *
 * This register is used to load data into the lookup table.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 32; //!< Writing this field will load 4 bytes, aligned to four byte boundaries, of data indexed by the ADDR field of the PXP_LUT_CTRL register.
    } B;
} hw_epxp_lut_data_t;
#endif

/*
 * constants & macros for entire EPXP_LUT_DATA register
 */
#define HW_EPXP_LUT_DATA_ADDR      (REGS_EPXP_BASE + 0x260)
#define HW_EPXP_LUT_DATA_SET_ADDR  (HW_EPXP_LUT_DATA_ADDR + 0x4)
#define HW_EPXP_LUT_DATA_CLR_ADDR  (HW_EPXP_LUT_DATA_ADDR + 0x8)
#define HW_EPXP_LUT_DATA_TOG_ADDR  (HW_EPXP_LUT_DATA_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_LUT_DATA           (*(volatile hw_epxp_lut_data_t *) HW_EPXP_LUT_DATA_ADDR)
#define HW_EPXP_LUT_DATA_RD()      (HW_EPXP_LUT_DATA.U)
#define HW_EPXP_LUT_DATA_WR(v)     (HW_EPXP_LUT_DATA.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_DATA_SET_ADDR) = (v))
#define HW_EPXP_LUT_DATA_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_DATA_CLR_ADDR) = (v))
#define HW_EPXP_LUT_DATA_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_DATA_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_LUT_DATA bitfields
 */

/* --- Register HW_EPXP_LUT_DATA, field DATA[31:0] (RW)
 *
 * Writing this field will load 4 bytes, aligned to four byte boundaries, of data indexed by the
 * ADDR field of the PXP_LUT_CTRL register.
 */

#define BP_EPXP_LUT_DATA_DATA      (0)
#define BM_EPXP_LUT_DATA_DATA      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_DATA_DATA(v)   ((((reg32_t) v) << 0) & BM_EPXP_LUT_DATA_DATA)
#else
#define BF_EPXP_LUT_DATA_DATA(v)   (((v) << 0) & BM_EPXP_LUT_DATA_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_EPXP_LUT_DATA_DATA(v)   BF_CS1(EPXP_LUT_DATA, DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_LUT_EXTMEM - Lookup Table External Memory Address Register. (RW)
 *
 * For DMA LUT memory loads, this is the base address from which data will be sourced to store into
 * the LUT memory array. For Cached LUT memory pixel transformations, this register will store the
 * base address of the full 64K pixel LUT translation table.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< This register contains the external memory address used for LUT memory operation. For DMA LUT memory loads, this is the base address from which data will be sourced to store into the LUT memory array. For Cached LUT memory pixel transformations, this register will store the base address of the full 64K pixel LUT translation table.
    } B;
} hw_epxp_lut_extmem_t;
#endif

/*
 * constants & macros for entire EPXP_LUT_EXTMEM register
 */
#define HW_EPXP_LUT_EXTMEM_ADDR      (REGS_EPXP_BASE + 0x270)
#define HW_EPXP_LUT_EXTMEM_SET_ADDR  (HW_EPXP_LUT_EXTMEM_ADDR + 0x4)
#define HW_EPXP_LUT_EXTMEM_CLR_ADDR  (HW_EPXP_LUT_EXTMEM_ADDR + 0x8)
#define HW_EPXP_LUT_EXTMEM_TOG_ADDR  (HW_EPXP_LUT_EXTMEM_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_LUT_EXTMEM           (*(volatile hw_epxp_lut_extmem_t *) HW_EPXP_LUT_EXTMEM_ADDR)
#define HW_EPXP_LUT_EXTMEM_RD()      (HW_EPXP_LUT_EXTMEM.U)
#define HW_EPXP_LUT_EXTMEM_WR(v)     (HW_EPXP_LUT_EXTMEM.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_EXTMEM_SET_ADDR) = (v))
#define HW_EPXP_LUT_EXTMEM_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_EXTMEM_CLR_ADDR) = (v))
#define HW_EPXP_LUT_EXTMEM_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_LUT_EXTMEM_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_LUT_EXTMEM bitfields
 */

/* --- Register HW_EPXP_LUT_EXTMEM, field ADDR[31:0] (RW)
 *
 * This register contains the external memory address used for LUT memory operation. For DMA LUT
 * memory loads, this is the base address from which data will be sourced to store into the LUT
 * memory array. For Cached LUT memory pixel transformations, this register will store the base
 * address of the full 64K pixel LUT translation table.
 */

#define BP_EPXP_LUT_EXTMEM_ADDR      (0)
#define BM_EPXP_LUT_EXTMEM_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_LUT_EXTMEM_ADDR(v)   ((((reg32_t) v) << 0) & BM_EPXP_LUT_EXTMEM_ADDR)
#else
#define BF_EPXP_LUT_EXTMEM_ADDR(v)   (((v) << 0) & BM_EPXP_LUT_EXTMEM_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_EPXP_LUT_EXTMEM_ADDR(v)   BF_CS1(EPXP_LUT_EXTMEM, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_CFA - Color Filter Array Register. (RW)
 *
 * There are sixteen 2 bit values in this register each mapping a selected component to the output
 * pixel. The two bit values are defined as 0=>R, 1=>G, 2=>B, and 3=>W. The first byte represents
 * the repetitive pattern of RGBW pixels in the CFA for the first line segment of each processed PXP
 * block. The second byte represents the pattern in the second line segment of the block, and so on.
 * The first byte repeats two times for 8x8 macro block mode, and repeats four times for 16x16 block
 * mode.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 32; //!< This register contains the Color Filter Array pattern for decimation of RGBW4444 16 bit pixels to individual R, G, B, W values. The pattern represents a replicated 4x4 color filter array for the entire output frame buffer.
    } B;
} hw_epxp_cfa_t;
#endif

/*
 * constants & macros for entire EPXP_CFA register
 */
#define HW_EPXP_CFA_ADDR      (REGS_EPXP_BASE + 0x280)
#define HW_EPXP_CFA_SET_ADDR  (HW_EPXP_CFA_ADDR + 0x4)
#define HW_EPXP_CFA_CLR_ADDR  (HW_EPXP_CFA_ADDR + 0x8)
#define HW_EPXP_CFA_TOG_ADDR  (HW_EPXP_CFA_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_CFA           (*(volatile hw_epxp_cfa_t *) HW_EPXP_CFA_ADDR)
#define HW_EPXP_CFA_RD()      (HW_EPXP_CFA.U)
#define HW_EPXP_CFA_WR(v)     (HW_EPXP_CFA.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_CFA_SET_ADDR) = (v))
#define HW_EPXP_CFA_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_CFA_CLR_ADDR) = (v))
#define HW_EPXP_CFA_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_CFA_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_CFA bitfields
 */

/* --- Register HW_EPXP_CFA, field DATA[31:0] (RW)
 *
 * This register contains the Color Filter Array pattern for decimation of RGBW4444 16 bit pixels to
 * individual R, G, B, W values. The pattern represents a replicated 4x4 color filter array for the
 * entire output frame buffer.
 */

#define BP_EPXP_CFA_DATA      (0)
#define BM_EPXP_CFA_DATA      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_CFA_DATA(v)   ((((reg32_t) v) << 0) & BM_EPXP_CFA_DATA)
#else
#define BF_EPXP_CFA_DATA(v)   (((v) << 0) & BM_EPXP_CFA_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_EPXP_CFA_DATA(v)   BF_CS1(EPXP_CFA, DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST_CTRL - Histogram Control Register. (RW)
 *
 * Provides control and status registers for the PXP's histogram classification algorithm.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned STATUS : 4; //!< Indicates which histogram matched the processed bitmap. Bit[0] indicates that the bitmap pixels were fully contained within the HIST2 (black / white) histogram. Bit[1] indicates that the bitmap pixels were fully contained within the HIST4 (2-bit grayscale) histogram. Bit[2] indicates that the bitmap pixels were fully contained within the HIST8 (3-bit grayscale) histogram. Bit[3] indicates that the bitmap pixels were fully contained within the HIST16 (4-bit grayscale) histogram.
        unsigned PANEL_MODE : 2; //!< Specifies the EPDC panel grayscale depth. This value is used to specify the number of bits used in comparisons when matching pixels to histogram bins. All comparator values MUST be programmed such that their bit width is consistent with the value of this register field. For instance, if GRAY16 is selected, comparator values must be in the range of 0x0-0xF.
        unsigned RESERVED0 : 26; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist_ctrl_t;
#endif

/*
 * constants & macros for entire EPXP_HIST_CTRL register
 */
#define HW_EPXP_HIST_CTRL_ADDR      (REGS_EPXP_BASE + 0x290)
#define HW_EPXP_HIST_CTRL_SET_ADDR  (HW_EPXP_HIST_CTRL_ADDR + 0x4)
#define HW_EPXP_HIST_CTRL_CLR_ADDR  (HW_EPXP_HIST_CTRL_ADDR + 0x8)
#define HW_EPXP_HIST_CTRL_TOG_ADDR  (HW_EPXP_HIST_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST_CTRL           (*(volatile hw_epxp_hist_ctrl_t *) HW_EPXP_HIST_CTRL_ADDR)
#define HW_EPXP_HIST_CTRL_RD()      (HW_EPXP_HIST_CTRL.U)
#define HW_EPXP_HIST_CTRL_WR(v)     (HW_EPXP_HIST_CTRL.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST_CTRL_SET_ADDR) = (v))
#define HW_EPXP_HIST_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST_CTRL_CLR_ADDR) = (v))
#define HW_EPXP_HIST_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST_CTRL bitfields
 */

/* --- Register HW_EPXP_HIST_CTRL, field STATUS[3:0] (RW)
 *
 * Indicates which histogram matched the processed bitmap. Bit[0] indicates that the bitmap pixels
 * were fully contained within the HIST2 (black / white) histogram. Bit[1] indicates that the bitmap
 * pixels were fully contained within the HIST4 (2-bit grayscale) histogram. Bit[2] indicates that
 * the bitmap pixels were fully contained within the HIST8 (3-bit grayscale) histogram. Bit[3]
 * indicates that the bitmap pixels were fully contained within the HIST16 (4-bit grayscale)
 * histogram.
 */

#define BP_EPXP_HIST_CTRL_STATUS      (0)
#define BM_EPXP_HIST_CTRL_STATUS      (0x0000000f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST_CTRL_STATUS(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST_CTRL_STATUS)
#else
#define BF_EPXP_HIST_CTRL_STATUS(v)   (((v) << 0) & BM_EPXP_HIST_CTRL_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STATUS field to a new value.
#define BW_EPXP_HIST_CTRL_STATUS(v)   BF_CS1(EPXP_HIST_CTRL, STATUS, v)
#endif

/* --- Register HW_EPXP_HIST_CTRL, field PANEL_MODE[5:4] (RW)
 *
 * Specifies the EPDC panel grayscale depth. This value is used to specify the number of bits used
 * in comparisons when matching pixels to histogram bins. All comparator values MUST be programmed
 * such that their bit width is consistent with the value of this register field. For instance, if
 * GRAY16 is selected, comparator values must be in the range of 0x0-0xF.
 *
 * Values:
 * GRAY4 = 0x0 - 4-bit grayscale
 * GRAY8 = 0x1 - 8-bit grayscale
 * GRAY16 = 0x2 - 16-bit grayscale
 * GRAY32 = 0x3 - 32-bit grayscale
 */

#define BP_EPXP_HIST_CTRL_PANEL_MODE      (4)
#define BM_EPXP_HIST_CTRL_PANEL_MODE      (0x00000030)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST_CTRL_PANEL_MODE(v)   ((((reg32_t) v) << 4) & BM_EPXP_HIST_CTRL_PANEL_MODE)
#else
#define BF_EPXP_HIST_CTRL_PANEL_MODE(v)   (((v) << 4) & BM_EPXP_HIST_CTRL_PANEL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PANEL_MODE field to a new value.
#define BW_EPXP_HIST_CTRL_PANEL_MODE(v)   BF_CS1(EPXP_HIST_CTRL, PANEL_MODE, v)
#endif

#define BV_EPXP_HIST_CTRL_PANEL_MODE__GRAY4 (0x0) //!< 4-bit grayscale
#define BV_EPXP_HIST_CTRL_PANEL_MODE__GRAY8 (0x1) //!< 8-bit grayscale
#define BV_EPXP_HIST_CTRL_PANEL_MODE__GRAY16 (0x2) //!< 16-bit grayscale
#define BV_EPXP_HIST_CTRL_PANEL_MODE__GRAY32 (0x3) //!< 32-bit grayscale

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST2_PARAM - 2-level Histogram Parameter Register. (RW)
 *
 * This register specifies the valid values for a 2-level histogram. If all pixels in a bitmap match
 * the 2-level histogram values, STATUS[0] will be set at the end of frame processing. All
 * comparator values should be programmed such that they are consistent with the PANEL_MODE control
 * field.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VALUE0 : 5; //!< Black value for 2-level histogram
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned VALUE1 : 5; //!< White value for 2-level histogram
        unsigned RESERVED1 : 3; //!< Reserved, always set to zero.
        unsigned RESERVED2 : 16; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist2_param_t;
#endif

/*
 * constants & macros for entire EPXP_HIST2_PARAM register
 */
#define HW_EPXP_HIST2_PARAM_ADDR      (REGS_EPXP_BASE + 0x2a0)
#define HW_EPXP_HIST2_PARAM_SET_ADDR  (HW_EPXP_HIST2_PARAM_ADDR + 0x4)
#define HW_EPXP_HIST2_PARAM_CLR_ADDR  (HW_EPXP_HIST2_PARAM_ADDR + 0x8)
#define HW_EPXP_HIST2_PARAM_TOG_ADDR  (HW_EPXP_HIST2_PARAM_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST2_PARAM           (*(volatile hw_epxp_hist2_param_t *) HW_EPXP_HIST2_PARAM_ADDR)
#define HW_EPXP_HIST2_PARAM_RD()      (HW_EPXP_HIST2_PARAM.U)
#define HW_EPXP_HIST2_PARAM_WR(v)     (HW_EPXP_HIST2_PARAM.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST2_PARAM_SET_ADDR) = (v))
#define HW_EPXP_HIST2_PARAM_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST2_PARAM_CLR_ADDR) = (v))
#define HW_EPXP_HIST2_PARAM_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST2_PARAM_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST2_PARAM bitfields
 */

/* --- Register HW_EPXP_HIST2_PARAM, field VALUE0[4:0] (RW)
 *
 * Black value for 2-level histogram
 */

#define BP_EPXP_HIST2_PARAM_VALUE0      (0)
#define BM_EPXP_HIST2_PARAM_VALUE0      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST2_PARAM_VALUE0(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST2_PARAM_VALUE0)
#else
#define BF_EPXP_HIST2_PARAM_VALUE0(v)   (((v) << 0) & BM_EPXP_HIST2_PARAM_VALUE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPXP_HIST2_PARAM_VALUE0(v)   BF_CS1(EPXP_HIST2_PARAM, VALUE0, v)
#endif

/* --- Register HW_EPXP_HIST2_PARAM, field VALUE1[12:8] (RW)
 *
 * White value for 2-level histogram
 */

#define BP_EPXP_HIST2_PARAM_VALUE1      (8)
#define BM_EPXP_HIST2_PARAM_VALUE1      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST2_PARAM_VALUE1(v)   ((((reg32_t) v) << 8) & BM_EPXP_HIST2_PARAM_VALUE1)
#else
#define BF_EPXP_HIST2_PARAM_VALUE1(v)   (((v) << 8) & BM_EPXP_HIST2_PARAM_VALUE1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE1 field to a new value.
#define BW_EPXP_HIST2_PARAM_VALUE1(v)   BF_CS1(EPXP_HIST2_PARAM, VALUE1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST4_PARAM - 4-level Histogram Parameter Register. (RW)
 *
 * This register specifies the valid values for a 4-level histogram. If all pixels in a bitmap match
 * the 4-level histogram values, STATUS[1] will be set at the end of frame processing. All
 * comparator values should be programmed such that they are consistent with the PANEL_MODE control
 * field.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VALUE0 : 5; //!< GRAY0 (Black) value for 4-level histogram
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned VALUE1 : 5; //!< GRAY1 value for 4-level histogram
        unsigned RESERVED1 : 3; //!< Reserved, always set to zero.
        unsigned VALUE2 : 5; //!< GRAY2 value for 4-level histogram
        unsigned RESERVED2 : 3; //!< Reserved, always set to zero.
        unsigned VALUE3 : 5; //!< GRAY3 (White) value for 4-level histogram
        unsigned RESERVED3 : 3; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist4_param_t;
#endif

/*
 * constants & macros for entire EPXP_HIST4_PARAM register
 */
#define HW_EPXP_HIST4_PARAM_ADDR      (REGS_EPXP_BASE + 0x2b0)
#define HW_EPXP_HIST4_PARAM_SET_ADDR  (HW_EPXP_HIST4_PARAM_ADDR + 0x4)
#define HW_EPXP_HIST4_PARAM_CLR_ADDR  (HW_EPXP_HIST4_PARAM_ADDR + 0x8)
#define HW_EPXP_HIST4_PARAM_TOG_ADDR  (HW_EPXP_HIST4_PARAM_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST4_PARAM           (*(volatile hw_epxp_hist4_param_t *) HW_EPXP_HIST4_PARAM_ADDR)
#define HW_EPXP_HIST4_PARAM_RD()      (HW_EPXP_HIST4_PARAM.U)
#define HW_EPXP_HIST4_PARAM_WR(v)     (HW_EPXP_HIST4_PARAM.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST4_PARAM_SET_ADDR) = (v))
#define HW_EPXP_HIST4_PARAM_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST4_PARAM_CLR_ADDR) = (v))
#define HW_EPXP_HIST4_PARAM_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST4_PARAM_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST4_PARAM bitfields
 */

/* --- Register HW_EPXP_HIST4_PARAM, field VALUE0[4:0] (RW)
 *
 * GRAY0 (Black) value for 4-level histogram
 */

#define BP_EPXP_HIST4_PARAM_VALUE0      (0)
#define BM_EPXP_HIST4_PARAM_VALUE0      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST4_PARAM_VALUE0(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST4_PARAM_VALUE0)
#else
#define BF_EPXP_HIST4_PARAM_VALUE0(v)   (((v) << 0) & BM_EPXP_HIST4_PARAM_VALUE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPXP_HIST4_PARAM_VALUE0(v)   BF_CS1(EPXP_HIST4_PARAM, VALUE0, v)
#endif

/* --- Register HW_EPXP_HIST4_PARAM, field VALUE1[12:8] (RW)
 *
 * GRAY1 value for 4-level histogram
 */

#define BP_EPXP_HIST4_PARAM_VALUE1      (8)
#define BM_EPXP_HIST4_PARAM_VALUE1      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST4_PARAM_VALUE1(v)   ((((reg32_t) v) << 8) & BM_EPXP_HIST4_PARAM_VALUE1)
#else
#define BF_EPXP_HIST4_PARAM_VALUE1(v)   (((v) << 8) & BM_EPXP_HIST4_PARAM_VALUE1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE1 field to a new value.
#define BW_EPXP_HIST4_PARAM_VALUE1(v)   BF_CS1(EPXP_HIST4_PARAM, VALUE1, v)
#endif

/* --- Register HW_EPXP_HIST4_PARAM, field VALUE2[20:16] (RW)
 *
 * GRAY2 value for 4-level histogram
 */

#define BP_EPXP_HIST4_PARAM_VALUE2      (16)
#define BM_EPXP_HIST4_PARAM_VALUE2      (0x001f0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST4_PARAM_VALUE2(v)   ((((reg32_t) v) << 16) & BM_EPXP_HIST4_PARAM_VALUE2)
#else
#define BF_EPXP_HIST4_PARAM_VALUE2(v)   (((v) << 16) & BM_EPXP_HIST4_PARAM_VALUE2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE2 field to a new value.
#define BW_EPXP_HIST4_PARAM_VALUE2(v)   BF_CS1(EPXP_HIST4_PARAM, VALUE2, v)
#endif

/* --- Register HW_EPXP_HIST4_PARAM, field VALUE3[28:24] (RW)
 *
 * GRAY3 (White) value for 4-level histogram
 */

#define BP_EPXP_HIST4_PARAM_VALUE3      (24)
#define BM_EPXP_HIST4_PARAM_VALUE3      (0x1f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST4_PARAM_VALUE3(v)   ((((reg32_t) v) << 24) & BM_EPXP_HIST4_PARAM_VALUE3)
#else
#define BF_EPXP_HIST4_PARAM_VALUE3(v)   (((v) << 24) & BM_EPXP_HIST4_PARAM_VALUE3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE3 field to a new value.
#define BW_EPXP_HIST4_PARAM_VALUE3(v)   BF_CS1(EPXP_HIST4_PARAM, VALUE3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST8_PARAM0 - 8-level Histogram Parameter 0 Register. (RW)
 *
 * This register specifies four of the valid values for an 8-level histogram. If all pixels in a
 * bitmap match the 8-level histogram values, STATUS[2] will be set at the end of frame processing.
 * All comparator values should be programmed such that they are consistent with the PANEL_MODE
 * control field.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VALUE0 : 5; //!< GRAY0 (Black) value for 8-level histogram
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned VALUE1 : 5; //!< GRAY1 value for 8-level histogram
        unsigned RESERVED1 : 3; //!< Reserved, always set to zero.
        unsigned VALUE2 : 5; //!< GRAY2 value for 8-level histogram
        unsigned RESERVED2 : 3; //!< Reserved, always set to zero.
        unsigned VALUE3 : 5; //!< GRAY3 value for 8-level histogram
        unsigned RESERVED3 : 3; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist8_param0_t;
#endif

/*
 * constants & macros for entire EPXP_HIST8_PARAM0 register
 */
#define HW_EPXP_HIST8_PARAM0_ADDR      (REGS_EPXP_BASE + 0x2c0)
#define HW_EPXP_HIST8_PARAM0_SET_ADDR  (HW_EPXP_HIST8_PARAM0_ADDR + 0x4)
#define HW_EPXP_HIST8_PARAM0_CLR_ADDR  (HW_EPXP_HIST8_PARAM0_ADDR + 0x8)
#define HW_EPXP_HIST8_PARAM0_TOG_ADDR  (HW_EPXP_HIST8_PARAM0_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST8_PARAM0           (*(volatile hw_epxp_hist8_param0_t *) HW_EPXP_HIST8_PARAM0_ADDR)
#define HW_EPXP_HIST8_PARAM0_RD()      (HW_EPXP_HIST8_PARAM0.U)
#define HW_EPXP_HIST8_PARAM0_WR(v)     (HW_EPXP_HIST8_PARAM0.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST8_PARAM0_SET_ADDR) = (v))
#define HW_EPXP_HIST8_PARAM0_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST8_PARAM0_CLR_ADDR) = (v))
#define HW_EPXP_HIST8_PARAM0_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST8_PARAM0_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST8_PARAM0 bitfields
 */

/* --- Register HW_EPXP_HIST8_PARAM0, field VALUE0[4:0] (RW)
 *
 * GRAY0 (Black) value for 8-level histogram
 */

#define BP_EPXP_HIST8_PARAM0_VALUE0      (0)
#define BM_EPXP_HIST8_PARAM0_VALUE0      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST8_PARAM0_VALUE0(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST8_PARAM0_VALUE0)
#else
#define BF_EPXP_HIST8_PARAM0_VALUE0(v)   (((v) << 0) & BM_EPXP_HIST8_PARAM0_VALUE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPXP_HIST8_PARAM0_VALUE0(v)   BF_CS1(EPXP_HIST8_PARAM0, VALUE0, v)
#endif

/* --- Register HW_EPXP_HIST8_PARAM0, field VALUE1[12:8] (RW)
 *
 * GRAY1 value for 8-level histogram
 */

#define BP_EPXP_HIST8_PARAM0_VALUE1      (8)
#define BM_EPXP_HIST8_PARAM0_VALUE1      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST8_PARAM0_VALUE1(v)   ((((reg32_t) v) << 8) & BM_EPXP_HIST8_PARAM0_VALUE1)
#else
#define BF_EPXP_HIST8_PARAM0_VALUE1(v)   (((v) << 8) & BM_EPXP_HIST8_PARAM0_VALUE1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE1 field to a new value.
#define BW_EPXP_HIST8_PARAM0_VALUE1(v)   BF_CS1(EPXP_HIST8_PARAM0, VALUE1, v)
#endif

/* --- Register HW_EPXP_HIST8_PARAM0, field VALUE2[20:16] (RW)
 *
 * GRAY2 value for 8-level histogram
 */

#define BP_EPXP_HIST8_PARAM0_VALUE2      (16)
#define BM_EPXP_HIST8_PARAM0_VALUE2      (0x001f0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST8_PARAM0_VALUE2(v)   ((((reg32_t) v) << 16) & BM_EPXP_HIST8_PARAM0_VALUE2)
#else
#define BF_EPXP_HIST8_PARAM0_VALUE2(v)   (((v) << 16) & BM_EPXP_HIST8_PARAM0_VALUE2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE2 field to a new value.
#define BW_EPXP_HIST8_PARAM0_VALUE2(v)   BF_CS1(EPXP_HIST8_PARAM0, VALUE2, v)
#endif

/* --- Register HW_EPXP_HIST8_PARAM0, field VALUE3[28:24] (RW)
 *
 * GRAY3 value for 8-level histogram
 */

#define BP_EPXP_HIST8_PARAM0_VALUE3      (24)
#define BM_EPXP_HIST8_PARAM0_VALUE3      (0x1f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST8_PARAM0_VALUE3(v)   ((((reg32_t) v) << 24) & BM_EPXP_HIST8_PARAM0_VALUE3)
#else
#define BF_EPXP_HIST8_PARAM0_VALUE3(v)   (((v) << 24) & BM_EPXP_HIST8_PARAM0_VALUE3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE3 field to a new value.
#define BW_EPXP_HIST8_PARAM0_VALUE3(v)   BF_CS1(EPXP_HIST8_PARAM0, VALUE3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST8_PARAM1 - 8-level Histogram Parameter 1 Register. (RW)
 *
 * This register specifies four of the valid values for an 8-level histogram. If all pixels in a
 * bitmap match the 8-level histogram values, STATUS[2] will be set at the end of frame processing.
 * All comparator values should be programmed such that they are consistent with the PANEL_MODE
 * control field.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VALUE4 : 5; //!< GRAY4 value for 8-level histogram
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned VALUE5 : 5; //!< GRAY5 value for 8-level histogram
        unsigned RESERVED1 : 3; //!< Reserved, always set to zero.
        unsigned VALUE6 : 5; //!< GRAY6 value for 8-level histogram
        unsigned RESERVED2 : 3; //!< Reserved, always set to zero.
        unsigned VALUE7 : 5; //!< GRAY7 (White) value for 8-level histogram
        unsigned RESERVED3 : 3; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist8_param1_t;
#endif

/*
 * constants & macros for entire EPXP_HIST8_PARAM1 register
 */
#define HW_EPXP_HIST8_PARAM1_ADDR      (REGS_EPXP_BASE + 0x2d0)
#define HW_EPXP_HIST8_PARAM1_SET_ADDR  (HW_EPXP_HIST8_PARAM1_ADDR + 0x4)
#define HW_EPXP_HIST8_PARAM1_CLR_ADDR  (HW_EPXP_HIST8_PARAM1_ADDR + 0x8)
#define HW_EPXP_HIST8_PARAM1_TOG_ADDR  (HW_EPXP_HIST8_PARAM1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST8_PARAM1           (*(volatile hw_epxp_hist8_param1_t *) HW_EPXP_HIST8_PARAM1_ADDR)
#define HW_EPXP_HIST8_PARAM1_RD()      (HW_EPXP_HIST8_PARAM1.U)
#define HW_EPXP_HIST8_PARAM1_WR(v)     (HW_EPXP_HIST8_PARAM1.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST8_PARAM1_SET_ADDR) = (v))
#define HW_EPXP_HIST8_PARAM1_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST8_PARAM1_CLR_ADDR) = (v))
#define HW_EPXP_HIST8_PARAM1_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST8_PARAM1_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST8_PARAM1 bitfields
 */

/* --- Register HW_EPXP_HIST8_PARAM1, field VALUE4[4:0] (RW)
 *
 * GRAY4 value for 8-level histogram
 */

#define BP_EPXP_HIST8_PARAM1_VALUE4      (0)
#define BM_EPXP_HIST8_PARAM1_VALUE4      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST8_PARAM1_VALUE4(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST8_PARAM1_VALUE4)
#else
#define BF_EPXP_HIST8_PARAM1_VALUE4(v)   (((v) << 0) & BM_EPXP_HIST8_PARAM1_VALUE4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE4 field to a new value.
#define BW_EPXP_HIST8_PARAM1_VALUE4(v)   BF_CS1(EPXP_HIST8_PARAM1, VALUE4, v)
#endif

/* --- Register HW_EPXP_HIST8_PARAM1, field VALUE5[12:8] (RW)
 *
 * GRAY5 value for 8-level histogram
 */

#define BP_EPXP_HIST8_PARAM1_VALUE5      (8)
#define BM_EPXP_HIST8_PARAM1_VALUE5      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST8_PARAM1_VALUE5(v)   ((((reg32_t) v) << 8) & BM_EPXP_HIST8_PARAM1_VALUE5)
#else
#define BF_EPXP_HIST8_PARAM1_VALUE5(v)   (((v) << 8) & BM_EPXP_HIST8_PARAM1_VALUE5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE5 field to a new value.
#define BW_EPXP_HIST8_PARAM1_VALUE5(v)   BF_CS1(EPXP_HIST8_PARAM1, VALUE5, v)
#endif

/* --- Register HW_EPXP_HIST8_PARAM1, field VALUE6[20:16] (RW)
 *
 * GRAY6 value for 8-level histogram
 */

#define BP_EPXP_HIST8_PARAM1_VALUE6      (16)
#define BM_EPXP_HIST8_PARAM1_VALUE6      (0x001f0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST8_PARAM1_VALUE6(v)   ((((reg32_t) v) << 16) & BM_EPXP_HIST8_PARAM1_VALUE6)
#else
#define BF_EPXP_HIST8_PARAM1_VALUE6(v)   (((v) << 16) & BM_EPXP_HIST8_PARAM1_VALUE6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE6 field to a new value.
#define BW_EPXP_HIST8_PARAM1_VALUE6(v)   BF_CS1(EPXP_HIST8_PARAM1, VALUE6, v)
#endif

/* --- Register HW_EPXP_HIST8_PARAM1, field VALUE7[28:24] (RW)
 *
 * GRAY7 (White) value for 8-level histogram
 */

#define BP_EPXP_HIST8_PARAM1_VALUE7      (24)
#define BM_EPXP_HIST8_PARAM1_VALUE7      (0x1f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST8_PARAM1_VALUE7(v)   ((((reg32_t) v) << 24) & BM_EPXP_HIST8_PARAM1_VALUE7)
#else
#define BF_EPXP_HIST8_PARAM1_VALUE7(v)   (((v) << 24) & BM_EPXP_HIST8_PARAM1_VALUE7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE7 field to a new value.
#define BW_EPXP_HIST8_PARAM1_VALUE7(v)   BF_CS1(EPXP_HIST8_PARAM1, VALUE7, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST16_PARAM0 - 16-level Histogram Parameter 0 Register. (RW)
 *
 * This register specifies four of the valid values for a 16-level histogram. If all pixels in a
 * bitmap match the 16-level histogram values, STATUS[3] will be set at the end of frame processing.
 * All comparator values should be programmed such that they are consistent with the PANEL_MODE
 * control field.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VALUE0 : 5; //!< GRAY0 (Black) value for 16-level histogram
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned VALUE1 : 5; //!< GRAY1 value for 16-level histogram
        unsigned RESERVED1 : 3; //!< Reserved, always set to zero.
        unsigned VALUE2 : 5; //!< GRAY2 value for 16-level histogram
        unsigned RESERVED2 : 3; //!< Reserved, always set to zero.
        unsigned VALUE3 : 5; //!< GRAY3 value for 16-level histogram
        unsigned RESERVED3 : 3; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist16_param0_t;
#endif

/*
 * constants & macros for entire EPXP_HIST16_PARAM0 register
 */
#define HW_EPXP_HIST16_PARAM0_ADDR      (REGS_EPXP_BASE + 0x2e0)
#define HW_EPXP_HIST16_PARAM0_SET_ADDR  (HW_EPXP_HIST16_PARAM0_ADDR + 0x4)
#define HW_EPXP_HIST16_PARAM0_CLR_ADDR  (HW_EPXP_HIST16_PARAM0_ADDR + 0x8)
#define HW_EPXP_HIST16_PARAM0_TOG_ADDR  (HW_EPXP_HIST16_PARAM0_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST16_PARAM0           (*(volatile hw_epxp_hist16_param0_t *) HW_EPXP_HIST16_PARAM0_ADDR)
#define HW_EPXP_HIST16_PARAM0_RD()      (HW_EPXP_HIST16_PARAM0.U)
#define HW_EPXP_HIST16_PARAM0_WR(v)     (HW_EPXP_HIST16_PARAM0.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM0_SET_ADDR) = (v))
#define HW_EPXP_HIST16_PARAM0_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM0_CLR_ADDR) = (v))
#define HW_EPXP_HIST16_PARAM0_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM0_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST16_PARAM0 bitfields
 */

/* --- Register HW_EPXP_HIST16_PARAM0, field VALUE0[4:0] (RW)
 *
 * GRAY0 (Black) value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM0_VALUE0      (0)
#define BM_EPXP_HIST16_PARAM0_VALUE0      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM0_VALUE0(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST16_PARAM0_VALUE0)
#else
#define BF_EPXP_HIST16_PARAM0_VALUE0(v)   (((v) << 0) & BM_EPXP_HIST16_PARAM0_VALUE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE0 field to a new value.
#define BW_EPXP_HIST16_PARAM0_VALUE0(v)   BF_CS1(EPXP_HIST16_PARAM0, VALUE0, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM0, field VALUE1[12:8] (RW)
 *
 * GRAY1 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM0_VALUE1      (8)
#define BM_EPXP_HIST16_PARAM0_VALUE1      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM0_VALUE1(v)   ((((reg32_t) v) << 8) & BM_EPXP_HIST16_PARAM0_VALUE1)
#else
#define BF_EPXP_HIST16_PARAM0_VALUE1(v)   (((v) << 8) & BM_EPXP_HIST16_PARAM0_VALUE1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE1 field to a new value.
#define BW_EPXP_HIST16_PARAM0_VALUE1(v)   BF_CS1(EPXP_HIST16_PARAM0, VALUE1, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM0, field VALUE2[20:16] (RW)
 *
 * GRAY2 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM0_VALUE2      (16)
#define BM_EPXP_HIST16_PARAM0_VALUE2      (0x001f0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM0_VALUE2(v)   ((((reg32_t) v) << 16) & BM_EPXP_HIST16_PARAM0_VALUE2)
#else
#define BF_EPXP_HIST16_PARAM0_VALUE2(v)   (((v) << 16) & BM_EPXP_HIST16_PARAM0_VALUE2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE2 field to a new value.
#define BW_EPXP_HIST16_PARAM0_VALUE2(v)   BF_CS1(EPXP_HIST16_PARAM0, VALUE2, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM0, field VALUE3[28:24] (RW)
 *
 * GRAY3 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM0_VALUE3      (24)
#define BM_EPXP_HIST16_PARAM0_VALUE3      (0x1f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM0_VALUE3(v)   ((((reg32_t) v) << 24) & BM_EPXP_HIST16_PARAM0_VALUE3)
#else
#define BF_EPXP_HIST16_PARAM0_VALUE3(v)   (((v) << 24) & BM_EPXP_HIST16_PARAM0_VALUE3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE3 field to a new value.
#define BW_EPXP_HIST16_PARAM0_VALUE3(v)   BF_CS1(EPXP_HIST16_PARAM0, VALUE3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST16_PARAM1 - 16-level Histogram Parameter 1 Register. (RW)
 *
 * This register specifies four of the valid values for a 16-level histogram. If all pixels in a
 * bitmap match the 16-level histogram values, STATUS[3] will be set at the end of frame processing.
 * All comparator values should be programmed such that they are consistent with the PANEL_MODE
 * control field.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VALUE4 : 5; //!< GRAY4 value for 16-level histogram
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned VALUE5 : 5; //!< GRAY5 value for 16-level histogram
        unsigned RESERVED1 : 3; //!< Reserved, always set to zero.
        unsigned VALUE6 : 5; //!< GRAY6 value for 16-level histogram
        unsigned RESERVED2 : 3; //!< Reserved, always set to zero.
        unsigned VALUE7 : 5; //!< GRAY7 value for 16-level histogram
        unsigned RESERVED3 : 3; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist16_param1_t;
#endif

/*
 * constants & macros for entire EPXP_HIST16_PARAM1 register
 */
#define HW_EPXP_HIST16_PARAM1_ADDR      (REGS_EPXP_BASE + 0x2f0)
#define HW_EPXP_HIST16_PARAM1_SET_ADDR  (HW_EPXP_HIST16_PARAM1_ADDR + 0x4)
#define HW_EPXP_HIST16_PARAM1_CLR_ADDR  (HW_EPXP_HIST16_PARAM1_ADDR + 0x8)
#define HW_EPXP_HIST16_PARAM1_TOG_ADDR  (HW_EPXP_HIST16_PARAM1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST16_PARAM1           (*(volatile hw_epxp_hist16_param1_t *) HW_EPXP_HIST16_PARAM1_ADDR)
#define HW_EPXP_HIST16_PARAM1_RD()      (HW_EPXP_HIST16_PARAM1.U)
#define HW_EPXP_HIST16_PARAM1_WR(v)     (HW_EPXP_HIST16_PARAM1.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM1_SET_ADDR) = (v))
#define HW_EPXP_HIST16_PARAM1_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM1_CLR_ADDR) = (v))
#define HW_EPXP_HIST16_PARAM1_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM1_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST16_PARAM1 bitfields
 */

/* --- Register HW_EPXP_HIST16_PARAM1, field VALUE4[4:0] (RW)
 *
 * GRAY4 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM1_VALUE4      (0)
#define BM_EPXP_HIST16_PARAM1_VALUE4      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM1_VALUE4(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST16_PARAM1_VALUE4)
#else
#define BF_EPXP_HIST16_PARAM1_VALUE4(v)   (((v) << 0) & BM_EPXP_HIST16_PARAM1_VALUE4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE4 field to a new value.
#define BW_EPXP_HIST16_PARAM1_VALUE4(v)   BF_CS1(EPXP_HIST16_PARAM1, VALUE4, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM1, field VALUE5[12:8] (RW)
 *
 * GRAY5 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM1_VALUE5      (8)
#define BM_EPXP_HIST16_PARAM1_VALUE5      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM1_VALUE5(v)   ((((reg32_t) v) << 8) & BM_EPXP_HIST16_PARAM1_VALUE5)
#else
#define BF_EPXP_HIST16_PARAM1_VALUE5(v)   (((v) << 8) & BM_EPXP_HIST16_PARAM1_VALUE5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE5 field to a new value.
#define BW_EPXP_HIST16_PARAM1_VALUE5(v)   BF_CS1(EPXP_HIST16_PARAM1, VALUE5, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM1, field VALUE6[20:16] (RW)
 *
 * GRAY6 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM1_VALUE6      (16)
#define BM_EPXP_HIST16_PARAM1_VALUE6      (0x001f0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM1_VALUE6(v)   ((((reg32_t) v) << 16) & BM_EPXP_HIST16_PARAM1_VALUE6)
#else
#define BF_EPXP_HIST16_PARAM1_VALUE6(v)   (((v) << 16) & BM_EPXP_HIST16_PARAM1_VALUE6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE6 field to a new value.
#define BW_EPXP_HIST16_PARAM1_VALUE6(v)   BF_CS1(EPXP_HIST16_PARAM1, VALUE6, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM1, field VALUE7[28:24] (RW)
 *
 * GRAY7 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM1_VALUE7      (24)
#define BM_EPXP_HIST16_PARAM1_VALUE7      (0x1f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM1_VALUE7(v)   ((((reg32_t) v) << 24) & BM_EPXP_HIST16_PARAM1_VALUE7)
#else
#define BF_EPXP_HIST16_PARAM1_VALUE7(v)   (((v) << 24) & BM_EPXP_HIST16_PARAM1_VALUE7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE7 field to a new value.
#define BW_EPXP_HIST16_PARAM1_VALUE7(v)   BF_CS1(EPXP_HIST16_PARAM1, VALUE7, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST16_PARAM2 - 16-level Histogram Parameter 2 Register. (RW)
 *
 * This register specifies four of the valid values for a 16-level histogram. If all pixels in a
 * bitmap match the 16-level histogram values, STATUS[3] will be set at the end of frame processing.
 * All comparator values should be programmed such that they are consistent with the PANEL_MODE
 * control field.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VALUE8 : 5; //!< GRAY8 value for 16-level histogram
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned VALUE9 : 5; //!< GRAY9 value for 16-level histogram
        unsigned RESERVED1 : 3; //!< Reserved, always set to zero.
        unsigned VALUE10 : 5; //!< GRAY10 value for 16-level histogram
        unsigned RESERVED2 : 3; //!< Reserved, always set to zero.
        unsigned VALUE11 : 5; //!< GRAY11 value for 16-level histogram
        unsigned RESERVED3 : 3; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist16_param2_t;
#endif

/*
 * constants & macros for entire EPXP_HIST16_PARAM2 register
 */
#define HW_EPXP_HIST16_PARAM2_ADDR      (REGS_EPXP_BASE + 0x300)
#define HW_EPXP_HIST16_PARAM2_SET_ADDR  (HW_EPXP_HIST16_PARAM2_ADDR + 0x4)
#define HW_EPXP_HIST16_PARAM2_CLR_ADDR  (HW_EPXP_HIST16_PARAM2_ADDR + 0x8)
#define HW_EPXP_HIST16_PARAM2_TOG_ADDR  (HW_EPXP_HIST16_PARAM2_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST16_PARAM2           (*(volatile hw_epxp_hist16_param2_t *) HW_EPXP_HIST16_PARAM2_ADDR)
#define HW_EPXP_HIST16_PARAM2_RD()      (HW_EPXP_HIST16_PARAM2.U)
#define HW_EPXP_HIST16_PARAM2_WR(v)     (HW_EPXP_HIST16_PARAM2.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM2_SET_ADDR) = (v))
#define HW_EPXP_HIST16_PARAM2_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM2_CLR_ADDR) = (v))
#define HW_EPXP_HIST16_PARAM2_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM2_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST16_PARAM2 bitfields
 */

/* --- Register HW_EPXP_HIST16_PARAM2, field VALUE8[4:0] (RW)
 *
 * GRAY8 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM2_VALUE8      (0)
#define BM_EPXP_HIST16_PARAM2_VALUE8      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM2_VALUE8(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST16_PARAM2_VALUE8)
#else
#define BF_EPXP_HIST16_PARAM2_VALUE8(v)   (((v) << 0) & BM_EPXP_HIST16_PARAM2_VALUE8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE8 field to a new value.
#define BW_EPXP_HIST16_PARAM2_VALUE8(v)   BF_CS1(EPXP_HIST16_PARAM2, VALUE8, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM2, field VALUE9[12:8] (RW)
 *
 * GRAY9 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM2_VALUE9      (8)
#define BM_EPXP_HIST16_PARAM2_VALUE9      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM2_VALUE9(v)   ((((reg32_t) v) << 8) & BM_EPXP_HIST16_PARAM2_VALUE9)
#else
#define BF_EPXP_HIST16_PARAM2_VALUE9(v)   (((v) << 8) & BM_EPXP_HIST16_PARAM2_VALUE9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE9 field to a new value.
#define BW_EPXP_HIST16_PARAM2_VALUE9(v)   BF_CS1(EPXP_HIST16_PARAM2, VALUE9, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM2, field VALUE10[20:16] (RW)
 *
 * GRAY10 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM2_VALUE10      (16)
#define BM_EPXP_HIST16_PARAM2_VALUE10      (0x001f0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM2_VALUE10(v)   ((((reg32_t) v) << 16) & BM_EPXP_HIST16_PARAM2_VALUE10)
#else
#define BF_EPXP_HIST16_PARAM2_VALUE10(v)   (((v) << 16) & BM_EPXP_HIST16_PARAM2_VALUE10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE10 field to a new value.
#define BW_EPXP_HIST16_PARAM2_VALUE10(v)   BF_CS1(EPXP_HIST16_PARAM2, VALUE10, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM2, field VALUE11[28:24] (RW)
 *
 * GRAY11 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM2_VALUE11      (24)
#define BM_EPXP_HIST16_PARAM2_VALUE11      (0x1f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM2_VALUE11(v)   ((((reg32_t) v) << 24) & BM_EPXP_HIST16_PARAM2_VALUE11)
#else
#define BF_EPXP_HIST16_PARAM2_VALUE11(v)   (((v) << 24) & BM_EPXP_HIST16_PARAM2_VALUE11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE11 field to a new value.
#define BW_EPXP_HIST16_PARAM2_VALUE11(v)   BF_CS1(EPXP_HIST16_PARAM2, VALUE11, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_HIST16_PARAM3 - 16-level Histogram Parameter 3 Register. (RW)
 *
 * This register specifies four of the valid values for a 16-level histogram. If all pixels in a
 * bitmap match the 16-level histogram values, STATUS[3] will be set at the end of frame processing.
 * All comparator values should be programmed such that they are consistent with the PANEL_MODE
 * control field.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VALUE12 : 5; //!< GRAY12 value for 16-level histogram
        unsigned RESERVED0 : 3; //!< Reserved, always set to zero.
        unsigned VALUE13 : 5; //!< GRAY13 value for 16-level histogram
        unsigned RESERVED1 : 3; //!< Reserved, always set to zero.
        unsigned VALUE14 : 5; //!< GRAY14 value for 16-level histogram
        unsigned RESERVED2 : 3; //!< Reserved, always set to zero.
        unsigned VALUE15 : 5; //!< GRAY15 (White) value for 16-level histogram
        unsigned RESERVED3 : 3; //!< Reserved, always set to zero.
    } B;
} hw_epxp_hist16_param3_t;
#endif

/*
 * constants & macros for entire EPXP_HIST16_PARAM3 register
 */
#define HW_EPXP_HIST16_PARAM3_ADDR      (REGS_EPXP_BASE + 0x310)
#define HW_EPXP_HIST16_PARAM3_SET_ADDR  (HW_EPXP_HIST16_PARAM3_ADDR + 0x4)
#define HW_EPXP_HIST16_PARAM3_CLR_ADDR  (HW_EPXP_HIST16_PARAM3_ADDR + 0x8)
#define HW_EPXP_HIST16_PARAM3_TOG_ADDR  (HW_EPXP_HIST16_PARAM3_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_HIST16_PARAM3           (*(volatile hw_epxp_hist16_param3_t *) HW_EPXP_HIST16_PARAM3_ADDR)
#define HW_EPXP_HIST16_PARAM3_RD()      (HW_EPXP_HIST16_PARAM3.U)
#define HW_EPXP_HIST16_PARAM3_WR(v)     (HW_EPXP_HIST16_PARAM3.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM3_SET_ADDR) = (v))
#define HW_EPXP_HIST16_PARAM3_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM3_CLR_ADDR) = (v))
#define HW_EPXP_HIST16_PARAM3_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_HIST16_PARAM3_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_HIST16_PARAM3 bitfields
 */

/* --- Register HW_EPXP_HIST16_PARAM3, field VALUE12[4:0] (RW)
 *
 * GRAY12 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM3_VALUE12      (0)
#define BM_EPXP_HIST16_PARAM3_VALUE12      (0x0000001f)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM3_VALUE12(v)   ((((reg32_t) v) << 0) & BM_EPXP_HIST16_PARAM3_VALUE12)
#else
#define BF_EPXP_HIST16_PARAM3_VALUE12(v)   (((v) << 0) & BM_EPXP_HIST16_PARAM3_VALUE12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE12 field to a new value.
#define BW_EPXP_HIST16_PARAM3_VALUE12(v)   BF_CS1(EPXP_HIST16_PARAM3, VALUE12, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM3, field VALUE13[12:8] (RW)
 *
 * GRAY13 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM3_VALUE13      (8)
#define BM_EPXP_HIST16_PARAM3_VALUE13      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM3_VALUE13(v)   ((((reg32_t) v) << 8) & BM_EPXP_HIST16_PARAM3_VALUE13)
#else
#define BF_EPXP_HIST16_PARAM3_VALUE13(v)   (((v) << 8) & BM_EPXP_HIST16_PARAM3_VALUE13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE13 field to a new value.
#define BW_EPXP_HIST16_PARAM3_VALUE13(v)   BF_CS1(EPXP_HIST16_PARAM3, VALUE13, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM3, field VALUE14[20:16] (RW)
 *
 * GRAY14 value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM3_VALUE14      (16)
#define BM_EPXP_HIST16_PARAM3_VALUE14      (0x001f0000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM3_VALUE14(v)   ((((reg32_t) v) << 16) & BM_EPXP_HIST16_PARAM3_VALUE14)
#else
#define BF_EPXP_HIST16_PARAM3_VALUE14(v)   (((v) << 16) & BM_EPXP_HIST16_PARAM3_VALUE14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE14 field to a new value.
#define BW_EPXP_HIST16_PARAM3_VALUE14(v)   BF_CS1(EPXP_HIST16_PARAM3, VALUE14, v)
#endif

/* --- Register HW_EPXP_HIST16_PARAM3, field VALUE15[28:24] (RW)
 *
 * GRAY15 (White) value for 16-level histogram
 */

#define BP_EPXP_HIST16_PARAM3_VALUE15      (24)
#define BM_EPXP_HIST16_PARAM3_VALUE15      (0x1f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_HIST16_PARAM3_VALUE15(v)   ((((reg32_t) v) << 24) & BM_EPXP_HIST16_PARAM3_VALUE15)
#else
#define BF_EPXP_HIST16_PARAM3_VALUE15(v)   (((v) << 24) & BM_EPXP_HIST16_PARAM3_VALUE15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE15 field to a new value.
#define BW_EPXP_HIST16_PARAM3_VALUE15(v)   BF_CS1(EPXP_HIST16_PARAM3, VALUE15, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_POWER - PXP Power Control Register. (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LUT_LP_STATE_WAY0_BANK0 : 3; //!< Select the low power state of the LUT's WAY0-BANK0 memory.
        unsigned LUT_LP_STATE_WAY0_BANKN : 3; //!< Select the low power state of the LUT's WAY0-BANK1,2,3 memory.
        unsigned LUT_LP_STATE_WAY1_BANKN : 3; //!< Select the low power state of the LUT's WAY0-BANK0,1,2,3 memory.
        unsigned ROT_MEM_LP_STATE : 3; //!< Select the low power state of the ROT memory.
        unsigned CTRL : 20; //!< This register contains power control for the PXP.
    } B;
} hw_epxp_power_t;
#endif

/*
 * constants & macros for entire EPXP_POWER register
 */
#define HW_EPXP_POWER_ADDR      (REGS_EPXP_BASE + 0x320)
#define HW_EPXP_POWER_SET_ADDR  (HW_EPXP_POWER_ADDR + 0x4)
#define HW_EPXP_POWER_CLR_ADDR  (HW_EPXP_POWER_ADDR + 0x8)
#define HW_EPXP_POWER_TOG_ADDR  (HW_EPXP_POWER_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_POWER           (*(volatile hw_epxp_power_t *) HW_EPXP_POWER_ADDR)
#define HW_EPXP_POWER_RD()      (HW_EPXP_POWER.U)
#define HW_EPXP_POWER_WR(v)     (HW_EPXP_POWER.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_POWER_SET_ADDR) = (v))
#define HW_EPXP_POWER_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_POWER_CLR_ADDR) = (v))
#define HW_EPXP_POWER_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_POWER_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_POWER bitfields
 */

/* --- Register HW_EPXP_POWER, field LUT_LP_STATE_WAY0_BANK0[2:0] (RW)
 *
 * Select the low power state of the LUT's WAY0-BANK0 memory.
 *
 * Values:
 * NONE = 0x0 - Memory is not in low power state.
 * LS = 0x1 - Light Sleep Mode. Low leakage mode, maintain memory contents.
 * DS = 0x2 - Deep Sleep Mode. Low leakage mode, maintain memory contents.
 * SD = 0x4 - Shut Down Mode. Shut Down periphery and core, no memory retention.
 */

#define BP_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0      (0)
#define BM_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0(v)   ((((reg32_t) v) << 0) & BM_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0)
#else
#define BF_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0(v)   (((v) << 0) & BM_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_LP_STATE_WAY0_BANK0 field to a new value.
#define BW_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0(v)   BF_CS1(EPXP_POWER, LUT_LP_STATE_WAY0_BANK0, v)
#endif

#define BV_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0__NONE (0x0) //!< Memory is not in low power state.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0__LS (0x1) //!< Light Sleep Mode. Low leakage mode, maintain memory contents.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0__DS (0x2) //!< Deep Sleep Mode. Low leakage mode, maintain memory contents.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY0_BANK0__SD (0x4) //!< Shut Down Mode. Shut Down periphery and core, no memory retention.

/* --- Register HW_EPXP_POWER, field LUT_LP_STATE_WAY0_BANKN[5:3] (RW)
 *
 * Select the low power state of the LUT's WAY0-BANK1,2,3 memory.
 *
 * Values:
 * NONE = 0x0 - Memory is not in low power state.
 * LS = 0x1 - Light Sleep Mode. Low leakage mode, maintain memory contents.
 * DS = 0x2 - Deep Sleep Mode. Low leakage mode, maintain memory contents.
 * SD = 0x4 - Shut Down Mode. Shut Down periphery and core, no memory retention.
 */

#define BP_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN      (3)
#define BM_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN      (0x00000038)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN(v)   ((((reg32_t) v) << 3) & BM_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN)
#else
#define BF_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN(v)   (((v) << 3) & BM_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_LP_STATE_WAY0_BANKN field to a new value.
#define BW_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN(v)   BF_CS1(EPXP_POWER, LUT_LP_STATE_WAY0_BANKN, v)
#endif

#define BV_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN__NONE (0x0) //!< Memory is not in low power state.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN__LS (0x1) //!< Light Sleep Mode. Low leakage mode, maintain memory contents.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN__DS (0x2) //!< Deep Sleep Mode. Low leakage mode, maintain memory contents.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY0_BANKN__SD (0x4) //!< Shut Down Mode. Shut Down periphery and core, no memory retention.

/* --- Register HW_EPXP_POWER, field LUT_LP_STATE_WAY1_BANKN[8:6] (RW)
 *
 * Select the low power state of the LUT's WAY0-BANK0,1,2,3 memory.
 *
 * Values:
 * NONE = 0x0 - Memory is not in low power state.
 * LS = 0x1 - Light Sleep Mode. Low leakage mode, maintain memory contents.
 * DS = 0x2 - Deep Sleep Mode. Low leakage mode, maintain memory contents.
 * SD = 0x4 - Shut Down Mode. Shut Down periphery and core, no memory retention.
 */

#define BP_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN      (6)
#define BM_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN      (0x000001c0)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN(v)   ((((reg32_t) v) << 6) & BM_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN)
#else
#define BF_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN(v)   (((v) << 6) & BM_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_LP_STATE_WAY1_BANKN field to a new value.
#define BW_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN(v)   BF_CS1(EPXP_POWER, LUT_LP_STATE_WAY1_BANKN, v)
#endif

#define BV_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN__NONE (0x0) //!< Memory is not in low power state.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN__LS (0x1) //!< Light Sleep Mode. Low leakage mode, maintain memory contents.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN__DS (0x2) //!< Deep Sleep Mode. Low leakage mode, maintain memory contents.
#define BV_EPXP_POWER_LUT_LP_STATE_WAY1_BANKN__SD (0x4) //!< Shut Down Mode. Shut Down periphery and core, no memory retention.

/* --- Register HW_EPXP_POWER, field ROT_MEM_LP_STATE[11:9] (RW)
 *
 * Select the low power state of the ROT memory.
 *
 * Values:
 * NONE = 0x0 - Memory is not in low power state.
 * LS = 0x1 - Light Sleep Mode. Low leakage mode, maintain memory contents.
 * DS = 0x2 - Deep Sleep Mode. Low leakage mode, maintain memory contents.
 * SD = 0x4 - Shut Down Mode. Shut Down periphery and core, no memory retention.
 */

#define BP_EPXP_POWER_ROT_MEM_LP_STATE      (9)
#define BM_EPXP_POWER_ROT_MEM_LP_STATE      (0x00000e00)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_POWER_ROT_MEM_LP_STATE(v)   ((((reg32_t) v) << 9) & BM_EPXP_POWER_ROT_MEM_LP_STATE)
#else
#define BF_EPXP_POWER_ROT_MEM_LP_STATE(v)   (((v) << 9) & BM_EPXP_POWER_ROT_MEM_LP_STATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROT_MEM_LP_STATE field to a new value.
#define BW_EPXP_POWER_ROT_MEM_LP_STATE(v)   BF_CS1(EPXP_POWER, ROT_MEM_LP_STATE, v)
#endif

#define BV_EPXP_POWER_ROT_MEM_LP_STATE__NONE (0x0) //!< Memory is not in low power state.
#define BV_EPXP_POWER_ROT_MEM_LP_STATE__LS (0x1) //!< Light Sleep Mode. Low leakage mode, maintain memory contents.
#define BV_EPXP_POWER_ROT_MEM_LP_STATE__DS (0x2) //!< Deep Sleep Mode. Low leakage mode, maintain memory contents.
#define BV_EPXP_POWER_ROT_MEM_LP_STATE__SD (0x4) //!< Shut Down Mode. Shut Down periphery and core, no memory retention.

/* --- Register HW_EPXP_POWER, field CTRL[31:12] (RW)
 *
 * This register contains power control for the PXP.
 */

#define BP_EPXP_POWER_CTRL      (12)
#define BM_EPXP_POWER_CTRL      (0xfffff000)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_POWER_CTRL(v)   ((((reg32_t) v) << 12) & BM_EPXP_POWER_CTRL)
#else
#define BF_EPXP_POWER_CTRL(v)   (((v) << 12) & BM_EPXP_POWER_CTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTRL field to a new value.
#define BW_EPXP_POWER_CTRL(v)   BF_CS1(EPXP_POWER, CTRL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPXP_NEXT - Next Frame Pointer (RW)
 *
 * This register contains a pointer to a data structure used to reload the PXP registers at the end
 * of the current frame.  To enable this functionality, software must write this register while the
 * PXP is processing the current data frame (if the PXP is currently idle, this will also initiate
 * an immediate load of registers from the pointer). The process of writing this register (WRITE
 * operation) will set a semaphore in hardware to notify the control logic that a register reload
 * operation must be performed when the current frame processing is complete. At the end of a frame,
 * the PXP will fetch the register settings from this location, signal an interrupt to software,
 * then proceed with rendering the next frame of data. Software may cancel the reload operation by
 * issuing a CLEAR operation to this register. SET and TOGGLE operations should not be used when
 * addressing this register. All registers will be reloaded with the exception of the following:
 * STAT, CSCCOEFn, NEXT , VERSION . All other registers will be loaded in the order they appear in
 * the register map. Once the pointer's contents have been loaded into the PXP's registers, the
 * NEXT_IRQ interrupt will be issued (see the PXP_STATUS register).   EXAMPLE   // create register
 * command structure in memory u32* pxp_commands0[48], pxp_commands1; u32 rc; // initialize control
 * structure for frame 0 pxp_commands0[0] = ...; // CTRL pxp_commands0[1] = ...; // OUT Buffer ...
 * pxp_commands0[47] = ..; // Overlay7 param2 // initialize control structure for frame 1
 * pxp_commands1[0] = ...; // CTRL pxp_commands1[1] = ...; // OUT Buffer ... pxp_commands1[47] = ..;
 * // Overlay7 param2 // poll until a command isn't queued while (rc=PXP_NEXT_RD() &
 * BM_PXP_NEXT_ENABLED ); PXP_NEXT_WR(pxp_commands0); // enable PXP operation 0 via command pointer
 * // poll until first command clears while (rc=PXP_NEXT_RD() & BM_PXP_NEXT_ENABLED );
 * PXP_NEXT_WR(pxp_commands1); // enable PXP operation 1 via command pointer
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENABLED : 1; //!< Indicates that the "next frame" functionality has been enabled. This bit reflects the status of the hardware semaphore indicating that a reload operation is pending at the end of the current frame.
        unsigned RESERVED0 : 1; //!< Reserved, always set to zero.
        unsigned POINTER : 30; //!< A pointer to a data structure containing register values to be used when processing the next frame. The pointer must be 32-bit aligned and should reside in on-chip or off-chip memory.
    } B;
} hw_epxp_next_t;
#endif

/*
 * constants & macros for entire EPXP_NEXT register
 */
#define HW_EPXP_NEXT_ADDR      (REGS_EPXP_BASE + 0x400)
#define HW_EPXP_NEXT_SET_ADDR  (HW_EPXP_NEXT_ADDR + 0x4)
#define HW_EPXP_NEXT_CLR_ADDR  (HW_EPXP_NEXT_ADDR + 0x8)
#define HW_EPXP_NEXT_TOG_ADDR  (HW_EPXP_NEXT_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_EPXP_NEXT           (*(volatile hw_epxp_next_t *) HW_EPXP_NEXT_ADDR)
#define HW_EPXP_NEXT_RD()      (HW_EPXP_NEXT.U)
#define HW_EPXP_NEXT_WR(v)     (HW_EPXP_NEXT.U = (v))
#define HW_GPMI_CTRL0_SET(v)    ((*(volatile reg32_t *) HW_EPXP_NEXT_SET_ADDR) = (v))
#define HW_EPXP_NEXT_CLR(v)    ((*(volatile reg32_t *) HW_EPXP_NEXT_CLR_ADDR) = (v))
#define HW_EPXP_NEXT_TOG(v)    ((*(volatile reg32_t *) HW_EPXP_NEXT_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual EPXP_NEXT bitfields
 */

/* --- Register HW_EPXP_NEXT, field ENABLED[0:0] (RO)
 *
 * Indicates that the "next frame" functionality has been enabled. This bit reflects the status of
 * the hardware semaphore indicating that a reload operation is pending at the end of the current
 * frame.
 */

#define BP_EPXP_NEXT_ENABLED      (0)
#define BM_EPXP_NEXT_ENABLED      (0x00000001)

/* --- Register HW_EPXP_NEXT, field POINTER[31:2] (RW)
 *
 * A pointer to a data structure containing register values to be used when processing the next
 * frame. The pointer must be 32-bit aligned and should reside in on-chip or off-chip memory.
 */

#define BP_EPXP_NEXT_POINTER      (2)
#define BM_EPXP_NEXT_POINTER      (0xfffffffc)

#ifndef __LANGUAGE_ASM__
#define BF_EPXP_NEXT_POINTER(v)   ((((reg32_t) v) << 2) & BM_EPXP_NEXT_POINTER)
#else
#define BF_EPXP_NEXT_POINTER(v)   (((v) << 2) & BM_EPXP_NEXT_POINTER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POINTER field to a new value.
#define BW_EPXP_NEXT_POINTER(v)   BF_CS1(EPXP_NEXT, POINTER, v)
#endif


/*!
 * @brief All EPXP module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_epxp_ctrl_t CTRL; //!< Control Register 0
    volatile reg32_t CTRL_SET; //!< Control Register 0 Set
    volatile reg32_t CTRL_CLR; //!< Control Register 0 Clear
    volatile reg32_t CTRL_TOG; //!< Control Register 0 Toggle
    volatile hw_epxp_stat_t STAT; //!< Status Register
    volatile reg32_t STAT_SET; //!< Status Register Set
    volatile reg32_t STAT_CLR; //!< Status Register Clear
    volatile reg32_t STAT_TOG; //!< Status Register Toggle
    volatile hw_epxp_out_ctrl_t OUT_CTRL; //!< Output Buffer Control Register
    volatile reg32_t OUT_CTRL_SET; //!< Output Buffer Control Register Set
    volatile reg32_t OUT_CTRL_CLR; //!< Output Buffer Control Register Clear
    volatile reg32_t OUT_CTRL_TOG; //!< Output Buffer Control Register Toggle
    volatile hw_epxp_out_buf_t OUT_BUF; //!< Output Frame Buffer Pointer
    volatile reg32_t OUT_BUF_SET; //!< Output Frame Buffer Pointer Set
    volatile reg32_t OUT_BUF_CLR; //!< Output Frame Buffer Pointer Clear
    volatile reg32_t OUT_BUF_TOG; //!< Output Frame Buffer Pointer Toggle
    volatile hw_epxp_out_buf2_t OUT_BUF2; //!< Output Frame Buffer Pointer #2
    volatile reg32_t OUT_BUF2_SET; //!< Output Frame Buffer Pointer #2 Set
    volatile reg32_t OUT_BUF2_CLR; //!< Output Frame Buffer Pointer #2 Clear
    volatile reg32_t OUT_BUF2_TOG; //!< Output Frame Buffer Pointer #2 Toggle
    volatile hw_epxp_out_pitch_t OUT_PITCH; //!< Output Buffer Pitch
    volatile reg32_t OUT_PITCH_SET; //!< Output Buffer Pitch Set
    volatile reg32_t OUT_PITCH_CLR; //!< Output Buffer Pitch Clear
    volatile reg32_t OUT_PITCH_TOG; //!< Output Buffer Pitch Toggle
    volatile hw_epxp_out_lrc_t OUT_LRC; //!< Output Surface Lower Right Coordinate
    volatile reg32_t OUT_LRC_SET; //!< Output Surface Lower Right Coordinate Set
    volatile reg32_t OUT_LRC_CLR; //!< Output Surface Lower Right Coordinate Clear
    volatile reg32_t OUT_LRC_TOG; //!< Output Surface Lower Right Coordinate Toggle
    volatile hw_epxp_out_ps_ulc_t OUT_PS_ULC; //!< Processed Surface Upper Left Coordinate
    volatile reg32_t OUT_PS_ULC_SET; //!< Processed Surface Upper Left Coordinate Set
    volatile reg32_t OUT_PS_ULC_CLR; //!< Processed Surface Upper Left Coordinate Clear
    volatile reg32_t OUT_PS_ULC_TOG; //!< Processed Surface Upper Left Coordinate Toggle
    volatile hw_epxp_out_ps_lrc_t OUT_PS_LRC; //!< Processed Surface Lower Right Coordinate
    volatile reg32_t OUT_PS_LRC_SET; //!< Processed Surface Lower Right Coordinate Set
    volatile reg32_t OUT_PS_LRC_CLR; //!< Processed Surface Lower Right Coordinate Clear
    volatile reg32_t OUT_PS_LRC_TOG; //!< Processed Surface Lower Right Coordinate Toggle
    volatile hw_epxp_out_as_ulc_t OUT_AS_ULC; //!< Alpha Surface Upper Left Coordinate
    volatile reg32_t OUT_AS_ULC_SET; //!< Alpha Surface Upper Left Coordinate Set
    volatile reg32_t OUT_AS_ULC_CLR; //!< Alpha Surface Upper Left Coordinate Clear
    volatile reg32_t OUT_AS_ULC_TOG; //!< Alpha Surface Upper Left Coordinate Toggle
    volatile hw_epxp_out_as_lrc_t OUT_AS_LRC; //!< Alpha Surface Lower Right Coordinate
    volatile reg32_t OUT_AS_LRC_SET; //!< Alpha Surface Lower Right Coordinate Set
    volatile reg32_t OUT_AS_LRC_CLR; //!< Alpha Surface Lower Right Coordinate Clear
    volatile reg32_t OUT_AS_LRC_TOG; //!< Alpha Surface Lower Right Coordinate Toggle
    volatile hw_epxp_ps_ctrl_t PS_CTRL; //!< Processed Surface (PS) Control Register
    volatile reg32_t PS_CTRL_SET; //!< Processed Surface (PS) Control Register Set
    volatile reg32_t PS_CTRL_CLR; //!< Processed Surface (PS) Control Register Clear
    volatile reg32_t PS_CTRL_TOG; //!< Processed Surface (PS) Control Register Toggle
    volatile hw_epxp_ps_buf_t PS_BUF; //!< PS Input Buffer Address
    volatile reg32_t PS_BUF_SET; //!< PS Input Buffer Address Set
    volatile reg32_t PS_BUF_CLR; //!< PS Input Buffer Address Clear
    volatile reg32_t PS_BUF_TOG; //!< PS Input Buffer Address Toggle
    volatile hw_epxp_ps_ubuf_t PS_UBUF; //!< PS U/Cb or 2 Plane UV Input Buffer Address
    volatile reg32_t PS_UBUF_SET; //!< PS U/Cb or 2 Plane UV Input Buffer Address Set
    volatile reg32_t PS_UBUF_CLR; //!< PS U/Cb or 2 Plane UV Input Buffer Address Clear
    volatile reg32_t PS_UBUF_TOG; //!< PS U/Cb or 2 Plane UV Input Buffer Address Toggle
    volatile hw_epxp_ps_vbuf_t PS_VBUF; //!< PS V/Cr Input Buffer Address
    volatile reg32_t PS_VBUF_SET; //!< PS V/Cr Input Buffer Address Set
    volatile reg32_t PS_VBUF_CLR; //!< PS V/Cr Input Buffer Address Clear
    volatile reg32_t PS_VBUF_TOG; //!< PS V/Cr Input Buffer Address Toggle
    volatile hw_epxp_ps_pitch_t PS_PITCH; //!< Processed Surface Pitch
    volatile reg32_t PS_PITCH_SET; //!< Processed Surface Pitch Set
    volatile reg32_t PS_PITCH_CLR; //!< Processed Surface Pitch Clear
    volatile reg32_t PS_PITCH_TOG; //!< Processed Surface Pitch Toggle
    volatile hw_epxp_ps_background_t PS_BACKGROUND; //!< PS Background Color
    volatile reg32_t PS_BACKGROUND_SET; //!< PS Background Color Set
    volatile reg32_t PS_BACKGROUND_CLR; //!< PS Background Color Clear
    volatile reg32_t PS_BACKGROUND_TOG; //!< PS Background Color Toggle
    volatile hw_epxp_ps_scale_t PS_SCALE; //!< PS Scale Factor Register
    volatile reg32_t PS_SCALE_SET; //!< PS Scale Factor Register Set
    volatile reg32_t PS_SCALE_CLR; //!< PS Scale Factor Register Clear
    volatile reg32_t PS_SCALE_TOG; //!< PS Scale Factor Register Toggle
    volatile hw_epxp_ps_offset_t PS_OFFSET; //!< PS Scale Offset Register
    volatile reg32_t PS_OFFSET_SET; //!< PS Scale Offset Register Set
    volatile reg32_t PS_OFFSET_CLR; //!< PS Scale Offset Register Clear
    volatile reg32_t PS_OFFSET_TOG; //!< PS Scale Offset Register Toggle
    volatile hw_epxp_ps_clrkeylow_t PS_CLRKEYLOW; //!< PS Color Key Low
    volatile reg32_t PS_CLRKEYLOW_SET; //!< PS Color Key Low Set
    volatile reg32_t PS_CLRKEYLOW_CLR; //!< PS Color Key Low Clear
    volatile reg32_t PS_CLRKEYLOW_TOG; //!< PS Color Key Low Toggle
    volatile hw_epxp_ps_clrkeyhigh_t PS_CLRKEYHIGH; //!< PS Color Key High
    volatile reg32_t PS_CLRKEYHIGH_SET; //!< PS Color Key High Set
    volatile reg32_t PS_CLRKEYHIGH_CLR; //!< PS Color Key High Clear
    volatile reg32_t PS_CLRKEYHIGH_TOG; //!< PS Color Key High Toggle
    volatile hw_epxp_as_ctrl_t AS_CTRL; //!< Alpha Surface Control
    volatile reg32_t AS_CTRL_SET; //!< Alpha Surface Control Set
    volatile reg32_t AS_CTRL_CLR; //!< Alpha Surface Control Clear
    volatile reg32_t AS_CTRL_TOG; //!< Alpha Surface Control Toggle
    volatile hw_epxp_as_buf_t AS_BUF; //!< Alpha Surface Buffer Pointer
    volatile reg32_t AS_BUF_SET; //!< Alpha Surface Buffer Pointer Set
    volatile reg32_t AS_BUF_CLR; //!< Alpha Surface Buffer Pointer Clear
    volatile reg32_t AS_BUF_TOG; //!< Alpha Surface Buffer Pointer Toggle
    volatile hw_epxp_as_pitch_t AS_PITCH; //!< Alpha Surface Pitch
    volatile reg32_t AS_PITCH_SET; //!< Alpha Surface Pitch Set
    volatile reg32_t AS_PITCH_CLR; //!< Alpha Surface Pitch Clear
    volatile reg32_t AS_PITCH_TOG; //!< Alpha Surface Pitch Toggle
    volatile hw_epxp_as_clrkeylow_t AS_CLRKEYLOW; //!< Overlay Color Key Low
    volatile reg32_t AS_CLRKEYLOW_SET; //!< Overlay Color Key Low Set
    volatile reg32_t AS_CLRKEYLOW_CLR; //!< Overlay Color Key Low Clear
    volatile reg32_t AS_CLRKEYLOW_TOG; //!< Overlay Color Key Low Toggle
    volatile hw_epxp_as_clrkeyhigh_t AS_CLRKEYHIGH; //!< Overlay Color Key High
    volatile reg32_t AS_CLRKEYHIGH_SET; //!< Overlay Color Key High Set
    volatile reg32_t AS_CLRKEYHIGH_CLR; //!< Overlay Color Key High Clear
    volatile reg32_t AS_CLRKEYHIGH_TOG; //!< Overlay Color Key High Toggle
    volatile hw_epxp_csc1_coef0_t CSC1_COEF0; //!< Color Space Conversion Coefficient Register 0
    volatile reg32_t CSC1_COEF0_SET; //!< Color Space Conversion Coefficient Register 0 Set
    volatile reg32_t CSC1_COEF0_CLR; //!< Color Space Conversion Coefficient Register 0 Clear
    volatile reg32_t CSC1_COEF0_TOG; //!< Color Space Conversion Coefficient Register 0 Toggle
    volatile hw_epxp_csc1_coef1_t CSC1_COEF1; //!< Color Space Conversion Coefficient Register 1
    volatile reg32_t CSC1_COEF1_SET; //!< Color Space Conversion Coefficient Register 1 Set
    volatile reg32_t CSC1_COEF1_CLR; //!< Color Space Conversion Coefficient Register 1 Clear
    volatile reg32_t CSC1_COEF1_TOG; //!< Color Space Conversion Coefficient Register 1 Toggle
    volatile hw_epxp_csc1_coef2_t CSC1_COEF2; //!< Color Space Conversion Coefficient Register 2
    volatile reg32_t CSC1_COEF2_SET; //!< Color Space Conversion Coefficient Register 2 Set
    volatile reg32_t CSC1_COEF2_CLR; //!< Color Space Conversion Coefficient Register 2 Clear
    volatile reg32_t CSC1_COEF2_TOG; //!< Color Space Conversion Coefficient Register 2 Toggle
    volatile hw_epxp_csc2_ctrl_t CSC2_CTRL; //!< Color Space Conversion Control Register.
    volatile reg32_t CSC2_CTRL_SET; //!< Color Space Conversion Control Register. Set
    volatile reg32_t CSC2_CTRL_CLR; //!< Color Space Conversion Control Register. Clear
    volatile reg32_t CSC2_CTRL_TOG; //!< Color Space Conversion Control Register. Toggle
    volatile hw_epxp_csc2_coef0_t CSC2_COEF0; //!< Color Space Conversion Coefficient Register 0
    volatile reg32_t CSC2_COEF0_SET; //!< Color Space Conversion Coefficient Register 0 Set
    volatile reg32_t CSC2_COEF0_CLR; //!< Color Space Conversion Coefficient Register 0 Clear
    volatile reg32_t CSC2_COEF0_TOG; //!< Color Space Conversion Coefficient Register 0 Toggle
    volatile hw_epxp_csc2_coef1_t CSC2_COEF1; //!< Color Space Conversion Coefficient Register 1
    volatile reg32_t CSC2_COEF1_SET; //!< Color Space Conversion Coefficient Register 1 Set
    volatile reg32_t CSC2_COEF1_CLR; //!< Color Space Conversion Coefficient Register 1 Clear
    volatile reg32_t CSC2_COEF1_TOG; //!< Color Space Conversion Coefficient Register 1 Toggle
    volatile hw_epxp_csc2_coef2_t CSC2_COEF2; //!< Color Space Conversion Coefficient Register 2
    volatile reg32_t CSC2_COEF2_SET; //!< Color Space Conversion Coefficient Register 2 Set
    volatile reg32_t CSC2_COEF2_CLR; //!< Color Space Conversion Coefficient Register 2 Clear
    volatile reg32_t CSC2_COEF2_TOG; //!< Color Space Conversion Coefficient Register 2 Toggle
    volatile hw_epxp_csc2_coef3_t CSC2_COEF3; //!< Color Space Conversion Coefficient Register 3
    volatile reg32_t CSC2_COEF3_SET; //!< Color Space Conversion Coefficient Register 3 Set
    volatile reg32_t CSC2_COEF3_CLR; //!< Color Space Conversion Coefficient Register 3 Clear
    volatile reg32_t CSC2_COEF3_TOG; //!< Color Space Conversion Coefficient Register 3 Toggle
    volatile hw_epxp_csc2_coef4_t CSC2_COEF4; //!< Color Space Conversion Coefficient Register 4
    volatile reg32_t CSC2_COEF4_SET; //!< Color Space Conversion Coefficient Register 4 Set
    volatile reg32_t CSC2_COEF4_CLR; //!< Color Space Conversion Coefficient Register 4 Clear
    volatile reg32_t CSC2_COEF4_TOG; //!< Color Space Conversion Coefficient Register 4 Toggle
    volatile hw_epxp_csc2_coef5_t CSC2_COEF5; //!< Color Space Conversion Coefficient Register 5
    volatile reg32_t CSC2_COEF5_SET; //!< Color Space Conversion Coefficient Register 5 Set
    volatile reg32_t CSC2_COEF5_CLR; //!< Color Space Conversion Coefficient Register 5 Clear
    volatile reg32_t CSC2_COEF5_TOG; //!< Color Space Conversion Coefficient Register 5 Toggle
    volatile hw_epxp_lut_ctrl_t LUT_CTRL; //!< Lookup Table Control Register.
    volatile reg32_t LUT_CTRL_SET; //!< Lookup Table Control Register. Set
    volatile reg32_t LUT_CTRL_CLR; //!< Lookup Table Control Register. Clear
    volatile reg32_t LUT_CTRL_TOG; //!< Lookup Table Control Register. Toggle
    volatile hw_epxp_lut_addr_t LUT_ADDR; //!< Lookup Table Control Register.
    volatile reg32_t LUT_ADDR_SET; //!< Lookup Table Control Register. Set
    volatile reg32_t LUT_ADDR_CLR; //!< Lookup Table Control Register. Clear
    volatile reg32_t LUT_ADDR_TOG; //!< Lookup Table Control Register. Toggle
    volatile hw_epxp_lut_data_t LUT_DATA; //!< Lookup Table Data Register.
    volatile reg32_t LUT_DATA_SET; //!< Lookup Table Data Register. Set
    volatile reg32_t LUT_DATA_CLR; //!< Lookup Table Data Register. Clear
    volatile reg32_t LUT_DATA_TOG; //!< Lookup Table Data Register. Toggle
    volatile hw_epxp_lut_extmem_t LUT_EXTMEM; //!< Lookup Table External Memory Address Register.
    volatile reg32_t LUT_EXTMEM_SET; //!< Lookup Table External Memory Address Register. Set
    volatile reg32_t LUT_EXTMEM_CLR; //!< Lookup Table External Memory Address Register. Clear
    volatile reg32_t LUT_EXTMEM_TOG; //!< Lookup Table External Memory Address Register. Toggle
    volatile hw_epxp_cfa_t CFA; //!< Color Filter Array Register.
    volatile reg32_t CFA_SET; //!< Color Filter Array Register. Set
    volatile reg32_t CFA_CLR; //!< Color Filter Array Register. Clear
    volatile reg32_t CFA_TOG; //!< Color Filter Array Register. Toggle
    volatile hw_epxp_hist_ctrl_t HIST_CTRL; //!< Histogram Control Register.
    volatile reg32_t HIST_CTRL_SET; //!< Histogram Control Register. Set
    volatile reg32_t HIST_CTRL_CLR; //!< Histogram Control Register. Clear
    volatile reg32_t HIST_CTRL_TOG; //!< Histogram Control Register. Toggle
    volatile hw_epxp_hist2_param_t HIST2_PARAM; //!< 2-level Histogram Parameter Register.
    volatile reg32_t HIST2_PARAM_SET; //!< 2-level Histogram Parameter Register. Set
    volatile reg32_t HIST2_PARAM_CLR; //!< 2-level Histogram Parameter Register. Clear
    volatile reg32_t HIST2_PARAM_TOG; //!< 2-level Histogram Parameter Register. Toggle
    volatile hw_epxp_hist4_param_t HIST4_PARAM; //!< 4-level Histogram Parameter Register.
    volatile reg32_t HIST4_PARAM_SET; //!< 4-level Histogram Parameter Register. Set
    volatile reg32_t HIST4_PARAM_CLR; //!< 4-level Histogram Parameter Register. Clear
    volatile reg32_t HIST4_PARAM_TOG; //!< 4-level Histogram Parameter Register. Toggle
    volatile hw_epxp_hist8_param0_t HIST8_PARAM0; //!< 8-level Histogram Parameter 0 Register.
    volatile reg32_t HIST8_PARAM0_SET; //!< 8-level Histogram Parameter 0 Register. Set
    volatile reg32_t HIST8_PARAM0_CLR; //!< 8-level Histogram Parameter 0 Register. Clear
    volatile reg32_t HIST8_PARAM0_TOG; //!< 8-level Histogram Parameter 0 Register. Toggle
    volatile hw_epxp_hist8_param1_t HIST8_PARAM1; //!< 8-level Histogram Parameter 1 Register.
    volatile reg32_t HIST8_PARAM1_SET; //!< 8-level Histogram Parameter 1 Register. Set
    volatile reg32_t HIST8_PARAM1_CLR; //!< 8-level Histogram Parameter 1 Register. Clear
    volatile reg32_t HIST8_PARAM1_TOG; //!< 8-level Histogram Parameter 1 Register. Toggle
    volatile hw_epxp_hist16_param0_t HIST16_PARAM0; //!< 16-level Histogram Parameter 0 Register.
    volatile reg32_t HIST16_PARAM0_SET; //!< 16-level Histogram Parameter 0 Register. Set
    volatile reg32_t HIST16_PARAM0_CLR; //!< 16-level Histogram Parameter 0 Register. Clear
    volatile reg32_t HIST16_PARAM0_TOG; //!< 16-level Histogram Parameter 0 Register. Toggle
    volatile hw_epxp_hist16_param1_t HIST16_PARAM1; //!< 16-level Histogram Parameter 1 Register.
    volatile reg32_t HIST16_PARAM1_SET; //!< 16-level Histogram Parameter 1 Register. Set
    volatile reg32_t HIST16_PARAM1_CLR; //!< 16-level Histogram Parameter 1 Register. Clear
    volatile reg32_t HIST16_PARAM1_TOG; //!< 16-level Histogram Parameter 1 Register. Toggle
    volatile hw_epxp_hist16_param2_t HIST16_PARAM2; //!< 16-level Histogram Parameter 2 Register.
    volatile reg32_t HIST16_PARAM2_SET; //!< 16-level Histogram Parameter 2 Register. Set
    volatile reg32_t HIST16_PARAM2_CLR; //!< 16-level Histogram Parameter 2 Register. Clear
    volatile reg32_t HIST16_PARAM2_TOG; //!< 16-level Histogram Parameter 2 Register. Toggle
    volatile hw_epxp_hist16_param3_t HIST16_PARAM3; //!< 16-level Histogram Parameter 3 Register.
    volatile reg32_t HIST16_PARAM3_SET; //!< 16-level Histogram Parameter 3 Register. Set
    volatile reg32_t HIST16_PARAM3_CLR; //!< 16-level Histogram Parameter 3 Register. Clear
    volatile reg32_t HIST16_PARAM3_TOG; //!< 16-level Histogram Parameter 3 Register. Toggle
    volatile hw_epxp_power_t POWER; //!< PXP Power Control Register.
    volatile reg32_t POWER_SET; //!< PXP Power Control Register. Set
    volatile reg32_t POWER_CLR; //!< PXP Power Control Register. Clear
    volatile reg32_t POWER_TOG; //!< PXP Power Control Register. Toggle
    reg32_t _reserved0[52];
    volatile hw_epxp_next_t NEXT; //!< Next Frame Pointer
    volatile reg32_t NEXT_SET; //!< Next Frame Pointer Set
    volatile reg32_t NEXT_CLR; //!< Next Frame Pointer Clear
    volatile reg32_t NEXT_TOG; //!< Next Frame Pointer Toggle
} hw_epxp_t;
#endif

//! @brief Macro to access all EPXP registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_EPXP(0)</code>.
#define HW_EPXP     (*(volatile hw_epxp_t *) REGS_EPXP_BASE)


#endif // _EPXP_H
