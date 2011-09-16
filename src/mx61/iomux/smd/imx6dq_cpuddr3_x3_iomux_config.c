/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: imx6dq_cpuddr3_x3_iomux_config.c

#include "imx6dq_cpuddr3_x3_iomux_config.h"


// Function to configure iomux for i.MX6DQ board CPUDDR3 X3.
void imx6dq_cpuddr3_x3_iomux_config(void)
{
    anatop_iomux_config();
    can1_iomux_config();
    can2_iomux_config();
    ccm_iomux_config();
    ecspi1_iomux_config();
    enet_iomux_config();
    esai1_iomux_config();
    gpio3_iomux_config();
    gpio4_iomux_config();
    gpio5_iomux_config();
    gpio6_iomux_config();
    hdmi_tx_iomux_config();
    i2c1_iomux_config();
    i2c2_iomux_config();
    i2c3_iomux_config();
    ipu1_iomux_config();
    mlb_iomux_config();
    pwm1_iomux_config();
    uart2_iomux_config();
    uart4_iomux_config();
    usboh3_iomux_config();
    usdhc1_iomux_config();
    usdhc2_iomux_config();
    usdhc3_iomux_config();
    usdhc4_iomux_config();

}
