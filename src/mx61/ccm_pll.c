/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

/* In i.MX61, PLLs don't need to be configured. Default values cover most use cases. */
void prog_pll(void)
{
/* TBD */
}

/*!
 * This function returns the frequency of a clock.
 */
uint32_t get_clock(uint8_t clock)
{
    uint32_t ret_val = 0;

    switch (clock) {
    case AHB_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / ahb_podf_;
        break;
    case IPG_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / ahb_podf_ / ipg_podf_;
        break;
    case IPG_PER_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / ahb_podf_ / ipg_podf_ / perclk_podf_;
        break;
    default:
        break;
    }

    return ret_val;
}

/*!
 * Set/unset clock gating for a peripheral.
 * @param   ccm_ccgrx - address of the clock gating register: CCM_CCGR1,...
 * @param   cgx_offset - offset of the clock gating field: CG(x).
 * @param   gating_mode - clock gating mode: CLOCK_ON or CLOCK_OFF.
 */
void ccm_ccgr_config(uint32_t ccm_ccgrx, uint32_t cgx_offset, uint8_t gating_mode)
{
    if (gating_mode == CLOCK_ON)
        *(volatile uint32_t *)(ccm_ccgrx) |= cgx_offset;
    else
        *(volatile uint32_t *)(ccm_ccgrx) &= ~cgx_offset;
}

/*!
 * Set/unset clock gating for a peripheral.
 * @param   base_address - configure clock gating for that module from the base address.
 * @param   gating_mode - clock gating mode: CLOCK_ON or CLOCK_OFF.
 */
void clock_gating_config(uint32_t base_address, uint8_t gating_mode)
{

    switch (base_address) {
    case UART1_BASE_ADDR:
    case UART2_BASE_ADDR:
    case UART3_BASE_ADDR:
    case UART4_BASE_ADDR:
    case UART5_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR5, CG(13) | CG(12), gating_mode);
        break;
    case SSI3_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR5, CG(11), gating_mode);
        break;
    case SSI2_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR5, CG(10), gating_mode);
        break;
    case SSI1_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR5, CG(9), gating_mode);
        break;
    case SPDIF_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR5, CG(7), gating_mode);
        break;
    case SPBA_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR5, CG(6), gating_mode);
        break;
    case SDMA_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR5, CG(3), gating_mode);
        break;
    case SATA_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR5, CG(2), gating_mode);
        break;
    case EPIT1_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR1, CG(6), gating_mode);
        break;
    case EPIT2_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR1, CG(7), gating_mode);
        break;
    case GPT_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR1, CG(10) | CG(9), gating_mode);
        break;

    default:
        break;
    }

}

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

        /*config PLL5 to be 594MHz */
        reg32_write(ANATOP_BASE_ADDR + 0xF8, 0x00003F00);
        reg32_write(ANATOP_BASE_ADDR + 0xF4, 0x00001300);
    } else if (pclk == 148500000) {
        /*clk output from 540M PFD1 of PLL3 */
        regval = reg32_read(CCM_CHSCCDR) & (~0x1FF);
        reg32_write(CCM_CHSCCDR, regval | 0x158);

        /*config PLL5 to be 594MHz */
        reg32_write(ANATOP_BASE_ADDR + 0xF8, 0x00003F00);
        reg32_write(ANATOP_BASE_ADDR + 0xF4, 0x00001300);
    } else {
        printf("the hdmi pixel clock is not supported!\n");
    }
}
