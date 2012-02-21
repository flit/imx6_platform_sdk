/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USBNC_H
#define _USBNC_H

#include "regs.h"

#ifndef REGS_USBNC_BASE
#define REGS_USBNC_BASE (REGS_BASE + 0x02184000)
#endif


/*!
 * @brief HW_USBNC_USB_OTG_CTRL - USB OTG Control Register
 *
 * The USB OTG control register controls the integration specific features of the USB OTG
 * module. These features are not directly related to the USB functionality, but control
 * special features, interfacing on the USB ports, as well as power control and wake-up
 * functionality.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned OVER_CUR_DIS : 1; //!< Disable OTG Overcurrent Detection
        unsigned OVER_CUR_POL : 1; //!< OTG Polarity of Overcurrent  The polarity of OTG port overcurrent event
        unsigned PWR_POL : 1; //!< OTG Power Polarity  This bit should be set according to PMIC Power Pin polarity.
        unsigned WIE : 1; //!< OTG Wake-up Interrupt Enable  This bit enables or disables the OTG wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force OTG UTMI PHY Reset  This bit is used to force a reset to the UTMI PHY.  During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY  For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force OTG UTMI PHY Suspend  This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode.  For Freescale test only.
        unsigned UTMI_ON_CLOCK : 1; //!< Force OTG UTMI PHY clock output on even if suspend mode.
        unsigned WKUP_SW_EN : 1; //!< OTG Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< OTG Software Wake-up
        unsigned WKUP_ID_EN : 1; //!< OTG Wake-up on ID change enable
        unsigned WKUP_VBUS_EN : 1; //!< OTG wake-up on VBUS change enable
        unsigned RESERVED1 : 13; //!< Reserved
        unsigned WIR : 1; //!< OTG Wake-up Interrupt Request  This bit indicates that a wake-up interrupt request is received on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
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

/* --- Register HW_USBNC_USB_OTG_CTRL, field OVER_CUR_DIS
 *
 * Disable OTG Overcurrent Detection
 */

#define BP_USBNC_USB_OTG_CTRL_OVER_CUR_DIS      7
#define BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   ((((reg32_t) v) << 7) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS)
#else
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   (((v) << 7) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   BF_CS1(USBNC_USB_OTG_CTRL, OVER_CUR_DIS, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field OVER_CUR_POL
 *
 * OTG Polarity of Overcurrent  The polarity of OTG port overcurrent event
 */

#define BP_USBNC_USB_OTG_CTRL_OVER_CUR_POL      8
#define BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   ((((reg32_t) v) << 8) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL)
#else
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   (((v) << 8) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   BF_CS1(USBNC_USB_OTG_CTRL, OVER_CUR_POL, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field PWR_POL
 *
 * OTG Power Polarity  This bit should be set according to PMIC Power Pin polarity.
 */

#define BP_USBNC_USB_OTG_CTRL_PWR_POL      9
#define BM_USBNC_USB_OTG_CTRL_PWR_POL      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_PWR_POL(v)   ((((reg32_t) v) << 9) & BM_USBNC_USB_OTG_CTRL_PWR_POL)
#else
#define BF_USBNC_USB_OTG_CTRL_PWR_POL(v)   (((v) << 9) & BM_USBNC_USB_OTG_CTRL_PWR_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_PWR_POL(v)   BF_CS1(USBNC_USB_OTG_CTRL, PWR_POL, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WIE
 *
 * OTG Wake-up Interrupt Enable  This bit enables or disables the OTG wake-up interrupt. Disabling
 * the interrupt also                                 clears the Interrupt request bit. Wake-up
 * interrupt enable should be turned off after                                 receiving a wake-up
 * interrupt and turned on again prior to going in suspend mode
 */

#define BP_USBNC_USB_OTG_CTRL_WIE      10
#define BM_USBNC_USB_OTG_CTRL_WIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_OTG_CTRL_WIE)
#else
#define BF_USBNC_USB_OTG_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_OTG_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WIE(v)   BF_CS1(USBNC_USB_OTG_CTRL, WIE, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field RESET
 *
 * Force OTG UTMI PHY Reset  This bit is used to force a reset to the UTMI PHY.  During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY  For Freescale test only.
 */

#define BP_USBNC_USB_OTG_CTRL_RESET      11
#define BM_USBNC_USB_OTG_CTRL_RESET      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_OTG_CTRL_RESET)
#else
#define BF_USBNC_USB_OTG_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_OTG_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_RESET(v)   BF_CS1(USBNC_USB_OTG_CTRL, RESET, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field SUSPENDM
 *
 * Force OTG UTMI PHY Suspend  This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set                                 bits SUSP and PHCD in USB core register
 * PORTSC1 to put PHY into suspend mode.  For Freescale test only.
 */

#define BP_USBNC_USB_OTG_CTRL_SUSPENDM      12
#define BM_USBNC_USB_OTG_CTRL_SUSPENDM      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_OTG_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_OTG_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_OTG_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_OTG_CTRL, SUSPENDM, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field UTMI_ON_CLOCK
 *
 * Force OTG UTMI PHY clock output on even if suspend mode.
 */

#define BP_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK      13
#define BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK)
#else
#define BF_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   (((v) << 13) & BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   BF_CS1(USBNC_USB_OTG_CTRL, UTMI_ON_CLOCK, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_SW_EN
 *
 * OTG Software Wake-up Enable
 */

#define BP_USBNC_USB_OTG_CTRL_WKUP_SW_EN      14
#define BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_SW_EN, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_SW
 *
 * OTG Software Wake-up
 */

#define BP_USBNC_USB_OTG_CTRL_WKUP_SW      15
#define BM_USBNC_USB_OTG_CTRL_WKUP_SW      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_OTG_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_OTG_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_SW, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_ID_EN
 *
 * OTG Wake-up on ID change enable
 */

#define BP_USBNC_USB_OTG_CTRL_WKUP_ID_EN      16
#define BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   (((v) << 16) & BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_ID_EN, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_VBUS_EN
 *
 * OTG wake-up on VBUS change enable
 */

#define BP_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN      17
#define BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   ((((reg32_t) v) << 17) & BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   (((v) << 17) & BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_VBUS_EN, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WIR
 *
 * OTG Wake-up Interrupt Request  This bit indicates that a wake-up interrupt request is received on
 * the OTG port. This bit                                 is cleared by disabling the wake-up
 * interrupt (clearing bit "OWIE").
 */

#define BP_USBNC_USB_OTG_CTRL_WIR      31
#define BM_USBNC_USB_OTG_CTRL_WIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WIR(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_OTG_CTRL_WIR)
#else
#define BF_USBNC_USB_OTG_CTRL_WIR(v)   (((v) << 31) & BM_USBNC_USB_OTG_CTRL_WIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WIR(v)   BF_CS1(USBNC_USB_OTG_CTRL, WIR, v)
#endif

/*!
 * @brief HW_USBNC_USB_UH1_CTRL - USB Host1 Control Register
 *
 * The USB Host1 control register controls the integration specific features of the USB Host1
 * module. These features are not directly related to the USB functionality, but control special
 * features, interfacing on the USB ports, as well as power control and wake-up functionality.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned OVER_CUR_DIS : 1; //!< Disable Host 1 Overcurrent Detection
        unsigned OVER_CUR_POL : 1; //!< Host 1 Polarity of Overcurrent  The polarity of Host 1 port overcurrent event
        unsigned PWR_POL : 1; //!< Host1 Power Polarity  This bit should be set according to PMIC Power Pin polarity.
        unsigned WIE : 1; //!< Host 1 Wake-up Interrupt Enable  This bit enables or disables the Host 1 wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force Host 1 UTMI PHY Reset  This bit is used to force a reset to the UTMI PHY.  During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY  For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force Host 1 UTMI PHY Suspend  This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode.  For Freescale test only.
        unsigned UTMI_ON_CLOCK : 1; //!< Force Host 1 UTMI PHY clock output on even if suspend mode.
        unsigned WKUP_SW_EN : 1; //!< Host 1 Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< Host 1 Software Wake-up
        unsigned WKUP_ID_EN : 1; //!< Host 1 Wake-up on ID change enable
        unsigned WKUP_VBUS_EN : 1; //!< Host 1 wake-up on VBUS change enable
        unsigned RESERVED1 : 13; //!< Reserved
        unsigned WIR : 1; //!< Host 1 Wake-up Interrupt Request  This bit indicates that a wake-up interrupt request is received on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
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

/* --- Register HW_USBNC_USB_UH1_CTRL, field OVER_CUR_DIS
 *
 * Disable Host 1 Overcurrent Detection
 */

#define BP_USBNC_USB_UH1_CTRL_OVER_CUR_DIS      7
#define BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   ((((reg32_t) v) << 7) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS)
#else
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   (((v) << 7) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   BF_CS1(USBNC_USB_UH1_CTRL, OVER_CUR_DIS, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field OVER_CUR_POL
 *
 * Host 1 Polarity of Overcurrent  The polarity of Host 1 port overcurrent event
 */

#define BP_USBNC_USB_UH1_CTRL_OVER_CUR_POL      8
#define BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   ((((reg32_t) v) << 8) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL)
#else
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   (((v) << 8) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   BF_CS1(USBNC_USB_UH1_CTRL, OVER_CUR_POL, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field PWR_POL
 *
 * Host1 Power Polarity  This bit should be set according to PMIC Power Pin polarity.
 */

#define BP_USBNC_USB_UH1_CTRL_PWR_POL      9
#define BM_USBNC_USB_UH1_CTRL_PWR_POL      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_PWR_POL(v)   ((((reg32_t) v) << 9) & BM_USBNC_USB_UH1_CTRL_PWR_POL)
#else
#define BF_USBNC_USB_UH1_CTRL_PWR_POL(v)   (((v) << 9) & BM_USBNC_USB_UH1_CTRL_PWR_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_PWR_POL(v)   BF_CS1(USBNC_USB_UH1_CTRL, PWR_POL, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WIE
 *
 * Host 1 Wake-up Interrupt Enable  This bit enables or disables the Host 1 wake-up interrupt.
 * Disabling the interrupt also                                 clears the Interrupt request bit.
 * Wake-up interrupt enable should be turned off after                                 receiving a
 * wake-up interrupt and turned on again prior to going in suspend mode
 */

#define BP_USBNC_USB_UH1_CTRL_WIE      10
#define BM_USBNC_USB_UH1_CTRL_WIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH1_CTRL_WIE)
#else
#define BF_USBNC_USB_UH1_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH1_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH1_CTRL, WIE, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field RESET
 *
 * Force Host 1 UTMI PHY Reset  This bit is used to force a reset to the UTMI PHY.  During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY  For Freescale test only.
 */

#define BP_USBNC_USB_UH1_CTRL_RESET      11
#define BM_USBNC_USB_UH1_CTRL_RESET      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH1_CTRL_RESET)
#else
#define BF_USBNC_USB_UH1_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH1_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH1_CTRL, RESET, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field SUSPENDM
 *
 * Force Host 1 UTMI PHY Suspend  This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set                                 bits SUSP and PHCD in USB core register
 * PORTSC1 to put PHY into suspend mode.  For Freescale test only.
 */

#define BP_USBNC_USB_UH1_CTRL_SUSPENDM      12
#define BM_USBNC_USB_UH1_CTRL_SUSPENDM      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH1_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH1_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH1_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH1_CTRL, SUSPENDM, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field UTMI_ON_CLOCK
 *
 * Force Host 1 UTMI PHY clock output on even if suspend mode.
 */

#define BP_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK      13
#define BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK)
#else
#define BF_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   (((v) << 13) & BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   BF_CS1(USBNC_USB_UH1_CTRL, UTMI_ON_CLOCK, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_SW_EN
 *
 * Host 1 Software Wake-up Enable
 */

#define BP_USBNC_USB_UH1_CTRL_WKUP_SW_EN      14
#define BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_SW_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_SW
 *
 * Host 1 Software Wake-up
 */

#define BP_USBNC_USB_UH1_CTRL_WKUP_SW      15
#define BM_USBNC_USB_UH1_CTRL_WKUP_SW      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH1_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH1_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_SW, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_ID_EN
 *
 * Host 1 Wake-up on ID change enable
 */

#define BP_USBNC_USB_UH1_CTRL_WKUP_ID_EN      16
#define BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   (((v) << 16) & BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_ID_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_VBUS_EN
 *
 * Host 1 wake-up on VBUS change enable
 */

#define BP_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN      17
#define BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   ((((reg32_t) v) << 17) & BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   (((v) << 17) & BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_VBUS_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WIR
 *
 * Host 1 Wake-up Interrupt Request  This bit indicates that a wake-up interrupt request is received
 * on the OTG port. This bit                                 is cleared by disabling the wake-up
 * interrupt (clearing bit "OWIE").
 */

#define BP_USBNC_USB_UH1_CTRL_WIR      31
#define BM_USBNC_USB_UH1_CTRL_WIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WIR(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH1_CTRL_WIR)
#else
#define BF_USBNC_USB_UH1_CTRL_WIR(v)   (((v) << 31) & BM_USBNC_USB_UH1_CTRL_WIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WIR(v)   BF_CS1(USBNC_USB_UH1_CTRL, WIR, v)
#endif

/*!
 * @brief HW_USBNC_USB_UH2_CTRL - USB Host2 Control Register
 *
 * The USB Host2 control register controls the integration specific features of the USB host2
 * module. These features are not directly related to the USB functionality, but control
 * special features, interfacing on the USB ports, as well as power control and wake-up
 * functionality.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned WIE : 1; //!< Host 2 Wake-up Interrupt Enable  This bit enables or disables the Host 2 wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force Host 2 UTMI PHY Reset  This bit is used to force a reset to the UTMI PHY.  During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY  For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force Host 2 UTMI PHY Suspend  This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode.  For Freescale test only.
        unsigned RESERVED1 : 1; //!< Force OTG UTMI PHY 480M clock output on when Host 2 is not in suspend mode.
        unsigned WKUP_SW_EN : 1; //!< Host 2 Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< Host 2 Software Wake-up
        unsigned RESERVED2 : 15; //!< Reserved
        unsigned WIR : 1; //!< Host 2 Wake-up Interrupt Request  This bit indicates that a wake-up interrupt request is received on the Host 2 port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
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

/* --- Register HW_USBNC_USB_UH2_CTRL, field WIE
 *
 * Host 2 Wake-up Interrupt Enable  This bit enables or disables the Host 2 wake-up interrupt.
 * Disabling the interrupt also                                 clears the Interrupt request bit.
 * Wake-up interrupt enable should be turned off after                                 receiving a
 * wake-up interrupt and turned on again prior to going in suspend mode
 */

#define BP_USBNC_USB_UH2_CTRL_WIE      10
#define BM_USBNC_USB_UH2_CTRL_WIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH2_CTRL_WIE)
#else
#define BF_USBNC_USB_UH2_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH2_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH2_CTRL, WIE, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field RESET
 *
 * Force Host 2 UTMI PHY Reset  This bit is used to force a reset to the UTMI PHY.  During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY  For Freescale test only.
 */

#define BP_USBNC_USB_UH2_CTRL_RESET      11
#define BM_USBNC_USB_UH2_CTRL_RESET      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH2_CTRL_RESET)
#else
#define BF_USBNC_USB_UH2_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH2_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH2_CTRL, RESET, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field SUSPENDM
 *
 * Force Host 2 UTMI PHY Suspend  This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set                                 bits SUSP and PHCD in USB core register
 * PORTSC1 to put PHY into suspend mode.  For Freescale test only.
 */

#define BP_USBNC_USB_UH2_CTRL_SUSPENDM      12
#define BM_USBNC_USB_UH2_CTRL_SUSPENDM      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH2_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH2_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH2_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH2_CTRL, SUSPENDM, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field WKUP_SW_EN
 *
 * Host 2 Software Wake-up Enable
 */

#define BP_USBNC_USB_UH2_CTRL_WKUP_SW_EN      14
#define BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH2_CTRL, WKUP_SW_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field WKUP_SW
 *
 * Host 2 Software Wake-up
 */

#define BP_USBNC_USB_UH2_CTRL_WKUP_SW      15
#define BM_USBNC_USB_UH2_CTRL_WKUP_SW      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH2_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH2_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH2_CTRL, WKUP_SW, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field WIR
 *
 * Host 2 Wake-up Interrupt Request  This bit indicates that a wake-up interrupt request is received
 * on the Host 2 port. This bit                                 is cleared by disabling the wake-up
 * interrupt (clearing bit "OWIE").
 */

#define BP_USBNC_USB_UH2_CTRL_WIR      31
#define BM_USBNC_USB_UH2_CTRL_WIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WIR(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH2_CTRL_WIR)
#else
#define BF_USBNC_USB_UH2_CTRL_WIR(v)   (((v) << 31) & BM_USBNC_USB_UH2_CTRL_WIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_WIR(v)   BF_CS1(USBNC_USB_UH2_CTRL, WIR, v)
#endif

/*!
 * @brief HW_USBNC_USB_UH3_CTRL - USB Host3 Control Register
 *
 * The USB Host3 control register controls the integration specific features of the USB Host3
 * module. These features are not directly related to the USB functionality, but control
 * special features, interfacing on the USB ports, as well as power control and wake-up
 * functionality.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved0
        unsigned WIE : 1; //!< Host 3 Wake-up Interrupt Enable  This bit enables or disables the Host 3 wake-up interrupt. Disabling the interrupt also clears the Interrupt request bit. Wake-up interrupt enable should be turned off after receiving a wake-up interrupt and turned on again prior to going in suspend mode
        unsigned RESET : 1; //!< Force Host 3 UTMI PHY Reset  This bit is used to force a reset to the UTMI PHY.  During normal operation, S/W should set USBCMD.RST bit to reset the UTMI PHY  For Freescale test only.
        unsigned SUSPENDM : 1; //!< Force Host 3 UTMI PHY Suspend  This bit is used to put PHY into suspend mode. During normal operation, S/W should set bits SUSP and PHCD in USB core register PORTSC1 to put PHY into suspend mode.  For Freescale test only.
        unsigned RESERVED1 : 1; //!< Force OTG UTMI PHY 480M clock output on when Host 3 is not in suspend mode.
        unsigned WKUP_SW_EN : 1; //!< Host 3 Software Wake-up Enable
        unsigned WKUP_SW : 1; //!< Host 3 Software Wake-up
        unsigned RESERVED2 : 15; //!< Reserved
        unsigned WIR : 1; //!< Host 3 Wake-up Interrupt Request  This bit indicates that a wake-up interrupt request is received on the OTG port. This bit is cleared by disabling the wake-up interrupt (clearing bit "OWIE").
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

/* --- Register HW_USBNC_USB_UH3_CTRL, field WIE
 *
 * Host 3 Wake-up Interrupt Enable  This bit enables or disables the Host 3 wake-up interrupt.
 * Disabling the interrupt also                                 clears the Interrupt request bit.
 * Wake-up interrupt enable should be turned off after                                 receiving a
 * wake-up interrupt and turned on again prior to going in suspend mode
 */

#define BP_USBNC_USB_UH3_CTRL_WIE      10
#define BM_USBNC_USB_UH3_CTRL_WIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH3_CTRL_WIE)
#else
#define BF_USBNC_USB_UH3_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH3_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH3_CTRL, WIE, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field RESET
 *
 * Force Host 3 UTMI PHY Reset  This bit is used to force a reset to the UTMI PHY.  During normal
 * operation, S/W should set USBCMD.RST bit to reset the UTMI PHY  For Freescale test only.
 */

#define BP_USBNC_USB_UH3_CTRL_RESET      11
#define BM_USBNC_USB_UH3_CTRL_RESET      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH3_CTRL_RESET)
#else
#define BF_USBNC_USB_UH3_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH3_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH3_CTRL, RESET, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field SUSPENDM
 *
 * Force Host 3 UTMI PHY Suspend  This bit is used to put PHY into suspend mode. During normal
 * operation, S/W should set                                 bits SUSP and PHCD in USB core register
 * PORTSC1 to put PHY into suspend mode.  For Freescale test only.
 */

#define BP_USBNC_USB_UH3_CTRL_SUSPENDM      12
#define BM_USBNC_USB_UH3_CTRL_SUSPENDM      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH3_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH3_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH3_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH3_CTRL, SUSPENDM, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field WKUP_SW_EN
 *
 * Host 3 Software Wake-up Enable
 */

#define BP_USBNC_USB_UH3_CTRL_WKUP_SW_EN      14
#define BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH3_CTRL, WKUP_SW_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field WKUP_SW
 *
 * Host 3 Software Wake-up
 */

#define BP_USBNC_USB_UH3_CTRL_WKUP_SW      15
#define BM_USBNC_USB_UH3_CTRL_WKUP_SW      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH3_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH3_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH3_CTRL, WKUP_SW, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field WIR
 *
 * Host 3 Wake-up Interrupt Request  This bit indicates that a wake-up interrupt request is received
 * on the OTG port. This bit                                 is cleared by disabling the wake-up
 * interrupt (clearing bit "OWIE").
 */

#define BP_USBNC_USB_UH3_CTRL_WIR      31
#define BM_USBNC_USB_UH3_CTRL_WIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WIR(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH3_CTRL_WIR)
#else
#define BF_USBNC_USB_UH3_CTRL_WIR(v)   (((v) << 31) & BM_USBNC_USB_UH3_CTRL_WIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_WIR(v)   BF_CS1(USBNC_USB_UH3_CTRL, WIR, v)
#endif

/*!
 * @brief HW_USBNC_USB_UH2_HSIC_CTRL - USB Host2 HSIC Control Register
 *
 * The USB Host2 HSIC control register controls Host2 high speed IC configuration. These
 * features are not directly related to the USB functionality, but control special features,
 * interfacing on the USB ports, as well as power control.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field HSIC_CLK_ON
 *
 * Force Host2 HSIC module 480M clock on, even when in Host 2 is in suspend mode.
 */

#define BP_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON      11
#define BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   (((v) << 11) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, HSIC_CLK_ON, v)
#endif

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field HSIC_EN
 *
 * Host2 HSIC enable
 */

#define BP_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN      12
#define BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   (((v) << 12) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, HSIC_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field CLK_VLD
 *
 * Indicating whether Host2 HSIC clock is valid.
 */

#define BP_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD      31
#define BM_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD(v)   (((v) << 31) & BM_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, CLK_VLD, v)
#endif

/*!
 * @brief HW_USBNC_USB_UH3_HSIC_CTRL - USB Host3 HSIC Control Register
 *
 * The USB Host3 HSIC control register controls Host3 high speed IC configuration. These
 * features are not directly related to the USB functionality, but control special features,
 * interfacing on the USB ports, as well as power control.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field HSIC_CLK_ON
 *
 * Force Host3 HSIC module 480M clock on, even when in Host 2 is in suspend mode.
 */

#define BP_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON      11
#define BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   (((v) << 11) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, HSIC_CLK_ON, v)
#endif

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field HSIC_EN
 *
 * Host3 HSIC enable
 */

#define BP_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN      12
#define BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   (((v) << 12) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, HSIC_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field CLK_VLD
 *
 * Indicating whether Host3 HSIC clock is valid.
 */

#define BP_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD      31
#define BM_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD(v)   (((v) << 31) & BM_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, CLK_VLD, v)
#endif

/*!
 * @brief HW_USBNC_USB_OTG_PHY_CTRL_0 - OTG UTMI PHY Control 0 Register
 *
 * USB OTG UTMI PHY control register 0 is used to control the on-chip OTG UTMI PHY.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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

/* --- Register HW_USBNC_USB_OTG_PHY_CTRL_0, field UTMI_CLK_VLD
 *
 * Indicating whether OTG UTMI PHY clock is valid
 */

#define BP_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD      31
#define BM_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD)
#else
#define BF_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD(v)   (((v) << 31) & BM_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD(v)   BF_CS1(USBNC_USB_OTG_PHY_CTRL_0, UTMI_CLK_VLD, v)
#endif

/*!
 * @brief HW_USBNC_USB_UH1_PHY_CTRL_0 - Host1 UTMI PHY Control 0 Register
 *
 * USB Host1 UTMI PHY Control Register 0 are used to control the on-chip Host1 UTMI PHY.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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

/* --- Register HW_USBNC_USB_UH1_PHY_CTRL_0, field UTMI_CLK_VLD
 *
 * Indicating whether Host 1 UTMI PHY clock is valid
 */

#define BP_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD      31
#define BM_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD)
#else
#define BF_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD(v)   (((v) << 31) & BM_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD(v)   BF_CS1(USBNC_USB_UH1_PHY_CTRL_0, UTMI_CLK_VLD, v)
#endif



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
} hw_usbnc_t
#endif

//! @brief Macro to access all USBNC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USBNC(0)</code>.
#define HW_USBNC     (*(volatile hw_usbnc_t *) REGS_USBNC_BASE)


#endif // _USBNC_H
