/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "obds.h"
#include "hardware.h"

#define MC1323_I2C_ID           0x4C
#define MC1323_REG_SDIDH	0x06
#define MC1323_REG_SDIDL	0x07

unsigned char buf[] = { 0, 0, 0, 0 };

static unsigned int mc1323_reg_read(unsigned int i2c_base_addr, unsigned int reg_addr)
{
    struct imx_i2c_request rq;
    unsigned int reg_data;

    reg_data = 0;
    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = MC1323_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;
    if (i2c_xfer(&rq, I2C_READ) != 0) {
//    if (i2c_xfer(i2c_base_addr, &rq, I2C_READ) != 0) {
        printf("Failed to read from i2c\n");
    }
    reg_data = buf[0] | buf[1] << 8 | buf[2] << 16 | buf[3] << 24;

    return reg_data;
}

static int mc1323_reg_write(unsigned int i2c_base_addr, unsigned int reg_addr, unsigned int reg_val)
{
    struct imx_i2c_request rq;

    buf[0] = reg_val;
    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = MC1323_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;
    
    return i2c_xfer(&rq, I2C_WRITE);
//    return i2c_xfer(i2c_base_addr, &rq, I2C_WRITE);
}

int i2c_device_id_check_mc1323(unsigned int i2c_base_addr)
{
    unsigned int sdidh = 0;
    unsigned int sdidl = 0;
    printf("\tTest MC1323 (Zigbee) Device ID ");
    i2c_init(i2c_base_addr, 170000);

    sdidh = mc1323_reg_read(i2c_base_addr, MC1323_REG_SDIDH);   //read  WHO_AM_I reg

    sdidl = mc1323_reg_read(i2c_base_addr, MC1323_REG_SDIDL);   //read  WHO_AM_I reg

    if ((sdidh == 0x20 || sdidh == 0x30) && sdidl == 0x28) {
        printf("passed 0x%02X%02X\n", sdidh, sdidl);
        return 0;
    } else {
        printf("failed, 0x2028 vs 0x%02X%02X\n", sdidh, sdidl);
        return 1;
    }
}
