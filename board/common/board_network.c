/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/* ENET iomux config */
void imx_ar8031_iomux()
{
    enet_iomux_config();        // iomux tool output
}

/*CPU_PER_RST_B low to high*/
void imx_ar8031_reset(void)
{
#if defined(BOARD_SMART_DEVICE)
    /* Select ALT5 mode of ENET_CRS-DV for GPIO1_25 - PGMII_NRST */
    /* active low output */
    gpio_set_direction(GPIO_PORT1, 25, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 25, GPIO_LOW_LEVEL);
    hal_delay_us(500);
    gpio_set_level(GPIO_PORT1, 25, GPIO_HIGH_LEVEL);
#elif defined(BOARD_SABRE_AI) && !defined(BOARD_REV_A)
    /* CPU_PER_RST_B low to high */
//    max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
//    hal_delay_us(1000);
//    max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
#endif
}

/*CPU_PER_RST_B low to high*/
void imx_KSZ9021RN_reset(void)
{
    //max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    //hal_delay_us(1000000);
    //max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
#ifdef BOARD_SABRE_LITE
    // Config gpio3_GPIO[23] to pad EIM_D23(D25)
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0x7), IOMUXC_SW_MUX_CTL_PAD_EIM_D23);
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D23);
    writel((readl(GPIO3_BASE_ADDR + 0x4) | (1 << 23)), GPIO3_BASE_ADDR + 0x4);  /*output */
    writel(readl(GPIO3_BASE_ADDR + 0x0) & ~(1 << 23), GPIO3_BASE_ADDR + 0x0);   // output low
    hal_delay_us(1000000);      // hold in reset for a delay
    writel(readl(GPIO3_BASE_ADDR + 0x0) | (1 << 23), GPIO3_BASE_ADDR + 0x0);
#endif
}

/*! From obds
 * ENET iomux config
 */
void imx_enet_iomux(void)
{
    enet_iomux_config();        // iomux tool output

#ifdef BOARD_SABRE_AI
    /* Select ENET, ENET_CAN1_STEER(PORT_EXP_B3) */
    max7310_set_gpio_output(1, 2, GPIO_LOW_LEVEL);
    /* Select ALT5 mode of GPIO_19 for GPIO4_5 - PGMIT_INT_B */
    /* active low input */
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_GPIO_19);
    gpio_set_direction(GPIO_PORT4, 5, GPIO_GDIR_INPUT);
#endif
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
