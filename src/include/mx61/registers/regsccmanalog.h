/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CCM_ANALOG_H
#define _CCM_ANALOG_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_CCM_ANALOG_PLL_SYS - Analog System PLL control Register
 * - HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL - Analog USBPHY0 480MHz PLL Control Register
 * - HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL - Analog USBPHY1 480MHz PLL Control Register
 * - HW_CCM_ANALOG_PLL_528 - Analog 528MHz PLL Control Register
 * - HW_CCM_ANALOG_PLL_528_SS - 528MHz PLL Spread Spectrum Register.
 * - HW_CCM_ANALOG_PLL_528_NUM - Numerator of 528MHz PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_528_DENOM - Denominator of 528MHz PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_AUDIO - Analog Audio PLL control Register
 * - HW_CCM_ANALOG_PLL_AUDIO_NUM - Numerator of Audio PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_AUDIO_DENOM - Denominator of Audio PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_VIDEO - Analog Video PLL control Register
 * - HW_CCM_ANALOG_PLL_VIDEO_NUM - Numerator of Video PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_VIDEO_DENOM - Denominator of Video PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_MLB - MLB PLL Control Register
 * - HW_CCM_ANALOG_PLL_ENET - Analog ENET PLL Control Register
 * - HW_CCM_ANALOG_PFD_480 - 480MHz Clock Phase Fractional Divider Control Register
 * - HW_CCM_ANALOG_PFD_528 - 528MHz Clock Phase Fractional Divider Control Register
 *
 * hw_ccm_analog_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_CCM_ANALOG_BASE
#define REGS_CCM_ANALOG_BASE (0x020c8000) //!< Base address for CCM_ANALOG.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_SYS - Analog System PLL control Register (RW)
 *
 * The control register provides control for the system PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 7; //!< This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin * div_select/2.0.
        unsigned HALF_LF : 1; //!< Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale.
        unsigned HALF_CP : 1; //!< Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< Analog debug bit.
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable the clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned LVDS_SEL : 1; //!< Analog Debug Bit
        unsigned LVDS_24MHZ_SEL : 1; //!< Analog Debug Bit
        unsigned PLL_SEL : 1; //!< Reserved
        unsigned RSVD0 : 11; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_sys_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_SYS register
 */
#define HW_CCM_ANALOG_PLL_SYS_ADDR      (REGS_CCM_ANALOG_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_SYS           (*(volatile hw_ccm_analog_pll_sys_t *) HW_CCM_ANALOG_PLL_SYS_ADDR)
#define HW_CCM_ANALOG_PLL_SYS_RD()      (HW_CCM_ANALOG_PLL_SYS.U)
#define HW_CCM_ANALOG_PLL_SYS_WR(v)     (HW_CCM_ANALOG_PLL_SYS.U = (v))
#define HW_CCM_ANALOG_PLL_SYS_SET(v)    (HW_CCM_ANALOG_PLL_SYS_WR(HW_CCM_ANALOG_PLL_SYS_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_SYS_CLR(v)    (HW_CCM_ANALOG_PLL_SYS_WR(HW_CCM_ANALOG_PLL_SYS_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_SYS_TOG(v)    (HW_CCM_ANALOG_PLL_SYS_WR(HW_CCM_ANALOG_PLL_SYS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_SYS bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin *
 * div_select/2.0.
 */

#define BP_CCM_ANALOG_PLL_SYS_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_SYS_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_SYS_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_SYS_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_SYS_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_HALF_LF      7
#define BM_CCM_ANALOG_PLL_SYS_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_SYS_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_SYS_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_SYS_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_HALF_CP      9
#define BM_CCM_ANALOG_PLL_SYS_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_SYS_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_SYS_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_SYS_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_SYS_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_SYS_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_SYS_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_SYS_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_SYS_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_SYS, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field ENABLE (RW)
 *
 * Enable the clock output.
 */

#define BP_CCM_ANALOG_PLL_SYS_ENABLE      13
#define BM_CCM_ANALOG_PLL_SYS_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_SYS_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_SYS_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_SYS_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_SYS, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_SYS, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_SYS, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_SYS_BYPASS      16
#define BM_CCM_ANALOG_PLL_SYS_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_SYS_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_SYS_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_SYS_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_SYS, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field LVDS_SEL (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_LVDS_SEL      17
#define BM_CCM_ANALOG_PLL_SYS_LVDS_SEL      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_LVDS_SEL(v)   ((((reg32_t) v) << 17) & BM_CCM_ANALOG_PLL_SYS_LVDS_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_LVDS_SEL(v)   (((v) << 17) & BM_CCM_ANALOG_PLL_SYS_LVDS_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_LVDS_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS, LVDS_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field LVDS_24MHZ_SEL (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL      18
#define BM_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_24MHZ_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS, LVDS_24MHZ_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field PLL_SEL (RW)
 *
 * Reserved
 */

#define BP_CCM_ANALOG_PLL_SYS_PLL_SEL      19
#define BM_CCM_ANALOG_PLL_SYS_PLL_SEL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_PLL_SEL(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_SYS_PLL_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_PLL_SEL(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_SYS_PLL_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_PLL_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS, PLL_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_SYS_RSVD0      20
#define BM_CCM_ANALOG_PLL_SYS_RSVD0      0x7ff00000

/* --- Register HW_CCM_ANALOG_PLL_SYS, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_SYS_LOCK      31
#define BM_CCM_ANALOG_PLL_SYS_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL - Analog USBPHY0 480MHz PLL Control Register (RW)
 *
 * The control register provides control for USBPHY0 480MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RSVD0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set automatically when USBPHYn remote wakeup event occurs.
        unsigned RSVD1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RSVD11 : 17; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy0_pll_480_ctrl_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY0_PLL_480_CTRL register
 */
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ADDR      (REGS_CCM_ANALOG_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL           (*(volatile hw_ccm_analog_usbphy0_pll_480_ctrl_t *) HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ADDR)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RD()      (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL.U)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_WR(v)     (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL.U = (v))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RD() |  (v)))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RD() & ~(v)))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY0_PLL_480_CTRL bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT      0
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RSVD0      2
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RSVD0      0x0000003c

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field EN_USB_CLKS (RW)
 *
 * Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted
 * in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set
 * automatically when USBPHYn remote wakeup event occurs.
 *
 * Values:
 * 0 - PLL outputs for USBPHYn off.
 * 1 - PLL outputs for USBPHYn on.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS      6
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS(v)   ((((reg32_t) v) << 6) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS(v)   (((v) << 6) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL, EN_USB_CLKS, v)
#endif


/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field RSVD1 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RSVD1      7
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RSVD1      0x00000f80

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field POWER (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER      12
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER(v)   (((v) << 12) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field ENABLE (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE      13
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field RSVD1 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RSVD1      14
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RSVD1      0x7fffc000

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK      31
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL - Analog USBPHY1 480MHz PLL Control Register (RW)
 *
 * The control register provides control for USBPHY1 480MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RSVD0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1 are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned RSVD1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RSVD11 : 17; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy1_pll_480_ctrl_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY1_PLL_480_CTRL register
 */
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ADDR      (REGS_CCM_ANALOG_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL           (*(volatile hw_ccm_analog_usbphy1_pll_480_ctrl_t *) HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ADDR)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RD()      (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL.U)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_WR(v)     (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL.U = (v))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RD() |  (v)))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RD() & ~(v)))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY1_PLL_480_CTRL bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT      0
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RSVD0      2
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RSVD0      0x0000003c

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field EN_USB_CLKS (RW)
 *
 * 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1
 * are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable
 * USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when
 * USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS      6
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS(v)   ((((reg32_t) v) << 6) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS(v)   (((v) << 6) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL, EN_USB_CLKS, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field RSVD1 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RSVD1      7
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RSVD1      0x00000f80

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field POWER (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER      12
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER(v)   (((v) << 12) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field ENABLE (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE      13
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field RSVD1 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RSVD1      14
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RSVD1      0x7fffc000

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK      31
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528 - Analog 528MHz PLL Control Register (RW)
 *
 * The control register provides control for the 528MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 1; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RSVD0 : 6; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog Debug bit.
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RSVD1 : 12; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_528_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_528 register
 */
#define HW_CCM_ANALOG_PLL_528_ADDR      (REGS_CCM_ANALOG_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_528           (*(volatile hw_ccm_analog_pll_528_t *) HW_CCM_ANALOG_PLL_528_ADDR)
#define HW_CCM_ANALOG_PLL_528_RD()      (HW_CCM_ANALOG_PLL_528.U)
#define HW_CCM_ANALOG_PLL_528_WR(v)     (HW_CCM_ANALOG_PLL_528.U = (v))
#define HW_CCM_ANALOG_PLL_528_SET(v)    (HW_CCM_ANALOG_PLL_528_WR(HW_CCM_ANALOG_PLL_528_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_528_CLR(v)    (HW_CCM_ANALOG_PLL_528_WR(HW_CCM_ANALOG_PLL_528_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_528_TOG(v)    (HW_CCM_ANALOG_PLL_528_WR(HW_CCM_ANALOG_PLL_528_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_528 bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_528, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_PLL_528_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_528_DIV_SELECT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_528_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_528_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_528_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_528_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_528, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_528_RSVD0      1
#define BM_CCM_ANALOG_PLL_528_RSVD0      0x0000007e

/* --- Register HW_CCM_ANALOG_PLL_528, field HALF_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_HALF_LF      7
#define BM_CCM_ANALOG_PLL_528_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_528_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_528_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_528_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_528, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_528_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_528_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_528_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_528_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_528, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field HALF_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_HALF_CP      9
#define BM_CCM_ANALOG_PLL_528_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_528_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_528_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_528_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_528, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_528_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_528_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_528_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_528_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_528, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field HOLD_RING_OFF (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_528_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_528_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_528_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_528_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_528_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_528_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_528, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_528_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_528_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_528_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_528_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_528_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_528_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_528, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field ENABLE (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_528_ENABLE      13
#define BM_CCM_ANALOG_PLL_528_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_528_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_528_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_528_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_528_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_528, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_528, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_528, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_528_BYPASS      16
#define BM_CCM_ANALOG_PLL_528_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_528_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_528_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_528_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_528_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_528, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_528_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_528_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_528_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_528_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_528_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_528_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_528, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field RSVD1 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_528_RSVD1      19
#define BM_CCM_ANALOG_PLL_528_RSVD1      0x7ff80000

/* --- Register HW_CCM_ANALOG_PLL_528, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_528_LOCK      31
#define BM_CCM_ANALOG_PLL_528_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_SS - 528MHz PLL Spread Spectrum Register. (RW)
 *
 * This register contains the 528 PLL spread spectrum controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned STEP : 15; //!< frequency change step = step/B*24MHz.
        unsigned ENABLE : 1; //!< This bit enables the spread spectrum modulation.
        unsigned STOP : 16; //!< Frequency change = stop/B*24MHz.
    } B;
} hw_ccm_analog_pll_528_ss_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_528_SS register
 */
#define HW_CCM_ANALOG_PLL_528_SS_ADDR      (REGS_CCM_ANALOG_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_528_SS           (*(volatile hw_ccm_analog_pll_528_ss_t *) HW_CCM_ANALOG_PLL_528_SS_ADDR)
#define HW_CCM_ANALOG_PLL_528_SS_RD()      (HW_CCM_ANALOG_PLL_528_SS.U)
#define HW_CCM_ANALOG_PLL_528_SS_WR(v)     (HW_CCM_ANALOG_PLL_528_SS.U = (v))
#define HW_CCM_ANALOG_PLL_528_SS_SET(v)    (HW_CCM_ANALOG_PLL_528_SS_WR(HW_CCM_ANALOG_PLL_528_SS_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_528_SS_CLR(v)    (HW_CCM_ANALOG_PLL_528_SS_WR(HW_CCM_ANALOG_PLL_528_SS_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_528_SS_TOG(v)    (HW_CCM_ANALOG_PLL_528_SS_WR(HW_CCM_ANALOG_PLL_528_SS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_528_SS bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_528_SS, field STEP (RW)
 *
 * frequency change step = step/B*24MHz.
 */

#define BP_CCM_ANALOG_PLL_528_SS_STEP      0
#define BM_CCM_ANALOG_PLL_528_SS_STEP      0x00007fff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SS_STEP(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_528_SS_STEP)
#else
#define BF_CCM_ANALOG_PLL_528_SS_STEP(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_528_SS_STEP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STEP field to a new value.
#define BW_CCM_ANALOG_PLL_528_SS_STEP(v)   BF_CS1(CCM_ANALOG_PLL_528_SS, STEP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SS, field ENABLE (RW)
 *
 * This bit enables the spread spectrum modulation.
 */

#define BP_CCM_ANALOG_PLL_528_SS_ENABLE      15
#define BM_CCM_ANALOG_PLL_528_SS_ENABLE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SS_ENABLE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PLL_528_SS_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_528_SS_ENABLE(v)   (((v) << 15) & BM_CCM_ANALOG_PLL_528_SS_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_528_SS_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_528_SS, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SS, field STOP (RW)
 *
 * Frequency change = stop/B*24MHz.
 */

#define BP_CCM_ANALOG_PLL_528_SS_STOP      16
#define BM_CCM_ANALOG_PLL_528_SS_STOP      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SS_STOP(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_528_SS_STOP)
#else
#define BF_CCM_ANALOG_PLL_528_SS_STOP(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_528_SS_STOP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STOP field to a new value.
#define BW_CCM_ANALOG_PLL_528_SS_STOP(v)   BF_CS1(CCM_ANALOG_PLL_528_SS, STOP, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_NUM - Numerator of 528MHz PLL Fractional Loop Divider Register (RW)
 *
 * This register contains the numerator of 528MHz PLL fractional loop divider(Signed number).
 * Absoulte value should be less than denominator
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned A : 30; //!< 30 bit numerator (A) of fractional loop divider (signed integer).
        unsigned RSVD0 : 2; //!< Always set to zero (0).
    } B;
} hw_ccm_analog_pll_528_num_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_528_NUM register
 */
#define HW_CCM_ANALOG_PLL_528_NUM_ADDR      (REGS_CCM_ANALOG_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_528_NUM           (*(volatile hw_ccm_analog_pll_528_num_t *) HW_CCM_ANALOG_PLL_528_NUM_ADDR)
#define HW_CCM_ANALOG_PLL_528_NUM_RD()      (HW_CCM_ANALOG_PLL_528_NUM.U)
#define HW_CCM_ANALOG_PLL_528_NUM_WR(v)     (HW_CCM_ANALOG_PLL_528_NUM.U = (v))
#define HW_CCM_ANALOG_PLL_528_NUM_SET(v)    (HW_CCM_ANALOG_PLL_528_NUM_WR(HW_CCM_ANALOG_PLL_528_NUM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_528_NUM_CLR(v)    (HW_CCM_ANALOG_PLL_528_NUM_WR(HW_CCM_ANALOG_PLL_528_NUM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_528_NUM_TOG(v)    (HW_CCM_ANALOG_PLL_528_NUM_WR(HW_CCM_ANALOG_PLL_528_NUM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_528_NUM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_528_NUM, field A (RW)
 *
 * 30 bit numerator (A) of fractional loop divider (signed integer).
 */

#define BP_CCM_ANALOG_PLL_528_NUM_A      0
#define BM_CCM_ANALOG_PLL_528_NUM_A      0x3fffffff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_NUM_A(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_528_NUM_A)
#else
#define BF_CCM_ANALOG_PLL_528_NUM_A(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_528_NUM_A)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the A field to a new value.
#define BW_CCM_ANALOG_PLL_528_NUM_A(v)   BF_CS1(CCM_ANALOG_PLL_528_NUM, A, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_NUM, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_528_NUM_RSVD0      30
#define BM_CCM_ANALOG_PLL_528_NUM_RSVD0      0xc0000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_DENOM - Denominator of 528MHz PLL Fractional Loop Divider Register (RW)
 *
 * This register contains the Denominator of 528MHz PLL fractional loop divider.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned B : 30; //!< 30 bit Denominator (B) of fractional loop divider (unsigned integer).
        unsigned RSVD0 : 2; //!< Always set to zero (0).
    } B;
} hw_ccm_analog_pll_528_denom_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_528_DENOM register
 */
#define HW_CCM_ANALOG_PLL_528_DENOM_ADDR      (REGS_CCM_ANALOG_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_528_DENOM           (*(volatile hw_ccm_analog_pll_528_denom_t *) HW_CCM_ANALOG_PLL_528_DENOM_ADDR)
#define HW_CCM_ANALOG_PLL_528_DENOM_RD()      (HW_CCM_ANALOG_PLL_528_DENOM.U)
#define HW_CCM_ANALOG_PLL_528_DENOM_WR(v)     (HW_CCM_ANALOG_PLL_528_DENOM.U = (v))
#define HW_CCM_ANALOG_PLL_528_DENOM_SET(v)    (HW_CCM_ANALOG_PLL_528_DENOM_WR(HW_CCM_ANALOG_PLL_528_DENOM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_528_DENOM_CLR(v)    (HW_CCM_ANALOG_PLL_528_DENOM_WR(HW_CCM_ANALOG_PLL_528_DENOM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_528_DENOM_TOG(v)    (HW_CCM_ANALOG_PLL_528_DENOM_WR(HW_CCM_ANALOG_PLL_528_DENOM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_528_DENOM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_528_DENOM, field B (RW)
 *
 * 30 bit Denominator (B) of fractional loop divider (unsigned integer).
 */

#define BP_CCM_ANALOG_PLL_528_DENOM_B      0
#define BM_CCM_ANALOG_PLL_528_DENOM_B      0x3fffffff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_DENOM_B(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_528_DENOM_B)
#else
#define BF_CCM_ANALOG_PLL_528_DENOM_B(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_528_DENOM_B)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the B field to a new value.
#define BW_CCM_ANALOG_PLL_528_DENOM_B(v)   BF_CS1(CCM_ANALOG_PLL_528_DENOM, B, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_DENOM, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_528_DENOM_RSVD0      30
#define BM_CCM_ANALOG_PLL_528_DENOM_RSVD0      0xc0000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO - Analog Audio PLL control Register (RW)
 *
 * The control register provides control for the audio PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 7; //!< This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
        unsigned HALF_LF : 1; //!< Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale.
        unsigned HALF_CP : 1; //!< Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< Analog debug Bit
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED0 : 1; //!< Revsered
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned POST_DIV_SELECT : 2; //!< These bits implement a divider after the PLL, but before the enable and bypass mux.
        unsigned SSC_EN : 1; //!< Reserved Bit
        unsigned RSVD0 : 9; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_audio_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_ADDR      (REGS_CCM_ANALOG_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO           (*(volatile hw_ccm_analog_pll_audio_t *) HW_CCM_ANALOG_PLL_AUDIO_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_RD()      (HW_CCM_ANALOG_PLL_AUDIO.U)
#define HW_CCM_ANALOG_PLL_AUDIO_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_SET(v)    (HW_CCM_ANALOG_PLL_AUDIO_WR(HW_CCM_ANALOG_PLL_AUDIO_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_AUDIO_CLR(v)    (HW_CCM_ANALOG_PLL_AUDIO_WR(HW_CCM_ANALOG_PLL_AUDIO_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_AUDIO_TOG(v)    (HW_CCM_ANALOG_PLL_AUDIO_WR(HW_CCM_ANALOG_PLL_AUDIO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HALF_LF      7
#define BM_CCM_ANALOG_PLL_AUDIO_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_AUDIO_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_AUDIO_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HALF_CP      9
#define BM_CCM_ANALOG_PLL_AUDIO_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_AUDIO_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_AUDIO_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HOLD_RING_OFF (RW)
 *
 * Analog debug Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field ENABLE (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_AUDIO_ENABLE      13
#define BM_CCM_ANALOG_PLL_AUDIO_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_AUDIO_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_AUDIO_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_BYPASS      16
#define BM_CCM_ANALOG_PLL_AUDIO_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field POST_DIV_SELECT (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT      19
#define BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field SSC_EN (RW)
 *
 * Reserved Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SSC_EN      21
#define BM_CCM_ANALOG_PLL_AUDIO_SSC_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SSC_EN(v)   ((((reg32_t) v) << 21) & BM_CCM_ANALOG_PLL_AUDIO_SSC_EN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SSC_EN(v)   (((v) << 21) & BM_CCM_ANALOG_PLL_AUDIO_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_AUDIO_RSVD0      22
#define BM_CCM_ANALOG_PLL_AUDIO_RSVD0      0x7fc00000

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_LOCK      31
#define BM_CCM_ANALOG_PLL_AUDIO_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_NUM - Numerator of Audio PLL Fractional Loop Divider Register (RW)
 *
 * This register contains the numerator (A) of Audio PLL fractional loop divider.(Signed number),
 * absolute value should be less than denominator  Absolute value should be less than denominator
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned A : 30; //!< 30 bit numerator of fractional loop divider.
        unsigned RSVD0 : 2; //!< Always set to zero (0).
    } B;
} hw_ccm_analog_pll_audio_num_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO_NUM register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_ADDR      (REGS_CCM_ANALOG_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO_NUM           (*(volatile hw_ccm_analog_pll_audio_num_t *) HW_CCM_ANALOG_PLL_AUDIO_NUM_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_RD()      (HW_CCM_ANALOG_PLL_AUDIO_NUM.U)
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO_NUM.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_SET(v)    (HW_CCM_ANALOG_PLL_AUDIO_NUM_WR(HW_CCM_ANALOG_PLL_AUDIO_NUM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_CLR(v)    (HW_CCM_ANALOG_PLL_AUDIO_NUM_WR(HW_CCM_ANALOG_PLL_AUDIO_NUM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_TOG(v)    (HW_CCM_ANALOG_PLL_AUDIO_NUM_WR(HW_CCM_ANALOG_PLL_AUDIO_NUM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO_NUM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_NUM, field A (RW)
 *
 * 30 bit numerator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_NUM_A      0
#define BM_CCM_ANALOG_PLL_AUDIO_NUM_A      0x3fffffff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_NUM_A(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_NUM_A)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_NUM_A(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_NUM_A)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the A field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_NUM_A(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_NUM, A, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_NUM, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_AUDIO_NUM_RSVD0      30
#define BM_CCM_ANALOG_PLL_AUDIO_NUM_RSVD0      0xc0000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_DENOM - Denominator of Audio PLL Fractional Loop Divider Register (RW)
 *
 * This register contains the Denominator (B) of Audio PLL fractional loop divider.(unsigned number)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned B : 30; //!< 30 bit Denominator of fractional loop divider.
        unsigned RSVD0 : 2; //!< Always set to zero (0).
    } B;
} hw_ccm_analog_pll_audio_denom_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO_DENOM register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_ADDR      (REGS_CCM_ANALOG_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM           (*(volatile hw_ccm_analog_pll_audio_denom_t *) HW_CCM_ANALOG_PLL_AUDIO_DENOM_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD()      (HW_CCM_ANALOG_PLL_AUDIO_DENOM.U)
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO_DENOM.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_SET(v)    (HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR(HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_CLR(v)    (HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR(HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_TOG(v)    (HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR(HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO_DENOM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_DENOM, field B (RW)
 *
 * 30 bit Denominator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DENOM_B      0
#define BM_CCM_ANALOG_PLL_AUDIO_DENOM_B      0x3fffffff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_DENOM_B)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_DENOM_B)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the B field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_DENOM, B, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_DENOM, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DENOM_RSVD0      30
#define BM_CCM_ANALOG_PLL_AUDIO_DENOM_RSVD0      0xc0000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO - Analog Video PLL control Register (RW)
 *
 * The control register provides control for the Video PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 7; //!< This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
        unsigned HALF_LF : 1; //!< Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale.
        unsigned HALF_CP : 1; //!< Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< Analog Debug bit.
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enalbe PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned POST_DIV_SELECT : 2; //!< These bits implement a divider after the PLL, but before the enable and bypass mux.
        unsigned SSC_EN : 1; //!< Revserved BIt
        unsigned RSVD0 : 9; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_video_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_ADDR      (REGS_CCM_ANALOG_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO           (*(volatile hw_ccm_analog_pll_video_t *) HW_CCM_ANALOG_PLL_VIDEO_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_RD()      (HW_CCM_ANALOG_PLL_VIDEO.U)
#define HW_CCM_ANALOG_PLL_VIDEO_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_SET(v)    (HW_CCM_ANALOG_PLL_VIDEO_WR(HW_CCM_ANALOG_PLL_VIDEO_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_VIDEO_CLR(v)    (HW_CCM_ANALOG_PLL_VIDEO_WR(HW_CCM_ANALOG_PLL_VIDEO_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_VIDEO_TOG(v)    (HW_CCM_ANALOG_PLL_VIDEO_WR(HW_CCM_ANALOG_PLL_VIDEO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HALF_LF      7
#define BM_CCM_ANALOG_PLL_VIDEO_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_VIDEO_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_VIDEO_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HALF_CP      9
#define BM_CCM_ANALOG_PLL_VIDEO_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_VIDEO_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_VIDEO_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HOLD_RING_OFF (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field ENABLE (RW)
 *
 * Enalbe PLL output
 */

#define BP_CCM_ANALOG_PLL_VIDEO_ENABLE      13
#define BM_CCM_ANALOG_PLL_VIDEO_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_VIDEO_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_VIDEO_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_BYPASS      16
#define BM_CCM_ANALOG_PLL_VIDEO_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field POST_DIV_SELECT (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT      19
#define BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field SSC_EN (RW)
 *
 * Revserved BIt
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SSC_EN      21
#define BM_CCM_ANALOG_PLL_VIDEO_SSC_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SSC_EN(v)   ((((reg32_t) v) << 21) & BM_CCM_ANALOG_PLL_VIDEO_SSC_EN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SSC_EN(v)   (((v) << 21) & BM_CCM_ANALOG_PLL_VIDEO_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_VIDEO_RSVD0      22
#define BM_CCM_ANALOG_PLL_VIDEO_RSVD0      0x7fc00000

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_LOCK      31
#define BM_CCM_ANALOG_PLL_VIDEO_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_NUM - Numerator of Video PLL Fractional Loop Divider Register (RW)
 *
 * This register contains the numerator (A) of Video PLL fractional loop divider.(Signed number)
 * Absolute value should be less than denominator
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned A : 30; //!< 30 bit numerator of fractional loop divider(Signed number), absolute value should be less than denominator
        unsigned RSVD0 : 2; //!< Always set to zero (0).
    } B;
} hw_ccm_analog_pll_video_num_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO_NUM register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_ADDR      (REGS_CCM_ANALOG_BASE + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO_NUM           (*(volatile hw_ccm_analog_pll_video_num_t *) HW_CCM_ANALOG_PLL_VIDEO_NUM_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_RD()      (HW_CCM_ANALOG_PLL_VIDEO_NUM.U)
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO_NUM.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_SET(v)    (HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(HW_CCM_ANALOG_PLL_VIDEO_NUM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_CLR(v)    (HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(HW_CCM_ANALOG_PLL_VIDEO_NUM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_TOG(v)    (HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(HW_CCM_ANALOG_PLL_VIDEO_NUM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO_NUM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_NUM, field A (RW)
 *
 * 30 bit numerator of fractional loop divider(Signed number), absolute value should be less than
 * denominator
 */

#define BP_CCM_ANALOG_PLL_VIDEO_NUM_A      0
#define BM_CCM_ANALOG_PLL_VIDEO_NUM_A      0x3fffffff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_NUM_A(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_NUM_A)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_NUM_A(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_NUM_A)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the A field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_NUM_A(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_NUM, A, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_NUM, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_VIDEO_NUM_RSVD0      30
#define BM_CCM_ANALOG_PLL_VIDEO_NUM_RSVD0      0xc0000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_DENOM - Denominator of Video PLL Fractional Loop Divider Register (RW)
 *
 * This register contains the Denominator (B) of Video PLL fractional loop divider.(Unsigned number)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned B : 30; //!< 30 bit Denominator of fractional loop divider.
        unsigned RSVD0 : 2; //!< Always set to zero (0).
    } B;
} hw_ccm_analog_pll_video_denom_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO_DENOM register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_ADDR      (REGS_CCM_ANALOG_BASE + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM           (*(volatile hw_ccm_analog_pll_video_denom_t *) HW_CCM_ANALOG_PLL_VIDEO_DENOM_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD()      (HW_CCM_ANALOG_PLL_VIDEO_DENOM.U)
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO_DENOM.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_SET(v)    (HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_CLR(v)    (HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_TOG(v)    (HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO_DENOM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_DENOM, field B (RW)
 *
 * 30 bit Denominator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DENOM_B      0
#define BM_CCM_ANALOG_PLL_VIDEO_DENOM_B      0x3fffffff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_DENOM_B)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_DENOM_B)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the B field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_DENOM, B, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_DENOM, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DENOM_RSVD0      30
#define BM_CCM_ANALOG_PLL_VIDEO_DENOM_RSVD0      0xc0000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_MLB - MLB PLL Control Register (RW)
 *
 * This register defines the control bits for the MLB PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved.
        unsigned HOLD_RING_OFF : 1; //!< Analog debug bit.
        unsigned PHASE_SEL : 2; //!< Analog debut bit.
        unsigned RESERVED1 : 2; //!< Reserved.
        unsigned BYPASS : 1; //!< Bypass the PLL.
        unsigned VDDA_DELAY_CFG : 3; //!< Configure the phase delay of the MLB PLL by adjusting the delay line in Vddio power domain.
        unsigned VDDD_DELAY_CFG : 3; //!< Configure the phase delay of the MLB PLL by adjusting the delay line in core Vdd poser domain.
        unsigned RX_CLK_DELAY_CFG : 3; //!< Configure the phase delay of the MLB PLL RX Clock.
        unsigned MLB_FLT_RES_CFG : 3; //!< Configure the filter resistor for different divider ratio of MLB PLL.
        unsigned RESERVED2 : 2; //!< Reserved.
        unsigned LOCK : 1; //!< Lock bit
    } B;
} hw_ccm_analog_pll_mlb_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_MLB register
 */
#define HW_CCM_ANALOG_PLL_MLB_ADDR      (REGS_CCM_ANALOG_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_MLB           (*(volatile hw_ccm_analog_pll_mlb_t *) HW_CCM_ANALOG_PLL_MLB_ADDR)
#define HW_CCM_ANALOG_PLL_MLB_RD()      (HW_CCM_ANALOG_PLL_MLB.U)
#define HW_CCM_ANALOG_PLL_MLB_WR(v)     (HW_CCM_ANALOG_PLL_MLB.U = (v))
#define HW_CCM_ANALOG_PLL_MLB_SET(v)    (HW_CCM_ANALOG_PLL_MLB_WR(HW_CCM_ANALOG_PLL_MLB_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_MLB_CLR(v)    (HW_CCM_ANALOG_PLL_MLB_WR(HW_CCM_ANALOG_PLL_MLB_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_MLB_TOG(v)    (HW_CCM_ANALOG_PLL_MLB_WR(HW_CCM_ANALOG_PLL_MLB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_MLB bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_MLB, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_MLB, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field PHASE_SEL (RW)
 *
 * Analog debut bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_PHASE_SEL      12
#define BM_CCM_ANALOG_PLL_MLB_PHASE_SEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_PHASE_SEL(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_MLB_PHASE_SEL)
#else
#define BF_CCM_ANALOG_PLL_MLB_PHASE_SEL(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_MLB_PHASE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHASE_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_PHASE_SEL(v)   BF_CS1(CCM_ANALOG_PLL_MLB, PHASE_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field BYPASS (RW)
 *
 * Bypass the PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_BYPASS      16
#define BM_CCM_ANALOG_PLL_MLB_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_MLB_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_MLB_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_MLB_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_MLB, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field VDDA_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in Vddio power domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG      17
#define BM_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG      0x000e0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG(v)   ((((reg32_t) v) << 17) & BM_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG(v)   (((v) << 17) & BM_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDA_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB, VDDA_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field VDDD_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in core Vdd poser domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG      20
#define BM_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG(v)   ((((reg32_t) v) << 20) & BM_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG(v)   (((v) << 20) & BM_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDD_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB, VDDD_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field RX_CLK_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL RX Clock.
 */

#define BP_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG      23
#define BM_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG(v)   (((v) << 23) & BM_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CLK_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB, RX_CLK_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field MLB_FLT_RES_CFG (RW)
 *
 * Configure the filter resistor for different divider ratio of MLB PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG      26
#define BM_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG(v)   ((((reg32_t) v) << 26) & BM_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG(v)   (((v) << 26) & BM_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MLB_FLT_RES_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB, MLB_FLT_RES_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field LOCK (RO)
 *
 * Lock bit
 *
 * Values:
 * 0 - PLL is not currently locked
 * 1 - PLL is currently locked.
 */

#define BP_CCM_ANALOG_PLL_MLB_LOCK      31
#define BM_CCM_ANALOG_PLL_MLB_LOCK      0x80000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_ENET - Analog ENET PLL Control Register (RW)
 *
 * The control register provides control for the ENET PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz respectively.
        unsigned RSVD0 : 5; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog debug bit
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable the ethernet clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_PCIE : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_SATA : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RSVD1 : 10; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_enet_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_ENET register
 */
#define HW_CCM_ANALOG_PLL_ENET_ADDR      (REGS_CCM_ANALOG_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_ENET           (*(volatile hw_ccm_analog_pll_enet_t *) HW_CCM_ANALOG_PLL_ENET_ADDR)
#define HW_CCM_ANALOG_PLL_ENET_RD()      (HW_CCM_ANALOG_PLL_ENET.U)
#define HW_CCM_ANALOG_PLL_ENET_WR(v)     (HW_CCM_ANALOG_PLL_ENET.U = (v))
#define HW_CCM_ANALOG_PLL_ENET_SET(v)    (HW_CCM_ANALOG_PLL_ENET_WR(HW_CCM_ANALOG_PLL_ENET_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_ENET_CLR(v)    (HW_CCM_ANALOG_PLL_ENET_WR(HW_CCM_ANALOG_PLL_ENET_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_ENET_TOG(v)    (HW_CCM_ANALOG_PLL_ENET_WR(HW_CCM_ANALOG_PLL_ENET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_ENET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DIV_SELECT (RW)
 *
 * Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not
 * 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz
 * respectively.
 */

#define BP_CCM_ANALOG_PLL_ENET_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_ENET_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_ENET_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_ENET_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_ENET_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field RSVD0 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_ENET_RSVD0      2
#define BM_CCM_ANALOG_PLL_ENET_RSVD0      0x0000007c

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HALF_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_HALF_LF      7
#define BM_CCM_ANALOG_PLL_ENET_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_ENET_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_ENET_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_ENET_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HALF_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_HALF_CP      9
#define BM_CCM_ANALOG_PLL_ENET_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_ENET_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_ENET_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_ENET_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit
 */

#define BP_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_ENET_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_ENET_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_ENET_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_ENET_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_ENET_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_ENET, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE (RW)
 *
 * Enable the ethernet clock output.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE      13
#define BM_CCM_ANALOG_PLL_ENET_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_ENET_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_ENET_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_ENET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_ENET, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_ENET, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_ENET_BYPASS      16
#define BM_CCM_ANALOG_PLL_ENET_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_ENET_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_ENET_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_ENET_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_ENET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_ENET, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE_PCIE (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE_PCIE      19
#define BM_CCM_ANALOG_PLL_ENET_ENABLE_PCIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_PCIE(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_ENET_ENABLE_PCIE)
#else
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_PCIE(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_ENET_ENABLE_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PCIE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE_PCIE(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE_PCIE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE_SATA (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE_SATA      20
#define BM_CCM_ANALOG_PLL_ENET_ENABLE_SATA      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_SATA(v)   ((((reg32_t) v) << 20) & BM_CCM_ANALOG_PLL_ENET_ENABLE_SATA)
#else
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_SATA(v)   (((v) << 20) & BM_CCM_ANALOG_PLL_ENET_ENABLE_SATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_SATA field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE_SATA(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE_SATA, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field RSVD1 (RO)
 *
 * Always set to zero (0).
 */

#define BP_CCM_ANALOG_PLL_ENET_RSVD1      21
#define BM_CCM_ANALOG_PLL_ENET_RSVD1      0x7fe00000

/* --- Register HW_CCM_ANALOG_PLL_ENET, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_ENET_LOCK      31
#define BM_CCM_ANALOG_PLL_ENET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_480 - 480MHz Clock Phase Fractional Divider Control Register (RW)
 *
 * The PFD_480 control register provides control for PFD clock generation.  This register controls
 * the 4-phase fractional clock dividers. The fractional clock frequencies are a product of the
 * values in these registers.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PFD0_FRAC : 6; //!< This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
        unsigned PFD0_STABLE : 1; //!< This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD0_CLKGATE : 1; //!< If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0: ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD1_FRAC : 6; //!< This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
        unsigned PFD1_STABLE : 1; //!< This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD1_CLKGATE : 1; //!< IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD2_FRAC : 6; //!< This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
        unsigned PFD2_STABLE : 1; //!< This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD2_CLKGATE : 1; //!< IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD3_FRAC : 6; //!< This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
        unsigned PFD3_STABLE : 1; //!< This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD3_CLKGATE : 1; //!< IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
    } B;
} hw_ccm_analog_pfd_480_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_480 register
 */
#define HW_CCM_ANALOG_PFD_480_ADDR      (REGS_CCM_ANALOG_BASE + 0xf0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_480           (*(volatile hw_ccm_analog_pfd_480_t *) HW_CCM_ANALOG_PFD_480_ADDR)
#define HW_CCM_ANALOG_PFD_480_RD()      (HW_CCM_ANALOG_PFD_480.U)
#define HW_CCM_ANALOG_PFD_480_WR(v)     (HW_CCM_ANALOG_PFD_480.U = (v))
#define HW_CCM_ANALOG_PFD_480_SET(v)    (HW_CCM_ANALOG_PFD_480_WR(HW_CCM_ANALOG_PFD_480_RD() |  (v)))
#define HW_CCM_ANALOG_PFD_480_CLR(v)    (HW_CCM_ANALOG_PFD_480_WR(HW_CCM_ANALOG_PFD_480_RD() & ~(v)))
#define HW_CCM_ANALOG_PFD_480_TOG(v)    (HW_CCM_ANALOG_PFD_480_WR(HW_CCM_ANALOG_PFD_480_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_480 bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_FRAC      0
#define BM_CCM_ANALOG_PFD_480_PFD0_FRAC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_PFD0_FRAC(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PFD_480_PFD0_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_PFD0_FRAC(v)   (((v) << 0) & BM_CCM_ANALOG_PFD_480_PFD0_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_STABLE      6
#define BM_CCM_ANALOG_PFD_480_PFD0_STABLE      0x00000040

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_CLKGATE (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_CLKGATE      7
#define BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_PFD0_CLKGATE(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_PFD0_CLKGATE(v)   (((v) << 7) & BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_FRAC      8
#define BM_CCM_ANALOG_PFD_480_PFD1_FRAC      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_PFD1_FRAC(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PFD_480_PFD1_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_PFD1_FRAC(v)   (((v) << 8) & BM_CCM_ANALOG_PFD_480_PFD1_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_STABLE      14
#define BM_CCM_ANALOG_PFD_480_PFD1_STABLE      0x00004000

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_CLKGATE      15
#define BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_PFD1_CLKGATE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_PFD1_CLKGATE(v)   (((v) << 15) & BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_FRAC      16
#define BM_CCM_ANALOG_PFD_480_PFD2_FRAC      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_PFD2_FRAC(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PFD_480_PFD2_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_PFD2_FRAC(v)   (((v) << 16) & BM_CCM_ANALOG_PFD_480_PFD2_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_STABLE      22
#define BM_CCM_ANALOG_PFD_480_PFD2_STABLE      0x00400000

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_CLKGATE      23
#define BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_PFD2_CLKGATE(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_PFD2_CLKGATE(v)   (((v) << 23) & BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_FRAC      24
#define BM_CCM_ANALOG_PFD_480_PFD3_FRAC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_PFD3_FRAC(v)   ((((reg32_t) v) << 24) & BM_CCM_ANALOG_PFD_480_PFD3_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_PFD3_FRAC(v)   (((v) << 24) & BM_CCM_ANALOG_PFD_480_PFD3_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_STABLE      30
#define BM_CCM_ANALOG_PFD_480_PFD3_STABLE      0x40000000

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_CLKGATE      31
#define BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_PFD3_CLKGATE(v)   ((((reg32_t) v) << 31) & BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_PFD3_CLKGATE(v)   (((v) << 31) & BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD3_CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_528 - 528MHz Clock Phase Fractional Divider Control Register (RW)
 *
 * The PFD_528 control register provides control for PFD clock generation.  This register controls
 * the 4-phase fractional clock dividers. The fractional clock frequencies are a product of the
 * values in these registers.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PFD0_FRAC : 6; //!< This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
        unsigned PFD0_STABLE : 1; //!< This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD0_CLKGATE : 1; //!< If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0: ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD1_FRAC : 6; //!< This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
        unsigned PFD1_STABLE : 1; //!< This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD1_CLKGATE : 1; //!< IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD2_FRAC : 6; //!< This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
        unsigned PFD2_STABLE : 1; //!< This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD2_CLKGATE : 1; //!< IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD3_FRAC : 6; //!< This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
        unsigned PFD3_STABLE : 1; //!< This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD3_CLKGATE : 1; //!< IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL powered down
    } B;
} hw_ccm_analog_pfd_528_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_528 register
 */
#define HW_CCM_ANALOG_PFD_528_ADDR      (REGS_CCM_ANALOG_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_528           (*(volatile hw_ccm_analog_pfd_528_t *) HW_CCM_ANALOG_PFD_528_ADDR)
#define HW_CCM_ANALOG_PFD_528_RD()      (HW_CCM_ANALOG_PFD_528.U)
#define HW_CCM_ANALOG_PFD_528_WR(v)     (HW_CCM_ANALOG_PFD_528.U = (v))
#define HW_CCM_ANALOG_PFD_528_SET(v)    (HW_CCM_ANALOG_PFD_528_WR(HW_CCM_ANALOG_PFD_528_RD() |  (v)))
#define HW_CCM_ANALOG_PFD_528_CLR(v)    (HW_CCM_ANALOG_PFD_528_WR(HW_CCM_ANALOG_PFD_528_RD() & ~(v)))
#define HW_CCM_ANALOG_PFD_528_TOG(v)    (HW_CCM_ANALOG_PFD_528_WR(HW_CCM_ANALOG_PFD_528_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_528 bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_FRAC      0
#define BM_CCM_ANALOG_PFD_528_PFD0_FRAC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_PFD0_FRAC(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PFD_528_PFD0_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_PFD0_FRAC(v)   (((v) << 0) & BM_CCM_ANALOG_PFD_528_PFD0_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_STABLE      6
#define BM_CCM_ANALOG_PFD_528_PFD0_STABLE      0x00000040

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_CLKGATE (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_CLKGATE      7
#define BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_PFD0_CLKGATE(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_PFD0_CLKGATE(v)   (((v) << 7) & BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_FRAC      8
#define BM_CCM_ANALOG_PFD_528_PFD1_FRAC      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_PFD1_FRAC(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PFD_528_PFD1_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_PFD1_FRAC(v)   (((v) << 8) & BM_CCM_ANALOG_PFD_528_PFD1_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_STABLE      14
#define BM_CCM_ANALOG_PFD_528_PFD1_STABLE      0x00004000

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_CLKGATE      15
#define BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_PFD1_CLKGATE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_PFD1_CLKGATE(v)   (((v) << 15) & BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_FRAC      16
#define BM_CCM_ANALOG_PFD_528_PFD2_FRAC      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_PFD2_FRAC(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PFD_528_PFD2_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_PFD2_FRAC(v)   (((v) << 16) & BM_CCM_ANALOG_PFD_528_PFD2_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_STABLE      22
#define BM_CCM_ANALOG_PFD_528_PFD2_STABLE      0x00400000

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_CLKGATE      23
#define BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_PFD2_CLKGATE(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_PFD2_CLKGATE(v)   (((v) << 23) & BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_FRAC      24
#define BM_CCM_ANALOG_PFD_528_PFD3_FRAC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_PFD3_FRAC(v)   ((((reg32_t) v) << 24) & BM_CCM_ANALOG_PFD_528_PFD3_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_PFD3_FRAC(v)   (((v) << 24) & BM_CCM_ANALOG_PFD_528_PFD3_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_STABLE      30
#define BM_CCM_ANALOG_PFD_528_PFD3_STABLE      0x40000000

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_CLKGATE      31
#define BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_PFD3_CLKGATE(v)   ((((reg32_t) v) << 31) & BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_PFD3_CLKGATE(v)   (((v) << 31) & BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD3_CLKGATE, v)
#endif


/*!
 * @brief All CCM_ANALOG module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_ccm_analog_pll_sys_t PLL_SYS; //!< Analog System PLL control Register
    reg32_t _reserved0[3];
    volatile hw_ccm_analog_usbphy0_pll_480_ctrl_t USBPHY0_PLL_480_CTRL; //!< Analog USBPHY0 480MHz PLL Control Register
    reg32_t _reserved1[3];
    volatile hw_ccm_analog_usbphy1_pll_480_ctrl_t USBPHY1_PLL_480_CTRL; //!< Analog USBPHY1 480MHz PLL Control Register
    reg32_t _reserved2[3];
    volatile hw_ccm_analog_pll_528_t PLL_528; //!< Analog 528MHz PLL Control Register
    reg32_t _reserved3[3];
    volatile hw_ccm_analog_pll_528_ss_t PLL_528_SS; //!< 528MHz PLL Spread Spectrum Register.
    reg32_t _reserved4[3];
    volatile hw_ccm_analog_pll_528_num_t PLL_528_NUM; //!< Numerator of 528MHz PLL Fractional Loop Divider Register
    reg32_t _reserved5[3];
    volatile hw_ccm_analog_pll_528_denom_t PLL_528_DENOM; //!< Denominator of 528MHz PLL Fractional Loop Divider Register
    reg32_t _reserved6[3];
    volatile hw_ccm_analog_pll_audio_t PLL_AUDIO; //!< Analog Audio PLL control Register
    reg32_t _reserved7[3];
    volatile hw_ccm_analog_pll_audio_num_t PLL_AUDIO_NUM; //!< Numerator of Audio PLL Fractional Loop Divider Register
    reg32_t _reserved8[3];
    volatile hw_ccm_analog_pll_audio_denom_t PLL_AUDIO_DENOM; //!< Denominator of Audio PLL Fractional Loop Divider Register
    reg32_t _reserved9[3];
    volatile hw_ccm_analog_pll_video_t PLL_VIDEO; //!< Analog Video PLL control Register
    reg32_t _reserved10[3];
    volatile hw_ccm_analog_pll_video_num_t PLL_VIDEO_NUM; //!< Numerator of Video PLL Fractional Loop Divider Register
    reg32_t _reserved11[3];
    volatile hw_ccm_analog_pll_video_denom_t PLL_VIDEO_DENOM; //!< Denominator of Video PLL Fractional Loop Divider Register
    reg32_t _reserved12[3];
    volatile hw_ccm_analog_pll_mlb_t PLL_MLB; //!< MLB PLL Control Register
    reg32_t _reserved13[3];
    volatile hw_ccm_analog_pll_enet_t PLL_ENET; //!< Analog ENET PLL Control Register
    reg32_t _reserved14[3];
    volatile hw_ccm_analog_pfd_480_t PFD_480; //!< 480MHz Clock Phase Fractional Divider Control Register
    reg32_t _reserved15[3];
    volatile hw_ccm_analog_pfd_528_t PFD_528; //!< 528MHz Clock Phase Fractional Divider Control Register
} hw_ccm_analog_t
#endif

//! @brief Macro to access all CCM_ANALOG registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CCM_ANALOG(0)</code>.
#define HW_CCM_ANALOG     (*(volatile hw_ccm_analog_t *) REGS_CCM_ANALOG_BASE)


#endif // _CCM_ANALOG_H
