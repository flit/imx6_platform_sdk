/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: kpp_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance kpp.
void kpp_iomux_config(void)
{
    // Config kpp.COL[5] to pad SD2_CLK(C21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_CLK(0x020E02F4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_CLK.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: SD2_CLK.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CLK of instance: usdhc2.
    //                NOTE: - Config IOMUXC_USDHC2_IPP_CARD_CLK_IN_SELECT_INPUT for mode ALT0.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: COL[5] of instance: kpp.
    //                NOTE: - Config IOMUXC_KPP_IPP_IND_COL_5_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_RXFS of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_RXFS_AMX_SELECT_INPUT for mode ALT3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[10] of instance: gpio1.
    writel((SION_ENABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_CLK);
    // Pad SD2_CLK is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_KPP_IPP_IND_COL_5_SELECT_INPUT(0x020E08C0)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT4_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: kpp,   In Pin: ipp_ind_col[5]
    //     SEL_CSI0_DAT4_ALT3 (0) - Selecting Pad: CSI0_DAT4 for Mode: ALT3.
    //     SEL_GPIO_0_ALT2 (1) - Selecting Pad: GPIO_0 for Mode: ALT2.
    //     SEL_GPIO_19_ALT0 (2) - Selecting Pad: GPIO_19 for Mode: ALT0.
    //     SEL_SD2_CLK_ALT2 (3) - Selecting Pad: SD2_CLK for Mode: ALT2.
    writel((SEL_SD2_CLK_ALT2 & 0x3), IOMUXC_KPP_IPP_IND_COL_5_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_CLK(0x020E06DC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD2_CLK.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD2_CLK.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD2_CLK.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD2_CLK.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD2_CLK.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD2_CLK.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD2_CLK.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD2_CLK.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_47KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_CLK);

    // Config kpp.COL[6] to pad SD2_DAT3(B22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_DAT3(0x020E0308)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_DAT3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: SD2_DAT3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT3 of instance: usdhc2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: COL[6] of instance: kpp.
    //                NOTE: - Config IOMUXC_KPP_IPP_IND_COL_6_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXC of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_TXCLK_AMX_SELECT_INPUT for mode ALT3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[12] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DONE of instance: sjc.
    writel((SION_ENABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_DAT3);
    // Pad SD2_DAT3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_KPP_IPP_IND_COL_6_SELECT_INPUT(0x020E08C4)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT6_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: kpp,   In Pin: ipp_ind_col[6]
    //     SEL_CSI0_DAT6_ALT3 (0) - Selecting Pad: CSI0_DAT6 for Mode: ALT3.
    //     SEL_GPIO_9_ALT2 (1) - Selecting Pad: GPIO_9 for Mode: ALT2.
    //     SEL_SD2_DAT3_ALT2 (2) - Selecting Pad: SD2_DAT3 for Mode: ALT2.
    writel((SEL_SD2_DAT3_ALT2 & 0x3), IOMUXC_KPP_IPP_IND_COL_6_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_DAT3(0x020E06F0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD2_DAT3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD2_DAT3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD2_DAT3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD2_DAT3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD2_DAT3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD2_DAT3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD2_DAT3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD2_DAT3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_47KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_DAT3);

    // Config kpp.COL[7] to pad SD2_DAT1(E20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_DAT1(0x020E0300)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_DAT1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: SD2_DAT1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT1 of instance: usdhc2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: WEIM_CS[2] of instance: weim.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXFS of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_TXFS_AMX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: COL[7] of instance: kpp.
    //                NOTE: - Config IOMUXC_KPP_IPP_IND_COL_7_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[14] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: WAIT of instance: ccm.
    writel((SION_ENABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_DAT1);
    // Pad SD2_DAT1 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_KPP_IPP_IND_COL_7_SELECT_INPUT(0x020E08C8)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT8_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: kpp,   In Pin: ipp_ind_col[7]
    //     SEL_CSI0_DAT8_ALT3 (0) - Selecting Pad: CSI0_DAT8 for Mode: ALT3.
    //     SEL_GPIO_4_ALT2 (1) - Selecting Pad: GPIO_4 for Mode: ALT2.
    //     SEL_SD2_DAT1_ALT4 (2) - Selecting Pad: SD2_DAT1 for Mode: ALT4.
    writel((SEL_CSI0_DAT8_ALT3 & 0x3), IOMUXC_KPP_IPP_IND_COL_7_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_DAT1(0x020E06E8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD2_DAT1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD2_DAT1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD2_DAT1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD2_DAT1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD2_DAT1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD2_DAT1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD2_DAT1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD2_DAT1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_47KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_DAT1);

    // Config kpp.ROW[5] to pad SD2_CMD(F19)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_CMD(0x020E02F8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_CMD.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: SD2_CMD.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CMD of instance: usdhc2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: ROW[5] of instance: kpp.
    //                NOTE: - Config IOMUXC_KPP_IPP_IND_ROW_5_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_RXC of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_RXCLK_AMX_SELECT_INPUT for mode ALT3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[11] of instance: gpio1.
    writel((SION_ENABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_CMD);
    // Pad SD2_CMD is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_KPP_IPP_IND_ROW_5_SELECT_INPUT(0x020E08CC)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT5_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: kpp,   In Pin: ipp_ind_row[5]
    //     SEL_CSI0_DAT5_ALT3 (0) - Selecting Pad: CSI0_DAT5 for Mode: ALT3.
    //     SEL_GPIO_1_ALT2 (1) - Selecting Pad: GPIO_1 for Mode: ALT2.
    //     SEL_SD2_CMD_ALT2 (2) - Selecting Pad: SD2_CMD for Mode: ALT2.
    writel((SEL_SD2_CMD_ALT2 & 0x3), IOMUXC_KPP_IPP_IND_ROW_5_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_CMD(0x020E06E0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD2_CMD.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD2_CMD.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD2_CMD.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD2_CMD.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD2_CMD.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD2_CMD.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD2_CMD.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD2_CMD.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_22KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_CMD);

    // Config kpp.ROW[6] to pad SD2_DAT2(A23)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_DAT2(0x020E0304)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_DAT2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: SD2_DAT2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT2 of instance: usdhc2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: WEIM_CS[3] of instance: weim.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXD of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_DB_AMX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: ROW[6] of instance: kpp.
    //                NOTE: - Config IOMUXC_KPP_IPP_IND_ROW_6_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[13] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: STOP of instance: ccm.
    writel((SION_ENABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_DAT2);
    // Pad SD2_DAT2 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_KPP_IPP_IND_ROW_6_SELECT_INPUT(0x020E08D0)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT7_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: kpp,   In Pin: ipp_ind_row[6]
    //     SEL_CSI0_DAT7_ALT3 (0) - Selecting Pad: CSI0_DAT7 for Mode: ALT3.
    //     SEL_GPIO_2_ALT2 (1) - Selecting Pad: GPIO_2 for Mode: ALT2.
    //     SEL_SD2_DAT2_ALT4 (2) - Selecting Pad: SD2_DAT2 for Mode: ALT4.
    writel((SEL_CSI0_DAT7_ALT3 & 0x3), IOMUXC_KPP_IPP_IND_ROW_6_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_DAT2(0x020E06EC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD2_DAT2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD2_DAT2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD2_DAT2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD2_DAT2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD2_DAT2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD2_DAT2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD2_DAT2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD2_DAT2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_22KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_DAT2);

    // Config kpp.ROW[7] to pad SD2_DAT0(A22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_DAT0(0x020E02FC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_DAT0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: SD2_DAT0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT0 of instance: usdhc2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_RXD of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_DA_AMX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: ROW[7] of instance: kpp.
    //                NOTE: - Config IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[15] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DCIC_OUT of instance: dcic2.
    writel((SION_ENABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_DAT0);
    // Pad SD2_DAT0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT(0x020E08D4)
    //   DAISY (1-0) Reset: SEL_CSI0_DAT9_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: kpp,   In Pin: ipp_ind_row[7]
    //     SEL_CSI0_DAT9_ALT3 (0) - Selecting Pad: CSI0_DAT9 for Mode: ALT3.
    //     SEL_GPIO_5_ALT2 (1) - Selecting Pad: GPIO_5 for Mode: ALT2.
    //     SEL_SD2_DAT0_ALT4 (2) - Selecting Pad: SD2_DAT0 for Mode: ALT4.
    writel((SEL_CSI0_DAT9_ALT3 & 0x3), IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_DAT0(0x020E06E4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD2_DAT0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD2_DAT0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD2_DAT0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD2_DAT0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD2_DAT0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD2_DAT0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD2_DAT0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD2_DAT0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_22KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_DAT0);
}
