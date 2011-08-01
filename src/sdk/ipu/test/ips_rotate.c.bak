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

int ips_rotate_test(void)
{
    // create IPU object
    my_ipu = ips_new_ipu();
    // create memory and define video output data
    mem = ips_new_mem(a1, b1);
    out_video = mem.ips_new_ims();
    out_video.ips_set_format(yuv422);
    out_video.ips_set_size(x1, y2);
    // using same memory device define video input data
    in_video = mem.ips_new_ims();
    in_video.ips_set_size(x2, y2);
    in_video.ips_set_format(yuv422);
    //Start streaming
    my_ipu.streamon(out_video, in_video);
    return TRUE;
}
