/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "board_i2c.h"
#include "registers/regsi2c.h"

////////////////////////////////////////////////////////////////////////////////
// Globals
////////////////////////////////////////////////////////////////////////////////

const i2c_device_info_t g_wm8958_i2c_device = { HW_I2C2, (0x34 >> 1), 100000 };

const i2c_device_info_t g_wm8962_i2c_device = { HW_I2C1, (0x34 >> 1), 48000 };

const i2c_device_info_t g_sgtl5000_i2c_device = { HW_I2C2, 0x0a, 100000 };

const i2c_device_info_t g_cs42888_i2c_device = { HW_I2C1, (0x90 >> 1), 100000 };


const i2c_device_info_t g_pmic_ltc3589_i2c_device = { HW_I2C2, (0x68 >> 1), 170000 };

const i2c_device_info_t g_pmic_da9053_i2c_device = { HW_I2C1, (0x90 >> 1), 170000 };

const i2c_device_info_t g_pmic_max17135_i2c_device = { HW_I2C1, (0x90 >> 1), 170000 };

const i2c_device_info_t g_pmic_pf0100_i2c_device = { HW_I2C2, (0x10 >> 1), 170000 };


#if defined(BOARD_EVB)
const i2c_device_info_t g_adv7180_i2c_device = { HW_I2C1, (0x42 >> 1), 50000 };
#else
const i2c_device_info_t g_adv7180_i2c_device = { HW_I2C3, (0x42 >> 1), 50000 };
#endif


const i2c_device_info_t g_os81050_i2c_device = { HW_I2C3, (0x40 >> 1), 50000 };


#if defined(BOARD_SABRE_LITE)
const i2c_device_info_t g_p1003_tsc_i2c_device = { HW_I2C3, 4 };
#else
const i2c_device_info_t g_p1003_tsc_i2c_device = { HW_I2C2, 4 };
#endif


const i2c_device_info_t g_at24cx_i2c_device = { HW_I2C3, (0xa0 >> 1), 170000 };


const i2c_device_info_t g_si476x_i2c_device = { HW_I2C2, (0xC6 >> 1), 50000 };

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
