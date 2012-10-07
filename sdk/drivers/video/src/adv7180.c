/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file camera_def.h
 * @brief common macro and data structre defination of camera.
 * @ingroup diag_camera
 */

#include "video/adv7180_def.h"
#include "sdk_types.h"
#include "timer/timer.h"
#include "iomux_config.h"
#include "iomux_register.h"
#include "soc_memory_map.h"
#include "hardware.h"

/*! Description of video formats supported.
 *
 *  PAL: raw=720x625, active=720x576.
 *  NTSC: raw=720x525, active=720x480.
 */
video_fmt_t video_fmts[] = {
	{			/*! NTSC */
	 .fmt_id = ADV7180_NTSC,
	 .name = "NTSC",
	 .raw_width = 720,	/* SENS_FRM_WIDTH */
	 .raw_height = 525,	/* SENS_FRM_HEIGHT */
	 .active_width = 720,	/* ACT_FRM_WIDTH plus 1 */
	 .active_height = 480,	/* ACT_FRM_WIDTH plus 1 */
	 },
	{			/*! (B, G, H, I, N) PAL */
	 .fmt_id = ADV7180_PAL,
	 .name = "PAL",
	 .raw_width = 720,
	 .raw_height = 625,
	 .active_width = 720,
	 .active_height = 576,
	 },
	{			/*! Unlocked standard */
	 .fmt_id = ADV7180_NOT_LOCKED,
	 .name = "Autodetect",
	 .raw_width = 720,
	 .raw_height = 625,
	 .active_width = 720,
	 .active_height = 576,
	 },
};

static void adv7180_hard_reset(uint8_t cvbs);

int32_t adv7180_i2c_init(uint32_t base, uint32_t baud)
{
    int32_t ret = 0;
    int32_t i2c_delay = 500 * 1000;

    ret = i2c_init(base, baud);
    if (ret != 0) {
        printf("I2C initialization failed!\n");
        return ret;
    }
    hal_delay_us(i2c_delay);

    return ret;
}

static int32_t adv7180_write_reg(uint8_t reg, uint8_t pval)
{
    int ret = 0;
    struct imx_i2c_request rq = {0};

    rq.ctl_addr = g_adv7180_i2c_device.port;
    rq.dev_addr = g_adv7180_i2c_device.address;
    rq.reg_addr = reg;
    rq.reg_addr_sz = 1;

    rq.buffer_sz = 1;
    rq.buffer = &pval;
    ret = i2c_xfer(&rq, I2C_WRITE);

    return ret;
}

static int32_t adv7180_read_reg(uint8_t reg)
{
    int ret = 0;
    struct imx_i2c_request rq = {0};
	uint8_t pval = 0;

    rq.ctl_addr = g_adv7180_i2c_device.port;
    rq.dev_addr = g_adv7180_i2c_device.address;
    rq.reg_addr = reg;
    rq.reg_addr_sz = 1;

    rq.buffer_sz = 1;
    rq.buffer = &pval;
    ret = i2c_xfer(&rq, I2C_READ);

	if (ret == 0)
    	return (int32_t) pval;
	else 
		return -1;
}

static void adv7180_pwdn(int32_t pwdn)
{
	uint32_t gpio_base = 0, gpio_num;

	/*Tvin reset: PORT2_P97 */
    writel(0x5, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT5);
	gpio_base = GPIO5_BASE_ADDR;
	gpio_num = 23;

    reg32setbit(gpio_base + 0x0004, gpio_num);  //set GPIO1_17 as output

	if (pwdn == 1)
    	reg32setbit(gpio_base, gpio_num);
	else
    	reg32clrbit(gpio_base, gpio_num);

}

static void adv7180_reset(void)
{
	uint32_t gpio_base = 0, gpio_num;
	int32_t reset_delay = 100000;

	/*Tvin reset: PORT2_P95 */
    writel(0x5, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT7);
	gpio_base = GPIO5_BASE_ADDR;
	gpio_num = 25;

    reg32setbit(gpio_base + 0x0004, gpio_num);  //set GPIO1_17 as output
//    reg32clrbit(gpio_base, gpio_num);

//	hal_delay_us(reset_delay);
    reg32setbit(gpio_base, gpio_num);

	/*Tvin power down: PORT2_P97 */
	adv7180_pwdn(0);

	hal_delay_us(reset_delay);
	adv7180_pwdn(1);
}

/*!
 * Sets the camera power.
 *
 * on if 1, power is to be turned on.  0 means power is to be turned off
 */
static int32_t adv7180_power_on(int32_t on)
{
	if (on) { /*turn on */
		if (adv7180_write_reg(ADV7180_PWR_MNG, 0) != 0)
			return TEST_FAILED;
	} else { /*turn off*/
		if (adv7180_write_reg(ADV7180_PWR_MNG, 0x24) != 0)
			return TEST_FAILED;
	}

	return TEST_PASSED;
}

static void csi0_tvin_io_init(void)
{
	/* iomux setting for csi0 */
	csi_port0_iomux_config();

	/* Tvin reset */
	adv7180_reset();

	hal_delay_us(20000);
}

int32_t adv7180_init(void)
{
	int8_t rev_id = 0;
	int8_t cvbs = 0; // YPrPb input false on arm2 board

	csi0_tvin_io_init();

	adv7180_i2c_init(g_adv7180_i2c_device.port, 50000);
	/* read the revision ID of the tvin chip */
	rev_id = adv7180_read_reg(ADV7180_IDENT);
	if (!((rev_id == 0x1B) || (rev_id == 0x1C) || (rev_id == 0x1E))) {
		printf("ADV7180 is expected! Wrong Version %02X\n", rev_id);
		return TEST_FAILED;
	}

	/* ADV7180 initialization. */
	adv7180_hard_reset(cvbs);

	hal_delay_us(500000);

	return TEST_PASSED;
}

int32_t adv7180_get_std(void)
{
	uint32_t reg_val;
	int32_t idx;

	adv7180_i2c_init(g_adv7180_i2c_device.port, 50000);

	/* Read the AD_RESULT to get the output video standard */
	reg_val = adv7180_read_reg(ADV7180_STATUS_1) & 0x70;

	if (reg_val == 0x40) {
		/* PAL */
		idx = ADV7180_PAL;
	} else if (reg_val == 0) {
		/*NTSC*/
		idx = ADV7180_NTSC;
	} else {
		idx = ADV7180_NOT_LOCKED;
		printf("Got invalid video standard!\n");
	}

	return idx;
}

/*
 * return 1 if the video is in interlaced mode 
 * 0 for progressive mode */
int32_t adv7180_is_interlaced_mode(void)
{
	uint32_t reg_val;

	adv7180_i2c_init(g_adv7180_i2c_device.port, 50000);
	/* Read the AD_RESULT to get the output video if interlaced or progressive */
	reg_val = adv7180_read_reg(ADV7180_STATUS_3) & 0x40;

	if (reg_val)
		return 1;
	else 
		return 0;
}

static void adv7180_hard_reset(uint8_t cvbs)
{
	adv7180_i2c_init(g_adv7180_i2c_device.port, 50000);

	if (cvbs) {
		/* Set CVBS input on AIN1 */
		adv7180_write_reg(ADV7180_INPUT_CTL, 0x00);
		/* luma timing: [1:0]0x00 No delay
		 * chrome: [5:3] 0x03 No delay
		 * */
		adv7180_write_reg(0x27, 0x58); 
	} else {
		/*
		 * Set YPbPr input on AIN1,4,5 and normal
		 * operations(autodection of all stds).
		 */
		adv7180_write_reg(ADV7180_INPUT_CTL, 0x09);
		/* luma timing: [1:0]0x01 37ns
		 * chrome timeing: [5:3] 0x6 three pixels (late)
		 * */
		adv7180_write_reg(0x27, 0x71);
	}

	/* Datasheet recommends */
	adv7180_write_reg(0x01, 0xc8);
	adv7180_write_reg(0x02, 0x04);
	adv7180_write_reg(0x03, 0x00);
	adv7180_write_reg(0x04, 0xC4); /* 16 ~ 235*/
	adv7180_write_reg(0x05, 0x00);
	adv7180_write_reg(0x06, 0x02);
	adv7180_write_reg(0x07, 0x7F);
	adv7180_write_reg(0x08, 0x80);
	adv7180_write_reg(0x0A, 0x00);
	adv7180_write_reg(0x0B, 0x00);
	adv7180_write_reg(0x0C, 0x36);
	adv7180_write_reg(0x0D, 0x7C);
	adv7180_write_reg(0x0E, 0x00);
	adv7180_write_reg(0x0F, 0x00);
	adv7180_write_reg(0x13, 0x00);
	adv7180_write_reg(0x14, 0x12);
	adv7180_write_reg(0x15, 0x00);
	adv7180_write_reg(0x16, 0x00);
	adv7180_write_reg(0x17, 0x01);
	adv7180_write_reg(0x18, 0x93);
	adv7180_write_reg(0xF1, 0x19);
	adv7180_write_reg(0x1A, 0x00);
	adv7180_write_reg(0x1B, 0x00);
	adv7180_write_reg(0x1C, 0x00);
	adv7180_write_reg(0x1D, 0x40);
	adv7180_write_reg(0x1E, 0x00);
	adv7180_write_reg(0x1F, 0x00);
	adv7180_write_reg(0x20, 0x00);
	adv7180_write_reg(0x21, 0x00);
	adv7180_write_reg(0x22, 0x00);
	adv7180_write_reg(0x23, 0xC0);
	adv7180_write_reg(0x24, 0x00);
	adv7180_write_reg(0x25, 0x00);
	adv7180_write_reg(0x26, 0x00);
	adv7180_write_reg(0x28, 0x00);
	adv7180_write_reg(0x29, 0x00);
	adv7180_write_reg(0x2A, 0x00);
	adv7180_write_reg(0x2B, 0xE1);
	adv7180_write_reg(0x2C, 0xAE);
	adv7180_write_reg(0x2D, 0xF4);
	adv7180_write_reg(0x2E, 0x00);
	adv7180_write_reg(0x2F, 0xF0);
	adv7180_write_reg(0x30, 0x00);
	adv7180_write_reg(0x31, 0x12);
	adv7180_write_reg(0x32, 0x41);
	adv7180_write_reg(0x33, 0x84);
	adv7180_write_reg(0x34, 0x00);
	adv7180_write_reg(0x35, 0x00);
	adv7180_write_reg(0x36, 0x00);
	adv7180_write_reg(0x37, 0x01);
	adv7180_write_reg(0x38, 0x80);
	adv7180_write_reg(0x39, 0xC0);
	adv7180_write_reg(0x3A, 0x10);
	adv7180_write_reg(0x3B, 0x05);
	adv7180_write_reg(0x3C, 0x58);
	adv7180_write_reg(0x3D, 0xB2);
	adv7180_write_reg(0x3E, 0x64);
	adv7180_write_reg(0x3F, 0xE4);
	adv7180_write_reg(0x40, 0x90);
	adv7180_write_reg(0x41, 0x01);
	adv7180_write_reg(0x42, 0x7E);
	adv7180_write_reg(0x43, 0xA4);
	adv7180_write_reg(0x44, 0xFF);
	adv7180_write_reg(0x45, 0xB6);
	adv7180_write_reg(0x46, 0x12);
	adv7180_write_reg(0x48, 0x00);
	adv7180_write_reg(0x49, 0x00);
	adv7180_write_reg(0x4A, 0x00);
	adv7180_write_reg(0x4B, 0x00);
	adv7180_write_reg(0x4C, 0x00);
	adv7180_write_reg(0x4D, 0xEF);
	adv7180_write_reg(0x4E, 0x08);
	adv7180_write_reg(0x4F, 0x08);
	adv7180_write_reg(0x50, 0x08);
	adv7180_write_reg(0x51, 0x24);
	adv7180_write_reg(0x52, 0x0B);
	adv7180_write_reg(0x53, 0x4E);
	adv7180_write_reg(0x54, 0x80);
	adv7180_write_reg(0x55, 0x00);
	adv7180_write_reg(0x56, 0x10);
	adv7180_write_reg(0x57, 0x00);
	adv7180_write_reg(0x58, 0x00);
	adv7180_write_reg(0x59, 0x00);
	adv7180_write_reg(0x5A, 0x00);
	adv7180_write_reg(0x5B, 0x00);
	adv7180_write_reg(0x5C, 0x00);
	adv7180_write_reg(0x5D, 0x00);
	adv7180_write_reg(0x5E, 0x00);
	adv7180_write_reg(0x5F, 0x00);
	adv7180_write_reg(0x60, 0x00);
	adv7180_write_reg(0x61, 0x00);
	adv7180_write_reg(0x62, 0x20);
	adv7180_write_reg(0x63, 0x00);
	adv7180_write_reg(0x64, 0x00);
	adv7180_write_reg(0x65, 0x00);
	adv7180_write_reg(0x66, 0x00);
	adv7180_write_reg(0x67, 0x03);
	adv7180_write_reg(0x68, 0x01);
	adv7180_write_reg(0x69, 0x00);
	adv7180_write_reg(0x6A, 0x00);
	adv7180_write_reg(0x6B, 0xC0);
	adv7180_write_reg(0x6C, 0x00);
	adv7180_write_reg(0x6D, 0x00);
	adv7180_write_reg(0x6E, 0x00);
	adv7180_write_reg(0x6F, 0x00);
	adv7180_write_reg(0x70, 0x00);
	adv7180_write_reg(0x71, 0x00);
	adv7180_write_reg(0x72, 0x00);
	adv7180_write_reg(0x73, 0x10);
	adv7180_write_reg(0x74, 0x04);
	adv7180_write_reg(0x75, 0x01);
	adv7180_write_reg(0x76, 0x00);
	adv7180_write_reg(0x77, 0x3F);
	adv7180_write_reg(0x78, 0xFF);
	adv7180_write_reg(0x79, 0xFF);
	adv7180_write_reg(0x7A, 0xFF);
	adv7180_write_reg(0x7B, 0x1E);
	adv7180_write_reg(0x7C, 0xC0);
	adv7180_write_reg(0x7D, 0x00);
	adv7180_write_reg(0x7E, 0x00);
	adv7180_write_reg(0x7F, 0x00);
	adv7180_write_reg(0x80, 0x00);
	adv7180_write_reg(0x81, 0xC0);
	adv7180_write_reg(0x82, 0x04);
	adv7180_write_reg(0x83, 0x00);
	adv7180_write_reg(0x84, 0x0C);
	adv7180_write_reg(0x85, 0x02);
	adv7180_write_reg(0x86, 0x03);
	adv7180_write_reg(0x87, 0x63);
	adv7180_write_reg(0x88, 0x5A);
	adv7180_write_reg(0x89, 0x08);
	adv7180_write_reg(0x8A, 0x10);
	adv7180_write_reg(0x8B, 0x00);
	adv7180_write_reg(0x8C, 0x40);
	adv7180_write_reg(0x8D, 0x00);
	adv7180_write_reg(0x8E, 0x40);
	adv7180_write_reg(0x8F, 0x00);
	adv7180_write_reg(0x90, 0x00);
	adv7180_write_reg(0x91, 0x50);
	adv7180_write_reg(0x92, 0x00);
	adv7180_write_reg(0x93, 0x00);
	adv7180_write_reg(0x94, 0x00);
	adv7180_write_reg(0x95, 0x00);
	adv7180_write_reg(0x96, 0x00);
	adv7180_write_reg(0x97, 0xF0);
	adv7180_write_reg(0x98, 0x00);
	adv7180_write_reg(0x99, 0x00);
	adv7180_write_reg(0x9A, 0x00);
	adv7180_write_reg(0x9B, 0x00);
	adv7180_write_reg(0x9C, 0x00);
	adv7180_write_reg(0x9D, 0x00);
	adv7180_write_reg(0x9E, 0x00);
	adv7180_write_reg(0x9F, 0x00);
	adv7180_write_reg(0xA0, 0x00);
	adv7180_write_reg(0xA1, 0x00);
	adv7180_write_reg(0xA2, 0x00);
	adv7180_write_reg(0xA3, 0x00);
	adv7180_write_reg(0xA4, 0x00);
	adv7180_write_reg(0xA5, 0x00);
	adv7180_write_reg(0xA6, 0x00);
	adv7180_write_reg(0xA7, 0x00);
	adv7180_write_reg(0xA8, 0x00);
	adv7180_write_reg(0xA9, 0x00);
	adv7180_write_reg(0xAA, 0x00);
	adv7180_write_reg(0xAB, 0x00);
	adv7180_write_reg(0xAC, 0x00);
	adv7180_write_reg(0xAD, 0x00);
	adv7180_write_reg(0xAE, 0x60);
	adv7180_write_reg(0xAF, 0x00);
	adv7180_write_reg(0xB0, 0x00);
	adv7180_write_reg(0xB1, 0x60);
	adv7180_write_reg(0xB2, 0x1C);
	adv7180_write_reg(0xB3, 0x54);
	adv7180_write_reg(0xB4, 0x00);
	adv7180_write_reg(0xB5, 0x00);
	adv7180_write_reg(0xB6, 0x00);
	adv7180_write_reg(0xB7, 0x13);
	adv7180_write_reg(0xB8, 0x03);
	adv7180_write_reg(0xB9, 0x33);
	adv7180_write_reg(0xBF, 0x02);
	adv7180_write_reg(0xC0, 0x00);
	adv7180_write_reg(0xC1, 0x00);
	adv7180_write_reg(0xC2, 0x00);
	adv7180_write_reg(0xC3, 0x00);
	adv7180_write_reg(0xC4, 0x00);
	adv7180_write_reg(0xC5, 0x81);
	adv7180_write_reg(0xC6, 0x00);
	adv7180_write_reg(0xC7, 0x00);
	adv7180_write_reg(0xC8, 0x00);
	adv7180_write_reg(0xC9, 0x04);
	adv7180_write_reg(0xCC, 0x69);
	adv7180_write_reg(0xCD, 0x00);
	adv7180_write_reg(0xCE, 0x01);
	adv7180_write_reg(0xCF, 0xB4);
	adv7180_write_reg(0xD0, 0x00);
	adv7180_write_reg(0xD1, 0x10);
	adv7180_write_reg(0xD2, 0xFF);
	adv7180_write_reg(0xD3, 0xFF);
	adv7180_write_reg(0xD4, 0x7F);
	adv7180_write_reg(0xD5, 0x7F);
	adv7180_write_reg(0xD6, 0x3E);
	adv7180_write_reg(0xD7, 0x08);
	adv7180_write_reg(0xD8, 0x3C);
	adv7180_write_reg(0xD9, 0x08);
	adv7180_write_reg(0xDA, 0x3C);
	adv7180_write_reg(0xDB, 0x9B);
	adv7180_write_reg(0xDC, 0xAC);
	adv7180_write_reg(0xDD, 0x4C);
	adv7180_write_reg(0xDE, 0x00);
	adv7180_write_reg(0xDF, 0x00);
	adv7180_write_reg(0xE0, 0x14);
	adv7180_write_reg(0xE1, 0x80);
	adv7180_write_reg(0xE2, 0x80);
	adv7180_write_reg(0xE3, 0x80);
	adv7180_write_reg(0xE4, 0x80);
	adv7180_write_reg(0xE5, 0x25);
	adv7180_write_reg(0xE6, 0x44);
	adv7180_write_reg(0xE7, 0x63);
	adv7180_write_reg(0xE8, 0x65);
	adv7180_write_reg(0xE9, 0x14);
	adv7180_write_reg(0xEA, 0x63);
	adv7180_write_reg(0xEB, 0x55);
	adv7180_write_reg(0xEC, 0x55);
	adv7180_write_reg(0xEE, 0x00);
	adv7180_write_reg(0xEF, 0x4A);
	adv7180_write_reg(0xF0, 0x44);
	adv7180_write_reg(0xF1, 0x0C);
	adv7180_write_reg(0xF2, 0x32);
	adv7180_write_reg(0xF3, 0x00);
	adv7180_write_reg(0xF4, 0x3F);
	adv7180_write_reg(0xF5, 0xE0);
	adv7180_write_reg(0xF6, 0x69);
	adv7180_write_reg(0xF7, 0x10);
	adv7180_write_reg(0xF8, 0x00);
	adv7180_write_reg(0xF9, 0x03);
	adv7180_write_reg(0xFA, 0xFA);
	adv7180_write_reg(0xFB, 0x40);
}
