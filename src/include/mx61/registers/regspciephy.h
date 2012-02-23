/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _PCIE_PHY_H
#define _PCIE_PHY_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_PCIE_PHY_IDCODE_LO - Register ID Low 16 bits
 * - HW_PCIE_PHY_IDCODE_HI - Register ID High 16 bits
 * - HW_PCIE_PHY_DEBUG - Debug Register
 * - HW_PCIE_PHY_RTUNE_DEBUG - Debug Register
 * - HW_PCIE_PHY_RTUNE_STAT - 
 * - HW_PCIE_PHY_SS_PHASE - 
 * - HW_PCIE_PHY_SS_FREQ - 
 * - HW_PCIE_PHY_ATEOVRD - 
 * - HW_PCIE_PHY_MPLL_OVRD_IN_LO - 
 * - HW_PCIE_PHY_SSC_OVRD_IN - 
 * - HW_PCIE_PHY_BS_OVRD_IN - 
 * - HW_PCIE_PHY_LEVEL_OVRD_IN - 
 * - HW_PCIE_PHY_SUP_OVRD_OUT - 
 * - HW_PCIE_PHY_MPLL_ASIC_IN - 
 * - HW_PCIE_PHY_BS_ASIC_IN - 
 * - HW_PCIE_PHY_LEVEL_ASIC_IN - 
 * - HW_PCIE_PHY_SSC_ASIC_IN - 
 * - HW_PCIE_PHY_SUP_ASIC_OUT - 
 * - HW_PCIE_PHY_ATEOVRD_STATUS - 
 * - HW_PCIE_PHY_SCOPE_ENABLES - 
 * - HW_PCIE_PHY_SCOPE_SAMPLES - 
 * - HW_PCIE_PHY_SCOPE_COUNT - 
 * - HW_PCIE_PHY_SCOPE_CTL - 
 * - HW_PCIE_PHY_SCOPE_MASK - 
 * - HW_PCIE_PHY_MPLL_LOOP_CTL - 
 * - HW_PCIE_PHY_MPLL_ATB_MEAS1 - 
 * - HW_PCIE_PHY_MPLL_ATB_MEAS2 - 
 * - HW_PCIE_PHY_MPLL_OVR - 
 * - HW_PCIE_PHY_RTUNE_RTUNE_CTRL - 
 * - HW_PCIE_PHY_ATB_SWITCHYARD_CTRL - 
 * - HW_PCIE_PHY_TX_OVRD_IN_LO - 
 * - HW_PCIE_PHY_TX_OVRD_IN_HI - 
 * - HW_PCIE_PHY_TX_OVRD_DRV_LO - 
 * - HW_PCIE_PHY_TX_OVRD_OUT - 
 * - HW_PCIE_PHY_RX_OVRD_IN_LO - 
 * - HW_PCIE_PHY_RX_OVRD_IN_HI - 
 * - HW_PCIE_PHY_RX_OVRD_OUT - 
 * - HW_PCIE_PHY_TX_ASIC_IN - 
 * - HW_PCIE_PHY_TX_ASIC_DRV_LO - 
 * - HW_PCIE_PHY_TX_ASIC_DRV_HI - 
 * - HW_PCIE_PHY_TX_ASIC_OUT - 
 * - HW_PCIE_PHY_RX_ASIC_IN - 
 * - HW_PCIE_PHY_RX_ASIC_OUT - 
 * - HW_PCIE_PHY_TX_DEBUG - 
 * - HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0 - 
 * - HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1 - 
 * - HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN - 
 * - HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT - 
 * - HW_PCIE_PHY_TX_LBERT_CTL - 
 * - HW_PCIE_PHY_RX_LBERT_CTL - 
 * - HW_PCIE_PHY_RX_LBERT_ERR - 
 * - HW_PCIE_PHY_RX_SCOPE_CTL - 
 * - HW_PCIE_PHY_RX_SCOPE_PHASE - 
 * - HW_PCIE_PHY_RX_DPLL_FREQ - 
 * - HW_PCIE_PHY_RX_CDR_CTL - 
 * - HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG - 
 * - HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD - 
 * - HW_PCIE_PHY_RX_CDR_LOCK_VEC - 
 * - HW_PCIE_PHY_RX_CDR_ADAP_FSM - 
 * - HW_PCIE_PHY_RX_ATB0 - 
 * - HW_PCIE_PHY_RX_ATB1 - 
 * - HW_PCIE_PHY_RX_ENPWR0 - 
 * - HW_PCIE_PHY_RX_PMIX_PHASE - 
 * - HW_PCIE_PHY_RX_ENPWR1 - 
 * - HW_PCIE_PHY_RX_ENPWR2 - 
 * - HW_PCIE_PHY_RX_SCOPE - 
 * - HW_PCIE_PHY_TX_TXDRV_CNTRL - 
 * - HW_PCIE_PHY_TX_POWER_CTL - 
 * - HW_PCIE_PHY_TX_ALT_BLOCK - 
 * - HW_PCIE_PHY_TX_ALT_AND_LOOPBACK - 
 * - HW_PCIE_PHY_TX_TX_ATB_REG - 
 *
 * hw_pcie_phy_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PCIE_PHY_BASE
#define REGS_PCIE_PHY_BASE (0x00000000) //!< Base address for PCIE_PHY.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_IDCODE_LO - Register ID Low 16 bits (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short IDCODE_LO : 16; //!< Data
    } B;
} hw_pcie_phy_idcode_lo_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_IDCODE_LO register
 */
#define HW_PCIE_PHY_IDCODE_LO_ADDR      (REGS_PCIE_PHY_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_IDCODE_LO           (*(volatile hw_pcie_phy_idcode_lo_t *) HW_PCIE_PHY_IDCODE_LO_ADDR)
#define HW_PCIE_PHY_IDCODE_LO_RD()      (HW_PCIE_PHY_IDCODE_LO.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_IDCODE_LO bitfields
 */

/* --- Register HW_PCIE_PHY_IDCODE_LO, field IDCODE_LO (RO)
 *
 * Data
 */

#define BP_PCIE_PHY_IDCODE_LO_IDCODE_LO      0
#define BM_PCIE_PHY_IDCODE_LO_IDCODE_LO      0x0000ffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_IDCODE_HI - Register ID High 16 bits (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short IDCODE_HI : 16; //!< Data
    } B;
} hw_pcie_phy_idcode_hi_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_IDCODE_HI register
 */
#define HW_PCIE_PHY_IDCODE_HI_ADDR      (REGS_PCIE_PHY_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_IDCODE_HI           (*(volatile hw_pcie_phy_idcode_hi_t *) HW_PCIE_PHY_IDCODE_HI_ADDR)
#define HW_PCIE_PHY_IDCODE_HI_RD()      (HW_PCIE_PHY_IDCODE_HI.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_IDCODE_HI bitfields
 */

/* --- Register HW_PCIE_PHY_IDCODE_HI, field IDCODE_HI (RO)
 *
 * Data
 */

#define BP_PCIE_PHY_IDCODE_HI_IDCODE_HI      0
#define BM_PCIE_PHY_IDCODE_HI_IDCODE_HI      0x0000ffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_DEBUG - Debug Register (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short TX_VREF_SEL : 5; //!< -
        unsigned short DTB_SEL : 2; //!< Description: The lane DTB's are ORed together with the support DTB signals selected with the following encodings.
        unsigned short RESERVED0 : 10; //!< Reserved
    } B;
} hw_pcie_phy_debug_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_DEBUG register
 */
#define HW_PCIE_PHY_DEBUG_ADDR      (REGS_PCIE_PHY_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_DEBUG           (*(volatile hw_pcie_phy_debug_t *) HW_PCIE_PHY_DEBUG_ADDR)
#define HW_PCIE_PHY_DEBUG_RD()      (HW_PCIE_PHY_DEBUG.U)
#define HW_PCIE_PHY_DEBUG_WR(v)     (HW_PCIE_PHY_DEBUG.U = (v))
#define HW_PCIE_PHY_DEBUG_SET(v)    (HW_PCIE_PHY_DEBUG_WR(HW_PCIE_PHY_DEBUG_RD() |  (v)))
#define HW_PCIE_PHY_DEBUG_CLR(v)    (HW_PCIE_PHY_DEBUG_WR(HW_PCIE_PHY_DEBUG_RD() & ~(v)))
#define HW_PCIE_PHY_DEBUG_TOG(v)    (HW_PCIE_PHY_DEBUG_WR(HW_PCIE_PHY_DEBUG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_DEBUG bitfields
 */

/* --- Register HW_PCIE_PHY_DEBUG, field TX_VREF_SEL (RW)
 *
 * -
 */

#define BP_PCIE_PHY_DEBUG_TX_VREF_SEL      0
#define BM_PCIE_PHY_DEBUG_TX_VREF_SEL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_DEBUG_TX_VREF_SEL(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_DEBUG_TX_VREF_SEL)
#else
#define BF_PCIE_PHY_DEBUG_TX_VREF_SEL(v)   (((v) << 0) & BM_PCIE_PHY_DEBUG_TX_VREF_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_VREF_SEL field to a new value.
#define BW_PCIE_PHY_DEBUG_TX_VREF_SEL(v)   BF_CS1(PCIE_PHY_DEBUG, TX_VREF_SEL, v)
#endif

/* --- Register HW_PCIE_PHY_DEBUG, field DTB_SEL (RW)
 *
 * Description: The lane DTB's are ORed together with the support DTB signals selected with the
 * following encodings.
 *
 * Values:
 * 00 - None
 * 01 - reset_ctl DTB output
 * 10 - Scope DTB output
 * 11 - rtune DTB output
 */

#define BP_PCIE_PHY_DEBUG_DTB_SEL      5
#define BM_PCIE_PHY_DEBUG_DTB_SEL      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_DEBUG_DTB_SEL(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_DEBUG_DTB_SEL)
#else
#define BF_PCIE_PHY_DEBUG_DTB_SEL(v)   (((v) << 5) & BM_PCIE_PHY_DEBUG_DTB_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL field to a new value.
#define BW_PCIE_PHY_DEBUG_DTB_SEL(v)   BF_CS1(PCIE_PHY_DEBUG, DTB_SEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RTUNE_DEBUG - Debug Register (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short FLIP_COMP : 1; //!< Inverts Analog Comparator Output.
        unsigned short MAN_TUNE : 1; //!< Write a 1 to perform a manual tuning specified by the TYPE field. Starting a manual tune while a tune is currently running can cause unpredictable results. For use only when you know what the part is doing (with respect to resistor tuning). Write a 1 to perform an operation. Subsequent writes with the bit set will trigger the operation. No need to clear (0) the bit between writes.
        unsigned short SET_VAL : 1; //!< Sets value. Write a 1 to manually write the register specified by the TYPE field to the value in the VALUE field.
        unsigned short TYPE : 2; //!< Type of manual tuning or register read/write to execute.
        unsigned short VALUE : 10; //!< Value to use when triggering SET_VAL field. Only the 6 LSB's are used when setting Rx cal or Tx cal values.
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_pcie_phy_rtune_debug_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RTUNE_DEBUG register
 */
#define HW_PCIE_PHY_RTUNE_DEBUG_ADDR      (REGS_PCIE_PHY_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RTUNE_DEBUG           (*(volatile hw_pcie_phy_rtune_debug_t *) HW_PCIE_PHY_RTUNE_DEBUG_ADDR)
#define HW_PCIE_PHY_RTUNE_DEBUG_RD()      (HW_PCIE_PHY_RTUNE_DEBUG.U)
#define HW_PCIE_PHY_RTUNE_DEBUG_WR(v)     (HW_PCIE_PHY_RTUNE_DEBUG.U = (v))
#define HW_PCIE_PHY_RTUNE_DEBUG_SET(v)    (HW_PCIE_PHY_RTUNE_DEBUG_WR(HW_PCIE_PHY_RTUNE_DEBUG_RD() |  (v)))
#define HW_PCIE_PHY_RTUNE_DEBUG_CLR(v)    (HW_PCIE_PHY_RTUNE_DEBUG_WR(HW_PCIE_PHY_RTUNE_DEBUG_RD() & ~(v)))
#define HW_PCIE_PHY_RTUNE_DEBUG_TOG(v)    (HW_PCIE_PHY_RTUNE_DEBUG_WR(HW_PCIE_PHY_RTUNE_DEBUG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RTUNE_DEBUG bitfields
 */

/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field FLIP_COMP (RW)
 *
 * Inverts Analog Comparator Output.
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP      0
#define BM_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP)
#else
#define BF_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP(v)   (((v) << 0) & BM_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FLIP_COMP field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP(v)   BF_CS1(PCIE_PHY_RTUNE_DEBUG, FLIP_COMP, v)
#endif

/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field MAN_TUNE (RW)
 *
 * Write a 1 to perform a manual tuning specified by the TYPE field. Starting a manual tune while a
 * tune is currently running can cause unpredictable results. For use only when you know what the
 * part is doing (with respect to resistor tuning). Write a 1 to perform an operation. Subsequent
 * writes with the bit set will trigger the operation. No need to clear (0) the bit between writes.
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE      1
#define BM_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE)
#else
#define BF_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE(v)   (((v) << 1) & BM_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MAN_TUNE field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE(v)   BF_CS1(PCIE_PHY_RTUNE_DEBUG, MAN_TUNE, v)
#endif

/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field SET_VAL (RW)
 *
 * Sets value. Write a 1 to manually write the register specified by the TYPE field to the value in
 * the VALUE field.
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_SET_VAL      2
#define BM_PCIE_PHY_RTUNE_DEBUG_SET_VAL      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_DEBUG_SET_VAL(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RTUNE_DEBUG_SET_VAL)
#else
#define BF_PCIE_PHY_RTUNE_DEBUG_SET_VAL(v)   (((v) << 2) & BM_PCIE_PHY_RTUNE_DEBUG_SET_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_VAL field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_SET_VAL(v)   BF_CS1(PCIE_PHY_RTUNE_DEBUG, SET_VAL, v)
#endif

/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field TYPE (RW)
 *
 * Type of manual tuning or register read/write to execute.
 *
 * Values:
 * 00 - ADC, or read/write rt_value
 * 01 - Rx tune, or read/write rx_cal_val (only 6 bits)
 * 10 - Tx tune, or read/write tx_cal_val (only 6 bits)
 * 11 - Resref detect (no affect when triggering SET_VAL fi
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_TYPE      3
#define BM_PCIE_PHY_RTUNE_DEBUG_TYPE      0x00000018

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_DEBUG_TYPE(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RTUNE_DEBUG_TYPE)
#else
#define BF_PCIE_PHY_RTUNE_DEBUG_TYPE(v)   (((v) << 3) & BM_PCIE_PHY_RTUNE_DEBUG_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TYPE field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_TYPE(v)   BF_CS1(PCIE_PHY_RTUNE_DEBUG, TYPE, v)
#endif


/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field VALUE (RW)
 *
 * Value to use when triggering SET_VAL field. Only the 6 LSB's are used when setting Rx cal or Tx
 * cal values.
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_VALUE      5
#define BM_PCIE_PHY_RTUNE_DEBUG_VALUE      0x00007fe0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_DEBUG_VALUE(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RTUNE_DEBUG_VALUE)
#else
#define BF_PCIE_PHY_RTUNE_DEBUG_VALUE(v)   (((v) << 5) & BM_PCIE_PHY_RTUNE_DEBUG_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_VALUE(v)   BF_CS1(PCIE_PHY_RTUNE_DEBUG, VALUE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RTUNE_STAT -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short STAT : 10; //!< Current value of the register specifed by the RTUNE_DEBUG[TYPE] field.
        unsigned short RESERVED0 : 6; //!< Reserved
    } B;
} hw_pcie_phy_rtune_stat_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RTUNE_STAT register
 */
#define HW_PCIE_PHY_RTUNE_STAT_ADDR      (REGS_PCIE_PHY_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RTUNE_STAT           (*(volatile hw_pcie_phy_rtune_stat_t *) HW_PCIE_PHY_RTUNE_STAT_ADDR)
#define HW_PCIE_PHY_RTUNE_STAT_RD()      (HW_PCIE_PHY_RTUNE_STAT.U)
#define HW_PCIE_PHY_RTUNE_STAT_WR(v)     (HW_PCIE_PHY_RTUNE_STAT.U = (v))
#define HW_PCIE_PHY_RTUNE_STAT_SET(v)    (HW_PCIE_PHY_RTUNE_STAT_WR(HW_PCIE_PHY_RTUNE_STAT_RD() |  (v)))
#define HW_PCIE_PHY_RTUNE_STAT_CLR(v)    (HW_PCIE_PHY_RTUNE_STAT_WR(HW_PCIE_PHY_RTUNE_STAT_RD() & ~(v)))
#define HW_PCIE_PHY_RTUNE_STAT_TOG(v)    (HW_PCIE_PHY_RTUNE_STAT_WR(HW_PCIE_PHY_RTUNE_STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RTUNE_STAT bitfields
 */

/* --- Register HW_PCIE_PHY_RTUNE_STAT, field STAT (RO)
 *
 * Current value of the register specifed by the RTUNE_DEBUG[TYPE] field.
 */

#define BP_PCIE_PHY_RTUNE_STAT_STAT      0
#define BM_PCIE_PHY_RTUNE_STAT_STAT      0x000003ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SS_PHASE -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DTHR : 10; //!< Current value of the register specifed by the RTUNE_DEBUG[TYPE] field.
        unsigned short RESERVED0 : 6; //!< Reserved
    } B;
} hw_pcie_phy_ss_phase_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SS_PHASE register
 */
#define HW_PCIE_PHY_SS_PHASE_ADDR      (REGS_PCIE_PHY_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SS_PHASE           (*(volatile hw_pcie_phy_ss_phase_t *) HW_PCIE_PHY_SS_PHASE_ADDR)
#define HW_PCIE_PHY_SS_PHASE_RD()      (HW_PCIE_PHY_SS_PHASE.U)
#define HW_PCIE_PHY_SS_PHASE_WR(v)     (HW_PCIE_PHY_SS_PHASE.U = (v))
#define HW_PCIE_PHY_SS_PHASE_SET(v)    (HW_PCIE_PHY_SS_PHASE_WR(HW_PCIE_PHY_SS_PHASE_RD() |  (v)))
#define HW_PCIE_PHY_SS_PHASE_CLR(v)    (HW_PCIE_PHY_SS_PHASE_WR(HW_PCIE_PHY_SS_PHASE_RD() & ~(v)))
#define HW_PCIE_PHY_SS_PHASE_TOG(v)    (HW_PCIE_PHY_SS_PHASE_WR(HW_PCIE_PHY_SS_PHASE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SS_PHASE bitfields
 */

/* --- Register HW_PCIE_PHY_SS_PHASE, field DTHR (RW)
 *
 * Current value of the register specifed by the RTUNE_DEBUG[TYPE] field.
 */

#define BP_PCIE_PHY_SS_PHASE_DTHR      0
#define BM_PCIE_PHY_SS_PHASE_DTHR      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SS_PHASE_DTHR(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SS_PHASE_DTHR)
#else
#define BF_PCIE_PHY_SS_PHASE_DTHR(v)   (((v) << 0) & BM_PCIE_PHY_SS_PHASE_DTHR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTHR field to a new value.
#define BW_PCIE_PHY_SS_PHASE_DTHR(v)   BF_CS1(PCIE_PHY_SS_PHASE, DTHR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SS_FREQ -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short FREQ_CNT_INIT : 7; //!< Initial frequency counter value. Spread spectrum clocking must be enabled to read from or write to this register.
        unsigned short FREQ_PK : 7; //!< Peak frequency value (for changing direction). Spread spectrum clocking must be enabled to read from or write to this register.
        unsigned short FREQ_OVRD : 1; //!< Frequency register override. Spread spectrum clocking must be enabled to read from or write to this register. Must be set for PHASE writes to stick.
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_pcie_phy_ss_freq_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SS_FREQ register
 */
#define HW_PCIE_PHY_SS_FREQ_ADDR      (REGS_PCIE_PHY_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SS_FREQ           (*(volatile hw_pcie_phy_ss_freq_t *) HW_PCIE_PHY_SS_FREQ_ADDR)
#define HW_PCIE_PHY_SS_FREQ_RD()      (HW_PCIE_PHY_SS_FREQ.U)
#define HW_PCIE_PHY_SS_FREQ_WR(v)     (HW_PCIE_PHY_SS_FREQ.U = (v))
#define HW_PCIE_PHY_SS_FREQ_SET(v)    (HW_PCIE_PHY_SS_FREQ_WR(HW_PCIE_PHY_SS_FREQ_RD() |  (v)))
#define HW_PCIE_PHY_SS_FREQ_CLR(v)    (HW_PCIE_PHY_SS_FREQ_WR(HW_PCIE_PHY_SS_FREQ_RD() & ~(v)))
#define HW_PCIE_PHY_SS_FREQ_TOG(v)    (HW_PCIE_PHY_SS_FREQ_WR(HW_PCIE_PHY_SS_FREQ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SS_FREQ bitfields
 */

/* --- Register HW_PCIE_PHY_SS_FREQ, field FREQ_CNT_INIT (RW)
 *
 * Initial frequency counter value. Spread spectrum clocking must be enabled to read from or write
 * to this register.
 */

#define BP_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT      0
#define BM_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT)
#else
#define BF_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT(v)   (((v) << 0) & BM_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_CNT_INIT field to a new value.
#define BW_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT(v)   BF_CS1(PCIE_PHY_SS_FREQ, FREQ_CNT_INIT, v)
#endif

/* --- Register HW_PCIE_PHY_SS_FREQ, field FREQ_PK (RW)
 *
 * Peak frequency value (for changing direction). Spread spectrum clocking must be enabled to read
 * from or write to this register.
 */

#define BP_PCIE_PHY_SS_FREQ_FREQ_PK      7
#define BM_PCIE_PHY_SS_FREQ_FREQ_PK      0x00003f80

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SS_FREQ_FREQ_PK(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_SS_FREQ_FREQ_PK)
#else
#define BF_PCIE_PHY_SS_FREQ_FREQ_PK(v)   (((v) << 7) & BM_PCIE_PHY_SS_FREQ_FREQ_PK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_PK field to a new value.
#define BW_PCIE_PHY_SS_FREQ_FREQ_PK(v)   BF_CS1(PCIE_PHY_SS_FREQ, FREQ_PK, v)
#endif

/* --- Register HW_PCIE_PHY_SS_FREQ, field FREQ_OVRD (RW)
 *
 * Frequency register override. Spread spectrum clocking must be enabled to read from or write to
 * this register. Must be set for PHASE writes to stick.
 */

#define BP_PCIE_PHY_SS_FREQ_FREQ_OVRD      14
#define BM_PCIE_PHY_SS_FREQ_FREQ_OVRD      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SS_FREQ_FREQ_OVRD(v)   ((((reg32_t) v) << 14) & BM_PCIE_PHY_SS_FREQ_FREQ_OVRD)
#else
#define BF_PCIE_PHY_SS_FREQ_FREQ_OVRD(v)   (((v) << 14) & BM_PCIE_PHY_SS_FREQ_FREQ_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_OVRD field to a new value.
#define BW_PCIE_PHY_SS_FREQ_FREQ_OVRD(v)   BF_CS1(PCIE_PHY_SS_FREQ, FREQ_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_ATEOVRD -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RESERVED0 : 1; //!< Reserved
        unsigned short REF_CLKDIV2 : 1; //!< Override value for SSP ref_clk prescaler.
        unsigned short REF_USB2_EN : 1; //!< Override value for HSPHY ref_clk enable.
        unsigned short ATEOVRD_EN : 1; //!< Override enable for ATE signals.
        unsigned short RESERVED1 : 12; //!< Reserved
    } B;
} hw_pcie_phy_ateovrd_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_ATEOVRD register
 */
#define HW_PCIE_PHY_ATEOVRD_ADDR      (REGS_PCIE_PHY_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_ATEOVRD           (*(volatile hw_pcie_phy_ateovrd_t *) HW_PCIE_PHY_ATEOVRD_ADDR)
#define HW_PCIE_PHY_ATEOVRD_RD()      (HW_PCIE_PHY_ATEOVRD.U)
#define HW_PCIE_PHY_ATEOVRD_WR(v)     (HW_PCIE_PHY_ATEOVRD.U = (v))
#define HW_PCIE_PHY_ATEOVRD_SET(v)    (HW_PCIE_PHY_ATEOVRD_WR(HW_PCIE_PHY_ATEOVRD_RD() |  (v)))
#define HW_PCIE_PHY_ATEOVRD_CLR(v)    (HW_PCIE_PHY_ATEOVRD_WR(HW_PCIE_PHY_ATEOVRD_RD() & ~(v)))
#define HW_PCIE_PHY_ATEOVRD_TOG(v)    (HW_PCIE_PHY_ATEOVRD_WR(HW_PCIE_PHY_ATEOVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_ATEOVRD bitfields
 */

/* --- Register HW_PCIE_PHY_ATEOVRD, field REF_CLKDIV2 (RW)
 *
 * Override value for SSP ref_clk prescaler.
 */

#define BP_PCIE_PHY_ATEOVRD_REF_CLKDIV2      1
#define BM_PCIE_PHY_ATEOVRD_REF_CLKDIV2      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATEOVRD_REF_CLKDIV2(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_ATEOVRD_REF_CLKDIV2)
#else
#define BF_PCIE_PHY_ATEOVRD_REF_CLKDIV2(v)   (((v) << 1) & BM_PCIE_PHY_ATEOVRD_REF_CLKDIV2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REF_CLKDIV2 field to a new value.
#define BW_PCIE_PHY_ATEOVRD_REF_CLKDIV2(v)   BF_CS1(PCIE_PHY_ATEOVRD, REF_CLKDIV2, v)
#endif

/* --- Register HW_PCIE_PHY_ATEOVRD, field REF_USB2_EN (RW)
 *
 * Override value for HSPHY ref_clk enable.
 */

#define BP_PCIE_PHY_ATEOVRD_REF_USB2_EN      2
#define BM_PCIE_PHY_ATEOVRD_REF_USB2_EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATEOVRD_REF_USB2_EN(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_ATEOVRD_REF_USB2_EN)
#else
#define BF_PCIE_PHY_ATEOVRD_REF_USB2_EN(v)   (((v) << 2) & BM_PCIE_PHY_ATEOVRD_REF_USB2_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REF_USB2_EN field to a new value.
#define BW_PCIE_PHY_ATEOVRD_REF_USB2_EN(v)   BF_CS1(PCIE_PHY_ATEOVRD, REF_USB2_EN, v)
#endif

/* --- Register HW_PCIE_PHY_ATEOVRD, field ATEOVRD_EN (RW)
 *
 * Override enable for ATE signals.
 */

#define BP_PCIE_PHY_ATEOVRD_ATEOVRD_EN      3
#define BM_PCIE_PHY_ATEOVRD_ATEOVRD_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATEOVRD_ATEOVRD_EN(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_ATEOVRD_ATEOVRD_EN)
#else
#define BF_PCIE_PHY_ATEOVRD_ATEOVRD_EN(v)   (((v) << 3) & BM_PCIE_PHY_ATEOVRD_ATEOVRD_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEOVRD_EN field to a new value.
#define BW_PCIE_PHY_ATEOVRD_ATEOVRD_EN(v)   BF_CS1(PCIE_PHY_ATEOVRD, ATEOVRD_EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_OVRD_IN_LO -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MPLL_EN : 1; //!< Override value for mpll_en.
        unsigned short MPLL_EN_OVRD : 1; //!< Override enable for mpll_en.
        unsigned short MPLL_MULTIPLIER : 7; //!< Override value for mpll_multiplier.
        unsigned short MPLL_MULTIPLIER_OVRD : 1; //!< Override enable for mpll_multiplier.
        unsigned short RTUNE_REQ : 1; //!< Override value for rtune_req.
        unsigned short RTUNE_REQ_OVRD : 1; //!< Override enable for rtune_req.
        unsigned short RES_REQ_IN : 1; //!< Override value for res_req_in.
        unsigned short RES_REQ_IN_OVRD : 1; //!< Override enable for res_req_in.
        unsigned short RES_ACK_IN : 1; //!< Override value for res_ack_in.
        unsigned short RES_ACK_IN_OVRD : 1; //!< Override enable for res_ack_in.
    } B;
} hw_pcie_phy_mpll_ovrd_in_lo_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_MPLL_OVRD_IN_LO register
 */
#define HW_PCIE_PHY_MPLL_OVRD_IN_LO_ADDR      (REGS_PCIE_PHY_BASE + 0x11)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_MPLL_OVRD_IN_LO           (*(volatile hw_pcie_phy_mpll_ovrd_in_lo_t *) HW_PCIE_PHY_MPLL_OVRD_IN_LO_ADDR)
#define HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD()      (HW_PCIE_PHY_MPLL_OVRD_IN_LO.U)
#define HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR(v)     (HW_PCIE_PHY_MPLL_OVRD_IN_LO.U = (v))
#define HW_PCIE_PHY_MPLL_OVRD_IN_LO_SET(v)    (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR(HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() |  (v)))
#define HW_PCIE_PHY_MPLL_OVRD_IN_LO_CLR(v)    (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR(HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~(v)))
#define HW_PCIE_PHY_MPLL_OVRD_IN_LO_TOG(v)    (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR(HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_MPLL_OVRD_IN_LO bitfields
 */

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field MPLL_EN (RW)
 *
 * Override value for mpll_en.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN      0
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN(v)   (((v) << 0) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_EN field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, MPLL_EN, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field MPLL_EN_OVRD (RW)
 *
 * Override enable for mpll_en.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD      1
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD(v)   (((v) << 1) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_EN_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, MPLL_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field MPLL_MULTIPLIER (RW)
 *
 * Override value for mpll_multiplier.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER      2
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER      0x000001fc

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER(v)   (((v) << 2) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_MULTIPLIER field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, MPLL_MULTIPLIER, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field MPLL_MULTIPLIER_OVRD (RW)
 *
 * Override enable for mpll_multiplier.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD      9
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD(v)   ((((reg32_t) v) << 9) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD(v)   (((v) << 9) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_MULTIPLIER_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, MPLL_MULTIPLIER_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RTUNE_REQ (RW)
 *
 * Override value for rtune_req.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ      10
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ(v)   (((v) << 10) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_REQ field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, RTUNE_REQ, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RTUNE_REQ_OVRD (RW)
 *
 * Override enable for rtune_req.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD      11
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD(v)   ((((reg32_t) v) << 11) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD(v)   (((v) << 11) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_REQ_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, RTUNE_REQ_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RES_REQ_IN (RW)
 *
 * Override value for res_req_in.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN      12
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN(v)   ((((reg32_t) v) << 12) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN(v)   (((v) << 12) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_REQ_IN field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, RES_REQ_IN, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RES_REQ_IN_OVRD (RW)
 *
 * Override enable for res_req_in.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD      13
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD(v)   ((((reg32_t) v) << 13) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD(v)   (((v) << 13) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_REQ_IN_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, RES_REQ_IN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RES_ACK_IN (RW)
 *
 * Override value for res_ack_in.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN      14
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN(v)   ((((reg32_t) v) << 14) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN(v)   (((v) << 14) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_ACK_IN field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, RES_ACK_IN, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RES_ACK_IN_OVRD (RW)
 *
 * Override enable for res_ack_in.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD      15
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD(v)   ((((reg32_t) v) << 15) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD)
#else
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD(v)   (((v) << 15) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_ACK_IN_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD(v)   BF_CS1(PCIE_PHY_MPLL_OVRD_IN_LO, RES_ACK_IN_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SSC_OVRD_IN -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short SSC_REF_CLK_SEL : 8; //!< Override value for reference clock scaling.
        unsigned short SSC_RANGE : 2; //!< Override value for SSC modulation range.
        unsigned short SSC_EN : 1; //!< Override value for SSC enable.
        unsigned short SSC_OVRD_IN_EN : 1; //!< Override enable for Spread Spectrum generator.
        unsigned short RESERVED0 : 4; //!< Reserved
    } B;
} hw_pcie_phy_ssc_ovrd_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SSC_OVRD_IN register
 */
#define HW_PCIE_PHY_SSC_OVRD_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x13)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SSC_OVRD_IN           (*(volatile hw_pcie_phy_ssc_ovrd_in_t *) HW_PCIE_PHY_SSC_OVRD_IN_ADDR)
#define HW_PCIE_PHY_SSC_OVRD_IN_RD()      (HW_PCIE_PHY_SSC_OVRD_IN.U)
#define HW_PCIE_PHY_SSC_OVRD_IN_WR(v)     (HW_PCIE_PHY_SSC_OVRD_IN.U = (v))
#define HW_PCIE_PHY_SSC_OVRD_IN_SET(v)    (HW_PCIE_PHY_SSC_OVRD_IN_WR(HW_PCIE_PHY_SSC_OVRD_IN_RD() |  (v)))
#define HW_PCIE_PHY_SSC_OVRD_IN_CLR(v)    (HW_PCIE_PHY_SSC_OVRD_IN_WR(HW_PCIE_PHY_SSC_OVRD_IN_RD() & ~(v)))
#define HW_PCIE_PHY_SSC_OVRD_IN_TOG(v)    (HW_PCIE_PHY_SSC_OVRD_IN_WR(HW_PCIE_PHY_SSC_OVRD_IN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SSC_OVRD_IN bitfields
 */

/* --- Register HW_PCIE_PHY_SSC_OVRD_IN, field SSC_REF_CLK_SEL (RW)
 *
 * Override value for reference clock scaling.
 */

#define BP_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL      0
#define BM_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL)
#else
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL(v)   (((v) << 0) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_REF_CLK_SEL field to a new value.
#define BW_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL(v)   BF_CS1(PCIE_PHY_SSC_OVRD_IN, SSC_REF_CLK_SEL, v)
#endif

/* --- Register HW_PCIE_PHY_SSC_OVRD_IN, field SSC_RANGE (RW)
 *
 * Override value for SSC modulation range.
 */

#define BP_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE      8
#define BM_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE)
#else
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE(v)   (((v) << 8) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_RANGE field to a new value.
#define BW_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE(v)   BF_CS1(PCIE_PHY_SSC_OVRD_IN, SSC_RANGE, v)
#endif

/* --- Register HW_PCIE_PHY_SSC_OVRD_IN, field SSC_EN (RW)
 *
 * Override value for SSC enable.
 */

#define BP_PCIE_PHY_SSC_OVRD_IN_SSC_EN      10
#define BM_PCIE_PHY_SSC_OVRD_IN_SSC_EN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_EN(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_EN)
#else
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_EN(v)   (((v) << 10) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_PCIE_PHY_SSC_OVRD_IN_SSC_EN(v)   BF_CS1(PCIE_PHY_SSC_OVRD_IN, SSC_EN, v)
#endif

/* --- Register HW_PCIE_PHY_SSC_OVRD_IN, field SSC_OVRD_IN_EN (RW)
 *
 * Override enable for Spread Spectrum generator.
 */

#define BP_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN      11
#define BM_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN(v)   ((((reg32_t) v) << 11) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN)
#else
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN(v)   (((v) << 11) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_OVRD_IN_EN field to a new value.
#define BW_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN(v)   BF_CS1(PCIE_PHY_SSC_OVRD_IN, SSC_OVRD_IN_EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_BS_OVRD_IN -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short IN : 1; //!< Override value for bs_shift_dr.
        unsigned short SHIFT_DR : 1; //!< Override value for bs_shift_dr.
        unsigned short CAPTURE_DR : 1; //!< Override value for bs_capture_dr
        unsigned short UPDATE_DR : 1; //!< Override value for bs_update_dr.
        unsigned short PRELOAD : 1; //!< Override value for bs_preload.
        unsigned short EXTEST : 1; //!< Override value for bs_extest.
        unsigned short EXTEST_AC : 1; //!< Override value for bs_extest_ac.
        unsigned short CLAMP : 1; //!< Override value for bs_clamp.
        unsigned short HIGHZ : 1; //!< Override value for bs_highz.
        unsigned short INIT : 1; //!< Override value for bs_init.
        unsigned short INVERT : 1; //!< Override value for bs_invert.
        unsigned short EN : 1; //!< Enables override values for all inputs controlled by this register.
        unsigned short RESERVED0 : 4; //!< Reserved.
    } B;
} hw_pcie_phy_bs_ovrd_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_BS_OVRD_IN register
 */
#define HW_PCIE_PHY_BS_OVRD_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_BS_OVRD_IN           (*(volatile hw_pcie_phy_bs_ovrd_in_t *) HW_PCIE_PHY_BS_OVRD_IN_ADDR)
#define HW_PCIE_PHY_BS_OVRD_IN_RD()      (HW_PCIE_PHY_BS_OVRD_IN.U)
#define HW_PCIE_PHY_BS_OVRD_IN_WR(v)     (HW_PCIE_PHY_BS_OVRD_IN.U = (v))
#define HW_PCIE_PHY_BS_OVRD_IN_SET(v)    (HW_PCIE_PHY_BS_OVRD_IN_WR(HW_PCIE_PHY_BS_OVRD_IN_RD() |  (v)))
#define HW_PCIE_PHY_BS_OVRD_IN_CLR(v)    (HW_PCIE_PHY_BS_OVRD_IN_WR(HW_PCIE_PHY_BS_OVRD_IN_RD() & ~(v)))
#define HW_PCIE_PHY_BS_OVRD_IN_TOG(v)    (HW_PCIE_PHY_BS_OVRD_IN_WR(HW_PCIE_PHY_BS_OVRD_IN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_BS_OVRD_IN bitfields
 */

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field IN (RW)
 *
 * Override value for bs_shift_dr.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_IN      0
#define BM_PCIE_PHY_BS_OVRD_IN_IN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_IN(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_BS_OVRD_IN_IN)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_IN(v)   (((v) << 0) & BM_PCIE_PHY_BS_OVRD_IN_IN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IN field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_IN(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, IN, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field SHIFT_DR (RW)
 *
 * Override value for bs_shift_dr.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_SHIFT_DR      1
#define BM_PCIE_PHY_BS_OVRD_IN_SHIFT_DR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_SHIFT_DR(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_BS_OVRD_IN_SHIFT_DR)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_SHIFT_DR(v)   (((v) << 1) & BM_PCIE_PHY_BS_OVRD_IN_SHIFT_DR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SHIFT_DR field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_SHIFT_DR(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, SHIFT_DR, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field CAPTURE_DR (RW)
 *
 * Override value for bs_capture_dr
 */

#define BP_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR      2
#define BM_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR(v)   (((v) << 2) & BM_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CAPTURE_DR field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, CAPTURE_DR, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field UPDATE_DR (RW)
 *
 * Override value for bs_update_dr.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_UPDATE_DR      3
#define BM_PCIE_PHY_BS_OVRD_IN_UPDATE_DR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_UPDATE_DR(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_BS_OVRD_IN_UPDATE_DR)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_UPDATE_DR(v)   (((v) << 3) & BM_PCIE_PHY_BS_OVRD_IN_UPDATE_DR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UPDATE_DR field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_UPDATE_DR(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, UPDATE_DR, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field PRELOAD (RW)
 *
 * Override value for bs_preload.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_PRELOAD      4
#define BM_PCIE_PHY_BS_OVRD_IN_PRELOAD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_PRELOAD(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_BS_OVRD_IN_PRELOAD)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_PRELOAD(v)   (((v) << 4) & BM_PCIE_PHY_BS_OVRD_IN_PRELOAD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PRELOAD field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_PRELOAD(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, PRELOAD, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field EXTEST (RW)
 *
 * Override value for bs_extest.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_EXTEST      5
#define BM_PCIE_PHY_BS_OVRD_IN_EXTEST      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_EXTEST(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_EXTEST(v)   (((v) << 5) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTEST field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_EXTEST(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, EXTEST, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field EXTEST_AC (RW)
 *
 * Override value for bs_extest_ac.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_EXTEST_AC      6
#define BM_PCIE_PHY_BS_OVRD_IN_EXTEST_AC      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_EXTEST_AC(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST_AC)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_EXTEST_AC(v)   (((v) << 6) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST_AC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTEST_AC field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_EXTEST_AC(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, EXTEST_AC, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field CLAMP (RW)
 *
 * Override value for bs_clamp.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_CLAMP      7
#define BM_PCIE_PHY_BS_OVRD_IN_CLAMP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_CLAMP(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_BS_OVRD_IN_CLAMP)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_CLAMP(v)   (((v) << 7) & BM_PCIE_PHY_BS_OVRD_IN_CLAMP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLAMP field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_CLAMP(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, CLAMP, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field HIGHZ (RW)
 *
 * Override value for bs_highz.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_HIGHZ      8
#define BM_PCIE_PHY_BS_OVRD_IN_HIGHZ      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_HIGHZ(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_BS_OVRD_IN_HIGHZ)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_HIGHZ(v)   (((v) << 8) & BM_PCIE_PHY_BS_OVRD_IN_HIGHZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HIGHZ field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_HIGHZ(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, HIGHZ, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field INIT (RW)
 *
 * Override value for bs_init.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_INIT      9
#define BM_PCIE_PHY_BS_OVRD_IN_INIT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_INIT(v)   ((((reg32_t) v) << 9) & BM_PCIE_PHY_BS_OVRD_IN_INIT)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_INIT(v)   (((v) << 9) & BM_PCIE_PHY_BS_OVRD_IN_INIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INIT field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_INIT(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, INIT, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field INVERT (RW)
 *
 * Override value for bs_invert.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_INVERT      10
#define BM_PCIE_PHY_BS_OVRD_IN_INVERT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_INVERT(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_BS_OVRD_IN_INVERT)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_INVERT(v)   (((v) << 10) & BM_PCIE_PHY_BS_OVRD_IN_INVERT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INVERT field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_INVERT(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, INVERT, v)
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field EN (RW)
 *
 * Enables override values for all inputs controlled by this register.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_EN      11
#define BM_PCIE_PHY_BS_OVRD_IN_EN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_BS_OVRD_IN_EN(v)   ((((reg32_t) v) << 11) & BM_PCIE_PHY_BS_OVRD_IN_EN)
#else
#define BF_PCIE_PHY_BS_OVRD_IN_EN(v)   (((v) << 11) & BM_PCIE_PHY_BS_OVRD_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_EN(v)   BF_CS1(PCIE_PHY_BS_OVRD_IN, EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_LEVEL_OVRD_IN -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short LOS_LEVEL : 5; //!< Override value for los_level.
        unsigned short ACJT_LEVEL : 5; //!< Override value for acjt_level.
        unsigned short EN : 1; //!< Enables override values for all inputs controlled by this register.
        unsigned short RESERVED0 : 5; //!< Reserved.
    } B;
} hw_pcie_phy_level_ovrd_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_LEVEL_OVRD_IN register
 */
#define HW_PCIE_PHY_LEVEL_OVRD_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x15)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_LEVEL_OVRD_IN           (*(volatile hw_pcie_phy_level_ovrd_in_t *) HW_PCIE_PHY_LEVEL_OVRD_IN_ADDR)
#define HW_PCIE_PHY_LEVEL_OVRD_IN_RD()      (HW_PCIE_PHY_LEVEL_OVRD_IN.U)
#define HW_PCIE_PHY_LEVEL_OVRD_IN_WR(v)     (HW_PCIE_PHY_LEVEL_OVRD_IN.U = (v))
#define HW_PCIE_PHY_LEVEL_OVRD_IN_SET(v)    (HW_PCIE_PHY_LEVEL_OVRD_IN_WR(HW_PCIE_PHY_LEVEL_OVRD_IN_RD() |  (v)))
#define HW_PCIE_PHY_LEVEL_OVRD_IN_CLR(v)    (HW_PCIE_PHY_LEVEL_OVRD_IN_WR(HW_PCIE_PHY_LEVEL_OVRD_IN_RD() & ~(v)))
#define HW_PCIE_PHY_LEVEL_OVRD_IN_TOG(v)    (HW_PCIE_PHY_LEVEL_OVRD_IN_WR(HW_PCIE_PHY_LEVEL_OVRD_IN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_LEVEL_OVRD_IN bitfields
 */

/* --- Register HW_PCIE_PHY_LEVEL_OVRD_IN, field LOS_LEVEL (RW)
 *
 * Override value for los_level.
 */

#define BP_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL      0
#define BM_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL)
#else
#define BF_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL(v)   (((v) << 0) & BM_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS_LEVEL field to a new value.
#define BW_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL(v)   BF_CS1(PCIE_PHY_LEVEL_OVRD_IN, LOS_LEVEL, v)
#endif

/* --- Register HW_PCIE_PHY_LEVEL_OVRD_IN, field ACJT_LEVEL (RW)
 *
 * Override value for acjt_level.
 */

#define BP_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL      5
#define BM_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL)
#else
#define BF_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL(v)   (((v) << 5) & BM_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACJT_LEVEL field to a new value.
#define BW_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL(v)   BF_CS1(PCIE_PHY_LEVEL_OVRD_IN, ACJT_LEVEL, v)
#endif

/* --- Register HW_PCIE_PHY_LEVEL_OVRD_IN, field EN (RW)
 *
 * Enables override values for all inputs controlled by this register.
 */

#define BP_PCIE_PHY_LEVEL_OVRD_IN_EN      10
#define BM_PCIE_PHY_LEVEL_OVRD_IN_EN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_LEVEL_OVRD_IN_EN(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_LEVEL_OVRD_IN_EN)
#else
#define BF_PCIE_PHY_LEVEL_OVRD_IN_EN(v)   (((v) << 10) & BM_PCIE_PHY_LEVEL_OVRD_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_PCIE_PHY_LEVEL_OVRD_IN_EN(v)   BF_CS1(PCIE_PHY_LEVEL_OVRD_IN, EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SUP_OVRD_OUT -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RES_ACK_OUT : 1; //!< Override value for res_ack_out output.
        unsigned short RES_ACK_OUT_OVRD : 1; //!< Override enable for res_ack_out output.
        unsigned short RES_REQ_OUT : 1; //!< Override value for res_req_out output.
        unsigned short RES_REQ_OUT_OVRD : 1; //!< Override enable for res_req_out output.
        unsigned short RTUNE_ACK : 1; //!< Override value for rtune_ack output.
        unsigned short RTUNE_ACK_OVRD : 1; //!< Override enable for rtune_ack output.
        unsigned short BS_OUT : 1; //!< Override value for bs_out output.
        unsigned short BS_OUT_OVRD : 1; //!< Override enable for bs_out output.
        unsigned short MPLL_STATE : 1; //!< Override value for mpll_state output.
        unsigned short MPLL_STATE_OVRD : 1; //!< Override enable for mpll_state output.
        unsigned short RESERVED0 : 6; //!< Reserved.
    } B;
} hw_pcie_phy_sup_ovrd_out_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SUP_OVRD_OUT register
 */
#define HW_PCIE_PHY_SUP_OVRD_OUT_ADDR      (REGS_PCIE_PHY_BASE + 0x16)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SUP_OVRD_OUT           (*(volatile hw_pcie_phy_sup_ovrd_out_t *) HW_PCIE_PHY_SUP_OVRD_OUT_ADDR)
#define HW_PCIE_PHY_SUP_OVRD_OUT_RD()      (HW_PCIE_PHY_SUP_OVRD_OUT.U)
#define HW_PCIE_PHY_SUP_OVRD_OUT_WR(v)     (HW_PCIE_PHY_SUP_OVRD_OUT.U = (v))
#define HW_PCIE_PHY_SUP_OVRD_OUT_SET(v)    (HW_PCIE_PHY_SUP_OVRD_OUT_WR(HW_PCIE_PHY_SUP_OVRD_OUT_RD() |  (v)))
#define HW_PCIE_PHY_SUP_OVRD_OUT_CLR(v)    (HW_PCIE_PHY_SUP_OVRD_OUT_WR(HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~(v)))
#define HW_PCIE_PHY_SUP_OVRD_OUT_TOG(v)    (HW_PCIE_PHY_SUP_OVRD_OUT_WR(HW_PCIE_PHY_SUP_OVRD_OUT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SUP_OVRD_OUT bitfields
 */

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RES_ACK_OUT (RW)
 *
 * Override value for res_ack_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT      0
#define BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT(v)   (((v) << 0) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_ACK_OUT field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, RES_ACK_OUT, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RES_ACK_OUT_OVRD (RW)
 *
 * Override enable for res_ack_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD      1
#define BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD(v)   (((v) << 1) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_ACK_OUT_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, RES_ACK_OUT_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RES_REQ_OUT (RW)
 *
 * Override value for res_req_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT      2
#define BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT(v)   (((v) << 2) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_REQ_OUT field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, RES_REQ_OUT, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RES_REQ_OUT_OVRD (RW)
 *
 * Override enable for res_req_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD      3
#define BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD(v)   (((v) << 3) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_REQ_OUT_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, RES_REQ_OUT_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RTUNE_ACK (RW)
 *
 * Override value for rtune_ack output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK      4
#define BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK(v)   (((v) << 4) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_ACK field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, RTUNE_ACK, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RTUNE_ACK_OVRD (RW)
 *
 * Override enable for rtune_ack output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD      5
#define BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD(v)   (((v) << 5) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_ACK_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, RTUNE_ACK_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field BS_OUT (RW)
 *
 * Override value for bs_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT      6
#define BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT(v)   (((v) << 6) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BS_OUT field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_BS_OUT(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, BS_OUT, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field BS_OUT_OVRD (RW)
 *
 * Override enable for bs_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD      7
#define BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD(v)   (((v) << 7) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BS_OUT_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, BS_OUT_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field MPLL_STATE (RW)
 *
 * Override value for mpll_state output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE      8
#define BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE(v)   (((v) << 8) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_STATE field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, MPLL_STATE, v)
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field MPLL_STATE_OVRD (RW)
 *
 * Override enable for mpll_state output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD      9
#define BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD(v)   ((((reg32_t) v) << 9) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD)
#else
#define BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD(v)   (((v) << 9) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_STATE_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD(v)   BF_CS1(PCIE_PHY_SUP_OVRD_OUT, MPLL_STATE_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_ASIC_IN -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MPLL_EN : 1; //!< Value from ASIC for mpll_en.
        unsigned short MPLL_MULTIPLIER : 7; //!< Value from ASIC for mpll_multiplier.
        unsigned short RTUNE_REQ : 1; //!< Value from ASIC for rtune_req.
        unsigned short RES_REQ_IN : 1; //!< Value from ASIC for res_req_in.
        unsigned short RES_ACK_IN : 1; //!< Value from ASIC for res_ack_in.
        unsigned short MPLL_QWORD_CLK_EN : 1; //!< Value from ASIC for mpll_qword_clk_en.
        unsigned short MPLL_DWORD_CLK_EN : 1; //!< Value from ASIC for mpll_dword_clk_en.
        unsigned short MPLL_WORD_CLK_EN : 1; //!< Value from ASIC for mpll_word_clk_en.
        unsigned short RESERVED0 : 2; //!< Reserved.
    } B;
} hw_pcie_phy_mpll_asic_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_MPLL_ASIC_IN register
 */
#define HW_PCIE_PHY_MPLL_ASIC_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x17)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_MPLL_ASIC_IN           (*(volatile hw_pcie_phy_mpll_asic_in_t *) HW_PCIE_PHY_MPLL_ASIC_IN_ADDR)
#define HW_PCIE_PHY_MPLL_ASIC_IN_RD()      (HW_PCIE_PHY_MPLL_ASIC_IN.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_MPLL_ASIC_IN bitfields
 */

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_EN (RO)
 *
 * Value from ASIC for mpll_en.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_EN      0
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_EN      0x00000001

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_MULTIPLIER (RO)
 *
 * Value from ASIC for mpll_multiplier.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER      1
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER      0x000000fe

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field RTUNE_REQ (RO)
 *
 * Value from ASIC for rtune_req.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ      8
#define BM_PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ      0x00000100

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field RES_REQ_IN (RO)
 *
 * Value from ASIC for res_req_in.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN      9
#define BM_PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN      0x00000200

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field RES_ACK_IN (RO)
 *
 * Value from ASIC for res_ack_in.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN      10
#define BM_PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN      0x00000400

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_QWORD_CLK_EN (RO)
 *
 * Value from ASIC for mpll_qword_clk_en.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN      11
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN      0x00000800

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_DWORD_CLK_EN (RO)
 *
 * Value from ASIC for mpll_dword_clk_en.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN      12
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN      0x00001000

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_WORD_CLK_EN (RO)
 *
 * Value from ASIC for mpll_word_clk_en.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN      13
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN      0x00002000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_BS_ASIC_IN -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short IN : 1; //!< Value from ASIC for bs_in.
        unsigned short SHIFT_DR : 1; //!< Value from ASIC for bs_shift_dr.
        unsigned short CAPTURE_DR : 1; //!< Value from ASIC for bs_capture_dr.
        unsigned short UPDATE_DR : 1; //!< Value from ASIC for bs_update_dr.
        unsigned short PRELOAD : 1; //!< Value from ASIC for bs_preload.
        unsigned short EXTEST : 1; //!< Value from ASIC for bs_extest.
        unsigned short EXTEST_AC : 1; //!< Value from ASIC for bs_extest_ac.
        unsigned short CLAMP : 1; //!< Value from ASIC for bs_clamp.
        unsigned short HIGHZ : 1; //!< Value from ASIC for bs_highz.
        unsigned short INIT : 1; //!< Value from ASIC for bs_init.
        unsigned short INVERT : 1; //!< Value from ASIC for bs_invert.
        unsigned short RESERVED0 : 5; //!< Reserved.
    } B;
} hw_pcie_phy_bs_asic_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_BS_ASIC_IN register
 */
#define HW_PCIE_PHY_BS_ASIC_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_BS_ASIC_IN           (*(volatile hw_pcie_phy_bs_asic_in_t *) HW_PCIE_PHY_BS_ASIC_IN_ADDR)
#define HW_PCIE_PHY_BS_ASIC_IN_RD()      (HW_PCIE_PHY_BS_ASIC_IN.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_BS_ASIC_IN bitfields
 */

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field IN (RO)
 *
 * Value from ASIC for bs_in.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_IN      0
#define BM_PCIE_PHY_BS_ASIC_IN_IN      0x00000001

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field SHIFT_DR (RO)
 *
 * Value from ASIC for bs_shift_dr.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_SHIFT_DR      1
#define BM_PCIE_PHY_BS_ASIC_IN_SHIFT_DR      0x00000002

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field CAPTURE_DR (RO)
 *
 * Value from ASIC for bs_capture_dr.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_CAPTURE_DR      2
#define BM_PCIE_PHY_BS_ASIC_IN_CAPTURE_DR      0x00000004

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field UPDATE_DR (RO)
 *
 * Value from ASIC for bs_update_dr.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_UPDATE_DR      3
#define BM_PCIE_PHY_BS_ASIC_IN_UPDATE_DR      0x00000008

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field PRELOAD (RO)
 *
 * Value from ASIC for bs_preload.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_PRELOAD      4
#define BM_PCIE_PHY_BS_ASIC_IN_PRELOAD      0x00000010

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field EXTEST (RO)
 *
 * Value from ASIC for bs_extest.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_EXTEST      5
#define BM_PCIE_PHY_BS_ASIC_IN_EXTEST      0x00000020

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field EXTEST_AC (RO)
 *
 * Value from ASIC for bs_extest_ac.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_EXTEST_AC      6
#define BM_PCIE_PHY_BS_ASIC_IN_EXTEST_AC      0x00000040

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field CLAMP (RO)
 *
 * Value from ASIC for bs_clamp.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_CLAMP      7
#define BM_PCIE_PHY_BS_ASIC_IN_CLAMP      0x00000080

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field HIGHZ (RO)
 *
 * Value from ASIC for bs_highz.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_HIGHZ      8
#define BM_PCIE_PHY_BS_ASIC_IN_HIGHZ      0x00000100

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field INIT (RO)
 *
 * Value from ASIC for bs_init.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_INIT      9
#define BM_PCIE_PHY_BS_ASIC_IN_INIT      0x00000200

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field INVERT (RO)
 *
 * Value from ASIC for bs_invert.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_INVERT      10
#define BM_PCIE_PHY_BS_ASIC_IN_INVERT      0x00000400

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_LEVEL_ASIC_IN -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short LOS_LEVEL : 5; //!< Value from ASIC for los_level.
        unsigned short ACJT_LEVEL : 5; //!< Value from ASIC for acjt_level.
        unsigned short RESERVED0 : 6; //!< Reserved.
    } B;
} hw_pcie_phy_level_asic_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_LEVEL_ASIC_IN register
 */
#define HW_PCIE_PHY_LEVEL_ASIC_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x19)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_LEVEL_ASIC_IN           (*(volatile hw_pcie_phy_level_asic_in_t *) HW_PCIE_PHY_LEVEL_ASIC_IN_ADDR)
#define HW_PCIE_PHY_LEVEL_ASIC_IN_RD()      (HW_PCIE_PHY_LEVEL_ASIC_IN.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_LEVEL_ASIC_IN bitfields
 */

/* --- Register HW_PCIE_PHY_LEVEL_ASIC_IN, field LOS_LEVEL (RO)
 *
 * Value from ASIC for los_level.
 */

#define BP_PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL      0
#define BM_PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL      0x0000001f

/* --- Register HW_PCIE_PHY_LEVEL_ASIC_IN, field ACJT_LEVEL (RO)
 *
 * Value from ASIC for acjt_level.
 */

#define BP_PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL      5
#define BM_PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL      0x000003e0

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SSC_ASIC_IN -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short FSEL : 3; //!< Value from ASIC for fsel.
        unsigned short SSC_REF_CLK_SEL : 8; //!< Value from ASIC for ssc_ref_clk_sel
        unsigned short SSC_RANGE : 2; //!< Value from ASIC for ssc_range.
        unsigned short SS_EN : 1; //!< Value from ASIC for ssc_en.
        unsigned short RESERVED0 : 2; //!< Reserved.
    } B;
} hw_pcie_phy_ssc_asic_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SSC_ASIC_IN register
 */
#define HW_PCIE_PHY_SSC_ASIC_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x1a)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SSC_ASIC_IN           (*(volatile hw_pcie_phy_ssc_asic_in_t *) HW_PCIE_PHY_SSC_ASIC_IN_ADDR)
#define HW_PCIE_PHY_SSC_ASIC_IN_RD()      (HW_PCIE_PHY_SSC_ASIC_IN.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_SSC_ASIC_IN bitfields
 */

/* --- Register HW_PCIE_PHY_SSC_ASIC_IN, field FSEL (RO)
 *
 * Value from ASIC for fsel.
 */

#define BP_PCIE_PHY_SSC_ASIC_IN_FSEL      0
#define BM_PCIE_PHY_SSC_ASIC_IN_FSEL      0x00000007

/* --- Register HW_PCIE_PHY_SSC_ASIC_IN, field SSC_REF_CLK_SEL (RO)
 *
 * Value from ASIC for ssc_ref_clk_sel
 */

#define BP_PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL      3
#define BM_PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL      0x000007f8

/* --- Register HW_PCIE_PHY_SSC_ASIC_IN, field SSC_RANGE (RO)
 *
 * Value from ASIC for ssc_range.
 */

#define BP_PCIE_PHY_SSC_ASIC_IN_SSC_RANGE      11
#define BM_PCIE_PHY_SSC_ASIC_IN_SSC_RANGE      0x00001800

/* --- Register HW_PCIE_PHY_SSC_ASIC_IN, field SS_EN (RO)
 *
 * Value from ASIC for ssc_en.
 */

#define BP_PCIE_PHY_SSC_ASIC_IN_SS_EN      13
#define BM_PCIE_PHY_SSC_ASIC_IN_SS_EN      0x00002000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SUP_ASIC_OUT -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RES_ACK_OUT : 1; //!< Value from PHY for res_ack_out output.
        unsigned short RES_REQ_OUT : 1; //!< Value from PHY for res_req_out output.
        unsigned short RTUNE_ACK : 1; //!< Value from PHY for rtune_ack output.
        unsigned short BS_OUT : 1; //!< Value from PHY for bs_out output.
        unsigned short MPLL_STATE : 1; //!< Value from PHY for mpll_state output.
        unsigned short RESERVED0 : 11; //!< Reserved.
    } B;
} hw_pcie_phy_sup_asic_out_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SUP_ASIC_OUT register
 */
#define HW_PCIE_PHY_SUP_ASIC_OUT_ADDR      (REGS_PCIE_PHY_BASE + 0x1b)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SUP_ASIC_OUT           (*(volatile hw_pcie_phy_sup_asic_out_t *) HW_PCIE_PHY_SUP_ASIC_OUT_ADDR)
#define HW_PCIE_PHY_SUP_ASIC_OUT_RD()      (HW_PCIE_PHY_SUP_ASIC_OUT.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_SUP_ASIC_OUT bitfields
 */

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field RES_ACK_OUT (RO)
 *
 * Value from PHY for res_ack_out output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT      0
#define BM_PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT      0x00000001

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field RES_REQ_OUT (RO)
 *
 * Value from PHY for res_req_out output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT      1
#define BM_PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT      0x00000002

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field RTUNE_ACK (RO)
 *
 * Value from PHY for rtune_ack output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK      2
#define BM_PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK      0x00000004

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field BS_OUT (RO)
 *
 * Value from PHY for bs_out output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_BS_OUT      3
#define BM_PCIE_PHY_SUP_ASIC_OUT_BS_OUT      0x00000008

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field MPLL_STATE (RO)
 *
 * Value from PHY for mpll_state output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE      4
#define BM_PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE      0x00000010

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_ATEOVRD_STATUS -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short REF_USB2_EN_OUT : 1; //!< Value from ATEOVRD for ref_usb2_en.
        unsigned short REF_CLKDIV2_OUT : 1; //!< Value from ATEOVRD for ref_clkdiv2.
        unsigned short PHY_RESET_OUT : 1; //!< Value from ATEOVRD for phy_reset.
        unsigned short ATEOVRD_EN : 1; //!< When set, values from ATEOVRD register are sent to PHY.
        unsigned short REF_USB2_EN_IN : 1; //!< Value from ASIC for ref_usb2_en.
        unsigned short REF_CLKDIV2_IN : 1; //!< Value from ASIC for ref_clkdiv2.
        unsigned short PHY_RESET_IN : 1; //!< Value from ASIC for phy_reset
        unsigned short REF_USE_PAD : 1; //!< Value from ASIC for ref_use_pad
        unsigned short REF_SSP_EN : 1; //!< Value from ASIC for ref_ssp_en.
        unsigned short RESERVED0 : 7; //!< Reserved.
    } B;
} hw_pcie_phy_ateovrd_status_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_ATEOVRD_STATUS register
 */
#define HW_PCIE_PHY_ATEOVRD_STATUS_ADDR      (REGS_PCIE_PHY_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_ATEOVRD_STATUS           (*(volatile hw_pcie_phy_ateovrd_status_t *) HW_PCIE_PHY_ATEOVRD_STATUS_ADDR)
#define HW_PCIE_PHY_ATEOVRD_STATUS_RD()      (HW_PCIE_PHY_ATEOVRD_STATUS.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_ATEOVRD_STATUS bitfields
 */

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_USB2_EN_OUT (RO)
 *
 * Value from ATEOVRD for ref_usb2_en.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT      0
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT      0x00000001

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_CLKDIV2_OUT (RO)
 *
 * Value from ATEOVRD for ref_clkdiv2.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT      1
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT      0x00000002

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field PHY_RESET_OUT (RO)
 *
 * Value from ATEOVRD for phy_reset.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT      2
#define BM_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT      0x00000004

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field ATEOVRD_EN (RO)
 *
 * When set, values from ATEOVRD register are sent to PHY.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN      3
#define BM_PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN      0x00000008

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_USB2_EN_IN (RO)
 *
 * Value from ASIC for ref_usb2_en.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN      4
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN      0x00000010

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_CLKDIV2_IN (RO)
 *
 * Value from ASIC for ref_clkdiv2.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN      5
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN      0x00000020

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field PHY_RESET_IN (RO)
 *
 * Value from ASIC for phy_reset
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN      6
#define BM_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN      0x00000040

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_USE_PAD (RO)
 *
 * Value from ASIC for ref_use_pad
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD      7
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD      0x00000080

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_SSP_EN (RO)
 *
 * Value from ASIC for ref_ssp_en.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN      8
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN      0x00000100

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_ENABLES -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short XOR_EN : 1; //!< Uses scope_xor input for count values.
        unsigned short MASK_EN : 1; //!< Enables scope_mask input for tracking count values. Clears registers when deasserted.
        unsigned short MASK_SATURATION_MODE : 1; //!< Method of mask saturation.
        unsigned short RESERVED0 : 13; //!< Reserved.
    } B;
} hw_pcie_phy_scope_enables_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_ENABLES register
 */
#define HW_PCIE_PHY_SCOPE_ENABLES_ADDR      (REGS_PCIE_PHY_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_ENABLES           (*(volatile hw_pcie_phy_scope_enables_t *) HW_PCIE_PHY_SCOPE_ENABLES_ADDR)
#define HW_PCIE_PHY_SCOPE_ENABLES_RD()      (HW_PCIE_PHY_SCOPE_ENABLES.U)
#define HW_PCIE_PHY_SCOPE_ENABLES_WR(v)     (HW_PCIE_PHY_SCOPE_ENABLES.U = (v))
#define HW_PCIE_PHY_SCOPE_ENABLES_SET(v)    (HW_PCIE_PHY_SCOPE_ENABLES_WR(HW_PCIE_PHY_SCOPE_ENABLES_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_ENABLES_CLR(v)    (HW_PCIE_PHY_SCOPE_ENABLES_WR(HW_PCIE_PHY_SCOPE_ENABLES_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_ENABLES_TOG(v)    (HW_PCIE_PHY_SCOPE_ENABLES_WR(HW_PCIE_PHY_SCOPE_ENABLES_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_ENABLES bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_ENABLES, field XOR_EN (RW)
 *
 * Uses scope_xor input for count values.
 */

#define BP_PCIE_PHY_SCOPE_ENABLES_XOR_EN      0
#define BM_PCIE_PHY_SCOPE_ENABLES_XOR_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SCOPE_ENABLES_XOR_EN(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SCOPE_ENABLES_XOR_EN)
#else
#define BF_PCIE_PHY_SCOPE_ENABLES_XOR_EN(v)   (((v) << 0) & BM_PCIE_PHY_SCOPE_ENABLES_XOR_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the XOR_EN field to a new value.
#define BW_PCIE_PHY_SCOPE_ENABLES_XOR_EN(v)   BF_CS1(PCIE_PHY_SCOPE_ENABLES, XOR_EN, v)
#endif

/* --- Register HW_PCIE_PHY_SCOPE_ENABLES, field MASK_EN (RW)
 *
 * Enables scope_mask input for tracking count values. Clears registers when deasserted.
 */

#define BP_PCIE_PHY_SCOPE_ENABLES_MASK_EN      1
#define BM_PCIE_PHY_SCOPE_ENABLES_MASK_EN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SCOPE_ENABLES_MASK_EN(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_EN)
#else
#define BF_PCIE_PHY_SCOPE_ENABLES_MASK_EN(v)   (((v) << 1) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_EN field to a new value.
#define BW_PCIE_PHY_SCOPE_ENABLES_MASK_EN(v)   BF_CS1(PCIE_PHY_SCOPE_ENABLES, MASK_EN, v)
#endif

/* --- Register HW_PCIE_PHY_SCOPE_ENABLES, field MASK_SATURATION_MODE (RW)
 *
 * Method of mask saturation.
 *
 * Values:
 * 1 - Saturates when the first mask_counter reaches sample_limit.
 * 0 - Saturates when all mask_counters have reached sample_limit.
 */

#define BP_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE      2
#define BM_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE)
#else
#define BF_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE(v)   (((v) << 2) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_SATURATION_MODE field to a new value.
#define BW_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE(v)   BF_CS1(PCIE_PHY_SCOPE_ENABLES, MASK_SATURATION_MODE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_SAMPLES -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short SAMPLES : 16; //!< Number of samples to count.
    } B;
} hw_pcie_phy_scope_samples_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_SAMPLES register
 */
#define HW_PCIE_PHY_SCOPE_SAMPLES_ADDR      (REGS_PCIE_PHY_BASE + 0x21)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_SAMPLES           (*(volatile hw_pcie_phy_scope_samples_t *) HW_PCIE_PHY_SCOPE_SAMPLES_ADDR)
#define HW_PCIE_PHY_SCOPE_SAMPLES_RD()      (HW_PCIE_PHY_SCOPE_SAMPLES.U)
#define HW_PCIE_PHY_SCOPE_SAMPLES_WR(v)     (HW_PCIE_PHY_SCOPE_SAMPLES.U = (v))
#define HW_PCIE_PHY_SCOPE_SAMPLES_SET(v)    (HW_PCIE_PHY_SCOPE_SAMPLES_WR(HW_PCIE_PHY_SCOPE_SAMPLES_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_SAMPLES_CLR(v)    (HW_PCIE_PHY_SCOPE_SAMPLES_WR(HW_PCIE_PHY_SCOPE_SAMPLES_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_SAMPLES_TOG(v)    (HW_PCIE_PHY_SCOPE_SAMPLES_WR(HW_PCIE_PHY_SCOPE_SAMPLES_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_SAMPLES bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_SAMPLES, field SAMPLES (RW)
 *
 * Number of samples to count.
 */

#define BP_PCIE_PHY_SCOPE_SAMPLES_SAMPLES      0
#define BM_PCIE_PHY_SCOPE_SAMPLES_SAMPLES      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SCOPE_SAMPLES_SAMPLES(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SCOPE_SAMPLES_SAMPLES)
#else
#define BF_PCIE_PHY_SCOPE_SAMPLES_SAMPLES(v)   (((v) << 0) & BM_PCIE_PHY_SCOPE_SAMPLES_SAMPLES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SAMPLES field to a new value.
#define BW_PCIE_PHY_SCOPE_SAMPLES_SAMPLES(v)   BF_CS1(PCIE_PHY_SCOPE_SAMPLES, SAMPLES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_COUNT -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short COUNT : 16; //!< A write to this register starts the counting process. The value of FFFF indicates counting still in progress. If in MASK mode, asserting MASK_EN also starts the counting
    } B;
} hw_pcie_phy_scope_count_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_COUNT register
 */
#define HW_PCIE_PHY_SCOPE_COUNT_ADDR      (REGS_PCIE_PHY_BASE + 0x22)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_COUNT           (*(volatile hw_pcie_phy_scope_count_t *) HW_PCIE_PHY_SCOPE_COUNT_ADDR)
#define HW_PCIE_PHY_SCOPE_COUNT_RD()      (HW_PCIE_PHY_SCOPE_COUNT.U)
#define HW_PCIE_PHY_SCOPE_COUNT_WR(v)     (HW_PCIE_PHY_SCOPE_COUNT.U = (v))
#define HW_PCIE_PHY_SCOPE_COUNT_SET(v)    (HW_PCIE_PHY_SCOPE_COUNT_WR(HW_PCIE_PHY_SCOPE_COUNT_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_COUNT_CLR(v)    (HW_PCIE_PHY_SCOPE_COUNT_WR(HW_PCIE_PHY_SCOPE_COUNT_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_COUNT_TOG(v)    (HW_PCIE_PHY_SCOPE_COUNT_WR(HW_PCIE_PHY_SCOPE_COUNT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_COUNT bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_COUNT, field COUNT (RW)
 *
 * A write to this register starts the counting process. The value of FFFF indicates counting still
 * in progress. If in MASK mode, asserting MASK_EN also starts the counting
 */

#define BP_PCIE_PHY_SCOPE_COUNT_COUNT      0
#define BM_PCIE_PHY_SCOPE_COUNT_COUNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SCOPE_COUNT_COUNT(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SCOPE_COUNT_COUNT)
#else
#define BF_PCIE_PHY_SCOPE_COUNT_COUNT(v)   (((v) << 0) & BM_PCIE_PHY_SCOPE_COUNT_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_PCIE_PHY_SCOPE_COUNT_COUNT(v)   BF_CS1(PCIE_PHY_SCOPE_COUNT, COUNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_CTL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MASK_SATURATION : 1; //!< When asserted, mask registers have saturated.
        unsigned short COUNT : 1; //!< A write to this register starts the counting process. The value of FFFF indicates counting still in progress. If in MASK mode, asserting MASK_EN also starts the counting
        unsigned short RESERVED0 : 14; //!< Reserved.
    } B;
} hw_pcie_phy_scope_ctl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_CTL register
 */
#define HW_PCIE_PHY_SCOPE_CTL_ADDR      (REGS_PCIE_PHY_BASE + 0x23)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_CTL           (*(volatile hw_pcie_phy_scope_ctl_t *) HW_PCIE_PHY_SCOPE_CTL_ADDR)
#define HW_PCIE_PHY_SCOPE_CTL_RD()      (HW_PCIE_PHY_SCOPE_CTL.U)
#define HW_PCIE_PHY_SCOPE_CTL_WR(v)     (HW_PCIE_PHY_SCOPE_CTL.U = (v))
#define HW_PCIE_PHY_SCOPE_CTL_SET(v)    (HW_PCIE_PHY_SCOPE_CTL_WR(HW_PCIE_PHY_SCOPE_CTL_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_CTL_CLR(v)    (HW_PCIE_PHY_SCOPE_CTL_WR(HW_PCIE_PHY_SCOPE_CTL_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_CTL_TOG(v)    (HW_PCIE_PHY_SCOPE_CTL_WR(HW_PCIE_PHY_SCOPE_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_CTL bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_CTL, field MASK_SATURATION (RW)
 *
 * When asserted, mask registers have saturated.
 */

#define BP_PCIE_PHY_SCOPE_CTL_MASK_SATURATION      0
#define BM_PCIE_PHY_SCOPE_CTL_MASK_SATURATION      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SCOPE_CTL_MASK_SATURATION(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SCOPE_CTL_MASK_SATURATION)
#else
#define BF_PCIE_PHY_SCOPE_CTL_MASK_SATURATION(v)   (((v) << 0) & BM_PCIE_PHY_SCOPE_CTL_MASK_SATURATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_SATURATION field to a new value.
#define BW_PCIE_PHY_SCOPE_CTL_MASK_SATURATION(v)   BF_CS1(PCIE_PHY_SCOPE_CTL, MASK_SATURATION, v)
#endif

/* --- Register HW_PCIE_PHY_SCOPE_CTL, field COUNT (RW)
 *
 * A write to this register starts the counting process. The value of FFFF indicates counting still
 * in progress. If in MASK mode, asserting MASK_EN also starts the counting
 */

#define BP_PCIE_PHY_SCOPE_CTL_COUNT      1
#define BM_PCIE_PHY_SCOPE_CTL_COUNT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SCOPE_CTL_COUNT(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_SCOPE_CTL_COUNT)
#else
#define BF_PCIE_PHY_SCOPE_CTL_COUNT(v)   (((v) << 1) & BM_PCIE_PHY_SCOPE_CTL_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_PCIE_PHY_SCOPE_CTL_COUNT(v)   BF_CS1(PCIE_PHY_SCOPE_CTL, COUNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MASK_VAL_N : 16; //!< Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK register
 */
#define HW_PCIE_PHY_SCOPE_MASK_ADDR      (REGS_PCIE_PHY_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK           (*(volatile hw_pcie_phy_scope_mask_t *) HW_PCIE_PHY_SCOPE_MASK_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_RD()      (HW_PCIE_PHY_SCOPE_MASK.U)
#define HW_PCIE_PHY_SCOPE_MASK_WR(v)     (HW_PCIE_PHY_SCOPE_MASK.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_WR(HW_PCIE_PHY_SCOPE_MASK_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_WR(HW_PCIE_PHY_SCOPE_MASK_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_WR(HW_PCIE_PHY_SCOPE_MASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK, field MASK_VAL_N (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_MASK_VAL_N      0
#define BM_PCIE_PHY_SCOPE_MASK_MASK_VAL_N      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_SCOPE_MASK_MASK_VAL_N(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_SCOPE_MASK_MASK_VAL_N)
#else
#define BF_PCIE_PHY_SCOPE_MASK_MASK_VAL_N(v)   (((v) << 0) & BM_PCIE_PHY_SCOPE_MASK_MASK_VAL_N)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_MASK_VAL_N(v)   BF_CS1(PCIE_PHY_SCOPE_MASK, MASK_VAL_N, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_LOOP_CTL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short VMB : 1; //!< Measures MPLL master bias voltage.
        unsigned short VBF_SF : 1; //!< Measures MPLL VBF_SF (RC filtered gate voltage for VPSF source follower).
        unsigned short INT_CNTRL : 2; //!< Charge pump integrating current setting.
        unsigned short PROP_CNTRL : 4; //!< Charge pump proportional current setting.
        unsigned short RESERVED0 : 8; //!< Reserved.
    } B;
} hw_pcie_phy_mpll_loop_ctl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_MPLL_LOOP_CTL register
 */
#define HW_PCIE_PHY_MPLL_LOOP_CTL_ADDR      (REGS_PCIE_PHY_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_MPLL_LOOP_CTL           (*(volatile hw_pcie_phy_mpll_loop_ctl_t *) HW_PCIE_PHY_MPLL_LOOP_CTL_ADDR)
#define HW_PCIE_PHY_MPLL_LOOP_CTL_RD()      (HW_PCIE_PHY_MPLL_LOOP_CTL.U)
#define HW_PCIE_PHY_MPLL_LOOP_CTL_WR(v)     (HW_PCIE_PHY_MPLL_LOOP_CTL.U = (v))
#define HW_PCIE_PHY_MPLL_LOOP_CTL_SET(v)    (HW_PCIE_PHY_MPLL_LOOP_CTL_WR(HW_PCIE_PHY_MPLL_LOOP_CTL_RD() |  (v)))
#define HW_PCIE_PHY_MPLL_LOOP_CTL_CLR(v)    (HW_PCIE_PHY_MPLL_LOOP_CTL_WR(HW_PCIE_PHY_MPLL_LOOP_CTL_RD() & ~(v)))
#define HW_PCIE_PHY_MPLL_LOOP_CTL_TOG(v)    (HW_PCIE_PHY_MPLL_LOOP_CTL_WR(HW_PCIE_PHY_MPLL_LOOP_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_MPLL_LOOP_CTL bitfields
 */

/* --- Register HW_PCIE_PHY_MPLL_LOOP_CTL, field VMB (RW)
 *
 * Measures MPLL master bias voltage.
 */

#define BP_PCIE_PHY_MPLL_LOOP_CTL_VMB      0
#define BM_PCIE_PHY_MPLL_LOOP_CTL_VMB      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_LOOP_CTL_VMB(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_MPLL_LOOP_CTL_VMB)
#else
#define BF_PCIE_PHY_MPLL_LOOP_CTL_VMB(v)   (((v) << 0) & BM_PCIE_PHY_MPLL_LOOP_CTL_VMB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VMB field to a new value.
#define BW_PCIE_PHY_MPLL_LOOP_CTL_VMB(v)   BF_CS1(PCIE_PHY_MPLL_LOOP_CTL, VMB, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_LOOP_CTL, field VBF_SF (RW)
 *
 * Measures MPLL VBF_SF (RC filtered gate voltage for VPSF source follower).
 */

#define BP_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF      1
#define BM_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF)
#else
#define BF_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF(v)   (((v) << 1) & BM_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VBF_SF field to a new value.
#define BW_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF(v)   BF_CS1(PCIE_PHY_MPLL_LOOP_CTL, VBF_SF, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_LOOP_CTL, field INT_CNTRL (RW)
 *
 * Charge pump integrating current setting.
 */

#define BP_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL      2
#define BM_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL)
#else
#define BF_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL(v)   (((v) << 2) & BM_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_CNTRL field to a new value.
#define BW_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL(v)   BF_CS1(PCIE_PHY_MPLL_LOOP_CTL, INT_CNTRL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_LOOP_CTL, field PROP_CNTRL (RW)
 *
 * Charge pump proportional current setting.
 */

#define BP_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL      4
#define BM_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL)
#else
#define BF_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL(v)   (((v) << 4) & BM_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PROP_CNTRL field to a new value.
#define BW_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL(v)   BF_CS1(PCIE_PHY_MPLL_LOOP_CTL, PROP_CNTRL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_ATB_MEAS1 -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short VREG_MPLL : 1; //!< Puts vreg_mpll on atb_s_p.
        unsigned short VP_CP : 1; //!< Puts vp_cp on atb_s_p.
        unsigned short VPA : 1; //!< Puts vpa on atb_s_m.
        unsigned short IVCO : 1; //!< Puts VCO current / 93 on atb_f_m.
        unsigned short GD : 1; //!< Puts gd on atb_s_m.
        unsigned short VCNTRL : 1; //!< Puts vcntrl on atb_s_m.
        unsigned short VREF : 1; //!< Puts vref from charge pump on atb_s_p.
        unsigned short VPSF : 1; //!< Puts vpsf on atb_s_p.
        unsigned short RESERVED0 : 8; //!< Reserved.
    } B;
} hw_pcie_phy_mpll_atb_meas1_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_MPLL_ATB_MEAS1 register
 */
#define HW_PCIE_PHY_MPLL_ATB_MEAS1_ADDR      (REGS_PCIE_PHY_BASE + 0x31)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_MPLL_ATB_MEAS1           (*(volatile hw_pcie_phy_mpll_atb_meas1_t *) HW_PCIE_PHY_MPLL_ATB_MEAS1_ADDR)
#define HW_PCIE_PHY_MPLL_ATB_MEAS1_RD()      (HW_PCIE_PHY_MPLL_ATB_MEAS1.U)
#define HW_PCIE_PHY_MPLL_ATB_MEAS1_WR(v)     (HW_PCIE_PHY_MPLL_ATB_MEAS1.U = (v))
#define HW_PCIE_PHY_MPLL_ATB_MEAS1_SET(v)    (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR(HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() |  (v)))
#define HW_PCIE_PHY_MPLL_ATB_MEAS1_CLR(v)    (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR(HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~(v)))
#define HW_PCIE_PHY_MPLL_ATB_MEAS1_TOG(v)    (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR(HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_MPLL_ATB_MEAS1 bitfields
 */

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VREG_MPLL (RW)
 *
 * Puts vreg_mpll on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL      0
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL(v)   (((v) << 0) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VREG_MPLL field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS1, VREG_MPLL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VP_CP (RW)
 *
 * Puts vp_cp on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP      1
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP(v)   (((v) << 1) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VP_CP field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS1, VP_CP, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VPA (RW)
 *
 * Puts vpa on atb_s_m.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VPA      2
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VPA      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VPA(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPA)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VPA(v)   (((v) << 2) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPA field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VPA(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS1, VPA, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field IVCO (RW)
 *
 * Puts VCO current / 93 on atb_f_m.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_IVCO      3
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_IVCO      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_IVCO(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_MPLL_ATB_MEAS1_IVCO)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_IVCO(v)   (((v) << 3) & BM_PCIE_PHY_MPLL_ATB_MEAS1_IVCO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IVCO field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_IVCO(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS1, IVCO, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field GD (RW)
 *
 * Puts gd on atb_s_m.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_GD      4
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_GD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_GD(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_MPLL_ATB_MEAS1_GD)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_GD(v)   (((v) << 4) & BM_PCIE_PHY_MPLL_ATB_MEAS1_GD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GD field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_GD(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS1, GD, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VCNTRL (RW)
 *
 * Puts vcntrl on atb_s_m.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL      5
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL(v)   (((v) << 5) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VCNTRL field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS1, VCNTRL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VREF (RW)
 *
 * Puts vref from charge pump on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VREF      6
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VREF      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VREF(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREF)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VREF(v)   (((v) << 6) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VREF field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VREF(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS1, VREF, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VPSF (RW)
 *
 * Puts vpsf on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VPSF      7
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VPSF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VPSF(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPSF)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VPSF(v)   (((v) << 7) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPSF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPSF field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VPSF(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS1, VPSF, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_ATB_MEAS2 -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short EN_MPMIX_TST : 1; //!< Enables XOR gate to test linearity of MPLL phase mixer.
        unsigned short EN_MPMIX_VPMIX : 1; //!< Puts vreg_pmix on atb_s_p.
        unsigned short FRC_PMIX_VPMIX : 1; //!< Forces mpll_pmix_vreg to use atb_s_m as its input instead of vbg.
        unsigned short MEAS_TEMP : 1; //!< Instructs POR block to measure the temperature.
        unsigned short ATB_SENSE_SEL : 1; //!< connects internal atb sense bus to external bus
        unsigned short VCNTRL_P : 1; //!< Puts dcc output vcntrl_m on atb_s_p
        unsigned short VCNTRL_M : 1; //!< Puts dcc output vcntrl_p on atb_s_m
        unsigned short IVCO_FILT : 1; //!< Puts filtered version of ivco on atb_s_p
        unsigned short RESERVED0 : 8; //!< Reserved.
    } B;
} hw_pcie_phy_mpll_atb_meas2_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_MPLL_ATB_MEAS2 register
 */
#define HW_PCIE_PHY_MPLL_ATB_MEAS2_ADDR      (REGS_PCIE_PHY_BASE + 0x32)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_MPLL_ATB_MEAS2           (*(volatile hw_pcie_phy_mpll_atb_meas2_t *) HW_PCIE_PHY_MPLL_ATB_MEAS2_ADDR)
#define HW_PCIE_PHY_MPLL_ATB_MEAS2_RD()      (HW_PCIE_PHY_MPLL_ATB_MEAS2.U)
#define HW_PCIE_PHY_MPLL_ATB_MEAS2_WR(v)     (HW_PCIE_PHY_MPLL_ATB_MEAS2.U = (v))
#define HW_PCIE_PHY_MPLL_ATB_MEAS2_SET(v)    (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR(HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() |  (v)))
#define HW_PCIE_PHY_MPLL_ATB_MEAS2_CLR(v)    (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR(HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~(v)))
#define HW_PCIE_PHY_MPLL_ATB_MEAS2_TOG(v)    (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR(HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_MPLL_ATB_MEAS2 bitfields
 */

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field EN_MPMIX_TST (RW)
 *
 * Enables XOR gate to test linearity of MPLL phase mixer.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST      0
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST(v)   (((v) << 0) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_MPMIX_TST field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS2, EN_MPMIX_TST, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field EN_MPMIX_VPMIX (RW)
 *
 * Puts vreg_pmix on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX      1
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX(v)   (((v) << 1) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_MPMIX_VPMIX field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS2, EN_MPMIX_VPMIX, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field FRC_PMIX_VPMIX (RW)
 *
 * Forces mpll_pmix_vreg to use atb_s_m as its input instead of vbg.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX      2
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX(v)   (((v) << 2) & BM_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_PMIX_VPMIX field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS2, FRC_PMIX_VPMIX, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field MEAS_TEMP (RW)
 *
 * Instructs POR block to measure the temperature.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP      3
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP(v)   (((v) << 3) & BM_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_TEMP field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS2, MEAS_TEMP, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field ATB_SENSE_SEL (RW)
 *
 * connects internal atb sense bus to external bus
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL      4
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL(v)   (((v) << 4) & BM_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_SENSE_SEL field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS2, ATB_SENSE_SEL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field VCNTRL_P (RW)
 *
 * Puts dcc output vcntrl_m on atb_s_p
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P      5
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P(v)   (((v) << 5) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VCNTRL_P field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS2, VCNTRL_P, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field VCNTRL_M (RW)
 *
 * Puts dcc output vcntrl_p on atb_s_m
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M      6
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M(v)   (((v) << 6) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VCNTRL_M field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS2, VCNTRL_M, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field IVCO_FILT (RW)
 *
 * Puts filtered version of ivco on atb_s_p
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT      7
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT)
#else
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT(v)   (((v) << 7) & BM_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IVCO_FILT field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT(v)   BF_CS1(PCIE_PHY_MPLL_ATB_MEAS2, IVCO_FILT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_OVR -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short EN_PMIX_CLK_SEL_LCL : 1; //!< enable local control of pmix_clk_sel
        unsigned short PMIX_CLK_SEL_LCL : 1; //!< local pmix_clk_sel value
        unsigned short EN_RST_LCL : 1; //!< enable local control of reset
        unsigned short RST_LCL : 1; //!< local Reset value
        unsigned short EN_GS_LCL : 1; //!< Enables local control of gear_shift
        unsigned short GS_LCL : 1; //!< local gear_shift value
        unsigned short EN_PWRON_LCL : 1; //!< Enables local control of power_on
        unsigned short PWRON_LCL : 1; //!< local power_on value
        unsigned short RESERVED0 : 8; //!< Reserved.
    } B;
} hw_pcie_phy_mpll_ovr_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_MPLL_OVR register
 */
#define HW_PCIE_PHY_MPLL_OVR_ADDR      (REGS_PCIE_PHY_BASE + 0x33)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_MPLL_OVR           (*(volatile hw_pcie_phy_mpll_ovr_t *) HW_PCIE_PHY_MPLL_OVR_ADDR)
#define HW_PCIE_PHY_MPLL_OVR_RD()      (HW_PCIE_PHY_MPLL_OVR.U)
#define HW_PCIE_PHY_MPLL_OVR_WR(v)     (HW_PCIE_PHY_MPLL_OVR.U = (v))
#define HW_PCIE_PHY_MPLL_OVR_SET(v)    (HW_PCIE_PHY_MPLL_OVR_WR(HW_PCIE_PHY_MPLL_OVR_RD() |  (v)))
#define HW_PCIE_PHY_MPLL_OVR_CLR(v)    (HW_PCIE_PHY_MPLL_OVR_WR(HW_PCIE_PHY_MPLL_OVR_RD() & ~(v)))
#define HW_PCIE_PHY_MPLL_OVR_TOG(v)    (HW_PCIE_PHY_MPLL_OVR_WR(HW_PCIE_PHY_MPLL_OVR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_MPLL_OVR bitfields
 */

/* --- Register HW_PCIE_PHY_MPLL_OVR, field EN_PMIX_CLK_SEL_LCL (RW)
 *
 * enable local control of pmix_clk_sel
 */

#define BP_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL      0
#define BM_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL)
#else
#define BF_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL(v)   (((v) << 0) & BM_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_PMIX_CLK_SEL_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL(v)   BF_CS1(PCIE_PHY_MPLL_OVR, EN_PMIX_CLK_SEL_LCL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field PMIX_CLK_SEL_LCL (RW)
 *
 * local pmix_clk_sel value
 */

#define BP_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL      1
#define BM_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL)
#else
#define BF_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL(v)   (((v) << 1) & BM_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PMIX_CLK_SEL_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL(v)   BF_CS1(PCIE_PHY_MPLL_OVR, PMIX_CLK_SEL_LCL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field EN_RST_LCL (RW)
 *
 * enable local control of reset
 */

#define BP_PCIE_PHY_MPLL_OVR_EN_RST_LCL      2
#define BM_PCIE_PHY_MPLL_OVR_EN_RST_LCL      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVR_EN_RST_LCL(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_MPLL_OVR_EN_RST_LCL)
#else
#define BF_PCIE_PHY_MPLL_OVR_EN_RST_LCL(v)   (((v) << 2) & BM_PCIE_PHY_MPLL_OVR_EN_RST_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RST_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_EN_RST_LCL(v)   BF_CS1(PCIE_PHY_MPLL_OVR, EN_RST_LCL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field RST_LCL (RW)
 *
 * local Reset value
 */

#define BP_PCIE_PHY_MPLL_OVR_RST_LCL      3
#define BM_PCIE_PHY_MPLL_OVR_RST_LCL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVR_RST_LCL(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_MPLL_OVR_RST_LCL)
#else
#define BF_PCIE_PHY_MPLL_OVR_RST_LCL(v)   (((v) << 3) & BM_PCIE_PHY_MPLL_OVR_RST_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RST_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_RST_LCL(v)   BF_CS1(PCIE_PHY_MPLL_OVR, RST_LCL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field EN_GS_LCL (RW)
 *
 * Enables local control of gear_shift
 */

#define BP_PCIE_PHY_MPLL_OVR_EN_GS_LCL      4
#define BM_PCIE_PHY_MPLL_OVR_EN_GS_LCL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVR_EN_GS_LCL(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_MPLL_OVR_EN_GS_LCL)
#else
#define BF_PCIE_PHY_MPLL_OVR_EN_GS_LCL(v)   (((v) << 4) & BM_PCIE_PHY_MPLL_OVR_EN_GS_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_GS_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_EN_GS_LCL(v)   BF_CS1(PCIE_PHY_MPLL_OVR, EN_GS_LCL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field GS_LCL (RW)
 *
 * local gear_shift value
 */

#define BP_PCIE_PHY_MPLL_OVR_GS_LCL      5
#define BM_PCIE_PHY_MPLL_OVR_GS_LCL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVR_GS_LCL(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_MPLL_OVR_GS_LCL)
#else
#define BF_PCIE_PHY_MPLL_OVR_GS_LCL(v)   (((v) << 5) & BM_PCIE_PHY_MPLL_OVR_GS_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GS_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_GS_LCL(v)   BF_CS1(PCIE_PHY_MPLL_OVR, GS_LCL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field EN_PWRON_LCL (RW)
 *
 * Enables local control of power_on
 */

#define BP_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL      6
#define BM_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL)
#else
#define BF_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL(v)   (((v) << 6) & BM_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_PWRON_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL(v)   BF_CS1(PCIE_PHY_MPLL_OVR, EN_PWRON_LCL, v)
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field PWRON_LCL (RW)
 *
 * local power_on value
 */

#define BP_PCIE_PHY_MPLL_OVR_PWRON_LCL      7
#define BM_PCIE_PHY_MPLL_OVR_PWRON_LCL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_MPLL_OVR_PWRON_LCL(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_MPLL_OVR_PWRON_LCL)
#else
#define BF_PCIE_PHY_MPLL_OVR_PWRON_LCL(v)   (((v) << 7) & BM_PCIE_PHY_MPLL_OVR_PWRON_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PWRON_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_PWRON_LCL(v)   BF_CS1(PCIE_PHY_MPLL_OVR, PWRON_LCL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RTUNE_RTUNE_CTRL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RT_SEL_ATBF : 1; //!< RTUNE ATB input slect bit
        unsigned short RT_SEL_ATBP : 1; //!< RTUNE ATB sense input select bit
        unsigned short RT_ATB : 1; //!< RTUNE ATB mode control bit
        unsigned short RT_DAC_CHOP : 1; //!< Margin DAC chop control bit
        unsigned short RT_DAC_MODE : 2; //!< Margin DAC mode control bits
        unsigned short X4_FRC_OFF : 1; //!< When set, do not multiply test current by 4
        unsigned short RT_PWRON_FRC_ON : 1; //!< When set, forces RTUNE block to be on
        unsigned short RESERVED0 : 8; //!< Reserved.
    } B;
} hw_pcie_phy_rtune_rtune_ctrl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RTUNE_RTUNE_CTRL register
 */
#define HW_PCIE_PHY_RTUNE_RTUNE_CTRL_ADDR      (REGS_PCIE_PHY_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RTUNE_RTUNE_CTRL           (*(volatile hw_pcie_phy_rtune_rtune_ctrl_t *) HW_PCIE_PHY_RTUNE_RTUNE_CTRL_ADDR)
#define HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD()      (HW_PCIE_PHY_RTUNE_RTUNE_CTRL.U)
#define HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR(v)     (HW_PCIE_PHY_RTUNE_RTUNE_CTRL.U = (v))
#define HW_PCIE_PHY_RTUNE_RTUNE_CTRL_SET(v)    (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR(HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() |  (v)))
#define HW_PCIE_PHY_RTUNE_RTUNE_CTRL_CLR(v)    (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR(HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() & ~(v)))
#define HW_PCIE_PHY_RTUNE_RTUNE_CTRL_TOG(v)    (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR(HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RTUNE_RTUNE_CTRL bitfields
 */

/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_SEL_ATBF (RW)
 *
 * RTUNE ATB input slect bit
 *
 * Values:
 * 1 - atb_fm
 * 0 - atb_s_p/m
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF      0
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF)
#else
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF(v)   (((v) << 0) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_SEL_ATBF field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF(v)   BF_CS1(PCIE_PHY_RTUNE_RTUNE_CTRL, RT_SEL_ATBF, v)
#endif


/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_SEL_ATBP (RW)
 *
 * RTUNE ATB sense input select bit
 *
 * Values:
 * 1 - atb_s_p
 * 0 - atb_s_m
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP      1
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP)
#else
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP(v)   (((v) << 1) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_SEL_ATBP field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP(v)   BF_CS1(PCIE_PHY_RTUNE_RTUNE_CTRL, RT_SEL_ATBP, v)
#endif


/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_ATB (RW)
 *
 * RTUNE ATB mode control bit
 *
 * Values:
 * 1 - RTUNE performs ADC on ATB input
 * 0 - not accessing ATB
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB      2
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB)
#else
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB(v)   (((v) << 2) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_ATB field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB(v)   BF_CS1(PCIE_PHY_RTUNE_RTUNE_CTRL, RT_ATB, v)
#endif


/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_DAC_CHOP (RW)
 *
 * Margin DAC chop control bit
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP      3
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP)
#else
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP(v)   (((v) << 3) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_DAC_CHOP field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP(v)   BF_CS1(PCIE_PHY_RTUNE_RTUNE_CTRL, RT_DAC_CHOP, v)
#endif

/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_DAC_MODE (RW)
 *
 * Margin DAC mode control bits
 *
 * Values:
 * 00 - powerdown
 * 01 - DAC drives atb_s_p/m directly
 * 10 - DAC drives atb_s_p/m to the RX in margining mode
 * 11 - illegal state
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE      4
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE)
#else
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE(v)   (((v) << 4) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_DAC_MODE field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE(v)   BF_CS1(PCIE_PHY_RTUNE_RTUNE_CTRL, RT_DAC_MODE, v)
#endif


/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field X4_FRC_OFF (RW)
 *
 * When set, do not multiply test current by 4
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF      6
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF)
#else
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF(v)   (((v) << 6) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X4_FRC_OFF field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF(v)   BF_CS1(PCIE_PHY_RTUNE_RTUNE_CTRL, X4_FRC_OFF, v)
#endif

/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_PWRON_FRC_ON (RW)
 *
 * When set, forces RTUNE block to be on
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON      7
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON)
#else
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON(v)   (((v) << 7) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_PWRON_FRC_ON field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON(v)   BF_CS1(PCIE_PHY_RTUNE_RTUNE_CTRL, RT_PWRON_FRC_ON, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_ATB_SWITCHYARD_CTRL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ASM_GD : 1; //!< Connect atb_s_m to gd
        unsigned short ASP_VP : 1; //!< Connect atb_s_p to vp
        unsigned short ASP_VPHREG : 1; //!< Connect atb_s_p vphreg
        unsigned short ASP_VPH : 1; //!< Connect atb_s_p to vph
        unsigned short ATEST_AFM : 1; //!< Connect atest to atb_f_m
        unsigned short ATEST_AFP : 1; //!< Connect atest to atb_f_p
        unsigned short ATEST_ASM : 1; //!< Connect atest to atb_s_m
        unsigned short ATEST_ASP : 1; //!< Connect atest to atb_s_p
        unsigned short RESERVED0 : 8; //!< Reserved.
    } B;
} hw_pcie_phy_atb_switchyard_ctrl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_ATB_SWITCHYARD_CTRL register
 */
#define HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ADDR      (REGS_PCIE_PHY_BASE + 0x35)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_ATB_SWITCHYARD_CTRL           (*(volatile hw_pcie_phy_atb_switchyard_ctrl_t *) HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ADDR)
#define HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD()      (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL.U)
#define HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR(v)     (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL.U = (v))
#define HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_SET(v)    (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR(HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() |  (v)))
#define HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_CLR(v)    (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR(HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~(v)))
#define HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_TOG(v)    (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR(HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_ATB_SWITCHYARD_CTRL bitfields
 */

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ASM_GD (RW)
 *
 * Connect atb_s_m to gd
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD      0
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD)
#else
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD(v)   (((v) << 0) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASM_GD field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD(v)   BF_CS1(PCIE_PHY_ATB_SWITCHYARD_CTRL, ASM_GD, v)
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ASP_VP (RW)
 *
 * Connect atb_s_p to vp
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP      1
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP)
#else
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP(v)   (((v) << 1) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP_VP field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP(v)   BF_CS1(PCIE_PHY_ATB_SWITCHYARD_CTRL, ASP_VP, v)
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ASP_VPHREG (RW)
 *
 * Connect atb_s_p vphreg
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG      2
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG)
#else
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG(v)   (((v) << 2) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP_VPHREG field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG(v)   BF_CS1(PCIE_PHY_ATB_SWITCHYARD_CTRL, ASP_VPHREG, v)
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ASP_VPH (RW)
 *
 * Connect atb_s_p to vph
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH      3
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH)
#else
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH(v)   (((v) << 3) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP_VPH field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH(v)   BF_CS1(PCIE_PHY_ATB_SWITCHYARD_CTRL, ASP_VPH, v)
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ATEST_AFM (RW)
 *
 * Connect atest to atb_f_m
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM      4
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM)
#else
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM(v)   (((v) << 4) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEST_AFM field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM(v)   BF_CS1(PCIE_PHY_ATB_SWITCHYARD_CTRL, ATEST_AFM, v)
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ATEST_AFP (RW)
 *
 * Connect atest to atb_f_p
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP      5
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP)
#else
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP(v)   (((v) << 5) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEST_AFP field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP(v)   BF_CS1(PCIE_PHY_ATB_SWITCHYARD_CTRL, ATEST_AFP, v)
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ATEST_ASM (RW)
 *
 * Connect atest to atb_s_m
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM      6
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM)
#else
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM(v)   (((v) << 6) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEST_ASM field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM(v)   BF_CS1(PCIE_PHY_ATB_SWITCHYARD_CTRL, ATEST_ASM, v)
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ATEST_ASP (RW)
 *
 * Connect atest to atb_s_p
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP      7
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP)
#else
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP(v)   (((v) << 7) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEST_ASP field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP(v)   BF_CS1(PCIE_PHY_ATB_SWITCHYARD_CTRL, ATEST_ASP, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_OVRD_IN_LO -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short LOOPBK_EN : 1; //!< Override value for loopbk_en
        unsigned short TX_LOOPBK_EN_OVRD : 1; //!< Override enable for loopbk_en
        unsigned short TX_INVERT : 1; //!< Override value for tx_invert
        unsigned short TX_INVERT_OVRD : 1; //!< Override enable for tx_invert
        unsigned short TX_DATA_EN : 1; //!< Override value for tx_data_en
        unsigned short TX_DATA_EN_OVRD : 1; //!< Override enable for tx_data_en
        unsigned short TX_EN : 1; //!< Override value for tx_en
        unsigned short TX_EN_OVRD : 1; //!< Override enable for tx_en
        unsigned short TX_CM_EN : 1; //!< Override value for tx_cm_en
        unsigned short TX_CM_EN_OVRD : 1; //!< Override enable for tx_cm_en
        unsigned short TX_BEACON_EN : 1; //!< Override value for tx_beacon_en
        unsigned short TX_BEACON_EN_OVRD : 1; //!< Override enable for tx_beacon_en
        unsigned short TX_DETECT_RX_REQ : 1; //!< Override value for tx_detect_rx_req
        unsigned short TX_DETECT_RX_REQ_OVRD : 1; //!< Override enable for tx_detect_rx_req
        unsigned short RESERVED0 : 2; //!< Reserved.
    } B;
} hw_pcie_phy_tx_ovrd_in_lo_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_OVRD_IN_LO register
 */
#define HW_PCIE_PHY_TX_OVRD_IN_LO_ADDR      (REGS_PCIE_PHY_BASE + 0x1000)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_OVRD_IN_LO           (*(volatile hw_pcie_phy_tx_ovrd_in_lo_t *) HW_PCIE_PHY_TX_OVRD_IN_LO_ADDR)
#define HW_PCIE_PHY_TX_OVRD_IN_LO_RD()      (HW_PCIE_PHY_TX_OVRD_IN_LO.U)
#define HW_PCIE_PHY_TX_OVRD_IN_LO_WR(v)     (HW_PCIE_PHY_TX_OVRD_IN_LO.U = (v))
#define HW_PCIE_PHY_TX_OVRD_IN_LO_SET(v)    (HW_PCIE_PHY_TX_OVRD_IN_LO_WR(HW_PCIE_PHY_TX_OVRD_IN_LO_RD() |  (v)))
#define HW_PCIE_PHY_TX_OVRD_IN_LO_CLR(v)    (HW_PCIE_PHY_TX_OVRD_IN_LO_WR(HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~(v)))
#define HW_PCIE_PHY_TX_OVRD_IN_LO_TOG(v)    (HW_PCIE_PHY_TX_OVRD_IN_LO_WR(HW_PCIE_PHY_TX_OVRD_IN_LO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_OVRD_IN_LO bitfields
 */

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field LOOPBK_EN (RW)
 *
 * Override value for loopbk_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN      0
#define BM_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN(v)   (((v) << 0) & BM_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOPBK_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, LOOPBK_EN, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_LOOPBK_EN_OVRD (RW)
 *
 * Override enable for loopbk_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD      1
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD(v)   (((v) << 1) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_LOOPBK_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_LOOPBK_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_INVERT (RW)
 *
 * Override value for tx_invert
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT      2
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT(v)   (((v) << 2) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_INVERT field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_INVERT, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_INVERT_OVRD (RW)
 *
 * Override enable for tx_invert
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD      3
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD(v)   (((v) << 3) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_INVERT_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_INVERT_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_DATA_EN (RW)
 *
 * Override value for tx_data_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN      4
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN(v)   (((v) << 4) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DATA_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_DATA_EN, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_DATA_EN_OVRD (RW)
 *
 * Override enable for tx_data_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD      5
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD(v)   (((v) << 5) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DATA_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_DATA_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_EN (RW)
 *
 * Override value for tx_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN      6
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN(v)   (((v) << 6) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_EN(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_EN, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_EN_OVRD (RW)
 *
 * Override enable for tx_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD      7
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD(v)   (((v) << 7) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_CM_EN (RW)
 *
 * Override value for tx_cm_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN      8
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN(v)   (((v) << 8) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CM_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_CM_EN, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_CM_EN_OVRD (RW)
 *
 * Override enable for tx_cm_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD      9
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD(v)   ((((reg32_t) v) << 9) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD(v)   (((v) << 9) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CM_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_CM_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_BEACON_EN (RW)
 *
 * Override value for tx_beacon_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN      10
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN(v)   (((v) << 10) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_BEACON_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_BEACON_EN, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_BEACON_EN_OVRD (RW)
 *
 * Override enable for tx_beacon_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD      11
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD(v)   ((((reg32_t) v) << 11) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD(v)   (((v) << 11) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_BEACON_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_BEACON_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_DETECT_RX_REQ (RW)
 *
 * Override value for tx_detect_rx_req
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ      12
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ(v)   ((((reg32_t) v) << 12) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ(v)   (((v) << 12) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DETECT_RX_REQ field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_DETECT_RX_REQ, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_DETECT_RX_REQ_OVRD (RW)
 *
 * Override enable for tx_detect_rx_req
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD      13
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD(v)   ((((reg32_t) v) << 13) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD(v)   (((v) << 13) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DETECT_RX_REQ_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_LO, TX_DETECT_RX_REQ_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_OVRD_IN_HI -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short TX_RATE : 2; //!< Override incomming tx lane rate.
        unsigned short TX_RATE_OVRD : 1; //!< Override enable for tx_rate.
        unsigned short TX_CLK_OUT_EN : 1; //!< Override incomming tx_clk_out_en.
        unsigned short TX_CLK_OUT_EN_OVRD : 1; //!< Override enable for tx_clk_out_en.
        unsigned short TX_NYQUIST_DATA : 1; //!< Override incoming data to nyquist
        unsigned short TX_RESET : 1; //!< Override value for tx_reset
        unsigned short TX_RESET_OVRD : 1; //!< Override enable for tx_reset
        unsigned short RESERVED0 : 8; //!< Reserved.
    } B;
} hw_pcie_phy_tx_ovrd_in_hi_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_OVRD_IN_HI register
 */
#define HW_PCIE_PHY_TX_OVRD_IN_HI_ADDR      (REGS_PCIE_PHY_BASE + 0x1001)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_OVRD_IN_HI           (*(volatile hw_pcie_phy_tx_ovrd_in_hi_t *) HW_PCIE_PHY_TX_OVRD_IN_HI_ADDR)
#define HW_PCIE_PHY_TX_OVRD_IN_HI_RD()      (HW_PCIE_PHY_TX_OVRD_IN_HI.U)
#define HW_PCIE_PHY_TX_OVRD_IN_HI_WR(v)     (HW_PCIE_PHY_TX_OVRD_IN_HI.U = (v))
#define HW_PCIE_PHY_TX_OVRD_IN_HI_SET(v)    (HW_PCIE_PHY_TX_OVRD_IN_HI_WR(HW_PCIE_PHY_TX_OVRD_IN_HI_RD() |  (v)))
#define HW_PCIE_PHY_TX_OVRD_IN_HI_CLR(v)    (HW_PCIE_PHY_TX_OVRD_IN_HI_WR(HW_PCIE_PHY_TX_OVRD_IN_HI_RD() & ~(v)))
#define HW_PCIE_PHY_TX_OVRD_IN_HI_TOG(v)    (HW_PCIE_PHY_TX_OVRD_IN_HI_WR(HW_PCIE_PHY_TX_OVRD_IN_HI_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_OVRD_IN_HI bitfields
 */

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_RATE (RW)
 *
 * Override incomming tx lane rate.
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE      0
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE(v)   (((v) << 0) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RATE field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_HI, TX_RATE, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_RATE_OVRD (RW)
 *
 * Override enable for tx_rate.
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD      2
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD(v)   (((v) << 2) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RATE_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_HI, TX_RATE_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_CLK_OUT_EN (RW)
 *
 * Override incomming tx_clk_out_en.
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN      3
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN(v)   (((v) << 3) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CLK_OUT_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_HI, TX_CLK_OUT_EN, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_CLK_OUT_EN_OVRD (RW)
 *
 * Override enable for tx_clk_out_en.
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD      4
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD(v)   (((v) << 4) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CLK_OUT_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_HI, TX_CLK_OUT_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_NYQUIST_DATA (RW)
 *
 * Override incoming data to nyquist
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA      5
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA(v)   (((v) << 5) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_NYQUIST_DATA field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_HI, TX_NYQUIST_DATA, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_RESET (RW)
 *
 * Override value for tx_reset
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET      6
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET(v)   (((v) << 6) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RESET field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_HI, TX_RESET, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_RESET_OVRD (RW)
 *
 * Override enable for tx_reset
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD      7
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD(v)   (((v) << 7) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RESET_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_IN_HI, TX_RESET_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_OVRD_DRV_LO -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short AMPLITUDE : 7; //!< Override value for transmit amplitude.
        unsigned short PREEMPH : 7; //!< Override value for transmit preemphasis
        unsigned short EN : 1; //!< Enables override values for all inputs controlled by this register
        unsigned short RESERVED0 : 1; //!< Reserved.
    } B;
} hw_pcie_phy_tx_ovrd_drv_lo_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_OVRD_DRV_LO register
 */
#define HW_PCIE_PHY_TX_OVRD_DRV_LO_ADDR      (REGS_PCIE_PHY_BASE + 0x1003)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_OVRD_DRV_LO           (*(volatile hw_pcie_phy_tx_ovrd_drv_lo_t *) HW_PCIE_PHY_TX_OVRD_DRV_LO_ADDR)
#define HW_PCIE_PHY_TX_OVRD_DRV_LO_RD()      (HW_PCIE_PHY_TX_OVRD_DRV_LO.U)
#define HW_PCIE_PHY_TX_OVRD_DRV_LO_WR(v)     (HW_PCIE_PHY_TX_OVRD_DRV_LO.U = (v))
#define HW_PCIE_PHY_TX_OVRD_DRV_LO_SET(v)    (HW_PCIE_PHY_TX_OVRD_DRV_LO_WR(HW_PCIE_PHY_TX_OVRD_DRV_LO_RD() |  (v)))
#define HW_PCIE_PHY_TX_OVRD_DRV_LO_CLR(v)    (HW_PCIE_PHY_TX_OVRD_DRV_LO_WR(HW_PCIE_PHY_TX_OVRD_DRV_LO_RD() & ~(v)))
#define HW_PCIE_PHY_TX_OVRD_DRV_LO_TOG(v)    (HW_PCIE_PHY_TX_OVRD_DRV_LO_WR(HW_PCIE_PHY_TX_OVRD_DRV_LO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_OVRD_DRV_LO bitfields
 */

/* --- Register HW_PCIE_PHY_TX_OVRD_DRV_LO, field AMPLITUDE (RW)
 *
 * Override value for transmit amplitude.
 */

#define BP_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE      0
#define BM_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE)
#else
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE(v)   (((v) << 0) & BM_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AMPLITUDE field to a new value.
#define BW_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE(v)   BF_CS1(PCIE_PHY_TX_OVRD_DRV_LO, AMPLITUDE, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_DRV_LO, field PREEMPH (RW)
 *
 * Override value for transmit preemphasis
 */

#define BP_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH      7
#define BM_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH      0x00003f80

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH)
#else
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH(v)   (((v) << 7) & BM_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PREEMPH field to a new value.
#define BW_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH(v)   BF_CS1(PCIE_PHY_TX_OVRD_DRV_LO, PREEMPH, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_DRV_LO, field EN (RW)
 *
 * Enables override values for all inputs controlled by this register
 */

#define BP_PCIE_PHY_TX_OVRD_DRV_LO_EN      14
#define BM_PCIE_PHY_TX_OVRD_DRV_LO_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_EN(v)   ((((reg32_t) v) << 14) & BM_PCIE_PHY_TX_OVRD_DRV_LO_EN)
#else
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_EN(v)   (((v) << 14) & BM_PCIE_PHY_TX_OVRD_DRV_LO_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_DRV_LO_EN(v)   BF_CS1(PCIE_PHY_TX_OVRD_DRV_LO, EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_OVRD_OUT -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DETECT_RX_RES : 1; //!< Override value for tx_detect_rx_res
        unsigned short DETECT_RX_RES_OVRD : 1; //!< Override enable for tx_detect_rx_res
        unsigned short TX_DETECT_RX_ACK : 1; //!< Override value for tx_detect_rx_ack
        unsigned short TX_DETECT_RX_ACK_OVRD : 1; //!< Override enable for tx_detect_rx_ack
        unsigned short TX_CM_STATE : 1; //!< Override value for tx_cm_state
        unsigned short TX_CM_STATE_OVRD : 1; //!< Override enable for tx_cm_state
        unsigned short TX_STATE : 1; //!< Override value for tx_state
        unsigned short TX_STATE_OVRD : 1; //!< Override enable for tx_state
        unsigned short RESERVED0 : 8; //!< Reserved.
    } B;
} hw_pcie_phy_tx_ovrd_out_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_OVRD_OUT register
 */
#define HW_PCIE_PHY_TX_OVRD_OUT_ADDR      (REGS_PCIE_PHY_BASE + 0x1004)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_OVRD_OUT           (*(volatile hw_pcie_phy_tx_ovrd_out_t *) HW_PCIE_PHY_TX_OVRD_OUT_ADDR)
#define HW_PCIE_PHY_TX_OVRD_OUT_RD()      (HW_PCIE_PHY_TX_OVRD_OUT.U)
#define HW_PCIE_PHY_TX_OVRD_OUT_WR(v)     (HW_PCIE_PHY_TX_OVRD_OUT.U = (v))
#define HW_PCIE_PHY_TX_OVRD_OUT_SET(v)    (HW_PCIE_PHY_TX_OVRD_OUT_WR(HW_PCIE_PHY_TX_OVRD_OUT_RD() |  (v)))
#define HW_PCIE_PHY_TX_OVRD_OUT_CLR(v)    (HW_PCIE_PHY_TX_OVRD_OUT_WR(HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~(v)))
#define HW_PCIE_PHY_TX_OVRD_OUT_TOG(v)    (HW_PCIE_PHY_TX_OVRD_OUT_WR(HW_PCIE_PHY_TX_OVRD_OUT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_OVRD_OUT bitfields
 */

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field DETECT_RX_RES (RW)
 *
 * Override value for tx_detect_rx_res
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES      0
#define BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES)
#else
#define BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES(v)   (((v) << 0) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DETECT_RX_RES field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES(v)   BF_CS1(PCIE_PHY_TX_OVRD_OUT, DETECT_RX_RES, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field DETECT_RX_RES_OVRD (RW)
 *
 * Override enable for tx_detect_rx_res
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD      1
#define BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD(v)   (((v) << 1) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DETECT_RX_RES_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_OUT, DETECT_RX_RES_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_DETECT_RX_ACK (RW)
 *
 * Override value for tx_detect_rx_ack
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK      2
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK)
#else
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK(v)   (((v) << 2) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DETECT_RX_ACK field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK(v)   BF_CS1(PCIE_PHY_TX_OVRD_OUT, TX_DETECT_RX_ACK, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_DETECT_RX_ACK_OVRD (RW)
 *
 * Override enable for tx_detect_rx_ack
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD      3
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD(v)   (((v) << 3) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DETECT_RX_ACK_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_OUT, TX_DETECT_RX_ACK_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_CM_STATE (RW)
 *
 * Override value for tx_cm_state
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE      4
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE)
#else
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE(v)   (((v) << 4) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CM_STATE field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE(v)   BF_CS1(PCIE_PHY_TX_OVRD_OUT, TX_CM_STATE, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_CM_STATE_OVRD (RW)
 *
 * Override enable for tx_cm_state
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD      5
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD(v)   (((v) << 5) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CM_STATE_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_OUT, TX_CM_STATE_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_STATE (RW)
 *
 * Override value for tx_state
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE      6
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE)
#else
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE(v)   (((v) << 6) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_STATE field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_STATE(v)   BF_CS1(PCIE_PHY_TX_OVRD_OUT, TX_STATE, v)
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_STATE_OVRD (RW)
 *
 * Override enable for tx_state
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD      7
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD)
#else
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD(v)   (((v) << 7) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_STATE_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD(v)   BF_CS1(PCIE_PHY_TX_OVRD_OUT, TX_STATE_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_OVRD_IN_LO -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RX_INVERT : 1; //!< Override value for rx_invert
        unsigned short RX_INVERT_OVRD : 1; //!< Override enable for rx_invert
        unsigned short RX_PLL_EN : 1; //!< Override value for rx_pll_en
        unsigned short RX_PLL_EN_OVRD : 1; //!< Override enable for rx_pll_en
        unsigned short RX_DATA_EN : 1; //!< Override value for rx_data_en
        unsigned short RX_DATA_EN_OVRD : 1; //!< Override enable for rx_data_en
        unsigned short RX_ALIGN_EN : 1; //!< Override value for rx_align_en
        unsigned short RX_ALIGN_EN_OVRD : 1; //!< Override enable for rx_align_en
        unsigned short RX_BIT_SHIFT : 1; //!< Override value for rx_bit_shift
        unsigned short RX_BIT_SHIFT_OVRD : 1; //!< Override enable for rx_bit_shift
        unsigned short RX_TERM_EN : 1; //!< Override value for rx_term_en
        unsigned short RX_TERM_EN_OVRD : 1; //!< Override enable for rx_term_en
        unsigned short RX_LOS_EN : 1; //!< Override value for rx_los_en
        unsigned short RX_LOS_EN_OVRD : 1; //!< Override enable for rx_los_en
        unsigned short RESERVED0 : 2; //!< Reserved.
    } B;
} hw_pcie_phy_rx_ovrd_in_lo_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_OVRD_IN_LO register
 */
#define HW_PCIE_PHY_RX_OVRD_IN_LO_ADDR      (REGS_PCIE_PHY_BASE + 0x1005)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_OVRD_IN_LO           (*(volatile hw_pcie_phy_rx_ovrd_in_lo_t *) HW_PCIE_PHY_RX_OVRD_IN_LO_ADDR)
#define HW_PCIE_PHY_RX_OVRD_IN_LO_RD()      (HW_PCIE_PHY_RX_OVRD_IN_LO.U)
#define HW_PCIE_PHY_RX_OVRD_IN_LO_WR(v)     (HW_PCIE_PHY_RX_OVRD_IN_LO.U = (v))
#define HW_PCIE_PHY_RX_OVRD_IN_LO_SET(v)    (HW_PCIE_PHY_RX_OVRD_IN_LO_WR(HW_PCIE_PHY_RX_OVRD_IN_LO_RD() |  (v)))
#define HW_PCIE_PHY_RX_OVRD_IN_LO_CLR(v)    (HW_PCIE_PHY_RX_OVRD_IN_LO_WR(HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~(v)))
#define HW_PCIE_PHY_RX_OVRD_IN_LO_TOG(v)    (HW_PCIE_PHY_RX_OVRD_IN_LO_WR(HW_PCIE_PHY_RX_OVRD_IN_LO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_OVRD_IN_LO bitfields
 */

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_INVERT (RW)
 *
 * Override value for rx_invert
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT      0
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT(v)   (((v) << 0) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_INVERT field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_INVERT, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_INVERT_OVRD (RW)
 *
 * Override enable for rx_invert
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD      1
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD(v)   (((v) << 1) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_INVERT_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_INVERT_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_PLL_EN (RW)
 *
 * Override value for rx_pll_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN      2
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN(v)   (((v) << 2) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_PLL_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_PLL_EN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_PLL_EN_OVRD (RW)
 *
 * Override enable for rx_pll_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD      3
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD(v)   (((v) << 3) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_PLL_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_PLL_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_DATA_EN (RW)
 *
 * Override value for rx_data_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN      4
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN(v)   (((v) << 4) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_DATA_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_DATA_EN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_DATA_EN_OVRD (RW)
 *
 * Override enable for rx_data_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD      5
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD(v)   (((v) << 5) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_DATA_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_DATA_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_ALIGN_EN (RW)
 *
 * Override value for rx_align_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN      6
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN(v)   (((v) << 6) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ALIGN_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_ALIGN_EN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_ALIGN_EN_OVRD (RW)
 *
 * Override enable for rx_align_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD      7
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD(v)   (((v) << 7) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ALIGN_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_ALIGN_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_BIT_SHIFT (RW)
 *
 * Override value for rx_bit_shift
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT      8
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT(v)   (((v) << 8) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_BIT_SHIFT field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_BIT_SHIFT, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_BIT_SHIFT_OVRD (RW)
 *
 * Override enable for rx_bit_shift
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD      9
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD(v)   ((((reg32_t) v) << 9) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD(v)   (((v) << 9) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_BIT_SHIFT_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_BIT_SHIFT_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_TERM_EN (RW)
 *
 * Override value for rx_term_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN      10
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN(v)   (((v) << 10) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_TERM_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_TERM_EN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_TERM_EN_OVRD (RW)
 *
 * Override enable for rx_term_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD      11
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD(v)   ((((reg32_t) v) << 11) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD(v)   (((v) << 11) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_TERM_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_TERM_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_LOS_EN (RW)
 *
 * Override value for rx_los_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN      12
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN(v)   ((((reg32_t) v) << 12) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN(v)   (((v) << 12) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_LOS_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_LOS_EN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_LOS_EN_OVRD (RW)
 *
 * Override enable for rx_los_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD      13
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD(v)   ((((reg32_t) v) << 13) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD(v)   (((v) << 13) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_LOS_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_LO, RX_LOS_EN_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_OVRD_IN_HI -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RX_RATE : 2; //!< Override value for rx_rate
        unsigned short RX_RATE_OVRD : 1; //!< Override enable for rx_rate
        unsigned short RX_LOS_FILTER : 2; //!< Override value for rx_los_filter
        unsigned short RX_LOS_FILTER_OVRD : 1; //!< Override enable for rx_los_filter
        unsigned short RX_EQ_EN : 1; //!< Override value for rx_eq_en
        unsigned short RX_EQ_EN_OVRD : 1; //!< Override enable for rx_eq_en
        unsigned short RX_EQ : 3; //!< Override value for rx_eq
        unsigned short RX_EQ_OVRD : 1; //!< Override enable for rx_eq
        unsigned short RX_RESET : 1; //!< Override value for rx_reset
        unsigned short RX_RESET_OVRD : 1; //!< Override enable for rx_reset
        unsigned short RESERVED0 : 2; //!< Reserved.
    } B;
} hw_pcie_phy_rx_ovrd_in_hi_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_OVRD_IN_HI register
 */
#define HW_PCIE_PHY_RX_OVRD_IN_HI_ADDR      (REGS_PCIE_PHY_BASE + 0x1006)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_OVRD_IN_HI           (*(volatile hw_pcie_phy_rx_ovrd_in_hi_t *) HW_PCIE_PHY_RX_OVRD_IN_HI_ADDR)
#define HW_PCIE_PHY_RX_OVRD_IN_HI_RD()      (HW_PCIE_PHY_RX_OVRD_IN_HI.U)
#define HW_PCIE_PHY_RX_OVRD_IN_HI_WR(v)     (HW_PCIE_PHY_RX_OVRD_IN_HI.U = (v))
#define HW_PCIE_PHY_RX_OVRD_IN_HI_SET(v)    (HW_PCIE_PHY_RX_OVRD_IN_HI_WR(HW_PCIE_PHY_RX_OVRD_IN_HI_RD() |  (v)))
#define HW_PCIE_PHY_RX_OVRD_IN_HI_CLR(v)    (HW_PCIE_PHY_RX_OVRD_IN_HI_WR(HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~(v)))
#define HW_PCIE_PHY_RX_OVRD_IN_HI_TOG(v)    (HW_PCIE_PHY_RX_OVRD_IN_HI_WR(HW_PCIE_PHY_RX_OVRD_IN_HI_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_OVRD_IN_HI bitfields
 */

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_RATE (RW)
 *
 * Override value for rx_rate
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE      0
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE(v)   (((v) << 0) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_RATE field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_RATE, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_RATE_OVRD (RW)
 *
 * Override enable for rx_rate
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD      2
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD(v)   (((v) << 2) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_RATE_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_RATE_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_LOS_FILTER (RW)
 *
 * Override value for rx_los_filter
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER      3
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER      0x00000018

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER(v)   (((v) << 3) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_LOS_FILTER field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_LOS_FILTER, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_LOS_FILTER_OVRD (RW)
 *
 * Override enable for rx_los_filter
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD      5
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD(v)   (((v) << 5) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_LOS_FILTER_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_LOS_FILTER_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_EQ_EN (RW)
 *
 * Override value for rx_eq_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN      6
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN(v)   (((v) << 6) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_EQ_EN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_EQ_EN_OVRD (RW)
 *
 * Override enable for rx_eq_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD      7
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD(v)   (((v) << 7) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_EQ_EN_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_EQ (RW)
 *
 * Override value for rx_eq
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ      8
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ(v)   (((v) << 8) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_EQ, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_EQ_OVRD (RW)
 *
 * Override enable for rx_eq
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD      11
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD(v)   ((((reg32_t) v) << 11) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD(v)   (((v) << 11) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_EQ_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_RESET (RW)
 *
 * Override value for rx_reset
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET      12
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET(v)   ((((reg32_t) v) << 12) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET(v)   (((v) << 12) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_RESET field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_RESET, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_RESET_OVRD (RW)
 *
 * Override enable for rx_reset
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD      13
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD(v)   ((((reg32_t) v) << 13) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD(v)   (((v) << 13) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_RESET_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_IN_HI, RX_RESET_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_OVRD_OUT -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short VALID : 1; //!< Override value for rx_valid
        unsigned short VALID_OVRD : 1; //!< Override enable for rx_valid
        unsigned short PLL_STATE : 1; //!< Override value for rx_pll_state
        unsigned short PLL_STATE_OVRD : 1; //!< Override enable for rx_pll_state
        unsigned short LOS : 1; //!< Override value for rx_los
        unsigned short LOS_OVRD : 1; //!< Override value for rx_los
        unsigned short ZERO_DATA : 1; //!< Override data output to all zeros
        unsigned short RESERVED0 : 9; //!< Reserved.
    } B;
} hw_pcie_phy_rx_ovrd_out_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_OVRD_OUT register
 */
#define HW_PCIE_PHY_RX_OVRD_OUT_ADDR      (REGS_PCIE_PHY_BASE + 0x1007)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_OVRD_OUT           (*(volatile hw_pcie_phy_rx_ovrd_out_t *) HW_PCIE_PHY_RX_OVRD_OUT_ADDR)
#define HW_PCIE_PHY_RX_OVRD_OUT_RD()      (HW_PCIE_PHY_RX_OVRD_OUT.U)
#define HW_PCIE_PHY_RX_OVRD_OUT_WR(v)     (HW_PCIE_PHY_RX_OVRD_OUT.U = (v))
#define HW_PCIE_PHY_RX_OVRD_OUT_SET(v)    (HW_PCIE_PHY_RX_OVRD_OUT_WR(HW_PCIE_PHY_RX_OVRD_OUT_RD() |  (v)))
#define HW_PCIE_PHY_RX_OVRD_OUT_CLR(v)    (HW_PCIE_PHY_RX_OVRD_OUT_WR(HW_PCIE_PHY_RX_OVRD_OUT_RD() & ~(v)))
#define HW_PCIE_PHY_RX_OVRD_OUT_TOG(v)    (HW_PCIE_PHY_RX_OVRD_OUT_WR(HW_PCIE_PHY_RX_OVRD_OUT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_OVRD_OUT bitfields
 */

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field VALID (RW)
 *
 * Override value for rx_valid
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_VALID      0
#define BM_PCIE_PHY_RX_OVRD_OUT_VALID      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_OUT_VALID(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_OVRD_OUT_VALID)
#else
#define BF_PCIE_PHY_RX_OVRD_OUT_VALID(v)   (((v) << 0) & BM_PCIE_PHY_RX_OVRD_OUT_VALID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALID field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_VALID(v)   BF_CS1(PCIE_PHY_RX_OVRD_OUT, VALID, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field VALID_OVRD (RW)
 *
 * Override enable for rx_valid
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD      1
#define BM_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD(v)   (((v) << 1) & BM_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VALID_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_OUT, VALID_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field PLL_STATE (RW)
 *
 * Override value for rx_pll_state
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE      2
#define BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE)
#else
#define BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE(v)   (((v) << 2) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_STATE field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_PLL_STATE(v)   BF_CS1(PCIE_PHY_RX_OVRD_OUT, PLL_STATE, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field PLL_STATE_OVRD (RW)
 *
 * Override enable for rx_pll_state
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD      3
#define BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD(v)   (((v) << 3) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_STATE_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_OUT, PLL_STATE_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field LOS (RW)
 *
 * Override value for rx_los
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_LOS      4
#define BM_PCIE_PHY_RX_OVRD_OUT_LOS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_OUT_LOS(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RX_OVRD_OUT_LOS)
#else
#define BF_PCIE_PHY_RX_OVRD_OUT_LOS(v)   (((v) << 4) & BM_PCIE_PHY_RX_OVRD_OUT_LOS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_LOS(v)   BF_CS1(PCIE_PHY_RX_OVRD_OUT, LOS, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field LOS_OVRD (RW)
 *
 * Override value for rx_los
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD      5
#define BM_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD)
#else
#define BF_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD(v)   (((v) << 5) & BM_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD(v)   BF_CS1(PCIE_PHY_RX_OVRD_OUT, LOS_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field ZERO_DATA (RW)
 *
 * Override data output to all zeros
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA      6
#define BM_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA)
#else
#define BF_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA(v)   (((v) << 6) & BM_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ZERO_DATA field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA(v)   BF_CS1(PCIE_PHY_RX_OVRD_OUT, ZERO_DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ASIC_IN -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short TX_RATE : 2; //!< Value from ASIC for tx_rate
        unsigned short LOOPBK_EN : 1; //!< Value from ASIC for loopbk_en
        unsigned short INVERT : 1; //!< Value from ASIC for tx_invert
        unsigned short TX_RESET : 1; //!< Value from ASIC for tx_reset
        unsigned short DATA_EN : 1; //!< Value from ASIC for tx_data_en
        unsigned short TX_EN : 1; //!< Value from ASIC for tx_en
        unsigned short CM_EN : 1; //!< Value from ASIC for tx_cm_en
        unsigned short BEACON_EN : 1; //!< Value from ASIC for tx_beacon_en
        unsigned short DETECT_RX_REQ : 1; //!< Value from ASIC for tx_detect_rx_req
        unsigned short TX_CLK_OUT_EN : 1; //!< Value from ASIC for tx_clk_out_en
        unsigned short RESERVED0 : 5; //!< Reserved.
    } B;
} hw_pcie_phy_tx_asic_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_ASIC_IN register
 */
#define HW_PCIE_PHY_TX_ASIC_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x1008)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_ASIC_IN           (*(volatile hw_pcie_phy_tx_asic_in_t *) HW_PCIE_PHY_TX_ASIC_IN_ADDR)
#define HW_PCIE_PHY_TX_ASIC_IN_RD()      (HW_PCIE_PHY_TX_ASIC_IN.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_ASIC_IN bitfields
 */

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field TX_RATE (RO)
 *
 * Value from ASIC for tx_rate
 */

#define BP_PCIE_PHY_TX_ASIC_IN_TX_RATE      0
#define BM_PCIE_PHY_TX_ASIC_IN_TX_RATE      0x00000003

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field LOOPBK_EN (RO)
 *
 * Value from ASIC for loopbk_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_LOOPBK_EN      2
#define BM_PCIE_PHY_TX_ASIC_IN_LOOPBK_EN      0x00000004

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field INVERT (RO)
 *
 * Value from ASIC for tx_invert
 */

#define BP_PCIE_PHY_TX_ASIC_IN_INVERT      3
#define BM_PCIE_PHY_TX_ASIC_IN_INVERT      0x00000008

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field TX_RESET (RO)
 *
 * Value from ASIC for tx_reset
 */

#define BP_PCIE_PHY_TX_ASIC_IN_TX_RESET      4
#define BM_PCIE_PHY_TX_ASIC_IN_TX_RESET      0x00000010

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field DATA_EN (RO)
 *
 * Value from ASIC for tx_data_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_DATA_EN      5
#define BM_PCIE_PHY_TX_ASIC_IN_DATA_EN      0x00000020

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field TX_EN (RO)
 *
 * Value from ASIC for tx_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_TX_EN      6
#define BM_PCIE_PHY_TX_ASIC_IN_TX_EN      0x00000040

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field CM_EN (RO)
 *
 * Value from ASIC for tx_cm_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_CM_EN      7
#define BM_PCIE_PHY_TX_ASIC_IN_CM_EN      0x00000080

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field BEACON_EN (RO)
 *
 * Value from ASIC for tx_beacon_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_BEACON_EN      8
#define BM_PCIE_PHY_TX_ASIC_IN_BEACON_EN      0x00000100

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field DETECT_RX_REQ (RO)
 *
 * Value from ASIC for tx_detect_rx_req
 */

#define BP_PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ      9
#define BM_PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ      0x00000200

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field TX_CLK_OUT_EN (RO)
 *
 * Value from ASIC for tx_clk_out_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN      10
#define BM_PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN      0x00000400

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ASIC_DRV_LO -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short AMPLITUDE : 7; //!< Value from ASIC for tx_amplitude
        unsigned short PREEMPH : 7; //!< Value from ASIC for tx_preemph
        unsigned short RESERVED0 : 2; //!< Reserved.
    } B;
} hw_pcie_phy_tx_asic_drv_lo_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_ASIC_DRV_LO register
 */
#define HW_PCIE_PHY_TX_ASIC_DRV_LO_ADDR      (REGS_PCIE_PHY_BASE + 0x1009)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_ASIC_DRV_LO           (*(volatile hw_pcie_phy_tx_asic_drv_lo_t *) HW_PCIE_PHY_TX_ASIC_DRV_LO_ADDR)
#define HW_PCIE_PHY_TX_ASIC_DRV_LO_RD()      (HW_PCIE_PHY_TX_ASIC_DRV_LO.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_ASIC_DRV_LO bitfields
 */

/* --- Register HW_PCIE_PHY_TX_ASIC_DRV_LO, field AMPLITUDE (RO)
 *
 * Value from ASIC for tx_amplitude
 */

#define BP_PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE      0
#define BM_PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE      0x0000007f

/* --- Register HW_PCIE_PHY_TX_ASIC_DRV_LO, field PREEMPH (RO)
 *
 * Value from ASIC for tx_preemph
 */

#define BP_PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH      7
#define BM_PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH      0x00003f80

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ASIC_DRV_HI -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short TERM_OFFSET : 5; //!< Value from ASIC for tx_term_offset
        unsigned short RESERVED0 : 11; //!< Reserved.
    } B;
} hw_pcie_phy_tx_asic_drv_hi_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_ASIC_DRV_HI register
 */
#define HW_PCIE_PHY_TX_ASIC_DRV_HI_ADDR      (REGS_PCIE_PHY_BASE + 0x100a)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_ASIC_DRV_HI           (*(volatile hw_pcie_phy_tx_asic_drv_hi_t *) HW_PCIE_PHY_TX_ASIC_DRV_HI_ADDR)
#define HW_PCIE_PHY_TX_ASIC_DRV_HI_RD()      (HW_PCIE_PHY_TX_ASIC_DRV_HI.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_ASIC_DRV_HI bitfields
 */

/* --- Register HW_PCIE_PHY_TX_ASIC_DRV_HI, field TERM_OFFSET (RO)
 *
 * Value from ASIC for tx_term_offset
 */

#define BP_PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET      0
#define BM_PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET      0x0000001f

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ASIC_OUT -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DETECT_RX_RES : 1; //!< Value from PHY for tx_detect_rx_res
        unsigned short RESERVED0 : 1; //!< Always returns 0
        unsigned short DETECT_RX_ACK : 1; //!< Value from PHY for tx_detect_rx_ack
        unsigned short CM_STATE : 1; //!< Value from PHY for tx_cm_state
        unsigned short STATE : 1; //!< Value from PHY for tx_state
        unsigned short RESERVED1 : 11; //!< Reserved.
    } B;
} hw_pcie_phy_tx_asic_out_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_ASIC_OUT register
 */
#define HW_PCIE_PHY_TX_ASIC_OUT_ADDR      (REGS_PCIE_PHY_BASE + 0x100b)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_ASIC_OUT           (*(volatile hw_pcie_phy_tx_asic_out_t *) HW_PCIE_PHY_TX_ASIC_OUT_ADDR)
#define HW_PCIE_PHY_TX_ASIC_OUT_RD()      (HW_PCIE_PHY_TX_ASIC_OUT.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_ASIC_OUT bitfields
 */

/* --- Register HW_PCIE_PHY_TX_ASIC_OUT, field DETECT_RX_RES (RO)
 *
 * Value from PHY for tx_detect_rx_res
 */

#define BP_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES      0
#define BM_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES      0x00000001

/* --- Register HW_PCIE_PHY_TX_ASIC_OUT, field DETECT_RX_ACK (RO)
 *
 * Value from PHY for tx_detect_rx_ack
 */

#define BP_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK      2
#define BM_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK      0x00000004

/* --- Register HW_PCIE_PHY_TX_ASIC_OUT, field CM_STATE (RO)
 *
 * Value from PHY for tx_cm_state
 */

#define BP_PCIE_PHY_TX_ASIC_OUT_CM_STATE      3
#define BM_PCIE_PHY_TX_ASIC_OUT_CM_STATE      0x00000008

/* --- Register HW_PCIE_PHY_TX_ASIC_OUT, field STATE (RO)
 *
 * Value from PHY for tx_state
 */

#define BP_PCIE_PHY_TX_ASIC_OUT_STATE      4
#define BM_PCIE_PHY_TX_ASIC_OUT_STATE      0x00000010

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ASIC_IN -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RX_RATE : 2; //!< Value from ASIC for rx_rate
        unsigned short INVERT : 1; //!< Value from ASIC for rx_invert
        unsigned short RX_RESET : 1; //!< Value from ASIC for rx_reset
        unsigned short PLL_EN : 1; //!< Value from ASIC for rx_pll_en
        unsigned short DATA_EN : 1; //!< Value from ASIC for rx_data_en
        unsigned short ALIGN_EN : 1; //!< Value from ASIC for rx_align_en
        unsigned short CLK_SHIFT : 1; //!< Value from ASIC for rx_bit_shift
        unsigned short TERM_EN : 1; //!< Value from ASIC for rx_term_en
        unsigned short LOS_EN : 1; //!< Value from ASIC for rx_los_en
        unsigned short LOS_FILTER : 2; //!< Value from ASIC for rx_los_filter
        unsigned short RX_EQ : 3; //!< Value from ASIC for rx_eq
        unsigned short RX_EQ_EN : 1; //!< Value from ASIC for rx_eq_en
    } B;
} hw_pcie_phy_rx_asic_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_ASIC_IN register
 */
#define HW_PCIE_PHY_RX_ASIC_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x100c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_ASIC_IN           (*(volatile hw_pcie_phy_rx_asic_in_t *) HW_PCIE_PHY_RX_ASIC_IN_ADDR)
#define HW_PCIE_PHY_RX_ASIC_IN_RD()      (HW_PCIE_PHY_RX_ASIC_IN.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_ASIC_IN bitfields
 */

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field RX_RATE (RO)
 *
 * Value from ASIC for rx_rate
 */

#define BP_PCIE_PHY_RX_ASIC_IN_RX_RATE      0
#define BM_PCIE_PHY_RX_ASIC_IN_RX_RATE      0x00000003

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field INVERT (RO)
 *
 * Value from ASIC for rx_invert
 */

#define BP_PCIE_PHY_RX_ASIC_IN_INVERT      2
#define BM_PCIE_PHY_RX_ASIC_IN_INVERT      0x00000004

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field RX_RESET (RO)
 *
 * Value from ASIC for rx_reset
 */

#define BP_PCIE_PHY_RX_ASIC_IN_RX_RESET      3
#define BM_PCIE_PHY_RX_ASIC_IN_RX_RESET      0x00000008

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field PLL_EN (RO)
 *
 * Value from ASIC for rx_pll_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_PLL_EN      4
#define BM_PCIE_PHY_RX_ASIC_IN_PLL_EN      0x00000010

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field DATA_EN (RO)
 *
 * Value from ASIC for rx_data_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_DATA_EN      5
#define BM_PCIE_PHY_RX_ASIC_IN_DATA_EN      0x00000020

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field ALIGN_EN (RO)
 *
 * Value from ASIC for rx_align_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_ALIGN_EN      6
#define BM_PCIE_PHY_RX_ASIC_IN_ALIGN_EN      0x00000040

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field CLK_SHIFT (RO)
 *
 * Value from ASIC for rx_bit_shift
 */

#define BP_PCIE_PHY_RX_ASIC_IN_CLK_SHIFT      7
#define BM_PCIE_PHY_RX_ASIC_IN_CLK_SHIFT      0x00000080

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field TERM_EN (RO)
 *
 * Value from ASIC for rx_term_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_TERM_EN      8
#define BM_PCIE_PHY_RX_ASIC_IN_TERM_EN      0x00000100

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field LOS_EN (RO)
 *
 * Value from ASIC for rx_los_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_LOS_EN      9
#define BM_PCIE_PHY_RX_ASIC_IN_LOS_EN      0x00000200

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field LOS_FILTER (RO)
 *
 * Value from ASIC for rx_los_filter
 */

#define BP_PCIE_PHY_RX_ASIC_IN_LOS_FILTER      10
#define BM_PCIE_PHY_RX_ASIC_IN_LOS_FILTER      0x00000c00

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field RX_EQ (RO)
 *
 * Value from ASIC for rx_eq
 */

#define BP_PCIE_PHY_RX_ASIC_IN_RX_EQ      12
#define BM_PCIE_PHY_RX_ASIC_IN_RX_EQ      0x00007000

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field RX_EQ_EN (RO)
 *
 * Value from ASIC for rx_eq_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_RX_EQ_EN      15
#define BM_PCIE_PHY_RX_ASIC_IN_RX_EQ_EN      0x00008000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ASIC_OUT -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short VALID : 1; //!< Value from PHY for rx_valid
        unsigned short PLL_STATE : 1; //!< Value from PHY for rx_pll_state
        unsigned short LOS : 1; //!< Value from PHY for rx_los
        unsigned short RESERVED0 : 13; //!< Reserved.
    } B;
} hw_pcie_phy_rx_asic_out_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_ASIC_OUT register
 */
#define HW_PCIE_PHY_RX_ASIC_OUT_ADDR      (REGS_PCIE_PHY_BASE + 0x100d)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_ASIC_OUT           (*(volatile hw_pcie_phy_rx_asic_out_t *) HW_PCIE_PHY_RX_ASIC_OUT_ADDR)
#define HW_PCIE_PHY_RX_ASIC_OUT_RD()      (HW_PCIE_PHY_RX_ASIC_OUT.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_ASIC_OUT bitfields
 */

/* --- Register HW_PCIE_PHY_RX_ASIC_OUT, field VALID (RO)
 *
 * Value from PHY for rx_valid
 */

#define BP_PCIE_PHY_RX_ASIC_OUT_VALID      0
#define BM_PCIE_PHY_RX_ASIC_OUT_VALID      0x00000001

/* --- Register HW_PCIE_PHY_RX_ASIC_OUT, field PLL_STATE (RO)
 *
 * Value from PHY for rx_pll_state
 */

#define BP_PCIE_PHY_RX_ASIC_OUT_PLL_STATE      1
#define BM_PCIE_PHY_RX_ASIC_OUT_PLL_STATE      0x00000002

/* --- Register HW_PCIE_PHY_RX_ASIC_OUT, field LOS (RO)
 *
 * Value from PHY for rx_los
 */

#define BP_PCIE_PHY_RX_ASIC_OUT_LOS      2
#define BM_PCIE_PHY_RX_ASIC_OUT_LOS      0x00000004

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_DEBUG -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DTB_SEL : 3; //!< Selects data to drive on DTB 0.
        unsigned short DETECT_RX_ALWAYS : 1; //!< Always signal 1 for rx_detect ignoring analog
        unsigned short RXDET_MEAS_TIME : 8; //!< Time to wait for rxdet measurement (* 8 refclk cycles)
        unsigned short CM_LFPS_EN : 1; //!< Use LFPS to reach Common Mode. Let VCMHOLD circuit drive it is cleared.
        unsigned short RESERVED0 : 3; //!< Reserved.
    } B;
} hw_pcie_phy_tx_debug_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_DEBUG register
 */
#define HW_PCIE_PHY_TX_DEBUG_ADDR      (REGS_PCIE_PHY_BASE + 0x1010)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_DEBUG           (*(volatile hw_pcie_phy_tx_debug_t *) HW_PCIE_PHY_TX_DEBUG_ADDR)
#define HW_PCIE_PHY_TX_DEBUG_RD()      (HW_PCIE_PHY_TX_DEBUG.U)
#define HW_PCIE_PHY_TX_DEBUG_WR(v)     (HW_PCIE_PHY_TX_DEBUG.U = (v))
#define HW_PCIE_PHY_TX_DEBUG_SET(v)    (HW_PCIE_PHY_TX_DEBUG_WR(HW_PCIE_PHY_TX_DEBUG_RD() |  (v)))
#define HW_PCIE_PHY_TX_DEBUG_CLR(v)    (HW_PCIE_PHY_TX_DEBUG_WR(HW_PCIE_PHY_TX_DEBUG_RD() & ~(v)))
#define HW_PCIE_PHY_TX_DEBUG_TOG(v)    (HW_PCIE_PHY_TX_DEBUG_WR(HW_PCIE_PHY_TX_DEBUG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_DEBUG bitfields
 */

/* --- Register HW_PCIE_PHY_TX_DEBUG, field DTB_SEL (RW)
 *
 * Selects data to drive on DTB 0.
 *
 * Values:
 * 0 - Disabled
 * 1 - mag_update/sub signals
 * 2 - mag_high/add signals
 * 3 - Clock aligner early/shift signals
 * 4 - Analog/ASIC clocks
 * 5 - tx_state counter/LBERT strobe
 * 6 - noclk_ref_rst/dig_rst
 * 7 - tx_ana_rxdetp_high/tx_ana_rx
 */

#define BP_PCIE_PHY_TX_DEBUG_DTB_SEL      0
#define BM_PCIE_PHY_TX_DEBUG_DTB_SEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_DEBUG_DTB_SEL(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_DEBUG_DTB_SEL)
#else
#define BF_PCIE_PHY_TX_DEBUG_DTB_SEL(v)   (((v) << 0) & BM_PCIE_PHY_TX_DEBUG_DTB_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL field to a new value.
#define BW_PCIE_PHY_TX_DEBUG_DTB_SEL(v)   BF_CS1(PCIE_PHY_TX_DEBUG, DTB_SEL, v)
#endif


/* --- Register HW_PCIE_PHY_TX_DEBUG, field DETECT_RX_ALWAYS (RW)
 *
 * Always signal 1 for rx_detect ignoring analog
 */

#define BP_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS      3
#define BM_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS)
#else
#define BF_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS(v)   (((v) << 3) & BM_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DETECT_RX_ALWAYS field to a new value.
#define BW_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS(v)   BF_CS1(PCIE_PHY_TX_DEBUG, DETECT_RX_ALWAYS, v)
#endif

/* --- Register HW_PCIE_PHY_TX_DEBUG, field RXDET_MEAS_TIME (RW)
 *
 * Time to wait for rxdet measurement (* 8 refclk cycles)
 */

#define BP_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME      4
#define BM_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME      0x00000ff0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME)
#else
#define BF_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME(v)   (((v) << 4) & BM_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDET_MEAS_TIME field to a new value.
#define BW_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME(v)   BF_CS1(PCIE_PHY_TX_DEBUG, RXDET_MEAS_TIME, v)
#endif

/* --- Register HW_PCIE_PHY_TX_DEBUG, field CM_LFPS_EN (RW)
 *
 * Use LFPS to reach Common Mode. Let VCMHOLD circuit drive it is cleared.
 */

#define BP_PCIE_PHY_TX_DEBUG_CM_LFPS_EN      12
#define BM_PCIE_PHY_TX_DEBUG_CM_LFPS_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_DEBUG_CM_LFPS_EN(v)   ((((reg32_t) v) << 12) & BM_PCIE_PHY_TX_DEBUG_CM_LFPS_EN)
#else
#define BF_PCIE_PHY_TX_DEBUG_CM_LFPS_EN(v)   (((v) << 12) & BM_PCIE_PHY_TX_DEBUG_CM_LFPS_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CM_LFPS_EN field to a new value.
#define BW_PCIE_PHY_TX_DEBUG_CM_LFPS_EN(v)   BF_CS1(PCIE_PHY_TX_DEBUG, CM_LFPS_EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0 -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short N_TRISTATE : 7; //!< Value from VMD for number of tristate legs.
        unsigned short N_USE : 7; //!< Value from VMD for legs to use
        unsigned short DONE : 1; //!< Configuration is done
        unsigned short RESERVED0 : 1; //!< Reserved.
    } B;
} hw_pcie_phy_tx_vmd_fsm_tx_vcm_0_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_VMD_FSM_TX_VCM_0 register
 */
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_ADDR      (REGS_PCIE_PHY_BASE + 0x1011)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0           (*(volatile hw_pcie_phy_tx_vmd_fsm_tx_vcm_0_t *) HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_ADDR)
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_RD()      (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_VMD_FSM_TX_VCM_0 bitfields
 */

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0, field N_TRISTATE (RO)
 *
 * Value from VMD for number of tristate legs.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE      0
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE      0x0000007f

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0, field N_USE (RO)
 *
 * Value from VMD for legs to use
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE      7
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE      0x00003f80

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0, field DONE (RO)
 *
 * Configuration is done
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE      14
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE      0x00004000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1 -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short N_TRAILER : 7; //!< Value from VMD for number of trailer legs.
        unsigned short N_FIXED : 7; //!< Value from VMD for number of fixed driver legs.
        unsigned short TRA_DONE : 1; //!< N_TRAILER Multiplication has completed.
        unsigned short FIXED_DONE : 1; //!< N_FIXED Multiplication has completed.
    } B;
} hw_pcie_phy_tx_vmd_fsm_tx_vcm_1_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_VMD_FSM_TX_VCM_1 register
 */
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_ADDR      (REGS_PCIE_PHY_BASE + 0x1012)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1           (*(volatile hw_pcie_phy_tx_vmd_fsm_tx_vcm_1_t *) HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_ADDR)
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_RD()      (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_VMD_FSM_TX_VCM_1 bitfields
 */

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1, field N_TRAILER (RO)
 *
 * Value from VMD for number of trailer legs.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER      0
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER      0x0000007f

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1, field N_FIXED (RO)
 *
 * Value from VMD for number of fixed driver legs.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED      7
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED      0x00003f80

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1, field TRA_DONE (RO)
 *
 * N_TRAILER Multiplication has completed.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE      14
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE      0x00004000

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1, field FIXED_DONE (RO)
 *
 * N_FIXED Multiplication has completed.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE      15
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE      0x00008000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CONFIG_DATA : 1; //!< Override value for the Voltage Mode Driver Configuration FSM's config data.
        unsigned short CONFIG_CLK : 1; //!< Override value for the Voltage Mode Driver Configuration FSM's config clk.
        unsigned short CONFIG_LOAD : 1; //!< Override value for the Voltage Mode Driver Configuration FSM's config load.
        unsigned short CONFIG_OVRD : 1; //!< Override the Voltage Mode Driver Configuration FSM and access the shift chain directly.
        unsigned short RESERVED0 : 12; //!< Reserved
    } B;
} hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_in_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN register
 */
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_ADDR      (REGS_PCIE_PHY_BASE + 0x1013)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN           (*(volatile hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_in_t *) HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_ADDR)
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_RD()      (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN.U)
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_WR(v)     (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN.U = (v))
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_SET(v)    (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_WR(HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_RD() |  (v)))
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CLR(v)    (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_WR(HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_RD() & ~(v)))
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_TOG(v)    (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_WR(HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN bitfields
 */

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, field CONFIG_DATA (RW)
 *
 * Override value for the Voltage Mode Driver Configuration FSM's config data.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA      0
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA)
#else
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA(v)   (((v) << 0) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIG_DATA field to a new value.
#define BW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA(v)   BF_CS1(PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, CONFIG_DATA, v)
#endif

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, field CONFIG_CLK (RW)
 *
 * Override value for the Voltage Mode Driver Configuration FSM's config clk.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK      1
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK)
#else
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK(v)   (((v) << 1) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIG_CLK field to a new value.
#define BW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK(v)   BF_CS1(PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, CONFIG_CLK, v)
#endif

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, field CONFIG_LOAD (RW)
 *
 * Override value for the Voltage Mode Driver Configuration FSM's config load.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD      2
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD)
#else
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD(v)   (((v) << 2) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIG_LOAD field to a new value.
#define BW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD(v)   BF_CS1(PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, CONFIG_LOAD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, field CONFIG_OVRD (RW)
 *
 * Override the Voltage Mode Driver Configuration FSM and access the shift chain directly.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD      3
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD)
#else
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD(v)   (((v) << 3) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIG_OVRD field to a new value.
#define BW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD(v)   BF_CS1(PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, CONFIG_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short SHIFT_OUT : 1; //!< Current value from TX_ANAs configuration shift register.
        unsigned short RESERVED0 : 15; //!< Reserved
    } B;
} hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_out_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT register
 */
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_ADDR      (REGS_PCIE_PHY_BASE + 0x1014)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT           (*(volatile hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_out_t *) HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_ADDR)
#define HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_RD()      (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT bitfields
 */

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT, field SHIFT_OUT (RO)
 *
 * Current value from TX_ANAs configuration shift register.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT      0
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT      0x00000001

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_LBERT_CTL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MODE : 3; //!< Pattern to generate When changing modes, you must first change to disabled.
        unsigned short TRIGGER_ERR : 1; //!< Insert a single error into a lsb Any write of a 1 to this bit will insert an error
        unsigned short PAT0 : 10; //!< Pattern for modes 3-5
        unsigned short RESERVED0 : 2; //!< Reserved
    } B;
} hw_pcie_phy_tx_lbert_ctl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_LBERT_CTL register
 */
#define HW_PCIE_PHY_TX_LBERT_CTL_ADDR      (REGS_PCIE_PHY_BASE + 0x1015)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_LBERT_CTL           (*(volatile hw_pcie_phy_tx_lbert_ctl_t *) HW_PCIE_PHY_TX_LBERT_CTL_ADDR)
#define HW_PCIE_PHY_TX_LBERT_CTL_RD()      (HW_PCIE_PHY_TX_LBERT_CTL.U)
#define HW_PCIE_PHY_TX_LBERT_CTL_WR(v)     (HW_PCIE_PHY_TX_LBERT_CTL.U = (v))
#define HW_PCIE_PHY_TX_LBERT_CTL_SET(v)    (HW_PCIE_PHY_TX_LBERT_CTL_WR(HW_PCIE_PHY_TX_LBERT_CTL_RD() |  (v)))
#define HW_PCIE_PHY_TX_LBERT_CTL_CLR(v)    (HW_PCIE_PHY_TX_LBERT_CTL_WR(HW_PCIE_PHY_TX_LBERT_CTL_RD() & ~(v)))
#define HW_PCIE_PHY_TX_LBERT_CTL_TOG(v)    (HW_PCIE_PHY_TX_LBERT_CTL_WR(HW_PCIE_PHY_TX_LBERT_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_LBERT_CTL bitfields
 */

/* --- Register HW_PCIE_PHY_TX_LBERT_CTL, field MODE (RW)
 *
 * Pattern to generate When changing modes, you must first change to disabled.
 *
 * Values:
 * 0 - Disabled
 * 1 - lfsr31. X^31 + X^28 + 1
 * 2 - lfsr23. X^23 + X^18 + 1
 * 3 - lfsr15. X^15 + X^14 + 1
 * 4 - lfsr7. X^7 + X^6 + 1
 * 5 - Fixed word (PAT0)
 * 6 - DC-balanced word (PAT0)
 */

#define BP_PCIE_PHY_TX_LBERT_CTL_MODE      0
#define BM_PCIE_PHY_TX_LBERT_CTL_MODE      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_LBERT_CTL_MODE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_LBERT_CTL_MODE)
#else
#define BF_PCIE_PHY_TX_LBERT_CTL_MODE(v)   (((v) << 0) & BM_PCIE_PHY_TX_LBERT_CTL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_PCIE_PHY_TX_LBERT_CTL_MODE(v)   BF_CS1(PCIE_PHY_TX_LBERT_CTL, MODE, v)
#endif


/* --- Register HW_PCIE_PHY_TX_LBERT_CTL, field TRIGGER_ERR (RW)
 *
 * Insert a single error into a lsb Any write of a 1 to this bit will insert an error
 */

#define BP_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR      3
#define BM_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR)
#else
#define BF_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR(v)   (((v) << 3) & BM_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TRIGGER_ERR field to a new value.
#define BW_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR(v)   BF_CS1(PCIE_PHY_TX_LBERT_CTL, TRIGGER_ERR, v)
#endif

/* --- Register HW_PCIE_PHY_TX_LBERT_CTL, field PAT0 (RW)
 *
 * Pattern for modes 3-5
 */

#define BP_PCIE_PHY_TX_LBERT_CTL_PAT0      4
#define BM_PCIE_PHY_TX_LBERT_CTL_PAT0      0x00003ff0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_LBERT_CTL_PAT0(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_LBERT_CTL_PAT0)
#else
#define BF_PCIE_PHY_TX_LBERT_CTL_PAT0(v)   (((v) << 4) & BM_PCIE_PHY_TX_LBERT_CTL_PAT0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PAT0 field to a new value.
#define BW_PCIE_PHY_TX_LBERT_CTL_PAT0(v)   BF_CS1(PCIE_PHY_TX_LBERT_CTL, PAT0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_LBERT_CTL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MODE : 3; //!< Pattern to match When changing modes, you must first change to disabled.
        unsigned short SYNC : 1; //!< Synchronize pattern matcher LFSR with incoming data A write of a one to this bit will reset the error counter and start a synchronization of the PM. There is no need to write this back to zero to run normally.
        unsigned short RESERVED0 : 12; //!< Reserved
    } B;
} hw_pcie_phy_rx_lbert_ctl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_LBERT_CTL register
 */
#define HW_PCIE_PHY_RX_LBERT_CTL_ADDR      (REGS_PCIE_PHY_BASE + 0x1016)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_LBERT_CTL           (*(volatile hw_pcie_phy_rx_lbert_ctl_t *) HW_PCIE_PHY_RX_LBERT_CTL_ADDR)
#define HW_PCIE_PHY_RX_LBERT_CTL_RD()      (HW_PCIE_PHY_RX_LBERT_CTL.U)
#define HW_PCIE_PHY_RX_LBERT_CTL_WR(v)     (HW_PCIE_PHY_RX_LBERT_CTL.U = (v))
#define HW_PCIE_PHY_RX_LBERT_CTL_SET(v)    (HW_PCIE_PHY_RX_LBERT_CTL_WR(HW_PCIE_PHY_RX_LBERT_CTL_RD() |  (v)))
#define HW_PCIE_PHY_RX_LBERT_CTL_CLR(v)    (HW_PCIE_PHY_RX_LBERT_CTL_WR(HW_PCIE_PHY_RX_LBERT_CTL_RD() & ~(v)))
#define HW_PCIE_PHY_RX_LBERT_CTL_TOG(v)    (HW_PCIE_PHY_RX_LBERT_CTL_WR(HW_PCIE_PHY_RX_LBERT_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_LBERT_CTL bitfields
 */

/* --- Register HW_PCIE_PHY_RX_LBERT_CTL, field MODE (RW)
 *
 * Pattern to match When changing modes, you must first change to disabled.
 *
 * Values:
 * 0 - Disabled
 * 1 - lfsr31. X^31 + X^28 + 1
 * 2 - lfsr23. X^23 + X^18 + 1
 * 3 - lfsr15: X^15 + X^14 + 1
 * 4 - lfsr7 : X^7 + X^6 + 1
 * 5 - d[n] = d[n-10]
 * 6 - d[n] = !d[n-10]
 * 7 - d[n] =
 */

#define BP_PCIE_PHY_RX_LBERT_CTL_MODE      0
#define BM_PCIE_PHY_RX_LBERT_CTL_MODE      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_LBERT_CTL_MODE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_LBERT_CTL_MODE)
#else
#define BF_PCIE_PHY_RX_LBERT_CTL_MODE(v)   (((v) << 0) & BM_PCIE_PHY_RX_LBERT_CTL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_PCIE_PHY_RX_LBERT_CTL_MODE(v)   BF_CS1(PCIE_PHY_RX_LBERT_CTL, MODE, v)
#endif


/* --- Register HW_PCIE_PHY_RX_LBERT_CTL, field SYNC (RW)
 *
 * Synchronize pattern matcher LFSR with incoming data A write of a one to this bit will reset the
 * error counter and start a synchronization of the PM. There is no need to write this back to zero
 * to run normally.
 */

#define BP_PCIE_PHY_RX_LBERT_CTL_SYNC      3
#define BM_PCIE_PHY_RX_LBERT_CTL_SYNC      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_LBERT_CTL_SYNC(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_LBERT_CTL_SYNC)
#else
#define BF_PCIE_PHY_RX_LBERT_CTL_SYNC(v)   (((v) << 3) & BM_PCIE_PHY_RX_LBERT_CTL_SYNC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYNC field to a new value.
#define BW_PCIE_PHY_RX_LBERT_CTL_SYNC(v)   BF_CS1(PCIE_PHY_RX_LBERT_CTL, SYNC, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_LBERT_ERR -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short COUNT : 15; //!< A read of this register, or a sync of the PM resets the error count. Current error count If OV14 field is active, then multiply count by 128
        unsigned short OV14 : 1; //!< If active, multiply COUNT by 128. If OV14=1 and COUNT=2^15-1, signals overflow of counter
    } B;
} hw_pcie_phy_rx_lbert_err_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_LBERT_ERR register
 */
#define HW_PCIE_PHY_RX_LBERT_ERR_ADDR      (REGS_PCIE_PHY_BASE + 0x1017)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_LBERT_ERR           (*(volatile hw_pcie_phy_rx_lbert_err_t *) HW_PCIE_PHY_RX_LBERT_ERR_ADDR)
#define HW_PCIE_PHY_RX_LBERT_ERR_RD()      (HW_PCIE_PHY_RX_LBERT_ERR.U)
#define HW_PCIE_PHY_RX_LBERT_ERR_WR(v)     (HW_PCIE_PHY_RX_LBERT_ERR.U = (v))
#define HW_PCIE_PHY_RX_LBERT_ERR_SET(v)    (HW_PCIE_PHY_RX_LBERT_ERR_WR(HW_PCIE_PHY_RX_LBERT_ERR_RD() |  (v)))
#define HW_PCIE_PHY_RX_LBERT_ERR_CLR(v)    (HW_PCIE_PHY_RX_LBERT_ERR_WR(HW_PCIE_PHY_RX_LBERT_ERR_RD() & ~(v)))
#define HW_PCIE_PHY_RX_LBERT_ERR_TOG(v)    (HW_PCIE_PHY_RX_LBERT_ERR_WR(HW_PCIE_PHY_RX_LBERT_ERR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_LBERT_ERR bitfields
 */

/* --- Register HW_PCIE_PHY_RX_LBERT_ERR, field COUNT (RW)
 *
 * A read of this register, or a sync of the PM resets the error count. Current error count If OV14
 * field is active, then multiply count by 128
 */

#define BP_PCIE_PHY_RX_LBERT_ERR_COUNT      0
#define BM_PCIE_PHY_RX_LBERT_ERR_COUNT      0x00007fff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_LBERT_ERR_COUNT(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_LBERT_ERR_COUNT)
#else
#define BF_PCIE_PHY_RX_LBERT_ERR_COUNT(v)   (((v) << 0) & BM_PCIE_PHY_RX_LBERT_ERR_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_PCIE_PHY_RX_LBERT_ERR_COUNT(v)   BF_CS1(PCIE_PHY_RX_LBERT_ERR, COUNT, v)
#endif

/* --- Register HW_PCIE_PHY_RX_LBERT_ERR, field OV14 (RW)
 *
 * If active, multiply COUNT by 128. If OV14=1 and COUNT=2^15-1, signals overflow of counter
 */

#define BP_PCIE_PHY_RX_LBERT_ERR_OV14      15
#define BM_PCIE_PHY_RX_LBERT_ERR_OV14      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_LBERT_ERR_OV14(v)   ((((reg32_t) v) << 15) & BM_PCIE_PHY_RX_LBERT_ERR_OV14)
#else
#define BF_PCIE_PHY_RX_LBERT_ERR_OV14(v)   (((v) << 15) & BM_PCIE_PHY_RX_LBERT_ERR_OV14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OV14 field to a new value.
#define BW_PCIE_PHY_RX_LBERT_ERR_OV14(v)   BF_CS1(PCIE_PHY_RX_LBERT_ERR, OV14, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_SCOPE_CTL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MODE : 3; //!< Sampling mode of counters. WORD is 20 bits.
        unsigned short RESERVED0 : 13; //!< Reserved
    } B;
} hw_pcie_phy_rx_scope_ctl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_SCOPE_CTL register
 */
#define HW_PCIE_PHY_RX_SCOPE_CTL_ADDR      (REGS_PCIE_PHY_BASE + 0x1018)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_SCOPE_CTL           (*(volatile hw_pcie_phy_rx_scope_ctl_t *) HW_PCIE_PHY_RX_SCOPE_CTL_ADDR)
#define HW_PCIE_PHY_RX_SCOPE_CTL_RD()      (HW_PCIE_PHY_RX_SCOPE_CTL.U)
#define HW_PCIE_PHY_RX_SCOPE_CTL_WR(v)     (HW_PCIE_PHY_RX_SCOPE_CTL.U = (v))
#define HW_PCIE_PHY_RX_SCOPE_CTL_SET(v)    (HW_PCIE_PHY_RX_SCOPE_CTL_WR(HW_PCIE_PHY_RX_SCOPE_CTL_RD() |  (v)))
#define HW_PCIE_PHY_RX_SCOPE_CTL_CLR(v)    (HW_PCIE_PHY_RX_SCOPE_CTL_WR(HW_PCIE_PHY_RX_SCOPE_CTL_RD() & ~(v)))
#define HW_PCIE_PHY_RX_SCOPE_CTL_TOG(v)    (HW_PCIE_PHY_RX_SCOPE_CTL_WR(HW_PCIE_PHY_RX_SCOPE_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_SCOPE_CTL bitfields
 */

/* --- Register HW_PCIE_PHY_RX_SCOPE_CTL, field MODE (RW)
 *
 * Sampling mode of counters. WORD is 20 bits.
 *
 * Values:
 * 0 - Off
 * 1 - Sample data every WORD *(1 + DELAY) bits
 * 2 - Sample data every WORD *(1 + DELAY) + 1 bits
 * 3 - Sample data every WORD *(1 + DELAY) + 2 bits
 * 4 - Sample data every clk and assert XOR and MASK increment
 */

#define BP_PCIE_PHY_RX_SCOPE_CTL_MODE      0
#define BM_PCIE_PHY_RX_SCOPE_CTL_MODE      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_CTL_MODE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_SCOPE_CTL_MODE)
#else
#define BF_PCIE_PHY_RX_SCOPE_CTL_MODE(v)   (((v) << 0) & BM_PCIE_PHY_RX_SCOPE_CTL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_CTL_MODE(v)   BF_CS1(PCIE_PHY_RX_SCOPE_CTL, MODE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_SCOPE_PHASE -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short SAMPLE_PHASE : 6; //!< Sampling Phase
        unsigned short UPDATE : 1; //!< Update Sampling phase. Write a 1.
        unsigned short SCOPE_SEL : 1; //!< Select sampling mode.
        unsigned short SCOPE_DELAY : 2; //!< How many clocks to delay the analog scope_data.
        unsigned short BASE : 5; //!< which bit to sample when MODE = 1 or 4
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_pcie_phy_rx_scope_phase_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_SCOPE_PHASE register
 */
#define HW_PCIE_PHY_RX_SCOPE_PHASE_ADDR      (REGS_PCIE_PHY_BASE + 0x1019)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_SCOPE_PHASE           (*(volatile hw_pcie_phy_rx_scope_phase_t *) HW_PCIE_PHY_RX_SCOPE_PHASE_ADDR)
#define HW_PCIE_PHY_RX_SCOPE_PHASE_RD()      (HW_PCIE_PHY_RX_SCOPE_PHASE.U)
#define HW_PCIE_PHY_RX_SCOPE_PHASE_WR(v)     (HW_PCIE_PHY_RX_SCOPE_PHASE.U = (v))
#define HW_PCIE_PHY_RX_SCOPE_PHASE_SET(v)    (HW_PCIE_PHY_RX_SCOPE_PHASE_WR(HW_PCIE_PHY_RX_SCOPE_PHASE_RD() |  (v)))
#define HW_PCIE_PHY_RX_SCOPE_PHASE_CLR(v)    (HW_PCIE_PHY_RX_SCOPE_PHASE_WR(HW_PCIE_PHY_RX_SCOPE_PHASE_RD() & ~(v)))
#define HW_PCIE_PHY_RX_SCOPE_PHASE_TOG(v)    (HW_PCIE_PHY_RX_SCOPE_PHASE_WR(HW_PCIE_PHY_RX_SCOPE_PHASE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_SCOPE_PHASE bitfields
 */

/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field SAMPLE_PHASE (RW)
 *
 * Sampling Phase
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE      0
#define BM_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE)
#else
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE(v)   (((v) << 0) & BM_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SAMPLE_PHASE field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE(v)   BF_CS1(PCIE_PHY_RX_SCOPE_PHASE, SAMPLE_PHASE, v)
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field UPDATE (RW)
 *
 * Update Sampling phase. Write a 1.
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_UPDATE      6
#define BM_PCIE_PHY_RX_SCOPE_PHASE_UPDATE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_PHASE_UPDATE(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_SCOPE_PHASE_UPDATE)
#else
#define BF_PCIE_PHY_RX_SCOPE_PHASE_UPDATE(v)   (((v) << 6) & BM_PCIE_PHY_RX_SCOPE_PHASE_UPDATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UPDATE field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_UPDATE(v)   BF_CS1(PCIE_PHY_RX_SCOPE_PHASE, UPDATE, v)
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field SCOPE_SEL (RW)
 *
 * Select sampling mode.
 *
 * Values:
 * 0 - Before AFE sampling
 * 1 - After AFE sampling
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL      7
#define BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL)
#else
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL(v)   (((v) << 7) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_SEL field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL(v)   BF_CS1(PCIE_PHY_RX_SCOPE_PHASE, SCOPE_SEL, v)
#endif


/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field SCOPE_DELAY (RW)
 *
 * How many clocks to delay the analog scope_data.
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY      8
#define BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY)
#else
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY(v)   (((v) << 8) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_DELAY field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY(v)   BF_CS1(PCIE_PHY_RX_SCOPE_PHASE, SCOPE_DELAY, v)
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field BASE (RW)
 *
 * which bit to sample when MODE = 1 or 4
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_BASE      10
#define BM_PCIE_PHY_RX_SCOPE_PHASE_BASE      0x00007c00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_PHASE_BASE(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_RX_SCOPE_PHASE_BASE)
#else
#define BF_PCIE_PHY_RX_SCOPE_PHASE_BASE(v)   (((v) << 10) & BM_PCIE_PHY_RX_SCOPE_PHASE_BASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BASE field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_BASE(v)   BF_CS1(PCIE_PHY_RX_SCOPE_PHASE, BASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_DPLL_FREQ -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DTHR : 1; //!< Bits below the useful resolution
        unsigned short VAL : 12; //!< Freq is 1.526*VAL ppm from the reference When mpll_slow is set, the ppm is half the eqn above
        unsigned short RESERVED0 : 3; //!< Reserved
    } B;
} hw_pcie_phy_rx_dpll_freq_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_DPLL_FREQ register
 */
#define HW_PCIE_PHY_RX_DPLL_FREQ_ADDR      (REGS_PCIE_PHY_BASE + 0x101a)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_DPLL_FREQ           (*(volatile hw_pcie_phy_rx_dpll_freq_t *) HW_PCIE_PHY_RX_DPLL_FREQ_ADDR)
#define HW_PCIE_PHY_RX_DPLL_FREQ_RD()      (HW_PCIE_PHY_RX_DPLL_FREQ.U)
#define HW_PCIE_PHY_RX_DPLL_FREQ_WR(v)     (HW_PCIE_PHY_RX_DPLL_FREQ.U = (v))
#define HW_PCIE_PHY_RX_DPLL_FREQ_SET(v)    (HW_PCIE_PHY_RX_DPLL_FREQ_WR(HW_PCIE_PHY_RX_DPLL_FREQ_RD() |  (v)))
#define HW_PCIE_PHY_RX_DPLL_FREQ_CLR(v)    (HW_PCIE_PHY_RX_DPLL_FREQ_WR(HW_PCIE_PHY_RX_DPLL_FREQ_RD() & ~(v)))
#define HW_PCIE_PHY_RX_DPLL_FREQ_TOG(v)    (HW_PCIE_PHY_RX_DPLL_FREQ_WR(HW_PCIE_PHY_RX_DPLL_FREQ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_DPLL_FREQ bitfields
 */

/* --- Register HW_PCIE_PHY_RX_DPLL_FREQ, field DTHR (RW)
 *
 * Bits below the useful resolution
 */

#define BP_PCIE_PHY_RX_DPLL_FREQ_DTHR      0
#define BM_PCIE_PHY_RX_DPLL_FREQ_DTHR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_DPLL_FREQ_DTHR(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_DPLL_FREQ_DTHR)
#else
#define BF_PCIE_PHY_RX_DPLL_FREQ_DTHR(v)   (((v) << 0) & BM_PCIE_PHY_RX_DPLL_FREQ_DTHR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTHR field to a new value.
#define BW_PCIE_PHY_RX_DPLL_FREQ_DTHR(v)   BF_CS1(PCIE_PHY_RX_DPLL_FREQ, DTHR, v)
#endif

/* --- Register HW_PCIE_PHY_RX_DPLL_FREQ, field VAL (RW)
 *
 * Freq is 1.526*VAL ppm from the reference When mpll_slow is set, the ppm is half the eqn above
 */

#define BP_PCIE_PHY_RX_DPLL_FREQ_VAL      1
#define BM_PCIE_PHY_RX_DPLL_FREQ_VAL      0x00001ffe

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_DPLL_FREQ_VAL(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RX_DPLL_FREQ_VAL)
#else
#define BF_PCIE_PHY_RX_DPLL_FREQ_VAL(v)   (((v) << 1) & BM_PCIE_PHY_RX_DPLL_FREQ_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VAL field to a new value.
#define BW_PCIE_PHY_RX_DPLL_FREQ_VAL(v)   BF_CS1(PCIE_PHY_RX_DPLL_FREQ, VAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_CTL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short PHDET_EN : 2; //!< Enables phase detecter. top bit is odd slicers, bottom is even
        unsigned short PHDET_EDGE : 2; //!< Edges to use for phase detection.
        unsigned short PHDET_POL : 1; //!< Reverse polarity of phase error
        unsigned short OVRD_DPLL_GAIN : 1; //!< Override PHUG and FRUG values
        unsigned short PHUG_VALUE : 2; //!< override value for PHUG
        unsigned short FRUG_VALUE : 2; //!< override value for FRUG
        unsigned short FAST_START : 1; //!< decrease startup steps by 50%
        unsigned short ALWAYS_REALIGN : 1; //!< realign on any misaligned comma
        unsigned short DTB_SEL : 4; //!< Select to drive various signals onto the DTB.
    } B;
} hw_pcie_phy_rx_cdr_ctl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_CDR_CTL register
 */
#define HW_PCIE_PHY_RX_CDR_CTL_ADDR      (REGS_PCIE_PHY_BASE + 0x101b)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_CDR_CTL           (*(volatile hw_pcie_phy_rx_cdr_ctl_t *) HW_PCIE_PHY_RX_CDR_CTL_ADDR)
#define HW_PCIE_PHY_RX_CDR_CTL_RD()      (HW_PCIE_PHY_RX_CDR_CTL.U)
#define HW_PCIE_PHY_RX_CDR_CTL_WR(v)     (HW_PCIE_PHY_RX_CDR_CTL.U = (v))
#define HW_PCIE_PHY_RX_CDR_CTL_SET(v)    (HW_PCIE_PHY_RX_CDR_CTL_WR(HW_PCIE_PHY_RX_CDR_CTL_RD() |  (v)))
#define HW_PCIE_PHY_RX_CDR_CTL_CLR(v)    (HW_PCIE_PHY_RX_CDR_CTL_WR(HW_PCIE_PHY_RX_CDR_CTL_RD() & ~(v)))
#define HW_PCIE_PHY_RX_CDR_CTL_TOG(v)    (HW_PCIE_PHY_RX_CDR_CTL_WR(HW_PCIE_PHY_RX_CDR_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_CDR_CTL bitfields
 */

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field PHDET_EN (RW)
 *
 * Enables phase detecter. top bit is odd slicers, bottom is even
 */

#define BP_PCIE_PHY_RX_CDR_CTL_PHDET_EN      0
#define BM_PCIE_PHY_RX_CDR_CTL_PHDET_EN      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_EN(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EN)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_EN(v)   (((v) << 0) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_EN field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_PHDET_EN(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, PHDET_EN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field PHDET_EDGE (RW)
 *
 * Edges to use for phase detection.
 *
 * Values:
 * 11 - Use both edges
 * 10 - Use rising edges only
 * 01 - Use falling edges only
 * 00 - Ignore all edges
 */

#define BP_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE      2
#define BM_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE(v)   (((v) << 2) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_EDGE field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, PHDET_EDGE, v)
#endif


/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field PHDET_POL (RW)
 *
 * Reverse polarity of phase error
 */

#define BP_PCIE_PHY_RX_CDR_CTL_PHDET_POL      4
#define BM_PCIE_PHY_RX_CDR_CTL_PHDET_POL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_POL(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_POL)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_POL(v)   (((v) << 4) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_POL field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_PHDET_POL(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, PHDET_POL, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field OVRD_DPLL_GAIN (RW)
 *
 * Override PHUG and FRUG values
 */

#define BP_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN      5
#define BM_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN(v)   (((v) << 5) & BM_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_DPLL_GAIN field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, OVRD_DPLL_GAIN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field PHUG_VALUE (RW)
 *
 * override value for PHUG
 */

#define BP_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE      6
#define BM_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE(v)   (((v) << 6) & BM_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHUG_VALUE field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, PHUG_VALUE, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field FRUG_VALUE (RW)
 *
 * override value for FRUG
 */

#define BP_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE      8
#define BM_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE(v)   (((v) << 8) & BM_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRUG_VALUE field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, FRUG_VALUE, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field FAST_START (RW)
 *
 * decrease startup steps by 50%
 */

#define BP_PCIE_PHY_RX_CDR_CTL_FAST_START      10
#define BM_PCIE_PHY_RX_CDR_CTL_FAST_START      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_FAST_START(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_RX_CDR_CTL_FAST_START)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_FAST_START(v)   (((v) << 10) & BM_PCIE_PHY_RX_CDR_CTL_FAST_START)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FAST_START field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_FAST_START(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, FAST_START, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field ALWAYS_REALIGN (RW)
 *
 * realign on any misaligned comma
 */

#define BP_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN      11
#define BM_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN(v)   ((((reg32_t) v) << 11) & BM_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN(v)   (((v) << 11) & BM_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALWAYS_REALIGN field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, ALWAYS_REALIGN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field DTB_SEL (RW)
 *
 * Select to drive various signals onto the DTB.
 *
 * Values:
 * 0 - disabled
 * 1 - pll_ana_rst,pll_count from rx_pwr_ctl
 * 2 - com_good_high/low from aligner
 * 3 - com_bad_high/low from aligner
 * 4 - shift_in_prog,ana_odd_data from aligner
 * 5 - Low bits of XAUI align FSM state
 */

#define BP_PCIE_PHY_RX_CDR_CTL_DTB_SEL      12
#define BM_PCIE_PHY_RX_CDR_CTL_DTB_SEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_CTL_DTB_SEL(v)   ((((reg32_t) v) << 12) & BM_PCIE_PHY_RX_CDR_CTL_DTB_SEL)
#else
#define BF_PCIE_PHY_RX_CDR_CTL_DTB_SEL(v)   (((v) << 12) & BM_PCIE_PHY_RX_CDR_CTL_DTB_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_DTB_SEL(v)   BF_CS1(PCIE_PHY_RX_CDR_CTL, DTB_SEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CDR_EN : 1; //!< CDR has been enabled.
        unsigned short CDR_TIMEOUT : 1; //!< CDR has not locked to datastream and has timed-out.
        unsigned short CDR_RX_VALID : 1; //!< CDR has locked to incoming data stream.
        unsigned short ALIGNED : 1; //!< Datapath is bit-aligned.
        unsigned short CDR_EN_EQ : 1; //!< Equalization loop is enabling the CDR.
        unsigned short CDR_EN_ADAP : 1; //!< Adapatation loop is enabling the CDR.
        unsigned short ADAP_RX_VALID : 1; //!< Adaptation has completed and locked
        unsigned short RX_ANA_EQ : 3; //!< Equalization setting to Analog.
        unsigned short RX_EQ_CTR : 3; //!< Initial centre point from equalization FSM.
        unsigned short ADAP_RX_EQ : 3; //!< Equalization setting from adaptation FSM.
    } B;
} hw_pcie_phy_rx_cdr_cdr_fsm_debug_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_CDR_CDR_FSM_DEBUG register
 */
#define HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADDR      (REGS_PCIE_PHY_BASE + 0x101c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG           (*(volatile hw_pcie_phy_rx_cdr_cdr_fsm_debug_t *) HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADDR)
#define HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RD()      (HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_CDR_CDR_FSM_DEBUG bitfields
 */

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_EN (RO)
 *
 * CDR has been enabled.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN      0
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN      0x00000001

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_TIMEOUT (RO)
 *
 * CDR has not locked to datastream and has timed-out.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT      1
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT      0x00000002

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_RX_VALID (RO)
 *
 * CDR has locked to incoming data stream.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID      2
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID      0x00000004

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field ALIGNED (RO)
 *
 * Datapath is bit-aligned.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED      3
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED      0x00000008

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_EN_EQ (RO)
 *
 * Equalization loop is enabling the CDR.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ      4
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ      0x00000010

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_EN_ADAP (RO)
 *
 * Adapatation loop is enabling the CDR.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP      5
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP      0x00000020

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field ADAP_RX_VALID (RO)
 *
 * Adaptation has completed and locked
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID      6
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID      0x00000040

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field RX_ANA_EQ (RO)
 *
 * Equalization setting to Analog.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ      7
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ      0x00000380

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field RX_EQ_CTR (RO)
 *
 * Initial centre point from equalization FSM.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR      10
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR      0x00001c00

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field ADAP_RX_EQ (RO)
 *
 * Equalization setting from adaptation FSM.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ      13
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ      0x0000e000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short LOCK_VECTOR : 8; //!< Override value for the locked_vector.
        unsigned short LOCK_VECTOR_EN : 1; //!< Override value for the locked_vector output completion.
        unsigned short LOCK_VECTOR_OVRD : 1; //!< Override enable for the rx_eq outputs.
        unsigned short ADAP_POLARITY : 1; //!< If asserted invert default adaptation adjustment for equalization. IF early decrease equalization. Normal mode is to decrease.
        unsigned short ADAP_CTR_LEVEL : 5; //!< Amount of earlies that increment the adaptation counter (times 16).
    } B;
} hw_pcie_phy_rx_cdr_lock_vec_ovrd_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_CDR_LOCK_VEC_OVRD register
 */
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADDR      (REGS_PCIE_PHY_BASE + 0x101d)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD           (*(volatile hw_pcie_phy_rx_cdr_lock_vec_ovrd_t *) HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADDR)
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD()      (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD.U)
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR(v)     (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD.U = (v))
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_SET(v)    (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR(HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD() |  (v)))
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_CLR(v)    (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR(HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD() & ~(v)))
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_TOG(v)    (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR(HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_CDR_LOCK_VEC_OVRD bitfields
 */

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field LOCK_VECTOR (RW)
 *
 * Override value for the locked_vector.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR      0
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR)
#else
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR(v)   (((v) << 0) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_VECTOR field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR(v)   BF_CS1(PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, LOCK_VECTOR, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field LOCK_VECTOR_EN (RW)
 *
 * Override value for the locked_vector output completion.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN      8
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN(v)   ((((reg32_t) v) << 8) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN)
#else
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN(v)   (((v) << 8) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_VECTOR_EN field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN(v)   BF_CS1(PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, LOCK_VECTOR_EN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field LOCK_VECTOR_OVRD (RW)
 *
 * Override enable for the rx_eq outputs.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD      9
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD(v)   ((((reg32_t) v) << 9) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD)
#else
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD(v)   (((v) << 9) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_VECTOR_OVRD field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD(v)   BF_CS1(PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, LOCK_VECTOR_OVRD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field ADAP_POLARITY (RW)
 *
 * If asserted invert default adaptation adjustment for equalization. IF early decrease
 * equalization. Normal mode is to decrease.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY      10
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY(v)   ((((reg32_t) v) << 10) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY)
#else
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY(v)   (((v) << 10) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADAP_POLARITY field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY(v)   BF_CS1(PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, ADAP_POLARITY, v)
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field ADAP_CTR_LEVEL (RW)
 *
 * Amount of earlies that increment the adaptation counter (times 16).
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL      11
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL      0x0000f800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL(v)   ((((reg32_t) v) << 11) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL)
#else
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL(v)   (((v) << 11) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADAP_CTR_LEVEL field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL(v)   BF_CS1(PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, ADAP_CTR_LEVEL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_LOCK_VEC -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short EQ_LOCKED_VECTOR : 8; //!< Results of equalization loop.
        unsigned short EQ_LOCKED_VECTOR_EN : 1; //!< Equalization locked vector has been filled.
        unsigned short EQ_RX_EQ : 3; //!< Equalization setting from the Equalization Loop.
        unsigned short RESERVED0 : 4; //!< Reserved
    } B;
} hw_pcie_phy_rx_cdr_lock_vec_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_CDR_LOCK_VEC register
 */
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_ADDR      (REGS_PCIE_PHY_BASE + 0x101e)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC           (*(volatile hw_pcie_phy_rx_cdr_lock_vec_t *) HW_PCIE_PHY_RX_CDR_LOCK_VEC_ADDR)
#define HW_PCIE_PHY_RX_CDR_LOCK_VEC_RD()      (HW_PCIE_PHY_RX_CDR_LOCK_VEC.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_CDR_LOCK_VEC bitfields
 */

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC, field EQ_LOCKED_VECTOR (RO)
 *
 * Results of equalization loop.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR      0
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR      0x000000ff

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC, field EQ_LOCKED_VECTOR_EN (RO)
 *
 * Equalization locked vector has been filled.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN      8
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN      0x00000100

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC, field EQ_RX_EQ (RO)
 *
 * Equalization setting from the Equalization Loop.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ      9
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ      0x00000e00

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_ADAP_FSM -  (RO)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ADAP_STATE : 3; //!< Adaptation State.
        unsigned short ADAP_CTR : 4; //!< Adaptation count register.
        unsigned short LOOP_CTR : 4; //!< Loop count register.
        unsigned short MSTR_CTR : 5; //!< Master count register.
    } B;
} hw_pcie_phy_rx_cdr_adap_fsm_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_CDR_ADAP_FSM register
 */
#define HW_PCIE_PHY_RX_CDR_ADAP_FSM_ADDR      (REGS_PCIE_PHY_BASE + 0x101f)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_CDR_ADAP_FSM           (*(volatile hw_pcie_phy_rx_cdr_adap_fsm_t *) HW_PCIE_PHY_RX_CDR_ADAP_FSM_ADDR)
#define HW_PCIE_PHY_RX_CDR_ADAP_FSM_RD()      (HW_PCIE_PHY_RX_CDR_ADAP_FSM.U)
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_CDR_ADAP_FSM bitfields
 */

/* --- Register HW_PCIE_PHY_RX_CDR_ADAP_FSM, field ADAP_STATE (RO)
 *
 * Adaptation State.
 *
 * Values:
 * 000 - ADAP_RESET
 * 001 - ADAP_LOCK
 * 010 - ADAP_SUFF
 * 011 - ADAP_LOOP
 * 100 - ADAP_MSTR
 * 101 - ADAP_DONE
 */

#define BP_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE      0
#define BM_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE      0x00000007


/* --- Register HW_PCIE_PHY_RX_CDR_ADAP_FSM, field ADAP_CTR (RO)
 *
 * Adaptation count register.
 */

#define BP_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR      3
#define BM_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR      0x00000078

/* --- Register HW_PCIE_PHY_RX_CDR_ADAP_FSM, field LOOP_CTR (RO)
 *
 * Loop count register.
 */

#define BP_PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR      7
#define BM_PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR      0x00000780

/* --- Register HW_PCIE_PHY_RX_CDR_ADAP_FSM, field MSTR_CTR (RO)
 *
 * Master count register.
 */

#define BP_PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR      11
#define BM_PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR      0x0000f800

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ATB0 -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short EN_ATB_VOFF : 1; //!< Puts rxafe voff_p on atb_s_p and voff_m on atb_s_m.
        unsigned short EN_ATB_RP_S : 1; //!< Puts rxafe outputs vo_p on atb_s_p and vo_m on atb_s_m.
        unsigned short EN_ATB_RP_F : 1; //!< Enables atb_sense_p on positive-side termination resistor.
        unsigned short EN_ATB_RM_S : 1; //!< Enables atb_force_p on positive-side termination resistor.
        unsigned short EN_ATB_RM_F : 1; //!< Enables atb_sense_m on negative-side termination resistor.
        unsigned short EN_MARG : 1; //!< Enables atb_force_p on negative-side termination resistor.
        unsigned short EN_ATB : 1; //!< Enables margining mode in receiver; requires atb_f_m to be high-Z!.
        unsigned short EN_ATB1 : 1; //!< Enables ATB sensing and forcing on internal Rx nodes.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_rx_atb0_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_ATB0 register
 */
#define HW_PCIE_PHY_RX_ATB0_ADDR      (REGS_PCIE_PHY_BASE + 0x1020)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_ATB0           (*(volatile hw_pcie_phy_rx_atb0_t *) HW_PCIE_PHY_RX_ATB0_ADDR)
#define HW_PCIE_PHY_RX_ATB0_RD()      (HW_PCIE_PHY_RX_ATB0.U)
#define HW_PCIE_PHY_RX_ATB0_WR(v)     (HW_PCIE_PHY_RX_ATB0.U = (v))
#define HW_PCIE_PHY_RX_ATB0_SET(v)    (HW_PCIE_PHY_RX_ATB0_WR(HW_PCIE_PHY_RX_ATB0_RD() |  (v)))
#define HW_PCIE_PHY_RX_ATB0_CLR(v)    (HW_PCIE_PHY_RX_ATB0_WR(HW_PCIE_PHY_RX_ATB0_RD() & ~(v)))
#define HW_PCIE_PHY_RX_ATB0_TOG(v)    (HW_PCIE_PHY_RX_ATB0_WR(HW_PCIE_PHY_RX_ATB0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_ATB0 bitfields
 */

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_VOFF (RW)
 *
 * Puts rxafe voff_p on atb_s_p and voff_m on atb_s_m.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_VOFF      0
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_VOFF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_VOFF(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_ATB0_EN_ATB_VOFF)
#else
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_VOFF(v)   (((v) << 0) & BM_PCIE_PHY_RX_ATB0_EN_ATB_VOFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_VOFF field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_VOFF(v)   BF_CS1(PCIE_PHY_RX_ATB0, EN_ATB_VOFF, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_RP_S (RW)
 *
 * Puts rxafe outputs vo_p on atb_s_p and vo_m on atb_s_m.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_S      1
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_S      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_S(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_S)
#else
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_S(v)   (((v) << 1) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_S)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_RP_S field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_RP_S(v)   BF_CS1(PCIE_PHY_RX_ATB0, EN_ATB_RP_S, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_RP_F (RW)
 *
 * Enables atb_sense_p on positive-side termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_F      2
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_F      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_F(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_F)
#else
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_F(v)   (((v) << 2) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_F)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_RP_F field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_RP_F(v)   BF_CS1(PCIE_PHY_RX_ATB0, EN_ATB_RP_F, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_RM_S (RW)
 *
 * Enables atb_force_p on positive-side termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_S      3
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_S      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_S(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_S)
#else
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_S(v)   (((v) << 3) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_S)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_RM_S field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_RM_S(v)   BF_CS1(PCIE_PHY_RX_ATB0, EN_ATB_RM_S, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_RM_F (RW)
 *
 * Enables atb_sense_m on negative-side termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_F      4
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_F      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_F(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_F)
#else
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_F(v)   (((v) << 4) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_F)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_RM_F field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_RM_F(v)   BF_CS1(PCIE_PHY_RX_ATB0, EN_ATB_RM_F, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_MARG (RW)
 *
 * Enables atb_force_p on negative-side termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_MARG      5
#define BM_PCIE_PHY_RX_ATB0_EN_MARG      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB0_EN_MARG(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_ATB0_EN_MARG)
#else
#define BF_PCIE_PHY_RX_ATB0_EN_MARG(v)   (((v) << 5) & BM_PCIE_PHY_RX_ATB0_EN_MARG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_MARG field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_MARG(v)   BF_CS1(PCIE_PHY_RX_ATB0, EN_MARG, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB (RW)
 *
 * Enables margining mode in receiver; requires atb_f_m to be high-Z!.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB      6
#define BM_PCIE_PHY_RX_ATB0_EN_ATB      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB0_EN_ATB(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_ATB0_EN_ATB)
#else
#define BF_PCIE_PHY_RX_ATB0_EN_ATB(v)   (((v) << 6) & BM_PCIE_PHY_RX_ATB0_EN_ATB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB(v)   BF_CS1(PCIE_PHY_RX_ATB0, EN_ATB, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB (RW)
 *
 * Enables ATB sensing and forcing on internal Rx nodes.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB      7
#define BM_PCIE_PHY_RX_ATB0_EN_ATB      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB0_EN_ATB(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RX_ATB0_EN_ATB)
#else
#define BF_PCIE_PHY_RX_ATB0_EN_ATB(v)   (((v) << 7) & BM_PCIE_PHY_RX_ATB0_EN_ATB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB(v)   BF_CS1(PCIE_PHY_RX_ATB0, EN_ATB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ATB1 -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short NC0 : 1; //!< Enables/disables Rx termination resistor.
        unsigned short EN_VLOS_USB3 : 1; //!< Enables LOS levels to be those for USB3; otherwise, PCI Express levels.
        unsigned short MEAS_VP : 1; //!< Enables sensing of local vp in Rx; ties vp to atb_sense_p.
        unsigned short MEAS_GD : 1; //!< Enables sensing of local gd in Rx; ties gd to atb_sense_m.
        unsigned short EN_ATB_VRF : 1; //!< Enables sensing of vref_rx on atb_sense_p.
        unsigned short EN_ATB_VLOS : 1; //!< Enables sensing of LOS reference voltage on atb_sense_p.
        unsigned short VLOS_MIN : 1; //!< Sets LOS reference voltage. (VLOS_MAX, VLOS_MIN): (1,1): None (1,0): Maximum (0,1): Minimum (0,0): Nominal
        unsigned short VLOS_MAX : 1; //!< Sets LOS reference voltage. (VLOS_MAX, VLOS_MIN): (1,1): None (1,0): Maximum (0,1): Minimum (0,0): Nominal
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_rx_atb1_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_ATB1 register
 */
#define HW_PCIE_PHY_RX_ATB1_ADDR      (REGS_PCIE_PHY_BASE + 0x1021)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_ATB1           (*(volatile hw_pcie_phy_rx_atb1_t *) HW_PCIE_PHY_RX_ATB1_ADDR)
#define HW_PCIE_PHY_RX_ATB1_RD()      (HW_PCIE_PHY_RX_ATB1.U)
#define HW_PCIE_PHY_RX_ATB1_WR(v)     (HW_PCIE_PHY_RX_ATB1.U = (v))
#define HW_PCIE_PHY_RX_ATB1_SET(v)    (HW_PCIE_PHY_RX_ATB1_WR(HW_PCIE_PHY_RX_ATB1_RD() |  (v)))
#define HW_PCIE_PHY_RX_ATB1_CLR(v)    (HW_PCIE_PHY_RX_ATB1_WR(HW_PCIE_PHY_RX_ATB1_RD() & ~(v)))
#define HW_PCIE_PHY_RX_ATB1_TOG(v)    (HW_PCIE_PHY_RX_ATB1_WR(HW_PCIE_PHY_RX_ATB1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_ATB1 bitfields
 */

/* --- Register HW_PCIE_PHY_RX_ATB1, field NC0 (RW)
 *
 * Enables/disables Rx termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB1_NC0      0
#define BM_PCIE_PHY_RX_ATB1_NC0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB1_NC0(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_ATB1_NC0)
#else
#define BF_PCIE_PHY_RX_ATB1_NC0(v)   (((v) << 0) & BM_PCIE_PHY_RX_ATB1_NC0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NC0 field to a new value.
#define BW_PCIE_PHY_RX_ATB1_NC0(v)   BF_CS1(PCIE_PHY_RX_ATB1, NC0, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field EN_VLOS_USB3 (RW)
 *
 * Enables LOS levels to be those for USB3; otherwise, PCI Express levels.
 */

#define BP_PCIE_PHY_RX_ATB1_EN_VLOS_USB3      1
#define BM_PCIE_PHY_RX_ATB1_EN_VLOS_USB3      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB1_EN_VLOS_USB3(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RX_ATB1_EN_VLOS_USB3)
#else
#define BF_PCIE_PHY_RX_ATB1_EN_VLOS_USB3(v)   (((v) << 1) & BM_PCIE_PHY_RX_ATB1_EN_VLOS_USB3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_VLOS_USB3 field to a new value.
#define BW_PCIE_PHY_RX_ATB1_EN_VLOS_USB3(v)   BF_CS1(PCIE_PHY_RX_ATB1, EN_VLOS_USB3, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field MEAS_VP (RW)
 *
 * Enables sensing of local vp in Rx; ties vp to atb_sense_p.
 */

#define BP_PCIE_PHY_RX_ATB1_MEAS_VP      2
#define BM_PCIE_PHY_RX_ATB1_MEAS_VP      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB1_MEAS_VP(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_ATB1_MEAS_VP)
#else
#define BF_PCIE_PHY_RX_ATB1_MEAS_VP(v)   (((v) << 2) & BM_PCIE_PHY_RX_ATB1_MEAS_VP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_VP field to a new value.
#define BW_PCIE_PHY_RX_ATB1_MEAS_VP(v)   BF_CS1(PCIE_PHY_RX_ATB1, MEAS_VP, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field MEAS_GD (RW)
 *
 * Enables sensing of local gd in Rx; ties gd to atb_sense_m.
 */

#define BP_PCIE_PHY_RX_ATB1_MEAS_GD      3
#define BM_PCIE_PHY_RX_ATB1_MEAS_GD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB1_MEAS_GD(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_ATB1_MEAS_GD)
#else
#define BF_PCIE_PHY_RX_ATB1_MEAS_GD(v)   (((v) << 3) & BM_PCIE_PHY_RX_ATB1_MEAS_GD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_GD field to a new value.
#define BW_PCIE_PHY_RX_ATB1_MEAS_GD(v)   BF_CS1(PCIE_PHY_RX_ATB1, MEAS_GD, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field EN_ATB_VRF (RW)
 *
 * Enables sensing of vref_rx on atb_sense_p.
 */

#define BP_PCIE_PHY_RX_ATB1_EN_ATB_VRF      4
#define BM_PCIE_PHY_RX_ATB1_EN_ATB_VRF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB1_EN_ATB_VRF(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VRF)
#else
#define BF_PCIE_PHY_RX_ATB1_EN_ATB_VRF(v)   (((v) << 4) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VRF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_VRF field to a new value.
#define BW_PCIE_PHY_RX_ATB1_EN_ATB_VRF(v)   BF_CS1(PCIE_PHY_RX_ATB1, EN_ATB_VRF, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field EN_ATB_VLOS (RW)
 *
 * Enables sensing of LOS reference voltage on atb_sense_p.
 */

#define BP_PCIE_PHY_RX_ATB1_EN_ATB_VLOS      5
#define BM_PCIE_PHY_RX_ATB1_EN_ATB_VLOS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB1_EN_ATB_VLOS(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VLOS)
#else
#define BF_PCIE_PHY_RX_ATB1_EN_ATB_VLOS(v)   (((v) << 5) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VLOS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_VLOS field to a new value.
#define BW_PCIE_PHY_RX_ATB1_EN_ATB_VLOS(v)   BF_CS1(PCIE_PHY_RX_ATB1, EN_ATB_VLOS, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field VLOS_MIN (RW)
 *
 * Sets LOS reference voltage. (VLOS_MAX, VLOS_MIN): (1,1): None (1,0): Maximum (0,1): Minimum
 * (0,0): Nominal
 */

#define BP_PCIE_PHY_RX_ATB1_VLOS_MIN      6
#define BM_PCIE_PHY_RX_ATB1_VLOS_MIN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB1_VLOS_MIN(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_ATB1_VLOS_MIN)
#else
#define BF_PCIE_PHY_RX_ATB1_VLOS_MIN(v)   (((v) << 6) & BM_PCIE_PHY_RX_ATB1_VLOS_MIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VLOS_MIN field to a new value.
#define BW_PCIE_PHY_RX_ATB1_VLOS_MIN(v)   BF_CS1(PCIE_PHY_RX_ATB1, VLOS_MIN, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field VLOS_MAX (RW)
 *
 * Sets LOS reference voltage. (VLOS_MAX, VLOS_MIN): (1,1): None (1,0): Maximum (0,1): Minimum
 * (0,0): Nominal
 */

#define BP_PCIE_PHY_RX_ATB1_VLOS_MAX      7
#define BM_PCIE_PHY_RX_ATB1_VLOS_MAX      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ATB1_VLOS_MAX(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RX_ATB1_VLOS_MAX)
#else
#define BF_PCIE_PHY_RX_ATB1_VLOS_MAX(v)   (((v) << 7) & BM_PCIE_PHY_RX_ATB1_VLOS_MAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VLOS_MAX field to a new value.
#define BW_PCIE_PHY_RX_ATB1_VLOS_MAX(v)   BF_CS1(PCIE_PHY_RX_ATB1, VLOS_MAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ENPWR0 -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short LCL_ACJT : 1; //!< Enables/disables ACJTAG block.
        unsigned short CTL_ACJT : 1; //!< Enables override of ACJTAG block state.
        unsigned short LCL_RXCK : 1; //!< Enables/disables en_rx_clock (Rx clock enable).
        unsigned short CTL_RXCK : 1; //!< Enables override of Rx clock circuit state.
        unsigned short LCL_EN_LOS : 1; //!< Enables/disables LOS block.
        unsigned short CTL_EN_LOS : 1; //!< Enables override of LOS block state.
        unsigned short LCL_RXPWRON : 1; //!< Enables/disables Rx slicers.
        unsigned short CTL_RXPWRON : 1; //!< Enables override of Rx block power.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_rx_enpwr0_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_ENPWR0 register
 */
#define HW_PCIE_PHY_RX_ENPWR0_ADDR      (REGS_PCIE_PHY_BASE + 0x1022)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_ENPWR0           (*(volatile hw_pcie_phy_rx_enpwr0_t *) HW_PCIE_PHY_RX_ENPWR0_ADDR)
#define HW_PCIE_PHY_RX_ENPWR0_RD()      (HW_PCIE_PHY_RX_ENPWR0.U)
#define HW_PCIE_PHY_RX_ENPWR0_WR(v)     (HW_PCIE_PHY_RX_ENPWR0.U = (v))
#define HW_PCIE_PHY_RX_ENPWR0_SET(v)    (HW_PCIE_PHY_RX_ENPWR0_WR(HW_PCIE_PHY_RX_ENPWR0_RD() |  (v)))
#define HW_PCIE_PHY_RX_ENPWR0_CLR(v)    (HW_PCIE_PHY_RX_ENPWR0_WR(HW_PCIE_PHY_RX_ENPWR0_RD() & ~(v)))
#define HW_PCIE_PHY_RX_ENPWR0_TOG(v)    (HW_PCIE_PHY_RX_ENPWR0_WR(HW_PCIE_PHY_RX_ENPWR0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_ENPWR0 bitfields
 */

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field LCL_ACJT (RW)
 *
 * Enables/disables ACJTAG block.
 */

#define BP_PCIE_PHY_RX_ENPWR0_LCL_ACJT      0
#define BM_PCIE_PHY_RX_ENPWR0_LCL_ACJT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR0_LCL_ACJT(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_ENPWR0_LCL_ACJT)
#else
#define BF_PCIE_PHY_RX_ENPWR0_LCL_ACJT(v)   (((v) << 0) & BM_PCIE_PHY_RX_ENPWR0_LCL_ACJT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_ACJT field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_LCL_ACJT(v)   BF_CS1(PCIE_PHY_RX_ENPWR0, LCL_ACJT, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field CTL_ACJT (RW)
 *
 * Enables override of ACJTAG block state.
 */

#define BP_PCIE_PHY_RX_ENPWR0_CTL_ACJT      1
#define BM_PCIE_PHY_RX_ENPWR0_CTL_ACJT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR0_CTL_ACJT(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RX_ENPWR0_CTL_ACJT)
#else
#define BF_PCIE_PHY_RX_ENPWR0_CTL_ACJT(v)   (((v) << 1) & BM_PCIE_PHY_RX_ENPWR0_CTL_ACJT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_ACJT field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_CTL_ACJT(v)   BF_CS1(PCIE_PHY_RX_ENPWR0, CTL_ACJT, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field LCL_RXCK (RW)
 *
 * Enables/disables en_rx_clock (Rx clock enable).
 */

#define BP_PCIE_PHY_RX_ENPWR0_LCL_RXCK      2
#define BM_PCIE_PHY_RX_ENPWR0_LCL_RXCK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR0_LCL_RXCK(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXCK)
#else
#define BF_PCIE_PHY_RX_ENPWR0_LCL_RXCK(v)   (((v) << 2) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_RXCK field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_LCL_RXCK(v)   BF_CS1(PCIE_PHY_RX_ENPWR0, LCL_RXCK, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field CTL_RXCK (RW)
 *
 * Enables override of Rx clock circuit state.
 */

#define BP_PCIE_PHY_RX_ENPWR0_CTL_RXCK      3
#define BM_PCIE_PHY_RX_ENPWR0_CTL_RXCK      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR0_CTL_RXCK(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXCK)
#else
#define BF_PCIE_PHY_RX_ENPWR0_CTL_RXCK(v)   (((v) << 3) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_RXCK field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_CTL_RXCK(v)   BF_CS1(PCIE_PHY_RX_ENPWR0, CTL_RXCK, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field LCL_EN_LOS (RW)
 *
 * Enables/disables LOS block.
 */

#define BP_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS      4
#define BM_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS)
#else
#define BF_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS(v)   (((v) << 4) & BM_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_EN_LOS field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS(v)   BF_CS1(PCIE_PHY_RX_ENPWR0, LCL_EN_LOS, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field CTL_EN_LOS (RW)
 *
 * Enables override of LOS block state.
 */

#define BP_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS      5
#define BM_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS)
#else
#define BF_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS(v)   (((v) << 5) & BM_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_EN_LOS field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS(v)   BF_CS1(PCIE_PHY_RX_ENPWR0, CTL_EN_LOS, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field LCL_RXPWRON (RW)
 *
 * Enables/disables Rx slicers.
 */

#define BP_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON      6
#define BM_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON)
#else
#define BF_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON(v)   (((v) << 6) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_RXPWRON field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON(v)   BF_CS1(PCIE_PHY_RX_ENPWR0, LCL_RXPWRON, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field CTL_RXPWRON (RW)
 *
 * Enables override of Rx block power.
 */

#define BP_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON      7
#define BM_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON)
#else
#define BF_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON(v)   (((v) << 7) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_RXPWRON field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON(v)   BF_CS1(PCIE_PHY_RX_ENPWR0, CTL_RXPWRON, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_PMIX_PHASE -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short PHASE : 8; //!< Write to bits 8-1 of the Phase Select register in the phase mixer.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_rx_pmix_phase_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_PMIX_PHASE register
 */
#define HW_PCIE_PHY_RX_PMIX_PHASE_ADDR      (REGS_PCIE_PHY_BASE + 0x1023)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_PMIX_PHASE           (*(volatile hw_pcie_phy_rx_pmix_phase_t *) HW_PCIE_PHY_RX_PMIX_PHASE_ADDR)
#define HW_PCIE_PHY_RX_PMIX_PHASE_RD()      (HW_PCIE_PHY_RX_PMIX_PHASE.U)
#define HW_PCIE_PHY_RX_PMIX_PHASE_WR(v)     (HW_PCIE_PHY_RX_PMIX_PHASE.U = (v))
#define HW_PCIE_PHY_RX_PMIX_PHASE_SET(v)    (HW_PCIE_PHY_RX_PMIX_PHASE_WR(HW_PCIE_PHY_RX_PMIX_PHASE_RD() |  (v)))
#define HW_PCIE_PHY_RX_PMIX_PHASE_CLR(v)    (HW_PCIE_PHY_RX_PMIX_PHASE_WR(HW_PCIE_PHY_RX_PMIX_PHASE_RD() & ~(v)))
#define HW_PCIE_PHY_RX_PMIX_PHASE_TOG(v)    (HW_PCIE_PHY_RX_PMIX_PHASE_WR(HW_PCIE_PHY_RX_PMIX_PHASE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_PMIX_PHASE bitfields
 */

/* --- Register HW_PCIE_PHY_RX_PMIX_PHASE, field PHASE (RW)
 *
 * Write to bits 8-1 of the Phase Select register in the phase mixer.
 */

#define BP_PCIE_PHY_RX_PMIX_PHASE_PHASE      0
#define BM_PCIE_PHY_RX_PMIX_PHASE_PHASE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_PMIX_PHASE_PHASE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_PMIX_PHASE_PHASE)
#else
#define BF_PCIE_PHY_RX_PMIX_PHASE_PHASE(v)   (((v) << 0) & BM_PCIE_PHY_RX_PMIX_PHASE_PHASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHASE field to a new value.
#define BW_PCIE_PHY_RX_PMIX_PHASE_PHASE(v)   BF_CS1(PCIE_PHY_RX_PMIX_PHASE, PHASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ENPWR1 -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CTL_PHASE_REG_RST : 1; //!< Enables override of Phase register reset.
        unsigned short LCL_PHASE_REG_RST : 1; //!< Reset Phase register.
        unsigned short CTL_BST : 1; //!< Enables override of Rx boost (equalization) value.
        unsigned short LCL_BST : 3; //!< Rx boost (equalization) value
        unsigned short CTL_RXTERM : 1; //!< Enables override of rx_term_en.
        unsigned short LCL_RXTERM : 1; //!< Enables/disables Rx termination.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_rx_enpwr1_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_ENPWR1 register
 */
#define HW_PCIE_PHY_RX_ENPWR1_ADDR      (REGS_PCIE_PHY_BASE + 0x1024)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_ENPWR1           (*(volatile hw_pcie_phy_rx_enpwr1_t *) HW_PCIE_PHY_RX_ENPWR1_ADDR)
#define HW_PCIE_PHY_RX_ENPWR1_RD()      (HW_PCIE_PHY_RX_ENPWR1.U)
#define HW_PCIE_PHY_RX_ENPWR1_WR(v)     (HW_PCIE_PHY_RX_ENPWR1.U = (v))
#define HW_PCIE_PHY_RX_ENPWR1_SET(v)    (HW_PCIE_PHY_RX_ENPWR1_WR(HW_PCIE_PHY_RX_ENPWR1_RD() |  (v)))
#define HW_PCIE_PHY_RX_ENPWR1_CLR(v)    (HW_PCIE_PHY_RX_ENPWR1_WR(HW_PCIE_PHY_RX_ENPWR1_RD() & ~(v)))
#define HW_PCIE_PHY_RX_ENPWR1_TOG(v)    (HW_PCIE_PHY_RX_ENPWR1_WR(HW_PCIE_PHY_RX_ENPWR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_ENPWR1 bitfields
 */

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field CTL_PHASE_REG_RST (RW)
 *
 * Enables override of Phase register reset.
 */

#define BP_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST      0
#define BM_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST)
#else
#define BF_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST(v)   (((v) << 0) & BM_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_PHASE_REG_RST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST(v)   BF_CS1(PCIE_PHY_RX_ENPWR1, CTL_PHASE_REG_RST, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field LCL_PHASE_REG_RST (RW)
 *
 * Reset Phase register.
 */

#define BP_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST      1
#define BM_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST)
#else
#define BF_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST(v)   (((v) << 1) & BM_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_PHASE_REG_RST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST(v)   BF_CS1(PCIE_PHY_RX_ENPWR1, LCL_PHASE_REG_RST, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field CTL_BST (RW)
 *
 * Enables override of Rx boost (equalization) value.
 */

#define BP_PCIE_PHY_RX_ENPWR1_CTL_BST      2
#define BM_PCIE_PHY_RX_ENPWR1_CTL_BST      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR1_CTL_BST(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_ENPWR1_CTL_BST)
#else
#define BF_PCIE_PHY_RX_ENPWR1_CTL_BST(v)   (((v) << 2) & BM_PCIE_PHY_RX_ENPWR1_CTL_BST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_BST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_CTL_BST(v)   BF_CS1(PCIE_PHY_RX_ENPWR1, CTL_BST, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field LCL_BST (RW)
 *
 * Rx boost (equalization) value
 */

#define BP_PCIE_PHY_RX_ENPWR1_LCL_BST      3
#define BM_PCIE_PHY_RX_ENPWR1_LCL_BST      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR1_LCL_BST(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_ENPWR1_LCL_BST)
#else
#define BF_PCIE_PHY_RX_ENPWR1_LCL_BST(v)   (((v) << 3) & BM_PCIE_PHY_RX_ENPWR1_LCL_BST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_BST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_LCL_BST(v)   BF_CS1(PCIE_PHY_RX_ENPWR1, LCL_BST, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field CTL_RXTERM (RW)
 *
 * Enables override of rx_term_en.
 */

#define BP_PCIE_PHY_RX_ENPWR1_CTL_RXTERM      6
#define BM_PCIE_PHY_RX_ENPWR1_CTL_RXTERM      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR1_CTL_RXTERM(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_ENPWR1_CTL_RXTERM)
#else
#define BF_PCIE_PHY_RX_ENPWR1_CTL_RXTERM(v)   (((v) << 6) & BM_PCIE_PHY_RX_ENPWR1_CTL_RXTERM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_RXTERM field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_CTL_RXTERM(v)   BF_CS1(PCIE_PHY_RX_ENPWR1, CTL_RXTERM, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field LCL_RXTERM (RW)
 *
 * Enables/disables Rx termination.
 */

#define BP_PCIE_PHY_RX_ENPWR1_LCL_RXTERM      7
#define BM_PCIE_PHY_RX_ENPWR1_LCL_RXTERM      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR1_LCL_RXTERM(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RX_ENPWR1_LCL_RXTERM)
#else
#define BF_PCIE_PHY_RX_ENPWR1_LCL_RXTERM(v)   (((v) << 7) & BM_PCIE_PHY_RX_ENPWR1_LCL_RXTERM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_RXTERM field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_LCL_RXTERM(v)   BF_CS1(PCIE_PHY_RX_ENPWR1, LCL_RXTERM, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ENPWR2 -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RX_SCOPE_ATB_0 : 1; //!< Instructs Rx scope regulated VP to use atb_f_p as reference instead of VP.
        unsigned short RX_SCOPE_ATB_1 : 1; //!< Puts Rx scope regulated VP on atb_s_p.
        unsigned short RX_SCOPE_ATB_2 : 1; //!< Puts XOR of Rx scope PMIX input and output on atb_s_p.
        unsigned short EN_RXPMIX_FRC_VPMIX : 1; //!< Instructs rx_pmix_vreg_pmix to use atb_s_m as a reference instead of vbg.
        unsigned short EN_RXPMIX_VOSC : 1; //!< Puts vreg_vosc on atb_s_p.
        unsigned short EN_RXPMIX_VRX : 1; //!< Puts vreg_rx on atb_s_p.
        unsigned short EN_RXPMIX_VPMIX : 1; //!< Puts vreg_pmix on atb_s_p.
        unsigned short EN_RXPMIX_TST : 1; //!< Enables XOR gate to test linearity of Rx phase mixer using atb_s_p and atb_s_m.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_rx_enpwr2_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_ENPWR2 register
 */
#define HW_PCIE_PHY_RX_ENPWR2_ADDR      (REGS_PCIE_PHY_BASE + 0x1025)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_ENPWR2           (*(volatile hw_pcie_phy_rx_enpwr2_t *) HW_PCIE_PHY_RX_ENPWR2_ADDR)
#define HW_PCIE_PHY_RX_ENPWR2_RD()      (HW_PCIE_PHY_RX_ENPWR2.U)
#define HW_PCIE_PHY_RX_ENPWR2_WR(v)     (HW_PCIE_PHY_RX_ENPWR2.U = (v))
#define HW_PCIE_PHY_RX_ENPWR2_SET(v)    (HW_PCIE_PHY_RX_ENPWR2_WR(HW_PCIE_PHY_RX_ENPWR2_RD() |  (v)))
#define HW_PCIE_PHY_RX_ENPWR2_CLR(v)    (HW_PCIE_PHY_RX_ENPWR2_WR(HW_PCIE_PHY_RX_ENPWR2_RD() & ~(v)))
#define HW_PCIE_PHY_RX_ENPWR2_TOG(v)    (HW_PCIE_PHY_RX_ENPWR2_WR(HW_PCIE_PHY_RX_ENPWR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_ENPWR2 bitfields
 */

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field RX_SCOPE_ATB_0 (RW)
 *
 * Instructs Rx scope regulated VP to use atb_f_p as reference instead of VP.
 */

#define BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0      0
#define BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0)
#else
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0(v)   (((v) << 0) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_ATB_0 field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0(v)   BF_CS1(PCIE_PHY_RX_ENPWR2, RX_SCOPE_ATB_0, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field RX_SCOPE_ATB_1 (RW)
 *
 * Puts Rx scope regulated VP on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1      1
#define BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1)
#else
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1(v)   (((v) << 1) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_ATB_1 field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1(v)   BF_CS1(PCIE_PHY_RX_ENPWR2, RX_SCOPE_ATB_1, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field RX_SCOPE_ATB_2 (RW)
 *
 * Puts XOR of Rx scope PMIX input and output on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2      2
#define BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2)
#else
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2(v)   (((v) << 2) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_ATB_2 field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2(v)   BF_CS1(PCIE_PHY_RX_ENPWR2, RX_SCOPE_ATB_2, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_FRC_VPMIX (RW)
 *
 * Instructs rx_pmix_vreg_pmix to use atb_s_m as a reference instead of vbg.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX      3
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX)
#else
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX(v)   (((v) << 3) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_FRC_VPMIX field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX(v)   BF_CS1(PCIE_PHY_RX_ENPWR2, EN_RXPMIX_FRC_VPMIX, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_VOSC (RW)
 *
 * Puts vreg_vosc on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC      4
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC)
#else
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC(v)   (((v) << 4) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_VOSC field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC(v)   BF_CS1(PCIE_PHY_RX_ENPWR2, EN_RXPMIX_VOSC, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_VRX (RW)
 *
 * Puts vreg_rx on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX      5
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX)
#else
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX(v)   (((v) << 5) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_VRX field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX(v)   BF_CS1(PCIE_PHY_RX_ENPWR2, EN_RXPMIX_VRX, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_VPMIX (RW)
 *
 * Puts vreg_pmix on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX      6
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX)
#else
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX(v)   (((v) << 6) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_VPMIX field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX(v)   BF_CS1(PCIE_PHY_RX_ENPWR2, EN_RXPMIX_VPMIX, v)
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_TST (RW)
 *
 * Enables XOR gate to test linearity of Rx phase mixer using atb_s_p and atb_s_m.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST      7
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST)
#else
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST(v)   (((v) << 7) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_TST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST(v)   BF_CS1(PCIE_PHY_RX_ENPWR2, EN_RXPMIX_TST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_SCOPE -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short NC_SCOPE_3 : 3; //!< NC
        unsigned short RX_SCOPE_FDIV20 : 1; //!< Divides scope output clock by 20 instead of 10.
        unsigned short RX_SCOPE_SLEW : 1; //!< Sets high for low Rx clock frqeuencies (625 MHz) for Rx scope to work correctly.
        unsigned short NC_SCOPE_2 : 3; //!< NC
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_rx_scope_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_RX_SCOPE register
 */
#define HW_PCIE_PHY_RX_SCOPE_ADDR      (REGS_PCIE_PHY_BASE + 0x1026)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_RX_SCOPE           (*(volatile hw_pcie_phy_rx_scope_t *) HW_PCIE_PHY_RX_SCOPE_ADDR)
#define HW_PCIE_PHY_RX_SCOPE_RD()      (HW_PCIE_PHY_RX_SCOPE.U)
#define HW_PCIE_PHY_RX_SCOPE_WR(v)     (HW_PCIE_PHY_RX_SCOPE.U = (v))
#define HW_PCIE_PHY_RX_SCOPE_SET(v)    (HW_PCIE_PHY_RX_SCOPE_WR(HW_PCIE_PHY_RX_SCOPE_RD() |  (v)))
#define HW_PCIE_PHY_RX_SCOPE_CLR(v)    (HW_PCIE_PHY_RX_SCOPE_WR(HW_PCIE_PHY_RX_SCOPE_RD() & ~(v)))
#define HW_PCIE_PHY_RX_SCOPE_TOG(v)    (HW_PCIE_PHY_RX_SCOPE_WR(HW_PCIE_PHY_RX_SCOPE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_RX_SCOPE bitfields
 */

/* --- Register HW_PCIE_PHY_RX_SCOPE, field NC_SCOPE_3 (RW)
 *
 * NC
 */

#define BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_3      0
#define BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_3      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_3(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_3)
#else
#define BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_3(v)   (((v) << 0) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NC_SCOPE_3 field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_NC_SCOPE_3(v)   BF_CS1(PCIE_PHY_RX_SCOPE, NC_SCOPE_3, v)
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE, field RX_SCOPE_FDIV20 (RW)
 *
 * Divides scope output clock by 20 instead of 10.
 */

#define BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20      3
#define BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20)
#else
#define BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20(v)   (((v) << 3) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_FDIV20 field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20(v)   BF_CS1(PCIE_PHY_RX_SCOPE, RX_SCOPE_FDIV20, v)
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE, field RX_SCOPE_SLEW (RW)
 *
 * Sets high for low Rx clock frqeuencies (625 MHz) for Rx scope to work correctly.
 */

#define BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW      4
#define BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW)
#else
#define BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW(v)   (((v) << 4) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_SLEW field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW(v)   BF_CS1(PCIE_PHY_RX_SCOPE, RX_SCOPE_SLEW, v)
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE, field NC_SCOPE_2 (RW)
 *
 * NC
 */

#define BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_2      5
#define BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_2      0x000000e0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_2(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_2)
#else
#define BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_2(v)   (((v) << 5) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NC_SCOPE_2 field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_NC_SCOPE_2(v)   BF_CS1(PCIE_PHY_RX_SCOPE, NC_SCOPE_2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_TXDRV_CNTRL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short NOCONN_6 : 1; //!< Reserved
        unsigned short NOCONN_7 : 1; //!< Reserved
        unsigned short NOCONN_8 : 1; //!< Reserved
        unsigned short OVRD_VCM_HOLD : 1; //!< Selects local value of vcm_hold_reg instead of tx_vcm_hold to control state of TX common mode hold circuitry.
        unsigned short VCM_HOLD_REG : 1; //!< Register override for tx_vcm_hold; selected when ovrd_vcm_hold is high; controls the TX common mode hold circuitry.
        unsigned short OVRD_PULL_UP : 1; //!< Selects loval value of pull_up_reg instead of tx_pull_up.
        unsigned short PULL_UP_REG : 1; //!< Register override for tx_pull_up; selected when ovrd_pull_up is high; causes calibrated TX bits to pull up in common mode fashion, unless pull_dn_reg is high.
        unsigned short PULL_DN_REG : 1; //!< Register bit that causes the calibrated Tx bits to pull down in common mode fashion. If pull_dn_reg and tx_pull_up are both high, then pull_dn_reg wins (takes precedence" ).
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_tx_txdrv_cntrl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_TXDRV_CNTRL register
 */
#define HW_PCIE_PHY_TX_TXDRV_CNTRL_ADDR      (REGS_PCIE_PHY_BASE + 0x102b)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_TXDRV_CNTRL           (*(volatile hw_pcie_phy_tx_txdrv_cntrl_t *) HW_PCIE_PHY_TX_TXDRV_CNTRL_ADDR)
#define HW_PCIE_PHY_TX_TXDRV_CNTRL_RD()      (HW_PCIE_PHY_TX_TXDRV_CNTRL.U)
#define HW_PCIE_PHY_TX_TXDRV_CNTRL_WR(v)     (HW_PCIE_PHY_TX_TXDRV_CNTRL.U = (v))
#define HW_PCIE_PHY_TX_TXDRV_CNTRL_SET(v)    (HW_PCIE_PHY_TX_TXDRV_CNTRL_WR(HW_PCIE_PHY_TX_TXDRV_CNTRL_RD() |  (v)))
#define HW_PCIE_PHY_TX_TXDRV_CNTRL_CLR(v)    (HW_PCIE_PHY_TX_TXDRV_CNTRL_WR(HW_PCIE_PHY_TX_TXDRV_CNTRL_RD() & ~(v)))
#define HW_PCIE_PHY_TX_TXDRV_CNTRL_TOG(v)    (HW_PCIE_PHY_TX_TXDRV_CNTRL_WR(HW_PCIE_PHY_TX_TXDRV_CNTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_TXDRV_CNTRL bitfields
 */

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field NOCONN_6 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6      0
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6      0x00000001

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field NOCONN_7 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7      1
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7      0x00000002

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field NOCONN_8 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8      2
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8      0x00000004

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field OVRD_VCM_HOLD (RW)
 *
 * Selects local value of vcm_hold_reg instead of tx_vcm_hold to control state of TX common mode
 * hold circuitry.
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD      3
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD)
#else
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD(v)   (((v) << 3) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_VCM_HOLD field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD(v)   BF_CS1(PCIE_PHY_TX_TXDRV_CNTRL, OVRD_VCM_HOLD, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field VCM_HOLD_REG (RW)
 *
 * Register override for tx_vcm_hold; selected when ovrd_vcm_hold is high; controls the TX common
 * mode hold circuitry.
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG      4
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG)
#else
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG(v)   (((v) << 4) & BM_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VCM_HOLD_REG field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG(v)   BF_CS1(PCIE_PHY_TX_TXDRV_CNTRL, VCM_HOLD_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field OVRD_PULL_UP (RW)
 *
 * Selects loval value of pull_up_reg instead of tx_pull_up.
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP      5
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP)
#else
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP(v)   (((v) << 5) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_PULL_UP field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP(v)   BF_CS1(PCIE_PHY_TX_TXDRV_CNTRL, OVRD_PULL_UP, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field PULL_UP_REG (RW)
 *
 * Register override for tx_pull_up; selected when ovrd_pull_up is high; causes calibrated TX bits
 * to pull up in common mode fashion, unless pull_dn_reg is high.
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG      6
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG)
#else
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG(v)   (((v) << 6) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PULL_UP_REG field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG(v)   BF_CS1(PCIE_PHY_TX_TXDRV_CNTRL, PULL_UP_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field PULL_DN_REG (RW)
 *
 * Register bit that causes the calibrated Tx bits to pull down in common mode fashion. If
 * pull_dn_reg and tx_pull_up are both high, then pull_dn_reg wins (takes precedence" ).
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG      7
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG)
#else
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG(v)   (((v) << 7) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PULL_DN_REG field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG(v)   BF_CS1(PCIE_PHY_TX_TXDRV_CNTRL, PULL_DN_REG, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_POWER_CTL -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short NOCONN_5 : 1; //!< Reserved
        unsigned short REFGEN_PDN_REG : 1; //!< Value for refgen_pwdn when OVRD_EN is 1.
        unsigned short TX_DIV_CLK_EN : 1; //!< Enables the div clock that is output from the Tx to the undersampler, more appropriately called tx_sampler_clk_en; this clock is output after the optional divide-by-2/ 4; tx_clk_en must be high to output a clock.
        unsigned short REFGEN_EN_REG : 1; //!< Register override value for tx_refgen_en; turns on the pmos_bias refgen block and the rxdetect comparators.
        unsigned short DATA_EN_REG : 1; //!< Value for tx_data_en when OVRD_EN is 1.
        unsigned short CLK_EN_REG : 1; //!< Value for tx_clk_en when OVRD_EN is 1.
        unsigned short SERIAL_EN_REG : 1; //!< Value for tx_serial_en when OVRD_EN is 1.
        unsigned short OVRD_EN : 1; //!< Enables local overrides for all signals in this register.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_tx_power_ctl_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_POWER_CTL register
 */
#define HW_PCIE_PHY_TX_POWER_CTL_ADDR      (REGS_PCIE_PHY_BASE + 0x102c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_POWER_CTL           (*(volatile hw_pcie_phy_tx_power_ctl_t *) HW_PCIE_PHY_TX_POWER_CTL_ADDR)
#define HW_PCIE_PHY_TX_POWER_CTL_RD()      (HW_PCIE_PHY_TX_POWER_CTL.U)
#define HW_PCIE_PHY_TX_POWER_CTL_WR(v)     (HW_PCIE_PHY_TX_POWER_CTL.U = (v))
#define HW_PCIE_PHY_TX_POWER_CTL_SET(v)    (HW_PCIE_PHY_TX_POWER_CTL_WR(HW_PCIE_PHY_TX_POWER_CTL_RD() |  (v)))
#define HW_PCIE_PHY_TX_POWER_CTL_CLR(v)    (HW_PCIE_PHY_TX_POWER_CTL_WR(HW_PCIE_PHY_TX_POWER_CTL_RD() & ~(v)))
#define HW_PCIE_PHY_TX_POWER_CTL_TOG(v)    (HW_PCIE_PHY_TX_POWER_CTL_WR(HW_PCIE_PHY_TX_POWER_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_POWER_CTL bitfields
 */

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field NOCONN_5 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_POWER_CTL_NOCONN_5      0
#define BM_PCIE_PHY_TX_POWER_CTL_NOCONN_5      0x00000001

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field REFGEN_PDN_REG (RW)
 *
 * Value for refgen_pwdn when OVRD_EN is 1.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG      1
#define BM_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG)
#else
#define BF_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG(v)   (((v) << 1) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REFGEN_PDN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG(v)   BF_CS1(PCIE_PHY_TX_POWER_CTL, REFGEN_PDN_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field TX_DIV_CLK_EN (RW)
 *
 * Enables the div clock that is output from the Tx to the undersampler, more appropriately called
 * tx_sampler_clk_en; this clock is output after the optional divide-by-2/ 4; tx_clk_en must be high
 * to output a clock.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN      2
#define BM_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN)
#else
#define BF_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN(v)   (((v) << 2) & BM_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DIV_CLK_EN field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN(v)   BF_CS1(PCIE_PHY_TX_POWER_CTL, TX_DIV_CLK_EN, v)
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field REFGEN_EN_REG (RW)
 *
 * Register override value for tx_refgen_en; turns on the pmos_bias refgen block and the rxdetect
 * comparators.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG      3
#define BM_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG)
#else
#define BF_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG(v)   (((v) << 3) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REFGEN_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG(v)   BF_CS1(PCIE_PHY_TX_POWER_CTL, REFGEN_EN_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field DATA_EN_REG (RW)
 *
 * Value for tx_data_en when OVRD_EN is 1.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG      4
#define BM_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG)
#else
#define BF_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG(v)   (((v) << 4) & BM_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG(v)   BF_CS1(PCIE_PHY_TX_POWER_CTL, DATA_EN_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field CLK_EN_REG (RW)
 *
 * Value for tx_clk_en when OVRD_EN is 1.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG      5
#define BM_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG)
#else
#define BF_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG(v)   (((v) << 5) & BM_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG(v)   BF_CS1(PCIE_PHY_TX_POWER_CTL, CLK_EN_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field SERIAL_EN_REG (RW)
 *
 * Value for tx_serial_en when OVRD_EN is 1.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG      6
#define BM_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG)
#else
#define BF_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG(v)   (((v) << 6) & BM_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SERIAL_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG(v)   BF_CS1(PCIE_PHY_TX_POWER_CTL, SERIAL_EN_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field OVRD_EN (RW)
 *
 * Enables local overrides for all signals in this register.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_OVRD_EN      7
#define BM_PCIE_PHY_TX_POWER_CTL_OVRD_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_POWER_CTL_OVRD_EN(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_POWER_CTL_OVRD_EN)
#else
#define BF_PCIE_PHY_TX_POWER_CTL_OVRD_EN(v)   (((v) << 7) & BM_PCIE_PHY_TX_POWER_CTL_OVRD_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_EN field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_OVRD_EN(v)   BF_CS1(PCIE_PHY_TX_POWER_CTL, OVRD_EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ALT_BLOCK -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short OVRD_ALT_BUS : 1; //!< Enables local overrides for alt-bus control signals.
        unsigned short ALT_OSC_VPHREG : 1; //!< Enables and connects the vphreg oscillator to the transmit pins; must set drv_source_reg bus correctly.
        unsigned short ALT_OSC_VPH : 1; //!< Enables and connects the vph oscillator to the transmit pins; must set drv_source_reg bus correctly.
        unsigned short ALT_OSC_VP : 1; //!< Enables and connects the vp oscillator to the transmit pins; must set drv_source_reg bus correctly.
        unsigned short JTAG_DATA_REG : 1; //!< Value for jtag_data when OVRD_ALT_BUS is 1.
        unsigned short DRV_SOURCE_REG : 2; //!< Value for tx_data_source when OVRD_ALT_BUS is 1
        unsigned short EN_ALT_BUS : 1; //!< Enables the Tx for alt bus mode, powers up the pmos_bias block, and so on; required if manually running the alt bus features.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_tx_alt_block_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_ALT_BLOCK register
 */
#define HW_PCIE_PHY_TX_ALT_BLOCK_ADDR      (REGS_PCIE_PHY_BASE + 0x102d)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_ALT_BLOCK           (*(volatile hw_pcie_phy_tx_alt_block_t *) HW_PCIE_PHY_TX_ALT_BLOCK_ADDR)
#define HW_PCIE_PHY_TX_ALT_BLOCK_RD()      (HW_PCIE_PHY_TX_ALT_BLOCK.U)
#define HW_PCIE_PHY_TX_ALT_BLOCK_WR(v)     (HW_PCIE_PHY_TX_ALT_BLOCK.U = (v))
#define HW_PCIE_PHY_TX_ALT_BLOCK_SET(v)    (HW_PCIE_PHY_TX_ALT_BLOCK_WR(HW_PCIE_PHY_TX_ALT_BLOCK_RD() |  (v)))
#define HW_PCIE_PHY_TX_ALT_BLOCK_CLR(v)    (HW_PCIE_PHY_TX_ALT_BLOCK_WR(HW_PCIE_PHY_TX_ALT_BLOCK_RD() & ~(v)))
#define HW_PCIE_PHY_TX_ALT_BLOCK_TOG(v)    (HW_PCIE_PHY_TX_ALT_BLOCK_WR(HW_PCIE_PHY_TX_ALT_BLOCK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_ALT_BLOCK bitfields
 */

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field OVRD_ALT_BUS (RW)
 *
 * Enables local overrides for alt-bus control signals.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS      0
#define BM_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS)
#else
#define BF_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS(v)   (((v) << 0) & BM_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_ALT_BUS field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS(v)   BF_CS1(PCIE_PHY_TX_ALT_BLOCK, OVRD_ALT_BUS, v)
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field ALT_OSC_VPHREG (RW)
 *
 * Enables and connects the vphreg oscillator to the transmit pins; must set drv_source_reg bus
 * correctly.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG      1
#define BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG)
#else
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG(v)   (((v) << 1) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALT_OSC_VPHREG field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG(v)   BF_CS1(PCIE_PHY_TX_ALT_BLOCK, ALT_OSC_VPHREG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field ALT_OSC_VPH (RW)
 *
 * Enables and connects the vph oscillator to the transmit pins; must set drv_source_reg bus
 * correctly.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH      2
#define BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH)
#else
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH(v)   (((v) << 2) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALT_OSC_VPH field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH(v)   BF_CS1(PCIE_PHY_TX_ALT_BLOCK, ALT_OSC_VPH, v)
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field ALT_OSC_VP (RW)
 *
 * Enables and connects the vp oscillator to the transmit pins; must set drv_source_reg bus
 * correctly.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP      3
#define BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP)
#else
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP(v)   (((v) << 3) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALT_OSC_VP field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP(v)   BF_CS1(PCIE_PHY_TX_ALT_BLOCK, ALT_OSC_VP, v)
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field JTAG_DATA_REG (RW)
 *
 * Value for jtag_data when OVRD_ALT_BUS is 1.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG      4
#define BM_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG)
#else
#define BF_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG(v)   (((v) << 4) & BM_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the JTAG_DATA_REG field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG(v)   BF_CS1(PCIE_PHY_TX_ALT_BLOCK, JTAG_DATA_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field DRV_SOURCE_REG (RW)
 *
 * Value for tx_data_source when OVRD_ALT_BUS is 1
 *
 * Values:
 * 11 - JTAG data common mode for test
 * 10 - LFPS oscillator differential
 * 01 - JTAG data differential
 * 00 - Serializer data or alt oscillator vp/vph/vphreg/vptx if selected
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG      5
#define BM_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG)
#else
#define BF_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG(v)   (((v) << 5) & BM_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DRV_SOURCE_REG field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG(v)   BF_CS1(PCIE_PHY_TX_ALT_BLOCK, DRV_SOURCE_REG, v)
#endif


/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field EN_ALT_BUS (RW)
 *
 * Enables the Tx for alt bus mode, powers up the pmos_bias block, and so on; required if manually
 * running the alt bus features.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS      7
#define BM_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS)
#else
#define BF_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS(v)   (((v) << 7) & BM_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ALT_BUS field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS(v)   BF_CS1(PCIE_PHY_TX_ALT_BLOCK, EN_ALT_BUS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ALT_AND_LOOPBACK -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short NOCONN_00 : 1; //!< Reserved
        unsigned short NOCONN_01 : 1; //!< Reserved
        unsigned short NOCONN_02 : 1; //!< Reserved
        unsigned short NOCONN_03 : 1; //!< Reserved
        unsigned short NOCONN_04 : 1; //!< Reserved
        unsigned short ALT_VPTX_OSC : 1; //!< Enables and connects the vptx oscillator to the transmit pins; must set drv_source_reg bus correctly.
        unsigned short TX_LB_EN_REG : 1; //!< Value of the tx_lb_en pin when OVRD_TX_LB is enabled.
        unsigned short OVRD_TX_LB : 1; //!< Enables the override of the tx_lb_en pin.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_tx_alt_and_loopback_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_ALT_AND_LOOPBACK register
 */
#define HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_ADDR      (REGS_PCIE_PHY_BASE + 0x102e)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_ALT_AND_LOOPBACK           (*(volatile hw_pcie_phy_tx_alt_and_loopback_t *) HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_ADDR)
#define HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_RD()      (HW_PCIE_PHY_TX_ALT_AND_LOOPBACK.U)
#define HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_WR(v)     (HW_PCIE_PHY_TX_ALT_AND_LOOPBACK.U = (v))
#define HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_SET(v)    (HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_WR(HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_RD() |  (v)))
#define HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_CLR(v)    (HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_WR(HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_RD() & ~(v)))
#define HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_TOG(v)    (HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_WR(HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_ALT_AND_LOOPBACK bitfields
 */

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_00 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00      0
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00      0x00000001

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_01 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01      1
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01      0x00000002

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_02 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02      2
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02      0x00000004

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_03 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03      3
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03      0x00000008

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_04 (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04      4
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04      0x00000010

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field ALT_VPTX_OSC (RW)
 *
 * Enables and connects the vptx oscillator to the transmit pins; must set drv_source_reg bus
 * correctly.
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC      5
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC)
#else
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC(v)   (((v) << 5) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALT_VPTX_OSC field to a new value.
#define BW_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC(v)   BF_CS1(PCIE_PHY_TX_ALT_AND_LOOPBACK, ALT_VPTX_OSC, v)
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field TX_LB_EN_REG (RW)
 *
 * Value of the tx_lb_en pin when OVRD_TX_LB is enabled.
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG      6
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG)
#else
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG(v)   (((v) << 6) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_LB_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG(v)   BF_CS1(PCIE_PHY_TX_ALT_AND_LOOPBACK, TX_LB_EN_REG, v)
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field OVRD_TX_LB (RW)
 *
 * Enables the override of the tx_lb_en pin.
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB      7
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB)
#else
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB(v)   (((v) << 7) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_TX_LB field to a new value.
#define BW_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB(v)   BF_CS1(PCIE_PHY_TX_ALT_AND_LOOPBACK, OVRD_TX_LB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_TX_ATB_REG -  (RW)
 *

 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ATB_VCM : 1; //!< Connects tx_p/tx_m common mode voltage onto atb_s_p and local ground onto atb_s_m.
        unsigned short ATB_TXSM : 1; //!< Connects tx_m to atb_s_m.
        unsigned short ATB_TXSP : 1; //!< Connects tx_p to atb_s_p.
        unsigned short ATB_TXFM : 1; //!< Connects tx_m to atb_f_m.
        unsigned short ATB_TXFP : 1; //!< Connects tx_p to atb_f_p.
        unsigned short ATB_RXDETREF : 1; //!< Connects Rx detect block reference voltage to atb_s_p and local ground to atb_s_m.
        unsigned short ATB_VCM_REP : 1; //!< Connects common mode replica voltage in pmos_bias block to atb_s_p and local ground to atb_s_m.
        unsigned short ATB_PBIAS : 1; //!< Connects real pmos_bias voltage for Tx PMOS driver pull-up path to atb_s_p and local ground at the pmos_bias block to atb_s_m.
        unsigned short RESERVED0 : 8; //!< Reserved
    } B;
} hw_pcie_phy_tx_tx_atb_reg_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_TX_TX_ATB_REG register
 */
#define HW_PCIE_PHY_TX_TX_ATB_REG_ADDR      (REGS_PCIE_PHY_BASE + 0x102f)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_TX_TX_ATB_REG           (*(volatile hw_pcie_phy_tx_tx_atb_reg_t *) HW_PCIE_PHY_TX_TX_ATB_REG_ADDR)
#define HW_PCIE_PHY_TX_TX_ATB_REG_RD()      (HW_PCIE_PHY_TX_TX_ATB_REG.U)
#define HW_PCIE_PHY_TX_TX_ATB_REG_WR(v)     (HW_PCIE_PHY_TX_TX_ATB_REG.U = (v))
#define HW_PCIE_PHY_TX_TX_ATB_REG_SET(v)    (HW_PCIE_PHY_TX_TX_ATB_REG_WR(HW_PCIE_PHY_TX_TX_ATB_REG_RD() |  (v)))
#define HW_PCIE_PHY_TX_TX_ATB_REG_CLR(v)    (HW_PCIE_PHY_TX_TX_ATB_REG_WR(HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~(v)))
#define HW_PCIE_PHY_TX_TX_ATB_REG_TOG(v)    (HW_PCIE_PHY_TX_TX_ATB_REG_WR(HW_PCIE_PHY_TX_TX_ATB_REG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_TX_TX_ATB_REG bitfields
 */

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_VCM (RW)
 *
 * Connects tx_p/tx_m common mode voltage onto atb_s_p and local ground onto atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM      0
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM(v)   ((((reg32_t) v) << 0) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM)
#else
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM(v)   (((v) << 0) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_VCM field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM(v)   BF_CS1(PCIE_PHY_TX_TX_ATB_REG, ATB_VCM, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_TXSM (RW)
 *
 * Connects tx_m to atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM      1
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM(v)   ((((reg32_t) v) << 1) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM)
#else
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM(v)   (((v) << 1) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_TXSM field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM(v)   BF_CS1(PCIE_PHY_TX_TX_ATB_REG, ATB_TXSM, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_TXSP (RW)
 *
 * Connects tx_p to atb_s_p.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP      2
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP(v)   ((((reg32_t) v) << 2) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP)
#else
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP(v)   (((v) << 2) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_TXSP field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP(v)   BF_CS1(PCIE_PHY_TX_TX_ATB_REG, ATB_TXSP, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_TXFM (RW)
 *
 * Connects tx_m to atb_f_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM      3
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM(v)   ((((reg32_t) v) << 3) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM)
#else
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM(v)   (((v) << 3) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_TXFM field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM(v)   BF_CS1(PCIE_PHY_TX_TX_ATB_REG, ATB_TXFM, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_TXFP (RW)
 *
 * Connects tx_p to atb_f_p.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP      4
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP(v)   ((((reg32_t) v) << 4) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP)
#else
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP(v)   (((v) << 4) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_TXFP field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP(v)   BF_CS1(PCIE_PHY_TX_TX_ATB_REG, ATB_TXFP, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_RXDETREF (RW)
 *
 * Connects Rx detect block reference voltage to atb_s_p and local ground to atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF      5
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF(v)   ((((reg32_t) v) << 5) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF)
#else
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF(v)   (((v) << 5) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_RXDETREF field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF(v)   BF_CS1(PCIE_PHY_TX_TX_ATB_REG, ATB_RXDETREF, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_VCM_REP (RW)
 *
 * Connects common mode replica voltage in pmos_bias block to atb_s_p and local ground to atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP      6
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP(v)   ((((reg32_t) v) << 6) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP)
#else
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP(v)   (((v) << 6) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_VCM_REP field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP(v)   BF_CS1(PCIE_PHY_TX_TX_ATB_REG, ATB_VCM_REP, v)
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_PBIAS (RW)
 *
 * Connects real pmos_bias voltage for Tx PMOS driver pull-up path to atb_s_p and local ground at
 * the pmos_bias block to atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS      7
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS(v)   ((((reg32_t) v) << 7) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS)
#else
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS(v)   (((v) << 7) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_PBIAS field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS(v)   BF_CS1(PCIE_PHY_TX_TX_ATB_REG, ATB_PBIAS, v)
#endif


/*!
 * @brief All PCIE_PHY module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_pcie_phy_idcode_lo_t IDCODE_LO; //!< Register ID Low 16 bits
    volatile hw_pcie_phy_idcode_hi_t IDCODE_HI; //!< Register ID High 16 bits
    volatile hw_pcie_phy_debug_t DEBUG; //!< Debug Register
    volatile hw_pcie_phy_rtune_debug_t RTUNE_DEBUG; //!< Debug Register
    volatile hw_pcie_phy_rtune_stat_t RTUNE_STAT; //!< 
    volatile hw_pcie_phy_ss_phase_t SS_PHASE; //!< 
    volatile hw_pcie_phy_ss_freq_t SS_FREQ; //!< 
    reg16_t _reserved0;
    volatile hw_pcie_phy_ateovrd_t ATEOVRD; //!< 
    volatile hw_pcie_phy_mpll_ovrd_in_lo_t MPLL_OVRD_IN_LO; //!< 
    volatile hw_pcie_phy_ssc_ovrd_in_t SSC_OVRD_IN; //!< 
    volatile hw_pcie_phy_bs_ovrd_in_t BS_OVRD_IN; //!< 
    volatile hw_pcie_phy_level_ovrd_in_t LEVEL_OVRD_IN; //!< 
    volatile hw_pcie_phy_sup_ovrd_out_t SUP_OVRD_OUT; //!< 
    volatile hw_pcie_phy_mpll_asic_in_t MPLL_ASIC_IN; //!< 
    volatile hw_pcie_phy_bs_asic_in_t BS_ASIC_IN; //!< 
    volatile hw_pcie_phy_level_asic_in_t LEVEL_ASIC_IN; //!< 
    volatile hw_pcie_phy_ssc_asic_in_t SSC_ASIC_IN; //!< 
    volatile hw_pcie_phy_sup_asic_out_t SUP_ASIC_OUT; //!< 
    volatile hw_pcie_phy_ateovrd_status_t ATEOVRD_STATUS; //!< 
    volatile hw_pcie_phy_scope_enables_t SCOPE_ENABLES; //!< 
    volatile hw_pcie_phy_scope_samples_t SCOPE_SAMPLES; //!< 
    volatile hw_pcie_phy_scope_count_t SCOPE_COUNT; //!< 
    volatile hw_pcie_phy_scope_ctl_t SCOPE_CTL; //!< 
    volatile hw_pcie_phy_scope_mask_t SCOPE_MASK; //!< 
    volatile hw_pcie_phy_mpll_loop_ctl_t MPLL_LOOP_CTL; //!< 
    volatile hw_pcie_phy_mpll_atb_meas1_t MPLL_ATB_MEAS1; //!< 
    volatile hw_pcie_phy_mpll_atb_meas2_t MPLL_ATB_MEAS2; //!< 
    volatile hw_pcie_phy_mpll_ovr_t MPLL_OVR; //!< 
    volatile hw_pcie_phy_rtune_rtune_ctrl_t RTUNE_RTUNE_CTRL; //!< 
    volatile hw_pcie_phy_atb_switchyard_ctrl_t ATB_SWITCHYARD_CTRL; //!< 
    reg16_t _reserved1[2017];
    volatile hw_pcie_phy_tx_ovrd_in_lo_t TX_OVRD_IN_LO; //!< 
    volatile hw_pcie_phy_tx_ovrd_in_hi_t TX_OVRD_IN_HI; //!< 
    volatile hw_pcie_phy_tx_ovrd_drv_lo_t TX_OVRD_DRV_LO; //!< 
    volatile hw_pcie_phy_tx_ovrd_out_t TX_OVRD_OUT; //!< 
    volatile hw_pcie_phy_rx_ovrd_in_lo_t RX_OVRD_IN_LO; //!< 
    volatile hw_pcie_phy_rx_ovrd_in_hi_t RX_OVRD_IN_HI; //!< 
    volatile hw_pcie_phy_rx_ovrd_out_t RX_OVRD_OUT; //!< 
    volatile hw_pcie_phy_tx_asic_in_t TX_ASIC_IN; //!< 
    volatile hw_pcie_phy_tx_asic_drv_lo_t TX_ASIC_DRV_LO; //!< 
    volatile hw_pcie_phy_tx_asic_drv_hi_t TX_ASIC_DRV_HI; //!< 
    volatile hw_pcie_phy_tx_asic_out_t TX_ASIC_OUT; //!< 
    volatile hw_pcie_phy_rx_asic_in_t RX_ASIC_IN; //!< 
    volatile hw_pcie_phy_rx_asic_out_t RX_ASIC_OUT; //!< 
    volatile hw_pcie_phy_tx_debug_t TX_DEBUG; //!< 
    volatile hw_pcie_phy_tx_vmd_fsm_tx_vcm_0_t TX_VMD_FSM_TX_VCM_0; //!< 
    volatile hw_pcie_phy_tx_vmd_fsm_tx_vcm_1_t TX_VMD_FSM_TX_VCM_1; //!< 
    volatile hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_in_t TX_VMD_FSM_TX_VCM_DEBUG_IN; //!< 
    volatile hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_out_t TX_VMD_FSM_TX_VCM_DEBUG_OUT; //!< 
    volatile hw_pcie_phy_tx_lbert_ctl_t TX_LBERT_CTL; //!< 
    volatile hw_pcie_phy_rx_lbert_ctl_t RX_LBERT_CTL; //!< 
    volatile hw_pcie_phy_rx_lbert_err_t RX_LBERT_ERR; //!< 
    volatile hw_pcie_phy_rx_scope_ctl_t RX_SCOPE_CTL; //!< 
    volatile hw_pcie_phy_rx_scope_phase_t RX_SCOPE_PHASE; //!< 
    volatile hw_pcie_phy_rx_dpll_freq_t RX_DPLL_FREQ; //!< 
    volatile hw_pcie_phy_rx_cdr_ctl_t RX_CDR_CTL; //!< 
    volatile hw_pcie_phy_rx_cdr_cdr_fsm_debug_t RX_CDR_CDR_FSM_DEBUG; //!< 
    volatile hw_pcie_phy_rx_cdr_lock_vec_ovrd_t RX_CDR_LOCK_VEC_OVRD; //!< 
    volatile hw_pcie_phy_rx_cdr_lock_vec_t RX_CDR_LOCK_VEC; //!< 
    volatile hw_pcie_phy_rx_cdr_adap_fsm_t RX_CDR_ADAP_FSM; //!< 
    volatile hw_pcie_phy_rx_atb0_t RX_ATB0; //!< 
    volatile hw_pcie_phy_rx_atb1_t RX_ATB1; //!< 
    volatile hw_pcie_phy_rx_enpwr0_t RX_ENPWR0; //!< 
    volatile hw_pcie_phy_rx_pmix_phase_t RX_PMIX_PHASE; //!< 
    volatile hw_pcie_phy_rx_enpwr1_t RX_ENPWR1; //!< 
    volatile hw_pcie_phy_rx_enpwr2_t RX_ENPWR2; //!< 
    volatile hw_pcie_phy_rx_scope_t RX_SCOPE; //!< 
    volatile hw_pcie_phy_tx_txdrv_cntrl_t TX_TXDRV_CNTRL; //!< 
    volatile hw_pcie_phy_tx_power_ctl_t TX_POWER_CTL; //!< 
    volatile hw_pcie_phy_tx_alt_block_t TX_ALT_BLOCK; //!< 
    volatile hw_pcie_phy_tx_alt_and_loopback_t TX_ALT_AND_LOOPBACK; //!< 
    volatile hw_pcie_phy_tx_tx_atb_reg_t TX_TX_ATB_REG; //!< 
} hw_pcie_phy_t
#endif

//! @brief Macro to access all PCIE_PHY registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PCIE_PHY(0)</code>.
#define HW_PCIE_PHY     (*(volatile hw_pcie_phy_t *) REGS_PCIE_PHY_BASE)


#endif // _PCIE_PHY_H
