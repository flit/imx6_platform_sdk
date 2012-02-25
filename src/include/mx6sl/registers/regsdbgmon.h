/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _DBGMON_H
#define _DBGMON_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_DBGMON_HW_DBGMON_CTRL - HW_DBGMON_CTRL
 * - HW_DBGMON_HW_DBGMON_MASTER_EN - HW_DBGMON_MASTER_EN
 * - HW_DBGMON_HW_DBGMON_IRQ - HW_DBGMON_IRQ
 * - HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW - HW_DBGMON_TRAP_ADDR_LOW
 * - HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH - HW_DBGMON_TRAP_ADDR_HIGH
 * - HW_DBGMON_HW_DBGMON_TRAP_ID - HW_DBGMON_TRAP_ID
 * - HW_DBGMON_HW_DBGMON_SNVS_ADDR - HW_DBGMON_SNVS_ADDR
 * - HW_DBGMON_HW_DBGMON_SNVS_DATA - HW_DBGMON_SNVS_DATA
 * - HW_DBGMON_HW_DBGMON_SNVS_INFO - HW_DBGMON_SNVS_INFO
 * - HW_DBGMON_HW_DBGMON_VERSION - HW_DBGMON_VERSION
 *
 * hw_dbgmon_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_DBGMON_BASE
#define REGS_DBGMON_BASE (0x02900000) //!< Base address for DBGMON.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_CTRL - HW_DBGMON_CTRL (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RUN : 1; //!< Set this bit to one to enable the DBGMON operation
        unsigned SNAP : 1; //!< Set this bit to snapshot the registers selected by REQSEL to SNVS domain registers
        unsigned CLR : 1; //!< Set this bit to clear the registers in SOC domain. This bit will be automatically set to 0 once the clear process is done
        unsigned CLR_SNVS : 1; //!< Set this bit to clear the registers in SNVS domain
        unsigned ADDR_TRAPMODE : 1; //!< The bit defines the address trap function.
        unsigned ID_TRAPMODE : 1; //!< The bit defines the ID trap function.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned REQSEL : 2; //!< This field defines which sets of AXI transaction will be snaped to SNVS domain registers. Assume (N-3), (N-2), (N-1), N represent four continous most recent AXI transactions, N is the latest transactions
        unsigned RESERVED1 : 6; //!< Reserved
        unsigned WORKMODE : 1; //!< This field defines whether ignore the transaction in IRQ
        unsigned RESERVED2 : 3; //!< Reserved
        unsigned ADDR_MASKEN : 1; //!< This field control the address mask function,
        unsigned RESERVED3 : 3; //!< Reserved
        unsigned WDOG_IRQ_SEL : 1; //!< Select the source of WDOG IRQ.
        unsigned RESERVED4 : 5; //!< Reserved
        unsigned CLKGATE : 1; //!< This bit must be set to zero for normal oepration. When set to one it gates off the clock to the block.
        unsigned SFTRST : 1; //!< Set to zero for normal operation. When this bit is set to one(default), then the entire block is held in its reset state
    } B;
} hw_dbgmon_hw_dbgmon_ctrl_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_CTRL register
 */
#define HW_DBGMON_HW_DBGMON_CTRL_ADDR      (REGS_DBGMON_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_CTRL           (*(volatile hw_dbgmon_hw_dbgmon_ctrl_t *) HW_DBGMON_HW_DBGMON_CTRL_ADDR)
#define HW_DBGMON_HW_DBGMON_CTRL_RD()      (HW_DBGMON_HW_DBGMON_CTRL.U)
#define HW_DBGMON_HW_DBGMON_CTRL_WR(v)     (HW_DBGMON_HW_DBGMON_CTRL.U = (v))
#define HW_DBGMON_HW_DBGMON_CTRL_SET(v)    (HW_DBGMON_HW_DBGMON_CTRL_WR(HW_DBGMON_HW_DBGMON_CTRL_RD() |  (v)))
#define HW_DBGMON_HW_DBGMON_CTRL_CLR(v)    (HW_DBGMON_HW_DBGMON_CTRL_WR(HW_DBGMON_HW_DBGMON_CTRL_RD() & ~(v)))
#define HW_DBGMON_HW_DBGMON_CTRL_TOG(v)    (HW_DBGMON_HW_DBGMON_CTRL_WR(HW_DBGMON_HW_DBGMON_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_CTRL bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field RUN[0:0] (RW)
 *
 * Set this bit to one to enable the DBGMON operation
 *
 * Values:
 * 0 - HALT, DBGMON is in halt status
 * 1 - RUN, DBGMON is in working status
 */

#define BP_DBGMON_HW_DBGMON_CTRL_RUN      (0)
#define BM_DBGMON_HW_DBGMON_CTRL_RUN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_RUN(v)   ((((reg32_t) v) << 0) & BM_DBGMON_HW_DBGMON_CTRL_RUN)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_RUN(v)   (((v) << 0) & BM_DBGMON_HW_DBGMON_CTRL_RUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RUN field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_RUN(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, RUN, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field SNAP[1:1] (RW)
 *
 * Set this bit to snapshot the registers selected by REQSEL to SNVS domain registers
 */

#define BP_DBGMON_HW_DBGMON_CTRL_SNAP      (1)
#define BM_DBGMON_HW_DBGMON_CTRL_SNAP      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_SNAP(v)   ((((reg32_t) v) << 1) & BM_DBGMON_HW_DBGMON_CTRL_SNAP)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_SNAP(v)   (((v) << 1) & BM_DBGMON_HW_DBGMON_CTRL_SNAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SNAP field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_SNAP(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, SNAP, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field CLR[2:2] (RW)
 *
 * Set this bit to clear the registers in SOC domain. This bit will be automatically set to 0 once
 * the clear process is done
 */

#define BP_DBGMON_HW_DBGMON_CTRL_CLR      (2)
#define BM_DBGMON_HW_DBGMON_CTRL_CLR      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_CLR(v)   ((((reg32_t) v) << 2) & BM_DBGMON_HW_DBGMON_CTRL_CLR)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_CLR(v)   (((v) << 2) & BM_DBGMON_HW_DBGMON_CTRL_CLR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_CLR(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, CLR, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field CLR_SNVS[3:3] (RW)
 *
 * Set this bit to clear the registers in SNVS domain
 */

#define BP_DBGMON_HW_DBGMON_CTRL_CLR_SNVS      (3)
#define BM_DBGMON_HW_DBGMON_CTRL_CLR_SNVS      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_CLR_SNVS(v)   ((((reg32_t) v) << 3) & BM_DBGMON_HW_DBGMON_CTRL_CLR_SNVS)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_CLR_SNVS(v)   (((v) << 3) & BM_DBGMON_HW_DBGMON_CTRL_CLR_SNVS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_SNVS field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_CLR_SNVS(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, CLR_SNVS, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field ADDR_TRAPMODE[4:4] (RW)
 *
 * The bit defines the address trap function.
 *
 * Values:
 * 0 - Address trap function is disabled
 * 1 - Address trap function is enabled
 */

#define BP_DBGMON_HW_DBGMON_CTRL_ADDR_TRAPMODE      (4)
#define BM_DBGMON_HW_DBGMON_CTRL_ADDR_TRAPMODE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_ADDR_TRAPMODE(v)   ((((reg32_t) v) << 4) & BM_DBGMON_HW_DBGMON_CTRL_ADDR_TRAPMODE)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_ADDR_TRAPMODE(v)   (((v) << 4) & BM_DBGMON_HW_DBGMON_CTRL_ADDR_TRAPMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR_TRAPMODE field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_ADDR_TRAPMODE(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, ADDR_TRAPMODE, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field ID_TRAPMODE[5:5] (RW)
 *
 * The bit defines the ID trap function.
 *
 * Values:
 * 0 - ID trap function is disabled
 * 1 - ID trap function is enabled
 */

#define BP_DBGMON_HW_DBGMON_CTRL_ID_TRAPMODE      (5)
#define BM_DBGMON_HW_DBGMON_CTRL_ID_TRAPMODE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_ID_TRAPMODE(v)   ((((reg32_t) v) << 5) & BM_DBGMON_HW_DBGMON_CTRL_ID_TRAPMODE)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_ID_TRAPMODE(v)   (((v) << 5) & BM_DBGMON_HW_DBGMON_CTRL_ID_TRAPMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ID_TRAPMODE field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_ID_TRAPMODE(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, ID_TRAPMODE, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field REQSEL[9:8] (RW)
 *
 * This field defines which sets of AXI transaction will be snaped to SNVS domain registers. Assume
 * (N-3), (N-2), (N-1), N represent four continous most recent AXI transactions, N is the latest
 * transactions
 *
 * Values:
 * 00 - The information of the latest transaction will be snapped to SNVS domain registers
 * 01 - (N-1) transaction will be snapped to SNVS domain registers
 * 10 - (N-2) transaction will be snapped to SNVS domain registers
 * 11 - (N-3) transaction will be snapped to SNVS domain registers
 */

#define BP_DBGMON_HW_DBGMON_CTRL_REQSEL      (8)
#define BM_DBGMON_HW_DBGMON_CTRL_REQSEL      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_REQSEL(v)   ((((reg32_t) v) << 8) & BM_DBGMON_HW_DBGMON_CTRL_REQSEL)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_REQSEL(v)   (((v) << 8) & BM_DBGMON_HW_DBGMON_CTRL_REQSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REQSEL field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_REQSEL(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, REQSEL, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field WORKMODE[16:16] (RW)
 *
 * This field defines whether ignore the transaction in IRQ
 *
 * Values:
 * 0 - The axi transaction in interrupt status will be monitored
 * 1 - The axi transaction in interrupt status will be ignored
 */

#define BP_DBGMON_HW_DBGMON_CTRL_WORKMODE      (16)
#define BM_DBGMON_HW_DBGMON_CTRL_WORKMODE      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_WORKMODE(v)   ((((reg32_t) v) << 16) & BM_DBGMON_HW_DBGMON_CTRL_WORKMODE)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_WORKMODE(v)   (((v) << 16) & BM_DBGMON_HW_DBGMON_CTRL_WORKMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WORKMODE field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_WORKMODE(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, WORKMODE, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field ADDR_MASKEN[20:20] (RW)
 *
 * This field control the address mask function,
 *
 * Values:
 * 0 - Address mask is disabled, all address range will be monitored
 * 1 - Address mask is enabled, address within the range defined by ADDR_HIGH, ADDR_LOW will be monitored
 */

#define BP_DBGMON_HW_DBGMON_CTRL_ADDR_MASKEN      (20)
#define BM_DBGMON_HW_DBGMON_CTRL_ADDR_MASKEN      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_ADDR_MASKEN(v)   ((((reg32_t) v) << 20) & BM_DBGMON_HW_DBGMON_CTRL_ADDR_MASKEN)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_ADDR_MASKEN(v)   (((v) << 20) & BM_DBGMON_HW_DBGMON_CTRL_ADDR_MASKEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR_MASKEN field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_ADDR_MASKEN(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, ADDR_MASKEN, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field WDOG_IRQ_SEL[24:24] (RW)
 *
 * Select the source of WDOG IRQ.
 *
 * Values:
 * 0 - Select WDOG1 as WDOG IRQ source
 * 1 - Select WDOG2 as WDOG IRQ source
 */

#define BP_DBGMON_HW_DBGMON_CTRL_WDOG_IRQ_SEL      (24)
#define BM_DBGMON_HW_DBGMON_CTRL_WDOG_IRQ_SEL      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_WDOG_IRQ_SEL(v)   ((((reg32_t) v) << 24) & BM_DBGMON_HW_DBGMON_CTRL_WDOG_IRQ_SEL)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_WDOG_IRQ_SEL(v)   (((v) << 24) & BM_DBGMON_HW_DBGMON_CTRL_WDOG_IRQ_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WDOG_IRQ_SEL field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_WDOG_IRQ_SEL(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, WDOG_IRQ_SEL, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field CLKGATE[30:30] (RW)
 *
 * This bit must be set to zero for normal oepration. When set to one it gates off the clock to the
 * block.
 *
 * Values:
 * 0 - Allow DBGMON to operate normally
 * 1 - Gating off the clock of DBGMON in order to minimize the power consumption.
 */

#define BP_DBGMON_HW_DBGMON_CTRL_CLKGATE      (30)
#define BM_DBGMON_HW_DBGMON_CTRL_CLKGATE      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_DBGMON_HW_DBGMON_CTRL_CLKGATE)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_CLKGATE(v)   (((v) << 30) & BM_DBGMON_HW_DBGMON_CTRL_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_CLKGATE(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, CLKGATE, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_CTRL, field SFTRST[31:31] (RW)
 *
 * Set to zero for normal operation. When this bit is set to one(default), then the entire block is
 * held in its reset state
 *
 * Values:
 * 0 - Allow DBGMON to operate normally
 * 1 - Hold DBGMON in reset
 */

#define BP_DBGMON_HW_DBGMON_CTRL_SFTRST      (31)
#define BM_DBGMON_HW_DBGMON_CTRL_SFTRST      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_CTRL_SFTRST(v)   ((((reg32_t) v) << 31) & BM_DBGMON_HW_DBGMON_CTRL_SFTRST)
#else
#define BF_DBGMON_HW_DBGMON_CTRL_SFTRST(v)   (((v) << 31) & BM_DBGMON_HW_DBGMON_CTRL_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_DBGMON_HW_DBGMON_CTRL_SFTRST(v)   BF_CS1(DBGMON_HW_DBGMON_CTRL, SFTRST, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_MASTER_EN - HW_DBGMON_MASTER_EN (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MID0 : 1; //!< Set to 1 to enable monitoring on MasterID 0.
        unsigned MID1 : 1; //!< Set to 1 to enable monitoring on MasterID 1.
        unsigned MID2 : 1; //!< Set to 1 to enable monitoring on MasterID 2.
        unsigned MID3 : 1; //!< Set to 1 to enable monitoring on MasterID 3.
        unsigned MID4 : 1; //!< Set to 1 to enable monitoring on MasterID 4.
        unsigned MID5 : 1; //!< Set to 1 to enable monitoring on MasterID 5
        unsigned MID6 : 1; //!< Set to 1 to enable monitoring on MasterID 6.
        unsigned MID7 : 1; //!< Set to 1 to enable monitoring on MasterID 7.
        unsigned MID8 : 1; //!< Set to 1 to enable monitoring on MasterID 8.
        unsigned MID9 : 1; //!< Set to 1 to enable monitoring on MasterID 9.
        unsigned MID10 : 1; //!< Set to 1 to enable monitoring on MasterID 10.
        unsigned MID11 : 1; //!< Set to 1 to enable monitoring on MasterID 11.
        unsigned MID12 : 1; //!< Set to 1 to enable monitoring on MasterID 12.
        unsigned MID13 : 1; //!< Set to 1 to enable monitoring on MasterID 13.
        unsigned MID14 : 1; //!< Set to 1 to enable monitoring on MasterID 14.
        unsigned MID15 : 1; //!< Set to 1 to enable monitoring on MasterID 15.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_dbgmon_hw_dbgmon_master_en_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_MASTER_EN register
 */
#define HW_DBGMON_HW_DBGMON_MASTER_EN_ADDR      (REGS_DBGMON_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_MASTER_EN           (*(volatile hw_dbgmon_hw_dbgmon_master_en_t *) HW_DBGMON_HW_DBGMON_MASTER_EN_ADDR)
#define HW_DBGMON_HW_DBGMON_MASTER_EN_RD()      (HW_DBGMON_HW_DBGMON_MASTER_EN.U)
#define HW_DBGMON_HW_DBGMON_MASTER_EN_WR(v)     (HW_DBGMON_HW_DBGMON_MASTER_EN.U = (v))
#define HW_DBGMON_HW_DBGMON_MASTER_EN_SET(v)    (HW_DBGMON_HW_DBGMON_MASTER_EN_WR(HW_DBGMON_HW_DBGMON_MASTER_EN_RD() |  (v)))
#define HW_DBGMON_HW_DBGMON_MASTER_EN_CLR(v)    (HW_DBGMON_HW_DBGMON_MASTER_EN_WR(HW_DBGMON_HW_DBGMON_MASTER_EN_RD() & ~(v)))
#define HW_DBGMON_HW_DBGMON_MASTER_EN_TOG(v)    (HW_DBGMON_HW_DBGMON_MASTER_EN_WR(HW_DBGMON_HW_DBGMON_MASTER_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_MASTER_EN bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID0[0:0] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 0.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID0      (0)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID0      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID0(v)   ((((reg32_t) v) << 0) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID0)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID0(v)   (((v) << 0) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID0 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID0(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID0, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID1[1:1] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 1.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID1      (1)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID1      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID1(v)   ((((reg32_t) v) << 1) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID1)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID1(v)   (((v) << 1) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID1 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID1(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID1, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID2[2:2] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 2.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID2      (2)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID2(v)   ((((reg32_t) v) << 2) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID2)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID2(v)   (((v) << 2) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID2 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID2(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID2, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID3[3:3] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 3.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID3      (3)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID3      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID3(v)   ((((reg32_t) v) << 3) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID3)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID3(v)   (((v) << 3) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID3 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID3(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID3, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID4[4:4] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 4.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID4      (4)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID4      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID4(v)   ((((reg32_t) v) << 4) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID4)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID4(v)   (((v) << 4) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID4 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID4(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID4, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID5[5:5] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 5
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID5      (5)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID5      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID5(v)   ((((reg32_t) v) << 5) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID5)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID5(v)   (((v) << 5) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID5 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID5(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID5, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID6[6:6] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 6.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID6      (6)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID6      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID6(v)   ((((reg32_t) v) << 6) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID6)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID6(v)   (((v) << 6) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID6 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID6(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID6, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID7[7:7] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 7.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID7      (7)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID7      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID7(v)   ((((reg32_t) v) << 7) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID7)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID7(v)   (((v) << 7) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID7 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID7(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID7, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID8[8:8] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 8.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID8      (8)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID8      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID8(v)   ((((reg32_t) v) << 8) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID8)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID8(v)   (((v) << 8) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID8 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID8(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID8, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID9[9:9] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 9.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID9      (9)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID9      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID9(v)   ((((reg32_t) v) << 9) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID9)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID9(v)   (((v) << 9) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID9 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID9(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID9, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID10[10:10] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 10.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID10      (10)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID10      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID10(v)   ((((reg32_t) v) << 10) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID10)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID10(v)   (((v) << 10) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID10 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID10(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID10, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID11[11:11] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 11.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID11      (11)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID11      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID11(v)   ((((reg32_t) v) << 11) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID11)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID11(v)   (((v) << 11) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID11 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID11(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID11, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID12[12:12] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 12.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID12      (12)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID12      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID12(v)   ((((reg32_t) v) << 12) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID12)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID12(v)   (((v) << 12) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID12 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID12(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID12, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID13[13:13] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 13.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID13      (13)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID13      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID13(v)   ((((reg32_t) v) << 13) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID13)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID13(v)   (((v) << 13) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID13 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID13(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID13, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID14[14:14] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 14.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID14      (14)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID14      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID14(v)   ((((reg32_t) v) << 14) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID14)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID14(v)   (((v) << 14) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID14 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID14(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID14, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_MASTER_EN, field MID15[15:15] (RW)
 *
 * Set to 1 to enable monitoring on MasterID 15.
 */

#define BP_DBGMON_HW_DBGMON_MASTER_EN_MID15      (15)
#define BM_DBGMON_HW_DBGMON_MASTER_EN_MID15      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID15(v)   ((((reg32_t) v) << 15) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID15)
#else
#define BF_DBGMON_HW_DBGMON_MASTER_EN_MID15(v)   (((v) << 15) & BM_DBGMON_HW_DBGMON_MASTER_EN_MID15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MID15 field to a new value.
#define BW_DBGMON_HW_DBGMON_MASTER_EN_MID15(v)   BF_CS1(DBGMON_HW_DBGMON_MASTER_EN, MID15, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_IRQ - HW_DBGMON_IRQ (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR_TRAP_IRQEN : 1; //!< Address trap interrupt control.
        unsigned ID_TRAP_IRQEN : 1; //!< ID trap interrupt control.
        unsigned ADDR_TRAP_IRQ : 1; //!< This bit indicates the Address trap interrupt is happening. Write to 1 to SCT address(offset = 0x28) to clear it.
        unsigned ID_TRAP_IRQ : 1; //!< This bit indicates the ID trap interrupt is happening. Write to 1 to SCT address(offset = 0x28) to clear it.
        unsigned RESERVED0 : 12; //!< Reserved.
        unsigned IRQ_MID : 16; //!< This field indicate which master sends the interrupt, will not update until all interrupts are cleared. each bit represents one master. IRQ_MID[16] represents Master 0 IRQ_MID[17] represents Master 1, and so on
    } B;
} hw_dbgmon_hw_dbgmon_irq_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_IRQ register
 */
#define HW_DBGMON_HW_DBGMON_IRQ_ADDR      (REGS_DBGMON_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_IRQ           (*(volatile hw_dbgmon_hw_dbgmon_irq_t *) HW_DBGMON_HW_DBGMON_IRQ_ADDR)
#define HW_DBGMON_HW_DBGMON_IRQ_RD()      (HW_DBGMON_HW_DBGMON_IRQ.U)
#define HW_DBGMON_HW_DBGMON_IRQ_WR(v)     (HW_DBGMON_HW_DBGMON_IRQ.U = (v))
#define HW_DBGMON_HW_DBGMON_IRQ_SET(v)    (HW_DBGMON_HW_DBGMON_IRQ_WR(HW_DBGMON_HW_DBGMON_IRQ_RD() |  (v)))
#define HW_DBGMON_HW_DBGMON_IRQ_CLR(v)    (HW_DBGMON_HW_DBGMON_IRQ_WR(HW_DBGMON_HW_DBGMON_IRQ_RD() & ~(v)))
#define HW_DBGMON_HW_DBGMON_IRQ_TOG(v)    (HW_DBGMON_HW_DBGMON_IRQ_WR(HW_DBGMON_HW_DBGMON_IRQ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_IRQ bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_IRQ, field ADDR_TRAP_IRQEN[0:0] (RW)
 *
 * Address trap interrupt control.
 *
 * Values:
 * 0 - Address trap interrupt is disabled
 * 1 - Address trap interrupt is enabled
 */

#define BP_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQEN      (0)
#define BM_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQEN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQEN(v)   ((((reg32_t) v) << 0) & BM_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQEN)
#else
#define BF_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQEN(v)   (((v) << 0) & BM_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR_TRAP_IRQEN field to a new value.
#define BW_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQEN(v)   BF_CS1(DBGMON_HW_DBGMON_IRQ, ADDR_TRAP_IRQEN, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_IRQ, field ID_TRAP_IRQEN[1:1] (RW)
 *
 * ID trap interrupt control.
 *
 * Values:
 * 0 - ID trap interrupt is disabled
 * 1 - ID trap interrupt is enabled
 */

#define BP_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQEN      (1)
#define BM_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQEN      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQEN(v)   ((((reg32_t) v) << 1) & BM_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQEN)
#else
#define BF_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQEN(v)   (((v) << 1) & BM_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ID_TRAP_IRQEN field to a new value.
#define BW_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQEN(v)   BF_CS1(DBGMON_HW_DBGMON_IRQ, ID_TRAP_IRQEN, v)
#endif


/* --- Register HW_DBGMON_HW_DBGMON_IRQ, field ADDR_TRAP_IRQ[2:2] (RW)
 *
 * This bit indicates the Address trap interrupt is happening. Write to 1 to SCT address(offset =
 * 0x28) to clear it.
 */

#define BP_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQ      (2)
#define BM_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQ      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQ(v)   ((((reg32_t) v) << 2) & BM_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQ)
#else
#define BF_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQ(v)   (((v) << 2) & BM_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR_TRAP_IRQ field to a new value.
#define BW_DBGMON_HW_DBGMON_IRQ_ADDR_TRAP_IRQ(v)   BF_CS1(DBGMON_HW_DBGMON_IRQ, ADDR_TRAP_IRQ, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_IRQ, field ID_TRAP_IRQ[3:3] (RW)
 *
 * This bit indicates the ID trap interrupt is happening. Write to 1 to SCT address(offset = 0x28)
 * to clear it.
 */

#define BP_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQ      (3)
#define BM_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQ      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQ(v)   ((((reg32_t) v) << 3) & BM_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQ)
#else
#define BF_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQ(v)   (((v) << 3) & BM_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ID_TRAP_IRQ field to a new value.
#define BW_DBGMON_HW_DBGMON_IRQ_ID_TRAP_IRQ(v)   BF_CS1(DBGMON_HW_DBGMON_IRQ, ID_TRAP_IRQ, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_IRQ, field IRQ_MID[31:16] (RW)
 *
 * This field indicate which master sends the interrupt, will not update until all interrupts are
 * cleared. each bit represents one master. IRQ_MID[16] represents Master 0 IRQ_MID[17] represents
 * Master 1, and so on
 */

#define BP_DBGMON_HW_DBGMON_IRQ_IRQ_MID      (16)
#define BM_DBGMON_HW_DBGMON_IRQ_IRQ_MID      (0xffff0000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_IRQ_IRQ_MID(v)   ((((reg32_t) v) << 16) & BM_DBGMON_HW_DBGMON_IRQ_IRQ_MID)
#else
#define BF_DBGMON_HW_DBGMON_IRQ_IRQ_MID(v)   (((v) << 16) & BM_DBGMON_HW_DBGMON_IRQ_IRQ_MID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_MID field to a new value.
#define BW_DBGMON_HW_DBGMON_IRQ_IRQ_MID(v)   BF_CS1(DBGMON_HW_DBGMON_IRQ, IRQ_MID, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW - HW_DBGMON_TRAP_ADDR_LOW (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDRESS : 32; //!< This field contains 32-bit low address for the address trap range
    } B;
} hw_dbgmon_hw_dbgmon_trap_addr_low_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_TRAP_ADDR_LOW register
 */
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDR      (REGS_DBGMON_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW           (*(volatile hw_dbgmon_hw_dbgmon_trap_addr_low_t *) HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDR)
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_RD()      (HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW.U)
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_WR(v)     (HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW.U = (v))
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_SET(v)    (HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_WR(HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_RD() |  (v)))
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_CLR(v)    (HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_WR(HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_RD() & ~(v)))
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_TOG(v)    (HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_WR(HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_TRAP_ADDR_LOW bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW, field ADDRESS[31:0] (RW)
 *
 * This field contains 32-bit low address for the address trap range
 */

#define BP_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDRESS      (0)
#define BM_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDRESS      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDRESS(v)   ((((reg32_t) v) << 0) & BM_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDRESS)
#else
#define BF_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDRESS(v)   (((v) << 0) & BM_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRESS field to a new value.
#define BW_DBGMON_HW_DBGMON_TRAP_ADDR_LOW_ADDRESS(v)   BF_CS1(DBGMON_HW_DBGMON_TRAP_ADDR_LOW, ADDRESS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH - HW_DBGMON_TRAP_ADDR_HIGH (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDRESS : 32; //!< This field contains 32-bit high address for the address trap range
    } B;
} hw_dbgmon_hw_dbgmon_trap_addr_high_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_TRAP_ADDR_HIGH register
 */
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDR      (REGS_DBGMON_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH           (*(volatile hw_dbgmon_hw_dbgmon_trap_addr_high_t *) HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDR)
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_RD()      (HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH.U)
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_WR(v)     (HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH.U = (v))
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_SET(v)    (HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_WR(HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_RD() |  (v)))
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_CLR(v)    (HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_WR(HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_RD() & ~(v)))
#define HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_TOG(v)    (HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_WR(HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_TRAP_ADDR_HIGH bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH, field ADDRESS[31:0] (RW)
 *
 * This field contains 32-bit high address for the address trap range
 */

#define BP_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDRESS      (0)
#define BM_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDRESS      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDRESS(v)   ((((reg32_t) v) << 0) & BM_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDRESS)
#else
#define BF_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDRESS(v)   (((v) << 0) & BM_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRESS field to a new value.
#define BW_DBGMON_HW_DBGMON_TRAP_ADDR_HIGH_ADDRESS(v)   BF_CS1(DBGMON_HW_DBGMON_TRAP_ADDR_HIGH, ADDRESS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_TRAP_ID - HW_DBGMON_TRAP_ID (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TRAP_ID_LOW : 16; //!< This field contains 16-bit low ID for ID trap range
        unsigned TRAP_ID_HIGH : 16; //!< This field contains 16-bit high ID for ID trap range
    } B;
} hw_dbgmon_hw_dbgmon_trap_id_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_TRAP_ID register
 */
#define HW_DBGMON_HW_DBGMON_TRAP_ID_ADDR      (REGS_DBGMON_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_TRAP_ID           (*(volatile hw_dbgmon_hw_dbgmon_trap_id_t *) HW_DBGMON_HW_DBGMON_TRAP_ID_ADDR)
#define HW_DBGMON_HW_DBGMON_TRAP_ID_RD()      (HW_DBGMON_HW_DBGMON_TRAP_ID.U)
#define HW_DBGMON_HW_DBGMON_TRAP_ID_WR(v)     (HW_DBGMON_HW_DBGMON_TRAP_ID.U = (v))
#define HW_DBGMON_HW_DBGMON_TRAP_ID_SET(v)    (HW_DBGMON_HW_DBGMON_TRAP_ID_WR(HW_DBGMON_HW_DBGMON_TRAP_ID_RD() |  (v)))
#define HW_DBGMON_HW_DBGMON_TRAP_ID_CLR(v)    (HW_DBGMON_HW_DBGMON_TRAP_ID_WR(HW_DBGMON_HW_DBGMON_TRAP_ID_RD() & ~(v)))
#define HW_DBGMON_HW_DBGMON_TRAP_ID_TOG(v)    (HW_DBGMON_HW_DBGMON_TRAP_ID_WR(HW_DBGMON_HW_DBGMON_TRAP_ID_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_TRAP_ID bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_TRAP_ID, field TRAP_ID_LOW[15:0] (RW)
 *
 * This field contains 16-bit low ID for ID trap range
 */

#define BP_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_LOW      (0)
#define BM_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_LOW      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_LOW(v)   ((((reg32_t) v) << 0) & BM_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_LOW)
#else
#define BF_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_LOW(v)   (((v) << 0) & BM_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_LOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TRAP_ID_LOW field to a new value.
#define BW_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_LOW(v)   BF_CS1(DBGMON_HW_DBGMON_TRAP_ID, TRAP_ID_LOW, v)
#endif

/* --- Register HW_DBGMON_HW_DBGMON_TRAP_ID, field TRAP_ID_HIGH[31:16] (RW)
 *
 * This field contains 16-bit high ID for ID trap range
 */

#define BP_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_HIGH      (16)
#define BM_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_HIGH      (0xffff0000)

#ifndef __LANGUAGE_ASM__
#define BF_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_HIGH(v)   ((((reg32_t) v) << 16) & BM_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_HIGH)
#else
#define BF_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_HIGH(v)   (((v) << 16) & BM_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_HIGH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TRAP_ID_HIGH field to a new value.
#define BW_DBGMON_HW_DBGMON_TRAP_ID_TRAP_ID_HIGH(v)   BF_CS1(DBGMON_HW_DBGMON_TRAP_ID, TRAP_ID_HIGH, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_SNVS_ADDR - HW_DBGMON_SNVS_ADDR (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< This field contains 32-bit Address in SNVS domain register
    } B;
} hw_dbgmon_hw_dbgmon_snvs_addr_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_SNVS_ADDR register
 */
#define HW_DBGMON_HW_DBGMON_SNVS_ADDR_ADDR      (REGS_DBGMON_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_SNVS_ADDR           (*(volatile hw_dbgmon_hw_dbgmon_snvs_addr_t *) HW_DBGMON_HW_DBGMON_SNVS_ADDR_ADDR)
#define HW_DBGMON_HW_DBGMON_SNVS_ADDR_RD()      (HW_DBGMON_HW_DBGMON_SNVS_ADDR.U)
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_SNVS_ADDR bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_SNVS_ADDR, field ADDR[31:0] (RO)
 *
 * This field contains 32-bit Address in SNVS domain register
 */

#define BP_DBGMON_HW_DBGMON_SNVS_ADDR_ADDR      (0)
#define BM_DBGMON_HW_DBGMON_SNVS_ADDR_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_SNVS_DATA - HW_DBGMON_SNVS_DATA (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 32; //!< This field contains 32-bit Data of AXI transaction in SNVS domain register
    } B;
} hw_dbgmon_hw_dbgmon_snvs_data_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_SNVS_DATA register
 */
#define HW_DBGMON_HW_DBGMON_SNVS_DATA_ADDR      (REGS_DBGMON_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_SNVS_DATA           (*(volatile hw_dbgmon_hw_dbgmon_snvs_data_t *) HW_DBGMON_HW_DBGMON_SNVS_DATA_ADDR)
#define HW_DBGMON_HW_DBGMON_SNVS_DATA_RD()      (HW_DBGMON_HW_DBGMON_SNVS_DATA.U)
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_SNVS_DATA bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_SNVS_DATA, field DATA[31:0] (RO)
 *
 * This field contains 32-bit Data of AXI transaction in SNVS domain register
 */

#define BP_DBGMON_HW_DBGMON_SNVS_DATA_DATA      (0)
#define BM_DBGMON_HW_DBGMON_SNVS_DATA_DATA      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_SNVS_INFO - HW_DBGMON_SNVS_INFO (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned COMPLETE : 1; //!< The field indicates whether the AXI transaction in SNVS domain complete. 0: not complete, 1: Complete
        unsigned RDWR : 1; //!< The field indicates the read/write attribute of AXI transaction in SNVS domain. 0: read, 1: Write
        unsigned RESERVED0 : 14; //!< Reserved
        unsigned ID : 16; //!< The field contain the ID of the AXI transaction in SNVS domain
    } B;
} hw_dbgmon_hw_dbgmon_snvs_info_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_SNVS_INFO register
 */
#define HW_DBGMON_HW_DBGMON_SNVS_INFO_ADDR      (REGS_DBGMON_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_SNVS_INFO           (*(volatile hw_dbgmon_hw_dbgmon_snvs_info_t *) HW_DBGMON_HW_DBGMON_SNVS_INFO_ADDR)
#define HW_DBGMON_HW_DBGMON_SNVS_INFO_RD()      (HW_DBGMON_HW_DBGMON_SNVS_INFO.U)
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_SNVS_INFO bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_SNVS_INFO, field COMPLETE[0:0] (RO)
 *
 * The field indicates whether the AXI transaction in SNVS domain complete. 0: not complete, 1:
 * Complete
 */

#define BP_DBGMON_HW_DBGMON_SNVS_INFO_COMPLETE      (0)
#define BM_DBGMON_HW_DBGMON_SNVS_INFO_COMPLETE      (0x00000001)

/* --- Register HW_DBGMON_HW_DBGMON_SNVS_INFO, field RDWR[1:1] (RO)
 *
 * The field indicates the read/write attribute of AXI transaction in SNVS domain. 0: read, 1: Write
 */

#define BP_DBGMON_HW_DBGMON_SNVS_INFO_RDWR      (1)
#define BM_DBGMON_HW_DBGMON_SNVS_INFO_RDWR      (0x00000002)

/* --- Register HW_DBGMON_HW_DBGMON_SNVS_INFO, field ID[31:16] (RO)
 *
 * The field contain the ID of the AXI transaction in SNVS domain
 */

#define BP_DBGMON_HW_DBGMON_SNVS_INFO_ID      (16)
#define BM_DBGMON_HW_DBGMON_SNVS_INFO_ID      (0xffff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DBGMON_HW_DBGMON_VERSION - HW_DBGMON_VERSION (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned STEP : 16; //!< Fixed read-only value reflecting the stepping of the RTL version
        unsigned MINOR : 8; //!< Fixed read-only value reflecting the MINOR field of the RTL version
        unsigned MAJOR : 8; //!< Fixed read-only value reflecting the MAJOR field of the RTL version
    } B;
} hw_dbgmon_hw_dbgmon_version_t;
#endif

/*
 * constants & macros for entire DBGMON_HW_DBGMON_VERSION register
 */
#define HW_DBGMON_HW_DBGMON_VERSION_ADDR      (REGS_DBGMON_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_DBGMON_HW_DBGMON_VERSION           (*(volatile hw_dbgmon_hw_dbgmon_version_t *) HW_DBGMON_HW_DBGMON_VERSION_ADDR)
#define HW_DBGMON_HW_DBGMON_VERSION_RD()      (HW_DBGMON_HW_DBGMON_VERSION.U)
#endif

/*
 * constants & macros for individual DBGMON_HW_DBGMON_VERSION bitfields
 */

/* --- Register HW_DBGMON_HW_DBGMON_VERSION, field STEP[15:0] (RO)
 *
 * Fixed read-only value reflecting the stepping of the RTL version
 */

#define BP_DBGMON_HW_DBGMON_VERSION_STEP      (0)
#define BM_DBGMON_HW_DBGMON_VERSION_STEP      (0x0000ffff)

/* --- Register HW_DBGMON_HW_DBGMON_VERSION, field MINOR[23:16] (RO)
 *
 * Fixed read-only value reflecting the MINOR field of the RTL version
 */

#define BP_DBGMON_HW_DBGMON_VERSION_MINOR      (16)
#define BM_DBGMON_HW_DBGMON_VERSION_MINOR      (0x00ff0000)

/* --- Register HW_DBGMON_HW_DBGMON_VERSION, field MAJOR[31:24] (RO)
 *
 * Fixed read-only value reflecting the MAJOR field of the RTL version
 */

#define BP_DBGMON_HW_DBGMON_VERSION_MAJOR      (24)
#define BM_DBGMON_HW_DBGMON_VERSION_MAJOR      (0xff000000)


/*!
 * @brief All DBGMON module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_dbgmon_hw_dbgmon_ctrl_t HW_DBGMON_CTRL; //!< HW_DBGMON_CTRL
    reg32_t _reserved0[3];
    volatile hw_dbgmon_hw_dbgmon_master_en_t HW_DBGMON_MASTER_EN; //!< HW_DBGMON_MASTER_EN
    reg32_t _reserved1[3];
    volatile hw_dbgmon_hw_dbgmon_irq_t HW_DBGMON_IRQ; //!< HW_DBGMON_IRQ
    reg32_t _reserved2[3];
    volatile hw_dbgmon_hw_dbgmon_trap_addr_low_t HW_DBGMON_TRAP_ADDR_LOW; //!< HW_DBGMON_TRAP_ADDR_LOW
    reg32_t _reserved3[3];
    volatile hw_dbgmon_hw_dbgmon_trap_addr_high_t HW_DBGMON_TRAP_ADDR_HIGH; //!< HW_DBGMON_TRAP_ADDR_HIGH
    reg32_t _reserved4[3];
    volatile hw_dbgmon_hw_dbgmon_trap_id_t HW_DBGMON_TRAP_ID; //!< HW_DBGMON_TRAP_ID
    reg32_t _reserved5[3];
    volatile hw_dbgmon_hw_dbgmon_snvs_addr_t HW_DBGMON_SNVS_ADDR; //!< HW_DBGMON_SNVS_ADDR
    reg32_t _reserved6[3];
    volatile hw_dbgmon_hw_dbgmon_snvs_data_t HW_DBGMON_SNVS_DATA; //!< HW_DBGMON_SNVS_DATA
    reg32_t _reserved7[3];
    volatile hw_dbgmon_hw_dbgmon_snvs_info_t HW_DBGMON_SNVS_INFO; //!< HW_DBGMON_SNVS_INFO
    reg32_t _reserved8[3];
    volatile hw_dbgmon_hw_dbgmon_version_t HW_DBGMON_VERSION; //!< HW_DBGMON_VERSION
} hw_dbgmon_t;
#endif

//! @brief Macro to access all DBGMON registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_DBGMON(0)</code>.
#define HW_DBGMON     (*(volatile hw_dbgmon_t *) REGS_DBGMON_BASE)


#endif // _DBGMON_H
