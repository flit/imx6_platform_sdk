/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _GPU2D_H
#define _GPU2D_H

#include "regs.h"

#ifndef REGS_GPU2D_BASE
#define REGS_GPU2D_BASE (REGS_BASE + 0x00134000)
#endif


/*!
 * @brief HW_GPU2D_AQHICLOCKCONTROL - Clock Control Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned MULTI_PIPE_USE_SINGLE_AXI : 4; //!< Force all the transactions to go to one AXI.
        unsigned MULTI_PIPE_REG_SELECT : 4; //!< Determines which HI/MC to use while reading registers.
        unsigned ISOLATE_GPU : 1; //!< Isolate GPU bit
        unsigned IDLE_VG : 1; //!< VG pipe is idle.
        unsigned IDLE2_D : 1; //!< 2D pipe is idle.
        unsigned IDLE3_D : 1; //!< 3D pipe is idle.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned SOFT_RESET : 1; //!< Soft resets the IP.
        unsigned DISABLE_DEBUG_REGISTERS : 1; //!< Disable debug registers. If this bit is 1, debug registers are clock gated.
        unsigned DISABLE_RAM_CLOCK_GATING : 1; //!< Disables clock gating for rams.
        unsigned FSCALE_CMD_LOAD : 1; //!< 
        unsigned FSCALE_VAL : 7; //!< 
        unsigned CLK2D_DIS : 1; //!< Disable 2D clock.
        unsigned CLK3D_DIS : 1; //!< Disable 3D clock.
    } B;
} hw_gpu2d_aqhiclockcontrol_t;
#endif

/*
 * constants & macros for entire GPU2D_AQHICLOCKCONTROL register
 */
#define HW_GPU2D_AQHICLOCKCONTROL_ADDR      (REGS_GPU2D_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_AQHICLOCKCONTROL           (*(volatile hw_gpu2d_aqhiclockcontrol_t *) HW_GPU2D_AQHICLOCKCONTROL_ADDR)
#define HW_GPU2D_AQHICLOCKCONTROL_RD()      (HW_GPU2D_AQHICLOCKCONTROL.U)
#define HW_GPU2D_AQHICLOCKCONTROL_WR(v)     (HW_GPU2D_AQHICLOCKCONTROL.U = (v))
#define HW_GPU2D_AQHICLOCKCONTROL_SET(v)    (HW_GPU2D_AQHICLOCKCONTROL_WR(HW_GPU2D_AQHICLOCKCONTROL_RD() |  (v)))
#define HW_GPU2D_AQHICLOCKCONTROL_CLR(v)    (HW_GPU2D_AQHICLOCKCONTROL_WR(HW_GPU2D_AQHICLOCKCONTROL_RD() & ~(v)))
#define HW_GPU2D_AQHICLOCKCONTROL_TOG(v)    (HW_GPU2D_AQHICLOCKCONTROL_WR(HW_GPU2D_AQHICLOCKCONTROL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_AQHICLOCKCONTROL bitfields
 */

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field MULTI_PIPE_USE_SINGLE_AXI
 *
 * Force all the transactions to go to one AXI.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI      4
#define BM_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI(v)   ((((reg32_t) v) << 4) & BM_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI(v)   (((v) << 4) & BM_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, MULTI_PIPE_USE_SINGLE_AXI, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field MULTI_PIPE_REG_SELECT
 *
 * Determines which HI/MC to use while reading registers.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT      8
#define BM_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT(v)   ((((reg32_t) v) << 8) & BM_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT(v)   (((v) << 8) & BM_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, MULTI_PIPE_REG_SELECT, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field ISOLATE_GPU
 *
 * Isolate GPU bit
 */

#define BP_GPU2D_AQHICLOCKCONTROL_ISOLATE_GPU      12
#define BM_GPU2D_AQHICLOCKCONTROL_ISOLATE_GPU      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_ISOLATE_GPU(v)   ((((reg32_t) v) << 12) & BM_GPU2D_AQHICLOCKCONTROL_ISOLATE_GPU)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_ISOLATE_GPU(v)   (((v) << 12) & BM_GPU2D_AQHICLOCKCONTROL_ISOLATE_GPU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_ISOLATE_GPU(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, ISOLATE_GPU, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field IDLE_VG
 *
 * VG pipe is idle.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_IDLE_VG      13
#define BM_GPU2D_AQHICLOCKCONTROL_IDLE_VG      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_IDLE_VG(v)   ((((reg32_t) v) << 13) & BM_GPU2D_AQHICLOCKCONTROL_IDLE_VG)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_IDLE_VG(v)   (((v) << 13) & BM_GPU2D_AQHICLOCKCONTROL_IDLE_VG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_IDLE_VG(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, IDLE_VG, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field IDLE2_D
 *
 * 2D pipe is idle.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_IDLE2_D      14
#define BM_GPU2D_AQHICLOCKCONTROL_IDLE2_D      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_IDLE2_D(v)   ((((reg32_t) v) << 14) & BM_GPU2D_AQHICLOCKCONTROL_IDLE2_D)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_IDLE2_D(v)   (((v) << 14) & BM_GPU2D_AQHICLOCKCONTROL_IDLE2_D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_IDLE2_D(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, IDLE2_D, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field IDLE3_D
 *
 * 3D pipe is idle.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_IDLE3_D      15
#define BM_GPU2D_AQHICLOCKCONTROL_IDLE3_D      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_IDLE3_D(v)   ((((reg32_t) v) << 15) & BM_GPU2D_AQHICLOCKCONTROL_IDLE3_D)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_IDLE3_D(v)   (((v) << 15) & BM_GPU2D_AQHICLOCKCONTROL_IDLE3_D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_IDLE3_D(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, IDLE3_D, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field SOFT_RESET
 *
 * Soft resets the IP.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_SOFT_RESET      19
#define BM_GPU2D_AQHICLOCKCONTROL_SOFT_RESET      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_SOFT_RESET(v)   ((((reg32_t) v) << 19) & BM_GPU2D_AQHICLOCKCONTROL_SOFT_RESET)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_SOFT_RESET(v)   (((v) << 19) & BM_GPU2D_AQHICLOCKCONTROL_SOFT_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_SOFT_RESET(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, SOFT_RESET, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field DISABLE_DEBUG_REGISTERS
 *
 * Disable debug registers. If this bit is 1, debug registers are clock
 * gated.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS      20
#define BM_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS(v)   ((((reg32_t) v) << 20) & BM_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS(v)   (((v) << 20) & BM_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, DISABLE_DEBUG_REGISTERS, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field DISABLE_RAM_CLOCK_GATING
 *
 * Disables clock gating for rams.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING      21
#define BM_GPU2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING(v)   ((((reg32_t) v) << 21) & BM_GPU2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING(v)   (((v) << 21) & BM_GPU2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, DISABLE_RAM_CLOCK_GATING, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field FSCALE_CMD_LOAD
 *

 */

#define BP_GPU2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD      22
#define BM_GPU2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD(v)   ((((reg32_t) v) << 22) & BM_GPU2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD(v)   (((v) << 22) & BM_GPU2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, FSCALE_CMD_LOAD, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field FSCALE_VAL
 *

 */

#define BP_GPU2D_AQHICLOCKCONTROL_FSCALE_VAL      23
#define BM_GPU2D_AQHICLOCKCONTROL_FSCALE_VAL      0x3f800000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_FSCALE_VAL(v)   ((((reg32_t) v) << 23) & BM_GPU2D_AQHICLOCKCONTROL_FSCALE_VAL)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_FSCALE_VAL(v)   (((v) << 23) & BM_GPU2D_AQHICLOCKCONTROL_FSCALE_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_FSCALE_VAL(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, FSCALE_VAL, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field CLK2D_DIS
 *
 * Disable 2D clock.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_CLK2D_DIS      30
#define BM_GPU2D_AQHICLOCKCONTROL_CLK2D_DIS      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_CLK2D_DIS(v)   ((((reg32_t) v) << 30) & BM_GPU2D_AQHICLOCKCONTROL_CLK2D_DIS)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_CLK2D_DIS(v)   (((v) << 30) & BM_GPU2D_AQHICLOCKCONTROL_CLK2D_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_CLK2D_DIS(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, CLK2D_DIS, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field CLK3D_DIS
 *
 * Disable 3D clock.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_CLK3D_DIS      31
#define BM_GPU2D_AQHICLOCKCONTROL_CLK3D_DIS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_CLK3D_DIS(v)   ((((reg32_t) v) << 31) & BM_GPU2D_AQHICLOCKCONTROL_CLK3D_DIS)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_CLK3D_DIS(v)   (((v) << 31) & BM_GPU2D_AQHICLOCKCONTROL_CLK3D_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHICLOCKCONTROL_CLK3D_DIS(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, CLK3D_DIS, v)
#endif

/*!
 * @brief HW_GPU2D_AQHIIDLE - Idle Status Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AXI_LP : 1; //!< AXI is in low power mode.
        unsigned RESERVED0 : 19; //!< Reserved.
        unsigned IDLE_TS : 1; //!< TS is idle.
        unsigned IDLE_FP : 1; //!< FP is idle.
        unsigned IDLE_IM : 1; //!< IM is idle.
        unsigned IDLE_VG : 1; //!< VG is idle.
        unsigned IDLE_TX : 1; //!< TX is idle.
        unsigned IDLE_RA : 1; //!< RA is idle.
        unsigned IDLE_SE : 1; //!< SE is idle.
        unsigned IDLE_PA : 1; //!< PA is idle.
        unsigned IDLE_SH : 1; //!< SH is idle.
        unsigned IDLE_PE : 1; //!< PE is idle.
        unsigned IDLE_DE : 1; //!< DE is idle.
        unsigned IDLE_FE : 1; //!< FE is idle.
    } B;
} hw_gpu2d_aqhiidle_t;
#endif

/*
 * constants & macros for entire GPU2D_AQHIIDLE register
 */
#define HW_GPU2D_AQHIIDLE_ADDR      (REGS_GPU2D_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_AQHIIDLE           (*(volatile hw_gpu2d_aqhiidle_t *) HW_GPU2D_AQHIIDLE_ADDR)
#define HW_GPU2D_AQHIIDLE_RD()      (HW_GPU2D_AQHIIDLE.U)
#define HW_GPU2D_AQHIIDLE_WR(v)     (HW_GPU2D_AQHIIDLE.U = (v))
#define HW_GPU2D_AQHIIDLE_SET(v)    (HW_GPU2D_AQHIIDLE_WR(HW_GPU2D_AQHIIDLE_RD() |  (v)))
#define HW_GPU2D_AQHIIDLE_CLR(v)    (HW_GPU2D_AQHIIDLE_WR(HW_GPU2D_AQHIIDLE_RD() & ~(v)))
#define HW_GPU2D_AQHIIDLE_TOG(v)    (HW_GPU2D_AQHIIDLE_WR(HW_GPU2D_AQHIIDLE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_AQHIIDLE bitfields
 */

/* --- Register HW_GPU2D_AQHIIDLE, field AXI_LP
 *
 * AXI is in low power mode.
 */

#define BP_GPU2D_AQHIIDLE_AXI_LP      0
#define BM_GPU2D_AQHIIDLE_AXI_LP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_AXI_LP(v)   ((((reg32_t) v) << 0) & BM_GPU2D_AQHIIDLE_AXI_LP)
#else
#define BF_GPU2D_AQHIIDLE_AXI_LP(v)   (((v) << 0) & BM_GPU2D_AQHIIDLE_AXI_LP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_AXI_LP(v)   BF_CS1(GPU2D_AQHIIDLE, AXI_LP, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_TS
 *
 * TS is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_TS      20
#define BM_GPU2D_AQHIIDLE_IDLE_TS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_TS(v)   ((((reg32_t) v) << 20) & BM_GPU2D_AQHIIDLE_IDLE_TS)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_TS(v)   (((v) << 20) & BM_GPU2D_AQHIIDLE_IDLE_TS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_TS(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_TS, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_FP
 *
 * FP is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_FP      21
#define BM_GPU2D_AQHIIDLE_IDLE_FP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_FP(v)   ((((reg32_t) v) << 21) & BM_GPU2D_AQHIIDLE_IDLE_FP)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_FP(v)   (((v) << 21) & BM_GPU2D_AQHIIDLE_IDLE_FP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_FP(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_FP, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_IM
 *
 * IM is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_IM      22
#define BM_GPU2D_AQHIIDLE_IDLE_IM      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_IM(v)   ((((reg32_t) v) << 22) & BM_GPU2D_AQHIIDLE_IDLE_IM)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_IM(v)   (((v) << 22) & BM_GPU2D_AQHIIDLE_IDLE_IM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_IM(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_IM, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_VG
 *
 * VG is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_VG      23
#define BM_GPU2D_AQHIIDLE_IDLE_VG      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_VG(v)   ((((reg32_t) v) << 23) & BM_GPU2D_AQHIIDLE_IDLE_VG)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_VG(v)   (((v) << 23) & BM_GPU2D_AQHIIDLE_IDLE_VG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_VG(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_VG, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_TX
 *
 * TX is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_TX      24
#define BM_GPU2D_AQHIIDLE_IDLE_TX      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_TX(v)   ((((reg32_t) v) << 24) & BM_GPU2D_AQHIIDLE_IDLE_TX)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_TX(v)   (((v) << 24) & BM_GPU2D_AQHIIDLE_IDLE_TX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_TX(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_TX, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_RA
 *
 * RA is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_RA      25
#define BM_GPU2D_AQHIIDLE_IDLE_RA      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_RA(v)   ((((reg32_t) v) << 25) & BM_GPU2D_AQHIIDLE_IDLE_RA)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_RA(v)   (((v) << 25) & BM_GPU2D_AQHIIDLE_IDLE_RA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_RA(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_RA, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_SE
 *
 * SE is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_SE      26
#define BM_GPU2D_AQHIIDLE_IDLE_SE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_SE(v)   ((((reg32_t) v) << 26) & BM_GPU2D_AQHIIDLE_IDLE_SE)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_SE(v)   (((v) << 26) & BM_GPU2D_AQHIIDLE_IDLE_SE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_SE(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_SE, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_PA
 *
 * PA is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_PA      27
#define BM_GPU2D_AQHIIDLE_IDLE_PA      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_PA(v)   ((((reg32_t) v) << 27) & BM_GPU2D_AQHIIDLE_IDLE_PA)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_PA(v)   (((v) << 27) & BM_GPU2D_AQHIIDLE_IDLE_PA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_PA(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_PA, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_SH
 *
 * SH is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_SH      28
#define BM_GPU2D_AQHIIDLE_IDLE_SH      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_SH(v)   ((((reg32_t) v) << 28) & BM_GPU2D_AQHIIDLE_IDLE_SH)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_SH(v)   (((v) << 28) & BM_GPU2D_AQHIIDLE_IDLE_SH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_SH(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_SH, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_PE
 *
 * PE is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_PE      29
#define BM_GPU2D_AQHIIDLE_IDLE_PE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_PE(v)   ((((reg32_t) v) << 29) & BM_GPU2D_AQHIIDLE_IDLE_PE)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_PE(v)   (((v) << 29) & BM_GPU2D_AQHIIDLE_IDLE_PE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_PE(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_PE, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_DE
 *
 * DE is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_DE      30
#define BM_GPU2D_AQHIIDLE_IDLE_DE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_DE(v)   ((((reg32_t) v) << 30) & BM_GPU2D_AQHIIDLE_IDLE_DE)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_DE(v)   (((v) << 30) & BM_GPU2D_AQHIIDLE_IDLE_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_DE(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_DE, v)
#endif

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_FE
 *
 * FE is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_FE      31
#define BM_GPU2D_AQHIIDLE_IDLE_FE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHIIDLE_IDLE_FE(v)   ((((reg32_t) v) << 31) & BM_GPU2D_AQHIIDLE_IDLE_FE)
#else
#define BF_GPU2D_AQHIIDLE_IDLE_FE(v)   (((v) << 31) & BM_GPU2D_AQHIIDLE_IDLE_FE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQHIIDLE_IDLE_FE(v)   BF_CS1(GPU2D_AQHIIDLE, IDLE_FE, v)
#endif

/*!
 * @brief HW_GPU2D_AQAXICONFIG - AXI Configuration Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned ARCACHE : 4; //!< 
        unsigned AWCACHE : 4; //!< 
        unsigned ARID : 4; //!< 
        unsigned AWID : 4; //!< 
    } B;
} hw_gpu2d_aqaxiconfig_t;
#endif

/*
 * constants & macros for entire GPU2D_AQAXICONFIG register
 */
#define HW_GPU2D_AQAXICONFIG_ADDR      (REGS_GPU2D_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_AQAXICONFIG           (*(volatile hw_gpu2d_aqaxiconfig_t *) HW_GPU2D_AQAXICONFIG_ADDR)
#define HW_GPU2D_AQAXICONFIG_RD()      (HW_GPU2D_AQAXICONFIG.U)
#define HW_GPU2D_AQAXICONFIG_WR(v)     (HW_GPU2D_AQAXICONFIG.U = (v))
#define HW_GPU2D_AQAXICONFIG_SET(v)    (HW_GPU2D_AQAXICONFIG_WR(HW_GPU2D_AQAXICONFIG_RD() |  (v)))
#define HW_GPU2D_AQAXICONFIG_CLR(v)    (HW_GPU2D_AQAXICONFIG_WR(HW_GPU2D_AQAXICONFIG_RD() & ~(v)))
#define HW_GPU2D_AQAXICONFIG_TOG(v)    (HW_GPU2D_AQAXICONFIG_WR(HW_GPU2D_AQAXICONFIG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_AQAXICONFIG bitfields
 */

/* --- Register HW_GPU2D_AQAXICONFIG, field ARCACHE
 *

 */

#define BP_GPU2D_AQAXICONFIG_ARCACHE      16
#define BM_GPU2D_AQAXICONFIG_ARCACHE      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQAXICONFIG_ARCACHE(v)   ((((reg32_t) v) << 16) & BM_GPU2D_AQAXICONFIG_ARCACHE)
#else
#define BF_GPU2D_AQAXICONFIG_ARCACHE(v)   (((v) << 16) & BM_GPU2D_AQAXICONFIG_ARCACHE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQAXICONFIG_ARCACHE(v)   BF_CS1(GPU2D_AQAXICONFIG, ARCACHE, v)
#endif

/* --- Register HW_GPU2D_AQAXICONFIG, field AWCACHE
 *

 */

#define BP_GPU2D_AQAXICONFIG_AWCACHE      20
#define BM_GPU2D_AQAXICONFIG_AWCACHE      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQAXICONFIG_AWCACHE(v)   ((((reg32_t) v) << 20) & BM_GPU2D_AQAXICONFIG_AWCACHE)
#else
#define BF_GPU2D_AQAXICONFIG_AWCACHE(v)   (((v) << 20) & BM_GPU2D_AQAXICONFIG_AWCACHE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQAXICONFIG_AWCACHE(v)   BF_CS1(GPU2D_AQAXICONFIG, AWCACHE, v)
#endif

/* --- Register HW_GPU2D_AQAXICONFIG, field ARID
 *

 */

#define BP_GPU2D_AQAXICONFIG_ARID      24
#define BM_GPU2D_AQAXICONFIG_ARID      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQAXICONFIG_ARID(v)   ((((reg32_t) v) << 24) & BM_GPU2D_AQAXICONFIG_ARID)
#else
#define BF_GPU2D_AQAXICONFIG_ARID(v)   (((v) << 24) & BM_GPU2D_AQAXICONFIG_ARID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQAXICONFIG_ARID(v)   BF_CS1(GPU2D_AQAXICONFIG, ARID, v)
#endif

/* --- Register HW_GPU2D_AQAXICONFIG, field AWID
 *

 */

#define BP_GPU2D_AQAXICONFIG_AWID      28
#define BM_GPU2D_AQAXICONFIG_AWID      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQAXICONFIG_AWID(v)   ((((reg32_t) v) << 28) & BM_GPU2D_AQAXICONFIG_AWID)
#else
#define BF_GPU2D_AQAXICONFIG_AWID(v)   (((v) << 28) & BM_GPU2D_AQAXICONFIG_AWID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQAXICONFIG_AWID(v)   BF_CS1(GPU2D_AQAXICONFIG, AWID, v)
#endif

/*!
 * @brief HW_GPU2D_AQAXISTATUS - AXI Status Register
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
} hw_gpu2d_aqaxistatus_t;
#endif

/*
 * constants & macros for entire GPU2D_AQAXISTATUS register
 */
#define HW_GPU2D_AQAXISTATUS_ADDR      (REGS_GPU2D_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_AQAXISTATUS           (*(volatile hw_gpu2d_aqaxistatus_t *) HW_GPU2D_AQAXISTATUS_ADDR)
#define HW_GPU2D_AQAXISTATUS_RD()      (HW_GPU2D_AQAXISTATUS.U)
#define HW_GPU2D_AQAXISTATUS_WR(v)     (HW_GPU2D_AQAXISTATUS.U = (v))
#define HW_GPU2D_AQAXISTATUS_SET(v)    (HW_GPU2D_AQAXISTATUS_WR(HW_GPU2D_AQAXISTATUS_RD() |  (v)))
#define HW_GPU2D_AQAXISTATUS_CLR(v)    (HW_GPU2D_AQAXISTATUS_WR(HW_GPU2D_AQAXISTATUS_RD() & ~(v)))
#define HW_GPU2D_AQAXISTATUS_TOG(v)    (HW_GPU2D_AQAXISTATUS_WR(HW_GPU2D_AQAXISTATUS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_AQAXISTATUS bitfields
 */

/* --- Register HW_GPU2D_AQAXISTATUS, field WR_ERR_ID
 *

 */

#define BP_GPU2D_AQAXISTATUS_WR_ERR_ID      0
#define BM_GPU2D_AQAXISTATUS_WR_ERR_ID      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQAXISTATUS_WR_ERR_ID(v)   ((((reg32_t) v) << 0) & BM_GPU2D_AQAXISTATUS_WR_ERR_ID)
#else
#define BF_GPU2D_AQAXISTATUS_WR_ERR_ID(v)   (((v) << 0) & BM_GPU2D_AQAXISTATUS_WR_ERR_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQAXISTATUS_WR_ERR_ID(v)   BF_CS1(GPU2D_AQAXISTATUS, WR_ERR_ID, v)
#endif

/* --- Register HW_GPU2D_AQAXISTATUS, field RD_ERR_ID
 *

 */

#define BP_GPU2D_AQAXISTATUS_RD_ERR_ID      4
#define BM_GPU2D_AQAXISTATUS_RD_ERR_ID      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQAXISTATUS_RD_ERR_ID(v)   ((((reg32_t) v) << 4) & BM_GPU2D_AQAXISTATUS_RD_ERR_ID)
#else
#define BF_GPU2D_AQAXISTATUS_RD_ERR_ID(v)   (((v) << 4) & BM_GPU2D_AQAXISTATUS_RD_ERR_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQAXISTATUS_RD_ERR_ID(v)   BF_CS1(GPU2D_AQAXISTATUS, RD_ERR_ID, v)
#endif

/* --- Register HW_GPU2D_AQAXISTATUS, field DET_WR_ERR
 *

 */

#define BP_GPU2D_AQAXISTATUS_DET_WR_ERR      8
#define BM_GPU2D_AQAXISTATUS_DET_WR_ERR      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQAXISTATUS_DET_WR_ERR(v)   ((((reg32_t) v) << 8) & BM_GPU2D_AQAXISTATUS_DET_WR_ERR)
#else
#define BF_GPU2D_AQAXISTATUS_DET_WR_ERR(v)   (((v) << 8) & BM_GPU2D_AQAXISTATUS_DET_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQAXISTATUS_DET_WR_ERR(v)   BF_CS1(GPU2D_AQAXISTATUS, DET_WR_ERR, v)
#endif

/* --- Register HW_GPU2D_AQAXISTATUS, field DET_RD_ERR
 *

 */

#define BP_GPU2D_AQAXISTATUS_DET_RD_ERR      9
#define BM_GPU2D_AQAXISTATUS_DET_RD_ERR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQAXISTATUS_DET_RD_ERR(v)   ((((reg32_t) v) << 9) & BM_GPU2D_AQAXISTATUS_DET_RD_ERR)
#else
#define BF_GPU2D_AQAXISTATUS_DET_RD_ERR(v)   (((v) << 9) & BM_GPU2D_AQAXISTATUS_DET_RD_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQAXISTATUS_DET_RD_ERR(v)   BF_CS1(GPU2D_AQAXISTATUS, DET_RD_ERR, v)
#endif

/*!
 * @brief HW_GPU2D_AQINTRACKNOWLEDGE - Interrupt Acknowledge Register
 *
 * Interrupt acknowledge register. Each bit represents a corresponding event
 * being triggered. Reading frmo this register clears the outstanding
 * interrupt.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INTR_VEC : 32; //!< 
    } B;
} hw_gpu2d_aqintracknowledge_t;
#endif

/*
 * constants & macros for entire GPU2D_AQINTRACKNOWLEDGE register
 */
#define HW_GPU2D_AQINTRACKNOWLEDGE_ADDR      (REGS_GPU2D_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_AQINTRACKNOWLEDGE           (*(volatile hw_gpu2d_aqintracknowledge_t *) HW_GPU2D_AQINTRACKNOWLEDGE_ADDR)
#define HW_GPU2D_AQINTRACKNOWLEDGE_RD()      (HW_GPU2D_AQINTRACKNOWLEDGE.U)
#define HW_GPU2D_AQINTRACKNOWLEDGE_WR(v)     (HW_GPU2D_AQINTRACKNOWLEDGE.U = (v))
#define HW_GPU2D_AQINTRACKNOWLEDGE_SET(v)    (HW_GPU2D_AQINTRACKNOWLEDGE_WR(HW_GPU2D_AQINTRACKNOWLEDGE_RD() |  (v)))
#define HW_GPU2D_AQINTRACKNOWLEDGE_CLR(v)    (HW_GPU2D_AQINTRACKNOWLEDGE_WR(HW_GPU2D_AQINTRACKNOWLEDGE_RD() & ~(v)))
#define HW_GPU2D_AQINTRACKNOWLEDGE_TOG(v)    (HW_GPU2D_AQINTRACKNOWLEDGE_WR(HW_GPU2D_AQINTRACKNOWLEDGE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_AQINTRACKNOWLEDGE bitfields
 */

/* --- Register HW_GPU2D_AQINTRACKNOWLEDGE, field INTR_VEC
 *

 */

#define BP_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC      0
#define BM_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC(v)   ((((reg32_t) v) << 0) & BM_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC)
#else
#define BF_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC(v)   (((v) << 0) & BM_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC(v)   BF_CS1(GPU2D_AQINTRACKNOWLEDGE, INTR_VEC, v)
#endif

/*!
 * @brief HW_GPU2D_AQINTRENBL - Interrupt Enable Register
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
} hw_gpu2d_aqintrenbl_t;
#endif

/*
 * constants & macros for entire GPU2D_AQINTRENBL register
 */
#define HW_GPU2D_AQINTRENBL_ADDR      (REGS_GPU2D_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_AQINTRENBL           (*(volatile hw_gpu2d_aqintrenbl_t *) HW_GPU2D_AQINTRENBL_ADDR)
#define HW_GPU2D_AQINTRENBL_RD()      (HW_GPU2D_AQINTRENBL.U)
#define HW_GPU2D_AQINTRENBL_WR(v)     (HW_GPU2D_AQINTRENBL.U = (v))
#define HW_GPU2D_AQINTRENBL_SET(v)    (HW_GPU2D_AQINTRENBL_WR(HW_GPU2D_AQINTRENBL_RD() |  (v)))
#define HW_GPU2D_AQINTRENBL_CLR(v)    (HW_GPU2D_AQINTRENBL_WR(HW_GPU2D_AQINTRENBL_RD() & ~(v)))
#define HW_GPU2D_AQINTRENBL_TOG(v)    (HW_GPU2D_AQINTRENBL_WR(HW_GPU2D_AQINTRENBL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_AQINTRENBL bitfields
 */

/* --- Register HW_GPU2D_AQINTRENBL, field INTR_ENBL_VEC
 *

 */

#define BP_GPU2D_AQINTRENBL_INTR_ENBL_VEC      0
#define BM_GPU2D_AQINTRENBL_INTR_ENBL_VEC      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQINTRENBL_INTR_ENBL_VEC(v)   ((((reg32_t) v) << 0) & BM_GPU2D_AQINTRENBL_INTR_ENBL_VEC)
#else
#define BF_GPU2D_AQINTRENBL_INTR_ENBL_VEC(v)   (((v) << 0) & BM_GPU2D_AQINTRENBL_INTR_ENBL_VEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQINTRENBL_INTR_ENBL_VEC(v)   BF_CS1(GPU2D_AQINTRENBL, INTR_ENBL_VEC, v)
#endif

/*!
 * @brief HW_GPU2D_AQIDENT - Identification Register
 *
 * Identification register. This register has no set reset value. It varies
 * with the implementation.
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
} hw_gpu2d_aqident_t;
#endif

/*
 * constants & macros for entire GPU2D_AQIDENT register
 */
#define HW_GPU2D_AQIDENT_ADDR      (REGS_GPU2D_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_AQIDENT           (*(volatile hw_gpu2d_aqident_t *) HW_GPU2D_AQIDENT_ADDR)
#define HW_GPU2D_AQIDENT_RD()      (HW_GPU2D_AQIDENT.U)
#define HW_GPU2D_AQIDENT_WR(v)     (HW_GPU2D_AQIDENT.U = (v))
#define HW_GPU2D_AQIDENT_SET(v)    (HW_GPU2D_AQIDENT_WR(HW_GPU2D_AQIDENT_RD() |  (v)))
#define HW_GPU2D_AQIDENT_CLR(v)    (HW_GPU2D_AQIDENT_WR(HW_GPU2D_AQIDENT_RD() & ~(v)))
#define HW_GPU2D_AQIDENT_TOG(v)    (HW_GPU2D_AQIDENT_WR(HW_GPU2D_AQIDENT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_AQIDENT bitfields
 */

/* --- Register HW_GPU2D_AQIDENT, field CUSTOMER
 *
 * Customer value.
 */

#define BP_GPU2D_AQIDENT_CUSTOMER      0
#define BM_GPU2D_AQIDENT_CUSTOMER      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQIDENT_CUSTOMER(v)   ((((reg32_t) v) << 0) & BM_GPU2D_AQIDENT_CUSTOMER)
#else
#define BF_GPU2D_AQIDENT_CUSTOMER(v)   (((v) << 0) & BM_GPU2D_AQIDENT_CUSTOMER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQIDENT_CUSTOMER(v)   BF_CS1(GPU2D_AQIDENT, CUSTOMER, v)
#endif

/* --- Register HW_GPU2D_AQIDENT, field TECHNOLOGY
 *
 * Technology value.
 */

#define BP_GPU2D_AQIDENT_TECHNOLOGY      8
#define BM_GPU2D_AQIDENT_TECHNOLOGY      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQIDENT_TECHNOLOGY(v)   ((((reg32_t) v) << 8) & BM_GPU2D_AQIDENT_TECHNOLOGY)
#else
#define BF_GPU2D_AQIDENT_TECHNOLOGY(v)   (((v) << 8) & BM_GPU2D_AQIDENT_TECHNOLOGY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQIDENT_TECHNOLOGY(v)   BF_CS1(GPU2D_AQIDENT, TECHNOLOGY, v)
#endif

/* --- Register HW_GPU2D_AQIDENT, field REVISION
 *
 * Revision value.
 */

#define BP_GPU2D_AQIDENT_REVISION      12
#define BM_GPU2D_AQIDENT_REVISION      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQIDENT_REVISION(v)   ((((reg32_t) v) << 12) & BM_GPU2D_AQIDENT_REVISION)
#else
#define BF_GPU2D_AQIDENT_REVISION(v)   (((v) << 12) & BM_GPU2D_AQIDENT_REVISION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQIDENT_REVISION(v)   BF_CS1(GPU2D_AQIDENT, REVISION, v)
#endif

/* --- Register HW_GPU2D_AQIDENT, field PRODUCT
 *
 * Product value.
 */

#define BP_GPU2D_AQIDENT_PRODUCT      16
#define BM_GPU2D_AQIDENT_PRODUCT      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQIDENT_PRODUCT(v)   ((((reg32_t) v) << 16) & BM_GPU2D_AQIDENT_PRODUCT)
#else
#define BF_GPU2D_AQIDENT_PRODUCT(v)   (((v) << 16) & BM_GPU2D_AQIDENT_PRODUCT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQIDENT_PRODUCT(v)   BF_CS1(GPU2D_AQIDENT, PRODUCT, v)
#endif

/* --- Register HW_GPU2D_AQIDENT, field FAMILY
 *
 * Family value.
 */

#define BP_GPU2D_AQIDENT_FAMILY      24
#define BM_GPU2D_AQIDENT_FAMILY      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQIDENT_FAMILY(v)   ((((reg32_t) v) << 24) & BM_GPU2D_AQIDENT_FAMILY)
#else
#define BF_GPU2D_AQIDENT_FAMILY(v)   (((v) << 24) & BM_GPU2D_AQIDENT_FAMILY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AQIDENT_FAMILY(v)   BF_CS1(GPU2D_AQIDENT, FAMILY, v)
#endif

/*!
 * @brief HW_GPU2D_FEATURES - Features Register
 *
 * Shows which features are enabled in this chip. This register has no set
 * reset value. It varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FE20_BIT_INDEX : 1; //!< Supports 20 bit index.
        unsigned RS_YUV_TARGET : 1; //!< Supports resolving into YUV target.
        unsigned BYTE_WRITE_3D : 1; //!< 3D PE has byte write capability.
        unsigned FE20 : 1; //!< FE 2.0 is present.
        unsigned VGTS : 1; //!< VG tessellator is present.
        unsigned PIPE_VG : 1; //!< VG pipe is present.
        unsigned MEM32_BIT_SUPPORT : 1; //!< 32 bit memory address support.
        unsigned YUY2_RENDER_TARGET : 1; //!< YUY2 support in PE and YUY2 to RGB conversion in resolve.
        unsigned HALF_TX_CACHE : 1; //!< TX cache is half.
        unsigned HALF_PE_CACHE : 1; //!< PE cache is half.
        unsigned YUY2_AVERAGING : 1; //!< YUY2 averaging support in resolve.
        unsigned NO_SCALER : 1; //!< IP does not have 2D scaler.
        unsigned BYTE_WRITE_2D : 1; //!< Supports byte write in 2D.
        unsigned BUFFER_INTERLEAVING : 1; //!< IP supports interleaving depth and color buffers.
        unsigned NO422_TEXTURE : 1; //!< IP does not have 422 texture input format.
        unsigned NO_EZ : 1; //!< IP does not have early-Z.
        unsigned MIN_AREA : 1; //!< IP is configured to have minimum area.
        unsigned MODULE_CG : 1; //!< Second level clock gating is available.
        unsigned YUV420_TILER : 1; //!< YUV 4:2:0 tiler is available.
        unsigned HIGH_DYNAMIC_RANGE : 1; //!< Shows if the IP has HDR support.
        unsigned FAST_SCALER : 1; //!< Shows if the IP has HD scaler.
        unsigned ETC1_TEXTURE_COMPRESSION : 1; //!< ETC1 texture compression.
        unsigned PIPE_2D : 1; //!< Shows if there is 2D engine.
        unsigned DC : 1; //!< Shows if there is a display controller in the IP.
        unsigned MSAA : 1; //!< MSAA support.
        unsigned YUV420_FILTER : 1; //!< YUV 4:2:0 support in filter blit.
        unsigned ZCOMPRESSION : 1; //!< Depth and color compression.
        unsigned DEBUG_MODE : 1; //!< Debug registers.
        unsigned DXT_TEXTURE_COMPRESSION : 1; //!< DXT texture compression.
        unsigned PIPE_3D : 1; //!< 3D pipe.
        unsigned SPECIAL_ANTI_ALIASING : 1; //!< Full-screen anti-aliasing.
        unsigned FAST_CLEAR : 1; //!< Fast clear.
    } B;
} hw_gpu2d_features_t;
#endif

/*
 * constants & macros for entire GPU2D_FEATURES register
 */
#define HW_GPU2D_FEATURES_ADDR      (REGS_GPU2D_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_FEATURES           (*(volatile hw_gpu2d_features_t *) HW_GPU2D_FEATURES_ADDR)
#define HW_GPU2D_FEATURES_RD()      (HW_GPU2D_FEATURES.U)
#define HW_GPU2D_FEATURES_WR(v)     (HW_GPU2D_FEATURES.U = (v))
#define HW_GPU2D_FEATURES_SET(v)    (HW_GPU2D_FEATURES_WR(HW_GPU2D_FEATURES_RD() |  (v)))
#define HW_GPU2D_FEATURES_CLR(v)    (HW_GPU2D_FEATURES_WR(HW_GPU2D_FEATURES_RD() & ~(v)))
#define HW_GPU2D_FEATURES_TOG(v)    (HW_GPU2D_FEATURES_WR(HW_GPU2D_FEATURES_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_FEATURES bitfields
 */

/* --- Register HW_GPU2D_FEATURES, field FE20_BIT_INDEX
 *
 * Supports 20 bit index.
 */

#define BP_GPU2D_FEATURES_FE20_BIT_INDEX      0
#define BM_GPU2D_FEATURES_FE20_BIT_INDEX      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_FE20_BIT_INDEX(v)   ((((reg32_t) v) << 0) & BM_GPU2D_FEATURES_FE20_BIT_INDEX)
#else
#define BF_GPU2D_FEATURES_FE20_BIT_INDEX(v)   (((v) << 0) & BM_GPU2D_FEATURES_FE20_BIT_INDEX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_FE20_BIT_INDEX(v)   BF_CS1(GPU2D_FEATURES, FE20_BIT_INDEX, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field RS_YUV_TARGET
 *
 * Supports resolving into YUV target.
 */

#define BP_GPU2D_FEATURES_RS_YUV_TARGET      1
#define BM_GPU2D_FEATURES_RS_YUV_TARGET      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_RS_YUV_TARGET(v)   ((((reg32_t) v) << 1) & BM_GPU2D_FEATURES_RS_YUV_TARGET)
#else
#define BF_GPU2D_FEATURES_RS_YUV_TARGET(v)   (((v) << 1) & BM_GPU2D_FEATURES_RS_YUV_TARGET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_RS_YUV_TARGET(v)   BF_CS1(GPU2D_FEATURES, RS_YUV_TARGET, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field BYTE_WRITE_3D
 *
 * 3D PE has byte write capability.
 */

#define BP_GPU2D_FEATURES_BYTE_WRITE_3D      2
#define BM_GPU2D_FEATURES_BYTE_WRITE_3D      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_BYTE_WRITE_3D(v)   ((((reg32_t) v) << 2) & BM_GPU2D_FEATURES_BYTE_WRITE_3D)
#else
#define BF_GPU2D_FEATURES_BYTE_WRITE_3D(v)   (((v) << 2) & BM_GPU2D_FEATURES_BYTE_WRITE_3D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_BYTE_WRITE_3D(v)   BF_CS1(GPU2D_FEATURES, BYTE_WRITE_3D, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field FE20
 *
 * FE 2.0 is present.
 */

#define BP_GPU2D_FEATURES_FE20      3
#define BM_GPU2D_FEATURES_FE20      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_FE20(v)   ((((reg32_t) v) << 3) & BM_GPU2D_FEATURES_FE20)
#else
#define BF_GPU2D_FEATURES_FE20(v)   (((v) << 3) & BM_GPU2D_FEATURES_FE20)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_FE20(v)   BF_CS1(GPU2D_FEATURES, FE20, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field VGTS
 *
 * VG tessellator is present.
 */

#define BP_GPU2D_FEATURES_VGTS      4
#define BM_GPU2D_FEATURES_VGTS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_VGTS(v)   ((((reg32_t) v) << 4) & BM_GPU2D_FEATURES_VGTS)
#else
#define BF_GPU2D_FEATURES_VGTS(v)   (((v) << 4) & BM_GPU2D_FEATURES_VGTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_VGTS(v)   BF_CS1(GPU2D_FEATURES, VGTS, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field PIPE_VG
 *
 * VG pipe is present.
 */

#define BP_GPU2D_FEATURES_PIPE_VG      5
#define BM_GPU2D_FEATURES_PIPE_VG      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_PIPE_VG(v)   ((((reg32_t) v) << 5) & BM_GPU2D_FEATURES_PIPE_VG)
#else
#define BF_GPU2D_FEATURES_PIPE_VG(v)   (((v) << 5) & BM_GPU2D_FEATURES_PIPE_VG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_PIPE_VG(v)   BF_CS1(GPU2D_FEATURES, PIPE_VG, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field MEM32_BIT_SUPPORT
 *
 * 32 bit memory address support.
 */

#define BP_GPU2D_FEATURES_MEM32_BIT_SUPPORT      6
#define BM_GPU2D_FEATURES_MEM32_BIT_SUPPORT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_MEM32_BIT_SUPPORT(v)   ((((reg32_t) v) << 6) & BM_GPU2D_FEATURES_MEM32_BIT_SUPPORT)
#else
#define BF_GPU2D_FEATURES_MEM32_BIT_SUPPORT(v)   (((v) << 6) & BM_GPU2D_FEATURES_MEM32_BIT_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_MEM32_BIT_SUPPORT(v)   BF_CS1(GPU2D_FEATURES, MEM32_BIT_SUPPORT, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field YUY2_RENDER_TARGET
 *
 * YUY2 support in PE and YUY2 to RGB conversion in resolve.
 */

#define BP_GPU2D_FEATURES_YUY2_RENDER_TARGET      7
#define BM_GPU2D_FEATURES_YUY2_RENDER_TARGET      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_YUY2_RENDER_TARGET(v)   ((((reg32_t) v) << 7) & BM_GPU2D_FEATURES_YUY2_RENDER_TARGET)
#else
#define BF_GPU2D_FEATURES_YUY2_RENDER_TARGET(v)   (((v) << 7) & BM_GPU2D_FEATURES_YUY2_RENDER_TARGET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_YUY2_RENDER_TARGET(v)   BF_CS1(GPU2D_FEATURES, YUY2_RENDER_TARGET, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field HALF_TX_CACHE
 *
 * TX cache is half.
 */

#define BP_GPU2D_FEATURES_HALF_TX_CACHE      8
#define BM_GPU2D_FEATURES_HALF_TX_CACHE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_HALF_TX_CACHE(v)   ((((reg32_t) v) << 8) & BM_GPU2D_FEATURES_HALF_TX_CACHE)
#else
#define BF_GPU2D_FEATURES_HALF_TX_CACHE(v)   (((v) << 8) & BM_GPU2D_FEATURES_HALF_TX_CACHE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_HALF_TX_CACHE(v)   BF_CS1(GPU2D_FEATURES, HALF_TX_CACHE, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field HALF_PE_CACHE
 *
 * PE cache is half.
 */

#define BP_GPU2D_FEATURES_HALF_PE_CACHE      9
#define BM_GPU2D_FEATURES_HALF_PE_CACHE      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_HALF_PE_CACHE(v)   ((((reg32_t) v) << 9) & BM_GPU2D_FEATURES_HALF_PE_CACHE)
#else
#define BF_GPU2D_FEATURES_HALF_PE_CACHE(v)   (((v) << 9) & BM_GPU2D_FEATURES_HALF_PE_CACHE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_HALF_PE_CACHE(v)   BF_CS1(GPU2D_FEATURES, HALF_PE_CACHE, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field YUY2_AVERAGING
 *
 * YUY2 averaging support in resolve.
 */

#define BP_GPU2D_FEATURES_YUY2_AVERAGING      10
#define BM_GPU2D_FEATURES_YUY2_AVERAGING      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_YUY2_AVERAGING(v)   ((((reg32_t) v) << 10) & BM_GPU2D_FEATURES_YUY2_AVERAGING)
#else
#define BF_GPU2D_FEATURES_YUY2_AVERAGING(v)   (((v) << 10) & BM_GPU2D_FEATURES_YUY2_AVERAGING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_YUY2_AVERAGING(v)   BF_CS1(GPU2D_FEATURES, YUY2_AVERAGING, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field NO_SCALER
 *
 * IP does not have 2D scaler.
 */

#define BP_GPU2D_FEATURES_NO_SCALER      11
#define BM_GPU2D_FEATURES_NO_SCALER      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_NO_SCALER(v)   ((((reg32_t) v) << 11) & BM_GPU2D_FEATURES_NO_SCALER)
#else
#define BF_GPU2D_FEATURES_NO_SCALER(v)   (((v) << 11) & BM_GPU2D_FEATURES_NO_SCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_NO_SCALER(v)   BF_CS1(GPU2D_FEATURES, NO_SCALER, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field BYTE_WRITE_2D
 *
 * Supports byte write in 2D.
 */

#define BP_GPU2D_FEATURES_BYTE_WRITE_2D      12
#define BM_GPU2D_FEATURES_BYTE_WRITE_2D      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_BYTE_WRITE_2D(v)   ((((reg32_t) v) << 12) & BM_GPU2D_FEATURES_BYTE_WRITE_2D)
#else
#define BF_GPU2D_FEATURES_BYTE_WRITE_2D(v)   (((v) << 12) & BM_GPU2D_FEATURES_BYTE_WRITE_2D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_BYTE_WRITE_2D(v)   BF_CS1(GPU2D_FEATURES, BYTE_WRITE_2D, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field BUFFER_INTERLEAVING
 *
 * IP supports interleaving depth and color buffers.
 */

#define BP_GPU2D_FEATURES_BUFFER_INTERLEAVING      13
#define BM_GPU2D_FEATURES_BUFFER_INTERLEAVING      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_BUFFER_INTERLEAVING(v)   ((((reg32_t) v) << 13) & BM_GPU2D_FEATURES_BUFFER_INTERLEAVING)
#else
#define BF_GPU2D_FEATURES_BUFFER_INTERLEAVING(v)   (((v) << 13) & BM_GPU2D_FEATURES_BUFFER_INTERLEAVING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_BUFFER_INTERLEAVING(v)   BF_CS1(GPU2D_FEATURES, BUFFER_INTERLEAVING, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field NO422_TEXTURE
 *
 * IP does not have 422 texture input format.
 */

#define BP_GPU2D_FEATURES_NO422_TEXTURE      14
#define BM_GPU2D_FEATURES_NO422_TEXTURE      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_NO422_TEXTURE(v)   ((((reg32_t) v) << 14) & BM_GPU2D_FEATURES_NO422_TEXTURE)
#else
#define BF_GPU2D_FEATURES_NO422_TEXTURE(v)   (((v) << 14) & BM_GPU2D_FEATURES_NO422_TEXTURE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_NO422_TEXTURE(v)   BF_CS1(GPU2D_FEATURES, NO422_TEXTURE, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field NO_EZ
 *
 * IP does not have early-Z.
 */

#define BP_GPU2D_FEATURES_NO_EZ      15
#define BM_GPU2D_FEATURES_NO_EZ      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_NO_EZ(v)   ((((reg32_t) v) << 15) & BM_GPU2D_FEATURES_NO_EZ)
#else
#define BF_GPU2D_FEATURES_NO_EZ(v)   (((v) << 15) & BM_GPU2D_FEATURES_NO_EZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_NO_EZ(v)   BF_CS1(GPU2D_FEATURES, NO_EZ, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field MIN_AREA
 *
 * IP is configured to have minimum area.
 */

#define BP_GPU2D_FEATURES_MIN_AREA      16
#define BM_GPU2D_FEATURES_MIN_AREA      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_MIN_AREA(v)   ((((reg32_t) v) << 16) & BM_GPU2D_FEATURES_MIN_AREA)
#else
#define BF_GPU2D_FEATURES_MIN_AREA(v)   (((v) << 16) & BM_GPU2D_FEATURES_MIN_AREA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_MIN_AREA(v)   BF_CS1(GPU2D_FEATURES, MIN_AREA, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field MODULE_CG
 *
 * Second level clock gating is available.
 */

#define BP_GPU2D_FEATURES_MODULE_CG      17
#define BM_GPU2D_FEATURES_MODULE_CG      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_MODULE_CG(v)   ((((reg32_t) v) << 17) & BM_GPU2D_FEATURES_MODULE_CG)
#else
#define BF_GPU2D_FEATURES_MODULE_CG(v)   (((v) << 17) & BM_GPU2D_FEATURES_MODULE_CG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_MODULE_CG(v)   BF_CS1(GPU2D_FEATURES, MODULE_CG, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field YUV420_TILER
 *
 * YUV 4:2:0 tiler is available.
 */

#define BP_GPU2D_FEATURES_YUV420_TILER      18
#define BM_GPU2D_FEATURES_YUV420_TILER      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_YUV420_TILER(v)   ((((reg32_t) v) << 18) & BM_GPU2D_FEATURES_YUV420_TILER)
#else
#define BF_GPU2D_FEATURES_YUV420_TILER(v)   (((v) << 18) & BM_GPU2D_FEATURES_YUV420_TILER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_YUV420_TILER(v)   BF_CS1(GPU2D_FEATURES, YUV420_TILER, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field HIGH_DYNAMIC_RANGE
 *
 * Shows if the IP has HDR support.
 */

#define BP_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE      19
#define BM_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE(v)   ((((reg32_t) v) << 19) & BM_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE)
#else
#define BF_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE(v)   (((v) << 19) & BM_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE(v)   BF_CS1(GPU2D_FEATURES, HIGH_DYNAMIC_RANGE, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field FAST_SCALER
 *
 * Shows if the IP has HD scaler.
 */

#define BP_GPU2D_FEATURES_FAST_SCALER      20
#define BM_GPU2D_FEATURES_FAST_SCALER      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_FAST_SCALER(v)   ((((reg32_t) v) << 20) & BM_GPU2D_FEATURES_FAST_SCALER)
#else
#define BF_GPU2D_FEATURES_FAST_SCALER(v)   (((v) << 20) & BM_GPU2D_FEATURES_FAST_SCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_FAST_SCALER(v)   BF_CS1(GPU2D_FEATURES, FAST_SCALER, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field ETC1_TEXTURE_COMPRESSION
 *
 * ETC1 texture compression.
 */

#define BP_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION      21
#define BM_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION(v)   ((((reg32_t) v) << 21) & BM_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION)
#else
#define BF_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION(v)   (((v) << 21) & BM_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION(v)   BF_CS1(GPU2D_FEATURES, ETC1_TEXTURE_COMPRESSION, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field PIPE_2D
 *
 * Shows if there is 2D engine.
 */

#define BP_GPU2D_FEATURES_PIPE_2D      22
#define BM_GPU2D_FEATURES_PIPE_2D      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_PIPE_2D(v)   ((((reg32_t) v) << 22) & BM_GPU2D_FEATURES_PIPE_2D)
#else
#define BF_GPU2D_FEATURES_PIPE_2D(v)   (((v) << 22) & BM_GPU2D_FEATURES_PIPE_2D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_PIPE_2D(v)   BF_CS1(GPU2D_FEATURES, PIPE_2D, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field DC
 *
 * Shows if there is a display controller in the IP.
 */

#define BP_GPU2D_FEATURES_DC      23
#define BM_GPU2D_FEATURES_DC      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_DC(v)   ((((reg32_t) v) << 23) & BM_GPU2D_FEATURES_DC)
#else
#define BF_GPU2D_FEATURES_DC(v)   (((v) << 23) & BM_GPU2D_FEATURES_DC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_DC(v)   BF_CS1(GPU2D_FEATURES, DC, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field MSAA
 *
 * MSAA support.
 */

#define BP_GPU2D_FEATURES_MSAA      24
#define BM_GPU2D_FEATURES_MSAA      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_MSAA(v)   ((((reg32_t) v) << 24) & BM_GPU2D_FEATURES_MSAA)
#else
#define BF_GPU2D_FEATURES_MSAA(v)   (((v) << 24) & BM_GPU2D_FEATURES_MSAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_MSAA(v)   BF_CS1(GPU2D_FEATURES, MSAA, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field YUV420_FILTER
 *
 * YUV 4:2:0 support in filter blit.
 */

#define BP_GPU2D_FEATURES_YUV420_FILTER      25
#define BM_GPU2D_FEATURES_YUV420_FILTER      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_YUV420_FILTER(v)   ((((reg32_t) v) << 25) & BM_GPU2D_FEATURES_YUV420_FILTER)
#else
#define BF_GPU2D_FEATURES_YUV420_FILTER(v)   (((v) << 25) & BM_GPU2D_FEATURES_YUV420_FILTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_YUV420_FILTER(v)   BF_CS1(GPU2D_FEATURES, YUV420_FILTER, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field ZCOMPRESSION
 *
 * Depth and color compression.
 */

#define BP_GPU2D_FEATURES_ZCOMPRESSION      26
#define BM_GPU2D_FEATURES_ZCOMPRESSION      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_ZCOMPRESSION(v)   ((((reg32_t) v) << 26) & BM_GPU2D_FEATURES_ZCOMPRESSION)
#else
#define BF_GPU2D_FEATURES_ZCOMPRESSION(v)   (((v) << 26) & BM_GPU2D_FEATURES_ZCOMPRESSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_ZCOMPRESSION(v)   BF_CS1(GPU2D_FEATURES, ZCOMPRESSION, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field DEBUG_MODE
 *
 * Debug registers.
 */

#define BP_GPU2D_FEATURES_DEBUG_MODE      27
#define BM_GPU2D_FEATURES_DEBUG_MODE      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_DEBUG_MODE(v)   ((((reg32_t) v) << 27) & BM_GPU2D_FEATURES_DEBUG_MODE)
#else
#define BF_GPU2D_FEATURES_DEBUG_MODE(v)   (((v) << 27) & BM_GPU2D_FEATURES_DEBUG_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_DEBUG_MODE(v)   BF_CS1(GPU2D_FEATURES, DEBUG_MODE, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field DXT_TEXTURE_COMPRESSION
 *
 * DXT texture compression.
 */

#define BP_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION      28
#define BM_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION(v)   ((((reg32_t) v) << 28) & BM_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION)
#else
#define BF_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION(v)   (((v) << 28) & BM_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION(v)   BF_CS1(GPU2D_FEATURES, DXT_TEXTURE_COMPRESSION, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field PIPE_3D
 *
 * 3D pipe.
 */

#define BP_GPU2D_FEATURES_PIPE_3D      29
#define BM_GPU2D_FEATURES_PIPE_3D      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_PIPE_3D(v)   ((((reg32_t) v) << 29) & BM_GPU2D_FEATURES_PIPE_3D)
#else
#define BF_GPU2D_FEATURES_PIPE_3D(v)   (((v) << 29) & BM_GPU2D_FEATURES_PIPE_3D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_PIPE_3D(v)   BF_CS1(GPU2D_FEATURES, PIPE_3D, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field SPECIAL_ANTI_ALIASING
 *
 * Full-screen anti-aliasing.
 */

#define BP_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING      30
#define BM_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING(v)   ((((reg32_t) v) << 30) & BM_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING)
#else
#define BF_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING(v)   (((v) << 30) & BM_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING(v)   BF_CS1(GPU2D_FEATURES, SPECIAL_ANTI_ALIASING, v)
#endif

/* --- Register HW_GPU2D_FEATURES, field FAST_CLEAR
 *
 * Fast clear.
 */

#define BP_GPU2D_FEATURES_FAST_CLEAR      31
#define BM_GPU2D_FEATURES_FAST_CLEAR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_FEATURES_FAST_CLEAR(v)   ((((reg32_t) v) << 31) & BM_GPU2D_FEATURES_FAST_CLEAR)
#else
#define BF_GPU2D_FEATURES_FAST_CLEAR(v)   (((v) << 31) & BM_GPU2D_FEATURES_FAST_CLEAR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_FEATURES_FAST_CLEAR(v)   BF_CS1(GPU2D_FEATURES, FAST_CLEAR, v)
#endif

/*!
 * @brief HW_GPU2D_CHIPID - Chip Identification Register
 *
 * Shows the ID for the chip in BCD. This register has no set reset value.
 * It varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ID : 32; //!< Id.
    } B;
} hw_gpu2d_chipid_t;
#endif

/*
 * constants & macros for entire GPU2D_CHIPID register
 */
#define HW_GPU2D_CHIPID_ADDR      (REGS_GPU2D_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_CHIPID           (*(volatile hw_gpu2d_chipid_t *) HW_GPU2D_CHIPID_ADDR)
#define HW_GPU2D_CHIPID_RD()      (HW_GPU2D_CHIPID.U)
#define HW_GPU2D_CHIPID_WR(v)     (HW_GPU2D_CHIPID.U = (v))
#define HW_GPU2D_CHIPID_SET(v)    (HW_GPU2D_CHIPID_WR(HW_GPU2D_CHIPID_RD() |  (v)))
#define HW_GPU2D_CHIPID_CLR(v)    (HW_GPU2D_CHIPID_WR(HW_GPU2D_CHIPID_RD() & ~(v)))
#define HW_GPU2D_CHIPID_TOG(v)    (HW_GPU2D_CHIPID_WR(HW_GPU2D_CHIPID_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_CHIPID bitfields
 */

/* --- Register HW_GPU2D_CHIPID, field ID
 *
 * Id.
 */

#define BP_GPU2D_CHIPID_ID      0
#define BM_GPU2D_CHIPID_ID      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPID_ID(v)   ((((reg32_t) v) << 0) & BM_GPU2D_CHIPID_ID)
#else
#define BF_GPU2D_CHIPID_ID(v)   (((v) << 0) & BM_GPU2D_CHIPID_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPID_ID(v)   BF_CS1(GPU2D_CHIPID, ID, v)
#endif

/*!
 * @brief HW_GPU2D_CHIPREV - Chip Revision Register
 *
 * Shows the revision for the chip in BCD. This register has no set reset
 * value. It varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned REV : 32; //!< Revision.
    } B;
} hw_gpu2d_chiprev_t;
#endif

/*
 * constants & macros for entire GPU2D_CHIPREV register
 */
#define HW_GPU2D_CHIPREV_ADDR      (REGS_GPU2D_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_CHIPREV           (*(volatile hw_gpu2d_chiprev_t *) HW_GPU2D_CHIPREV_ADDR)
#define HW_GPU2D_CHIPREV_RD()      (HW_GPU2D_CHIPREV.U)
#define HW_GPU2D_CHIPREV_WR(v)     (HW_GPU2D_CHIPREV.U = (v))
#define HW_GPU2D_CHIPREV_SET(v)    (HW_GPU2D_CHIPREV_WR(HW_GPU2D_CHIPREV_RD() |  (v)))
#define HW_GPU2D_CHIPREV_CLR(v)    (HW_GPU2D_CHIPREV_WR(HW_GPU2D_CHIPREV_RD() & ~(v)))
#define HW_GPU2D_CHIPREV_TOG(v)    (HW_GPU2D_CHIPREV_WR(HW_GPU2D_CHIPREV_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_CHIPREV bitfields
 */

/* --- Register HW_GPU2D_CHIPREV, field REV
 *
 * Revision.
 */

#define BP_GPU2D_CHIPREV_REV      0
#define BM_GPU2D_CHIPREV_REV      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPREV_REV(v)   ((((reg32_t) v) << 0) & BM_GPU2D_CHIPREV_REV)
#else
#define BF_GPU2D_CHIPREV_REV(v)   (((v) << 0) & BM_GPU2D_CHIPREV_REV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPREV_REV(v)   BF_CS1(GPU2D_CHIPREV, REV, v)
#endif

/*!
 * @brief HW_GPU2D_CHIPDATE - Chip Release Date Register
 *
 * Shows the release date for the IP. This register has no set reset value.
 * It varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATE : 32; //!< Date.
    } B;
} hw_gpu2d_chipdate_t;
#endif

/*
 * constants & macros for entire GPU2D_CHIPDATE register
 */
#define HW_GPU2D_CHIPDATE_ADDR      (REGS_GPU2D_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_CHIPDATE           (*(volatile hw_gpu2d_chipdate_t *) HW_GPU2D_CHIPDATE_ADDR)
#define HW_GPU2D_CHIPDATE_RD()      (HW_GPU2D_CHIPDATE.U)
#define HW_GPU2D_CHIPDATE_WR(v)     (HW_GPU2D_CHIPDATE.U = (v))
#define HW_GPU2D_CHIPDATE_SET(v)    (HW_GPU2D_CHIPDATE_WR(HW_GPU2D_CHIPDATE_RD() |  (v)))
#define HW_GPU2D_CHIPDATE_CLR(v)    (HW_GPU2D_CHIPDATE_WR(HW_GPU2D_CHIPDATE_RD() & ~(v)))
#define HW_GPU2D_CHIPDATE_TOG(v)    (HW_GPU2D_CHIPDATE_WR(HW_GPU2D_CHIPDATE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_CHIPDATE bitfields
 */

/* --- Register HW_GPU2D_CHIPDATE, field DATE
 *
 * Date.
 */

#define BP_GPU2D_CHIPDATE_DATE      0
#define BM_GPU2D_CHIPDATE_DATE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPDATE_DATE(v)   ((((reg32_t) v) << 0) & BM_GPU2D_CHIPDATE_DATE)
#else
#define BF_GPU2D_CHIPDATE_DATE(v)   (((v) << 0) & BM_GPU2D_CHIPDATE_DATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPDATE_DATE(v)   BF_CS1(GPU2D_CHIPDATE, DATE, v)
#endif

/*!
 * @brief HW_GPU2D_CHIPTIME - Chip Release Time Register
 *
 * Shows the release time for the IP. This register has no set reset value.
 * It varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TIME : 32; //!< Time.
    } B;
} hw_gpu2d_chiptime_t;
#endif

/*
 * constants & macros for entire GPU2D_CHIPTIME register
 */
#define HW_GPU2D_CHIPTIME_ADDR      (REGS_GPU2D_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_CHIPTIME           (*(volatile hw_gpu2d_chiptime_t *) HW_GPU2D_CHIPTIME_ADDR)
#define HW_GPU2D_CHIPTIME_RD()      (HW_GPU2D_CHIPTIME.U)
#define HW_GPU2D_CHIPTIME_WR(v)     (HW_GPU2D_CHIPTIME.U = (v))
#define HW_GPU2D_CHIPTIME_SET(v)    (HW_GPU2D_CHIPTIME_WR(HW_GPU2D_CHIPTIME_RD() |  (v)))
#define HW_GPU2D_CHIPTIME_CLR(v)    (HW_GPU2D_CHIPTIME_WR(HW_GPU2D_CHIPTIME_RD() & ~(v)))
#define HW_GPU2D_CHIPTIME_TOG(v)    (HW_GPU2D_CHIPTIME_WR(HW_GPU2D_CHIPTIME_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_CHIPTIME bitfields
 */

/* --- Register HW_GPU2D_CHIPTIME, field TIME
 *
 * Time.
 */

#define BP_GPU2D_CHIPTIME_TIME      0
#define BM_GPU2D_CHIPTIME_TIME      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPTIME_TIME(v)   ((((reg32_t) v) << 0) & BM_GPU2D_CHIPTIME_TIME)
#else
#define BF_GPU2D_CHIPTIME_TIME(v)   (((v) << 0) & BM_GPU2D_CHIPTIME_TIME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPTIME_TIME(v)   BF_CS1(GPU2D_CHIPTIME, TIME, v)
#endif

/*!
 * @brief HW_GPU2D_CHIPCUSTOMER - Chip Customer Register
 *
 * Shows the customer and group for the IP. This register has no set reset
 * value. It varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GROUP : 16; //!< Group.
        unsigned COMPANY : 16; //!< Company.
    } B;
} hw_gpu2d_chipcustomer_t;
#endif

/*
 * constants & macros for entire GPU2D_CHIPCUSTOMER register
 */
#define HW_GPU2D_CHIPCUSTOMER_ADDR      (REGS_GPU2D_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_CHIPCUSTOMER           (*(volatile hw_gpu2d_chipcustomer_t *) HW_GPU2D_CHIPCUSTOMER_ADDR)
#define HW_GPU2D_CHIPCUSTOMER_RD()      (HW_GPU2D_CHIPCUSTOMER.U)
#define HW_GPU2D_CHIPCUSTOMER_WR(v)     (HW_GPU2D_CHIPCUSTOMER.U = (v))
#define HW_GPU2D_CHIPCUSTOMER_SET(v)    (HW_GPU2D_CHIPCUSTOMER_WR(HW_GPU2D_CHIPCUSTOMER_RD() |  (v)))
#define HW_GPU2D_CHIPCUSTOMER_CLR(v)    (HW_GPU2D_CHIPCUSTOMER_WR(HW_GPU2D_CHIPCUSTOMER_RD() & ~(v)))
#define HW_GPU2D_CHIPCUSTOMER_TOG(v)    (HW_GPU2D_CHIPCUSTOMER_WR(HW_GPU2D_CHIPCUSTOMER_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_CHIPCUSTOMER bitfields
 */

/* --- Register HW_GPU2D_CHIPCUSTOMER, field GROUP
 *
 * Group.
 */

#define BP_GPU2D_CHIPCUSTOMER_GROUP      0
#define BM_GPU2D_CHIPCUSTOMER_GROUP      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPCUSTOMER_GROUP(v)   ((((reg32_t) v) << 0) & BM_GPU2D_CHIPCUSTOMER_GROUP)
#else
#define BF_GPU2D_CHIPCUSTOMER_GROUP(v)   (((v) << 0) & BM_GPU2D_CHIPCUSTOMER_GROUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPCUSTOMER_GROUP(v)   BF_CS1(GPU2D_CHIPCUSTOMER, GROUP, v)
#endif

/* --- Register HW_GPU2D_CHIPCUSTOMER, field COMPANY
 *
 * Company.
 */

#define BP_GPU2D_CHIPCUSTOMER_COMPANY      16
#define BM_GPU2D_CHIPCUSTOMER_COMPANY      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPCUSTOMER_COMPANY(v)   ((((reg32_t) v) << 16) & BM_GPU2D_CHIPCUSTOMER_COMPANY)
#else
#define BF_GPU2D_CHIPCUSTOMER_COMPANY(v)   (((v) << 16) & BM_GPU2D_CHIPCUSTOMER_COMPANY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPCUSTOMER_COMPANY(v)   BF_CS1(GPU2D_CHIPCUSTOMER, COMPANY, v)
#endif

/*!
 * @brief HW_GPU2D_MINORFEATURES0 - Minor Features Register 0
 *
 * Shows which minor features are enabled in this chip. This register has no
 * set reset value. It varies with the implementation.
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
        unsigned TEXTURE8_K : 1; //!< Supports 8Kx8K textures.
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
        unsigned EXTRA_SHADER_INSTRUCTIONS1 : 1; //!< Sqrt, sin, cos instructions are available.
        unsigned DEFAULT_REG0 : 1; //!< Unavailable registers will return 0.
        unsigned MC_20 : 1; //!< New style MC with separate paths for color and depth.
        unsigned SHADER_MSAA_SIDEBAND : 1; //!< Put the MSAA data into sideband fifo.
        unsigned BUG_FIXES0 : 1; //!< 
        unsigned VAA : 1; //!< VAA is available or not.
        unsigned BYPASS_IN_MSAA : 1; //!< Shader supports bypass mode when MSAA is enabled.
        unsigned HIERARCHICAL_Z : 1; //!< Hierarchiccal Z is supported.
        unsigned NEW_TEXTURE : 1; //!< New texture unit is available.
        unsigned A8_TARGET_SUPPORT : 1; //!< 2D engine supports A8 target.
        unsigned CORRECT_STENCIL : 1; //!< Correct stencil behavior in depth only.
        unsigned ENHANCE_VR : 1; //!< Enhance VR and add a mode to walk 16 pixels in 16-bit mode in Vertical pass to improve $ hit rate when rotating 90/270.
    } B;
} hw_gpu2d_minorfeatures0_t;
#endif

/*
 * constants & macros for entire GPU2D_MINORFEATURES0 register
 */
#define HW_GPU2D_MINORFEATURES0_ADDR      (REGS_GPU2D_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_MINORFEATURES0           (*(volatile hw_gpu2d_minorfeatures0_t *) HW_GPU2D_MINORFEATURES0_ADDR)
#define HW_GPU2D_MINORFEATURES0_RD()      (HW_GPU2D_MINORFEATURES0.U)
#define HW_GPU2D_MINORFEATURES0_WR(v)     (HW_GPU2D_MINORFEATURES0.U = (v))
#define HW_GPU2D_MINORFEATURES0_SET(v)    (HW_GPU2D_MINORFEATURES0_WR(HW_GPU2D_MINORFEATURES0_RD() |  (v)))
#define HW_GPU2D_MINORFEATURES0_CLR(v)    (HW_GPU2D_MINORFEATURES0_WR(HW_GPU2D_MINORFEATURES0_RD() & ~(v)))
#define HW_GPU2D_MINORFEATURES0_TOG(v)    (HW_GPU2D_MINORFEATURES0_WR(HW_GPU2D_MINORFEATURES0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_MINORFEATURES0 bitfields
 */

/* --- Register HW_GPU2D_MINORFEATURES0, field FLIP_Y
 *
 * Y flipping capability is added to resolve.
 */

#define BP_GPU2D_MINORFEATURES0_FLIP_Y      0
#define BM_GPU2D_MINORFEATURES0_FLIP_Y      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_FLIP_Y(v)   ((((reg32_t) v) << 0) & BM_GPU2D_MINORFEATURES0_FLIP_Y)
#else
#define BF_GPU2D_MINORFEATURES0_FLIP_Y(v)   (((v) << 0) & BM_GPU2D_MINORFEATURES0_FLIP_Y)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_FLIP_Y(v)   BF_CS1(GPU2D_MINORFEATURES0, FLIP_Y, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field DUAL_RETURN_BUS
 *
 * Dual Return Bus from HI to clients.
 */

#define BP_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS      1
#define BM_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS(v)   ((((reg32_t) v) << 1) & BM_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS)
#else
#define BF_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS(v)   (((v) << 1) & BM_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS(v)   BF_CS1(GPU2D_MINORFEATURES0, DUAL_RETURN_BUS, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field ENDIANNESS_CONFIG
 *
 * Configurable endianness support.
 */

#define BP_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG      2
#define BM_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG(v)   ((((reg32_t) v) << 2) & BM_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG)
#else
#define BF_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG(v)   (((v) << 2) & BM_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG(v)   BF_CS1(GPU2D_MINORFEATURES0, ENDIANNESS_CONFIG, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field TEXTURE8_K
 *
 * Supports 8Kx8K textures.
 */

#define BP_GPU2D_MINORFEATURES0_TEXTURE8_K      3
#define BM_GPU2D_MINORFEATURES0_TEXTURE8_K      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_TEXTURE8_K(v)   ((((reg32_t) v) << 3) & BM_GPU2D_MINORFEATURES0_TEXTURE8_K)
#else
#define BF_GPU2D_MINORFEATURES0_TEXTURE8_K(v)   (((v) << 3) & BM_GPU2D_MINORFEATURES0_TEXTURE8_K)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_TEXTURE8_K(v)   BF_CS1(GPU2D_MINORFEATURES0, TEXTURE8_K, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field CORRECT_TEXTURE_CONVERTER
 *
 * Driver hack is not needed.
 */

#define BP_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER      4
#define BM_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER(v)   ((((reg32_t) v) << 4) & BM_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER)
#else
#define BF_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER(v)   (((v) << 4) & BM_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER(v)   BF_CS1(GPU2D_MINORFEATURES0, CORRECT_TEXTURE_CONVERTER, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field SPECIAL_MSAA_LOD
 *
 * Special LOD calculation when MSAA is on.
 */

#define BP_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD      5
#define BM_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD(v)   ((((reg32_t) v) << 5) & BM_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD)
#else
#define BF_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD(v)   (((v) << 5) & BM_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD(v)   BF_CS1(GPU2D_MINORFEATURES0, SPECIAL_MSAA_LOD, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field FAST_CLEAR_FLUSH
 *
 * Proper flush is done in fast clear cache.
 */

#define BP_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH      6
#define BM_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH(v)   ((((reg32_t) v) << 6) & BM_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH)
#else
#define BF_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH(v)   (((v) << 6) & BM_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH(v)   BF_CS1(GPU2D_MINORFEATURES0, FAST_CLEAR_FLUSH, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field CORRECT_AUTO_DISABLE
 *
 * Auto disable in FC is correct.
 */

#define BP_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE      8
#define BM_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE(v)   ((((reg32_t) v) << 8) & BM_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE)
#else
#define BF_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE(v)   (((v) << 8) & BM_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE(v)   BF_CS1(GPU2D_MINORFEATURES0, CORRECT_AUTO_DISABLE, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field RENDER_8K
 *
 * Supports 8K render target.
 */

#define BP_GPU2D_MINORFEATURES0_RENDER_8K      9
#define BM_GPU2D_MINORFEATURES0_RENDER_8K      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_RENDER_8K(v)   ((((reg32_t) v) << 9) & BM_GPU2D_MINORFEATURES0_RENDER_8K)
#else
#define BF_GPU2D_MINORFEATURES0_RENDER_8K(v)   (((v) << 9) & BM_GPU2D_MINORFEATURES0_RENDER_8K)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_RENDER_8K(v)   BF_CS1(GPU2D_MINORFEATURES0, RENDER_8K, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field TILE_STATUS_2BITS
 *
 * 2 bits are used instead of 4 bits for tile status.
 */

#define BP_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS      10
#define BM_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS(v)   ((((reg32_t) v) << 10) & BM_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS)
#else
#define BF_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS(v)   (((v) << 10) & BM_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS(v)   BF_CS1(GPU2D_MINORFEATURES0, TILE_STATUS_2BITS, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field SEPARATE_TILE_STATUS_WHEN_INTERLEAVED
 *
 * Use 2 separate tile status buffers in interleaved mode.
 */

#define BP_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED      11
#define BM_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED(v)   ((((reg32_t) v) << 11) & BM_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED)
#else
#define BF_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED(v)   (((v) << 11) & BM_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED(v)   BF_CS1(GPU2D_MINORFEATURES0, SEPARATE_TILE_STATUS_WHEN_INTERLEAVED, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field SUPER_TILED_32X32
 *
 * 32x32 super tile is available.
 */

#define BP_GPU2D_MINORFEATURES0_SUPER_TILED_32X32      12
#define BM_GPU2D_MINORFEATURES0_SUPER_TILED_32X32      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_SUPER_TILED_32X32(v)   ((((reg32_t) v) << 12) & BM_GPU2D_MINORFEATURES0_SUPER_TILED_32X32)
#else
#define BF_GPU2D_MINORFEATURES0_SUPER_TILED_32X32(v)   (((v) << 12) & BM_GPU2D_MINORFEATURES0_SUPER_TILED_32X32)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_SUPER_TILED_32X32(v)   BF_CS1(GPU2D_MINORFEATURES0, SUPER_TILED_32X32, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field VG_20
 *
 * Major updates to VG pipe (TS buffer tiling. State masking.).
 */

#define BP_GPU2D_MINORFEATURES0_VG_20      13
#define BM_GPU2D_MINORFEATURES0_VG_20      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_VG_20(v)   ((((reg32_t) v) << 13) & BM_GPU2D_MINORFEATURES0_VG_20)
#else
#define BF_GPU2D_MINORFEATURES0_VG_20(v)   (((v) << 13) & BM_GPU2D_MINORFEATURES0_VG_20)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_VG_20(v)   BF_CS1(GPU2D_MINORFEATURES0, VG_20, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field TS_EXTENDED_COMMANDS
 *
 * New commands added to the tessellator.
 */

#define BP_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS      14
#define BM_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS(v)   ((((reg32_t) v) << 14) & BM_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS)
#else
#define BF_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS(v)   (((v) << 14) & BM_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS(v)   BF_CS1(GPU2D_MINORFEATURES0, TS_EXTENDED_COMMANDS, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field COMPRESSION_FIFO_FIXED
 *
 * If this bit is not set, the FIFO counter should be set to 50. Else,
 * the default should remain.
 */

#define BP_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED      15
#define BM_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED(v)   ((((reg32_t) v) << 15) & BM_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED)
#else
#define BF_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED(v)   (((v) << 15) & BM_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED(v)   BF_CS1(GPU2D_MINORFEATURES0, COMPRESSION_FIFO_FIXED, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field EXTRA_SHADER_INSTRUCTIONS0
 *
 * Floor, ceil, and sign instructions are available.
 */

#define BP_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0      16
#define BM_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0(v)   ((((reg32_t) v) << 16) & BM_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0)
#else
#define BF_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0(v)   (((v) << 16) & BM_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0(v)   BF_CS1(GPU2D_MINORFEATURES0, EXTRA_SHADER_INSTRUCTIONS0, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field VG_FILTER
 *
 * VG filter is available.
 */

#define BP_GPU2D_MINORFEATURES0_VG_FILTER      17
#define BM_GPU2D_MINORFEATURES0_VG_FILTER      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_VG_FILTER(v)   ((((reg32_t) v) << 17) & BM_GPU2D_MINORFEATURES0_VG_FILTER)
#else
#define BF_GPU2D_MINORFEATURES0_VG_FILTER(v)   (((v) << 17) & BM_GPU2D_MINORFEATURES0_VG_FILTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_VG_FILTER(v)   BF_CS1(GPU2D_MINORFEATURES0, VG_FILTER, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field VG_21
 *
 * Minor updates to VG pipe (Event generation from VG, TS, PE). Tiled
 * image support.
 */

#define BP_GPU2D_MINORFEATURES0_VG_21      18
#define BM_GPU2D_MINORFEATURES0_VG_21      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_VG_21(v)   ((((reg32_t) v) << 18) & BM_GPU2D_MINORFEATURES0_VG_21)
#else
#define BF_GPU2D_MINORFEATURES0_VG_21(v)   (((v) << 18) & BM_GPU2D_MINORFEATURES0_VG_21)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_VG_21(v)   BF_CS1(GPU2D_MINORFEATURES0, VG_21, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field SHADER_GETS_W
 *
 * W is sent to SH from RA.
 */

#define BP_GPU2D_MINORFEATURES0_SHADER_GETS_W      19
#define BM_GPU2D_MINORFEATURES0_SHADER_GETS_W      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_SHADER_GETS_W(v)   ((((reg32_t) v) << 19) & BM_GPU2D_MINORFEATURES0_SHADER_GETS_W)
#else
#define BF_GPU2D_MINORFEATURES0_SHADER_GETS_W(v)   (((v) << 19) & BM_GPU2D_MINORFEATURES0_SHADER_GETS_W)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_SHADER_GETS_W(v)   BF_CS1(GPU2D_MINORFEATURES0, SHADER_GETS_W, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field EXTRA_SHADER_INSTRUCTIONS1
 *
 * Sqrt, sin, cos instructions are available.
 */

#define BP_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1      20
#define BM_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1(v)   ((((reg32_t) v) << 20) & BM_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1)
#else
#define BF_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1(v)   (((v) << 20) & BM_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1(v)   BF_CS1(GPU2D_MINORFEATURES0, EXTRA_SHADER_INSTRUCTIONS1, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field DEFAULT_REG0
 *
 * Unavailable registers will return 0.
 */

#define BP_GPU2D_MINORFEATURES0_DEFAULT_REG0      21
#define BM_GPU2D_MINORFEATURES0_DEFAULT_REG0      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_DEFAULT_REG0(v)   ((((reg32_t) v) << 21) & BM_GPU2D_MINORFEATURES0_DEFAULT_REG0)
#else
#define BF_GPU2D_MINORFEATURES0_DEFAULT_REG0(v)   (((v) << 21) & BM_GPU2D_MINORFEATURES0_DEFAULT_REG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_DEFAULT_REG0(v)   BF_CS1(GPU2D_MINORFEATURES0, DEFAULT_REG0, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field MC_20
 *
 * New style MC with separate paths for color and depth.
 */

#define BP_GPU2D_MINORFEATURES0_MC_20      22
#define BM_GPU2D_MINORFEATURES0_MC_20      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_MC_20(v)   ((((reg32_t) v) << 22) & BM_GPU2D_MINORFEATURES0_MC_20)
#else
#define BF_GPU2D_MINORFEATURES0_MC_20(v)   (((v) << 22) & BM_GPU2D_MINORFEATURES0_MC_20)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_MC_20(v)   BF_CS1(GPU2D_MINORFEATURES0, MC_20, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field SHADER_MSAA_SIDEBAND
 *
 * Put the MSAA data into sideband fifo.
 */

#define BP_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND      23
#define BM_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND(v)   ((((reg32_t) v) << 23) & BM_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND)
#else
#define BF_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND(v)   (((v) << 23) & BM_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND(v)   BF_CS1(GPU2D_MINORFEATURES0, SHADER_MSAA_SIDEBAND, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field BUG_FIXES0
 *

 */

#define BP_GPU2D_MINORFEATURES0_BUG_FIXES0      24
#define BM_GPU2D_MINORFEATURES0_BUG_FIXES0      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_BUG_FIXES0(v)   ((((reg32_t) v) << 24) & BM_GPU2D_MINORFEATURES0_BUG_FIXES0)
#else
#define BF_GPU2D_MINORFEATURES0_BUG_FIXES0(v)   (((v) << 24) & BM_GPU2D_MINORFEATURES0_BUG_FIXES0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_BUG_FIXES0(v)   BF_CS1(GPU2D_MINORFEATURES0, BUG_FIXES0, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field VAA
 *
 * VAA is available or not.
 */

#define BP_GPU2D_MINORFEATURES0_VAA      25
#define BM_GPU2D_MINORFEATURES0_VAA      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_VAA(v)   ((((reg32_t) v) << 25) & BM_GPU2D_MINORFEATURES0_VAA)
#else
#define BF_GPU2D_MINORFEATURES0_VAA(v)   (((v) << 25) & BM_GPU2D_MINORFEATURES0_VAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_VAA(v)   BF_CS1(GPU2D_MINORFEATURES0, VAA, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field BYPASS_IN_MSAA
 *
 * Shader supports bypass mode when MSAA is enabled.
 */

#define BP_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA      26
#define BM_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA(v)   ((((reg32_t) v) << 26) & BM_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA)
#else
#define BF_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA(v)   (((v) << 26) & BM_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA(v)   BF_CS1(GPU2D_MINORFEATURES0, BYPASS_IN_MSAA, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field HIERARCHICAL_Z
 *
 * Hierarchiccal Z is supported.
 */

#define BP_GPU2D_MINORFEATURES0_HIERARCHICAL_Z      27
#define BM_GPU2D_MINORFEATURES0_HIERARCHICAL_Z      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_HIERARCHICAL_Z(v)   ((((reg32_t) v) << 27) & BM_GPU2D_MINORFEATURES0_HIERARCHICAL_Z)
#else
#define BF_GPU2D_MINORFEATURES0_HIERARCHICAL_Z(v)   (((v) << 27) & BM_GPU2D_MINORFEATURES0_HIERARCHICAL_Z)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_HIERARCHICAL_Z(v)   BF_CS1(GPU2D_MINORFEATURES0, HIERARCHICAL_Z, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field NEW_TEXTURE
 *
 * New texture unit is available.
 */

#define BP_GPU2D_MINORFEATURES0_NEW_TEXTURE      28
#define BM_GPU2D_MINORFEATURES0_NEW_TEXTURE      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_NEW_TEXTURE(v)   ((((reg32_t) v) << 28) & BM_GPU2D_MINORFEATURES0_NEW_TEXTURE)
#else
#define BF_GPU2D_MINORFEATURES0_NEW_TEXTURE(v)   (((v) << 28) & BM_GPU2D_MINORFEATURES0_NEW_TEXTURE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_NEW_TEXTURE(v)   BF_CS1(GPU2D_MINORFEATURES0, NEW_TEXTURE, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field A8_TARGET_SUPPORT
 *
 * 2D engine supports A8 target.
 */

#define BP_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT      29
#define BM_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT(v)   ((((reg32_t) v) << 29) & BM_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT)
#else
#define BF_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT(v)   (((v) << 29) & BM_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT(v)   BF_CS1(GPU2D_MINORFEATURES0, A8_TARGET_SUPPORT, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field CORRECT_STENCIL
 *
 * Correct stencil behavior in depth only.
 */

#define BP_GPU2D_MINORFEATURES0_CORRECT_STENCIL      30
#define BM_GPU2D_MINORFEATURES0_CORRECT_STENCIL      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_CORRECT_STENCIL(v)   ((((reg32_t) v) << 30) & BM_GPU2D_MINORFEATURES0_CORRECT_STENCIL)
#else
#define BF_GPU2D_MINORFEATURES0_CORRECT_STENCIL(v)   (((v) << 30) & BM_GPU2D_MINORFEATURES0_CORRECT_STENCIL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_CORRECT_STENCIL(v)   BF_CS1(GPU2D_MINORFEATURES0, CORRECT_STENCIL, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES0, field ENHANCE_VR
 *
 * Enhance VR and add a mode to walk 16 pixels in 16-bit mode in
 * Vertical pass to improve $ hit rate when rotating 90/270.
 */

#define BP_GPU2D_MINORFEATURES0_ENHANCE_VR      31
#define BM_GPU2D_MINORFEATURES0_ENHANCE_VR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES0_ENHANCE_VR(v)   ((((reg32_t) v) << 31) & BM_GPU2D_MINORFEATURES0_ENHANCE_VR)
#else
#define BF_GPU2D_MINORFEATURES0_ENHANCE_VR(v)   (((v) << 31) & BM_GPU2D_MINORFEATURES0_ENHANCE_VR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES0_ENHANCE_VR(v)   BF_CS1(GPU2D_MINORFEATURES0, ENHANCE_VR, v)
#endif

/*!
 * @brief HW_GPU2D_CACHECONTROL - Cache Control Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NOT_USED : 32; //!< Reserved
    } B;
} hw_gpu2d_cachecontrol_t;
#endif

/*
 * constants & macros for entire GPU2D_CACHECONTROL register
 */
#define HW_GPU2D_CACHECONTROL_ADDR      (REGS_GPU2D_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_CACHECONTROL           (*(volatile hw_gpu2d_cachecontrol_t *) HW_GPU2D_CACHECONTROL_ADDR)
#define HW_GPU2D_CACHECONTROL_RD()      (HW_GPU2D_CACHECONTROL.U)
#define HW_GPU2D_CACHECONTROL_WR(v)     (HW_GPU2D_CACHECONTROL.U = (v))
#define HW_GPU2D_CACHECONTROL_SET(v)    (HW_GPU2D_CACHECONTROL_WR(HW_GPU2D_CACHECONTROL_RD() |  (v)))
#define HW_GPU2D_CACHECONTROL_CLR(v)    (HW_GPU2D_CACHECONTROL_WR(HW_GPU2D_CACHECONTROL_RD() & ~(v)))
#define HW_GPU2D_CACHECONTROL_TOG(v)    (HW_GPU2D_CACHECONTROL_WR(HW_GPU2D_CACHECONTROL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_CACHECONTROL bitfields
 */

/* --- Register HW_GPU2D_CACHECONTROL, field NOT_USED
 *
 * Reserved
 */

#define BP_GPU2D_CACHECONTROL_NOT_USED      0
#define BM_GPU2D_CACHECONTROL_NOT_USED      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CACHECONTROL_NOT_USED(v)   ((((reg32_t) v) << 0) & BM_GPU2D_CACHECONTROL_NOT_USED)
#else
#define BF_GPU2D_CACHECONTROL_NOT_USED(v)   (((v) << 0) & BM_GPU2D_CACHECONTROL_NOT_USED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CACHECONTROL_NOT_USED(v)   BF_CS1(GPU2D_CACHECONTROL, NOT_USED, v)
#endif

/*!
 * @brief HW_GPU2D_RESETMEMCOUNTERS - Reset Mem Counters Register
 *
 * Writing 1 will reset the counters and stop counting. Write 0 to start
 * counting again. This register is write only so it has no reset                             value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESET : 32; //!< 
    } B;
} hw_gpu2d_resetmemcounters_t;
#endif

/*
 * constants & macros for entire GPU2D_RESETMEMCOUNTERS register
 */
#define HW_GPU2D_RESETMEMCOUNTERS_ADDR      (REGS_GPU2D_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_RESETMEMCOUNTERS           (*(volatile hw_gpu2d_resetmemcounters_t *) HW_GPU2D_RESETMEMCOUNTERS_ADDR)
#define HW_GPU2D_RESETMEMCOUNTERS_RD()      (HW_GPU2D_RESETMEMCOUNTERS.U)
#define HW_GPU2D_RESETMEMCOUNTERS_WR(v)     (HW_GPU2D_RESETMEMCOUNTERS.U = (v))
#define HW_GPU2D_RESETMEMCOUNTERS_SET(v)    (HW_GPU2D_RESETMEMCOUNTERS_WR(HW_GPU2D_RESETMEMCOUNTERS_RD() |  (v)))
#define HW_GPU2D_RESETMEMCOUNTERS_CLR(v)    (HW_GPU2D_RESETMEMCOUNTERS_WR(HW_GPU2D_RESETMEMCOUNTERS_RD() & ~(v)))
#define HW_GPU2D_RESETMEMCOUNTERS_TOG(v)    (HW_GPU2D_RESETMEMCOUNTERS_WR(HW_GPU2D_RESETMEMCOUNTERS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_RESETMEMCOUNTERS bitfields
 */

/* --- Register HW_GPU2D_RESETMEMCOUNTERS, field RESET
 *

 */

#define BP_GPU2D_RESETMEMCOUNTERS_RESET      0
#define BM_GPU2D_RESETMEMCOUNTERS_RESET      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_RESETMEMCOUNTERS_RESET(v)   ((((reg32_t) v) << 0) & BM_GPU2D_RESETMEMCOUNTERS_RESET)
#else
#define BF_GPU2D_RESETMEMCOUNTERS_RESET(v)   (((v) << 0) & BM_GPU2D_RESETMEMCOUNTERS_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_RESETMEMCOUNTERS_RESET(v)   BF_CS1(GPU2D_RESETMEMCOUNTERS, RESET, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALREADS - Read Count Register
 *
 * Total reads in terms of 64bits.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu2d_totalreads_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALREADS register
 */
#define HW_GPU2D_TOTALREADS_ADDR      (REGS_GPU2D_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALREADS           (*(volatile hw_gpu2d_totalreads_t *) HW_GPU2D_TOTALREADS_ADDR)
#define HW_GPU2D_TOTALREADS_RD()      (HW_GPU2D_TOTALREADS.U)
#define HW_GPU2D_TOTALREADS_WR(v)     (HW_GPU2D_TOTALREADS.U = (v))
#define HW_GPU2D_TOTALREADS_SET(v)    (HW_GPU2D_TOTALREADS_WR(HW_GPU2D_TOTALREADS_RD() |  (v)))
#define HW_GPU2D_TOTALREADS_CLR(v)    (HW_GPU2D_TOTALREADS_WR(HW_GPU2D_TOTALREADS_RD() & ~(v)))
#define HW_GPU2D_TOTALREADS_TOG(v)    (HW_GPU2D_TOTALREADS_WR(HW_GPU2D_TOTALREADS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALREADS bitfields
 */

/* --- Register HW_GPU2D_TOTALREADS, field COUNT
 *

 */

#define BP_GPU2D_TOTALREADS_COUNT      0
#define BM_GPU2D_TOTALREADS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALREADS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALREADS_COUNT)
#else
#define BF_GPU2D_TOTALREADS_COUNT(v)   (((v) << 0) & BM_GPU2D_TOTALREADS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALREADS_COUNT(v)   BF_CS1(GPU2D_TOTALREADS, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALWRITES - Write Count Register
 *
 * Total writes in terms of 64bits.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu2d_totalwrites_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALWRITES register
 */
#define HW_GPU2D_TOTALWRITES_ADDR      (REGS_GPU2D_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALWRITES           (*(volatile hw_gpu2d_totalwrites_t *) HW_GPU2D_TOTALWRITES_ADDR)
#define HW_GPU2D_TOTALWRITES_RD()      (HW_GPU2D_TOTALWRITES.U)
#define HW_GPU2D_TOTALWRITES_WR(v)     (HW_GPU2D_TOTALWRITES.U = (v))
#define HW_GPU2D_TOTALWRITES_SET(v)    (HW_GPU2D_TOTALWRITES_WR(HW_GPU2D_TOTALWRITES_RD() |  (v)))
#define HW_GPU2D_TOTALWRITES_CLR(v)    (HW_GPU2D_TOTALWRITES_WR(HW_GPU2D_TOTALWRITES_RD() & ~(v)))
#define HW_GPU2D_TOTALWRITES_TOG(v)    (HW_GPU2D_TOTALWRITES_WR(HW_GPU2D_TOTALWRITES_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALWRITES bitfields
 */

/* --- Register HW_GPU2D_TOTALWRITES, field COUNT
 *

 */

#define BP_GPU2D_TOTALWRITES_COUNT      0
#define BM_GPU2D_TOTALWRITES_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALWRITES_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALWRITES_COUNT)
#else
#define BF_GPU2D_TOTALWRITES_COUNT(v)   (((v) << 0) & BM_GPU2D_TOTALWRITES_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALWRITES_COUNT(v)   BF_CS1(GPU2D_TOTALWRITES, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_CHIPSPECS - Chip Specification Register
 *
 * Specs for the chip. This register has no set reset value. It varies with
 * the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned VERTEX_OUTPUT_BUFFER_SIZE : 4; //!< Log2 of vertex output buffer size.
        unsigned NUM_PIXEL_PIPES : 3; //!< Number of pixel pipes.
        unsigned NUM_SHADER_CORES : 5; //!< Number of shader cores.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned VERTEX_CACHE_SIZE : 5; //!< Number of entries in the vertex shader cache.
        unsigned THREAD_COUNT : 4; //!< Log2 of thread count.
        unsigned TEMP_REGISTERS : 4; //!< Log2 of temporary registers.
        unsigned STREAMS : 4; //!< Number of vertex streams.
    } B;
} hw_gpu2d_chipspecs_t;
#endif

/*
 * constants & macros for entire GPU2D_CHIPSPECS register
 */
#define HW_GPU2D_CHIPSPECS_ADDR      (REGS_GPU2D_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_CHIPSPECS           (*(volatile hw_gpu2d_chipspecs_t *) HW_GPU2D_CHIPSPECS_ADDR)
#define HW_GPU2D_CHIPSPECS_RD()      (HW_GPU2D_CHIPSPECS.U)
#define HW_GPU2D_CHIPSPECS_WR(v)     (HW_GPU2D_CHIPSPECS.U = (v))
#define HW_GPU2D_CHIPSPECS_SET(v)    (HW_GPU2D_CHIPSPECS_WR(HW_GPU2D_CHIPSPECS_RD() |  (v)))
#define HW_GPU2D_CHIPSPECS_CLR(v)    (HW_GPU2D_CHIPSPECS_WR(HW_GPU2D_CHIPSPECS_RD() & ~(v)))
#define HW_GPU2D_CHIPSPECS_TOG(v)    (HW_GPU2D_CHIPSPECS_WR(HW_GPU2D_CHIPSPECS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_CHIPSPECS bitfields
 */

/* --- Register HW_GPU2D_CHIPSPECS, field VERTEX_OUTPUT_BUFFER_SIZE
 *
 * Log2 of vertex output buffer size.
 */

#define BP_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE      0
#define BM_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE(v)   ((((reg32_t) v) << 0) & BM_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE)
#else
#define BF_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE(v)   (((v) << 0) & BM_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE(v)   BF_CS1(GPU2D_CHIPSPECS, VERTEX_OUTPUT_BUFFER_SIZE, v)
#endif

/* --- Register HW_GPU2D_CHIPSPECS, field NUM_PIXEL_PIPES
 *
 * Number of pixel pipes.
 */

#define BP_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES      4
#define BM_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES(v)   ((((reg32_t) v) << 4) & BM_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES)
#else
#define BF_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES(v)   (((v) << 4) & BM_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES(v)   BF_CS1(GPU2D_CHIPSPECS, NUM_PIXEL_PIPES, v)
#endif

/* --- Register HW_GPU2D_CHIPSPECS, field NUM_SHADER_CORES
 *
 * Number of shader cores.
 */

#define BP_GPU2D_CHIPSPECS_NUM_SHADER_CORES      7
#define BM_GPU2D_CHIPSPECS_NUM_SHADER_CORES      0x00000f80

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPSPECS_NUM_SHADER_CORES(v)   ((((reg32_t) v) << 7) & BM_GPU2D_CHIPSPECS_NUM_SHADER_CORES)
#else
#define BF_GPU2D_CHIPSPECS_NUM_SHADER_CORES(v)   (((v) << 7) & BM_GPU2D_CHIPSPECS_NUM_SHADER_CORES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPSPECS_NUM_SHADER_CORES(v)   BF_CS1(GPU2D_CHIPSPECS, NUM_SHADER_CORES, v)
#endif

/* --- Register HW_GPU2D_CHIPSPECS, field VERTEX_CACHE_SIZE
 *
 * Number of entries in the vertex shader cache.
 */

#define BP_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE      15
#define BM_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE      0x000f8000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE(v)   ((((reg32_t) v) << 15) & BM_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE)
#else
#define BF_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE(v)   (((v) << 15) & BM_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE(v)   BF_CS1(GPU2D_CHIPSPECS, VERTEX_CACHE_SIZE, v)
#endif

/* --- Register HW_GPU2D_CHIPSPECS, field THREAD_COUNT
 *
 * Log2 of thread count.
 */

#define BP_GPU2D_CHIPSPECS_THREAD_COUNT      20
#define BM_GPU2D_CHIPSPECS_THREAD_COUNT      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPSPECS_THREAD_COUNT(v)   ((((reg32_t) v) << 20) & BM_GPU2D_CHIPSPECS_THREAD_COUNT)
#else
#define BF_GPU2D_CHIPSPECS_THREAD_COUNT(v)   (((v) << 20) & BM_GPU2D_CHIPSPECS_THREAD_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPSPECS_THREAD_COUNT(v)   BF_CS1(GPU2D_CHIPSPECS, THREAD_COUNT, v)
#endif

/* --- Register HW_GPU2D_CHIPSPECS, field TEMP_REGISTERS
 *
 * Log2 of temporary registers.
 */

#define BP_GPU2D_CHIPSPECS_TEMP_REGISTERS      24
#define BM_GPU2D_CHIPSPECS_TEMP_REGISTERS      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPSPECS_TEMP_REGISTERS(v)   ((((reg32_t) v) << 24) & BM_GPU2D_CHIPSPECS_TEMP_REGISTERS)
#else
#define BF_GPU2D_CHIPSPECS_TEMP_REGISTERS(v)   (((v) << 24) & BM_GPU2D_CHIPSPECS_TEMP_REGISTERS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPSPECS_TEMP_REGISTERS(v)   BF_CS1(GPU2D_CHIPSPECS, TEMP_REGISTERS, v)
#endif

/* --- Register HW_GPU2D_CHIPSPECS, field STREAMS
 *
 * Number of vertex streams.
 */

#define BP_GPU2D_CHIPSPECS_STREAMS      28
#define BM_GPU2D_CHIPSPECS_STREAMS      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPSPECS_STREAMS(v)   ((((reg32_t) v) << 28) & BM_GPU2D_CHIPSPECS_STREAMS)
#else
#define BF_GPU2D_CHIPSPECS_STREAMS(v)   (((v) << 28) & BM_GPU2D_CHIPSPECS_STREAMS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPSPECS_STREAMS(v)   BF_CS1(GPU2D_CHIPSPECS, STREAMS, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALWRITEBURSTS - Write Data Count Register
 *
 * Total write Data Count in terms of 64bits. This register has no reset
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
} hw_gpu2d_totalwritebursts_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALWRITEBURSTS register
 */
#define HW_GPU2D_TOTALWRITEBURSTS_ADDR      (REGS_GPU2D_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALWRITEBURSTS           (*(volatile hw_gpu2d_totalwritebursts_t *) HW_GPU2D_TOTALWRITEBURSTS_ADDR)
#define HW_GPU2D_TOTALWRITEBURSTS_RD()      (HW_GPU2D_TOTALWRITEBURSTS.U)
#define HW_GPU2D_TOTALWRITEBURSTS_WR(v)     (HW_GPU2D_TOTALWRITEBURSTS.U = (v))
#define HW_GPU2D_TOTALWRITEBURSTS_SET(v)    (HW_GPU2D_TOTALWRITEBURSTS_WR(HW_GPU2D_TOTALWRITEBURSTS_RD() |  (v)))
#define HW_GPU2D_TOTALWRITEBURSTS_CLR(v)    (HW_GPU2D_TOTALWRITEBURSTS_WR(HW_GPU2D_TOTALWRITEBURSTS_RD() & ~(v)))
#define HW_GPU2D_TOTALWRITEBURSTS_TOG(v)    (HW_GPU2D_TOTALWRITEBURSTS_WR(HW_GPU2D_TOTALWRITEBURSTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALWRITEBURSTS bitfields
 */

/* --- Register HW_GPU2D_TOTALWRITEBURSTS, field COUNT
 *

 */

#define BP_GPU2D_TOTALWRITEBURSTS_COUNT      0
#define BM_GPU2D_TOTALWRITEBURSTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALWRITEBURSTS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALWRITEBURSTS_COUNT)
#else
#define BF_GPU2D_TOTALWRITEBURSTS_COUNT(v)   (((v) << 0) & BM_GPU2D_TOTALWRITEBURSTS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALWRITEBURSTS_COUNT(v)   BF_CS1(GPU2D_TOTALWRITEBURSTS, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALWRITEREQS - Write REQ Count Register
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
} hw_gpu2d_totalwritereqs_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALWRITEREQS register
 */
#define HW_GPU2D_TOTALWRITEREQS_ADDR      (REGS_GPU2D_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALWRITEREQS           (*(volatile hw_gpu2d_totalwritereqs_t *) HW_GPU2D_TOTALWRITEREQS_ADDR)
#define HW_GPU2D_TOTALWRITEREQS_RD()      (HW_GPU2D_TOTALWRITEREQS.U)
#define HW_GPU2D_TOTALWRITEREQS_WR(v)     (HW_GPU2D_TOTALWRITEREQS.U = (v))
#define HW_GPU2D_TOTALWRITEREQS_SET(v)    (HW_GPU2D_TOTALWRITEREQS_WR(HW_GPU2D_TOTALWRITEREQS_RD() |  (v)))
#define HW_GPU2D_TOTALWRITEREQS_CLR(v)    (HW_GPU2D_TOTALWRITEREQS_WR(HW_GPU2D_TOTALWRITEREQS_RD() & ~(v)))
#define HW_GPU2D_TOTALWRITEREQS_TOG(v)    (HW_GPU2D_TOTALWRITEREQS_WR(HW_GPU2D_TOTALWRITEREQS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALWRITEREQS bitfields
 */

/* --- Register HW_GPU2D_TOTALWRITEREQS, field COUNT
 *

 */

#define BP_GPU2D_TOTALWRITEREQS_COUNT      0
#define BM_GPU2D_TOTALWRITEREQS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALWRITEREQS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALWRITEREQS_COUNT)
#else
#define BF_GPU2D_TOTALWRITEREQS_COUNT(v)   (((v) << 0) & BM_GPU2D_TOTALWRITEREQS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALWRITEREQS_COUNT(v)   BF_CS1(GPU2D_TOTALWRITEREQS, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALWRITELASTS - Total WLAST Count Register
 *
 * Total WLAST Count. This is used to match with GCTotalWriteReqs. This
 * register has no reset value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu2d_totalwritelasts_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALWRITELASTS register
 */
#define HW_GPU2D_TOTALWRITELASTS_ADDR      (REGS_GPU2D_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALWRITELASTS           (*(volatile hw_gpu2d_totalwritelasts_t *) HW_GPU2D_TOTALWRITELASTS_ADDR)
#define HW_GPU2D_TOTALWRITELASTS_RD()      (HW_GPU2D_TOTALWRITELASTS.U)
#define HW_GPU2D_TOTALWRITELASTS_WR(v)     (HW_GPU2D_TOTALWRITELASTS.U = (v))
#define HW_GPU2D_TOTALWRITELASTS_SET(v)    (HW_GPU2D_TOTALWRITELASTS_WR(HW_GPU2D_TOTALWRITELASTS_RD() |  (v)))
#define HW_GPU2D_TOTALWRITELASTS_CLR(v)    (HW_GPU2D_TOTALWRITELASTS_WR(HW_GPU2D_TOTALWRITELASTS_RD() & ~(v)))
#define HW_GPU2D_TOTALWRITELASTS_TOG(v)    (HW_GPU2D_TOTALWRITELASTS_WR(HW_GPU2D_TOTALWRITELASTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALWRITELASTS bitfields
 */

/* --- Register HW_GPU2D_TOTALWRITELASTS, field COUNT
 *

 */

#define BP_GPU2D_TOTALWRITELASTS_COUNT      0
#define BM_GPU2D_TOTALWRITELASTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALWRITELASTS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALWRITELASTS_COUNT)
#else
#define BF_GPU2D_TOTALWRITELASTS_COUNT(v)   (((v) << 0) & BM_GPU2D_TOTALWRITELASTS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALWRITELASTS_COUNT(v)   BF_CS1(GPU2D_TOTALWRITELASTS, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALREADBURSTS - Total Read Data Count Register
 *
 * Total Read Data Count in terms of 64bits. This register has no reset
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
} hw_gpu2d_totalreadbursts_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALREADBURSTS register
 */
#define HW_GPU2D_TOTALREADBURSTS_ADDR      (REGS_GPU2D_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALREADBURSTS           (*(volatile hw_gpu2d_totalreadbursts_t *) HW_GPU2D_TOTALREADBURSTS_ADDR)
#define HW_GPU2D_TOTALREADBURSTS_RD()      (HW_GPU2D_TOTALREADBURSTS.U)
#define HW_GPU2D_TOTALREADBURSTS_WR(v)     (HW_GPU2D_TOTALREADBURSTS.U = (v))
#define HW_GPU2D_TOTALREADBURSTS_SET(v)    (HW_GPU2D_TOTALREADBURSTS_WR(HW_GPU2D_TOTALREADBURSTS_RD() |  (v)))
#define HW_GPU2D_TOTALREADBURSTS_CLR(v)    (HW_GPU2D_TOTALREADBURSTS_WR(HW_GPU2D_TOTALREADBURSTS_RD() & ~(v)))
#define HW_GPU2D_TOTALREADBURSTS_TOG(v)    (HW_GPU2D_TOTALREADBURSTS_WR(HW_GPU2D_TOTALREADBURSTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALREADBURSTS bitfields
 */

/* --- Register HW_GPU2D_TOTALREADBURSTS, field COUNT
 *

 */

#define BP_GPU2D_TOTALREADBURSTS_COUNT      0
#define BM_GPU2D_TOTALREADBURSTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALREADBURSTS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALREADBURSTS_COUNT)
#else
#define BF_GPU2D_TOTALREADBURSTS_COUNT(v)   (((v) << 0) & BM_GPU2D_TOTALREADBURSTS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALREADBURSTS_COUNT(v)   BF_CS1(GPU2D_TOTALREADBURSTS, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALREADREQS - Total Read REQ Count Register
 *
 * Total Read Request Count. This register has no reset value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu2d_totalreadreqs_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALREADREQS register
 */
#define HW_GPU2D_TOTALREADREQS_ADDR      (REGS_GPU2D_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALREADREQS           (*(volatile hw_gpu2d_totalreadreqs_t *) HW_GPU2D_TOTALREADREQS_ADDR)
#define HW_GPU2D_TOTALREADREQS_RD()      (HW_GPU2D_TOTALREADREQS.U)
#define HW_GPU2D_TOTALREADREQS_WR(v)     (HW_GPU2D_TOTALREADREQS.U = (v))
#define HW_GPU2D_TOTALREADREQS_SET(v)    (HW_GPU2D_TOTALREADREQS_WR(HW_GPU2D_TOTALREADREQS_RD() |  (v)))
#define HW_GPU2D_TOTALREADREQS_CLR(v)    (HW_GPU2D_TOTALREADREQS_WR(HW_GPU2D_TOTALREADREQS_RD() & ~(v)))
#define HW_GPU2D_TOTALREADREQS_TOG(v)    (HW_GPU2D_TOTALREADREQS_WR(HW_GPU2D_TOTALREADREQS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALREADREQS bitfields
 */

/* --- Register HW_GPU2D_TOTALREADREQS, field COUNT
 *

 */

#define BP_GPU2D_TOTALREADREQS_COUNT      0
#define BM_GPU2D_TOTALREADREQS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALREADREQS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALREADREQS_COUNT)
#else
#define BF_GPU2D_TOTALREADREQS_COUNT(v)   (((v) << 0) & BM_GPU2D_TOTALREADREQS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALREADREQS_COUNT(v)   BF_CS1(GPU2D_TOTALREADREQS, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALREADLASTS - Total RLAST Count Register
 *
 * Total RLAST Count. This is used to match with GCTotalReadReqs. This
 * register has no reset value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu2d_totalreadlasts_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALREADLASTS register
 */
#define HW_GPU2D_TOTALREADLASTS_ADDR      (REGS_GPU2D_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALREADLASTS           (*(volatile hw_gpu2d_totalreadlasts_t *) HW_GPU2D_TOTALREADLASTS_ADDR)
#define HW_GPU2D_TOTALREADLASTS_RD()      (HW_GPU2D_TOTALREADLASTS.U)
#define HW_GPU2D_TOTALREADLASTS_WR(v)     (HW_GPU2D_TOTALREADLASTS.U = (v))
#define HW_GPU2D_TOTALREADLASTS_SET(v)    (HW_GPU2D_TOTALREADLASTS_WR(HW_GPU2D_TOTALREADLASTS_RD() |  (v)))
#define HW_GPU2D_TOTALREADLASTS_CLR(v)    (HW_GPU2D_TOTALREADLASTS_WR(HW_GPU2D_TOTALREADLASTS_RD() & ~(v)))
#define HW_GPU2D_TOTALREADLASTS_TOG(v)    (HW_GPU2D_TOTALREADLASTS_WR(HW_GPU2D_TOTALREADLASTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALREADLASTS bitfields
 */

/* --- Register HW_GPU2D_TOTALREADLASTS, field COUNT
 *

 */

#define BP_GPU2D_TOTALREADLASTS_COUNT      0
#define BM_GPU2D_TOTALREADLASTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALREADLASTS_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALREADLASTS_COUNT)
#else
#define BF_GPU2D_TOTALREADLASTS_COUNT(v)   (((v) << 0) & BM_GPU2D_TOTALREADLASTS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALREADLASTS_COUNT(v)   BF_CS1(GPU2D_TOTALREADLASTS, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_GPOUT0 - General Purpose Register 0
 *
 * General Purpose output register0. R/W but not connected to anywhere
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu2d_gpout0_t;
#endif

/*
 * constants & macros for entire GPU2D_GPOUT0 register
 */
#define HW_GPU2D_GPOUT0_ADDR      (REGS_GPU2D_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_GPOUT0           (*(volatile hw_gpu2d_gpout0_t *) HW_GPU2D_GPOUT0_ADDR)
#define HW_GPU2D_GPOUT0_RD()      (HW_GPU2D_GPOUT0.U)
#define HW_GPU2D_GPOUT0_WR(v)     (HW_GPU2D_GPOUT0.U = (v))
#define HW_GPU2D_GPOUT0_SET(v)    (HW_GPU2D_GPOUT0_WR(HW_GPU2D_GPOUT0_RD() |  (v)))
#define HW_GPU2D_GPOUT0_CLR(v)    (HW_GPU2D_GPOUT0_WR(HW_GPU2D_GPOUT0_RD() & ~(v)))
#define HW_GPU2D_GPOUT0_TOG(v)    (HW_GPU2D_GPOUT0_WR(HW_GPU2D_GPOUT0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_GPOUT0 bitfields
 */

/* --- Register HW_GPU2D_GPOUT0, field COUNT
 *

 */

#define BP_GPU2D_GPOUT0_COUNT      0
#define BM_GPU2D_GPOUT0_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_GPOUT0_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_GPOUT0_COUNT)
#else
#define BF_GPU2D_GPOUT0_COUNT(v)   (((v) << 0) & BM_GPU2D_GPOUT0_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_GPOUT0_COUNT(v)   BF_CS1(GPU2D_GPOUT0, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_GPOUT1 - General Purpose Register 1
 *
 * General Purpose output register1. R/W but not connected to anywhere
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu2d_gpout1_t;
#endif

/*
 * constants & macros for entire GPU2D_GPOUT1 register
 */
#define HW_GPU2D_GPOUT1_ADDR      (REGS_GPU2D_BASE + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_GPOUT1           (*(volatile hw_gpu2d_gpout1_t *) HW_GPU2D_GPOUT1_ADDR)
#define HW_GPU2D_GPOUT1_RD()      (HW_GPU2D_GPOUT1.U)
#define HW_GPU2D_GPOUT1_WR(v)     (HW_GPU2D_GPOUT1.U = (v))
#define HW_GPU2D_GPOUT1_SET(v)    (HW_GPU2D_GPOUT1_WR(HW_GPU2D_GPOUT1_RD() |  (v)))
#define HW_GPU2D_GPOUT1_CLR(v)    (HW_GPU2D_GPOUT1_WR(HW_GPU2D_GPOUT1_RD() & ~(v)))
#define HW_GPU2D_GPOUT1_TOG(v)    (HW_GPU2D_GPOUT1_WR(HW_GPU2D_GPOUT1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_GPOUT1 bitfields
 */

/* --- Register HW_GPU2D_GPOUT1, field COUNT
 *

 */

#define BP_GPU2D_GPOUT1_COUNT      0
#define BM_GPU2D_GPOUT1_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_GPOUT1_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_GPOUT1_COUNT)
#else
#define BF_GPU2D_GPOUT1_COUNT(v)   (((v) << 0) & BM_GPU2D_GPOUT1_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_GPOUT1_COUNT(v)   BF_CS1(GPU2D_GPOUT1, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_GPOUT2 - General Purpose Register 2
 *
 * General Purpose output register2. R/W but not connected to anywhere
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< 
    } B;
} hw_gpu2d_gpout2_t;
#endif

/*
 * constants & macros for entire GPU2D_GPOUT2 register
 */
#define HW_GPU2D_GPOUT2_ADDR      (REGS_GPU2D_BASE + 0x6c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_GPOUT2           (*(volatile hw_gpu2d_gpout2_t *) HW_GPU2D_GPOUT2_ADDR)
#define HW_GPU2D_GPOUT2_RD()      (HW_GPU2D_GPOUT2.U)
#define HW_GPU2D_GPOUT2_WR(v)     (HW_GPU2D_GPOUT2.U = (v))
#define HW_GPU2D_GPOUT2_SET(v)    (HW_GPU2D_GPOUT2_WR(HW_GPU2D_GPOUT2_RD() |  (v)))
#define HW_GPU2D_GPOUT2_CLR(v)    (HW_GPU2D_GPOUT2_WR(HW_GPU2D_GPOUT2_RD() & ~(v)))
#define HW_GPU2D_GPOUT2_TOG(v)    (HW_GPU2D_GPOUT2_WR(HW_GPU2D_GPOUT2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_GPOUT2 bitfields
 */

/* --- Register HW_GPU2D_GPOUT2, field COUNT
 *

 */

#define BP_GPU2D_GPOUT2_COUNT      0
#define BM_GPU2D_GPOUT2_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_GPOUT2_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPU2D_GPOUT2_COUNT)
#else
#define BF_GPU2D_GPOUT2_COUNT(v)   (((v) << 0) & BM_GPU2D_GPOUT2_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_GPOUT2_COUNT(v)   BF_CS1(GPU2D_GPOUT2, COUNT, v)
#endif

/*!
 * @brief HW_GPU2D_AXICONTROL - AXI Control Register
 *
 * Special Handling on AXI Bus
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_FULL_BURST_MODE : 32; //!< 
    } B;
} hw_gpu2d_axicontrol_t;
#endif

/*
 * constants & macros for entire GPU2D_AXICONTROL register
 */
#define HW_GPU2D_AXICONTROL_ADDR      (REGS_GPU2D_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_AXICONTROL           (*(volatile hw_gpu2d_axicontrol_t *) HW_GPU2D_AXICONTROL_ADDR)
#define HW_GPU2D_AXICONTROL_RD()      (HW_GPU2D_AXICONTROL.U)
#define HW_GPU2D_AXICONTROL_WR(v)     (HW_GPU2D_AXICONTROL.U = (v))
#define HW_GPU2D_AXICONTROL_SET(v)    (HW_GPU2D_AXICONTROL_WR(HW_GPU2D_AXICONTROL_RD() |  (v)))
#define HW_GPU2D_AXICONTROL_CLR(v)    (HW_GPU2D_AXICONTROL_WR(HW_GPU2D_AXICONTROL_RD() & ~(v)))
#define HW_GPU2D_AXICONTROL_TOG(v)    (HW_GPU2D_AXICONTROL_WR(HW_GPU2D_AXICONTROL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_AXICONTROL bitfields
 */

/* --- Register HW_GPU2D_AXICONTROL, field WR_FULL_BURST_MODE
 *

 */

#define BP_GPU2D_AXICONTROL_WR_FULL_BURST_MODE      0
#define BM_GPU2D_AXICONTROL_WR_FULL_BURST_MODE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AXICONTROL_WR_FULL_BURST_MODE(v)   ((((reg32_t) v) << 0) & BM_GPU2D_AXICONTROL_WR_FULL_BURST_MODE)
#else
#define BF_GPU2D_AXICONTROL_WR_FULL_BURST_MODE(v)   (((v) << 0) & BM_GPU2D_AXICONTROL_WR_FULL_BURST_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_AXICONTROL_WR_FULL_BURST_MODE(v)   BF_CS1(GPU2D_AXICONTROL, WR_FULL_BURST_MODE, v)
#endif

/*!
 * @brief HW_GPU2D_MINORFEATURES1 - Minor Features Register 1
 *
 * Shows which features are enabled in this chip. This register has no set
 * reset value. It varies with the implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 26; //!< Reserved
        unsigned TEXTURE_STRIDE : 1; //!< Texture has stride and memory addressing.
        unsigned BUG_FIXES2 : 1; //!< 
        unsigned BUG_FIXES1 : 1; //!< 
        unsigned VG_DOUBLE_BUFFER : 1; //!< Double buffering support for VG (second TS-->VG semaphore is present).
        unsigned V2_COMPRESSION : 1; //!< V2 compression.
        unsigned RSUV_SWIZZLE : 1; //!< Resolve UV swizzle.
    } B;
} hw_gpu2d_minorfeatures1_t;
#endif

/*
 * constants & macros for entire GPU2D_MINORFEATURES1 register
 */
#define HW_GPU2D_MINORFEATURES1_ADDR      (REGS_GPU2D_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_MINORFEATURES1           (*(volatile hw_gpu2d_minorfeatures1_t *) HW_GPU2D_MINORFEATURES1_ADDR)
#define HW_GPU2D_MINORFEATURES1_RD()      (HW_GPU2D_MINORFEATURES1.U)
#define HW_GPU2D_MINORFEATURES1_WR(v)     (HW_GPU2D_MINORFEATURES1.U = (v))
#define HW_GPU2D_MINORFEATURES1_SET(v)    (HW_GPU2D_MINORFEATURES1_WR(HW_GPU2D_MINORFEATURES1_RD() |  (v)))
#define HW_GPU2D_MINORFEATURES1_CLR(v)    (HW_GPU2D_MINORFEATURES1_WR(HW_GPU2D_MINORFEATURES1_RD() & ~(v)))
#define HW_GPU2D_MINORFEATURES1_TOG(v)    (HW_GPU2D_MINORFEATURES1_WR(HW_GPU2D_MINORFEATURES1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_MINORFEATURES1 bitfields
 */

/* --- Register HW_GPU2D_MINORFEATURES1, field TEXTURE_STRIDE
 *
 * Texture has stride and memory addressing.
 */

#define BP_GPU2D_MINORFEATURES1_TEXTURE_STRIDE      26
#define BM_GPU2D_MINORFEATURES1_TEXTURE_STRIDE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES1_TEXTURE_STRIDE(v)   ((((reg32_t) v) << 26) & BM_GPU2D_MINORFEATURES1_TEXTURE_STRIDE)
#else
#define BF_GPU2D_MINORFEATURES1_TEXTURE_STRIDE(v)   (((v) << 26) & BM_GPU2D_MINORFEATURES1_TEXTURE_STRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES1_TEXTURE_STRIDE(v)   BF_CS1(GPU2D_MINORFEATURES1, TEXTURE_STRIDE, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES1, field BUG_FIXES2
 *

 */

#define BP_GPU2D_MINORFEATURES1_BUG_FIXES2      27
#define BM_GPU2D_MINORFEATURES1_BUG_FIXES2      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES1_BUG_FIXES2(v)   ((((reg32_t) v) << 27) & BM_GPU2D_MINORFEATURES1_BUG_FIXES2)
#else
#define BF_GPU2D_MINORFEATURES1_BUG_FIXES2(v)   (((v) << 27) & BM_GPU2D_MINORFEATURES1_BUG_FIXES2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES1_BUG_FIXES2(v)   BF_CS1(GPU2D_MINORFEATURES1, BUG_FIXES2, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES1, field BUG_FIXES1
 *

 */

#define BP_GPU2D_MINORFEATURES1_BUG_FIXES1      28
#define BM_GPU2D_MINORFEATURES1_BUG_FIXES1      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES1_BUG_FIXES1(v)   ((((reg32_t) v) << 28) & BM_GPU2D_MINORFEATURES1_BUG_FIXES1)
#else
#define BF_GPU2D_MINORFEATURES1_BUG_FIXES1(v)   (((v) << 28) & BM_GPU2D_MINORFEATURES1_BUG_FIXES1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES1_BUG_FIXES1(v)   BF_CS1(GPU2D_MINORFEATURES1, BUG_FIXES1, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES1, field VG_DOUBLE_BUFFER
 *
 * Double buffering support for VG (second TS-->VG semaphore is
 * present).
 */

#define BP_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER      29
#define BM_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER(v)   ((((reg32_t) v) << 29) & BM_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER)
#else
#define BF_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER(v)   (((v) << 29) & BM_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER(v)   BF_CS1(GPU2D_MINORFEATURES1, VG_DOUBLE_BUFFER, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES1, field V2_COMPRESSION
 *
 * V2 compression.
 */

#define BP_GPU2D_MINORFEATURES1_V2_COMPRESSION      30
#define BM_GPU2D_MINORFEATURES1_V2_COMPRESSION      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES1_V2_COMPRESSION(v)   ((((reg32_t) v) << 30) & BM_GPU2D_MINORFEATURES1_V2_COMPRESSION)
#else
#define BF_GPU2D_MINORFEATURES1_V2_COMPRESSION(v)   (((v) << 30) & BM_GPU2D_MINORFEATURES1_V2_COMPRESSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES1_V2_COMPRESSION(v)   BF_CS1(GPU2D_MINORFEATURES1, V2_COMPRESSION, v)
#endif

/* --- Register HW_GPU2D_MINORFEATURES1, field RSUV_SWIZZLE
 *
 * Resolve UV swizzle.
 */

#define BP_GPU2D_MINORFEATURES1_RSUV_SWIZZLE      31
#define BM_GPU2D_MINORFEATURES1_RSUV_SWIZZLE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MINORFEATURES1_RSUV_SWIZZLE(v)   ((((reg32_t) v) << 31) & BM_GPU2D_MINORFEATURES1_RSUV_SWIZZLE)
#else
#define BF_GPU2D_MINORFEATURES1_RSUV_SWIZZLE(v)   (((v) << 31) & BM_GPU2D_MINORFEATURES1_RSUV_SWIZZLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MINORFEATURES1_RSUV_SWIZZLE(v)   BF_CS1(GPU2D_MINORFEATURES1, RSUV_SWIZZLE, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALCYCLES - Total Cycle Counter Register
 *
 * Total cycles. This register is a free running counter. It can be reset by
 * writing 0 to it.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CYCLES : 32; //!< 
    } B;
} hw_gpu2d_totalcycles_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALCYCLES register
 */
#define HW_GPU2D_TOTALCYCLES_ADDR      (REGS_GPU2D_BASE + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALCYCLES           (*(volatile hw_gpu2d_totalcycles_t *) HW_GPU2D_TOTALCYCLES_ADDR)
#define HW_GPU2D_TOTALCYCLES_RD()      (HW_GPU2D_TOTALCYCLES.U)
#define HW_GPU2D_TOTALCYCLES_WR(v)     (HW_GPU2D_TOTALCYCLES.U = (v))
#define HW_GPU2D_TOTALCYCLES_SET(v)    (HW_GPU2D_TOTALCYCLES_WR(HW_GPU2D_TOTALCYCLES_RD() |  (v)))
#define HW_GPU2D_TOTALCYCLES_CLR(v)    (HW_GPU2D_TOTALCYCLES_WR(HW_GPU2D_TOTALCYCLES_RD() & ~(v)))
#define HW_GPU2D_TOTALCYCLES_TOG(v)    (HW_GPU2D_TOTALCYCLES_WR(HW_GPU2D_TOTALCYCLES_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALCYCLES bitfields
 */

/* --- Register HW_GPU2D_TOTALCYCLES, field CYCLES
 *

 */

#define BP_GPU2D_TOTALCYCLES_CYCLES      0
#define BM_GPU2D_TOTALCYCLES_CYCLES      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALCYCLES_CYCLES(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALCYCLES_CYCLES)
#else
#define BF_GPU2D_TOTALCYCLES_CYCLES(v)   (((v) << 0) & BM_GPU2D_TOTALCYCLES_CYCLES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALCYCLES_CYCLES(v)   BF_CS1(GPU2D_TOTALCYCLES, CYCLES, v)
#endif

/*!
 * @brief HW_GPU2D_TOTALIDLECYLES - Total Idle Cycle Register
 *
 * Total cycles where the GPU is idle. It is reset when gcTotalCycles
 * register is written to. It looks at all the blocks but FE when
 * determining the IP is idle.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CYCLES : 32; //!< 
    } B;
} hw_gpu2d_totalidlecyles_t;
#endif

/*
 * constants & macros for entire GPU2D_TOTALIDLECYLES register
 */
#define HW_GPU2D_TOTALIDLECYLES_ADDR      (REGS_GPU2D_BASE + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_TOTALIDLECYLES           (*(volatile hw_gpu2d_totalidlecyles_t *) HW_GPU2D_TOTALIDLECYLES_ADDR)
#define HW_GPU2D_TOTALIDLECYLES_RD()      (HW_GPU2D_TOTALIDLECYLES.U)
#define HW_GPU2D_TOTALIDLECYLES_WR(v)     (HW_GPU2D_TOTALIDLECYLES.U = (v))
#define HW_GPU2D_TOTALIDLECYLES_SET(v)    (HW_GPU2D_TOTALIDLECYLES_WR(HW_GPU2D_TOTALIDLECYLES_RD() |  (v)))
#define HW_GPU2D_TOTALIDLECYLES_CLR(v)    (HW_GPU2D_TOTALIDLECYLES_WR(HW_GPU2D_TOTALIDLECYLES_RD() & ~(v)))
#define HW_GPU2D_TOTALIDLECYLES_TOG(v)    (HW_GPU2D_TOTALIDLECYLES_WR(HW_GPU2D_TOTALIDLECYLES_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_TOTALIDLECYLES bitfields
 */

/* --- Register HW_GPU2D_TOTALIDLECYLES, field CYCLES
 *

 */

#define BP_GPU2D_TOTALIDLECYLES_CYCLES      0
#define BM_GPU2D_TOTALIDLECYLES_CYCLES      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_TOTALIDLECYLES_CYCLES(v)   ((((reg32_t) v) << 0) & BM_GPU2D_TOTALIDLECYLES_CYCLES)
#else
#define BF_GPU2D_TOTALIDLECYLES_CYCLES(v)   (((v) << 0) & BM_GPU2D_TOTALIDLECYLES_CYCLES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_TOTALIDLECYLES_CYCLES(v)   BF_CS1(GPU2D_TOTALIDLECYLES, CYCLES, v)
#endif

/*!
 * @brief HW_GPU2D_CHIPSPECS2 - Chip Specification Register
 *
 * Set address to 0x020 from 1G per Joseph                             Hernanzez  Specs for the
 * chip. This register has no reset value. It varies with the
 * implementation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CYCLES : 32; //!< 
    } B;
} hw_gpu2d_chipspecs2_t;
#endif

/*
 * constants & macros for entire GPU2D_CHIPSPECS2 register
 */
#define HW_GPU2D_CHIPSPECS2_ADDR      (REGS_GPU2D_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_CHIPSPECS2           (*(volatile hw_gpu2d_chipspecs2_t *) HW_GPU2D_CHIPSPECS2_ADDR)
#define HW_GPU2D_CHIPSPECS2_RD()      (HW_GPU2D_CHIPSPECS2.U)
#define HW_GPU2D_CHIPSPECS2_WR(v)     (HW_GPU2D_CHIPSPECS2.U = (v))
#define HW_GPU2D_CHIPSPECS2_SET(v)    (HW_GPU2D_CHIPSPECS2_WR(HW_GPU2D_CHIPSPECS2_RD() |  (v)))
#define HW_GPU2D_CHIPSPECS2_CLR(v)    (HW_GPU2D_CHIPSPECS2_WR(HW_GPU2D_CHIPSPECS2_RD() & ~(v)))
#define HW_GPU2D_CHIPSPECS2_TOG(v)    (HW_GPU2D_CHIPSPECS2_WR(HW_GPU2D_CHIPSPECS2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_CHIPSPECS2 bitfields
 */

/* --- Register HW_GPU2D_CHIPSPECS2, field CYCLES
 *

 */

#define BP_GPU2D_CHIPSPECS2_CYCLES      0
#define BM_GPU2D_CHIPSPECS2_CYCLES      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_CHIPSPECS2_CYCLES(v)   ((((reg32_t) v) << 0) & BM_GPU2D_CHIPSPECS2_CYCLES)
#else
#define BF_GPU2D_CHIPSPECS2_CYCLES(v)   (((v) << 0) & BM_GPU2D_CHIPSPECS2_CYCLES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_CHIPSPECS2_CYCLES(v)   BF_CS1(GPU2D_CHIPSPECS2, CYCLES, v)
#endif

/*!
 * @brief HW_GPU2D_MODULEPOWERCONTROLS - Power Control Register
 *
 * The Power Management register set has just a few registers for
 * controlling clock gating within the core. GC400 allows the user to
 * control the clock gating of each internal module independently of the
 * other modules. Users can access all of these registers via the AHB
 * Bus.  Control register for module level power controls.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TURN_OFF_COUNTER : 16; //!< Counter value for clock gating the module if the module is idle for this amount of clock cycles.
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned TURN_ON_COUNTER : 4; //!< Number of clock cycles to wait after turning on the clock.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned DISABLE_STARVE_MODULE_CLOCK_GATING : 1; //!< Disables module level clock gating for starve/idle condition.
        unsigned DISABLE_STALL_MODULE_CLOCK_GATING : 1; //!< Disables module level clock gating for stall condition.
        unsigned ENABLE_MODULE_CLOCK_GATING : 1; //!< Enables module level clock gating.
    } B;
} hw_gpu2d_modulepowercontrols_t;
#endif

/*
 * constants & macros for entire GPU2D_MODULEPOWERCONTROLS register
 */
#define HW_GPU2D_MODULEPOWERCONTROLS_ADDR      (REGS_GPU2D_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_MODULEPOWERCONTROLS           (*(volatile hw_gpu2d_modulepowercontrols_t *) HW_GPU2D_MODULEPOWERCONTROLS_ADDR)
#define HW_GPU2D_MODULEPOWERCONTROLS_RD()      (HW_GPU2D_MODULEPOWERCONTROLS.U)
#define HW_GPU2D_MODULEPOWERCONTROLS_WR(v)     (HW_GPU2D_MODULEPOWERCONTROLS.U = (v))
#define HW_GPU2D_MODULEPOWERCONTROLS_SET(v)    (HW_GPU2D_MODULEPOWERCONTROLS_WR(HW_GPU2D_MODULEPOWERCONTROLS_RD() |  (v)))
#define HW_GPU2D_MODULEPOWERCONTROLS_CLR(v)    (HW_GPU2D_MODULEPOWERCONTROLS_WR(HW_GPU2D_MODULEPOWERCONTROLS_RD() & ~(v)))
#define HW_GPU2D_MODULEPOWERCONTROLS_TOG(v)    (HW_GPU2D_MODULEPOWERCONTROLS_WR(HW_GPU2D_MODULEPOWERCONTROLS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_MODULEPOWERCONTROLS bitfields
 */

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field TURN_OFF_COUNTER
 *
 * Counter value for clock gating the module if the module is idle for
 * this amount of clock cycles.
 */

#define BP_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER      0
#define BM_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER(v)   ((((reg32_t) v) << 0) & BM_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER)
#else
#define BF_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER(v)   (((v) << 0) & BM_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, TURN_OFF_COUNTER, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field TURN_ON_COUNTER
 *
 * Number of clock cycles to wait after turning on the clock.
 */

#define BP_GPU2D_MODULEPOWERCONTROLS_TURN_ON_COUNTER      24
#define BM_GPU2D_MODULEPOWERCONTROLS_TURN_ON_COUNTER      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERCONTROLS_TURN_ON_COUNTER(v)   ((((reg32_t) v) << 24) & BM_GPU2D_MODULEPOWERCONTROLS_TURN_ON_COUNTER)
#else
#define BF_GPU2D_MODULEPOWERCONTROLS_TURN_ON_COUNTER(v)   (((v) << 24) & BM_GPU2D_MODULEPOWERCONTROLS_TURN_ON_COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERCONTROLS_TURN_ON_COUNTER(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, TURN_ON_COUNTER, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field DISABLE_STARVE_MODULE_CLOCK_GATING
 *
 * Disables module level clock gating for starve/idle condition.
 */

#define BP_GPU2D_MODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING      29
#define BM_GPU2D_MODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING(v)   ((((reg32_t) v) << 29) & BM_GPU2D_MODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING)
#else
#define BF_GPU2D_MODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING(v)   (((v) << 29) & BM_GPU2D_MODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, DISABLE_STARVE_MODULE_CLOCK_GATING, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field DISABLE_STALL_MODULE_CLOCK_GATING
 *
 * Disables module level clock gating for stall condition.
 */

#define BP_GPU2D_MODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING      30
#define BM_GPU2D_MODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING(v)   ((((reg32_t) v) << 30) & BM_GPU2D_MODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING)
#else
#define BF_GPU2D_MODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING(v)   (((v) << 30) & BM_GPU2D_MODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, DISABLE_STALL_MODULE_CLOCK_GATING, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field ENABLE_MODULE_CLOCK_GATING
 *
 * Enables module level clock gating.
 */

#define BP_GPU2D_MODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING      31
#define BM_GPU2D_MODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING(v)   ((((reg32_t) v) << 31) & BM_GPU2D_MODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING)
#else
#define BF_GPU2D_MODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING(v)   (((v) << 31) & BM_GPU2D_MODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, ENABLE_MODULE_CLOCK_GATING, v)
#endif

/*!
 * @brief HW_GPU2D_MODULEPOWERMODULECONTROL - Power Level Register
 *
 * Module level control registers.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20; //!< Reserved
        unsigned DISABLE_MODULE_CLOCK_GATING_TS : 1; //!< Disables module level clock gating for TS.
        unsigned DISABLE_MODULE_CLOCK_GATING_FP : 1; //!< Disables module level clock gating for FP.
        unsigned DISABLE_MODULE_CLOCK_GATING_IM : 1; //!< Disables module level clock gating for IM.
        unsigned DISABLE_MODULE_CLOCK_GATING_VG : 1; //!< Disables module level clock gating for VG.
        unsigned DISABLE_MODULE_CLOCK_GATING_TX : 1; //!< Disables module level clock gating for TX.
        unsigned DISABLE_MODULE_CLOCK_GATING_RA : 1; //!< Disables module level clock gating for RA.
        unsigned DISABLE_MODULE_CLOCK_GATING_SE : 1; //!< Disables module level clock gating for SE.
        unsigned DISABLE_MODULE_CLOCK_GATING_PA : 1; //!< Disables module level clock gating for PA.
        unsigned DISABLE_MODULE_CLOCK_GATING_SH : 1; //!< Disables module level clock gating for SH.
        unsigned DISABLE_MODULE_CLOCK_GATING_PE : 1; //!< Disables module level clock gating for PE.
        unsigned DISABLE_MODULE_CLOCK_GATING_DE : 1; //!< Disables module level clock gating for DE.
        unsigned DISABLE_MODULE_CLOCK_GATING_FE : 1; //!< Disables module level clock gating for FE.
    } B;
} hw_gpu2d_modulepowermodulecontrol_t;
#endif

/*
 * constants & macros for entire GPU2D_MODULEPOWERMODULECONTROL register
 */
#define HW_GPU2D_MODULEPOWERMODULECONTROL_ADDR      (REGS_GPU2D_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_MODULEPOWERMODULECONTROL           (*(volatile hw_gpu2d_modulepowermodulecontrol_t *) HW_GPU2D_MODULEPOWERMODULECONTROL_ADDR)
#define HW_GPU2D_MODULEPOWERMODULECONTROL_RD()      (HW_GPU2D_MODULEPOWERMODULECONTROL.U)
#define HW_GPU2D_MODULEPOWERMODULECONTROL_WR(v)     (HW_GPU2D_MODULEPOWERMODULECONTROL.U = (v))
#define HW_GPU2D_MODULEPOWERMODULECONTROL_SET(v)    (HW_GPU2D_MODULEPOWERMODULECONTROL_WR(HW_GPU2D_MODULEPOWERMODULECONTROL_RD() |  (v)))
#define HW_GPU2D_MODULEPOWERMODULECONTROL_CLR(v)    (HW_GPU2D_MODULEPOWERMODULECONTROL_WR(HW_GPU2D_MODULEPOWERMODULECONTROL_RD() & ~(v)))
#define HW_GPU2D_MODULEPOWERMODULECONTROL_TOG(v)    (HW_GPU2D_MODULEPOWERMODULECONTROL_WR(HW_GPU2D_MODULEPOWERMODULECONTROL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_MODULEPOWERMODULECONTROL bitfields
 */

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_TS
 *
 * Disables module level clock gating for TS.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS      20
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS(v)   ((((reg32_t) v) << 20) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS(v)   (((v) << 20) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_TS, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_FP
 *
 * Disables module level clock gating for FP.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FP      21
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FP(v)   ((((reg32_t) v) << 21) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FP)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FP(v)   (((v) << 21) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FP(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_FP, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_IM
 *
 * Disables module level clock gating for IM.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM      22
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM(v)   ((((reg32_t) v) << 22) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM(v)   (((v) << 22) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_IM, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_VG
 *
 * Disables module level clock gating for VG.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG      23
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG(v)   ((((reg32_t) v) << 23) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG(v)   (((v) << 23) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_VG, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_TX
 *
 * Disables module level clock gating for TX.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX      24
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX(v)   ((((reg32_t) v) << 24) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX(v)   (((v) << 24) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_TX, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_RA
 *
 * Disables module level clock gating for RA.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA      25
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA(v)   ((((reg32_t) v) << 25) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA(v)   (((v) << 25) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_RA, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_SE
 *
 * Disables module level clock gating for SE.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE      26
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE(v)   ((((reg32_t) v) << 26) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE(v)   (((v) << 26) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_SE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_PA
 *
 * Disables module level clock gating for PA.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA      27
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA(v)   ((((reg32_t) v) << 27) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA(v)   (((v) << 27) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_PA, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_SH
 *
 * Disables module level clock gating for SH.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH      28
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH(v)   ((((reg32_t) v) << 28) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH(v)   (((v) << 28) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_SH, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_PE
 *
 * Disables module level clock gating for PE.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE      29
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE(v)   ((((reg32_t) v) << 29) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE(v)   (((v) << 29) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_PE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_DE
 *
 * Disables module level clock gating for DE.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE      30
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE(v)   ((((reg32_t) v) << 30) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE(v)   (((v) << 30) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_DE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_FE
 *
 * Disables module level clock gating for FE.
 */

#define BP_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE      31
#define BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE(v)   ((((reg32_t) v) << 31) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE)
#else
#define BF_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE(v)   (((v) << 31) & BM_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_FE, v)
#endif

/*!
 * @brief HW_GPU2D_MODULEPOWERMODULESTATUS - Power Status Register
 *
 * Module level control status.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20; //!< Reserved
        unsigned MODULE_CLOCK_GATED_TS : 1; //!< Module level clock gating is ON for TS.
        unsigned MODULE_CLOCK_GATED_FP : 1; //!< Module level clock gating is ON for FP.
        unsigned MODULE_CLOCK_GATED_IM : 1; //!< Module level clock gating is ON for IM.
        unsigned MODULE_CLOCK_GATED_VG : 1; //!< Module level clock gating is ON for VG.
        unsigned MODULE_CLOCK_GATED_TX : 1; //!< Module level clock gating is ON for TX.
        unsigned MODULE_CLOCK_GATED_RA : 1; //!< Module level clock gating is ON for RA.
        unsigned MODULE_CLOCK_GATED_SE : 1; //!< Module level clock gating is ON for SE.
        unsigned MODULE_CLOCK_GATED_PA : 1; //!< Module level clock gating is ON for PA.
        unsigned MODULE_CLOCK_GATED_SH : 1; //!< Module level clock gating is ON for SH.
        unsigned MODULE_CLOCK_GATED_PE : 1; //!< Module level clock gating is ON for PE.
        unsigned MODULE_CLOCK_GATED_DE : 1; //!< Module level clock gating is ON for DE.
        unsigned MODULE_CLOCK_GATED_FE : 1; //!< Module level clock gating is ON for FE.
    } B;
} hw_gpu2d_modulepowermodulestatus_t;
#endif

/*
 * constants & macros for entire GPU2D_MODULEPOWERMODULESTATUS register
 */
#define HW_GPU2D_MODULEPOWERMODULESTATUS_ADDR      (REGS_GPU2D_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_GPU2D_MODULEPOWERMODULESTATUS           (*(volatile hw_gpu2d_modulepowermodulestatus_t *) HW_GPU2D_MODULEPOWERMODULESTATUS_ADDR)
#define HW_GPU2D_MODULEPOWERMODULESTATUS_RD()      (HW_GPU2D_MODULEPOWERMODULESTATUS.U)
#define HW_GPU2D_MODULEPOWERMODULESTATUS_WR(v)     (HW_GPU2D_MODULEPOWERMODULESTATUS.U = (v))
#define HW_GPU2D_MODULEPOWERMODULESTATUS_SET(v)    (HW_GPU2D_MODULEPOWERMODULESTATUS_WR(HW_GPU2D_MODULEPOWERMODULESTATUS_RD() |  (v)))
#define HW_GPU2D_MODULEPOWERMODULESTATUS_CLR(v)    (HW_GPU2D_MODULEPOWERMODULESTATUS_WR(HW_GPU2D_MODULEPOWERMODULESTATUS_RD() & ~(v)))
#define HW_GPU2D_MODULEPOWERMODULESTATUS_TOG(v)    (HW_GPU2D_MODULEPOWERMODULESTATUS_WR(HW_GPU2D_MODULEPOWERMODULESTATUS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPU2D_MODULEPOWERMODULESTATUS bitfields
 */

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_TS
 *
 * Module level clock gating is ON for TS.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS      20
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS(v)   ((((reg32_t) v) << 20) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS(v)   (((v) << 20) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_TS, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_FP
 *
 * Module level clock gating is ON for FP.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP      21
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP(v)   ((((reg32_t) v) << 21) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP(v)   (((v) << 21) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_FP, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_IM
 *
 * Module level clock gating is ON for IM.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM      22
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM(v)   ((((reg32_t) v) << 22) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM(v)   (((v) << 22) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_IM, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_VG
 *
 * Module level clock gating is ON for VG.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG      23
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG(v)   ((((reg32_t) v) << 23) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG(v)   (((v) << 23) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_VG, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_TX
 *
 * Module level clock gating is ON for TX.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX      24
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX(v)   ((((reg32_t) v) << 24) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX(v)   (((v) << 24) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_TX, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_RA
 *
 * Module level clock gating is ON for RA.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA      25
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA(v)   ((((reg32_t) v) << 25) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA(v)   (((v) << 25) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_RA, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_SE
 *
 * Module level clock gating is ON for SE.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE      26
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE(v)   ((((reg32_t) v) << 26) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE(v)   (((v) << 26) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_SE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_PA
 *
 * Module level clock gating is ON for PA.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA      27
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA(v)   ((((reg32_t) v) << 27) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA(v)   (((v) << 27) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_PA, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_SH
 *
 * Module level clock gating is ON for SH.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH      28
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH(v)   ((((reg32_t) v) << 28) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH(v)   (((v) << 28) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_SH, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_PE
 *
 * Module level clock gating is ON for PE.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE      29
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE(v)   ((((reg32_t) v) << 29) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE(v)   (((v) << 29) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_PE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_DE
 *
 * Module level clock gating is ON for DE.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE      30
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE(v)   ((((reg32_t) v) << 30) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE(v)   (((v) << 30) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_DE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_FE
 *
 * Module level clock gating is ON for FE.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE      31
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE(v)   ((((reg32_t) v) << 31) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE)
#else
#define BF_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE(v)   (((v) << 31) & BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE(v)   BF_CS1(GPU2D_MODULEPOWERMODULESTATUS, MODULE_CLOCK_GATED_FE, v)
#endif



/*!
 * @brief All GPU2D module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_gpu2d_aqhiclockcontrol_t AQHICLOCKCONTROL; //!< Clock Control Register
    volatile hw_gpu2d_aqhiidle_t AQHIIDLE; //!< Idle Status Register
    volatile hw_gpu2d_aqaxiconfig_t AQAXICONFIG; //!< AXI Configuration Register
    volatile hw_gpu2d_aqaxistatus_t AQAXISTATUS; //!< AXI Status Register
    volatile hw_gpu2d_aqintracknowledge_t AQINTRACKNOWLEDGE; //!< Interrupt Acknowledge Register
    volatile hw_gpu2d_aqintrenbl_t AQINTRENBL; //!< Interrupt Enable Register
    volatile hw_gpu2d_aqident_t AQIDENT; //!< Identification Register
    volatile hw_gpu2d_features_t FEATURES; //!< Features Register
    volatile hw_gpu2d_chipid_t CHIPID; //!< Chip Identification Register
    volatile hw_gpu2d_chiprev_t CHIPREV; //!< Chip Revision Register
    volatile hw_gpu2d_chipdate_t CHIPDATE; //!< Chip Release Date Register
    volatile hw_gpu2d_chiptime_t CHIPTIME; //!< Chip Release Time Register
    volatile hw_gpu2d_chipcustomer_t CHIPCUSTOMER; //!< Chip Customer Register
    volatile hw_gpu2d_minorfeatures0_t MINORFEATURES0; //!< Minor Features Register 0
    volatile hw_gpu2d_cachecontrol_t CACHECONTROL; //!< Cache Control Register
    volatile hw_gpu2d_resetmemcounters_t RESETMEMCOUNTERS; //!< Reset Mem Counters Register
    volatile hw_gpu2d_totalreads_t TOTALREADS; //!< Read Count Register
    volatile hw_gpu2d_totalwrites_t TOTALWRITES; //!< Write Count Register
    volatile hw_gpu2d_chipspecs_t CHIPSPECS; //!< Chip Specification Register
    volatile hw_gpu2d_totalwritebursts_t TOTALWRITEBURSTS; //!< Write Data Count Register
    volatile hw_gpu2d_totalwritereqs_t TOTALWRITEREQS; //!< Write REQ Count Register
    volatile hw_gpu2d_totalwritelasts_t TOTALWRITELASTS; //!< Total WLAST Count Register
    volatile hw_gpu2d_totalreadbursts_t TOTALREADBURSTS; //!< Total Read Data Count Register
    volatile hw_gpu2d_totalreadreqs_t TOTALREADREQS; //!< Total Read REQ Count Register
    volatile hw_gpu2d_totalreadlasts_t TOTALREADLASTS; //!< Total RLAST Count Register
    volatile hw_gpu2d_gpout0_t GPOUT0; //!< General Purpose Register 0
    volatile hw_gpu2d_gpout1_t GPOUT1; //!< General Purpose Register 1
    volatile hw_gpu2d_gpout2_t GPOUT2; //!< General Purpose Register 2
    volatile hw_gpu2d_axicontrol_t AXICONTROL; //!< AXI Control Register
    volatile hw_gpu2d_minorfeatures1_t MINORFEATURES1; //!< Minor Features Register 1
    volatile hw_gpu2d_totalcycles_t TOTALCYCLES; //!< Total Cycle Counter Register
    volatile hw_gpu2d_totalidlecyles_t TOTALIDLECYLES; //!< Total Idle Cycle Register
    volatile hw_gpu2d_chipspecs2_t CHIPSPECS2; //!< Chip Specification Register
    volatile hw_gpu2d_modulepowercontrols_t MODULEPOWERCONTROLS; //!< Power Control Register
    volatile hw_gpu2d_modulepowermodulecontrol_t MODULEPOWERMODULECONTROL; //!< Power Level Register
    volatile hw_gpu2d_modulepowermodulestatus_t MODULEPOWERMODULESTATUS; //!< Power Status Register
} hw_gpu2d_t
#endif

//! @brief Macro to access all GPU2D registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_GPU2D(0)</code>.
#define HW_GPU2D     (*(volatile hw_gpu2d_t *) REGS_GPU2D_BASE)


#endif // _GPU2D_H
