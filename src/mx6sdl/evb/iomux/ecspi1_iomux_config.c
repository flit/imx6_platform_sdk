/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
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
    // Config ecspi1.MISO to pad EIM_D17(F21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D17(0x020E0148)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D17.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_D17.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[17] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MISO of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_PIN6 of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_PIXCLK of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_PIX_CLK_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DCIC_OUT of instance: dcic1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[17] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SCL of instance: i2c3.
    //                NOTE: - Config IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT for mode ALT6.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: VCOM[0] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_D17);
    // Pad EIM_D17 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT(0x020E07DC)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT6_ALT2
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1,   In Pin: ipp_ind_miso
    //     SEL_CSI0_DAT6_ALT2 (0) - Selecting Pad: CSI0_DAT6 for Mode: ALT2.
    //     SEL_DISP0_DAT22_ALT2 (1) - Selecting Pad: DISP0_DAT22 for Mode: ALT2.
    //     SEL_EIM_D17_ALT1 (2) - Selecting Pad: EIM_D17 for Mode: ALT1.
    //     SEL_KEY_COL1_ALT0 (3) - Selecting Pad: KEY_COL1 for Mode: ALT0.
    writel((SEL_CSI0_DAT6_ALT2 & 0x3), IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D17(0x020E0518)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D17.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D17.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D17.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D17.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D17.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D17.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D17.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D17.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D17);

    // Config ecspi1.MOSI to pad EIM_D18(D24)
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
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_D18);
    // Pad EIM_D18 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT(0x020E07E0)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT5_ALT2
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1,   In Pin: ipp_ind_mosi
    //     SEL_CSI0_DAT5_ALT2 (0) - Selecting Pad: CSI0_DAT5 for Mode: ALT2.
    //     SEL_DISP0_DAT21_ALT2 (1) - Selecting Pad: DISP0_DAT21 for Mode: ALT2.
    //     SEL_EIM_D18_ALT1 (2) - Selecting Pad: EIM_D18 for Mode: ALT1.
    //     SEL_KEY_ROW0_ALT0 (3) - Selecting Pad: KEY_ROW0 for Mode: ALT0.
    writel((SEL_CSI0_DAT5_ALT2 & 0x3), IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT);
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

    // Config ecspi1.SCLK to pad EIM_D16(C25)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D16(0x020E0144)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D16.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_D16.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[16] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SCLK of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_PIN5 of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_D[18] of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_DATA_18_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DDC_SDA of instance: hdmi_tx.
    //                NOTE: - Config IOMUXC_HDMI_TX_II2C_MSTH13TDDC_SDAIN_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[16] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SDA of instance: i2c2.
    //                NOTE: - Config IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT for mode ALT6.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[10] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_D16);
    // Pad EIM_D16 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT(0x020E07D8)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT4_ALT2
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1,   In Pin: ipp_cspi_clk_in
    //     SEL_CSI0_DAT4_ALT2 (0) - Selecting Pad: CSI0_DAT4 for Mode: ALT2.
    //     SEL_DISP0_DAT20_ALT2 (1) - Selecting Pad: DISP0_DAT20 for Mode: ALT2.
    //     SEL_EIM_D16_ALT1 (2) - Selecting Pad: EIM_D16 for Mode: ALT1.
    //     SEL_KEY_COL0_ALT0 (3) - Selecting Pad: KEY_COL0 for Mode: ALT0.
    writel((SEL_CSI0_DAT4_ALT2 & 0x3), IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D16(0x020E0514)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D16.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D16.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D16.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D16.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D16.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D16.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D16.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D16.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D16);

    // Config ecspi1.SS0 to pad EIM_EB2(E22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_EB2(0x020E01CC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_EB2.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_EB2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_EB[2] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS0 of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI1_EXT_CLK of instance: ccm.
    //                NOTE: - Config IOMUXC_CCM_IPP_DI1_CLK_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_D[19] of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_DATA_19_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DDC_SCL of instance: hdmi_tx.
    //                NOTE: - Config IOMUXC_HDMI_TX_II2C_MSTH13TDDC_SCLIN_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[30] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SCL of instance: i2c2.
    //                NOTE: - Config IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[30] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[5] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_EB2);
    // Pad EIM_EB2 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT(0x020E07E4)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT7_ALT2
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1,   In Pin: ipp_ind_ss_b[0]
    //     SEL_CSI0_DAT7_ALT2 (0) - Selecting Pad: CSI0_DAT7 for Mode: ALT2.
    //     SEL_DISP0_DAT23_ALT2 (1) - Selecting Pad: DISP0_DAT23 for Mode: ALT2.
    //     SEL_EIM_EB2_ALT1 (2) - Selecting Pad: EIM_EB2 for Mode: ALT1.
    //     SEL_KEY_ROW1_ALT0 (3) - Selecting Pad: KEY_ROW1 for Mode: ALT0.
    writel((SEL_CSI0_DAT7_ALT2 & 0x3), IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_EB2(0x020E059C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_EB2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_EB2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_EB2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_EB2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_EB2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_EB2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_EB2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_EB2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_EB2);

    // Config ecspi1.SS1 to pad EIM_D19(G21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D19(0x020E0150)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D19.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_D19.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[19] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS1 of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_PIN8 of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_D[16] of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_DATA_16_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CTS of instance: uart1.
    //                NOTE: - Config IOMUXC_UART1_IPP_UART_RTS_B_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[19] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: EPITO of instance: epit1.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[12] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_D19);
    // Pad EIM_D19 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT(0x020E07E8)
    //   DAISY (1-0) Reset: SEL_DISP0_DAT15_ALT2
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: ecspi1,   In Pin: ipp_ind_ss_b[1]
    //     SEL_DISP0_DAT15_ALT2 (0) - Selecting Pad: DISP0_DAT15 for Mode: ALT2.
    //     SEL_EIM_D19_ALT1 (1) - Selecting Pad: EIM_D19 for Mode: ALT1.
    //     SEL_KEY_COL2_ALT0 (2) - Selecting Pad: KEY_COL2 for Mode: ALT0.
    writel((SEL_DISP0_DAT15_ALT2 & 0x3), IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D19(0x020E0520)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D19.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D19.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D19.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D19.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D19.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D19.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D19.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D19.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D19);
}
