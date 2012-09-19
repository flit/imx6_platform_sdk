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

int32_t gpio_dir_config(int32_t instance, int32_t pin, int32_t dir)
{
    uint32_t oldVal = 0, newVal = 0;

    if ((instance > HW_GPIO_INSTANCE_COUNT) || (instance < 1)) {
        printf("Invalid GPIO Instance HW_GPIO%d parameter. HW_GPIO1~HW_GPIO%d is allowed.\n",
        		instance, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }
    
    oldVal = HW_GPIO_GDIR_RD(instance);

    if (dir == GPIO_GDIR_INPUT)
        newVal = oldVal & (~(1 << pin));
    else
        newVal = oldVal | (1 << pin);

    HW_GPIO_GDIR_WR(instance, newVal);

    return 0; //SUCCESS;
}

int32_t gpio_int_config(int32_t instance, int32_t pin, int32_t config)
{
    if ((instance > HW_GPIO_INSTANCE_COUNT) || (instance < 0)) {
        printf("Invalid GPIO Instance HW_GPIO%d parameter. HW_GPIO1~HW_GPIO%d is allowed.\n",
        		instance, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    if (pin < 16)
    {
        // GPIOs 0-15 use ICR1 register
    	uint32_t value = HW_GPIO_ICR1_RD(instance);    // read current value
    	uint32_t field_offset = pin * 2;               // fields are 2 bits wide
        value &= ~(BM_GPIO_ICR1_ICR0 << field_offset); // clear specified field
        value |= config << field_offset;               // set specified field
        HW_GPIO_ICR1_WR(instance, value);              // write new value
    }
    else
    {
        // GPIOs 16-31 use ICR2 register
        uint32_t value = HW_GPIO_ICR2_RD(instance);     // read current value
    	uint32_t field_offset = (pin - 16) * 2;         // fields are 2 bits wide
        value &= ~(BM_GPIO_ICR2_ICR16 << field_offset); // clear specified field
        value |= config << field_offset;                // set specified field
        HW_GPIO_ICR1_WR(instance, value);               // write new value
    }

    return 0; //SUCCESS;
}

int32_t gpio_int_mask(int32_t instance, int32_t pin, int32_t mask)
{
    if ((instance > HW_GPIO_INSTANCE_COUNT) || (instance < 1)) {
        printf("Invalid GPIO Instance HW_GPIO%d parameter. HW_GPIO1~HW_GPIO%d is allowed.\n",
        		instance, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    uint32_t value = HW_GPIO_IMR_RD(instance);

    if (mask == GPIO_IMR_MASKED)
        value &= ~(1 << pin);
    else
        value |= 1 << pin;

    HW_GPIO_GDIR_WR(instance, value);

    return 0; //SUCCESS;
}

int32_t gpio_int_status(int32_t instance, int32_t pin)
{
    if ((instance > HW_GPIO_INSTANCE_COUNT) || (instance < 1)) {
        printf("Invalid GPIO Instance HW_GPIO%d parameter. HW_GPIO1~HW_GPIO%d is allowed.\n",
        		instance, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    return HW_GPIO_ISR_RD(instance);
}

int32_t gpio_int_clear(int32_t instance, int32_t pin)
{
    if ((instance > HW_GPIO_INSTANCE_COUNT) || (instance < 1)) {
        printf("Invalid GPIO Instance HW_GPIO%d parameter. HW_GPIO1~HW_GPIO%d is allowed.\n",
        		instance, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    uint32_t value = HW_GPIO_ISR_RD(instance);
    value |= 1 << pin;
    HW_GPIO_ISR_WR(instance, value);
    
    return 0; //SUCCESS;
}

int32_t gpio_write_data(int32_t port, int32_t pin, uint32_t attr)
{
    int32_t dir;
    uint32_t oldVal = 0, newVal = 0;

    if ((port >= HW_GPIO_INSTANCE_COUNT) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~%d] Is Allowed!\n", port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return INVALID_PARAMETER;
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
    return 0; //SUCCESS;
}

int32_t gpio_read_data(int32_t port, int32_t pin)
{
    int32_t dir;

    if ((port >= HW_GPIO_INSTANCE_COUNT) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~%d] Is Allowed!\n", port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return INVALID_PARAMETER;
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
