/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __VDOA_H__
#define __VDOA_H__

#include "sdk.h"

//! @addtogroup diag_vdoa
//! @{

//////////////////////////////////////////////////////////////////////////////
// API
//////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Configure the VDOA attribute before transfer start
 *
 * @param width Frame/Field width
 * @param height Frame/Field height
 * @param vpu_sl Strideline for the VPU output memory
 * @param ipu_sl Strideline for the IPU input memory
 * @param interlaced Setting of frame mode, interlaved or progressive
 * @param ipu_sel IPU index selection
 * @param bandLines set the line numbers per band
 * @param pfs Set the pixel format
 */
void vdoa_setup(int width, int height, int vpu_sl, int ipu_sl, int interlaced,
                int ipu_sel, int bandLines, int pfs);

/*!
 * @brief Configure the VDOA for video data transition
 *
 * @param src Source buffer address
 * @param vubo U component offset used for VPU output
 * @param dst Destination buffer address
 * @param iubo U componet offset used for IPU input
 *
 */
void vdoa_start(uint32_t src, uint32_t ubo, uint32_t dst, uint32_t iubo);

/*!
 * @brief Enable VDOA EOT interrupt
 */
void vdoa_enable_interrupt(void);

/*!
 * @brief Disable VDOA EOT interrupt
 */
void vdoa_disable_interrupt(void);

/*!
 * @brief Clear the VDOA EOT(End Of Tranfer) interrupt state
 */
void vdoa_clear_interrupt(void);

/*!
 * @brief Check the VDOA tranfer state
 */
bool vdoa_check_tx_eot(void);

//! @}

#endif

//////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////
