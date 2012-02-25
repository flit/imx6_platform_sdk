/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USBNC_H
#define _USBNC_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_USBNC_USB_OTG_CTRL - USB OTG Control Register
 * - HW_USBNC_USB_UH1_CTRL - USB Host1 Control Register
 * - HW_USBNC_USB_UH2_CTRL - USB Host2 Control Register
 * - HW_USBNC_USB_UH3_CTRL - USB Host3 Control Register
 * - HW_USBNC_USB_UH2_HSIC_CTRL - USB Host2 HSIC Control Register
 * - HW_USBNC_USB_UH3_HSIC_CTRL - USB Host3 HSIC Control Register
 * - HW_USBNC_USB_OTG_PHY_CTRL_0 - OTG UTMI PHY Control 0 Register
 * - HW_USBNC_USB_UH1_PHY_CTRL_0 - Host1 UTMI PHY Control 0 Register
 *
 * hw_usbnc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_USBNC_BASE
#define REGS_USBNC_BASE (0x02184000) //!< Base address for USBNC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_OTG_CTRL - USB OTG Control Register (RW)
 *
 * The USB OTG control register controls the integration specific features of the USB OTG module.
 * These features are not directly related to the USB functionality, but control special features,
 * interfacing on the USB ports, as well as power control and wake-up functionality.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned OVER_CUR_DIS : 1; //!< Disable OTG Overcurrent Detection
        unsigned OVER_CUR_POL : 1; //!< OTG Polarity of Overcurrent The polarity of OTG port overcurrent event
        unsigned PWR_POL : 1; //!< OTG Power Polarity This bit should be set according to PMIC Power Pin polarity.
        unsigned WIE : 1; //!< OTG Wake-up Interrupt Enable This bit enables or disables the OTG wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force OTG UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force OTG UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode. For Freescale test only.
        unsigned UTMI_ON_CLOCK : 1; //!< Force OTG UTMI PHY clock output on even if suspend mode.
        unsigned WKUP_SW_EN : 1; //!< OTG Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< OTG Software Wake-up
        unsigned WKUP_ID_EN : 1; //!< OTG Wake-up on ID change enable
        unsigned WKUP_VBUS_EN : 1; //!< OTG wake-up on VBUS change enable
        unsigned RESERVED1 : 13; //!< Reserved
        unsigned WIR : 1; //!< OTG Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
    } B;
} hw_usbnc_usb_otg_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_OTG_CTRL register
 */
#define HW_USBNC_USB_OTG_CTRL_ADDR      (REGS_USBNC_BASE + 0x800)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_OTG_CTRL           (*(volatile hw_usbnc_usb_otg_ctrl_t *) HW_USBNC_USB_OTG_CTRL_ADDR)
#define HW_USBNC_USB_OTG_CTRL_RD()      (HW_USBNC_USB_OTG_CTRL.U)
#define HW_USBNC_USB_OTG_CTRL_WR(v)     (HW_USBNC_USB_OTG_CTRL.U = (v))
#define HW_USBNC_USB_OTG_CTRL_SET(v)    (HW_USBNC_USB_OTG_CTRL_WR(HW_USBNC_USB_OTG_CTRL_RD() |  (v)))
#define HW_USBNC_USB_OTG_CTRL_CLR(v)    (HW_USBNC_USB_OTG_CTRL_WR(HW_USBNC_USB_OTG_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_OTG_CTRL_TOG(v)    (HW_USBNC_USB_OTG_CTRL_WR(HW_USBNC_USB_OTG_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_OTG_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_OTG_CTRL, field OVER_CUR_DIS[7:7] (RW)
 *
 * Disable OTG Overcurrent Detection
 *
 * Values:
 * 0 - Enables overcurrent detection
 * 1 - Disables overcurrent detection
 */

#define BP_USBNC_USB_OTG_CTRL_OVER_CUR_DIS      (7)
#define BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   ((((reg32_t) v) << 7) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS)
#else
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   (((v) << 7) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVER_CUR_DIS field to a new value.
#define BW_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   BF_CS1(USBNC_USB_OTG_CTRL, OVER_CUR_DIS, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field OVER_CUR_POL[8:8] (RW)
 *
 * OTG Polarity of Overcurrent The polarity of OTG port overcurrent event
 *
 * Values:
 * 0 - High active
 * 1 - Low active
 */

#define BP_USBNC_USB_OTG_CTRL_OVER_CUR_POL      (8)
#define BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   ((((reg32_t) v) << 8) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL)
#else
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   (((v) << 8) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVER_CUR_POL field to a new value.
#define BW_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   BF_CS1(USBNC_USB_OTG_CTRL, OVER_CUR_POL, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field PWR_POL[9:9] (RW)
 *
 * OTG Power Polarity This bit should be set according to PMIC Power Pin polarity.
 *
 * Values:
 * 0 - PMIC Power Pin is Low active.
 * 1 - PMIC Power Pin is High active.
 */

#define BP_USBNC_USB_OTG_CTRL_PWR_POL      (9)
#define BM_USBNC_USB_OTG_CTRL_PWR_POL      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_PWR_POL(v)   ((((reg32_t) v) << 9) & BM_USBNC_USB_OTG_CTRL_PWR_POL)
#else
#define BF_USBNC_USB_OTG_CTRL_PWR_POL(v)   (((v) << 9) & BM_USBNC_USB_OTG_CTRL_PWR_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PWR_POL field to a new value.
#define BW_USBNC_USB_OTG_CTRL_PWR_POL(v)   BF_CS1(USBNC_USB_OTG_CTRL, PWR_POL, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field WIE[10:10] (RW)
 *
 * OTG Wake-up Interrupt Enable This bit enables or disables the OTG wake-up interrupt. Disabling
 * the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned
 * off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
 *
 * Values:
 * 0 - Interrupt Disabled
 * 1 - Interrupt Enabled
 */

#define BP_USBNC_USB_OTG_CTRL_WIE      (10)
#define BM_USBNC_USB_OTG_CTRL_WIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_OTG_CTRL_WIE)
#else
#define BF_USBNC_USB_OTG_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_OTG_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_USBNC_USB_OTG_CTRL_WIE(v)   BF_CS1(USBNC_USB_OTG_CTRL, WIE, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field RESET[11:11] (RW)
 *
 * Force OTG UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
 *
 * Values:
 * 0 - Inactive
 * 1 - Reset the PHY
 */

#define BP_USBNC_USB_OTG_CTRL_RESET      (11)
#define BM_USBNC_USB_OTG_CTRL_RESET      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_OTG_CTRL_RESET)
#else
#define BF_USBNC_USB_OTG_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_OTG_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_USBNC_USB_OTG_CTRL_RESET(v)   BF_CS1(USBNC_USB_OTG_CTRL, RESET, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field SUSPENDM[12:12] (RW)
 *
 * Force OTG UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend
 * mode. For Freescale test only.
 *
 * Values:
 * 0 - Force OTG UTMI PHY Suspend
 * 1 - Inactive
 */

#define BP_USBNC_USB_OTG_CTRL_SUSPENDM      (12)
#define BM_USBNC_USB_OTG_CTRL_SUSPENDM      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_OTG_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_OTG_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_OTG_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSPENDM field to a new value.
#define BW_USBNC_USB_OTG_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_OTG_CTRL, SUSPENDM, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field UTMI_ON_CLOCK[13:13] (RW)
 *
 * Force OTG UTMI PHY clock output on even if suspend mode.
 *
 * Values:
 * 0 - Inactive
 * 1 - Force clock output on
 */

#define BP_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK      (13)
#define BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK)
#else
#define BF_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   (((v) << 13) & BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_ON_CLOCK field to a new value.
#define BW_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   BF_CS1(USBNC_USB_OTG_CTRL, UTMI_ON_CLOCK, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_SW_EN[14:14] (RW)
 *
 * OTG Software Wake-up Enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG_CTRL_WKUP_SW_EN      (14)
#define BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW_EN field to a new value.
#define BW_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_SW_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_SW[15:15] (RW)
 *
 * OTG Software Wake-up
 *
 * Values:
 * 0 - Inactive
 * 1 - Force wake-up
 */

#define BP_USBNC_USB_OTG_CTRL_WKUP_SW      (15)
#define BM_USBNC_USB_OTG_CTRL_WKUP_SW      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_OTG_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_OTG_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW field to a new value.
#define BW_USBNC_USB_OTG_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_SW, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_ID_EN[16:16] (RW)
 *
 * OTG Wake-up on ID change enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG_CTRL_WKUP_ID_EN      (16)
#define BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   (((v) << 16) & BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_ID_EN field to a new value.
#define BW_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_ID_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_VBUS_EN[17:17] (RW)
 *
 * OTG wake-up on VBUS change enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN      (17)
#define BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   ((((reg32_t) v) << 17) & BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   (((v) << 17) & BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_VBUS_EN field to a new value.
#define BW_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_VBUS_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG_CTRL, field WIR[31:31] (RO)
 *
 * OTG Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on
 * the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
 *
 * Values:
 * 0 - No wake-up interrupt request received
 * 1 - Wake-up Interrupt Request received
 */

#define BP_USBNC_USB_OTG_CTRL_WIR      (31)
#define BM_USBNC_USB_OTG_CTRL_WIR      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_UH1_CTRL - USB Host1 Control Register (RW)
 *
 * The USB Host1 control register controls the integration specific features of the USB Host1
 * module. These features are not directly related to the USB functionality, but control special
 * features, interfacing on the USB ports, as well as power control and wake-up functionality.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned OVER_CUR_DIS : 1; //!< Disable Host 1 Overcurrent Detection
        unsigned OVER_CUR_POL : 1; //!< Host 1 Polarity of Overcurrent The polarity of Host 1 port overcurrent event
        unsigned PWR_POL : 1; //!< Host1 Power Polarity This bit should be set according to PMIC Power Pin polarity.
        unsigned WIE : 1; //!< Host 1 Wake-up Interrupt Enable This bit enables or disables the Host 1 wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force Host 1 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force Host 1 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode. For Freescale test only.
        unsigned UTMI_ON_CLOCK : 1; //!< Force Host 1 UTMI PHY clock output on even if suspend mode.
        unsigned WKUP_SW_EN : 1; //!< Host 1 Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< Host 1 Software Wake-up
        unsigned WKUP_ID_EN : 1; //!< Host 1 Wake-up on ID change enable
        unsigned WKUP_VBUS_EN : 1; //!< Host 1 wake-up on VBUS change enable
        unsigned RESERVED1 : 13; //!< Reserved
        unsigned WIR : 1; //!< Host 1 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
    } B;
} hw_usbnc_usb_uh1_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH1_CTRL register
 */
#define HW_USBNC_USB_UH1_CTRL_ADDR      (REGS_USBNC_BASE + 0x804)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH1_CTRL           (*(volatile hw_usbnc_usb_uh1_ctrl_t *) HW_USBNC_USB_UH1_CTRL_ADDR)
#define HW_USBNC_USB_UH1_CTRL_RD()      (HW_USBNC_USB_UH1_CTRL.U)
#define HW_USBNC_USB_UH1_CTRL_WR(v)     (HW_USBNC_USB_UH1_CTRL.U = (v))
#define HW_USBNC_USB_UH1_CTRL_SET(v)    (HW_USBNC_USB_UH1_CTRL_WR(HW_USBNC_USB_UH1_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH1_CTRL_CLR(v)    (HW_USBNC_USB_UH1_CTRL_WR(HW_USBNC_USB_UH1_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH1_CTRL_TOG(v)    (HW_USBNC_USB_UH1_CTRL_WR(HW_USBNC_USB_UH1_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_UH1_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH1_CTRL, field OVER_CUR_DIS[7:7] (RW)
 *
 * Disable Host 1 Overcurrent Detection
 *
 * Values:
 * 0 - Enables overcurrent detection
 * 1 - Disables overcurrent detection
 */

#define BP_USBNC_USB_UH1_CTRL_OVER_CUR_DIS      (7)
#define BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   ((((reg32_t) v) << 7) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS)
#else
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   (((v) << 7) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVER_CUR_DIS field to a new value.
#define BW_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   BF_CS1(USBNC_USB_UH1_CTRL, OVER_CUR_DIS, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field OVER_CUR_POL[8:8] (RW)
 *
 * Host 1 Polarity of Overcurrent The polarity of Host 1 port overcurrent event
 *
 * Values:
 * 0 - High active
 * 1 - Low active
 */

#define BP_USBNC_USB_UH1_CTRL_OVER_CUR_POL      (8)
#define BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   ((((reg32_t) v) << 8) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL)
#else
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   (((v) << 8) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVER_CUR_POL field to a new value.
#define BW_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   BF_CS1(USBNC_USB_UH1_CTRL, OVER_CUR_POL, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field PWR_POL[9:9] (RW)
 *
 * Host1 Power Polarity This bit should be set according to PMIC Power Pin polarity.
 *
 * Values:
 * 0 - PMIC Power Pin is Low active.
 * 1 - PMIC Power Pin is High active.
 */

#define BP_USBNC_USB_UH1_CTRL_PWR_POL      (9)
#define BM_USBNC_USB_UH1_CTRL_PWR_POL      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_PWR_POL(v)   ((((reg32_t) v) << 9) & BM_USBNC_USB_UH1_CTRL_PWR_POL)
#else
#define BF_USBNC_USB_UH1_CTRL_PWR_POL(v)   (((v) << 9) & BM_USBNC_USB_UH1_CTRL_PWR_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PWR_POL field to a new value.
#define BW_USBNC_USB_UH1_CTRL_PWR_POL(v)   BF_CS1(USBNC_USB_UH1_CTRL, PWR_POL, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field WIE[10:10] (RW)
 *
 * Host 1 Wake-up Interrupt Enable This bit enables or disables the Host 1 wake-up interrupt.
 * Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be
 * turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
 *
 * Values:
 * 0 - Interrupt Disabled
 * 1 - Interrupt Enabled
 */

#define BP_USBNC_USB_UH1_CTRL_WIE      (10)
#define BM_USBNC_USB_UH1_CTRL_WIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH1_CTRL_WIE)
#else
#define BF_USBNC_USB_UH1_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH1_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_USBNC_USB_UH1_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH1_CTRL, WIE, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field RESET[11:11] (RW)
 *
 * Force Host 1 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
 *
 * Values:
 * 0 - Inactive
 * 1 - Reset the PHY
 */

#define BP_USBNC_USB_UH1_CTRL_RESET      (11)
#define BM_USBNC_USB_UH1_CTRL_RESET      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH1_CTRL_RESET)
#else
#define BF_USBNC_USB_UH1_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH1_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_USBNC_USB_UH1_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH1_CTRL, RESET, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field SUSPENDM[12:12] (RW)
 *
 * Force Host 1 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend
 * mode. For Freescale test only.
 *
 * Values:
 * 0 - Enable
 * 1 - Disable
 */

#define BP_USBNC_USB_UH1_CTRL_SUSPENDM      (12)
#define BM_USBNC_USB_UH1_CTRL_SUSPENDM      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH1_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH1_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH1_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSPENDM field to a new value.
#define BW_USBNC_USB_UH1_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH1_CTRL, SUSPENDM, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field UTMI_ON_CLOCK[13:13] (RW)
 *
 * Force Host 1 UTMI PHY clock output on even if suspend mode.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK      (13)
#define BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK)
#else
#define BF_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   (((v) << 13) & BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_ON_CLOCK field to a new value.
#define BW_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   BF_CS1(USBNC_USB_UH1_CTRL, UTMI_ON_CLOCK, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_SW_EN[14:14] (RW)
 *
 * Host 1 Software Wake-up Enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_UH1_CTRL_WKUP_SW_EN      (14)
#define BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW_EN field to a new value.
#define BW_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_SW_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_SW[15:15] (RW)
 *
 * Host 1 Software Wake-up
 *
 * Values:
 * 0 - Inactive
 * 1 - Force wake-up
 */

#define BP_USBNC_USB_UH1_CTRL_WKUP_SW      (15)
#define BM_USBNC_USB_UH1_CTRL_WKUP_SW      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH1_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH1_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW field to a new value.
#define BW_USBNC_USB_UH1_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_SW, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_ID_EN[16:16] (RW)
 *
 * Host 1 Wake-up on ID change enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_UH1_CTRL_WKUP_ID_EN      (16)
#define BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   (((v) << 16) & BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_ID_EN field to a new value.
#define BW_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_ID_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_VBUS_EN[17:17] (RW)
 *
 * Host 1 wake-up on VBUS change enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN      (17)
#define BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   ((((reg32_t) v) << 17) & BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   (((v) << 17) & BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_VBUS_EN field to a new value.
#define BW_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_VBUS_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH1_CTRL, field WIR[31:31] (RO)
 *
 * Host 1 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received
 * on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
 *
 * Values:
 * 0 - No wake-up interrupt request received
 * 1 - Wake-up Interrupt Request received
 */

#define BP_USBNC_USB_UH1_CTRL_WIR      (31)
#define BM_USBNC_USB_UH1_CTRL_WIR      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_UH2_CTRL - USB Host2 Control Register (RW)
 *
 * The USB Host2 control register controls the integration specific features of the USB host2
 * module. These features are not directly related to the USB functionality, but control special
 * features, interfacing on the USB ports, as well as power control and wake-up functionality.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned WIE : 1; //!< Host 2 Wake-up Interrupt Enable This bit enables or disables the Host 2 wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force Host 2 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force Host 2 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode. For Freescale test only.
        unsigned _480M_CLK_ON : 1; //!< Force OTG UTMI PHY 480M clock output on when Host 2 is not in suspend mode.
        unsigned WKUP_SW_EN : 1; //!< Host 2 Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< Host 2 Software Wake-up
        unsigned RESERVED1 : 15; //!< Reserved
        unsigned WIR : 1; //!< Host 2 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on the Host 2 port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
    } B;
} hw_usbnc_usb_uh2_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH2_CTRL register
 */
#define HW_USBNC_USB_UH2_CTRL_ADDR      (REGS_USBNC_BASE + 0x808)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH2_CTRL           (*(volatile hw_usbnc_usb_uh2_ctrl_t *) HW_USBNC_USB_UH2_CTRL_ADDR)
#define HW_USBNC_USB_UH2_CTRL_RD()      (HW_USBNC_USB_UH2_CTRL.U)
#define HW_USBNC_USB_UH2_CTRL_WR(v)     (HW_USBNC_USB_UH2_CTRL.U = (v))
#define HW_USBNC_USB_UH2_CTRL_SET(v)    (HW_USBNC_USB_UH2_CTRL_WR(HW_USBNC_USB_UH2_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH2_CTRL_CLR(v)    (HW_USBNC_USB_UH2_CTRL_WR(HW_USBNC_USB_UH2_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH2_CTRL_TOG(v)    (HW_USBNC_USB_UH2_CTRL_WR(HW_USBNC_USB_UH2_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_UH2_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH2_CTRL, field WIE[10:10] (RW)
 *
 * Host 2 Wake-up Interrupt Enable This bit enables or disables the Host 2 wake-up interrupt.
 * Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be
 * turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
 *
 * Values:
 * 0 - Interrupt Disabled
 * 1 - Interrupt Enabled
 */

#define BP_USBNC_USB_UH2_CTRL_WIE      (10)
#define BM_USBNC_USB_UH2_CTRL_WIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH2_CTRL_WIE)
#else
#define BF_USBNC_USB_UH2_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH2_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_USBNC_USB_UH2_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH2_CTRL, WIE, v)
#endif


/* --- Register HW_USBNC_USB_UH2_CTRL, field RESET[11:11] (RW)
 *
 * Force Host 2 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
 *
 * Values:
 * 0 - Inactive
 * 1 - Reset the PHY
 */

#define BP_USBNC_USB_UH2_CTRL_RESET      (11)
#define BM_USBNC_USB_UH2_CTRL_RESET      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH2_CTRL_RESET)
#else
#define BF_USBNC_USB_UH2_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH2_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_USBNC_USB_UH2_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH2_CTRL, RESET, v)
#endif


/* --- Register HW_USBNC_USB_UH2_CTRL, field SUSPENDM[12:12] (RW)
 *
 * Force Host 2 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend
 * mode. For Freescale test only.
 *
 * Values:
 * 0 - Enable
 * 1 - Disable
 */

#define BP_USBNC_USB_UH2_CTRL_SUSPENDM      (12)
#define BM_USBNC_USB_UH2_CTRL_SUSPENDM      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH2_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH2_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH2_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSPENDM field to a new value.
#define BW_USBNC_USB_UH2_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH2_CTRL, SUSPENDM, v)
#endif


/* --- Register HW_USBNC_USB_UH2_CTRL, field _480M_CLK_ON[13:13] (RW)
 *
 * Force OTG UTMI PHY 480M clock output on when Host 2 is not in suspend mode.
 *
 * Values:
 * 0 - Inactive
 * 1 - Force OTG UTMI PHY 480M clock output on
 */

#define BP_USBNC_USB_UH2_CTRL__480M_CLK_ON      (13)
#define BM_USBNC_USB_UH2_CTRL__480M_CLK_ON      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL__480M_CLK_ON(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_UH2_CTRL__480M_CLK_ON)
#else
#define BF_USBNC_USB_UH2_CTRL__480M_CLK_ON(v)   (((v) << 13) & BM_USBNC_USB_UH2_CTRL__480M_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the _480M_CLK_ON field to a new value.
#define BW_USBNC_USB_UH2_CTRL__480M_CLK_ON(v)   BF_CS1(USBNC_USB_UH2_CTRL, _480M_CLK_ON, v)
#endif


/* --- Register HW_USBNC_USB_UH2_CTRL, field WKUP_SW_EN[14:14] (RW)
 *
 * Host 2 Software Wake-up Enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_UH2_CTRL_WKUP_SW_EN      (14)
#define BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW_EN field to a new value.
#define BW_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH2_CTRL, WKUP_SW_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH2_CTRL, field WKUP_SW[15:15] (RW)
 *
 * Host 2 Software Wake-up
 *
 * Values:
 * 0 - Inactive
 * 1 - Force wake-up
 */

#define BP_USBNC_USB_UH2_CTRL_WKUP_SW      (15)
#define BM_USBNC_USB_UH2_CTRL_WKUP_SW      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH2_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH2_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW field to a new value.
#define BW_USBNC_USB_UH2_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH2_CTRL, WKUP_SW, v)
#endif


/* --- Register HW_USBNC_USB_UH2_CTRL, field WIR[31:31] (RO)
 *
 * Host 2 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received
 * on the Host 2 port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
 *
 * Values:
 * 0 - No wake-up interrupt request received
 * 1 - Wake-up Interrupt Request received
 */

#define BP_USBNC_USB_UH2_CTRL_WIR      (31)
#define BM_USBNC_USB_UH2_CTRL_WIR      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_UH3_CTRL - USB Host3 Control Register (RW)
 *
 * The USB Host3 control register controls the integration specific features of the USB Host3
 * module. These features are not directly related to the USB functionality, but control special
 * features, interfacing on the USB ports, as well as power control and wake-up functionality.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved0
        unsigned WIE : 1; //!< Host 3 Wake-up Interrupt Enable This bit enables or disables the Host 3 wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force Host 3 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force Host 3 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode. For Freescale test only.
        unsigned _480M_CLK_ON : 1; //!< Force OTG UTMI PHY 480M clock output on when Host 3 is not in suspend mode.
        unsigned WKUP_SW_EN : 1; //!< Host 3 Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< Host 3 Software Wake-up
        unsigned RESERVED1 : 15; //!< Reserved
        unsigned WIR : 1; //!< Host 3 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
    } B;
} hw_usbnc_usb_uh3_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH3_CTRL register
 */
#define HW_USBNC_USB_UH3_CTRL_ADDR      (REGS_USBNC_BASE + 0x80c)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH3_CTRL           (*(volatile hw_usbnc_usb_uh3_ctrl_t *) HW_USBNC_USB_UH3_CTRL_ADDR)
#define HW_USBNC_USB_UH3_CTRL_RD()      (HW_USBNC_USB_UH3_CTRL.U)
#define HW_USBNC_USB_UH3_CTRL_WR(v)     (HW_USBNC_USB_UH3_CTRL.U = (v))
#define HW_USBNC_USB_UH3_CTRL_SET(v)    (HW_USBNC_USB_UH3_CTRL_WR(HW_USBNC_USB_UH3_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH3_CTRL_CLR(v)    (HW_USBNC_USB_UH3_CTRL_WR(HW_USBNC_USB_UH3_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH3_CTRL_TOG(v)    (HW_USBNC_USB_UH3_CTRL_WR(HW_USBNC_USB_UH3_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_UH3_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH3_CTRL, field WIE[10:10] (RW)
 *
 * Host 3 Wake-up Interrupt Enable This bit enables or disables the Host 3 wake-up interrupt.
 * Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be
 * turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
 *
 * Values:
 * 0 - Interrupt Disabled
 * 1 - Interrupt Enabled
 */

#define BP_USBNC_USB_UH3_CTRL_WIE      (10)
#define BM_USBNC_USB_UH3_CTRL_WIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH3_CTRL_WIE)
#else
#define BF_USBNC_USB_UH3_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH3_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_USBNC_USB_UH3_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH3_CTRL, WIE, v)
#endif


/* --- Register HW_USBNC_USB_UH3_CTRL, field RESET[11:11] (RW)
 *
 * Force Host 3 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
 *
 * Values:
 * 0 - Inactive
 * 1 - Reset the PHY
 */

#define BP_USBNC_USB_UH3_CTRL_RESET      (11)
#define BM_USBNC_USB_UH3_CTRL_RESET      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH3_CTRL_RESET)
#else
#define BF_USBNC_USB_UH3_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH3_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_USBNC_USB_UH3_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH3_CTRL, RESET, v)
#endif


/* --- Register HW_USBNC_USB_UH3_CTRL, field SUSPENDM[12:12] (RW)
 *
 * Force Host 3 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend
 * mode. For Freescale test only.
 *
 * Values:
 * 0 - Force OTG UTMI PHY Suspend
 * 1 - Inactive
 */

#define BP_USBNC_USB_UH3_CTRL_SUSPENDM      (12)
#define BM_USBNC_USB_UH3_CTRL_SUSPENDM      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH3_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH3_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH3_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSPENDM field to a new value.
#define BW_USBNC_USB_UH3_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH3_CTRL, SUSPENDM, v)
#endif


/* --- Register HW_USBNC_USB_UH3_CTRL, field _480M_CLK_ON[13:13] (RW)
 *
 * Force OTG UTMI PHY 480M clock output on when Host 3 is not in suspend mode.
 *
 * Values:
 * 0 - Inactive
 * 1 - Force OTG UTMI PHY 480M clock output on
 */

#define BP_USBNC_USB_UH3_CTRL__480M_CLK_ON      (13)
#define BM_USBNC_USB_UH3_CTRL__480M_CLK_ON      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL__480M_CLK_ON(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_UH3_CTRL__480M_CLK_ON)
#else
#define BF_USBNC_USB_UH3_CTRL__480M_CLK_ON(v)   (((v) << 13) & BM_USBNC_USB_UH3_CTRL__480M_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the _480M_CLK_ON field to a new value.
#define BW_USBNC_USB_UH3_CTRL__480M_CLK_ON(v)   BF_CS1(USBNC_USB_UH3_CTRL, _480M_CLK_ON, v)
#endif


/* --- Register HW_USBNC_USB_UH3_CTRL, field WKUP_SW_EN[14:14] (RW)
 *
 * Host 3 Software Wake-up Enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_UH3_CTRL_WKUP_SW_EN      (14)
#define BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW_EN field to a new value.
#define BW_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH3_CTRL, WKUP_SW_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH3_CTRL, field WKUP_SW[15:15] (RW)
 *
 * Host 3 Software Wake-up
 *
 * Values:
 * 0 - Inactive
 * 1 - Force wake-up
 */

#define BP_USBNC_USB_UH3_CTRL_WKUP_SW      (15)
#define BM_USBNC_USB_UH3_CTRL_WKUP_SW      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH3_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH3_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW field to a new value.
#define BW_USBNC_USB_UH3_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH3_CTRL, WKUP_SW, v)
#endif


/* --- Register HW_USBNC_USB_UH3_CTRL, field WIR[31:31] (RO)
 *
 * Host 3 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received
 * on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
 *
 * Values:
 * 0 - No Wake-up interrupt received
 * 1 - Wake-up interrupt received
 */

#define BP_USBNC_USB_UH3_CTRL_WIR      (31)
#define BM_USBNC_USB_UH3_CTRL_WIR      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_UH2_HSIC_CTRL - USB Host2 HSIC Control Register (RW)
 *
 * The USB Host2 HSIC control register controls Host2 high speed IC configuration. These features
 * are not directly related to the USB functionality, but control special features, interfacing on
 * the USB ports, as well as power control.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned HSIC_CLK_ON : 1; //!< Force Host2 HSIC module 480M clock on, even when in Host 2 is in suspend mode.
        unsigned HSIC_EN : 1; //!< Host2 HSIC enable
        unsigned RESERVED1 : 18; //!< Reserved
        unsigned CLK_VLD : 1; //!< Indicating whether Host2 HSIC clock is valid.
    } B;
} hw_usbnc_usb_uh2_hsic_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH2_HSIC_CTRL register
 */
#define HW_USBNC_USB_UH2_HSIC_CTRL_ADDR      (REGS_USBNC_BASE + 0x810)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH2_HSIC_CTRL           (*(volatile hw_usbnc_usb_uh2_hsic_ctrl_t *) HW_USBNC_USB_UH2_HSIC_CTRL_ADDR)
#define HW_USBNC_USB_UH2_HSIC_CTRL_RD()      (HW_USBNC_USB_UH2_HSIC_CTRL.U)
#define HW_USBNC_USB_UH2_HSIC_CTRL_WR(v)     (HW_USBNC_USB_UH2_HSIC_CTRL.U = (v))
#define HW_USBNC_USB_UH2_HSIC_CTRL_SET(v)    (HW_USBNC_USB_UH2_HSIC_CTRL_WR(HW_USBNC_USB_UH2_HSIC_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH2_HSIC_CTRL_CLR(v)    (HW_USBNC_USB_UH2_HSIC_CTRL_WR(HW_USBNC_USB_UH2_HSIC_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH2_HSIC_CTRL_TOG(v)    (HW_USBNC_USB_UH2_HSIC_CTRL_WR(HW_USBNC_USB_UH2_HSIC_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_UH2_HSIC_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field HSIC_CLK_ON[11:11] (RW)
 *
 * Force Host2 HSIC module 480M clock on, even when in Host 2 is in suspend mode.
 *
 * Values:
 * 0 - Inactive
 * 1 - Active
 */

#define BP_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON      (11)
#define BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   (((v) << 11) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSIC_CLK_ON field to a new value.
#define BW_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, HSIC_CLK_ON, v)
#endif


/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field HSIC_EN[12:12] (RW)
 *
 * Host2 HSIC enable
 *
 * Values:
 * 0 - Disabled
 * 1 - Enabled
 */

#define BP_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN      (12)
#define BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   (((v) << 12) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSIC_EN field to a new value.
#define BW_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, HSIC_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field CLK_VLD[31:31] (RO)
 *
 * Indicating whether Host2 HSIC clock is valid.
 *
 * Values:
 * 1 - Valid
 * 2 - Invalid
 */

#define BP_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD      (31)
#define BM_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_UH3_HSIC_CTRL - USB Host3 HSIC Control Register (RW)
 *
 * The USB Host3 HSIC control register controls Host3 high speed IC configuration. These features
 * are not directly related to the USB functionality, but control special features, interfacing on
 * the USB ports, as well as power control.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned HSIC_CLK_ON : 1; //!< Force Host3 HSIC module 480M clock on, even when in Host 2 is in suspend mode.
        unsigned HSIC_EN : 1; //!< Host3 HSIC enable
        unsigned RESERVED1 : 18; //!< Reserved
        unsigned CLK_VLD : 1; //!< Indicating whether Host3 HSIC clock is valid.
    } B;
} hw_usbnc_usb_uh3_hsic_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH3_HSIC_CTRL register
 */
#define HW_USBNC_USB_UH3_HSIC_CTRL_ADDR      (REGS_USBNC_BASE + 0x814)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH3_HSIC_CTRL           (*(volatile hw_usbnc_usb_uh3_hsic_ctrl_t *) HW_USBNC_USB_UH3_HSIC_CTRL_ADDR)
#define HW_USBNC_USB_UH3_HSIC_CTRL_RD()      (HW_USBNC_USB_UH3_HSIC_CTRL.U)
#define HW_USBNC_USB_UH3_HSIC_CTRL_WR(v)     (HW_USBNC_USB_UH3_HSIC_CTRL.U = (v))
#define HW_USBNC_USB_UH3_HSIC_CTRL_SET(v)    (HW_USBNC_USB_UH3_HSIC_CTRL_WR(HW_USBNC_USB_UH3_HSIC_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH3_HSIC_CTRL_CLR(v)    (HW_USBNC_USB_UH3_HSIC_CTRL_WR(HW_USBNC_USB_UH3_HSIC_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH3_HSIC_CTRL_TOG(v)    (HW_USBNC_USB_UH3_HSIC_CTRL_WR(HW_USBNC_USB_UH3_HSIC_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_UH3_HSIC_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field HSIC_CLK_ON[11:11] (RW)
 *
 * Force Host3 HSIC module 480M clock on, even when in Host 2 is in suspend mode.
 *
 * Values:
 * 0 - Inactive
 * 1 - Active
 */

#define BP_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON      (11)
#define BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   (((v) << 11) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSIC_CLK_ON field to a new value.
#define BW_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, HSIC_CLK_ON, v)
#endif


/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field HSIC_EN[12:12] (RW)
 *
 * Host3 HSIC enable
 *
 * Values:
 * 0 - Disabled
 * 1 - Enabled
 */

#define BP_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN      (12)
#define BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   (((v) << 12) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSIC_EN field to a new value.
#define BW_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, HSIC_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field CLK_VLD[31:31] (RO)
 *
 * Indicating whether Host3 HSIC clock is valid.
 *
 * Values:
 * 1 - Valid
 * 2 - Invalid
 */

#define BP_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD      (31)
#define BM_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_OTG_PHY_CTRL_0 - OTG UTMI PHY Control 0 Register (RW)
 *
 * USB OTG UTMI PHY control register 0 is used to control the on-chip OTG UTMI PHY.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned RESERVED1 : 28; //!< Reserved
        unsigned UTMI_CLK_VLD : 1; //!< Indicating whether OTG UTMI PHY clock is valid
    } B;
} hw_usbnc_usb_otg_phy_ctrl_0_t;
#endif

/*
 * constants & macros for entire USBNC_USB_OTG_PHY_CTRL_0 register
 */
#define HW_USBNC_USB_OTG_PHY_CTRL_0_ADDR      (REGS_USBNC_BASE + 0x818)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_OTG_PHY_CTRL_0           (*(volatile hw_usbnc_usb_otg_phy_ctrl_0_t *) HW_USBNC_USB_OTG_PHY_CTRL_0_ADDR)
#define HW_USBNC_USB_OTG_PHY_CTRL_0_RD()      (HW_USBNC_USB_OTG_PHY_CTRL_0.U)
#define HW_USBNC_USB_OTG_PHY_CTRL_0_WR(v)     (HW_USBNC_USB_OTG_PHY_CTRL_0.U = (v))
#define HW_USBNC_USB_OTG_PHY_CTRL_0_SET(v)    (HW_USBNC_USB_OTG_PHY_CTRL_0_WR(HW_USBNC_USB_OTG_PHY_CTRL_0_RD() |  (v)))
#define HW_USBNC_USB_OTG_PHY_CTRL_0_CLR(v)    (HW_USBNC_USB_OTG_PHY_CTRL_0_WR(HW_USBNC_USB_OTG_PHY_CTRL_0_RD() & ~(v)))
#define HW_USBNC_USB_OTG_PHY_CTRL_0_TOG(v)    (HW_USBNC_USB_OTG_PHY_CTRL_0_WR(HW_USBNC_USB_OTG_PHY_CTRL_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_OTG_PHY_CTRL_0 bitfields
 */

/* --- Register HW_USBNC_USB_OTG_PHY_CTRL_0, field UTMI_CLK_VLD[31:31] (RC1)
 *
 * Indicating whether OTG UTMI PHY clock is valid
 *
 * Values:
 * 0 - Invalid
 * 1 - Valid
 */

#define BP_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD      (31)
#define BM_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_UH1_PHY_CTRL_0 - Host1 UTMI PHY Control 0 Register (RW)
 *
 * USB Host1 UTMI PHY Control Register 0 are used to control the on-chip Host1 UTMI PHY.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned RESERVED1 : 28; //!< Reserved
        unsigned UTMI_CLK_VLD : 1; //!< Indicating whether Host 1 UTMI PHY clock is valid
    } B;
} hw_usbnc_usb_uh1_phy_ctrl_0_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH1_PHY_CTRL_0 register
 */
#define HW_USBNC_USB_UH1_PHY_CTRL_0_ADDR      (REGS_USBNC_BASE + 0x81c)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH1_PHY_CTRL_0           (*(volatile hw_usbnc_usb_uh1_phy_ctrl_0_t *) HW_USBNC_USB_UH1_PHY_CTRL_0_ADDR)
#define HW_USBNC_USB_UH1_PHY_CTRL_0_RD()      (HW_USBNC_USB_UH1_PHY_CTRL_0.U)
#define HW_USBNC_USB_UH1_PHY_CTRL_0_WR(v)     (HW_USBNC_USB_UH1_PHY_CTRL_0.U = (v))
#define HW_USBNC_USB_UH1_PHY_CTRL_0_SET(v)    (HW_USBNC_USB_UH1_PHY_CTRL_0_WR(HW_USBNC_USB_UH1_PHY_CTRL_0_RD() |  (v)))
#define HW_USBNC_USB_UH1_PHY_CTRL_0_CLR(v)    (HW_USBNC_USB_UH1_PHY_CTRL_0_WR(HW_USBNC_USB_UH1_PHY_CTRL_0_RD() & ~(v)))
#define HW_USBNC_USB_UH1_PHY_CTRL_0_TOG(v)    (HW_USBNC_USB_UH1_PHY_CTRL_0_WR(HW_USBNC_USB_UH1_PHY_CTRL_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_UH1_PHY_CTRL_0 bitfields
 */

/* --- Register HW_USBNC_USB_UH1_PHY_CTRL_0, field UTMI_CLK_VLD[31:31] (RC1)
 *
 * Indicating whether Host 1 UTMI PHY clock is valid
 *
 * Values:
 * 0 - Invalid
 * 1 - Valid
 */

#define BP_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD      (31)
#define BM_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD      (0x80000000)



/*!
 * @brief All USBNC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg32_t _reserved0[512];
    volatile hw_usbnc_usb_otg_ctrl_t USB_OTG_CTRL; //!< USB OTG Control Register
    volatile hw_usbnc_usb_uh1_ctrl_t USB_UH1_CTRL; //!< USB Host1 Control Register
    volatile hw_usbnc_usb_uh2_ctrl_t USB_UH2_CTRL; //!< USB Host2 Control Register
    volatile hw_usbnc_usb_uh3_ctrl_t USB_UH3_CTRL; //!< USB Host3 Control Register
    volatile hw_usbnc_usb_uh2_hsic_ctrl_t USB_UH2_HSIC_CTRL; //!< USB Host2 HSIC Control Register
    volatile hw_usbnc_usb_uh3_hsic_ctrl_t USB_UH3_HSIC_CTRL; //!< USB Host3 HSIC Control Register
    volatile hw_usbnc_usb_otg_phy_ctrl_0_t USB_OTG_PHY_CTRL_0; //!< OTG UTMI PHY Control 0 Register
    volatile hw_usbnc_usb_uh1_phy_ctrl_0_t USB_UH1_PHY_CTRL_0; //!< Host1 UTMI PHY Control 0 Register
} hw_usbnc_t;
#endif

//! @brief Macro to access all USBNC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USBNC(0)</code>.
#define HW_USBNC     (*(volatile hw_usbnc_t *) REGS_USBNC_BASE)


#endif // _USBNC_H
