/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_PCIE_PHY_REGISTERS_H__
#define __HW_PCIE_PHY_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SDL PCIE_PHY registers defined in this header file.
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
 * - HW_PCIE_PHY_SCOPE_MASK_000 - 
 * - HW_PCIE_PHY_SCOPE_MASK_001 - 
 * - HW_PCIE_PHY_SCOPE_MASK_010 - 
 * - HW_PCIE_PHY_SCOPE_MASK_011 - 
 * - HW_PCIE_PHY_SCOPE_MASK_100 - 
 * - HW_PCIE_PHY_SCOPE_MASK_101 - 
 * - HW_PCIE_PHY_SCOPE_MASK_110 - 
 * - HW_PCIE_PHY_SCOPE_MASK_111 - 
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
 * - hw_pcie_phy_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PCIE_PHY_BASE
#define HW_PCIE_PHY_INSTANCE_COUNT (1) //!< Number of instances of the PCIE_PHY module.
#define REGS_PCIE_PHY_BASE (0x00000000) //!< Base address for PCIE_PHY.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_IDCODE_LO - Register ID Low 16 bits (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_idcode_lo
{
    reg16_t U;
    struct _hw_pcie_phy_idcode_lo_bitfields
    {
        unsigned short IDCODE_LO : 16; //!< [15:0] Data
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

/* --- Register HW_PCIE_PHY_IDCODE_LO, field IDCODE_LO[15:0] (RO)
 *
 * Data
 */

#define BP_PCIE_PHY_IDCODE_LO_IDCODE_LO      (0)      //!< Bit position for PCIE_PHY_IDCODE_LO_IDCODE_LO.
#define BM_PCIE_PHY_IDCODE_LO_IDCODE_LO      (0x0000ffff)  //!< Bit mask for PCIE_PHY_IDCODE_LO_IDCODE_LO.

//! @brief Get value of PCIE_PHY_IDCODE_LO_IDCODE_LO from a register value.
#define BG_PCIE_PHY_IDCODE_LO_IDCODE_LO(r)   (((r) & BM_PCIE_PHY_IDCODE_LO_IDCODE_LO) >> BP_PCIE_PHY_IDCODE_LO_IDCODE_LO)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_IDCODE_HI - Register ID High 16 bits (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_idcode_hi
{
    reg16_t U;
    struct _hw_pcie_phy_idcode_hi_bitfields
    {
        unsigned short IDCODE_HI : 16; //!< [15:0] Data
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

/* --- Register HW_PCIE_PHY_IDCODE_HI, field IDCODE_HI[15:0] (RO)
 *
 * Data
 */

#define BP_PCIE_PHY_IDCODE_HI_IDCODE_HI      (0)      //!< Bit position for PCIE_PHY_IDCODE_HI_IDCODE_HI.
#define BM_PCIE_PHY_IDCODE_HI_IDCODE_HI      (0x0000ffff)  //!< Bit mask for PCIE_PHY_IDCODE_HI_IDCODE_HI.

//! @brief Get value of PCIE_PHY_IDCODE_HI_IDCODE_HI from a register value.
#define BG_PCIE_PHY_IDCODE_HI_IDCODE_HI(r)   (((r) & BM_PCIE_PHY_IDCODE_HI_IDCODE_HI) >> BP_PCIE_PHY_IDCODE_HI_IDCODE_HI)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_DEBUG - Debug Register (RW)
 *
 * Reset value: 0x0000000a
 *

 */
typedef union _hw_pcie_phy_debug
{
    reg16_t U;
    struct _hw_pcie_phy_debug_bitfields
    {
        unsigned short TX_VREF_SEL : 5; //!< [4:0] -
        unsigned short DTB_SEL : 2; //!< [6:5] Description: The lane DTB's are ORed together with the support DTB signals selected with the following encodings.
        unsigned short RESERVED0 : 9; //!< [15:7] Reserved.
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

/* --- Register HW_PCIE_PHY_DEBUG, field TX_VREF_SEL[4:0] (RW)
 *
 * -
 */

#define BP_PCIE_PHY_DEBUG_TX_VREF_SEL      (0)      //!< Bit position for PCIE_PHY_DEBUG_TX_VREF_SEL.
#define BM_PCIE_PHY_DEBUG_TX_VREF_SEL      (0x0000001f)  //!< Bit mask for PCIE_PHY_DEBUG_TX_VREF_SEL.

//! @brief Get value of PCIE_PHY_DEBUG_TX_VREF_SEL from a register value.
#define BG_PCIE_PHY_DEBUG_TX_VREF_SEL(r)   (((r) & BM_PCIE_PHY_DEBUG_TX_VREF_SEL) >> BP_PCIE_PHY_DEBUG_TX_VREF_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_DEBUG_TX_VREF_SEL.
#define BF_PCIE_PHY_DEBUG_TX_VREF_SEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_DEBUG_TX_VREF_SEL) & BM_PCIE_PHY_DEBUG_TX_VREF_SEL)
#else
//! @brief Format value for bitfield PCIE_PHY_DEBUG_TX_VREF_SEL.
#define BF_PCIE_PHY_DEBUG_TX_VREF_SEL(v)   (((v) << BP_PCIE_PHY_DEBUG_TX_VREF_SEL) & BM_PCIE_PHY_DEBUG_TX_VREF_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_VREF_SEL field to a new value.
#define BW_PCIE_PHY_DEBUG_TX_VREF_SEL(v)   (HW_PCIE_PHY_DEBUG_WR((HW_PCIE_PHY_DEBUG_RD() & ~BM_PCIE_PHY_DEBUG_TX_VREF_SEL) | BF_PCIE_PHY_DEBUG_TX_VREF_SEL(v)))
#endif

/* --- Register HW_PCIE_PHY_DEBUG, field DTB_SEL[6:5] (RW)
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

#define BP_PCIE_PHY_DEBUG_DTB_SEL      (5)      //!< Bit position for PCIE_PHY_DEBUG_DTB_SEL.
#define BM_PCIE_PHY_DEBUG_DTB_SEL      (0x00000060)  //!< Bit mask for PCIE_PHY_DEBUG_DTB_SEL.

//! @brief Get value of PCIE_PHY_DEBUG_DTB_SEL from a register value.
#define BG_PCIE_PHY_DEBUG_DTB_SEL(r)   (((r) & BM_PCIE_PHY_DEBUG_DTB_SEL) >> BP_PCIE_PHY_DEBUG_DTB_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_DEBUG_DTB_SEL.
#define BF_PCIE_PHY_DEBUG_DTB_SEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_DEBUG_DTB_SEL) & BM_PCIE_PHY_DEBUG_DTB_SEL)
#else
//! @brief Format value for bitfield PCIE_PHY_DEBUG_DTB_SEL.
#define BF_PCIE_PHY_DEBUG_DTB_SEL(v)   (((v) << BP_PCIE_PHY_DEBUG_DTB_SEL) & BM_PCIE_PHY_DEBUG_DTB_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL field to a new value.
#define BW_PCIE_PHY_DEBUG_DTB_SEL(v)   (HW_PCIE_PHY_DEBUG_WR((HW_PCIE_PHY_DEBUG_RD() & ~BM_PCIE_PHY_DEBUG_DTB_SEL) | BF_PCIE_PHY_DEBUG_DTB_SEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RTUNE_DEBUG - Debug Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rtune_debug
{
    reg16_t U;
    struct _hw_pcie_phy_rtune_debug_bitfields
    {
        unsigned short FLIP_COMP : 1; //!< [0] Inverts Analog Comparator Output.
        unsigned short MAN_TUNE : 1; //!< [1] Write a 1 to perform a manual tuning specified by the TYPE field. Starting a manual tune while a tune is currently running can cause unpredictable results. For use only when you know what the part is doing (with respect to resistor tuning). Write a 1 to perform an operation. Subsequent writes with the bit set will trigger the operation. No need to clear (0) the bit between writes.
        unsigned short SET_VAL : 1; //!< [2] Sets value. Write a 1 to manually write the register specified by the TYPE field to the value in the VALUE field.
        unsigned short TYPE : 2; //!< [4:3] Type of manual tuning or register read/write to execute.
        unsigned short VALUE : 10; //!< [14:5] Value to use when triggering SET_VAL field. Only the 6 LSB's are used when setting Rx cal or Tx cal values.
        unsigned short RESERVED0 : 1; //!< [15] Reserved
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

/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field FLIP_COMP[0] (RW)
 *
 * Inverts Analog Comparator Output.
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP      (0)      //!< Bit position for PCIE_PHY_RTUNE_DEBUG_FLIP_COMP.
#define BM_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP      (0x00000001)  //!< Bit mask for PCIE_PHY_RTUNE_DEBUG_FLIP_COMP.

//! @brief Get value of PCIE_PHY_RTUNE_DEBUG_FLIP_COMP from a register value.
#define BG_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP(r)   (((r) & BM_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP) >> BP_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_FLIP_COMP.
#define BF_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP) & BM_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_FLIP_COMP.
#define BF_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP(v)   (((v) << BP_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP) & BM_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FLIP_COMP field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP(v)   (HW_PCIE_PHY_RTUNE_DEBUG_WR((HW_PCIE_PHY_RTUNE_DEBUG_RD() & ~BM_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP) | BF_PCIE_PHY_RTUNE_DEBUG_FLIP_COMP(v)))
#endif

/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field MAN_TUNE[1] (RW)
 *
 * Write a 1 to perform a manual tuning specified by the TYPE field. Starting a manual tune while a
 * tune is currently running can cause unpredictable results. For use only when you know what the
 * part is doing (with respect to resistor tuning). Write a 1 to perform an operation. Subsequent
 * writes with the bit set will trigger the operation. No need to clear (0) the bit between writes.
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE      (1)      //!< Bit position for PCIE_PHY_RTUNE_DEBUG_MAN_TUNE.
#define BM_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE      (0x00000002)  //!< Bit mask for PCIE_PHY_RTUNE_DEBUG_MAN_TUNE.

//! @brief Get value of PCIE_PHY_RTUNE_DEBUG_MAN_TUNE from a register value.
#define BG_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE(r)   (((r) & BM_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE) >> BP_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_MAN_TUNE.
#define BF_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE) & BM_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_MAN_TUNE.
#define BF_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE(v)   (((v) << BP_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE) & BM_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MAN_TUNE field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE(v)   (HW_PCIE_PHY_RTUNE_DEBUG_WR((HW_PCIE_PHY_RTUNE_DEBUG_RD() & ~BM_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE) | BF_PCIE_PHY_RTUNE_DEBUG_MAN_TUNE(v)))
#endif

/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field SET_VAL[2] (RW)
 *
 * Sets value. Write a 1 to manually write the register specified by the TYPE field to the value in
 * the VALUE field.
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_SET_VAL      (2)      //!< Bit position for PCIE_PHY_RTUNE_DEBUG_SET_VAL.
#define BM_PCIE_PHY_RTUNE_DEBUG_SET_VAL      (0x00000004)  //!< Bit mask for PCIE_PHY_RTUNE_DEBUG_SET_VAL.

//! @brief Get value of PCIE_PHY_RTUNE_DEBUG_SET_VAL from a register value.
#define BG_PCIE_PHY_RTUNE_DEBUG_SET_VAL(r)   (((r) & BM_PCIE_PHY_RTUNE_DEBUG_SET_VAL) >> BP_PCIE_PHY_RTUNE_DEBUG_SET_VAL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_SET_VAL.
#define BF_PCIE_PHY_RTUNE_DEBUG_SET_VAL(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_DEBUG_SET_VAL) & BM_PCIE_PHY_RTUNE_DEBUG_SET_VAL)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_SET_VAL.
#define BF_PCIE_PHY_RTUNE_DEBUG_SET_VAL(v)   (((v) << BP_PCIE_PHY_RTUNE_DEBUG_SET_VAL) & BM_PCIE_PHY_RTUNE_DEBUG_SET_VAL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_VAL field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_SET_VAL(v)   (HW_PCIE_PHY_RTUNE_DEBUG_WR((HW_PCIE_PHY_RTUNE_DEBUG_RD() & ~BM_PCIE_PHY_RTUNE_DEBUG_SET_VAL) | BF_PCIE_PHY_RTUNE_DEBUG_SET_VAL(v)))
#endif

/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field TYPE[4:3] (RW)
 *
 * Type of manual tuning or register read/write to execute.
 *
 * Values:
 * 00 - ADC, or read/write rt_value
 * 01 - Rx tune, or read/write rx_cal_val (only 6 bits)
 * 10 - Tx tune, or read/write tx_cal_val (only 6 bits)
 * 11 - Resref detect (no affect when triggering SET_VAL fi
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_TYPE      (3)      //!< Bit position for PCIE_PHY_RTUNE_DEBUG_TYPE.
#define BM_PCIE_PHY_RTUNE_DEBUG_TYPE      (0x00000018)  //!< Bit mask for PCIE_PHY_RTUNE_DEBUG_TYPE.

//! @brief Get value of PCIE_PHY_RTUNE_DEBUG_TYPE from a register value.
#define BG_PCIE_PHY_RTUNE_DEBUG_TYPE(r)   (((r) & BM_PCIE_PHY_RTUNE_DEBUG_TYPE) >> BP_PCIE_PHY_RTUNE_DEBUG_TYPE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_TYPE.
#define BF_PCIE_PHY_RTUNE_DEBUG_TYPE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_DEBUG_TYPE) & BM_PCIE_PHY_RTUNE_DEBUG_TYPE)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_TYPE.
#define BF_PCIE_PHY_RTUNE_DEBUG_TYPE(v)   (((v) << BP_PCIE_PHY_RTUNE_DEBUG_TYPE) & BM_PCIE_PHY_RTUNE_DEBUG_TYPE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TYPE field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_TYPE(v)   (HW_PCIE_PHY_RTUNE_DEBUG_WR((HW_PCIE_PHY_RTUNE_DEBUG_RD() & ~BM_PCIE_PHY_RTUNE_DEBUG_TYPE) | BF_PCIE_PHY_RTUNE_DEBUG_TYPE(v)))
#endif


/* --- Register HW_PCIE_PHY_RTUNE_DEBUG, field VALUE[14:5] (RW)
 *
 * Value to use when triggering SET_VAL field. Only the 6 LSB's are used when setting Rx cal or Tx
 * cal values.
 */

#define BP_PCIE_PHY_RTUNE_DEBUG_VALUE      (5)      //!< Bit position for PCIE_PHY_RTUNE_DEBUG_VALUE.
#define BM_PCIE_PHY_RTUNE_DEBUG_VALUE      (0x00007fe0)  //!< Bit mask for PCIE_PHY_RTUNE_DEBUG_VALUE.

//! @brief Get value of PCIE_PHY_RTUNE_DEBUG_VALUE from a register value.
#define BG_PCIE_PHY_RTUNE_DEBUG_VALUE(r)   (((r) & BM_PCIE_PHY_RTUNE_DEBUG_VALUE) >> BP_PCIE_PHY_RTUNE_DEBUG_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_VALUE.
#define BF_PCIE_PHY_RTUNE_DEBUG_VALUE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_DEBUG_VALUE) & BM_PCIE_PHY_RTUNE_DEBUG_VALUE)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_DEBUG_VALUE.
#define BF_PCIE_PHY_RTUNE_DEBUG_VALUE(v)   (((v) << BP_PCIE_PHY_RTUNE_DEBUG_VALUE) & BM_PCIE_PHY_RTUNE_DEBUG_VALUE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE field to a new value.
#define BW_PCIE_PHY_RTUNE_DEBUG_VALUE(v)   (HW_PCIE_PHY_RTUNE_DEBUG_WR((HW_PCIE_PHY_RTUNE_DEBUG_RD() & ~BM_PCIE_PHY_RTUNE_DEBUG_VALUE) | BF_PCIE_PHY_RTUNE_DEBUG_VALUE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RTUNE_STAT -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rtune_stat
{
    reg16_t U;
    struct _hw_pcie_phy_rtune_stat_bitfields
    {
        unsigned short STAT : 10; //!< [9:0] Current value of the register specifed by the RTUNE_DEBUG[TYPE] field.
        unsigned short RESERVED0 : 6; //!< [15:10] Reserved
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

/* --- Register HW_PCIE_PHY_RTUNE_STAT, field STAT[9:0] (RO)
 *
 * Current value of the register specifed by the RTUNE_DEBUG[TYPE] field.
 */

#define BP_PCIE_PHY_RTUNE_STAT_STAT      (0)      //!< Bit position for PCIE_PHY_RTUNE_STAT_STAT.
#define BM_PCIE_PHY_RTUNE_STAT_STAT      (0x000003ff)  //!< Bit mask for PCIE_PHY_RTUNE_STAT_STAT.

//! @brief Get value of PCIE_PHY_RTUNE_STAT_STAT from a register value.
#define BG_PCIE_PHY_RTUNE_STAT_STAT(r)   (((r) & BM_PCIE_PHY_RTUNE_STAT_STAT) >> BP_PCIE_PHY_RTUNE_STAT_STAT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SS_PHASE -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_ss_phase
{
    reg16_t U;
    struct _hw_pcie_phy_ss_phase_bitfields
    {
        unsigned short DTHR : 10; //!< [9:0] Current value of the register specifed by the RTUNE_DEBUG[TYPE] field.
        unsigned short RESERVED0 : 6; //!< [15:10] Reserved
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

/* --- Register HW_PCIE_PHY_SS_PHASE, field DTHR[9:0] (RW)
 *
 * Current value of the register specifed by the RTUNE_DEBUG[TYPE] field.
 */

#define BP_PCIE_PHY_SS_PHASE_DTHR      (0)      //!< Bit position for PCIE_PHY_SS_PHASE_DTHR.
#define BM_PCIE_PHY_SS_PHASE_DTHR      (0x000003ff)  //!< Bit mask for PCIE_PHY_SS_PHASE_DTHR.

//! @brief Get value of PCIE_PHY_SS_PHASE_DTHR from a register value.
#define BG_PCIE_PHY_SS_PHASE_DTHR(r)   (((r) & BM_PCIE_PHY_SS_PHASE_DTHR) >> BP_PCIE_PHY_SS_PHASE_DTHR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SS_PHASE_DTHR.
#define BF_PCIE_PHY_SS_PHASE_DTHR(v)   ((((reg16_t) v) << BP_PCIE_PHY_SS_PHASE_DTHR) & BM_PCIE_PHY_SS_PHASE_DTHR)
#else
//! @brief Format value for bitfield PCIE_PHY_SS_PHASE_DTHR.
#define BF_PCIE_PHY_SS_PHASE_DTHR(v)   (((v) << BP_PCIE_PHY_SS_PHASE_DTHR) & BM_PCIE_PHY_SS_PHASE_DTHR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTHR field to a new value.
#define BW_PCIE_PHY_SS_PHASE_DTHR(v)   (HW_PCIE_PHY_SS_PHASE_WR((HW_PCIE_PHY_SS_PHASE_RD() & ~BM_PCIE_PHY_SS_PHASE_DTHR) | BF_PCIE_PHY_SS_PHASE_DTHR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SS_FREQ -  (RW)
 *
 * Reset value: 0x00003327
 *

 */
typedef union _hw_pcie_phy_ss_freq
{
    reg16_t U;
    struct _hw_pcie_phy_ss_freq_bitfields
    {
        unsigned short FREQ_CNT_INIT : 7; //!< [6:0] Initial frequency counter value. Spread spectrum clocking must be enabled to read from or write to this register.
        unsigned short FREQ_PK : 7; //!< [13:7] Peak frequency value (for changing direction). Spread spectrum clocking must be enabled to read from or write to this register.
        unsigned short FREQ_OVRD : 1; //!< [14] Frequency register override. Spread spectrum clocking must be enabled to read from or write to this register. Must be set for PHASE writes to stick.
        unsigned short RESERVED0 : 1; //!< [15] Reserved
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

/* --- Register HW_PCIE_PHY_SS_FREQ, field FREQ_CNT_INIT[6:0] (RW)
 *
 * Initial frequency counter value. Spread spectrum clocking must be enabled to read from or write
 * to this register.
 */

#define BP_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT      (0)      //!< Bit position for PCIE_PHY_SS_FREQ_FREQ_CNT_INIT.
#define BM_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT      (0x0000007f)  //!< Bit mask for PCIE_PHY_SS_FREQ_FREQ_CNT_INIT.

//! @brief Get value of PCIE_PHY_SS_FREQ_FREQ_CNT_INIT from a register value.
#define BG_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT(r)   (((r) & BM_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT) >> BP_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SS_FREQ_FREQ_CNT_INIT.
#define BF_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT(v)   ((((reg16_t) v) << BP_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT) & BM_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT)
#else
//! @brief Format value for bitfield PCIE_PHY_SS_FREQ_FREQ_CNT_INIT.
#define BF_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT(v)   (((v) << BP_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT) & BM_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_CNT_INIT field to a new value.
#define BW_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT(v)   (HW_PCIE_PHY_SS_FREQ_WR((HW_PCIE_PHY_SS_FREQ_RD() & ~BM_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT) | BF_PCIE_PHY_SS_FREQ_FREQ_CNT_INIT(v)))
#endif

/* --- Register HW_PCIE_PHY_SS_FREQ, field FREQ_PK[13:7] (RW)
 *
 * Peak frequency value (for changing direction). Spread spectrum clocking must be enabled to read
 * from or write to this register.
 */

#define BP_PCIE_PHY_SS_FREQ_FREQ_PK      (7)      //!< Bit position for PCIE_PHY_SS_FREQ_FREQ_PK.
#define BM_PCIE_PHY_SS_FREQ_FREQ_PK      (0x00003f80)  //!< Bit mask for PCIE_PHY_SS_FREQ_FREQ_PK.

//! @brief Get value of PCIE_PHY_SS_FREQ_FREQ_PK from a register value.
#define BG_PCIE_PHY_SS_FREQ_FREQ_PK(r)   (((r) & BM_PCIE_PHY_SS_FREQ_FREQ_PK) >> BP_PCIE_PHY_SS_FREQ_FREQ_PK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SS_FREQ_FREQ_PK.
#define BF_PCIE_PHY_SS_FREQ_FREQ_PK(v)   ((((reg16_t) v) << BP_PCIE_PHY_SS_FREQ_FREQ_PK) & BM_PCIE_PHY_SS_FREQ_FREQ_PK)
#else
//! @brief Format value for bitfield PCIE_PHY_SS_FREQ_FREQ_PK.
#define BF_PCIE_PHY_SS_FREQ_FREQ_PK(v)   (((v) << BP_PCIE_PHY_SS_FREQ_FREQ_PK) & BM_PCIE_PHY_SS_FREQ_FREQ_PK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_PK field to a new value.
#define BW_PCIE_PHY_SS_FREQ_FREQ_PK(v)   (HW_PCIE_PHY_SS_FREQ_WR((HW_PCIE_PHY_SS_FREQ_RD() & ~BM_PCIE_PHY_SS_FREQ_FREQ_PK) | BF_PCIE_PHY_SS_FREQ_FREQ_PK(v)))
#endif

/* --- Register HW_PCIE_PHY_SS_FREQ, field FREQ_OVRD[14] (RW)
 *
 * Frequency register override. Spread spectrum clocking must be enabled to read from or write to
 * this register. Must be set for PHASE writes to stick.
 */

#define BP_PCIE_PHY_SS_FREQ_FREQ_OVRD      (14)      //!< Bit position for PCIE_PHY_SS_FREQ_FREQ_OVRD.
#define BM_PCIE_PHY_SS_FREQ_FREQ_OVRD      (0x00004000)  //!< Bit mask for PCIE_PHY_SS_FREQ_FREQ_OVRD.

//! @brief Get value of PCIE_PHY_SS_FREQ_FREQ_OVRD from a register value.
#define BG_PCIE_PHY_SS_FREQ_FREQ_OVRD(r)   (((r) & BM_PCIE_PHY_SS_FREQ_FREQ_OVRD) >> BP_PCIE_PHY_SS_FREQ_FREQ_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SS_FREQ_FREQ_OVRD.
#define BF_PCIE_PHY_SS_FREQ_FREQ_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_SS_FREQ_FREQ_OVRD) & BM_PCIE_PHY_SS_FREQ_FREQ_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_SS_FREQ_FREQ_OVRD.
#define BF_PCIE_PHY_SS_FREQ_FREQ_OVRD(v)   (((v) << BP_PCIE_PHY_SS_FREQ_FREQ_OVRD) & BM_PCIE_PHY_SS_FREQ_FREQ_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_OVRD field to a new value.
#define BW_PCIE_PHY_SS_FREQ_FREQ_OVRD(v)   (HW_PCIE_PHY_SS_FREQ_WR((HW_PCIE_PHY_SS_FREQ_RD() & ~BM_PCIE_PHY_SS_FREQ_FREQ_OVRD) | BF_PCIE_PHY_SS_FREQ_FREQ_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_ATEOVRD -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_ateovrd
{
    reg16_t U;
    struct _hw_pcie_phy_ateovrd_bitfields
    {
        unsigned short RESERVED0 : 1; //!< [0] Reserved
        unsigned short REF_CLKDIV2 : 1; //!< [1] Override value for SSP ref_clk prescaler.
        unsigned short REF_USB2_EN : 1; //!< [2] Override value for HSPHY ref_clk enable.
        unsigned short ATEOVRD_EN : 1; //!< [3] Override enable for ATE signals.
        unsigned short RESERVED1 : 12; //!< [15:4] Reserved
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

/* --- Register HW_PCIE_PHY_ATEOVRD, field REF_CLKDIV2[1] (RW)
 *
 * Override value for SSP ref_clk prescaler.
 */

#define BP_PCIE_PHY_ATEOVRD_REF_CLKDIV2      (1)      //!< Bit position for PCIE_PHY_ATEOVRD_REF_CLKDIV2.
#define BM_PCIE_PHY_ATEOVRD_REF_CLKDIV2      (0x00000002)  //!< Bit mask for PCIE_PHY_ATEOVRD_REF_CLKDIV2.

//! @brief Get value of PCIE_PHY_ATEOVRD_REF_CLKDIV2 from a register value.
#define BG_PCIE_PHY_ATEOVRD_REF_CLKDIV2(r)   (((r) & BM_PCIE_PHY_ATEOVRD_REF_CLKDIV2) >> BP_PCIE_PHY_ATEOVRD_REF_CLKDIV2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATEOVRD_REF_CLKDIV2.
#define BF_PCIE_PHY_ATEOVRD_REF_CLKDIV2(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATEOVRD_REF_CLKDIV2) & BM_PCIE_PHY_ATEOVRD_REF_CLKDIV2)
#else
//! @brief Format value for bitfield PCIE_PHY_ATEOVRD_REF_CLKDIV2.
#define BF_PCIE_PHY_ATEOVRD_REF_CLKDIV2(v)   (((v) << BP_PCIE_PHY_ATEOVRD_REF_CLKDIV2) & BM_PCIE_PHY_ATEOVRD_REF_CLKDIV2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REF_CLKDIV2 field to a new value.
#define BW_PCIE_PHY_ATEOVRD_REF_CLKDIV2(v)   (HW_PCIE_PHY_ATEOVRD_WR((HW_PCIE_PHY_ATEOVRD_RD() & ~BM_PCIE_PHY_ATEOVRD_REF_CLKDIV2) | BF_PCIE_PHY_ATEOVRD_REF_CLKDIV2(v)))
#endif

/* --- Register HW_PCIE_PHY_ATEOVRD, field REF_USB2_EN[2] (RW)
 *
 * Override value for HSPHY ref_clk enable.
 */

#define BP_PCIE_PHY_ATEOVRD_REF_USB2_EN      (2)      //!< Bit position for PCIE_PHY_ATEOVRD_REF_USB2_EN.
#define BM_PCIE_PHY_ATEOVRD_REF_USB2_EN      (0x00000004)  //!< Bit mask for PCIE_PHY_ATEOVRD_REF_USB2_EN.

//! @brief Get value of PCIE_PHY_ATEOVRD_REF_USB2_EN from a register value.
#define BG_PCIE_PHY_ATEOVRD_REF_USB2_EN(r)   (((r) & BM_PCIE_PHY_ATEOVRD_REF_USB2_EN) >> BP_PCIE_PHY_ATEOVRD_REF_USB2_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATEOVRD_REF_USB2_EN.
#define BF_PCIE_PHY_ATEOVRD_REF_USB2_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATEOVRD_REF_USB2_EN) & BM_PCIE_PHY_ATEOVRD_REF_USB2_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_ATEOVRD_REF_USB2_EN.
#define BF_PCIE_PHY_ATEOVRD_REF_USB2_EN(v)   (((v) << BP_PCIE_PHY_ATEOVRD_REF_USB2_EN) & BM_PCIE_PHY_ATEOVRD_REF_USB2_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REF_USB2_EN field to a new value.
#define BW_PCIE_PHY_ATEOVRD_REF_USB2_EN(v)   (HW_PCIE_PHY_ATEOVRD_WR((HW_PCIE_PHY_ATEOVRD_RD() & ~BM_PCIE_PHY_ATEOVRD_REF_USB2_EN) | BF_PCIE_PHY_ATEOVRD_REF_USB2_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_ATEOVRD, field ATEOVRD_EN[3] (RW)
 *
 * Override enable for ATE signals.
 */

#define BP_PCIE_PHY_ATEOVRD_ATEOVRD_EN      (3)      //!< Bit position for PCIE_PHY_ATEOVRD_ATEOVRD_EN.
#define BM_PCIE_PHY_ATEOVRD_ATEOVRD_EN      (0x00000008)  //!< Bit mask for PCIE_PHY_ATEOVRD_ATEOVRD_EN.

//! @brief Get value of PCIE_PHY_ATEOVRD_ATEOVRD_EN from a register value.
#define BG_PCIE_PHY_ATEOVRD_ATEOVRD_EN(r)   (((r) & BM_PCIE_PHY_ATEOVRD_ATEOVRD_EN) >> BP_PCIE_PHY_ATEOVRD_ATEOVRD_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATEOVRD_ATEOVRD_EN.
#define BF_PCIE_PHY_ATEOVRD_ATEOVRD_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATEOVRD_ATEOVRD_EN) & BM_PCIE_PHY_ATEOVRD_ATEOVRD_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_ATEOVRD_ATEOVRD_EN.
#define BF_PCIE_PHY_ATEOVRD_ATEOVRD_EN(v)   (((v) << BP_PCIE_PHY_ATEOVRD_ATEOVRD_EN) & BM_PCIE_PHY_ATEOVRD_ATEOVRD_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEOVRD_EN field to a new value.
#define BW_PCIE_PHY_ATEOVRD_ATEOVRD_EN(v)   (HW_PCIE_PHY_ATEOVRD_WR((HW_PCIE_PHY_ATEOVRD_RD() & ~BM_PCIE_PHY_ATEOVRD_ATEOVRD_EN) | BF_PCIE_PHY_ATEOVRD_ATEOVRD_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_OVRD_IN_LO -  (RW)
 *
 * Reset value: 0x0000004c
 *

 */
typedef union _hw_pcie_phy_mpll_ovrd_in_lo
{
    reg16_t U;
    struct _hw_pcie_phy_mpll_ovrd_in_lo_bitfields
    {
        unsigned short MPLL_EN : 1; //!< [0] Override value for mpll_en.
        unsigned short MPLL_EN_OVRD : 1; //!< [1] Override enable for mpll_en.
        unsigned short MPLL_MULTIPLIER : 7; //!< [8:2] Override value for mpll_multiplier.
        unsigned short MPLL_MULTIPLIER_OVRD : 1; //!< [9] Override enable for mpll_multiplier.
        unsigned short RTUNE_REQ : 1; //!< [10] Override value for rtune_req.
        unsigned short RTUNE_REQ_OVRD : 1; //!< [11] Override enable for rtune_req.
        unsigned short RES_REQ_IN : 1; //!< [12] Override value for res_req_in.
        unsigned short RES_REQ_IN_OVRD : 1; //!< [13] Override enable for res_req_in.
        unsigned short RES_ACK_IN : 1; //!< [14] Override value for res_ack_in.
        unsigned short RES_ACK_IN_OVRD : 1; //!< [15] Override enable for res_ack_in.
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

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field MPLL_EN[0] (RW)
 *
 * Override value for mpll_en.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN      (0)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN      (0x00000001)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_EN field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field MPLL_EN_OVRD[1] (RW)
 *
 * Override enable for mpll_en.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD      (1)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD      (0x00000002)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_EN_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field MPLL_MULTIPLIER[8:2] (RW)
 *
 * Override value for mpll_multiplier.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER      (2)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER      (0x000001fc)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_MULTIPLIER field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field MPLL_MULTIPLIER_OVRD[9] (RW)
 *
 * Override enable for mpll_multiplier.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD      (9)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD      (0x00000200)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_MULTIPLIER_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_MPLL_MULTIPLIER_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RTUNE_REQ[10] (RW)
 *
 * Override value for rtune_req.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ      (10)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ      (0x00000400)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_REQ field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RTUNE_REQ_OVRD[11] (RW)
 *
 * Override enable for rtune_req.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD      (11)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD      (0x00000800)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_REQ_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_RTUNE_REQ_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RES_REQ_IN[12] (RW)
 *
 * Override value for res_req_in.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN      (12)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN      (0x00001000)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_REQ_IN field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RES_REQ_IN_OVRD[13] (RW)
 *
 * Override enable for res_req_in.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD      (13)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD      (0x00002000)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_REQ_IN_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_REQ_IN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RES_ACK_IN[14] (RW)
 *
 * Override value for res_ack_in.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN      (14)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN      (0x00004000)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_ACK_IN field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVRD_IN_LO, field RES_ACK_IN_OVRD[15] (RW)
 *
 * Override enable for res_ack_in.
 */

#define BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD      (15)      //!< Bit position for PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD.
#define BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD      (0x00008000)  //!< Bit mask for PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD.

//! @brief Get value of PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD from a register value.
#define BG_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD(r)   (((r) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD) >> BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD.
#define BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD(v)   (((v) << BP_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD) & BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_ACK_IN_OVRD field to a new value.
#define BW_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD(v)   (HW_PCIE_PHY_MPLL_OVRD_IN_LO_WR((HW_PCIE_PHY_MPLL_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD) | BF_PCIE_PHY_MPLL_OVRD_IN_LO_RES_ACK_IN_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SSC_OVRD_IN -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_ssc_ovrd_in
{
    reg16_t U;
    struct _hw_pcie_phy_ssc_ovrd_in_bitfields
    {
        unsigned short SSC_REF_CLK_SEL : 8; //!< [7:0] Override value for reference clock scaling.
        unsigned short SSC_RANGE : 2; //!< [9:8] Override value for SSC modulation range.
        unsigned short SSC_EN : 1; //!< [10] Override value for SSC enable.
        unsigned short SSC_OVRD_IN_EN : 1; //!< [11] Override enable for Spread Spectrum generator.
        unsigned short RESERVED0 : 4; //!< [15:12] Reserved
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

/* --- Register HW_PCIE_PHY_SSC_OVRD_IN, field SSC_REF_CLK_SEL[7:0] (RW)
 *
 * Override value for reference clock scaling.
 */

#define BP_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL      (0)      //!< Bit position for PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL.
#define BM_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL      (0x000000ff)  //!< Bit mask for PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL.

//! @brief Get value of PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL from a register value.
#define BG_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL(r)   (((r) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL) >> BP_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL.
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL)
#else
//! @brief Format value for bitfield PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL.
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL(v)   (((v) << BP_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_REF_CLK_SEL field to a new value.
#define BW_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL(v)   (HW_PCIE_PHY_SSC_OVRD_IN_WR((HW_PCIE_PHY_SSC_OVRD_IN_RD() & ~BM_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL) | BF_PCIE_PHY_SSC_OVRD_IN_SSC_REF_CLK_SEL(v)))
#endif

/* --- Register HW_PCIE_PHY_SSC_OVRD_IN, field SSC_RANGE[9:8] (RW)
 *
 * Override value for SSC modulation range.
 */

#define BP_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE      (8)      //!< Bit position for PCIE_PHY_SSC_OVRD_IN_SSC_RANGE.
#define BM_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE      (0x00000300)  //!< Bit mask for PCIE_PHY_SSC_OVRD_IN_SSC_RANGE.

//! @brief Get value of PCIE_PHY_SSC_OVRD_IN_SSC_RANGE from a register value.
#define BG_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE(r)   (((r) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE) >> BP_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SSC_OVRD_IN_SSC_RANGE.
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE(v)   ((((reg16_t) v) << BP_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE)
#else
//! @brief Format value for bitfield PCIE_PHY_SSC_OVRD_IN_SSC_RANGE.
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE(v)   (((v) << BP_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_RANGE field to a new value.
#define BW_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE(v)   (HW_PCIE_PHY_SSC_OVRD_IN_WR((HW_PCIE_PHY_SSC_OVRD_IN_RD() & ~BM_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE) | BF_PCIE_PHY_SSC_OVRD_IN_SSC_RANGE(v)))
#endif

/* --- Register HW_PCIE_PHY_SSC_OVRD_IN, field SSC_EN[10] (RW)
 *
 * Override value for SSC enable.
 */

#define BP_PCIE_PHY_SSC_OVRD_IN_SSC_EN      (10)      //!< Bit position for PCIE_PHY_SSC_OVRD_IN_SSC_EN.
#define BM_PCIE_PHY_SSC_OVRD_IN_SSC_EN      (0x00000400)  //!< Bit mask for PCIE_PHY_SSC_OVRD_IN_SSC_EN.

//! @brief Get value of PCIE_PHY_SSC_OVRD_IN_SSC_EN from a register value.
#define BG_PCIE_PHY_SSC_OVRD_IN_SSC_EN(r)   (((r) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_EN) >> BP_PCIE_PHY_SSC_OVRD_IN_SSC_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SSC_OVRD_IN_SSC_EN.
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_SSC_OVRD_IN_SSC_EN) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_SSC_OVRD_IN_SSC_EN.
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_EN(v)   (((v) << BP_PCIE_PHY_SSC_OVRD_IN_SSC_EN) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_PCIE_PHY_SSC_OVRD_IN_SSC_EN(v)   (HW_PCIE_PHY_SSC_OVRD_IN_WR((HW_PCIE_PHY_SSC_OVRD_IN_RD() & ~BM_PCIE_PHY_SSC_OVRD_IN_SSC_EN) | BF_PCIE_PHY_SSC_OVRD_IN_SSC_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_SSC_OVRD_IN, field SSC_OVRD_IN_EN[11] (RW)
 *
 * Override enable for Spread Spectrum generator.
 */

#define BP_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN      (11)      //!< Bit position for PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN.
#define BM_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN      (0x00000800)  //!< Bit mask for PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN.

//! @brief Get value of PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN from a register value.
#define BG_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN(r)   (((r) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN) >> BP_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN.
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN.
#define BF_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN(v)   (((v) << BP_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN) & BM_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_OVRD_IN_EN field to a new value.
#define BW_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN(v)   (HW_PCIE_PHY_SSC_OVRD_IN_WR((HW_PCIE_PHY_SSC_OVRD_IN_RD() & ~BM_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN) | BF_PCIE_PHY_SSC_OVRD_IN_SSC_OVRD_IN_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_BS_OVRD_IN -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_bs_ovrd_in
{
    reg16_t U;
    struct _hw_pcie_phy_bs_ovrd_in_bitfields
    {
        unsigned short IN : 1; //!< [0] Override value for bs_shift_dr.
        unsigned short SHIFT_DR : 1; //!< [1] Override value for bs_shift_dr.
        unsigned short CAPTURE_DR : 1; //!< [2] Override value for bs_capture_dr
        unsigned short UPDATE_DR : 1; //!< [3] Override value for bs_update_dr.
        unsigned short PRELOAD : 1; //!< [4] Override value for bs_preload.
        unsigned short EXTEST : 1; //!< [5] Override value for bs_extest.
        unsigned short EXTEST_AC : 1; //!< [6] Override value for bs_extest_ac.
        unsigned short CLAMP : 1; //!< [7] Override value for bs_clamp.
        unsigned short HIGHZ : 1; //!< [8] Override value for bs_highz.
        unsigned short INIT : 1; //!< [9] Override value for bs_init.
        unsigned short INVERT : 1; //!< [10] Override value for bs_invert.
        unsigned short EN : 1; //!< [11] Enables override values for all inputs controlled by this register.
        unsigned short RESERVED0 : 4; //!< [15:12] Reserved.
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

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field IN[0] (RW)
 *
 * Override value for bs_shift_dr.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_IN      (0)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_IN.
#define BM_PCIE_PHY_BS_OVRD_IN_IN      (0x00000001)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_IN.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_IN from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_IN(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_IN) >> BP_PCIE_PHY_BS_OVRD_IN_IN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_IN.
#define BF_PCIE_PHY_BS_OVRD_IN_IN(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_IN) & BM_PCIE_PHY_BS_OVRD_IN_IN)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_IN.
#define BF_PCIE_PHY_BS_OVRD_IN_IN(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_IN) & BM_PCIE_PHY_BS_OVRD_IN_IN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IN field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_IN(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_IN) | BF_PCIE_PHY_BS_OVRD_IN_IN(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field SHIFT_DR[1] (RW)
 *
 * Override value for bs_shift_dr.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_SHIFT_DR      (1)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_SHIFT_DR.
#define BM_PCIE_PHY_BS_OVRD_IN_SHIFT_DR      (0x00000002)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_SHIFT_DR.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_SHIFT_DR from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_SHIFT_DR(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_SHIFT_DR) >> BP_PCIE_PHY_BS_OVRD_IN_SHIFT_DR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_SHIFT_DR.
#define BF_PCIE_PHY_BS_OVRD_IN_SHIFT_DR(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_SHIFT_DR) & BM_PCIE_PHY_BS_OVRD_IN_SHIFT_DR)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_SHIFT_DR.
#define BF_PCIE_PHY_BS_OVRD_IN_SHIFT_DR(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_SHIFT_DR) & BM_PCIE_PHY_BS_OVRD_IN_SHIFT_DR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SHIFT_DR field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_SHIFT_DR(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_SHIFT_DR) | BF_PCIE_PHY_BS_OVRD_IN_SHIFT_DR(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field CAPTURE_DR[2] (RW)
 *
 * Override value for bs_capture_dr
 */

#define BP_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR      (2)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_CAPTURE_DR.
#define BM_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR      (0x00000004)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_CAPTURE_DR.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_CAPTURE_DR from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR) >> BP_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_CAPTURE_DR.
#define BF_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR) & BM_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_CAPTURE_DR.
#define BF_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR) & BM_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CAPTURE_DR field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR) | BF_PCIE_PHY_BS_OVRD_IN_CAPTURE_DR(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field UPDATE_DR[3] (RW)
 *
 * Override value for bs_update_dr.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_UPDATE_DR      (3)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_UPDATE_DR.
#define BM_PCIE_PHY_BS_OVRD_IN_UPDATE_DR      (0x00000008)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_UPDATE_DR.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_UPDATE_DR from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_UPDATE_DR(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_UPDATE_DR) >> BP_PCIE_PHY_BS_OVRD_IN_UPDATE_DR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_UPDATE_DR.
#define BF_PCIE_PHY_BS_OVRD_IN_UPDATE_DR(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_UPDATE_DR) & BM_PCIE_PHY_BS_OVRD_IN_UPDATE_DR)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_UPDATE_DR.
#define BF_PCIE_PHY_BS_OVRD_IN_UPDATE_DR(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_UPDATE_DR) & BM_PCIE_PHY_BS_OVRD_IN_UPDATE_DR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPDATE_DR field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_UPDATE_DR(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_UPDATE_DR) | BF_PCIE_PHY_BS_OVRD_IN_UPDATE_DR(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field PRELOAD[4] (RW)
 *
 * Override value for bs_preload.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_PRELOAD      (4)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_PRELOAD.
#define BM_PCIE_PHY_BS_OVRD_IN_PRELOAD      (0x00000010)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_PRELOAD.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_PRELOAD from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_PRELOAD(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_PRELOAD) >> BP_PCIE_PHY_BS_OVRD_IN_PRELOAD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_PRELOAD.
#define BF_PCIE_PHY_BS_OVRD_IN_PRELOAD(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_PRELOAD) & BM_PCIE_PHY_BS_OVRD_IN_PRELOAD)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_PRELOAD.
#define BF_PCIE_PHY_BS_OVRD_IN_PRELOAD(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_PRELOAD) & BM_PCIE_PHY_BS_OVRD_IN_PRELOAD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRELOAD field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_PRELOAD(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_PRELOAD) | BF_PCIE_PHY_BS_OVRD_IN_PRELOAD(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field EXTEST[5] (RW)
 *
 * Override value for bs_extest.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_EXTEST      (5)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_EXTEST.
#define BM_PCIE_PHY_BS_OVRD_IN_EXTEST      (0x00000020)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_EXTEST.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_EXTEST from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_EXTEST(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST) >> BP_PCIE_PHY_BS_OVRD_IN_EXTEST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_EXTEST.
#define BF_PCIE_PHY_BS_OVRD_IN_EXTEST(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_EXTEST) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_EXTEST.
#define BF_PCIE_PHY_BS_OVRD_IN_EXTEST(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_EXTEST) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTEST field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_EXTEST(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_EXTEST) | BF_PCIE_PHY_BS_OVRD_IN_EXTEST(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field EXTEST_AC[6] (RW)
 *
 * Override value for bs_extest_ac.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_EXTEST_AC      (6)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_EXTEST_AC.
#define BM_PCIE_PHY_BS_OVRD_IN_EXTEST_AC      (0x00000040)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_EXTEST_AC.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_EXTEST_AC from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_EXTEST_AC(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST_AC) >> BP_PCIE_PHY_BS_OVRD_IN_EXTEST_AC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_EXTEST_AC.
#define BF_PCIE_PHY_BS_OVRD_IN_EXTEST_AC(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_EXTEST_AC) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST_AC)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_EXTEST_AC.
#define BF_PCIE_PHY_BS_OVRD_IN_EXTEST_AC(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_EXTEST_AC) & BM_PCIE_PHY_BS_OVRD_IN_EXTEST_AC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTEST_AC field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_EXTEST_AC(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_EXTEST_AC) | BF_PCIE_PHY_BS_OVRD_IN_EXTEST_AC(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field CLAMP[7] (RW)
 *
 * Override value for bs_clamp.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_CLAMP      (7)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_CLAMP.
#define BM_PCIE_PHY_BS_OVRD_IN_CLAMP      (0x00000080)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_CLAMP.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_CLAMP from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_CLAMP(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_CLAMP) >> BP_PCIE_PHY_BS_OVRD_IN_CLAMP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_CLAMP.
#define BF_PCIE_PHY_BS_OVRD_IN_CLAMP(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_CLAMP) & BM_PCIE_PHY_BS_OVRD_IN_CLAMP)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_CLAMP.
#define BF_PCIE_PHY_BS_OVRD_IN_CLAMP(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_CLAMP) & BM_PCIE_PHY_BS_OVRD_IN_CLAMP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLAMP field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_CLAMP(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_CLAMP) | BF_PCIE_PHY_BS_OVRD_IN_CLAMP(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field HIGHZ[8] (RW)
 *
 * Override value for bs_highz.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_HIGHZ      (8)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_HIGHZ.
#define BM_PCIE_PHY_BS_OVRD_IN_HIGHZ      (0x00000100)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_HIGHZ.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_HIGHZ from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_HIGHZ(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_HIGHZ) >> BP_PCIE_PHY_BS_OVRD_IN_HIGHZ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_HIGHZ.
#define BF_PCIE_PHY_BS_OVRD_IN_HIGHZ(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_HIGHZ) & BM_PCIE_PHY_BS_OVRD_IN_HIGHZ)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_HIGHZ.
#define BF_PCIE_PHY_BS_OVRD_IN_HIGHZ(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_HIGHZ) & BM_PCIE_PHY_BS_OVRD_IN_HIGHZ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HIGHZ field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_HIGHZ(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_HIGHZ) | BF_PCIE_PHY_BS_OVRD_IN_HIGHZ(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field INIT[9] (RW)
 *
 * Override value for bs_init.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_INIT      (9)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_INIT.
#define BM_PCIE_PHY_BS_OVRD_IN_INIT      (0x00000200)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_INIT.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_INIT from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_INIT(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_INIT) >> BP_PCIE_PHY_BS_OVRD_IN_INIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_INIT.
#define BF_PCIE_PHY_BS_OVRD_IN_INIT(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_INIT) & BM_PCIE_PHY_BS_OVRD_IN_INIT)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_INIT.
#define BF_PCIE_PHY_BS_OVRD_IN_INIT(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_INIT) & BM_PCIE_PHY_BS_OVRD_IN_INIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INIT field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_INIT(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_INIT) | BF_PCIE_PHY_BS_OVRD_IN_INIT(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field INVERT[10] (RW)
 *
 * Override value for bs_invert.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_INVERT      (10)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_INVERT.
#define BM_PCIE_PHY_BS_OVRD_IN_INVERT      (0x00000400)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_INVERT.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_INVERT from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_INVERT(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_INVERT) >> BP_PCIE_PHY_BS_OVRD_IN_INVERT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_INVERT.
#define BF_PCIE_PHY_BS_OVRD_IN_INVERT(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_INVERT) & BM_PCIE_PHY_BS_OVRD_IN_INVERT)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_INVERT.
#define BF_PCIE_PHY_BS_OVRD_IN_INVERT(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_INVERT) & BM_PCIE_PHY_BS_OVRD_IN_INVERT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INVERT field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_INVERT(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_INVERT) | BF_PCIE_PHY_BS_OVRD_IN_INVERT(v)))
#endif

/* --- Register HW_PCIE_PHY_BS_OVRD_IN, field EN[11] (RW)
 *
 * Enables override values for all inputs controlled by this register.
 */

#define BP_PCIE_PHY_BS_OVRD_IN_EN      (11)      //!< Bit position for PCIE_PHY_BS_OVRD_IN_EN.
#define BM_PCIE_PHY_BS_OVRD_IN_EN      (0x00000800)  //!< Bit mask for PCIE_PHY_BS_OVRD_IN_EN.

//! @brief Get value of PCIE_PHY_BS_OVRD_IN_EN from a register value.
#define BG_PCIE_PHY_BS_OVRD_IN_EN(r)   (((r) & BM_PCIE_PHY_BS_OVRD_IN_EN) >> BP_PCIE_PHY_BS_OVRD_IN_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_EN.
#define BF_PCIE_PHY_BS_OVRD_IN_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_BS_OVRD_IN_EN) & BM_PCIE_PHY_BS_OVRD_IN_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_BS_OVRD_IN_EN.
#define BF_PCIE_PHY_BS_OVRD_IN_EN(v)   (((v) << BP_PCIE_PHY_BS_OVRD_IN_EN) & BM_PCIE_PHY_BS_OVRD_IN_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_PCIE_PHY_BS_OVRD_IN_EN(v)   (HW_PCIE_PHY_BS_OVRD_IN_WR((HW_PCIE_PHY_BS_OVRD_IN_RD() & ~BM_PCIE_PHY_BS_OVRD_IN_EN) | BF_PCIE_PHY_BS_OVRD_IN_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_LEVEL_OVRD_IN -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_level_ovrd_in
{
    reg16_t U;
    struct _hw_pcie_phy_level_ovrd_in_bitfields
    {
        unsigned short LOS_LEVEL : 5; //!< [4:0] Override value for los_level.
        unsigned short ACJT_LEVEL : 5; //!< [9:5] Override value for acjt_level.
        unsigned short EN : 1; //!< [10] Enables override values for all inputs controlled by this register.
        unsigned short RESERVED0 : 5; //!< [15:11] Reserved.
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

/* --- Register HW_PCIE_PHY_LEVEL_OVRD_IN, field LOS_LEVEL[4:0] (RW)
 *
 * Override value for los_level.
 */

#define BP_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL      (0)      //!< Bit position for PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL.
#define BM_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL      (0x0000001f)  //!< Bit mask for PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL.

//! @brief Get value of PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL from a register value.
#define BG_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL(r)   (((r) & BM_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL) >> BP_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL.
#define BF_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL) & BM_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL)
#else
//! @brief Format value for bitfield PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL.
#define BF_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL(v)   (((v) << BP_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL) & BM_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS_LEVEL field to a new value.
#define BW_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL(v)   (HW_PCIE_PHY_LEVEL_OVRD_IN_WR((HW_PCIE_PHY_LEVEL_OVRD_IN_RD() & ~BM_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL) | BF_PCIE_PHY_LEVEL_OVRD_IN_LOS_LEVEL(v)))
#endif

/* --- Register HW_PCIE_PHY_LEVEL_OVRD_IN, field ACJT_LEVEL[9:5] (RW)
 *
 * Override value for acjt_level.
 */

#define BP_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL      (5)      //!< Bit position for PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL.
#define BM_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL      (0x000003e0)  //!< Bit mask for PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL.

//! @brief Get value of PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL from a register value.
#define BG_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL(r)   (((r) & BM_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL) >> BP_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL.
#define BF_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL) & BM_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL)
#else
//! @brief Format value for bitfield PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL.
#define BF_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL(v)   (((v) << BP_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL) & BM_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACJT_LEVEL field to a new value.
#define BW_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL(v)   (HW_PCIE_PHY_LEVEL_OVRD_IN_WR((HW_PCIE_PHY_LEVEL_OVRD_IN_RD() & ~BM_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL) | BF_PCIE_PHY_LEVEL_OVRD_IN_ACJT_LEVEL(v)))
#endif

/* --- Register HW_PCIE_PHY_LEVEL_OVRD_IN, field EN[10] (RW)
 *
 * Enables override values for all inputs controlled by this register.
 */

#define BP_PCIE_PHY_LEVEL_OVRD_IN_EN      (10)      //!< Bit position for PCIE_PHY_LEVEL_OVRD_IN_EN.
#define BM_PCIE_PHY_LEVEL_OVRD_IN_EN      (0x00000400)  //!< Bit mask for PCIE_PHY_LEVEL_OVRD_IN_EN.

//! @brief Get value of PCIE_PHY_LEVEL_OVRD_IN_EN from a register value.
#define BG_PCIE_PHY_LEVEL_OVRD_IN_EN(r)   (((r) & BM_PCIE_PHY_LEVEL_OVRD_IN_EN) >> BP_PCIE_PHY_LEVEL_OVRD_IN_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_LEVEL_OVRD_IN_EN.
#define BF_PCIE_PHY_LEVEL_OVRD_IN_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_LEVEL_OVRD_IN_EN) & BM_PCIE_PHY_LEVEL_OVRD_IN_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_LEVEL_OVRD_IN_EN.
#define BF_PCIE_PHY_LEVEL_OVRD_IN_EN(v)   (((v) << BP_PCIE_PHY_LEVEL_OVRD_IN_EN) & BM_PCIE_PHY_LEVEL_OVRD_IN_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_PCIE_PHY_LEVEL_OVRD_IN_EN(v)   (HW_PCIE_PHY_LEVEL_OVRD_IN_WR((HW_PCIE_PHY_LEVEL_OVRD_IN_RD() & ~BM_PCIE_PHY_LEVEL_OVRD_IN_EN) | BF_PCIE_PHY_LEVEL_OVRD_IN_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SUP_OVRD_OUT -  (RW)
 *
 * Reset value: 0x00000101
 *

 */
typedef union _hw_pcie_phy_sup_ovrd_out
{
    reg16_t U;
    struct _hw_pcie_phy_sup_ovrd_out_bitfields
    {
        unsigned short RES_ACK_OUT : 1; //!< [0] Override value for res_ack_out output.
        unsigned short RES_ACK_OUT_OVRD : 1; //!< [1] Override enable for res_ack_out output.
        unsigned short RES_REQ_OUT : 1; //!< [2] Override value for res_req_out output.
        unsigned short RES_REQ_OUT_OVRD : 1; //!< [3] Override enable for res_req_out output.
        unsigned short RTUNE_ACK : 1; //!< [4] Override value for rtune_ack output.
        unsigned short RTUNE_ACK_OVRD : 1; //!< [5] Override enable for rtune_ack output.
        unsigned short BS_OUT : 1; //!< [6] Override value for bs_out output.
        unsigned short BS_OUT_OVRD : 1; //!< [7] Override enable for bs_out output.
        unsigned short MPLL_STATE : 1; //!< [8] Override value for mpll_state output.
        unsigned short MPLL_STATE_OVRD : 1; //!< [9] Override enable for mpll_state output.
        unsigned short RESERVED0 : 6; //!< [15:10] Reserved.
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

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RES_ACK_OUT[0] (RW)
 *
 * Override value for res_ack_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT      (0)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT.
#define BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT      (0x00000001)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT) >> BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_ACK_OUT field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT) | BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RES_ACK_OUT_OVRD[1] (RW)
 *
 * Override enable for res_ack_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD      (1)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD.
#define BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD      (0x00000002)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD) >> BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_ACK_OUT_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD) | BF_PCIE_PHY_SUP_OVRD_OUT_RES_ACK_OUT_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RES_REQ_OUT[2] (RW)
 *
 * Override value for res_req_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT      (2)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT.
#define BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT      (0x00000004)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT) >> BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_REQ_OUT field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT) | BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RES_REQ_OUT_OVRD[3] (RW)
 *
 * Override enable for res_req_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD      (3)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD.
#define BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD      (0x00000008)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD) >> BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RES_REQ_OUT_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD) | BF_PCIE_PHY_SUP_OVRD_OUT_RES_REQ_OUT_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RTUNE_ACK[4] (RW)
 *
 * Override value for rtune_ack output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK      (4)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK.
#define BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK      (0x00000010)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK) >> BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_ACK field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK) | BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field RTUNE_ACK_OVRD[5] (RW)
 *
 * Override enable for rtune_ack output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD      (5)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD.
#define BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD      (0x00000020)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD) >> BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_ACK_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD) | BF_PCIE_PHY_SUP_OVRD_OUT_RTUNE_ACK_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field BS_OUT[6] (RW)
 *
 * Override value for bs_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT      (6)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_BS_OUT.
#define BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT      (0x00000040)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_BS_OUT.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_BS_OUT from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_BS_OUT(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT) >> BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_BS_OUT.
#define BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_BS_OUT.
#define BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BS_OUT field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_BS_OUT(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT) | BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field BS_OUT_OVRD[7] (RW)
 *
 * Override enable for bs_out output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD      (7)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD.
#define BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD      (0x00000080)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD) >> BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BS_OUT_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD) | BF_PCIE_PHY_SUP_OVRD_OUT_BS_OUT_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field MPLL_STATE[8] (RW)
 *
 * Override value for mpll_state output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE      (8)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE.
#define BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE      (0x00000100)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE) >> BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE.
#define BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE.
#define BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_STATE field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE) | BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE(v)))
#endif

/* --- Register HW_PCIE_PHY_SUP_OVRD_OUT, field MPLL_STATE_OVRD[9] (RW)
 *
 * Override enable for mpll_state output.
 */

#define BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD      (9)      //!< Bit position for PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD.
#define BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD      (0x00000200)  //!< Bit mask for PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD.

//! @brief Get value of PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD from a register value.
#define BG_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD(r)   (((r) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD) >> BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD.
#define BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD(v)   (((v) << BP_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD) & BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_STATE_OVRD field to a new value.
#define BW_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD(v)   (HW_PCIE_PHY_SUP_OVRD_OUT_WR((HW_PCIE_PHY_SUP_OVRD_OUT_RD() & ~BM_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD) | BF_PCIE_PHY_SUP_OVRD_OUT_MPLL_STATE_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_ASIC_IN -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_mpll_asic_in
{
    reg16_t U;
    struct _hw_pcie_phy_mpll_asic_in_bitfields
    {
        unsigned short MPLL_EN : 1; //!< [0] Value from ASIC for mpll_en.
        unsigned short MPLL_MULTIPLIER : 7; //!< [7:1] Value from ASIC for mpll_multiplier.
        unsigned short RTUNE_REQ : 1; //!< [8] Value from ASIC for rtune_req.
        unsigned short RES_REQ_IN : 1; //!< [9] Value from ASIC for res_req_in.
        unsigned short RES_ACK_IN : 1; //!< [10] Value from ASIC for res_ack_in.
        unsigned short MPLL_QWORD_CLK_EN : 1; //!< [11] Value from ASIC for mpll_qword_clk_en.
        unsigned short MPLL_DWORD_CLK_EN : 1; //!< [12] Value from ASIC for mpll_dword_clk_en.
        unsigned short MPLL_WORD_CLK_EN : 1; //!< [13] Value from ASIC for mpll_word_clk_en.
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved.
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

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_EN[0] (RO)
 *
 * Value from ASIC for mpll_en.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_EN      (0)      //!< Bit position for PCIE_PHY_MPLL_ASIC_IN_MPLL_EN.
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_EN      (0x00000001)  //!< Bit mask for PCIE_PHY_MPLL_ASIC_IN_MPLL_EN.

//! @brief Get value of PCIE_PHY_MPLL_ASIC_IN_MPLL_EN from a register value.
#define BG_PCIE_PHY_MPLL_ASIC_IN_MPLL_EN(r)   (((r) & BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_EN) >> BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_EN)

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_MULTIPLIER[7:1] (RO)
 *
 * Value from ASIC for mpll_multiplier.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER      (1)      //!< Bit position for PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER.
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER      (0x000000fe)  //!< Bit mask for PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER.

//! @brief Get value of PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER from a register value.
#define BG_PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER(r)   (((r) & BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER) >> BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_MULTIPLIER)

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field RTUNE_REQ[8] (RO)
 *
 * Value from ASIC for rtune_req.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ      (8)      //!< Bit position for PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ.
#define BM_PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ      (0x00000100)  //!< Bit mask for PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ.

//! @brief Get value of PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ from a register value.
#define BG_PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ(r)   (((r) & BM_PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ) >> BP_PCIE_PHY_MPLL_ASIC_IN_RTUNE_REQ)

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field RES_REQ_IN[9] (RO)
 *
 * Value from ASIC for res_req_in.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN      (9)      //!< Bit position for PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN.
#define BM_PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN      (0x00000200)  //!< Bit mask for PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN.

//! @brief Get value of PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN from a register value.
#define BG_PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN(r)   (((r) & BM_PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN) >> BP_PCIE_PHY_MPLL_ASIC_IN_RES_REQ_IN)

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field RES_ACK_IN[10] (RO)
 *
 * Value from ASIC for res_ack_in.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN      (10)      //!< Bit position for PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN.
#define BM_PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN      (0x00000400)  //!< Bit mask for PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN.

//! @brief Get value of PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN from a register value.
#define BG_PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN(r)   (((r) & BM_PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN) >> BP_PCIE_PHY_MPLL_ASIC_IN_RES_ACK_IN)

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_QWORD_CLK_EN[11] (RO)
 *
 * Value from ASIC for mpll_qword_clk_en.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN      (11)      //!< Bit position for PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN.
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN      (0x00000800)  //!< Bit mask for PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN.

//! @brief Get value of PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN from a register value.
#define BG_PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN(r)   (((r) & BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN) >> BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_QWORD_CLK_EN)

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_DWORD_CLK_EN[12] (RO)
 *
 * Value from ASIC for mpll_dword_clk_en.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN      (12)      //!< Bit position for PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN.
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN      (0x00001000)  //!< Bit mask for PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN.

//! @brief Get value of PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN from a register value.
#define BG_PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN(r)   (((r) & BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN) >> BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_DWORD_CLK_EN)

/* --- Register HW_PCIE_PHY_MPLL_ASIC_IN, field MPLL_WORD_CLK_EN[13] (RO)
 *
 * Value from ASIC for mpll_word_clk_en.
 */

#define BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN      (13)      //!< Bit position for PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN.
#define BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN      (0x00002000)  //!< Bit mask for PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN.

//! @brief Get value of PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN from a register value.
#define BG_PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN(r)   (((r) & BM_PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN) >> BP_PCIE_PHY_MPLL_ASIC_IN_MPLL_WORD_CLK_EN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_BS_ASIC_IN -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_bs_asic_in
{
    reg16_t U;
    struct _hw_pcie_phy_bs_asic_in_bitfields
    {
        unsigned short IN : 1; //!< [0] Value from ASIC for bs_in.
        unsigned short SHIFT_DR : 1; //!< [1] Value from ASIC for bs_shift_dr.
        unsigned short CAPTURE_DR : 1; //!< [2] Value from ASIC for bs_capture_dr.
        unsigned short UPDATE_DR : 1; //!< [3] Value from ASIC for bs_update_dr.
        unsigned short PRELOAD : 1; //!< [4] Value from ASIC for bs_preload.
        unsigned short EXTEST : 1; //!< [5] Value from ASIC for bs_extest.
        unsigned short EXTEST_AC : 1; //!< [6] Value from ASIC for bs_extest_ac.
        unsigned short CLAMP : 1; //!< [7] Value from ASIC for bs_clamp.
        unsigned short HIGHZ : 1; //!< [8] Value from ASIC for bs_highz.
        unsigned short INIT : 1; //!< [9] Value from ASIC for bs_init.
        unsigned short INVERT : 1; //!< [10] Value from ASIC for bs_invert.
        unsigned short RESERVED0 : 5; //!< [15:11] Reserved.
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

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field IN[0] (RO)
 *
 * Value from ASIC for bs_in.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_IN      (0)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_IN.
#define BM_PCIE_PHY_BS_ASIC_IN_IN      (0x00000001)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_IN.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_IN from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_IN(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_IN) >> BP_PCIE_PHY_BS_ASIC_IN_IN)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field SHIFT_DR[1] (RO)
 *
 * Value from ASIC for bs_shift_dr.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_SHIFT_DR      (1)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_SHIFT_DR.
#define BM_PCIE_PHY_BS_ASIC_IN_SHIFT_DR      (0x00000002)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_SHIFT_DR.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_SHIFT_DR from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_SHIFT_DR(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_SHIFT_DR) >> BP_PCIE_PHY_BS_ASIC_IN_SHIFT_DR)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field CAPTURE_DR[2] (RO)
 *
 * Value from ASIC for bs_capture_dr.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_CAPTURE_DR      (2)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_CAPTURE_DR.
#define BM_PCIE_PHY_BS_ASIC_IN_CAPTURE_DR      (0x00000004)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_CAPTURE_DR.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_CAPTURE_DR from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_CAPTURE_DR(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_CAPTURE_DR) >> BP_PCIE_PHY_BS_ASIC_IN_CAPTURE_DR)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field UPDATE_DR[3] (RO)
 *
 * Value from ASIC for bs_update_dr.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_UPDATE_DR      (3)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_UPDATE_DR.
#define BM_PCIE_PHY_BS_ASIC_IN_UPDATE_DR      (0x00000008)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_UPDATE_DR.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_UPDATE_DR from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_UPDATE_DR(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_UPDATE_DR) >> BP_PCIE_PHY_BS_ASIC_IN_UPDATE_DR)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field PRELOAD[4] (RO)
 *
 * Value from ASIC for bs_preload.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_PRELOAD      (4)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_PRELOAD.
#define BM_PCIE_PHY_BS_ASIC_IN_PRELOAD      (0x00000010)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_PRELOAD.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_PRELOAD from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_PRELOAD(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_PRELOAD) >> BP_PCIE_PHY_BS_ASIC_IN_PRELOAD)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field EXTEST[5] (RO)
 *
 * Value from ASIC for bs_extest.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_EXTEST      (5)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_EXTEST.
#define BM_PCIE_PHY_BS_ASIC_IN_EXTEST      (0x00000020)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_EXTEST.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_EXTEST from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_EXTEST(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_EXTEST) >> BP_PCIE_PHY_BS_ASIC_IN_EXTEST)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field EXTEST_AC[6] (RO)
 *
 * Value from ASIC for bs_extest_ac.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_EXTEST_AC      (6)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_EXTEST_AC.
#define BM_PCIE_PHY_BS_ASIC_IN_EXTEST_AC      (0x00000040)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_EXTEST_AC.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_EXTEST_AC from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_EXTEST_AC(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_EXTEST_AC) >> BP_PCIE_PHY_BS_ASIC_IN_EXTEST_AC)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field CLAMP[7] (RO)
 *
 * Value from ASIC for bs_clamp.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_CLAMP      (7)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_CLAMP.
#define BM_PCIE_PHY_BS_ASIC_IN_CLAMP      (0x00000080)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_CLAMP.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_CLAMP from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_CLAMP(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_CLAMP) >> BP_PCIE_PHY_BS_ASIC_IN_CLAMP)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field HIGHZ[8] (RO)
 *
 * Value from ASIC for bs_highz.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_HIGHZ      (8)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_HIGHZ.
#define BM_PCIE_PHY_BS_ASIC_IN_HIGHZ      (0x00000100)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_HIGHZ.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_HIGHZ from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_HIGHZ(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_HIGHZ) >> BP_PCIE_PHY_BS_ASIC_IN_HIGHZ)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field INIT[9] (RO)
 *
 * Value from ASIC for bs_init.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_INIT      (9)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_INIT.
#define BM_PCIE_PHY_BS_ASIC_IN_INIT      (0x00000200)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_INIT.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_INIT from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_INIT(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_INIT) >> BP_PCIE_PHY_BS_ASIC_IN_INIT)

/* --- Register HW_PCIE_PHY_BS_ASIC_IN, field INVERT[10] (RO)
 *
 * Value from ASIC for bs_invert.
 */

#define BP_PCIE_PHY_BS_ASIC_IN_INVERT      (10)      //!< Bit position for PCIE_PHY_BS_ASIC_IN_INVERT.
#define BM_PCIE_PHY_BS_ASIC_IN_INVERT      (0x00000400)  //!< Bit mask for PCIE_PHY_BS_ASIC_IN_INVERT.

//! @brief Get value of PCIE_PHY_BS_ASIC_IN_INVERT from a register value.
#define BG_PCIE_PHY_BS_ASIC_IN_INVERT(r)   (((r) & BM_PCIE_PHY_BS_ASIC_IN_INVERT) >> BP_PCIE_PHY_BS_ASIC_IN_INVERT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_LEVEL_ASIC_IN -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_level_asic_in
{
    reg16_t U;
    struct _hw_pcie_phy_level_asic_in_bitfields
    {
        unsigned short LOS_LEVEL : 5; //!< [4:0] Value from ASIC for los_level.
        unsigned short ACJT_LEVEL : 5; //!< [9:5] Value from ASIC for acjt_level.
        unsigned short RESERVED0 : 6; //!< [15:10] Reserved.
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

/* --- Register HW_PCIE_PHY_LEVEL_ASIC_IN, field LOS_LEVEL[4:0] (RO)
 *
 * Value from ASIC for los_level.
 */

#define BP_PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL      (0)      //!< Bit position for PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL.
#define BM_PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL      (0x0000001f)  //!< Bit mask for PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL.

//! @brief Get value of PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL from a register value.
#define BG_PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL(r)   (((r) & BM_PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL) >> BP_PCIE_PHY_LEVEL_ASIC_IN_LOS_LEVEL)

/* --- Register HW_PCIE_PHY_LEVEL_ASIC_IN, field ACJT_LEVEL[9:5] (RO)
 *
 * Value from ASIC for acjt_level.
 */

#define BP_PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL      (5)      //!< Bit position for PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL.
#define BM_PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL      (0x000003e0)  //!< Bit mask for PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL.

//! @brief Get value of PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL from a register value.
#define BG_PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL(r)   (((r) & BM_PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL) >> BP_PCIE_PHY_LEVEL_ASIC_IN_ACJT_LEVEL)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SSC_ASIC_IN -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_ssc_asic_in
{
    reg16_t U;
    struct _hw_pcie_phy_ssc_asic_in_bitfields
    {
        unsigned short FSEL : 3; //!< [2:0] Value from ASIC for fsel.
        unsigned short SSC_REF_CLK_SEL : 8; //!< [10:3] Value from ASIC for ssc_ref_clk_sel
        unsigned short SSC_RANGE : 2; //!< [12:11] Value from ASIC for ssc_range.
        unsigned short SS_EN : 1; //!< [13] Value from ASIC for ssc_en.
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved.
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

/* --- Register HW_PCIE_PHY_SSC_ASIC_IN, field FSEL[2:0] (RO)
 *
 * Value from ASIC for fsel.
 */

#define BP_PCIE_PHY_SSC_ASIC_IN_FSEL      (0)      //!< Bit position for PCIE_PHY_SSC_ASIC_IN_FSEL.
#define BM_PCIE_PHY_SSC_ASIC_IN_FSEL      (0x00000007)  //!< Bit mask for PCIE_PHY_SSC_ASIC_IN_FSEL.

//! @brief Get value of PCIE_PHY_SSC_ASIC_IN_FSEL from a register value.
#define BG_PCIE_PHY_SSC_ASIC_IN_FSEL(r)   (((r) & BM_PCIE_PHY_SSC_ASIC_IN_FSEL) >> BP_PCIE_PHY_SSC_ASIC_IN_FSEL)

/* --- Register HW_PCIE_PHY_SSC_ASIC_IN, field SSC_REF_CLK_SEL[10:3] (RO)
 *
 * Value from ASIC for ssc_ref_clk_sel
 */

#define BP_PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL      (3)      //!< Bit position for PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL.
#define BM_PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL      (0x000007f8)  //!< Bit mask for PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL.

//! @brief Get value of PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL from a register value.
#define BG_PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL(r)   (((r) & BM_PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL) >> BP_PCIE_PHY_SSC_ASIC_IN_SSC_REF_CLK_SEL)

/* --- Register HW_PCIE_PHY_SSC_ASIC_IN, field SSC_RANGE[12:11] (RO)
 *
 * Value from ASIC for ssc_range.
 */

#define BP_PCIE_PHY_SSC_ASIC_IN_SSC_RANGE      (11)      //!< Bit position for PCIE_PHY_SSC_ASIC_IN_SSC_RANGE.
#define BM_PCIE_PHY_SSC_ASIC_IN_SSC_RANGE      (0x00001800)  //!< Bit mask for PCIE_PHY_SSC_ASIC_IN_SSC_RANGE.

//! @brief Get value of PCIE_PHY_SSC_ASIC_IN_SSC_RANGE from a register value.
#define BG_PCIE_PHY_SSC_ASIC_IN_SSC_RANGE(r)   (((r) & BM_PCIE_PHY_SSC_ASIC_IN_SSC_RANGE) >> BP_PCIE_PHY_SSC_ASIC_IN_SSC_RANGE)

/* --- Register HW_PCIE_PHY_SSC_ASIC_IN, field SS_EN[13] (RO)
 *
 * Value from ASIC for ssc_en.
 */

#define BP_PCIE_PHY_SSC_ASIC_IN_SS_EN      (13)      //!< Bit position for PCIE_PHY_SSC_ASIC_IN_SS_EN.
#define BM_PCIE_PHY_SSC_ASIC_IN_SS_EN      (0x00002000)  //!< Bit mask for PCIE_PHY_SSC_ASIC_IN_SS_EN.

//! @brief Get value of PCIE_PHY_SSC_ASIC_IN_SS_EN from a register value.
#define BG_PCIE_PHY_SSC_ASIC_IN_SS_EN(r)   (((r) & BM_PCIE_PHY_SSC_ASIC_IN_SS_EN) >> BP_PCIE_PHY_SSC_ASIC_IN_SS_EN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SUP_ASIC_OUT -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_sup_asic_out
{
    reg16_t U;
    struct _hw_pcie_phy_sup_asic_out_bitfields
    {
        unsigned short RES_ACK_OUT : 1; //!< [0] Value from PHY for res_ack_out output.
        unsigned short RES_REQ_OUT : 1; //!< [1] Value from PHY for res_req_out output.
        unsigned short RTUNE_ACK : 1; //!< [2] Value from PHY for rtune_ack output.
        unsigned short BS_OUT : 1; //!< [3] Value from PHY for bs_out output.
        unsigned short MPLL_STATE : 1; //!< [4] Value from PHY for mpll_state output.
        unsigned short RESERVED0 : 11; //!< [15:5] Reserved.
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

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field RES_ACK_OUT[0] (RO)
 *
 * Value from PHY for res_ack_out output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT      (0)      //!< Bit position for PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT.
#define BM_PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT      (0x00000001)  //!< Bit mask for PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT.

//! @brief Get value of PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT from a register value.
#define BG_PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT(r)   (((r) & BM_PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT) >> BP_PCIE_PHY_SUP_ASIC_OUT_RES_ACK_OUT)

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field RES_REQ_OUT[1] (RO)
 *
 * Value from PHY for res_req_out output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT      (1)      //!< Bit position for PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT.
#define BM_PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT      (0x00000002)  //!< Bit mask for PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT.

//! @brief Get value of PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT from a register value.
#define BG_PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT(r)   (((r) & BM_PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT) >> BP_PCIE_PHY_SUP_ASIC_OUT_RES_REQ_OUT)

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field RTUNE_ACK[2] (RO)
 *
 * Value from PHY for rtune_ack output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK      (2)      //!< Bit position for PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK.
#define BM_PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK      (0x00000004)  //!< Bit mask for PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK.

//! @brief Get value of PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK from a register value.
#define BG_PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK(r)   (((r) & BM_PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK) >> BP_PCIE_PHY_SUP_ASIC_OUT_RTUNE_ACK)

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field BS_OUT[3] (RO)
 *
 * Value from PHY for bs_out output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_BS_OUT      (3)      //!< Bit position for PCIE_PHY_SUP_ASIC_OUT_BS_OUT.
#define BM_PCIE_PHY_SUP_ASIC_OUT_BS_OUT      (0x00000008)  //!< Bit mask for PCIE_PHY_SUP_ASIC_OUT_BS_OUT.

//! @brief Get value of PCIE_PHY_SUP_ASIC_OUT_BS_OUT from a register value.
#define BG_PCIE_PHY_SUP_ASIC_OUT_BS_OUT(r)   (((r) & BM_PCIE_PHY_SUP_ASIC_OUT_BS_OUT) >> BP_PCIE_PHY_SUP_ASIC_OUT_BS_OUT)

/* --- Register HW_PCIE_PHY_SUP_ASIC_OUT, field MPLL_STATE[4] (RO)
 *
 * Value from PHY for mpll_state output.
 */

#define BP_PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE      (4)      //!< Bit position for PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE.
#define BM_PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE      (0x00000010)  //!< Bit mask for PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE.

//! @brief Get value of PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE from a register value.
#define BG_PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE(r)   (((r) & BM_PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE) >> BP_PCIE_PHY_SUP_ASIC_OUT_MPLL_STATE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_ATEOVRD_STATUS -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_ateovrd_status
{
    reg16_t U;
    struct _hw_pcie_phy_ateovrd_status_bitfields
    {
        unsigned short REF_USB2_EN_OUT : 1; //!< [0] Value from ATEOVRD for ref_usb2_en.
        unsigned short REF_CLKDIV2_OUT : 1; //!< [1] Value from ATEOVRD for ref_clkdiv2.
        unsigned short PHY_RESET_OUT : 1; //!< [2] Value from ATEOVRD for phy_reset.
        unsigned short ATEOVRD_EN : 1; //!< [3] When set, values from ATEOVRD register are sent to PHY.
        unsigned short REF_USB2_EN_IN : 1; //!< [4] Value from ASIC for ref_usb2_en.
        unsigned short REF_CLKDIV2_IN : 1; //!< [5] Value from ASIC for ref_clkdiv2.
        unsigned short PHY_RESET_IN : 1; //!< [6] Value from ASIC for phy_reset
        unsigned short REF_USE_PAD : 1; //!< [7] Value from ASIC for ref_use_pad
        unsigned short REF_SSP_EN : 1; //!< [8] Value from ASIC for ref_ssp_en.
        unsigned short RESERVED0 : 7; //!< [15:9] Reserved.
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

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_USB2_EN_OUT[0] (RO)
 *
 * Value from ATEOVRD for ref_usb2_en.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT      (0)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT.
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT      (0x00000001)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT) >> BP_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_OUT)

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_CLKDIV2_OUT[1] (RO)
 *
 * Value from ATEOVRD for ref_clkdiv2.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT      (1)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT.
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT      (0x00000002)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT) >> BP_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_OUT)

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field PHY_RESET_OUT[2] (RO)
 *
 * Value from ATEOVRD for phy_reset.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT      (2)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT.
#define BM_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT      (0x00000004)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT) >> BP_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_OUT)

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field ATEOVRD_EN[3] (RO)
 *
 * When set, values from ATEOVRD register are sent to PHY.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN      (3)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN.
#define BM_PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN      (0x00000008)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN) >> BP_PCIE_PHY_ATEOVRD_STATUS_ATEOVRD_EN)

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_USB2_EN_IN[4] (RO)
 *
 * Value from ASIC for ref_usb2_en.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN      (4)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN.
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN      (0x00000010)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN) >> BP_PCIE_PHY_ATEOVRD_STATUS_REF_USB2_EN_IN)

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_CLKDIV2_IN[5] (RO)
 *
 * Value from ASIC for ref_clkdiv2.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN      (5)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN.
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN      (0x00000020)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN) >> BP_PCIE_PHY_ATEOVRD_STATUS_REF_CLKDIV2_IN)

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field PHY_RESET_IN[6] (RO)
 *
 * Value from ASIC for phy_reset
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN      (6)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN.
#define BM_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN      (0x00000040)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN) >> BP_PCIE_PHY_ATEOVRD_STATUS_PHY_RESET_IN)

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_USE_PAD[7] (RO)
 *
 * Value from ASIC for ref_use_pad
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD      (7)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD.
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD      (0x00000080)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD) >> BP_PCIE_PHY_ATEOVRD_STATUS_REF_USE_PAD)

/* --- Register HW_PCIE_PHY_ATEOVRD_STATUS, field REF_SSP_EN[8] (RO)
 *
 * Value from ASIC for ref_ssp_en.
 */

#define BP_PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN      (8)      //!< Bit position for PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN.
#define BM_PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN      (0x00000100)  //!< Bit mask for PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN.

//! @brief Get value of PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN from a register value.
#define BG_PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN(r)   (((r) & BM_PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN) >> BP_PCIE_PHY_ATEOVRD_STATUS_REF_SSP_EN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_ENABLES -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_enables
{
    reg16_t U;
    struct _hw_pcie_phy_scope_enables_bitfields
    {
        unsigned short XOR_EN : 1; //!< [0] Uses scope_xor input for count values.
        unsigned short MASK_EN : 1; //!< [1] Enables scope_mask input for tracking count values. Clears registers when deasserted.
        unsigned short MASK_SATURATION_MODE : 1; //!< [2] Method of mask saturation.
        unsigned short RESERVED0 : 13; //!< [15:3] Reserved.
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

/* --- Register HW_PCIE_PHY_SCOPE_ENABLES, field XOR_EN[0] (RW)
 *
 * Uses scope_xor input for count values.
 */

#define BP_PCIE_PHY_SCOPE_ENABLES_XOR_EN      (0)      //!< Bit position for PCIE_PHY_SCOPE_ENABLES_XOR_EN.
#define BM_PCIE_PHY_SCOPE_ENABLES_XOR_EN      (0x00000001)  //!< Bit mask for PCIE_PHY_SCOPE_ENABLES_XOR_EN.

//! @brief Get value of PCIE_PHY_SCOPE_ENABLES_XOR_EN from a register value.
#define BG_PCIE_PHY_SCOPE_ENABLES_XOR_EN(r)   (((r) & BM_PCIE_PHY_SCOPE_ENABLES_XOR_EN) >> BP_PCIE_PHY_SCOPE_ENABLES_XOR_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_ENABLES_XOR_EN.
#define BF_PCIE_PHY_SCOPE_ENABLES_XOR_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_ENABLES_XOR_EN) & BM_PCIE_PHY_SCOPE_ENABLES_XOR_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_ENABLES_XOR_EN.
#define BF_PCIE_PHY_SCOPE_ENABLES_XOR_EN(v)   (((v) << BP_PCIE_PHY_SCOPE_ENABLES_XOR_EN) & BM_PCIE_PHY_SCOPE_ENABLES_XOR_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the XOR_EN field to a new value.
#define BW_PCIE_PHY_SCOPE_ENABLES_XOR_EN(v)   (HW_PCIE_PHY_SCOPE_ENABLES_WR((HW_PCIE_PHY_SCOPE_ENABLES_RD() & ~BM_PCIE_PHY_SCOPE_ENABLES_XOR_EN) | BF_PCIE_PHY_SCOPE_ENABLES_XOR_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_SCOPE_ENABLES, field MASK_EN[1] (RW)
 *
 * Enables scope_mask input for tracking count values. Clears registers when deasserted.
 */

#define BP_PCIE_PHY_SCOPE_ENABLES_MASK_EN      (1)      //!< Bit position for PCIE_PHY_SCOPE_ENABLES_MASK_EN.
#define BM_PCIE_PHY_SCOPE_ENABLES_MASK_EN      (0x00000002)  //!< Bit mask for PCIE_PHY_SCOPE_ENABLES_MASK_EN.

//! @brief Get value of PCIE_PHY_SCOPE_ENABLES_MASK_EN from a register value.
#define BG_PCIE_PHY_SCOPE_ENABLES_MASK_EN(r)   (((r) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_EN) >> BP_PCIE_PHY_SCOPE_ENABLES_MASK_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_ENABLES_MASK_EN.
#define BF_PCIE_PHY_SCOPE_ENABLES_MASK_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_ENABLES_MASK_EN) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_ENABLES_MASK_EN.
#define BF_PCIE_PHY_SCOPE_ENABLES_MASK_EN(v)   (((v) << BP_PCIE_PHY_SCOPE_ENABLES_MASK_EN) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_EN field to a new value.
#define BW_PCIE_PHY_SCOPE_ENABLES_MASK_EN(v)   (HW_PCIE_PHY_SCOPE_ENABLES_WR((HW_PCIE_PHY_SCOPE_ENABLES_RD() & ~BM_PCIE_PHY_SCOPE_ENABLES_MASK_EN) | BF_PCIE_PHY_SCOPE_ENABLES_MASK_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_SCOPE_ENABLES, field MASK_SATURATION_MODE[2] (RW)
 *
 * Method of mask saturation.
 *
 * Values:
 * 0 - Saturates when all mask_counters have reached sample_limit.
 * 1 - Saturates when the first mask_counter reaches sample_limit.
 */

#define BP_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE      (2)      //!< Bit position for PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE.
#define BM_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE      (0x00000004)  //!< Bit mask for PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE.

//! @brief Get value of PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE from a register value.
#define BG_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE(r)   (((r) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE) >> BP_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE.
#define BF_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE.
#define BF_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE(v)   (((v) << BP_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE) & BM_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_SATURATION_MODE field to a new value.
#define BW_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE(v)   (HW_PCIE_PHY_SCOPE_ENABLES_WR((HW_PCIE_PHY_SCOPE_ENABLES_RD() & ~BM_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE) | BF_PCIE_PHY_SCOPE_ENABLES_MASK_SATURATION_MODE(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_SAMPLES -  (RW)
 *
 * Reset value: 0x00000100
 *

 */
typedef union _hw_pcie_phy_scope_samples
{
    reg16_t U;
    struct _hw_pcie_phy_scope_samples_bitfields
    {
        unsigned short SAMPLES : 16; //!< [15:0] Number of samples to count.
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

/* --- Register HW_PCIE_PHY_SCOPE_SAMPLES, field SAMPLES[15:0] (RW)
 *
 * Number of samples to count.
 */

#define BP_PCIE_PHY_SCOPE_SAMPLES_SAMPLES      (0)      //!< Bit position for PCIE_PHY_SCOPE_SAMPLES_SAMPLES.
#define BM_PCIE_PHY_SCOPE_SAMPLES_SAMPLES      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_SAMPLES_SAMPLES.

//! @brief Get value of PCIE_PHY_SCOPE_SAMPLES_SAMPLES from a register value.
#define BG_PCIE_PHY_SCOPE_SAMPLES_SAMPLES(r)   (((r) & BM_PCIE_PHY_SCOPE_SAMPLES_SAMPLES) >> BP_PCIE_PHY_SCOPE_SAMPLES_SAMPLES)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_SAMPLES_SAMPLES.
#define BF_PCIE_PHY_SCOPE_SAMPLES_SAMPLES(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_SAMPLES_SAMPLES) & BM_PCIE_PHY_SCOPE_SAMPLES_SAMPLES)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_SAMPLES_SAMPLES.
#define BF_PCIE_PHY_SCOPE_SAMPLES_SAMPLES(v)   (((v) << BP_PCIE_PHY_SCOPE_SAMPLES_SAMPLES) & BM_PCIE_PHY_SCOPE_SAMPLES_SAMPLES)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SAMPLES field to a new value.
#define BW_PCIE_PHY_SCOPE_SAMPLES_SAMPLES(v)   (HW_PCIE_PHY_SCOPE_SAMPLES_WR((HW_PCIE_PHY_SCOPE_SAMPLES_RD() & ~BM_PCIE_PHY_SCOPE_SAMPLES_SAMPLES) | BF_PCIE_PHY_SCOPE_SAMPLES_SAMPLES(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_COUNT -  (RW)
 *
 * Reset value: 0x0000ffff
 *

 */
typedef union _hw_pcie_phy_scope_count
{
    reg16_t U;
    struct _hw_pcie_phy_scope_count_bitfields
    {
        unsigned short COUNT : 16; //!< [15:0] A write to this register starts the counting process. The value of FFFF indicates counting still in progress. If in MASK mode, asserting MASK_EN also starts the counting
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

/* --- Register HW_PCIE_PHY_SCOPE_COUNT, field COUNT[15:0] (RW)
 *
 * A write to this register starts the counting process. The value of FFFF indicates counting still
 * in progress. If in MASK mode, asserting MASK_EN also starts the counting
 */

#define BP_PCIE_PHY_SCOPE_COUNT_COUNT      (0)      //!< Bit position for PCIE_PHY_SCOPE_COUNT_COUNT.
#define BM_PCIE_PHY_SCOPE_COUNT_COUNT      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_COUNT_COUNT.

//! @brief Get value of PCIE_PHY_SCOPE_COUNT_COUNT from a register value.
#define BG_PCIE_PHY_SCOPE_COUNT_COUNT(r)   (((r) & BM_PCIE_PHY_SCOPE_COUNT_COUNT) >> BP_PCIE_PHY_SCOPE_COUNT_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_COUNT_COUNT.
#define BF_PCIE_PHY_SCOPE_COUNT_COUNT(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_COUNT_COUNT) & BM_PCIE_PHY_SCOPE_COUNT_COUNT)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_COUNT_COUNT.
#define BF_PCIE_PHY_SCOPE_COUNT_COUNT(v)   (((v) << BP_PCIE_PHY_SCOPE_COUNT_COUNT) & BM_PCIE_PHY_SCOPE_COUNT_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_PCIE_PHY_SCOPE_COUNT_COUNT(v)   (HW_PCIE_PHY_SCOPE_COUNT_WR((HW_PCIE_PHY_SCOPE_COUNT_RD() & ~BM_PCIE_PHY_SCOPE_COUNT_COUNT) | BF_PCIE_PHY_SCOPE_COUNT_COUNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_CTL -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_ctl
{
    reg16_t U;
    struct _hw_pcie_phy_scope_ctl_bitfields
    {
        unsigned short MASK_SATURATION : 1; //!< [0] When asserted, mask registers have saturated.
        unsigned short COUNT : 1; //!< [1] A write to this register starts the counting process. The value of FFFF indicates counting still in progress. If in MASK mode, asserting MASK_EN also starts the counting
        unsigned short RESERVED0 : 14; //!< [15:2] Reserved.
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

/* --- Register HW_PCIE_PHY_SCOPE_CTL, field MASK_SATURATION[0] (RW)
 *
 * When asserted, mask registers have saturated.
 */

#define BP_PCIE_PHY_SCOPE_CTL_MASK_SATURATION      (0)      //!< Bit position for PCIE_PHY_SCOPE_CTL_MASK_SATURATION.
#define BM_PCIE_PHY_SCOPE_CTL_MASK_SATURATION      (0x00000001)  //!< Bit mask for PCIE_PHY_SCOPE_CTL_MASK_SATURATION.

//! @brief Get value of PCIE_PHY_SCOPE_CTL_MASK_SATURATION from a register value.
#define BG_PCIE_PHY_SCOPE_CTL_MASK_SATURATION(r)   (((r) & BM_PCIE_PHY_SCOPE_CTL_MASK_SATURATION) >> BP_PCIE_PHY_SCOPE_CTL_MASK_SATURATION)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_CTL_MASK_SATURATION.
#define BF_PCIE_PHY_SCOPE_CTL_MASK_SATURATION(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_CTL_MASK_SATURATION) & BM_PCIE_PHY_SCOPE_CTL_MASK_SATURATION)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_CTL_MASK_SATURATION.
#define BF_PCIE_PHY_SCOPE_CTL_MASK_SATURATION(v)   (((v) << BP_PCIE_PHY_SCOPE_CTL_MASK_SATURATION) & BM_PCIE_PHY_SCOPE_CTL_MASK_SATURATION)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_SATURATION field to a new value.
#define BW_PCIE_PHY_SCOPE_CTL_MASK_SATURATION(v)   (HW_PCIE_PHY_SCOPE_CTL_WR((HW_PCIE_PHY_SCOPE_CTL_RD() & ~BM_PCIE_PHY_SCOPE_CTL_MASK_SATURATION) | BF_PCIE_PHY_SCOPE_CTL_MASK_SATURATION(v)))
#endif

/* --- Register HW_PCIE_PHY_SCOPE_CTL, field COUNT[1] (RW)
 *
 * A write to this register starts the counting process. The value of FFFF indicates counting still
 * in progress. If in MASK mode, asserting MASK_EN also starts the counting
 */

#define BP_PCIE_PHY_SCOPE_CTL_COUNT      (1)      //!< Bit position for PCIE_PHY_SCOPE_CTL_COUNT.
#define BM_PCIE_PHY_SCOPE_CTL_COUNT      (0x00000002)  //!< Bit mask for PCIE_PHY_SCOPE_CTL_COUNT.

//! @brief Get value of PCIE_PHY_SCOPE_CTL_COUNT from a register value.
#define BG_PCIE_PHY_SCOPE_CTL_COUNT(r)   (((r) & BM_PCIE_PHY_SCOPE_CTL_COUNT) >> BP_PCIE_PHY_SCOPE_CTL_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_CTL_COUNT.
#define BF_PCIE_PHY_SCOPE_CTL_COUNT(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_CTL_COUNT) & BM_PCIE_PHY_SCOPE_CTL_COUNT)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_CTL_COUNT.
#define BF_PCIE_PHY_SCOPE_CTL_COUNT(v)   (((v) << BP_PCIE_PHY_SCOPE_CTL_COUNT) & BM_PCIE_PHY_SCOPE_CTL_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_PCIE_PHY_SCOPE_CTL_COUNT(v)   (HW_PCIE_PHY_SCOPE_CTL_WR((HW_PCIE_PHY_SCOPE_CTL_RD() & ~BM_PCIE_PHY_SCOPE_CTL_COUNT) | BF_PCIE_PHY_SCOPE_CTL_COUNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK_000 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_mask_000
{
    reg16_t U;
    struct _hw_pcie_phy_scope_mask_000_bitfields
    {
        unsigned short MASK_VAL_N : 16; //!< [15:0] Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_000_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK_000 register
 */
#define HW_PCIE_PHY_SCOPE_MASK_000_ADDR      (REGS_PCIE_PHY_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK_000           (*(volatile hw_pcie_phy_scope_mask_000_t *) HW_PCIE_PHY_SCOPE_MASK_000_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_000_RD()      (HW_PCIE_PHY_SCOPE_MASK_000.U)
#define HW_PCIE_PHY_SCOPE_MASK_000_WR(v)     (HW_PCIE_PHY_SCOPE_MASK_000.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_000_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_000_WR(HW_PCIE_PHY_SCOPE_MASK_000_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_000_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_000_WR(HW_PCIE_PHY_SCOPE_MASK_000_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_000_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_000_WR(HW_PCIE_PHY_SCOPE_MASK_000_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK_000 bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK_000, field MASK_VAL_N[15:0] (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N      (0)      //!< Bit position for PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N.
#define BM_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N.

//! @brief Get value of PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N from a register value.
#define BG_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N(r)   (((r) & BM_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N) >> BP_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N(v)   (((v) << BP_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N(v)   (HW_PCIE_PHY_SCOPE_MASK_000_WR((HW_PCIE_PHY_SCOPE_MASK_000_RD() & ~BM_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N) | BF_PCIE_PHY_SCOPE_MASK_000_MASK_VAL_N(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK_001 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_mask_001
{
    reg16_t U;
    struct _hw_pcie_phy_scope_mask_001_bitfields
    {
        unsigned short MASK_VAL_N : 16; //!< [15:0] Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_001_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK_001 register
 */
#define HW_PCIE_PHY_SCOPE_MASK_001_ADDR      (REGS_PCIE_PHY_BASE + 0x25)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK_001           (*(volatile hw_pcie_phy_scope_mask_001_t *) HW_PCIE_PHY_SCOPE_MASK_001_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_001_RD()      (HW_PCIE_PHY_SCOPE_MASK_001.U)
#define HW_PCIE_PHY_SCOPE_MASK_001_WR(v)     (HW_PCIE_PHY_SCOPE_MASK_001.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_001_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_001_WR(HW_PCIE_PHY_SCOPE_MASK_001_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_001_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_001_WR(HW_PCIE_PHY_SCOPE_MASK_001_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_001_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_001_WR(HW_PCIE_PHY_SCOPE_MASK_001_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK_001 bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK_001, field MASK_VAL_N[15:0] (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N      (0)      //!< Bit position for PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N.
#define BM_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N.

//! @brief Get value of PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N from a register value.
#define BG_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N(r)   (((r) & BM_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N) >> BP_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N(v)   (((v) << BP_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N(v)   (HW_PCIE_PHY_SCOPE_MASK_001_WR((HW_PCIE_PHY_SCOPE_MASK_001_RD() & ~BM_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N) | BF_PCIE_PHY_SCOPE_MASK_001_MASK_VAL_N(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK_010 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_mask_010
{
    reg16_t U;
    struct _hw_pcie_phy_scope_mask_010_bitfields
    {
        unsigned short MASK_VAL_N : 16; //!< [15:0] Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_010_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK_010 register
 */
#define HW_PCIE_PHY_SCOPE_MASK_010_ADDR      (REGS_PCIE_PHY_BASE + 0x26)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK_010           (*(volatile hw_pcie_phy_scope_mask_010_t *) HW_PCIE_PHY_SCOPE_MASK_010_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_010_RD()      (HW_PCIE_PHY_SCOPE_MASK_010.U)
#define HW_PCIE_PHY_SCOPE_MASK_010_WR(v)     (HW_PCIE_PHY_SCOPE_MASK_010.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_010_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_010_WR(HW_PCIE_PHY_SCOPE_MASK_010_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_010_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_010_WR(HW_PCIE_PHY_SCOPE_MASK_010_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_010_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_010_WR(HW_PCIE_PHY_SCOPE_MASK_010_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK_010 bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK_010, field MASK_VAL_N[15:0] (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N      (0)      //!< Bit position for PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N.
#define BM_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N.

//! @brief Get value of PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N from a register value.
#define BG_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N(r)   (((r) & BM_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N) >> BP_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N(v)   (((v) << BP_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N(v)   (HW_PCIE_PHY_SCOPE_MASK_010_WR((HW_PCIE_PHY_SCOPE_MASK_010_RD() & ~BM_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N) | BF_PCIE_PHY_SCOPE_MASK_010_MASK_VAL_N(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK_011 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_mask_011
{
    reg16_t U;
    struct _hw_pcie_phy_scope_mask_011_bitfields
    {
        unsigned short MASK_VAL_N : 16; //!< [15:0] Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_011_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK_011 register
 */
#define HW_PCIE_PHY_SCOPE_MASK_011_ADDR      (REGS_PCIE_PHY_BASE + 0x27)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK_011           (*(volatile hw_pcie_phy_scope_mask_011_t *) HW_PCIE_PHY_SCOPE_MASK_011_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_011_RD()      (HW_PCIE_PHY_SCOPE_MASK_011.U)
#define HW_PCIE_PHY_SCOPE_MASK_011_WR(v)     (HW_PCIE_PHY_SCOPE_MASK_011.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_011_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_011_WR(HW_PCIE_PHY_SCOPE_MASK_011_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_011_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_011_WR(HW_PCIE_PHY_SCOPE_MASK_011_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_011_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_011_WR(HW_PCIE_PHY_SCOPE_MASK_011_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK_011 bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK_011, field MASK_VAL_N[15:0] (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N      (0)      //!< Bit position for PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N.
#define BM_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N.

//! @brief Get value of PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N from a register value.
#define BG_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N(r)   (((r) & BM_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N) >> BP_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N(v)   (((v) << BP_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N(v)   (HW_PCIE_PHY_SCOPE_MASK_011_WR((HW_PCIE_PHY_SCOPE_MASK_011_RD() & ~BM_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N) | BF_PCIE_PHY_SCOPE_MASK_011_MASK_VAL_N(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK_100 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_mask_100
{
    reg16_t U;
    struct _hw_pcie_phy_scope_mask_100_bitfields
    {
        unsigned short MASK_VAL_N : 16; //!< [15:0] Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_100_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK_100 register
 */
#define HW_PCIE_PHY_SCOPE_MASK_100_ADDR      (REGS_PCIE_PHY_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK_100           (*(volatile hw_pcie_phy_scope_mask_100_t *) HW_PCIE_PHY_SCOPE_MASK_100_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_100_RD()      (HW_PCIE_PHY_SCOPE_MASK_100.U)
#define HW_PCIE_PHY_SCOPE_MASK_100_WR(v)     (HW_PCIE_PHY_SCOPE_MASK_100.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_100_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_100_WR(HW_PCIE_PHY_SCOPE_MASK_100_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_100_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_100_WR(HW_PCIE_PHY_SCOPE_MASK_100_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_100_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_100_WR(HW_PCIE_PHY_SCOPE_MASK_100_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK_100 bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK_100, field MASK_VAL_N[15:0] (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N      (0)      //!< Bit position for PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N.
#define BM_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N.

//! @brief Get value of PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N from a register value.
#define BG_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N(r)   (((r) & BM_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N) >> BP_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N(v)   (((v) << BP_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N(v)   (HW_PCIE_PHY_SCOPE_MASK_100_WR((HW_PCIE_PHY_SCOPE_MASK_100_RD() & ~BM_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N) | BF_PCIE_PHY_SCOPE_MASK_100_MASK_VAL_N(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK_101 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_mask_101
{
    reg16_t U;
    struct _hw_pcie_phy_scope_mask_101_bitfields
    {
        unsigned short MASK_VAL_N : 16; //!< [15:0] Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_101_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK_101 register
 */
#define HW_PCIE_PHY_SCOPE_MASK_101_ADDR      (REGS_PCIE_PHY_BASE + 0x29)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK_101           (*(volatile hw_pcie_phy_scope_mask_101_t *) HW_PCIE_PHY_SCOPE_MASK_101_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_101_RD()      (HW_PCIE_PHY_SCOPE_MASK_101.U)
#define HW_PCIE_PHY_SCOPE_MASK_101_WR(v)     (HW_PCIE_PHY_SCOPE_MASK_101.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_101_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_101_WR(HW_PCIE_PHY_SCOPE_MASK_101_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_101_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_101_WR(HW_PCIE_PHY_SCOPE_MASK_101_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_101_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_101_WR(HW_PCIE_PHY_SCOPE_MASK_101_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK_101 bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK_101, field MASK_VAL_N[15:0] (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N      (0)      //!< Bit position for PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N.
#define BM_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N.

//! @brief Get value of PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N from a register value.
#define BG_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N(r)   (((r) & BM_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N) >> BP_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N(v)   (((v) << BP_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N(v)   (HW_PCIE_PHY_SCOPE_MASK_101_WR((HW_PCIE_PHY_SCOPE_MASK_101_RD() & ~BM_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N) | BF_PCIE_PHY_SCOPE_MASK_101_MASK_VAL_N(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK_110 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_mask_110
{
    reg16_t U;
    struct _hw_pcie_phy_scope_mask_110_bitfields
    {
        unsigned short MASK_VAL_N : 16; //!< [15:0] Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_110_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK_110 register
 */
#define HW_PCIE_PHY_SCOPE_MASK_110_ADDR      (REGS_PCIE_PHY_BASE + 0x2a)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK_110           (*(volatile hw_pcie_phy_scope_mask_110_t *) HW_PCIE_PHY_SCOPE_MASK_110_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_110_RD()      (HW_PCIE_PHY_SCOPE_MASK_110.U)
#define HW_PCIE_PHY_SCOPE_MASK_110_WR(v)     (HW_PCIE_PHY_SCOPE_MASK_110.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_110_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_110_WR(HW_PCIE_PHY_SCOPE_MASK_110_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_110_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_110_WR(HW_PCIE_PHY_SCOPE_MASK_110_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_110_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_110_WR(HW_PCIE_PHY_SCOPE_MASK_110_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK_110 bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK_110, field MASK_VAL_N[15:0] (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N      (0)      //!< Bit position for PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N.
#define BM_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N.

//! @brief Get value of PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N from a register value.
#define BG_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N(r)   (((r) & BM_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N) >> BP_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N(v)   (((v) << BP_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N(v)   (HW_PCIE_PHY_SCOPE_MASK_110_WR((HW_PCIE_PHY_SCOPE_MASK_110_RD() & ~BM_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N) | BF_PCIE_PHY_SCOPE_MASK_110_MASK_VAL_N(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_SCOPE_MASK_111 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_scope_mask_111
{
    reg16_t U;
    struct _hw_pcie_phy_scope_mask_111_bitfields
    {
        unsigned short MASK_VAL_N : 16; //!< [15:0] Starting count value of mask register. Scope must be enabled to read from or write to this register.
    } B;
} hw_pcie_phy_scope_mask_111_t;
#endif

/*
 * constants & macros for entire PCIE_PHY_SCOPE_MASK_111 register
 */
#define HW_PCIE_PHY_SCOPE_MASK_111_ADDR      (REGS_PCIE_PHY_BASE + 0x2b)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PHY_SCOPE_MASK_111           (*(volatile hw_pcie_phy_scope_mask_111_t *) HW_PCIE_PHY_SCOPE_MASK_111_ADDR)
#define HW_PCIE_PHY_SCOPE_MASK_111_RD()      (HW_PCIE_PHY_SCOPE_MASK_111.U)
#define HW_PCIE_PHY_SCOPE_MASK_111_WR(v)     (HW_PCIE_PHY_SCOPE_MASK_111.U = (v))
#define HW_PCIE_PHY_SCOPE_MASK_111_SET(v)    (HW_PCIE_PHY_SCOPE_MASK_111_WR(HW_PCIE_PHY_SCOPE_MASK_111_RD() |  (v)))
#define HW_PCIE_PHY_SCOPE_MASK_111_CLR(v)    (HW_PCIE_PHY_SCOPE_MASK_111_WR(HW_PCIE_PHY_SCOPE_MASK_111_RD() & ~(v)))
#define HW_PCIE_PHY_SCOPE_MASK_111_TOG(v)    (HW_PCIE_PHY_SCOPE_MASK_111_WR(HW_PCIE_PHY_SCOPE_MASK_111_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PCIE_PHY_SCOPE_MASK_111 bitfields
 */

/* --- Register HW_PCIE_PHY_SCOPE_MASK_111, field MASK_VAL_N[15:0] (RW)
 *
 * Starting count value of mask register. Scope must be enabled to read from or write to this
 * register.
 */

#define BP_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N      (0)      //!< Bit position for PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N.
#define BM_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N      (0x0000ffff)  //!< Bit mask for PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N.

//! @brief Get value of PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N from a register value.
#define BG_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N(r)   (((r) & BM_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N) >> BP_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N(v)   ((((reg16_t) v) << BP_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N)
#else
//! @brief Format value for bitfield PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N.
#define BF_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N(v)   (((v) << BP_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N) & BM_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VAL_N field to a new value.
#define BW_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N(v)   (HW_PCIE_PHY_SCOPE_MASK_111_WR((HW_PCIE_PHY_SCOPE_MASK_111_RD() & ~BM_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N) | BF_PCIE_PHY_SCOPE_MASK_111_MASK_VAL_N(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_LOOP_CTL -  (RW)
 *
 * Reset value: 0x000000c0
 *

 */
typedef union _hw_pcie_phy_mpll_loop_ctl
{
    reg16_t U;
    struct _hw_pcie_phy_mpll_loop_ctl_bitfields
    {
        unsigned short VMB : 1; //!< [0] Measures MPLL master bias voltage.
        unsigned short VBF_SF : 1; //!< [1] Measures MPLL VBF_SF (RC filtered gate voltage for VPSF source follower).
        unsigned short INT_CNTRL : 2; //!< [3:2] Charge pump integrating current setting.
        unsigned short PROP_CNTRL : 4; //!< [7:4] Charge pump proportional current setting.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved.
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

/* --- Register HW_PCIE_PHY_MPLL_LOOP_CTL, field VMB[0] (RW)
 *
 * Measures MPLL master bias voltage.
 */

#define BP_PCIE_PHY_MPLL_LOOP_CTL_VMB      (0)      //!< Bit position for PCIE_PHY_MPLL_LOOP_CTL_VMB.
#define BM_PCIE_PHY_MPLL_LOOP_CTL_VMB      (0x00000001)  //!< Bit mask for PCIE_PHY_MPLL_LOOP_CTL_VMB.

//! @brief Get value of PCIE_PHY_MPLL_LOOP_CTL_VMB from a register value.
#define BG_PCIE_PHY_MPLL_LOOP_CTL_VMB(r)   (((r) & BM_PCIE_PHY_MPLL_LOOP_CTL_VMB) >> BP_PCIE_PHY_MPLL_LOOP_CTL_VMB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_LOOP_CTL_VMB.
#define BF_PCIE_PHY_MPLL_LOOP_CTL_VMB(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_LOOP_CTL_VMB) & BM_PCIE_PHY_MPLL_LOOP_CTL_VMB)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_LOOP_CTL_VMB.
#define BF_PCIE_PHY_MPLL_LOOP_CTL_VMB(v)   (((v) << BP_PCIE_PHY_MPLL_LOOP_CTL_VMB) & BM_PCIE_PHY_MPLL_LOOP_CTL_VMB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VMB field to a new value.
#define BW_PCIE_PHY_MPLL_LOOP_CTL_VMB(v)   (HW_PCIE_PHY_MPLL_LOOP_CTL_WR((HW_PCIE_PHY_MPLL_LOOP_CTL_RD() & ~BM_PCIE_PHY_MPLL_LOOP_CTL_VMB) | BF_PCIE_PHY_MPLL_LOOP_CTL_VMB(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_LOOP_CTL, field VBF_SF[1] (RW)
 *
 * Measures MPLL VBF_SF (RC filtered gate voltage for VPSF source follower).
 */

#define BP_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF      (1)      //!< Bit position for PCIE_PHY_MPLL_LOOP_CTL_VBF_SF.
#define BM_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF      (0x00000002)  //!< Bit mask for PCIE_PHY_MPLL_LOOP_CTL_VBF_SF.

//! @brief Get value of PCIE_PHY_MPLL_LOOP_CTL_VBF_SF from a register value.
#define BG_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF(r)   (((r) & BM_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF) >> BP_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_LOOP_CTL_VBF_SF.
#define BF_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF) & BM_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_LOOP_CTL_VBF_SF.
#define BF_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF(v)   (((v) << BP_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF) & BM_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBF_SF field to a new value.
#define BW_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF(v)   (HW_PCIE_PHY_MPLL_LOOP_CTL_WR((HW_PCIE_PHY_MPLL_LOOP_CTL_RD() & ~BM_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF) | BF_PCIE_PHY_MPLL_LOOP_CTL_VBF_SF(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_LOOP_CTL, field INT_CNTRL[3:2] (RW)
 *
 * Charge pump integrating current setting.
 */

#define BP_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL      (2)      //!< Bit position for PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL.
#define BM_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL      (0x0000000c)  //!< Bit mask for PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL.

//! @brief Get value of PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL from a register value.
#define BG_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL(r)   (((r) & BM_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL) >> BP_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL.
#define BF_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL) & BM_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL.
#define BF_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL(v)   (((v) << BP_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL) & BM_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_CNTRL field to a new value.
#define BW_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL(v)   (HW_PCIE_PHY_MPLL_LOOP_CTL_WR((HW_PCIE_PHY_MPLL_LOOP_CTL_RD() & ~BM_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL) | BF_PCIE_PHY_MPLL_LOOP_CTL_INT_CNTRL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_LOOP_CTL, field PROP_CNTRL[7:4] (RW)
 *
 * Charge pump proportional current setting.
 */

#define BP_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL      (4)      //!< Bit position for PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL.
#define BM_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL      (0x000000f0)  //!< Bit mask for PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL.

//! @brief Get value of PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL from a register value.
#define BG_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL(r)   (((r) & BM_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL) >> BP_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL.
#define BF_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL) & BM_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL.
#define BF_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL(v)   (((v) << BP_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL) & BM_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PROP_CNTRL field to a new value.
#define BW_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL(v)   (HW_PCIE_PHY_MPLL_LOOP_CTL_WR((HW_PCIE_PHY_MPLL_LOOP_CTL_RD() & ~BM_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL) | BF_PCIE_PHY_MPLL_LOOP_CTL_PROP_CNTRL(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_ATB_MEAS1 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_mpll_atb_meas1
{
    reg16_t U;
    struct _hw_pcie_phy_mpll_atb_meas1_bitfields
    {
        unsigned short VREG_MPLL : 1; //!< [0] Puts vreg_mpll on atb_s_p.
        unsigned short VP_CP : 1; //!< [1] Puts vp_cp on atb_s_p.
        unsigned short VPA : 1; //!< [2] Puts vpa on atb_s_m.
        unsigned short IVCO : 1; //!< [3] Puts VCO current / 93 on atb_f_m.
        unsigned short GD : 1; //!< [4] Puts gd on atb_s_m.
        unsigned short VCNTRL : 1; //!< [5] Puts vcntrl on atb_s_m.
        unsigned short VREF : 1; //!< [6] Puts vref from charge pump on atb_s_p.
        unsigned short VPSF : 1; //!< [7] Puts vpsf on atb_s_p.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved.
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

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VREG_MPLL[0] (RW)
 *
 * Puts vreg_mpll on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL      (0)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL.
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL      (0x00000001)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL) >> BP_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VREG_MPLL field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR((HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL) | BF_PCIE_PHY_MPLL_ATB_MEAS1_VREG_MPLL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VP_CP[1] (RW)
 *
 * Puts vp_cp on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP      (1)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS1_VP_CP.
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP      (0x00000002)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS1_VP_CP.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS1_VP_CP from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP) >> BP_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VP_CP.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VP_CP.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VP_CP field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR((HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP) | BF_PCIE_PHY_MPLL_ATB_MEAS1_VP_CP(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VPA[2] (RW)
 *
 * Puts vpa on atb_s_m.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VPA      (2)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS1_VPA.
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VPA      (0x00000004)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS1_VPA.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS1_VPA from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS1_VPA(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPA) >> BP_PCIE_PHY_MPLL_ATB_MEAS1_VPA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VPA.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VPA(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VPA) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPA)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VPA.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VPA(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VPA) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VPA field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VPA(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR((HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS1_VPA) | BF_PCIE_PHY_MPLL_ATB_MEAS1_VPA(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field IVCO[3] (RW)
 *
 * Puts VCO current / 93 on atb_f_m.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_IVCO      (3)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS1_IVCO.
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_IVCO      (0x00000008)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS1_IVCO.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS1_IVCO from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS1_IVCO(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS1_IVCO) >> BP_PCIE_PHY_MPLL_ATB_MEAS1_IVCO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_IVCO.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_IVCO(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_IVCO) & BM_PCIE_PHY_MPLL_ATB_MEAS1_IVCO)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_IVCO.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_IVCO(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_IVCO) & BM_PCIE_PHY_MPLL_ATB_MEAS1_IVCO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IVCO field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_IVCO(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR((HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS1_IVCO) | BF_PCIE_PHY_MPLL_ATB_MEAS1_IVCO(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field GD[4] (RW)
 *
 * Puts gd on atb_s_m.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_GD      (4)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS1_GD.
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_GD      (0x00000010)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS1_GD.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS1_GD from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS1_GD(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS1_GD) >> BP_PCIE_PHY_MPLL_ATB_MEAS1_GD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_GD.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_GD(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_GD) & BM_PCIE_PHY_MPLL_ATB_MEAS1_GD)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_GD.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_GD(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_GD) & BM_PCIE_PHY_MPLL_ATB_MEAS1_GD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GD field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_GD(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR((HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS1_GD) | BF_PCIE_PHY_MPLL_ATB_MEAS1_GD(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VCNTRL[5] (RW)
 *
 * Puts vcntrl on atb_s_m.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL      (5)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL.
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL      (0x00000020)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL) >> BP_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VCNTRL field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR((HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL) | BF_PCIE_PHY_MPLL_ATB_MEAS1_VCNTRL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VREF[6] (RW)
 *
 * Puts vref from charge pump on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VREF      (6)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS1_VREF.
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VREF      (0x00000040)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS1_VREF.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS1_VREF from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS1_VREF(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREF) >> BP_PCIE_PHY_MPLL_ATB_MEAS1_VREF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VREF.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VREF(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VREF) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREF)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VREF.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VREF(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VREF) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VREF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VREF field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VREF(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR((HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS1_VREF) | BF_PCIE_PHY_MPLL_ATB_MEAS1_VREF(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS1, field VPSF[7] (RW)
 *
 * Puts vpsf on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS1_VPSF      (7)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS1_VPSF.
#define BM_PCIE_PHY_MPLL_ATB_MEAS1_VPSF      (0x00000080)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS1_VPSF.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS1_VPSF from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS1_VPSF(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPSF) >> BP_PCIE_PHY_MPLL_ATB_MEAS1_VPSF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VPSF.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VPSF(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VPSF) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPSF)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS1_VPSF.
#define BF_PCIE_PHY_MPLL_ATB_MEAS1_VPSF(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS1_VPSF) & BM_PCIE_PHY_MPLL_ATB_MEAS1_VPSF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VPSF field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS1_VPSF(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS1_WR((HW_PCIE_PHY_MPLL_ATB_MEAS1_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS1_VPSF) | BF_PCIE_PHY_MPLL_ATB_MEAS1_VPSF(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_ATB_MEAS2 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_mpll_atb_meas2
{
    reg16_t U;
    struct _hw_pcie_phy_mpll_atb_meas2_bitfields
    {
        unsigned short EN_MPMIX_TST : 1; //!< [0] Enables XOR gate to test linearity of MPLL phase mixer.
        unsigned short EN_MPMIX_VPMIX : 1; //!< [1] Puts vreg_pmix on atb_s_p.
        unsigned short FRC_PMIX_VPMIX : 1; //!< [2] Forces mpll_pmix_vreg to use atb_s_m as its input instead of vbg.
        unsigned short MEAS_TEMP : 1; //!< [3] Instructs POR block to measure the temperature.
        unsigned short ATB_SENSE_SEL : 1; //!< [4] connects internal atb sense bus to external bus
        unsigned short VCNTRL_P : 1; //!< [5] Puts dcc output vcntrl_m on atb_s_p
        unsigned short VCNTRL_M : 1; //!< [6] Puts dcc output vcntrl_p on atb_s_m
        unsigned short IVCO_FILT : 1; //!< [7] Puts filtered version of ivco on atb_s_p
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved.
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

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field EN_MPMIX_TST[0] (RW)
 *
 * Enables XOR gate to test linearity of MPLL phase mixer.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST      (0)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST.
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST      (0x00000001)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST) >> BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_MPMIX_TST field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR((HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST) | BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_TST(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field EN_MPMIX_VPMIX[1] (RW)
 *
 * Puts vreg_pmix on atb_s_p.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX      (1)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX.
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX      (0x00000002)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX) >> BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX) & BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_MPMIX_VPMIX field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR((HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX) | BF_PCIE_PHY_MPLL_ATB_MEAS2_EN_MPMIX_VPMIX(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field FRC_PMIX_VPMIX[2] (RW)
 *
 * Forces mpll_pmix_vreg to use atb_s_m as its input instead of vbg.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX      (2)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX.
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX      (0x00000004)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX) >> BP_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX) & BM_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX) & BM_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_PMIX_VPMIX field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR((HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX) | BF_PCIE_PHY_MPLL_ATB_MEAS2_FRC_PMIX_VPMIX(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field MEAS_TEMP[3] (RW)
 *
 * Instructs POR block to measure the temperature.
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP      (3)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP.
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP      (0x00000008)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP) >> BP_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP) & BM_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP) & BM_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_TEMP field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR((HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP) | BF_PCIE_PHY_MPLL_ATB_MEAS2_MEAS_TEMP(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field ATB_SENSE_SEL[4] (RW)
 *
 * connects internal atb sense bus to external bus
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL      (4)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL.
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL      (0x00000010)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL) >> BP_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL) & BM_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL) & BM_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_SENSE_SEL field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR((HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL) | BF_PCIE_PHY_MPLL_ATB_MEAS2_ATB_SENSE_SEL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field VCNTRL_P[5] (RW)
 *
 * Puts dcc output vcntrl_m on atb_s_p
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P      (5)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P.
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P      (0x00000020)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P) >> BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VCNTRL_P field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR((HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P) | BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_P(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field VCNTRL_M[6] (RW)
 *
 * Puts dcc output vcntrl_p on atb_s_m
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M      (6)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M.
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M      (0x00000040)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M) >> BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M) & BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VCNTRL_M field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR((HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M) | BF_PCIE_PHY_MPLL_ATB_MEAS2_VCNTRL_M(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_ATB_MEAS2, field IVCO_FILT[7] (RW)
 *
 * Puts filtered version of ivco on atb_s_p
 */

#define BP_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT      (7)      //!< Bit position for PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT.
#define BM_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT      (0x00000080)  //!< Bit mask for PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT.

//! @brief Get value of PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT from a register value.
#define BG_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT(r)   (((r) & BM_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT) >> BP_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT) & BM_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT.
#define BF_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT(v)   (((v) << BP_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT) & BM_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IVCO_FILT field to a new value.
#define BW_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT(v)   (HW_PCIE_PHY_MPLL_ATB_MEAS2_WR((HW_PCIE_PHY_MPLL_ATB_MEAS2_RD() & ~BM_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT) | BF_PCIE_PHY_MPLL_ATB_MEAS2_IVCO_FILT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_MPLL_OVR -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_mpll_ovr
{
    reg16_t U;
    struct _hw_pcie_phy_mpll_ovr_bitfields
    {
        unsigned short EN_PMIX_CLK_SEL_LCL : 1; //!< [0] enable local control of pmix_clk_sel
        unsigned short PMIX_CLK_SEL_LCL : 1; //!< [1] local pmix_clk_sel value
        unsigned short EN_RST_LCL : 1; //!< [2] enable local control of reset
        unsigned short RST_LCL : 1; //!< [3] local Reset value
        unsigned short EN_GS_LCL : 1; //!< [4] Enables local control of gear_shift
        unsigned short GS_LCL : 1; //!< [5] local gear_shift value
        unsigned short EN_PWRON_LCL : 1; //!< [6] Enables local control of power_on
        unsigned short PWRON_LCL : 1; //!< [7] local power_on value
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved.
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

/* --- Register HW_PCIE_PHY_MPLL_OVR, field EN_PMIX_CLK_SEL_LCL[0] (RW)
 *
 * enable local control of pmix_clk_sel
 */

#define BP_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL      (0)      //!< Bit position for PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL.
#define BM_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL      (0x00000001)  //!< Bit mask for PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL.

//! @brief Get value of PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL from a register value.
#define BG_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL(r)   (((r) & BM_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL) >> BP_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL.
#define BF_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL) & BM_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL.
#define BF_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL(v)   (((v) << BP_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL) & BM_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_PMIX_CLK_SEL_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL(v)   (HW_PCIE_PHY_MPLL_OVR_WR((HW_PCIE_PHY_MPLL_OVR_RD() & ~BM_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL) | BF_PCIE_PHY_MPLL_OVR_EN_PMIX_CLK_SEL_LCL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field PMIX_CLK_SEL_LCL[1] (RW)
 *
 * local pmix_clk_sel value
 */

#define BP_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL      (1)      //!< Bit position for PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL.
#define BM_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL      (0x00000002)  //!< Bit mask for PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL.

//! @brief Get value of PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL from a register value.
#define BG_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL(r)   (((r) & BM_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL) >> BP_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL.
#define BF_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL) & BM_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL.
#define BF_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL(v)   (((v) << BP_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL) & BM_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PMIX_CLK_SEL_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL(v)   (HW_PCIE_PHY_MPLL_OVR_WR((HW_PCIE_PHY_MPLL_OVR_RD() & ~BM_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL) | BF_PCIE_PHY_MPLL_OVR_PMIX_CLK_SEL_LCL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field EN_RST_LCL[2] (RW)
 *
 * enable local control of reset
 */

#define BP_PCIE_PHY_MPLL_OVR_EN_RST_LCL      (2)      //!< Bit position for PCIE_PHY_MPLL_OVR_EN_RST_LCL.
#define BM_PCIE_PHY_MPLL_OVR_EN_RST_LCL      (0x00000004)  //!< Bit mask for PCIE_PHY_MPLL_OVR_EN_RST_LCL.

//! @brief Get value of PCIE_PHY_MPLL_OVR_EN_RST_LCL from a register value.
#define BG_PCIE_PHY_MPLL_OVR_EN_RST_LCL(r)   (((r) & BM_PCIE_PHY_MPLL_OVR_EN_RST_LCL) >> BP_PCIE_PHY_MPLL_OVR_EN_RST_LCL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_EN_RST_LCL.
#define BF_PCIE_PHY_MPLL_OVR_EN_RST_LCL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVR_EN_RST_LCL) & BM_PCIE_PHY_MPLL_OVR_EN_RST_LCL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_EN_RST_LCL.
#define BF_PCIE_PHY_MPLL_OVR_EN_RST_LCL(v)   (((v) << BP_PCIE_PHY_MPLL_OVR_EN_RST_LCL) & BM_PCIE_PHY_MPLL_OVR_EN_RST_LCL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RST_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_EN_RST_LCL(v)   (HW_PCIE_PHY_MPLL_OVR_WR((HW_PCIE_PHY_MPLL_OVR_RD() & ~BM_PCIE_PHY_MPLL_OVR_EN_RST_LCL) | BF_PCIE_PHY_MPLL_OVR_EN_RST_LCL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field RST_LCL[3] (RW)
 *
 * local Reset value
 */

#define BP_PCIE_PHY_MPLL_OVR_RST_LCL      (3)      //!< Bit position for PCIE_PHY_MPLL_OVR_RST_LCL.
#define BM_PCIE_PHY_MPLL_OVR_RST_LCL      (0x00000008)  //!< Bit mask for PCIE_PHY_MPLL_OVR_RST_LCL.

//! @brief Get value of PCIE_PHY_MPLL_OVR_RST_LCL from a register value.
#define BG_PCIE_PHY_MPLL_OVR_RST_LCL(r)   (((r) & BM_PCIE_PHY_MPLL_OVR_RST_LCL) >> BP_PCIE_PHY_MPLL_OVR_RST_LCL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_RST_LCL.
#define BF_PCIE_PHY_MPLL_OVR_RST_LCL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVR_RST_LCL) & BM_PCIE_PHY_MPLL_OVR_RST_LCL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_RST_LCL.
#define BF_PCIE_PHY_MPLL_OVR_RST_LCL(v)   (((v) << BP_PCIE_PHY_MPLL_OVR_RST_LCL) & BM_PCIE_PHY_MPLL_OVR_RST_LCL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RST_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_RST_LCL(v)   (HW_PCIE_PHY_MPLL_OVR_WR((HW_PCIE_PHY_MPLL_OVR_RD() & ~BM_PCIE_PHY_MPLL_OVR_RST_LCL) | BF_PCIE_PHY_MPLL_OVR_RST_LCL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field EN_GS_LCL[4] (RW)
 *
 * Enables local control of gear_shift
 */

#define BP_PCIE_PHY_MPLL_OVR_EN_GS_LCL      (4)      //!< Bit position for PCIE_PHY_MPLL_OVR_EN_GS_LCL.
#define BM_PCIE_PHY_MPLL_OVR_EN_GS_LCL      (0x00000010)  //!< Bit mask for PCIE_PHY_MPLL_OVR_EN_GS_LCL.

//! @brief Get value of PCIE_PHY_MPLL_OVR_EN_GS_LCL from a register value.
#define BG_PCIE_PHY_MPLL_OVR_EN_GS_LCL(r)   (((r) & BM_PCIE_PHY_MPLL_OVR_EN_GS_LCL) >> BP_PCIE_PHY_MPLL_OVR_EN_GS_LCL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_EN_GS_LCL.
#define BF_PCIE_PHY_MPLL_OVR_EN_GS_LCL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVR_EN_GS_LCL) & BM_PCIE_PHY_MPLL_OVR_EN_GS_LCL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_EN_GS_LCL.
#define BF_PCIE_PHY_MPLL_OVR_EN_GS_LCL(v)   (((v) << BP_PCIE_PHY_MPLL_OVR_EN_GS_LCL) & BM_PCIE_PHY_MPLL_OVR_EN_GS_LCL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_GS_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_EN_GS_LCL(v)   (HW_PCIE_PHY_MPLL_OVR_WR((HW_PCIE_PHY_MPLL_OVR_RD() & ~BM_PCIE_PHY_MPLL_OVR_EN_GS_LCL) | BF_PCIE_PHY_MPLL_OVR_EN_GS_LCL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field GS_LCL[5] (RW)
 *
 * local gear_shift value
 */

#define BP_PCIE_PHY_MPLL_OVR_GS_LCL      (5)      //!< Bit position for PCIE_PHY_MPLL_OVR_GS_LCL.
#define BM_PCIE_PHY_MPLL_OVR_GS_LCL      (0x00000020)  //!< Bit mask for PCIE_PHY_MPLL_OVR_GS_LCL.

//! @brief Get value of PCIE_PHY_MPLL_OVR_GS_LCL from a register value.
#define BG_PCIE_PHY_MPLL_OVR_GS_LCL(r)   (((r) & BM_PCIE_PHY_MPLL_OVR_GS_LCL) >> BP_PCIE_PHY_MPLL_OVR_GS_LCL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_GS_LCL.
#define BF_PCIE_PHY_MPLL_OVR_GS_LCL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVR_GS_LCL) & BM_PCIE_PHY_MPLL_OVR_GS_LCL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_GS_LCL.
#define BF_PCIE_PHY_MPLL_OVR_GS_LCL(v)   (((v) << BP_PCIE_PHY_MPLL_OVR_GS_LCL) & BM_PCIE_PHY_MPLL_OVR_GS_LCL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GS_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_GS_LCL(v)   (HW_PCIE_PHY_MPLL_OVR_WR((HW_PCIE_PHY_MPLL_OVR_RD() & ~BM_PCIE_PHY_MPLL_OVR_GS_LCL) | BF_PCIE_PHY_MPLL_OVR_GS_LCL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field EN_PWRON_LCL[6] (RW)
 *
 * Enables local control of power_on
 */

#define BP_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL      (6)      //!< Bit position for PCIE_PHY_MPLL_OVR_EN_PWRON_LCL.
#define BM_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL      (0x00000040)  //!< Bit mask for PCIE_PHY_MPLL_OVR_EN_PWRON_LCL.

//! @brief Get value of PCIE_PHY_MPLL_OVR_EN_PWRON_LCL from a register value.
#define BG_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL(r)   (((r) & BM_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL) >> BP_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_EN_PWRON_LCL.
#define BF_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL) & BM_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_EN_PWRON_LCL.
#define BF_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL(v)   (((v) << BP_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL) & BM_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_PWRON_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL(v)   (HW_PCIE_PHY_MPLL_OVR_WR((HW_PCIE_PHY_MPLL_OVR_RD() & ~BM_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL) | BF_PCIE_PHY_MPLL_OVR_EN_PWRON_LCL(v)))
#endif

/* --- Register HW_PCIE_PHY_MPLL_OVR, field PWRON_LCL[7] (RW)
 *
 * local power_on value
 */

#define BP_PCIE_PHY_MPLL_OVR_PWRON_LCL      (7)      //!< Bit position for PCIE_PHY_MPLL_OVR_PWRON_LCL.
#define BM_PCIE_PHY_MPLL_OVR_PWRON_LCL      (0x00000080)  //!< Bit mask for PCIE_PHY_MPLL_OVR_PWRON_LCL.

//! @brief Get value of PCIE_PHY_MPLL_OVR_PWRON_LCL from a register value.
#define BG_PCIE_PHY_MPLL_OVR_PWRON_LCL(r)   (((r) & BM_PCIE_PHY_MPLL_OVR_PWRON_LCL) >> BP_PCIE_PHY_MPLL_OVR_PWRON_LCL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_PWRON_LCL.
#define BF_PCIE_PHY_MPLL_OVR_PWRON_LCL(v)   ((((reg16_t) v) << BP_PCIE_PHY_MPLL_OVR_PWRON_LCL) & BM_PCIE_PHY_MPLL_OVR_PWRON_LCL)
#else
//! @brief Format value for bitfield PCIE_PHY_MPLL_OVR_PWRON_LCL.
#define BF_PCIE_PHY_MPLL_OVR_PWRON_LCL(v)   (((v) << BP_PCIE_PHY_MPLL_OVR_PWRON_LCL) & BM_PCIE_PHY_MPLL_OVR_PWRON_LCL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PWRON_LCL field to a new value.
#define BW_PCIE_PHY_MPLL_OVR_PWRON_LCL(v)   (HW_PCIE_PHY_MPLL_OVR_WR((HW_PCIE_PHY_MPLL_OVR_RD() & ~BM_PCIE_PHY_MPLL_OVR_PWRON_LCL) | BF_PCIE_PHY_MPLL_OVR_PWRON_LCL(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RTUNE_RTUNE_CTRL -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rtune_rtune_ctrl
{
    reg16_t U;
    struct _hw_pcie_phy_rtune_rtune_ctrl_bitfields
    {
        unsigned short RT_SEL_ATBF : 1; //!< [0] RTUNE ATB input slect bit
        unsigned short RT_SEL_ATBP : 1; //!< [1] RTUNE ATB sense input select bit
        unsigned short RT_ATB : 1; //!< [2] RTUNE ATB mode control bit
        unsigned short RT_DAC_CHOP : 1; //!< [3] Margin DAC chop control bit
        unsigned short RT_DAC_MODE : 2; //!< [5:4] Margin DAC mode control bits
        unsigned short X4_FRC_OFF : 1; //!< [6] When set, do not multiply test current by 4
        unsigned short RT_PWRON_FRC_ON : 1; //!< [7] When set, forces RTUNE block to be on
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved.
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

/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_SEL_ATBF[0] (RW)
 *
 * RTUNE ATB input slect bit
 *
 * Values:
 * 0 - atb_s_p/m
 * 1 - atb_fm
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF      (0)      //!< Bit position for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF.
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF      (0x00000001)  //!< Bit mask for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF.

//! @brief Get value of PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF from a register value.
#define BG_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF(r)   (((r) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF) >> BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF(v)   (((v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_SEL_ATBF field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF(v)   (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR((HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() & ~BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF) | BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBF(v)))
#endif


/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_SEL_ATBP[1] (RW)
 *
 * RTUNE ATB sense input select bit
 *
 * Values:
 * 0 - atb_s_m
 * 1 - atb_s_p
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP      (1)      //!< Bit position for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP.
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP      (0x00000002)  //!< Bit mask for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP.

//! @brief Get value of PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP from a register value.
#define BG_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP(r)   (((r) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP) >> BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP(v)   (((v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_SEL_ATBP field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP(v)   (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR((HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() & ~BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP) | BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_SEL_ATBP(v)))
#endif


/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_ATB[2] (RW)
 *
 * RTUNE ATB mode control bit
 *
 * Values:
 * 0 - not accessing ATB
 * 1 - RTUNE performs ADC on ATB input
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB      (2)      //!< Bit position for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB.
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB      (0x00000004)  //!< Bit mask for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB.

//! @brief Get value of PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB from a register value.
#define BG_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB(r)   (((r) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB) >> BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB(v)   (((v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_ATB field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB(v)   (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR((HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() & ~BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB) | BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_ATB(v)))
#endif


/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_DAC_CHOP[3] (RW)
 *
 * Margin DAC chop control bit
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP      (3)      //!< Bit position for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP.
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP      (0x00000008)  //!< Bit mask for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP.

//! @brief Get value of PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP from a register value.
#define BG_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP(r)   (((r) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP) >> BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP(v)   (((v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_DAC_CHOP field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP(v)   (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR((HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() & ~BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP) | BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_CHOP(v)))
#endif

/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_DAC_MODE[5:4] (RW)
 *
 * Margin DAC mode control bits
 *
 * Values:
 * 00 - powerdown
 * 01 - DAC drives atb_s_p/m directly
 * 10 - DAC drives atb_s_p/m to the RX in margining mode
 * 11 - illegal state
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE      (4)      //!< Bit position for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE.
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE      (0x00000030)  //!< Bit mask for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE.

//! @brief Get value of PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE from a register value.
#define BG_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE(r)   (((r) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE) >> BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE(v)   (((v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_DAC_MODE field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE(v)   (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR((HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() & ~BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE) | BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_DAC_MODE(v)))
#endif


/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field X4_FRC_OFF[6] (RW)
 *
 * When set, do not multiply test current by 4
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF      (6)      //!< Bit position for PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF.
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF      (0x00000040)  //!< Bit mask for PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF.

//! @brief Get value of PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF from a register value.
#define BG_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF(r)   (((r) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF) >> BP_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF(v)   (((v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the X4_FRC_OFF field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF(v)   (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR((HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() & ~BM_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF) | BF_PCIE_PHY_RTUNE_RTUNE_CTRL_X4_FRC_OFF(v)))
#endif

/* --- Register HW_PCIE_PHY_RTUNE_RTUNE_CTRL, field RT_PWRON_FRC_ON[7] (RW)
 *
 * When set, forces RTUNE block to be on
 */

#define BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON      (7)      //!< Bit position for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON.
#define BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON      (0x00000080)  //!< Bit mask for PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON.

//! @brief Get value of PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON from a register value.
#define BG_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON(r)   (((r) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON) >> BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON(v)   ((((reg16_t) v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON)
#else
//! @brief Format value for bitfield PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON.
#define BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON(v)   (((v) << BP_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON) & BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RT_PWRON_FRC_ON field to a new value.
#define BW_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON(v)   (HW_PCIE_PHY_RTUNE_RTUNE_CTRL_WR((HW_PCIE_PHY_RTUNE_RTUNE_CTRL_RD() & ~BM_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON) | BF_PCIE_PHY_RTUNE_RTUNE_CTRL_RT_PWRON_FRC_ON(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_ATB_SWITCHYARD_CTRL -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_atb_switchyard_ctrl
{
    reg16_t U;
    struct _hw_pcie_phy_atb_switchyard_ctrl_bitfields
    {
        unsigned short ASM_GD : 1; //!< [0] Connect atb_s_m to gd
        unsigned short ASP_VP : 1; //!< [1] Connect atb_s_p to vp
        unsigned short ASP_VPHREG : 1; //!< [2] Connect atb_s_p vphreg
        unsigned short ASP_VPH : 1; //!< [3] Connect atb_s_p to vph
        unsigned short ATEST_AFM : 1; //!< [4] Connect atest to atb_f_m
        unsigned short ATEST_AFP : 1; //!< [5] Connect atest to atb_f_p
        unsigned short ATEST_ASM : 1; //!< [6] Connect atest to atb_s_m
        unsigned short ATEST_ASP : 1; //!< [7] Connect atest to atb_s_p
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved.
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

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ASM_GD[0] (RW)
 *
 * Connect atb_s_m to gd
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD      (0)      //!< Bit position for PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD.
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD      (0x00000001)  //!< Bit mask for PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD.

//! @brief Get value of PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD from a register value.
#define BG_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD(r)   (((r) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD) >> BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD)
#else
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD(v)   (((v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASM_GD field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD(v)   (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR((HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD) | BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASM_GD(v)))
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ASP_VP[1] (RW)
 *
 * Connect atb_s_p to vp
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP      (1)      //!< Bit position for PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP.
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP      (0x00000002)  //!< Bit mask for PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP.

//! @brief Get value of PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP from a register value.
#define BG_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP(r)   (((r) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP) >> BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP)
#else
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP(v)   (((v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP_VP field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP(v)   (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR((HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP) | BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VP(v)))
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ASP_VPHREG[2] (RW)
 *
 * Connect atb_s_p vphreg
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG      (2)      //!< Bit position for PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG.
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG      (0x00000004)  //!< Bit mask for PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG.

//! @brief Get value of PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG from a register value.
#define BG_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG(r)   (((r) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG) >> BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG)
#else
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG(v)   (((v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP_VPHREG field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG(v)   (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR((HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG) | BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPHREG(v)))
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ASP_VPH[3] (RW)
 *
 * Connect atb_s_p to vph
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH      (3)      //!< Bit position for PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH.
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH      (0x00000008)  //!< Bit mask for PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH.

//! @brief Get value of PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH from a register value.
#define BG_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH(r)   (((r) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH) >> BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH)
#else
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH(v)   (((v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP_VPH field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH(v)   (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR((HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH) | BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ASP_VPH(v)))
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ATEST_AFM[4] (RW)
 *
 * Connect atest to atb_f_m
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM      (4)      //!< Bit position for PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM.
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM      (0x00000010)  //!< Bit mask for PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM.

//! @brief Get value of PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM from a register value.
#define BG_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM(r)   (((r) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM) >> BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM)
#else
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM(v)   (((v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEST_AFM field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM(v)   (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR((HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM) | BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFM(v)))
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ATEST_AFP[5] (RW)
 *
 * Connect atest to atb_f_p
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP      (5)      //!< Bit position for PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP.
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP      (0x00000020)  //!< Bit mask for PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP.

//! @brief Get value of PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP from a register value.
#define BG_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP(r)   (((r) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP) >> BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP)
#else
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP(v)   (((v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEST_AFP field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP(v)   (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR((HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP) | BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_AFP(v)))
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ATEST_ASM[6] (RW)
 *
 * Connect atest to atb_s_m
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM      (6)      //!< Bit position for PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM.
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM      (0x00000040)  //!< Bit mask for PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM.

//! @brief Get value of PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM from a register value.
#define BG_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM(r)   (((r) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM) >> BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM)
#else
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM(v)   (((v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEST_ASM field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM(v)   (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR((HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM) | BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASM(v)))
#endif

/* --- Register HW_PCIE_PHY_ATB_SWITCHYARD_CTRL, field ATEST_ASP[7] (RW)
 *
 * Connect atest to atb_s_p
 */

#define BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP      (7)      //!< Bit position for PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP.
#define BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP      (0x00000080)  //!< Bit mask for PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP.

//! @brief Get value of PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP from a register value.
#define BG_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP(r)   (((r) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP) >> BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP(v)   ((((reg16_t) v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP)
#else
//! @brief Format value for bitfield PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP.
#define BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP(v)   (((v) << BP_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP) & BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEST_ASP field to a new value.
#define BW_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP(v)   (HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_WR((HW_PCIE_PHY_ATB_SWITCHYARD_CTRL_RD() & ~BM_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP) | BF_PCIE_PHY_ATB_SWITCHYARD_CTRL_ATEST_ASP(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_OVRD_IN_LO -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_ovrd_in_lo
{
    reg16_t U;
    struct _hw_pcie_phy_tx_ovrd_in_lo_bitfields
    {
        unsigned short LOOPBK_EN : 1; //!< [0] Override value for loopbk_en
        unsigned short TX_LOOPBK_EN_OVRD : 1; //!< [1] Override enable for loopbk_en
        unsigned short TX_INVERT : 1; //!< [2] Override value for tx_invert
        unsigned short TX_INVERT_OVRD : 1; //!< [3] Override enable for tx_invert
        unsigned short TX_DATA_EN : 1; //!< [4] Override value for tx_data_en
        unsigned short TX_DATA_EN_OVRD : 1; //!< [5] Override enable for tx_data_en
        unsigned short TX_EN : 1; //!< [6] Override value for tx_en
        unsigned short TX_EN_OVRD : 1; //!< [7] Override enable for tx_en
        unsigned short TX_CM_EN : 1; //!< [8] Override value for tx_cm_en
        unsigned short TX_CM_EN_OVRD : 1; //!< [9] Override enable for tx_cm_en
        unsigned short TX_BEACON_EN : 1; //!< [10] Override value for tx_beacon_en
        unsigned short TX_BEACON_EN_OVRD : 1; //!< [11] Override enable for tx_beacon_en
        unsigned short TX_DETECT_RX_REQ : 1; //!< [12] Override value for tx_detect_rx_req
        unsigned short TX_DETECT_RX_REQ_OVRD : 1; //!< [13] Override enable for tx_detect_rx_req
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field LOOPBK_EN[0] (RW)
 *
 * Override value for loopbk_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN      (0)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN) >> BP_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOPBK_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN) | BF_PCIE_PHY_TX_OVRD_IN_LO_LOOPBK_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_LOOPBK_EN_OVRD[1] (RW)
 *
 * Override enable for loopbk_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD      (1)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD      (0x00000002)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_LOOPBK_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_LOOPBK_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_INVERT[2] (RW)
 *
 * Override value for tx_invert
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT      (2)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_INVERT field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_INVERT_OVRD[3] (RW)
 *
 * Override enable for tx_invert
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD      (3)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_INVERT_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_INVERT_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_DATA_EN[4] (RW)
 *
 * Override value for tx_data_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN      (4)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DATA_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_DATA_EN_OVRD[5] (RW)
 *
 * Override enable for tx_data_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD      (5)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD      (0x00000020)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DATA_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DATA_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_EN[6] (RW)
 *
 * Override value for tx_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN      (6)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_EN.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN      (0x00000040)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_EN.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_EN from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_EN(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_EN(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_EN_OVRD[7] (RW)
 *
 * Override enable for tx_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD      (7)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_CM_EN[8] (RW)
 *
 * Override value for tx_cm_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN      (8)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN      (0x00000100)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CM_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_CM_EN_OVRD[9] (RW)
 *
 * Override enable for tx_cm_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD      (9)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD      (0x00000200)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CM_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_CM_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_BEACON_EN[10] (RW)
 *
 * Override value for tx_beacon_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN      (10)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN      (0x00000400)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_BEACON_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_BEACON_EN_OVRD[11] (RW)
 *
 * Override enable for tx_beacon_en
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD      (11)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD      (0x00000800)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_BEACON_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_BEACON_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_DETECT_RX_REQ[12] (RW)
 *
 * Override value for tx_detect_rx_req
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ      (12)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ      (0x00001000)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DETECT_RX_REQ field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_LO, field TX_DETECT_RX_REQ_OVRD[13] (RW)
 *
 * Override enable for tx_detect_rx_req
 */

#define BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD      (13)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD      (0x00002000)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DETECT_RX_REQ_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_LO_WR((HW_PCIE_PHY_TX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_LO_TX_DETECT_RX_REQ_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_OVRD_IN_HI -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_ovrd_in_hi
{
    reg16_t U;
    struct _hw_pcie_phy_tx_ovrd_in_hi_bitfields
    {
        unsigned short TX_RATE : 2; //!< [1:0] Override incomming tx lane rate.
        unsigned short TX_RATE_OVRD : 1; //!< [2] Override enable for tx_rate.
        unsigned short TX_CLK_OUT_EN : 1; //!< [3] Override incomming tx_clk_out_en.
        unsigned short TX_CLK_OUT_EN_OVRD : 1; //!< [4] Override enable for tx_clk_out_en.
        unsigned short TX_NYQUIST_DATA : 1; //!< [5] Override incoming data to nyquist
        unsigned short TX_RESET : 1; //!< [6] Override value for tx_reset
        unsigned short TX_RESET_OVRD : 1; //!< [7] Override enable for tx_reset
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_RATE[1:0] (RW)
 *
 * Override incomming tx lane rate.
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE      (0)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_HI_TX_RATE.
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE      (0x00000003)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_HI_TX_RATE.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_HI_TX_RATE from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE) >> BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_RATE.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_RATE.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RATE field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE(v)   (HW_PCIE_PHY_TX_OVRD_IN_HI_WR((HW_PCIE_PHY_TX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE) | BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_RATE_OVRD[2] (RW)
 *
 * Override enable for tx_rate.
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD      (2)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RATE_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_HI_WR((HW_PCIE_PHY_TX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RATE_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_CLK_OUT_EN[3] (RW)
 *
 * Override incomming tx_clk_out_en.
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN      (3)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN.
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN) >> BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CLK_OUT_EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN(v)   (HW_PCIE_PHY_TX_OVRD_IN_HI_WR((HW_PCIE_PHY_TX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN) | BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_CLK_OUT_EN_OVRD[4] (RW)
 *
 * Override enable for tx_clk_out_en.
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD      (4)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CLK_OUT_EN_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_HI_WR((HW_PCIE_PHY_TX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_HI_TX_CLK_OUT_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_NYQUIST_DATA[5] (RW)
 *
 * Override incoming data to nyquist
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA      (5)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA.
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA      (0x00000020)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA) >> BP_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_NYQUIST_DATA field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA(v)   (HW_PCIE_PHY_TX_OVRD_IN_HI_WR((HW_PCIE_PHY_TX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA) | BF_PCIE_PHY_TX_OVRD_IN_HI_TX_NYQUIST_DATA(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_RESET[6] (RW)
 *
 * Override value for tx_reset
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET      (6)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_HI_TX_RESET.
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET      (0x00000040)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_HI_TX_RESET.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_HI_TX_RESET from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET) >> BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_RESET.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_RESET.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RESET field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET(v)   (HW_PCIE_PHY_TX_OVRD_IN_HI_WR((HW_PCIE_PHY_TX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET) | BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_IN_HI, field TX_RESET_OVRD[7] (RW)
 *
 * Override enable for tx_reset
 */

#define BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD      (7)      //!< Bit position for PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD.
#define BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD) >> BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD.
#define BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD) & BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RESET_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_IN_HI_WR((HW_PCIE_PHY_TX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD) | BF_PCIE_PHY_TX_OVRD_IN_HI_TX_RESET_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_OVRD_DRV_LO -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_ovrd_drv_lo
{
    reg16_t U;
    struct _hw_pcie_phy_tx_ovrd_drv_lo_bitfields
    {
        unsigned short AMPLITUDE : 7; //!< [6:0] Override value for transmit amplitude.
        unsigned short PREEMPH : 7; //!< [13:7] Override value for transmit preemphasis
        unsigned short EN : 1; //!< [14] Enables override values for all inputs controlled by this register
        unsigned short RESERVED0 : 1; //!< [15] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_OVRD_DRV_LO, field AMPLITUDE[6:0] (RW)
 *
 * Override value for transmit amplitude.
 */

#define BP_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE      (0)      //!< Bit position for PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE.
#define BM_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE      (0x0000007f)  //!< Bit mask for PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE.

//! @brief Get value of PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE from a register value.
#define BG_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE(r)   (((r) & BM_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE) >> BP_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE.
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE) & BM_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE.
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE(v)   (((v) << BP_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE) & BM_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AMPLITUDE field to a new value.
#define BW_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE(v)   (HW_PCIE_PHY_TX_OVRD_DRV_LO_WR((HW_PCIE_PHY_TX_OVRD_DRV_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE) | BF_PCIE_PHY_TX_OVRD_DRV_LO_AMPLITUDE(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_DRV_LO, field PREEMPH[13:7] (RW)
 *
 * Override value for transmit preemphasis
 */

#define BP_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH      (7)      //!< Bit position for PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH.
#define BM_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH      (0x00003f80)  //!< Bit mask for PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH.

//! @brief Get value of PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH from a register value.
#define BG_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH(r)   (((r) & BM_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH) >> BP_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH.
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH) & BM_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH.
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH(v)   (((v) << BP_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH) & BM_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PREEMPH field to a new value.
#define BW_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH(v)   (HW_PCIE_PHY_TX_OVRD_DRV_LO_WR((HW_PCIE_PHY_TX_OVRD_DRV_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH) | BF_PCIE_PHY_TX_OVRD_DRV_LO_PREEMPH(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_DRV_LO, field EN[14] (RW)
 *
 * Enables override values for all inputs controlled by this register
 */

#define BP_PCIE_PHY_TX_OVRD_DRV_LO_EN      (14)      //!< Bit position for PCIE_PHY_TX_OVRD_DRV_LO_EN.
#define BM_PCIE_PHY_TX_OVRD_DRV_LO_EN      (0x00004000)  //!< Bit mask for PCIE_PHY_TX_OVRD_DRV_LO_EN.

//! @brief Get value of PCIE_PHY_TX_OVRD_DRV_LO_EN from a register value.
#define BG_PCIE_PHY_TX_OVRD_DRV_LO_EN(r)   (((r) & BM_PCIE_PHY_TX_OVRD_DRV_LO_EN) >> BP_PCIE_PHY_TX_OVRD_DRV_LO_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_DRV_LO_EN.
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_DRV_LO_EN) & BM_PCIE_PHY_TX_OVRD_DRV_LO_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_DRV_LO_EN.
#define BF_PCIE_PHY_TX_OVRD_DRV_LO_EN(v)   (((v) << BP_PCIE_PHY_TX_OVRD_DRV_LO_EN) & BM_PCIE_PHY_TX_OVRD_DRV_LO_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_PCIE_PHY_TX_OVRD_DRV_LO_EN(v)   (HW_PCIE_PHY_TX_OVRD_DRV_LO_WR((HW_PCIE_PHY_TX_OVRD_DRV_LO_RD() & ~BM_PCIE_PHY_TX_OVRD_DRV_LO_EN) | BF_PCIE_PHY_TX_OVRD_DRV_LO_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_OVRD_OUT -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_ovrd_out
{
    reg16_t U;
    struct _hw_pcie_phy_tx_ovrd_out_bitfields
    {
        unsigned short DETECT_RX_RES : 1; //!< [0] Override value for tx_detect_rx_res
        unsigned short DETECT_RX_RES_OVRD : 1; //!< [1] Override enable for tx_detect_rx_res
        unsigned short TX_DETECT_RX_ACK : 1; //!< [2] Override value for tx_detect_rx_ack
        unsigned short TX_DETECT_RX_ACK_OVRD : 1; //!< [3] Override enable for tx_detect_rx_ack
        unsigned short TX_CM_STATE : 1; //!< [4] Override value for tx_cm_state
        unsigned short TX_CM_STATE_OVRD : 1; //!< [5] Override enable for tx_cm_state
        unsigned short TX_STATE : 1; //!< [6] Override value for tx_state
        unsigned short TX_STATE_OVRD : 1; //!< [7] Override enable for tx_state
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field DETECT_RX_RES[0] (RW)
 *
 * Override value for tx_detect_rx_res
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES      (0)      //!< Bit position for PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES.
#define BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES.

//! @brief Get value of PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES from a register value.
#define BG_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES(r)   (((r) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES) >> BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES.
#define BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES.
#define BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES(v)   (((v) << BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DETECT_RX_RES field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES(v)   (HW_PCIE_PHY_TX_OVRD_OUT_WR((HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES) | BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field DETECT_RX_RES_OVRD[1] (RW)
 *
 * Override enable for tx_detect_rx_res
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD      (1)      //!< Bit position for PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD.
#define BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD      (0x00000002)  //!< Bit mask for PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD) >> BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD.
#define BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD.
#define BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD) & BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DETECT_RX_RES_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_OUT_WR((HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~BM_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD) | BF_PCIE_PHY_TX_OVRD_OUT_DETECT_RX_RES_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_DETECT_RX_ACK[2] (RW)
 *
 * Override value for tx_detect_rx_ack
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK      (2)      //!< Bit position for PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK.
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK.

//! @brief Get value of PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK from a register value.
#define BG_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK(r)   (((r) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK) >> BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK(v)   (((v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DETECT_RX_ACK field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK(v)   (HW_PCIE_PHY_TX_OVRD_OUT_WR((HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK) | BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_DETECT_RX_ACK_OVRD[3] (RW)
 *
 * Override enable for tx_detect_rx_ack
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD      (3)      //!< Bit position for PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD.
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD) >> BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD) & BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DETECT_RX_ACK_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_OUT_WR((HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~BM_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD) | BF_PCIE_PHY_TX_OVRD_OUT_TX_DETECT_RX_ACK_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_CM_STATE[4] (RW)
 *
 * Override value for tx_cm_state
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE      (4)      //!< Bit position for PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE.
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE.

//! @brief Get value of PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE from a register value.
#define BG_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE(r)   (((r) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE) >> BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE(v)   (((v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CM_STATE field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE(v)   (HW_PCIE_PHY_TX_OVRD_OUT_WR((HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE) | BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_CM_STATE_OVRD[5] (RW)
 *
 * Override enable for tx_cm_state
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD      (5)      //!< Bit position for PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD.
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD      (0x00000020)  //!< Bit mask for PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD) >> BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD) & BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CM_STATE_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_OUT_WR((HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~BM_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD) | BF_PCIE_PHY_TX_OVRD_OUT_TX_CM_STATE_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_STATE[6] (RW)
 *
 * Override value for tx_state
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE      (6)      //!< Bit position for PCIE_PHY_TX_OVRD_OUT_TX_STATE.
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE      (0x00000040)  //!< Bit mask for PCIE_PHY_TX_OVRD_OUT_TX_STATE.

//! @brief Get value of PCIE_PHY_TX_OVRD_OUT_TX_STATE from a register value.
#define BG_PCIE_PHY_TX_OVRD_OUT_TX_STATE(r)   (((r) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE) >> BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_STATE.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_STATE.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE(v)   (((v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_STATE field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_STATE(v)   (HW_PCIE_PHY_TX_OVRD_OUT_WR((HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE) | BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_OVRD_OUT, field TX_STATE_OVRD[7] (RW)
 *
 * Override enable for tx_state
 */

#define BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD      (7)      //!< Bit position for PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD.
#define BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD.

//! @brief Get value of PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD from a register value.
#define BG_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD(r)   (((r) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD) >> BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD.
#define BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD(v)   (((v) << BP_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD) & BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_STATE_OVRD field to a new value.
#define BW_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD(v)   (HW_PCIE_PHY_TX_OVRD_OUT_WR((HW_PCIE_PHY_TX_OVRD_OUT_RD() & ~BM_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD) | BF_PCIE_PHY_TX_OVRD_OUT_TX_STATE_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_OVRD_IN_LO -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_ovrd_in_lo
{
    reg16_t U;
    struct _hw_pcie_phy_rx_ovrd_in_lo_bitfields
    {
        unsigned short RX_INVERT : 1; //!< [0] Override value for rx_invert
        unsigned short RX_INVERT_OVRD : 1; //!< [1] Override enable for rx_invert
        unsigned short RX_PLL_EN : 1; //!< [2] Override value for rx_pll_en
        unsigned short RX_PLL_EN_OVRD : 1; //!< [3] Override enable for rx_pll_en
        unsigned short RX_DATA_EN : 1; //!< [4] Override value for rx_data_en
        unsigned short RX_DATA_EN_OVRD : 1; //!< [5] Override enable for rx_data_en
        unsigned short RX_ALIGN_EN : 1; //!< [6] Override value for rx_align_en
        unsigned short RX_ALIGN_EN_OVRD : 1; //!< [7] Override enable for rx_align_en
        unsigned short RX_BIT_SHIFT : 1; //!< [8] Override value for rx_bit_shift
        unsigned short RX_BIT_SHIFT_OVRD : 1; //!< [9] Override enable for rx_bit_shift
        unsigned short RX_TERM_EN : 1; //!< [10] Override value for rx_term_en
        unsigned short RX_TERM_EN_OVRD : 1; //!< [11] Override enable for rx_term_en
        unsigned short RX_LOS_EN : 1; //!< [12] Override value for rx_los_en
        unsigned short RX_LOS_EN_OVRD : 1; //!< [13] Override enable for rx_los_en
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved.
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

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_INVERT[0] (RW)
 *
 * Override value for rx_invert
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT      (0)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_INVERT field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_INVERT_OVRD[1] (RW)
 *
 * Override enable for rx_invert
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD      (1)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_INVERT_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_INVERT_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_PLL_EN[2] (RW)
 *
 * Override value for rx_pll_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN      (2)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_PLL_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_PLL_EN_OVRD[3] (RW)
 *
 * Override enable for rx_pll_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD      (3)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_PLL_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_PLL_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_DATA_EN[4] (RW)
 *
 * Override value for rx_data_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN      (4)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_DATA_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_DATA_EN_OVRD[5] (RW)
 *
 * Override enable for rx_data_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD      (5)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_DATA_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_DATA_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_ALIGN_EN[6] (RW)
 *
 * Override value for rx_align_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN      (6)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ALIGN_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_ALIGN_EN_OVRD[7] (RW)
 *
 * Override enable for rx_align_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD      (7)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ALIGN_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_ALIGN_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_BIT_SHIFT[8] (RW)
 *
 * Override value for rx_bit_shift
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT      (8)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT      (0x00000100)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_BIT_SHIFT field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_BIT_SHIFT_OVRD[9] (RW)
 *
 * Override enable for rx_bit_shift
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD      (9)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD      (0x00000200)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_BIT_SHIFT_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_BIT_SHIFT_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_TERM_EN[10] (RW)
 *
 * Override value for rx_term_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN      (10)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN      (0x00000400)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_TERM_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_TERM_EN_OVRD[11] (RW)
 *
 * Override enable for rx_term_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD      (11)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD      (0x00000800)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_TERM_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_TERM_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_LOS_EN[12] (RW)
 *
 * Override value for rx_los_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN      (12)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN      (0x00001000)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_LOS_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_LO, field RX_LOS_EN_OVRD[13] (RW)
 *
 * Override enable for rx_los_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD      (13)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD      (0x00002000)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_LOS_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_LO_WR((HW_PCIE_PHY_RX_OVRD_IN_LO_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_LO_RX_LOS_EN_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_OVRD_IN_HI -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_ovrd_in_hi
{
    reg16_t U;
    struct _hw_pcie_phy_rx_ovrd_in_hi_bitfields
    {
        unsigned short RX_RATE : 2; //!< [1:0] Override value for rx_rate
        unsigned short RX_RATE_OVRD : 1; //!< [2] Override enable for rx_rate
        unsigned short RX_LOS_FILTER : 2; //!< [4:3] Override value for rx_los_filter
        unsigned short RX_LOS_FILTER_OVRD : 1; //!< [5] Override enable for rx_los_filter
        unsigned short RX_EQ_EN : 1; //!< [6] Override value for rx_eq_en
        unsigned short RX_EQ_EN_OVRD : 1; //!< [7] Override enable for rx_eq_en
        unsigned short RX_EQ : 3; //!< [10:8] Override value for rx_eq
        unsigned short RX_EQ_OVRD : 1; //!< [11] Override enable for rx_eq
        unsigned short RX_RESET : 1; //!< [12] Override value for rx_reset
        unsigned short RX_RESET_OVRD : 1; //!< [13] Override enable for rx_reset
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved.
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

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_RATE[1:0] (RW)
 *
 * Override value for rx_rate
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE      (0)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_RATE.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE      (0x00000003)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_RATE.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_RATE from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_RATE.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_RATE.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_RATE field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_RATE_OVRD[2] (RW)
 *
 * Override enable for rx_rate
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD      (2)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_RATE_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RATE_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_LOS_FILTER[4:3] (RW)
 *
 * Override value for rx_los_filter
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER      (3)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER      (0x00000018)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_LOS_FILTER field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_LOS_FILTER_OVRD[5] (RW)
 *
 * Override enable for rx_los_filter
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD      (5)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_LOS_FILTER_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_LOS_FILTER_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_EQ_EN[6] (RW)
 *
 * Override value for rx_eq_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN      (6)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ_EN field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_EQ_EN_OVRD[7] (RW)
 *
 * Override enable for rx_eq_en
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD      (7)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ_EN_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_EN_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_EQ[10:8] (RW)
 *
 * Override value for rx_eq
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ      (8)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_EQ.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ      (0x00000700)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_EQ.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_EQ from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_EQ.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_EQ.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_EQ_OVRD[11] (RW)
 *
 * Override enable for rx_eq
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD      (11)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD      (0x00000800)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_EQ_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_EQ_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_RESET[12] (RW)
 *
 * Override value for rx_reset
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET      (12)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_RESET.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET      (0x00001000)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_RESET.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_RESET from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_RESET.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_RESET.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_RESET field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_IN_HI, field RX_RESET_OVRD[13] (RW)
 *
 * Override enable for rx_reset
 */

#define BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD      (13)      //!< Bit position for PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD.
#define BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD      (0x00002000)  //!< Bit mask for PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD) >> BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD.
#define BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD) & BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_RESET_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_IN_HI_WR((HW_PCIE_PHY_RX_OVRD_IN_HI_RD() & ~BM_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD) | BF_PCIE_PHY_RX_OVRD_IN_HI_RX_RESET_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_OVRD_OUT -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_ovrd_out
{
    reg16_t U;
    struct _hw_pcie_phy_rx_ovrd_out_bitfields
    {
        unsigned short VALID : 1; //!< [0] Override value for rx_valid
        unsigned short VALID_OVRD : 1; //!< [1] Override enable for rx_valid
        unsigned short PLL_STATE : 1; //!< [2] Override value for rx_pll_state
        unsigned short PLL_STATE_OVRD : 1; //!< [3] Override enable for rx_pll_state
        unsigned short LOS : 1; //!< [4] Override value for rx_los
        unsigned short LOS_OVRD : 1; //!< [5] Override value for rx_los
        unsigned short ZERO_DATA : 1; //!< [6] Override data output to all zeros
        unsigned short RESERVED0 : 9; //!< [15:7] Reserved.
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

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field VALID[0] (RW)
 *
 * Override value for rx_valid
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_VALID      (0)      //!< Bit position for PCIE_PHY_RX_OVRD_OUT_VALID.
#define BM_PCIE_PHY_RX_OVRD_OUT_VALID      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_OVRD_OUT_VALID.

//! @brief Get value of PCIE_PHY_RX_OVRD_OUT_VALID from a register value.
#define BG_PCIE_PHY_RX_OVRD_OUT_VALID(r)   (((r) & BM_PCIE_PHY_RX_OVRD_OUT_VALID) >> BP_PCIE_PHY_RX_OVRD_OUT_VALID)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_VALID.
#define BF_PCIE_PHY_RX_OVRD_OUT_VALID(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_OUT_VALID) & BM_PCIE_PHY_RX_OVRD_OUT_VALID)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_VALID.
#define BF_PCIE_PHY_RX_OVRD_OUT_VALID(v)   (((v) << BP_PCIE_PHY_RX_OVRD_OUT_VALID) & BM_PCIE_PHY_RX_OVRD_OUT_VALID)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALID field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_VALID(v)   (HW_PCIE_PHY_RX_OVRD_OUT_WR((HW_PCIE_PHY_RX_OVRD_OUT_RD() & ~BM_PCIE_PHY_RX_OVRD_OUT_VALID) | BF_PCIE_PHY_RX_OVRD_OUT_VALID(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field VALID_OVRD[1] (RW)
 *
 * Override enable for rx_valid
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD      (1)      //!< Bit position for PCIE_PHY_RX_OVRD_OUT_VALID_OVRD.
#define BM_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_OVRD_OUT_VALID_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_OUT_VALID_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD) >> BP_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_VALID_OVRD.
#define BF_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD) & BM_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_VALID_OVRD.
#define BF_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD) & BM_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALID_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_OUT_WR((HW_PCIE_PHY_RX_OVRD_OUT_RD() & ~BM_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD) | BF_PCIE_PHY_RX_OVRD_OUT_VALID_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field PLL_STATE[2] (RW)
 *
 * Override value for rx_pll_state
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE      (2)      //!< Bit position for PCIE_PHY_RX_OVRD_OUT_PLL_STATE.
#define BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_OVRD_OUT_PLL_STATE.

//! @brief Get value of PCIE_PHY_RX_OVRD_OUT_PLL_STATE from a register value.
#define BG_PCIE_PHY_RX_OVRD_OUT_PLL_STATE(r)   (((r) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE) >> BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_PLL_STATE.
#define BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_PLL_STATE.
#define BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE(v)   (((v) << BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_STATE field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_PLL_STATE(v)   (HW_PCIE_PHY_RX_OVRD_OUT_WR((HW_PCIE_PHY_RX_OVRD_OUT_RD() & ~BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE) | BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field PLL_STATE_OVRD[3] (RW)
 *
 * Override enable for rx_pll_state
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD      (3)      //!< Bit position for PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD.
#define BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD) >> BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD.
#define BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD.
#define BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD) & BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_STATE_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_OUT_WR((HW_PCIE_PHY_RX_OVRD_OUT_RD() & ~BM_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD) | BF_PCIE_PHY_RX_OVRD_OUT_PLL_STATE_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field LOS[4] (RW)
 *
 * Override value for rx_los
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_LOS      (4)      //!< Bit position for PCIE_PHY_RX_OVRD_OUT_LOS.
#define BM_PCIE_PHY_RX_OVRD_OUT_LOS      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_OVRD_OUT_LOS.

//! @brief Get value of PCIE_PHY_RX_OVRD_OUT_LOS from a register value.
#define BG_PCIE_PHY_RX_OVRD_OUT_LOS(r)   (((r) & BM_PCIE_PHY_RX_OVRD_OUT_LOS) >> BP_PCIE_PHY_RX_OVRD_OUT_LOS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_LOS.
#define BF_PCIE_PHY_RX_OVRD_OUT_LOS(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_OUT_LOS) & BM_PCIE_PHY_RX_OVRD_OUT_LOS)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_LOS.
#define BF_PCIE_PHY_RX_OVRD_OUT_LOS(v)   (((v) << BP_PCIE_PHY_RX_OVRD_OUT_LOS) & BM_PCIE_PHY_RX_OVRD_OUT_LOS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_LOS(v)   (HW_PCIE_PHY_RX_OVRD_OUT_WR((HW_PCIE_PHY_RX_OVRD_OUT_RD() & ~BM_PCIE_PHY_RX_OVRD_OUT_LOS) | BF_PCIE_PHY_RX_OVRD_OUT_LOS(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field LOS_OVRD[5] (RW)
 *
 * Override value for rx_los
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD      (5)      //!< Bit position for PCIE_PHY_RX_OVRD_OUT_LOS_OVRD.
#define BM_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_OVRD_OUT_LOS_OVRD.

//! @brief Get value of PCIE_PHY_RX_OVRD_OUT_LOS_OVRD from a register value.
#define BG_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD(r)   (((r) & BM_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD) >> BP_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_LOS_OVRD.
#define BF_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD) & BM_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_LOS_OVRD.
#define BF_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD(v)   (((v) << BP_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD) & BM_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS_OVRD field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD(v)   (HW_PCIE_PHY_RX_OVRD_OUT_WR((HW_PCIE_PHY_RX_OVRD_OUT_RD() & ~BM_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD) | BF_PCIE_PHY_RX_OVRD_OUT_LOS_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_OVRD_OUT, field ZERO_DATA[6] (RW)
 *
 * Override data output to all zeros
 */

#define BP_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA      (6)      //!< Bit position for PCIE_PHY_RX_OVRD_OUT_ZERO_DATA.
#define BM_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_OVRD_OUT_ZERO_DATA.

//! @brief Get value of PCIE_PHY_RX_OVRD_OUT_ZERO_DATA from a register value.
#define BG_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA(r)   (((r) & BM_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA) >> BP_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_ZERO_DATA.
#define BF_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA) & BM_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_OVRD_OUT_ZERO_DATA.
#define BF_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA(v)   (((v) << BP_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA) & BM_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ZERO_DATA field to a new value.
#define BW_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA(v)   (HW_PCIE_PHY_RX_OVRD_OUT_WR((HW_PCIE_PHY_RX_OVRD_OUT_RD() & ~BM_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA) | BF_PCIE_PHY_RX_OVRD_OUT_ZERO_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ASIC_IN -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_asic_in
{
    reg16_t U;
    struct _hw_pcie_phy_tx_asic_in_bitfields
    {
        unsigned short TX_RATE : 2; //!< [1:0] Value from ASIC for tx_rate
        unsigned short LOOPBK_EN : 1; //!< [2] Value from ASIC for loopbk_en
        unsigned short INVERT : 1; //!< [3] Value from ASIC for tx_invert
        unsigned short TX_RESET : 1; //!< [4] Value from ASIC for tx_reset
        unsigned short DATA_EN : 1; //!< [5] Value from ASIC for tx_data_en
        unsigned short TX_EN : 1; //!< [6] Value from ASIC for tx_en
        unsigned short CM_EN : 1; //!< [7] Value from ASIC for tx_cm_en
        unsigned short BEACON_EN : 1; //!< [8] Value from ASIC for tx_beacon_en
        unsigned short DETECT_RX_REQ : 1; //!< [9] Value from ASIC for tx_detect_rx_req
        unsigned short TX_CLK_OUT_EN : 1; //!< [10] Value from ASIC for tx_clk_out_en
        unsigned short RESERVED0 : 5; //!< [15:11] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field TX_RATE[1:0] (RO)
 *
 * Value from ASIC for tx_rate
 */

#define BP_PCIE_PHY_TX_ASIC_IN_TX_RATE      (0)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_TX_RATE.
#define BM_PCIE_PHY_TX_ASIC_IN_TX_RATE      (0x00000003)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_TX_RATE.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_TX_RATE from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_TX_RATE(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_TX_RATE) >> BP_PCIE_PHY_TX_ASIC_IN_TX_RATE)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field LOOPBK_EN[2] (RO)
 *
 * Value from ASIC for loopbk_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_LOOPBK_EN      (2)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_LOOPBK_EN.
#define BM_PCIE_PHY_TX_ASIC_IN_LOOPBK_EN      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_LOOPBK_EN.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_LOOPBK_EN from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_LOOPBK_EN(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_LOOPBK_EN) >> BP_PCIE_PHY_TX_ASIC_IN_LOOPBK_EN)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field INVERT[3] (RO)
 *
 * Value from ASIC for tx_invert
 */

#define BP_PCIE_PHY_TX_ASIC_IN_INVERT      (3)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_INVERT.
#define BM_PCIE_PHY_TX_ASIC_IN_INVERT      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_INVERT.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_INVERT from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_INVERT(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_INVERT) >> BP_PCIE_PHY_TX_ASIC_IN_INVERT)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field TX_RESET[4] (RO)
 *
 * Value from ASIC for tx_reset
 */

#define BP_PCIE_PHY_TX_ASIC_IN_TX_RESET      (4)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_TX_RESET.
#define BM_PCIE_PHY_TX_ASIC_IN_TX_RESET      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_TX_RESET.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_TX_RESET from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_TX_RESET(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_TX_RESET) >> BP_PCIE_PHY_TX_ASIC_IN_TX_RESET)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field DATA_EN[5] (RO)
 *
 * Value from ASIC for tx_data_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_DATA_EN      (5)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_DATA_EN.
#define BM_PCIE_PHY_TX_ASIC_IN_DATA_EN      (0x00000020)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_DATA_EN.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_DATA_EN from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_DATA_EN(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_DATA_EN) >> BP_PCIE_PHY_TX_ASIC_IN_DATA_EN)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field TX_EN[6] (RO)
 *
 * Value from ASIC for tx_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_TX_EN      (6)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_TX_EN.
#define BM_PCIE_PHY_TX_ASIC_IN_TX_EN      (0x00000040)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_TX_EN.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_TX_EN from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_TX_EN(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_TX_EN) >> BP_PCIE_PHY_TX_ASIC_IN_TX_EN)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field CM_EN[7] (RO)
 *
 * Value from ASIC for tx_cm_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_CM_EN      (7)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_CM_EN.
#define BM_PCIE_PHY_TX_ASIC_IN_CM_EN      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_CM_EN.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_CM_EN from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_CM_EN(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_CM_EN) >> BP_PCIE_PHY_TX_ASIC_IN_CM_EN)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field BEACON_EN[8] (RO)
 *
 * Value from ASIC for tx_beacon_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_BEACON_EN      (8)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_BEACON_EN.
#define BM_PCIE_PHY_TX_ASIC_IN_BEACON_EN      (0x00000100)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_BEACON_EN.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_BEACON_EN from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_BEACON_EN(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_BEACON_EN) >> BP_PCIE_PHY_TX_ASIC_IN_BEACON_EN)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field DETECT_RX_REQ[9] (RO)
 *
 * Value from ASIC for tx_detect_rx_req
 */

#define BP_PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ      (9)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ.
#define BM_PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ      (0x00000200)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ) >> BP_PCIE_PHY_TX_ASIC_IN_DETECT_RX_REQ)

/* --- Register HW_PCIE_PHY_TX_ASIC_IN, field TX_CLK_OUT_EN[10] (RO)
 *
 * Value from ASIC for tx_clk_out_en
 */

#define BP_PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN      (10)      //!< Bit position for PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN.
#define BM_PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN      (0x00000400)  //!< Bit mask for PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN.

//! @brief Get value of PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN from a register value.
#define BG_PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN(r)   (((r) & BM_PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN) >> BP_PCIE_PHY_TX_ASIC_IN_TX_CLK_OUT_EN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ASIC_DRV_LO -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_asic_drv_lo
{
    reg16_t U;
    struct _hw_pcie_phy_tx_asic_drv_lo_bitfields
    {
        unsigned short AMPLITUDE : 7; //!< [6:0] Value from ASIC for tx_amplitude
        unsigned short PREEMPH : 7; //!< [13:7] Value from ASIC for tx_preemph
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_ASIC_DRV_LO, field AMPLITUDE[6:0] (RO)
 *
 * Value from ASIC for tx_amplitude
 */

#define BP_PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE      (0)      //!< Bit position for PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE.
#define BM_PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE      (0x0000007f)  //!< Bit mask for PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE.

//! @brief Get value of PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE from a register value.
#define BG_PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE(r)   (((r) & BM_PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE) >> BP_PCIE_PHY_TX_ASIC_DRV_LO_AMPLITUDE)

/* --- Register HW_PCIE_PHY_TX_ASIC_DRV_LO, field PREEMPH[13:7] (RO)
 *
 * Value from ASIC for tx_preemph
 */

#define BP_PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH      (7)      //!< Bit position for PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH.
#define BM_PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH      (0x00003f80)  //!< Bit mask for PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH.

//! @brief Get value of PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH from a register value.
#define BG_PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH(r)   (((r) & BM_PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH) >> BP_PCIE_PHY_TX_ASIC_DRV_LO_PREEMPH)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ASIC_DRV_HI -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_asic_drv_hi
{
    reg16_t U;
    struct _hw_pcie_phy_tx_asic_drv_hi_bitfields
    {
        unsigned short TERM_OFFSET : 5; //!< [4:0] Value from ASIC for tx_term_offset
        unsigned short RESERVED0 : 11; //!< [15:5] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_ASIC_DRV_HI, field TERM_OFFSET[4:0] (RO)
 *
 * Value from ASIC for tx_term_offset
 */

#define BP_PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET      (0)      //!< Bit position for PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET.
#define BM_PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET      (0x0000001f)  //!< Bit mask for PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET.

//! @brief Get value of PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET from a register value.
#define BG_PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET(r)   (((r) & BM_PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET) >> BP_PCIE_PHY_TX_ASIC_DRV_HI_TERM_OFFSET)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ASIC_OUT -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_asic_out
{
    reg16_t U;
    struct _hw_pcie_phy_tx_asic_out_bitfields
    {
        unsigned short DETECT_RX_RES : 1; //!< [0] Value from PHY for tx_detect_rx_res
        unsigned short RESERVED0 : 1; //!< [1] Always returns 0
        unsigned short DETECT_RX_ACK : 1; //!< [2] Value from PHY for tx_detect_rx_ack
        unsigned short CM_STATE : 1; //!< [3] Value from PHY for tx_cm_state
        unsigned short STATE : 1; //!< [4] Value from PHY for tx_state
        unsigned short RESERVED1 : 11; //!< [15:5] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_ASIC_OUT, field DETECT_RX_RES[0] (RO)
 *
 * Value from PHY for tx_detect_rx_res
 */

#define BP_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES      (0)      //!< Bit position for PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES.
#define BM_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES.

//! @brief Get value of PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES from a register value.
#define BG_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES(r)   (((r) & BM_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES) >> BP_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_RES)

/* --- Register HW_PCIE_PHY_TX_ASIC_OUT, field DETECT_RX_ACK[2] (RO)
 *
 * Value from PHY for tx_detect_rx_ack
 */

#define BP_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK      (2)      //!< Bit position for PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK.
#define BM_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK.

//! @brief Get value of PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK from a register value.
#define BG_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK(r)   (((r) & BM_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK) >> BP_PCIE_PHY_TX_ASIC_OUT_DETECT_RX_ACK)

/* --- Register HW_PCIE_PHY_TX_ASIC_OUT, field CM_STATE[3] (RO)
 *
 * Value from PHY for tx_cm_state
 */

#define BP_PCIE_PHY_TX_ASIC_OUT_CM_STATE      (3)      //!< Bit position for PCIE_PHY_TX_ASIC_OUT_CM_STATE.
#define BM_PCIE_PHY_TX_ASIC_OUT_CM_STATE      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_ASIC_OUT_CM_STATE.

//! @brief Get value of PCIE_PHY_TX_ASIC_OUT_CM_STATE from a register value.
#define BG_PCIE_PHY_TX_ASIC_OUT_CM_STATE(r)   (((r) & BM_PCIE_PHY_TX_ASIC_OUT_CM_STATE) >> BP_PCIE_PHY_TX_ASIC_OUT_CM_STATE)

/* --- Register HW_PCIE_PHY_TX_ASIC_OUT, field STATE[4] (RO)
 *
 * Value from PHY for tx_state
 */

#define BP_PCIE_PHY_TX_ASIC_OUT_STATE      (4)      //!< Bit position for PCIE_PHY_TX_ASIC_OUT_STATE.
#define BM_PCIE_PHY_TX_ASIC_OUT_STATE      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_ASIC_OUT_STATE.

//! @brief Get value of PCIE_PHY_TX_ASIC_OUT_STATE from a register value.
#define BG_PCIE_PHY_TX_ASIC_OUT_STATE(r)   (((r) & BM_PCIE_PHY_TX_ASIC_OUT_STATE) >> BP_PCIE_PHY_TX_ASIC_OUT_STATE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ASIC_IN -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_asic_in
{
    reg16_t U;
    struct _hw_pcie_phy_rx_asic_in_bitfields
    {
        unsigned short RX_RATE : 2; //!< [1:0] Value from ASIC for rx_rate
        unsigned short INVERT : 1; //!< [2] Value from ASIC for rx_invert
        unsigned short RX_RESET : 1; //!< [3] Value from ASIC for rx_reset
        unsigned short PLL_EN : 1; //!< [4] Value from ASIC for rx_pll_en
        unsigned short DATA_EN : 1; //!< [5] Value from ASIC for rx_data_en
        unsigned short ALIGN_EN : 1; //!< [6] Value from ASIC for rx_align_en
        unsigned short CLK_SHIFT : 1; //!< [7] Value from ASIC for rx_bit_shift
        unsigned short TERM_EN : 1; //!< [8] Value from ASIC for rx_term_en
        unsigned short LOS_EN : 1; //!< [9] Value from ASIC for rx_los_en
        unsigned short LOS_FILTER : 2; //!< [11:10] Value from ASIC for rx_los_filter
        unsigned short RX_EQ : 3; //!< [14:12] Value from ASIC for rx_eq
        unsigned short RX_EQ_EN : 1; //!< [15] Value from ASIC for rx_eq_en
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

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field RX_RATE[1:0] (RO)
 *
 * Value from ASIC for rx_rate
 */

#define BP_PCIE_PHY_RX_ASIC_IN_RX_RATE      (0)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_RX_RATE.
#define BM_PCIE_PHY_RX_ASIC_IN_RX_RATE      (0x00000003)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_RX_RATE.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_RX_RATE from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_RX_RATE(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_RX_RATE) >> BP_PCIE_PHY_RX_ASIC_IN_RX_RATE)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field INVERT[2] (RO)
 *
 * Value from ASIC for rx_invert
 */

#define BP_PCIE_PHY_RX_ASIC_IN_INVERT      (2)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_INVERT.
#define BM_PCIE_PHY_RX_ASIC_IN_INVERT      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_INVERT.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_INVERT from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_INVERT(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_INVERT) >> BP_PCIE_PHY_RX_ASIC_IN_INVERT)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field RX_RESET[3] (RO)
 *
 * Value from ASIC for rx_reset
 */

#define BP_PCIE_PHY_RX_ASIC_IN_RX_RESET      (3)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_RX_RESET.
#define BM_PCIE_PHY_RX_ASIC_IN_RX_RESET      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_RX_RESET.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_RX_RESET from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_RX_RESET(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_RX_RESET) >> BP_PCIE_PHY_RX_ASIC_IN_RX_RESET)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field PLL_EN[4] (RO)
 *
 * Value from ASIC for rx_pll_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_PLL_EN      (4)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_PLL_EN.
#define BM_PCIE_PHY_RX_ASIC_IN_PLL_EN      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_PLL_EN.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_PLL_EN from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_PLL_EN(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_PLL_EN) >> BP_PCIE_PHY_RX_ASIC_IN_PLL_EN)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field DATA_EN[5] (RO)
 *
 * Value from ASIC for rx_data_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_DATA_EN      (5)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_DATA_EN.
#define BM_PCIE_PHY_RX_ASIC_IN_DATA_EN      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_DATA_EN.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_DATA_EN from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_DATA_EN(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_DATA_EN) >> BP_PCIE_PHY_RX_ASIC_IN_DATA_EN)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field ALIGN_EN[6] (RO)
 *
 * Value from ASIC for rx_align_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_ALIGN_EN      (6)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_ALIGN_EN.
#define BM_PCIE_PHY_RX_ASIC_IN_ALIGN_EN      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_ALIGN_EN.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_ALIGN_EN from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_ALIGN_EN(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_ALIGN_EN) >> BP_PCIE_PHY_RX_ASIC_IN_ALIGN_EN)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field CLK_SHIFT[7] (RO)
 *
 * Value from ASIC for rx_bit_shift
 */

#define BP_PCIE_PHY_RX_ASIC_IN_CLK_SHIFT      (7)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_CLK_SHIFT.
#define BM_PCIE_PHY_RX_ASIC_IN_CLK_SHIFT      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_CLK_SHIFT.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_CLK_SHIFT from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_CLK_SHIFT(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_CLK_SHIFT) >> BP_PCIE_PHY_RX_ASIC_IN_CLK_SHIFT)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field TERM_EN[8] (RO)
 *
 * Value from ASIC for rx_term_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_TERM_EN      (8)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_TERM_EN.
#define BM_PCIE_PHY_RX_ASIC_IN_TERM_EN      (0x00000100)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_TERM_EN.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_TERM_EN from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_TERM_EN(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_TERM_EN) >> BP_PCIE_PHY_RX_ASIC_IN_TERM_EN)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field LOS_EN[9] (RO)
 *
 * Value from ASIC for rx_los_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_LOS_EN      (9)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_LOS_EN.
#define BM_PCIE_PHY_RX_ASIC_IN_LOS_EN      (0x00000200)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_LOS_EN.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_LOS_EN from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_LOS_EN(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_LOS_EN) >> BP_PCIE_PHY_RX_ASIC_IN_LOS_EN)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field LOS_FILTER[11:10] (RO)
 *
 * Value from ASIC for rx_los_filter
 */

#define BP_PCIE_PHY_RX_ASIC_IN_LOS_FILTER      (10)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_LOS_FILTER.
#define BM_PCIE_PHY_RX_ASIC_IN_LOS_FILTER      (0x00000c00)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_LOS_FILTER.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_LOS_FILTER from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_LOS_FILTER(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_LOS_FILTER) >> BP_PCIE_PHY_RX_ASIC_IN_LOS_FILTER)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field RX_EQ[14:12] (RO)
 *
 * Value from ASIC for rx_eq
 */

#define BP_PCIE_PHY_RX_ASIC_IN_RX_EQ      (12)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_RX_EQ.
#define BM_PCIE_PHY_RX_ASIC_IN_RX_EQ      (0x00007000)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_RX_EQ.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_RX_EQ from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_RX_EQ(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_RX_EQ) >> BP_PCIE_PHY_RX_ASIC_IN_RX_EQ)

/* --- Register HW_PCIE_PHY_RX_ASIC_IN, field RX_EQ_EN[15] (RO)
 *
 * Value from ASIC for rx_eq_en
 */

#define BP_PCIE_PHY_RX_ASIC_IN_RX_EQ_EN      (15)      //!< Bit position for PCIE_PHY_RX_ASIC_IN_RX_EQ_EN.
#define BM_PCIE_PHY_RX_ASIC_IN_RX_EQ_EN      (0x00008000)  //!< Bit mask for PCIE_PHY_RX_ASIC_IN_RX_EQ_EN.

//! @brief Get value of PCIE_PHY_RX_ASIC_IN_RX_EQ_EN from a register value.
#define BG_PCIE_PHY_RX_ASIC_IN_RX_EQ_EN(r)   (((r) & BM_PCIE_PHY_RX_ASIC_IN_RX_EQ_EN) >> BP_PCIE_PHY_RX_ASIC_IN_RX_EQ_EN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ASIC_OUT -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_asic_out
{
    reg16_t U;
    struct _hw_pcie_phy_rx_asic_out_bitfields
    {
        unsigned short VALID : 1; //!< [0] Value from PHY for rx_valid
        unsigned short PLL_STATE : 1; //!< [1] Value from PHY for rx_pll_state
        unsigned short LOS : 1; //!< [2] Value from PHY for rx_los
        unsigned short RESERVED0 : 13; //!< [15:3] Reserved.
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

/* --- Register HW_PCIE_PHY_RX_ASIC_OUT, field VALID[0] (RO)
 *
 * Value from PHY for rx_valid
 */

#define BP_PCIE_PHY_RX_ASIC_OUT_VALID      (0)      //!< Bit position for PCIE_PHY_RX_ASIC_OUT_VALID.
#define BM_PCIE_PHY_RX_ASIC_OUT_VALID      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_ASIC_OUT_VALID.

//! @brief Get value of PCIE_PHY_RX_ASIC_OUT_VALID from a register value.
#define BG_PCIE_PHY_RX_ASIC_OUT_VALID(r)   (((r) & BM_PCIE_PHY_RX_ASIC_OUT_VALID) >> BP_PCIE_PHY_RX_ASIC_OUT_VALID)

/* --- Register HW_PCIE_PHY_RX_ASIC_OUT, field PLL_STATE[1] (RO)
 *
 * Value from PHY for rx_pll_state
 */

#define BP_PCIE_PHY_RX_ASIC_OUT_PLL_STATE      (1)      //!< Bit position for PCIE_PHY_RX_ASIC_OUT_PLL_STATE.
#define BM_PCIE_PHY_RX_ASIC_OUT_PLL_STATE      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_ASIC_OUT_PLL_STATE.

//! @brief Get value of PCIE_PHY_RX_ASIC_OUT_PLL_STATE from a register value.
#define BG_PCIE_PHY_RX_ASIC_OUT_PLL_STATE(r)   (((r) & BM_PCIE_PHY_RX_ASIC_OUT_PLL_STATE) >> BP_PCIE_PHY_RX_ASIC_OUT_PLL_STATE)

/* --- Register HW_PCIE_PHY_RX_ASIC_OUT, field LOS[2] (RO)
 *
 * Value from PHY for rx_los
 */

#define BP_PCIE_PHY_RX_ASIC_OUT_LOS      (2)      //!< Bit position for PCIE_PHY_RX_ASIC_OUT_LOS.
#define BM_PCIE_PHY_RX_ASIC_OUT_LOS      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_ASIC_OUT_LOS.

//! @brief Get value of PCIE_PHY_RX_ASIC_OUT_LOS from a register value.
#define BG_PCIE_PHY_RX_ASIC_OUT_LOS(r)   (((r) & BM_PCIE_PHY_RX_ASIC_OUT_LOS) >> BP_PCIE_PHY_RX_ASIC_OUT_LOS)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_DEBUG -  (RW)
 *
 * Reset value: 0x00001080
 *

 */
typedef union _hw_pcie_phy_tx_debug
{
    reg16_t U;
    struct _hw_pcie_phy_tx_debug_bitfields
    {
        unsigned short DTB_SEL : 3; //!< [2:0] Selects data to drive on DTB 0.
        unsigned short DETECT_RX_ALWAYS : 1; //!< [3] Always signal 1 for rx_detect ignoring analog
        unsigned short RXDET_MEAS_TIME : 8; //!< [11:4] Time to wait for rxdet measurement (* 8 refclk cycles)
        unsigned short CM_LFPS_EN : 1; //!< [12] Use LFPS to reach Common Mode. Let VCMHOLD circuit drive it is cleared.
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_DEBUG, field DTB_SEL[2:0] (RW)
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

#define BP_PCIE_PHY_TX_DEBUG_DTB_SEL      (0)      //!< Bit position for PCIE_PHY_TX_DEBUG_DTB_SEL.
#define BM_PCIE_PHY_TX_DEBUG_DTB_SEL      (0x00000007)  //!< Bit mask for PCIE_PHY_TX_DEBUG_DTB_SEL.

//! @brief Get value of PCIE_PHY_TX_DEBUG_DTB_SEL from a register value.
#define BG_PCIE_PHY_TX_DEBUG_DTB_SEL(r)   (((r) & BM_PCIE_PHY_TX_DEBUG_DTB_SEL) >> BP_PCIE_PHY_TX_DEBUG_DTB_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_DEBUG_DTB_SEL.
#define BF_PCIE_PHY_TX_DEBUG_DTB_SEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_DEBUG_DTB_SEL) & BM_PCIE_PHY_TX_DEBUG_DTB_SEL)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_DEBUG_DTB_SEL.
#define BF_PCIE_PHY_TX_DEBUG_DTB_SEL(v)   (((v) << BP_PCIE_PHY_TX_DEBUG_DTB_SEL) & BM_PCIE_PHY_TX_DEBUG_DTB_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL field to a new value.
#define BW_PCIE_PHY_TX_DEBUG_DTB_SEL(v)   (HW_PCIE_PHY_TX_DEBUG_WR((HW_PCIE_PHY_TX_DEBUG_RD() & ~BM_PCIE_PHY_TX_DEBUG_DTB_SEL) | BF_PCIE_PHY_TX_DEBUG_DTB_SEL(v)))
#endif


/* --- Register HW_PCIE_PHY_TX_DEBUG, field DETECT_RX_ALWAYS[3] (RW)
 *
 * Always signal 1 for rx_detect ignoring analog
 */

#define BP_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS      (3)      //!< Bit position for PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS.
#define BM_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS.

//! @brief Get value of PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS from a register value.
#define BG_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS(r)   (((r) & BM_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS) >> BP_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS.
#define BF_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS) & BM_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS.
#define BF_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS(v)   (((v) << BP_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS) & BM_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DETECT_RX_ALWAYS field to a new value.
#define BW_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS(v)   (HW_PCIE_PHY_TX_DEBUG_WR((HW_PCIE_PHY_TX_DEBUG_RD() & ~BM_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS) | BF_PCIE_PHY_TX_DEBUG_DETECT_RX_ALWAYS(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_DEBUG, field RXDET_MEAS_TIME[11:4] (RW)
 *
 * Time to wait for rxdet measurement (* 8 refclk cycles)
 */

#define BP_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME      (4)      //!< Bit position for PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME.
#define BM_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME      (0x00000ff0)  //!< Bit mask for PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME.

//! @brief Get value of PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME from a register value.
#define BG_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME(r)   (((r) & BM_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME) >> BP_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME.
#define BF_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME) & BM_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME.
#define BF_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME(v)   (((v) << BP_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME) & BM_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDET_MEAS_TIME field to a new value.
#define BW_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME(v)   (HW_PCIE_PHY_TX_DEBUG_WR((HW_PCIE_PHY_TX_DEBUG_RD() & ~BM_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME) | BF_PCIE_PHY_TX_DEBUG_RXDET_MEAS_TIME(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_DEBUG, field CM_LFPS_EN[12] (RW)
 *
 * Use LFPS to reach Common Mode. Let VCMHOLD circuit drive it is cleared.
 */

#define BP_PCIE_PHY_TX_DEBUG_CM_LFPS_EN      (12)      //!< Bit position for PCIE_PHY_TX_DEBUG_CM_LFPS_EN.
#define BM_PCIE_PHY_TX_DEBUG_CM_LFPS_EN      (0x00001000)  //!< Bit mask for PCIE_PHY_TX_DEBUG_CM_LFPS_EN.

//! @brief Get value of PCIE_PHY_TX_DEBUG_CM_LFPS_EN from a register value.
#define BG_PCIE_PHY_TX_DEBUG_CM_LFPS_EN(r)   (((r) & BM_PCIE_PHY_TX_DEBUG_CM_LFPS_EN) >> BP_PCIE_PHY_TX_DEBUG_CM_LFPS_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_DEBUG_CM_LFPS_EN.
#define BF_PCIE_PHY_TX_DEBUG_CM_LFPS_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_DEBUG_CM_LFPS_EN) & BM_PCIE_PHY_TX_DEBUG_CM_LFPS_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_DEBUG_CM_LFPS_EN.
#define BF_PCIE_PHY_TX_DEBUG_CM_LFPS_EN(v)   (((v) << BP_PCIE_PHY_TX_DEBUG_CM_LFPS_EN) & BM_PCIE_PHY_TX_DEBUG_CM_LFPS_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CM_LFPS_EN field to a new value.
#define BW_PCIE_PHY_TX_DEBUG_CM_LFPS_EN(v)   (HW_PCIE_PHY_TX_DEBUG_WR((HW_PCIE_PHY_TX_DEBUG_RD() & ~BM_PCIE_PHY_TX_DEBUG_CM_LFPS_EN) | BF_PCIE_PHY_TX_DEBUG_CM_LFPS_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0 -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_vmd_fsm_tx_vcm_0
{
    reg16_t U;
    struct _hw_pcie_phy_tx_vmd_fsm_tx_vcm_0_bitfields
    {
        unsigned short N_TRISTATE : 7; //!< [6:0] Value from VMD for number of tristate legs.
        unsigned short N_USE : 7; //!< [13:7] Value from VMD for legs to use
        unsigned short DONE : 1; //!< [14] Configuration is done
        unsigned short RESERVED0 : 1; //!< [15] Reserved.
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

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0, field N_TRISTATE[6:0] (RO)
 *
 * Value from VMD for number of tristate legs.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE      (0)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE      (0x0000007f)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_TRISTATE)

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0, field N_USE[13:7] (RO)
 *
 * Value from VMD for legs to use
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE      (7)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE      (0x00003f80)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_N_USE)

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_0, field DONE[14] (RO)
 *
 * Configuration is done
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE      (14)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE      (0x00004000)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_0_DONE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1 -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_vmd_fsm_tx_vcm_1
{
    reg16_t U;
    struct _hw_pcie_phy_tx_vmd_fsm_tx_vcm_1_bitfields
    {
        unsigned short N_TRAILER : 7; //!< [6:0] Value from VMD for number of trailer legs.
        unsigned short N_FIXED : 7; //!< [13:7] Value from VMD for number of fixed driver legs.
        unsigned short TRA_DONE : 1; //!< [14] N_TRAILER Multiplication has completed.
        unsigned short FIXED_DONE : 1; //!< [15] N_FIXED Multiplication has completed.
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

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1, field N_TRAILER[6:0] (RO)
 *
 * Value from VMD for number of trailer legs.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER      (0)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER      (0x0000007f)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_TRAILER)

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1, field N_FIXED[13:7] (RO)
 *
 * Value from VMD for number of fixed driver legs.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED      (7)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED      (0x00003f80)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_N_FIXED)

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1, field TRA_DONE[14] (RO)
 *
 * N_TRAILER Multiplication has completed.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE      (14)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE      (0x00004000)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_TRA_DONE)

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_1, field FIXED_DONE[15] (RO)
 *
 * N_FIXED Multiplication has completed.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE      (15)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE      (0x00008000)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_1_FIXED_DONE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_in
{
    reg16_t U;
    struct _hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_in_bitfields
    {
        unsigned short CONFIG_DATA : 1; //!< [0] Override value for the Voltage Mode Driver Configuration FSM's config data.
        unsigned short CONFIG_CLK : 1; //!< [1] Override value for the Voltage Mode Driver Configuration FSM's config clk.
        unsigned short CONFIG_LOAD : 1; //!< [2] Override value for the Voltage Mode Driver Configuration FSM's config load.
        unsigned short CONFIG_OVRD : 1; //!< [3] Override the Voltage Mode Driver Configuration FSM and access the shift chain directly.
        unsigned short RESERVED0 : 12; //!< [15:4] Reserved
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

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, field CONFIG_DATA[0] (RW)
 *
 * Override value for the Voltage Mode Driver Configuration FSM's config data.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA      (0)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA.
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA.
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA(v)   (((v) << BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIG_DATA field to a new value.
#define BW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA(v)   (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_WR((HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_RD() & ~BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA) | BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_DATA(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, field CONFIG_CLK[1] (RW)
 *
 * Override value for the Voltage Mode Driver Configuration FSM's config clk.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK      (1)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK      (0x00000002)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK.
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK.
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK(v)   (((v) << BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIG_CLK field to a new value.
#define BW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK(v)   (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_WR((HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_RD() & ~BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK) | BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_CLK(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, field CONFIG_LOAD[2] (RW)
 *
 * Override value for the Voltage Mode Driver Configuration FSM's config load.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD      (2)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD.
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD.
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD(v)   (((v) << BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIG_LOAD field to a new value.
#define BW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD(v)   (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_WR((HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_RD() & ~BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD) | BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_LOAD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN, field CONFIG_OVRD[3] (RW)
 *
 * Override the Voltage Mode Driver Configuration FSM and access the shift chain directly.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD      (3)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD.
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD.
#define BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD(v)   (((v) << BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIG_OVRD field to a new value.
#define BW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD(v)   (HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_WR((HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_RD() & ~BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD) | BF_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_IN_CONFIG_OVRD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_out
{
    reg16_t U;
    struct _hw_pcie_phy_tx_vmd_fsm_tx_vcm_debug_out_bitfields
    {
        unsigned short SHIFT_OUT : 1; //!< [0] Current value from TX_ANAs configuration shift register.
        unsigned short RESERVED0 : 15; //!< [15:1] Reserved
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

/* --- Register HW_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT, field SHIFT_OUT[0] (RO)
 *
 * Current value from TX_ANAs configuration shift register.
 */

#define BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT      (0)      //!< Bit position for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT.
#define BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT.

//! @brief Get value of PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT from a register value.
#define BG_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT(r)   (((r) & BM_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT) >> BP_PCIE_PHY_TX_VMD_FSM_TX_VCM_DEBUG_OUT_SHIFT_OUT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_LBERT_CTL -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_lbert_ctl
{
    reg16_t U;
    struct _hw_pcie_phy_tx_lbert_ctl_bitfields
    {
        unsigned short MODE : 3; //!< [2:0] Pattern to generate When changing modes, you must first change to disabled.
        unsigned short TRIGGER_ERR : 1; //!< [3] Insert a single error into a lsb Any write of a 1 to this bit will insert an error
        unsigned short PAT0 : 10; //!< [13:4] Pattern for modes 3-5
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved
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

/* --- Register HW_PCIE_PHY_TX_LBERT_CTL, field MODE[2:0] (RW)
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

#define BP_PCIE_PHY_TX_LBERT_CTL_MODE      (0)      //!< Bit position for PCIE_PHY_TX_LBERT_CTL_MODE.
#define BM_PCIE_PHY_TX_LBERT_CTL_MODE      (0x00000007)  //!< Bit mask for PCIE_PHY_TX_LBERT_CTL_MODE.

//! @brief Get value of PCIE_PHY_TX_LBERT_CTL_MODE from a register value.
#define BG_PCIE_PHY_TX_LBERT_CTL_MODE(r)   (((r) & BM_PCIE_PHY_TX_LBERT_CTL_MODE) >> BP_PCIE_PHY_TX_LBERT_CTL_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_LBERT_CTL_MODE.
#define BF_PCIE_PHY_TX_LBERT_CTL_MODE(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_LBERT_CTL_MODE) & BM_PCIE_PHY_TX_LBERT_CTL_MODE)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_LBERT_CTL_MODE.
#define BF_PCIE_PHY_TX_LBERT_CTL_MODE(v)   (((v) << BP_PCIE_PHY_TX_LBERT_CTL_MODE) & BM_PCIE_PHY_TX_LBERT_CTL_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_PCIE_PHY_TX_LBERT_CTL_MODE(v)   (HW_PCIE_PHY_TX_LBERT_CTL_WR((HW_PCIE_PHY_TX_LBERT_CTL_RD() & ~BM_PCIE_PHY_TX_LBERT_CTL_MODE) | BF_PCIE_PHY_TX_LBERT_CTL_MODE(v)))
#endif


/* --- Register HW_PCIE_PHY_TX_LBERT_CTL, field TRIGGER_ERR[3] (RW)
 *
 * Insert a single error into a lsb Any write of a 1 to this bit will insert an error
 */

#define BP_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR      (3)      //!< Bit position for PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR.
#define BM_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR.

//! @brief Get value of PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR from a register value.
#define BG_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR(r)   (((r) & BM_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR) >> BP_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR.
#define BF_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR) & BM_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR.
#define BF_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR(v)   (((v) << BP_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR) & BM_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TRIGGER_ERR field to a new value.
#define BW_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR(v)   (HW_PCIE_PHY_TX_LBERT_CTL_WR((HW_PCIE_PHY_TX_LBERT_CTL_RD() & ~BM_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR) | BF_PCIE_PHY_TX_LBERT_CTL_TRIGGER_ERR(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_LBERT_CTL, field PAT0[13:4] (RW)
 *
 * Pattern for modes 3-5
 */

#define BP_PCIE_PHY_TX_LBERT_CTL_PAT0      (4)      //!< Bit position for PCIE_PHY_TX_LBERT_CTL_PAT0.
#define BM_PCIE_PHY_TX_LBERT_CTL_PAT0      (0x00003ff0)  //!< Bit mask for PCIE_PHY_TX_LBERT_CTL_PAT0.

//! @brief Get value of PCIE_PHY_TX_LBERT_CTL_PAT0 from a register value.
#define BG_PCIE_PHY_TX_LBERT_CTL_PAT0(r)   (((r) & BM_PCIE_PHY_TX_LBERT_CTL_PAT0) >> BP_PCIE_PHY_TX_LBERT_CTL_PAT0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_LBERT_CTL_PAT0.
#define BF_PCIE_PHY_TX_LBERT_CTL_PAT0(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_LBERT_CTL_PAT0) & BM_PCIE_PHY_TX_LBERT_CTL_PAT0)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_LBERT_CTL_PAT0.
#define BF_PCIE_PHY_TX_LBERT_CTL_PAT0(v)   (((v) << BP_PCIE_PHY_TX_LBERT_CTL_PAT0) & BM_PCIE_PHY_TX_LBERT_CTL_PAT0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PAT0 field to a new value.
#define BW_PCIE_PHY_TX_LBERT_CTL_PAT0(v)   (HW_PCIE_PHY_TX_LBERT_CTL_WR((HW_PCIE_PHY_TX_LBERT_CTL_RD() & ~BM_PCIE_PHY_TX_LBERT_CTL_PAT0) | BF_PCIE_PHY_TX_LBERT_CTL_PAT0(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_LBERT_CTL -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_lbert_ctl
{
    reg16_t U;
    struct _hw_pcie_phy_rx_lbert_ctl_bitfields
    {
        unsigned short MODE : 3; //!< [2:0] Pattern to match When changing modes, you must first change to disabled.
        unsigned short SYNC : 1; //!< [3] Synchronize pattern matcher LFSR with incoming data A write of a one to this bit will reset the error counter and start a synchronization of the PM. There is no need to write this back to zero to run normally.
        unsigned short RESERVED0 : 12; //!< [15:4] Reserved
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

/* --- Register HW_PCIE_PHY_RX_LBERT_CTL, field MODE[2:0] (RW)
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

#define BP_PCIE_PHY_RX_LBERT_CTL_MODE      (0)      //!< Bit position for PCIE_PHY_RX_LBERT_CTL_MODE.
#define BM_PCIE_PHY_RX_LBERT_CTL_MODE      (0x00000007)  //!< Bit mask for PCIE_PHY_RX_LBERT_CTL_MODE.

//! @brief Get value of PCIE_PHY_RX_LBERT_CTL_MODE from a register value.
#define BG_PCIE_PHY_RX_LBERT_CTL_MODE(r)   (((r) & BM_PCIE_PHY_RX_LBERT_CTL_MODE) >> BP_PCIE_PHY_RX_LBERT_CTL_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_LBERT_CTL_MODE.
#define BF_PCIE_PHY_RX_LBERT_CTL_MODE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_LBERT_CTL_MODE) & BM_PCIE_PHY_RX_LBERT_CTL_MODE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_LBERT_CTL_MODE.
#define BF_PCIE_PHY_RX_LBERT_CTL_MODE(v)   (((v) << BP_PCIE_PHY_RX_LBERT_CTL_MODE) & BM_PCIE_PHY_RX_LBERT_CTL_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_PCIE_PHY_RX_LBERT_CTL_MODE(v)   (HW_PCIE_PHY_RX_LBERT_CTL_WR((HW_PCIE_PHY_RX_LBERT_CTL_RD() & ~BM_PCIE_PHY_RX_LBERT_CTL_MODE) | BF_PCIE_PHY_RX_LBERT_CTL_MODE(v)))
#endif


/* --- Register HW_PCIE_PHY_RX_LBERT_CTL, field SYNC[3] (RW)
 *
 * Synchronize pattern matcher LFSR with incoming data A write of a one to this bit will reset the
 * error counter and start a synchronization of the PM. There is no need to write this back to zero
 * to run normally.
 */

#define BP_PCIE_PHY_RX_LBERT_CTL_SYNC      (3)      //!< Bit position for PCIE_PHY_RX_LBERT_CTL_SYNC.
#define BM_PCIE_PHY_RX_LBERT_CTL_SYNC      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_LBERT_CTL_SYNC.

//! @brief Get value of PCIE_PHY_RX_LBERT_CTL_SYNC from a register value.
#define BG_PCIE_PHY_RX_LBERT_CTL_SYNC(r)   (((r) & BM_PCIE_PHY_RX_LBERT_CTL_SYNC) >> BP_PCIE_PHY_RX_LBERT_CTL_SYNC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_LBERT_CTL_SYNC.
#define BF_PCIE_PHY_RX_LBERT_CTL_SYNC(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_LBERT_CTL_SYNC) & BM_PCIE_PHY_RX_LBERT_CTL_SYNC)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_LBERT_CTL_SYNC.
#define BF_PCIE_PHY_RX_LBERT_CTL_SYNC(v)   (((v) << BP_PCIE_PHY_RX_LBERT_CTL_SYNC) & BM_PCIE_PHY_RX_LBERT_CTL_SYNC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYNC field to a new value.
#define BW_PCIE_PHY_RX_LBERT_CTL_SYNC(v)   (HW_PCIE_PHY_RX_LBERT_CTL_WR((HW_PCIE_PHY_RX_LBERT_CTL_RD() & ~BM_PCIE_PHY_RX_LBERT_CTL_SYNC) | BF_PCIE_PHY_RX_LBERT_CTL_SYNC(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_LBERT_ERR -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_lbert_err
{
    reg16_t U;
    struct _hw_pcie_phy_rx_lbert_err_bitfields
    {
        unsigned short COUNT : 15; //!< [14:0] A read of this register, or a sync of the PM resets the error count. Current error count If OV14 field is active, then multiply count by 128
        unsigned short OV14 : 1; //!< [15] If active, multiply COUNT by 128. If OV14=1 and COUNT=2^15-1, signals overflow of counter
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

/* --- Register HW_PCIE_PHY_RX_LBERT_ERR, field COUNT[14:0] (RW)
 *
 * A read of this register, or a sync of the PM resets the error count. Current error count If OV14
 * field is active, then multiply count by 128
 */

#define BP_PCIE_PHY_RX_LBERT_ERR_COUNT      (0)      //!< Bit position for PCIE_PHY_RX_LBERT_ERR_COUNT.
#define BM_PCIE_PHY_RX_LBERT_ERR_COUNT      (0x00007fff)  //!< Bit mask for PCIE_PHY_RX_LBERT_ERR_COUNT.

//! @brief Get value of PCIE_PHY_RX_LBERT_ERR_COUNT from a register value.
#define BG_PCIE_PHY_RX_LBERT_ERR_COUNT(r)   (((r) & BM_PCIE_PHY_RX_LBERT_ERR_COUNT) >> BP_PCIE_PHY_RX_LBERT_ERR_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_LBERT_ERR_COUNT.
#define BF_PCIE_PHY_RX_LBERT_ERR_COUNT(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_LBERT_ERR_COUNT) & BM_PCIE_PHY_RX_LBERT_ERR_COUNT)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_LBERT_ERR_COUNT.
#define BF_PCIE_PHY_RX_LBERT_ERR_COUNT(v)   (((v) << BP_PCIE_PHY_RX_LBERT_ERR_COUNT) & BM_PCIE_PHY_RX_LBERT_ERR_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNT field to a new value.
#define BW_PCIE_PHY_RX_LBERT_ERR_COUNT(v)   (HW_PCIE_PHY_RX_LBERT_ERR_WR((HW_PCIE_PHY_RX_LBERT_ERR_RD() & ~BM_PCIE_PHY_RX_LBERT_ERR_COUNT) | BF_PCIE_PHY_RX_LBERT_ERR_COUNT(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_LBERT_ERR, field OV14[15] (RW)
 *
 * If active, multiply COUNT by 128. If OV14=1 and COUNT=2^15-1, signals overflow of counter
 */

#define BP_PCIE_PHY_RX_LBERT_ERR_OV14      (15)      //!< Bit position for PCIE_PHY_RX_LBERT_ERR_OV14.
#define BM_PCIE_PHY_RX_LBERT_ERR_OV14      (0x00008000)  //!< Bit mask for PCIE_PHY_RX_LBERT_ERR_OV14.

//! @brief Get value of PCIE_PHY_RX_LBERT_ERR_OV14 from a register value.
#define BG_PCIE_PHY_RX_LBERT_ERR_OV14(r)   (((r) & BM_PCIE_PHY_RX_LBERT_ERR_OV14) >> BP_PCIE_PHY_RX_LBERT_ERR_OV14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_LBERT_ERR_OV14.
#define BF_PCIE_PHY_RX_LBERT_ERR_OV14(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_LBERT_ERR_OV14) & BM_PCIE_PHY_RX_LBERT_ERR_OV14)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_LBERT_ERR_OV14.
#define BF_PCIE_PHY_RX_LBERT_ERR_OV14(v)   (((v) << BP_PCIE_PHY_RX_LBERT_ERR_OV14) & BM_PCIE_PHY_RX_LBERT_ERR_OV14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OV14 field to a new value.
#define BW_PCIE_PHY_RX_LBERT_ERR_OV14(v)   (HW_PCIE_PHY_RX_LBERT_ERR_WR((HW_PCIE_PHY_RX_LBERT_ERR_RD() & ~BM_PCIE_PHY_RX_LBERT_ERR_OV14) | BF_PCIE_PHY_RX_LBERT_ERR_OV14(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_SCOPE_CTL -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_scope_ctl
{
    reg16_t U;
    struct _hw_pcie_phy_rx_scope_ctl_bitfields
    {
        unsigned short MODE : 3; //!< [2:0] Sampling mode of counters. WORD is 20 bits.
        unsigned short RESERVED0 : 13; //!< [15:3] Reserved
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

/* --- Register HW_PCIE_PHY_RX_SCOPE_CTL, field MODE[2:0] (RW)
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

#define BP_PCIE_PHY_RX_SCOPE_CTL_MODE      (0)      //!< Bit position for PCIE_PHY_RX_SCOPE_CTL_MODE.
#define BM_PCIE_PHY_RX_SCOPE_CTL_MODE      (0x00000007)  //!< Bit mask for PCIE_PHY_RX_SCOPE_CTL_MODE.

//! @brief Get value of PCIE_PHY_RX_SCOPE_CTL_MODE from a register value.
#define BG_PCIE_PHY_RX_SCOPE_CTL_MODE(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_CTL_MODE) >> BP_PCIE_PHY_RX_SCOPE_CTL_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_CTL_MODE.
#define BF_PCIE_PHY_RX_SCOPE_CTL_MODE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_CTL_MODE) & BM_PCIE_PHY_RX_SCOPE_CTL_MODE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_CTL_MODE.
#define BF_PCIE_PHY_RX_SCOPE_CTL_MODE(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_CTL_MODE) & BM_PCIE_PHY_RX_SCOPE_CTL_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_CTL_MODE(v)   (HW_PCIE_PHY_RX_SCOPE_CTL_WR((HW_PCIE_PHY_RX_SCOPE_CTL_RD() & ~BM_PCIE_PHY_RX_SCOPE_CTL_MODE) | BF_PCIE_PHY_RX_SCOPE_CTL_MODE(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_SCOPE_PHASE -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_scope_phase
{
    reg16_t U;
    struct _hw_pcie_phy_rx_scope_phase_bitfields
    {
        unsigned short SAMPLE_PHASE : 6; //!< [5:0] Sampling Phase
        unsigned short UPDATE : 1; //!< [6] Update Sampling phase. Write a 1.
        unsigned short SCOPE_SEL : 1; //!< [7] Select sampling mode.
        unsigned short SCOPE_DELAY : 2; //!< [9:8] How many clocks to delay the analog scope_data.
        unsigned short BASE : 5; //!< [14:10] which bit to sample when MODE = 1 or 4
        unsigned short RESERVED0 : 1; //!< [15] Reserved
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

/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field SAMPLE_PHASE[5:0] (RW)
 *
 * Sampling Phase
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE      (0)      //!< Bit position for PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE.
#define BM_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE      (0x0000003f)  //!< Bit mask for PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE.

//! @brief Get value of PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE from a register value.
#define BG_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE) >> BP_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE) & BM_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE) & BM_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SAMPLE_PHASE field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE(v)   (HW_PCIE_PHY_RX_SCOPE_PHASE_WR((HW_PCIE_PHY_RX_SCOPE_PHASE_RD() & ~BM_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE) | BF_PCIE_PHY_RX_SCOPE_PHASE_SAMPLE_PHASE(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field UPDATE[6] (RW)
 *
 * Update Sampling phase. Write a 1.
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_UPDATE      (6)      //!< Bit position for PCIE_PHY_RX_SCOPE_PHASE_UPDATE.
#define BM_PCIE_PHY_RX_SCOPE_PHASE_UPDATE      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_SCOPE_PHASE_UPDATE.

//! @brief Get value of PCIE_PHY_RX_SCOPE_PHASE_UPDATE from a register value.
#define BG_PCIE_PHY_RX_SCOPE_PHASE_UPDATE(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_PHASE_UPDATE) >> BP_PCIE_PHY_RX_SCOPE_PHASE_UPDATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_UPDATE.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_UPDATE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_PHASE_UPDATE) & BM_PCIE_PHY_RX_SCOPE_PHASE_UPDATE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_UPDATE.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_UPDATE(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_PHASE_UPDATE) & BM_PCIE_PHY_RX_SCOPE_PHASE_UPDATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPDATE field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_UPDATE(v)   (HW_PCIE_PHY_RX_SCOPE_PHASE_WR((HW_PCIE_PHY_RX_SCOPE_PHASE_RD() & ~BM_PCIE_PHY_RX_SCOPE_PHASE_UPDATE) | BF_PCIE_PHY_RX_SCOPE_PHASE_UPDATE(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field SCOPE_SEL[7] (RW)
 *
 * Select sampling mode.
 *
 * Values:
 * 0 - Before AFE sampling
 * 1 - After AFE sampling
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL      (7)      //!< Bit position for PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL.
#define BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL.

//! @brief Get value of PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL from a register value.
#define BG_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL) >> BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_SEL field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL(v)   (HW_PCIE_PHY_RX_SCOPE_PHASE_WR((HW_PCIE_PHY_RX_SCOPE_PHASE_RD() & ~BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL) | BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_SEL(v)))
#endif


/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field SCOPE_DELAY[9:8] (RW)
 *
 * How many clocks to delay the analog scope_data.
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY      (8)      //!< Bit position for PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY.
#define BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY      (0x00000300)  //!< Bit mask for PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY.

//! @brief Get value of PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY from a register value.
#define BG_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY) >> BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY) & BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_DELAY field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY(v)   (HW_PCIE_PHY_RX_SCOPE_PHASE_WR((HW_PCIE_PHY_RX_SCOPE_PHASE_RD() & ~BM_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY) | BF_PCIE_PHY_RX_SCOPE_PHASE_SCOPE_DELAY(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE_PHASE, field BASE[14:10] (RW)
 *
 * which bit to sample when MODE = 1 or 4
 */

#define BP_PCIE_PHY_RX_SCOPE_PHASE_BASE      (10)      //!< Bit position for PCIE_PHY_RX_SCOPE_PHASE_BASE.
#define BM_PCIE_PHY_RX_SCOPE_PHASE_BASE      (0x00007c00)  //!< Bit mask for PCIE_PHY_RX_SCOPE_PHASE_BASE.

//! @brief Get value of PCIE_PHY_RX_SCOPE_PHASE_BASE from a register value.
#define BG_PCIE_PHY_RX_SCOPE_PHASE_BASE(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_PHASE_BASE) >> BP_PCIE_PHY_RX_SCOPE_PHASE_BASE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_BASE.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_BASE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_PHASE_BASE) & BM_PCIE_PHY_RX_SCOPE_PHASE_BASE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_PHASE_BASE.
#define BF_PCIE_PHY_RX_SCOPE_PHASE_BASE(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_PHASE_BASE) & BM_PCIE_PHY_RX_SCOPE_PHASE_BASE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BASE field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_PHASE_BASE(v)   (HW_PCIE_PHY_RX_SCOPE_PHASE_WR((HW_PCIE_PHY_RX_SCOPE_PHASE_RD() & ~BM_PCIE_PHY_RX_SCOPE_PHASE_BASE) | BF_PCIE_PHY_RX_SCOPE_PHASE_BASE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_DPLL_FREQ -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_dpll_freq
{
    reg16_t U;
    struct _hw_pcie_phy_rx_dpll_freq_bitfields
    {
        unsigned short DTHR : 1; //!< [0] Bits below the useful resolution
        unsigned short VAL : 12; //!< [12:1] Freq is 1.526*VAL ppm from the reference When mpll_slow is set, the ppm is half the eqn above
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved
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

/* --- Register HW_PCIE_PHY_RX_DPLL_FREQ, field DTHR[0] (RW)
 *
 * Bits below the useful resolution
 */

#define BP_PCIE_PHY_RX_DPLL_FREQ_DTHR      (0)      //!< Bit position for PCIE_PHY_RX_DPLL_FREQ_DTHR.
#define BM_PCIE_PHY_RX_DPLL_FREQ_DTHR      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_DPLL_FREQ_DTHR.

//! @brief Get value of PCIE_PHY_RX_DPLL_FREQ_DTHR from a register value.
#define BG_PCIE_PHY_RX_DPLL_FREQ_DTHR(r)   (((r) & BM_PCIE_PHY_RX_DPLL_FREQ_DTHR) >> BP_PCIE_PHY_RX_DPLL_FREQ_DTHR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_DPLL_FREQ_DTHR.
#define BF_PCIE_PHY_RX_DPLL_FREQ_DTHR(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_DPLL_FREQ_DTHR) & BM_PCIE_PHY_RX_DPLL_FREQ_DTHR)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_DPLL_FREQ_DTHR.
#define BF_PCIE_PHY_RX_DPLL_FREQ_DTHR(v)   (((v) << BP_PCIE_PHY_RX_DPLL_FREQ_DTHR) & BM_PCIE_PHY_RX_DPLL_FREQ_DTHR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTHR field to a new value.
#define BW_PCIE_PHY_RX_DPLL_FREQ_DTHR(v)   (HW_PCIE_PHY_RX_DPLL_FREQ_WR((HW_PCIE_PHY_RX_DPLL_FREQ_RD() & ~BM_PCIE_PHY_RX_DPLL_FREQ_DTHR) | BF_PCIE_PHY_RX_DPLL_FREQ_DTHR(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_DPLL_FREQ, field VAL[12:1] (RW)
 *
 * Freq is 1.526*VAL ppm from the reference When mpll_slow is set, the ppm is half the eqn above
 */

#define BP_PCIE_PHY_RX_DPLL_FREQ_VAL      (1)      //!< Bit position for PCIE_PHY_RX_DPLL_FREQ_VAL.
#define BM_PCIE_PHY_RX_DPLL_FREQ_VAL      (0x00001ffe)  //!< Bit mask for PCIE_PHY_RX_DPLL_FREQ_VAL.

//! @brief Get value of PCIE_PHY_RX_DPLL_FREQ_VAL from a register value.
#define BG_PCIE_PHY_RX_DPLL_FREQ_VAL(r)   (((r) & BM_PCIE_PHY_RX_DPLL_FREQ_VAL) >> BP_PCIE_PHY_RX_DPLL_FREQ_VAL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_DPLL_FREQ_VAL.
#define BF_PCIE_PHY_RX_DPLL_FREQ_VAL(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_DPLL_FREQ_VAL) & BM_PCIE_PHY_RX_DPLL_FREQ_VAL)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_DPLL_FREQ_VAL.
#define BF_PCIE_PHY_RX_DPLL_FREQ_VAL(v)   (((v) << BP_PCIE_PHY_RX_DPLL_FREQ_VAL) & BM_PCIE_PHY_RX_DPLL_FREQ_VAL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VAL field to a new value.
#define BW_PCIE_PHY_RX_DPLL_FREQ_VAL(v)   (HW_PCIE_PHY_RX_DPLL_FREQ_WR((HW_PCIE_PHY_RX_DPLL_FREQ_RD() & ~BM_PCIE_PHY_RX_DPLL_FREQ_VAL) | BF_PCIE_PHY_RX_DPLL_FREQ_VAL(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_CTL -  (RW)
 *
 * Reset value: 0x0000000f
 *

 */
typedef union _hw_pcie_phy_rx_cdr_ctl
{
    reg16_t U;
    struct _hw_pcie_phy_rx_cdr_ctl_bitfields
    {
        unsigned short PHDET_EN : 2; //!< [1:0] Enables phase detecter. top bit is odd slicers, bottom is even
        unsigned short PHDET_EDGE : 2; //!< [3:2] Edges to use for phase detection.
        unsigned short PHDET_POL : 1; //!< [4] Reverse polarity of phase error
        unsigned short OVRD_DPLL_GAIN : 1; //!< [5] Override PHUG and FRUG values
        unsigned short PHUG_VALUE : 2; //!< [7:6] override value for PHUG
        unsigned short FRUG_VALUE : 2; //!< [9:8] override value for FRUG
        unsigned short FAST_START : 1; //!< [10] decrease startup steps by 50%
        unsigned short ALWAYS_REALIGN : 1; //!< [11] realign on any misaligned comma
        unsigned short DTB_SEL : 4; //!< [15:12] Select to drive various signals onto the DTB.
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

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field PHDET_EN[1:0] (RW)
 *
 * Enables phase detecter. top bit is odd slicers, bottom is even
 */

#define BP_PCIE_PHY_RX_CDR_CTL_PHDET_EN      (0)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_PHDET_EN.
#define BM_PCIE_PHY_RX_CDR_CTL_PHDET_EN      (0x00000003)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_PHDET_EN.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_PHDET_EN from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_PHDET_EN(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EN) >> BP_PCIE_PHY_RX_CDR_CTL_PHDET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_PHDET_EN.
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_PHDET_EN) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_PHDET_EN.
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_EN(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_PHDET_EN) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_EN field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_PHDET_EN(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_PHDET_EN) | BF_PCIE_PHY_RX_CDR_CTL_PHDET_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field PHDET_EDGE[3:2] (RW)
 *
 * Edges to use for phase detection.
 *
 * Values:
 * 00 - Ignore all edges
 * 01 - Use falling edges only
 * 10 - Use rising edges only
 * 11 - Use both edges
 */

#define BP_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE      (2)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_PHDET_EDGE.
#define BM_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE      (0x0000000c)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_PHDET_EDGE.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_PHDET_EDGE from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE) >> BP_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_PHDET_EDGE.
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_PHDET_EDGE.
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_EDGE field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE) | BF_PCIE_PHY_RX_CDR_CTL_PHDET_EDGE(v)))
#endif


/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field PHDET_POL[4] (RW)
 *
 * Reverse polarity of phase error
 */

#define BP_PCIE_PHY_RX_CDR_CTL_PHDET_POL      (4)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_PHDET_POL.
#define BM_PCIE_PHY_RX_CDR_CTL_PHDET_POL      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_PHDET_POL.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_PHDET_POL from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_PHDET_POL(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_POL) >> BP_PCIE_PHY_RX_CDR_CTL_PHDET_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_PHDET_POL.
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_POL(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_PHDET_POL) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_POL)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_PHDET_POL.
#define BF_PCIE_PHY_RX_CDR_CTL_PHDET_POL(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_PHDET_POL) & BM_PCIE_PHY_RX_CDR_CTL_PHDET_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PHDET_POL field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_PHDET_POL(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_PHDET_POL) | BF_PCIE_PHY_RX_CDR_CTL_PHDET_POL(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field OVRD_DPLL_GAIN[5] (RW)
 *
 * Override PHUG and FRUG values
 */

#define BP_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN      (5)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN.
#define BM_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN) >> BP_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN.
#define BF_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN) & BM_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN.
#define BF_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN) & BM_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_DPLL_GAIN field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN) | BF_PCIE_PHY_RX_CDR_CTL_OVRD_DPLL_GAIN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field PHUG_VALUE[7:6] (RW)
 *
 * override value for PHUG
 */

#define BP_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE      (6)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_PHUG_VALUE.
#define BM_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE      (0x000000c0)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_PHUG_VALUE.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_PHUG_VALUE from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE) >> BP_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_PHUG_VALUE.
#define BF_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE) & BM_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_PHUG_VALUE.
#define BF_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE) & BM_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PHUG_VALUE field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE) | BF_PCIE_PHY_RX_CDR_CTL_PHUG_VALUE(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field FRUG_VALUE[9:8] (RW)
 *
 * override value for FRUG
 */

#define BP_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE      (8)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_FRUG_VALUE.
#define BM_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE      (0x00000300)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_FRUG_VALUE.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_FRUG_VALUE from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE) >> BP_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_FRUG_VALUE.
#define BF_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE) & BM_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_FRUG_VALUE.
#define BF_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE) & BM_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRUG_VALUE field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE) | BF_PCIE_PHY_RX_CDR_CTL_FRUG_VALUE(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field FAST_START[10] (RW)
 *
 * decrease startup steps by 50%
 */

#define BP_PCIE_PHY_RX_CDR_CTL_FAST_START      (10)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_FAST_START.
#define BM_PCIE_PHY_RX_CDR_CTL_FAST_START      (0x00000400)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_FAST_START.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_FAST_START from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_FAST_START(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_FAST_START) >> BP_PCIE_PHY_RX_CDR_CTL_FAST_START)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_FAST_START.
#define BF_PCIE_PHY_RX_CDR_CTL_FAST_START(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_FAST_START) & BM_PCIE_PHY_RX_CDR_CTL_FAST_START)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_FAST_START.
#define BF_PCIE_PHY_RX_CDR_CTL_FAST_START(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_FAST_START) & BM_PCIE_PHY_RX_CDR_CTL_FAST_START)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FAST_START field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_FAST_START(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_FAST_START) | BF_PCIE_PHY_RX_CDR_CTL_FAST_START(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field ALWAYS_REALIGN[11] (RW)
 *
 * realign on any misaligned comma
 */

#define BP_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN      (11)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN.
#define BM_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN      (0x00000800)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN) >> BP_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN.
#define BF_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN) & BM_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN.
#define BF_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN) & BM_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALWAYS_REALIGN field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN) | BF_PCIE_PHY_RX_CDR_CTL_ALWAYS_REALIGN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_CTL, field DTB_SEL[15:12] (RW)
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

#define BP_PCIE_PHY_RX_CDR_CTL_DTB_SEL      (12)      //!< Bit position for PCIE_PHY_RX_CDR_CTL_DTB_SEL.
#define BM_PCIE_PHY_RX_CDR_CTL_DTB_SEL      (0x0000f000)  //!< Bit mask for PCIE_PHY_RX_CDR_CTL_DTB_SEL.

//! @brief Get value of PCIE_PHY_RX_CDR_CTL_DTB_SEL from a register value.
#define BG_PCIE_PHY_RX_CDR_CTL_DTB_SEL(r)   (((r) & BM_PCIE_PHY_RX_CDR_CTL_DTB_SEL) >> BP_PCIE_PHY_RX_CDR_CTL_DTB_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_DTB_SEL.
#define BF_PCIE_PHY_RX_CDR_CTL_DTB_SEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_CTL_DTB_SEL) & BM_PCIE_PHY_RX_CDR_CTL_DTB_SEL)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_CTL_DTB_SEL.
#define BF_PCIE_PHY_RX_CDR_CTL_DTB_SEL(v)   (((v) << BP_PCIE_PHY_RX_CDR_CTL_DTB_SEL) & BM_PCIE_PHY_RX_CDR_CTL_DTB_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL field to a new value.
#define BW_PCIE_PHY_RX_CDR_CTL_DTB_SEL(v)   (HW_PCIE_PHY_RX_CDR_CTL_WR((HW_PCIE_PHY_RX_CDR_CTL_RD() & ~BM_PCIE_PHY_RX_CDR_CTL_DTB_SEL) | BF_PCIE_PHY_RX_CDR_CTL_DTB_SEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_cdr_cdr_fsm_debug
{
    reg16_t U;
    struct _hw_pcie_phy_rx_cdr_cdr_fsm_debug_bitfields
    {
        unsigned short CDR_EN : 1; //!< [0] CDR has been enabled.
        unsigned short CDR_TIMEOUT : 1; //!< [1] CDR has not locked to datastream and has timed-out.
        unsigned short CDR_RX_VALID : 1; //!< [2] CDR has locked to incoming data stream.
        unsigned short ALIGNED : 1; //!< [3] Datapath is bit-aligned.
        unsigned short CDR_EN_EQ : 1; //!< [4] Equalization loop is enabling the CDR.
        unsigned short CDR_EN_ADAP : 1; //!< [5] Adapatation loop is enabling the CDR.
        unsigned short ADAP_RX_VALID : 1; //!< [6] Adaptation has completed and locked
        unsigned short RX_ANA_EQ : 3; //!< [9:7] Equalization setting to Analog.
        unsigned short RX_EQ_CTR : 3; //!< [12:10] Initial centre point from equalization FSM.
        unsigned short ADAP_RX_EQ : 3; //!< [15:13] Equalization setting from adaptation FSM.
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

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_EN[0] (RO)
 *
 * CDR has been enabled.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN      (0)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_TIMEOUT[1] (RO)
 *
 * CDR has not locked to datastream and has timed-out.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT      (1)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_TIMEOUT)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_RX_VALID[2] (RO)
 *
 * CDR has locked to incoming data stream.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID      (2)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_RX_VALID)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field ALIGNED[3] (RO)
 *
 * Datapath is bit-aligned.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED      (3)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ALIGNED)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_EN_EQ[4] (RO)
 *
 * Equalization loop is enabling the CDR.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ      (4)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_EQ)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field CDR_EN_ADAP[5] (RO)
 *
 * Adapatation loop is enabling the CDR.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP      (5)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_CDR_EN_ADAP)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field ADAP_RX_VALID[6] (RO)
 *
 * Adaptation has completed and locked
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID      (6)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_VALID)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field RX_ANA_EQ[9:7] (RO)
 *
 * Equalization setting to Analog.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ      (7)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ      (0x00000380)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_ANA_EQ)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field RX_EQ_CTR[12:10] (RO)
 *
 * Initial centre point from equalization FSM.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR      (10)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR      (0x00001c00)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_RX_EQ_CTR)

/* --- Register HW_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG, field ADAP_RX_EQ[15:13] (RO)
 *
 * Equalization setting from adaptation FSM.
 */

#define BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ      (13)      //!< Bit position for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ.
#define BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ      (0x0000e000)  //!< Bit mask for PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ.

//! @brief Get value of PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ from a register value.
#define BG_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ(r)   (((r) & BM_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ) >> BP_PCIE_PHY_RX_CDR_CDR_FSM_DEBUG_ADAP_RX_EQ)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD -  (RW)
 *
 * Reset value: 0x00008000
 *

 */
typedef union _hw_pcie_phy_rx_cdr_lock_vec_ovrd
{
    reg16_t U;
    struct _hw_pcie_phy_rx_cdr_lock_vec_ovrd_bitfields
    {
        unsigned short LOCK_VECTOR : 8; //!< [7:0] Override value for the locked_vector.
        unsigned short LOCK_VECTOR_EN : 1; //!< [8] Override value for the locked_vector output completion.
        unsigned short LOCK_VECTOR_OVRD : 1; //!< [9] Override enable for the rx_eq outputs.
        unsigned short ADAP_POLARITY : 1; //!< [10] If asserted invert default adaptation adjustment for equalization. IF early decrease equalization. Normal mode is to decrease.
        unsigned short ADAP_CTR_LEVEL : 5; //!< [15:11] Amount of earlies that increment the adaptation counter (times 16).
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

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field LOCK_VECTOR[7:0] (RW)
 *
 * Override value for the locked_vector.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR      (0)      //!< Bit position for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR.
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR      (0x000000ff)  //!< Bit mask for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR.

//! @brief Get value of PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR from a register value.
#define BG_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR(r)   (((r) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR) >> BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR(v)   (((v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_VECTOR field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR(v)   (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR((HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD() & ~BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR) | BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field LOCK_VECTOR_EN[8] (RW)
 *
 * Override value for the locked_vector output completion.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN      (8)      //!< Bit position for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN.
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN      (0x00000100)  //!< Bit mask for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN.

//! @brief Get value of PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN from a register value.
#define BG_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN(r)   (((r) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN) >> BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN(v)   (((v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_VECTOR_EN field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN(v)   (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR((HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD() & ~BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN) | BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field LOCK_VECTOR_OVRD[9] (RW)
 *
 * Override enable for the rx_eq outputs.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD      (9)      //!< Bit position for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD.
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD      (0x00000200)  //!< Bit mask for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD.

//! @brief Get value of PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD from a register value.
#define BG_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD(r)   (((r) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD) >> BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD(v)   (((v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_VECTOR_OVRD field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD(v)   (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR((HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD() & ~BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD) | BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_LOCK_VECTOR_OVRD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field ADAP_POLARITY[10] (RW)
 *
 * If asserted invert default adaptation adjustment for equalization. IF early decrease
 * equalization. Normal mode is to decrease.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY      (10)      //!< Bit position for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY.
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY      (0x00000400)  //!< Bit mask for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY.

//! @brief Get value of PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY from a register value.
#define BG_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY(r)   (((r) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY) >> BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY(v)   (((v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADAP_POLARITY field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY(v)   (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR((HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD() & ~BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY) | BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_POLARITY(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD, field ADAP_CTR_LEVEL[15:11] (RW)
 *
 * Amount of earlies that increment the adaptation counter (times 16).
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL      (11)      //!< Bit position for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL.
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL      (0x0000f800)  //!< Bit mask for PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL.

//! @brief Get value of PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL from a register value.
#define BG_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL(r)   (((r) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL) >> BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL.
#define BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL(v)   (((v) << BP_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADAP_CTR_LEVEL field to a new value.
#define BW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL(v)   (HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_WR((HW_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_RD() & ~BM_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL) | BF_PCIE_PHY_RX_CDR_LOCK_VEC_OVRD_ADAP_CTR_LEVEL(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_LOCK_VEC -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_cdr_lock_vec
{
    reg16_t U;
    struct _hw_pcie_phy_rx_cdr_lock_vec_bitfields
    {
        unsigned short EQ_LOCKED_VECTOR : 8; //!< [7:0] Results of equalization loop.
        unsigned short EQ_LOCKED_VECTOR_EN : 1; //!< [8] Equalization locked vector has been filled.
        unsigned short EQ_RX_EQ : 3; //!< [11:9] Equalization setting from the Equalization Loop.
        unsigned short RESERVED0 : 4; //!< [15:12] Reserved
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

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC, field EQ_LOCKED_VECTOR[7:0] (RO)
 *
 * Results of equalization loop.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR      (0)      //!< Bit position for PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR.
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR      (0x000000ff)  //!< Bit mask for PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR.

//! @brief Get value of PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR from a register value.
#define BG_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR(r)   (((r) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR) >> BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR)

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC, field EQ_LOCKED_VECTOR_EN[8] (RO)
 *
 * Equalization locked vector has been filled.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN      (8)      //!< Bit position for PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN.
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN      (0x00000100)  //!< Bit mask for PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN.

//! @brief Get value of PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN from a register value.
#define BG_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN(r)   (((r) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN) >> BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_LOCKED_VECTOR_EN)

/* --- Register HW_PCIE_PHY_RX_CDR_LOCK_VEC, field EQ_RX_EQ[11:9] (RO)
 *
 * Equalization setting from the Equalization Loop.
 */

#define BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ      (9)      //!< Bit position for PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ.
#define BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ      (0x00000e00)  //!< Bit mask for PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ.

//! @brief Get value of PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ from a register value.
#define BG_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ(r)   (((r) & BM_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ) >> BP_PCIE_PHY_RX_CDR_LOCK_VEC_EQ_RX_EQ)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_CDR_ADAP_FSM -  (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_cdr_adap_fsm
{
    reg16_t U;
    struct _hw_pcie_phy_rx_cdr_adap_fsm_bitfields
    {
        unsigned short ADAP_STATE : 3; //!< [2:0] Adaptation State.
        unsigned short ADAP_CTR : 4; //!< [6:3] Adaptation count register.
        unsigned short LOOP_CTR : 4; //!< [10:7] Loop count register.
        unsigned short MSTR_CTR : 5; //!< [15:11] Master count register.
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

/* --- Register HW_PCIE_PHY_RX_CDR_ADAP_FSM, field ADAP_STATE[2:0] (RO)
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

#define BP_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE      (0)      //!< Bit position for PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE.
#define BM_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE      (0x00000007)  //!< Bit mask for PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE.

//! @brief Get value of PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE from a register value.
#define BG_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE(r)   (((r) & BM_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE) >> BP_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_STATE)


/* --- Register HW_PCIE_PHY_RX_CDR_ADAP_FSM, field ADAP_CTR[6:3] (RO)
 *
 * Adaptation count register.
 */

#define BP_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR      (3)      //!< Bit position for PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR.
#define BM_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR      (0x00000078)  //!< Bit mask for PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR.

//! @brief Get value of PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR from a register value.
#define BG_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR(r)   (((r) & BM_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR) >> BP_PCIE_PHY_RX_CDR_ADAP_FSM_ADAP_CTR)

/* --- Register HW_PCIE_PHY_RX_CDR_ADAP_FSM, field LOOP_CTR[10:7] (RO)
 *
 * Loop count register.
 */

#define BP_PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR      (7)      //!< Bit position for PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR.
#define BM_PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR      (0x00000780)  //!< Bit mask for PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR.

//! @brief Get value of PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR from a register value.
#define BG_PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR(r)   (((r) & BM_PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR) >> BP_PCIE_PHY_RX_CDR_ADAP_FSM_LOOP_CTR)

/* --- Register HW_PCIE_PHY_RX_CDR_ADAP_FSM, field MSTR_CTR[15:11] (RO)
 *
 * Master count register.
 */

#define BP_PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR      (11)      //!< Bit position for PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR.
#define BM_PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR      (0x0000f800)  //!< Bit mask for PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR.

//! @brief Get value of PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR from a register value.
#define BG_PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR(r)   (((r) & BM_PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR) >> BP_PCIE_PHY_RX_CDR_ADAP_FSM_MSTR_CTR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ATB0 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_atb0
{
    reg16_t U;
    struct _hw_pcie_phy_rx_atb0_bitfields
    {
        unsigned short EN_ATB_VOFF : 1; //!< [0] Puts rxafe voff_p on atb_s_p and voff_m on atb_s_m.
        unsigned short EN_ATB_RP_S : 1; //!< [1] Puts rxafe outputs vo_p on atb_s_p and vo_m on atb_s_m.
        unsigned short EN_ATB_RP_F : 1; //!< [2] Enables atb_sense_p on positive-side termination resistor.
        unsigned short EN_ATB_RM_S : 1; //!< [3] Enables atb_force_p on positive-side termination resistor.
        unsigned short EN_ATB_RM_F : 1; //!< [4] Enables atb_sense_m on negative-side termination resistor.
        unsigned short EN_MARG : 1; //!< [5] Enables atb_force_p on negative-side termination resistor.
        unsigned short EN_ATB : 1; //!< [6] Enables margining mode in receiver; requires atb_f_m to be high-Z!.
        unsigned short EN_ATB1 : 1; //!< [7] Enables ATB sensing and forcing on internal Rx nodes.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_VOFF[0] (RW)
 *
 * Puts rxafe voff_p on atb_s_p and voff_m on atb_s_m.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_VOFF      (0)      //!< Bit position for PCIE_PHY_RX_ATB0_EN_ATB_VOFF.
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_VOFF      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_ATB0_EN_ATB_VOFF.

//! @brief Get value of PCIE_PHY_RX_ATB0_EN_ATB_VOFF from a register value.
#define BG_PCIE_PHY_RX_ATB0_EN_ATB_VOFF(r)   (((r) & BM_PCIE_PHY_RX_ATB0_EN_ATB_VOFF) >> BP_PCIE_PHY_RX_ATB0_EN_ATB_VOFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_VOFF.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_VOFF(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_VOFF) & BM_PCIE_PHY_RX_ATB0_EN_ATB_VOFF)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_VOFF.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_VOFF(v)   (((v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_VOFF) & BM_PCIE_PHY_RX_ATB0_EN_ATB_VOFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_VOFF field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_VOFF(v)   (HW_PCIE_PHY_RX_ATB0_WR((HW_PCIE_PHY_RX_ATB0_RD() & ~BM_PCIE_PHY_RX_ATB0_EN_ATB_VOFF) | BF_PCIE_PHY_RX_ATB0_EN_ATB_VOFF(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_RP_S[1] (RW)
 *
 * Puts rxafe outputs vo_p on atb_s_p and vo_m on atb_s_m.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_S      (1)      //!< Bit position for PCIE_PHY_RX_ATB0_EN_ATB_RP_S.
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_S      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_ATB0_EN_ATB_RP_S.

//! @brief Get value of PCIE_PHY_RX_ATB0_EN_ATB_RP_S from a register value.
#define BG_PCIE_PHY_RX_ATB0_EN_ATB_RP_S(r)   (((r) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_S) >> BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_S)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_RP_S.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_S(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_S) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_S)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_RP_S.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_S(v)   (((v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_S) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_S)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_RP_S field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_RP_S(v)   (HW_PCIE_PHY_RX_ATB0_WR((HW_PCIE_PHY_RX_ATB0_RD() & ~BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_S) | BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_S(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_RP_F[2] (RW)
 *
 * Enables atb_sense_p on positive-side termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_F      (2)      //!< Bit position for PCIE_PHY_RX_ATB0_EN_ATB_RP_F.
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_F      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_ATB0_EN_ATB_RP_F.

//! @brief Get value of PCIE_PHY_RX_ATB0_EN_ATB_RP_F from a register value.
#define BG_PCIE_PHY_RX_ATB0_EN_ATB_RP_F(r)   (((r) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_F) >> BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_F)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_RP_F.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_F(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_F) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_F)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_RP_F.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_F(v)   (((v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_RP_F) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_F)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_RP_F field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_RP_F(v)   (HW_PCIE_PHY_RX_ATB0_WR((HW_PCIE_PHY_RX_ATB0_RD() & ~BM_PCIE_PHY_RX_ATB0_EN_ATB_RP_F) | BF_PCIE_PHY_RX_ATB0_EN_ATB_RP_F(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_RM_S[3] (RW)
 *
 * Enables atb_force_p on positive-side termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_S      (3)      //!< Bit position for PCIE_PHY_RX_ATB0_EN_ATB_RM_S.
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_S      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_ATB0_EN_ATB_RM_S.

//! @brief Get value of PCIE_PHY_RX_ATB0_EN_ATB_RM_S from a register value.
#define BG_PCIE_PHY_RX_ATB0_EN_ATB_RM_S(r)   (((r) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_S) >> BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_S)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_RM_S.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_S(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_S) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_S)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_RM_S.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_S(v)   (((v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_S) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_S)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_RM_S field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_RM_S(v)   (HW_PCIE_PHY_RX_ATB0_WR((HW_PCIE_PHY_RX_ATB0_RD() & ~BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_S) | BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_S(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB_RM_F[4] (RW)
 *
 * Enables atb_sense_m on negative-side termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_F      (4)      //!< Bit position for PCIE_PHY_RX_ATB0_EN_ATB_RM_F.
#define BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_F      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_ATB0_EN_ATB_RM_F.

//! @brief Get value of PCIE_PHY_RX_ATB0_EN_ATB_RM_F from a register value.
#define BG_PCIE_PHY_RX_ATB0_EN_ATB_RM_F(r)   (((r) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_F) >> BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_F)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_RM_F.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_F(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_F) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_F)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB_RM_F.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_F(v)   (((v) << BP_PCIE_PHY_RX_ATB0_EN_ATB_RM_F) & BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_F)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_RM_F field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB_RM_F(v)   (HW_PCIE_PHY_RX_ATB0_WR((HW_PCIE_PHY_RX_ATB0_RD() & ~BM_PCIE_PHY_RX_ATB0_EN_ATB_RM_F) | BF_PCIE_PHY_RX_ATB0_EN_ATB_RM_F(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_MARG[5] (RW)
 *
 * Enables atb_force_p on negative-side termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_MARG      (5)      //!< Bit position for PCIE_PHY_RX_ATB0_EN_MARG.
#define BM_PCIE_PHY_RX_ATB0_EN_MARG      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_ATB0_EN_MARG.

//! @brief Get value of PCIE_PHY_RX_ATB0_EN_MARG from a register value.
#define BG_PCIE_PHY_RX_ATB0_EN_MARG(r)   (((r) & BM_PCIE_PHY_RX_ATB0_EN_MARG) >> BP_PCIE_PHY_RX_ATB0_EN_MARG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_MARG.
#define BF_PCIE_PHY_RX_ATB0_EN_MARG(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB0_EN_MARG) & BM_PCIE_PHY_RX_ATB0_EN_MARG)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_MARG.
#define BF_PCIE_PHY_RX_ATB0_EN_MARG(v)   (((v) << BP_PCIE_PHY_RX_ATB0_EN_MARG) & BM_PCIE_PHY_RX_ATB0_EN_MARG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_MARG field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_MARG(v)   (HW_PCIE_PHY_RX_ATB0_WR((HW_PCIE_PHY_RX_ATB0_RD() & ~BM_PCIE_PHY_RX_ATB0_EN_MARG) | BF_PCIE_PHY_RX_ATB0_EN_MARG(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB[6] (RW)
 *
 * Enables margining mode in receiver; requires atb_f_m to be high-Z!.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB      (6)      //!< Bit position for PCIE_PHY_RX_ATB0_EN_ATB.
#define BM_PCIE_PHY_RX_ATB0_EN_ATB      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_ATB0_EN_ATB.

//! @brief Get value of PCIE_PHY_RX_ATB0_EN_ATB from a register value.
#define BG_PCIE_PHY_RX_ATB0_EN_ATB(r)   (((r) & BM_PCIE_PHY_RX_ATB0_EN_ATB) >> BP_PCIE_PHY_RX_ATB0_EN_ATB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB0_EN_ATB) & BM_PCIE_PHY_RX_ATB0_EN_ATB)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB(v)   (((v) << BP_PCIE_PHY_RX_ATB0_EN_ATB) & BM_PCIE_PHY_RX_ATB0_EN_ATB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB(v)   (HW_PCIE_PHY_RX_ATB0_WR((HW_PCIE_PHY_RX_ATB0_RD() & ~BM_PCIE_PHY_RX_ATB0_EN_ATB) | BF_PCIE_PHY_RX_ATB0_EN_ATB(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB0, field EN_ATB1[7] (RW)
 *
 * Enables ATB sensing and forcing on internal Rx nodes.
 */

#define BP_PCIE_PHY_RX_ATB0_EN_ATB1      (7)      //!< Bit position for PCIE_PHY_RX_ATB0_EN_ATB1.
#define BM_PCIE_PHY_RX_ATB0_EN_ATB1      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_ATB0_EN_ATB1.

//! @brief Get value of PCIE_PHY_RX_ATB0_EN_ATB1 from a register value.
#define BG_PCIE_PHY_RX_ATB0_EN_ATB1(r)   (((r) & BM_PCIE_PHY_RX_ATB0_EN_ATB1) >> BP_PCIE_PHY_RX_ATB0_EN_ATB1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB1.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB1(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB0_EN_ATB1) & BM_PCIE_PHY_RX_ATB0_EN_ATB1)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB0_EN_ATB1.
#define BF_PCIE_PHY_RX_ATB0_EN_ATB1(v)   (((v) << BP_PCIE_PHY_RX_ATB0_EN_ATB1) & BM_PCIE_PHY_RX_ATB0_EN_ATB1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB1 field to a new value.
#define BW_PCIE_PHY_RX_ATB0_EN_ATB1(v)   (HW_PCIE_PHY_RX_ATB0_WR((HW_PCIE_PHY_RX_ATB0_RD() & ~BM_PCIE_PHY_RX_ATB0_EN_ATB1) | BF_PCIE_PHY_RX_ATB0_EN_ATB1(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ATB1 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_atb1
{
    reg16_t U;
    struct _hw_pcie_phy_rx_atb1_bitfields
    {
        unsigned short NC0 : 1; //!< [0] Enables/disables Rx termination resistor.
        unsigned short EN_VLOS_USB3 : 1; //!< [1] Enables LOS levels to be those for USB3; otherwise, PCI Express levels.
        unsigned short MEAS_VP : 1; //!< [2] Enables sensing of local vp in Rx; ties vp to atb_sense_p.
        unsigned short MEAS_GD : 1; //!< [3] Enables sensing of local gd in Rx; ties gd to atb_sense_m.
        unsigned short EN_ATB_VRF : 1; //!< [4] Enables sensing of vref_rx on atb_sense_p.
        unsigned short EN_ATB_VLOS : 1; //!< [5] Enables sensing of LOS reference voltage on atb_sense_p.
        unsigned short VLOS_MIN : 1; //!< [6] Sets LOS reference voltage. (VLOS_MAX, VLOS_MIN): (1,1): None (1,0): Maximum (0,1): Minimum (0,0): Nominal
        unsigned short VLOS_MAX : 1; //!< [7] Sets LOS reference voltage. (VLOS_MAX, VLOS_MIN): (1,1): None (1,0): Maximum (0,1): Minimum (0,0): Nominal
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_RX_ATB1, field NC0[0] (RW)
 *
 * Enables/disables Rx termination resistor.
 */

#define BP_PCIE_PHY_RX_ATB1_NC0      (0)      //!< Bit position for PCIE_PHY_RX_ATB1_NC0.
#define BM_PCIE_PHY_RX_ATB1_NC0      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_ATB1_NC0.

//! @brief Get value of PCIE_PHY_RX_ATB1_NC0 from a register value.
#define BG_PCIE_PHY_RX_ATB1_NC0(r)   (((r) & BM_PCIE_PHY_RX_ATB1_NC0) >> BP_PCIE_PHY_RX_ATB1_NC0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_NC0.
#define BF_PCIE_PHY_RX_ATB1_NC0(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB1_NC0) & BM_PCIE_PHY_RX_ATB1_NC0)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_NC0.
#define BF_PCIE_PHY_RX_ATB1_NC0(v)   (((v) << BP_PCIE_PHY_RX_ATB1_NC0) & BM_PCIE_PHY_RX_ATB1_NC0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NC0 field to a new value.
#define BW_PCIE_PHY_RX_ATB1_NC0(v)   (HW_PCIE_PHY_RX_ATB1_WR((HW_PCIE_PHY_RX_ATB1_RD() & ~BM_PCIE_PHY_RX_ATB1_NC0) | BF_PCIE_PHY_RX_ATB1_NC0(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field EN_VLOS_USB3[1] (RW)
 *
 * Enables LOS levels to be those for USB3; otherwise, PCI Express levels.
 */

#define BP_PCIE_PHY_RX_ATB1_EN_VLOS_USB3      (1)      //!< Bit position for PCIE_PHY_RX_ATB1_EN_VLOS_USB3.
#define BM_PCIE_PHY_RX_ATB1_EN_VLOS_USB3      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_ATB1_EN_VLOS_USB3.

//! @brief Get value of PCIE_PHY_RX_ATB1_EN_VLOS_USB3 from a register value.
#define BG_PCIE_PHY_RX_ATB1_EN_VLOS_USB3(r)   (((r) & BM_PCIE_PHY_RX_ATB1_EN_VLOS_USB3) >> BP_PCIE_PHY_RX_ATB1_EN_VLOS_USB3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_EN_VLOS_USB3.
#define BF_PCIE_PHY_RX_ATB1_EN_VLOS_USB3(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB1_EN_VLOS_USB3) & BM_PCIE_PHY_RX_ATB1_EN_VLOS_USB3)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_EN_VLOS_USB3.
#define BF_PCIE_PHY_RX_ATB1_EN_VLOS_USB3(v)   (((v) << BP_PCIE_PHY_RX_ATB1_EN_VLOS_USB3) & BM_PCIE_PHY_RX_ATB1_EN_VLOS_USB3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_VLOS_USB3 field to a new value.
#define BW_PCIE_PHY_RX_ATB1_EN_VLOS_USB3(v)   (HW_PCIE_PHY_RX_ATB1_WR((HW_PCIE_PHY_RX_ATB1_RD() & ~BM_PCIE_PHY_RX_ATB1_EN_VLOS_USB3) | BF_PCIE_PHY_RX_ATB1_EN_VLOS_USB3(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field MEAS_VP[2] (RW)
 *
 * Enables sensing of local vp in Rx; ties vp to atb_sense_p.
 */

#define BP_PCIE_PHY_RX_ATB1_MEAS_VP      (2)      //!< Bit position for PCIE_PHY_RX_ATB1_MEAS_VP.
#define BM_PCIE_PHY_RX_ATB1_MEAS_VP      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_ATB1_MEAS_VP.

//! @brief Get value of PCIE_PHY_RX_ATB1_MEAS_VP from a register value.
#define BG_PCIE_PHY_RX_ATB1_MEAS_VP(r)   (((r) & BM_PCIE_PHY_RX_ATB1_MEAS_VP) >> BP_PCIE_PHY_RX_ATB1_MEAS_VP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_MEAS_VP.
#define BF_PCIE_PHY_RX_ATB1_MEAS_VP(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB1_MEAS_VP) & BM_PCIE_PHY_RX_ATB1_MEAS_VP)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_MEAS_VP.
#define BF_PCIE_PHY_RX_ATB1_MEAS_VP(v)   (((v) << BP_PCIE_PHY_RX_ATB1_MEAS_VP) & BM_PCIE_PHY_RX_ATB1_MEAS_VP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_VP field to a new value.
#define BW_PCIE_PHY_RX_ATB1_MEAS_VP(v)   (HW_PCIE_PHY_RX_ATB1_WR((HW_PCIE_PHY_RX_ATB1_RD() & ~BM_PCIE_PHY_RX_ATB1_MEAS_VP) | BF_PCIE_PHY_RX_ATB1_MEAS_VP(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field MEAS_GD[3] (RW)
 *
 * Enables sensing of local gd in Rx; ties gd to atb_sense_m.
 */

#define BP_PCIE_PHY_RX_ATB1_MEAS_GD      (3)      //!< Bit position for PCIE_PHY_RX_ATB1_MEAS_GD.
#define BM_PCIE_PHY_RX_ATB1_MEAS_GD      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_ATB1_MEAS_GD.

//! @brief Get value of PCIE_PHY_RX_ATB1_MEAS_GD from a register value.
#define BG_PCIE_PHY_RX_ATB1_MEAS_GD(r)   (((r) & BM_PCIE_PHY_RX_ATB1_MEAS_GD) >> BP_PCIE_PHY_RX_ATB1_MEAS_GD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_MEAS_GD.
#define BF_PCIE_PHY_RX_ATB1_MEAS_GD(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB1_MEAS_GD) & BM_PCIE_PHY_RX_ATB1_MEAS_GD)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_MEAS_GD.
#define BF_PCIE_PHY_RX_ATB1_MEAS_GD(v)   (((v) << BP_PCIE_PHY_RX_ATB1_MEAS_GD) & BM_PCIE_PHY_RX_ATB1_MEAS_GD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_GD field to a new value.
#define BW_PCIE_PHY_RX_ATB1_MEAS_GD(v)   (HW_PCIE_PHY_RX_ATB1_WR((HW_PCIE_PHY_RX_ATB1_RD() & ~BM_PCIE_PHY_RX_ATB1_MEAS_GD) | BF_PCIE_PHY_RX_ATB1_MEAS_GD(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field EN_ATB_VRF[4] (RW)
 *
 * Enables sensing of vref_rx on atb_sense_p.
 */

#define BP_PCIE_PHY_RX_ATB1_EN_ATB_VRF      (4)      //!< Bit position for PCIE_PHY_RX_ATB1_EN_ATB_VRF.
#define BM_PCIE_PHY_RX_ATB1_EN_ATB_VRF      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_ATB1_EN_ATB_VRF.

//! @brief Get value of PCIE_PHY_RX_ATB1_EN_ATB_VRF from a register value.
#define BG_PCIE_PHY_RX_ATB1_EN_ATB_VRF(r)   (((r) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VRF) >> BP_PCIE_PHY_RX_ATB1_EN_ATB_VRF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_EN_ATB_VRF.
#define BF_PCIE_PHY_RX_ATB1_EN_ATB_VRF(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB1_EN_ATB_VRF) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VRF)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_EN_ATB_VRF.
#define BF_PCIE_PHY_RX_ATB1_EN_ATB_VRF(v)   (((v) << BP_PCIE_PHY_RX_ATB1_EN_ATB_VRF) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VRF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_VRF field to a new value.
#define BW_PCIE_PHY_RX_ATB1_EN_ATB_VRF(v)   (HW_PCIE_PHY_RX_ATB1_WR((HW_PCIE_PHY_RX_ATB1_RD() & ~BM_PCIE_PHY_RX_ATB1_EN_ATB_VRF) | BF_PCIE_PHY_RX_ATB1_EN_ATB_VRF(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field EN_ATB_VLOS[5] (RW)
 *
 * Enables sensing of LOS reference voltage on atb_sense_p.
 */

#define BP_PCIE_PHY_RX_ATB1_EN_ATB_VLOS      (5)      //!< Bit position for PCIE_PHY_RX_ATB1_EN_ATB_VLOS.
#define BM_PCIE_PHY_RX_ATB1_EN_ATB_VLOS      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_ATB1_EN_ATB_VLOS.

//! @brief Get value of PCIE_PHY_RX_ATB1_EN_ATB_VLOS from a register value.
#define BG_PCIE_PHY_RX_ATB1_EN_ATB_VLOS(r)   (((r) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VLOS) >> BP_PCIE_PHY_RX_ATB1_EN_ATB_VLOS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_EN_ATB_VLOS.
#define BF_PCIE_PHY_RX_ATB1_EN_ATB_VLOS(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB1_EN_ATB_VLOS) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VLOS)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_EN_ATB_VLOS.
#define BF_PCIE_PHY_RX_ATB1_EN_ATB_VLOS(v)   (((v) << BP_PCIE_PHY_RX_ATB1_EN_ATB_VLOS) & BM_PCIE_PHY_RX_ATB1_EN_ATB_VLOS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ATB_VLOS field to a new value.
#define BW_PCIE_PHY_RX_ATB1_EN_ATB_VLOS(v)   (HW_PCIE_PHY_RX_ATB1_WR((HW_PCIE_PHY_RX_ATB1_RD() & ~BM_PCIE_PHY_RX_ATB1_EN_ATB_VLOS) | BF_PCIE_PHY_RX_ATB1_EN_ATB_VLOS(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field VLOS_MIN[6] (RW)
 *
 * Sets LOS reference voltage. (VLOS_MAX, VLOS_MIN): (1,1): None (1,0): Maximum (0,1): Minimum
 * (0,0): Nominal
 */

#define BP_PCIE_PHY_RX_ATB1_VLOS_MIN      (6)      //!< Bit position for PCIE_PHY_RX_ATB1_VLOS_MIN.
#define BM_PCIE_PHY_RX_ATB1_VLOS_MIN      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_ATB1_VLOS_MIN.

//! @brief Get value of PCIE_PHY_RX_ATB1_VLOS_MIN from a register value.
#define BG_PCIE_PHY_RX_ATB1_VLOS_MIN(r)   (((r) & BM_PCIE_PHY_RX_ATB1_VLOS_MIN) >> BP_PCIE_PHY_RX_ATB1_VLOS_MIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_VLOS_MIN.
#define BF_PCIE_PHY_RX_ATB1_VLOS_MIN(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB1_VLOS_MIN) & BM_PCIE_PHY_RX_ATB1_VLOS_MIN)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_VLOS_MIN.
#define BF_PCIE_PHY_RX_ATB1_VLOS_MIN(v)   (((v) << BP_PCIE_PHY_RX_ATB1_VLOS_MIN) & BM_PCIE_PHY_RX_ATB1_VLOS_MIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VLOS_MIN field to a new value.
#define BW_PCIE_PHY_RX_ATB1_VLOS_MIN(v)   (HW_PCIE_PHY_RX_ATB1_WR((HW_PCIE_PHY_RX_ATB1_RD() & ~BM_PCIE_PHY_RX_ATB1_VLOS_MIN) | BF_PCIE_PHY_RX_ATB1_VLOS_MIN(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ATB1, field VLOS_MAX[7] (RW)
 *
 * Sets LOS reference voltage. (VLOS_MAX, VLOS_MIN): (1,1): None (1,0): Maximum (0,1): Minimum
 * (0,0): Nominal
 */

#define BP_PCIE_PHY_RX_ATB1_VLOS_MAX      (7)      //!< Bit position for PCIE_PHY_RX_ATB1_VLOS_MAX.
#define BM_PCIE_PHY_RX_ATB1_VLOS_MAX      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_ATB1_VLOS_MAX.

//! @brief Get value of PCIE_PHY_RX_ATB1_VLOS_MAX from a register value.
#define BG_PCIE_PHY_RX_ATB1_VLOS_MAX(r)   (((r) & BM_PCIE_PHY_RX_ATB1_VLOS_MAX) >> BP_PCIE_PHY_RX_ATB1_VLOS_MAX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_VLOS_MAX.
#define BF_PCIE_PHY_RX_ATB1_VLOS_MAX(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ATB1_VLOS_MAX) & BM_PCIE_PHY_RX_ATB1_VLOS_MAX)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ATB1_VLOS_MAX.
#define BF_PCIE_PHY_RX_ATB1_VLOS_MAX(v)   (((v) << BP_PCIE_PHY_RX_ATB1_VLOS_MAX) & BM_PCIE_PHY_RX_ATB1_VLOS_MAX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VLOS_MAX field to a new value.
#define BW_PCIE_PHY_RX_ATB1_VLOS_MAX(v)   (HW_PCIE_PHY_RX_ATB1_WR((HW_PCIE_PHY_RX_ATB1_RD() & ~BM_PCIE_PHY_RX_ATB1_VLOS_MAX) | BF_PCIE_PHY_RX_ATB1_VLOS_MAX(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ENPWR0 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_enpwr0
{
    reg16_t U;
    struct _hw_pcie_phy_rx_enpwr0_bitfields
    {
        unsigned short LCL_ACJT : 1; //!< [0] Enables/disables ACJTAG block.
        unsigned short CTL_ACJT : 1; //!< [1] Enables override of ACJTAG block state.
        unsigned short LCL_RXCK : 1; //!< [2] Enables/disables en_rx_clock (Rx clock enable).
        unsigned short CTL_RXCK : 1; //!< [3] Enables override of Rx clock circuit state.
        unsigned short LCL_EN_LOS : 1; //!< [4] Enables/disables LOS block.
        unsigned short CTL_EN_LOS : 1; //!< [5] Enables override of LOS block state.
        unsigned short LCL_RXPWRON : 1; //!< [6] Enables/disables Rx slicers.
        unsigned short CTL_RXPWRON : 1; //!< [7] Enables override of Rx block power.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field LCL_ACJT[0] (RW)
 *
 * Enables/disables ACJTAG block.
 */

#define BP_PCIE_PHY_RX_ENPWR0_LCL_ACJT      (0)      //!< Bit position for PCIE_PHY_RX_ENPWR0_LCL_ACJT.
#define BM_PCIE_PHY_RX_ENPWR0_LCL_ACJT      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_ENPWR0_LCL_ACJT.

//! @brief Get value of PCIE_PHY_RX_ENPWR0_LCL_ACJT from a register value.
#define BG_PCIE_PHY_RX_ENPWR0_LCL_ACJT(r)   (((r) & BM_PCIE_PHY_RX_ENPWR0_LCL_ACJT) >> BP_PCIE_PHY_RX_ENPWR0_LCL_ACJT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_LCL_ACJT.
#define BF_PCIE_PHY_RX_ENPWR0_LCL_ACJT(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR0_LCL_ACJT) & BM_PCIE_PHY_RX_ENPWR0_LCL_ACJT)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_LCL_ACJT.
#define BF_PCIE_PHY_RX_ENPWR0_LCL_ACJT(v)   (((v) << BP_PCIE_PHY_RX_ENPWR0_LCL_ACJT) & BM_PCIE_PHY_RX_ENPWR0_LCL_ACJT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_ACJT field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_LCL_ACJT(v)   (HW_PCIE_PHY_RX_ENPWR0_WR((HW_PCIE_PHY_RX_ENPWR0_RD() & ~BM_PCIE_PHY_RX_ENPWR0_LCL_ACJT) | BF_PCIE_PHY_RX_ENPWR0_LCL_ACJT(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field CTL_ACJT[1] (RW)
 *
 * Enables override of ACJTAG block state.
 */

#define BP_PCIE_PHY_RX_ENPWR0_CTL_ACJT      (1)      //!< Bit position for PCIE_PHY_RX_ENPWR0_CTL_ACJT.
#define BM_PCIE_PHY_RX_ENPWR0_CTL_ACJT      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_ENPWR0_CTL_ACJT.

//! @brief Get value of PCIE_PHY_RX_ENPWR0_CTL_ACJT from a register value.
#define BG_PCIE_PHY_RX_ENPWR0_CTL_ACJT(r)   (((r) & BM_PCIE_PHY_RX_ENPWR0_CTL_ACJT) >> BP_PCIE_PHY_RX_ENPWR0_CTL_ACJT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_CTL_ACJT.
#define BF_PCIE_PHY_RX_ENPWR0_CTL_ACJT(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR0_CTL_ACJT) & BM_PCIE_PHY_RX_ENPWR0_CTL_ACJT)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_CTL_ACJT.
#define BF_PCIE_PHY_RX_ENPWR0_CTL_ACJT(v)   (((v) << BP_PCIE_PHY_RX_ENPWR0_CTL_ACJT) & BM_PCIE_PHY_RX_ENPWR0_CTL_ACJT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_ACJT field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_CTL_ACJT(v)   (HW_PCIE_PHY_RX_ENPWR0_WR((HW_PCIE_PHY_RX_ENPWR0_RD() & ~BM_PCIE_PHY_RX_ENPWR0_CTL_ACJT) | BF_PCIE_PHY_RX_ENPWR0_CTL_ACJT(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field LCL_RXCK[2] (RW)
 *
 * Enables/disables en_rx_clock (Rx clock enable).
 */

#define BP_PCIE_PHY_RX_ENPWR0_LCL_RXCK      (2)      //!< Bit position for PCIE_PHY_RX_ENPWR0_LCL_RXCK.
#define BM_PCIE_PHY_RX_ENPWR0_LCL_RXCK      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_ENPWR0_LCL_RXCK.

//! @brief Get value of PCIE_PHY_RX_ENPWR0_LCL_RXCK from a register value.
#define BG_PCIE_PHY_RX_ENPWR0_LCL_RXCK(r)   (((r) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXCK) >> BP_PCIE_PHY_RX_ENPWR0_LCL_RXCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_LCL_RXCK.
#define BF_PCIE_PHY_RX_ENPWR0_LCL_RXCK(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR0_LCL_RXCK) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXCK)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_LCL_RXCK.
#define BF_PCIE_PHY_RX_ENPWR0_LCL_RXCK(v)   (((v) << BP_PCIE_PHY_RX_ENPWR0_LCL_RXCK) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_RXCK field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_LCL_RXCK(v)   (HW_PCIE_PHY_RX_ENPWR0_WR((HW_PCIE_PHY_RX_ENPWR0_RD() & ~BM_PCIE_PHY_RX_ENPWR0_LCL_RXCK) | BF_PCIE_PHY_RX_ENPWR0_LCL_RXCK(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field CTL_RXCK[3] (RW)
 *
 * Enables override of Rx clock circuit state.
 */

#define BP_PCIE_PHY_RX_ENPWR0_CTL_RXCK      (3)      //!< Bit position for PCIE_PHY_RX_ENPWR0_CTL_RXCK.
#define BM_PCIE_PHY_RX_ENPWR0_CTL_RXCK      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_ENPWR0_CTL_RXCK.

//! @brief Get value of PCIE_PHY_RX_ENPWR0_CTL_RXCK from a register value.
#define BG_PCIE_PHY_RX_ENPWR0_CTL_RXCK(r)   (((r) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXCK) >> BP_PCIE_PHY_RX_ENPWR0_CTL_RXCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_CTL_RXCK.
#define BF_PCIE_PHY_RX_ENPWR0_CTL_RXCK(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR0_CTL_RXCK) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXCK)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_CTL_RXCK.
#define BF_PCIE_PHY_RX_ENPWR0_CTL_RXCK(v)   (((v) << BP_PCIE_PHY_RX_ENPWR0_CTL_RXCK) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_RXCK field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_CTL_RXCK(v)   (HW_PCIE_PHY_RX_ENPWR0_WR((HW_PCIE_PHY_RX_ENPWR0_RD() & ~BM_PCIE_PHY_RX_ENPWR0_CTL_RXCK) | BF_PCIE_PHY_RX_ENPWR0_CTL_RXCK(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field LCL_EN_LOS[4] (RW)
 *
 * Enables/disables LOS block.
 */

#define BP_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS      (4)      //!< Bit position for PCIE_PHY_RX_ENPWR0_LCL_EN_LOS.
#define BM_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_ENPWR0_LCL_EN_LOS.

//! @brief Get value of PCIE_PHY_RX_ENPWR0_LCL_EN_LOS from a register value.
#define BG_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS(r)   (((r) & BM_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS) >> BP_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_LCL_EN_LOS.
#define BF_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS) & BM_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_LCL_EN_LOS.
#define BF_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS(v)   (((v) << BP_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS) & BM_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_EN_LOS field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS(v)   (HW_PCIE_PHY_RX_ENPWR0_WR((HW_PCIE_PHY_RX_ENPWR0_RD() & ~BM_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS) | BF_PCIE_PHY_RX_ENPWR0_LCL_EN_LOS(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field CTL_EN_LOS[5] (RW)
 *
 * Enables override of LOS block state.
 */

#define BP_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS      (5)      //!< Bit position for PCIE_PHY_RX_ENPWR0_CTL_EN_LOS.
#define BM_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_ENPWR0_CTL_EN_LOS.

//! @brief Get value of PCIE_PHY_RX_ENPWR0_CTL_EN_LOS from a register value.
#define BG_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS(r)   (((r) & BM_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS) >> BP_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_CTL_EN_LOS.
#define BF_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS) & BM_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_CTL_EN_LOS.
#define BF_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS(v)   (((v) << BP_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS) & BM_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_EN_LOS field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS(v)   (HW_PCIE_PHY_RX_ENPWR0_WR((HW_PCIE_PHY_RX_ENPWR0_RD() & ~BM_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS) | BF_PCIE_PHY_RX_ENPWR0_CTL_EN_LOS(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field LCL_RXPWRON[6] (RW)
 *
 * Enables/disables Rx slicers.
 */

#define BP_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON      (6)      //!< Bit position for PCIE_PHY_RX_ENPWR0_LCL_RXPWRON.
#define BM_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_ENPWR0_LCL_RXPWRON.

//! @brief Get value of PCIE_PHY_RX_ENPWR0_LCL_RXPWRON from a register value.
#define BG_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON(r)   (((r) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON) >> BP_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_LCL_RXPWRON.
#define BF_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_LCL_RXPWRON.
#define BF_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON(v)   (((v) << BP_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON) & BM_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_RXPWRON field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON(v)   (HW_PCIE_PHY_RX_ENPWR0_WR((HW_PCIE_PHY_RX_ENPWR0_RD() & ~BM_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON) | BF_PCIE_PHY_RX_ENPWR0_LCL_RXPWRON(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR0, field CTL_RXPWRON[7] (RW)
 *
 * Enables override of Rx block power.
 */

#define BP_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON      (7)      //!< Bit position for PCIE_PHY_RX_ENPWR0_CTL_RXPWRON.
#define BM_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_ENPWR0_CTL_RXPWRON.

//! @brief Get value of PCIE_PHY_RX_ENPWR0_CTL_RXPWRON from a register value.
#define BG_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON(r)   (((r) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON) >> BP_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_CTL_RXPWRON.
#define BF_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR0_CTL_RXPWRON.
#define BF_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON(v)   (((v) << BP_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON) & BM_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_RXPWRON field to a new value.
#define BW_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON(v)   (HW_PCIE_PHY_RX_ENPWR0_WR((HW_PCIE_PHY_RX_ENPWR0_RD() & ~BM_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON) | BF_PCIE_PHY_RX_ENPWR0_CTL_RXPWRON(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_PMIX_PHASE -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_pmix_phase
{
    reg16_t U;
    struct _hw_pcie_phy_rx_pmix_phase_bitfields
    {
        unsigned short PHASE : 8; //!< [7:0] Write to bits 8-1 of the Phase Select register in the phase mixer.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_RX_PMIX_PHASE, field PHASE[7:0] (RW)
 *
 * Write to bits 8-1 of the Phase Select register in the phase mixer.
 */

#define BP_PCIE_PHY_RX_PMIX_PHASE_PHASE      (0)      //!< Bit position for PCIE_PHY_RX_PMIX_PHASE_PHASE.
#define BM_PCIE_PHY_RX_PMIX_PHASE_PHASE      (0x000000ff)  //!< Bit mask for PCIE_PHY_RX_PMIX_PHASE_PHASE.

//! @brief Get value of PCIE_PHY_RX_PMIX_PHASE_PHASE from a register value.
#define BG_PCIE_PHY_RX_PMIX_PHASE_PHASE(r)   (((r) & BM_PCIE_PHY_RX_PMIX_PHASE_PHASE) >> BP_PCIE_PHY_RX_PMIX_PHASE_PHASE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_PMIX_PHASE_PHASE.
#define BF_PCIE_PHY_RX_PMIX_PHASE_PHASE(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_PMIX_PHASE_PHASE) & BM_PCIE_PHY_RX_PMIX_PHASE_PHASE)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_PMIX_PHASE_PHASE.
#define BF_PCIE_PHY_RX_PMIX_PHASE_PHASE(v)   (((v) << BP_PCIE_PHY_RX_PMIX_PHASE_PHASE) & BM_PCIE_PHY_RX_PMIX_PHASE_PHASE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PHASE field to a new value.
#define BW_PCIE_PHY_RX_PMIX_PHASE_PHASE(v)   (HW_PCIE_PHY_RX_PMIX_PHASE_WR((HW_PCIE_PHY_RX_PMIX_PHASE_RD() & ~BM_PCIE_PHY_RX_PMIX_PHASE_PHASE) | BF_PCIE_PHY_RX_PMIX_PHASE_PHASE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ENPWR1 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_enpwr1
{
    reg16_t U;
    struct _hw_pcie_phy_rx_enpwr1_bitfields
    {
        unsigned short CTL_PHASE_REG_RST : 1; //!< [0] Enables override of Phase register reset.
        unsigned short LCL_PHASE_REG_RST : 1; //!< [1] Reset Phase register.
        unsigned short CTL_BST : 1; //!< [2] Enables override of Rx boost (equalization) value.
        unsigned short LCL_BST : 3; //!< [5:3] Rx boost (equalization) value
        unsigned short CTL_RXTERM : 1; //!< [6] Enables override of rx_term_en.
        unsigned short LCL_RXTERM : 1; //!< [7] Enables/disables Rx termination.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field CTL_PHASE_REG_RST[0] (RW)
 *
 * Enables override of Phase register reset.
 */

#define BP_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST      (0)      //!< Bit position for PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST.
#define BM_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST.

//! @brief Get value of PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST from a register value.
#define BG_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST(r)   (((r) & BM_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST) >> BP_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST.
#define BF_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST) & BM_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST.
#define BF_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST(v)   (((v) << BP_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST) & BM_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_PHASE_REG_RST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST(v)   (HW_PCIE_PHY_RX_ENPWR1_WR((HW_PCIE_PHY_RX_ENPWR1_RD() & ~BM_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST) | BF_PCIE_PHY_RX_ENPWR1_CTL_PHASE_REG_RST(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field LCL_PHASE_REG_RST[1] (RW)
 *
 * Reset Phase register.
 */

#define BP_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST      (1)      //!< Bit position for PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST.
#define BM_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST.

//! @brief Get value of PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST from a register value.
#define BG_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST(r)   (((r) & BM_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST) >> BP_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST.
#define BF_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST) & BM_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST.
#define BF_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST(v)   (((v) << BP_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST) & BM_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_PHASE_REG_RST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST(v)   (HW_PCIE_PHY_RX_ENPWR1_WR((HW_PCIE_PHY_RX_ENPWR1_RD() & ~BM_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST) | BF_PCIE_PHY_RX_ENPWR1_LCL_PHASE_REG_RST(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field CTL_BST[2] (RW)
 *
 * Enables override of Rx boost (equalization) value.
 */

#define BP_PCIE_PHY_RX_ENPWR1_CTL_BST      (2)      //!< Bit position for PCIE_PHY_RX_ENPWR1_CTL_BST.
#define BM_PCIE_PHY_RX_ENPWR1_CTL_BST      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_ENPWR1_CTL_BST.

//! @brief Get value of PCIE_PHY_RX_ENPWR1_CTL_BST from a register value.
#define BG_PCIE_PHY_RX_ENPWR1_CTL_BST(r)   (((r) & BM_PCIE_PHY_RX_ENPWR1_CTL_BST) >> BP_PCIE_PHY_RX_ENPWR1_CTL_BST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_CTL_BST.
#define BF_PCIE_PHY_RX_ENPWR1_CTL_BST(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR1_CTL_BST) & BM_PCIE_PHY_RX_ENPWR1_CTL_BST)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_CTL_BST.
#define BF_PCIE_PHY_RX_ENPWR1_CTL_BST(v)   (((v) << BP_PCIE_PHY_RX_ENPWR1_CTL_BST) & BM_PCIE_PHY_RX_ENPWR1_CTL_BST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_BST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_CTL_BST(v)   (HW_PCIE_PHY_RX_ENPWR1_WR((HW_PCIE_PHY_RX_ENPWR1_RD() & ~BM_PCIE_PHY_RX_ENPWR1_CTL_BST) | BF_PCIE_PHY_RX_ENPWR1_CTL_BST(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field LCL_BST[5:3] (RW)
 *
 * Rx boost (equalization) value
 */

#define BP_PCIE_PHY_RX_ENPWR1_LCL_BST      (3)      //!< Bit position for PCIE_PHY_RX_ENPWR1_LCL_BST.
#define BM_PCIE_PHY_RX_ENPWR1_LCL_BST      (0x00000038)  //!< Bit mask for PCIE_PHY_RX_ENPWR1_LCL_BST.

//! @brief Get value of PCIE_PHY_RX_ENPWR1_LCL_BST from a register value.
#define BG_PCIE_PHY_RX_ENPWR1_LCL_BST(r)   (((r) & BM_PCIE_PHY_RX_ENPWR1_LCL_BST) >> BP_PCIE_PHY_RX_ENPWR1_LCL_BST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_LCL_BST.
#define BF_PCIE_PHY_RX_ENPWR1_LCL_BST(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR1_LCL_BST) & BM_PCIE_PHY_RX_ENPWR1_LCL_BST)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_LCL_BST.
#define BF_PCIE_PHY_RX_ENPWR1_LCL_BST(v)   (((v) << BP_PCIE_PHY_RX_ENPWR1_LCL_BST) & BM_PCIE_PHY_RX_ENPWR1_LCL_BST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_BST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_LCL_BST(v)   (HW_PCIE_PHY_RX_ENPWR1_WR((HW_PCIE_PHY_RX_ENPWR1_RD() & ~BM_PCIE_PHY_RX_ENPWR1_LCL_BST) | BF_PCIE_PHY_RX_ENPWR1_LCL_BST(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field CTL_RXTERM[6] (RW)
 *
 * Enables override of rx_term_en.
 */

#define BP_PCIE_PHY_RX_ENPWR1_CTL_RXTERM      (6)      //!< Bit position for PCIE_PHY_RX_ENPWR1_CTL_RXTERM.
#define BM_PCIE_PHY_RX_ENPWR1_CTL_RXTERM      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_ENPWR1_CTL_RXTERM.

//! @brief Get value of PCIE_PHY_RX_ENPWR1_CTL_RXTERM from a register value.
#define BG_PCIE_PHY_RX_ENPWR1_CTL_RXTERM(r)   (((r) & BM_PCIE_PHY_RX_ENPWR1_CTL_RXTERM) >> BP_PCIE_PHY_RX_ENPWR1_CTL_RXTERM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_CTL_RXTERM.
#define BF_PCIE_PHY_RX_ENPWR1_CTL_RXTERM(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR1_CTL_RXTERM) & BM_PCIE_PHY_RX_ENPWR1_CTL_RXTERM)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_CTL_RXTERM.
#define BF_PCIE_PHY_RX_ENPWR1_CTL_RXTERM(v)   (((v) << BP_PCIE_PHY_RX_ENPWR1_CTL_RXTERM) & BM_PCIE_PHY_RX_ENPWR1_CTL_RXTERM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTL_RXTERM field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_CTL_RXTERM(v)   (HW_PCIE_PHY_RX_ENPWR1_WR((HW_PCIE_PHY_RX_ENPWR1_RD() & ~BM_PCIE_PHY_RX_ENPWR1_CTL_RXTERM) | BF_PCIE_PHY_RX_ENPWR1_CTL_RXTERM(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR1, field LCL_RXTERM[7] (RW)
 *
 * Enables/disables Rx termination.
 */

#define BP_PCIE_PHY_RX_ENPWR1_LCL_RXTERM      (7)      //!< Bit position for PCIE_PHY_RX_ENPWR1_LCL_RXTERM.
#define BM_PCIE_PHY_RX_ENPWR1_LCL_RXTERM      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_ENPWR1_LCL_RXTERM.

//! @brief Get value of PCIE_PHY_RX_ENPWR1_LCL_RXTERM from a register value.
#define BG_PCIE_PHY_RX_ENPWR1_LCL_RXTERM(r)   (((r) & BM_PCIE_PHY_RX_ENPWR1_LCL_RXTERM) >> BP_PCIE_PHY_RX_ENPWR1_LCL_RXTERM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_LCL_RXTERM.
#define BF_PCIE_PHY_RX_ENPWR1_LCL_RXTERM(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR1_LCL_RXTERM) & BM_PCIE_PHY_RX_ENPWR1_LCL_RXTERM)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR1_LCL_RXTERM.
#define BF_PCIE_PHY_RX_ENPWR1_LCL_RXTERM(v)   (((v) << BP_PCIE_PHY_RX_ENPWR1_LCL_RXTERM) & BM_PCIE_PHY_RX_ENPWR1_LCL_RXTERM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LCL_RXTERM field to a new value.
#define BW_PCIE_PHY_RX_ENPWR1_LCL_RXTERM(v)   (HW_PCIE_PHY_RX_ENPWR1_WR((HW_PCIE_PHY_RX_ENPWR1_RD() & ~BM_PCIE_PHY_RX_ENPWR1_LCL_RXTERM) | BF_PCIE_PHY_RX_ENPWR1_LCL_RXTERM(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_ENPWR2 -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_enpwr2
{
    reg16_t U;
    struct _hw_pcie_phy_rx_enpwr2_bitfields
    {
        unsigned short RX_SCOPE_ATB_0 : 1; //!< [0] Instructs Rx scope regulated VP to use atb_f_p as reference instead of VP.
        unsigned short RX_SCOPE_ATB_1 : 1; //!< [1] Puts Rx scope regulated VP on atb_s_p.
        unsigned short RX_SCOPE_ATB_2 : 1; //!< [2] Puts XOR of Rx scope PMIX input and output on atb_s_p.
        unsigned short EN_RXPMIX_FRC_VPMIX : 1; //!< [3] Instructs rx_pmix_vreg_pmix to use atb_s_m as a reference instead of vbg.
        unsigned short EN_RXPMIX_VOSC : 1; //!< [4] Puts vreg_vosc on atb_s_p.
        unsigned short EN_RXPMIX_VRX : 1; //!< [5] Puts vreg_rx on atb_s_p.
        unsigned short EN_RXPMIX_VPMIX : 1; //!< [6] Puts vreg_pmix on atb_s_p.
        unsigned short EN_RXPMIX_TST : 1; //!< [7] Enables XOR gate to test linearity of Rx phase mixer using atb_s_p and atb_s_m.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field RX_SCOPE_ATB_0[0] (RW)
 *
 * Instructs Rx scope regulated VP to use atb_f_p as reference instead of VP.
 */

#define BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0      (0)      //!< Bit position for PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0.
#define BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0      (0x00000001)  //!< Bit mask for PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0.

//! @brief Get value of PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0 from a register value.
#define BG_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0(r)   (((r) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0) >> BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0.
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0.
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0(v)   (((v) << BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_ATB_0 field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0(v)   (HW_PCIE_PHY_RX_ENPWR2_WR((HW_PCIE_PHY_RX_ENPWR2_RD() & ~BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0) | BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_0(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field RX_SCOPE_ATB_1[1] (RW)
 *
 * Puts Rx scope regulated VP on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1      (1)      //!< Bit position for PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1.
#define BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1      (0x00000002)  //!< Bit mask for PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1.

//! @brief Get value of PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1 from a register value.
#define BG_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1(r)   (((r) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1) >> BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1.
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1.
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1(v)   (((v) << BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_ATB_1 field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1(v)   (HW_PCIE_PHY_RX_ENPWR2_WR((HW_PCIE_PHY_RX_ENPWR2_RD() & ~BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1) | BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_1(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field RX_SCOPE_ATB_2[2] (RW)
 *
 * Puts XOR of Rx scope PMIX input and output on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2      (2)      //!< Bit position for PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2.
#define BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2      (0x00000004)  //!< Bit mask for PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2.

//! @brief Get value of PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2 from a register value.
#define BG_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2(r)   (((r) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2) >> BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2.
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2.
#define BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2(v)   (((v) << BP_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2) & BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_ATB_2 field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2(v)   (HW_PCIE_PHY_RX_ENPWR2_WR((HW_PCIE_PHY_RX_ENPWR2_RD() & ~BM_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2) | BF_PCIE_PHY_RX_ENPWR2_RX_SCOPE_ATB_2(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_FRC_VPMIX[3] (RW)
 *
 * Instructs rx_pmix_vreg_pmix to use atb_s_m as a reference instead of vbg.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX      (3)      //!< Bit position for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX.
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX.

//! @brief Get value of PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX from a register value.
#define BG_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX(r)   (((r) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX) >> BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX(v)   (((v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_FRC_VPMIX field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX(v)   (HW_PCIE_PHY_RX_ENPWR2_WR((HW_PCIE_PHY_RX_ENPWR2_RD() & ~BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX) | BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_FRC_VPMIX(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_VOSC[4] (RW)
 *
 * Puts vreg_vosc on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC      (4)      //!< Bit position for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC.
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC.

//! @brief Get value of PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC from a register value.
#define BG_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC(r)   (((r) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC) >> BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC(v)   (((v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_VOSC field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC(v)   (HW_PCIE_PHY_RX_ENPWR2_WR((HW_PCIE_PHY_RX_ENPWR2_RD() & ~BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC) | BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VOSC(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_VRX[5] (RW)
 *
 * Puts vreg_rx on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX      (5)      //!< Bit position for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX.
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX      (0x00000020)  //!< Bit mask for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX.

//! @brief Get value of PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX from a register value.
#define BG_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX(r)   (((r) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX) >> BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX(v)   (((v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_VRX field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX(v)   (HW_PCIE_PHY_RX_ENPWR2_WR((HW_PCIE_PHY_RX_ENPWR2_RD() & ~BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX) | BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VRX(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_VPMIX[6] (RW)
 *
 * Puts vreg_pmix on atb_s_p.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX      (6)      //!< Bit position for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX.
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX      (0x00000040)  //!< Bit mask for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX.

//! @brief Get value of PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX from a register value.
#define BG_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX(r)   (((r) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX) >> BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX(v)   (((v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_VPMIX field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX(v)   (HW_PCIE_PHY_RX_ENPWR2_WR((HW_PCIE_PHY_RX_ENPWR2_RD() & ~BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX) | BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_VPMIX(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_ENPWR2, field EN_RXPMIX_TST[7] (RW)
 *
 * Enables XOR gate to test linearity of Rx phase mixer using atb_s_p and atb_s_m.
 */

#define BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST      (7)      //!< Bit position for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST.
#define BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST      (0x00000080)  //!< Bit mask for PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST.

//! @brief Get value of PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST from a register value.
#define BG_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST(r)   (((r) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST) >> BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST.
#define BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST(v)   (((v) << BP_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST) & BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_RXPMIX_TST field to a new value.
#define BW_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST(v)   (HW_PCIE_PHY_RX_ENPWR2_WR((HW_PCIE_PHY_RX_ENPWR2_RD() & ~BM_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST) | BF_PCIE_PHY_RX_ENPWR2_EN_RXPMIX_TST(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_RX_SCOPE -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_rx_scope
{
    reg16_t U;
    struct _hw_pcie_phy_rx_scope_bitfields
    {
        unsigned short NC_SCOPE_3 : 3; //!< [2:0] NC
        unsigned short RX_SCOPE_FDIV20 : 1; //!< [3] Divides scope output clock by 20 instead of 10.
        unsigned short RX_SCOPE_SLEW : 1; //!< [4] Sets high for low Rx clock frqeuencies (625 MHz) for Rx scope to work correctly.
        unsigned short NC_SCOPE_2 : 3; //!< [7:5] NC
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_RX_SCOPE, field NC_SCOPE_3[2:0] (RW)
 *
 * NC
 */

#define BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_3      (0)      //!< Bit position for PCIE_PHY_RX_SCOPE_NC_SCOPE_3.
#define BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_3      (0x00000007)  //!< Bit mask for PCIE_PHY_RX_SCOPE_NC_SCOPE_3.

//! @brief Get value of PCIE_PHY_RX_SCOPE_NC_SCOPE_3 from a register value.
#define BG_PCIE_PHY_RX_SCOPE_NC_SCOPE_3(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_3) >> BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_NC_SCOPE_3.
#define BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_3(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_3) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_3)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_NC_SCOPE_3.
#define BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_3(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_3) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NC_SCOPE_3 field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_NC_SCOPE_3(v)   (HW_PCIE_PHY_RX_SCOPE_WR((HW_PCIE_PHY_RX_SCOPE_RD() & ~BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_3) | BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_3(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE, field RX_SCOPE_FDIV20[3] (RW)
 *
 * Divides scope output clock by 20 instead of 10.
 */

#define BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20      (3)      //!< Bit position for PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20.
#define BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20      (0x00000008)  //!< Bit mask for PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20.

//! @brief Get value of PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20 from a register value.
#define BG_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20) >> BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20.
#define BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20.
#define BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_FDIV20 field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20(v)   (HW_PCIE_PHY_RX_SCOPE_WR((HW_PCIE_PHY_RX_SCOPE_RD() & ~BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20) | BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_FDIV20(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE, field RX_SCOPE_SLEW[4] (RW)
 *
 * Sets high for low Rx clock frqeuencies (625 MHz) for Rx scope to work correctly.
 */

#define BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW      (4)      //!< Bit position for PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW.
#define BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW      (0x00000010)  //!< Bit mask for PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW.

//! @brief Get value of PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW from a register value.
#define BG_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW) >> BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW.
#define BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW.
#define BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW) & BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SCOPE_SLEW field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW(v)   (HW_PCIE_PHY_RX_SCOPE_WR((HW_PCIE_PHY_RX_SCOPE_RD() & ~BM_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW) | BF_PCIE_PHY_RX_SCOPE_RX_SCOPE_SLEW(v)))
#endif

/* --- Register HW_PCIE_PHY_RX_SCOPE, field NC_SCOPE_2[7:5] (RW)
 *
 * NC
 */

#define BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_2      (5)      //!< Bit position for PCIE_PHY_RX_SCOPE_NC_SCOPE_2.
#define BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_2      (0x000000e0)  //!< Bit mask for PCIE_PHY_RX_SCOPE_NC_SCOPE_2.

//! @brief Get value of PCIE_PHY_RX_SCOPE_NC_SCOPE_2 from a register value.
#define BG_PCIE_PHY_RX_SCOPE_NC_SCOPE_2(r)   (((r) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_2) >> BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_NC_SCOPE_2.
#define BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_2(v)   ((((reg16_t) v) << BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_2) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_2)
#else
//! @brief Format value for bitfield PCIE_PHY_RX_SCOPE_NC_SCOPE_2.
#define BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_2(v)   (((v) << BP_PCIE_PHY_RX_SCOPE_NC_SCOPE_2) & BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NC_SCOPE_2 field to a new value.
#define BW_PCIE_PHY_RX_SCOPE_NC_SCOPE_2(v)   (HW_PCIE_PHY_RX_SCOPE_WR((HW_PCIE_PHY_RX_SCOPE_RD() & ~BM_PCIE_PHY_RX_SCOPE_NC_SCOPE_2) | BF_PCIE_PHY_RX_SCOPE_NC_SCOPE_2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_TXDRV_CNTRL -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_txdrv_cntrl
{
    reg16_t U;
    struct _hw_pcie_phy_tx_txdrv_cntrl_bitfields
    {
        unsigned short NOCONN_6 : 1; //!< [0] Reserved
        unsigned short NOCONN_7 : 1; //!< [1] Reserved
        unsigned short NOCONN_8 : 1; //!< [2] Reserved
        unsigned short OVRD_VCM_HOLD : 1; //!< [3] Selects local value of vcm_hold_reg instead of tx_vcm_hold to control state of TX common mode hold circuitry.
        unsigned short VCM_HOLD_REG : 1; //!< [4] Register override for tx_vcm_hold; selected when ovrd_vcm_hold is high; controls the TX common mode hold circuitry.
        unsigned short OVRD_PULL_UP : 1; //!< [5] Selects loval value of pull_up_reg instead of tx_pull_up.
        unsigned short PULL_UP_REG : 1; //!< [6] Register override for tx_pull_up; selected when ovrd_pull_up is high; causes calibrated TX bits to pull up in common mode fashion, unless pull_dn_reg is high.
        unsigned short PULL_DN_REG : 1; //!< [7] Register bit that causes the calibrated Tx bits to pull down in common mode fashion. If pull_dn_reg and tx_pull_up are both high, then pull_dn_reg wins (takes precedence" ).
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field NOCONN_6[0] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6      (0)      //!< Bit position for PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6.
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6.

//! @brief Get value of PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6 from a register value.
#define BG_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6(r)   (((r) & BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6) >> BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_6)

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field NOCONN_7[1] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7      (1)      //!< Bit position for PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7.
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7      (0x00000002)  //!< Bit mask for PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7.

//! @brief Get value of PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7 from a register value.
#define BG_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7(r)   (((r) & BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7) >> BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_7)

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field NOCONN_8[2] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8      (2)      //!< Bit position for PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8.
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8.

//! @brief Get value of PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8 from a register value.
#define BG_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8(r)   (((r) & BM_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8) >> BP_PCIE_PHY_TX_TXDRV_CNTRL_NOCONN_8)

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field OVRD_VCM_HOLD[3] (RW)
 *
 * Selects local value of vcm_hold_reg instead of tx_vcm_hold to control state of TX common mode
 * hold circuitry.
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD      (3)      //!< Bit position for PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD.
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD.

//! @brief Get value of PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD from a register value.
#define BG_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD(r)   (((r) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD) >> BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD(v)   (((v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_VCM_HOLD field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD(v)   (HW_PCIE_PHY_TX_TXDRV_CNTRL_WR((HW_PCIE_PHY_TX_TXDRV_CNTRL_RD() & ~BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD) | BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_VCM_HOLD(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field VCM_HOLD_REG[4] (RW)
 *
 * Register override for tx_vcm_hold; selected when ovrd_vcm_hold is high; controls the TX common
 * mode hold circuitry.
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG      (4)      //!< Bit position for PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG.
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG.

//! @brief Get value of PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG from a register value.
#define BG_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG(r)   (((r) & BM_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG) >> BP_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG) & BM_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG(v)   (((v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG) & BM_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VCM_HOLD_REG field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG(v)   (HW_PCIE_PHY_TX_TXDRV_CNTRL_WR((HW_PCIE_PHY_TX_TXDRV_CNTRL_RD() & ~BM_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG) | BF_PCIE_PHY_TX_TXDRV_CNTRL_VCM_HOLD_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field OVRD_PULL_UP[5] (RW)
 *
 * Selects loval value of pull_up_reg instead of tx_pull_up.
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP      (5)      //!< Bit position for PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP.
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP      (0x00000020)  //!< Bit mask for PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP.

//! @brief Get value of PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP from a register value.
#define BG_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP(r)   (((r) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP) >> BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP(v)   (((v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP) & BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_PULL_UP field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP(v)   (HW_PCIE_PHY_TX_TXDRV_CNTRL_WR((HW_PCIE_PHY_TX_TXDRV_CNTRL_RD() & ~BM_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP) | BF_PCIE_PHY_TX_TXDRV_CNTRL_OVRD_PULL_UP(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field PULL_UP_REG[6] (RW)
 *
 * Register override for tx_pull_up; selected when ovrd_pull_up is high; causes calibrated TX bits
 * to pull up in common mode fashion, unless pull_dn_reg is high.
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG      (6)      //!< Bit position for PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG.
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG      (0x00000040)  //!< Bit mask for PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG.

//! @brief Get value of PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG from a register value.
#define BG_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG(r)   (((r) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG) >> BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG(v)   (((v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PULL_UP_REG field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG(v)   (HW_PCIE_PHY_TX_TXDRV_CNTRL_WR((HW_PCIE_PHY_TX_TXDRV_CNTRL_RD() & ~BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG) | BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_UP_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TXDRV_CNTRL, field PULL_DN_REG[7] (RW)
 *
 * Register bit that causes the calibrated Tx bits to pull down in common mode fashion. If
 * pull_dn_reg and tx_pull_up are both high, then pull_dn_reg wins (takes precedence" ).
 */

#define BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG      (7)      //!< Bit position for PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG.
#define BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG.

//! @brief Get value of PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG from a register value.
#define BG_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG(r)   (((r) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG) >> BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG.
#define BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG(v)   (((v) << BP_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG) & BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PULL_DN_REG field to a new value.
#define BW_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG(v)   (HW_PCIE_PHY_TX_TXDRV_CNTRL_WR((HW_PCIE_PHY_TX_TXDRV_CNTRL_RD() & ~BM_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG) | BF_PCIE_PHY_TX_TXDRV_CNTRL_PULL_DN_REG(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_POWER_CTL -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_power_ctl
{
    reg16_t U;
    struct _hw_pcie_phy_tx_power_ctl_bitfields
    {
        unsigned short NOCONN_5 : 1; //!< [0] Reserved
        unsigned short REFGEN_PDN_REG : 1; //!< [1] Value for refgen_pwdn when OVRD_EN is 1.
        unsigned short TX_DIV_CLK_EN : 1; //!< [2] Enables the div clock that is output from the Tx to the undersampler, more appropriately called tx_sampler_clk_en; this clock is output after the optional divide-by-2/ 4; tx_clk_en must be high to output a clock.
        unsigned short REFGEN_EN_REG : 1; //!< [3] Register override value for tx_refgen_en; turns on the pmos_bias refgen block and the rxdetect comparators.
        unsigned short DATA_EN_REG : 1; //!< [4] Value for tx_data_en when OVRD_EN is 1.
        unsigned short CLK_EN_REG : 1; //!< [5] Value for tx_clk_en when OVRD_EN is 1.
        unsigned short SERIAL_EN_REG : 1; //!< [6] Value for tx_serial_en when OVRD_EN is 1.
        unsigned short OVRD_EN : 1; //!< [7] Enables local overrides for all signals in this register.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field NOCONN_5[0] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_POWER_CTL_NOCONN_5      (0)      //!< Bit position for PCIE_PHY_TX_POWER_CTL_NOCONN_5.
#define BM_PCIE_PHY_TX_POWER_CTL_NOCONN_5      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_POWER_CTL_NOCONN_5.

//! @brief Get value of PCIE_PHY_TX_POWER_CTL_NOCONN_5 from a register value.
#define BG_PCIE_PHY_TX_POWER_CTL_NOCONN_5(r)   (((r) & BM_PCIE_PHY_TX_POWER_CTL_NOCONN_5) >> BP_PCIE_PHY_TX_POWER_CTL_NOCONN_5)

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field REFGEN_PDN_REG[1] (RW)
 *
 * Value for refgen_pwdn when OVRD_EN is 1.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG      (1)      //!< Bit position for PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG.
#define BM_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG      (0x00000002)  //!< Bit mask for PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG.

//! @brief Get value of PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG from a register value.
#define BG_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG(r)   (((r) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG) >> BP_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG(v)   (((v) << BP_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFGEN_PDN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG(v)   (HW_PCIE_PHY_TX_POWER_CTL_WR((HW_PCIE_PHY_TX_POWER_CTL_RD() & ~BM_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG) | BF_PCIE_PHY_TX_POWER_CTL_REFGEN_PDN_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field TX_DIV_CLK_EN[2] (RW)
 *
 * Enables the div clock that is output from the Tx to the undersampler, more appropriately called
 * tx_sampler_clk_en; this clock is output after the optional divide-by-2/ 4; tx_clk_en must be high
 * to output a clock.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN      (2)      //!< Bit position for PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN.
#define BM_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN.

//! @brief Get value of PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN from a register value.
#define BG_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN(r)   (((r) & BM_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN) >> BP_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN.
#define BF_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN) & BM_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN.
#define BF_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN(v)   (((v) << BP_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN) & BM_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DIV_CLK_EN field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN(v)   (HW_PCIE_PHY_TX_POWER_CTL_WR((HW_PCIE_PHY_TX_POWER_CTL_RD() & ~BM_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN) | BF_PCIE_PHY_TX_POWER_CTL_TX_DIV_CLK_EN(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field REFGEN_EN_REG[3] (RW)
 *
 * Register override value for tx_refgen_en; turns on the pmos_bias refgen block and the rxdetect
 * comparators.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG      (3)      //!< Bit position for PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG.
#define BM_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG.

//! @brief Get value of PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG from a register value.
#define BG_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG(r)   (((r) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG) >> BP_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG(v)   (((v) << BP_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG) & BM_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFGEN_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG(v)   (HW_PCIE_PHY_TX_POWER_CTL_WR((HW_PCIE_PHY_TX_POWER_CTL_RD() & ~BM_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG) | BF_PCIE_PHY_TX_POWER_CTL_REFGEN_EN_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field DATA_EN_REG[4] (RW)
 *
 * Value for tx_data_en when OVRD_EN is 1.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG      (4)      //!< Bit position for PCIE_PHY_TX_POWER_CTL_DATA_EN_REG.
#define BM_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_POWER_CTL_DATA_EN_REG.

//! @brief Get value of PCIE_PHY_TX_POWER_CTL_DATA_EN_REG from a register value.
#define BG_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG(r)   (((r) & BM_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG) >> BP_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_DATA_EN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG) & BM_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_DATA_EN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG(v)   (((v) << BP_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG) & BM_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG(v)   (HW_PCIE_PHY_TX_POWER_CTL_WR((HW_PCIE_PHY_TX_POWER_CTL_RD() & ~BM_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG) | BF_PCIE_PHY_TX_POWER_CTL_DATA_EN_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field CLK_EN_REG[5] (RW)
 *
 * Value for tx_clk_en when OVRD_EN is 1.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG      (5)      //!< Bit position for PCIE_PHY_TX_POWER_CTL_CLK_EN_REG.
#define BM_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG      (0x00000020)  //!< Bit mask for PCIE_PHY_TX_POWER_CTL_CLK_EN_REG.

//! @brief Get value of PCIE_PHY_TX_POWER_CTL_CLK_EN_REG from a register value.
#define BG_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG(r)   (((r) & BM_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG) >> BP_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_CLK_EN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG) & BM_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_CLK_EN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG(v)   (((v) << BP_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG) & BM_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG(v)   (HW_PCIE_PHY_TX_POWER_CTL_WR((HW_PCIE_PHY_TX_POWER_CTL_RD() & ~BM_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG) | BF_PCIE_PHY_TX_POWER_CTL_CLK_EN_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field SERIAL_EN_REG[6] (RW)
 *
 * Value for tx_serial_en when OVRD_EN is 1.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG      (6)      //!< Bit position for PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG.
#define BM_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG      (0x00000040)  //!< Bit mask for PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG.

//! @brief Get value of PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG from a register value.
#define BG_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG(r)   (((r) & BM_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG) >> BP_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG) & BM_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG.
#define BF_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG(v)   (((v) << BP_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG) & BM_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SERIAL_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG(v)   (HW_PCIE_PHY_TX_POWER_CTL_WR((HW_PCIE_PHY_TX_POWER_CTL_RD() & ~BM_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG) | BF_PCIE_PHY_TX_POWER_CTL_SERIAL_EN_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_POWER_CTL, field OVRD_EN[7] (RW)
 *
 * Enables local overrides for all signals in this register.
 */

#define BP_PCIE_PHY_TX_POWER_CTL_OVRD_EN      (7)      //!< Bit position for PCIE_PHY_TX_POWER_CTL_OVRD_EN.
#define BM_PCIE_PHY_TX_POWER_CTL_OVRD_EN      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_POWER_CTL_OVRD_EN.

//! @brief Get value of PCIE_PHY_TX_POWER_CTL_OVRD_EN from a register value.
#define BG_PCIE_PHY_TX_POWER_CTL_OVRD_EN(r)   (((r) & BM_PCIE_PHY_TX_POWER_CTL_OVRD_EN) >> BP_PCIE_PHY_TX_POWER_CTL_OVRD_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_OVRD_EN.
#define BF_PCIE_PHY_TX_POWER_CTL_OVRD_EN(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_POWER_CTL_OVRD_EN) & BM_PCIE_PHY_TX_POWER_CTL_OVRD_EN)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_POWER_CTL_OVRD_EN.
#define BF_PCIE_PHY_TX_POWER_CTL_OVRD_EN(v)   (((v) << BP_PCIE_PHY_TX_POWER_CTL_OVRD_EN) & BM_PCIE_PHY_TX_POWER_CTL_OVRD_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_EN field to a new value.
#define BW_PCIE_PHY_TX_POWER_CTL_OVRD_EN(v)   (HW_PCIE_PHY_TX_POWER_CTL_WR((HW_PCIE_PHY_TX_POWER_CTL_RD() & ~BM_PCIE_PHY_TX_POWER_CTL_OVRD_EN) | BF_PCIE_PHY_TX_POWER_CTL_OVRD_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ALT_BLOCK -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_alt_block
{
    reg16_t U;
    struct _hw_pcie_phy_tx_alt_block_bitfields
    {
        unsigned short OVRD_ALT_BUS : 1; //!< [0] Enables local overrides for alt-bus control signals.
        unsigned short ALT_OSC_VPHREG : 1; //!< [1] Enables and connects the vphreg oscillator to the transmit pins; must set drv_source_reg bus correctly.
        unsigned short ALT_OSC_VPH : 1; //!< [2] Enables and connects the vph oscillator to the transmit pins; must set drv_source_reg bus correctly.
        unsigned short ALT_OSC_VP : 1; //!< [3] Enables and connects the vp oscillator to the transmit pins; must set drv_source_reg bus correctly.
        unsigned short JTAG_DATA_REG : 1; //!< [4] Value for jtag_data when OVRD_ALT_BUS is 1.
        unsigned short DRV_SOURCE_REG : 2; //!< [6:5] Value for tx_data_source when OVRD_ALT_BUS is 1
        unsigned short EN_ALT_BUS : 1; //!< [7] Enables the Tx for alt bus mode, powers up the pmos_bias block, and so on; required if manually running the alt bus features.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field OVRD_ALT_BUS[0] (RW)
 *
 * Enables local overrides for alt-bus control signals.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS      (0)      //!< Bit position for PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS.
#define BM_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS.

//! @brief Get value of PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS from a register value.
#define BG_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS(r)   (((r) & BM_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS) >> BP_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS.
#define BF_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS) & BM_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS.
#define BF_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS(v)   (((v) << BP_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS) & BM_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_ALT_BUS field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS(v)   (HW_PCIE_PHY_TX_ALT_BLOCK_WR((HW_PCIE_PHY_TX_ALT_BLOCK_RD() & ~BM_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS) | BF_PCIE_PHY_TX_ALT_BLOCK_OVRD_ALT_BUS(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field ALT_OSC_VPHREG[1] (RW)
 *
 * Enables and connects the vphreg oscillator to the transmit pins; must set drv_source_reg bus
 * correctly.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG      (1)      //!< Bit position for PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG.
#define BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG      (0x00000002)  //!< Bit mask for PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG.

//! @brief Get value of PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG from a register value.
#define BG_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG(r)   (((r) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG) >> BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG.
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG.
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG(v)   (((v) << BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALT_OSC_VPHREG field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG(v)   (HW_PCIE_PHY_TX_ALT_BLOCK_WR((HW_PCIE_PHY_TX_ALT_BLOCK_RD() & ~BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG) | BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPHREG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field ALT_OSC_VPH[2] (RW)
 *
 * Enables and connects the vph oscillator to the transmit pins; must set drv_source_reg bus
 * correctly.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH      (2)      //!< Bit position for PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH.
#define BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH.

//! @brief Get value of PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH from a register value.
#define BG_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH(r)   (((r) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH) >> BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH.
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH.
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH(v)   (((v) << BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALT_OSC_VPH field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH(v)   (HW_PCIE_PHY_TX_ALT_BLOCK_WR((HW_PCIE_PHY_TX_ALT_BLOCK_RD() & ~BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH) | BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VPH(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field ALT_OSC_VP[3] (RW)
 *
 * Enables and connects the vp oscillator to the transmit pins; must set drv_source_reg bus
 * correctly.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP      (3)      //!< Bit position for PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP.
#define BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP.

//! @brief Get value of PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP from a register value.
#define BG_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP(r)   (((r) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP) >> BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP.
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP.
#define BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP(v)   (((v) << BP_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP) & BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALT_OSC_VP field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP(v)   (HW_PCIE_PHY_TX_ALT_BLOCK_WR((HW_PCIE_PHY_TX_ALT_BLOCK_RD() & ~BM_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP) | BF_PCIE_PHY_TX_ALT_BLOCK_ALT_OSC_VP(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field JTAG_DATA_REG[4] (RW)
 *
 * Value for jtag_data when OVRD_ALT_BUS is 1.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG      (4)      //!< Bit position for PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG.
#define BM_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG.

//! @brief Get value of PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG from a register value.
#define BG_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG(r)   (((r) & BM_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG) >> BP_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG.
#define BF_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG) & BM_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG.
#define BF_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG(v)   (((v) << BP_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG) & BM_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the JTAG_DATA_REG field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG(v)   (HW_PCIE_PHY_TX_ALT_BLOCK_WR((HW_PCIE_PHY_TX_ALT_BLOCK_RD() & ~BM_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG) | BF_PCIE_PHY_TX_ALT_BLOCK_JTAG_DATA_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field DRV_SOURCE_REG[6:5] (RW)
 *
 * Value for tx_data_source when OVRD_ALT_BUS is 1
 *
 * Values:
 * 00 - Serializer data or alt oscillator vp/vph/vphreg/vptx if selected
 * 01 - JTAG data differential
 * 10 - LFPS oscillator differential
 * 11 - JTAG data common mode for test
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG      (5)      //!< Bit position for PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG.
#define BM_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG      (0x00000060)  //!< Bit mask for PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG.

//! @brief Get value of PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG from a register value.
#define BG_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG(r)   (((r) & BM_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG) >> BP_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG.
#define BF_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG) & BM_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG.
#define BF_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG(v)   (((v) << BP_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG) & BM_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DRV_SOURCE_REG field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG(v)   (HW_PCIE_PHY_TX_ALT_BLOCK_WR((HW_PCIE_PHY_TX_ALT_BLOCK_RD() & ~BM_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG) | BF_PCIE_PHY_TX_ALT_BLOCK_DRV_SOURCE_REG(v)))
#endif


/* --- Register HW_PCIE_PHY_TX_ALT_BLOCK, field EN_ALT_BUS[7] (RW)
 *
 * Enables the Tx for alt bus mode, powers up the pmos_bias block, and so on; required if manually
 * running the alt bus features.
 */

#define BP_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS      (7)      //!< Bit position for PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS.
#define BM_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS.

//! @brief Get value of PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS from a register value.
#define BG_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS(r)   (((r) & BM_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS) >> BP_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS.
#define BF_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS) & BM_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS.
#define BF_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS(v)   (((v) << BP_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS) & BM_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ALT_BUS field to a new value.
#define BW_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS(v)   (HW_PCIE_PHY_TX_ALT_BLOCK_WR((HW_PCIE_PHY_TX_ALT_BLOCK_RD() & ~BM_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS) | BF_PCIE_PHY_TX_ALT_BLOCK_EN_ALT_BUS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_ALT_AND_LOOPBACK -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_alt_and_loopback
{
    reg16_t U;
    struct _hw_pcie_phy_tx_alt_and_loopback_bitfields
    {
        unsigned short NOCONN_00 : 1; //!< [0] Reserved
        unsigned short NOCONN_01 : 1; //!< [1] Reserved
        unsigned short NOCONN_02 : 1; //!< [2] Reserved
        unsigned short NOCONN_03 : 1; //!< [3] Reserved
        unsigned short NOCONN_04 : 1; //!< [4] Reserved
        unsigned short ALT_VPTX_OSC : 1; //!< [5] Enables and connects the vptx oscillator to the transmit pins; must set drv_source_reg bus correctly.
        unsigned short TX_LB_EN_REG : 1; //!< [6] Value of the tx_lb_en pin when OVRD_TX_LB is enabled.
        unsigned short OVRD_TX_LB : 1; //!< [7] Enables the override of the tx_lb_en pin.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_00[0] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00      (0)      //!< Bit position for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00.
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00.

//! @brief Get value of PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00 from a register value.
#define BG_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00(r)   (((r) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00) >> BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_00)

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_01[1] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01      (1)      //!< Bit position for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01.
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01      (0x00000002)  //!< Bit mask for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01.

//! @brief Get value of PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01 from a register value.
#define BG_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01(r)   (((r) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01) >> BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_01)

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_02[2] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02      (2)      //!< Bit position for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02.
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02.

//! @brief Get value of PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02 from a register value.
#define BG_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02(r)   (((r) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02) >> BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_02)

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_03[3] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03      (3)      //!< Bit position for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03.
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03.

//! @brief Get value of PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03 from a register value.
#define BG_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03(r)   (((r) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03) >> BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_03)

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field NOCONN_04[4] (RU)
 *
 * Reserved
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04      (4)      //!< Bit position for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04.
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04.

//! @brief Get value of PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04 from a register value.
#define BG_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04(r)   (((r) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04) >> BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_NOCONN_04)

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field ALT_VPTX_OSC[5] (RW)
 *
 * Enables and connects the vptx oscillator to the transmit pins; must set drv_source_reg bus
 * correctly.
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC      (5)      //!< Bit position for PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC.
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC      (0x00000020)  //!< Bit mask for PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC.

//! @brief Get value of PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC from a register value.
#define BG_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC(r)   (((r) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC) >> BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC.
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC.
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC(v)   (((v) << BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALT_VPTX_OSC field to a new value.
#define BW_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC(v)   (HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_WR((HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_RD() & ~BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC) | BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_ALT_VPTX_OSC(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field TX_LB_EN_REG[6] (RW)
 *
 * Value of the tx_lb_en pin when OVRD_TX_LB is enabled.
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG      (6)      //!< Bit position for PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG.
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG      (0x00000040)  //!< Bit mask for PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG.

//! @brief Get value of PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG from a register value.
#define BG_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG(r)   (((r) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG) >> BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG.
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG.
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG(v)   (((v) << BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_LB_EN_REG field to a new value.
#define BW_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG(v)   (HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_WR((HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_RD() & ~BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG) | BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_TX_LB_EN_REG(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_ALT_AND_LOOPBACK, field OVRD_TX_LB[7] (RW)
 *
 * Enables the override of the tx_lb_en pin.
 */

#define BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB      (7)      //!< Bit position for PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB.
#define BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB.

//! @brief Get value of PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB from a register value.
#define BG_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB(r)   (((r) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB) >> BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB.
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB.
#define BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB(v)   (((v) << BP_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB) & BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_TX_LB field to a new value.
#define BW_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB(v)   (HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_WR((HW_PCIE_PHY_TX_ALT_AND_LOOPBACK_RD() & ~BM_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB) | BF_PCIE_PHY_TX_ALT_AND_LOOPBACK_OVRD_TX_LB(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PHY_TX_TX_ATB_REG -  (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_pcie_phy_tx_tx_atb_reg
{
    reg16_t U;
    struct _hw_pcie_phy_tx_tx_atb_reg_bitfields
    {
        unsigned short ATB_VCM : 1; //!< [0] Connects tx_p/tx_m common mode voltage onto atb_s_p and local ground onto atb_s_m.
        unsigned short ATB_TXSM : 1; //!< [1] Connects tx_m to atb_s_m.
        unsigned short ATB_TXSP : 1; //!< [2] Connects tx_p to atb_s_p.
        unsigned short ATB_TXFM : 1; //!< [3] Connects tx_m to atb_f_m.
        unsigned short ATB_TXFP : 1; //!< [4] Connects tx_p to atb_f_p.
        unsigned short ATB_RXDETREF : 1; //!< [5] Connects Rx detect block reference voltage to atb_s_p and local ground to atb_s_m.
        unsigned short ATB_VCM_REP : 1; //!< [6] Connects common mode replica voltage in pmos_bias block to atb_s_p and local ground to atb_s_m.
        unsigned short ATB_PBIAS : 1; //!< [7] Connects real pmos_bias voltage for Tx PMOS driver pull-up path to atb_s_p and local ground at the pmos_bias block to atb_s_m.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
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

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_VCM[0] (RW)
 *
 * Connects tx_p/tx_m common mode voltage onto atb_s_p and local ground onto atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM      (0)      //!< Bit position for PCIE_PHY_TX_TX_ATB_REG_ATB_VCM.
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM      (0x00000001)  //!< Bit mask for PCIE_PHY_TX_TX_ATB_REG_ATB_VCM.

//! @brief Get value of PCIE_PHY_TX_TX_ATB_REG_ATB_VCM from a register value.
#define BG_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM(r)   (((r) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM) >> BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_VCM.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_VCM.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM(v)   (((v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_VCM field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM(v)   (HW_PCIE_PHY_TX_TX_ATB_REG_WR((HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM) | BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_TXSM[1] (RW)
 *
 * Connects tx_m to atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM      (1)      //!< Bit position for PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM.
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM      (0x00000002)  //!< Bit mask for PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM.

//! @brief Get value of PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM from a register value.
#define BG_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM(r)   (((r) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM) >> BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM(v)   (((v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_TXSM field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM(v)   (HW_PCIE_PHY_TX_TX_ATB_REG_WR((HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM) | BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSM(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_TXSP[2] (RW)
 *
 * Connects tx_p to atb_s_p.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP      (2)      //!< Bit position for PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP.
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP      (0x00000004)  //!< Bit mask for PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP.

//! @brief Get value of PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP from a register value.
#define BG_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP(r)   (((r) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP) >> BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP(v)   (((v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_TXSP field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP(v)   (HW_PCIE_PHY_TX_TX_ATB_REG_WR((HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP) | BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXSP(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_TXFM[3] (RW)
 *
 * Connects tx_m to atb_f_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM      (3)      //!< Bit position for PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM.
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM      (0x00000008)  //!< Bit mask for PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM.

//! @brief Get value of PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM from a register value.
#define BG_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM(r)   (((r) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM) >> BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM(v)   (((v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_TXFM field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM(v)   (HW_PCIE_PHY_TX_TX_ATB_REG_WR((HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM) | BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFM(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_TXFP[4] (RW)
 *
 * Connects tx_p to atb_f_p.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP      (4)      //!< Bit position for PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP.
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP      (0x00000010)  //!< Bit mask for PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP.

//! @brief Get value of PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP from a register value.
#define BG_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP(r)   (((r) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP) >> BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP(v)   (((v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_TXFP field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP(v)   (HW_PCIE_PHY_TX_TX_ATB_REG_WR((HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~BM_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP) | BF_PCIE_PHY_TX_TX_ATB_REG_ATB_TXFP(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_RXDETREF[5] (RW)
 *
 * Connects Rx detect block reference voltage to atb_s_p and local ground to atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF      (5)      //!< Bit position for PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF.
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF      (0x00000020)  //!< Bit mask for PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF.

//! @brief Get value of PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF from a register value.
#define BG_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF(r)   (((r) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF) >> BP_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF(v)   (((v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_RXDETREF field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF(v)   (HW_PCIE_PHY_TX_TX_ATB_REG_WR((HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~BM_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF) | BF_PCIE_PHY_TX_TX_ATB_REG_ATB_RXDETREF(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_VCM_REP[6] (RW)
 *
 * Connects common mode replica voltage in pmos_bias block to atb_s_p and local ground to atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP      (6)      //!< Bit position for PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP.
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP      (0x00000040)  //!< Bit mask for PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP.

//! @brief Get value of PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP from a register value.
#define BG_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP(r)   (((r) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP) >> BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP(v)   (((v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_VCM_REP field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP(v)   (HW_PCIE_PHY_TX_TX_ATB_REG_WR((HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~BM_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP) | BF_PCIE_PHY_TX_TX_ATB_REG_ATB_VCM_REP(v)))
#endif

/* --- Register HW_PCIE_PHY_TX_TX_ATB_REG, field ATB_PBIAS[7] (RW)
 *
 * Connects real pmos_bias voltage for Tx PMOS driver pull-up path to atb_s_p and local ground at
 * the pmos_bias block to atb_s_m.
 */

#define BP_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS      (7)      //!< Bit position for PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS.
#define BM_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS      (0x00000080)  //!< Bit mask for PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS.

//! @brief Get value of PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS from a register value.
#define BG_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS(r)   (((r) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS) >> BP_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS(v)   ((((reg16_t) v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS)
#else
//! @brief Format value for bitfield PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS.
#define BF_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS(v)   (((v) << BP_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS) & BM_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_PBIAS field to a new value.
#define BW_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS(v)   (HW_PCIE_PHY_TX_TX_ATB_REG_WR((HW_PCIE_PHY_TX_TX_ATB_REG_RD() & ~BM_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS) | BF_PCIE_PHY_TX_TX_ATB_REG_ATB_PBIAS(v)))
#endif


/*!
 * @brief All PCIE_PHY module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_pcie_phy
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
    volatile hw_pcie_phy_scope_mask_000_t SCOPE_MASK_000; //!< 
    volatile hw_pcie_phy_scope_mask_001_t SCOPE_MASK_001; //!< 
    volatile hw_pcie_phy_scope_mask_010_t SCOPE_MASK_010; //!< 
    volatile hw_pcie_phy_scope_mask_011_t SCOPE_MASK_011; //!< 
    volatile hw_pcie_phy_scope_mask_100_t SCOPE_MASK_100; //!< 
    volatile hw_pcie_phy_scope_mask_101_t SCOPE_MASK_101; //!< 
    volatile hw_pcie_phy_scope_mask_110_t SCOPE_MASK_110; //!< 
    volatile hw_pcie_phy_scope_mask_111_t SCOPE_MASK_111; //!< 
    volatile hw_pcie_phy_mpll_loop_ctl_t MPLL_LOOP_CTL; //!< 
    volatile hw_pcie_phy_mpll_atb_meas1_t MPLL_ATB_MEAS1; //!< 
    volatile hw_pcie_phy_mpll_atb_meas2_t MPLL_ATB_MEAS2; //!< 
    volatile hw_pcie_phy_mpll_ovr_t MPLL_OVR; //!< 
    volatile hw_pcie_phy_rtune_rtune_ctrl_t RTUNE_RTUNE_CTRL; //!< 
    volatile hw_pcie_phy_atb_switchyard_ctrl_t ATB_SWITCHYARD_CTRL; //!< 
    reg32_t _reserved1[1005];
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
} hw_pcie_phy_t;
#pragma pack()

//! @brief Macro to access all PCIE_PHY registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PCIE_PHY(0)</code>.
#define HW_PCIE_PHY     (*(volatile hw_pcie_phy_t *) REGS_PCIE_PHY_BASE)

#endif


#endif // __HW_PCIE_PHY_REGISTERS_H__
