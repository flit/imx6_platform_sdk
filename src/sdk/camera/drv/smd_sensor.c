/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file smd_sensor.c
 * @brief common functions for sensor on smd.
 * @ingroup diag_camera
 */

#include "camera_def.h"

static int32_t sensor_write_reg(uint32_t dev_addr, uint16_t reg_addr, uint16_t * pval,
                                uint16_t is_16bits);
static int32_t sensor_read_reg(uint32_t dev_addr, uint16_t reg_addr, uint16_t * pval,
                               uint16_t is_16bits);

/*!
 * reset camera sensor through GPIO on SMD board 
 *
 */
void sensor_reset(void)
{
    int32_t reset_occupy = 1000, reset_delay = 1000;

    sensor_standby(0);

#if defined(MX6DQ_SMART_DEVICE) || defined(MX6SDL_SMART_DEVICE)
    /* MX6DQ/SDL_SMART_DEVICE: camera reset through GPIO1_17 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1, 0x5);
    reg32setbit(GPIO1_BASE_ADDR + 0x0004, 17);  //set GPIO1_17 as output
    reg32clrbit(GPIO1_BASE_ADDR, 17);
    hal_delay_us(reset_occupy);
    reg32setbit(GPIO1_BASE_ADDR, 17);
    hal_delay_us(reset_delay);
#else
    /* MX53_SMD camera reset through GPIO6_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B, 0x1);
    reg32setbit(GPIO6_BASE_ADDR + 0x0004, 9);
    reg32clrbit(GPIO6_BASE_ADDR, 9);
    hal_delay_us(reset_occupy);
    reg32setbit(GPIO6_BASE_ADDR, 9);
    hal_delay_us(reset_delay);
#endif
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

#if defined(MX6DQ_SMART_DEVICE) || defined(MX6SDL_SMART_DEVICE)
    /* MX6DQ/SDL_SMART_DEVICE: setting to gpio1_16, power down high active */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT0, 0x5);
    reg32setbit(GPIO1_BASE_ADDR + 0x0004, 16);  //set GPIO1_16 as output
    if (enable)
        reg32setbit(GPIO1_BASE_ADDR, 16);
    else
        reg32clrbit(GPIO1_BASE_ADDR, 16);
#else
    /* MX53_SMD: setting to gpio6_10, power down high active */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, 0x1);
    reg32setbit(GPIO6_BASE_ADDR + 0x0004, 10);
    if (enable)
        reg32setbit(GPIO6_BASE_ADDR, 10);
    else
        reg32clrbit(GPIO6_BASE_ADDR, 10);
#endif

    return ret;
}

/*!
 * set camera sensor clock to 24MHz. 
 *
 */
void sensor_clock_setting(void)
{
    int32_t clock_delay = 1000;

#if defined(MX6DQ_SMART_DEVICE) || defined(MX6SDL_SMART_DEVICE)
    /*config gpio_0 to be clko */
    writel(0x0, IOMUXC_SW_MUX_CTL_PAD_GPIO_0);
    /*MX6DQ/SDL_SMART_DEVICE: config clko */
    writel(0x00031, IOMUXC_SW_PAD_CTL_PAD_GPIO_0);  // Set GPIO0
    /*select osc_clk 24MHz, CKO1 output drives cko2 clock */
    writel(0x10e0180, CCM_BASE_ADDR + 0x60);
#else
    unsigned int32_t value = 0;

    /*config gpio_0 to be clko */
    writel(0x0, IOMUXC_SW_MUX_CTL_PAD_GPIO_0);
    /*MX53_SMD: config clko select ahb_clk / 5 */
    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_GPIO_0);
    value = readl(CCM_BASE_ADDR + 0x60) & (~0xFF);

    /*ahb_clk divided by 8 to provide mclk */
    writel(value | 0xCB, CCM_BASE_ADDR + 0x60);
#endif

    hal_delay_us(clock_delay);
}

/*!
 * configure camera sensor according to sensor profile 
 * @param	sensor: sensor profile information
 *
 */
int32_t sensor_config(t_camera_profile * sensor)
{
    int32_t ret = 0;

    csi_port0_iomux_config();   //config csi port
    ret = sensor_init(sensor);

    return ret;
}

/*!
 * search which camera sensor is pluged in 
 *
 * @return sensor profile for the camera pluged in
 *
 */
t_camera_profile *search_sensor(void)
{
    int32_t i, j;
    uint16_t read_value, error;
    t_camera_profile *sensor_on;

    for (i = 0; i < SENSOR_NUM; i++) {
        error = 0;
        sensor_on = &camera_profiles[i];
#ifdef MX53_SMD
        camera_power_on(sensor_on->avdd_mv, sensor_on->dovdd_mv, sensor_on->dvdd_mv);
#else
        camera_power_on();
#endif
        sensor_reset();
        sensor_clock_setting();
        sensor_i2c_init(I2C1_BASE_ADDR, 170000);

        for (j = 0; j < sensor_on->sensor_detection_size; ++j) {
            t_reg_param *setting = &sensor_on->sensor_detection[j];
            sensor_read_reg(sensor_on->i2c_dev_addr, setting->addr, &read_value,
                            setting->is_16bits);
            if (setting->delay_ms != 0)
                hal_delay_us(setting->delay_ms * 1000);
            if (read_value != setting->value) {
                error = 1;
                break;
            }
        }
        if (error == 0) {
            printf("Sensor %s detected.\n", sensor_on->sensor_name);
            break;
        }
    }

    if (i == SENSOR_NUM) {
        printf("No valid sensor can be found.\n");
        return NULL;
    }

    return sensor_on;
}

/*!
 * initialize camera sensor 
 * @param	sensor: sensor profile information
 *
 */
int32_t sensor_init(t_camera_profile * sensor)
{
    int32_t i;
    uint16_t read_value;

    sensor_i2c_init(I2C1_BASE_ADDR, 170000);
    t_camera_mode *preview_mode = &sensor->modes[sensor->mode_id];

    for (i = 0; i < preview_mode->size; ++i) {
        t_reg_param *setting = &preview_mode->setting[i];
        sensor_write_reg(sensor->i2c_dev_addr, setting->addr, &setting->value, setting->is_16bits);
        if (setting->delay_ms != 0)
            hal_delay_us(setting->delay_ms);

        if (setting->verify) {
            sensor_read_reg(sensor->i2c_dev_addr, setting->addr, &read_value, setting->is_16bits);
            if (read_value != setting->value) {
                printf("reg[0x%x]=0x%x, but expected=0x%x\n", setting->addr, read_value,
                       setting->value);
            } else {
                //printf ("I2C RIGHT: [reg 0x%x], real = 0x%x, expected = 0x%x\n", regAddr, tmpVal, regVal);
            }
        }
    }

    return 0;
}

/*!
 * configure camera sensor to af trigger mode 
 * @param	sensor: sensor profile information
 *
 */
int32_t sensor_af_trigger(t_camera_profile * sensor)
{
    int32_t ret = 0, i;
    t_reg_param *setting;

    sensor_i2c_init(I2C1_BASE_ADDR, 170000);

    for (i = 0; i < sensor->af_trigger_size; ++i) {
        setting = &sensor->af_trigger[i];
        sensor_write_reg(sensor->i2c_dev_addr, setting->addr, &setting->value, setting->is_16bits);
        if (setting->delay_ms != 0)
            hal_delay_us(setting->delay_ms * 1000);
    }

    return ret;
}

int32_t sensor_autofocus_init(t_camera_profile * sensor)
{
    int32_t ret = 0, i;
    uint16_t read_value;

    if (sensor->auto_focus_enable) {
        printf("Download auto-focus firmware......\n");

        sensor_i2c_init(I2C1_BASE_ADDR, 170000);

        for (i = 0; i < sensor->af_firmware_size; ++i) {
            t_reg_param *setting = &sensor->af_firmware[i];
            sensor_write_reg(sensor->i2c_dev_addr, setting->addr, &setting->value,
                             setting->is_16bits);
            if (setting->delay_ms != 0)
                hal_delay_us(setting->delay_ms * 1000);

            if (setting->verify) {
                sensor_read_reg(sensor->i2c_dev_addr, setting->addr, &read_value,
                                setting->is_16bits);
                if (read_value != setting->value) {
                    printf("reg[0x%x]=0x%x, but expected=0x%x\n", setting->addr, read_value,
                           setting->value);
                } else {
                    //printf ("I2C RIGHT: [reg 0x%x], real = 0x%x, expected = 0x%x\n", regAddr, tmpVal, regVal);
                }
            }
        }
        printf("Auto-focus ready\n");
    }

    return ret;
}

/*!
 * initialize the i2c module for camera sensor -- mainly enable the i2c clock, module itself and the i2c clock prescaler.
 *
 * @param   base        base address of i2c module (also assigned for i2cx_clk)
 * @param   baud        the desired data rate in bps
 *
 * @return  0 if successful; non-zero otherwise
 */
int32_t sensor_i2c_init(uint32_t base, uint32_t baud)
{
    int32_t ret = 0;
    int32_t i2c_delay = 500;

    ret = i2c_init(base, baud);
    if (ret != 0) {
        printf("I2C1 initialization failed!\n");
        return ret;
    }
    hal_delay_us(i2c_delay);

    return ret;
}

static int32_t sensor_write_reg(uint32_t dev_addr, uint16_t reg_addr, uint16_t * pval,
                                uint16_t is_16bits)
{
    int32_t ret = 0;
    struct imx_i2c_request rq;

    reg_addr = ((reg_addr & 0x00FF) << 8) | ((reg_addr & 0xFF00) >> 8); //swap MSB and LSB
    rq.ctl_addr = I2C1_BASE_ADDR;
    rq.dev_addr = dev_addr >> 1;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 2;

    if (is_16bits == 0) {
        uint8_t value = *pval;
        rq.buffer_sz = 1;
        rq.buffer = &value;
        ret = i2c_xfer(&rq, I2C_WRITE);
    } else {
        uint8_t value[2];
        value[0] = ((*pval) & 0xFF00) >> 8;
        value[1] = (*pval) & 0x00FF;
        rq.buffer_sz = 2;
        rq.buffer = value;
        ret = i2c_xfer(&rq, I2C_WRITE);
    }

    return ret;
}

static int32_t sensor_read_reg(uint32_t dev_addr, uint16_t reg_addr, uint16_t * pval,
                               uint16_t is_16bits)
{
    int32_t ret = 0;
    struct imx_i2c_request rq;

    reg_addr = ((reg_addr & 0x00FF) << 8) | ((reg_addr & 0xFF00) >> 8); //swap MSB and LSB
    rq.ctl_addr = I2C1_BASE_ADDR;
    rq.dev_addr = dev_addr >> 1;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 2;

    if (is_16bits == 0) {
        uint8_t value = *pval;
        rq.buffer_sz = 1;
        rq.buffer = &value;
        ret = i2c_xfer(&rq, I2C_READ);
        *pval = value;
    } else {
        uint8_t value[2];
        rq.buffer_sz = 2;
        rq.buffer = value;
        ret = i2c_xfer(&rq, I2C_READ);
        *pval = (value[0] << 8) | (value[1]);
    }

    return ret;
}
