/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

#define PMIC_MAX17135_I2C_ADDR        (0x90 >> 1)   // PMIC I2C Slave address
#define PMIC_MAX17135_I2C_REG_BYTE    0x1   // Number of Bytes to transfer the PMIC reg number
#define PMIC_MAX17135_I2C_DATA_BYTE   0x1   // Number of Bytes to transfer the PMIC reg data

unsigned char max17135_reg_read(unsigned char reg)
{
    struct imx_i2c_request rq;
    unsigned char buf = 0;

    /* Initialize some of the I2C imx_i2c_request structure, these parameters shouldn't need to be changed */
    rq.ctl_addr = PMIC_MAX17135_I2C_BASE;
    rq.dev_addr = PMIC_MAX17135_I2C_ADDR;
    rq.reg_addr_sz = PMIC_MAX17135_I2C_REG_BYTE;
    rq.buffer_sz = PMIC_MAX17135_I2C_DATA_BYTE;
    rq.reg_addr = reg;
    rq.buffer = &buf;

    i2c_xfer(&rq, I2C_READ);

    return buf;
}

void max17135_reg_write(unsigned char reg, unsigned char reg_data)
{
    struct imx_i2c_request rq;

    rq.ctl_addr = PMIC_MAX17135_I2C_BASE;
    rq.dev_addr = PMIC_MAX17135_I2C_ADDR;
    rq.reg_addr_sz = PMIC_MAX17135_I2C_REG_BYTE;
    rq.buffer_sz = PMIC_MAX17135_I2C_DATA_BYTE;
    rq.reg_addr = reg;
    rq.buffer = &reg_data;

    i2c_xfer(&rq, I2C_READ);
}

static void max17135_output_seq_set(void)
{
    /*power up sequence */
    max17135_reg_write(0x10, 0x0A); //delay 10ms
    max17135_reg_write(0x12, 0x14);
    max17135_reg_write(0x11, 0x1E);
    max17135_reg_write(0x13, 0x28);

    /*power down sequence */
    max17135_reg_write(0x14, 0x0A);
    max17135_reg_write(0x16, 0x14);
    max17135_reg_write(0x15, 0x1E);
    max17135_reg_write(0x17, 0x28);

}

int i2c_device_id_check_MAX17135(void)
{
    unsigned char reg_data = 0;

    printf("Test MAX17135 Device ID - ");

    i2c_init(PMIC_MAX17135_I2C_BASE, 170000);

    reg_data = max17135_reg_read(0x07);
    if (0x4D == reg_data) {
        printf("passed 0x%02X\n\n", reg_data);
//      max17135_output_seq_set();
        return TEST_PASSED;
    } else {
        printf("failed, 0x4D vs 0x%02X\n\n", reg_data);
        return TEST_FAILED;
    }
}
