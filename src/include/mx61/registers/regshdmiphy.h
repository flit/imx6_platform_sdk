/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _HDMI_PHY_H
#define _HDMI_PHY_H

#include "regs.h"

#ifndef REGS_HDMI_PHY_BASE
#define REGS_HDMI_PHY_BASE (REGS_BASE + 0x00000000)
#endif


/*!
 * @brief HW_HDMI_PHY_PWRCTRL - Power Control
 *
 * Register name : PWRCTRL  Access type : Read/write/override  Address : 0x00  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short CK_PWRON : 1; //!< Clock Power-On  This bit powers on or powers off the clock driver.
        unsigned short TX_PWRON2 : 1; //!< Transmitter Power-On 2  This bit powers on or powers off the transmitter driver for channel 2.
        unsigned short TX_PWRON1 : 1; //!< Transmitter Power-On 1  This bit powers on or powers off the transmitter driver for channel 1.
        unsigned short TX_PWRON0 : 1; //!< Transmitter Power-On 0  This bit powers on or powers off the transmitter driver for channel 0.
        unsigned short TX_PWRON : 1; //!< Transmitter Power-On  This bit enables users to power down the entire PHY through the I2C interface.
        unsigned short RESERVED0 : 10; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_pwrctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PWRCTRL register
 */
#define HW_HDMI_PHY_PWRCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PWRCTRL           (*(volatile hw_hdmi_phy_pwrctrl_t *) HW_HDMI_PHY_PWRCTRL_ADDR)
#define HW_HDMI_PHY_PWRCTRL_RD()      (HW_HDMI_PHY_PWRCTRL.U)
#define HW_HDMI_PHY_PWRCTRL_WR(v)     (HW_HDMI_PHY_PWRCTRL.U = (v))
#define HW_HDMI_PHY_PWRCTRL_SET(v)    (HW_HDMI_PHY_PWRCTRL_WR(HW_HDMI_PHY_PWRCTRL_RD() |  (v)))
#define HW_HDMI_PHY_PWRCTRL_CLR(v)    (HW_HDMI_PHY_PWRCTRL_WR(HW_HDMI_PHY_PWRCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_PWRCTRL_TOG(v)    (HW_HDMI_PHY_PWRCTRL_WR(HW_HDMI_PHY_PWRCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_PWRCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_PWRCTRL, field CK_PWRON
 *
 * Clock Power-On  This bit powers on or powers off the clock driver.
 */

#define BP_HDMI_PHY_PWRCTRL_CK_PWRON      0
#define BM_HDMI_PHY_PWRCTRL_CK_PWRON      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PWRCTRL_CK_PWRON(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_PWRCTRL_CK_PWRON)
#else
#define BF_HDMI_PHY_PWRCTRL_CK_PWRON(v)   (((v) << 0) & BM_HDMI_PHY_PWRCTRL_CK_PWRON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PWRCTRL_CK_PWRON(v)   BF_CS1(HDMI_PHY_PWRCTRL, CK_PWRON, v)
#endif

/* --- Register HW_HDMI_PHY_PWRCTRL, field TX_PWRON2
 *
 * Transmitter Power-On 2  This bit powers on or powers off the transmitter driver for channel 2.
 */

#define BP_HDMI_PHY_PWRCTRL_TX_PWRON2      1
#define BM_HDMI_PHY_PWRCTRL_TX_PWRON2      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON2(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_PWRCTRL_TX_PWRON2)
#else
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON2(v)   (((v) << 1) & BM_HDMI_PHY_PWRCTRL_TX_PWRON2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PWRCTRL_TX_PWRON2(v)   BF_CS1(HDMI_PHY_PWRCTRL, TX_PWRON2, v)
#endif

/* --- Register HW_HDMI_PHY_PWRCTRL, field TX_PWRON1
 *
 * Transmitter Power-On 1  This bit powers on or powers off the transmitter driver for channel 1.
 */

#define BP_HDMI_PHY_PWRCTRL_TX_PWRON1      2
#define BM_HDMI_PHY_PWRCTRL_TX_PWRON1      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON1(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_PWRCTRL_TX_PWRON1)
#else
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON1(v)   (((v) << 2) & BM_HDMI_PHY_PWRCTRL_TX_PWRON1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PWRCTRL_TX_PWRON1(v)   BF_CS1(HDMI_PHY_PWRCTRL, TX_PWRON1, v)
#endif

/* --- Register HW_HDMI_PHY_PWRCTRL, field TX_PWRON0
 *
 * Transmitter Power-On 0  This bit powers on or powers off the transmitter driver for channel 0.
 */

#define BP_HDMI_PHY_PWRCTRL_TX_PWRON0      3
#define BM_HDMI_PHY_PWRCTRL_TX_PWRON0      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON0(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_PWRCTRL_TX_PWRON0)
#else
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON0(v)   (((v) << 3) & BM_HDMI_PHY_PWRCTRL_TX_PWRON0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PWRCTRL_TX_PWRON0(v)   BF_CS1(HDMI_PHY_PWRCTRL, TX_PWRON0, v)
#endif

/* --- Register HW_HDMI_PHY_PWRCTRL, field TX_PWRON
 *
 * Transmitter Power-On  This bit enables users to power down the entire PHY through the I2C
 * interface.
 */

#define BP_HDMI_PHY_PWRCTRL_TX_PWRON      4
#define BM_HDMI_PHY_PWRCTRL_TX_PWRON      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_PWRCTRL_TX_PWRON)
#else
#define BF_HDMI_PHY_PWRCTRL_TX_PWRON(v)   (((v) << 4) & BM_HDMI_PHY_PWRCTRL_TX_PWRON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PWRCTRL_TX_PWRON(v)   BF_CS1(HDMI_PHY_PWRCTRL, TX_PWRON, v)
#endif

/* --- Register HW_HDMI_PHY_PWRCTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_PWRCTRL_OVERRIDE      15
#define BM_HDMI_PHY_PWRCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PWRCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_PWRCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_PWRCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_PWRCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PWRCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_PWRCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SERDIVCTRL - Serializer Divider Control
 *
 * Register name : SERDIVCTRL  Access type : Read/write/override  Address : 0x01  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short TX_SER_DIV_EN2 : 1; //!< Transmitter Serializer Divider Enable 2  This bit enables or disables the low-speed clock in serializer 2.
        unsigned short TX_SER_DIV_EN1 : 1; //!< Transmitter Serializer Divider Enable 1  This bit enables or disables the low-speed clock in serializer 1.
        unsigned short TX_SER_DIV_EN0 : 1; //!< Transmitter Serializer Divider Enable 0  This bit enables or disables the low-speed clock in serializer 0.
        unsigned short RESERVED0 : 12; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_serdivctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SERDIVCTRL register
 */
#define HW_HDMI_PHY_SERDIVCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SERDIVCTRL           (*(volatile hw_hdmi_phy_serdivctrl_t *) HW_HDMI_PHY_SERDIVCTRL_ADDR)
#define HW_HDMI_PHY_SERDIVCTRL_RD()      (HW_HDMI_PHY_SERDIVCTRL.U)
#define HW_HDMI_PHY_SERDIVCTRL_WR(v)     (HW_HDMI_PHY_SERDIVCTRL.U = (v))
#define HW_HDMI_PHY_SERDIVCTRL_SET(v)    (HW_HDMI_PHY_SERDIVCTRL_WR(HW_HDMI_PHY_SERDIVCTRL_RD() |  (v)))
#define HW_HDMI_PHY_SERDIVCTRL_CLR(v)    (HW_HDMI_PHY_SERDIVCTRL_WR(HW_HDMI_PHY_SERDIVCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_SERDIVCTRL_TOG(v)    (HW_HDMI_PHY_SERDIVCTRL_WR(HW_HDMI_PHY_SERDIVCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SERDIVCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_SERDIVCTRL, field TX_SER_DIV_EN2
 *
 * Transmitter Serializer Divider Enable 2  This bit enables or disables the low-speed clock in
 * serializer 2.
 */

#define BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2      0
#define BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2)
#else
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2(v)   (((v) << 0) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN2(v)   BF_CS1(HDMI_PHY_SERDIVCTRL, TX_SER_DIV_EN2, v)
#endif

/* --- Register HW_HDMI_PHY_SERDIVCTRL, field TX_SER_DIV_EN1
 *
 * Transmitter Serializer Divider Enable 1  This bit enables or disables the low-speed clock in
 * serializer 1.
 */

#define BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1      1
#define BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1)
#else
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1(v)   (((v) << 1) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN1(v)   BF_CS1(HDMI_PHY_SERDIVCTRL, TX_SER_DIV_EN1, v)
#endif

/* --- Register HW_HDMI_PHY_SERDIVCTRL, field TX_SER_DIV_EN0
 *
 * Transmitter Serializer Divider Enable 0  This bit enables or disables the low-speed clock in
 * serializer 0.
 */

#define BP_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0      2
#define BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0)
#else
#define BF_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0(v)   (((v) << 2) & BM_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERDIVCTRL_TX_SER_DIV_EN0(v)   BF_CS1(HDMI_PHY_SERDIVCTRL, TX_SER_DIV_EN0, v)
#endif

/* --- Register HW_HDMI_PHY_SERDIVCTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_SERDIVCTRL_OVERRIDE      15
#define BM_HDMI_PHY_SERDIVCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERDIVCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_SERDIVCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_SERDIVCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_SERDIVCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERDIVCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_SERDIVCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SERCKCTRL - Serializer Clock Control
 *
 * Register name : SERCKCTRL  Access type : Read/write/override  Address : 0x02  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short TX_SER_CLK_EN2 : 1; //!< Transmitter Serializer Clock Enable 2  This bit enables or disables the high-speed clock in serializer two.
        unsigned short TX_SER_CLK_EN1 : 1; //!< Transmitter Serializer Clock Enable 1  This bit enables or disables the high-speed clock in serializer 1.
        unsigned short TX_SER_CLK_EN0 : 1; //!< Transmitter Serializer Clock Enable 0  This bit enables or disables the high-speed clock in serializer 0.
        unsigned short RESERVED0 : 12; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_serckctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SERCKCTRL register
 */
#define HW_HDMI_PHY_SERCKCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SERCKCTRL           (*(volatile hw_hdmi_phy_serckctrl_t *) HW_HDMI_PHY_SERCKCTRL_ADDR)
#define HW_HDMI_PHY_SERCKCTRL_RD()      (HW_HDMI_PHY_SERCKCTRL.U)
#define HW_HDMI_PHY_SERCKCTRL_WR(v)     (HW_HDMI_PHY_SERCKCTRL.U = (v))
#define HW_HDMI_PHY_SERCKCTRL_SET(v)    (HW_HDMI_PHY_SERCKCTRL_WR(HW_HDMI_PHY_SERCKCTRL_RD() |  (v)))
#define HW_HDMI_PHY_SERCKCTRL_CLR(v)    (HW_HDMI_PHY_SERCKCTRL_WR(HW_HDMI_PHY_SERCKCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_SERCKCTRL_TOG(v)    (HW_HDMI_PHY_SERCKCTRL_WR(HW_HDMI_PHY_SERCKCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SERCKCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_SERCKCTRL, field TX_SER_CLK_EN2
 *
 * Transmitter Serializer Clock Enable 2  This bit enables or disables the high-speed clock in
 * serializer two.
 */

#define BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2      0
#define BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2)
#else
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2(v)   (((v) << 0) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN2(v)   BF_CS1(HDMI_PHY_SERCKCTRL, TX_SER_CLK_EN2, v)
#endif

/* --- Register HW_HDMI_PHY_SERCKCTRL, field TX_SER_CLK_EN1
 *
 * Transmitter Serializer Clock Enable 1  This bit enables or disables the high-speed clock in
 * serializer 1.
 */

#define BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1      1
#define BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1)
#else
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1(v)   (((v) << 1) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN1(v)   BF_CS1(HDMI_PHY_SERCKCTRL, TX_SER_CLK_EN1, v)
#endif

/* --- Register HW_HDMI_PHY_SERCKCTRL, field TX_SER_CLK_EN0
 *
 * Transmitter Serializer Clock Enable 0  This bit enables or disables the high-speed clock in
 * serializer 0.
 */

#define BP_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0      2
#define BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0)
#else
#define BF_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0(v)   (((v) << 2) & BM_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERCKCTRL_TX_SER_CLK_EN0(v)   BF_CS1(HDMI_PHY_SERCKCTRL, TX_SER_CLK_EN0, v)
#endif

/* --- Register HW_HDMI_PHY_SERCKCTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_SERCKCTRL_OVERRIDE      15
#define BM_HDMI_PHY_SERCKCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERCKCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_SERCKCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_SERCKCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_SERCKCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERCKCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_SERCKCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SERCKKILLCTRL - Serializer Clock Kill Control
 *
 * Register name : SERCKKILLCTRL  Access type : Read/write/override  Address : 0x03  Value at reset
 * : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short TX_SER_CLK_KILL2 : 1; //!< Transmitter Serializer Clock Kill 2  This bit is used to delay the tx_ck_out2 sampling clock by a time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of the tx_ck_out2 clock.
        unsigned short TX_SER_CLK_KILL1 : 1; //!< Transmitter Serializer Clock Kill 1  This bit is used to delay the tx_ck_out1 sampling clock by a time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of the tx_ck_out1 clock.
        unsigned short TX_SER_CLK_KILL0 : 1; //!< Transmitter Serializer Clock Kill 0  This bit is used to delay the tx_ck_out0 sampling clock by a time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of the tx_ck_out0 clock.
        unsigned short RESERVED0 : 12; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_serckkillctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SERCKKILLCTRL register
 */
#define HW_HDMI_PHY_SERCKKILLCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SERCKKILLCTRL           (*(volatile hw_hdmi_phy_serckkillctrl_t *) HW_HDMI_PHY_SERCKKILLCTRL_ADDR)
#define HW_HDMI_PHY_SERCKKILLCTRL_RD()      (HW_HDMI_PHY_SERCKKILLCTRL.U)
#define HW_HDMI_PHY_SERCKKILLCTRL_WR(v)     (HW_HDMI_PHY_SERCKKILLCTRL.U = (v))
#define HW_HDMI_PHY_SERCKKILLCTRL_SET(v)    (HW_HDMI_PHY_SERCKKILLCTRL_WR(HW_HDMI_PHY_SERCKKILLCTRL_RD() |  (v)))
#define HW_HDMI_PHY_SERCKKILLCTRL_CLR(v)    (HW_HDMI_PHY_SERCKKILLCTRL_WR(HW_HDMI_PHY_SERCKKILLCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_SERCKKILLCTRL_TOG(v)    (HW_HDMI_PHY_SERCKKILLCTRL_WR(HW_HDMI_PHY_SERCKKILLCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SERCKKILLCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_SERCKKILLCTRL, field TX_SER_CLK_KILL2
 *
 * Transmitter Serializer Clock Kill 2  This bit is used to delay the tx_ck_out2 sampling clock by a
 * time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of
 * the tx_ck_out2 clock.
 */

#define BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2      0
#define BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2)
#else
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2(v)   (((v) << 0) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL2(v)   BF_CS1(HDMI_PHY_SERCKKILLCTRL, TX_SER_CLK_KILL2, v)
#endif

/* --- Register HW_HDMI_PHY_SERCKKILLCTRL, field TX_SER_CLK_KILL1
 *
 * Transmitter Serializer Clock Kill 1  This bit is used to delay the tx_ck_out1 sampling clock by a
 * time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of
 * the tx_ck_out1 clock.
 */

#define BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1      1
#define BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1)
#else
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1(v)   (((v) << 1) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL1(v)   BF_CS1(HDMI_PHY_SERCKKILLCTRL, TX_SER_CLK_KILL1, v)
#endif

/* --- Register HW_HDMI_PHY_SERCKKILLCTRL, field TX_SER_CLK_KILL0
 *
 * Transmitter Serializer Clock Kill 0  This bit is used to delay the tx_ck_out0 sampling clock by a
 * time t delay , where t delay equals one period of refclk (340 MHz). This delay equals 0.2 UI of
 * the tx_ck_out0 clock.
 */

#define BP_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0      2
#define BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0)
#else
#define BF_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0(v)   (((v) << 2) & BM_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERCKKILLCTRL_TX_SER_CLK_KILL0(v)   BF_CS1(HDMI_PHY_SERCKKILLCTRL, TX_SER_CLK_KILL0, v)
#endif

/* --- Register HW_HDMI_PHY_SERCKKILLCTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_SERCKKILLCTRL_OVERRIDE      15
#define BM_HDMI_PHY_SERCKKILLCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SERCKKILLCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_SERCKKILLCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_SERCKKILLCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_SERCKKILLCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SERCKKILLCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_SERCKKILLCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_TXRESCTRL - Transmitter and Resistance Calibration Control
 *
 * Register name : TXRESCALCTRL  Access type : Read/write/override  Address : 0x04  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short RESCAL_REP : 7; //!< Resistance Calibration Replica  This bus controls the bias voltage of the transmitter driver. rescal_rep[6:0]  provides 64 voltage levels; the specific values are defined from lab test results.
        unsigned short TX_RESCAL : 7; //!< Transmitter Resistance Calibration  This bus controls the parallel termination of the transmitter drivers and sets termination to a value based on the calibration algorithm performed in the support resistance calibration module. tx_rescal[6:0] provides 64 termination levels; the specific values are defined from lab test results.
        unsigned short RESERVED0 : 1; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_txresctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TXRESCTRL register
 */
#define HW_HDMI_PHY_TXRESCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TXRESCTRL           (*(volatile hw_hdmi_phy_txresctrl_t *) HW_HDMI_PHY_TXRESCTRL_ADDR)
#define HW_HDMI_PHY_TXRESCTRL_RD()      (HW_HDMI_PHY_TXRESCTRL.U)
#define HW_HDMI_PHY_TXRESCTRL_WR(v)     (HW_HDMI_PHY_TXRESCTRL.U = (v))
#define HW_HDMI_PHY_TXRESCTRL_SET(v)    (HW_HDMI_PHY_TXRESCTRL_WR(HW_HDMI_PHY_TXRESCTRL_RD() |  (v)))
#define HW_HDMI_PHY_TXRESCTRL_CLR(v)    (HW_HDMI_PHY_TXRESCTRL_WR(HW_HDMI_PHY_TXRESCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_TXRESCTRL_TOG(v)    (HW_HDMI_PHY_TXRESCTRL_WR(HW_HDMI_PHY_TXRESCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_TXRESCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_TXRESCTRL, field RESCAL_REP
 *
 * Resistance Calibration Replica  This bus controls the bias voltage of the transmitter driver.
 * rescal_rep[6:0]  provides 64 voltage levels; the specific values are defined from lab test
 * results.
 */

#define BP_HDMI_PHY_TXRESCTRL_RESCAL_REP      0
#define BM_HDMI_PHY_TXRESCTRL_RESCAL_REP      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TXRESCTRL_RESCAL_REP(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_TXRESCTRL_RESCAL_REP)
#else
#define BF_HDMI_PHY_TXRESCTRL_RESCAL_REP(v)   (((v) << 0) & BM_HDMI_PHY_TXRESCTRL_RESCAL_REP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_TXRESCTRL_RESCAL_REP(v)   BF_CS1(HDMI_PHY_TXRESCTRL, RESCAL_REP, v)
#endif

/* --- Register HW_HDMI_PHY_TXRESCTRL, field TX_RESCAL
 *
 * Transmitter Resistance Calibration  This bus controls the parallel termination of the transmitter
 * drivers and sets termination to a value based on the calibration algorithm performed in the
 * support resistance calibration module. tx_rescal[6:0] provides 64 termination levels; the
 * specific values are defined from lab test results.
 */

#define BP_HDMI_PHY_TXRESCTRL_TX_RESCAL      7
#define BM_HDMI_PHY_TXRESCTRL_TX_RESCAL      0x00003f80

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TXRESCTRL_TX_RESCAL(v)   ((((reg32_t) v) << 7) & BM_HDMI_PHY_TXRESCTRL_TX_RESCAL)
#else
#define BF_HDMI_PHY_TXRESCTRL_TX_RESCAL(v)   (((v) << 7) & BM_HDMI_PHY_TXRESCTRL_TX_RESCAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_TXRESCTRL_TX_RESCAL(v)   BF_CS1(HDMI_PHY_TXRESCTRL, TX_RESCAL, v)
#endif

/* --- Register HW_HDMI_PHY_TXRESCTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_TXRESCTRL_OVERRIDE      15
#define BM_HDMI_PHY_TXRESCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TXRESCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_TXRESCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_TXRESCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_TXRESCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_TXRESCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_TXRESCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_CKCALCTRL - Clock Calibration Control
 *
 * Register name : CKCALCTRL  Access type : Read/write/override  Address : 0x05  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short CK_RESCAL : 7; //!< Clock Resistance Calibration  This bus controls the termination of the clock driver and sets the termination to a value based on the calibration algorithm performed in the support resistance calibration module. ck_rescal[6:0] provides 64 termination levels; the specific values are defined from lab test results.
        unsigned short RESERVED0 : 8; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_ckcalctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CKCALCTRL register
 */
#define HW_HDMI_PHY_CKCALCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CKCALCTRL           (*(volatile hw_hdmi_phy_ckcalctrl_t *) HW_HDMI_PHY_CKCALCTRL_ADDR)
#define HW_HDMI_PHY_CKCALCTRL_RD()      (HW_HDMI_PHY_CKCALCTRL.U)
#define HW_HDMI_PHY_CKCALCTRL_WR(v)     (HW_HDMI_PHY_CKCALCTRL.U = (v))
#define HW_HDMI_PHY_CKCALCTRL_SET(v)    (HW_HDMI_PHY_CKCALCTRL_WR(HW_HDMI_PHY_CKCALCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CKCALCTRL_CLR(v)    (HW_HDMI_PHY_CKCALCTRL_WR(HW_HDMI_PHY_CKCALCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CKCALCTRL_TOG(v)    (HW_HDMI_PHY_CKCALCTRL_WR(HW_HDMI_PHY_CKCALCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_CKCALCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CKCALCTRL, field CK_RESCAL
 *
 * Clock Resistance Calibration  This bus controls the termination of the clock driver and sets the
 * termination to a value based on the calibration algorithm performed in the support resistance
 * calibration module. ck_rescal[6:0] provides 64 termination levels; the specific values are
 * defined from lab test results.
 */

#define BP_HDMI_PHY_CKCALCTRL_CK_RESCAL      0
#define BM_HDMI_PHY_CKCALCTRL_CK_RESCAL      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CKCALCTRL_CK_RESCAL(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_CKCALCTRL_CK_RESCAL)
#else
#define BF_HDMI_PHY_CKCALCTRL_CK_RESCAL(v)   (((v) << 0) & BM_HDMI_PHY_CKCALCTRL_CK_RESCAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CKCALCTRL_CK_RESCAL(v)   BF_CS1(HDMI_PHY_CKCALCTRL, CK_RESCAL, v)
#endif

/* --- Register HW_HDMI_PHY_CKCALCTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_CKCALCTRL_OVERRIDE      15
#define BM_HDMI_PHY_CKCALCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CKCALCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_CKCALCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_CKCALCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_CKCALCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CKCALCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_CKCALCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_CPCE_CTRL - Color Depth, Pixel Repetition, Clock Divider for PLL and MPLL, and Edge Rate Control
 *
 * Register name : -  Access type : Read/write  Address : 0x06  Value at reset : 0x0400
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short CLR_DPTH : 2; //!< Color Depth  This bus controls the factor by which to divide the reference clock (PCLK) by the output TMDS rate (ck_ref_mpll_p/m).
        unsigned short PIXEL_REP : 3; //!< Pixel Repetition  This bus controls another factor by which to divide the input frequency (refclk) by the output TMDS rate (ck_ref_mpll_p/m).  FTMDS/Fin = (clr_depth[1:0] x pixel_rep[2]) / (pixel_rep[1:0])
        unsigned short PLL_N_CNTRL : 2; //!< Programmable Divider Control  This bus controls the programmable divider modules, which are set based on the refclk_p/m (pixel rate) input reference frequency to keep the ring oscillator within the required range (740 MHz through 1.48 GHz in PLL).
        unsigned short MPLL_N_CNTRL : 2; //!< Programmable Divider Control  This bus controls the programmable divider modulus, which are set based on the ck_ref_mpll_p/m (TMDS rate) input reference frequency to keep the ring oscillator within the required range (925 MHz through 1.85 GHz in MPLL).
        unsigned short CK_EDGERATE : 2; //!< Clock Edge Rate  This bus controls the slew rate of the clock output driver.
        unsigned short TX_EDGERATE : 2; //!< Transmitter Edge Rate  This bus controls the slew rate of the transmitter output driver.
        unsigned short PREP_DIV : 2; //!< Digital Pixel Repetition Divider Controls the ratio by which the internal TMDS clock is divided to generate PREPCLK.
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_phy_cpce_ctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CPCE_CTRL register
 */
#define HW_HDMI_PHY_CPCE_CTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CPCE_CTRL           (*(volatile hw_hdmi_phy_cpce_ctrl_t *) HW_HDMI_PHY_CPCE_CTRL_ADDR)
#define HW_HDMI_PHY_CPCE_CTRL_RD()      (HW_HDMI_PHY_CPCE_CTRL.U)
#define HW_HDMI_PHY_CPCE_CTRL_WR(v)     (HW_HDMI_PHY_CPCE_CTRL.U = (v))
#define HW_HDMI_PHY_CPCE_CTRL_SET(v)    (HW_HDMI_PHY_CPCE_CTRL_WR(HW_HDMI_PHY_CPCE_CTRL_RD() |  (v)))
#define HW_HDMI_PHY_CPCE_CTRL_CLR(v)    (HW_HDMI_PHY_CPCE_CTRL_WR(HW_HDMI_PHY_CPCE_CTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CPCE_CTRL_TOG(v)    (HW_HDMI_PHY_CPCE_CTRL_WR(HW_HDMI_PHY_CPCE_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_CPCE_CTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CPCE_CTRL, field CLR_DPTH
 *
 * Color Depth  This bus controls the factor by which to divide the reference clock (PCLK) by the
 * output TMDS rate (ck_ref_mpll_p/m).
 */

#define BP_HDMI_PHY_CPCE_CTRL_CLR_DPTH      0
#define BM_HDMI_PHY_CPCE_CTRL_CLR_DPTH      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CPCE_CTRL_CLR_DPTH(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_CPCE_CTRL_CLR_DPTH)
#else
#define BF_HDMI_PHY_CPCE_CTRL_CLR_DPTH(v)   (((v) << 0) & BM_HDMI_PHY_CPCE_CTRL_CLR_DPTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CPCE_CTRL_CLR_DPTH(v)   BF_CS1(HDMI_PHY_CPCE_CTRL, CLR_DPTH, v)
#endif

/* --- Register HW_HDMI_PHY_CPCE_CTRL, field PIXEL_REP
 *
 * Pixel Repetition  This bus controls another factor by which to divide the input frequency
 * (refclk) by the output TMDS rate (ck_ref_mpll_p/m).  FTMDS/Fin = (clr_depth[1:0] x pixel_rep[2])
 * / (pixel_rep[1:0])
 */

#define BP_HDMI_PHY_CPCE_CTRL_PIXEL_REP      2
#define BM_HDMI_PHY_CPCE_CTRL_PIXEL_REP      0x0000001c

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CPCE_CTRL_PIXEL_REP(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_CPCE_CTRL_PIXEL_REP)
#else
#define BF_HDMI_PHY_CPCE_CTRL_PIXEL_REP(v)   (((v) << 2) & BM_HDMI_PHY_CPCE_CTRL_PIXEL_REP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CPCE_CTRL_PIXEL_REP(v)   BF_CS1(HDMI_PHY_CPCE_CTRL, PIXEL_REP, v)
#endif

/* --- Register HW_HDMI_PHY_CPCE_CTRL, field PLL_N_CNTRL
 *
 * Programmable Divider Control  This bus controls the programmable divider modules, which are set
 * based on the refclk_p/m (pixel rate) input reference frequency to keep the ring oscillator within
 * the required range (740 MHz through 1.48 GHz in PLL).
 */

#define BP_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL      5
#define BM_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL)
#else
#define BF_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL(v)   (((v) << 5) & BM_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CPCE_CTRL_PLL_N_CNTRL(v)   BF_CS1(HDMI_PHY_CPCE_CTRL, PLL_N_CNTRL, v)
#endif

/* --- Register HW_HDMI_PHY_CPCE_CTRL, field MPLL_N_CNTRL
 *
 * Programmable Divider Control  This bus controls the programmable divider modulus, which are set
 * based on the ck_ref_mpll_p/m (TMDS rate) input reference frequency to keep the ring oscillator
 * within the required range (925 MHz through 1.85 GHz in MPLL).
 */

#define BP_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL      7
#define BM_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL      0x00000180

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL(v)   ((((reg32_t) v) << 7) & BM_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL)
#else
#define BF_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL(v)   (((v) << 7) & BM_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CPCE_CTRL_MPLL_N_CNTRL(v)   BF_CS1(HDMI_PHY_CPCE_CTRL, MPLL_N_CNTRL, v)
#endif

/* --- Register HW_HDMI_PHY_CPCE_CTRL, field CK_EDGERATE
 *
 * Clock Edge Rate  This bus controls the slew rate of the clock output driver.
 */

#define BP_HDMI_PHY_CPCE_CTRL_CK_EDGERATE      9
#define BM_HDMI_PHY_CPCE_CTRL_CK_EDGERATE      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CPCE_CTRL_CK_EDGERATE(v)   ((((reg32_t) v) << 9) & BM_HDMI_PHY_CPCE_CTRL_CK_EDGERATE)
#else
#define BF_HDMI_PHY_CPCE_CTRL_CK_EDGERATE(v)   (((v) << 9) & BM_HDMI_PHY_CPCE_CTRL_CK_EDGERATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CPCE_CTRL_CK_EDGERATE(v)   BF_CS1(HDMI_PHY_CPCE_CTRL, CK_EDGERATE, v)
#endif

/* --- Register HW_HDMI_PHY_CPCE_CTRL, field TX_EDGERATE
 *
 * Transmitter Edge Rate  This bus controls the slew rate of the transmitter output driver.
 */

#define BP_HDMI_PHY_CPCE_CTRL_TX_EDGERATE      11
#define BM_HDMI_PHY_CPCE_CTRL_TX_EDGERATE      0x00001800

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CPCE_CTRL_TX_EDGERATE(v)   ((((reg32_t) v) << 11) & BM_HDMI_PHY_CPCE_CTRL_TX_EDGERATE)
#else
#define BF_HDMI_PHY_CPCE_CTRL_TX_EDGERATE(v)   (((v) << 11) & BM_HDMI_PHY_CPCE_CTRL_TX_EDGERATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CPCE_CTRL_TX_EDGERATE(v)   BF_CS1(HDMI_PHY_CPCE_CTRL, TX_EDGERATE, v)
#endif

/* --- Register HW_HDMI_PHY_CPCE_CTRL, field PREP_DIV
 *
 * Digital Pixel Repetition Divider Controls the ratio by which the internal TMDS clock is divided
 * to generate PREPCLK.
 */

#define BP_HDMI_PHY_CPCE_CTRL_PREP_DIV      13
#define BM_HDMI_PHY_CPCE_CTRL_PREP_DIV      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CPCE_CTRL_PREP_DIV(v)   ((((reg32_t) v) << 13) & BM_HDMI_PHY_CPCE_CTRL_PREP_DIV)
#else
#define BF_HDMI_PHY_CPCE_CTRL_PREP_DIV(v)   (((v) << 13) & BM_HDMI_PHY_CPCE_CTRL_PREP_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CPCE_CTRL_PREP_DIV(v)   BF_CS1(HDMI_PHY_CPCE_CTRL, PREP_DIV, v)
#endif

/*!
 * @brief HW_HDMI_PHY_TXCLKMEASCTRL - Tx and Clock Measure Control
 *
 * Register name : TXCKMEASCTRL  Access type : Read/write  Address : 0x07  Value at reset : 0x0000
 * tx_meas_iv2[7:0]        Effective Bit  Register Value  Description    tx_meas_iv2[0]  00000001
 * Connect V cm_p (common DC voltage of the positive side of scope) to the analog test bus.
 * tx_meas_iv2[1]  00000010  Connect V cm_m (common DC voltage of the negative side of scope) to the
 * analog test bus.    tx_meas_iv2[2]  00000100  Connect V bg3by4_reg (output node of tx_vreg_vbgby2
 * block) to the analog test bus.    tx_meas_iv2[3]  00001000  Connect t x_vref (reference voltage
 * of tx_biasgen block) to the analog test bus.    tx_meas_iv2[4]  00010000  Connect V rep_fb
 * (feedback voltage of the replica circuit of tx_biasgen block) to the analog test bus.
 * tx_meas_iv2[5]  00100000  In the event that bleed current is too large, this bit can be used to
 * force vb closer to gnd and disable/reduce the bleed current. (This bit is a debug feature, which
 * does not pull vb to gnd properly.)    tx_meas_iv2[6]  01000000  Connect V p (low power supply) to
 * the analog test bus.    tx_meas_iv2[7]  10000000  Connect V cm (common DC voltage of the scope)
 * to the analog test bus.       ck_meas_iv[7:0]        Effective Bit  Register Value  Description
 * ck_meas_iv[0]  00000001  Connect V cm_p (common DC voltage of the positive side of scope) to the
 * analog test bus.    ck_meas_iv[1]  00000010  Connect V cm_m (common DC voltage of the negative
 * side of scope) to the analog test bus.    ck_meas_iv[2]  00000100  Connect V bg3by4_reg (output
 * node of tx_vreg_vbgby2 block) to the analog test bus.    ck_meas_iv[3]  00001000  Connect t
 * x_vref (reference voltage of tx_biasgen block) to the analog test bus.    ck_meas_iv[4]  00010000
 * Connect V rep_fb (feedback voltage of the replica circuit of tx_biasgen block) to the analog test
 * bus.    ck_meas_iv[5]  00100000  In the event that bleed current is too large, this bit can be
 * used to force v b closer to gnd and disable/reduce the bleed current. (This bit is a debug
 * feature, which does not pull v b to gnd properly.)    ck_meas_iv[6]  01000000  Connect V p (low
 * power supply) to the analog test bus.    ck_meas_iv[7]  10000000  Connect V cm (common DC voltage
 * of scope) to the analog test bus.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short CK_MEAS_IV : 8; //!< Clock Measure Internal Voltage  This bus is used to test specific voltages for the clock lane/channel by applying voltages on the atb_sense port based on configured currents, as described in the ck_meas_iv[7:0] table.
        unsigned short TX_MEAS_IV2 : 8; //!< Transmitter Measure Internal Voltage 2  This bus is used to test specific voltages for third transmitter lane/channel by applying voltages on the atb_sense port based on configured currents, as described in the tx_meas_iv2[7:0] table.
    } B;
} hw_hdmi_phy_txclkmeasctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TXCLKMEASCTRL register
 */
#define HW_HDMI_PHY_TXCLKMEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TXCLKMEASCTRL           (*(volatile hw_hdmi_phy_txclkmeasctrl_t *) HW_HDMI_PHY_TXCLKMEASCTRL_ADDR)
#define HW_HDMI_PHY_TXCLKMEASCTRL_RD()      (HW_HDMI_PHY_TXCLKMEASCTRL.U)
#define HW_HDMI_PHY_TXCLKMEASCTRL_WR(v)     (HW_HDMI_PHY_TXCLKMEASCTRL.U = (v))
#define HW_HDMI_PHY_TXCLKMEASCTRL_SET(v)    (HW_HDMI_PHY_TXCLKMEASCTRL_WR(HW_HDMI_PHY_TXCLKMEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_TXCLKMEASCTRL_CLR(v)    (HW_HDMI_PHY_TXCLKMEASCTRL_WR(HW_HDMI_PHY_TXCLKMEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_TXCLKMEASCTRL_TOG(v)    (HW_HDMI_PHY_TXCLKMEASCTRL_WR(HW_HDMI_PHY_TXCLKMEASCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_TXCLKMEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_TXCLKMEASCTRL, field CK_MEAS_IV
 *
 * Clock Measure Internal Voltage  This bus is used to test specific voltages for the clock
 * lane/channel by applying voltages on the atb_sense port based on configured currents, as
 * described in the ck_meas_iv[7:0] table.
 */

#define BP_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV      0
#define BM_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV)
#else
#define BF_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV(v)   (((v) << 0) & BM_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_TXCLKMEASCTRL_CK_MEAS_IV(v)   BF_CS1(HDMI_PHY_TXCLKMEASCTRL, CK_MEAS_IV, v)
#endif

/* --- Register HW_HDMI_PHY_TXCLKMEASCTRL, field TX_MEAS_IV2
 *
 * Transmitter Measure Internal Voltage 2  This bus is used to test specific voltages for third
 * transmitter lane/channel by applying voltages on the atb_sense port based on configured currents,
 * as described in the tx_meas_iv2[7:0] table.
 */

#define BP_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2      8
#define BM_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2(v)   ((((reg32_t) v) << 8) & BM_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2)
#else
#define BF_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2(v)   (((v) << 8) & BM_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_TXCLKMEASCTRL_TX_MEAS_IV2(v)   BF_CS1(HDMI_PHY_TXCLKMEASCTRL, TX_MEAS_IV2, v)
#endif

/*!
 * @brief HW_HDMI_PHY_TXMEASCTRL - Tx Measure Control
 *
 * Register name : TXMEASCTRL  Access type : Read/write  Address : 0x08  Value at reset : 0x0000
 * tx_meas_iv1[7:0]        Effective Bit  Register Value  Description    tx_meas_iv1[0]  00000001
 * Connect V cm_p (common DC voltage of positive side of scope) to the analog test bus.
 * tx_meas_iv1[1]  00000010  Connect V cm_m (common DC voltage of negative side of scope) to the
 * analog test bus.    tx_meas_iv1[2]  00000100  Connect V bg3by4_reg (output node of tx_vreg_vbgby2
 * block) to the analog test bus.    tx_meas_iv1[3]  00001000  Connect t x_vref (reference voltage
 * of tx_biasgen block) to the analog test bus.    tx_meas_iv1[4]  00010000  Connect V rep_fb
 * (feedback voltage of replica circuit of tx_biasgen block) to the analog test bus.
 * tx_meas_iv1[5]  00100000  In case bleed current is too large, this bit can be used to force v b
 * closer to gnd and disable/reduce the bleed current. (This bit is a debug feature, which does not
 * pull v b to gnd properly.)    tx_meas_iv1[6]  01000000  Connect V p (low power supply) to the
 * analog test bus.    tx_meas_iv1[7]  10000000  Connect V cm (common DC voltage of scope) to the
 * analog test bus.       tx_meas_iv0[7:0]        Effective Bit  Register Value  Description
 * tx_meas_iv0[0]  00000001  Connect V cm_p (common DC voltage of positive side of scope) to the
 * analog test bus.    tx_meas_iv0[1]  00000010  Connect V cm_m (common DC voltage of negative side
 * of scope) to the analog test bus.    tx_meas_iv0[2]  00000100  Connect V bg3by4_reg (output node
 * of tx_vreg_vbgby2 block) to the analog test bus.    tx_meas_iv0[3]  00001000  Connect t x_vref
 * (reference voltage of tx_biasgen block) to the analog test bus    tx_meas_iv0[4]  00010000
 * Connect V rep_fb (feedback voltage of replica circuit of tx_biasgen block) to the analog test
 * bus.    tx_meas_iv0[5]  00100000  In the event that bleed current is too large, this bit can be
 * used to force v b closer to gnd and disable/reduce the bleed current. (This bit is a debug
 * feature, which does not pull v b to gnd properly.)    tx_meas_iv0[6]  01000000  Connect V p (low
 * power supply) to the analog test bus.    tx_meas_iv0[7]  10000000  Connect V cm (common DC
 * voltage of scope) to the analog test bus.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short TX_MEAS_IV1 : 8; //!< Transmitter Measure Internal Voltage 1  This bus is used to test specific voltages for the second transmitter lane/channel by applying voltages on the atb_sense port based on configured currents, as described in the tx_meas_iv1[7:0] table.
        unsigned short TX_MEAS_IV0 : 8; //!< Transmitter Measure Internal Voltage 0  This bus is used to test specific voltages for the first transmitter lane/channel by applying voltages on the atb_sense port based on configured currents, as described in the tx_meas_iv0[7:0] table.
    } B;
} hw_hdmi_phy_txmeasctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TXMEASCTRL register
 */
#define HW_HDMI_PHY_TXMEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TXMEASCTRL           (*(volatile hw_hdmi_phy_txmeasctrl_t *) HW_HDMI_PHY_TXMEASCTRL_ADDR)
#define HW_HDMI_PHY_TXMEASCTRL_RD()      (HW_HDMI_PHY_TXMEASCTRL.U)
#define HW_HDMI_PHY_TXMEASCTRL_WR(v)     (HW_HDMI_PHY_TXMEASCTRL.U = (v))
#define HW_HDMI_PHY_TXMEASCTRL_SET(v)    (HW_HDMI_PHY_TXMEASCTRL_WR(HW_HDMI_PHY_TXMEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_TXMEASCTRL_CLR(v)    (HW_HDMI_PHY_TXMEASCTRL_WR(HW_HDMI_PHY_TXMEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_TXMEASCTRL_TOG(v)    (HW_HDMI_PHY_TXMEASCTRL_WR(HW_HDMI_PHY_TXMEASCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_TXMEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_TXMEASCTRL, field TX_MEAS_IV1
 *
 * Transmitter Measure Internal Voltage 1  This bus is used to test specific voltages for the second
 * transmitter lane/channel by applying voltages on the atb_sense port based on configured currents,
 * as described in the tx_meas_iv1[7:0] table.
 */

#define BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1      0
#define BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1)
#else
#define BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1(v)   (((v) << 0) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV1(v)   BF_CS1(HDMI_PHY_TXMEASCTRL, TX_MEAS_IV1, v)
#endif

/* --- Register HW_HDMI_PHY_TXMEASCTRL, field TX_MEAS_IV0
 *
 * Transmitter Measure Internal Voltage 0  This bus is used to test specific voltages for the first
 * transmitter lane/channel by applying voltages on the atb_sense port based on configured currents,
 * as described in the tx_meas_iv0[7:0] table.
 */

#define BP_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0      8
#define BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0(v)   ((((reg32_t) v) << 8) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0)
#else
#define BF_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0(v)   (((v) << 8) & BM_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_TXMEASCTRL_TX_MEAS_IV0(v)   BF_CS1(HDMI_PHY_TXMEASCTRL, TX_MEAS_IV0, v)
#endif

/*!
 * @brief HW_HDMI_PHY_CKSYMTXCTRL - Clock Symbol and Transmitter Control
 *
 * Register name : CKSYMTXCTRL  Access type : Read/write/override  Address : 0x09  Value at reset :
 * 0x0009
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short CK_SYMON : 1; //!< Clock Symbol On  This bit enables the clock symbol driver. To enable the clock driver, the ck_powon bit must be high. In addition, there is no pre-emphasis enable for the clock driver.
        unsigned short TX_TRBON : 1; //!< Transmitter Trailer B On  This bit enables the transmitter trailer B driver(s). To enable the transmitter trailer B driver(s) and to enable pre-emphasis, the tx_pwron bit for each channel must be high.
        unsigned short TX_TRAON : 1; //!< Transmitter Trailer A On  This bit enables the transmitter trailer A driver(s). To enable the transmitter trailer A driver(s) and to enable pre-emphasis, the tx_pwron bit for each channel must be high.
        unsigned short TX_SYMON : 1; //!< Transmitter Symbol On  This bit enables the transmitter symbol driver(s), To enable the transmitter driver(s), the tx_pwron bit for each channel must be high.
        unsigned short RESERVED0 : 11; //!< Reserved
        unsigned short OVERRIDE : 1; //!< 
    } B;
} hw_hdmi_phy_cksymtxctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CKSYMTXCTRL register
 */
#define HW_HDMI_PHY_CKSYMTXCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CKSYMTXCTRL           (*(volatile hw_hdmi_phy_cksymtxctrl_t *) HW_HDMI_PHY_CKSYMTXCTRL_ADDR)
#define HW_HDMI_PHY_CKSYMTXCTRL_RD()      (HW_HDMI_PHY_CKSYMTXCTRL.U)
#define HW_HDMI_PHY_CKSYMTXCTRL_WR(v)     (HW_HDMI_PHY_CKSYMTXCTRL.U = (v))
#define HW_HDMI_PHY_CKSYMTXCTRL_SET(v)    (HW_HDMI_PHY_CKSYMTXCTRL_WR(HW_HDMI_PHY_CKSYMTXCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CKSYMTXCTRL_CLR(v)    (HW_HDMI_PHY_CKSYMTXCTRL_WR(HW_HDMI_PHY_CKSYMTXCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CKSYMTXCTRL_TOG(v)    (HW_HDMI_PHY_CKSYMTXCTRL_WR(HW_HDMI_PHY_CKSYMTXCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_CKSYMTXCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field CK_SYMON
 *
 * Clock Symbol On  This bit enables the clock symbol driver. To enable the clock driver, the
 * ck_powon bit must be high. In addition, there is no pre-emphasis enable for the clock driver.
 */

#define BP_HDMI_PHY_CKSYMTXCTRL_CK_SYMON      0
#define BM_HDMI_PHY_CKSYMTXCTRL_CK_SYMON      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CKSYMTXCTRL_CK_SYMON(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_CKSYMTXCTRL_CK_SYMON)
#else
#define BF_HDMI_PHY_CKSYMTXCTRL_CK_SYMON(v)   (((v) << 0) & BM_HDMI_PHY_CKSYMTXCTRL_CK_SYMON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CKSYMTXCTRL_CK_SYMON(v)   BF_CS1(HDMI_PHY_CKSYMTXCTRL, CK_SYMON, v)
#endif

/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field TX_TRBON
 *
 * Transmitter Trailer B On  This bit enables the transmitter trailer B driver(s). To enable the
 * transmitter trailer B driver(s) and to enable pre-emphasis, the tx_pwron bit for each channel
 * must be high.
 */

#define BP_HDMI_PHY_CKSYMTXCTRL_TX_TRBON      1
#define BM_HDMI_PHY_CKSYMTXCTRL_TX_TRBON      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_TRBON(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRBON)
#else
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_TRBON(v)   (((v) << 1) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRBON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CKSYMTXCTRL_TX_TRBON(v)   BF_CS1(HDMI_PHY_CKSYMTXCTRL, TX_TRBON, v)
#endif

/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field TX_TRAON
 *
 * Transmitter Trailer A On  This bit enables the transmitter trailer A driver(s). To enable the
 * transmitter trailer A driver(s) and to enable pre-emphasis, the tx_pwron bit for each channel
 * must be high.
 */

#define BP_HDMI_PHY_CKSYMTXCTRL_TX_TRAON      2
#define BM_HDMI_PHY_CKSYMTXCTRL_TX_TRAON      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_TRAON(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRAON)
#else
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_TRAON(v)   (((v) << 2) & BM_HDMI_PHY_CKSYMTXCTRL_TX_TRAON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CKSYMTXCTRL_TX_TRAON(v)   BF_CS1(HDMI_PHY_CKSYMTXCTRL, TX_TRAON, v)
#endif

/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field TX_SYMON
 *
 * Transmitter Symbol On  This bit enables the transmitter symbol driver(s), To enable the
 * transmitter driver(s), the tx_pwron bit for each channel must be high.
 */

#define BP_HDMI_PHY_CKSYMTXCTRL_TX_SYMON      3
#define BM_HDMI_PHY_CKSYMTXCTRL_TX_SYMON      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_SYMON(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_CKSYMTXCTRL_TX_SYMON)
#else
#define BF_HDMI_PHY_CKSYMTXCTRL_TX_SYMON(v)   (((v) << 3) & BM_HDMI_PHY_CKSYMTXCTRL_TX_SYMON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CKSYMTXCTRL_TX_SYMON(v)   BF_CS1(HDMI_PHY_CKSYMTXCTRL, TX_SYMON, v)
#endif

/* --- Register HW_HDMI_PHY_CKSYMTXCTRL, field OVERRIDE
 *

 */

#define BP_HDMI_PHY_CKSYMTXCTRL_OVERRIDE      15
#define BM_HDMI_PHY_CKSYMTXCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CKSYMTXCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_CKSYMTXCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_CKSYMTXCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_CKSYMTXCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CKSYMTXCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_CKSYMTXCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_CMPSEQCTRL - Comparator Sequence Control
 *
 * Register name : CMPSEQCTRL  Access type : Read/write/override  Address : 0x0A  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SUP_COMP_RT_R : 1; //!< Support Comparator Resistance Termination  This bit controls the comparator sequence.
        unsigned short RESERVED0 : 14; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_cmpseqctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CMPSEQCTRL register
 */
#define HW_HDMI_PHY_CMPSEQCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xa)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CMPSEQCTRL           (*(volatile hw_hdmi_phy_cmpseqctrl_t *) HW_HDMI_PHY_CMPSEQCTRL_ADDR)
#define HW_HDMI_PHY_CMPSEQCTRL_RD()      (HW_HDMI_PHY_CMPSEQCTRL.U)
#define HW_HDMI_PHY_CMPSEQCTRL_WR(v)     (HW_HDMI_PHY_CMPSEQCTRL.U = (v))
#define HW_HDMI_PHY_CMPSEQCTRL_SET(v)    (HW_HDMI_PHY_CMPSEQCTRL_WR(HW_HDMI_PHY_CMPSEQCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CMPSEQCTRL_CLR(v)    (HW_HDMI_PHY_CMPSEQCTRL_WR(HW_HDMI_PHY_CMPSEQCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CMPSEQCTRL_TOG(v)    (HW_HDMI_PHY_CMPSEQCTRL_WR(HW_HDMI_PHY_CMPSEQCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_CMPSEQCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CMPSEQCTRL, field SUP_COMP_RT_R
 *
 * Support Comparator Resistance Termination  This bit controls the comparator sequence.
 */

#define BP_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R      0
#define BM_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R)
#else
#define BF_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R(v)   (((v) << 0) & BM_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CMPSEQCTRL_SUP_COMP_RT_R(v)   BF_CS1(HDMI_PHY_CMPSEQCTRL, SUP_COMP_RT_R, v)
#endif

/* --- Register HW_HDMI_PHY_CMPSEQCTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_CMPSEQCTRL_OVERRIDE      15
#define BM_HDMI_PHY_CMPSEQCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CMPSEQCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_CMPSEQCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_CMPSEQCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_CMPSEQCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CMPSEQCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_CMPSEQCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_CMPPWRCTRL - Comparator Power Control
 *
 * Register name : CMPPWRCTRL  Access type : Read/write/override  Address : 0x0B  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SUP_COMP_RT_PWRON : 1; //!< Support Comparator Resistance Termination Power-On  This bit powers on the Comparator module.
        unsigned short RESERVED0 : 14; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_cmppwrctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CMPPWRCTRL register
 */
#define HW_HDMI_PHY_CMPPWRCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xb)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CMPPWRCTRL           (*(volatile hw_hdmi_phy_cmppwrctrl_t *) HW_HDMI_PHY_CMPPWRCTRL_ADDR)
#define HW_HDMI_PHY_CMPPWRCTRL_RD()      (HW_HDMI_PHY_CMPPWRCTRL.U)
#define HW_HDMI_PHY_CMPPWRCTRL_WR(v)     (HW_HDMI_PHY_CMPPWRCTRL.U = (v))
#define HW_HDMI_PHY_CMPPWRCTRL_SET(v)    (HW_HDMI_PHY_CMPPWRCTRL_WR(HW_HDMI_PHY_CMPPWRCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CMPPWRCTRL_CLR(v)    (HW_HDMI_PHY_CMPPWRCTRL_WR(HW_HDMI_PHY_CMPPWRCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CMPPWRCTRL_TOG(v)    (HW_HDMI_PHY_CMPPWRCTRL_WR(HW_HDMI_PHY_CMPPWRCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_CMPPWRCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CMPPWRCTRL, field SUP_COMP_RT_PWRON
 *
 * Support Comparator Resistance Termination Power-On  This bit powers on the Comparator module.
 */

#define BP_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON      0
#define BM_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON)
#else
#define BF_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON(v)   (((v) << 0) & BM_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CMPPWRCTRL_SUP_COMP_RT_PWRON(v)   BF_CS1(HDMI_PHY_CMPPWRCTRL, SUP_COMP_RT_PWRON, v)
#endif

/* --- Register HW_HDMI_PHY_CMPPWRCTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_CMPPWRCTRL_OVERRIDE      15
#define BM_HDMI_PHY_CMPPWRCTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CMPPWRCTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_CMPPWRCTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_CMPPWRCTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_CMPPWRCTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CMPPWRCTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_CMPPWRCTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_CMPMODECTRL - Comparator Mode Control
 *
 * Register name : CMPMODECTRL  Access type : Read/write/override  Address : 0x0C  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SUP_COMP_MODE : 1; //!< Support Comparator Mode  This bit selects the comparator mode.
        unsigned short RESERVED0 : 14; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_cmpmodectrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CMPMODECTRL register
 */
#define HW_HDMI_PHY_CMPMODECTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CMPMODECTRL           (*(volatile hw_hdmi_phy_cmpmodectrl_t *) HW_HDMI_PHY_CMPMODECTRL_ADDR)
#define HW_HDMI_PHY_CMPMODECTRL_RD()      (HW_HDMI_PHY_CMPMODECTRL.U)
#define HW_HDMI_PHY_CMPMODECTRL_WR(v)     (HW_HDMI_PHY_CMPMODECTRL.U = (v))
#define HW_HDMI_PHY_CMPMODECTRL_SET(v)    (HW_HDMI_PHY_CMPMODECTRL_WR(HW_HDMI_PHY_CMPMODECTRL_RD() |  (v)))
#define HW_HDMI_PHY_CMPMODECTRL_CLR(v)    (HW_HDMI_PHY_CMPMODECTRL_WR(HW_HDMI_PHY_CMPMODECTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CMPMODECTRL_TOG(v)    (HW_HDMI_PHY_CMPMODECTRL_WR(HW_HDMI_PHY_CMPMODECTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_CMPMODECTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CMPMODECTRL, field SUP_COMP_MODE
 *
 * Support Comparator Mode  This bit selects the comparator mode.
 */

#define BP_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE      0
#define BM_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE)
#else
#define BF_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE(v)   (((v) << 0) & BM_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CMPMODECTRL_SUP_COMP_MODE(v)   BF_CS1(HDMI_PHY_CMPMODECTRL, SUP_COMP_MODE, v)
#endif

/* --- Register HW_HDMI_PHY_CMPMODECTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_CMPMODECTRL_OVERRIDE      15
#define BM_HDMI_PHY_CMPMODECTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CMPMODECTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_CMPMODECTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_CMPMODECTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_CMPMODECTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CMPMODECTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_CMPMODECTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_MEASCTRL - Measure Control
 *
 * Register name : MEASCTRL  Access type : Read/write  Address : 0x0D  Value at reset : 0x0000  Two
 * or more of the previous register bits must not be set to 1 simultaneously; doing so can lead to a
 * hardware problem.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SUP_DAC_ON_ATB : 1; //!< Support Digital-to-Analog Converter On Analog Test Bus  This bit connects or disconnects the DAC's output on the analog test bus to test the performance of the DAC through Integral Non-Linearity (INL) and Differential Non-Linearity (DNL).
        unsigned short SUP_POR_MEAS_IV : 2; //!< Support Power Measure Internal Voltage  This bus connects or disconnects a single output signal on the analog test bus to measure the voltage of two nodes of the support power block.
        unsigned short SUP_ATB_ON_REXT : 1; //!< Support Analog Test Bus On External Calibration Resistance  This bit connects or disconnects the V rext node to/from the analog test bus.
        unsigned short RESERVED0 : 12; //!< Reserved
    } B;
} hw_hdmi_phy_measctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_MEASCTRL register
 */
#define HW_HDMI_PHY_MEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_MEASCTRL           (*(volatile hw_hdmi_phy_measctrl_t *) HW_HDMI_PHY_MEASCTRL_ADDR)
#define HW_HDMI_PHY_MEASCTRL_RD()      (HW_HDMI_PHY_MEASCTRL.U)
#define HW_HDMI_PHY_MEASCTRL_WR(v)     (HW_HDMI_PHY_MEASCTRL.U = (v))
#define HW_HDMI_PHY_MEASCTRL_SET(v)    (HW_HDMI_PHY_MEASCTRL_WR(HW_HDMI_PHY_MEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_MEASCTRL_CLR(v)    (HW_HDMI_PHY_MEASCTRL_WR(HW_HDMI_PHY_MEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_MEASCTRL_TOG(v)    (HW_HDMI_PHY_MEASCTRL_WR(HW_HDMI_PHY_MEASCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_MEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_MEASCTRL, field SUP_DAC_ON_ATB
 *
 * Support Digital-to-Analog Converter On Analog Test Bus  This bit connects or disconnects the
 * DAC's output on the analog test bus to test the performance of the DAC through Integral Non-
 * Linearity (INL) and Differential Non-Linearity (DNL).
 */

#define BP_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB      0
#define BM_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB)
#else
#define BF_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB(v)   (((v) << 0) & BM_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MEASCTRL_SUP_DAC_ON_ATB(v)   BF_CS1(HDMI_PHY_MEASCTRL, SUP_DAC_ON_ATB, v)
#endif

/* --- Register HW_HDMI_PHY_MEASCTRL, field SUP_POR_MEAS_IV
 *
 * Support Power Measure Internal Voltage  This bus connects or disconnects a single output signal
 * on the analog test bus to measure the voltage of two nodes of the support power block.
 */

#define BP_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV      1
#define BM_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV)
#else
#define BF_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV(v)   (((v) << 1) & BM_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MEASCTRL_SUP_POR_MEAS_IV(v)   BF_CS1(HDMI_PHY_MEASCTRL, SUP_POR_MEAS_IV, v)
#endif

/* --- Register HW_HDMI_PHY_MEASCTRL, field SUP_ATB_ON_REXT
 *
 * Support Analog Test Bus On External Calibration Resistance  This bit connects or disconnects the
 * V rext node to/from the analog test bus.
 */

#define BP_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT      3
#define BM_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT)
#else
#define BF_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT(v)   (((v) << 3) & BM_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MEASCTRL_SUP_ATB_ON_REXT(v)   BF_CS1(HDMI_PHY_MEASCTRL, SUP_ATB_ON_REXT, v)
#endif

/*!
 * @brief HW_HDMI_PHY_VLEVCTRL - Voltage Level Control
 *
 * Register name : VLEVCTRL  Access type : Read/write  Address : 0x0E  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SUP_CK_LVL : 5; //!< Support Clock Level  This bus controls the reference voltage level of the Clock Channel module. This voltage reference has a direct relation with the output signal voltage level. For more information about the driver voltage level configuration, see .
        unsigned short SUP_TX_LVL : 5; //!< Support Transmitter Level  This bus controls the reference voltage level of the three transmitter channel modules. This voltage reference has a direct relation with the output signal voltage level. For more information about the driver voltage level configuration, see .
        unsigned short RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_phy_vlevctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_VLEVCTRL register
 */
#define HW_HDMI_PHY_VLEVCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xe)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_VLEVCTRL           (*(volatile hw_hdmi_phy_vlevctrl_t *) HW_HDMI_PHY_VLEVCTRL_ADDR)
#define HW_HDMI_PHY_VLEVCTRL_RD()      (HW_HDMI_PHY_VLEVCTRL.U)
#define HW_HDMI_PHY_VLEVCTRL_WR(v)     (HW_HDMI_PHY_VLEVCTRL.U = (v))
#define HW_HDMI_PHY_VLEVCTRL_SET(v)    (HW_HDMI_PHY_VLEVCTRL_WR(HW_HDMI_PHY_VLEVCTRL_RD() |  (v)))
#define HW_HDMI_PHY_VLEVCTRL_CLR(v)    (HW_HDMI_PHY_VLEVCTRL_WR(HW_HDMI_PHY_VLEVCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_VLEVCTRL_TOG(v)    (HW_HDMI_PHY_VLEVCTRL_WR(HW_HDMI_PHY_VLEVCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_VLEVCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_VLEVCTRL, field SUP_CK_LVL
 *
 * Support Clock Level  This bus controls the reference voltage level of the Clock Channel module.
 * This voltage reference has a direct relation with the output signal voltage level. For more
 * information about the driver voltage level configuration, see .
 */

#define BP_HDMI_PHY_VLEVCTRL_SUP_CK_LVL      0
#define BM_HDMI_PHY_VLEVCTRL_SUP_CK_LVL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_VLEVCTRL_SUP_CK_LVL(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_VLEVCTRL_SUP_CK_LVL)
#else
#define BF_HDMI_PHY_VLEVCTRL_SUP_CK_LVL(v)   (((v) << 0) & BM_HDMI_PHY_VLEVCTRL_SUP_CK_LVL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_VLEVCTRL_SUP_CK_LVL(v)   BF_CS1(HDMI_PHY_VLEVCTRL, SUP_CK_LVL, v)
#endif

/* --- Register HW_HDMI_PHY_VLEVCTRL, field SUP_TX_LVL
 *
 * Support Transmitter Level  This bus controls the reference voltage level of the three transmitter
 * channel modules. This voltage reference has a direct relation with the output signal voltage
 * level. For more information about the driver voltage level configuration, see .
 */

#define BP_HDMI_PHY_VLEVCTRL_SUP_TX_LVL      5
#define BM_HDMI_PHY_VLEVCTRL_SUP_TX_LVL      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_VLEVCTRL_SUP_TX_LVL(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_VLEVCTRL_SUP_TX_LVL)
#else
#define BF_HDMI_PHY_VLEVCTRL_SUP_TX_LVL(v)   (((v) << 5) & BM_HDMI_PHY_VLEVCTRL_SUP_TX_LVL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_VLEVCTRL_SUP_TX_LVL(v)   BF_CS1(HDMI_PHY_VLEVCTRL, SUP_TX_LVL, v)
#endif

/*!
 * @brief HW_HDMI_PHY_D2ACTRL - Digital-to-Analog Control
 *
 * Register name : D2ACTRL  Access type : Read/write/override  Address : 0x0F  Value at reset :
 * 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SUP_DAC_TH_N : 3; //!< Support Digital-to-Analog Thermometer Inverted  This bus value is inverted and defined in the thermometer code to represent the binary code of the two MSB's of the 9-bit DAC value.  Note : To increase the stability of the DAC block, the two MSB's of the 9-bit DAC value are represented in thermometer code, not in binary code. The MSB's of the 9-bit DAC value is split into two thermometer-code bits. A transition from 0 to 1 of the 9-bit DAC value's MSB is represented by "00" -> "01" -> "11" in thermometer code.
        unsigned short SUP_DAC_N : 8; //!< Support Analog-to-Digital Inverted  This bus represents the LSB's of the 9-bit DAC value.
        unsigned short RESERVED0 : 4; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_d2actrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_D2ACTRL register
 */
#define HW_HDMI_PHY_D2ACTRL_ADDR      (REGS_HDMI_PHY_BASE + 0xf)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_D2ACTRL           (*(volatile hw_hdmi_phy_d2actrl_t *) HW_HDMI_PHY_D2ACTRL_ADDR)
#define HW_HDMI_PHY_D2ACTRL_RD()      (HW_HDMI_PHY_D2ACTRL.U)
#define HW_HDMI_PHY_D2ACTRL_WR(v)     (HW_HDMI_PHY_D2ACTRL.U = (v))
#define HW_HDMI_PHY_D2ACTRL_SET(v)    (HW_HDMI_PHY_D2ACTRL_WR(HW_HDMI_PHY_D2ACTRL_RD() |  (v)))
#define HW_HDMI_PHY_D2ACTRL_CLR(v)    (HW_HDMI_PHY_D2ACTRL_WR(HW_HDMI_PHY_D2ACTRL_RD() & ~(v)))
#define HW_HDMI_PHY_D2ACTRL_TOG(v)    (HW_HDMI_PHY_D2ACTRL_WR(HW_HDMI_PHY_D2ACTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_D2ACTRL bitfields
 */

/* --- Register HW_HDMI_PHY_D2ACTRL, field SUP_DAC_TH_N
 *
 * Support Digital-to-Analog Thermometer Inverted  This bus value is inverted and defined in the
 * thermometer code to represent the binary code of the two MSB's of the 9-bit DAC value.  Note : To
 * increase the stability of the DAC block, the two MSB's of the 9-bit DAC value are represented in
 * thermometer code, not in binary code. The MSB's of the 9-bit DAC value is split into two
 * thermometer-code bits. A transition from 0 to 1 of the 9-bit DAC value's MSB is represented by
 * "00" -> "01" -> "11" in thermometer code.
 */

#define BP_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N      0
#define BM_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N)
#else
#define BF_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N(v)   (((v) << 0) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_D2ACTRL_SUP_DAC_TH_N(v)   BF_CS1(HDMI_PHY_D2ACTRL, SUP_DAC_TH_N, v)
#endif

/* --- Register HW_HDMI_PHY_D2ACTRL, field SUP_DAC_N
 *
 * Support Analog-to-Digital Inverted  This bus represents the LSB's of the 9-bit DAC value.
 */

#define BP_HDMI_PHY_D2ACTRL_SUP_DAC_N      3
#define BM_HDMI_PHY_D2ACTRL_SUP_DAC_N      0x000007f8

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_D2ACTRL_SUP_DAC_N(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_N)
#else
#define BF_HDMI_PHY_D2ACTRL_SUP_DAC_N(v)   (((v) << 3) & BM_HDMI_PHY_D2ACTRL_SUP_DAC_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_D2ACTRL_SUP_DAC_N(v)   BF_CS1(HDMI_PHY_D2ACTRL, SUP_DAC_N, v)
#endif

/* --- Register HW_HDMI_PHY_D2ACTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_D2ACTRL_OVERRIDE      15
#define BM_HDMI_PHY_D2ACTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_D2ACTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_D2ACTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_D2ACTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_D2ACTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_D2ACTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_D2ACTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_CURRCTRL - Current Control
 *
 * Register name : CURRCTRL  Access type : Read/write  Address : 0x10  Value at reset : 0x08AB
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short PLL_INT_CNTRL : 3; //!< PLL Charge Pump Integral Control  This bus controls the PLL charge pump integral current. Eight levels of charge pump integral current value are possible. The specific values are defined in .  Default (reset) value of pll_int_cntrl[2:0] is 100.
        unsigned short PLL_PROP_CNTRL : 3; //!< PLL Proportional Control  This bus controls the PLL charge pump proportional current. Eight levels of charge pump proportional current value are possible. The specific values are defined in .  Default (reset) value of pll_int_cntrl is 011.
        unsigned short MPLL_INT_CNTRL : 3; //!< MPLL Integral Control  This bus controls the charge pump integral current. Eight levels of charge pump integral current value are possible. The specific values are defined in .  Default (reset) value of pll_int_cntrl[1:0] is 100.
        unsigned short MPLL_PROP_CNTRL : 3; //!< MPLL Proportional Control  This bus controls the MPLL charge pump proportional current. Eight levels of charge pump proportional current value are possible. The specific values are defined in .  Default (reset) value of pll_prop_cntrl[1:0] is 100.
        unsigned short RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_phy_currctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CURRCTRL register
 */
#define HW_HDMI_PHY_CURRCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CURRCTRL           (*(volatile hw_hdmi_phy_currctrl_t *) HW_HDMI_PHY_CURRCTRL_ADDR)
#define HW_HDMI_PHY_CURRCTRL_RD()      (HW_HDMI_PHY_CURRCTRL.U)
#define HW_HDMI_PHY_CURRCTRL_WR(v)     (HW_HDMI_PHY_CURRCTRL.U = (v))
#define HW_HDMI_PHY_CURRCTRL_SET(v)    (HW_HDMI_PHY_CURRCTRL_WR(HW_HDMI_PHY_CURRCTRL_RD() |  (v)))
#define HW_HDMI_PHY_CURRCTRL_CLR(v)    (HW_HDMI_PHY_CURRCTRL_WR(HW_HDMI_PHY_CURRCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_CURRCTRL_TOG(v)    (HW_HDMI_PHY_CURRCTRL_WR(HW_HDMI_PHY_CURRCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_CURRCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_CURRCTRL, field PLL_INT_CNTRL
 *
 * PLL Charge Pump Integral Control  This bus controls the PLL charge pump integral current. Eight
 * levels of charge pump integral current value are possible. The specific values are defined in .
 * Default (reset) value of pll_int_cntrl[2:0] is 100.
 */

#define BP_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL      0
#define BM_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL)
#else
#define BF_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL(v)   (((v) << 0) & BM_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CURRCTRL_PLL_INT_CNTRL(v)   BF_CS1(HDMI_PHY_CURRCTRL, PLL_INT_CNTRL, v)
#endif

/* --- Register HW_HDMI_PHY_CURRCTRL, field PLL_PROP_CNTRL
 *
 * PLL Proportional Control  This bus controls the PLL charge pump proportional current. Eight
 * levels of charge pump proportional current value are possible. The specific values are defined in
 * .  Default (reset) value of pll_int_cntrl is 011.
 */

#define BP_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL      3
#define BM_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL)
#else
#define BF_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL(v)   (((v) << 3) & BM_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CURRCTRL_PLL_PROP_CNTRL(v)   BF_CS1(HDMI_PHY_CURRCTRL, PLL_PROP_CNTRL, v)
#endif

/* --- Register HW_HDMI_PHY_CURRCTRL, field MPLL_INT_CNTRL
 *
 * MPLL Integral Control  This bus controls the charge pump integral current. Eight levels of charge
 * pump integral current value are possible. The specific values are defined in .  Default (reset)
 * value of pll_int_cntrl[1:0] is 100.
 */

#define BP_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL      6
#define BM_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL)
#else
#define BF_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL(v)   (((v) << 6) & BM_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CURRCTRL_MPLL_INT_CNTRL(v)   BF_CS1(HDMI_PHY_CURRCTRL, MPLL_INT_CNTRL, v)
#endif

/* --- Register HW_HDMI_PHY_CURRCTRL, field MPLL_PROP_CNTRL
 *
 * MPLL Proportional Control  This bus controls the MPLL charge pump proportional current. Eight
 * levels of charge pump proportional current value are possible. The specific values are defined in
 * .  Default (reset) value of pll_prop_cntrl[1:0] is 100.
 */

#define BP_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL      9
#define BM_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL(v)   ((((reg32_t) v) << 9) & BM_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL)
#else
#define BF_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL(v)   (((v) << 9) & BM_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_CURRCTRL_MPLL_PROP_CNTRL(v)   BF_CS1(HDMI_PHY_CURRCTRL, MPLL_PROP_CNTRL, v)
#endif

/*!
 * @brief HW_HDMI_PHY_DRVANACTRL - Drive Analog Control
 *
 * Register name : DRVANACTRL  Access type : Read/write/override  Address : 0x11  Value at reset :
 * 0x0003
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short MPLL_DRV_ANA : 1; //!< MPLL Drive Analog  This bit enables or disables driving the ck_ref_p/m clocks to all transmitters  (tx_topa).  Default (reset) value of mpll_drv_ana is 1.
        unsigned short PLL_DRV_ANA : 1; //!< PLL Drive Analog  This bit enables or disables driving the ck_ref_mpll_p/m clocks to the MPLL  module.  Default (reset) value of pll_drv_ana is 1.
        unsigned short RESERVED0 : 13; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_drvanactrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_DRVANACTRL register
 */
#define HW_HDMI_PHY_DRVANACTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x11)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_DRVANACTRL           (*(volatile hw_hdmi_phy_drvanactrl_t *) HW_HDMI_PHY_DRVANACTRL_ADDR)
#define HW_HDMI_PHY_DRVANACTRL_RD()      (HW_HDMI_PHY_DRVANACTRL.U)
#define HW_HDMI_PHY_DRVANACTRL_WR(v)     (HW_HDMI_PHY_DRVANACTRL.U = (v))
#define HW_HDMI_PHY_DRVANACTRL_SET(v)    (HW_HDMI_PHY_DRVANACTRL_WR(HW_HDMI_PHY_DRVANACTRL_RD() |  (v)))
#define HW_HDMI_PHY_DRVANACTRL_CLR(v)    (HW_HDMI_PHY_DRVANACTRL_WR(HW_HDMI_PHY_DRVANACTRL_RD() & ~(v)))
#define HW_HDMI_PHY_DRVANACTRL_TOG(v)    (HW_HDMI_PHY_DRVANACTRL_WR(HW_HDMI_PHY_DRVANACTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_DRVANACTRL bitfields
 */

/* --- Register HW_HDMI_PHY_DRVANACTRL, field MPLL_DRV_ANA
 *
 * MPLL Drive Analog  This bit enables or disables driving the ck_ref_p/m clocks to all transmitters
 * (tx_topa).  Default (reset) value of mpll_drv_ana is 1.
 */

#define BP_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA      0
#define BM_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA)
#else
#define BF_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA(v)   (((v) << 0) & BM_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DRVANACTRL_MPLL_DRV_ANA(v)   BF_CS1(HDMI_PHY_DRVANACTRL, MPLL_DRV_ANA, v)
#endif

/* --- Register HW_HDMI_PHY_DRVANACTRL, field PLL_DRV_ANA
 *
 * PLL Drive Analog  This bit enables or disables driving the ck_ref_mpll_p/m clocks to the MPLL
 * module.  Default (reset) value of pll_drv_ana is 1.
 */

#define BP_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA      1
#define BM_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA)
#else
#define BF_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA(v)   (((v) << 1) & BM_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DRVANACTRL_PLL_DRV_ANA(v)   BF_CS1(HDMI_PHY_DRVANACTRL, PLL_DRV_ANA, v)
#endif

/* --- Register HW_HDMI_PHY_DRVANACTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_DRVANACTRL_OVERRIDE      15
#define BM_HDMI_PHY_DRVANACTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DRVANACTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_DRVANACTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_DRVANACTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_DRVANACTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DRVANACTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_DRVANACTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_PLLMEASCTRL - PLL Measure Control
 *
 * Register name : PLLMEASCTRL  Access type : Read/write  Address : 0x12  Value at reset : 0x0000
 * With the exception of pll_atb_sense_sel and pll_meas_iv[9], two or more of the previous register
 * bits must not be set to 1 simultaneously; doing so can lead to a hardware problem.  The table
 * below describes the pll_meas_iv[10:0] bit settings.   pll_meas_iv[10:0]        Effective Bit
 * Pll_meas_iv[10:0] Value  Description    Pll_meas_iv[0]  00000000001  Not used.    Pll_meas_iv[1]
 * 00000000010  Not used in pll_top. Connected to fast_tech pins of PLL and MPLL in hdmi_topa.
 * Pll_meas_iv[2]  00000000100  Connects VP supply voltage to the atb_sense line.    Pll_meas_iv[3]
 * 00000001000  Connects vp_cp to the atb_sense line.    Pll_meas_iv[4]  00000010000  Connects
 * internal supply voltage of the VCO (ivco) to the atb_sense line.    Pll_meas_iv[5]  00000100000
 * Connects vp_cko voltage to the atb_sense line.    Pll_meas_iv[6]  00001000000  Connects node vpsf
 * to the atb_sense line.    Pll_meas_iv[7]  00010000000  Connects vref to atb_sense line.
 * Pll_meas_iv[8]  00100000000  Connects vcntrl to atb_sense line.    Pll_meas_iv[9]  01000000000
 * Enables the phase mixer and pll_cko_pm_p/m.    Pll_meas_iv[10]  10000000000  Measures the voltage
 * corresponding to the output phase of the clr_dpth divider (fb_clk) with respect to refclk.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short PLL_MEAS_GD : 1; //!< PLL Measure Ground  This bit connects or disconnects the ground signal to the atb_sense (analog test bus) bus.
        unsigned short PLL_MEAS_IV : 11; //!< PLL Measure Internal Voltage  This bus enables or disables measuring various PLL node voltages and branch currents.  For information about the bit settings, see the pll_meas_iv[10:0] table.
        unsigned short PLL_ATB_SENSE_SEL : 1; //!< PLL Analog Test Bus Sense Select  This bit enables or disables internal signals of the PLL to be connected to the analog test bus. Without setting this bit, no measurements can be made on the atb_sense line.  Default (reset) value of pll_atb_sense_sel is 0.
        unsigned short RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_phy_pllmeasctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PLLMEASCTRL register
 */
#define HW_HDMI_PHY_PLLMEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x12)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PLLMEASCTRL           (*(volatile hw_hdmi_phy_pllmeasctrl_t *) HW_HDMI_PHY_PLLMEASCTRL_ADDR)
#define HW_HDMI_PHY_PLLMEASCTRL_RD()      (HW_HDMI_PHY_PLLMEASCTRL.U)
#define HW_HDMI_PHY_PLLMEASCTRL_WR(v)     (HW_HDMI_PHY_PLLMEASCTRL.U = (v))
#define HW_HDMI_PHY_PLLMEASCTRL_SET(v)    (HW_HDMI_PHY_PLLMEASCTRL_WR(HW_HDMI_PHY_PLLMEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_PLLMEASCTRL_CLR(v)    (HW_HDMI_PHY_PLLMEASCTRL_WR(HW_HDMI_PHY_PLLMEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_PLLMEASCTRL_TOG(v)    (HW_HDMI_PHY_PLLMEASCTRL_WR(HW_HDMI_PHY_PLLMEASCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_PLLMEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_PLLMEASCTRL, field PLL_MEAS_GD
 *
 * PLL Measure Ground  This bit connects or disconnects the ground signal to the atb_sense (analog
 * test bus) bus.
 */

#define BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD      0
#define BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD)
#else
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD(v)   (((v) << 0) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_GD(v)   BF_CS1(HDMI_PHY_PLLMEASCTRL, PLL_MEAS_GD, v)
#endif

/* --- Register HW_HDMI_PHY_PLLMEASCTRL, field PLL_MEAS_IV
 *
 * PLL Measure Internal Voltage  This bus enables or disables measuring various PLL node voltages
 * and branch currents.  For information about the bit settings, see the pll_meas_iv[10:0] table.
 */

#define BP_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV      1
#define BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV      0x00000ffe

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV)
#else
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV(v)   (((v) << 1) & BM_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PLLMEASCTRL_PLL_MEAS_IV(v)   BF_CS1(HDMI_PHY_PLLMEASCTRL, PLL_MEAS_IV, v)
#endif

/* --- Register HW_HDMI_PHY_PLLMEASCTRL, field PLL_ATB_SENSE_SEL
 *
 * PLL Analog Test Bus Sense Select  This bit enables or disables internal signals of the PLL to be
 * connected to the analog test bus. Without setting this bit, no measurements can be made on the
 * atb_sense line.  Default (reset) value of pll_atb_sense_sel is 0.
 */

#define BP_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL      12
#define BM_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL(v)   ((((reg32_t) v) << 12) & BM_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL)
#else
#define BF_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL(v)   (((v) << 12) & BM_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PLLMEASCTRL_PLL_ATB_SENSE_SEL(v)   BF_CS1(HDMI_PHY_PLLMEASCTRL, PLL_ATB_SENSE_SEL, v)
#endif

/*!
 * @brief HW_HDMI_PHY_PLLPHBYCTRL - PLL Phase and Bypass Control
 *
 * Register name : PLLPHBYCTRL  Access type : Read/write  Address : 0x13  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short PLL_PH_SEL : 10; //!< PLL Phase Select  This bus is a control word for the PLL's phase mixer that enables the phase of pll_cko_pm_p/m to be varied ± 0.5 UI of the VCO frequency, which is 740-1,480 MHz.
        unsigned short PLL_PH_SEL_CK : 1; //!< PLL Phase Select Clock  This bit enables or disables latching the ph_sel[9:0] into a 9-bit DAC used in the phase mixer.
        unsigned short BYPASS_PPLL : 1; //!< Bypass Pre-PLL  This bit enables or disables bypassing the pre-PLL.
        unsigned short RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_phy_pllphbyctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PLLPHBYCTRL register
 */
#define HW_HDMI_PHY_PLLPHBYCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x13)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PLLPHBYCTRL           (*(volatile hw_hdmi_phy_pllphbyctrl_t *) HW_HDMI_PHY_PLLPHBYCTRL_ADDR)
#define HW_HDMI_PHY_PLLPHBYCTRL_RD()      (HW_HDMI_PHY_PLLPHBYCTRL.U)
#define HW_HDMI_PHY_PLLPHBYCTRL_WR(v)     (HW_HDMI_PHY_PLLPHBYCTRL.U = (v))
#define HW_HDMI_PHY_PLLPHBYCTRL_SET(v)    (HW_HDMI_PHY_PLLPHBYCTRL_WR(HW_HDMI_PHY_PLLPHBYCTRL_RD() |  (v)))
#define HW_HDMI_PHY_PLLPHBYCTRL_CLR(v)    (HW_HDMI_PHY_PLLPHBYCTRL_WR(HW_HDMI_PHY_PLLPHBYCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_PLLPHBYCTRL_TOG(v)    (HW_HDMI_PHY_PLLPHBYCTRL_WR(HW_HDMI_PHY_PLLPHBYCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_PLLPHBYCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_PLLPHBYCTRL, field PLL_PH_SEL
 *
 * PLL Phase Select  This bus is a control word for the PLL's phase mixer that enables the phase of
 * pll_cko_pm_p/m to be varied ± 0.5 UI of the VCO frequency, which is 740-1,480 MHz.
 */

#define BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL      0
#define BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL)
#else
#define BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL(v)   (((v) << 0) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL(v)   BF_CS1(HDMI_PHY_PLLPHBYCTRL, PLL_PH_SEL, v)
#endif

/* --- Register HW_HDMI_PHY_PLLPHBYCTRL, field PLL_PH_SEL_CK
 *
 * PLL Phase Select Clock  This bit enables or disables latching the ph_sel[9:0] into a 9-bit DAC
 * used in the phase mixer.
 */

#define BP_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK      10
#define BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK(v)   ((((reg32_t) v) << 10) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK)
#else
#define BF_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK(v)   (((v) << 10) & BM_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PLLPHBYCTRL_PLL_PH_SEL_CK(v)   BF_CS1(HDMI_PHY_PLLPHBYCTRL, PLL_PH_SEL_CK, v)
#endif

/* --- Register HW_HDMI_PHY_PLLPHBYCTRL, field BYPASS_PPLL
 *
 * Bypass Pre-PLL  This bit enables or disables bypassing the pre-PLL.
 */

#define BP_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL      11
#define BM_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL(v)   ((((reg32_t) v) << 11) & BM_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL)
#else
#define BF_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL(v)   (((v) << 11) & BM_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PLLPHBYCTRL_BYPASS_PPLL(v)   BF_CS1(HDMI_PHY_PLLPHBYCTRL, BYPASS_PPLL, v)
#endif

/*!
 * @brief HW_HDMI_PHY_GRP_CTRL - Gear Shift, Reset Mode, and Power State Control
 *
 * Register name : -  Access type : Read/write/override  Address : 0x14  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short MPLL_GEAR_SHIFT : 1; //!< MPLL Gear Shift  This bit enables or disables Rapid Locking mode, where the mpll_gear_shift bit is asserted for 25 µs when coming out of reset, then deasserted before clocks are valid.
        unsigned short PLL_GEAR_SHIFT : 1; //!< PLL Gear Shift  This bit enables or disables Rapid Locking mode, where the pll_gear_shift bit is asserted for 25 µs when coming out of reset, then deasserted before clocks are valid.
        unsigned short MPLL_RST : 1; //!< MPLL Reset  This bit is used to place the MPLL in Reset mode.
        unsigned short MPLL_PWR_ON : 1; //!< MPLL Power-On  This bit is used to power-on/off the MPLL module.
        unsigned short PLL_RST : 1; //!< PLL Reset  This bit is used to place the MPLL in Reset mode.
        unsigned short PLL_PWR_ON : 1; //!< PLL Power-On  This bit is used to power on/off the PLL module.  Note: If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
        unsigned short RESERVED0 : 9; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_grp_ctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_GRP_CTRL register
 */
#define HW_HDMI_PHY_GRP_CTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_GRP_CTRL           (*(volatile hw_hdmi_phy_grp_ctrl_t *) HW_HDMI_PHY_GRP_CTRL_ADDR)
#define HW_HDMI_PHY_GRP_CTRL_RD()      (HW_HDMI_PHY_GRP_CTRL.U)
#define HW_HDMI_PHY_GRP_CTRL_WR(v)     (HW_HDMI_PHY_GRP_CTRL.U = (v))
#define HW_HDMI_PHY_GRP_CTRL_SET(v)    (HW_HDMI_PHY_GRP_CTRL_WR(HW_HDMI_PHY_GRP_CTRL_RD() |  (v)))
#define HW_HDMI_PHY_GRP_CTRL_CLR(v)    (HW_HDMI_PHY_GRP_CTRL_WR(HW_HDMI_PHY_GRP_CTRL_RD() & ~(v)))
#define HW_HDMI_PHY_GRP_CTRL_TOG(v)    (HW_HDMI_PHY_GRP_CTRL_WR(HW_HDMI_PHY_GRP_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_GRP_CTRL bitfields
 */

/* --- Register HW_HDMI_PHY_GRP_CTRL, field MPLL_GEAR_SHIFT
 *
 * MPLL Gear Shift  This bit enables or disables Rapid Locking mode, where the mpll_gear_shift bit
 * is asserted for 25 µs when coming out of reset, then deasserted before clocks are valid.
 */

#define BP_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT      0
#define BM_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT)
#else
#define BF_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT(v)   (((v) << 0) & BM_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GRP_CTRL_MPLL_GEAR_SHIFT(v)   BF_CS1(HDMI_PHY_GRP_CTRL, MPLL_GEAR_SHIFT, v)
#endif

/* --- Register HW_HDMI_PHY_GRP_CTRL, field PLL_GEAR_SHIFT
 *
 * PLL Gear Shift  This bit enables or disables Rapid Locking mode, where the pll_gear_shift bit is
 * asserted for 25 µs when coming out of reset, then deasserted before clocks are valid.
 */

#define BP_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT      1
#define BM_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT)
#else
#define BF_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT(v)   (((v) << 1) & BM_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GRP_CTRL_PLL_GEAR_SHIFT(v)   BF_CS1(HDMI_PHY_GRP_CTRL, PLL_GEAR_SHIFT, v)
#endif

/* --- Register HW_HDMI_PHY_GRP_CTRL, field MPLL_RST
 *
 * MPLL Reset  This bit is used to place the MPLL in Reset mode.
 */

#define BP_HDMI_PHY_GRP_CTRL_MPLL_RST      2
#define BM_HDMI_PHY_GRP_CTRL_MPLL_RST      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GRP_CTRL_MPLL_RST(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_GRP_CTRL_MPLL_RST)
#else
#define BF_HDMI_PHY_GRP_CTRL_MPLL_RST(v)   (((v) << 2) & BM_HDMI_PHY_GRP_CTRL_MPLL_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GRP_CTRL_MPLL_RST(v)   BF_CS1(HDMI_PHY_GRP_CTRL, MPLL_RST, v)
#endif

/* --- Register HW_HDMI_PHY_GRP_CTRL, field MPLL_PWR_ON
 *
 * MPLL Power-On  This bit is used to power-on/off the MPLL module.
 */

#define BP_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON      3
#define BM_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON)
#else
#define BF_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON(v)   (((v) << 3) & BM_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GRP_CTRL_MPLL_PWR_ON(v)   BF_CS1(HDMI_PHY_GRP_CTRL, MPLL_PWR_ON, v)
#endif

/* --- Register HW_HDMI_PHY_GRP_CTRL, field PLL_RST
 *
 * PLL Reset  This bit is used to place the MPLL in Reset mode.
 */

#define BP_HDMI_PHY_GRP_CTRL_PLL_RST      4
#define BM_HDMI_PHY_GRP_CTRL_PLL_RST      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GRP_CTRL_PLL_RST(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_GRP_CTRL_PLL_RST)
#else
#define BF_HDMI_PHY_GRP_CTRL_PLL_RST(v)   (((v) << 4) & BM_HDMI_PHY_GRP_CTRL_PLL_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GRP_CTRL_PLL_RST(v)   BF_CS1(HDMI_PHY_GRP_CTRL, PLL_RST, v)
#endif

/* --- Register HW_HDMI_PHY_GRP_CTRL, field PLL_PWR_ON
 *
 * PLL Power-On  This bit is used to power on/off the PLL module.  Note: If the Override bit is set
 * to 1, the working value is the Override bit value, not the registered value.
 */

#define BP_HDMI_PHY_GRP_CTRL_PLL_PWR_ON      5
#define BM_HDMI_PHY_GRP_CTRL_PLL_PWR_ON      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GRP_CTRL_PLL_PWR_ON(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_GRP_CTRL_PLL_PWR_ON)
#else
#define BF_HDMI_PHY_GRP_CTRL_PLL_PWR_ON(v)   (((v) << 5) & BM_HDMI_PHY_GRP_CTRL_PLL_PWR_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GRP_CTRL_PLL_PWR_ON(v)   BF_CS1(HDMI_PHY_GRP_CTRL, PLL_PWR_ON, v)
#endif

/* --- Register HW_HDMI_PHY_GRP_CTRL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_GRP_CTRL_OVERRIDE      15
#define BM_HDMI_PHY_GRP_CTRL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GRP_CTRL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_GRP_CTRL_OVERRIDE)
#else
#define BF_HDMI_PHY_GRP_CTRL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_GRP_CTRL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GRP_CTRL_OVERRIDE(v)   BF_CS1(HDMI_PHY_GRP_CTRL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_GMPCTRL - Gmp Control
 *
 * Register name : GMPCTRL  Access type : Read/write  Address : 0x15  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short MPLL_GMP_CNTRL : 2; //!< MPLL gmp Control  This bus controls the effective loop-filter resistance (= 1/gmp) to increase or decrease MPLL bandwidth and to compensate for changes in the Divider module (n_cntrl).
        unsigned short PLL_GMP_CNTRL : 2; //!< PLL gmp Control  This bus controls the effective loop-filter resistance (equal) to increase or decrease PLL bandwidth and to compensate for changes in the Divider module (n_cntrl).
        unsigned short RESERVED0 : 12; //!< Reserved
    } B;
} hw_hdmi_phy_gmpctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_GMPCTRL register
 */
#define HW_HDMI_PHY_GMPCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x15)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_GMPCTRL           (*(volatile hw_hdmi_phy_gmpctrl_t *) HW_HDMI_PHY_GMPCTRL_ADDR)
#define HW_HDMI_PHY_GMPCTRL_RD()      (HW_HDMI_PHY_GMPCTRL.U)
#define HW_HDMI_PHY_GMPCTRL_WR(v)     (HW_HDMI_PHY_GMPCTRL.U = (v))
#define HW_HDMI_PHY_GMPCTRL_SET(v)    (HW_HDMI_PHY_GMPCTRL_WR(HW_HDMI_PHY_GMPCTRL_RD() |  (v)))
#define HW_HDMI_PHY_GMPCTRL_CLR(v)    (HW_HDMI_PHY_GMPCTRL_WR(HW_HDMI_PHY_GMPCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_GMPCTRL_TOG(v)    (HW_HDMI_PHY_GMPCTRL_WR(HW_HDMI_PHY_GMPCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_GMPCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_GMPCTRL, field MPLL_GMP_CNTRL
 *
 * MPLL gmp Control  This bus controls the effective loop-filter resistance (= 1/gmp) to increase or
 * decrease MPLL bandwidth and to compensate for changes in the Divider module (n_cntrl).
 */

#define BP_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL      0
#define BM_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL)
#else
#define BF_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL(v)   (((v) << 0) & BM_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GMPCTRL_MPLL_GMP_CNTRL(v)   BF_CS1(HDMI_PHY_GMPCTRL, MPLL_GMP_CNTRL, v)
#endif

/* --- Register HW_HDMI_PHY_GMPCTRL, field PLL_GMP_CNTRL
 *
 * PLL gmp Control  This bus controls the effective loop-filter resistance (equal) to increase or
 * decrease PLL bandwidth and to compensate for changes in the Divider module (n_cntrl).
 */

#define BP_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL      2
#define BM_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL)
#else
#define BF_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL(v)   (((v) << 2) & BM_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_GMPCTRL_PLL_GMP_CNTRL(v)   BF_CS1(HDMI_PHY_GMPCTRL, PLL_GMP_CNTRL, v)
#endif

/*!
 * @brief HW_HDMI_PHY_MPLLMEASCTRL - MPLL Measure Control
 *
 * Register name : MPLLMEASCTRL  Access type : Read/write  Address : 0x16  Value at reset : 0x0000
 * With the exception of mpll_atb_sense_sel, mpll_meas_iv[9], and mpll_meas_iv[11], two or more of
 * the previous register bits must not be set to 1 simultaneously, because doing so can lead to a
 * hardware problem.  The table below describes the mpll_meas_iv[11:0] bit settings.
 * mpll_meas_iv[11:0]        Effective Bit  mpll_meas_iv[11:0] Value  Description
 * mpll_meas_iv[0]  000000000001  Connects the internal positive DCC control line (vc0p) to the
 * atb_sense line.    mpll_meas_iv[1]  000000000010  Connects the internal negative DCC control line
 * (vc0m) to the atb_sense line.    mpll_meas_iv[2]  000000000100  Connects VP supply voltage to the
 * atb_sense line.    mpll_meas_iv[3]  000000001000  Connects vp_cp to the atb_sense line.
 * mpll_meas_iv[4]  000000010000  Connects the internal supply voltage of the VCO (ivco) to the
 * atb_sense line through a low-pass filter.    mpll_meas_iv[5]  000000100000  Connects the vp_cko
 * voltage to the atb_sense line.    mpll_meas_iv[6]  000001000000  Connects the vpsf node to the
 * atb_sense line.    mpll_meas_iv[7]  000010000000  Connects vref to the atb_sense line.
 * mpll_meas_iv[8]  000100000000  Connects vcntrl to the atb_sense line.    mpll_meas_iv[9]
 * 001000000000  Enables the phase mixer and cko_pm_p/m.    mpll_meas_iv[10]  010000000000  Measures
 * the voltage corresponding to the phase of the divide-by-5 output (fb_clk) with respect to the
 * phase of the mpll_ana input (ck_refclk_p).    mpll_meas_iv[11]  100000000000  Forces div_x1 low;
 * therefore, bitclk_p/m is multiplexed to ck_ref_p/m (normally, if n_cntrl = 00, ck0_p/m is
 * multiplexed to ck_ref_p/m and DCC loop is enabled.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short MPLL_MEAS_GD : 1; //!< MPLL Measure Ground  This bit connects or disconnects the ground signal to the atb_sense (analog test bus) bus.
        unsigned short MPLL_MEAS_IV : 12; //!< MPLL Measure Internal Voltage  This bus enables or disables measuring various PLL node voltages and branch currents.  For information about the bit settings, see the mpll_meas_iv[11:0] table.
        unsigned short MPLL_ATB_SENSE_SEL : 1; //!< MPLL Analog Test Bus Sense Select  This bit enables or disables internal signals of the PLL to be connected to the analog test bus. Without setting this bit, no measurements can be made on the atb_sense line.  Default (reset) value of mpll_atb_sense_sel is 0.
        unsigned short RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_phy_mpllmeasctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_MPLLMEASCTRL register
 */
#define HW_HDMI_PHY_MPLLMEASCTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x16)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_MPLLMEASCTRL           (*(volatile hw_hdmi_phy_mpllmeasctrl_t *) HW_HDMI_PHY_MPLLMEASCTRL_ADDR)
#define HW_HDMI_PHY_MPLLMEASCTRL_RD()      (HW_HDMI_PHY_MPLLMEASCTRL.U)
#define HW_HDMI_PHY_MPLLMEASCTRL_WR(v)     (HW_HDMI_PHY_MPLLMEASCTRL.U = (v))
#define HW_HDMI_PHY_MPLLMEASCTRL_SET(v)    (HW_HDMI_PHY_MPLLMEASCTRL_WR(HW_HDMI_PHY_MPLLMEASCTRL_RD() |  (v)))
#define HW_HDMI_PHY_MPLLMEASCTRL_CLR(v)    (HW_HDMI_PHY_MPLLMEASCTRL_WR(HW_HDMI_PHY_MPLLMEASCTRL_RD() & ~(v)))
#define HW_HDMI_PHY_MPLLMEASCTRL_TOG(v)    (HW_HDMI_PHY_MPLLMEASCTRL_WR(HW_HDMI_PHY_MPLLMEASCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_MPLLMEASCTRL bitfields
 */

/* --- Register HW_HDMI_PHY_MPLLMEASCTRL, field MPLL_MEAS_GD
 *
 * MPLL Measure Ground  This bit connects or disconnects the ground signal to the atb_sense (analog
 * test bus) bus.
 */

#define BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD      0
#define BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD)
#else
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD(v)   (((v) << 0) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_GD(v)   BF_CS1(HDMI_PHY_MPLLMEASCTRL, MPLL_MEAS_GD, v)
#endif

/* --- Register HW_HDMI_PHY_MPLLMEASCTRL, field MPLL_MEAS_IV
 *
 * MPLL Measure Internal Voltage  This bus enables or disables measuring various PLL node voltages
 * and branch currents.  For information about the bit settings, see the mpll_meas_iv[11:0] table.
 */

#define BP_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV      1
#define BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV      0x00001ffe

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV)
#else
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV(v)   (((v) << 1) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MPLLMEASCTRL_MPLL_MEAS_IV(v)   BF_CS1(HDMI_PHY_MPLLMEASCTRL, MPLL_MEAS_IV, v)
#endif

/* --- Register HW_HDMI_PHY_MPLLMEASCTRL, field MPLL_ATB_SENSE_SEL
 *
 * MPLL Analog Test Bus Sense Select  This bit enables or disables internal signals of the PLL to be
 * connected to the analog test bus. Without setting this bit, no measurements can be made on the
 * atb_sense line.  Default (reset) value of mpll_atb_sense_sel is 0.
 */

#define BP_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL      13
#define BM_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL(v)   ((((reg32_t) v) << 13) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL)
#else
#define BF_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL(v)   (((v) << 13) & BM_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MPLLMEASCTRL_MPLL_ATB_SENSE_SEL(v)   BF_CS1(HDMI_PHY_MPLLMEASCTRL, MPLL_ATB_SENSE_SEL, v)
#endif

/*!
 * @brief HW_HDMI_PHY_MSM_CTRL - MPLL and PLL Phase, Scope Clock Select, and MUX Clock Control
 *
 * Register name : -  Access type : Read/write  Address : 0x17  Value at reset : 0x0000  The table
 * below describes the cko_sel[1:0] bit settings. (The cko_sel[1:0] default value is 00.)
 * cko_sel[1:0]         cko_sel[1:0]  TMDS Clock Mode  PLL and MPLL Mode  Output TMDS Clock on TMDS
 * Channel      00  Non-Coherent  Normal  ck_ref_mpll_p/m (Pre-PLL out)    01  Off (PLL and MPLL are
 * both off)  Normal  Off (No output TMDS clock)    10  Test (PHY in test mode)  Normal  PCLK (Input
 * reference clock to HDMI 3D Tx PHY)    11  Coherent  Normal  fb_clk (MPLL feedback clock)    00
 * Off (PLL and MPLL are both off)  Bypass  Off (No output TMDS clock)    01  Off (PLL and MPLL are
 * both off)  Bypass  Off (No output TMDS clock)    10  Non-Coherent  Bypass  PCLK (Input reference
 * clock to HDMI 3D Tx PHY)    11  Coherent  Bypass  fb_clk (MPLL feedback clock)
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_CK_SEL : 1; //!< Scope Clock Select  Selects the clock to connect to the scope clock signal: the differential pll_cko_p/m or the differential mpll_cko_p/m.
        unsigned short CKO_SEL : 2; //!< Clock Output Select  This bus selects the clock to be connected to the output TMDS clock channel.   Notes:    Normal mode: The color depth or pixel repetition is required, which means that the PLL is powered on (pll_pwr_on bit is set to 1) and the bypass_ppll bit is set to 0.  Bypass mode: The color depth and the pixel repetition is not required, which means that the PLL is powered off (pll_pwr_on bit is set to 0) and the bypass_ppll bit is set to 1.   For information about the cko_sel[1:0] bit settings and corresponding PLL/MPLL  modes, see the cko_sel[1:0] table.
        unsigned short MPLL_PH_SEL : 10; //!< MPLL Phase Select  This bus is a control word for the MPLL's phase mixer and enables the phase of pll_cko_pm_p /m to be varied ± 0.5 UI of the VCO frequency, which has a range of 925-1,850 MHz.
        unsigned short MPLL_PH_SEL_CK : 1; //!< MPLL Phase Select Clock  This bit enables or disables latching ph_sel[9:0] into a 9-bit DAC used in the phase mixer.
        unsigned short RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_phy_msm_ctrl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_MSM_CTRL register
 */
#define HW_HDMI_PHY_MSM_CTRL_ADDR      (REGS_HDMI_PHY_BASE + 0x17)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_MSM_CTRL           (*(volatile hw_hdmi_phy_msm_ctrl_t *) HW_HDMI_PHY_MSM_CTRL_ADDR)
#define HW_HDMI_PHY_MSM_CTRL_RD()      (HW_HDMI_PHY_MSM_CTRL.U)
#define HW_HDMI_PHY_MSM_CTRL_WR(v)     (HW_HDMI_PHY_MSM_CTRL.U = (v))
#define HW_HDMI_PHY_MSM_CTRL_SET(v)    (HW_HDMI_PHY_MSM_CTRL_WR(HW_HDMI_PHY_MSM_CTRL_RD() |  (v)))
#define HW_HDMI_PHY_MSM_CTRL_CLR(v)    (HW_HDMI_PHY_MSM_CTRL_WR(HW_HDMI_PHY_MSM_CTRL_RD() & ~(v)))
#define HW_HDMI_PHY_MSM_CTRL_TOG(v)    (HW_HDMI_PHY_MSM_CTRL_WR(HW_HDMI_PHY_MSM_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_MSM_CTRL bitfields
 */

/* --- Register HW_HDMI_PHY_MSM_CTRL, field SCOPE_CK_SEL
 *
 * Scope Clock Select  Selects the clock to connect to the scope clock signal: the differential
 * pll_cko_p/m or the differential mpll_cko_p/m.
 */

#define BP_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL      0
#define BM_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL)
#else
#define BF_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL(v)   (((v) << 0) & BM_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MSM_CTRL_SCOPE_CK_SEL(v)   BF_CS1(HDMI_PHY_MSM_CTRL, SCOPE_CK_SEL, v)
#endif

/* --- Register HW_HDMI_PHY_MSM_CTRL, field CKO_SEL
 *
 * Clock Output Select  This bus selects the clock to be connected to the output TMDS clock channel.
 * Notes:    Normal mode: The color depth or pixel repetition is required, which means that the PLL
 * is powered on (pll_pwr_on bit is set to 1) and the bypass_ppll bit is set to 0.  Bypass mode: The
 * color depth and the pixel repetition is not required, which means that the PLL is powered off
 * (pll_pwr_on bit is set to 0) and the bypass_ppll bit is set to 1.   For information about the
 * cko_sel[1:0] bit settings and corresponding PLL/MPLL  modes, see the cko_sel[1:0] table.
 */

#define BP_HDMI_PHY_MSM_CTRL_CKO_SEL      1
#define BM_HDMI_PHY_MSM_CTRL_CKO_SEL      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MSM_CTRL_CKO_SEL(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_MSM_CTRL_CKO_SEL)
#else
#define BF_HDMI_PHY_MSM_CTRL_CKO_SEL(v)   (((v) << 1) & BM_HDMI_PHY_MSM_CTRL_CKO_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MSM_CTRL_CKO_SEL(v)   BF_CS1(HDMI_PHY_MSM_CTRL, CKO_SEL, v)
#endif

/* --- Register HW_HDMI_PHY_MSM_CTRL, field MPLL_PH_SEL
 *
 * MPLL Phase Select  This bus is a control word for the MPLL's phase mixer and enables the phase of
 * pll_cko_pm_p /m to be varied ± 0.5 UI of the VCO frequency, which has a range of 925-1,850 MHz.
 */

#define BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL      3
#define BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL      0x00001ff8

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL)
#else
#define BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL(v)   (((v) << 3) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL(v)   BF_CS1(HDMI_PHY_MSM_CTRL, MPLL_PH_SEL, v)
#endif

/* --- Register HW_HDMI_PHY_MSM_CTRL, field MPLL_PH_SEL_CK
 *
 * MPLL Phase Select Clock  This bit enables or disables latching ph_sel[9:0] into a 9-bit DAC used
 * in the phase mixer.
 */

#define BP_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK      13
#define BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK(v)   ((((reg32_t) v) << 13) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK)
#else
#define BF_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK(v)   (((v) << 13) & BM_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_MSM_CTRL_MPLL_PH_SEL_CK(v)   BF_CS1(HDMI_PHY_MSM_CTRL, MPLL_PH_SEL_CK, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCRPB_STATUS - Scope, Comparator Result and Power Bad Status
 *
 * Register name : -  Access type : Read-only  Address : 0x18  Value at reset : N/A
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short CK_SCOPE_OUT : 1; //!< Clock Scope Output Signal
        unsigned short TX_SCOPE_OUT2 : 1; //!< Scoping Value for Lane 2
        unsigned short TX_SCOPE_OUT1 : 1; //!< Scoping Value for Lane 1
        unsigned short TX_SCOPE_OUT0 : 1; //!< Scoping Value for Lane 0
        unsigned short SUP_COMP_RT_RESULT : 1; //!< Support Comparator Resistance Termination Result  This bit represents the result of the comparison process.
        unsigned short RESERVED0 : 1; //!< Reserved
        unsigned short ADC_VAL : 10; //!< ADC/DAC bit word (analog signal value)
    } B;
} hw_hdmi_phy_scrpb_status_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCRPB_STATUS register
 */
#define HW_HDMI_PHY_SCRPB_STATUS_ADDR      (REGS_HDMI_PHY_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCRPB_STATUS           (*(volatile hw_hdmi_phy_scrpb_status_t *) HW_HDMI_PHY_SCRPB_STATUS_ADDR)
#define HW_HDMI_PHY_SCRPB_STATUS_RD()      (HW_HDMI_PHY_SCRPB_STATUS.U)
#define HW_HDMI_PHY_SCRPB_STATUS_WR(v)     (HW_HDMI_PHY_SCRPB_STATUS.U = (v))
#define HW_HDMI_PHY_SCRPB_STATUS_SET(v)    (HW_HDMI_PHY_SCRPB_STATUS_WR(HW_HDMI_PHY_SCRPB_STATUS_RD() |  (v)))
#define HW_HDMI_PHY_SCRPB_STATUS_CLR(v)    (HW_HDMI_PHY_SCRPB_STATUS_WR(HW_HDMI_PHY_SCRPB_STATUS_RD() & ~(v)))
#define HW_HDMI_PHY_SCRPB_STATUS_TOG(v)    (HW_HDMI_PHY_SCRPB_STATUS_WR(HW_HDMI_PHY_SCRPB_STATUS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCRPB_STATUS bitfields
 */

/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field CK_SCOPE_OUT
 *
 * Clock Scope Output Signal
 */

#define BP_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT      0
#define BM_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT)
#else
#define BF_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT(v)   (((v) << 0) & BM_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCRPB_STATUS_CK_SCOPE_OUT(v)   BF_CS1(HDMI_PHY_SCRPB_STATUS, CK_SCOPE_OUT, v)
#endif

/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field TX_SCOPE_OUT2
 *
 * Scoping Value for Lane 2
 */

#define BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2      1
#define BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2)
#else
#define BF_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2(v)   (((v) << 1) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT2(v)   BF_CS1(HDMI_PHY_SCRPB_STATUS, TX_SCOPE_OUT2, v)
#endif

/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field TX_SCOPE_OUT1
 *
 * Scoping Value for Lane 1
 */

#define BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1      2
#define BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1)
#else
#define BF_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1(v)   (((v) << 2) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT1(v)   BF_CS1(HDMI_PHY_SCRPB_STATUS, TX_SCOPE_OUT1, v)
#endif

/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field TX_SCOPE_OUT0
 *
 * Scoping Value for Lane 0
 */

#define BP_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0      3
#define BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0)
#else
#define BF_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0(v)   (((v) << 3) & BM_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCRPB_STATUS_TX_SCOPE_OUT0(v)   BF_CS1(HDMI_PHY_SCRPB_STATUS, TX_SCOPE_OUT0, v)
#endif

/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field SUP_COMP_RT_RESULT
 *
 * Support Comparator Resistance Termination Result  This bit represents the result of the
 * comparison process.
 */

#define BP_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT      4
#define BM_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT)
#else
#define BF_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT(v)   (((v) << 4) & BM_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCRPB_STATUS_SUP_COMP_RT_RESULT(v)   BF_CS1(HDMI_PHY_SCRPB_STATUS, SUP_COMP_RT_RESULT, v)
#endif

/* --- Register HW_HDMI_PHY_SCRPB_STATUS, field ADC_VAL
 *
 * ADC/DAC bit word (analog signal value)
 */

#define BP_HDMI_PHY_SCRPB_STATUS_ADC_VAL      6
#define BM_HDMI_PHY_SCRPB_STATUS_ADC_VAL      0x0000ffc0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCRPB_STATUS_ADC_VAL(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_SCRPB_STATUS_ADC_VAL)
#else
#define BF_HDMI_PHY_SCRPB_STATUS_ADC_VAL(v)   (((v) << 6) & BM_HDMI_PHY_SCRPB_STATUS_ADC_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCRPB_STATUS_ADC_VAL(v)   BF_CS1(HDMI_PHY_SCRPB_STATUS, ADC_VAL, v)
#endif

/*!
 * @brief HW_HDMI_PHY_TXTERM - Transmission Termination
 *
 * Register name : TXTERM  Access type : Read/write  Address : 0x19  Value at reset : 0x0007
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short D_TX_TERM : 3; //!< Digital Transmission Termination  This bus defines the transmission termination (resistance) value, which is set by the HDMI controller. The formula for the resistance value is:  R = 50 / (1 - 0.125 x d_tx_term)  This equation is valid only when d_tx_term equals 0-6.   000: 50 Ω  001: 56.14 Ω  010: 66.67 Ω  011: 80 Ω  100: 100 Ω  101: 133.33 Ω  110: 200 Ω  111: Open circuit
        unsigned short RESERVED0 : 13; //!< Reserved
    } B;
} hw_hdmi_phy_txterm_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TXTERM register
 */
#define HW_HDMI_PHY_TXTERM_ADDR      (REGS_HDMI_PHY_BASE + 0x19)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TXTERM           (*(volatile hw_hdmi_phy_txterm_t *) HW_HDMI_PHY_TXTERM_ADDR)
#define HW_HDMI_PHY_TXTERM_RD()      (HW_HDMI_PHY_TXTERM.U)
#define HW_HDMI_PHY_TXTERM_WR(v)     (HW_HDMI_PHY_TXTERM.U = (v))
#define HW_HDMI_PHY_TXTERM_SET(v)    (HW_HDMI_PHY_TXTERM_WR(HW_HDMI_PHY_TXTERM_RD() |  (v)))
#define HW_HDMI_PHY_TXTERM_CLR(v)    (HW_HDMI_PHY_TXTERM_WR(HW_HDMI_PHY_TXTERM_RD() & ~(v)))
#define HW_HDMI_PHY_TXTERM_TOG(v)    (HW_HDMI_PHY_TXTERM_WR(HW_HDMI_PHY_TXTERM_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_TXTERM bitfields
 */

/* --- Register HW_HDMI_PHY_TXTERM, field D_TX_TERM
 *
 * Digital Transmission Termination  This bus defines the transmission termination (resistance)
 * value, which is set by the HDMI controller. The formula for the resistance value is:  R = 50 / (1
 * - 0.125 x d_tx_term)  This equation is valid only when d_tx_term equals 0-6.   000: 50 Ω  001:
 * 56.14 Ω  010: 66.67 Ω  011: 80 Ω  100: 100 Ω  101: 133.33 Ω  110: 200 Ω  111: Open circuit
 */

#define BP_HDMI_PHY_TXTERM_D_TX_TERM      0
#define BM_HDMI_PHY_TXTERM_D_TX_TERM      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TXTERM_D_TX_TERM(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_TXTERM_D_TX_TERM)
#else
#define BF_HDMI_PHY_TXTERM_D_TX_TERM(v)   (((v) << 0) & BM_HDMI_PHY_TXTERM_D_TX_TERM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_TXTERM_D_TX_TERM(v)   BF_CS1(HDMI_PHY_TXTERM, D_TX_TERM, v)
#endif

/*!
 * @brief HW_HDMI_PHY_PTRPT_ENBL - Power Sequence, TX Clock Alignment, Resistance Calibration, Pattern Generator Skip Bit, and TMDS Encoder Enable
 *
 * Register name : -  Access type : Read/write/override  Address : 0x1A  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short REFCLK_ENB : 1; //!< Reference Clock Enable  This bit enables or disables the input reference clock.
        unsigned short CKO_WORD_ENB : 1; //!< Output Clock Word Enable  This bit enables the output word clock.
        unsigned short TX_READY : 1; //!< Transmission Ready  This bit indicates whether the PHY transmit driver is ready to transmit data.
        unsigned short TX_CK_ALIGN_ENB : 1; //!< Transmission Clock Alignment Enable  This bit disables or enables the clock alignment FSM.
        unsigned short RCAL_ENB : 1; //!< Resistance Calibration Enable  This bit enables or disables the resistance clock alignment process.
        unsigned short CK_REF_ENB : 1; //!< Clock Reference Enable  This bit powers up the clock alignment and the resistance calibration modules.
        unsigned short PG_SKIP_BIT0 : 1; //!< Pattern Generator Skip Bit 0  This bit enables or disables pattern generator skip bit feature for channel 0.
        unsigned short PG_SKIP_BIT1 : 1; //!< Pattern Generator Skip Bit 1  This bit enables or disables pattern generator skip bit feature for channel 1.
        unsigned short PG_SKIP_BIT2 : 1; //!< Pattern Generator Skip Bit 2  This bit enables or disables pattern generator skip bit feature for channel 2.
        unsigned short RESERVED0 : 6; //!< Reserved
        unsigned short OVERRIDE : 1; //!< If the Override bit is set to 1, the working value is the Override bit value, not the registered value.
    } B;
} hw_hdmi_phy_ptrpt_enbl_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PTRPT_ENBL register
 */
#define HW_HDMI_PHY_PTRPT_ENBL_ADDR      (REGS_HDMI_PHY_BASE + 0x1a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PTRPT_ENBL           (*(volatile hw_hdmi_phy_ptrpt_enbl_t *) HW_HDMI_PHY_PTRPT_ENBL_ADDR)
#define HW_HDMI_PHY_PTRPT_ENBL_RD()      (HW_HDMI_PHY_PTRPT_ENBL.U)
#define HW_HDMI_PHY_PTRPT_ENBL_WR(v)     (HW_HDMI_PHY_PTRPT_ENBL.U = (v))
#define HW_HDMI_PHY_PTRPT_ENBL_SET(v)    (HW_HDMI_PHY_PTRPT_ENBL_WR(HW_HDMI_PHY_PTRPT_ENBL_RD() |  (v)))
#define HW_HDMI_PHY_PTRPT_ENBL_CLR(v)    (HW_HDMI_PHY_PTRPT_ENBL_WR(HW_HDMI_PHY_PTRPT_ENBL_RD() & ~(v)))
#define HW_HDMI_PHY_PTRPT_ENBL_TOG(v)    (HW_HDMI_PHY_PTRPT_ENBL_WR(HW_HDMI_PHY_PTRPT_ENBL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_PTRPT_ENBL bitfields
 */

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field REFCLK_ENB
 *
 * Reference Clock Enable  This bit enables or disables the input reference clock.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB      0
#define BM_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB(v)   (((v) << 0) & BM_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_REFCLK_ENB(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, REFCLK_ENB, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field CKO_WORD_ENB
 *
 * Output Clock Word Enable  This bit enables the output word clock.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB      1
#define BM_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB(v)   (((v) << 1) & BM_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_CKO_WORD_ENB(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, CKO_WORD_ENB, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field TX_READY
 *
 * Transmission Ready  This bit indicates whether the PHY transmit driver is ready to transmit data.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_TX_READY      2
#define BM_HDMI_PHY_PTRPT_ENBL_TX_READY      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_TX_READY(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_PTRPT_ENBL_TX_READY)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_TX_READY(v)   (((v) << 2) & BM_HDMI_PHY_PTRPT_ENBL_TX_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_TX_READY(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, TX_READY, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field TX_CK_ALIGN_ENB
 *
 * Transmission Clock Alignment Enable  This bit disables or enables the clock alignment FSM.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB      3
#define BM_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB(v)   (((v) << 3) & BM_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_TX_CK_ALIGN_ENB(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, TX_CK_ALIGN_ENB, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field RCAL_ENB
 *
 * Resistance Calibration Enable  This bit enables or disables the resistance clock alignment
 * process.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_RCAL_ENB      4
#define BM_HDMI_PHY_PTRPT_ENBL_RCAL_ENB      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_RCAL_ENB(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_PTRPT_ENBL_RCAL_ENB)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_RCAL_ENB(v)   (((v) << 4) & BM_HDMI_PHY_PTRPT_ENBL_RCAL_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_RCAL_ENB(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, RCAL_ENB, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field CK_REF_ENB
 *
 * Clock Reference Enable  This bit powers up the clock alignment and the resistance calibration
 * modules.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB      5
#define BM_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB(v)   (((v) << 5) & BM_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_CK_REF_ENB(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, CK_REF_ENB, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field PG_SKIP_BIT0
 *
 * Pattern Generator Skip Bit 0  This bit enables or disables pattern generator skip bit feature for
 * channel 0.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0      6
#define BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0(v)   (((v) << 6) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT0(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, PG_SKIP_BIT0, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field PG_SKIP_BIT1
 *
 * Pattern Generator Skip Bit 1  This bit enables or disables pattern generator skip bit feature for
 * channel 1.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1      7
#define BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1(v)   ((((reg32_t) v) << 7) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1(v)   (((v) << 7) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT1(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, PG_SKIP_BIT1, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field PG_SKIP_BIT2
 *
 * Pattern Generator Skip Bit 2  This bit enables or disables pattern generator skip bit feature for
 * channel 2.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2      8
#define BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2(v)   ((((reg32_t) v) << 8) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2(v)   (((v) << 8) & BM_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_PG_SKIP_BIT2(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, PG_SKIP_BIT2, v)
#endif

/* --- Register HW_HDMI_PHY_PTRPT_ENBL, field OVERRIDE
 *
 * If the Override bit is set to 1, the working value is the Override bit value, not the registered
 * value.
 */

#define BP_HDMI_PHY_PTRPT_ENBL_OVERRIDE      15
#define BM_HDMI_PHY_PTRPT_ENBL_OVERRIDE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PTRPT_ENBL_OVERRIDE(v)   ((((reg32_t) v) << 15) & BM_HDMI_PHY_PTRPT_ENBL_OVERRIDE)
#else
#define BF_HDMI_PHY_PTRPT_ENBL_OVERRIDE(v)   (((v) << 15) & BM_HDMI_PHY_PTRPT_ENBL_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PTRPT_ENBL_OVERRIDE(v)   BF_CS1(HDMI_PHY_PTRPT_ENBL, OVERRIDE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_PATTERNGEN - Pattern Generator Mode
 *
 * Register name : PATTERNGEN  Access type : Read/write  Address : 0x1B  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short PG_PAT : 10; //!< Pattern Generator Generated Pattern  This bus carries the generated pattern from the Pattern Generator module.
        unsigned short PG_INSERT_ERR0 : 1; //!< Pattern Generator Insert Error Zero  This bit enables or disables error insertion inside the generated pattern for channel 0.
        unsigned short PG_INSERT_ERR1 : 1; //!< Pattern Generator Insert Error One  This bit enables or disables error insertion inside the generated pattern for channel 1.
        unsigned short PG_INSERT_ERR2 : 1; //!< Pattern Generator Insert Error Two  This bit enables or disables error insertion inside the generated pattern for channel 2.
        unsigned short RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_phy_patterngen_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_PATTERNGEN register
 */
#define HW_HDMI_PHY_PATTERNGEN_ADDR      (REGS_HDMI_PHY_BASE + 0x1b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_PATTERNGEN           (*(volatile hw_hdmi_phy_patterngen_t *) HW_HDMI_PHY_PATTERNGEN_ADDR)
#define HW_HDMI_PHY_PATTERNGEN_RD()      (HW_HDMI_PHY_PATTERNGEN.U)
#define HW_HDMI_PHY_PATTERNGEN_WR(v)     (HW_HDMI_PHY_PATTERNGEN.U = (v))
#define HW_HDMI_PHY_PATTERNGEN_SET(v)    (HW_HDMI_PHY_PATTERNGEN_WR(HW_HDMI_PHY_PATTERNGEN_RD() |  (v)))
#define HW_HDMI_PHY_PATTERNGEN_CLR(v)    (HW_HDMI_PHY_PATTERNGEN_WR(HW_HDMI_PHY_PATTERNGEN_RD() & ~(v)))
#define HW_HDMI_PHY_PATTERNGEN_TOG(v)    (HW_HDMI_PHY_PATTERNGEN_WR(HW_HDMI_PHY_PATTERNGEN_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_PATTERNGEN bitfields
 */

/* --- Register HW_HDMI_PHY_PATTERNGEN, field PG_PAT
 *
 * Pattern Generator Generated Pattern  This bus carries the generated pattern from the Pattern
 * Generator module.
 */

#define BP_HDMI_PHY_PATTERNGEN_PG_PAT      0
#define BM_HDMI_PHY_PATTERNGEN_PG_PAT      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PATTERNGEN_PG_PAT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_PATTERNGEN_PG_PAT)
#else
#define BF_HDMI_PHY_PATTERNGEN_PG_PAT(v)   (((v) << 0) & BM_HDMI_PHY_PATTERNGEN_PG_PAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PATTERNGEN_PG_PAT(v)   BF_CS1(HDMI_PHY_PATTERNGEN, PG_PAT, v)
#endif

/* --- Register HW_HDMI_PHY_PATTERNGEN, field PG_INSERT_ERR0
 *
 * Pattern Generator Insert Error Zero  This bit enables or disables error insertion inside the
 * generated pattern for channel 0.
 */

#define BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0      10
#define BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0(v)   ((((reg32_t) v) << 10) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0)
#else
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0(v)   (((v) << 10) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR0(v)   BF_CS1(HDMI_PHY_PATTERNGEN, PG_INSERT_ERR0, v)
#endif

/* --- Register HW_HDMI_PHY_PATTERNGEN, field PG_INSERT_ERR1
 *
 * Pattern Generator Insert Error One  This bit enables or disables error insertion inside the
 * generated pattern for channel 1.
 */

#define BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1      11
#define BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1(v)   ((((reg32_t) v) << 11) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1)
#else
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1(v)   (((v) << 11) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR1(v)   BF_CS1(HDMI_PHY_PATTERNGEN, PG_INSERT_ERR1, v)
#endif

/* --- Register HW_HDMI_PHY_PATTERNGEN, field PG_INSERT_ERR2
 *
 * Pattern Generator Insert Error Two  This bit enables or disables error insertion inside the
 * generated pattern for channel 2.
 */

#define BP_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2      12
#define BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2(v)   ((((reg32_t) v) << 12) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2)
#else
#define BF_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2(v)   (((v) << 12) & BM_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_PATTERNGEN_PG_INSERT_ERR2(v)   BF_CS1(HDMI_PHY_PATTERNGEN, PG_INSERT_ERR2, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SDCAP_MODE - The Soft-Reset and DAC Enable, Clock Alignment and PG Mode
 *
 * Register name : -  Access type : Read/write  Address : 0x1C  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SOFT_RESET : 1; //!< Soft Reset  This bit enables or disables the soft-reset feature.
        unsigned short ADC_ENB : 1; //!< Analog-to-Digital Converter Enable  This bit enables or disables the analog-to-digital converter.
        unsigned short TX_CK_ALIGN_MODE : 1; //!< Transmission Clock Alignment Mode  This bit selects the Transmission Clock Alignment mode.
        unsigned short PG_MODE0 : 3; //!< Pattern Generator Mode 0  This bus is used to select the mode of the Pattern Generator module for channel 0.
        unsigned short PG_MODE1 : 3; //!< Pattern Generator Mode 1  This bus is used to select the mode of the Pattern Generator module for channel 1.
        unsigned short PG_MODE2 : 3; //!< Pattern Generator Mode 2  This bus is used to select the mode of the Pattern Generator module for channel 2.
        unsigned short RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_phy_sdcap_mode_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SDCAP_MODE register
 */
#define HW_HDMI_PHY_SDCAP_MODE_ADDR      (REGS_HDMI_PHY_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SDCAP_MODE           (*(volatile hw_hdmi_phy_sdcap_mode_t *) HW_HDMI_PHY_SDCAP_MODE_ADDR)
#define HW_HDMI_PHY_SDCAP_MODE_RD()      (HW_HDMI_PHY_SDCAP_MODE.U)
#define HW_HDMI_PHY_SDCAP_MODE_WR(v)     (HW_HDMI_PHY_SDCAP_MODE.U = (v))
#define HW_HDMI_PHY_SDCAP_MODE_SET(v)    (HW_HDMI_PHY_SDCAP_MODE_WR(HW_HDMI_PHY_SDCAP_MODE_RD() |  (v)))
#define HW_HDMI_PHY_SDCAP_MODE_CLR(v)    (HW_HDMI_PHY_SDCAP_MODE_WR(HW_HDMI_PHY_SDCAP_MODE_RD() & ~(v)))
#define HW_HDMI_PHY_SDCAP_MODE_TOG(v)    (HW_HDMI_PHY_SDCAP_MODE_WR(HW_HDMI_PHY_SDCAP_MODE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SDCAP_MODE bitfields
 */

/* --- Register HW_HDMI_PHY_SDCAP_MODE, field SOFT_RESET
 *
 * Soft Reset  This bit enables or disables the soft-reset feature.
 */

#define BP_HDMI_PHY_SDCAP_MODE_SOFT_RESET      0
#define BM_HDMI_PHY_SDCAP_MODE_SOFT_RESET      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SDCAP_MODE_SOFT_RESET(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SDCAP_MODE_SOFT_RESET)
#else
#define BF_HDMI_PHY_SDCAP_MODE_SOFT_RESET(v)   (((v) << 0) & BM_HDMI_PHY_SDCAP_MODE_SOFT_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SDCAP_MODE_SOFT_RESET(v)   BF_CS1(HDMI_PHY_SDCAP_MODE, SOFT_RESET, v)
#endif

/* --- Register HW_HDMI_PHY_SDCAP_MODE, field ADC_ENB
 *
 * Analog-to-Digital Converter Enable  This bit enables or disables the analog-to-digital converter.
 */

#define BP_HDMI_PHY_SDCAP_MODE_ADC_ENB      1
#define BM_HDMI_PHY_SDCAP_MODE_ADC_ENB      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SDCAP_MODE_ADC_ENB(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_SDCAP_MODE_ADC_ENB)
#else
#define BF_HDMI_PHY_SDCAP_MODE_ADC_ENB(v)   (((v) << 1) & BM_HDMI_PHY_SDCAP_MODE_ADC_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SDCAP_MODE_ADC_ENB(v)   BF_CS1(HDMI_PHY_SDCAP_MODE, ADC_ENB, v)
#endif

/* --- Register HW_HDMI_PHY_SDCAP_MODE, field TX_CK_ALIGN_MODE
 *
 * Transmission Clock Alignment Mode  This bit selects the Transmission Clock Alignment mode.
 */

#define BP_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE      2
#define BM_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE)
#else
#define BF_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE(v)   (((v) << 2) & BM_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SDCAP_MODE_TX_CK_ALIGN_MODE(v)   BF_CS1(HDMI_PHY_SDCAP_MODE, TX_CK_ALIGN_MODE, v)
#endif

/* --- Register HW_HDMI_PHY_SDCAP_MODE, field PG_MODE0
 *
 * Pattern Generator Mode 0  This bus is used to select the mode of the Pattern Generator module for
 * channel 0.
 */

#define BP_HDMI_PHY_SDCAP_MODE_PG_MODE0      3
#define BM_HDMI_PHY_SDCAP_MODE_PG_MODE0      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE0(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE0)
#else
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE0(v)   (((v) << 3) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SDCAP_MODE_PG_MODE0(v)   BF_CS1(HDMI_PHY_SDCAP_MODE, PG_MODE0, v)
#endif

/* --- Register HW_HDMI_PHY_SDCAP_MODE, field PG_MODE1
 *
 * Pattern Generator Mode 1  This bus is used to select the mode of the Pattern Generator module for
 * channel 1.
 */

#define BP_HDMI_PHY_SDCAP_MODE_PG_MODE1      6
#define BM_HDMI_PHY_SDCAP_MODE_PG_MODE1      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE1(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE1)
#else
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE1(v)   (((v) << 6) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SDCAP_MODE_PG_MODE1(v)   BF_CS1(HDMI_PHY_SDCAP_MODE, PG_MODE1, v)
#endif

/* --- Register HW_HDMI_PHY_SDCAP_MODE, field PG_MODE2
 *
 * Pattern Generator Mode 2  This bus is used to select the mode of the Pattern Generator module for
 * channel 2.
 */

#define BP_HDMI_PHY_SDCAP_MODE_PG_MODE2      9
#define BM_HDMI_PHY_SDCAP_MODE_PG_MODE2      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE2(v)   ((((reg32_t) v) << 9) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE2)
#else
#define BF_HDMI_PHY_SDCAP_MODE_PG_MODE2(v)   (((v) << 9) & BM_HDMI_PHY_SDCAP_MODE_PG_MODE2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SDCAP_MODE_PG_MODE2(v)   BF_CS1(HDMI_PHY_SDCAP_MODE, PG_MODE2, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCOPEMODE - Scope Mode register
 *
 * Register name : SCOPEMODE  Access type : Read/write  Address : 0x1D  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_SAMPLE_CNT : 10; //!< Scope Sample Counter  Indicates the number of samples that will be counted (should be multiple of the LFSR length). This count includes only the LSB bits; if the LFSR15 was used, you must program the new bits under the 0x24 register.
        unsigned short SCOPE_ENB0 : 1; //!< Scope Enable 0  This bit enables or disables the tracing of 1's on channel 0.
        unsigned short SCOPE_ENB1 : 1; //!< Scope Enable 1  This bit enables or disables the tracing of 1's on channel 1.
        unsigned short SCOPE_ENB2 : 1; //!< Scope Enable 2  This bit enables or disables the tracing of 1's on channel 2.
        unsigned short CK_SCOPE_ENB : 1; //!< Clock Scope Enable  This bit enables or disables the tracing of 1's on the clock channel.
        unsigned short RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_phy_scopemode_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPEMODE register
 */
#define HW_HDMI_PHY_SCOPEMODE_ADDR      (REGS_HDMI_PHY_BASE + 0x1d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPEMODE           (*(volatile hw_hdmi_phy_scopemode_t *) HW_HDMI_PHY_SCOPEMODE_ADDR)
#define HW_HDMI_PHY_SCOPEMODE_RD()      (HW_HDMI_PHY_SCOPEMODE.U)
#define HW_HDMI_PHY_SCOPEMODE_WR(v)     (HW_HDMI_PHY_SCOPEMODE.U = (v))
#define HW_HDMI_PHY_SCOPEMODE_SET(v)    (HW_HDMI_PHY_SCOPEMODE_WR(HW_HDMI_PHY_SCOPEMODE_RD() |  (v)))
#define HW_HDMI_PHY_SCOPEMODE_CLR(v)    (HW_HDMI_PHY_SCOPEMODE_WR(HW_HDMI_PHY_SCOPEMODE_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPEMODE_TOG(v)    (HW_HDMI_PHY_SCOPEMODE_WR(HW_HDMI_PHY_SCOPEMODE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCOPEMODE bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPEMODE, field SCOPE_SAMPLE_CNT
 *
 * Scope Sample Counter  Indicates the number of samples that will be counted (should be multiple of
 * the LFSR length). This count includes only the LSB bits; if the LFSR15 was used, you must program
 * the new bits under the 0x24 register.
 */

#define BP_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT      0
#define BM_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT)
#else
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT(v)   (((v) << 0) & BM_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPEMODE_SCOPE_SAMPLE_CNT(v)   BF_CS1(HDMI_PHY_SCOPEMODE, SCOPE_SAMPLE_CNT, v)
#endif

/* --- Register HW_HDMI_PHY_SCOPEMODE, field SCOPE_ENB0
 *
 * Scope Enable 0  This bit enables or disables the tracing of 1's on channel 0.
 */

#define BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB0      10
#define BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB0      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB0(v)   ((((reg32_t) v) << 10) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB0)
#else
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB0(v)   (((v) << 10) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPEMODE_SCOPE_ENB0(v)   BF_CS1(HDMI_PHY_SCOPEMODE, SCOPE_ENB0, v)
#endif

/* --- Register HW_HDMI_PHY_SCOPEMODE, field SCOPE_ENB1
 *
 * Scope Enable 1  This bit enables or disables the tracing of 1's on channel 1.
 */

#define BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB1      11
#define BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB1      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB1(v)   ((((reg32_t) v) << 11) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB1)
#else
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB1(v)   (((v) << 11) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPEMODE_SCOPE_ENB1(v)   BF_CS1(HDMI_PHY_SCOPEMODE, SCOPE_ENB1, v)
#endif

/* --- Register HW_HDMI_PHY_SCOPEMODE, field SCOPE_ENB2
 *
 * Scope Enable 2  This bit enables or disables the tracing of 1's on channel 2.
 */

#define BP_HDMI_PHY_SCOPEMODE_SCOPE_ENB2      12
#define BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB2      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB2(v)   ((((reg32_t) v) << 12) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB2)
#else
#define BF_HDMI_PHY_SCOPEMODE_SCOPE_ENB2(v)   (((v) << 12) & BM_HDMI_PHY_SCOPEMODE_SCOPE_ENB2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPEMODE_SCOPE_ENB2(v)   BF_CS1(HDMI_PHY_SCOPEMODE, SCOPE_ENB2, v)
#endif

/* --- Register HW_HDMI_PHY_SCOPEMODE, field CK_SCOPE_ENB
 *
 * Clock Scope Enable  This bit enables or disables the tracing of 1's on the clock channel.
 */

#define BP_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB      13
#define BM_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB(v)   ((((reg32_t) v) << 13) & BM_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB)
#else
#define BF_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB(v)   (((v) << 13) & BM_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPEMODE_CK_SCOPE_ENB(v)   BF_CS1(HDMI_PHY_SCOPEMODE, CK_SCOPE_ENB, v)
#endif

/*!
 * @brief HW_HDMI_PHY_DIGTXMODE - Digital Transmission Mode
 *
 * Register name : DIGTXMODE  Access type : Read/write  Address : 0x1E  Value at reset : 0x0000
 * dtb_select[6:0]   The dtb_select[6:0] encodings for the bit pairs are as follows:   Power
 * Sequence    0x00: dtb[1] = pll_pwr_on and dtb[0] = pll_rst  0x01: dtb[1] = pll_pwr_on and dtb[0]
 * = pll_gear_shift  0x02: dtb[1] = pll_pwr_on and dtb[0] = pll_drv_ana  0x03: dtb[1] = pll_pwr_on
 * and dtb[0] = cko_word_enb  0x04: dtb[1] = pll_pwr_on and dtb[0] = tx_ready  0x05: dtb[1] =
 * mpll_pwr_on and dtb[0] = mpll_rst  0x06: dtb[1] = mpll_pwr_on and dtb[0] = mpll_gear_shift  0x07:
 * dtb[1] = mpll_pwr_on and dtb[0] = mpll_drv_ana  0x08: dtb[1] = mpll_pwr_on and dtb[0] =
 * cko_word_enb  0x09: dtb[1] = mpll_pwr_on and dtb[0] = tx_ready  0x0A: dtb[1] = mpll_pwr_on and
 * dtb[0] = tx_ser_div_en1  0x0B: dtb[1] = mpll_pwr_on and dtb[0] = tx_ser_clk_en1  0x0C: dtb[1] =
 * ck_ref_enb and dtb[0] = refclk_enb  0x0D: dtb[1] = cko_word_enb and dtb[0] = refclk_enb
 * Transmission Clock Alignment    0x0E: Reserved  0x0F: dtb[1] = tx_ck_align_enb and dtb[0] =
 * tx_ser_clk_kill0  0x10: dtb[1] = tx_ck_align_enb and dtb[0] = tx_ser_clk_kill1  0x11: dtb[1] =
 * tx_ck_align_enb and dtb[0] = tx_ser_clk_kill2  0x12: dtb[1] = tx_ck_align_enb and dtb[0] =
 * tx_ck_align_done    Resistance Calibration and Analog-to-Digital Converter    0x13: Reserved
 * 0x14: dtb[1] = ck_rescal[6] and dtb[0] = ck_rescal[5]  0x15: dtb[1] = ck_rescal[4] and dtb[0] =
 * ck_rescal[3]  0x16: dtb[1] = ck_rescal[2] and dtb[0] = ck_rescal[1]  0x17: dtb[1] = ck_rescal[0]
 * and dtb[0] = sup_comp_mode  0x18: dtb[1] = sup_comp_rt_result and dtb[0] = sup_comp_rt_r  0x19:
 * dtb[1] = sup_dac_n[7] and dtb[0] = sup_dac_n[6]  0x1A: dtb[1] = sup_dac_n[5] and dtb[0] =
 * sup_dac_n[4]  0x1B: dtb[1] = sup_dac_n[3] and dtb[0] = sup_dac_n[2]  0x1C: dtb[1] = sup_dac_n[1]
 * and dtb[0] = sup_dac_n[0]  0x1D: dtb[1] = sup_dac_th_n[2] and dtb[0] = sup_dac_th_n[1]  0x1E:
 * dtb[1] = sup_dac_th_n[0] and dtb[0] = rescal_rep[6]  0x1F: dtb[1] = rescal_rep[5] and dtb[0] =
 * rescal_rep[4]  0x20: dtb[1] = rescal_rep[3] and dtb[0] = rescal_rep[2]  0x21: dtb[1] =
 * rescal_rep[1] and dtb[0] = rescal_rep[0]  0x22: dtb[1] = rcal_enb and dtb[0] = rcal_adc_done
 * 0x23: dtb[1] = sup_comp_rt_pwron and dtb[0] = rcal_adc_done  0x24: Reserved  0x25: Reserved
 * 0x26: Reserved  0x27: Reserved    TMDS Data Pattern    0x28: dtb[1] = tmds_data2[9] and dtb[0] =
 * tmds_data2[8]  0x29: dtb[1] = tmds_data2[8] and dtb[0] = tmds_data2[7]  0x2A: dtb[1] =
 * tmds_data2[7] and dtb[0] = tmds_data2[6]  0x2B: dtb[1] = tmds_data2[6] and dtb[0] = tmds_data2[5]
 * 0x2C: dtb[1] = tmds_data2[5] and dtb[0] = tmds_data2[4]  0x2D: dtb[1] = tmds_data2[4] and dtb[0]
 * = tmds_data2[3]  0x2E: dtb[1] = tmds_data2[3] and dtb[0] = tmds_data2[2]  0x2F: dtb[1] =
 * tmds_data2[2] and dtb[0] = tmds_data2[1]  0x30: dtb[1] = tmds_data2[1] and dtb[0] = tmds_data2[0]
 * 0x31: dtb[1] = tmds_data2[0] and dtb[0] = tmds_data1[9]  0x32: dtb[1] = tmds_data1[9] and dtb[0]
 * = tmds_data1[8]  0x33: dtb[1] = tmds_data1[8] and dtb[0] = tmds_data1[7]  0x34: dtb[1] =
 * tmds_data1[7] and dtb[0] = tmds_data1[6]  0x35: dtb[1] = tmds_data1[6] and dtb[0] = tmds_data1[5]
 * 0x36: dtb[1] = tmds_data1[5] and dtb[0] = tmds_data1[4]  0x37: dtb[1] = tmds_data1[4] and dtb[0]
 * = tmds_data1[3]  0x38: dtb[1] = tmds_data1[3] and dtb[0] = tmds_data1[2]  0x39: dtb[1] =
 * tmds_data1[2] and dtb[0] = tmds_data1[1]  0x3A: dtb[1] = tmds_data1[1] and dtb[0] = tmds_data1[0]
 * 0x3B: dtb[1] = tmds_data1[0] and dtb[0] = tmds_data0[9]  0x3C: dtb[1] = tmds_data0[9] and dtb[0]
 * = tmds_data0[8]  0x3D: dtb[1] = tmds_data0[8] and dtb[0] = tmds_data0[7]  0x3E: dtb[1] =
 * tmds_data0[7] and dtb[0] = tmds_data0[6]  0x3F: dtb[1] = tmds_data0[6] and dtb[0] = tmds_data0[5]
 * 0x40: dtb[1] = tmds_data0[5] and dtb[0] = tmds_data0[4]  0x41: dtb[1] = tmds_data0[4] and dtb[0]
 * = tmds_data0[3]  0x42: dtb[1] = tmds_data0[3] and dtb[0] = tmds_data0[2]  0x43: dtb[1] =
 * tmds_data0[2] and dtb[0] = tmds_data0[1]  0x44: dtb[1] = tmds_data0[1] and dtb[0] = tmds_data0[0]
 * 0x45: dtb[1] = tmds_data0[0] and dtb[0] = tx_ready    Pattern Generator    0x46: dtb[1] =
 * tmds_data2[0] and dtb[0] = pg_dtb2  0x47: dtb[1] = tmds_data1[0] and dtb[0] = pg_dtb1  0x48:
 * dtb[1] = tmds_data0[0] and dtb[0] = pg_dtb0  0x49: dtb[1] = pg_dtb2 and dtb[0] = pg_dtb0  0x4A:
 * dtb[1] = pg_dtb1 and dtb[0] = pg_dtb0  0x4B: Reserved  0x4C: Reserved  0x4D: Reserved  0x4E:
 * Reserved  0x4F: Reserved    Scope    0x50: dtb[1] = scope_enb2 and dtb[0] = scope_done2  0x51:
 * dtb[1] = scope_enb1 and dtb[0] = scope_done1  0x52: dtb[1] = scope_enb0 and dtb[0] = scope_done0
 * 0x53: dtb[1] = ck_scope_enb and dtb[0] = ck_scope_done  0x54: dtb[1] = scope_enb2 and dtb[0] =
 * tx_scope_out2  0x55: dtb[1] = scope_enb1 and dtb[0] = tx_scope_out1  0x56: dtb[1] = scope_enb0
 * and dtb[0] = tx_scope_out0  0x57: Reserved  0x58: Reserved  0x59: Reserved    I  2  C    0x5A:
 * dtb[1] = start_cond and dtb[0] = cregs_write (Not stored in the control register.)  0x5B: dtb[1]
 * = sda_pull_dn_n and dtb[0] = cregs_ack (Not stored in the control register.)  0x5C: dtb[1] =
 * cregs_read and dtb[0] = cregs_rd_data[0] (Not stored in the control register.)  0x5D: Reserved
 * 0x5E: Reserved  0x5F: Reserved  0x60: Reserved  0x61: Reserved  0x62: Reserved  0x63: Reserved
 * Rx Sense    0x64: dtb[1] = rx_sense of clock driver and dtb[0] = rx_sense of CH2's driver  0x65:
 * dtb[1] = rx_sense of CH1's driver and dtb[0] = rx_sense of CH0's driver  0x66: -
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SKIP_BIT0 : 1; //!< Skip Bit 0  This bit enables or disables skipping of the ninth bit of the transmitted pattern on channel 0.
        unsigned short SKIP_BIT1 : 1; //!< Skip Bit 1  This bit enables or disables skipping of the ninth bit of the transmitted pattern on channel 1.
        unsigned short SKIP_BIT2 : 1; //!< Skip Bit 2  This bit enables or disables skipping of the ninth bit of the transmitted pattern on channel 2.
        unsigned short CKO_WORD_DIV_ENB : 1; //!< Clock Output Word Divider Enable  This bit enables or disables the output clock word divider.
        unsigned short INVERT_DATA0 : 1; //!< Inverter Data 0  This bit enables or disables the inverting feature for the transmitted pattern on channel 0.
        unsigned short INVERT_DATA1 : 1; //!< Inverter Data 1  This bit enables or disables the inverting feature for the transmitted pattern on channel 1.
        unsigned short INVERT_DATA2 : 1; //!< Inverter Data 2  This bit enables or disables the inverting feature for the transmitted pattern on channel 2.
        unsigned short DTB_SELECT : 6; //!< Debug Test Bus Select  This field determines the pair of bits placed on the dtb[1:0] bus. These selected pairs of bits come from the control register. The values that appear on dtb[1:0] are the current values actually stored in the control register (not the override values) with the exception of I 2 C values, which are not stored in the control register.  For information about the bit pairs, see dtb_select[6:0] .
        unsigned short RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_phy_digtxmode_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_DIGTXMODE register
 */
#define HW_HDMI_PHY_DIGTXMODE_ADDR      (REGS_HDMI_PHY_BASE + 0x1e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_DIGTXMODE           (*(volatile hw_hdmi_phy_digtxmode_t *) HW_HDMI_PHY_DIGTXMODE_ADDR)
#define HW_HDMI_PHY_DIGTXMODE_RD()      (HW_HDMI_PHY_DIGTXMODE.U)
#define HW_HDMI_PHY_DIGTXMODE_WR(v)     (HW_HDMI_PHY_DIGTXMODE.U = (v))
#define HW_HDMI_PHY_DIGTXMODE_SET(v)    (HW_HDMI_PHY_DIGTXMODE_WR(HW_HDMI_PHY_DIGTXMODE_RD() |  (v)))
#define HW_HDMI_PHY_DIGTXMODE_CLR(v)    (HW_HDMI_PHY_DIGTXMODE_WR(HW_HDMI_PHY_DIGTXMODE_RD() & ~(v)))
#define HW_HDMI_PHY_DIGTXMODE_TOG(v)    (HW_HDMI_PHY_DIGTXMODE_WR(HW_HDMI_PHY_DIGTXMODE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_DIGTXMODE bitfields
 */

/* --- Register HW_HDMI_PHY_DIGTXMODE, field SKIP_BIT0
 *
 * Skip Bit 0  This bit enables or disables skipping of the ninth bit of the transmitted pattern on
 * channel 0.
 */

#define BP_HDMI_PHY_DIGTXMODE_SKIP_BIT0      0
#define BM_HDMI_PHY_DIGTXMODE_SKIP_BIT0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT0(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT0)
#else
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT0(v)   (((v) << 0) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DIGTXMODE_SKIP_BIT0(v)   BF_CS1(HDMI_PHY_DIGTXMODE, SKIP_BIT0, v)
#endif

/* --- Register HW_HDMI_PHY_DIGTXMODE, field SKIP_BIT1
 *
 * Skip Bit 1  This bit enables or disables skipping of the ninth bit of the transmitted pattern on
 * channel 1.
 */

#define BP_HDMI_PHY_DIGTXMODE_SKIP_BIT1      1
#define BM_HDMI_PHY_DIGTXMODE_SKIP_BIT1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT1(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT1)
#else
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT1(v)   (((v) << 1) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DIGTXMODE_SKIP_BIT1(v)   BF_CS1(HDMI_PHY_DIGTXMODE, SKIP_BIT1, v)
#endif

/* --- Register HW_HDMI_PHY_DIGTXMODE, field SKIP_BIT2
 *
 * Skip Bit 2  This bit enables or disables skipping of the ninth bit of the transmitted pattern on
 * channel 2.
 */

#define BP_HDMI_PHY_DIGTXMODE_SKIP_BIT2      2
#define BM_HDMI_PHY_DIGTXMODE_SKIP_BIT2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT2(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT2)
#else
#define BF_HDMI_PHY_DIGTXMODE_SKIP_BIT2(v)   (((v) << 2) & BM_HDMI_PHY_DIGTXMODE_SKIP_BIT2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DIGTXMODE_SKIP_BIT2(v)   BF_CS1(HDMI_PHY_DIGTXMODE, SKIP_BIT2, v)
#endif

/* --- Register HW_HDMI_PHY_DIGTXMODE, field CKO_WORD_DIV_ENB
 *
 * Clock Output Word Divider Enable  This bit enables or disables the output clock word divider.
 */

#define BP_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB      3
#define BM_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB)
#else
#define BF_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB(v)   (((v) << 3) & BM_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DIGTXMODE_CKO_WORD_DIV_ENB(v)   BF_CS1(HDMI_PHY_DIGTXMODE, CKO_WORD_DIV_ENB, v)
#endif

/* --- Register HW_HDMI_PHY_DIGTXMODE, field INVERT_DATA0
 *
 * Inverter Data 0  This bit enables or disables the inverting feature for the transmitted pattern
 * on channel 0.
 */

#define BP_HDMI_PHY_DIGTXMODE_INVERT_DATA0      4
#define BM_HDMI_PHY_DIGTXMODE_INVERT_DATA0      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA0(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA0)
#else
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA0(v)   (((v) << 4) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DIGTXMODE_INVERT_DATA0(v)   BF_CS1(HDMI_PHY_DIGTXMODE, INVERT_DATA0, v)
#endif

/* --- Register HW_HDMI_PHY_DIGTXMODE, field INVERT_DATA1
 *
 * Inverter Data 1  This bit enables or disables the inverting feature for the transmitted pattern
 * on channel 1.
 */

#define BP_HDMI_PHY_DIGTXMODE_INVERT_DATA1      5
#define BM_HDMI_PHY_DIGTXMODE_INVERT_DATA1      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA1(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA1)
#else
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA1(v)   (((v) << 5) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DIGTXMODE_INVERT_DATA1(v)   BF_CS1(HDMI_PHY_DIGTXMODE, INVERT_DATA1, v)
#endif

/* --- Register HW_HDMI_PHY_DIGTXMODE, field INVERT_DATA2
 *
 * Inverter Data 2  This bit enables or disables the inverting feature for the transmitted pattern
 * on channel 2.
 */

#define BP_HDMI_PHY_DIGTXMODE_INVERT_DATA2      6
#define BM_HDMI_PHY_DIGTXMODE_INVERT_DATA2      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA2(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA2)
#else
#define BF_HDMI_PHY_DIGTXMODE_INVERT_DATA2(v)   (((v) << 6) & BM_HDMI_PHY_DIGTXMODE_INVERT_DATA2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DIGTXMODE_INVERT_DATA2(v)   BF_CS1(HDMI_PHY_DIGTXMODE, INVERT_DATA2, v)
#endif

/* --- Register HW_HDMI_PHY_DIGTXMODE, field DTB_SELECT
 *
 * Debug Test Bus Select  This field determines the pair of bits placed on the dtb[1:0] bus. These
 * selected pairs of bits come from the control register. The values that appear on dtb[1:0] are the
 * current values actually stored in the control register (not the override values) with the
 * exception of I 2 C values, which are not stored in the control register.  For information about
 * the bit pairs, see dtb_select[6:0] .
 */

#define BP_HDMI_PHY_DIGTXMODE_DTB_SELECT      7
#define BM_HDMI_PHY_DIGTXMODE_DTB_SELECT      0x00001f80

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_DIGTXMODE_DTB_SELECT(v)   ((((reg32_t) v) << 7) & BM_HDMI_PHY_DIGTXMODE_DTB_SELECT)
#else
#define BF_HDMI_PHY_DIGTXMODE_DTB_SELECT(v)   (((v) << 7) & BM_HDMI_PHY_DIGTXMODE_DTB_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_DIGTXMODE_DTB_SELECT(v)   BF_CS1(HDMI_PHY_DIGTXMODE, DTB_SELECT, v)
#endif

/*!
 * @brief HW_HDMI_PHY_STR_STATUS - Scope, Transmission Clock Alignment, and Resistance Calibration Set-on-Done Status
 *
 * Register name : -  Access type : Read/write/asynchronous set-on-done  Address : 0x1F  Value at
 * reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_DONE0 : 1; //!< Scope Done 0  This bit indicates the status of tracing of 1's on channel 0.
        unsigned short SCOPE_DONE1 : 1; //!< Scope Done 1  This bit indicates the status of tracing of 1's on channel 1.
        unsigned short SCOPE_DONE2 : 1; //!< Scope Done 2  This bit indicates the status of tracing of 1's on channel 2.
        unsigned short CK_SCOPE_DONE : 1; //!< Clock Scope Done  This bit indicates the status of tracing of 1's on the clock channel.
        unsigned short TX_CK_ALIGN_DONE : 1; //!< Transmission Clock Alignment Done  This bit indicates the status of completing the transmission clock alignment FSM.
        unsigned short RCAL_ADC_DONE : 1; //!< Resistance Calibration Analog-to-Digital Converter Done  This bit indicates the status of completing the resistance calibration FSM.
        unsigned short RESERVED0 : 10; //!< Reserved
    } B;
} hw_hdmi_phy_str_status_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_STR_STATUS register
 */
#define HW_HDMI_PHY_STR_STATUS_ADDR      (REGS_HDMI_PHY_BASE + 0x1f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_STR_STATUS           (*(volatile hw_hdmi_phy_str_status_t *) HW_HDMI_PHY_STR_STATUS_ADDR)
#define HW_HDMI_PHY_STR_STATUS_RD()      (HW_HDMI_PHY_STR_STATUS.U)
#define HW_HDMI_PHY_STR_STATUS_WR(v)     (HW_HDMI_PHY_STR_STATUS.U = (v))
#define HW_HDMI_PHY_STR_STATUS_SET(v)    (HW_HDMI_PHY_STR_STATUS_WR(HW_HDMI_PHY_STR_STATUS_RD() |  (v)))
#define HW_HDMI_PHY_STR_STATUS_CLR(v)    (HW_HDMI_PHY_STR_STATUS_WR(HW_HDMI_PHY_STR_STATUS_RD() & ~(v)))
#define HW_HDMI_PHY_STR_STATUS_TOG(v)    (HW_HDMI_PHY_STR_STATUS_WR(HW_HDMI_PHY_STR_STATUS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_STR_STATUS bitfields
 */

/* --- Register HW_HDMI_PHY_STR_STATUS, field SCOPE_DONE0
 *
 * Scope Done 0  This bit indicates the status of tracing of 1's on channel 0.
 */

#define BP_HDMI_PHY_STR_STATUS_SCOPE_DONE0      0
#define BM_HDMI_PHY_STR_STATUS_SCOPE_DONE0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE0(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE0)
#else
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE0(v)   (((v) << 0) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_STR_STATUS_SCOPE_DONE0(v)   BF_CS1(HDMI_PHY_STR_STATUS, SCOPE_DONE0, v)
#endif

/* --- Register HW_HDMI_PHY_STR_STATUS, field SCOPE_DONE1
 *
 * Scope Done 1  This bit indicates the status of tracing of 1's on channel 1.
 */

#define BP_HDMI_PHY_STR_STATUS_SCOPE_DONE1      1
#define BM_HDMI_PHY_STR_STATUS_SCOPE_DONE1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE1(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE1)
#else
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE1(v)   (((v) << 1) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_STR_STATUS_SCOPE_DONE1(v)   BF_CS1(HDMI_PHY_STR_STATUS, SCOPE_DONE1, v)
#endif

/* --- Register HW_HDMI_PHY_STR_STATUS, field SCOPE_DONE2
 *
 * Scope Done 2  This bit indicates the status of tracing of 1's on channel 2.
 */

#define BP_HDMI_PHY_STR_STATUS_SCOPE_DONE2      2
#define BM_HDMI_PHY_STR_STATUS_SCOPE_DONE2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE2(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE2)
#else
#define BF_HDMI_PHY_STR_STATUS_SCOPE_DONE2(v)   (((v) << 2) & BM_HDMI_PHY_STR_STATUS_SCOPE_DONE2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_STR_STATUS_SCOPE_DONE2(v)   BF_CS1(HDMI_PHY_STR_STATUS, SCOPE_DONE2, v)
#endif

/* --- Register HW_HDMI_PHY_STR_STATUS, field CK_SCOPE_DONE
 *
 * Clock Scope Done  This bit indicates the status of tracing of 1's on the clock channel.
 */

#define BP_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE      3
#define BM_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE)
#else
#define BF_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE(v)   (((v) << 3) & BM_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_STR_STATUS_CK_SCOPE_DONE(v)   BF_CS1(HDMI_PHY_STR_STATUS, CK_SCOPE_DONE, v)
#endif

/* --- Register HW_HDMI_PHY_STR_STATUS, field TX_CK_ALIGN_DONE
 *
 * Transmission Clock Alignment Done  This bit indicates the status of completing the transmission
 * clock alignment FSM.
 */

#define BP_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE      4
#define BM_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE)
#else
#define BF_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE(v)   (((v) << 4) & BM_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_STR_STATUS_TX_CK_ALIGN_DONE(v)   BF_CS1(HDMI_PHY_STR_STATUS, TX_CK_ALIGN_DONE, v)
#endif

/* --- Register HW_HDMI_PHY_STR_STATUS, field RCAL_ADC_DONE
 *
 * Resistance Calibration Analog-to-Digital Converter Done  This bit indicates the status of
 * completing the resistance calibration FSM.
 */

#define BP_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE      5
#define BM_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE)
#else
#define BF_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE(v)   (((v) << 5) & BM_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_STR_STATUS_RCAL_ADC_DONE(v)   BF_CS1(HDMI_PHY_STR_STATUS, RCAL_ADC_DONE, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCOPECNT0 - Scope Counter on Channel 0
 *
 * Register name : SCOPECNT0  Access type : Read-only  Address : 0x20  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_ONES_CNT0 : 16; //!< Scope 1's Counter 0  This register carries the number of counted 1's on channel 0. If the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x25 register.
    } B;
} hw_hdmi_phy_scopecnt0_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNT0 register
 */
#define HW_HDMI_PHY_SCOPECNT0_ADDR      (REGS_HDMI_PHY_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNT0           (*(volatile hw_hdmi_phy_scopecnt0_t *) HW_HDMI_PHY_SCOPECNT0_ADDR)
#define HW_HDMI_PHY_SCOPECNT0_RD()      (HW_HDMI_PHY_SCOPECNT0.U)
#define HW_HDMI_PHY_SCOPECNT0_WR(v)     (HW_HDMI_PHY_SCOPECNT0.U = (v))
#define HW_HDMI_PHY_SCOPECNT0_SET(v)    (HW_HDMI_PHY_SCOPECNT0_WR(HW_HDMI_PHY_SCOPECNT0_RD() |  (v)))
#define HW_HDMI_PHY_SCOPECNT0_CLR(v)    (HW_HDMI_PHY_SCOPECNT0_WR(HW_HDMI_PHY_SCOPECNT0_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPECNT0_TOG(v)    (HW_HDMI_PHY_SCOPECNT0_WR(HW_HDMI_PHY_SCOPECNT0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCOPECNT0 bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNT0, field SCOPE_ONES_CNT0
 *
 * Scope 1's Counter 0  This register carries the number of counted 1's on channel 0. If the LFSR15
 * was used to generate the scope patterns, you must read the MSB bits under 0x25 register.
 */

#define BP_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0      0
#define BM_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0)
#else
#define BF_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0(v)   (((v) << 0) & BM_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPECNT0_SCOPE_ONES_CNT0(v)   BF_CS1(HDMI_PHY_SCOPECNT0, SCOPE_ONES_CNT0, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCOPECNT1 - Scope Counter on Channel 1
 *
 * Register name : SCOPECNT1  Access type : Read-only  Address : 0x21  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_ONES_CNT1 : 16; //!< Scope 1's Counter 1  This register carries the number of counted 1's on channel 1. If the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x25 register.
    } B;
} hw_hdmi_phy_scopecnt1_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNT1 register
 */
#define HW_HDMI_PHY_SCOPECNT1_ADDR      (REGS_HDMI_PHY_BASE + 0x21)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNT1           (*(volatile hw_hdmi_phy_scopecnt1_t *) HW_HDMI_PHY_SCOPECNT1_ADDR)
#define HW_HDMI_PHY_SCOPECNT1_RD()      (HW_HDMI_PHY_SCOPECNT1.U)
#define HW_HDMI_PHY_SCOPECNT1_WR(v)     (HW_HDMI_PHY_SCOPECNT1.U = (v))
#define HW_HDMI_PHY_SCOPECNT1_SET(v)    (HW_HDMI_PHY_SCOPECNT1_WR(HW_HDMI_PHY_SCOPECNT1_RD() |  (v)))
#define HW_HDMI_PHY_SCOPECNT1_CLR(v)    (HW_HDMI_PHY_SCOPECNT1_WR(HW_HDMI_PHY_SCOPECNT1_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPECNT1_TOG(v)    (HW_HDMI_PHY_SCOPECNT1_WR(HW_HDMI_PHY_SCOPECNT1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCOPECNT1 bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNT1, field SCOPE_ONES_CNT1
 *
 * Scope 1's Counter 1  This register carries the number of counted 1's on channel 1. If the LFSR15
 * was used to generate the scope patterns, you must read the MSB bits under 0x25 register.
 */

#define BP_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1      0
#define BM_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1)
#else
#define BF_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1(v)   (((v) << 0) & BM_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPECNT1_SCOPE_ONES_CNT1(v)   BF_CS1(HDMI_PHY_SCOPECNT1, SCOPE_ONES_CNT1, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCOPECNT2 - Scope Counter on Channel 2
 *
 * Register name : SCOPECNT2  Access type : Read-only  Address : 0x22  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_ONES_CNT2 : 16; //!< Scope 1's Counter 2  This register carries the number of counted 1's on channel 2. If the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x26 register.
    } B;
} hw_hdmi_phy_scopecnt2_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNT2 register
 */
#define HW_HDMI_PHY_SCOPECNT2_ADDR      (REGS_HDMI_PHY_BASE + 0x22)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNT2           (*(volatile hw_hdmi_phy_scopecnt2_t *) HW_HDMI_PHY_SCOPECNT2_ADDR)
#define HW_HDMI_PHY_SCOPECNT2_RD()      (HW_HDMI_PHY_SCOPECNT2.U)
#define HW_HDMI_PHY_SCOPECNT2_WR(v)     (HW_HDMI_PHY_SCOPECNT2.U = (v))
#define HW_HDMI_PHY_SCOPECNT2_SET(v)    (HW_HDMI_PHY_SCOPECNT2_WR(HW_HDMI_PHY_SCOPECNT2_RD() |  (v)))
#define HW_HDMI_PHY_SCOPECNT2_CLR(v)    (HW_HDMI_PHY_SCOPECNT2_WR(HW_HDMI_PHY_SCOPECNT2_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPECNT2_TOG(v)    (HW_HDMI_PHY_SCOPECNT2_WR(HW_HDMI_PHY_SCOPECNT2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCOPECNT2 bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNT2, field SCOPE_ONES_CNT2
 *
 * Scope 1's Counter 2  This register carries the number of counted 1's on channel 2. If the LFSR15
 * was used to generate the scope patterns, you must read the MSB bits under 0x26 register.
 */

#define BP_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2      0
#define BM_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2)
#else
#define BF_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2(v)   (((v) << 0) & BM_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPECNT2_SCOPE_ONES_CNT2(v)   BF_CS1(HDMI_PHY_SCOPECNT2, SCOPE_ONES_CNT2, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCOPECNTCLK - Scope Counter on Clock Channel
 *
 * Register name : SCOPECNTCK  Access type : Read-only  Address : 0x23  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short CK_SCOPE_ONES_CNT : 16; //!< Clock Scope 1's Counter  This register carries the number of counted 1's on the clock channel. If the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x26 register.
    } B;
} hw_hdmi_phy_scopecntclk_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNTCLK register
 */
#define HW_HDMI_PHY_SCOPECNTCLK_ADDR      (REGS_HDMI_PHY_BASE + 0x23)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNTCLK           (*(volatile hw_hdmi_phy_scopecntclk_t *) HW_HDMI_PHY_SCOPECNTCLK_ADDR)
#define HW_HDMI_PHY_SCOPECNTCLK_RD()      (HW_HDMI_PHY_SCOPECNTCLK.U)
#define HW_HDMI_PHY_SCOPECNTCLK_WR(v)     (HW_HDMI_PHY_SCOPECNTCLK.U = (v))
#define HW_HDMI_PHY_SCOPECNTCLK_SET(v)    (HW_HDMI_PHY_SCOPECNTCLK_WR(HW_HDMI_PHY_SCOPECNTCLK_RD() |  (v)))
#define HW_HDMI_PHY_SCOPECNTCLK_CLR(v)    (HW_HDMI_PHY_SCOPECNTCLK_WR(HW_HDMI_PHY_SCOPECNTCLK_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPECNTCLK_TOG(v)    (HW_HDMI_PHY_SCOPECNTCLK_WR(HW_HDMI_PHY_SCOPECNTCLK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCOPECNTCLK bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNTCLK, field CK_SCOPE_ONES_CNT
 *
 * Clock Scope 1's Counter  This register carries the number of counted 1's on the clock channel. If
 * the LFSR15 was used to generate the scope patterns, you must read the MSB bits under 0x26
 * register.
 */

#define BP_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT      0
#define BM_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT)
#else
#define BF_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT(v)   (((v) << 0) & BM_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPECNTCLK_CK_SCOPE_ONES_CNT(v)   BF_CS1(HDMI_PHY_SCOPECNTCLK, CK_SCOPE_ONES_CNT, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCOPESAMPLE - Scope Sample Count MSB, Scope Sample Repetition
 *
 * Register name : SCOPESAMPLE  Access type : Read/write  Address : 0x24  Value at reset : 0x13c0
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_SAMPLE_CNT : 6; //!< Scope Sample Counter  Indicates the number of samples that will be counted (should be multiple of the  LFSR length). These samples are the MSB bits only.
        unsigned short SCOPE_SAMPLE_REP : 7; //!< Scope Sample Repetition  Number of repetitions made by the scope FSM. The total samples captured is scope_sample_rep x scope_sample_cnt.
        unsigned short RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_phy_scopesample_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPESAMPLE register
 */
#define HW_HDMI_PHY_SCOPESAMPLE_ADDR      (REGS_HDMI_PHY_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPESAMPLE           (*(volatile hw_hdmi_phy_scopesample_t *) HW_HDMI_PHY_SCOPESAMPLE_ADDR)
#define HW_HDMI_PHY_SCOPESAMPLE_RD()      (HW_HDMI_PHY_SCOPESAMPLE.U)
#define HW_HDMI_PHY_SCOPESAMPLE_WR(v)     (HW_HDMI_PHY_SCOPESAMPLE.U = (v))
#define HW_HDMI_PHY_SCOPESAMPLE_SET(v)    (HW_HDMI_PHY_SCOPESAMPLE_WR(HW_HDMI_PHY_SCOPESAMPLE_RD() |  (v)))
#define HW_HDMI_PHY_SCOPESAMPLE_CLR(v)    (HW_HDMI_PHY_SCOPESAMPLE_WR(HW_HDMI_PHY_SCOPESAMPLE_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPESAMPLE_TOG(v)    (HW_HDMI_PHY_SCOPESAMPLE_WR(HW_HDMI_PHY_SCOPESAMPLE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCOPESAMPLE bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPESAMPLE, field SCOPE_SAMPLE_CNT
 *
 * Scope Sample Counter  Indicates the number of samples that will be counted (should be multiple of
 * the  LFSR length). These samples are the MSB bits only.
 */

#define BP_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT      0
#define BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT)
#else
#define BF_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT(v)   (((v) << 0) & BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_CNT(v)   BF_CS1(HDMI_PHY_SCOPESAMPLE, SCOPE_SAMPLE_CNT, v)
#endif

/* --- Register HW_HDMI_PHY_SCOPESAMPLE, field SCOPE_SAMPLE_REP
 *
 * Scope Sample Repetition  Number of repetitions made by the scope FSM. The total samples captured
 * is scope_sample_rep x scope_sample_cnt.
 */

#define BP_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP      6
#define BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP      0x00001fc0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP)
#else
#define BF_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP(v)   (((v) << 6) & BM_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPESAMPLE_SCOPE_SAMPLE_REP(v)   BF_CS1(HDMI_PHY_SCOPESAMPLE, SCOPE_SAMPLE_REP, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCOPECNTMSB01 - Scope Counter MSB Channel 0 and Channel 1
 *
 * Register name : SCOPECNTMSB01  Access type : Read-only  Address : 0x25  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_ONES_CNT0 : 8; //!< Scope 1's Counter 0  This register carries the number of counted 1's on channel 0. These 1's are the  MSB bits only.
        unsigned short SCOPE_ONES_CNT1 : 5; //!< Scope 1's Counter 1  This register carries the number of counted 1's on channel 1. These 1's are the  MSB bits only.
        unsigned short RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_phy_scopecntmsb01_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNTMSB01 register
 */
#define HW_HDMI_PHY_SCOPECNTMSB01_ADDR      (REGS_HDMI_PHY_BASE + 0x25)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNTMSB01           (*(volatile hw_hdmi_phy_scopecntmsb01_t *) HW_HDMI_PHY_SCOPECNTMSB01_ADDR)
#define HW_HDMI_PHY_SCOPECNTMSB01_RD()      (HW_HDMI_PHY_SCOPECNTMSB01.U)
#define HW_HDMI_PHY_SCOPECNTMSB01_WR(v)     (HW_HDMI_PHY_SCOPECNTMSB01.U = (v))
#define HW_HDMI_PHY_SCOPECNTMSB01_SET(v)    (HW_HDMI_PHY_SCOPECNTMSB01_WR(HW_HDMI_PHY_SCOPECNTMSB01_RD() |  (v)))
#define HW_HDMI_PHY_SCOPECNTMSB01_CLR(v)    (HW_HDMI_PHY_SCOPECNTMSB01_WR(HW_HDMI_PHY_SCOPECNTMSB01_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPECNTMSB01_TOG(v)    (HW_HDMI_PHY_SCOPECNTMSB01_WR(HW_HDMI_PHY_SCOPECNTMSB01_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCOPECNTMSB01 bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNTMSB01, field SCOPE_ONES_CNT0
 *
 * Scope 1's Counter 0  This register carries the number of counted 1's on channel 0. These 1's are
 * the  MSB bits only.
 */

#define BP_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0      0
#define BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0)
#else
#define BF_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0(v)   (((v) << 0) & BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT0(v)   BF_CS1(HDMI_PHY_SCOPECNTMSB01, SCOPE_ONES_CNT0, v)
#endif

/* --- Register HW_HDMI_PHY_SCOPECNTMSB01, field SCOPE_ONES_CNT1
 *
 * Scope 1's Counter 1  This register carries the number of counted 1's on channel 1. These 1's are
 * the  MSB bits only.
 */

#define BP_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1      8
#define BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1(v)   ((((reg32_t) v) << 8) & BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1)
#else
#define BF_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1(v)   (((v) << 8) & BM_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPECNTMSB01_SCOPE_ONES_CNT1(v)   BF_CS1(HDMI_PHY_SCOPECNTMSB01, SCOPE_ONES_CNT1, v)
#endif

/*!
 * @brief HW_HDMI_PHY_SCOPECNTMSB2CK - Scope Counter MSB Channel 2 and Clock Channel
 *
 * Register name : SCOPECNTMSB2CK  Access type : Read-only  Address : 0x26  Value at reset : 0x0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SCOPE_ONES_CNT2 : 6; //!< Scope 1's Counter 2  This register carries the number of counted 1's on channel 2. These 1's are the  MSB bits only.
        unsigned short CK_SCOPE_ONES_CNT : 7; //!< Clock Scope 1's Counter  This register carries the number of counted 1's on the clock channel. These 1's are the MSB bits only.
        unsigned short RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_phy_scopecntmsb2ck_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_SCOPECNTMSB2CK register
 */
#define HW_HDMI_PHY_SCOPECNTMSB2CK_ADDR      (REGS_HDMI_PHY_BASE + 0x26)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_SCOPECNTMSB2CK           (*(volatile hw_hdmi_phy_scopecntmsb2ck_t *) HW_HDMI_PHY_SCOPECNTMSB2CK_ADDR)
#define HW_HDMI_PHY_SCOPECNTMSB2CK_RD()      (HW_HDMI_PHY_SCOPECNTMSB2CK.U)
#define HW_HDMI_PHY_SCOPECNTMSB2CK_WR(v)     (HW_HDMI_PHY_SCOPECNTMSB2CK.U = (v))
#define HW_HDMI_PHY_SCOPECNTMSB2CK_SET(v)    (HW_HDMI_PHY_SCOPECNTMSB2CK_WR(HW_HDMI_PHY_SCOPECNTMSB2CK_RD() |  (v)))
#define HW_HDMI_PHY_SCOPECNTMSB2CK_CLR(v)    (HW_HDMI_PHY_SCOPECNTMSB2CK_WR(HW_HDMI_PHY_SCOPECNTMSB2CK_RD() & ~(v)))
#define HW_HDMI_PHY_SCOPECNTMSB2CK_TOG(v)    (HW_HDMI_PHY_SCOPECNTMSB2CK_WR(HW_HDMI_PHY_SCOPECNTMSB2CK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual HDMI_PHY_SCOPECNTMSB2CK bitfields
 */

/* --- Register HW_HDMI_PHY_SCOPECNTMSB2CK, field SCOPE_ONES_CNT2
 *
 * Scope 1's Counter 2  This register carries the number of counted 1's on channel 2. These 1's are
 * the  MSB bits only.
 */

#define BP_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2      0
#define BM_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2)
#else
#define BF_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2(v)   (((v) << 0) & BM_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPECNTMSB2CK_SCOPE_ONES_CNT2(v)   BF_CS1(HDMI_PHY_SCOPECNTMSB2CK, SCOPE_ONES_CNT2, v)
#endif

/* --- Register HW_HDMI_PHY_SCOPECNTMSB2CK, field CK_SCOPE_ONES_CNT
 *
 * Clock Scope 1's Counter  This register carries the number of counted 1's on the clock channel.
 * These 1's are the MSB bits only.
 */

#define BP_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT      6
#define BM_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT      0x00001fc0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT)
#else
#define BF_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT(v)   (((v) << 6) & BM_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_HDMI_PHY_SCOPECNTMSB2CK_CK_SCOPE_ONES_CNT(v)   BF_CS1(HDMI_PHY_SCOPECNTMSB2CK, CK_SCOPE_ONES_CNT, v)
#endif



/*!
 * @brief All HDMI_PHY module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_hdmi_phy_pwrctrl_t PWRCTRL; //!< Power Control
    volatile hw_hdmi_phy_serdivctrl_t SERDIVCTRL; //!< Serializer Divider Control
    volatile hw_hdmi_phy_serckctrl_t SERCKCTRL; //!< Serializer Clock Control
    volatile hw_hdmi_phy_serckkillctrl_t SERCKKILLCTRL; //!< Serializer Clock Kill Control
    volatile hw_hdmi_phy_txresctrl_t TXRESCTRL; //!< Transmitter and Resistance Calibration Control
    volatile hw_hdmi_phy_ckcalctrl_t CKCALCTRL; //!< Clock Calibration Control
    volatile hw_hdmi_phy_cpce_ctrl_t CPCE_CTRL; //!< Color Depth, Pixel Repetition, Clock Divider for PLL and MPLL, and Edge Rate Control
    volatile hw_hdmi_phy_txclkmeasctrl_t TXCLKMEASCTRL; //!< Tx and Clock Measure Control
    volatile hw_hdmi_phy_txmeasctrl_t TXMEASCTRL; //!< Tx Measure Control
    volatile hw_hdmi_phy_cksymtxctrl_t CKSYMTXCTRL; //!< Clock Symbol and Transmitter Control
    volatile hw_hdmi_phy_cmpseqctrl_t CMPSEQCTRL; //!< Comparator Sequence Control
    volatile hw_hdmi_phy_cmppwrctrl_t CMPPWRCTRL; //!< Comparator Power Control
    volatile hw_hdmi_phy_cmpmodectrl_t CMPMODECTRL; //!< Comparator Mode Control
    volatile hw_hdmi_phy_measctrl_t MEASCTRL; //!< Measure Control
    volatile hw_hdmi_phy_vlevctrl_t VLEVCTRL; //!< Voltage Level Control
    volatile hw_hdmi_phy_d2actrl_t D2ACTRL; //!< Digital-to-Analog Control
    volatile hw_hdmi_phy_currctrl_t CURRCTRL; //!< Current Control
    volatile hw_hdmi_phy_drvanactrl_t DRVANACTRL; //!< Drive Analog Control
    volatile hw_hdmi_phy_pllmeasctrl_t PLLMEASCTRL; //!< PLL Measure Control
    volatile hw_hdmi_phy_pllphbyctrl_t PLLPHBYCTRL; //!< PLL Phase and Bypass Control
    volatile hw_hdmi_phy_grp_ctrl_t GRP_CTRL; //!< Gear Shift, Reset Mode, and Power State Control
    volatile hw_hdmi_phy_gmpctrl_t GMPCTRL; //!< Gmp Control
    volatile hw_hdmi_phy_mpllmeasctrl_t MPLLMEASCTRL; //!< MPLL Measure Control
    volatile hw_hdmi_phy_msm_ctrl_t MSM_CTRL; //!< MPLL and PLL Phase, Scope Clock Select, and MUX Clock Control
    volatile hw_hdmi_phy_scrpb_status_t SCRPB_STATUS; //!< Scope, Comparator Result and Power Bad Status
    volatile hw_hdmi_phy_txterm_t TXTERM; //!< Transmission Termination
    volatile hw_hdmi_phy_ptrpt_enbl_t PTRPT_ENBL; //!< Power Sequence, TX Clock Alignment, Resistance Calibration, Pattern Generator Skip Bit, and TMDS Encoder Enable
    volatile hw_hdmi_phy_patterngen_t PATTERNGEN; //!< Pattern Generator Mode
    volatile hw_hdmi_phy_sdcap_mode_t SDCAP_MODE; //!< The Soft-Reset and DAC Enable, Clock Alignment and PG Mode
    volatile hw_hdmi_phy_scopemode_t SCOPEMODE; //!< Scope Mode register
    volatile hw_hdmi_phy_digtxmode_t DIGTXMODE; //!< Digital Transmission Mode
    volatile hw_hdmi_phy_str_status_t STR_STATUS; //!< Scope, Transmission Clock Alignment, and Resistance Calibration Set-on-Done Status
    volatile hw_hdmi_phy_scopecnt0_t SCOPECNT0; //!< Scope Counter on Channel 0
    volatile hw_hdmi_phy_scopecnt1_t SCOPECNT1; //!< Scope Counter on Channel 1
    volatile hw_hdmi_phy_scopecnt2_t SCOPECNT2; //!< Scope Counter on Channel 2
    volatile hw_hdmi_phy_scopecntclk_t SCOPECNTCLK; //!< Scope Counter on Clock Channel
    volatile hw_hdmi_phy_scopesample_t SCOPESAMPLE; //!< Scope Sample Count MSB, Scope Sample Repetition
    volatile hw_hdmi_phy_scopecntmsb01_t SCOPECNTMSB01; //!< Scope Counter MSB Channel 0 and Channel 1
    volatile hw_hdmi_phy_scopecntmsb2ck_t SCOPECNTMSB2CK; //!< Scope Counter MSB Channel 2 and Clock Channel
} hw_hdmi_phy_t
#endif

//! @brief Macro to access all HDMI_PHY registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_HDMI_PHY(0)</code>.
#define HW_HDMI_PHY     (*(volatile hw_hdmi_phy_t *) REGS_HDMI_PHY_BASE)


#endif // _HDMI_PHY_H
