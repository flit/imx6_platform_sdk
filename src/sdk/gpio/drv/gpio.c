/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpio.c
 * @brief Driver to control the GPIO module.
 *
 */

#include "hardware.h"

/*!
 * Sets the GPIO direction for the specified pin.
 *
 * @param	port: 	GPIO module instance, 0 to MAX_GPIO_PORT.
 * @param 	pin:	GPIO pin 0 to 31.
 * @param 	dir:	direction for the pin. in or out.
 * @return -1 means failed to set the pin
 */
int32_t gpio_dir_config(int32_t port, int32_t pin, int32_t dir)
{
    uint32_t oldVal = 0, newVal = 0;

    if ((port >= MAX_GPIO_PORT) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~%d] Is Allowed!\n", port, MAX_GPIO_PORT);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    oldVal = readl(g_mx_gpio_port[port] + GPIO_GDIR_OFFSET);

    if (dir == GPIO_GDIR_INPUT)
        newVal = oldVal & (~(1 << pin));
    else
        newVal = oldVal | (1 << pin);

    writel(newVal, g_mx_gpio_port[port] + GPIO_GDIR_OFFSET);
    return 0;
}

/*!
 *	Sets the GPIO attributte(high or low) for the specified pin.
 *
 *  @param  port: 	GPIO module instance, 0 to MAX_GPIO_PORT.
 *	@param  pin:	GPIO pin 0 to 31.
 *  @param  attr:	attributte for the pin. high/low
 *  @return  -1 means failed to set the pin
 */
int32_t gpio_write_data(int32_t port, int32_t pin, uint32_t attr)
{
    int32_t dir;
    uint32_t oldVal = 0, newVal = 0;

    if ((port >= MAX_GPIO_PORT) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~%d] Is Allowed!\n", port, MAX_GPIO_PORT);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    dir = (readl(g_mx_gpio_port[port] + GPIO_GDIR_OFFSET) & (1 << pin)) >> pin;

    if (dir != 1) {
        printf("GPIO%d_%d is not configured to be output!\n", port + 1, pin);
        return -1;
    }

    oldVal = readl(g_mx_gpio_port[port] + GPIO_DR_OFFSET);

    if (attr == 0)
        newVal = oldVal & (~(1 << pin));
    else if (attr == 1)
        newVal = oldVal | (1 << pin);

    writel(newVal, g_mx_gpio_port[port] + GPIO_DR_OFFSET);
    return 0;
}

/*!
 *	Gets the GPIO attributte(high or low) for the specified pin.
 *
 *  @param	port: 	GPIO module instance, 0 to MAX_GPIO_PORT.
 *	@param	pin:	GPIO pin 0 to 31.
 *  @return	-1 means failed to get the value
*/
int32_t gpio_read_data(int32_t port, int32_t pin)
{
    int32_t dir;

    if ((port >= MAX_GPIO_PORT) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~%d] Is Allowed!\n", port, MAX_GPIO_PORT);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    dir = (readl(g_mx_gpio_port[port] + GPIO_GDIR_OFFSET) & (1 << pin)) >> pin;

    if (dir != 0) {
        printf("GPIO%d_%d is not configured to be input!\n", port + 1, pin);
        return -1;
    }

    return (readl(g_mx_gpio_port[port] + GPIO_DR_OFFSET) & (1 << pin)) >> pin;
}
