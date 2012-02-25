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
 * - HW_USBNC_USB_OTG1_CTRL - USB OTG1 Control Register
 * - HW_USBNC_USB_OTG2_CTRL - USB OTG2 Control Register
 * - HW_USBNC_USB_UH_CTRL - USB Host Control Register
 * - HW_USBNC_USB_UH_HSIC_CTRL - USB Host HSIC Control Register
 * - HW_USBNC_USB_OTG1_PHY_CTRL_0 - OTG1 UTMI PHY Control 0 Register
 * - HW_USBNC_USB_OTG2_PHY_CTRL_0 - OTG2 UTMI PHY Control 0 Register
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
 * @brief HW_USBNC_USB_OTG1_CTRL - USB OTG1 Control Register (RW)
 *
 * The USB OTG1 control register controls the integration specific features of the USB OTG1 module.
 * These features are not directly related to the USB functionality, but control special features,
 * interfacing on the USB ports, as well as power control and wake-up functionality.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned OVER_CUR_DIS : 1; //!< Disable OTG1 Overcurrent Detection
        unsigned OVER_CUR_POL : 1; //!< OTG1 Polarity of Overcurrent The polarity of OTG1 port overcurrent event
        unsigned PWR_POL : 1; //!< OTG1 Power Polarity This bit should be set according to PMIC Power Pin polarity.
        unsigned WIE : 1; //!< OTG1 Wake-up Interrupt Enable This bit enables or disables the OTG1 wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force OTG1 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force OTG1 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode. For Freescale test only.
        unsigned UTMI_ON_CLOCK : 1; //!< Force OTG1 UTMI PHY clock output on even if suspend mode.
        unsigned WKUP_SW_EN : 1; //!< OTG1 Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< OTG1 Software Wake-up
        unsigned WKUP_ID_EN : 1; //!< OTG1 Wake-up on ID change enable
        unsigned WKUP_VBUS_EN : 1; //!< OTG1 wake-up on VBUS change enable
        unsigned RESERVED1 : 13; //!< Reserved
        unsigned WIR : 1; //!< OTG1 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on the OTG1 port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
    } B;
} hw_usbnc_usb_otg1_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_OTG1_CTRL register
 */
#define HW_USBNC_USB_OTG1_CTRL_ADDR      (REGS_USBNC_BASE + 0x800)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_OTG1_CTRL           (*(volatile hw_usbnc_usb_otg1_ctrl_t *) HW_USBNC_USB_OTG1_CTRL_ADDR)
#define HW_USBNC_USB_OTG1_CTRL_RD()      (HW_USBNC_USB_OTG1_CTRL.U)
#define HW_USBNC_USB_OTG1_CTRL_WR(v)     (HW_USBNC_USB_OTG1_CTRL.U = (v))
#define HW_USBNC_USB_OTG1_CTRL_SET(v)    (HW_USBNC_USB_OTG1_CTRL_WR(HW_USBNC_USB_OTG1_CTRL_RD() |  (v)))
#define HW_USBNC_USB_OTG1_CTRL_CLR(v)    (HW_USBNC_USB_OTG1_CTRL_WR(HW_USBNC_USB_OTG1_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_OTG1_CTRL_TOG(v)    (HW_USBNC_USB_OTG1_CTRL_WR(HW_USBNC_USB_OTG1_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_OTG1_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_OTG1_CTRL, field OVER_CUR_DIS[7:7] (RW)
 *
 * Disable OTG1 Overcurrent Detection
 *
 * Values:
 * 0 - Enables overcurrent detection
 * 1 - Disables overcurrent detection
 */

#define BP_USBNC_USB_OTG1_CTRL_OVER_CUR_DIS      (7)
#define BM_USBNC_USB_OTG1_CTRL_OVER_CUR_DIS      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_OVER_CUR_DIS(v)   ((((reg32_t) v) << 7) & BM_USBNC_USB_OTG1_CTRL_OVER_CUR_DIS)
#else
#define BF_USBNC_USB_OTG1_CTRL_OVER_CUR_DIS(v)   (((v) << 7) & BM_USBNC_USB_OTG1_CTRL_OVER_CUR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVER_CUR_DIS field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_OVER_CUR_DIS(v)   BF_CS1(USBNC_USB_OTG1_CTRL, OVER_CUR_DIS, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field OVER_CUR_POL[8:8] (RW)
 *
 * OTG1 Polarity of Overcurrent The polarity of OTG1 port overcurrent event
 *
 * Values:
 * 0 - High active
 * 1 - Low active
 */

#define BP_USBNC_USB_OTG1_CTRL_OVER_CUR_POL      (8)
#define BM_USBNC_USB_OTG1_CTRL_OVER_CUR_POL      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_OVER_CUR_POL(v)   ((((reg32_t) v) << 8) & BM_USBNC_USB_OTG1_CTRL_OVER_CUR_POL)
#else
#define BF_USBNC_USB_OTG1_CTRL_OVER_CUR_POL(v)   (((v) << 8) & BM_USBNC_USB_OTG1_CTRL_OVER_CUR_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVER_CUR_POL field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_OVER_CUR_POL(v)   BF_CS1(USBNC_USB_OTG1_CTRL, OVER_CUR_POL, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field PWR_POL[9:9] (RW)
 *
 * OTG1 Power Polarity This bit should be set according to PMIC Power Pin polarity.
 *
 * Values:
 * 0 - PMIC Power Pin is Low active.
 * 1 - PMIC Power Pin is High active.
 */

#define BP_USBNC_USB_OTG1_CTRL_PWR_POL      (9)
#define BM_USBNC_USB_OTG1_CTRL_PWR_POL      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_PWR_POL(v)   ((((reg32_t) v) << 9) & BM_USBNC_USB_OTG1_CTRL_PWR_POL)
#else
#define BF_USBNC_USB_OTG1_CTRL_PWR_POL(v)   (((v) << 9) & BM_USBNC_USB_OTG1_CTRL_PWR_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PWR_POL field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_PWR_POL(v)   BF_CS1(USBNC_USB_OTG1_CTRL, PWR_POL, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field WIE[10:10] (RW)
 *
 * OTG1 Wake-up Interrupt Enable This bit enables or disables the OTG1 wake-up interrupt. Disabling
 * the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned
 * off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
 *
 * Values:
 * 0 - Interrupt Disabled
 * 1 - Interrupt Enabled
 */

#define BP_USBNC_USB_OTG1_CTRL_WIE      (10)
#define BM_USBNC_USB_OTG1_CTRL_WIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_OTG1_CTRL_WIE)
#else
#define BF_USBNC_USB_OTG1_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_OTG1_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_WIE(v)   BF_CS1(USBNC_USB_OTG1_CTRL, WIE, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field RESET[11:11] (RW)
 *
 * Force OTG1 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
 *
 * Values:
 * 0 - Inactive
 * 1 - Reset the PHY
 */

#define BP_USBNC_USB_OTG1_CTRL_RESET      (11)
#define BM_USBNC_USB_OTG1_CTRL_RESET      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_OTG1_CTRL_RESET)
#else
#define BF_USBNC_USB_OTG1_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_OTG1_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_RESET(v)   BF_CS1(USBNC_USB_OTG1_CTRL, RESET, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field SUSPENDM[12:12] (RW)
 *
 * Force OTG1 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend
 * mode. For Freescale test only.
 *
 * Values:
 * 0 - Force OTG1 UTMI PHY Suspend
 * 1 - Inactive
 */

#define BP_USBNC_USB_OTG1_CTRL_SUSPENDM      (12)
#define BM_USBNC_USB_OTG1_CTRL_SUSPENDM      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_OTG1_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_OTG1_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_OTG1_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSPENDM field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_OTG1_CTRL, SUSPENDM, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field UTMI_ON_CLOCK[13:13] (RW)
 *
 * Force OTG1 UTMI PHY clock output on even if suspend mode.
 *
 * Values:
 * 0 - Inactive
 * 1 - Force clock output on
 */

#define BP_USBNC_USB_OTG1_CTRL_UTMI_ON_CLOCK      (13)
#define BM_USBNC_USB_OTG1_CTRL_UTMI_ON_CLOCK      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_UTMI_ON_CLOCK(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_OTG1_CTRL_UTMI_ON_CLOCK)
#else
#define BF_USBNC_USB_OTG1_CTRL_UTMI_ON_CLOCK(v)   (((v) << 13) & BM_USBNC_USB_OTG1_CTRL_UTMI_ON_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_ON_CLOCK field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_UTMI_ON_CLOCK(v)   BF_CS1(USBNC_USB_OTG1_CTRL, UTMI_ON_CLOCK, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field WKUP_SW_EN[14:14] (RW)
 *
 * OTG1 Software Wake-up Enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG1_CTRL_WKUP_SW_EN      (14)
#define BM_USBNC_USB_OTG1_CTRL_WKUP_SW_EN      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_OTG1_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_OTG1_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_OTG1_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW_EN field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_OTG1_CTRL, WKUP_SW_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field WKUP_SW[15:15] (RW)
 *
 * OTG1 Software Wake-up
 *
 * Values:
 * 0 - Inactive
 * 1 - Force wake-up
 */

#define BP_USBNC_USB_OTG1_CTRL_WKUP_SW      (15)
#define BM_USBNC_USB_OTG1_CTRL_WKUP_SW      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_OTG1_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_OTG1_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_OTG1_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_OTG1_CTRL, WKUP_SW, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field WKUP_ID_EN[16:16] (RW)
 *
 * OTG1 Wake-up on ID change enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG1_CTRL_WKUP_ID_EN      (16)
#define BM_USBNC_USB_OTG1_CTRL_WKUP_ID_EN      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_WKUP_ID_EN(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_OTG1_CTRL_WKUP_ID_EN)
#else
#define BF_USBNC_USB_OTG1_CTRL_WKUP_ID_EN(v)   (((v) << 16) & BM_USBNC_USB_OTG1_CTRL_WKUP_ID_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_ID_EN field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_WKUP_ID_EN(v)   BF_CS1(USBNC_USB_OTG1_CTRL, WKUP_ID_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field WKUP_VBUS_EN[17:17] (RW)
 *
 * OTG1 wake-up on VBUS change enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN      (17)
#define BM_USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN(v)   ((((reg32_t) v) << 17) & BM_USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN)
#else
#define BF_USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN(v)   (((v) << 17) & BM_USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_VBUS_EN field to a new value.
#define BW_USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN(v)   BF_CS1(USBNC_USB_OTG1_CTRL, WKUP_VBUS_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG1_CTRL, field WIR[31:31] (RO)
 *
 * OTG1 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on
 * the OTG1 port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
 *
 * Values:
 * 0 - No wake-up interrupt request received
 * 1 - Wake-up Interrupt Request received
 */

#define BP_USBNC_USB_OTG1_CTRL_WIR      (31)
#define BM_USBNC_USB_OTG1_CTRL_WIR      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_OTG2_CTRL - USB OTG2 Control Register (RW)
 *
 * The USB OTG2 control register controls the integration specific features of the USB OTG2 module.
 * These features are not directly related to the USB functionality, but control special features,
 * interfacing on the USB ports, as well as power control and wake-up functionality.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned OVER_CUR_DIS : 1; //!< Disable OTG2 Overcurrent Detection
        unsigned OVER_CUR_POL : 1; //!< OTG2 Polarity of Overcurrent The polarity of OTG2 port overcurrent event
        unsigned PWR_POL : 1; //!< OTG2 Power Polarity This bit should be set according to PMIC Power Pin polarity.
        unsigned WIE : 1; //!< OTG2 Wake-up Interrupt Enable This bit enables or disables the OTG2 wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force OTG2 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force OTG2 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode. For Freescale test only.
        unsigned UTMI_ON_CLOCK : 1; //!< Force OTG2 UTMI PHY clock output on even if suspend mode.
        unsigned WKUP_SW_EN : 1; //!< OTG2 Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< OTG2 Software Wake-up
        unsigned WKUP_ID_EN : 1; //!< OTG2 Wake-up on ID change enable
        unsigned WKUP_VBUS_EN : 1; //!< OTG2 wake-up on VBUS change enable
        unsigned RESERVED1 : 13; //!< Reserved
        unsigned WIR : 1; //!< OTG2 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
    } B;
} hw_usbnc_usb_otg2_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_OTG2_CTRL register
 */
#define HW_USBNC_USB_OTG2_CTRL_ADDR      (REGS_USBNC_BASE + 0x804)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_OTG2_CTRL           (*(volatile hw_usbnc_usb_otg2_ctrl_t *) HW_USBNC_USB_OTG2_CTRL_ADDR)
#define HW_USBNC_USB_OTG2_CTRL_RD()      (HW_USBNC_USB_OTG2_CTRL.U)
#define HW_USBNC_USB_OTG2_CTRL_WR(v)     (HW_USBNC_USB_OTG2_CTRL.U = (v))
#define HW_USBNC_USB_OTG2_CTRL_SET(v)    (HW_USBNC_USB_OTG2_CTRL_WR(HW_USBNC_USB_OTG2_CTRL_RD() |  (v)))
#define HW_USBNC_USB_OTG2_CTRL_CLR(v)    (HW_USBNC_USB_OTG2_CTRL_WR(HW_USBNC_USB_OTG2_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_OTG2_CTRL_TOG(v)    (HW_USBNC_USB_OTG2_CTRL_WR(HW_USBNC_USB_OTG2_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_OTG2_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_OTG2_CTRL, field OVER_CUR_DIS[7:7] (RW)
 *
 * Disable OTG2 Overcurrent Detection
 *
 * Values:
 * 0 - Enables overcurrent detection
 * 1 - Disables overcurrent detection
 */

#define BP_USBNC_USB_OTG2_CTRL_OVER_CUR_DIS      (7)
#define BM_USBNC_USB_OTG2_CTRL_OVER_CUR_DIS      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_OVER_CUR_DIS(v)   ((((reg32_t) v) << 7) & BM_USBNC_USB_OTG2_CTRL_OVER_CUR_DIS)
#else
#define BF_USBNC_USB_OTG2_CTRL_OVER_CUR_DIS(v)   (((v) << 7) & BM_USBNC_USB_OTG2_CTRL_OVER_CUR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVER_CUR_DIS field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_OVER_CUR_DIS(v)   BF_CS1(USBNC_USB_OTG2_CTRL, OVER_CUR_DIS, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field OVER_CUR_POL[8:8] (RW)
 *
 * OTG2 Polarity of Overcurrent The polarity of OTG2 port overcurrent event
 *
 * Values:
 * 0 - High active
 * 1 - Low active
 */

#define BP_USBNC_USB_OTG2_CTRL_OVER_CUR_POL      (8)
#define BM_USBNC_USB_OTG2_CTRL_OVER_CUR_POL      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_OVER_CUR_POL(v)   ((((reg32_t) v) << 8) & BM_USBNC_USB_OTG2_CTRL_OVER_CUR_POL)
#else
#define BF_USBNC_USB_OTG2_CTRL_OVER_CUR_POL(v)   (((v) << 8) & BM_USBNC_USB_OTG2_CTRL_OVER_CUR_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVER_CUR_POL field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_OVER_CUR_POL(v)   BF_CS1(USBNC_USB_OTG2_CTRL, OVER_CUR_POL, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field PWR_POL[9:9] (RW)
 *
 * OTG2 Power Polarity This bit should be set according to PMIC Power Pin polarity.
 *
 * Values:
 * 0 - PMIC Power Pin is Low active.
 * 1 - PMIC Power Pin is High active.
 */

#define BP_USBNC_USB_OTG2_CTRL_PWR_POL      (9)
#define BM_USBNC_USB_OTG2_CTRL_PWR_POL      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_PWR_POL(v)   ((((reg32_t) v) << 9) & BM_USBNC_USB_OTG2_CTRL_PWR_POL)
#else
#define BF_USBNC_USB_OTG2_CTRL_PWR_POL(v)   (((v) << 9) & BM_USBNC_USB_OTG2_CTRL_PWR_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PWR_POL field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_PWR_POL(v)   BF_CS1(USBNC_USB_OTG2_CTRL, PWR_POL, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field WIE[10:10] (RW)
 *
 * OTG2 Wake-up Interrupt Enable This bit enables or disables the OTG2 wake-up interrupt. Disabling
 * the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned
 * off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
 *
 * Values:
 * 0 - Interrupt Disabled
 * 1 - Interrupt Enabled
 */

#define BP_USBNC_USB_OTG2_CTRL_WIE      (10)
#define BM_USBNC_USB_OTG2_CTRL_WIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_OTG2_CTRL_WIE)
#else
#define BF_USBNC_USB_OTG2_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_OTG2_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_WIE(v)   BF_CS1(USBNC_USB_OTG2_CTRL, WIE, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field RESET[11:11] (RW)
 *
 * Force OTG2 UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
 *
 * Values:
 * 0 - Inactive
 * 1 - Reset the PHY
 */

#define BP_USBNC_USB_OTG2_CTRL_RESET      (11)
#define BM_USBNC_USB_OTG2_CTRL_RESET      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_OTG2_CTRL_RESET)
#else
#define BF_USBNC_USB_OTG2_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_OTG2_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_RESET(v)   BF_CS1(USBNC_USB_OTG2_CTRL, RESET, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field SUSPENDM[12:12] (RW)
 *
 * Force OTG2 UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend
 * mode. For Freescale test only.
 *
 * Values:
 * 0 - Enable
 * 1 - Disable
 */

#define BP_USBNC_USB_OTG2_CTRL_SUSPENDM      (12)
#define BM_USBNC_USB_OTG2_CTRL_SUSPENDM      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_OTG2_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_OTG2_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_OTG2_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSPENDM field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_OTG2_CTRL, SUSPENDM, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field UTMI_ON_CLOCK[13:13] (RW)
 *
 * Force OTG2 UTMI PHY clock output on even if suspend mode.
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG2_CTRL_UTMI_ON_CLOCK      (13)
#define BM_USBNC_USB_OTG2_CTRL_UTMI_ON_CLOCK      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_UTMI_ON_CLOCK(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_OTG2_CTRL_UTMI_ON_CLOCK)
#else
#define BF_USBNC_USB_OTG2_CTRL_UTMI_ON_CLOCK(v)   (((v) << 13) & BM_USBNC_USB_OTG2_CTRL_UTMI_ON_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UTMI_ON_CLOCK field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_UTMI_ON_CLOCK(v)   BF_CS1(USBNC_USB_OTG2_CTRL, UTMI_ON_CLOCK, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field WKUP_SW_EN[14:14] (RW)
 *
 * OTG2 Software Wake-up Enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG2_CTRL_WKUP_SW_EN      (14)
#define BM_USBNC_USB_OTG2_CTRL_WKUP_SW_EN      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_OTG2_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_OTG2_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_OTG2_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW_EN field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_OTG2_CTRL, WKUP_SW_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field WKUP_SW[15:15] (RW)
 *
 * OTG2 Software Wake-up
 *
 * Values:
 * 0 - Inactive
 * 1 - Force wake-up
 */

#define BP_USBNC_USB_OTG2_CTRL_WKUP_SW      (15)
#define BM_USBNC_USB_OTG2_CTRL_WKUP_SW      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_OTG2_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_OTG2_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_OTG2_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_OTG2_CTRL, WKUP_SW, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field WKUP_ID_EN[16:16] (RW)
 *
 * OTG2 Wake-up on ID change enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG2_CTRL_WKUP_ID_EN      (16)
#define BM_USBNC_USB_OTG2_CTRL_WKUP_ID_EN      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_WKUP_ID_EN(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_OTG2_CTRL_WKUP_ID_EN)
#else
#define BF_USBNC_USB_OTG2_CTRL_WKUP_ID_EN(v)   (((v) << 16) & BM_USBNC_USB_OTG2_CTRL_WKUP_ID_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_ID_EN field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_WKUP_ID_EN(v)   BF_CS1(USBNC_USB_OTG2_CTRL, WKUP_ID_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field WKUP_VBUS_EN[17:17] (RW)
 *
 * OTG2 wake-up on VBUS change enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN      (17)
#define BM_USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN(v)   ((((reg32_t) v) << 17) & BM_USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN)
#else
#define BF_USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN(v)   (((v) << 17) & BM_USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_VBUS_EN field to a new value.
#define BW_USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN(v)   BF_CS1(USBNC_USB_OTG2_CTRL, WKUP_VBUS_EN, v)
#endif


/* --- Register HW_USBNC_USB_OTG2_CTRL, field WIR[31:31] (RO)
 *
 * OTG2 Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on
 * the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
 *
 * Values:
 * 0 - No wake-up interrupt request received
 * 1 - Wake-up Interrupt Request received
 */

#define BP_USBNC_USB_OTG2_CTRL_WIR      (31)
#define BM_USBNC_USB_OTG2_CTRL_WIR      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_UH_CTRL - USB Host Control Register (RW)
 *
 * The USB Host control register controls the integration specific features of the USB host2 module.
 * These features are not directly related to the USB functionality, but control special features,
 * interfacing on the USB ports, as well as power control and wake-up functionality.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned WIE : 1; //!< Host Wake-up Interrupt Enable This bit enables or disables the Host wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force Host UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force Host UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode. For Freescale test only.
        unsigned _480M_CLK_ON : 1; //!< Force OTG UTMI PHY 480M clock output on when Host is not in suspend mode.
        unsigned WKUP_SW_EN : 1; //!< Host Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< Host Software Wake-up
        unsigned RESERVED1 : 15; //!< Reserved
        unsigned WIR : 1; //!< Host Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on the Host port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
    } B;
} hw_usbnc_usb_uh_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH_CTRL register
 */
#define HW_USBNC_USB_UH_CTRL_ADDR      (REGS_USBNC_BASE + 0x808)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH_CTRL           (*(volatile hw_usbnc_usb_uh_ctrl_t *) HW_USBNC_USB_UH_CTRL_ADDR)
#define HW_USBNC_USB_UH_CTRL_RD()      (HW_USBNC_USB_UH_CTRL.U)
#define HW_USBNC_USB_UH_CTRL_WR(v)     (HW_USBNC_USB_UH_CTRL.U = (v))
#define HW_USBNC_USB_UH_CTRL_SET(v)    (HW_USBNC_USB_UH_CTRL_WR(HW_USBNC_USB_UH_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH_CTRL_CLR(v)    (HW_USBNC_USB_UH_CTRL_WR(HW_USBNC_USB_UH_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH_CTRL_TOG(v)    (HW_USBNC_USB_UH_CTRL_WR(HW_USBNC_USB_UH_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_UH_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH_CTRL, field WIE[10:10] (RW)
 *
 * Host Wake-up Interrupt Enable This bit enables or disables the Host wake-up interrupt. Disabling
 * the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned
 * off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
 *
 * Values:
 * 0 - Interrupt Disabled
 * 1 - Interrupt Enabled
 */

#define BP_USBNC_USB_UH_CTRL_WIE      (10)
#define BM_USBNC_USB_UH_CTRL_WIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH_CTRL_WIE)
#else
#define BF_USBNC_USB_UH_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_USBNC_USB_UH_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH_CTRL, WIE, v)
#endif


/* --- Register HW_USBNC_USB_UH_CTRL, field RESET[11:11] (RW)
 *
 * Force Host UTMI PHY Reset This bit is used to force a reset to the UTMI PHY. During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY For Freescale test only.
 *
 * Values:
 * 0 - Inactive
 * 1 - Reset the PHY
 */

#define BP_USBNC_USB_UH_CTRL_RESET      (11)
#define BM_USBNC_USB_UH_CTRL_RESET      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH_CTRL_RESET)
#else
#define BF_USBNC_USB_UH_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_USBNC_USB_UH_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH_CTRL, RESET, v)
#endif


/* --- Register HW_USBNC_USB_UH_CTRL, field SUSPENDM[12:12] (RW)
 *
 * Force Host UTMI PHY Suspend This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend
 * mode. For Freescale test only.
 *
 * Values:
 * 0 - Enable
 * 1 - Disable
 */

#define BP_USBNC_USB_UH_CTRL_SUSPENDM      (12)
#define BM_USBNC_USB_UH_CTRL_SUSPENDM      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSPENDM field to a new value.
#define BW_USBNC_USB_UH_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH_CTRL, SUSPENDM, v)
#endif


/* --- Register HW_USBNC_USB_UH_CTRL, field _480M_CLK_ON[13:13] (RW)
 *
 * Force OTG UTMI PHY 480M clock output on when Host is not in suspend mode.
 *
 * Values:
 * 0 - Inactive
 * 1 - Force OTG UTMI PHY 480M clock output on
 */

#define BP_USBNC_USB_UH_CTRL__480M_CLK_ON      (13)
#define BM_USBNC_USB_UH_CTRL__480M_CLK_ON      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH_CTRL__480M_CLK_ON(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_UH_CTRL__480M_CLK_ON)
#else
#define BF_USBNC_USB_UH_CTRL__480M_CLK_ON(v)   (((v) << 13) & BM_USBNC_USB_UH_CTRL__480M_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the _480M_CLK_ON field to a new value.
#define BW_USBNC_USB_UH_CTRL__480M_CLK_ON(v)   BF_CS1(USBNC_USB_UH_CTRL, _480M_CLK_ON, v)
#endif


/* --- Register HW_USBNC_USB_UH_CTRL, field WKUP_SW_EN[14:14] (RW)
 *
 * Host Software Wake-up Enable
 *
 * Values:
 * 0 - Disable
 * 1 - Enable
 */

#define BP_USBNC_USB_UH_CTRL_WKUP_SW_EN      (14)
#define BM_USBNC_USB_UH_CTRL_WKUP_SW_EN      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW_EN field to a new value.
#define BW_USBNC_USB_UH_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH_CTRL, WKUP_SW_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH_CTRL, field WKUP_SW[15:15] (RW)
 *
 * Host Software Wake-up
 *
 * Values:
 * 0 - Inactive
 * 1 - Force wake-up
 */

#define BP_USBNC_USB_UH_CTRL_WKUP_SW      (15)
#define BM_USBNC_USB_UH_CTRL_WKUP_SW      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKUP_SW field to a new value.
#define BW_USBNC_USB_UH_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH_CTRL, WKUP_SW, v)
#endif


/* --- Register HW_USBNC_USB_UH_CTRL, field WIR[31:31] (RO)
 *
 * Host Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on
 * the Host port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
 *
 * Values:
 * 0 - No wake-up interrupt request received
 * 1 - Wake-up Interrupt Request received
 */

#define BP_USBNC_USB_UH_CTRL_WIR      (31)
#define BM_USBNC_USB_UH_CTRL_WIR      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_UH_HSIC_CTRL - USB Host HSIC Control Register (RW)
 *
 * The USB Host HSIC control register controls Host high speed IC configuration. These features are
 * not directly related to the USB functionality, but control special features, interfacing on the
 * USB ports, as well as power control.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned HSIC_CLK_ON : 1; //!< Force Host HSIC module 480M clock on, even when in Host is in suspend mode.
        unsigned HSIC_EN : 1; //!< Host HSIC enable
        unsigned RESERVED1 : 18; //!< Reserved
        unsigned CLK_VLD : 1; //!< Indicating whether Host HSIC clock is valid.
    } B;
} hw_usbnc_usb_uh_hsic_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH_HSIC_CTRL register
 */
#define HW_USBNC_USB_UH_HSIC_CTRL_ADDR      (REGS_USBNC_BASE + 0x810)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH_HSIC_CTRL           (*(volatile hw_usbnc_usb_uh_hsic_ctrl_t *) HW_USBNC_USB_UH_HSIC_CTRL_ADDR)
#define HW_USBNC_USB_UH_HSIC_CTRL_RD()      (HW_USBNC_USB_UH_HSIC_CTRL.U)
#define HW_USBNC_USB_UH_HSIC_CTRL_WR(v)     (HW_USBNC_USB_UH_HSIC_CTRL.U = (v))
#define HW_USBNC_USB_UH_HSIC_CTRL_SET(v)    (HW_USBNC_USB_UH_HSIC_CTRL_WR(HW_USBNC_USB_UH_HSIC_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH_HSIC_CTRL_CLR(v)    (HW_USBNC_USB_UH_HSIC_CTRL_WR(HW_USBNC_USB_UH_HSIC_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH_HSIC_CTRL_TOG(v)    (HW_USBNC_USB_UH_HSIC_CTRL_WR(HW_USBNC_USB_UH_HSIC_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_UH_HSIC_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH_HSIC_CTRL, field HSIC_CLK_ON[11:11] (RW)
 *
 * Force Host HSIC module 480M clock on, even when in Host is in suspend mode.
 *
 * Values:
 * 0 - Inactive
 * 1 - Active
 */

#define BP_USBNC_USB_UH_HSIC_CTRL_HSIC_CLK_ON      (11)
#define BM_USBNC_USB_UH_HSIC_CTRL_HSIC_CLK_ON      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH_HSIC_CTRL_HSIC_CLK_ON(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH_HSIC_CTRL_HSIC_CLK_ON)
#else
#define BF_USBNC_USB_UH_HSIC_CTRL_HSIC_CLK_ON(v)   (((v) << 11) & BM_USBNC_USB_UH_HSIC_CTRL_HSIC_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSIC_CLK_ON field to a new value.
#define BW_USBNC_USB_UH_HSIC_CTRL_HSIC_CLK_ON(v)   BF_CS1(USBNC_USB_UH_HSIC_CTRL, HSIC_CLK_ON, v)
#endif


/* --- Register HW_USBNC_USB_UH_HSIC_CTRL, field HSIC_EN[12:12] (RW)
 *
 * Host HSIC enable
 *
 * Values:
 * 0 - Disabled
 * 1 - Enabled
 */

#define BP_USBNC_USB_UH_HSIC_CTRL_HSIC_EN      (12)
#define BM_USBNC_USB_UH_HSIC_CTRL_HSIC_EN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH_HSIC_CTRL_HSIC_EN(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH_HSIC_CTRL_HSIC_EN)
#else
#define BF_USBNC_USB_UH_HSIC_CTRL_HSIC_EN(v)   (((v) << 12) & BM_USBNC_USB_UH_HSIC_CTRL_HSIC_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSIC_EN field to a new value.
#define BW_USBNC_USB_UH_HSIC_CTRL_HSIC_EN(v)   BF_CS1(USBNC_USB_UH_HSIC_CTRL, HSIC_EN, v)
#endif


/* --- Register HW_USBNC_USB_UH_HSIC_CTRL, field CLK_VLD[31:31] (RO)
 *
 * Indicating whether Host HSIC clock is valid.
 *
 * Values:
 * 1 - Valid
 * 2 - Invalid
 */

#define BP_USBNC_USB_UH_HSIC_CTRL_CLK_VLD      (31)
#define BM_USBNC_USB_UH_HSIC_CTRL_CLK_VLD      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_OTG1_PHY_CTRL_0 - OTG1 UTMI PHY Control 0 Register (RW)
 *
 * USB OTG1 UTMI PHY control register 0 is used to control the on-chip OTG1 UTMI PHY.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned RESERVED1 : 28; //!< Reserved
        unsigned UTMI_CLK_VLD : 1; //!< Indicating whether OTG1 UTMI PHY clock is valid
    } B;
} hw_usbnc_usb_otg1_phy_ctrl_0_t;
#endif

/*
 * constants & macros for entire USBNC_USB_OTG1_PHY_CTRL_0 register
 */
#define HW_USBNC_USB_OTG1_PHY_CTRL_0_ADDR      (REGS_USBNC_BASE + 0x818)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_OTG1_PHY_CTRL_0           (*(volatile hw_usbnc_usb_otg1_phy_ctrl_0_t *) HW_USBNC_USB_OTG1_PHY_CTRL_0_ADDR)
#define HW_USBNC_USB_OTG1_PHY_CTRL_0_RD()      (HW_USBNC_USB_OTG1_PHY_CTRL_0.U)
#define HW_USBNC_USB_OTG1_PHY_CTRL_0_WR(v)     (HW_USBNC_USB_OTG1_PHY_CTRL_0.U = (v))
#define HW_USBNC_USB_OTG1_PHY_CTRL_0_SET(v)    (HW_USBNC_USB_OTG1_PHY_CTRL_0_WR(HW_USBNC_USB_OTG1_PHY_CTRL_0_RD() |  (v)))
#define HW_USBNC_USB_OTG1_PHY_CTRL_0_CLR(v)    (HW_USBNC_USB_OTG1_PHY_CTRL_0_WR(HW_USBNC_USB_OTG1_PHY_CTRL_0_RD() & ~(v)))
#define HW_USBNC_USB_OTG1_PHY_CTRL_0_TOG(v)    (HW_USBNC_USB_OTG1_PHY_CTRL_0_WR(HW_USBNC_USB_OTG1_PHY_CTRL_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_OTG1_PHY_CTRL_0 bitfields
 */

/* --- Register HW_USBNC_USB_OTG1_PHY_CTRL_0, field UTMI_CLK_VLD[31:31] (RC1)
 *
 * Indicating whether OTG1 UTMI PHY clock is valid
 *
 * Values:
 * 0 - Invalid
 * 1 - Valid
 */

#define BP_USBNC_USB_OTG1_PHY_CTRL_0_UTMI_CLK_VLD      (31)
#define BM_USBNC_USB_OTG1_PHY_CTRL_0_UTMI_CLK_VLD      (0x80000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBNC_USB_OTG2_PHY_CTRL_0 - OTG2 UTMI PHY Control 0 Register (RW)
 *
 * USB OTG2 UTMI PHY Control Register 0 are used to control the on-chip OTG2 UTMI PHY.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned RESERVED1 : 28; //!< Reserved
        unsigned UTMI_CLK_VLD : 1; //!< Indicating whether OTG2 UTMI PHY clock is valid
    } B;
} hw_usbnc_usb_otg2_phy_ctrl_0_t;
#endif

/*
 * constants & macros for entire USBNC_USB_OTG2_PHY_CTRL_0 register
 */
#define HW_USBNC_USB_OTG2_PHY_CTRL_0_ADDR      (REGS_USBNC_BASE + 0x81c)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_OTG2_PHY_CTRL_0           (*(volatile hw_usbnc_usb_otg2_phy_ctrl_0_t *) HW_USBNC_USB_OTG2_PHY_CTRL_0_ADDR)
#define HW_USBNC_USB_OTG2_PHY_CTRL_0_RD()      (HW_USBNC_USB_OTG2_PHY_CTRL_0.U)
#define HW_USBNC_USB_OTG2_PHY_CTRL_0_WR(v)     (HW_USBNC_USB_OTG2_PHY_CTRL_0.U = (v))
#define HW_USBNC_USB_OTG2_PHY_CTRL_0_SET(v)    (HW_USBNC_USB_OTG2_PHY_CTRL_0_WR(HW_USBNC_USB_OTG2_PHY_CTRL_0_RD() |  (v)))
#define HW_USBNC_USB_OTG2_PHY_CTRL_0_CLR(v)    (HW_USBNC_USB_OTG2_PHY_CTRL_0_WR(HW_USBNC_USB_OTG2_PHY_CTRL_0_RD() & ~(v)))
#define HW_USBNC_USB_OTG2_PHY_CTRL_0_TOG(v)    (HW_USBNC_USB_OTG2_PHY_CTRL_0_WR(HW_USBNC_USB_OTG2_PHY_CTRL_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBNC_USB_OTG2_PHY_CTRL_0 bitfields
 */

/* --- Register HW_USBNC_USB_OTG2_PHY_CTRL_0, field UTMI_CLK_VLD[31:31] (RC1)
 *
 * Indicating whether OTG2 UTMI PHY clock is valid
 *
 * Values:
 * 0 - Invalid
 * 1 - Valid
 */

#define BP_USBNC_USB_OTG2_PHY_CTRL_0_UTMI_CLK_VLD      (31)
#define BM_USBNC_USB_OTG2_PHY_CTRL_0_UTMI_CLK_VLD      (0x80000000)



/*!
 * @brief All USBNC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg32_t _reserved0[512];
    volatile hw_usbnc_usb_otg1_ctrl_t USB_OTG1_CTRL; //!< USB OTG1 Control Register
    volatile hw_usbnc_usb_otg2_ctrl_t USB_OTG2_CTRL; //!< USB OTG2 Control Register
    volatile hw_usbnc_usb_uh_ctrl_t USB_UH_CTRL; //!< USB Host Control Register
    reg32_t _reserved1;
    volatile hw_usbnc_usb_uh_hsic_ctrl_t USB_UH_HSIC_CTRL; //!< USB Host HSIC Control Register
    reg32_t _reserved2;
    volatile hw_usbnc_usb_otg1_phy_ctrl_0_t USB_OTG1_PHY_CTRL_0; //!< OTG1 UTMI PHY Control 0 Register
    volatile hw_usbnc_usb_otg2_phy_ctrl_0_t USB_OTG2_PHY_CTRL_0; //!< OTG2 UTMI PHY Control 0 Register
} hw_usbnc_t;
#endif

//! @brief Macro to access all USBNC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USBNC(0)</code>.
#define HW_USBNC     (*(volatile hw_usbnc_t *) REGS_USBNC_BASE)


#endif // _USBNC_H
