/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file max7310_test.c
 * @brief Test for the I/O expander MAX7310 controlled through I2C.
 */

#include "ioexpander/max7310.h"

/*! 
 * @note In hardware.h an array of I2C requests is created as multiple I/O expanders
 *       could be used on a board.
 *       Thanks to board_init() in hardware.c, the requests are populated with addresses.
 *       The local I2C request used in this driver should point to the request of the
 *       IO expander that needs to be accessed.
 *       e.g.     max7310_i2c_req = &max7310_i2c_req_array[slave_id];
 */
extern struct imx_i2c_request *max7310_i2c_req;

extern uint8_t max7310_reg_read(uint8_t reg_addr);


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
