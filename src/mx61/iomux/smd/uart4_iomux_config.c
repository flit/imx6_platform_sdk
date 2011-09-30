/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: uart4_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance uart4.
void uart4_iomux_config(void)
{
    // Config uart4_RXD_MUX to pad KEY_ROW0(V6)
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
    writel((SION_DISABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0);
    // Pad KEY_ROW0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0938)
    //   DAISY (1-0) Reset: SEL_KEY_COL0_ALT4
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart4, In Pin: ipp_uart_rxd_mux
    //     SEL_KEY_COL0_ALT4 (0) - Selecting Pad: KEY_COL0 for Mode: ALT4.
    //     SEL_KEY_ROW0_ALT4 (1) - Selecting Pad: KEY_ROW0 for Mode: ALT4.
    //     SEL_CSI0_DAT12_ALT3 (2) - Selecting Pad: CSI0_DAT12 for Mode: ALT3.
    //     SEL_CSI0_DAT13_ALT3 (3) - Selecting Pad: CSI0_DAT13 for Mode: ALT3.
    writel((SEL_KEY_ROW0_ALT4 & 0x3), IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT);
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

    // Config uart4_TXD_MUX to pad KEY_COL0(W5)
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
    writel((SION_DISABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_COL0);
    // Pad KEY_COL0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0938)
    //   DAISY (1-0) Reset: SEL_KEY_COL0_ALT4
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart4, In Pin: ipp_uart_rxd_mux
    //     SEL_KEY_COL0_ALT4 (0) - Selecting Pad: KEY_COL0 for Mode: ALT4.
    //     SEL_KEY_ROW0_ALT4 (1) - Selecting Pad: KEY_ROW0 for Mode: ALT4.
    //     SEL_CSI0_DAT12_ALT3 (2) - Selecting Pad: CSI0_DAT12 for Mode: ALT3.
    //     SEL_CSI0_DAT13_ALT3 (3) - Selecting Pad: CSI0_DAT13 for Mode: ALT3.
    writel((SEL_KEY_ROW0_ALT4 & 0x3), IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT);
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
}
