/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "functions.h"
#include "hardware.h"

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

void ldb_clock_config(int freq)
{
 /*TBD*/}
