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

/* RTC driver API */
void rtc_init(void);
void rtc_deinit(void);
void rtc_setup_onetime_timer(uint64_t timeout, funct_t callback);
void rtc_setup_periodic_timer(uint32_t periodic_bit, funct_t callback);
void rtc_disable_periodic_timer(void);

#endif //__RTC_H__
