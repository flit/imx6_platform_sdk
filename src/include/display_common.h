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
    uint32_t name_flag;
    uint32_t refresh;
    uint32_t width;
    uint32_t height;
    uint32_t pixel_clock;
    uint32_t hsync_start_width;
    uint32_t hsync_width;
    uint32_t hsync_end_width;
    uint32_t vsync_start_width;
    uint32_t vsync_width;
    uint32_t vsync_end_width;
    uint32_t delay_h2v;
    uint32_t interlaced;
    uint32_t data_format;
    uint32_t clk_sel;
    uint32_t clk_pol;
    uint32_t hsync_sel;
    uint32_t hsync_pol;
    uint32_t vsync_sel;
    uint32_t vsync_pol;
    uint32_t drdy_pol;
    uint32_t data_pol;
} display_device_info_t;

#endif
