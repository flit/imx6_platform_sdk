/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file hdmi_common.h
 * @brief common definitions for hdmi driver.
 * @ingroup diag_hdmi
 */

#ifndef __HDMI_COMMON_H__
#define __HDMI_COMMON_H__

#define TRUE 1
#define FALSE 0

enum hdmi_datamap {
    RGB444_8B = 0x01,
    RGB444_10B = 0x03,
    RGB444_12B = 0x05,
    RGB444_16B = 0x07,
    YCbCr444_8B = 0x09,
    YCbCr444_10B = 0x0B,
    YCbCr444_12B = 0x0D,
    YCbCr444_16B = 0x0F,
    YCbCr422_8B = 0x16,
    YCbCr422_10B = 0x14,
    YCbCr422_12B = 0x12,
};

enum hdmi_csc_enc_format {
    eRGB = 0x0,
    eYCC444 = 0x01,
    eYCC422 = 0x2,
    eExtended = 0x3,
};

enum hdmi_colorimetry {
    eITU601,
    eITU709,
};

enum hdmi_input_source {
    IPU1_DI0 = 0x0,
    IPU1_DI1 = 0x1,
    IPU2_DI0 = 0x2,
    IPU2_DI1 = 0x3,
};

typedef struct hdmi_vmode {
    unsigned int mCode;
    unsigned int mHdmiDviSel;
    unsigned int mRVBlankInOSC;
    unsigned int mRefreshRate;
    unsigned int mHImageSize;
    unsigned int mVImageSize;
    unsigned int mHActive;
    unsigned int mVActive;
    unsigned int mHBlanking;
    unsigned int mVBlanking;
    unsigned int mHSyncOffset;
    unsigned int mVSyncOffset;
    unsigned int mHSyncPulseWidth;
    unsigned int mVSyncPulseWidth;
    unsigned int mHSyncPolarity;
    unsigned int mVSyncPolarity;
    unsigned int mDataEnablePolarity;
    unsigned int mInterlaced;
    unsigned int mPixelClock;
    unsigned int mHBorder;
    unsigned int mVBorder;
    unsigned int mPixelRepetitionInput;
} hdmi_vmode_s;

typedef struct hdmi_data_info {
    unsigned int enc_in_format;
    unsigned int enc_out_format;
    unsigned int enc_color_depth;
    unsigned int colorimetry;
    unsigned int pix_repet_factor;
    unsigned int hdcp_enable;
    hdmi_vmode_s * video_mode;
} hdmi_data_info_s;

/*! ------------------------------------------------------------
 * HDMI TX common Functions
 *  ------------------------------------------------------------
 */
void writebf(uint8_t data, uint32_t addr, uint8_t shift, uint8_t width);
void hdmi_set_video_mode(hdmi_vmode_s * vmode);
int isColorSpaceConversion(hdmi_data_info_s hdmi_instance);
int isColorSpaceDecimation(hdmi_data_info_s hdmi_instance);
int isColorSpaceInterpolation(hdmi_data_info_s hdmi_instance);
int isPixelRepetition(hdmi_data_info_s hdmi_instance);

/*! ------------------------------------------------------------
 * HDMI TX Functions
 *  ------------------------------------------------------------
 */
void hdmi_config_input_source(uint32_t mux_value);

/*! ------------------------------------------------------------
 * HDMI TX Video Sampler
 *  ------------------------------------------------------------
 */
void hdmi_video_sample(hdmi_data_info_s hdmi_instance);

/*! ------------------------------------------------------------
 * HDMI TX Color Space Converter
 *  ------------------------------------------------------------
 */
void update_csc_coeffs(hdmi_data_info_s hdmi_instance);
void hdmi_video_csc(hdmi_data_info_s hdmi_instance);

/*! ------------------------------------------------------------
 * HDMI TX Video Packetizer
 *  ------------------------------------------------------------
 */
void hdmi_video_packetize(hdmi_data_info_s hdmi_instance);

/*! ------------------------------------------------------------
 * HDMI TX Frame Composer
 *  ------------------------------------------------------------
 */
void preamble_filter_set(uint8_t value, uint8_t channel);
void hdmi_av_frame_composer(hdmi_data_info_s * hdmi_instance);

/*! ------------------------------------------------------------
 * HDMI TX Audio
 *  ------------------------------------------------------------
 */
void hdmi_audio_mute(uint32_t en);

/*! ------------------------------------------------------------
 * HDMI TX HDCP
 *  ------------------------------------------------------------
 */
void hdmi_tx_hdcp_config(uint32_t de);

/*! ------------------------------------------------------------
 * HDMI TX PHY
 *  ------------------------------------------------------------
 */
void hdmi_phy_init(uint8_t de, uint16_t pclk);


/*! ------------------------------------------------------------
 * Functions for Debugging
 *  ------------------------------------------------------------
 */
void hdmi_config_force_video(uint8_t force);
void hdmi_config_forced_pixels(uint8_t red, uint8_t green, uint8_t blue);

#endif
