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

#include <stdio.h>

#include "hardware.h"
#include "mipi_common.h"
#include "ipu/inc/ipu_common.h"
#include "iomux_config.h"
#include "registers/regsipu.h"

extern void mipi_csi2_config(void);

int32_t mipi_csi2_test(void)
{
    int32_t ipu_index = 1;
    ips_dev_panel_t *panel;

    printf("Runing mipi csi-2 test.\n");
    ipu1_iomux_config();
    ipu_sw_reset(ipu_index, 1000);

    panel = search_panel("HannStar XGA LVDS");
    panel->panel_init(&ipu_index);

    mipi_csi2_config();

    ipu_mipi_csi2_setup(1, 640, 480, panel);
    ipu_enable_display(ipu_index);

    ipu_channel_buf_ready(ipu_index, 0, 0);
    ipu_channel_buf_ready(ipu_index, 0, 1);
    ipu_channel_buf_ready(ipu_index, 23, 0);
    ipu_channel_buf_ready(ipu_index, 23, 1);

    while (1) {
        printf("Stop MIPI CSI? [y/n]\n");
        if (is_input_char('y'))
            break;
    }

    return TEST_PASSED;
}
