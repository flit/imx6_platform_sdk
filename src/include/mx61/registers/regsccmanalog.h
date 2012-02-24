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
 * - HW_CCM_ANALOG_PLL_SYS_SET - Analog System PLL control Register _SET
 * - HW_CCM_ANALOG_PLL_SYS_CLR - Analog System PLL control Register _CLR
 * - HW_CCM_ANALOG_PLL_SYS_TOG - Analog System PLL control Register _TOG
 * - HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL - Analog USBPHY0 480MHz PLL Control Register
 * - HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET - Analog USBPHY0 480MHz PLL Control Register _SET
 * - HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR - Analog USBPHY0 480MHz PLL Control Register _CLR
 * - HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG - Analog USBPHY0 480MHz PLL Control Register _TOG
 * - HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL - Analog USBPHY1 480MHz PLL Control Register
 * - HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET - Analog USBPHY1 480MHz PLL Control Register _SET
 * - HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR - Analog USBPHY1 480MHz PLL Control Register _CLR
 * - HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG - Analog USBPHY1 480MHz PLL Control Register _TOG
 * - HW_CCM_ANALOG_PLL_528 - Analog 528MHz PLL Control Register
 * - HW_CCM_ANALOG_PLL_528_SET - Analog 528MHz PLL Control Register _SET
 * - HW_CCM_ANALOG_PLL_528_CLR - Analog 528MHz PLL Control Register _CLR
 * - HW_CCM_ANALOG_PLL_528_TOG - Analog 528MHz PLL Control Register _TOG
 * - HW_CCM_ANALOG_PLL_528_SS - 528MHz PLL Spread Spectrum Register.
 * - HW_CCM_ANALOG_PLL_528_NUM - Numerator of 528MHz PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_528_DENOM - Denominator of 528MHz PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_AUDIO - Analog Audio PLL control Register
 * - HW_CCM_ANALOG_PLL_AUDIO_SET - Analog Audio PLL control Register _SET
 * - HW_CCM_ANALOG_PLL_AUDIO_CLR - Analog Audio PLL control Register _CLR
 * - HW_CCM_ANALOG_PLL_AUDIO_TOG - Analog Audio PLL control Register _TOG
 * - HW_CCM_ANALOG_PLL_AUDIO_NUM - Numerator of Audio PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_AUDIO_DENOM - Denominator of Audio PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_VIDEO - Analog Video PLL control Register
 * - HW_CCM_ANALOG_PLL_VIDEO_SET - Analog Video PLL control Register _SET
 * - HW_CCM_ANALOG_PLL_VIDEO_CLR - Analog Video PLL control Register _CLR
 * - HW_CCM_ANALOG_PLL_VIDEO_TOG - Analog Video PLL control Register _TOG
 * - HW_CCM_ANALOG_PLL_VIDEO_NUM - Numerator of Video PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_VIDEO_DENOM - Denominator of Video PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_MLB - MLB PLL Control Register
 * - HW_CCM_ANALOG_PLL_MLB_SET - MLB PLL Control Register _SET
 * - HW_CCM_ANALOG_PLL_MLB_CLR - MLB PLL Control Register _CLR
 * - HW_CCM_ANALOG_PLL_MLB_TOG - MLB PLL Control Register _TOG
 * - HW_CCM_ANALOG_PLL_ENET - Analog ENET PLL Control Register
 * - HW_CCM_ANALOG_PLL_ENET_SET - Analog ENET PLL Control Register _SET
 * - HW_CCM_ANALOG_PLL_ENET_CLR - Analog ENET PLL Control Register _CLR
 * - HW_CCM_ANALOG_PLL_ENET_TOG - Analog ENET PLL Control Register _TOG
 * - HW_CCM_ANALOG_PFD_480 - 480MHz Clock Phase Fractional Divider Control Register
 * - HW_CCM_ANALOG_PFD_480_SET - 480MHz Clock Phase Fractional Divider Control Register _SET
 * - HW_CCM_ANALOG_PFD_480_CLR - 480MHz Clock Phase Fractional Divider Control Register _CLR
 * - HW_CCM_ANALOG_PFD_480_TOG - 480MHz Clock Phase Fractional Divider Control Register _TOG
 * - HW_CCM_ANALOG_PFD_528 - 528MHz Clock Phase Fractional Divider Control Register
 * - HW_CCM_ANALOG_PFD_528_SET - 528MHz Clock Phase Fractional Divider Control Register _SET
 * - HW_CCM_ANALOG_PFD_528_CLR - 528MHz Clock Phase Fractional Divider Control Register _CLR
 * - HW_CCM_ANALOG_PFD_528_TOG - 528MHz Clock Phase Fractional Divider Control Register _TOG
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
        unsigned RESERVED0 : 11; //!< Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_SYS, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_SYS_LOCK      31
#define BM_CCM_ANALOG_PLL_SYS_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_SYS_SET - Analog System PLL control Register _SET (RW)
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
        unsigned RESERVED0 : 11; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_sys_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_SYS_SET register
 */
#define HW_CCM_ANALOG_PLL_SYS_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_SYS_SET           (*(volatile hw_ccm_analog_pll_sys_set_t *) HW_CCM_ANALOG_PLL_SYS_SET_ADDR)
#define HW_CCM_ANALOG_PLL_SYS_SET_RD()      (HW_CCM_ANALOG_PLL_SYS_SET.U)
#define HW_CCM_ANALOG_PLL_SYS_SET_WR(v)     (HW_CCM_ANALOG_PLL_SYS_SET.U = (v))
#define HW_CCM_ANALOG_PLL_SYS_SET_SET(v)    (HW_CCM_ANALOG_PLL_SYS_SET_WR(HW_CCM_ANALOG_PLL_SYS_SET_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_SYS_SET_CLR(v)    (HW_CCM_ANALOG_PLL_SYS_SET_WR(HW_CCM_ANALOG_PLL_SYS_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_SYS_SET_TOG(v)    (HW_CCM_ANALOG_PLL_SYS_SET_WR(HW_CCM_ANALOG_PLL_SYS_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_SYS_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin *
 * div_select/2.0.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_SYS_SET_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_SYS_SET_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_SYS_SET_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_HALF_LF      7
#define BM_CCM_ANALOG_PLL_SYS_SET_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_SYS_SET_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_SYS_SET_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_SYS_SET_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_SYS_SET_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_SYS_SET_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_HALF_CP      9
#define BM_CCM_ANALOG_PLL_SYS_SET_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_SYS_SET_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_SYS_SET_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_SYS_SET_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_SYS_SET_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_SYS_SET_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_SYS_SET_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_SYS_SET_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_SYS_SET_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_SYS_SET_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_SYS_SET_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_SYS_SET_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field ENABLE (RW)
 *
 * Enable the clock output.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_ENABLE      13
#define BM_CCM_ANALOG_PLL_SYS_SET_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_SYS_SET_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_SYS_SET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_BYPASS      16
#define BM_CCM_ANALOG_PLL_SYS_SET_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_SYS_SET_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_SYS_SET_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field LVDS_SEL (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_LVDS_SEL      17
#define BM_CCM_ANALOG_PLL_SYS_SET_LVDS_SEL      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_LVDS_SEL(v)   ((((reg32_t) v) << 17) & BM_CCM_ANALOG_PLL_SYS_SET_LVDS_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_LVDS_SEL(v)   (((v) << 17) & BM_CCM_ANALOG_PLL_SYS_SET_LVDS_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_LVDS_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, LVDS_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field LVDS_24MHZ_SEL (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_LVDS_24MHZ_SEL      18
#define BM_CCM_ANALOG_PLL_SYS_SET_LVDS_24MHZ_SEL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_LVDS_24MHZ_SEL(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_SYS_SET_LVDS_24MHZ_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_LVDS_24MHZ_SEL(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_SYS_SET_LVDS_24MHZ_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_24MHZ_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_LVDS_24MHZ_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, LVDS_24MHZ_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field PLL_SEL (RW)
 *
 * Reserved
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_PLL_SEL      19
#define BM_CCM_ANALOG_PLL_SYS_SET_PLL_SEL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_SET_PLL_SEL(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_SYS_SET_PLL_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_SET_PLL_SEL(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_SYS_SET_PLL_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_SET_PLL_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_SET, PLL_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_SET, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_SYS_SET_LOCK      31
#define BM_CCM_ANALOG_PLL_SYS_SET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_SYS_CLR - Analog System PLL control Register _CLR (RW)
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
        unsigned RESERVED0 : 11; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_sys_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_SYS_CLR register
 */
#define HW_CCM_ANALOG_PLL_SYS_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_SYS_CLR           (*(volatile hw_ccm_analog_pll_sys_clr_t *) HW_CCM_ANALOG_PLL_SYS_CLR_ADDR)
#define HW_CCM_ANALOG_PLL_SYS_CLR_RD()      (HW_CCM_ANALOG_PLL_SYS_CLR.U)
#define HW_CCM_ANALOG_PLL_SYS_CLR_WR(v)     (HW_CCM_ANALOG_PLL_SYS_CLR.U = (v))
#define HW_CCM_ANALOG_PLL_SYS_CLR_SET(v)    (HW_CCM_ANALOG_PLL_SYS_CLR_WR(HW_CCM_ANALOG_PLL_SYS_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_SYS_CLR_CLR(v)    (HW_CCM_ANALOG_PLL_SYS_CLR_WR(HW_CCM_ANALOG_PLL_SYS_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_SYS_CLR_TOG(v)    (HW_CCM_ANALOG_PLL_SYS_CLR_WR(HW_CCM_ANALOG_PLL_SYS_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_SYS_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin *
 * div_select/2.0.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_HALF_LF      7
#define BM_CCM_ANALOG_PLL_SYS_CLR_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_SYS_CLR_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_SYS_CLR_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_HALF_CP      9
#define BM_CCM_ANALOG_PLL_SYS_CLR_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_SYS_CLR_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_SYS_CLR_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_SYS_CLR_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_SYS_CLR_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_SYS_CLR_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_SYS_CLR_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_SYS_CLR_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_SYS_CLR_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field ENABLE (RW)
 *
 * Enable the clock output.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_ENABLE      13
#define BM_CCM_ANALOG_PLL_SYS_CLR_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_SYS_CLR_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_SYS_CLR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_BYPASS      16
#define BM_CCM_ANALOG_PLL_SYS_CLR_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_SYS_CLR_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_SYS_CLR_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field LVDS_SEL (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_LVDS_SEL      17
#define BM_CCM_ANALOG_PLL_SYS_CLR_LVDS_SEL      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_LVDS_SEL(v)   ((((reg32_t) v) << 17) & BM_CCM_ANALOG_PLL_SYS_CLR_LVDS_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_LVDS_SEL(v)   (((v) << 17) & BM_CCM_ANALOG_PLL_SYS_CLR_LVDS_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_LVDS_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, LVDS_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field LVDS_24MHZ_SEL (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_LVDS_24MHZ_SEL      18
#define BM_CCM_ANALOG_PLL_SYS_CLR_LVDS_24MHZ_SEL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_LVDS_24MHZ_SEL(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_SYS_CLR_LVDS_24MHZ_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_LVDS_24MHZ_SEL(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_SYS_CLR_LVDS_24MHZ_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_24MHZ_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_LVDS_24MHZ_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, LVDS_24MHZ_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field PLL_SEL (RW)
 *
 * Reserved
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_PLL_SEL      19
#define BM_CCM_ANALOG_PLL_SYS_CLR_PLL_SEL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_CLR_PLL_SEL(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_SYS_CLR_PLL_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_CLR_PLL_SEL(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_SYS_CLR_PLL_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_CLR_PLL_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_CLR, PLL_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_CLR, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_SYS_CLR_LOCK      31
#define BM_CCM_ANALOG_PLL_SYS_CLR_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_SYS_TOG - Analog System PLL control Register _TOG (RW)
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
        unsigned RESERVED0 : 11; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_sys_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_SYS_TOG register
 */
#define HW_CCM_ANALOG_PLL_SYS_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_SYS_TOG           (*(volatile hw_ccm_analog_pll_sys_tog_t *) HW_CCM_ANALOG_PLL_SYS_TOG_ADDR)
#define HW_CCM_ANALOG_PLL_SYS_TOG_RD()      (HW_CCM_ANALOG_PLL_SYS_TOG.U)
#define HW_CCM_ANALOG_PLL_SYS_TOG_WR(v)     (HW_CCM_ANALOG_PLL_SYS_TOG.U = (v))
#define HW_CCM_ANALOG_PLL_SYS_TOG_SET(v)    (HW_CCM_ANALOG_PLL_SYS_TOG_WR(HW_CCM_ANALOG_PLL_SYS_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_SYS_TOG_CLR(v)    (HW_CCM_ANALOG_PLL_SYS_TOG_WR(HW_CCM_ANALOG_PLL_SYS_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_SYS_TOG_TOG(v)    (HW_CCM_ANALOG_PLL_SYS_TOG_WR(HW_CCM_ANALOG_PLL_SYS_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_SYS_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin *
 * div_select/2.0.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_HALF_LF      7
#define BM_CCM_ANALOG_PLL_SYS_TOG_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_SYS_TOG_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_SYS_TOG_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_HALF_CP      9
#define BM_CCM_ANALOG_PLL_SYS_TOG_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_SYS_TOG_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_SYS_TOG_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_SYS_TOG_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_SYS_TOG_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_SYS_TOG_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_SYS_TOG_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_SYS_TOG_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_SYS_TOG_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field ENABLE (RW)
 *
 * Enable the clock output.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_ENABLE      13
#define BM_CCM_ANALOG_PLL_SYS_TOG_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_SYS_TOG_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_SYS_TOG_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_BYPASS      16
#define BM_CCM_ANALOG_PLL_SYS_TOG_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_SYS_TOG_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_SYS_TOG_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field LVDS_SEL (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_LVDS_SEL      17
#define BM_CCM_ANALOG_PLL_SYS_TOG_LVDS_SEL      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_LVDS_SEL(v)   ((((reg32_t) v) << 17) & BM_CCM_ANALOG_PLL_SYS_TOG_LVDS_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_LVDS_SEL(v)   (((v) << 17) & BM_CCM_ANALOG_PLL_SYS_TOG_LVDS_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_LVDS_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, LVDS_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field LVDS_24MHZ_SEL (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_LVDS_24MHZ_SEL      18
#define BM_CCM_ANALOG_PLL_SYS_TOG_LVDS_24MHZ_SEL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_LVDS_24MHZ_SEL(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_SYS_TOG_LVDS_24MHZ_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_LVDS_24MHZ_SEL(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_SYS_TOG_LVDS_24MHZ_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_24MHZ_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_LVDS_24MHZ_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, LVDS_24MHZ_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field PLL_SEL (RW)
 *
 * Reserved
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_PLL_SEL      19
#define BM_CCM_ANALOG_PLL_SYS_TOG_PLL_SEL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_SYS_TOG_PLL_SEL(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_SYS_TOG_PLL_SEL)
#else
#define BF_CCM_ANALOG_PLL_SYS_TOG_PLL_SEL(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_SYS_TOG_PLL_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_TOG_PLL_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS_TOG, PLL_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS_TOG, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_SYS_TOG_LOCK      31
#define BM_CCM_ANALOG_PLL_SYS_TOG_LOCK      0x80000000

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
        unsigned RESERVED0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set automatically when USBPHYn remote wakeup event occurs.
        unsigned RESERVED1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK      31
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET - Analog USBPHY0 480MHz PLL Control Register _SET (RW)
 *
 * The control register provides control for USBPHY0 480MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set automatically when USBPHYn remote wakeup event occurs.
        unsigned RESERVED1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy0_pll_480_ctrl_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET register
 */
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET           (*(volatile hw_ccm_analog_usbphy0_pll_480_ctrl_set_t *) HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ADDR)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_RD()      (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET.U)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_WR(v)     (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET.U = (v))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_SET(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_RD() |  (v)))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_CLR(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_TOG(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_DIV_SELECT      0
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_DIV_SELECT)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, field EN_USB_CLKS (RW)
 *
 * Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted
 * in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set
 * automatically when USBPHYn remote wakeup event occurs.
 *
 * Values:
 * 0 - PLL outputs for USBPHYn off.
 * 1 - PLL outputs for USBPHYn on.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_EN_USB_CLKS      6
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_EN_USB_CLKS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_EN_USB_CLKS(v)   ((((reg32_t) v) << 6) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_EN_USB_CLKS)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_EN_USB_CLKS(v)   (((v) << 6) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, EN_USB_CLKS, v)
#endif


/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, field POWER (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_POWER      12
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_POWER      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_POWER(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_POWER)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_POWER(v)   (((v) << 12) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, field ENABLE (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ENABLE      13
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ENABLE)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_LOCK      31
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR - Analog USBPHY0 480MHz PLL Control Register _CLR (RW)
 *
 * The control register provides control for USBPHY0 480MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set automatically when USBPHYn remote wakeup event occurs.
        unsigned RESERVED1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy0_pll_480_ctrl_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR register
 */
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR           (*(volatile hw_ccm_analog_usbphy0_pll_480_ctrl_clr_t *) HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ADDR)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_RD()      (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR.U)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_WR(v)     (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR.U = (v))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_SET(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_CLR(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_TOG(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_DIV_SELECT      0
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_DIV_SELECT)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, field EN_USB_CLKS (RW)
 *
 * Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted
 * in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set
 * automatically when USBPHYn remote wakeup event occurs.
 *
 * Values:
 * 0 - PLL outputs for USBPHYn off.
 * 1 - PLL outputs for USBPHYn on.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_EN_USB_CLKS      6
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_EN_USB_CLKS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_EN_USB_CLKS(v)   ((((reg32_t) v) << 6) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_EN_USB_CLKS)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_EN_USB_CLKS(v)   (((v) << 6) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, EN_USB_CLKS, v)
#endif


/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, field POWER (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_POWER      12
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_POWER      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_POWER(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_POWER)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_POWER(v)   (((v) << 12) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, field ENABLE (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ENABLE      13
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ENABLE)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_LOCK      31
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG - Analog USBPHY0 480MHz PLL Control Register _TOG (RW)
 *
 * The control register provides control for USBPHY0 480MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set automatically when USBPHYn remote wakeup event occurs.
        unsigned RESERVED1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy0_pll_480_ctrl_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG register
 */
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG           (*(volatile hw_ccm_analog_usbphy0_pll_480_ctrl_tog_t *) HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ADDR)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_RD()      (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG.U)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_WR(v)     (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG.U = (v))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_SET(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_CLR(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_TOG(v)    (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_WR(HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_DIV_SELECT      0
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_DIV_SELECT)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, field EN_USB_CLKS (RW)
 *
 * Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted
 * in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set
 * automatically when USBPHYn remote wakeup event occurs.
 *
 * Values:
 * 0 - PLL outputs for USBPHYn off.
 * 1 - PLL outputs for USBPHYn on.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_EN_USB_CLKS      6
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_EN_USB_CLKS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_EN_USB_CLKS(v)   ((((reg32_t) v) << 6) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_EN_USB_CLKS)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_EN_USB_CLKS(v)   (((v) << 6) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, EN_USB_CLKS, v)
#endif


/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, field POWER (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_POWER      12
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_POWER      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_POWER(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_POWER)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_POWER(v)   (((v) << 12) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, field ENABLE (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ENABLE      13
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ENABLE)
#else
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_LOCK      31
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_LOCK      0x80000000

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
        unsigned RESERVED0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1 are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned RESERVED1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK      31
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET - Analog USBPHY1 480MHz PLL Control Register _SET (RW)
 *
 * The control register provides control for USBPHY1 480MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1 are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned RESERVED1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy1_pll_480_ctrl_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET register
 */
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET           (*(volatile hw_ccm_analog_usbphy1_pll_480_ctrl_set_t *) HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ADDR)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_RD()      (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET.U)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_WR(v)     (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET.U = (v))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_SET(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_RD() |  (v)))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_CLR(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_TOG(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_DIV_SELECT      0
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_DIV_SELECT)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, field EN_USB_CLKS (RW)
 *
 * 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1
 * are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable
 * USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when
 * USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_EN_USB_CLKS      6
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_EN_USB_CLKS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_EN_USB_CLKS(v)   ((((reg32_t) v) << 6) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_EN_USB_CLKS)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_EN_USB_CLKS(v)   (((v) << 6) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, EN_USB_CLKS, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, field POWER (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_POWER      12
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_POWER      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_POWER(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_POWER)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_POWER(v)   (((v) << 12) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, field ENABLE (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ENABLE      13
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ENABLE)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_LOCK      31
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR - Analog USBPHY1 480MHz PLL Control Register _CLR (RW)
 *
 * The control register provides control for USBPHY1 480MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1 are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned RESERVED1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy1_pll_480_ctrl_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR register
 */
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR           (*(volatile hw_ccm_analog_usbphy1_pll_480_ctrl_clr_t *) HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ADDR)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_RD()      (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR.U)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_WR(v)     (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR.U = (v))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_SET(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_CLR(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_TOG(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_DIV_SELECT      0
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_DIV_SELECT)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, field EN_USB_CLKS (RW)
 *
 * 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1
 * are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable
 * USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when
 * USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_EN_USB_CLKS      6
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_EN_USB_CLKS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_EN_USB_CLKS(v)   ((((reg32_t) v) << 6) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_EN_USB_CLKS)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_EN_USB_CLKS(v)   (((v) << 6) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, EN_USB_CLKS, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, field POWER (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_POWER      12
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_POWER      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_POWER(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_POWER)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_POWER(v)   (((v) << 12) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, field ENABLE (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ENABLE      13
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ENABLE)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_LOCK      31
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG - Analog USBPHY1 480MHz PLL Control Register _TOG (RW)
 *
 * The control register provides control for USBPHY1 480MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1 are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned RESERVED1 : 5; //!< Always set to zero (0).
        unsigned POWER : 1; //!< Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned ENABLE : 1; //!< Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy1_pll_480_ctrl_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG register
 */
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG           (*(volatile hw_ccm_analog_usbphy1_pll_480_ctrl_tog_t *) HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ADDR)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_RD()      (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG.U)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_WR(v)     (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG.U = (v))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_SET(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_CLR(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_TOG(v)    (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_WR(HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_DIV_SELECT      0
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_DIV_SELECT)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, field EN_USB_CLKS (RW)
 *
 * 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1
 * are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable
 * USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when
 * USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_EN_USB_CLKS      6
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_EN_USB_CLKS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_EN_USB_CLKS(v)   ((((reg32_t) v) << 6) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_EN_USB_CLKS)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_EN_USB_CLKS(v)   (((v) << 6) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, EN_USB_CLKS, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, field POWER (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_POWER      12
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_POWER      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_POWER(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_POWER)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_POWER(v)   (((v) << 12) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_POWER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, field ENABLE (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ENABLE      13
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ENABLE)
#else
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_LOCK      31
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_LOCK      0x80000000

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
        unsigned RESERVED0 : 6; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog Debug bit.
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 12; //!< Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_528, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_528_LOCK      31
#define BM_CCM_ANALOG_PLL_528_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_SET - Analog 528MHz PLL Control Register _SET (RW)
 *
 * The control register provides control for the 528MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 1; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 6; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog Debug bit.
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 12; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_528_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_528_SET register
 */
#define HW_CCM_ANALOG_PLL_528_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_528_SET           (*(volatile hw_ccm_analog_pll_528_set_t *) HW_CCM_ANALOG_PLL_528_SET_ADDR)
#define HW_CCM_ANALOG_PLL_528_SET_RD()      (HW_CCM_ANALOG_PLL_528_SET.U)
#define HW_CCM_ANALOG_PLL_528_SET_WR(v)     (HW_CCM_ANALOG_PLL_528_SET.U = (v))
#define HW_CCM_ANALOG_PLL_528_SET_SET(v)    (HW_CCM_ANALOG_PLL_528_SET_WR(HW_CCM_ANALOG_PLL_528_SET_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_528_SET_CLR(v)    (HW_CCM_ANALOG_PLL_528_SET_WR(HW_CCM_ANALOG_PLL_528_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_528_SET_TOG(v)    (HW_CCM_ANALOG_PLL_528_SET_WR(HW_CCM_ANALOG_PLL_528_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_528_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_PLL_528_SET_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_528_SET_DIV_SELECT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_528_SET_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_528_SET_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_528_SET_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field HALF_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_SET_HALF_LF      7
#define BM_CCM_ANALOG_PLL_528_SET_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_528_SET_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_528_SET_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_528_SET_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_SET_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_528_SET_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_528_SET_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_528_SET_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_528_SET_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field HALF_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_SET_HALF_CP      9
#define BM_CCM_ANALOG_PLL_528_SET_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_528_SET_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_528_SET_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_528_SET_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_SET_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_528_SET_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_528_SET_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_528_SET_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_528_SET_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field HOLD_RING_OFF (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_528_SET_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_528_SET_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_528_SET_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_528_SET_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_528_SET_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_528_SET_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_528_SET_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_528_SET_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_528_SET_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_528_SET_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field ENABLE (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_528_SET_ENABLE      13
#define BM_CCM_ANALOG_PLL_528_SET_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_528_SET_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_528_SET_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_528_SET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_528_SET_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_528_SET_BYPASS      16
#define BM_CCM_ANALOG_PLL_528_SET_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_528_SET_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_528_SET_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_528_SET_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_528_SET_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_528_SET_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_SET_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_528_SET_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_528_SET_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_528_SET_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_528_SET_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_528_SET, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SET, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_528_SET_LOCK      31
#define BM_CCM_ANALOG_PLL_528_SET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_CLR - Analog 528MHz PLL Control Register _CLR (RW)
 *
 * The control register provides control for the 528MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 1; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 6; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog Debug bit.
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 12; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_528_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_528_CLR register
 */
#define HW_CCM_ANALOG_PLL_528_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_528_CLR           (*(volatile hw_ccm_analog_pll_528_clr_t *) HW_CCM_ANALOG_PLL_528_CLR_ADDR)
#define HW_CCM_ANALOG_PLL_528_CLR_RD()      (HW_CCM_ANALOG_PLL_528_CLR.U)
#define HW_CCM_ANALOG_PLL_528_CLR_WR(v)     (HW_CCM_ANALOG_PLL_528_CLR.U = (v))
#define HW_CCM_ANALOG_PLL_528_CLR_SET(v)    (HW_CCM_ANALOG_PLL_528_CLR_WR(HW_CCM_ANALOG_PLL_528_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_528_CLR_CLR(v)    (HW_CCM_ANALOG_PLL_528_CLR_WR(HW_CCM_ANALOG_PLL_528_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_528_CLR_TOG(v)    (HW_CCM_ANALOG_PLL_528_CLR_WR(HW_CCM_ANALOG_PLL_528_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_528_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_PLL_528_CLR_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_528_CLR_DIV_SELECT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_528_CLR_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_528_CLR_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field HALF_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_CLR_HALF_LF      7
#define BM_CCM_ANALOG_PLL_528_CLR_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_528_CLR_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_528_CLR_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_CLR_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_528_CLR_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_528_CLR_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_528_CLR_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field HALF_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_CLR_HALF_CP      9
#define BM_CCM_ANALOG_PLL_528_CLR_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_528_CLR_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_528_CLR_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_CLR_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_528_CLR_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_528_CLR_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_528_CLR_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field HOLD_RING_OFF (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_528_CLR_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_528_CLR_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_528_CLR_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_528_CLR_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_528_CLR_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_528_CLR_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_528_CLR_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_528_CLR_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field ENABLE (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_528_CLR_ENABLE      13
#define BM_CCM_ANALOG_PLL_528_CLR_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_528_CLR_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_528_CLR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_528_CLR_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_528_CLR_BYPASS      16
#define BM_CCM_ANALOG_PLL_528_CLR_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_528_CLR_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_528_CLR_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_528_CLR_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_528_CLR_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_CLR_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_528_CLR_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_528_CLR_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_528_CLR_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_528_CLR_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_528_CLR, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_CLR, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_528_CLR_LOCK      31
#define BM_CCM_ANALOG_PLL_528_CLR_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_TOG - Analog 528MHz PLL Control Register _TOG (RW)
 *
 * The control register provides control for the 528MHz PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 1; //!< This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 6; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog Debug bit.
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 12; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_528_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_528_TOG register
 */
#define HW_CCM_ANALOG_PLL_528_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_528_TOG           (*(volatile hw_ccm_analog_pll_528_tog_t *) HW_CCM_ANALOG_PLL_528_TOG_ADDR)
#define HW_CCM_ANALOG_PLL_528_TOG_RD()      (HW_CCM_ANALOG_PLL_528_TOG.U)
#define HW_CCM_ANALOG_PLL_528_TOG_WR(v)     (HW_CCM_ANALOG_PLL_528_TOG.U = (v))
#define HW_CCM_ANALOG_PLL_528_TOG_SET(v)    (HW_CCM_ANALOG_PLL_528_TOG_WR(HW_CCM_ANALOG_PLL_528_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_528_TOG_CLR(v)    (HW_CCM_ANALOG_PLL_528_TOG_WR(HW_CCM_ANALOG_PLL_528_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_528_TOG_TOG(v)    (HW_CCM_ANALOG_PLL_528_TOG_WR(HW_CCM_ANALOG_PLL_528_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_528_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_PLL_528_TOG_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_528_TOG_DIV_SELECT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_528_TOG_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_528_TOG_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field HALF_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_TOG_HALF_LF      7
#define BM_CCM_ANALOG_PLL_528_TOG_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_528_TOG_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_528_TOG_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_TOG_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_528_TOG_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_528_TOG_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_528_TOG_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field HALF_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_TOG_HALF_CP      9
#define BM_CCM_ANALOG_PLL_528_TOG_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_528_TOG_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_528_TOG_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_TOG_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_528_TOG_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_528_TOG_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_528_TOG_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field HOLD_RING_OFF (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_528_TOG_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_528_TOG_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_528_TOG_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_528_TOG_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_528_TOG_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_528_TOG_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_528_TOG_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_528_TOG_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field ENABLE (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_528_TOG_ENABLE      13
#define BM_CCM_ANALOG_PLL_528_TOG_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_528_TOG_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_528_TOG_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_528_TOG_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_528_TOG_BYPASS      16
#define BM_CCM_ANALOG_PLL_528_TOG_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_528_TOG_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_528_TOG_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_528_TOG_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_528_TOG_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_528_TOG_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_528_TOG_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_528_TOG_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_528_TOG_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_528_TOG_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_528_TOG, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_TOG, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_528_TOG_LOCK      31
#define BM_CCM_ANALOG_PLL_528_TOG_LOCK      0x80000000

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
        unsigned RESERVED0 : 2; //!< Always set to zero (0).
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
        unsigned RESERVED0 : 2; //!< Always set to zero (0).
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
        unsigned RESERVED1 : 9; //!< Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_LOCK      31
#define BM_CCM_ANALOG_PLL_AUDIO_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_SET - Analog Audio PLL control Register _SET (RW)
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
        unsigned RESERVED1 : 9; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_audio_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO_SET register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO_SET           (*(volatile hw_ccm_analog_pll_audio_set_t *) HW_CCM_ANALOG_PLL_AUDIO_SET_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_SET_RD()      (HW_CCM_ANALOG_PLL_AUDIO_SET.U)
#define HW_CCM_ANALOG_PLL_AUDIO_SET_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO_SET.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_SET_SET(v)    (HW_CCM_ANALOG_PLL_AUDIO_SET_WR(HW_CCM_ANALOG_PLL_AUDIO_SET_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_AUDIO_SET_CLR(v)    (HW_CCM_ANALOG_PLL_AUDIO_SET_WR(HW_CCM_ANALOG_PLL_AUDIO_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_AUDIO_SET_TOG(v)    (HW_CCM_ANALOG_PLL_AUDIO_SET_WR(HW_CCM_ANALOG_PLL_AUDIO_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_HALF_LF      7
#define BM_CCM_ANALOG_PLL_AUDIO_SET_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_AUDIO_SET_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_AUDIO_SET_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_HALF_CP      9
#define BM_CCM_ANALOG_PLL_AUDIO_SET_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_AUDIO_SET_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_AUDIO_SET_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field HOLD_RING_OFF (RW)
 *
 * Analog debug Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_AUDIO_SET_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_AUDIO_SET_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_AUDIO_SET_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field ENABLE (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_ENABLE      13
#define BM_CCM_ANALOG_PLL_AUDIO_SET_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_AUDIO_SET_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_AUDIO_SET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_BYPASS      16
#define BM_CCM_ANALOG_PLL_AUDIO_SET_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_AUDIO_SET_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_AUDIO_SET_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_AUDIO_SET_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_AUDIO_SET_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_AUDIO_SET_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field POST_DIV_SELECT (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT      19
#define BM_CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field SSC_EN (RW)
 *
 * Reserved Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_SSC_EN      21
#define BM_CCM_ANALOG_PLL_AUDIO_SET_SSC_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_SET_SSC_EN(v)   ((((reg32_t) v) << 21) & BM_CCM_ANALOG_PLL_AUDIO_SET_SSC_EN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_SET_SSC_EN(v)   (((v) << 21) & BM_CCM_ANALOG_PLL_AUDIO_SET_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SET_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_SET, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_SET, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SET_LOCK      31
#define BM_CCM_ANALOG_PLL_AUDIO_SET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_CLR - Analog Audio PLL control Register _CLR (RW)
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
        unsigned RESERVED1 : 9; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_audio_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO_CLR register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO_CLR           (*(volatile hw_ccm_analog_pll_audio_clr_t *) HW_CCM_ANALOG_PLL_AUDIO_CLR_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_CLR_RD()      (HW_CCM_ANALOG_PLL_AUDIO_CLR.U)
#define HW_CCM_ANALOG_PLL_AUDIO_CLR_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO_CLR.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_CLR_SET(v)    (HW_CCM_ANALOG_PLL_AUDIO_CLR_WR(HW_CCM_ANALOG_PLL_AUDIO_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_AUDIO_CLR_CLR(v)    (HW_CCM_ANALOG_PLL_AUDIO_CLR_WR(HW_CCM_ANALOG_PLL_AUDIO_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_AUDIO_CLR_TOG(v)    (HW_CCM_ANALOG_PLL_AUDIO_CLR_WR(HW_CCM_ANALOG_PLL_AUDIO_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_HALF_LF      7
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_AUDIO_CLR_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_AUDIO_CLR_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_HALF_CP      9
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_AUDIO_CLR_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_AUDIO_CLR_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field HOLD_RING_OFF (RW)
 *
 * Analog debug Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_AUDIO_CLR_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_AUDIO_CLR_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field ENABLE (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_ENABLE      13
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_AUDIO_CLR_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_AUDIO_CLR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS      16
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_AUDIO_CLR_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_AUDIO_CLR_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field POST_DIV_SELECT (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT      19
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field SSC_EN (RW)
 *
 * Reserved Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_SSC_EN      21
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_SSC_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_SSC_EN(v)   ((((reg32_t) v) << 21) & BM_CCM_ANALOG_PLL_AUDIO_CLR_SSC_EN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_CLR_SSC_EN(v)   (((v) << 21) & BM_CCM_ANALOG_PLL_AUDIO_CLR_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_CLR_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_CLR, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_CLR, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_CLR_LOCK      31
#define BM_CCM_ANALOG_PLL_AUDIO_CLR_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_TOG - Analog Audio PLL control Register _TOG (RW)
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
        unsigned RESERVED1 : 9; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_audio_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO_TOG register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO_TOG           (*(volatile hw_ccm_analog_pll_audio_tog_t *) HW_CCM_ANALOG_PLL_AUDIO_TOG_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_TOG_RD()      (HW_CCM_ANALOG_PLL_AUDIO_TOG.U)
#define HW_CCM_ANALOG_PLL_AUDIO_TOG_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO_TOG.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_TOG_SET(v)    (HW_CCM_ANALOG_PLL_AUDIO_TOG_WR(HW_CCM_ANALOG_PLL_AUDIO_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_AUDIO_TOG_CLR(v)    (HW_CCM_ANALOG_PLL_AUDIO_TOG_WR(HW_CCM_ANALOG_PLL_AUDIO_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_AUDIO_TOG_TOG(v)    (HW_CCM_ANALOG_PLL_AUDIO_TOG_WR(HW_CCM_ANALOG_PLL_AUDIO_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_HALF_LF      7
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_AUDIO_TOG_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_AUDIO_TOG_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_HALF_CP      9
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_AUDIO_TOG_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_AUDIO_TOG_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field HOLD_RING_OFF (RW)
 *
 * Analog debug Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_AUDIO_TOG_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_AUDIO_TOG_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field ENABLE (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_ENABLE      13
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_AUDIO_TOG_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_AUDIO_TOG_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS      16
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_AUDIO_TOG_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_AUDIO_TOG_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field POST_DIV_SELECT (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT      19
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field SSC_EN (RW)
 *
 * Reserved Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_SSC_EN      21
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_SSC_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_SSC_EN(v)   ((((reg32_t) v) << 21) & BM_CCM_ANALOG_PLL_AUDIO_TOG_SSC_EN)
#else
#define BF_CCM_ANALOG_PLL_AUDIO_TOG_SSC_EN(v)   (((v) << 21) & BM_CCM_ANALOG_PLL_AUDIO_TOG_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_TOG_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO_TOG, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_TOG, field LOCK (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_TOG_LOCK      31
#define BM_CCM_ANALOG_PLL_AUDIO_TOG_LOCK      0x80000000

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
        unsigned RESERVED0 : 2; //!< Always set to zero (0).
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
        unsigned RESERVED0 : 2; //!< Always set to zero (0).
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
        unsigned RESERVED1 : 9; //!< Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_LOCK      31
#define BM_CCM_ANALOG_PLL_VIDEO_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_SET - Analog Video PLL control Register _SET (RW)
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
        unsigned RESERVED1 : 9; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_video_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO_SET register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO_SET           (*(volatile hw_ccm_analog_pll_video_set_t *) HW_CCM_ANALOG_PLL_VIDEO_SET_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_SET_RD()      (HW_CCM_ANALOG_PLL_VIDEO_SET.U)
#define HW_CCM_ANALOG_PLL_VIDEO_SET_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO_SET.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_SET_SET(v)    (HW_CCM_ANALOG_PLL_VIDEO_SET_WR(HW_CCM_ANALOG_PLL_VIDEO_SET_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_VIDEO_SET_CLR(v)    (HW_CCM_ANALOG_PLL_VIDEO_SET_WR(HW_CCM_ANALOG_PLL_VIDEO_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_VIDEO_SET_TOG(v)    (HW_CCM_ANALOG_PLL_VIDEO_SET_WR(HW_CCM_ANALOG_PLL_VIDEO_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_HALF_LF      7
#define BM_CCM_ANALOG_PLL_VIDEO_SET_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_VIDEO_SET_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_VIDEO_SET_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_HALF_CP      9
#define BM_CCM_ANALOG_PLL_VIDEO_SET_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_VIDEO_SET_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_VIDEO_SET_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field HOLD_RING_OFF (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_VIDEO_SET_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_VIDEO_SET_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_VIDEO_SET_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field ENABLE (RW)
 *
 * Enalbe PLL output
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_ENABLE      13
#define BM_CCM_ANALOG_PLL_VIDEO_SET_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_VIDEO_SET_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_VIDEO_SET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_BYPASS      16
#define BM_CCM_ANALOG_PLL_VIDEO_SET_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_VIDEO_SET_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_VIDEO_SET_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_VIDEO_SET_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_VIDEO_SET_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_VIDEO_SET_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field POST_DIV_SELECT (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT      19
#define BM_CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field SSC_EN (RW)
 *
 * Revserved BIt
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_SSC_EN      21
#define BM_CCM_ANALOG_PLL_VIDEO_SET_SSC_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_SET_SSC_EN(v)   ((((reg32_t) v) << 21) & BM_CCM_ANALOG_PLL_VIDEO_SET_SSC_EN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_SET_SSC_EN(v)   (((v) << 21) & BM_CCM_ANALOG_PLL_VIDEO_SET_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SET_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_SET, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_SET, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SET_LOCK      31
#define BM_CCM_ANALOG_PLL_VIDEO_SET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_CLR - Analog Video PLL control Register _CLR (RW)
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
        unsigned RESERVED1 : 9; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_video_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO_CLR register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO_CLR           (*(volatile hw_ccm_analog_pll_video_clr_t *) HW_CCM_ANALOG_PLL_VIDEO_CLR_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_CLR_RD()      (HW_CCM_ANALOG_PLL_VIDEO_CLR.U)
#define HW_CCM_ANALOG_PLL_VIDEO_CLR_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO_CLR.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_CLR_SET(v)    (HW_CCM_ANALOG_PLL_VIDEO_CLR_WR(HW_CCM_ANALOG_PLL_VIDEO_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_VIDEO_CLR_CLR(v)    (HW_CCM_ANALOG_PLL_VIDEO_CLR_WR(HW_CCM_ANALOG_PLL_VIDEO_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_VIDEO_CLR_TOG(v)    (HW_CCM_ANALOG_PLL_VIDEO_CLR_WR(HW_CCM_ANALOG_PLL_VIDEO_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_HALF_LF      7
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_VIDEO_CLR_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_VIDEO_CLR_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_HALF_CP      9
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_VIDEO_CLR_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_VIDEO_CLR_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field HOLD_RING_OFF (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_VIDEO_CLR_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_VIDEO_CLR_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field ENABLE (RW)
 *
 * Enalbe PLL output
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_ENABLE      13
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_VIDEO_CLR_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_VIDEO_CLR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS      16
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_VIDEO_CLR_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_VIDEO_CLR_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field POST_DIV_SELECT (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT      19
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field SSC_EN (RW)
 *
 * Revserved BIt
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_SSC_EN      21
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_SSC_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_SSC_EN(v)   ((((reg32_t) v) << 21) & BM_CCM_ANALOG_PLL_VIDEO_CLR_SSC_EN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_CLR_SSC_EN(v)   (((v) << 21) & BM_CCM_ANALOG_PLL_VIDEO_CLR_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_CLR_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_CLR, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_CLR, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_CLR_LOCK      31
#define BM_CCM_ANALOG_PLL_VIDEO_CLR_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_TOG - Analog Video PLL control Register _TOG (RW)
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
        unsigned RESERVED1 : 9; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_video_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO_TOG register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO_TOG           (*(volatile hw_ccm_analog_pll_video_tog_t *) HW_CCM_ANALOG_PLL_VIDEO_TOG_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_TOG_RD()      (HW_CCM_ANALOG_PLL_VIDEO_TOG.U)
#define HW_CCM_ANALOG_PLL_VIDEO_TOG_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO_TOG.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_TOG_SET(v)    (HW_CCM_ANALOG_PLL_VIDEO_TOG_WR(HW_CCM_ANALOG_PLL_VIDEO_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_VIDEO_TOG_CLR(v)    (HW_CCM_ANALOG_PLL_VIDEO_TOG_WR(HW_CCM_ANALOG_PLL_VIDEO_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_VIDEO_TOG_TOG(v)    (HW_CCM_ANALOG_PLL_VIDEO_TOG_WR(HW_CCM_ANALOG_PLL_VIDEO_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field DIV_SELECT (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field HALF_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_HALF_LF      7
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_VIDEO_TOG_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_VIDEO_TOG_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field HALF_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_HALF_CP      9
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_VIDEO_TOG_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_VIDEO_TOG_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field HOLD_RING_OFF (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_VIDEO_TOG_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_VIDEO_TOG_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field ENABLE (RW)
 *
 * Enalbe PLL output
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_ENABLE      13
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_VIDEO_TOG_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_VIDEO_TOG_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS      16
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_VIDEO_TOG_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_VIDEO_TOG_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field POST_DIV_SELECT (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT      19
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field SSC_EN (RW)
 *
 * Revserved BIt
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_SSC_EN      21
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_SSC_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_SSC_EN(v)   ((((reg32_t) v) << 21) & BM_CCM_ANALOG_PLL_VIDEO_TOG_SSC_EN)
#else
#define BF_CCM_ANALOG_PLL_VIDEO_TOG_SSC_EN(v)   (((v) << 21) & BM_CCM_ANALOG_PLL_VIDEO_TOG_SSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_TOG_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO_TOG, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_TOG, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_TOG_LOCK      31
#define BM_CCM_ANALOG_PLL_VIDEO_TOG_LOCK      0x80000000

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
        unsigned RESERVED0 : 2; //!< Always set to zero (0).
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
        unsigned RESERVED0 : 2; //!< Always set to zero (0).
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
 * @brief HW_CCM_ANALOG_PLL_MLB_SET - MLB PLL Control Register _SET (RW)
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
} hw_ccm_analog_pll_mlb_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_MLB_SET register
 */
#define HW_CCM_ANALOG_PLL_MLB_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_MLB_SET           (*(volatile hw_ccm_analog_pll_mlb_set_t *) HW_CCM_ANALOG_PLL_MLB_SET_ADDR)
#define HW_CCM_ANALOG_PLL_MLB_SET_RD()      (HW_CCM_ANALOG_PLL_MLB_SET.U)
#define HW_CCM_ANALOG_PLL_MLB_SET_WR(v)     (HW_CCM_ANALOG_PLL_MLB_SET.U = (v))
#define HW_CCM_ANALOG_PLL_MLB_SET_SET(v)    (HW_CCM_ANALOG_PLL_MLB_SET_WR(HW_CCM_ANALOG_PLL_MLB_SET_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_MLB_SET_CLR(v)    (HW_CCM_ANALOG_PLL_MLB_SET_WR(HW_CCM_ANALOG_PLL_MLB_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_MLB_SET_TOG(v)    (HW_CCM_ANALOG_PLL_MLB_SET_WR(HW_CCM_ANALOG_PLL_MLB_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_MLB_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_MLB_SET, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_SET_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_MLB_SET_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_SET_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_MLB_SET_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_MLB_SET_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_MLB_SET_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_SET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_MLB_SET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_SET, field PHASE_SEL (RW)
 *
 * Analog debut bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_SET_PHASE_SEL      12
#define BM_CCM_ANALOG_PLL_MLB_SET_PHASE_SEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_SET_PHASE_SEL(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_MLB_SET_PHASE_SEL)
#else
#define BF_CCM_ANALOG_PLL_MLB_SET_PHASE_SEL(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_MLB_SET_PHASE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHASE_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_SET_PHASE_SEL(v)   BF_CS1(CCM_ANALOG_PLL_MLB_SET, PHASE_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_SET, field BYPASS (RW)
 *
 * Bypass the PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_SET_BYPASS      16
#define BM_CCM_ANALOG_PLL_MLB_SET_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_SET_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_MLB_SET_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_MLB_SET_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_MLB_SET_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_SET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_MLB_SET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_SET, field VDDA_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in Vddio power domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_SET_VDDA_DELAY_CFG      17
#define BM_CCM_ANALOG_PLL_MLB_SET_VDDA_DELAY_CFG      0x000e0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_SET_VDDA_DELAY_CFG(v)   ((((reg32_t) v) << 17) & BM_CCM_ANALOG_PLL_MLB_SET_VDDA_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_SET_VDDA_DELAY_CFG(v)   (((v) << 17) & BM_CCM_ANALOG_PLL_MLB_SET_VDDA_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDA_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_SET_VDDA_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_SET, VDDA_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_SET, field VDDD_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in core Vdd poser domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_SET_VDDD_DELAY_CFG      20
#define BM_CCM_ANALOG_PLL_MLB_SET_VDDD_DELAY_CFG      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_SET_VDDD_DELAY_CFG(v)   ((((reg32_t) v) << 20) & BM_CCM_ANALOG_PLL_MLB_SET_VDDD_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_SET_VDDD_DELAY_CFG(v)   (((v) << 20) & BM_CCM_ANALOG_PLL_MLB_SET_VDDD_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDD_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_SET_VDDD_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_SET, VDDD_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_SET, field RX_CLK_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL RX Clock.
 */

#define BP_CCM_ANALOG_PLL_MLB_SET_RX_CLK_DELAY_CFG      23
#define BM_CCM_ANALOG_PLL_MLB_SET_RX_CLK_DELAY_CFG      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_SET_RX_CLK_DELAY_CFG(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PLL_MLB_SET_RX_CLK_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_SET_RX_CLK_DELAY_CFG(v)   (((v) << 23) & BM_CCM_ANALOG_PLL_MLB_SET_RX_CLK_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CLK_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_SET_RX_CLK_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_SET, RX_CLK_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_SET, field MLB_FLT_RES_CFG (RW)
 *
 * Configure the filter resistor for different divider ratio of MLB PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_SET_MLB_FLT_RES_CFG      26
#define BM_CCM_ANALOG_PLL_MLB_SET_MLB_FLT_RES_CFG      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_SET_MLB_FLT_RES_CFG(v)   ((((reg32_t) v) << 26) & BM_CCM_ANALOG_PLL_MLB_SET_MLB_FLT_RES_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_SET_MLB_FLT_RES_CFG(v)   (((v) << 26) & BM_CCM_ANALOG_PLL_MLB_SET_MLB_FLT_RES_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MLB_FLT_RES_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_SET_MLB_FLT_RES_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_SET, MLB_FLT_RES_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_SET, field LOCK (RO)
 *
 * Lock bit
 *
 * Values:
 * 0 - PLL is not currently locked
 * 1 - PLL is currently locked.
 */

#define BP_CCM_ANALOG_PLL_MLB_SET_LOCK      31
#define BM_CCM_ANALOG_PLL_MLB_SET_LOCK      0x80000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_MLB_CLR - MLB PLL Control Register _CLR (RW)
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
} hw_ccm_analog_pll_mlb_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_MLB_CLR register
 */
#define HW_CCM_ANALOG_PLL_MLB_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0xd8)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_MLB_CLR           (*(volatile hw_ccm_analog_pll_mlb_clr_t *) HW_CCM_ANALOG_PLL_MLB_CLR_ADDR)
#define HW_CCM_ANALOG_PLL_MLB_CLR_RD()      (HW_CCM_ANALOG_PLL_MLB_CLR.U)
#define HW_CCM_ANALOG_PLL_MLB_CLR_WR(v)     (HW_CCM_ANALOG_PLL_MLB_CLR.U = (v))
#define HW_CCM_ANALOG_PLL_MLB_CLR_SET(v)    (HW_CCM_ANALOG_PLL_MLB_CLR_WR(HW_CCM_ANALOG_PLL_MLB_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_MLB_CLR_CLR(v)    (HW_CCM_ANALOG_PLL_MLB_CLR_WR(HW_CCM_ANALOG_PLL_MLB_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_MLB_CLR_TOG(v)    (HW_CCM_ANALOG_PLL_MLB_CLR_WR(HW_CCM_ANALOG_PLL_MLB_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_MLB_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_MLB_CLR, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_CLR_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_MLB_CLR_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_CLR_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_MLB_CLR_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_MLB_CLR_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_MLB_CLR_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_CLR_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_MLB_CLR, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_CLR, field PHASE_SEL (RW)
 *
 * Analog debut bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_CLR_PHASE_SEL      12
#define BM_CCM_ANALOG_PLL_MLB_CLR_PHASE_SEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_CLR_PHASE_SEL(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_MLB_CLR_PHASE_SEL)
#else
#define BF_CCM_ANALOG_PLL_MLB_CLR_PHASE_SEL(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_MLB_CLR_PHASE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHASE_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_CLR_PHASE_SEL(v)   BF_CS1(CCM_ANALOG_PLL_MLB_CLR, PHASE_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_CLR, field BYPASS (RW)
 *
 * Bypass the PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_CLR_BYPASS      16
#define BM_CCM_ANALOG_PLL_MLB_CLR_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_CLR_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_MLB_CLR_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_MLB_CLR_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_MLB_CLR_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_CLR_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_MLB_CLR, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_CLR, field VDDA_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in Vddio power domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_CLR_VDDA_DELAY_CFG      17
#define BM_CCM_ANALOG_PLL_MLB_CLR_VDDA_DELAY_CFG      0x000e0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_CLR_VDDA_DELAY_CFG(v)   ((((reg32_t) v) << 17) & BM_CCM_ANALOG_PLL_MLB_CLR_VDDA_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_CLR_VDDA_DELAY_CFG(v)   (((v) << 17) & BM_CCM_ANALOG_PLL_MLB_CLR_VDDA_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDA_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_CLR_VDDA_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_CLR, VDDA_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_CLR, field VDDD_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in core Vdd poser domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_CLR_VDDD_DELAY_CFG      20
#define BM_CCM_ANALOG_PLL_MLB_CLR_VDDD_DELAY_CFG      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_CLR_VDDD_DELAY_CFG(v)   ((((reg32_t) v) << 20) & BM_CCM_ANALOG_PLL_MLB_CLR_VDDD_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_CLR_VDDD_DELAY_CFG(v)   (((v) << 20) & BM_CCM_ANALOG_PLL_MLB_CLR_VDDD_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDD_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_CLR_VDDD_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_CLR, VDDD_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_CLR, field RX_CLK_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL RX Clock.
 */

#define BP_CCM_ANALOG_PLL_MLB_CLR_RX_CLK_DELAY_CFG      23
#define BM_CCM_ANALOG_PLL_MLB_CLR_RX_CLK_DELAY_CFG      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_CLR_RX_CLK_DELAY_CFG(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PLL_MLB_CLR_RX_CLK_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_CLR_RX_CLK_DELAY_CFG(v)   (((v) << 23) & BM_CCM_ANALOG_PLL_MLB_CLR_RX_CLK_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CLK_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_CLR_RX_CLK_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_CLR, RX_CLK_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_CLR, field MLB_FLT_RES_CFG (RW)
 *
 * Configure the filter resistor for different divider ratio of MLB PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_CLR_MLB_FLT_RES_CFG      26
#define BM_CCM_ANALOG_PLL_MLB_CLR_MLB_FLT_RES_CFG      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_CLR_MLB_FLT_RES_CFG(v)   ((((reg32_t) v) << 26) & BM_CCM_ANALOG_PLL_MLB_CLR_MLB_FLT_RES_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_CLR_MLB_FLT_RES_CFG(v)   (((v) << 26) & BM_CCM_ANALOG_PLL_MLB_CLR_MLB_FLT_RES_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MLB_FLT_RES_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_CLR_MLB_FLT_RES_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_CLR, MLB_FLT_RES_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_CLR, field LOCK (RO)
 *
 * Lock bit
 *
 * Values:
 * 0 - PLL is not currently locked
 * 1 - PLL is currently locked.
 */

#define BP_CCM_ANALOG_PLL_MLB_CLR_LOCK      31
#define BM_CCM_ANALOG_PLL_MLB_CLR_LOCK      0x80000000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_MLB_TOG - MLB PLL Control Register _TOG (RW)
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
} hw_ccm_analog_pll_mlb_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_MLB_TOG register
 */
#define HW_CCM_ANALOG_PLL_MLB_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0xdc)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_MLB_TOG           (*(volatile hw_ccm_analog_pll_mlb_tog_t *) HW_CCM_ANALOG_PLL_MLB_TOG_ADDR)
#define HW_CCM_ANALOG_PLL_MLB_TOG_RD()      (HW_CCM_ANALOG_PLL_MLB_TOG.U)
#define HW_CCM_ANALOG_PLL_MLB_TOG_WR(v)     (HW_CCM_ANALOG_PLL_MLB_TOG.U = (v))
#define HW_CCM_ANALOG_PLL_MLB_TOG_SET(v)    (HW_CCM_ANALOG_PLL_MLB_TOG_WR(HW_CCM_ANALOG_PLL_MLB_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_MLB_TOG_CLR(v)    (HW_CCM_ANALOG_PLL_MLB_TOG_WR(HW_CCM_ANALOG_PLL_MLB_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_MLB_TOG_TOG(v)    (HW_CCM_ANALOG_PLL_MLB_TOG_WR(HW_CCM_ANALOG_PLL_MLB_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_MLB_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_MLB_TOG, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_TOG_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_MLB_TOG_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_TOG_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_MLB_TOG_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_MLB_TOG_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_MLB_TOG_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_TOG_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_MLB_TOG, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_TOG, field PHASE_SEL (RW)
 *
 * Analog debut bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_TOG_PHASE_SEL      12
#define BM_CCM_ANALOG_PLL_MLB_TOG_PHASE_SEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_TOG_PHASE_SEL(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_MLB_TOG_PHASE_SEL)
#else
#define BF_CCM_ANALOG_PLL_MLB_TOG_PHASE_SEL(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_MLB_TOG_PHASE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHASE_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_TOG_PHASE_SEL(v)   BF_CS1(CCM_ANALOG_PLL_MLB_TOG, PHASE_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_TOG, field BYPASS (RW)
 *
 * Bypass the PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_TOG_BYPASS      16
#define BM_CCM_ANALOG_PLL_MLB_TOG_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_TOG_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_MLB_TOG_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_MLB_TOG_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_MLB_TOG_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_TOG_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_MLB_TOG, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_TOG, field VDDA_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in Vddio power domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_TOG_VDDA_DELAY_CFG      17
#define BM_CCM_ANALOG_PLL_MLB_TOG_VDDA_DELAY_CFG      0x000e0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_TOG_VDDA_DELAY_CFG(v)   ((((reg32_t) v) << 17) & BM_CCM_ANALOG_PLL_MLB_TOG_VDDA_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_TOG_VDDA_DELAY_CFG(v)   (((v) << 17) & BM_CCM_ANALOG_PLL_MLB_TOG_VDDA_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDA_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_TOG_VDDA_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_TOG, VDDA_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_TOG, field VDDD_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in core Vdd poser domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_TOG_VDDD_DELAY_CFG      20
#define BM_CCM_ANALOG_PLL_MLB_TOG_VDDD_DELAY_CFG      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_TOG_VDDD_DELAY_CFG(v)   ((((reg32_t) v) << 20) & BM_CCM_ANALOG_PLL_MLB_TOG_VDDD_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_TOG_VDDD_DELAY_CFG(v)   (((v) << 20) & BM_CCM_ANALOG_PLL_MLB_TOG_VDDD_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDD_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_TOG_VDDD_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_TOG, VDDD_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_TOG, field RX_CLK_DELAY_CFG (RW)
 *
 * Configure the phase delay of the MLB PLL RX Clock.
 */

#define BP_CCM_ANALOG_PLL_MLB_TOG_RX_CLK_DELAY_CFG      23
#define BM_CCM_ANALOG_PLL_MLB_TOG_RX_CLK_DELAY_CFG      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_TOG_RX_CLK_DELAY_CFG(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PLL_MLB_TOG_RX_CLK_DELAY_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_TOG_RX_CLK_DELAY_CFG(v)   (((v) << 23) & BM_CCM_ANALOG_PLL_MLB_TOG_RX_CLK_DELAY_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CLK_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_TOG_RX_CLK_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_TOG, RX_CLK_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_TOG, field MLB_FLT_RES_CFG (RW)
 *
 * Configure the filter resistor for different divider ratio of MLB PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_TOG_MLB_FLT_RES_CFG      26
#define BM_CCM_ANALOG_PLL_MLB_TOG_MLB_FLT_RES_CFG      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_MLB_TOG_MLB_FLT_RES_CFG(v)   ((((reg32_t) v) << 26) & BM_CCM_ANALOG_PLL_MLB_TOG_MLB_FLT_RES_CFG)
#else
#define BF_CCM_ANALOG_PLL_MLB_TOG_MLB_FLT_RES_CFG(v)   (((v) << 26) & BM_CCM_ANALOG_PLL_MLB_TOG_MLB_FLT_RES_CFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MLB_FLT_RES_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_TOG_MLB_FLT_RES_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB_TOG, MLB_FLT_RES_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB_TOG, field LOCK (RO)
 *
 * Lock bit
 *
 * Values:
 * 0 - PLL is not currently locked
 * 1 - PLL is currently locked.
 */

#define BP_CCM_ANALOG_PLL_MLB_TOG_LOCK      31
#define BM_CCM_ANALOG_PLL_MLB_TOG_LOCK      0x80000000


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
        unsigned RESERVED0 : 5; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog debug bit
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable the ethernet clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_PCIE : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_SATA : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 10; //!< Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_ENET, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_ENET_LOCK      31
#define BM_CCM_ANALOG_PLL_ENET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_ENET_SET - Analog ENET PLL Control Register _SET (RW)
 *
 * The control register provides control for the ENET PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz respectively.
        unsigned RESERVED0 : 5; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog debug bit
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable the ethernet clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_PCIE : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_SATA : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 10; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_enet_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_ENET_SET register
 */
#define HW_CCM_ANALOG_PLL_ENET_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_ENET_SET           (*(volatile hw_ccm_analog_pll_enet_set_t *) HW_CCM_ANALOG_PLL_ENET_SET_ADDR)
#define HW_CCM_ANALOG_PLL_ENET_SET_RD()      (HW_CCM_ANALOG_PLL_ENET_SET.U)
#define HW_CCM_ANALOG_PLL_ENET_SET_WR(v)     (HW_CCM_ANALOG_PLL_ENET_SET.U = (v))
#define HW_CCM_ANALOG_PLL_ENET_SET_SET(v)    (HW_CCM_ANALOG_PLL_ENET_SET_WR(HW_CCM_ANALOG_PLL_ENET_SET_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_ENET_SET_CLR(v)    (HW_CCM_ANALOG_PLL_ENET_SET_WR(HW_CCM_ANALOG_PLL_ENET_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_ENET_SET_TOG(v)    (HW_CCM_ANALOG_PLL_ENET_SET_WR(HW_CCM_ANALOG_PLL_ENET_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_ENET_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field DIV_SELECT (RW)
 *
 * Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not
 * 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz
 * respectively.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_ENET_SET_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_ENET_SET_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_ENET_SET_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field HALF_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_HALF_LF      7
#define BM_CCM_ANALOG_PLL_ENET_SET_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_ENET_SET_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_ENET_SET_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_ENET_SET_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_ENET_SET_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_ENET_SET_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field HALF_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_HALF_CP      9
#define BM_CCM_ANALOG_PLL_ENET_SET_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_ENET_SET_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_ENET_SET_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_ENET_SET_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_ENET_SET_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_ENET_SET_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_ENET_SET_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_ENET_SET_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_ENET_SET_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_ENET_SET_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_ENET_SET_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_ENET_SET_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field ENABLE (RW)
 *
 * Enable the ethernet clock output.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_ENABLE      13
#define BM_CCM_ANALOG_PLL_ENET_SET_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_ENET_SET_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_ENET_SET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_BYPASS      16
#define BM_CCM_ANALOG_PLL_ENET_SET_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_ENET_SET_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_ENET_SET_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_ENET_SET_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_ENET_SET_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_ENET_SET_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field ENABLE_PCIE (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_ENABLE_PCIE      19
#define BM_CCM_ANALOG_PLL_ENET_SET_ENABLE_PCIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_ENABLE_PCIE(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_ENET_SET_ENABLE_PCIE)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_ENABLE_PCIE(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_ENET_SET_ENABLE_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PCIE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_ENABLE_PCIE(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, ENABLE_PCIE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field ENABLE_SATA (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_ENABLE_SATA      20
#define BM_CCM_ANALOG_PLL_ENET_SET_ENABLE_SATA      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_SET_ENABLE_SATA(v)   ((((reg32_t) v) << 20) & BM_CCM_ANALOG_PLL_ENET_SET_ENABLE_SATA)
#else
#define BF_CCM_ANALOG_PLL_ENET_SET_ENABLE_SATA(v)   (((v) << 20) & BM_CCM_ANALOG_PLL_ENET_SET_ENABLE_SATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_SATA field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_SET_ENABLE_SATA(v)   BF_CS1(CCM_ANALOG_PLL_ENET_SET, ENABLE_SATA, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_SET, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_ENET_SET_LOCK      31
#define BM_CCM_ANALOG_PLL_ENET_SET_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_ENET_CLR - Analog ENET PLL Control Register _CLR (RW)
 *
 * The control register provides control for the ENET PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz respectively.
        unsigned RESERVED0 : 5; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog debug bit
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable the ethernet clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_PCIE : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_SATA : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 10; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_enet_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_ENET_CLR register
 */
#define HW_CCM_ANALOG_PLL_ENET_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_ENET_CLR           (*(volatile hw_ccm_analog_pll_enet_clr_t *) HW_CCM_ANALOG_PLL_ENET_CLR_ADDR)
#define HW_CCM_ANALOG_PLL_ENET_CLR_RD()      (HW_CCM_ANALOG_PLL_ENET_CLR.U)
#define HW_CCM_ANALOG_PLL_ENET_CLR_WR(v)     (HW_CCM_ANALOG_PLL_ENET_CLR.U = (v))
#define HW_CCM_ANALOG_PLL_ENET_CLR_SET(v)    (HW_CCM_ANALOG_PLL_ENET_CLR_WR(HW_CCM_ANALOG_PLL_ENET_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_ENET_CLR_CLR(v)    (HW_CCM_ANALOG_PLL_ENET_CLR_WR(HW_CCM_ANALOG_PLL_ENET_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_ENET_CLR_TOG(v)    (HW_CCM_ANALOG_PLL_ENET_CLR_WR(HW_CCM_ANALOG_PLL_ENET_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_ENET_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field DIV_SELECT (RW)
 *
 * Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not
 * 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz
 * respectively.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field HALF_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_HALF_LF      7
#define BM_CCM_ANALOG_PLL_ENET_CLR_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_ENET_CLR_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_ENET_CLR_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field HALF_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_HALF_CP      9
#define BM_CCM_ANALOG_PLL_ENET_CLR_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_ENET_CLR_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_ENET_CLR_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_ENET_CLR_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_ENET_CLR_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_ENET_CLR_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_ENET_CLR_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_ENET_CLR_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_ENET_CLR_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field ENABLE (RW)
 *
 * Enable the ethernet clock output.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_ENABLE      13
#define BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_BYPASS      16
#define BM_CCM_ANALOG_PLL_ENET_CLR_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_ENET_CLR_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_ENET_CLR_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_ENET_CLR_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_ENET_CLR_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_ENET_CLR_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field ENABLE_PCIE (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_ENABLE_PCIE      19
#define BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE_PCIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_ENABLE_PCIE(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE_PCIE)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_ENABLE_PCIE(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PCIE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_ENABLE_PCIE(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, ENABLE_PCIE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field ENABLE_SATA (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_ENABLE_SATA      20
#define BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE_SATA      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_CLR_ENABLE_SATA(v)   ((((reg32_t) v) << 20) & BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE_SATA)
#else
#define BF_CCM_ANALOG_PLL_ENET_CLR_ENABLE_SATA(v)   (((v) << 20) & BM_CCM_ANALOG_PLL_ENET_CLR_ENABLE_SATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_SATA field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_CLR_ENABLE_SATA(v)   BF_CS1(CCM_ANALOG_PLL_ENET_CLR, ENABLE_SATA, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_CLR, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_ENET_CLR_LOCK      31
#define BM_CCM_ANALOG_PLL_ENET_CLR_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_ENET_TOG - Analog ENET PLL Control Register _TOG (RW)
 *
 * The control register provides control for the ENET PLL.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIV_SELECT : 2; //!< Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz respectively.
        unsigned RESERVED0 : 5; //!< Always set to zero (0).
        unsigned HALF_LF : 1; //!< Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< Reserved by Freescale
        unsigned HALF_CP : 1; //!< Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< Analog debug bit
        unsigned POWERDOWN : 1; //!< Powers down the PLL.
        unsigned ENABLE : 1; //!< Enable the ethernet clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< Determines the bypass source.
        unsigned BYPASS : 1; //!< Bypass the pll.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PFD_OFFSET_EN : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_PCIE : 1; //!< Enables an offset in the phase frequency detector.
        unsigned ENABLE_SATA : 1; //!< Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 10; //!< Always set to zero (0).
        unsigned LOCK : 1; //!< 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_enet_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_ENET_TOG register
 */
#define HW_CCM_ANALOG_PLL_ENET_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_ENET_TOG           (*(volatile hw_ccm_analog_pll_enet_tog_t *) HW_CCM_ANALOG_PLL_ENET_TOG_ADDR)
#define HW_CCM_ANALOG_PLL_ENET_TOG_RD()      (HW_CCM_ANALOG_PLL_ENET_TOG.U)
#define HW_CCM_ANALOG_PLL_ENET_TOG_WR(v)     (HW_CCM_ANALOG_PLL_ENET_TOG.U = (v))
#define HW_CCM_ANALOG_PLL_ENET_TOG_SET(v)    (HW_CCM_ANALOG_PLL_ENET_TOG_WR(HW_CCM_ANALOG_PLL_ENET_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_ENET_TOG_CLR(v)    (HW_CCM_ANALOG_PLL_ENET_TOG_WR(HW_CCM_ANALOG_PLL_ENET_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_ENET_TOG_TOG(v)    (HW_CCM_ANALOG_PLL_ENET_TOG_WR(HW_CCM_ANALOG_PLL_ENET_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_ENET_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field DIV_SELECT (RW)
 *
 * Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not
 * 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz
 * respectively.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT      0
#define BM_CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT(v)   (((v) << 0) & BM_CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field HALF_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_HALF_LF      7
#define BM_CCM_ANALOG_PLL_ENET_TOG_HALF_LF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_HALF_LF(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PLL_ENET_TOG_HALF_LF)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_HALF_LF(v)   (((v) << 7) & BM_CCM_ANALOG_PLL_ENET_TOG_HALF_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field DOUBLE_LF (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_LF      8
#define BM_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_LF      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_LF(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_LF)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_LF(v)   (((v) << 8) & BM_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_LF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field HALF_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_HALF_CP      9
#define BM_CCM_ANALOG_PLL_ENET_TOG_HALF_CP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_HALF_CP(v)   ((((reg32_t) v) << 9) & BM_CCM_ANALOG_PLL_ENET_TOG_HALF_CP)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_HALF_CP(v)   (((v) << 9) & BM_CCM_ANALOG_PLL_ENET_TOG_HALF_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field DOUBLE_CP (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_CP      10
#define BM_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_CP      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_CP(v)   ((((reg32_t) v) << 10) & BM_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_CP)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_CP(v)   (((v) << 10) & BM_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_CP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field HOLD_RING_OFF (RW)
 *
 * Analog debug bit
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_HOLD_RING_OFF      11
#define BM_CCM_ANALOG_PLL_ENET_TOG_HOLD_RING_OFF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_HOLD_RING_OFF(v)   ((((reg32_t) v) << 11) & BM_CCM_ANALOG_PLL_ENET_TOG_HOLD_RING_OFF)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_HOLD_RING_OFF(v)   (((v) << 11) & BM_CCM_ANALOG_PLL_ENET_TOG_HOLD_RING_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field POWERDOWN (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_POWERDOWN      12
#define BM_CCM_ANALOG_PLL_ENET_TOG_POWERDOWN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_POWERDOWN(v)   ((((reg32_t) v) << 12) & BM_CCM_ANALOG_PLL_ENET_TOG_POWERDOWN)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_POWERDOWN(v)   (((v) << 12) & BM_CCM_ANALOG_PLL_ENET_TOG_POWERDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field ENABLE (RW)
 *
 * Enable the ethernet clock output.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_ENABLE      13
#define BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_ENABLE(v)   ((((reg32_t) v) << 13) & BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_ENABLE(v)   (((v) << 13) & BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field BYPASS_CLK_SRC (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC      14
#define BM_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << 14) & BM_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC(v)   (((v) << 14) & BM_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC__OSC_24M    0x0
#define BV_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC__ANACLK_1    0x1
#define BV_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC__ANACLK_2    0x2
#define BV_CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC__XOR    0x3

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field BYPASS (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_BYPASS      16
#define BM_CCM_ANALOG_PLL_ENET_TOG_BYPASS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_BYPASS(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PLL_ENET_TOG_BYPASS)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_BYPASS(v)   (((v) << 16) & BM_CCM_ANALOG_PLL_ENET_TOG_BYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field PFD_OFFSET_EN (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_PFD_OFFSET_EN      18
#define BM_CCM_ANALOG_PLL_ENET_TOG_PFD_OFFSET_EN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_PFD_OFFSET_EN(v)   ((((reg32_t) v) << 18) & BM_CCM_ANALOG_PLL_ENET_TOG_PFD_OFFSET_EN)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_PFD_OFFSET_EN(v)   (((v) << 18) & BM_CCM_ANALOG_PLL_ENET_TOG_PFD_OFFSET_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field ENABLE_PCIE (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_ENABLE_PCIE      19
#define BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE_PCIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_ENABLE_PCIE(v)   ((((reg32_t) v) << 19) & BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE_PCIE)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_ENABLE_PCIE(v)   (((v) << 19) & BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PCIE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_ENABLE_PCIE(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, ENABLE_PCIE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field ENABLE_SATA (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_ENABLE_SATA      20
#define BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE_SATA      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PLL_ENET_TOG_ENABLE_SATA(v)   ((((reg32_t) v) << 20) & BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE_SATA)
#else
#define BF_CCM_ANALOG_PLL_ENET_TOG_ENABLE_SATA(v)   (((v) << 20) & BM_CCM_ANALOG_PLL_ENET_TOG_ENABLE_SATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_SATA field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_TOG_ENABLE_SATA(v)   BF_CS1(CCM_ANALOG_PLL_ENET_TOG, ENABLE_SATA, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET_TOG, field LOCK (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_ENET_TOG_LOCK      31
#define BM_CCM_ANALOG_PLL_ENET_TOG_LOCK      0x80000000

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
 * @brief HW_CCM_ANALOG_PFD_480_SET - 480MHz Clock Phase Fractional Divider Control Register _SET (RW)
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
} hw_ccm_analog_pfd_480_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_480_SET register
 */
#define HW_CCM_ANALOG_PFD_480_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0xf4)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_480_SET           (*(volatile hw_ccm_analog_pfd_480_set_t *) HW_CCM_ANALOG_PFD_480_SET_ADDR)
#define HW_CCM_ANALOG_PFD_480_SET_RD()      (HW_CCM_ANALOG_PFD_480_SET.U)
#define HW_CCM_ANALOG_PFD_480_SET_WR(v)     (HW_CCM_ANALOG_PFD_480_SET.U = (v))
#define HW_CCM_ANALOG_PFD_480_SET_SET(v)    (HW_CCM_ANALOG_PFD_480_SET_WR(HW_CCM_ANALOG_PFD_480_SET_RD() |  (v)))
#define HW_CCM_ANALOG_PFD_480_SET_CLR(v)    (HW_CCM_ANALOG_PFD_480_SET_WR(HW_CCM_ANALOG_PFD_480_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_PFD_480_SET_TOG(v)    (HW_CCM_ANALOG_PFD_480_SET_WR(HW_CCM_ANALOG_PFD_480_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_480_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD0_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD0_FRAC      0
#define BM_CCM_ANALOG_PFD_480_SET_PFD0_FRAC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_SET_PFD0_FRAC(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PFD_480_SET_PFD0_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_SET_PFD0_FRAC(v)   (((v) << 0) & BM_CCM_ANALOG_PFD_480_SET_PFD0_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_SET_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_SET, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD0_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD0_STABLE      6
#define BM_CCM_ANALOG_PFD_480_SET_PFD0_STABLE      0x00000040

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD0_CLKGATE (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE      7
#define BM_CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE(v)   (((v) << 7) & BM_CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_SET, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD1_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD1_FRAC      8
#define BM_CCM_ANALOG_PFD_480_SET_PFD1_FRAC      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_SET_PFD1_FRAC(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PFD_480_SET_PFD1_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_SET_PFD1_FRAC(v)   (((v) << 8) & BM_CCM_ANALOG_PFD_480_SET_PFD1_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_SET_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_SET, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD1_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD1_STABLE      14
#define BM_CCM_ANALOG_PFD_480_SET_PFD1_STABLE      0x00004000

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD1_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE      15
#define BM_CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE(v)   (((v) << 15) & BM_CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_SET, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD2_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD2_FRAC      16
#define BM_CCM_ANALOG_PFD_480_SET_PFD2_FRAC      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_SET_PFD2_FRAC(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PFD_480_SET_PFD2_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_SET_PFD2_FRAC(v)   (((v) << 16) & BM_CCM_ANALOG_PFD_480_SET_PFD2_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_SET_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_SET, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD2_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD2_STABLE      22
#define BM_CCM_ANALOG_PFD_480_SET_PFD2_STABLE      0x00400000

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD2_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE      23
#define BM_CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE(v)   (((v) << 23) & BM_CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_SET, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD3_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD3_FRAC      24
#define BM_CCM_ANALOG_PFD_480_SET_PFD3_FRAC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_SET_PFD3_FRAC(v)   ((((reg32_t) v) << 24) & BM_CCM_ANALOG_PFD_480_SET_PFD3_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_SET_PFD3_FRAC(v)   (((v) << 24) & BM_CCM_ANALOG_PFD_480_SET_PFD3_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_SET_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_SET, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD3_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD3_STABLE      30
#define BM_CCM_ANALOG_PFD_480_SET_PFD3_STABLE      0x40000000

/* --- Register HW_CCM_ANALOG_PFD_480_SET, field PFD3_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE      31
#define BM_CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE(v)   ((((reg32_t) v) << 31) & BM_CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE(v)   (((v) << 31) & BM_CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_SET, PFD3_CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_480_CLR - 480MHz Clock Phase Fractional Divider Control Register _CLR (RW)
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
} hw_ccm_analog_pfd_480_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_480_CLR register
 */
#define HW_CCM_ANALOG_PFD_480_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_480_CLR           (*(volatile hw_ccm_analog_pfd_480_clr_t *) HW_CCM_ANALOG_PFD_480_CLR_ADDR)
#define HW_CCM_ANALOG_PFD_480_CLR_RD()      (HW_CCM_ANALOG_PFD_480_CLR.U)
#define HW_CCM_ANALOG_PFD_480_CLR_WR(v)     (HW_CCM_ANALOG_PFD_480_CLR.U = (v))
#define HW_CCM_ANALOG_PFD_480_CLR_SET(v)    (HW_CCM_ANALOG_PFD_480_CLR_WR(HW_CCM_ANALOG_PFD_480_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_PFD_480_CLR_CLR(v)    (HW_CCM_ANALOG_PFD_480_CLR_WR(HW_CCM_ANALOG_PFD_480_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_PFD_480_CLR_TOG(v)    (HW_CCM_ANALOG_PFD_480_CLR_WR(HW_CCM_ANALOG_PFD_480_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_480_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD0_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD0_FRAC      0
#define BM_CCM_ANALOG_PFD_480_CLR_PFD0_FRAC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_CLR_PFD0_FRAC(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PFD_480_CLR_PFD0_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_CLR_PFD0_FRAC(v)   (((v) << 0) & BM_CCM_ANALOG_PFD_480_CLR_PFD0_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_CLR_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_CLR, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD0_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD0_STABLE      6
#define BM_CCM_ANALOG_PFD_480_CLR_PFD0_STABLE      0x00000040

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD0_CLKGATE (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE      7
#define BM_CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE(v)   (((v) << 7) & BM_CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_CLR, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD1_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD1_FRAC      8
#define BM_CCM_ANALOG_PFD_480_CLR_PFD1_FRAC      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_CLR_PFD1_FRAC(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PFD_480_CLR_PFD1_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_CLR_PFD1_FRAC(v)   (((v) << 8) & BM_CCM_ANALOG_PFD_480_CLR_PFD1_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_CLR_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_CLR, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD1_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD1_STABLE      14
#define BM_CCM_ANALOG_PFD_480_CLR_PFD1_STABLE      0x00004000

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD1_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE      15
#define BM_CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE(v)   (((v) << 15) & BM_CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_CLR, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD2_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD2_FRAC      16
#define BM_CCM_ANALOG_PFD_480_CLR_PFD2_FRAC      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_CLR_PFD2_FRAC(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PFD_480_CLR_PFD2_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_CLR_PFD2_FRAC(v)   (((v) << 16) & BM_CCM_ANALOG_PFD_480_CLR_PFD2_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_CLR_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_CLR, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD2_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD2_STABLE      22
#define BM_CCM_ANALOG_PFD_480_CLR_PFD2_STABLE      0x00400000

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD2_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE      23
#define BM_CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE(v)   (((v) << 23) & BM_CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_CLR, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD3_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD3_FRAC      24
#define BM_CCM_ANALOG_PFD_480_CLR_PFD3_FRAC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_CLR_PFD3_FRAC(v)   ((((reg32_t) v) << 24) & BM_CCM_ANALOG_PFD_480_CLR_PFD3_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_CLR_PFD3_FRAC(v)   (((v) << 24) & BM_CCM_ANALOG_PFD_480_CLR_PFD3_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_CLR_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_CLR, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD3_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD3_STABLE      30
#define BM_CCM_ANALOG_PFD_480_CLR_PFD3_STABLE      0x40000000

/* --- Register HW_CCM_ANALOG_PFD_480_CLR, field PFD3_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE      31
#define BM_CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE(v)   ((((reg32_t) v) << 31) & BM_CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE(v)   (((v) << 31) & BM_CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_CLR, PFD3_CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_480_TOG - 480MHz Clock Phase Fractional Divider Control Register _TOG (RW)
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
} hw_ccm_analog_pfd_480_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_480_TOG register
 */
#define HW_CCM_ANALOG_PFD_480_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_480_TOG           (*(volatile hw_ccm_analog_pfd_480_tog_t *) HW_CCM_ANALOG_PFD_480_TOG_ADDR)
#define HW_CCM_ANALOG_PFD_480_TOG_RD()      (HW_CCM_ANALOG_PFD_480_TOG.U)
#define HW_CCM_ANALOG_PFD_480_TOG_WR(v)     (HW_CCM_ANALOG_PFD_480_TOG.U = (v))
#define HW_CCM_ANALOG_PFD_480_TOG_SET(v)    (HW_CCM_ANALOG_PFD_480_TOG_WR(HW_CCM_ANALOG_PFD_480_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_PFD_480_TOG_CLR(v)    (HW_CCM_ANALOG_PFD_480_TOG_WR(HW_CCM_ANALOG_PFD_480_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_PFD_480_TOG_TOG(v)    (HW_CCM_ANALOG_PFD_480_TOG_WR(HW_CCM_ANALOG_PFD_480_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_480_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD0_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD0_FRAC      0
#define BM_CCM_ANALOG_PFD_480_TOG_PFD0_FRAC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_TOG_PFD0_FRAC(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PFD_480_TOG_PFD0_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_TOG_PFD0_FRAC(v)   (((v) << 0) & BM_CCM_ANALOG_PFD_480_TOG_PFD0_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_TOG_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_TOG, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD0_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD0_STABLE      6
#define BM_CCM_ANALOG_PFD_480_TOG_PFD0_STABLE      0x00000040

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD0_CLKGATE (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE      7
#define BM_CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE(v)   (((v) << 7) & BM_CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_TOG, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD1_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD1_FRAC      8
#define BM_CCM_ANALOG_PFD_480_TOG_PFD1_FRAC      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_TOG_PFD1_FRAC(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PFD_480_TOG_PFD1_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_TOG_PFD1_FRAC(v)   (((v) << 8) & BM_CCM_ANALOG_PFD_480_TOG_PFD1_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_TOG_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_TOG, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD1_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD1_STABLE      14
#define BM_CCM_ANALOG_PFD_480_TOG_PFD1_STABLE      0x00004000

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD1_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE      15
#define BM_CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE(v)   (((v) << 15) & BM_CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_TOG, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD2_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD2_FRAC      16
#define BM_CCM_ANALOG_PFD_480_TOG_PFD2_FRAC      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_TOG_PFD2_FRAC(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PFD_480_TOG_PFD2_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_TOG_PFD2_FRAC(v)   (((v) << 16) & BM_CCM_ANALOG_PFD_480_TOG_PFD2_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_TOG_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_TOG, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD2_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD2_STABLE      22
#define BM_CCM_ANALOG_PFD_480_TOG_PFD2_STABLE      0x00400000

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD2_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE      23
#define BM_CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE(v)   (((v) << 23) & BM_CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_TOG, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD3_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD3_FRAC      24
#define BM_CCM_ANALOG_PFD_480_TOG_PFD3_FRAC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_TOG_PFD3_FRAC(v)   ((((reg32_t) v) << 24) & BM_CCM_ANALOG_PFD_480_TOG_PFD3_FRAC)
#else
#define BF_CCM_ANALOG_PFD_480_TOG_PFD3_FRAC(v)   (((v) << 24) & BM_CCM_ANALOG_PFD_480_TOG_PFD3_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_TOG_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480_TOG, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD3_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD3_STABLE      30
#define BM_CCM_ANALOG_PFD_480_TOG_PFD3_STABLE      0x40000000

/* --- Register HW_CCM_ANALOG_PFD_480_TOG, field PFD3_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE      31
#define BM_CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE(v)   ((((reg32_t) v) << 31) & BM_CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE(v)   (((v) << 31) & BM_CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480_TOG, PFD3_CLKGATE, v)
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

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_528_SET - 528MHz Clock Phase Fractional Divider Control Register _SET (RW)
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
} hw_ccm_analog_pfd_528_set_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_528_SET register
 */
#define HW_CCM_ANALOG_PFD_528_SET_ADDR      (REGS_CCM_ANALOG_BASE + 0x104)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_528_SET           (*(volatile hw_ccm_analog_pfd_528_set_t *) HW_CCM_ANALOG_PFD_528_SET_ADDR)
#define HW_CCM_ANALOG_PFD_528_SET_RD()      (HW_CCM_ANALOG_PFD_528_SET.U)
#define HW_CCM_ANALOG_PFD_528_SET_WR(v)     (HW_CCM_ANALOG_PFD_528_SET.U = (v))
#define HW_CCM_ANALOG_PFD_528_SET_SET(v)    (HW_CCM_ANALOG_PFD_528_SET_WR(HW_CCM_ANALOG_PFD_528_SET_RD() |  (v)))
#define HW_CCM_ANALOG_PFD_528_SET_CLR(v)    (HW_CCM_ANALOG_PFD_528_SET_WR(HW_CCM_ANALOG_PFD_528_SET_RD() & ~(v)))
#define HW_CCM_ANALOG_PFD_528_SET_TOG(v)    (HW_CCM_ANALOG_PFD_528_SET_WR(HW_CCM_ANALOG_PFD_528_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_528_SET bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD0_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD0_FRAC      0
#define BM_CCM_ANALOG_PFD_528_SET_PFD0_FRAC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_SET_PFD0_FRAC(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PFD_528_SET_PFD0_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_SET_PFD0_FRAC(v)   (((v) << 0) & BM_CCM_ANALOG_PFD_528_SET_PFD0_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_SET_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_SET, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD0_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD0_STABLE      6
#define BM_CCM_ANALOG_PFD_528_SET_PFD0_STABLE      0x00000040

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD0_CLKGATE (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE      7
#define BM_CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE(v)   (((v) << 7) & BM_CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_SET, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD1_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD1_FRAC      8
#define BM_CCM_ANALOG_PFD_528_SET_PFD1_FRAC      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_SET_PFD1_FRAC(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PFD_528_SET_PFD1_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_SET_PFD1_FRAC(v)   (((v) << 8) & BM_CCM_ANALOG_PFD_528_SET_PFD1_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_SET_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_SET, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD1_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD1_STABLE      14
#define BM_CCM_ANALOG_PFD_528_SET_PFD1_STABLE      0x00004000

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD1_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE      15
#define BM_CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE(v)   (((v) << 15) & BM_CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_SET, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD2_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD2_FRAC      16
#define BM_CCM_ANALOG_PFD_528_SET_PFD2_FRAC      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_SET_PFD2_FRAC(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PFD_528_SET_PFD2_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_SET_PFD2_FRAC(v)   (((v) << 16) & BM_CCM_ANALOG_PFD_528_SET_PFD2_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_SET_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_SET, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD2_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD2_STABLE      22
#define BM_CCM_ANALOG_PFD_528_SET_PFD2_STABLE      0x00400000

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD2_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE      23
#define BM_CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE(v)   (((v) << 23) & BM_CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_SET, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD3_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD3_FRAC      24
#define BM_CCM_ANALOG_PFD_528_SET_PFD3_FRAC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_SET_PFD3_FRAC(v)   ((((reg32_t) v) << 24) & BM_CCM_ANALOG_PFD_528_SET_PFD3_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_SET_PFD3_FRAC(v)   (((v) << 24) & BM_CCM_ANALOG_PFD_528_SET_PFD3_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_SET_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_SET, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD3_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD3_STABLE      30
#define BM_CCM_ANALOG_PFD_528_SET_PFD3_STABLE      0x40000000

/* --- Register HW_CCM_ANALOG_PFD_528_SET, field PFD3_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE      31
#define BM_CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE(v)   ((((reg32_t) v) << 31) & BM_CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE(v)   (((v) << 31) & BM_CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_SET, PFD3_CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_528_CLR - 528MHz Clock Phase Fractional Divider Control Register _CLR (RW)
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
} hw_ccm_analog_pfd_528_clr_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_528_CLR register
 */
#define HW_CCM_ANALOG_PFD_528_CLR_ADDR      (REGS_CCM_ANALOG_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_528_CLR           (*(volatile hw_ccm_analog_pfd_528_clr_t *) HW_CCM_ANALOG_PFD_528_CLR_ADDR)
#define HW_CCM_ANALOG_PFD_528_CLR_RD()      (HW_CCM_ANALOG_PFD_528_CLR.U)
#define HW_CCM_ANALOG_PFD_528_CLR_WR(v)     (HW_CCM_ANALOG_PFD_528_CLR.U = (v))
#define HW_CCM_ANALOG_PFD_528_CLR_SET(v)    (HW_CCM_ANALOG_PFD_528_CLR_WR(HW_CCM_ANALOG_PFD_528_CLR_RD() |  (v)))
#define HW_CCM_ANALOG_PFD_528_CLR_CLR(v)    (HW_CCM_ANALOG_PFD_528_CLR_WR(HW_CCM_ANALOG_PFD_528_CLR_RD() & ~(v)))
#define HW_CCM_ANALOG_PFD_528_CLR_TOG(v)    (HW_CCM_ANALOG_PFD_528_CLR_WR(HW_CCM_ANALOG_PFD_528_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_528_CLR bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD0_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD0_FRAC      0
#define BM_CCM_ANALOG_PFD_528_CLR_PFD0_FRAC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_CLR_PFD0_FRAC(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PFD_528_CLR_PFD0_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_CLR_PFD0_FRAC(v)   (((v) << 0) & BM_CCM_ANALOG_PFD_528_CLR_PFD0_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_CLR_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_CLR, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD0_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD0_STABLE      6
#define BM_CCM_ANALOG_PFD_528_CLR_PFD0_STABLE      0x00000040

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD0_CLKGATE (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE      7
#define BM_CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE(v)   (((v) << 7) & BM_CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_CLR, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD1_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD1_FRAC      8
#define BM_CCM_ANALOG_PFD_528_CLR_PFD1_FRAC      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_CLR_PFD1_FRAC(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PFD_528_CLR_PFD1_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_CLR_PFD1_FRAC(v)   (((v) << 8) & BM_CCM_ANALOG_PFD_528_CLR_PFD1_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_CLR_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_CLR, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD1_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD1_STABLE      14
#define BM_CCM_ANALOG_PFD_528_CLR_PFD1_STABLE      0x00004000

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD1_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE      15
#define BM_CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE(v)   (((v) << 15) & BM_CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_CLR, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD2_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD2_FRAC      16
#define BM_CCM_ANALOG_PFD_528_CLR_PFD2_FRAC      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_CLR_PFD2_FRAC(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PFD_528_CLR_PFD2_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_CLR_PFD2_FRAC(v)   (((v) << 16) & BM_CCM_ANALOG_PFD_528_CLR_PFD2_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_CLR_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_CLR, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD2_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD2_STABLE      22
#define BM_CCM_ANALOG_PFD_528_CLR_PFD2_STABLE      0x00400000

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD2_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE      23
#define BM_CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE(v)   (((v) << 23) & BM_CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_CLR, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD3_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD3_FRAC      24
#define BM_CCM_ANALOG_PFD_528_CLR_PFD3_FRAC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_CLR_PFD3_FRAC(v)   ((((reg32_t) v) << 24) & BM_CCM_ANALOG_PFD_528_CLR_PFD3_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_CLR_PFD3_FRAC(v)   (((v) << 24) & BM_CCM_ANALOG_PFD_528_CLR_PFD3_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_CLR_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_CLR, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD3_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD3_STABLE      30
#define BM_CCM_ANALOG_PFD_528_CLR_PFD3_STABLE      0x40000000

/* --- Register HW_CCM_ANALOG_PFD_528_CLR, field PFD3_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE      31
#define BM_CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE(v)   ((((reg32_t) v) << 31) & BM_CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE(v)   (((v) << 31) & BM_CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_CLR, PFD3_CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_528_TOG - 528MHz Clock Phase Fractional Divider Control Register _TOG (RW)
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
} hw_ccm_analog_pfd_528_tog_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_528_TOG register
 */
#define HW_CCM_ANALOG_PFD_528_TOG_ADDR      (REGS_CCM_ANALOG_BASE + 0x10c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_528_TOG           (*(volatile hw_ccm_analog_pfd_528_tog_t *) HW_CCM_ANALOG_PFD_528_TOG_ADDR)
#define HW_CCM_ANALOG_PFD_528_TOG_RD()      (HW_CCM_ANALOG_PFD_528_TOG.U)
#define HW_CCM_ANALOG_PFD_528_TOG_WR(v)     (HW_CCM_ANALOG_PFD_528_TOG.U = (v))
#define HW_CCM_ANALOG_PFD_528_TOG_SET(v)    (HW_CCM_ANALOG_PFD_528_TOG_WR(HW_CCM_ANALOG_PFD_528_TOG_RD() |  (v)))
#define HW_CCM_ANALOG_PFD_528_TOG_CLR(v)    (HW_CCM_ANALOG_PFD_528_TOG_WR(HW_CCM_ANALOG_PFD_528_TOG_RD() & ~(v)))
#define HW_CCM_ANALOG_PFD_528_TOG_TOG(v)    (HW_CCM_ANALOG_PFD_528_TOG_WR(HW_CCM_ANALOG_PFD_528_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_528_TOG bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD0_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD0_FRAC      0
#define BM_CCM_ANALOG_PFD_528_TOG_PFD0_FRAC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_TOG_PFD0_FRAC(v)   ((((reg32_t) v) << 0) & BM_CCM_ANALOG_PFD_528_TOG_PFD0_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_TOG_PFD0_FRAC(v)   (((v) << 0) & BM_CCM_ANALOG_PFD_528_TOG_PFD0_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_TOG_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_TOG, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD0_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD0_STABLE      6
#define BM_CCM_ANALOG_PFD_528_TOG_PFD0_STABLE      0x00000040

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD0_CLKGATE (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE      7
#define BM_CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE(v)   ((((reg32_t) v) << 7) & BM_CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE(v)   (((v) << 7) & BM_CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_TOG, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD1_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD1_FRAC      8
#define BM_CCM_ANALOG_PFD_528_TOG_PFD1_FRAC      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_TOG_PFD1_FRAC(v)   ((((reg32_t) v) << 8) & BM_CCM_ANALOG_PFD_528_TOG_PFD1_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_TOG_PFD1_FRAC(v)   (((v) << 8) & BM_CCM_ANALOG_PFD_528_TOG_PFD1_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_TOG_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_TOG, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD1_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD1_STABLE      14
#define BM_CCM_ANALOG_PFD_528_TOG_PFD1_STABLE      0x00004000

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD1_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE      15
#define BM_CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE(v)   ((((reg32_t) v) << 15) & BM_CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE(v)   (((v) << 15) & BM_CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_TOG, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD2_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD2_FRAC      16
#define BM_CCM_ANALOG_PFD_528_TOG_PFD2_FRAC      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_TOG_PFD2_FRAC(v)   ((((reg32_t) v) << 16) & BM_CCM_ANALOG_PFD_528_TOG_PFD2_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_TOG_PFD2_FRAC(v)   (((v) << 16) & BM_CCM_ANALOG_PFD_528_TOG_PFD2_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_TOG_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_TOG, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD2_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD2_STABLE      22
#define BM_CCM_ANALOG_PFD_528_TOG_PFD2_STABLE      0x00400000

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD2_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE      23
#define BM_CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE(v)   ((((reg32_t) v) << 23) & BM_CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE(v)   (((v) << 23) & BM_CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_TOG, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD3_FRAC (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD3_FRAC      24
#define BM_CCM_ANALOG_PFD_528_TOG_PFD3_FRAC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_TOG_PFD3_FRAC(v)   ((((reg32_t) v) << 24) & BM_CCM_ANALOG_PFD_528_TOG_PFD3_FRAC)
#else
#define BF_CCM_ANALOG_PFD_528_TOG_PFD3_FRAC(v)   (((v) << 24) & BM_CCM_ANALOG_PFD_528_TOG_PFD3_FRAC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_TOG_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528_TOG, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD3_STABLE (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD3_STABLE      30
#define BM_CCM_ANALOG_PFD_528_TOG_PFD3_STABLE      0x40000000

/* --- Register HW_CCM_ANALOG_PFD_528_TOG, field PFD3_CLKGATE (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE      31
#define BM_CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE(v)   ((((reg32_t) v) << 31) & BM_CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE)
#else
#define BF_CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE(v)   (((v) << 31) & BM_CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528_TOG, PFD3_CLKGATE, v)
#endif


/*!
 * @brief All CCM_ANALOG module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_ccm_analog_pll_sys_t PLL_SYS; //!< Analog System PLL control Register
    volatile hw_ccm_analog_pll_sys_set_t PLL_SYS_SET; //!< Analog System PLL control Register _SET
    volatile hw_ccm_analog_pll_sys_clr_t PLL_SYS_CLR; //!< Analog System PLL control Register _CLR
    volatile hw_ccm_analog_pll_sys_tog_t PLL_SYS_TOG; //!< Analog System PLL control Register _TOG
    volatile hw_ccm_analog_usbphy0_pll_480_ctrl_t USBPHY0_PLL_480_CTRL; //!< Analog USBPHY0 480MHz PLL Control Register
    volatile hw_ccm_analog_usbphy0_pll_480_ctrl_set_t USBPHY0_PLL_480_CTRL_SET; //!< Analog USBPHY0 480MHz PLL Control Register _SET
    volatile hw_ccm_analog_usbphy0_pll_480_ctrl_clr_t USBPHY0_PLL_480_CTRL_CLR; //!< Analog USBPHY0 480MHz PLL Control Register _CLR
    volatile hw_ccm_analog_usbphy0_pll_480_ctrl_tog_t USBPHY0_PLL_480_CTRL_TOG; //!< Analog USBPHY0 480MHz PLL Control Register _TOG
    volatile hw_ccm_analog_usbphy1_pll_480_ctrl_t USBPHY1_PLL_480_CTRL; //!< Analog USBPHY1 480MHz PLL Control Register
    volatile hw_ccm_analog_usbphy1_pll_480_ctrl_set_t USBPHY1_PLL_480_CTRL_SET; //!< Analog USBPHY1 480MHz PLL Control Register _SET
    volatile hw_ccm_analog_usbphy1_pll_480_ctrl_clr_t USBPHY1_PLL_480_CTRL_CLR; //!< Analog USBPHY1 480MHz PLL Control Register _CLR
    volatile hw_ccm_analog_usbphy1_pll_480_ctrl_tog_t USBPHY1_PLL_480_CTRL_TOG; //!< Analog USBPHY1 480MHz PLL Control Register _TOG
    volatile hw_ccm_analog_pll_528_t PLL_528; //!< Analog 528MHz PLL Control Register
    volatile hw_ccm_analog_pll_528_set_t PLL_528_SET; //!< Analog 528MHz PLL Control Register _SET
    volatile hw_ccm_analog_pll_528_clr_t PLL_528_CLR; //!< Analog 528MHz PLL Control Register _CLR
    volatile hw_ccm_analog_pll_528_tog_t PLL_528_TOG; //!< Analog 528MHz PLL Control Register _TOG
    volatile hw_ccm_analog_pll_528_ss_t PLL_528_SS; //!< 528MHz PLL Spread Spectrum Register.
    reg32_t _reserved0[3];
    volatile hw_ccm_analog_pll_528_num_t PLL_528_NUM; //!< Numerator of 528MHz PLL Fractional Loop Divider Register
    reg32_t _reserved1[3];
    volatile hw_ccm_analog_pll_528_denom_t PLL_528_DENOM; //!< Denominator of 528MHz PLL Fractional Loop Divider Register
    reg32_t _reserved2[3];
    volatile hw_ccm_analog_pll_audio_t PLL_AUDIO; //!< Analog Audio PLL control Register
    volatile hw_ccm_analog_pll_audio_set_t PLL_AUDIO_SET; //!< Analog Audio PLL control Register _SET
    volatile hw_ccm_analog_pll_audio_clr_t PLL_AUDIO_CLR; //!< Analog Audio PLL control Register _CLR
    volatile hw_ccm_analog_pll_audio_tog_t PLL_AUDIO_TOG; //!< Analog Audio PLL control Register _TOG
    volatile hw_ccm_analog_pll_audio_num_t PLL_AUDIO_NUM; //!< Numerator of Audio PLL Fractional Loop Divider Register
    reg32_t _reserved3[3];
    volatile hw_ccm_analog_pll_audio_denom_t PLL_AUDIO_DENOM; //!< Denominator of Audio PLL Fractional Loop Divider Register
    reg32_t _reserved4[3];
    volatile hw_ccm_analog_pll_video_t PLL_VIDEO; //!< Analog Video PLL control Register
    volatile hw_ccm_analog_pll_video_set_t PLL_VIDEO_SET; //!< Analog Video PLL control Register _SET
    volatile hw_ccm_analog_pll_video_clr_t PLL_VIDEO_CLR; //!< Analog Video PLL control Register _CLR
    volatile hw_ccm_analog_pll_video_tog_t PLL_VIDEO_TOG; //!< Analog Video PLL control Register _TOG
    volatile hw_ccm_analog_pll_video_num_t PLL_VIDEO_NUM; //!< Numerator of Video PLL Fractional Loop Divider Register
    reg32_t _reserved5[3];
    volatile hw_ccm_analog_pll_video_denom_t PLL_VIDEO_DENOM; //!< Denominator of Video PLL Fractional Loop Divider Register
    reg32_t _reserved6[3];
    volatile hw_ccm_analog_pll_mlb_t PLL_MLB; //!< MLB PLL Control Register
    volatile hw_ccm_analog_pll_mlb_set_t PLL_MLB_SET; //!< MLB PLL Control Register _SET
    volatile hw_ccm_analog_pll_mlb_clr_t PLL_MLB_CLR; //!< MLB PLL Control Register _CLR
    volatile hw_ccm_analog_pll_mlb_tog_t PLL_MLB_TOG; //!< MLB PLL Control Register _TOG
    volatile hw_ccm_analog_pll_enet_t PLL_ENET; //!< Analog ENET PLL Control Register
    volatile hw_ccm_analog_pll_enet_set_t PLL_ENET_SET; //!< Analog ENET PLL Control Register _SET
    volatile hw_ccm_analog_pll_enet_clr_t PLL_ENET_CLR; //!< Analog ENET PLL Control Register _CLR
    volatile hw_ccm_analog_pll_enet_tog_t PLL_ENET_TOG; //!< Analog ENET PLL Control Register _TOG
    volatile hw_ccm_analog_pfd_480_t PFD_480; //!< 480MHz Clock Phase Fractional Divider Control Register
    volatile hw_ccm_analog_pfd_480_set_t PFD_480_SET; //!< 480MHz Clock Phase Fractional Divider Control Register _SET
    volatile hw_ccm_analog_pfd_480_clr_t PFD_480_CLR; //!< 480MHz Clock Phase Fractional Divider Control Register _CLR
    volatile hw_ccm_analog_pfd_480_tog_t PFD_480_TOG; //!< 480MHz Clock Phase Fractional Divider Control Register _TOG
    volatile hw_ccm_analog_pfd_528_t PFD_528; //!< 528MHz Clock Phase Fractional Divider Control Register
    volatile hw_ccm_analog_pfd_528_set_t PFD_528_SET; //!< 528MHz Clock Phase Fractional Divider Control Register _SET
    volatile hw_ccm_analog_pfd_528_clr_t PFD_528_CLR; //!< 528MHz Clock Phase Fractional Divider Control Register _CLR
    volatile hw_ccm_analog_pfd_528_tog_t PFD_528_TOG; //!< 528MHz Clock Phase Fractional Divider Control Register _TOG
} hw_ccm_analog_t;
#endif

//! @brief Macro to access all CCM_ANALOG registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CCM_ANALOG(0)</code>.
#define HW_CCM_ANALOG     (*(volatile hw_ccm_analog_t *) REGS_CCM_ANALOG_BASE)


#endif // _CCM_ANALOG_H
