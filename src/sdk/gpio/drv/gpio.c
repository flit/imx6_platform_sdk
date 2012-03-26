/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpio.c
 * @brief Driver to control the GPIO module.
 * @ingroup diag_gpio
 */

#include "hardware.h"
#include "gpio/gpio.h"
#include "registers/regsgpio.h"

int32_t gpio_get_port_count(void)
{
    return HW_GPIO_INSTANCE_COUNT;
}

int32_t gpio_dir_config(int32_t port, int32_t pin, int32_t dir)
{
    uint32_t oldVal = 0, newVal = 0;

    if ((port >= HW_GPIO_INSTANCE_COUNT) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~%d] Is Allowed!\n", port, HW_GPIO_INSTANCE_COUNT);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }
    
    // Convert port to base 1.
    port += 1;

    oldVal = HW_GPIO_GDIR_RD(port);

    if (dir == GPIO_GDIR_INPUT)
        newVal = oldVal & (~(1 << pin));
    else
        newVal = oldVal | (1 << pin);

    HW_GPIO_GDIR_WR(port, newVal);
    
    return 0;
}

int32_t gpio_write_data(int32_t port, int32_t pin, uint32_t attr)
{
    int32_t dir;
    uint32_t oldVal = 0, newVal = 0;

    if ((port >= HW_GPIO_INSTANCE_COUNT) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~%d] Is Allowed!\n", port, HW_GPIO_INSTANCE_COUNT);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }
    
    // Convert port to base 1.
    port += 1;

    dir = (HW_GPIO_GDIR_RD(port) >> pin) & 1;

    if (dir != 1) {
        printf("GPIO%d_%d is not configured to be output!\n", port, pin);
        return -1;
    }

    oldVal = HW_GPIO_DR_RD(port);

    if (attr == 0)
        newVal = oldVal & (~(1 << pin));
    else if (attr == 1)
        newVal = oldVal | (1 << pin);

    HW_GPIO_DR_WR(port, newVal);
    return 0;
}

int32_t gpio_read_data(int32_t port, int32_t pin)
{
    int32_t dir;

    if ((port >= HW_GPIO_INSTANCE_COUNT) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~%d] Is Allowed!\n", port, HW_GPIO_INSTANCE_COUNT);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }
    
    // Convert port to base 1.
    port += 1;

    dir = (HW_GPIO_GDIR_RD(port) >> pin) & 1;

    if (dir != 0) {
        printf("GPIO%d_%d is not configured to be input!\n", port, pin);
        return -1;
    }

    return (HW_GPIO_PSR_RD(port) >> pin) & 1;
}
