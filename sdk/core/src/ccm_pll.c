/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// For now this must come before hardware.h due to conflict with ENABLE macro.
#include "registers/regsccmanalog.h"

#include "hardware.h"
#include "registers/regsccm.h"
#include "registers/regsgpc.h"

const uint32_t PLL1_OUTPUT = 792000000;
const uint32_t PLL2_OUTPUT[] = { 528000000, 396000000, 352000000, 198000000, 594000000 };
const uint32_t PLL3_OUTPUT[] = { 480000000, 720000000, 540000000, 508235294, 454736842 };
const uint32_t PLL4_OUTPUT = 650000000;
const uint32_t PLL5_OUTPUT = 650000000;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void ccm_init(void)
{
    // ETHNET
    HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_POWERDOWN);
    HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE);
    HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_BYPASS);
    HW_CCM_ANALOG_PLL_ENET.B.DIV_SELECT = 0x3;

    /* Ungate clocks that are not enabled in a driver - need to be updated */
    HW_CCM_CCGR0_WR(0xffffffff);
    HW_CCM_CCGR1_WR(0xFFCC0FFF);    // EPIT, ESAI, GPT enabled by driver
    HW_CCM_CCGR2_WR(0xFFFFF03F);    // I2C enabled by driver
    HW_CCM_CCGR3_WR(0xffffffff);
    HW_CCM_CCGR4_WR(0x00FFFF03);    // GPMI, Perfmon enabled by driver
    HW_CCM_CCGR5_WR(0xF0FFFFCF);    // UART, SATA enabled by driver
    HW_CCM_CCGR6_WR(0xffffffff);

    /*
     * Keep default settings at reset.
     * pre_periph_clk_sel is by default at 0, so the selected output
     * of PLL2 is the main output at 528MHz.
     * => by default, ahb_podf divides by 4 => AHB_CLK@132MHz.
     * => by default, ipg_podf divides by 2 => IPG_CLK@66MHz.
     */
    HW_CCM_CBCDR.U = BF_CCM_CBCDR_AHB_PODF(3)
        | BF_CCM_CBCDR_AXI_PODF(1)
        | BF_CCM_CBCDR_IPG_PODF(1);

    /*
     * UART clock tree: PLL3 (480MHz) div-by-6: 80MHz
     * 80MHz uart_clk_podf (div-by-1) = 80MHz (UART module clock input)
     */
//    writel(readl(CCM_CSCDR1) & 0x0000003F, CCM_CSCDR1);
//     HW_CCM_CSCDR1.U = 

    /* Mask all interrupt sources that could wake up the processor when in
       a low power mode. A source is individually masked/unmasked when the 
       interrupt is enabled/disabled by the GIC/interrupt driver. */
    HW_GPC_IMR1_WR(0xFFFFFFFF);
    HW_GPC_IMR2_WR(0xFFFFFFFF);
    HW_GPC_IMR3_WR(0xFFFFFFFF);
    HW_GPC_IMR4_WR(0xFFFFFFFF);
}

uint32_t get_main_clock(main_clocks_t clock)
{
    uint32_t ret_val = 0;
    uint32_t pre_periph_clk_sel = HW_CCM_CBCMR.B.PRE_PERIPH_CLK_SEL;

    switch (clock) {
    case CPU_CLK:
        ret_val = PLL1_OUTPUT;
        break;
    case AXI_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel] / (HW_CCM_CBCDR.B.AXI_PODF + 1);
        break;
    case MMDC_CH0_AXI_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel] / (HW_CCM_CBCDR.B.MMDC_CH0_AXI_PODF + 1);
        break;
    case AHB_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel] / (HW_CCM_CBCDR.B.AHB_PODF + 1);
        break;
    case IPG_CLK:
        ret_val =
            PLL2_OUTPUT[pre_periph_clk_sel] / (HW_CCM_CBCDR.B.AHB_PODF +
                                               1) / (HW_CCM_CBCDR.B.IPG_PODF + 1);
        break;
    case IPG_PER_CLK:
        ret_val =
            PLL2_OUTPUT[pre_periph_clk_sel] / (HW_CCM_CBCDR.B.AHB_PODF +
                                               1) / (HW_CCM_CBCDR.B.IPG_PODF +
                                                     1) / (HW_CCM_CSCMR1.B.PERCLK_PODF + 1);
        break;
    case MMDC_CH1_AXI_CLK:
        ret_val = PLL2_OUTPUT[pre_periph_clk_sel] / (HW_CCM_CBCDR.B.MMDC_CH1_AXI_PODF + 1);
        break;
    default:
        break;
    }

    return ret_val;
}

uint32_t get_peri_clock(peri_clocks_t clock)
{
    uint32_t ret_val = 0;

    switch (clock)
    {
        case UART1_BAUD:
        case UART2_BAUD:
        case UART3_BAUD:
        case UART4_BAUD:
            // UART source clock is a fixed PLL3 / 6
            ret_val = PLL3_OUTPUT[0] / 6 / (HW_CCM_CSCDR1.B.UART_CLK_PODF + 1);
            break;
    
        case RAWNAND_CLK:
            ret_val = PLL3_OUTPUT[0] / (HW_CCM_CS2CDR.B.ENFC_CLK_PRED + 1) /( HW_CCM_CS2CDR.B.ENFC_CLK_PODF + 1);
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
void ccm_ccgr_config(uint32_t ccm_ccgrx, uint32_t cgx_offset, uint32_t gating_mode)
{
    if (gating_mode == CLOCK_ON)
        *(volatile uint32_t *)(ccm_ccgrx) |= cgx_offset;
    else
        *(volatile uint32_t *)(ccm_ccgrx) &= ~cgx_offset;
}

void clock_gating_config(uint32_t base_address, uint32_t gating_mode)
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
        writel((gating_mode & 0x1) << 16, IOMUXC_GPR11);
        break;
    case PERFMON2_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR4;
        cgx_offset = CG(2);
        /* specific bit 16 to enable */
        writel((gating_mode & 0x1) << 16, IOMUXC_GPR11);
        break;
    case PERFMON3_BASE_ADDR:
        ccm_ccgrx = CCM_CCGR4;
        cgx_offset = CG(3);
        /* specific bit 16 to enable */
        writel((gating_mode & 0x1) << 16, IOMUXC_GPR11);
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
    if (ccm_ccgrx != 0)
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
void ldb_clock_config(int freq, int ipu_index)
{
    uint32_t regval = 0;
    if (freq == 65000000)       //for XGA resolution
    {
        /*config pll3 PFD1 to 455M. pll3 is 480M */
        BW_CCM_ANALOG_PFD_480_PFD1_FRAC(19);

        if (ipu_index == 1) {
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
        } else {
            /*set ldb_di0_clk_sel to PLL3 PFD1 */
            regval = readl(CCM_CS2CDR) & (~0x7E00);
            regval |= 0x3600;
            writel(regval, CCM_CS2CDR);

            /*set clk_div to 7 */
            regval = readl(CCM_CSCMR2) & (~0xC00);
            regval |= 0xC00;
            writel(regval, CCM_CSCMR2);

            /*set ipu2_di0_clk_sel from ldb_di0_clk */
            regval = readl(CCM_CSCDR2) & (~0x0E07);
            regval |= 0x0603;
            writel(regval, CCM_CSCDR2);
        }
    } else {
        printf("The frequency %d for LDB is not supported yet.", freq);
    }
}

void hdmi_clock_set(int ipu_index, uint32_t pclk)
{
    uint32_t regval = 0;

    if (pclk == 74250000) {
        if (ipu_index == 1) {
            /*clk output from 540M PFD1 of PLL3 */
            regval = reg32_read(CCM_CHSCCDR) & (~0x1FF);
            reg32_write(CCM_CHSCCDR, regval | 0x168);
        } else {
            /*clk output from 540M PFD1 of PLL3 */
            regval = reg32_read(CCM_CSCDR2) & (~0x1FF);
            reg32_write(CCM_CSCDR2, regval | 0x168);
        }

        /*config PFD1 of PLL3 to be 445MHz */
        BW_CCM_ANALOG_PFD_480_PFD1_FRAC(0x13);

    } else if (pclk == 148500000) {
        if (ipu_index == 1) {
            /*clk output from 540M PFD1 of PLL3 */
            regval = reg32_read(CCM_CHSCCDR) & (~0x1FF);
            reg32_write(CCM_CHSCCDR, regval | 0x168);
        } else {
            /*clk output from 540M PFD1 of PLL3 */
            regval = reg32_read(CCM_CSCDR2) & (~0x1FF);
            reg32_write(CCM_CSCDR2, regval | 0x168);
        }
        /*config PFD1 of PLL3 to be 445MHz */
        BW_CCM_ANALOG_PFD_480_PFD1_FRAC(0x10);
	
    } else {
        printf("the hdmi pixel clock is not supported!\n");
    }
}

//! @brief Configure and enable the GPMI and BCH clocks.
//!
//! The GPMI clock is selected to be sourced from the main PLL3 clock (480 MHz), then
//! divided by 4 and again by 1. The resulting clock is 120 MHz.
void gpmi_nand_clk_setup(void)
{
    HW_CCM_ANALOG_PFD_528_CLR(BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE);

    // Gate clocks before adjusting dividers.
    clock_gating_config(GPMI_BASE_ADDR, CLOCK_OFF);

    HW_CCM_CS2CDR.B.ENFC_CLK_SEL = 2; // Select pll3 clock (480 MHz)
    HW_CCM_CS2CDR.B.ENFC_CLK_PRED = 3; // Divide by 4
    HW_CCM_CS2CDR.B.ENFC_CLK_PODF = 0; // Divide by 1

    // Ungate clocks.
    clock_gating_config(GPMI_BASE_ADDR, CLOCK_ON);
    
    HW_CCM_CCGR0.B.CG2 = CLOCK_ON; // apbhdma_hclk_enable
}

void esai_clk_sel_gate_on()
{
    uint32_t val = 0;
    val = readl(CCM_CSCMR2);
    val &= ~(0x03 << 19);
    val |= 0x01 << 19;          //source from PLL3_508
    writel(val, CCM_CSCMR2);

    clock_gating_config(ESAI1_BASE_ADDR, CLOCK_ON);
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

    //enable ENET_PLL (PLL8). done in freq_populate()
    //enale SATA_CLK in the ENET_PLL register
    HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_100M);
    
    //config ENET PLL div_select for SATA - 100MHz
    HW_CCM_ANALOG_PLL_ENET.B.DIV_SELECT = 0x2;  // 0b10-100MHz
}

/*!
 * SATA related clocks dis function
 */
void sata_clock_disable(void)
{
    //disable SATA_CLK in CCGR5.
    clock_gating_config(SATA_BASE_ADDR, CLOCK_OFF);

    //disable ENET_PLL (PLL8)
    HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_ENABLE_100M);
}

/*!
 * SATA related function to get the PHY source clock
 */
void sata_get_phy_src_clk(sata_phy_ref_clk_t * phy_ref_clk)
{
    *phy_ref_clk = CCM_PLL_ENET;
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

    return;
}

void ccm_set_lpm_wakeup_source(uint32_t irq_id, bool doEnable)
{
    uint32_t reg_offset = 0, bit_offset = 0;
    uint32_t gpc_imr = 0;

    /* calculate the offset of the register handling that interrupt ID */
    /* ID starts at 32, so for instance ID=89 is handled by IMR2 because
       the integer part of the division is reg_offset = 2 */
    reg_offset = (irq_id / 32);
    /* and the rest of the previous division is used to calculate the bit
       offset in the register, so for ID=89 this is bit_offset = 25 */
    bit_offset = irq_id - 32 * reg_offset;

    /* get the current value of the corresponding GPC_IMRx register */
    gpc_imr = readl(GPC_BASE_ADDR + GPC_IMR1_OFFSET + (reg_offset - 1) * 4);

    if (doEnable) {
        /* clear the corresponding bit to unmask the interrupt source */
        gpc_imr &= ~(1 << bit_offset);
        /* write the new mask */
        writel(gpc_imr, GPC_BASE_ADDR + GPC_IMR1_OFFSET + (reg_offset - 1) * 4);
    } else {
        /* set the corresponding bit to mask the interrupt source */
        gpc_imr |= (1 << bit_offset);
        /* write the new mask */
        writel(gpc_imr, GPC_BASE_ADDR + GPC_IMR1_OFFSET + (reg_offset - 1) * 4);
    }
}

void ccm_enter_low_power(lp_modes_t lp_mode)
{
    uint32_t ccm_clpcr = 0;

    /* if MMDC channel 1 is not used, the handshake must be masked */
    /* enable the well-biased mode - set disable core clock in wait - set
       disable oscillator in stop */
    ccm_clpcr = BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS |
        BM_CCM_CLPCR_WB_CORE_AT_LPM |
        BM_CCM_CLPCR_SBYOS | BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM | lp_mode;

    if (lp_mode == STOP_MODE)
        /* enable peripherals well-biased */
        ccm_clpcr |= BM_CCM_CLPCR_WB_PER_AT_LPM;

    HW_CCM_CLPCR_WR(ccm_clpcr);

    __asm(
             /* data synchronization barrier (caches, TLB maintenance, ...) */
             "dsb;"
             /* wait for interrupt instruction */
             "wfi;"
             /* instruction synchronization barrier (flush the pipe-line) */
             "isb;");

    return;
}

void mipi_clock_set(void)
{
	BW_CCM_ANALOG_PFD_480_PFD1_FRAC(0x10);
}

void mipi_csi2_clock_set(void)
{
    /*set VIDPLL(PLL5) to 596MHz */
    HW_CCM_ANALOG_PLL_VIDEO_WR(0x00002018);	
    HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(0x00000000);
    HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(0x00000001);
    while(!(HW_CCM_ANALOG_PLL_VIDEO_RD() & 0x80000000)); //waiting for PLL lock
    HW_CCM_ANALOG_PLL_VIDEO_CLR(0x00010000); //disable bypass VIDPLL
	
    /*select CSI0_MCLK osc_clk 24MHz, CKO1 output drives cko2 clock */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK, ALT3);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, 0x1B0B0);
    reg32_write(CCM_CCOSR, 0x10e0180);
}

void gpu_clock_config(void)
{
    HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(0xFF0D6C3);
    HW_CCM_ANALOG_PLL_VIDEO_WR(0x12002);
    while(!(HW_CCM_ANALOG_PLL_VIDEO_RD() & 0x80000000)); //waiting for PLL lock
    HW_CCM_ANALOG_PLL_VIDEO_WR(0x80002002);

    //ldb_di0_clk select PLL5
    reg32_write(CCM_CS2CDR, reg32_read(CCM_CS2CDR) & 0xfffff1ff);

    reg32_write(IOMUXC_GPR3, (reg32_read(IOMUXC_GPR3) & 0xfffffcff) | 0x80);    // ipu_mux
    reg32_write(CCM_CHSCCDR, reg32_read(CCM_CHSCCDR) | 0x3);    // ipu1_di0_clk_sel: ldb_di0_clk
    reg32_write(CCM_CSCMR2, reg32_read(CCM_CSCMR2) | 0xc00);    // ldb_di0 divided by 3.5
    reg32_write(CCM_CSCDR2, reg32_read(CCM_CSCDR2) | 0x603);
}

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
