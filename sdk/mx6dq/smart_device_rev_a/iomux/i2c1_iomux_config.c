/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: i2c1_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance i2c1.
void i2c1_iomux_config(void)
{
    // Config i2c1.SCL to pad CSI0_DAT9(N5)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT9(0x020E027C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad CSI0_DAT9.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: CSI0_DAT9.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CSI0_D[9] of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: WEIM_D[7] of instance: weim.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: MOSI of instance: ecspi2.
    //                NOTE: - Config Register IOMUXC_ECSPI2_IPP_IND_MOSI_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: ROW[7] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SCL of instance: i2c1.
    //                NOTE: - Config Register IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[27] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: MMDC_DEBUG[48] of instance: mmdc.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: TRACE[6] of instance: cheetah.
    writel((SION_ENABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT9);
    // Pad CSI0_DAT9 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT(0x020E0898)
    //   DAISY (0) Reset: SEL_EIM_D21_ALT6
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: i2c1, In Pin: ipp_scl_in
    //     SEL_EIM_D21_ALT6 (0) - Selecting Pad: EIM_D21 for Mode: ALT6.
    //     SEL_CSI0_DAT9_ALT4 (1) - Selecting Pad: CSI0_DAT9 for Mode: ALT4.
    writel((SEL_CSI0_DAT9_ALT4 & 0x1), IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT9(0x020E064C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: CSI0_DAT9.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: CSI0_DAT9.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: CSI0_DAT9.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: CSI0_DAT9.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: CSI0_DAT9.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: CSI0_DAT9.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: CSI0_DAT9.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: CSI0_DAT9.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT9);

    // Config i2c1.SDA to pad CSI0_DAT8(N6)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT8(0x020E0278)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad CSI0_DAT8.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: CSI0_DAT8.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CSI0_D[8] of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: WEIM_D[6] of instance: weim.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SCLK of instance: ecspi2.
    //                NOTE: - Config Register IOMUXC_ECSPI2_IPP_CSPI_CLK_IN_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: COL[7] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_COL_7_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SDA of instance: i2c1.
    //                NOTE: - Config Register IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[26] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: MMDC_DEBUG[47] of instance: mmdc.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: TRACE[5] of instance: cheetah.
    writel((SION_ENABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT8);
    // Pad CSI0_DAT8 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT(0x020E089C)
    //   DAISY (0) Reset: SEL_EIM_D28_ALT1
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: i2c1, In Pin: ipp_sda_in
    //     SEL_EIM_D28_ALT1 (0) - Selecting Pad: EIM_D28 for Mode: ALT1.
    //     SEL_CSI0_DAT8_ALT4 (1) - Selecting Pad: CSI0_DAT8 for Mode: ALT4.
    writel((SEL_CSI0_DAT8_ALT4 & 0x1), IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT8(0x020E0648)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: CSI0_DAT8.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: CSI0_DAT8.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: CSI0_DAT8.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: CSI0_DAT8.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: CSI0_DAT8.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: CSI0_DAT8.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: CSI0_DAT8.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: CSI0_DAT8.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT8);
}
