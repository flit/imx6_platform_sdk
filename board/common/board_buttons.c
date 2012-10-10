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

//! @brief IOMUX configuration for the Android_Buttons
void android_buttons_iomux_config()
{
    //HOME_(SD2_CMD_GPI1_11)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD2_CMD, ALT5);   //GPIO1[11]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD2_CMD, 0x00E0); // pull-up enabled at pad

    //BACK_(SD2_DAT3_GPI1_12)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD2_DAT3, ALT5);  //GPIO1[12]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD2_DAT3, 0x00E0);    // pull-up enabled at pad

    //PROG_(SD4_DAT4_GPI2_12)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT4, ALT5);  //GPIO2[12]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD4_DAT4, 0x00E0);    // pull-up enabled at pad

    //VOL+_(SD4_DAT7_GPI2_15)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT7, ALT5);  //GPIO2[15]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD4_DAT7, 0x00E0);    // pull-up enabled at pad

    //VOL-_(DISP0_DAT20_GPI5_14)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT20, ALT5);   //GPIO5[14]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20, 0x00E0); // pull-up enabled at pad
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
