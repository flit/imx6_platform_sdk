/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

static struct imx_i2c_request at24cxx_i2c_req;

static int32_t at24cx_read(uint32_t addr, uint8_t buf[])
{
    at24cxx_i2c_req.buffer = buf;
    return i2c_xfer(&at24cxx_i2c_req, I2C_READ);
}

static int32_t at24cx_write(uint32_t addr, uint8_t buf[])
{
    at24cxx_i2c_req.buffer = buf;
    return i2c_xfer(&at24cxx_i2c_req, I2C_WRITE);
}

int32_t i2c_eeprom_at24cxx_test(void)
{
    uint8_t buf1[4], buf2[4];

    // Initialize the request
    at24cxx_i2c_req.ctl_addr = AT24Cx_I2C_BASE;     // the I2C controller base address
    at24cxx_i2c_req.dev_addr = AT24Cx_I2C_ID;     // the I2C DEVICE address
    at24cxx_i2c_req.reg_addr_sz = 2;
    at24cxx_i2c_req.buffer_sz = 3;

    i2c_init(AT24Cx_I2C_BASE, 170000);

#ifdef MX61_EVB
    /*Set iomux and daisy chain for eeprom test */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D17, ALT6 | 0x10);
    reg32_write(IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT, 0x00);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D17, 0x1b8b0);

    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D18, ALT6 | 0x10);
    reg32_write(IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT, 0x00);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D18, 0x1b8b0);
#endif

    buf1[0] = 'F';
    buf1[1] = 'S';
    buf1[2] = 'L';

    at24cx_write(0, buf1);

    buf2[0] = 0;
    buf2[1] = 0;
    buf2[2] = 0;
    at24cx_read(0, buf2);

#ifdef MX61_EVB
    /*Restore iomux and daisy chain setting */
    i2c_init(AT24Cx_I2C_BASE, 170000);
#endif

    if ((buf2[0] != buf1[0]) || (buf2[1] != buf1[1]) || (buf2[2] != buf1[2])) {
        printf("I2C EEPROM test fail.\n");
        printf("Please make sure EEPROM is mounted on board\n");
        return TEST_FAILED;
    } else {
        printf("I2C EEPROM test pass.\n");
        return TEST_PASSED;
    }
}
