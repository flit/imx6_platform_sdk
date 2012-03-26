/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpio.h
 * @brief  Defines related to the GPIO controller and used by gpio.c
 * @ingroup diag_gpio
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#include "sdk.h"

//! @addtogroup diag_gpio
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Available GPIO ports.
typedef enum {
    GPIO_PORT1 = 0,
    GPIO_PORT2 = 1,
    GPIO_PORT3 = 2,
    GPIO_PORT4 = 3,
    GPIO_PORT5 = 4,
    GPIO_PORT6 = 5,
    GPIO_PORT7 = 6,
} GPIO_PORT;

//! @name GPIO bitfield values
//! @todo Add these to register definition XML.
//@{
#define GPIO_GDIR_INPUT             0   //!< GPIO pin is input
#define GPIO_GDIR_OUTPUT            1   //!< GPIO pin is output

#define GPIO_LOW_LEVEL              0   //!< GPIO pin is low
#define GPIO_HIGH_LEVEL             1   //!< GPIO pin is high

#define GPIO_ICR_LOW_LEVEL          0   //!< Interrupt is low-level
#define GPIO_ICR_HIGH_LEVEL         1   //!< Interrupt is high-level
#define GPIO_ICR_RISE_EDGE          2   //!< Interrupt is rising edge
#define GPIO_ICR_FALL_EDGE          3   //!< Interrupt is falling edge

#define GPIO_IMR_MASKED             0   //!< Interrupt is masked
#define GPIO_IMR_UNMASKED           1   //!< Interrupt is unmasked

#define GPIO_EDGE_SEL_DISABLE       0   //!< Edge select is disabled
#define GPIO_EDGE_SEL_ENABLE        1   //!< Edge select is enabled
//@}

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Sets the GPIO direction for the specified pin.
 *
 * @param	port GPIO module instance, 0 to MAX_GPIO_PORT.
 * @param 	pin	GPIO pin 0 to 31.
 * @param 	dir	direction for the pin. in or out.
 * @return -1 means failed to set the pin
 */
int32_t gpio_dir_config(int32_t port, int32_t pin, int32_t dir);

/*!
 *	@brief Sets the GPIO attributte(high or low) for the specified pin.
 *
 *  @param  port GPIO module instance, 0 to MAX_GPIO_PORT.
 *	@param  pin	GPIO pin 0 to 31.
 *  @param  attr attributte for the pin. high/low
 *  @return  -1 means failed to set the pin
 */
int32_t gpio_write_data(int32_t port, int32_t pin, uint32_t attr);

/*!
 *	Gets the GPIO attributte(high or low) for the specified pin.
 *
 *  @param	port: 	GPIO module instance, 0 to MAX_GPIO_PORT.
 *	@param	pin:	GPIO pin 0 to 31.
 *  @return	-1 means failed to get the value
*/
int32_t gpio_read_data(int32_t port, int32_t pin);

#if defined(__cplusplus)
}
#endif

//! @}

#endif //__GPIO_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
