/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#if !defined(__tempmon_h__)
#define __tempmon_h__

#include "io.h"

//////////////////////////////////////////////////////////////////////////////////////////
// Public API
//////////////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @brief Initialize the tempmon driver.
//!
//! @retval SUCCESS Driver was initialized successfully.
int tempmon_init(void);

//! @brief Read the current on-die temperature.
//! @return The temperature of the die in degrees C.
int tempmon_get_temp(void);

#if defined(__cplusplus)
}
#endif

#endif // __tempmon_h__
//////////////////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////////////////
