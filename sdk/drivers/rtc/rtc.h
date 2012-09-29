/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file rtc.h
 * @brief  RTC driver header file.
 *
 * @ingroup diag_timer
 */

#ifndef __RTC_H__
#define __RTC_H__

#include "sdk.h"

//! @addtogroup diag_rtc
//! @{

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initializes RTC.
 *
 * Enables non-secured real time counter, disables alarm and periodic interrupt.
 * It also registers an interrupt service handler.
 */
void rtc_init(void);

/*!
 * Disables interrupt, counter, alarm and periodic alarm
 */
void rtc_deinit(void);

/*!
 * @brief Setup up a one-shot timer.
 *
 * @param   timeout Set RTC alarm timeout.
 * @param   callback Callback function to be called from isr.
 */
void rtc_setup_onetime_timer(uint64_t timeout, funct_t callback);

/*!
 * @brief Sets up a periodic timer.
 *
 * @param   periodic_bit Periodic interrupt freq (valid values 0-15)
 * @param   callback Pointer to callback function
 */
void rtc_setup_periodic_timer(uint32_t periodic_bit, funct_t callback);

/*!
 * @brief Disables the periodic timer.
 */
void rtc_disable_periodic_timer(void);

#if defined(__cplusplus)
}
#endif

//! @}

#endif //__RTC_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
