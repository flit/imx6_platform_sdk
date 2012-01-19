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

#include "io.h"

/* SNVS driver API */
void srtc_init(void);
void srtc_deinit(void);
void srtc_setup_onetime_timer(uint32_t timeout, funct_t callback);

#endif //__SRTC_H__
