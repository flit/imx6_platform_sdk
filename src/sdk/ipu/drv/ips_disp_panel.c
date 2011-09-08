/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_disp_panel.c
 * @brief IPU Software library, display panel parameters setting and initialization
 * @group diag_ipu
 */
#include "ips.h"
#include "ipu_common.h"

/*!
 * lvds bridge configuration
 *
 * @param   	bit_mode:      	18 or 24bit mode selection
 */
void ldb_config(int bit_mode)
{
    char recvCh = '2';

    switch (recvCh) {
    case '0':
        /* enable DI0 on LVDS port 0 */
        writel(0x0001 | (bit_mode << 5), IOMUXC_GPR2);
        break;
    case '1':
        /* enable DI0 on LVDS port 1 */
        writel(0x0004 | (bit_mode << 7), IOMUXC_GPR2);
        break;
    case '2':
    default:
        /* enable DI0 on both LVDS ports */
        writel(0x0005 | (bit_mode << 5) | (bit_mode << 7), IOMUXC_GPR2);
        break;
    case '3':
        /* enable DI0 on LVDS port 0 and 1 in split mode */
        writel(0x0015 | (bit_mode << 5) | (bit_mode << 7), IOMUXC_GPR2);
        break;
    }
}

static int claa_wvga_panel_init(void)
{
    return true;
}

static int claa_wvga_panel_deinit(void)
{
    return true;
}

extern void ldb_iomux_config(void);
extern void ldb_clock_config(int freq);
extern void lvds_power_on(void);
extern void ldb_config(int bit_mode);

static int hannstar_lvds_panel_init(void)
{
    ldb_iomux_config();
    ldb_clock_config(65000000);
    lvds_power_on();
    ldb_config(LVDS_PANEL_18BITS_MODE);
    return true;
}

static int hannstar_lvds_panel_deinit(void)
{
    return true;
}

extern void hdmi_pgm_iomux(void);
extern void hdmi_clock_set(unsigned int pclk);
static int hdmi_1080p60_init(void)
{
    hdmi_pgm_iomux();
    hdmi_clock_set(148500000);
    //hdmi_config();
    return true;
}

static int hdmi_1080p60_deinit(void)
{
    return true;
}

ips_dev_panel_t disp_dev_list[] = {
    {
     "CLAA01 WVGA",             // name
     CLAA_WVGA,                 // panel id flag
     DCMAP_RGB666,              // data format for panel
     60,                        // refresh rate
     800,                       // panel width
     480,                       //panel height
     27000000,                  // pixel clock frequency
     60,                        // hsync start width
     20,                        // hsync width
     40,                        // hsyn back width
     15,                        // vysnc start width
     10,                        // vsync width
     5,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     0,                         // clock selection, internal
     0,                         // clock polarity
     0,                         // hsync polarity
     0,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     &claa_wvga_panel_init,     // initialization
     &claa_wvga_panel_deinit,   // deinit
     }
    ,
    {
     "HannStar XGA LVDS",       // name
     HannStar_XGA_LVDS,         // panel id flag
     DCMAP_RGB666,              // data format for panel
     60,                        // refresh rate
     1024,                      // panel width
     768,                       //panel height
     65000000,                  // pixel clock frequency
     296,                       // hsync start width
     136,                       // hsync width
     24,                        // hsyn back width
     32,                        // vysnc start width
     3,                         // vsync width
     6,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     1,                         // clock selection, external
     1,                         // clock polarity
     1,                         // hsync polarity
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     &hannstar_lvds_panel_init,
     &hannstar_lvds_panel_deinit,
     }
    ,
    {
     "HDMI 1080P 60Hz",         // name
     HDMI_1080P60,              // panel id flag
     DCMAP_RGB888,              // data format for panel
     60,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     148500000,                 // pixel clock frequency
     192,                       // hsync start width
     44,                        // hsync width
     88,                        // hsyn back width
     41,                        // vysnc start width
     5,                         // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync polarity
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     &hdmi_1080p60_init,
     &hdmi_1080p60_deinit,
     }
};

uint32_t num_of_panels = sizeof(disp_dev_list) / sizeof(ips_dev_panel_t);
