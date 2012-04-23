/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_USB_ANALOG_REGISTERS_H__
#define __HW_USB_ANALOG_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL USB_ANALOG registers defined in this header file.
 *
 * - HW_USB_ANALOG_USB1_VBUS_DETECT - USB VBUS Detect Register
 * - HW_USB_ANALOG_USB1_CHRG_DETECT - USB Charger Detect Register
 * - HW_USB_ANALOG_USB1_VBUS_DETECT_STAT - USB VBUS Detect Status Register
 * - HW_USB_ANALOG_USB1_CHRG_DETECT_STAT - USB Charger Detect Status Register
 * - HW_USB_ANALOG_USB1_LOOPBACK - USB Loopback Test Register
 * - HW_USB_ANALOG_USB1_MISC - USB Misc Register
 * - HW_USB_ANALOG_USB2_VBUS_DETECT - USB VBUS Detect Register
 * - HW_USB_ANALOG_USB2_CHRG_DETECT - USB Charger Detect Register
 * - HW_USB_ANALOG_USB2_VBUS_DETECT_STAT - USB VBUS Detect Status Register
 * - HW_USB_ANALOG_USB2_CHRG_DETECT_STAT - USB Charger Detect Status Register
 * - HW_USB_ANALOG_USB2_LOOPBACK - USB Loopback Test Register
 * - HW_USB_ANALOG_USB2_MISC - USB Misc Register
 * - HW_USB_ANALOG_DIGPROG - Chip Silicon Version
 *
 * - hw_usb_analog_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_USB_ANALOG_BASE
#define HW_USB_ANALOG_INSTANCE_COUNT (1) //!< Number of instances of the USB_ANALOG module.
#define REGS_USB_ANALOG_BASE (0x020c8000) //!< Base address for USB_ANALOG.
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
// HW_USB_ANALOG_USB1_VBUS_DETECT - USB VBUS Detect Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB1_VBUS_DETECT - USB VBUS Detect Register (RW)
 *
 * Reset value: 0x00100004
 *
 * This register defines controls for USB VBUS detect.
 */
typedef union _hw_usb_analog_usb1_vbus_detect
{
    reg32_t U;
    struct _hw_usb_analog_usb1_vbus_detect_bitfields
    {
        unsigned VBUSVALID_THRESH : 3; //!< [2:0] Set the threshold for the VBUSVALID comparator. This comparator is the most accurate method to determine the presence of 5v, and includes hystersis to minimize the need for software debounce of the detection. This comparator has ~50mV of hystersis to prevent chattering at the comparator trip point.
        unsigned VBUS_OVERRIDE_EN : 1; //!< [3] Enable the override the VBUSVALID, AVALID, BVALID and SESSEND signals from the USB OTG PHY with override register bit values.
        unsigned SESSEND_OVERRIDE : 1; //!< [4] Override value for the SESSEND hardware signal.
        unsigned BVALID_OVERRIDE : 1; //!< [5] Override value for the BVALID hardware signal.
        unsigned AVALID_OVERRIDE : 1; //!< [6] Override value for the aVALID hardware signal.
        unsigned VBUSVALID_OVERRIDE : 1; //!< [7] Override value for the VBUSVALID hardware signal.
        unsigned RESERVED0 : 10; //!< [17:8] Reserved.
        unsigned VBUSVALID_TO_B : 1; //!< [18] This bit muxes the Bvalid comparator to the VBUSVALID comparator and is used for test purposes only.
        unsigned RESERVED1 : 1; //!< [19] Reserved.
        unsigned VBUSVALID_PWRUP_CMPS : 1; //!< [20] Powers up comparators for vbus_valid detector.
        unsigned RESERVED2 : 5; //!< [25:21] Reserved.
        unsigned DISCHARGE_VBUS : 1; //!< [26] USB OTG discharge VBUS.
        unsigned CHARGE_VBUS : 1; //!< [27] USB OTG charge VBUS.
        unsigned RESERVED3 : 3; //!< [30:28] Reserved.
        unsigned EN_CHARGER_RESISTOR : 1; //!< [31] Enable 125k pullup on USB_DP and 375k on USB_DN to provide USB_CHARGER functionality for USB. This functionality is a new USB spec and should not be enabled unless recommended by Freescale.
    } B;
} hw_usb_analog_usb1_vbus_detect_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB1_VBUS_DETECT register
 */
#define HW_USB_ANALOG_USB1_VBUS_DETECT_ADDR      (REGS_USB_ANALOG_BASE + 0x1a0)
#define HW_USB_ANALOG_USB1_VBUS_DETECT_SET_ADDR  (HW_USB_ANALOG_USB1_VBUS_DETECT_ADDR + 0x4)
#define HW_USB_ANALOG_USB1_VBUS_DETECT_CLR_ADDR  (HW_USB_ANALOG_USB1_VBUS_DETECT_ADDR + 0x8)
#define HW_USB_ANALOG_USB1_VBUS_DETECT_TOG_ADDR  (HW_USB_ANALOG_USB1_VBUS_DETECT_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB1_VBUS_DETECT           (*(volatile hw_usb_analog_usb1_vbus_detect_t *) HW_USB_ANALOG_USB1_VBUS_DETECT_ADDR)
#define HW_USB_ANALOG_USB1_VBUS_DETECT_RD()      (HW_USB_ANALOG_USB1_VBUS_DETECT.U)
#define HW_USB_ANALOG_USB1_VBUS_DETECT_WR(v)     (HW_USB_ANALOG_USB1_VBUS_DETECT.U = (v))
#define HW_USB_ANALOG_USB1_VBUS_DETECT_SET(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_VBUS_DETECT_SET_ADDR) = (v))
#define HW_USB_ANALOG_USB1_VBUS_DETECT_CLR(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_VBUS_DETECT_CLR_ADDR) = (v))
#define HW_USB_ANALOG_USB1_VBUS_DETECT_TOG(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_VBUS_DETECT_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual USB_ANALOG_USB1_VBUS_DETECT bitfields
 */

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field VBUSVALID_THRESH[2:0] (RW)
 *
 * Set the threshold for the VBUSVALID comparator. This comparator is the most accurate method to
 * determine the presence of 5v, and includes hystersis to minimize the need for software debounce
 * of the detection. This comparator has ~50mV of hystersis to prevent chattering at the comparator
 * trip point.
 *
 * Values:
 * 4V0 = 000 - 4.0V
 * 4V1 = 001 - 4.1V
 * 4V2 = 010 - 4.2V
 * 4V3 = 011 - 4.3V
 * 4V4 = 100 - 4.4V (default)
 * 4V5 = 101 - 4.5V
 * 4V6 = 110 - 4.6V
 * 4V7 = 111 - 4.7V
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH      (0)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH      (0x00000007)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH) >> BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUSVALID_THRESH field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, VBUSVALID_THRESH, v)
#endif

#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH__4V0 (0x0) //!< 4.0V
#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH__4V1 (0x1) //!< 4.1V
#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH__4V2 (0x2) //!< 4.2V
#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH__4V3 (0x3) //!< 4.3V
#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH__4V4 (0x4) //!< 4.4V (default)
#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH__4V5 (0x5) //!< 4.5V
#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH__4V6 (0x6) //!< 4.6V
#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_THRESH__4V7 (0x7) //!< 4.7V

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field VBUS_OVERRIDE_EN[3] (RW)
 *
 * Enable the override the VBUSVALID, AVALID, BVALID and SESSEND signals from the USB OTG PHY with
 * override register bit values.
 *
 * Values:
 * HARDWARE = 0 - Use hardware generated values.
 * OVERRIDE = 1 - Use the software controlled values.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN      (3)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN      (0x00000008)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN) >> BP_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUS_OVERRIDE_EN field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, VBUS_OVERRIDE_EN, v)
#endif

#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN__HARDWARE (0x0) //!< Use hardware generated values.
#define BV_USB_ANALOG_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN__OVERRIDE (0x1) //!< Use the software controlled values.

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field SESSEND_OVERRIDE[4] (RW)
 *
 * Override value for the SESSEND hardware signal.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE      (4)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE      (0x00000010)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE) >> BP_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE) & BM_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SESSEND_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_SESSEND_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, SESSEND_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field BVALID_OVERRIDE[5] (RW)
 *
 * Override value for the BVALID hardware signal.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE      (5)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE      (0x00000020)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE) >> BP_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE) & BM_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BVALID_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_BVALID_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, BVALID_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field AVALID_OVERRIDE[6] (RW)
 *
 * Override value for the aVALID hardware signal.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE      (6)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE      (0x00000040)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE) >> BP_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE) & BM_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AVALID_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_AVALID_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, AVALID_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field VBUSVALID_OVERRIDE[7] (RW)
 *
 * Override value for the VBUSVALID hardware signal.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE      (7)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE      (0x00000080)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE) >> BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUSVALID_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, VBUSVALID_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field VBUSVALID_TO_B[18] (RW)
 *
 * This bit muxes the Bvalid comparator to the VBUSVALID comparator and is used for test purposes
 * only.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B      (18)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B      (0x00040000)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B) >> BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUSVALID_TO_B field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_TO_B(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, VBUSVALID_TO_B, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field VBUSVALID_PWRUP_CMPS[20] (RW)
 *
 * Powers up comparators for vbus_valid detector.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS      (20)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS      (0x00100000)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS) >> BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS) & BM_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUSVALID_PWRUP_CMPS field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_VBUSVALID_PWRUP_CMPS(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, VBUSVALID_PWRUP_CMPS, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field DISCHARGE_VBUS[26] (RW)
 *
 * USB OTG discharge VBUS.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS      (26)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS      (0x04000000)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS) >> BP_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS) & BM_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DISCHARGE_VBUS field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_DISCHARGE_VBUS(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, DISCHARGE_VBUS, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field CHARGE_VBUS[27] (RW)
 *
 * USB OTG charge VBUS.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS      (27)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS      (0x08000000)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS) >> BP_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS) & BM_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHARGE_VBUS field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_CHARGE_VBUS(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, CHARGE_VBUS, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT, field EN_CHARGER_RESISTOR[31] (RW)
 *
 * Enable 125k pullup on USB_DP and 375k on USB_DN to provide USB_CHARGER functionality for USB.
 * This functionality is a new USB spec and should not be enabled unless recommended by Freescale.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR      (31)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR      (0x80000000)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR) >> BP_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR)

//! @brief Format value for bitfield USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR.
#define BF_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR) & BM_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_CHARGER_RESISTOR field to a new value.
#define BW_USB_ANALOG_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR(v)   BF_CS1(USB_ANALOG_USB1_VBUS_DETECT, EN_CHARGER_RESISTOR, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB1_CHRG_DETECT - USB Charger Detect Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB1_CHRG_DETECT - USB Charger Detect Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register defines controls for USB charger detect.
 */
typedef union _hw_usb_analog_usb1_chrg_detect
{
    reg32_t U;
    struct _hw_usb_analog_usb1_chrg_detect_bitfields
    {
        unsigned FORCE_DETECT : 1; //!< [0] Set this bit to 1 to force the charger detector circuit to signal the presence of a charger.
        unsigned RESERVED0 : 17; //!< [17:1] Reserved.
        unsigned CHK_CONTACT : 1; //!< [18] 
        unsigned CHK_CHRG_B : 1; //!< [19] 
        unsigned EN_B : 1; //!< [20] Control the charger detector.
        unsigned RESERVED1 : 3; //!< [23:21] Reserved.
        unsigned RESERVED2 : 8; //!< [31:24] Reserved.
    } B;
} hw_usb_analog_usb1_chrg_detect_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB1_CHRG_DETECT register
 */
#define HW_USB_ANALOG_USB1_CHRG_DETECT_ADDR      (REGS_USB_ANALOG_BASE + 0x1b0)
#define HW_USB_ANALOG_USB1_CHRG_DETECT_SET_ADDR  (HW_USB_ANALOG_USB1_CHRG_DETECT_ADDR + 0x4)
#define HW_USB_ANALOG_USB1_CHRG_DETECT_CLR_ADDR  (HW_USB_ANALOG_USB1_CHRG_DETECT_ADDR + 0x8)
#define HW_USB_ANALOG_USB1_CHRG_DETECT_TOG_ADDR  (HW_USB_ANALOG_USB1_CHRG_DETECT_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB1_CHRG_DETECT           (*(volatile hw_usb_analog_usb1_chrg_detect_t *) HW_USB_ANALOG_USB1_CHRG_DETECT_ADDR)
#define HW_USB_ANALOG_USB1_CHRG_DETECT_RD()      (HW_USB_ANALOG_USB1_CHRG_DETECT.U)
#define HW_USB_ANALOG_USB1_CHRG_DETECT_WR(v)     (HW_USB_ANALOG_USB1_CHRG_DETECT.U = (v))
#define HW_USB_ANALOG_USB1_CHRG_DETECT_SET(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_CHRG_DETECT_SET_ADDR) = (v))
#define HW_USB_ANALOG_USB1_CHRG_DETECT_CLR(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_CHRG_DETECT_CLR_ADDR) = (v))
#define HW_USB_ANALOG_USB1_CHRG_DETECT_TOG(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_CHRG_DETECT_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual USB_ANALOG_USB1_CHRG_DETECT bitfields
 */

/* --- Register HW_USB_ANALOG_USB1_CHRG_DETECT, field FORCE_DETECT[0] (RW)
 *
 * Set this bit to 1 to force the charger detector circuit to signal the presence of a charger.
 */

#define BP_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT      (0)      //!< Bit position for USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT.
#define BM_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT      (0x00000001)  //!< Bit mask for USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT.

//! @brief Get value of USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT from a register value.
#define BG_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT) >> BP_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT)

//! @brief Format value for bitfield USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT.
#define BF_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT) & BM_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FORCE_DETECT field to a new value.
#define BW_USB_ANALOG_USB1_CHRG_DETECT_FORCE_DETECT(v)   BF_CS1(USB_ANALOG_USB1_CHRG_DETECT, FORCE_DETECT, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_CHRG_DETECT, field CHK_CONTACT[18] (RW)
 *

 *
 * Values:
 * NO_CHECK = 0 - Do not check the contact of USB plug.
 * CHECK = 1 - Check whether the USB plug has been in contact with each other
 */

#define BP_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT      (18)      //!< Bit position for USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT.
#define BM_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT      (0x00040000)  //!< Bit mask for USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT.

//! @brief Get value of USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT from a register value.
#define BG_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT) >> BP_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT)

//! @brief Format value for bitfield USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT.
#define BF_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT) & BM_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHK_CONTACT field to a new value.
#define BW_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT(v)   BF_CS1(USB_ANALOG_USB1_CHRG_DETECT, CHK_CONTACT, v)
#endif

#define BV_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT__NO_CHECK (0x0) //!< Do not check the contact of USB plug.
#define BV_USB_ANALOG_USB1_CHRG_DETECT_CHK_CONTACT__CHECK (0x1) //!< Check whether the USB plug has been in contact with each other

/* --- Register HW_USB_ANALOG_USB1_CHRG_DETECT, field CHK_CHRG_B[19] (RW)
 *

 *
 * Values:
 * CHECK = 0 - Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
 * NO_CHECK = 1 - Do not check whether a charger is connected to the USB port.
 */

#define BP_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B      (19)      //!< Bit position for USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B.
#define BM_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B      (0x00080000)  //!< Bit mask for USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B.

//! @brief Get value of USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B from a register value.
#define BG_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B) >> BP_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B)

//! @brief Format value for bitfield USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B.
#define BF_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B) & BM_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHK_CHRG_B field to a new value.
#define BW_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B(v)   BF_CS1(USB_ANALOG_USB1_CHRG_DETECT, CHK_CHRG_B, v)
#endif

#define BV_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B__CHECK (0x0) //!< Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
#define BV_USB_ANALOG_USB1_CHRG_DETECT_CHK_CHRG_B__NO_CHECK (0x1) //!< Do not check whether a charger is connected to the USB port.

/* --- Register HW_USB_ANALOG_USB1_CHRG_DETECT, field EN_B[20] (RW)
 *
 * Control the charger detector.
 *
 * Values:
 * ENABLE = 0 - Enable the charger detector.
 * DISABLE = 1 - Disable the charger detector.
 */

#define BP_USB_ANALOG_USB1_CHRG_DETECT_EN_B      (20)      //!< Bit position for USB_ANALOG_USB1_CHRG_DETECT_EN_B.
#define BM_USB_ANALOG_USB1_CHRG_DETECT_EN_B      (0x00100000)  //!< Bit mask for USB_ANALOG_USB1_CHRG_DETECT_EN_B.

//! @brief Get value of USB_ANALOG_USB1_CHRG_DETECT_EN_B from a register value.
#define BG_USB_ANALOG_USB1_CHRG_DETECT_EN_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_CHRG_DETECT_EN_B) >> BP_USB_ANALOG_USB1_CHRG_DETECT_EN_B)

//! @brief Format value for bitfield USB_ANALOG_USB1_CHRG_DETECT_EN_B.
#define BF_USB_ANALOG_USB1_CHRG_DETECT_EN_B(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_CHRG_DETECT_EN_B) & BM_USB_ANALOG_USB1_CHRG_DETECT_EN_B)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_B field to a new value.
#define BW_USB_ANALOG_USB1_CHRG_DETECT_EN_B(v)   BF_CS1(USB_ANALOG_USB1_CHRG_DETECT, EN_B, v)
#endif

#define BV_USB_ANALOG_USB1_CHRG_DETECT_EN_B__ENABLE (0x0) //!< Enable the charger detector.
#define BV_USB_ANALOG_USB1_CHRG_DETECT_EN_B__DISABLE (0x1) //!< Disable the charger detector.

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB1_VBUS_DETECT_STAT - USB VBUS Detect Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB1_VBUS_DETECT_STAT - USB VBUS Detect Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register defines fields for USB VBUS Detect status.
 */
typedef union _hw_usb_analog_usb1_vbus_detect_stat
{
    reg32_t U;
    struct _hw_usb_analog_usb1_vbus_detect_stat_bitfields
    {
        unsigned SESSEND : 1; //!< [0] Session End for USB OTG. This bit is a read only version of the state of the analog signal. It can not be overwritten by software like the SESSEND bit below. NOTE: This bit's default value depends on whether VDD5V is present, 0 if VDD5V is present, 1 if VDD5V is not present.
        unsigned BVALID : 1; //!< [1] Indicates VBus is valid for a B-peripheral. This bit is a read only version of the state of the analog signal. It can not be overritten by software.
        unsigned AVALID : 1; //!< [2] Indicates VBus is valid for a A-peripheral. This bit is a read only version of the state of the analog signal. It can not be overritten by software.
        unsigned VBUS_VALID : 1; //!< [3] VBus valid for USB OTG. This bit is a read only version of the state of the analog signal. It can not be overwritten by software.
        unsigned RESERVED0 : 28; //!< [31:4] Reserved.
    } B;
} hw_usb_analog_usb1_vbus_detect_stat_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB1_VBUS_DETECT_STAT register
 */
#define HW_USB_ANALOG_USB1_VBUS_DETECT_STAT_ADDR      (REGS_USB_ANALOG_BASE + 0x1c0)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB1_VBUS_DETECT_STAT           (*(volatile hw_usb_analog_usb1_vbus_detect_stat_t *) HW_USB_ANALOG_USB1_VBUS_DETECT_STAT_ADDR)
#define HW_USB_ANALOG_USB1_VBUS_DETECT_STAT_RD()      (HW_USB_ANALOG_USB1_VBUS_DETECT_STAT.U)
#endif

/*
 * constants & macros for individual USB_ANALOG_USB1_VBUS_DETECT_STAT bitfields
 */

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT_STAT, field SESSEND[0] (RO)
 *
 * Session End for USB OTG. This bit is a read only version of the state of the analog signal. It
 * can not be overwritten by software like the SESSEND bit below. NOTE: This bit's default value
 * depends on whether VDD5V is present, 0 if VDD5V is present, 1 if VDD5V is not present.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_STAT_SESSEND      (0)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_STAT_SESSEND.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_STAT_SESSEND      (0x00000001)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_STAT_SESSEND.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_STAT_SESSEND from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_STAT_SESSEND(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_STAT_SESSEND) >> BP_USB_ANALOG_USB1_VBUS_DETECT_STAT_SESSEND)

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT_STAT, field BVALID[1] (RO)
 *
 * Indicates VBus is valid for a B-peripheral. This bit is a read only version of the state of the
 * analog signal. It can not be overritten by software.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_STAT_BVALID      (1)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_STAT_BVALID.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_STAT_BVALID      (0x00000002)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_STAT_BVALID.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_STAT_BVALID from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_STAT_BVALID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_STAT_BVALID) >> BP_USB_ANALOG_USB1_VBUS_DETECT_STAT_BVALID)

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT_STAT, field AVALID[2] (RO)
 *
 * Indicates VBus is valid for a A-peripheral. This bit is a read only version of the state of the
 * analog signal. It can not be overritten by software.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_STAT_AVALID      (2)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_STAT_AVALID.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_STAT_AVALID      (0x00000004)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_STAT_AVALID.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_STAT_AVALID from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_STAT_AVALID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_STAT_AVALID) >> BP_USB_ANALOG_USB1_VBUS_DETECT_STAT_AVALID)

/* --- Register HW_USB_ANALOG_USB1_VBUS_DETECT_STAT, field VBUS_VALID[3] (RO)
 *
 * VBus valid for USB OTG. This bit is a read only version of the state of the analog signal. It can
 * not be overwritten by software.
 */

#define BP_USB_ANALOG_USB1_VBUS_DETECT_STAT_VBUS_VALID      (3)      //!< Bit position for USB_ANALOG_USB1_VBUS_DETECT_STAT_VBUS_VALID.
#define BM_USB_ANALOG_USB1_VBUS_DETECT_STAT_VBUS_VALID      (0x00000008)  //!< Bit mask for USB_ANALOG_USB1_VBUS_DETECT_STAT_VBUS_VALID.

//! @brief Get value of USB_ANALOG_USB1_VBUS_DETECT_STAT_VBUS_VALID from a register value.
#define BG_USB_ANALOG_USB1_VBUS_DETECT_STAT_VBUS_VALID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_VBUS_DETECT_STAT_VBUS_VALID) >> BP_USB_ANALOG_USB1_VBUS_DETECT_STAT_VBUS_VALID)

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB1_CHRG_DETECT_STAT - USB Charger Detect Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB1_CHRG_DETECT_STAT - USB Charger Detect Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register defines fields for USB charger detect status.
 */
typedef union _hw_usb_analog_usb1_chrg_detect_stat
{
    reg32_t U;
    struct _hw_usb_analog_usb1_chrg_detect_stat_bitfields
    {
        unsigned PLUG_CONTACT : 1; //!< [0] State of the USB plug contact detector.
        unsigned CHRG_DETECTED : 1; //!< [1] State of charger detection. This bit is a read only version of the state of the analog signal.
        unsigned DM_STATE : 1; //!< [2] DM line state output of the charger detector.
        unsigned DP_STATE : 1; //!< [3] DP line state output of the charger detector.
        unsigned RESERVED0 : 28; //!< [31:4] Reserved.
    } B;
} hw_usb_analog_usb1_chrg_detect_stat_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB1_CHRG_DETECT_STAT register
 */
#define HW_USB_ANALOG_USB1_CHRG_DETECT_STAT_ADDR      (REGS_USB_ANALOG_BASE + 0x1d0)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB1_CHRG_DETECT_STAT           (*(volatile hw_usb_analog_usb1_chrg_detect_stat_t *) HW_USB_ANALOG_USB1_CHRG_DETECT_STAT_ADDR)
#define HW_USB_ANALOG_USB1_CHRG_DETECT_STAT_RD()      (HW_USB_ANALOG_USB1_CHRG_DETECT_STAT.U)
#endif

/*
 * constants & macros for individual USB_ANALOG_USB1_CHRG_DETECT_STAT bitfields
 */

/* --- Register HW_USB_ANALOG_USB1_CHRG_DETECT_STAT, field PLUG_CONTACT[0] (RO)
 *
 * State of the USB plug contact detector.
 *
 * Values:
 * NO_CONTACT = 0 - The USB plug has not made contact.
 * GOOD_CONTACT = 1 - The USB plug has made good contact.
 */

#define BP_USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT      (0)      //!< Bit position for USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT.
#define BM_USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT      (0x00000001)  //!< Bit mask for USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT.

//! @brief Get value of USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT from a register value.
#define BG_USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT) >> BP_USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT)

#define BV_USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT__NO_CONTACT (0x0) //!< The USB plug has not made contact.
#define BV_USB_ANALOG_USB1_CHRG_DETECT_STAT_PLUG_CONTACT__GOOD_CONTACT (0x1) //!< The USB plug has made good contact.

/* --- Register HW_USB_ANALOG_USB1_CHRG_DETECT_STAT, field CHRG_DETECTED[1] (RO)
 *
 * State of charger detection. This bit is a read only version of the state of the analog signal.
 *
 * Values:
 * CHARGER_NOT_PRESENT = 0 - The USB port is not connected to a charger.
 * CHARGER_PRESENT = 1 - A charger (either a dedicated charger or a host charger) is connected to the USB port.
 */

#define BP_USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED      (1)      //!< Bit position for USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED.
#define BM_USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED      (0x00000002)  //!< Bit mask for USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED.

//! @brief Get value of USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED from a register value.
#define BG_USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED) >> BP_USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED)

#define BV_USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED__CHARGER_NOT_PRESENT (0x0) //!< The USB port is not connected to a charger.
#define BV_USB_ANALOG_USB1_CHRG_DETECT_STAT_CHRG_DETECTED__CHARGER_PRESENT (0x1) //!< A charger (either a dedicated charger or a host charger) is connected to the USB port.

/* --- Register HW_USB_ANALOG_USB1_CHRG_DETECT_STAT, field DM_STATE[2] (RO)
 *
 * DM line state output of the charger detector.
 */

#define BP_USB_ANALOG_USB1_CHRG_DETECT_STAT_DM_STATE      (2)      //!< Bit position for USB_ANALOG_USB1_CHRG_DETECT_STAT_DM_STATE.
#define BM_USB_ANALOG_USB1_CHRG_DETECT_STAT_DM_STATE      (0x00000004)  //!< Bit mask for USB_ANALOG_USB1_CHRG_DETECT_STAT_DM_STATE.

//! @brief Get value of USB_ANALOG_USB1_CHRG_DETECT_STAT_DM_STATE from a register value.
#define BG_USB_ANALOG_USB1_CHRG_DETECT_STAT_DM_STATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_CHRG_DETECT_STAT_DM_STATE) >> BP_USB_ANALOG_USB1_CHRG_DETECT_STAT_DM_STATE)

/* --- Register HW_USB_ANALOG_USB1_CHRG_DETECT_STAT, field DP_STATE[3] (RO)
 *
 * DP line state output of the charger detector.
 */

#define BP_USB_ANALOG_USB1_CHRG_DETECT_STAT_DP_STATE      (3)      //!< Bit position for USB_ANALOG_USB1_CHRG_DETECT_STAT_DP_STATE.
#define BM_USB_ANALOG_USB1_CHRG_DETECT_STAT_DP_STATE      (0x00000008)  //!< Bit mask for USB_ANALOG_USB1_CHRG_DETECT_STAT_DP_STATE.

//! @brief Get value of USB_ANALOG_USB1_CHRG_DETECT_STAT_DP_STATE from a register value.
#define BG_USB_ANALOG_USB1_CHRG_DETECT_STAT_DP_STATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_CHRG_DETECT_STAT_DP_STATE) >> BP_USB_ANALOG_USB1_CHRG_DETECT_STAT_DP_STATE)

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB1_LOOPBACK - USB Loopback Test Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB1_LOOPBACK - USB Loopback Test Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register defines controls for the USB1 loopback test function.
 */
typedef union _hw_usb_analog_usb1_loopback
{
    reg32_t U;
    struct _hw_usb_analog_usb1_loopback_bitfields
    {
        unsigned UTMI_TESTSTART : 1; //!< [0] This bit enables the USB1 loopback test.
        unsigned UTMI_DIG_TST0 : 1; //!< [1] Mode control for USB1.
        unsigned UTMI_DIG_TST1 : 1; //!< [2] Mode control for USB1.
        unsigned TSTI_TX_HS_MODE : 1; //!< [3] Select HS or FS mode for USB1.
        unsigned TSTI_TX_LS_MODE : 1; //!< [4] Set to 1 to choose LS for USB1, set to 0 to choose HS or FS mode which is defined by TSTI1_TX_HS. Defined by TSTI1_TX_HS.
        unsigned TSTI_TX_EN : 1; //!< [5] Enable TX for USB1.
        unsigned TSTI_TX_HIZ : 1; //!< [6] Sets TX Hi-Z for USB1.
        unsigned UTMO_DIG_TST0 : 1; //!< [7] This read-only bit is a status bit for USB1 LB = 1 is pass.
        unsigned UTMO_DIG_TST1 : 1; //!< [8] This read-only bit is a status bit for USB1 LB = 0 is pass.
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_usb_analog_usb1_loopback_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB1_LOOPBACK register
 */
#define HW_USB_ANALOG_USB1_LOOPBACK_ADDR      (REGS_USB_ANALOG_BASE + 0x1e0)
#define HW_USB_ANALOG_USB1_LOOPBACK_SET_ADDR  (HW_USB_ANALOG_USB1_LOOPBACK_ADDR + 0x4)
#define HW_USB_ANALOG_USB1_LOOPBACK_CLR_ADDR  (HW_USB_ANALOG_USB1_LOOPBACK_ADDR + 0x8)
#define HW_USB_ANALOG_USB1_LOOPBACK_TOG_ADDR  (HW_USB_ANALOG_USB1_LOOPBACK_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB1_LOOPBACK           (*(volatile hw_usb_analog_usb1_loopback_t *) HW_USB_ANALOG_USB1_LOOPBACK_ADDR)
#define HW_USB_ANALOG_USB1_LOOPBACK_RD()      (HW_USB_ANALOG_USB1_LOOPBACK.U)
#define HW_USB_ANALOG_USB1_LOOPBACK_WR(v)     (HW_USB_ANALOG_USB1_LOOPBACK.U = (v))
#define HW_USB_ANALOG_USB1_LOOPBACK_SET(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_LOOPBACK_SET_ADDR) = (v))
#define HW_USB_ANALOG_USB1_LOOPBACK_CLR(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_LOOPBACK_CLR_ADDR) = (v))
#define HW_USB_ANALOG_USB1_LOOPBACK_TOG(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_LOOPBACK_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual USB_ANALOG_USB1_LOOPBACK bitfields
 */

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field UTMI_TESTSTART[0] (RW)
 *
 * This bit enables the USB1 loopback test.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART      (0)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART.
#define BM_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART      (0x00000001)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART) >> BP_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART)

//! @brief Format value for bitfield USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART.
#define BF_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART) & BM_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_TESTSTART field to a new value.
#define BW_USB_ANALOG_USB1_LOOPBACK_UTMI_TESTSTART(v)   BF_CS1(USB_ANALOG_USB1_LOOPBACK, UTMI_TESTSTART, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field UTMI_DIG_TST0[1] (RW)
 *
 * Mode control for USB1.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0      (1)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0.
#define BM_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0      (0x00000002)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0 from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0) >> BP_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0)

//! @brief Format value for bitfield USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0.
#define BF_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0) & BM_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_DIG_TST0 field to a new value.
#define BW_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST0(v)   BF_CS1(USB_ANALOG_USB1_LOOPBACK, UTMI_DIG_TST0, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field UTMI_DIG_TST1[2] (RW)
 *
 * Mode control for USB1.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1      (2)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1.
#define BM_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1      (0x00000004)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1 from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1) >> BP_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1)

//! @brief Format value for bitfield USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1.
#define BF_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1) & BM_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_DIG_TST1 field to a new value.
#define BW_USB_ANALOG_USB1_LOOPBACK_UTMI_DIG_TST1(v)   BF_CS1(USB_ANALOG_USB1_LOOPBACK, UTMI_DIG_TST1, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field TSTI_TX_HS_MODE[3] (RW)
 *
 * Select HS or FS mode for USB1.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE      (3)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE.
#define BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE      (0x00000008)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE) >> BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE)

//! @brief Format value for bitfield USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE.
#define BF_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE) & BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSTI_TX_HS_MODE field to a new value.
#define BW_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HS_MODE(v)   BF_CS1(USB_ANALOG_USB1_LOOPBACK, TSTI_TX_HS_MODE, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field TSTI_TX_LS_MODE[4] (RW)
 *
 * Set to 1 to choose LS for USB1, set to 0 to choose HS or FS mode which is defined by TSTI1_TX_HS.
 * Defined by TSTI1_TX_HS.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE      (4)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE.
#define BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE      (0x00000010)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE) >> BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE)

//! @brief Format value for bitfield USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE.
#define BF_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE) & BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSTI_TX_LS_MODE field to a new value.
#define BW_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_LS_MODE(v)   BF_CS1(USB_ANALOG_USB1_LOOPBACK, TSTI_TX_LS_MODE, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field TSTI_TX_EN[5] (RW)
 *
 * Enable TX for USB1.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN      (5)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN.
#define BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN      (0x00000020)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN) >> BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN)

//! @brief Format value for bitfield USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN.
#define BF_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN) & BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSTI_TX_EN field to a new value.
#define BW_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_EN(v)   BF_CS1(USB_ANALOG_USB1_LOOPBACK, TSTI_TX_EN, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field TSTI_TX_HIZ[6] (RW)
 *
 * Sets TX Hi-Z for USB1.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ      (6)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ.
#define BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ      (0x00000040)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ) >> BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ)

//! @brief Format value for bitfield USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ.
#define BF_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ) & BM_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSTI_TX_HIZ field to a new value.
#define BW_USB_ANALOG_USB1_LOOPBACK_TSTI_TX_HIZ(v)   BF_CS1(USB_ANALOG_USB1_LOOPBACK, TSTI_TX_HIZ, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field UTMO_DIG_TST0[7] (RO)
 *
 * This read-only bit is a status bit for USB1 LB = 1 is pass.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST0      (7)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST0.
#define BM_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST0      (0x00000080)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST0.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST0 from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST0) >> BP_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST0)

/* --- Register HW_USB_ANALOG_USB1_LOOPBACK, field UTMO_DIG_TST1[8] (RO)
 *
 * This read-only bit is a status bit for USB1 LB = 0 is pass.
 */

#define BP_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST1      (8)      //!< Bit position for USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST1.
#define BM_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST1      (0x00000100)  //!< Bit mask for USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST1.

//! @brief Get value of USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST1 from a register value.
#define BG_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST1) >> BP_USB_ANALOG_USB1_LOOPBACK_UTMO_DIG_TST1)

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB1_MISC - USB Misc Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB1_MISC - USB Misc Register (RW)
 *
 * Reset value: 0x00000002
 *
 * This register defines controls for USB.
 */
typedef union _hw_usb_analog_usb1_misc
{
    reg32_t U;
    struct _hw_usb_analog_usb1_misc_bitfields
    {
        unsigned HS_USE_EXTERNAL_R : 1; //!< [0] Use external resistor to generate the current bias for the high speed transmitter. This bit should not be changed unless recommended by Freescale.
        unsigned EN_DEGLITCH : 1; //!< [1] Enable the deglitching circuit of the USB PLL output.
        unsigned RESERVED0 : 28; //!< [29:2] Reserved.
        unsigned EN_CLK_UTMI : 1; //!< [30] Enables the clk to the UTMI block.
        unsigned RESERVED1 : 1; //!< [31] Reserved.
    } B;
} hw_usb_analog_usb1_misc_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB1_MISC register
 */
#define HW_USB_ANALOG_USB1_MISC_ADDR      (REGS_USB_ANALOG_BASE + 0x1f0)
#define HW_USB_ANALOG_USB1_MISC_SET_ADDR  (HW_USB_ANALOG_USB1_MISC_ADDR + 0x4)
#define HW_USB_ANALOG_USB1_MISC_CLR_ADDR  (HW_USB_ANALOG_USB1_MISC_ADDR + 0x8)
#define HW_USB_ANALOG_USB1_MISC_TOG_ADDR  (HW_USB_ANALOG_USB1_MISC_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB1_MISC           (*(volatile hw_usb_analog_usb1_misc_t *) HW_USB_ANALOG_USB1_MISC_ADDR)
#define HW_USB_ANALOG_USB1_MISC_RD()      (HW_USB_ANALOG_USB1_MISC.U)
#define HW_USB_ANALOG_USB1_MISC_WR(v)     (HW_USB_ANALOG_USB1_MISC.U = (v))
#define HW_USB_ANALOG_USB1_MISC_SET(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_MISC_SET_ADDR) = (v))
#define HW_USB_ANALOG_USB1_MISC_CLR(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_MISC_CLR_ADDR) = (v))
#define HW_USB_ANALOG_USB1_MISC_TOG(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB1_MISC_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual USB_ANALOG_USB1_MISC bitfields
 */

/* --- Register HW_USB_ANALOG_USB1_MISC, field HS_USE_EXTERNAL_R[0] (RW)
 *
 * Use external resistor to generate the current bias for the high speed transmitter. This bit
 * should not be changed unless recommended by Freescale.
 */

#define BP_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R      (0)      //!< Bit position for USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R.
#define BM_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R      (0x00000001)  //!< Bit mask for USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R.

//! @brief Get value of USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R from a register value.
#define BG_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R) >> BP_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R)

//! @brief Format value for bitfield USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R.
#define BF_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R) & BM_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HS_USE_EXTERNAL_R field to a new value.
#define BW_USB_ANALOG_USB1_MISC_HS_USE_EXTERNAL_R(v)   BF_CS1(USB_ANALOG_USB1_MISC, HS_USE_EXTERNAL_R, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_MISC, field EN_DEGLITCH[1] (RW)
 *
 * Enable the deglitching circuit of the USB PLL output.
 */

#define BP_USB_ANALOG_USB1_MISC_EN_DEGLITCH      (1)      //!< Bit position for USB_ANALOG_USB1_MISC_EN_DEGLITCH.
#define BM_USB_ANALOG_USB1_MISC_EN_DEGLITCH      (0x00000002)  //!< Bit mask for USB_ANALOG_USB1_MISC_EN_DEGLITCH.

//! @brief Get value of USB_ANALOG_USB1_MISC_EN_DEGLITCH from a register value.
#define BG_USB_ANALOG_USB1_MISC_EN_DEGLITCH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_MISC_EN_DEGLITCH) >> BP_USB_ANALOG_USB1_MISC_EN_DEGLITCH)

//! @brief Format value for bitfield USB_ANALOG_USB1_MISC_EN_DEGLITCH.
#define BF_USB_ANALOG_USB1_MISC_EN_DEGLITCH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_MISC_EN_DEGLITCH) & BM_USB_ANALOG_USB1_MISC_EN_DEGLITCH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_DEGLITCH field to a new value.
#define BW_USB_ANALOG_USB1_MISC_EN_DEGLITCH(v)   BF_CS1(USB_ANALOG_USB1_MISC, EN_DEGLITCH, v)
#endif

/* --- Register HW_USB_ANALOG_USB1_MISC, field EN_CLK_UTMI[30] (RW)
 *
 * Enables the clk to the UTMI block.
 */

#define BP_USB_ANALOG_USB1_MISC_EN_CLK_UTMI      (30)      //!< Bit position for USB_ANALOG_USB1_MISC_EN_CLK_UTMI.
#define BM_USB_ANALOG_USB1_MISC_EN_CLK_UTMI      (0x40000000)  //!< Bit mask for USB_ANALOG_USB1_MISC_EN_CLK_UTMI.

//! @brief Get value of USB_ANALOG_USB1_MISC_EN_CLK_UTMI from a register value.
#define BG_USB_ANALOG_USB1_MISC_EN_CLK_UTMI(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB1_MISC_EN_CLK_UTMI) >> BP_USB_ANALOG_USB1_MISC_EN_CLK_UTMI)

//! @brief Format value for bitfield USB_ANALOG_USB1_MISC_EN_CLK_UTMI.
#define BF_USB_ANALOG_USB1_MISC_EN_CLK_UTMI(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB1_MISC_EN_CLK_UTMI) & BM_USB_ANALOG_USB1_MISC_EN_CLK_UTMI)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_CLK_UTMI field to a new value.
#define BW_USB_ANALOG_USB1_MISC_EN_CLK_UTMI(v)   BF_CS1(USB_ANALOG_USB1_MISC, EN_CLK_UTMI, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB2_VBUS_DETECT - USB VBUS Detect Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB2_VBUS_DETECT - USB VBUS Detect Register (RW)
 *
 * Reset value: 0x00100004
 *
 * This register defines controls for USB VBUS detect.
 */
typedef union _hw_usb_analog_usb2_vbus_detect
{
    reg32_t U;
    struct _hw_usb_analog_usb2_vbus_detect_bitfields
    {
        unsigned VBUSVALID_THRESH : 3; //!< [2:0] Set the threshold for the VBUSVALID comparator. This comparator is the most accurate method to determine the presence of 5v, and includes hystersis to minimize the need for software debounce of the detection. This comparator has ~50mV of hystersis to prevent chattering at the comparator trip point.
        unsigned VBUS_OVERRIDE_EN : 1; //!< [3] Enable the override the VBUSVALID, AVALID, BVALID and SESSEND signals from the USB OTG PHY with override register bit values.
        unsigned SESSEND_OVERRIDE : 1; //!< [4] Override value for the SESSEND hardware signal.
        unsigned BVALID_OVERRIDE : 1; //!< [5] Override value for the BVALID hardware signal.
        unsigned AVALID_OVERRIDE : 1; //!< [6] Override value for the aVALID hardware signal.
        unsigned VBUSVALID_OVERRIDE : 1; //!< [7] Override value for the VBUSVALID hardware signal.
        unsigned ID_OVERRIDE_EN : 1; //!< [8] Enable the override for the USB UH1 id with override register bit values.
        unsigned ID_OVERRIDE : 1; //!< [9] Override value for the USB UH1 id bit.
        unsigned RESERVED0 : 8; //!< [17:10] Reserved.
        unsigned VBUSVALID_TO_B : 1; //!< [18] This bit muxes the Bvalid comparator to the VBUSVALID comparator and is used for test purposes only.
        unsigned RESERVED1 : 1; //!< [19] Reserved.
        unsigned VBUSVALID_PWRUP_CMPS : 1; //!< [20] Powers up comparators for vbus_valid detector.
        unsigned RESERVED2 : 5; //!< [25:21] Reserved.
        unsigned DISCHARGE_VBUS : 1; //!< [26] USB OTG discharge VBUS.
        unsigned CHARGE_VBUS : 1; //!< [27] USB OTG charge VBUS.
        unsigned RESERVED3 : 3; //!< [30:28] Reserved.
        unsigned EN_CHARGER_RESISTOR : 1; //!< [31] Enable 125k pullup on USB_DP and 375k on USB_DN to provide USB_CHARGER functionality for USB. This functionality is a new USB spec and should not be enabled unless recommended by Freescale.
    } B;
} hw_usb_analog_usb2_vbus_detect_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB2_VBUS_DETECT register
 */
#define HW_USB_ANALOG_USB2_VBUS_DETECT_ADDR      (REGS_USB_ANALOG_BASE + 0x200)
#define HW_USB_ANALOG_USB2_VBUS_DETECT_SET_ADDR  (HW_USB_ANALOG_USB2_VBUS_DETECT_ADDR + 0x4)
#define HW_USB_ANALOG_USB2_VBUS_DETECT_CLR_ADDR  (HW_USB_ANALOG_USB2_VBUS_DETECT_ADDR + 0x8)
#define HW_USB_ANALOG_USB2_VBUS_DETECT_TOG_ADDR  (HW_USB_ANALOG_USB2_VBUS_DETECT_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB2_VBUS_DETECT           (*(volatile hw_usb_analog_usb2_vbus_detect_t *) HW_USB_ANALOG_USB2_VBUS_DETECT_ADDR)
#define HW_USB_ANALOG_USB2_VBUS_DETECT_RD()      (HW_USB_ANALOG_USB2_VBUS_DETECT.U)
#define HW_USB_ANALOG_USB2_VBUS_DETECT_WR(v)     (HW_USB_ANALOG_USB2_VBUS_DETECT.U = (v))
#define HW_USB_ANALOG_USB2_VBUS_DETECT_SET(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_VBUS_DETECT_SET_ADDR) = (v))
#define HW_USB_ANALOG_USB2_VBUS_DETECT_CLR(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_VBUS_DETECT_CLR_ADDR) = (v))
#define HW_USB_ANALOG_USB2_VBUS_DETECT_TOG(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_VBUS_DETECT_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual USB_ANALOG_USB2_VBUS_DETECT bitfields
 */

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field VBUSVALID_THRESH[2:0] (RW)
 *
 * Set the threshold for the VBUSVALID comparator. This comparator is the most accurate method to
 * determine the presence of 5v, and includes hystersis to minimize the need for software debounce
 * of the detection. This comparator has ~50mV of hystersis to prevent chattering at the comparator
 * trip point.
 *
 * Values:
 * 4V0 = 000 - 4.0V
 * 4V1 = 001 - 4.1V
 * 4V2 = 010 - 4.2V
 * 4V3 = 011 - 4.3V
 * 4V4 = 100 - 4.4V (default)
 * 4V5 = 101 - 4.5V
 * 4V6 = 110 - 4.6V
 * 4V7 = 111 - 4.7V
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH      (0)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH      (0x00000007)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH) >> BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUSVALID_THRESH field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, VBUSVALID_THRESH, v)
#endif

#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH__4V0 (0x0) //!< 4.0V
#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH__4V1 (0x1) //!< 4.1V
#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH__4V2 (0x2) //!< 4.2V
#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH__4V3 (0x3) //!< 4.3V
#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH__4V4 (0x4) //!< 4.4V (default)
#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH__4V5 (0x5) //!< 4.5V
#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH__4V6 (0x6) //!< 4.6V
#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_THRESH__4V7 (0x7) //!< 4.7V

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field VBUS_OVERRIDE_EN[3] (RW)
 *
 * Enable the override the VBUSVALID, AVALID, BVALID and SESSEND signals from the USB OTG PHY with
 * override register bit values.
 *
 * Values:
 * HARDWARE = 0 - Use hardware generated values.
 * OVERRIDE = 1 - Use the software controlled values.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN      (3)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN      (0x00000008)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN) >> BP_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUS_OVERRIDE_EN field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, VBUS_OVERRIDE_EN, v)
#endif

#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN__HARDWARE (0x0) //!< Use hardware generated values.
#define BV_USB_ANALOG_USB2_VBUS_DETECT_VBUS_OVERRIDE_EN__OVERRIDE (0x1) //!< Use the software controlled values.

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field SESSEND_OVERRIDE[4] (RW)
 *
 * Override value for the SESSEND hardware signal.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE      (4)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE      (0x00000010)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE) >> BP_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE) & BM_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SESSEND_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_SESSEND_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, SESSEND_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field BVALID_OVERRIDE[5] (RW)
 *
 * Override value for the BVALID hardware signal.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE      (5)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE      (0x00000020)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE) >> BP_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE) & BM_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BVALID_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_BVALID_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, BVALID_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field AVALID_OVERRIDE[6] (RW)
 *
 * Override value for the aVALID hardware signal.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE      (6)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE      (0x00000040)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE) >> BP_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE) & BM_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AVALID_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_AVALID_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, AVALID_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field VBUSVALID_OVERRIDE[7] (RW)
 *
 * Override value for the VBUSVALID hardware signal.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE      (7)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE      (0x00000080)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE) >> BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUSVALID_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, VBUSVALID_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field ID_OVERRIDE_EN[8] (RW)
 *
 * Enable the override for the USB UH1 id with override register bit values.
 *
 * Values:
 * HARDWARE = 0 - Use hardware generated values.
 * OVERRIDE = 1 - Use the software controlled values.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN      (8)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN      (0x00000100)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN) >> BP_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN) & BM_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ID_OVERRIDE_EN field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, ID_OVERRIDE_EN, v)
#endif

#define BV_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN__HARDWARE (0x0) //!< Use hardware generated values.
#define BV_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE_EN__OVERRIDE (0x1) //!< Use the software controlled values.

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field ID_OVERRIDE[9] (RW)
 *
 * Override value for the USB UH1 id bit.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE      (9)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE      (0x00000200)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE) >> BP_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE) & BM_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ID_OVERRIDE field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_ID_OVERRIDE(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, ID_OVERRIDE, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field VBUSVALID_TO_B[18] (RW)
 *
 * This bit muxes the Bvalid comparator to the VBUSVALID comparator and is used for test purposes
 * only.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B      (18)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B      (0x00040000)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B) >> BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUSVALID_TO_B field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_TO_B(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, VBUSVALID_TO_B, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field VBUSVALID_PWRUP_CMPS[20] (RW)
 *
 * Powers up comparators for vbus_valid detector.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS      (20)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS      (0x00100000)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS) >> BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS) & BM_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VBUSVALID_PWRUP_CMPS field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_VBUSVALID_PWRUP_CMPS(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, VBUSVALID_PWRUP_CMPS, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field DISCHARGE_VBUS[26] (RW)
 *
 * USB OTG discharge VBUS.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS      (26)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS      (0x04000000)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS) >> BP_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS) & BM_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DISCHARGE_VBUS field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_DISCHARGE_VBUS(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, DISCHARGE_VBUS, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field CHARGE_VBUS[27] (RW)
 *
 * USB OTG charge VBUS.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS      (27)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS      (0x08000000)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS) >> BP_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS) & BM_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHARGE_VBUS field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_CHARGE_VBUS(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, CHARGE_VBUS, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT, field EN_CHARGER_RESISTOR[31] (RW)
 *
 * Enable 125k pullup on USB_DP and 375k on USB_DN to provide USB_CHARGER functionality for USB.
 * This functionality is a new USB spec and should not be enabled unless recommended by Freescale.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR      (31)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR      (0x80000000)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR) >> BP_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR)

//! @brief Format value for bitfield USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR.
#define BF_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR) & BM_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_CHARGER_RESISTOR field to a new value.
#define BW_USB_ANALOG_USB2_VBUS_DETECT_EN_CHARGER_RESISTOR(v)   BF_CS1(USB_ANALOG_USB2_VBUS_DETECT, EN_CHARGER_RESISTOR, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB2_CHRG_DETECT - USB Charger Detect Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB2_CHRG_DETECT - USB Charger Detect Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register defines controls for USB charger detect.
 */
typedef union _hw_usb_analog_usb2_chrg_detect
{
    reg32_t U;
    struct _hw_usb_analog_usb2_chrg_detect_bitfields
    {
        unsigned FORCE_DETECT : 1; //!< [0] Set this bit to 1 to force the charger detector circuit to signal the presence of a charger.
        unsigned RESERVED0 : 17; //!< [17:1] Reserved.
        unsigned CHK_CONTACT : 1; //!< [18] 
        unsigned CHK_CHRG_B : 1; //!< [19] 
        unsigned EN_B : 1; //!< [20] Control the charger detector.
        unsigned RESERVED1 : 3; //!< [23:21] Reserved.
        unsigned RESERVED2 : 8; //!< [31:24] Reserved.
    } B;
} hw_usb_analog_usb2_chrg_detect_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB2_CHRG_DETECT register
 */
#define HW_USB_ANALOG_USB2_CHRG_DETECT_ADDR      (REGS_USB_ANALOG_BASE + 0x210)
#define HW_USB_ANALOG_USB2_CHRG_DETECT_SET_ADDR  (HW_USB_ANALOG_USB2_CHRG_DETECT_ADDR + 0x4)
#define HW_USB_ANALOG_USB2_CHRG_DETECT_CLR_ADDR  (HW_USB_ANALOG_USB2_CHRG_DETECT_ADDR + 0x8)
#define HW_USB_ANALOG_USB2_CHRG_DETECT_TOG_ADDR  (HW_USB_ANALOG_USB2_CHRG_DETECT_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB2_CHRG_DETECT           (*(volatile hw_usb_analog_usb2_chrg_detect_t *) HW_USB_ANALOG_USB2_CHRG_DETECT_ADDR)
#define HW_USB_ANALOG_USB2_CHRG_DETECT_RD()      (HW_USB_ANALOG_USB2_CHRG_DETECT.U)
#define HW_USB_ANALOG_USB2_CHRG_DETECT_WR(v)     (HW_USB_ANALOG_USB2_CHRG_DETECT.U = (v))
#define HW_USB_ANALOG_USB2_CHRG_DETECT_SET(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_CHRG_DETECT_SET_ADDR) = (v))
#define HW_USB_ANALOG_USB2_CHRG_DETECT_CLR(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_CHRG_DETECT_CLR_ADDR) = (v))
#define HW_USB_ANALOG_USB2_CHRG_DETECT_TOG(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_CHRG_DETECT_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual USB_ANALOG_USB2_CHRG_DETECT bitfields
 */

/* --- Register HW_USB_ANALOG_USB2_CHRG_DETECT, field FORCE_DETECT[0] (RW)
 *
 * Set this bit to 1 to force the charger detector circuit to signal the presence of a charger.
 */

#define BP_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT      (0)      //!< Bit position for USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT.
#define BM_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT      (0x00000001)  //!< Bit mask for USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT.

//! @brief Get value of USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT from a register value.
#define BG_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT) >> BP_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT)

//! @brief Format value for bitfield USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT.
#define BF_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT) & BM_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FORCE_DETECT field to a new value.
#define BW_USB_ANALOG_USB2_CHRG_DETECT_FORCE_DETECT(v)   BF_CS1(USB_ANALOG_USB2_CHRG_DETECT, FORCE_DETECT, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_CHRG_DETECT, field CHK_CONTACT[18] (RW)
 *

 *
 * Values:
 * NO_CHECK = 0 - Do not check the contact of USB plug.
 * CHECK = 1 - Check whether the USB plug has been in contact with each other
 */

#define BP_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT      (18)      //!< Bit position for USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT.
#define BM_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT      (0x00040000)  //!< Bit mask for USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT.

//! @brief Get value of USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT from a register value.
#define BG_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT) >> BP_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT)

//! @brief Format value for bitfield USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT.
#define BF_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT) & BM_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHK_CONTACT field to a new value.
#define BW_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT(v)   BF_CS1(USB_ANALOG_USB2_CHRG_DETECT, CHK_CONTACT, v)
#endif

#define BV_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT__NO_CHECK (0x0) //!< Do not check the contact of USB plug.
#define BV_USB_ANALOG_USB2_CHRG_DETECT_CHK_CONTACT__CHECK (0x1) //!< Check whether the USB plug has been in contact with each other

/* --- Register HW_USB_ANALOG_USB2_CHRG_DETECT, field CHK_CHRG_B[19] (RW)
 *

 *
 * Values:
 * CHECK = 0 - Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
 * NO_CHECK = 1 - Do not check whether a charger is connected to the USB port.
 */

#define BP_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B      (19)      //!< Bit position for USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B.
#define BM_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B      (0x00080000)  //!< Bit mask for USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B.

//! @brief Get value of USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B from a register value.
#define BG_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B) >> BP_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B)

//! @brief Format value for bitfield USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B.
#define BF_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B) & BM_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHK_CHRG_B field to a new value.
#define BW_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B(v)   BF_CS1(USB_ANALOG_USB2_CHRG_DETECT, CHK_CHRG_B, v)
#endif

#define BV_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B__CHECK (0x0) //!< Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
#define BV_USB_ANALOG_USB2_CHRG_DETECT_CHK_CHRG_B__NO_CHECK (0x1) //!< Do not check whether a charger is connected to the USB port.

/* --- Register HW_USB_ANALOG_USB2_CHRG_DETECT, field EN_B[20] (RW)
 *
 * Control the charger detector.
 *
 * Values:
 * ENABLE = 0 - Enable the charger detector.
 * DISABLE = 1 - Disable the charger detector.
 */

#define BP_USB_ANALOG_USB2_CHRG_DETECT_EN_B      (20)      //!< Bit position for USB_ANALOG_USB2_CHRG_DETECT_EN_B.
#define BM_USB_ANALOG_USB2_CHRG_DETECT_EN_B      (0x00100000)  //!< Bit mask for USB_ANALOG_USB2_CHRG_DETECT_EN_B.

//! @brief Get value of USB_ANALOG_USB2_CHRG_DETECT_EN_B from a register value.
#define BG_USB_ANALOG_USB2_CHRG_DETECT_EN_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_CHRG_DETECT_EN_B) >> BP_USB_ANALOG_USB2_CHRG_DETECT_EN_B)

//! @brief Format value for bitfield USB_ANALOG_USB2_CHRG_DETECT_EN_B.
#define BF_USB_ANALOG_USB2_CHRG_DETECT_EN_B(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_CHRG_DETECT_EN_B) & BM_USB_ANALOG_USB2_CHRG_DETECT_EN_B)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_B field to a new value.
#define BW_USB_ANALOG_USB2_CHRG_DETECT_EN_B(v)   BF_CS1(USB_ANALOG_USB2_CHRG_DETECT, EN_B, v)
#endif

#define BV_USB_ANALOG_USB2_CHRG_DETECT_EN_B__ENABLE (0x0) //!< Enable the charger detector.
#define BV_USB_ANALOG_USB2_CHRG_DETECT_EN_B__DISABLE (0x1) //!< Disable the charger detector.

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB2_VBUS_DETECT_STAT - USB VBUS Detect Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB2_VBUS_DETECT_STAT - USB VBUS Detect Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register defines fields for USB VBUS Detect status.
 */
typedef union _hw_usb_analog_usb2_vbus_detect_stat
{
    reg32_t U;
    struct _hw_usb_analog_usb2_vbus_detect_stat_bitfields
    {
        unsigned SESSEND : 1; //!< [0] Session End for USB OTG. This bit is a read only version of the state of the analog signal. It can not be overwritten by software like the SESSEND bit below. NOTE: This bit's default value depends on whether VDD5V is present, 0 if VDD5V is present, 1 if VDD5V is not present.
        unsigned BVALID : 1; //!< [1] Indicates VBus is valid for a B-peripheral. This bit is a read only version of the state of the analog signal. It can not be overritten by software.
        unsigned AVALID : 1; //!< [2] Indicates VBus is valid for a A-peripheral. This bit is a read only version of the state of the analog signal. It can not be overritten by software.
        unsigned VBUS_VALID : 1; //!< [3] VBus valid for USB OTG. This bit is a read only version of the state of the analog signal. It can not be overwritten by software.
        unsigned RESERVED0 : 28; //!< [31:4] Reserved.
    } B;
} hw_usb_analog_usb2_vbus_detect_stat_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB2_VBUS_DETECT_STAT register
 */
#define HW_USB_ANALOG_USB2_VBUS_DETECT_STAT_ADDR      (REGS_USB_ANALOG_BASE + 0x220)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB2_VBUS_DETECT_STAT           (*(volatile hw_usb_analog_usb2_vbus_detect_stat_t *) HW_USB_ANALOG_USB2_VBUS_DETECT_STAT_ADDR)
#define HW_USB_ANALOG_USB2_VBUS_DETECT_STAT_RD()      (HW_USB_ANALOG_USB2_VBUS_DETECT_STAT.U)
#endif

/*
 * constants & macros for individual USB_ANALOG_USB2_VBUS_DETECT_STAT bitfields
 */

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT_STAT, field SESSEND[0] (RO)
 *
 * Session End for USB OTG. This bit is a read only version of the state of the analog signal. It
 * can not be overwritten by software like the SESSEND bit below. NOTE: This bit's default value
 * depends on whether VDD5V is present, 0 if VDD5V is present, 1 if VDD5V is not present.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_STAT_SESSEND      (0)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_STAT_SESSEND.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_STAT_SESSEND      (0x00000001)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_STAT_SESSEND.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_STAT_SESSEND from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_STAT_SESSEND(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_STAT_SESSEND) >> BP_USB_ANALOG_USB2_VBUS_DETECT_STAT_SESSEND)

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT_STAT, field BVALID[1] (RO)
 *
 * Indicates VBus is valid for a B-peripheral. This bit is a read only version of the state of the
 * analog signal. It can not be overritten by software.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_STAT_BVALID      (1)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_STAT_BVALID.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_STAT_BVALID      (0x00000002)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_STAT_BVALID.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_STAT_BVALID from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_STAT_BVALID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_STAT_BVALID) >> BP_USB_ANALOG_USB2_VBUS_DETECT_STAT_BVALID)

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT_STAT, field AVALID[2] (RO)
 *
 * Indicates VBus is valid for a A-peripheral. This bit is a read only version of the state of the
 * analog signal. It can not be overritten by software.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_STAT_AVALID      (2)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_STAT_AVALID.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_STAT_AVALID      (0x00000004)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_STAT_AVALID.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_STAT_AVALID from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_STAT_AVALID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_STAT_AVALID) >> BP_USB_ANALOG_USB2_VBUS_DETECT_STAT_AVALID)

/* --- Register HW_USB_ANALOG_USB2_VBUS_DETECT_STAT, field VBUS_VALID[3] (RO)
 *
 * VBus valid for USB OTG. This bit is a read only version of the state of the analog signal. It can
 * not be overwritten by software.
 */

#define BP_USB_ANALOG_USB2_VBUS_DETECT_STAT_VBUS_VALID      (3)      //!< Bit position for USB_ANALOG_USB2_VBUS_DETECT_STAT_VBUS_VALID.
#define BM_USB_ANALOG_USB2_VBUS_DETECT_STAT_VBUS_VALID      (0x00000008)  //!< Bit mask for USB_ANALOG_USB2_VBUS_DETECT_STAT_VBUS_VALID.

//! @brief Get value of USB_ANALOG_USB2_VBUS_DETECT_STAT_VBUS_VALID from a register value.
#define BG_USB_ANALOG_USB2_VBUS_DETECT_STAT_VBUS_VALID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_VBUS_DETECT_STAT_VBUS_VALID) >> BP_USB_ANALOG_USB2_VBUS_DETECT_STAT_VBUS_VALID)

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB2_CHRG_DETECT_STAT - USB Charger Detect Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB2_CHRG_DETECT_STAT - USB Charger Detect Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register defines fields for USB charger detect status.
 */
typedef union _hw_usb_analog_usb2_chrg_detect_stat
{
    reg32_t U;
    struct _hw_usb_analog_usb2_chrg_detect_stat_bitfields
    {
        unsigned PLUG_CONTACT : 1; //!< [0] State of the USB plug contact detector.
        unsigned CHRG_DETECTED : 1; //!< [1] State of charger detection. This bit is a read only version of the state of the analog signal.
        unsigned DM_STATE : 1; //!< [2] DM line state output of the charger detector.
        unsigned DP_STATE : 1; //!< [3] DP line state output of the charger detector.
        unsigned RESERVED0 : 28; //!< [31:4] Reserved.
    } B;
} hw_usb_analog_usb2_chrg_detect_stat_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB2_CHRG_DETECT_STAT register
 */
#define HW_USB_ANALOG_USB2_CHRG_DETECT_STAT_ADDR      (REGS_USB_ANALOG_BASE + 0x230)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB2_CHRG_DETECT_STAT           (*(volatile hw_usb_analog_usb2_chrg_detect_stat_t *) HW_USB_ANALOG_USB2_CHRG_DETECT_STAT_ADDR)
#define HW_USB_ANALOG_USB2_CHRG_DETECT_STAT_RD()      (HW_USB_ANALOG_USB2_CHRG_DETECT_STAT.U)
#endif

/*
 * constants & macros for individual USB_ANALOG_USB2_CHRG_DETECT_STAT bitfields
 */

/* --- Register HW_USB_ANALOG_USB2_CHRG_DETECT_STAT, field PLUG_CONTACT[0] (RO)
 *
 * State of the USB plug contact detector.
 *
 * Values:
 * NO_CONTACT = 0 - The USB plug has not made contact.
 * GOOD_CONTACT = 1 - The USB plug has made good contact.
 */

#define BP_USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT      (0)      //!< Bit position for USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT.
#define BM_USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT      (0x00000001)  //!< Bit mask for USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT.

//! @brief Get value of USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT from a register value.
#define BG_USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT) >> BP_USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT)

#define BV_USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT__NO_CONTACT (0x0) //!< The USB plug has not made contact.
#define BV_USB_ANALOG_USB2_CHRG_DETECT_STAT_PLUG_CONTACT__GOOD_CONTACT (0x1) //!< The USB plug has made good contact.

/* --- Register HW_USB_ANALOG_USB2_CHRG_DETECT_STAT, field CHRG_DETECTED[1] (RO)
 *
 * State of charger detection. This bit is a read only version of the state of the analog signal.
 *
 * Values:
 * CHARGER_NOT_PRESENT = 0 - The USB port is not connected to a charger.
 * CHARGER_PRESENT = 1 - A charger (either a dedicated charger or a host charger) is connected to the USB port.
 */

#define BP_USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED      (1)      //!< Bit position for USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED.
#define BM_USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED      (0x00000002)  //!< Bit mask for USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED.

//! @brief Get value of USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED from a register value.
#define BG_USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED) >> BP_USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED)

#define BV_USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED__CHARGER_NOT_PRESENT (0x0) //!< The USB port is not connected to a charger.
#define BV_USB_ANALOG_USB2_CHRG_DETECT_STAT_CHRG_DETECTED__CHARGER_PRESENT (0x1) //!< A charger (either a dedicated charger or a host charger) is connected to the USB port.

/* --- Register HW_USB_ANALOG_USB2_CHRG_DETECT_STAT, field DM_STATE[2] (RO)
 *
 * DM line state output of the charger detector.
 */

#define BP_USB_ANALOG_USB2_CHRG_DETECT_STAT_DM_STATE      (2)      //!< Bit position for USB_ANALOG_USB2_CHRG_DETECT_STAT_DM_STATE.
#define BM_USB_ANALOG_USB2_CHRG_DETECT_STAT_DM_STATE      (0x00000004)  //!< Bit mask for USB_ANALOG_USB2_CHRG_DETECT_STAT_DM_STATE.

//! @brief Get value of USB_ANALOG_USB2_CHRG_DETECT_STAT_DM_STATE from a register value.
#define BG_USB_ANALOG_USB2_CHRG_DETECT_STAT_DM_STATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_CHRG_DETECT_STAT_DM_STATE) >> BP_USB_ANALOG_USB2_CHRG_DETECT_STAT_DM_STATE)

/* --- Register HW_USB_ANALOG_USB2_CHRG_DETECT_STAT, field DP_STATE[3] (RO)
 *
 * DP line state output of the charger detector.
 */

#define BP_USB_ANALOG_USB2_CHRG_DETECT_STAT_DP_STATE      (3)      //!< Bit position for USB_ANALOG_USB2_CHRG_DETECT_STAT_DP_STATE.
#define BM_USB_ANALOG_USB2_CHRG_DETECT_STAT_DP_STATE      (0x00000008)  //!< Bit mask for USB_ANALOG_USB2_CHRG_DETECT_STAT_DP_STATE.

//! @brief Get value of USB_ANALOG_USB2_CHRG_DETECT_STAT_DP_STATE from a register value.
#define BG_USB_ANALOG_USB2_CHRG_DETECT_STAT_DP_STATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_CHRG_DETECT_STAT_DP_STATE) >> BP_USB_ANALOG_USB2_CHRG_DETECT_STAT_DP_STATE)

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB2_LOOPBACK - USB Loopback Test Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB2_LOOPBACK - USB Loopback Test Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register defines controls for the USB2 loopback test function.
 */
typedef union _hw_usb_analog_usb2_loopback
{
    reg32_t U;
    struct _hw_usb_analog_usb2_loopback_bitfields
    {
        unsigned UTMI_TESTSTART : 1; //!< [0] This bit enables the USB2 loopback test.
        unsigned UTMI_DIG_TST0 : 1; //!< [1] Mode control for USB2.
        unsigned UTMI_DIG_TST1 : 1; //!< [2] Mode control for USB2.
        unsigned TSTI_TX_HS_MODE : 1; //!< [3] Select HS or FS mode for USB2.
        unsigned TSTI_TX_LS_MODE : 1; //!< [4] Set to 1 to choose LS for USB2, set to 0 to choose HS or FS mode which is defined by TSTI1_TX_HS. Defined by TSTI1_TX_HS.
        unsigned TSTI_TX_EN : 1; //!< [5] Enable TX for USB2.
        unsigned TSTI_TX_HIZ : 1; //!< [6] Sets TX Hi-Z for USB2.
        unsigned UTMO_DIG_TST0 : 1; //!< [7] This read-only bit is a status bit for USB2 LB = 1 is pass.
        unsigned UTMO_DIG_TST1 : 1; //!< [8] This read-only bit is a status bit for USB2 LB = 0 is pass.
        unsigned RESERVED0 : 23; //!< [31:9] Reserved.
    } B;
} hw_usb_analog_usb2_loopback_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB2_LOOPBACK register
 */
#define HW_USB_ANALOG_USB2_LOOPBACK_ADDR      (REGS_USB_ANALOG_BASE + 0x240)
#define HW_USB_ANALOG_USB2_LOOPBACK_SET_ADDR  (HW_USB_ANALOG_USB2_LOOPBACK_ADDR + 0x4)
#define HW_USB_ANALOG_USB2_LOOPBACK_CLR_ADDR  (HW_USB_ANALOG_USB2_LOOPBACK_ADDR + 0x8)
#define HW_USB_ANALOG_USB2_LOOPBACK_TOG_ADDR  (HW_USB_ANALOG_USB2_LOOPBACK_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB2_LOOPBACK           (*(volatile hw_usb_analog_usb2_loopback_t *) HW_USB_ANALOG_USB2_LOOPBACK_ADDR)
#define HW_USB_ANALOG_USB2_LOOPBACK_RD()      (HW_USB_ANALOG_USB2_LOOPBACK.U)
#define HW_USB_ANALOG_USB2_LOOPBACK_WR(v)     (HW_USB_ANALOG_USB2_LOOPBACK.U = (v))
#define HW_USB_ANALOG_USB2_LOOPBACK_SET(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_LOOPBACK_SET_ADDR) = (v))
#define HW_USB_ANALOG_USB2_LOOPBACK_CLR(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_LOOPBACK_CLR_ADDR) = (v))
#define HW_USB_ANALOG_USB2_LOOPBACK_TOG(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_LOOPBACK_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual USB_ANALOG_USB2_LOOPBACK bitfields
 */

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field UTMI_TESTSTART[0] (RW)
 *
 * This bit enables the USB2 loopback test.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART      (0)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART.
#define BM_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART      (0x00000001)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART) >> BP_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART)

//! @brief Format value for bitfield USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART.
#define BF_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART) & BM_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_TESTSTART field to a new value.
#define BW_USB_ANALOG_USB2_LOOPBACK_UTMI_TESTSTART(v)   BF_CS1(USB_ANALOG_USB2_LOOPBACK, UTMI_TESTSTART, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field UTMI_DIG_TST0[1] (RW)
 *
 * Mode control for USB2.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0      (1)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0.
#define BM_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0      (0x00000002)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0 from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0) >> BP_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0)

//! @brief Format value for bitfield USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0.
#define BF_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0) & BM_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_DIG_TST0 field to a new value.
#define BW_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST0(v)   BF_CS1(USB_ANALOG_USB2_LOOPBACK, UTMI_DIG_TST0, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field UTMI_DIG_TST1[2] (RW)
 *
 * Mode control for USB2.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1      (2)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1.
#define BM_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1      (0x00000004)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1 from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1) >> BP_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1)

//! @brief Format value for bitfield USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1.
#define BF_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1) & BM_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_DIG_TST1 field to a new value.
#define BW_USB_ANALOG_USB2_LOOPBACK_UTMI_DIG_TST1(v)   BF_CS1(USB_ANALOG_USB2_LOOPBACK, UTMI_DIG_TST1, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field TSTI_TX_HS_MODE[3] (RW)
 *
 * Select HS or FS mode for USB2.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE      (3)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE.
#define BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE      (0x00000008)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE) >> BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE)

//! @brief Format value for bitfield USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE.
#define BF_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE) & BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSTI_TX_HS_MODE field to a new value.
#define BW_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HS_MODE(v)   BF_CS1(USB_ANALOG_USB2_LOOPBACK, TSTI_TX_HS_MODE, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field TSTI_TX_LS_MODE[4] (RW)
 *
 * Set to 1 to choose LS for USB2, set to 0 to choose HS or FS mode which is defined by TSTI1_TX_HS.
 * Defined by TSTI1_TX_HS.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE      (4)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE.
#define BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE      (0x00000010)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE) >> BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE)

//! @brief Format value for bitfield USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE.
#define BF_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE) & BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSTI_TX_LS_MODE field to a new value.
#define BW_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_LS_MODE(v)   BF_CS1(USB_ANALOG_USB2_LOOPBACK, TSTI_TX_LS_MODE, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field TSTI_TX_EN[5] (RW)
 *
 * Enable TX for USB2.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN      (5)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN.
#define BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN      (0x00000020)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN) >> BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN)

//! @brief Format value for bitfield USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN.
#define BF_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN) & BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSTI_TX_EN field to a new value.
#define BW_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_EN(v)   BF_CS1(USB_ANALOG_USB2_LOOPBACK, TSTI_TX_EN, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field TSTI_TX_HIZ[6] (RW)
 *
 * Sets TX Hi-Z for USB2.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ      (6)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ.
#define BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ      (0x00000040)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ) >> BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ)

//! @brief Format value for bitfield USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ.
#define BF_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ) & BM_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSTI_TX_HIZ field to a new value.
#define BW_USB_ANALOG_USB2_LOOPBACK_TSTI_TX_HIZ(v)   BF_CS1(USB_ANALOG_USB2_LOOPBACK, TSTI_TX_HIZ, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field UTMO_DIG_TST0[7] (RO)
 *
 * This read-only bit is a status bit for USB2 LB = 1 is pass.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST0      (7)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST0.
#define BM_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST0      (0x00000080)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST0.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST0 from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST0) >> BP_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST0)

/* --- Register HW_USB_ANALOG_USB2_LOOPBACK, field UTMO_DIG_TST1[8] (RO)
 *
 * This read-only bit is a status bit for USB2 LB = 0 is pass.
 */

#define BP_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST1      (8)      //!< Bit position for USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST1.
#define BM_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST1      (0x00000100)  //!< Bit mask for USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST1.

//! @brief Get value of USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST1 from a register value.
#define BG_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST1) >> BP_USB_ANALOG_USB2_LOOPBACK_UTMO_DIG_TST1)

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_USB2_MISC - USB Misc Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_USB2_MISC - USB Misc Register (RW)
 *
 * Reset value: 0x00000002
 *
 * This register defines controls for USB.
 */
typedef union _hw_usb_analog_usb2_misc
{
    reg32_t U;
    struct _hw_usb_analog_usb2_misc_bitfields
    {
        unsigned HS_USE_EXTERNAL_R : 1; //!< [0] Use external resistor to generate the current bias for the high speed transmitter. This bit should not be changed unless recommended by Freescale.
        unsigned EN_DEGLITCH : 1; //!< [1] Enable the deglitching circuit of the USB PLL output.
        unsigned RESERVED0 : 28; //!< [29:2] Reserved.
        unsigned EN_CLK_UTMI : 1; //!< [30] Enables the clk to the UTMI block.
        unsigned RESERVED1 : 1; //!< [31] Reserved.
    } B;
} hw_usb_analog_usb2_misc_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_USB2_MISC register
 */
#define HW_USB_ANALOG_USB2_MISC_ADDR      (REGS_USB_ANALOG_BASE + 0x250)
#define HW_USB_ANALOG_USB2_MISC_SET_ADDR  (HW_USB_ANALOG_USB2_MISC_ADDR + 0x4)
#define HW_USB_ANALOG_USB2_MISC_CLR_ADDR  (HW_USB_ANALOG_USB2_MISC_ADDR + 0x8)
#define HW_USB_ANALOG_USB2_MISC_TOG_ADDR  (HW_USB_ANALOG_USB2_MISC_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_USB2_MISC           (*(volatile hw_usb_analog_usb2_misc_t *) HW_USB_ANALOG_USB2_MISC_ADDR)
#define HW_USB_ANALOG_USB2_MISC_RD()      (HW_USB_ANALOG_USB2_MISC.U)
#define HW_USB_ANALOG_USB2_MISC_WR(v)     (HW_USB_ANALOG_USB2_MISC.U = (v))
#define HW_USB_ANALOG_USB2_MISC_SET(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_MISC_SET_ADDR) = (v))
#define HW_USB_ANALOG_USB2_MISC_CLR(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_MISC_CLR_ADDR) = (v))
#define HW_USB_ANALOG_USB2_MISC_TOG(v)    ((*(volatile reg32_t *) HW_USB_ANALOG_USB2_MISC_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual USB_ANALOG_USB2_MISC bitfields
 */

/* --- Register HW_USB_ANALOG_USB2_MISC, field HS_USE_EXTERNAL_R[0] (RW)
 *
 * Use external resistor to generate the current bias for the high speed transmitter. This bit
 * should not be changed unless recommended by Freescale.
 */

#define BP_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R      (0)      //!< Bit position for USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R.
#define BM_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R      (0x00000001)  //!< Bit mask for USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R.

//! @brief Get value of USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R from a register value.
#define BG_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R) >> BP_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R)

//! @brief Format value for bitfield USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R.
#define BF_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R) & BM_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HS_USE_EXTERNAL_R field to a new value.
#define BW_USB_ANALOG_USB2_MISC_HS_USE_EXTERNAL_R(v)   BF_CS1(USB_ANALOG_USB2_MISC, HS_USE_EXTERNAL_R, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_MISC, field EN_DEGLITCH[1] (RW)
 *
 * Enable the deglitching circuit of the USB PLL output.
 */

#define BP_USB_ANALOG_USB2_MISC_EN_DEGLITCH      (1)      //!< Bit position for USB_ANALOG_USB2_MISC_EN_DEGLITCH.
#define BM_USB_ANALOG_USB2_MISC_EN_DEGLITCH      (0x00000002)  //!< Bit mask for USB_ANALOG_USB2_MISC_EN_DEGLITCH.

//! @brief Get value of USB_ANALOG_USB2_MISC_EN_DEGLITCH from a register value.
#define BG_USB_ANALOG_USB2_MISC_EN_DEGLITCH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_MISC_EN_DEGLITCH) >> BP_USB_ANALOG_USB2_MISC_EN_DEGLITCH)

//! @brief Format value for bitfield USB_ANALOG_USB2_MISC_EN_DEGLITCH.
#define BF_USB_ANALOG_USB2_MISC_EN_DEGLITCH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_MISC_EN_DEGLITCH) & BM_USB_ANALOG_USB2_MISC_EN_DEGLITCH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_DEGLITCH field to a new value.
#define BW_USB_ANALOG_USB2_MISC_EN_DEGLITCH(v)   BF_CS1(USB_ANALOG_USB2_MISC, EN_DEGLITCH, v)
#endif

/* --- Register HW_USB_ANALOG_USB2_MISC, field EN_CLK_UTMI[30] (RW)
 *
 * Enables the clk to the UTMI block.
 */

#define BP_USB_ANALOG_USB2_MISC_EN_CLK_UTMI      (30)      //!< Bit position for USB_ANALOG_USB2_MISC_EN_CLK_UTMI.
#define BM_USB_ANALOG_USB2_MISC_EN_CLK_UTMI      (0x40000000)  //!< Bit mask for USB_ANALOG_USB2_MISC_EN_CLK_UTMI.

//! @brief Get value of USB_ANALOG_USB2_MISC_EN_CLK_UTMI from a register value.
#define BG_USB_ANALOG_USB2_MISC_EN_CLK_UTMI(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_USB2_MISC_EN_CLK_UTMI) >> BP_USB_ANALOG_USB2_MISC_EN_CLK_UTMI)

//! @brief Format value for bitfield USB_ANALOG_USB2_MISC_EN_CLK_UTMI.
#define BF_USB_ANALOG_USB2_MISC_EN_CLK_UTMI(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_USB_ANALOG_USB2_MISC_EN_CLK_UTMI) & BM_USB_ANALOG_USB2_MISC_EN_CLK_UTMI)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_CLK_UTMI field to a new value.
#define BW_USB_ANALOG_USB2_MISC_EN_CLK_UTMI(v)   BF_CS1(USB_ANALOG_USB2_MISC, EN_CLK_UTMI, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_USB_ANALOG_DIGPROG - Chip Silicon Version
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_ANALOG_DIGPROG - Chip Silicon Version (RO)
 *
 * Reset value: 0x00000000
 *
 * The DIGPROG register returns the digital program ID for the silicon.
 */
typedef union _hw_usb_analog_digprog
{
    reg32_t U;
    struct _hw_usb_analog_digprog_bitfields
    {
        unsigned MINOR : 8; //!< [7:0] Fixed read-only value reflecting the MINOR field of the RTL version.
        unsigned MAJOR : 16; //!< [23:8] Fixed read-only value reflecting the MAJOR field of the RTL version.
        unsigned RESERVED0 : 8; //!< [31:24] Reserved.
    } B;
} hw_usb_analog_digprog_t;
#endif

/*
 * constants & macros for entire USB_ANALOG_DIGPROG register
 */
#define HW_USB_ANALOG_DIGPROG_ADDR      (REGS_USB_ANALOG_BASE + 0x260)

#ifndef __LANGUAGE_ASM__
#define HW_USB_ANALOG_DIGPROG           (*(volatile hw_usb_analog_digprog_t *) HW_USB_ANALOG_DIGPROG_ADDR)
#define HW_USB_ANALOG_DIGPROG_RD()      (HW_USB_ANALOG_DIGPROG.U)
#endif

/*
 * constants & macros for individual USB_ANALOG_DIGPROG bitfields
 */

/* --- Register HW_USB_ANALOG_DIGPROG, field MINOR[7:0] (RO)
 *
 * Fixed read-only value reflecting the MINOR field of the RTL version.
 */

#define BP_USB_ANALOG_DIGPROG_MINOR      (0)      //!< Bit position for USB_ANALOG_DIGPROG_MINOR.
#define BM_USB_ANALOG_DIGPROG_MINOR      (0x000000ff)  //!< Bit mask for USB_ANALOG_DIGPROG_MINOR.

//! @brief Get value of USB_ANALOG_DIGPROG_MINOR from a register value.
#define BG_USB_ANALOG_DIGPROG_MINOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_DIGPROG_MINOR) >> BP_USB_ANALOG_DIGPROG_MINOR)

/* --- Register HW_USB_ANALOG_DIGPROG, field MAJOR[23:8] (RO)
 *
 * Fixed read-only value reflecting the MAJOR field of the RTL version.
 */

#define BP_USB_ANALOG_DIGPROG_MAJOR      (8)      //!< Bit position for USB_ANALOG_DIGPROG_MAJOR.
#define BM_USB_ANALOG_DIGPROG_MAJOR      (0x00ffff00)  //!< Bit mask for USB_ANALOG_DIGPROG_MAJOR.

//! @brief Get value of USB_ANALOG_DIGPROG_MAJOR from a register value.
#define BG_USB_ANALOG_DIGPROG_MAJOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_USB_ANALOG_DIGPROG_MAJOR) >> BP_USB_ANALOG_DIGPROG_MAJOR)


/*!
 * @brief All USB_ANALOG module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_usb_analog
{
    reg32_t _reserved0[104];
    volatile hw_usb_analog_usb1_vbus_detect_t USB1_VBUS_DETECT; //!< USB VBUS Detect Register
    volatile reg32_t USB1_VBUS_DETECT_SET; //!< USB VBUS Detect Register Set
    volatile reg32_t USB1_VBUS_DETECT_CLR; //!< USB VBUS Detect Register Clear
    volatile reg32_t USB1_VBUS_DETECT_TOG; //!< USB VBUS Detect Register Toggle
    volatile hw_usb_analog_usb1_chrg_detect_t USB1_CHRG_DETECT; //!< USB Charger Detect Register
    volatile reg32_t USB1_CHRG_DETECT_SET; //!< USB Charger Detect Register Set
    volatile reg32_t USB1_CHRG_DETECT_CLR; //!< USB Charger Detect Register Clear
    volatile reg32_t USB1_CHRG_DETECT_TOG; //!< USB Charger Detect Register Toggle
    volatile hw_usb_analog_usb1_vbus_detect_stat_t USB1_VBUS_DETECT_STAT; //!< USB VBUS Detect Status Register
    reg32_t _reserved1[3];
    volatile hw_usb_analog_usb1_chrg_detect_stat_t USB1_CHRG_DETECT_STAT; //!< USB Charger Detect Status Register
    reg32_t _reserved2[3];
    volatile hw_usb_analog_usb1_loopback_t USB1_LOOPBACK; //!< USB Loopback Test Register
    volatile reg32_t USB1_LOOPBACK_SET; //!< USB Loopback Test Register Set
    volatile reg32_t USB1_LOOPBACK_CLR; //!< USB Loopback Test Register Clear
    volatile reg32_t USB1_LOOPBACK_TOG; //!< USB Loopback Test Register Toggle
    volatile hw_usb_analog_usb1_misc_t USB1_MISC; //!< USB Misc Register
    volatile reg32_t USB1_MISC_SET; //!< USB Misc Register Set
    volatile reg32_t USB1_MISC_CLR; //!< USB Misc Register Clear
    volatile reg32_t USB1_MISC_TOG; //!< USB Misc Register Toggle
    volatile hw_usb_analog_usb2_vbus_detect_t USB2_VBUS_DETECT; //!< USB VBUS Detect Register
    volatile reg32_t USB2_VBUS_DETECT_SET; //!< USB VBUS Detect Register Set
    volatile reg32_t USB2_VBUS_DETECT_CLR; //!< USB VBUS Detect Register Clear
    volatile reg32_t USB2_VBUS_DETECT_TOG; //!< USB VBUS Detect Register Toggle
    volatile hw_usb_analog_usb2_chrg_detect_t USB2_CHRG_DETECT; //!< USB Charger Detect Register
    volatile reg32_t USB2_CHRG_DETECT_SET; //!< USB Charger Detect Register Set
    volatile reg32_t USB2_CHRG_DETECT_CLR; //!< USB Charger Detect Register Clear
    volatile reg32_t USB2_CHRG_DETECT_TOG; //!< USB Charger Detect Register Toggle
    volatile hw_usb_analog_usb2_vbus_detect_stat_t USB2_VBUS_DETECT_STAT; //!< USB VBUS Detect Status Register
    reg32_t _reserved3[3];
    volatile hw_usb_analog_usb2_chrg_detect_stat_t USB2_CHRG_DETECT_STAT; //!< USB Charger Detect Status Register
    reg32_t _reserved4[3];
    volatile hw_usb_analog_usb2_loopback_t USB2_LOOPBACK; //!< USB Loopback Test Register
    volatile reg32_t USB2_LOOPBACK_SET; //!< USB Loopback Test Register Set
    volatile reg32_t USB2_LOOPBACK_CLR; //!< USB Loopback Test Register Clear
    volatile reg32_t USB2_LOOPBACK_TOG; //!< USB Loopback Test Register Toggle
    volatile hw_usb_analog_usb2_misc_t USB2_MISC; //!< USB Misc Register
    volatile reg32_t USB2_MISC_SET; //!< USB Misc Register Set
    volatile reg32_t USB2_MISC_CLR; //!< USB Misc Register Clear
    volatile reg32_t USB2_MISC_TOG; //!< USB Misc Register Toggle
    volatile hw_usb_analog_digprog_t DIGPROG; //!< Chip Silicon Version
} hw_usb_analog_t;
#pragma pack()

//! @brief Macro to access all USB_ANALOG registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USB_ANALOG(0)</code>.
#define HW_USB_ANALOG     (*(volatile hw_usb_analog_t *) REGS_USB_ANALOG_BASE)

#endif


#endif // __HW_USB_ANALOG_REGISTERS_H__
