/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpt_test.h
 * @brief GPT unit tests header file.
 *
 * @ingroup diag_timer
 */

#include "hardware.h"

void gpt_interrupt_routine(void);
int32_t gpt_test(void);
void gpt_out_compare_test(void);
void gpt_in_capture_test(void);
