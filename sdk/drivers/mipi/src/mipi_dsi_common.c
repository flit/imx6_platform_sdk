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

#include "registers/regsmipidsi.h"
#include "mipi/mipi_common.h"
#include "ipu/ipu_common.h"

void dphy_write_control(unsigned long testcode, unsigned long testwrite)
{
	/* {phy_testclk, phy_testclr} = {0, 0} */
	BW_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK(0);
	BW_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLR(0);

	/* {phy_testen, phy_testdout, phy_testdin}*/
	HW_MIPI_DSI_PHY_TST_CTRL1_WR(testcode);
	BW_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN(1);

	/* {phy_testclk, phy_testclr} = {0, 0} --> {1, 0}*/
	BW_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK(1);

	/* {phy_testclk, phy_testclr} = {1, 0} --> {0, 0}*/
	BW_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK(0);

	/* {phy_testen, phy_testdout, phy_testdin}*/
	HW_MIPI_DSI_PHY_TST_CTRL1_WR(testwrite);
	BW_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN(0);

	/* {phy_testclk, phy_testclr} = {0, 0} --> {1, 0}*/
	BW_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK(1);

	/* {phy_testclk, phy_testclr} = {1, 0} --> {0, 0}*/
	BW_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK(0);
}

void gen_write_cmd(unsigned long gen_hdr)
{
	HW_MIPI_DSI_GEN_HDR_WR(gen_hdr);
}

void gen_write_data(unsigned long gen_pld_data)
{
	HW_MIPI_DSI_GEN_PLD_DATA_WR(gen_pld_data);
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
	int thsa, thbp, thline;
	float dpi2_laneclk_ratio;
	float pclk = 0;
	float pperiod = 0;

	/*step 1: keeping core and d-phy in reset state */
	HW_MIPI_DSI_PWR_UP_WR(0x0);
	HW_MIPI_DSI_PHY_RSTZ_WR(0x0);

    /*step 2: set the DSI DPI interface */
	BW_MIPI_DSI_PHY_IF_CFG_PHY_STOP_WAIT_TIME(PHY_STOP_WAIT_TIME);
	BW_MIPI_DSI_PHY_IF_CFG_N_LANES(dlane - 1);

    /*virtual id = 0, 24bit color normal color mode, and also the sync polarities */
	HW_MIPI_DSI_DPI_CFG_WR(DPI_CFG);
    /*set the video transmission mode, select burst mode */
	HW_MIPI_DSI_VID_MODE_CFG_WR(VID_MODE_CFG);
    /*set timeout clock and escape clock divisions. */
	HW_MIPI_DSI_CLKMGR_CFG_WR(DSI_CLK_DIV);
	HW_MIPI_DSI_PHY_TMR_CFG_WR(PHY_TIMING_CFG);
	HW_MIPI_DSI_VID_PKT_CFG_WR(VID_PKT_CFG);
    /*calculate and set the timing */
	pclk = (264/((int)(264/24.55+0.5)));   //MHz, 264M is the IPU frequency
	pperiod = ((float)(1000/pclk)); //ns
   	dpi2_laneclk_ratio = (float)(pperiod/CLKLANEBYTEPERIOD); 
	thsa = (int)(((float)DPITHSA)*dpi2_laneclk_ratio);
	thbp = (int)(((float)DPITHBP)*dpi2_laneclk_ratio);
	thline = (int)(((float)(DPITHSA+DPITHBP+DPITHACT+DPITHFP))*dpi2_laneclk_ratio);
	BW_MIPI_DSI_TMR_LINE_CFG_HSA_TIME(thsa);
	BW_MIPI_DSI_TMR_LINE_CFG_HBP_TIME(thbp);
	BW_MIPI_DSI_TMR_LINE_CFG_HLINE_TIME(thline);
	HW_MIPI_DSI_VTIMING_CFG_WR(VTIMING_CFG);
    /*set the packet handleri, including the packet size and sync timing */
	HW_MIPI_DSI_PCKHDL_CFG_WR(PCKHDL_CFG);
	HW_MIPI_DSI_CMD_MODE_CFG_WR(0x00001fff);
    /*enable DSI controller */
	HW_MIPI_DSI_PWR_UP_WR(PWR_UP);

    /*step 4: configure the DPHY PLL clock frequency */
    dphy_write_control(0x44, 0x32); //set clock to be 800Mhz
	BW_MIPI_DSI_PHY_RSTZ_PHY_SHUTDOWNZ(1);
	BW_MIPI_DSI_PHY_RSTZ_PHY_RSTZ(1);
	BW_MIPI_DSI_PHY_RSTZ_PHY_ENABLECLK(1);

	while(!HW_MIPI_DSI_PHY_STATUS.B.PHYLOCK);
	while(!HW_MIPI_DSI_PHY_STATUS.B.PHYSTOPSTATECLKLANE);

    /*configure the TRULY panel through the generic data interface */
    mipi_lcd_init();

	HW_MIPI_DSI_PHY_IF_CTRL_WR(PHY_IF_CTRL);
}
