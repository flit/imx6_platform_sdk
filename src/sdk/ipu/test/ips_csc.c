/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_csc.c
 * @brief IPU color space conversion test.
 * @ingroup diag_ipu
 */

#include <string.h>
#include <stdio.h>

#include "ipu_common.h"
#include "ips_test.h"

int ips_csc_test(ips_dev_panel_t * panel)
{
    uint32_t ipu_index = 1;     // use ipu 1
    uint32_t channel_in, channel_out;
    ipu_res_info_t res_info;
    ic_csc_params_t csc_params;
    uint32_t taskType = PP_TASK;
    uint8_t revchar;

    printf("\n-- Color Space Conversion Example ---\n");
    /*step 1: setup IPU display channel */
    /*reset IPU */
    ipu_sw_reset(ipu_index, 1000);

    /*setup IPU dual display channel, enable partial plane */
    ipu_display_setup(ipu_index, panel, INTERLEAVED_RGB, NO_CSC);

    /*enable ipu display channel */
    ipu_enable_display(ipu_index);

    /*load foreground image */
    load_horiz_image(CH23_EBA0, panel->width, panel->height);

    printf("RGB image -- Do you want to change it to YUV format (y or n)?\n");
    do {
        revchar = getchar();
    } while (revchar == (uint8_t) 0xFF);
    if (!(revchar == 'Y' || revchar == 'y'))
        return FALSE;

    /*step 2: change RGB565 to YUV420 through IC main processing section.
       IC CSC task takes after the resize work. */
    /*setup ic task and dma channel for RGB -- YUV. */
    switch (taskType) {
    case PrP_VF_TASK:
        channel_in = MEM_TO_IC_PRP_RES_CH12;
        channel_out = IC_PRPVF_RES_TO_MEM_CH21;
        break;
    case PP_TASK:
        channel_in = MEM_TO_IC_PP_RES_CH11;
        channel_out = IC_PP_RES_TO_MEM_CH22;
        break;
    default:
        printf("Wrong IC processing task.\n");
        return FALSE;
    }
    /*setup ic main processing task channel for CSC */
    memset(&res_info, 0x00, sizeof(ipu_res_info_t));
    res_info.addr0_in = CH23_EBA0;
    res_info.pixel_format_in = INTERLEAVED_RGB;
    res_info.width_in = panel->width;
    res_info.height_in = panel->height;
    res_info.strideline_in = 2 * res_info.width_in - 1;
    res_info.addr0_out = CH27_EBA0;
    res_info.pixel_format_out = NON_INTERLEAVED_YUV420;
    res_info.width_out = res_info.width_in;
    res_info.height_out = res_info.height_in;
    res_info.strideline_out = res_info.width_out - 1;
    res_info.u_offset_out = res_info.width_out * res_info.height_out;
    ipu_resize_idmac_config(ipu_index, channel_in, channel_out, res_info);

    /*setpup ic main processing task for resize and CSC */
    ipu_ic_enable(ipu_index, 0, 0);
    memset(&csc_params, 0x00, sizeof(ic_csc_params_t));
    csc_params.taskType = PP_TASK;
    csc_params.inFormat = RGB;
    csc_params.outFormat = YUV;
    ipu_ic_resize_config(ipu_index, PP_TASK, res_info);
    ipu_ic_csc_config(ipu_index, 1, csc_params);

    /*enable IC task. */
    ipu_ic_task_enable(ipu_index, PP_TASK, IC_PP, 1);
    ipu_ic_enable(ipu_index, 1, 0);

    ipu_channel_buf_ready(1, channel_out, 0);
    ipu_channel_buf_ready(1, channel_in, 0);
    while (ipu_idmac_channel_busy(1, channel_in)) ;
    while (ipu_idmac_channel_busy(1, channel_out)) ;

    ipu_idmac_channel_enable(ipu_index, channel_in, 0);
    ipu_idmac_channel_enable(ipu_index, channel_out, 0);

    //ipu_display_setup(ipu_index, panel, NON_INTERLEAVED_YUV420, NON_CSC);
    memset((void *)CH23_EBA0, 0x00, panel->width * panel->height * 2);
    memcpy((void *)CH23_EBA0, (void *)CH27_EBA0, panel->width * panel->height * 3 / 2);

    /*setup display channel for YUV420. */
    printf("----- The YUV format displays on RGB screen -----\n");
    printf("Do you want to change it back to RGB?....\n");
    do {
        revchar = getchar();
    } while (revchar == (uint8_t) 0xFF);
    if (!(revchar == 'Y' || revchar == 'y'))
        return FALSE;

    /*step 3: change YUV to RGB through DP module directly to screen.*/
    //setting display idmac channel and CSC on DP module.
    ipu_sw_reset(ipu_index, 1000);
    ipu_display_setup(ipu_index, panel, NON_INTERLEAVED_YUV420, YUV_RGB);
    ipu_enable_display(ipu_index);

    return TRUE;
}
