/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#if !defined(__tempmon_h__)
#define __tempmon_h__

#include "sdk.h"

//! @addtogroup tempmon
//! @{

//////////////////////////////////////////////////////////////////////////////////////////
// Types
//////////////////////////////////////////////////////////////////////////////////////////

//! @brief Callback prototype used for the temperature alarm.
typedef void (*tempmon_alarm_callback_t)(float temperature);

//////////////////////////////////////////////////////////////////////////////////////////
// API
//////////////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif


//! @brief Initialize the tempmon driver.
//!
//! @retval SUCCESS Driver was initialized successfully.
int tempmon_init(void);

//! @brief Read the current on-die temperature.
//!
//! @return The temperature of the die in degrees C.
float tempmon_get_temp(void);

//! @brief Enable the over-temperature alarm.
//!
//! @param period Measurement period in milliseconds. The maximum period is 2 seconds, and if the
//!     provided value is over this maximum then a period of 2 seconds will be used instead.
//! @param alarmTemp The alarm temperature in degrees C. When the current temperature rises above
//!     this value, an over-temperature alarm interrupt will be raised and the @a alarmCallback
//!     will be invoked.
//! @param alarmCallback Pointer to the function to be called when the current temperature rises
//!     above @a alarmTemp.
void tempmon_set_alarm(uint32_t period, float alarmTemp, tempmon_alarm_callback_t alarmCallback);

//! @brief Disable the over-temperature alarm.
//!
//! Does nothing if the alarm was not previously enabled.
void tempmon_disable_alarm(void);


#if defined(__cplusplus)
}
#endif

//! @}

#endif // __tempmon_h__
//////////////////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////////////////
