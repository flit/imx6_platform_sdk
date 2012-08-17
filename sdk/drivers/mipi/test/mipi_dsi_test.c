/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  mipi_csi2_test.c
 * @brief common functions for mipi csi.
 *
 * @ingroup diag_mipi
 */

#include "mipi/mipi_common.h"
#include "hardware.h"
#include <stdio.h>

extern int32_t ips_mipi_wvga_rgb_stream(int32_t ipu_index);

int32_t mipi_dsi_test(void)
{
    ips_mipi_wvga_rgb_stream(1);
    mipi_dsi_init();
    return true;
}
