/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "gpmi/gpmi.h"
#include "core/ccm_pll.h"
#include "registers/regsgpmi.h"
#include "registers/regsccm.h"
#include "registers/regsccmanalog.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

//! @brief Configure and enable the GPMI and BCH clocks.
//!
//! The GPMI clock is selected to be sourced from the main PLL3 clock (480 MHz), then
//! divided by 4 and again by 1. The resulting clock is 120 MHz.
void gpmi_nand_clk_setup(void)
{
    HW_CCM_ANALOG_PFD_528_CLR(BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE);

    // Gate clocks before adjusting dividers.
    clock_gating_config(REGS_GPMI_BASE, CLOCK_OFF);

    HW_CCM_CS2CDR.B.ENFC_CLK_SEL = 2;   // Select pll3 clock (480 MHz)
    HW_CCM_CS2CDR.B.ENFC_CLK_PRED = 3;  // Divide by 4
    HW_CCM_CS2CDR.B.ENFC_CLK_PODF = 0;  // Divide by 1

    // Ungate clocks.
    clock_gating_config(REGS_GPMI_BASE, CLOCK_ON);

    HW_CCM_CCGR0.B.CG2 = CLOCK_ON;  // apbhdma_hclk_enable
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
