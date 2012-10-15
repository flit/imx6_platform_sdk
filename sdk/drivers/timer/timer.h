/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

//! @addtogroup diag_timer
//! @{

/*!
 * @file timer.h
 * @brief various defines used by the timer driver.
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#include "sdk.h"

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////

//! @brief Options for low power mode support for the timers.
//!
//! These constants are bit masks that are or'd together to select in which low
//! power modes the timer will continue counting.
enum _timer_low_power_modes
{
    WAIT_MODE_EN = 1,   //!< Timer is enabled in wait mode.
    STOP_MODE_EN = 2    //!< Timer is enabled in stop mode.
};

//! @brief Available clock sources for the timers.
enum _timer_clock_sources
{
    CLKSRC_OFF = 0,     //!< clock source is OFF
    CLKSRC_IPG_CLK = 1, //!< clock source is peripheral clock
    CLKSRC_PER_CLK = 2, //!< clock source is high-freq reference clock
    CLKSRC_CLKIN = 3,   //!< clock source is external from a CLKIN input
    CLKSRC_CKIL = 3     //!< clock source is low-freq reference clock
};

//! @brief Do not enable interrupts.
#define POLLING_MODE 0

////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

//! @brief Hardware module for system timer.
//!
//! This hw_module is used by the driver in order to factor out board
//! specific functionality. It must be defined by the board support
//! library or the application.
extern hw_module_t g_system_timer;

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

//! @}

#endif // __TIMER_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
