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
 * @file display_list.h
 * @brief display devices descriptions, including the timing and resolution.
 * @ingroup diag_display
 */

#ifndef __DISPLAY_LIST_H__
#define __DISPLAY_LIST_H__

display_device_info_t disp_dev_list[] = {
    {
     "EPSON L4F00242 VGA",      // name
     EPSON_VGA,                 // name flag
     60,                        // refresh rate
     480,                       // panel width
     640,                       //panel height
     24000000,                  // pixel clock frequency
     80,                        // hsync start width
     20,                        // hsync width
     41,                        // hsyn back width
     20,                        // vysnc start width
     10,                        // vsync width
     5,                         // vsync back width
     480,                       // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_RGB666,              // data format for panel
     0,                         // clock selection, internal
     1,                         // clock polarity
     1,                         // hsync selection
     0,                         // hsync polarity
     2,                         // vsync selection
     0,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "CLAA01 WVGA",
     CLAA_WVGA,
     60,
     800,
     480,
     27000000,
     60,
     20,
     40,
     15,
     10,
     5,
     0,
     0,
     DCMAP_RGB565,
     0,                         // clock selection
     0,                         // clock polarity
     1,                         // hsync selection
     0,                         // hsync polarity
     2,                         // vsync selection
     0,                         // vync polarity
     1,
     0,                         // data polarity
     }
    ,
    {
     "SEIKO WVGA 7 INCH",
     SEIKO_WVGA_7INCH,
     60,
     800,
     480,
     33260000,
     216,
     128,
     40,
     35,
     2,
     10,
     0,
     0,
     DCMAP_RGB888,
     0,
     1,
     0,                         // hsync selection
     0,                         // hsync polarity
     2,                         // vsync selection
     0,                         // vync polarity
     1,
     0,                         // data polarity
     }
    ,
    {
     "SEIKO WVGA 4.3 INCH",
     SEIKO_WVGA_4_3INCH,
     60,
     800,
     480,
     33500000,
     174,
     10,
     89,
     20,
     10,
     23,
     0,
     0,
     DCMAP_RGB888,
     0,
     1,
     0,                         // hsync selection
     0,                         // hsync polarity
     2,                         // vsync selection
     0,                         // vync polarity
     1,
     0,                         // data polarity
     }
    {
     "AUO 17'' XGA LVDS",
     AUO_XGA_LVDS,
     60,
     1024,
     768,
     65000000,
     296,
     136,
     24,
     32,
     3,
     6,
     0,
     0,
     DCMAP_RGB888,
     1,
     1,
     1,
     1,
     2,
     1,
     1,
     0,                         // data polarity
     }
    ,
    {
     "HannStar XGA LVDS",
     HannStar_XGA_LVDS,
     60,
     1024,
     768,
     65000000,
     296,
     136,
     24,
     32,
     3,
     6,
     0,
     0,
     DCMAP_RGB666,
     1,
     1,
     1,
     1,
     2,
     1,
     1,
     0,                         // data polarity
     }
    ,
    {
     "CHIMEI 21'' HD1080 LVDS",
     CHIMEI_HD1080_LVDS,
     60,
     1920,
     1080,
     130000000,
     100,
     20,
     40,
     36,
     10,
     10,
     0,
     0,
     DCMAP_RGB888,
     1,
     1,
     1,
     1,
     2,
     1,
     1,
     0,                         // data polarity
     }
    ,
    {
     "VGA OUT XGA RESOLUTION",
     VGAOUT_XGA,
     60,
     1024,
     768,
     65000000,
     160,
     136,
     160,
     9,
     6,
     29,
     0,
     0,
     DCMAP_GBR888,
     1,                         // clock selection, external
     0,                         // clock polarity
     0,                         // hsync selection
     0,                         // hsync polarity
     2,                         // vsync selection
     0,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "DVI OUT SVGA RESOLUTION",
     DVI_SVGA,
     60,
     800,
     600,
     32000000,
     22,
     16,
     3,
     60,
     40,
     27,
     0,
     0,
     DCMAP_RGB888,
     0,
     0,
     1,
     1,
     2,
     1,
     1,
     0,                         // data polarity
     }
    ,
    {
     "DVI OUT XGA RESOLUTION",
     DVI_XGA,
     60,
     1024,
     768,
     65000000,
     312,
     144,
     8,
     35,
     6,
     3,
     0,
     0,
     DCMAP_RGB888,
     0,                         // clock selection, internal
     1,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "DVI OUT SXGA RESOLUTION",
     DVI_SXGA,
     60,
     1280,
     1024,
     108000000,
     360,
     112,
     48,
     41,
     3,
     1,
     0,
     0,
     DCMAP_RGB888,
     0,                         // clock selection, internal
     1,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "TV OUT NTSC MODE",        // name
     TV_NTSC,                   // name flag
     60,                        // refresh rate
     720,                       // panel width
     480,                       //panel height
     27000000,                  // pixel clock frequency
     126,                       // hsync start width
     2,                         // hsync width
     12,                        // hsyn back width
     32,                        // vysnc start width
     3,                         // vsync width
     13,                        // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_VYU888,              // data format for panel
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "TV OUT PAL MODE",         // name
     TV_PAL,                    // name flag
     50,                        // refresh rate
     720,                       // panel width
     576,                       //panel height
     27000000,                  // pixel clock frequency
     126,                       // hsync start width
     2,                         // hsync width
     18,                        // hsyn back width
     32,                        // vysnc start width
     3,                         // vsync width
     17,                        // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_VYU888,              // data format for panel
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "TV OUT 720P 60Hz MODE",   // name
     TV_720P60,                 // name flag
     60,                        // refresh rate
     1280,                      // panel width
     720,                       //panel height
     74250000,                  // pixel clock frequency
     260,                       // hsync start width
     10,                        // hsync width
     110,                       // hsyn back width
     26,                        // vysnc start width
     2,                         // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_VYU888,              // data format for panel
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "TV OUT 1080P 30Hz MODE",  // name
     TV_1080P30,                // name flag
     30,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     74250000,                  // pixel clock frequency
     192,                       // hsync start width
     10,                        // hsync width
     88,                        // hsyn back width
     41,                        // vysnc start width
     10,                        // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_VYU888,              // data format for panel
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "TV OUT 1080P 25Hz MODE",  // name
     TV_1080P25,                // name flag
     25,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     74250000,                  // pixel clock frequency
     192,                       // hsync start width
     5,                         // hsync width
     528,                       // hsyn back width
     40,                        // vysnc start width
     5,                         // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_VYU888,              // data format for panel
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "TV OUT 1080P 24Hz MODE",  // name
     TV_1080P24,                // name flag
     24,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     74250000,                  // pixel clock frequency
     192,                       // hsync start width
     5,                         // hsync width
     638,                       // hsyn back width
     41,                        // vysnc start width
     5,                         // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_VYU888,              // data format for panel
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     // 1080I60
     "TV OUT 1080I 60Hz MODE",  // name
     TV_1080I60,                // name flag
     60,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     74250000,                  // pixel clock frequency
     192,                       // hsync start width
     10,                        // hsync width
     88,                        // hsyn back width
     40,                        // vysnc start width
     10,                        // vsync width
     5,                         // vsync back width
     0,                         // delay from hsync to vsync
     1,                         // interlaced mode
     DCMAP_VYU888,              // data format for panel
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "HDMI 480P 60Hz MODE",     // name, 640*480
     HDMI_480P60,               // name flag
     60,                        // refresh rate
     640,                       // panel width
     480,                       //panel height
     25170000,                  // pixel clock frequency
     144,                       // hsync start width
     96,                        // hsync width
     16,                        // hsyn back width
     35,                        // vysnc start width
     2,                         // vsync width
     10,                        // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_RGB888,              // data format for panel
     1,                         // clock selection
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "HDMI 720P 60Hz MODE",     // name
     HDMI_720P60,               // name flag
     60,                        // refresh rate
     1280,                      // panel width
     720,                       //panel height
     74250000,                  // pixel clock frequency
     260,                       // hsync start width
     40,                        // hsync width
     110,                       // hsyn back width
     25,                        // vysnc start width
     5,                         // vsync width
     5,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_RGB888,              // data format for panel
     1,                         // clock selection
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "HDMI 1080P24 MODE",       // name
     HDMI_1080P24,              // name flag
     24,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     74250000,                  // pixel clock frequency
     192,                       // hsync start width
     5,                         // hsync width
     638,                       // hsyn back width
     41,                        // vysnc start width
     5,                         // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_RGB888,              // data format for panel
     1,                         // clock selection
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "HDMI 1080P25 MODE",       // name
     HDMI_1080P25,              // name flag
     25,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     74250000,                  // pixel clock frequency
     192,                       // hsync start width
     10,                        // hsync width
     528,                       // hsyn back width
     40,                        // vysnc start width
     10,                        // vsync width
     5,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_RGB888,              // data format for panel
     1,                         // clock selection
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "HDMI 1080P30 MODE",       // name
     HDMI_1080P30,              // name flag
     30,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     74250000,                  // pixel clock frequency
     192,                       // hsync start width
     10,                        // hsync width
     88,                        // hsyn back width
     41,                        // vysnc start width
     10,                        // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_RGB888,              // data format for panel
     1,                         // clock selection
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
    ,
    {
     "HDMI 1080P 60Hz MODE",    // name
     HDMI_1080P60,              // name flag
     60,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     74250000,                  // pixel clock frequency
     192,                       // hsync start width
     10,                        // hsync width
     88,                        // hsyn back width
     41,                        // vysnc start width
     10,                        // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     DCMAP_RGB888,              // data format for panel
     1,                         // clock selection
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     2,                         // vsync selection
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     }
};

#endif
