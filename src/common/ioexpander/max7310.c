/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file max7310.c
 * @brief Driver and test for the I/O expander MAX7310 controlled through I2C.
 *
 * @ingroup diag_ioexpander
 */

#include "hardware.h"

/*! 
 * @note In hardware.h an array of I2C requests is created as multiple I/O expanders
 *       could be used on a board.
 *       Thanks to board_init() in hardware.c, the requests are populated with addresses.
 *       The local I2C request used in this driver should point to the request of the
 *       IO expander that needs to be accessed.
 *       e.g.     max7310_i2c_req = &max7310_i2c_req_array[slave_id];
 */
static struct imx_i2c_request *max7310_i2c_req;

#define input_port_reg  0x00
#define output_port_reg 0x01
#define polarity_reg    0x02
#define config_reg      0x03
#define timeout_reg     0x04

/*!
 * Function to read a register of the MAX7310.
 *
 * @param reg_addr   register address
 *
 * @return the value of the read register
 */
uint8_t max7310_reg_read(uint8_t reg_addr)
{
    uint8_t buf;

    max7310_i2c_req->reg_addr = reg_addr;
    max7310_i2c_req->buffer = &buf;
    i2c_xfer(max7310_i2c_req, I2C_READ);

    return buf;
}

/*!
 * Function to read a register of the video A/D converter ADV7180.
 *
 * @param reg_addr   register address
 * @param data       written data
 *
 * @return 0 on success; non-zero otherwise
 */
int32_t max7310_reg_write(uint8_t reg_addr, uint8_t data)
{
    max7310_i2c_req->reg_addr = reg_addr;
    max7310_i2c_req->buffer = &data;

    return i2c_xfer(max7310_i2c_req, I2C_WRITE);
}

/*!
 * Initialize the MAX7310 with a default I/O direction and output value.
 * That IC has no ID register, so one of the register is also initialized
 * with a known value here. This will be used by the read ID test.
 *
 * @param slave_id         I/O expander instance number
 * @param io_default_dir   default I/O direction
 * @param out_default_val  default output value
 * 
 * @return 0 on success; non-zero otherwise
 */
int32_t max7310_init(uint32_t slave_id, uint32_t io_default_dir, uint32_t out_default_val)
{
    max7310_i2c_req = &max7310_i2c_req_array[slave_id];

    /* I2C controller init */
    i2c_init(max7310_i2c_req->ctl_addr, 170000);
    /* initialize I2C request fixed elements */
    max7310_i2c_req->reg_addr_sz = 1;
    max7310_i2c_req->buffer_sz = 1;
    /* initialize I/O to output with all outputs at 0 */
    max7310_reg_write(polarity_reg, 0x00);  // non-inverted polarity
    max7310_reg_write(output_port_reg, out_default_val);
    max7310_reg_write(config_reg, io_default_dir);
    /* Disable timeout function that reset I2C bus in case of error
       and store a known value for ID test => which should obviously pass */
    max7310_reg_write(timeout_reg, 0xAC);

    return 0;
}

/*!
 * Function to control the MAX7310 output state.
 *
 * @param slave_id   I/O expander instance number (0=instance 0,...)
 * @param io_x       I/O number (0=IO_0, 1=IO_1, ...)
 * @param level      I/O state (0=low, 1=high)
 * 
 * @return 0 on success; non-zero otherwise
 */
void max7310_set_gpio_output(uint32_t slave_id, uint32_t io_x, uint32_t level)
{
    uint8_t data;

    max7310_i2c_req = &max7310_i2c_req_array[slave_id];
    /* read output state first through the input register */
    data = max7310_reg_read(input_port_reg);
    /* process it */
    data &= ~(1 << io_x);
    data |= (level << io_x);
    /* write result in output register */
    max7310_reg_write(output_port_reg, data);
}

/*!
 * The test tries to read the created device ID for all MAX7310 used on board.
 * That IC has no ID register, so one of the register is initialized with
 * a known value during init. That test should actually always pass.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
static int32_t max7310_i2c_device_id_check(void)
{
    uint32_t i, data;
    int32_t ret = -1, ret_all = 0;

    for (i = 0; i < MAX7310_NBR; i++) {
        max7310_i2c_req = &max7310_i2c_req_array[i];
        data = max7310_reg_read(timeout_reg);
        printf("data read back is 0x%x\n", data);

        if (data == 0xAC)
            ret = 0;
        else
            ret_all = -1;

        printf("I2C IO expander number %d test %s\n", i, (ret == 0) ? "passed" : "failed");
    }

    if (ret_all == 0) {
        return TEST_PASSED;
    } else {
        return TEST_FAILED;
    }
}
