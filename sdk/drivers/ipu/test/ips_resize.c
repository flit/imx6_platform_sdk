/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_resize.c
 * @brief IPU resize test.
 * @ingroup diag_ipu
 */

#include <string.h>
#include <stdio.h>

#include "ips_test.h"

int32_t ips_resize_test(ips_dev_panel_t * panel)
{
    uint32_t ipu_index = 1;     // use ipu 1
    uint32_t taskType = PP_TASK;
    uint32_t rot_in_mem = CH28_EBA0, rot_out_mem = CH27_EBA0, res_out_mem = CH23_EBA0;
    ipu_rot_info_t rot_info;
    ipu_res_info_t res_info;
    uint32_t rot_chnl_in, rot_chnl_out, res_chnl_in, res_chnl_out;
    uint32_t flag = 0;
    uint8_t revchar;

    /*Rotation Test. Press y to rotate 90 degree. */
    printf("\n-- Resize rotated image to fit the screen --\n");
    printf("Press 'Y'/'y' for 90 degree clockwise rotation. \nOther key to exit.)\n");

    /*reset IPU */
    ipu_sw_reset(ipu_index, 1000);

    /*setup IPU display channel */
    ipu_display_setup(ipu_index, res_out_mem, (uint32_t) NULL, INTERLEAVED_RGB, panel);

    /*enable ipu display channel */
    ipu_enable_display(ipu_index);

    /*load image */
//  load_centralized_image(CH23_EBA0, panel);

    /*setup ic task and dma channel for resize. */
    switch (taskType) {
    case PrP_VF_TASK:
        res_chnl_in = MEM_TO_IC_PRP_RES_CH12;
        res_chnl_out = IC_PRPVF_RES_TO_MEM_CH21;
        rot_chnl_in = MEM_TO_IC_PRPVF_ROT_CH46;
        rot_chnl_out = IC_PRPVF_ROT_TO_MEM_CH49;
        break;
    case PP_TASK:
        res_chnl_in = MEM_TO_IC_PP_RES_CH11;
        res_chnl_out = IC_PP_RES_TO_MEM_CH22;
        rot_chnl_in = MEM_TO_IC_PP_ROT_CH47;
        rot_chnl_out = IC_PP_ROT_TO_MEM_CH50;
        break;
    default:
        printf("Wrong IC processing task.\n");
    }

    while (1) {
        do {
            revchar = getchar();
        } while (revchar == (uint8_t) 0xFF);
        if (revchar == 'Y' || revchar == 'y') {
            if (flag == 0) {
                //odd frame: 1024 * 768 -- 768 * 1024 --  576 * 768
                //1 read data from CH28_EBA0 and rotate it, store result to CH27_EBA0
                //2 read rotated data from CH27_EBA0 and resize it, store result to CH23_EBA0 which is for display channel.
                memcpy((void *)rot_in_mem, (void *)res_out_mem, panel->width * panel->height * 2);
                //set rotate idma
                memset(&rot_info, 0x00, sizeof(ipu_rot_info_t));
                rot_info.width_in = panel->width;
                rot_info.height_in = panel->height;
                rot_info.width_out = rot_info.height_in;
                rot_info.height_out = rot_info.width_in;
                rot_info.strideline_in = rot_info.width_in * 2 - 1;
                rot_info.strideline_out = rot_info.width_out * 2 - 1;
                rot_info.pixel_format_in = INTERLEAVED_RGB;
                rot_info.pixel_format_out = INTERLEAVED_RGB;
                rot_info.rot = 1;
                rot_info.hf = 0;
                rot_info.vf = 0;
                rot_info.addr0_in = rot_in_mem;
                rot_info.addr0_out = rot_out_mem;
                ipu_rotate_idmac_config(ipu_index, rot_chnl_in, rot_chnl_out, rot_info);

                //set resize idma
                memset(&res_info, 0x00, sizeof(ipu_rot_info_t));
                res_info.width_in = rot_info.width_out;
                res_info.height_in = rot_info.height_out;
                res_info.height_out = panel->height;
                res_info.width_out = res_info.height_out * res_info.width_in / res_info.height_in;
                res_info.strideline_in = res_info.width_in * 2 - 1;
                res_info.strideline_out = panel->width * 2 - 1;
                res_info.pixel_format_in = INTERLEAVED_RGB;
                res_info.pixel_format_out = INTERLEAVED_RGB;
                res_info.addr0_in = rot_out_mem;
                res_info.addr0_out =
                    res_out_mem + (panel->height - res_info.height_out) * panel->width +
                    panel->width - res_info.width_out;

                ipu_resize_idmac_config(ipu_index, res_chnl_in, res_chnl_out, res_info);

                //set ic task
                ipu_ic_enable(ipu_index, 0, 0);
                ipu_ic_rotation_config(ipu_index, taskType, 1, 0, 0);
                ipu_ic_resize_config(ipu_index, taskType, res_info);

                //enable ic task
                ipu_ic_task_enable(ipu_index, PP_TASK, IC_PP, 1);
                ipu_ic_task_enable(ipu_index, PP_TASK, IC_ROT, 1);
                ipu_ic_enable(ipu_index, 1, 1);

                //enable rotate idma channel
                ipu_channel_buf_ready(ipu_index, rot_chnl_out, 0);
                ipu_channel_buf_ready(ipu_index, rot_chnl_in, 0);
                while (ipu_idmac_channel_busy(1, rot_chnl_in)) ;
                while (ipu_idmac_channel_busy(1, rot_chnl_out)) ;

                //enable resize idma channel
                ipu_channel_buf_ready(ipu_index, res_chnl_out, 0);
                ipu_channel_buf_ready(ipu_index, res_chnl_in, 0);
                while (ipu_idmac_channel_busy(1, res_chnl_in)) ;
                while (ipu_idmac_channel_busy(1, res_chnl_out)) ;
                set_background_margin(panel, res_info.width_out, res_info.height_out);
            } else {
                //even frame: 768 * 1024 (rotated result of last frame) -- 1024 * 768
                //read data from CH27_EBA0 and rotate it, store result to CH23_EBA0 for display
                //set rotate idma 
                memset(&rot_info, 0x00, sizeof(ipu_rot_info_t));
                rot_info.width_in = panel->height;
                rot_info.height_in = panel->width;
                rot_info.width_out = rot_info.height_in;
                rot_info.height_out = rot_info.width_in;
                rot_info.strideline_in = rot_info.width_in * 2 - 1;
                rot_info.strideline_out = rot_info.width_out * 2 - 1;
                rot_info.pixel_format_in = INTERLEAVED_RGB;
                rot_info.pixel_format_out = INTERLEAVED_RGB;
                rot_info.rot = 1;
                rot_info.hf = 0;
                rot_info.vf = 0;
                rot_info.addr0_in = rot_out_mem;
                rot_info.addr0_out = res_out_mem;
                ipu_rotate_idmac_config(ipu_index, rot_chnl_in, rot_chnl_out, rot_info);

                //set ic task
                ipu_ic_enable(ipu_index, 0, 0);
                ipu_ic_rotation_config(ipu_index, taskType, 1, 0, 0);

                //enable ic task
                ipu_ic_task_enable(ipu_index, PP_TASK, IC_PP, 1);
                ipu_ic_task_enable(ipu_index, PP_TASK, IC_ROT, 1);
                ipu_ic_enable(ipu_index, 1, 1);

                //enable rotate idma
                ipu_channel_buf_ready(ipu_index, rot_chnl_out, 0);
                ipu_channel_buf_ready(ipu_index, rot_chnl_in, 0);
                while (ipu_idmac_channel_busy(1, rot_chnl_in)) ;
                while (ipu_idmac_channel_busy(1, rot_chnl_out)) ;
            }
            //set flag for next frame.
            flag = (flag + 1) % 2;
        } else
            break;
    };

    return TRUE;
}
