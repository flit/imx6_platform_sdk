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
//! board_init() is called.
void platform_init(void);

#if defined(__cplusplus)
}
#endif

#endif // __PLATFORM_INIT_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
