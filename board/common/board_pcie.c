/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "registers/regsccm.h"
#include "registers/regsccmanalog.h"
#include "registers/regspmu.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void pcie_clk_setup(uint32_t enable)
{
    if (enable) {
        // gate on pci-e clks
        HW_CCM_CCGR4.B.CG0 = CLOCK_ON;

        // clear the powerdown bit
        HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_POWERDOWN);
        // enable pll
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE);
        // wait the pll locked
        while (!HW_CCM_ANALOG_PLL_ENET.B.LOCK) ;
        // Disable bypass
        HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_BYPASS);
        // enable pci-e ref clk
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_125M);
    }
}

void pcie_card_pwr_setup(uint32_t enable)
{
    i2c_init(I2C3_BASE_ADDR, 100000);

    if (enable) {
        //enable pciemini_3.3v
        max7310_set_gpio_output(1, 2, 1);
    } else {
        max7310_set_gpio_output(1, 2, 0);
    }
}

void enable_extrn_125mhz_clk(uint32_t enable)
{
    if (enable) {
        // Disable SATA clock gating used as external reference
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_100M);

        // Select PCIe clock source and switch to output buffer.
        HW_PMU_MISC1_CLR(BM_PMU_MISC1_LVDSCLK1_IBEN);
        HW_PMU_MISC1.B.LVDS1_CLK_SEL = BV_PMU_MISC1_LVDS1_CLK_SEL__PCIE_REF;
        HW_PMU_MISC1_SET(BM_PMU_MISC1_LVDSCLK1_OBEN);
    }
}

void pcie_card_rst(void)
{
    i2c_init(I2C3_BASE_ADDR, 100000);

    max7310_set_gpio_output(0, 2, 0);

    hal_delay_us(200 * 1000);

    max7310_set_gpio_output(0, 2, 1);
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
