/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
/*!
 * @defgroup diag_display Test
 */

/*!
 * @file display_common.h
 * @brief lcd display common definitions. for both LCDC and IPU usage.
 * @ingroup diag_display
 */

#ifndef __LCD_DISPLAY_H__
#define __LCD_DISPLAY_H__

enum color_map {
    DCMAP_RGB565,
    DCMAP_RGB666,
    DCMAP_RGB666H,
    DCMAP_RGB666L,
    DCMAP_RGB888,
    DCMAP_GBR888,
    DCMAP_BRG888,
    DCMAP_YUV888,
    DCMAP_UVY888,
    DCMAP_VYU888,
    DCMAP_RGBA8888,
    DCMAP_YUVA8888,
};
enum disp_dev_flag {
    EPSON_VGA,
    CLAA_WVGA,
    SEIKO_WVGA_7INCH,
    SEIKO_WVGA_4_3INCH,
    AUO_XGA_LVDS,
    HannStar_XGA_LVDS,
    CHIMEI_HD1080_LVDS,
    VGAOUT_XGA,
    DVI_SVGA,
    DVI_XGA,
    DVI_SXGA,
    TV_NTSC,
    TV_PAL,
    TV_720P60,
    TV_1080P30,
    TV_1080P25,
    TV_1080P24,
    TV_1080I60,
    HDMI_480P60,
    HDMI_720P60,
    HDMI_1080P24,
    HDMI_1080P25,
    HDMI_1080P30,
    HDMI_1080P60,
};

typedef struct display_device_info {
    char name[32];
    unsigned int name_flag;
    unsigned int refresh;
    unsigned int width;
    unsigned int height;
    unsigned int pixel_clock;
    unsigned int hsync_start_width;
    unsigned int hsync_width;
    unsigned int hsync_end_width;
    unsigned int vsync_start_width;
    unsigned int vsync_width;
    unsigned int vsync_end_width;
    unsigned int delay_h2v;
    unsigned int interlaced;
    unsigned int data_format;
    unsigned int clk_sel;
    unsigned int clk_pol;
    unsigned int hsync_sel;
    unsigned int hsync_pol;
    unsigned int vsync_sel;
    unsigned int vsync_pol;
    unsigned int drdy_pol;
    unsigned int data_pol;
} display_device_info_t;

#endif
