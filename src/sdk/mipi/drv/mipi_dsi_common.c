/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  mipi_dsi_common.c
 * @brief common functions for mipi dsi, currently only support DPI mode
 *
 * @ingroup diag_mipi
 */

#include "mipi_common.h"
#include "../../ipu/inc/ipu_common.h"

void dphy_write_control(unsigned long testcode, unsigned long testwrite)
{
    reg32_write(DSI_PHY_TST_CTRL0, 0x00000000);
    reg32_write(DSI_PHY_TST_CTRL1, (0x00010000 | testcode));
    reg32_write(DSI_PHY_TST_CTRL0, 0x00000002);
    reg32_write(DSI_PHY_TST_CTRL0, 0x00000000);
    reg32_write(DSI_PHY_TST_CTRL1, (0x00000000 | testwrite));
    reg32_write(DSI_PHY_TST_CTRL0, 0x00000002);
    reg32_write(DSI_PHY_TST_CTRL0, 0x00000000);

}

void gen_write_cmd(unsigned long gen_hdr)
{
    reg32_write(DSI_GEN_HDR, gen_hdr);
}

void gen_write_data(unsigned long gen_pld_data)
{
    reg32_write(DSI_GEN_PLD_DATA, gen_pld_data);
}

void mipi_lcd_init(void)
{
    gen_write_data(0x6983ffb9);
    gen_write_cmd(0x00000429);
    //hal_delay_us(1000);

    gen_write_data(0x032300b2);
    gen_write_data(0xff007003);
    gen_write_data(0x00000000);
    gen_write_data(0x01000303);
    gen_write_cmd(0x00001029);
    //hal_delay_us(1000);

    gen_write_data(0x5f1d00b4);
    gen_write_data(0x0000060e);
    gen_write_cmd(0x00000629);
    //hal_delay_us(1000);

    gen_write_data(0x030400d5);
    gen_write_data(0x1c050100);
    gen_write_data(0x00030170);
    gen_write_data(0x51064000);
    gen_write_data(0x41000007);
    gen_write_data(0x07075006);
    gen_write_data(0x0000040f);
    gen_write_cmd(0x00001b29);
    //hal_delay_us(5000);

    gen_write_data(0x340001b1);
    gen_write_data(0x0f0f0006);
    gen_write_data(0x3f3f322a);
    gen_write_data(0xe6013a07);
    gen_write_data(0xe6e6e6e6);
    gen_write_cmd(0x00001429);
    //hal_delay_us(1000);

    gen_write_data(0x005656b6);
    gen_write_cmd(0x00000329);
    //hal_delay_us(1000);

    gen_write_cmd(0x0002cc23);
    //hal_delay_us(1000);

    gen_write_data(0x221d00e0);
    gen_write_data(0x2e3f3d38);
    gen_write_data(0x0f0d064a);
    gen_write_data(0x16131513);
    gen_write_data(0x1d001910);
    gen_write_data(0x3f3d3822);
    gen_write_data(0x0d064a2e);
    gen_write_data(0x1315130f);
    gen_write_data(0x00191016);
    gen_write_cmd(0x00002329);
    //hal_delay_us(500);

    gen_write_data(0xc6a000ba);
    gen_write_data(0x10000a00);
    gen_write_data(0x11026f30);
    gen_write_data(0x00004018);

    gen_write_cmd(0x00000e29);
    gen_write_cmd(0x00773a23);

    gen_write_data(0xdf00002a);
    gen_write_data(0x00000001);

    gen_write_cmd(0x00000529);

    gen_write_data(0x1f00002b);
    gen_write_data(0x00000003);

    gen_write_cmd(0x00000529);
    hal_delay_us(500);

    gen_write_cmd(0x00ff5123);  //Write CABC minimum brightness,

    gen_write_cmd(0x00001523);  //Write CABC minimum brightness,
    hal_delay_us(500);
    gen_write_cmd(0x00245323);  //Write CABC minimum brightness,
    hal_delay_us(500);

    gen_write_cmd(0x00001113);
    //hal_delay_us(1000);

    gen_write_cmd(0x00002913);

    hal_delay_us(1000);
}

void mipi_dsi_init(void)
{
    int dlane = 1;              //data lane set to 1

    /*step 1: keeping core and d-phy in reset state */
    reg32_write(DSI_PWR_UP, 0x0);
    reg32_write(DSI_PHY_RSTZ, 0x00000000);

    /*step 2: set the DSI DPI interface */
    reg32_write(DSI_PHY_IF_CFG, ((PHY_STOP_WAIT_TIME << 2) | (dlane - 1)));
    /*virtual id = 0, 24bit color normal color mode, and also the sync polarities */
    reg32_write(DSI_DPI_CFG, DPI_CFG);
    /*set the video transmission mode, select burst mode */
    reg32_write(DSI_VID_MODE_CFG, VID_MODE_CFG);
    /*set timeout clock and escape clock divisions. */
    reg32_write(DSI_CLKMGR_CFG, DSI_CLK_DIV);
    reg32_write(DSI_TMR_CFG, PHY_TIMING_CFG);
    reg32_write(DSI_VID_PKT_CFG, VID_PKT_CFG);  //pixel per packet is 480, one line 
    /*set the timing */
    reg32_write(DSI_TMR_LINE_CFG, TMR_LINE_CFG);
    reg32_write(DSI_VTIMING_CFG, VTIMING_CFG);
    /*set the packet handleri, including the packet size and sync timing */
    reg32_write(DSI_PCKHDL_CFG, PCKHDL_CFG);
    reg32_write(DSI_CMD_MODE_CFG, 0x00001fff);
    /*enable DSI controller */
    reg32_write(DSI_PWR_UP, PWR_UP);

    /*step 4: configure the DPHY PLL clock frequency */
    dphy_write_control(0x44, 0x32); //set clock to be 800Mhz
    reg32_write(DSI_PHY_RSTZ, 0x7);
    while ((reg32_read(DSI_PHY_STATUS) & 0x1) != 0x1) ;
    while ((reg32_read(DSI_PHY_STATUS) & 0x4) != 0x4) ;

    /*configure the TRULY panel through the generic data interface */
    mipi_lcd_init();

    reg32_write(DSI_PHY_IF_CTRL, PHY_IF_CTRL);
}
