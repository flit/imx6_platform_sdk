/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"
#include "board_io_expanders.h"
#include "registers/regsi2c.h"
#include "registers/regsiomuxc.h"

////////////////////////////////////////////////////////////////////////////////
// Globals
////////////////////////////////////////////////////////////////////////////////

imx_i2c_request_t max7310_i2c_req_array[MAX7310_NBR];

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void board_ioexpander_init(void)
{
#if defined(BOARD_SABRE_AI)
    // Bring max7310 out of reset
    // (this iomux setting should be done in gpio_iomux_config())
    HW_IOMUXC_SW_MUX_CTL_PAD_SD2_DAT0_WR(BF_IOMUXC_SW_MUX_CTL_PAD_SD2_DAT0_MUX_MODE_V(ALT5));
    gpio_set_direction(GPIO_PORT1, 15, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 15, GPIO_HIGH_LEVEL);
 
    // for I2C3 steering
    // Select ALT5 mode of EIM_A24 for GPIO5_4 - EIMD18_I2C3_STEER(EIM_A24)
    // high output to select I2C3 option
    // (this iomux setting should be done in gpio_iomux_config())
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_A24_WR(BF_IOMUXC_SW_MUX_CTL_PAD_EIM_A24_MUX_MODE_V(ALT5));
    gpio_set_direction(GPIO_PORT5, 4, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT5, 4, GPIO_HIGH_LEVEL);
#endif

    // Build array of I2C request structures.
#if defined(BOARD_EVB) || defined(BOARD_SABRE_AI)
    // Configure some board signals through I/O expanders
    max7310_i2c_req_array[0].ctl_addr = HW_I2C3; // the I2C controller base address
    max7310_i2c_req_array[0].dev_addr = MAX7310_I2C_ID0;    // the I2C DEVICE address
    max7310_init(0, MAX7310_ID0_DEF_DIR, MAX7310_ID0_DEF_VAL);
    
    max7310_i2c_req_array[1].ctl_addr = HW_I2C3; // the I2C controller base address
    max7310_i2c_req_array[1].dev_addr = MAX7310_I2C_ID1;    // the I2C DEVICE address
    max7310_init(1, MAX7310_ID1_DEF_DIR, MAX7310_ID1_DEF_VAL);
#endif
#if defined(BOARD_SABRE_AI)
    max7310_i2c_req_array[2].ctl_addr = HW_I2C3; // the I2C controller base address
    max7310_i2c_req_array[2].dev_addr = MAX7310_I2C_ID2;    // the I2C DEVICE address
    max7310_init(2, MAX7310_ID2_DEF_DIR, MAX7310_ID2_DEF_VAL);
#endif
}


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
