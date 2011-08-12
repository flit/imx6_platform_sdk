/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_disp_panel.c
 * @brief IPU Software library, display panel parameters 
 */
#include "ips.h"
#include "ipu_common.h"

void ldb_config(int bit_mode)
{
    char recvCh = NONE_CHAR;

    /*LVDS panel test */
    printf("Please select LVDS port to use:\n");
    printf("\t0 - LVDS port 0\n");
    printf("\t1 - LVDS port 1\n");
    printf("\t2 - LVDS port 0 and port 1\n");
    printf("\t3 - LVDS port 0 and port 1 in split mode\n");

    do {
        recvCh = uart_receive_char(&debug_uart);

        if (recvCh == '0') {
            /* enable DI0 on LVDS port 0 */
            writel(0x0001 | (bit_mode << 5), IOMUXC_GPR2);
            break;
        } else if (recvCh == '1') {
            /* enable DI0 on LVDS port 1 */
            writel(0x0004 | (bit_mode << 7), IOMUXC_GPR2);
            break;
        } else if (recvCh == '2') {
            /* enable DI0 on both LVDS ports */
            writel(0x0005 | (bit_mode << 5) | (bit_mode << 7), IOMUXC_GPR2);
            break;
        } else if (recvCh == '3') {
            /* enable DI0 on LVDS port 0 and 1 in split mode */
            writel(0x0015 | (bit_mode << 5) | (bit_mode << 7), IOMUXC_GPR2);
            break;
        }
    }
    while (1);

}

int claa_wvga_panel_init(int panel_type)
{
    return true;
}

int claa_wvga_panel_deinit(int panel_type)
{
    return true;
}

int hannstar_lvds_panel_init(int panel_type)
{
    ldb_iomux_config();
    ldb_clock_config(65000000);
    lvds_power_on();
    ldb_config(0);
    return true;
}

int hannstar_lvds_panel_deinit(int panel_type)
{
    return true;
}

ips_dev_panel_t disp_dev_list[16] = {
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
     1,                         // hsync selection
     0,                         // hsync polarity
     2,                         // vsync selection
     0,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     0,                         // internal vsync
     &claa_wvga_panel_init,     // initialization
     &claa_wvga_panel_deinit,   // deinit
     }
    ,
    {
     "HannStar XGA LVDS",
     HannStar_XGA_LVDS,
     DCMAP_RGB666,
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
     1,
     1,
     1,
     1,
     2,
     1,
     1,
     0,                         // data polarity
     1,                         //external vsync
     &hannstar_lvds_panel_init,
     &hannstar_lvds_panel_deinit,
     }
    ,

};
