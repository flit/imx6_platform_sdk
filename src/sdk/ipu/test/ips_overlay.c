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

int ips_overlay_test(void)
{
    // create IPU object
    my_ipu = ips_new_ipu();

    // create display
    disp1 = ips_new_display(a1, b1);

    // define require UI output
    out_bg = disp1.ips_new_ims();
    out_bg.ips_set_size(x_bg_out, y_bg_out);
    out_bg.ips_set_position(X_bg, Y_bg);
    out_bg.ips_set_transparency(alpha_bg);
    out_bg.ips_set_layer(0);

    // define require video output
    out_video_fg = disp1.ips_new_ims();
    out_video_fg.ips_set_size(x_fg_out, y_fg_out);
    out_video_fg.ips_set_position(X_fg, Y_fg);
    out_video_fg.ips_set_transparency(alpha_fg);
    out_video_fg.ips_set_layer(1);

    // create memory and define UI input data
    mem1 = ips_new_mem(a2, b2);
    in_bg = mem1.ips_new_ims();
    in_bg.ips_set_size(x_bg_in, y_bg_in);
    in_bg.ips_set_format(rgb888);

    // create memory and define video input data
    mem2 = ips_new_mem(a3, b3);
    in_video_fg = mem2.ips_new_ims();
    in_video_fg.ips_set_size(x_fg_in, y_fg_in);
    in_video_fg.ips_set_format(yuv422);

    //Start streaming of UI and Video Playback
    my_ipu.streamon(out_bg, in_bg);
    my_ipu.streamon(out_video_fg, in_video_fg);

    return TRUE;
}
