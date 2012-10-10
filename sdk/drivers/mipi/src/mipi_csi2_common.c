/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  mipi_csi2_common.c
 * @brief common functions for mipi csi.
 *
 * @ingroup diag_mipi
 */

#include <stdio.h>
#include "mipi/mipi_common.h"
#include "ipu/ipu_common.h"
#include "registers/regsmipicsi.h"

#define PREVIEW 1
#define MIPI_SENSOR_ADDR 0x3C

extern void mipi_cam_power_on(void);
extern void mipi_ipu_csi_config(void);
extern void mipi_sensor_config(unsigned int i2c_base);
extern char receive_char(void);
extern void mipi_csi2_clock_set(void);

static void mipi_sensor_i2c_init(unsigned int base, unsigned int baud)
{
    int ret = 0;
    int i2c_delay = 500 * 100;

    ret = i2c_init(base, baud);
    if (ret != 0) {
        printf("Sensor I2C initialization failed!\n");
        return;
    }
    hal_delay_us(i2c_delay);

}

static int32_t mipi_sensor_write_reg(uint32_t i2c_base, uint16_t reg, uint8_t pval)
{
    int ret = 0;
    struct imx_i2c_request rq = {0};
//  printf("reg 0x%04x : 0x%02x\n", reg, pval);

    reg = ((reg & 0x00FF) << 8) | ((reg & 0xFF00) >> 8);    //swap MSB and LSB
    rq.ctl_addr = i2c_base;
    rq.dev_addr = MIPI_SENSOR_ADDR;
    rq.reg_addr = reg;
    rq.reg_addr_sz = 2;

    rq.buffer_sz = 1;
    rq.buffer = &pval;
    ret = i2c_xfer(&rq, I2C_WRITE);

    return ret;
}

static int32_t mipi_sensor_read_reg(uint32_t i2c_base, uint16_t reg, uint8_t * pval)
{
    int ret = 0;
    struct imx_i2c_request rq = {0};

    reg = ((reg & 0x00FF) << 8) | ((reg & 0xFF00) >> 8);    //swap MSB and LSB
    rq.ctl_addr = i2c_base;
    rq.dev_addr = MIPI_SENSOR_ADDR;
    rq.reg_addr = reg;
    rq.reg_addr_sz = 2;

    rq.buffer_sz = 1;
    rq.buffer = pval;
    ret = i2c_xfer(&rq, I2C_READ);

    return ret;
}

/*for debug purpose*/
static int dev_check_reg(unsigned int i2c_base, unsigned int slave_addr, unsigned char reg,
                         unsigned char *pval)
{
    int ret = 0;
    struct imx_i2c_request rq = {0};

    rq.ctl_addr = i2c_base;
    rq.dev_addr = slave_addr >> 1;
    rq.reg_addr = reg;
    rq.reg_addr_sz = 1;

    rq.buffer_sz = 1;
    rq.buffer = pval;
    *pval = 0xAB;
    i2c_xfer(&rq, I2C_WRITE);
    *pval = 0;
    printf("baddr %x, id %x\n", reg, *pval);
    ret = i2c_xfer(&rq, I2C_READ);
    printf("aaddr %x, id %x\n", reg, *pval);

    return ret;
}

void mipi_sensor_id_check(unsigned int i2c_base)
{
    unsigned char data_high, data_low;
    char revchar;
    do {
        mipi_sensor_read_reg(i2c_base, 0x300b, &data_low);
        mipi_sensor_read_reg(i2c_base, 0x300a, &data_high);
        printf("The sensor chip id is 0x%04x\n", (data_high << 8) | data_low);
        if (((data_high << 8) | data_low) == 0x5640)
            break;
        printf("please re-connect the camera, now re-check? y for yes, n for no\n");

        do {
            revchar = getchar();
        } while (revchar == (uint8_t) 0xFF);

        if (revchar == 'n') {
            break;
        }
    } while (1);
}

void mipi_sensor_load_firmware(unsigned int i2c_base, mipi_cam_mode_t * mipi_cam_fm)
{
    int i = 0;
    unsigned char val = 0;

    while (i < mipi_cam_fm->size) {
        mipi_sensor_write_reg(i2c_base,
                              (mipi_cam_fm->setting + i)->addr, (mipi_cam_fm->setting + i)->value);
        if ((mipi_cam_fm->setting + i)->delay_us)
            hal_delay_us((mipi_cam_fm->setting + i)->delay_us * 1000);
        if ((mipi_cam_fm->setting + i)->verify) {
            mipi_sensor_read_reg(i2c_base, (mipi_cam_fm->setting + i)->addr, &val);
            if ((mipi_cam_fm->setting + i)->value != val) {
                printf("Sensor configuation failed! expected 0x%x, actual 0x%x",
                       (mipi_cam_fm->setting + i)->value, val);
            }
        }

        i++;
    }
}

void mipi_sensor_regs_dump(unsigned int i2c_base, unsigned short start, unsigned short end)
{
    unsigned char data;
    unsigned short i = start;
    while (i <= end) {
        mipi_sensor_read_reg(i2c_base, i, &data);
        printf("reg@0x%04x:  0x%02x\n", i, data);
        i++;
    }
}

void mipi_sensor_config(unsigned int i2c_base)
{
    mipi_cam_mode_t *mipi_cam_fm = NULL;

    mipi_sensor_i2c_init(i2c_base, 170000);
    mipi_sensor_id_check(i2c_base);

    /*init mipi camera */
    mipi_cam_fm = &mipi_cam_modes[OV5640_MODE_VGA_640X480_30FPS_YUV422];
    mipi_sensor_load_firmware(i2c_base, mipi_cam_fm);

    printf("Download mipi sensor firmware done!\n");
}

void i2c2_sensor_off(unsigned int i2c_base)
{
    mipi_sensor_write_reg(i2c_base, 0x3008, 0x42);  //sleep;   
    mipi_sensor_write_reg(i2c_base, 0x3503, 0x7);
    mipi_sensor_write_reg(i2c_base, 0x483b, 0xff);  //sleep;
    mipi_sensor_write_reg(i2c_base, 0x3007, 0xf7);  //sleep;   

}

void i2c2_sensor_on(unsigned int i2c_base)
{
    mipi_sensor_write_reg(i2c_base, 0x3008, 0x42);  //sleep;   
    mipi_sensor_write_reg(i2c_base, 0x3503, 0x7);
    mipi_sensor_write_reg(i2c_base, 0x483b, 0xff);  //sleep;
    mipi_sensor_write_reg(i2c_base, 0x3007, 0xf7);  //sleep;   
    mipi_sensor_write_reg(i2c_base, 0x3008, 0x02);
    mipi_sensor_write_reg(i2c_base, 0x3503, 0x0);
    mipi_sensor_write_reg(i2c_base, 0x483b, 0x33);  //mipi  reset;
    mipi_sensor_write_reg(i2c_base, 0x3007, 0xff);  //sleep;

}

int32_t mipi_csi2_set_lanes(uint32_t lanes)
{
    if (lanes > 4 || lanes < 1)
        return FALSE;
	BW_MIPI_CSI_N_LANES_N_LANES(lanes - 1);
    return TRUE;
}

void mipi_csi2_controller_program(void)
{
    //ov5640 support 2 lanes. (using lane 0 and lane 1)
    mipi_csi2_set_lanes(2);

    /*PHY loopback test */
	//{phy_testclk,phy_testclr} = {0,1}
	BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK(0);
	BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR(1);

	//{phy_testen,phy_testdout,phy_testdin}
	HW_MIPI_CSI_PHY_TST_CTRL1_CLR(
			BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN |
			BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDOUT |
			BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN);

	//{phy_testclk,phy_testclr} = {0,1} --> {0,0}
	BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR(0);
	//{phy_testclk,phy_testclr} = {0,0} --> {1,0}
	BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK(1);

	//{phy_testen,phy_testdout,phy_testdin}
	BW_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN(0x44);
	BW_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN(1);

	//{phy_testclk,phy_testclr} = {1,0} --> {0,0}
	BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK(0);

	//{phy_testen,phy_testdout,phy_testdin}
	BW_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN(0);
	BW_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN(0x14);

	//{phy_testclk,phy_testclr} = {0,0} --> {1,0}
	BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK(1);

	//{phy_testclk,phy_testclr} = {1,0} --> {0,0}
	BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK(0);

    // raise phy shutdown
	BW_MIPI_CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ(1);

    //raise phy reset
	BW_MIPI_CSI_DPHY_RSTZ_DPHY_RSTZ(1);

    //raise csi2 reset
	BW_MIPI_CSI_CSI2_RESETN_CSI2_RESETN(1);
}

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

void mipi_csi2_config(void)
{
    int32_t timeout = 0x100000;

    /*D-PHY initialize */
    mipi_csi2_clock_set();
    mipi_cam_power_on();

    /*CSI2 controller program */
    mipi_csi2_controller_program();

    /*check if D-PHY is ready to receive: clock lane and data lane in stop state */
    timeout = 0x100000;
	while(HW_MIPI_CSI_PHY_STATE.B.PHY_RXULPSCLKNOT &&
		  HW_MIPI_CSI_PHY_STATE.B.PHY_STOPSTATEDATA_1 &&
		  HW_MIPI_CSI_PHY_STATE.B.PHY_STOPSTATEDATA_0) {
        if (timeout-- < 0) {
            printf("Waiting for PHY ready timeout!!\n");
            return;
        }
    }

    /*config mipi camera sensor */
    mipi_sensor_config(I2C2_BASE_ADDR);

    /*check if ddr clock is received */
    timeout = 0x100000;
	while(!HW_MIPI_CSI_PHY_STATE.B.PHY_RXCLKACTIVEHS) {
		if (timeout-- < 0) {
			printf("Waiting for DDR clock ready timeout!!\n");
			return;
		}
	}
}
