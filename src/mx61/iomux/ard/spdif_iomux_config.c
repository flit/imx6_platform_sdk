/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: spdif_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance spdif.
void spdif_iomux_config(void)
{
    // Config spdif_IN1 to pad KEY_COL3(U5)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL3(0x020E0210)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_COL3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SS3 of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_SS_B_3_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: CRS of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DDC_SCL of instance: hdmi_tx.
    //                NOTE: - Config Register IOMUXC_HDMI_TX_II2C_MSTH13TDDC_SCLIN_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: COL[3] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SCL of instance: i2c2.
    //                NOTE: - Config Register IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[12] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IN1 of instance: spdif.
    //                NOTE: - Config Register IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HADDR[5] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT6 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_COL3);
    // Pad KEY_COL3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT(0x020E0914)
    //   DAISY (1-0) Reset: SEL_EIM_D21_ALT7
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: spdif, In Pin: spdif_in1
    //     SEL_EIM_D21_ALT7 (0) - Selecting Pad: EIM_D21 for Mode: ALT7.
    //     SEL_ENET_RX_ER_ALT3 (1) - Selecting Pad: ENET_RX_ER for Mode: ALT3.
    //     SEL_KEY_COL3_ALT6 (2) - Selecting Pad: KEY_COL3 for Mode: ALT6.
    //     SEL_GPIO_16_ALT4 (3) - Selecting Pad: GPIO_16 for Mode: ALT4.
    writel((SEL_EIM_D21_ALT7 & 0x3), IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL3(0x020E05E0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_COL3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_COL3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_COL3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_COL3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_COL3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_COL3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_COL3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_COL3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_KEY_COL3);
}
