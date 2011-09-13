/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "hardware.h"
#include "hdmi_tx.h"

extern int ips_hdmi_stream(void);

void hdmi_test(void){
  
    printf("\n---- Running HDMI test ----\n");
    
    hdmi_data_info_s myHDMI_info = { 0 };  // declare new hdmi module object instance
    hdmi_vmode_s myHDMI_vmode_info = { 0 };  // declare new hdmi module object instance
    myHDMI_info.video_mode = &myHDMI_vmode_info;
    
    myHDMI_info.enc_in_format = eRGB;
    myHDMI_info.enc_out_format = eRGB;
    myHDMI_info.enc_color_depth = 8;
    myHDMI_info.colorimetry = eITU601;
    myHDMI_info.pix_repet_factor = 0;
    myHDMI_info.hdcp_enable = 0;
//    myHDMI_info.video_mode->mCode = 4;  //1280x720p @ 59.94/60Hz 16:9
    myHDMI_info.video_mode->mCode = 16;  //1920x1080p @ 59.94/60Hz 16:9
    myHDMI_info.video_mode->mHdmiDviSel = TRUE;
    myHDMI_info.video_mode->mRVBlankInOSC = FALSE;
    myHDMI_info.video_mode->mRefreshRate = 60000;
    myHDMI_info.video_mode->mDataEnablePolarity = TRUE;
    
    //hdmi_config_forced_pixels(82, 151, 7); // set to a forest greenish color
    //hdmi_config_force_video(TRUE);
    
    hdmi_av_frame_composer(&myHDMI_info);
    hdmi_video_packetize(myHDMI_info);
    hdmi_video_csc(myHDMI_info);
    hdmi_video_sample(myHDMI_info);
    
    hdmi_audio_mute(TRUE);
    hdmi_tx_hdcp_config(myHDMI_info.video_mode->mDataEnablePolarity);
    
    hdmi_phy_init(TRUE, myHDMI_info.video_mode->mPixelClock);
    
    hdmi_config_input_source(IPU1_DI0); // configure input source to HDMI block
    
 
    // configure IPU to output stream for hdmi input
    if(ips_hdmi_stream()){ // set up ipu1 disp0  1080P60 display stream 
        printf("HDMI test PASS\n");
    }
    else{
        printf("HDMI test FAIL\n");    
    }
}
