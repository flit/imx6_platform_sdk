/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: uart1_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance uart1.
void uart1_iomux_config(void)
{
    // Config uart1.RXD_MUX to pad SD3_DAT6(E13)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD3_DAT6(0x020E032C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD3_DAT6.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD3_DAT6.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT6 of instance: usdhc3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RXD_MUX of instance: uart1.
    //                NOTE: - Config IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[18] of instance: gpio6.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD3_DAT6);
    // Pad SD3_DAT6 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E08FC)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT10_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart1,   In Pin: ipp_uart_rxd_mux
    //     SEL_CSI0_DAT10_ALT3 (0) - Selecting Pad: CSI0_DAT10 for Mode: ALT3.
    //     SEL_CSI0_DAT11_ALT3 (1) - Selecting Pad: CSI0_DAT11 for Mode: ALT3.
    //     SEL_SD3_DAT6_ALT1 (2) - Selecting Pad: SD3_DAT6 for Mode: ALT1.
    //     SEL_SD3_DAT7_ALT1 (3) - Selecting Pad: SD3_DAT7 for Mode: ALT1.
    writel((SEL_CSI0_DAT10_ALT3 & 0x3), IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD3_DAT6(0x020E0714)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD3_DAT6.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD3_DAT6.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD3_DAT6.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD3_DAT6.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD3_DAT6.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD3_DAT6.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD3_DAT6.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD3_DAT6.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD3_DAT6);

    // Config uart1.TXD_MUX to pad SD3_DAT7(F13)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD3_DAT7(0x020E0330)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD3_DAT7.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD3_DAT7.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT7 of instance: usdhc3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: TXD_MUX of instance: uart1.
    //                NOTE: - Config IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[17] of instance: gpio6.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD3_DAT7);
    // Pad SD3_DAT7 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E08FC)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT10_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart1,   In Pin: ipp_uart_rxd_mux
    //     SEL_CSI0_DAT10_ALT3 (0) - Selecting Pad: CSI0_DAT10 for Mode: ALT3.
    //     SEL_CSI0_DAT11_ALT3 (1) - Selecting Pad: CSI0_DAT11 for Mode: ALT3.
    //     SEL_SD3_DAT6_ALT1 (2) - Selecting Pad: SD3_DAT6 for Mode: ALT1.
    //     SEL_SD3_DAT7_ALT1 (3) - Selecting Pad: SD3_DAT7 for Mode: ALT1.
    writel((SEL_CSI0_DAT10_ALT3 & 0x3), IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD3_DAT7(0x020E0718)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD3_DAT7.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD3_DAT7.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD3_DAT7.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD3_DAT7.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD3_DAT7.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD3_DAT7.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD3_DAT7.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD3_DAT7.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD3_DAT7);
}
