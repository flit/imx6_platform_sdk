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

#if defined(__cplusplus)
extern "C" {
#endif

void _sys_exit(int32_t return_code);

int32_t is_input_char(uint8_t c, const char* const indent);
uint32_t get_input_hex(void);
int read_int(void);

#if defined(__cplusplus)
}
#endif

#endif //_SYSTEM_UTIL_H_
