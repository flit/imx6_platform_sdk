/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <string.h>
#include <stdio.h>

#include "ipu_common.h"
#include "ips_test.h"

int ips_combiner_test(ips_dev_panel_t * panel)
{
    uint32_t ipu_index = 1;     // use ipu 1
    uint32_t fg_width = 600, fg_height = 100;
    uint8_t revchar;

    printf("\n-- Combiner Test ---\n");
    /*reset IPU */
    ipu_sw_reset(ipu_index, 1000);

    /*setup IPU dual display channel, enable partial plane */
    ipu_dual_display_setup(ipu_index, panel, INTERLEAVED_RGB, fg_width, fg_height);

    /*enable ipu display channel */
    ipu_enable_display(ipu_index);

    /*load background image */
    load_centralized_image(CH23_EBA0, panel);
    /*load foreground image */
    load_foreground_image(CH27_EBA0, fg_width, fg_height);

    printf
        ("Do you see the logo(background) and text (foreground) in the bottom of your screen (y or n)?\n");
    do {
        revchar = getchar();
    } while (revchar == (uint8_t) 0xFF);
    if (!(revchar == 'Y' || revchar == 'y')) {
        //disable the foreground channel.
        ipu_idmac_channel_enable(ipu_index, 27, 0);
        ipu_dp_config(ipu_index, NO_CSC, 1, 0, 0, 0);
        return FALSE;
    }

    return TRUE;
}
