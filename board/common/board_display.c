/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "registers/regsccmanalog.h"
#include "registers/regsccm.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * Provide the LVDS power through GPIO pins
 */
void lvds_power_on(void)
{
#if defined(BOARD_EVB)
    /*3.3V power supply through the load switch FDC6331L */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_9, ALT5);
    gpio_set_direction(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef BOARD_SMART_DEVICE
    // 3v3 on by default
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
    // PMIC_5V LVDS1 power on by default
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_set_direction(GPIO_PORT1, 21, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 21, GPIO_HIGH_LEVEL);
#endif

#ifdef BOARD_SABRE_AI
    /*3.3V power supply through IOexpander */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_set_direction(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 9, GPIO_HIGH_LEVEL);

#endif
}

/*! From obds
 * Disable the display panel
 */
void disable_para_panel(void)
{
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
    gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
}

/*! Copy from OBDS
 * Provide the power for TFT LCD backlight
 */
void tftlcd_backlight_en(char *panel_name)
{
    if (!strcmp(panel_name, "CLAA 070VC01")) {
        /*GPIO to provide backlight */
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT4, 20, GPIO_HIGH_LEVEL);
    } else if (!strcmp(panel_name, "BoundaryDev WVGA")) {
#if defined (BOARD_REV_A)
        /*lvds/parallel display backlight enable, GPIO2_0 */
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
        gpio_set_direction(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT2, 9, GPIO_HIGH_LEVEL);

        // lcd_contrast conflict with actual BoundaryDev display so seeting to input
        // since TSC not used on SABRE AI
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_INPUT);
#elif defined (BOARD_REV_B)
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT4, 20, GPIO_HIGH_LEVEL);
#endif
    } else {
        printf("Unsupported panel!\n");
    }
#if 0
#ifdef BOARD_SABRE_AI
    /*lvds/parallel display backlight enable, GPIO2_0 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_set_direction(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 9, GPIO_LOW_LEVEL);

    // lcd_contrast conflict with actual BoundaryDev display so seeting to input
    // since TSC not used on SABRE AI
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
    gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_INPUT);
#endif
#ifdef BOARD_SMART_DEVICE
    /* AUX_3V15 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B, 0x1B0B0);
    gpio_set_direction(GPIO_PORT6, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 9, GPIO_HIGH_LEVEL);
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_set_direction(GPIO_PORT1, 21, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 21, GPIO_HIGH_LEVEL);
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
#endif
#endif

}

/*! Copy from OBDS
 * Reset the TFT LCD
 */
void tftlcd_reset(char *panel_name)
{
    if (!strcmp(panel_name, "CLAA 070VC01")) {
#ifdef BOARD_EVB
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
        gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_set_level(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
#ifdef BOARD_SMART_DEVICE
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_DA8, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_DA8, 0x1B0B0);
        gpio_set_direction(GPIO_PORT3, 8, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT3, 8, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_set_level(GPIO_PORT3, 8, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
    }
}

/*!
 * @brief Configure ldb clock as per the display resolution.
 *
 * ldb clock is derived from PLL5, ldb on ipu1
 */
void ldb_clock_config(int freq, int ipu_index)
{
    if (freq == 65000000)       //for XGA resolution
    {
        //config pll3 PFD1 to 455M. pll3 is 480M 
        BW_CCM_ANALOG_PFD_480_PFD1_FRAC(19);

        // set ldb_di0_clk_sel to PLL3 PFD1
        HW_CCM_CS2CDR.B.LDB_DI0_CLK_SEL = 3;
        HW_CCM_CS2CDR.B.LDB_DI1_CLK_SEL = 3;

        // set clk_div to 7
        HW_CCM_CSCMR2.B.LDB_DI0_IPU_DIV = 1;
        HW_CCM_CSCMR2.B.LDB_DI1_IPU_DIV = 1;

        if (ipu_index == 1) {
            //set ipu1_di0_clk_sel from ldb_di0_clk 
            HW_CCM_CHSCCDR.B.IPU1_DI0_CLK_SEL = 3;  // ldb_di0_clk
            HW_CCM_CHSCCDR.B.IPU1_DI1_CLK_SEL = 3;  // ldb_di0_clk
        }
#if CHIP_MX6DQ
        else {
            //set ipu2_di0_clk_sel from ldb_di0_clk 
            HW_CCM_CSCDR2.B.IPU2_DI0_CLK_SEL = 3;
            HW_CCM_CSCDR2.B.IPU2_DI1_CLK_SEL = 3;
        }
#endif // CHIP_MX6DQ
    } else {
        printf("The frequency %d for LDB is not supported yet.", freq);
    }
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
