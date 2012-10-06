/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_I2C_INTERNAL_H__
#define __IMX_I2C_INTERNAL_H__

#include "i2c/imx_i2c.h"
#include "registers/regsi2c.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! Max number of operations to wait to receive ack.
#define WAIT_RXAK_LOOPS     1000000

//! Max number of operations to wait until busy.
#define WAIT_BUSY_LOOPS     100000

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Setup I2C interrupt.
 *
 * It enables or disables the related HW module interrupt, and attached the related
 * sub-routine into the vector table.
 *
 * @param   port Pointer to the I2C module structure.
 * @param   state Enable or disable the interrupt. Pass true to enable.
 */
void i2c_setup_interrupt(const hw_module_t *port, bool state);

/*!
 * @brief I2C interrupt routine for slave transfers.
 */
void i2c_slave_interrupt_routine(void);

//! @brief Returns the I2C controller instance from a request struct.
unsigned i2c_get_request_instance(const imx_i2c_request_t * rq);

#if defined(__cplusplus)
}
#endif

#endif // __IMX_I2C_INTERNAL_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
