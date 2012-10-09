/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "camera/camera_def.h"
#include "registers/regsiomuxc.h"
#include "registers/regsccm.h"

#if defined (CHIP_MX6SL)
#define CAMERA_I2C_PORT (3)
#else
#define CAMERA_I2C_PORT (1)
#endif

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

uint8_t g_camera_i2c_port = CAMERA_I2C_PORT;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/* dummy empty function for camera_test
 * camera power is always on for MX6DQ SMD board*/
void camera_power_on(void)
{
}

#if !defined(CHIP_MX6SL)
/*IOMUX configuration for CSI port0*/
void csi_port0_iomux_config(void)
{
    uint32_t tmpVal;

    /* config CSI0_PIXCLK pad for ipu instance CSI0_PIXCLK port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_PIXCLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_PIXCLK, 0x130B0);
    /* config CSI0_MCLK pad for ipu instance CSI0_HSYNC port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, 0x130B0);
    /* config CSI0_VSYNC pad for ipu instance CSI0_VSYNC port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_VSYNC, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_VSYNC, 0x130B0);
    /* config CSI0_DAT12 pad for ipu instance CSI0_D[12] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT12, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT12, 0x130B0);
    /* config CSI0_DAT13 pad for ipu instance CSI0_D[13] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT13, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT13, 0x130B0);
    /* config CSI0_DAT14 pad for ipu instance CSI0_D[14] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT14, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT14, 0x130B0);
    /* config CSI0_DAT15 pad for ipu instance CSI0_D[15] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT15, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT15, 0x130B0);
    /* config CSI0_DAT16 pad for ipu instance CSI0_D[16] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT16, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT16, 0x130B0);
    /* config CSI0_DAT17 pad for ipu instance CSI0_D[17] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT17, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT17, 0x130B0);
    /* config CSI0_DAT18 pad for ipu instance CSI0_D[18] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT18, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT18, 0x130B0);
    /* config CSI0_DAT19 pad for ipu instance CSI0_D[19] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT19, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT19, 0x130B0);

    /* set GPR1 to enable parallel interface
     * bit 19: 0 - Enable mipi to IPU1 CSI0, virtual channel is fixed to 0
     *         1 - Enable parallel interface to IPU CSI0
     * bit 20: 0 - Enable mipi to IPU2 CSI1, virtual channel is fixed to 3
     *         1 - Enable parallel interface to IPU2 CSI1
     * IPU1 CSI1 directly connect to mipi CSI2, virtual channel is fixed to 1
     * IPU2 CSI0 directly connect to mipi CSI2, virtual channel is fixed to 2
     */
    tmpVal = reg32_read(IOMUXC_GPR1);
    reg32_write(IOMUXC_GPR1, tmpVal | (0x1 << 19));
}
#endif // !CHIP_MX6SL

//Copied from obds
/* I/O config for the DS90UR124QVS - LVDS camera in */
void deserializer_io_config(void)
{
   // REN and RPWDB controlled by ADV7180 configured in the driver
#if defined (CHIP_MX6SL)
    csi_iomux_config();
#else
    csi_port0_iomux_config();
#endif
}

#if !defined(CHIP_MX6SL)
/*!
 * reset camera sensor through GPIO on SMD board 
 *
 */
void sensor_reset(void)
{
    int32_t reset_occupy = 1000, reset_delay = 1000;

    sensor_standby(0);

    /* MX6DQ/SDL_SMART_DEVICE: camera reset through GPIO1_17 */
	BW_IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1_MUX_MODE(ALT5);
	gpio_set_direction(GPIO_PORT1, 17, GPIO_GDIR_OUTPUT);

	gpio_set_level(GPIO_PORT1, 17, GPIO_LOW_LEVEL);
    hal_delay_us(reset_occupy);

	gpio_set_level(GPIO_PORT1, 17, GPIO_HIGH_LEVEL);
    hal_delay_us(reset_delay);
}

/*!
 * set camera sensor to standby mode.
 *
 * @param	enable: specify whether set camera sensor to standby mode
 * 
 */
int32_t sensor_standby(int32_t enable)
{
    int32_t ret = 0;

    /* MX6DQ/SDL_SMART_DEVICE: setting to gpio1_16, power down high active */
	BW_IOMUXC_SW_MUX_CTL_PAD_SD1_DAT0_MUX_MODE(ALT5);
	gpio_set_direction(GPIO_PORT1, 16, GPIO_GDIR_OUTPUT);
    if (enable)
		gpio_set_level(GPIO_PORT1, 16, GPIO_HIGH_LEVEL);
    else
		gpio_set_level(GPIO_PORT1, 16, GPIO_LOW_LEVEL);

    return ret;
}

/*!
 * set camera sensor clock to 24MHz. 
 *
 */
void sensor_clock_setting(void)
{
    int32_t clock_delay = 1000;

    /*MX6DQ/SDL_SMART_DEVICE: config clko */
    /*config gpio_0 to be clko */
	BW_IOMUXC_SW_MUX_CTL_PAD_GPIO_0_MUX_MODE(ALT0);

	BW_IOMUXC_SW_PAD_CTL_PAD_GPIO_0_SRE(SRE_FAST);
	BW_IOMUXC_SW_PAD_CTL_PAD_GPIO_0_DSE(DSE_80OHM);

    /*select osc_clk 24MHz, CKO1 output drives cko2 clock */
	HW_CCM_CCOSR_WR(
			BF_CCM_CCOSR_CLKO2_EN(1) |
			BF_CCM_CCOSR_CLKO2_DIV(0) | /*div 1*/
			BF_CCM_CCOSR_CLKO2_SEL(0xe) | /*osc_clk*/
			BF_CCM_CCOSR_CLKO1_CLKO2_SEL(1) |
			BF_CCM_CCOSR_CLKO1_EN(1) |
			BF_CCM_CCOSR_CLKO1_DIV(0)); /*div 1*/

    hal_delay_us(clock_delay);
}
#endif // !defined(CHIP_MX6SL)

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
