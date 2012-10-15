/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
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

#include "sdk.h"

static void tick_timer_interrupt_routine(void);
static void epit_delay_test(void);
static void epit_tick_test(void);
int32_t epit_test(void);