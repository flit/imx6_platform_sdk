/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "registers/regsccm.h"

#if !defined(CHIP_MX6SL)
#include "registers/regsesai.h"
#endif

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void SGTL5000PowerUp_and_clockinit(void)
{
}

/*!
 *
 * Additional code related to clock configuration
 *
 */
unsigned int spdif_get_tx_clk_freq(void)
{
    return 30000000;
}

/*! From obds
 * Audio Codec Power on
 */
void audio_codec_power_on (void)
{
#ifdef BOARD_SMART_DEVICE
    //CODEC PWR_EN, key_col12
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_KEY_COL2);
    gpio_set_direction(GPIO_PORT4, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT4, 10, GPIO_HIGH_LEVEL);
#endif
}

/*! From obds
 * Audio Clock Config
 */
void audio_clock_config(void)
{
#if defined(CHIP_MX6DQ) && defined(BOARD_SMART_DEVICE) 
    uint32_t val = 0;
    
    ccm_iomux_config();

    val = (0x01 << 24) |      //clko2 en
          (0x05 << 21) |     //div 6
          (0x13 << 16) |     //ssi2 root clk
          (0x01 << 8);       //CKO1 output drives cko2 clock
//    writel(val, CCM_CCOSR);
    writel(val, (CCM_BASE_ADDR + CCM_CCOSR_OFFSET));
#endif
}

/*!
 * @brief SPDIF clock configuration
 *
 * Use the default setting as follow:
 * CDCDR[spdif0_clk_sel](PLL3)->CDCDR[spdif0_clk_pred](div2)->CDCDR[spdif0_clk_podf](div8)-> spdif0_clk_root, so
 * the freqency of spdif0_clk should be 480/2/8 = 30MHz.
 */
void spdif_clk_cfg(void)
{
    HW_CCM_CDCDR.B.SPDIF0_CLK_SEL = 3;  // PLL3
    HW_CCM_CDCDR.B.SPDIF0_CLK_PODF = 7; // div 8
    HW_CCM_CDCDR.B.SPDIF0_CLK_PRED = 1; // div 2

    clock_gating_config(SPDIF_BASE_ADDR, CLOCK_ON);

    return;
}

#if !defined(CHIP_MX6SL)
/*!
 * Power no esai codec.
 */
int esai_codec_power_on(void)
{
    // No need to do anything for BOARD_SABRE_AI
    return 0;
}

void esai_clk_sel_gate_on()
{
    // source from PLL3_508
    HW_CCM_CSCMR2.B.ESAI_CLK_SEL = 1;

    clock_gating_config(REGS_ESAI_BASE, CLOCK_ON);
}
#endif // !defined(CHIP_MX6SL)

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
