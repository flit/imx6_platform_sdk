/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USB_PHY_H
#define _USB_PHY_H

#include "regs.h"

#ifndef REGS_USB_PHY_BASE
#define REGS_USB_PHY0_BASE (REGS_BASE + 0x020c9000)
#define REGS_USB_PHY1_BASE (REGS_BASE + 0x020ca000)
#define REGS_USB_PHY_BASE(x) ( x == 0 ? REGS_USB_PHY0_BASE : x == 1 ? REGS_USB_PHY1_BASE : 0xffff0000)
#endif


/*!
 * @brief HW_USB_PHY_PWD - USB PHY Power-Down Register
 *
 * The USB PHY Power-Down Register provides overall control of the PHY power state.  Before
 * programming this register, the PHY clocks must be enabled in registers USBPHYx_CTRLn and
 * CCM_ANALOG_USBPHYx_PLL_480_CTRLn.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD0 : 10; //!< Reserved.
        unsigned TXPWDFS : 1; //!< 0 = Normal operation.  1 = Power-down the USB full-speed drivers. This turns off the current starvation sources and puts the drivers into high-impedance output.  Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned TXPWDIBIAS : 1; //!< 0 = Normal operation.  1 = Power-down the USB PHY current bias block for the transmitter. This bit should be set only when the USB is in suspend mode. This effectively powers down the entire USB transmit path.  Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.  Note that these circuits are shared with the battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned TXPWDV2I : 1; //!< 0 = Normal operation.  1 = Power-down the USB PHY transmit V-to-I converter and the current mirror.  Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.  Note that these circuits are shared with the battery charge circuit. Setting this to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned RSVD1 : 4; //!< Reserved.
        unsigned RXPWDENV : 1; //!< 0 = Normal operation.  1 = Power-down the USB high-speed receiver envelope detector (squelch signal).  Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWD1PT1 : 1; //!< 0 = Normal operation.  1 = Power-down the USB full-speed differential receiver.  Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDDIFF : 1; //!< 0 = Normal operation.  1 = Power-down the USB high-speed differential receiver.  Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDRX : 1; //!< 0 = Normal operation.  1 = Power-down the entire USB PHY receiver block except for the full-speed differential receiver.  Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RSVD2 : 11; //!< Reserved.
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

/* --- Register HW_USB_PHY_PWD, field RSVD0
 *
 * Reserved.
 */

#define BP_USB_PHY_PWD_RSVD0      0
#define BM_USB_PHY_PWD_RSVD0      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RSVD0(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_PWD_RSVD0)
#else
#define BF_USB_PHY_PWD_RSVD0(v)   (((v) << 0) & BM_USB_PHY_PWD_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RSVD0(v)   BF_CS1(USB_PHY_PWD, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDFS
 *
 * 0 = Normal operation.  1 = Power-down the USB full-speed drivers. This turns off the current
 * starvation sources and puts the drivers into high-impedance output.  Note that this bit will be
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
#define BW_USB_PHY_PWD_TXPWDFS(v)   BF_CS1(USB_PHY_PWD, TXPWDFS, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDIBIAS
 *
 * 0 = Normal operation.  1 = Power-down the USB PHY current bias block for the transmitter. This
 * bit should be set only when the USB is in suspend mode. This effectively powers down the entire
 * USB transmit path.  Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.  Note that these circuits are shared with the
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
#define BW_USB_PHY_PWD_TXPWDIBIAS(v)   BF_CS1(USB_PHY_PWD, TXPWDIBIAS, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDV2I
 *
 * 0 = Normal operation.  1 = Power-down the USB PHY transmit V-to-I converter and the current
 * mirror.  Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.  Note that these circuits are shared with the
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
#define BW_USB_PHY_PWD_TXPWDV2I(v)   BF_CS1(USB_PHY_PWD, TXPWDV2I, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RSVD1
 *
 * Reserved.
 */

#define BP_USB_PHY_PWD_RSVD1      13
#define BM_USB_PHY_PWD_RSVD1      0x0001e000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RSVD1(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_PWD_RSVD1)
#else
#define BF_USB_PHY_PWD_RSVD1(v)   (((v) << 13) & BM_USB_PHY_PWD_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RSVD1(v)   BF_CS1(USB_PHY_PWD, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDENV
 *
 * 0 = Normal operation.  1 = Power-down the USB high-speed receiver envelope detector (squelch
 * signal).  Note that this bit will be auto cleared if there is USB wakeup event while
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
#define BW_USB_PHY_PWD_RXPWDENV(v)   BF_CS1(USB_PHY_PWD, RXPWDENV, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWD1PT1
 *
 * 0 = Normal operation.  1 = Power-down the USB full-speed differential receiver.  Note that this
 * bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL
 * is enabled.
 */

#define BP_USB_PHY_PWD_RXPWD1PT1      18
#define BM_USB_PHY_PWD_RXPWD1PT1      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWD1PT1(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_PWD_RXPWD1PT1)
#else
#define BF_USB_PHY_PWD_RXPWD1PT1(v)   (((v) << 18) & BM_USB_PHY_PWD_RXPWD1PT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RXPWD1PT1(v)   BF_CS1(USB_PHY_PWD, RXPWD1PT1, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDDIFF
 *
 * 0 = Normal operation.  1 = Power-down the USB high-speed differential receiver.  Note that this
 * bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL
 * is enabled.
 */

#define BP_USB_PHY_PWD_RXPWDDIFF      19
#define BM_USB_PHY_PWD_RXPWDDIFF      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWDDIFF(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_PWD_RXPWDDIFF)
#else
#define BF_USB_PHY_PWD_RXPWDDIFF(v)   (((v) << 19) & BM_USB_PHY_PWD_RXPWDDIFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RXPWDDIFF(v)   BF_CS1(USB_PHY_PWD, RXPWDDIFF, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDRX
 *
 * 0 = Normal operation.  1 = Power-down the entire USB PHY receiver block except for the full-speed
 * differential receiver.  Note that this bit will be auto cleared if there is USB wakeup event
 * while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_RXPWDRX      20
#define BM_USB_PHY_PWD_RXPWDRX      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWDRX(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_PWD_RXPWDRX)
#else
#define BF_USB_PHY_PWD_RXPWDRX(v)   (((v) << 20) & BM_USB_PHY_PWD_RXPWDRX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RXPWDRX(v)   BF_CS1(USB_PHY_PWD, RXPWDRX, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RSVD2
 *
 * Reserved.
 */

#define BP_USB_PHY_PWD_RSVD2      21
#define BM_USB_PHY_PWD_RSVD2      0xffe00000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RSVD2(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_PWD_RSVD2)
#else
#define BF_USB_PHY_PWD_RSVD2(v)   (((v) << 21) & BM_USB_PHY_PWD_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RSVD2(v)   BF_CS1(USB_PHY_PWD, RSVD2, v)
#endif

/*!
 * @brief HW_USB_PHY_TX - USB PHY Transmitter Control Register
 *
 * The USB PHY Transmitter Control Register handles the transmit controls.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned D_CAL : 4; //!< Resistor Trimming Code:  0000 = 0.16%  0111 = Nominal  1111 = +25%
        unsigned RSVD0 : 4; //!< Reserved.  Note: This bit should remain clear.
        unsigned TXCAL45DN : 4; //!< Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RSVD1 : 4; //!< Reserved.  Note: This bit should remain clear.
        unsigned TXCAL45DP : 4; //!< Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RSVD2 : 12; //!< Reserved.
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

/* --- Register HW_USB_PHY_TX, field D_CAL
 *
 * Resistor Trimming Code:  0000 = 0.16%  0111 = Nominal  1111 = +25%
 */

#define BP_USB_PHY_TX_D_CAL      0
#define BM_USB_PHY_TX_D_CAL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_D_CAL(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_TX_D_CAL)
#else
#define BF_USB_PHY_TX_D_CAL(v)   (((v) << 0) & BM_USB_PHY_TX_D_CAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_D_CAL(v)   BF_CS1(USB_PHY_TX, D_CAL, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD0
 *
 * Reserved.  Note: This bit should remain clear.
 */

#define BP_USB_PHY_TX_RSVD0      4
#define BM_USB_PHY_TX_RSVD0      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD0(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_TX_RSVD0)
#else
#define BF_USB_PHY_TX_RSVD0(v)   (((v) << 4) & BM_USB_PHY_TX_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD0(v)   BF_CS1(USB_PHY_TX, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXCAL45DN
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
#define BW_USB_PHY_TX_TXCAL45DN(v)   BF_CS1(USB_PHY_TX, TXCAL45DN, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD1
 *
 * Reserved.  Note: This bit should remain clear.
 */

#define BP_USB_PHY_TX_RSVD1      12
#define BM_USB_PHY_TX_RSVD1      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD1(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_TX_RSVD1)
#else
#define BF_USB_PHY_TX_RSVD1(v)   (((v) << 12) & BM_USB_PHY_TX_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD1(v)   BF_CS1(USB_PHY_TX, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXCAL45DP
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
#define BW_USB_PHY_TX_TXCAL45DP(v)   BF_CS1(USB_PHY_TX, TXCAL45DP, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD2
 *
 * Reserved.
 */

#define BP_USB_PHY_TX_RSVD2      20
#define BM_USB_PHY_TX_RSVD2      0xfff00000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD2(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_TX_RSVD2)
#else
#define BF_USB_PHY_TX_RSVD2(v)   (((v) << 20) & BM_USB_PHY_TX_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD2(v)   BF_CS1(USB_PHY_TX, RSVD2, v)
#endif

/*!
 * @brief HW_USB_PHY_RX - USB PHY Receiver Control Register
 *
 * The USB PHY Receiver Control Register handles receive path controls.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ENVADJ : 3; //!< The ENVADJ field adjusts the trip point for the envelope detector.  0000 = Trip-Level Voltage is 0.12500 V  0001 = Trip-Level Voltage is 0.10000 V  0010 = Trip-Level Voltage is 0.13750 V  0011 = Trip-Level Voltage is 0.15000 V  01XX = Reserved  1XXX = Reserved
        unsigned RSVD0 : 1; //!< Reserved.
        unsigned DISCONADJ : 3; //!< The DISCONADJ field adjusts the trip point for the disconnect detector:  0000 = Trip-Level Voltage is 0.57500 V  0001 = Trip-Level Voltage is 0.56875 V  0010 = Trip-Level Voltage is 0.58125 V  0011 = Trip-Level Voltage is 0.58750 V  01XX = Reserved  1XXX = Reserved
        unsigned RSVD1 : 15; //!< Reserved.
        unsigned RXDBYPASS : 1; //!< 0 = Normal operation.  1 = Use the output of the USB_DP single-ended receiver in place of the full-speed differential receiver.  This test mode is intended for lab use only.
        unsigned RSVD2 : 9; //!< Reserved.
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

/* --- Register HW_USB_PHY_RX, field ENVADJ
 *
 * The ENVADJ field adjusts the trip point for the envelope detector.  0000 = Trip-Level Voltage is
 * 0.12500 V  0001 = Trip-Level Voltage is 0.10000 V  0010 = Trip-Level Voltage is 0.13750 V  0011 =
 * Trip-Level Voltage is 0.15000 V  01XX = Reserved  1XXX = Reserved
 */

#define BP_USB_PHY_RX_ENVADJ      0
#define BM_USB_PHY_RX_ENVADJ      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_ENVADJ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_RX_ENVADJ)
#else
#define BF_USB_PHY_RX_ENVADJ(v)   (((v) << 0) & BM_USB_PHY_RX_ENVADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_ENVADJ(v)   BF_CS1(USB_PHY_RX, ENVADJ, v)
#endif

/* --- Register HW_USB_PHY_RX, field RSVD0
 *
 * Reserved.
 */

#define BP_USB_PHY_RX_RSVD0      3
#define BM_USB_PHY_RX_RSVD0      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RSVD0(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_RX_RSVD0)
#else
#define BF_USB_PHY_RX_RSVD0(v)   (((v) << 3) & BM_USB_PHY_RX_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_RSVD0(v)   BF_CS1(USB_PHY_RX, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_RX, field DISCONADJ
 *
 * The DISCONADJ field adjusts the trip point for the disconnect detector:  0000 = Trip-Level
 * Voltage is 0.57500 V  0001 = Trip-Level Voltage is 0.56875 V  0010 = Trip-Level Voltage is
 * 0.58125 V  0011 = Trip-Level Voltage is 0.58750 V  01XX = Reserved  1XXX = Reserved
 */

#define BP_USB_PHY_RX_DISCONADJ      4
#define BM_USB_PHY_RX_DISCONADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_DISCONADJ(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_RX_DISCONADJ)
#else
#define BF_USB_PHY_RX_DISCONADJ(v)   (((v) << 4) & BM_USB_PHY_RX_DISCONADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_DISCONADJ(v)   BF_CS1(USB_PHY_RX, DISCONADJ, v)
#endif

/* --- Register HW_USB_PHY_RX, field RSVD1
 *
 * Reserved.
 */

#define BP_USB_PHY_RX_RSVD1      7
#define BM_USB_PHY_RX_RSVD1      0x003fff80

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RSVD1(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_RX_RSVD1)
#else
#define BF_USB_PHY_RX_RSVD1(v)   (((v) << 7) & BM_USB_PHY_RX_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_RSVD1(v)   BF_CS1(USB_PHY_RX, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_RX, field RXDBYPASS
 *
 * 0 = Normal operation.  1 = Use the output of the USB_DP single-ended receiver in place of the
 * full-speed differential receiver.  This test mode is intended for lab use only.
 */

#define BP_USB_PHY_RX_RXDBYPASS      22
#define BM_USB_PHY_RX_RXDBYPASS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RXDBYPASS(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_RX_RXDBYPASS)
#else
#define BF_USB_PHY_RX_RXDBYPASS(v)   (((v) << 22) & BM_USB_PHY_RX_RXDBYPASS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_RXDBYPASS(v)   BF_CS1(USB_PHY_RX, RXDBYPASS, v)
#endif

/* --- Register HW_USB_PHY_RX, field RSVD2
 *
 * Reserved.
 */

#define BP_USB_PHY_RX_RSVD2      23
#define BM_USB_PHY_RX_RSVD2      0xff800000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RSVD2(v)   ((((reg32_t) v) << 23) & BM_USB_PHY_RX_RSVD2)
#else
#define BF_USB_PHY_RX_RSVD2(v)   (((v) << 23) & BM_USB_PHY_RX_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_RSVD2(v)   BF_CS1(USB_PHY_RX, RSVD2, v)
#endif

/*!
 * @brief HW_USB_PHY_CTRL - USB PHY General Control Register
 *
 * The USB PHY General Control Register handles OTG and Host controls. This register also includes
 * interrupt enables and connectivity detect enables and results.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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
        unsigned RSVD0 : 1; //!< Reserved.
        unsigned ENAUTOCLR_CLKGATE : 1; //!< Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENAUTOCLR_PHY_PWD : 1; //!< Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENDPDMCHG_WKUP : 1; //!< Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled by default.
        unsigned ENIDCHG_WKUP : 1; //!< Enables the feature to wakeup USB if ID is toggled when USB is suspended.
        unsigned ENVBUSCHG_WKUP : 1; //!< Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
        unsigned FSDLL_RST_EN : 1; //!< Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
        unsigned RSVD1 : 2; //!< Reserved.
        unsigned OTG_ID_VALUE : 1; //!< Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE has debounce logic to filter the glitches on ID Pad.
        unsigned HOST_FORCE_LS_SE0 : 1; //!< Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in host mode for the resume sequence. After the packet is transferred, this bit is cleared. The design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger this event when leaving suspend. This bit is used in conjunction with USBPHYx_DEBUG_HOST_RESUME_DEBUG.
        unsigned UTMI_SUSPENDM : 1; //!< Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required by the UTMI specification.
        unsigned CLKGATE : 1; //!< Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated.  Note this bit can be auto-cleared if there is any wakeup event when USB is suspended while ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
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

/* --- Register HW_USB_PHY_CTRL, field ENOTG_ID_CHG_IRQ
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
#define BW_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL, ENOTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENHOSTDISCONDETECT
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
#define BW_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   BF_CS1(USB_PHY_CTRL, ENHOSTDISCONDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQHOSTDISCON
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
#define BW_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   BF_CS1(USB_PHY_CTRL, ENIRQHOSTDISCON, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field HOSTDISCONDETECT_IRQ
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
#define BW_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   BF_CS1(USB_PHY_CTRL, HOSTDISCONDETECT_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENDEVPLUGINDETECT
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
#define BW_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   BF_CS1(USB_PHY_CTRL, ENDEVPLUGINDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DEVPLUGIN_POLARITY
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
#define BW_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   BF_CS1(USB_PHY_CTRL, DEVPLUGIN_POLARITY, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field OTG_ID_CHG_IRQ
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
#define BW_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL, OTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENOTGIDDETECT
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
#define BW_USB_PHY_CTRL_ENOTGIDDETECT(v)   BF_CS1(USB_PHY_CTRL, ENOTGIDDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RESUMEIRQSTICKY
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
#define BW_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   BF_CS1(USB_PHY_CTRL, RESUMEIRQSTICKY, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQRESUMEDETECT
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
#define BW_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   BF_CS1(USB_PHY_CTRL, ENIRQRESUMEDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RESUME_IRQ
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
#define BW_USB_PHY_CTRL_RESUME_IRQ(v)   BF_CS1(USB_PHY_CTRL, RESUME_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQDEVPLUGIN
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
#define BW_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   BF_CS1(USB_PHY_CTRL, ENIRQDEVPLUGIN, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DEVPLUGIN_IRQ
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
#define BW_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   BF_CS1(USB_PHY_CTRL, DEVPLUGIN_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DATA_ON_LRADC
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
#define BW_USB_PHY_CTRL_DATA_ON_LRADC(v)   BF_CS1(USB_PHY_CTRL, DATA_ON_LRADC, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENUTMILEVEL2
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
#define BW_USB_PHY_CTRL_ENUTMILEVEL2(v)   BF_CS1(USB_PHY_CTRL, ENUTMILEVEL2, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENUTMILEVEL3
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
#define BW_USB_PHY_CTRL_ENUTMILEVEL3(v)   BF_CS1(USB_PHY_CTRL, ENUTMILEVEL3, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQWAKEUP
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
#define BW_USB_PHY_CTRL_ENIRQWAKEUP(v)   BF_CS1(USB_PHY_CTRL, ENIRQWAKEUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field WAKEUP_IRQ
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
#define BW_USB_PHY_CTRL_WAKEUP_IRQ(v)   BF_CS1(USB_PHY_CTRL, WAKEUP_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RSVD0
 *
 * Reserved.
 */

#define BP_USB_PHY_CTRL_RSVD0      18
#define BM_USB_PHY_CTRL_RSVD0      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_RSVD0(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_CTRL_RSVD0)
#else
#define BF_USB_PHY_CTRL_RSVD0(v)   (((v) << 18) & BM_USB_PHY_CTRL_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_RSVD0(v)   BF_CS1(USB_PHY_CTRL, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENAUTOCLR_CLKGATE
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
#define BW_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   BF_CS1(USB_PHY_CTRL, ENAUTOCLR_CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENAUTOCLR_PHY_PWD
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
#define BW_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   BF_CS1(USB_PHY_CTRL, ENAUTOCLR_PHY_PWD, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENDPDMCHG_WKUP
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
#define BW_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENDPDMCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIDCHG_WKUP
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
#define BW_USB_PHY_CTRL_ENIDCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENIDCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENVBUSCHG_WKUP
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
#define BW_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENVBUSCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field FSDLL_RST_EN
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
#define BW_USB_PHY_CTRL_FSDLL_RST_EN(v)   BF_CS1(USB_PHY_CTRL, FSDLL_RST_EN, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RSVD1
 *
 * Reserved.
 */

#define BP_USB_PHY_CTRL_RSVD1      25
#define BM_USB_PHY_CTRL_RSVD1      0x06000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_RSVD1(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_CTRL_RSVD1)
#else
#define BF_USB_PHY_CTRL_RSVD1(v)   (((v) << 25) & BM_USB_PHY_CTRL_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_RSVD1(v)   BF_CS1(USB_PHY_CTRL, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field OTG_ID_VALUE
 *
 * Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE
 * has debounce logic to filter the glitches on ID Pad.
 */

#define BP_USB_PHY_CTRL_OTG_ID_VALUE      27
#define BM_USB_PHY_CTRL_OTG_ID_VALUE      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_OTG_ID_VALUE(v)   ((((reg32_t) v) << 27) & BM_USB_PHY_CTRL_OTG_ID_VALUE)
#else
#define BF_USB_PHY_CTRL_OTG_ID_VALUE(v)   (((v) << 27) & BM_USB_PHY_CTRL_OTG_ID_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_OTG_ID_VALUE(v)   BF_CS1(USB_PHY_CTRL, OTG_ID_VALUE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field HOST_FORCE_LS_SE0
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
#define BW_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   BF_CS1(USB_PHY_CTRL, HOST_FORCE_LS_SE0, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field UTMI_SUSPENDM
 *
 * Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD
 * are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required
 * by the UTMI specification.
 */

#define BP_USB_PHY_CTRL_UTMI_SUSPENDM      29
#define BM_USB_PHY_CTRL_UTMI_SUSPENDM      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_UTMI_SUSPENDM(v)   ((((reg32_t) v) << 29) & BM_USB_PHY_CTRL_UTMI_SUSPENDM)
#else
#define BF_USB_PHY_CTRL_UTMI_SUSPENDM(v)   (((v) << 29) & BM_USB_PHY_CTRL_UTMI_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_UTMI_SUSPENDM(v)   BF_CS1(USB_PHY_CTRL, UTMI_SUSPENDM, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field CLKGATE
 *
 * Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while
 * the USB is not actively being used. Configuration state is kept while the clock is gated.  Note
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
#define BW_USB_PHY_CTRL_CLKGATE(v)   BF_CS1(USB_PHY_CTRL, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field SFTRST
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
#define BW_USB_PHY_CTRL_SFTRST(v)   BF_CS1(USB_PHY_CTRL, SFTRST, v)
#endif

/*!
 * @brief HW_USB_PHY_STATUS - USB PHY Status Register
 *
 * The USB PHY Status Register holds results of IRQ and other detects.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD0 : 3; //!< Reserved.
        unsigned HOSTDISCONDETECT_STATUS : 1; //!< Indicates that the device has disconnected while in high-speed host mode.
        unsigned RSVD1 : 2; //!< Reserved.
        unsigned DEVPLUGIN_STATUS : 1; //!< Indicates that the device has been connected on the USB_DP and USB_DM lines.
        unsigned RSVD2 : 1; //!< Reserved.
        unsigned OTGID_STATUS : 1; //!< Indicates the results of ID pin on MiniAB plug.  False (0) is when ID resistance is less than Ra_Plug_ID, indicating host (A) side.  True (1) is when ID resistance is greater than Rb_Plug_ID, indicating device (B) side.
        unsigned RSVD3 : 1; //!< Reserved.
        unsigned RESUME_STATUS : 1; //!< Indicates that the host is sending a wake-up after suspend and has triggered an interrupt.
        unsigned RSVD4 : 21; //!< Reserved.
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

/* --- Register HW_USB_PHY_STATUS, field RSVD0
 *
 * Reserved.
 */

#define BP_USB_PHY_STATUS_RSVD0      0
#define BM_USB_PHY_STATUS_RSVD0      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD0(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_STATUS_RSVD0)
#else
#define BF_USB_PHY_STATUS_RSVD0(v)   (((v) << 0) & BM_USB_PHY_STATUS_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD0(v)   BF_CS1(USB_PHY_STATUS, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field HOSTDISCONDETECT_STATUS
 *
 * Indicates that the device has disconnected while in high-speed host mode.
 */

#define BP_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS      3
#define BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS)
#else
#define BF_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS(v)   (((v) << 3) & BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS(v)   BF_CS1(USB_PHY_STATUS, HOSTDISCONDETECT_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RSVD1
 *
 * Reserved.
 */

#define BP_USB_PHY_STATUS_RSVD1      4
#define BM_USB_PHY_STATUS_RSVD1      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD1(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_STATUS_RSVD1)
#else
#define BF_USB_PHY_STATUS_RSVD1(v)   (((v) << 4) & BM_USB_PHY_STATUS_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD1(v)   BF_CS1(USB_PHY_STATUS, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field DEVPLUGIN_STATUS
 *
 * Indicates that the device has been connected on the USB_DP and USB_DM lines.
 */

#define BP_USB_PHY_STATUS_DEVPLUGIN_STATUS      6
#define BM_USB_PHY_STATUS_DEVPLUGIN_STATUS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_DEVPLUGIN_STATUS(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_STATUS_DEVPLUGIN_STATUS)
#else
#define BF_USB_PHY_STATUS_DEVPLUGIN_STATUS(v)   (((v) << 6) & BM_USB_PHY_STATUS_DEVPLUGIN_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_DEVPLUGIN_STATUS(v)   BF_CS1(USB_PHY_STATUS, DEVPLUGIN_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RSVD2
 *
 * Reserved.
 */

#define BP_USB_PHY_STATUS_RSVD2      7
#define BM_USB_PHY_STATUS_RSVD2      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD2(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_STATUS_RSVD2)
#else
#define BF_USB_PHY_STATUS_RSVD2(v)   (((v) << 7) & BM_USB_PHY_STATUS_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD2(v)   BF_CS1(USB_PHY_STATUS, RSVD2, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field OTGID_STATUS
 *
 * Indicates the results of ID pin on MiniAB plug.  False (0) is when ID resistance is less than
 * Ra_Plug_ID, indicating host (A) side.  True (1) is when ID resistance is greater than Rb_Plug_ID,
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
#define BW_USB_PHY_STATUS_OTGID_STATUS(v)   BF_CS1(USB_PHY_STATUS, OTGID_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RSVD3
 *
 * Reserved.
 */

#define BP_USB_PHY_STATUS_RSVD3      9
#define BM_USB_PHY_STATUS_RSVD3      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD3(v)   ((((reg32_t) v) << 9) & BM_USB_PHY_STATUS_RSVD3)
#else
#define BF_USB_PHY_STATUS_RSVD3(v)   (((v) << 9) & BM_USB_PHY_STATUS_RSVD3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD3(v)   BF_CS1(USB_PHY_STATUS, RSVD3, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RESUME_STATUS
 *
 * Indicates that the host is sending a wake-up after suspend and has triggered an interrupt.
 */

#define BP_USB_PHY_STATUS_RESUME_STATUS      10
#define BM_USB_PHY_STATUS_RESUME_STATUS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RESUME_STATUS(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_STATUS_RESUME_STATUS)
#else
#define BF_USB_PHY_STATUS_RESUME_STATUS(v)   (((v) << 10) & BM_USB_PHY_STATUS_RESUME_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RESUME_STATUS(v)   BF_CS1(USB_PHY_STATUS, RESUME_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RSVD4
 *
 * Reserved.
 */

#define BP_USB_PHY_STATUS_RSVD4      11
#define BM_USB_PHY_STATUS_RSVD4      0xfffff800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD4(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_STATUS_RSVD4)
#else
#define BF_USB_PHY_STATUS_RSVD4(v)   (((v) << 11) & BM_USB_PHY_STATUS_RSVD4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD4(v)   BF_CS1(USB_PHY_STATUS, RSVD4, v)
#endif

/*!
 * @brief HW_USB_PHY_DEBUG - USB PHY Debug Register
 *
 * This register is used to debug the USB PHY.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OTGIDPIOLOCK : 1; //!< Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power for the comparators that are used to determine the ID status.
        unsigned DEBUG_INTERFACE_HOLD : 1; //!< Use holding registers to assist in timing for external UTMI interface.
        unsigned HSTPULLDOWN : 2; //!< Set bit 3 to 1 to pull down 15-KOhm on USB_DP line.  Set bit 2 to 1 to pull down 15-KOhm on USB_DM line.  Clear to 0 to disable.
        unsigned ENHSTPULLDOWN : 2; //!< Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown.  Set bit 4 to 1 to override the control of the USB_DM 15-KOhm pulldown.  Clear to 0 to disable.
        unsigned RSVD0 : 2; //!< Reserved.
        unsigned TX2RXCOUNT : 4; //!< Delay in between the end of transmit to the beginning of receive. This is a Johnson count value and thus will count to 8.
        unsigned ENTX2RXCOUNT : 1; //!< Set this bit to allow a countdown to transition in between TX and RX.
        unsigned RSVD1 : 3; //!< Reserved.
        unsigned SQUELCHRESETCOUNT : 5; //!< Delay in between the detection of squelch to the reset of high-speed RX.
        unsigned RSVD2 : 3; //!< Reserved.
        unsigned ENSQUELCHRESET : 1; //!< Set bit to allow squelch to reset high-speed receive.
        unsigned SQUELCHRESETLENGTH : 4; //!< Duration of RESET in terms of the number of 480-MHz cycles.
        unsigned HOST_RESUME_DEBUG : 1; //!< Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
        unsigned CLKGATE : 1; //!< Gate Test Clocks.  Clear to 0 for running clocks.  Set to 1 to gate clocks. Set this to save power while the USB is not actively being used.  Configuration state is kept while the clock is gated.
        unsigned RSVD3 : 1; //!< Reserved.
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

/* --- Register HW_USB_PHY_DEBUG, field OTGIDPIOLOCK
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
#define BW_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   BF_CS1(USB_PHY_DEBUG, OTGIDPIOLOCK, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field DEBUG_INTERFACE_HOLD
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
#define BW_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   BF_CS1(USB_PHY_DEBUG, DEBUG_INTERFACE_HOLD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field HSTPULLDOWN
 *
 * Set bit 3 to 1 to pull down 15-KOhm on USB_DP line.  Set bit 2 to 1 to pull down 15-KOhm on
 * USB_DM line.  Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_HSTPULLDOWN      2
#define BM_USB_PHY_DEBUG_HSTPULLDOWN      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_HSTPULLDOWN(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_DEBUG_HSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_HSTPULLDOWN(v)   (((v) << 2) & BM_USB_PHY_DEBUG_HSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_HSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG, HSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENHSTPULLDOWN
 *
 * Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown.  Set bit 4 to 1 to
 * override the control of the USB_DM 15-KOhm pulldown.  Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_ENHSTPULLDOWN      4
#define BM_USB_PHY_DEBUG_ENHSTPULLDOWN      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   (((v) << 4) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG, ENHSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field RSVD0
 *
 * Reserved.
 */

#define BP_USB_PHY_DEBUG_RSVD0      6
#define BM_USB_PHY_DEBUG_RSVD0      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_RSVD0(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_DEBUG_RSVD0)
#else
#define BF_USB_PHY_DEBUG_RSVD0(v)   (((v) << 6) & BM_USB_PHY_DEBUG_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_RSVD0(v)   BF_CS1(USB_PHY_DEBUG, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field TX2RXCOUNT
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
#define BW_USB_PHY_DEBUG_TX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG, TX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENTX2RXCOUNT
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
#define BW_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG, ENTX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field RSVD1
 *
 * Reserved.
 */

#define BP_USB_PHY_DEBUG_RSVD1      13
#define BM_USB_PHY_DEBUG_RSVD1      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_RSVD1(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_DEBUG_RSVD1)
#else
#define BF_USB_PHY_DEBUG_RSVD1(v)   (((v) << 13) & BM_USB_PHY_DEBUG_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_RSVD1(v)   BF_CS1(USB_PHY_DEBUG, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field SQUELCHRESETCOUNT
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
#define BW_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   BF_CS1(USB_PHY_DEBUG, SQUELCHRESETCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field RSVD2
 *
 * Reserved.
 */

#define BP_USB_PHY_DEBUG_RSVD2      21
#define BM_USB_PHY_DEBUG_RSVD2      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_RSVD2(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_DEBUG_RSVD2)
#else
#define BF_USB_PHY_DEBUG_RSVD2(v)   (((v) << 21) & BM_USB_PHY_DEBUG_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_RSVD2(v)   BF_CS1(USB_PHY_DEBUG, RSVD2, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENSQUELCHRESET
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
#define BW_USB_PHY_DEBUG_ENSQUELCHRESET(v)   BF_CS1(USB_PHY_DEBUG, ENSQUELCHRESET, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field SQUELCHRESETLENGTH
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
#define BW_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   BF_CS1(USB_PHY_DEBUG, SQUELCHRESETLENGTH, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field HOST_RESUME_DEBUG
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
#define BW_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   BF_CS1(USB_PHY_DEBUG, HOST_RESUME_DEBUG, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field CLKGATE
 *
 * Gate Test Clocks.  Clear to 0 for running clocks.  Set to 1 to gate clocks. Set this to save
 * power while the USB is not actively being used.  Configuration state is kept while the clock is
 * gated.
 */

#define BP_USB_PHY_DEBUG_CLKGATE      30
#define BM_USB_PHY_DEBUG_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_DEBUG_CLKGATE)
#else
#define BF_USB_PHY_DEBUG_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_DEBUG_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_CLKGATE(v)   BF_CS1(USB_PHY_DEBUG, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field RSVD3
 *
 * Reserved.
 */

#define BP_USB_PHY_DEBUG_RSVD3      31
#define BM_USB_PHY_DEBUG_RSVD3      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_RSVD3(v)   ((((reg32_t) v) << 31) & BM_USB_PHY_DEBUG_RSVD3)
#else
#define BF_USB_PHY_DEBUG_RSVD3(v)   (((v) << 31) & BM_USB_PHY_DEBUG_RSVD3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_RSVD3(v)   BF_CS1(USB_PHY_DEBUG, RSVD3, v)
#endif

/*!
 * @brief HW_USB_PHY_DEBUG0_STATUS - UTMI Debug Status Register 0
 *
 * The UTMI Debug Status Register 0 holds multiple views for counters and status of state machines.
 * This is used in conjunction with the USBPHYx_DEBUG1_DBG_ADDRESS field to choose which function to
 * view. The default is described in the bit fields below and is used to count errors.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LOOP_BACK_FAIL_COUNT : 16; //!< Running count of the failed pseudo-random generator loopback.  Each time entering testmode, counter goes to 900D and will count up for every detected packet failure in digital/analog loopback tests.
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
#define HW_USB_PHY_DEBUG0_STATUS_WR(x, v)     (HW_USB_PHY_DEBUG0_STATUS(x).U = (v))
#define HW_USB_PHY_DEBUG0_STATUS_SET(x, v)    (HW_USB_PHY_DEBUG0_STATUS_WR(x, HW_USB_PHY_DEBUG0_STATUS_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG0_STATUS_CLR(x, v)    (HW_USB_PHY_DEBUG0_STATUS_WR(x, HW_USB_PHY_DEBUG0_STATUS_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG0_STATUS_TOG(x, v)    (HW_USB_PHY_DEBUG0_STATUS_WR(x, HW_USB_PHY_DEBUG0_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_DEBUG0_STATUS bitfields
 */

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field LOOP_BACK_FAIL_COUNT
 *
 * Running count of the failed pseudo-random generator loopback.  Each time entering testmode,
 * counter goes to 900D and will count up for every detected packet failure in digital/analog
 * loopback tests.
 */

#define BP_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT      0
#define BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT)
#else
#define BF_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(v)   (((v) << 0) & BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(v)   BF_CS1(USB_PHY_DEBUG0_STATUS, LOOP_BACK_FAIL_COUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field UTMI_RXERROR_FAIL_COUNT
 *
 * Running count of the UTMI_RXERROR.
 */

#define BP_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT      16
#define BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT      0x03ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT)
#else
#define BF_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(v)   (((v) << 16) & BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(v)   BF_CS1(USB_PHY_DEBUG0_STATUS, UTMI_RXERROR_FAIL_COUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field SQUELCH_COUNT
 *
 * Running count of the squelch reset instead of normal end for HS RX.
 */

#define BP_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT      26
#define BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT      0xfc000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT(v)   ((((reg32_t) v) << 26) & BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT)
#else
#define BF_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT(v)   (((v) << 26) & BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT(v)   BF_CS1(USB_PHY_DEBUG0_STATUS, SQUELCH_COUNT, v)
#endif

/*!
 * @brief HW_USB_PHY_DEBUG1 - UTMI Debug Status Register 1
 *
 * Chooses the muxing of the debug register to be shown in USBPHYx_DEBUG0_STATUS.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD0 : 13; //!< Reserved.  Note: This bit should remain clear.
        unsigned ENTAILADJVD : 2; //!< Delay increment of the rise of squelch:  00 = Delay is nominal  01 = Delay is +20%  10 = Delay is -20%  11 = Delay is -40%
        unsigned RSVD1 : 17; //!< Reserved.
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

/* --- Register HW_USB_PHY_DEBUG1, field RSVD0
 *
 * Reserved.  Note: This bit should remain clear.
 */

#define BP_USB_PHY_DEBUG1_RSVD0      0
#define BM_USB_PHY_DEBUG1_RSVD0      0x00001fff

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_RSVD0(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG1_RSVD0)
#else
#define BF_USB_PHY_DEBUG1_RSVD0(v)   (((v) << 0) & BM_USB_PHY_DEBUG1_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_RSVD0(v)   BF_CS1(USB_PHY_DEBUG1, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_DEBUG1, field ENTAILADJVD
 *
 * Delay increment of the rise of squelch:  00 = Delay is nominal  01 = Delay is +20%  10 = Delay is
 * -20%  11 = Delay is -40%
 */

#define BP_USB_PHY_DEBUG1_ENTAILADJVD      13
#define BM_USB_PHY_DEBUG1_ENTAILADJVD      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_ENTAILADJVD(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_DEBUG1_ENTAILADJVD)
#else
#define BF_USB_PHY_DEBUG1_ENTAILADJVD(v)   (((v) << 13) & BM_USB_PHY_DEBUG1_ENTAILADJVD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_ENTAILADJVD(v)   BF_CS1(USB_PHY_DEBUG1, ENTAILADJVD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG1, field RSVD1
 *
 * Reserved.
 */

#define BP_USB_PHY_DEBUG1_RSVD1      15
#define BM_USB_PHY_DEBUG1_RSVD1      0xffff8000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_RSVD1(v)   ((((reg32_t) v) << 15) & BM_USB_PHY_DEBUG1_RSVD1)
#else
#define BF_USB_PHY_DEBUG1_RSVD1(v)   (((v) << 15) & BM_USB_PHY_DEBUG1_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_RSVD1(v)   BF_CS1(USB_PHY_DEBUG1, RSVD1, v)
#endif

/*!
 * @brief HW_USB_PHY_VERSION - UTMI RTL Version
 *
 * Fields for RTL Version.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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
#define HW_USB_PHY_VERSION_WR(x, v)     (HW_USB_PHY_VERSION(x).U = (v))
#define HW_USB_PHY_VERSION_SET(x, v)    (HW_USB_PHY_VERSION_WR(x, HW_USB_PHY_VERSION_RD(x) |  (v)))
#define HW_USB_PHY_VERSION_CLR(x, v)    (HW_USB_PHY_VERSION_WR(x, HW_USB_PHY_VERSION_RD(x) & ~(v)))
#define HW_USB_PHY_VERSION_TOG(x, v)    (HW_USB_PHY_VERSION_WR(x, HW_USB_PHY_VERSION_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_VERSION bitfields
 */

/* --- Register HW_USB_PHY_VERSION, field STEP
 *
 * Fixed read-only value reflecting the stepping of the RTL version.
 */

#define BP_USB_PHY_VERSION_STEP      0
#define BM_USB_PHY_VERSION_STEP      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_VERSION_STEP(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_VERSION_STEP)
#else
#define BF_USB_PHY_VERSION_STEP(v)   (((v) << 0) & BM_USB_PHY_VERSION_STEP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_VERSION_STEP(v)   BF_CS1(USB_PHY_VERSION, STEP, v)
#endif

/* --- Register HW_USB_PHY_VERSION, field MINOR
 *
 * Fixed read-only value reflecting the MINOR field of the RTL version.
 */

#define BP_USB_PHY_VERSION_MINOR      16
#define BM_USB_PHY_VERSION_MINOR      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_VERSION_MINOR(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_VERSION_MINOR)
#else
#define BF_USB_PHY_VERSION_MINOR(v)   (((v) << 16) & BM_USB_PHY_VERSION_MINOR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_VERSION_MINOR(v)   BF_CS1(USB_PHY_VERSION, MINOR, v)
#endif

/* --- Register HW_USB_PHY_VERSION, field MAJOR
 *
 * Fixed read-only value reflecting the MAJOR field of the RTL version.
 */

#define BP_USB_PHY_VERSION_MAJOR      24
#define BM_USB_PHY_VERSION_MAJOR      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_VERSION_MAJOR(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_VERSION_MAJOR)
#else
#define BF_USB_PHY_VERSION_MAJOR(v)   (((v) << 24) & BM_USB_PHY_VERSION_MAJOR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_VERSION_MAJOR(v)   BF_CS1(USB_PHY_VERSION, MAJOR, v)
#endif



/*!
 * @brief All USB_PHY module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_usb_phy_pwd_t PWD; //!< USB PHY Power-Down Register
    reg32_t _reserved0[3];
    volatile hw_usb_phy_tx_t TX; //!< USB PHY Transmitter Control Register
    reg32_t _reserved1[3];
    volatile hw_usb_phy_rx_t RX; //!< USB PHY Receiver Control Register
    reg32_t _reserved2[3];
    volatile hw_usb_phy_ctrl_t CTRL; //!< USB PHY General Control Register
    reg32_t _reserved3[3];
    volatile hw_usb_phy_status_t STATUS; //!< USB PHY Status Register
    reg32_t _reserved4[3];
    volatile hw_usb_phy_debug_t DEBUG; //!< USB PHY Debug Register
    reg32_t _reserved5[3];
    volatile hw_usb_phy_debug0_status_t DEBUG0_STATUS; //!< UTMI Debug Status Register 0
    reg32_t _reserved6[3];
    volatile hw_usb_phy_debug1_t DEBUG1; //!< UTMI Debug Status Register 1
    reg32_t _reserved7[3];
    volatile hw_usb_phy_version_t VERSION; //!< UTMI RTL Version
} hw_usb_phy_t
#endif

//! @brief Macro to access all USB_PHY registers.
//! @param x USB_PHY instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USB_PHY(0)</code>.
#define HW_USB_PHY(x)     (*(volatile hw_usb_phy_t *) REGS_USB_PHY_BASE(x))


#endif // _USB_PHY_H
