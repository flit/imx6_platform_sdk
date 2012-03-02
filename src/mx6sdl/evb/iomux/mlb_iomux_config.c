/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: mlb_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance mlb.
void mlb_iomux_config(void)
{
    // Config mlb.MLBCLK to pad GPIO_3(R7)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_3(0x020E0228)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: HCKR of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_HCKR_SELECT_INPUT for mode ALT0.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SCL of instance: i2c3.
    //                NOTE: - Config IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CLKO2 of instance: ccm.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[3] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: USBH1_OC of instance: usboh3.
    //                NOTE: - Config IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: MLBCLK of instance: mlb.
    //                NOTE: - Config IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT for mode ALT7.
    writel((SION_DISABLED & 0x1) << 4 | (ALT7 & 0x7), IOMUXC_SW_MUX_CTL_PAD_GPIO_3);
    // Pad GPIO_3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT(0x020E08DC)
    //   DAISY (0) Reset: SEL_ENET_TXD1_ALT0
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: mlb,   In Pin: mlb_clk_in
    //     SEL_ENET_TXD1_ALT0 (0) - Selecting Pad: ENET_TXD1 for Mode: ALT0.
    //     SEL_GPIO_3_ALT7 (1) - Selecting Pad: GPIO_3 for Mode: ALT7.
    writel((SEL_ENET_TXD1_ALT0 & 0x1), IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_3(0x020E05F8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_GPIO_3);

    // Config mlb.MLBDAT to pad GPIO_2(T1)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_2(0x020E0224)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: FST of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_FST_SELECT_INPUT for mode ALT0.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: ROW[6] of instance: kpp.
    //                NOTE: - Config IOMUXC_KPP_IPP_IND_ROW_6_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CSU_ALARM_AUT[0] of instance: csu.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[2] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: WP of instance: usdhc2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: MLBDAT of instance: mlb.
    //                NOTE: - Config IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT for mode ALT7.
    writel((SION_DISABLED & 0x1) << 4 | (ALT7 & 0x7), IOMUXC_SW_MUX_CTL_PAD_GPIO_2);
    // Pad GPIO_2 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT(0x020E08E0)
    //   DAISY (0) Reset: SEL_ENET_MDC_ALT0
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: mlb,   In Pin: mlb_data_in
    //     SEL_ENET_MDC_ALT0 (0) - Selecting Pad: ENET_MDC for Mode: ALT0.
    //     SEL_GPIO_2_ALT7 (1) - Selecting Pad: GPIO_2 for Mode: ALT7.
    writel((SEL_ENET_MDC_ALT0 & 0x1), IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_2(0x020E05F4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_GPIO_2);

    // Config mlb.MLBSIG to pad GPIO_6(T3)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_6(0x020E0234)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_6.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_6.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SCKT of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SCKT_SELECT_INPUT for mode ALT0.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SDA of instance: i2c3.
    //                NOTE: - Config IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CSU_INT_DEB of instance: csu.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[6] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: LCTL of instance: usdhc2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: MLBSIG of instance: mlb.
    //                NOTE: - Config IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT for mode ALT7.
    writel((SION_DISABLED & 0x1) << 4 | (ALT7 & 0x7), IOMUXC_SW_MUX_CTL_PAD_GPIO_6);
    // Pad GPIO_6 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT(0x020E08E4)
    //   DAISY (0) Reset: SEL_ENET_RXD1_ALT0
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: mlb,   In Pin: mlb_sig_in
    //     SEL_ENET_RXD1_ALT0 (0) - Selecting Pad: ENET_RXD1 for Mode: ALT0.
    //     SEL_GPIO_6_ALT7 (1) - Selecting Pad: GPIO_6 for Mode: ALT7.
    writel((SEL_ENET_RXD1_ALT0 & 0x1), IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_6(0x020E0604)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_6.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_6.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_6.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_6.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_6.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_6.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_6.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_6.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_GPIO_6);
}
