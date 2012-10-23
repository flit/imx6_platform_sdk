/*
 * Copyright (C) 2008-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __SDK_TYPES_H__
#define __SDK_TYPES_H__

//! @addtogroup sdk_common
//! @{

/*!
 * @file sdk_types.h
 * @brief Basic types used throughout the SDK.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @name Alternate Boolean constants
//@{
#define TRUE        1
#define FALSE       0
//@}

//! @brief 
#define NONE_CHAR   (0xFF)

//! @brief A parameter was out of range or otherwise invalid.
#define INVALID_PARAMETER (-1)

//! @name Min/max macros
//@{
#if !defined(MIN)
    #define MIN(a, b)   ((a) < (b) ? (a) : (b))
#endif

#if !defined(MAX)
    #define MAX(a, b)   ((a) > (b) ? (a) : (b))
#endif
//@}

//! @brief Computes the number of elements in an array.
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))

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
typedef enum _test_return
{
	TEST_NOT_IMPLEMENTED = -2, // present in the menu, but not functional
	TEST_FAILED          = -1,
    TEST_PASSED          = 0,
    TEST_BYPASSED        = 2,  // user elected to exit the test before it was run
    TEST_NOT_PRESENT     = 3,  // not present in the menu.
    TEST_CONTINUE        = 4   // proceed with the test. opposite of TEST_BYPASSED
} test_return_t;

//! @name Return codes
//@{
// #define SUCCESS (0)
// #define ERROR (1)
//@}

//! @brief Defines a pointer to a function.
typedef void (*funct_t) (void);

/*!
 * @brief Details of a hardware peripheral instance.
 */
typedef struct hw_module {
    const char *name;       //!< Name of the module.
    uint32_t instance;    //!< The number of this module instance. The first instance is number 1.
    uint32_t base;      //!< Module base address.
    uint32_t freq;      //!< Input clock frequency.
    uint32_t irq_id;    //!< ID of its interrupt.
    void (*irq_subroutine)(void);   //!< Module interrupt sub-routine address.
    void (*iomux_config) (void);   //!< Module I/O mux configuration function.
} hw_module_t;

//! @brief Possible types of displays.
enum display_type {
    DISP_DEV_NULL = 0,
    DISP_DEV_TFTLCD,
    DISP_DEV_LVDS,
    DISP_DEV_VGA,
    DISP_DEV_HDMI,
    DISP_DEV_TV,
    DISP_DEV_MIPI,
};

//! @}

#endif // __SDK_TYPES_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
