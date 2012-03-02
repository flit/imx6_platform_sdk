/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _EPIT_H
#define _EPIT_H

#include "regs.h"

/*
 * i.MX6SL EPIT registers defined in this header file.
 *
 * - HW_EPIT_EPITCR - Control register
 * - HW_EPIT_EPITSR - Status register
 * - HW_EPIT_EPITLR - Load register
 * - HW_EPIT_EPITCMPR - Compare register
 * - HW_EPIT_EPITCNR - Counter register
 *
 * hw_epit_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_EPIT_BASE
#define REGS_EPIT1_BASE (0x020d0000) //!< Base address for EPIT instance number 1.
#define REGS_EPIT2_BASE (0x020d4000) //!< Base address for EPIT instance number 2.

//! @brief Get the base address of EPIT by instance number.
//! @param x EPIT instance number, from 0 through 2.
#define REGS_EPIT_BASE(x) ( x == 1 ? REGS_EPIT1_BASE : x == 2 ? REGS_EPIT2_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPIT_EPITCR - Control register (RW)
 *
 * Reset value: 0x00000000
 *
 * The EPIT control register (EPIT_EPITCR) is used to configure the operating settings of the EPIT.
 * It contains the clock division prescaler value and also the interrupt enable bit. Additionally it
 * contains other control bit which are outlined below.  Peripheral (IP) Bus Write access to EPIT
 * Control Register (EPIT_EPITCR) results in one cycle of the wait state (ips_xfr_wait high for 1
 * cycle) , while other valid peripheral (IP) bus accesses are with 0 wait state.
 */
typedef union _hw_epit_epitcr
{
    reg32_t U;
    struct _hw_epit_epitcr_bitfields
    {
        unsigned EN : 1; //!< [0] This bit enables the EPIT. EPIT counter and prescaler value when EPIT is enabled (EN =1), is dependent upon ENMOD and RLD bit as described for ENMOD bit. It is recommended that all registers be properly programmed before setting this bit. This bit is reset by a hardware reset. A software reset does not affect this bit.
        unsigned ENMOD : 1; //!< [1] EPIT enable mode. When EPIT is disabled (EN=0), both main counter and prescaler counter freeze their count at current count values. ENMOD bit is a r/w bit that determines the counter value when the EPIT is enabled again by setting EN bit. If ENMOD bit is set, then main counter is loaded with the load value (If RLD=1)/ 0xFFFF_FFFF (If RLD=0) and prescaler counter is reset, when EPIT is enabled (EN=1). If ENMOD is programmed to 0 then both main counter and prescaler counter restart counting from their frozen values when EPIT is enabled (EN=1). If EPIT is programmed to be disabled in a low-power mode (STOP/WAIT/DEBUG /DOZE ), then both the main counter and the prescaler counter freeze at their current count values when EPIT enters low-power mode. When EPIT exits the low-power mode, both main counter and prescaler counter start counting from their frozen values irrespective of the ENMOD bit. This bit is reset by a hardware reset. A software reset does not affect this bit.
        unsigned OCIEN : 1; //!< [2] Output compare interrupt enable. This bit enables the generation of interrupt on occurrence of compare event.
        unsigned RLD : 1; //!< [3] Counter reload control. This bit is cleared by hardware reset. It decides the counter functionality, whether to run in free-running mode or set-and-forget mode.
        unsigned PRESCALAR : 12; //!< [15:4] Counter clock prescaler value. This bit field determines the prescaler value by which the clock is divided before it goes to the counter
        unsigned SWR : 1; //!< [16] Software reset. The EPIT is reset when this bit is set to 1. It is a self clearing bit. This bit is set when the block is in reset state and is cleared when the reset procedure is over. Setting this bit resets all the registers to their reset values, except for the EN, ENMOD, STOPEN , DOZEN , WAITEN and DBGEN bits in this control register
        unsigned IOVW : 1; //!< [17] EPIT counter overwrite enable. This bit controls the counter data when the modulus register is written. When this bit is set, all writes to the load register overwrites the counter contents and the counter starts subsequently counting down from the programmed value.
        unsigned DBGEN : 1; //!< [18] This bit is used to keep the EPIT functional in debug mode. When this bit is cleared, the input clock is gated off in debug mode.This bit is reset by hardware reset. A software reset does not affect this bit.
        unsigned WAITEN : 1; //!< [19] This read/write control bit enables the operation of the EPIT during wait mode. This bit is reset by a hardware reset. A software reset does not affect this bit.
        unsigned RESERVED0 : 1; //!< [20] Reserved. Writing to these bits does not affect the functionality of EPIT. These bits are always read as zero.
        unsigned STOPEN : 1; //!< [21] EPIT stop mode enable. This read/write control bit enables the operation of the EPIT during stop mode. This bit is reset by a hardware reset and unaffected by software reset.
        unsigned OM : 2; //!< [23:22] EPIT output mode.This bit field determines the mode of EPIT output on the output pin.
        unsigned CLKSRC : 2; //!< [25:24] Select clock source These bits determine which clock input is to be selected for running the counter. This field value should only be changed when the EPIT is disabled by clearing the EN bit in this register. For other programming requirements while changing clock source, refer to .
        unsigned RESERVED1 : 6; //!< [31:26] Reserved. Writing to these bits does not affect the functionality of EPIT. These bits are always read as zero.
    } B;
} hw_epit_epitcr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCR register
 */
#define HW_EPIT_EPITCR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCR(x)           (*(volatile hw_epit_epitcr_t *) HW_EPIT_EPITCR_ADDR(x))
#define HW_EPIT_EPITCR_RD(x)        (HW_EPIT_EPITCR(x).U)
#define HW_EPIT_EPITCR_WR(x, v)     (HW_EPIT_EPITCR(x).U = (v))
#define HW_EPIT_EPITCR_SET(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) |  (v)))
#define HW_EPIT_EPITCR_CLR(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) & ~(v)))
#define HW_EPIT_EPITCR_TOG(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual EPIT_EPITCR bitfields
 */

/* --- Register HW_EPIT_EPITCR, field EN[0] (RW)
 *
 * This bit enables the EPIT. EPIT counter and prescaler value when EPIT is enabled (EN =1), is
 * dependent upon ENMOD and RLD bit as described for ENMOD bit. It is recommended that all registers
 * be properly programmed before setting this bit. This bit is reset by a hardware reset. A software
 * reset does not affect this bit.
 *
 * Values:
 * 0 - EPIT is disabled
 * 1 - EPIT is enabled
 */

#define BP_EPIT_EPITCR_EN      (0)      //!< Bit position for EPIT_EPITCR_EN.
#define BM_EPIT_EPITCR_EN      (0x00000001)  //!< Bit mask for EPIT_EPITCR_EN.

//! @brief Get value of EPIT_EPITCR_EN from a register value.
#define BG_EPIT_EPITCR_EN(r)   (((r) & BM_EPIT_EPITCR_EN) >> BP_EPIT_EPITCR_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_EN.
#define BF_EPIT_EPITCR_EN(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_EN) & BM_EPIT_EPITCR_EN)
#else
//! @brief Format value for bitfield EPIT_EPITCR_EN.
#define BF_EPIT_EPITCR_EN(v)   (((v) << BP_EPIT_EPITCR_EN) & BM_EPIT_EPITCR_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_EPIT_EPITCR_EN(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_EN) | BF_EPIT_EPITCR_EN(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field ENMOD[1] (RW)
 *
 * EPIT enable mode. When EPIT is disabled (EN=0), both main counter and prescaler counter freeze
 * their count at current count values. ENMOD bit is a r/w bit that determines the counter value
 * when the EPIT is enabled again by setting EN bit. If ENMOD bit is set, then main counter is
 * loaded with the load value (If RLD=1)/ 0xFFFF_FFFF (If RLD=0) and prescaler counter is reset,
 * when EPIT is enabled (EN=1). If ENMOD is programmed to 0 then both main counter and prescaler
 * counter restart counting from their frozen values when EPIT is enabled (EN=1). If EPIT is
 * programmed to be disabled in a low-power mode (STOP/WAIT/DEBUG /DOZE ), then both the main
 * counter and the prescaler counter freeze at their current count values when EPIT enters low-power
 * mode. When EPIT exits the low-power mode, both main counter and prescaler counter start counting
 * from their frozen values irrespective of the ENMOD bit. This bit is reset by a hardware reset. A
 * software reset does not affect this bit.
 *
 * Values:
 * 0 - Counter starts counting from the value it had when it was disabled.
 * 1 - Counter starts count from load value (RLD=1) or 0xFFFF_FFFF (If RLD=0)
 */

#define BP_EPIT_EPITCR_ENMOD      (1)      //!< Bit position for EPIT_EPITCR_ENMOD.
#define BM_EPIT_EPITCR_ENMOD      (0x00000002)  //!< Bit mask for EPIT_EPITCR_ENMOD.

//! @brief Get value of EPIT_EPITCR_ENMOD from a register value.
#define BG_EPIT_EPITCR_ENMOD(r)   (((r) & BM_EPIT_EPITCR_ENMOD) >> BP_EPIT_EPITCR_ENMOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_ENMOD.
#define BF_EPIT_EPITCR_ENMOD(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_ENMOD) & BM_EPIT_EPITCR_ENMOD)
#else
//! @brief Format value for bitfield EPIT_EPITCR_ENMOD.
#define BF_EPIT_EPITCR_ENMOD(v)   (((v) << BP_EPIT_EPITCR_ENMOD) & BM_EPIT_EPITCR_ENMOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENMOD field to a new value.
#define BW_EPIT_EPITCR_ENMOD(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_ENMOD) | BF_EPIT_EPITCR_ENMOD(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field OCIEN[2] (RW)
 *
 * Output compare interrupt enable. This bit enables the generation of interrupt on occurrence of
 * compare event.
 *
 * Values:
 * 0 - Compare interrupt disabled
 * 1 - Compare interrupt enabled
 */

#define BP_EPIT_EPITCR_OCIEN      (2)      //!< Bit position for EPIT_EPITCR_OCIEN.
#define BM_EPIT_EPITCR_OCIEN      (0x00000004)  //!< Bit mask for EPIT_EPITCR_OCIEN.

//! @brief Get value of EPIT_EPITCR_OCIEN from a register value.
#define BG_EPIT_EPITCR_OCIEN(r)   (((r) & BM_EPIT_EPITCR_OCIEN) >> BP_EPIT_EPITCR_OCIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_OCIEN.
#define BF_EPIT_EPITCR_OCIEN(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_OCIEN) & BM_EPIT_EPITCR_OCIEN)
#else
//! @brief Format value for bitfield EPIT_EPITCR_OCIEN.
#define BF_EPIT_EPITCR_OCIEN(v)   (((v) << BP_EPIT_EPITCR_OCIEN) & BM_EPIT_EPITCR_OCIEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OCIEN field to a new value.
#define BW_EPIT_EPITCR_OCIEN(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_OCIEN) | BF_EPIT_EPITCR_OCIEN(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field RLD[3] (RW)
 *
 * Counter reload control. This bit is cleared by hardware reset. It decides the counter
 * functionality, whether to run in free-running mode or set-and-forget mode.
 *
 * Values:
 * 0 - When the counter reaches zero it rolls over to 0xFFFF_FFFF (free-running mode)
 * 1 - When the counter reaches zero it reloads from the modulus register (set-and-forget mode)
 */

#define BP_EPIT_EPITCR_RLD      (3)      //!< Bit position for EPIT_EPITCR_RLD.
#define BM_EPIT_EPITCR_RLD      (0x00000008)  //!< Bit mask for EPIT_EPITCR_RLD.

//! @brief Get value of EPIT_EPITCR_RLD from a register value.
#define BG_EPIT_EPITCR_RLD(r)   (((r) & BM_EPIT_EPITCR_RLD) >> BP_EPIT_EPITCR_RLD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_RLD.
#define BF_EPIT_EPITCR_RLD(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_RLD) & BM_EPIT_EPITCR_RLD)
#else
//! @brief Format value for bitfield EPIT_EPITCR_RLD.
#define BF_EPIT_EPITCR_RLD(v)   (((v) << BP_EPIT_EPITCR_RLD) & BM_EPIT_EPITCR_RLD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RLD field to a new value.
#define BW_EPIT_EPITCR_RLD(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_RLD) | BF_EPIT_EPITCR_RLD(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field PRESCALAR[15:4] (RW)
 *
 * Counter clock prescaler value. This bit field determines the prescaler value by which the clock
 * is divided before it goes to the counter
 *
 * Values:
 * 0x000 - Divide by 1
 * 0x001 - Divide by 2
 * 0xFFFF - Divide by 4096
 */

#define BP_EPIT_EPITCR_PRESCALAR      (4)      //!< Bit position for EPIT_EPITCR_PRESCALAR.
#define BM_EPIT_EPITCR_PRESCALAR      (0x0000fff0)  //!< Bit mask for EPIT_EPITCR_PRESCALAR.

//! @brief Get value of EPIT_EPITCR_PRESCALAR from a register value.
#define BG_EPIT_EPITCR_PRESCALAR(r)   (((r) & BM_EPIT_EPITCR_PRESCALAR) >> BP_EPIT_EPITCR_PRESCALAR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_PRESCALAR.
#define BF_EPIT_EPITCR_PRESCALAR(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_PRESCALAR) & BM_EPIT_EPITCR_PRESCALAR)
#else
//! @brief Format value for bitfield EPIT_EPITCR_PRESCALAR.
#define BF_EPIT_EPITCR_PRESCALAR(v)   (((v) << BP_EPIT_EPITCR_PRESCALAR) & BM_EPIT_EPITCR_PRESCALAR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESCALAR field to a new value.
#define BW_EPIT_EPITCR_PRESCALAR(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_PRESCALAR) | BF_EPIT_EPITCR_PRESCALAR(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field SWR[16] (RW)
 *
 * Software reset. The EPIT is reset when this bit is set to 1. It is a self clearing bit. This bit
 * is set when the block is in reset state and is cleared when the reset procedure is over. Setting
 * this bit resets all the registers to their reset values, except for the EN, ENMOD, STOPEN , DOZEN
 * , WAITEN and DBGEN bits in this control register
 *
 * Values:
 * 0 - EPIT is out of reset
 * 1 - EPIT is undergoing reset
 */

#define BP_EPIT_EPITCR_SWR      (16)      //!< Bit position for EPIT_EPITCR_SWR.
#define BM_EPIT_EPITCR_SWR      (0x00010000)  //!< Bit mask for EPIT_EPITCR_SWR.

//! @brief Get value of EPIT_EPITCR_SWR from a register value.
#define BG_EPIT_EPITCR_SWR(r)   (((r) & BM_EPIT_EPITCR_SWR) >> BP_EPIT_EPITCR_SWR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_SWR.
#define BF_EPIT_EPITCR_SWR(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_SWR) & BM_EPIT_EPITCR_SWR)
#else
//! @brief Format value for bitfield EPIT_EPITCR_SWR.
#define BF_EPIT_EPITCR_SWR(v)   (((v) << BP_EPIT_EPITCR_SWR) & BM_EPIT_EPITCR_SWR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SWR field to a new value.
#define BW_EPIT_EPITCR_SWR(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_SWR) | BF_EPIT_EPITCR_SWR(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field IOVW[17] (RW)
 *
 * EPIT counter overwrite enable. This bit controls the counter data when the modulus register is
 * written. When this bit is set, all writes to the load register overwrites the counter contents
 * and the counter starts subsequently counting down from the programmed value.
 *
 * Values:
 * 0 - Write to load register does not result in counter value being overwritten.
 * 1 - Write to load register results in immediate overwriting of counter value.
 */

#define BP_EPIT_EPITCR_IOVW      (17)      //!< Bit position for EPIT_EPITCR_IOVW.
#define BM_EPIT_EPITCR_IOVW      (0x00020000)  //!< Bit mask for EPIT_EPITCR_IOVW.

//! @brief Get value of EPIT_EPITCR_IOVW from a register value.
#define BG_EPIT_EPITCR_IOVW(r)   (((r) & BM_EPIT_EPITCR_IOVW) >> BP_EPIT_EPITCR_IOVW)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_IOVW.
#define BF_EPIT_EPITCR_IOVW(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_IOVW) & BM_EPIT_EPITCR_IOVW)
#else
//! @brief Format value for bitfield EPIT_EPITCR_IOVW.
#define BF_EPIT_EPITCR_IOVW(v)   (((v) << BP_EPIT_EPITCR_IOVW) & BM_EPIT_EPITCR_IOVW)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IOVW field to a new value.
#define BW_EPIT_EPITCR_IOVW(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_IOVW) | BF_EPIT_EPITCR_IOVW(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field DBGEN[18] (RW)
 *
 * This bit is used to keep the EPIT functional in debug mode. When this bit is cleared, the input
 * clock is gated off in debug mode.This bit is reset by hardware reset. A software reset does not
 * affect this bit.
 *
 * Values:
 * 0 - Inactive in debug mode
 * 1 - Active in debug mode
 */

#define BP_EPIT_EPITCR_DBGEN      (18)      //!< Bit position for EPIT_EPITCR_DBGEN.
#define BM_EPIT_EPITCR_DBGEN      (0x00040000)  //!< Bit mask for EPIT_EPITCR_DBGEN.

//! @brief Get value of EPIT_EPITCR_DBGEN from a register value.
#define BG_EPIT_EPITCR_DBGEN(r)   (((r) & BM_EPIT_EPITCR_DBGEN) >> BP_EPIT_EPITCR_DBGEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_DBGEN.
#define BF_EPIT_EPITCR_DBGEN(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_DBGEN) & BM_EPIT_EPITCR_DBGEN)
#else
//! @brief Format value for bitfield EPIT_EPITCR_DBGEN.
#define BF_EPIT_EPITCR_DBGEN(v)   (((v) << BP_EPIT_EPITCR_DBGEN) & BM_EPIT_EPITCR_DBGEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DBGEN field to a new value.
#define BW_EPIT_EPITCR_DBGEN(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_DBGEN) | BF_EPIT_EPITCR_DBGEN(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field WAITEN[19] (RW)
 *
 * This read/write control bit enables the operation of the EPIT during wait mode. This bit is reset
 * by a hardware reset. A software reset does not affect this bit.
 *
 * Values:
 * 0 - EPIT is disabled in wait mode
 * 1 - EPIT is enabled in wait mode
 */

#define BP_EPIT_EPITCR_WAITEN      (19)      //!< Bit position for EPIT_EPITCR_WAITEN.
#define BM_EPIT_EPITCR_WAITEN      (0x00080000)  //!< Bit mask for EPIT_EPITCR_WAITEN.

//! @brief Get value of EPIT_EPITCR_WAITEN from a register value.
#define BG_EPIT_EPITCR_WAITEN(r)   (((r) & BM_EPIT_EPITCR_WAITEN) >> BP_EPIT_EPITCR_WAITEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_WAITEN.
#define BF_EPIT_EPITCR_WAITEN(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_WAITEN) & BM_EPIT_EPITCR_WAITEN)
#else
//! @brief Format value for bitfield EPIT_EPITCR_WAITEN.
#define BF_EPIT_EPITCR_WAITEN(v)   (((v) << BP_EPIT_EPITCR_WAITEN) & BM_EPIT_EPITCR_WAITEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAITEN field to a new value.
#define BW_EPIT_EPITCR_WAITEN(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_WAITEN) | BF_EPIT_EPITCR_WAITEN(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field STOPEN[21] (RW)
 *
 * EPIT stop mode enable. This read/write control bit enables the operation of the EPIT during stop
 * mode. This bit is reset by a hardware reset and unaffected by software reset.
 *
 * Values:
 * 0 - EPIT is disabled in stop mode
 * 1 - EPIT is enabled in stop mode
 */

#define BP_EPIT_EPITCR_STOPEN      (21)      //!< Bit position for EPIT_EPITCR_STOPEN.
#define BM_EPIT_EPITCR_STOPEN      (0x00200000)  //!< Bit mask for EPIT_EPITCR_STOPEN.

//! @brief Get value of EPIT_EPITCR_STOPEN from a register value.
#define BG_EPIT_EPITCR_STOPEN(r)   (((r) & BM_EPIT_EPITCR_STOPEN) >> BP_EPIT_EPITCR_STOPEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_STOPEN.
#define BF_EPIT_EPITCR_STOPEN(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_STOPEN) & BM_EPIT_EPITCR_STOPEN)
#else
//! @brief Format value for bitfield EPIT_EPITCR_STOPEN.
#define BF_EPIT_EPITCR_STOPEN(v)   (((v) << BP_EPIT_EPITCR_STOPEN) & BM_EPIT_EPITCR_STOPEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STOPEN field to a new value.
#define BW_EPIT_EPITCR_STOPEN(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_STOPEN) | BF_EPIT_EPITCR_STOPEN(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field OM[23:22] (RW)
 *
 * EPIT output mode.This bit field determines the mode of EPIT output on the output pin.
 *
 * Values:
 * 00 - EPIT output is disconnected from pad
 * 01 - Toggle output pin
 * 10 - Clear output pin
 * 11 - Set output pin
 */

#define BP_EPIT_EPITCR_OM      (22)      //!< Bit position for EPIT_EPITCR_OM.
#define BM_EPIT_EPITCR_OM      (0x00c00000)  //!< Bit mask for EPIT_EPITCR_OM.

//! @brief Get value of EPIT_EPITCR_OM from a register value.
#define BG_EPIT_EPITCR_OM(r)   (((r) & BM_EPIT_EPITCR_OM) >> BP_EPIT_EPITCR_OM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_OM.
#define BF_EPIT_EPITCR_OM(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_OM) & BM_EPIT_EPITCR_OM)
#else
//! @brief Format value for bitfield EPIT_EPITCR_OM.
#define BF_EPIT_EPITCR_OM(v)   (((v) << BP_EPIT_EPITCR_OM) & BM_EPIT_EPITCR_OM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OM field to a new value.
#define BW_EPIT_EPITCR_OM(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_OM) | BF_EPIT_EPITCR_OM(v)))
#endif


/* --- Register HW_EPIT_EPITCR, field CLKSRC[25:24] (RW)
 *
 * Select clock source These bits determine which clock input is to be selected for running the
 * counter. This field value should only be changed when the EPIT is disabled by clearing the EN bit
 * in this register. For other programming requirements while changing clock source, refer to .
 *
 * Values:
 * 00 - Clock is off
 * 01 - Peripheral clock (ipg_clk)
 * 10 - High-frequency reference clock (ipg_clk_highfreq)
 * 11 - Low-frequency reference clock (ipg_clk_32k)
 */

#define BP_EPIT_EPITCR_CLKSRC      (24)      //!< Bit position for EPIT_EPITCR_CLKSRC.
#define BM_EPIT_EPITCR_CLKSRC      (0x03000000)  //!< Bit mask for EPIT_EPITCR_CLKSRC.

//! @brief Get value of EPIT_EPITCR_CLKSRC from a register value.
#define BG_EPIT_EPITCR_CLKSRC(r)   (((r) & BM_EPIT_EPITCR_CLKSRC) >> BP_EPIT_EPITCR_CLKSRC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCR_CLKSRC.
#define BF_EPIT_EPITCR_CLKSRC(v)   ((((reg32_t) v) << BP_EPIT_EPITCR_CLKSRC) & BM_EPIT_EPITCR_CLKSRC)
#else
//! @brief Format value for bitfield EPIT_EPITCR_CLKSRC.
#define BF_EPIT_EPITCR_CLKSRC(v)   (((v) << BP_EPIT_EPITCR_CLKSRC) & BM_EPIT_EPITCR_CLKSRC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKSRC field to a new value.
#define BW_EPIT_EPITCR_CLKSRC(x, v)   (HW_EPIT_EPITCR_WR(x, (HW_EPIT_EPITCR_RD(x) & ~BM_EPIT_EPITCR_CLKSRC) | BF_EPIT_EPITCR_CLKSRC(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPIT_EPITSR - Status register (RW)
 *
 * Reset value: 0x00000000
 *
 * The EPIT status register (EPIT_EPITSR) has a single status bit for the output compare event. The
 * bit is a write 1 to clear bit.
 */
typedef union _hw_epit_epitsr
{
    reg32_t U;
    struct _hw_epit_epitsr_bitfields
    {
        unsigned OCIF : 1; //!< [0] Output compare interrupt flag. This bit is the interrupt flag that is set when the content of counter equals the content of the compare register (EPIT_EPITCMPR). The bit is a write 1 to clear bit.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved. Writing to these bits does not affect the functionality of EPIT. These bits are always read as zero.
    } B;
} hw_epit_epitsr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITSR register
 */
#define HW_EPIT_EPITSR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITSR(x)           (*(volatile hw_epit_epitsr_t *) HW_EPIT_EPITSR_ADDR(x))
#define HW_EPIT_EPITSR_RD(x)        (HW_EPIT_EPITSR(x).U)
#define HW_EPIT_EPITSR_WR(x, v)     (HW_EPIT_EPITSR(x).U = (v))
#define HW_EPIT_EPITSR_SET(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) |  (v)))
#define HW_EPIT_EPITSR_CLR(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) & ~(v)))
#define HW_EPIT_EPITSR_TOG(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual EPIT_EPITSR bitfields
 */

/* --- Register HW_EPIT_EPITSR, field OCIF[0] (W1C)
 *
 * Output compare interrupt flag. This bit is the interrupt flag that is set when the content of
 * counter equals the content of the compare register (EPIT_EPITCMPR). The bit is a write 1 to clear
 * bit.
 *
 * Values:
 * 0 - Compare event hasn't occurred
 * 1 - Compare event occurred
 */

#define BP_EPIT_EPITSR_OCIF      (0)      //!< Bit position for EPIT_EPITSR_OCIF.
#define BM_EPIT_EPITSR_OCIF      (0x00000001)  //!< Bit mask for EPIT_EPITSR_OCIF.

//! @brief Get value of EPIT_EPITSR_OCIF from a register value.
#define BG_EPIT_EPITSR_OCIF(r)   (((r) & BM_EPIT_EPITSR_OCIF) >> BP_EPIT_EPITSR_OCIF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITSR_OCIF.
#define BF_EPIT_EPITSR_OCIF(v)   ((((reg32_t) v) << BP_EPIT_EPITSR_OCIF) & BM_EPIT_EPITSR_OCIF)
#else
//! @brief Format value for bitfield EPIT_EPITSR_OCIF.
#define BF_EPIT_EPITSR_OCIF(v)   (((v) << BP_EPIT_EPITSR_OCIF) & BM_EPIT_EPITSR_OCIF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OCIF field to a new value.
#define BW_EPIT_EPITSR_OCIF(x, v)   (HW_EPIT_EPITSR_WR(x, (HW_EPIT_EPITSR_RD(x) & ~BM_EPIT_EPITSR_OCIF) | BF_EPIT_EPITSR_OCIF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPIT_EPITLR - Load register (RW)
 *
 * Reset value: 0xffffffff
 *
 * The EPIT load register (EPIT_EPITLR) contains the value that is to be loaded into the counter
 * when EPIT counter reaches zero if the RLD bit in EPIT_EPITCR is set. If the IOVW bit in the
 * EPIT_EPITCR is set then a write to this register overwrites the value of the EPIT counter
 * register in addition to updating this registers value. This overwrite feature is active even if
 * the RLD bit is not set.  IP Bus Write access to EPIT Load Register (EPITLR) results in one cycle
 * of wait state (ips_xfr_wait high for 1 cycle), while other valid IP bus accesses are with 0 wait
 * state.
 */
typedef union _hw_epit_epitlr
{
    reg32_t U;
    struct _hw_epit_epitlr_bitfields
    {
        unsigned LOAD : 32; //!< [31:0] Load value. Value that is loaded into the counter at the start of each count cycle.
    } B;
} hw_epit_epitlr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITLR register
 */
#define HW_EPIT_EPITLR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITLR(x)           (*(volatile hw_epit_epitlr_t *) HW_EPIT_EPITLR_ADDR(x))
#define HW_EPIT_EPITLR_RD(x)        (HW_EPIT_EPITLR(x).U)
#define HW_EPIT_EPITLR_WR(x, v)     (HW_EPIT_EPITLR(x).U = (v))
#define HW_EPIT_EPITLR_SET(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) |  (v)))
#define HW_EPIT_EPITLR_CLR(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) & ~(v)))
#define HW_EPIT_EPITLR_TOG(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual EPIT_EPITLR bitfields
 */

/* --- Register HW_EPIT_EPITLR, field LOAD[31:0] (RW)
 *
 * Load value. Value that is loaded into the counter at the start of each count cycle.
 */

#define BP_EPIT_EPITLR_LOAD      (0)      //!< Bit position for EPIT_EPITLR_LOAD.
#define BM_EPIT_EPITLR_LOAD      (0xffffffff)  //!< Bit mask for EPIT_EPITLR_LOAD.

//! @brief Get value of EPIT_EPITLR_LOAD from a register value.
#define BG_EPIT_EPITLR_LOAD(r)   (((r) & BM_EPIT_EPITLR_LOAD) >> BP_EPIT_EPITLR_LOAD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITLR_LOAD.
#define BF_EPIT_EPITLR_LOAD(v)   ((((reg32_t) v) << BP_EPIT_EPITLR_LOAD) & BM_EPIT_EPITLR_LOAD)
#else
//! @brief Format value for bitfield EPIT_EPITLR_LOAD.
#define BF_EPIT_EPITLR_LOAD(v)   (((v) << BP_EPIT_EPITLR_LOAD) & BM_EPIT_EPITLR_LOAD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOAD field to a new value.
#define BW_EPIT_EPITLR_LOAD(x, v)   (HW_EPIT_EPITLR_WR(x, (HW_EPIT_EPITLR_RD(x) & ~BM_EPIT_EPITLR_LOAD) | BF_EPIT_EPITLR_LOAD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPIT_EPITCMPR - Compare register (RW)
 *
 * Reset value: 0x00000000
 *
 * The EPIT compare register (EPIT_EPITCMPR) holds the value that determines when a compare event is
 * generated.
 */
typedef union _hw_epit_epitcmpr
{
    reg32_t U;
    struct _hw_epit_epitcmpr_bitfields
    {
        unsigned COMPARE : 32; //!< [31:0] Compare Value. When the counter value equals this bit field value a compare event is generated.
    } B;
} hw_epit_epitcmpr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCMPR register
 */
#define HW_EPIT_EPITCMPR_ADDR(x)      (REGS_EPIT_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCMPR(x)           (*(volatile hw_epit_epitcmpr_t *) HW_EPIT_EPITCMPR_ADDR(x))
#define HW_EPIT_EPITCMPR_RD(x)        (HW_EPIT_EPITCMPR(x).U)
#define HW_EPIT_EPITCMPR_WR(x, v)     (HW_EPIT_EPITCMPR(x).U = (v))
#define HW_EPIT_EPITCMPR_SET(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) |  (v)))
#define HW_EPIT_EPITCMPR_CLR(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) & ~(v)))
#define HW_EPIT_EPITCMPR_TOG(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual EPIT_EPITCMPR bitfields
 */

/* --- Register HW_EPIT_EPITCMPR, field COMPARE[31:0] (RW)
 *
 * Compare Value. When the counter value equals this bit field value a compare event is generated.
 */

#define BP_EPIT_EPITCMPR_COMPARE      (0)      //!< Bit position for EPIT_EPITCMPR_COMPARE.
#define BM_EPIT_EPITCMPR_COMPARE      (0xffffffff)  //!< Bit mask for EPIT_EPITCMPR_COMPARE.

//! @brief Get value of EPIT_EPITCMPR_COMPARE from a register value.
#define BG_EPIT_EPITCMPR_COMPARE(r)   (((r) & BM_EPIT_EPITCMPR_COMPARE) >> BP_EPIT_EPITCMPR_COMPARE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield EPIT_EPITCMPR_COMPARE.
#define BF_EPIT_EPITCMPR_COMPARE(v)   ((((reg32_t) v) << BP_EPIT_EPITCMPR_COMPARE) & BM_EPIT_EPITCMPR_COMPARE)
#else
//! @brief Format value for bitfield EPIT_EPITCMPR_COMPARE.
#define BF_EPIT_EPITCMPR_COMPARE(v)   (((v) << BP_EPIT_EPITCMPR_COMPARE) & BM_EPIT_EPITCMPR_COMPARE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPARE field to a new value.
#define BW_EPIT_EPITCMPR_COMPARE(x, v)   (HW_EPIT_EPITCMPR_WR(x, (HW_EPIT_EPITCMPR_RD(x) & ~BM_EPIT_EPITCMPR_COMPARE) | BF_EPIT_EPITCMPR_COMPARE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EPIT_EPITCNR - Counter register (RO)
 *
 * Reset value: 0xffffffff
 *
 * The EPIT counter register (EPIT_EPITCNR) contains the current count value and can be read at any
 * time without disturbing the counter. This is a read-only register and any attempt to write into
 * it generates a transfer error. But if the IOVW bit in EPIT_EPITCR is set, the value of this
 * register can be overwritten with a write to EPIT_EPITLR. This change is reflected when this
 * register is subsequently read.  .
 */
typedef union _hw_epit_epitcnr
{
    reg32_t U;
    struct _hw_epit_epitcnr_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] Counter value. This contains the current value of the counter.
    } B;
} hw_epit_epitcnr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCNR register
 */
#define HW_EPIT_EPITCNR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCNR(x)           (*(volatile hw_epit_epitcnr_t *) HW_EPIT_EPITCNR_ADDR(x))
#define HW_EPIT_EPITCNR_RD(x)        (HW_EPIT_EPITCNR(x).U)
#endif

/*
 * constants & macros for individual EPIT_EPITCNR bitfields
 */

/* --- Register HW_EPIT_EPITCNR, field COUNT[31:0] (RO)
 *
 * Counter value. This contains the current value of the counter.
 */

#define BP_EPIT_EPITCNR_COUNT      (0)      //!< Bit position for EPIT_EPITCNR_COUNT.
#define BM_EPIT_EPITCNR_COUNT      (0xffffffff)  //!< Bit mask for EPIT_EPITCNR_COUNT.

//! @brief Get value of EPIT_EPITCNR_COUNT from a register value.
#define BG_EPIT_EPITCNR_COUNT(r)   (((r) & BM_EPIT_EPITCNR_COUNT) >> BP_EPIT_EPITCNR_COUNT)


/*!
 * @brief All EPIT module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_epit
{
    volatile hw_epit_epitcr_t EPITCR; //!< Control register
    volatile hw_epit_epitsr_t EPITSR; //!< Status register
    volatile hw_epit_epitlr_t EPITLR; //!< Load register
    volatile hw_epit_epitcmpr_t EPITCMPR; //!< Compare register
    volatile hw_epit_epitcnr_t EPITCNR; //!< Counter register
} hw_epit_t;
#pragma pack()
#endif

//! @brief Macro to access all EPIT registers.
//! @param x EPIT instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_EPIT(0)</code>.
#define HW_EPIT(x)     (*(volatile hw_epit_t *) REGS_EPIT_BASE(x))


#endif // _EPIT_H
