/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: ecspi1_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance ecspi1.
void ecspi1_iomux_config(void)
{
    // Config ecspi1_MISO to pad KEY_COL1(U7)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL1(0x020E0200)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_COL1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: MISO of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MDIO of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_MDIO_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUD5_TXFS of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_TXFS_AMX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: COL[1] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: TXD_MUX of instance: uart5.
    //                NOTE: - Config Register IOMUXC_UART5_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[8] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: VSELECT of instance: usdhc1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HADDR[1] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_COL1);
    // Pad KEY_COL1 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT(0x020E07F8)
    //   DAISY (1-0) Reset: SEL_EIM_D17_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1, In Pin: ipp_ind_miso
    //     SEL_EIM_D17_ALT1 (0) - Selecting Pad: EIM_D17 for Mode: ALT1.
    //     SEL_DISP0_DAT22_ALT2 (1) - Selecting Pad: DISP0_DAT22 for Mode: ALT2.
    //     SEL_KEY_COL1_ALT0 (2) - Selecting Pad: KEY_COL1 for Mode: ALT0.
    //     SEL_CSI0_DAT6_ALT2 (3) - Selecting Pad: CSI0_DAT6 for Mode: ALT2.
    writel((SEL_EIM_D17_ALT1 & 0x3), IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL1(0x020E05D0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_COL1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_COL1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_COL1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_COL1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_COL1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_COL1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_COL1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_COL1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_KEY_COL1);

    // Config ecspi1_MOSI to pad KEY_ROW0(V6)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0(0x020E01FC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_ROW0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_ROW0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: MOSI of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: TDATA[3] of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUD5_TXD of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_DB_AMX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: ROW[0] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: RXD_MUX of instance: uart4.
    //                NOTE: - Config Register IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[7] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DCIC_OUT of instance: dcic2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HADDR[0] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0);
    // Pad KEY_ROW0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT(0x020E07FC)
    //   DAISY (1-0) Reset: SEL_EIM_D18_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1, In Pin: ipp_ind_mosi
    //     SEL_EIM_D18_ALT1 (0) - Selecting Pad: EIM_D18 for Mode: ALT1.
    //     SEL_DISP0_DAT21_ALT2 (1) - Selecting Pad: DISP0_DAT21 for Mode: ALT2.
    //     SEL_KEY_ROW0_ALT0 (2) - Selecting Pad: KEY_ROW0 for Mode: ALT0.
    //     SEL_CSI0_DAT5_ALT2 (3) - Selecting Pad: CSI0_DAT5 for Mode: ALT2.
    writel((SEL_EIM_D18_ALT1 & 0x3), IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0(0x020E05CC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_ROW0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_ROW0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_ROW0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_ROW0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_ROW0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_ROW0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_ROW0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_ROW0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0);

    // Config ecspi1_SCLK to pad KEY_COL0(W5)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL0(0x020E01F8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_COL0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SCLK of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RDATA[3] of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_RXDATA_3_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUD5_TXC of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_TXCLK_AMX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: COL[0] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: TXD_MUX of instance: uart4.
    //                NOTE: - Config Register IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[6] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DCIC_OUT of instance: dcic1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANY_PU_RST of instance: src.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_COL0);
    // Pad KEY_COL0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT(0x020E07F4)
    //   DAISY (1-0) Reset: SEL_EIM_D16_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1, In Pin: ipp_cspi_clk_in
    //     SEL_EIM_D16_ALT1 (0) - Selecting Pad: EIM_D16 for Mode: ALT1.
    //     SEL_DISP0_DAT20_ALT2 (1) - Selecting Pad: DISP0_DAT20 for Mode: ALT2.
    //     SEL_KEY_COL0_ALT0 (2) - Selecting Pad: KEY_COL0 for Mode: ALT0.
    //     SEL_CSI0_DAT4_ALT2 (3) - Selecting Pad: CSI0_DAT4 for Mode: ALT2.
    writel((SEL_EIM_D16_ALT1 & 0x3), IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL0(0x020E05C8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_COL0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_COL0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_COL0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_COL0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_COL0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_COL0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_COL0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_COL0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_KEY_COL0);

    // Config ecspi1_SS0 to pad KEY_ROW1(U6)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_ROW1(0x020E0204)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_ROW1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_ROW1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SS0 of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: COL of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUD5_RXD of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_DA_AMX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: ROW[1] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: RXD_MUX of instance: uart5.
    //                NOTE: - Config Register IOMUXC_UART5_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[9] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: VSELECT of instance: usdhc2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HADDR[2] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_ROW1);
    // Pad KEY_ROW1 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT(0x020E0800)
    //   DAISY (1-0) Reset: SEL_EIM_EB2_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1, In Pin: ipp_ind_ss_b[0]
    //     SEL_EIM_EB2_ALT1 (0) - Selecting Pad: EIM_EB2 for Mode: ALT1.
    //     SEL_DISP0_DAT23_ALT2 (1) - Selecting Pad: DISP0_DAT23 for Mode: ALT2.
    //     SEL_KEY_ROW1_ALT0 (2) - Selecting Pad: KEY_ROW1 for Mode: ALT0.
    //     SEL_CSI0_DAT7_ALT2 (3) - Selecting Pad: CSI0_DAT7 for Mode: ALT2.
    writel((SEL_EIM_EB2_ALT1 & 0x3), IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_ROW1(0x020E05D4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_ROW1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_ROW1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_ROW1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_ROW1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_ROW1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_ROW1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_ROW1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_ROW1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_KEY_ROW1);
}
