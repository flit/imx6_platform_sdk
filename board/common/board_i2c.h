/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__BOARD_I2C_H__)
#define __BOARD_I2C_H__

#include "sdk_types.h"
#include "i2c/imx_i2c.h"

////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

//! @name Audio codecs
//@{
extern const i2c_device_info_t g_wm8958_i2c_device;
extern const i2c_device_info_t g_wm8962_i2c_device;
extern const i2c_device_info_t g_sgtl5000_i2c_device;
extern const i2c_device_info_t g_cs42888_i2c_device;
//@}

//! @name PMICs
//@{
extern const i2c_device_info_t g_pmic_ltc3589_i2c_device;
extern const i2c_device_info_t g_pmic_da9053_i2c_device;
extern const i2c_device_info_t g_pmic_pf0100_i2c_device;
extern const i2c_device_info_t g_pmic_max17135_i2c_device;
//@}

//! @brief ADV7180 video decoder
extern const i2c_device_info_t g_adv7180_i2c_device;

//! @brief OS81050 MLB MOST controller
extern const i2c_device_info_t g_os81050_i2c_device;

//! @brief P1003 touch screen controller
extern const i2c_device_info_t g_p1003_tsc_i2c_device;

//! @brief AT24Cxx EEPROM
extern const i2c_device_info_t g_at24cx_i2c_device;

//! @brief Si476x FM tuner
extern const i2c_device_info_t g_si476x_i2c_device;

#endif // __BOARD_I2C_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
