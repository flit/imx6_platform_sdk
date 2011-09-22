/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <string.h>
#include <stdio.h>

#include "ips.h"
#include "ipu_common.h"
#include "ips_test.h"

/*!
 * LVDS display test case. note that the memory for the flow is not released
 */
int ips_display_test(void)
{
    uint8_t revchar;
    ips_device_t *mem, *ipu, *disp;
    ips_ims_t *ims;
    ips_pad_t *srcpad;
    ips_flow_t *flow;
    ips_bin_t *bin;

    // create memory and define video output data
    disp = ips_new_device(IPS_DEV_DISPLAY, "HannStar XGA LVDS");
    mem = ips_new_device(IPS_DEV_MEM, "memory");
    ipu = ips_new_device(IPS_DEV_IPU, "ipu");

    ims = ips_new_ims();
    ips_set_ims(ims, OFFSETOF(ips_ims_t, width), 1024, EOP);
    ips_set_ims(ims, OFFSETOF(ips_ims_t, height), 768, EOP);
    srcpad = ips_device_get_src_pad(mem, "output");
    ips_set_pad_ims(srcpad, ims);

    bin = ips_new_bin("display bin");
    ips_bin_add_device_many(bin, mem, ipu, disp, NULL);
    ips_device_add_sink_pad(ipu, "common");
    ips_link_device_many(mem, "output", "common", ipu, "di0", "interface", disp, NULL);

    flow = ips_new_flow(IPU1_DP_DISP0, "di0 display", bin);
    load_centralized_image(flow);
    stream_on(flow);

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
 */
int ips_hdmi_stream(void)
{
    uint8_t revchar;
    ips_device_t *mem, *ipu, *disp;
    ips_ims_t *ims;
    ips_pad_t *srcpad;
    ips_flow_t *flow;
    ips_bin_t *bin;

    // create memory and define video output data
    disp = ips_new_device(IPS_DEV_DISPLAY, "HDMI 1080P 60Hz");
    mem = ips_new_device(IPS_DEV_MEM, "memory");
    ipu = ips_new_device(IPS_DEV_IPU, "ipu");

    ims = ips_new_ims();
    ips_set_ims(ims, OFFSETOF(ips_ims_t, width), 1920, EOP);
    ips_set_ims(ims, OFFSETOF(ips_ims_t, height), 1080, EOP);
    srcpad = ips_device_get_src_pad(mem, "output");
    ips_set_pad_ims(srcpad, ims);

    bin = ips_new_bin("display bin");
    ips_bin_add_device_many(bin, mem, ipu, disp, NULL);
    ips_device_add_sink_pad(ipu, "common");
    ips_link_device_many(mem, "output", "common", ipu, "di0", "interface", disp, NULL);

    flow = ips_new_flow(IPU1_DP_DISP0, "di0 display", bin);
    load_centralized_image(flow);
    stream_on(flow);

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
