/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "obds.h"
#include "hardware.h"

#define REG_COMMAND_1 	0x00
#define REG_COMMAND_2	0x01
#define REG_DATA_LSB	0x02
#define REG_DATA_MSB	0x03

static unsigned char isl29023_reg_read(unsigned int i2c_base_addr, unsigned char reg_addr)
{
    struct imx_i2c_request rq;
    unsigned char buf[1];
    unsigned char reg_data = 0;

    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = ISL29023_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;
    i2c_xfer(&rq, I2C_READ);
//    i2c_xfer(i2c_base_addr, &rq, I2C_READ);
    reg_data = buf[0];
    return reg_data;
}

static int isl29023_reg_write(unsigned int i2c_base_addr, unsigned char reg_addr,
                              unsigned char reg_val)
{
    struct imx_i2c_request rq;
    unsigned char buf[1];
    buf[0] = reg_val;

    rq.ctl_addr = i2c_base_addr; 
    rq.dev_addr = ISL29023_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;
    return i2c_xfer(&rq, I2C_WRITE);
//    return i2c_xfer(i2c_base_addr, &rq, I2C_WRITE);
}

static int isl29023_set_config(unsigned int i2c_base_addr)
{
    /*put the device into power-down mode */
    isl29023_reg_write(i2c_base_addr, REG_COMMAND_1, 0x00);
    /*16bit ADC,Range1(0011 Lux) */
    isl29023_reg_write(i2c_base_addr, REG_COMMAND_2, 0x03);

    return 0;
}

static unsigned int isl29023_get_lux(unsigned int i2c_base_addr)
{
    unsigned char val1 = 0, val2 = 0;
    unsigned int iVal = 0, lux = 0;
    /*ALS once */
    isl29023_reg_write(i2c_base_addr, REG_COMMAND_1, 0x01 << 5);
    /*T_int is about 1ms with Rext = 100K */
    hal_delay_us(1000 * 10);

    val1 = isl29023_reg_read(i2c_base_addr, REG_DATA_LSB);
    val2 = isl29023_reg_read(i2c_base_addr, REG_DATA_MSB);
    iVal = (val2 << 8) | val1;
    lux = iVal * 64000 >> 16;

    return lux;
}

static int isl29023_show_lux(unsigned int i2c_base_addr)
{
    unsigned char uc = 0;
    unsigned int lux = 0;

    printf("    Do you want to check the light sensor?(y/n)\n\n");

    do {
        uc = getchar();
//        uc = receive_char();
    } while (uc == NONE_CHAR);

    if (uc == 'y' || uc == 'Y') {
        isl29023_set_config(i2c_base_addr);

        printf("    Start show luminance. Type 'x' to exit.\n\n");
        while (1) {
            lux = isl29023_get_lux(i2c_base_addr);
            printf("\r    The luminance is: %8d lux\t\t   ", lux);
            uc = getchar();
//            uc = receive_char();
            if (uc == 'x' || uc == 'X') {
                printf("\n\n");
                break;
            }
        }
    } else {
        return 1;
    }
    return 0;
}

int i2c_device_id_check_isl29023(unsigned int i2c_base_addr)
{
    unsigned int data_saved = 0, data_reg = 0;
    printf("Test ISL29023 Device ID - ");
    i2c_init(i2c_base_addr, 170000);
    data_saved = isl29023_reg_read(i2c_base_addr, 0x04);    //read  INT_LT_LSB

    isl29023_reg_write(i2c_base_addr, 0x04, 0xA5);

    data_reg = isl29023_reg_read(i2c_base_addr, 0x04);
    if (0xA5 == data_reg) {
        printf("passed 0x%02X\n\n", data_reg);
        isl29023_reg_write(i2c_base_addr, 0x04, data_saved);
        isl29023_show_lux(i2c_base_addr);
        return 0;
    } else {
        printf("failed, 0xA5 vs 0x%02X\n\n", data_reg);
        return 1;
    }
}
