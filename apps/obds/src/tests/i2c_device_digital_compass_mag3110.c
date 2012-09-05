/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

unsigned char mag3110_reg_read(unsigned int i2c_base_addr, unsigned char reg_addr)
{
    struct imx_i2c_request rq;
    unsigned char buf[1];
    unsigned char reg_data = 0;

    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = MAG3110_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;

    if (i2c_xfer(&rq, I2C_READ) != 0) {
//    if (i2c_xfer(i2c_base_addr, &rq, I2C_READ) != 0) {
        printf("%s() error. return\n", __FUNCTION__);
        return -1;
    }

    reg_data = buf[0];

    return reg_data;
}

int i2c_device_id_check_mag3110(unsigned int i2c_base_addr)
{
    unsigned char ret_data;

    i2c_init(i2c_base_addr, 170000);

    ret_data = mag3110_reg_read(i2c_base_addr, 0x07);

    if (ret_data != 0xC4) {
        printf(" * MAG3110 device ID test failed, read back 0x%x but it should be 0xC4 \n",
               ret_data);
        return TEST_FAILED;
    } else {
        printf(" MAG3110 I2C device check passed, read back 0x%x \n", ret_data);
        return TEST_PASSED;
    }
}
