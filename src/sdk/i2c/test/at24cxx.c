/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file at24cxx.c
 * @brief Driver foe the I2C EEPROM Atmel AT24Cxx.
 *
 * @ingroup diag_i2c
 */

#include "hardware.h"

static struct imx_i2c_request at24cxx_i2c_req;

static int32_t at24cx_read(uint32_t addr, uint8_t *buf)
{
    at24cxx_i2c_req.buffer = buf;
    at24cxx_i2c_req.reg_addr = addr;    
    return i2c_read(&at24cxx_i2c_req);
}

static int32_t at24cx_write(uint32_t addr, uint8_t *buf)
{
    int32_t ret;

    at24cxx_i2c_req.buffer = buf;
    at24cxx_i2c_req.reg_addr = addr;
    ret = i2c_write(&at24cxx_i2c_req);

    /* the write cycle time of that EEPROM is max 5ms,
     * so wait for the write to complete.
     */
    hal_delay_us(5000);

    return ret;
}

static uint8_t test_buffer[] = {'F', 'R', 'E', 'E', 'S', 'C', 'A', 'L', 'E', 'I', '2', 'C', 'T', 'E', 'S', 'T'};

int32_t i2c_eeprom_at24cxx_test(void)
{
    uint8_t data_buffer[sizeof(test_buffer)];
    uint8_t i, buffer_size = sizeof(test_buffer);
    int32_t ret = 0;

    printf("  Starting EEPROM test...\n");

    // Initialize the request
    at24cxx_i2c_req.ctl_addr = AT24Cx_I2C_BASE; // the I2C controller base address
    at24cxx_i2c_req.dev_addr = AT24Cx_I2C_ID;   // the I2C DEVICE address
    at24cxx_i2c_req.reg_addr_sz = 2;
    at24cxx_i2c_req.buffer_sz = buffer_size;

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

    /* write known data to the EEPROM */
    ret = at24cx_write(0, test_buffer);
    if(ret != 0)
        printf("A problem occured during the EEPROM programming !\n");

    /* set the buffer of read data at a known state */
    for(i=0;i<buffer_size;i++)
        data_buffer[i] = 0;
    /* read the data from the EEPROM */
    ret = at24cx_read(0, data_buffer);
    if(ret != 0)
        printf("A problem occured during the EEPROM reading !\n");

#ifdef MX61_EVB
    /*Restore iomux and daisy chain setting */
    i2c_init(AT24Cx_I2C_BASE, 170000);
#endif

    for(i=0;i<buffer_size;i++) {
        if (data_buffer[i] != test_buffer[i]) {
            printf("I2C EEPROM test fail.\n");
            printf("Read 0x%01X instead of 0x%01X at address 0x%01X.\n",
                            data_buffer[i], test_buffer[i], i);
            printf("Please make sure EEPROM is mounted on board.\n");
            return TEST_FAILED;
        }
    }

    printf("I2C EEPROM test pass.\n");
    return TEST_PASSED;
 }
