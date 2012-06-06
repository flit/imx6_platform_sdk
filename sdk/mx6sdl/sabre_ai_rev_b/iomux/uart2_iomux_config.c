/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: uart2_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance uart2.
void uart2_iomux_config(void)
{
    // Config uart2.CTS to pad SD4_DAT6(B20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD4_DAT6(0x020E0358)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD4_DAT6.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: SD4_DAT6.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D14 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT6 of instance: usdhc4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CTS of instance: uart2.
    //                NOTE: - Config IOMUXC_UART2_IPP_UART_RTS_B_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[14] of instance: gpio2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD4_DAT6);
    // Pad SD4_DAT6 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART2_IPP_UART_RTS_B_SELECT_INPUT(0x020E0900)
    //   DAISY (2-0) Reset: SEL_EIM_D28_ALT4
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart2,   In Pin: ipp_uart_rts_b
    //     SEL_EIM_D28_ALT4 (0) - Selecting Pad: EIM_D28 for Mode: ALT4.
    //     SEL_EIM_D29_ALT4 (1) - Selecting Pad: EIM_D29 for Mode: ALT4.
    //     SEL_SD3_CLK_ALT1 (2) - Selecting Pad: SD3_CLK for Mode: ALT1.
    //     SEL_SD3_CMD_ALT1 (3) - Selecting Pad: SD3_CMD for Mode: ALT1.
    //     SEL_SD4_DAT5_ALT2 (4) - Selecting Pad: SD4_DAT5 for Mode: ALT2.
    //     SEL_SD4_DAT6_ALT2 (5) - Selecting Pad: SD4_DAT6 for Mode: ALT2.
    writel((SEL_EIM_D28_ALT4 & 0x7), IOMUXC_UART2_IPP_UART_RTS_B_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD4_DAT6(0x020E0740)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD4_DAT6.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD4_DAT6.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD4_DAT6.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD4_DAT6.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD4_DAT6.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD4_DAT6.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD4_DAT6.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD4_DAT6.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD4_DAT6);

    // Config uart2.RTS to pad SD4_DAT5(C19)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD4_DAT5(0x020E0354)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD4_DAT5.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: SD4_DAT5.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D13 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT5 of instance: usdhc4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: RTS of instance: uart2.
    //                NOTE: - Config IOMUXC_UART2_IPP_UART_RTS_B_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[13] of instance: gpio2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD4_DAT5);
    // Pad SD4_DAT5 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART2_IPP_UART_RTS_B_SELECT_INPUT(0x020E0900)
    //   DAISY (2-0) Reset: SEL_EIM_D28_ALT4
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart2,   In Pin: ipp_uart_rts_b
    //     SEL_EIM_D28_ALT4 (0) - Selecting Pad: EIM_D28 for Mode: ALT4.
    //     SEL_EIM_D29_ALT4 (1) - Selecting Pad: EIM_D29 for Mode: ALT4.
    //     SEL_SD3_CLK_ALT1 (2) - Selecting Pad: SD3_CLK for Mode: ALT1.
    //     SEL_SD3_CMD_ALT1 (3) - Selecting Pad: SD3_CMD for Mode: ALT1.
    //     SEL_SD4_DAT5_ALT2 (4) - Selecting Pad: SD4_DAT5 for Mode: ALT2.
    //     SEL_SD4_DAT6_ALT2 (5) - Selecting Pad: SD4_DAT6 for Mode: ALT2.
    writel((SEL_EIM_D28_ALT4 & 0x7), IOMUXC_UART2_IPP_UART_RTS_B_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD4_DAT5(0x020E073C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD4_DAT5.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD4_DAT5.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD4_DAT5.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD4_DAT5.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD4_DAT5.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD4_DAT5.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD4_DAT5.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD4_DAT5.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD4_DAT5);

    // Config uart2.RXD_MUX to pad GPIO_8(R5)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_8(0x020E023C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_8.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: GPIO_8.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX5_RX0 of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SDO5_SDI0_SELECT_INPUT for mode ALT0.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: EPITO of instance: epit2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: RXCAN of instance: can1.
    //                NOTE: - Config IOMUXC_CAN1_IPP_IND_CANRX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: RXD_MUX of instance: uart2.
    //                NOTE: - Config IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[8] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SRCLK of instance: spdif.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: OTGUSB_PWRCTL_WAKEUP of instance: usboh3.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDA of instance: i2c4.
    //                NOTE: - Config IOMUXC_I2C4_IPP_SDA_IN_SELECT_INPUT for mode ALT8.
    writel((SION_DISABLED & 0x1) << 4 | (ALT4 & 0xF), IOMUXC_SW_MUX_CTL_PAD_GPIO_8);
    // Pad GPIO_8 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0904)
    //   DAISY (2-0) Reset: SEL_EIM_D26_ALT4
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart2,   In Pin: ipp_uart_rxd_mux
    //     SEL_EIM_D26_ALT4 (0) - Selecting Pad: EIM_D26 for Mode: ALT4.
    //     SEL_EIM_D27_ALT4 (1) - Selecting Pad: EIM_D27 for Mode: ALT4.
    //     SEL_GPIO_7_ALT4 (2) - Selecting Pad: GPIO_7 for Mode: ALT4.
    //     SEL_GPIO_8_ALT4 (3) - Selecting Pad: GPIO_8 for Mode: ALT4.
    //     SEL_SD3_DAT4_ALT1 (4) - Selecting Pad: SD3_DAT4 for Mode: ALT1.
    //     SEL_SD3_DAT5_ALT1 (5) - Selecting Pad: SD3_DAT5 for Mode: ALT1.
    //     SEL_SD4_DAT4_ALT2 (6) - Selecting Pad: SD4_DAT4 for Mode: ALT2.
    //     SEL_SD4_DAT7_ALT2 (7) - Selecting Pad: SD4_DAT7 for Mode: ALT2.
    writel((SEL_GPIO_8_ALT4 & 0x7), IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_8(0x020E060C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_8.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_8.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_8.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_8.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_8.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_8.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_8.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_8.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_GPIO_8);

    // Config uart2.TXD_MUX to pad GPIO_7(R3)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_7(0x020E0238)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_7.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_7.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX4_RX1 of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SDO4_SDI1_SELECT_INPUT for mode ALT0.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: EPITO of instance: epit1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: TXCAN of instance: can1.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: TXD_MUX of instance: uart2.
    //                NOTE: - Config IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[7] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: PLOCK of instance: spdif.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: OTGUSB_HOST_MODE of instance: usboh3.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SCL of instance: i2c4.
    //                NOTE: - Config IOMUXC_I2C4_IPP_SCL_IN_SELECT_INPUT for mode ALT8.
    writel((SION_DISABLED & 0x1) << 4 | (ALT4 & 0xF), IOMUXC_SW_MUX_CTL_PAD_GPIO_7);
    // Pad GPIO_7 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0904)
    //   DAISY (2-0) Reset: SEL_EIM_D26_ALT4
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart2,   In Pin: ipp_uart_rxd_mux
    //     SEL_EIM_D26_ALT4 (0) - Selecting Pad: EIM_D26 for Mode: ALT4.
    //     SEL_EIM_D27_ALT4 (1) - Selecting Pad: EIM_D27 for Mode: ALT4.
    //     SEL_GPIO_7_ALT4 (2) - Selecting Pad: GPIO_7 for Mode: ALT4.
    //     SEL_GPIO_8_ALT4 (3) - Selecting Pad: GPIO_8 for Mode: ALT4.
    //     SEL_SD3_DAT4_ALT1 (4) - Selecting Pad: SD3_DAT4 for Mode: ALT1.
    //     SEL_SD3_DAT5_ALT1 (5) - Selecting Pad: SD3_DAT5 for Mode: ALT1.
    //     SEL_SD4_DAT4_ALT2 (6) - Selecting Pad: SD4_DAT4 for Mode: ALT2.
    //     SEL_SD4_DAT7_ALT2 (7) - Selecting Pad: SD4_DAT7 for Mode: ALT2.
    writel((SEL_GPIO_8_ALT4 & 0x7), IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_7(0x020E0608)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_7.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_7.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_7.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_7.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_7.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_7.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_7.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_7.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_GPIO_7);
}
