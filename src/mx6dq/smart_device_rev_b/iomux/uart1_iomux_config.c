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
    // Config uart1.RXD_MUX to pad CSI0_DAT11(M3)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT11(0x020E0284)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad CSI0_DAT11.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: CSI0_DAT11.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CSI0_D[11] of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: AUD3_RXFS of instance: audmux.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SS0 of instance: ecspi2.
    //                NOTE: - Config Register IOMUXC_ECSPI2_IPP_IND_SS_B_0_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: RXD_MUX of instance: uart1.
    //                NOTE: - Config Register IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DEBUG_PC[5] of instance: sdma.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[29] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: MMDC_DEBUG[34] of instance: mmdc.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: TRACE[8] of instance: cheetah.
    writel((SION_DISABLED & 0x1) << 4 | (ALT3 & 0x7), IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT11);
    // Pad CSI0_DAT11 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0920)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT10_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart1, In Pin: ipp_uart_rxd_mux
    //     SEL_CSI0_DAT10_ALT3 (0) - Selecting Pad: CSI0_DAT10 for Mode: ALT3.
    //     SEL_CSI0_DAT11_ALT3 (1) - Selecting Pad: CSI0_DAT11 for Mode: ALT3.
    //     SEL_SD3_DAT7_ALT1 (2) - Selecting Pad: SD3_DAT7 for Mode: ALT1.
    //     SEL_SD3_DAT6_ALT1 (3) - Selecting Pad: SD3_DAT6 for Mode: ALT1.
    writel((SEL_CSI0_DAT11_ALT3 & 0x3), IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT11(0x020E0654)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: CSI0_DAT11.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: CSI0_DAT11.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: CSI0_DAT11.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: CSI0_DAT11.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: CSI0_DAT11.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: CSI0_DAT11.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: CSI0_DAT11.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: CSI0_DAT11.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT11);

    // Config uart1.TXD_MUX to pad CSI0_DAT10(M1)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT10(0x020E0280)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad CSI0_DAT10.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: CSI0_DAT10.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CSI0_D[10] of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: AUD3_RXC of instance: audmux.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: MISO of instance: ecspi2.
    //                NOTE: - Config Register IOMUXC_ECSPI2_IPP_IND_MISO_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: TXD_MUX of instance: uart1.
    //                NOTE: - Config Register IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DEBUG_PC[4] of instance: sdma.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[28] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: MMDC_DEBUG[33] of instance: mmdc.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: TRACE[7] of instance: cheetah.
    writel((SION_DISABLED & 0x1) << 4 | (ALT3 & 0x7), IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT10);
    // Pad CSI0_DAT10 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0920)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT10_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart1, In Pin: ipp_uart_rxd_mux
    //     SEL_CSI0_DAT10_ALT3 (0) - Selecting Pad: CSI0_DAT10 for Mode: ALT3.
    //     SEL_CSI0_DAT11_ALT3 (1) - Selecting Pad: CSI0_DAT11 for Mode: ALT3.
    //     SEL_SD3_DAT7_ALT1 (2) - Selecting Pad: SD3_DAT7 for Mode: ALT1.
    //     SEL_SD3_DAT6_ALT1 (3) - Selecting Pad: SD3_DAT6 for Mode: ALT1.
    writel((SEL_CSI0_DAT11_ALT3 & 0x3), IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT10(0x020E0650)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: CSI0_DAT10.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: CSI0_DAT10.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: CSI0_DAT10.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: CSI0_DAT10.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: CSI0_DAT10.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: CSI0_DAT10.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: CSI0_DAT10.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: CSI0_DAT10.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT10);
}
