/*
 * Copyright (C) 2008-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file sdk_types.h
 * @brief       Basic defines
 *
 * @ingroup diag_init
 */
#ifndef __SDK_TYPES_H__
#define __SDK_TYPES_H__

#define USE_STDINT 1

#include <stdbool.h>

#if USE_STDINT
#  include <stdint.h>
#endif // USE_STDINT

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

#if !USE_STDINT

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

typedef long long int64_t;
typedef int int32_t;
typedef short int16_t;
typedef char int8_t;

#endif // USE_STDINT

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

#endif // __SDK_TYPES_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
