/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: gps_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance gps.
void gps_iomux_config(void)
{
    // Config gps.GPS_PWREN to pad EIM_DA0(L20)
    // WAS Instance:gpio3 Signal:GPIO[0]
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA0(0x020E0184)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA0.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_DA0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[0] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[9] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[9] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[0] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[0] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCLKN of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA0);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA0(0x020E0554)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA0);

    // Config gps.GPS_PPS to pad EIM_D18(D24)
    // WAS Instance:gpio3 Signal:GPIO[18]
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D18(0x020E014C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D18.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_D18.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[18] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MOSI of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_PIN7 of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_D[17] of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_DATA_17_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DI1_D0_CS of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[18] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SDA of instance: i2c3.
    //                NOTE: - Config IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT for mode ALT6.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: VCOM[1] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_D18);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D18(0x020E051C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D18.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D18.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D18.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D18.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D18.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D18.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D18.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D18.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D18);

    // Config gps.GPS_RESET_B to pad EIM_EB0(K21)
    // WAS Instance:gpio2 Signal:GPIO[28]
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_EB0(0x020E01C4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_EB0.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_EB0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_EB[0] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[11] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[11] of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_DATA_11_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: PMIC_RDY of instance: ccm.
    //                NOTE: - Config IOMUXC_CCM_PMIC_VFUNCIONAL_READY_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[28] of instance: gpio2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[27] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: PWRCOM of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_EB0);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_EB0(0x020E0594)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_EB0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_EB0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_EB0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_EB0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_EB0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_EB0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_EB0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_EB0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_EB0);

    // Config gps.GPS_TXD to pad EIM_D24(F22)
    // WAS Instance:uart3 Signal:TXD_MUX
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D24(0x020E0164)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D24.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_D24.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[24] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS2 of instance: ecspi4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TXD_MUX of instance: uart3.
    //                NOTE: - Config IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: SS2 of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_SS_B_2_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SS2 of instance: ecspi2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[24] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: AUD5_RXFS of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P5_INPUT_RXFS_AMX_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DTR of instance: uart1.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCE[7] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_D24);
    // Pad EIM_D24 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E090C)
    //   DAISY (1-0) Reset: SEL_EIM_D24_ALT2
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart3,   In Pin: ipp_uart_rxd_mux
    //     SEL_EIM_D24_ALT2 (0) - Selecting Pad: EIM_D24 for Mode: ALT2.
    //     SEL_EIM_D25_ALT2 (1) - Selecting Pad: EIM_D25 for Mode: ALT2.
    //     SEL_SD4_CLK_ALT2 (2) - Selecting Pad: SD4_CLK for Mode: ALT2.
    //     SEL_SD4_CMD_ALT2 (3) - Selecting Pad: SD4_CMD for Mode: ALT2.
    writel((SEL_EIM_D25_ALT2 & 0x3), IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D24(0x020E0534)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D24.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D24.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D24.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D24.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D24.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D24.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D24.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D24.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D24);

    // Config gps.GPS_RXD to pad EIM_D25(G22)
    // WAS Instance:uart3 Signal:RXD_MUX
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D25(0x020E0168)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D25.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_D25.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[25] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS3 of instance: ecspi4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: RXD_MUX of instance: uart3.
    //                NOTE: - Config IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: SS3 of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_SS_B_3_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SS3 of instance: ecspi2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[25] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: AUD5_RXC of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P5_INPUT_RXCLK_AMX_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DSR of instance: uart1.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCE[8] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_D25);
    // Pad EIM_D25 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E090C)
    //   DAISY (1-0) Reset: SEL_EIM_D24_ALT2
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart3,   In Pin: ipp_uart_rxd_mux
    //     SEL_EIM_D24_ALT2 (0) - Selecting Pad: EIM_D24 for Mode: ALT2.
    //     SEL_EIM_D25_ALT2 (1) - Selecting Pad: EIM_D25 for Mode: ALT2.
    //     SEL_SD4_CLK_ALT2 (2) - Selecting Pad: SD4_CLK for Mode: ALT2.
    //     SEL_SD4_CMD_ALT2 (3) - Selecting Pad: SD4_CMD for Mode: ALT2.
    writel((SEL_EIM_D25_ALT2 & 0x3), IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D25(0x020E0538)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D25.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D25.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D25.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D25.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D25.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D25.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D25.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D25.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D25);
}
