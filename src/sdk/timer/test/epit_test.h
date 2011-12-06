/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file epit_test.h
 * @brief EPIT unit tests header file.
 *
 * @ingroup diag_timer
 */

#include "hardware.h"

void tick_timer_interrupt_routine(void);
int32_t epit_test(void);
void epit_delay_test(void);
void epit_tick_test(void);
