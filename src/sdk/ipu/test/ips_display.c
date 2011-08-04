/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <string.h>
#include <stdio.h>

#include "ips.h"
#include "ips_test.h"

int ips_display_test(void)
{
    ips_device_t *mem;
    ips_dev_memory_t *memattr;
    ips_image_stream_t *ims;
    ips_pad_t *sinkpad;
    ips_dev_display_t *disp;
    ips_flow_t *flow;

    // create memory and define video output data
    mem = ips_new_device(IPS_DEV_MEM);
    memattr = (ips_dev_memory_t *) (mem->devattr);
    ims = memattr->create_ims(23);
    ips_set_ims(ims, OFFSETOF(ips_image_stream_t, width), 1024, EOP);
    ips_set_ims(ims, OFFSETOF(ips_image_stream_t, height), 768, EOP);
    sinkpad = ips_device_get_sink_pad(mem);
    ips_set_pad_ims(sinkpad, ims);

    disp = ips_new_device(IPS_DEV_DISPLAY);
    flow = ips_link_device(mem, disp);

    return true;
}
