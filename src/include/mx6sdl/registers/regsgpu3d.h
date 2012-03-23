/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_GPU3D_REGISTERS_H__
#define __HW_GPU3D_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SDL GPU3D registers defined in this header file.
 *
 * - HW_GPU3D_AQH_CLK_CTRL - AQHiClockControl
 * - HW_GPU3D_AQH_IDLE - AQHIdle
 * - HW_GPU3D_AQA_CFG - AQAxiConfig
 * - HW_GPU3D_AQA_STATUS - AQAxiStatus
 * - HW_GPU3D_AQI_ACK - AQIntrAcknowledge
 * - HW_GPU3D_AQI_ENBL - AQIntrEnbl
 * - HW_GPU3D_AQIDENT - AQIdent
 * - HW_GPU3D_GC_FEAT - GCFeatures
 * - HW_GPU3D_GCC_ID - GCChipId
 * - HW_GPU3D_GCC_REV - GCChipRev
 * - HW_GPU3D_GCC_DATE - GCChipDate
 * - HW_GPU3D_GCC_TIME - GCChipTime
 * - HW_GPU3D_GCC_CUST - GCChipCustomer
 * - HW_GPU3D_GCM_FEAT_0 - GCMinorFeatures0
 * - HW_GPU3D_GCC_CRTL - GCCacheControl
 * - HW_GPU3D_GCR_MEM_CTRS - GCResetMemCounters
 * - HW_GPU3D_GCT_READS - gcTotalReads
 * - HW_GPU3D_GCT_WRITES - gcTotalWrites
 * - HW_GPU3D_GCC_SPECS - gcChipSpecs
 * - HW_GPU3D_GCT_WRITE_BURSTS - gcTotalWriteBursts
 * - HW_GPU3D_GCT_WRITE_REQS - gcTotalWriteReqs
 * - HW_GPU3D_GCT_WRITE_LASTS - gcTotalWriteLasts
 * - HW_GPU3D_GCT_READ_BURSTS - gcTotalReadBursts
 * - HW_GPU3D_GCT_READ_REQS - gcTotalReadReqs
 * - HW_GPU3D_GCT_READ_LASTS - gcTotalReadLasts
 * - HW_GPU3D_GCGPO_0 - gcGpOut0
 * - HW_GPU3D_GCGPO_1 - gcGpOut1
 * - HW_GPU3D_GCGPO_2 - gcGpOut2
 * - HW_GPU3D_GCA_CRTL - gcAxiControl
 * - HW_GPU3D_GCM_FEAT_1 - GCMinorFeatures1
 * - HW_GPU3D_GCT_CYCLES - gcTotalCycles
 * - HW_GPU3D_GCT_IDLE_CYCLES - gcTotalIdleCycles
 *
 * - hw_gpu3d_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_GPU3D_BASE
#define HW_GPU3D_INSTANCE_COUNT (1) //!< Number of instances of the GPU3D module.
#define REGS_GPU3D_BASE (0x00130000) //!< Base address for GPU3D.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_AQH_CLK_CTRL - AQHiClockControl (RW)
 *
 * Reset value: 0x00000100
 *
 * Clock control register.
 */
typedef union _hw_gpu3d_aqh_clk_ctrl
{
    reg32_t U;
    struct _hw_gpu3d_aqh_clk_ctrl_bitfields
    {
        unsigned CLK3D_DIS : 1; //!< [0] Disable 3D clock.
        unsigned CLK2D_DIS : 1; //!< [1] Disable 2D clock.
        unsigned FSCALE_VAL : 7; //!< [8:2] 
        unsigned FSCALE_CMD_LOAD : 1; //!< [9] 
        unsigned DISABLE_RAM_CLOCK_GATING : 1; //!< [10] Disables clock gating for rams.
        unsigned DISABLE_DEBUG_REGISTERS : 1; //!< [11] Disable debug registers. If this bit is 1, debug registers are clock gated.
        unsigned SOFT_RESET : 1; //!< [12] Soft resets the IP.
        unsigned RESERVED0 : 3; //!< [15:13] Reserved
        unsigned IDLE3_D : 1; //!< [16] 3D pipe is idle.
        unsigned IDLE2_D : 1; //!< [17] 2D pipe is idle.
        unsigned IDLE_VG : 1; //!< [18] VG is idle.
        unsigned ISOLATE_GPU : 1; //!< [19] Isolate GPU bit
        unsigned MULTI_PIPE_REG_SELECT : 4; //!< [23:20] Determines which HI/MC to use while reading registers.
        unsigned MULTI_PIPE_USE_SINGLE_AXI : 4; //!< [27:24] Force all the transactions to go to one AXI
        unsigned RESERVED1 : 4; //!< [31:28] Reserved
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

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field CLK3D_DIS[0] (RW)
 *
 * Disable 3D clock.
 */

#define BP_GPU3D_AQH_CLK_CTRL_CLK3D_DIS      (0)      //!< Bit position for GPU3D_AQH_CLK_CTRL_CLK3D_DIS.
#define BM_GPU3D_AQH_CLK_CTRL_CLK3D_DIS      (0x00000001)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_CLK3D_DIS.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_CLK3D_DIS from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_CLK3D_DIS(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_CLK3D_DIS) >> BP_GPU3D_AQH_CLK_CTRL_CLK3D_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_CLK3D_DIS.
#define BF_GPU3D_AQH_CLK_CTRL_CLK3D_DIS(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_CLK3D_DIS) & BM_GPU3D_AQH_CLK_CTRL_CLK3D_DIS)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_CLK3D_DIS.
#define BF_GPU3D_AQH_CLK_CTRL_CLK3D_DIS(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_CLK3D_DIS) & BM_GPU3D_AQH_CLK_CTRL_CLK3D_DIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK3D_DIS field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_CLK3D_DIS(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_CLK3D_DIS) | BF_GPU3D_AQH_CLK_CTRL_CLK3D_DIS(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field CLK2D_DIS[1] (RW)
 *
 * Disable 2D clock.
 */

#define BP_GPU3D_AQH_CLK_CTRL_CLK2D_DIS      (1)      //!< Bit position for GPU3D_AQH_CLK_CTRL_CLK2D_DIS.
#define BM_GPU3D_AQH_CLK_CTRL_CLK2D_DIS      (0x00000002)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_CLK2D_DIS.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_CLK2D_DIS from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_CLK2D_DIS(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_CLK2D_DIS) >> BP_GPU3D_AQH_CLK_CTRL_CLK2D_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_CLK2D_DIS.
#define BF_GPU3D_AQH_CLK_CTRL_CLK2D_DIS(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_CLK2D_DIS) & BM_GPU3D_AQH_CLK_CTRL_CLK2D_DIS)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_CLK2D_DIS.
#define BF_GPU3D_AQH_CLK_CTRL_CLK2D_DIS(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_CLK2D_DIS) & BM_GPU3D_AQH_CLK_CTRL_CLK2D_DIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK2D_DIS field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_CLK2D_DIS(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_CLK2D_DIS) | BF_GPU3D_AQH_CLK_CTRL_CLK2D_DIS(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field FSCALE_VAL[8:2] (RW)
 *

 */

#define BP_GPU3D_AQH_CLK_CTRL_FSCALE_VAL      (2)      //!< Bit position for GPU3D_AQH_CLK_CTRL_FSCALE_VAL.
#define BM_GPU3D_AQH_CLK_CTRL_FSCALE_VAL      (0x000001fc)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_FSCALE_VAL.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_FSCALE_VAL from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_VAL) >> BP_GPU3D_AQH_CLK_CTRL_FSCALE_VAL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_FSCALE_VAL.
#define BF_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_FSCALE_VAL) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_VAL)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_FSCALE_VAL.
#define BF_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_FSCALE_VAL) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_VAL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FSCALE_VAL field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_FSCALE_VAL) | BF_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field FSCALE_CMD_LOAD[9] (RW)
 *

 */

#define BP_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD      (9)      //!< Bit position for GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD.
#define BM_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD      (0x00000200)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD) >> BP_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD.
#define BF_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD.
#define BF_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD) & BM_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FSCALE_CMD_LOAD field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD) | BF_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field DISABLE_RAM_CLOCK_GATING[10] (RW)
 *
 * Disables clock gating for rams.
 */

#define BP_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING      (10)      //!< Bit position for GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING.
#define BM_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING      (0x00000400)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING) >> BP_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING.
#define BF_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING.
#define BF_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DISABLE_RAM_CLOCK_GATING field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING) | BF_GPU3D_AQH_CLK_CTRL_DISABLE_RAM_CLOCK_GATING(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field DISABLE_DEBUG_REGISTERS[11] (RW)
 *
 * Disable debug registers. If this bit is 1, debug registers are clock gated.
 */

#define BP_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS      (11)      //!< Bit position for GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS.
#define BM_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS      (0x00000800)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS) >> BP_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS.
#define BF_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS.
#define BF_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS) & BM_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DISABLE_DEBUG_REGISTERS field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS) | BF_GPU3D_AQH_CLK_CTRL_DISABLE_DEBUG_REGISTERS(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field SOFT_RESET[12] (RW)
 *
 * Soft resets the IP.
 */

#define BP_GPU3D_AQH_CLK_CTRL_SOFT_RESET      (12)      //!< Bit position for GPU3D_AQH_CLK_CTRL_SOFT_RESET.
#define BM_GPU3D_AQH_CLK_CTRL_SOFT_RESET      (0x00001000)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_SOFT_RESET.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_SOFT_RESET from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_SOFT_RESET(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_SOFT_RESET) >> BP_GPU3D_AQH_CLK_CTRL_SOFT_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_SOFT_RESET.
#define BF_GPU3D_AQH_CLK_CTRL_SOFT_RESET(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_SOFT_RESET) & BM_GPU3D_AQH_CLK_CTRL_SOFT_RESET)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_SOFT_RESET.
#define BF_GPU3D_AQH_CLK_CTRL_SOFT_RESET(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_SOFT_RESET) & BM_GPU3D_AQH_CLK_CTRL_SOFT_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOFT_RESET field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_SOFT_RESET(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_SOFT_RESET) | BF_GPU3D_AQH_CLK_CTRL_SOFT_RESET(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field IDLE3_D[16] (RW)
 *
 * 3D pipe is idle.
 */

#define BP_GPU3D_AQH_CLK_CTRL_IDLE3_D      (16)      //!< Bit position for GPU3D_AQH_CLK_CTRL_IDLE3_D.
#define BM_GPU3D_AQH_CLK_CTRL_IDLE3_D      (0x00010000)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_IDLE3_D.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_IDLE3_D from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_IDLE3_D(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_IDLE3_D) >> BP_GPU3D_AQH_CLK_CTRL_IDLE3_D)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_IDLE3_D.
#define BF_GPU3D_AQH_CLK_CTRL_IDLE3_D(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_IDLE3_D) & BM_GPU3D_AQH_CLK_CTRL_IDLE3_D)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_IDLE3_D.
#define BF_GPU3D_AQH_CLK_CTRL_IDLE3_D(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_IDLE3_D) & BM_GPU3D_AQH_CLK_CTRL_IDLE3_D)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDLE3_D field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_IDLE3_D(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_IDLE3_D) | BF_GPU3D_AQH_CLK_CTRL_IDLE3_D(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field IDLE2_D[17] (RW)
 *
 * 2D pipe is idle.
 */

#define BP_GPU3D_AQH_CLK_CTRL_IDLE2_D      (17)      //!< Bit position for GPU3D_AQH_CLK_CTRL_IDLE2_D.
#define BM_GPU3D_AQH_CLK_CTRL_IDLE2_D      (0x00020000)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_IDLE2_D.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_IDLE2_D from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_IDLE2_D(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_IDLE2_D) >> BP_GPU3D_AQH_CLK_CTRL_IDLE2_D)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_IDLE2_D.
#define BF_GPU3D_AQH_CLK_CTRL_IDLE2_D(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_IDLE2_D) & BM_GPU3D_AQH_CLK_CTRL_IDLE2_D)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_IDLE2_D.
#define BF_GPU3D_AQH_CLK_CTRL_IDLE2_D(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_IDLE2_D) & BM_GPU3D_AQH_CLK_CTRL_IDLE2_D)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDLE2_D field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_IDLE2_D(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_IDLE2_D) | BF_GPU3D_AQH_CLK_CTRL_IDLE2_D(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field IDLE_VG[18] (RW)
 *
 * VG is idle.
 */

#define BP_GPU3D_AQH_CLK_CTRL_IDLE_VG      (18)      //!< Bit position for GPU3D_AQH_CLK_CTRL_IDLE_VG.
#define BM_GPU3D_AQH_CLK_CTRL_IDLE_VG      (0x00040000)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_IDLE_VG.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_IDLE_VG from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_IDLE_VG(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_IDLE_VG) >> BP_GPU3D_AQH_CLK_CTRL_IDLE_VG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_IDLE_VG.
#define BF_GPU3D_AQH_CLK_CTRL_IDLE_VG(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_IDLE_VG) & BM_GPU3D_AQH_CLK_CTRL_IDLE_VG)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_IDLE_VG.
#define BF_GPU3D_AQH_CLK_CTRL_IDLE_VG(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_IDLE_VG) & BM_GPU3D_AQH_CLK_CTRL_IDLE_VG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDLE_VG field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_IDLE_VG(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_IDLE_VG) | BF_GPU3D_AQH_CLK_CTRL_IDLE_VG(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field ISOLATE_GPU[19] (RW)
 *
 * Isolate GPU bit
 */

#define BP_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU      (19)      //!< Bit position for GPU3D_AQH_CLK_CTRL_ISOLATE_GPU.
#define BM_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU      (0x00080000)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_ISOLATE_GPU.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_ISOLATE_GPU from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU) >> BP_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_ISOLATE_GPU.
#define BF_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU) & BM_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_ISOLATE_GPU.
#define BF_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU) & BM_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISOLATE_GPU field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU) | BF_GPU3D_AQH_CLK_CTRL_ISOLATE_GPU(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field MULTI_PIPE_REG_SELECT[23:20] (RW)
 *
 * Determines which HI/MC to use while reading registers.
 */

#define BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT      (20)      //!< Bit position for GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT.
#define BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT      (0x00f00000)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT) >> BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT.
#define BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT.
#define BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MULTI_PIPE_REG_SELECT field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT) | BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_REG_SELECT(v)))
#endif

/* --- Register HW_GPU3D_AQH_CLK_CTRL, field MULTI_PIPE_USE_SINGLE_AXI[27:24] (RW)
 *
 * Force all the transactions to go to one AXI
 */

#define BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI      (24)      //!< Bit position for GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI.
#define BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI      (0x0f000000)  //!< Bit mask for GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI.

//! @brief Get value of GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI from a register value.
#define BG_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI(r)   (((r) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI) >> BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI.
#define BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI(v)   ((((reg32_t) v) << BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI)
#else
//! @brief Format value for bitfield GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI.
#define BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI(v)   (((v) << BP_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI) & BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MULTI_PIPE_USE_SINGLE_AXI field to a new value.
#define BW_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI(v)   (HW_GPU3D_AQH_CLK_CTRL_WR((HW_GPU3D_AQH_CLK_CTRL_RD() & ~BM_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI) | BF_GPU3D_AQH_CLK_CTRL_MULTI_PIPE_USE_SINGLE_AXI(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_AQH_IDLE - AQHIdle (RO)
 *
 * Reset value: 0x7fffffff
 *
 * Idle status register.
 */
typedef union _hw_gpu3d_aqh_idle
{
    reg32_t U;
    struct _hw_gpu3d_aqh_idle_bitfields
    {
        unsigned IDLE_FE : 1; //!< [0] FE is idle.
        unsigned IDLE_DE : 1; //!< [1] DE is idle.
        unsigned IDLE_PE : 1; //!< [2] PE is idle.
        unsigned IDLE_SH : 1; //!< [3] SH is idle.
        unsigned IDLE_PA : 1; //!< [4] PA is idle.
        unsigned IDLE_SE : 1; //!< [5] SE is idle.
        unsigned IDLE_RA : 1; //!< [6] RA is idle.
        unsigned IDLE_TX : 1; //!< [7] TX is idle.
        unsigned IDLE_VG : 1; //!< [8] VG is idle.
        unsigned IDLE_IM : 1; //!< [9] IM is idle.
        unsigned IDLE_FP : 1; //!< [10] FP is idle.
        unsigned IDLE_TS : 1; //!< [11] TS is idle.
        unsigned RESERVED0 : 19; //!< [30:12] Unused bits reserved for future expansion.
        unsigned AXI_LP : 1; //!< [31] AXI is in low power mode.
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
#endif

/*
 * constants & macros for individual GPU3D_AQH_IDLE bitfields
 */

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_FE[0] (RO)
 *
 * FE is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_FE      (0)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_FE.
#define BM_GPU3D_AQH_IDLE_IDLE_FE      (0x00000001)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_FE.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_FE from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_FE(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_FE) >> BP_GPU3D_AQH_IDLE_IDLE_FE)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_DE[1] (RO)
 *
 * DE is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_DE      (1)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_DE.
#define BM_GPU3D_AQH_IDLE_IDLE_DE      (0x00000002)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_DE.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_DE from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_DE(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_DE) >> BP_GPU3D_AQH_IDLE_IDLE_DE)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_PE[2] (RO)
 *
 * PE is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_PE      (2)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_PE.
#define BM_GPU3D_AQH_IDLE_IDLE_PE      (0x00000004)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_PE.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_PE from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_PE(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_PE) >> BP_GPU3D_AQH_IDLE_IDLE_PE)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_SH[3] (RO)
 *
 * SH is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_SH      (3)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_SH.
#define BM_GPU3D_AQH_IDLE_IDLE_SH      (0x00000008)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_SH.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_SH from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_SH(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_SH) >> BP_GPU3D_AQH_IDLE_IDLE_SH)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_PA[4] (RO)
 *
 * PA is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_PA      (4)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_PA.
#define BM_GPU3D_AQH_IDLE_IDLE_PA      (0x00000010)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_PA.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_PA from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_PA(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_PA) >> BP_GPU3D_AQH_IDLE_IDLE_PA)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_SE[5] (RO)
 *
 * SE is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_SE      (5)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_SE.
#define BM_GPU3D_AQH_IDLE_IDLE_SE      (0x00000020)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_SE.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_SE from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_SE(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_SE) >> BP_GPU3D_AQH_IDLE_IDLE_SE)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_RA[6] (RO)
 *
 * RA is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_RA      (6)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_RA.
#define BM_GPU3D_AQH_IDLE_IDLE_RA      (0x00000040)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_RA.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_RA from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_RA(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_RA) >> BP_GPU3D_AQH_IDLE_IDLE_RA)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_TX[7] (RO)
 *
 * TX is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_TX      (7)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_TX.
#define BM_GPU3D_AQH_IDLE_IDLE_TX      (0x00000080)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_TX.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_TX from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_TX(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_TX) >> BP_GPU3D_AQH_IDLE_IDLE_TX)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_VG[8] (RO)
 *
 * VG is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_VG      (8)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_VG.
#define BM_GPU3D_AQH_IDLE_IDLE_VG      (0x00000100)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_VG.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_VG from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_VG(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_VG) >> BP_GPU3D_AQH_IDLE_IDLE_VG)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_IM[9] (RO)
 *
 * IM is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_IM      (9)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_IM.
#define BM_GPU3D_AQH_IDLE_IDLE_IM      (0x00000200)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_IM.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_IM from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_IM(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_IM) >> BP_GPU3D_AQH_IDLE_IDLE_IM)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_FP[10] (RO)
 *
 * FP is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_FP      (10)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_FP.
#define BM_GPU3D_AQH_IDLE_IDLE_FP      (0x00000400)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_FP.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_FP from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_FP(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_FP) >> BP_GPU3D_AQH_IDLE_IDLE_FP)

/* --- Register HW_GPU3D_AQH_IDLE, field IDLE_TS[11] (RO)
 *
 * TS is idle.
 */

#define BP_GPU3D_AQH_IDLE_IDLE_TS      (11)      //!< Bit position for GPU3D_AQH_IDLE_IDLE_TS.
#define BM_GPU3D_AQH_IDLE_IDLE_TS      (0x00000800)  //!< Bit mask for GPU3D_AQH_IDLE_IDLE_TS.

//! @brief Get value of GPU3D_AQH_IDLE_IDLE_TS from a register value.
#define BG_GPU3D_AQH_IDLE_IDLE_TS(r)   (((r) & BM_GPU3D_AQH_IDLE_IDLE_TS) >> BP_GPU3D_AQH_IDLE_IDLE_TS)

/* --- Register HW_GPU3D_AQH_IDLE, field AXI_LP[31] (RO)
 *
 * AXI is in low power mode.
 */

#define BP_GPU3D_AQH_IDLE_AXI_LP      (31)      //!< Bit position for GPU3D_AQH_IDLE_AXI_LP.
#define BM_GPU3D_AQH_IDLE_AXI_LP      (0x80000000)  //!< Bit mask for GPU3D_AQH_IDLE_AXI_LP.

//! @brief Get value of GPU3D_AQH_IDLE_AXI_LP from a register value.
#define BG_GPU3D_AQH_IDLE_AXI_LP(r)   (((r) & BM_GPU3D_AQH_IDLE_AXI_LP) >> BP_GPU3D_AQH_IDLE_AXI_LP)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_AQA_CFG - AQAxiConfig (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_gpu3d_aqa_cfg
{
    reg32_t U;
    struct _hw_gpu3d_aqa_cfg_bitfields
    {
        unsigned AWID : 4; //!< [3:0] 
        unsigned ARID : 4; //!< [7:4] 
        unsigned AWCACHE : 4; //!< [11:8] 
        unsigned ARCACHE : 4; //!< [15:12] 
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
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

/* --- Register HW_GPU3D_AQA_CFG, field AWID[3:0] (RW)
 *

 */

#define BP_GPU3D_AQA_CFG_AWID      (0)      //!< Bit position for GPU3D_AQA_CFG_AWID.
#define BM_GPU3D_AQA_CFG_AWID      (0x0000000f)  //!< Bit mask for GPU3D_AQA_CFG_AWID.

//! @brief Get value of GPU3D_AQA_CFG_AWID from a register value.
#define BG_GPU3D_AQA_CFG_AWID(r)   (((r) & BM_GPU3D_AQA_CFG_AWID) >> BP_GPU3D_AQA_CFG_AWID)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQA_CFG_AWID.
#define BF_GPU3D_AQA_CFG_AWID(v)   ((((reg32_t) v) << BP_GPU3D_AQA_CFG_AWID) & BM_GPU3D_AQA_CFG_AWID)
#else
//! @brief Format value for bitfield GPU3D_AQA_CFG_AWID.
#define BF_GPU3D_AQA_CFG_AWID(v)   (((v) << BP_GPU3D_AQA_CFG_AWID) & BM_GPU3D_AQA_CFG_AWID)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AWID field to a new value.
#define BW_GPU3D_AQA_CFG_AWID(v)   (HW_GPU3D_AQA_CFG_WR((HW_GPU3D_AQA_CFG_RD() & ~BM_GPU3D_AQA_CFG_AWID) | BF_GPU3D_AQA_CFG_AWID(v)))
#endif

/* --- Register HW_GPU3D_AQA_CFG, field ARID[7:4] (RW)
 *

 */

#define BP_GPU3D_AQA_CFG_ARID      (4)      //!< Bit position for GPU3D_AQA_CFG_ARID.
#define BM_GPU3D_AQA_CFG_ARID      (0x000000f0)  //!< Bit mask for GPU3D_AQA_CFG_ARID.

//! @brief Get value of GPU3D_AQA_CFG_ARID from a register value.
#define BG_GPU3D_AQA_CFG_ARID(r)   (((r) & BM_GPU3D_AQA_CFG_ARID) >> BP_GPU3D_AQA_CFG_ARID)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQA_CFG_ARID.
#define BF_GPU3D_AQA_CFG_ARID(v)   ((((reg32_t) v) << BP_GPU3D_AQA_CFG_ARID) & BM_GPU3D_AQA_CFG_ARID)
#else
//! @brief Format value for bitfield GPU3D_AQA_CFG_ARID.
#define BF_GPU3D_AQA_CFG_ARID(v)   (((v) << BP_GPU3D_AQA_CFG_ARID) & BM_GPU3D_AQA_CFG_ARID)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARID field to a new value.
#define BW_GPU3D_AQA_CFG_ARID(v)   (HW_GPU3D_AQA_CFG_WR((HW_GPU3D_AQA_CFG_RD() & ~BM_GPU3D_AQA_CFG_ARID) | BF_GPU3D_AQA_CFG_ARID(v)))
#endif

/* --- Register HW_GPU3D_AQA_CFG, field AWCACHE[11:8] (RW)
 *

 */

#define BP_GPU3D_AQA_CFG_AWCACHE      (8)      //!< Bit position for GPU3D_AQA_CFG_AWCACHE.
#define BM_GPU3D_AQA_CFG_AWCACHE      (0x00000f00)  //!< Bit mask for GPU3D_AQA_CFG_AWCACHE.

//! @brief Get value of GPU3D_AQA_CFG_AWCACHE from a register value.
#define BG_GPU3D_AQA_CFG_AWCACHE(r)   (((r) & BM_GPU3D_AQA_CFG_AWCACHE) >> BP_GPU3D_AQA_CFG_AWCACHE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQA_CFG_AWCACHE.
#define BF_GPU3D_AQA_CFG_AWCACHE(v)   ((((reg32_t) v) << BP_GPU3D_AQA_CFG_AWCACHE) & BM_GPU3D_AQA_CFG_AWCACHE)
#else
//! @brief Format value for bitfield GPU3D_AQA_CFG_AWCACHE.
#define BF_GPU3D_AQA_CFG_AWCACHE(v)   (((v) << BP_GPU3D_AQA_CFG_AWCACHE) & BM_GPU3D_AQA_CFG_AWCACHE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AWCACHE field to a new value.
#define BW_GPU3D_AQA_CFG_AWCACHE(v)   (HW_GPU3D_AQA_CFG_WR((HW_GPU3D_AQA_CFG_RD() & ~BM_GPU3D_AQA_CFG_AWCACHE) | BF_GPU3D_AQA_CFG_AWCACHE(v)))
#endif

/* --- Register HW_GPU3D_AQA_CFG, field ARCACHE[15:12] (RW)
 *

 */

#define BP_GPU3D_AQA_CFG_ARCACHE      (12)      //!< Bit position for GPU3D_AQA_CFG_ARCACHE.
#define BM_GPU3D_AQA_CFG_ARCACHE      (0x0000f000)  //!< Bit mask for GPU3D_AQA_CFG_ARCACHE.

//! @brief Get value of GPU3D_AQA_CFG_ARCACHE from a register value.
#define BG_GPU3D_AQA_CFG_ARCACHE(r)   (((r) & BM_GPU3D_AQA_CFG_ARCACHE) >> BP_GPU3D_AQA_CFG_ARCACHE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQA_CFG_ARCACHE.
#define BF_GPU3D_AQA_CFG_ARCACHE(v)   ((((reg32_t) v) << BP_GPU3D_AQA_CFG_ARCACHE) & BM_GPU3D_AQA_CFG_ARCACHE)
#else
//! @brief Format value for bitfield GPU3D_AQA_CFG_ARCACHE.
#define BF_GPU3D_AQA_CFG_ARCACHE(v)   (((v) << BP_GPU3D_AQA_CFG_ARCACHE) & BM_GPU3D_AQA_CFG_ARCACHE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARCACHE field to a new value.
#define BW_GPU3D_AQA_CFG_ARCACHE(v)   (HW_GPU3D_AQA_CFG_WR((HW_GPU3D_AQA_CFG_RD() & ~BM_GPU3D_AQA_CFG_ARCACHE) | BF_GPU3D_AQA_CFG_ARCACHE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_AQA_STATUS - AQAxiStatus (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_gpu3d_aqa_status
{
    reg32_t U;
    struct _hw_gpu3d_aqa_status_bitfields
    {
        unsigned WR_ERR_ID : 4; //!< [3:0] 
        unsigned RD_ERR_ID : 4; //!< [7:4] 
        unsigned DET_WR_ERR : 1; //!< [8] 
        unsigned DET_RD_ERR : 1; //!< [9] 
        unsigned RESERVED0 : 22; //!< [31:10] Reserved
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
#endif

/*
 * constants & macros for individual GPU3D_AQA_STATUS bitfields
 */

/* --- Register HW_GPU3D_AQA_STATUS, field WR_ERR_ID[3:0] (RO)
 *

 */

#define BP_GPU3D_AQA_STATUS_WR_ERR_ID      (0)      //!< Bit position for GPU3D_AQA_STATUS_WR_ERR_ID.
#define BM_GPU3D_AQA_STATUS_WR_ERR_ID      (0x0000000f)  //!< Bit mask for GPU3D_AQA_STATUS_WR_ERR_ID.

//! @brief Get value of GPU3D_AQA_STATUS_WR_ERR_ID from a register value.
#define BG_GPU3D_AQA_STATUS_WR_ERR_ID(r)   (((r) & BM_GPU3D_AQA_STATUS_WR_ERR_ID) >> BP_GPU3D_AQA_STATUS_WR_ERR_ID)

/* --- Register HW_GPU3D_AQA_STATUS, field RD_ERR_ID[7:4] (RO)
 *

 */

#define BP_GPU3D_AQA_STATUS_RD_ERR_ID      (4)      //!< Bit position for GPU3D_AQA_STATUS_RD_ERR_ID.
#define BM_GPU3D_AQA_STATUS_RD_ERR_ID      (0x000000f0)  //!< Bit mask for GPU3D_AQA_STATUS_RD_ERR_ID.

//! @brief Get value of GPU3D_AQA_STATUS_RD_ERR_ID from a register value.
#define BG_GPU3D_AQA_STATUS_RD_ERR_ID(r)   (((r) & BM_GPU3D_AQA_STATUS_RD_ERR_ID) >> BP_GPU3D_AQA_STATUS_RD_ERR_ID)

/* --- Register HW_GPU3D_AQA_STATUS, field DET_WR_ERR[8] (RO)
 *

 */

#define BP_GPU3D_AQA_STATUS_DET_WR_ERR      (8)      //!< Bit position for GPU3D_AQA_STATUS_DET_WR_ERR.
#define BM_GPU3D_AQA_STATUS_DET_WR_ERR      (0x00000100)  //!< Bit mask for GPU3D_AQA_STATUS_DET_WR_ERR.

//! @brief Get value of GPU3D_AQA_STATUS_DET_WR_ERR from a register value.
#define BG_GPU3D_AQA_STATUS_DET_WR_ERR(r)   (((r) & BM_GPU3D_AQA_STATUS_DET_WR_ERR) >> BP_GPU3D_AQA_STATUS_DET_WR_ERR)

/* --- Register HW_GPU3D_AQA_STATUS, field DET_RD_ERR[9] (RO)
 *

 */

#define BP_GPU3D_AQA_STATUS_DET_RD_ERR      (9)      //!< Bit position for GPU3D_AQA_STATUS_DET_RD_ERR.
#define BM_GPU3D_AQA_STATUS_DET_RD_ERR      (0x00000200)  //!< Bit mask for GPU3D_AQA_STATUS_DET_RD_ERR.

//! @brief Get value of GPU3D_AQA_STATUS_DET_RD_ERR from a register value.
#define BG_GPU3D_AQA_STATUS_DET_RD_ERR(r)   (((r) & BM_GPU3D_AQA_STATUS_DET_RD_ERR) >> BP_GPU3D_AQA_STATUS_DET_RD_ERR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_AQI_ACK - AQIntrAcknowledge (RO)
 *
 * Reset value: 0x00000000
 *
 * Interrupt acknowledge register. Each bit represents a corresponding event being triggered.
 * Reading from this register clears the outstanding interrupt.
 */
typedef union _hw_gpu3d_aqi_ack
{
    reg32_t U;
    struct _hw_gpu3d_aqi_ack_bitfields
    {
        unsigned INTR_VEC : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_AQI_ACK bitfields
 */

/* --- Register HW_GPU3D_AQI_ACK, field INTR_VEC[31:0] (RO)
 *

 */

#define BP_GPU3D_AQI_ACK_INTR_VEC      (0)      //!< Bit position for GPU3D_AQI_ACK_INTR_VEC.
#define BM_GPU3D_AQI_ACK_INTR_VEC      (0xffffffff)  //!< Bit mask for GPU3D_AQI_ACK_INTR_VEC.

//! @brief Get value of GPU3D_AQI_ACK_INTR_VEC from a register value.
#define BG_GPU3D_AQI_ACK_INTR_VEC(r)   (((r) & BM_GPU3D_AQI_ACK_INTR_VEC) >> BP_GPU3D_AQI_ACK_INTR_VEC)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_AQI_ENBL - AQIntrEnbl (RW)
 *
 * Reset value: 0x00000000
 *
 * Interrupt enable register. Each bit enables a corresponding event.
 */
typedef union _hw_gpu3d_aqi_enbl
{
    reg32_t U;
    struct _hw_gpu3d_aqi_enbl_bitfields
    {
        unsigned INTR_ENBL_VEC : 32; //!< [31:0] 
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

/* --- Register HW_GPU3D_AQI_ENBL, field INTR_ENBL_VEC[31:0] (RW)
 *

 */

#define BP_GPU3D_AQI_ENBL_INTR_ENBL_VEC      (0)      //!< Bit position for GPU3D_AQI_ENBL_INTR_ENBL_VEC.
#define BM_GPU3D_AQI_ENBL_INTR_ENBL_VEC      (0xffffffff)  //!< Bit mask for GPU3D_AQI_ENBL_INTR_ENBL_VEC.

//! @brief Get value of GPU3D_AQI_ENBL_INTR_ENBL_VEC from a register value.
#define BG_GPU3D_AQI_ENBL_INTR_ENBL_VEC(r)   (((r) & BM_GPU3D_AQI_ENBL_INTR_ENBL_VEC) >> BP_GPU3D_AQI_ENBL_INTR_ENBL_VEC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_AQI_ENBL_INTR_ENBL_VEC.
#define BF_GPU3D_AQI_ENBL_INTR_ENBL_VEC(v)   ((((reg32_t) v) << BP_GPU3D_AQI_ENBL_INTR_ENBL_VEC) & BM_GPU3D_AQI_ENBL_INTR_ENBL_VEC)
#else
//! @brief Format value for bitfield GPU3D_AQI_ENBL_INTR_ENBL_VEC.
#define BF_GPU3D_AQI_ENBL_INTR_ENBL_VEC(v)   (((v) << BP_GPU3D_AQI_ENBL_INTR_ENBL_VEC) & BM_GPU3D_AQI_ENBL_INTR_ENBL_VEC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INTR_ENBL_VEC field to a new value.
#define BW_GPU3D_AQI_ENBL_INTR_ENBL_VEC(v)   (HW_GPU3D_AQI_ENBL_WR((HW_GPU3D_AQI_ENBL_RD() & ~BM_GPU3D_AQI_ENBL_INTR_ENBL_VEC) | BF_GPU3D_AQI_ENBL_INTR_ENBL_VEC(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_AQIDENT - AQIdent (RO)
 *
 * Reset value: 0x00000000
 *
 * Identification register. This register has no set reset value. It varies with the implementation.
 */
typedef union _hw_gpu3d_aqident
{
    reg32_t U;
    struct _hw_gpu3d_aqident_bitfields
    {
        unsigned CUSTOMER : 8; //!< [7:0] Customer value.
        unsigned TECHNOLOGY : 4; //!< [11:8] Technology value.
        unsigned REVISION : 4; //!< [15:12] Revision value.
        unsigned PRODUCT : 8; //!< [23:16] Product value.
        unsigned FAMILY : 8; //!< [31:24] Family value.
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
#endif

/*
 * constants & macros for individual GPU3D_AQIDENT bitfields
 */

/* --- Register HW_GPU3D_AQIDENT, field CUSTOMER[7:0] (RO)
 *
 * Customer value.
 */

#define BP_GPU3D_AQIDENT_CUSTOMER      (0)      //!< Bit position for GPU3D_AQIDENT_CUSTOMER.
#define BM_GPU3D_AQIDENT_CUSTOMER      (0x000000ff)  //!< Bit mask for GPU3D_AQIDENT_CUSTOMER.

//! @brief Get value of GPU3D_AQIDENT_CUSTOMER from a register value.
#define BG_GPU3D_AQIDENT_CUSTOMER(r)   (((r) & BM_GPU3D_AQIDENT_CUSTOMER) >> BP_GPU3D_AQIDENT_CUSTOMER)

/* --- Register HW_GPU3D_AQIDENT, field TECHNOLOGY[11:8] (RO)
 *
 * Technology value.
 */

#define BP_GPU3D_AQIDENT_TECHNOLOGY      (8)      //!< Bit position for GPU3D_AQIDENT_TECHNOLOGY.
#define BM_GPU3D_AQIDENT_TECHNOLOGY      (0x00000f00)  //!< Bit mask for GPU3D_AQIDENT_TECHNOLOGY.

//! @brief Get value of GPU3D_AQIDENT_TECHNOLOGY from a register value.
#define BG_GPU3D_AQIDENT_TECHNOLOGY(r)   (((r) & BM_GPU3D_AQIDENT_TECHNOLOGY) >> BP_GPU3D_AQIDENT_TECHNOLOGY)

/* --- Register HW_GPU3D_AQIDENT, field REVISION[15:12] (RO)
 *
 * Revision value.
 */

#define BP_GPU3D_AQIDENT_REVISION      (12)      //!< Bit position for GPU3D_AQIDENT_REVISION.
#define BM_GPU3D_AQIDENT_REVISION      (0x0000f000)  //!< Bit mask for GPU3D_AQIDENT_REVISION.

//! @brief Get value of GPU3D_AQIDENT_REVISION from a register value.
#define BG_GPU3D_AQIDENT_REVISION(r)   (((r) & BM_GPU3D_AQIDENT_REVISION) >> BP_GPU3D_AQIDENT_REVISION)

/* --- Register HW_GPU3D_AQIDENT, field PRODUCT[23:16] (RO)
 *
 * Product value.
 */

#define BP_GPU3D_AQIDENT_PRODUCT      (16)      //!< Bit position for GPU3D_AQIDENT_PRODUCT.
#define BM_GPU3D_AQIDENT_PRODUCT      (0x00ff0000)  //!< Bit mask for GPU3D_AQIDENT_PRODUCT.

//! @brief Get value of GPU3D_AQIDENT_PRODUCT from a register value.
#define BG_GPU3D_AQIDENT_PRODUCT(r)   (((r) & BM_GPU3D_AQIDENT_PRODUCT) >> BP_GPU3D_AQIDENT_PRODUCT)

/* --- Register HW_GPU3D_AQIDENT, field FAMILY[31:24] (RO)
 *
 * Family value.
 *
 * Values:
 * 0C - =>GC800
 * 14 - =>GPU3D
 */

#define BP_GPU3D_AQIDENT_FAMILY      (24)      //!< Bit position for GPU3D_AQIDENT_FAMILY.
#define BM_GPU3D_AQIDENT_FAMILY      (0xff000000)  //!< Bit mask for GPU3D_AQIDENT_FAMILY.

//! @brief Get value of GPU3D_AQIDENT_FAMILY from a register value.
#define BG_GPU3D_AQIDENT_FAMILY(r)   (((r) & BM_GPU3D_AQIDENT_FAMILY) >> BP_GPU3D_AQIDENT_FAMILY)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GC_FEAT - GCFeatures (RO)
 *
 * Reset value: 0x00000000
 *
 * Shows which features are enabled in this chip. This register has no set reset value. It varies
 * with the implementation.
 */
typedef union _hw_gpu3d_gc_feat
{
    reg32_t U;
    struct _hw_gpu3d_gc_feat_bitfields
    {
        unsigned FAST_CLEAR : 1; //!< [0] Fast clear.
        unsigned SPECIAL_ANTI_ALIASING : 1; //!< [1] Full-screen anti-aliasing.
        unsigned PIPE_3D : 1; //!< [2] 3D pipe.
        unsigned DXT_TEXTURE_COMPRESSION : 1; //!< [3] DXT texture compression.
        unsigned DEBUG_MODE : 1; //!< [4] Debug registers.
        unsigned ZCOMPRESSION : 1; //!< [5] Depth and color compression.
        unsigned YUV420_FILTER : 1; //!< [6] YUV 4:2:0 support in filter blit.
        unsigned MSAA : 1; //!< [7] MSAA support.
        unsigned DC : 1; //!< [8] Shows if there is a display controller in the IP.
        unsigned PIPE_2D : 1; //!< [9] Shows if there is 2D engine.
        unsigned ETC1_TEXTURE_COMPRESSION : 1; //!< [10] ETC1 texture compression.
        unsigned FAST_SCALER : 1; //!< [11] Shows if the IP has HD scaler.
        unsigned HIGH_DYNAMIC_RANGE : 1; //!< [12] Shows if the IP has HDR support.
        unsigned YUV420_TILER : 1; //!< [13] YUV 4:2:0 tiler is available.
        unsigned MODULE_CG : 1; //!< [14] Secong level clock gating is available.
        unsigned MIN_AREA : 1; //!< [15] IP is configured to have minimum area.
        unsigned NO_EZ : 1; //!< [16] IP does not have early-Z.
        unsigned NO422_TEXTURE : 1; //!< [17] IP does not have 422 texture input format.
        unsigned BUFFER_INTERLEAVING : 1; //!< [18] IP supports interleaving depth and color buffers.
        unsigned BYTE_WRITE_2D : 1; //!< [19] Supports byte write in 2D.
        unsigned NO_SCALER : 1; //!< [20] IP does not have 2D scaler.
        unsigned YUY2_AVERAGING : 1; //!< [21] YUY2 averaging support in resolve.
        unsigned HALF_PE_CACHE : 1; //!< [22] PE cache is half.
        unsigned HALF_TX_CACHE : 1; //!< [23] TX cache is half.
        unsigned YUY2_RENDER_TARGET : 1; //!< [24] YUY2 support in PE and YUY2 to RGB conversion in resolve.
        unsigned MEM32_BIT_SUPPORT : 1; //!< [25] 32 bit memory address support.
        unsigned PIPE_VG : 1; //!< [26] VCG pipe is present.
        unsigned VGTS : 1; //!< [27] VG tessellator is present.
        unsigned FE20 : 1; //!< [28] FE 2.0 is present.
        unsigned BYTE_WRITE_3D : 1; //!< [29] 3D PE has byte write capability.
        unsigned RS_YUV_TARGET : 1; //!< [30] Supports resolving into YUV target.
        unsigned FE20_BIT_INDEX : 1; //!< [31] Supports 20 bit index.
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
#endif

/*
 * constants & macros for individual GPU3D_GC_FEAT bitfields
 */

/* --- Register HW_GPU3D_GC_FEAT, field FAST_CLEAR[0] (RO)
 *
 * Fast clear.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_FAST_CLEAR      (0)      //!< Bit position for GPU3D_GC_FEAT_FAST_CLEAR.
#define BM_GPU3D_GC_FEAT_FAST_CLEAR      (0x00000001)  //!< Bit mask for GPU3D_GC_FEAT_FAST_CLEAR.

//! @brief Get value of GPU3D_GC_FEAT_FAST_CLEAR from a register value.
#define BG_GPU3D_GC_FEAT_FAST_CLEAR(r)   (((r) & BM_GPU3D_GC_FEAT_FAST_CLEAR) >> BP_GPU3D_GC_FEAT_FAST_CLEAR)


/* --- Register HW_GPU3D_GC_FEAT, field SPECIAL_ANTI_ALIASING[1] (RO)
 *
 * Full-screen anti-aliasing.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING      (1)      //!< Bit position for GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING.
#define BM_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING      (0x00000002)  //!< Bit mask for GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING.

//! @brief Get value of GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING from a register value.
#define BG_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING(r)   (((r) & BM_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING) >> BP_GPU3D_GC_FEAT_SPECIAL_ANTI_ALIASING)


/* --- Register HW_GPU3D_GC_FEAT, field PIPE_3D[2] (RO)
 *
 * 3D pipe.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_PIPE_3D      (2)      //!< Bit position for GPU3D_GC_FEAT_PIPE_3D.
#define BM_GPU3D_GC_FEAT_PIPE_3D      (0x00000004)  //!< Bit mask for GPU3D_GC_FEAT_PIPE_3D.

//! @brief Get value of GPU3D_GC_FEAT_PIPE_3D from a register value.
#define BG_GPU3D_GC_FEAT_PIPE_3D(r)   (((r) & BM_GPU3D_GC_FEAT_PIPE_3D) >> BP_GPU3D_GC_FEAT_PIPE_3D)


/* --- Register HW_GPU3D_GC_FEAT, field DXT_TEXTURE_COMPRESSION[3] (RO)
 *
 * DXT texture compression.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION      (3)      //!< Bit position for GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION.
#define BM_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION      (0x00000008)  //!< Bit mask for GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION.

//! @brief Get value of GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION from a register value.
#define BG_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION(r)   (((r) & BM_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION) >> BP_GPU3D_GC_FEAT_DXT_TEXTURE_COMPRESSION)


/* --- Register HW_GPU3D_GC_FEAT, field DEBUG_MODE[4] (RO)
 *
 * Debug registers.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_DEBUG_MODE      (4)      //!< Bit position for GPU3D_GC_FEAT_DEBUG_MODE.
#define BM_GPU3D_GC_FEAT_DEBUG_MODE      (0x00000010)  //!< Bit mask for GPU3D_GC_FEAT_DEBUG_MODE.

//! @brief Get value of GPU3D_GC_FEAT_DEBUG_MODE from a register value.
#define BG_GPU3D_GC_FEAT_DEBUG_MODE(r)   (((r) & BM_GPU3D_GC_FEAT_DEBUG_MODE) >> BP_GPU3D_GC_FEAT_DEBUG_MODE)


/* --- Register HW_GPU3D_GC_FEAT, field ZCOMPRESSION[5] (RO)
 *
 * Depth and color compression.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_ZCOMPRESSION      (5)      //!< Bit position for GPU3D_GC_FEAT_ZCOMPRESSION.
#define BM_GPU3D_GC_FEAT_ZCOMPRESSION      (0x00000020)  //!< Bit mask for GPU3D_GC_FEAT_ZCOMPRESSION.

//! @brief Get value of GPU3D_GC_FEAT_ZCOMPRESSION from a register value.
#define BG_GPU3D_GC_FEAT_ZCOMPRESSION(r)   (((r) & BM_GPU3D_GC_FEAT_ZCOMPRESSION) >> BP_GPU3D_GC_FEAT_ZCOMPRESSION)


/* --- Register HW_GPU3D_GC_FEAT, field YUV420_FILTER[6] (RO)
 *
 * YUV 4:2:0 support in filter blit.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_YUV420_FILTER      (6)      //!< Bit position for GPU3D_GC_FEAT_YUV420_FILTER.
#define BM_GPU3D_GC_FEAT_YUV420_FILTER      (0x00000040)  //!< Bit mask for GPU3D_GC_FEAT_YUV420_FILTER.

//! @brief Get value of GPU3D_GC_FEAT_YUV420_FILTER from a register value.
#define BG_GPU3D_GC_FEAT_YUV420_FILTER(r)   (((r) & BM_GPU3D_GC_FEAT_YUV420_FILTER) >> BP_GPU3D_GC_FEAT_YUV420_FILTER)


/* --- Register HW_GPU3D_GC_FEAT, field MSAA[7] (RO)
 *
 * MSAA support.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_MSAA      (7)      //!< Bit position for GPU3D_GC_FEAT_MSAA.
#define BM_GPU3D_GC_FEAT_MSAA      (0x00000080)  //!< Bit mask for GPU3D_GC_FEAT_MSAA.

//! @brief Get value of GPU3D_GC_FEAT_MSAA from a register value.
#define BG_GPU3D_GC_FEAT_MSAA(r)   (((r) & BM_GPU3D_GC_FEAT_MSAA) >> BP_GPU3D_GC_FEAT_MSAA)


/* --- Register HW_GPU3D_GC_FEAT, field DC[8] (RO)
 *
 * Shows if there is a display controller in the IP.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_DC      (8)      //!< Bit position for GPU3D_GC_FEAT_DC.
#define BM_GPU3D_GC_FEAT_DC      (0x00000100)  //!< Bit mask for GPU3D_GC_FEAT_DC.

//! @brief Get value of GPU3D_GC_FEAT_DC from a register value.
#define BG_GPU3D_GC_FEAT_DC(r)   (((r) & BM_GPU3D_GC_FEAT_DC) >> BP_GPU3D_GC_FEAT_DC)


/* --- Register HW_GPU3D_GC_FEAT, field PIPE_2D[9] (RO)
 *
 * Shows if there is 2D engine.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_PIPE_2D      (9)      //!< Bit position for GPU3D_GC_FEAT_PIPE_2D.
#define BM_GPU3D_GC_FEAT_PIPE_2D      (0x00000200)  //!< Bit mask for GPU3D_GC_FEAT_PIPE_2D.

//! @brief Get value of GPU3D_GC_FEAT_PIPE_2D from a register value.
#define BG_GPU3D_GC_FEAT_PIPE_2D(r)   (((r) & BM_GPU3D_GC_FEAT_PIPE_2D) >> BP_GPU3D_GC_FEAT_PIPE_2D)


/* --- Register HW_GPU3D_GC_FEAT, field ETC1_TEXTURE_COMPRESSION[10] (RO)
 *
 * ETC1 texture compression.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION      (10)      //!< Bit position for GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION.
#define BM_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION      (0x00000400)  //!< Bit mask for GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION.

//! @brief Get value of GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION from a register value.
#define BG_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION(r)   (((r) & BM_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION) >> BP_GPU3D_GC_FEAT_ETC1_TEXTURE_COMPRESSION)


/* --- Register HW_GPU3D_GC_FEAT, field FAST_SCALER[11] (RO)
 *
 * Shows if the IP has HD scaler.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_FAST_SCALER      (11)      //!< Bit position for GPU3D_GC_FEAT_FAST_SCALER.
#define BM_GPU3D_GC_FEAT_FAST_SCALER      (0x00000800)  //!< Bit mask for GPU3D_GC_FEAT_FAST_SCALER.

//! @brief Get value of GPU3D_GC_FEAT_FAST_SCALER from a register value.
#define BG_GPU3D_GC_FEAT_FAST_SCALER(r)   (((r) & BM_GPU3D_GC_FEAT_FAST_SCALER) >> BP_GPU3D_GC_FEAT_FAST_SCALER)


/* --- Register HW_GPU3D_GC_FEAT, field HIGH_DYNAMIC_RANGE[12] (RO)
 *
 * Shows if the IP has HDR support.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE      (12)      //!< Bit position for GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE.
#define BM_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE      (0x00001000)  //!< Bit mask for GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE.

//! @brief Get value of GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE from a register value.
#define BG_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE(r)   (((r) & BM_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE) >> BP_GPU3D_GC_FEAT_HIGH_DYNAMIC_RANGE)


/* --- Register HW_GPU3D_GC_FEAT, field YUV420_TILER[13] (RO)
 *
 * YUV 4:2:0 tiler is available.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_YUV420_TILER      (13)      //!< Bit position for GPU3D_GC_FEAT_YUV420_TILER.
#define BM_GPU3D_GC_FEAT_YUV420_TILER      (0x00002000)  //!< Bit mask for GPU3D_GC_FEAT_YUV420_TILER.

//! @brief Get value of GPU3D_GC_FEAT_YUV420_TILER from a register value.
#define BG_GPU3D_GC_FEAT_YUV420_TILER(r)   (((r) & BM_GPU3D_GC_FEAT_YUV420_TILER) >> BP_GPU3D_GC_FEAT_YUV420_TILER)


/* --- Register HW_GPU3D_GC_FEAT, field MODULE_CG[14] (RO)
 *
 * Secong level clock gating is available.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_MODULE_CG      (14)      //!< Bit position for GPU3D_GC_FEAT_MODULE_CG.
#define BM_GPU3D_GC_FEAT_MODULE_CG      (0x00004000)  //!< Bit mask for GPU3D_GC_FEAT_MODULE_CG.

//! @brief Get value of GPU3D_GC_FEAT_MODULE_CG from a register value.
#define BG_GPU3D_GC_FEAT_MODULE_CG(r)   (((r) & BM_GPU3D_GC_FEAT_MODULE_CG) >> BP_GPU3D_GC_FEAT_MODULE_CG)


/* --- Register HW_GPU3D_GC_FEAT, field MIN_AREA[15] (RO)
 *
 * IP is configured to have minimum area.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_MIN_AREA      (15)      //!< Bit position for GPU3D_GC_FEAT_MIN_AREA.
#define BM_GPU3D_GC_FEAT_MIN_AREA      (0x00008000)  //!< Bit mask for GPU3D_GC_FEAT_MIN_AREA.

//! @brief Get value of GPU3D_GC_FEAT_MIN_AREA from a register value.
#define BG_GPU3D_GC_FEAT_MIN_AREA(r)   (((r) & BM_GPU3D_GC_FEAT_MIN_AREA) >> BP_GPU3D_GC_FEAT_MIN_AREA)


/* --- Register HW_GPU3D_GC_FEAT, field NO_EZ[16] (RO)
 *
 * IP does not have early-Z.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_NO_EZ      (16)      //!< Bit position for GPU3D_GC_FEAT_NO_EZ.
#define BM_GPU3D_GC_FEAT_NO_EZ      (0x00010000)  //!< Bit mask for GPU3D_GC_FEAT_NO_EZ.

//! @brief Get value of GPU3D_GC_FEAT_NO_EZ from a register value.
#define BG_GPU3D_GC_FEAT_NO_EZ(r)   (((r) & BM_GPU3D_GC_FEAT_NO_EZ) >> BP_GPU3D_GC_FEAT_NO_EZ)


/* --- Register HW_GPU3D_GC_FEAT, field NO422_TEXTURE[17] (RO)
 *
 * IP does not have 422 texture input format.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_NO422_TEXTURE      (17)      //!< Bit position for GPU3D_GC_FEAT_NO422_TEXTURE.
#define BM_GPU3D_GC_FEAT_NO422_TEXTURE      (0x00020000)  //!< Bit mask for GPU3D_GC_FEAT_NO422_TEXTURE.

//! @brief Get value of GPU3D_GC_FEAT_NO422_TEXTURE from a register value.
#define BG_GPU3D_GC_FEAT_NO422_TEXTURE(r)   (((r) & BM_GPU3D_GC_FEAT_NO422_TEXTURE) >> BP_GPU3D_GC_FEAT_NO422_TEXTURE)


/* --- Register HW_GPU3D_GC_FEAT, field BUFFER_INTERLEAVING[18] (RO)
 *
 * IP supports interleaving depth and color buffers.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_BUFFER_INTERLEAVING      (18)      //!< Bit position for GPU3D_GC_FEAT_BUFFER_INTERLEAVING.
#define BM_GPU3D_GC_FEAT_BUFFER_INTERLEAVING      (0x00040000)  //!< Bit mask for GPU3D_GC_FEAT_BUFFER_INTERLEAVING.

//! @brief Get value of GPU3D_GC_FEAT_BUFFER_INTERLEAVING from a register value.
#define BG_GPU3D_GC_FEAT_BUFFER_INTERLEAVING(r)   (((r) & BM_GPU3D_GC_FEAT_BUFFER_INTERLEAVING) >> BP_GPU3D_GC_FEAT_BUFFER_INTERLEAVING)


/* --- Register HW_GPU3D_GC_FEAT, field BYTE_WRITE_2D[19] (RO)
 *
 * Supports byte write in 2D.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_BYTE_WRITE_2D      (19)      //!< Bit position for GPU3D_GC_FEAT_BYTE_WRITE_2D.
#define BM_GPU3D_GC_FEAT_BYTE_WRITE_2D      (0x00080000)  //!< Bit mask for GPU3D_GC_FEAT_BYTE_WRITE_2D.

//! @brief Get value of GPU3D_GC_FEAT_BYTE_WRITE_2D from a register value.
#define BG_GPU3D_GC_FEAT_BYTE_WRITE_2D(r)   (((r) & BM_GPU3D_GC_FEAT_BYTE_WRITE_2D) >> BP_GPU3D_GC_FEAT_BYTE_WRITE_2D)


/* --- Register HW_GPU3D_GC_FEAT, field NO_SCALER[20] (RO)
 *
 * IP does not have 2D scaler.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_NO_SCALER      (20)      //!< Bit position for GPU3D_GC_FEAT_NO_SCALER.
#define BM_GPU3D_GC_FEAT_NO_SCALER      (0x00100000)  //!< Bit mask for GPU3D_GC_FEAT_NO_SCALER.

//! @brief Get value of GPU3D_GC_FEAT_NO_SCALER from a register value.
#define BG_GPU3D_GC_FEAT_NO_SCALER(r)   (((r) & BM_GPU3D_GC_FEAT_NO_SCALER) >> BP_GPU3D_GC_FEAT_NO_SCALER)


/* --- Register HW_GPU3D_GC_FEAT, field YUY2_AVERAGING[21] (RO)
 *
 * YUY2 averaging support in resolve.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_YUY2_AVERAGING      (21)      //!< Bit position for GPU3D_GC_FEAT_YUY2_AVERAGING.
#define BM_GPU3D_GC_FEAT_YUY2_AVERAGING      (0x00200000)  //!< Bit mask for GPU3D_GC_FEAT_YUY2_AVERAGING.

//! @brief Get value of GPU3D_GC_FEAT_YUY2_AVERAGING from a register value.
#define BG_GPU3D_GC_FEAT_YUY2_AVERAGING(r)   (((r) & BM_GPU3D_GC_FEAT_YUY2_AVERAGING) >> BP_GPU3D_GC_FEAT_YUY2_AVERAGING)


/* --- Register HW_GPU3D_GC_FEAT, field HALF_PE_CACHE[22] (RO)
 *
 * PE cache is half.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_HALF_PE_CACHE      (22)      //!< Bit position for GPU3D_GC_FEAT_HALF_PE_CACHE.
#define BM_GPU3D_GC_FEAT_HALF_PE_CACHE      (0x00400000)  //!< Bit mask for GPU3D_GC_FEAT_HALF_PE_CACHE.

//! @brief Get value of GPU3D_GC_FEAT_HALF_PE_CACHE from a register value.
#define BG_GPU3D_GC_FEAT_HALF_PE_CACHE(r)   (((r) & BM_GPU3D_GC_FEAT_HALF_PE_CACHE) >> BP_GPU3D_GC_FEAT_HALF_PE_CACHE)


/* --- Register HW_GPU3D_GC_FEAT, field HALF_TX_CACHE[23] (RO)
 *
 * TX cache is half.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_HALF_TX_CACHE      (23)      //!< Bit position for GPU3D_GC_FEAT_HALF_TX_CACHE.
#define BM_GPU3D_GC_FEAT_HALF_TX_CACHE      (0x00800000)  //!< Bit mask for GPU3D_GC_FEAT_HALF_TX_CACHE.

//! @brief Get value of GPU3D_GC_FEAT_HALF_TX_CACHE from a register value.
#define BG_GPU3D_GC_FEAT_HALF_TX_CACHE(r)   (((r) & BM_GPU3D_GC_FEAT_HALF_TX_CACHE) >> BP_GPU3D_GC_FEAT_HALF_TX_CACHE)


/* --- Register HW_GPU3D_GC_FEAT, field YUY2_RENDER_TARGET[24] (RO)
 *
 * YUY2 support in PE and YUY2 to RGB conversion in resolve.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_YUY2_RENDER_TARGET      (24)      //!< Bit position for GPU3D_GC_FEAT_YUY2_RENDER_TARGET.
#define BM_GPU3D_GC_FEAT_YUY2_RENDER_TARGET      (0x01000000)  //!< Bit mask for GPU3D_GC_FEAT_YUY2_RENDER_TARGET.

//! @brief Get value of GPU3D_GC_FEAT_YUY2_RENDER_TARGET from a register value.
#define BG_GPU3D_GC_FEAT_YUY2_RENDER_TARGET(r)   (((r) & BM_GPU3D_GC_FEAT_YUY2_RENDER_TARGET) >> BP_GPU3D_GC_FEAT_YUY2_RENDER_TARGET)


/* --- Register HW_GPU3D_GC_FEAT, field MEM32_BIT_SUPPORT[25] (RO)
 *
 * 32 bit memory address support.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT      (25)      //!< Bit position for GPU3D_GC_FEAT_MEM32_BIT_SUPPORT.
#define BM_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT      (0x02000000)  //!< Bit mask for GPU3D_GC_FEAT_MEM32_BIT_SUPPORT.

//! @brief Get value of GPU3D_GC_FEAT_MEM32_BIT_SUPPORT from a register value.
#define BG_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT(r)   (((r) & BM_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT) >> BP_GPU3D_GC_FEAT_MEM32_BIT_SUPPORT)


/* --- Register HW_GPU3D_GC_FEAT, field PIPE_VG[26] (RO)
 *
 * VCG pipe is present.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_PIPE_VG      (26)      //!< Bit position for GPU3D_GC_FEAT_PIPE_VG.
#define BM_GPU3D_GC_FEAT_PIPE_VG      (0x04000000)  //!< Bit mask for GPU3D_GC_FEAT_PIPE_VG.

//! @brief Get value of GPU3D_GC_FEAT_PIPE_VG from a register value.
#define BG_GPU3D_GC_FEAT_PIPE_VG(r)   (((r) & BM_GPU3D_GC_FEAT_PIPE_VG) >> BP_GPU3D_GC_FEAT_PIPE_VG)


/* --- Register HW_GPU3D_GC_FEAT, field VGTS[27] (RO)
 *
 * VG tessellator is present.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_VGTS      (27)      //!< Bit position for GPU3D_GC_FEAT_VGTS.
#define BM_GPU3D_GC_FEAT_VGTS      (0x08000000)  //!< Bit mask for GPU3D_GC_FEAT_VGTS.

//! @brief Get value of GPU3D_GC_FEAT_VGTS from a register value.
#define BG_GPU3D_GC_FEAT_VGTS(r)   (((r) & BM_GPU3D_GC_FEAT_VGTS) >> BP_GPU3D_GC_FEAT_VGTS)


/* --- Register HW_GPU3D_GC_FEAT, field FE20[28] (RO)
 *
 * FE 2.0 is present.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_FE20      (28)      //!< Bit position for GPU3D_GC_FEAT_FE20.
#define BM_GPU3D_GC_FEAT_FE20      (0x10000000)  //!< Bit mask for GPU3D_GC_FEAT_FE20.

//! @brief Get value of GPU3D_GC_FEAT_FE20 from a register value.
#define BG_GPU3D_GC_FEAT_FE20(r)   (((r) & BM_GPU3D_GC_FEAT_FE20) >> BP_GPU3D_GC_FEAT_FE20)


/* --- Register HW_GPU3D_GC_FEAT, field BYTE_WRITE_3D[29] (RO)
 *
 * 3D PE has byte write capability.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_BYTE_WRITE_3D      (29)      //!< Bit position for GPU3D_GC_FEAT_BYTE_WRITE_3D.
#define BM_GPU3D_GC_FEAT_BYTE_WRITE_3D      (0x20000000)  //!< Bit mask for GPU3D_GC_FEAT_BYTE_WRITE_3D.

//! @brief Get value of GPU3D_GC_FEAT_BYTE_WRITE_3D from a register value.
#define BG_GPU3D_GC_FEAT_BYTE_WRITE_3D(r)   (((r) & BM_GPU3D_GC_FEAT_BYTE_WRITE_3D) >> BP_GPU3D_GC_FEAT_BYTE_WRITE_3D)


/* --- Register HW_GPU3D_GC_FEAT, field RS_YUV_TARGET[30] (RO)
 *
 * Supports resolving into YUV target.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_RS_YUV_TARGET      (30)      //!< Bit position for GPU3D_GC_FEAT_RS_YUV_TARGET.
#define BM_GPU3D_GC_FEAT_RS_YUV_TARGET      (0x40000000)  //!< Bit mask for GPU3D_GC_FEAT_RS_YUV_TARGET.

//! @brief Get value of GPU3D_GC_FEAT_RS_YUV_TARGET from a register value.
#define BG_GPU3D_GC_FEAT_RS_YUV_TARGET(r)   (((r) & BM_GPU3D_GC_FEAT_RS_YUV_TARGET) >> BP_GPU3D_GC_FEAT_RS_YUV_TARGET)


/* --- Register HW_GPU3D_GC_FEAT, field FE20_BIT_INDEX[31] (RO)
 *
 * Supports 20 bit index.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GC_FEAT_FE20_BIT_INDEX      (31)      //!< Bit position for GPU3D_GC_FEAT_FE20_BIT_INDEX.
#define BM_GPU3D_GC_FEAT_FE20_BIT_INDEX      (0x80000000)  //!< Bit mask for GPU3D_GC_FEAT_FE20_BIT_INDEX.

//! @brief Get value of GPU3D_GC_FEAT_FE20_BIT_INDEX from a register value.
#define BG_GPU3D_GC_FEAT_FE20_BIT_INDEX(r)   (((r) & BM_GPU3D_GC_FEAT_FE20_BIT_INDEX) >> BP_GPU3D_GC_FEAT_FE20_BIT_INDEX)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCC_ID - GCChipId (RO)
 *
 * Reset value: 0x00000000
 *
 * Shows the ID for the chip in SBCD. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union _hw_gpu3d_gcc_id
{
    reg32_t U;
    struct _hw_gpu3d_gcc_id_bitfields
    {
        unsigned ID : 32; //!< [31:0] Id
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
#endif

/*
 * constants & macros for individual GPU3D_GCC_ID bitfields
 */

/* --- Register HW_GPU3D_GCC_ID, field ID[31:0] (RO)
 *
 * Id
 */

#define BP_GPU3D_GCC_ID_ID      (0)      //!< Bit position for GPU3D_GCC_ID_ID.
#define BM_GPU3D_GCC_ID_ID      (0xffffffff)  //!< Bit mask for GPU3D_GCC_ID_ID.

//! @brief Get value of GPU3D_GCC_ID_ID from a register value.
#define BG_GPU3D_GCC_ID_ID(r)   (((r) & BM_GPU3D_GCC_ID_ID) >> BP_GPU3D_GCC_ID_ID)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCC_REV - GCChipRev (RO)
 *
 * Reset value: 0x00000000
 *
 * Shows the revision for the chip in BCD. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union _hw_gpu3d_gcc_rev
{
    reg32_t U;
    struct _hw_gpu3d_gcc_rev_bitfields
    {
        unsigned REV : 32; //!< [31:0] Revision
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
#endif

/*
 * constants & macros for individual GPU3D_GCC_REV bitfields
 */

/* --- Register HW_GPU3D_GCC_REV, field REV[31:0] (RO)
 *
 * Revision
 */

#define BP_GPU3D_GCC_REV_REV      (0)      //!< Bit position for GPU3D_GCC_REV_REV.
#define BM_GPU3D_GCC_REV_REV      (0xffffffff)  //!< Bit mask for GPU3D_GCC_REV_REV.

//! @brief Get value of GPU3D_GCC_REV_REV from a register value.
#define BG_GPU3D_GCC_REV_REV(r)   (((r) & BM_GPU3D_GCC_REV_REV) >> BP_GPU3D_GCC_REV_REV)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCC_DATE - GCChipDate (RO)
 *
 * Reset value: 0x00000000
 *
 * Shows the release date for the IP. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union _hw_gpu3d_gcc_date
{
    reg32_t U;
    struct _hw_gpu3d_gcc_date_bitfields
    {
        unsigned DATE : 32; //!< [31:0] Date
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
#endif

/*
 * constants & macros for individual GPU3D_GCC_DATE bitfields
 */

/* --- Register HW_GPU3D_GCC_DATE, field DATE[31:0] (RO)
 *
 * Date
 */

#define BP_GPU3D_GCC_DATE_DATE      (0)      //!< Bit position for GPU3D_GCC_DATE_DATE.
#define BM_GPU3D_GCC_DATE_DATE      (0xffffffff)  //!< Bit mask for GPU3D_GCC_DATE_DATE.

//! @brief Get value of GPU3D_GCC_DATE_DATE from a register value.
#define BG_GPU3D_GCC_DATE_DATE(r)   (((r) & BM_GPU3D_GCC_DATE_DATE) >> BP_GPU3D_GCC_DATE_DATE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCC_TIME - GCChipTime (RO)
 *
 * Reset value: 0x00000000
 *
 * Shows the release time for the IP. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union _hw_gpu3d_gcc_time
{
    reg32_t U;
    struct _hw_gpu3d_gcc_time_bitfields
    {
        unsigned TIME : 32; //!< [31:0] Time
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
#endif

/*
 * constants & macros for individual GPU3D_GCC_TIME bitfields
 */

/* --- Register HW_GPU3D_GCC_TIME, field TIME[31:0] (RO)
 *
 * Time
 */

#define BP_GPU3D_GCC_TIME_TIME      (0)      //!< Bit position for GPU3D_GCC_TIME_TIME.
#define BM_GPU3D_GCC_TIME_TIME      (0xffffffff)  //!< Bit mask for GPU3D_GCC_TIME_TIME.

//! @brief Get value of GPU3D_GCC_TIME_TIME from a register value.
#define BG_GPU3D_GCC_TIME_TIME(r)   (((r) & BM_GPU3D_GCC_TIME_TIME) >> BP_GPU3D_GCC_TIME_TIME)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCC_CUST - GCChipCustomer (RO)
 *
 * Reset value: 0x00000000
 *
 * Shows the customer and group for the IP. This register has no set reset value. It varies with the
 * implementation.
 */
typedef union _hw_gpu3d_gcc_cust
{
    reg32_t U;
    struct _hw_gpu3d_gcc_cust_bitfields
    {
        unsigned GROUP : 16; //!< [15:0] Group
        unsigned COMPANY : 16; //!< [31:16] Company
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
#endif

/*
 * constants & macros for individual GPU3D_GCC_CUST bitfields
 */

/* --- Register HW_GPU3D_GCC_CUST, field GROUP[15:0] (RO)
 *
 * Group
 */

#define BP_GPU3D_GCC_CUST_GROUP      (0)      //!< Bit position for GPU3D_GCC_CUST_GROUP.
#define BM_GPU3D_GCC_CUST_GROUP      (0x0000ffff)  //!< Bit mask for GPU3D_GCC_CUST_GROUP.

//! @brief Get value of GPU3D_GCC_CUST_GROUP from a register value.
#define BG_GPU3D_GCC_CUST_GROUP(r)   (((r) & BM_GPU3D_GCC_CUST_GROUP) >> BP_GPU3D_GCC_CUST_GROUP)

/* --- Register HW_GPU3D_GCC_CUST, field COMPANY[31:16] (RO)
 *
 * Company
 */

#define BP_GPU3D_GCC_CUST_COMPANY      (16)      //!< Bit position for GPU3D_GCC_CUST_COMPANY.
#define BM_GPU3D_GCC_CUST_COMPANY      (0xffff0000)  //!< Bit mask for GPU3D_GCC_CUST_COMPANY.

//! @brief Get value of GPU3D_GCC_CUST_COMPANY from a register value.
#define BG_GPU3D_GCC_CUST_COMPANY(r)   (((r) & BM_GPU3D_GCC_CUST_COMPANY) >> BP_GPU3D_GCC_CUST_COMPANY)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCM_FEAT_0 - GCMinorFeatures0 (RO)
 *
 * Reset value: 0x00000000
 *
 * Shows which minor features are enabled in this chip. This register has no set reset value. It
 * varies with the implementation.
 */
typedef union _hw_gpu3d_gcm_feat_0
{
    reg32_t U;
    struct _hw_gpu3d_gcm_feat_0_bitfields
    {
        unsigned FLIP_Y : 1; //!< [0] Y flipping capability is added to resolve.
        unsigned DUAL_RETURN_BUS : 1; //!< [1] Dual Return Bus from HI to clients.
        unsigned ENDIANNESS_CONFIG : 1; //!< [2] Configurable endianness support.
        unsigned TESTURE8_K : 1; //!< [3] Supports 8Kx8K textures.
        unsigned CORRECT_TEXTURE_CONVERTER : 1; //!< [4] Driver hack is not needed.
        unsigned SPECIAL_MSAA_LOD : 1; //!< [5] Special LOD calculation when MSAA is on.
        unsigned FAST_CLEAR_FLUSH : 1; //!< [6] Proper flush is done in fast clear cache.
        unsigned _2DPE20 : 1; //!< [7] 2D PE 2.0 is present.
        unsigned CORRECT_AUTO_DISABLE : 1; //!< [8] Auto disable in FC is correct.
        unsigned RENDER_8K : 1; //!< [9] Supports 8K render target.
        unsigned TILE_STATUS_2BITS : 1; //!< [10] 2 bits are used instead of 4 bits for tile status.
        unsigned SEPARATE_TILE_STATUS_WHEN_INTERLEAVED : 1; //!< [11] Use 2 separate tile status buffers in interleaved mode.
        unsigned SUPER_TILED_32X32 : 1; //!< [12] 32x32 super tile is available.
        unsigned VG_20 : 1; //!< [13] Major updates to VG pipe (TS buffer tiling. State masking.).
        unsigned TS_EXTENDED_COMMANDS : 1; //!< [14] New commands added to the tessellator.
        unsigned COMPRESSION_FIFO_FIXED : 1; //!< [15] If this bit is not set, the FIFO counter should be set to 50. Else, the default should remain.
        unsigned EXTRA_SHADER_INSTRUCTIONS0 : 1; //!< [16] Floor, ceil, and sign instructions are available.
        unsigned VG_FILTER : 1; //!< [17] VG filter is available.
        unsigned VG_21 : 1; //!< [18] Minor updates to VG pipe (Event generation from VG, TS, PE). Tiled image support.
        unsigned SHADER_GETS_W : 1; //!< [19] W is sent to SH from RA.
        unsigned EXTRA_SHADER_INSTRUCTIONS1 : 1; //!< [20] Sqrt, sin, cos intructions are available.
        unsigned DEFAULT_REG0 : 1; //!< [21] Unavailable registers will return 0.
        unsigned MC_20 : 1; //!< [22] New stlye MC with separate paths for color and depth.
        unsigned SHADER_MSAA_SIDEBAND : 1; //!< [23] Put the MSAA data into sideband fifo.
        unsigned BUG_FIXES0 : 1; //!< [24] 
        unsigned VAA : 1; //!< [25] VAA is available or not.
        unsigned BYPASS_IN_MSAA : 1; //!< [26] Shader supports bypass modew when MSAA is enabled.
        unsigned HIERARCHICAL_Z : 1; //!< [27] Hierarchical Z is supported.
        unsigned NEW_TEXTURE : 1; //!< [28] New texture unit is available.
        unsigned A8_TARGET_SUPPORT : 1; //!< [29] 2D engine supports A8 target.
        unsigned CORRECT_STENCIL : 1; //!< [30] Correct stencil behavior in depth only.
        unsigned ENHANCE_VR : 1; //!< [31] Enhance VR and add a mode to walk 16 pixels in 16-bit mode in Vertical pass to improve $ hit rate when rotating 90/270.
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
#endif

/*
 * constants & macros for individual GPU3D_GCM_FEAT_0 bitfields
 */

/* --- Register HW_GPU3D_GCM_FEAT_0, field FLIP_Y[0] (RO)
 *
 * Y flipping capability is added to resolve.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_FLIP_Y      (0)      //!< Bit position for GPU3D_GCM_FEAT_0_FLIP_Y.
#define BM_GPU3D_GCM_FEAT_0_FLIP_Y      (0x00000001)  //!< Bit mask for GPU3D_GCM_FEAT_0_FLIP_Y.

//! @brief Get value of GPU3D_GCM_FEAT_0_FLIP_Y from a register value.
#define BG_GPU3D_GCM_FEAT_0_FLIP_Y(r)   (((r) & BM_GPU3D_GCM_FEAT_0_FLIP_Y) >> BP_GPU3D_GCM_FEAT_0_FLIP_Y)


/* --- Register HW_GPU3D_GCM_FEAT_0, field DUAL_RETURN_BUS[1] (RO)
 *
 * Dual Return Bus from HI to clients.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS      (1)      //!< Bit position for GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS.
#define BM_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS      (0x00000002)  //!< Bit mask for GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS.

//! @brief Get value of GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS from a register value.
#define BG_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS(r)   (((r) & BM_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS) >> BP_GPU3D_GCM_FEAT_0_DUAL_RETURN_BUS)


/* --- Register HW_GPU3D_GCM_FEAT_0, field ENDIANNESS_CONFIG[2] (RO)
 *
 * Configurable endianness support.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG      (2)      //!< Bit position for GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG.
#define BM_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG      (0x00000004)  //!< Bit mask for GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG.

//! @brief Get value of GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG from a register value.
#define BG_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG(r)   (((r) & BM_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG) >> BP_GPU3D_GCM_FEAT_0_ENDIANNESS_CONFIG)


/* --- Register HW_GPU3D_GCM_FEAT_0, field TESTURE8_K[3] (RO)
 *
 * Supports 8Kx8K textures.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_TESTURE8_K      (3)      //!< Bit position for GPU3D_GCM_FEAT_0_TESTURE8_K.
#define BM_GPU3D_GCM_FEAT_0_TESTURE8_K      (0x00000008)  //!< Bit mask for GPU3D_GCM_FEAT_0_TESTURE8_K.

//! @brief Get value of GPU3D_GCM_FEAT_0_TESTURE8_K from a register value.
#define BG_GPU3D_GCM_FEAT_0_TESTURE8_K(r)   (((r) & BM_GPU3D_GCM_FEAT_0_TESTURE8_K) >> BP_GPU3D_GCM_FEAT_0_TESTURE8_K)


/* --- Register HW_GPU3D_GCM_FEAT_0, field CORRECT_TEXTURE_CONVERTER[4] (RO)
 *
 * Driver hack is not needed.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER      (4)      //!< Bit position for GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER.
#define BM_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER      (0x00000010)  //!< Bit mask for GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER.

//! @brief Get value of GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER from a register value.
#define BG_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER(r)   (((r) & BM_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER) >> BP_GPU3D_GCM_FEAT_0_CORRECT_TEXTURE_CONVERTER)


/* --- Register HW_GPU3D_GCM_FEAT_0, field SPECIAL_MSAA_LOD[5] (RO)
 *
 * Special LOD calculation when MSAA is on.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD      (5)      //!< Bit position for GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD.
#define BM_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD      (0x00000020)  //!< Bit mask for GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD.

//! @brief Get value of GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD from a register value.
#define BG_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD(r)   (((r) & BM_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD) >> BP_GPU3D_GCM_FEAT_0_SPECIAL_MSAA_LOD)


/* --- Register HW_GPU3D_GCM_FEAT_0, field FAST_CLEAR_FLUSH[6] (RO)
 *
 * Proper flush is done in fast clear cache.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH      (6)      //!< Bit position for GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH.
#define BM_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH      (0x00000040)  //!< Bit mask for GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH.

//! @brief Get value of GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH from a register value.
#define BG_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH(r)   (((r) & BM_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH) >> BP_GPU3D_GCM_FEAT_0_FAST_CLEAR_FLUSH)


/* --- Register HW_GPU3D_GCM_FEAT_0, field _2DPE20[7] (RO)
 *
 * 2D PE 2.0 is present.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0__2DPE20      (7)      //!< Bit position for GPU3D_GCM_FEAT_0__2DPE20.
#define BM_GPU3D_GCM_FEAT_0__2DPE20      (0x00000080)  //!< Bit mask for GPU3D_GCM_FEAT_0__2DPE20.

//! @brief Get value of GPU3D_GCM_FEAT_0__2DPE20 from a register value.
#define BG_GPU3D_GCM_FEAT_0__2DPE20(r)   (((r) & BM_GPU3D_GCM_FEAT_0__2DPE20) >> BP_GPU3D_GCM_FEAT_0__2DPE20)


/* --- Register HW_GPU3D_GCM_FEAT_0, field CORRECT_AUTO_DISABLE[8] (RO)
 *
 * Auto disable in FC is correct.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE      (8)      //!< Bit position for GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE.
#define BM_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE      (0x00000100)  //!< Bit mask for GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE.

//! @brief Get value of GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE from a register value.
#define BG_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE(r)   (((r) & BM_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE) >> BP_GPU3D_GCM_FEAT_0_CORRECT_AUTO_DISABLE)


/* --- Register HW_GPU3D_GCM_FEAT_0, field RENDER_8K[9] (RO)
 *
 * Supports 8K render target.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_RENDER_8K      (9)      //!< Bit position for GPU3D_GCM_FEAT_0_RENDER_8K.
#define BM_GPU3D_GCM_FEAT_0_RENDER_8K      (0x00000200)  //!< Bit mask for GPU3D_GCM_FEAT_0_RENDER_8K.

//! @brief Get value of GPU3D_GCM_FEAT_0_RENDER_8K from a register value.
#define BG_GPU3D_GCM_FEAT_0_RENDER_8K(r)   (((r) & BM_GPU3D_GCM_FEAT_0_RENDER_8K) >> BP_GPU3D_GCM_FEAT_0_RENDER_8K)


/* --- Register HW_GPU3D_GCM_FEAT_0, field TILE_STATUS_2BITS[10] (RO)
 *
 * 2 bits are used instead of 4 bits for tile status.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS      (10)      //!< Bit position for GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS.
#define BM_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS      (0x00000400)  //!< Bit mask for GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS.

//! @brief Get value of GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS from a register value.
#define BG_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS(r)   (((r) & BM_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS) >> BP_GPU3D_GCM_FEAT_0_TILE_STATUS_2BITS)


/* --- Register HW_GPU3D_GCM_FEAT_0, field SEPARATE_TILE_STATUS_WHEN_INTERLEAVED[11] (RO)
 *
 * Use 2 separate tile status buffers in interleaved mode.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED      (11)      //!< Bit position for GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED.
#define BM_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED      (0x00000800)  //!< Bit mask for GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED.

//! @brief Get value of GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED from a register value.
#define BG_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED(r)   (((r) & BM_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED) >> BP_GPU3D_GCM_FEAT_0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED)


/* --- Register HW_GPU3D_GCM_FEAT_0, field SUPER_TILED_32X32[12] (RO)
 *
 * 32x32 super tile is available.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32      (12)      //!< Bit position for GPU3D_GCM_FEAT_0_SUPER_TILED_32X32.
#define BM_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32      (0x00001000)  //!< Bit mask for GPU3D_GCM_FEAT_0_SUPER_TILED_32X32.

//! @brief Get value of GPU3D_GCM_FEAT_0_SUPER_TILED_32X32 from a register value.
#define BG_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32(r)   (((r) & BM_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32) >> BP_GPU3D_GCM_FEAT_0_SUPER_TILED_32X32)


/* --- Register HW_GPU3D_GCM_FEAT_0, field VG_20[13] (RO)
 *
 * Major updates to VG pipe (TS buffer tiling. State masking.).
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_VG_20      (13)      //!< Bit position for GPU3D_GCM_FEAT_0_VG_20.
#define BM_GPU3D_GCM_FEAT_0_VG_20      (0x00002000)  //!< Bit mask for GPU3D_GCM_FEAT_0_VG_20.

//! @brief Get value of GPU3D_GCM_FEAT_0_VG_20 from a register value.
#define BG_GPU3D_GCM_FEAT_0_VG_20(r)   (((r) & BM_GPU3D_GCM_FEAT_0_VG_20) >> BP_GPU3D_GCM_FEAT_0_VG_20)


/* --- Register HW_GPU3D_GCM_FEAT_0, field TS_EXTENDED_COMMANDS[14] (RO)
 *
 * New commands added to the tessellator.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS      (14)      //!< Bit position for GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS.
#define BM_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS      (0x00004000)  //!< Bit mask for GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS.

//! @brief Get value of GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS from a register value.
#define BG_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS(r)   (((r) & BM_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS) >> BP_GPU3D_GCM_FEAT_0_TS_EXTENDED_COMMANDS)


/* --- Register HW_GPU3D_GCM_FEAT_0, field COMPRESSION_FIFO_FIXED[15] (RO)
 *
 * If this bit is not set, the FIFO counter should be set to 50. Else, the default should remain.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED      (15)      //!< Bit position for GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED.
#define BM_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED      (0x00008000)  //!< Bit mask for GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED.

//! @brief Get value of GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED from a register value.
#define BG_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED(r)   (((r) & BM_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED) >> BP_GPU3D_GCM_FEAT_0_COMPRESSION_FIFO_FIXED)


/* --- Register HW_GPU3D_GCM_FEAT_0, field EXTRA_SHADER_INSTRUCTIONS0[16] (RO)
 *
 * Floor, ceil, and sign instructions are available.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0      (16)      //!< Bit position for GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0.
#define BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0      (0x00010000)  //!< Bit mask for GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0.

//! @brief Get value of GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0 from a register value.
#define BG_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0(r)   (((r) & BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0) >> BP_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS0)


/* --- Register HW_GPU3D_GCM_FEAT_0, field VG_FILTER[17] (RO)
 *
 * VG filter is available.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_VG_FILTER      (17)      //!< Bit position for GPU3D_GCM_FEAT_0_VG_FILTER.
#define BM_GPU3D_GCM_FEAT_0_VG_FILTER      (0x00020000)  //!< Bit mask for GPU3D_GCM_FEAT_0_VG_FILTER.

//! @brief Get value of GPU3D_GCM_FEAT_0_VG_FILTER from a register value.
#define BG_GPU3D_GCM_FEAT_0_VG_FILTER(r)   (((r) & BM_GPU3D_GCM_FEAT_0_VG_FILTER) >> BP_GPU3D_GCM_FEAT_0_VG_FILTER)


/* --- Register HW_GPU3D_GCM_FEAT_0, field VG_21[18] (RO)
 *
 * Minor updates to VG pipe (Event generation from VG, TS, PE). Tiled image support.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_VG_21      (18)      //!< Bit position for GPU3D_GCM_FEAT_0_VG_21.
#define BM_GPU3D_GCM_FEAT_0_VG_21      (0x00040000)  //!< Bit mask for GPU3D_GCM_FEAT_0_VG_21.

//! @brief Get value of GPU3D_GCM_FEAT_0_VG_21 from a register value.
#define BG_GPU3D_GCM_FEAT_0_VG_21(r)   (((r) & BM_GPU3D_GCM_FEAT_0_VG_21) >> BP_GPU3D_GCM_FEAT_0_VG_21)


/* --- Register HW_GPU3D_GCM_FEAT_0, field SHADER_GETS_W[19] (RO)
 *
 * W is sent to SH from RA.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_SHADER_GETS_W      (19)      //!< Bit position for GPU3D_GCM_FEAT_0_SHADER_GETS_W.
#define BM_GPU3D_GCM_FEAT_0_SHADER_GETS_W      (0x00080000)  //!< Bit mask for GPU3D_GCM_FEAT_0_SHADER_GETS_W.

//! @brief Get value of GPU3D_GCM_FEAT_0_SHADER_GETS_W from a register value.
#define BG_GPU3D_GCM_FEAT_0_SHADER_GETS_W(r)   (((r) & BM_GPU3D_GCM_FEAT_0_SHADER_GETS_W) >> BP_GPU3D_GCM_FEAT_0_SHADER_GETS_W)


/* --- Register HW_GPU3D_GCM_FEAT_0, field EXTRA_SHADER_INSTRUCTIONS1[20] (RO)
 *
 * Sqrt, sin, cos intructions are available.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1      (20)      //!< Bit position for GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1.
#define BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1      (0x00100000)  //!< Bit mask for GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1.

//! @brief Get value of GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1 from a register value.
#define BG_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1(r)   (((r) & BM_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1) >> BP_GPU3D_GCM_FEAT_0_EXTRA_SHADER_INSTRUCTIONS1)


/* --- Register HW_GPU3D_GCM_FEAT_0, field DEFAULT_REG0[21] (RO)
 *
 * Unavailable registers will return 0.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_DEFAULT_REG0      (21)      //!< Bit position for GPU3D_GCM_FEAT_0_DEFAULT_REG0.
#define BM_GPU3D_GCM_FEAT_0_DEFAULT_REG0      (0x00200000)  //!< Bit mask for GPU3D_GCM_FEAT_0_DEFAULT_REG0.

//! @brief Get value of GPU3D_GCM_FEAT_0_DEFAULT_REG0 from a register value.
#define BG_GPU3D_GCM_FEAT_0_DEFAULT_REG0(r)   (((r) & BM_GPU3D_GCM_FEAT_0_DEFAULT_REG0) >> BP_GPU3D_GCM_FEAT_0_DEFAULT_REG0)


/* --- Register HW_GPU3D_GCM_FEAT_0, field MC_20[22] (RO)
 *
 * New stlye MC with separate paths for color and depth.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_MC_20      (22)      //!< Bit position for GPU3D_GCM_FEAT_0_MC_20.
#define BM_GPU3D_GCM_FEAT_0_MC_20      (0x00400000)  //!< Bit mask for GPU3D_GCM_FEAT_0_MC_20.

//! @brief Get value of GPU3D_GCM_FEAT_0_MC_20 from a register value.
#define BG_GPU3D_GCM_FEAT_0_MC_20(r)   (((r) & BM_GPU3D_GCM_FEAT_0_MC_20) >> BP_GPU3D_GCM_FEAT_0_MC_20)


/* --- Register HW_GPU3D_GCM_FEAT_0, field SHADER_MSAA_SIDEBAND[23] (RO)
 *
 * Put the MSAA data into sideband fifo.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND      (23)      //!< Bit position for GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND.
#define BM_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND      (0x00800000)  //!< Bit mask for GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND.

//! @brief Get value of GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND from a register value.
#define BG_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND(r)   (((r) & BM_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND) >> BP_GPU3D_GCM_FEAT_0_SHADER_MSAA_SIDEBAND)


/* --- Register HW_GPU3D_GCM_FEAT_0, field BUG_FIXES0[24] (RO)
 *

 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_BUG_FIXES0      (24)      //!< Bit position for GPU3D_GCM_FEAT_0_BUG_FIXES0.
#define BM_GPU3D_GCM_FEAT_0_BUG_FIXES0      (0x01000000)  //!< Bit mask for GPU3D_GCM_FEAT_0_BUG_FIXES0.

//! @brief Get value of GPU3D_GCM_FEAT_0_BUG_FIXES0 from a register value.
#define BG_GPU3D_GCM_FEAT_0_BUG_FIXES0(r)   (((r) & BM_GPU3D_GCM_FEAT_0_BUG_FIXES0) >> BP_GPU3D_GCM_FEAT_0_BUG_FIXES0)


/* --- Register HW_GPU3D_GCM_FEAT_0, field VAA[25] (RO)
 *
 * VAA is available or not.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_VAA      (25)      //!< Bit position for GPU3D_GCM_FEAT_0_VAA.
#define BM_GPU3D_GCM_FEAT_0_VAA      (0x02000000)  //!< Bit mask for GPU3D_GCM_FEAT_0_VAA.

//! @brief Get value of GPU3D_GCM_FEAT_0_VAA from a register value.
#define BG_GPU3D_GCM_FEAT_0_VAA(r)   (((r) & BM_GPU3D_GCM_FEAT_0_VAA) >> BP_GPU3D_GCM_FEAT_0_VAA)


/* --- Register HW_GPU3D_GCM_FEAT_0, field BYPASS_IN_MSAA[26] (RO)
 *
 * Shader supports bypass modew when MSAA is enabled.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA      (26)      //!< Bit position for GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA.
#define BM_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA      (0x04000000)  //!< Bit mask for GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA.

//! @brief Get value of GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA from a register value.
#define BG_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA(r)   (((r) & BM_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA) >> BP_GPU3D_GCM_FEAT_0_BYPASS_IN_MSAA)


/* --- Register HW_GPU3D_GCM_FEAT_0, field HIERARCHICAL_Z[27] (RO)
 *
 * Hierarchical Z is supported.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z      (27)      //!< Bit position for GPU3D_GCM_FEAT_0_HIERARCHICAL_Z.
#define BM_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z      (0x08000000)  //!< Bit mask for GPU3D_GCM_FEAT_0_HIERARCHICAL_Z.

//! @brief Get value of GPU3D_GCM_FEAT_0_HIERARCHICAL_Z from a register value.
#define BG_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z(r)   (((r) & BM_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z) >> BP_GPU3D_GCM_FEAT_0_HIERARCHICAL_Z)


/* --- Register HW_GPU3D_GCM_FEAT_0, field NEW_TEXTURE[28] (RO)
 *
 * New texture unit is available.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_NEW_TEXTURE      (28)      //!< Bit position for GPU3D_GCM_FEAT_0_NEW_TEXTURE.
#define BM_GPU3D_GCM_FEAT_0_NEW_TEXTURE      (0x10000000)  //!< Bit mask for GPU3D_GCM_FEAT_0_NEW_TEXTURE.

//! @brief Get value of GPU3D_GCM_FEAT_0_NEW_TEXTURE from a register value.
#define BG_GPU3D_GCM_FEAT_0_NEW_TEXTURE(r)   (((r) & BM_GPU3D_GCM_FEAT_0_NEW_TEXTURE) >> BP_GPU3D_GCM_FEAT_0_NEW_TEXTURE)


/* --- Register HW_GPU3D_GCM_FEAT_0, field A8_TARGET_SUPPORT[29] (RO)
 *
 * 2D engine supports A8 target.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT      (29)      //!< Bit position for GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT.
#define BM_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT      (0x20000000)  //!< Bit mask for GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT.

//! @brief Get value of GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT from a register value.
#define BG_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT(r)   (((r) & BM_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT) >> BP_GPU3D_GCM_FEAT_0_A8_TARGET_SUPPORT)


/* --- Register HW_GPU3D_GCM_FEAT_0, field CORRECT_STENCIL[30] (RO)
 *
 * Correct stencil behavior in depth only.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_CORRECT_STENCIL      (30)      //!< Bit position for GPU3D_GCM_FEAT_0_CORRECT_STENCIL.
#define BM_GPU3D_GCM_FEAT_0_CORRECT_STENCIL      (0x40000000)  //!< Bit mask for GPU3D_GCM_FEAT_0_CORRECT_STENCIL.

//! @brief Get value of GPU3D_GCM_FEAT_0_CORRECT_STENCIL from a register value.
#define BG_GPU3D_GCM_FEAT_0_CORRECT_STENCIL(r)   (((r) & BM_GPU3D_GCM_FEAT_0_CORRECT_STENCIL) >> BP_GPU3D_GCM_FEAT_0_CORRECT_STENCIL)


/* --- Register HW_GPU3D_GCM_FEAT_0, field ENHANCE_VR[31] (RO)
 *
 * Enhance VR and add a mode to walk 16 pixels in 16-bit mode in Vertical pass to improve $ hit rate
 * when rotating 90/270.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_0_ENHANCE_VR      (31)      //!< Bit position for GPU3D_GCM_FEAT_0_ENHANCE_VR.
#define BM_GPU3D_GCM_FEAT_0_ENHANCE_VR      (0x80000000)  //!< Bit mask for GPU3D_GCM_FEAT_0_ENHANCE_VR.

//! @brief Get value of GPU3D_GCM_FEAT_0_ENHANCE_VR from a register value.
#define BG_GPU3D_GCM_FEAT_0_ENHANCE_VR(r)   (((r) & BM_GPU3D_GCM_FEAT_0_ENHANCE_VR) >> BP_GPU3D_GCM_FEAT_0_ENHANCE_VR)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCC_CRTL - GCCacheControl (RW)
 *
 * Reset value: 0x00000000
 *
 * Not used.
 */
typedef union _hw_gpu3d_gcc_crtl
{
    reg32_t U;
    struct _hw_gpu3d_gcc_crtl_bitfields
    {
        unsigned NOT_USED : 32; //!< [31:0] 
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

/* --- Register HW_GPU3D_GCC_CRTL, field NOT_USED[31:0] (RW)
 *

 */

#define BP_GPU3D_GCC_CRTL_NOT_USED      (0)      //!< Bit position for GPU3D_GCC_CRTL_NOT_USED.
#define BM_GPU3D_GCC_CRTL_NOT_USED      (0xffffffff)  //!< Bit mask for GPU3D_GCC_CRTL_NOT_USED.

//! @brief Get value of GPU3D_GCC_CRTL_NOT_USED from a register value.
#define BG_GPU3D_GCC_CRTL_NOT_USED(r)   (((r) & BM_GPU3D_GCC_CRTL_NOT_USED) >> BP_GPU3D_GCC_CRTL_NOT_USED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_GCC_CRTL_NOT_USED.
#define BF_GPU3D_GCC_CRTL_NOT_USED(v)   ((((reg32_t) v) << BP_GPU3D_GCC_CRTL_NOT_USED) & BM_GPU3D_GCC_CRTL_NOT_USED)
#else
//! @brief Format value for bitfield GPU3D_GCC_CRTL_NOT_USED.
#define BF_GPU3D_GCC_CRTL_NOT_USED(v)   (((v) << BP_GPU3D_GCC_CRTL_NOT_USED) & BM_GPU3D_GCC_CRTL_NOT_USED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NOT_USED field to a new value.
#define BW_GPU3D_GCC_CRTL_NOT_USED(v)   (HW_GPU3D_GCC_CRTL_WR((HW_GPU3D_GCC_CRTL_RD() & ~BM_GPU3D_GCC_CRTL_NOT_USED) | BF_GPU3D_GCC_CRTL_NOT_USED(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCR_MEM_CTRS - GCResetMemCounters (RW)
 *
 * Reset value: 0x00000000
 *
 * Writing 1 will reset the counters and stop counting. Write 0 to start counting again. This
 * register is write only so it has no reset value.
 */
typedef union _hw_gpu3d_gcr_mem_ctrs
{
    reg32_t U;
    struct _hw_gpu3d_gcr_mem_ctrs_bitfields
    {
        unsigned RESET : 32; //!< [31:0] 
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

/* --- Register HW_GPU3D_GCR_MEM_CTRS, field RESET[31:0] (RW)
 *

 */

#define BP_GPU3D_GCR_MEM_CTRS_RESET      (0)      //!< Bit position for GPU3D_GCR_MEM_CTRS_RESET.
#define BM_GPU3D_GCR_MEM_CTRS_RESET      (0xffffffff)  //!< Bit mask for GPU3D_GCR_MEM_CTRS_RESET.

//! @brief Get value of GPU3D_GCR_MEM_CTRS_RESET from a register value.
#define BG_GPU3D_GCR_MEM_CTRS_RESET(r)   (((r) & BM_GPU3D_GCR_MEM_CTRS_RESET) >> BP_GPU3D_GCR_MEM_CTRS_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_GCR_MEM_CTRS_RESET.
#define BF_GPU3D_GCR_MEM_CTRS_RESET(v)   ((((reg32_t) v) << BP_GPU3D_GCR_MEM_CTRS_RESET) & BM_GPU3D_GCR_MEM_CTRS_RESET)
#else
//! @brief Format value for bitfield GPU3D_GCR_MEM_CTRS_RESET.
#define BF_GPU3D_GCR_MEM_CTRS_RESET(v)   (((v) << BP_GPU3D_GCR_MEM_CTRS_RESET) & BM_GPU3D_GCR_MEM_CTRS_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_GPU3D_GCR_MEM_CTRS_RESET(v)   (HW_GPU3D_GCR_MEM_CTRS_WR((HW_GPU3D_GCR_MEM_CTRS_RD() & ~BM_GPU3D_GCR_MEM_CTRS_RESET) | BF_GPU3D_GCR_MEM_CTRS_RESET(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_READS - gcTotalReads (RO)
 *
 * Reset value: 0x00000000
 *
 * Total reads in terms of 64 bits.
 */
typedef union _hw_gpu3d_gct_reads
{
    reg32_t U;
    struct _hw_gpu3d_gct_reads_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_GCT_READS bitfields
 */

/* --- Register HW_GPU3D_GCT_READS, field COUNT[31:0] (RO)
 *

 */

#define BP_GPU3D_GCT_READS_COUNT      (0)      //!< Bit position for GPU3D_GCT_READS_COUNT.
#define BM_GPU3D_GCT_READS_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCT_READS_COUNT.

//! @brief Get value of GPU3D_GCT_READS_COUNT from a register value.
#define BG_GPU3D_GCT_READS_COUNT(r)   (((r) & BM_GPU3D_GCT_READS_COUNT) >> BP_GPU3D_GCT_READS_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_WRITES - gcTotalWrites (RO)
 *
 * Reset value: 0x00000000
 *
 * Total writes in terms of 64 bits.
 */
typedef union _hw_gpu3d_gct_writes
{
    reg32_t U;
    struct _hw_gpu3d_gct_writes_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_GCT_WRITES bitfields
 */

/* --- Register HW_GPU3D_GCT_WRITES, field COUNT[31:0] (RO)
 *

 */

#define BP_GPU3D_GCT_WRITES_COUNT      (0)      //!< Bit position for GPU3D_GCT_WRITES_COUNT.
#define BM_GPU3D_GCT_WRITES_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCT_WRITES_COUNT.

//! @brief Get value of GPU3D_GCT_WRITES_COUNT from a register value.
#define BG_GPU3D_GCT_WRITES_COUNT(r)   (((r) & BM_GPU3D_GCT_WRITES_COUNT) >> BP_GPU3D_GCT_WRITES_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCC_SPECS - gcChipSpecs (RO)
 *
 * Reset value: 0x00000000
 *
 * Specs for the chip. This register has no set reset value. It varies with the implementation.
 */
typedef union _hw_gpu3d_gcc_specs
{
    reg32_t U;
    struct _hw_gpu3d_gcc_specs_bitfields
    {
        unsigned STREAMS : 4; //!< [3:0] Number of vertex streams.
        unsigned TEAMP_REGISTERS : 4; //!< [7:4] Log2 of temporary registers.
        unsigned THREAD_COUNT : 4; //!< [11:8] Log2 of thread count.
        unsigned VERTEX_CACHE_SIZE : 5; //!< [16:12] Number of entries in the vertex shader cache.
        unsigned RESERVED0 : 3; //!< [19:17] Reserved
        unsigned NUM_SHADER_CORES : 5; //!< [24:20] Number of shader cores.
        unsigned NUM_PIXEL_PIPES : 3; //!< [27:25] Number of pixel pipes.
        unsigned VERTEX_OUTPUT_BUFFER_SIZE : 4; //!< [31:28] Log2 of vertex output buffer size.
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
#endif

/*
 * constants & macros for individual GPU3D_GCC_SPECS bitfields
 */

/* --- Register HW_GPU3D_GCC_SPECS, field STREAMS[3:0] (RO)
 *
 * Number of vertex streams.
 */

#define BP_GPU3D_GCC_SPECS_STREAMS      (0)      //!< Bit position for GPU3D_GCC_SPECS_STREAMS.
#define BM_GPU3D_GCC_SPECS_STREAMS      (0x0000000f)  //!< Bit mask for GPU3D_GCC_SPECS_STREAMS.

//! @brief Get value of GPU3D_GCC_SPECS_STREAMS from a register value.
#define BG_GPU3D_GCC_SPECS_STREAMS(r)   (((r) & BM_GPU3D_GCC_SPECS_STREAMS) >> BP_GPU3D_GCC_SPECS_STREAMS)

/* --- Register HW_GPU3D_GCC_SPECS, field TEAMP_REGISTERS[7:4] (RO)
 *
 * Log2 of temporary registers.
 */

#define BP_GPU3D_GCC_SPECS_TEAMP_REGISTERS      (4)      //!< Bit position for GPU3D_GCC_SPECS_TEAMP_REGISTERS.
#define BM_GPU3D_GCC_SPECS_TEAMP_REGISTERS      (0x000000f0)  //!< Bit mask for GPU3D_GCC_SPECS_TEAMP_REGISTERS.

//! @brief Get value of GPU3D_GCC_SPECS_TEAMP_REGISTERS from a register value.
#define BG_GPU3D_GCC_SPECS_TEAMP_REGISTERS(r)   (((r) & BM_GPU3D_GCC_SPECS_TEAMP_REGISTERS) >> BP_GPU3D_GCC_SPECS_TEAMP_REGISTERS)

/* --- Register HW_GPU3D_GCC_SPECS, field THREAD_COUNT[11:8] (RO)
 *
 * Log2 of thread count.
 */

#define BP_GPU3D_GCC_SPECS_THREAD_COUNT      (8)      //!< Bit position for GPU3D_GCC_SPECS_THREAD_COUNT.
#define BM_GPU3D_GCC_SPECS_THREAD_COUNT      (0x00000f00)  //!< Bit mask for GPU3D_GCC_SPECS_THREAD_COUNT.

//! @brief Get value of GPU3D_GCC_SPECS_THREAD_COUNT from a register value.
#define BG_GPU3D_GCC_SPECS_THREAD_COUNT(r)   (((r) & BM_GPU3D_GCC_SPECS_THREAD_COUNT) >> BP_GPU3D_GCC_SPECS_THREAD_COUNT)

/* --- Register HW_GPU3D_GCC_SPECS, field VERTEX_CACHE_SIZE[16:12] (RO)
 *
 * Number of entries in the vertex shader cache.
 */

#define BP_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE      (12)      //!< Bit position for GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE.
#define BM_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE      (0x0001f000)  //!< Bit mask for GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE.

//! @brief Get value of GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE from a register value.
#define BG_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE(r)   (((r) & BM_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE) >> BP_GPU3D_GCC_SPECS_VERTEX_CACHE_SIZE)

/* --- Register HW_GPU3D_GCC_SPECS, field NUM_SHADER_CORES[24:20] (RO)
 *
 * Number of shader cores.
 */

#define BP_GPU3D_GCC_SPECS_NUM_SHADER_CORES      (20)      //!< Bit position for GPU3D_GCC_SPECS_NUM_SHADER_CORES.
#define BM_GPU3D_GCC_SPECS_NUM_SHADER_CORES      (0x01f00000)  //!< Bit mask for GPU3D_GCC_SPECS_NUM_SHADER_CORES.

//! @brief Get value of GPU3D_GCC_SPECS_NUM_SHADER_CORES from a register value.
#define BG_GPU3D_GCC_SPECS_NUM_SHADER_CORES(r)   (((r) & BM_GPU3D_GCC_SPECS_NUM_SHADER_CORES) >> BP_GPU3D_GCC_SPECS_NUM_SHADER_CORES)

/* --- Register HW_GPU3D_GCC_SPECS, field NUM_PIXEL_PIPES[27:25] (RO)
 *
 * Number of pixel pipes.
 */

#define BP_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES      (25)      //!< Bit position for GPU3D_GCC_SPECS_NUM_PIXEL_PIPES.
#define BM_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES      (0x0e000000)  //!< Bit mask for GPU3D_GCC_SPECS_NUM_PIXEL_PIPES.

//! @brief Get value of GPU3D_GCC_SPECS_NUM_PIXEL_PIPES from a register value.
#define BG_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES(r)   (((r) & BM_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES) >> BP_GPU3D_GCC_SPECS_NUM_PIXEL_PIPES)

/* --- Register HW_GPU3D_GCC_SPECS, field VERTEX_OUTPUT_BUFFER_SIZE[31:28] (RO)
 *
 * Log2 of vertex output buffer size.
 */

#define BP_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE      (28)      //!< Bit position for GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE.
#define BM_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE      (0xf0000000)  //!< Bit mask for GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE.

//! @brief Get value of GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE from a register value.
#define BG_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE(r)   (((r) & BM_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE) >> BP_GPU3D_GCC_SPECS_VERTEX_OUTPUT_BUFFER_SIZE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_WRITE_BURSTS - gcTotalWriteBursts (RO)
 *
 * Reset value: 0x00000000
 *
 * Total write Data Count in terms of 64 bits. This register has no reset value.
 */
typedef union _hw_gpu3d_gct_write_bursts
{
    reg32_t U;
    struct _hw_gpu3d_gct_write_bursts_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_GCT_WRITE_BURSTS bitfields
 */

/* --- Register HW_GPU3D_GCT_WRITE_BURSTS, field COUNT[31:0] (RO)
 *

 */

#define BP_GPU3D_GCT_WRITE_BURSTS_COUNT      (0)      //!< Bit position for GPU3D_GCT_WRITE_BURSTS_COUNT.
#define BM_GPU3D_GCT_WRITE_BURSTS_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCT_WRITE_BURSTS_COUNT.

//! @brief Get value of GPU3D_GCT_WRITE_BURSTS_COUNT from a register value.
#define BG_GPU3D_GCT_WRITE_BURSTS_COUNT(r)   (((r) & BM_GPU3D_GCT_WRITE_BURSTS_COUNT) >> BP_GPU3D_GCT_WRITE_BURSTS_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_WRITE_REQS - gcTotalWriteReqs (RO)
 *
 * Reset value: 0x00000000
 *
 * Total write Request Count. This register has no reset value.
 */
typedef union _hw_gpu3d_gct_write_reqs
{
    reg32_t U;
    struct _hw_gpu3d_gct_write_reqs_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_GCT_WRITE_REQS bitfields
 */

/* --- Register HW_GPU3D_GCT_WRITE_REQS, field COUNT[31:0] (RO)
 *

 */

#define BP_GPU3D_GCT_WRITE_REQS_COUNT      (0)      //!< Bit position for GPU3D_GCT_WRITE_REQS_COUNT.
#define BM_GPU3D_GCT_WRITE_REQS_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCT_WRITE_REQS_COUNT.

//! @brief Get value of GPU3D_GCT_WRITE_REQS_COUNT from a register value.
#define BG_GPU3D_GCT_WRITE_REQS_COUNT(r)   (((r) & BM_GPU3D_GCT_WRITE_REQS_COUNT) >> BP_GPU3D_GCT_WRITE_REQS_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_WRITE_LASTS - gcTotalWriteLasts (RO)
 *
 * Reset value: 0x00000000
 *
 * Total WLAST Count. This is used to match with GCTotalWriteReqs. This register has no reset value.
 */
typedef union _hw_gpu3d_gct_write_lasts
{
    reg32_t U;
    struct _hw_gpu3d_gct_write_lasts_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_GCT_WRITE_LASTS bitfields
 */

/* --- Register HW_GPU3D_GCT_WRITE_LASTS, field COUNT[31:0] (RO)
 *

 */

#define BP_GPU3D_GCT_WRITE_LASTS_COUNT      (0)      //!< Bit position for GPU3D_GCT_WRITE_LASTS_COUNT.
#define BM_GPU3D_GCT_WRITE_LASTS_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCT_WRITE_LASTS_COUNT.

//! @brief Get value of GPU3D_GCT_WRITE_LASTS_COUNT from a register value.
#define BG_GPU3D_GCT_WRITE_LASTS_COUNT(r)   (((r) & BM_GPU3D_GCT_WRITE_LASTS_COUNT) >> BP_GPU3D_GCT_WRITE_LASTS_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_READ_BURSTS - gcTotalReadBursts (RO)
 *
 * Reset value: 0x00000000
 *
 * Total Read Data COunt in terms of 64 bits. This register has no reset value.
 */
typedef union _hw_gpu3d_gct_read_bursts
{
    reg32_t U;
    struct _hw_gpu3d_gct_read_bursts_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_GCT_READ_BURSTS bitfields
 */

/* --- Register HW_GPU3D_GCT_READ_BURSTS, field COUNT[31:0] (RO)
 *

 */

#define BP_GPU3D_GCT_READ_BURSTS_COUNT      (0)      //!< Bit position for GPU3D_GCT_READ_BURSTS_COUNT.
#define BM_GPU3D_GCT_READ_BURSTS_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCT_READ_BURSTS_COUNT.

//! @brief Get value of GPU3D_GCT_READ_BURSTS_COUNT from a register value.
#define BG_GPU3D_GCT_READ_BURSTS_COUNT(r)   (((r) & BM_GPU3D_GCT_READ_BURSTS_COUNT) >> BP_GPU3D_GCT_READ_BURSTS_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_READ_REQS - gcTotalReadReqs (RO)
 *
 * Reset value: 0x00000000
 *
 * Total Read Request Count. This register has no reset value.  s
 */
typedef union _hw_gpu3d_gct_read_reqs
{
    reg32_t U;
    struct _hw_gpu3d_gct_read_reqs_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_GCT_READ_REQS bitfields
 */

/* --- Register HW_GPU3D_GCT_READ_REQS, field COUNT[31:0] (RO)
 *

 */

#define BP_GPU3D_GCT_READ_REQS_COUNT      (0)      //!< Bit position for GPU3D_GCT_READ_REQS_COUNT.
#define BM_GPU3D_GCT_READ_REQS_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCT_READ_REQS_COUNT.

//! @brief Get value of GPU3D_GCT_READ_REQS_COUNT from a register value.
#define BG_GPU3D_GCT_READ_REQS_COUNT(r)   (((r) & BM_GPU3D_GCT_READ_REQS_COUNT) >> BP_GPU3D_GCT_READ_REQS_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_READ_LASTS - gcTotalReadLasts (RO)
 *
 * Reset value: 0x00000000
 *
 * Total RLAST Count. This is uset to match with GCTotalReadReqs. This register has no reset value.
 */
typedef union _hw_gpu3d_gct_read_lasts
{
    reg32_t U;
    struct _hw_gpu3d_gct_read_lasts_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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
#endif

/*
 * constants & macros for individual GPU3D_GCT_READ_LASTS bitfields
 */

/* --- Register HW_GPU3D_GCT_READ_LASTS, field COUNT[31:0] (RO)
 *

 */

#define BP_GPU3D_GCT_READ_LASTS_COUNT      (0)      //!< Bit position for GPU3D_GCT_READ_LASTS_COUNT.
#define BM_GPU3D_GCT_READ_LASTS_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCT_READ_LASTS_COUNT.

//! @brief Get value of GPU3D_GCT_READ_LASTS_COUNT from a register value.
#define BG_GPU3D_GCT_READ_LASTS_COUNT(r)   (((r) & BM_GPU3D_GCT_READ_LASTS_COUNT) >> BP_GPU3D_GCT_READ_LASTS_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCGPO_0 - gcGpOut0 (RW)
 *
 * Reset value: 0x00000000
 *
 * General Purpose output register 0. R/W but not connected to anywhere.
 */
typedef union _hw_gpu3d_gcgpo_0
{
    reg32_t U;
    struct _hw_gpu3d_gcgpo_0_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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

/* --- Register HW_GPU3D_GCGPO_0, field COUNT[31:0] (RW)
 *

 */

#define BP_GPU3D_GCGPO_0_COUNT      (0)      //!< Bit position for GPU3D_GCGPO_0_COUNT.
#define BM_GPU3D_GCGPO_0_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCGPO_0_COUNT.

//! @brief Get value of GPU3D_GCGPO_0_COUNT from a register value.
#define BG_GPU3D_GCGPO_0_COUNT(r)   (((r) & BM_GPU3D_GCGPO_0_COUNT) >> BP_GPU3D_GCGPO_0_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_GCGPO_0_COUNT.
#define BF_GPU3D_GCGPO_0_COUNT(v)   ((((reg32_t) v) << BP_GPU3D_GCGPO_0_COUNT) & BM_GPU3D_GCGPO_0_COUNT)
#else
//! @brief Format value for bitfield GPU3D_GCGPO_0_COUNT.
#define BF_GPU3D_GCGPO_0_COUNT(v)   (((v) << BP_GPU3D_GCGPO_0_COUNT) & BM_GPU3D_GCGPO_0_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_GPU3D_GCGPO_0_COUNT(v)   (HW_GPU3D_GCGPO_0_WR((HW_GPU3D_GCGPO_0_RD() & ~BM_GPU3D_GCGPO_0_COUNT) | BF_GPU3D_GCGPO_0_COUNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCGPO_1 - gcGpOut1 (RW)
 *
 * Reset value: 0x00000000
 *
 * General Purpose output register 1. R/W but not connected to anywhere.
 */
typedef union _hw_gpu3d_gcgpo_1
{
    reg32_t U;
    struct _hw_gpu3d_gcgpo_1_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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

/* --- Register HW_GPU3D_GCGPO_1, field COUNT[31:0] (RW)
 *

 */

#define BP_GPU3D_GCGPO_1_COUNT      (0)      //!< Bit position for GPU3D_GCGPO_1_COUNT.
#define BM_GPU3D_GCGPO_1_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCGPO_1_COUNT.

//! @brief Get value of GPU3D_GCGPO_1_COUNT from a register value.
#define BG_GPU3D_GCGPO_1_COUNT(r)   (((r) & BM_GPU3D_GCGPO_1_COUNT) >> BP_GPU3D_GCGPO_1_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_GCGPO_1_COUNT.
#define BF_GPU3D_GCGPO_1_COUNT(v)   ((((reg32_t) v) << BP_GPU3D_GCGPO_1_COUNT) & BM_GPU3D_GCGPO_1_COUNT)
#else
//! @brief Format value for bitfield GPU3D_GCGPO_1_COUNT.
#define BF_GPU3D_GCGPO_1_COUNT(v)   (((v) << BP_GPU3D_GCGPO_1_COUNT) & BM_GPU3D_GCGPO_1_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_GPU3D_GCGPO_1_COUNT(v)   (HW_GPU3D_GCGPO_1_WR((HW_GPU3D_GCGPO_1_RD() & ~BM_GPU3D_GCGPO_1_COUNT) | BF_GPU3D_GCGPO_1_COUNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCGPO_2 - gcGpOut2 (RW)
 *
 * Reset value: 0x00000000
 *
 * General Purpose output register 2. R/W but not connected to anywhere.
 */
typedef union _hw_gpu3d_gcgpo_2
{
    reg32_t U;
    struct _hw_gpu3d_gcgpo_2_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] 
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

/* --- Register HW_GPU3D_GCGPO_2, field COUNT[31:0] (RW)
 *

 */

#define BP_GPU3D_GCGPO_2_COUNT      (0)      //!< Bit position for GPU3D_GCGPO_2_COUNT.
#define BM_GPU3D_GCGPO_2_COUNT      (0xffffffff)  //!< Bit mask for GPU3D_GCGPO_2_COUNT.

//! @brief Get value of GPU3D_GCGPO_2_COUNT from a register value.
#define BG_GPU3D_GCGPO_2_COUNT(r)   (((r) & BM_GPU3D_GCGPO_2_COUNT) >> BP_GPU3D_GCGPO_2_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_GCGPO_2_COUNT.
#define BF_GPU3D_GCGPO_2_COUNT(v)   ((((reg32_t) v) << BP_GPU3D_GCGPO_2_COUNT) & BM_GPU3D_GCGPO_2_COUNT)
#else
//! @brief Format value for bitfield GPU3D_GCGPO_2_COUNT.
#define BF_GPU3D_GCGPO_2_COUNT(v)   (((v) << BP_GPU3D_GCGPO_2_COUNT) & BM_GPU3D_GCGPO_2_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_GPU3D_GCGPO_2_COUNT(v)   (HW_GPU3D_GCGPO_2_WR((HW_GPU3D_GCGPO_2_RD() & ~BM_GPU3D_GCGPO_2_COUNT) | BF_GPU3D_GCGPO_2_COUNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCA_CRTL - gcAxiControl (RW)
 *
 * Reset value: 0x00000000
 *
 * Speacial Handling on AXI Bus.
 */
typedef union _hw_gpu3d_gca_crtl
{
    reg32_t U;
    struct _hw_gpu3d_gca_crtl_bitfields
    {
        unsigned WR_FULL_BURST_MODE : 1; //!< [0] 
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
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

/* --- Register HW_GPU3D_GCA_CRTL, field WR_FULL_BURST_MODE[0] (RW)
 *

 *
 * Values:
 * 0 - =>NO_BURST_RESET_VALUE
 * 1 - =>BURST_RESET_VALUE
 */

#define BP_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE      (0)      //!< Bit position for GPU3D_GCA_CRTL_WR_FULL_BURST_MODE.
#define BM_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE      (0x00000001)  //!< Bit mask for GPU3D_GCA_CRTL_WR_FULL_BURST_MODE.

//! @brief Get value of GPU3D_GCA_CRTL_WR_FULL_BURST_MODE from a register value.
#define BG_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE(r)   (((r) & BM_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE) >> BP_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_GCA_CRTL_WR_FULL_BURST_MODE.
#define BF_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE(v)   ((((reg32_t) v) << BP_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE) & BM_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE)
#else
//! @brief Format value for bitfield GPU3D_GCA_CRTL_WR_FULL_BURST_MODE.
#define BF_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE(v)   (((v) << BP_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE) & BM_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WR_FULL_BURST_MODE field to a new value.
#define BW_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE(v)   (HW_GPU3D_GCA_CRTL_WR((HW_GPU3D_GCA_CRTL_RD() & ~BM_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE) | BF_GPU3D_GCA_CRTL_WR_FULL_BURST_MODE(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCM_FEAT_1 - GCMinorFeatures1 (RO)
 *
 * Reset value: 0x00000000
 *
 * Shows which features are enabled in this chip. This register has no set reset value. It varies
 * with the implementation.
 */
typedef union _hw_gpu3d_gcm_feat_1
{
    reg32_t U;
    struct _hw_gpu3d_gcm_feat_1_bitfields
    {
        unsigned RSUV_SWIZZLE : 1; //!< [0] Resolve UV swizzle.
        unsigned V2_COMPRESSION : 1; //!< [1] V2 compression.
        unsigned VG_DOUBLE_BUFFER : 1; //!< [2] Double buffering support for VG (second TS-->VG semaphore is present).
        unsigned BUG_FIXES1 : 1; //!< [3] 
        unsigned BUG_FIXES2 : 1; //!< [4] 
        unsigned TEXTURE_STRIDE : 1; //!< [5] Texture has stride and memory addressing.
        unsigned RESERVED0 : 26; //!< [31:6] Reserved
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
#endif

/*
 * constants & macros for individual GPU3D_GCM_FEAT_1 bitfields
 */

/* --- Register HW_GPU3D_GCM_FEAT_1, field RSUV_SWIZZLE[0] (RO)
 *
 * Resolve UV swizzle.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE      (0)      //!< Bit position for GPU3D_GCM_FEAT_1_RSUV_SWIZZLE.
#define BM_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE      (0x00000001)  //!< Bit mask for GPU3D_GCM_FEAT_1_RSUV_SWIZZLE.

//! @brief Get value of GPU3D_GCM_FEAT_1_RSUV_SWIZZLE from a register value.
#define BG_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE(r)   (((r) & BM_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE) >> BP_GPU3D_GCM_FEAT_1_RSUV_SWIZZLE)


/* --- Register HW_GPU3D_GCM_FEAT_1, field V2_COMPRESSION[1] (RO)
 *
 * V2 compression.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_1_V2_COMPRESSION      (1)      //!< Bit position for GPU3D_GCM_FEAT_1_V2_COMPRESSION.
#define BM_GPU3D_GCM_FEAT_1_V2_COMPRESSION      (0x00000002)  //!< Bit mask for GPU3D_GCM_FEAT_1_V2_COMPRESSION.

//! @brief Get value of GPU3D_GCM_FEAT_1_V2_COMPRESSION from a register value.
#define BG_GPU3D_GCM_FEAT_1_V2_COMPRESSION(r)   (((r) & BM_GPU3D_GCM_FEAT_1_V2_COMPRESSION) >> BP_GPU3D_GCM_FEAT_1_V2_COMPRESSION)


/* --- Register HW_GPU3D_GCM_FEAT_1, field VG_DOUBLE_BUFFER[2] (RO)
 *
 * Double buffering support for VG (second TS-->VG semaphore is present).
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER      (2)      //!< Bit position for GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER.
#define BM_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER      (0x00000004)  //!< Bit mask for GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER.

//! @brief Get value of GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER from a register value.
#define BG_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER(r)   (((r) & BM_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER) >> BP_GPU3D_GCM_FEAT_1_VG_DOUBLE_BUFFER)


/* --- Register HW_GPU3D_GCM_FEAT_1, field BUG_FIXES1[3] (RO)
 *

 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_1_BUG_FIXES1      (3)      //!< Bit position for GPU3D_GCM_FEAT_1_BUG_FIXES1.
#define BM_GPU3D_GCM_FEAT_1_BUG_FIXES1      (0x00000008)  //!< Bit mask for GPU3D_GCM_FEAT_1_BUG_FIXES1.

//! @brief Get value of GPU3D_GCM_FEAT_1_BUG_FIXES1 from a register value.
#define BG_GPU3D_GCM_FEAT_1_BUG_FIXES1(r)   (((r) & BM_GPU3D_GCM_FEAT_1_BUG_FIXES1) >> BP_GPU3D_GCM_FEAT_1_BUG_FIXES1)


/* --- Register HW_GPU3D_GCM_FEAT_1, field BUG_FIXES2[4] (RO)
 *

 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_1_BUG_FIXES2      (4)      //!< Bit position for GPU3D_GCM_FEAT_1_BUG_FIXES2.
#define BM_GPU3D_GCM_FEAT_1_BUG_FIXES2      (0x00000010)  //!< Bit mask for GPU3D_GCM_FEAT_1_BUG_FIXES2.

//! @brief Get value of GPU3D_GCM_FEAT_1_BUG_FIXES2 from a register value.
#define BG_GPU3D_GCM_FEAT_1_BUG_FIXES2(r)   (((r) & BM_GPU3D_GCM_FEAT_1_BUG_FIXES2) >> BP_GPU3D_GCM_FEAT_1_BUG_FIXES2)


/* --- Register HW_GPU3D_GCM_FEAT_1, field TEXTURE_STRIDE[5] (RO)
 *
 * Texture has stride and memory addressing.
 *
 * Values:
 * 0 - =>NONE
 * 1 - =>AVAILABLE
 */

#define BP_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE      (5)      //!< Bit position for GPU3D_GCM_FEAT_1_TEXTURE_STRIDE.
#define BM_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE      (0x00000020)  //!< Bit mask for GPU3D_GCM_FEAT_1_TEXTURE_STRIDE.

//! @brief Get value of GPU3D_GCM_FEAT_1_TEXTURE_STRIDE from a register value.
#define BG_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE(r)   (((r) & BM_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE) >> BP_GPU3D_GCM_FEAT_1_TEXTURE_STRIDE)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_CYCLES - gcTotalCycles (RW)
 *
 * Reset value: 0x00000000
 *
 * Total cycles. This register is a free-running counter. It can be reset by writing 0 to it.
 */
typedef union _hw_gpu3d_gct_cycles
{
    reg32_t U;
    struct _hw_gpu3d_gct_cycles_bitfields
    {
        unsigned CYCLES : 32; //!< [31:0] 
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

/* --- Register HW_GPU3D_GCT_CYCLES, field CYCLES[31:0] (RW)
 *

 */

#define BP_GPU3D_GCT_CYCLES_CYCLES      (0)      //!< Bit position for GPU3D_GCT_CYCLES_CYCLES.
#define BM_GPU3D_GCT_CYCLES_CYCLES      (0xffffffff)  //!< Bit mask for GPU3D_GCT_CYCLES_CYCLES.

//! @brief Get value of GPU3D_GCT_CYCLES_CYCLES from a register value.
#define BG_GPU3D_GCT_CYCLES_CYCLES(r)   (((r) & BM_GPU3D_GCT_CYCLES_CYCLES) >> BP_GPU3D_GCT_CYCLES_CYCLES)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_GCT_CYCLES_CYCLES.
#define BF_GPU3D_GCT_CYCLES_CYCLES(v)   ((((reg32_t) v) << BP_GPU3D_GCT_CYCLES_CYCLES) & BM_GPU3D_GCT_CYCLES_CYCLES)
#else
//! @brief Format value for bitfield GPU3D_GCT_CYCLES_CYCLES.
#define BF_GPU3D_GCT_CYCLES_CYCLES(v)   (((v) << BP_GPU3D_GCT_CYCLES_CYCLES) & BM_GPU3D_GCT_CYCLES_CYCLES)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CYCLES field to a new value.
#define BW_GPU3D_GCT_CYCLES_CYCLES(v)   (HW_GPU3D_GCT_CYCLES_WR((HW_GPU3D_GCT_CYCLES_RD() & ~BM_GPU3D_GCT_CYCLES_CYCLES) | BF_GPU3D_GCT_CYCLES_CYCLES(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPU3D_GCT_IDLE_CYCLES - gcTotalIdleCycles (RW)
 *
 * Reset value: 0x00000000
 *
 * Total cycles where the GPU is idle. It is reset when gcTotalCylces register is written to. It
 * looks at all the blocks except FE when determining if the IP is idle.
 */
typedef union _hw_gpu3d_gct_idle_cycles
{
    reg32_t U;
    struct _hw_gpu3d_gct_idle_cycles_bitfields
    {
        unsigned CYCLES : 32; //!< [31:0] 
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

/* --- Register HW_GPU3D_GCT_IDLE_CYCLES, field CYCLES[31:0] (RW)
 *

 */

#define BP_GPU3D_GCT_IDLE_CYCLES_CYCLES      (0)      //!< Bit position for GPU3D_GCT_IDLE_CYCLES_CYCLES.
#define BM_GPU3D_GCT_IDLE_CYCLES_CYCLES      (0xffffffff)  //!< Bit mask for GPU3D_GCT_IDLE_CYCLES_CYCLES.

//! @brief Get value of GPU3D_GCT_IDLE_CYCLES_CYCLES from a register value.
#define BG_GPU3D_GCT_IDLE_CYCLES_CYCLES(r)   (((r) & BM_GPU3D_GCT_IDLE_CYCLES_CYCLES) >> BP_GPU3D_GCT_IDLE_CYCLES_CYCLES)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPU3D_GCT_IDLE_CYCLES_CYCLES.
#define BF_GPU3D_GCT_IDLE_CYCLES_CYCLES(v)   ((((reg32_t) v) << BP_GPU3D_GCT_IDLE_CYCLES_CYCLES) & BM_GPU3D_GCT_IDLE_CYCLES_CYCLES)
#else
//! @brief Format value for bitfield GPU3D_GCT_IDLE_CYCLES_CYCLES.
#define BF_GPU3D_GCT_IDLE_CYCLES_CYCLES(v)   (((v) << BP_GPU3D_GCT_IDLE_CYCLES_CYCLES) & BM_GPU3D_GCT_IDLE_CYCLES_CYCLES)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CYCLES field to a new value.
#define BW_GPU3D_GCT_IDLE_CYCLES_CYCLES(v)   (HW_GPU3D_GCT_IDLE_CYCLES_WR((HW_GPU3D_GCT_IDLE_CYCLES_RD() & ~BM_GPU3D_GCT_IDLE_CYCLES_CYCLES) | BF_GPU3D_GCT_IDLE_CYCLES_CYCLES(v)))
#endif


/*!
 * @brief All GPU3D module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_gpu3d
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
} hw_gpu3d_t;
#pragma pack()

//! @brief Macro to access all GPU3D registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_GPU3D(0)</code>.
#define HW_GPU3D     (*(volatile hw_gpu3d_t *) REGS_GPU3D_BASE)

#endif


#endif // __HW_GPU3D_REGISTERS_H__
