/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USB_PHY_H
#define _USB_PHY_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_USB_PHY_PWD - USB PHY Power-Down Register
 * - HW_USB_PHY_PWD_SET - USB PHY Power-Down Register _SET
 * - HW_USB_PHY_PWD_CLR - USB PHY Power-Down Register _CLR
 * - HW_USB_PHY_PWD_TOG - USB PHY Power-Down Register _TOG
 * - HW_USB_PHY_TX - USB PHY Transmitter Control Register
 * - HW_USB_PHY_TX_SET - USB PHY Transmitter Control Register _SET
 * - HW_USB_PHY_TX_CLR - USB PHY Transmitter Control Register _CLR
 * - HW_USB_PHY_TX_TOG - USB PHY Transmitter Control Register _TOG
 * - HW_USB_PHY_RX - USB PHY Receiver Control Register
 * - HW_USB_PHY_RX_SET - USB PHY Receiver Control Register _SET
 * - HW_USB_PHY_RX_CLR - USB PHY Receiver Control Register _CLR
 * - HW_USB_PHY_RX_TOG - USB PHY Receiver Control Register _TOG
 * - HW_USB_PHY_CTRL - USB PHY General Control Register
 * - HW_USB_PHY_CTRL_SET - USB PHY General Control Register _SET
 * - HW_USB_PHY_CTRL_CLR - USB PHY General Control Register _CLR
 * - HW_USB_PHY_CTRL_TOG - USB PHY General Control Register _TOG
 * - HW_USB_PHY_STATUS - USB PHY Status Register
 * - HW_USB_PHY_DEBUG - USB PHY Debug Register
 * - HW_USB_PHY_DEBUG_SET - USB PHY Debug Register _SET
 * - HW_USB_PHY_DEBUG_CLR - USB PHY Debug Register _CLR
 * - HW_USB_PHY_DEBUG_TOG - USB PHY Debug Register _TOG
 * - HW_USB_PHY_DEBUG0_STATUS - UTMI Debug Status Register 0
 * - HW_USB_PHY_DEBUG1 - UTMI Debug Status Register 1
 * - HW_USB_PHY_DEBUG1_SET - UTMI Debug Status Register 1 _SET
 * - HW_USB_PHY_DEBUG1_CLR - UTMI Debug Status Register 1 _CLR
 * - HW_USB_PHY_DEBUG1_TOG - UTMI Debug Status Register 1 _TOG
 * - HW_USB_PHY_VERSION - UTMI RTL Version
 *
 * hw_usb_phy_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_USB_PHY_BASE
#define REGS_USB_PHY0_BASE (0x020c9000) //!< Base address for USB_PHY instance number 0.
#define REGS_USB_PHY1_BASE (0x020ca000) //!< Base address for USB_PHY instance number 1.

//! @brief Get the base address of USB_PHY by instance number.
//! @param x USB_PHY instance number, from 0 through 2.
#define REGS_USB_PHY_BASE(x) ( x == 0 ? REGS_USB_PHY0_BASE : x == 1 ? REGS_USB_PHY1_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_PWD - USB PHY Power-Down Register (RW)
 *
 * The USB PHY Power-Down Register provides overall control of the PHY power state. Before
 * programming this register, the PHY clocks must be enabled in registers USBPHYx_CTRLn and
 * CCM_ANALOG_USBPHYx_PLL_480_CTRLn.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved.
        unsigned TXPWDFS : 1; //!< 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current starvation sources and puts the drivers into high-impedance output. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned TXPWDIBIAS : 1; //!< 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit should be set only when the USB is in suspend mode. This effectively powers down the entire USB transmit path. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned TXPWDV2I : 1; //!< 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current mirror. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned RESERVED1 : 4; //!< Reserved.
        unsigned RXPWDENV : 1; //!< 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch signal). Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWD1PT1 : 1; //!< 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDDIFF : 1; //!< 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDRX : 1; //!< 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RESERVED2 : 11; //!< Reserved.
    } B;
} hw_usb_phy_pwd_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_PWD register
 */
#define HW_USB_PHY_PWD_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_PWD(x)           (*(volatile hw_usb_phy_pwd_t *) HW_USB_PHY_PWD_ADDR(x))
#define HW_USB_PHY_PWD_RD(x)        (HW_USB_PHY_PWD(x).U)
#define HW_USB_PHY_PWD_WR(x, v)     (HW_USB_PHY_PWD(x).U = (v))
#define HW_USB_PHY_PWD_SET(x, v)    (HW_USB_PHY_PWD_WR(x, HW_USB_PHY_PWD_RD(x) |  (v)))
#define HW_USB_PHY_PWD_CLR(x, v)    (HW_USB_PHY_PWD_WR(x, HW_USB_PHY_PWD_RD(x) & ~(v)))
#define HW_USB_PHY_PWD_TOG(x, v)    (HW_USB_PHY_PWD_WR(x, HW_USB_PHY_PWD_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_PWD bitfields
 */

/* --- Register HW_USB_PHY_PWD, field TXPWDFS (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current
 * starvation sources and puts the drivers into high-impedance output. Note that this bit will be
 * auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_TXPWDFS      10
#define BM_USB_PHY_PWD_TXPWDFS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TXPWDFS(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_PWD_TXPWDFS)
#else
#define BF_USB_PHY_PWD_TXPWDFS(v)   (((v) << 10) & BM_USB_PHY_PWD_TXPWDFS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDFS field to a new value.
#define BW_USB_PHY_PWD_TXPWDFS(v)   BF_CS1(USB_PHY_PWD, TXPWDFS, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDIBIAS (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit
 * should be set only when the USB is in suspend mode. This effectively powers down the entire USB
 * transmit path. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_TXPWDIBIAS      11
#define BM_USB_PHY_PWD_TXPWDIBIAS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TXPWDIBIAS(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_PWD_TXPWDIBIAS)
#else
#define BF_USB_PHY_PWD_TXPWDIBIAS(v)   (((v) << 11) & BM_USB_PHY_PWD_TXPWDIBIAS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDIBIAS field to a new value.
#define BW_USB_PHY_PWD_TXPWDIBIAS(v)   BF_CS1(USB_PHY_PWD, TXPWDIBIAS, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDV2I (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current
 * mirror. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_TXPWDV2I      12
#define BM_USB_PHY_PWD_TXPWDV2I      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TXPWDV2I(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_PWD_TXPWDV2I)
#else
#define BF_USB_PHY_PWD_TXPWDV2I(v)   (((v) << 12) & BM_USB_PHY_PWD_TXPWDV2I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDV2I field to a new value.
#define BW_USB_PHY_PWD_TXPWDV2I(v)   BF_CS1(USB_PHY_PWD, TXPWDV2I, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDENV (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch
 * signal). Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_RXPWDENV      17
#define BM_USB_PHY_PWD_RXPWDENV      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWDENV(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_PWD_RXPWDENV)
#else
#define BF_USB_PHY_PWD_RXPWDENV(v)   (((v) << 17) & BM_USB_PHY_PWD_RXPWDENV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDENV field to a new value.
#define BW_USB_PHY_PWD_RXPWDENV(v)   BF_CS1(USB_PHY_PWD, RXPWDENV, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWD1PT1 (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_RXPWD1PT1      18
#define BM_USB_PHY_PWD_RXPWD1PT1      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWD1PT1(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_PWD_RXPWD1PT1)
#else
#define BF_USB_PHY_PWD_RXPWD1PT1(v)   (((v) << 18) & BM_USB_PHY_PWD_RXPWD1PT1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWD1PT1 field to a new value.
#define BW_USB_PHY_PWD_RXPWD1PT1(v)   BF_CS1(USB_PHY_PWD, RXPWD1PT1, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDDIFF (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_RXPWDDIFF      19
#define BM_USB_PHY_PWD_RXPWDDIFF      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWDDIFF(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_PWD_RXPWDDIFF)
#else
#define BF_USB_PHY_PWD_RXPWDDIFF(v)   (((v) << 19) & BM_USB_PHY_PWD_RXPWDDIFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDDIFF field to a new value.
#define BW_USB_PHY_PWD_RXPWDDIFF(v)   BF_CS1(USB_PHY_PWD, RXPWDDIFF, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDRX (RW)
 *
 * 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed
 * differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_RXPWDRX      20
#define BM_USB_PHY_PWD_RXPWDRX      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWDRX(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_PWD_RXPWDRX)
#else
#define BF_USB_PHY_PWD_RXPWDRX(v)   (((v) << 20) & BM_USB_PHY_PWD_RXPWDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDRX field to a new value.
#define BW_USB_PHY_PWD_RXPWDRX(v)   BF_CS1(USB_PHY_PWD, RXPWDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_PWD_SET - USB PHY Power-Down Register _SET (RW)
 *
 * The USB PHY Power-Down Register provides overall control of the PHY power state. Before
 * programming this register, the PHY clocks must be enabled in registers USBPHYx_CTRLn and
 * CCM_ANALOG_USBPHYx_PLL_480_CTRLn.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved.
        unsigned TXPWDFS : 1; //!< 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current starvation sources and puts the drivers into high-impedance output. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned TXPWDIBIAS : 1; //!< 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit should be set only when the USB is in suspend mode. This effectively powers down the entire USB transmit path. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned TXPWDV2I : 1; //!< 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current mirror. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned RESERVED1 : 4; //!< Reserved.
        unsigned RXPWDENV : 1; //!< 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch signal). Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWD1PT1 : 1; //!< 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDDIFF : 1; //!< 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDRX : 1; //!< 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RESERVED2 : 11; //!< Reserved.
    } B;
} hw_usb_phy_pwd_set_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_PWD_SET register
 */
#define HW_USB_PHY_PWD_SET_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_PWD_SET(x)           (*(volatile hw_usb_phy_pwd_set_t *) HW_USB_PHY_PWD_SET_ADDR(x))
#define HW_USB_PHY_PWD_SET_RD(x)        (HW_USB_PHY_PWD_SET(x).U)
#define HW_USB_PHY_PWD_SET_WR(x, v)     (HW_USB_PHY_PWD_SET(x).U = (v))
#define HW_USB_PHY_PWD_SET_SET(x, v)    (HW_USB_PHY_PWD_SET_WR(x, HW_USB_PHY_PWD_SET_RD(x) |  (v)))
#define HW_USB_PHY_PWD_SET_CLR(x, v)    (HW_USB_PHY_PWD_SET_WR(x, HW_USB_PHY_PWD_SET_RD(x) & ~(v)))
#define HW_USB_PHY_PWD_SET_TOG(x, v)    (HW_USB_PHY_PWD_SET_WR(x, HW_USB_PHY_PWD_SET_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_PWD_SET bitfields
 */

/* --- Register HW_USB_PHY_PWD_SET, field TXPWDFS (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current
 * starvation sources and puts the drivers into high-impedance output. Note that this bit will be
 * auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_SET_TXPWDFS      10
#define BM_USB_PHY_PWD_SET_TXPWDFS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_SET_TXPWDFS(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_PWD_SET_TXPWDFS)
#else
#define BF_USB_PHY_PWD_SET_TXPWDFS(v)   (((v) << 10) & BM_USB_PHY_PWD_SET_TXPWDFS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDFS field to a new value.
#define BW_USB_PHY_PWD_SET_TXPWDFS(v)   BF_CS1(USB_PHY_PWD_SET, TXPWDFS, v)
#endif

/* --- Register HW_USB_PHY_PWD_SET, field TXPWDIBIAS (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit
 * should be set only when the USB is in suspend mode. This effectively powers down the entire USB
 * transmit path. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_SET_TXPWDIBIAS      11
#define BM_USB_PHY_PWD_SET_TXPWDIBIAS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_SET_TXPWDIBIAS(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_PWD_SET_TXPWDIBIAS)
#else
#define BF_USB_PHY_PWD_SET_TXPWDIBIAS(v)   (((v) << 11) & BM_USB_PHY_PWD_SET_TXPWDIBIAS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDIBIAS field to a new value.
#define BW_USB_PHY_PWD_SET_TXPWDIBIAS(v)   BF_CS1(USB_PHY_PWD_SET, TXPWDIBIAS, v)
#endif

/* --- Register HW_USB_PHY_PWD_SET, field TXPWDV2I (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current
 * mirror. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_SET_TXPWDV2I      12
#define BM_USB_PHY_PWD_SET_TXPWDV2I      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_SET_TXPWDV2I(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_PWD_SET_TXPWDV2I)
#else
#define BF_USB_PHY_PWD_SET_TXPWDV2I(v)   (((v) << 12) & BM_USB_PHY_PWD_SET_TXPWDV2I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDV2I field to a new value.
#define BW_USB_PHY_PWD_SET_TXPWDV2I(v)   BF_CS1(USB_PHY_PWD_SET, TXPWDV2I, v)
#endif

/* --- Register HW_USB_PHY_PWD_SET, field RXPWDENV (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch
 * signal). Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_SET_RXPWDENV      17
#define BM_USB_PHY_PWD_SET_RXPWDENV      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_SET_RXPWDENV(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_PWD_SET_RXPWDENV)
#else
#define BF_USB_PHY_PWD_SET_RXPWDENV(v)   (((v) << 17) & BM_USB_PHY_PWD_SET_RXPWDENV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDENV field to a new value.
#define BW_USB_PHY_PWD_SET_RXPWDENV(v)   BF_CS1(USB_PHY_PWD_SET, RXPWDENV, v)
#endif

/* --- Register HW_USB_PHY_PWD_SET, field RXPWD1PT1 (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_SET_RXPWD1PT1      18
#define BM_USB_PHY_PWD_SET_RXPWD1PT1      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_SET_RXPWD1PT1(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_PWD_SET_RXPWD1PT1)
#else
#define BF_USB_PHY_PWD_SET_RXPWD1PT1(v)   (((v) << 18) & BM_USB_PHY_PWD_SET_RXPWD1PT1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWD1PT1 field to a new value.
#define BW_USB_PHY_PWD_SET_RXPWD1PT1(v)   BF_CS1(USB_PHY_PWD_SET, RXPWD1PT1, v)
#endif

/* --- Register HW_USB_PHY_PWD_SET, field RXPWDDIFF (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_SET_RXPWDDIFF      19
#define BM_USB_PHY_PWD_SET_RXPWDDIFF      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_SET_RXPWDDIFF(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_PWD_SET_RXPWDDIFF)
#else
#define BF_USB_PHY_PWD_SET_RXPWDDIFF(v)   (((v) << 19) & BM_USB_PHY_PWD_SET_RXPWDDIFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDDIFF field to a new value.
#define BW_USB_PHY_PWD_SET_RXPWDDIFF(v)   BF_CS1(USB_PHY_PWD_SET, RXPWDDIFF, v)
#endif

/* --- Register HW_USB_PHY_PWD_SET, field RXPWDRX (RW)
 *
 * 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed
 * differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_SET_RXPWDRX      20
#define BM_USB_PHY_PWD_SET_RXPWDRX      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_SET_RXPWDRX(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_PWD_SET_RXPWDRX)
#else
#define BF_USB_PHY_PWD_SET_RXPWDRX(v)   (((v) << 20) & BM_USB_PHY_PWD_SET_RXPWDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDRX field to a new value.
#define BW_USB_PHY_PWD_SET_RXPWDRX(v)   BF_CS1(USB_PHY_PWD_SET, RXPWDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_PWD_CLR - USB PHY Power-Down Register _CLR (RW)
 *
 * The USB PHY Power-Down Register provides overall control of the PHY power state. Before
 * programming this register, the PHY clocks must be enabled in registers USBPHYx_CTRLn and
 * CCM_ANALOG_USBPHYx_PLL_480_CTRLn.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved.
        unsigned TXPWDFS : 1; //!< 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current starvation sources and puts the drivers into high-impedance output. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned TXPWDIBIAS : 1; //!< 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit should be set only when the USB is in suspend mode. This effectively powers down the entire USB transmit path. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned TXPWDV2I : 1; //!< 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current mirror. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned RESERVED1 : 4; //!< Reserved.
        unsigned RXPWDENV : 1; //!< 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch signal). Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWD1PT1 : 1; //!< 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDDIFF : 1; //!< 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDRX : 1; //!< 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RESERVED2 : 11; //!< Reserved.
    } B;
} hw_usb_phy_pwd_clr_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_PWD_CLR register
 */
#define HW_USB_PHY_PWD_CLR_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_PWD_CLR(x)           (*(volatile hw_usb_phy_pwd_clr_t *) HW_USB_PHY_PWD_CLR_ADDR(x))
#define HW_USB_PHY_PWD_CLR_RD(x)        (HW_USB_PHY_PWD_CLR(x).U)
#define HW_USB_PHY_PWD_CLR_WR(x, v)     (HW_USB_PHY_PWD_CLR(x).U = (v))
#define HW_USB_PHY_PWD_CLR_SET(x, v)    (HW_USB_PHY_PWD_CLR_WR(x, HW_USB_PHY_PWD_CLR_RD(x) |  (v)))
#define HW_USB_PHY_PWD_CLR_CLR(x, v)    (HW_USB_PHY_PWD_CLR_WR(x, HW_USB_PHY_PWD_CLR_RD(x) & ~(v)))
#define HW_USB_PHY_PWD_CLR_TOG(x, v)    (HW_USB_PHY_PWD_CLR_WR(x, HW_USB_PHY_PWD_CLR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_PWD_CLR bitfields
 */

/* --- Register HW_USB_PHY_PWD_CLR, field TXPWDFS (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current
 * starvation sources and puts the drivers into high-impedance output. Note that this bit will be
 * auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_CLR_TXPWDFS      10
#define BM_USB_PHY_PWD_CLR_TXPWDFS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_CLR_TXPWDFS(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_PWD_CLR_TXPWDFS)
#else
#define BF_USB_PHY_PWD_CLR_TXPWDFS(v)   (((v) << 10) & BM_USB_PHY_PWD_CLR_TXPWDFS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDFS field to a new value.
#define BW_USB_PHY_PWD_CLR_TXPWDFS(v)   BF_CS1(USB_PHY_PWD_CLR, TXPWDFS, v)
#endif

/* --- Register HW_USB_PHY_PWD_CLR, field TXPWDIBIAS (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit
 * should be set only when the USB is in suspend mode. This effectively powers down the entire USB
 * transmit path. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_CLR_TXPWDIBIAS      11
#define BM_USB_PHY_PWD_CLR_TXPWDIBIAS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_CLR_TXPWDIBIAS(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_PWD_CLR_TXPWDIBIAS)
#else
#define BF_USB_PHY_PWD_CLR_TXPWDIBIAS(v)   (((v) << 11) & BM_USB_PHY_PWD_CLR_TXPWDIBIAS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDIBIAS field to a new value.
#define BW_USB_PHY_PWD_CLR_TXPWDIBIAS(v)   BF_CS1(USB_PHY_PWD_CLR, TXPWDIBIAS, v)
#endif

/* --- Register HW_USB_PHY_PWD_CLR, field TXPWDV2I (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current
 * mirror. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_CLR_TXPWDV2I      12
#define BM_USB_PHY_PWD_CLR_TXPWDV2I      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_CLR_TXPWDV2I(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_PWD_CLR_TXPWDV2I)
#else
#define BF_USB_PHY_PWD_CLR_TXPWDV2I(v)   (((v) << 12) & BM_USB_PHY_PWD_CLR_TXPWDV2I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDV2I field to a new value.
#define BW_USB_PHY_PWD_CLR_TXPWDV2I(v)   BF_CS1(USB_PHY_PWD_CLR, TXPWDV2I, v)
#endif

/* --- Register HW_USB_PHY_PWD_CLR, field RXPWDENV (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch
 * signal). Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_CLR_RXPWDENV      17
#define BM_USB_PHY_PWD_CLR_RXPWDENV      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_CLR_RXPWDENV(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_PWD_CLR_RXPWDENV)
#else
#define BF_USB_PHY_PWD_CLR_RXPWDENV(v)   (((v) << 17) & BM_USB_PHY_PWD_CLR_RXPWDENV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDENV field to a new value.
#define BW_USB_PHY_PWD_CLR_RXPWDENV(v)   BF_CS1(USB_PHY_PWD_CLR, RXPWDENV, v)
#endif

/* --- Register HW_USB_PHY_PWD_CLR, field RXPWD1PT1 (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_CLR_RXPWD1PT1      18
#define BM_USB_PHY_PWD_CLR_RXPWD1PT1      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_CLR_RXPWD1PT1(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_PWD_CLR_RXPWD1PT1)
#else
#define BF_USB_PHY_PWD_CLR_RXPWD1PT1(v)   (((v) << 18) & BM_USB_PHY_PWD_CLR_RXPWD1PT1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWD1PT1 field to a new value.
#define BW_USB_PHY_PWD_CLR_RXPWD1PT1(v)   BF_CS1(USB_PHY_PWD_CLR, RXPWD1PT1, v)
#endif

/* --- Register HW_USB_PHY_PWD_CLR, field RXPWDDIFF (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_CLR_RXPWDDIFF      19
#define BM_USB_PHY_PWD_CLR_RXPWDDIFF      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_CLR_RXPWDDIFF(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_PWD_CLR_RXPWDDIFF)
#else
#define BF_USB_PHY_PWD_CLR_RXPWDDIFF(v)   (((v) << 19) & BM_USB_PHY_PWD_CLR_RXPWDDIFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDDIFF field to a new value.
#define BW_USB_PHY_PWD_CLR_RXPWDDIFF(v)   BF_CS1(USB_PHY_PWD_CLR, RXPWDDIFF, v)
#endif

/* --- Register HW_USB_PHY_PWD_CLR, field RXPWDRX (RW)
 *
 * 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed
 * differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_CLR_RXPWDRX      20
#define BM_USB_PHY_PWD_CLR_RXPWDRX      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_CLR_RXPWDRX(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_PWD_CLR_RXPWDRX)
#else
#define BF_USB_PHY_PWD_CLR_RXPWDRX(v)   (((v) << 20) & BM_USB_PHY_PWD_CLR_RXPWDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDRX field to a new value.
#define BW_USB_PHY_PWD_CLR_RXPWDRX(v)   BF_CS1(USB_PHY_PWD_CLR, RXPWDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_PWD_TOG - USB PHY Power-Down Register _TOG (RW)
 *
 * The USB PHY Power-Down Register provides overall control of the PHY power state. Before
 * programming this register, the PHY clocks must be enabled in registers USBPHYx_CTRLn and
 * CCM_ANALOG_USBPHYx_PLL_480_CTRLn.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved.
        unsigned TXPWDFS : 1; //!< 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current starvation sources and puts the drivers into high-impedance output. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned TXPWDIBIAS : 1; //!< 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit should be set only when the USB is in suspend mode. This effectively powers down the entire USB transmit path. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned TXPWDV2I : 1; //!< 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current mirror. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned RESERVED1 : 4; //!< Reserved.
        unsigned RXPWDENV : 1; //!< 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch signal). Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWD1PT1 : 1; //!< 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDDIFF : 1; //!< 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDRX : 1; //!< 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RESERVED2 : 11; //!< Reserved.
    } B;
} hw_usb_phy_pwd_tog_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_PWD_TOG register
 */
#define HW_USB_PHY_PWD_TOG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_PWD_TOG(x)           (*(volatile hw_usb_phy_pwd_tog_t *) HW_USB_PHY_PWD_TOG_ADDR(x))
#define HW_USB_PHY_PWD_TOG_RD(x)        (HW_USB_PHY_PWD_TOG(x).U)
#define HW_USB_PHY_PWD_TOG_WR(x, v)     (HW_USB_PHY_PWD_TOG(x).U = (v))
#define HW_USB_PHY_PWD_TOG_SET(x, v)    (HW_USB_PHY_PWD_TOG_WR(x, HW_USB_PHY_PWD_TOG_RD(x) |  (v)))
#define HW_USB_PHY_PWD_TOG_CLR(x, v)    (HW_USB_PHY_PWD_TOG_WR(x, HW_USB_PHY_PWD_TOG_RD(x) & ~(v)))
#define HW_USB_PHY_PWD_TOG_TOG(x, v)    (HW_USB_PHY_PWD_TOG_WR(x, HW_USB_PHY_PWD_TOG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_PWD_TOG bitfields
 */

/* --- Register HW_USB_PHY_PWD_TOG, field TXPWDFS (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current
 * starvation sources and puts the drivers into high-impedance output. Note that this bit will be
 * auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_TOG_TXPWDFS      10
#define BM_USB_PHY_PWD_TOG_TXPWDFS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TOG_TXPWDFS(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_PWD_TOG_TXPWDFS)
#else
#define BF_USB_PHY_PWD_TOG_TXPWDFS(v)   (((v) << 10) & BM_USB_PHY_PWD_TOG_TXPWDFS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDFS field to a new value.
#define BW_USB_PHY_PWD_TOG_TXPWDFS(v)   BF_CS1(USB_PHY_PWD_TOG, TXPWDFS, v)
#endif

/* --- Register HW_USB_PHY_PWD_TOG, field TXPWDIBIAS (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit
 * should be set only when the USB is in suspend mode. This effectively powers down the entire USB
 * transmit path. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_TOG_TXPWDIBIAS      11
#define BM_USB_PHY_PWD_TOG_TXPWDIBIAS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TOG_TXPWDIBIAS(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_PWD_TOG_TXPWDIBIAS)
#else
#define BF_USB_PHY_PWD_TOG_TXPWDIBIAS(v)   (((v) << 11) & BM_USB_PHY_PWD_TOG_TXPWDIBIAS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDIBIAS field to a new value.
#define BW_USB_PHY_PWD_TOG_TXPWDIBIAS(v)   BF_CS1(USB_PHY_PWD_TOG, TXPWDIBIAS, v)
#endif

/* --- Register HW_USB_PHY_PWD_TOG, field TXPWDV2I (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current
 * mirror. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_TOG_TXPWDV2I      12
#define BM_USB_PHY_PWD_TOG_TXPWDV2I      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TOG_TXPWDV2I(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_PWD_TOG_TXPWDV2I)
#else
#define BF_USB_PHY_PWD_TOG_TXPWDV2I(v)   (((v) << 12) & BM_USB_PHY_PWD_TOG_TXPWDV2I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDV2I field to a new value.
#define BW_USB_PHY_PWD_TOG_TXPWDV2I(v)   BF_CS1(USB_PHY_PWD_TOG, TXPWDV2I, v)
#endif

/* --- Register HW_USB_PHY_PWD_TOG, field RXPWDENV (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch
 * signal). Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_TOG_RXPWDENV      17
#define BM_USB_PHY_PWD_TOG_RXPWDENV      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TOG_RXPWDENV(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_PWD_TOG_RXPWDENV)
#else
#define BF_USB_PHY_PWD_TOG_RXPWDENV(v)   (((v) << 17) & BM_USB_PHY_PWD_TOG_RXPWDENV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDENV field to a new value.
#define BW_USB_PHY_PWD_TOG_RXPWDENV(v)   BF_CS1(USB_PHY_PWD_TOG, RXPWDENV, v)
#endif

/* --- Register HW_USB_PHY_PWD_TOG, field RXPWD1PT1 (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_TOG_RXPWD1PT1      18
#define BM_USB_PHY_PWD_TOG_RXPWD1PT1      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TOG_RXPWD1PT1(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_PWD_TOG_RXPWD1PT1)
#else
#define BF_USB_PHY_PWD_TOG_RXPWD1PT1(v)   (((v) << 18) & BM_USB_PHY_PWD_TOG_RXPWD1PT1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWD1PT1 field to a new value.
#define BW_USB_PHY_PWD_TOG_RXPWD1PT1(v)   BF_CS1(USB_PHY_PWD_TOG, RXPWD1PT1, v)
#endif

/* --- Register HW_USB_PHY_PWD_TOG, field RXPWDDIFF (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_TOG_RXPWDDIFF      19
#define BM_USB_PHY_PWD_TOG_RXPWDDIFF      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TOG_RXPWDDIFF(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_PWD_TOG_RXPWDDIFF)
#else
#define BF_USB_PHY_PWD_TOG_RXPWDDIFF(v)   (((v) << 19) & BM_USB_PHY_PWD_TOG_RXPWDDIFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDDIFF field to a new value.
#define BW_USB_PHY_PWD_TOG_RXPWDDIFF(v)   BF_CS1(USB_PHY_PWD_TOG, RXPWDDIFF, v)
#endif

/* --- Register HW_USB_PHY_PWD_TOG, field RXPWDRX (RW)
 *
 * 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed
 * differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_TOG_RXPWDRX      20
#define BM_USB_PHY_PWD_TOG_RXPWDRX      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TOG_RXPWDRX(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_PWD_TOG_RXPWDRX)
#else
#define BF_USB_PHY_PWD_TOG_RXPWDRX(v)   (((v) << 20) & BM_USB_PHY_PWD_TOG_RXPWDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDRX field to a new value.
#define BW_USB_PHY_PWD_TOG_RXPWDRX(v)   BF_CS1(USB_PHY_PWD_TOG, RXPWDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_TX - USB PHY Transmitter Control Register (RW)
 *
 * The USB PHY Transmitter Control Register handles the transmit controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned D_CAL : 4; //!< Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
        unsigned RESERVED0 : 4; //!< Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DN : 4; //!< Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED1 : 4; //!< Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DP : 4; //!< Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED2 : 12; //!< Reserved.
    } B;
} hw_usb_phy_tx_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_TX register
 */
#define HW_USB_PHY_TX_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_TX(x)           (*(volatile hw_usb_phy_tx_t *) HW_USB_PHY_TX_ADDR(x))
#define HW_USB_PHY_TX_RD(x)        (HW_USB_PHY_TX(x).U)
#define HW_USB_PHY_TX_WR(x, v)     (HW_USB_PHY_TX(x).U = (v))
#define HW_USB_PHY_TX_SET(x, v)    (HW_USB_PHY_TX_WR(x, HW_USB_PHY_TX_RD(x) |  (v)))
#define HW_USB_PHY_TX_CLR(x, v)    (HW_USB_PHY_TX_WR(x, HW_USB_PHY_TX_RD(x) & ~(v)))
#define HW_USB_PHY_TX_TOG(x, v)    (HW_USB_PHY_TX_WR(x, HW_USB_PHY_TX_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_TX bitfields
 */

/* --- Register HW_USB_PHY_TX, field D_CAL (RW)
 *
 * Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
 */

#define BP_USB_PHY_TX_D_CAL      0
#define BM_USB_PHY_TX_D_CAL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_D_CAL(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_TX_D_CAL)
#else
#define BF_USB_PHY_TX_D_CAL(v)   (((v) << 0) & BM_USB_PHY_TX_D_CAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the D_CAL field to a new value.
#define BW_USB_PHY_TX_D_CAL(v)   BF_CS1(USB_PHY_TX, D_CAL, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXCAL45DN (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_TXCAL45DN      8
#define BM_USB_PHY_TX_TXCAL45DN      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TXCAL45DN(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_TX_TXCAL45DN)
#else
#define BF_USB_PHY_TX_TXCAL45DN(v)   (((v) << 8) & BM_USB_PHY_TX_TXCAL45DN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DN field to a new value.
#define BW_USB_PHY_TX_TXCAL45DN(v)   BF_CS1(USB_PHY_TX, TXCAL45DN, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXCAL45DP (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_TXCAL45DP      16
#define BM_USB_PHY_TX_TXCAL45DP      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TXCAL45DP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_TX_TXCAL45DP)
#else
#define BF_USB_PHY_TX_TXCAL45DP(v)   (((v) << 16) & BM_USB_PHY_TX_TXCAL45DP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DP field to a new value.
#define BW_USB_PHY_TX_TXCAL45DP(v)   BF_CS1(USB_PHY_TX, TXCAL45DP, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_TX_SET - USB PHY Transmitter Control Register _SET (RW)
 *
 * The USB PHY Transmitter Control Register handles the transmit controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned D_CAL : 4; //!< Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
        unsigned RESERVED0 : 4; //!< Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DN : 4; //!< Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED1 : 4; //!< Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DP : 4; //!< Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED2 : 12; //!< Reserved.
    } B;
} hw_usb_phy_tx_set_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_TX_SET register
 */
#define HW_USB_PHY_TX_SET_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_TX_SET(x)           (*(volatile hw_usb_phy_tx_set_t *) HW_USB_PHY_TX_SET_ADDR(x))
#define HW_USB_PHY_TX_SET_RD(x)        (HW_USB_PHY_TX_SET(x).U)
#define HW_USB_PHY_TX_SET_WR(x, v)     (HW_USB_PHY_TX_SET(x).U = (v))
#define HW_USB_PHY_TX_SET_SET(x, v)    (HW_USB_PHY_TX_SET_WR(x, HW_USB_PHY_TX_SET_RD(x) |  (v)))
#define HW_USB_PHY_TX_SET_CLR(x, v)    (HW_USB_PHY_TX_SET_WR(x, HW_USB_PHY_TX_SET_RD(x) & ~(v)))
#define HW_USB_PHY_TX_SET_TOG(x, v)    (HW_USB_PHY_TX_SET_WR(x, HW_USB_PHY_TX_SET_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_TX_SET bitfields
 */

/* --- Register HW_USB_PHY_TX_SET, field D_CAL (RW)
 *
 * Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
 */

#define BP_USB_PHY_TX_SET_D_CAL      0
#define BM_USB_PHY_TX_SET_D_CAL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_SET_D_CAL(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_TX_SET_D_CAL)
#else
#define BF_USB_PHY_TX_SET_D_CAL(v)   (((v) << 0) & BM_USB_PHY_TX_SET_D_CAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the D_CAL field to a new value.
#define BW_USB_PHY_TX_SET_D_CAL(v)   BF_CS1(USB_PHY_TX_SET, D_CAL, v)
#endif

/* --- Register HW_USB_PHY_TX_SET, field TXCAL45DN (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_SET_TXCAL45DN      8
#define BM_USB_PHY_TX_SET_TXCAL45DN      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_SET_TXCAL45DN(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_TX_SET_TXCAL45DN)
#else
#define BF_USB_PHY_TX_SET_TXCAL45DN(v)   (((v) << 8) & BM_USB_PHY_TX_SET_TXCAL45DN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DN field to a new value.
#define BW_USB_PHY_TX_SET_TXCAL45DN(v)   BF_CS1(USB_PHY_TX_SET, TXCAL45DN, v)
#endif

/* --- Register HW_USB_PHY_TX_SET, field TXCAL45DP (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_SET_TXCAL45DP      16
#define BM_USB_PHY_TX_SET_TXCAL45DP      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_SET_TXCAL45DP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_TX_SET_TXCAL45DP)
#else
#define BF_USB_PHY_TX_SET_TXCAL45DP(v)   (((v) << 16) & BM_USB_PHY_TX_SET_TXCAL45DP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DP field to a new value.
#define BW_USB_PHY_TX_SET_TXCAL45DP(v)   BF_CS1(USB_PHY_TX_SET, TXCAL45DP, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_TX_CLR - USB PHY Transmitter Control Register _CLR (RW)
 *
 * The USB PHY Transmitter Control Register handles the transmit controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned D_CAL : 4; //!< Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
        unsigned RESERVED0 : 4; //!< Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DN : 4; //!< Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED1 : 4; //!< Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DP : 4; //!< Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED2 : 12; //!< Reserved.
    } B;
} hw_usb_phy_tx_clr_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_TX_CLR register
 */
#define HW_USB_PHY_TX_CLR_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_TX_CLR(x)           (*(volatile hw_usb_phy_tx_clr_t *) HW_USB_PHY_TX_CLR_ADDR(x))
#define HW_USB_PHY_TX_CLR_RD(x)        (HW_USB_PHY_TX_CLR(x).U)
#define HW_USB_PHY_TX_CLR_WR(x, v)     (HW_USB_PHY_TX_CLR(x).U = (v))
#define HW_USB_PHY_TX_CLR_SET(x, v)    (HW_USB_PHY_TX_CLR_WR(x, HW_USB_PHY_TX_CLR_RD(x) |  (v)))
#define HW_USB_PHY_TX_CLR_CLR(x, v)    (HW_USB_PHY_TX_CLR_WR(x, HW_USB_PHY_TX_CLR_RD(x) & ~(v)))
#define HW_USB_PHY_TX_CLR_TOG(x, v)    (HW_USB_PHY_TX_CLR_WR(x, HW_USB_PHY_TX_CLR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_TX_CLR bitfields
 */

/* --- Register HW_USB_PHY_TX_CLR, field D_CAL (RW)
 *
 * Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
 */

#define BP_USB_PHY_TX_CLR_D_CAL      0
#define BM_USB_PHY_TX_CLR_D_CAL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_CLR_D_CAL(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_TX_CLR_D_CAL)
#else
#define BF_USB_PHY_TX_CLR_D_CAL(v)   (((v) << 0) & BM_USB_PHY_TX_CLR_D_CAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the D_CAL field to a new value.
#define BW_USB_PHY_TX_CLR_D_CAL(v)   BF_CS1(USB_PHY_TX_CLR, D_CAL, v)
#endif

/* --- Register HW_USB_PHY_TX_CLR, field TXCAL45DN (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_CLR_TXCAL45DN      8
#define BM_USB_PHY_TX_CLR_TXCAL45DN      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_CLR_TXCAL45DN(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_TX_CLR_TXCAL45DN)
#else
#define BF_USB_PHY_TX_CLR_TXCAL45DN(v)   (((v) << 8) & BM_USB_PHY_TX_CLR_TXCAL45DN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DN field to a new value.
#define BW_USB_PHY_TX_CLR_TXCAL45DN(v)   BF_CS1(USB_PHY_TX_CLR, TXCAL45DN, v)
#endif

/* --- Register HW_USB_PHY_TX_CLR, field TXCAL45DP (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_CLR_TXCAL45DP      16
#define BM_USB_PHY_TX_CLR_TXCAL45DP      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_CLR_TXCAL45DP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_TX_CLR_TXCAL45DP)
#else
#define BF_USB_PHY_TX_CLR_TXCAL45DP(v)   (((v) << 16) & BM_USB_PHY_TX_CLR_TXCAL45DP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DP field to a new value.
#define BW_USB_PHY_TX_CLR_TXCAL45DP(v)   BF_CS1(USB_PHY_TX_CLR, TXCAL45DP, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_TX_TOG - USB PHY Transmitter Control Register _TOG (RW)
 *
 * The USB PHY Transmitter Control Register handles the transmit controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned D_CAL : 4; //!< Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
        unsigned RESERVED0 : 4; //!< Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DN : 4; //!< Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED1 : 4; //!< Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DP : 4; //!< Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED2 : 12; //!< Reserved.
    } B;
} hw_usb_phy_tx_tog_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_TX_TOG register
 */
#define HW_USB_PHY_TX_TOG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_TX_TOG(x)           (*(volatile hw_usb_phy_tx_tog_t *) HW_USB_PHY_TX_TOG_ADDR(x))
#define HW_USB_PHY_TX_TOG_RD(x)        (HW_USB_PHY_TX_TOG(x).U)
#define HW_USB_PHY_TX_TOG_WR(x, v)     (HW_USB_PHY_TX_TOG(x).U = (v))
#define HW_USB_PHY_TX_TOG_SET(x, v)    (HW_USB_PHY_TX_TOG_WR(x, HW_USB_PHY_TX_TOG_RD(x) |  (v)))
#define HW_USB_PHY_TX_TOG_CLR(x, v)    (HW_USB_PHY_TX_TOG_WR(x, HW_USB_PHY_TX_TOG_RD(x) & ~(v)))
#define HW_USB_PHY_TX_TOG_TOG(x, v)    (HW_USB_PHY_TX_TOG_WR(x, HW_USB_PHY_TX_TOG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_TX_TOG bitfields
 */

/* --- Register HW_USB_PHY_TX_TOG, field D_CAL (RW)
 *
 * Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
 */

#define BP_USB_PHY_TX_TOG_D_CAL      0
#define BM_USB_PHY_TX_TOG_D_CAL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TOG_D_CAL(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_TX_TOG_D_CAL)
#else
#define BF_USB_PHY_TX_TOG_D_CAL(v)   (((v) << 0) & BM_USB_PHY_TX_TOG_D_CAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the D_CAL field to a new value.
#define BW_USB_PHY_TX_TOG_D_CAL(v)   BF_CS1(USB_PHY_TX_TOG, D_CAL, v)
#endif

/* --- Register HW_USB_PHY_TX_TOG, field TXCAL45DN (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_TOG_TXCAL45DN      8
#define BM_USB_PHY_TX_TOG_TXCAL45DN      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TOG_TXCAL45DN(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_TX_TOG_TXCAL45DN)
#else
#define BF_USB_PHY_TX_TOG_TXCAL45DN(v)   (((v) << 8) & BM_USB_PHY_TX_TOG_TXCAL45DN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DN field to a new value.
#define BW_USB_PHY_TX_TOG_TXCAL45DN(v)   BF_CS1(USB_PHY_TX_TOG, TXCAL45DN, v)
#endif

/* --- Register HW_USB_PHY_TX_TOG, field TXCAL45DP (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_TOG_TXCAL45DP      16
#define BM_USB_PHY_TX_TOG_TXCAL45DP      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TOG_TXCAL45DP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_TX_TOG_TXCAL45DP)
#else
#define BF_USB_PHY_TX_TOG_TXCAL45DP(v)   (((v) << 16) & BM_USB_PHY_TX_TOG_TXCAL45DP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DP field to a new value.
#define BW_USB_PHY_TX_TOG_TXCAL45DP(v)   BF_CS1(USB_PHY_TX_TOG, TXCAL45DP, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_RX - USB PHY Receiver Control Register (RW)
 *
 * The USB PHY Receiver Control Register handles receive path controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENVADJ : 3; //!< The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 = Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned DISCONADJ : 3; //!< The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 = Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED1 : 15; //!< Reserved.
        unsigned RXDBYPASS : 1; //!< 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the full-speed differential receiver. This test mode is intended for lab use only.
        unsigned RESERVED2 : 9; //!< Reserved.
    } B;
} hw_usb_phy_rx_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_RX register
 */
#define HW_USB_PHY_RX_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_RX(x)           (*(volatile hw_usb_phy_rx_t *) HW_USB_PHY_RX_ADDR(x))
#define HW_USB_PHY_RX_RD(x)        (HW_USB_PHY_RX(x).U)
#define HW_USB_PHY_RX_WR(x, v)     (HW_USB_PHY_RX(x).U = (v))
#define HW_USB_PHY_RX_SET(x, v)    (HW_USB_PHY_RX_WR(x, HW_USB_PHY_RX_RD(x) |  (v)))
#define HW_USB_PHY_RX_CLR(x, v)    (HW_USB_PHY_RX_WR(x, HW_USB_PHY_RX_RD(x) & ~(v)))
#define HW_USB_PHY_RX_TOG(x, v)    (HW_USB_PHY_RX_WR(x, HW_USB_PHY_RX_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_RX bitfields
 */

/* --- Register HW_USB_PHY_RX, field ENVADJ (RW)
 *
 * The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is
 * 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 =
 * Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_ENVADJ      0
#define BM_USB_PHY_RX_ENVADJ      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_ENVADJ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_RX_ENVADJ)
#else
#define BF_USB_PHY_RX_ENVADJ(v)   (((v) << 0) & BM_USB_PHY_RX_ENVADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVADJ field to a new value.
#define BW_USB_PHY_RX_ENVADJ(v)   BF_CS1(USB_PHY_RX, ENVADJ, v)
#endif

/* --- Register HW_USB_PHY_RX, field DISCONADJ (RW)
 *
 * The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage
 * is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 =
 * Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_DISCONADJ      4
#define BM_USB_PHY_RX_DISCONADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_DISCONADJ(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_RX_DISCONADJ)
#else
#define BF_USB_PHY_RX_DISCONADJ(v)   (((v) << 4) & BM_USB_PHY_RX_DISCONADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISCONADJ field to a new value.
#define BW_USB_PHY_RX_DISCONADJ(v)   BF_CS1(USB_PHY_RX, DISCONADJ, v)
#endif

/* --- Register HW_USB_PHY_RX, field RXDBYPASS (RW)
 *
 * 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the
 * full-speed differential receiver. This test mode is intended for lab use only.
 */

#define BP_USB_PHY_RX_RXDBYPASS      22
#define BM_USB_PHY_RX_RXDBYPASS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RXDBYPASS(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_RX_RXDBYPASS)
#else
#define BF_USB_PHY_RX_RXDBYPASS(v)   (((v) << 22) & BM_USB_PHY_RX_RXDBYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDBYPASS field to a new value.
#define BW_USB_PHY_RX_RXDBYPASS(v)   BF_CS1(USB_PHY_RX, RXDBYPASS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_RX_SET - USB PHY Receiver Control Register _SET (RW)
 *
 * The USB PHY Receiver Control Register handles receive path controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENVADJ : 3; //!< The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 = Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned DISCONADJ : 3; //!< The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 = Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED1 : 15; //!< Reserved.
        unsigned RXDBYPASS : 1; //!< 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the full-speed differential receiver. This test mode is intended for lab use only.
        unsigned RESERVED2 : 9; //!< Reserved.
    } B;
} hw_usb_phy_rx_set_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_RX_SET register
 */
#define HW_USB_PHY_RX_SET_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_RX_SET(x)           (*(volatile hw_usb_phy_rx_set_t *) HW_USB_PHY_RX_SET_ADDR(x))
#define HW_USB_PHY_RX_SET_RD(x)        (HW_USB_PHY_RX_SET(x).U)
#define HW_USB_PHY_RX_SET_WR(x, v)     (HW_USB_PHY_RX_SET(x).U = (v))
#define HW_USB_PHY_RX_SET_SET(x, v)    (HW_USB_PHY_RX_SET_WR(x, HW_USB_PHY_RX_SET_RD(x) |  (v)))
#define HW_USB_PHY_RX_SET_CLR(x, v)    (HW_USB_PHY_RX_SET_WR(x, HW_USB_PHY_RX_SET_RD(x) & ~(v)))
#define HW_USB_PHY_RX_SET_TOG(x, v)    (HW_USB_PHY_RX_SET_WR(x, HW_USB_PHY_RX_SET_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_RX_SET bitfields
 */

/* --- Register HW_USB_PHY_RX_SET, field ENVADJ (RW)
 *
 * The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is
 * 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 =
 * Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_SET_ENVADJ      0
#define BM_USB_PHY_RX_SET_ENVADJ      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_SET_ENVADJ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_RX_SET_ENVADJ)
#else
#define BF_USB_PHY_RX_SET_ENVADJ(v)   (((v) << 0) & BM_USB_PHY_RX_SET_ENVADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVADJ field to a new value.
#define BW_USB_PHY_RX_SET_ENVADJ(v)   BF_CS1(USB_PHY_RX_SET, ENVADJ, v)
#endif

/* --- Register HW_USB_PHY_RX_SET, field DISCONADJ (RW)
 *
 * The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage
 * is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 =
 * Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_SET_DISCONADJ      4
#define BM_USB_PHY_RX_SET_DISCONADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_SET_DISCONADJ(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_RX_SET_DISCONADJ)
#else
#define BF_USB_PHY_RX_SET_DISCONADJ(v)   (((v) << 4) & BM_USB_PHY_RX_SET_DISCONADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISCONADJ field to a new value.
#define BW_USB_PHY_RX_SET_DISCONADJ(v)   BF_CS1(USB_PHY_RX_SET, DISCONADJ, v)
#endif

/* --- Register HW_USB_PHY_RX_SET, field RXDBYPASS (RW)
 *
 * 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the
 * full-speed differential receiver. This test mode is intended for lab use only.
 */

#define BP_USB_PHY_RX_SET_RXDBYPASS      22
#define BM_USB_PHY_RX_SET_RXDBYPASS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_SET_RXDBYPASS(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_RX_SET_RXDBYPASS)
#else
#define BF_USB_PHY_RX_SET_RXDBYPASS(v)   (((v) << 22) & BM_USB_PHY_RX_SET_RXDBYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDBYPASS field to a new value.
#define BW_USB_PHY_RX_SET_RXDBYPASS(v)   BF_CS1(USB_PHY_RX_SET, RXDBYPASS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_RX_CLR - USB PHY Receiver Control Register _CLR (RW)
 *
 * The USB PHY Receiver Control Register handles receive path controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENVADJ : 3; //!< The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 = Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned DISCONADJ : 3; //!< The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 = Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED1 : 15; //!< Reserved.
        unsigned RXDBYPASS : 1; //!< 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the full-speed differential receiver. This test mode is intended for lab use only.
        unsigned RESERVED2 : 9; //!< Reserved.
    } B;
} hw_usb_phy_rx_clr_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_RX_CLR register
 */
#define HW_USB_PHY_RX_CLR_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_RX_CLR(x)           (*(volatile hw_usb_phy_rx_clr_t *) HW_USB_PHY_RX_CLR_ADDR(x))
#define HW_USB_PHY_RX_CLR_RD(x)        (HW_USB_PHY_RX_CLR(x).U)
#define HW_USB_PHY_RX_CLR_WR(x, v)     (HW_USB_PHY_RX_CLR(x).U = (v))
#define HW_USB_PHY_RX_CLR_SET(x, v)    (HW_USB_PHY_RX_CLR_WR(x, HW_USB_PHY_RX_CLR_RD(x) |  (v)))
#define HW_USB_PHY_RX_CLR_CLR(x, v)    (HW_USB_PHY_RX_CLR_WR(x, HW_USB_PHY_RX_CLR_RD(x) & ~(v)))
#define HW_USB_PHY_RX_CLR_TOG(x, v)    (HW_USB_PHY_RX_CLR_WR(x, HW_USB_PHY_RX_CLR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_RX_CLR bitfields
 */

/* --- Register HW_USB_PHY_RX_CLR, field ENVADJ (RW)
 *
 * The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is
 * 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 =
 * Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_CLR_ENVADJ      0
#define BM_USB_PHY_RX_CLR_ENVADJ      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_CLR_ENVADJ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_RX_CLR_ENVADJ)
#else
#define BF_USB_PHY_RX_CLR_ENVADJ(v)   (((v) << 0) & BM_USB_PHY_RX_CLR_ENVADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVADJ field to a new value.
#define BW_USB_PHY_RX_CLR_ENVADJ(v)   BF_CS1(USB_PHY_RX_CLR, ENVADJ, v)
#endif

/* --- Register HW_USB_PHY_RX_CLR, field DISCONADJ (RW)
 *
 * The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage
 * is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 =
 * Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_CLR_DISCONADJ      4
#define BM_USB_PHY_RX_CLR_DISCONADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_CLR_DISCONADJ(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_RX_CLR_DISCONADJ)
#else
#define BF_USB_PHY_RX_CLR_DISCONADJ(v)   (((v) << 4) & BM_USB_PHY_RX_CLR_DISCONADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISCONADJ field to a new value.
#define BW_USB_PHY_RX_CLR_DISCONADJ(v)   BF_CS1(USB_PHY_RX_CLR, DISCONADJ, v)
#endif

/* --- Register HW_USB_PHY_RX_CLR, field RXDBYPASS (RW)
 *
 * 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the
 * full-speed differential receiver. This test mode is intended for lab use only.
 */

#define BP_USB_PHY_RX_CLR_RXDBYPASS      22
#define BM_USB_PHY_RX_CLR_RXDBYPASS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_CLR_RXDBYPASS(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_RX_CLR_RXDBYPASS)
#else
#define BF_USB_PHY_RX_CLR_RXDBYPASS(v)   (((v) << 22) & BM_USB_PHY_RX_CLR_RXDBYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDBYPASS field to a new value.
#define BW_USB_PHY_RX_CLR_RXDBYPASS(v)   BF_CS1(USB_PHY_RX_CLR, RXDBYPASS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_RX_TOG - USB PHY Receiver Control Register _TOG (RW)
 *
 * The USB PHY Receiver Control Register handles receive path controls.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENVADJ : 3; //!< The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 = Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned DISCONADJ : 3; //!< The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 = Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED1 : 15; //!< Reserved.
        unsigned RXDBYPASS : 1; //!< 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the full-speed differential receiver. This test mode is intended for lab use only.
        unsigned RESERVED2 : 9; //!< Reserved.
    } B;
} hw_usb_phy_rx_tog_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_RX_TOG register
 */
#define HW_USB_PHY_RX_TOG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_RX_TOG(x)           (*(volatile hw_usb_phy_rx_tog_t *) HW_USB_PHY_RX_TOG_ADDR(x))
#define HW_USB_PHY_RX_TOG_RD(x)        (HW_USB_PHY_RX_TOG(x).U)
#define HW_USB_PHY_RX_TOG_WR(x, v)     (HW_USB_PHY_RX_TOG(x).U = (v))
#define HW_USB_PHY_RX_TOG_SET(x, v)    (HW_USB_PHY_RX_TOG_WR(x, HW_USB_PHY_RX_TOG_RD(x) |  (v)))
#define HW_USB_PHY_RX_TOG_CLR(x, v)    (HW_USB_PHY_RX_TOG_WR(x, HW_USB_PHY_RX_TOG_RD(x) & ~(v)))
#define HW_USB_PHY_RX_TOG_TOG(x, v)    (HW_USB_PHY_RX_TOG_WR(x, HW_USB_PHY_RX_TOG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_RX_TOG bitfields
 */

/* --- Register HW_USB_PHY_RX_TOG, field ENVADJ (RW)
 *
 * The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is
 * 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 =
 * Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_TOG_ENVADJ      0
#define BM_USB_PHY_RX_TOG_ENVADJ      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_TOG_ENVADJ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_RX_TOG_ENVADJ)
#else
#define BF_USB_PHY_RX_TOG_ENVADJ(v)   (((v) << 0) & BM_USB_PHY_RX_TOG_ENVADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVADJ field to a new value.
#define BW_USB_PHY_RX_TOG_ENVADJ(v)   BF_CS1(USB_PHY_RX_TOG, ENVADJ, v)
#endif

/* --- Register HW_USB_PHY_RX_TOG, field DISCONADJ (RW)
 *
 * The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage
 * is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 =
 * Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_TOG_DISCONADJ      4
#define BM_USB_PHY_RX_TOG_DISCONADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_TOG_DISCONADJ(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_RX_TOG_DISCONADJ)
#else
#define BF_USB_PHY_RX_TOG_DISCONADJ(v)   (((v) << 4) & BM_USB_PHY_RX_TOG_DISCONADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISCONADJ field to a new value.
#define BW_USB_PHY_RX_TOG_DISCONADJ(v)   BF_CS1(USB_PHY_RX_TOG, DISCONADJ, v)
#endif

/* --- Register HW_USB_PHY_RX_TOG, field RXDBYPASS (RW)
 *
 * 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the
 * full-speed differential receiver. This test mode is intended for lab use only.
 */

#define BP_USB_PHY_RX_TOG_RXDBYPASS      22
#define BM_USB_PHY_RX_TOG_RXDBYPASS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_TOG_RXDBYPASS(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_RX_TOG_RXDBYPASS)
#else
#define BF_USB_PHY_RX_TOG_RXDBYPASS(v)   (((v) << 22) & BM_USB_PHY_RX_TOG_RXDBYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDBYPASS field to a new value.
#define BW_USB_PHY_RX_TOG_RXDBYPASS(v)   BF_CS1(USB_PHY_RX_TOG, RXDBYPASS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_CTRL - USB PHY General Control Register (RW)
 *
 * The USB PHY General Control Register handles OTG and Host controls. This register also includes
 * interrupt enables and connectivity detect enables and results.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENOTG_ID_CHG_IRQ : 1; //!< Enable OTG_ID_CHG_IRQ.
        unsigned ENHOSTDISCONDETECT : 1; //!< For host mode, enables high-speed disconnect detector. This signal allows the override of enabling the detection that is normally done in the UTMI controller. The UTMI controller enables this circuit whenever the host sends a start-of-frame packet.
        unsigned ENIRQHOSTDISCON : 1; //!< Enables interrupt for detection of disconnection to Device when in high-speed host mode. This should be enabled after ENDEVPLUGINDETECT is enabled.
        unsigned HOSTDISCONDETECT_IRQ : 1; //!< Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENDEVPLUGINDETECT : 1; //!< For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
        unsigned DEVPLUGIN_POLARITY : 1; //!< For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
        unsigned OTG_ID_CHG_IRQ : 1; //!< OTG ID change interrupt. Indicates the value of ID pin changed.
        unsigned ENOTGIDDETECT : 1; //!< Enables circuit to detect resistance of MiniAB ID pin.
        unsigned RESUMEIRQSTICKY : 1; //!< Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only set during the wake-up period.
        unsigned ENIRQRESUMEDETECT : 1; //!< Enables interrupt for detection of a non-J state on the USB line. This should only be enabled after the device has entered suspend mode.
        unsigned RESUME_IRQ : 1; //!< Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset during suspend. Use this bit to wake up from suspend for either the resume or the reset case. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENIRQDEVPLUGIN : 1; //!< Enables interrupt for the detection of connectivity to the USB line.
        unsigned DEVPLUGIN_IRQ : 1; //!< Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned DATA_ON_LRADC : 1; //!< Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
        unsigned ENUTMILEVEL2 : 1; //!< Enables UTMI+ Level2. This should be enabled if needs to support LS device
        unsigned ENUTMILEVEL3 : 1; //!< Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device connected
        unsigned ENIRQWAKEUP : 1; //!< Enables interrupt for the wakeup events.
        unsigned WAKEUP_IRQ : 1; //!< Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned ENAUTOCLR_CLKGATE : 1; //!< Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENAUTOCLR_PHY_PWD : 1; //!< Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENDPDMCHG_WKUP : 1; //!< Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled by default.
        unsigned ENIDCHG_WKUP : 1; //!< Enables the feature to wakeup USB if ID is toggled when USB is suspended.
        unsigned ENVBUSCHG_WKUP : 1; //!< Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
        unsigned FSDLL_RST_EN : 1; //!< Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
        unsigned RESERVED1 : 2; //!< Reserved.
        unsigned OTG_ID_VALUE : 1; //!< Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE has debounce logic to filter the glitches on ID Pad.
        unsigned HOST_FORCE_LS_SE0 : 1; //!< Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in host mode for the resume sequence. After the packet is transferred, this bit is cleared. The design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger this event when leaving suspend. This bit is used in conjunction with USBPHYx_DEBUG_HOST_RESUME_DEBUG.
        unsigned UTMI_SUSPENDM : 1; //!< Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required by the UTMI specification.
        unsigned CLKGATE : 1; //!< Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated. Note this bit can be auto-cleared if there is any wakeup event when USB is suspended while ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
        unsigned SFTRST : 1; //!< Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers. Set to 0 to release the PHY from reset.
    } B;
} hw_usb_phy_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_CTRL register
 */
#define HW_USB_PHY_CTRL_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_CTRL(x)           (*(volatile hw_usb_phy_ctrl_t *) HW_USB_PHY_CTRL_ADDR(x))
#define HW_USB_PHY_CTRL_RD(x)        (HW_USB_PHY_CTRL(x).U)
#define HW_USB_PHY_CTRL_WR(x, v)     (HW_USB_PHY_CTRL(x).U = (v))
#define HW_USB_PHY_CTRL_SET(x, v)    (HW_USB_PHY_CTRL_WR(x, HW_USB_PHY_CTRL_RD(x) |  (v)))
#define HW_USB_PHY_CTRL_CLR(x, v)    (HW_USB_PHY_CTRL_WR(x, HW_USB_PHY_CTRL_RD(x) & ~(v)))
#define HW_USB_PHY_CTRL_TOG(x, v)    (HW_USB_PHY_CTRL_WR(x, HW_USB_PHY_CTRL_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_CTRL bitfields
 */

/* --- Register HW_USB_PHY_CTRL, field ENOTG_ID_CHG_IRQ (RW)
 *
 * Enable OTG_ID_CHG_IRQ.
 */

#define BP_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ      0
#define BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   (((v) << 0) & BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL, ENOTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENHOSTDISCONDETECT (RW)
 *
 * For host mode, enables high-speed disconnect detector. This signal allows the override of
 * enabling the detection that is normally done in the UTMI controller. The UTMI controller enables
 * this circuit whenever the host sends a start-of-frame packet.
 */

#define BP_USB_PHY_CTRL_ENHOSTDISCONDETECT      1
#define BM_USB_PHY_CTRL_ENHOSTDISCONDETECT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_CTRL_ENHOSTDISCONDETECT)
#else
#define BF_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   (((v) << 1) & BM_USB_PHY_CTRL_ENHOSTDISCONDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHOSTDISCONDETECT field to a new value.
#define BW_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   BF_CS1(USB_PHY_CTRL, ENHOSTDISCONDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQHOSTDISCON (RW)
 *
 * Enables interrupt for detection of disconnection to Device when in high-speed host mode. This
 * should be enabled after ENDEVPLUGINDETECT is enabled.
 */

#define BP_USB_PHY_CTRL_ENIRQHOSTDISCON      2
#define BM_USB_PHY_CTRL_ENIRQHOSTDISCON      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_CTRL_ENIRQHOSTDISCON)
#else
#define BF_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   (((v) << 2) & BM_USB_PHY_CTRL_ENIRQHOSTDISCON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQHOSTDISCON field to a new value.
#define BW_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   BF_CS1(USB_PHY_CTRL, ENIRQHOSTDISCON, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field HOSTDISCONDETECT_IRQ (RW)
 *
 * Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to
 * the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ      3
#define BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ)
#else
#define BF_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   (((v) << 3) & BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOSTDISCONDETECT_IRQ field to a new value.
#define BW_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   BF_CS1(USB_PHY_CTRL, HOSTDISCONDETECT_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENDEVPLUGINDETECT (RW)
 *
 * For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
 */

#define BP_USB_PHY_CTRL_ENDEVPLUGINDETECT      4
#define BM_USB_PHY_CTRL_ENDEVPLUGINDETECT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_CTRL_ENDEVPLUGINDETECT)
#else
#define BF_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   (((v) << 4) & BM_USB_PHY_CTRL_ENDEVPLUGINDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDEVPLUGINDETECT field to a new value.
#define BW_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   BF_CS1(USB_PHY_CTRL, ENDEVPLUGINDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DEVPLUGIN_POLARITY (RW)
 *
 * For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is
 * plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
 */

#define BP_USB_PHY_CTRL_DEVPLUGIN_POLARITY      5
#define BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   ((((reg32_t) v) << 5) & BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY)
#else
#define BF_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   (((v) << 5) & BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_POLARITY field to a new value.
#define BW_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   BF_CS1(USB_PHY_CTRL, DEVPLUGIN_POLARITY, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field OTG_ID_CHG_IRQ (RW)
 *
 * OTG ID change interrupt. Indicates the value of ID pin changed.
 */

#define BP_USB_PHY_CTRL_OTG_ID_CHG_IRQ      6
#define BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   (((v) << 6) & BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL, OTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENOTGIDDETECT (RW)
 *
 * Enables circuit to detect resistance of MiniAB ID pin.
 */

#define BP_USB_PHY_CTRL_ENOTGIDDETECT      7
#define BM_USB_PHY_CTRL_ENOTGIDDETECT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENOTGIDDETECT(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_CTRL_ENOTGIDDETECT)
#else
#define BF_USB_PHY_CTRL_ENOTGIDDETECT(v)   (((v) << 7) & BM_USB_PHY_CTRL_ENOTGIDDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTGIDDETECT field to a new value.
#define BW_USB_PHY_CTRL_ENOTGIDDETECT(v)   BF_CS1(USB_PHY_CTRL, ENOTGIDDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RESUMEIRQSTICKY (RW)
 *
 * Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only
 * set during the wake-up period.
 */

#define BP_USB_PHY_CTRL_RESUMEIRQSTICKY      8
#define BM_USB_PHY_CTRL_RESUMEIRQSTICKY      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_CTRL_RESUMEIRQSTICKY)
#else
#define BF_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   (((v) << 8) & BM_USB_PHY_CTRL_RESUMEIRQSTICKY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUMEIRQSTICKY field to a new value.
#define BW_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   BF_CS1(USB_PHY_CTRL, RESUMEIRQSTICKY, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQRESUMEDETECT (RW)
 *
 * Enables interrupt for detection of a non-J state on the USB line. This should only be enabled
 * after the device has entered suspend mode.
 */

#define BP_USB_PHY_CTRL_ENIRQRESUMEDETECT      9
#define BM_USB_PHY_CTRL_ENIRQRESUMEDETECT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   ((((reg32_t) v) << 9) & BM_USB_PHY_CTRL_ENIRQRESUMEDETECT)
#else
#define BF_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   (((v) << 9) & BM_USB_PHY_CTRL_ENIRQRESUMEDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQRESUMEDETECT field to a new value.
#define BW_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   BF_CS1(USB_PHY_CTRL, ENIRQRESUMEDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RESUME_IRQ (RW)
 *
 * Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset
 * during suspend. Use this bit to wake up from suspend for either the resume or the reset case.
 * Reset this bit by writing a 1 to the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_RESUME_IRQ      10
#define BM_USB_PHY_CTRL_RESUME_IRQ      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_RESUME_IRQ(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_CTRL_RESUME_IRQ)
#else
#define BF_USB_PHY_CTRL_RESUME_IRQ(v)   (((v) << 10) & BM_USB_PHY_CTRL_RESUME_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUME_IRQ field to a new value.
#define BW_USB_PHY_CTRL_RESUME_IRQ(v)   BF_CS1(USB_PHY_CTRL, RESUME_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQDEVPLUGIN (RW)
 *
 * Enables interrupt for the detection of connectivity to the USB line.
 */

#define BP_USB_PHY_CTRL_ENIRQDEVPLUGIN      11
#define BM_USB_PHY_CTRL_ENIRQDEVPLUGIN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_CTRL_ENIRQDEVPLUGIN)
#else
#define BF_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   (((v) << 11) & BM_USB_PHY_CTRL_ENIRQDEVPLUGIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQDEVPLUGIN field to a new value.
#define BW_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   BF_CS1(USB_PHY_CTRL, ENIRQDEVPLUGIN, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DEVPLUGIN_IRQ (RW)
 *
 * Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_DEVPLUGIN_IRQ      12
#define BM_USB_PHY_CTRL_DEVPLUGIN_IRQ      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_CTRL_DEVPLUGIN_IRQ)
#else
#define BF_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   (((v) << 12) & BM_USB_PHY_CTRL_DEVPLUGIN_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_IRQ field to a new value.
#define BW_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   BF_CS1(USB_PHY_CTRL, DEVPLUGIN_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DATA_ON_LRADC (RW)
 *
 * Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
 */

#define BP_USB_PHY_CTRL_DATA_ON_LRADC      13
#define BM_USB_PHY_CTRL_DATA_ON_LRADC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_DATA_ON_LRADC(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_CTRL_DATA_ON_LRADC)
#else
#define BF_USB_PHY_CTRL_DATA_ON_LRADC(v)   (((v) << 13) & BM_USB_PHY_CTRL_DATA_ON_LRADC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_ON_LRADC field to a new value.
#define BW_USB_PHY_CTRL_DATA_ON_LRADC(v)   BF_CS1(USB_PHY_CTRL, DATA_ON_LRADC, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENUTMILEVEL2 (RW)
 *
 * Enables UTMI+ Level2. This should be enabled if needs to support LS device
 */

#define BP_USB_PHY_CTRL_ENUTMILEVEL2      14
#define BM_USB_PHY_CTRL_ENUTMILEVEL2      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENUTMILEVEL2(v)   ((((reg32_t) v) << 14) & BM_USB_PHY_CTRL_ENUTMILEVEL2)
#else
#define BF_USB_PHY_CTRL_ENUTMILEVEL2(v)   (((v) << 14) & BM_USB_PHY_CTRL_ENUTMILEVEL2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL2 field to a new value.
#define BW_USB_PHY_CTRL_ENUTMILEVEL2(v)   BF_CS1(USB_PHY_CTRL, ENUTMILEVEL2, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENUTMILEVEL3 (RW)
 *
 * Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device
 * connected
 */

#define BP_USB_PHY_CTRL_ENUTMILEVEL3      15
#define BM_USB_PHY_CTRL_ENUTMILEVEL3      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENUTMILEVEL3(v)   ((((reg32_t) v) << 15) & BM_USB_PHY_CTRL_ENUTMILEVEL3)
#else
#define BF_USB_PHY_CTRL_ENUTMILEVEL3(v)   (((v) << 15) & BM_USB_PHY_CTRL_ENUTMILEVEL3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL3 field to a new value.
#define BW_USB_PHY_CTRL_ENUTMILEVEL3(v)   BF_CS1(USB_PHY_CTRL, ENUTMILEVEL3, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQWAKEUP (RW)
 *
 * Enables interrupt for the wakeup events.
 */

#define BP_USB_PHY_CTRL_ENIRQWAKEUP      16
#define BM_USB_PHY_CTRL_ENIRQWAKEUP      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIRQWAKEUP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_CTRL_ENIRQWAKEUP)
#else
#define BF_USB_PHY_CTRL_ENIRQWAKEUP(v)   (((v) << 16) & BM_USB_PHY_CTRL_ENIRQWAKEUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQWAKEUP field to a new value.
#define BW_USB_PHY_CTRL_ENIRQWAKEUP(v)   BF_CS1(USB_PHY_CTRL, ENIRQWAKEUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field WAKEUP_IRQ (RW)
 *
 * Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_WAKEUP_IRQ      17
#define BM_USB_PHY_CTRL_WAKEUP_IRQ      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_WAKEUP_IRQ(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_CTRL_WAKEUP_IRQ)
#else
#define BF_USB_PHY_CTRL_WAKEUP_IRQ(v)   (((v) << 17) & BM_USB_PHY_CTRL_WAKEUP_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP_IRQ field to a new value.
#define BW_USB_PHY_CTRL_WAKEUP_IRQ(v)   BF_CS1(USB_PHY_CTRL, WAKEUP_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENAUTOCLR_CLKGATE (RW)
 *
 * Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is
 * suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
 */

#define BP_USB_PHY_CTRL_ENAUTOCLR_CLKGATE      19
#define BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE)
#else
#define BF_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   (((v) << 19) & BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   BF_CS1(USB_PHY_CTRL, ENAUTOCLR_CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENAUTOCLR_PHY_PWD (RW)
 *
 * Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event
 * while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's
 * interaction.
 */

#define BP_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD      20
#define BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD)
#else
#define BF_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   (((v) << 20) & BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_PHY_PWD field to a new value.
#define BW_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   BF_CS1(USB_PHY_CTRL, ENAUTOCLR_PHY_PWD, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENDPDMCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled
 * by default.
 */

#define BP_USB_PHY_CTRL_ENDPDMCHG_WKUP      21
#define BM_USB_PHY_CTRL_ENDPDMCHG_WKUP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_CTRL_ENDPDMCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   (((v) << 21) & BM_USB_PHY_CTRL_ENDPDMCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDPDMCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENDPDMCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIDCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if ID is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_ENIDCHG_WKUP      22
#define BM_USB_PHY_CTRL_ENIDCHG_WKUP      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIDCHG_WKUP(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_CTRL_ENIDCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_ENIDCHG_WKUP(v)   (((v) << 22) & BM_USB_PHY_CTRL_ENIDCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIDCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_ENIDCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENIDCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENVBUSCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_ENVBUSCHG_WKUP      23
#define BM_USB_PHY_CTRL_ENVBUSCHG_WKUP      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   ((((reg32_t) v) << 23) & BM_USB_PHY_CTRL_ENVBUSCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   (((v) << 23) & BM_USB_PHY_CTRL_ENVBUSCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVBUSCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENVBUSCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field FSDLL_RST_EN (RW)
 *
 * Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
 */

#define BP_USB_PHY_CTRL_FSDLL_RST_EN      24
#define BM_USB_PHY_CTRL_FSDLL_RST_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_FSDLL_RST_EN(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_CTRL_FSDLL_RST_EN)
#else
#define BF_USB_PHY_CTRL_FSDLL_RST_EN(v)   (((v) << 24) & BM_USB_PHY_CTRL_FSDLL_RST_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FSDLL_RST_EN field to a new value.
#define BW_USB_PHY_CTRL_FSDLL_RST_EN(v)   BF_CS1(USB_PHY_CTRL, FSDLL_RST_EN, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field OTG_ID_VALUE (RO)
 *
 * Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE
 * has debounce logic to filter the glitches on ID Pad.
 */

#define BP_USB_PHY_CTRL_OTG_ID_VALUE      27
#define BM_USB_PHY_CTRL_OTG_ID_VALUE      0x08000000

/* --- Register HW_USB_PHY_CTRL, field HOST_FORCE_LS_SE0 (RW)
 *
 * Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in
 * host mode for the resume sequence. After the packet is transferred, this bit is cleared. The
 * design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger
 * this event when leaving suspend. This bit is used in conjunction with
 * USBPHYx_DEBUG_HOST_RESUME_DEBUG.
 */

#define BP_USB_PHY_CTRL_HOST_FORCE_LS_SE0      28
#define BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   ((((reg32_t) v) << 28) & BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0)
#else
#define BF_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   (((v) << 28) & BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_FORCE_LS_SE0 field to a new value.
#define BW_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   BF_CS1(USB_PHY_CTRL, HOST_FORCE_LS_SE0, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field UTMI_SUSPENDM (RO)
 *
 * Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD
 * are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required
 * by the UTMI specification.
 */

#define BP_USB_PHY_CTRL_UTMI_SUSPENDM      29
#define BM_USB_PHY_CTRL_UTMI_SUSPENDM      0x20000000

/* --- Register HW_USB_PHY_CTRL, field CLKGATE (RW)
 *
 * Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while
 * the USB is not actively being used. Configuration state is kept while the clock is gated. Note
 * this bit can be auto-cleared if there is any wakeup event when USB is suspended while
 * ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_CTRL_CLKGATE      30
#define BM_USB_PHY_CTRL_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_CTRL_CLKGATE)
#else
#define BF_USB_PHY_CTRL_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_CTRL_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_CLKGATE(v)   BF_CS1(USB_PHY_CTRL, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field SFTRST (RW)
 *
 * Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL
 * registers. Set to 0 to release the PHY from reset.
 */

#define BP_USB_PHY_CTRL_SFTRST      31
#define BM_USB_PHY_CTRL_SFTRST      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SFTRST(v)   ((((reg32_t) v) << 31) & BM_USB_PHY_CTRL_SFTRST)
#else
#define BF_USB_PHY_CTRL_SFTRST(v)   (((v) << 31) & BM_USB_PHY_CTRL_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_USB_PHY_CTRL_SFTRST(v)   BF_CS1(USB_PHY_CTRL, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_CTRL_SET - USB PHY General Control Register _SET (RW)
 *
 * The USB PHY General Control Register handles OTG and Host controls. This register also includes
 * interrupt enables and connectivity detect enables and results.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENOTG_ID_CHG_IRQ : 1; //!< Enable OTG_ID_CHG_IRQ.
        unsigned ENHOSTDISCONDETECT : 1; //!< For host mode, enables high-speed disconnect detector. This signal allows the override of enabling the detection that is normally done in the UTMI controller. The UTMI controller enables this circuit whenever the host sends a start-of-frame packet.
        unsigned ENIRQHOSTDISCON : 1; //!< Enables interrupt for detection of disconnection to Device when in high-speed host mode. This should be enabled after ENDEVPLUGINDETECT is enabled.
        unsigned HOSTDISCONDETECT_IRQ : 1; //!< Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENDEVPLUGINDETECT : 1; //!< For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
        unsigned DEVPLUGIN_POLARITY : 1; //!< For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
        unsigned OTG_ID_CHG_IRQ : 1; //!< OTG ID change interrupt. Indicates the value of ID pin changed.
        unsigned ENOTGIDDETECT : 1; //!< Enables circuit to detect resistance of MiniAB ID pin.
        unsigned RESUMEIRQSTICKY : 1; //!< Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only set during the wake-up period.
        unsigned ENIRQRESUMEDETECT : 1; //!< Enables interrupt for detection of a non-J state on the USB line. This should only be enabled after the device has entered suspend mode.
        unsigned RESUME_IRQ : 1; //!< Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset during suspend. Use this bit to wake up from suspend for either the resume or the reset case. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENIRQDEVPLUGIN : 1; //!< Enables interrupt for the detection of connectivity to the USB line.
        unsigned DEVPLUGIN_IRQ : 1; //!< Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned DATA_ON_LRADC : 1; //!< Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
        unsigned ENUTMILEVEL2 : 1; //!< Enables UTMI+ Level2. This should be enabled if needs to support LS device
        unsigned ENUTMILEVEL3 : 1; //!< Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device connected
        unsigned ENIRQWAKEUP : 1; //!< Enables interrupt for the wakeup events.
        unsigned WAKEUP_IRQ : 1; //!< Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned ENAUTOCLR_CLKGATE : 1; //!< Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENAUTOCLR_PHY_PWD : 1; //!< Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENDPDMCHG_WKUP : 1; //!< Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled by default.
        unsigned ENIDCHG_WKUP : 1; //!< Enables the feature to wakeup USB if ID is toggled when USB is suspended.
        unsigned ENVBUSCHG_WKUP : 1; //!< Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
        unsigned FSDLL_RST_EN : 1; //!< Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
        unsigned RESERVED1 : 2; //!< Reserved.
        unsigned OTG_ID_VALUE : 1; //!< Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE has debounce logic to filter the glitches on ID Pad.
        unsigned HOST_FORCE_LS_SE0 : 1; //!< Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in host mode for the resume sequence. After the packet is transferred, this bit is cleared. The design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger this event when leaving suspend. This bit is used in conjunction with USBPHYx_DEBUG_HOST_RESUME_DEBUG.
        unsigned UTMI_SUSPENDM : 1; //!< Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required by the UTMI specification.
        unsigned CLKGATE : 1; //!< Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated. Note this bit can be auto-cleared if there is any wakeup event when USB is suspended while ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
        unsigned SFTRST : 1; //!< Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers. Set to 0 to release the PHY from reset.
    } B;
} hw_usb_phy_ctrl_set_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_CTRL_SET register
 */
#define HW_USB_PHY_CTRL_SET_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_CTRL_SET(x)           (*(volatile hw_usb_phy_ctrl_set_t *) HW_USB_PHY_CTRL_SET_ADDR(x))
#define HW_USB_PHY_CTRL_SET_RD(x)        (HW_USB_PHY_CTRL_SET(x).U)
#define HW_USB_PHY_CTRL_SET_WR(x, v)     (HW_USB_PHY_CTRL_SET(x).U = (v))
#define HW_USB_PHY_CTRL_SET_SET(x, v)    (HW_USB_PHY_CTRL_SET_WR(x, HW_USB_PHY_CTRL_SET_RD(x) |  (v)))
#define HW_USB_PHY_CTRL_SET_CLR(x, v)    (HW_USB_PHY_CTRL_SET_WR(x, HW_USB_PHY_CTRL_SET_RD(x) & ~(v)))
#define HW_USB_PHY_CTRL_SET_TOG(x, v)    (HW_USB_PHY_CTRL_SET_WR(x, HW_USB_PHY_CTRL_SET_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_CTRL_SET bitfields
 */

/* --- Register HW_USB_PHY_CTRL_SET, field ENOTG_ID_CHG_IRQ (RW)
 *
 * Enable OTG_ID_CHG_IRQ.
 */

#define BP_USB_PHY_CTRL_SET_ENOTG_ID_CHG_IRQ      0
#define BM_USB_PHY_CTRL_SET_ENOTG_ID_CHG_IRQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENOTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_CTRL_SET_ENOTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_SET_ENOTG_ID_CHG_IRQ(v)   (((v) << 0) & BM_USB_PHY_CTRL_SET_ENOTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_SET_ENOTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL_SET, ENOTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENHOSTDISCONDETECT (RW)
 *
 * For host mode, enables high-speed disconnect detector. This signal allows the override of
 * enabling the detection that is normally done in the UTMI controller. The UTMI controller enables
 * this circuit whenever the host sends a start-of-frame packet.
 */

#define BP_USB_PHY_CTRL_SET_ENHOSTDISCONDETECT      1
#define BM_USB_PHY_CTRL_SET_ENHOSTDISCONDETECT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENHOSTDISCONDETECT(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_CTRL_SET_ENHOSTDISCONDETECT)
#else
#define BF_USB_PHY_CTRL_SET_ENHOSTDISCONDETECT(v)   (((v) << 1) & BM_USB_PHY_CTRL_SET_ENHOSTDISCONDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHOSTDISCONDETECT field to a new value.
#define BW_USB_PHY_CTRL_SET_ENHOSTDISCONDETECT(v)   BF_CS1(USB_PHY_CTRL_SET, ENHOSTDISCONDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENIRQHOSTDISCON (RW)
 *
 * Enables interrupt for detection of disconnection to Device when in high-speed host mode. This
 * should be enabled after ENDEVPLUGINDETECT is enabled.
 */

#define BP_USB_PHY_CTRL_SET_ENIRQHOSTDISCON      2
#define BM_USB_PHY_CTRL_SET_ENIRQHOSTDISCON      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENIRQHOSTDISCON(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_CTRL_SET_ENIRQHOSTDISCON)
#else
#define BF_USB_PHY_CTRL_SET_ENIRQHOSTDISCON(v)   (((v) << 2) & BM_USB_PHY_CTRL_SET_ENIRQHOSTDISCON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQHOSTDISCON field to a new value.
#define BW_USB_PHY_CTRL_SET_ENIRQHOSTDISCON(v)   BF_CS1(USB_PHY_CTRL_SET, ENIRQHOSTDISCON, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field HOSTDISCONDETECT_IRQ (RW)
 *
 * Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to
 * the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_SET_HOSTDISCONDETECT_IRQ      3
#define BM_USB_PHY_CTRL_SET_HOSTDISCONDETECT_IRQ      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_HOSTDISCONDETECT_IRQ(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_CTRL_SET_HOSTDISCONDETECT_IRQ)
#else
#define BF_USB_PHY_CTRL_SET_HOSTDISCONDETECT_IRQ(v)   (((v) << 3) & BM_USB_PHY_CTRL_SET_HOSTDISCONDETECT_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOSTDISCONDETECT_IRQ field to a new value.
#define BW_USB_PHY_CTRL_SET_HOSTDISCONDETECT_IRQ(v)   BF_CS1(USB_PHY_CTRL_SET, HOSTDISCONDETECT_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENDEVPLUGINDETECT (RW)
 *
 * For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
 */

#define BP_USB_PHY_CTRL_SET_ENDEVPLUGINDETECT      4
#define BM_USB_PHY_CTRL_SET_ENDEVPLUGINDETECT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENDEVPLUGINDETECT(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_CTRL_SET_ENDEVPLUGINDETECT)
#else
#define BF_USB_PHY_CTRL_SET_ENDEVPLUGINDETECT(v)   (((v) << 4) & BM_USB_PHY_CTRL_SET_ENDEVPLUGINDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDEVPLUGINDETECT field to a new value.
#define BW_USB_PHY_CTRL_SET_ENDEVPLUGINDETECT(v)   BF_CS1(USB_PHY_CTRL_SET, ENDEVPLUGINDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field DEVPLUGIN_POLARITY (RW)
 *
 * For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is
 * plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
 */

#define BP_USB_PHY_CTRL_SET_DEVPLUGIN_POLARITY      5
#define BM_USB_PHY_CTRL_SET_DEVPLUGIN_POLARITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_DEVPLUGIN_POLARITY(v)   ((((reg32_t) v) << 5) & BM_USB_PHY_CTRL_SET_DEVPLUGIN_POLARITY)
#else
#define BF_USB_PHY_CTRL_SET_DEVPLUGIN_POLARITY(v)   (((v) << 5) & BM_USB_PHY_CTRL_SET_DEVPLUGIN_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_POLARITY field to a new value.
#define BW_USB_PHY_CTRL_SET_DEVPLUGIN_POLARITY(v)   BF_CS1(USB_PHY_CTRL_SET, DEVPLUGIN_POLARITY, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field OTG_ID_CHG_IRQ (RW)
 *
 * OTG ID change interrupt. Indicates the value of ID pin changed.
 */

#define BP_USB_PHY_CTRL_SET_OTG_ID_CHG_IRQ      6
#define BM_USB_PHY_CTRL_SET_OTG_ID_CHG_IRQ      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_OTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_CTRL_SET_OTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_SET_OTG_ID_CHG_IRQ(v)   (((v) << 6) & BM_USB_PHY_CTRL_SET_OTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_SET_OTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL_SET, OTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENOTGIDDETECT (RW)
 *
 * Enables circuit to detect resistance of MiniAB ID pin.
 */

#define BP_USB_PHY_CTRL_SET_ENOTGIDDETECT      7
#define BM_USB_PHY_CTRL_SET_ENOTGIDDETECT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENOTGIDDETECT(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_CTRL_SET_ENOTGIDDETECT)
#else
#define BF_USB_PHY_CTRL_SET_ENOTGIDDETECT(v)   (((v) << 7) & BM_USB_PHY_CTRL_SET_ENOTGIDDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTGIDDETECT field to a new value.
#define BW_USB_PHY_CTRL_SET_ENOTGIDDETECT(v)   BF_CS1(USB_PHY_CTRL_SET, ENOTGIDDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field RESUMEIRQSTICKY (RW)
 *
 * Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only
 * set during the wake-up period.
 */

#define BP_USB_PHY_CTRL_SET_RESUMEIRQSTICKY      8
#define BM_USB_PHY_CTRL_SET_RESUMEIRQSTICKY      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_RESUMEIRQSTICKY(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_CTRL_SET_RESUMEIRQSTICKY)
#else
#define BF_USB_PHY_CTRL_SET_RESUMEIRQSTICKY(v)   (((v) << 8) & BM_USB_PHY_CTRL_SET_RESUMEIRQSTICKY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUMEIRQSTICKY field to a new value.
#define BW_USB_PHY_CTRL_SET_RESUMEIRQSTICKY(v)   BF_CS1(USB_PHY_CTRL_SET, RESUMEIRQSTICKY, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENIRQRESUMEDETECT (RW)
 *
 * Enables interrupt for detection of a non-J state on the USB line. This should only be enabled
 * after the device has entered suspend mode.
 */

#define BP_USB_PHY_CTRL_SET_ENIRQRESUMEDETECT      9
#define BM_USB_PHY_CTRL_SET_ENIRQRESUMEDETECT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENIRQRESUMEDETECT(v)   ((((reg32_t) v) << 9) & BM_USB_PHY_CTRL_SET_ENIRQRESUMEDETECT)
#else
#define BF_USB_PHY_CTRL_SET_ENIRQRESUMEDETECT(v)   (((v) << 9) & BM_USB_PHY_CTRL_SET_ENIRQRESUMEDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQRESUMEDETECT field to a new value.
#define BW_USB_PHY_CTRL_SET_ENIRQRESUMEDETECT(v)   BF_CS1(USB_PHY_CTRL_SET, ENIRQRESUMEDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field RESUME_IRQ (RW)
 *
 * Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset
 * during suspend. Use this bit to wake up from suspend for either the resume or the reset case.
 * Reset this bit by writing a 1 to the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_SET_RESUME_IRQ      10
#define BM_USB_PHY_CTRL_SET_RESUME_IRQ      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_RESUME_IRQ(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_CTRL_SET_RESUME_IRQ)
#else
#define BF_USB_PHY_CTRL_SET_RESUME_IRQ(v)   (((v) << 10) & BM_USB_PHY_CTRL_SET_RESUME_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUME_IRQ field to a new value.
#define BW_USB_PHY_CTRL_SET_RESUME_IRQ(v)   BF_CS1(USB_PHY_CTRL_SET, RESUME_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENIRQDEVPLUGIN (RW)
 *
 * Enables interrupt for the detection of connectivity to the USB line.
 */

#define BP_USB_PHY_CTRL_SET_ENIRQDEVPLUGIN      11
#define BM_USB_PHY_CTRL_SET_ENIRQDEVPLUGIN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENIRQDEVPLUGIN(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_CTRL_SET_ENIRQDEVPLUGIN)
#else
#define BF_USB_PHY_CTRL_SET_ENIRQDEVPLUGIN(v)   (((v) << 11) & BM_USB_PHY_CTRL_SET_ENIRQDEVPLUGIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQDEVPLUGIN field to a new value.
#define BW_USB_PHY_CTRL_SET_ENIRQDEVPLUGIN(v)   BF_CS1(USB_PHY_CTRL_SET, ENIRQDEVPLUGIN, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field DEVPLUGIN_IRQ (RW)
 *
 * Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_SET_DEVPLUGIN_IRQ      12
#define BM_USB_PHY_CTRL_SET_DEVPLUGIN_IRQ      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_DEVPLUGIN_IRQ(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_CTRL_SET_DEVPLUGIN_IRQ)
#else
#define BF_USB_PHY_CTRL_SET_DEVPLUGIN_IRQ(v)   (((v) << 12) & BM_USB_PHY_CTRL_SET_DEVPLUGIN_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_IRQ field to a new value.
#define BW_USB_PHY_CTRL_SET_DEVPLUGIN_IRQ(v)   BF_CS1(USB_PHY_CTRL_SET, DEVPLUGIN_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field DATA_ON_LRADC (RW)
 *
 * Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
 */

#define BP_USB_PHY_CTRL_SET_DATA_ON_LRADC      13
#define BM_USB_PHY_CTRL_SET_DATA_ON_LRADC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_DATA_ON_LRADC(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_CTRL_SET_DATA_ON_LRADC)
#else
#define BF_USB_PHY_CTRL_SET_DATA_ON_LRADC(v)   (((v) << 13) & BM_USB_PHY_CTRL_SET_DATA_ON_LRADC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_ON_LRADC field to a new value.
#define BW_USB_PHY_CTRL_SET_DATA_ON_LRADC(v)   BF_CS1(USB_PHY_CTRL_SET, DATA_ON_LRADC, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENUTMILEVEL2 (RW)
 *
 * Enables UTMI+ Level2. This should be enabled if needs to support LS device
 */

#define BP_USB_PHY_CTRL_SET_ENUTMILEVEL2      14
#define BM_USB_PHY_CTRL_SET_ENUTMILEVEL2      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENUTMILEVEL2(v)   ((((reg32_t) v) << 14) & BM_USB_PHY_CTRL_SET_ENUTMILEVEL2)
#else
#define BF_USB_PHY_CTRL_SET_ENUTMILEVEL2(v)   (((v) << 14) & BM_USB_PHY_CTRL_SET_ENUTMILEVEL2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL2 field to a new value.
#define BW_USB_PHY_CTRL_SET_ENUTMILEVEL2(v)   BF_CS1(USB_PHY_CTRL_SET, ENUTMILEVEL2, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENUTMILEVEL3 (RW)
 *
 * Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device
 * connected
 */

#define BP_USB_PHY_CTRL_SET_ENUTMILEVEL3      15
#define BM_USB_PHY_CTRL_SET_ENUTMILEVEL3      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENUTMILEVEL3(v)   ((((reg32_t) v) << 15) & BM_USB_PHY_CTRL_SET_ENUTMILEVEL3)
#else
#define BF_USB_PHY_CTRL_SET_ENUTMILEVEL3(v)   (((v) << 15) & BM_USB_PHY_CTRL_SET_ENUTMILEVEL3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL3 field to a new value.
#define BW_USB_PHY_CTRL_SET_ENUTMILEVEL3(v)   BF_CS1(USB_PHY_CTRL_SET, ENUTMILEVEL3, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENIRQWAKEUP (RW)
 *
 * Enables interrupt for the wakeup events.
 */

#define BP_USB_PHY_CTRL_SET_ENIRQWAKEUP      16
#define BM_USB_PHY_CTRL_SET_ENIRQWAKEUP      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENIRQWAKEUP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_CTRL_SET_ENIRQWAKEUP)
#else
#define BF_USB_PHY_CTRL_SET_ENIRQWAKEUP(v)   (((v) << 16) & BM_USB_PHY_CTRL_SET_ENIRQWAKEUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQWAKEUP field to a new value.
#define BW_USB_PHY_CTRL_SET_ENIRQWAKEUP(v)   BF_CS1(USB_PHY_CTRL_SET, ENIRQWAKEUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field WAKEUP_IRQ (RW)
 *
 * Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_SET_WAKEUP_IRQ      17
#define BM_USB_PHY_CTRL_SET_WAKEUP_IRQ      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_WAKEUP_IRQ(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_CTRL_SET_WAKEUP_IRQ)
#else
#define BF_USB_PHY_CTRL_SET_WAKEUP_IRQ(v)   (((v) << 17) & BM_USB_PHY_CTRL_SET_WAKEUP_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP_IRQ field to a new value.
#define BW_USB_PHY_CTRL_SET_WAKEUP_IRQ(v)   BF_CS1(USB_PHY_CTRL_SET, WAKEUP_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENAUTOCLR_CLKGATE (RW)
 *
 * Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is
 * suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
 */

#define BP_USB_PHY_CTRL_SET_ENAUTOCLR_CLKGATE      19
#define BM_USB_PHY_CTRL_SET_ENAUTOCLR_CLKGATE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENAUTOCLR_CLKGATE(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_CTRL_SET_ENAUTOCLR_CLKGATE)
#else
#define BF_USB_PHY_CTRL_SET_ENAUTOCLR_CLKGATE(v)   (((v) << 19) & BM_USB_PHY_CTRL_SET_ENAUTOCLR_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_SET_ENAUTOCLR_CLKGATE(v)   BF_CS1(USB_PHY_CTRL_SET, ENAUTOCLR_CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENAUTOCLR_PHY_PWD (RW)
 *
 * Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event
 * while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's
 * interaction.
 */

#define BP_USB_PHY_CTRL_SET_ENAUTOCLR_PHY_PWD      20
#define BM_USB_PHY_CTRL_SET_ENAUTOCLR_PHY_PWD      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENAUTOCLR_PHY_PWD(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_CTRL_SET_ENAUTOCLR_PHY_PWD)
#else
#define BF_USB_PHY_CTRL_SET_ENAUTOCLR_PHY_PWD(v)   (((v) << 20) & BM_USB_PHY_CTRL_SET_ENAUTOCLR_PHY_PWD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_PHY_PWD field to a new value.
#define BW_USB_PHY_CTRL_SET_ENAUTOCLR_PHY_PWD(v)   BF_CS1(USB_PHY_CTRL_SET, ENAUTOCLR_PHY_PWD, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENDPDMCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled
 * by default.
 */

#define BP_USB_PHY_CTRL_SET_ENDPDMCHG_WKUP      21
#define BM_USB_PHY_CTRL_SET_ENDPDMCHG_WKUP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENDPDMCHG_WKUP(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_CTRL_SET_ENDPDMCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_SET_ENDPDMCHG_WKUP(v)   (((v) << 21) & BM_USB_PHY_CTRL_SET_ENDPDMCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDPDMCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_SET_ENDPDMCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_SET, ENDPDMCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENIDCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if ID is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_SET_ENIDCHG_WKUP      22
#define BM_USB_PHY_CTRL_SET_ENIDCHG_WKUP      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENIDCHG_WKUP(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_CTRL_SET_ENIDCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_SET_ENIDCHG_WKUP(v)   (((v) << 22) & BM_USB_PHY_CTRL_SET_ENIDCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIDCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_SET_ENIDCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_SET, ENIDCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field ENVBUSCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_SET_ENVBUSCHG_WKUP      23
#define BM_USB_PHY_CTRL_SET_ENVBUSCHG_WKUP      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_ENVBUSCHG_WKUP(v)   ((((reg32_t) v) << 23) & BM_USB_PHY_CTRL_SET_ENVBUSCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_SET_ENVBUSCHG_WKUP(v)   (((v) << 23) & BM_USB_PHY_CTRL_SET_ENVBUSCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVBUSCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_SET_ENVBUSCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_SET, ENVBUSCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field FSDLL_RST_EN (RW)
 *
 * Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
 */

#define BP_USB_PHY_CTRL_SET_FSDLL_RST_EN      24
#define BM_USB_PHY_CTRL_SET_FSDLL_RST_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_FSDLL_RST_EN(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_CTRL_SET_FSDLL_RST_EN)
#else
#define BF_USB_PHY_CTRL_SET_FSDLL_RST_EN(v)   (((v) << 24) & BM_USB_PHY_CTRL_SET_FSDLL_RST_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FSDLL_RST_EN field to a new value.
#define BW_USB_PHY_CTRL_SET_FSDLL_RST_EN(v)   BF_CS1(USB_PHY_CTRL_SET, FSDLL_RST_EN, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field OTG_ID_VALUE (RO)
 *
 * Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE
 * has debounce logic to filter the glitches on ID Pad.
 */

#define BP_USB_PHY_CTRL_SET_OTG_ID_VALUE      27
#define BM_USB_PHY_CTRL_SET_OTG_ID_VALUE      0x08000000

/* --- Register HW_USB_PHY_CTRL_SET, field HOST_FORCE_LS_SE0 (RW)
 *
 * Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in
 * host mode for the resume sequence. After the packet is transferred, this bit is cleared. The
 * design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger
 * this event when leaving suspend. This bit is used in conjunction with
 * USBPHYx_DEBUG_HOST_RESUME_DEBUG.
 */

#define BP_USB_PHY_CTRL_SET_HOST_FORCE_LS_SE0      28
#define BM_USB_PHY_CTRL_SET_HOST_FORCE_LS_SE0      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_HOST_FORCE_LS_SE0(v)   ((((reg32_t) v) << 28) & BM_USB_PHY_CTRL_SET_HOST_FORCE_LS_SE0)
#else
#define BF_USB_PHY_CTRL_SET_HOST_FORCE_LS_SE0(v)   (((v) << 28) & BM_USB_PHY_CTRL_SET_HOST_FORCE_LS_SE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_FORCE_LS_SE0 field to a new value.
#define BW_USB_PHY_CTRL_SET_HOST_FORCE_LS_SE0(v)   BF_CS1(USB_PHY_CTRL_SET, HOST_FORCE_LS_SE0, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field UTMI_SUSPENDM (RO)
 *
 * Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD
 * are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required
 * by the UTMI specification.
 */

#define BP_USB_PHY_CTRL_SET_UTMI_SUSPENDM      29
#define BM_USB_PHY_CTRL_SET_UTMI_SUSPENDM      0x20000000

/* --- Register HW_USB_PHY_CTRL_SET, field CLKGATE (RW)
 *
 * Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while
 * the USB is not actively being used. Configuration state is kept while the clock is gated. Note
 * this bit can be auto-cleared if there is any wakeup event when USB is suspended while
 * ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_CTRL_SET_CLKGATE      30
#define BM_USB_PHY_CTRL_SET_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_CTRL_SET_CLKGATE)
#else
#define BF_USB_PHY_CTRL_SET_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_CTRL_SET_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_SET_CLKGATE(v)   BF_CS1(USB_PHY_CTRL_SET, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL_SET, field SFTRST (RW)
 *
 * Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL
 * registers. Set to 0 to release the PHY from reset.
 */

#define BP_USB_PHY_CTRL_SET_SFTRST      31
#define BM_USB_PHY_CTRL_SET_SFTRST      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SET_SFTRST(v)   ((((reg32_t) v) << 31) & BM_USB_PHY_CTRL_SET_SFTRST)
#else
#define BF_USB_PHY_CTRL_SET_SFTRST(v)   (((v) << 31) & BM_USB_PHY_CTRL_SET_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_USB_PHY_CTRL_SET_SFTRST(v)   BF_CS1(USB_PHY_CTRL_SET, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_CTRL_CLR - USB PHY General Control Register _CLR (RW)
 *
 * The USB PHY General Control Register handles OTG and Host controls. This register also includes
 * interrupt enables and connectivity detect enables and results.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENOTG_ID_CHG_IRQ : 1; //!< Enable OTG_ID_CHG_IRQ.
        unsigned ENHOSTDISCONDETECT : 1; //!< For host mode, enables high-speed disconnect detector. This signal allows the override of enabling the detection that is normally done in the UTMI controller. The UTMI controller enables this circuit whenever the host sends a start-of-frame packet.
        unsigned ENIRQHOSTDISCON : 1; //!< Enables interrupt for detection of disconnection to Device when in high-speed host mode. This should be enabled after ENDEVPLUGINDETECT is enabled.
        unsigned HOSTDISCONDETECT_IRQ : 1; //!< Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENDEVPLUGINDETECT : 1; //!< For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
        unsigned DEVPLUGIN_POLARITY : 1; //!< For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
        unsigned OTG_ID_CHG_IRQ : 1; //!< OTG ID change interrupt. Indicates the value of ID pin changed.
        unsigned ENOTGIDDETECT : 1; //!< Enables circuit to detect resistance of MiniAB ID pin.
        unsigned RESUMEIRQSTICKY : 1; //!< Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only set during the wake-up period.
        unsigned ENIRQRESUMEDETECT : 1; //!< Enables interrupt for detection of a non-J state on the USB line. This should only be enabled after the device has entered suspend mode.
        unsigned RESUME_IRQ : 1; //!< Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset during suspend. Use this bit to wake up from suspend for either the resume or the reset case. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENIRQDEVPLUGIN : 1; //!< Enables interrupt for the detection of connectivity to the USB line.
        unsigned DEVPLUGIN_IRQ : 1; //!< Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned DATA_ON_LRADC : 1; //!< Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
        unsigned ENUTMILEVEL2 : 1; //!< Enables UTMI+ Level2. This should be enabled if needs to support LS device
        unsigned ENUTMILEVEL3 : 1; //!< Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device connected
        unsigned ENIRQWAKEUP : 1; //!< Enables interrupt for the wakeup events.
        unsigned WAKEUP_IRQ : 1; //!< Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned ENAUTOCLR_CLKGATE : 1; //!< Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENAUTOCLR_PHY_PWD : 1; //!< Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENDPDMCHG_WKUP : 1; //!< Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled by default.
        unsigned ENIDCHG_WKUP : 1; //!< Enables the feature to wakeup USB if ID is toggled when USB is suspended.
        unsigned ENVBUSCHG_WKUP : 1; //!< Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
        unsigned FSDLL_RST_EN : 1; //!< Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
        unsigned RESERVED1 : 2; //!< Reserved.
        unsigned OTG_ID_VALUE : 1; //!< Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE has debounce logic to filter the glitches on ID Pad.
        unsigned HOST_FORCE_LS_SE0 : 1; //!< Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in host mode for the resume sequence. After the packet is transferred, this bit is cleared. The design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger this event when leaving suspend. This bit is used in conjunction with USBPHYx_DEBUG_HOST_RESUME_DEBUG.
        unsigned UTMI_SUSPENDM : 1; //!< Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required by the UTMI specification.
        unsigned CLKGATE : 1; //!< Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated. Note this bit can be auto-cleared if there is any wakeup event when USB is suspended while ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
        unsigned SFTRST : 1; //!< Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers. Set to 0 to release the PHY from reset.
    } B;
} hw_usb_phy_ctrl_clr_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_CTRL_CLR register
 */
#define HW_USB_PHY_CTRL_CLR_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_CTRL_CLR(x)           (*(volatile hw_usb_phy_ctrl_clr_t *) HW_USB_PHY_CTRL_CLR_ADDR(x))
#define HW_USB_PHY_CTRL_CLR_RD(x)        (HW_USB_PHY_CTRL_CLR(x).U)
#define HW_USB_PHY_CTRL_CLR_WR(x, v)     (HW_USB_PHY_CTRL_CLR(x).U = (v))
#define HW_USB_PHY_CTRL_CLR_SET(x, v)    (HW_USB_PHY_CTRL_CLR_WR(x, HW_USB_PHY_CTRL_CLR_RD(x) |  (v)))
#define HW_USB_PHY_CTRL_CLR_CLR(x, v)    (HW_USB_PHY_CTRL_CLR_WR(x, HW_USB_PHY_CTRL_CLR_RD(x) & ~(v)))
#define HW_USB_PHY_CTRL_CLR_TOG(x, v)    (HW_USB_PHY_CTRL_CLR_WR(x, HW_USB_PHY_CTRL_CLR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_CTRL_CLR bitfields
 */

/* --- Register HW_USB_PHY_CTRL_CLR, field ENOTG_ID_CHG_IRQ (RW)
 *
 * Enable OTG_ID_CHG_IRQ.
 */

#define BP_USB_PHY_CTRL_CLR_ENOTG_ID_CHG_IRQ      0
#define BM_USB_PHY_CTRL_CLR_ENOTG_ID_CHG_IRQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENOTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_CTRL_CLR_ENOTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_CLR_ENOTG_ID_CHG_IRQ(v)   (((v) << 0) & BM_USB_PHY_CTRL_CLR_ENOTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENOTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL_CLR, ENOTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENHOSTDISCONDETECT (RW)
 *
 * For host mode, enables high-speed disconnect detector. This signal allows the override of
 * enabling the detection that is normally done in the UTMI controller. The UTMI controller enables
 * this circuit whenever the host sends a start-of-frame packet.
 */

#define BP_USB_PHY_CTRL_CLR_ENHOSTDISCONDETECT      1
#define BM_USB_PHY_CTRL_CLR_ENHOSTDISCONDETECT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENHOSTDISCONDETECT(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_CTRL_CLR_ENHOSTDISCONDETECT)
#else
#define BF_USB_PHY_CTRL_CLR_ENHOSTDISCONDETECT(v)   (((v) << 1) & BM_USB_PHY_CTRL_CLR_ENHOSTDISCONDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHOSTDISCONDETECT field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENHOSTDISCONDETECT(v)   BF_CS1(USB_PHY_CTRL_CLR, ENHOSTDISCONDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENIRQHOSTDISCON (RW)
 *
 * Enables interrupt for detection of disconnection to Device when in high-speed host mode. This
 * should be enabled after ENDEVPLUGINDETECT is enabled.
 */

#define BP_USB_PHY_CTRL_CLR_ENIRQHOSTDISCON      2
#define BM_USB_PHY_CTRL_CLR_ENIRQHOSTDISCON      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENIRQHOSTDISCON(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_CTRL_CLR_ENIRQHOSTDISCON)
#else
#define BF_USB_PHY_CTRL_CLR_ENIRQHOSTDISCON(v)   (((v) << 2) & BM_USB_PHY_CTRL_CLR_ENIRQHOSTDISCON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQHOSTDISCON field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENIRQHOSTDISCON(v)   BF_CS1(USB_PHY_CTRL_CLR, ENIRQHOSTDISCON, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field HOSTDISCONDETECT_IRQ (RW)
 *
 * Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to
 * the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_CLR_HOSTDISCONDETECT_IRQ      3
#define BM_USB_PHY_CTRL_CLR_HOSTDISCONDETECT_IRQ      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_HOSTDISCONDETECT_IRQ(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_CTRL_CLR_HOSTDISCONDETECT_IRQ)
#else
#define BF_USB_PHY_CTRL_CLR_HOSTDISCONDETECT_IRQ(v)   (((v) << 3) & BM_USB_PHY_CTRL_CLR_HOSTDISCONDETECT_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOSTDISCONDETECT_IRQ field to a new value.
#define BW_USB_PHY_CTRL_CLR_HOSTDISCONDETECT_IRQ(v)   BF_CS1(USB_PHY_CTRL_CLR, HOSTDISCONDETECT_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENDEVPLUGINDETECT (RW)
 *
 * For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
 */

#define BP_USB_PHY_CTRL_CLR_ENDEVPLUGINDETECT      4
#define BM_USB_PHY_CTRL_CLR_ENDEVPLUGINDETECT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENDEVPLUGINDETECT(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_CTRL_CLR_ENDEVPLUGINDETECT)
#else
#define BF_USB_PHY_CTRL_CLR_ENDEVPLUGINDETECT(v)   (((v) << 4) & BM_USB_PHY_CTRL_CLR_ENDEVPLUGINDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDEVPLUGINDETECT field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENDEVPLUGINDETECT(v)   BF_CS1(USB_PHY_CTRL_CLR, ENDEVPLUGINDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field DEVPLUGIN_POLARITY (RW)
 *
 * For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is
 * plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
 */

#define BP_USB_PHY_CTRL_CLR_DEVPLUGIN_POLARITY      5
#define BM_USB_PHY_CTRL_CLR_DEVPLUGIN_POLARITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_DEVPLUGIN_POLARITY(v)   ((((reg32_t) v) << 5) & BM_USB_PHY_CTRL_CLR_DEVPLUGIN_POLARITY)
#else
#define BF_USB_PHY_CTRL_CLR_DEVPLUGIN_POLARITY(v)   (((v) << 5) & BM_USB_PHY_CTRL_CLR_DEVPLUGIN_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_POLARITY field to a new value.
#define BW_USB_PHY_CTRL_CLR_DEVPLUGIN_POLARITY(v)   BF_CS1(USB_PHY_CTRL_CLR, DEVPLUGIN_POLARITY, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field OTG_ID_CHG_IRQ (RW)
 *
 * OTG ID change interrupt. Indicates the value of ID pin changed.
 */

#define BP_USB_PHY_CTRL_CLR_OTG_ID_CHG_IRQ      6
#define BM_USB_PHY_CTRL_CLR_OTG_ID_CHG_IRQ      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_OTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_CTRL_CLR_OTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_CLR_OTG_ID_CHG_IRQ(v)   (((v) << 6) & BM_USB_PHY_CTRL_CLR_OTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_CLR_OTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL_CLR, OTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENOTGIDDETECT (RW)
 *
 * Enables circuit to detect resistance of MiniAB ID pin.
 */

#define BP_USB_PHY_CTRL_CLR_ENOTGIDDETECT      7
#define BM_USB_PHY_CTRL_CLR_ENOTGIDDETECT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENOTGIDDETECT(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_CTRL_CLR_ENOTGIDDETECT)
#else
#define BF_USB_PHY_CTRL_CLR_ENOTGIDDETECT(v)   (((v) << 7) & BM_USB_PHY_CTRL_CLR_ENOTGIDDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTGIDDETECT field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENOTGIDDETECT(v)   BF_CS1(USB_PHY_CTRL_CLR, ENOTGIDDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field RESUMEIRQSTICKY (RW)
 *
 * Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only
 * set during the wake-up period.
 */

#define BP_USB_PHY_CTRL_CLR_RESUMEIRQSTICKY      8
#define BM_USB_PHY_CTRL_CLR_RESUMEIRQSTICKY      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_RESUMEIRQSTICKY(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_CTRL_CLR_RESUMEIRQSTICKY)
#else
#define BF_USB_PHY_CTRL_CLR_RESUMEIRQSTICKY(v)   (((v) << 8) & BM_USB_PHY_CTRL_CLR_RESUMEIRQSTICKY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUMEIRQSTICKY field to a new value.
#define BW_USB_PHY_CTRL_CLR_RESUMEIRQSTICKY(v)   BF_CS1(USB_PHY_CTRL_CLR, RESUMEIRQSTICKY, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENIRQRESUMEDETECT (RW)
 *
 * Enables interrupt for detection of a non-J state on the USB line. This should only be enabled
 * after the device has entered suspend mode.
 */

#define BP_USB_PHY_CTRL_CLR_ENIRQRESUMEDETECT      9
#define BM_USB_PHY_CTRL_CLR_ENIRQRESUMEDETECT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENIRQRESUMEDETECT(v)   ((((reg32_t) v) << 9) & BM_USB_PHY_CTRL_CLR_ENIRQRESUMEDETECT)
#else
#define BF_USB_PHY_CTRL_CLR_ENIRQRESUMEDETECT(v)   (((v) << 9) & BM_USB_PHY_CTRL_CLR_ENIRQRESUMEDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQRESUMEDETECT field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENIRQRESUMEDETECT(v)   BF_CS1(USB_PHY_CTRL_CLR, ENIRQRESUMEDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field RESUME_IRQ (RW)
 *
 * Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset
 * during suspend. Use this bit to wake up from suspend for either the resume or the reset case.
 * Reset this bit by writing a 1 to the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_CLR_RESUME_IRQ      10
#define BM_USB_PHY_CTRL_CLR_RESUME_IRQ      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_RESUME_IRQ(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_CTRL_CLR_RESUME_IRQ)
#else
#define BF_USB_PHY_CTRL_CLR_RESUME_IRQ(v)   (((v) << 10) & BM_USB_PHY_CTRL_CLR_RESUME_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUME_IRQ field to a new value.
#define BW_USB_PHY_CTRL_CLR_RESUME_IRQ(v)   BF_CS1(USB_PHY_CTRL_CLR, RESUME_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENIRQDEVPLUGIN (RW)
 *
 * Enables interrupt for the detection of connectivity to the USB line.
 */

#define BP_USB_PHY_CTRL_CLR_ENIRQDEVPLUGIN      11
#define BM_USB_PHY_CTRL_CLR_ENIRQDEVPLUGIN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENIRQDEVPLUGIN(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_CTRL_CLR_ENIRQDEVPLUGIN)
#else
#define BF_USB_PHY_CTRL_CLR_ENIRQDEVPLUGIN(v)   (((v) << 11) & BM_USB_PHY_CTRL_CLR_ENIRQDEVPLUGIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQDEVPLUGIN field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENIRQDEVPLUGIN(v)   BF_CS1(USB_PHY_CTRL_CLR, ENIRQDEVPLUGIN, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field DEVPLUGIN_IRQ (RW)
 *
 * Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_CLR_DEVPLUGIN_IRQ      12
#define BM_USB_PHY_CTRL_CLR_DEVPLUGIN_IRQ      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_DEVPLUGIN_IRQ(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_CTRL_CLR_DEVPLUGIN_IRQ)
#else
#define BF_USB_PHY_CTRL_CLR_DEVPLUGIN_IRQ(v)   (((v) << 12) & BM_USB_PHY_CTRL_CLR_DEVPLUGIN_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_IRQ field to a new value.
#define BW_USB_PHY_CTRL_CLR_DEVPLUGIN_IRQ(v)   BF_CS1(USB_PHY_CTRL_CLR, DEVPLUGIN_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field DATA_ON_LRADC (RW)
 *
 * Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
 */

#define BP_USB_PHY_CTRL_CLR_DATA_ON_LRADC      13
#define BM_USB_PHY_CTRL_CLR_DATA_ON_LRADC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_DATA_ON_LRADC(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_CTRL_CLR_DATA_ON_LRADC)
#else
#define BF_USB_PHY_CTRL_CLR_DATA_ON_LRADC(v)   (((v) << 13) & BM_USB_PHY_CTRL_CLR_DATA_ON_LRADC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_ON_LRADC field to a new value.
#define BW_USB_PHY_CTRL_CLR_DATA_ON_LRADC(v)   BF_CS1(USB_PHY_CTRL_CLR, DATA_ON_LRADC, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENUTMILEVEL2 (RW)
 *
 * Enables UTMI+ Level2. This should be enabled if needs to support LS device
 */

#define BP_USB_PHY_CTRL_CLR_ENUTMILEVEL2      14
#define BM_USB_PHY_CTRL_CLR_ENUTMILEVEL2      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENUTMILEVEL2(v)   ((((reg32_t) v) << 14) & BM_USB_PHY_CTRL_CLR_ENUTMILEVEL2)
#else
#define BF_USB_PHY_CTRL_CLR_ENUTMILEVEL2(v)   (((v) << 14) & BM_USB_PHY_CTRL_CLR_ENUTMILEVEL2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL2 field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENUTMILEVEL2(v)   BF_CS1(USB_PHY_CTRL_CLR, ENUTMILEVEL2, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENUTMILEVEL3 (RW)
 *
 * Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device
 * connected
 */

#define BP_USB_PHY_CTRL_CLR_ENUTMILEVEL3      15
#define BM_USB_PHY_CTRL_CLR_ENUTMILEVEL3      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENUTMILEVEL3(v)   ((((reg32_t) v) << 15) & BM_USB_PHY_CTRL_CLR_ENUTMILEVEL3)
#else
#define BF_USB_PHY_CTRL_CLR_ENUTMILEVEL3(v)   (((v) << 15) & BM_USB_PHY_CTRL_CLR_ENUTMILEVEL3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL3 field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENUTMILEVEL3(v)   BF_CS1(USB_PHY_CTRL_CLR, ENUTMILEVEL3, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENIRQWAKEUP (RW)
 *
 * Enables interrupt for the wakeup events.
 */

#define BP_USB_PHY_CTRL_CLR_ENIRQWAKEUP      16
#define BM_USB_PHY_CTRL_CLR_ENIRQWAKEUP      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENIRQWAKEUP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_CTRL_CLR_ENIRQWAKEUP)
#else
#define BF_USB_PHY_CTRL_CLR_ENIRQWAKEUP(v)   (((v) << 16) & BM_USB_PHY_CTRL_CLR_ENIRQWAKEUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQWAKEUP field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENIRQWAKEUP(v)   BF_CS1(USB_PHY_CTRL_CLR, ENIRQWAKEUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field WAKEUP_IRQ (RW)
 *
 * Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_CLR_WAKEUP_IRQ      17
#define BM_USB_PHY_CTRL_CLR_WAKEUP_IRQ      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_WAKEUP_IRQ(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_CTRL_CLR_WAKEUP_IRQ)
#else
#define BF_USB_PHY_CTRL_CLR_WAKEUP_IRQ(v)   (((v) << 17) & BM_USB_PHY_CTRL_CLR_WAKEUP_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP_IRQ field to a new value.
#define BW_USB_PHY_CTRL_CLR_WAKEUP_IRQ(v)   BF_CS1(USB_PHY_CTRL_CLR, WAKEUP_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENAUTOCLR_CLKGATE (RW)
 *
 * Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is
 * suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
 */

#define BP_USB_PHY_CTRL_CLR_ENAUTOCLR_CLKGATE      19
#define BM_USB_PHY_CTRL_CLR_ENAUTOCLR_CLKGATE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENAUTOCLR_CLKGATE(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_CTRL_CLR_ENAUTOCLR_CLKGATE)
#else
#define BF_USB_PHY_CTRL_CLR_ENAUTOCLR_CLKGATE(v)   (((v) << 19) & BM_USB_PHY_CTRL_CLR_ENAUTOCLR_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENAUTOCLR_CLKGATE(v)   BF_CS1(USB_PHY_CTRL_CLR, ENAUTOCLR_CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENAUTOCLR_PHY_PWD (RW)
 *
 * Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event
 * while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's
 * interaction.
 */

#define BP_USB_PHY_CTRL_CLR_ENAUTOCLR_PHY_PWD      20
#define BM_USB_PHY_CTRL_CLR_ENAUTOCLR_PHY_PWD      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENAUTOCLR_PHY_PWD(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_CTRL_CLR_ENAUTOCLR_PHY_PWD)
#else
#define BF_USB_PHY_CTRL_CLR_ENAUTOCLR_PHY_PWD(v)   (((v) << 20) & BM_USB_PHY_CTRL_CLR_ENAUTOCLR_PHY_PWD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_PHY_PWD field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENAUTOCLR_PHY_PWD(v)   BF_CS1(USB_PHY_CTRL_CLR, ENAUTOCLR_PHY_PWD, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENDPDMCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled
 * by default.
 */

#define BP_USB_PHY_CTRL_CLR_ENDPDMCHG_WKUP      21
#define BM_USB_PHY_CTRL_CLR_ENDPDMCHG_WKUP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENDPDMCHG_WKUP(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_CTRL_CLR_ENDPDMCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_CLR_ENDPDMCHG_WKUP(v)   (((v) << 21) & BM_USB_PHY_CTRL_CLR_ENDPDMCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDPDMCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENDPDMCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_CLR, ENDPDMCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENIDCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if ID is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_CLR_ENIDCHG_WKUP      22
#define BM_USB_PHY_CTRL_CLR_ENIDCHG_WKUP      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENIDCHG_WKUP(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_CTRL_CLR_ENIDCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_CLR_ENIDCHG_WKUP(v)   (((v) << 22) & BM_USB_PHY_CTRL_CLR_ENIDCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIDCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENIDCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_CLR, ENIDCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field ENVBUSCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_CLR_ENVBUSCHG_WKUP      23
#define BM_USB_PHY_CTRL_CLR_ENVBUSCHG_WKUP      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_ENVBUSCHG_WKUP(v)   ((((reg32_t) v) << 23) & BM_USB_PHY_CTRL_CLR_ENVBUSCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_CLR_ENVBUSCHG_WKUP(v)   (((v) << 23) & BM_USB_PHY_CTRL_CLR_ENVBUSCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVBUSCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_CLR_ENVBUSCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_CLR, ENVBUSCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field FSDLL_RST_EN (RW)
 *
 * Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
 */

#define BP_USB_PHY_CTRL_CLR_FSDLL_RST_EN      24
#define BM_USB_PHY_CTRL_CLR_FSDLL_RST_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_FSDLL_RST_EN(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_CTRL_CLR_FSDLL_RST_EN)
#else
#define BF_USB_PHY_CTRL_CLR_FSDLL_RST_EN(v)   (((v) << 24) & BM_USB_PHY_CTRL_CLR_FSDLL_RST_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FSDLL_RST_EN field to a new value.
#define BW_USB_PHY_CTRL_CLR_FSDLL_RST_EN(v)   BF_CS1(USB_PHY_CTRL_CLR, FSDLL_RST_EN, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field OTG_ID_VALUE (RO)
 *
 * Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE
 * has debounce logic to filter the glitches on ID Pad.
 */

#define BP_USB_PHY_CTRL_CLR_OTG_ID_VALUE      27
#define BM_USB_PHY_CTRL_CLR_OTG_ID_VALUE      0x08000000

/* --- Register HW_USB_PHY_CTRL_CLR, field HOST_FORCE_LS_SE0 (RW)
 *
 * Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in
 * host mode for the resume sequence. After the packet is transferred, this bit is cleared. The
 * design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger
 * this event when leaving suspend. This bit is used in conjunction with
 * USBPHYx_DEBUG_HOST_RESUME_DEBUG.
 */

#define BP_USB_PHY_CTRL_CLR_HOST_FORCE_LS_SE0      28
#define BM_USB_PHY_CTRL_CLR_HOST_FORCE_LS_SE0      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_HOST_FORCE_LS_SE0(v)   ((((reg32_t) v) << 28) & BM_USB_PHY_CTRL_CLR_HOST_FORCE_LS_SE0)
#else
#define BF_USB_PHY_CTRL_CLR_HOST_FORCE_LS_SE0(v)   (((v) << 28) & BM_USB_PHY_CTRL_CLR_HOST_FORCE_LS_SE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_FORCE_LS_SE0 field to a new value.
#define BW_USB_PHY_CTRL_CLR_HOST_FORCE_LS_SE0(v)   BF_CS1(USB_PHY_CTRL_CLR, HOST_FORCE_LS_SE0, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field UTMI_SUSPENDM (RO)
 *
 * Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD
 * are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required
 * by the UTMI specification.
 */

#define BP_USB_PHY_CTRL_CLR_UTMI_SUSPENDM      29
#define BM_USB_PHY_CTRL_CLR_UTMI_SUSPENDM      0x20000000

/* --- Register HW_USB_PHY_CTRL_CLR, field CLKGATE (RW)
 *
 * Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while
 * the USB is not actively being used. Configuration state is kept while the clock is gated. Note
 * this bit can be auto-cleared if there is any wakeup event when USB is suspended while
 * ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_CTRL_CLR_CLKGATE      30
#define BM_USB_PHY_CTRL_CLR_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_CTRL_CLR_CLKGATE)
#else
#define BF_USB_PHY_CTRL_CLR_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_CTRL_CLR_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_CLR_CLKGATE(v)   BF_CS1(USB_PHY_CTRL_CLR, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL_CLR, field SFTRST (RW)
 *
 * Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL
 * registers. Set to 0 to release the PHY from reset.
 */

#define BP_USB_PHY_CTRL_CLR_SFTRST      31
#define BM_USB_PHY_CTRL_CLR_SFTRST      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLR_SFTRST(v)   ((((reg32_t) v) << 31) & BM_USB_PHY_CTRL_CLR_SFTRST)
#else
#define BF_USB_PHY_CTRL_CLR_SFTRST(v)   (((v) << 31) & BM_USB_PHY_CTRL_CLR_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_USB_PHY_CTRL_CLR_SFTRST(v)   BF_CS1(USB_PHY_CTRL_CLR, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_CTRL_TOG - USB PHY General Control Register _TOG (RW)
 *
 * The USB PHY General Control Register handles OTG and Host controls. This register also includes
 * interrupt enables and connectivity detect enables and results.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENOTG_ID_CHG_IRQ : 1; //!< Enable OTG_ID_CHG_IRQ.
        unsigned ENHOSTDISCONDETECT : 1; //!< For host mode, enables high-speed disconnect detector. This signal allows the override of enabling the detection that is normally done in the UTMI controller. The UTMI controller enables this circuit whenever the host sends a start-of-frame packet.
        unsigned ENIRQHOSTDISCON : 1; //!< Enables interrupt for detection of disconnection to Device when in high-speed host mode. This should be enabled after ENDEVPLUGINDETECT is enabled.
        unsigned HOSTDISCONDETECT_IRQ : 1; //!< Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENDEVPLUGINDETECT : 1; //!< For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
        unsigned DEVPLUGIN_POLARITY : 1; //!< For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
        unsigned OTG_ID_CHG_IRQ : 1; //!< OTG ID change interrupt. Indicates the value of ID pin changed.
        unsigned ENOTGIDDETECT : 1; //!< Enables circuit to detect resistance of MiniAB ID pin.
        unsigned RESUMEIRQSTICKY : 1; //!< Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only set during the wake-up period.
        unsigned ENIRQRESUMEDETECT : 1; //!< Enables interrupt for detection of a non-J state on the USB line. This should only be enabled after the device has entered suspend mode.
        unsigned RESUME_IRQ : 1; //!< Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset during suspend. Use this bit to wake up from suspend for either the resume or the reset case. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENIRQDEVPLUGIN : 1; //!< Enables interrupt for the detection of connectivity to the USB line.
        unsigned DEVPLUGIN_IRQ : 1; //!< Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned DATA_ON_LRADC : 1; //!< Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
        unsigned ENUTMILEVEL2 : 1; //!< Enables UTMI+ Level2. This should be enabled if needs to support LS device
        unsigned ENUTMILEVEL3 : 1; //!< Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device connected
        unsigned ENIRQWAKEUP : 1; //!< Enables interrupt for the wakeup events.
        unsigned WAKEUP_IRQ : 1; //!< Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned ENAUTOCLR_CLKGATE : 1; //!< Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENAUTOCLR_PHY_PWD : 1; //!< Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENDPDMCHG_WKUP : 1; //!< Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled by default.
        unsigned ENIDCHG_WKUP : 1; //!< Enables the feature to wakeup USB if ID is toggled when USB is suspended.
        unsigned ENVBUSCHG_WKUP : 1; //!< Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
        unsigned FSDLL_RST_EN : 1; //!< Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
        unsigned RESERVED1 : 2; //!< Reserved.
        unsigned OTG_ID_VALUE : 1; //!< Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE has debounce logic to filter the glitches on ID Pad.
        unsigned HOST_FORCE_LS_SE0 : 1; //!< Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in host mode for the resume sequence. After the packet is transferred, this bit is cleared. The design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger this event when leaving suspend. This bit is used in conjunction with USBPHYx_DEBUG_HOST_RESUME_DEBUG.
        unsigned UTMI_SUSPENDM : 1; //!< Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required by the UTMI specification.
        unsigned CLKGATE : 1; //!< Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated. Note this bit can be auto-cleared if there is any wakeup event when USB is suspended while ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
        unsigned SFTRST : 1; //!< Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers. Set to 0 to release the PHY from reset.
    } B;
} hw_usb_phy_ctrl_tog_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_CTRL_TOG register
 */
#define HW_USB_PHY_CTRL_TOG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_CTRL_TOG(x)           (*(volatile hw_usb_phy_ctrl_tog_t *) HW_USB_PHY_CTRL_TOG_ADDR(x))
#define HW_USB_PHY_CTRL_TOG_RD(x)        (HW_USB_PHY_CTRL_TOG(x).U)
#define HW_USB_PHY_CTRL_TOG_WR(x, v)     (HW_USB_PHY_CTRL_TOG(x).U = (v))
#define HW_USB_PHY_CTRL_TOG_SET(x, v)    (HW_USB_PHY_CTRL_TOG_WR(x, HW_USB_PHY_CTRL_TOG_RD(x) |  (v)))
#define HW_USB_PHY_CTRL_TOG_CLR(x, v)    (HW_USB_PHY_CTRL_TOG_WR(x, HW_USB_PHY_CTRL_TOG_RD(x) & ~(v)))
#define HW_USB_PHY_CTRL_TOG_TOG(x, v)    (HW_USB_PHY_CTRL_TOG_WR(x, HW_USB_PHY_CTRL_TOG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_CTRL_TOG bitfields
 */

/* --- Register HW_USB_PHY_CTRL_TOG, field ENOTG_ID_CHG_IRQ (RW)
 *
 * Enable OTG_ID_CHG_IRQ.
 */

#define BP_USB_PHY_CTRL_TOG_ENOTG_ID_CHG_IRQ      0
#define BM_USB_PHY_CTRL_TOG_ENOTG_ID_CHG_IRQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENOTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_CTRL_TOG_ENOTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_TOG_ENOTG_ID_CHG_IRQ(v)   (((v) << 0) & BM_USB_PHY_CTRL_TOG_ENOTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENOTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL_TOG, ENOTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENHOSTDISCONDETECT (RW)
 *
 * For host mode, enables high-speed disconnect detector. This signal allows the override of
 * enabling the detection that is normally done in the UTMI controller. The UTMI controller enables
 * this circuit whenever the host sends a start-of-frame packet.
 */

#define BP_USB_PHY_CTRL_TOG_ENHOSTDISCONDETECT      1
#define BM_USB_PHY_CTRL_TOG_ENHOSTDISCONDETECT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENHOSTDISCONDETECT(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_CTRL_TOG_ENHOSTDISCONDETECT)
#else
#define BF_USB_PHY_CTRL_TOG_ENHOSTDISCONDETECT(v)   (((v) << 1) & BM_USB_PHY_CTRL_TOG_ENHOSTDISCONDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHOSTDISCONDETECT field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENHOSTDISCONDETECT(v)   BF_CS1(USB_PHY_CTRL_TOG, ENHOSTDISCONDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENIRQHOSTDISCON (RW)
 *
 * Enables interrupt for detection of disconnection to Device when in high-speed host mode. This
 * should be enabled after ENDEVPLUGINDETECT is enabled.
 */

#define BP_USB_PHY_CTRL_TOG_ENIRQHOSTDISCON      2
#define BM_USB_PHY_CTRL_TOG_ENIRQHOSTDISCON      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENIRQHOSTDISCON(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_CTRL_TOG_ENIRQHOSTDISCON)
#else
#define BF_USB_PHY_CTRL_TOG_ENIRQHOSTDISCON(v)   (((v) << 2) & BM_USB_PHY_CTRL_TOG_ENIRQHOSTDISCON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQHOSTDISCON field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENIRQHOSTDISCON(v)   BF_CS1(USB_PHY_CTRL_TOG, ENIRQHOSTDISCON, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field HOSTDISCONDETECT_IRQ (RW)
 *
 * Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to
 * the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_TOG_HOSTDISCONDETECT_IRQ      3
#define BM_USB_PHY_CTRL_TOG_HOSTDISCONDETECT_IRQ      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_HOSTDISCONDETECT_IRQ(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_CTRL_TOG_HOSTDISCONDETECT_IRQ)
#else
#define BF_USB_PHY_CTRL_TOG_HOSTDISCONDETECT_IRQ(v)   (((v) << 3) & BM_USB_PHY_CTRL_TOG_HOSTDISCONDETECT_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOSTDISCONDETECT_IRQ field to a new value.
#define BW_USB_PHY_CTRL_TOG_HOSTDISCONDETECT_IRQ(v)   BF_CS1(USB_PHY_CTRL_TOG, HOSTDISCONDETECT_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENDEVPLUGINDETECT (RW)
 *
 * For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
 */

#define BP_USB_PHY_CTRL_TOG_ENDEVPLUGINDETECT      4
#define BM_USB_PHY_CTRL_TOG_ENDEVPLUGINDETECT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENDEVPLUGINDETECT(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_CTRL_TOG_ENDEVPLUGINDETECT)
#else
#define BF_USB_PHY_CTRL_TOG_ENDEVPLUGINDETECT(v)   (((v) << 4) & BM_USB_PHY_CTRL_TOG_ENDEVPLUGINDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDEVPLUGINDETECT field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENDEVPLUGINDETECT(v)   BF_CS1(USB_PHY_CTRL_TOG, ENDEVPLUGINDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field DEVPLUGIN_POLARITY (RW)
 *
 * For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is
 * plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
 */

#define BP_USB_PHY_CTRL_TOG_DEVPLUGIN_POLARITY      5
#define BM_USB_PHY_CTRL_TOG_DEVPLUGIN_POLARITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_DEVPLUGIN_POLARITY(v)   ((((reg32_t) v) << 5) & BM_USB_PHY_CTRL_TOG_DEVPLUGIN_POLARITY)
#else
#define BF_USB_PHY_CTRL_TOG_DEVPLUGIN_POLARITY(v)   (((v) << 5) & BM_USB_PHY_CTRL_TOG_DEVPLUGIN_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_POLARITY field to a new value.
#define BW_USB_PHY_CTRL_TOG_DEVPLUGIN_POLARITY(v)   BF_CS1(USB_PHY_CTRL_TOG, DEVPLUGIN_POLARITY, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field OTG_ID_CHG_IRQ (RW)
 *
 * OTG ID change interrupt. Indicates the value of ID pin changed.
 */

#define BP_USB_PHY_CTRL_TOG_OTG_ID_CHG_IRQ      6
#define BM_USB_PHY_CTRL_TOG_OTG_ID_CHG_IRQ      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_OTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_CTRL_TOG_OTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_TOG_OTG_ID_CHG_IRQ(v)   (((v) << 6) & BM_USB_PHY_CTRL_TOG_OTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_TOG_OTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL_TOG, OTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENOTGIDDETECT (RW)
 *
 * Enables circuit to detect resistance of MiniAB ID pin.
 */

#define BP_USB_PHY_CTRL_TOG_ENOTGIDDETECT      7
#define BM_USB_PHY_CTRL_TOG_ENOTGIDDETECT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENOTGIDDETECT(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_CTRL_TOG_ENOTGIDDETECT)
#else
#define BF_USB_PHY_CTRL_TOG_ENOTGIDDETECT(v)   (((v) << 7) & BM_USB_PHY_CTRL_TOG_ENOTGIDDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTGIDDETECT field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENOTGIDDETECT(v)   BF_CS1(USB_PHY_CTRL_TOG, ENOTGIDDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field RESUMEIRQSTICKY (RW)
 *
 * Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only
 * set during the wake-up period.
 */

#define BP_USB_PHY_CTRL_TOG_RESUMEIRQSTICKY      8
#define BM_USB_PHY_CTRL_TOG_RESUMEIRQSTICKY      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_RESUMEIRQSTICKY(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_CTRL_TOG_RESUMEIRQSTICKY)
#else
#define BF_USB_PHY_CTRL_TOG_RESUMEIRQSTICKY(v)   (((v) << 8) & BM_USB_PHY_CTRL_TOG_RESUMEIRQSTICKY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUMEIRQSTICKY field to a new value.
#define BW_USB_PHY_CTRL_TOG_RESUMEIRQSTICKY(v)   BF_CS1(USB_PHY_CTRL_TOG, RESUMEIRQSTICKY, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENIRQRESUMEDETECT (RW)
 *
 * Enables interrupt for detection of a non-J state on the USB line. This should only be enabled
 * after the device has entered suspend mode.
 */

#define BP_USB_PHY_CTRL_TOG_ENIRQRESUMEDETECT      9
#define BM_USB_PHY_CTRL_TOG_ENIRQRESUMEDETECT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENIRQRESUMEDETECT(v)   ((((reg32_t) v) << 9) & BM_USB_PHY_CTRL_TOG_ENIRQRESUMEDETECT)
#else
#define BF_USB_PHY_CTRL_TOG_ENIRQRESUMEDETECT(v)   (((v) << 9) & BM_USB_PHY_CTRL_TOG_ENIRQRESUMEDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQRESUMEDETECT field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENIRQRESUMEDETECT(v)   BF_CS1(USB_PHY_CTRL_TOG, ENIRQRESUMEDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field RESUME_IRQ (RW)
 *
 * Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset
 * during suspend. Use this bit to wake up from suspend for either the resume or the reset case.
 * Reset this bit by writing a 1 to the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_TOG_RESUME_IRQ      10
#define BM_USB_PHY_CTRL_TOG_RESUME_IRQ      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_RESUME_IRQ(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_CTRL_TOG_RESUME_IRQ)
#else
#define BF_USB_PHY_CTRL_TOG_RESUME_IRQ(v)   (((v) << 10) & BM_USB_PHY_CTRL_TOG_RESUME_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUME_IRQ field to a new value.
#define BW_USB_PHY_CTRL_TOG_RESUME_IRQ(v)   BF_CS1(USB_PHY_CTRL_TOG, RESUME_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENIRQDEVPLUGIN (RW)
 *
 * Enables interrupt for the detection of connectivity to the USB line.
 */

#define BP_USB_PHY_CTRL_TOG_ENIRQDEVPLUGIN      11
#define BM_USB_PHY_CTRL_TOG_ENIRQDEVPLUGIN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENIRQDEVPLUGIN(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_CTRL_TOG_ENIRQDEVPLUGIN)
#else
#define BF_USB_PHY_CTRL_TOG_ENIRQDEVPLUGIN(v)   (((v) << 11) & BM_USB_PHY_CTRL_TOG_ENIRQDEVPLUGIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQDEVPLUGIN field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENIRQDEVPLUGIN(v)   BF_CS1(USB_PHY_CTRL_TOG, ENIRQDEVPLUGIN, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field DEVPLUGIN_IRQ (RW)
 *
 * Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_TOG_DEVPLUGIN_IRQ      12
#define BM_USB_PHY_CTRL_TOG_DEVPLUGIN_IRQ      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_DEVPLUGIN_IRQ(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_CTRL_TOG_DEVPLUGIN_IRQ)
#else
#define BF_USB_PHY_CTRL_TOG_DEVPLUGIN_IRQ(v)   (((v) << 12) & BM_USB_PHY_CTRL_TOG_DEVPLUGIN_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_IRQ field to a new value.
#define BW_USB_PHY_CTRL_TOG_DEVPLUGIN_IRQ(v)   BF_CS1(USB_PHY_CTRL_TOG, DEVPLUGIN_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field DATA_ON_LRADC (RW)
 *
 * Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
 */

#define BP_USB_PHY_CTRL_TOG_DATA_ON_LRADC      13
#define BM_USB_PHY_CTRL_TOG_DATA_ON_LRADC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_DATA_ON_LRADC(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_CTRL_TOG_DATA_ON_LRADC)
#else
#define BF_USB_PHY_CTRL_TOG_DATA_ON_LRADC(v)   (((v) << 13) & BM_USB_PHY_CTRL_TOG_DATA_ON_LRADC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_ON_LRADC field to a new value.
#define BW_USB_PHY_CTRL_TOG_DATA_ON_LRADC(v)   BF_CS1(USB_PHY_CTRL_TOG, DATA_ON_LRADC, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENUTMILEVEL2 (RW)
 *
 * Enables UTMI+ Level2. This should be enabled if needs to support LS device
 */

#define BP_USB_PHY_CTRL_TOG_ENUTMILEVEL2      14
#define BM_USB_PHY_CTRL_TOG_ENUTMILEVEL2      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENUTMILEVEL2(v)   ((((reg32_t) v) << 14) & BM_USB_PHY_CTRL_TOG_ENUTMILEVEL2)
#else
#define BF_USB_PHY_CTRL_TOG_ENUTMILEVEL2(v)   (((v) << 14) & BM_USB_PHY_CTRL_TOG_ENUTMILEVEL2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL2 field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENUTMILEVEL2(v)   BF_CS1(USB_PHY_CTRL_TOG, ENUTMILEVEL2, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENUTMILEVEL3 (RW)
 *
 * Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device
 * connected
 */

#define BP_USB_PHY_CTRL_TOG_ENUTMILEVEL3      15
#define BM_USB_PHY_CTRL_TOG_ENUTMILEVEL3      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENUTMILEVEL3(v)   ((((reg32_t) v) << 15) & BM_USB_PHY_CTRL_TOG_ENUTMILEVEL3)
#else
#define BF_USB_PHY_CTRL_TOG_ENUTMILEVEL3(v)   (((v) << 15) & BM_USB_PHY_CTRL_TOG_ENUTMILEVEL3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL3 field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENUTMILEVEL3(v)   BF_CS1(USB_PHY_CTRL_TOG, ENUTMILEVEL3, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENIRQWAKEUP (RW)
 *
 * Enables interrupt for the wakeup events.
 */

#define BP_USB_PHY_CTRL_TOG_ENIRQWAKEUP      16
#define BM_USB_PHY_CTRL_TOG_ENIRQWAKEUP      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENIRQWAKEUP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_CTRL_TOG_ENIRQWAKEUP)
#else
#define BF_USB_PHY_CTRL_TOG_ENIRQWAKEUP(v)   (((v) << 16) & BM_USB_PHY_CTRL_TOG_ENIRQWAKEUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQWAKEUP field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENIRQWAKEUP(v)   BF_CS1(USB_PHY_CTRL_TOG, ENIRQWAKEUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field WAKEUP_IRQ (RW)
 *
 * Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_TOG_WAKEUP_IRQ      17
#define BM_USB_PHY_CTRL_TOG_WAKEUP_IRQ      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_WAKEUP_IRQ(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_CTRL_TOG_WAKEUP_IRQ)
#else
#define BF_USB_PHY_CTRL_TOG_WAKEUP_IRQ(v)   (((v) << 17) & BM_USB_PHY_CTRL_TOG_WAKEUP_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP_IRQ field to a new value.
#define BW_USB_PHY_CTRL_TOG_WAKEUP_IRQ(v)   BF_CS1(USB_PHY_CTRL_TOG, WAKEUP_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENAUTOCLR_CLKGATE (RW)
 *
 * Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is
 * suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
 */

#define BP_USB_PHY_CTRL_TOG_ENAUTOCLR_CLKGATE      19
#define BM_USB_PHY_CTRL_TOG_ENAUTOCLR_CLKGATE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENAUTOCLR_CLKGATE(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_CTRL_TOG_ENAUTOCLR_CLKGATE)
#else
#define BF_USB_PHY_CTRL_TOG_ENAUTOCLR_CLKGATE(v)   (((v) << 19) & BM_USB_PHY_CTRL_TOG_ENAUTOCLR_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENAUTOCLR_CLKGATE(v)   BF_CS1(USB_PHY_CTRL_TOG, ENAUTOCLR_CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENAUTOCLR_PHY_PWD (RW)
 *
 * Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event
 * while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's
 * interaction.
 */

#define BP_USB_PHY_CTRL_TOG_ENAUTOCLR_PHY_PWD      20
#define BM_USB_PHY_CTRL_TOG_ENAUTOCLR_PHY_PWD      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENAUTOCLR_PHY_PWD(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_CTRL_TOG_ENAUTOCLR_PHY_PWD)
#else
#define BF_USB_PHY_CTRL_TOG_ENAUTOCLR_PHY_PWD(v)   (((v) << 20) & BM_USB_PHY_CTRL_TOG_ENAUTOCLR_PHY_PWD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_PHY_PWD field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENAUTOCLR_PHY_PWD(v)   BF_CS1(USB_PHY_CTRL_TOG, ENAUTOCLR_PHY_PWD, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENDPDMCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled
 * by default.
 */

#define BP_USB_PHY_CTRL_TOG_ENDPDMCHG_WKUP      21
#define BM_USB_PHY_CTRL_TOG_ENDPDMCHG_WKUP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENDPDMCHG_WKUP(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_CTRL_TOG_ENDPDMCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_TOG_ENDPDMCHG_WKUP(v)   (((v) << 21) & BM_USB_PHY_CTRL_TOG_ENDPDMCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDPDMCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENDPDMCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_TOG, ENDPDMCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENIDCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if ID is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_TOG_ENIDCHG_WKUP      22
#define BM_USB_PHY_CTRL_TOG_ENIDCHG_WKUP      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENIDCHG_WKUP(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_CTRL_TOG_ENIDCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_TOG_ENIDCHG_WKUP(v)   (((v) << 22) & BM_USB_PHY_CTRL_TOG_ENIDCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIDCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENIDCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_TOG, ENIDCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field ENVBUSCHG_WKUP (RW)
 *
 * Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_TOG_ENVBUSCHG_WKUP      23
#define BM_USB_PHY_CTRL_TOG_ENVBUSCHG_WKUP      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_ENVBUSCHG_WKUP(v)   ((((reg32_t) v) << 23) & BM_USB_PHY_CTRL_TOG_ENVBUSCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_TOG_ENVBUSCHG_WKUP(v)   (((v) << 23) & BM_USB_PHY_CTRL_TOG_ENVBUSCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVBUSCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_TOG_ENVBUSCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL_TOG, ENVBUSCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field FSDLL_RST_EN (RW)
 *
 * Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
 */

#define BP_USB_PHY_CTRL_TOG_FSDLL_RST_EN      24
#define BM_USB_PHY_CTRL_TOG_FSDLL_RST_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_FSDLL_RST_EN(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_CTRL_TOG_FSDLL_RST_EN)
#else
#define BF_USB_PHY_CTRL_TOG_FSDLL_RST_EN(v)   (((v) << 24) & BM_USB_PHY_CTRL_TOG_FSDLL_RST_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FSDLL_RST_EN field to a new value.
#define BW_USB_PHY_CTRL_TOG_FSDLL_RST_EN(v)   BF_CS1(USB_PHY_CTRL_TOG, FSDLL_RST_EN, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field OTG_ID_VALUE (RO)
 *
 * Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE
 * has debounce logic to filter the glitches on ID Pad.
 */

#define BP_USB_PHY_CTRL_TOG_OTG_ID_VALUE      27
#define BM_USB_PHY_CTRL_TOG_OTG_ID_VALUE      0x08000000

/* --- Register HW_USB_PHY_CTRL_TOG, field HOST_FORCE_LS_SE0 (RW)
 *
 * Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in
 * host mode for the resume sequence. After the packet is transferred, this bit is cleared. The
 * design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger
 * this event when leaving suspend. This bit is used in conjunction with
 * USBPHYx_DEBUG_HOST_RESUME_DEBUG.
 */

#define BP_USB_PHY_CTRL_TOG_HOST_FORCE_LS_SE0      28
#define BM_USB_PHY_CTRL_TOG_HOST_FORCE_LS_SE0      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_HOST_FORCE_LS_SE0(v)   ((((reg32_t) v) << 28) & BM_USB_PHY_CTRL_TOG_HOST_FORCE_LS_SE0)
#else
#define BF_USB_PHY_CTRL_TOG_HOST_FORCE_LS_SE0(v)   (((v) << 28) & BM_USB_PHY_CTRL_TOG_HOST_FORCE_LS_SE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_FORCE_LS_SE0 field to a new value.
#define BW_USB_PHY_CTRL_TOG_HOST_FORCE_LS_SE0(v)   BF_CS1(USB_PHY_CTRL_TOG, HOST_FORCE_LS_SE0, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field UTMI_SUSPENDM (RO)
 *
 * Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD
 * are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required
 * by the UTMI specification.
 */

#define BP_USB_PHY_CTRL_TOG_UTMI_SUSPENDM      29
#define BM_USB_PHY_CTRL_TOG_UTMI_SUSPENDM      0x20000000

/* --- Register HW_USB_PHY_CTRL_TOG, field CLKGATE (RW)
 *
 * Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while
 * the USB is not actively being used. Configuration state is kept while the clock is gated. Note
 * this bit can be auto-cleared if there is any wakeup event when USB is suspended while
 * ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_CTRL_TOG_CLKGATE      30
#define BM_USB_PHY_CTRL_TOG_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_CTRL_TOG_CLKGATE)
#else
#define BF_USB_PHY_CTRL_TOG_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_CTRL_TOG_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_TOG_CLKGATE(v)   BF_CS1(USB_PHY_CTRL_TOG, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL_TOG, field SFTRST (RW)
 *
 * Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL
 * registers. Set to 0 to release the PHY from reset.
 */

#define BP_USB_PHY_CTRL_TOG_SFTRST      31
#define BM_USB_PHY_CTRL_TOG_SFTRST      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_TOG_SFTRST(v)   ((((reg32_t) v) << 31) & BM_USB_PHY_CTRL_TOG_SFTRST)
#else
#define BF_USB_PHY_CTRL_TOG_SFTRST(v)   (((v) << 31) & BM_USB_PHY_CTRL_TOG_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_USB_PHY_CTRL_TOG_SFTRST(v)   BF_CS1(USB_PHY_CTRL_TOG, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_STATUS - USB PHY Status Register (RW)
 *
 * The USB PHY Status Register holds results of IRQ and other detects.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 3; //!< Reserved.
        unsigned HOSTDISCONDETECT_STATUS : 1; //!< Indicates that the device has disconnected while in high-speed host mode.
        unsigned RESERVED1 : 2; //!< Reserved.
        unsigned DEVPLUGIN_STATUS : 1; //!< Indicates that the device has been connected on the USB_DP and USB_DM lines.
        unsigned RESERVED2 : 1; //!< Reserved.
        unsigned OTGID_STATUS : 1; //!< Indicates the results of ID pin on MiniAB plug. False (0) is when ID resistance is less than Ra_Plug_ID, indicating host (A) side. True (1) is when ID resistance is greater than Rb_Plug_ID, indicating device (B) side.
        unsigned RESERVED3 : 1; //!< Reserved.
        unsigned RESUME_STATUS : 1; //!< Indicates that the host is sending a wake-up after suspend and has triggered an interrupt.
        unsigned RESERVED4 : 21; //!< Reserved.
    } B;
} hw_usb_phy_status_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_STATUS register
 */
#define HW_USB_PHY_STATUS_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_STATUS(x)           (*(volatile hw_usb_phy_status_t *) HW_USB_PHY_STATUS_ADDR(x))
#define HW_USB_PHY_STATUS_RD(x)        (HW_USB_PHY_STATUS(x).U)
#define HW_USB_PHY_STATUS_WR(x, v)     (HW_USB_PHY_STATUS(x).U = (v))
#define HW_USB_PHY_STATUS_SET(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) |  (v)))
#define HW_USB_PHY_STATUS_CLR(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) & ~(v)))
#define HW_USB_PHY_STATUS_TOG(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_STATUS bitfields
 */

/* --- Register HW_USB_PHY_STATUS, field HOSTDISCONDETECT_STATUS (RO)
 *
 * Indicates that the device has disconnected while in high-speed host mode.
 */

#define BP_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS      3
#define BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS      0x00000008

/* --- Register HW_USB_PHY_STATUS, field DEVPLUGIN_STATUS (RO)
 *
 * Indicates that the device has been connected on the USB_DP and USB_DM lines.
 */

#define BP_USB_PHY_STATUS_DEVPLUGIN_STATUS      6
#define BM_USB_PHY_STATUS_DEVPLUGIN_STATUS      0x00000040

/* --- Register HW_USB_PHY_STATUS, field OTGID_STATUS (RW)
 *
 * Indicates the results of ID pin on MiniAB plug. False (0) is when ID resistance is less than
 * Ra_Plug_ID, indicating host (A) side. True (1) is when ID resistance is greater than Rb_Plug_ID,
 * indicating device (B) side.
 */

#define BP_USB_PHY_STATUS_OTGID_STATUS      8
#define BM_USB_PHY_STATUS_OTGID_STATUS      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_OTGID_STATUS(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_STATUS_OTGID_STATUS)
#else
#define BF_USB_PHY_STATUS_OTGID_STATUS(v)   (((v) << 8) & BM_USB_PHY_STATUS_OTGID_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTGID_STATUS field to a new value.
#define BW_USB_PHY_STATUS_OTGID_STATUS(v)   BF_CS1(USB_PHY_STATUS, OTGID_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RESUME_STATUS (RO)
 *
 * Indicates that the host is sending a wake-up after suspend and has triggered an interrupt.
 */

#define BP_USB_PHY_STATUS_RESUME_STATUS      10
#define BM_USB_PHY_STATUS_RESUME_STATUS      0x00000400

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG - USB PHY Debug Register (RW)
 *
 * This register is used to debug the USB PHY.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned OTGIDPIOLOCK : 1; //!< Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power for the comparators that are used to determine the ID status.
        unsigned DEBUG_INTERFACE_HOLD : 1; //!< Use holding registers to assist in timing for external UTMI interface.
        unsigned HSTPULLDOWN : 2; //!< Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM line. Clear to 0 to disable.
        unsigned ENHSTPULLDOWN : 2; //!< Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
        unsigned RESERVED0 : 2; //!< Reserved.
        unsigned TX2RXCOUNT : 4; //!< Delay in between the end of transmit to the beginning of receive. This is a Johnson count value and thus will count to 8.
        unsigned ENTX2RXCOUNT : 1; //!< Set this bit to allow a countdown to transition in between TX and RX.
        unsigned RESERVED1 : 3; //!< Reserved.
        unsigned SQUELCHRESETCOUNT : 5; //!< Delay in between the detection of squelch to the reset of high-speed RX.
        unsigned RESERVED2 : 3; //!< Reserved.
        unsigned ENSQUELCHRESET : 1; //!< Set bit to allow squelch to reset high-speed receive.
        unsigned SQUELCHRESETLENGTH : 4; //!< Duration of RESET in terms of the number of 480-MHz cycles.
        unsigned HOST_RESUME_DEBUG : 1; //!< Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
        unsigned CLKGATE : 1; //!< Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated.
        unsigned RESERVED3 : 1; //!< Reserved.
    } B;
} hw_usb_phy_debug_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG register
 */
#define HW_USB_PHY_DEBUG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG(x)           (*(volatile hw_usb_phy_debug_t *) HW_USB_PHY_DEBUG_ADDR(x))
#define HW_USB_PHY_DEBUG_RD(x)        (HW_USB_PHY_DEBUG(x).U)
#define HW_USB_PHY_DEBUG_WR(x, v)     (HW_USB_PHY_DEBUG(x).U = (v))
#define HW_USB_PHY_DEBUG_SET(x, v)    (HW_USB_PHY_DEBUG_WR(x, HW_USB_PHY_DEBUG_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG_CLR(x, v)    (HW_USB_PHY_DEBUG_WR(x, HW_USB_PHY_DEBUG_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG_TOG(x, v)    (HW_USB_PHY_DEBUG_WR(x, HW_USB_PHY_DEBUG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG bitfields
 */

/* --- Register HW_USB_PHY_DEBUG, field OTGIDPIOLOCK (RW)
 *
 * Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power
 * for the comparators that are used to determine the ID status.
 */

#define BP_USB_PHY_DEBUG_OTGIDPIOLOCK      0
#define BM_USB_PHY_DEBUG_OTGIDPIOLOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG_OTGIDPIOLOCK)
#else
#define BF_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   (((v) << 0) & BM_USB_PHY_DEBUG_OTGIDPIOLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTGIDPIOLOCK field to a new value.
#define BW_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   BF_CS1(USB_PHY_DEBUG, OTGIDPIOLOCK, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field DEBUG_INTERFACE_HOLD (RW)
 *
 * Use holding registers to assist in timing for external UTMI interface.
 */

#define BP_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD      1
#define BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD)
#else
#define BF_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   (((v) << 1) & BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEBUG_INTERFACE_HOLD field to a new value.
#define BW_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   BF_CS1(USB_PHY_DEBUG, DEBUG_INTERFACE_HOLD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field HSTPULLDOWN (RW)
 *
 * Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM
 * line. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_HSTPULLDOWN      2
#define BM_USB_PHY_DEBUG_HSTPULLDOWN      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_HSTPULLDOWN(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_DEBUG_HSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_HSTPULLDOWN(v)   (((v) << 2) & BM_USB_PHY_DEBUG_HSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_HSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG, HSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENHSTPULLDOWN (RW)
 *
 * Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override
 * the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_ENHSTPULLDOWN      4
#define BM_USB_PHY_DEBUG_ENHSTPULLDOWN      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   (((v) << 4) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG, ENHSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field TX2RXCOUNT (RW)
 *
 * Delay in between the end of transmit to the beginning of receive. This is a Johnson count value
 * and thus will count to 8.
 */

#define BP_USB_PHY_DEBUG_TX2RXCOUNT      8
#define BM_USB_PHY_DEBUG_TX2RXCOUNT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TX2RXCOUNT(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_DEBUG_TX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_TX2RXCOUNT(v)   (((v) << 8) & BM_USB_PHY_DEBUG_TX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_TX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG, TX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENTX2RXCOUNT (RW)
 *
 * Set this bit to allow a countdown to transition in between TX and RX.
 */

#define BP_USB_PHY_DEBUG_ENTX2RXCOUNT      12
#define BM_USB_PHY_DEBUG_ENTX2RXCOUNT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_DEBUG_ENTX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   (((v) << 12) & BM_USB_PHY_DEBUG_ENTX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG, ENTX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field SQUELCHRESETCOUNT (RW)
 *
 * Delay in between the detection of squelch to the reset of high-speed RX.
 */

#define BP_USB_PHY_DEBUG_SQUELCHRESETCOUNT      16
#define BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT)
#else
#define BF_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   (((v) << 16) & BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   BF_CS1(USB_PHY_DEBUG, SQUELCHRESETCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENSQUELCHRESET (RW)
 *
 * Set bit to allow squelch to reset high-speed receive.
 */

#define BP_USB_PHY_DEBUG_ENSQUELCHRESET      24
#define BM_USB_PHY_DEBUG_ENSQUELCHRESET      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_ENSQUELCHRESET(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_DEBUG_ENSQUELCHRESET)
#else
#define BF_USB_PHY_DEBUG_ENSQUELCHRESET(v)   (((v) << 24) & BM_USB_PHY_DEBUG_ENSQUELCHRESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENSQUELCHRESET field to a new value.
#define BW_USB_PHY_DEBUG_ENSQUELCHRESET(v)   BF_CS1(USB_PHY_DEBUG, ENSQUELCHRESET, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field SQUELCHRESETLENGTH (RW)
 *
 * Duration of RESET in terms of the number of 480-MHz cycles.
 */

#define BP_USB_PHY_DEBUG_SQUELCHRESETLENGTH      25
#define BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH      0x1e000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH)
#else
#define BF_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   (((v) << 25) & BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETLENGTH field to a new value.
#define BW_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   BF_CS1(USB_PHY_DEBUG, SQUELCHRESETLENGTH, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field HOST_RESUME_DEBUG (RW)
 *
 * Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
 */

#define BP_USB_PHY_DEBUG_HOST_RESUME_DEBUG      29
#define BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   ((((reg32_t) v) << 29) & BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG)
#else
#define BF_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   (((v) << 29) & BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_RESUME_DEBUG field to a new value.
#define BW_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   BF_CS1(USB_PHY_DEBUG, HOST_RESUME_DEBUG, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field CLKGATE (RW)
 *
 * Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power
 * while the USB is not actively being used. Configuration state is kept while the clock is gated.
 */

#define BP_USB_PHY_DEBUG_CLKGATE      30
#define BM_USB_PHY_DEBUG_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_DEBUG_CLKGATE)
#else
#define BF_USB_PHY_DEBUG_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_DEBUG_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_DEBUG_CLKGATE(v)   BF_CS1(USB_PHY_DEBUG, CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG_SET - USB PHY Debug Register _SET (RW)
 *
 * This register is used to debug the USB PHY.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned OTGIDPIOLOCK : 1; //!< Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power for the comparators that are used to determine the ID status.
        unsigned DEBUG_INTERFACE_HOLD : 1; //!< Use holding registers to assist in timing for external UTMI interface.
        unsigned HSTPULLDOWN : 2; //!< Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM line. Clear to 0 to disable.
        unsigned ENHSTPULLDOWN : 2; //!< Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
        unsigned RESERVED0 : 2; //!< Reserved.
        unsigned TX2RXCOUNT : 4; //!< Delay in between the end of transmit to the beginning of receive. This is a Johnson count value and thus will count to 8.
        unsigned ENTX2RXCOUNT : 1; //!< Set this bit to allow a countdown to transition in between TX and RX.
        unsigned RESERVED1 : 3; //!< Reserved.
        unsigned SQUELCHRESETCOUNT : 5; //!< Delay in between the detection of squelch to the reset of high-speed RX.
        unsigned RESERVED2 : 3; //!< Reserved.
        unsigned ENSQUELCHRESET : 1; //!< Set bit to allow squelch to reset high-speed receive.
        unsigned SQUELCHRESETLENGTH : 4; //!< Duration of RESET in terms of the number of 480-MHz cycles.
        unsigned HOST_RESUME_DEBUG : 1; //!< Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
        unsigned CLKGATE : 1; //!< Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated.
        unsigned RESERVED3 : 1; //!< Reserved.
    } B;
} hw_usb_phy_debug_set_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG_SET register
 */
#define HW_USB_PHY_DEBUG_SET_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG_SET(x)           (*(volatile hw_usb_phy_debug_set_t *) HW_USB_PHY_DEBUG_SET_ADDR(x))
#define HW_USB_PHY_DEBUG_SET_RD(x)        (HW_USB_PHY_DEBUG_SET(x).U)
#define HW_USB_PHY_DEBUG_SET_WR(x, v)     (HW_USB_PHY_DEBUG_SET(x).U = (v))
#define HW_USB_PHY_DEBUG_SET_SET(x, v)    (HW_USB_PHY_DEBUG_SET_WR(x, HW_USB_PHY_DEBUG_SET_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG_SET_CLR(x, v)    (HW_USB_PHY_DEBUG_SET_WR(x, HW_USB_PHY_DEBUG_SET_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG_SET_TOG(x, v)    (HW_USB_PHY_DEBUG_SET_WR(x, HW_USB_PHY_DEBUG_SET_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG_SET bitfields
 */

/* --- Register HW_USB_PHY_DEBUG_SET, field OTGIDPIOLOCK (RW)
 *
 * Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power
 * for the comparators that are used to determine the ID status.
 */

#define BP_USB_PHY_DEBUG_SET_OTGIDPIOLOCK      0
#define BM_USB_PHY_DEBUG_SET_OTGIDPIOLOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_OTGIDPIOLOCK(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG_SET_OTGIDPIOLOCK)
#else
#define BF_USB_PHY_DEBUG_SET_OTGIDPIOLOCK(v)   (((v) << 0) & BM_USB_PHY_DEBUG_SET_OTGIDPIOLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTGIDPIOLOCK field to a new value.
#define BW_USB_PHY_DEBUG_SET_OTGIDPIOLOCK(v)   BF_CS1(USB_PHY_DEBUG_SET, OTGIDPIOLOCK, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field DEBUG_INTERFACE_HOLD (RW)
 *
 * Use holding registers to assist in timing for external UTMI interface.
 */

#define BP_USB_PHY_DEBUG_SET_DEBUG_INTERFACE_HOLD      1
#define BM_USB_PHY_DEBUG_SET_DEBUG_INTERFACE_HOLD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_DEBUG_INTERFACE_HOLD(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_DEBUG_SET_DEBUG_INTERFACE_HOLD)
#else
#define BF_USB_PHY_DEBUG_SET_DEBUG_INTERFACE_HOLD(v)   (((v) << 1) & BM_USB_PHY_DEBUG_SET_DEBUG_INTERFACE_HOLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEBUG_INTERFACE_HOLD field to a new value.
#define BW_USB_PHY_DEBUG_SET_DEBUG_INTERFACE_HOLD(v)   BF_CS1(USB_PHY_DEBUG_SET, DEBUG_INTERFACE_HOLD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field HSTPULLDOWN (RW)
 *
 * Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM
 * line. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_SET_HSTPULLDOWN      2
#define BM_USB_PHY_DEBUG_SET_HSTPULLDOWN      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_HSTPULLDOWN(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_DEBUG_SET_HSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_SET_HSTPULLDOWN(v)   (((v) << 2) & BM_USB_PHY_DEBUG_SET_HSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_SET_HSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG_SET, HSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field ENHSTPULLDOWN (RW)
 *
 * Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override
 * the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_SET_ENHSTPULLDOWN      4
#define BM_USB_PHY_DEBUG_SET_ENHSTPULLDOWN      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_ENHSTPULLDOWN(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_DEBUG_SET_ENHSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_SET_ENHSTPULLDOWN(v)   (((v) << 4) & BM_USB_PHY_DEBUG_SET_ENHSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_SET_ENHSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG_SET, ENHSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field TX2RXCOUNT (RW)
 *
 * Delay in between the end of transmit to the beginning of receive. This is a Johnson count value
 * and thus will count to 8.
 */

#define BP_USB_PHY_DEBUG_SET_TX2RXCOUNT      8
#define BM_USB_PHY_DEBUG_SET_TX2RXCOUNT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_TX2RXCOUNT(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_DEBUG_SET_TX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_SET_TX2RXCOUNT(v)   (((v) << 8) & BM_USB_PHY_DEBUG_SET_TX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_SET_TX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG_SET, TX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field ENTX2RXCOUNT (RW)
 *
 * Set this bit to allow a countdown to transition in between TX and RX.
 */

#define BP_USB_PHY_DEBUG_SET_ENTX2RXCOUNT      12
#define BM_USB_PHY_DEBUG_SET_ENTX2RXCOUNT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_ENTX2RXCOUNT(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_DEBUG_SET_ENTX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_SET_ENTX2RXCOUNT(v)   (((v) << 12) & BM_USB_PHY_DEBUG_SET_ENTX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_SET_ENTX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG_SET, ENTX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field SQUELCHRESETCOUNT (RW)
 *
 * Delay in between the detection of squelch to the reset of high-speed RX.
 */

#define BP_USB_PHY_DEBUG_SET_SQUELCHRESETCOUNT      16
#define BM_USB_PHY_DEBUG_SET_SQUELCHRESETCOUNT      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_SQUELCHRESETCOUNT(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_DEBUG_SET_SQUELCHRESETCOUNT)
#else
#define BF_USB_PHY_DEBUG_SET_SQUELCHRESETCOUNT(v)   (((v) << 16) & BM_USB_PHY_DEBUG_SET_SQUELCHRESETCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_SET_SQUELCHRESETCOUNT(v)   BF_CS1(USB_PHY_DEBUG_SET, SQUELCHRESETCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field ENSQUELCHRESET (RW)
 *
 * Set bit to allow squelch to reset high-speed receive.
 */

#define BP_USB_PHY_DEBUG_SET_ENSQUELCHRESET      24
#define BM_USB_PHY_DEBUG_SET_ENSQUELCHRESET      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_ENSQUELCHRESET(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_DEBUG_SET_ENSQUELCHRESET)
#else
#define BF_USB_PHY_DEBUG_SET_ENSQUELCHRESET(v)   (((v) << 24) & BM_USB_PHY_DEBUG_SET_ENSQUELCHRESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENSQUELCHRESET field to a new value.
#define BW_USB_PHY_DEBUG_SET_ENSQUELCHRESET(v)   BF_CS1(USB_PHY_DEBUG_SET, ENSQUELCHRESET, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field SQUELCHRESETLENGTH (RW)
 *
 * Duration of RESET in terms of the number of 480-MHz cycles.
 */

#define BP_USB_PHY_DEBUG_SET_SQUELCHRESETLENGTH      25
#define BM_USB_PHY_DEBUG_SET_SQUELCHRESETLENGTH      0x1e000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_SQUELCHRESETLENGTH(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_DEBUG_SET_SQUELCHRESETLENGTH)
#else
#define BF_USB_PHY_DEBUG_SET_SQUELCHRESETLENGTH(v)   (((v) << 25) & BM_USB_PHY_DEBUG_SET_SQUELCHRESETLENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETLENGTH field to a new value.
#define BW_USB_PHY_DEBUG_SET_SQUELCHRESETLENGTH(v)   BF_CS1(USB_PHY_DEBUG_SET, SQUELCHRESETLENGTH, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field HOST_RESUME_DEBUG (RW)
 *
 * Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
 */

#define BP_USB_PHY_DEBUG_SET_HOST_RESUME_DEBUG      29
#define BM_USB_PHY_DEBUG_SET_HOST_RESUME_DEBUG      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_HOST_RESUME_DEBUG(v)   ((((reg32_t) v) << 29) & BM_USB_PHY_DEBUG_SET_HOST_RESUME_DEBUG)
#else
#define BF_USB_PHY_DEBUG_SET_HOST_RESUME_DEBUG(v)   (((v) << 29) & BM_USB_PHY_DEBUG_SET_HOST_RESUME_DEBUG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_RESUME_DEBUG field to a new value.
#define BW_USB_PHY_DEBUG_SET_HOST_RESUME_DEBUG(v)   BF_CS1(USB_PHY_DEBUG_SET, HOST_RESUME_DEBUG, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_SET, field CLKGATE (RW)
 *
 * Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power
 * while the USB is not actively being used. Configuration state is kept while the clock is gated.
 */

#define BP_USB_PHY_DEBUG_SET_CLKGATE      30
#define BM_USB_PHY_DEBUG_SET_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SET_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_DEBUG_SET_CLKGATE)
#else
#define BF_USB_PHY_DEBUG_SET_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_DEBUG_SET_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_DEBUG_SET_CLKGATE(v)   BF_CS1(USB_PHY_DEBUG_SET, CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG_CLR - USB PHY Debug Register _CLR (RW)
 *
 * This register is used to debug the USB PHY.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned OTGIDPIOLOCK : 1; //!< Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power for the comparators that are used to determine the ID status.
        unsigned DEBUG_INTERFACE_HOLD : 1; //!< Use holding registers to assist in timing for external UTMI interface.
        unsigned HSTPULLDOWN : 2; //!< Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM line. Clear to 0 to disable.
        unsigned ENHSTPULLDOWN : 2; //!< Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
        unsigned RESERVED0 : 2; //!< Reserved.
        unsigned TX2RXCOUNT : 4; //!< Delay in between the end of transmit to the beginning of receive. This is a Johnson count value and thus will count to 8.
        unsigned ENTX2RXCOUNT : 1; //!< Set this bit to allow a countdown to transition in between TX and RX.
        unsigned RESERVED1 : 3; //!< Reserved.
        unsigned SQUELCHRESETCOUNT : 5; //!< Delay in between the detection of squelch to the reset of high-speed RX.
        unsigned RESERVED2 : 3; //!< Reserved.
        unsigned ENSQUELCHRESET : 1; //!< Set bit to allow squelch to reset high-speed receive.
        unsigned SQUELCHRESETLENGTH : 4; //!< Duration of RESET in terms of the number of 480-MHz cycles.
        unsigned HOST_RESUME_DEBUG : 1; //!< Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
        unsigned CLKGATE : 1; //!< Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated.
        unsigned RESERVED3 : 1; //!< Reserved.
    } B;
} hw_usb_phy_debug_clr_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG_CLR register
 */
#define HW_USB_PHY_DEBUG_CLR_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG_CLR(x)           (*(volatile hw_usb_phy_debug_clr_t *) HW_USB_PHY_DEBUG_CLR_ADDR(x))
#define HW_USB_PHY_DEBUG_CLR_RD(x)        (HW_USB_PHY_DEBUG_CLR(x).U)
#define HW_USB_PHY_DEBUG_CLR_WR(x, v)     (HW_USB_PHY_DEBUG_CLR(x).U = (v))
#define HW_USB_PHY_DEBUG_CLR_SET(x, v)    (HW_USB_PHY_DEBUG_CLR_WR(x, HW_USB_PHY_DEBUG_CLR_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG_CLR_CLR(x, v)    (HW_USB_PHY_DEBUG_CLR_WR(x, HW_USB_PHY_DEBUG_CLR_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG_CLR_TOG(x, v)    (HW_USB_PHY_DEBUG_CLR_WR(x, HW_USB_PHY_DEBUG_CLR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG_CLR bitfields
 */

/* --- Register HW_USB_PHY_DEBUG_CLR, field OTGIDPIOLOCK (RW)
 *
 * Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power
 * for the comparators that are used to determine the ID status.
 */

#define BP_USB_PHY_DEBUG_CLR_OTGIDPIOLOCK      0
#define BM_USB_PHY_DEBUG_CLR_OTGIDPIOLOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_OTGIDPIOLOCK(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG_CLR_OTGIDPIOLOCK)
#else
#define BF_USB_PHY_DEBUG_CLR_OTGIDPIOLOCK(v)   (((v) << 0) & BM_USB_PHY_DEBUG_CLR_OTGIDPIOLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTGIDPIOLOCK field to a new value.
#define BW_USB_PHY_DEBUG_CLR_OTGIDPIOLOCK(v)   BF_CS1(USB_PHY_DEBUG_CLR, OTGIDPIOLOCK, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field DEBUG_INTERFACE_HOLD (RW)
 *
 * Use holding registers to assist in timing for external UTMI interface.
 */

#define BP_USB_PHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD      1
#define BM_USB_PHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD)
#else
#define BF_USB_PHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD(v)   (((v) << 1) & BM_USB_PHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEBUG_INTERFACE_HOLD field to a new value.
#define BW_USB_PHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD(v)   BF_CS1(USB_PHY_DEBUG_CLR, DEBUG_INTERFACE_HOLD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field HSTPULLDOWN (RW)
 *
 * Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM
 * line. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_CLR_HSTPULLDOWN      2
#define BM_USB_PHY_DEBUG_CLR_HSTPULLDOWN      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_HSTPULLDOWN(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_DEBUG_CLR_HSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_CLR_HSTPULLDOWN(v)   (((v) << 2) & BM_USB_PHY_DEBUG_CLR_HSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_CLR_HSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG_CLR, HSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field ENHSTPULLDOWN (RW)
 *
 * Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override
 * the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_CLR_ENHSTPULLDOWN      4
#define BM_USB_PHY_DEBUG_CLR_ENHSTPULLDOWN      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_ENHSTPULLDOWN(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_DEBUG_CLR_ENHSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_CLR_ENHSTPULLDOWN(v)   (((v) << 4) & BM_USB_PHY_DEBUG_CLR_ENHSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_CLR_ENHSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG_CLR, ENHSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field TX2RXCOUNT (RW)
 *
 * Delay in between the end of transmit to the beginning of receive. This is a Johnson count value
 * and thus will count to 8.
 */

#define BP_USB_PHY_DEBUG_CLR_TX2RXCOUNT      8
#define BM_USB_PHY_DEBUG_CLR_TX2RXCOUNT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_TX2RXCOUNT(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_DEBUG_CLR_TX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_CLR_TX2RXCOUNT(v)   (((v) << 8) & BM_USB_PHY_DEBUG_CLR_TX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_CLR_TX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG_CLR, TX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field ENTX2RXCOUNT (RW)
 *
 * Set this bit to allow a countdown to transition in between TX and RX.
 */

#define BP_USB_PHY_DEBUG_CLR_ENTX2RXCOUNT      12
#define BM_USB_PHY_DEBUG_CLR_ENTX2RXCOUNT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_ENTX2RXCOUNT(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_DEBUG_CLR_ENTX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_CLR_ENTX2RXCOUNT(v)   (((v) << 12) & BM_USB_PHY_DEBUG_CLR_ENTX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_CLR_ENTX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG_CLR, ENTX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field SQUELCHRESETCOUNT (RW)
 *
 * Delay in between the detection of squelch to the reset of high-speed RX.
 */

#define BP_USB_PHY_DEBUG_CLR_SQUELCHRESETCOUNT      16
#define BM_USB_PHY_DEBUG_CLR_SQUELCHRESETCOUNT      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_SQUELCHRESETCOUNT(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_DEBUG_CLR_SQUELCHRESETCOUNT)
#else
#define BF_USB_PHY_DEBUG_CLR_SQUELCHRESETCOUNT(v)   (((v) << 16) & BM_USB_PHY_DEBUG_CLR_SQUELCHRESETCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_CLR_SQUELCHRESETCOUNT(v)   BF_CS1(USB_PHY_DEBUG_CLR, SQUELCHRESETCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field ENSQUELCHRESET (RW)
 *
 * Set bit to allow squelch to reset high-speed receive.
 */

#define BP_USB_PHY_DEBUG_CLR_ENSQUELCHRESET      24
#define BM_USB_PHY_DEBUG_CLR_ENSQUELCHRESET      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_ENSQUELCHRESET(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_DEBUG_CLR_ENSQUELCHRESET)
#else
#define BF_USB_PHY_DEBUG_CLR_ENSQUELCHRESET(v)   (((v) << 24) & BM_USB_PHY_DEBUG_CLR_ENSQUELCHRESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENSQUELCHRESET field to a new value.
#define BW_USB_PHY_DEBUG_CLR_ENSQUELCHRESET(v)   BF_CS1(USB_PHY_DEBUG_CLR, ENSQUELCHRESET, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field SQUELCHRESETLENGTH (RW)
 *
 * Duration of RESET in terms of the number of 480-MHz cycles.
 */

#define BP_USB_PHY_DEBUG_CLR_SQUELCHRESETLENGTH      25
#define BM_USB_PHY_DEBUG_CLR_SQUELCHRESETLENGTH      0x1e000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_SQUELCHRESETLENGTH(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_DEBUG_CLR_SQUELCHRESETLENGTH)
#else
#define BF_USB_PHY_DEBUG_CLR_SQUELCHRESETLENGTH(v)   (((v) << 25) & BM_USB_PHY_DEBUG_CLR_SQUELCHRESETLENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETLENGTH field to a new value.
#define BW_USB_PHY_DEBUG_CLR_SQUELCHRESETLENGTH(v)   BF_CS1(USB_PHY_DEBUG_CLR, SQUELCHRESETLENGTH, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field HOST_RESUME_DEBUG (RW)
 *
 * Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
 */

#define BP_USB_PHY_DEBUG_CLR_HOST_RESUME_DEBUG      29
#define BM_USB_PHY_DEBUG_CLR_HOST_RESUME_DEBUG      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_HOST_RESUME_DEBUG(v)   ((((reg32_t) v) << 29) & BM_USB_PHY_DEBUG_CLR_HOST_RESUME_DEBUG)
#else
#define BF_USB_PHY_DEBUG_CLR_HOST_RESUME_DEBUG(v)   (((v) << 29) & BM_USB_PHY_DEBUG_CLR_HOST_RESUME_DEBUG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_RESUME_DEBUG field to a new value.
#define BW_USB_PHY_DEBUG_CLR_HOST_RESUME_DEBUG(v)   BF_CS1(USB_PHY_DEBUG_CLR, HOST_RESUME_DEBUG, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_CLR, field CLKGATE (RW)
 *
 * Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power
 * while the USB is not actively being used. Configuration state is kept while the clock is gated.
 */

#define BP_USB_PHY_DEBUG_CLR_CLKGATE      30
#define BM_USB_PHY_DEBUG_CLR_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLR_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_DEBUG_CLR_CLKGATE)
#else
#define BF_USB_PHY_DEBUG_CLR_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_DEBUG_CLR_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_DEBUG_CLR_CLKGATE(v)   BF_CS1(USB_PHY_DEBUG_CLR, CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG_TOG - USB PHY Debug Register _TOG (RW)
 *
 * This register is used to debug the USB PHY.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned OTGIDPIOLOCK : 1; //!< Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power for the comparators that are used to determine the ID status.
        unsigned DEBUG_INTERFACE_HOLD : 1; //!< Use holding registers to assist in timing for external UTMI interface.
        unsigned HSTPULLDOWN : 2; //!< Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM line. Clear to 0 to disable.
        unsigned ENHSTPULLDOWN : 2; //!< Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
        unsigned RESERVED0 : 2; //!< Reserved.
        unsigned TX2RXCOUNT : 4; //!< Delay in between the end of transmit to the beginning of receive. This is a Johnson count value and thus will count to 8.
        unsigned ENTX2RXCOUNT : 1; //!< Set this bit to allow a countdown to transition in between TX and RX.
        unsigned RESERVED1 : 3; //!< Reserved.
        unsigned SQUELCHRESETCOUNT : 5; //!< Delay in between the detection of squelch to the reset of high-speed RX.
        unsigned RESERVED2 : 3; //!< Reserved.
        unsigned ENSQUELCHRESET : 1; //!< Set bit to allow squelch to reset high-speed receive.
        unsigned SQUELCHRESETLENGTH : 4; //!< Duration of RESET in terms of the number of 480-MHz cycles.
        unsigned HOST_RESUME_DEBUG : 1; //!< Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
        unsigned CLKGATE : 1; //!< Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated.
        unsigned RESERVED3 : 1; //!< Reserved.
    } B;
} hw_usb_phy_debug_tog_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG_TOG register
 */
#define HW_USB_PHY_DEBUG_TOG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG_TOG(x)           (*(volatile hw_usb_phy_debug_tog_t *) HW_USB_PHY_DEBUG_TOG_ADDR(x))
#define HW_USB_PHY_DEBUG_TOG_RD(x)        (HW_USB_PHY_DEBUG_TOG(x).U)
#define HW_USB_PHY_DEBUG_TOG_WR(x, v)     (HW_USB_PHY_DEBUG_TOG(x).U = (v))
#define HW_USB_PHY_DEBUG_TOG_SET(x, v)    (HW_USB_PHY_DEBUG_TOG_WR(x, HW_USB_PHY_DEBUG_TOG_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG_TOG_CLR(x, v)    (HW_USB_PHY_DEBUG_TOG_WR(x, HW_USB_PHY_DEBUG_TOG_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG_TOG_TOG(x, v)    (HW_USB_PHY_DEBUG_TOG_WR(x, HW_USB_PHY_DEBUG_TOG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG_TOG bitfields
 */

/* --- Register HW_USB_PHY_DEBUG_TOG, field OTGIDPIOLOCK (RW)
 *
 * Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power
 * for the comparators that are used to determine the ID status.
 */

#define BP_USB_PHY_DEBUG_TOG_OTGIDPIOLOCK      0
#define BM_USB_PHY_DEBUG_TOG_OTGIDPIOLOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_OTGIDPIOLOCK(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG_TOG_OTGIDPIOLOCK)
#else
#define BF_USB_PHY_DEBUG_TOG_OTGIDPIOLOCK(v)   (((v) << 0) & BM_USB_PHY_DEBUG_TOG_OTGIDPIOLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OTGIDPIOLOCK field to a new value.
#define BW_USB_PHY_DEBUG_TOG_OTGIDPIOLOCK(v)   BF_CS1(USB_PHY_DEBUG_TOG, OTGIDPIOLOCK, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field DEBUG_INTERFACE_HOLD (RW)
 *
 * Use holding registers to assist in timing for external UTMI interface.
 */

#define BP_USB_PHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD      1
#define BM_USB_PHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD)
#else
#define BF_USB_PHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD(v)   (((v) << 1) & BM_USB_PHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEBUG_INTERFACE_HOLD field to a new value.
#define BW_USB_PHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD(v)   BF_CS1(USB_PHY_DEBUG_TOG, DEBUG_INTERFACE_HOLD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field HSTPULLDOWN (RW)
 *
 * Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM
 * line. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_TOG_HSTPULLDOWN      2
#define BM_USB_PHY_DEBUG_TOG_HSTPULLDOWN      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_HSTPULLDOWN(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_DEBUG_TOG_HSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_TOG_HSTPULLDOWN(v)   (((v) << 2) & BM_USB_PHY_DEBUG_TOG_HSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_TOG_HSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG_TOG, HSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field ENHSTPULLDOWN (RW)
 *
 * Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override
 * the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_TOG_ENHSTPULLDOWN      4
#define BM_USB_PHY_DEBUG_TOG_ENHSTPULLDOWN      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_ENHSTPULLDOWN(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_DEBUG_TOG_ENHSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_TOG_ENHSTPULLDOWN(v)   (((v) << 4) & BM_USB_PHY_DEBUG_TOG_ENHSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_TOG_ENHSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG_TOG, ENHSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field TX2RXCOUNT (RW)
 *
 * Delay in between the end of transmit to the beginning of receive. This is a Johnson count value
 * and thus will count to 8.
 */

#define BP_USB_PHY_DEBUG_TOG_TX2RXCOUNT      8
#define BM_USB_PHY_DEBUG_TOG_TX2RXCOUNT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_TX2RXCOUNT(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_DEBUG_TOG_TX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_TOG_TX2RXCOUNT(v)   (((v) << 8) & BM_USB_PHY_DEBUG_TOG_TX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_TOG_TX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG_TOG, TX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field ENTX2RXCOUNT (RW)
 *
 * Set this bit to allow a countdown to transition in between TX and RX.
 */

#define BP_USB_PHY_DEBUG_TOG_ENTX2RXCOUNT      12
#define BM_USB_PHY_DEBUG_TOG_ENTX2RXCOUNT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_ENTX2RXCOUNT(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_DEBUG_TOG_ENTX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_TOG_ENTX2RXCOUNT(v)   (((v) << 12) & BM_USB_PHY_DEBUG_TOG_ENTX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_TOG_ENTX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG_TOG, ENTX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field SQUELCHRESETCOUNT (RW)
 *
 * Delay in between the detection of squelch to the reset of high-speed RX.
 */

#define BP_USB_PHY_DEBUG_TOG_SQUELCHRESETCOUNT      16
#define BM_USB_PHY_DEBUG_TOG_SQUELCHRESETCOUNT      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_SQUELCHRESETCOUNT(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_DEBUG_TOG_SQUELCHRESETCOUNT)
#else
#define BF_USB_PHY_DEBUG_TOG_SQUELCHRESETCOUNT(v)   (((v) << 16) & BM_USB_PHY_DEBUG_TOG_SQUELCHRESETCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_TOG_SQUELCHRESETCOUNT(v)   BF_CS1(USB_PHY_DEBUG_TOG, SQUELCHRESETCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field ENSQUELCHRESET (RW)
 *
 * Set bit to allow squelch to reset high-speed receive.
 */

#define BP_USB_PHY_DEBUG_TOG_ENSQUELCHRESET      24
#define BM_USB_PHY_DEBUG_TOG_ENSQUELCHRESET      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_ENSQUELCHRESET(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_DEBUG_TOG_ENSQUELCHRESET)
#else
#define BF_USB_PHY_DEBUG_TOG_ENSQUELCHRESET(v)   (((v) << 24) & BM_USB_PHY_DEBUG_TOG_ENSQUELCHRESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENSQUELCHRESET field to a new value.
#define BW_USB_PHY_DEBUG_TOG_ENSQUELCHRESET(v)   BF_CS1(USB_PHY_DEBUG_TOG, ENSQUELCHRESET, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field SQUELCHRESETLENGTH (RW)
 *
 * Duration of RESET in terms of the number of 480-MHz cycles.
 */

#define BP_USB_PHY_DEBUG_TOG_SQUELCHRESETLENGTH      25
#define BM_USB_PHY_DEBUG_TOG_SQUELCHRESETLENGTH      0x1e000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_SQUELCHRESETLENGTH(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_DEBUG_TOG_SQUELCHRESETLENGTH)
#else
#define BF_USB_PHY_DEBUG_TOG_SQUELCHRESETLENGTH(v)   (((v) << 25) & BM_USB_PHY_DEBUG_TOG_SQUELCHRESETLENGTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETLENGTH field to a new value.
#define BW_USB_PHY_DEBUG_TOG_SQUELCHRESETLENGTH(v)   BF_CS1(USB_PHY_DEBUG_TOG, SQUELCHRESETLENGTH, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field HOST_RESUME_DEBUG (RW)
 *
 * Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
 */

#define BP_USB_PHY_DEBUG_TOG_HOST_RESUME_DEBUG      29
#define BM_USB_PHY_DEBUG_TOG_HOST_RESUME_DEBUG      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_HOST_RESUME_DEBUG(v)   ((((reg32_t) v) << 29) & BM_USB_PHY_DEBUG_TOG_HOST_RESUME_DEBUG)
#else
#define BF_USB_PHY_DEBUG_TOG_HOST_RESUME_DEBUG(v)   (((v) << 29) & BM_USB_PHY_DEBUG_TOG_HOST_RESUME_DEBUG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_RESUME_DEBUG field to a new value.
#define BW_USB_PHY_DEBUG_TOG_HOST_RESUME_DEBUG(v)   BF_CS1(USB_PHY_DEBUG_TOG, HOST_RESUME_DEBUG, v)
#endif

/* --- Register HW_USB_PHY_DEBUG_TOG, field CLKGATE (RW)
 *
 * Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power
 * while the USB is not actively being used. Configuration state is kept while the clock is gated.
 */

#define BP_USB_PHY_DEBUG_TOG_CLKGATE      30
#define BM_USB_PHY_DEBUG_TOG_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TOG_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_DEBUG_TOG_CLKGATE)
#else
#define BF_USB_PHY_DEBUG_TOG_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_DEBUG_TOG_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_DEBUG_TOG_CLKGATE(v)   BF_CS1(USB_PHY_DEBUG_TOG, CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG0_STATUS - UTMI Debug Status Register 0 (RO)
 *
 * The UTMI Debug Status Register 0 holds multiple views for counters and status of state machines.
 * This is used in conjunction with the USBPHYx_DEBUG1_DBG_ADDRESS field to choose which function to
 * view. The default is described in the bit fields below and is used to count errors.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LOOP_BACK_FAIL_COUNT : 16; //!< Running count of the failed pseudo-random generator loopback. Each time entering testmode, counter goes to 900D and will count up for every detected packet failure in digital/analog loopback tests.
        unsigned UTMI_RXERROR_FAIL_COUNT : 10; //!< Running count of the UTMI_RXERROR.
        unsigned SQUELCH_COUNT : 6; //!< Running count of the squelch reset instead of normal end for HS RX.
    } B;
} hw_usb_phy_debug0_status_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG0_STATUS register
 */
#define HW_USB_PHY_DEBUG0_STATUS_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG0_STATUS(x)           (*(volatile hw_usb_phy_debug0_status_t *) HW_USB_PHY_DEBUG0_STATUS_ADDR(x))
#define HW_USB_PHY_DEBUG0_STATUS_RD(x)        (HW_USB_PHY_DEBUG0_STATUS(x).U)
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG0_STATUS bitfields
 */

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field LOOP_BACK_FAIL_COUNT (RO)
 *
 * Running count of the failed pseudo-random generator loopback. Each time entering testmode,
 * counter goes to 900D and will count up for every detected packet failure in digital/analog
 * loopback tests.
 */

#define BP_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT      0
#define BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT      0x0000ffff

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field UTMI_RXERROR_FAIL_COUNT (RO)
 *
 * Running count of the UTMI_RXERROR.
 */

#define BP_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT      16
#define BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT      0x03ff0000

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field SQUELCH_COUNT (RO)
 *
 * Running count of the squelch reset instead of normal end for HS RX.
 */

#define BP_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT      26
#define BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT      0xfc000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG1 - UTMI Debug Status Register 1 (RW)
 *
 * Chooses the muxing of the debug register to be shown in USBPHYx_DEBUG0_STATUS.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 13; //!< Reserved. Note: This bit should remain clear.
        unsigned ENTAILADJVD : 2; //!< Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
        unsigned RESERVED1 : 17; //!< Reserved.
    } B;
} hw_usb_phy_debug1_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG1 register
 */
#define HW_USB_PHY_DEBUG1_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG1(x)           (*(volatile hw_usb_phy_debug1_t *) HW_USB_PHY_DEBUG1_ADDR(x))
#define HW_USB_PHY_DEBUG1_RD(x)        (HW_USB_PHY_DEBUG1(x).U)
#define HW_USB_PHY_DEBUG1_WR(x, v)     (HW_USB_PHY_DEBUG1(x).U = (v))
#define HW_USB_PHY_DEBUG1_SET(x, v)    (HW_USB_PHY_DEBUG1_WR(x, HW_USB_PHY_DEBUG1_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG1_CLR(x, v)    (HW_USB_PHY_DEBUG1_WR(x, HW_USB_PHY_DEBUG1_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG1_TOG(x, v)    (HW_USB_PHY_DEBUG1_WR(x, HW_USB_PHY_DEBUG1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG1 bitfields
 */

/* --- Register HW_USB_PHY_DEBUG1, field ENTAILADJVD (RW)
 *
 * Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is
 * -20% 11 = Delay is -40%
 */

#define BP_USB_PHY_DEBUG1_ENTAILADJVD      13
#define BM_USB_PHY_DEBUG1_ENTAILADJVD      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_ENTAILADJVD(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_DEBUG1_ENTAILADJVD)
#else
#define BF_USB_PHY_DEBUG1_ENTAILADJVD(v)   (((v) << 13) & BM_USB_PHY_DEBUG1_ENTAILADJVD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTAILADJVD field to a new value.
#define BW_USB_PHY_DEBUG1_ENTAILADJVD(v)   BF_CS1(USB_PHY_DEBUG1, ENTAILADJVD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG1_SET - UTMI Debug Status Register 1 _SET (RW)
 *
 * Chooses the muxing of the debug register to be shown in USBPHYx_DEBUG0_STATUS.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 13; //!< Reserved. Note: This bit should remain clear.
        unsigned ENTAILADJVD : 2; //!< Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
        unsigned RESERVED1 : 17; //!< Reserved.
    } B;
} hw_usb_phy_debug1_set_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG1_SET register
 */
#define HW_USB_PHY_DEBUG1_SET_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG1_SET(x)           (*(volatile hw_usb_phy_debug1_set_t *) HW_USB_PHY_DEBUG1_SET_ADDR(x))
#define HW_USB_PHY_DEBUG1_SET_RD(x)        (HW_USB_PHY_DEBUG1_SET(x).U)
#define HW_USB_PHY_DEBUG1_SET_WR(x, v)     (HW_USB_PHY_DEBUG1_SET(x).U = (v))
#define HW_USB_PHY_DEBUG1_SET_SET(x, v)    (HW_USB_PHY_DEBUG1_SET_WR(x, HW_USB_PHY_DEBUG1_SET_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG1_SET_CLR(x, v)    (HW_USB_PHY_DEBUG1_SET_WR(x, HW_USB_PHY_DEBUG1_SET_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG1_SET_TOG(x, v)    (HW_USB_PHY_DEBUG1_SET_WR(x, HW_USB_PHY_DEBUG1_SET_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG1_SET bitfields
 */

/* --- Register HW_USB_PHY_DEBUG1_SET, field ENTAILADJVD (RW)
 *
 * Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is
 * -20% 11 = Delay is -40%
 */

#define BP_USB_PHY_DEBUG1_SET_ENTAILADJVD      13
#define BM_USB_PHY_DEBUG1_SET_ENTAILADJVD      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_SET_ENTAILADJVD(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_DEBUG1_SET_ENTAILADJVD)
#else
#define BF_USB_PHY_DEBUG1_SET_ENTAILADJVD(v)   (((v) << 13) & BM_USB_PHY_DEBUG1_SET_ENTAILADJVD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTAILADJVD field to a new value.
#define BW_USB_PHY_DEBUG1_SET_ENTAILADJVD(v)   BF_CS1(USB_PHY_DEBUG1_SET, ENTAILADJVD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG1_CLR - UTMI Debug Status Register 1 _CLR (RW)
 *
 * Chooses the muxing of the debug register to be shown in USBPHYx_DEBUG0_STATUS.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 13; //!< Reserved. Note: This bit should remain clear.
        unsigned ENTAILADJVD : 2; //!< Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
        unsigned RESERVED1 : 17; //!< Reserved.
    } B;
} hw_usb_phy_debug1_clr_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG1_CLR register
 */
#define HW_USB_PHY_DEBUG1_CLR_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG1_CLR(x)           (*(volatile hw_usb_phy_debug1_clr_t *) HW_USB_PHY_DEBUG1_CLR_ADDR(x))
#define HW_USB_PHY_DEBUG1_CLR_RD(x)        (HW_USB_PHY_DEBUG1_CLR(x).U)
#define HW_USB_PHY_DEBUG1_CLR_WR(x, v)     (HW_USB_PHY_DEBUG1_CLR(x).U = (v))
#define HW_USB_PHY_DEBUG1_CLR_SET(x, v)    (HW_USB_PHY_DEBUG1_CLR_WR(x, HW_USB_PHY_DEBUG1_CLR_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG1_CLR_CLR(x, v)    (HW_USB_PHY_DEBUG1_CLR_WR(x, HW_USB_PHY_DEBUG1_CLR_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG1_CLR_TOG(x, v)    (HW_USB_PHY_DEBUG1_CLR_WR(x, HW_USB_PHY_DEBUG1_CLR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG1_CLR bitfields
 */

/* --- Register HW_USB_PHY_DEBUG1_CLR, field ENTAILADJVD (RW)
 *
 * Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is
 * -20% 11 = Delay is -40%
 */

#define BP_USB_PHY_DEBUG1_CLR_ENTAILADJVD      13
#define BM_USB_PHY_DEBUG1_CLR_ENTAILADJVD      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_CLR_ENTAILADJVD(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_DEBUG1_CLR_ENTAILADJVD)
#else
#define BF_USB_PHY_DEBUG1_CLR_ENTAILADJVD(v)   (((v) << 13) & BM_USB_PHY_DEBUG1_CLR_ENTAILADJVD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTAILADJVD field to a new value.
#define BW_USB_PHY_DEBUG1_CLR_ENTAILADJVD(v)   BF_CS1(USB_PHY_DEBUG1_CLR, ENTAILADJVD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG1_TOG - UTMI Debug Status Register 1 _TOG (RW)
 *
 * Chooses the muxing of the debug register to be shown in USBPHYx_DEBUG0_STATUS.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 13; //!< Reserved. Note: This bit should remain clear.
        unsigned ENTAILADJVD : 2; //!< Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
        unsigned RESERVED1 : 17; //!< Reserved.
    } B;
} hw_usb_phy_debug1_tog_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG1_TOG register
 */
#define HW_USB_PHY_DEBUG1_TOG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG1_TOG(x)           (*(volatile hw_usb_phy_debug1_tog_t *) HW_USB_PHY_DEBUG1_TOG_ADDR(x))
#define HW_USB_PHY_DEBUG1_TOG_RD(x)        (HW_USB_PHY_DEBUG1_TOG(x).U)
#define HW_USB_PHY_DEBUG1_TOG_WR(x, v)     (HW_USB_PHY_DEBUG1_TOG(x).U = (v))
#define HW_USB_PHY_DEBUG1_TOG_SET(x, v)    (HW_USB_PHY_DEBUG1_TOG_WR(x, HW_USB_PHY_DEBUG1_TOG_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG1_TOG_CLR(x, v)    (HW_USB_PHY_DEBUG1_TOG_WR(x, HW_USB_PHY_DEBUG1_TOG_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG1_TOG_TOG(x, v)    (HW_USB_PHY_DEBUG1_TOG_WR(x, HW_USB_PHY_DEBUG1_TOG_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG1_TOG bitfields
 */

/* --- Register HW_USB_PHY_DEBUG1_TOG, field ENTAILADJVD (RW)
 *
 * Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is
 * -20% 11 = Delay is -40%
 */

#define BP_USB_PHY_DEBUG1_TOG_ENTAILADJVD      13
#define BM_USB_PHY_DEBUG1_TOG_ENTAILADJVD      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_TOG_ENTAILADJVD(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_DEBUG1_TOG_ENTAILADJVD)
#else
#define BF_USB_PHY_DEBUG1_TOG_ENTAILADJVD(v)   (((v) << 13) & BM_USB_PHY_DEBUG1_TOG_ENTAILADJVD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTAILADJVD field to a new value.
#define BW_USB_PHY_DEBUG1_TOG_ENTAILADJVD(v)   BF_CS1(USB_PHY_DEBUG1_TOG, ENTAILADJVD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_VERSION - UTMI RTL Version (RO)
 *
 * Fields for RTL Version.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned STEP : 16; //!< Fixed read-only value reflecting the stepping of the RTL version.
        unsigned MINOR : 8; //!< Fixed read-only value reflecting the MINOR field of the RTL version.
        unsigned MAJOR : 8; //!< Fixed read-only value reflecting the MAJOR field of the RTL version.
    } B;
} hw_usb_phy_version_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_VERSION register
 */
#define HW_USB_PHY_VERSION_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_VERSION(x)           (*(volatile hw_usb_phy_version_t *) HW_USB_PHY_VERSION_ADDR(x))
#define HW_USB_PHY_VERSION_RD(x)        (HW_USB_PHY_VERSION(x).U)
#endif

/*
 * constants & macros for individual USB_PHY_VERSION bitfields
 */

/* --- Register HW_USB_PHY_VERSION, field STEP (RO)
 *
 * Fixed read-only value reflecting the stepping of the RTL version.
 */

#define BP_USB_PHY_VERSION_STEP      0
#define BM_USB_PHY_VERSION_STEP      0x0000ffff

/* --- Register HW_USB_PHY_VERSION, field MINOR (RO)
 *
 * Fixed read-only value reflecting the MINOR field of the RTL version.
 */

#define BP_USB_PHY_VERSION_MINOR      16
#define BM_USB_PHY_VERSION_MINOR      0x00ff0000

/* --- Register HW_USB_PHY_VERSION, field MAJOR (RO)
 *
 * Fixed read-only value reflecting the MAJOR field of the RTL version.
 */

#define BP_USB_PHY_VERSION_MAJOR      24
#define BM_USB_PHY_VERSION_MAJOR      0xff000000


/*!
 * @brief All USB_PHY module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_usb_phy_pwd_t PWD; //!< USB PHY Power-Down Register
    volatile hw_usb_phy_pwd_set_t PWD_SET; //!< USB PHY Power-Down Register _SET
    volatile hw_usb_phy_pwd_clr_t PWD_CLR; //!< USB PHY Power-Down Register _CLR
    volatile hw_usb_phy_pwd_tog_t PWD_TOG; //!< USB PHY Power-Down Register _TOG
    volatile hw_usb_phy_tx_t TX; //!< USB PHY Transmitter Control Register
    volatile hw_usb_phy_tx_set_t TX_SET; //!< USB PHY Transmitter Control Register _SET
    volatile hw_usb_phy_tx_clr_t TX_CLR; //!< USB PHY Transmitter Control Register _CLR
    volatile hw_usb_phy_tx_tog_t TX_TOG; //!< USB PHY Transmitter Control Register _TOG
    volatile hw_usb_phy_rx_t RX; //!< USB PHY Receiver Control Register
    volatile hw_usb_phy_rx_set_t RX_SET; //!< USB PHY Receiver Control Register _SET
    volatile hw_usb_phy_rx_clr_t RX_CLR; //!< USB PHY Receiver Control Register _CLR
    volatile hw_usb_phy_rx_tog_t RX_TOG; //!< USB PHY Receiver Control Register _TOG
    volatile hw_usb_phy_ctrl_t CTRL; //!< USB PHY General Control Register
    volatile hw_usb_phy_ctrl_set_t CTRL_SET; //!< USB PHY General Control Register _SET
    volatile hw_usb_phy_ctrl_clr_t CTRL_CLR; //!< USB PHY General Control Register _CLR
    volatile hw_usb_phy_ctrl_tog_t CTRL_TOG; //!< USB PHY General Control Register _TOG
    volatile hw_usb_phy_status_t STATUS; //!< USB PHY Status Register
    reg32_t _reserved0[3];
    volatile hw_usb_phy_debug_t DEBUG; //!< USB PHY Debug Register
    volatile hw_usb_phy_debug_set_t DEBUG_SET; //!< USB PHY Debug Register _SET
    volatile hw_usb_phy_debug_clr_t DEBUG_CLR; //!< USB PHY Debug Register _CLR
    volatile hw_usb_phy_debug_tog_t DEBUG_TOG; //!< USB PHY Debug Register _TOG
    volatile hw_usb_phy_debug0_status_t DEBUG0_STATUS; //!< UTMI Debug Status Register 0
    reg32_t _reserved1[3];
    volatile hw_usb_phy_debug1_t DEBUG1; //!< UTMI Debug Status Register 1
    volatile hw_usb_phy_debug1_set_t DEBUG1_SET; //!< UTMI Debug Status Register 1 _SET
    volatile hw_usb_phy_debug1_clr_t DEBUG1_CLR; //!< UTMI Debug Status Register 1 _CLR
    volatile hw_usb_phy_debug1_tog_t DEBUG1_TOG; //!< UTMI Debug Status Register 1 _TOG
    volatile hw_usb_phy_version_t VERSION; //!< UTMI RTL Version
} hw_usb_phy_t;
#endif

//! @brief Macro to access all USB_PHY registers.
//! @param x USB_PHY instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USB_PHY(0)</code>.
#define HW_USB_PHY(x)     (*(volatile hw_usb_phy_t *) REGS_USB_PHY_BASE(x))


#endif // _USB_PHY_H
