/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__PLATFORM_INIT_H__)
#define __PLATFORM_INIT_H__

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @brief Do basic hardware initialization to make the system usable.
//!
//! Performs minimal initialization to enable most drivers to work. The GIC,
//! CCM, and UART drivers are inited. The systme timer is inited. And
//! board_ioexpander_init() is called.
void platform_init(void);

////////////////////////////////////////////////////////////////////////////////
// Board support
////////////////////////////////////////////////////////////////////////////////

//! @name Board support
//!
//! Defined in the board support library and used from platform_init().
//@{
/*!
 * @brief Retrieve the freq info based on the passed in module base address.
 *
 * @param   module_base     The base address of the module.
 * @return  Frequency in Hz or 0 for an invalid module.
 */
uint32_t get_module_freq(uint32_t module_base);

//! @brief Array of pointers to modules defined in this file.
//!
//! The array is terminated with a NULL entry.
extern hw_module_t * g_imx_modules[];
//@}

#if defined(__cplusplus)
}
#endif

#endif // __PLATFORM_INIT_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
