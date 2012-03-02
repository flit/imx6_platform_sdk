/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: hdmi_tx_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance hdmi_tx.
void hdmi_tx_iomux_config(void)
{
    // Config hdmi_tx.CEC_LINE to pad EIM_A25(H19)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_A25(0x020E0134)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_A25.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 10 iomux modes to be used for pad: EIM_A25.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_A[25] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS1 of instance: ecspi4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: RDY of instance: ecspi2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: DI1_PIN12 of instance: ipu1.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DI0_D1_CS of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[2] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: CEC_LINE of instance: hdmi_tx.
    //                NOTE: - Config IOMUXC_HDMI_TX_ICECIN_SELECT_INPUT for mode ALT6.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[15] of instance: epdc.
    //     ALT9 (9) - Select mux mode: ALT9 mux port: ACLK_FREERUN of instance: weim.
    writel((SION_DISABLED & 0x1) << 4 | (ALT6 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_A25);
    // Pad EIM_A25 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_HDMI_TX_ICECIN_SELECT_INPUT(0x020E085C)
    //   DAISY (0) Reset: SEL_EIM_A25_ALT6
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: hdmi_tx,   In Pin: icecin
    //     SEL_EIM_A25_ALT6 (0) - Selecting Pad: EIM_A25 for Mode: ALT6.
    //     SEL_KEY_ROW2_ALT6 (1) - Selecting Pad: KEY_ROW2 for Mode: ALT6.
    writel((SEL_EIM_A25_ALT6 & 0x1), IOMUXC_HDMI_TX_ICECIN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_A25(0x020E0504)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_A25.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_A25.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_A25.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_A25.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_A25.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_A25.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_A25.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_A25.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_A25);
}
