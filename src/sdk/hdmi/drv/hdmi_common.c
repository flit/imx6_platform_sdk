/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file hdmi_common.c
 */
#include <stdio.h>
#include "hardware.h"
#include "hdmi_tx.h"

/*! ------------------------------------------------------------
 * HDMI TX common Functions
 *  ------------------------------------------------------------
 */

/*!
 * write bit fields of hdmi internal regiters
 *
 * @param  	data:	written value of the bit fields
 * @param  	addr:	address of the register
 * @param  	shift:	lsb offset of the bit-field
 * @param  	width:	width of the bit-field
 */
void writebf(uint8_t data, uint32_t addr, uint8_t shift, uint8_t width)
{
    uint8_t temp = 0;
    uint8_t mask = (1 << width) - 1;
    if (data > mask) {
        printf("Invalid parameter for %s\n", __FUNCTION__);
        return;
    }

    temp = readb(addr);
    temp &= ~(mask << shift);
    temp |= (data & mask) << shift;
    writeb(temp, addr);
}

int isColorSpaceConversion(hdmi_data_info_s hdmi_instance)
{
    return (hdmi_instance.enc_in_format != hdmi_instance.enc_out_format) ? TRUE : FALSE;
}

int isColorSpaceDecimation(hdmi_data_info_s hdmi_instance)
{
    return (hdmi_instance.enc_in_format != hdmi_instance.enc_out_format) ? TRUE : FALSE;
}

int isColorSpaceInterpolation(hdmi_data_info_s hdmi_instance)
{
    return ((hdmi_instance.enc_in_format == eYCC422) &&
            (hdmi_instance.enc_out_format == eRGB
             || hdmi_instance.enc_out_format == eYCC444)) ? TRUE : FALSE;
}

int isPixelRepetition(hdmi_data_info_s hdmi_instance)
{
    return (hdmi_instance.pix_repet_factor > 0) ? TRUE : FALSE;
}

/*!
 * this submodule is responsible for the video/audio data composition.
 *
 * @param	vmode:	video mode parameters
 */
void hdmi_set_video_mode(hdmi_vmode_s * vmode)
{
    vmode->mHBorder = 0;
    vmode->mVBorder = 0;
    vmode->mPixelRepetitionInput = 0;
    vmode->mHImageSize = 16;
    vmode->mVImageSize = 9;

    switch (vmode->mCode) {
    case 1:                    //640x480p @ 59.94/60Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
        vmode->mHActive = 640;
        vmode->mVActive = 480;
        vmode->mHBlanking = 160;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 16;
        vmode->mVSyncOffset = 10;
        vmode->mHSyncPulseWidth = 96;
        vmode->mVSyncPulseWidth = 2;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE; // not(progressive_nI)
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 2517 : 2520;
        break;
    case 2:                    //720x480p @ 59.94/60Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 3:                    //720x480p @ 59.94/60Hz 16:9
        vmode->mHActive = 720;
        vmode->mVActive = 480;
        vmode->mHBlanking = 138;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 16;
        vmode->mVSyncOffset = 9;
        vmode->mHSyncPulseWidth = 62;
        vmode->mVSyncPulseWidth = 6;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 2700 : 2702;
        break;
    case 4:                    //1280x720p @ 59.94/60Hz 16:9
        vmode->mHActive = 1280;
        vmode->mVActive = 720;
        vmode->mHBlanking = 370;
        vmode->mVBlanking = 30;
        vmode->mHSyncOffset = 110;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 40;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 7417 : 7425;
        break;
    case 5:                    //1920x1080i @ 59.94/60Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 540;
        vmode->mHBlanking = 280;
        vmode->mVBlanking = 22;
        vmode->mHSyncOffset = 88;
        vmode->mVSyncOffset = 2;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 7417 : 7425;
        break;
    case 6:                    //720(1440)x480i @ 59.94/60Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 7:                    //720(1440)x480i @ 59.94/60Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 240;
        vmode->mHBlanking = 276;
        vmode->mVBlanking = 22;
        vmode->mHSyncOffset = 38;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 124;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 2700 : 2702;
        vmode->mPixelRepetitionInput = 1;
        break;
    case 8:                    //720(1440)x240p @ 59.826/60.054/59.886/60.115Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 9:                    //720(1440)x240p @ 59.826/60.054/59.886/60.115Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 240;
        vmode->mHBlanking = 276;
        vmode->mVBlanking = (vmode->mRefreshRate > 60000) ? 22 : 23;
        vmode->mHSyncOffset = 38;
        vmode->mVSyncOffset = (vmode->mRefreshRate > 60000) ? 4 : 5;
        vmode->mHSyncPulseWidth = 124;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = ((vmode->mRefreshRate == 60054) || vmode->mRefreshRate == 59826) ? 2700 : 2702;    // else 60.115/59.886 Hz
        vmode->mPixelRepetitionInput = 1;
        break;
    case 10:                   //2880x480i @ 59.94/60Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 11:                   //2880x480i @ 59.94/60Hz 16:9
        vmode->mHActive = 2880;
        vmode->mVActive = 240;
        vmode->mHBlanking = 552;
        vmode->mVBlanking = 22;
        vmode->mHSyncOffset = 76;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 248;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 5400 : 5405;
        break;
    case 12:                   //2880x240p @ 59.826/60.054/59.886/60.115Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 13:                   //2880x240p @ 59.826/60.054/59.886/60.115Hz 16:9
        vmode->mHActive = 2880;
        vmode->mVActive = 240;
        vmode->mHBlanking = 552;
        vmode->mVBlanking = (vmode->mRefreshRate > 60000) ? 22 : 23;
        vmode->mHSyncOffset = 76;
        vmode->mVSyncOffset = (vmode->mRefreshRate > 60000) ? 4 : 5;
        vmode->mHSyncPulseWidth = 248;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = ((vmode->mRefreshRate == 60054) || vmode->mRefreshRate == 59826) ? 5400 : 5405;    // else 60.115/59.886 Hz
        break;
    case 14:                   //1440x480p @ 59.94/60Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 15:                   //1440x480p @ 59.94/60Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 480;
        vmode->mHBlanking = 276;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 32;
        vmode->mVSyncOffset = 9;
        vmode->mHSyncPulseWidth = 124;
        vmode->mVSyncPulseWidth = 6;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 5400 : 5405;
        break;
    case 16:                   //1920x1080p @ 59.94/60Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 1080;
        vmode->mHBlanking = 280;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 88;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 14835 : 14850;
        break;
    case 17:                   //720x576p @ 50Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 18:                   //720x576p @ 50Hz 16:9
        vmode->mHActive = 720;
        vmode->mVActive = 576;
        vmode->mHBlanking = 144;
        vmode->mVBlanking = 49;
        vmode->mHSyncOffset = 12;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 64;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 2700;
        break;
    case 19:                   //1280x720p @ 50Hz 16:9
        vmode->mHActive = 1280;
        vmode->mVActive = 720;
        vmode->mHBlanking = 700;
        vmode->mVBlanking = 30;
        vmode->mHSyncOffset = 440;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 40;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 7425;
        break;
    case 20:                   //1920x1080i @ 50Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 540;
        vmode->mHBlanking = 720;
        vmode->mVBlanking = 22;
        vmode->mHSyncOffset = 528;
        vmode->mVSyncOffset = 2;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = 7425;
        break;
    case 21:                   //720(1440)x576i @ 50Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 22:                   //720(1440)x576i @ 50Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 288;
        vmode->mHBlanking = 288;
        vmode->mVBlanking = 24;
        vmode->mHSyncOffset = 24;
        vmode->mVSyncOffset = 2;
        vmode->mHSyncPulseWidth = 126;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = 2700;
        vmode->mPixelRepetitionInput = 1;
        break;
    case 23:                   //720(1440)x288p @ 50Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 24:                   //720(1440)x288p @ 50Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 288;
        vmode->mHBlanking = 288;
        vmode->mVBlanking =
            (vmode->mRefreshRate == 50080) ? 24 : ((vmode->mRefreshRate == 49920) ? 25 : 26);
        vmode->mHSyncOffset = 24;
        vmode->mVSyncOffset =
            (vmode->mRefreshRate == 50080) ? 2 : ((vmode->mRefreshRate == 49920) ? 3 : 4);
        vmode->mHSyncPulseWidth = 126;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 2700;
        vmode->mPixelRepetitionInput = 1;
        break;
    case 25:                   //2880x576i @ 50Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 26:                   //2880x576i @ 50Hz 16:9
        vmode->mHActive = 2880;
        vmode->mVActive = 288;
        vmode->mHBlanking = 576;
        vmode->mVBlanking = 24;
        vmode->mHSyncOffset = 48;
        vmode->mVSyncOffset = 2;
        vmode->mHSyncPulseWidth = 252;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = 5400;
        break;
    case 27:                   //2880x288p @ 50Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 28:                   //2880x288p @ 50Hz 16:9
        vmode->mHActive = 2880;
        vmode->mVActive = 288;
        vmode->mHBlanking = 576;
        vmode->mVBlanking =
            (vmode->mRefreshRate == 50080) ? 24 : ((vmode->mRefreshRate == 49920) ? 25 : 26);
        vmode->mHSyncOffset = 48;
        vmode->mVSyncOffset =
            (vmode->mRefreshRate == 50080) ? 2 : ((vmode->mRefreshRate == 49920) ? 3 : 4);
        vmode->mHSyncPulseWidth = 252;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 5400;
        break;
    case 29:                   //1440x576p @ 50Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 30:                   //1440x576p @ 50Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 576;
        vmode->mHBlanking = 288;
        vmode->mVBlanking = 49;
        vmode->mHSyncOffset = 24;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 128;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 5400;
        break;
    case 31:                   //1920x1080p @ 50Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 1080;
        vmode->mHBlanking = 720;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 528;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 14850;
        break;
    case 32:                   //1920x1080p @ 23.976/24Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 1080;
        vmode->mHBlanking = 830;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 638;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 23976) ? 7417 : 7425;
        break;
    case 33:                   //1920x1080p @ 25Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 1080;
        vmode->mHBlanking = 720;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 528;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 7425;
        break;
    case 34:                   //1920x1080p @ 29.97/30Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 1080;
        vmode->mHBlanking = 280;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 88;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 29970) ? 7417 : 7425;
        break;
    case 35:                   //2880x480p @ 60Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 36:                   //2880x480p @ 60Hz 16:9
        vmode->mHActive = 2880;
        vmode->mVActive = 480;
        vmode->mHBlanking = 552;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 64;
        vmode->mVSyncOffset = 9;
        vmode->mHSyncPulseWidth = 248;
        vmode->mVSyncPulseWidth = 6;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 59940) ? 10800 : 10810;
        break;
    case 37:                   //2880x576p @ 50Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 38:                   //2880x576p @ 50Hz 16:9
        vmode->mHActive = 2880;
        vmode->mVActive = 576;
        vmode->mHBlanking = 576;
        vmode->mVBlanking = 49;
        vmode->mHSyncOffset = 48;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 256;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 10800;
        break;
    case 39:                   //1920x1080i (1250 total) @ 50Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 540;
        vmode->mHBlanking = 384;
        vmode->mVBlanking = 85;
        vmode->mHSyncOffset = 32;
        vmode->mVSyncOffset = 23;
        vmode->mHSyncPulseWidth = 168;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = 7200;
        break;
    case 40:                   //1920x1080i @ 100Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 540;
        vmode->mHBlanking = 720;
        vmode->mVBlanking = 22;
        vmode->mHSyncOffset = 528;
        vmode->mVSyncOffset = 2;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = 14850;
        break;
    case 41:                   //1280x720p @ 100Hz 16:9
        vmode->mHActive = 1280;
        vmode->mVActive = 720;
        vmode->mHBlanking = 700;
        vmode->mVBlanking = 30;
        vmode->mHSyncOffset = 440;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 40;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 14850;
        break;
    case 42:                   //720x576p @ 100Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 43:                   //720x576p @ 100Hz 16:9
        vmode->mHActive = 720;
        vmode->mVActive = 576;
        vmode->mHBlanking = 144;
        vmode->mVBlanking = 49;
        vmode->mHSyncOffset = 12;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 64;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 5400;
        break;
    case 44:                   //720(1440)x576i @ 100Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 45:                   //720(1440)x576i @ 100Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 288;
        vmode->mHBlanking = 288;
        vmode->mVBlanking = 24;
        vmode->mHSyncOffset = 24;
        vmode->mVSyncOffset = 2;
        vmode->mHSyncPulseWidth = 126;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = 5400;
        vmode->mPixelRepetitionInput = 1;
        break;
    case 46:                   //1920x1080i @ 119.88/120Hz 16:9
        vmode->mHActive = 1920;
        vmode->mVActive = 540;
        vmode->mHBlanking = 288;
        vmode->mVBlanking = 22;
        vmode->mHSyncOffset = 88;
        vmode->mVSyncOffset = 2;
        vmode->mHSyncPulseWidth = 44;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = (vmode->mRefreshRate == 119880) ? 14835 : 14850;
        break;
    case 47:                   //1280x720p @ 119.88/120Hz 16:9
        vmode->mHActive = 1280;
        vmode->mVActive = 720;
        vmode->mHBlanking = 370;
        vmode->mVBlanking = 30;
        vmode->mHSyncOffset = 110;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 40;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = TRUE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 119880) ? 14835 : 14850;
        break;
    case 48:                   //720x480p @ 119.88/120Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 49:                   //720x480p @ 119.88/120Hz 16:9
        vmode->mHActive = 720;
        vmode->mVActive = 480;
        vmode->mHBlanking = 138;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 16;
        vmode->mVSyncOffset = 9;
        vmode->mHSyncPulseWidth = 62;
        vmode->mVSyncPulseWidth = 6;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 119880) ? 5400 : 5405;
        break;
    case 50:                   //720(1440)x480i @ 119.88/120Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 51:                   //720(1440)x480i @ 119.88/120Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 240;
        vmode->mHBlanking = 276;
        vmode->mVBlanking = 22;
        vmode->mHSyncOffset = 38;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 124;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = (vmode->mRefreshRate == 119880) ? 5400 : 5405;
        vmode->mPixelRepetitionInput = 1;
        break;
    case 52:                   //720X576p @ 200Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 53:                   //720X576p @ 200Hz 16:9
        vmode->mHActive = 720;
        vmode->mVActive = 576;
        vmode->mHBlanking = 144;
        vmode->mVBlanking = 49;
        vmode->mHSyncOffset = 12;
        vmode->mVSyncOffset = 5;
        vmode->mHSyncPulseWidth = 64;
        vmode->mVSyncPulseWidth = 5;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = 10800;
        break;
    case 54:                   //720(1440)x576i @ 200Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 55:                   //720(1440)x576i @ 200Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 288;
        vmode->mHBlanking = 288;
        vmode->mVBlanking = 24;
        vmode->mHSyncOffset = 24;
        vmode->mVSyncOffset = 2;
        vmode->mHSyncPulseWidth = 126;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = 10800;
        vmode->mPixelRepetitionInput = 1;
        break;
    case 56:                   //720x480p @ 239.76/240Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 57:                   //720x480p @ 239.76/240Hz 16:9
        vmode->mHActive = 720;
        vmode->mVActive = 480;
        vmode->mHBlanking = 138;
        vmode->mVBlanking = 45;
        vmode->mHSyncOffset = 16;
        vmode->mVSyncOffset = 9;
        vmode->mHSyncPulseWidth = 62;
        vmode->mVSyncPulseWidth = 6;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = FALSE;
        vmode->mPixelClock = (vmode->mRefreshRate == 239760) ? 10800 : 10810;
        break;
    case 58:                   //720(1440)x480i @ 239.76/240Hz 4:3
        vmode->mHImageSize = 4;
        vmode->mVImageSize = 3;
    case 59:                   //720(1440)x480i @ 239.76/240Hz 16:9
        vmode->mHActive = 1440;
        vmode->mVActive = 240;
        vmode->mHBlanking = 276;
        vmode->mVBlanking = 22;
        vmode->mHSyncOffset = 38;
        vmode->mVSyncOffset = 4;
        vmode->mHSyncPulseWidth = 124;
        vmode->mVSyncPulseWidth = 3;
        vmode->mHSyncPolarity = vmode->mVSyncPolarity = FALSE;
        vmode->mInterlaced = TRUE;
        vmode->mPixelClock = (vmode->mRefreshRate == 239760) ? 10800 : 10810;
        vmode->mPixelRepetitionInput = 1;
        break;
    default:
        vmode->mCode = -1;
        printf("invalid code\n");
        return;
    }
    return;
}
