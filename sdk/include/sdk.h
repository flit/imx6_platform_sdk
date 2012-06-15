/*
 * Copyright (C) 2008-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file sdk.h
 * @brief       Basic defines
 *
 * @ingroup diag_init
 */
#ifndef __SDK_H__
#define __SDK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "sdk_types.h"
#include "io.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////


#define TRUE        1
#define FALSE       0

#define NONE_CHAR   (0xFF)

//! @name Min/max macros
//@{
#if !defined(MIN)
    #define MIN(a, b)   ((a) < (b) ? (a) : (b))
#endif

#if !defined(MAX)
    #define MAX(a, b)   ((a) > (b) ? (a) : (b))
#endif
//@}

//! @brief Debug print utility.
//!
//! This print function will only output text when the @a DEBUG macro is defined.
static inline void debug_printf(const char * format, ...)
{
#if defined(DEBUG)
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
#endif
}

//! @name Test results
//@{
#define TEST_PASSED     (0)
#define TEST_FAILED     (-1)
#define TEST_BYPASSED   (2)
#define TEST_NOTPRESENT (3)
//@}

//! @name Return codes
//@{
// #define SUCCESS (0)
// #define ERROR (1)
//@}

#endif // __SDK_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
