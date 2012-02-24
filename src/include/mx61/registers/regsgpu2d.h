/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _GPU2D_H
#define _GPU2D_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_GPU2D_AQHICLOCKCONTROL - Clock Control Register
 * - HW_GPU2D_AQHIIDLE - Idle Status Register
 * - HW_GPU2D_AQAXICONFIG - AXI Configuration Register
 * - HW_GPU2D_AQAXISTATUS - AXI Status Register
 * - HW_GPU2D_AQINTRACKNOWLEDGE - Interrupt Acknowledge Register
 * - HW_GPU2D_AQINTRENBL - Interrupt Enable Register
 * - HW_GPU2D_AQIDENT - Identification Register
 * - HW_GPU2D_FEATURES - Features Register
 * - HW_GPU2D_CHIPID - Chip Identification Register
 * - HW_GPU2D_CHIPREV - Chip Revision Register
 * - HW_GPU2D_CHIPDATE - Chip Release Date Register
 * - HW_GPU2D_CHIPTIME - Chip Release Time Register
 * - HW_GPU2D_CHIPCUSTOMER - Chip Customer Register
 * - HW_GPU2D_MINORFEATURES0 - Minor Features Register 0
 * - HW_GPU2D_CACHECONTROL - Cache Control Register
 * - HW_GPU2D_RESETMEMCOUNTERS - Reset Mem Counters Register
 * - HW_GPU2D_TOTALREADS - Read Count Register
 * - HW_GPU2D_TOTALWRITES - Write Count Register
 * - HW_GPU2D_CHIPSPECS - Chip Specification Register
 * - HW_GPU2D_TOTALWRITEBURSTS - Write Data Count Register
 * - HW_GPU2D_TOTALWRITEREQS - Write REQ Count Register
 * - HW_GPU2D_TOTALWRITELASTS - Total WLAST Count Register
 * - HW_GPU2D_TOTALREADBURSTS - Total Read Data Count Register
 * - HW_GPU2D_TOTALREADREQS - Total Read REQ Count Register
 * - HW_GPU2D_TOTALREADLASTS - Total RLAST Count Register
 * - HW_GPU2D_GPOUT0 - General Purpose Register 0
 * - HW_GPU2D_GPOUT1 - General Purpose Register 1
 * - HW_GPU2D_GPOUT2 - General Purpose Register 2
 * - HW_GPU2D_AXICONTROL - AXI Control Register
 * - HW_GPU2D_MINORFEATURES1 - Minor Features Register 1
 * - HW_GPU2D_TOTALCYCLES - Total Cycle Counter Register
 * - HW_GPU2D_TOTALIDLECYLES - Total Idle Cycle Register
 * - HW_GPU2D_CHIPSPECS2 - Chip Specification Register
 * - HW_GPU2D_MODULEPOWERCONTROLS - Power Control Register
 * - HW_GPU2D_MODULEPOWERMODULECONTROL - Power Level Register
 * - HW_GPU2D_MODULEPOWERMODULESTATUS - Power Status Register
 *
 * hw_gpu2d_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_GPU2D_BASE
#define REGS_GPU2D_BASE (0x00134000) //!< Base address for GPU2D.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_AQHICLOCKCONTROL - Clock Control Register (RW)
 *

 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field MULTI_PIPE_USE_SINGLE_AXI (RW)
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
//! @brief Set the MULTI_PIPE_USE_SINGLE_AXI field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, MULTI_PIPE_USE_SINGLE_AXI, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field MULTI_PIPE_REG_SELECT (RW)
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
//! @brief Set the MULTI_PIPE_REG_SELECT field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, MULTI_PIPE_REG_SELECT, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field ISOLATE_GPU (RW)
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
//! @brief Set the ISOLATE_GPU field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_ISOLATE_GPU(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, ISOLATE_GPU, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field IDLE_VG (RW)
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
//! @brief Set the IDLE_VG field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_IDLE_VG(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, IDLE_VG, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field IDLE2_D (RW)
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
//! @brief Set the IDLE2_D field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_IDLE2_D(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, IDLE2_D, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field IDLE3_D (RW)
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
//! @brief Set the IDLE3_D field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_IDLE3_D(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, IDLE3_D, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field SOFT_RESET (RW)
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
//! @brief Set the SOFT_RESET field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_SOFT_RESET(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, SOFT_RESET, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field DISABLE_DEBUG_REGISTERS (RW)
 *
 * Disable debug registers. If this bit is 1, debug registers are clock gated.
 */

#define BP_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS      20
#define BM_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS(v)   ((((reg32_t) v) << 20) & BM_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS)
#else
#define BF_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS(v)   (((v) << 20) & BM_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISABLE_DEBUG_REGISTERS field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, DISABLE_DEBUG_REGISTERS, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field DISABLE_RAM_CLOCK_GATING (RW)
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
//! @brief Set the DISABLE_RAM_CLOCK_GATING field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, DISABLE_RAM_CLOCK_GATING, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field FSCALE_CMD_LOAD (RW)
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
//! @brief Set the FSCALE_CMD_LOAD field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, FSCALE_CMD_LOAD, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field FSCALE_VAL (RW)
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
//! @brief Set the FSCALE_VAL field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_FSCALE_VAL(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, FSCALE_VAL, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field CLK2D_DIS (RW)
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
//! @brief Set the CLK2D_DIS field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_CLK2D_DIS(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, CLK2D_DIS, v)
#endif

/* --- Register HW_GPU2D_AQHICLOCKCONTROL, field CLK3D_DIS (RW)
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
//! @brief Set the CLK3D_DIS field to a new value.
#define BW_GPU2D_AQHICLOCKCONTROL_CLK3D_DIS(v)   BF_CS1(GPU2D_AQHICLOCKCONTROL, CLK3D_DIS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_AQHIIDLE - Idle Status Register (RO)
 *

 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_AQHIIDLE bitfields
 */

/* --- Register HW_GPU2D_AQHIIDLE, field AXI_LP (RO)
 *
 * AXI is in low power mode.
 */

#define BP_GPU2D_AQHIIDLE_AXI_LP      0
#define BM_GPU2D_AQHIIDLE_AXI_LP      0x00000001

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_TS (RO)
 *
 * TS is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_TS      20
#define BM_GPU2D_AQHIIDLE_IDLE_TS      0x00100000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_FP (RO)
 *
 * FP is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_FP      21
#define BM_GPU2D_AQHIIDLE_IDLE_FP      0x00200000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_IM (RO)
 *
 * IM is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_IM      22
#define BM_GPU2D_AQHIIDLE_IDLE_IM      0x00400000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_VG (RO)
 *
 * VG is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_VG      23
#define BM_GPU2D_AQHIIDLE_IDLE_VG      0x00800000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_TX (RO)
 *
 * TX is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_TX      24
#define BM_GPU2D_AQHIIDLE_IDLE_TX      0x01000000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_RA (RO)
 *
 * RA is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_RA      25
#define BM_GPU2D_AQHIIDLE_IDLE_RA      0x02000000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_SE (RO)
 *
 * SE is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_SE      26
#define BM_GPU2D_AQHIIDLE_IDLE_SE      0x04000000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_PA (RO)
 *
 * PA is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_PA      27
#define BM_GPU2D_AQHIIDLE_IDLE_PA      0x08000000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_SH (RO)
 *
 * SH is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_SH      28
#define BM_GPU2D_AQHIIDLE_IDLE_SH      0x10000000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_PE (RO)
 *
 * PE is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_PE      29
#define BM_GPU2D_AQHIIDLE_IDLE_PE      0x20000000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_DE (RO)
 *
 * DE is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_DE      30
#define BM_GPU2D_AQHIIDLE_IDLE_DE      0x40000000

/* --- Register HW_GPU2D_AQHIIDLE, field IDLE_FE (RO)
 *
 * FE is idle.
 */

#define BP_GPU2D_AQHIIDLE_IDLE_FE      31
#define BM_GPU2D_AQHIIDLE_IDLE_FE      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_AQAXICONFIG - AXI Configuration Register (RW)
 *

 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_AQAXICONFIG, field ARCACHE (RW)
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
//! @brief Set the ARCACHE field to a new value.
#define BW_GPU2D_AQAXICONFIG_ARCACHE(v)   BF_CS1(GPU2D_AQAXICONFIG, ARCACHE, v)
#endif

/* --- Register HW_GPU2D_AQAXICONFIG, field AWCACHE (RW)
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
//! @brief Set the AWCACHE field to a new value.
#define BW_GPU2D_AQAXICONFIG_AWCACHE(v)   BF_CS1(GPU2D_AQAXICONFIG, AWCACHE, v)
#endif

/* --- Register HW_GPU2D_AQAXICONFIG, field ARID (RW)
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
//! @brief Set the ARID field to a new value.
#define BW_GPU2D_AQAXICONFIG_ARID(v)   BF_CS1(GPU2D_AQAXICONFIG, ARID, v)
#endif

/* --- Register HW_GPU2D_AQAXICONFIG, field AWID (RW)
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
//! @brief Set the AWID field to a new value.
#define BW_GPU2D_AQAXICONFIG_AWID(v)   BF_CS1(GPU2D_AQAXICONFIG, AWID, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_AQAXISTATUS - AXI Status Register (RW)
 *

 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_AQAXISTATUS, field WR_ERR_ID (RW)
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
//! @brief Set the WR_ERR_ID field to a new value.
#define BW_GPU2D_AQAXISTATUS_WR_ERR_ID(v)   BF_CS1(GPU2D_AQAXISTATUS, WR_ERR_ID, v)
#endif

/* --- Register HW_GPU2D_AQAXISTATUS, field RD_ERR_ID (RW)
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
//! @brief Set the RD_ERR_ID field to a new value.
#define BW_GPU2D_AQAXISTATUS_RD_ERR_ID(v)   BF_CS1(GPU2D_AQAXISTATUS, RD_ERR_ID, v)
#endif

/* --- Register HW_GPU2D_AQAXISTATUS, field DET_WR_ERR (RW)
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
//! @brief Set the DET_WR_ERR field to a new value.
#define BW_GPU2D_AQAXISTATUS_DET_WR_ERR(v)   BF_CS1(GPU2D_AQAXISTATUS, DET_WR_ERR, v)
#endif

/* --- Register HW_GPU2D_AQAXISTATUS, field DET_RD_ERR (RW)
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
//! @brief Set the DET_RD_ERR field to a new value.
#define BW_GPU2D_AQAXISTATUS_DET_RD_ERR(v)   BF_CS1(GPU2D_AQAXISTATUS, DET_RD_ERR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_AQINTRACKNOWLEDGE - Interrupt Acknowledge Register (RO)
 *
 * Interrupt acknowledge register. Each bit represents a corresponding event being triggered.
 * Reading frmo this register clears the outstanding interrupt.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_AQINTRACKNOWLEDGE bitfields
 */

/* --- Register HW_GPU2D_AQINTRACKNOWLEDGE, field INTR_VEC (RO)
 *

 */

#define BP_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC      0
#define BM_GPU2D_AQINTRACKNOWLEDGE_INTR_VEC      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_AQINTRENBL - Interrupt Enable Register (RW)
 *
 * Interrupt enable register. Each bit enables a corresponding event.
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_AQINTRENBL, field INTR_ENBL_VEC (RW)
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
//! @brief Set the INTR_ENBL_VEC field to a new value.
#define BW_GPU2D_AQINTRENBL_INTR_ENBL_VEC(v)   BF_CS1(GPU2D_AQINTRENBL, INTR_ENBL_VEC, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_AQIDENT - Identification Register (RO)
 *
 * Identification register. This register has no set reset value. It varies with the implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_AQIDENT bitfields
 */

/* --- Register HW_GPU2D_AQIDENT, field CUSTOMER (RO)
 *
 * Customer value.
 */

#define BP_GPU2D_AQIDENT_CUSTOMER      0
#define BM_GPU2D_AQIDENT_CUSTOMER      0x000000ff

/* --- Register HW_GPU2D_AQIDENT, field TECHNOLOGY (RO)
 *
 * Technology value.
 */

#define BP_GPU2D_AQIDENT_TECHNOLOGY      8
#define BM_GPU2D_AQIDENT_TECHNOLOGY      0x00000f00

/* --- Register HW_GPU2D_AQIDENT, field REVISION (RO)
 *
 * Revision value.
 */

#define BP_GPU2D_AQIDENT_REVISION      12
#define BM_GPU2D_AQIDENT_REVISION      0x0000f000

/* --- Register HW_GPU2D_AQIDENT, field PRODUCT (RO)
 *
 * Product value.
 */

#define BP_GPU2D_AQIDENT_PRODUCT      16
#define BM_GPU2D_AQIDENT_PRODUCT      0x00ff0000

/* --- Register HW_GPU2D_AQIDENT, field FAMILY (RO)
 *
 * Family value.
 *
 * Values:
 * 01 - GC500
 * 02 - GC520
 * 03 - GC530
 * 04 - GC400
 * 05 - GC450
 * 08 - GC600
 * 09 - GC700
 * 0A - GC350
 * 10 - GC1000
 * 0B - GC380
 * 0C - GC800
 * 14 - GC2000
 */

#define BP_GPU2D_AQIDENT_FAMILY      24
#define BM_GPU2D_AQIDENT_FAMILY      0xff000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_FEATURES - Features Register (RO)
 *
 * Shows which features are enabled in this chip. This register has no set reset value. It varies
 * with the implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_FEATURES bitfields
 */

/* --- Register HW_GPU2D_FEATURES, field FE20_BIT_INDEX (RO)
 *
 * Supports 20 bit index.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_FE20_BIT_INDEX      0
#define BM_GPU2D_FEATURES_FE20_BIT_INDEX      0x00000001


/* --- Register HW_GPU2D_FEATURES, field RS_YUV_TARGET (RO)
 *
 * Supports resolving into YUV target.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_RS_YUV_TARGET      1
#define BM_GPU2D_FEATURES_RS_YUV_TARGET      0x00000002


/* --- Register HW_GPU2D_FEATURES, field BYTE_WRITE_3D (RO)
 *
 * 3D PE has byte write capability.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_BYTE_WRITE_3D      2
#define BM_GPU2D_FEATURES_BYTE_WRITE_3D      0x00000004


/* --- Register HW_GPU2D_FEATURES, field FE20 (RO)
 *
 * FE 2.0 is present.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_FE20      3
#define BM_GPU2D_FEATURES_FE20      0x00000008


/* --- Register HW_GPU2D_FEATURES, field VGTS (RO)
 *
 * VG tessellator is present.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_VGTS      4
#define BM_GPU2D_FEATURES_VGTS      0x00000010


/* --- Register HW_GPU2D_FEATURES, field PIPE_VG (RO)
 *
 * VG pipe is present.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_PIPE_VG      5
#define BM_GPU2D_FEATURES_PIPE_VG      0x00000020


/* --- Register HW_GPU2D_FEATURES, field MEM32_BIT_SUPPORT (RO)
 *
 * 32 bit memory address support.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_MEM32_BIT_SUPPORT      6
#define BM_GPU2D_FEATURES_MEM32_BIT_SUPPORT      0x00000040


/* --- Register HW_GPU2D_FEATURES, field YUY2_RENDER_TARGET (RO)
 *
 * YUY2 support in PE and YUY2 to RGB conversion in resolve.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_YUY2_RENDER_TARGET      7
#define BM_GPU2D_FEATURES_YUY2_RENDER_TARGET      0x00000080


/* --- Register HW_GPU2D_FEATURES, field HALF_TX_CACHE (RO)
 *
 * TX cache is half.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_HALF_TX_CACHE      8
#define BM_GPU2D_FEATURES_HALF_TX_CACHE      0x00000100


/* --- Register HW_GPU2D_FEATURES, field HALF_PE_CACHE (RO)
 *
 * PE cache is half.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_HALF_PE_CACHE      9
#define BM_GPU2D_FEATURES_HALF_PE_CACHE      0x00000200


/* --- Register HW_GPU2D_FEATURES, field YUY2_AVERAGING (RO)
 *
 * YUY2 averaging support in resolve.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_YUY2_AVERAGING      10
#define BM_GPU2D_FEATURES_YUY2_AVERAGING      0x00000400


/* --- Register HW_GPU2D_FEATURES, field NO_SCALER (RO)
 *
 * IP does not have 2D scaler.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_NO_SCALER      11
#define BM_GPU2D_FEATURES_NO_SCALER      0x00000800


/* --- Register HW_GPU2D_FEATURES, field BYTE_WRITE_2D (RO)
 *
 * Supports byte write in 2D.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_BYTE_WRITE_2D      12
#define BM_GPU2D_FEATURES_BYTE_WRITE_2D      0x00001000


/* --- Register HW_GPU2D_FEATURES, field BUFFER_INTERLEAVING (RO)
 *
 * IP supports interleaving depth and color buffers.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_BUFFER_INTERLEAVING      13
#define BM_GPU2D_FEATURES_BUFFER_INTERLEAVING      0x00002000


/* --- Register HW_GPU2D_FEATURES, field NO422_TEXTURE (RO)
 *
 * IP does not have 422 texture input format.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_NO422_TEXTURE      14
#define BM_GPU2D_FEATURES_NO422_TEXTURE      0x00004000


/* --- Register HW_GPU2D_FEATURES, field NO_EZ (RO)
 *
 * IP does not have early-Z.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_NO_EZ      15
#define BM_GPU2D_FEATURES_NO_EZ      0x00008000


/* --- Register HW_GPU2D_FEATURES, field MIN_AREA (RO)
 *
 * IP is configured to have minimum area.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_MIN_AREA      16
#define BM_GPU2D_FEATURES_MIN_AREA      0x00010000


/* --- Register HW_GPU2D_FEATURES, field MODULE_CG (RO)
 *
 * Second level clock gating is available.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_MODULE_CG      17
#define BM_GPU2D_FEATURES_MODULE_CG      0x00020000


/* --- Register HW_GPU2D_FEATURES, field YUV420_TILER (RO)
 *
 * YUV 4:2:0 tiler is available.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_YUV420_TILER      18
#define BM_GPU2D_FEATURES_YUV420_TILER      0x00040000


/* --- Register HW_GPU2D_FEATURES, field HIGH_DYNAMIC_RANGE (RO)
 *
 * Shows if the IP has HDR support.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE      19
#define BM_GPU2D_FEATURES_HIGH_DYNAMIC_RANGE      0x00080000


/* --- Register HW_GPU2D_FEATURES, field FAST_SCALER (RO)
 *
 * Shows if the IP has HD scaler.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_FAST_SCALER      20
#define BM_GPU2D_FEATURES_FAST_SCALER      0x00100000


/* --- Register HW_GPU2D_FEATURES, field ETC1_TEXTURE_COMPRESSION (RO)
 *
 * ETC1 texture compression.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION      21
#define BM_GPU2D_FEATURES_ETC1_TEXTURE_COMPRESSION      0x00200000


/* --- Register HW_GPU2D_FEATURES, field PIPE_2D (RO)
 *
 * Shows if there is 2D engine.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_PIPE_2D      22
#define BM_GPU2D_FEATURES_PIPE_2D      0x00400000


/* --- Register HW_GPU2D_FEATURES, field DC (RO)
 *
 * Shows if there is a display controller in the IP.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_DC      23
#define BM_GPU2D_FEATURES_DC      0x00800000


/* --- Register HW_GPU2D_FEATURES, field MSAA (RO)
 *
 * MSAA support.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_MSAA      24
#define BM_GPU2D_FEATURES_MSAA      0x01000000


/* --- Register HW_GPU2D_FEATURES, field YUV420_FILTER (RO)
 *
 * YUV 4:2:0 support in filter blit.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_YUV420_FILTER      25
#define BM_GPU2D_FEATURES_YUV420_FILTER      0x02000000


/* --- Register HW_GPU2D_FEATURES, field ZCOMPRESSION (RO)
 *
 * Depth and color compression.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_ZCOMPRESSION      26
#define BM_GPU2D_FEATURES_ZCOMPRESSION      0x04000000


/* --- Register HW_GPU2D_FEATURES, field DEBUG_MODE (RO)
 *
 * Debug registers.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_DEBUG_MODE      27
#define BM_GPU2D_FEATURES_DEBUG_MODE      0x08000000


/* --- Register HW_GPU2D_FEATURES, field DXT_TEXTURE_COMPRESSION (RO)
 *
 * DXT texture compression.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION      28
#define BM_GPU2D_FEATURES_DXT_TEXTURE_COMPRESSION      0x10000000


/* --- Register HW_GPU2D_FEATURES, field PIPE_3D (RO)
 *
 * 3D pipe.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_PIPE_3D      29
#define BM_GPU2D_FEATURES_PIPE_3D      0x20000000


/* --- Register HW_GPU2D_FEATURES, field SPECIAL_ANTI_ALIASING (RO)
 *
 * Full-screen anti-aliasing.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING      30
#define BM_GPU2D_FEATURES_SPECIAL_ANTI_ALIASING      0x40000000


/* --- Register HW_GPU2D_FEATURES, field FAST_CLEAR (RO)
 *
 * Fast clear.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_FEATURES_FAST_CLEAR      31
#define BM_GPU2D_FEATURES_FAST_CLEAR      0x80000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_CHIPID - Chip Identification Register (RO)
 *
 * Shows the ID for the chip in BCD. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_CHIPID bitfields
 */

/* --- Register HW_GPU2D_CHIPID, field ID (RO)
 *
 * Id.
 */

#define BP_GPU2D_CHIPID_ID      0
#define BM_GPU2D_CHIPID_ID      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_CHIPREV - Chip Revision Register (RO)
 *
 * Shows the revision for the chip in BCD. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_CHIPREV bitfields
 */

/* --- Register HW_GPU2D_CHIPREV, field REV (RO)
 *
 * Revision.
 */

#define BP_GPU2D_CHIPREV_REV      0
#define BM_GPU2D_CHIPREV_REV      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_CHIPDATE - Chip Release Date Register (RO)
 *
 * Shows the release date for the IP. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_CHIPDATE bitfields
 */

/* --- Register HW_GPU2D_CHIPDATE, field DATE (RO)
 *
 * Date.
 */

#define BP_GPU2D_CHIPDATE_DATE      0
#define BM_GPU2D_CHIPDATE_DATE      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_CHIPTIME - Chip Release Time Register (RO)
 *
 * Shows the release time for the IP. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_CHIPTIME bitfields
 */

/* --- Register HW_GPU2D_CHIPTIME, field TIME (RO)
 *
 * Time.
 */

#define BP_GPU2D_CHIPTIME_TIME      0
#define BM_GPU2D_CHIPTIME_TIME      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_CHIPCUSTOMER - Chip Customer Register (RO)
 *
 * Shows the customer and group for the IP. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_CHIPCUSTOMER bitfields
 */

/* --- Register HW_GPU2D_CHIPCUSTOMER, field GROUP (RO)
 *
 * Group.
 */

#define BP_GPU2D_CHIPCUSTOMER_GROUP      0
#define BM_GPU2D_CHIPCUSTOMER_GROUP      0x0000ffff

/* --- Register HW_GPU2D_CHIPCUSTOMER, field COMPANY (RO)
 *
 * Company.
 */

#define BP_GPU2D_CHIPCUSTOMER_COMPANY      16
#define BM_GPU2D_CHIPCUSTOMER_COMPANY      0xffff0000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_MINORFEATURES0 - Minor Features Register 0 (RO)
 *
 * Shows which minor features are enabled in this chip. This register has no set reset value. It
 * varies with the implementation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FLIP_Y : 1; //!< Y flipping capability is added to resolve.
        unsigned DUAL_RETURN_BUS : 1; //!< Dual Return Bus from HI to clients.
        unsigned ENDIANNESS_CONFIG : 1; //!< Configurable endianness support.
        unsigned TEXTURE8_K : 1; //!< Supports 8Kx8K textures.
        unsigned CORRECT_TEXTURE_CONVERTER : 1; //!< Driver hack is not needed.
        unsigned SPECIAL_MSAA_LOD : 1; //!< Special LOD calculation when MSAA is on.
        unsigned FAST_CLEAR_FLUSH : 1; //!< Proper flush is done in fast clear cache.
        unsigned _2DPE20 : 1; //!< 2D PE 2.0 is present.
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
#endif

/*
 * constants & macros for individual GPU2D_MINORFEATURES0 bitfields
 */

/* --- Register HW_GPU2D_MINORFEATURES0, field FLIP_Y (RO)
 *
 * Y flipping capability is added to resolve.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_FLIP_Y      0
#define BM_GPU2D_MINORFEATURES0_FLIP_Y      0x00000001


/* --- Register HW_GPU2D_MINORFEATURES0, field DUAL_RETURN_BUS (RO)
 *
 * Dual Return Bus from HI to clients.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS      1
#define BM_GPU2D_MINORFEATURES0_DUAL_RETURN_BUS      0x00000002


/* --- Register HW_GPU2D_MINORFEATURES0, field ENDIANNESS_CONFIG (RO)
 *
 * Configurable endianness support.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG      2
#define BM_GPU2D_MINORFEATURES0_ENDIANNESS_CONFIG      0x00000004


/* --- Register HW_GPU2D_MINORFEATURES0, field TEXTURE8_K (RO)
 *
 * Supports 8Kx8K textures.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_TEXTURE8_K      3
#define BM_GPU2D_MINORFEATURES0_TEXTURE8_K      0x00000008


/* --- Register HW_GPU2D_MINORFEATURES0, field CORRECT_TEXTURE_CONVERTER (RO)
 *
 * Driver hack is not needed.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER      4
#define BM_GPU2D_MINORFEATURES0_CORRECT_TEXTURE_CONVERTER      0x00000010


/* --- Register HW_GPU2D_MINORFEATURES0, field SPECIAL_MSAA_LOD (RO)
 *
 * Special LOD calculation when MSAA is on.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD      5
#define BM_GPU2D_MINORFEATURES0_SPECIAL_MSAA_LOD      0x00000020


/* --- Register HW_GPU2D_MINORFEATURES0, field FAST_CLEAR_FLUSH (RO)
 *
 * Proper flush is done in fast clear cache.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH      6
#define BM_GPU2D_MINORFEATURES0_FAST_CLEAR_FLUSH      0x00000040


/* --- Register HW_GPU2D_MINORFEATURES0, field _2DPE20 (RO)
 *
 * 2D PE 2.0 is present.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0__2DPE20      7
#define BM_GPU2D_MINORFEATURES0__2DPE20      0x00000080


/* --- Register HW_GPU2D_MINORFEATURES0, field CORRECT_AUTO_DISABLE (RO)
 *
 * Auto disable in FC is correct.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE      8
#define BM_GPU2D_MINORFEATURES0_CORRECT_AUTO_DISABLE      0x00000100


/* --- Register HW_GPU2D_MINORFEATURES0, field RENDER_8K (RO)
 *
 * Supports 8K render target.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_RENDER_8K      9
#define BM_GPU2D_MINORFEATURES0_RENDER_8K      0x00000200


/* --- Register HW_GPU2D_MINORFEATURES0, field TILE_STATUS_2BITS (RO)
 *
 * 2 bits are used instead of 4 bits for tile status.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS      10
#define BM_GPU2D_MINORFEATURES0_TILE_STATUS_2BITS      0x00000400


/* --- Register HW_GPU2D_MINORFEATURES0, field SEPARATE_TILE_STATUS_WHEN_INTERLEAVED (RO)
 *
 * Use 2 separate tile status buffers in interleaved mode.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED      11
#define BM_GPU2D_MINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED      0x00000800


/* --- Register HW_GPU2D_MINORFEATURES0, field SUPER_TILED_32X32 (RO)
 *
 * 32x32 super tile is available.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_SUPER_TILED_32X32      12
#define BM_GPU2D_MINORFEATURES0_SUPER_TILED_32X32      0x00001000


/* --- Register HW_GPU2D_MINORFEATURES0, field VG_20 (RO)
 *
 * Major updates to VG pipe (TS buffer tiling. State masking.).
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_VG_20      13
#define BM_GPU2D_MINORFEATURES0_VG_20      0x00002000


/* --- Register HW_GPU2D_MINORFEATURES0, field TS_EXTENDED_COMMANDS (RO)
 *
 * New commands added to the tessellator.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS      14
#define BM_GPU2D_MINORFEATURES0_TS_EXTENDED_COMMANDS      0x00004000


/* --- Register HW_GPU2D_MINORFEATURES0, field COMPRESSION_FIFO_FIXED (RO)
 *
 * If this bit is not set, the FIFO counter should be set to 50. Else, the default should remain.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED      15
#define BM_GPU2D_MINORFEATURES0_COMPRESSION_FIFO_FIXED      0x00008000


/* --- Register HW_GPU2D_MINORFEATURES0, field EXTRA_SHADER_INSTRUCTIONS0 (RO)
 *
 * Floor, ceil, and sign instructions are available.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0      16
#define BM_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0      0x00010000


/* --- Register HW_GPU2D_MINORFEATURES0, field VG_FILTER (RO)
 *
 * VG filter is available.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_VG_FILTER      17
#define BM_GPU2D_MINORFEATURES0_VG_FILTER      0x00020000


/* --- Register HW_GPU2D_MINORFEATURES0, field VG_21 (RO)
 *
 * Minor updates to VG pipe (Event generation from VG, TS, PE). Tiled image support.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_VG_21      18
#define BM_GPU2D_MINORFEATURES0_VG_21      0x00040000


/* --- Register HW_GPU2D_MINORFEATURES0, field SHADER_GETS_W (RO)
 *
 * W is sent to SH from RA.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_SHADER_GETS_W      19
#define BM_GPU2D_MINORFEATURES0_SHADER_GETS_W      0x00080000


/* --- Register HW_GPU2D_MINORFEATURES0, field EXTRA_SHADER_INSTRUCTIONS1 (RO)
 *
 * Sqrt, sin, cos instructions are available.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1      20
#define BM_GPU2D_MINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1      0x00100000


/* --- Register HW_GPU2D_MINORFEATURES0, field DEFAULT_REG0 (RO)
 *
 * Unavailable registers will return 0.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_DEFAULT_REG0      21
#define BM_GPU2D_MINORFEATURES0_DEFAULT_REG0      0x00200000


/* --- Register HW_GPU2D_MINORFEATURES0, field MC_20 (RO)
 *
 * New style MC with separate paths for color and depth.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_MC_20      22
#define BM_GPU2D_MINORFEATURES0_MC_20      0x00400000


/* --- Register HW_GPU2D_MINORFEATURES0, field SHADER_MSAA_SIDEBAND (RO)
 *
 * Put the MSAA data into sideband fifo.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND      23
#define BM_GPU2D_MINORFEATURES0_SHADER_MSAA_SIDEBAND      0x00800000


/* --- Register HW_GPU2D_MINORFEATURES0, field BUG_FIXES0 (RO)
 *

 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_BUG_FIXES0      24
#define BM_GPU2D_MINORFEATURES0_BUG_FIXES0      0x01000000


/* --- Register HW_GPU2D_MINORFEATURES0, field VAA (RO)
 *
 * VAA is available or not.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_VAA      25
#define BM_GPU2D_MINORFEATURES0_VAA      0x02000000


/* --- Register HW_GPU2D_MINORFEATURES0, field BYPASS_IN_MSAA (RO)
 *
 * Shader supports bypass mode when MSAA is enabled.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA      26
#define BM_GPU2D_MINORFEATURES0_BYPASS_IN_MSAA      0x04000000


/* --- Register HW_GPU2D_MINORFEATURES0, field HIERARCHICAL_Z (RO)
 *
 * Hierarchiccal Z is supported.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_HIERARCHICAL_Z      27
#define BM_GPU2D_MINORFEATURES0_HIERARCHICAL_Z      0x08000000


/* --- Register HW_GPU2D_MINORFEATURES0, field NEW_TEXTURE (RO)
 *
 * New texture unit is available.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_NEW_TEXTURE      28
#define BM_GPU2D_MINORFEATURES0_NEW_TEXTURE      0x10000000


/* --- Register HW_GPU2D_MINORFEATURES0, field A8_TARGET_SUPPORT (RO)
 *
 * 2D engine supports A8 target.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT      29
#define BM_GPU2D_MINORFEATURES0_A8_TARGET_SUPPORT      0x20000000


/* --- Register HW_GPU2D_MINORFEATURES0, field CORRECT_STENCIL (RO)
 *
 * Correct stencil behavior in depth only.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_CORRECT_STENCIL      30
#define BM_GPU2D_MINORFEATURES0_CORRECT_STENCIL      0x40000000


/* --- Register HW_GPU2D_MINORFEATURES0, field ENHANCE_VR (RO)
 *
 * Enhance VR and add a mode to walk 16 pixels in 16-bit mode in Vertical pass to improve $ hit rate
 * when rotating 90/270.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES0_ENHANCE_VR      31
#define BM_GPU2D_MINORFEATURES0_ENHANCE_VR      0x80000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_CACHECONTROL - Cache Control Register (RW)
 *

 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_CACHECONTROL, field NOT_USED (RW)
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
//! @brief Set the NOT_USED field to a new value.
#define BW_GPU2D_CACHECONTROL_NOT_USED(v)   BF_CS1(GPU2D_CACHECONTROL, NOT_USED, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_RESETMEMCOUNTERS - Reset Mem Counters Register (WO)
 *
 * Writing 1 will reset the counters and stop counting. Write 0 to start counting again. This
 * register is write only so it has no reset value.
 */
typedef union
{
    reg32_t U;
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
#define HW_GPU2D_RESETMEMCOUNTERS_WR(v)     (HW_GPU2D_RESETMEMCOUNTERS.U = (v))
#endif

/*
 * constants & macros for individual GPU2D_RESETMEMCOUNTERS bitfields
 */

/* --- Register HW_GPU2D_RESETMEMCOUNTERS, field RESET (WO)
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
//! @brief Set the RESET field to a new value.
#define BW_GPU2D_RESETMEMCOUNTERS_RESET(v)   BF_CS1(GPU2D_RESETMEMCOUNTERS, RESET, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALREADS - Read Count Register (RO)
 *
 * Total reads in terms of 64bits.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_TOTALREADS bitfields
 */

/* --- Register HW_GPU2D_TOTALREADS, field COUNT (RO)
 *

 */

#define BP_GPU2D_TOTALREADS_COUNT      0
#define BM_GPU2D_TOTALREADS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALWRITES - Write Count Register (RO)
 *
 * Total writes in terms of 64bits.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_TOTALWRITES bitfields
 */

/* --- Register HW_GPU2D_TOTALWRITES, field COUNT (RO)
 *

 */

#define BP_GPU2D_TOTALWRITES_COUNT      0
#define BM_GPU2D_TOTALWRITES_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_CHIPSPECS - Chip Specification Register (RO)
 *
 * Specs for the chip. This register has no set reset value. It varies with the implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_CHIPSPECS bitfields
 */

/* --- Register HW_GPU2D_CHIPSPECS, field VERTEX_OUTPUT_BUFFER_SIZE (RO)
 *
 * Log2 of vertex output buffer size.
 */

#define BP_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE      0
#define BM_GPU2D_CHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE      0x0000000f

/* --- Register HW_GPU2D_CHIPSPECS, field NUM_PIXEL_PIPES (RO)
 *
 * Number of pixel pipes.
 */

#define BP_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES      4
#define BM_GPU2D_CHIPSPECS_NUM_PIXEL_PIPES      0x00000070

/* --- Register HW_GPU2D_CHIPSPECS, field NUM_SHADER_CORES (RO)
 *
 * Number of shader cores.
 */

#define BP_GPU2D_CHIPSPECS_NUM_SHADER_CORES      7
#define BM_GPU2D_CHIPSPECS_NUM_SHADER_CORES      0x00000f80

/* --- Register HW_GPU2D_CHIPSPECS, field VERTEX_CACHE_SIZE (RO)
 *
 * Number of entries in the vertex shader cache.
 */

#define BP_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE      15
#define BM_GPU2D_CHIPSPECS_VERTEX_CACHE_SIZE      0x000f8000

/* --- Register HW_GPU2D_CHIPSPECS, field THREAD_COUNT (RO)
 *
 * Log2 of thread count.
 */

#define BP_GPU2D_CHIPSPECS_THREAD_COUNT      20
#define BM_GPU2D_CHIPSPECS_THREAD_COUNT      0x00f00000

/* --- Register HW_GPU2D_CHIPSPECS, field TEMP_REGISTERS (RO)
 *
 * Log2 of temporary registers.
 */

#define BP_GPU2D_CHIPSPECS_TEMP_REGISTERS      24
#define BM_GPU2D_CHIPSPECS_TEMP_REGISTERS      0x0f000000

/* --- Register HW_GPU2D_CHIPSPECS, field STREAMS (RO)
 *
 * Number of vertex streams.
 */

#define BP_GPU2D_CHIPSPECS_STREAMS      28
#define BM_GPU2D_CHIPSPECS_STREAMS      0xf0000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALWRITEBURSTS - Write Data Count Register (RO)
 *
 * Total write Data Count in terms of 64bits. This register has no reset value.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_TOTALWRITEBURSTS bitfields
 */

/* --- Register HW_GPU2D_TOTALWRITEBURSTS, field COUNT (RO)
 *

 */

#define BP_GPU2D_TOTALWRITEBURSTS_COUNT      0
#define BM_GPU2D_TOTALWRITEBURSTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALWRITEREQS - Write REQ Count Register (RO)
 *
 * Total write Request Count. This register has no reset value.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_TOTALWRITEREQS bitfields
 */

/* --- Register HW_GPU2D_TOTALWRITEREQS, field COUNT (RO)
 *

 */

#define BP_GPU2D_TOTALWRITEREQS_COUNT      0
#define BM_GPU2D_TOTALWRITEREQS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALWRITELASTS - Total WLAST Count Register (RO)
 *
 * Total WLAST Count. This is used to match with GCTotalWriteReqs. This register has no reset value.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_TOTALWRITELASTS bitfields
 */

/* --- Register HW_GPU2D_TOTALWRITELASTS, field COUNT (RO)
 *

 */

#define BP_GPU2D_TOTALWRITELASTS_COUNT      0
#define BM_GPU2D_TOTALWRITELASTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALREADBURSTS - Total Read Data Count Register (RO)
 *
 * Total Read Data Count in terms of 64bits. This register has no reset value.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_TOTALREADBURSTS bitfields
 */

/* --- Register HW_GPU2D_TOTALREADBURSTS, field COUNT (RO)
 *

 */

#define BP_GPU2D_TOTALREADBURSTS_COUNT      0
#define BM_GPU2D_TOTALREADBURSTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALREADREQS - Total Read REQ Count Register (RO)
 *
 * Total Read Request Count. This register has no reset value.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_TOTALREADREQS bitfields
 */

/* --- Register HW_GPU2D_TOTALREADREQS, field COUNT (RO)
 *

 */

#define BP_GPU2D_TOTALREADREQS_COUNT      0
#define BM_GPU2D_TOTALREADREQS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALREADLASTS - Total RLAST Count Register (RO)
 *
 * Total RLAST Count. This is used to match with GCTotalReadReqs. This register has no reset value.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_TOTALREADLASTS bitfields
 */

/* --- Register HW_GPU2D_TOTALREADLASTS, field COUNT (RO)
 *

 */

#define BP_GPU2D_TOTALREADLASTS_COUNT      0
#define BM_GPU2D_TOTALREADLASTS_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_GPOUT0 - General Purpose Register 0 (RW)
 *
 * General Purpose output register0. R/W but not connected to anywhere
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_GPOUT0, field COUNT (RW)
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
//! @brief Set the COUNT field to a new value.
#define BW_GPU2D_GPOUT0_COUNT(v)   BF_CS1(GPU2D_GPOUT0, COUNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_GPOUT1 - General Purpose Register 1 (RW)
 *
 * General Purpose output register1. R/W but not connected to anywhere
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_GPOUT1, field COUNT (RW)
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
//! @brief Set the COUNT field to a new value.
#define BW_GPU2D_GPOUT1_COUNT(v)   BF_CS1(GPU2D_GPOUT1, COUNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_GPOUT2 - General Purpose Register 2 (RW)
 *
 * General Purpose output register2. R/W but not connected to anywhere
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_GPOUT2, field COUNT (RW)
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
//! @brief Set the COUNT field to a new value.
#define BW_GPU2D_GPOUT2_COUNT(v)   BF_CS1(GPU2D_GPOUT2, COUNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_AXICONTROL - AXI Control Register (RW)
 *
 * Special Handling on AXI Bus
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_AXICONTROL, field WR_FULL_BURST_MODE (RW)
 *

 *
 * Values:
 * 0 - NO_BURST_RESET_VALUE
 * 1 - BURST_RESET_VALUE
 */

#define BP_GPU2D_AXICONTROL_WR_FULL_BURST_MODE      0
#define BM_GPU2D_AXICONTROL_WR_FULL_BURST_MODE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_AXICONTROL_WR_FULL_BURST_MODE(v)   ((((reg32_t) v) << 0) & BM_GPU2D_AXICONTROL_WR_FULL_BURST_MODE)
#else
#define BF_GPU2D_AXICONTROL_WR_FULL_BURST_MODE(v)   (((v) << 0) & BM_GPU2D_AXICONTROL_WR_FULL_BURST_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WR_FULL_BURST_MODE field to a new value.
#define BW_GPU2D_AXICONTROL_WR_FULL_BURST_MODE(v)   BF_CS1(GPU2D_AXICONTROL, WR_FULL_BURST_MODE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_MINORFEATURES1 - Minor Features Register 1 (RO)
 *
 * Shows which features are enabled in this chip. This register has no set reset value. It varies
 * with the implementation.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_MINORFEATURES1 bitfields
 */

/* --- Register HW_GPU2D_MINORFEATURES1, field TEXTURE_STRIDE (RO)
 *
 * Texture has stride and memory addressing.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES1_TEXTURE_STRIDE      26
#define BM_GPU2D_MINORFEATURES1_TEXTURE_STRIDE      0x04000000


/* --- Register HW_GPU2D_MINORFEATURES1, field BUG_FIXES2 (RO)
 *

 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES1_BUG_FIXES2      27
#define BM_GPU2D_MINORFEATURES1_BUG_FIXES2      0x08000000


/* --- Register HW_GPU2D_MINORFEATURES1, field BUG_FIXES1 (RO)
 *

 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES1_BUG_FIXES1      28
#define BM_GPU2D_MINORFEATURES1_BUG_FIXES1      0x10000000


/* --- Register HW_GPU2D_MINORFEATURES1, field VG_DOUBLE_BUFFER (RO)
 *
 * Double buffering support for VG (second TS-->VG semaphore is present).
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER      29
#define BM_GPU2D_MINORFEATURES1_VG_DOUBLE_BUFFER      0x20000000


/* --- Register HW_GPU2D_MINORFEATURES1, field V2_COMPRESSION (RO)
 *
 * V2 compression.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES1_V2_COMPRESSION      30
#define BM_GPU2D_MINORFEATURES1_V2_COMPRESSION      0x40000000


/* --- Register HW_GPU2D_MINORFEATURES1, field RSUV_SWIZZLE (RO)
 *
 * Resolve UV swizzle.
 *
 * Values:
 * 0 - NONE
 * 1 - AVAILABLE
 */

#define BP_GPU2D_MINORFEATURES1_RSUV_SWIZZLE      31
#define BM_GPU2D_MINORFEATURES1_RSUV_SWIZZLE      0x80000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALCYCLES - Total Cycle Counter Register (RW)
 *
 * Total cycles. This register is a free running counter. It can be reset by writing 0 to it.
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_TOTALCYCLES, field CYCLES (RW)
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
//! @brief Set the CYCLES field to a new value.
#define BW_GPU2D_TOTALCYCLES_CYCLES(v)   BF_CS1(GPU2D_TOTALCYCLES, CYCLES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_TOTALIDLECYLES - Total Idle Cycle Register (RW)
 *
 * Total cycles where the GPU is idle. It is reset when gcTotalCycles register is written to. It
 * looks at all the blocks but FE when determining the IP is idle.
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_TOTALIDLECYLES, field CYCLES (RW)
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
//! @brief Set the CYCLES field to a new value.
#define BW_GPU2D_TOTALIDLECYLES_CYCLES(v)   BF_CS1(GPU2D_TOTALIDLECYLES, CYCLES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_CHIPSPECS2 - Chip Specification Register (RW)
 *
 * Set address to 0x020 from 1G per Joseph Hernanzez  Specs for the chip. This register has no reset
 * value. It varies with the implementation.
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_CHIPSPECS2, field CYCLES (RW)
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
//! @brief Set the CYCLES field to a new value.
#define BW_GPU2D_CHIPSPECS2_CYCLES(v)   BF_CS1(GPU2D_CHIPSPECS2, CYCLES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_MODULEPOWERCONTROLS - Power Control Register (RW)
 *
 * The Power Management register set has just a few registers for controlling clock gating within
 * the core. GC400 allows the user to control the clock gating of each internal module independently
 * of the other modules. Users can access all of these registers via the AHB Bus.  Control register
 * for module level power controls.
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field TURN_OFF_COUNTER (RW)
 *
 * Counter value for clock gating the module if the module is idle for this amount of clock cycles.
 */

#define BP_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER      0
#define BM_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER(v)   ((((reg32_t) v) << 0) & BM_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER)
#else
#define BF_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER(v)   (((v) << 0) & BM_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TURN_OFF_COUNTER field to a new value.
#define BW_GPU2D_MODULEPOWERCONTROLS_TURN_OFF_COUNTER(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, TURN_OFF_COUNTER, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field TURN_ON_COUNTER (RW)
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
//! @brief Set the TURN_ON_COUNTER field to a new value.
#define BW_GPU2D_MODULEPOWERCONTROLS_TURN_ON_COUNTER(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, TURN_ON_COUNTER, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field DISABLE_STARVE_MODULE_CLOCK_GATING (RW)
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
//! @brief Set the DISABLE_STARVE_MODULE_CLOCK_GATING field to a new value.
#define BW_GPU2D_MODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, DISABLE_STARVE_MODULE_CLOCK_GATING, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field DISABLE_STALL_MODULE_CLOCK_GATING (RW)
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
//! @brief Set the DISABLE_STALL_MODULE_CLOCK_GATING field to a new value.
#define BW_GPU2D_MODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, DISABLE_STALL_MODULE_CLOCK_GATING, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERCONTROLS, field ENABLE_MODULE_CLOCK_GATING (RW)
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
//! @brief Set the ENABLE_MODULE_CLOCK_GATING field to a new value.
#define BW_GPU2D_MODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING(v)   BF_CS1(GPU2D_MODULEPOWERCONTROLS, ENABLE_MODULE_CLOCK_GATING, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_MODULEPOWERMODULECONTROL - Power Level Register (RW)
 *
 * Module level control registers.
 */
typedef union
{
    reg32_t U;
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

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_TS (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_TS field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TS(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_TS, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_FP (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_FP field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FP(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_FP, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_IM (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_IM field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_IM(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_IM, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_VG (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_VG field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_VG(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_VG, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_TX (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_TX field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_TX, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_RA (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_RA field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_RA, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_SE (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_SE field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_SE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_PA (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_PA field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_PA, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_SH (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_SH field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_SH, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_PE (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_PE field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_PE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_DE (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_DE field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_DE, v)
#endif

/* --- Register HW_GPU2D_MODULEPOWERMODULECONTROL, field DISABLE_MODULE_CLOCK_GATING_FE (RW)
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
//! @brief Set the DISABLE_MODULE_CLOCK_GATING_FE field to a new value.
#define BW_GPU2D_MODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE(v)   BF_CS1(GPU2D_MODULEPOWERMODULECONTROL, DISABLE_MODULE_CLOCK_GATING_FE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU2D_MODULEPOWERMODULESTATUS - Power Status Register (RO)
 *
 * Module level control status.
 */
typedef union
{
    reg32_t U;
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
#endif

/*
 * constants & macros for individual GPU2D_MODULEPOWERMODULESTATUS bitfields
 */

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_TS (RO)
 *
 * Module level clock gating is ON for TS.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS      20
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TS      0x00100000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_FP (RO)
 *
 * Module level clock gating is ON for FP.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP      21
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FP      0x00200000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_IM (RO)
 *
 * Module level clock gating is ON for IM.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM      22
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_IM      0x00400000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_VG (RO)
 *
 * Module level clock gating is ON for VG.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG      23
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_VG      0x00800000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_TX (RO)
 *
 * Module level clock gating is ON for TX.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX      24
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX      0x01000000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_RA (RO)
 *
 * Module level clock gating is ON for RA.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA      25
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA      0x02000000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_SE (RO)
 *
 * Module level clock gating is ON for SE.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE      26
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE      0x04000000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_PA (RO)
 *
 * Module level clock gating is ON for PA.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA      27
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA      0x08000000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_SH (RO)
 *
 * Module level clock gating is ON for SH.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH      28
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH      0x10000000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_PE (RO)
 *
 * Module level clock gating is ON for PE.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE      29
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE      0x20000000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_DE (RO)
 *
 * Module level clock gating is ON for DE.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE      30
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE      0x40000000

/* --- Register HW_GPU2D_MODULEPOWERMODULESTATUS, field MODULE_CLOCK_GATED_FE (RO)
 *
 * Module level clock gating is ON for FE.
 */

#define BP_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE      31
#define BM_GPU2D_MODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE      0x80000000


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
} hw_gpu2d_t;
#endif

//! @brief Macro to access all GPU2D registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_GPU2D(0)</code>.
#define HW_GPU2D     (*(volatile hw_gpu2d_t *) REGS_GPU2D_BASE)


#endif // _GPU2D_H
