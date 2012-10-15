/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"

// MX6SL EVK uses an SMSC LAN8720 PHY

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

// ENET iomux config
void imx_ar8031_iomux()
{
    fec_iomux_config();
}

// CPU_PER_RST_B low to high
void imx_ar8031_reset(void)
{
}

/*CPU_PER_RST_B low to high*/
// void imx_KSZ9021RN_reset(void)
// {
// }

/*! From obds
 * ENET iomux config
 */
void imx_enet_iomux(void)
{
    fec_iomux_config();
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
