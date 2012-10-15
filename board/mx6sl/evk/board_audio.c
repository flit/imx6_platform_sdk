/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"
#include "registers/regsccm.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 *
 * Additional code related to clock configuration
 *
 */
unsigned int spdif_get_tx_clk_freq(void)
{
    return 30000000;
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
}

/*! From obds
 * Audio Codec Power on
 */
void audio_codec_power_on (void)
{
}

/*! From obds
 * Audio Clock Config
 */
void audio_clock_config(void)
{
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
