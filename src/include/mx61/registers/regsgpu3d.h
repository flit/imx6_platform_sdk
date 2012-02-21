/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _GPU3D_H
#define _GPU3D_H

#include "regs.h"

#ifndef REGS_GPU3D_BASE
#define REGS_GPU3D_BASE (REGS_BASE + 0x00130000)
#endif


/*!
 * @brief HW_GPU3D_AQH_CLK_CTRL - AQHiClockControl
 *
 * Clock control register.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CLK3D_DIS : 1; //!< Disable 3D clock.
        unsigned CLK2D_DIS : 1; //!< Disable 2D clock.
        unsigned FSCALE_VAL : 7; //!< 
        unsigned FSCALE_CMD_LOAD : 1; //!< 
        unsigned DISABLE_RAM_CLOCK_GATING : 1; //!< Disables clock gating for rams.
        unsigned DISABLE_DEBUG_REGISTERS : 1; //!< Disable debug registers. If this bit is 1, debug registers are clock gated.
        unsigned SOFT_RESET : 1; //!< Soft resets the IP.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned IDLE3_D : 1; //!< 3D pipe is idle.
        unsigned IDLE2_D : 1; //!< 2D pipe is idle.
        unsigned IDLE_VG : 1; //!< VG is idle.
        unsigned ISOLATE_GPU : 1; //!< Isolate GPU bit
        unsigned MULTI_PIPE_REG_SELECT : 4; //!< Determines which HI/MC to use while reading registers.
        unsigned MULTI_PIPE_USE_SINGLE_AXI : 4; //!< Force all the transactions to go to one AXI
        unsigned RESERVED1 : 4; //!< Reserved
    } B;
} hw_gpu3d_aqh_clk_ctrl_t;
#endif

/*
 * constants & macros for entire GPU3D_AQH_CLK_CTRL register
 */
#define HW_GPU3D_AQH_CLK_CTRL_ADDR      (REGS_GPU3D_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_AQH_CLK_CTRL           (*(volatile hw_gpu3d_aqh_clk_ctrl_t *) HW_GPU3D_AQH_CLK_CTRL_ADDR)
#define HW_GPU3D_AQH_CLK_CTRL_RD()      (HW_GPU3D_AQH_CLK_CTRL.U)
#define HW_GPU3D_AQH_CLK_CTRL_WR(v)     (HW_GPU3D_AQH_CLK_CTRL.U = (v))
#define HW_GPU3D_AQH_CLK_CTRL_SET(v)    (HW_GPU3D_AQH_CLK_CTRL_WR(HW_GPU3D_AQH_CLK_CTRL_RD() |  (v)))
#define HW_GPU3D_AQH_CLK_CTRL_CLR(v)    (HW_GPU3D_AQH_CLK_CTRL_WR(HW_GPU3D_AQH_CLK_CTRL_RD() & ~(v)))
#define HW_GPU3D_AQH_CLK_CTRL_TOG(v)    (HW_GPU3D_AQH_CLK_CTRL_WR(HW_GPU3D_AQH_CLK_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_AQH_CLK_CTRL bitfields
 */

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field CLK3D_DIS
 *
 * Disable 3D clock.
 */

#define BP_GPU3D_AQH_CLK_CTRL_CLK3D_DIS      0
#define BM_GPU3D_AQH_CLK_CTRL_CLK3D_DIS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_CLK3D_DIS(v)   ((((reg32_t) v) << 0) & BM_GPU3D_AQH_CLK_CTRL_CLK3D_DIS)
#else
#define BF_GPU3D_AQH_CLK_CTRL_CLK3D_DIS(v)   (((v) << 0) & BM_GPU3D_AQH_CLK_CTRL_CLK3D_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_CLK3D_DIS(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, CLK3D_DIS, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field CLK2D_DIS
 *
 * Disable 2D clock.
 */

#define BP_GPU3D_AQH_CLK_CTRL_CLK2D_DIS      1
#define BM_GPU3D_AQH_CLK_CTRL_CLK2D_DIS      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_CLK2D_DIS(v)   ((((reg32_t) v) << 1) & BM_GPU3D_AQH_CLK_CTRL_CLK2D_DIS)
#else
#define BF_GPU3D_AQH_CLK_CTRL_CLK2D_DIS(v)   (((v) << 1) & BM_GPU3D_AQH_CLK_CTRL_CLK2D_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_CLK2D_DIS(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, CLK2D_DIS, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field FSCALE_VAL
 *

 */

#define BP_GPU3D_AQH_CLK_CTRL_FSCALE_VAL      2
#define BM_GPU3D_AQH_CLK_CTRL_FSCALE_VAL      0x000001fc

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(v)   ((((reg32_t) v) << 2) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_VAL)
#else
#define BF_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(v)   (((v) << 2) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, FSCALE_VAL, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field FSCALE_CMD_LOAD
 *

 */

#define BP_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD      9
#define BM_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(v)   ((((reg32_t) v) << 9) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD)
#else
#define BF_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(v)   (((v) << 9) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, FSCALE_CMD_LOAD, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field DISABLE_RAM_CLOCK_GATING
 *
 * Disables clock gating for rams.
 */

#define BP_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING      10
#define BM_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING(v)   ((((reg32_t) v) << 10) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING)
#else
#define BF_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING(v)   (((v) << 10) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, DISABLE_RAM_CLOCK_GATING, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field DISABLE_DEBUG_REGISTERS
 *
 * Disable debug registers. If this bit is 1, debug registers are clock gated.
 */

#define BP_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS      11
#define BM_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS(v)   ((((reg32_t) v) << 11) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS)
#else
#define BF_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS(v)   (((v) << 11) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, DISABLE_DEBUG_REGISTERS, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field SOFT_RESET
 *
 * Soft resets the IP.
 */

#define BP_GPU3D_AQH_CLK_CTRL_SOFT_RESET      12
#define BM_GPU3D_AQH_CLK_CTRL_SOFT_RESET      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_SOFT_RESET(v)   ((((reg32_t) v) << 12) & BM_GPU3D_AQH_CLK_CTRL_SOFT_RESET)
#else
#define BF_GPU3D_AQH_CLK_CTRL_SOFT_RESET(v)   (((v) << 12) & BM_GPU3D_AQH_CLK_CTRL_SOFT_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_SOFT_RESET(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, SOFT_RESET, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field IDLE3_D
 *
 * 3D pipe is idle.
 */

#define BP_GPU3D_AQH_CLK_CTRL_IDLE3_D      16
#define BM_GPU3D_AQH_CLK_CTRL_IDLE3_D      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_IDLE3_D(v)   ((((reg32_t) v) << 16) & BM_GPU3D_AQH_CLK_CTRL_IDLE3_D)
#else
#define BF_GPU3D_AQH_CLK_CTRL_IDLE3_D(v)   (((v) << 16) & BM_GPU3D_AQH_CLK_CTRL_IDLE3_D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_IDLE3_D(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, IDLE3_D, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field IDLE2_D
 *
 * 2D pipe is idle.
 */

#define BP_GPU3D_AQH_CLK_CTRL_IDLE2_D      17
#define BM_GPU3D_AQH_CLK_CTRL_IDLE2_D      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_IDLE2_D(v)   ((((reg32_t) v) << 17) & BM_GPU3D_AQH_CLK_CTRL_IDLE2_D)
#else
#define BF_GPU3D_AQH_CLK_CTRL_IDLE2_D(v)   (((v) << 17) & BM_GPU3D_AQH_CLK_CTRL_IDLE2_D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_IDLE2_D(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, IDLE2_D, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field IDLE_VG
 *
 * VG is idle.
 */

#define BP_GPU3D_AQH_CLK_CTRL_IDLE_VG      18
#define BM_GPU3D_AQH_CLK_CTRL_IDLE_VG      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_IDLE_VG(v)   ((((reg32_t) v) << 18) & BM_GPU3D_AQH_CLK_CTRL_IDLE_VG)
#else
#define BF_GPU3D_AQH_CLK_CTRL_IDLE_VG(v)   (((v) << 18) & BM_GPU3D_AQH_CLK_CTRL_IDLE_VG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_IDLE_VG(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, IDLE_VG, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field ISOLATE_GPU
 *
 * Isolate GPU bit
 */

#define BP_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU      19
#define BM_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU(v)   ((((reg32_t) v) << 19) & BM_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU)
#else
#define BF_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU(v)   (((v) << 19) & BM_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, ISOLATE_GPU, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field MULTI_PIPE_REG_SELECT
 *
 * Determines which HI/MC to use while reading registers.
 */

#define BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT      20
#define BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT(v)   ((((reg32_t) v) << 20) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT)
#else
#define BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT(v)   (((v) << 20) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, MULTI_PIPE_REG_SELECT, v)
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field MULTI_PIPE_USE_SINGLE_AXI
 *
 * Force all the transactions to go to one AXI
 */

#define BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI      24
#define BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI(v)   ((((reg32_t) v) << 24) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI)
#else
#define BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI(v)   (((v) << 24) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI(v)   BF_CS1(GPU3D_AQH_CLK_CTRL, MULTI_PIPE_USE_SINGLE_AXI, v)
#endif

/*!
 * @brief HW_GPU3D_AQH_IDLE - AQHIdle
 *
 * Idle status register.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IDLE_FE : 1; //!< FE is idle.
        unsigned IDLE_DE : 1; //!< DE is idle.
        unsigned IDLE_PE : 1; //!< PE is idle.
        unsigned IDLE_SH : 1; //!< SH is idle.
        unsigned IDLE_PA : 1; //!< PA is idle.
        unsigned IDLE_SE : 1; //!< SE is idle.
        unsigned IDLE_RA : 1; //!< RA is idle.
        unsigned IDLE_TX : 1; //!< TX is idle.
        unsigned IDLE_VG : 1; //!< VG is idle.
        unsigned IDLE_IM : 1; //!< IM is idle.
        unsigned IDLE_FP : 1; //!< FP is idle.
        unsigned IDLE_TS : 1; //!< TS is idle.
        unsigned RESERVED0 : 19; //!< Unused bits reserved for future expansion.
        unsigned AXI_LP : 1; //!< AXI is in low power mode.
    } B;
} hw_gpu3d_aqh_idle_t;
#endif

/*
 * constants & macros for entire GPU3D_AQH_IDLE register
 */
#define HW_GPU3D_AQH_IDLE_ADDR      (REGS_GPU3D_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_AQH_IDLE           (*(volatile hw_gpu3d_aqh_idle_t *) HW_GPU3D_AQH_IDLE_ADDR)
#define HW_GPU3D_AQH_IDLE_RD()      (HW_GPU3D_AQH_IDLE.U)
#define HW_GPU3D_AQH_IDLE_WR(v)     (HW_GPU3D_AQH_IDLE.U = (v))
#define HW_GPU3D_AQH_IDLE_SET(v)    (HW_GPU3D_AQH_IDLE_WR(HW_GPU3D_AQH_IDLE_RD() |  (v)))
#define HW_GPU3D_AQH_IDLE_CLR(v)    (HW_GPU3D_AQH_IDLE_WR(HW_GPU3D_AQH_IDLE_RD() & ~(v)))
#define HW_GPU3D_AQH_IDLE_TOG(v)    (HW_GPU3D_AQH_IDLE_WR(HW_GPU3D_AQH_IDLE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_AQH_IDLE bitfields
 */

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_FE
 *
 * FE is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_FE      0
#define BM_GPU3D_AQH_IDLE_IDLE_FE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_FE(v)   ((((reg32_t) v) << 0) & BM_GPU3D_AQH_IDLE_IDLE_FE)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_FE(v)   (((v) << 0) & BM_GPU3D_AQH_IDLE_IDLE_FE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_FE(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_FE, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_DE
 *
 * DE is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_DE      1
#define BM_GPU3D_AQH_IDLE_IDLE_DE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_DE(v)   ((((reg32_t) v) << 1) & BM_GPU3D_AQH_IDLE_IDLE_DE)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_DE(v)   (((v) << 1) & BM_GPU3D_AQH_IDLE_IDLE_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_DE(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_DE, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_PE
 *
 * PE is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_PE      2
#define BM_GPU3D_AQH_IDLE_IDLE_PE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_PE(v)   ((((reg32_t) v) << 2) & BM_GPU3D_AQH_IDLE_IDLE_PE)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_PE(v)   (((v) << 2) & BM_GPU3D_AQH_IDLE_IDLE_PE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_PE(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_PE, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_SH
 *
 * SH is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_SH      3
#define BM_GPU3D_AQH_IDLE_IDLE_SH      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_SH(v)   ((((reg32_t) v) << 3) & BM_GPU3D_AQH_IDLE_IDLE_SH)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_SH(v)   (((v) << 3) & BM_GPU3D_AQH_IDLE_IDLE_SH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_SH(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_SH, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_PA
 *
 * PA is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_PA      4
#define BM_GPU3D_AQH_IDLE_IDLE_PA      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_PA(v)   ((((reg32_t) v) << 4) & BM_GPU3D_AQH_IDLE_IDLE_PA)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_PA(v)   (((v) << 4) & BM_GPU3D_AQH_IDLE_IDLE_PA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_PA(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_PA, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_SE
 *
 * SE is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_SE      5
#define BM_GPU3D_AQH_IDLE_IDLE_SE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_SE(v)   ((((reg32_t) v) << 5) & BM_GPU3D_AQH_IDLE_IDLE_SE)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_SE(v)   (((v) << 5) & BM_GPU3D_AQH_IDLE_IDLE_SE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_SE(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_SE, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_RA
 *
 * RA is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_RA      6
#define BM_GPU3D_AQH_IDLE_IDLE_RA      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_RA(v)   ((((reg32_t) v) << 6) & BM_GPU3D_AQH_IDLE_IDLE_RA)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_RA(v)   (((v) << 6) & BM_GPU3D_AQH_IDLE_IDLE_RA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_RA(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_RA, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_TX
 *
 * TX is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_TX      7
#define BM_GPU3D_AQH_IDLE_IDLE_TX      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_TX(v)   ((((reg32_t) v) << 7) & BM_GPU3D_AQH_IDLE_IDLE_TX)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_TX(v)   (((v) << 7) & BM_GPU3D_AQH_IDLE_IDLE_TX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_TX(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_TX, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_VG
 *
 * VG is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_VG      8
#define BM_GPU3D_AQH_IDLE_IDLE_VG      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_VG(v)   ((((reg32_t) v) << 8) & BM_GPU3D_AQH_IDLE_IDLE_VG)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_VG(v)   (((v) << 8) & BM_GPU3D_AQH_IDLE_IDLE_VG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_VG(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_VG, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_IM
 *
 * IM is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_IM      9
#define BM_GPU3D_AQH_IDLE_IDLE_IM      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_IM(v)   ((((reg32_t) v) << 9) & BM_GPU3D_AQH_IDLE_IDLE_IM)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_IM(v)   (((v) << 9) & BM_GPU3D_AQH_IDLE_IDLE_IM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_IM(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_IM, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_FP
 *
 * FP is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_FP      10
#define BM_GPU3D_AQH_IDLE_IDLE_FP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_FP(v)   ((((reg32_t) v) << 10) & BM_GPU3D_AQH_IDLE_IDLE_FP)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_FP(v)   (((v) << 10) & BM_GPU3D_AQH_IDLE_IDLE_FP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_FP(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_FP, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_TS
 *
 * TS is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_TS      11
#define BM_GPU3D_AQH_IDLE_IDLE_TS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_IDLE_TS(v)   ((((reg32_t) v) << 11) & BM_GPU3D_AQH_IDLE_IDLE_TS)
#else
#define BF_GPU3D_AQH_IDLE_IDLE_TS(v)   (((v) << 11) & BM_GPU3D_AQH_IDLE_IDLE_TS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_IDLE_TS(v)   BF_CS1(GPU3D_AQH_IDLE, IDLE_TS, v)
#endif

/* --- Register HW_GPU3D_AQH_IDLE, field AXI_LP
 *
 * AXI is in low power mode.
 */

#define BP_GPU3D_AQH_IDLE_AXI_LP      31
#define BM_GPU3D_AQH_IDLE_AXI_LP      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQH_IDLE_AXI_LP(v)   ((((reg32_t) v) << 31) & BM_GPU3D_AQH_IDLE_AXI_LP)
#else
#define BF_GPU3D_AQH_IDLE_AXI_LP(v)   (((v) << 31) & BM_GPU3D_AQH_IDLE_AXI_LP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQH_IDLE_AXI_LP(v)   BF_CS1(GPU3D_AQH_IDLE, AXI_LP, v)
#endif

/*!
 * @brief HW_GPU3D_AQA_CFG - AQAxiConfig
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AWID : 4; //!< 
        unsigned ARID : 4; //!< 
        unsigned AWCACHE : 4; //!< 
        unsigned ARCACHE : 4; //!< 
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_gpu3d_aqa_cfg_t;
#endif

/*
 * constants & macros for entire GPU3D_AQA_CFG register
 */
#define HW_GPU3D_AQA_CFG_ADDR      (REGS_GPU3D_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_AQA_CFG           (*(volatile hw_gpu3d_aqa_cfg_t *) HW_GPU3D_AQA_CFG_ADDR)
#define HW_GPU3D_AQA_CFG_RD()      (HW_GPU3D_AQA_CFG.U)
#define HW_GPU3D_AQA_CFG_WR(v)     (HW_GPU3D_AQA_CFG.U = (v))
#define HW_GPU3D_AQA_CFG_SET(v)    (HW_GPU3D_AQA_CFG_WR(HW_GPU3D_AQA_CFG_RD() |  (v)))
#define HW_GPU3D_AQA_CFG_CLR(v)    (HW_GPU3D_AQA_CFG_WR(HW_GPU3D_AQA_CFG_RD() & ~(v)))
#define HW_GPU3D_AQA_CFG_TOG(v)    (HW_GPU3D_AQA_CFG_WR(HW_GPU3D_AQA_CFG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_AQA_CFG bitfields
 */

/* --- Register HW_GPU3D_AQA_CFG, field AWID
 *

 */

#define BP_GPU3D_AQA_CFG_AWID      0
#define BM_GPU3D_AQA_CFG_AWID      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQA_CFG_AWID(v)   ((((reg32_t) v) << 0) & BM_GPU3D_AQA_CFG_AWID)
#else
#define BF_GPU3D_AQA_CFG_AWID(v)   (((v) << 0) & BM_GPU3D_AQA_CFG_AWID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQA_CFG_AWID(v)   BF_CS1(GPU3D_AQA_CFG, AWID, v)
#endif

/* --- Register HW_GPU3D_AQA_CFG, field ARID
 *

 */

#define BP_GPU3D_AQA_CFG_ARID      4
#define BM_GPU3D_AQA_CFG_ARID      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQA_CFG_ARID(v)   ((((reg32_t) v) << 4) & BM_GPU3D_AQA_CFG_ARID)
#else
#define BF_GPU3D_AQA_CFG_ARID(v)   (((v) << 4) & BM_GPU3D_AQA_CFG_ARID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQA_CFG_ARID(v)   BF_CS1(GPU3D_AQA_CFG, ARID, v)
#endif

/* --- Register HW_GPU3D_AQA_CFG, field AWCACHE
 *

 */

#define BP_GPU3D_AQA_CFG_AWCACHE      8
#define BM_GPU3D_AQA_CFG_AWCACHE      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQA_CFG_AWCACHE(v)   ((((reg32_t) v) << 8) & BM_GPU3D_AQA_CFG_AWCACHE)
#else
#define BF_GPU3D_AQA_CFG_AWCACHE(v)   (((v) << 8) & BM_GPU3D_AQA_CFG_AWCACHE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQA_CFG_AWCACHE(v)   BF_CS1(GPU3D_AQA_CFG, AWCACHE, v)
#endif

/* --- Register HW_GPU3D_AQA_CFG, field ARCACHE
 *

 */

#define BP_GPU3D_AQA_CFG_ARCACHE      12
#define BM_GPU3D_AQA_CFG_ARCACHE      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQA_CFG_ARCACHE(v)   ((((reg32_t) v) << 12) & BM_GPU3D_AQA_CFG_ARCACHE)
#else
#define BF_GPU3D_AQA_CFG_ARCACHE(v)   (((v) << 12) & BM_GPU3D_AQA_CFG_ARCACHE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQA_CFG_ARCACHE(v)   BF_CS1(GPU3D_AQA_CFG, ARCACHE, v)
#endif

/*!
 * @brief HW_GPU3D_AQA_STATUS - AQAxiStatus
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_ERR_ID : 4; //!< 
        unsigned RD_ERR_ID : 4; //!< 
        unsigned DET_WR_ERR : 1; //!< 
        unsigned DET_RD_ERR : 1; //!< 
        unsigned RESERVED0 : 22; //!< Reserved
    } B;
} hw_gpu3d_aqa_status_t;
#endif

/*
 * constants & macros for entire GPU3D_AQA_STATUS register
 */
#define HW_GPU3D_AQA_STATUS_ADDR      (REGS_GPU3D_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_AQA_STATUS           (*(volatile hw_gpu3d_aqa_status_t *) HW_GPU3D_AQA_STATUS_ADDR)
#define HW_GPU3D_AQA_STATUS_RD()      (HW_GPU3D_AQA_STATUS.U)
#define HW_GPU3D_AQA_STATUS_WR(v)     (HW_GPU3D_AQA_STATUS.U = (v))
#define HW_GPU3D_AQA_STATUS_SET(v)    (HW_GPU3D_AQA_STATUS_WR(HW_GPU3D_AQA_STATUS_RD() |  (v)))
#define HW_GPU3D_AQA_STATUS_CLR(v)    (HW_GPU3D_AQA_STATUS_WR(HW_GPU3D_AQA_STATUS_RD() & ~(v)))
#define HW_GPU3D_AQA_STATUS_TOG(v)    (HW_GPU3D_AQA_STATUS_WR(HW_GPU3D_AQA_STATUS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_AQA_STATUS bitfields
 */

/* --- Register HW_GPU3D_AQA_STATUS, field WR_ERR_ID
 *

 */

#define BP_GPU3D_AQA_STATUS_WR_ERR_ID      0
#define BM_GPU3D_AQA_STATUS_WR_ERR_ID      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQA_STATUS_WR_ERR_ID(v)   ((((reg32_t) v) << 0) & BM_GPU3D_AQA_STATUS_WR_ERR_ID)
#else
#define BF_GPU3D_AQA_STATUS_WR_ERR_ID(v)   (((v) << 0) & BM_GPU3D_AQA_STATUS_WR_ERR_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQA_STATUS_WR_ERR_ID(v)   BF_CS1(GPU3D_AQA_STATUS, WR_ERR_ID, v)
#endif

/* --- Register HW_GPU3D_AQA_STATUS, field RD_ERR_ID
 *

 */

#define BP_GPU3D_AQA_STATUS_RD_ERR_ID      4
#define BM_GPU3D_AQA_STATUS_RD_ERR_ID      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQA_STATUS_RD_ERR_ID(v)   ((((reg32_t) v) << 4) & BM_GPU3D_AQA_STATUS_RD_ERR_ID)
#else
#define BF_GPU3D_AQA_STATUS_RD_ERR_ID(v)   (((v) << 4) & BM_GPU3D_AQA_STATUS_RD_ERR_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQA_STATUS_RD_ERR_ID(v)   BF_CS1(GPU3D_AQA_STATUS, RD_ERR_ID, v)
#endif

/* --- Register HW_GPU3D_AQA_STATUS, field DET_WR_ERR
 *

 */

#define BP_GPU3D_AQA_STATUS_DET_WR_ERR      8
#define BM_GPU3D_AQA_STATUS_DET_WR_ERR      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQA_STATUS_DET_WR_ERR(v)   ((((reg32_t) v) << 8) & BM_GPU3D_AQA_STATUS_DET_WR_ERR)
#else
#define BF_GPU3D_AQA_STATUS_DET_WR_ERR(v)   (((v) << 8) & BM_GPU3D_AQA_STATUS_DET_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQA_STATUS_DET_WR_ERR(v)   BF_CS1(GPU3D_AQA_STATUS, DET_WR_ERR, v)
#endif

/* --- Register HW_GPU3D_AQA_STATUS, field DET_RD_ERR
 *

 */

#define BP_GPU3D_AQA_STATUS_DET_RD_ERR      9
#define BM_GPU3D_AQA_STATUS_DET_RD_ERR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQA_STATUS_DET_RD_ERR(v)   ((((reg32_t) v) << 9) & BM_GPU3D_AQA_STATUS_DET_RD_ERR)
#else
#define BF_GPU3D_AQA_STATUS_DET_RD_ERR(v)   (((v) << 9) & BM_GPU3D_AQA_STATUS_DET_RD_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQA_STATUS_DET_RD_ERR(v)   BF_CS1(GPU3D_AQA_STATUS, DET_RD_ERR, v)
#endif

/*!
 * @brief HW_GPU3D_AQI_ACK - AQIntrAcknowledge
 *
 * Interrupt acknowledge register. Each bit represents a corresponding event being triggered.
 * Reading from this register clears the outstanding interrupt.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INTR_VEC : 32; //!< 
    } B;
} hw_gpu3d_aqi_ack_t;
#endif

/*
 * constants & macros for entire GPU3D_AQI_ACK register
 */
#define HW_GPU3D_AQI_ACK_ADDR      (REGS_GPU3D_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_AQI_ACK           (*(volatile hw_gpu3d_aqi_ack_t *) HW_GPU3D_AQI_ACK_ADDR)
#define HW_GPU3D_AQI_ACK_RD()      (HW_GPU3D_AQI_ACK.U)
#define HW_GPU3D_AQI_ACK_WR(v)     (HW_GPU3D_AQI_ACK.U = (v))
#define HW_GPU3D_AQI_ACK_SET(v)    (HW_GPU3D_AQI_ACK_WR(HW_GPU3D_AQI_ACK_RD() |  (v)))
#define HW_GPU3D_AQI_ACK_CLR(v)    (HW_GPU3D_AQI_ACK_WR(HW_GPU3D_AQI_ACK_RD() & ~(v)))
#define HW_GPU3D_AQI_ACK_TOG(v)    (HW_GPU3D_AQI_ACK_WR(HW_GPU3D_AQI_ACK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_AQI_ACK bitfields
 */

/* --- Register HW_GPU3D_AQI_ACK, field INTR_VEC
 *

 */

#define BP_GPU3D_AQI_ACK_INTR_VEC      0
#define BM_GPU3D_AQI_ACK_INTR_VEC      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQI_ACK_INTR_VEC(v)   ((((reg32_t) v) << 0) & BM_GPU3D_AQI_ACK_INTR_VEC)
#else
#define BF_GPU3D_AQI_ACK_INTR_VEC(v)   (((v) << 0) & BM_GPU3D_AQI_ACK_INTR_VEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQI_ACK_INTR_VEC(v)   BF_CS1(GPU3D_AQI_ACK, INTR_VEC, v)
#endif

/*!
 * @brief HW_GPU3D_AQI_ENBL - AQIntrEnbl
 *
 * Interrupt enable register. Each bit enables a corresponding event.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INTR_ENBL_VEC : 32; //!< 
    } B;
} hw_gpu3d_aqi_enbl_t;
#endif

/*
 * constants & macros for entire GPU3D_AQI_ENBL register
 */
#define HW_GPU3D_AQI_ENBL_ADDR      (REGS_GPU3D_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_AQI_ENBL           (*(volatile hw_gpu3d_aqi_enbl_t *) HW_GPU3D_AQI_ENBL_ADDR)
#define HW_GPU3D_AQI_ENBL_RD()      (HW_GPU3D_AQI_ENBL.U)
#define HW_GPU3D_AQI_ENBL_WR(v)     (HW_GPU3D_AQI_ENBL.U = (v))
#define HW_GPU3D_AQI_ENBL_SET(v)    (HW_GPU3D_AQI_ENBL_WR(HW_GPU3D_AQI_ENBL_RD() |  (v)))
#define HW_GPU3D_AQI_ENBL_CLR(v)    (HW_GPU3D_AQI_ENBL_WR(HW_GPU3D_AQI_ENBL_RD() & ~(v)))
#define HW_GPU3D_AQI_ENBL_TOG(v)    (HW_GPU3D_AQI_ENBL_WR(HW_GPU3D_AQI_ENBL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_AQI_ENBL bitfields
 */

/* --- Register HW_GPU3D_AQI_ENBL, field INTR_ENBL_VEC
 *

 */

#define BP_GPU3D_AQI_ENBL_INTR_ENBL_VEC      0
#define BM_GPU3D_AQI_ENBL_INTR_ENBL_VEC      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQI_ENBL_INTR_ENBL_VEC(v)   ((((reg32_t) v) << 0) & BM_GPU3D_AQI_ENBL_INTR_ENBL_VEC)
#else
#define BF_GPU3D_AQI_ENBL_INTR_ENBL_VEC(v)   (((v) << 0) & BM_GPU3D_AQI_ENBL_INTR_ENBL_VEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQI_ENBL_INTR_ENBL_VEC(v)   BF_CS1(GPU3D_AQI_ENBL, INTR_ENBL_VEC, v)
#endif

/*!
 * @brief HW_GPU3D_AQIDENT - AQIdent
 *
 * Identification register. This register has no set reset value. It varies with the
 * implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CUSTOMER : 8; //!< Customer value.
        unsigned TECHNOLOGY : 4; //!< Technology value.
        unsigned REVISION : 4; //!< Revision value.
        unsigned PRODUCT : 8; //!< Product value.
        unsigned FAMILY : 8; //!< Family value.
    } B;
} hw_gpu3d_aqident_t;
#endif

/*
 * constants & macros for entire GPU3D_AQIDENT register
 */
#define HW_GPU3D_AQIDENT_ADDR      (REGS_GPU3D_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_AQIDENT           (*(volatile hw_gpu3d_aqident_t *) HW_GPU3D_AQIDENT_ADDR)
#define HW_GPU3D_AQIDENT_RD()      (HW_GPU3D_AQIDENT.U)
#define HW_GPU3D_AQIDENT_WR(v)     (HW_GPU3D_AQIDENT.U = (v))
#define HW_GPU3D_AQIDENT_SET(v)    (HW_GPU3D_AQIDENT_WR(HW_GPU3D_AQIDENT_RD() |  (v)))
#define HW_GPU3D_AQIDENT_CLR(v)    (HW_GPU3D_AQIDENT_WR(HW_GPU3D_AQIDENT_RD() & ~(v)))
#define HW_GPU3D_AQIDENT_TOG(v)    (HW_GPU3D_AQIDENT_WR(HW_GPU3D_AQIDENT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_AQIDENT bitfields
 */

/* --- Register HW_GPU3D_AQIDENT, field CUSTOMER
 *
 * Customer value.
 */

#define BP_GPU3D_AQIDENT_CUSTOMER      0
#define BM_GPU3D_AQIDENT_CUSTOMER      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQIDENT_CUSTOMER(v)   ((((reg32_t) v) << 0) & BM_GPU3D_AQIDENT_CUSTOMER)
#else
#define BF_GPU3D_AQIDENT_CUSTOMER(v)   (((v) << 0) & BM_GPU3D_AQIDENT_CUSTOMER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQIDENT_CUSTOMER(v)   BF_CS1(GPU3D_AQIDENT, CUSTOMER, v)
#endif

/* --- Register HW_GPU3D_AQIDENT, field TECHNOLOGY
 *
 * Technology value.
 */

#define BP_GPU3D_AQIDENT_TECHNOLOGY      8
#define BM_GPU3D_AQIDENT_TECHNOLOGY      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQIDENT_TECHNOLOGY(v)   ((((reg32_t) v) << 8) & BM_GPU3D_AQIDENT_TECHNOLOGY)
#else
#define BF_GPU3D_AQIDENT_TECHNOLOGY(v)   (((v) << 8) & BM_GPU3D_AQIDENT_TECHNOLOGY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQIDENT_TECHNOLOGY(v)   BF_CS1(GPU3D_AQIDENT, TECHNOLOGY, v)
#endif

/* --- Register HW_GPU3D_AQIDENT, field REVISION
 *
 * Revision value.
 */

#define BP_GPU3D_AQIDENT_REVISION      12
#define BM_GPU3D_AQIDENT_REVISION      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQIDENT_REVISION(v)   ((((reg32_t) v) << 12) & BM_GPU3D_AQIDENT_REVISION)
#else
#define BF_GPU3D_AQIDENT_REVISION(v)   (((v) << 12) & BM_GPU3D_AQIDENT_REVISION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQIDENT_REVISION(v)   BF_CS1(GPU3D_AQIDENT, REVISION, v)
#endif

/* --- Register HW_GPU3D_AQIDENT, field PRODUCT
 *
 * Product value.
 */

#define BP_GPU3D_AQIDENT_PRODUCT      16
#define BM_GPU3D_AQIDENT_PRODUCT      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQIDENT_PRODUCT(v)   ((((reg32_t) v) << 16) & BM_GPU3D_AQIDENT_PRODUCT)
#else
#define BF_GPU3D_AQIDENT_PRODUCT(v)   (((v) << 16) & BM_GPU3D_AQIDENT_PRODUCT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQIDENT_PRODUCT(v)   BF_CS1(GPU3D_AQIDENT, PRODUCT, v)
#endif

/* --- Register HW_GPU3D_AQIDENT, field FAMILY
 *
 * Family value.
 */

#define BP_GPU3D_AQIDENT_FAMILY      24
#define BM_GPU3D_AQIDENT_FAMILY      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_AQIDENT_FAMILY(v)   ((((reg32_t) v) << 24) & BM_GPU3D_AQIDENT_FAMILY)
#else
#define BF_GPU3D_AQIDENT_FAMILY(v)   (((v) << 24) & BM_GPU3D_AQIDENT_FAMILY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_AQIDENT_FAMILY(v)   BF_CS1(GPU3D_AQIDENT, FAMILY, v)
#endif

/*!
 * @brief HW_GPU3D_GC_FEAT - GCFeatures
 *
 * Shows which features are enabled in this chip. This register has no set reset value. It
 * varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FAST_CLEAR : 1; //!< Fast clear.
        unsigned SPECIAL_ANTI_ALIASING : 1; //!< Full-screen anti-aliasing.
        unsigned PIPE_3D : 1; //!< 3D pipe.
        unsigned DXT_TEXTURE_COMPRESSION : 1; //!< DXT texture compression.
        unsigned DEBUG_MODE : 1; //!< Debug registers.
        unsigned ZCOMPRESSION : 1; //!< Depth and color compression.
        unsigned YUV420_FILTER : 1; //!< YUV 4:2:0 support in filter blit.
        unsigned MSAA : 1; //!< MSAA support.
        unsigned DC : 1; //!< Shows if there is a display controller in the IP.
        unsigned PIPE_2D : 1; //!< Shows if there is 2D engine.
        unsigned ETC1_TEXTURE_COMPRESSION : 1; //!< ETC1 texture compression.
        unsigned FAST_SCALER : 1; //!< Shows if the IP has HD scaler.
        unsigned HIGH_DYNAMIC_RANGE : 1; //!< Shows if the IP has HDR support.
        unsigned YUV420_TILER : 1; //!< YUV 4:2:0 tiler is available.
        unsigned MODULE_CG : 1; //!< Secong level clock gating is available.
        unsigned MIN_AREA : 1; //!< IP is configured to have minimum area.
        unsigned NO_EZ : 1; //!< IP does not have early-Z.
        unsigned NO422_TEXTURE : 1; //!< IP does not have 422 texture input format.
        unsigned BUFFER_INTERLEAVING : 1; //!< IP supports interleaving depth and color buffers.
        unsigned BYTE_WRITE_2D : 1; //!< Supports byte write in 2D.
        unsigned NO_SCALER : 1; //!< IP does not have 2D scaler.
        unsigned YUY2_AVERAGING : 1; //!< YUY2 averaging support in resolve.
        unsigned HALF_PE_CACHE : 1; //!< PE cache is half.
        unsigned HALF_TX_CACHE : 1; //!< TX cache is half.
        unsigned YUY2_RENDER_TARGET : 1; //!< YUY2 support in PE and YUY2 to RGB conversion in resolve.
        unsigned MEM32_BIT_SUPPORT : 1; //!< 32 bit memory address support.
        unsigned PIPE_VG : 1; //!< VCG pipe is present.
        unsigned VGTS : 1; //!< VG tessellator is present.
        unsigned FE20 : 1; //!< FE 2.0 is present.
        unsigned BYTE_WRITE_3D : 1; //!< 3D PE has byte write capability.
        unsigned RS_YUV_TARGET : 1; //!< Supports resolving into YUV target.
        unsigned FE20_BIT_INDEX : 1; //!< Supports 20 bit index.
    } B;
} hw_gpu3d_gc_feat_t;
#endif

/*
 * constants & macros for entire GPU3D_GC_FEAT register
 */
#define HW_GPU3D_GC_FEAT_ADDR      (REGS_GPU3D_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GC_FEAT           (*(volatile hw_gpu3d_gc_feat_t *) HW_GPU3D_GC_FEAT_ADDR)
#define HW_GPU3D_GC_FEAT_RD()      (HW_GPU3D_GC_FEAT.U)
#define HW_GPU3D_GC_FEAT_WR(v)     (HW_GPU3D_GC_FEAT.U = (v))
#define HW_GPU3D_GC_FEAT_SET(v)    (HW_GPU3D_GC_FEAT_WR(HW_GPU3D_GC_FEAT_RD() |  (v)))
#define HW_GPU3D_GC_FEAT_CLR(v)    (HW_GPU3D_GC_FEAT_WR(HW_GPU3D_GC_FEAT_RD() & ~(v)))
#define HW_GPU3D_GC_FEAT_TOG(v)    (HW_GPU3D_GC_FEAT_WR(HW_GPU3D_GC_FEAT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GC_FEAT bitfields
 */

/* --- Register HW_GPU3D_GC_FEAT, field FAST_CLEAR
 *
 * Fast clear.
 */

#define BP_GPU3D_GC_FEAT_FAST_CLEAR      0
#define BM_GPU3D_GC_FEAT_FAST_CLEAR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_FAST_CLEAR(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GC_FEAT_FAST_CLEAR)
#else
#define BF_GPU3D_GC_FEAT_FAST_CLEAR(v)   (((v) << 0) & BM_GPU3D_GC_FEAT_FAST_CLEAR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_FAST_CLEAR(v)   BF_CS1(GPU3D_GC_FEAT, FAST_CLEAR, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field SPECIAL_ANTI_ALIASING
 *
 * Full-screen anti-aliasing.
 */

#define BP_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING      1
#define BM_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING(v)   ((((reg32_t) v) << 1) & BM_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING)
#else
#define BF_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING(v)   (((v) << 1) & BM_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING(v)   BF_CS1(GPU3D_GC_FEAT, SPECIAL_ANTI_ALIASING, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field PIPE_3D
 *
 * 3D pipe.
 */

#define BP_GPU3D_GC_FEAT_PIPE_3D      2
#define BM_GPU3D_GC_FEAT_PIPE_3D      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_PIPE_3D(v)   ((((reg32_t) v) << 2) & BM_GPU3D_GC_FEAT_PIPE_3D)
#else
#define BF_GPU3D_GC_FEAT_PIPE_3D(v)   (((v) << 2) & BM_GPU3D_GC_FEAT_PIPE_3D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_PIPE_3D(v)   BF_CS1(GPU3D_GC_FEAT, PIPE_3D, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field DXT_TEXTURE_COMPRESSION
 *
 * DXT texture compression.
 */

#define BP_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION      3
#define BM_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION(v)   ((((reg32_t) v) << 3) & BM_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION)
#else
#define BF_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION(v)   (((v) << 3) & BM_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION(v)   BF_CS1(GPU3D_GC_FEAT, DXT_TEXTURE_COMPRESSION, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field DEBUG_MODE
 *
 * Debug registers.
 */

#define BP_GPU3D_GC_FEAT_DEBUG_MODE      4
#define BM_GPU3D_GC_FEAT_DEBUG_MODE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_DEBUG_MODE(v)   ((((reg32_t) v) << 4) & BM_GPU3D_GC_FEAT_DEBUG_MODE)
#else
#define BF_GPU3D_GC_FEAT_DEBUG_MODE(v)   (((v) << 4) & BM_GPU3D_GC_FEAT_DEBUG_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_DEBUG_MODE(v)   BF_CS1(GPU3D_GC_FEAT, DEBUG_MODE, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field ZCOMPRESSION
 *
 * Depth and color compression.
 */

#define BP_GPU3D_GC_FEAT_ZCOMPRESSION      5
#define BM_GPU3D_GC_FEAT_ZCOMPRESSION      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_ZCOMPRESSION(v)   ((((reg32_t) v) << 5) & BM_GPU3D_GC_FEAT_ZCOMPRESSION)
#else
#define BF_GPU3D_GC_FEAT_ZCOMPRESSION(v)   (((v) << 5) & BM_GPU3D_GC_FEAT_ZCOMPRESSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_ZCOMPRESSION(v)   BF_CS1(GPU3D_GC_FEAT, ZCOMPRESSION, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field YUV420_FILTER
 *
 * YUV 4:2:0 support in filter blit.
 */

#define BP_GPU3D_GC_FEAT_YUV420_FILTER      6
#define BM_GPU3D_GC_FEAT_YUV420_FILTER      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_YUV420_FILTER(v)   ((((reg32_t) v) << 6) & BM_GPU3D_GC_FEAT_YUV420_FILTER)
#else
#define BF_GPU3D_GC_FEAT_YUV420_FILTER(v)   (((v) << 6) & BM_GPU3D_GC_FEAT_YUV420_FILTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_YUV420_FILTER(v)   BF_CS1(GPU3D_GC_FEAT, YUV420_FILTER, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field MSAA
 *
 * MSAA support.
 */

#define BP_GPU3D_GC_FEAT_MSAA      7
#define BM_GPU3D_GC_FEAT_MSAA      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_MSAA(v)   ((((reg32_t) v) << 7) & BM_GPU3D_GC_FEAT_MSAA)
#else
#define BF_GPU3D_GC_FEAT_MSAA(v)   (((v) << 7) & BM_GPU3D_GC_FEAT_MSAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_MSAA(v)   BF_CS1(GPU3D_GC_FEAT, MSAA, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field DC
 *
 * Shows if there is a display controller in the IP.
 */

#define BP_GPU3D_GC_FEAT_DC      8
#define BM_GPU3D_GC_FEAT_DC      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_DC(v)   ((((reg32_t) v) << 8) & BM_GPU3D_GC_FEAT_DC)
#else
#define BF_GPU3D_GC_FEAT_DC(v)   (((v) << 8) & BM_GPU3D_GC_FEAT_DC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_DC(v)   BF_CS1(GPU3D_GC_FEAT, DC, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field PIPE_2D
 *
 * Shows if there is 2D engine.
 */

#define BP_GPU3D_GC_FEAT_PIPE_2D      9
#define BM_GPU3D_GC_FEAT_PIPE_2D      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_PIPE_2D(v)   ((((reg32_t) v) << 9) & BM_GPU3D_GC_FEAT_PIPE_2D)
#else
#define BF_GPU3D_GC_FEAT_PIPE_2D(v)   (((v) << 9) & BM_GPU3D_GC_FEAT_PIPE_2D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_PIPE_2D(v)   BF_CS1(GPU3D_GC_FEAT, PIPE_2D, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field ETC1_TEXTURE_COMPRESSION
 *
 * ETC1 texture compression.
 */

#define BP_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION      10
#define BM_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION(v)   ((((reg32_t) v) << 10) & BM_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION)
#else
#define BF_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION(v)   (((v) << 10) & BM_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION(v)   BF_CS1(GPU3D_GC_FEAT, ETC1_TEXTURE_COMPRESSION, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field FAST_SCALER
 *
 * Shows if the IP has HD scaler.
 */

#define BP_GPU3D_GC_FEAT_FAST_SCALER      11
#define BM_GPU3D_GC_FEAT_FAST_SCALER      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_FAST_SCALER(v)   ((((reg32_t) v) << 11) & BM_GPU3D_GC_FEAT_FAST_SCALER)
#else
#define BF_GPU3D_GC_FEAT_FAST_SCALER(v)   (((v) << 11) & BM_GPU3D_GC_FEAT_FAST_SCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_FAST_SCALER(v)   BF_CS1(GPU3D_GC_FEAT, FAST_SCALER, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field HIGH_DYNAMIC_RANGE
 *
 * Shows if the IP has HDR support.
 */

#define BP_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE      12
#define BM_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE(v)   ((((reg32_t) v) << 12) & BM_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE)
#else
#define BF_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE(v)   (((v) << 12) & BM_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE(v)   BF_CS1(GPU3D_GC_FEAT, HIGH_DYNAMIC_RANGE, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field YUV420_TILER
 *
 * YUV 4:2:0 tiler is available.
 */

#define BP_GPU3D_GC_FEAT_YUV420_TILER      13
#define BM_GPU3D_GC_FEAT_YUV420_TILER      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_YUV420_TILER(v)   ((((reg32_t) v) << 13) & BM_GPU3D_GC_FEAT_YUV420_TILER)
#else
#define BF_GPU3D_GC_FEAT_YUV420_TILER(v)   (((v) << 13) & BM_GPU3D_GC_FEAT_YUV420_TILER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_YUV420_TILER(v)   BF_CS1(GPU3D_GC_FEAT, YUV420_TILER, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field MODULE_CG
 *
 * Secong level clock gating is available.
 */

#define BP_GPU3D_GC_FEAT_MODULE_CG      14
#define BM_GPU3D_GC_FEAT_MODULE_CG      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_MODULE_CG(v)   ((((reg32_t) v) << 14) & BM_GPU3D_GC_FEAT_MODULE_CG)
#else
#define BF_GPU3D_GC_FEAT_MODULE_CG(v)   (((v) << 14) & BM_GPU3D_GC_FEAT_MODULE_CG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_MODULE_CG(v)   BF_CS1(GPU3D_GC_FEAT, MODULE_CG, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field MIN_AREA
 *
 * IP is configured to have minimum area.
 */

#define BP_GPU3D_GC_FEAT_MIN_AREA      15
#define BM_GPU3D_GC_FEAT_MIN_AREA      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_MIN_AREA(v)   ((((reg32_t) v) << 15) & BM_GPU3D_GC_FEAT_MIN_AREA)
#else
#define BF_GPU3D_GC_FEAT_MIN_AREA(v)   (((v) << 15) & BM_GPU3D_GC_FEAT_MIN_AREA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_MIN_AREA(v)   BF_CS1(GPU3D_GC_FEAT, MIN_AREA, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field NO_EZ
 *
 * IP does not have early-Z.
 */

#define BP_GPU3D_GC_FEAT_NO_EZ      16
#define BM_GPU3D_GC_FEAT_NO_EZ      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_NO_EZ(v)   ((((reg32_t) v) << 16) & BM_GPU3D_GC_FEAT_NO_EZ)
#else
#define BF_GPU3D_GC_FEAT_NO_EZ(v)   (((v) << 16) & BM_GPU3D_GC_FEAT_NO_EZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_NO_EZ(v)   BF_CS1(GPU3D_GC_FEAT, NO_EZ, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field NO422_TEXTURE
 *
 * IP does not have 422 texture input format.
 */

#define BP_GPU3D_GC_FEAT_NO422_TEXTURE      17
#define BM_GPU3D_GC_FEAT_NO422_TEXTURE      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_NO422_TEXTURE(v)   ((((reg32_t) v) << 17) & BM_GPU3D_GC_FEAT_NO422_TEXTURE)
#else
#define BF_GPU3D_GC_FEAT_NO422_TEXTURE(v)   (((v) << 17) & BM_GPU3D_GC_FEAT_NO422_TEXTURE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_NO422_TEXTURE(v)   BF_CS1(GPU3D_GC_FEAT, NO422_TEXTURE, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field BUFFER_INTERLEAVING
 *
 * IP supports interleaving depth and color buffers.
 */

#define BP_GPU3D_GC_FEAT_BUFFER_INTERLEAVING      18
#define BM_GPU3D_GC_FEAT_BUFFER_INTERLEAVING      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_BUFFER_INTERLEAVING(v)   ((((reg32_t) v) << 18) & BM_GPU3D_GC_FEAT_BUFFER_INTERLEAVING)
#else
#define BF_GPU3D_GC_FEAT_BUFFER_INTERLEAVING(v)   (((v) << 18) & BM_GPU3D_GC_FEAT_BUFFER_INTERLEAVING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_BUFFER_INTERLEAVING(v)   BF_CS1(GPU3D_GC_FEAT, BUFFER_INTERLEAVING, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field BYTE_WRITE_2D
 *
 * Supports byte write in 2D.
 */

#define BP_GPU3D_GC_FEAT_BYTE_WRITE_2D      19
#define BM_GPU3D_GC_FEAT_BYTE_WRITE_2D      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_BYTE_WRITE_2D(v)   ((((reg32_t) v) << 19) & BM_GPU3D_GC_FEAT_BYTE_WRITE_2D)
#else
#define BF_GPU3D_GC_FEAT_BYTE_WRITE_2D(v)   (((v) << 19) & BM_GPU3D_GC_FEAT_BYTE_WRITE_2D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_BYTE_WRITE_2D(v)   BF_CS1(GPU3D_GC_FEAT, BYTE_WRITE_2D, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field NO_SCALER
 *
 * IP does not have 2D scaler.
 */

#define BP_GPU3D_GC_FEAT_NO_SCALER      20
#define BM_GPU3D_GC_FEAT_NO_SCALER      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_NO_SCALER(v)   ((((reg32_t) v) << 20) & BM_GPU3D_GC_FEAT_NO_SCALER)
#else
#define BF_GPU3D_GC_FEAT_NO_SCALER(v)   (((v) << 20) & BM_GPU3D_GC_FEAT_NO_SCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_NO_SCALER(v)   BF_CS1(GPU3D_GC_FEAT, NO_SCALER, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field YUY2_AVERAGING
 *
 * YUY2 averaging support in resolve.
 */

#define BP_GPU3D_GC_FEAT_YUY2_AVERAGING      21
#define BM_GPU3D_GC_FEAT_YUY2_AVERAGING      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_YUY2_AVERAGING(v)   ((((reg32_t) v) << 21) & BM_GPU3D_GC_FEAT_YUY2_AVERAGING)
#else
#define BF_GPU3D_GC_FEAT_YUY2_AVERAGING(v)   (((v) << 21) & BM_GPU3D_GC_FEAT_YUY2_AVERAGING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_YUY2_AVERAGING(v)   BF_CS1(GPU3D_GC_FEAT, YUY2_AVERAGING, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field HALF_PE_CACHE
 *
 * PE cache is half.
 */

#define BP_GPU3D_GC_FEAT_HALF_PE_CACHE      22
#define BM_GPU3D_GC_FEAT_HALF_PE_CACHE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_HALF_PE_CACHE(v)   ((((reg32_t) v) << 22) & BM_GPU3D_GC_FEAT_HALF_PE_CACHE)
#else
#define BF_GPU3D_GC_FEAT_HALF_PE_CACHE(v)   (((v) << 22) & BM_GPU3D_GC_FEAT_HALF_PE_CACHE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_HALF_PE_CACHE(v)   BF_CS1(GPU3D_GC_FEAT, HALF_PE_CACHE, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field HALF_TX_CACHE
 *
 * TX cache is half.
 */

#define BP_GPU3D_GC_FEAT_HALF_TX_CACHE      23
#define BM_GPU3D_GC_FEAT_HALF_TX_CACHE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_HALF_TX_CACHE(v)   ((((reg32_t) v) << 23) & BM_GPU3D_GC_FEAT_HALF_TX_CACHE)
#else
#define BF_GPU3D_GC_FEAT_HALF_TX_CACHE(v)   (((v) << 23) & BM_GPU3D_GC_FEAT_HALF_TX_CACHE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_HALF_TX_CACHE(v)   BF_CS1(GPU3D_GC_FEAT, HALF_TX_CACHE, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field YUY2_RENDER_TARGET
 *
 * YUY2 support in PE and YUY2 to RGB conversion in resolve.
 */

#define BP_GPU3D_GC_FEAT_YUY2_RENDER_TARGET      24
#define BM_GPU3D_GC_FEAT_YUY2_RENDER_TARGET      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_YUY2_RENDER_TARGET(v)   ((((reg32_t) v) << 24) & BM_GPU3D_GC_FEAT_YUY2_RENDER_TARGET)
#else
#define BF_GPU3D_GC_FEAT_YUY2_RENDER_TARGET(v)   (((v) << 24) & BM_GPU3D_GC_FEAT_YUY2_RENDER_TARGET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_YUY2_RENDER_TARGET(v)   BF_CS1(GPU3D_GC_FEAT, YUY2_RENDER_TARGET, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field MEM32_BIT_SUPPORT
 *
 * 32 bit memory address support.
 */

#define BP_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT      25
#define BM_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT(v)   ((((reg32_t) v) << 25) & BM_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT)
#else
#define BF_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT(v)   (((v) << 25) & BM_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT(v)   BF_CS1(GPU3D_GC_FEAT, MEM32_BIT_SUPPORT, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field PIPE_VG
 *
 * VCG pipe is present.
 */

#define BP_GPU3D_GC_FEAT_PIPE_VG      26
#define BM_GPU3D_GC_FEAT_PIPE_VG      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_PIPE_VG(v)   ((((reg32_t) v) << 26) & BM_GPU3D_GC_FEAT_PIPE_VG)
#else
#define BF_GPU3D_GC_FEAT_PIPE_VG(v)   (((v) << 26) & BM_GPU3D_GC_FEAT_PIPE_VG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_PIPE_VG(v)   BF_CS1(GPU3D_GC_FEAT, PIPE_VG, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field VGTS
 *
 * VG tessellator is present.
 */

#define BP_GPU3D_GC_FEAT_VGTS      27
#define BM_GPU3D_GC_FEAT_VGTS      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_VGTS(v)   ((((reg32_t) v) << 27) & BM_GPU3D_GC_FEAT_VGTS)
#else
#define BF_GPU3D_GC_FEAT_VGTS(v)   (((v) << 27) & BM_GPU3D_GC_FEAT_VGTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_VGTS(v)   BF_CS1(GPU3D_GC_FEAT, VGTS, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field FE20
 *
 * FE 2.0 is present.
 */

#define BP_GPU3D_GC_FEAT_FE20      28
#define BM_GPU3D_GC_FEAT_FE20      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_FE20(v)   ((((reg32_t) v) << 28) & BM_GPU3D_GC_FEAT_FE20)
#else
#define BF_GPU3D_GC_FEAT_FE20(v)   (((v) << 28) & BM_GPU3D_GC_FEAT_FE20)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_FE20(v)   BF_CS1(GPU3D_GC_FEAT, FE20, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field BYTE_WRITE_3D
 *
 * 3D PE has byte write capability.
 */

#define BP_GPU3D_GC_FEAT_BYTE_WRITE_3D      29
#define BM_GPU3D_GC_FEAT_BYTE_WRITE_3D      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_BYTE_WRITE_3D(v)   ((((reg32_t) v) << 29) & BM_GPU3D_GC_FEAT_BYTE_WRITE_3D)
#else
#define BF_GPU3D_GC_FEAT_BYTE_WRITE_3D(v)   (((v) << 29) & BM_GPU3D_GC_FEAT_BYTE_WRITE_3D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_BYTE_WRITE_3D(v)   BF_CS1(GPU3D_GC_FEAT, BYTE_WRITE_3D, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field RS_YUV_TARGET
 *
 * Supports resolving into YUV target.
 */

#define BP_GPU3D_GC_FEAT_RS_YUV_TARGET      30
#define BM_GPU3D_GC_FEAT_RS_YUV_TARGET      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_RS_YUV_TARGET(v)   ((((reg32_t) v) << 30) & BM_GPU3D_GC_FEAT_RS_YUV_TARGET)
#else
#define BF_GPU3D_GC_FEAT_RS_YUV_TARGET(v)   (((v) << 30) & BM_GPU3D_GC_FEAT_RS_YUV_TARGET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_RS_YUV_TARGET(v)   BF_CS1(GPU3D_GC_FEAT, RS_YUV_TARGET, v)
#endif

/* --- Register HW_GPU3D_GC_FEAT, field FE20_BIT_INDEX
 *
 * Supports 20 bit index.
 */

#define BP_GPU3D_GC_FEAT_FE20_BIT_INDEX      31
#define BM_GPU3D_GC_FEAT_FE20_BIT_INDEX      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GC_FEAT_FE20_BIT_INDEX(v)   ((((reg32_t) v) << 31) & BM_GPU3D_GC_FEAT_FE20_BIT_INDEX)
#else
#define BF_GPU3D_GC_FEAT_FE20_BIT_INDEX(v)   (((v) << 31) & BM_GPU3D_GC_FEAT_FE20_BIT_INDEX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GC_FEAT_FE20_BIT_INDEX(v)   BF_CS1(GPU3D_GC_FEAT, FE20_BIT_INDEX, v)
#endif

/*!
 * @brief HW_GPU3D_GCC_ID - GCChipId
 *
 * Shows the ID for the chip in SBCD. This register has no set reset value. It varies with the
 * implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ID : 32; //!< Id
    } B;
} hw_gpu3d_gcc_id_t;
#endif

/*
 * constants & macros for entire GPU3D_GCC_ID register
 */
#define HW_GPU3D_GCC_ID_ADDR      (REGS_GPU3D_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCC_ID           (*(volatile hw_gpu3d_gcc_id_t *) HW_GPU3D_GCC_ID_ADDR)
#define HW_GPU3D_GCC_ID_RD()      (HW_GPU3D_GCC_ID.U)
#define HW_GPU3D_GCC_ID_WR(v)     (HW_GPU3D_GCC_ID.U = (v))
#define HW_GPU3D_GCC_ID_SET(v)    (HW_GPU3D_GCC_ID_WR(HW_GPU3D_GCC_ID_RD() |  (v)))
#define HW_GPU3D_GCC_ID_CLR(v)    (HW_GPU3D_GCC_ID_WR(HW_GPU3D_GCC_ID_RD() & ~(v)))
#define HW_GPU3D_GCC_ID_TOG(v)    (HW_GPU3D_GCC_ID_WR(HW_GPU3D_GCC_ID_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCC_ID bitfields
 */

/* --- Register HW_GPU3D_GCC_ID, field ID
 *
 * Id
 */

#define BP_GPU3D_GCC_ID_ID      0
#define BM_GPU3D_GCC_ID_ID      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_ID_ID(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCC_ID_ID)
#else
#define BF_GPU3D_GCC_ID_ID(v)   (((v) << 0) & BM_GPU3D_GCC_ID_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_ID_ID(v)   BF_CS1(GPU3D_GCC_ID, ID, v)
#endif

/*!
 * @brief HW_GPU3D_GCC_REV - GCChipRev
 *
 * Shows the revision for the chip in BCD. This register has no set reset value. It varies with
 * the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned REV : 32; //!< Revision
    } B;
} hw_gpu3d_gcc_rev_t;
#endif

/*
 * constants & macros for entire GPU3D_GCC_REV register
 */
#define HW_GPU3D_GCC_REV_ADDR      (REGS_GPU3D_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCC_REV           (*(volatile hw_gpu3d_gcc_rev_t *) HW_GPU3D_GCC_REV_ADDR)
#define HW_GPU3D_GCC_REV_RD()      (HW_GPU3D_GCC_REV.U)
#define HW_GPU3D_GCC_REV_WR(v)     (HW_GPU3D_GCC_REV.U = (v))
#define HW_GPU3D_GCC_REV_SET(v)    (HW_GPU3D_GCC_REV_WR(HW_GPU3D_GCC_REV_RD() |  (v)))
#define HW_GPU3D_GCC_REV_CLR(v)    (HW_GPU3D_GCC_REV_WR(HW_GPU3D_GCC_REV_RD() & ~(v)))
#define HW_GPU3D_GCC_REV_TOG(v)    (HW_GPU3D_GCC_REV_WR(HW_GPU3D_GCC_REV_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCC_REV bitfields
 */

/* --- Register HW_GPU3D_GCC_REV, field REV
 *
 * Revision
 */

#define BP_GPU3D_GCC_REV_REV      0
#define BM_GPU3D_GCC_REV_REV      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_REV_REV(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCC_REV_REV)
#else
#define BF_GPU3D_GCC_REV_REV(v)   (((v) << 0) & BM_GPU3D_GCC_REV_REV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_REV_REV(v)   BF_CS1(GPU3D_GCC_REV, REV, v)
#endif

/*!
 * @brief HW_GPU3D_GCC_DATE - GCChipDate
 *
 * Shows the release date for the IP. This register has no set reset value. It varies with the
 * implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATE : 32; //!< Date
    } B;
} hw_gpu3d_gcc_date_t;
#endif

/*
 * constants & macros for entire GPU3D_GCC_DATE register
 */
#define HW_GPU3D_GCC_DATE_ADDR      (REGS_GPU3D_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCC_DATE           (*(volatile hw_gpu3d_gcc_date_t *) HW_GPU3D_GCC_DATE_ADDR)
#define HW_GPU3D_GCC_DATE_RD()      (HW_GPU3D_GCC_DATE.U)
#define HW_GPU3D_GCC_DATE_WR(v)     (HW_GPU3D_GCC_DATE.U = (v))
#define HW_GPU3D_GCC_DATE_SET(v)    (HW_GPU3D_GCC_DATE_WR(HW_GPU3D_GCC_DATE_RD() |  (v)))
#define HW_GPU3D_GCC_DATE_CLR(v)    (HW_GPU3D_GCC_DATE_WR(HW_GPU3D_GCC_DATE_RD() & ~(v)))
#define HW_GPU3D_GCC_DATE_TOG(v)    (HW_GPU3D_GCC_DATE_WR(HW_GPU3D_GCC_DATE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCC_DATE bitfields
 */

/* --- Register HW_GPU3D_GCC_DATE, field DATE
 *
 * Date
 */

#define BP_GPU3D_GCC_DATE_DATE      0
#define BM_GPU3D_GCC_DATE_DATE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_DATE_DATE(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCC_DATE_DATE)
#else
#define BF_GPU3D_GCC_DATE_DATE(v)   (((v) << 0) & BM_GPU3D_GCC_DATE_DATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_DATE_DATE(v)   BF_CS1(GPU3D_GCC_DATE, DATE, v)
#endif

/*!
 * @brief HW_GPU3D_GCC_TIME - GCChipTime
 *
 * Shows the release time for the IP. This register has no set reset value. It varies with the
 * implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TIME : 32; //!< Time
    } B;
} hw_gpu3d_gcc_time_t;
#endif

/*
 * constants & macros for entire GPU3D_GCC_TIME register
 */
#define HW_GPU3D_GCC_TIME_ADDR      (REGS_GPU3D_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCC_TIME           (*(volatile hw_gpu3d_gcc_time_t *) HW_GPU3D_GCC_TIME_ADDR)
#define HW_GPU3D_GCC_TIME_RD()      (HW_GPU3D_GCC_TIME.U)
#define HW_GPU3D_GCC_TIME_WR(v)     (HW_GPU3D_GCC_TIME.U = (v))
#define HW_GPU3D_GCC_TIME_SET(v)    (HW_GPU3D_GCC_TIME_WR(HW_GPU3D_GCC_TIME_RD() |  (v)))
#define HW_GPU3D_GCC_TIME_CLR(v)    (HW_GPU3D_GCC_TIME_WR(HW_GPU3D_GCC_TIME_RD() & ~(v)))
#define HW_GPU3D_GCC_TIME_TOG(v)    (HW_GPU3D_GCC_TIME_WR(HW_GPU3D_GCC_TIME_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCC_TIME bitfields
 */

/* --- Register HW_GPU3D_GCC_TIME, field TIME
 *
 * Time
 */

#define BP_GPU3D_GCC_TIME_TIME      0
#define BM_GPU3D_GCC_TIME_TIME      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_TIME_TIME(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCC_TIME_TIME)
#else
#define BF_GPU3D_GCC_TIME_TIME(v)   (((v) << 0) & BM_GPU3D_GCC_TIME_TIME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_TIME_TIME(v)   BF_CS1(GPU3D_GCC_TIME, TIME, v)
#endif

/*!
 * @brief HW_GPU3D_GCC_CUST - GCChipCustomer
 *
 * Shows the customer and group for the IP. This register has no set reset value. It varies with
 * the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GROUP : 16; //!< Group
        unsigned COMPANY : 16; //!< Company
    } B;
} hw_gpu3d_gcc_cust_t;
#endif

/*
 * constants & macros for entire GPU3D_GCC_CUST register
 */
#define HW_GPU3D_GCC_CUST_ADDR      (REGS_GPU3D_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCC_CUST           (*(volatile hw_gpu3d_gcc_cust_t *) HW_GPU3D_GCC_CUST_ADDR)
#define HW_GPU3D_GCC_CUST_RD()      (HW_GPU3D_GCC_CUST.U)
#define HW_GPU3D_GCC_CUST_WR(v)     (HW_GPU3D_GCC_CUST.U = (v))
#define HW_GPU3D_GCC_CUST_SET(v)    (HW_GPU3D_GCC_CUST_WR(HW_GPU3D_GCC_CUST_RD() |  (v)))
#define HW_GPU3D_GCC_CUST_CLR(v)    (HW_GPU3D_GCC_CUST_WR(HW_GPU3D_GCC_CUST_RD() & ~(v)))
#define HW_GPU3D_GCC_CUST_TOG(v)    (HW_GPU3D_GCC_CUST_WR(HW_GPU3D_GCC_CUST_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCC_CUST bitfields
 */

/* --- Register HW_GPU3D_GCC_CUST, field GROUP
 *
 * Group
 */

#define BP_GPU3D_GCC_CUST_GROUP      0
#define BM_GPU3D_GCC_CUST_GROUP      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_CUST_GROUP(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCC_CUST_GROUP)
#else
#define BF_GPU3D_GCC_CUST_GROUP(v)   (((v) << 0) & BM_GPU3D_GCC_CUST_GROUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_CUST_GROUP(v)   BF_CS1(GPU3D_GCC_CUST, GROUP, v)
#endif

/* --- Register HW_GPU3D_GCC_CUST, field COMPANY
 *
 * Company
 */

#define BP_GPU3D_GCC_CUST_COMPANY      16
#define BM_GPU3D_GCC_CUST_COMPANY      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_CUST_COMPANY(v)   ((((reg32_t) v) << 16) & BM_GPU3D_GCC_CUST_COMPANY)
#else
#define BF_GPU3D_GCC_CUST_COMPANY(v)   (((v) << 16) & BM_GPU3D_GCC_CUST_COMPANY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_CUST_COMPANY(v)   BF_CS1(GPU3D_GCC_CUST, COMPANY, v)
#endif

/*!
 * @brief HW_GPU3D_GCM_FEAT_0 - GCMinorFeatures0
 *
 * Shows which minor features are enabled in this chip. This register has no set reset value. It
 * varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FLIP_Y : 1; //!< Y flipping capability is added to resolve.
        unsigned DUAL_RETURN_BUS : 1; //!< Dual Return Bus from HI to clients.
        unsigned ENDIANNESS_CONFIG : 1; //!< Configurable endianness support.
        unsigned TESTURE8_K : 1; //!< Supports 8Kx8K textures.
        unsigned CORRECT_TEXTURE_CONVERTER : 1; //!< Driver hack is not needed.
        unsigned SPECIAL_MSAA_LOD : 1; //!< Special LOD calculation when MSAA is on.
        unsigned FAST_CLEAR_FLUSH : 1; //!< Proper flush is done in fast clear cache.
        unsigned RESERVED0 : 1; //!< 2D PE 2.0 is present.
        unsigned CORRECT_AUTO_DISABLE : 1; //!< Auto disable in FC is correct.
        unsigned RENDER_8K : 1; //!< Supports 8K render target.
        unsigned TILE_STATUS_2BITS : 1; //!< 2 bits are used instead of 4 bits for tile status.
        unsigned SEPARATE_TILE_STATUS_WHEN_INTERLEAVED : 1; //!< Use 2 separate tile status buffers in interleaved mode.
        unsigned SUPER_TILED_32X32 : 1; //!< 32x32 super tile is available.
        unsigned VG_20 : 1; //!< Major updates to VG pipe (TS buffer tiling. State masking.).
        unsigned TS_EXTENDED_COMMANDS : 1; //!< New commands added to the tessellator.
        unsigned COMPRESSION_FIFO_FIXED : 1; //!< If this bit is not set, the FIFO counter should be set to 50. Else, the default should remain.
        unsigned EXTRA_SHADER_INSTRUCTIONS0 : 1; //!< Floor, ceil, and sign instructions are available.
        unsigned VG_FILTER : 1; //!< VG filter is available.
        unsigned VG_21 : 1; //!< Minor updates to VG pipe (Event generation from VG, TS, PE). Tiled image support.
        unsigned SHADER_GETS_W : 1; //!< W is sent to SH from RA.
        unsigned EXTRA_SHADER_INSTRUCTIONS1 : 1; //!< Sqrt, sin, cos intructions are available.
        unsigned DEFAULT_REG0 : 1; //!< Unavailable registers will return 0.
        unsigned MC_20 : 1; //!< New stlye MC with separate paths for color and depth.
        unsigned SHADER_MSAA_SIDEBAND : 1; //!< Put the MSAA data into sideband fifo.
        unsigned BUG_FIXES0 : 1; //!< 
        unsigned VAA : 1; //!< VAA is available or not.
        unsigned BYPASS_IN_MSAA : 1; //!< Shader supports bypass modew when MSAA is enabled.
        unsigned HIERARCHICAL_Z : 1; //!< Hierarchical Z is supported.
        unsigned NEW_TEXTURE : 1; //!< New texture unit is available.
        unsigned A8_TARGET_SUPPORT : 1; //!< 2D engine supports A8 target.
        unsigned CORRECT_STENCIL : 1; //!< Correct stencil behavior in depth only.
        unsigned ENHANCE_VR : 1; //!< Enhance VR and add a mode to walk 16 pixels in 16-bit mode in Vertical pass to improve $ hit rate when rotating 90/270.
    } B;
} hw_gpu3d_gcm_feat_0_t;
#endif

/*
 * constants & macros for entire GPU3D_GCM_FEAT_0 register
 */
#define HW_GPU3D_GCM_FEAT_0_ADDR      (REGS_GPU3D_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCM_FEAT_0           (*(volatile hw_gpu3d_gcm_feat_0_t *) HW_GPU3D_GCM_FEAT_0_ADDR)
#define HW_GPU3D_GCM_FEAT_0_RD()      (HW_GPU3D_GCM_FEAT_0.U)
#define HW_GPU3D_GCM_FEAT_0_WR(v)     (HW_GPU3D_GCM_FEAT_0.U = (v))
#define HW_GPU3D_GCM_FEAT_0_SET(v)    (HW_GPU3D_GCM_FEAT_0_WR(HW_GPU3D_GCM_FEAT_0_RD() |  (v)))
#define HW_GPU3D_GCM_FEAT_0_CLR(v)    (HW_GPU3D_GCM_FEAT_0_WR(HW_GPU3D_GCM_FEAT_0_RD() & ~(v)))
#define HW_GPU3D_GCM_FEAT_0_TOG(v)    (HW_GPU3D_GCM_FEAT_0_WR(HW_GPU3D_GCM_FEAT_0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCM_FEAT_0 bitfields
 */

/* --- Register HW_GPU3D_GCM_FEAT_0, field FLIP_Y
 *
 * Y flipping capability is added to resolve.
 */

#define BP_GPU3D_GCM_FEAT_0_FLIP_Y      0
#define BM_GPU3D_GCM_FEAT_0_FLIP_Y      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_FLIP_Y(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCM_FEAT_0_FLIP_Y)
#else
#define BF_GPU3D_GCM_FEAT_0_FLIP_Y(v)   (((v) << 0) & BM_GPU3D_GCM_FEAT_0_FLIP_Y)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_FLIP_Y(v)   BF_CS1(GPU3D_GCM_FEAT_0, FLIP_Y, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field DUAL_RETURN_BUS
 *
 * Dual Return Bus from HI to clients.
 */

#define BP_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS      1
#define BM_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS(v)   ((((reg32_t) v) << 1) & BM_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS)
#else
#define BF_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS(v)   (((v) << 1) & BM_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS(v)   BF_CS1(GPU3D_GCM_FEAT_0, DUAL_RETURN_BUS, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field ENDIANNESS_CONFIG
 *
 * Configurable endianness support.
 */

#define BP_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG      2
#define BM_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG(v)   ((((reg32_t) v) << 2) & BM_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG)
#else
#define BF_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG(v)   (((v) << 2) & BM_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG(v)   BF_CS1(GPU3D_GCM_FEAT_0, ENDIANNESS_CONFIG, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field TESTURE8_K
 *
 * Supports 8Kx8K textures.
 */

#define BP_GPU3D_GCM_FEAT_0_TESTURE8_K      3
#define BM_GPU3D_GCM_FEAT_0_TESTURE8_K      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_TESTURE8_K(v)   ((((reg32_t) v) << 3) & BM_GPU3D_GCM_FEAT_0_TESTURE8_K)
#else
#define BF_GPU3D_GCM_FEAT_0_TESTURE8_K(v)   (((v) << 3) & BM_GPU3D_GCM_FEAT_0_TESTURE8_K)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_TESTURE8_K(v)   BF_CS1(GPU3D_GCM_FEAT_0, TESTURE8_K, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field CORRECT_TEXTURE_CONVERTER
 *
 * Driver hack is not needed.
 */

#define BP_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER      4
#define BM_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER(v)   ((((reg32_t) v) << 4) & BM_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER)
#else
#define BF_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER(v)   (((v) << 4) & BM_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER(v)   BF_CS1(GPU3D_GCM_FEAT_0, CORRECT_TEXTURE_CONVERTER, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field SPECIAL_MSAA_LOD
 *
 * Special LOD calculation when MSAA is on.
 */

#define BP_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD      5
#define BM_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD(v)   ((((reg32_t) v) << 5) & BM_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD)
#else
#define BF_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD(v)   (((v) << 5) & BM_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD(v)   BF_CS1(GPU3D_GCM_FEAT_0, SPECIAL_MSAA_LOD, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field FAST_CLEAR_FLUSH
 *
 * Proper flush is done in fast clear cache.
 */

#define BP_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH      6
#define BM_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH(v)   ((((reg32_t) v) << 6) & BM_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH)
#else
#define BF_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH(v)   (((v) << 6) & BM_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH(v)   BF_CS1(GPU3D_GCM_FEAT_0, FAST_CLEAR_FLUSH, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field CORRECT_AUTO_DISABLE
 *
 * Auto disable in FC is correct.
 */

#define BP_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE      8
#define BM_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE(v)   ((((reg32_t) v) << 8) & BM_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE)
#else
#define BF_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE(v)   (((v) << 8) & BM_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE(v)   BF_CS1(GPU3D_GCM_FEAT_0, CORRECT_AUTO_DISABLE, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field RENDER_8K
 *
 * Supports 8K render target.
 */

#define BP_GPU3D_GCM_FEAT_0_RENDER_8K      9
#define BM_GPU3D_GCM_FEAT_0_RENDER_8K      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_RENDER_8K(v)   ((((reg32_t) v) << 9) & BM_GPU3D_GCM_FEAT_0_RENDER_8K)
#else
#define BF_GPU3D_GCM_FEAT_0_RENDER_8K(v)   (((v) << 9) & BM_GPU3D_GCM_FEAT_0_RENDER_8K)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_RENDER_8K(v)   BF_CS1(GPU3D_GCM_FEAT_0, RENDER_8K, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field TILE_STATUS_2BITS
 *
 * 2 bits are used instead of 4 bits for tile status.
 */

#define BP_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS      10
#define BM_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS(v)   ((((reg32_t) v) << 10) & BM_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS)
#else
#define BF_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS(v)   (((v) << 10) & BM_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS(v)   BF_CS1(GPU3D_GCM_FEAT_0, TILE_STATUS_2BITS, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field SEPARATE_TILE_STATUS_WHEN_INTERLEAVED
 *
 * Use 2 separate tile status buffers in interleaved mode.
 */

#define BP_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED      11
#define BM_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED(v)   ((((reg32_t) v) << 11) & BM_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED)
#else
#define BF_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED(v)   (((v) << 11) & BM_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED(v)   BF_CS1(GPU3D_GCM_FEAT_0, SEPARATE_TILE_STATUS_WHEN_INTERLEAVED, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field SUPER_TILED_32X32
 *
 * 32x32 super tile is available.
 */

#define BP_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32      12
#define BM_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32(v)   ((((reg32_t) v) << 12) & BM_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32)
#else
#define BF_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32(v)   (((v) << 12) & BM_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32(v)   BF_CS1(GPU3D_GCM_FEAT_0, SUPER_TILED_32X32, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field VG_20
 *
 * Major updates to VG pipe (TS buffer tiling. State masking.).
 */

#define BP_GPU3D_GCM_FEAT_0_VG_20      13
#define BM_GPU3D_GCM_FEAT_0_VG_20      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_VG_20(v)   ((((reg32_t) v) << 13) & BM_GPU3D_GCM_FEAT_0_VG_20)
#else
#define BF_GPU3D_GCM_FEAT_0_VG_20(v)   (((v) << 13) & BM_GPU3D_GCM_FEAT_0_VG_20)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_VG_20(v)   BF_CS1(GPU3D_GCM_FEAT_0, VG_20, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field TS_EXTENDED_COMMANDS
 *
 * New commands added to the tessellator.
 */

#define BP_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS      14
#define BM_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS(v)   ((((reg32_t) v) << 14) & BM_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS)
#else
#define BF_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS(v)   (((v) << 14) & BM_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS(v)   BF_CS1(GPU3D_GCM_FEAT_0, TS_EXTENDED_COMMANDS, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field COMPRESSION_FIFO_FIXED
 *
 * If this bit is not set, the FIFO counter should be set to 50. Else, the default should
 * remain.
 */

#define BP_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED      15
#define BM_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED(v)   ((((reg32_t) v) << 15) & BM_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED)
#else
#define BF_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED(v)   (((v) << 15) & BM_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED(v)   BF_CS1(GPU3D_GCM_FEAT_0, COMPRESSION_FIFO_FIXED, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field EXTRA_SHADER_INSTRUCTIONS0
 *
 * Floor, ceil, and sign instructions are available.
 */

#define BP_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0      16
#define BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0(v)   ((((reg32_t) v) << 16) & BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0)
#else
#define BF_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0(v)   (((v) << 16) & BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0(v)   BF_CS1(GPU3D_GCM_FEAT_0, EXTRA_SHADER_INSTRUCTIONS0, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field VG_FILTER
 *
 * VG filter is available.
 */

#define BP_GPU3D_GCM_FEAT_0_VG_FILTER      17
#define BM_GPU3D_GCM_FEAT_0_VG_FILTER      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_VG_FILTER(v)   ((((reg32_t) v) << 17) & BM_GPU3D_GCM_FEAT_0_VG_FILTER)
#else
#define BF_GPU3D_GCM_FEAT_0_VG_FILTER(v)   (((v) << 17) & BM_GPU3D_GCM_FEAT_0_VG_FILTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_VG_FILTER(v)   BF_CS1(GPU3D_GCM_FEAT_0, VG_FILTER, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field VG_21
 *
 * Minor updates to VG pipe (Event generation from VG, TS, PE). Tiled image support.
 */

#define BP_GPU3D_GCM_FEAT_0_VG_21      18
#define BM_GPU3D_GCM_FEAT_0_VG_21      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_VG_21(v)   ((((reg32_t) v) << 18) & BM_GPU3D_GCM_FEAT_0_VG_21)
#else
#define BF_GPU3D_GCM_FEAT_0_VG_21(v)   (((v) << 18) & BM_GPU3D_GCM_FEAT_0_VG_21)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_VG_21(v)   BF_CS1(GPU3D_GCM_FEAT_0, VG_21, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field SHADER_GETS_W
 *
 * W is sent to SH from RA.
 */

#define BP_GPU3D_GCM_FEAT_0_SHADER_GETS_W      19
#define BM_GPU3D_GCM_FEAT_0_SHADER_GETS_W      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_SHADER_GETS_W(v)   ((((reg32_t) v) << 19) & BM_GPU3D_GCM_FEAT_0_SHADER_GETS_W)
#else
#define BF_GPU3D_GCM_FEAT_0_SHADER_GETS_W(v)   (((v) << 19) & BM_GPU3D_GCM_FEAT_0_SHADER_GETS_W)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_SHADER_GETS_W(v)   BF_CS1(GPU3D_GCM_FEAT_0, SHADER_GETS_W, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field EXTRA_SHADER_INSTRUCTIONS1
 *
 * Sqrt, sin, cos intructions are available.
 */

#define BP_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1      20
#define BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1(v)   ((((reg32_t) v) << 20) & BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1)
#else
#define BF_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1(v)   (((v) << 20) & BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1(v)   BF_CS1(GPU3D_GCM_FEAT_0, EXTRA_SHADER_INSTRUCTIONS1, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field DEFAULT_REG0
 *
 * Unavailable registers will return 0.
 */

#define BP_GPU3D_GCM_FEAT_0_DEFAULT_REG0      21
#define BM_GPU3D_GCM_FEAT_0_DEFAULT_REG0      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_DEFAULT_REG0(v)   ((((reg32_t) v) << 21) & BM_GPU3D_GCM_FEAT_0_DEFAULT_REG0)
#else
#define BF_GPU3D_GCM_FEAT_0_DEFAULT_REG0(v)   (((v) << 21) & BM_GPU3D_GCM_FEAT_0_DEFAULT_REG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_DEFAULT_REG0(v)   BF_CS1(GPU3D_GCM_FEAT_0, DEFAULT_REG0, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field MC_20
 *
 * New stlye MC with separate paths for color and depth.
 */

#define BP_GPU3D_GCM_FEAT_0_MC_20      22
#define BM_GPU3D_GCM_FEAT_0_MC_20      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_MC_20(v)   ((((reg32_t) v) << 22) & BM_GPU3D_GCM_FEAT_0_MC_20)
#else
#define BF_GPU3D_GCM_FEAT_0_MC_20(v)   (((v) << 22) & BM_GPU3D_GCM_FEAT_0_MC_20)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_MC_20(v)   BF_CS1(GPU3D_GCM_FEAT_0, MC_20, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field SHADER_MSAA_SIDEBAND
 *
 * Put the MSAA data into sideband fifo.
 */

#define BP_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND      23
#define BM_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND(v)   ((((reg32_t) v) << 23) & BM_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND)
#else
#define BF_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND(v)   (((v) << 23) & BM_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND(v)   BF_CS1(GPU3D_GCM_FEAT_0, SHADER_MSAA_SIDEBAND, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field BUG_FIXES0
 *

 */

#define BP_GPU3D_GCM_FEAT_0_BUG_FIXES0      24
#define BM_GPU3D_GCM_FEAT_0_BUG_FIXES0      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_BUG_FIXES0(v)   ((((reg32_t) v) << 24) & BM_GPU3D_GCM_FEAT_0_BUG_FIXES0)
#else
#define BF_GPU3D_GCM_FEAT_0_BUG_FIXES0(v)   (((v) << 24) & BM_GPU3D_GCM_FEAT_0_BUG_FIXES0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_BUG_FIXES0(v)   BF_CS1(GPU3D_GCM_FEAT_0, BUG_FIXES0, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field VAA
 *
 * VAA is available or not.
 */

#define BP_GPU3D_GCM_FEAT_0_VAA      25
#define BM_GPU3D_GCM_FEAT_0_VAA      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_VAA(v)   ((((reg32_t) v) << 25) & BM_GPU3D_GCM_FEAT_0_VAA)
#else
#define BF_GPU3D_GCM_FEAT_0_VAA(v)   (((v) << 25) & BM_GPU3D_GCM_FEAT_0_VAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_VAA(v)   BF_CS1(GPU3D_GCM_FEAT_0, VAA, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field BYPASS_IN_MSAA
 *
 * Shader supports bypass modew when MSAA is enabled.
 */

#define BP_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA      26
#define BM_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA(v)   ((((reg32_t) v) << 26) & BM_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA)
#else
#define BF_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA(v)   (((v) << 26) & BM_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA(v)   BF_CS1(GPU3D_GCM_FEAT_0, BYPASS_IN_MSAA, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field HIERARCHICAL_Z
 *
 * Hierarchical Z is supported.
 */

#define BP_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z      27
#define BM_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z(v)   ((((reg32_t) v) << 27) & BM_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z)
#else
#define BF_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z(v)   (((v) << 27) & BM_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z(v)   BF_CS1(GPU3D_GCM_FEAT_0, HIERARCHICAL_Z, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field NEW_TEXTURE
 *
 * New texture unit is available.
 */

#define BP_GPU3D_GCM_FEAT_0_NEW_TEXTURE      28
#define BM_GPU3D_GCM_FEAT_0_NEW_TEXTURE      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_NEW_TEXTURE(v)   ((((reg32_t) v) << 28) & BM_GPU3D_GCM_FEAT_0_NEW_TEXTURE)
#else
#define BF_GPU3D_GCM_FEAT_0_NEW_TEXTURE(v)   (((v) << 28) & BM_GPU3D_GCM_FEAT_0_NEW_TEXTURE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_NEW_TEXTURE(v)   BF_CS1(GPU3D_GCM_FEAT_0, NEW_TEXTURE, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field A8_TARGET_SUPPORT
 *
 * 2D engine supports A8 target.
 */

#define BP_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT      29
#define BM_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT(v)   ((((reg32_t) v) << 29) & BM_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT)
#else
#define BF_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT(v)   (((v) << 29) & BM_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT(v)   BF_CS1(GPU3D_GCM_FEAT_0, A8_TARGET_SUPPORT, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field CORRECT_STENCIL
 *
 * Correct stencil behavior in depth only.
 */

#define BP_GPU3D_GCM_FEAT_0_CORRECT_STENCIL      30
#define BM_GPU3D_GCM_FEAT_0_CORRECT_STENCIL      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_CORRECT_STENCIL(v)   ((((reg32_t) v) << 30) & BM_GPU3D_GCM_FEAT_0_CORRECT_STENCIL)
#else
#define BF_GPU3D_GCM_FEAT_0_CORRECT_STENCIL(v)   (((v) << 30) & BM_GPU3D_GCM_FEAT_0_CORRECT_STENCIL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_CORRECT_STENCIL(v)   BF_CS1(GPU3D_GCM_FEAT_0, CORRECT_STENCIL, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_0, field ENHANCE_VR
 *
 * Enhance VR and add a mode to walk 16 pixels in 16-bit mode in Vertical pass to improve $
 * hit rate when rotating 90/270.
 */

#define BP_GPU3D_GCM_FEAT_0_ENHANCE_VR      31
#define BM_GPU3D_GCM_FEAT_0_ENHANCE_VR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_0_ENHANCE_VR(v)   ((((reg32_t) v) << 31) & BM_GPU3D_GCM_FEAT_0_ENHANCE_VR)
#else
#define BF_GPU3D_GCM_FEAT_0_ENHANCE_VR(v)   (((v) << 31) & BM_GPU3D_GCM_FEAT_0_ENHANCE_VR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_0_ENHANCE_VR(v)   BF_CS1(GPU3D_GCM_FEAT_0, ENHANCE_VR, v)
#endif

/*!
 * @brief HW_GPU3D_GCC_CRTL - GCCacheControl
 *
 * Not used.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NOT_USED : 32; //!< 
    } B;
} hw_gpu3d_gcc_crtl_t;
#endif

/*
 * constants & macros for entire GPU3D_GCC_CRTL register
 */
#define HW_GPU3D_GCC_CRTL_ADDR      (REGS_GPU3D_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCC_CRTL           (*(volatile hw_gpu3d_gcc_crtl_t *) HW_GPU3D_GCC_CRTL_ADDR)
#define HW_GPU3D_GCC_CRTL_RD()      (HW_GPU3D_GCC_CRTL.U)
#define HW_GPU3D_GCC_CRTL_WR(v)     (HW_GPU3D_GCC_CRTL.U = (v))
#define HW_GPU3D_GCC_CRTL_SET(v)    (HW_GPU3D_GCC_CRTL_WR(HW_GPU3D_GCC_CRTL_RD() |  (v)))
#define HW_GPU3D_GCC_CRTL_CLR(v)    (HW_GPU3D_GCC_CRTL_WR(HW_GPU3D_GCC_CRTL_RD() & ~(v)))
#define HW_GPU3D_GCC_CRTL_TOG(v)    (HW_GPU3D_GCC_CRTL_WR(HW_GPU3D_GCC_CRTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCC_CRTL bitfields
 */

/* --- Register HW_GPU3D_GCC_CRTL, field NOT_USED
 *

 */

#define BP_GPU3D_GCC_CRTL_NOT_USED      0
#define BM_GPU3D_GCC_CRTL_NOT_USED      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_CRTL_NOT_USED(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCC_CRTL_NOT_USED)
#else
#define BF_GPU3D_GCC_CRTL_NOT_USED(v)   (((v) << 0) & BM_GPU3D_GCC_CRTL_NOT_USED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_CRTL_NOT_USED(v)   BF_CS1(GPU3D_GCC_CRTL, NOT_USED, v)
#endif

/*!
 * @brief HW_GPU3D_GCR_MEM_CTRS - GCResetMemCounters
 *
 * Writing 1 will reset the counters and stop counting. Write 0 to start counting again. This
 * register is write only so it has no reset value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESET : 32; //!< 
    } B;
} hw_gpu3d_gcr_mem_ctrs_t;
#endif

/*
 * constants & macros for entire GPU3D_GCR_MEM_CTRS register
 */
#define HW_GPU3D_GCR_MEM_CTRS_ADDR      (REGS_GPU3D_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCR_MEM_CTRS           (*(volatile hw_gpu3d_gcr_mem_ctrs_t *) HW_GPU3D_GCR_MEM_CTRS_ADDR)
#define HW_GPU3D_GCR_MEM_CTRS_RD()      (HW_GPU3D_GCR_MEM_CTRS.U)
#define HW_GPU3D_GCR_MEM_CTRS_WR(v)     (HW_GPU3D_GCR_MEM_CTRS.U = (v))
#define HW_GPU3D_GCR_MEM_CTRS_SET(v)    (HW_GPU3D_GCR_MEM_CTRS_WR(HW_GPU3D_GCR_MEM_CTRS_RD() |  (v)))
#define HW_GPU3D_GCR_MEM_CTRS_CLR(v)    (HW_GPU3D_GCR_MEM_CTRS_WR(HW_GPU3D_GCR_MEM_CTRS_RD() & ~(v)))
#define HW_GPU3D_GCR_MEM_CTRS_TOG(v)    (HW_GPU3D_GCR_MEM_CTRS_WR(HW_GPU3D_GCR_MEM_CTRS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCR_MEM_CTRS bitfields
 */

/* --- Register HW_GPU3D_GCR_MEM_CTRS, field RESET
 *

 */

#define BP_GPU3D_GCR_MEM_CTRS_RESET      0
#define BM_GPU3D_GCR_MEM_CTRS_RESET      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCR_MEM_CTRS_RESET(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCR_MEM_CTRS_RESET)
#else
#define BF_GPU3D_GCR_MEM_CTRS_RESET(v)   (((v) << 0) & BM_GPU3D_GCR_MEM_CTRS_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCR_MEM_CTRS_RESET(v)   BF_CS1(GPU3D_GCR_MEM_CTRS, RESET, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_READS - gcTotalReads
 *
 * Total reads in terms of 64 bits.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gct_reads_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_READS register
 */
#define HW_GPU3D_GCT_READS_ADDR      (REGS_GPU3D_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_READS           (*(volatile hw_gpu3d_gct_reads_t *) HW_GPU3D_GCT_READS_ADDR)
#define HW_GPU3D_GCT_READS_RD()      (HW_GPU3D_GCT_READS.U)
#define HW_GPU3D_GCT_READS_WR(v)     (HW_GPU3D_GCT_READS.U = (v))
#define HW_GPU3D_GCT_READS_SET(v)    (HW_GPU3D_GCT_READS_WR(HW_GPU3D_GCT_READS_RD() |  (v)))
#define HW_GPU3D_GCT_READS_CLR(v)    (HW_GPU3D_GCT_READS_WR(HW_GPU3D_GCT_READS_RD() & ~(v)))
#define HW_GPU3D_GCT_READS_TOG(v)    (HW_GPU3D_GCT_READS_WR(HW_GPU3D_GCT_READS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_READS bitfields
 */

/* --- Register HW_GPU3D_GCT_READS, field COUNT
 *

 */

#define BP_GPU3D_GCT_READS_COUNT      0
#define BM_GPU3D_GCT_READS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_READS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_READS_COUNT)
#else
#define BF_GPU3D_GCT_READS_COUNT(v)   (((v) << 0) & BM_GPU3D_GCT_READS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_READS_COUNT(v)   BF_CS1(GPU3D_GCT_READS, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_WRITES - gcTotalWrites
 *
 * Total writes in terms of 64 bits.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gct_writes_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_WRITES register
 */
#define HW_GPU3D_GCT_WRITES_ADDR      (REGS_GPU3D_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_WRITES           (*(volatile hw_gpu3d_gct_writes_t *) HW_GPU3D_GCT_WRITES_ADDR)
#define HW_GPU3D_GCT_WRITES_RD()      (HW_GPU3D_GCT_WRITES.U)
#define HW_GPU3D_GCT_WRITES_WR(v)     (HW_GPU3D_GCT_WRITES.U = (v))
#define HW_GPU3D_GCT_WRITES_SET(v)    (HW_GPU3D_GCT_WRITES_WR(HW_GPU3D_GCT_WRITES_RD() |  (v)))
#define HW_GPU3D_GCT_WRITES_CLR(v)    (HW_GPU3D_GCT_WRITES_WR(HW_GPU3D_GCT_WRITES_RD() & ~(v)))
#define HW_GPU3D_GCT_WRITES_TOG(v)    (HW_GPU3D_GCT_WRITES_WR(HW_GPU3D_GCT_WRITES_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_WRITES bitfields
 */

/* --- Register HW_GPU3D_GCT_WRITES, field COUNT
 *

 */

#define BP_GPU3D_GCT_WRITES_COUNT      0
#define BM_GPU3D_GCT_WRITES_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_WRITES_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_WRITES_COUNT)
#else
#define BF_GPU3D_GCT_WRITES_COUNT(v)   (((v) << 0) & BM_GPU3D_GCT_WRITES_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_WRITES_COUNT(v)   BF_CS1(GPU3D_GCT_WRITES, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCC_SPECS - gcChipSpecs
 *
 * Specs for the chip. This register has no set reset value. It varies with the
 * implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned STREAMS : 4; //!< Number of vertex streams.
        unsigned TEAMP_REGISTERS : 4; //!< Log2 of temporary registers.
        unsigned THREAD_COUNT : 4; //!< Log2 of thread count.
        unsigned VERTEX_CACHE_SIZE : 5; //!< Number of entries in the vertex shader cache.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned NUM_SHADER_CORES : 5; //!< Number of shader cores.
        unsigned NUM_PIXEL_PIPES : 3; //!< Number of pixel pipes.
        unsigned VERTEX_OUTPUT_BUFFER_SIZE : 4; //!< Log2 of vertex output buffer size.
    } B;
} hw_gpu3d_gcc_specs_t;
#endif

/*
 * constants & macros for entire GPU3D_GCC_SPECS register
 */
#define HW_GPU3D_GCC_SPECS_ADDR      (REGS_GPU3D_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCC_SPECS           (*(volatile hw_gpu3d_gcc_specs_t *) HW_GPU3D_GCC_SPECS_ADDR)
#define HW_GPU3D_GCC_SPECS_RD()      (HW_GPU3D_GCC_SPECS.U)
#define HW_GPU3D_GCC_SPECS_WR(v)     (HW_GPU3D_GCC_SPECS.U = (v))
#define HW_GPU3D_GCC_SPECS_SET(v)    (HW_GPU3D_GCC_SPECS_WR(HW_GPU3D_GCC_SPECS_RD() |  (v)))
#define HW_GPU3D_GCC_SPECS_CLR(v)    (HW_GPU3D_GCC_SPECS_WR(HW_GPU3D_GCC_SPECS_RD() & ~(v)))
#define HW_GPU3D_GCC_SPECS_TOG(v)    (HW_GPU3D_GCC_SPECS_WR(HW_GPU3D_GCC_SPECS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCC_SPECS bitfields
 */

/* --- Register HW_GPU3D_GCC_SPECS, field STREAMS
 *
 * Number of vertex streams.
 */

#define BP_GPU3D_GCC_SPECS_STREAMS      0
#define BM_GPU3D_GCC_SPECS_STREAMS      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_SPECS_STREAMS(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCC_SPECS_STREAMS)
#else
#define BF_GPU3D_GCC_SPECS_STREAMS(v)   (((v) << 0) & BM_GPU3D_GCC_SPECS_STREAMS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_SPECS_STREAMS(v)   BF_CS1(GPU3D_GCC_SPECS, STREAMS, v)
#endif

/* --- Register HW_GPU3D_GCC_SPECS, field TEAMP_REGISTERS
 *
 * Log2 of temporary registers.
 */

#define BP_GPU3D_GCC_SPECS_TEAMP_REGISTERS      4
#define BM_GPU3D_GCC_SPECS_TEAMP_REGISTERS      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_SPECS_TEAMP_REGISTERS(v)   ((((reg32_t) v) << 4) & BM_GPU3D_GCC_SPECS_TEAMP_REGISTERS)
#else
#define BF_GPU3D_GCC_SPECS_TEAMP_REGISTERS(v)   (((v) << 4) & BM_GPU3D_GCC_SPECS_TEAMP_REGISTERS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_SPECS_TEAMP_REGISTERS(v)   BF_CS1(GPU3D_GCC_SPECS, TEAMP_REGISTERS, v)
#endif

/* --- Register HW_GPU3D_GCC_SPECS, field THREAD_COUNT
 *
 * Log2 of thread count.
 */

#define BP_GPU3D_GCC_SPECS_THREAD_COUNT      8
#define BM_GPU3D_GCC_SPECS_THREAD_COUNT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_SPECS_THREAD_COUNT(v)   ((((reg32_t) v) << 8) & BM_GPU3D_GCC_SPECS_THREAD_COUNT)
#else
#define BF_GPU3D_GCC_SPECS_THREAD_COUNT(v)   (((v) << 8) & BM_GPU3D_GCC_SPECS_THREAD_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_SPECS_THREAD_COUNT(v)   BF_CS1(GPU3D_GCC_SPECS, THREAD_COUNT, v)
#endif

/* --- Register HW_GPU3D_GCC_SPECS, field VERTEX_CACHE_SIZE
 *
 * Number of entries in the vertex shader cache.
 */

#define BP_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE      12
#define BM_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE      0x0001f000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE(v)   ((((reg32_t) v) << 12) & BM_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE)
#else
#define BF_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE(v)   (((v) << 12) & BM_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE(v)   BF_CS1(GPU3D_GCC_SPECS, VERTEX_CACHE_SIZE, v)
#endif

/* --- Register HW_GPU3D_GCC_SPECS, field NUM_SHADER_CORES
 *
 * Number of shader cores.
 */

#define BP_GPU3D_GCC_SPECS_NUM_SHADER_CORES      20
#define BM_GPU3D_GCC_SPECS_NUM_SHADER_CORES      0x01f00000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_SPECS_NUM_SHADER_CORES(v)   ((((reg32_t) v) << 20) & BM_GPU3D_GCC_SPECS_NUM_SHADER_CORES)
#else
#define BF_GPU3D_GCC_SPECS_NUM_SHADER_CORES(v)   (((v) << 20) & BM_GPU3D_GCC_SPECS_NUM_SHADER_CORES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_SPECS_NUM_SHADER_CORES(v)   BF_CS1(GPU3D_GCC_SPECS, NUM_SHADER_CORES, v)
#endif

/* --- Register HW_GPU3D_GCC_SPECS, field NUM_PIXEL_PIPES
 *
 * Number of pixel pipes.
 */

#define BP_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES      25
#define BM_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES      0x0e000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES(v)   ((((reg32_t) v) << 25) & BM_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES)
#else
#define BF_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES(v)   (((v) << 25) & BM_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES(v)   BF_CS1(GPU3D_GCC_SPECS, NUM_PIXEL_PIPES, v)
#endif

/* --- Register HW_GPU3D_GCC_SPECS, field VERTEX_OUTPUT_BUFFER_SIZE
 *
 * Log2 of vertex output buffer size.
 */

#define BP_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE      28
#define BM_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE(v)   ((((reg32_t) v) << 28) & BM_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE)
#else
#define BF_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE(v)   (((v) << 28) & BM_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE(v)   BF_CS1(GPU3D_GCC_SPECS, VERTEX_OUTPUT_BUFFER_SIZE, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_WRITE_BURSTS - gcTotalWriteBursts
 *
 * Total write Data Count in terms of 64 bits. This register has no reset value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gct_write_bursts_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_WRITE_BURSTS register
 */
#define HW_GPU3D_GCT_WRITE_BURSTS_ADDR      (REGS_GPU3D_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_WRITE_BURSTS           (*(volatile hw_gpu3d_gct_write_bursts_t *) HW_GPU3D_GCT_WRITE_BURSTS_ADDR)
#define HW_GPU3D_GCT_WRITE_BURSTS_RD()      (HW_GPU3D_GCT_WRITE_BURSTS.U)
#define HW_GPU3D_GCT_WRITE_BURSTS_WR(v)     (HW_GPU3D_GCT_WRITE_BURSTS.U = (v))
#define HW_GPU3D_GCT_WRITE_BURSTS_SET(v)    (HW_GPU3D_GCT_WRITE_BURSTS_WR(HW_GPU3D_GCT_WRITE_BURSTS_RD() |  (v)))
#define HW_GPU3D_GCT_WRITE_BURSTS_CLR(v)    (HW_GPU3D_GCT_WRITE_BURSTS_WR(HW_GPU3D_GCT_WRITE_BURSTS_RD() & ~(v)))
#define HW_GPU3D_GCT_WRITE_BURSTS_TOG(v)    (HW_GPU3D_GCT_WRITE_BURSTS_WR(HW_GPU3D_GCT_WRITE_BURSTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_WRITE_BURSTS bitfields
 */

/* --- Register HW_GPU3D_GCT_WRITE_BURSTS, field COUNT
 *

 */

#define BP_GPU3D_GCT_WRITE_BURSTS_COUNT      0
#define BM_GPU3D_GCT_WRITE_BURSTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_WRITE_BURSTS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_WRITE_BURSTS_COUNT)
#else
#define BF_GPU3D_GCT_WRITE_BURSTS_COUNT(v)   (((v) << 0) & BM_GPU3D_GCT_WRITE_BURSTS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_WRITE_BURSTS_COUNT(v)   BF_CS1(GPU3D_GCT_WRITE_BURSTS, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_WRITE_REQS - gcTotalWriteReqs
 *
 * Total write Request Count. This register has no reset value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gct_write_reqs_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_WRITE_REQS register
 */
#define HW_GPU3D_GCT_WRITE_REQS_ADDR      (REGS_GPU3D_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_WRITE_REQS           (*(volatile hw_gpu3d_gct_write_reqs_t *) HW_GPU3D_GCT_WRITE_REQS_ADDR)
#define HW_GPU3D_GCT_WRITE_REQS_RD()      (HW_GPU3D_GCT_WRITE_REQS.U)
#define HW_GPU3D_GCT_WRITE_REQS_WR(v)     (HW_GPU3D_GCT_WRITE_REQS.U = (v))
#define HW_GPU3D_GCT_WRITE_REQS_SET(v)    (HW_GPU3D_GCT_WRITE_REQS_WR(HW_GPU3D_GCT_WRITE_REQS_RD() |  (v)))
#define HW_GPU3D_GCT_WRITE_REQS_CLR(v)    (HW_GPU3D_GCT_WRITE_REQS_WR(HW_GPU3D_GCT_WRITE_REQS_RD() & ~(v)))
#define HW_GPU3D_GCT_WRITE_REQS_TOG(v)    (HW_GPU3D_GCT_WRITE_REQS_WR(HW_GPU3D_GCT_WRITE_REQS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_WRITE_REQS bitfields
 */

/* --- Register HW_GPU3D_GCT_WRITE_REQS, field COUNT
 *

 */

#define BP_GPU3D_GCT_WRITE_REQS_COUNT      0
#define BM_GPU3D_GCT_WRITE_REQS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_WRITE_REQS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_WRITE_REQS_COUNT)
#else
#define BF_GPU3D_GCT_WRITE_REQS_COUNT(v)   (((v) << 0) & BM_GPU3D_GCT_WRITE_REQS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_WRITE_REQS_COUNT(v)   BF_CS1(GPU3D_GCT_WRITE_REQS, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_WRITE_LASTS - gcTotalWriteLasts
 *
 * Total WLAST Count. This is used to match with GCTotalWriteReqs. This register has no reset
 * value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gct_write_lasts_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_WRITE_LASTS register
 */
#define HW_GPU3D_GCT_WRITE_LASTS_ADDR      (REGS_GPU3D_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_WRITE_LASTS           (*(volatile hw_gpu3d_gct_write_lasts_t *) HW_GPU3D_GCT_WRITE_LASTS_ADDR)
#define HW_GPU3D_GCT_WRITE_LASTS_RD()      (HW_GPU3D_GCT_WRITE_LASTS.U)
#define HW_GPU3D_GCT_WRITE_LASTS_WR(v)     (HW_GPU3D_GCT_WRITE_LASTS.U = (v))
#define HW_GPU3D_GCT_WRITE_LASTS_SET(v)    (HW_GPU3D_GCT_WRITE_LASTS_WR(HW_GPU3D_GCT_WRITE_LASTS_RD() |  (v)))
#define HW_GPU3D_GCT_WRITE_LASTS_CLR(v)    (HW_GPU3D_GCT_WRITE_LASTS_WR(HW_GPU3D_GCT_WRITE_LASTS_RD() & ~(v)))
#define HW_GPU3D_GCT_WRITE_LASTS_TOG(v)    (HW_GPU3D_GCT_WRITE_LASTS_WR(HW_GPU3D_GCT_WRITE_LASTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_WRITE_LASTS bitfields
 */

/* --- Register HW_GPU3D_GCT_WRITE_LASTS, field COUNT
 *

 */

#define BP_GPU3D_GCT_WRITE_LASTS_COUNT      0
#define BM_GPU3D_GCT_WRITE_LASTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_WRITE_LASTS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_WRITE_LASTS_COUNT)
#else
#define BF_GPU3D_GCT_WRITE_LASTS_COUNT(v)   (((v) << 0) & BM_GPU3D_GCT_WRITE_LASTS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_WRITE_LASTS_COUNT(v)   BF_CS1(GPU3D_GCT_WRITE_LASTS, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_READ_BURSTS - gcTotalReadBursts
 *
 * Total Read Data COunt in terms of 64 bits. This register has no reset value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gct_read_bursts_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_READ_BURSTS register
 */
#define HW_GPU3D_GCT_READ_BURSTS_ADDR      (REGS_GPU3D_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_READ_BURSTS           (*(volatile hw_gpu3d_gct_read_bursts_t *) HW_GPU3D_GCT_READ_BURSTS_ADDR)
#define HW_GPU3D_GCT_READ_BURSTS_RD()      (HW_GPU3D_GCT_READ_BURSTS.U)
#define HW_GPU3D_GCT_READ_BURSTS_WR(v)     (HW_GPU3D_GCT_READ_BURSTS.U = (v))
#define HW_GPU3D_GCT_READ_BURSTS_SET(v)    (HW_GPU3D_GCT_READ_BURSTS_WR(HW_GPU3D_GCT_READ_BURSTS_RD() |  (v)))
#define HW_GPU3D_GCT_READ_BURSTS_CLR(v)    (HW_GPU3D_GCT_READ_BURSTS_WR(HW_GPU3D_GCT_READ_BURSTS_RD() & ~(v)))
#define HW_GPU3D_GCT_READ_BURSTS_TOG(v)    (HW_GPU3D_GCT_READ_BURSTS_WR(HW_GPU3D_GCT_READ_BURSTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_READ_BURSTS bitfields
 */

/* --- Register HW_GPU3D_GCT_READ_BURSTS, field COUNT
 *

 */

#define BP_GPU3D_GCT_READ_BURSTS_COUNT      0
#define BM_GPU3D_GCT_READ_BURSTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_READ_BURSTS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_READ_BURSTS_COUNT)
#else
#define BF_GPU3D_GCT_READ_BURSTS_COUNT(v)   (((v) << 0) & BM_GPU3D_GCT_READ_BURSTS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_READ_BURSTS_COUNT(v)   BF_CS1(GPU3D_GCT_READ_BURSTS, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_READ_REQS - gcTotalReadReqs
 *
 * Total Read Request Count. This register has no reset value.  s
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gct_read_reqs_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_READ_REQS register
 */
#define HW_GPU3D_GCT_READ_REQS_ADDR      (REGS_GPU3D_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_READ_REQS           (*(volatile hw_gpu3d_gct_read_reqs_t *) HW_GPU3D_GCT_READ_REQS_ADDR)
#define HW_GPU3D_GCT_READ_REQS_RD()      (HW_GPU3D_GCT_READ_REQS.U)
#define HW_GPU3D_GCT_READ_REQS_WR(v)     (HW_GPU3D_GCT_READ_REQS.U = (v))
#define HW_GPU3D_GCT_READ_REQS_SET(v)    (HW_GPU3D_GCT_READ_REQS_WR(HW_GPU3D_GCT_READ_REQS_RD() |  (v)))
#define HW_GPU3D_GCT_READ_REQS_CLR(v)    (HW_GPU3D_GCT_READ_REQS_WR(HW_GPU3D_GCT_READ_REQS_RD() & ~(v)))
#define HW_GPU3D_GCT_READ_REQS_TOG(v)    (HW_GPU3D_GCT_READ_REQS_WR(HW_GPU3D_GCT_READ_REQS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_READ_REQS bitfields
 */

/* --- Register HW_GPU3D_GCT_READ_REQS, field COUNT
 *

 */

#define BP_GPU3D_GCT_READ_REQS_COUNT      0
#define BM_GPU3D_GCT_READ_REQS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_READ_REQS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_READ_REQS_COUNT)
#else
#define BF_GPU3D_GCT_READ_REQS_COUNT(v)   (((v) << 0) & BM_GPU3D_GCT_READ_REQS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_READ_REQS_COUNT(v)   BF_CS1(GPU3D_GCT_READ_REQS, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_READ_LASTS - gcTotalReadLasts
 *
 * Total RLAST Count. This is uset to match with GCTotalReadReqs. This register has no reset
 * value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gct_read_lasts_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_READ_LASTS register
 */
#define HW_GPU3D_GCT_READ_LASTS_ADDR      (REGS_GPU3D_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_READ_LASTS           (*(volatile hw_gpu3d_gct_read_lasts_t *) HW_GPU3D_GCT_READ_LASTS_ADDR)
#define HW_GPU3D_GCT_READ_LASTS_RD()      (HW_GPU3D_GCT_READ_LASTS.U)
#define HW_GPU3D_GCT_READ_LASTS_WR(v)     (HW_GPU3D_GCT_READ_LASTS.U = (v))
#define HW_GPU3D_GCT_READ_LASTS_SET(v)    (HW_GPU3D_GCT_READ_LASTS_WR(HW_GPU3D_GCT_READ_LASTS_RD() |  (v)))
#define HW_GPU3D_GCT_READ_LASTS_CLR(v)    (HW_GPU3D_GCT_READ_LASTS_WR(HW_GPU3D_GCT_READ_LASTS_RD() & ~(v)))
#define HW_GPU3D_GCT_READ_LASTS_TOG(v)    (HW_GPU3D_GCT_READ_LASTS_WR(HW_GPU3D_GCT_READ_LASTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_READ_LASTS bitfields
 */

/* --- Register HW_GPU3D_GCT_READ_LASTS, field COUNT
 *

 */

#define BP_GPU3D_GCT_READ_LASTS_COUNT      0
#define BM_GPU3D_GCT_READ_LASTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_READ_LASTS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_READ_LASTS_COUNT)
#else
#define BF_GPU3D_GCT_READ_LASTS_COUNT(v)   (((v) << 0) & BM_GPU3D_GCT_READ_LASTS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_READ_LASTS_COUNT(v)   BF_CS1(GPU3D_GCT_READ_LASTS, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCGPO_0 - gcGpOut0
 *
 * General Purpose output register 0. R/W but not connected to anywhere.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gcgpo_0_t;
#endif

/*
 * constants & macros for entire GPU3D_GCGPO_0 register
 */
#define HW_GPU3D_GCGPO_0_ADDR      (REGS_GPU3D_BASE + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCGPO_0           (*(volatile hw_gpu3d_gcgpo_0_t *) HW_GPU3D_GCGPO_0_ADDR)
#define HW_GPU3D_GCGPO_0_RD()      (HW_GPU3D_GCGPO_0.U)
#define HW_GPU3D_GCGPO_0_WR(v)     (HW_GPU3D_GCGPO_0.U = (v))
#define HW_GPU3D_GCGPO_0_SET(v)    (HW_GPU3D_GCGPO_0_WR(HW_GPU3D_GCGPO_0_RD() |  (v)))
#define HW_GPU3D_GCGPO_0_CLR(v)    (HW_GPU3D_GCGPO_0_WR(HW_GPU3D_GCGPO_0_RD() & ~(v)))
#define HW_GPU3D_GCGPO_0_TOG(v)    (HW_GPU3D_GCGPO_0_WR(HW_GPU3D_GCGPO_0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCGPO_0 bitfields
 */

/* --- Register HW_GPU3D_GCGPO_0, field COUNT
 *

 */

#define BP_GPU3D_GCGPO_0_COUNT      0
#define BM_GPU3D_GCGPO_0_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCGPO_0_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCGPO_0_COUNT)
#else
#define BF_GPU3D_GCGPO_0_COUNT(v)   (((v) << 0) & BM_GPU3D_GCGPO_0_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCGPO_0_COUNT(v)   BF_CS1(GPU3D_GCGPO_0, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCGPO_1 - gcGpOut1
 *
 * General Purpose output register 1. R/W but not connected to anywhere.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gcgpo_1_t;
#endif

/*
 * constants & macros for entire GPU3D_GCGPO_1 register
 */
#define HW_GPU3D_GCGPO_1_ADDR      (REGS_GPU3D_BASE + 0x6c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCGPO_1           (*(volatile hw_gpu3d_gcgpo_1_t *) HW_GPU3D_GCGPO_1_ADDR)
#define HW_GPU3D_GCGPO_1_RD()      (HW_GPU3D_GCGPO_1.U)
#define HW_GPU3D_GCGPO_1_WR(v)     (HW_GPU3D_GCGPO_1.U = (v))
#define HW_GPU3D_GCGPO_1_SET(v)    (HW_GPU3D_GCGPO_1_WR(HW_GPU3D_GCGPO_1_RD() |  (v)))
#define HW_GPU3D_GCGPO_1_CLR(v)    (HW_GPU3D_GCGPO_1_WR(HW_GPU3D_GCGPO_1_RD() & ~(v)))
#define HW_GPU3D_GCGPO_1_TOG(v)    (HW_GPU3D_GCGPO_1_WR(HW_GPU3D_GCGPO_1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCGPO_1 bitfields
 */

/* --- Register HW_GPU3D_GCGPO_1, field COUNT
 *

 */

#define BP_GPU3D_GCGPO_1_COUNT      0
#define BM_GPU3D_GCGPO_1_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCGPO_1_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCGPO_1_COUNT)
#else
#define BF_GPU3D_GCGPO_1_COUNT(v)   (((v) << 0) & BM_GPU3D_GCGPO_1_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCGPO_1_COUNT(v)   BF_CS1(GPU3D_GCGPO_1, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCGPO_2 - gcGpOut2
 *
 * General Purpose output register 2. R/W but not connected to anywhere.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu3d_gcgpo_2_t;
#endif

/*
 * constants & macros for entire GPU3D_GCGPO_2 register
 */
#define HW_GPU3D_GCGPO_2_ADDR      (REGS_GPU3D_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCGPO_2           (*(volatile hw_gpu3d_gcgpo_2_t *) HW_GPU3D_GCGPO_2_ADDR)
#define HW_GPU3D_GCGPO_2_RD()      (HW_GPU3D_GCGPO_2.U)
#define HW_GPU3D_GCGPO_2_WR(v)     (HW_GPU3D_GCGPO_2.U = (v))
#define HW_GPU3D_GCGPO_2_SET(v)    (HW_GPU3D_GCGPO_2_WR(HW_GPU3D_GCGPO_2_RD() |  (v)))
#define HW_GPU3D_GCGPO_2_CLR(v)    (HW_GPU3D_GCGPO_2_WR(HW_GPU3D_GCGPO_2_RD() & ~(v)))
#define HW_GPU3D_GCGPO_2_TOG(v)    (HW_GPU3D_GCGPO_2_WR(HW_GPU3D_GCGPO_2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCGPO_2 bitfields
 */

/* --- Register HW_GPU3D_GCGPO_2, field COUNT
 *

 */

#define BP_GPU3D_GCGPO_2_COUNT      0
#define BM_GPU3D_GCGPO_2_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCGPO_2_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCGPO_2_COUNT)
#else
#define BF_GPU3D_GCGPO_2_COUNT(v)   (((v) << 0) & BM_GPU3D_GCGPO_2_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCGPO_2_COUNT(v)   BF_CS1(GPU3D_GCGPO_2, COUNT, v)
#endif

/*!
 * @brief HW_GPU3D_GCA_CRTL - gcAxiControl
 *
 * Speacial Handling on AXI Bus.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_FULL_BURST_MODE : 1; //!< 
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_gpu3d_gca_crtl_t;
#endif

/*
 * constants & macros for entire GPU3D_GCA_CRTL register
 */
#define HW_GPU3D_GCA_CRTL_ADDR      (REGS_GPU3D_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCA_CRTL           (*(volatile hw_gpu3d_gca_crtl_t *) HW_GPU3D_GCA_CRTL_ADDR)
#define HW_GPU3D_GCA_CRTL_RD()      (HW_GPU3D_GCA_CRTL.U)
#define HW_GPU3D_GCA_CRTL_WR(v)     (HW_GPU3D_GCA_CRTL.U = (v))
#define HW_GPU3D_GCA_CRTL_SET(v)    (HW_GPU3D_GCA_CRTL_WR(HW_GPU3D_GCA_CRTL_RD() |  (v)))
#define HW_GPU3D_GCA_CRTL_CLR(v)    (HW_GPU3D_GCA_CRTL_WR(HW_GPU3D_GCA_CRTL_RD() & ~(v)))
#define HW_GPU3D_GCA_CRTL_TOG(v)    (HW_GPU3D_GCA_CRTL_WR(HW_GPU3D_GCA_CRTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCA_CRTL bitfields
 */

/* --- Register HW_GPU3D_GCA_CRTL, field WR_FULL_BURST_MODE
 *

 */

#define BP_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE      0
#define BM_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE)
#else
#define BF_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE(v)   (((v) << 0) & BM_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE(v)   BF_CS1(GPU3D_GCA_CRTL, WR_FULL_BURST_MODE, v)
#endif

/*!
 * @brief HW_GPU3D_GCM_FEAT_1 - GCMinorFeatures1
 *
 * Shows which features are enabled in this chip. This register has no set reset value. It
 * varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSUV_SWIZZLE : 1; //!< Resolve UV swizzle.
        unsigned V2_COMPRESSION : 1; //!< V2 compression.
        unsigned VG_DOUBLE_BUFFER : 1; //!< Double buffering support for VG (second TS-->VG semaphore is present).
        unsigned BUG_FIXES1 : 1; //!< 
        unsigned BUG_FIXES2 : 1; //!< 
        unsigned TEXTURE_STRIDE : 1; //!< Texture has stride and memory addressing.
        unsigned RESERVED0 : 26; //!< Reserved
    } B;
} hw_gpu3d_gcm_feat_1_t;
#endif

/*
 * constants & macros for entire GPU3D_GCM_FEAT_1 register
 */
#define HW_GPU3D_GCM_FEAT_1_ADDR      (REGS_GPU3D_BASE + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCM_FEAT_1           (*(volatile hw_gpu3d_gcm_feat_1_t *) HW_GPU3D_GCM_FEAT_1_ADDR)
#define HW_GPU3D_GCM_FEAT_1_RD()      (HW_GPU3D_GCM_FEAT_1.U)
#define HW_GPU3D_GCM_FEAT_1_WR(v)     (HW_GPU3D_GCM_FEAT_1.U = (v))
#define HW_GPU3D_GCM_FEAT_1_SET(v)    (HW_GPU3D_GCM_FEAT_1_WR(HW_GPU3D_GCM_FEAT_1_RD() |  (v)))
#define HW_GPU3D_GCM_FEAT_1_CLR(v)    (HW_GPU3D_GCM_FEAT_1_WR(HW_GPU3D_GCM_FEAT_1_RD() & ~(v)))
#define HW_GPU3D_GCM_FEAT_1_TOG(v)    (HW_GPU3D_GCM_FEAT_1_WR(HW_GPU3D_GCM_FEAT_1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCM_FEAT_1 bitfields
 */

/* --- Register HW_GPU3D_GCM_FEAT_1, field RSUV_SWIZZLE
 *
 * Resolve UV swizzle.
 */

#define BP_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE      0
#define BM_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE)
#else
#define BF_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE(v)   (((v) << 0) & BM_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE(v)   BF_CS1(GPU3D_GCM_FEAT_1, RSUV_SWIZZLE, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_1, field V2_COMPRESSION
 *
 * V2 compression.
 */

#define BP_GPU3D_GCM_FEAT_1_V2_COMPRESSION      1
#define BM_GPU3D_GCM_FEAT_1_V2_COMPRESSION      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_1_V2_COMPRESSION(v)   ((((reg32_t) v) << 1) & BM_GPU3D_GCM_FEAT_1_V2_COMPRESSION)
#else
#define BF_GPU3D_GCM_FEAT_1_V2_COMPRESSION(v)   (((v) << 1) & BM_GPU3D_GCM_FEAT_1_V2_COMPRESSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_1_V2_COMPRESSION(v)   BF_CS1(GPU3D_GCM_FEAT_1, V2_COMPRESSION, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_1, field VG_DOUBLE_BUFFER
 *
 * Double buffering support for VG (second TS-->VG semaphore is present).
 */

#define BP_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER      2
#define BM_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER(v)   ((((reg32_t) v) << 2) & BM_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER)
#else
#define BF_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER(v)   (((v) << 2) & BM_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER(v)   BF_CS1(GPU3D_GCM_FEAT_1, VG_DOUBLE_BUFFER, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_1, field BUG_FIXES1
 *

 */

#define BP_GPU3D_GCM_FEAT_1_BUG_FIXES1      3
#define BM_GPU3D_GCM_FEAT_1_BUG_FIXES1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_1_BUG_FIXES1(v)   ((((reg32_t) v) << 3) & BM_GPU3D_GCM_FEAT_1_BUG_FIXES1)
#else
#define BF_GPU3D_GCM_FEAT_1_BUG_FIXES1(v)   (((v) << 3) & BM_GPU3D_GCM_FEAT_1_BUG_FIXES1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_1_BUG_FIXES1(v)   BF_CS1(GPU3D_GCM_FEAT_1, BUG_FIXES1, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_1, field BUG_FIXES2
 *

 */

#define BP_GPU3D_GCM_FEAT_1_BUG_FIXES2      4
#define BM_GPU3D_GCM_FEAT_1_BUG_FIXES2      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_1_BUG_FIXES2(v)   ((((reg32_t) v) << 4) & BM_GPU3D_GCM_FEAT_1_BUG_FIXES2)
#else
#define BF_GPU3D_GCM_FEAT_1_BUG_FIXES2(v)   (((v) << 4) & BM_GPU3D_GCM_FEAT_1_BUG_FIXES2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_1_BUG_FIXES2(v)   BF_CS1(GPU3D_GCM_FEAT_1, BUG_FIXES2, v)
#endif

/* --- Register HW_GPU3D_GCM_FEAT_1, field TEXTURE_STRIDE
 *
 * Texture has stride and memory addressing.
 */

#define BP_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE      5
#define BM_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE(v)   ((((reg32_t) v) << 5) & BM_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE)
#else
#define BF_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE(v)   (((v) << 5) & BM_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE(v)   BF_CS1(GPU3D_GCM_FEAT_1, TEXTURE_STRIDE, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_CYCLES - gcTotalCycles
 *
 * Total cycles. This register is a free-running counter. It can be reset by writing 0 to
 * it.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CYCLES : 32; //!< 
    } B;
} hw_gpu3d_gct_cycles_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_CYCLES register
 */
#define HW_GPU3D_GCT_CYCLES_ADDR      (REGS_GPU3D_BASE + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_CYCLES           (*(volatile hw_gpu3d_gct_cycles_t *) HW_GPU3D_GCT_CYCLES_ADDR)
#define HW_GPU3D_GCT_CYCLES_RD()      (HW_GPU3D_GCT_CYCLES.U)
#define HW_GPU3D_GCT_CYCLES_WR(v)     (HW_GPU3D_GCT_CYCLES.U = (v))
#define HW_GPU3D_GCT_CYCLES_SET(v)    (HW_GPU3D_GCT_CYCLES_WR(HW_GPU3D_GCT_CYCLES_RD() |  (v)))
#define HW_GPU3D_GCT_CYCLES_CLR(v)    (HW_GPU3D_GCT_CYCLES_WR(HW_GPU3D_GCT_CYCLES_RD() & ~(v)))
#define HW_GPU3D_GCT_CYCLES_TOG(v)    (HW_GPU3D_GCT_CYCLES_WR(HW_GPU3D_GCT_CYCLES_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_CYCLES bitfields
 */

/* --- Register HW_GPU3D_GCT_CYCLES, field CYCLES
 *

 */

#define BP_GPU3D_GCT_CYCLES_CYCLES      0
#define BM_GPU3D_GCT_CYCLES_CYCLES      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_CYCLES_CYCLES(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_CYCLES_CYCLES)
#else
#define BF_GPU3D_GCT_CYCLES_CYCLES(v)   (((v) << 0) & BM_GPU3D_GCT_CYCLES_CYCLES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_CYCLES_CYCLES(v)   BF_CS1(GPU3D_GCT_CYCLES, CYCLES, v)
#endif

/*!
 * @brief HW_GPU3D_GCT_IDLE_CYCLES - gcTotalIdleCycles
 *
 * Total cycles where the GPU is idle. It is reset when gcTotalCylces register is written to. It
 * looks at all the blocks except FE when determining if the IP is idle.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CYCLES : 32; //!< 
    } B;
} hw_gpu3d_gct_idle_cycles_t;
#endif

/*
 * constants & macros for entire GPU3D_GCT_IDLE_CYCLES register
 */
#define HW_GPU3D_GCT_IDLE_CYCLES_ADDR      (REGS_GPU3D_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_GPU3D_GCT_IDLE_CYCLES           (*(volatile hw_gpu3d_gct_idle_cycles_t *) HW_GPU3D_GCT_IDLE_CYCLES_ADDR)
#define HW_GPU3D_GCT_IDLE_CYCLES_RD()      (HW_GPU3D_GCT_IDLE_CYCLES.U)
#define HW_GPU3D_GCT_IDLE_CYCLES_WR(v)     (HW_GPU3D_GCT_IDLE_CYCLES.U = (v))
#define HW_GPU3D_GCT_IDLE_CYCLES_SET(v)    (HW_GPU3D_GCT_IDLE_CYCLES_WR(HW_GPU3D_GCT_IDLE_CYCLES_RD() |  (v)))
#define HW_GPU3D_GCT_IDLE_CYCLES_CLR(v)    (HW_GPU3D_GCT_IDLE_CYCLES_WR(HW_GPU3D_GCT_IDLE_CYCLES_RD() & ~(v)))
#define HW_GPU3D_GCT_IDLE_CYCLES_TOG(v)    (HW_GPU3D_GCT_IDLE_CYCLES_WR(HW_GPU3D_GCT_IDLE_CYCLES_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU3D_GCT_IDLE_CYCLES bitfields
 */

/* --- Register HW_GPU3D_GCT_IDLE_CYCLES, field CYCLES
 *

 */

#define BP_GPU3D_GCT_IDLE_CYCLES_CYCLES      0
#define BM_GPU3D_GCT_IDLE_CYCLES_CYCLES      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU3D_GCT_IDLE_CYCLES_CYCLES(v)   ((((reg32_t) v) << 0) & BM_GPU3D_GCT_IDLE_CYCLES_CYCLES)
#else
#define BF_GPU3D_GCT_IDLE_CYCLES_CYCLES(v)   (((v) << 0) & BM_GPU3D_GCT_IDLE_CYCLES_CYCLES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU3D_GCT_IDLE_CYCLES_CYCLES(v)   BF_CS1(GPU3D_GCT_IDLE_CYCLES, CYCLES, v)
#endif



/*!
 * @brief All GPU3D module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_gpu3d_aqh_clk_ctrl_t AQH_CLK_CTRL; //!< AQHiClockControl
    volatile hw_gpu3d_aqh_idle_t AQH_IDLE; //!< AQHIdle
    volatile hw_gpu3d_aqa_cfg_t AQA_CFG; //!< AQAxiConfig
    volatile hw_gpu3d_aqa_status_t AQA_STATUS; //!< AQAxiStatus
    volatile hw_gpu3d_aqi_ack_t AQI_ACK; //!< AQIntrAcknowledge
    volatile hw_gpu3d_aqi_enbl_t AQI_ENBL; //!< AQIntrEnbl
    volatile hw_gpu3d_aqident_t AQIDENT; //!< AQIdent
    volatile hw_gpu3d_gc_feat_t GC_FEAT; //!< GCFeatures
    volatile hw_gpu3d_gcc_id_t GCC_ID; //!< GCChipId
    volatile hw_gpu3d_gcc_rev_t GCC_REV; //!< GCChipRev
    volatile hw_gpu3d_gcc_date_t GCC_DATE; //!< GCChipDate
    volatile hw_gpu3d_gcc_time_t GCC_TIME; //!< GCChipTime
    volatile hw_gpu3d_gcc_cust_t GCC_CUST; //!< GCChipCustomer
    volatile hw_gpu3d_gcm_feat_0_t GCM_FEAT_0; //!< GCMinorFeatures0
    volatile hw_gpu3d_gcc_crtl_t GCC_CRTL; //!< GCCacheControl
    volatile hw_gpu3d_gcr_mem_ctrs_t GCR_MEM_CTRS; //!< GCResetMemCounters
    volatile hw_gpu3d_gct_reads_t GCT_READS; //!< gcTotalReads
    volatile hw_gpu3d_gct_writes_t GCT_WRITES; //!< gcTotalWrites
    volatile hw_gpu3d_gcc_specs_t GCC_SPECS; //!< gcChipSpecs
    volatile hw_gpu3d_gct_write_bursts_t GCT_WRITE_BURSTS; //!< gcTotalWriteBursts
    volatile hw_gpu3d_gct_write_reqs_t GCT_WRITE_REQS; //!< gcTotalWriteReqs
    volatile hw_gpu3d_gct_write_lasts_t GCT_WRITE_LASTS; //!< gcTotalWriteLasts
    volatile hw_gpu3d_gct_read_bursts_t GCT_READ_BURSTS; //!< gcTotalReadBursts
    reg32_t _reserved0;
    volatile hw_gpu3d_gct_read_reqs_t GCT_READ_REQS; //!< gcTotalReadReqs
    volatile hw_gpu3d_gct_read_lasts_t GCT_READ_LASTS; //!< gcTotalReadLasts
    volatile hw_gpu3d_gcgpo_0_t GCGPO_0; //!< gcGpOut0
    volatile hw_gpu3d_gcgpo_1_t GCGPO_1; //!< gcGpOut1
    volatile hw_gpu3d_gcgpo_2_t GCGPO_2; //!< gcGpOut2
    volatile hw_gpu3d_gca_crtl_t GCA_CRTL; //!< gcAxiControl
    volatile hw_gpu3d_gcm_feat_1_t GCM_FEAT_1; //!< GCMinorFeatures1
    volatile hw_gpu3d_gct_cycles_t GCT_CYCLES; //!< gcTotalCycles
    volatile hw_gpu3d_gct_idle_cycles_t GCT_IDLE_CYCLES; //!< gcTotalIdleCycles
} hw_gpu3d_t
#endif

//! @brief Macro to access all GPU3D registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_GPU3D(0)</code>.
#define HW_GPU3D     (*(volatile hw_gpu3d_t *) REGS_GPU3D_BASE)


#endif // _GPU3D_H
