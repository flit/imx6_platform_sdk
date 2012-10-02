/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#if !defined(__PRINT_CLOCK_INFO_H__)
#define __PRINT_CLOCK_INFO_H__

#include "sdk.h"

//! @addtogroup app_common
//! @{

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif


/*!
 * @brief Display module frequency
 */
void show_freq(void);

/*!
 * @brief Display the board's DDR configuration
 */
void show_ddr_config(void);


#if defined(__cplusplus)
}
#endif

//! @}

#endif // __PRINT_CLOCK_INFO_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
