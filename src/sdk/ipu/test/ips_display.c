/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_display.c
 * @brief IPU display test.
 * @ingroup diag_ipu
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ipu_common.h"
#include "ips_test.h"

/*!
 * LVDS display test case. note that the memory for the flow is not released
 *
 * @param	panel:		ipu panel configuration data structure
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

/*!
 * HDMI 1080P60 display stream
 *
 * @param	ipu_index:	ipu index
 */
int ips_hdmi_1080P60_stream(int ipu_index)
{
    ips_dev_panel_t *panel;

    /*enable panel */
    panel = search_panel("HDMI 1080P 60Hz");
    panel->panel_init();

    /*reset IPU */
    ipu_sw_reset(ipu_index, 1000);

    /*setup IPU display channel */
    ipu_display_setup(ipu_index, panel, PARTIAL_INTERLEAVED_YUV420, YUV_RGB);
    memset((void *)CH23_EBA0, 0x10, panel->width * panel->height);
    memset((void *)CH23_EBA0 + panel->width * FRAME_MAX_HEIGHT, 0x80,
           panel->width * panel->height / 2);
    memset((void *)CH23_EBA1, 0x10, panel->width * panel->height);
    memset((void *)CH23_EBA1 + panel->width * FRAME_MAX_HEIGHT, 0x80,
           panel->width * panel->height / 2);

    /*realloc the DMFC fifo */
    ipu_dmfc_alloc(ipu_index, 23, DMFC_FIFO_512X128, 0, DMFC_BURST_32X128);
    ipu_cpmem_mod_field(ipu_cpmem_addr(ipu_index, 23), NON_INTERLEAVED_NPB, 63);

    /*enable ipu display channel */
    ipu_enable_display(ipu_index);

    return 1;
}

/*!
 * SII9022 1080P60 display stream
 * @param	ipu_index:	ipu index
 */
int ips_sii9022_1080P60_stream(int ipu_index)
{
    ips_dev_panel_t *panel;

    /*enable panel */
    panel = search_panel("SII9022 1080P 60Hz");
    panel->panel_init();

    /*reset IPU */
    ipu_sw_reset(ipu_index, 1000);

    /*setup IPU display channel */
    ipu_display_setup(ipu_index, panel, PARTIAL_INTERLEAVED_YUV420, YUV_RGB);

    /*realloc the DMFC fifo */
    ipu_dmfc_alloc(ipu_index, 23, DMFC_FIFO_512X128, 0, DMFC_BURST_32X128);
    ipu_cpmem_mod_field(ipu_cpmem_addr(ipu_index, 23), NON_INTERLEAVED_NPB, 63);

    /*enable ipu display channel */
    ipu_enable_display(ipu_index);

    return 1;
}
