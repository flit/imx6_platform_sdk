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
/* Nothing to do here but keep compatibility with i.MX53 */
}

void ccm_init(void)
{
    //ETHNET
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 12);    /*power down bit */
    reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 13);    /*enable bit */
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 16);    /*bypass bit */
    reg32_write_mask(HW_ANADIG_PLL_ETH_CTRL, 0x3, 0x3); /*divide bits */

    /* Ungate clocks that are not enabled in a driver - need to be updated */
    writel(0xFFFFFFFF, CCM_CCGR0);
    /* EPIT and GPT enabled by driver */
    writel(0xFFCF0FFF, CCM_CCGR1);
    /* I2C enabled by driver */
    writel(0xFFFFF03F, CCM_CCGR2);
    writel(0xFFFFFFFF, CCM_CCGR3);
    writel(0xFFFFFFFF, CCM_CCGR4);
    /* UART enabled by driver */
    writel(0xF0FFFFFF, CCM_CCGR5);
    writel(0xFFFFFFFF, CCM_CCGR6);
    writel(0xFFFFFFFF, CCM_CCGR7);

    /*
     * Keep default settings at reset.
     * pre_periph_clk_sel is by default at 0, so the selected output
     * of PLL2 is the main output at 528MHz.
     * => by default, ahb_podf divides by 4 => AHB_CLK@132MHz.
     * => by default, ipg_podf divides by 2 => IPG_CLK@66MHz.
     */
    writel(0x00018D00, CCM_CBCDR);
    writel(0x00020324, CCM_CBCMR);

    /*
     * UART clock tree: PLL3 (480MHz) div-by-6: 80MHz
     * 80MHz uart_clk_podf (div-by-1) = 80MHz (UART module clock input)
     */
    writel(readl(CCM_CSCDR1) & 0x0000003F, CCM_CSCDR1);

    /* Power up 480MHz PLL */
//    reg32_write_mask(HW_ANADIG_USB1_PLL_480_CTRL_RW, 0x00001000, 0x00001000);

    /* Enable 480MHz PLL */
//    reg32_write_mask(HW_ANADIG_USB1_PLL_480_CTRL_RW, 0x00002000, 0x00002000);

    /* config IPU hsp clock, derived from AXI B */
//    temp = *(volatile uint32_t *)(CCM_BASE_ADDR + CLKCTL_CBCMR);
//    temp &= ~(0x000000C0);
//    temp |= 0x00000040;
//    *(volatile uint32_t *)(CCM_BASE_ADDR + CLKCTL_CBCMR) = temp;
    /* now set perclk_pred1 to div-by-2 */
//    temp = *(volatile uint32_t *)(CCM_BASE_ADDR + CLKCTL_CBCDR);
//    temp &= ~(0x00380000);
//    temp |= 0x00080000;
//    *(volatile uint32_t *)(CCM_BASE_ADDR + CLKCTL_CBCDR) = temp;
}

/*!
 * This function returns the frequency of a clock.
 */
uint32_t get_main_clock(enum main_clocks clock)
{
    uint32_t ret_val = 0;

    switch (clock) {
    case CPU_CLK:
        ret_val = PLL1_OUTPUT;
        break;
    case AXI_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / axi_podf_;
        break;
    case MMDC_CH0_AXI_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / mmdc_ch0_axi_podf_;
        break;
    case AHB_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / ahb_podf_;
        break;
    case IPG_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / ahb_podf_ / ipg_podf_;
        break;
    case IPG_PER_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / ahb_podf_ / ipg_podf_ / perclk_podf_;
        break;
    case MMDC_CH1_AXI_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel_] / mmdc_ch1_axi_podf_;
        break;
    default:
        break;
    }

    return ret_val;
}

/*!
 * This function returns the frequency of a clock.
 */
uint32_t get_peri_clock(enum peri_clocks clock)
{
    uint32_t ret_val = 0;

    switch (clock) {
    case UART1_BAUD:
    case UART2_BAUD:
    case UART3_BAUD:
    case UART4_BAUD:
        /* UART source clock is a fixed PLL3 / 6 */
        ret_val = PLL3_OUTPUT[0] / 6 / uart_clk_podf_;
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
        ccm_ccgr_config(CCM_CCGR1, CG(10), gating_mode);
        break;
    case I2C1_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR2, CG(3), gating_mode);
        break;
    case I2C2_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR2, CG(4), gating_mode);
        break;
    case I2C3_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR2, CG(5), gating_mode);
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
    writel(0x00010800, CCM_CSCDR3);
}

/*!
 * config ldb clock as per the display resolution
 *
 * ldb clock is derived from PLL5
 */
void ldb_clock_config(int freq)
{
    uint32_t regval = 0;
    if (freq == 65000000)       //for XGA resolution
    {
        /*config pll3 PFD1 to 455M. pll3 is 480M */
        writel(0x1311130C, ANATOP_BASE_ADDR + 0xF0);

        /*set ldb_di0_clk_sel to PLL3 PFD1 */
        regval = readl(CCM_CS2CDR) & (~0x7E00);
        regval |= 0x3600;
        writel(regval, CCM_CS2CDR);

        /*set clk_div to 7 */
        regval = readl(CCM_CSCMR2) & (~0xC00);
        regval |= 0xC00;
        writel(regval, CCM_CSCMR2);

        /*set ipu1_di0_clk_sel from ldb_di0_clk */
        regval = readl(CCM_CHSCCDR) & (~0x0E07);
        regval |= 0x0603;
        writel(regval, CCM_CHSCCDR);
        regval = readl(CCM_CSCDR2) & (~0x0E07);
        regval |= 0x0603;
        writel(regval, CCM_CSCDR2);
    } else {
        printf("The frequency %d for LDB is not supported yet.", freq);
    }
}

void hdmi_clock_set(uint32_t pclk)
{
    uint32_t regval = 0;

    if (pclk == 74250000) {
        /*clk output from 540M PFD1 of PLL3 */
        regval = readl(CCM_CHSCCDR) & (~0x1FF);
        writel(regval | 0x168, CCM_CHSCCDR);

        /*config PLL5 to be 594MHz */
        writel(0x00003F00, ANATOP_BASE_ADDR + 0xF8);
        writel(0x00001300, ANATOP_BASE_ADDR + 0xF4);
    } else if (pclk == 148500000) {
        /*clk output from 540M PFD1 of PLL3 */
        regval = readl(CCM_CHSCCDR) & (~0x1FF);
        writel(regval | 0x158, CCM_CHSCCDR);

        /*config PLL5 to be 594MHz */
        writel(0x00003F00, ANATOP_BASE_ADDR + 0xF8);
        writel(0x00001300, ANATOP_BASE_ADDR + 0xF4);
    } else {
        printf("the hdmi pixel clock is not supported!\n");
    }
}
