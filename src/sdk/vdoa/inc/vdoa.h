/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __VDOA_H__
#define __VDOA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hardware.h"

void vdoa_setup(int width, int height, int vpu_sl, int ipu_sl, int interlaced,
                int ipu_sel, int bandLines, int pfs);
void vdoa_start(uint32_t src, uint32_t ubo, uint32_t dst, uint32_t iubo);
void vdoa_enable_interrupt(void);
void vdoa_disable_interrupt(void);
void vdoa_clear_interrupt(void);
void vdoa_set_vpu_buffer(uint32_t vbuf);
void vdoa_set_ipu_buffer(uint32_t ibuf);
void vdoa_set_vpu_ubo(uint32_t vubo);
void vdoa_set_ipu_ubo(uint32_t iubo);
void vdoa_start_transfer(void);
bool vdoa_check_tx_eot(void);

#endif
