/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_QOSC_REGISTERS_H__
#define __HW_QOSC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL QOSC registers defined in this header file.
 *
 * - HW_QOSC_CTRL - QOS Control Register
 * - HW_QOSC_EMI_PRIORITY0 - EMI priority Registers
 * - HW_QOSC_EMI_PRIORITY1 - EMI priority Registers
 * - HW_QOSC_VERSION - QOS Version Register
 * - HW_QOSC_ADV_MASTER_EN - Advanced QOS Master Enable Register
 * - HW_QOSC_ADV_IRQ_MASK - Advanced QOS IRQ Mask Register
 * - HW_QOSC_ADV_BOOST_IRQ - Advanced QOS Boost IRQ Register
 * - HW_QOSC_ADV_BOOST_STATUS - Advanced QOS IRQ Status Register
 * - HW_QOSC_ADV_SW_BOOST - Advanced QOS SW Boost Register
 *
 * - hw_qosc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_QOSC_BASE
#define HW_QOSC_INSTANCE_COUNT (1) //!< Number of instances of the QOSC module.
#define REGS_QOSC_BASE (0x02094000) //!< Base address for QOSC.
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
// HW_QOSC_CTRL - QOS Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_CTRL - QOS Control Register (RW)
 *
 * Reset value: 0xc0000000
 *
 * The Control Register specifies the reset state and the interrupt controls for the Performance
 * Monitor.  This register controls functions of the QoS module.
 */
typedef union _hw_qosc_ctrl
{
    reg32_t U;
    struct _hw_qosc_ctrl_bitfields
    {
        unsigned EMI_PRIORITY_MODE : 1; //!< [0] Set this bit to one to enable QoS and priority values to be set separately for the AXI fabric and EMI.
        unsigned RESERVED0 : 29; //!< [29:1] Always set this bit field to zero.
        unsigned CLKGATE : 1; //!< [30] This bit must be set to zero for normal operation. When set to one it gates off the clocks to the block.
        unsigned SFTRST : 1; //!< [31] Set to zero for normal operation. When this bit is set to one (default), then the entire block is held in its reset state.
    } B;
} hw_qosc_ctrl_t;
#endif

/*
 * constants & macros for entire QOSC_CTRL register
 */
#define HW_QOSC_CTRL_ADDR      (REGS_QOSC_BASE + 0x0)
#define HW_QOSC_CTRL_SET_ADDR  (HW_QOSC_CTRL_ADDR + 0x4)
#define HW_QOSC_CTRL_CLR_ADDR  (HW_QOSC_CTRL_ADDR + 0x8)
#define HW_QOSC_CTRL_TOG_ADDR  (HW_QOSC_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_CTRL           (*(volatile hw_qosc_ctrl_t *) HW_QOSC_CTRL_ADDR)
#define HW_QOSC_CTRL_RD()      (HW_QOSC_CTRL.U)
#define HW_QOSC_CTRL_WR(v)     (HW_QOSC_CTRL.U = (v))
#define HW_QOSC_CTRL_SET(v)    ((*(volatile reg32_t *) HW_QOSC_CTRL_SET_ADDR) = (v))
#define HW_QOSC_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_QOSC_CTRL_CLR_ADDR) = (v))
#define HW_QOSC_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_QOSC_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual QOSC_CTRL bitfields
 */

/* --- Register HW_QOSC_CTRL, field EMI_PRIORITY_MODE[0] (RW)
 *
 * Set this bit to one to enable QoS and priority values to be set separately for the AXI fabric and
 * EMI.
 *
 * Values:
 * PASSTHROUGH_PRIORITY = 0x0 - Translate and pass the AXI fabric QoS settings for each master and command type through to the EMI
 *     with each command.
 * MANUAL_PRIORITY = 0x1 - Pass the register priority settings for each master and command type through to the EMI with each
 *     command.
 */

#define BP_QOSC_CTRL_EMI_PRIORITY_MODE      (0)      //!< Bit position for QOSC_CTRL_EMI_PRIORITY_MODE.
#define BM_QOSC_CTRL_EMI_PRIORITY_MODE      (0x00000001)  //!< Bit mask for QOSC_CTRL_EMI_PRIORITY_MODE.

//! @brief Get value of QOSC_CTRL_EMI_PRIORITY_MODE from a register value.
#define BG_QOSC_CTRL_EMI_PRIORITY_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_CTRL_EMI_PRIORITY_MODE) >> BP_QOSC_CTRL_EMI_PRIORITY_MODE)

//! @brief Format value for bitfield QOSC_CTRL_EMI_PRIORITY_MODE.
#define BF_QOSC_CTRL_EMI_PRIORITY_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_CTRL_EMI_PRIORITY_MODE) & BM_QOSC_CTRL_EMI_PRIORITY_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EMI_PRIORITY_MODE field to a new value.
#define BW_QOSC_CTRL_EMI_PRIORITY_MODE(v)   BF_CS1(QOSC_CTRL, EMI_PRIORITY_MODE, v)
#endif

#define BV_QOSC_CTRL_EMI_PRIORITY_MODE__PASSTHROUGH_PRIORITY (0x0) //!< Translate and pass the AXI fabric QoS settings for each master and command type through to the EMI with each command.
#define BV_QOSC_CTRL_EMI_PRIORITY_MODE__MANUAL_PRIORITY (0x1) //!< Pass the register priority settings for each master and command type through to the EMI with each command.

/* --- Register HW_QOSC_CTRL, field CLKGATE[30] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one it gates off the clocks to the
 * block.
 *
 * Values:
 * RUN = 0x0 - Allow QoS to operate normally.
 * NO_CLKS = 0x1 - Do not clock QoS gates in order to minimize power consumption.
 */

#define BP_QOSC_CTRL_CLKGATE      (30)      //!< Bit position for QOSC_CTRL_CLKGATE.
#define BM_QOSC_CTRL_CLKGATE      (0x40000000)  //!< Bit mask for QOSC_CTRL_CLKGATE.

//! @brief Get value of QOSC_CTRL_CLKGATE from a register value.
#define BG_QOSC_CTRL_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_CTRL_CLKGATE) >> BP_QOSC_CTRL_CLKGATE)

//! @brief Format value for bitfield QOSC_CTRL_CLKGATE.
#define BF_QOSC_CTRL_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_CTRL_CLKGATE) & BM_QOSC_CTRL_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_QOSC_CTRL_CLKGATE(v)   BF_CS1(QOSC_CTRL, CLKGATE, v)
#endif

#define BV_QOSC_CTRL_CLKGATE__RUN (0x0) //!< Allow QoS to operate normally.
#define BV_QOSC_CTRL_CLKGATE__NO_CLKS (0x1) //!< Do not clock QoS gates in order to minimize power consumption.

/* --- Register HW_QOSC_CTRL, field SFTRST[31] (RW)
 *
 * Set to zero for normal operation. When this bit is set to one (default), then the entire block is
 * held in its reset state.
 *
 * Values:
 * RUN = 0x0 - Allow QoS to operate normally.
 * RESET = 0x1 - Hold QoS in reset.
 */

#define BP_QOSC_CTRL_SFTRST      (31)      //!< Bit position for QOSC_CTRL_SFTRST.
#define BM_QOSC_CTRL_SFTRST      (0x80000000)  //!< Bit mask for QOSC_CTRL_SFTRST.

//! @brief Get value of QOSC_CTRL_SFTRST from a register value.
#define BG_QOSC_CTRL_SFTRST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_CTRL_SFTRST) >> BP_QOSC_CTRL_SFTRST)

//! @brief Format value for bitfield QOSC_CTRL_SFTRST.
#define BF_QOSC_CTRL_SFTRST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_CTRL_SFTRST) & BM_QOSC_CTRL_SFTRST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_QOSC_CTRL_SFTRST(v)   BF_CS1(QOSC_CTRL, SFTRST, v)
#endif

#define BV_QOSC_CTRL_SFTRST__RUN (0x0) //!< Allow QoS to operate normally.
#define BV_QOSC_CTRL_SFTRST__RESET (0x1) //!< Hold QoS in reset.

//-------------------------------------------------------------------------------------------
// HW_QOSC_EMI_PRIORITY0 - EMI priority Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_EMI_PRIORITY0 - EMI priority Registers (RW)
 *
 * Reset value: 0x22222222
 *
 * For EMI manual priority mode, this register specifies the AWPRIORITY and ARPRIORITY parameters
 * for masters 0-3.
 */
typedef union _hw_qosc_emi_priority0
{
    reg32_t U;
    struct _hw_qosc_emi_priority0_bitfields
    {
        unsigned M0_WR : 4; //!< [3:0] Specifies the priority level for the write commands on MasterID 0. 15 = highest priority. 0 = lowest priority.
        unsigned M0_RD : 4; //!< [7:4] Specifies the priority level for the read commands on MasterID 0. 15 = highest priority. 0 = lowest priority.
        unsigned M1_WR : 4; //!< [11:8] Specifies the priority level for the write commands on MasterID 1. 15 = highest priority. 0 = lowest priority.
        unsigned M1_RD : 4; //!< [15:12] Specifies the priority level for the read commands on MasterID 1. 15 = highest priority. 0 = lowest priority.
        unsigned M2_WR : 4; //!< [19:16] Specifies the priority level for the write commands on MasterID 2. 15 = highest priority. 0 = lowest priority.
        unsigned M2_RD : 4; //!< [23:20] Specifies the priority level for the read commands on MasterID 2. 15 = highest priority. 0 = lowest priority.
        unsigned M3_WR : 4; //!< [27:24] Specifies the priority level for the write commands on MasterID 3. 15 = highest priority. 0 = lowest priority.
        unsigned M3_RD : 4; //!< [31:28] Specifies the priority level for the read commands on MasterID 3. 15 = highest priority. 0 = lowest priority.
    } B;
} hw_qosc_emi_priority0_t;
#endif

/*
 * constants & macros for entire QOSC_EMI_PRIORITY0 register
 */
#define HW_QOSC_EMI_PRIORITY0_ADDR      (REGS_QOSC_BASE + 0x10)
#define HW_QOSC_EMI_PRIORITY0_SET_ADDR  (HW_QOSC_EMI_PRIORITY0_ADDR + 0x4)
#define HW_QOSC_EMI_PRIORITY0_CLR_ADDR  (HW_QOSC_EMI_PRIORITY0_ADDR + 0x8)
#define HW_QOSC_EMI_PRIORITY0_TOG_ADDR  (HW_QOSC_EMI_PRIORITY0_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_EMI_PRIORITY0           (*(volatile hw_qosc_emi_priority0_t *) HW_QOSC_EMI_PRIORITY0_ADDR)
#define HW_QOSC_EMI_PRIORITY0_RD()      (HW_QOSC_EMI_PRIORITY0.U)
#define HW_QOSC_EMI_PRIORITY0_WR(v)     (HW_QOSC_EMI_PRIORITY0.U = (v))
#define HW_QOSC_EMI_PRIORITY0_SET(v)    ((*(volatile reg32_t *) HW_QOSC_EMI_PRIORITY0_SET_ADDR) = (v))
#define HW_QOSC_EMI_PRIORITY0_CLR(v)    ((*(volatile reg32_t *) HW_QOSC_EMI_PRIORITY0_CLR_ADDR) = (v))
#define HW_QOSC_EMI_PRIORITY0_TOG(v)    ((*(volatile reg32_t *) HW_QOSC_EMI_PRIORITY0_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual QOSC_EMI_PRIORITY0 bitfields
 */

/* --- Register HW_QOSC_EMI_PRIORITY0, field M0_WR[3:0] (RW)
 *
 * Specifies the priority level for the write commands on MasterID 0. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY0_M0_WR      (0)      //!< Bit position for QOSC_EMI_PRIORITY0_M0_WR.
#define BM_QOSC_EMI_PRIORITY0_M0_WR      (0x0000000f)  //!< Bit mask for QOSC_EMI_PRIORITY0_M0_WR.

//! @brief Get value of QOSC_EMI_PRIORITY0_M0_WR from a register value.
#define BG_QOSC_EMI_PRIORITY0_M0_WR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY0_M0_WR) >> BP_QOSC_EMI_PRIORITY0_M0_WR)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY0_M0_WR.
#define BF_QOSC_EMI_PRIORITY0_M0_WR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY0_M0_WR) & BM_QOSC_EMI_PRIORITY0_M0_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M0_WR field to a new value.
#define BW_QOSC_EMI_PRIORITY0_M0_WR(v)   BF_CS1(QOSC_EMI_PRIORITY0, M0_WR, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY0, field M0_RD[7:4] (RW)
 *
 * Specifies the priority level for the read commands on MasterID 0. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY0_M0_RD      (4)      //!< Bit position for QOSC_EMI_PRIORITY0_M0_RD.
#define BM_QOSC_EMI_PRIORITY0_M0_RD      (0x000000f0)  //!< Bit mask for QOSC_EMI_PRIORITY0_M0_RD.

//! @brief Get value of QOSC_EMI_PRIORITY0_M0_RD from a register value.
#define BG_QOSC_EMI_PRIORITY0_M0_RD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY0_M0_RD) >> BP_QOSC_EMI_PRIORITY0_M0_RD)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY0_M0_RD.
#define BF_QOSC_EMI_PRIORITY0_M0_RD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY0_M0_RD) & BM_QOSC_EMI_PRIORITY0_M0_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M0_RD field to a new value.
#define BW_QOSC_EMI_PRIORITY0_M0_RD(v)   BF_CS1(QOSC_EMI_PRIORITY0, M0_RD, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY0, field M1_WR[11:8] (RW)
 *
 * Specifies the priority level for the write commands on MasterID 1. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY0_M1_WR      (8)      //!< Bit position for QOSC_EMI_PRIORITY0_M1_WR.
#define BM_QOSC_EMI_PRIORITY0_M1_WR      (0x00000f00)  //!< Bit mask for QOSC_EMI_PRIORITY0_M1_WR.

//! @brief Get value of QOSC_EMI_PRIORITY0_M1_WR from a register value.
#define BG_QOSC_EMI_PRIORITY0_M1_WR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY0_M1_WR) >> BP_QOSC_EMI_PRIORITY0_M1_WR)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY0_M1_WR.
#define BF_QOSC_EMI_PRIORITY0_M1_WR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY0_M1_WR) & BM_QOSC_EMI_PRIORITY0_M1_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M1_WR field to a new value.
#define BW_QOSC_EMI_PRIORITY0_M1_WR(v)   BF_CS1(QOSC_EMI_PRIORITY0, M1_WR, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY0, field M1_RD[15:12] (RW)
 *
 * Specifies the priority level for the read commands on MasterID 1. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY0_M1_RD      (12)      //!< Bit position for QOSC_EMI_PRIORITY0_M1_RD.
#define BM_QOSC_EMI_PRIORITY0_M1_RD      (0x0000f000)  //!< Bit mask for QOSC_EMI_PRIORITY0_M1_RD.

//! @brief Get value of QOSC_EMI_PRIORITY0_M1_RD from a register value.
#define BG_QOSC_EMI_PRIORITY0_M1_RD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY0_M1_RD) >> BP_QOSC_EMI_PRIORITY0_M1_RD)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY0_M1_RD.
#define BF_QOSC_EMI_PRIORITY0_M1_RD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY0_M1_RD) & BM_QOSC_EMI_PRIORITY0_M1_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M1_RD field to a new value.
#define BW_QOSC_EMI_PRIORITY0_M1_RD(v)   BF_CS1(QOSC_EMI_PRIORITY0, M1_RD, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY0, field M2_WR[19:16] (RW)
 *
 * Specifies the priority level for the write commands on MasterID 2. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY0_M2_WR      (16)      //!< Bit position for QOSC_EMI_PRIORITY0_M2_WR.
#define BM_QOSC_EMI_PRIORITY0_M2_WR      (0x000f0000)  //!< Bit mask for QOSC_EMI_PRIORITY0_M2_WR.

//! @brief Get value of QOSC_EMI_PRIORITY0_M2_WR from a register value.
#define BG_QOSC_EMI_PRIORITY0_M2_WR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY0_M2_WR) >> BP_QOSC_EMI_PRIORITY0_M2_WR)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY0_M2_WR.
#define BF_QOSC_EMI_PRIORITY0_M2_WR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY0_M2_WR) & BM_QOSC_EMI_PRIORITY0_M2_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M2_WR field to a new value.
#define BW_QOSC_EMI_PRIORITY0_M2_WR(v)   BF_CS1(QOSC_EMI_PRIORITY0, M2_WR, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY0, field M2_RD[23:20] (RW)
 *
 * Specifies the priority level for the read commands on MasterID 2. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY0_M2_RD      (20)      //!< Bit position for QOSC_EMI_PRIORITY0_M2_RD.
#define BM_QOSC_EMI_PRIORITY0_M2_RD      (0x00f00000)  //!< Bit mask for QOSC_EMI_PRIORITY0_M2_RD.

//! @brief Get value of QOSC_EMI_PRIORITY0_M2_RD from a register value.
#define BG_QOSC_EMI_PRIORITY0_M2_RD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY0_M2_RD) >> BP_QOSC_EMI_PRIORITY0_M2_RD)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY0_M2_RD.
#define BF_QOSC_EMI_PRIORITY0_M2_RD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY0_M2_RD) & BM_QOSC_EMI_PRIORITY0_M2_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M2_RD field to a new value.
#define BW_QOSC_EMI_PRIORITY0_M2_RD(v)   BF_CS1(QOSC_EMI_PRIORITY0, M2_RD, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY0, field M3_WR[27:24] (RW)
 *
 * Specifies the priority level for the write commands on MasterID 3. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY0_M3_WR      (24)      //!< Bit position for QOSC_EMI_PRIORITY0_M3_WR.
#define BM_QOSC_EMI_PRIORITY0_M3_WR      (0x0f000000)  //!< Bit mask for QOSC_EMI_PRIORITY0_M3_WR.

//! @brief Get value of QOSC_EMI_PRIORITY0_M3_WR from a register value.
#define BG_QOSC_EMI_PRIORITY0_M3_WR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY0_M3_WR) >> BP_QOSC_EMI_PRIORITY0_M3_WR)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY0_M3_WR.
#define BF_QOSC_EMI_PRIORITY0_M3_WR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY0_M3_WR) & BM_QOSC_EMI_PRIORITY0_M3_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M3_WR field to a new value.
#define BW_QOSC_EMI_PRIORITY0_M3_WR(v)   BF_CS1(QOSC_EMI_PRIORITY0, M3_WR, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY0, field M3_RD[31:28] (RW)
 *
 * Specifies the priority level for the read commands on MasterID 3. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY0_M3_RD      (28)      //!< Bit position for QOSC_EMI_PRIORITY0_M3_RD.
#define BM_QOSC_EMI_PRIORITY0_M3_RD      (0xf0000000)  //!< Bit mask for QOSC_EMI_PRIORITY0_M3_RD.

//! @brief Get value of QOSC_EMI_PRIORITY0_M3_RD from a register value.
#define BG_QOSC_EMI_PRIORITY0_M3_RD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY0_M3_RD) >> BP_QOSC_EMI_PRIORITY0_M3_RD)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY0_M3_RD.
#define BF_QOSC_EMI_PRIORITY0_M3_RD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY0_M3_RD) & BM_QOSC_EMI_PRIORITY0_M3_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M3_RD field to a new value.
#define BW_QOSC_EMI_PRIORITY0_M3_RD(v)   BF_CS1(QOSC_EMI_PRIORITY0, M3_RD, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_QOSC_EMI_PRIORITY1 - EMI priority Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_EMI_PRIORITY1 - EMI priority Registers (RW)
 *
 * Reset value: 0x2222aaaa
 *
 * For EMI manual priority mode, this register specifies the AWPRIORITY and ARPRIORITY parameters
 * for masters 4-7.
 */
typedef union _hw_qosc_emi_priority1
{
    reg32_t U;
    struct _hw_qosc_emi_priority1_bitfields
    {
        unsigned M4_WR : 4; //!< [3:0] Specifies the priority level for the write commands on MasterID 4. 15 = highest priority. 0 = lowest priority.
        unsigned M4_RD : 4; //!< [7:4] Specifies the priority level for the read commands on MasterID 4. 15 = highest priority. 0 = lowest priority.
        unsigned M5_WR : 4; //!< [11:8] Specifies the priority level for the write commands on MasterID 5. 15 = highest priority. 0 = lowest priority.
        unsigned M5_RD : 4; //!< [15:12] Specifies the priority level for the read commands on MasterID 5. 15 = highest priority. 0 = lowest priority.
        unsigned M6_WR : 4; //!< [19:16] Specifies the priority level for the write commands on MasterID 6. 15 = highest priority. 0 = lowest priority.
        unsigned M6_RD : 4; //!< [23:20] Specifies the priority level for the read commands on MasterID 6. 15 = highest priority. 0 = lowest priority.
        unsigned M7_WR : 4; //!< [27:24] Specifies the priority level for the write commands on MasterID 7. 15 = highest priority. 0 = lowest priority.
        unsigned M7_RD : 4; //!< [31:28] Specifies the priority level for the read commands on MasterID 7. 15 = highest priority. 0 = lowest priority.
    } B;
} hw_qosc_emi_priority1_t;
#endif

/*
 * constants & macros for entire QOSC_EMI_PRIORITY1 register
 */
#define HW_QOSC_EMI_PRIORITY1_ADDR      (REGS_QOSC_BASE + 0x20)
#define HW_QOSC_EMI_PRIORITY1_SET_ADDR  (HW_QOSC_EMI_PRIORITY1_ADDR + 0x4)
#define HW_QOSC_EMI_PRIORITY1_CLR_ADDR  (HW_QOSC_EMI_PRIORITY1_ADDR + 0x8)
#define HW_QOSC_EMI_PRIORITY1_TOG_ADDR  (HW_QOSC_EMI_PRIORITY1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_EMI_PRIORITY1           (*(volatile hw_qosc_emi_priority1_t *) HW_QOSC_EMI_PRIORITY1_ADDR)
#define HW_QOSC_EMI_PRIORITY1_RD()      (HW_QOSC_EMI_PRIORITY1.U)
#define HW_QOSC_EMI_PRIORITY1_WR(v)     (HW_QOSC_EMI_PRIORITY1.U = (v))
#define HW_QOSC_EMI_PRIORITY1_SET(v)    ((*(volatile reg32_t *) HW_QOSC_EMI_PRIORITY1_SET_ADDR) = (v))
#define HW_QOSC_EMI_PRIORITY1_CLR(v)    ((*(volatile reg32_t *) HW_QOSC_EMI_PRIORITY1_CLR_ADDR) = (v))
#define HW_QOSC_EMI_PRIORITY1_TOG(v)    ((*(volatile reg32_t *) HW_QOSC_EMI_PRIORITY1_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual QOSC_EMI_PRIORITY1 bitfields
 */

/* --- Register HW_QOSC_EMI_PRIORITY1, field M4_WR[3:0] (RW)
 *
 * Specifies the priority level for the write commands on MasterID 4. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY1_M4_WR      (0)      //!< Bit position for QOSC_EMI_PRIORITY1_M4_WR.
#define BM_QOSC_EMI_PRIORITY1_M4_WR      (0x0000000f)  //!< Bit mask for QOSC_EMI_PRIORITY1_M4_WR.

//! @brief Get value of QOSC_EMI_PRIORITY1_M4_WR from a register value.
#define BG_QOSC_EMI_PRIORITY1_M4_WR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY1_M4_WR) >> BP_QOSC_EMI_PRIORITY1_M4_WR)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY1_M4_WR.
#define BF_QOSC_EMI_PRIORITY1_M4_WR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY1_M4_WR) & BM_QOSC_EMI_PRIORITY1_M4_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M4_WR field to a new value.
#define BW_QOSC_EMI_PRIORITY1_M4_WR(v)   BF_CS1(QOSC_EMI_PRIORITY1, M4_WR, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY1, field M4_RD[7:4] (RW)
 *
 * Specifies the priority level for the read commands on MasterID 4. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY1_M4_RD      (4)      //!< Bit position for QOSC_EMI_PRIORITY1_M4_RD.
#define BM_QOSC_EMI_PRIORITY1_M4_RD      (0x000000f0)  //!< Bit mask for QOSC_EMI_PRIORITY1_M4_RD.

//! @brief Get value of QOSC_EMI_PRIORITY1_M4_RD from a register value.
#define BG_QOSC_EMI_PRIORITY1_M4_RD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY1_M4_RD) >> BP_QOSC_EMI_PRIORITY1_M4_RD)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY1_M4_RD.
#define BF_QOSC_EMI_PRIORITY1_M4_RD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY1_M4_RD) & BM_QOSC_EMI_PRIORITY1_M4_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M4_RD field to a new value.
#define BW_QOSC_EMI_PRIORITY1_M4_RD(v)   BF_CS1(QOSC_EMI_PRIORITY1, M4_RD, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY1, field M5_WR[11:8] (RW)
 *
 * Specifies the priority level for the write commands on MasterID 5. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY1_M5_WR      (8)      //!< Bit position for QOSC_EMI_PRIORITY1_M5_WR.
#define BM_QOSC_EMI_PRIORITY1_M5_WR      (0x00000f00)  //!< Bit mask for QOSC_EMI_PRIORITY1_M5_WR.

//! @brief Get value of QOSC_EMI_PRIORITY1_M5_WR from a register value.
#define BG_QOSC_EMI_PRIORITY1_M5_WR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY1_M5_WR) >> BP_QOSC_EMI_PRIORITY1_M5_WR)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY1_M5_WR.
#define BF_QOSC_EMI_PRIORITY1_M5_WR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY1_M5_WR) & BM_QOSC_EMI_PRIORITY1_M5_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M5_WR field to a new value.
#define BW_QOSC_EMI_PRIORITY1_M5_WR(v)   BF_CS1(QOSC_EMI_PRIORITY1, M5_WR, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY1, field M5_RD[15:12] (RW)
 *
 * Specifies the priority level for the read commands on MasterID 5. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY1_M5_RD      (12)      //!< Bit position for QOSC_EMI_PRIORITY1_M5_RD.
#define BM_QOSC_EMI_PRIORITY1_M5_RD      (0x0000f000)  //!< Bit mask for QOSC_EMI_PRIORITY1_M5_RD.

//! @brief Get value of QOSC_EMI_PRIORITY1_M5_RD from a register value.
#define BG_QOSC_EMI_PRIORITY1_M5_RD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY1_M5_RD) >> BP_QOSC_EMI_PRIORITY1_M5_RD)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY1_M5_RD.
#define BF_QOSC_EMI_PRIORITY1_M5_RD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY1_M5_RD) & BM_QOSC_EMI_PRIORITY1_M5_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M5_RD field to a new value.
#define BW_QOSC_EMI_PRIORITY1_M5_RD(v)   BF_CS1(QOSC_EMI_PRIORITY1, M5_RD, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY1, field M6_WR[19:16] (RW)
 *
 * Specifies the priority level for the write commands on MasterID 6. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY1_M6_WR      (16)      //!< Bit position for QOSC_EMI_PRIORITY1_M6_WR.
#define BM_QOSC_EMI_PRIORITY1_M6_WR      (0x000f0000)  //!< Bit mask for QOSC_EMI_PRIORITY1_M6_WR.

//! @brief Get value of QOSC_EMI_PRIORITY1_M6_WR from a register value.
#define BG_QOSC_EMI_PRIORITY1_M6_WR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY1_M6_WR) >> BP_QOSC_EMI_PRIORITY1_M6_WR)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY1_M6_WR.
#define BF_QOSC_EMI_PRIORITY1_M6_WR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY1_M6_WR) & BM_QOSC_EMI_PRIORITY1_M6_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M6_WR field to a new value.
#define BW_QOSC_EMI_PRIORITY1_M6_WR(v)   BF_CS1(QOSC_EMI_PRIORITY1, M6_WR, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY1, field M6_RD[23:20] (RW)
 *
 * Specifies the priority level for the read commands on MasterID 6. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY1_M6_RD      (20)      //!< Bit position for QOSC_EMI_PRIORITY1_M6_RD.
#define BM_QOSC_EMI_PRIORITY1_M6_RD      (0x00f00000)  //!< Bit mask for QOSC_EMI_PRIORITY1_M6_RD.

//! @brief Get value of QOSC_EMI_PRIORITY1_M6_RD from a register value.
#define BG_QOSC_EMI_PRIORITY1_M6_RD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY1_M6_RD) >> BP_QOSC_EMI_PRIORITY1_M6_RD)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY1_M6_RD.
#define BF_QOSC_EMI_PRIORITY1_M6_RD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY1_M6_RD) & BM_QOSC_EMI_PRIORITY1_M6_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M6_RD field to a new value.
#define BW_QOSC_EMI_PRIORITY1_M6_RD(v)   BF_CS1(QOSC_EMI_PRIORITY1, M6_RD, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY1, field M7_WR[27:24] (RW)
 *
 * Specifies the priority level for the write commands on MasterID 7. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY1_M7_WR      (24)      //!< Bit position for QOSC_EMI_PRIORITY1_M7_WR.
#define BM_QOSC_EMI_PRIORITY1_M7_WR      (0x0f000000)  //!< Bit mask for QOSC_EMI_PRIORITY1_M7_WR.

//! @brief Get value of QOSC_EMI_PRIORITY1_M7_WR from a register value.
#define BG_QOSC_EMI_PRIORITY1_M7_WR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY1_M7_WR) >> BP_QOSC_EMI_PRIORITY1_M7_WR)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY1_M7_WR.
#define BF_QOSC_EMI_PRIORITY1_M7_WR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY1_M7_WR) & BM_QOSC_EMI_PRIORITY1_M7_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M7_WR field to a new value.
#define BW_QOSC_EMI_PRIORITY1_M7_WR(v)   BF_CS1(QOSC_EMI_PRIORITY1, M7_WR, v)
#endif

/* --- Register HW_QOSC_EMI_PRIORITY1, field M7_RD[31:28] (RW)
 *
 * Specifies the priority level for the read commands on MasterID 7. 15 = highest priority. 0 =
 * lowest priority.
 */

#define BP_QOSC_EMI_PRIORITY1_M7_RD      (28)      //!< Bit position for QOSC_EMI_PRIORITY1_M7_RD.
#define BM_QOSC_EMI_PRIORITY1_M7_RD      (0xf0000000)  //!< Bit mask for QOSC_EMI_PRIORITY1_M7_RD.

//! @brief Get value of QOSC_EMI_PRIORITY1_M7_RD from a register value.
#define BG_QOSC_EMI_PRIORITY1_M7_RD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_EMI_PRIORITY1_M7_RD) >> BP_QOSC_EMI_PRIORITY1_M7_RD)

//! @brief Format value for bitfield QOSC_EMI_PRIORITY1_M7_RD.
#define BF_QOSC_EMI_PRIORITY1_M7_RD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_EMI_PRIORITY1_M7_RD) & BM_QOSC_EMI_PRIORITY1_M7_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M7_RD field to a new value.
#define BW_QOSC_EMI_PRIORITY1_M7_RD(v)   BF_CS1(QOSC_EMI_PRIORITY1, M7_RD, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_QOSC_VERSION - QOS Version Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_VERSION - QOS Version Register (RO)
 *
 * Reset value: 0x01000000
 *
 * This register always returns a known read value for debug purposes it indicates the version of
 * the block.  This register indicates the RTL version in use.
 */
typedef union _hw_qosc_version
{
    reg32_t U;
    struct _hw_qosc_version_bitfields
    {
        unsigned STEP : 16; //!< [15:0] Fixed read-only value reflecting the stepping of the RTL version.
        unsigned MINOR : 8; //!< [23:16] Fixed read-only value reflecting the MINOR field of the RTL version.
        unsigned MAJOR : 8; //!< [31:24] Fixed read-only value reflecting the MAJOR field of the RTL version.
    } B;
} hw_qosc_version_t;
#endif

/*
 * constants & macros for entire QOSC_VERSION register
 */
#define HW_QOSC_VERSION_ADDR      (REGS_QOSC_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_VERSION           (*(volatile hw_qosc_version_t *) HW_QOSC_VERSION_ADDR)
#define HW_QOSC_VERSION_RD()      (HW_QOSC_VERSION.U)
#endif

/*
 * constants & macros for individual QOSC_VERSION bitfields
 */

/* --- Register HW_QOSC_VERSION, field STEP[15:0] (RO)
 *
 * Fixed read-only value reflecting the stepping of the RTL version.
 */

#define BP_QOSC_VERSION_STEP      (0)      //!< Bit position for QOSC_VERSION_STEP.
#define BM_QOSC_VERSION_STEP      (0x0000ffff)  //!< Bit mask for QOSC_VERSION_STEP.

//! @brief Get value of QOSC_VERSION_STEP from a register value.
#define BG_QOSC_VERSION_STEP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_VERSION_STEP) >> BP_QOSC_VERSION_STEP)

/* --- Register HW_QOSC_VERSION, field MINOR[23:16] (RO)
 *
 * Fixed read-only value reflecting the MINOR field of the RTL version.
 */

#define BP_QOSC_VERSION_MINOR      (16)      //!< Bit position for QOSC_VERSION_MINOR.
#define BM_QOSC_VERSION_MINOR      (0x00ff0000)  //!< Bit mask for QOSC_VERSION_MINOR.

//! @brief Get value of QOSC_VERSION_MINOR from a register value.
#define BG_QOSC_VERSION_MINOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_VERSION_MINOR) >> BP_QOSC_VERSION_MINOR)

/* --- Register HW_QOSC_VERSION, field MAJOR[31:24] (RO)
 *
 * Fixed read-only value reflecting the MAJOR field of the RTL version.
 */

#define BP_QOSC_VERSION_MAJOR      (24)      //!< Bit position for QOSC_VERSION_MAJOR.
#define BM_QOSC_VERSION_MAJOR      (0xff000000)  //!< Bit mask for QOSC_VERSION_MAJOR.

//! @brief Get value of QOSC_VERSION_MAJOR from a register value.
#define BG_QOSC_VERSION_MAJOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_VERSION_MAJOR) >> BP_QOSC_VERSION_MAJOR)

//-------------------------------------------------------------------------------------------
// HW_QOSC_ADV_MASTER_EN - Advanced QOS Master Enable Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_ADV_MASTER_EN - Advanced QOS Master Enable Register (RW)
 *
 * Reset value: 0x0000ffff
 *
 * This register for enable advanced QOS control of master.
 */
typedef union _hw_qosc_adv_master_en
{
    reg32_t U;
    struct _hw_qosc_adv_master_en_bitfields
    {
        unsigned M0_DISABLE : 1; //!< [0] This bit must be set to zero for normal operation. When set to one M0 reg access deny.
        unsigned M1_DISABLE : 1; //!< [1] This bit must be set to zero for normal operation. When set to one M1 reg access deny.
        unsigned M2_DISABLE : 1; //!< [2] This bit must be set to zero for normal operation. When set to one M2 reg access deny.
        unsigned M3_DISABLE : 1; //!< [3] This bit must be set to zero for normal operation. When set to one M3 reg access deny.
        unsigned M4_DISABLE : 1; //!< [4] This bit must be set to zero for normal operation. When set to one M4 reg access deny.
        unsigned M5_DISABLE : 1; //!< [5] This bit must be set to zero for normal operation. When set to one M5 reg access deny.
        unsigned M6_DISABLE : 1; //!< [6] This bit must be set to zero for normal operation. When set to one M6 reg access deny.
        unsigned M7_DISABLE : 1; //!< [7] This bit must be set to zero for normal operation. When set to one M7 reg access deny.
        unsigned S0_DISABLE : 1; //!< [8] This bit must be set to zero for normal operation. When set to one S0 reg access deny.
        unsigned RESERVED0 : 23; //!< [31:9] Reserved. Always set this bit field to zero.
    } B;
} hw_qosc_adv_master_en_t;
#endif

/*
 * constants & macros for entire QOSC_ADV_MASTER_EN register
 */
#define HW_QOSC_ADV_MASTER_EN_ADDR      (REGS_QOSC_BASE + 0x40)
#define HW_QOSC_ADV_MASTER_EN_SET_ADDR  (HW_QOSC_ADV_MASTER_EN_ADDR + 0x4)
#define HW_QOSC_ADV_MASTER_EN_CLR_ADDR  (HW_QOSC_ADV_MASTER_EN_ADDR + 0x8)
#define HW_QOSC_ADV_MASTER_EN_TOG_ADDR  (HW_QOSC_ADV_MASTER_EN_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_ADV_MASTER_EN           (*(volatile hw_qosc_adv_master_en_t *) HW_QOSC_ADV_MASTER_EN_ADDR)
#define HW_QOSC_ADV_MASTER_EN_RD()      (HW_QOSC_ADV_MASTER_EN.U)
#define HW_QOSC_ADV_MASTER_EN_WR(v)     (HW_QOSC_ADV_MASTER_EN.U = (v))
#define HW_QOSC_ADV_MASTER_EN_SET(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_MASTER_EN_SET_ADDR) = (v))
#define HW_QOSC_ADV_MASTER_EN_CLR(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_MASTER_EN_CLR_ADDR) = (v))
#define HW_QOSC_ADV_MASTER_EN_TOG(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_MASTER_EN_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual QOSC_ADV_MASTER_EN bitfields
 */

/* --- Register HW_QOSC_ADV_MASTER_EN, field M0_DISABLE[0] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one M0 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_M0_DISABLE      (0)      //!< Bit position for QOSC_ADV_MASTER_EN_M0_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_M0_DISABLE      (0x00000001)  //!< Bit mask for QOSC_ADV_MASTER_EN_M0_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_M0_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_M0_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_M0_DISABLE) >> BP_QOSC_ADV_MASTER_EN_M0_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_M0_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_M0_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_M0_DISABLE) & BM_QOSC_ADV_MASTER_EN_M0_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M0_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_M0_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, M0_DISABLE, v)
#endif

/* --- Register HW_QOSC_ADV_MASTER_EN, field M1_DISABLE[1] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one M1 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_M1_DISABLE      (1)      //!< Bit position for QOSC_ADV_MASTER_EN_M1_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_M1_DISABLE      (0x00000002)  //!< Bit mask for QOSC_ADV_MASTER_EN_M1_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_M1_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_M1_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_M1_DISABLE) >> BP_QOSC_ADV_MASTER_EN_M1_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_M1_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_M1_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_M1_DISABLE) & BM_QOSC_ADV_MASTER_EN_M1_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M1_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_M1_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, M1_DISABLE, v)
#endif

/* --- Register HW_QOSC_ADV_MASTER_EN, field M2_DISABLE[2] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one M2 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_M2_DISABLE      (2)      //!< Bit position for QOSC_ADV_MASTER_EN_M2_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_M2_DISABLE      (0x00000004)  //!< Bit mask for QOSC_ADV_MASTER_EN_M2_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_M2_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_M2_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_M2_DISABLE) >> BP_QOSC_ADV_MASTER_EN_M2_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_M2_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_M2_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_M2_DISABLE) & BM_QOSC_ADV_MASTER_EN_M2_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M2_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_M2_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, M2_DISABLE, v)
#endif

/* --- Register HW_QOSC_ADV_MASTER_EN, field M3_DISABLE[3] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one M3 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_M3_DISABLE      (3)      //!< Bit position for QOSC_ADV_MASTER_EN_M3_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_M3_DISABLE      (0x00000008)  //!< Bit mask for QOSC_ADV_MASTER_EN_M3_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_M3_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_M3_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_M3_DISABLE) >> BP_QOSC_ADV_MASTER_EN_M3_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_M3_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_M3_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_M3_DISABLE) & BM_QOSC_ADV_MASTER_EN_M3_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M3_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_M3_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, M3_DISABLE, v)
#endif

/* --- Register HW_QOSC_ADV_MASTER_EN, field M4_DISABLE[4] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one M4 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_M4_DISABLE      (4)      //!< Bit position for QOSC_ADV_MASTER_EN_M4_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_M4_DISABLE      (0x00000010)  //!< Bit mask for QOSC_ADV_MASTER_EN_M4_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_M4_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_M4_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_M4_DISABLE) >> BP_QOSC_ADV_MASTER_EN_M4_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_M4_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_M4_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_M4_DISABLE) & BM_QOSC_ADV_MASTER_EN_M4_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M4_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_M4_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, M4_DISABLE, v)
#endif

/* --- Register HW_QOSC_ADV_MASTER_EN, field M5_DISABLE[5] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one M5 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_M5_DISABLE      (5)      //!< Bit position for QOSC_ADV_MASTER_EN_M5_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_M5_DISABLE      (0x00000020)  //!< Bit mask for QOSC_ADV_MASTER_EN_M5_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_M5_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_M5_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_M5_DISABLE) >> BP_QOSC_ADV_MASTER_EN_M5_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_M5_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_M5_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_M5_DISABLE) & BM_QOSC_ADV_MASTER_EN_M5_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M5_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_M5_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, M5_DISABLE, v)
#endif

/* --- Register HW_QOSC_ADV_MASTER_EN, field M6_DISABLE[6] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one M6 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_M6_DISABLE      (6)      //!< Bit position for QOSC_ADV_MASTER_EN_M6_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_M6_DISABLE      (0x00000040)  //!< Bit mask for QOSC_ADV_MASTER_EN_M6_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_M6_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_M6_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_M6_DISABLE) >> BP_QOSC_ADV_MASTER_EN_M6_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_M6_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_M6_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_M6_DISABLE) & BM_QOSC_ADV_MASTER_EN_M6_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M6_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_M6_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, M6_DISABLE, v)
#endif

/* --- Register HW_QOSC_ADV_MASTER_EN, field M7_DISABLE[7] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one M7 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_M7_DISABLE      (7)      //!< Bit position for QOSC_ADV_MASTER_EN_M7_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_M7_DISABLE      (0x00000080)  //!< Bit mask for QOSC_ADV_MASTER_EN_M7_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_M7_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_M7_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_M7_DISABLE) >> BP_QOSC_ADV_MASTER_EN_M7_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_M7_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_M7_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_M7_DISABLE) & BM_QOSC_ADV_MASTER_EN_M7_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M7_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_M7_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, M7_DISABLE, v)
#endif

/* --- Register HW_QOSC_ADV_MASTER_EN, field S0_DISABLE[8] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one S0 reg access deny.
 */

#define BP_QOSC_ADV_MASTER_EN_S0_DISABLE      (8)      //!< Bit position for QOSC_ADV_MASTER_EN_S0_DISABLE.
#define BM_QOSC_ADV_MASTER_EN_S0_DISABLE      (0x00000100)  //!< Bit mask for QOSC_ADV_MASTER_EN_S0_DISABLE.

//! @brief Get value of QOSC_ADV_MASTER_EN_S0_DISABLE from a register value.
#define BG_QOSC_ADV_MASTER_EN_S0_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_MASTER_EN_S0_DISABLE) >> BP_QOSC_ADV_MASTER_EN_S0_DISABLE)

//! @brief Format value for bitfield QOSC_ADV_MASTER_EN_S0_DISABLE.
#define BF_QOSC_ADV_MASTER_EN_S0_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_MASTER_EN_S0_DISABLE) & BM_QOSC_ADV_MASTER_EN_S0_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the S0_DISABLE field to a new value.
#define BW_QOSC_ADV_MASTER_EN_S0_DISABLE(v)   BF_CS1(QOSC_ADV_MASTER_EN, S0_DISABLE, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_QOSC_ADV_IRQ_MASK - Advanced QOS IRQ Mask Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_ADV_IRQ_MASK - Advanced QOS IRQ Mask Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register control masking for Advanced QOS interrupt.
 */
typedef union _hw_qosc_adv_irq_mask
{
    reg32_t U;
    struct _hw_qosc_adv_irq_mask_bitfields
    {
        unsigned M0_BOOST_IRQ_EN : 1; //!< [0] Setting this bit for enable the irq of master0 boost.
        unsigned M1_BOOST_IRQ_EN : 1; //!< [1] Setting this bit for enable the irq of master1 boost.
        unsigned M2_BOOST_IRQ_EN : 1; //!< [2] Setting this bit for enable the irq of master2 boost.
        unsigned M3_BOOST_IRQ_EN : 1; //!< [3] Setting this bit for enable the irq of master3 boost.
        unsigned M4_BOOST_IRQ_EN : 1; //!< [4] Setting this bit for enable the irq of master4 boost.
        unsigned M5_BOOST_IRQ_EN : 1; //!< [5] Setting this bit for enable the irq of master5 boost.
        unsigned M6_BOOST_IRQ_EN : 1; //!< [6] Setting this bit for enable the irq of master6 boost.
        unsigned M7_BOOST_IRQ_EN : 1; //!< [7] Setting this bit for enable the irq of master7 boost.
        unsigned RESERVED0 : 24; //!< [31:8] Reserved. Always set this bit field to zero.
    } B;
} hw_qosc_adv_irq_mask_t;
#endif

/*
 * constants & macros for entire QOSC_ADV_IRQ_MASK register
 */
#define HW_QOSC_ADV_IRQ_MASK_ADDR      (REGS_QOSC_BASE + 0x50)
#define HW_QOSC_ADV_IRQ_MASK_SET_ADDR  (HW_QOSC_ADV_IRQ_MASK_ADDR + 0x4)
#define HW_QOSC_ADV_IRQ_MASK_CLR_ADDR  (HW_QOSC_ADV_IRQ_MASK_ADDR + 0x8)
#define HW_QOSC_ADV_IRQ_MASK_TOG_ADDR  (HW_QOSC_ADV_IRQ_MASK_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_ADV_IRQ_MASK           (*(volatile hw_qosc_adv_irq_mask_t *) HW_QOSC_ADV_IRQ_MASK_ADDR)
#define HW_QOSC_ADV_IRQ_MASK_RD()      (HW_QOSC_ADV_IRQ_MASK.U)
#define HW_QOSC_ADV_IRQ_MASK_WR(v)     (HW_QOSC_ADV_IRQ_MASK.U = (v))
#define HW_QOSC_ADV_IRQ_MASK_SET(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_IRQ_MASK_SET_ADDR) = (v))
#define HW_QOSC_ADV_IRQ_MASK_CLR(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_IRQ_MASK_CLR_ADDR) = (v))
#define HW_QOSC_ADV_IRQ_MASK_TOG(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_IRQ_MASK_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual QOSC_ADV_IRQ_MASK bitfields
 */

/* --- Register HW_QOSC_ADV_IRQ_MASK, field M0_BOOST_IRQ_EN[0] (RW)
 *
 * Setting this bit for enable the irq of master0 boost.
 */

#define BP_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN      (0)      //!< Bit position for QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN.
#define BM_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN      (0x00000001)  //!< Bit mask for QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN.

//! @brief Get value of QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN from a register value.
#define BG_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN) >> BP_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN)

//! @brief Format value for bitfield QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN.
#define BF_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN) & BM_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M0_BOOST_IRQ_EN field to a new value.
#define BW_QOSC_ADV_IRQ_MASK_M0_BOOST_IRQ_EN(v)   BF_CS1(QOSC_ADV_IRQ_MASK, M0_BOOST_IRQ_EN, v)
#endif

/* --- Register HW_QOSC_ADV_IRQ_MASK, field M1_BOOST_IRQ_EN[1] (RW)
 *
 * Setting this bit for enable the irq of master1 boost.
 */

#define BP_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN      (1)      //!< Bit position for QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN.
#define BM_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN      (0x00000002)  //!< Bit mask for QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN.

//! @brief Get value of QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN from a register value.
#define BG_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN) >> BP_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN)

//! @brief Format value for bitfield QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN.
#define BF_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN) & BM_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M1_BOOST_IRQ_EN field to a new value.
#define BW_QOSC_ADV_IRQ_MASK_M1_BOOST_IRQ_EN(v)   BF_CS1(QOSC_ADV_IRQ_MASK, M1_BOOST_IRQ_EN, v)
#endif

/* --- Register HW_QOSC_ADV_IRQ_MASK, field M2_BOOST_IRQ_EN[2] (RW)
 *
 * Setting this bit for enable the irq of master2 boost.
 */

#define BP_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN      (2)      //!< Bit position for QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN.
#define BM_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN      (0x00000004)  //!< Bit mask for QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN.

//! @brief Get value of QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN from a register value.
#define BG_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN) >> BP_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN)

//! @brief Format value for bitfield QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN.
#define BF_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN) & BM_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M2_BOOST_IRQ_EN field to a new value.
#define BW_QOSC_ADV_IRQ_MASK_M2_BOOST_IRQ_EN(v)   BF_CS1(QOSC_ADV_IRQ_MASK, M2_BOOST_IRQ_EN, v)
#endif

/* --- Register HW_QOSC_ADV_IRQ_MASK, field M3_BOOST_IRQ_EN[3] (RW)
 *
 * Setting this bit for enable the irq of master3 boost.
 */

#define BP_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN      (3)      //!< Bit position for QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN.
#define BM_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN      (0x00000008)  //!< Bit mask for QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN.

//! @brief Get value of QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN from a register value.
#define BG_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN) >> BP_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN)

//! @brief Format value for bitfield QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN.
#define BF_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN) & BM_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M3_BOOST_IRQ_EN field to a new value.
#define BW_QOSC_ADV_IRQ_MASK_M3_BOOST_IRQ_EN(v)   BF_CS1(QOSC_ADV_IRQ_MASK, M3_BOOST_IRQ_EN, v)
#endif

/* --- Register HW_QOSC_ADV_IRQ_MASK, field M4_BOOST_IRQ_EN[4] (RW)
 *
 * Setting this bit for enable the irq of master4 boost.
 */

#define BP_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN      (4)      //!< Bit position for QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN.
#define BM_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN      (0x00000010)  //!< Bit mask for QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN.

//! @brief Get value of QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN from a register value.
#define BG_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN) >> BP_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN)

//! @brief Format value for bitfield QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN.
#define BF_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN) & BM_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M4_BOOST_IRQ_EN field to a new value.
#define BW_QOSC_ADV_IRQ_MASK_M4_BOOST_IRQ_EN(v)   BF_CS1(QOSC_ADV_IRQ_MASK, M4_BOOST_IRQ_EN, v)
#endif

/* --- Register HW_QOSC_ADV_IRQ_MASK, field M5_BOOST_IRQ_EN[5] (RW)
 *
 * Setting this bit for enable the irq of master5 boost.
 */

#define BP_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN      (5)      //!< Bit position for QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN.
#define BM_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN      (0x00000020)  //!< Bit mask for QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN.

//! @brief Get value of QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN from a register value.
#define BG_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN) >> BP_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN)

//! @brief Format value for bitfield QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN.
#define BF_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN) & BM_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M5_BOOST_IRQ_EN field to a new value.
#define BW_QOSC_ADV_IRQ_MASK_M5_BOOST_IRQ_EN(v)   BF_CS1(QOSC_ADV_IRQ_MASK, M5_BOOST_IRQ_EN, v)
#endif

/* --- Register HW_QOSC_ADV_IRQ_MASK, field M6_BOOST_IRQ_EN[6] (RW)
 *
 * Setting this bit for enable the irq of master6 boost.
 */

#define BP_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN      (6)      //!< Bit position for QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN.
#define BM_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN      (0x00000040)  //!< Bit mask for QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN.

//! @brief Get value of QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN from a register value.
#define BG_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN) >> BP_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN)

//! @brief Format value for bitfield QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN.
#define BF_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN) & BM_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M6_BOOST_IRQ_EN field to a new value.
#define BW_QOSC_ADV_IRQ_MASK_M6_BOOST_IRQ_EN(v)   BF_CS1(QOSC_ADV_IRQ_MASK, M6_BOOST_IRQ_EN, v)
#endif

/* --- Register HW_QOSC_ADV_IRQ_MASK, field M7_BOOST_IRQ_EN[7] (RW)
 *
 * Setting this bit for enable the irq of master7 boost.
 */

#define BP_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN      (7)      //!< Bit position for QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN.
#define BM_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN      (0x00000080)  //!< Bit mask for QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN.

//! @brief Get value of QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN from a register value.
#define BG_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN) >> BP_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN)

//! @brief Format value for bitfield QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN.
#define BF_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN) & BM_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M7_BOOST_IRQ_EN field to a new value.
#define BW_QOSC_ADV_IRQ_MASK_M7_BOOST_IRQ_EN(v)   BF_CS1(QOSC_ADV_IRQ_MASK, M7_BOOST_IRQ_EN, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_QOSC_ADV_BOOST_IRQ - Advanced QOS Boost IRQ Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_ADV_BOOST_IRQ - Advanced QOS Boost IRQ Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register control Advanced QOS interrupt.
 */
typedef union _hw_qosc_adv_boost_irq
{
    reg32_t U;
    struct _hw_qosc_adv_boost_irq_bitfields
    {
        unsigned M0_BOOST_IRQ : 1; //!< [0] Interrupt of master0 boost.
        unsigned M1_BOOST_IRQ : 1; //!< [1] Interrupt of master1 boost.
        unsigned M2_BOOST_IRQ : 1; //!< [2] Interrupt of master2 boost.
        unsigned M3_BOOST_IRQ : 1; //!< [3] Interrupt of master3 boost.
        unsigned M4_BOOST_IRQ : 1; //!< [4] Interrupt of master4 boost.
        unsigned M5_BOOST_IRQ : 1; //!< [5] Interrupt of master5 boost.
        unsigned M6_BOOST_IRQ : 1; //!< [6] Interrupt of master6 boost.
        unsigned M7_BOOST_IRQ : 1; //!< [7] Interrupt of master7 boost.
        unsigned RESERVED0 : 24; //!< [31:8] Reserved. Always set this bit field to zero.
    } B;
} hw_qosc_adv_boost_irq_t;
#endif

/*
 * constants & macros for entire QOSC_ADV_BOOST_IRQ register
 */
#define HW_QOSC_ADV_BOOST_IRQ_ADDR      (REGS_QOSC_BASE + 0x60)
#define HW_QOSC_ADV_BOOST_IRQ_SET_ADDR  (HW_QOSC_ADV_BOOST_IRQ_ADDR + 0x4)
#define HW_QOSC_ADV_BOOST_IRQ_CLR_ADDR  (HW_QOSC_ADV_BOOST_IRQ_ADDR + 0x8)
#define HW_QOSC_ADV_BOOST_IRQ_TOG_ADDR  (HW_QOSC_ADV_BOOST_IRQ_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_ADV_BOOST_IRQ           (*(volatile hw_qosc_adv_boost_irq_t *) HW_QOSC_ADV_BOOST_IRQ_ADDR)
#define HW_QOSC_ADV_BOOST_IRQ_RD()      (HW_QOSC_ADV_BOOST_IRQ.U)
#define HW_QOSC_ADV_BOOST_IRQ_WR(v)     (HW_QOSC_ADV_BOOST_IRQ.U = (v))
#define HW_QOSC_ADV_BOOST_IRQ_SET(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_BOOST_IRQ_SET_ADDR) = (v))
#define HW_QOSC_ADV_BOOST_IRQ_CLR(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_BOOST_IRQ_CLR_ADDR) = (v))
#define HW_QOSC_ADV_BOOST_IRQ_TOG(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_BOOST_IRQ_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual QOSC_ADV_BOOST_IRQ bitfields
 */

/* --- Register HW_QOSC_ADV_BOOST_IRQ, field M0_BOOST_IRQ[0] (RW)
 *
 * Interrupt of master0 boost.
 */

#define BP_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ      (0)      //!< Bit position for QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ.
#define BM_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ      (0x00000001)  //!< Bit mask for QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ.

//! @brief Get value of QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ from a register value.
#define BG_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ) >> BP_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ)

//! @brief Format value for bitfield QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ.
#define BF_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ) & BM_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M0_BOOST_IRQ field to a new value.
#define BW_QOSC_ADV_BOOST_IRQ_M0_BOOST_IRQ(v)   BF_CS1(QOSC_ADV_BOOST_IRQ, M0_BOOST_IRQ, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_IRQ, field M1_BOOST_IRQ[1] (RW)
 *
 * Interrupt of master1 boost.
 */

#define BP_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ      (1)      //!< Bit position for QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ.
#define BM_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ      (0x00000002)  //!< Bit mask for QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ.

//! @brief Get value of QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ from a register value.
#define BG_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ) >> BP_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ)

//! @brief Format value for bitfield QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ.
#define BF_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ) & BM_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M1_BOOST_IRQ field to a new value.
#define BW_QOSC_ADV_BOOST_IRQ_M1_BOOST_IRQ(v)   BF_CS1(QOSC_ADV_BOOST_IRQ, M1_BOOST_IRQ, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_IRQ, field M2_BOOST_IRQ[2] (RW)
 *
 * Interrupt of master2 boost.
 */

#define BP_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ      (2)      //!< Bit position for QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ.
#define BM_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ      (0x00000004)  //!< Bit mask for QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ.

//! @brief Get value of QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ from a register value.
#define BG_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ) >> BP_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ)

//! @brief Format value for bitfield QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ.
#define BF_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ) & BM_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M2_BOOST_IRQ field to a new value.
#define BW_QOSC_ADV_BOOST_IRQ_M2_BOOST_IRQ(v)   BF_CS1(QOSC_ADV_BOOST_IRQ, M2_BOOST_IRQ, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_IRQ, field M3_BOOST_IRQ[3] (RW)
 *
 * Interrupt of master3 boost.
 */

#define BP_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ      (3)      //!< Bit position for QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ.
#define BM_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ      (0x00000008)  //!< Bit mask for QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ.

//! @brief Get value of QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ from a register value.
#define BG_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ) >> BP_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ)

//! @brief Format value for bitfield QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ.
#define BF_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ) & BM_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M3_BOOST_IRQ field to a new value.
#define BW_QOSC_ADV_BOOST_IRQ_M3_BOOST_IRQ(v)   BF_CS1(QOSC_ADV_BOOST_IRQ, M3_BOOST_IRQ, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_IRQ, field M4_BOOST_IRQ[4] (RW)
 *
 * Interrupt of master4 boost.
 */

#define BP_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ      (4)      //!< Bit position for QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ.
#define BM_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ      (0x00000010)  //!< Bit mask for QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ.

//! @brief Get value of QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ from a register value.
#define BG_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ) >> BP_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ)

//! @brief Format value for bitfield QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ.
#define BF_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ) & BM_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M4_BOOST_IRQ field to a new value.
#define BW_QOSC_ADV_BOOST_IRQ_M4_BOOST_IRQ(v)   BF_CS1(QOSC_ADV_BOOST_IRQ, M4_BOOST_IRQ, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_IRQ, field M5_BOOST_IRQ[5] (RW)
 *
 * Interrupt of master5 boost.
 */

#define BP_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ      (5)      //!< Bit position for QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ.
#define BM_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ      (0x00000020)  //!< Bit mask for QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ.

//! @brief Get value of QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ from a register value.
#define BG_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ) >> BP_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ)

//! @brief Format value for bitfield QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ.
#define BF_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ) & BM_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M5_BOOST_IRQ field to a new value.
#define BW_QOSC_ADV_BOOST_IRQ_M5_BOOST_IRQ(v)   BF_CS1(QOSC_ADV_BOOST_IRQ, M5_BOOST_IRQ, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_IRQ, field M6_BOOST_IRQ[6] (RW)
 *
 * Interrupt of master6 boost.
 */

#define BP_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ      (6)      //!< Bit position for QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ.
#define BM_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ      (0x00000040)  //!< Bit mask for QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ.

//! @brief Get value of QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ from a register value.
#define BG_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ) >> BP_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ)

//! @brief Format value for bitfield QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ.
#define BF_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ) & BM_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M6_BOOST_IRQ field to a new value.
#define BW_QOSC_ADV_BOOST_IRQ_M6_BOOST_IRQ(v)   BF_CS1(QOSC_ADV_BOOST_IRQ, M6_BOOST_IRQ, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_IRQ, field M7_BOOST_IRQ[7] (RW)
 *
 * Interrupt of master7 boost.
 */

#define BP_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ      (7)      //!< Bit position for QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ.
#define BM_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ      (0x00000080)  //!< Bit mask for QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ.

//! @brief Get value of QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ from a register value.
#define BG_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ) >> BP_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ)

//! @brief Format value for bitfield QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ.
#define BF_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ) & BM_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M7_BOOST_IRQ field to a new value.
#define BW_QOSC_ADV_BOOST_IRQ_M7_BOOST_IRQ(v)   BF_CS1(QOSC_ADV_BOOST_IRQ, M7_BOOST_IRQ, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_QOSC_ADV_BOOST_STATUS - Advanced QOS IRQ Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_ADV_BOOST_STATUS - Advanced QOS IRQ Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register control for Advanced QOS interrupt status.
 */
typedef union _hw_qosc_adv_boost_status
{
    reg32_t U;
    struct _hw_qosc_adv_boost_status_bitfields
    {
        unsigned M0_BOOST_STATUS : 1; //!< [0] Real-time Status of master0 boost.
        unsigned M1_BOOST_STATUS : 1; //!< [1] Real-time Status of master1 boost.
        unsigned M2_BOOST_STATUS : 1; //!< [2] Real-time Status of master2 boost.
        unsigned M3_BOOST_STATUS : 1; //!< [3] Real-time Status of master3 boost.
        unsigned M4_BOOST_STATUS : 1; //!< [4] Real-time Status of master4 boost.
        unsigned M5_BOOST_STATUS : 1; //!< [5] Real-time Status of master5 boost.
        unsigned M6_BOOST_STATUS : 1; //!< [6] Real-time Status of master6 boost.
        unsigned M7_BOOST_STATUS : 1; //!< [7] Real-time Status of master7 boost.
        unsigned RESERVED0 : 24; //!< [31:8] Reserved. Always set this bit field to zero.
    } B;
} hw_qosc_adv_boost_status_t;
#endif

/*
 * constants & macros for entire QOSC_ADV_BOOST_STATUS register
 */
#define HW_QOSC_ADV_BOOST_STATUS_ADDR      (REGS_QOSC_BASE + 0x70)
#define HW_QOSC_ADV_BOOST_STATUS_SET_ADDR  (HW_QOSC_ADV_BOOST_STATUS_ADDR + 0x4)
#define HW_QOSC_ADV_BOOST_STATUS_CLR_ADDR  (HW_QOSC_ADV_BOOST_STATUS_ADDR + 0x8)
#define HW_QOSC_ADV_BOOST_STATUS_TOG_ADDR  (HW_QOSC_ADV_BOOST_STATUS_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_ADV_BOOST_STATUS           (*(volatile hw_qosc_adv_boost_status_t *) HW_QOSC_ADV_BOOST_STATUS_ADDR)
#define HW_QOSC_ADV_BOOST_STATUS_RD()      (HW_QOSC_ADV_BOOST_STATUS.U)
#define HW_QOSC_ADV_BOOST_STATUS_WR(v)     (HW_QOSC_ADV_BOOST_STATUS.U = (v))
#define HW_QOSC_ADV_BOOST_STATUS_SET(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_BOOST_STATUS_SET_ADDR) = (v))
#define HW_QOSC_ADV_BOOST_STATUS_CLR(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_BOOST_STATUS_CLR_ADDR) = (v))
#define HW_QOSC_ADV_BOOST_STATUS_TOG(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_BOOST_STATUS_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual QOSC_ADV_BOOST_STATUS bitfields
 */

/* --- Register HW_QOSC_ADV_BOOST_STATUS, field M0_BOOST_STATUS[0] (RW)
 *
 * Real-time Status of master0 boost.
 */

#define BP_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS      (0)      //!< Bit position for QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS.
#define BM_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS      (0x00000001)  //!< Bit mask for QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS.

//! @brief Get value of QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS from a register value.
#define BG_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS) >> BP_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS)

//! @brief Format value for bitfield QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS.
#define BF_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS) & BM_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M0_BOOST_STATUS field to a new value.
#define BW_QOSC_ADV_BOOST_STATUS_M0_BOOST_STATUS(v)   BF_CS1(QOSC_ADV_BOOST_STATUS, M0_BOOST_STATUS, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_STATUS, field M1_BOOST_STATUS[1] (RW)
 *
 * Real-time Status of master1 boost.
 */

#define BP_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS      (1)      //!< Bit position for QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS.
#define BM_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS      (0x00000002)  //!< Bit mask for QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS.

//! @brief Get value of QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS from a register value.
#define BG_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS) >> BP_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS)

//! @brief Format value for bitfield QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS.
#define BF_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS) & BM_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M1_BOOST_STATUS field to a new value.
#define BW_QOSC_ADV_BOOST_STATUS_M1_BOOST_STATUS(v)   BF_CS1(QOSC_ADV_BOOST_STATUS, M1_BOOST_STATUS, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_STATUS, field M2_BOOST_STATUS[2] (RW)
 *
 * Real-time Status of master2 boost.
 */

#define BP_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS      (2)      //!< Bit position for QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS.
#define BM_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS      (0x00000004)  //!< Bit mask for QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS.

//! @brief Get value of QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS from a register value.
#define BG_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS) >> BP_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS)

//! @brief Format value for bitfield QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS.
#define BF_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS) & BM_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M2_BOOST_STATUS field to a new value.
#define BW_QOSC_ADV_BOOST_STATUS_M2_BOOST_STATUS(v)   BF_CS1(QOSC_ADV_BOOST_STATUS, M2_BOOST_STATUS, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_STATUS, field M3_BOOST_STATUS[3] (RW)
 *
 * Real-time Status of master3 boost.
 */

#define BP_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS      (3)      //!< Bit position for QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS.
#define BM_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS      (0x00000008)  //!< Bit mask for QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS.

//! @brief Get value of QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS from a register value.
#define BG_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS) >> BP_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS)

//! @brief Format value for bitfield QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS.
#define BF_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS) & BM_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M3_BOOST_STATUS field to a new value.
#define BW_QOSC_ADV_BOOST_STATUS_M3_BOOST_STATUS(v)   BF_CS1(QOSC_ADV_BOOST_STATUS, M3_BOOST_STATUS, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_STATUS, field M4_BOOST_STATUS[4] (RW)
 *
 * Real-time Status of master4 boost.
 */

#define BP_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS      (4)      //!< Bit position for QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS.
#define BM_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS      (0x00000010)  //!< Bit mask for QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS.

//! @brief Get value of QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS from a register value.
#define BG_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS) >> BP_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS)

//! @brief Format value for bitfield QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS.
#define BF_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS) & BM_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M4_BOOST_STATUS field to a new value.
#define BW_QOSC_ADV_BOOST_STATUS_M4_BOOST_STATUS(v)   BF_CS1(QOSC_ADV_BOOST_STATUS, M4_BOOST_STATUS, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_STATUS, field M5_BOOST_STATUS[5] (RW)
 *
 * Real-time Status of master5 boost.
 */

#define BP_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS      (5)      //!< Bit position for QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS.
#define BM_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS      (0x00000020)  //!< Bit mask for QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS.

//! @brief Get value of QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS from a register value.
#define BG_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS) >> BP_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS)

//! @brief Format value for bitfield QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS.
#define BF_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS) & BM_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M5_BOOST_STATUS field to a new value.
#define BW_QOSC_ADV_BOOST_STATUS_M5_BOOST_STATUS(v)   BF_CS1(QOSC_ADV_BOOST_STATUS, M5_BOOST_STATUS, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_STATUS, field M6_BOOST_STATUS[6] (RW)
 *
 * Real-time Status of master6 boost.
 */

#define BP_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS      (6)      //!< Bit position for QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS.
#define BM_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS      (0x00000040)  //!< Bit mask for QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS.

//! @brief Get value of QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS from a register value.
#define BG_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS) >> BP_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS)

//! @brief Format value for bitfield QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS.
#define BF_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS) & BM_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M6_BOOST_STATUS field to a new value.
#define BW_QOSC_ADV_BOOST_STATUS_M6_BOOST_STATUS(v)   BF_CS1(QOSC_ADV_BOOST_STATUS, M6_BOOST_STATUS, v)
#endif

/* --- Register HW_QOSC_ADV_BOOST_STATUS, field M7_BOOST_STATUS[7] (RW)
 *
 * Real-time Status of master7 boost.
 */

#define BP_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS      (7)      //!< Bit position for QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS.
#define BM_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS      (0x00000080)  //!< Bit mask for QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS.

//! @brief Get value of QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS from a register value.
#define BG_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS) >> BP_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS)

//! @brief Format value for bitfield QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS.
#define BF_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS) & BM_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M7_BOOST_STATUS field to a new value.
#define BW_QOSC_ADV_BOOST_STATUS_M7_BOOST_STATUS(v)   BF_CS1(QOSC_ADV_BOOST_STATUS, M7_BOOST_STATUS, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_QOSC_ADV_SW_BOOST - Advanced QOS SW Boost Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_QOSC_ADV_SW_BOOST - Advanced QOS SW Boost Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register allows software boost the individual master ports for Advanced QOS.
 */
typedef union _hw_qosc_adv_sw_boost
{
    reg32_t U;
    struct _hw_qosc_adv_sw_boost_bitfields
    {
        unsigned M0_BOOST : 1; //!< [0] Setting this bit boost the interface between master0 and QOS.
        unsigned M1_BOOST : 1; //!< [1] Setting this bit boost the interface between master1 and QOS.
        unsigned M2_BOOST : 1; //!< [2] Setting this bit boost the interface between master2 and QOS.
        unsigned M3_BOOST : 1; //!< [3] Setting this bit boost the interface between master3 and QOS.
        unsigned M4_BOOST : 1; //!< [4] Setting this bit boost the interface between master4 and QOS.
        unsigned M5_BOOST : 1; //!< [5] Setting this bit boost the interface between master5 and QOS.
        unsigned M6_BOOST : 1; //!< [6] Setting this bit boost the interface between master6 and QOS.
        unsigned M7_BOOST : 1; //!< [7] Setting this bit boost the interface between master7 and QOS.
        unsigned RESERVED0 : 24; //!< [31:8] Reserved. Always set this bit field to zero.
    } B;
} hw_qosc_adv_sw_boost_t;
#endif

/*
 * constants & macros for entire QOSC_ADV_SW_BOOST register
 */
#define HW_QOSC_ADV_SW_BOOST_ADDR      (REGS_QOSC_BASE + 0x80)
#define HW_QOSC_ADV_SW_BOOST_SET_ADDR  (HW_QOSC_ADV_SW_BOOST_ADDR + 0x4)
#define HW_QOSC_ADV_SW_BOOST_CLR_ADDR  (HW_QOSC_ADV_SW_BOOST_ADDR + 0x8)
#define HW_QOSC_ADV_SW_BOOST_TOG_ADDR  (HW_QOSC_ADV_SW_BOOST_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_QOSC_ADV_SW_BOOST           (*(volatile hw_qosc_adv_sw_boost_t *) HW_QOSC_ADV_SW_BOOST_ADDR)
#define HW_QOSC_ADV_SW_BOOST_RD()      (HW_QOSC_ADV_SW_BOOST.U)
#define HW_QOSC_ADV_SW_BOOST_WR(v)     (HW_QOSC_ADV_SW_BOOST.U = (v))
#define HW_QOSC_ADV_SW_BOOST_SET(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_SW_BOOST_SET_ADDR) = (v))
#define HW_QOSC_ADV_SW_BOOST_CLR(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_SW_BOOST_CLR_ADDR) = (v))
#define HW_QOSC_ADV_SW_BOOST_TOG(v)    ((*(volatile reg32_t *) HW_QOSC_ADV_SW_BOOST_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual QOSC_ADV_SW_BOOST bitfields
 */

/* --- Register HW_QOSC_ADV_SW_BOOST, field M0_BOOST[0] (RW)
 *
 * Setting this bit boost the interface between master0 and QOS.
 */

#define BP_QOSC_ADV_SW_BOOST_M0_BOOST      (0)      //!< Bit position for QOSC_ADV_SW_BOOST_M0_BOOST.
#define BM_QOSC_ADV_SW_BOOST_M0_BOOST      (0x00000001)  //!< Bit mask for QOSC_ADV_SW_BOOST_M0_BOOST.

//! @brief Get value of QOSC_ADV_SW_BOOST_M0_BOOST from a register value.
#define BG_QOSC_ADV_SW_BOOST_M0_BOOST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_SW_BOOST_M0_BOOST) >> BP_QOSC_ADV_SW_BOOST_M0_BOOST)

//! @brief Format value for bitfield QOSC_ADV_SW_BOOST_M0_BOOST.
#define BF_QOSC_ADV_SW_BOOST_M0_BOOST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_SW_BOOST_M0_BOOST) & BM_QOSC_ADV_SW_BOOST_M0_BOOST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M0_BOOST field to a new value.
#define BW_QOSC_ADV_SW_BOOST_M0_BOOST(v)   BF_CS1(QOSC_ADV_SW_BOOST, M0_BOOST, v)
#endif

/* --- Register HW_QOSC_ADV_SW_BOOST, field M1_BOOST[1] (RW)
 *
 * Setting this bit boost the interface between master1 and QOS.
 */

#define BP_QOSC_ADV_SW_BOOST_M1_BOOST      (1)      //!< Bit position for QOSC_ADV_SW_BOOST_M1_BOOST.
#define BM_QOSC_ADV_SW_BOOST_M1_BOOST      (0x00000002)  //!< Bit mask for QOSC_ADV_SW_BOOST_M1_BOOST.

//! @brief Get value of QOSC_ADV_SW_BOOST_M1_BOOST from a register value.
#define BG_QOSC_ADV_SW_BOOST_M1_BOOST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_SW_BOOST_M1_BOOST) >> BP_QOSC_ADV_SW_BOOST_M1_BOOST)

//! @brief Format value for bitfield QOSC_ADV_SW_BOOST_M1_BOOST.
#define BF_QOSC_ADV_SW_BOOST_M1_BOOST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_SW_BOOST_M1_BOOST) & BM_QOSC_ADV_SW_BOOST_M1_BOOST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M1_BOOST field to a new value.
#define BW_QOSC_ADV_SW_BOOST_M1_BOOST(v)   BF_CS1(QOSC_ADV_SW_BOOST, M1_BOOST, v)
#endif

/* --- Register HW_QOSC_ADV_SW_BOOST, field M2_BOOST[2] (RW)
 *
 * Setting this bit boost the interface between master2 and QOS.
 */

#define BP_QOSC_ADV_SW_BOOST_M2_BOOST      (2)      //!< Bit position for QOSC_ADV_SW_BOOST_M2_BOOST.
#define BM_QOSC_ADV_SW_BOOST_M2_BOOST      (0x00000004)  //!< Bit mask for QOSC_ADV_SW_BOOST_M2_BOOST.

//! @brief Get value of QOSC_ADV_SW_BOOST_M2_BOOST from a register value.
#define BG_QOSC_ADV_SW_BOOST_M2_BOOST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_SW_BOOST_M2_BOOST) >> BP_QOSC_ADV_SW_BOOST_M2_BOOST)

//! @brief Format value for bitfield QOSC_ADV_SW_BOOST_M2_BOOST.
#define BF_QOSC_ADV_SW_BOOST_M2_BOOST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_SW_BOOST_M2_BOOST) & BM_QOSC_ADV_SW_BOOST_M2_BOOST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M2_BOOST field to a new value.
#define BW_QOSC_ADV_SW_BOOST_M2_BOOST(v)   BF_CS1(QOSC_ADV_SW_BOOST, M2_BOOST, v)
#endif

/* --- Register HW_QOSC_ADV_SW_BOOST, field M3_BOOST[3] (RW)
 *
 * Setting this bit boost the interface between master3 and QOS.
 */

#define BP_QOSC_ADV_SW_BOOST_M3_BOOST      (3)      //!< Bit position for QOSC_ADV_SW_BOOST_M3_BOOST.
#define BM_QOSC_ADV_SW_BOOST_M3_BOOST      (0x00000008)  //!< Bit mask for QOSC_ADV_SW_BOOST_M3_BOOST.

//! @brief Get value of QOSC_ADV_SW_BOOST_M3_BOOST from a register value.
#define BG_QOSC_ADV_SW_BOOST_M3_BOOST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_SW_BOOST_M3_BOOST) >> BP_QOSC_ADV_SW_BOOST_M3_BOOST)

//! @brief Format value for bitfield QOSC_ADV_SW_BOOST_M3_BOOST.
#define BF_QOSC_ADV_SW_BOOST_M3_BOOST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_SW_BOOST_M3_BOOST) & BM_QOSC_ADV_SW_BOOST_M3_BOOST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M3_BOOST field to a new value.
#define BW_QOSC_ADV_SW_BOOST_M3_BOOST(v)   BF_CS1(QOSC_ADV_SW_BOOST, M3_BOOST, v)
#endif

/* --- Register HW_QOSC_ADV_SW_BOOST, field M4_BOOST[4] (RW)
 *
 * Setting this bit boost the interface between master4 and QOS.
 */

#define BP_QOSC_ADV_SW_BOOST_M4_BOOST      (4)      //!< Bit position for QOSC_ADV_SW_BOOST_M4_BOOST.
#define BM_QOSC_ADV_SW_BOOST_M4_BOOST      (0x00000010)  //!< Bit mask for QOSC_ADV_SW_BOOST_M4_BOOST.

//! @brief Get value of QOSC_ADV_SW_BOOST_M4_BOOST from a register value.
#define BG_QOSC_ADV_SW_BOOST_M4_BOOST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_SW_BOOST_M4_BOOST) >> BP_QOSC_ADV_SW_BOOST_M4_BOOST)

//! @brief Format value for bitfield QOSC_ADV_SW_BOOST_M4_BOOST.
#define BF_QOSC_ADV_SW_BOOST_M4_BOOST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_SW_BOOST_M4_BOOST) & BM_QOSC_ADV_SW_BOOST_M4_BOOST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M4_BOOST field to a new value.
#define BW_QOSC_ADV_SW_BOOST_M4_BOOST(v)   BF_CS1(QOSC_ADV_SW_BOOST, M4_BOOST, v)
#endif

/* --- Register HW_QOSC_ADV_SW_BOOST, field M5_BOOST[5] (RW)
 *
 * Setting this bit boost the interface between master5 and QOS.
 */

#define BP_QOSC_ADV_SW_BOOST_M5_BOOST      (5)      //!< Bit position for QOSC_ADV_SW_BOOST_M5_BOOST.
#define BM_QOSC_ADV_SW_BOOST_M5_BOOST      (0x00000020)  //!< Bit mask for QOSC_ADV_SW_BOOST_M5_BOOST.

//! @brief Get value of QOSC_ADV_SW_BOOST_M5_BOOST from a register value.
#define BG_QOSC_ADV_SW_BOOST_M5_BOOST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_SW_BOOST_M5_BOOST) >> BP_QOSC_ADV_SW_BOOST_M5_BOOST)

//! @brief Format value for bitfield QOSC_ADV_SW_BOOST_M5_BOOST.
#define BF_QOSC_ADV_SW_BOOST_M5_BOOST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_SW_BOOST_M5_BOOST) & BM_QOSC_ADV_SW_BOOST_M5_BOOST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M5_BOOST field to a new value.
#define BW_QOSC_ADV_SW_BOOST_M5_BOOST(v)   BF_CS1(QOSC_ADV_SW_BOOST, M5_BOOST, v)
#endif

/* --- Register HW_QOSC_ADV_SW_BOOST, field M6_BOOST[6] (RW)
 *
 * Setting this bit boost the interface between master6 and QOS.
 */

#define BP_QOSC_ADV_SW_BOOST_M6_BOOST      (6)      //!< Bit position for QOSC_ADV_SW_BOOST_M6_BOOST.
#define BM_QOSC_ADV_SW_BOOST_M6_BOOST      (0x00000040)  //!< Bit mask for QOSC_ADV_SW_BOOST_M6_BOOST.

//! @brief Get value of QOSC_ADV_SW_BOOST_M6_BOOST from a register value.
#define BG_QOSC_ADV_SW_BOOST_M6_BOOST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_SW_BOOST_M6_BOOST) >> BP_QOSC_ADV_SW_BOOST_M6_BOOST)

//! @brief Format value for bitfield QOSC_ADV_SW_BOOST_M6_BOOST.
#define BF_QOSC_ADV_SW_BOOST_M6_BOOST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_SW_BOOST_M6_BOOST) & BM_QOSC_ADV_SW_BOOST_M6_BOOST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M6_BOOST field to a new value.
#define BW_QOSC_ADV_SW_BOOST_M6_BOOST(v)   BF_CS1(QOSC_ADV_SW_BOOST, M6_BOOST, v)
#endif

/* --- Register HW_QOSC_ADV_SW_BOOST, field M7_BOOST[7] (RW)
 *
 * Setting this bit boost the interface between master7 and QOS.
 */

#define BP_QOSC_ADV_SW_BOOST_M7_BOOST      (7)      //!< Bit position for QOSC_ADV_SW_BOOST_M7_BOOST.
#define BM_QOSC_ADV_SW_BOOST_M7_BOOST      (0x00000080)  //!< Bit mask for QOSC_ADV_SW_BOOST_M7_BOOST.

//! @brief Get value of QOSC_ADV_SW_BOOST_M7_BOOST from a register value.
#define BG_QOSC_ADV_SW_BOOST_M7_BOOST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_QOSC_ADV_SW_BOOST_M7_BOOST) >> BP_QOSC_ADV_SW_BOOST_M7_BOOST)

//! @brief Format value for bitfield QOSC_ADV_SW_BOOST_M7_BOOST.
#define BF_QOSC_ADV_SW_BOOST_M7_BOOST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_QOSC_ADV_SW_BOOST_M7_BOOST) & BM_QOSC_ADV_SW_BOOST_M7_BOOST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the M7_BOOST field to a new value.
#define BW_QOSC_ADV_SW_BOOST_M7_BOOST(v)   BF_CS1(QOSC_ADV_SW_BOOST, M7_BOOST, v)
#endif


/*!
 * @brief All QOSC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_qosc
{
    volatile hw_qosc_ctrl_t CTRL; //!< QOS Control Register
    volatile reg32_t CTRL_SET; //!< QOS Control Register Set
    volatile reg32_t CTRL_CLR; //!< QOS Control Register Clear
    volatile reg32_t CTRL_TOG; //!< QOS Control Register Toggle
    volatile hw_qosc_emi_priority0_t EMI_PRIORITY0; //!< EMI priority Registers
    volatile reg32_t EMI_PRIORITY0_SET; //!< EMI priority Registers Set
    volatile reg32_t EMI_PRIORITY0_CLR; //!< EMI priority Registers Clear
    volatile reg32_t EMI_PRIORITY0_TOG; //!< EMI priority Registers Toggle
    volatile hw_qosc_emi_priority1_t EMI_PRIORITY1; //!< EMI priority Registers
    volatile reg32_t EMI_PRIORITY1_SET; //!< EMI priority Registers Set
    volatile reg32_t EMI_PRIORITY1_CLR; //!< EMI priority Registers Clear
    volatile reg32_t EMI_PRIORITY1_TOG; //!< EMI priority Registers Toggle
    volatile hw_qosc_version_t VERSION; //!< QOS Version Register
    reg32_t _reserved0[3];
    volatile hw_qosc_adv_master_en_t ADV_MASTER_EN; //!< Advanced QOS Master Enable Register
    volatile reg32_t ADV_MASTER_EN_SET; //!< Advanced QOS Master Enable Register Set
    volatile reg32_t ADV_MASTER_EN_CLR; //!< Advanced QOS Master Enable Register Clear
    volatile reg32_t ADV_MASTER_EN_TOG; //!< Advanced QOS Master Enable Register Toggle
    volatile hw_qosc_adv_irq_mask_t ADV_IRQ_MASK; //!< Advanced QOS IRQ Mask Register
    volatile reg32_t ADV_IRQ_MASK_SET; //!< Advanced QOS IRQ Mask Register Set
    volatile reg32_t ADV_IRQ_MASK_CLR; //!< Advanced QOS IRQ Mask Register Clear
    volatile reg32_t ADV_IRQ_MASK_TOG; //!< Advanced QOS IRQ Mask Register Toggle
    volatile hw_qosc_adv_boost_irq_t ADV_BOOST_IRQ; //!< Advanced QOS Boost IRQ Register
    volatile reg32_t ADV_BOOST_IRQ_SET; //!< Advanced QOS Boost IRQ Register Set
    volatile reg32_t ADV_BOOST_IRQ_CLR; //!< Advanced QOS Boost IRQ Register Clear
    volatile reg32_t ADV_BOOST_IRQ_TOG; //!< Advanced QOS Boost IRQ Register Toggle
    volatile hw_qosc_adv_boost_status_t ADV_BOOST_STATUS; //!< Advanced QOS IRQ Status Register
    volatile reg32_t ADV_BOOST_STATUS_SET; //!< Advanced QOS IRQ Status Register Set
    volatile reg32_t ADV_BOOST_STATUS_CLR; //!< Advanced QOS IRQ Status Register Clear
    volatile reg32_t ADV_BOOST_STATUS_TOG; //!< Advanced QOS IRQ Status Register Toggle
    volatile hw_qosc_adv_sw_boost_t ADV_SW_BOOST; //!< Advanced QOS SW Boost Register
    volatile reg32_t ADV_SW_BOOST_SET; //!< Advanced QOS SW Boost Register Set
    volatile reg32_t ADV_SW_BOOST_CLR; //!< Advanced QOS SW Boost Register Clear
    volatile reg32_t ADV_SW_BOOST_TOG; //!< Advanced QOS SW Boost Register Toggle
} hw_qosc_t;
#pragma pack()

//! @brief Macro to access all QOSC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_QOSC(0)</code>.
#define HW_QOSC     (*(volatile hw_qosc_t *) REGS_QOSC_BASE)

#endif


#endif // __HW_QOSC_REGISTERS_H__
