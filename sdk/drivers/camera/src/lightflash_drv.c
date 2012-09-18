/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#ifdef CHIP_MX6DQ

//#include "imx_i2c.h"
#include "hardware.h"
//#include "functions.h"

#define ADP1650_I2C_ADDR    0x30

/* Reset ADP 1650
    A low-to-high transition on the EN pin resets all registers to their default values.
    SMART_DEVICE -- EN pin: GPIO3_20
 */
static void ADP1650_reset(void)
{
    int reset_occupy = 1000, reset_delay = 1000;

    /* SMART_DEVICE: set camera LED_FLASH_EN through GPIO3_20 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D20, 0x5);
    reg32setbit(GPIO3_BASE_ADDR + 0x0004, 20);  //set GPIO1_17 as output

    reg32clrbit(GPIO3_BASE_ADDR, 20);
    hal_delay_us(reset_occupy);

    reg32setbit(GPIO3_BASE_ADDR, 20);
    hal_delay_us(reset_delay);
}

static unsigned char ADP1650_reg_read(unsigned int i2c_base_addr, unsigned char reg_addr)
{
    struct imx_i2c_request rq;
    unsigned char buf[1];
    unsigned char reg_data = 0;
    rq.dev_addr = ADP1650_I2C_ADDR;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;
    rq.ctl_addr = i2c_base_addr; 
    i2c_xfer(&rq, I2C_READ);
    reg_data = buf[0];
    return reg_data;
}

static int ADP1650_reg_write(unsigned int i2c_base_addr, unsigned char reg_addr,
                             unsigned char reg_val)
{
    struct imx_i2c_request rq;
    unsigned char buf[1];

    buf[0] = reg_val;
    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = ADP1650_I2C_ADDR;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;
    return i2c_xfer(&rq, I2C_WRITE);
}

/* Test ADP1650 device id
    Design Information Register: 0x00 -- Default 0x22
  */
int i2c_device_id_check_ADP1650(unsigned int i2c_base_addr)
{
    unsigned int data_reg = 0;

    printf("\nTest ADP1650 Device ID: ");

    i2c_init(i2c_base_addr, 170000);

    data_reg = ADP1650_reg_read(i2c_base_addr, 0x00);   //read Design Information

    if (0x22 == data_reg) {
        printf("passed 0x%02X\n", data_reg);
        return 0;
    } else {
        printf("failed, 0x22 vs 0x%02X\n", data_reg);
        return 1;
    }
}

/* Set ADP1650 as Flash Mode
    Flash Duration:  0x02
    Flash Current:   0x03
    Flash Mode:       0x04
  */
void ADP1650_FlashMode_init(void)
{
    ADP1650_reset();

    i2c_init(I2C2_BASE_ADDR, 170000);
    i2c_device_id_check_ADP1650(I2C2_BASE_ADDR);

    /* ADP1650 Setting */
    ADP1650_reg_write(I2C2_BASE_ADDR, 0x02, 0x0F);
    ADP1650_reg_write(I2C2_BASE_ADDR, 0x03, 0x74);
    ADP1650_reg_write(I2C2_BASE_ADDR, 0x04, 0x8F);
}

#endif
