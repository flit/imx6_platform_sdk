/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file at24cxx.c
 * @brief Driver foe the I2C EEPROM Atmel AT24Cxx.
 *
 * @ingroup diag_i2c
 */

#include "sdk.h"

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
    at24cxx_i2c_req.device = &g_at24cx_i2c_device;
//     at24cxx_i2c_req.ctl_addr = AT24Cx_I2C_BASE; // the I2C controller base address
//     at24cxx_i2c_req.dev_addr = AT24Cx_I2C_ID;   // the I2C DEVICE address
    at24cxx_i2c_req.reg_addr_sz = 2;
    at24cxx_i2c_req.buffer_sz = buffer_size;

    i2c_init(g_at24cx_i2c_device.port, g_at24cx_i2c_device.freq);

#if defined(BOARD_EVB)
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

#if defined(BOARD_EVB)
    /*Restore iomux and daisy chain setting */
    i2c_init(g_at24cx_i2c_device.port, g_at24cx_i2c_device.freq);
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
