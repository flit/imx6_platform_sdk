/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

#define REF_IN_CLK_NUM  4
struct fixed_pll_mfd {
    uint32_t ref_clk_hz;
    uint32_t mfd;
};

const struct fixed_pll_mfd fixed_mfd[REF_IN_CLK_NUM] = {
    {0, 0},                     // reserved
    {0, 0},                     // reserved
    {FREQ_24MHZ, 24 * 16},      // 384
    {0, 0},                     // reserved
};

static volatile uint32_t *pll_base[] = {
    REG32_PTR(PLL1_BASE_ADDR),
    REG32_PTR(PLL2_BASE_ADDR),
    REG32_PTR(PLL3_BASE_ADDR),
    REG32_PTR(PLL4_BASE_ADDR),
};

/* The function prog_pll sets up all four PLLs as follows:
    PLL1 800MHz
    PLL2 400MHz
    PLL3 216MHz
    PLL4 595MHz
 */
void prog_pll(void)
{
    // Clear ESDCTL configuration bit to allow handshake
    reg32clrbit(ESDCTL_REGISTERS_BASE_ADDR + ESDCTL_ESDSCR_OFFSET, 15);
    // disabling automatic restart on PLLs
    reg32clrbit(PLL1_BASE_ADDR + PLL_DP_CONFIG, 1);
    reg32clrbit(PLL2_BASE_ADDR + PLL_DP_CONFIG, 1);
    reg32clrbit(PLL3_BASE_ADDR + PLL_DP_CONFIG, 1);
    reg32clrbit(PLL4_BASE_ADDR + PLL_DP_CONFIG, 1);
    // Program PLL1 to 800Mhz - assuming 24MHz OSC as reference
    reg32_write(PLL1_BASE_ADDR + PLL_DP_CTL, 0x00001222);
    reg32_write(PLL1_BASE_ADDR + PLL_DP_OP, 0x00000080);    //MFI=8; PDF=0
    reg32_write(PLL1_BASE_ADDR + PLL_DP_MFD, 8);    //MFD=9
    reg32_write(PLL1_BASE_ADDR + PLL_DP_MFN, 3);    //MFN=3
    // Program PLL2 to 400Mhz - assuming 24MHz OSC as reference
    reg32_write(PLL2_BASE_ADDR + PLL_DP_CTL, 0x00001222);
    reg32_write(PLL2_BASE_ADDR + PLL_DP_OP, 0x00000081);    //MFI=8; PDF=1
    reg32_write(PLL2_BASE_ADDR + PLL_DP_MFD, 8);    //MFD=9
    reg32_write(PLL2_BASE_ADDR + PLL_DP_MFN, 3);    //MFN=3
    // Program PLL3 freq to 300MHz - assuming 24MHz OSC as reference
    // Note, PLL3 will later be changed to 216MHz
    reg32_write(PLL3_BASE_ADDR + PLL_DP_CTL, 0x00001222);
    reg32_write(PLL3_BASE_ADDR + PLL_DP_OP, 0x00000061);    //MFI=6; PDF=1
    reg32_write(PLL3_BASE_ADDR + PLL_DP_MFD, 999);  //MFD=999
    reg32_write(PLL3_BASE_ADDR + PLL_DP_MFN, 250);  //MFN=250
    // Program PLL4 to 595Mhz - assuming 24MHz OSC as reference
    reg32_write(PLL4_BASE_ADDR + PLL_DP_CTL, 0x00001222);
    reg32_write(PLL4_BASE_ADDR + PLL_DP_OP, 0x00000060);    //MFI=6; PDF=0
    reg32_write(PLL4_BASE_ADDR + PLL_DP_MFD, 999);  //MFD=999
    reg32_write(PLL4_BASE_ADDR + PLL_DP_MFN, 198);  //MFN=198
    /* Sequence for re-programming PLL1
     * Since ARM runs off of PLL1, a particular sequence should be followed
     * such that the ARM clock can be moved safely from PLL1 to PLL3 to allow
     * re-programing of PLL1.
     * The sequence is as follows:
     * Choose PLL3 to source step clk (periph_apm_clk)
     * Set pll1_periph_clk_sel to "1" - DDR/axi_a is now sourced from PLL3
     */
    // switch ARM to PLL3 (still at original/default slow frequency)
    reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CCSR, 0x00000180, 0x00000180);  // step clk to PLL3
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CCSR, 2);    // set ARM to step clk (periph_apm_clk)
    // added handshake MK
    while (reg32_read(CCM_BASE_ADDR + CLKCTL_CDHIPR)) ; // verify handshake is over

    // restart PLL1
    reg32setbit(PLL1_BASE_ADDR + PLL_DP_CTL, 4);

    // Wait for PLL 1 to lock
    while (!((reg32_read(PLL1_BASE_ADDR + PLL_DP_CTL) & 1))) ;

    // switch ARM back to PLL1 (now full speed)
    reg32clrbit(CCM_BASE_ADDR + CLKCTL_CCSR, 2);    // set ARM to PLL1
    /* Sequence for re-programming PLL2
     * Since DDR runs off of PLL2, a particular sequence should be followed
     * such that the DDR clock can be moved safely from PLL2 to PLL3 to allow
     * re-programing of PLL2.
     * The sequence is as follows:
     * Program PLL3 to 300MHz, DDR clock will be at 300MHz
     * Set periph_apm_sel to PLL3, choosing PLL3 to source periph_apm_clk
     * Set periph_clk_sel to "1" - DDR/axi_a is now sourced from PLL3
     * Program PLL2 to 400MHz
     * Set PLL2 periph_clk_sel to "0" - pll2_sw_clk = PLL2
     * Set step clk back to lp_apm
     */
    // re-start PLL3 (above it was programmed to 300MHz)
    reg32setbit(PLL3_BASE_ADDR + PLL_DP_CTL, 4);

    // Wait for PLL 3 to lock
    while (!((reg32_read(PLL3_BASE_ADDR + PLL_DP_CTL) & 1))) ;

    /* In CBCMR, select PLL3 to source periph_apm_clk */
    reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CBCMR, 0x00001000, 0x00003000);

    /* The following moves DDR clock to PLL3 and sets to 300MHz */
    /* Note: periph_apm_clk was selected to be sourced from PLL3 per above, and PLL3 should now be 300MHz */
    reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CBCDR, 0x02000000, 0x02000000); // set pll2_sw_clk to periph_apm_clk (periph_clk_sel=1)

    reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CBCDR, 0x00000000, 0x00070000); // axi_a_podf = div-by-1
    /* Now re-start PLL2 at new freq of 400MHz */
    reg32setbit(PLL2_BASE_ADDR + PLL_DP_CTL, 4);

    // Wait for PLL 2 to lock
    while (!((reg32_read(PLL2_BASE_ADDR + PLL_DP_CTL) & 1))) ;

    /* Before setting pll2_sw_clk (and DDR clock) back to PLL2, first check to see if the axi_a_podf is greater
     * than div-by-1. If it is div-by-1, set to div-by-2, this will ensure the DDR clock is at a safe frequency
     * prior to switching over to PLL2 */
    /*    if((reg32_read(CCM_BASE_ADDR + CLKCTL_CBCDR)&(0x00070000))==0)
       {
       reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CBCDR, 0x00010000, 0x00070000);    // axi_a_podf = div-by-2
       }
     */
    /* Set pll2_sw_clk back to PLL2 now at 400MHz */
    reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CBCDR, 0x00000000, 0x02000000); // set pll2_sw_clk to periph_apm_clk (periph_clk_sel=0)
    /* Make sure DDR clock is set to axi_a and that axi_a_podf is set to div-by-1 */
    /* Set axi_podf to div-by-1, DDR will be 400MHz */
    reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CBCDR, 0x00000000, 0x00070000); // axi_a_podf = div-by-1
    /* Set DDR clock to be sourced from axi_a */
    reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CBCMR, 0x00000000, 0x00000C00); // ddr_clk_sel = axi_a
    /* set step_clk back to default (lp_apm)     */
    reg32_write_mask(CCM_BASE_ADDR + CLKCTL_CCSR, 0x00000000, 0x00000180);
    /* Set PLL3 to 216MHz
     * was set to 300MHz as an intermediate step above
     */
    // Program PLL3 to 216Mhz - assuming 24MHz OSC as reference
    reg32_write(PLL3_BASE_ADDR + PLL_DP_CTL, 0x00000222);
    reg32_write(PLL3_BASE_ADDR + PLL_DP_OP, 0x00000081);    //MFI=8; PDF=2
    reg32_write(PLL3_BASE_ADDR + PLL_DP_MFD, 0);    //MFD=0
    reg32_write(PLL3_BASE_ADDR + PLL_DP_MFN, 1);    //MFN=1
    // re-start PLL3
    reg32setbit(PLL3_BASE_ADDR + PLL_DP_CTL, 4);

    // Wait for PLL 3 to lock
    while (!((reg32_read(PLL3_BASE_ADDR + PLL_DP_CTL) & 1))) ;

    /*
     * Re-start PLL4 for 595MHz
     */
    reg32setbit(PLL4_BASE_ADDR + PLL_DP_CTL, 4);

    // Wait for PLL 4 to lock
    while (!((reg32_read(PLL4_BASE_ADDR + PLL_DP_CTL) & 1))) ;

    // re-enable automatic restart on PLLs
    reg32setbit(PLL1_BASE_ADDR + PLL_DP_CONFIG, 1);
    reg32setbit(PLL2_BASE_ADDR + PLL_DP_CONFIG, 1);
    reg32setbit(PLL3_BASE_ADDR + PLL_DP_CONFIG, 1);
    reg32setbit(PLL4_BASE_ADDR + PLL_DP_CONFIG, 1);
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
        ccm_ccgr_config(CCM_CCGR1, CG(4)|CG(3), gating_mode);
        break;
    case UART2_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR1, CG(6)|CG(5), gating_mode);
        break;
    case UART3_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR1, CG(8)|CG(7), gating_mode);
        break;
    case UART4_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR7, CG(5)|CG(4), gating_mode);
        break;
    case UART5_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR7, CG(7)|CG(6), gating_mode);
        break;
    case EPIT1_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR2, CG(2)|CG(1), gating_mode);
        break;
    case EPIT2_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR2, CG(4)|CG(3), gating_mode);
        break;
    case GPT_BASE_ADDR:
        ccm_ccgr_config(CCM_CCGR2, CG(10)|CG(9), gating_mode);
        break;


    default:
        break;
    }

}

/*!
 * This function returns the low power audio clock.
 */
uint32_t get_lp_apm(void)
{
    uint32_t ret_val = 0;
    uint32_t ccsr = readl(CCM_BASE_ADDR + CLKCTL_CCSR);

    if (((ccsr >> 10) & 1) == 0) {
        ret_val = FREQ_24MHZ;
    } else {
        ret_val = pll_clock(PLL4);
    }

    return ret_val;
}

/*!
 * This function returns the periph_clk.
 */
uint32_t get_periph_clk(void)
{
    uint32_t ret_val = 0, clk_sel;
    uint32_t cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    uint32_t cbcmr = readl(CCM_BASE_ADDR + CLKCTL_CBCMR);

    if (((cbcdr >> 25) & 1) == 0) {
        ret_val = pll_clock(PLL2);
    } else {
        clk_sel = (cbcmr >> 12) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1);
        } else if (clk_sel == 1) {
            ret_val = pll_clock(PLL3);
        } else if (clk_sel == 2) {
            ret_val = get_lp_apm();
        }
    }

    return ret_val;
}

/*!
 * This function returns the PLL output value in Hz based on pll.
 */
uint32_t pll_clock(enum plls pll)
{
    uint64_t mfi, mfn, mfd, pdf, ref_clk, pll_out, sign;
    uint64_t dp_ctrl, dp_op, dp_mfd, dp_mfn, clk_sel;
    uint8_t dbl = 0;
    dp_ctrl = pll_base[pll][PLL_DP_CTL >> 2];
    clk_sel = GET_FIELD(dp_ctrl, 2, 8);
    ref_clk = fixed_mfd[clk_sel].ref_clk_hz;

    if ((pll_base[pll][PLL_DP_CTL >> 2] & 0x80) == 0) {
        dp_op = pll_base[pll][PLL_DP_OP >> 2];
        dp_mfd = pll_base[pll][PLL_DP_MFD >> 2];
        dp_mfn = pll_base[pll][PLL_DP_MFN >> 2];
    } else {
        dp_op = pll_base[pll][PLL_DP_HFS_OP >> 2];
        dp_mfd = pll_base[pll][PLL_DP_HFS_MFD >> 2];
        dp_mfn = pll_base[pll][PLL_DP_HFS_MFN >> 2];
    }

    pdf = dp_op & 0xF;
    mfi = (dp_op >> 4) & 0xF;
    mfi = (mfi <= 5) ? 5 : mfi;
    mfd = dp_mfd & 0x07FFFFFF;
    mfn = dp_mfn & 0x07FFFFFF;
    sign = (mfn < 0x4000000) ? 0 : 1;
    mfn = (mfn <= 0x4000000) ? mfn : (0x8000000 - mfn);
    dbl = ((dp_ctrl >> 12) & 0x1) + 1;
    dbl = dbl * 2;

    if (sign == 0) {
        pll_out = (dbl * ref_clk * mfi + ((dbl * ref_clk * mfn) / (mfd + 1))) / (pdf + 1);
    } else {
        pll_out = (dbl * ref_clk * mfi - ((dbl * ref_clk * mfn) / (mfd + 1))) / (pdf + 1);
    }

    return (uint32_t) pll_out;
}

/*!
 * This function returns the emi_core_clk_root clock.
 */
uint32_t get_emi_core_clk(void)
{
    uint32_t cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    uint32_t clk_sel = 0, max_pdf = 0, peri_clk = 0, ahb_clk = 0;
    uint32_t ret_val = 0;
    max_pdf = (cbcdr >> 10) & 0x7;
    peri_clk = get_periph_clk();
    ahb_clk = peri_clk / (max_pdf + 1);
    clk_sel = (cbcdr >> 26) & 1;

    if (clk_sel == 0) {
        ret_val = peri_clk;
    } else {
        ret_val = ahb_clk;
    }

    return ret_val;
}

/*!
 * This function returns the main clock value in Hz.
 */
uint32_t get_main_clock(enum main_clocks clk)
{
    uint32_t pdf, max_pdf, ipg_pdf, nfc_pdf, clk_sel;
    uint32_t pll, ret_val = 0;
    uint32_t cacrr = readl(CCM_BASE_ADDR + CLKCTL_CACRR);
    uint32_t cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    uint32_t cbcmr = readl(CCM_BASE_ADDR + CLKCTL_CBCMR);
    uint32_t cscmr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCMR1);
    uint32_t cscdr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR1);

    switch (clk) {
    case CPU_CLK:
        pdf = cacrr & 0x7;
        pll = pll_clock(PLL1);
        ret_val = pll / (pdf + 1);
        break;
    case AHB_CLK:
        max_pdf = (cbcdr >> 10) & 0x7;
        pll = get_periph_clk();
        ret_val = pll / (max_pdf + 1);
        break;
    case IPG_CLK:
        max_pdf = (cbcdr >> 10) & 0x7;
        ipg_pdf = (cbcdr >> 8) & 0x3;
        pll = get_periph_clk();
        ret_val = pll / ((max_pdf + 1) * (ipg_pdf + 1));
        break;
    case IPG_PER_CLK:
        clk_sel = cbcmr & 1;

        if (clk_sel == 0) {
            clk_sel = (cbcmr >> 1) & 1;
            pdf = (((cbcdr >> 6) & 3) + 1) * (((cbcdr >> 3) & 7) + 1) * ((cbcdr & 7) + 1);

            if (clk_sel == 0) {
                ret_val = get_periph_clk() / pdf;
            } else {
                ret_val = get_lp_apm() / pdf;
            }
        } else {
            /* Same as IPG_CLK */
            max_pdf = (cbcdr >> 10) & 0x7;
            ipg_pdf = (cbcdr >> 8) & 0x3;
            pll = get_periph_clk();
            ret_val = pll / ((max_pdf + 1) * (ipg_pdf + 1));
        }

        break;
    case DDR_CLK:
        clk_sel = (cbcmr >> 10) & 3;
        pll = get_periph_clk();

        if (clk_sel == 0) {
            /* AXI A */
            pdf = (cbcdr >> 16) & 0x7;
        } else if (clk_sel == 1) {
            /* AXI B */
            pdf = (cbcdr >> 19) & 0x7;
        } else if (clk_sel == 2) {
            /* EMI SLOW CLOCK ROOT */
            pll = get_emi_core_clk();
            pdf = (cbcdr >> 22) & 0x7;
        } else if (clk_sel == 3) {
            /* AHB CLOCK */
            pdf = (cbcdr >> 10) & 0x7;
        }

        ret_val = pll / (pdf + 1);
        break;
    case NFC_CLK:
        pdf = (cbcdr >> 22) & 0x7;
        nfc_pdf = (cbcdr >> 13) & 0x7;
        pll = get_emi_core_clk();
        ret_val = pll / ((pdf + 1) * (nfc_pdf + 1));
        break;
    case USB_CLK:
        clk_sel = (cscmr1 >> 22) & 3;

        if (clk_sel == 0) {
            pll = pll_clock(PLL1);
        } else if (clk_sel == 1) {
            pll = pll_clock(PLL2);
        } else if (clk_sel == 2) {
            pll = pll_clock(PLL3);
        } else if (clk_sel == 3) {
            pll = get_lp_apm();
        }

        pdf = (cscdr1 >> 8) & 0x7;
        max_pdf = (cscdr1 >> 6) & 0x3;
        ret_val = pll / ((pdf + 1) * (max_pdf + 1));
        break;
    case VPU_CLK:
        clk_sel = (cbcmr >> 14) & 3;
        pll = get_periph_clk();

        if (clk_sel == 0) {
            /* AXI A */
            pdf = (cbcdr >> 16) & 0x7;
        } else if (clk_sel == 1) {
            /* AXI B */
            pdf = (cbcdr >> 19) & 0x7;
        } else if (clk_sel == 2) {
            /* EMI SLOW CLOCK ROOT */
            pll = get_emi_core_clk();
            pdf = (cbcdr >> 22) & 0x7;
        } else if (clk_sel == 3) {
            /* AHB CLOCK */
            pdf = (cbcdr >> 10) & 0x7;
        }

        ret_val = pll / (pdf + 1);
        break;
    default:
        printf("Unknown clock: %d\n", clk);
        break;
    }

    return ret_val;
}

/*!
 * This function returns the peripheral clock value in Hz.
 */
uint32_t get_peri_clock(enum peri_clocks clk)
{
    uint32_t ret_val = 0, pdf, pre_pdf, pre_pdf1, clk_sel;
    uint32_t cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    uint32_t cscmr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCMR1);
    uint32_t cscdr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR1);
    uint32_t cscdr2 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR2);
    uint32_t cs1cdr = readl(CCM_BASE_ADDR + CLKCTL_CS1CDR);
    uint32_t cs2cdr = readl(CCM_BASE_ADDR + CLKCTL_CS2CDR);

    switch (clk) {
    case UART1_BAUD:
    case UART2_BAUD:
    case UART3_BAUD:
        pre_pdf = (cscdr1 >> 3) & 0x7;
        pdf = cscdr1 & 0x7;
        clk_sel = (cscmr1 >> 24) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 1) {
            ret_val = pll_clock(PLL2) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 2) {
            ret_val = pll_clock(PLL3) / ((pre_pdf + 1) * (pdf + 1));
        } else {
            ret_val = get_lp_apm() / ((pre_pdf + 1) * (pdf + 1));
        }
        break;
    case SSI1_BAUD:
        pre_pdf = (cs1cdr >> 6) & 0x7;
        pdf = cs1cdr & 0x3F;
        clk_sel = (cscmr1 >> 14) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 0x1) {
            ret_val = pll_clock(PLL2) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 0x2) {
            ret_val = pll_clock(PLL3) / ((pre_pdf + 1) * (pdf + 1));
        } else {
            ret_val = CKIH / ((pre_pdf + 1) * (pdf + 1));
        }
        break;
    case SSI2_BAUD:
        pre_pdf = (cs2cdr >> 6) & 0x7;
        pdf = cs2cdr & 0x3F;
        clk_sel = (cscmr1 >> 12) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 0x1) {
            ret_val = pll_clock(PLL2) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 0x2) {
            ret_val = pll_clock(PLL3) / ((pre_pdf + 1) * (pdf + 1));
        } else {
            ret_val = CKIH / ((pre_pdf + 1) * (pdf + 1));
        }
        break;
    case SPI1_CLK:
    case SPI2_CLK:
        pre_pdf = (cscdr2 >> 25) & 0x7;
        pdf = (cscdr2 >> 19) & 0x3F;
        clk_sel = (cscmr1 >> 4) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 1) {
            ret_val = pll_clock(PLL2) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 2) {
            ret_val = pll_clock(PLL3) / ((pre_pdf + 1) * (pdf + 1));
        } else {
            ret_val = get_lp_apm() / ((pre_pdf + 1) * (pdf + 1));
        }
        break;
    case EPIT1_CLK:
    case EPIT2_CLK:
        pre_pdf1 = (cbcdr >> 6) & 0x3;
        pre_pdf = (cbcdr >> 3) & 0x7;
        pdf = cbcdr & 0x7;

        ret_val = get_lp_apm() / ((pre_pdf1 + 1) * (pre_pdf + 1) * (pdf + 1));
        break;
    default:
        printf("%s(): This clock: %d not supported yet \n", __FUNCTION__, clk);
        break;
    }

    return ret_val;
}

void ldb_clock_config(int freq)
{

    reg32clrbit(PLL4_BASE_ADDR + PLL_DP_CONFIG, 1);
    // Program PLL4 to 455Mhz - assuming 24MHz OSC as reference
    reg32_write(PLL4_BASE_ADDR + PLL_DP_CTL, 0x00001222);
    reg32_write(PLL4_BASE_ADDR + PLL_DP_OP, 0x00000091);    //MFI=6; PDF=0
    reg32_write(PLL4_BASE_ADDR + PLL_DP_MFD, 96);   //MFD=999
    reg32_write(PLL4_BASE_ADDR + PLL_DP_MFN, 45);   //MFN=198
    reg32setbit(PLL4_BASE_ADDR + PLL_DP_CTL, 4);

    // Wait for PLL 4 to lock
    while (!((reg32_read(PLL4_BASE_ADDR + PLL_DP_CTL) & 1))) ;

    reg32setbit(PLL4_BASE_ADDR + PLL_DP_CONFIG, 1);
    //derived from PLL4 (default 595M)
    //ldb_dix_clk_sel
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 8);
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 9);

    //ldb_dix_clk_div
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 10);
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 11);

    //derived from PLL4 (default 595M)
    //di0_clk_sel
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 26);
    reg32clrbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 27);
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 28);
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 29);
    reg32clrbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 30);
    reg32setbit(CCM_BASE_ADDR + CLKCTL_CSCMR2, 31);
}
