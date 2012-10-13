/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "registers/regsccm.h"
#include "registers/regsccmanalog.h"
#include "registers/regsiomuxc.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
/*!
 * Provide the mipi camera power and reset
 */
void mipi_cam_power_on(void)
{
#if defined(BOARD_EVB)
    /*reset of camera sensor, pin 27 */
    max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);

    /*power supply through pin25 of connector, for cam_pdown, power down and then up */
    max7310_set_gpio_output(0, 0, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
//    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);
#endif

#if defined(BOARD_SABRE_AI)
    /*power supply through pin25 of connector, direct connected to P3V3_DELAY,
       controlled by CPU_PER_RST_B */
    /*reset of camera sensor, together with the reset button */
    max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);

#endif

#if defined(BOARD_SMART_DEVICE)
    /*power supply through pin25 of connector, for cam_pdown */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B, 0x1B0B0);
    gpio_set_direction(GPIO_PORT6, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 9, GPIO_HIGH_LEVEL);

    /*reset of camera sensor, pin 27 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0, 0x1B0B0);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
#endif
}

/*!
 * enable mipi backlight
 */
void mipi_backlight_en(void)
{
    //configure pin19 of the mipi dsi/csi connector
#ifdef BOARD_EVB
    //set GPIO1_9 to 0 so clear vbus on board
    gpio_set_direction(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef BOARD_SABRE_AI
    //default be populated by P3V3_DELAYED
#endif

#ifdef BOARD_SMART_DEVICE
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_D0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_D0, 0x1B0B0);
    gpio_set_direction(GPIO_PORT2, 0, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 0, GPIO_HIGH_LEVEL);
#endif
}

/*!
 * reset MIPI display
 */
void mipi_display_reset(void)
{
#ifdef BOARD_EVB
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT, 0x1b0b0);
    gpio_set_direction(GPIO_PORT5, 0, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT5, 0, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT5, 0, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif

#ifdef BOARD_SABRE_AI
/*binded with the board reset button*/
#endif

#ifdef BOARD_SMART_DEVICE
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0, 0x1b0b0);
    gpio_set_direction(GPIO_PORT6, 11, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 11, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT6, 11, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif
}

void mipi_clock_set(void)
{
    BW_CCM_ANALOG_PFD_480_PFD1_FRAC(0x10);
}

void mipi_csi2_clock_set(void)
{
    //set VIDPLL(PLL5) to 596MHz 
    HW_CCM_ANALOG_PLL_VIDEO_WR(BF_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(0) |
                               BF_CCM_ANALOG_PLL_VIDEO_HALF_LF(1) |
                               BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(1) |
                               BF_CCM_ANALOG_PLL_VIDEO_ENABLE(1));
    HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(0x00000000);
    HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(0x00000001);
    while (!HW_CCM_ANALOG_PLL_VIDEO.B.LOCK) ;   //waiting for PLL lock
    BF_CLR(CCM_ANALOG_PLL_VIDEO, BYPASS);

    //select CSI0_MCLK osc_clk 24MHz, CKO1 output drives cko2 clock 
    HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK_WR(BV_FLD(IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK, MUX_MODE, ALT3));
    HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK_WR(BV_FLD(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, DSE, 40OHM) |
                                          BV_FLD(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, SPEED, 100MHZ) |
                                          BV_FLD(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, PKE, ENABLED) |
                                          BV_FLD(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, PUE, PULL) |
                                          BV_FLD(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, PUS,
                                                 100KOHM_PU) |
                                          BV_FLD(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, HYS, ENABLED));
    HW_CCM_CCOSR_WR(
                    BF_CCM_CCOSR_CLKO1_SEL(0) |
                    BF_CCM_CCOSR_CLKO1_DIV(0) |
                    BF_CCM_CCOSR_CLKO1_EN(1) |
                    BF_CCM_CCOSR_CLKO1_CLKO2_SEL(1) | // select cko2 for cko1 output
                    BF_CCM_CCOSR_CLKO2_SEL(0xe) |    // osc_clk
                    BF_CCM_CCOSR_CLKO2_DIV(0) |  // div 1
                    BF_CCM_CCOSR_CLKO2_EN(1));
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
