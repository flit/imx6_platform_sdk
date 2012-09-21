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


//! @addtogroup diag_gpio
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Available GPIO ports.
typedef enum {
	GPIO_NONE  = 0,
	GPIO_PORT1 = 1,
    GPIO_PORT2 = 2,
    GPIO_PORT3 = 3,
    GPIO_PORT4 = 4,
    GPIO_PORT5 = 5,
    GPIO_PORT6 = 6,
    GPIO_PORT7 = 7,
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

#define GPIO_ISR_NOT_ASSERTED       0   //!< Interrupt is not asserted
#define GPIO_ISR_ASSERTED           1   //!< Interrupt is asserted

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
 * @brief Returns the number of available GPIO instances.
 * @return An integer number of GPIO instances on this hardware.
 */
int32_t gpio_get_port_count(void);

/*!
 * @brief Sets the GPIO direction for the specified pin.
 *
 * @param   port : GPIO module instance, GPIO_PORT1, GPIO_PORT2, ... gpio_get_port_count().
 * @param   pin  : GPIO pin 0 to 31.
 * @param   dir  : Direction for the pin. GPIO_GDIR_INPUT(0) or GPIO_GDIR_OUTPUT(1).
 * @return  INVALID_PARAMETER(-1)
 */
int32_t gpio_set_direction(int32_t port, int32_t pin, int32_t dir);

/*!
 * @brief Sets the GPIO level(high or low) for the specified pin.
 *
 * @warning Fails if pin is not configured as an output.
 *
 * @param   port  : GPIO module instance, GPIO_PORT1, GPIO_PORT2, ... gpio_get_port_count().
 * @param   pin   : GPIO pin 0 to 31.
 * @param   level : GPIO_LOW_LEVEL(0), GPIO_HIGH_LEVEL(1)
 * @return  INVALID_PARAMETER(-1)
 */
int32_t gpio_set_level(int32_t port, int32_t pin, uint32_t level);

/*!
 *	Gets the GPIO level(high or low) for the specified pin.
 *
 *	@note Returns level for both input and output configured pins.
 *
 * @param   port : GPIO module instance, GPIO_PORT1, GPIO_PORT2, ... gpio_get_port_count().
 * @param   pin  : GPIO pin 0 to 31.
 * @retval  INVALID_PARAMETER(-1),
 * @retval  GPIO_LOW_LEVEL(0),
 * @retval  GPIO_HIGH_LEVEL(1)
*/
int32_t gpio_get_level(int32_t port, int32_t pin);

/*!
 * @brief Configures the interrupt condition for the specified GPIO input pin.
 *
 * @param   port : GPIO module instance, GPIO_PORT1, GPIO_PORT2, ... gpio_get_port_count().
 * @param   pin : GPIO pin 0 to 31.
 * @param   config : Interrupt condition for the pin. GPIO_ICR_LOW_LEVEL(0), GPIO_ICR_HIGH_LEVEL(1),
 *                   GPIO_ICR_RISE_EDGE(2), GPIO_ICR_FALL_EDGE(3)
 * @return INVALID_PARAMETER(-1)
 */
int32_t gpio_set_interrupt_config(int32_t port, int32_t pin, int32_t config);

/*!
 * @brief Enables/Disables the interrupt for the specified GPIO input pin.
 *
 * @param   port : GPIO module instance, GPIO_PORT1, GPIO_PORT2, ... gpio_get_port_count().
 * @param   pin : GPIO pin 0 to 31.
 * @param   mask : interrupt mask for the pin. GPIO_IMR_MASKED(0), GPIO_IMR_UNMASKED(1)
 * @return  INVALID_PARAMETER(-1)
 */
int32_t gpio_set_interrupt_mask(int32_t port, int32_t pin, int32_t mask);

/*!
 * @brief Gets the GPIO interrupt status for the specified pin.
 *
 * @param   port : GPIO module instance, GPIO_PORT1, GPIO_PORT2, ... gpio_get_port_count().
 * @param   pin : GPIO pin 0 to 31.
 * @return  INVALID_PARAMETER(-1), GPIO_ISR_NOT_ASSERTED(0), GPIO_ISR_ASSERTED(1)
 */
int32_t gpio_get_interrupt_status(int32_t port, int32_t pin);

/*!
 * @brief Clears the GPIO interrupt for the specified pin.
 *
 * @param   port : GPIO module instance, GPIO_PORT1, GPIO_PORT2, ... gpio_get_port_count().
 * @param   pin : GPIO pin 0 to 31.
 * @return  INVALID_PARAMETER(-1)
 */
int32_t gpio_clear_interrupt(int32_t port, int32_t pin);

#if defined(__cplusplus)
}
#endif

//! @}

#endif //__GPIO_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
