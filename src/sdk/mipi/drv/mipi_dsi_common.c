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

void gen_write_cmd(unsigned long GEN_HDR)
{

    reg32_write(DSI_GEN_HDR, GEN_HDR);
}

void gen_write_data(unsigned long GEN_PLD_DATA)
{
    reg32_write(DSI_GEN_PLD_DATA, GEN_PLD_DATA);
}

void mipi_lcd_init(void)
{
    gen_write_data(0x6983ffb9);
    gen_write_cmd(0x00000429);  //dcs long write 4byte,
    //hal_delay_us(1000);

    gen_write_data(0x032300b2);
    gen_write_data(0xff007003);
    gen_write_data(0x00000000);
    gen_write_data(0x01000303);

    gen_write_cmd(0x00001029);  //dcs long write 3byte,
    //hal_delay_us(1000);

    gen_write_data(0x5f1d00b4);
    gen_write_data(0x0000060e);
    gen_write_cmd(0x00000629);  //dcs long write 3byte,   
    //hal_delay_us(1000);

    gen_write_data(0x030400d5);
    gen_write_data(0x1c050100);
    gen_write_data(0x00030170);
    gen_write_data(0x51064000);
    gen_write_data(0x41000007);
    gen_write_data(0x07075006);
    gen_write_data(0x0000040f);

    gen_write_cmd(0x00001b29);  //dcs long write 3byte,
    //hal_delay_us(5000);

    gen_write_data(0x340001b1);
    gen_write_data(0x0f0f0006);
    gen_write_data(0x3f3f322a);
    gen_write_data(0xe6013a07);
    gen_write_data(0xe6e6e6e6);
    gen_write_cmd(0x00001429);  //dcs long write 3byte,
    //hal_delay_us(1000);

    gen_write_data(0x005656b6);
    gen_write_cmd(0x00000329);  //dcs long write 3byte,
    //hal_delay_us(1000);

    gen_write_cmd(0x0002cc23);  //dcs long write 4byte,
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
    gen_write_cmd(0x00002329);  //dcs long write 3byte,       

    //hal_delay_us(500);

    gen_write_data(0xc6a000ba);
    gen_write_data(0x10000a00);
    gen_write_data(0x11026f30);
    gen_write_data(0x00004018);

    gen_write_cmd(0x00000e29);  //dcs long write 3byte,   
    gen_write_cmd(0x00773a23);  //dcs long write 4byte,   

    gen_write_data(0xdf00002a);
    gen_write_data(0x00000001);

    gen_write_cmd(0x00000529);  //dcs long write 3byte,   

    gen_write_data(0x1f00002b);
    gen_write_data(0x00000003);

    gen_write_cmd(0x00000529);  //dcs long write 3byte,  
    hal_delay_us(500);

    gen_write_cmd(0x00ff5123);  //Write CABC minimum brightness,

    gen_write_cmd(0x00001523);  //Write CABC minimum brightness,
    hal_delay_us(500);
    gen_write_cmd(0x00245323);  //Write CABC minimum brightness,
    hal_delay_us(500);

    gen_write_cmd(0x00001113);  //dcs long write 4byte,                              
    //hal_delay_us(1000);

    gen_write_cmd(0x00002913);  //dcs long write 4byte,   

    hal_delay_us(1000);

}

void mipi_dsi_init(void)
{
    unsigned long rd_data;

    /*keeping core and d-phy in reset state */
    reg32_write(DSI_PWR_UP, 0x0);
    reg32_write(DSI_PHY_RSTZ, 0x00000000);

    /*set DSI clock and data lanes */
    reg32_write(DSI_CLKMGR_CFG, 0x107);
    reg32_write(DSI_DPI_CFG, DPI_CFG);  //hsync,vsync,dataen,low active ,and 24bits color coding
    reg32_write(DSI_PCKHDL_CFG, PCKHDL_CFG);
    reg32_write(DSI_DBI_CFG, 0x00000041);   //
    reg32_write(DSI_DBI_CMDSIZE, DBI_CMD_CTRL); //
    reg32_write(DSI_VID_PKT_CFG, VID_PKT_CFG);  //85 pixel on a single video packet.
    reg32_write(DSI_CMD_MODE_CFG, 0x00001fff);
    reg32_write(DSI_TMR_LINE_CFG, TMR_LINE_CFG);    //[31:18]=15.2/8*105=c8, [17:9]=15.2/8/15=1c ,[8:0]:15.2/8*4=8
    reg32_write(DSI_VTIMING_CFG, VTIMING_CFG);  //0x00141451);  //active data 20 line ,front Porch 5, Back Porch5 and Vsycn 1
    reg32_write(DSI_TMR_CFG, PHY_TIMING_CFG);   //0x0046e000);
    reg32_write(DSI_PHY_IF_CFG, PHY_IF_CFG);    //0x00000001);

    reg32_write(DSI_PWR_UP, PWR_UP);    //0x00000001);

    dphy_write_control(0x44, PLL_CLK);  //PLL 27M ref_clk out to 1GHz

    reg32_write(DSI_PHY_RSTZ, PHYRSTZ);
    rd_data = reg32_read(DSI_PHY_STATUS);
    while ((rd_data & 0x00000001) != 0x01) {
        rd_data = reg32_read(DSI_PHY_STATUS);
    }
    while ((rd_data & 0x00000004) != 0x04) {
        rd_data = reg32_read(DSI_PHY_STATUS);
    }
    rd_data = reg32_read(DSI_PHY_STATUS);

    mipi_lcd_init();

    reg32_write(DSI_VID_MODE_CFG, VID_MODE_CFG);    //0x0000003d);
    reg32_write(DSI_PHY_IF_CTRL, PHY_IF_CTRL);
}
