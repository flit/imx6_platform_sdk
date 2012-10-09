/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

//MLB iomux configuration
void mlb_io_config(void)
{
#ifdef MLB_SUPPORT
   //default board will use I2C3, but might be I2C2
   io_cfg_i2c(OS81050_I2C_BASE);
   mlb_iomux_config();
   //MLB_PWRDN input
   writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT15);
   gpio_set_direction(GPIO_PORT5, 9, GPIO_GDIR_INPUT);
#endif
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
