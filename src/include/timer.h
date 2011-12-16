/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file timer.h
 * @brief various defines used by the timer driver.
 * @ingroup diag_timer
 */

#ifndef __TIME_H__
#define __TIME_H__

#include "io.h"

/* these defines are common to EPIT and GPT modules */
#define WAIT_MODE_EN    1
#define STOP_MODE_EN    2
#define CLKSRC_OFF      0x0 // clock source is OFF
#define CLKSRC_IPG_CLK  0x1 // clock source is peripheral clock
#define CLKSRC_PER_CLK  0x2 // clock source is high-freq reference clock
#define CLKSRC_CLKIN    0x3 // clock source is external from a CLKIN input
#define CLKSRC_CKIL     0x3 // clock source is low-freq reference clock
/* list of output modes supported by the EPIT and GPT */
#define OUTPUT_CMP_DISABLE  0x0 // output disconnected from pad
#define OUTPUT_CMP_TOGGLE   0x1 // output toggle mode
#define OUTPUT_CMP_CLEAR    0x2 // output set low mode
#define OUTPUT_CMP_SET      0x3 // output set high mode
#define OUTPUT_CMP_LOWPULSE 0x4 // output set high mode

void hal_delay_us(uint32_t usecs);
void system_time_init(void);

#endif /* __TIME_H__ */
