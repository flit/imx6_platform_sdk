/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file timer.h
 * @brief various defines used by the timer driver.
 * @ingroup diag_timer
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#include "sdk.h"

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////

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

#define POLLING_MODE 0

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @brief Delay for a given number of microseconds.
//!
//! system_time_init() must have been called before using this function.
//!
//! @param usecs Delay in microseconds.
void hal_delay_us(uint32_t usecs);

//! @brief Init system timer facilities.
//!
//! Inits the EPIT timer used for delay, and inits the microsecond counter.
void system_time_init(void);

//! @brief Return the current microsecond counter value.
//!
//! @return The number of microseconds elapsed since system_time_init()
//!     was called. This value may roll over before reaching all ones.
uint64_t time_get_microseconds();

#if defined(__cplusplus)
}
#endif

#endif // __TIMER_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
