/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file hdmi_tx.c
 * @brief Transmit functions for the HDMI controller.
 *
 * @ingroup diag_hdmi
 */

#include <stdio.h>
#include "hardware.h"
#include "hdmi_tx.h"

/*! ------------------------------------------------------------
 * HDMI TX Functions
 *  ------------------------------------------------------------
 */

/*! 
 * program the input source mux for the hdmi input
 * this is set up in IOMUXC_GPR3 register
 * 
 * @param  	mux_value: type hdmi_input_source slecting between the mux options
 */
void hdmi_config_input_source(uint32_t mux_value)
{
    uint32_t regval = 0;

    regval = readl(IOMUXC_GPR3);
    regval &= 0xFFFFFFF0;       // mask off hdmi mux bits 
    regval |= mux_value << 2;   // shift value over to correct bit position
    writel(regval, IOMUXC_GPR3);    // set hdmi input mux value
}

/*! ------------------------------------------------------------
 * HDMI TX Video Sampler
 *  ------------------------------------------------------------
 */
/*!
 * this submodule is responsible for the video data synchronization.
 * for example, for RGB 4:4:4 input, the data map is defined as
 * 			pin{47~40} <==> R[7:0]
 * 			pin{31~24} <==> G[7:0]
 * 			pin{15~8}  <==> B[7:0]
 *
 * @param hdmi_instance - instance of the HDMI
 */
void hdmi_video_sample(hdmi_data_info_s hdmi_instance)
{
    int color_format = 0;
    if (hdmi_instance.enc_in_format == eRGB) {
        if (hdmi_instance.enc_color_depth == 8) {
            color_format = 0x01;
        } else if (hdmi_instance.enc_color_depth == 10) {
            color_format = 0x03;
        } else if (hdmi_instance.enc_color_depth == 12) {
            color_format = 0x05;
        } else if (hdmi_instance.enc_color_depth == 16) {
            color_format = 0x07;
        } else {
            printf("Invalid color depth %d!!", hdmi_instance.enc_color_depth);
            return;
        }
    } else if (hdmi_instance.enc_in_format == eYCC444) {
        if (hdmi_instance.enc_color_depth == 8) {
            color_format = 0x09;
        } else if (hdmi_instance.enc_color_depth == 10) {
            color_format = 0x0B;
        } else if (hdmi_instance.enc_color_depth == 12) {
            color_format = 0x0D;
        } else if (hdmi_instance.enc_color_depth == 16) {
            color_format = 0x0F;
        } else {
            printf("Invalid color depth %d!!", hdmi_instance.enc_color_depth);
            return;
        }
    } else if (hdmi_instance.enc_in_format == eYCC422) {
        if (hdmi_instance.enc_color_depth == 8) {
            color_format = 0x16;
        } else if (hdmi_instance.enc_color_depth == 10) {
            color_format = 0x14;
        } else if (hdmi_instance.enc_color_depth == 12) {
            color_format = 0x12;
        } else {
            printf("Invalid color depth %d!!", hdmi_instance.enc_color_depth);
            return;
        }
    }

    writebf(color_format, HDMI_TX_INVID0, 0, 6);
    writebf(0, HDMI_TX_INVID0, 7, 1);

    /*enable tx stuffing, when DE is inactive, fix the output data to 0 */
    writeb(0x7, HDMI_TX_INSTUFFING);
    writeb(0x0, HDMI_TX_GYDATA0);
    writeb(0x0, HDMI_TX_GYDATA1);
    writeb(0x0, HDMI_TX_RCRDATA0);
    writeb(0x0, HDMI_TX_RCRDATA1);
    writeb(0x0, HDMI_TX_BCBDATA0);
    writeb(0x0, HDMI_TX_BCBDATA1);
}

/*! ------------------------------------------------------------
 * HDMI TX Color Space Converter
 *  ------------------------------------------------------------
 */
/*!
 * update the color space conversion coefficients.
 *
 * @param hdmi_instance - instance of the HDMI
 */
void update_csc_coeffs(hdmi_data_info_s hdmi_instance)
{
    uint16_t csc_coeff[3][4];
    uint32_t csc_scale = 1;
    if (isColorSpaceConversion(hdmi_instance) == TRUE)  // csc needed
    {
        if (hdmi_instance.enc_out_format == eRGB) {
            if (hdmi_instance.colorimetry == eITU601) {
                csc_coeff[0][0] = 0x2000;
                csc_coeff[0][1] = 0x6926;
                csc_coeff[0][2] = 0x74fd;
                csc_coeff[0][3] = 0x010e;

                csc_coeff[1][0] = 0x2000;
                csc_coeff[1][1] = 0x2cdd;
                csc_coeff[1][2] = 0x0000;
                csc_coeff[1][3] = 0x7e9a;

                csc_coeff[2][0] = 0x2000;
                csc_coeff[2][1] = 0x0000;
                csc_coeff[2][2] = 0x38b4;
                csc_coeff[2][3] = 0x7e3b;

                csc_scale = 1;
            } else if (hdmi_instance.colorimetry == eITU709) {
                csc_coeff[0][0] = 0x2000;
                csc_coeff[0][1] = 0x7106;
                csc_coeff[0][2] = 0x7a02;
                csc_coeff[0][3] = 0x00a7;

                csc_coeff[1][0] = 0x2000;
                csc_coeff[1][1] = 0x3264;
                csc_coeff[1][2] = 0x0000;
                csc_coeff[1][3] = 0x7e6d;

                csc_coeff[2][0] = 0x2000;
                csc_coeff[2][1] = 0x0000;
                csc_coeff[2][2] = 0x3b61;
                csc_coeff[2][3] = 0x7e25;

                csc_scale = 1;
            }
        } else if (hdmi_instance.enc_in_format == eRGB) {
            if (hdmi_instance.colorimetry == eITU601) {
                csc_coeff[0][0] = 0x2591;
                csc_coeff[0][1] = 0x1322;
                csc_coeff[0][2] = 0x074b;
                csc_coeff[0][3] = 0x0000;

                csc_coeff[1][0] = 0x6535;
                csc_coeff[1][1] = 0x2000;
                csc_coeff[1][2] = 0x7acc;
                csc_coeff[1][3] = 0x0200;

                csc_coeff[1][0] = 0x6acd;
                csc_coeff[1][1] = 0x7534;
                csc_coeff[1][2] = 0x2000;
                csc_coeff[1][3] = 0x0200;

                csc_scale = 1;
            } else if (hdmi_instance.colorimetry == eITU709) {
                csc_coeff[0][0] = 0x2dc5;
                csc_coeff[0][1] = 0x0d9b;
                csc_coeff[0][2] = 0x049e;
                csc_coeff[0][3] = 0x0000;

                csc_coeff[1][0] = 0x63f0;
                csc_coeff[1][1] = 0x2000;
                csc_coeff[1][2] = 0x7d11;
                csc_coeff[1][3] = 0x0200;

                csc_coeff[2][0] = 0x6756;
                csc_coeff[2][1] = 0x78ab;
                csc_coeff[2][2] = 0x2000;
                csc_coeff[2][3] = 0x0200;

                csc_scale = 1;
            }
        }
    } else {
        csc_coeff[0][0] = 0x2000;
        csc_coeff[0][1] = 0x0000;
        csc_coeff[0][2] = 0x0000;
        csc_coeff[0][3] = 0x0000;

        csc_coeff[1][0] = 0x0000;
        csc_coeff[1][1] = 0x2000;
        csc_coeff[1][2] = 0x0000;
        csc_coeff[1][3] = 0x0000;

        csc_coeff[2][0] = 0x0000;
        csc_coeff[2][1] = 0x0000;
        csc_coeff[2][2] = 0x2000;
        csc_coeff[2][3] = 0x0000;

        csc_scale = 1;
    }

    /*update csc parameters in hdmi csc registers */
    writeb((uint8_t) (csc_coeff[0][0] & 0xFF), HDMI_CSC_COEF_A1_LSB);
    writeb((uint8_t) (csc_coeff[0][0] >> 8), HDMI_CSC_COEF_A1_MSB);
    writeb((uint8_t) (csc_coeff[0][1] & 0xFF), HDMI_CSC_COEF_A2_LSB);
    writeb((uint8_t) (csc_coeff[0][1] >> 8), HDMI_CSC_COEF_A2_MSB);
    writeb((uint8_t) (csc_coeff[0][2] & 0xFF), HDMI_CSC_COEF_A3_LSB);
    writeb((uint8_t) (csc_coeff[0][2] >> 8), HDMI_CSC_COEF_A3_MSB);
    writeb((uint8_t) (csc_coeff[0][3] & 0xFF), HDMI_CSC_COEF_A4_LSB);
    writeb((uint8_t) (csc_coeff[0][3] >> 8), HDMI_CSC_COEF_A4_MSB);

    writeb((uint8_t) (csc_coeff[1][0] & 0xFF), HDMI_CSC_COEF_B1_LSB);
    writeb((uint8_t) (csc_coeff[1][0] >> 8), HDMI_CSC_COEF_B1_MSB);
    writeb((uint8_t) (csc_coeff[1][1] & 0xFF), HDMI_CSC_COEF_B2_LSB);
    writeb((uint8_t) (csc_coeff[1][1] >> 8), HDMI_CSC_COEF_B2_MSB);
    writeb((uint8_t) (csc_coeff[1][2] & 0xFF), HDMI_CSC_COEF_B3_LSB);
    writeb((uint8_t) (csc_coeff[1][2] >> 8), HDMI_CSC_COEF_B3_MSB);
    writeb((uint8_t) (csc_coeff[1][3] & 0xFF), HDMI_CSC_COEF_B4_LSB);
    writeb((uint8_t) (csc_coeff[1][3] >> 8), HDMI_CSC_COEF_B4_MSB);

    writeb((uint8_t) (csc_coeff[2][0] & 0xFF), HDMI_CSC_COEF_C1_LSB);
    writeb((uint8_t) (csc_coeff[2][0] >> 8), HDMI_CSC_COEF_C1_MSB);
    writeb((uint8_t) (csc_coeff[2][1] & 0xFF), HDMI_CSC_COEF_C2_LSB);
    writeb((uint8_t) (csc_coeff[2][1] >> 8), HDMI_CSC_COEF_C2_MSB);
    writeb((uint8_t) (csc_coeff[2][2] & 0xFF), HDMI_CSC_COEF_C3_LSB);
    writeb((uint8_t) (csc_coeff[2][2] >> 8), HDMI_CSC_COEF_C3_MSB);
    writeb((uint8_t) (csc_coeff[2][3] & 0xFF), HDMI_CSC_COEF_C4_LSB);
    writeb((uint8_t) (csc_coeff[2][3] >> 8), HDMI_CSC_COEF_C4_MSB);

    writeb((readb(HDMI_CSC_SCALE) & 0xF0) | csc_scale, HDMI_CSC_SCALE);
}

/*!
 * set HDMI color space conversion module.
 *
 * @param hdmi_instance - instance of the HDMI
 */
void hdmi_video_csc(hdmi_data_info_s hdmi_instance)
{
    int color_depth = 0;
    int interpolation = 0;
    int decimation = 0;

    /*YCC422 interpolation to 444 mode */
    if (isColorSpaceInterpolation(hdmi_instance) == TRUE) {
        interpolation = 0x01;
    } else if (isColorSpaceDecimation(hdmi_instance) == TRUE) {
        decimation = 0x01;
    }

    if (hdmi_instance.enc_color_depth == 8) {
        color_depth = 4;
    } else if (hdmi_instance.enc_color_depth == 10) {
        color_depth = 5;
    } else if (hdmi_instance.enc_color_depth == 12) {
        color_depth = 6;
    } else if (hdmi_instance.enc_color_depth == 16) {
        color_depth = 7;
    } else {
        printf("Invalid color depth %d!!", hdmi_instance.enc_color_depth);
        return;
    }

    /*configure the CSC registers */
    writeb((interpolation << 4) | decimation, HDMI_CSC_CFG);
    writeb((readb(HDMI_CSC_SCALE) & 0x0F) | (color_depth << 4), HDMI_CSC_SCALE);
    update_csc_coeffs(hdmi_instance);
}

/*! ------------------------------------------------------------
 * HDMI TX Video Packetizer
 *  ------------------------------------------------------------
 */

/*!
 * HDMI video packetizer is used to packetize the data.
 * for example, if input is YCC422 mode or repeater is used, data should be repacked
 * this module can be bypassed.
 *
 * @param hdmi_instance - instance of the HDMI
 */
void hdmi_video_packetize(hdmi_data_info_s hdmi_instance)
{
    unsigned int color_depth = 0;
    unsigned int remap_size = 0;
    unsigned int output_select = 0;

    if (hdmi_instance.enc_out_format == eRGB || hdmi_instance.enc_out_format == eYCC444) {
        if (hdmi_instance.enc_color_depth == 0) {
            output_select = 3;
        } else if (hdmi_instance.enc_color_depth == 8) {
            color_depth = 4;
            output_select = 3;
        } else if (hdmi_instance.enc_color_depth == 10) {
            color_depth = 5;
        } else if (hdmi_instance.enc_color_depth == 12) {
            color_depth = 6;
        } else if (hdmi_instance.enc_color_depth == 16) {
            color_depth = 7;
        } else {
            printf("Invalid color depth %d!!\n", hdmi_instance.enc_color_depth);
            return;
        }
    } else if (hdmi_instance.enc_out_format == eYCC422) {
        if (hdmi_instance.enc_color_depth == 0 || hdmi_instance.enc_color_depth == 8) {
            remap_size = 0;
        } else if (hdmi_instance.enc_color_depth == 10) {
            remap_size = 1;
        } else if (hdmi_instance.enc_color_depth == 12) {
            remap_size = 2;
        } else {
            printf("Invalid color remap size %d!!\n", hdmi_instance.enc_color_depth);
            return;
        }
        output_select = 1;
    } else {
        printf("Invalid output encoding type %d!!\n", hdmi_instance.enc_out_format);
        return;
    }

    /*set the packetizer registers. */
    writeb(color_depth << 4 | hdmi_instance.pix_repet_factor, HDMI_VP_PR_CD);
    writebf(0x1, HDMI_VP_STUFF, 0, 1);
    if (hdmi_instance.pix_repet_factor > 1) // data from repeter block
    {
        writebf(1, HDMI_VP_CONF, 4, 1);
        writebf(0, HDMI_VP_CONF, 2, 1);
    } else {                    //data from packetizer block
        writebf(0, HDMI_VP_CONF, 4, 1);
        writebf(1, HDMI_VP_CONF, 2, 1);
    }
    writebf(0x1, HDMI_VP_STUFF, 5, 1);
    writebf(remap_size, HDMI_VP_REMAP, 0, 2);

    if (output_select == 0) {
        writebf(0, HDMI_VP_CONF, 6, 1);
        writebf(1, HDMI_VP_CONF, 5, 1);
        writebf(0, HDMI_VP_CONF, 3, 1);
    } else if (output_select == 1) {
        writebf(0, HDMI_VP_CONF, 6, 1);
        writebf(0, HDMI_VP_CONF, 5, 1);
        writebf(1, HDMI_VP_CONF, 3, 1);
    } else if (output_select == 2 || output_select == 3) {
        writebf(1, HDMI_VP_CONF, 6, 1);
        writebf(0, HDMI_VP_CONF, 5, 1);
        writebf(0, HDMI_VP_CONF, 3, 1);
    } else {
        printf("Invalid output option %d\n", output_select);
        return;
    }

    writebf(1, HDMI_VP_STUFF, 2, 1);
    writebf(1, HDMI_VP_STUFF, 1, 1);
    writebf(output_select, HDMI_VP_CONF, 0, 2);
}

/*! ------------------------------------------------------------
 * HDMI TX Frame Composer
 *  ------------------------------------------------------------
 */

/*!
 * preamble filter setting. this is used to indicate whether the 
 * upcoming data period is a VDP(video data period) or DI(data island)
 *
 * @param	value: 		data value for configuration
 * @param	channel:	channel number, 0~2
 */
void preamble_filter_set(uint8_t value, uint8_t channel)
{
    if (channel == 0) {
        writeb(value, HDMI_FC_CH0PREAM);
    } else if (channel == 1) {
        writebf(value, HDMI_FC_CH1PREAM, 0, 6);
    } else if (channel == 2) {
        writebf(value, HDMI_FC_CH2PREAM, 0, 6);
    } else {
        printf("Invalid channel number %d\n", channel);
    }
    return;
}

/*!
 * this submodule is responsible for the video/audio data composition.
 * video mode is set here, but the actual flow is determined by the input.
 *
 * @param hdmi_instance - instance of the HDMI
 */
void hdmi_av_frame_composer(hdmi_data_info_s * hdmi_instance)
{
    uint8_t i = 0;

    hdmi_set_video_mode(hdmi_instance->video_mode);

    // configure HDMI_FC_INVIDCONF register
    writebf((hdmi_instance->hdcp_enable == TRUE) ? 1 : 0, HDMI_FC_INVIDCONF, 7, 1);
    writebf((hdmi_instance->video_mode->mVSyncPolarity == TRUE) ? 1 : 0, HDMI_FC_INVIDCONF, 6, 1);
    writebf((hdmi_instance->video_mode->mHSyncPolarity == TRUE) ? 1 : 0, HDMI_FC_INVIDCONF, 5, 1);
    writebf((hdmi_instance->video_mode->mDataEnablePolarity == TRUE) ? 1 : 0, HDMI_FC_INVIDCONF, 4,
            1);
    writebf((hdmi_instance->video_mode->mHdmiDviSel == TRUE) ? 1 : 0, HDMI_FC_INVIDCONF, 3, 1); // select hdmi or dvi mode    
    if (hdmi_instance->video_mode->mCode == 39) {
        writebf(0, HDMI_FC_INVIDCONF, 1, 1);
    } else {
        writebf((hdmi_instance->video_mode->mInterlaced == TRUE) ? 1 : 0, HDMI_FC_INVIDCONF, 1, 1);
    }
    writebf((hdmi_instance->video_mode->mInterlaced == TRUE) ? 1 : 0, HDMI_FC_INVIDCONF, 0, 1);

    writebf((unsigned char)hdmi_instance->video_mode->mHActive, HDMI_FC_INHACTV0, 0, 8);
    writebf((unsigned char)(hdmi_instance->video_mode->mHActive >> 8), HDMI_FC_INHACTV1, 0, 4);
    writebf((unsigned char)hdmi_instance->video_mode->mHBlanking, HDMI_FC_INHBLANK0, 0, 8);
    writebf((unsigned char)(hdmi_instance->video_mode->mHBlanking >> 8), HDMI_FC_INHBLANK1, 0, 2);
    writebf((unsigned char)hdmi_instance->video_mode->mVActive, HDMI_FC_INVACTV0, 0, 8);
    writebf((unsigned char)(hdmi_instance->video_mode->mVActive >> 8), HDMI_FC_INVACTV1, 0, 3);
    writebf((unsigned char)hdmi_instance->video_mode->mVBlanking, HDMI_FC_INVBLANK, 0, 8);
    writebf((unsigned char)hdmi_instance->video_mode->mHSyncOffset, HDMI_FC_HSYNCINDELAY0, 0, 8);
    writebf((unsigned char)(hdmi_instance->video_mode->mHSyncOffset >> 8), HDMI_FC_HSYNCINDELAY1, 0,
            3);
    writebf((unsigned char)hdmi_instance->video_mode->mHSyncPulseWidth, HDMI_FC_HSYNCINWIDTH0, 0,
            8);
    writebf((unsigned char)(hdmi_instance->video_mode->mHSyncPulseWidth >> 8),
            HDMI_FC_HSYNCINWIDTH1, 0, 1);
    writebf((unsigned char)hdmi_instance->video_mode->mVSyncOffset, HDMI_FC_VSYNCINDELAY, 0, 8);
    writebf((unsigned char)hdmi_instance->video_mode->mVSyncPulseWidth, HDMI_FC_VSYNCINWIDTH, 0, 6);

    writeb(12, HDMI_FC_CTRLDUR);    //control period minimum duration
    writeb(32, HDMI_FC_EXCTRLDUR);
    writeb(1, HDMI_FC_EXCTRLSPAC);

    for (i = 0; i < 3; i++) {
        preamble_filter_set((i + 1) * 11, i);
    }

    /*pixel repetition setting. */
    writebf(hdmi_instance->video_mode->mPixelRepetitionInput + 1, HDMI_FC_PRCONF, 4, 4);
}

/*! ------------------------------------------------------------
 * HDMI TX HDCP
 *  ------------------------------------------------------------
 */

/*!
 * HDCP configuration, disabled here
 *
 * @param 	de:	data enable polarity
 */
void hdmi_tx_hdcp_config(uint32_t de)
{
    writebf(0, HDMI_A_HDCPCFG0, 2, 1);  //disable rx detect
    writebf((de == TRUE) ? 1 : 0, HDMI_A_VIDPOLCFG, 4, 1);
    writebf(1, HDMI_A_HDCPCFG1, 1, 1);
}

/*! ------------------------------------------------------------
 * Functions for Debugging
 *  ------------------------------------------------------------
 */

/*!
 * Force the HDMI video output to be fixed value! from FC_DBGTMDSx registers
 * 
 * @param  	force: true/false or enable/disable, if true enabled force video setting, if false disable it
 */
void hdmi_config_force_video(uint8_t force)
{
    uint8_t regval = 0;
    if (force) {
        regval = readb(HDMI_FC_DBGFORCE);
        writeb((regval | 1), HDMI_FC_DBGFORCE); // set bit 0 to force video from FC_DBGTMDSx registers
    } else {
        regval = readb(HDMI_FC_DBGFORCE);
        writeb((regval & 0xFE), HDMI_FC_DBGFORCE);  // clear bit 0 to disable forced video
    }
}

/*! 
 * configure the RGB pixel settings to be used when fixed video mode is enabled
 * 
 * @param  	red: pixel settings for red component.
 * @param  	green: pixel settings for green component.
 * @param  	blue: pixel settings for blue component.
 */
void hdmi_config_forced_pixels(uint8_t red, uint8_t green, uint8_t blue)
{
    writeb(red, HDMI_FC_DBGTMDS2);  //R
    writeb(green, HDMI_FC_DBGTMDS1);    //G
    writeb(blue, HDMI_FC_DBGTMDS0); //B
}
