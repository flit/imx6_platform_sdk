/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file hardware_modules.h
 * @brief Declarations for common hw_module structs.
 */

#if !defined(__HARDWARE_MODULES_H__)
#define __HARDWARE_MODULES_H__

#include "sdk.h"

////////////////////////////////////////////////////////////////////////////////
// Globals
////////////////////////////////////////////////////////////////////////////////

//! @brief The UART to use for debug console prints.
extern hw_module_t g_debug_uart;

//! @brief Timer used for delays other other system timing tasks.
extern hw_module_t g_system_timer;

//! @brief Array of pointers to modules defined in this file.
//!
//! The array is terminated with a NULL entry.
extern hw_module_t * g_imx_modules[];

////////////////////////////////////////////////////////////////////////////////
// Protoypes
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif


/*!
 * @brief Fills in the frequency info in each module's structure.
 */
void freq_populate(void);


#if defined(__cplusplus)
}
#endif

#endif // __HARDWARE_MODULES_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
