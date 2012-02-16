/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
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
    /* EPIT, ESAI, GPT enabled by driver */
    writel(0xFFCC0FFF, CCM_CCGR1);
    /* I2C enabled by driver */
    writel(0xFFFFF03F, CCM_CCGR2);
    writel(0xFFFFFFFF, CCM_CCGR3);
    /* GPMI, Perfmon enabled by driver */
    writel(0x00FFFF03, CCM_CCGR4);
    /* UART, SATA enabled by driver */
    writel(0xF0FFFFCF, CCM_CCGR5);
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
//    writel(0x00020324, CCM_CBCMR);

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
    uint32_t ccm_ccgrx = 0, cgx_offset = 0;

    switch (base_address) {
    case UART1_BASE_ADDR:
    case UART2_BASE_ADDR:
    case UART3_BASE_ADDR:
    case UART4_BASE_ADDR:
    case UART5_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR5;
        cgx_offset = CG(13) | CG(12);
        break;
    case SSI3_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR5;
        cgx_offset = CG(11);
        break;
    case SSI2_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR5;
        cgx_offset = CG(10);
        break;
    case SSI1_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR5;
        cgx_offset = CG(9);
        break;
    case SPDIF_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR5;
        cgx_offset = CG(7);
        break;
    case SPBA_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR5;
        cgx_offset = CG(6);
        break;
    case SDMA_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR5;
        cgx_offset = CG(3);
        break;
    case SATA_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR5;
        cgx_offset = CG(2);
        break;
    case EPIT1_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR1;
        cgx_offset = CG(6);
        break;
    case EPIT2_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR1;
        cgx_offset = CG(7);
        break;
    case GPT_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR1;
        cgx_offset = CG(10);
        break;
    case I2C1_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR2;
        cgx_offset = CG(3);
        break;
    case I2C2_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR2;
        cgx_offset = CG(4);
        break;
    case I2C3_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR2;
        cgx_offset = CG(5);
        break;
    case PERFMON1_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR4;
        cgx_offset = CG(1);
        /* specific bit 16 to enable */
        writel((gating_mode & 0x1) << 16 , IOMUXC_GPR11);
        break;
    case PERFMON2_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR4;
        cgx_offset = CG(2);
        /* specific bit 16 to enable */
        writel((gating_mode & 0x1) << 16 , IOMUXC_GPR11);
        break;
    case PERFMON3_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR4;
        cgx_offset = CG(3);
        /* specific bit 16 to enable */
        writel((gating_mode & 0x1) << 16 , IOMUXC_GPR11);
        break;
    case GPMI_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR4;
        cgx_offset = CG(15) | CG(14) | CG(13) | CG(12);
        break;
    case ESAI1_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR1;
        cgx_offset = CG(8);
        break;
    default:
        break;
    }

    /* apply changes only if a valid address was found */
    if(ccm_ccgrx != 0)
        ccm_ccgr_config(ccm_ccgrx, cgx_offset, gating_mode);
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
 * ldb clock is derived from PLL5, ldb on ipu1
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
        regval = readl(CCM_CSCDR2) & (~0x0E00);
        regval |= 0x0600;
        writel(regval, CCM_CSCDR2);
    } else {
        printf("The frequency %d for LDB is not supported yet.", freq);
    }
}

void hdmi_clock_set(int ipu_index, uint32_t pclk)
{
    uint32_t regval = 0;

    if (pclk == 74250000) {
        writel(7500000, ANATOP_BASE_ADDR + 0xB0);   //set the nominator
        writel(1000000, ANATOP_BASE_ADDR + 0xC0);   //set the denominator
        writel(0x00012018, ANATOP_BASE_ADDR + 0xA0);    //bypass VIDPLL

        while (!(readl(ANATOP_BASE_ADDR + 0xA0) & 0x80000000)) ;    //waiting for the pll lock

        writel(0x00010000, ANATOP_BASE_ADDR + 0xA8);    //disable bypass VIDPLL

        /*clk output from 540M PFD1 of PLL3 */
        regval = readl(CCM_CHSCCDR) & (~0x1FF);
        writel(regval | 0xB8, CCM_CHSCCDR);
        regval = readl(CCM_CSCDR2) & (~0x1FF);
        writel(regval | 0xB8, CCM_CSCDR2);
    } else if (pclk == 148500000) {
        writel(500000, ANATOP_BASE_ADDR + 0xB0);    //set the nominator
        writel(1000000, ANATOP_BASE_ADDR + 0xC0);   //set the denominator
        writel(0x00012031, ANATOP_BASE_ADDR + 0xA0);    //bypass VIDPLL

        while (!(readl(ANATOP_BASE_ADDR + 0xA0) & 0x80000000)) ;    //waiting for the pll lock

        writel(0x00010000, ANATOP_BASE_ADDR + 0xA8);    //disable bypass VIDPLL

        /*clk output from 540M PFD1 of PLL3 */
        if (ipu_index == 1) {
            regval = readl(CCM_CHSCCDR) & (~0x1FF);
            writel(regval | 0xB8, CCM_CHSCCDR);
        } else {
            regval = readl(CCM_CSCDR2) & (~0x1FF);
            writel(regval | 0xB8, CCM_CSCDR2);
        }
    } else {
        printf("the hdmi pixel clock is not supported!\n");
    }
}

void gpmi_nand_clk_setup(void)
{
    *(volatile uint32_t *)(HW_ANADIG_PFD_528_RW) &= ~(0x00800000);

clock_gating_config(GPMI_BASE_ADDR, CLOCK_OFF);

    *(volatile uint32_t *)(CCM_CS2CDR) &= ~(0x00030000);
    *(volatile uint32_t *)(CCM_CS2CDR) |= 0x00020000;
    *(volatile uint32_t *)(CCM_CS2CDR) &= ~(0x07fc0000);
    *(volatile uint32_t *)(CCM_CS2CDR) |= ((uint32_t) (4 << 18) | (3 << 21));

    clock_gating_config(GPMI_BASE_ADDR, CLOCK_ON);
}

void esai_clk_sel_gate_on()
{
    uint32_t val = 0;
#if ((defined MX61_ARD) || (defined MX61_SABRE_TABLET) || (defined MX61_SABRE_LITE) || (defined MX61_EVB))
    val = readl(CCM_CSCMR2);
    val &= ~(0x03 << 19);
    val |= 0x01 << 19;          //source from PLL3_508
    writel(val, CCM_CSCMR2);

    clock_gating_config(ESAI1_BASE_ADDR, CLOCK_ON);
#endif
}

/*!
 * SATA related clocks enable function
 */
void sata_clock_enable(void)
{
    // Set SATA timings     0x05932046
    reg32_write(0x020E0034, 0x05932044);
    hal_delay_us(1000);

    // Enable SATA PLL
    reg32_write(0x020E0034, 0x05932046);
    hal_delay_us(1000);

    //enable SATA_CLK in CCGR5
    clock_gating_config(SATA_BASE_ADDR, CLOCK_ON);

    //enable ENET_PLL (PLL8) in ANADIG. done in freq_populate()
    //enale SATA_CLK in the ENET_PLL register
    reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 20);    /* set ENABLE_SATA */
    //config ENET PLL div_select for SATA - 100MHz
    reg32_write_mask(HW_ANADIG_PLL_ETH_CTRL, 0x2, 0x3); /* 0b10-100MHz */
}

/*!
 * SATA related clocks dis function
 */
void sata_clock_disable(void)
{
    //disable SATA_CLK in CCGR5.
    clock_gating_config(SATA_BASE_ADDR, CLOCK_OFF);

    //disable ENET_PLL (PLL8) in ANADIG
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 20);    /* clear ENABLE_SATA */
}

/*!
 * SATA related function to get the PHY source clock
 */
void sata_get_phy_src_clk(sata_phy_ref_clk_t *phy_ref_clk)
{
    *phy_ref_clk = ANATOP_ENET_PLL;
}

/*!
 * SPDIF clock configuration
 * Use the default setting as follow:
 * CDCDR[spdif0_clk_sel](PLL3)->CDCDR[spdif0_clk_pred](div2)->CDCDR[spdif0_clk_podf](div8)-> spdif0_clk_root, so
 * the freqency of spdif0_clk should be 480/2/8 = 30MHz.
 */
void spdif_clk_cfg(void)
{
    unsigned int val;

    val = readl(CCM_BASE_ADDR + CCM_CDCDR_OFFSET);
    //CDCDR[spdif0_clk_sel](PLL3)
    val &= ~(0x03 << 20);
    val |= 0x03 << 20;
    //CDCDR[spdif0_clk_pred](div2)
    val &= ~(0x07 << 25);
    val |= 0x01 << 25;
    //CDCDR[spdif0_clk_podf](div8)
    val &= ~(0x07 << 22);
    val |= 0x07 << 22;
    writel(val, CCM_BASE_ADDR + CCM_CDCDR_OFFSET);

    clock_gating_config(SPDIF_BASE_ADDR, CLOCK_ON);
}

#define CORE_WB (1 << 17)
#define WAIT_MODE   0x1
#define STOP_MODE   0x2

void enter_wait_state(void)
{
    uint32_t ccm_clpcr;
    uint8_t sel;

    ccm_clpcr = readl(CCM_BASE_ADDR + CCM_CLPCR_OFFSET);
    ccm_clpcr |= CORE_WB | WAIT_MODE;
    writel(ccm_clpcr , CCM_BASE_ADDR + CCM_CLPCR_OFFSET);

    printf("CCM_CLPCR : 0x%X \n",ccm_clpcr);
    printf("GPC_ISR1 : 0x%X \n",readl(GPC_BASE_ADDR + GPC_ISR1_OFFSET));
    printf("GPC_ISR2 : 0x%X \n",readl(GPC_BASE_ADDR + GPC_ISR2_OFFSET));
    printf("GPC_ISR3 : 0x%X \n",readl(GPC_BASE_ADDR + GPC_ISR3_OFFSET));
    printf("GPC_ISR4 : 0x%X \n",readl(GPC_BASE_ADDR + GPC_ISR4_OFFSET));

    writel(0xFFFFFFFF ,GPC_BASE_ADDR + GPC_IMR1_OFFSET);
    writel(0xFFFFFFFF ,GPC_BASE_ADDR + GPC_IMR2_OFFSET);
    writel(0xFFFFFFFF ,GPC_BASE_ADDR + GPC_IMR3_OFFSET);
    writel(0xFFFFFFFF ,GPC_BASE_ADDR + GPC_IMR4_OFFSET);

    printf("Press a key to enter wait state...\n");

    do {
        sel = getchar();
    } while (sel == (uint8_t) 0xFF);

/* Wait for interrupt instruction */
    __asm(
            "mov r0, #0x0;"
            "mcr p15, 0, r0, c7, c0, 4;"
            "nop;"
            "nop;"
            "nop;"
            "nop;"
            "nop;"
          );

    printf("Fail !!!!\n");

}

void ccm_lpm_test(void)
{
    printf("Low power modes test\n");

    enter_wait_state();

    while(1);
}
