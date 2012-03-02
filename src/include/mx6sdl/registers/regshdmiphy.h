/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _HDMI_PHY_H
#define _HDMI_PHY_H

#include "regs.h"

/*
 * i.MX6SDL HDMI_PHY registers defined in this header file.
 *
 * - HW_HDMI_PHY_PWRCTRL - Power Control
 * - HW_HDMI_PHY_SERDIVCTRL - Serializer Divider Control
 * - HW_HDMI_PHY_SERCKCTRL - Serializer Clock Control
 * - HW_HDMI_PHY_SERCKKILLCTRL - Serializer Clock Kill Control
 * - HW_HDMI_PHY_TXRESCTRL - Transmitter and Resistance Calibration Control
 * - HW_HDMI_PHY_CKCALCTRL - Clock Calibration Control
 * - HW_HDMI_PHY_CPCE_CTRL - Color Depth, Pixel Repetition, Clock Divider for PLL and MPLL, and Edge Rate Control
 * - HW_HDMI_PHY_TXCLKMEASCTRL - Tx and Clock Measure Control
 * - HW_HDMI_PHY_TXMEASCTRL - Tx Measure Control
 * - HW_HDMI_PHY_CKSYMTXCTRL - Clock Symbol and Transmitter Control
 * - HW_HDMI_PHY_CMPSEQCTRL - Comparator Sequence Control
 * - HW_HDMI_PHY_CMPPWRCTRL - Comparator Power Control
 * - HW_HDMI_PHY_CMPMODECTRL - Comparator Mode Control
 * - HW_HDMI_PHY_MEASCTRL - Measure Control
 * - HW_HDMI_PHY_VLEVCTRL - Voltage Level Control
 * - HW_HDMI_PHY_D2ACTRL - Digital-to-Analog Control
 * - HW_HDMI_PHY_CURRCTRL - Current Control
 * - HW_HDMI_PHY_DRVANACTRL - Drive Analog Control
 * - HW_HDMI_PHY_PLLMEASCTRL - PLL Measure Control
 * - HW_HDMI_PHY_PLLPHBYCTRL - PLL Phase and Bypass Control
 * - HW_HDMI_PHY_GRP_CTRL - Gear Shift, Reset Mode, and Power State Control
 * - HW_HDMI_PHY_GMPCTRL - Gmp Control
 * - HW_HDMI_PHY_MPLLMEASCTRL - MPLL Measure Control
 * - HW_HDMI_PHY_MSM_CTRL - MPLL and PLL Phase, Scope Clock Select, and MUX Clock Control
 * - HW_HDMI_PHY_SCRPB_STATUS - Scope, Comparator Result and Power Bad Status
 * - HW_HDMI_PHY_TXTERM - Transmission Termination
 * - HW_HDMI_PHY_PTRPT_ENBL - Power Sequence, TX Clock Alignment, Resistance Calibration, Pattern Generator Skip Bit, and TMDS Encoder Enable
 * - HW_HDMI_PHY_PATTERNGEN - Pattern Generator Mode
 * - HW_HDMI_PHY_SDCAP_MODE - The Soft-Reset and DAC Enable, Clock Alignment and PG Mode
 * - HW_HDMI_PHY_SCOPEMODE - Scope Mode register
 * - HW_HDMI_PHY_DIGTXMODE - Digital Transmission Mode
 * - HW_HDMI_PHY_STR_STATUS - Scope, Transmission Clock Alignment, and Resistance Calibration Set-on-Done Status
 * - HW_HDMI_PHY_SCOPECNT0 - Scope Counter on Channel 0
 * - HW_HDMI_PHY_SCOPECNT1 - Scope Counter on Channel 1
 * - HW_HDMI_PHY_SCOPECNT2 - Scope Counter on Channel 2
 * - HW_HDMI_PHY_SCOPECNTCLK - Scope Counter on Clock Channel
 * - HW_HDMI_PHY_SCOPESAMPLE - Scope Sample Count MSB, Scope Sample Repetition
 * - HW_HDMI_PHY_SCOPECNTMSB01 - Scope Counter MSB Channel 0 and Channel 1
 * - HW_HDMI_PHY_SCOPECNTMSB2CK - Scope Counter MSB Channel 2 and Clock Channel
 *
 * hw_hdmi_phy_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_HDMI_PHY_BASE
#define REGS_HDMI_PHY_BASE (0x00000000) //!< Base address for HDMI_PHY.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_PWRCTRL - Power Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : PWRCTRL  Access type : Read/write/override  Address : 0x00  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_pwrctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_pwrctrl_bitfields
    {
        unsigned short CK_PWRON : 1; //!< [0] Clock Power-On This bit powers on or powers off the clock driver.
        unsigned short TX_PWRON2 : 1; //!< [1] Transmitter Power-On 2 This bit powers on or powers off the transmitter driver for channel 2.
        unsigned short TX_PWRON1 : 1; //!< [2] Transmitter Power-On 1 This bit powers on or powers off the transmitter driver for channel 1.
        unsigned short TX_PWRON0 : 1; //!< [3] Transmitter Power-On 0 This bit powers on or powers off the transmitter driver for channel 0.
        unsigned short TX_PWRON : 1; //!< [4] Transmitter Power-On This bit enables users to power down the entire PHY through the I2C interface.
        unsigned short RESERVED0 : 10; //!< [14:5] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_pwrctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PWRCTRL register
 */
#define HW_HDMI_PHY_PWRCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PWRCTRL           (*(volatile hw_hdmi_phy_pwrctrl_t *) HW_HDMI_PHY_PWRCTRL_ADDR)
#define HW_HDMI_PHY_PWRCTRL_RD()      (HW_HDMI_PHY_PWRCTRL.U)
#define HW_HDMI_PHY_PWRCTRL_WR(v)     (HW_HDMI_PHY_PWRCTRL.U = (v))
#define HW_HDMI_PHY_PWRCTRL_SET(v)    (HW_HDMI_PHY_PWRCTRL_WR(HW_HDMI_PHY_PWRCTRL_RD() |  (v)))
#define HW_HDMI_PHY_PWRCTRL_CLR(v)    (HW_HDMI_PHY_PWRCTRL_WR(HW_HDMI_PHY_PWRCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_PWRCTRL_TOG(v)    (HW_HDMI_PHY_PWRCTRL_WR(HW_HDMI_PHY_PWRCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_PWRCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_PWRCTRL, field CK_PWRON[0] (RW)
 *
 * Clock Power-On This bit powers on or powers off the clock driver.
 *
 * Values:
 * 0 - Power off the clock driver, if the Override bit is 0.
 * 1 - Power on the clock driver, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PWRCTRL_CK_PWRON      (0)      //!< Bit position for HDMI_PHY_PWRCTRL_CK_PWRON.
#define BM_HDMI_PHY_PWRCTRL_CK_PWRON      (0x00000001)  //!< Bit mask for HDMI_PHY_PWRCTRL_CK_PWRON.

//! @brief Get value of HDMI_PHY_PWRCTRL_CK_PWRON from a register value.
#define BG_HDMI_PHY_PWRCTRL_CK_PWRON(r)   (((r) & BM_HDMI_PHY_PWRCTRL_CK_PWRON) >> BP_HDMI_PHY_PWRCTRL_CK_PWRON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_CK_PWRON.
#define BF_HDMI_PHY_PWRCTRL_CK_PWRON(v)   ((((reg16_t) v) << BP_HDMI_PHY_PWRCTRL_CK_PWRON) & BM_HDMI_PHY_PWRCTRL_CK_PWRON)
#else
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_CK_PWRON.
#define BF_HDMI_PHY_PWRCTRL_CK_PWRON(v)   (((v) << BP_HDMI_PHY_PWRCTRL_CK_PWRON) & BM_HDMI_PHY_PWRCTRL_CK_PWRON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CK_PWRON field to a new value.
#define BW_HDMI_PHY_PWRCTRL_CK_PWRON(v)   (HW_HDMI_PHY_PWRCTRL_WR((HW_HDMI_PHY_PWRCTRL_RD() & ~BM_HDMI_PHY_PWRCTRL_CK_PWRON) | BF_HDMI_PHY_PWRCTRL_CK_PWRON(v)))
#endif


/* --- Register HW_HDMI_PHY_PWRCTRL, field TX_PWRON2[1] (RW)
 *
 * Transmitter Power-On 2 This bit powers on or powers off the transmitter driver for channel 2.
 *
 * Values:
 * 0 - Power off the transmitter driver for the third channel, if the Override bit is 0.
 * 1 - Power on the transmitter driver for the third channel, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PWRCTRL_TX_PWRON2      (1)      //!< Bit position for HDMI_PHY_PWRCTRL_TX_PWRON2.
#define BM_HDMI_PHY_PWRCTRL_TX_PWRON2      (0x00000002)  //!< Bit mask for HDMI_PHY_PWRCTRL_TX_PWRON2.

//! @brief Get value of HDMI_PHY_PWRCTRL_TX_PWRON2 from a register value.
#define BG_HDMI_PHY_PWRCTRL_TX_PWRON2(r)   (((r) & BM_HDMI_PHY_PWRCTRL_TX_PWRON2) >> BP_HDMI_PHY_PWRCTRL_TX_PWRON2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_TX_PWRON2.
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON2(v)   ((((reg16_t) v) << BP_HDMI_PHY_PWRCTRL_TX_PWRON2) & BM_HDMI_PHY_PWRCTRL_TX_PWRON2)
#else
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_TX_PWRON2.
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON2(v)   (((v) << BP_HDMI_PHY_PWRCTRL_TX_PWRON2) & BM_HDMI_PHY_PWRCTRL_TX_PWRON2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_PWRON2 field to a new value.
#define BW_HDMI_PHY_PWRCTRL_TX_PWRON2(v)   (HW_HDMI_PHY_PWRCTRL_WR((HW_HDMI_PHY_PWRCTRL_RD() & ~BM_HDMI_PHY_PWRCTRL_TX_PWRON2) | BF_HDMI_PHY_PWRCTRL_TX_PWRON2(v)))
#endif


/* --- Register HW_HDMI_PHY_PWRCTRL, field TX_PWRON1[2] (RW)
 *
 * Transmitter Power-On 1 This bit powers on or powers off the transmitter driver for channel 1.
 *
 * Values:
 * 0 - Power off the transmitter driver for the second channel, if the Override bit is 0.
 * 1 - Power on the transmitter driver for the second channel, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PWRCTRL_TX_PWRON1      (2)      //!< Bit position for HDMI_PHY_PWRCTRL_TX_PWRON1.
#define BM_HDMI_PHY_PWRCTRL_TX_PWRON1      (0x00000004)  //!< Bit mask for HDMI_PHY_PWRCTRL_TX_PWRON1.

//! @brief Get value of HDMI_PHY_PWRCTRL_TX_PWRON1 from a register value.
#define BG_HDMI_PHY_PWRCTRL_TX_PWRON1(r)   (((r) & BM_HDMI_PHY_PWRCTRL_TX_PWRON1) >> BP_HDMI_PHY_PWRCTRL_TX_PWRON1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_TX_PWRON1.
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON1(v)   ((((reg16_t) v) << BP_HDMI_PHY_PWRCTRL_TX_PWRON1) & BM_HDMI_PHY_PWRCTRL_TX_PWRON1)
#else
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_TX_PWRON1.
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON1(v)   (((v) << BP_HDMI_PHY_PWRCTRL_TX_PWRON1) & BM_HDMI_PHY_PWRCTRL_TX_PWRON1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_PWRON1 field to a new value.
#define BW_HDMI_PHY_PWRCTRL_TX_PWRON1(v)   (HW_HDMI_PHY_PWRCTRL_WR((HW_HDMI_PHY_PWRCTRL_RD() & ~BM_HDMI_PHY_PWRCTRL_TX_PWRON1) | BF_HDMI_PHY_PWRCTRL_TX_PWRON1(v)))
#endif


/* --- Register HW_HDMI_PHY_PWRCTRL, field TX_PWRON0[3] (RW)
 *
 * Transmitter Power-On 0 This bit powers on or powers off the transmitter driver for channel 0.
 *
 * Values:
 * 0 - Power off the transmitter driver for the first channel, if the Override bit is 0.
 * 1 - Power on the transmitter driver for the first channel, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PWRCTRL_TX_PWRON0      (3)      //!< Bit position for HDMI_PHY_PWRCTRL_TX_PWRON0.
#define BM_HDMI_PHY_PWRCTRL_TX_PWRON0      (0x00000008)  //!< Bit mask for HDMI_PHY_PWRCTRL_TX_PWRON0.

//! @brief Get value of HDMI_PHY_PWRCTRL_TX_PWRON0 from a register value.
#define BG_HDMI_PHY_PWRCTRL_TX_PWRON0(r)   (((r) & BM_HDMI_PHY_PWRCTRL_TX_PWRON0) >> BP_HDMI_PHY_PWRCTRL_TX_PWRON0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_TX_PWRON0.
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON0(v)   ((((reg16_t) v) << BP_HDMI_PHY_PWRCTRL_TX_PWRON0) & BM_HDMI_PHY_PWRCTRL_TX_PWRON0)
#else
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_TX_PWRON0.
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON0(v)   (((v) << BP_HDMI_PHY_PWRCTRL_TX_PWRON0) & BM_HDMI_PHY_PWRCTRL_TX_PWRON0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_PWRON0 field to a new value.
#define BW_HDMI_PHY_PWRCTRL_TX_PWRON0(v)   (HW_HDMI_PHY_PWRCTRL_WR((HW_HDMI_PHY_PWRCTRL_RD() & ~BM_HDMI_PHY_PWRCTRL_TX_PWRON0) | BF_HDMI_PHY_PWRCTRL_TX_PWRON0(v)))
#endif


/* --- Register HW_HDMI_PHY_PWRCTRL, field TX_PWRON[4] (RW)
 *
 * Transmitter Power-On This bit enables users to power down the entire PHY through the I2C
 * interface.
 *
 * Values:
 * 0 - Power off the PHY, if the Override bit is 1.
 * 1 - Power on the PHY, if the Override bit is 1.
 */

#define BP_HDMI_PHY_PWRCTRL_TX_PWRON      (4)      //!< Bit position for HDMI_PHY_PWRCTRL_TX_PWRON.
#define BM_HDMI_PHY_PWRCTRL_TX_PWRON      (0x00000010)  //!< Bit mask for HDMI_PHY_PWRCTRL_TX_PWRON.

//! @brief Get value of HDMI_PHY_PWRCTRL_TX_PWRON from a register value.
#define BG_HDMI_PHY_PWRCTRL_TX_PWRON(r)   (((r) & BM_HDMI_PHY_PWRCTRL_TX_PWRON) >> BP_HDMI_PHY_PWRCTRL_TX_PWRON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_TX_PWRON.
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON(v)   ((((reg16_t) v) << BP_HDMI_PHY_PWRCTRL_TX_PWRON) & BM_HDMI_PHY_PWRCTRL_TX_PWRON)
#else
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_TX_PWRON.
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON(v)   (((v) << BP_HDMI_PHY_PWRCTRL_TX_PWRON) & BM_HDMI_PHY_PWRCTRL_TX_PWRON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_PWRON field to a new value.
#define BW_HDMI_PHY_PWRCTRL_TX_PWRON(v)   (HW_HDMI_PHY_PWRCTRL_WR((HW_HDMI_PHY_PWRCTRL_RD() & ~BM_HDMI_PHY_PWRCTRL_TX_PWRON) | BF_HDMI_PHY_PWRCTRL_TX_PWRON(v)))
#endif


/* --- Register HW_HDMI_PHY_PWRCTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_PWRCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_PWRCTRL_OVERRIDE.
#define BM_HDMI_PHY_PWRCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_PWRCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_PWRCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_PWRCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_PWRCTRL_OVERRIDE) >> BP_HDMI_PHY_PWRCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_OVERRIDE.
#define BF_HDMI_PHY_PWRCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_PWRCTRL_OVERRIDE) & BM_HDMI_PHY_PWRCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_PWRCTRL_OVERRIDE.
#define BF_HDMI_PHY_PWRCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_PWRCTRL_OVERRIDE) & BM_HDMI_PHY_PWRCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_PWRCTRL_OVERRIDE(v)   (HW_HDMI_PHY_PWRCTRL_WR((HW_HDMI_PHY_PWRCTRL_RD() & ~BM_HDMI_PHY_PWRCTRL_OVERRIDE) | BF_HDMI_PHY_PWRCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SERDIVCTRL - Serializer Divider Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : SERDIVCTRL  Access type : Read/write/override  Address : 0x01  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_serdivctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_serdivctrl_bitfields
    {
        unsigned short TX_SER_DIV_EN2 : 1; //!< [0] Transmitter Serializer Divider Enable 2 This bit enables or disables the low-speed clock in serializer 2.
        unsigned short TX_SER_DIV_EN1 : 1; //!< [1] Transmitter Serializer Divider Enable 1 This bit enables or disables the low-speed clock in serializer 1.
        unsigned short TX_SER_DIV_EN0 : 1; //!< [2] Transmitter Serializer Divider Enable 0 This bit enables or disables the low-speed clock in serializer 0.
        unsigned short RESERVED0 : 12; //!< [14:3] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_serdivctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SERDIVCTRL register
 */
#define HW_HDMI_PHY_SERDIVCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SERDIVCTRL           (*(volatile hw_hdmi_phy_serdivctrl_t *) HW_HDMI_PHY_SERDIVCTRL_ADDR)
#define HW_HDMI_PHY_SERDIVCTRL_RD()      (HW_HDMI_PHY_SERDIVCTRL.U)
#define HW_HDMI_PHY_SERDIVCTRL_WR(v)     (HW_HDMI_PHY_SERDIVCTRL.U = (v))
#define HW_HDMI_PHY_SERDIVCTRL_SET(v)    (HW_HDMI_PHY_SERDIVCTRL_WR(HW_HDMI_PHY_SERDIVCTRL_RD() |  (v)))
#define HW_HDMI_PHY_SERDIVCTRL_CLR(v)    (HW_HDMI_PHY_SERDIVCTRL_WR(HW_HDMI_PHY_SERDIVCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_SERDIVCTRL_TOG(v)    (HW_HDMI_PHY_SERDIVCTRL_WR(HW_HDMI_PHY_SERDIVCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_SERDIVCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_SERDIVCTRL, field TX_SER_DIV_EN2[0] (RW)
 *
 * Transmitter Serializer Divider Enable 2 This bit enables or disables the low-speed clock in
 * serializer 2.
 *
 * Values:
 * 0 - Disable the low-speed clock in the third serializer, if the Override bit is 0.
 * 1 - Enable the low-speed clock in the third serializer, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2      (0)      //!< Bit position for HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2.
#define BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2      (0x00000001)  //!< Bit mask for HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2.

//! @brief Get value of HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2 from a register value.
#define BG_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2(r)   (((r) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2) >> BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2.
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2)
#else
//! @brief Format value for bitfield HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2.
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2(v)   (((v) << BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_DIV_EN2 field to a new value.
#define BW_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2(v)   (HW_HDMI_PHY_SERDIVCTRL_WR((HW_HDMI_PHY_SERDIVCTRL_RD() & ~BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2) | BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2(v)))
#endif


/* --- Register HW_HDMI_PHY_SERDIVCTRL, field TX_SER_DIV_EN1[1] (RW)
 *
 * Transmitter Serializer Divider Enable 1 This bit enables or disables the low-speed clock in
 * serializer 1.
 *
 * Values:
 * 0 - Disable the low-speed clock in the second serializer, if the Override bit is 0.
 * 1 - Enable the low-speed clock in the second serializer, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1      (1)      //!< Bit position for HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1.
#define BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1      (0x00000002)  //!< Bit mask for HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1.

//! @brief Get value of HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1 from a register value.
#define BG_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1(r)   (((r) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1) >> BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1.
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1)
#else
//! @brief Format value for bitfield HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1.
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1(v)   (((v) << BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_DIV_EN1 field to a new value.
#define BW_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1(v)   (HW_HDMI_PHY_SERDIVCTRL_WR((HW_HDMI_PHY_SERDIVCTRL_RD() & ~BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1) | BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1(v)))
#endif


/* --- Register HW_HDMI_PHY_SERDIVCTRL, field TX_SER_DIV_EN0[2] (RW)
 *
 * Transmitter Serializer Divider Enable 0 This bit enables or disables the low-speed clock in
 * serializer 0.
 *
 * Values:
 * 0 - Disable the low-speed clock in the first serializer, if the Override bit is 0.
 * 1 - Enable the low-speed clock in the first serializer, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0      (2)      //!< Bit position for HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0.
#define BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0      (0x00000004)  //!< Bit mask for HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0.

//! @brief Get value of HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0 from a register value.
#define BG_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0(r)   (((r) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0) >> BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0.
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0)
#else
//! @brief Format value for bitfield HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0.
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0(v)   (((v) << BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_DIV_EN0 field to a new value.
#define BW_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0(v)   (HW_HDMI_PHY_SERDIVCTRL_WR((HW_HDMI_PHY_SERDIVCTRL_RD() & ~BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0) | BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0(v)))
#endif


/* --- Register HW_HDMI_PHY_SERDIVCTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_SERDIVCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_SERDIVCTRL_OVERRIDE.
#define BM_HDMI_PHY_SERDIVCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_SERDIVCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_SERDIVCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_SERDIVCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_SERDIVCTRL_OVERRIDE) >> BP_HDMI_PHY_SERDIVCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERDIVCTRL_OVERRIDE.
#define BF_HDMI_PHY_SERDIVCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERDIVCTRL_OVERRIDE) & BM_HDMI_PHY_SERDIVCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_SERDIVCTRL_OVERRIDE.
#define BF_HDMI_PHY_SERDIVCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_SERDIVCTRL_OVERRIDE) & BM_HDMI_PHY_SERDIVCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_SERDIVCTRL_OVERRIDE(v)   (HW_HDMI_PHY_SERDIVCTRL_WR((HW_HDMI_PHY_SERDIVCTRL_RD() & ~BM_HDMI_PHY_SERDIVCTRL_OVERRIDE) | BF_HDMI_PHY_SERDIVCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SERCKCTRL - Serializer Clock Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : SERCKCTRL  Access type : Read/write/override  Address : 0x02  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_serckctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_serckctrl_bitfields
    {
        unsigned short TX_SER_CLK_EN2 : 1; //!< [0] Transmitter Serializer Clock Enable 2 This bit enables or disables the high-speed clock in serializer two.
        unsigned short TX_SER_CLK_EN1 : 1; //!< [1] Transmitter Serializer Clock Enable 1 This bit enables or disables the high-speed clock in serializer 1.
        unsigned short TX_SER_CLK_EN0 : 1; //!< [2] Transmitter Serializer Clock Enable 0 This bit enables or disables the high-speed clock in serializer 0.
        unsigned short RESERVED0 : 12; //!< [14:3] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_serckctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SERCKCTRL register
 */
#define HW_HDMI_PHY_SERCKCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SERCKCTRL           (*(volatile hw_hdmi_phy_serckctrl_t *) HW_HDMI_PHY_SERCKCTRL_ADDR)
#define HW_HDMI_PHY_SERCKCTRL_RD()      (HW_HDMI_PHY_SERCKCTRL.U)
#define HW_HDMI_PHY_SERCKCTRL_WR(v)     (HW_HDMI_PHY_SERCKCTRL.U = (v))
#define HW_HDMI_PHY_SERCKCTRL_SET(v)    (HW_HDMI_PHY_SERCKCTRL_WR(HW_HDMI_PHY_SERCKCTRL_RD() |  (v)))
#define HW_HDMI_PHY_SERCKCTRL_CLR(v)    (HW_HDMI_PHY_SERCKCTRL_WR(HW_HDMI_PHY_SERCKCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_SERCKCTRL_TOG(v)    (HW_HDMI_PHY_SERCKCTRL_WR(HW_HDMI_PHY_SERCKCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_SERCKCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_SERCKCTRL, field TX_SER_CLK_EN2[0] (RW)
 *
 * Transmitter Serializer Clock Enable 2 This bit enables or disables the high-speed clock in
 * serializer two.
 *
 * Values:
 * 0 - Disable the high-speed clock in the third serializer, if the Override bit is 0.
 * 1 - Enable the high-speed clock in the third serializer, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2      (0)      //!< Bit position for HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2.
#define BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2      (0x00000001)  //!< Bit mask for HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2.

//! @brief Get value of HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2 from a register value.
#define BG_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2(r)   (((r) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2) >> BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2.
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2)
#else
//! @brief Format value for bitfield HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2.
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2(v)   (((v) << BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_CLK_EN2 field to a new value.
#define BW_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2(v)   (HW_HDMI_PHY_SERCKCTRL_WR((HW_HDMI_PHY_SERCKCTRL_RD() & ~BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2) | BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2(v)))
#endif


/* --- Register HW_HDMI_PHY_SERCKCTRL, field TX_SER_CLK_EN1[1] (RW)
 *
 * Transmitter Serializer Clock Enable 1 This bit enables or disables the high-speed clock in
 * serializer 1.
 *
 * Values:
 * 0 - Disable the high-speed clock in the second serializer, if the Override bit is 0.
 * 1 - Enable the high-speed clock in the second serializer, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1      (1)      //!< Bit position for HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1.
#define BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1      (0x00000002)  //!< Bit mask for HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1.

//! @brief Get value of HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1 from a register value.
#define BG_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1(r)   (((r) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1) >> BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1.
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1)
#else
//! @brief Format value for bitfield HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1.
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1(v)   (((v) << BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_CLK_EN1 field to a new value.
#define BW_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1(v)   (HW_HDMI_PHY_SERCKCTRL_WR((HW_HDMI_PHY_SERCKCTRL_RD() & ~BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1) | BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1(v)))
#endif


/* --- Register HW_HDMI_PHY_SERCKCTRL, field TX_SER_CLK_EN0[2] (RW)
 *
 * Transmitter Serializer Clock Enable 0 This bit enables or disables the high-speed clock in
 * serializer 0.
 *
 * Values:
 * 0 - Disable the high-speed clock in the first serializer, if the Override bit is 0.
 * 1 - Enable the high-speed clock in the first serializer, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0      (2)      //!< Bit position for HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0.
#define BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0      (0x00000004)  //!< Bit mask for HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0.

//! @brief Get value of HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0 from a register value.
#define BG_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0(r)   (((r) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0) >> BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0.
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0)
#else
//! @brief Format value for bitfield HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0.
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0(v)   (((v) << BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_CLK_EN0 field to a new value.
#define BW_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0(v)   (HW_HDMI_PHY_SERCKCTRL_WR((HW_HDMI_PHY_SERCKCTRL_RD() & ~BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0) | BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0(v)))
#endif


/* --- Register HW_HDMI_PHY_SERCKCTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_SERCKCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_SERCKCTRL_OVERRIDE.
#define BM_HDMI_PHY_SERCKCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_SERCKCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_SERCKCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_SERCKCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_SERCKCTRL_OVERRIDE) >> BP_HDMI_PHY_SERCKCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERCKCTRL_OVERRIDE.
#define BF_HDMI_PHY_SERCKCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERCKCTRL_OVERRIDE) & BM_HDMI_PHY_SERCKCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_SERCKCTRL_OVERRIDE.
#define BF_HDMI_PHY_SERCKCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_SERCKCTRL_OVERRIDE) & BM_HDMI_PHY_SERCKCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_SERCKCTRL_OVERRIDE(v)   (HW_HDMI_PHY_SERCKCTRL_WR((HW_HDMI_PHY_SERCKCTRL_RD() & ~BM_HDMI_PHY_SERCKCTRL_OVERRIDE) | BF_HDMI_PHY_SERCKCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SERCKKILLCTRL - Serializer Clock Kill Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : SERCKKILLCTRL  Access type : Read/write/override  Address : 0x03  Value at reset
 * : 0x0000
 */
typedef union _hw_hdmi_phy_serckkillctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_serckkillctrl_bitfields
    {
        unsigned short TX_SER_CLK_KILL2 : 1; //!< [0] Transmitter Serializer Clock Kill 2 This bit is used to delay the tx_ck_out2 sampling clock by a time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of the tx_ck_out2 clock.
        unsigned short TX_SER_CLK_KILL1 : 1; //!< [1] Transmitter Serializer Clock Kill 1 This bit is used to delay the tx_ck_out1 sampling clock by a time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of the tx_ck_out1 clock.
        unsigned short TX_SER_CLK_KILL0 : 1; //!< [2] Transmitter Serializer Clock Kill 0 This bit is used to delay the tx_ck_out0 sampling clock by a time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of the tx_ck_out0 clock.
        unsigned short RESERVED0 : 12; //!< [14:3] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_serckkillctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SERCKKILLCTRL register
 */
#define HW_HDMI_PHY_SERCKKILLCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SERCKKILLCTRL           (*(volatile hw_hdmi_phy_serckkillctrl_t *) HW_HDMI_PHY_SERCKKILLCTRL_ADDR)
#define HW_HDMI_PHY_SERCKKILLCTRL_RD()      (HW_HDMI_PHY_SERCKKILLCTRL.U)
#define HW_HDMI_PHY_SERCKKILLCTRL_WR(v)     (HW_HDMI_PHY_SERCKKILLCTRL.U = (v))
#define HW_HDMI_PHY_SERCKKILLCTRL_SET(v)    (HW_HDMI_PHY_SERCKKILLCTRL_WR(HW_HDMI_PHY_SERCKKILLCTRL_RD() |  (v)))
#define HW_HDMI_PHY_SERCKKILLCTRL_CLR(v)    (HW_HDMI_PHY_SERCKKILLCTRL_WR(HW_HDMI_PHY_SERCKKILLCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_SERCKKILLCTRL_TOG(v)    (HW_HDMI_PHY_SERCKKILLCTRL_WR(HW_HDMI_PHY_SERCKKILLCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_SERCKKILLCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_SERCKKILLCTRL, field TX_SER_CLK_KILL2[0] (RW)
 *
 * Transmitter Serializer Clock Kill 2 This bit is used to delay the tx_ck_out2 sampling clock by a
 * time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of
 * the tx_ck_out2 clock.
 *
 * Values:
 * 0 - No effect, if the Override bit is 0.
 * 1 - Delay the tx_ck_out2 clock by 0.2 UI, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2      (0)      //!< Bit position for HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2.
#define BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2      (0x00000001)  //!< Bit mask for HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2.

//! @brief Get value of HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2 from a register value.
#define BG_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2(r)   (((r) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2) >> BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2.
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2)
#else
//! @brief Format value for bitfield HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2.
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2(v)   (((v) << BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_CLK_KILL2 field to a new value.
#define BW_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2(v)   (HW_HDMI_PHY_SERCKKILLCTRL_WR((HW_HDMI_PHY_SERCKKILLCTRL_RD() & ~BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2) | BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2(v)))
#endif


/* --- Register HW_HDMI_PHY_SERCKKILLCTRL, field TX_SER_CLK_KILL1[1] (RW)
 *
 * Transmitter Serializer Clock Kill 1 This bit is used to delay the tx_ck_out1 sampling clock by a
 * time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of
 * the tx_ck_out1 clock.
 *
 * Values:
 * 0 - No effect, if the Override bit is 0.
 * 1 - Delay the tx_ck_out1 clock by 0.2 UI, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1      (1)      //!< Bit position for HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1.
#define BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1      (0x00000002)  //!< Bit mask for HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1.

//! @brief Get value of HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1 from a register value.
#define BG_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1(r)   (((r) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1) >> BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1.
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1)
#else
//! @brief Format value for bitfield HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1.
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1(v)   (((v) << BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_CLK_KILL1 field to a new value.
#define BW_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1(v)   (HW_HDMI_PHY_SERCKKILLCTRL_WR((HW_HDMI_PHY_SERCKKILLCTRL_RD() & ~BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1) | BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1(v)))
#endif


/* --- Register HW_HDMI_PHY_SERCKKILLCTRL, field TX_SER_CLK_KILL0[2] (RW)
 *
 * Transmitter Serializer Clock Kill 0 This bit is used to delay the tx_ck_out0 sampling clock by a
 * time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of
 * the tx_ck_out0 clock.
 *
 * Values:
 * 0 - No effect, if the Override bit is 0.
 * 1 - Delay the tx_ck_out0 clock by 0.2 UI, if the Override bit is 0.
 */

#define BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0      (2)      //!< Bit position for HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0.
#define BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0      (0x00000004)  //!< Bit mask for HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0.

//! @brief Get value of HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0 from a register value.
#define BG_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0(r)   (((r) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0) >> BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0.
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0)
#else
//! @brief Format value for bitfield HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0.
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0(v)   (((v) << BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SER_CLK_KILL0 field to a new value.
#define BW_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0(v)   (HW_HDMI_PHY_SERCKKILLCTRL_WR((HW_HDMI_PHY_SERCKKILLCTRL_RD() & ~BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0) | BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0(v)))
#endif


/* --- Register HW_HDMI_PHY_SERCKKILLCTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_SERCKKILLCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_SERCKKILLCTRL_OVERRIDE.
#define BM_HDMI_PHY_SERCKKILLCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_SERCKKILLCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_SERCKKILLCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_SERCKKILLCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_SERCKKILLCTRL_OVERRIDE) >> BP_HDMI_PHY_SERCKKILLCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SERCKKILLCTRL_OVERRIDE.
#define BF_HDMI_PHY_SERCKKILLCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_SERCKKILLCTRL_OVERRIDE) & BM_HDMI_PHY_SERCKKILLCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_SERCKKILLCTRL_OVERRIDE.
#define BF_HDMI_PHY_SERCKKILLCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_SERCKKILLCTRL_OVERRIDE) & BM_HDMI_PHY_SERCKKILLCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_SERCKKILLCTRL_OVERRIDE(v)   (HW_HDMI_PHY_SERCKKILLCTRL_WR((HW_HDMI_PHY_SERCKKILLCTRL_RD() & ~BM_HDMI_PHY_SERCKKILLCTRL_OVERRIDE) | BF_HDMI_PHY_SERCKKILLCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_TXRESCTRL - Transmitter and Resistance Calibration Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : TXRESCALCTRL  Access type : Read/write/override  Address : 0x04  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_txresctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_txresctrl_bitfields
    {
        unsigned short RESCAL_REP : 7; //!< [6:0] Resistance Calibration Replica This bus controls the bias voltage of the transmitter driver. rescal_rep[6:0] provides 64 voltage levels; the specific values are defined from lab test results.
        unsigned short TX_RESCAL : 7; //!< [13:7] Transmitter Resistance Calibration This bus controls the parallel termination of the transmitter drivers and sets termination to a value based on the calibration algorithm performed in the support resistance calibration module. tx_rescal[6:0] provides 64 termination levels; the specific values are defined from lab test results.
        unsigned short RESERVED0 : 1; //!< [14] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_txresctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TXRESCTRL register
 */
#define HW_HDMI_PHY_TXRESCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TXRESCTRL           (*(volatile hw_hdmi_phy_txresctrl_t *) HW_HDMI_PHY_TXRESCTRL_ADDR)
#define HW_HDMI_PHY_TXRESCTRL_RD()      (HW_HDMI_PHY_TXRESCTRL.U)
#define HW_HDMI_PHY_TXRESCTRL_WR(v)     (HW_HDMI_PHY_TXRESCTRL.U = (v))
#define HW_HDMI_PHY_TXRESCTRL_SET(v)    (HW_HDMI_PHY_TXRESCTRL_WR(HW_HDMI_PHY_TXRESCTRL_RD() |  (v)))
#define HW_HDMI_PHY_TXRESCTRL_CLR(v)    (HW_HDMI_PHY_TXRESCTRL_WR(HW_HDMI_PHY_TXRESCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_TXRESCTRL_TOG(v)    (HW_HDMI_PHY_TXRESCTRL_WR(HW_HDMI_PHY_TXRESCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_TXRESCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_TXRESCTRL, field RESCAL_REP[6:0] (RW)
 *
 * Resistance Calibration Replica This bus controls the bias voltage of the transmitter driver.
 * rescal_rep[6:0] provides 64 voltage levels; the specific values are defined from lab test
 * results.
 */

#define BP_HDMI_PHY_TXRESCTRL_RESCAL_REP      (0)      //!< Bit position for HDMI_PHY_TXRESCTRL_RESCAL_REP.
#define BM_HDMI_PHY_TXRESCTRL_RESCAL_REP      (0x0000007f)  //!< Bit mask for HDMI_PHY_TXRESCTRL_RESCAL_REP.

//! @brief Get value of HDMI_PHY_TXRESCTRL_RESCAL_REP from a register value.
#define BG_HDMI_PHY_TXRESCTRL_RESCAL_REP(r)   (((r) & BM_HDMI_PHY_TXRESCTRL_RESCAL_REP) >> BP_HDMI_PHY_TXRESCTRL_RESCAL_REP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_TXRESCTRL_RESCAL_REP.
#define BF_HDMI_PHY_TXRESCTRL_RESCAL_REP(v)   ((((reg16_t) v) << BP_HDMI_PHY_TXRESCTRL_RESCAL_REP) & BM_HDMI_PHY_TXRESCTRL_RESCAL_REP)
#else
//! @brief Format value for bitfield HDMI_PHY_TXRESCTRL_RESCAL_REP.
#define BF_HDMI_PHY_TXRESCTRL_RESCAL_REP(v)   (((v) << BP_HDMI_PHY_TXRESCTRL_RESCAL_REP) & BM_HDMI_PHY_TXRESCTRL_RESCAL_REP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RESCAL_REP field to a new value.
#define BW_HDMI_PHY_TXRESCTRL_RESCAL_REP(v)   (HW_HDMI_PHY_TXRESCTRL_WR((HW_HDMI_PHY_TXRESCTRL_RD() & ~BM_HDMI_PHY_TXRESCTRL_RESCAL_REP) | BF_HDMI_PHY_TXRESCTRL_RESCAL_REP(v)))
#endif

/* --- Register HW_HDMI_PHY_TXRESCTRL, field TX_RESCAL[13:7] (RW)
 *
 * Transmitter Resistance Calibration This bus controls the parallel termination of the transmitter
 * drivers and sets termination to a value based on the calibration algorithm performed in the
 * support resistance calibration module. tx_rescal[6:0] provides 64 termination levels; the
 * specific values are defined from lab test results.
 */

#define BP_HDMI_PHY_TXRESCTRL_TX_RESCAL      (7)      //!< Bit position for HDMI_PHY_TXRESCTRL_TX_RESCAL.
#define BM_HDMI_PHY_TXRESCTRL_TX_RESCAL      (0x00003f80)  //!< Bit mask for HDMI_PHY_TXRESCTRL_TX_RESCAL.

//! @brief Get value of HDMI_PHY_TXRESCTRL_TX_RESCAL from a register value.
#define BG_HDMI_PHY_TXRESCTRL_TX_RESCAL(r)   (((r) & BM_HDMI_PHY_TXRESCTRL_TX_RESCAL) >> BP_HDMI_PHY_TXRESCTRL_TX_RESCAL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_TXRESCTRL_TX_RESCAL.
#define BF_HDMI_PHY_TXRESCTRL_TX_RESCAL(v)   ((((reg16_t) v) << BP_HDMI_PHY_TXRESCTRL_TX_RESCAL) & BM_HDMI_PHY_TXRESCTRL_TX_RESCAL)
#else
//! @brief Format value for bitfield HDMI_PHY_TXRESCTRL_TX_RESCAL.
#define BF_HDMI_PHY_TXRESCTRL_TX_RESCAL(v)   (((v) << BP_HDMI_PHY_TXRESCTRL_TX_RESCAL) & BM_HDMI_PHY_TXRESCTRL_TX_RESCAL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_RESCAL field to a new value.
#define BW_HDMI_PHY_TXRESCTRL_TX_RESCAL(v)   (HW_HDMI_PHY_TXRESCTRL_WR((HW_HDMI_PHY_TXRESCTRL_RD() & ~BM_HDMI_PHY_TXRESCTRL_TX_RESCAL) | BF_HDMI_PHY_TXRESCTRL_TX_RESCAL(v)))
#endif

/* --- Register HW_HDMI_PHY_TXRESCTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_TXRESCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_TXRESCTRL_OVERRIDE.
#define BM_HDMI_PHY_TXRESCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_TXRESCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_TXRESCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_TXRESCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_TXRESCTRL_OVERRIDE) >> BP_HDMI_PHY_TXRESCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_TXRESCTRL_OVERRIDE.
#define BF_HDMI_PHY_TXRESCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_TXRESCTRL_OVERRIDE) & BM_HDMI_PHY_TXRESCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_TXRESCTRL_OVERRIDE.
#define BF_HDMI_PHY_TXRESCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_TXRESCTRL_OVERRIDE) & BM_HDMI_PHY_TXRESCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_TXRESCTRL_OVERRIDE(v)   (HW_HDMI_PHY_TXRESCTRL_WR((HW_HDMI_PHY_TXRESCTRL_RD() & ~BM_HDMI_PHY_TXRESCTRL_OVERRIDE) | BF_HDMI_PHY_TXRESCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_CKCALCTRL - Clock Calibration Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : CKCALCTRL  Access type : Read/write/override  Address : 0x05  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_ckcalctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_ckcalctrl_bitfields
    {
        unsigned short CK_RESCAL : 7; //!< [6:0] Clock Resistance Calibration This bus controls the termination of the clock driver and sets the termination to a value based on the calibration algorithm performed in the support resistance calibration module. ck_rescal[6:0] provides 64 termination levels; the specific values are defined from lab test results.
        unsigned short RESERVED0 : 8; //!< [14:7] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_ckcalctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CKCALCTRL register
 */
#define HW_HDMI_PHY_CKCALCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CKCALCTRL           (*(volatile hw_hdmi_phy_ckcalctrl_t *) HW_HDMI_PHY_CKCALCTRL_ADDR)
#define HW_HDMI_PHY_CKCALCTRL_RD()      (HW_HDMI_PHY_CKCALCTRL.U)
#define HW_HDMI_PHY_CKCALCTRL_WR(v)     (HW_HDMI_PHY_CKCALCTRL.U = (v))
#define HW_HDMI_PHY_CKCALCTRL_SET(v)    (HW_HDMI_PHY_CKCALCTRL_WR(HW_HDMI_PHY_CKCALCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CKCALCTRL_CLR(v)    (HW_HDMI_PHY_CKCALCTRL_WR(HW_HDMI_PHY_CKCALCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CKCALCTRL_TOG(v)    (HW_HDMI_PHY_CKCALCTRL_WR(HW_HDMI_PHY_CKCALCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_CKCALCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CKCALCTRL, field CK_RESCAL[6:0] (RW)
 *
 * Clock Resistance Calibration This bus controls the termination of the clock driver and sets the
 * termination to a value based on the calibration algorithm performed in the support resistance
 * calibration module. ck_rescal[6:0] provides 64 termination levels; the specific values are
 * defined from lab test results.
 */

#define BP_HDMI_PHY_CKCALCTRL_CK_RESCAL      (0)      //!< Bit position for HDMI_PHY_CKCALCTRL_CK_RESCAL.
#define BM_HDMI_PHY_CKCALCTRL_CK_RESCAL      (0x0000007f)  //!< Bit mask for HDMI_PHY_CKCALCTRL_CK_RESCAL.

//! @brief Get value of HDMI_PHY_CKCALCTRL_CK_RESCAL from a register value.
#define BG_HDMI_PHY_CKCALCTRL_CK_RESCAL(r)   (((r) & BM_HDMI_PHY_CKCALCTRL_CK_RESCAL) >> BP_HDMI_PHY_CKCALCTRL_CK_RESCAL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CKCALCTRL_CK_RESCAL.
#define BF_HDMI_PHY_CKCALCTRL_CK_RESCAL(v)   ((((reg16_t) v) << BP_HDMI_PHY_CKCALCTRL_CK_RESCAL) & BM_HDMI_PHY_CKCALCTRL_CK_RESCAL)
#else
//! @brief Format value for bitfield HDMI_PHY_CKCALCTRL_CK_RESCAL.
#define BF_HDMI_PHY_CKCALCTRL_CK_RESCAL(v)   (((v) << BP_HDMI_PHY_CKCALCTRL_CK_RESCAL) & BM_HDMI_PHY_CKCALCTRL_CK_RESCAL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CK_RESCAL field to a new value.
#define BW_HDMI_PHY_CKCALCTRL_CK_RESCAL(v)   (HW_HDMI_PHY_CKCALCTRL_WR((HW_HDMI_PHY_CKCALCTRL_RD() & ~BM_HDMI_PHY_CKCALCTRL_CK_RESCAL) | BF_HDMI_PHY_CKCALCTRL_CK_RESCAL(v)))
#endif

/* --- Register HW_HDMI_PHY_CKCALCTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_CKCALCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_CKCALCTRL_OVERRIDE.
#define BM_HDMI_PHY_CKCALCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_CKCALCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_CKCALCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_CKCALCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_CKCALCTRL_OVERRIDE) >> BP_HDMI_PHY_CKCALCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CKCALCTRL_OVERRIDE.
#define BF_HDMI_PHY_CKCALCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_CKCALCTRL_OVERRIDE) & BM_HDMI_PHY_CKCALCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_CKCALCTRL_OVERRIDE.
#define BF_HDMI_PHY_CKCALCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_CKCALCTRL_OVERRIDE) & BM_HDMI_PHY_CKCALCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_CKCALCTRL_OVERRIDE(v)   (HW_HDMI_PHY_CKCALCTRL_WR((HW_HDMI_PHY_CKCALCTRL_RD() & ~BM_HDMI_PHY_CKCALCTRL_OVERRIDE) | BF_HDMI_PHY_CKCALCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_CPCE_CTRL - Color Depth, Pixel Repetition, Clock Divider for PLL and MPLL, and Edge Rate Control (RW)
 *
 * Reset value: 0x00000400
 *
 * Register name : -  Access type : Read/write  Address : 0x06  Value at reset : 0x0400
 */
typedef union _hw_hdmi_phy_cpce_ctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_cpce_ctrl_bitfields
    {
        unsigned short CLR_DPTH : 2; //!< [1:0] Color Depth This bus controls the factor by which to divide the reference clock (PCLK) by the output TMDS rate (ck_ref_mpll_p/m).
        unsigned short PIXEL_REP : 3; //!< [4:2] Pixel Repetition This bus controls another factor by which to divide the input frequency (refclk) by the output TMDS rate (ck_ref_mpll_p/m). FTMDS/Fin = (clr_depth[1:0] x pixel_rep[2]) / (pixel_rep[1:0])
        unsigned short PLL_N_CNTRL : 2; //!< [6:5] Programmable Divider Control This bus controls the programmable divider modules, which are set based on the refclk_p/m (pixel rate) input reference frequency to keep the ring oscillator within the required range (740 MHz through 1.48 GHz in PLL).
        unsigned short MPLL_N_CNTRL : 2; //!< [8:7] Programmable Divider Control This bus controls the programmable divider modulus, which are set based on the ck_ref_mpll_p/m (TMDS rate) input reference frequency to keep the ring oscillator within the required range (925 MHz through 1.85 GHz in MPLL).
        unsigned short CK_EDGERATE : 2; //!< [10:9] Clock Edge Rate This bus controls the slew rate of the clock output driver.
        unsigned short TX_EDGERATE : 2; //!< [12:11] Transmitter Edge Rate This bus controls the slew rate of the transmitter output driver.
        unsigned short PREP_DIV : 2; //!< [14:13] Digital Pixel Repetition Divider Controls the ratio by which the internal TMDS clock is divided to generate PREPCLK.
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_hdmi_phy_cpce_ctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CPCE_CTRL register
 */
#define HW_HDMI_PHY_CPCE_CTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CPCE_CTRL           (*(volatile hw_hdmi_phy_cpce_ctrl_t *) HW_HDMI_PHY_CPCE_CTRL_ADDR)
#define HW_HDMI_PHY_CPCE_CTRL_RD()      (HW_HDMI_PHY_CPCE_CTRL.U)
#define HW_HDMI_PHY_CPCE_CTRL_WR(v)     (HW_HDMI_PHY_CPCE_CTRL.U = (v))
#define HW_HDMI_PHY_CPCE_CTRL_SET(v)    (HW_HDMI_PHY_CPCE_CTRL_WR(HW_HDMI_PHY_CPCE_CTRL_RD() |  (v)))
#define HW_HDMI_PHY_CPCE_CTRL_CLR(v)    (HW_HDMI_PHY_CPCE_CTRL_WR(HW_HDMI_PHY_CPCE_CTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CPCE_CTRL_TOG(v)    (HW_HDMI_PHY_CPCE_CTRL_WR(HW_HDMI_PHY_CPCE_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_CPCE_CTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CPCE_CTRL, field CLR_DPTH[1:0] (RW)
 *
 * Color Depth This bus controls the factor by which to divide the reference clock (PCLK) by the
 * output TMDS rate (ck_ref_mpll_p/m).
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 5.
 * 10 - Divide by 6.
 * 11 - Divide by 8.
 */

#define BP_HDMI_PHY_CPCE_CTRL_CLR_DPTH      (0)      //!< Bit position for HDMI_PHY_CPCE_CTRL_CLR_DPTH.
#define BM_HDMI_PHY_CPCE_CTRL_CLR_DPTH      (0x00000003)  //!< Bit mask for HDMI_PHY_CPCE_CTRL_CLR_DPTH.

//! @brief Get value of HDMI_PHY_CPCE_CTRL_CLR_DPTH from a register value.
#define BG_HDMI_PHY_CPCE_CTRL_CLR_DPTH(r)   (((r) & BM_HDMI_PHY_CPCE_CTRL_CLR_DPTH) >> BP_HDMI_PHY_CPCE_CTRL_CLR_DPTH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_CLR_DPTH.
#define BF_HDMI_PHY_CPCE_CTRL_CLR_DPTH(v)   ((((reg16_t) v) << BP_HDMI_PHY_CPCE_CTRL_CLR_DPTH) & BM_HDMI_PHY_CPCE_CTRL_CLR_DPTH)
#else
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_CLR_DPTH.
#define BF_HDMI_PHY_CPCE_CTRL_CLR_DPTH(v)   (((v) << BP_HDMI_PHY_CPCE_CTRL_CLR_DPTH) & BM_HDMI_PHY_CPCE_CTRL_CLR_DPTH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_DPTH field to a new value.
#define BW_HDMI_PHY_CPCE_CTRL_CLR_DPTH(v)   (HW_HDMI_PHY_CPCE_CTRL_WR((HW_HDMI_PHY_CPCE_CTRL_RD() & ~BM_HDMI_PHY_CPCE_CTRL_CLR_DPTH) | BF_HDMI_PHY_CPCE_CTRL_CLR_DPTH(v)))
#endif


/* --- Register HW_HDMI_PHY_CPCE_CTRL, field PIXEL_REP[4:2] (RW)
 *
 * Pixel Repetition This bus controls another factor by which to divide the input frequency (refclk)
 * by the output TMDS rate (ck_ref_mpll_p/m). FTMDS/Fin = (clr_depth[1:0] x pixel_rep[2]) /
 * (pixel_rep[1:0])
 *
 * Values:
 * 0 - Pixel_rep[2] Divide by 1.
 * 00 - Pixel_rep[1:0] Divide by 4.
 * 1 - Pixel_rep[2] Divide by 2.
 * 01 - Pixel_rep[1:0] Divide by 2.
 * 1x - Pixel_rep[1:0] Divide by 1.
 */

#define BP_HDMI_PHY_CPCE_CTRL_PIXEL_REP      (2)      //!< Bit position for HDMI_PHY_CPCE_CTRL_PIXEL_REP.
#define BM_HDMI_PHY_CPCE_CTRL_PIXEL_REP      (0x0000001c)  //!< Bit mask for HDMI_PHY_CPCE_CTRL_PIXEL_REP.

//! @brief Get value of HDMI_PHY_CPCE_CTRL_PIXEL_REP from a register value.
#define BG_HDMI_PHY_CPCE_CTRL_PIXEL_REP(r)   (((r) & BM_HDMI_PHY_CPCE_CTRL_PIXEL_REP) >> BP_HDMI_PHY_CPCE_CTRL_PIXEL_REP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_PIXEL_REP.
#define BF_HDMI_PHY_CPCE_CTRL_PIXEL_REP(v)   ((((reg16_t) v) << BP_HDMI_PHY_CPCE_CTRL_PIXEL_REP) & BM_HDMI_PHY_CPCE_CTRL_PIXEL_REP)
#else
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_PIXEL_REP.
#define BF_HDMI_PHY_CPCE_CTRL_PIXEL_REP(v)   (((v) << BP_HDMI_PHY_CPCE_CTRL_PIXEL_REP) & BM_HDMI_PHY_CPCE_CTRL_PIXEL_REP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXEL_REP field to a new value.
#define BW_HDMI_PHY_CPCE_CTRL_PIXEL_REP(v)   (HW_HDMI_PHY_CPCE_CTRL_WR((HW_HDMI_PHY_CPCE_CTRL_RD() & ~BM_HDMI_PHY_CPCE_CTRL_PIXEL_REP) | BF_HDMI_PHY_CPCE_CTRL_PIXEL_REP(v)))
#endif


/* --- Register HW_HDMI_PHY_CPCE_CTRL, field PLL_N_CNTRL[6:5] (RW)
 *
 * Programmable Divider Control This bus controls the programmable divider modules, which are set
 * based on the refclk_p/m (pixel rate) input reference frequency to keep the ring oscillator within
 * the required range (740 MHz through 1.48 GHz in PLL).
 *
 * Values:
 * 00 - N = 1 (for TMDS rate of 184.1-370 MHz)
 * 01 - N = 2 (for TMDS rate of 92.51-185 MHz)
 * 10 - N = 4 (for TMDS rate of 45.26-92.5 MHz)
 * 11 - N = 8 (for TMDS rate (not the pixel rate) up to 45.25 MHz)
 */

#define BP_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL      (5)      //!< Bit position for HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL.
#define BM_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL      (0x00000060)  //!< Bit mask for HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL.

//! @brief Get value of HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL from a register value.
#define BG_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL(r)   (((r) & BM_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL) >> BP_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL.
#define BF_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL(v)   ((((reg16_t) v) << BP_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL) & BM_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL)
#else
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL.
#define BF_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL(v)   (((v) << BP_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL) & BM_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_N_CNTRL field to a new value.
#define BW_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL(v)   (HW_HDMI_PHY_CPCE_CTRL_WR((HW_HDMI_PHY_CPCE_CTRL_RD() & ~BM_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL) | BF_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL(v)))
#endif


/* --- Register HW_HDMI_PHY_CPCE_CTRL, field MPLL_N_CNTRL[8:7] (RW)
 *
 * Programmable Divider Control This bus controls the programmable divider modulus, which are set
 * based on the ck_ref_mpll_p/m (TMDS rate) input reference frequency to keep the ring oscillator
 * within the required range (925 MHz through 1.85 GHz in MPLL).
 *
 * Values:
 * 00 - N = 1 (for TMDS rate of 184.1-370 MHz)
 * 01 - N = 2 (for TMDS rate of 92.51-185 MHz)
 * 10 - N = 4 (for TMDS rate of 45.26-92.5 MHz)
 * 11 - N = 8 (for TMDS rate up to 45.25 MHz)
 */

#define BP_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL      (7)      //!< Bit position for HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL.
#define BM_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL      (0x00000180)  //!< Bit mask for HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL.

//! @brief Get value of HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL from a register value.
#define BG_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL(r)   (((r) & BM_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL) >> BP_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL.
#define BF_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL(v)   ((((reg16_t) v) << BP_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL) & BM_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL)
#else
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL.
#define BF_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL(v)   (((v) << BP_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL) & BM_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_N_CNTRL field to a new value.
#define BW_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL(v)   (HW_HDMI_PHY_CPCE_CTRL_WR((HW_HDMI_PHY_CPCE_CTRL_RD() & ~BM_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL) | BF_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL(v)))
#endif


/* --- Register HW_HDMI_PHY_CPCE_CTRL, field CK_EDGERATE[10:9] (RW)
 *
 * Clock Edge Rate This bus controls the slew rate of the clock output driver.
 *
 * Values:
 * 0 - ck_edgerate[0]: Slow edges
 * 0 - ck_edgerate[1]: Disable edge rate override.
 * 1 - ck_edgerate[0]: Fast edges
 * 1 - ck_edgerate[1]: Enable edge rate override.
 */

#define BP_HDMI_PHY_CPCE_CTRL_CK_EDGERATE      (9)      //!< Bit position for HDMI_PHY_CPCE_CTRL_CK_EDGERATE.
#define BM_HDMI_PHY_CPCE_CTRL_CK_EDGERATE      (0x00000600)  //!< Bit mask for HDMI_PHY_CPCE_CTRL_CK_EDGERATE.

//! @brief Get value of HDMI_PHY_CPCE_CTRL_CK_EDGERATE from a register value.
#define BG_HDMI_PHY_CPCE_CTRL_CK_EDGERATE(r)   (((r) & BM_HDMI_PHY_CPCE_CTRL_CK_EDGERATE) >> BP_HDMI_PHY_CPCE_CTRL_CK_EDGERATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_CK_EDGERATE.
#define BF_HDMI_PHY_CPCE_CTRL_CK_EDGERATE(v)   ((((reg16_t) v) << BP_HDMI_PHY_CPCE_CTRL_CK_EDGERATE) & BM_HDMI_PHY_CPCE_CTRL_CK_EDGERATE)
#else
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_CK_EDGERATE.
#define BF_HDMI_PHY_CPCE_CTRL_CK_EDGERATE(v)   (((v) << BP_HDMI_PHY_CPCE_CTRL_CK_EDGERATE) & BM_HDMI_PHY_CPCE_CTRL_CK_EDGERATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CK_EDGERATE field to a new value.
#define BW_HDMI_PHY_CPCE_CTRL_CK_EDGERATE(v)   (HW_HDMI_PHY_CPCE_CTRL_WR((HW_HDMI_PHY_CPCE_CTRL_RD() & ~BM_HDMI_PHY_CPCE_CTRL_CK_EDGERATE) | BF_HDMI_PHY_CPCE_CTRL_CK_EDGERATE(v)))
#endif


/* --- Register HW_HDMI_PHY_CPCE_CTRL, field TX_EDGERATE[12:11] (RW)
 *
 * Transmitter Edge Rate This bus controls the slew rate of the transmitter output driver.
 *
 * Values:
 * 0 - tx_edgerate[0]: Slow edges
 * 0 - tx_edgerate[1]: Disable edge rate override.
 * 1 - tx_edgerate[0]: Fast edges
 * 1 - tx_edgerate[1]: Enable edge rate override.
 */

#define BP_HDMI_PHY_CPCE_CTRL_TX_EDGERATE      (11)      //!< Bit position for HDMI_PHY_CPCE_CTRL_TX_EDGERATE.
#define BM_HDMI_PHY_CPCE_CTRL_TX_EDGERATE      (0x00001800)  //!< Bit mask for HDMI_PHY_CPCE_CTRL_TX_EDGERATE.

//! @brief Get value of HDMI_PHY_CPCE_CTRL_TX_EDGERATE from a register value.
#define BG_HDMI_PHY_CPCE_CTRL_TX_EDGERATE(r)   (((r) & BM_HDMI_PHY_CPCE_CTRL_TX_EDGERATE) >> BP_HDMI_PHY_CPCE_CTRL_TX_EDGERATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_TX_EDGERATE.
#define BF_HDMI_PHY_CPCE_CTRL_TX_EDGERATE(v)   ((((reg16_t) v) << BP_HDMI_PHY_CPCE_CTRL_TX_EDGERATE) & BM_HDMI_PHY_CPCE_CTRL_TX_EDGERATE)
#else
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_TX_EDGERATE.
#define BF_HDMI_PHY_CPCE_CTRL_TX_EDGERATE(v)   (((v) << BP_HDMI_PHY_CPCE_CTRL_TX_EDGERATE) & BM_HDMI_PHY_CPCE_CTRL_TX_EDGERATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_EDGERATE field to a new value.
#define BW_HDMI_PHY_CPCE_CTRL_TX_EDGERATE(v)   (HW_HDMI_PHY_CPCE_CTRL_WR((HW_HDMI_PHY_CPCE_CTRL_RD() & ~BM_HDMI_PHY_CPCE_CTRL_TX_EDGERATE) | BF_HDMI_PHY_CPCE_CTRL_TX_EDGERATE(v)))
#endif


/* --- Register HW_HDMI_PHY_CPCE_CTRL, field PREP_DIV[14:13] (RW)
 *
 * Digital Pixel Repetition Divider Controls the ratio by which the internal TMDS clock is divided
 * to generate PREPCLK.
 *
 * Values:
 * 00 - Divide by 1 (8 bit).
 * 01 - Divide by 1.25 (10 bits).
 * 10 - Divide by 1.5 (12 bits).
 * 11 - Divide by 2 (16 bits).
 */

#define BP_HDMI_PHY_CPCE_CTRL_PREP_DIV      (13)      //!< Bit position for HDMI_PHY_CPCE_CTRL_PREP_DIV.
#define BM_HDMI_PHY_CPCE_CTRL_PREP_DIV      (0x00006000)  //!< Bit mask for HDMI_PHY_CPCE_CTRL_PREP_DIV.

//! @brief Get value of HDMI_PHY_CPCE_CTRL_PREP_DIV from a register value.
#define BG_HDMI_PHY_CPCE_CTRL_PREP_DIV(r)   (((r) & BM_HDMI_PHY_CPCE_CTRL_PREP_DIV) >> BP_HDMI_PHY_CPCE_CTRL_PREP_DIV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_PREP_DIV.
#define BF_HDMI_PHY_CPCE_CTRL_PREP_DIV(v)   ((((reg16_t) v) << BP_HDMI_PHY_CPCE_CTRL_PREP_DIV) & BM_HDMI_PHY_CPCE_CTRL_PREP_DIV)
#else
//! @brief Format value for bitfield HDMI_PHY_CPCE_CTRL_PREP_DIV.
#define BF_HDMI_PHY_CPCE_CTRL_PREP_DIV(v)   (((v) << BP_HDMI_PHY_CPCE_CTRL_PREP_DIV) & BM_HDMI_PHY_CPCE_CTRL_PREP_DIV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PREP_DIV field to a new value.
#define BW_HDMI_PHY_CPCE_CTRL_PREP_DIV(v)   (HW_HDMI_PHY_CPCE_CTRL_WR((HW_HDMI_PHY_CPCE_CTRL_RD() & ~BM_HDMI_PHY_CPCE_CTRL_PREP_DIV) | BF_HDMI_PHY_CPCE_CTRL_PREP_DIV(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_TXCLKMEASCTRL - Tx and Clock Measure Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : TXCKMEASCTRL  Access type : Read/write  Address : 0x07  Value at reset : 0x0000
 * tx_meas_iv2[7:0]        Effective Bit  Register Value  Description    tx_meas_iv2[0]  00000001
 * Connect V cm_p (common DC voltage of the positive side of scope) to the analog test bus.
 * tx_meas_iv2[1]  00000010  Connect V cm_m (common DC voltage of the negative side of scope) to the
 * analog test bus.    tx_meas_iv2[2]  00000100  Connect V bg3by4_reg (output node of tx_vreg_vbgby2
 * block) to the analog test bus.    tx_meas_iv2[3]  00001000  Connect t x_vref (reference voltage
 * of tx_biasgen block) to the analog test bus.    tx_meas_iv2[4]  00010000  Connect V rep_fb
 * (feedback voltage of the replica circuit of tx_biasgen block) to the analog test bus.
 * tx_meas_iv2[5]  00100000  In the event that bleed current is too large, this bit can be used to
 * force vb closer to gnd and disable/reduce the bleed current. (This bit is a debug feature, which
 * does not pull vb to gnd properly.)    tx_meas_iv2[6]  01000000  Connect V p (low power supply) to
 * the analog test bus.    tx_meas_iv2[7]  10000000  Connect V cm (common DC voltage of the scope)
 * to the analog test bus.       ck_meas_iv[7:0]        Effective Bit  Register Value  Description
 * ck_meas_iv[0]  00000001  Connect V cm_p (common DC voltage of the positive side of scope) to the
 * analog test bus.    ck_meas_iv[1]  00000010  Connect V cm_m (common DC voltage of the negative
 * side of scope) to the analog test bus.    ck_meas_iv[2]  00000100  Connect V bg3by4_reg (output
 * node of tx_vreg_vbgby2 block) to the analog test bus.    ck_meas_iv[3]  00001000  Connect t
 * x_vref (reference voltage of tx_biasgen block) to the analog test bus.    ck_meas_iv[4]  00010000
 * Connect V rep_fb (feedback voltage of the replica circuit of tx_biasgen block) to the analog test
 * bus.    ck_meas_iv[5]  00100000  In the event that bleed current is too large, this bit can be
 * used to force v b closer to gnd and disable/reduce the bleed current. (This bit is a debug
 * feature, which does not pull v b to gnd properly.)    ck_meas_iv[6]  01000000  Connect V p (low
 * power supply) to the analog test bus.    ck_meas_iv[7]  10000000  Connect V cm (common DC voltage
 * of scope) to the analog test bus.
 */
typedef union _hw_hdmi_phy_txclkmeasctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_txclkmeasctrl_bitfields
    {
        unsigned short CK_MEAS_IV : 8; //!< [7:0] Clock Measure Internal Voltage This bus is used to test specific voltages for the clock lane/channel by applying voltages on the atb_sense port based on configured currents, as described in the ck_meas_iv[7:0] table.
        unsigned short TX_MEAS_IV2 : 8; //!< [15:8] Transmitter Measure Internal Voltage 2 This bus is used to test specific voltages for third transmitter lane/channel by applying voltages on the atb_sense port based on configured currents, as described in the tx_meas_iv2[7:0] table.
    } B;
} hw_hdmi_phy_txclkmeasctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TXCLKMEASCTRL register
 */
#define HW_HDMI_PHY_TXCLKMEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TXCLKMEASCTRL           (*(volatile hw_hdmi_phy_txclkmeasctrl_t *) HW_HDMI_PHY_TXCLKMEASCTRL_ADDR)
#define HW_HDMI_PHY_TXCLKMEASCTRL_RD()      (HW_HDMI_PHY_TXCLKMEASCTRL.U)
#define HW_HDMI_PHY_TXCLKMEASCTRL_WR(v)     (HW_HDMI_PHY_TXCLKMEASCTRL.U = (v))
#define HW_HDMI_PHY_TXCLKMEASCTRL_SET(v)    (HW_HDMI_PHY_TXCLKMEASCTRL_WR(HW_HDMI_PHY_TXCLKMEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_TXCLKMEASCTRL_CLR(v)    (HW_HDMI_PHY_TXCLKMEASCTRL_WR(HW_HDMI_PHY_TXCLKMEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_TXCLKMEASCTRL_TOG(v)    (HW_HDMI_PHY_TXCLKMEASCTRL_WR(HW_HDMI_PHY_TXCLKMEASCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_TXCLKMEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_TXCLKMEASCTRL, field CK_MEAS_IV[7:0] (RW)
 *
 * Clock Measure Internal Voltage This bus is used to test specific voltages for the clock
 * lane/channel by applying voltages on the atb_sense port based on configured currents, as
 * described in the ck_meas_iv[7:0] table.
 */

#define BP_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV      (0)      //!< Bit position for HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV.
#define BM_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV      (0x000000ff)  //!< Bit mask for HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV.

//! @brief Get value of HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV from a register value.
#define BG_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV(r)   (((r) & BM_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV) >> BP_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV.
#define BF_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV(v)   ((((reg16_t) v) << BP_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV) & BM_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV)
#else
//! @brief Format value for bitfield HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV.
#define BF_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV(v)   (((v) << BP_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV) & BM_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CK_MEAS_IV field to a new value.
#define BW_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV(v)   (HW_HDMI_PHY_TXCLKMEASCTRL_WR((HW_HDMI_PHY_TXCLKMEASCTRL_RD() & ~BM_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV) | BF_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV(v)))
#endif

/* --- Register HW_HDMI_PHY_TXCLKMEASCTRL, field TX_MEAS_IV2[15:8] (RW)
 *
 * Transmitter Measure Internal Voltage 2 This bus is used to test specific voltages for third
 * transmitter lane/channel by applying voltages on the atb_sense port based on configured currents,
 * as described in the tx_meas_iv2[7:0] table.
 */

#define BP_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2      (8)      //!< Bit position for HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2.
#define BM_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2      (0x0000ff00)  //!< Bit mask for HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2.

//! @brief Get value of HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2 from a register value.
#define BG_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2(r)   (((r) & BM_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2) >> BP_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2.
#define BF_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2(v)   ((((reg16_t) v) << BP_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2) & BM_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2)
#else
//! @brief Format value for bitfield HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2.
#define BF_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2(v)   (((v) << BP_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2) & BM_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_MEAS_IV2 field to a new value.
#define BW_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2(v)   (HW_HDMI_PHY_TXCLKMEASCTRL_WR((HW_HDMI_PHY_TXCLKMEASCTRL_RD() & ~BM_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2) | BF_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_TXMEASCTRL - Tx Measure Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : TXMEASCTRL  Access type : Read/write  Address : 0x08  Value at reset : 0x0000
 * tx_meas_iv1[7:0]        Effective Bit  Register Value  Description    tx_meas_iv1[0]  00000001
 * Connect V cm_p (common DC voltage of positive side of scope) to the analog test bus.
 * tx_meas_iv1[1]  00000010  Connect V cm_m (common DC voltage of negative side of scope) to the
 * analog test bus.    tx_meas_iv1[2]  00000100  Connect V bg3by4_reg (output node of tx_vreg_vbgby2
 * block) to the analog test bus.    tx_meas_iv1[3]  00001000  Connect t x_vref (reference voltage
 * of tx_biasgen block) to the analog test bus.    tx_meas_iv1[4]  00010000  Connect V rep_fb
 * (feedback voltage of replica circuit of tx_biasgen block) to the analog test bus.
 * tx_meas_iv1[5]  00100000  In case bleed current is too large, this bit can be used to force v b
 * closer to gnd and disable/reduce the bleed current. (This bit is a debug feature, which does not
 * pull v b to gnd properly.)    tx_meas_iv1[6]  01000000  Connect V p (low power supply) to the
 * analog test bus.    tx_meas_iv1[7]  10000000  Connect V cm (common DC voltage of scope) to the
 * analog test bus.       tx_meas_iv0[7:0]        Effective Bit  Register Value  Description
 * tx_meas_iv0[0]  00000001  Connect V cm_p (common DC voltage of positive side of scope) to the
 * analog test bus.    tx_meas_iv0[1]  00000010  Connect V cm_m (common DC voltage of negative side
 * of scope) to the analog test bus.    tx_meas_iv0[2]  00000100  Connect V bg3by4_reg (output node
 * of tx_vreg_vbgby2 block) to the analog test bus.    tx_meas_iv0[3]  00001000  Connect t x_vref
 * (reference voltage of tx_biasgen block) to the analog test bus    tx_meas_iv0[4]  00010000
 * Connect V rep_fb (feedback voltage of replica circuit of tx_biasgen block) to the analog test
 * bus.    tx_meas_iv0[5]  00100000  In the event that bleed current is too large, this bit can be
 * used to force v b closer to gnd and disable/reduce the bleed current. (This bit is a debug
 * feature, which does not pull v b to gnd properly.)    tx_meas_iv0[6]  01000000  Connect V p (low
 * power supply) to the analog test bus.    tx_meas_iv0[7]  10000000  Connect V cm (common DC
 * voltage of scope) to the analog test bus.
 */
typedef union _hw_hdmi_phy_txmeasctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_txmeasctrl_bitfields
    {
        unsigned short TX_MEAS_IV1 : 8; //!< [7:0] Transmitter Measure Internal Voltage 1 This bus is used to test specific voltages for the second transmitter lane/channel by applying voltages on the atb_sense port based on configured currents, as described in the tx_meas_iv1[7:0] table.
        unsigned short TX_MEAS_IV0 : 8; //!< [15:8] Transmitter Measure Internal Voltage 0 This bus is used to test specific voltages for the first transmitter lane/channel by applying voltages on the atb_sense port based on configured currents, as described in the tx_meas_iv0[7:0] table.
    } B;
} hw_hdmi_phy_txmeasctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TXMEASCTRL register
 */
#define HW_HDMI_PHY_TXMEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TXMEASCTRL           (*(volatile hw_hdmi_phy_txmeasctrl_t *) HW_HDMI_PHY_TXMEASCTRL_ADDR)
#define HW_HDMI_PHY_TXMEASCTRL_RD()      (HW_HDMI_PHY_TXMEASCTRL.U)
#define HW_HDMI_PHY_TXMEASCTRL_WR(v)     (HW_HDMI_PHY_TXMEASCTRL.U = (v))
#define HW_HDMI_PHY_TXMEASCTRL_SET(v)    (HW_HDMI_PHY_TXMEASCTRL_WR(HW_HDMI_PHY_TXMEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_TXMEASCTRL_CLR(v)    (HW_HDMI_PHY_TXMEASCTRL_WR(HW_HDMI_PHY_TXMEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_TXMEASCTRL_TOG(v)    (HW_HDMI_PHY_TXMEASCTRL_WR(HW_HDMI_PHY_TXMEASCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_TXMEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_TXMEASCTRL, field TX_MEAS_IV1[7:0] (RW)
 *
 * Transmitter Measure Internal Voltage 1 This bus is used to test specific voltages for the second
 * transmitter lane/channel by applying voltages on the atb_sense port based on configured currents,
 * as described in the tx_meas_iv1[7:0] table.
 */

#define BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1      (0)      //!< Bit position for HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1.
#define BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1      (0x000000ff)  //!< Bit mask for HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1.

//! @brief Get value of HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1 from a register value.
#define BG_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1(r)   (((r) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1) >> BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1.
#define BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1(v)   ((((reg16_t) v) << BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1)
#else
//! @brief Format value for bitfield HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1.
#define BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1(v)   (((v) << BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_MEAS_IV1 field to a new value.
#define BW_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1(v)   (HW_HDMI_PHY_TXMEASCTRL_WR((HW_HDMI_PHY_TXMEASCTRL_RD() & ~BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1) | BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1(v)))
#endif

/* --- Register HW_HDMI_PHY_TXMEASCTRL, field TX_MEAS_IV0[15:8] (RW)
 *
 * Transmitter Measure Internal Voltage 0 This bus is used to test specific voltages for the first
 * transmitter lane/channel by applying voltages on the atb_sense port based on configured currents,
 * as described in the tx_meas_iv0[7:0] table.
 */

#define BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0      (8)      //!< Bit position for HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0.
#define BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0      (0x0000ff00)  //!< Bit mask for HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0.

//! @brief Get value of HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0 from a register value.
#define BG_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0(r)   (((r) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0) >> BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0.
#define BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0(v)   ((((reg16_t) v) << BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0)
#else
//! @brief Format value for bitfield HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0.
#define BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0(v)   (((v) << BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_MEAS_IV0 field to a new value.
#define BW_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0(v)   (HW_HDMI_PHY_TXMEASCTRL_WR((HW_HDMI_PHY_TXMEASCTRL_RD() & ~BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0) | BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_CKSYMTXCTRL - Clock Symbol and Transmitter Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : CKSYMTXCTRL  Access type : Read/write/override  Address : 0x09  Value at reset :
 * 0x0009
 */
typedef union _hw_hdmi_phy_cksymtxctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_cksymtxctrl_bitfields
    {
        unsigned short CK_SYMON : 1; //!< [0] Clock Symbol On This bit enables the clock symbol driver. To enable the clock driver, the ck_powon bit must be high. In addition, there is no pre-emphasis enable for the clock driver.
        unsigned short TX_TRBON : 1; //!< [1] Transmitter Trailer B On This bit enables the transmitter trailer B driver(s). To enable the transmitter trailer B driver(s) and to enable pre-emphasis, the tx_pwron bit for each channel must be high.
        unsigned short TX_TRAON : 1; //!< [2] Transmitter Trailer A On This bit enables the transmitter trailer A driver(s). To enable the transmitter trailer A driver(s) and to enable pre-emphasis, the tx_pwron bit for each channel must be high.
        unsigned short TX_SYMON : 1; //!< [3] Transmitter Symbol On This bit enables the transmitter symbol driver(s), To enable the transmitter driver(s), the tx_pwron bit for each channel must be high.
        unsigned short RESERVED0 : 11; //!< [14:4] Reserved
        unsigned short OVERRIDE : 1; //!< [15] 
    } B;
} hw_hdmi_phy_cksymtxctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CKSYMTXCTRL register
 */
#define HW_HDMI_PHY_CKSYMTXCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CKSYMTXCTRL           (*(volatile hw_hdmi_phy_cksymtxctrl_t *) HW_HDMI_PHY_CKSYMTXCTRL_ADDR)
#define HW_HDMI_PHY_CKSYMTXCTRL_RD()      (HW_HDMI_PHY_CKSYMTXCTRL.U)
#define HW_HDMI_PHY_CKSYMTXCTRL_WR(v)     (HW_HDMI_PHY_CKSYMTXCTRL.U = (v))
#define HW_HDMI_PHY_CKSYMTXCTRL_SET(v)    (HW_HDMI_PHY_CKSYMTXCTRL_WR(HW_HDMI_PHY_CKSYMTXCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CKSYMTXCTRL_CLR(v)    (HW_HDMI_PHY_CKSYMTXCTRL_WR(HW_HDMI_PHY_CKSYMTXCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CKSYMTXCTRL_TOG(v)    (HW_HDMI_PHY_CKSYMTXCTRL_WR(HW_HDMI_PHY_CKSYMTXCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_CKSYMTXCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field CK_SYMON[0] (RW)
 *
 * Clock Symbol On This bit enables the clock symbol driver. To enable the clock driver, the
 * ck_powon bit must be high. In addition, there is no pre-emphasis enable for the clock driver.
 *
 * Values:
 * 0 - Disable the clock symbol driver, if the Override bit is 0.
 * 1 - Enable the clock symbol driver, if the Override bit is 0.
 */

#define BP_HDMI_PHY_CKSYMTXCTRL_CK_SYMON      (0)      //!< Bit position for HDMI_PHY_CKSYMTXCTRL_CK_SYMON.
#define BM_HDMI_PHY_CKSYMTXCTRL_CK_SYMON      (0x00000001)  //!< Bit mask for HDMI_PHY_CKSYMTXCTRL_CK_SYMON.

//! @brief Get value of HDMI_PHY_CKSYMTXCTRL_CK_SYMON from a register value.
#define BG_HDMI_PHY_CKSYMTXCTRL_CK_SYMON(r)   (((r) & BM_HDMI_PHY_CKSYMTXCTRL_CK_SYMON) >> BP_HDMI_PHY_CKSYMTXCTRL_CK_SYMON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_CK_SYMON.
#define BF_HDMI_PHY_CKSYMTXCTRL_CK_SYMON(v)   ((((reg16_t) v) << BP_HDMI_PHY_CKSYMTXCTRL_CK_SYMON) & BM_HDMI_PHY_CKSYMTXCTRL_CK_SYMON)
#else
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_CK_SYMON.
#define BF_HDMI_PHY_CKSYMTXCTRL_CK_SYMON(v)   (((v) << BP_HDMI_PHY_CKSYMTXCTRL_CK_SYMON) & BM_HDMI_PHY_CKSYMTXCTRL_CK_SYMON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CK_SYMON field to a new value.
#define BW_HDMI_PHY_CKSYMTXCTRL_CK_SYMON(v)   (HW_HDMI_PHY_CKSYMTXCTRL_WR((HW_HDMI_PHY_CKSYMTXCTRL_RD() & ~BM_HDMI_PHY_CKSYMTXCTRL_CK_SYMON) | BF_HDMI_PHY_CKSYMTXCTRL_CK_SYMON(v)))
#endif


/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field TX_TRBON[1] (RW)
 *
 * Transmitter Trailer B On This bit enables the transmitter trailer B driver(s). To enable the
 * transmitter trailer B driver(s) and to enable pre-emphasis, the tx_pwron bit for each channel
 * must be high.
 *
 * Values:
 * 0 - Disable the transmitter trailer B driver(s), if the Override bit is 0.
 * 1 - Enable the transmitter trailer B driver(s), if the Override bit is 0.
 */

#define BP_HDMI_PHY_CKSYMTXCTRL_TX_TRBON      (1)      //!< Bit position for HDMI_PHY_CKSYMTXCTRL_TX_TRBON.
#define BM_HDMI_PHY_CKSYMTXCTRL_TX_TRBON      (0x00000002)  //!< Bit mask for HDMI_PHY_CKSYMTXCTRL_TX_TRBON.

//! @brief Get value of HDMI_PHY_CKSYMTXCTRL_TX_TRBON from a register value.
#define BG_HDMI_PHY_CKSYMTXCTRL_TX_TRBON(r)   (((r) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRBON) >> BP_HDMI_PHY_CKSYMTXCTRL_TX_TRBON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_TX_TRBON.
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_TRBON(v)   ((((reg16_t) v) << BP_HDMI_PHY_CKSYMTXCTRL_TX_TRBON) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRBON)
#else
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_TX_TRBON.
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_TRBON(v)   (((v) << BP_HDMI_PHY_CKSYMTXCTRL_TX_TRBON) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRBON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_TRBON field to a new value.
#define BW_HDMI_PHY_CKSYMTXCTRL_TX_TRBON(v)   (HW_HDMI_PHY_CKSYMTXCTRL_WR((HW_HDMI_PHY_CKSYMTXCTRL_RD() & ~BM_HDMI_PHY_CKSYMTXCTRL_TX_TRBON) | BF_HDMI_PHY_CKSYMTXCTRL_TX_TRBON(v)))
#endif


/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field TX_TRAON[2] (RW)
 *
 * Transmitter Trailer A On This bit enables the transmitter trailer A driver(s). To enable the
 * transmitter trailer A driver(s) and to enable pre-emphasis, the tx_pwron bit for each channel
 * must be high.
 *
 * Values:
 * 0 - Disable the transmitter trailer A driver(s), if the Override bit is 0.
 * 1 - Enable the transmitter trailer A driver(s), if the Override bit is 0.
 */

#define BP_HDMI_PHY_CKSYMTXCTRL_TX_TRAON      (2)      //!< Bit position for HDMI_PHY_CKSYMTXCTRL_TX_TRAON.
#define BM_HDMI_PHY_CKSYMTXCTRL_TX_TRAON      (0x00000004)  //!< Bit mask for HDMI_PHY_CKSYMTXCTRL_TX_TRAON.

//! @brief Get value of HDMI_PHY_CKSYMTXCTRL_TX_TRAON from a register value.
#define BG_HDMI_PHY_CKSYMTXCTRL_TX_TRAON(r)   (((r) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRAON) >> BP_HDMI_PHY_CKSYMTXCTRL_TX_TRAON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_TX_TRAON.
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_TRAON(v)   ((((reg16_t) v) << BP_HDMI_PHY_CKSYMTXCTRL_TX_TRAON) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRAON)
#else
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_TX_TRAON.
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_TRAON(v)   (((v) << BP_HDMI_PHY_CKSYMTXCTRL_TX_TRAON) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRAON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_TRAON field to a new value.
#define BW_HDMI_PHY_CKSYMTXCTRL_TX_TRAON(v)   (HW_HDMI_PHY_CKSYMTXCTRL_WR((HW_HDMI_PHY_CKSYMTXCTRL_RD() & ~BM_HDMI_PHY_CKSYMTXCTRL_TX_TRAON) | BF_HDMI_PHY_CKSYMTXCTRL_TX_TRAON(v)))
#endif


/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field TX_SYMON[3] (RW)
 *
 * Transmitter Symbol On This bit enables the transmitter symbol driver(s), To enable the
 * transmitter driver(s), the tx_pwron bit for each channel must be high.
 *
 * Values:
 * 0 - Disable the transmitter symbol driver(s), if the Override bit is 0.
 * 1 - Enable the transmitter symbol driver(s), if the Override bit is 0.
 */

#define BP_HDMI_PHY_CKSYMTXCTRL_TX_SYMON      (3)      //!< Bit position for HDMI_PHY_CKSYMTXCTRL_TX_SYMON.
#define BM_HDMI_PHY_CKSYMTXCTRL_TX_SYMON      (0x00000008)  //!< Bit mask for HDMI_PHY_CKSYMTXCTRL_TX_SYMON.

//! @brief Get value of HDMI_PHY_CKSYMTXCTRL_TX_SYMON from a register value.
#define BG_HDMI_PHY_CKSYMTXCTRL_TX_SYMON(r)   (((r) & BM_HDMI_PHY_CKSYMTXCTRL_TX_SYMON) >> BP_HDMI_PHY_CKSYMTXCTRL_TX_SYMON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_TX_SYMON.
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_SYMON(v)   ((((reg16_t) v) << BP_HDMI_PHY_CKSYMTXCTRL_TX_SYMON) & BM_HDMI_PHY_CKSYMTXCTRL_TX_SYMON)
#else
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_TX_SYMON.
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_SYMON(v)   (((v) << BP_HDMI_PHY_CKSYMTXCTRL_TX_SYMON) & BM_HDMI_PHY_CKSYMTXCTRL_TX_SYMON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_SYMON field to a new value.
#define BW_HDMI_PHY_CKSYMTXCTRL_TX_SYMON(v)   (HW_HDMI_PHY_CKSYMTXCTRL_WR((HW_HDMI_PHY_CKSYMTXCTRL_RD() & ~BM_HDMI_PHY_CKSYMTXCTRL_TX_SYMON) | BF_HDMI_PHY_CKSYMTXCTRL_TX_SYMON(v)))
#endif


/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field OVERRIDE[15] (RW)
 *

 */

#define BP_HDMI_PHY_CKSYMTXCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_CKSYMTXCTRL_OVERRIDE.
#define BM_HDMI_PHY_CKSYMTXCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_CKSYMTXCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_CKSYMTXCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_CKSYMTXCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_CKSYMTXCTRL_OVERRIDE) >> BP_HDMI_PHY_CKSYMTXCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_OVERRIDE.
#define BF_HDMI_PHY_CKSYMTXCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_CKSYMTXCTRL_OVERRIDE) & BM_HDMI_PHY_CKSYMTXCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_CKSYMTXCTRL_OVERRIDE.
#define BF_HDMI_PHY_CKSYMTXCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_CKSYMTXCTRL_OVERRIDE) & BM_HDMI_PHY_CKSYMTXCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_CKSYMTXCTRL_OVERRIDE(v)   (HW_HDMI_PHY_CKSYMTXCTRL_WR((HW_HDMI_PHY_CKSYMTXCTRL_RD() & ~BM_HDMI_PHY_CKSYMTXCTRL_OVERRIDE) | BF_HDMI_PHY_CKSYMTXCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_CMPSEQCTRL - Comparator Sequence Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : CMPSEQCTRL  Access type : Read/write/override  Address : 0x0A  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_cmpseqctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_cmpseqctrl_bitfields
    {
        unsigned short SUP_COMP_RT_R : 1; //!< [0] Support Comparator Resistance Termination This bit controls the comparator sequence.
        unsigned short RESERVED0 : 14; //!< [14:1] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_cmpseqctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CMPSEQCTRL register
 */
#define HW_HDMI_PHY_CMPSEQCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xa)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CMPSEQCTRL           (*(volatile hw_hdmi_phy_cmpseqctrl_t *) HW_HDMI_PHY_CMPSEQCTRL_ADDR)
#define HW_HDMI_PHY_CMPSEQCTRL_RD()      (HW_HDMI_PHY_CMPSEQCTRL.U)
#define HW_HDMI_PHY_CMPSEQCTRL_WR(v)     (HW_HDMI_PHY_CMPSEQCTRL.U = (v))
#define HW_HDMI_PHY_CMPSEQCTRL_SET(v)    (HW_HDMI_PHY_CMPSEQCTRL_WR(HW_HDMI_PHY_CMPSEQCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CMPSEQCTRL_CLR(v)    (HW_HDMI_PHY_CMPSEQCTRL_WR(HW_HDMI_PHY_CMPSEQCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CMPSEQCTRL_TOG(v)    (HW_HDMI_PHY_CMPSEQCTRL_WR(HW_HDMI_PHY_CMPSEQCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_CMPSEQCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CMPSEQCTRL, field SUP_COMP_RT_R[0] (RW)
 *
 * Support Comparator Resistance Termination This bit controls the comparator sequence.
 *
 * Values:
 * 0 - Latch the first input, if the Override bit is 0.
 * 1 - Latch the second input, then set the comparator's output pin by the result of comparison, if the
 *     Override bit is 0.
 */

#define BP_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R      (0)      //!< Bit position for HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R.
#define BM_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R      (0x00000001)  //!< Bit mask for HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R.

//! @brief Get value of HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R from a register value.
#define BG_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R(r)   (((r) & BM_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R) >> BP_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R.
#define BF_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R(v)   ((((reg16_t) v) << BP_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R) & BM_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R)
#else
//! @brief Format value for bitfield HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R.
#define BF_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R(v)   (((v) << BP_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R) & BM_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_COMP_RT_R field to a new value.
#define BW_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R(v)   (HW_HDMI_PHY_CMPSEQCTRL_WR((HW_HDMI_PHY_CMPSEQCTRL_RD() & ~BM_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R) | BF_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R(v)))
#endif


/* --- Register HW_HDMI_PHY_CMPSEQCTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_CMPSEQCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_CMPSEQCTRL_OVERRIDE.
#define BM_HDMI_PHY_CMPSEQCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_CMPSEQCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_CMPSEQCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_CMPSEQCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_CMPSEQCTRL_OVERRIDE) >> BP_HDMI_PHY_CMPSEQCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CMPSEQCTRL_OVERRIDE.
#define BF_HDMI_PHY_CMPSEQCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_CMPSEQCTRL_OVERRIDE) & BM_HDMI_PHY_CMPSEQCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_CMPSEQCTRL_OVERRIDE.
#define BF_HDMI_PHY_CMPSEQCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_CMPSEQCTRL_OVERRIDE) & BM_HDMI_PHY_CMPSEQCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_CMPSEQCTRL_OVERRIDE(v)   (HW_HDMI_PHY_CMPSEQCTRL_WR((HW_HDMI_PHY_CMPSEQCTRL_RD() & ~BM_HDMI_PHY_CMPSEQCTRL_OVERRIDE) | BF_HDMI_PHY_CMPSEQCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_CMPPWRCTRL - Comparator Power Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : CMPPWRCTRL  Access type : Read/write/override  Address : 0x0B  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_cmppwrctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_cmppwrctrl_bitfields
    {
        unsigned short SUP_COMP_RT_PWRON : 1; //!< [0] Support Comparator Resistance Termination Power-On This bit powers on the Comparator module.
        unsigned short RESERVED0 : 14; //!< [14:1] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_cmppwrctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CMPPWRCTRL register
 */
#define HW_HDMI_PHY_CMPPWRCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xb)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CMPPWRCTRL           (*(volatile hw_hdmi_phy_cmppwrctrl_t *) HW_HDMI_PHY_CMPPWRCTRL_ADDR)
#define HW_HDMI_PHY_CMPPWRCTRL_RD()      (HW_HDMI_PHY_CMPPWRCTRL.U)
#define HW_HDMI_PHY_CMPPWRCTRL_WR(v)     (HW_HDMI_PHY_CMPPWRCTRL.U = (v))
#define HW_HDMI_PHY_CMPPWRCTRL_SET(v)    (HW_HDMI_PHY_CMPPWRCTRL_WR(HW_HDMI_PHY_CMPPWRCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CMPPWRCTRL_CLR(v)    (HW_HDMI_PHY_CMPPWRCTRL_WR(HW_HDMI_PHY_CMPPWRCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CMPPWRCTRL_TOG(v)    (HW_HDMI_PHY_CMPPWRCTRL_WR(HW_HDMI_PHY_CMPPWRCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_CMPPWRCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CMPPWRCTRL, field SUP_COMP_RT_PWRON[0] (RW)
 *
 * Support Comparator Resistance Termination Power-On This bit powers on the Comparator module.
 *
 * Values:
 * 0 - Power off the Comparator module and connect the comparator's output to ground, if the Override bit
 *     is 0.
 * 1 - Power on the Comparator module, if the Override bit is 0.
 */

#define BP_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON      (0)      //!< Bit position for HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON.
#define BM_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON      (0x00000001)  //!< Bit mask for HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON.

//! @brief Get value of HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON from a register value.
#define BG_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON(r)   (((r) & BM_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON) >> BP_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON.
#define BF_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON(v)   ((((reg16_t) v) << BP_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON) & BM_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON)
#else
//! @brief Format value for bitfield HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON.
#define BF_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON(v)   (((v) << BP_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON) & BM_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_COMP_RT_PWRON field to a new value.
#define BW_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON(v)   (HW_HDMI_PHY_CMPPWRCTRL_WR((HW_HDMI_PHY_CMPPWRCTRL_RD() & ~BM_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON) | BF_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON(v)))
#endif


/* --- Register HW_HDMI_PHY_CMPPWRCTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_CMPPWRCTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_CMPPWRCTRL_OVERRIDE.
#define BM_HDMI_PHY_CMPPWRCTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_CMPPWRCTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_CMPPWRCTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_CMPPWRCTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_CMPPWRCTRL_OVERRIDE) >> BP_HDMI_PHY_CMPPWRCTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CMPPWRCTRL_OVERRIDE.
#define BF_HDMI_PHY_CMPPWRCTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_CMPPWRCTRL_OVERRIDE) & BM_HDMI_PHY_CMPPWRCTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_CMPPWRCTRL_OVERRIDE.
#define BF_HDMI_PHY_CMPPWRCTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_CMPPWRCTRL_OVERRIDE) & BM_HDMI_PHY_CMPPWRCTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_CMPPWRCTRL_OVERRIDE(v)   (HW_HDMI_PHY_CMPPWRCTRL_WR((HW_HDMI_PHY_CMPPWRCTRL_RD() & ~BM_HDMI_PHY_CMPPWRCTRL_OVERRIDE) | BF_HDMI_PHY_CMPPWRCTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_CMPMODECTRL - Comparator Mode Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : CMPMODECTRL  Access type : Read/write/override  Address : 0x0C  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_cmpmodectrl
{
    reg16_t U;
    struct _hw_hdmi_phy_cmpmodectrl_bitfields
    {
        unsigned short SUP_COMP_MODE : 1; //!< [0] Support Comparator Mode This bit selects the comparator mode.
        unsigned short RESERVED0 : 14; //!< [14:1] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_cmpmodectrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CMPMODECTRL register
 */
#define HW_HDMI_PHY_CMPMODECTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CMPMODECTRL           (*(volatile hw_hdmi_phy_cmpmodectrl_t *) HW_HDMI_PHY_CMPMODECTRL_ADDR)
#define HW_HDMI_PHY_CMPMODECTRL_RD()      (HW_HDMI_PHY_CMPMODECTRL.U)
#define HW_HDMI_PHY_CMPMODECTRL_WR(v)     (HW_HDMI_PHY_CMPMODECTRL.U = (v))
#define HW_HDMI_PHY_CMPMODECTRL_SET(v)    (HW_HDMI_PHY_CMPMODECTRL_WR(HW_HDMI_PHY_CMPMODECTRL_RD() |  (v)))
#define HW_HDMI_PHY_CMPMODECTRL_CLR(v)    (HW_HDMI_PHY_CMPMODECTRL_WR(HW_HDMI_PHY_CMPMODECTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CMPMODECTRL_TOG(v)    (HW_HDMI_PHY_CMPMODECTRL_WR(HW_HDMI_PHY_CMPMODECTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_CMPMODECTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CMPMODECTRL, field SUP_COMP_MODE[0] (RW)
 *
 * Support Comparator Mode This bit selects the comparator mode.
 *
 * Values:
 * 0 - Testing mode (ADC mode)
 * 1 - Calibration mode
 */

#define BP_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE      (0)      //!< Bit position for HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE.
#define BM_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE      (0x00000001)  //!< Bit mask for HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE.

//! @brief Get value of HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE from a register value.
#define BG_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE(r)   (((r) & BM_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE) >> BP_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE.
#define BF_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE(v)   ((((reg16_t) v) << BP_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE) & BM_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE)
#else
//! @brief Format value for bitfield HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE.
#define BF_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE(v)   (((v) << BP_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE) & BM_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_COMP_MODE field to a new value.
#define BW_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE(v)   (HW_HDMI_PHY_CMPMODECTRL_WR((HW_HDMI_PHY_CMPMODECTRL_RD() & ~BM_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE) | BF_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE(v)))
#endif


/* --- Register HW_HDMI_PHY_CMPMODECTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_CMPMODECTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_CMPMODECTRL_OVERRIDE.
#define BM_HDMI_PHY_CMPMODECTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_CMPMODECTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_CMPMODECTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_CMPMODECTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_CMPMODECTRL_OVERRIDE) >> BP_HDMI_PHY_CMPMODECTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CMPMODECTRL_OVERRIDE.
#define BF_HDMI_PHY_CMPMODECTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_CMPMODECTRL_OVERRIDE) & BM_HDMI_PHY_CMPMODECTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_CMPMODECTRL_OVERRIDE.
#define BF_HDMI_PHY_CMPMODECTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_CMPMODECTRL_OVERRIDE) & BM_HDMI_PHY_CMPMODECTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_CMPMODECTRL_OVERRIDE(v)   (HW_HDMI_PHY_CMPMODECTRL_WR((HW_HDMI_PHY_CMPMODECTRL_RD() & ~BM_HDMI_PHY_CMPMODECTRL_OVERRIDE) | BF_HDMI_PHY_CMPMODECTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_MEASCTRL - Measure Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : MEASCTRL  Access type : Read/write  Address : 0x0D  Value at reset : 0x0000  Two
 * or more of the previous register bits must not be set to 1 simultaneously; doing so can lead to a
 * hardware problem.
 */
typedef union _hw_hdmi_phy_measctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_measctrl_bitfields
    {
        unsigned short SUP_DAC_ON_ATB : 1; //!< [0] Support Digital-to-Analog Converter On Analog Test Bus This bit connects or disconnects the DAC's output on the analog test bus to test the performance of the DAC through Integral Non-Linearity (INL) and Differential Non-Linearity (DNL).
        unsigned short SUP_POR_MEAS_IV : 2; //!< [2:1] Support Power Measure Internal Voltage This bus connects or disconnects a single output signal on the analog test bus to measure the voltage of two nodes of the support power block.
        unsigned short SUP_ATB_ON_REXT : 1; //!< [3] Support Analog Test Bus On External Calibration Resistance This bit connects or disconnects the V rext node to/from the analog test bus.
        unsigned short RESERVED0 : 12; //!< [15:4] Reserved
    } B;
} hw_hdmi_phy_measctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_MEASCTRL register
 */
#define HW_HDMI_PHY_MEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_MEASCTRL           (*(volatile hw_hdmi_phy_measctrl_t *) HW_HDMI_PHY_MEASCTRL_ADDR)
#define HW_HDMI_PHY_MEASCTRL_RD()      (HW_HDMI_PHY_MEASCTRL.U)
#define HW_HDMI_PHY_MEASCTRL_WR(v)     (HW_HDMI_PHY_MEASCTRL.U = (v))
#define HW_HDMI_PHY_MEASCTRL_SET(v)    (HW_HDMI_PHY_MEASCTRL_WR(HW_HDMI_PHY_MEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_MEASCTRL_CLR(v)    (HW_HDMI_PHY_MEASCTRL_WR(HW_HDMI_PHY_MEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_MEASCTRL_TOG(v)    (HW_HDMI_PHY_MEASCTRL_WR(HW_HDMI_PHY_MEASCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_MEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_MEASCTRL, field SUP_DAC_ON_ATB[0] (RW)
 *
 * Support Digital-to-Analog Converter On Analog Test Bus This bit connects or disconnects the DAC's
 * output on the analog test bus to test the performance of the DAC through Integral Non-Linearity
 * (INL) and Differential Non-Linearity (DNL).
 *
 * Values:
 * 0 - Disconnect the DAC's output from the analog test bus.
 * 1 - Connect the DAC's output to the analog test bus.
 */

#define BP_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB      (0)      //!< Bit position for HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB.
#define BM_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB      (0x00000001)  //!< Bit mask for HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB.

//! @brief Get value of HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB from a register value.
#define BG_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB(r)   (((r) & BM_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB) >> BP_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB.
#define BF_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB(v)   ((((reg16_t) v) << BP_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB) & BM_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB)
#else
//! @brief Format value for bitfield HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB.
#define BF_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB(v)   (((v) << BP_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB) & BM_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_DAC_ON_ATB field to a new value.
#define BW_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB(v)   (HW_HDMI_PHY_MEASCTRL_WR((HW_HDMI_PHY_MEASCTRL_RD() & ~BM_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB) | BF_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB(v)))
#endif


/* --- Register HW_HDMI_PHY_MEASCTRL, field SUP_POR_MEAS_IV[2:1] (RW)
 *
 * Support Power Measure Internal Voltage This bus connects or disconnects a single output signal on
 * the analog test bus to measure the voltage of two nodes of the support power block.
 *
 * Values:
 * 01 - Connect V be (Bipolar transistor voltage) to the analog test bus.
 * 10 - Connect V bg (Band-gap voltage) to the analog test bus.
 */

#define BP_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV      (1)      //!< Bit position for HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV.
#define BM_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV      (0x00000006)  //!< Bit mask for HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV.

//! @brief Get value of HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV from a register value.
#define BG_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV(r)   (((r) & BM_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV) >> BP_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV.
#define BF_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV(v)   ((((reg16_t) v) << BP_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV) & BM_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV)
#else
//! @brief Format value for bitfield HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV.
#define BF_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV(v)   (((v) << BP_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV) & BM_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_POR_MEAS_IV field to a new value.
#define BW_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV(v)   (HW_HDMI_PHY_MEASCTRL_WR((HW_HDMI_PHY_MEASCTRL_RD() & ~BM_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV) | BF_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV(v)))
#endif


/* --- Register HW_HDMI_PHY_MEASCTRL, field SUP_ATB_ON_REXT[3] (RW)
 *
 * Support Analog Test Bus On External Calibration Resistance This bit connects or disconnects the V
 * rext node to/from the analog test bus.
 *
 * Values:
 * 0 - Disconnect the V rext node from the analog test bus.
 * 1 - Connect the V rext node to the analog test bus.
 */

#define BP_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT      (3)      //!< Bit position for HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT.
#define BM_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT      (0x00000008)  //!< Bit mask for HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT.

//! @brief Get value of HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT from a register value.
#define BG_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT(r)   (((r) & BM_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT) >> BP_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT.
#define BF_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT(v)   ((((reg16_t) v) << BP_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT) & BM_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT)
#else
//! @brief Format value for bitfield HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT.
#define BF_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT(v)   (((v) << BP_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT) & BM_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_ATB_ON_REXT field to a new value.
#define BW_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT(v)   (HW_HDMI_PHY_MEASCTRL_WR((HW_HDMI_PHY_MEASCTRL_RD() & ~BM_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT) | BF_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_VLEVCTRL - Voltage Level Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : VLEVCTRL  Access type : Read/write  Address : 0x0E  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_vlevctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_vlevctrl_bitfields
    {
        unsigned short SUP_CK_LVL : 5; //!< [4:0] Support Clock Level This bus controls the reference voltage level of the Clock Channel module. This voltage reference has a direct relation with the output signal voltage level. For more information about the driver voltage level configuration, see .
        unsigned short SUP_TX_LVL : 5; //!< [9:5] Support Transmitter Level This bus controls the reference voltage level of the three transmitter channel modules. This voltage reference has a direct relation with the output signal voltage level. For more information about the driver voltage level configuration, see .
        unsigned short RESERVED0 : 6; //!< [15:10] Reserved
    } B;
} hw_hdmi_phy_vlevctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_VLEVCTRL register
 */
#define HW_HDMI_PHY_VLEVCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xe)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_VLEVCTRL           (*(volatile hw_hdmi_phy_vlevctrl_t *) HW_HDMI_PHY_VLEVCTRL_ADDR)
#define HW_HDMI_PHY_VLEVCTRL_RD()      (HW_HDMI_PHY_VLEVCTRL.U)
#define HW_HDMI_PHY_VLEVCTRL_WR(v)     (HW_HDMI_PHY_VLEVCTRL.U = (v))
#define HW_HDMI_PHY_VLEVCTRL_SET(v)    (HW_HDMI_PHY_VLEVCTRL_WR(HW_HDMI_PHY_VLEVCTRL_RD() |  (v)))
#define HW_HDMI_PHY_VLEVCTRL_CLR(v)    (HW_HDMI_PHY_VLEVCTRL_WR(HW_HDMI_PHY_VLEVCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_VLEVCTRL_TOG(v)    (HW_HDMI_PHY_VLEVCTRL_WR(HW_HDMI_PHY_VLEVCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_VLEVCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_VLEVCTRL, field SUP_CK_LVL[4:0] (RW)
 *
 * Support Clock Level This bus controls the reference voltage level of the Clock Channel module.
 * This voltage reference has a direct relation with the output signal voltage level. For more
 * information about the driver voltage level configuration, see .
 */

#define BP_HDMI_PHY_VLEVCTRL_SUP_CK_LVL      (0)      //!< Bit position for HDMI_PHY_VLEVCTRL_SUP_CK_LVL.
#define BM_HDMI_PHY_VLEVCTRL_SUP_CK_LVL      (0x0000001f)  //!< Bit mask for HDMI_PHY_VLEVCTRL_SUP_CK_LVL.

//! @brief Get value of HDMI_PHY_VLEVCTRL_SUP_CK_LVL from a register value.
#define BG_HDMI_PHY_VLEVCTRL_SUP_CK_LVL(r)   (((r) & BM_HDMI_PHY_VLEVCTRL_SUP_CK_LVL) >> BP_HDMI_PHY_VLEVCTRL_SUP_CK_LVL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_VLEVCTRL_SUP_CK_LVL.
#define BF_HDMI_PHY_VLEVCTRL_SUP_CK_LVL(v)   ((((reg16_t) v) << BP_HDMI_PHY_VLEVCTRL_SUP_CK_LVL) & BM_HDMI_PHY_VLEVCTRL_SUP_CK_LVL)
#else
//! @brief Format value for bitfield HDMI_PHY_VLEVCTRL_SUP_CK_LVL.
#define BF_HDMI_PHY_VLEVCTRL_SUP_CK_LVL(v)   (((v) << BP_HDMI_PHY_VLEVCTRL_SUP_CK_LVL) & BM_HDMI_PHY_VLEVCTRL_SUP_CK_LVL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_CK_LVL field to a new value.
#define BW_HDMI_PHY_VLEVCTRL_SUP_CK_LVL(v)   (HW_HDMI_PHY_VLEVCTRL_WR((HW_HDMI_PHY_VLEVCTRL_RD() & ~BM_HDMI_PHY_VLEVCTRL_SUP_CK_LVL) | BF_HDMI_PHY_VLEVCTRL_SUP_CK_LVL(v)))
#endif

/* --- Register HW_HDMI_PHY_VLEVCTRL, field SUP_TX_LVL[9:5] (RW)
 *
 * Support Transmitter Level This bus controls the reference voltage level of the three transmitter
 * channel modules. This voltage reference has a direct relation with the output signal voltage
 * level. For more information about the driver voltage level configuration, see .
 */

#define BP_HDMI_PHY_VLEVCTRL_SUP_TX_LVL      (5)      //!< Bit position for HDMI_PHY_VLEVCTRL_SUP_TX_LVL.
#define BM_HDMI_PHY_VLEVCTRL_SUP_TX_LVL      (0x000003e0)  //!< Bit mask for HDMI_PHY_VLEVCTRL_SUP_TX_LVL.

//! @brief Get value of HDMI_PHY_VLEVCTRL_SUP_TX_LVL from a register value.
#define BG_HDMI_PHY_VLEVCTRL_SUP_TX_LVL(r)   (((r) & BM_HDMI_PHY_VLEVCTRL_SUP_TX_LVL) >> BP_HDMI_PHY_VLEVCTRL_SUP_TX_LVL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_VLEVCTRL_SUP_TX_LVL.
#define BF_HDMI_PHY_VLEVCTRL_SUP_TX_LVL(v)   ((((reg16_t) v) << BP_HDMI_PHY_VLEVCTRL_SUP_TX_LVL) & BM_HDMI_PHY_VLEVCTRL_SUP_TX_LVL)
#else
//! @brief Format value for bitfield HDMI_PHY_VLEVCTRL_SUP_TX_LVL.
#define BF_HDMI_PHY_VLEVCTRL_SUP_TX_LVL(v)   (((v) << BP_HDMI_PHY_VLEVCTRL_SUP_TX_LVL) & BM_HDMI_PHY_VLEVCTRL_SUP_TX_LVL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_TX_LVL field to a new value.
#define BW_HDMI_PHY_VLEVCTRL_SUP_TX_LVL(v)   (HW_HDMI_PHY_VLEVCTRL_WR((HW_HDMI_PHY_VLEVCTRL_RD() & ~BM_HDMI_PHY_VLEVCTRL_SUP_TX_LVL) | BF_HDMI_PHY_VLEVCTRL_SUP_TX_LVL(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_D2ACTRL - Digital-to-Analog Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : D2ACTRL  Access type : Read/write/override  Address : 0x0F  Value at reset :
 * 0x0000
 */
typedef union _hw_hdmi_phy_d2actrl
{
    reg16_t U;
    struct _hw_hdmi_phy_d2actrl_bitfields
    {
        unsigned short SUP_DAC_TH_N : 3; //!< [2:0] Support Digital-to-Analog Thermometer Inverted This bus value is inverted and defined in the thermometer code to represent the binary code of the two MSB's of the 9-bit DAC value. Note : To increase the stability of the DAC block, the two MSB's of the 9-bit DAC value are represented in thermometer code, not in binary code. The MSB's of the 9-bit DAC value is split into two thermometer-code bits. A transition from 0 to 1 of the 9-bit DAC value's MSB is represented by "00" -> "01" -> "11" in thermometer code.
        unsigned short SUP_DAC_N : 8; //!< [10:3] Support Analog-to-Digital Inverted This bus represents the LSB's of the 9-bit DAC value.
        unsigned short RESERVED0 : 4; //!< [14:11] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_d2actrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_D2ACTRL register
 */
#define HW_HDMI_PHY_D2ACTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xf)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_D2ACTRL           (*(volatile hw_hdmi_phy_d2actrl_t *) HW_HDMI_PHY_D2ACTRL_ADDR)
#define HW_HDMI_PHY_D2ACTRL_RD()      (HW_HDMI_PHY_D2ACTRL.U)
#define HW_HDMI_PHY_D2ACTRL_WR(v)     (HW_HDMI_PHY_D2ACTRL.U = (v))
#define HW_HDMI_PHY_D2ACTRL_SET(v)    (HW_HDMI_PHY_D2ACTRL_WR(HW_HDMI_PHY_D2ACTRL_RD() |  (v)))
#define HW_HDMI_PHY_D2ACTRL_CLR(v)    (HW_HDMI_PHY_D2ACTRL_WR(HW_HDMI_PHY_D2ACTRL_RD() & ~(v)))
#define HW_HDMI_PHY_D2ACTRL_TOG(v)    (HW_HDMI_PHY_D2ACTRL_WR(HW_HDMI_PHY_D2ACTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_D2ACTRL bitfields
 */

/* --- Register HW_HDMI_PHY_D2ACTRL, field SUP_DAC_TH_N[2:0] (RW)
 *
 * Support Digital-to-Analog Thermometer Inverted This bus value is inverted and defined in the
 * thermometer code to represent the binary code of the two MSB's of the 9-bit DAC value. Note : To
 * increase the stability of the DAC block, the two MSB's of the 9-bit DAC value are represented in
 * thermometer code, not in binary code. The MSB's of the 9-bit DAC value is split into two
 * thermometer-code bits. A transition from 0 to 1 of the 9-bit DAC value's MSB is represented by
 * "00" -> "01" -> "11" in thermometer code.
 */

#define BP_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N      (0)      //!< Bit position for HDMI_PHY_D2ACTRL_SUP_DAC_TH_N.
#define BM_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N      (0x00000007)  //!< Bit mask for HDMI_PHY_D2ACTRL_SUP_DAC_TH_N.

//! @brief Get value of HDMI_PHY_D2ACTRL_SUP_DAC_TH_N from a register value.
#define BG_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N(r)   (((r) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N) >> BP_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_D2ACTRL_SUP_DAC_TH_N.
#define BF_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N(v)   ((((reg16_t) v) << BP_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N)
#else
//! @brief Format value for bitfield HDMI_PHY_D2ACTRL_SUP_DAC_TH_N.
#define BF_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N(v)   (((v) << BP_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_DAC_TH_N field to a new value.
#define BW_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N(v)   (HW_HDMI_PHY_D2ACTRL_WR((HW_HDMI_PHY_D2ACTRL_RD() & ~BM_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N) | BF_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N(v)))
#endif

/* --- Register HW_HDMI_PHY_D2ACTRL, field SUP_DAC_N[10:3] (RW)
 *
 * Support Analog-to-Digital Inverted This bus represents the LSB's of the 9-bit DAC value.
 */

#define BP_HDMI_PHY_D2ACTRL_SUP_DAC_N      (3)      //!< Bit position for HDMI_PHY_D2ACTRL_SUP_DAC_N.
#define BM_HDMI_PHY_D2ACTRL_SUP_DAC_N      (0x000007f8)  //!< Bit mask for HDMI_PHY_D2ACTRL_SUP_DAC_N.

//! @brief Get value of HDMI_PHY_D2ACTRL_SUP_DAC_N from a register value.
#define BG_HDMI_PHY_D2ACTRL_SUP_DAC_N(r)   (((r) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_N) >> BP_HDMI_PHY_D2ACTRL_SUP_DAC_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_D2ACTRL_SUP_DAC_N.
#define BF_HDMI_PHY_D2ACTRL_SUP_DAC_N(v)   ((((reg16_t) v) << BP_HDMI_PHY_D2ACTRL_SUP_DAC_N) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_N)
#else
//! @brief Format value for bitfield HDMI_PHY_D2ACTRL_SUP_DAC_N.
#define BF_HDMI_PHY_D2ACTRL_SUP_DAC_N(v)   (((v) << BP_HDMI_PHY_D2ACTRL_SUP_DAC_N) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUP_DAC_N field to a new value.
#define BW_HDMI_PHY_D2ACTRL_SUP_DAC_N(v)   (HW_HDMI_PHY_D2ACTRL_WR((HW_HDMI_PHY_D2ACTRL_RD() & ~BM_HDMI_PHY_D2ACTRL_SUP_DAC_N) | BF_HDMI_PHY_D2ACTRL_SUP_DAC_N(v)))
#endif

/* --- Register HW_HDMI_PHY_D2ACTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_D2ACTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_D2ACTRL_OVERRIDE.
#define BM_HDMI_PHY_D2ACTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_D2ACTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_D2ACTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_D2ACTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_D2ACTRL_OVERRIDE) >> BP_HDMI_PHY_D2ACTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_D2ACTRL_OVERRIDE.
#define BF_HDMI_PHY_D2ACTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_D2ACTRL_OVERRIDE) & BM_HDMI_PHY_D2ACTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_D2ACTRL_OVERRIDE.
#define BF_HDMI_PHY_D2ACTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_D2ACTRL_OVERRIDE) & BM_HDMI_PHY_D2ACTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_D2ACTRL_OVERRIDE(v)   (HW_HDMI_PHY_D2ACTRL_WR((HW_HDMI_PHY_D2ACTRL_RD() & ~BM_HDMI_PHY_D2ACTRL_OVERRIDE) | BF_HDMI_PHY_D2ACTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_CURRCTRL - Current Control (RW)
 *
 * Reset value: 0x000008ab
 *
 * Register name : CURRCTRL  Access type : Read/write  Address : 0x10  Value at reset : 0x08AB
 */
typedef union _hw_hdmi_phy_currctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_currctrl_bitfields
    {
        unsigned short PLL_INT_CNTRL : 3; //!< [2:0] PLL Charge Pump Integral Control This bus controls the PLL charge pump integral current. Eight levels of charge pump integral current value are possible. The specific values are defined in . Default (reset) value of pll_int_cntrl[2:0] is 100.
        unsigned short PLL_PROP_CNTRL : 3; //!< [5:3] PLL Proportional Control This bus controls the PLL charge pump proportional current. Eight levels of charge pump proportional current value are possible. The specific values are defined in . Default (reset) value of pll_int_cntrl is 011.
        unsigned short MPLL_INT_CNTRL : 3; //!< [8:6] MPLL Integral Control This bus controls the charge pump integral current. Eight levels of charge pump integral current value are possible. The specific values are defined in . Default (reset) value of pll_int_cntrl[1:0] is 100.
        unsigned short MPLL_PROP_CNTRL : 3; //!< [11:9] MPLL Proportional Control This bus controls the MPLL charge pump proportional current. Eight levels of charge pump proportional current value are possible. The specific values are defined in . Default (reset) value of pll_prop_cntrl[1:0] is 100.
        unsigned short RESERVED0 : 4; //!< [15:12] Reserved
    } B;
} hw_hdmi_phy_currctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CURRCTRL register
 */
#define HW_HDMI_PHY_CURRCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CURRCTRL           (*(volatile hw_hdmi_phy_currctrl_t *) HW_HDMI_PHY_CURRCTRL_ADDR)
#define HW_HDMI_PHY_CURRCTRL_RD()      (HW_HDMI_PHY_CURRCTRL.U)
#define HW_HDMI_PHY_CURRCTRL_WR(v)     (HW_HDMI_PHY_CURRCTRL.U = (v))
#define HW_HDMI_PHY_CURRCTRL_SET(v)    (HW_HDMI_PHY_CURRCTRL_WR(HW_HDMI_PHY_CURRCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CURRCTRL_CLR(v)    (HW_HDMI_PHY_CURRCTRL_WR(HW_HDMI_PHY_CURRCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CURRCTRL_TOG(v)    (HW_HDMI_PHY_CURRCTRL_WR(HW_HDMI_PHY_CURRCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_CURRCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CURRCTRL, field PLL_INT_CNTRL[2:0] (RW)
 *
 * PLL Charge Pump Integral Control This bus controls the PLL charge pump integral current. Eight
 * levels of charge pump integral current value are possible. The specific values are defined in .
 * Default (reset) value of pll_int_cntrl[2:0] is 100.
 */

#define BP_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL      (0)      //!< Bit position for HDMI_PHY_CURRCTRL_PLL_INT_CNTRL.
#define BM_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL      (0x00000007)  //!< Bit mask for HDMI_PHY_CURRCTRL_PLL_INT_CNTRL.

//! @brief Get value of HDMI_PHY_CURRCTRL_PLL_INT_CNTRL from a register value.
#define BG_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL(r)   (((r) & BM_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL) >> BP_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CURRCTRL_PLL_INT_CNTRL.
#define BF_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL(v)   ((((reg16_t) v) << BP_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL) & BM_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL)
#else
//! @brief Format value for bitfield HDMI_PHY_CURRCTRL_PLL_INT_CNTRL.
#define BF_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL(v)   (((v) << BP_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL) & BM_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_INT_CNTRL field to a new value.
#define BW_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL(v)   (HW_HDMI_PHY_CURRCTRL_WR((HW_HDMI_PHY_CURRCTRL_RD() & ~BM_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL) | BF_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL(v)))
#endif

/* --- Register HW_HDMI_PHY_CURRCTRL, field PLL_PROP_CNTRL[5:3] (RW)
 *
 * PLL Proportional Control This bus controls the PLL charge pump proportional current. Eight levels
 * of charge pump proportional current value are possible. The specific values are defined in .
 * Default (reset) value of pll_int_cntrl is 011.
 */

#define BP_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL      (3)      //!< Bit position for HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL.
#define BM_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL      (0x00000038)  //!< Bit mask for HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL.

//! @brief Get value of HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL from a register value.
#define BG_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL(r)   (((r) & BM_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL) >> BP_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL.
#define BF_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL(v)   ((((reg16_t) v) << BP_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL) & BM_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL)
#else
//! @brief Format value for bitfield HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL.
#define BF_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL(v)   (((v) << BP_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL) & BM_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_PROP_CNTRL field to a new value.
#define BW_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL(v)   (HW_HDMI_PHY_CURRCTRL_WR((HW_HDMI_PHY_CURRCTRL_RD() & ~BM_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL) | BF_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL(v)))
#endif

/* --- Register HW_HDMI_PHY_CURRCTRL, field MPLL_INT_CNTRL[8:6] (RW)
 *
 * MPLL Integral Control This bus controls the charge pump integral current. Eight levels of charge
 * pump integral current value are possible. The specific values are defined in . Default (reset)
 * value of pll_int_cntrl[1:0] is 100.
 */

#define BP_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL      (6)      //!< Bit position for HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL.
#define BM_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL      (0x000001c0)  //!< Bit mask for HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL.

//! @brief Get value of HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL from a register value.
#define BG_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL(r)   (((r) & BM_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL) >> BP_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL.
#define BF_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL(v)   ((((reg16_t) v) << BP_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL) & BM_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL)
#else
//! @brief Format value for bitfield HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL.
#define BF_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL(v)   (((v) << BP_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL) & BM_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_INT_CNTRL field to a new value.
#define BW_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL(v)   (HW_HDMI_PHY_CURRCTRL_WR((HW_HDMI_PHY_CURRCTRL_RD() & ~BM_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL) | BF_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL(v)))
#endif

/* --- Register HW_HDMI_PHY_CURRCTRL, field MPLL_PROP_CNTRL[11:9] (RW)
 *
 * MPLL Proportional Control This bus controls the MPLL charge pump proportional current. Eight
 * levels of charge pump proportional current value are possible. The specific values are defined in
 * . Default (reset) value of pll_prop_cntrl[1:0] is 100.
 */

#define BP_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL      (9)      //!< Bit position for HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL.
#define BM_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL      (0x00000e00)  //!< Bit mask for HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL.

//! @brief Get value of HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL from a register value.
#define BG_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL(r)   (((r) & BM_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL) >> BP_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL.
#define BF_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL(v)   ((((reg16_t) v) << BP_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL) & BM_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL)
#else
//! @brief Format value for bitfield HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL.
#define BF_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL(v)   (((v) << BP_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL) & BM_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_PROP_CNTRL field to a new value.
#define BW_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL(v)   (HW_HDMI_PHY_CURRCTRL_WR((HW_HDMI_PHY_CURRCTRL_RD() & ~BM_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL) | BF_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_DRVANACTRL - Drive Analog Control (RW)
 *
 * Reset value: 0x00000003
 *
 * Register name : DRVANACTRL  Access type : Read/write/override  Address : 0x11  Value at reset :
 * 0x0003
 */
typedef union _hw_hdmi_phy_drvanactrl
{
    reg16_t U;
    struct _hw_hdmi_phy_drvanactrl_bitfields
    {
        unsigned short MPLL_DRV_ANA : 1; //!< [0] MPLL Drive Analog This bit enables or disables driving the ck_ref_p/m clocks to all transmitters (tx_topa). Default (reset) value of mpll_drv_ana is 1.
        unsigned short PLL_DRV_ANA : 1; //!< [1] PLL Drive Analog This bit enables or disables driving the ck_ref_mpll_p/m clocks to the MPLL module. Default (reset) value of pll_drv_ana is 1.
        unsigned short RESERVED0 : 13; //!< [14:2] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_drvanactrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_DRVANACTRL register
 */
#define HW_HDMI_PHY_DRVANACTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x11)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_DRVANACTRL           (*(volatile hw_hdmi_phy_drvanactrl_t *) HW_HDMI_PHY_DRVANACTRL_ADDR)
#define HW_HDMI_PHY_DRVANACTRL_RD()      (HW_HDMI_PHY_DRVANACTRL.U)
#define HW_HDMI_PHY_DRVANACTRL_WR(v)     (HW_HDMI_PHY_DRVANACTRL.U = (v))
#define HW_HDMI_PHY_DRVANACTRL_SET(v)    (HW_HDMI_PHY_DRVANACTRL_WR(HW_HDMI_PHY_DRVANACTRL_RD() |  (v)))
#define HW_HDMI_PHY_DRVANACTRL_CLR(v)    (HW_HDMI_PHY_DRVANACTRL_WR(HW_HDMI_PHY_DRVANACTRL_RD() & ~(v)))
#define HW_HDMI_PHY_DRVANACTRL_TOG(v)    (HW_HDMI_PHY_DRVANACTRL_WR(HW_HDMI_PHY_DRVANACTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_DRVANACTRL bitfields
 */

/* --- Register HW_HDMI_PHY_DRVANACTRL, field MPLL_DRV_ANA[0] (RW)
 *
 * MPLL Drive Analog This bit enables or disables driving the ck_ref_p/m clocks to all transmitters
 * (tx_topa). Default (reset) value of mpll_drv_ana is 1.
 *
 * Values:
 * 0 - Set ck_ref_p high; ck_ref_m low, if the Override bit is 0.
 * 1 - Enable ck_ref_mpll output clock (125-1700 MHz ck_ref_p/m) to be driven to all transmitters
 *     (tx_topa), if the Override bit is 0.
 */

#define BP_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA      (0)      //!< Bit position for HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA.
#define BM_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA      (0x00000001)  //!< Bit mask for HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA.

//! @brief Get value of HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA from a register value.
#define BG_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA(r)   (((r) & BM_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA) >> BP_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA.
#define BF_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA(v)   ((((reg16_t) v) << BP_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA) & BM_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA)
#else
//! @brief Format value for bitfield HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA.
#define BF_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA(v)   (((v) << BP_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA) & BM_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_DRV_ANA field to a new value.
#define BW_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA(v)   (HW_HDMI_PHY_DRVANACTRL_WR((HW_HDMI_PHY_DRVANACTRL_RD() & ~BM_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA) | BF_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA(v)))
#endif


/* --- Register HW_HDMI_PHY_DRVANACTRL, field PLL_DRV_ANA[1] (RW)
 *
 * PLL Drive Analog This bit enables or disables driving the ck_ref_mpll_p/m clocks to the MPLL
 * module. Default (reset) value of pll_drv_ana is 1.
 *
 * Values:
 * 0 - Set ck_ref_mpll low, if the Override bit is 0.
 * 1 - Enable 25-340 MHz output clock (ck_ref_mpll_p/m) to be driven to MPLL, if the Override bit is 0.
 */

#define BP_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA      (1)      //!< Bit position for HDMI_PHY_DRVANACTRL_PLL_DRV_ANA.
#define BM_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA      (0x00000002)  //!< Bit mask for HDMI_PHY_DRVANACTRL_PLL_DRV_ANA.

//! @brief Get value of HDMI_PHY_DRVANACTRL_PLL_DRV_ANA from a register value.
#define BG_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA(r)   (((r) & BM_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA) >> BP_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DRVANACTRL_PLL_DRV_ANA.
#define BF_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA(v)   ((((reg16_t) v) << BP_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA) & BM_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA)
#else
//! @brief Format value for bitfield HDMI_PHY_DRVANACTRL_PLL_DRV_ANA.
#define BF_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA(v)   (((v) << BP_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA) & BM_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_DRV_ANA field to a new value.
#define BW_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA(v)   (HW_HDMI_PHY_DRVANACTRL_WR((HW_HDMI_PHY_DRVANACTRL_RD() & ~BM_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA) | BF_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA(v)))
#endif


/* --- Register HW_HDMI_PHY_DRVANACTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_DRVANACTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_DRVANACTRL_OVERRIDE.
#define BM_HDMI_PHY_DRVANACTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_DRVANACTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_DRVANACTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_DRVANACTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_DRVANACTRL_OVERRIDE) >> BP_HDMI_PHY_DRVANACTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DRVANACTRL_OVERRIDE.
#define BF_HDMI_PHY_DRVANACTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_DRVANACTRL_OVERRIDE) & BM_HDMI_PHY_DRVANACTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_DRVANACTRL_OVERRIDE.
#define BF_HDMI_PHY_DRVANACTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_DRVANACTRL_OVERRIDE) & BM_HDMI_PHY_DRVANACTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_DRVANACTRL_OVERRIDE(v)   (HW_HDMI_PHY_DRVANACTRL_WR((HW_HDMI_PHY_DRVANACTRL_RD() & ~BM_HDMI_PHY_DRVANACTRL_OVERRIDE) | BF_HDMI_PHY_DRVANACTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_PLLMEASCTRL - PLL Measure Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : PLLMEASCTRL  Access type : Read/write  Address : 0x12  Value at reset : 0x0000
 * With the exception of pll_atb_sense_sel and pll_meas_iv[9], two or more of the previous register
 * bits must not be set to 1 simultaneously; doing so can lead to a hardware problem.  The table
 * below describes the pll_meas_iv[10:0] bit settings.   pll_meas_iv[10:0]        Effective Bit
 * Pll_meas_iv[10:0] Value  Description    Pll_meas_iv[0]  00000000001  Not used.    Pll_meas_iv[1]
 * 00000000010  Not used in pll_top. Connected to fast_tech pins of PLL and MPLL in hdmi_topa.
 * Pll_meas_iv[2]  00000000100  Connects VP supply voltage to the atb_sense line.    Pll_meas_iv[3]
 * 00000001000  Connects vp_cp to the atb_sense line.    Pll_meas_iv[4]  00000010000  Connects
 * internal supply voltage of the VCO (ivco) to the atb_sense line.    Pll_meas_iv[5]  00000100000
 * Connects vp_cko voltage to the atb_sense line.    Pll_meas_iv[6]  00001000000  Connects node vpsf
 * to the atb_sense line.    Pll_meas_iv[7]  00010000000  Connects vref to atb_sense line.
 * Pll_meas_iv[8]  00100000000  Connects vcntrl to atb_sense line.    Pll_meas_iv[9]  01000000000
 * Enables the phase mixer and pll_cko_pm_p/m.    Pll_meas_iv[10]  10000000000  Measures the voltage
 * corresponding to the output phase of the clr_dpth divider (fb_clk) with respect to refclk.
 */
typedef union _hw_hdmi_phy_pllmeasctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_pllmeasctrl_bitfields
    {
        unsigned short PLL_MEAS_GD : 1; //!< [0] PLL Measure Ground This bit connects or disconnects the ground signal to the atb_sense (analog test bus) bus.
        unsigned short PLL_MEAS_IV : 11; //!< [11:1] PLL Measure Internal Voltage This bus enables or disables measuring various PLL node voltages and branch currents. For information about the bit settings, see the pll_meas_iv[10:0] table.
        unsigned short PLL_ATB_SENSE_SEL : 1; //!< [12] PLL Analog Test Bus Sense Select This bit enables or disables internal signals of the PLL to be connected to the analog test bus. Without setting this bit, no measurements can be made on the atb_sense line. Default (reset) value of pll_atb_sense_sel is 0.
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved
    } B;
} hw_hdmi_phy_pllmeasctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PLLMEASCTRL register
 */
#define HW_HDMI_PHY_PLLMEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x12)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PLLMEASCTRL           (*(volatile hw_hdmi_phy_pllmeasctrl_t *) HW_HDMI_PHY_PLLMEASCTRL_ADDR)
#define HW_HDMI_PHY_PLLMEASCTRL_RD()      (HW_HDMI_PHY_PLLMEASCTRL.U)
#define HW_HDMI_PHY_PLLMEASCTRL_WR(v)     (HW_HDMI_PHY_PLLMEASCTRL.U = (v))
#define HW_HDMI_PHY_PLLMEASCTRL_SET(v)    (HW_HDMI_PHY_PLLMEASCTRL_WR(HW_HDMI_PHY_PLLMEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_PLLMEASCTRL_CLR(v)    (HW_HDMI_PHY_PLLMEASCTRL_WR(HW_HDMI_PHY_PLLMEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_PLLMEASCTRL_TOG(v)    (HW_HDMI_PHY_PLLMEASCTRL_WR(HW_HDMI_PHY_PLLMEASCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_PLLMEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_PLLMEASCTRL, field PLL_MEAS_GD[0] (RW)
 *
 * PLL Measure Ground This bit connects or disconnects the ground signal to the atb_sense (analog
 * test bus) bus.
 *
 * Values:
 * 0 - Disconnect the ground signal from the atb_sense bus.
 * 1 - Connect the ground signal to the atb_sense bus.
 */

#define BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD      (0)      //!< Bit position for HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD.
#define BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD      (0x00000001)  //!< Bit mask for HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD.

//! @brief Get value of HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD from a register value.
#define BG_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD(r)   (((r) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD) >> BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD.
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD(v)   ((((reg16_t) v) << BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD)
#else
//! @brief Format value for bitfield HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD.
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD(v)   (((v) << BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_MEAS_GD field to a new value.
#define BW_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD(v)   (HW_HDMI_PHY_PLLMEASCTRL_WR((HW_HDMI_PHY_PLLMEASCTRL_RD() & ~BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD) | BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD(v)))
#endif


/* --- Register HW_HDMI_PHY_PLLMEASCTRL, field PLL_MEAS_IV[11:1] (RW)
 *
 * PLL Measure Internal Voltage This bus enables or disables measuring various PLL node voltages and
 * branch currents. For information about the bit settings, see the pll_meas_iv[10:0] table.
 */

#define BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV      (1)      //!< Bit position for HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV.
#define BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV      (0x00000ffe)  //!< Bit mask for HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV.

//! @brief Get value of HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV from a register value.
#define BG_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV(r)   (((r) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV) >> BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV.
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV(v)   ((((reg16_t) v) << BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV)
#else
//! @brief Format value for bitfield HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV.
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV(v)   (((v) << BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_MEAS_IV field to a new value.
#define BW_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV(v)   (HW_HDMI_PHY_PLLMEASCTRL_WR((HW_HDMI_PHY_PLLMEASCTRL_RD() & ~BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV) | BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV(v)))
#endif

/* --- Register HW_HDMI_PHY_PLLMEASCTRL, field PLL_ATB_SENSE_SEL[12] (RW)
 *
 * PLL Analog Test Bus Sense Select This bit enables or disables internal signals of the PLL to be
 * connected to the analog test bus. Without setting this bit, no measurements can be made on the
 * atb_sense line. Default (reset) value of pll_atb_sense_sel is 0.
 *
 * Values:
 * 0 - Disable the ability to measure internal DC signals on the atb_sense line in the PLL.
 * 1 - Enable the ability to measure internal DC signals on the atb_sense line in the PLL.
 */

#define BP_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL      (12)      //!< Bit position for HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL.
#define BM_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL      (0x00001000)  //!< Bit mask for HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL.

//! @brief Get value of HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL from a register value.
#define BG_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL(r)   (((r) & BM_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL) >> BP_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL.
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL(v)   ((((reg16_t) v) << BP_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL) & BM_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL)
#else
//! @brief Format value for bitfield HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL.
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL(v)   (((v) << BP_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL) & BM_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_ATB_SENSE_SEL field to a new value.
#define BW_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL(v)   (HW_HDMI_PHY_PLLMEASCTRL_WR((HW_HDMI_PHY_PLLMEASCTRL_RD() & ~BM_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL) | BF_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_PLLPHBYCTRL - PLL Phase and Bypass Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : PLLPHBYCTRL  Access type : Read/write  Address : 0x13  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_pllphbyctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_pllphbyctrl_bitfields
    {
        unsigned short PLL_PH_SEL : 10; //!< [9:0] PLL Phase Select This bus is a control word for the PLL's phase mixer that enables the phase of pll_cko_pm_p/m to be varied ± 0.5 UI of the VCO frequency, which is 740-1,480 MHz.
        unsigned short PLL_PH_SEL_CK : 1; //!< [10] PLL Phase Select Clock This bit enables or disables latching the ph_sel[9:0] into a 9-bit DAC used in the phase mixer.
        unsigned short BYPASS_PPLL : 1; //!< [11] Bypass Pre-PLL This bit enables or disables bypassing the pre-PLL.
        unsigned short RESERVED0 : 4; //!< [15:12] Reserved
    } B;
} hw_hdmi_phy_pllphbyctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PLLPHBYCTRL register
 */
#define HW_HDMI_PHY_PLLPHBYCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x13)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PLLPHBYCTRL           (*(volatile hw_hdmi_phy_pllphbyctrl_t *) HW_HDMI_PHY_PLLPHBYCTRL_ADDR)
#define HW_HDMI_PHY_PLLPHBYCTRL_RD()      (HW_HDMI_PHY_PLLPHBYCTRL.U)
#define HW_HDMI_PHY_PLLPHBYCTRL_WR(v)     (HW_HDMI_PHY_PLLPHBYCTRL.U = (v))
#define HW_HDMI_PHY_PLLPHBYCTRL_SET(v)    (HW_HDMI_PHY_PLLPHBYCTRL_WR(HW_HDMI_PHY_PLLPHBYCTRL_RD() |  (v)))
#define HW_HDMI_PHY_PLLPHBYCTRL_CLR(v)    (HW_HDMI_PHY_PLLPHBYCTRL_WR(HW_HDMI_PHY_PLLPHBYCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_PLLPHBYCTRL_TOG(v)    (HW_HDMI_PHY_PLLPHBYCTRL_WR(HW_HDMI_PHY_PLLPHBYCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_PLLPHBYCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_PLLPHBYCTRL, field PLL_PH_SEL[9:0] (RW)
 *
 * PLL Phase Select This bus is a control word for the PLL's phase mixer that enables the phase of
 * pll_cko_pm_p/m to be varied ± 0.5 UI of the VCO frequency, which is 740-1,480 MHz.
 */

#define BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL      (0)      //!< Bit position for HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL.
#define BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL      (0x000003ff)  //!< Bit mask for HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL.

//! @brief Get value of HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL from a register value.
#define BG_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL(r)   (((r) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL) >> BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL.
#define BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL(v)   ((((reg16_t) v) << BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL)
#else
//! @brief Format value for bitfield HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL.
#define BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL(v)   (((v) << BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_PH_SEL field to a new value.
#define BW_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL(v)   (HW_HDMI_PHY_PLLPHBYCTRL_WR((HW_HDMI_PHY_PLLPHBYCTRL_RD() & ~BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL) | BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL(v)))
#endif

/* --- Register HW_HDMI_PHY_PLLPHBYCTRL, field PLL_PH_SEL_CK[10] (RW)
 *
 * PLL Phase Select Clock This bit enables or disables latching the ph_sel[9:0] into a 9-bit DAC
 * used in the phase mixer.
 *
 * Values:
 * 0 - Disable latching the pll_ph_sel[9:0] into the 9-bit DAC.
 * 1 - Enable latching the pll_ph_sel[9:0] into the 9-bit DAC.
 */

#define BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK      (10)      //!< Bit position for HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK.
#define BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK      (0x00000400)  //!< Bit mask for HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK.

//! @brief Get value of HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK from a register value.
#define BG_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK(r)   (((r) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK) >> BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK.
#define BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK(v)   ((((reg16_t) v) << BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK)
#else
//! @brief Format value for bitfield HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK.
#define BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK(v)   (((v) << BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_PH_SEL_CK field to a new value.
#define BW_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK(v)   (HW_HDMI_PHY_PLLPHBYCTRL_WR((HW_HDMI_PHY_PLLPHBYCTRL_RD() & ~BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK) | BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK(v)))
#endif


/* --- Register HW_HDMI_PHY_PLLPHBYCTRL, field BYPASS_PPLL[11] (RW)
 *
 * Bypass Pre-PLL This bit enables or disables bypassing the pre-PLL.
 *
 * Values:
 * 0 - Disable bypassing pll_top by forcing refclk_mpll_ref low.
 * 1 - Enable bypassing pll_top by buffering refclk to refclk_mpll_ref.
 */

#define BP_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL      (11)      //!< Bit position for HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL.
#define BM_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL      (0x00000800)  //!< Bit mask for HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL.

//! @brief Get value of HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL from a register value.
#define BG_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL(r)   (((r) & BM_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL) >> BP_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL.
#define BF_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL(v)   ((((reg16_t) v) << BP_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL) & BM_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL)
#else
//! @brief Format value for bitfield HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL.
#define BF_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL(v)   (((v) << BP_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL) & BM_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_PPLL field to a new value.
#define BW_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL(v)   (HW_HDMI_PHY_PLLPHBYCTRL_WR((HW_HDMI_PHY_PLLPHBYCTRL_RD() & ~BM_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL) | BF_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_GRP_CTRL - Gear Shift, Reset Mode, and Power State Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : -  Access type : Read/write/override  Address : 0x14  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_grp_ctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_grp_ctrl_bitfields
    {
        unsigned short MPLL_GEAR_SHIFT : 1; //!< [0] MPLL Gear Shift This bit enables or disables Rapid Locking mode, where the mpll_gear_shift bit is asserted for 25 µs when coming out of reset, then deasserted before clocks are valid.
        unsigned short PLL_GEAR_SHIFT : 1; //!< [1] PLL Gear Shift This bit enables or disables Rapid Locking mode, where the pll_gear_shift bit is asserted for 25 µs when coming out of reset, then deasserted before clocks are valid.
        unsigned short MPLL_RST : 1; //!< [2] MPLL Reset This bit is used to place the MPLL in Reset mode.
        unsigned short MPLL_PWR_ON : 1; //!< [3] MPLL Power-On This bit is used to power-on/off the MPLL module.
        unsigned short PLL_RST : 1; //!< [4] PLL Reset This bit is used to place the MPLL in Reset mode.
        unsigned short PLL_PWR_ON : 1; //!< [5] PLL Power-On This bit is used to power on/off the PLL module. Note: If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
        unsigned short RESERVED0 : 9; //!< [14:6] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_grp_ctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_GRP_CTRL register
 */
#define HW_HDMI_PHY_GRP_CTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_GRP_CTRL           (*(volatile hw_hdmi_phy_grp_ctrl_t *) HW_HDMI_PHY_GRP_CTRL_ADDR)
#define HW_HDMI_PHY_GRP_CTRL_RD()      (HW_HDMI_PHY_GRP_CTRL.U)
#define HW_HDMI_PHY_GRP_CTRL_WR(v)     (HW_HDMI_PHY_GRP_CTRL.U = (v))
#define HW_HDMI_PHY_GRP_CTRL_SET(v)    (HW_HDMI_PHY_GRP_CTRL_WR(HW_HDMI_PHY_GRP_CTRL_RD() |  (v)))
#define HW_HDMI_PHY_GRP_CTRL_CLR(v)    (HW_HDMI_PHY_GRP_CTRL_WR(HW_HDMI_PHY_GRP_CTRL_RD() & ~(v)))
#define HW_HDMI_PHY_GRP_CTRL_TOG(v)    (HW_HDMI_PHY_GRP_CTRL_WR(HW_HDMI_PHY_GRP_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_GRP_CTRL bitfields
 */

/* --- Register HW_HDMI_PHY_GRP_CTRL, field MPLL_GEAR_SHIFT[0] (RW)
 *
 * MPLL Gear Shift This bit enables or disables Rapid Locking mode, where the mpll_gear_shift bit is
 * asserted for 25 µs when coming out of reset, then deasserted before clocks are valid.
 *
 * Values:
 * 0 - Disable Rapid Locking mode, if the Override bit is 0.
 * 1 - Enable Rapid Locking mode, if the Override bit is 0.
 */

#define BP_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT      (0)      //!< Bit position for HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT.
#define BM_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT      (0x00000001)  //!< Bit mask for HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT.

//! @brief Get value of HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT from a register value.
#define BG_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT(r)   (((r) & BM_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT) >> BP_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT.
#define BF_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT(v)   ((((reg16_t) v) << BP_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT) & BM_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT)
#else
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT.
#define BF_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT(v)   (((v) << BP_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT) & BM_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_GEAR_SHIFT field to a new value.
#define BW_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT(v)   (HW_HDMI_PHY_GRP_CTRL_WR((HW_HDMI_PHY_GRP_CTRL_RD() & ~BM_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT) | BF_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT(v)))
#endif


/* --- Register HW_HDMI_PHY_GRP_CTRL, field PLL_GEAR_SHIFT[1] (RW)
 *
 * PLL Gear Shift This bit enables or disables Rapid Locking mode, where the pll_gear_shift bit is
 * asserted for 25 µs when coming out of reset, then deasserted before clocks are valid.
 *
 * Values:
 * 0 - Disable Rapid Locking mode, if the Override bit is 0.
 * 1 - Enable Rapid Locking mode, if the Override bit is 0.
 */

#define BP_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT      (1)      //!< Bit position for HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT.
#define BM_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT      (0x00000002)  //!< Bit mask for HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT.

//! @brief Get value of HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT from a register value.
#define BG_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT(r)   (((r) & BM_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT) >> BP_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT.
#define BF_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT(v)   ((((reg16_t) v) << BP_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT) & BM_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT)
#else
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT.
#define BF_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT(v)   (((v) << BP_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT) & BM_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_GEAR_SHIFT field to a new value.
#define BW_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT(v)   (HW_HDMI_PHY_GRP_CTRL_WR((HW_HDMI_PHY_GRP_CTRL_RD() & ~BM_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT) | BF_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT(v)))
#endif


/* --- Register HW_HDMI_PHY_GRP_CTRL, field MPLL_RST[2] (RW)
 *
 * MPLL Reset This bit is used to place the MPLL in Reset mode.
 *
 * Values:
 * 0 - Enable MPLL to operate normally, if the Override bit is 0.
 * 1 - Place the MPLL in Reset mode, if the Override bit is 0.
 */

#define BP_HDMI_PHY_GRP_CTRL_MPLL_RST      (2)      //!< Bit position for HDMI_PHY_GRP_CTRL_MPLL_RST.
#define BM_HDMI_PHY_GRP_CTRL_MPLL_RST      (0x00000004)  //!< Bit mask for HDMI_PHY_GRP_CTRL_MPLL_RST.

//! @brief Get value of HDMI_PHY_GRP_CTRL_MPLL_RST from a register value.
#define BG_HDMI_PHY_GRP_CTRL_MPLL_RST(r)   (((r) & BM_HDMI_PHY_GRP_CTRL_MPLL_RST) >> BP_HDMI_PHY_GRP_CTRL_MPLL_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_MPLL_RST.
#define BF_HDMI_PHY_GRP_CTRL_MPLL_RST(v)   ((((reg16_t) v) << BP_HDMI_PHY_GRP_CTRL_MPLL_RST) & BM_HDMI_PHY_GRP_CTRL_MPLL_RST)
#else
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_MPLL_RST.
#define BF_HDMI_PHY_GRP_CTRL_MPLL_RST(v)   (((v) << BP_HDMI_PHY_GRP_CTRL_MPLL_RST) & BM_HDMI_PHY_GRP_CTRL_MPLL_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_RST field to a new value.
#define BW_HDMI_PHY_GRP_CTRL_MPLL_RST(v)   (HW_HDMI_PHY_GRP_CTRL_WR((HW_HDMI_PHY_GRP_CTRL_RD() & ~BM_HDMI_PHY_GRP_CTRL_MPLL_RST) | BF_HDMI_PHY_GRP_CTRL_MPLL_RST(v)))
#endif


/* --- Register HW_HDMI_PHY_GRP_CTRL, field MPLL_PWR_ON[3] (RW)
 *
 * MPLL Power-On This bit is used to power-on/off the MPLL module.
 *
 * Values:
 * 0 - Power on MPLL and set all output clocks to DC levels, if the Override bit is 0.
 * 1 - Power off MPLL and enable it to operate normally, if the Override bit is 0.
 */

#define BP_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON      (3)      //!< Bit position for HDMI_PHY_GRP_CTRL_MPLL_PWR_ON.
#define BM_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON      (0x00000008)  //!< Bit mask for HDMI_PHY_GRP_CTRL_MPLL_PWR_ON.

//! @brief Get value of HDMI_PHY_GRP_CTRL_MPLL_PWR_ON from a register value.
#define BG_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON(r)   (((r) & BM_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON) >> BP_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_MPLL_PWR_ON.
#define BF_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON(v)   ((((reg16_t) v) << BP_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON) & BM_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON)
#else
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_MPLL_PWR_ON.
#define BF_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON(v)   (((v) << BP_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON) & BM_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_PWR_ON field to a new value.
#define BW_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON(v)   (HW_HDMI_PHY_GRP_CTRL_WR((HW_HDMI_PHY_GRP_CTRL_RD() & ~BM_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON) | BF_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON(v)))
#endif


/* --- Register HW_HDMI_PHY_GRP_CTRL, field PLL_RST[4] (RW)
 *
 * PLL Reset This bit is used to place the MPLL in Reset mode.
 *
 * Values:
 * 0 - Enable PLL to operate normally, if the Override bit is 0.
 * 1 - Place the PLL in Reset mode, if the Override bit is 0.
 */

#define BP_HDMI_PHY_GRP_CTRL_PLL_RST      (4)      //!< Bit position for HDMI_PHY_GRP_CTRL_PLL_RST.
#define BM_HDMI_PHY_GRP_CTRL_PLL_RST      (0x00000010)  //!< Bit mask for HDMI_PHY_GRP_CTRL_PLL_RST.

//! @brief Get value of HDMI_PHY_GRP_CTRL_PLL_RST from a register value.
#define BG_HDMI_PHY_GRP_CTRL_PLL_RST(r)   (((r) & BM_HDMI_PHY_GRP_CTRL_PLL_RST) >> BP_HDMI_PHY_GRP_CTRL_PLL_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_PLL_RST.
#define BF_HDMI_PHY_GRP_CTRL_PLL_RST(v)   ((((reg16_t) v) << BP_HDMI_PHY_GRP_CTRL_PLL_RST) & BM_HDMI_PHY_GRP_CTRL_PLL_RST)
#else
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_PLL_RST.
#define BF_HDMI_PHY_GRP_CTRL_PLL_RST(v)   (((v) << BP_HDMI_PHY_GRP_CTRL_PLL_RST) & BM_HDMI_PHY_GRP_CTRL_PLL_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_RST field to a new value.
#define BW_HDMI_PHY_GRP_CTRL_PLL_RST(v)   (HW_HDMI_PHY_GRP_CTRL_WR((HW_HDMI_PHY_GRP_CTRL_RD() & ~BM_HDMI_PHY_GRP_CTRL_PLL_RST) | BF_HDMI_PHY_GRP_CTRL_PLL_RST(v)))
#endif


/* --- Register HW_HDMI_PHY_GRP_CTRL, field PLL_PWR_ON[5] (RW)
 *
 * PLL Power-On This bit is used to power on/off the PLL module. Note: If the Override bit is set to
 * 1, the working value is the Override bit value, not the registered value.
 *
 * Values:
 * 0 - Power off PLL and draw minimal current, if the Override bit is 0.
 * 1 - Power on PLL and enable it to operate normally, if the Override bit is 0.
 */

#define BP_HDMI_PHY_GRP_CTRL_PLL_PWR_ON      (5)      //!< Bit position for HDMI_PHY_GRP_CTRL_PLL_PWR_ON.
#define BM_HDMI_PHY_GRP_CTRL_PLL_PWR_ON      (0x00000020)  //!< Bit mask for HDMI_PHY_GRP_CTRL_PLL_PWR_ON.

//! @brief Get value of HDMI_PHY_GRP_CTRL_PLL_PWR_ON from a register value.
#define BG_HDMI_PHY_GRP_CTRL_PLL_PWR_ON(r)   (((r) & BM_HDMI_PHY_GRP_CTRL_PLL_PWR_ON) >> BP_HDMI_PHY_GRP_CTRL_PLL_PWR_ON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_PLL_PWR_ON.
#define BF_HDMI_PHY_GRP_CTRL_PLL_PWR_ON(v)   ((((reg16_t) v) << BP_HDMI_PHY_GRP_CTRL_PLL_PWR_ON) & BM_HDMI_PHY_GRP_CTRL_PLL_PWR_ON)
#else
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_PLL_PWR_ON.
#define BF_HDMI_PHY_GRP_CTRL_PLL_PWR_ON(v)   (((v) << BP_HDMI_PHY_GRP_CTRL_PLL_PWR_ON) & BM_HDMI_PHY_GRP_CTRL_PLL_PWR_ON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_PWR_ON field to a new value.
#define BW_HDMI_PHY_GRP_CTRL_PLL_PWR_ON(v)   (HW_HDMI_PHY_GRP_CTRL_WR((HW_HDMI_PHY_GRP_CTRL_RD() & ~BM_HDMI_PHY_GRP_CTRL_PLL_PWR_ON) | BF_HDMI_PHY_GRP_CTRL_PLL_PWR_ON(v)))
#endif


/* --- Register HW_HDMI_PHY_GRP_CTRL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_GRP_CTRL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_GRP_CTRL_OVERRIDE.
#define BM_HDMI_PHY_GRP_CTRL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_GRP_CTRL_OVERRIDE.

//! @brief Get value of HDMI_PHY_GRP_CTRL_OVERRIDE from a register value.
#define BG_HDMI_PHY_GRP_CTRL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_GRP_CTRL_OVERRIDE) >> BP_HDMI_PHY_GRP_CTRL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_OVERRIDE.
#define BF_HDMI_PHY_GRP_CTRL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_GRP_CTRL_OVERRIDE) & BM_HDMI_PHY_GRP_CTRL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_GRP_CTRL_OVERRIDE.
#define BF_HDMI_PHY_GRP_CTRL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_GRP_CTRL_OVERRIDE) & BM_HDMI_PHY_GRP_CTRL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_GRP_CTRL_OVERRIDE(v)   (HW_HDMI_PHY_GRP_CTRL_WR((HW_HDMI_PHY_GRP_CTRL_RD() & ~BM_HDMI_PHY_GRP_CTRL_OVERRIDE) | BF_HDMI_PHY_GRP_CTRL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_GMPCTRL - Gmp Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : GMPCTRL  Access type : Read/write  Address : 0x15  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_gmpctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_gmpctrl_bitfields
    {
        unsigned short MPLL_GMP_CNTRL : 2; //!< [1:0] MPLL gmp Control This bus controls the effective loop-filter resistance (= 1/gmp) to increase or decrease MPLL bandwidth and to compensate for changes in the Divider module (n_cntrl).
        unsigned short PLL_GMP_CNTRL : 2; //!< [3:2] PLL gmp Control This bus controls the effective loop-filter resistance (equal) to increase or decrease PLL bandwidth and to compensate for changes in the Divider module (n_cntrl).
        unsigned short RESERVED0 : 12; //!< [15:4] Reserved
    } B;
} hw_hdmi_phy_gmpctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_GMPCTRL register
 */
#define HW_HDMI_PHY_GMPCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x15)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_GMPCTRL           (*(volatile hw_hdmi_phy_gmpctrl_t *) HW_HDMI_PHY_GMPCTRL_ADDR)
#define HW_HDMI_PHY_GMPCTRL_RD()      (HW_HDMI_PHY_GMPCTRL.U)
#define HW_HDMI_PHY_GMPCTRL_WR(v)     (HW_HDMI_PHY_GMPCTRL.U = (v))
#define HW_HDMI_PHY_GMPCTRL_SET(v)    (HW_HDMI_PHY_GMPCTRL_WR(HW_HDMI_PHY_GMPCTRL_RD() |  (v)))
#define HW_HDMI_PHY_GMPCTRL_CLR(v)    (HW_HDMI_PHY_GMPCTRL_WR(HW_HDMI_PHY_GMPCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_GMPCTRL_TOG(v)    (HW_HDMI_PHY_GMPCTRL_WR(HW_HDMI_PHY_GMPCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_GMPCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_GMPCTRL, field MPLL_GMP_CNTRL[1:0] (RW)
 *
 * MPLL gmp Control This bus controls the effective loop-filter resistance (= 1/gmp) to increase or
 * decrease MPLL bandwidth and to compensate for changes in the Divider module (n_cntrl).
 *
 * Values:
 * 00 - TMDS rate up to 45.25 MHz
 * 01 - TMDS rate of 45.26-92.5 MHz
 * 10 - TMDS rate of 92.51-185 MHz
 * 11 - TMDS rate of 184.1-370 MHz
 */

#define BP_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL      (0)      //!< Bit position for HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL.
#define BM_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL      (0x00000003)  //!< Bit mask for HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL.

//! @brief Get value of HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL from a register value.
#define BG_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL(r)   (((r) & BM_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL) >> BP_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL.
#define BF_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL(v)   ((((reg16_t) v) << BP_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL) & BM_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL)
#else
//! @brief Format value for bitfield HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL.
#define BF_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL(v)   (((v) << BP_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL) & BM_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_GMP_CNTRL field to a new value.
#define BW_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL(v)   (HW_HDMI_PHY_GMPCTRL_WR((HW_HDMI_PHY_GMPCTRL_RD() & ~BM_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL) | BF_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL(v)))
#endif


/* --- Register HW_HDMI_PHY_GMPCTRL, field PLL_GMP_CNTRL[3:2] (RW)
 *
 * PLL gmp Control This bus controls the effective loop-filter resistance (equal) to increase or
 * decrease PLL bandwidth and to compensate for changes in the Divider module (n_cntrl).
 *
 * Values:
 * 00 - TMDS rate up to 45.25 MHz
 * 01 - TMDS rate of 45.26-92.5 MHz
 * 10 - TMDS rate of 92.51-185 MHz
 * 11 - TMDS rate of 184.1-370 MHz
 */

#define BP_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL      (2)      //!< Bit position for HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL.
#define BM_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL      (0x0000000c)  //!< Bit mask for HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL.

//! @brief Get value of HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL from a register value.
#define BG_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL(r)   (((r) & BM_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL) >> BP_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL.
#define BF_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL(v)   ((((reg16_t) v) << BP_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL) & BM_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL)
#else
//! @brief Format value for bitfield HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL.
#define BF_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL(v)   (((v) << BP_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL) & BM_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_GMP_CNTRL field to a new value.
#define BW_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL(v)   (HW_HDMI_PHY_GMPCTRL_WR((HW_HDMI_PHY_GMPCTRL_RD() & ~BM_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL) | BF_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_MPLLMEASCTRL - MPLL Measure Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : MPLLMEASCTRL  Access type : Read/write  Address : 0x16  Value at reset : 0x0000
 * With the exception of mpll_atb_sense_sel, mpll_meas_iv[9], and mpll_meas_iv[11], two or more of
 * the previous register bits must not be set to 1 simultaneously, because doing so can lead to a
 * hardware problem.  The table below describes the mpll_meas_iv[11:0] bit settings.
 * mpll_meas_iv[11:0]        Effective Bit  mpll_meas_iv[11:0] Value  Description
 * mpll_meas_iv[0]  000000000001  Connects the internal positive DCC control line (vc0p) to the
 * atb_sense line.    mpll_meas_iv[1]  000000000010  Connects the internal negative DCC control line
 * (vc0m) to the atb_sense line.    mpll_meas_iv[2]  000000000100  Connects VP supply voltage to the
 * atb_sense line.    mpll_meas_iv[3]  000000001000  Connects vp_cp to the atb_sense line.
 * mpll_meas_iv[4]  000000010000  Connects the internal supply voltage of the VCO (ivco) to the
 * atb_sense line through a low-pass filter.    mpll_meas_iv[5]  000000100000  Connects the vp_cko
 * voltage to the atb_sense line.    mpll_meas_iv[6]  000001000000  Connects the vpsf node to the
 * atb_sense line.    mpll_meas_iv[7]  000010000000  Connects vref to the atb_sense line.
 * mpll_meas_iv[8]  000100000000  Connects vcntrl to the atb_sense line.    mpll_meas_iv[9]
 * 001000000000  Enables the phase mixer and cko_pm_p/m.    mpll_meas_iv[10]  010000000000  Measures
 * the voltage corresponding to the phase of the divide-by-5 output (fb_clk) with respect to the
 * phase of the mpll_ana input (ck_refclk_p).    mpll_meas_iv[11]  100000000000  Forces div_x1 low;
 * therefore, bitclk_p/m is multiplexed to ck_ref_p/m (normally, if n_cntrl = 00, ck0_p/m is
 * multiplexed to ck_ref_p/m and DCC loop is enabled.
 */
typedef union _hw_hdmi_phy_mpllmeasctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_mpllmeasctrl_bitfields
    {
        unsigned short MPLL_MEAS_GD : 1; //!< [0] MPLL Measure Ground This bit connects or disconnects the ground signal to the atb_sense (analog test bus) bus.
        unsigned short MPLL_MEAS_IV : 12; //!< [12:1] MPLL Measure Internal Voltage This bus enables or disables measuring various PLL node voltages and branch currents. For information about the bit settings, see the mpll_meas_iv[11:0] table.
        unsigned short MPLL_ATB_SENSE_SEL : 1; //!< [13] MPLL Analog Test Bus Sense Select This bit enables or disables internal signals of the PLL to be connected to the analog test bus. Without setting this bit, no measurements can be made on the atb_sense line. Default (reset) value of mpll_atb_sense_sel is 0.
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved
    } B;
} hw_hdmi_phy_mpllmeasctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_MPLLMEASCTRL register
 */
#define HW_HDMI_PHY_MPLLMEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x16)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_MPLLMEASCTRL           (*(volatile hw_hdmi_phy_mpllmeasctrl_t *) HW_HDMI_PHY_MPLLMEASCTRL_ADDR)
#define HW_HDMI_PHY_MPLLMEASCTRL_RD()      (HW_HDMI_PHY_MPLLMEASCTRL.U)
#define HW_HDMI_PHY_MPLLMEASCTRL_WR(v)     (HW_HDMI_PHY_MPLLMEASCTRL.U = (v))
#define HW_HDMI_PHY_MPLLMEASCTRL_SET(v)    (HW_HDMI_PHY_MPLLMEASCTRL_WR(HW_HDMI_PHY_MPLLMEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_MPLLMEASCTRL_CLR(v)    (HW_HDMI_PHY_MPLLMEASCTRL_WR(HW_HDMI_PHY_MPLLMEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_MPLLMEASCTRL_TOG(v)    (HW_HDMI_PHY_MPLLMEASCTRL_WR(HW_HDMI_PHY_MPLLMEASCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_MPLLMEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_MPLLMEASCTRL, field MPLL_MEAS_GD[0] (RW)
 *
 * MPLL Measure Ground This bit connects or disconnects the ground signal to the atb_sense (analog
 * test bus) bus.
 *
 * Values:
 * 0 - Disconnect the ground signal from the atb_sense bus.
 * 1 - Connect the ground signal to the atb_sense bus.
 */

#define BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD      (0)      //!< Bit position for HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD.
#define BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD      (0x00000001)  //!< Bit mask for HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD.

//! @brief Get value of HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD from a register value.
#define BG_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD(r)   (((r) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD) >> BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD.
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD(v)   ((((reg16_t) v) << BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD)
#else
//! @brief Format value for bitfield HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD.
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD(v)   (((v) << BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_MEAS_GD field to a new value.
#define BW_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD(v)   (HW_HDMI_PHY_MPLLMEASCTRL_WR((HW_HDMI_PHY_MPLLMEASCTRL_RD() & ~BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD) | BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD(v)))
#endif


/* --- Register HW_HDMI_PHY_MPLLMEASCTRL, field MPLL_MEAS_IV[12:1] (RW)
 *
 * MPLL Measure Internal Voltage This bus enables or disables measuring various PLL node voltages
 * and branch currents. For information about the bit settings, see the mpll_meas_iv[11:0] table.
 */

#define BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV      (1)      //!< Bit position for HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV.
#define BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV      (0x00001ffe)  //!< Bit mask for HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV.

//! @brief Get value of HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV from a register value.
#define BG_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV(r)   (((r) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV) >> BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV.
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV(v)   ((((reg16_t) v) << BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV)
#else
//! @brief Format value for bitfield HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV.
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV(v)   (((v) << BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_MEAS_IV field to a new value.
#define BW_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV(v)   (HW_HDMI_PHY_MPLLMEASCTRL_WR((HW_HDMI_PHY_MPLLMEASCTRL_RD() & ~BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV) | BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV(v)))
#endif

/* --- Register HW_HDMI_PHY_MPLLMEASCTRL, field MPLL_ATB_SENSE_SEL[13] (RW)
 *
 * MPLL Analog Test Bus Sense Select This bit enables or disables internal signals of the PLL to be
 * connected to the analog test bus. Without setting this bit, no measurements can be made on the
 * atb_sense line. Default (reset) value of mpll_atb_sense_sel is 0.
 *
 * Values:
 * 0 - Disable the ability to measure internal DC signals on the atb_sense line in the PLL.
 * 1 - Enable the ability to measure internal DC signals on the atb_sense line in the PLL.
 */

#define BP_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL      (13)      //!< Bit position for HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL.
#define BM_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL      (0x00002000)  //!< Bit mask for HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL.

//! @brief Get value of HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL from a register value.
#define BG_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL(r)   (((r) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL) >> BP_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL.
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL(v)   ((((reg16_t) v) << BP_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL)
#else
//! @brief Format value for bitfield HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL.
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL(v)   (((v) << BP_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_ATB_SENSE_SEL field to a new value.
#define BW_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL(v)   (HW_HDMI_PHY_MPLLMEASCTRL_WR((HW_HDMI_PHY_MPLLMEASCTRL_RD() & ~BM_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL) | BF_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_MSM_CTRL - MPLL and PLL Phase, Scope Clock Select, and MUX Clock Control (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : -  Access type : Read/write  Address : 0x17  Value at reset : 0x0000  The table
 * below describes the cko_sel[1:0] bit settings. (The cko_sel[1:0] default value is 00.)
 * cko_sel[1:0]         cko_sel[1:0]  TMDS Clock Mode  PLL and MPLL Mode  Output TMDS Clock on TMDS
 * Channel      00  Non-Coherent  Normal  ck_ref_mpll_p/m (Pre-PLL out)    01  Off (PLL and MPLL are
 * both off)  Normal  Off (No output TMDS clock)    10  Test (PHY in test mode)  Normal  PCLK (Input
 * reference clock to HDMI 3D Tx PHY)    11  Coherent  Normal  fb_clk (MPLL feedback clock)    00
 * Off (PLL and MPLL are both off)  Bypass  Off (No output TMDS clock)    01  Off (PLL and MPLL are
 * both off)  Bypass  Off (No output TMDS clock)    10  Non-Coherent  Bypass  PCLK (Input reference
 * clock to HDMI 3D Tx PHY)    11  Coherent  Bypass  fb_clk (MPLL feedback clock)
 */
typedef union _hw_hdmi_phy_msm_ctrl
{
    reg16_t U;
    struct _hw_hdmi_phy_msm_ctrl_bitfields
    {
        unsigned short SCOPE_CK_SEL : 1; //!< [0] Scope Clock Select Selects the clock to connect to the scope clock signal: the differential pll_cko_p/m or the differential mpll_cko_p/m.
        unsigned short CKO_SEL : 2; //!< [2:1] Clock Output Select This bus selects the clock to be connected to the output TMDS clock channel. Notes: Normal mode: The color depth or pixel repetition is required, which means that the PLL is powered on (pll_pwr_on bit is set to 1) and the bypass_ppll bit is set to 0. Bypass mode: The color depth and the pixel repetition is not required, which means that the PLL is powered off (pll_pwr_on bit is set to 0) and the bypass_ppll bit is set to 1. For information about the cko_sel[1:0] bit settings and corresponding PLL/MPLL modes, see the cko_sel[1:0] table.
        unsigned short MPLL_PH_SEL : 10; //!< [12:3] MPLL Phase Select This bus is a control word for the MPLL's phase mixer and enables the phase of pll_cko_pm_p /m to be varied ± 0.5 UI of the VCO frequency, which has a range of 925-1,850 MHz.
        unsigned short MPLL_PH_SEL_CK : 1; //!< [13] MPLL Phase Select Clock This bit enables or disables latching ph_sel[9:0] into a 9-bit DAC used in the phase mixer.
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved
    } B;
} hw_hdmi_phy_msm_ctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_MSM_CTRL register
 */
#define HW_HDMI_PHY_MSM_CTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x17)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_MSM_CTRL           (*(volatile hw_hdmi_phy_msm_ctrl_t *) HW_HDMI_PHY_MSM_CTRL_ADDR)
#define HW_HDMI_PHY_MSM_CTRL_RD()      (HW_HDMI_PHY_MSM_CTRL.U)
#define HW_HDMI_PHY_MSM_CTRL_WR(v)     (HW_HDMI_PHY_MSM_CTRL.U = (v))
#define HW_HDMI_PHY_MSM_CTRL_SET(v)    (HW_HDMI_PHY_MSM_CTRL_WR(HW_HDMI_PHY_MSM_CTRL_RD() |  (v)))
#define HW_HDMI_PHY_MSM_CTRL_CLR(v)    (HW_HDMI_PHY_MSM_CTRL_WR(HW_HDMI_PHY_MSM_CTRL_RD() & ~(v)))
#define HW_HDMI_PHY_MSM_CTRL_TOG(v)    (HW_HDMI_PHY_MSM_CTRL_WR(HW_HDMI_PHY_MSM_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_MSM_CTRL bitfields
 */

/* --- Register HW_HDMI_PHY_MSM_CTRL, field SCOPE_CK_SEL[0] (RW)
 *
 * Scope Clock Select Selects the clock to connect to the scope clock signal: the differential
 * pll_cko_p/m or the differential mpll_cko_p/m.
 *
 * Values:
 * 0 - Connect the mpll_cko_pm_p/m to the clock scope (this clock has a range of 23.125-45.25 MHz) where
 *     the mpll_meas_iv[9] bit must be high.
 * 1 - Connect the pll_cko_pm_p/m to the clock scope (this clock has a range of 23.125-45.25 MHz) where the
 *     pll_meas_iv[9] bit must be high.
 */

#define BP_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL      (0)      //!< Bit position for HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL.
#define BM_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL      (0x00000001)  //!< Bit mask for HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL.

//! @brief Get value of HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL from a register value.
#define BG_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL(r)   (((r) & BM_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL) >> BP_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL.
#define BF_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL(v)   ((((reg16_t) v) << BP_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL) & BM_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL)
#else
//! @brief Format value for bitfield HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL.
#define BF_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL(v)   (((v) << BP_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL) & BM_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_CK_SEL field to a new value.
#define BW_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL(v)   (HW_HDMI_PHY_MSM_CTRL_WR((HW_HDMI_PHY_MSM_CTRL_RD() & ~BM_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL) | BF_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL(v)))
#endif


/* --- Register HW_HDMI_PHY_MSM_CTRL, field CKO_SEL[2:1] (RW)
 *
 * Clock Output Select This bus selects the clock to be connected to the output TMDS clock channel.
 * Notes: Normal mode: The color depth or pixel repetition is required, which means that the PLL is
 * powered on (pll_pwr_on bit is set to 1) and the bypass_ppll bit is set to 0. Bypass mode: The
 * color depth and the pixel repetition is not required, which means that the PLL is powered off
 * (pll_pwr_on bit is set to 0) and the bypass_ppll bit is set to 1. For information about the
 * cko_sel[1:0] bit settings and corresponding PLL/MPLL modes, see the cko_sel[1:0] table.
 */

#define BP_HDMI_PHY_MSM_CTRL_CKO_SEL      (1)      //!< Bit position for HDMI_PHY_MSM_CTRL_CKO_SEL.
#define BM_HDMI_PHY_MSM_CTRL_CKO_SEL      (0x00000006)  //!< Bit mask for HDMI_PHY_MSM_CTRL_CKO_SEL.

//! @brief Get value of HDMI_PHY_MSM_CTRL_CKO_SEL from a register value.
#define BG_HDMI_PHY_MSM_CTRL_CKO_SEL(r)   (((r) & BM_HDMI_PHY_MSM_CTRL_CKO_SEL) >> BP_HDMI_PHY_MSM_CTRL_CKO_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MSM_CTRL_CKO_SEL.
#define BF_HDMI_PHY_MSM_CTRL_CKO_SEL(v)   ((((reg16_t) v) << BP_HDMI_PHY_MSM_CTRL_CKO_SEL) & BM_HDMI_PHY_MSM_CTRL_CKO_SEL)
#else
//! @brief Format value for bitfield HDMI_PHY_MSM_CTRL_CKO_SEL.
#define BF_HDMI_PHY_MSM_CTRL_CKO_SEL(v)   (((v) << BP_HDMI_PHY_MSM_CTRL_CKO_SEL) & BM_HDMI_PHY_MSM_CTRL_CKO_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO_SEL field to a new value.
#define BW_HDMI_PHY_MSM_CTRL_CKO_SEL(v)   (HW_HDMI_PHY_MSM_CTRL_WR((HW_HDMI_PHY_MSM_CTRL_RD() & ~BM_HDMI_PHY_MSM_CTRL_CKO_SEL) | BF_HDMI_PHY_MSM_CTRL_CKO_SEL(v)))
#endif

/* --- Register HW_HDMI_PHY_MSM_CTRL, field MPLL_PH_SEL[12:3] (RW)
 *
 * MPLL Phase Select This bus is a control word for the MPLL's phase mixer and enables the phase of
 * pll_cko_pm_p /m to be varied ± 0.5 UI of the VCO frequency, which has a range of 925-1,850 MHz.
 */

#define BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL      (3)      //!< Bit position for HDMI_PHY_MSM_CTRL_MPLL_PH_SEL.
#define BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL      (0x00001ff8)  //!< Bit mask for HDMI_PHY_MSM_CTRL_MPLL_PH_SEL.

//! @brief Get value of HDMI_PHY_MSM_CTRL_MPLL_PH_SEL from a register value.
#define BG_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL(r)   (((r) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL) >> BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MSM_CTRL_MPLL_PH_SEL.
#define BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL(v)   ((((reg16_t) v) << BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL)
#else
//! @brief Format value for bitfield HDMI_PHY_MSM_CTRL_MPLL_PH_SEL.
#define BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL(v)   (((v) << BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_PH_SEL field to a new value.
#define BW_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL(v)   (HW_HDMI_PHY_MSM_CTRL_WR((HW_HDMI_PHY_MSM_CTRL_RD() & ~BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL) | BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL(v)))
#endif

/* --- Register HW_HDMI_PHY_MSM_CTRL, field MPLL_PH_SEL_CK[13] (RW)
 *
 * MPLL Phase Select Clock This bit enables or disables latching ph_sel[9:0] into a 9-bit DAC used
 * in the phase mixer.
 *
 * Values:
 * 0 - Disable latching mpll_ph_sel[9:0] into the 9-bit DAC.
 * 1 - Enable latching mpll_ph_sel[9:0] into the 9-bit DAC.
 */

#define BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK      (13)      //!< Bit position for HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK.
#define BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK      (0x00002000)  //!< Bit mask for HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK.

//! @brief Get value of HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK from a register value.
#define BG_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK(r)   (((r) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK) >> BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK.
#define BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK(v)   ((((reg16_t) v) << BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK)
#else
//! @brief Format value for bitfield HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK.
#define BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK(v)   (((v) << BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_PH_SEL_CK field to a new value.
#define BW_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK(v)   (HW_HDMI_PHY_MSM_CTRL_WR((HW_HDMI_PHY_MSM_CTRL_RD() & ~BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK) | BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCRPB_STATUS - Scope, Comparator Result and Power Bad Status (RO)
 *
 * Reset value: 0x00000000
 *
 * Register name : -  Access type : Read-only  Address : 0x18  Value at reset : N/A
 */
typedef union _hw_hdmi_phy_scrpb_status
{
    reg16_t U;
    struct _hw_hdmi_phy_scrpb_status_bitfields
    {
        unsigned short CK_SCOPE_OUT : 1; //!< [0] Clock Scope Output Signal
        unsigned short TX_SCOPE_OUT2 : 1; //!< [1] Scoping Value for Lane 2
        unsigned short TX_SCOPE_OUT1 : 1; //!< [2] Scoping Value for Lane 1
        unsigned short TX_SCOPE_OUT0 : 1; //!< [3] Scoping Value for Lane 0
        unsigned short SUP_COMP_RT_RESULT : 1; //!< [4] Support Comparator Resistance Termination Result This bit represents the result of the comparison process.
        unsigned short RESERVED0 : 1; //!< [5] Reserved
        unsigned short ADC_VAL : 10; //!< [15:6] ADC/DAC bit word (analog signal value)
    } B;
} hw_hdmi_phy_scrpb_status_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCRPB_STATUS register
 */
#define HW_HDMI_PHY_SCRPB_STATUS_ADDR      (REGS_HDMI_PHY_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCRPB_STATUS           (*(volatile hw_hdmi_phy_scrpb_status_t *) HW_HDMI_PHY_SCRPB_STATUS_ADDR)
#define HW_HDMI_PHY_SCRPB_STATUS_RD()      (HW_HDMI_PHY_SCRPB_STATUS.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_SCRPB_STATUS bitfields
 */

/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field CK_SCOPE_OUT[0] (RO)
 *
 * Clock Scope Output Signal
 *
 * Values:
 * 0 - The clock driver output is not differential.
 * 1 - The clock driver output is differential.
 */

#define BP_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT      (0)      //!< Bit position for HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT.
#define BM_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT      (0x00000001)  //!< Bit mask for HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT.

//! @brief Get value of HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT from a register value.
#define BG_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT(r)   (((r) & BM_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT) >> BP_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT)


/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field TX_SCOPE_OUT2[1] (RO)
 *
 * Scoping Value for Lane 2
 *
 * Values:
 * 0 - The driver output of lane 2 is not differential.
 * 1 - The driver output of lane 2 is differential.
 */

#define BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2      (1)      //!< Bit position for HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2.
#define BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2      (0x00000002)  //!< Bit mask for HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2.

//! @brief Get value of HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2 from a register value.
#define BG_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2(r)   (((r) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2) >> BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2)


/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field TX_SCOPE_OUT1[2] (RO)
 *
 * Scoping Value for Lane 1
 *
 * Values:
 * 0 - The driver output of lane 1 is not differential.
 * 1 - The driver output of lane 1 is differential.
 */

#define BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1      (2)      //!< Bit position for HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1.
#define BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1      (0x00000004)  //!< Bit mask for HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1.

//! @brief Get value of HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1 from a register value.
#define BG_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1(r)   (((r) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1) >> BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1)


/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field TX_SCOPE_OUT0[3] (RO)
 *
 * Scoping Value for Lane 0
 *
 * Values:
 * 0 - The driver output of lane 0 is not differential.
 * 1 - The driver output of lane 0 is differential.
 */

#define BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0      (3)      //!< Bit position for HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0.
#define BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0      (0x00000008)  //!< Bit mask for HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0.

//! @brief Get value of HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0 from a register value.
#define BG_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0(r)   (((r) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0) >> BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0)


/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field SUP_COMP_RT_RESULT[4] (RO)
 *
 * Support Comparator Resistance Termination Result This bit represents the result of the comparison
 * process.
 *
 * Values:
 * 0 - The first input is greater than or equal to the second input.
 * 1 - The first input is less than the second input.
 */

#define BP_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT      (4)      //!< Bit position for HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT.
#define BM_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT      (0x00000010)  //!< Bit mask for HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT.

//! @brief Get value of HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT from a register value.
#define BG_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT(r)   (((r) & BM_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT) >> BP_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT)


/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field ADC_VAL[15:6] (RO)
 *
 * ADC/DAC bit word (analog signal value)
 */

#define BP_HDMI_PHY_SCRPB_STATUS_ADC_VAL      (6)      //!< Bit position for HDMI_PHY_SCRPB_STATUS_ADC_VAL.
#define BM_HDMI_PHY_SCRPB_STATUS_ADC_VAL      (0x0000ffc0)  //!< Bit mask for HDMI_PHY_SCRPB_STATUS_ADC_VAL.

//! @brief Get value of HDMI_PHY_SCRPB_STATUS_ADC_VAL from a register value.
#define BG_HDMI_PHY_SCRPB_STATUS_ADC_VAL(r)   (((r) & BM_HDMI_PHY_SCRPB_STATUS_ADC_VAL) >> BP_HDMI_PHY_SCRPB_STATUS_ADC_VAL)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_TXTERM - Transmission Termination (RW)
 *
 * Reset value: 0x00000007
 *
 * Register name : TXTERM  Access type : Read/write  Address : 0x19  Value at reset : 0x0007
 */
typedef union _hw_hdmi_phy_txterm
{
    reg16_t U;
    struct _hw_hdmi_phy_txterm_bitfields
    {
        unsigned short D_TX_TERM : 3; //!< [2:0] Digital Transmission Termination This bus defines the transmission termination (resistance) value, which is set by the HDMI controller. The formula for the resistance value is: R = 50 / (1 - 0.125 x d_tx_term) This equation is valid only when d_tx_term equals 0-6. 000: 50 Ω 001: 56.14 Ω 010: 66.67 Ω 011: 80 Ω 100: 100 Ω 101: 133.33 Ω 110: 200 Ω 111: Open circuit
        unsigned short RESERVED0 : 13; //!< [15:3] Reserved
    } B;
} hw_hdmi_phy_txterm_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TXTERM register
 */
#define HW_HDMI_PHY_TXTERM_ADDR      (REGS_HDMI_PHY_BASE + 0x19)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TXTERM           (*(volatile hw_hdmi_phy_txterm_t *) HW_HDMI_PHY_TXTERM_ADDR)
#define HW_HDMI_PHY_TXTERM_RD()      (HW_HDMI_PHY_TXTERM.U)
#define HW_HDMI_PHY_TXTERM_WR(v)     (HW_HDMI_PHY_TXTERM.U = (v))
#define HW_HDMI_PHY_TXTERM_SET(v)    (HW_HDMI_PHY_TXTERM_WR(HW_HDMI_PHY_TXTERM_RD() |  (v)))
#define HW_HDMI_PHY_TXTERM_CLR(v)    (HW_HDMI_PHY_TXTERM_WR(HW_HDMI_PHY_TXTERM_RD() & ~(v)))
#define HW_HDMI_PHY_TXTERM_TOG(v)    (HW_HDMI_PHY_TXTERM_WR(HW_HDMI_PHY_TXTERM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_TXTERM bitfields
 */

/* --- Register HW_HDMI_PHY_TXTERM, field D_TX_TERM[2:0] (RW)
 *
 * Digital Transmission Termination This bus defines the transmission termination (resistance)
 * value, which is set by the HDMI controller. The formula for the resistance value is: R = 50 / (1
 * - 0.125 x d_tx_term) This equation is valid only when d_tx_term equals 0-6. 000: 50 Ω 001: 56.14
 * Ω 010: 66.67 Ω 011: 80 Ω 100: 100 Ω 101: 133.33 Ω 110: 200 Ω 111: Open circuit
 */

#define BP_HDMI_PHY_TXTERM_D_TX_TERM      (0)      //!< Bit position for HDMI_PHY_TXTERM_D_TX_TERM.
#define BM_HDMI_PHY_TXTERM_D_TX_TERM      (0x00000007)  //!< Bit mask for HDMI_PHY_TXTERM_D_TX_TERM.

//! @brief Get value of HDMI_PHY_TXTERM_D_TX_TERM from a register value.
#define BG_HDMI_PHY_TXTERM_D_TX_TERM(r)   (((r) & BM_HDMI_PHY_TXTERM_D_TX_TERM) >> BP_HDMI_PHY_TXTERM_D_TX_TERM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_TXTERM_D_TX_TERM.
#define BF_HDMI_PHY_TXTERM_D_TX_TERM(v)   ((((reg16_t) v) << BP_HDMI_PHY_TXTERM_D_TX_TERM) & BM_HDMI_PHY_TXTERM_D_TX_TERM)
#else
//! @brief Format value for bitfield HDMI_PHY_TXTERM_D_TX_TERM.
#define BF_HDMI_PHY_TXTERM_D_TX_TERM(v)   (((v) << BP_HDMI_PHY_TXTERM_D_TX_TERM) & BM_HDMI_PHY_TXTERM_D_TX_TERM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the D_TX_TERM field to a new value.
#define BW_HDMI_PHY_TXTERM_D_TX_TERM(v)   (HW_HDMI_PHY_TXTERM_WR((HW_HDMI_PHY_TXTERM_RD() & ~BM_HDMI_PHY_TXTERM_D_TX_TERM) | BF_HDMI_PHY_TXTERM_D_TX_TERM(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_PTRPT_ENBL - Power Sequence, TX Clock Alignment, Resistance Calibration, Pattern Generator Skip Bit, and TMDS Encoder Enable (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : -  Access type : Read/write/override  Address : 0x1A  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_ptrpt_enbl
{
    reg16_t U;
    struct _hw_hdmi_phy_ptrpt_enbl_bitfields
    {
        unsigned short REFCLK_ENB : 1; //!< [0] Reference Clock Enable This bit enables or disables the input reference clock.
        unsigned short CKO_WORD_ENB : 1; //!< [1] Output Clock Word Enable This bit enables the output word clock.
        unsigned short TX_READY : 1; //!< [2] Transmission Ready This bit indicates whether the PHY transmit driver is ready to transmit data.
        unsigned short TX_CK_ALIGN_ENB : 1; //!< [3] Transmission Clock Alignment Enable This bit disables or enables the clock alignment FSM.
        unsigned short RCAL_ENB : 1; //!< [4] Resistance Calibration Enable This bit enables or disables the resistance clock alignment process.
        unsigned short CK_REF_ENB : 1; //!< [5] Clock Reference Enable This bit powers up the clock alignment and the resistance calibration modules.
        unsigned short PG_SKIP_BIT0 : 1; //!< [6] Pattern Generator Skip Bit 0 This bit enables or disables pattern generator skip bit feature for channel 0.
        unsigned short PG_SKIP_BIT1 : 1; //!< [7] Pattern Generator Skip Bit 1 This bit enables or disables pattern generator skip bit feature for channel 1.
        unsigned short PG_SKIP_BIT2 : 1; //!< [8] Pattern Generator Skip Bit 2 This bit enables or disables pattern generator skip bit feature for channel 2.
        unsigned short RESERVED0 : 6; //!< [14:9] Reserved
        unsigned short OVERRIDE : 1; //!< [15] If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_ptrpt_enbl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PTRPT_ENBL register
 */
#define HW_HDMI_PHY_PTRPT_ENBL_ADDR      (REGS_HDMI_PHY_BASE + 0x1a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PTRPT_ENBL           (*(volatile hw_hdmi_phy_ptrpt_enbl_t *) HW_HDMI_PHY_PTRPT_ENBL_ADDR)
#define HW_HDMI_PHY_PTRPT_ENBL_RD()      (HW_HDMI_PHY_PTRPT_ENBL.U)
#define HW_HDMI_PHY_PTRPT_ENBL_WR(v)     (HW_HDMI_PHY_PTRPT_ENBL.U = (v))
#define HW_HDMI_PHY_PTRPT_ENBL_SET(v)    (HW_HDMI_PHY_PTRPT_ENBL_WR(HW_HDMI_PHY_PTRPT_ENBL_RD() |  (v)))
#define HW_HDMI_PHY_PTRPT_ENBL_CLR(v)    (HW_HDMI_PHY_PTRPT_ENBL_WR(HW_HDMI_PHY_PTRPT_ENBL_RD() & ~(v)))
#define HW_HDMI_PHY_PTRPT_ENBL_TOG(v)    (HW_HDMI_PHY_PTRPT_ENBL_WR(HW_HDMI_PHY_PTRPT_ENBL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_PTRPT_ENBL bitfields
 */

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field REFCLK_ENB[0] (RW)
 *
 * Reference Clock Enable This bit enables or disables the input reference clock.
 *
 * Values:
 * 0 - Disable the input reference clock, if the Override bit is 0.
 * 1 - Enable the input reference clock, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB      (0)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_REFCLK_ENB.
#define BM_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB      (0x00000001)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_REFCLK_ENB.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_REFCLK_ENB from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB) >> BP_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_REFCLK_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB) & BM_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_REFCLK_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB) & BM_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFCLK_ENB field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB) | BF_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field CKO_WORD_ENB[1] (RW)
 *
 * Output Clock Word Enable This bit enables the output word clock.
 *
 * Values:
 * 0 - Disable the output clock word, if the Override bit is 0.
 * 1 - Enable the output clock word, if the Override bit is 0
 */

#define BP_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB      (1)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB.
#define BM_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB      (0x00000002)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB) >> BP_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB) & BM_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB) & BM_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO_WORD_ENB field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB) | BF_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field TX_READY[2] (RW)
 *
 * Transmission Ready This bit indicates whether the PHY transmit driver is ready to transmit data.
 *
 * Values:
 * 0 - PHY transmit driver is not ready to transmit data, if the Override bit is 0.
 * 1 - PHY transmit driver is ready to transmit data, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_TX_READY      (2)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_TX_READY.
#define BM_HDMI_PHY_PTRPT_ENBL_TX_READY      (0x00000004)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_TX_READY.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_TX_READY from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_TX_READY(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_TX_READY) >> BP_HDMI_PHY_PTRPT_ENBL_TX_READY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_TX_READY.
#define BF_HDMI_PHY_PTRPT_ENBL_TX_READY(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_TX_READY) & BM_HDMI_PHY_PTRPT_ENBL_TX_READY)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_TX_READY.
#define BF_HDMI_PHY_PTRPT_ENBL_TX_READY(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_TX_READY) & BM_HDMI_PHY_PTRPT_ENBL_TX_READY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_READY field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_TX_READY(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_TX_READY) | BF_HDMI_PHY_PTRPT_ENBL_TX_READY(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field TX_CK_ALIGN_ENB[3] (RW)
 *
 * Transmission Clock Alignment Enable This bit disables or enables the clock alignment FSM.
 *
 * Values:
 * 0 - Disable transmission clock alignment FSM, if the Override bit is 0.
 * 1 - Enable transmission clock alignment FSM, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB      (3)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB.
#define BM_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB      (0x00000008)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB) >> BP_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB) & BM_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB) & BM_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CK_ALIGN_ENB field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB) | BF_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field RCAL_ENB[4] (RW)
 *
 * Resistance Calibration Enable This bit enables or disables the resistance clock alignment
 * process.
 *
 * Values:
 * 0 - Disable the resistance calibration FSM, if the Override bit is 0.
 * 1 - Enable the resistance calibration FSM, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_RCAL_ENB      (4)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_RCAL_ENB.
#define BM_HDMI_PHY_PTRPT_ENBL_RCAL_ENB      (0x00000010)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_RCAL_ENB.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_RCAL_ENB from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_RCAL_ENB(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_RCAL_ENB) >> BP_HDMI_PHY_PTRPT_ENBL_RCAL_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_RCAL_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_RCAL_ENB(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_RCAL_ENB) & BM_HDMI_PHY_PTRPT_ENBL_RCAL_ENB)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_RCAL_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_RCAL_ENB(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_RCAL_ENB) & BM_HDMI_PHY_PTRPT_ENBL_RCAL_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCAL_ENB field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_RCAL_ENB(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_RCAL_ENB) | BF_HDMI_PHY_PTRPT_ENBL_RCAL_ENB(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field CK_REF_ENB[5] (RW)
 *
 * Clock Reference Enable This bit powers up the clock alignment and the resistance calibration
 * modules.
 *
 * Values:
 * 0 - Powers down the clock alignment and the resistance calibration modules, if the Override bit is 0.
 * 1 - Powers up the clock alignment and the resistance calibration modules, if the Override bit is 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB      (5)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_CK_REF_ENB.
#define BM_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB      (0x00000020)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_CK_REF_ENB.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_CK_REF_ENB from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB) >> BP_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_CK_REF_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB) & BM_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_CK_REF_ENB.
#define BF_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB) & BM_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CK_REF_ENB field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB) | BF_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field PG_SKIP_BIT0[6] (RW)
 *
 * Pattern Generator Skip Bit 0 This bit enables or disables pattern generator skip bit feature for
 * channel 0.
 *
 * Values:
 * 0 - Disable the pattern generator skip bit feature for the first transmitting channel, if the Override
 *     bit is 0.
 * 1 - Enable the pattern generator skip bit feature for the first transmitting channel, if the Override
 *     bit is 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0      (6)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0.
#define BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0      (0x00000040)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0 from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0) >> BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0.
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0.
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_SKIP_BIT0 field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0) | BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field PG_SKIP_BIT1[7] (RW)
 *
 * Pattern Generator Skip Bit 1 This bit enables or disables pattern generator skip bit feature for
 * channel 1.
 *
 * Values:
 * 0 - Disable the pattern generator skip bit feature for the second transmitting channel, if the Override
 *     bit is 0.
 * 1 - Enable the pattern generator skip bit feature for the second transmitting channel, if the Override
 *     bit is 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1      (7)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1.
#define BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1      (0x00000080)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1 from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1) >> BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1.
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1.
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_SKIP_BIT1 field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1) | BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field PG_SKIP_BIT2[8] (RW)
 *
 * Pattern Generator Skip Bit 2 This bit enables or disables pattern generator skip bit feature for
 * channel 2.
 *
 * Values:
 * 0 - Disable the pattern generator skip bit feature for the third transmitting channel, if the Override
 *     bit is 0.
 * 1 - Enable the pattern generator skip bit feature for the third transmitting channel, if the Override
 *     bit is 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2      (8)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2.
#define BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2      (0x00000100)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2 from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2) >> BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2.
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2.
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_SKIP_BIT2 field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2) | BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2(v)))
#endif


/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field OVERRIDE[15] (RW)
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_OVERRIDE      (15)      //!< Bit position for HDMI_PHY_PTRPT_ENBL_OVERRIDE.
#define BM_HDMI_PHY_PTRPT_ENBL_OVERRIDE      (0x00008000)  //!< Bit mask for HDMI_PHY_PTRPT_ENBL_OVERRIDE.

//! @brief Get value of HDMI_PHY_PTRPT_ENBL_OVERRIDE from a register value.
#define BG_HDMI_PHY_PTRPT_ENBL_OVERRIDE(r)   (((r) & BM_HDMI_PHY_PTRPT_ENBL_OVERRIDE) >> BP_HDMI_PHY_PTRPT_ENBL_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_OVERRIDE.
#define BF_HDMI_PHY_PTRPT_ENBL_OVERRIDE(v)   ((((reg16_t) v) << BP_HDMI_PHY_PTRPT_ENBL_OVERRIDE) & BM_HDMI_PHY_PTRPT_ENBL_OVERRIDE)
#else
//! @brief Format value for bitfield HDMI_PHY_PTRPT_ENBL_OVERRIDE.
#define BF_HDMI_PHY_PTRPT_ENBL_OVERRIDE(v)   (((v) << BP_HDMI_PHY_PTRPT_ENBL_OVERRIDE) & BM_HDMI_PHY_PTRPT_ENBL_OVERRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERRIDE field to a new value.
#define BW_HDMI_PHY_PTRPT_ENBL_OVERRIDE(v)   (HW_HDMI_PHY_PTRPT_ENBL_WR((HW_HDMI_PHY_PTRPT_ENBL_RD() & ~BM_HDMI_PHY_PTRPT_ENBL_OVERRIDE) | BF_HDMI_PHY_PTRPT_ENBL_OVERRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_PATTERNGEN - Pattern Generator Mode (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : PATTERNGEN  Access type : Read/write  Address : 0x1B  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_patterngen
{
    reg16_t U;
    struct _hw_hdmi_phy_patterngen_bitfields
    {
        unsigned short PG_PAT : 10; //!< [9:0] Pattern Generator Generated Pattern This bus carries the generated pattern from the Pattern Generator module.
        unsigned short PG_INSERT_ERR0 : 1; //!< [10] Pattern Generator Insert Error Zero This bit enables or disables error insertion inside the generated pattern for channel 0.
        unsigned short PG_INSERT_ERR1 : 1; //!< [11] Pattern Generator Insert Error One This bit enables or disables error insertion inside the generated pattern for channel 1.
        unsigned short PG_INSERT_ERR2 : 1; //!< [12] Pattern Generator Insert Error Two This bit enables or disables error insertion inside the generated pattern for channel 2.
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved
    } B;
} hw_hdmi_phy_patterngen_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PATTERNGEN register
 */
#define HW_HDMI_PHY_PATTERNGEN_ADDR      (REGS_HDMI_PHY_BASE + 0x1b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PATTERNGEN           (*(volatile hw_hdmi_phy_patterngen_t *) HW_HDMI_PHY_PATTERNGEN_ADDR)
#define HW_HDMI_PHY_PATTERNGEN_RD()      (HW_HDMI_PHY_PATTERNGEN.U)
#define HW_HDMI_PHY_PATTERNGEN_WR(v)     (HW_HDMI_PHY_PATTERNGEN.U = (v))
#define HW_HDMI_PHY_PATTERNGEN_SET(v)    (HW_HDMI_PHY_PATTERNGEN_WR(HW_HDMI_PHY_PATTERNGEN_RD() |  (v)))
#define HW_HDMI_PHY_PATTERNGEN_CLR(v)    (HW_HDMI_PHY_PATTERNGEN_WR(HW_HDMI_PHY_PATTERNGEN_RD() & ~(v)))
#define HW_HDMI_PHY_PATTERNGEN_TOG(v)    (HW_HDMI_PHY_PATTERNGEN_WR(HW_HDMI_PHY_PATTERNGEN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_PATTERNGEN bitfields
 */

/* --- Register HW_HDMI_PHY_PATTERNGEN, field PG_PAT[9:0] (RW)
 *
 * Pattern Generator Generated Pattern This bus carries the generated pattern from the Pattern
 * Generator module.
 */

#define BP_HDMI_PHY_PATTERNGEN_PG_PAT      (0)      //!< Bit position for HDMI_PHY_PATTERNGEN_PG_PAT.
#define BM_HDMI_PHY_PATTERNGEN_PG_PAT      (0x000003ff)  //!< Bit mask for HDMI_PHY_PATTERNGEN_PG_PAT.

//! @brief Get value of HDMI_PHY_PATTERNGEN_PG_PAT from a register value.
#define BG_HDMI_PHY_PATTERNGEN_PG_PAT(r)   (((r) & BM_HDMI_PHY_PATTERNGEN_PG_PAT) >> BP_HDMI_PHY_PATTERNGEN_PG_PAT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PATTERNGEN_PG_PAT.
#define BF_HDMI_PHY_PATTERNGEN_PG_PAT(v)   ((((reg16_t) v) << BP_HDMI_PHY_PATTERNGEN_PG_PAT) & BM_HDMI_PHY_PATTERNGEN_PG_PAT)
#else
//! @brief Format value for bitfield HDMI_PHY_PATTERNGEN_PG_PAT.
#define BF_HDMI_PHY_PATTERNGEN_PG_PAT(v)   (((v) << BP_HDMI_PHY_PATTERNGEN_PG_PAT) & BM_HDMI_PHY_PATTERNGEN_PG_PAT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_PAT field to a new value.
#define BW_HDMI_PHY_PATTERNGEN_PG_PAT(v)   (HW_HDMI_PHY_PATTERNGEN_WR((HW_HDMI_PHY_PATTERNGEN_RD() & ~BM_HDMI_PHY_PATTERNGEN_PG_PAT) | BF_HDMI_PHY_PATTERNGEN_PG_PAT(v)))
#endif

/* --- Register HW_HDMI_PHY_PATTERNGEN, field PG_INSERT_ERR0[10] (RW)
 *
 * Pattern Generator Insert Error Zero This bit enables or disables error insertion inside the
 * generated pattern for channel 0.
 *
 * Values:
 * 0 - Do not insert error inside generated pattern for the first transmit channel.
 * 1 - Insert error inside generated pattern for the first transmit channel.
 */

#define BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0      (10)      //!< Bit position for HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0.
#define BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0      (0x00000400)  //!< Bit mask for HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0.

//! @brief Get value of HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0 from a register value.
#define BG_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0(r)   (((r) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0) >> BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0.
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0(v)   ((((reg16_t) v) << BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0)
#else
//! @brief Format value for bitfield HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0.
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0(v)   (((v) << BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_INSERT_ERR0 field to a new value.
#define BW_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0(v)   (HW_HDMI_PHY_PATTERNGEN_WR((HW_HDMI_PHY_PATTERNGEN_RD() & ~BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0) | BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0(v)))
#endif


/* --- Register HW_HDMI_PHY_PATTERNGEN, field PG_INSERT_ERR1[11] (RW)
 *
 * Pattern Generator Insert Error One This bit enables or disables error insertion inside the
 * generated pattern for channel 1.
 *
 * Values:
 * 0 - Do not insert error inside generated pattern for the second transmit channel.
 * 1 - Insert error inside generated pattern for the second transmit channel.
 */

#define BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1      (11)      //!< Bit position for HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1.
#define BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1      (0x00000800)  //!< Bit mask for HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1.

//! @brief Get value of HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1 from a register value.
#define BG_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1(r)   (((r) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1) >> BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1.
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1(v)   ((((reg16_t) v) << BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1)
#else
//! @brief Format value for bitfield HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1.
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1(v)   (((v) << BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_INSERT_ERR1 field to a new value.
#define BW_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1(v)   (HW_HDMI_PHY_PATTERNGEN_WR((HW_HDMI_PHY_PATTERNGEN_RD() & ~BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1) | BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1(v)))
#endif


/* --- Register HW_HDMI_PHY_PATTERNGEN, field PG_INSERT_ERR2[12] (RW)
 *
 * Pattern Generator Insert Error Two This bit enables or disables error insertion inside the
 * generated pattern for channel 2.
 *
 * Values:
 * 0 - Do not insert error inside generated pattern for the third transmit channel.
 * 1 - Insert error inside generated pattern for the third transmit channel.
 */

#define BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2      (12)      //!< Bit position for HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2.
#define BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2      (0x00001000)  //!< Bit mask for HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2.

//! @brief Get value of HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2 from a register value.
#define BG_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2(r)   (((r) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2) >> BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2.
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2(v)   ((((reg16_t) v) << BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2)
#else
//! @brief Format value for bitfield HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2.
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2(v)   (((v) << BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_INSERT_ERR2 field to a new value.
#define BW_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2(v)   (HW_HDMI_PHY_PATTERNGEN_WR((HW_HDMI_PHY_PATTERNGEN_RD() & ~BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2) | BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SDCAP_MODE - The Soft-Reset and DAC Enable, Clock Alignment and PG Mode (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : -  Access type : Read/write  Address : 0x1C  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_sdcap_mode
{
    reg16_t U;
    struct _hw_hdmi_phy_sdcap_mode_bitfields
    {
        unsigned short SOFT_RESET : 1; //!< [0] Soft Reset This bit enables or disables the soft-reset feature.
        unsigned short ADC_ENB : 1; //!< [1] Analog-to-Digital Converter Enable This bit enables or disables the analog-to-digital converter.
        unsigned short TX_CK_ALIGN_MODE : 1; //!< [2] Transmission Clock Alignment Mode This bit selects the Transmission Clock Alignment mode.
        unsigned short PG_MODE0 : 3; //!< [5:3] Pattern Generator Mode 0 This bus is used to select the mode of the Pattern Generator module for channel 0.
        unsigned short PG_MODE1 : 3; //!< [8:6] Pattern Generator Mode 1 This bus is used to select the mode of the Pattern Generator module for channel 1.
        unsigned short PG_MODE2 : 3; //!< [11:9] Pattern Generator Mode 2 This bus is used to select the mode of the Pattern Generator module for channel 2.
        unsigned short RESERVED0 : 4; //!< [15:12] Reserved
    } B;
} hw_hdmi_phy_sdcap_mode_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SDCAP_MODE register
 */
#define HW_HDMI_PHY_SDCAP_MODE_ADDR      (REGS_HDMI_PHY_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SDCAP_MODE           (*(volatile hw_hdmi_phy_sdcap_mode_t *) HW_HDMI_PHY_SDCAP_MODE_ADDR)
#define HW_HDMI_PHY_SDCAP_MODE_RD()      (HW_HDMI_PHY_SDCAP_MODE.U)
#define HW_HDMI_PHY_SDCAP_MODE_WR(v)     (HW_HDMI_PHY_SDCAP_MODE.U = (v))
#define HW_HDMI_PHY_SDCAP_MODE_SET(v)    (HW_HDMI_PHY_SDCAP_MODE_WR(HW_HDMI_PHY_SDCAP_MODE_RD() |  (v)))
#define HW_HDMI_PHY_SDCAP_MODE_CLR(v)    (HW_HDMI_PHY_SDCAP_MODE_WR(HW_HDMI_PHY_SDCAP_MODE_RD() & ~(v)))
#define HW_HDMI_PHY_SDCAP_MODE_TOG(v)    (HW_HDMI_PHY_SDCAP_MODE_WR(HW_HDMI_PHY_SDCAP_MODE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_SDCAP_MODE bitfields
 */

/* --- Register HW_HDMI_PHY_SDCAP_MODE, field SOFT_RESET[0] (RW)
 *
 * Soft Reset This bit enables or disables the soft-reset feature.
 *
 * Values:
 * 0 - Do not perform a soft reset.
 * 1 - Perform a soft reset by resetting all the system FSMs except the I 2 C and Control Register modules.
 */

#define BP_HDMI_PHY_SDCAP_MODE_SOFT_RESET      (0)      //!< Bit position for HDMI_PHY_SDCAP_MODE_SOFT_RESET.
#define BM_HDMI_PHY_SDCAP_MODE_SOFT_RESET      (0x00000001)  //!< Bit mask for HDMI_PHY_SDCAP_MODE_SOFT_RESET.

//! @brief Get value of HDMI_PHY_SDCAP_MODE_SOFT_RESET from a register value.
#define BG_HDMI_PHY_SDCAP_MODE_SOFT_RESET(r)   (((r) & BM_HDMI_PHY_SDCAP_MODE_SOFT_RESET) >> BP_HDMI_PHY_SDCAP_MODE_SOFT_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_SOFT_RESET.
#define BF_HDMI_PHY_SDCAP_MODE_SOFT_RESET(v)   ((((reg16_t) v) << BP_HDMI_PHY_SDCAP_MODE_SOFT_RESET) & BM_HDMI_PHY_SDCAP_MODE_SOFT_RESET)
#else
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_SOFT_RESET.
#define BF_HDMI_PHY_SDCAP_MODE_SOFT_RESET(v)   (((v) << BP_HDMI_PHY_SDCAP_MODE_SOFT_RESET) & BM_HDMI_PHY_SDCAP_MODE_SOFT_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOFT_RESET field to a new value.
#define BW_HDMI_PHY_SDCAP_MODE_SOFT_RESET(v)   (HW_HDMI_PHY_SDCAP_MODE_WR((HW_HDMI_PHY_SDCAP_MODE_RD() & ~BM_HDMI_PHY_SDCAP_MODE_SOFT_RESET) | BF_HDMI_PHY_SDCAP_MODE_SOFT_RESET(v)))
#endif


/* --- Register HW_HDMI_PHY_SDCAP_MODE, field ADC_ENB[1] (RW)
 *
 * Analog-to-Digital Converter Enable This bit enables or disables the analog-to-digital converter.
 *
 * Values:
 * 0 - Disable the analog-to-digital converter.
 * 1 - Enable the analog-to-digital converter, which is used in the Resistance Calibration module.
 */

#define BP_HDMI_PHY_SDCAP_MODE_ADC_ENB      (1)      //!< Bit position for HDMI_PHY_SDCAP_MODE_ADC_ENB.
#define BM_HDMI_PHY_SDCAP_MODE_ADC_ENB      (0x00000002)  //!< Bit mask for HDMI_PHY_SDCAP_MODE_ADC_ENB.

//! @brief Get value of HDMI_PHY_SDCAP_MODE_ADC_ENB from a register value.
#define BG_HDMI_PHY_SDCAP_MODE_ADC_ENB(r)   (((r) & BM_HDMI_PHY_SDCAP_MODE_ADC_ENB) >> BP_HDMI_PHY_SDCAP_MODE_ADC_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_ADC_ENB.
#define BF_HDMI_PHY_SDCAP_MODE_ADC_ENB(v)   ((((reg16_t) v) << BP_HDMI_PHY_SDCAP_MODE_ADC_ENB) & BM_HDMI_PHY_SDCAP_MODE_ADC_ENB)
#else
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_ADC_ENB.
#define BF_HDMI_PHY_SDCAP_MODE_ADC_ENB(v)   (((v) << BP_HDMI_PHY_SDCAP_MODE_ADC_ENB) & BM_HDMI_PHY_SDCAP_MODE_ADC_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADC_ENB field to a new value.
#define BW_HDMI_PHY_SDCAP_MODE_ADC_ENB(v)   (HW_HDMI_PHY_SDCAP_MODE_WR((HW_HDMI_PHY_SDCAP_MODE_RD() & ~BM_HDMI_PHY_SDCAP_MODE_ADC_ENB) | BF_HDMI_PHY_SDCAP_MODE_ADC_ENB(v)))
#endif


/* --- Register HW_HDMI_PHY_SDCAP_MODE, field TX_CK_ALIGN_MODE[2] (RW)
 *
 * Transmission Clock Alignment Mode This bit selects the Transmission Clock Alignment mode.
 *
 * Values:
 * 0 - Align the three lanes based on lane 1.
 * 1 - Align each of the three lanes separately in the following order: lane 2, lane 0, then lane 1.
 */

#define BP_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE      (2)      //!< Bit position for HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE.
#define BM_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE      (0x00000004)  //!< Bit mask for HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE.

//! @brief Get value of HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE from a register value.
#define BG_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE(r)   (((r) & BM_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE) >> BP_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE.
#define BF_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE(v)   ((((reg16_t) v) << BP_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE) & BM_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE)
#else
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE.
#define BF_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE(v)   (((v) << BP_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE) & BM_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CK_ALIGN_MODE field to a new value.
#define BW_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE(v)   (HW_HDMI_PHY_SDCAP_MODE_WR((HW_HDMI_PHY_SDCAP_MODE_RD() & ~BM_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE) | BF_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE(v)))
#endif


/* --- Register HW_HDMI_PHY_SDCAP_MODE, field PG_MODE0[5:3] (RW)
 *
 * Pattern Generator Mode 0 This bus is used to select the mode of the Pattern Generator module for
 * channel 0.
 *
 * Values:
 * 000 - Disable the Pattern Generator module.
 * 001 - Enable the Pattern Generator module and generate a sequence of patterns for the first channel using
 *     LFSR 15 equation (for example, x15 + x14 + 1).
 * 010 - Enable the Pattern Generator module and generate a sequence of patterns for the first channel using
 *     LFSR 7 equation (for example, x7 + x6 + 1).
 * 011 - Enable the Pattern Generator module and generate a sequence of patterns for the first channel with
 *     the fixed word, which is saved inside the pg_pat[9:0] field of the PATTERNGEN register.
 * 100 - Enable the Pattern Generator module and generate a sequence of patterns for the first channel with
 *     DC-balanced word (for example, 0's or 1's and their inverted values).
 * 101 - Enable the Pattern Generator module and generate a sequence of patterns for the first channel with
 *     fixed pattern using word of 0's word, 1's word, random word, the saved pattern inside the
 *     pg_pat[9:0] field of the PATTERNGEN register, and the inverted pg_pat[9:0] values (for
 *     example, 9 bits of 0's, 9 bits of 1's, 3FF, pg_pat[9:0], ~ pg_pat[9:0]).
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_HDMI_PHY_SDCAP_MODE_PG_MODE0      (3)      //!< Bit position for HDMI_PHY_SDCAP_MODE_PG_MODE0.
#define BM_HDMI_PHY_SDCAP_MODE_PG_MODE0      (0x00000038)  //!< Bit mask for HDMI_PHY_SDCAP_MODE_PG_MODE0.

//! @brief Get value of HDMI_PHY_SDCAP_MODE_PG_MODE0 from a register value.
#define BG_HDMI_PHY_SDCAP_MODE_PG_MODE0(r)   (((r) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE0) >> BP_HDMI_PHY_SDCAP_MODE_PG_MODE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_PG_MODE0.
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE0(v)   ((((reg16_t) v) << BP_HDMI_PHY_SDCAP_MODE_PG_MODE0) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE0)
#else
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_PG_MODE0.
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE0(v)   (((v) << BP_HDMI_PHY_SDCAP_MODE_PG_MODE0) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_MODE0 field to a new value.
#define BW_HDMI_PHY_SDCAP_MODE_PG_MODE0(v)   (HW_HDMI_PHY_SDCAP_MODE_WR((HW_HDMI_PHY_SDCAP_MODE_RD() & ~BM_HDMI_PHY_SDCAP_MODE_PG_MODE0) | BF_HDMI_PHY_SDCAP_MODE_PG_MODE0(v)))
#endif


/* --- Register HW_HDMI_PHY_SDCAP_MODE, field PG_MODE1[8:6] (RW)
 *
 * Pattern Generator Mode 1 This bus is used to select the mode of the Pattern Generator module for
 * channel 1.
 *
 * Values:
 * 000 - Disable the Pattern Generator module.
 * 001 - Enable the Pattern Generator module and generate a sequence of patterns for the second channel using
 *     LFSR 15 equation (for example, x15 + x14 + 1).
 * 010 - second the Pattern Generator module and generate a sequence of patterns for the first channel using
 *     LFSR 7 equation (for example, x7 + x6 + 1).
 * 011 - Enable the Pattern Generator module and generate a sequence of patterns for the second channel with
 *     the fixed word, which is saved inside the pg_pat[9:0] field of the PATTERNGEN register.
 * 100 - Enable the Pattern Generator module and generate a sequence of patterns for the second channel with
 *     DC-balanced word (for example, 0's or 1's and their inverted values).
 * 101 - Enable the Pattern Generator module and generate a sequence of patterns for the second channel with
 *     fixed pattern using word of 0's word, 1's word, random word, the saved pattern inside the
 *     pg_pat[9:0] field of the PATTERNGEN register, and the inverted pg_pat[9:0] values (for
 *     example, 9 bits of 0's, 9 bits of 1's, 3FF, pg_pat[9:0], ~ pg_pat[9:0]).
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_HDMI_PHY_SDCAP_MODE_PG_MODE1      (6)      //!< Bit position for HDMI_PHY_SDCAP_MODE_PG_MODE1.
#define BM_HDMI_PHY_SDCAP_MODE_PG_MODE1      (0x000001c0)  //!< Bit mask for HDMI_PHY_SDCAP_MODE_PG_MODE1.

//! @brief Get value of HDMI_PHY_SDCAP_MODE_PG_MODE1 from a register value.
#define BG_HDMI_PHY_SDCAP_MODE_PG_MODE1(r)   (((r) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE1) >> BP_HDMI_PHY_SDCAP_MODE_PG_MODE1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_PG_MODE1.
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE1(v)   ((((reg16_t) v) << BP_HDMI_PHY_SDCAP_MODE_PG_MODE1) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE1)
#else
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_PG_MODE1.
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE1(v)   (((v) << BP_HDMI_PHY_SDCAP_MODE_PG_MODE1) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_MODE1 field to a new value.
#define BW_HDMI_PHY_SDCAP_MODE_PG_MODE1(v)   (HW_HDMI_PHY_SDCAP_MODE_WR((HW_HDMI_PHY_SDCAP_MODE_RD() & ~BM_HDMI_PHY_SDCAP_MODE_PG_MODE1) | BF_HDMI_PHY_SDCAP_MODE_PG_MODE1(v)))
#endif


/* --- Register HW_HDMI_PHY_SDCAP_MODE, field PG_MODE2[11:9] (RW)
 *
 * Pattern Generator Mode 2 This bus is used to select the mode of the Pattern Generator module for
 * channel 2.
 *
 * Values:
 * 000 - Disable the Pattern Generator module.
 * 001 - Enable the Pattern Generator module and generate a sequence of patterns for the third channel using
 *     LFSR 15 equation (for example, x15 + x14 + 1).
 * 010 - Enable the Pattern Generator module and generate a sequence of patterns for the third channel using
 *     LFSR 7 equation (for example, x7 + x6 + 1).
 * 011 - Enable the Pattern Generator module and generate a sequence of patterns for the third channel with
 *     the fixed word, which is saved inside the pg_pat[9:0] field of the PATTERNGEN register.
 * 100 - Enable the Pattern Generator module and generate a sequence of patterns for the third channel with
 *     DC-balanced word (for example, 0's or 1's and their inverted values).
 * 101 - Enable the Pattern Generator module and generate a sequence of patterns for the third channel with
 *     fixed pattern using word of 0's word, 1's word, random word, the saved pattern inside the
 *     pg_pat[9:0] field of the PATTERNGEN register, and the inverted pg_pat[9:0] values (for
 *     example, 9 bits of 0's, 9 bits of 1's, 3FF, pg_pat[9:0], ~ pg_pat[9:0]).
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_HDMI_PHY_SDCAP_MODE_PG_MODE2      (9)      //!< Bit position for HDMI_PHY_SDCAP_MODE_PG_MODE2.
#define BM_HDMI_PHY_SDCAP_MODE_PG_MODE2      (0x00000e00)  //!< Bit mask for HDMI_PHY_SDCAP_MODE_PG_MODE2.

//! @brief Get value of HDMI_PHY_SDCAP_MODE_PG_MODE2 from a register value.
#define BG_HDMI_PHY_SDCAP_MODE_PG_MODE2(r)   (((r) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE2) >> BP_HDMI_PHY_SDCAP_MODE_PG_MODE2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_PG_MODE2.
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE2(v)   ((((reg16_t) v) << BP_HDMI_PHY_SDCAP_MODE_PG_MODE2) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE2)
#else
//! @brief Format value for bitfield HDMI_PHY_SDCAP_MODE_PG_MODE2.
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE2(v)   (((v) << BP_HDMI_PHY_SDCAP_MODE_PG_MODE2) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PG_MODE2 field to a new value.
#define BW_HDMI_PHY_SDCAP_MODE_PG_MODE2(v)   (HW_HDMI_PHY_SDCAP_MODE_WR((HW_HDMI_PHY_SDCAP_MODE_RD() & ~BM_HDMI_PHY_SDCAP_MODE_PG_MODE2) | BF_HDMI_PHY_SDCAP_MODE_PG_MODE2(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCOPEMODE - Scope Mode register (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : SCOPEMODE  Access type : Read/write  Address : 0x1D  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_scopemode
{
    reg16_t U;
    struct _hw_hdmi_phy_scopemode_bitfields
    {
        unsigned short SCOPE_SAMPLE_CNT : 10; //!< [9:0] Scope Sample Counter Indicates the number of samples that will be counted (should be multiple of the LFSR length). This count includes only the LSB bits; if the LFSR15 was used, you must program the new bits under the 0x24 register.
        unsigned short SCOPE_ENB0 : 1; //!< [10] Scope Enable 0 This bit enables or disables the tracing of 1's on channel 0.
        unsigned short SCOPE_ENB1 : 1; //!< [11] Scope Enable 1 This bit enables or disables the tracing of 1's on channel 1.
        unsigned short SCOPE_ENB2 : 1; //!< [12] Scope Enable 2 This bit enables or disables the tracing of 1's on channel 2.
        unsigned short CK_SCOPE_ENB : 1; //!< [13] Clock Scope Enable This bit enables or disables the tracing of 1's on the clock channel.
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved
    } B;
} hw_hdmi_phy_scopemode_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPEMODE register
 */
#define HW_HDMI_PHY_SCOPEMODE_ADDR      (REGS_HDMI_PHY_BASE + 0x1d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPEMODE           (*(volatile hw_hdmi_phy_scopemode_t *) HW_HDMI_PHY_SCOPEMODE_ADDR)
#define HW_HDMI_PHY_SCOPEMODE_RD()      (HW_HDMI_PHY_SCOPEMODE.U)
#define HW_HDMI_PHY_SCOPEMODE_WR(v)     (HW_HDMI_PHY_SCOPEMODE.U = (v))
#define HW_HDMI_PHY_SCOPEMODE_SET(v)    (HW_HDMI_PHY_SCOPEMODE_WR(HW_HDMI_PHY_SCOPEMODE_RD() |  (v)))
#define HW_HDMI_PHY_SCOPEMODE_CLR(v)    (HW_HDMI_PHY_SCOPEMODE_WR(HW_HDMI_PHY_SCOPEMODE_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPEMODE_TOG(v)    (HW_HDMI_PHY_SCOPEMODE_WR(HW_HDMI_PHY_SCOPEMODE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_SCOPEMODE bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPEMODE, field SCOPE_SAMPLE_CNT[9:0] (RW)
 *
 * Scope Sample Counter Indicates the number of samples that will be counted (should be multiple of
 * the LFSR length). This count includes only the LSB bits; if the LFSR15 was used, you must program
 * the new bits under the 0x24 register.
 */

#define BP_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT      (0)      //!< Bit position for HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT.
#define BM_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT      (0x000003ff)  //!< Bit mask for HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT.

//! @brief Get value of HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT from a register value.
#define BG_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT(r)   (((r) & BM_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT) >> BP_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT.
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT(v)   ((((reg16_t) v) << BP_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT) & BM_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT)
#else
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT.
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT(v)   (((v) << BP_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT) & BM_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_SAMPLE_CNT field to a new value.
#define BW_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT(v)   (HW_HDMI_PHY_SCOPEMODE_WR((HW_HDMI_PHY_SCOPEMODE_RD() & ~BM_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT) | BF_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT(v)))
#endif

/* --- Register HW_HDMI_PHY_SCOPEMODE, field SCOPE_ENB0[10] (RW)
 *
 * Scope Enable 0 This bit enables or disables the tracing of 1's on channel 0.
 *
 * Values:
 * 0 - Disable the tracing of 1's on the first channel.
 * 1 - Enable the tracing of 1's on the first channel.
 */

#define BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB0      (10)      //!< Bit position for HDMI_PHY_SCOPEMODE_SCOPE_ENB0.
#define BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB0      (0x00000400)  //!< Bit mask for HDMI_PHY_SCOPEMODE_SCOPE_ENB0.

//! @brief Get value of HDMI_PHY_SCOPEMODE_SCOPE_ENB0 from a register value.
#define BG_HDMI_PHY_SCOPEMODE_SCOPE_ENB0(r)   (((r) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB0) >> BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_SCOPE_ENB0.
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB0(v)   ((((reg16_t) v) << BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB0) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB0)
#else
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_SCOPE_ENB0.
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB0(v)   (((v) << BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB0) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_ENB0 field to a new value.
#define BW_HDMI_PHY_SCOPEMODE_SCOPE_ENB0(v)   (HW_HDMI_PHY_SCOPEMODE_WR((HW_HDMI_PHY_SCOPEMODE_RD() & ~BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB0) | BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB0(v)))
#endif


/* --- Register HW_HDMI_PHY_SCOPEMODE, field SCOPE_ENB1[11] (RW)
 *
 * Scope Enable 1 This bit enables or disables the tracing of 1's on channel 1.
 *
 * Values:
 * 0 - Disable the tracing of 1's on the second channel.
 * 1 - Enable the tracing of 1's on the second channel.
 */

#define BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB1      (11)      //!< Bit position for HDMI_PHY_SCOPEMODE_SCOPE_ENB1.
#define BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB1      (0x00000800)  //!< Bit mask for HDMI_PHY_SCOPEMODE_SCOPE_ENB1.

//! @brief Get value of HDMI_PHY_SCOPEMODE_SCOPE_ENB1 from a register value.
#define BG_HDMI_PHY_SCOPEMODE_SCOPE_ENB1(r)   (((r) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB1) >> BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_SCOPE_ENB1.
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB1(v)   ((((reg16_t) v) << BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB1) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB1)
#else
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_SCOPE_ENB1.
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB1(v)   (((v) << BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB1) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_ENB1 field to a new value.
#define BW_HDMI_PHY_SCOPEMODE_SCOPE_ENB1(v)   (HW_HDMI_PHY_SCOPEMODE_WR((HW_HDMI_PHY_SCOPEMODE_RD() & ~BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB1) | BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB1(v)))
#endif


/* --- Register HW_HDMI_PHY_SCOPEMODE, field SCOPE_ENB2[12] (RW)
 *
 * Scope Enable 2 This bit enables or disables the tracing of 1's on channel 2.
 *
 * Values:
 * 0 - Disable the tracing of 1's on the third channel.
 * 1 - Enable the tracing of 1's on the third channel.
 */

#define BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB2      (12)      //!< Bit position for HDMI_PHY_SCOPEMODE_SCOPE_ENB2.
#define BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB2      (0x00001000)  //!< Bit mask for HDMI_PHY_SCOPEMODE_SCOPE_ENB2.

//! @brief Get value of HDMI_PHY_SCOPEMODE_SCOPE_ENB2 from a register value.
#define BG_HDMI_PHY_SCOPEMODE_SCOPE_ENB2(r)   (((r) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB2) >> BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_SCOPE_ENB2.
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB2(v)   ((((reg16_t) v) << BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB2) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB2)
#else
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_SCOPE_ENB2.
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB2(v)   (((v) << BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB2) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_ENB2 field to a new value.
#define BW_HDMI_PHY_SCOPEMODE_SCOPE_ENB2(v)   (HW_HDMI_PHY_SCOPEMODE_WR((HW_HDMI_PHY_SCOPEMODE_RD() & ~BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB2) | BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB2(v)))
#endif


/* --- Register HW_HDMI_PHY_SCOPEMODE, field CK_SCOPE_ENB[13] (RW)
 *
 * Clock Scope Enable This bit enables or disables the tracing of 1's on the clock channel.
 *
 * Values:
 * 0 - Disable the tracing of 1's on the clock.
 * 1 - Enable the tracing of 1's on the clock.
 */

#define BP_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB      (13)      //!< Bit position for HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB.
#define BM_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB      (0x00002000)  //!< Bit mask for HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB.

//! @brief Get value of HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB from a register value.
#define BG_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB(r)   (((r) & BM_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB) >> BP_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB.
#define BF_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB(v)   ((((reg16_t) v) << BP_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB) & BM_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB)
#else
//! @brief Format value for bitfield HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB.
#define BF_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB(v)   (((v) << BP_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB) & BM_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CK_SCOPE_ENB field to a new value.
#define BW_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB(v)   (HW_HDMI_PHY_SCOPEMODE_WR((HW_HDMI_PHY_SCOPEMODE_RD() & ~BM_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB) | BF_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_DIGTXMODE - Digital Transmission Mode (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : DIGTXMODE  Access type : Read/write  Address : 0x1E  Value at reset : 0x0000
 * dtb_select[6:0]   The dtb_select[6:0] encodings for the bit pairs are as follows:   Power
 * Sequence    0x00: dtb[1] = pll_pwr_on and dtb[0] = pll_rst  0x01: dtb[1] = pll_pwr_on and dtb[0]
 * = pll_gear_shift  0x02: dtb[1] = pll_pwr_on and dtb[0] = pll_drv_ana  0x03: dtb[1] = pll_pwr_on
 * and dtb[0] = cko_word_enb  0x04: dtb[1] = pll_pwr_on and dtb[0] = tx_ready  0x05: dtb[1] =
 * mpll_pwr_on and dtb[0] = mpll_rst  0x06: dtb[1] = mpll_pwr_on and dtb[0] = mpll_gear_shift  0x07:
 * dtb[1] = mpll_pwr_on and dtb[0] = mpll_drv_ana  0x08: dtb[1] = mpll_pwr_on and dtb[0] =
 * cko_word_enb  0x09: dtb[1] = mpll_pwr_on and dtb[0] = tx_ready  0x0A: dtb[1] = mpll_pwr_on and
 * dtb[0] = tx_ser_div_en1  0x0B: dtb[1] = mpll_pwr_on and dtb[0] = tx_ser_clk_en1  0x0C: dtb[1] =
 * ck_ref_enb and dtb[0] = refclk_enb  0x0D: dtb[1] = cko_word_enb and dtb[0] = refclk_enb
 * Transmission Clock Alignment    0x0E: Reserved  0x0F: dtb[1] = tx_ck_align_enb and dtb[0] =
 * tx_ser_clk_kill0  0x10: dtb[1] = tx_ck_align_enb and dtb[0] = tx_ser_clk_kill1  0x11: dtb[1] =
 * tx_ck_align_enb and dtb[0] = tx_ser_clk_kill2  0x12: dtb[1] = tx_ck_align_enb and dtb[0] =
 * tx_ck_align_done    Resistance Calibration and Analog-to-Digital Converter    0x13: Reserved
 * 0x14: dtb[1] = ck_rescal[6] and dtb[0] = ck_rescal[5]  0x15: dtb[1] = ck_rescal[4] and dtb[0] =
 * ck_rescal[3]  0x16: dtb[1] = ck_rescal[2] and dtb[0] = ck_rescal[1]  0x17: dtb[1] = ck_rescal[0]
 * and dtb[0] = sup_comp_mode  0x18: dtb[1] = sup_comp_rt_result and dtb[0] = sup_comp_rt_r  0x19:
 * dtb[1] = sup_dac_n[7] and dtb[0] = sup_dac_n[6]  0x1A: dtb[1] = sup_dac_n[5] and dtb[0] =
 * sup_dac_n[4]  0x1B: dtb[1] = sup_dac_n[3] and dtb[0] = sup_dac_n[2]  0x1C: dtb[1] = sup_dac_n[1]
 * and dtb[0] = sup_dac_n[0]  0x1D: dtb[1] = sup_dac_th_n[2] and dtb[0] = sup_dac_th_n[1]  0x1E:
 * dtb[1] = sup_dac_th_n[0] and dtb[0] = rescal_rep[6]  0x1F: dtb[1] = rescal_rep[5] and dtb[0] =
 * rescal_rep[4]  0x20: dtb[1] = rescal_rep[3] and dtb[0] = rescal_rep[2]  0x21: dtb[1] =
 * rescal_rep[1] and dtb[0] = rescal_rep[0]  0x22: dtb[1] = rcal_enb and dtb[0] = rcal_adc_done
 * 0x23: dtb[1] = sup_comp_rt_pwron and dtb[0] = rcal_adc_done  0x24: Reserved  0x25: Reserved
 * 0x26: Reserved  0x27: Reserved    TMDS Data Pattern    0x28: dtb[1] = tmds_data2[9] and dtb[0] =
 * tmds_data2[8]  0x29: dtb[1] = tmds_data2[8] and dtb[0] = tmds_data2[7]  0x2A: dtb[1] =
 * tmds_data2[7] and dtb[0] = tmds_data2[6]  0x2B: dtb[1] = tmds_data2[6] and dtb[0] = tmds_data2[5]
 * 0x2C: dtb[1] = tmds_data2[5] and dtb[0] = tmds_data2[4]  0x2D: dtb[1] = tmds_data2[4] and dtb[0]
 * = tmds_data2[3]  0x2E: dtb[1] = tmds_data2[3] and dtb[0] = tmds_data2[2]  0x2F: dtb[1] =
 * tmds_data2[2] and dtb[0] = tmds_data2[1]  0x30: dtb[1] = tmds_data2[1] and dtb[0] = tmds_data2[0]
 * 0x31: dtb[1] = tmds_data2[0] and dtb[0] = tmds_data1[9]  0x32: dtb[1] = tmds_data1[9] and dtb[0]
 * = tmds_data1[8]  0x33: dtb[1] = tmds_data1[8] and dtb[0] = tmds_data1[7]  0x34: dtb[1] =
 * tmds_data1[7] and dtb[0] = tmds_data1[6]  0x35: dtb[1] = tmds_data1[6] and dtb[0] = tmds_data1[5]
 * 0x36: dtb[1] = tmds_data1[5] and dtb[0] = tmds_data1[4]  0x37: dtb[1] = tmds_data1[4] and dtb[0]
 * = tmds_data1[3]  0x38: dtb[1] = tmds_data1[3] and dtb[0] = tmds_data1[2]  0x39: dtb[1] =
 * tmds_data1[2] and dtb[0] = tmds_data1[1]  0x3A: dtb[1] = tmds_data1[1] and dtb[0] = tmds_data1[0]
 * 0x3B: dtb[1] = tmds_data1[0] and dtb[0] = tmds_data0[9]  0x3C: dtb[1] = tmds_data0[9] and dtb[0]
 * = tmds_data0[8]  0x3D: dtb[1] = tmds_data0[8] and dtb[0] = tmds_data0[7]  0x3E: dtb[1] =
 * tmds_data0[7] and dtb[0] = tmds_data0[6]  0x3F: dtb[1] = tmds_data0[6] and dtb[0] = tmds_data0[5]
 * 0x40: dtb[1] = tmds_data0[5] and dtb[0] = tmds_data0[4]  0x41: dtb[1] = tmds_data0[4] and dtb[0]
 * = tmds_data0[3]  0x42: dtb[1] = tmds_data0[3] and dtb[0] = tmds_data0[2]  0x43: dtb[1] =
 * tmds_data0[2] and dtb[0] = tmds_data0[1]  0x44: dtb[1] = tmds_data0[1] and dtb[0] = tmds_data0[0]
 * 0x45: dtb[1] = tmds_data0[0] and dtb[0] = tx_ready    Pattern Generator    0x46: dtb[1] =
 * tmds_data2[0] and dtb[0] = pg_dtb2  0x47: dtb[1] = tmds_data1[0] and dtb[0] = pg_dtb1  0x48:
 * dtb[1] = tmds_data0[0] and dtb[0] = pg_dtb0  0x49: dtb[1] = pg_dtb2 and dtb[0] = pg_dtb0  0x4A:
 * dtb[1] = pg_dtb1 and dtb[0] = pg_dtb0  0x4B: Reserved  0x4C: Reserved  0x4D: Reserved  0x4E:
 * Reserved  0x4F: Reserved    Scope    0x50: dtb[1] = scope_enb2 and dtb[0] = scope_done2  0x51:
 * dtb[1] = scope_enb1 and dtb[0] = scope_done1  0x52: dtb[1] = scope_enb0 and dtb[0] = scope_done0
 * 0x53: dtb[1] = ck_scope_enb and dtb[0] = ck_scope_done  0x54: dtb[1] = scope_enb2 and dtb[0] =
 * tx_scope_out2  0x55: dtb[1] = scope_enb1 and dtb[0] = tx_scope_out1  0x56: dtb[1] = scope_enb0
 * and dtb[0] = tx_scope_out0  0x57: Reserved  0x58: Reserved  0x59: Reserved    I  2  C    0x5A:
 * dtb[1] = start_cond and dtb[0] = cregs_write (Not stored in the control register.)  0x5B: dtb[1]
 * = sda_pull_dn_n and dtb[0] = cregs_ack (Not stored in the control register.)  0x5C: dtb[1] =
 * cregs_read and dtb[0] = cregs_rd_data[0] (Not stored in the control register.)  0x5D: Reserved
 * 0x5E: Reserved  0x5F: Reserved  0x60: Reserved  0x61: Reserved  0x62: Reserved  0x63: Reserved
 * Rx Sense    0x64: dtb[1] = rx_sense of clock driver and dtb[0] = rx_sense of CH2's driver  0x65:
 * dtb[1] = rx_sense of CH1's driver and dtb[0] = rx_sense of CH0's driver  0x66: -
 */
typedef union _hw_hdmi_phy_digtxmode
{
    reg16_t U;
    struct _hw_hdmi_phy_digtxmode_bitfields
    {
        unsigned short SKIP_BIT0 : 1; //!< [0] Skip Bit 0 This bit enables or disables skipping of the ninth bit of the transmitted pattern on channel 0.
        unsigned short SKIP_BIT1 : 1; //!< [1] Skip Bit 1 This bit enables or disables skipping of the ninth bit of the transmitted pattern on channel 1.
        unsigned short SKIP_BIT2 : 1; //!< [2] Skip Bit 2 This bit enables or disables skipping of the ninth bit of the transmitted pattern on channel 2.
        unsigned short CKO_WORD_DIV_ENB : 1; //!< [3] Clock Output Word Divider Enable This bit enables or disables the output clock word divider.
        unsigned short INVERT_DATA0 : 1; //!< [4] Inverter Data 0 This bit enables or disables the inverting feature for the transmitted pattern on channel 0.
        unsigned short INVERT_DATA1 : 1; //!< [5] Inverter Data 1 This bit enables or disables the inverting feature for the transmitted pattern on channel 1.
        unsigned short INVERT_DATA2 : 1; //!< [6] Inverter Data 2 This bit enables or disables the inverting feature for the transmitted pattern on channel 2.
        unsigned short DTB_SELECT : 6; //!< [12:7] Debug Test Bus Select This field determines the pair of bits placed on the dtb[1:0] bus. These selected pairs of bits come from the control register. The values that appear on dtb[1:0] are the current values actually stored in the control register (not the override values) with the exception of I 2 C values, which are not stored in the control register. For information about the bit pairs, see dtb_select[6:0] .
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved
    } B;
} hw_hdmi_phy_digtxmode_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_DIGTXMODE register
 */
#define HW_HDMI_PHY_DIGTXMODE_ADDR      (REGS_HDMI_PHY_BASE + 0x1e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_DIGTXMODE           (*(volatile hw_hdmi_phy_digtxmode_t *) HW_HDMI_PHY_DIGTXMODE_ADDR)
#define HW_HDMI_PHY_DIGTXMODE_RD()      (HW_HDMI_PHY_DIGTXMODE.U)
#define HW_HDMI_PHY_DIGTXMODE_WR(v)     (HW_HDMI_PHY_DIGTXMODE.U = (v))
#define HW_HDMI_PHY_DIGTXMODE_SET(v)    (HW_HDMI_PHY_DIGTXMODE_WR(HW_HDMI_PHY_DIGTXMODE_RD() |  (v)))
#define HW_HDMI_PHY_DIGTXMODE_CLR(v)    (HW_HDMI_PHY_DIGTXMODE_WR(HW_HDMI_PHY_DIGTXMODE_RD() & ~(v)))
#define HW_HDMI_PHY_DIGTXMODE_TOG(v)    (HW_HDMI_PHY_DIGTXMODE_WR(HW_HDMI_PHY_DIGTXMODE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_DIGTXMODE bitfields
 */

/* --- Register HW_HDMI_PHY_DIGTXMODE, field SKIP_BIT0[0] (RW)
 *
 * Skip Bit 0 This bit enables or disables skipping of the ninth bit of the transmitted pattern on
 * channel 0.
 *
 * Values:
 * 0 - Disable the skipping feature on the first channel.
 * 1 - Enable the skipping feature on the first channel.
 */

#define BP_HDMI_PHY_DIGTXMODE_SKIP_BIT0      (0)      //!< Bit position for HDMI_PHY_DIGTXMODE_SKIP_BIT0.
#define BM_HDMI_PHY_DIGTXMODE_SKIP_BIT0      (0x00000001)  //!< Bit mask for HDMI_PHY_DIGTXMODE_SKIP_BIT0.

//! @brief Get value of HDMI_PHY_DIGTXMODE_SKIP_BIT0 from a register value.
#define BG_HDMI_PHY_DIGTXMODE_SKIP_BIT0(r)   (((r) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT0) >> BP_HDMI_PHY_DIGTXMODE_SKIP_BIT0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_SKIP_BIT0.
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT0(v)   ((((reg16_t) v) << BP_HDMI_PHY_DIGTXMODE_SKIP_BIT0) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT0)
#else
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_SKIP_BIT0.
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT0(v)   (((v) << BP_HDMI_PHY_DIGTXMODE_SKIP_BIT0) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SKIP_BIT0 field to a new value.
#define BW_HDMI_PHY_DIGTXMODE_SKIP_BIT0(v)   (HW_HDMI_PHY_DIGTXMODE_WR((HW_HDMI_PHY_DIGTXMODE_RD() & ~BM_HDMI_PHY_DIGTXMODE_SKIP_BIT0) | BF_HDMI_PHY_DIGTXMODE_SKIP_BIT0(v)))
#endif


/* --- Register HW_HDMI_PHY_DIGTXMODE, field SKIP_BIT1[1] (RW)
 *
 * Skip Bit 1 This bit enables or disables skipping of the ninth bit of the transmitted pattern on
 * channel 1.
 *
 * Values:
 * 0 - Disable the skipping feature on the second channel.
 * 1 - Enable the skipping feature on the second channel.
 */

#define BP_HDMI_PHY_DIGTXMODE_SKIP_BIT1      (1)      //!< Bit position for HDMI_PHY_DIGTXMODE_SKIP_BIT1.
#define BM_HDMI_PHY_DIGTXMODE_SKIP_BIT1      (0x00000002)  //!< Bit mask for HDMI_PHY_DIGTXMODE_SKIP_BIT1.

//! @brief Get value of HDMI_PHY_DIGTXMODE_SKIP_BIT1 from a register value.
#define BG_HDMI_PHY_DIGTXMODE_SKIP_BIT1(r)   (((r) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT1) >> BP_HDMI_PHY_DIGTXMODE_SKIP_BIT1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_SKIP_BIT1.
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT1(v)   ((((reg16_t) v) << BP_HDMI_PHY_DIGTXMODE_SKIP_BIT1) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT1)
#else
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_SKIP_BIT1.
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT1(v)   (((v) << BP_HDMI_PHY_DIGTXMODE_SKIP_BIT1) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SKIP_BIT1 field to a new value.
#define BW_HDMI_PHY_DIGTXMODE_SKIP_BIT1(v)   (HW_HDMI_PHY_DIGTXMODE_WR((HW_HDMI_PHY_DIGTXMODE_RD() & ~BM_HDMI_PHY_DIGTXMODE_SKIP_BIT1) | BF_HDMI_PHY_DIGTXMODE_SKIP_BIT1(v)))
#endif


/* --- Register HW_HDMI_PHY_DIGTXMODE, field SKIP_BIT2[2] (RW)
 *
 * Skip Bit 2 This bit enables or disables skipping of the ninth bit of the transmitted pattern on
 * channel 2.
 *
 * Values:
 * 0 - Disable the skipping feature on the third channel.
 * 1 - Enable the skipping feature on the third channel.
 */

#define BP_HDMI_PHY_DIGTXMODE_SKIP_BIT2      (2)      //!< Bit position for HDMI_PHY_DIGTXMODE_SKIP_BIT2.
#define BM_HDMI_PHY_DIGTXMODE_SKIP_BIT2      (0x00000004)  //!< Bit mask for HDMI_PHY_DIGTXMODE_SKIP_BIT2.

//! @brief Get value of HDMI_PHY_DIGTXMODE_SKIP_BIT2 from a register value.
#define BG_HDMI_PHY_DIGTXMODE_SKIP_BIT2(r)   (((r) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT2) >> BP_HDMI_PHY_DIGTXMODE_SKIP_BIT2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_SKIP_BIT2.
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT2(v)   ((((reg16_t) v) << BP_HDMI_PHY_DIGTXMODE_SKIP_BIT2) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT2)
#else
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_SKIP_BIT2.
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT2(v)   (((v) << BP_HDMI_PHY_DIGTXMODE_SKIP_BIT2) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SKIP_BIT2 field to a new value.
#define BW_HDMI_PHY_DIGTXMODE_SKIP_BIT2(v)   (HW_HDMI_PHY_DIGTXMODE_WR((HW_HDMI_PHY_DIGTXMODE_RD() & ~BM_HDMI_PHY_DIGTXMODE_SKIP_BIT2) | BF_HDMI_PHY_DIGTXMODE_SKIP_BIT2(v)))
#endif


/* --- Register HW_HDMI_PHY_DIGTXMODE, field CKO_WORD_DIV_ENB[3] (RW)
 *
 * Clock Output Word Divider Enable This bit enables or disables the output clock word divider.
 *
 * Values:
 * 0 - Disable the output clock divider.
 * 1 - Enable the output clock divider.
 */

#define BP_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB      (3)      //!< Bit position for HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB.
#define BM_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB      (0x00000008)  //!< Bit mask for HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB.

//! @brief Get value of HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB from a register value.
#define BG_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB(r)   (((r) & BM_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB) >> BP_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB.
#define BF_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB(v)   ((((reg16_t) v) << BP_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB) & BM_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB)
#else
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB.
#define BF_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB(v)   (((v) << BP_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB) & BM_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO_WORD_DIV_ENB field to a new value.
#define BW_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB(v)   (HW_HDMI_PHY_DIGTXMODE_WR((HW_HDMI_PHY_DIGTXMODE_RD() & ~BM_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB) | BF_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB(v)))
#endif


/* --- Register HW_HDMI_PHY_DIGTXMODE, field INVERT_DATA0[4] (RW)
 *
 * Inverter Data 0 This bit enables or disables the inverting feature for the transmitted pattern on
 * channel 0.
 *
 * Values:
 * 0 - Disable the inverting feature on the first channel.
 * 1 - Enable the inverting feature on the first channel.
 */

#define BP_HDMI_PHY_DIGTXMODE_INVERT_DATA0      (4)      //!< Bit position for HDMI_PHY_DIGTXMODE_INVERT_DATA0.
#define BM_HDMI_PHY_DIGTXMODE_INVERT_DATA0      (0x00000010)  //!< Bit mask for HDMI_PHY_DIGTXMODE_INVERT_DATA0.

//! @brief Get value of HDMI_PHY_DIGTXMODE_INVERT_DATA0 from a register value.
#define BG_HDMI_PHY_DIGTXMODE_INVERT_DATA0(r)   (((r) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA0) >> BP_HDMI_PHY_DIGTXMODE_INVERT_DATA0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_INVERT_DATA0.
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA0(v)   ((((reg16_t) v) << BP_HDMI_PHY_DIGTXMODE_INVERT_DATA0) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA0)
#else
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_INVERT_DATA0.
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA0(v)   (((v) << BP_HDMI_PHY_DIGTXMODE_INVERT_DATA0) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INVERT_DATA0 field to a new value.
#define BW_HDMI_PHY_DIGTXMODE_INVERT_DATA0(v)   (HW_HDMI_PHY_DIGTXMODE_WR((HW_HDMI_PHY_DIGTXMODE_RD() & ~BM_HDMI_PHY_DIGTXMODE_INVERT_DATA0) | BF_HDMI_PHY_DIGTXMODE_INVERT_DATA0(v)))
#endif


/* --- Register HW_HDMI_PHY_DIGTXMODE, field INVERT_DATA1[5] (RW)
 *
 * Inverter Data 1 This bit enables or disables the inverting feature for the transmitted pattern on
 * channel 1.
 *
 * Values:
 * 0 - Disable the inverting feature on the second channel.
 * 1 - Enable the inverting feature on the second channel.
 */

#define BP_HDMI_PHY_DIGTXMODE_INVERT_DATA1      (5)      //!< Bit position for HDMI_PHY_DIGTXMODE_INVERT_DATA1.
#define BM_HDMI_PHY_DIGTXMODE_INVERT_DATA1      (0x00000020)  //!< Bit mask for HDMI_PHY_DIGTXMODE_INVERT_DATA1.

//! @brief Get value of HDMI_PHY_DIGTXMODE_INVERT_DATA1 from a register value.
#define BG_HDMI_PHY_DIGTXMODE_INVERT_DATA1(r)   (((r) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA1) >> BP_HDMI_PHY_DIGTXMODE_INVERT_DATA1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_INVERT_DATA1.
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA1(v)   ((((reg16_t) v) << BP_HDMI_PHY_DIGTXMODE_INVERT_DATA1) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA1)
#else
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_INVERT_DATA1.
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA1(v)   (((v) << BP_HDMI_PHY_DIGTXMODE_INVERT_DATA1) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INVERT_DATA1 field to a new value.
#define BW_HDMI_PHY_DIGTXMODE_INVERT_DATA1(v)   (HW_HDMI_PHY_DIGTXMODE_WR((HW_HDMI_PHY_DIGTXMODE_RD() & ~BM_HDMI_PHY_DIGTXMODE_INVERT_DATA1) | BF_HDMI_PHY_DIGTXMODE_INVERT_DATA1(v)))
#endif


/* --- Register HW_HDMI_PHY_DIGTXMODE, field INVERT_DATA2[6] (RW)
 *
 * Inverter Data 2 This bit enables or disables the inverting feature for the transmitted pattern on
 * channel 2.
 *
 * Values:
 * 0 - Disable the inverting feature on the third channel.
 * 1 - Enable the inverting feature on the third channel.
 */

#define BP_HDMI_PHY_DIGTXMODE_INVERT_DATA2      (6)      //!< Bit position for HDMI_PHY_DIGTXMODE_INVERT_DATA2.
#define BM_HDMI_PHY_DIGTXMODE_INVERT_DATA2      (0x00000040)  //!< Bit mask for HDMI_PHY_DIGTXMODE_INVERT_DATA2.

//! @brief Get value of HDMI_PHY_DIGTXMODE_INVERT_DATA2 from a register value.
#define BG_HDMI_PHY_DIGTXMODE_INVERT_DATA2(r)   (((r) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA2) >> BP_HDMI_PHY_DIGTXMODE_INVERT_DATA2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_INVERT_DATA2.
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA2(v)   ((((reg16_t) v) << BP_HDMI_PHY_DIGTXMODE_INVERT_DATA2) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA2)
#else
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_INVERT_DATA2.
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA2(v)   (((v) << BP_HDMI_PHY_DIGTXMODE_INVERT_DATA2) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INVERT_DATA2 field to a new value.
#define BW_HDMI_PHY_DIGTXMODE_INVERT_DATA2(v)   (HW_HDMI_PHY_DIGTXMODE_WR((HW_HDMI_PHY_DIGTXMODE_RD() & ~BM_HDMI_PHY_DIGTXMODE_INVERT_DATA2) | BF_HDMI_PHY_DIGTXMODE_INVERT_DATA2(v)))
#endif


/* --- Register HW_HDMI_PHY_DIGTXMODE, field DTB_SELECT[12:7] (RW)
 *
 * Debug Test Bus Select This field determines the pair of bits placed on the dtb[1:0] bus. These
 * selected pairs of bits come from the control register. The values that appear on dtb[1:0] are the
 * current values actually stored in the control register (not the override values) with the
 * exception of I 2 C values, which are not stored in the control register. For information about
 * the bit pairs, see dtb_select[6:0] .
 */

#define BP_HDMI_PHY_DIGTXMODE_DTB_SELECT      (7)      //!< Bit position for HDMI_PHY_DIGTXMODE_DTB_SELECT.
#define BM_HDMI_PHY_DIGTXMODE_DTB_SELECT      (0x00001f80)  //!< Bit mask for HDMI_PHY_DIGTXMODE_DTB_SELECT.

//! @brief Get value of HDMI_PHY_DIGTXMODE_DTB_SELECT from a register value.
#define BG_HDMI_PHY_DIGTXMODE_DTB_SELECT(r)   (((r) & BM_HDMI_PHY_DIGTXMODE_DTB_SELECT) >> BP_HDMI_PHY_DIGTXMODE_DTB_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_DTB_SELECT.
#define BF_HDMI_PHY_DIGTXMODE_DTB_SELECT(v)   ((((reg16_t) v) << BP_HDMI_PHY_DIGTXMODE_DTB_SELECT) & BM_HDMI_PHY_DIGTXMODE_DTB_SELECT)
#else
//! @brief Format value for bitfield HDMI_PHY_DIGTXMODE_DTB_SELECT.
#define BF_HDMI_PHY_DIGTXMODE_DTB_SELECT(v)   (((v) << BP_HDMI_PHY_DIGTXMODE_DTB_SELECT) & BM_HDMI_PHY_DIGTXMODE_DTB_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SELECT field to a new value.
#define BW_HDMI_PHY_DIGTXMODE_DTB_SELECT(v)   (HW_HDMI_PHY_DIGTXMODE_WR((HW_HDMI_PHY_DIGTXMODE_RD() & ~BM_HDMI_PHY_DIGTXMODE_DTB_SELECT) | BF_HDMI_PHY_DIGTXMODE_DTB_SELECT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_STR_STATUS - Scope, Transmission Clock Alignment, and Resistance Calibration Set-on-Done Status (RW)
 *
 * Reset value: 0x00000000
 *
 * Register name : -  Access type : Read/write/asynchronous set-on-done  Address : 0x1F  Value at
 * reset : 0x0000
 */
typedef union _hw_hdmi_phy_str_status
{
    reg16_t U;
    struct _hw_hdmi_phy_str_status_bitfields
    {
        unsigned short SCOPE_DONE0 : 1; //!< [0] Scope Done 0 This bit indicates the status of tracing of 1's on channel 0.
        unsigned short SCOPE_DONE1 : 1; //!< [1] Scope Done 1 This bit indicates the status of tracing of 1's on channel 1.
        unsigned short SCOPE_DONE2 : 1; //!< [2] Scope Done 2 This bit indicates the status of tracing of 1's on channel 2.
        unsigned short CK_SCOPE_DONE : 1; //!< [3] Clock Scope Done This bit indicates the status of tracing of 1's on the clock channel.
        unsigned short TX_CK_ALIGN_DONE : 1; //!< [4] Transmission Clock Alignment Done This bit indicates the status of completing the transmission clock alignment FSM.
        unsigned short RCAL_ADC_DONE : 1; //!< [5] Resistance Calibration Analog-to-Digital Converter Done This bit indicates the status of completing the resistance calibration FSM.
        unsigned short RESERVED0 : 10; //!< [15:6] Reserved
    } B;
} hw_hdmi_phy_str_status_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_STR_STATUS register
 */
#define HW_HDMI_PHY_STR_STATUS_ADDR      (REGS_HDMI_PHY_BASE + 0x1f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_STR_STATUS           (*(volatile hw_hdmi_phy_str_status_t *) HW_HDMI_PHY_STR_STATUS_ADDR)
#define HW_HDMI_PHY_STR_STATUS_RD()      (HW_HDMI_PHY_STR_STATUS.U)
#define HW_HDMI_PHY_STR_STATUS_WR(v)     (HW_HDMI_PHY_STR_STATUS.U = (v))
#define HW_HDMI_PHY_STR_STATUS_SET(v)    (HW_HDMI_PHY_STR_STATUS_WR(HW_HDMI_PHY_STR_STATUS_RD() |  (v)))
#define HW_HDMI_PHY_STR_STATUS_CLR(v)    (HW_HDMI_PHY_STR_STATUS_WR(HW_HDMI_PHY_STR_STATUS_RD() & ~(v)))
#define HW_HDMI_PHY_STR_STATUS_TOG(v)    (HW_HDMI_PHY_STR_STATUS_WR(HW_HDMI_PHY_STR_STATUS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_STR_STATUS bitfields
 */

/* --- Register HW_HDMI_PHY_STR_STATUS, field SCOPE_DONE0[0] (RW)
 *
 * Scope Done 0 This bit indicates the status of tracing of 1's on channel 0.
 *
 * Values:
 * 0 - The tracing process on channel 0 is not complete.
 * 1 - The tracing process on channel 0 is complete.
 */

#define BP_HDMI_PHY_STR_STATUS_SCOPE_DONE0      (0)      //!< Bit position for HDMI_PHY_STR_STATUS_SCOPE_DONE0.
#define BM_HDMI_PHY_STR_STATUS_SCOPE_DONE0      (0x00000001)  //!< Bit mask for HDMI_PHY_STR_STATUS_SCOPE_DONE0.

//! @brief Get value of HDMI_PHY_STR_STATUS_SCOPE_DONE0 from a register value.
#define BG_HDMI_PHY_STR_STATUS_SCOPE_DONE0(r)   (((r) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE0) >> BP_HDMI_PHY_STR_STATUS_SCOPE_DONE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_SCOPE_DONE0.
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE0(v)   ((((reg16_t) v) << BP_HDMI_PHY_STR_STATUS_SCOPE_DONE0) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE0)
#else
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_SCOPE_DONE0.
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE0(v)   (((v) << BP_HDMI_PHY_STR_STATUS_SCOPE_DONE0) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_DONE0 field to a new value.
#define BW_HDMI_PHY_STR_STATUS_SCOPE_DONE0(v)   (HW_HDMI_PHY_STR_STATUS_WR((HW_HDMI_PHY_STR_STATUS_RD() & ~BM_HDMI_PHY_STR_STATUS_SCOPE_DONE0) | BF_HDMI_PHY_STR_STATUS_SCOPE_DONE0(v)))
#endif


/* --- Register HW_HDMI_PHY_STR_STATUS, field SCOPE_DONE1[1] (RW)
 *
 * Scope Done 1 This bit indicates the status of tracing of 1's on channel 1.
 *
 * Values:
 * 0 - The tracing process on channel 1 is not complete.
 * 1 - The tracing process on channel 1 is complete.
 */

#define BP_HDMI_PHY_STR_STATUS_SCOPE_DONE1      (1)      //!< Bit position for HDMI_PHY_STR_STATUS_SCOPE_DONE1.
#define BM_HDMI_PHY_STR_STATUS_SCOPE_DONE1      (0x00000002)  //!< Bit mask for HDMI_PHY_STR_STATUS_SCOPE_DONE1.

//! @brief Get value of HDMI_PHY_STR_STATUS_SCOPE_DONE1 from a register value.
#define BG_HDMI_PHY_STR_STATUS_SCOPE_DONE1(r)   (((r) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE1) >> BP_HDMI_PHY_STR_STATUS_SCOPE_DONE1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_SCOPE_DONE1.
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE1(v)   ((((reg16_t) v) << BP_HDMI_PHY_STR_STATUS_SCOPE_DONE1) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE1)
#else
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_SCOPE_DONE1.
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE1(v)   (((v) << BP_HDMI_PHY_STR_STATUS_SCOPE_DONE1) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_DONE1 field to a new value.
#define BW_HDMI_PHY_STR_STATUS_SCOPE_DONE1(v)   (HW_HDMI_PHY_STR_STATUS_WR((HW_HDMI_PHY_STR_STATUS_RD() & ~BM_HDMI_PHY_STR_STATUS_SCOPE_DONE1) | BF_HDMI_PHY_STR_STATUS_SCOPE_DONE1(v)))
#endif


/* --- Register HW_HDMI_PHY_STR_STATUS, field SCOPE_DONE2[2] (RW)
 *
 * Scope Done 2 This bit indicates the status of tracing of 1's on channel 2.
 *
 * Values:
 * 0 - The tracing process on channel 2 is not complete.
 * 1 - The tracing process on channel 2 is complete.
 */

#define BP_HDMI_PHY_STR_STATUS_SCOPE_DONE2      (2)      //!< Bit position for HDMI_PHY_STR_STATUS_SCOPE_DONE2.
#define BM_HDMI_PHY_STR_STATUS_SCOPE_DONE2      (0x00000004)  //!< Bit mask for HDMI_PHY_STR_STATUS_SCOPE_DONE2.

//! @brief Get value of HDMI_PHY_STR_STATUS_SCOPE_DONE2 from a register value.
#define BG_HDMI_PHY_STR_STATUS_SCOPE_DONE2(r)   (((r) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE2) >> BP_HDMI_PHY_STR_STATUS_SCOPE_DONE2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_SCOPE_DONE2.
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE2(v)   ((((reg16_t) v) << BP_HDMI_PHY_STR_STATUS_SCOPE_DONE2) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE2)
#else
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_SCOPE_DONE2.
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE2(v)   (((v) << BP_HDMI_PHY_STR_STATUS_SCOPE_DONE2) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_DONE2 field to a new value.
#define BW_HDMI_PHY_STR_STATUS_SCOPE_DONE2(v)   (HW_HDMI_PHY_STR_STATUS_WR((HW_HDMI_PHY_STR_STATUS_RD() & ~BM_HDMI_PHY_STR_STATUS_SCOPE_DONE2) | BF_HDMI_PHY_STR_STATUS_SCOPE_DONE2(v)))
#endif


/* --- Register HW_HDMI_PHY_STR_STATUS, field CK_SCOPE_DONE[3] (RW)
 *
 * Clock Scope Done This bit indicates the status of tracing of 1's on the clock channel.
 *
 * Values:
 * 0 - The tracing process on the clock channel is not complete.
 * 1 - The tracing process on the clock channel is complete.
 */

#define BP_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE      (3)      //!< Bit position for HDMI_PHY_STR_STATUS_CK_SCOPE_DONE.
#define BM_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE      (0x00000008)  //!< Bit mask for HDMI_PHY_STR_STATUS_CK_SCOPE_DONE.

//! @brief Get value of HDMI_PHY_STR_STATUS_CK_SCOPE_DONE from a register value.
#define BG_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE(r)   (((r) & BM_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE) >> BP_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_CK_SCOPE_DONE.
#define BF_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE(v)   ((((reg16_t) v) << BP_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE) & BM_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE)
#else
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_CK_SCOPE_DONE.
#define BF_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE(v)   (((v) << BP_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE) & BM_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CK_SCOPE_DONE field to a new value.
#define BW_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE(v)   (HW_HDMI_PHY_STR_STATUS_WR((HW_HDMI_PHY_STR_STATUS_RD() & ~BM_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE) | BF_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE(v)))
#endif


/* --- Register HW_HDMI_PHY_STR_STATUS, field TX_CK_ALIGN_DONE[4] (RW)
 *
 * Transmission Clock Alignment Done This bit indicates the status of completing the transmission
 * clock alignment FSM.
 *
 * Values:
 * 0 - The transmission clock alignment FSM is not complete.
 * 1 - The transmission clock alignment FSM is complete.
 */

#define BP_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE      (4)      //!< Bit position for HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE.
#define BM_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE      (0x00000010)  //!< Bit mask for HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE.

//! @brief Get value of HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE from a register value.
#define BG_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE(r)   (((r) & BM_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE) >> BP_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE.
#define BF_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE(v)   ((((reg16_t) v) << BP_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE) & BM_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE)
#else
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE.
#define BF_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE(v)   (((v) << BP_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE) & BM_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_CK_ALIGN_DONE field to a new value.
#define BW_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE(v)   (HW_HDMI_PHY_STR_STATUS_WR((HW_HDMI_PHY_STR_STATUS_RD() & ~BM_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE) | BF_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE(v)))
#endif


/* --- Register HW_HDMI_PHY_STR_STATUS, field RCAL_ADC_DONE[5] (RW)
 *
 * Resistance Calibration Analog-to-Digital Converter Done This bit indicates the status of
 * completing the resistance calibration FSM.
 *
 * Values:
 * 0 - The resistance calibration FSM is not complete.
 * 1 - The resistance calibration FSM is complete.
 */

#define BP_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE      (5)      //!< Bit position for HDMI_PHY_STR_STATUS_RCAL_ADC_DONE.
#define BM_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE      (0x00000020)  //!< Bit mask for HDMI_PHY_STR_STATUS_RCAL_ADC_DONE.

//! @brief Get value of HDMI_PHY_STR_STATUS_RCAL_ADC_DONE from a register value.
#define BG_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE(r)   (((r) & BM_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE) >> BP_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_RCAL_ADC_DONE.
#define BF_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE(v)   ((((reg16_t) v) << BP_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE) & BM_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE)
#else
//! @brief Format value for bitfield HDMI_PHY_STR_STATUS_RCAL_ADC_DONE.
#define BF_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE(v)   (((v) << BP_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE) & BM_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCAL_ADC_DONE field to a new value.
#define BW_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE(v)   (HW_HDMI_PHY_STR_STATUS_WR((HW_HDMI_PHY_STR_STATUS_RD() & ~BM_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE) | BF_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCOPECNT0 - Scope Counter on Channel 0 (RO)
 *
 * Reset value: 0x00000000
 *
 * Register name : SCOPECNT0  Access type : Read-only  Address : 0x20  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_scopecnt0
{
    reg16_t U;
    struct _hw_hdmi_phy_scopecnt0_bitfields
    {
        unsigned short SCOPE_ONES_CNT0 : 16; //!< [15:0] Scope 1's Counter 0 This register carries the number of counted 1's on channel 0. If the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x25 register.
    } B;
} hw_hdmi_phy_scopecnt0_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNT0 register
 */
#define HW_HDMI_PHY_SCOPECNT0_ADDR      (REGS_HDMI_PHY_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNT0           (*(volatile hw_hdmi_phy_scopecnt0_t *) HW_HDMI_PHY_SCOPECNT0_ADDR)
#define HW_HDMI_PHY_SCOPECNT0_RD()      (HW_HDMI_PHY_SCOPECNT0.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_SCOPECNT0 bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNT0, field SCOPE_ONES_CNT0[15:0] (RO)
 *
 * Scope 1's Counter 0 This register carries the number of counted 1's on channel 0. If the LFSR15
 * was used to generate the scope patterns, you must read the MSB bits under 0x25 register.
 */

#define BP_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0      (0)      //!< Bit position for HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0.
#define BM_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0      (0x0000ffff)  //!< Bit mask for HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0.

//! @brief Get value of HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0 from a register value.
#define BG_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0(r)   (((r) & BM_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0) >> BP_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCOPECNT1 - Scope Counter on Channel 1 (RO)
 *
 * Reset value: 0x00000000
 *
 * Register name : SCOPECNT1  Access type : Read-only  Address : 0x21  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_scopecnt1
{
    reg16_t U;
    struct _hw_hdmi_phy_scopecnt1_bitfields
    {
        unsigned short SCOPE_ONES_CNT1 : 16; //!< [15:0] Scope 1's Counter 1 This register carries the number of counted 1's on channel 1. If the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x25 register.
    } B;
} hw_hdmi_phy_scopecnt1_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNT1 register
 */
#define HW_HDMI_PHY_SCOPECNT1_ADDR      (REGS_HDMI_PHY_BASE + 0x21)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNT1           (*(volatile hw_hdmi_phy_scopecnt1_t *) HW_HDMI_PHY_SCOPECNT1_ADDR)
#define HW_HDMI_PHY_SCOPECNT1_RD()      (HW_HDMI_PHY_SCOPECNT1.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_SCOPECNT1 bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNT1, field SCOPE_ONES_CNT1[15:0] (RO)
 *
 * Scope 1's Counter 1 This register carries the number of counted 1's on channel 1. If the LFSR15
 * was used to generate the scope patterns, you must read the MSB bits under 0x25 register.
 */

#define BP_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1      (0)      //!< Bit position for HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1.
#define BM_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1      (0x0000ffff)  //!< Bit mask for HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1.

//! @brief Get value of HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1 from a register value.
#define BG_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1(r)   (((r) & BM_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1) >> BP_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCOPECNT2 - Scope Counter on Channel 2 (RO)
 *
 * Reset value: 0x00000000
 *
 * Register name : SCOPECNT2  Access type : Read-only  Address : 0x22  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_scopecnt2
{
    reg16_t U;
    struct _hw_hdmi_phy_scopecnt2_bitfields
    {
        unsigned short SCOPE_ONES_CNT2 : 16; //!< [15:0] Scope 1's Counter 2 This register carries the number of counted 1's on channel 2. If the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x26 register.
    } B;
} hw_hdmi_phy_scopecnt2_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNT2 register
 */
#define HW_HDMI_PHY_SCOPECNT2_ADDR      (REGS_HDMI_PHY_BASE + 0x22)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNT2           (*(volatile hw_hdmi_phy_scopecnt2_t *) HW_HDMI_PHY_SCOPECNT2_ADDR)
#define HW_HDMI_PHY_SCOPECNT2_RD()      (HW_HDMI_PHY_SCOPECNT2.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_SCOPECNT2 bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNT2, field SCOPE_ONES_CNT2[15:0] (RO)
 *
 * Scope 1's Counter 2 This register carries the number of counted 1's on channel 2. If the LFSR15
 * was used to generate the scope patterns, you must read the MSB bits under 0x26 register.
 */

#define BP_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2      (0)      //!< Bit position for HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2.
#define BM_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2      (0x0000ffff)  //!< Bit mask for HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2.

//! @brief Get value of HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2 from a register value.
#define BG_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2(r)   (((r) & BM_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2) >> BP_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCOPECNTCLK - Scope Counter on Clock Channel (RO)
 *
 * Reset value: 0x00000000
 *
 * Register name : SCOPECNTCK  Access type : Read-only  Address : 0x23  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_scopecntclk
{
    reg16_t U;
    struct _hw_hdmi_phy_scopecntclk_bitfields
    {
        unsigned short CK_SCOPE_ONES_CNT : 16; //!< [15:0] Clock Scope 1's Counter This register carries the number of counted 1's on the clock channel. If the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x26 register.
    } B;
} hw_hdmi_phy_scopecntclk_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNTCLK register
 */
#define HW_HDMI_PHY_SCOPECNTCLK_ADDR      (REGS_HDMI_PHY_BASE + 0x23)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNTCLK           (*(volatile hw_hdmi_phy_scopecntclk_t *) HW_HDMI_PHY_SCOPECNTCLK_ADDR)
#define HW_HDMI_PHY_SCOPECNTCLK_RD()      (HW_HDMI_PHY_SCOPECNTCLK.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_SCOPECNTCLK bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNTCLK, field CK_SCOPE_ONES_CNT[15:0] (RO)
 *
 * Clock Scope 1's Counter This register carries the number of counted 1's on the clock channel. If
 * the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x26
 * register.
 */

#define BP_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT      (0)      //!< Bit position for HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT.
#define BM_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT      (0x0000ffff)  //!< Bit mask for HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT.

//! @brief Get value of HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT from a register value.
#define BG_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT(r)   (((r) & BM_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT) >> BP_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCOPESAMPLE - Scope Sample Count MSB, Scope Sample Repetition (RW)
 *
 * Reset value: 0x000013c0
 *
 * Register name : SCOPESAMPLE  Access type : Read/write  Address : 0x24  Value at reset : 0x13c0
 */
typedef union _hw_hdmi_phy_scopesample
{
    reg16_t U;
    struct _hw_hdmi_phy_scopesample_bitfields
    {
        unsigned short SCOPE_SAMPLE_CNT : 6; //!< [5:0] Scope Sample Counter Indicates the number of samples that will be counted (should be multiple of the LFSR length). These samples are the MSB bits only.
        unsigned short SCOPE_SAMPLE_REP : 7; //!< [12:6] Scope Sample Repetition Number of repetitions made by the scope FSM. The total samples captured is scope_sample_rep x scope_sample_cnt.
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved
    } B;
} hw_hdmi_phy_scopesample_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPESAMPLE register
 */
#define HW_HDMI_PHY_SCOPESAMPLE_ADDR      (REGS_HDMI_PHY_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPESAMPLE           (*(volatile hw_hdmi_phy_scopesample_t *) HW_HDMI_PHY_SCOPESAMPLE_ADDR)
#define HW_HDMI_PHY_SCOPESAMPLE_RD()      (HW_HDMI_PHY_SCOPESAMPLE.U)
#define HW_HDMI_PHY_SCOPESAMPLE_WR(v)     (HW_HDMI_PHY_SCOPESAMPLE.U = (v))
#define HW_HDMI_PHY_SCOPESAMPLE_SET(v)    (HW_HDMI_PHY_SCOPESAMPLE_WR(HW_HDMI_PHY_SCOPESAMPLE_RD() |  (v)))
#define HW_HDMI_PHY_SCOPESAMPLE_CLR(v)    (HW_HDMI_PHY_SCOPESAMPLE_WR(HW_HDMI_PHY_SCOPESAMPLE_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPESAMPLE_TOG(v)    (HW_HDMI_PHY_SCOPESAMPLE_WR(HW_HDMI_PHY_SCOPESAMPLE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_SCOPESAMPLE bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPESAMPLE, field SCOPE_SAMPLE_CNT[5:0] (RO)
 *
 * Scope Sample Counter Indicates the number of samples that will be counted (should be multiple of
 * the LFSR length). These samples are the MSB bits only.
 */

#define BP_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT      (0)      //!< Bit position for HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT.
#define BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT      (0x0000003f)  //!< Bit mask for HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT.

//! @brief Get value of HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT from a register value.
#define BG_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT(r)   (((r) & BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT) >> BP_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT)

/* --- Register HW_HDMI_PHY_SCOPESAMPLE, field SCOPE_SAMPLE_REP[12:6] (RO)
 *
 * Scope Sample Repetition Number of repetitions made by the scope FSM. The total samples captured
 * is scope_sample_rep x scope_sample_cnt.
 */

#define BP_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP      (6)      //!< Bit position for HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP.
#define BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP      (0x00001fc0)  //!< Bit mask for HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP.

//! @brief Get value of HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP from a register value.
#define BG_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP(r)   (((r) & BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP) >> BP_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCOPECNTMSB01 - Scope Counter MSB Channel 0 and Channel 1 (RO)
 *
 * Reset value: 0x00000000
 *
 * Register name : SCOPECNTMSB01  Access type : Read-only  Address : 0x25  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_scopecntmsb01
{
    reg16_t U;
    struct _hw_hdmi_phy_scopecntmsb01_bitfields
    {
        unsigned short SCOPE_ONES_CNT0 : 8; //!< [7:0] Scope 1's Counter 0 This register carries the number of counted 1's on channel 0. These 1's are the MSB bits only.
        unsigned short SCOPE_ONES_CNT1 : 5; //!< [12:8] Scope 1's Counter 1 This register carries the number of counted 1's on channel 1. These 1's are the MSB bits only.
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved
    } B;
} hw_hdmi_phy_scopecntmsb01_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNTMSB01 register
 */
#define HW_HDMI_PHY_SCOPECNTMSB01_ADDR      (REGS_HDMI_PHY_BASE + 0x25)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNTMSB01           (*(volatile hw_hdmi_phy_scopecntmsb01_t *) HW_HDMI_PHY_SCOPECNTMSB01_ADDR)
#define HW_HDMI_PHY_SCOPECNTMSB01_RD()      (HW_HDMI_PHY_SCOPECNTMSB01.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_SCOPECNTMSB01 bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNTMSB01, field SCOPE_ONES_CNT0[7:0] (RO)
 *
 * Scope 1's Counter 0 This register carries the number of counted 1's on channel 0. These 1's are
 * the MSB bits only.
 */

#define BP_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0      (0)      //!< Bit position for HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0.
#define BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0      (0x000000ff)  //!< Bit mask for HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0.

//! @brief Get value of HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0 from a register value.
#define BG_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0(r)   (((r) & BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0) >> BP_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0)

/* --- Register HW_HDMI_PHY_SCOPECNTMSB01, field SCOPE_ONES_CNT1[12:8] (RO)
 *
 * Scope 1's Counter 1 This register carries the number of counted 1's on channel 1. These 1's are
 * the MSB bits only.
 */

#define BP_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1      (8)      //!< Bit position for HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1.
#define BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1      (0x00001f00)  //!< Bit mask for HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1.

//! @brief Get value of HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1 from a register value.
#define BG_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1(r)   (((r) & BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1) >> BP_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_SCOPECNTMSB2CK - Scope Counter MSB Channel 2 and Clock Channel (RO)
 *
 * Reset value: 0x00000000
 *
 * Register name : SCOPECNTMSB2CK  Access type : Read-only  Address : 0x26  Value at reset : 0x0000
 */
typedef union _hw_hdmi_phy_scopecntmsb2ck
{
    reg16_t U;
    struct _hw_hdmi_phy_scopecntmsb2ck_bitfields
    {
        unsigned short SCOPE_ONES_CNT2 : 6; //!< [5:0] Scope 1's Counter 2 This register carries the number of counted 1's on channel 2. These 1's are the MSB bits only.
        unsigned short CK_SCOPE_ONES_CNT : 7; //!< [12:6] Clock Scope 1's Counter This register carries the number of counted 1's on the clock channel. These 1's are the MSB bits only.
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved
    } B;
} hw_hdmi_phy_scopecntmsb2ck_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNTMSB2CK register
 */
#define HW_HDMI_PHY_SCOPECNTMSB2CK_ADDR      (REGS_HDMI_PHY_BASE + 0x26)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNTMSB2CK           (*(volatile hw_hdmi_phy_scopecntmsb2ck_t *) HW_HDMI_PHY_SCOPECNTMSB2CK_ADDR)
#define HW_HDMI_PHY_SCOPECNTMSB2CK_RD()      (HW_HDMI_PHY_SCOPECNTMSB2CK.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_SCOPECNTMSB2CK bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNTMSB2CK, field SCOPE_ONES_CNT2[5:0] (RO)
 *
 * Scope 1's Counter 2 This register carries the number of counted 1's on channel 2. These 1's are
 * the MSB bits only.
 */

#define BP_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2      (0)      //!< Bit position for HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2.
#define BM_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2      (0x0000003f)  //!< Bit mask for HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2.

//! @brief Get value of HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2 from a register value.
#define BG_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2(r)   (((r) & BM_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2) >> BP_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2)

/* --- Register HW_HDMI_PHY_SCOPECNTMSB2CK, field CK_SCOPE_ONES_CNT[12:6] (RO)
 *
 * Clock Scope 1's Counter This register carries the number of counted 1's on the clock channel.
 * These 1's are the MSB bits only.
 */

#define BP_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT      (6)      //!< Bit position for HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT.
#define BM_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT      (0x00001fc0)  //!< Bit mask for HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT.

//! @brief Get value of HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT from a register value.
#define BG_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT(r)   (((r) & BM_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT) >> BP_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT)


/*!
 * @brief All HDMI_PHY module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_hdmi_phy
{
    volatile hw_hdmi_phy_pwrctrl_t PWRCTRL; //!< Power Control
    volatile hw_hdmi_phy_serdivctrl_t SERDIVCTRL; //!< Serializer Divider Control
    volatile hw_hdmi_phy_serckctrl_t SERCKCTRL; //!< Serializer Clock Control
    volatile hw_hdmi_phy_serckkillctrl_t SERCKKILLCTRL; //!< Serializer Clock Kill Control
    volatile hw_hdmi_phy_txresctrl_t TXRESCTRL; //!< Transmitter and Resistance Calibration Control
    volatile hw_hdmi_phy_ckcalctrl_t CKCALCTRL; //!< Clock Calibration Control
    volatile hw_hdmi_phy_cpce_ctrl_t CPCE_CTRL; //!< Color Depth, Pixel Repetition, Clock Divider for PLL and MPLL, and Edge Rate Control
    volatile hw_hdmi_phy_txclkmeasctrl_t TXCLKMEASCTRL; //!< Tx and Clock Measure Control
    volatile hw_hdmi_phy_txmeasctrl_t TXMEASCTRL; //!< Tx Measure Control
    volatile hw_hdmi_phy_cksymtxctrl_t CKSYMTXCTRL; //!< Clock Symbol and Transmitter Control
    volatile hw_hdmi_phy_cmpseqctrl_t CMPSEQCTRL; //!< Comparator Sequence Control
    volatile hw_hdmi_phy_cmppwrctrl_t CMPPWRCTRL; //!< Comparator Power Control
    volatile hw_hdmi_phy_cmpmodectrl_t CMPMODECTRL; //!< Comparator Mode Control
    volatile hw_hdmi_phy_measctrl_t MEASCTRL; //!< Measure Control
    volatile hw_hdmi_phy_vlevctrl_t VLEVCTRL; //!< Voltage Level Control
    volatile hw_hdmi_phy_d2actrl_t D2ACTRL; //!< Digital-to-Analog Control
    volatile hw_hdmi_phy_currctrl_t CURRCTRL; //!< Current Control
    volatile hw_hdmi_phy_drvanactrl_t DRVANACTRL; //!< Drive Analog Control
    volatile hw_hdmi_phy_pllmeasctrl_t PLLMEASCTRL; //!< PLL Measure Control
    volatile hw_hdmi_phy_pllphbyctrl_t PLLPHBYCTRL; //!< PLL Phase and Bypass Control
    volatile hw_hdmi_phy_grp_ctrl_t GRP_CTRL; //!< Gear Shift, Reset Mode, and Power State Control
    volatile hw_hdmi_phy_gmpctrl_t GMPCTRL; //!< Gmp Control
    volatile hw_hdmi_phy_mpllmeasctrl_t MPLLMEASCTRL; //!< MPLL Measure Control
    volatile hw_hdmi_phy_msm_ctrl_t MSM_CTRL; //!< MPLL and PLL Phase, Scope Clock Select, and MUX Clock Control
    volatile hw_hdmi_phy_scrpb_status_t SCRPB_STATUS; //!< Scope, Comparator Result and Power Bad Status
    volatile hw_hdmi_phy_txterm_t TXTERM; //!< Transmission Termination
    volatile hw_hdmi_phy_ptrpt_enbl_t PTRPT_ENBL; //!< Power Sequence, TX Clock Alignment, Resistance Calibration, Pattern Generator Skip Bit, and TMDS Encoder Enable
    volatile hw_hdmi_phy_patterngen_t PATTERNGEN; //!< Pattern Generator Mode
    volatile hw_hdmi_phy_sdcap_mode_t SDCAP_MODE; //!< The Soft-Reset and DAC Enable, Clock Alignment and PG Mode
    volatile hw_hdmi_phy_scopemode_t SCOPEMODE; //!< Scope Mode register
    volatile hw_hdmi_phy_digtxmode_t DIGTXMODE; //!< Digital Transmission Mode
    volatile hw_hdmi_phy_str_status_t STR_STATUS; //!< Scope, Transmission Clock Alignment, and Resistance Calibration Set-on-Done Status
    volatile hw_hdmi_phy_scopecnt0_t SCOPECNT0; //!< Scope Counter on Channel 0
    volatile hw_hdmi_phy_scopecnt1_t SCOPECNT1; //!< Scope Counter on Channel 1
    volatile hw_hdmi_phy_scopecnt2_t SCOPECNT2; //!< Scope Counter on Channel 2
    volatile hw_hdmi_phy_scopecntclk_t SCOPECNTCLK; //!< Scope Counter on Clock Channel
    volatile hw_hdmi_phy_scopesample_t SCOPESAMPLE; //!< Scope Sample Count MSB, Scope Sample Repetition
    volatile hw_hdmi_phy_scopecntmsb01_t SCOPECNTMSB01; //!< Scope Counter MSB Channel 0 and Channel 1
    volatile hw_hdmi_phy_scopecntmsb2ck_t SCOPECNTMSB2CK; //!< Scope Counter MSB Channel 2 and Clock Channel
} hw_hdmi_phy_t;
#pragma pack()
#endif

//! @brief Macro to access all HDMI_PHY registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_HDMI_PHY(0)</code>.
#define HW_HDMI_PHY     (*(volatile hw_hdmi_phy_t *) REGS_HDMI_PHY_BASE)


#endif // _HDMI_PHY_H
