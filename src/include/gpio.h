/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpio.h
 * @brief  Defines related to the GPIO controller and used by gpio.c
 *
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#include "io.h"
#include "gpio_define.h"

int32_t gpio_dir_config(int32_t port, int32_t pin, int32_t dir);
int32_t gpio_write_data(int32_t port, int32_t pin, uint32_t attr);
int32_t gpio_read_data(int32_t port, int32_t pin);

#endif //__GPIO_H__
