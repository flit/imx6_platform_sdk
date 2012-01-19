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
#include "mipi_common.h"
#include "../../ipu/inc/ipu_common.h"

#define PREVIEW 1
#define MIPI_SENSOR_ADDR 0x3C

extern void mipi_cam_power_on(void);
extern void mipi_ipu_csi_config(void);
extern void mipi_sensor_config(unsigned int i2c_base);
extern char receive_char(void);

static void mipi_sensor_i2c_init(unsigned int base, unsigned int baud)
{
    int ret = 0;
    int i2c_delay = 500;

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
    struct imx_i2c_request rq;
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
    struct imx_i2c_request rq;

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
    struct imx_i2c_request rq;

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
//          dev_check_reg(i2c_base, 0x90, 0x01<<1, &data_low);
        mipi_sensor_read_reg(i2c_base, 0x300a, &data_high);
        mipi_sensor_read_reg(i2c_base, 0x300b, &data_low);
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
            hal_delay_us((mipi_cam_fm->setting + i)->delay_us);
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
void mipi_csi2_clock_set(void)
{
    /*set VIDPLL(PLL5) to 596MHz */
    reg32_write(ANATOP_BASE_ADDR + 0xA0, 0x00002018);   // interger  = 24
    reg32_write(ANATOP_BASE_ADDR + 0xB0, 0x00000000);   // num = 0
    reg32_write(ANATOP_BASE_ADDR + 0xC0, 0x00000001);   // denom = 1, any value is okay
    while (!(reg32_read(ANATOP_BASE_ADDR + 0xA0) & 0x80000000)) ;   // wait for PLL lock
    reg32_write(ANATOP_BASE_ADDR + 0xA8, 0x00010000);

    /*select osc_clk 24MHz, CKO1 output drives cko2 clock */
    reg32_write(CCM_CHSCCDR, 0x00012150);
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK, ALT3);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, 0x1B0B0);
    reg32_write(CCM_CCOSR, 0x10e0180);
}

void mipi_csi2_reset(void)
{
    /*PHY loopback test */
    reg32_write(CSI2_PHY_TST_CTRL0, 0x00000001);    //{phy_testclk,phy_testclr} = {0,1}
    reg32_write(CSI2_PHY_TST_CTRL1, 0x00000000);    //{phy_testen,phy_testdout,phy_testdin}
    reg32_write(CSI2_PHY_TST_CTRL0, 0x00000000);    //{phy_testclk,phy_testclr} = {0,1}
    reg32_write(CSI2_PHY_TST_CTRL0, 0x00000002);    //{phy_testclk,phy_testclr} = {0,1}
    reg32_write(CSI2_PHY_TST_CTRL1, 0x00010044);    //{phy_testen,phy_testdout,phy_testdin}
    reg32_write(CSI2_PHY_TST_CTRL0, 0x00000000);    //{phy_testclk,phy_testclr} = {0,1}
    reg32_write(CSI2_PHY_TST_CTRL1, 0x00000014);    //{phy_testen,phy_testdout,phy_testdin}
    reg32_write(CSI2_PHY_TST_CTRL0, 0x00000002);    //{phy_testclk,phy_testclr} = {0,1}
    reg32_write(CSI2_PHY_TST_CTRL0, 0x00000000);    //{phy_testclk,phy_testclr} = {0,1}

    // raise phy shutdown
    reg32_write(CSI2_PHY_SHUTDOWNZ, 1);

    //raise phy reset
    reg32_write(CSI2_DPHY_RSTZ, 1);

    //raise csi2 reset
    reg32_write(CSI2_RESETN, 1);
}

/*!
 * Provide the mipi camera power and reset
 */
void mipi_cam_power_on(void)
{
#ifdef MX61_EVB
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

#ifdef MX61_ARD
    /*power supply through pin25 of connector, direct connected to P3V3_DELAY,
       controlled by CPU_PER_RST_B */
    /*reset of camera sensor, together with the reset button */
    max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);

#endif

#ifdef MX61_SABRE_TABLET
    /*power supply through pin25 of connector, for cam_pdown */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B, 0x1B0B0);
    gpio_dir_config(GPIO_PORT6, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT6, 9, GPIO_HIGH_LEVEL);

    /*reset of camera sensor, pin 27 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0, 0x1B0B0);
    gpio_dir_config(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT6, 10, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_write_data(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
#endif
}

int32_t mipi_csi2_set_lanes(uint32_t lanes)
{
    if (lanes > 4 || lanes < 1)
        return FALSE;
    reg32_write(CSI2_N_LANES, 0x1);
    return TRUE;
}

void mipi_csi2_config(void)
{
    uint32_t timeout = 0x100000;

    ipu_mipi_csi2_setup(1, 640, 480, 1024, 768, PARTIAL_INTERLEAVED_YUV420);

    mipi_csi2_clock_set();

    mipi_cam_power_on();

    //ov5640 support 2 lanes. (using lane 0 and lane 1)
    mipi_csi2_set_lanes(2);

    mipi_csi2_reset();

    mipi_sensor_config(I2C2_BASE_ADDR);

    while ((reg32_read(CSI2_PHY_STATE) & 0xffffffff) == 0x00000200) {
        if (timeout-- < 0) {
            printf("Waiting for PHY ready timeout!!\n");
            return;
        }
    }
}
