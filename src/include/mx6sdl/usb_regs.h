/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file usb_regs.h
 * @brief definitions for i.MC6 USB related variables and registers
 *
 * 
 */
#include "sdk.h"

#ifndef __USB_REGS__
#define __USB_REGS__

/*!
 * Non-core USB registers
 * These registers are implementation specific and may vary between i.MX parts
 */
typedef struct usbNonCore
{
	uint32_t  USBNC_USB_OTG_CTRL;
	uint32_t  USBNC_USB_UH1_CTRL;
	uint32_t  USBNC_USB_UH2_CTRL;
	uint32_t  USBNC_USB_UH3_CTRL;
	uint32_t  USBNC_USB_UH2_HSIC_CTRL;
	uint32_t  USBNC_USB_UH3_HSIC_CTRL;
	uint32_t  USBNC_USB_OTG_PHY_CTRL_0;
	uint32_t  USBNC_USB_UH1_PHY_CTRL_0;
	uint32_t  USBNC_USB_UH2_HSIC_DLL_CFG1;
	uint32_t  USBNC_USB_UH2_HSIC_DLL_CFG2;
	uint32_t  USBNC_USB_UH2_HSIC_DLL_CFG3;
	uint32_t  USBNC_USB_UH3_HSIC_DLL_CFG1;
	uint32_t  USBNC_USB_UH3_HSIC_DLL_CFG2;
	uint32_t  USBNC_USB_UH3_HSIC_DLL_CFG3;
} usbNonCore_t;

/*!
 * Bit definitions for USB OTG, UH1, UH2 and UH3 control registers
 * Not all bits are defined in every control register !
 */
#define WIR                 (1 << 31)                    // Wakeup interrupt enable
#define WKUP_VBUS_EN        (1 << 17)                    // Wakeup on Vbus change (OTG and UH1 only)
#define WKUP_ID_EN          (1 << 16)                    // Wakeup on ID change (OTG only)
#define WKUP_SW             (1 << 15)                    // Software wakeup
#define WKUP_SW_EN          (1 << 14)                    // Software wakeup enable
#define UTMI_ON_CLOCK       (1 << 13)                    // Force PHY clock (OTG and UH1) on when in low-power suspend
#define _480MHZ_CLOCK_ON    (1 << 13)                    // Force HSIC clock (UH2 and UH3) on when in low-power suspend
#define SUSPENDM            (1 << 12)                    // Force PHY in low-power suspend
#define RESET_PHY           (1 << 11)                    // RESET PHY
#define WIE                 (1 << 10)                    // Wakeup interrupt enable
#define PM                  (1 << 9)                     // Power/Overcurrent mask
#define OVER_CUR_POL        (1 << 8)                     // Overcurrent polarity
#define OVER_CUR_DIS        (1 << 7)                     // Disable overcurrent detection

/*!
 * Bit definitions for HSIC control registers (UH2 and UH3 only)
 */

#define CLK_VLD             (1 << 31)                    // Clock valid status
#define HSIC_EN             (1 << 12)                    // Enable HSIC interface
#define HSIC_CLK_ON         (1 << 11)                    // Force 480 MHz clock on during suspend

/*!
 * Bit definitions for UTMI PHY control 0 registers (OTG and UH1 only)
 */

#define CLK_VLD             (1 << 31)                    // Clock valid status

/*!
 * multiAccess:
 * Address register with RW, Set, Clear and Toggle addresses
 */

typedef struct multiAccess
{
	uint32_t RW;
	uint32_t SET;
	uint32_t CLEAR;
	uint32_t TOGGLE;
} multiAccess_t;

/*!
 * USB PLL bit definitions
 */
#define USBPLL_CTRL_LOCK                       (1 << 31)		// PLL Locked status
#define USBPLL_CTRL_BYPASS                     (1 << 16)		// enable PLL bypass
#define USBPLL_CTRL_BYPASS_CLK_SRC(x)          ((x) << 14)      // Select bypass clock source
#define USBPLL_CTRL_ENABLE                     (1 << 13)        // Enable PLL clock output
#define USBPLL_CTRL_POWER                      (1 << 12)        // Power up PLL
#define USBPLL_CTRL_HOLD_RING_OFF              (1 << 11)        // Analog debug -- not for application use
#define USBPLL_CTRL_DOUBLE_CP                  (1 << 10)        //
#define USBPLL_CTRL_HALF_CP                    (1 << 9)
#define USBPLL_CTRL_DOUBLE_LF                  (1 << 8)
#define USBPLL_CTRL_HALF_LF                    (1 << 7)
#define USBPLL_CTRL_EN_USB_CLKS                (1 << 6)
#define USBPLL_CTRL_CONTROL0                   0                // Not for application use
#define USBPLL_CTRL_DIV_SELECT(x)              (x)              // Pll loop divider 0: Fout=Fref*20; 1: Fout=Fref*22.

/*!
 * Register access and bit definitions for USB PHY on i.MX6
 *
 */
typedef struct usbPhy {
	multiAccess_t	USBPHY_PWD;                         // PHY power down register
	multiAccess_t	USBPHY_TX;                          // Transmitter control
	multiAccess_t	USBPHY_RX;                          // Receiver control
	multiAccess_t	USBPHY_CTRL;                        // PHY general control
	multiAccess_t	USBPHY_STATUS;                      // PHY status register
	multiAccess_t	USBPHY_DEBUG0_STATUS;               // Debug register -- Not for application use
	multiAccess_t	USBPHY_DEBUG1;                      // Debug register == Not for application use
	multiAccess_t	USBPHY_VERSION;                     //
	multiAccess_t	USBPHY_IP;                          // Analog debug
} usbPhy_t;

/*
 * USB PHY bit definitions
 */

#define USBPHY_PWD_RXPWDRX       (1 << 20)         // power down receiver except FS differential RX
#define USBPHY_PWD_RXPWDDIFF     (1 << 19)         // Power down HS receiver
#define USBPHY_PWD_RXPWD1PT1     (1 << 18)         // Power down FS differential receiver
#define USBPHY_PWD_RXPWDENV      (1 << 17)         // power down receiver envelope detector
#define USBPHY_PWD_TXPWDV2I      (1 << 12)         // power down transmitter V/I converter
#define USBPHY_PWD_TXPWDIBIAS    (1 << 11)         // Power down current bias
#define USBPHY_PWD_TXPWDFS       (1 << 10)         // Power down full-speed drivers

#define USBPHY_CTRL_SFTRST                  (1 << 31)
#define USBPHY_CTRL_CLKGATE					(1 << 30)
#define USBPHY_CTRL_UTMI_SUSPENDM           (1 << 29)
#define USBPHY_CTRL_HOST_FORCE_LS_SE0       (1 << 28)
#define USBPHY_CTRL_OTG_ID_VALUE            (1 << 27)
#define USBPHY_CTRL_ENAUTOSET_USBCLKS       (1 << 26)
#define USBPHY_CTRL_ENAUTOCLR_USBCLKGATE    (1 << 25)
#define USBPHY_CTRL_FSDLL_RST_EN            (1 << 24)
#define USBPHY_CTRL_ENVBUSCHG_WKUP          (1 << 23)
#define USBPHY_CTRL_ENIDCHG_WKUP            (1 << 22)
#define USBPHY_CTRL_ENDPDMCHG_WKUP          (1 << 21)
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD       (1 << 20)
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE       (1 << 19)
#define USBPHY_CTRL_ENAUTO_PWRON_PLL        (1 << 18)
#define USBPHY_CTRL_WAKEUP_IRQ              (1 << 17)
#define USBPHY_CTRL_ENIRQWAKEUP             (1 << 16)
#define USBPHY_CTRL_ENUTMILEVEL3            (1 << 15)
#define USBPHY_CTRL_ENUTMILEVEL2            (1 << 14)
#define USBPHY_CTRL_DATA_ON_LRADC           (1 << 13)
#define USBPHY_CTRL_DEVPLUGIN_IRQ           (1 << 12)
#define USBPHY_CTRL_ENIRQDEVPLUGIN          (1 << 11)
#define USBPHY_CTRL_RESUME_IRQ              (1 << 10)
#define USBPHY_CTRL_ENIRQRESUMEDETECT       (1 << 9)
#define USBPHY_CTRL_RESUMEIRQSTICKY         (1 << 8)
#define USBPHY_CTRL_ENOTGIDDETECT           (1 << 7)
#define USBPHY_CTRL_OTG_ID_CHG_IRQ          (1 << 6)
#define USBPHY_CTRL_DEVPLUGIN_POLARITY      (1 << 5)
#define USBPHY_CTRL_ENDEVPLUGINDETECT       (1 << 4)
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ    (1 << 3)
#define USBPHY_CTRL_ENIRQHOSTDISCON         (1 << 2)
#define USBPHY_CTRL_ENHOSTDISCONDETECT      (1 << 1)
#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ        (1 << 0)

/*
 * USBPHY_STATUS bit definitions
 */
#define USBPHY_STATUS_RESUME_STATUS              (1 << 10)
#define USBPHY_STATUS_OTGID_STATUS               (1 << 8)
#define USBPHY_STATUS_DEVPLUGIN_STATUS           (1 << 6)
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS    (1 << 3)

#endif /* __USB_REGS__*/
