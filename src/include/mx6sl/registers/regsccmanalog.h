/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_CCM_ANALOG_REGISTERS_H__
#define __HW_CCM_ANALOG_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL CCM_ANALOG registers defined in this header file.
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
 * - hw_ccm_analog_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_CCM_ANALOG_BASE
#define HW_CCM_ANALOG_INSTANCE_COUNT (1) //!< Number of instances of the CCM_ANALOG module.
#define REGS_CCM_ANALOG_BASE (0x020c8000) //!< Base address for CCM_ANALOG.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_SYS - Analog System PLL control Register (RW)
 *
 * Reset value: 0x00013042
 *
 * The control register provides control for the system PLL.
 */
typedef union _hw_ccm_analog_pll_sys
{
    reg32_t U;
    struct _hw_ccm_analog_pll_sys_bitfields
    {
        unsigned DIV_SELECT : 7; //!< [6:0] This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin * div_select/2.0.
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale.
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog debug bit.
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enable the clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned LVDS_SEL : 1; //!< [17] Analog Debug Bit
        unsigned LVDS_24MHZ_SEL : 1; //!< [18] Analog Debug Bit
        unsigned PLL_SEL : 1; //!< [19] Reserved
        unsigned RESERVED0 : 11; //!< [30:20] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_sys_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_SYS register
 */
#define HW_CCM_ANALOG_PLL_SYS_ADDR      (REGS_CCM_ANALOG_BASE + 0x0)
#define HW_CCM_ANALOG_PLL_SYS_SET_ADDR  (HW_CCM_ANALOG_PLL_SYS_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_SYS_CLR_ADDR  (HW_CCM_ANALOG_PLL_SYS_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_SYS_TOG_ADDR  (HW_CCM_ANALOG_PLL_SYS_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_SYS           (*(volatile hw_ccm_analog_pll_sys_t *) HW_CCM_ANALOG_PLL_SYS_ADDR)
#define HW_CCM_ANALOG_PLL_SYS_RD()      (HW_CCM_ANALOG_PLL_SYS.U)
#define HW_CCM_ANALOG_PLL_SYS_WR(v)     (HW_CCM_ANALOG_PLL_SYS.U = (v))
#define HW_CCM_ANALOG_PLL_SYS_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_SYS_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_SYS_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_SYS_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_SYS_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_SYS_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_SYS bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DIV_SELECT[6:0] (RW)
 *
 * This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin *
 * div_select/2.0.
 */

#define BP_CCM_ANALOG_PLL_SYS_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_SYS_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_SYS_DIV_SELECT      (0x0000007f)  //!< Bit mask for CCM_ANALOG_PLL_SYS_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_SYS_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_SYS_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_DIV_SELECT) >> BP_CCM_ANALOG_PLL_SYS_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_SYS_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_DIV_SELECT) & BM_CCM_ANALOG_PLL_SYS_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_SYS_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_DIV_SELECT) & BM_CCM_ANALOG_PLL_SYS_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_SYS_HALF_LF.
#define BM_CCM_ANALOG_PLL_SYS_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_SYS_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_SYS_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_SYS_HALF_LF(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_HALF_LF) >> BP_CCM_ANALOG_PLL_SYS_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HALF_LF.
#define BF_CCM_ANALOG_PLL_SYS_HALF_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_HALF_LF) & BM_CCM_ANALOG_PLL_SYS_HALF_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HALF_LF.
#define BF_CCM_ANALOG_PLL_SYS_HALF_LF(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_HALF_LF) & BM_CCM_ANALOG_PLL_SYS_HALF_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_SYS_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_SYS_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_SYS_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_SYS_DOUBLE_LF(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_SYS_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_DOUBLE_LF) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_LF(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_DOUBLE_LF) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_SYS_HALF_CP.
#define BM_CCM_ANALOG_PLL_SYS_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_SYS_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_SYS_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_SYS_HALF_CP(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_HALF_CP) >> BP_CCM_ANALOG_PLL_SYS_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HALF_CP.
#define BF_CCM_ANALOG_PLL_SYS_HALF_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_HALF_CP) & BM_CCM_ANALOG_PLL_SYS_HALF_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HALF_CP.
#define BF_CCM_ANALOG_PLL_SYS_HALF_CP(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_HALF_CP) & BM_CCM_ANALOG_PLL_SYS_HALF_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_SYS_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_SYS_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_SYS_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_SYS_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_SYS_DOUBLE_CP(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_SYS_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_DOUBLE_CP) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_CP(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_DOUBLE_CP) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HOLD_RING_OFF[11] (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_SYS_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_SYS_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_SYS_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_SYS_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_SYS_POWERDOWN.
#define BM_CCM_ANALOG_PLL_SYS_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_SYS_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_SYS_POWERDOWN(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_POWERDOWN) >> BP_CCM_ANALOG_PLL_SYS_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_POWERDOWN.
#define BF_CCM_ANALOG_PLL_SYS_POWERDOWN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_POWERDOWN) & BM_CCM_ANALOG_PLL_SYS_POWERDOWN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_POWERDOWN.
#define BF_CCM_ANALOG_PLL_SYS_POWERDOWN(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_POWERDOWN) & BM_CCM_ANALOG_PLL_SYS_POWERDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_SYS, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field ENABLE[13] (RW)
 *
 * Enable the clock output.
 */

#define BP_CCM_ANALOG_PLL_SYS_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_SYS_ENABLE.
#define BM_CCM_ANALOG_PLL_SYS_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_SYS_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_SYS_ENABLE(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_ENABLE) >> BP_CCM_ANALOG_PLL_SYS_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_ENABLE.
#define BF_CCM_ANALOG_PLL_SYS_ENABLE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_ENABLE) & BM_CCM_ANALOG_PLL_SYS_ENABLE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_ENABLE.
#define BF_CCM_ANALOG_PLL_SYS_ENABLE(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_ENABLE) & BM_CCM_ANALOG_PLL_SYS_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_SYS, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_SYS, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__ANACLK_2 (0x2) //!< Select the Anaclk2/2b as source.
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__XOR (0x3) //!< Select the xor of Anaclk1/1b and Anaclk2/2b as source.

/* --- Register HW_CCM_ANALOG_PLL_SYS, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_SYS_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_SYS_BYPASS.
#define BM_CCM_ANALOG_PLL_SYS_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_SYS_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_SYS_BYPASS(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_BYPASS) >> BP_CCM_ANALOG_PLL_SYS_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_BYPASS.
#define BF_CCM_ANALOG_PLL_SYS_BYPASS(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_BYPASS) & BM_CCM_ANALOG_PLL_SYS_BYPASS)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_BYPASS.
#define BF_CCM_ANALOG_PLL_SYS_BYPASS(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_BYPASS) & BM_CCM_ANALOG_PLL_SYS_BYPASS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_SYS, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field LVDS_SEL[17] (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_LVDS_SEL      (17)      //!< Bit position for CCM_ANALOG_PLL_SYS_LVDS_SEL.
#define BM_CCM_ANALOG_PLL_SYS_LVDS_SEL      (0x00020000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_LVDS_SEL.

//! @brief Get value of CCM_ANALOG_PLL_SYS_LVDS_SEL from a register value.
#define BG_CCM_ANALOG_PLL_SYS_LVDS_SEL(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_LVDS_SEL) >> BP_CCM_ANALOG_PLL_SYS_LVDS_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_LVDS_SEL.
#define BF_CCM_ANALOG_PLL_SYS_LVDS_SEL(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_LVDS_SEL) & BM_CCM_ANALOG_PLL_SYS_LVDS_SEL)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_LVDS_SEL.
#define BF_CCM_ANALOG_PLL_SYS_LVDS_SEL(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_LVDS_SEL) & BM_CCM_ANALOG_PLL_SYS_LVDS_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_LVDS_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS, LVDS_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field LVDS_24MHZ_SEL[18] (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL      (18)      //!< Bit position for CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL.
#define BM_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL.

//! @brief Get value of CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL from a register value.
#define BG_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL) >> BP_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL.
#define BF_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL) & BM_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL.
#define BF_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL) & BM_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_24MHZ_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_LVDS_24MHZ_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS, LVDS_24MHZ_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field PLL_SEL[19] (RW)
 *
 * Reserved
 */

#define BP_CCM_ANALOG_PLL_SYS_PLL_SEL      (19)      //!< Bit position for CCM_ANALOG_PLL_SYS_PLL_SEL.
#define BM_CCM_ANALOG_PLL_SYS_PLL_SEL      (0x00080000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_PLL_SEL.

//! @brief Get value of CCM_ANALOG_PLL_SYS_PLL_SEL from a register value.
#define BG_CCM_ANALOG_PLL_SYS_PLL_SEL(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_PLL_SEL) >> BP_CCM_ANALOG_PLL_SYS_PLL_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_PLL_SEL.
#define BF_CCM_ANALOG_PLL_SYS_PLL_SEL(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_SYS_PLL_SEL) & BM_CCM_ANALOG_PLL_SYS_PLL_SEL)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_PLL_SEL.
#define BF_CCM_ANALOG_PLL_SYS_PLL_SEL(v)   (((v) << BP_CCM_ANALOG_PLL_SYS_PLL_SEL) & BM_CCM_ANALOG_PLL_SYS_PLL_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_PLL_SEL(v)   BF_CS1(CCM_ANALOG_PLL_SYS, PLL_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_SYS_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_SYS_LOCK.
#define BM_CCM_ANALOG_PLL_SYS_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_SYS_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_SYS_LOCK(r)   (((r) & BM_CCM_ANALOG_PLL_SYS_LOCK) >> BP_CCM_ANALOG_PLL_SYS_LOCK)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL - Analog USBPHY0 480MHz PLL Control Register (RW)
 *
 * Reset value: 0x00012000
 *
 * The control register provides control for USBPHY0 480MHz PLL.
 */
typedef union _hw_ccm_analog_usbphy0_pll_480_ctrl
{
    reg32_t U;
    struct _hw_ccm_analog_usbphy0_pll_480_ctrl_bitfields
    {
        unsigned DIV_SELECT : 2; //!< [1:0] This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< [5:2] Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< [6] Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set automatically when USBPHYn remote wakeup event occurs.
        unsigned RESERVED1 : 5; //!< [11:7] Always set to zero (0).
        unsigned POWER : 1; //!< [12] Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
        unsigned ENABLE : 1; //!< [13] Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< [30:14] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy0_pll_480_ctrl_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY0_PLL_480_CTRL register
 */
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ADDR      (REGS_CCM_ANALOG_BASE + 0x10)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ADDR  (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ADDR + 0x4)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ADDR  (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ADDR + 0x8)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ADDR  (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL           (*(volatile hw_ccm_analog_usbphy0_pll_480_ctrl_t *) HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ADDR)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_RD()      (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL.U)
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_WR(v)     (HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL.U = (v))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_SET_ADDR) = (v))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY0_PLL_480_CTRL bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field DIV_SELECT[1:0] (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT.
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT      (0x00000003)  //!< Bit mask for CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT) >> BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT.
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT.
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field EN_USB_CLKS[6] (RW)
 *
 * Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted
 * in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set
 * automatically when USBPHYn remote wakeup event occurs.
 *
 * Values:
 * 0 - PLL outputs for USBPHYn off.
 * 1 - PLL outputs for USBPHYn on.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS      (6)      //!< Bit position for CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS.
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS      (0x00000040)  //!< Bit mask for CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS.

//! @brief Get value of CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS from a register value.
#define BG_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS(r)   (((r) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS) >> BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS.
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS(v)   ((((reg32_t) v) << BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS)
#else
//! @brief Format value for bitfield CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS.
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS(v)   (((v) << BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL, EN_USB_CLKS, v)
#endif


/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field POWER[12] (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER      (12)      //!< Bit position for CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER.
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER      (0x00001000)  //!< Bit mask for CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER.

//! @brief Get value of CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER from a register value.
#define BG_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER(r)   (((r) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER) >> BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER.
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER(v)   ((((reg32_t) v) << BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER)
#else
//! @brief Format value for bitfield CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER.
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER(v)   (((v) << BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field ENABLE[13] (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE      (13)      //!< Bit position for CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE.
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE.

//! @brief Get value of CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE from a register value.
#define BG_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE(r)   (((r) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE) >> BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE.
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE)
#else
//! @brief Format value for bitfield CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE.
#define BF_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE(v)   (((v) << BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY0_PLL_480_CTRL_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY0_PLL_480_CTRL, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY0_PLL_480_CTRL, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK      (31)      //!< Bit position for CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK.
#define BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK.

//! @brief Get value of CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK from a register value.
#define BG_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK(r)   (((r) & BM_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK) >> BP_CCM_ANALOG_USBPHY0_PLL_480_CTRL_LOCK)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL - Analog USBPHY1 480MHz PLL Control Register (RW)
 *
 * Reset value: 0x00012000
 *
 * The control register provides control for USBPHY1 480MHz PLL.
 */
typedef union _hw_ccm_analog_usbphy1_pll_480_ctrl
{
    reg32_t U;
    struct _hw_ccm_analog_usbphy1_pll_480_ctrl_bitfields
    {
        unsigned DIV_SELECT : 2; //!< [1:0] This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< [5:2] Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< [6] 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1 are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned RESERVED1 : 5; //!< [11:7] Always set to zero (0).
        unsigned POWER : 1; //!< [12] Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned ENABLE : 1; //!< [13] Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< [30:14] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_usbphy1_pll_480_ctrl_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_USBPHY1_PLL_480_CTRL register
 */
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ADDR      (REGS_CCM_ANALOG_BASE + 0x20)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ADDR  (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ADDR + 0x4)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ADDR  (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ADDR + 0x8)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ADDR  (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL           (*(volatile hw_ccm_analog_usbphy1_pll_480_ctrl_t *) HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ADDR)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_RD()      (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL.U)
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_WR(v)     (HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL.U = (v))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_SET_ADDR) = (v))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_USBPHY1_PLL_480_CTRL bitfields
 */

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field DIV_SELECT[1:0] (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT.
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT      (0x00000003)  //!< Bit mask for CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT) >> BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT.
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT.
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field EN_USB_CLKS[6] (RW)
 *
 * 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1
 * are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable
 * USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when
 * USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS      (6)      //!< Bit position for CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS.
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS      (0x00000040)  //!< Bit mask for CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS.

//! @brief Get value of CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS from a register value.
#define BG_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS(r)   (((r) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS) >> BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS.
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS(v)   ((((reg32_t) v) << BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS)
#else
//! @brief Format value for bitfield CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS.
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS(v)   (((v) << BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL, EN_USB_CLKS, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field POWER[12] (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER      (12)      //!< Bit position for CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER.
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER      (0x00001000)  //!< Bit mask for CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER.

//! @brief Get value of CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER from a register value.
#define BG_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER(r)   (((r) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER) >> BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER.
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER(v)   ((((reg32_t) v) << BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER)
#else
//! @brief Format value for bitfield CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER.
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER(v)   (((v) << BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_POWER(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field ENABLE[13] (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE      (13)      //!< Bit position for CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE.
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE.

//! @brief Get value of CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE from a register value.
#define BG_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE(r)   (((r) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE) >> BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE.
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE)
#else
//! @brief Format value for bitfield CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE.
#define BF_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE(v)   (((v) << BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_USBPHY1_PLL_480_CTRL_ENABLE(v)   BF_CS1(CCM_ANALOG_USBPHY1_PLL_480_CTRL, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_USBPHY1_PLL_480_CTRL, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK      (31)      //!< Bit position for CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK.
#define BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK.

//! @brief Get value of CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK from a register value.
#define BG_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK(r)   (((r) & BM_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK) >> BP_CCM_ANALOG_USBPHY1_PLL_480_CTRL_LOCK)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528 - Analog 528MHz PLL Control Register (RW)
 *
 * Reset value: 0x00013001
 *
 * The control register provides control for the 528MHz PLL.
 */
typedef union _hw_ccm_analog_pll_528
{
    reg32_t U;
    struct _hw_ccm_analog_pll_528_bitfields
    {
        unsigned DIV_SELECT : 1; //!< [0] This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 6; //!< [6:1] Always set to zero (0).
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog Debug bit.
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned RESERVED1 : 1; //!< [17] Reserved
        unsigned PFD_OFFSET_EN : 1; //!< [18] Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 12; //!< [30:19] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_528_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_528 register
 */
#define HW_CCM_ANALOG_PLL_528_ADDR      (REGS_CCM_ANALOG_BASE + 0x30)
#define HW_CCM_ANALOG_PLL_528_SET_ADDR  (HW_CCM_ANALOG_PLL_528_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_528_CLR_ADDR  (HW_CCM_ANALOG_PLL_528_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_528_TOG_ADDR  (HW_CCM_ANALOG_PLL_528_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_528           (*(volatile hw_ccm_analog_pll_528_t *) HW_CCM_ANALOG_PLL_528_ADDR)
#define HW_CCM_ANALOG_PLL_528_RD()      (HW_CCM_ANALOG_PLL_528.U)
#define HW_CCM_ANALOG_PLL_528_WR(v)     (HW_CCM_ANALOG_PLL_528.U = (v))
#define HW_CCM_ANALOG_PLL_528_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_528_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_528_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_528_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_528_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_528_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_528 bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_528, field DIV_SELECT[0] (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_PLL_528_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_528_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_528_DIV_SELECT      (0x00000001)  //!< Bit mask for CCM_ANALOG_PLL_528_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_528_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_528_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_PLL_528_DIV_SELECT) >> BP_CCM_ANALOG_PLL_528_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_528_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_DIV_SELECT) & BM_CCM_ANALOG_PLL_528_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_528_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_PLL_528_DIV_SELECT) & BM_CCM_ANALOG_PLL_528_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_528_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_528, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_528_HALF_LF.
#define BM_CCM_ANALOG_PLL_528_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_528_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_528_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_528_HALF_LF(r)   (((r) & BM_CCM_ANALOG_PLL_528_HALF_LF) >> BP_CCM_ANALOG_PLL_528_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_HALF_LF.
#define BF_CCM_ANALOG_PLL_528_HALF_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_HALF_LF) & BM_CCM_ANALOG_PLL_528_HALF_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_HALF_LF.
#define BF_CCM_ANALOG_PLL_528_HALF_LF(v)   (((v) << BP_CCM_ANALOG_PLL_528_HALF_LF) & BM_CCM_ANALOG_PLL_528_HALF_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_528, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_528_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_528_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_528_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_528_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_528_DOUBLE_LF(r)   (((r) & BM_CCM_ANALOG_PLL_528_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_528_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_528_DOUBLE_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_DOUBLE_LF) & BM_CCM_ANALOG_PLL_528_DOUBLE_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_528_DOUBLE_LF(v)   (((v) << BP_CCM_ANALOG_PLL_528_DOUBLE_LF) & BM_CCM_ANALOG_PLL_528_DOUBLE_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_528_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_528, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_528_HALF_CP.
#define BM_CCM_ANALOG_PLL_528_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_528_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_528_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_528_HALF_CP(r)   (((r) & BM_CCM_ANALOG_PLL_528_HALF_CP) >> BP_CCM_ANALOG_PLL_528_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_HALF_CP.
#define BF_CCM_ANALOG_PLL_528_HALF_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_HALF_CP) & BM_CCM_ANALOG_PLL_528_HALF_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_HALF_CP.
#define BF_CCM_ANALOG_PLL_528_HALF_CP(v)   (((v) << BP_CCM_ANALOG_PLL_528_HALF_CP) & BM_CCM_ANALOG_PLL_528_HALF_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_528, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_528_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_528_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_528_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_528_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_528_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_528_DOUBLE_CP(r)   (((r) & BM_CCM_ANALOG_PLL_528_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_528_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_528_DOUBLE_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_DOUBLE_CP) & BM_CCM_ANALOG_PLL_528_DOUBLE_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_528_DOUBLE_CP(v)   (((v) << BP_CCM_ANALOG_PLL_528_DOUBLE_CP) & BM_CCM_ANALOG_PLL_528_DOUBLE_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_528_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_528, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field HOLD_RING_OFF[11] (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_528_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_528_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_528_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_528_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_528_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_528_HOLD_RING_OFF(r)   (((r) & BM_CCM_ANALOG_PLL_528_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_528_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_528_HOLD_RING_OFF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_528_HOLD_RING_OFF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_528_HOLD_RING_OFF(v)   (((v) << BP_CCM_ANALOG_PLL_528_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_528_HOLD_RING_OFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_528_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_528, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_528_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_528_POWERDOWN.
#define BM_CCM_ANALOG_PLL_528_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_528_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_528_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_528_POWERDOWN(r)   (((r) & BM_CCM_ANALOG_PLL_528_POWERDOWN) >> BP_CCM_ANALOG_PLL_528_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_POWERDOWN.
#define BF_CCM_ANALOG_PLL_528_POWERDOWN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_POWERDOWN) & BM_CCM_ANALOG_PLL_528_POWERDOWN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_POWERDOWN.
#define BF_CCM_ANALOG_PLL_528_POWERDOWN(v)   (((v) << BP_CCM_ANALOG_PLL_528_POWERDOWN) & BM_CCM_ANALOG_PLL_528_POWERDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_528_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_528, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field ENABLE[13] (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_528_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_528_ENABLE.
#define BM_CCM_ANALOG_PLL_528_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_528_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_528_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_528_ENABLE(r)   (((r) & BM_CCM_ANALOG_PLL_528_ENABLE) >> BP_CCM_ANALOG_PLL_528_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_ENABLE.
#define BF_CCM_ANALOG_PLL_528_ENABLE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_ENABLE) & BM_CCM_ANALOG_PLL_528_ENABLE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_ENABLE.
#define BF_CCM_ANALOG_PLL_528_ENABLE(v)   (((v) << BP_CCM_ANALOG_PLL_528_ENABLE) & BM_CCM_ANALOG_PLL_528_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_528_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_528, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_528_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_528_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_528_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC(r)   (((r) & BM_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC(v)   (((v) << BP_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_528, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC__ANACLK_2 (0x2) //!< Select the Anaclk2/2b as source.
#define BV_CCM_ANALOG_PLL_528_BYPASS_CLK_SRC__XOR (0x3) //!< Select the xor of Anaclk1/1b and Anaclk2/2b as source.

/* --- Register HW_CCM_ANALOG_PLL_528, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_528_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_528_BYPASS.
#define BM_CCM_ANALOG_PLL_528_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_528_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_528_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_528_BYPASS(r)   (((r) & BM_CCM_ANALOG_PLL_528_BYPASS) >> BP_CCM_ANALOG_PLL_528_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_BYPASS.
#define BF_CCM_ANALOG_PLL_528_BYPASS(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_BYPASS) & BM_CCM_ANALOG_PLL_528_BYPASS)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_BYPASS.
#define BF_CCM_ANALOG_PLL_528_BYPASS(v)   (((v) << BP_CCM_ANALOG_PLL_528_BYPASS) & BM_CCM_ANALOG_PLL_528_BYPASS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_528_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_528, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field PFD_OFFSET_EN[18] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_528_PFD_OFFSET_EN      (18)      //!< Bit position for CCM_ANALOG_PLL_528_PFD_OFFSET_EN.
#define BM_CCM_ANALOG_PLL_528_PFD_OFFSET_EN      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_528_PFD_OFFSET_EN.

//! @brief Get value of CCM_ANALOG_PLL_528_PFD_OFFSET_EN from a register value.
#define BG_CCM_ANALOG_PLL_528_PFD_OFFSET_EN(r)   (((r) & BM_CCM_ANALOG_PLL_528_PFD_OFFSET_EN) >> BP_CCM_ANALOG_PLL_528_PFD_OFFSET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_528_PFD_OFFSET_EN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_528_PFD_OFFSET_EN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_528_PFD_OFFSET_EN(v)   (((v) << BP_CCM_ANALOG_PLL_528_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_528_PFD_OFFSET_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_528_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_528, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_528, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_528_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_528_LOCK.
#define BM_CCM_ANALOG_PLL_528_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_528_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_528_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_528_LOCK(r)   (((r) & BM_CCM_ANALOG_PLL_528_LOCK) >> BP_CCM_ANALOG_PLL_528_LOCK)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_SS - 528MHz PLL Spread Spectrum Register. (RW)
 *
 * Reset value: 0x00000000
 *
 * This register contains the 528 PLL spread spectrum controls.
 */
typedef union _hw_ccm_analog_pll_528_ss
{
    reg32_t U;
    struct _hw_ccm_analog_pll_528_ss_bitfields
    {
        unsigned STEP : 15; //!< [14:0] frequency change step = step/B*24MHz.
        unsigned ENABLE : 1; //!< [15] This bit enables the spread spectrum modulation.
        unsigned STOP : 16; //!< [31:16] Frequency change = stop/B*24MHz.
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

/* --- Register HW_CCM_ANALOG_PLL_528_SS, field STEP[14:0] (RW)
 *
 * frequency change step = step/B*24MHz.
 */

#define BP_CCM_ANALOG_PLL_528_SS_STEP      (0)      //!< Bit position for CCM_ANALOG_PLL_528_SS_STEP.
#define BM_CCM_ANALOG_PLL_528_SS_STEP      (0x00007fff)  //!< Bit mask for CCM_ANALOG_PLL_528_SS_STEP.

//! @brief Get value of CCM_ANALOG_PLL_528_SS_STEP from a register value.
#define BG_CCM_ANALOG_PLL_528_SS_STEP(r)   (((r) & BM_CCM_ANALOG_PLL_528_SS_STEP) >> BP_CCM_ANALOG_PLL_528_SS_STEP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_SS_STEP.
#define BF_CCM_ANALOG_PLL_528_SS_STEP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_SS_STEP) & BM_CCM_ANALOG_PLL_528_SS_STEP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_SS_STEP.
#define BF_CCM_ANALOG_PLL_528_SS_STEP(v)   (((v) << BP_CCM_ANALOG_PLL_528_SS_STEP) & BM_CCM_ANALOG_PLL_528_SS_STEP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STEP field to a new value.
#define BW_CCM_ANALOG_PLL_528_SS_STEP(v)   (HW_CCM_ANALOG_PLL_528_SS_WR((HW_CCM_ANALOG_PLL_528_SS_RD() & ~BM_CCM_ANALOG_PLL_528_SS_STEP) | BF_CCM_ANALOG_PLL_528_SS_STEP(v)))
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SS, field ENABLE[15] (RW)
 *
 * This bit enables the spread spectrum modulation.
 */

#define BP_CCM_ANALOG_PLL_528_SS_ENABLE      (15)      //!< Bit position for CCM_ANALOG_PLL_528_SS_ENABLE.
#define BM_CCM_ANALOG_PLL_528_SS_ENABLE      (0x00008000)  //!< Bit mask for CCM_ANALOG_PLL_528_SS_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_528_SS_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_528_SS_ENABLE(r)   (((r) & BM_CCM_ANALOG_PLL_528_SS_ENABLE) >> BP_CCM_ANALOG_PLL_528_SS_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_SS_ENABLE.
#define BF_CCM_ANALOG_PLL_528_SS_ENABLE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_SS_ENABLE) & BM_CCM_ANALOG_PLL_528_SS_ENABLE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_SS_ENABLE.
#define BF_CCM_ANALOG_PLL_528_SS_ENABLE(v)   (((v) << BP_CCM_ANALOG_PLL_528_SS_ENABLE) & BM_CCM_ANALOG_PLL_528_SS_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_528_SS_ENABLE(v)   (HW_CCM_ANALOG_PLL_528_SS_WR((HW_CCM_ANALOG_PLL_528_SS_RD() & ~BM_CCM_ANALOG_PLL_528_SS_ENABLE) | BF_CCM_ANALOG_PLL_528_SS_ENABLE(v)))
#endif

/* --- Register HW_CCM_ANALOG_PLL_528_SS, field STOP[31:16] (RW)
 *
 * Frequency change = stop/B*24MHz.
 */

#define BP_CCM_ANALOG_PLL_528_SS_STOP      (16)      //!< Bit position for CCM_ANALOG_PLL_528_SS_STOP.
#define BM_CCM_ANALOG_PLL_528_SS_STOP      (0xffff0000)  //!< Bit mask for CCM_ANALOG_PLL_528_SS_STOP.

//! @brief Get value of CCM_ANALOG_PLL_528_SS_STOP from a register value.
#define BG_CCM_ANALOG_PLL_528_SS_STOP(r)   (((r) & BM_CCM_ANALOG_PLL_528_SS_STOP) >> BP_CCM_ANALOG_PLL_528_SS_STOP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_SS_STOP.
#define BF_CCM_ANALOG_PLL_528_SS_STOP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_SS_STOP) & BM_CCM_ANALOG_PLL_528_SS_STOP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_SS_STOP.
#define BF_CCM_ANALOG_PLL_528_SS_STOP(v)   (((v) << BP_CCM_ANALOG_PLL_528_SS_STOP) & BM_CCM_ANALOG_PLL_528_SS_STOP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STOP field to a new value.
#define BW_CCM_ANALOG_PLL_528_SS_STOP(v)   (HW_CCM_ANALOG_PLL_528_SS_WR((HW_CCM_ANALOG_PLL_528_SS_RD() & ~BM_CCM_ANALOG_PLL_528_SS_STOP) | BF_CCM_ANALOG_PLL_528_SS_STOP(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_NUM - Numerator of 528MHz PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register contains the numerator of 528MHz PLL fractional loop divider(Signed number).
 * Absoulte value should be less than denominator
 */
typedef union _hw_ccm_analog_pll_528_num
{
    reg32_t U;
    struct _hw_ccm_analog_pll_528_num_bitfields
    {
        unsigned A : 30; //!< [29:0] 30 bit numerator (A) of fractional loop divider (signed integer).
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_528_NUM, field A[29:0] (RW)
 *
 * 30 bit numerator (A) of fractional loop divider (signed integer).
 */

#define BP_CCM_ANALOG_PLL_528_NUM_A      (0)      //!< Bit position for CCM_ANALOG_PLL_528_NUM_A.
#define BM_CCM_ANALOG_PLL_528_NUM_A      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_528_NUM_A.

//! @brief Get value of CCM_ANALOG_PLL_528_NUM_A from a register value.
#define BG_CCM_ANALOG_PLL_528_NUM_A(r)   (((r) & BM_CCM_ANALOG_PLL_528_NUM_A) >> BP_CCM_ANALOG_PLL_528_NUM_A)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_NUM_A.
#define BF_CCM_ANALOG_PLL_528_NUM_A(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_NUM_A) & BM_CCM_ANALOG_PLL_528_NUM_A)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_NUM_A.
#define BF_CCM_ANALOG_PLL_528_NUM_A(v)   (((v) << BP_CCM_ANALOG_PLL_528_NUM_A) & BM_CCM_ANALOG_PLL_528_NUM_A)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the A field to a new value.
#define BW_CCM_ANALOG_PLL_528_NUM_A(v)   (HW_CCM_ANALOG_PLL_528_NUM_WR((HW_CCM_ANALOG_PLL_528_NUM_RD() & ~BM_CCM_ANALOG_PLL_528_NUM_A) | BF_CCM_ANALOG_PLL_528_NUM_A(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_528_DENOM - Denominator of 528MHz PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x00000012
 *
 * This register contains the Denominator of 528MHz PLL fractional loop divider.
 */
typedef union _hw_ccm_analog_pll_528_denom
{
    reg32_t U;
    struct _hw_ccm_analog_pll_528_denom_bitfields
    {
        unsigned B : 30; //!< [29:0] 30 bit Denominator (B) of fractional loop divider (unsigned integer).
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_528_DENOM, field B[29:0] (RW)
 *
 * 30 bit Denominator (B) of fractional loop divider (unsigned integer).
 */

#define BP_CCM_ANALOG_PLL_528_DENOM_B      (0)      //!< Bit position for CCM_ANALOG_PLL_528_DENOM_B.
#define BM_CCM_ANALOG_PLL_528_DENOM_B      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_528_DENOM_B.

//! @brief Get value of CCM_ANALOG_PLL_528_DENOM_B from a register value.
#define BG_CCM_ANALOG_PLL_528_DENOM_B(r)   (((r) & BM_CCM_ANALOG_PLL_528_DENOM_B) >> BP_CCM_ANALOG_PLL_528_DENOM_B)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_DENOM_B.
#define BF_CCM_ANALOG_PLL_528_DENOM_B(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_528_DENOM_B) & BM_CCM_ANALOG_PLL_528_DENOM_B)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_528_DENOM_B.
#define BF_CCM_ANALOG_PLL_528_DENOM_B(v)   (((v) << BP_CCM_ANALOG_PLL_528_DENOM_B) & BM_CCM_ANALOG_PLL_528_DENOM_B)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the B field to a new value.
#define BW_CCM_ANALOG_PLL_528_DENOM_B(v)   (HW_CCM_ANALOG_PLL_528_DENOM_WR((HW_CCM_ANALOG_PLL_528_DENOM_RD() & ~BM_CCM_ANALOG_PLL_528_DENOM_B) | BF_CCM_ANALOG_PLL_528_DENOM_B(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO - Analog Audio PLL control Register (RW)
 *
 * Reset value: 0x00011006
 *
 * The control register provides control for the audio PLL.
 */
typedef union _hw_ccm_analog_pll_audio
{
    reg32_t U;
    struct _hw_ccm_analog_pll_audio_bitfields
    {
        unsigned DIV_SELECT : 7; //!< [6:0] This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale.
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog debug Bit
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned RESERVED0 : 1; //!< [17] Revsered
        unsigned PFD_OFFSET_EN : 1; //!< [18] Enables an offset in the phase frequency detector.
        unsigned POST_DIV_SELECT : 2; //!< [20:19] These bits implement a divider after the PLL, but before the enable and bypass mux.
        unsigned SSC_EN : 1; //!< [21] Reserved Bit
        unsigned RESERVED1 : 9; //!< [30:22] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_audio_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_ADDR      (REGS_CCM_ANALOG_BASE + 0x70)
#define HW_CCM_ANALOG_PLL_AUDIO_SET_ADDR  (HW_CCM_ANALOG_PLL_AUDIO_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_AUDIO_CLR_ADDR  (HW_CCM_ANALOG_PLL_AUDIO_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_AUDIO_TOG_ADDR  (HW_CCM_ANALOG_PLL_AUDIO_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO           (*(volatile hw_ccm_analog_pll_audio_t *) HW_CCM_ANALOG_PLL_AUDIO_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_RD()      (HW_CCM_ANALOG_PLL_AUDIO.U)
#define HW_CCM_ANALOG_PLL_AUDIO_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_AUDIO_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_AUDIO_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_AUDIO_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DIV_SELECT[6:0] (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT      (0x0000007f)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT) >> BP_CCM_ANALOG_PLL_AUDIO_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_DIV_SELECT) & BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_DIV_SELECT) & BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_HALF_LF.
#define BM_CCM_ANALOG_PLL_AUDIO_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_HALF_LF(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_HALF_LF) >> BP_CCM_ANALOG_PLL_AUDIO_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HALF_LF.
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_HALF_LF) & BM_CCM_ANALOG_PLL_AUDIO_HALF_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HALF_LF.
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_LF(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_HALF_LF) & BM_CCM_ANALOG_PLL_AUDIO_HALF_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_HALF_CP.
#define BM_CCM_ANALOG_PLL_AUDIO_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_HALF_CP(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_HALF_CP) >> BP_CCM_ANALOG_PLL_AUDIO_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HALF_CP.
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_HALF_CP) & BM_CCM_ANALOG_PLL_AUDIO_HALF_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HALF_CP.
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_CP(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_HALF_CP) & BM_CCM_ANALOG_PLL_AUDIO_HALF_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HOLD_RING_OFF[11] (RW)
 *
 * Analog debug Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_POWERDOWN.
#define BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_POWERDOWN(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN) >> BP_CCM_ANALOG_PLL_AUDIO_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_POWERDOWN.
#define BF_CCM_ANALOG_PLL_AUDIO_POWERDOWN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_POWERDOWN) & BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_POWERDOWN.
#define BF_CCM_ANALOG_PLL_AUDIO_POWERDOWN(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_POWERDOWN) & BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field ENABLE[13] (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_AUDIO_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_ENABLE.
#define BM_CCM_ANALOG_PLL_AUDIO_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_ENABLE(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_ENABLE) >> BP_CCM_ANALOG_PLL_AUDIO_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_ENABLE.
#define BF_CCM_ANALOG_PLL_AUDIO_ENABLE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_ENABLE) & BM_CCM_ANALOG_PLL_AUDIO_ENABLE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_ENABLE.
#define BF_CCM_ANALOG_PLL_AUDIO_ENABLE(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_ENABLE) & BM_CCM_ANALOG_PLL_AUDIO_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__ANACLK_2 (0x2) //!< Select the Anaclk2/2b as source.
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__XOR (0x3) //!< Select the xor of Anaclk1/1b and Anaclk2/2b as source.

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_BYPASS.
#define BM_CCM_ANALOG_PLL_AUDIO_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_BYPASS(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS) >> BP_CCM_ANALOG_PLL_AUDIO_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_BYPASS.
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_BYPASS) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_BYPASS.
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_BYPASS) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field PFD_OFFSET_EN[18] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN      (18)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN.
#define BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN) >> BP_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field POST_DIV_SELECT[20:19] (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT      (19)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT      (0x00180000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT) >> BP_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT) & BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT) & BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field SSC_EN[21] (RW)
 *
 * Reserved Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SSC_EN      (21)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_SSC_EN.
#define BM_CCM_ANALOG_PLL_AUDIO_SSC_EN      (0x00200000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_SSC_EN.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_SSC_EN from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_SSC_EN(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_SSC_EN) >> BP_CCM_ANALOG_PLL_AUDIO_SSC_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_SSC_EN.
#define BF_CCM_ANALOG_PLL_AUDIO_SSC_EN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_SSC_EN) & BM_CCM_ANALOG_PLL_AUDIO_SSC_EN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_SSC_EN.
#define BF_CCM_ANALOG_PLL_AUDIO_SSC_EN(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_SSC_EN) & BM_CCM_ANALOG_PLL_AUDIO_SSC_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_LOCK.
#define BM_CCM_ANALOG_PLL_AUDIO_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_LOCK(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_LOCK) >> BP_CCM_ANALOG_PLL_AUDIO_LOCK)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_NUM - Numerator of Audio PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x05f5e100
 *
 * This register contains the numerator (A) of Audio PLL fractional loop divider.(Signed number),
 * absolute value should be less than denominator  Absolute value should be less than denominator
 */
typedef union _hw_ccm_analog_pll_audio_num
{
    reg32_t U;
    struct _hw_ccm_analog_pll_audio_num_bitfields
    {
        unsigned A : 30; //!< [29:0] 30 bit numerator of fractional loop divider.
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_NUM, field A[29:0] (RW)
 *
 * 30 bit numerator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_NUM_A      (0)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_NUM_A.
#define BM_CCM_ANALOG_PLL_AUDIO_NUM_A      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_NUM_A.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_NUM_A from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_NUM_A(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_NUM_A) >> BP_CCM_ANALOG_PLL_AUDIO_NUM_A)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_NUM_A.
#define BF_CCM_ANALOG_PLL_AUDIO_NUM_A(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_NUM_A) & BM_CCM_ANALOG_PLL_AUDIO_NUM_A)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_NUM_A.
#define BF_CCM_ANALOG_PLL_AUDIO_NUM_A(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_NUM_A) & BM_CCM_ANALOG_PLL_AUDIO_NUM_A)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the A field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_NUM_A(v)   (HW_CCM_ANALOG_PLL_AUDIO_NUM_WR((HW_CCM_ANALOG_PLL_AUDIO_NUM_RD() & ~BM_CCM_ANALOG_PLL_AUDIO_NUM_A) | BF_CCM_ANALOG_PLL_AUDIO_NUM_A(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_DENOM - Denominator of Audio PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x2964619c
 *
 * This register contains the Denominator (B) of Audio PLL fractional loop divider.(unsigned number)
 */
typedef union _hw_ccm_analog_pll_audio_denom
{
    reg32_t U;
    struct _hw_ccm_analog_pll_audio_denom_bitfields
    {
        unsigned B : 30; //!< [29:0] 30 bit Denominator of fractional loop divider.
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_DENOM, field B[29:0] (RW)
 *
 * 30 bit Denominator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DENOM_B      (0)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_DENOM_B.
#define BM_CCM_ANALOG_PLL_AUDIO_DENOM_B      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_DENOM_B.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_DENOM_B from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_DENOM_B(r)   (((r) & BM_CCM_ANALOG_PLL_AUDIO_DENOM_B) >> BP_CCM_ANALOG_PLL_AUDIO_DENOM_B)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DENOM_B.
#define BF_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_AUDIO_DENOM_B) & BM_CCM_ANALOG_PLL_AUDIO_DENOM_B)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DENOM_B.
#define BF_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)   (((v) << BP_CCM_ANALOG_PLL_AUDIO_DENOM_B) & BM_CCM_ANALOG_PLL_AUDIO_DENOM_B)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the B field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)   (HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR((HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD() & ~BM_CCM_ANALOG_PLL_AUDIO_DENOM_B) | BF_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO - Analog Video PLL control Register (RW)
 *
 * Reset value: 0x0001100c
 *
 * The control register provides control for the Video PLL.
 */
typedef union _hw_ccm_analog_pll_video
{
    reg32_t U;
    struct _hw_ccm_analog_pll_video_bitfields
    {
        unsigned DIV_SELECT : 7; //!< [6:0] This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale.
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog Debug bit.
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enalbe PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned RESERVED0 : 1; //!< [17] Reserved
        unsigned PFD_OFFSET_EN : 1; //!< [18] Enables an offset in the phase frequency detector.
        unsigned POST_DIV_SELECT : 2; //!< [20:19] These bits implement a divider after the PLL, but before the enable and bypass mux.
        unsigned SSC_EN : 1; //!< [21] Revserved BIt
        unsigned RESERVED1 : 9; //!< [30:22] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_video_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_ADDR      (REGS_CCM_ANALOG_BASE + 0xa0)
#define HW_CCM_ANALOG_PLL_VIDEO_SET_ADDR  (HW_CCM_ANALOG_PLL_VIDEO_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_VIDEO_CLR_ADDR  (HW_CCM_ANALOG_PLL_VIDEO_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_VIDEO_TOG_ADDR  (HW_CCM_ANALOG_PLL_VIDEO_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO           (*(volatile hw_ccm_analog_pll_video_t *) HW_CCM_ANALOG_PLL_VIDEO_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_RD()      (HW_CCM_ANALOG_PLL_VIDEO.U)
#define HW_CCM_ANALOG_PLL_VIDEO_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_VIDEO_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_VIDEO_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_VIDEO_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DIV_SELECT[6:0] (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT      (0x0000007f)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT) >> BP_CCM_ANALOG_PLL_VIDEO_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_DIV_SELECT) & BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_DIV_SELECT) & BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_HALF_LF.
#define BM_CCM_ANALOG_PLL_VIDEO_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_HALF_LF(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_HALF_LF) >> BP_CCM_ANALOG_PLL_VIDEO_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HALF_LF.
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_HALF_LF) & BM_CCM_ANALOG_PLL_VIDEO_HALF_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HALF_LF.
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_LF(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_HALF_LF) & BM_CCM_ANALOG_PLL_VIDEO_HALF_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_HALF_CP.
#define BM_CCM_ANALOG_PLL_VIDEO_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_HALF_CP(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_HALF_CP) >> BP_CCM_ANALOG_PLL_VIDEO_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HALF_CP.
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_HALF_CP) & BM_CCM_ANALOG_PLL_VIDEO_HALF_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HALF_CP.
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_CP(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_HALF_CP) & BM_CCM_ANALOG_PLL_VIDEO_HALF_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HOLD_RING_OFF[11] (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_POWERDOWN.
#define BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_POWERDOWN(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN) >> BP_CCM_ANALOG_PLL_VIDEO_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_POWERDOWN.
#define BF_CCM_ANALOG_PLL_VIDEO_POWERDOWN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_POWERDOWN) & BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_POWERDOWN.
#define BF_CCM_ANALOG_PLL_VIDEO_POWERDOWN(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_POWERDOWN) & BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field ENABLE[13] (RW)
 *
 * Enalbe PLL output
 */

#define BP_CCM_ANALOG_PLL_VIDEO_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_ENABLE.
#define BM_CCM_ANALOG_PLL_VIDEO_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_ENABLE(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_ENABLE) >> BP_CCM_ANALOG_PLL_VIDEO_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_ENABLE.
#define BF_CCM_ANALOG_PLL_VIDEO_ENABLE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_ENABLE) & BM_CCM_ANALOG_PLL_VIDEO_ENABLE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_ENABLE.
#define BF_CCM_ANALOG_PLL_VIDEO_ENABLE(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_ENABLE) & BM_CCM_ANALOG_PLL_VIDEO_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__ANACLK_2 (0x2) //!< Select the Anaclk2/2b as source.
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__XOR (0x3) //!< Select the xor of Anaclk1/1b and Anaclk2/2b as source.

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_BYPASS.
#define BM_CCM_ANALOG_PLL_VIDEO_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_BYPASS(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS) >> BP_CCM_ANALOG_PLL_VIDEO_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_BYPASS.
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_BYPASS) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_BYPASS.
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_BYPASS) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field PFD_OFFSET_EN[18] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN      (18)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN.
#define BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN) >> BP_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field POST_DIV_SELECT[20:19] (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT      (19)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT      (0x00180000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT) >> BP_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT) & BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT) & BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field SSC_EN[21] (RW)
 *
 * Revserved BIt
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SSC_EN      (21)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_SSC_EN.
#define BM_CCM_ANALOG_PLL_VIDEO_SSC_EN      (0x00200000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_SSC_EN.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_SSC_EN from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_SSC_EN(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_SSC_EN) >> BP_CCM_ANALOG_PLL_VIDEO_SSC_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_SSC_EN.
#define BF_CCM_ANALOG_PLL_VIDEO_SSC_EN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_SSC_EN) & BM_CCM_ANALOG_PLL_VIDEO_SSC_EN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_SSC_EN.
#define BF_CCM_ANALOG_PLL_VIDEO_SSC_EN(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_SSC_EN) & BM_CCM_ANALOG_PLL_VIDEO_SSC_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_LOCK.
#define BM_CCM_ANALOG_PLL_VIDEO_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_LOCK(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_LOCK) >> BP_CCM_ANALOG_PLL_VIDEO_LOCK)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_NUM - Numerator of Video PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x05f5e100
 *
 * This register contains the numerator (A) of Video PLL fractional loop divider.(Signed number)
 * Absolute value should be less than denominator
 */
typedef union _hw_ccm_analog_pll_video_num
{
    reg32_t U;
    struct _hw_ccm_analog_pll_video_num_bitfields
    {
        unsigned A : 30; //!< [29:0] 30 bit numerator of fractional loop divider(Signed number), absolute value should be less than denominator
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_NUM, field A[29:0] (RW)
 *
 * 30 bit numerator of fractional loop divider(Signed number), absolute value should be less than
 * denominator
 */

#define BP_CCM_ANALOG_PLL_VIDEO_NUM_A      (0)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_NUM_A.
#define BM_CCM_ANALOG_PLL_VIDEO_NUM_A      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_NUM_A.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_NUM_A from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_NUM_A(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_NUM_A) >> BP_CCM_ANALOG_PLL_VIDEO_NUM_A)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_NUM_A.
#define BF_CCM_ANALOG_PLL_VIDEO_NUM_A(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_NUM_A) & BM_CCM_ANALOG_PLL_VIDEO_NUM_A)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_NUM_A.
#define BF_CCM_ANALOG_PLL_VIDEO_NUM_A(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_NUM_A) & BM_CCM_ANALOG_PLL_VIDEO_NUM_A)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the A field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_NUM_A(v)   (HW_CCM_ANALOG_PLL_VIDEO_NUM_WR((HW_CCM_ANALOG_PLL_VIDEO_NUM_RD() & ~BM_CCM_ANALOG_PLL_VIDEO_NUM_A) | BF_CCM_ANALOG_PLL_VIDEO_NUM_A(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_DENOM - Denominator of Video PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x10a24447
 *
 * This register contains the Denominator (B) of Video PLL fractional loop divider.(Unsigned number)
 */
typedef union _hw_ccm_analog_pll_video_denom
{
    reg32_t U;
    struct _hw_ccm_analog_pll_video_denom_bitfields
    {
        unsigned B : 30; //!< [29:0] 30 bit Denominator of fractional loop divider.
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
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

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_DENOM, field B[29:0] (RW)
 *
 * 30 bit Denominator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DENOM_B      (0)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_DENOM_B.
#define BM_CCM_ANALOG_PLL_VIDEO_DENOM_B      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_DENOM_B.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_DENOM_B from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_DENOM_B(r)   (((r) & BM_CCM_ANALOG_PLL_VIDEO_DENOM_B) >> BP_CCM_ANALOG_PLL_VIDEO_DENOM_B)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DENOM_B.
#define BF_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_VIDEO_DENOM_B) & BM_CCM_ANALOG_PLL_VIDEO_DENOM_B)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DENOM_B.
#define BF_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)   (((v) << BP_CCM_ANALOG_PLL_VIDEO_DENOM_B) & BM_CCM_ANALOG_PLL_VIDEO_DENOM_B)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the B field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)   (HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR((HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD() & ~BM_CCM_ANALOG_PLL_VIDEO_DENOM_B) | BF_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_MLB - MLB PLL Control Register (RW)
 *
 * Reset value: 0x00010000
 *
 * This register defines the control bits for the MLB PLL.
 */
typedef union _hw_ccm_analog_pll_mlb
{
    reg32_t U;
    struct _hw_ccm_analog_pll_mlb_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved.
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog debug bit.
        unsigned PHASE_SEL : 2; //!< [13:12] Analog debut bit.
        unsigned RESERVED1 : 2; //!< [15:14] Reserved.
        unsigned BYPASS : 1; //!< [16] Bypass the PLL.
        unsigned VDDA_DELAY_CFG : 3; //!< [19:17] Configure the phase delay of the MLB PLL by adjusting the delay line in Vddio power domain.
        unsigned VDDD_DELAY_CFG : 3; //!< [22:20] Configure the phase delay of the MLB PLL by adjusting the delay line in core Vdd poser domain.
        unsigned RX_CLK_DELAY_CFG : 3; //!< [25:23] Configure the phase delay of the MLB PLL RX Clock.
        unsigned MLB_FLT_RES_CFG : 3; //!< [28:26] Configure the filter resistor for different divider ratio of MLB PLL.
        unsigned RESERVED2 : 2; //!< [30:29] Reserved.
        unsigned LOCK : 1; //!< [31] Lock bit
    } B;
} hw_ccm_analog_pll_mlb_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_MLB register
 */
#define HW_CCM_ANALOG_PLL_MLB_ADDR      (REGS_CCM_ANALOG_BASE + 0xd0)
#define HW_CCM_ANALOG_PLL_MLB_SET_ADDR  (HW_CCM_ANALOG_PLL_MLB_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_MLB_CLR_ADDR  (HW_CCM_ANALOG_PLL_MLB_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_MLB_TOG_ADDR  (HW_CCM_ANALOG_PLL_MLB_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_MLB           (*(volatile hw_ccm_analog_pll_mlb_t *) HW_CCM_ANALOG_PLL_MLB_ADDR)
#define HW_CCM_ANALOG_PLL_MLB_RD()      (HW_CCM_ANALOG_PLL_MLB.U)
#define HW_CCM_ANALOG_PLL_MLB_WR(v)     (HW_CCM_ANALOG_PLL_MLB.U = (v))
#define HW_CCM_ANALOG_PLL_MLB_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_MLB_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_MLB_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_MLB_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_MLB_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_MLB_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_MLB bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_MLB, field HOLD_RING_OFF[11] (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_MLB_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_MLB_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_MLB_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF(r)   (((r) & BM_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF(v)   (((v) << BP_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_MLB, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field PHASE_SEL[13:12] (RW)
 *
 * Analog debut bit.
 */

#define BP_CCM_ANALOG_PLL_MLB_PHASE_SEL      (12)      //!< Bit position for CCM_ANALOG_PLL_MLB_PHASE_SEL.
#define BM_CCM_ANALOG_PLL_MLB_PHASE_SEL      (0x00003000)  //!< Bit mask for CCM_ANALOG_PLL_MLB_PHASE_SEL.

//! @brief Get value of CCM_ANALOG_PLL_MLB_PHASE_SEL from a register value.
#define BG_CCM_ANALOG_PLL_MLB_PHASE_SEL(r)   (((r) & BM_CCM_ANALOG_PLL_MLB_PHASE_SEL) >> BP_CCM_ANALOG_PLL_MLB_PHASE_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_PHASE_SEL.
#define BF_CCM_ANALOG_PLL_MLB_PHASE_SEL(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_MLB_PHASE_SEL) & BM_CCM_ANALOG_PLL_MLB_PHASE_SEL)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_PHASE_SEL.
#define BF_CCM_ANALOG_PLL_MLB_PHASE_SEL(v)   (((v) << BP_CCM_ANALOG_PLL_MLB_PHASE_SEL) & BM_CCM_ANALOG_PLL_MLB_PHASE_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PHASE_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_PHASE_SEL(v)   BF_CS1(CCM_ANALOG_PLL_MLB, PHASE_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field BYPASS[16] (RW)
 *
 * Bypass the PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_MLB_BYPASS.
#define BM_CCM_ANALOG_PLL_MLB_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_MLB_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_MLB_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_MLB_BYPASS(r)   (((r) & BM_CCM_ANALOG_PLL_MLB_BYPASS) >> BP_CCM_ANALOG_PLL_MLB_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_BYPASS.
#define BF_CCM_ANALOG_PLL_MLB_BYPASS(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_MLB_BYPASS) & BM_CCM_ANALOG_PLL_MLB_BYPASS)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_BYPASS.
#define BF_CCM_ANALOG_PLL_MLB_BYPASS(v)   (((v) << BP_CCM_ANALOG_PLL_MLB_BYPASS) & BM_CCM_ANALOG_PLL_MLB_BYPASS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_MLB, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field VDDA_DELAY_CFG[19:17] (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in Vddio power domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG      (17)      //!< Bit position for CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG.
#define BM_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG      (0x000e0000)  //!< Bit mask for CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG.

//! @brief Get value of CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG from a register value.
#define BG_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG(r)   (((r) & BM_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG) >> BP_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG.
#define BF_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG) & BM_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG.
#define BF_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG(v)   (((v) << BP_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG) & BM_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDA_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_VDDA_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB, VDDA_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field VDDD_DELAY_CFG[22:20] (RW)
 *
 * Configure the phase delay of the MLB PLL by adjusting the delay line in core Vdd poser domain.
 */

#define BP_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG      (20)      //!< Bit position for CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG.
#define BM_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG      (0x00700000)  //!< Bit mask for CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG.

//! @brief Get value of CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG from a register value.
#define BG_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG(r)   (((r) & BM_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG) >> BP_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG.
#define BF_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG) & BM_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG.
#define BF_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG(v)   (((v) << BP_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG) & BM_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VDDD_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_VDDD_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB, VDDD_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field RX_CLK_DELAY_CFG[25:23] (RW)
 *
 * Configure the phase delay of the MLB PLL RX Clock.
 */

#define BP_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG      (23)      //!< Bit position for CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG.
#define BM_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG      (0x03800000)  //!< Bit mask for CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG.

//! @brief Get value of CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG from a register value.
#define BG_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG(r)   (((r) & BM_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG) >> BP_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG.
#define BF_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG) & BM_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG.
#define BF_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG(v)   (((v) << BP_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG) & BM_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_CLK_DELAY_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_RX_CLK_DELAY_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB, RX_CLK_DELAY_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field MLB_FLT_RES_CFG[28:26] (RW)
 *
 * Configure the filter resistor for different divider ratio of MLB PLL.
 */

#define BP_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG      (26)      //!< Bit position for CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG.
#define BM_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG      (0x1c000000)  //!< Bit mask for CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG.

//! @brief Get value of CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG from a register value.
#define BG_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG(r)   (((r) & BM_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG) >> BP_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG.
#define BF_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG) & BM_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG.
#define BF_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG(v)   (((v) << BP_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG) & BM_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MLB_FLT_RES_CFG field to a new value.
#define BW_CCM_ANALOG_PLL_MLB_MLB_FLT_RES_CFG(v)   BF_CS1(CCM_ANALOG_PLL_MLB, MLB_FLT_RES_CFG, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_MLB, field LOCK[31] (RO)
 *
 * Lock bit
 *
 * Values:
 * 0 - PLL is not currently locked
 * 1 - PLL is currently locked.
 */

#define BP_CCM_ANALOG_PLL_MLB_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_MLB_LOCK.
#define BM_CCM_ANALOG_PLL_MLB_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_MLB_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_MLB_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_MLB_LOCK(r)   (((r) & BM_CCM_ANALOG_PLL_MLB_LOCK) >> BP_CCM_ANALOG_PLL_MLB_LOCK)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_ENET - Analog ENET PLL Control Register (RW)
 *
 * Reset value: 0x00011001
 *
 * The control register provides control for the ENET PLL.
 */
typedef union _hw_ccm_analog_pll_enet
{
    reg32_t U;
    struct _hw_ccm_analog_pll_enet_bitfields
    {
        unsigned DIV_SELECT : 2; //!< [1:0] Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz respectively.
        unsigned RESERVED0 : 5; //!< [6:2] Always set to zero (0).
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog debug bit
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enable the ethernet clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned RESERVED1 : 1; //!< [17] Reserved
        unsigned PFD_OFFSET_EN : 1; //!< [18] Enables an offset in the phase frequency detector.
        unsigned ENABLE_PCIE : 1; //!< [19] Enables an offset in the phase frequency detector.
        unsigned ENABLE_SATA : 1; //!< [20] Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 10; //!< [30:21] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_enet_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_ENET register
 */
#define HW_CCM_ANALOG_PLL_ENET_ADDR      (REGS_CCM_ANALOG_BASE + 0xe0)
#define HW_CCM_ANALOG_PLL_ENET_SET_ADDR  (HW_CCM_ANALOG_PLL_ENET_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_ENET_CLR_ADDR  (HW_CCM_ANALOG_PLL_ENET_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_ENET_TOG_ADDR  (HW_CCM_ANALOG_PLL_ENET_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_ENET           (*(volatile hw_ccm_analog_pll_enet_t *) HW_CCM_ANALOG_PLL_ENET_ADDR)
#define HW_CCM_ANALOG_PLL_ENET_RD()      (HW_CCM_ANALOG_PLL_ENET.U)
#define HW_CCM_ANALOG_PLL_ENET_WR(v)     (HW_CCM_ANALOG_PLL_ENET.U = (v))
#define HW_CCM_ANALOG_PLL_ENET_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ENET_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_ENET_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ENET_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_ENET_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ENET_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_ENET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DIV_SELECT[1:0] (RW)
 *
 * Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not
 * 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz
 * respectively.
 */

#define BP_CCM_ANALOG_PLL_ENET_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_ENET_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_ENET_DIV_SELECT      (0x00000003)  //!< Bit mask for CCM_ANALOG_PLL_ENET_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_ENET_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_ENET_DIV_SELECT(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_DIV_SELECT) >> BP_CCM_ANALOG_PLL_ENET_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_ENET_DIV_SELECT(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_DIV_SELECT) & BM_CCM_ANALOG_PLL_ENET_DIV_SELECT)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_ENET_DIV_SELECT(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_DIV_SELECT) & BM_CCM_ANALOG_PLL_ENET_DIV_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_ENET_HALF_LF.
#define BM_CCM_ANALOG_PLL_ENET_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_ENET_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_ENET_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_ENET_HALF_LF(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_HALF_LF) >> BP_CCM_ANALOG_PLL_ENET_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HALF_LF.
#define BF_CCM_ANALOG_PLL_ENET_HALF_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_HALF_LF) & BM_CCM_ANALOG_PLL_ENET_HALF_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HALF_LF.
#define BF_CCM_ANALOG_PLL_ENET_HALF_LF(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_HALF_LF) & BM_CCM_ANALOG_PLL_ENET_HALF_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_ENET_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_ENET_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_ENET_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_ENET_DOUBLE_LF(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_ENET_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_LF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_DOUBLE_LF) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_LF(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_DOUBLE_LF) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_ENET_HALF_CP.
#define BM_CCM_ANALOG_PLL_ENET_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_ENET_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_ENET_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_ENET_HALF_CP(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_HALF_CP) >> BP_CCM_ANALOG_PLL_ENET_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HALF_CP.
#define BF_CCM_ANALOG_PLL_ENET_HALF_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_HALF_CP) & BM_CCM_ANALOG_PLL_ENET_HALF_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HALF_CP.
#define BF_CCM_ANALOG_PLL_ENET_HALF_CP(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_HALF_CP) & BM_CCM_ANALOG_PLL_ENET_HALF_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_ENET_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_ENET_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_ENET_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_ENET_DOUBLE_CP(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_ENET_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_CP(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_DOUBLE_CP) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_CP(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_DOUBLE_CP) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HOLD_RING_OFF[11] (RW)
 *
 * Analog debug bit
 */

#define BP_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_ENET_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_ENET_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_ENET_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_ENET_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_ENET_POWERDOWN.
#define BM_CCM_ANALOG_PLL_ENET_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_ENET_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_ENET_POWERDOWN(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_POWERDOWN) >> BP_CCM_ANALOG_PLL_ENET_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_POWERDOWN.
#define BF_CCM_ANALOG_PLL_ENET_POWERDOWN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_POWERDOWN) & BM_CCM_ANALOG_PLL_ENET_POWERDOWN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_POWERDOWN.
#define BF_CCM_ANALOG_PLL_ENET_POWERDOWN(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_POWERDOWN) & BM_CCM_ANALOG_PLL_ENET_POWERDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_ENET, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE[13] (RW)
 *
 * Enable the ethernet clock output.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_ENET_ENABLE.
#define BM_CCM_ANALOG_PLL_ENET_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_ENET_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_ENET_ENABLE(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_ENABLE) >> BP_CCM_ANALOG_PLL_ENET_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_ENABLE) & BM_CCM_ANALOG_PLL_ENET_ENABLE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_ENABLE) & BM_CCM_ANALOG_PLL_ENET_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * ANACLK_2 = 0x2 - Select the Anaclk2/2b as source.
 * XOR = 0x3 - Select the xor of Anaclk1/1b and Anaclk2/2b as source.
 */

#define BP_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_ENET, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__ANACLK_2 (0x2) //!< Select the Anaclk2/2b as source.
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__XOR (0x3) //!< Select the xor of Anaclk1/1b and Anaclk2/2b as source.

/* --- Register HW_CCM_ANALOG_PLL_ENET, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_ENET_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_ENET_BYPASS.
#define BM_CCM_ANALOG_PLL_ENET_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_ENET_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_ENET_BYPASS(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_BYPASS) >> BP_CCM_ANALOG_PLL_ENET_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_BYPASS.
#define BF_CCM_ANALOG_PLL_ENET_BYPASS(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_BYPASS) & BM_CCM_ANALOG_PLL_ENET_BYPASS)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_BYPASS.
#define BF_CCM_ANALOG_PLL_ENET_BYPASS(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_BYPASS) & BM_CCM_ANALOG_PLL_ENET_BYPASS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_ENET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field PFD_OFFSET_EN[18] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN      (18)      //!< Bit position for CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN.
#define BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN.

//! @brief Get value of CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN from a register value.
#define BG_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN) >> BP_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_ENET, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE_PCIE[19] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE_PCIE      (19)      //!< Bit position for CCM_ANALOG_PLL_ENET_ENABLE_PCIE.
#define BM_CCM_ANALOG_PLL_ENET_ENABLE_PCIE      (0x00080000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_ENABLE_PCIE.

//! @brief Get value of CCM_ANALOG_PLL_ENET_ENABLE_PCIE from a register value.
#define BG_CCM_ANALOG_PLL_ENET_ENABLE_PCIE(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_ENABLE_PCIE) >> BP_CCM_ANALOG_PLL_ENET_ENABLE_PCIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE_PCIE.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_PCIE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_ENABLE_PCIE) & BM_CCM_ANALOG_PLL_ENET_ENABLE_PCIE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE_PCIE.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_PCIE(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_ENABLE_PCIE) & BM_CCM_ANALOG_PLL_ENET_ENABLE_PCIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PCIE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE_PCIE(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE_PCIE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE_SATA[20] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE_SATA      (20)      //!< Bit position for CCM_ANALOG_PLL_ENET_ENABLE_SATA.
#define BM_CCM_ANALOG_PLL_ENET_ENABLE_SATA      (0x00100000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_ENABLE_SATA.

//! @brief Get value of CCM_ANALOG_PLL_ENET_ENABLE_SATA from a register value.
#define BG_CCM_ANALOG_PLL_ENET_ENABLE_SATA(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_ENABLE_SATA) >> BP_CCM_ANALOG_PLL_ENET_ENABLE_SATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE_SATA.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_SATA(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PLL_ENET_ENABLE_SATA) & BM_CCM_ANALOG_PLL_ENET_ENABLE_SATA)
#else
//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE_SATA.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_SATA(v)   (((v) << BP_CCM_ANALOG_PLL_ENET_ENABLE_SATA) & BM_CCM_ANALOG_PLL_ENET_ENABLE_SATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_SATA field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE_SATA(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE_SATA, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_ENET_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_ENET_LOCK.
#define BM_CCM_ANALOG_PLL_ENET_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_ENET_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_ENET_LOCK(r)   (((r) & BM_CCM_ANALOG_PLL_ENET_LOCK) >> BP_CCM_ANALOG_PLL_ENET_LOCK)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_480 - 480MHz Clock Phase Fractional Divider Control Register (RW)
 *
 * Reset value: 0x1311100c
 *
 * The PFD_480 control register provides control for PFD clock generation.  This register controls
 * the 4-phase fractional clock dividers. The fractional clock frequencies are a product of the
 * values in these registers.
 */
typedef union _hw_ccm_analog_pfd_480
{
    reg32_t U;
    struct _hw_ccm_analog_pfd_480_bitfields
    {
        unsigned PFD0_FRAC : 6; //!< [5:0] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
        unsigned PFD0_STABLE : 1; //!< [6] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD0_CLKGATE : 1; //!< [7] If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0: ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD1_FRAC : 6; //!< [13:8] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
        unsigned PFD1_STABLE : 1; //!< [14] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD1_CLKGATE : 1; //!< [15] IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD2_FRAC : 6; //!< [21:16] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
        unsigned PFD2_STABLE : 1; //!< [22] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD2_CLKGATE : 1; //!< [23] IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD3_FRAC : 6; //!< [29:24] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
        unsigned PFD3_STABLE : 1; //!< [30] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD3_CLKGATE : 1; //!< [31] IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
    } B;
} hw_ccm_analog_pfd_480_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_480 register
 */
#define HW_CCM_ANALOG_PFD_480_ADDR      (REGS_CCM_ANALOG_BASE + 0xf0)
#define HW_CCM_ANALOG_PFD_480_SET_ADDR  (HW_CCM_ANALOG_PFD_480_ADDR + 0x4)
#define HW_CCM_ANALOG_PFD_480_CLR_ADDR  (HW_CCM_ANALOG_PFD_480_ADDR + 0x8)
#define HW_CCM_ANALOG_PFD_480_TOG_ADDR  (HW_CCM_ANALOG_PFD_480_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_480           (*(volatile hw_ccm_analog_pfd_480_t *) HW_CCM_ANALOG_PFD_480_ADDR)
#define HW_CCM_ANALOG_PFD_480_RD()      (HW_CCM_ANALOG_PFD_480.U)
#define HW_CCM_ANALOG_PFD_480_WR(v)     (HW_CCM_ANALOG_PFD_480.U = (v))
#define HW_CCM_ANALOG_PFD_480_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_480_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PFD_480_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_480_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PFD_480_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_480_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_480 bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_FRAC[5:0] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_FRAC      (0)      //!< Bit position for CCM_ANALOG_PFD_480_PFD0_FRAC.
#define BM_CCM_ANALOG_PFD_480_PFD0_FRAC      (0x0000003f)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD0_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD0_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD0_FRAC(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD0_FRAC) >> BP_CCM_ANALOG_PFD_480_PFD0_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD0_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD0_FRAC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_480_PFD0_FRAC) & BM_CCM_ANALOG_PFD_480_PFD0_FRAC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD0_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD0_FRAC(v)   (((v) << BP_CCM_ANALOG_PFD_480_PFD0_FRAC) & BM_CCM_ANALOG_PFD_480_PFD0_FRAC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_STABLE[6] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_STABLE      (6)      //!< Bit position for CCM_ANALOG_PFD_480_PFD0_STABLE.
#define BM_CCM_ANALOG_PFD_480_PFD0_STABLE      (0x00000040)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD0_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD0_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD0_STABLE(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD0_STABLE) >> BP_CCM_ANALOG_PFD_480_PFD0_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_CLKGATE[7] (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_CLKGATE      (7)      //!< Bit position for CCM_ANALOG_PFD_480_PFD0_CLKGATE.
#define BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE      (0x00000080)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD0_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD0_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD0_CLKGATE(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE) >> BP_CCM_ANALOG_PFD_480_PFD0_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD0_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD0_CLKGATE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_480_PFD0_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD0_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD0_CLKGATE(v)   (((v) << BP_CCM_ANALOG_PFD_480_PFD0_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_FRAC[13:8] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_FRAC      (8)      //!< Bit position for CCM_ANALOG_PFD_480_PFD1_FRAC.
#define BM_CCM_ANALOG_PFD_480_PFD1_FRAC      (0x00003f00)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD1_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD1_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD1_FRAC(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD1_FRAC) >> BP_CCM_ANALOG_PFD_480_PFD1_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD1_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD1_FRAC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_480_PFD1_FRAC) & BM_CCM_ANALOG_PFD_480_PFD1_FRAC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD1_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD1_FRAC(v)   (((v) << BP_CCM_ANALOG_PFD_480_PFD1_FRAC) & BM_CCM_ANALOG_PFD_480_PFD1_FRAC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_STABLE[14] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_STABLE      (14)      //!< Bit position for CCM_ANALOG_PFD_480_PFD1_STABLE.
#define BM_CCM_ANALOG_PFD_480_PFD1_STABLE      (0x00004000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD1_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD1_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD1_STABLE(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD1_STABLE) >> BP_CCM_ANALOG_PFD_480_PFD1_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_CLKGATE[15] (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_CLKGATE      (15)      //!< Bit position for CCM_ANALOG_PFD_480_PFD1_CLKGATE.
#define BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE      (0x00008000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD1_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD1_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD1_CLKGATE(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE) >> BP_CCM_ANALOG_PFD_480_PFD1_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD1_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD1_CLKGATE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_480_PFD1_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD1_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD1_CLKGATE(v)   (((v) << BP_CCM_ANALOG_PFD_480_PFD1_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_FRAC[21:16] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_FRAC      (16)      //!< Bit position for CCM_ANALOG_PFD_480_PFD2_FRAC.
#define BM_CCM_ANALOG_PFD_480_PFD2_FRAC      (0x003f0000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD2_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD2_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD2_FRAC(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD2_FRAC) >> BP_CCM_ANALOG_PFD_480_PFD2_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD2_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD2_FRAC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_480_PFD2_FRAC) & BM_CCM_ANALOG_PFD_480_PFD2_FRAC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD2_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD2_FRAC(v)   (((v) << BP_CCM_ANALOG_PFD_480_PFD2_FRAC) & BM_CCM_ANALOG_PFD_480_PFD2_FRAC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_STABLE[22] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_STABLE      (22)      //!< Bit position for CCM_ANALOG_PFD_480_PFD2_STABLE.
#define BM_CCM_ANALOG_PFD_480_PFD2_STABLE      (0x00400000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD2_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD2_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD2_STABLE(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD2_STABLE) >> BP_CCM_ANALOG_PFD_480_PFD2_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_CLKGATE[23] (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_CLKGATE      (23)      //!< Bit position for CCM_ANALOG_PFD_480_PFD2_CLKGATE.
#define BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE      (0x00800000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD2_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD2_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD2_CLKGATE(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE) >> BP_CCM_ANALOG_PFD_480_PFD2_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD2_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD2_CLKGATE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_480_PFD2_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD2_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD2_CLKGATE(v)   (((v) << BP_CCM_ANALOG_PFD_480_PFD2_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_FRAC[29:24] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_FRAC      (24)      //!< Bit position for CCM_ANALOG_PFD_480_PFD3_FRAC.
#define BM_CCM_ANALOG_PFD_480_PFD3_FRAC      (0x3f000000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD3_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD3_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD3_FRAC(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD3_FRAC) >> BP_CCM_ANALOG_PFD_480_PFD3_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD3_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD3_FRAC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_480_PFD3_FRAC) & BM_CCM_ANALOG_PFD_480_PFD3_FRAC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD3_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD3_FRAC(v)   (((v) << BP_CCM_ANALOG_PFD_480_PFD3_FRAC) & BM_CCM_ANALOG_PFD_480_PFD3_FRAC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_STABLE[30] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_STABLE      (30)      //!< Bit position for CCM_ANALOG_PFD_480_PFD3_STABLE.
#define BM_CCM_ANALOG_PFD_480_PFD3_STABLE      (0x40000000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD3_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD3_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD3_STABLE(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD3_STABLE) >> BP_CCM_ANALOG_PFD_480_PFD3_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_CLKGATE[31] (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_CLKGATE      (31)      //!< Bit position for CCM_ANALOG_PFD_480_PFD3_CLKGATE.
#define BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE      (0x80000000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD3_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD3_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD3_CLKGATE(r)   (((r) & BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE) >> BP_CCM_ANALOG_PFD_480_PFD3_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD3_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD3_CLKGATE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_480_PFD3_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD3_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD3_CLKGATE(v)   (((v) << BP_CCM_ANALOG_PFD_480_PFD3_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD3_CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_528 - 528MHz Clock Phase Fractional Divider Control Register (RW)
 *
 * Reset value: 0x1018101b
 *
 * The PFD_528 control register provides control for PFD clock generation.  This register controls
 * the 4-phase fractional clock dividers. The fractional clock frequencies are a product of the
 * values in these registers.
 */
typedef union _hw_ccm_analog_pfd_528
{
    reg32_t U;
    struct _hw_ccm_analog_pfd_528_bitfields
    {
        unsigned PFD0_FRAC : 6; //!< [5:0] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
        unsigned PFD0_STABLE : 1; //!< [6] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD0_CLKGATE : 1; //!< [7] If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0: ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD1_FRAC : 6; //!< [13:8] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
        unsigned PFD1_STABLE : 1; //!< [14] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD1_CLKGATE : 1; //!< [15] IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD2_FRAC : 6; //!< [21:16] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
        unsigned PFD2_STABLE : 1; //!< [22] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD2_CLKGATE : 1; //!< [23] IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD3_FRAC : 6; //!< [29:24] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
        unsigned PFD3_STABLE : 1; //!< [30] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD3_CLKGATE : 1; //!< [31] IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL powered down
    } B;
} hw_ccm_analog_pfd_528_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_528 register
 */
#define HW_CCM_ANALOG_PFD_528_ADDR      (REGS_CCM_ANALOG_BASE + 0x100)
#define HW_CCM_ANALOG_PFD_528_SET_ADDR  (HW_CCM_ANALOG_PFD_528_ADDR + 0x4)
#define HW_CCM_ANALOG_PFD_528_CLR_ADDR  (HW_CCM_ANALOG_PFD_528_ADDR + 0x8)
#define HW_CCM_ANALOG_PFD_528_TOG_ADDR  (HW_CCM_ANALOG_PFD_528_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_528           (*(volatile hw_ccm_analog_pfd_528_t *) HW_CCM_ANALOG_PFD_528_ADDR)
#define HW_CCM_ANALOG_PFD_528_RD()      (HW_CCM_ANALOG_PFD_528.U)
#define HW_CCM_ANALOG_PFD_528_WR(v)     (HW_CCM_ANALOG_PFD_528.U = (v))
#define HW_CCM_ANALOG_PFD_528_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_528_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PFD_528_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_528_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PFD_528_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_528_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_528 bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_FRAC[5:0] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_FRAC      (0)      //!< Bit position for CCM_ANALOG_PFD_528_PFD0_FRAC.
#define BM_CCM_ANALOG_PFD_528_PFD0_FRAC      (0x0000003f)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD0_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD0_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD0_FRAC(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD0_FRAC) >> BP_CCM_ANALOG_PFD_528_PFD0_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD0_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD0_FRAC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_528_PFD0_FRAC) & BM_CCM_ANALOG_PFD_528_PFD0_FRAC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD0_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD0_FRAC(v)   (((v) << BP_CCM_ANALOG_PFD_528_PFD0_FRAC) & BM_CCM_ANALOG_PFD_528_PFD0_FRAC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_STABLE[6] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_STABLE      (6)      //!< Bit position for CCM_ANALOG_PFD_528_PFD0_STABLE.
#define BM_CCM_ANALOG_PFD_528_PFD0_STABLE      (0x00000040)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD0_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD0_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD0_STABLE(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD0_STABLE) >> BP_CCM_ANALOG_PFD_528_PFD0_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_CLKGATE[7] (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_CLKGATE      (7)      //!< Bit position for CCM_ANALOG_PFD_528_PFD0_CLKGATE.
#define BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE      (0x00000080)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD0_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD0_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD0_CLKGATE(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE) >> BP_CCM_ANALOG_PFD_528_PFD0_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD0_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD0_CLKGATE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_528_PFD0_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD0_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD0_CLKGATE(v)   (((v) << BP_CCM_ANALOG_PFD_528_PFD0_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_FRAC[13:8] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_FRAC      (8)      //!< Bit position for CCM_ANALOG_PFD_528_PFD1_FRAC.
#define BM_CCM_ANALOG_PFD_528_PFD1_FRAC      (0x00003f00)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD1_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD1_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD1_FRAC(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD1_FRAC) >> BP_CCM_ANALOG_PFD_528_PFD1_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD1_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD1_FRAC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_528_PFD1_FRAC) & BM_CCM_ANALOG_PFD_528_PFD1_FRAC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD1_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD1_FRAC(v)   (((v) << BP_CCM_ANALOG_PFD_528_PFD1_FRAC) & BM_CCM_ANALOG_PFD_528_PFD1_FRAC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_STABLE[14] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_STABLE      (14)      //!< Bit position for CCM_ANALOG_PFD_528_PFD1_STABLE.
#define BM_CCM_ANALOG_PFD_528_PFD1_STABLE      (0x00004000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD1_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD1_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD1_STABLE(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD1_STABLE) >> BP_CCM_ANALOG_PFD_528_PFD1_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_CLKGATE[15] (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_CLKGATE      (15)      //!< Bit position for CCM_ANALOG_PFD_528_PFD1_CLKGATE.
#define BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE      (0x00008000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD1_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD1_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD1_CLKGATE(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE) >> BP_CCM_ANALOG_PFD_528_PFD1_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD1_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD1_CLKGATE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_528_PFD1_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD1_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD1_CLKGATE(v)   (((v) << BP_CCM_ANALOG_PFD_528_PFD1_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_FRAC[21:16] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_FRAC      (16)      //!< Bit position for CCM_ANALOG_PFD_528_PFD2_FRAC.
#define BM_CCM_ANALOG_PFD_528_PFD2_FRAC      (0x003f0000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD2_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD2_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD2_FRAC(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD2_FRAC) >> BP_CCM_ANALOG_PFD_528_PFD2_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD2_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD2_FRAC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_528_PFD2_FRAC) & BM_CCM_ANALOG_PFD_528_PFD2_FRAC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD2_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD2_FRAC(v)   (((v) << BP_CCM_ANALOG_PFD_528_PFD2_FRAC) & BM_CCM_ANALOG_PFD_528_PFD2_FRAC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_STABLE[22] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_STABLE      (22)      //!< Bit position for CCM_ANALOG_PFD_528_PFD2_STABLE.
#define BM_CCM_ANALOG_PFD_528_PFD2_STABLE      (0x00400000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD2_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD2_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD2_STABLE(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD2_STABLE) >> BP_CCM_ANALOG_PFD_528_PFD2_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_CLKGATE[23] (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_CLKGATE      (23)      //!< Bit position for CCM_ANALOG_PFD_528_PFD2_CLKGATE.
#define BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE      (0x00800000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD2_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD2_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD2_CLKGATE(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE) >> BP_CCM_ANALOG_PFD_528_PFD2_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD2_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD2_CLKGATE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_528_PFD2_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD2_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD2_CLKGATE(v)   (((v) << BP_CCM_ANALOG_PFD_528_PFD2_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_FRAC[29:24] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_FRAC      (24)      //!< Bit position for CCM_ANALOG_PFD_528_PFD3_FRAC.
#define BM_CCM_ANALOG_PFD_528_PFD3_FRAC      (0x3f000000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD3_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD3_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD3_FRAC(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD3_FRAC) >> BP_CCM_ANALOG_PFD_528_PFD3_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD3_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD3_FRAC(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_528_PFD3_FRAC) & BM_CCM_ANALOG_PFD_528_PFD3_FRAC)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD3_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD3_FRAC(v)   (((v) << BP_CCM_ANALOG_PFD_528_PFD3_FRAC) & BM_CCM_ANALOG_PFD_528_PFD3_FRAC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_STABLE[30] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_STABLE      (30)      //!< Bit position for CCM_ANALOG_PFD_528_PFD3_STABLE.
#define BM_CCM_ANALOG_PFD_528_PFD3_STABLE      (0x40000000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD3_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD3_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD3_STABLE(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD3_STABLE) >> BP_CCM_ANALOG_PFD_528_PFD3_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_CLKGATE[31] (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_CLKGATE      (31)      //!< Bit position for CCM_ANALOG_PFD_528_PFD3_CLKGATE.
#define BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE      (0x80000000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD3_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD3_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD3_CLKGATE(r)   (((r) & BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE) >> BP_CCM_ANALOG_PFD_528_PFD3_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD3_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD3_CLKGATE(v)   ((((reg32_t) v) << BP_CCM_ANALOG_PFD_528_PFD3_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE)
#else
//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD3_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD3_CLKGATE(v)   (((v) << BP_CCM_ANALOG_PFD_528_PFD3_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD3_CLKGATE, v)
#endif


/*!
 * @brief All CCM_ANALOG module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_ccm_analog
{
    volatile hw_ccm_analog_pll_sys_t PLL_SYS; //!< Analog System PLL control Register
    volatile reg32_t PLL_SYS_SET; //!< Analog System PLL control Register Set
    volatile reg32_t PLL_SYS_CLR; //!< Analog System PLL control Register Clear
    volatile reg32_t PLL_SYS_TOG; //!< Analog System PLL control Register Toggle
    volatile hw_ccm_analog_usbphy0_pll_480_ctrl_t USBPHY0_PLL_480_CTRL; //!< Analog USBPHY0 480MHz PLL Control Register
    volatile reg32_t USBPHY0_PLL_480_CTRL_SET; //!< Analog USBPHY0 480MHz PLL Control Register Set
    volatile reg32_t USBPHY0_PLL_480_CTRL_CLR; //!< Analog USBPHY0 480MHz PLL Control Register Clear
    volatile reg32_t USBPHY0_PLL_480_CTRL_TOG; //!< Analog USBPHY0 480MHz PLL Control Register Toggle
    volatile hw_ccm_analog_usbphy1_pll_480_ctrl_t USBPHY1_PLL_480_CTRL; //!< Analog USBPHY1 480MHz PLL Control Register
    volatile reg32_t USBPHY1_PLL_480_CTRL_SET; //!< Analog USBPHY1 480MHz PLL Control Register Set
    volatile reg32_t USBPHY1_PLL_480_CTRL_CLR; //!< Analog USBPHY1 480MHz PLL Control Register Clear
    volatile reg32_t USBPHY1_PLL_480_CTRL_TOG; //!< Analog USBPHY1 480MHz PLL Control Register Toggle
    volatile hw_ccm_analog_pll_528_t PLL_528; //!< Analog 528MHz PLL Control Register
    volatile reg32_t PLL_528_SET; //!< Analog 528MHz PLL Control Register Set
    volatile reg32_t PLL_528_CLR; //!< Analog 528MHz PLL Control Register Clear
    volatile reg32_t PLL_528_TOG; //!< Analog 528MHz PLL Control Register Toggle
    volatile hw_ccm_analog_pll_528_ss_t PLL_528_SS; //!< 528MHz PLL Spread Spectrum Register.
    reg32_t _reserved0[3];
    volatile hw_ccm_analog_pll_528_num_t PLL_528_NUM; //!< Numerator of 528MHz PLL Fractional Loop Divider Register
    reg32_t _reserved1[3];
    volatile hw_ccm_analog_pll_528_denom_t PLL_528_DENOM; //!< Denominator of 528MHz PLL Fractional Loop Divider Register
    reg32_t _reserved2[3];
    volatile hw_ccm_analog_pll_audio_t PLL_AUDIO; //!< Analog Audio PLL control Register
    volatile reg32_t PLL_AUDIO_SET; //!< Analog Audio PLL control Register Set
    volatile reg32_t PLL_AUDIO_CLR; //!< Analog Audio PLL control Register Clear
    volatile reg32_t PLL_AUDIO_TOG; //!< Analog Audio PLL control Register Toggle
    volatile hw_ccm_analog_pll_audio_num_t PLL_AUDIO_NUM; //!< Numerator of Audio PLL Fractional Loop Divider Register
    reg32_t _reserved3[3];
    volatile hw_ccm_analog_pll_audio_denom_t PLL_AUDIO_DENOM; //!< Denominator of Audio PLL Fractional Loop Divider Register
    reg32_t _reserved4[3];
    volatile hw_ccm_analog_pll_video_t PLL_VIDEO; //!< Analog Video PLL control Register
    volatile reg32_t PLL_VIDEO_SET; //!< Analog Video PLL control Register Set
    volatile reg32_t PLL_VIDEO_CLR; //!< Analog Video PLL control Register Clear
    volatile reg32_t PLL_VIDEO_TOG; //!< Analog Video PLL control Register Toggle
    volatile hw_ccm_analog_pll_video_num_t PLL_VIDEO_NUM; //!< Numerator of Video PLL Fractional Loop Divider Register
    reg32_t _reserved5[3];
    volatile hw_ccm_analog_pll_video_denom_t PLL_VIDEO_DENOM; //!< Denominator of Video PLL Fractional Loop Divider Register
    reg32_t _reserved6[3];
    volatile hw_ccm_analog_pll_mlb_t PLL_MLB; //!< MLB PLL Control Register
    volatile reg32_t PLL_MLB_SET; //!< MLB PLL Control Register Set
    volatile reg32_t PLL_MLB_CLR; //!< MLB PLL Control Register Clear
    volatile reg32_t PLL_MLB_TOG; //!< MLB PLL Control Register Toggle
    volatile hw_ccm_analog_pll_enet_t PLL_ENET; //!< Analog ENET PLL Control Register
    volatile reg32_t PLL_ENET_SET; //!< Analog ENET PLL Control Register Set
    volatile reg32_t PLL_ENET_CLR; //!< Analog ENET PLL Control Register Clear
    volatile reg32_t PLL_ENET_TOG; //!< Analog ENET PLL Control Register Toggle
    volatile hw_ccm_analog_pfd_480_t PFD_480; //!< 480MHz Clock Phase Fractional Divider Control Register
    volatile reg32_t PFD_480_SET; //!< 480MHz Clock Phase Fractional Divider Control Register Set
    volatile reg32_t PFD_480_CLR; //!< 480MHz Clock Phase Fractional Divider Control Register Clear
    volatile reg32_t PFD_480_TOG; //!< 480MHz Clock Phase Fractional Divider Control Register Toggle
    volatile hw_ccm_analog_pfd_528_t PFD_528; //!< 528MHz Clock Phase Fractional Divider Control Register
    volatile reg32_t PFD_528_SET; //!< 528MHz Clock Phase Fractional Divider Control Register Set
    volatile reg32_t PFD_528_CLR; //!< 528MHz Clock Phase Fractional Divider Control Register Clear
    volatile reg32_t PFD_528_TOG; //!< 528MHz Clock Phase Fractional Divider Control Register Toggle
} hw_ccm_analog_t;
#pragma pack()

//! @brief Macro to access all CCM_ANALOG registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CCM_ANALOG(0)</code>.
#define HW_CCM_ANALOG     (*(volatile hw_ccm_analog_t *) REGS_CCM_ANALOG_BASE)

#endif


#endif // __HW_CCM_ANALOG_REGISTERS_H__
