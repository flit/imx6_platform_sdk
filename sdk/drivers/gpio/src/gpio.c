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

int32_t gpio_set_direction(int32_t port, int32_t pin, int32_t dir)
{
    uint32_t oldVal = 0, newVal = 0;

    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
        		port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }
    
    oldVal = HW_GPIO_GDIR_RD(port);

    if (dir == GPIO_GDIR_INPUT)
        newVal = oldVal & (~(1 << pin));
    else
        newVal = oldVal | (1 << pin);

    HW_GPIO_GDIR_WR(port, newVal);

    return 0; //SUCCESS;
}

int32_t gpio_set_level(int32_t port, int32_t pin, uint32_t level)
{
    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
        		port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    uint32_t mask = 1 << pin;

    int32_t dir = HW_GPIO_GDIR_RD(port) & mask ? GPIO_GDIR_OUTPUT : GPIO_GDIR_INPUT;

    if (dir != GPIO_GDIR_OUTPUT)
    {
        printf("GPIO_PORT%d_%d is not configured to be output!\n", port, pin);
        return -1;
    }

    uint32_t value = HW_GPIO_DR_RD(port);   // read current value

    if (level == GPIO_LOW_LEVEL)            // fix it up
    	value &= ~mask;
    else if ( level == GPIO_HIGH_LEVEL)
    	value |= mask;

    HW_GPIO_DR_WR(port, value);             // write new value

    return 0; //SUCCESS;
}

int32_t gpio_get_level(int32_t port, int32_t pin)
{
    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
        		port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    uint32_t mask = 1 << pin;

    return HW_GPIO_PSR_RD(port) & mask ? GPIO_HIGH_LEVEL : GPIO_LOW_LEVEL;
}

int32_t gpio_set_interrupt_config(int32_t port, int32_t pin, int32_t config)
{
    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
        		port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    if (pin < 16)
    {
        // GPIOs 0-15 use ICR1 register
    	uint32_t value = HW_GPIO_ICR1_RD(port);        // read current value
    	uint32_t field_offset = pin * 2;               // fields are 2 bits wide
        value &= ~(BM_GPIO_ICR1_ICR0 << field_offset); // clear specified field
        value |= config << field_offset;               // set specified field
        HW_GPIO_ICR1_WR(port, value);                  // write new value
    }
    else
    {
        // GPIOs 16-31 use ICR2 register
        uint32_t value = HW_GPIO_ICR2_RD(port);         // read current value
    	uint32_t field_offset = (pin - 16) * 2;         // fields are 2 bits wide
        value &= ~(BM_GPIO_ICR2_ICR16 << field_offset); // clear specified field
        value |= config << field_offset;                // set specified field
        HW_GPIO_ICR1_WR(port, value);                   // write new value
    }

    return 0; //SUCCESS;
}

int32_t gpio_set_interrupt_mask(int32_t port, int32_t pin, int32_t mask)
{
    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
        		port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    uint32_t value = HW_GPIO_IMR_RD(port);

    if (mask == GPIO_IMR_MASKED)
        value &= ~(1 << pin);
    else
        value |= 1 << pin;

    HW_GPIO_GDIR_WR(port, value);

    return 0; //SUCCESS;
}

int32_t gpio_get_interrupt_status(int32_t port, int32_t pin)
{
    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
        		port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    return HW_GPIO_ISR_RD(port) & (1 << pin) ? GPIO_ISR_ASSERTED : GPIO_ISR_NOT_ASSERTED;
}

int32_t gpio_clear_interrupt(int32_t port, int32_t pin)
{
    if ((port > HW_GPIO_INSTANCE_COUNT) || (port < 1))
    {
        printf("Invalid GPIO Instance GPIO_PORT%d parameter. GPIO_PORT1~GPIO_PORT%d is allowed.\n",
        		port, HW_GPIO_INSTANCE_COUNT);
        return INVALID_PARAMETER;
    }

    if ((pin > 31) || (pin < 0))
    {
        printf("Invalid GPIO Pin %d parameter. Pin 0~31 is allowed.\n", pin);
        return INVALID_PARAMETER;
    }

    uint32_t value = HW_GPIO_ISR_RD(port);
    value |= 1 << pin;
    HW_GPIO_ISR_WR(port, value);
    
    return 0; //SUCCESS;
}
