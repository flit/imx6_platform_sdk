/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#if !defined(__MAX7310_H__)
#define __MAX7310_H__

#include "sdk.h"
#include "i2c/imx_i2c.h"

//! @addtogroup diag_ioexpander
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief An array of I2C requests for all used expanders on the board.
//!
//! This array is used to specify the I2C addresses for the I/O expanders.
extern imx_i2c_request_t max7310_i2c_req_array[];

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize the MAX7310.
 *
 * Sets a a default I/O direction and output value. The I2C bus reset on timeout
 * feature is disabled.
 *
 * The MAX7310 has no ID register, so one the timeout register is also initialized
 * with a value of 0xAC. This can be used later to verify the presence of the device.
 *
 * @param slave_id         I/O expander instance number
 * @param io_default_dir   default I/O direction
 * @param out_default_val  default output value
 * 
 * @return 0 on success; non-zero otherwise
 */
int32_t max7310_init(uint32_t slave_id, uint32_t io_default_dir, uint32_t out_default_val);

/*!
 * @brief Controls the MAX7310 output pin state.
 *
 * @param slave_id   I/O expander instance number (0=instance 0,...)
 * @param io_x       I/O number (0=IO_0, 1=IO_1, ...)
 * @param level      I/O state (0=low, 1=high)
 * 
 * @return 0 on success; non-zero otherwise
 */
void max7310_set_gpio_output(uint32_t slave_id, uint32_t io_x, uint32_t level);

#if defined(__cplusplus)
}
#endif

//! @}

#endif // __MAX7310_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
