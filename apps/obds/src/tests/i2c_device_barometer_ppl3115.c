/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

#define PPL3115_I2C_ID			0x60
#define PPL3115_REG_DEVICE_ID_OFF	0x0C

static unsigned char ppl3115_reg_read(unsigned int i2c_base_addr, unsigned char reg_addr)
{
    struct imx_i2c_request rq;
    unsigned char buf[1];
    unsigned char reg_data = 0;

    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = PPL3115_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;

    i2c_xfer(&rq, I2C_READ);
//    i2c_xfer(i2c_base_addr, &rq, I2C_READ);
    reg_data = buf[0];
    return reg_data;
}

static int ppl3115_reg_write(unsigned int i2c_base_addr, unsigned char reg_addr,
                             unsigned char reg_val)
{
    struct imx_i2c_request rq;
    unsigned char buf[1];
//    unsigned char reg_data = 0;
    buf[0] = reg_val;
    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = PPL3115_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;

    return i2c_xfer(&rq, I2C_WRITE);
//    return i2c_xfer(i2c_base_addr, &rq, I2C_WRITE);
}

int i2c_device_id_check_ppl3115(unsigned int i2c_base_addr)
{
    unsigned int reg_data = 0;
    printf("\tTest PPL3115 Device ID ");
    i2c_init(i2c_base_addr, 170000);
    reg_data = ppl3115_reg_read(i2c_base_addr, PPL3115_REG_DEVICE_ID_OFF);  //read  WHO_AM_I reg

    if (0xC4 == reg_data) {
       printf("passed 0x%02X\n", reg_data);
        return 0;
    } else {
        printf("failed, 0xC4 vs 0x%02X\n", reg_data);
        return 1;
    }
}
