/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "functions.h"
#include "hardware.h"

/*need to update for mx61*/
void prog_pll(void)
{
 /*TBD*/}

/*!
 * config ipu hsp clk to default 264MHz
 *
 * ipu_hsp_clk is derived from mmdc_ch0 divided by 2.
 */
void ipu_hsp_clk_config(void)
{
    /*clk_sel from mmdc_ch0, podf=1 */
    reg32_write(CCM_CSCDR3, 0x00010800);
}

/*!
 * config ldb clock as per the display resolution
 *
 * ldb clock is derived from PLL5
 */
void ldb_clock_config(int freq)
{
    unsigned int regval = 0;
    if (freq == 65000000)       //for XGA resolution
    {
        /*config pll3 PFD1 to 455M. pll3 is 480M */
        reg32_write(ANATOP_BASE_ADDR + 0xF0, 0x1311130C);

        /*set ldb_di0_clk_sel to PLL3 PFD1 */
        regval = reg32_read(CCM_CS2CDR) & (~0x7E00);
        regval |= 0x3600;
        reg32_write(CCM_CS2CDR, regval);

        /*set clk_div to 7 */
        regval = reg32_read(CCM_CSCMR2) & (~0xC00);
        regval |= 0xC00;
        reg32_write(CCM_CSCMR2, regval);

        /*set ipu1_di0_clk_sel from ldb_di0_clk */
        regval = reg32_read(CCM_CHSCCDR) & (~0x0E07);
        regval |= 0x0603;
        reg32_write(CCM_CHSCCDR, regval);
        regval = reg32_read(CCM_CSCDR2) & (~0x0E07);
        regval |= 0x0603;
        reg32_write(CCM_CSCDR2, regval);
    } else {
        printf("The frequency %d for LDB is not supported yet.", freq);
    }
}

void hdmi_clock_set(unsigned int pclk)
{
    unsigned int regval = 0;

    if (pclk == 74250000) {
        /*clk output from 540M PFD1 of PLL3 */
        regval = reg32_read(CCM_CHSCCDR) & (~0x1FF);
        reg32_write(CCM_CHSCCDR, regval | 0x168);

        /*config PLL5 to be 445MHz */
        reg32_write(ANATOP_BASE_ADDR + 0xF8, 0x00003F00);
        reg32_write(ANATOP_BASE_ADDR + 0xF4, 0x00001300);
    } else {
        printf("the hdmi pixel clock is not supported!\n");
    }
}
