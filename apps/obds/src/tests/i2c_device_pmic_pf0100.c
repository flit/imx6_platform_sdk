/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
//#include "imx_i2c.h"

#define PMIC_PF0100_I2C_NUM        1    // Which I2C used to interface with the PMIC; 0=I2C1, 1=I2C2
#define PMIC_PF0100_I2C_REG_BYTE   0x1  // Number of Bytes to transfer the PMIC reg number
#define PMIC_PF0100_I2C_DATA_BYTE  0x1  // Number of Bytes to transfer the PMIC reg data

#define PMIC_PF0100_I2C_ID         (0x10 >> 1)  //0x08

unsigned char pf0100_reg_read(unsigned char reg_addr)
{
    struct imx_i2c_request rq;
    unsigned char buf;

    rq.ctl_addr = PMIC_PF0100_I2C_BASE;
    rq.dev_addr = PMIC_PF0100_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = &buf;

//    i2c_xfer(PMIC_PF0100_I2C_BASE, &rq, I2C_READ);
    i2c_xfer(&rq, I2C_READ);

    return buf;
}

void pf0100_reg_write(unsigned char reg_addr, unsigned char reg_data)
{
    struct imx_i2c_request rq;

    rq.ctl_addr = PMIC_PF0100_I2C_BASE;
    rq.dev_addr = PMIC_PF0100_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = &reg_data;

//    i2c_xfer(PMIC_PF0100_I2C_BASE, &rq, I2C_WRITE);
    i2c_xfer(&rq, I2C_WRITE);
}

void pf0100_enable_vgen2_1v5(void)
{
    unsigned char data;

    i2c_init(PMIC_PF0100_I2C_BASE, 170000);
    data = pf0100_reg_read(109);
    pf0100_reg_write(109, 0x1E);
}

void pf0100_enable_vgen4_1v8(void)
{
    unsigned char data;

    i2c_init(PMIC_PF0100_I2C_BASE, 170000);
    data = pf0100_reg_read(111);
    pf0100_reg_write(111, 0x10);
}

void pf0100_enable_vgen6_2v8(void)
{
    unsigned char data;

    i2c_init(PMIC_PF0100_I2C_BASE, 170000);
    data = pf0100_reg_read(113);
    pf0100_reg_write(113, 0x1A);
}

int pf0100_i2c_device_id_test_enable;
int pf0100_i2c_device_id_check(void)
{
    unsigned char data;

    if (!pf0100_i2c_device_id_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("PMIC PF0100 ID TEST");

    i2c_init(PMIC_PF0100_I2C_BASE, 170000);

    data = 0x0;
    data = pf0100_reg_read(0x0);    //Device ID
    if (!(data & 0x10)) {       //bit 4 should be set, 0b0001xxxx
        printf("Expected id 0b0001xxxx (PF0100), read 0x%X\n", data);
        return TEST_FAILED;
    }
    printf("PF0100 ID: 0b0001xxxx, read: 0x%X\n", data);
    printf(" PMIC PF0100 ID test passed \n");

    return TEST_PASSED;
}

//RUN_TEST("PMIC PF0100", pf0100_i2c_device_id_check)
