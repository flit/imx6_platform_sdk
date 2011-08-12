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

int ips_display_test(void)
{
    ips_device_t *mem, *ipu, *disp, *superdev;
    ips_image_stream_t *ims;
    ips_pad_t *srcpad;
    ips_flow_t *flow;

    // create memory and define video output data
    disp = ips_new_device(IPS_DEV_DISPLAY, "display");
    mem = ips_new_device(IPS_DEV_MEM, "memory");
    ipu = ips_new_device(IPS_DEV_IPU, "ipu");

    ims = ((ips_dev_memory_t *) mem->devattr)->create_ims(MEM_TO_DP_BG_CH23);
    ips_set_ims(ims, OFFSETOF(ips_image_stream_t, width), 1024, EOP);
    ips_set_ims(ims, OFFSETOF(ips_image_stream_t, height), 768, EOP);
    srcpad = ips_device_get_src_pad(mem, "output");
    ips_set_pad_ims(srcpad, ims);

    superdev = ips_link_device_many(mem, "output", "dpin", ipu, "di0", "interface", disp, NULL);

    flow = ips_new_flow(IPU1_DP_DISP0, superdev);
    ips_flow_add_device_many(flow, mem, ipu, disp);

    stream_on();
    return true;
}
