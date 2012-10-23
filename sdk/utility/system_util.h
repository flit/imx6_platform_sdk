/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  system_util.h
 * @brief header file for the system utility functions.
 *
 */

#ifndef _SYSTEM_UTIL_H_
#define _SYSTEM_UTIL_H_

#include "sdk.h"

//! @addtogroup diag_util
//! @{

////////////////////////////////////////////////////////////////////////////////
// Board support
////////////////////////////////////////////////////////////////////////////////

//! @name Board support
//@{
//! @brief Hardware module for debug UART.
//!
//! This hw_module is used by the driver in order to factor out board
//! specific functionality. It must be defined by the board support
//! library or the application.
extern hw_module_t g_debug_uart;
//@}

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

void _sys_exit(int32_t return_code);

/*!
 * @brief breakpoint function
 */
void mybkpt(void);

/*!
 * This function waits for an input char to be received from the UART. Once a char is received,
 * it tests against the passed in char and return 0 if they don't match. 
 * @param   c        the input character to be expected (NOT case sensitive)
 * @param   indent   pointer to a character buffer to use for indenting text to screen
 * @return  0        if input char doesn't match with c
 *          non-zero otherwise
 */
int32_t is_input_char(uint8_t c, const char* const indent);

uint32_t get_input_hex(void);

int read_int(void);

#if defined(__cplusplus)
}
#endif

//! @}

#endif //_SYSTEM_UTIL_H_
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
