/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ipu_common.h"
#include "ips_test.h"

/*!
 * LVDS display test case. note that the memory for the flow is not released
 */
int ips_display_test(ips_dev_panel_t * panel)
{
    uint32_t ipu_index = 1;     // use ipu 1
    uint8_t revchar;

    printf("\n-- Single Image Display -- \n");
    /*reset IPU */
    ipu_sw_reset(ipu_index, 1000);

    /*setup IPU display channel */
    ipu_display_setup(ipu_index, panel, INTERLEAVED_RGB, NO_CSC);

    /*enable ipu display channel */
    ipu_enable_display(ipu_index);

    /*load image */
    load_centralized_image(CH23_EBA0, panel);

    printf("Do you see the image (y or n)?\n");
    do {
        revchar = getchar();
    } while (revchar == (uint8_t) 0xFF);
    if (!(revchar == 'Y' || revchar == 'y'))
        return FALSE;

    return TRUE;
}

/*!
 * HDMI 1080P60 display stream
 */
int ips_hdmi_stream(void)
{
    ips_dev_panel_t *panel;
    uint32_t ipu_index = 1;     // use ipu 1
    uint8_t revchar;

    /*enable panel */
    panel = search_panel("HDMI 1080P 60Hz");
    panel->panel_init();

    printf("\n-- Single Image Display -- \n");
    /*reset IPU */
    ipu_sw_reset(ipu_index, 1000);

    /*setup IPU display channel */
    ipu_display_setup(ipu_index, panel, INTERLEAVED_RGB, NO_CSC);

    /*enable ipu display channel */
    ipu_enable_display(ipu_index);

    /*load image */
    load_centralized_image(CH23_EBA0, panel);

    printf("Do you see the image (y or n)?\n");
    do {
        revchar = getchar();
    } while (revchar == (uint8_t) 0xFF);
    if (revchar == 'Y' || revchar == 'y') {
        return TRUE;
    } else {
        return FALSE;
    }
}
