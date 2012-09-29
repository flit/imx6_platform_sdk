/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file srtc.h
 * @brief  SNVS SRTC driver header file.
 *
 * @ingroup diag_timer
 */

#ifndef __SRTC_H__
#define __SRTC_H__

#include "sdk.h"

//! @addtogroup diag_srtc
//! @{

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initializes SRTC.
 *
 * Enables the secure real time counter and disables time alarm. It also calls
 * register the interrupt service handler.
 */
void srtc_init(void);

/*!
 * @brief Disables interrupt, counter and time alarm 
 */
void srtc_deinit(void);

/*!
 * @brief Setup SRTC one-time timer.
 *
 * @param   timeout Set SRTC alarm timeout.
 * @param   callback Callback function to be called from isr.
 */
void srtc_setup_onetime_timer(uint32_t timeout, funct_t callback);

#if defined(__cplusplus)
}
#endif

//! @}

#endif //__SRTC_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
