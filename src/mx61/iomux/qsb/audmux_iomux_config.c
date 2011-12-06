/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: audmux_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance audmux.
void audmux_iomux_config(void)
{
    // Config audmux_AUD4_RXD to pad SD2_DAT0(A22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_DAT0(0x020E0054)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_DAT0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: SD2_DAT0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT0 of instance: usdhc2.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MISO of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_IND_MISO_SELECT_INPUT for mode ALT1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_RXD of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P4_INPUT_DA_AMX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: ROW[7] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[15] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DCIC_OUT of instance: dcic2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[2] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT3 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_DAT0);
    // Pad SD2_DAT0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_AUDMUX_P4_INPUT_DA_AMX_SELECT_INPUT(0x020E07B4)
    //   DAISY (0) Reset: SEL_SD2_DAT0_ALT3
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: audmux, In Pin: p4_input_da_amx
    //     SEL_SD2_DAT0_ALT3 (0) - Selecting Pad: SD2_DAT0 for Mode: ALT3.
    //     SEL_DISP0_DAT23_ALT3 (1) - Selecting Pad: DISP0_DAT23 for Mode: ALT3.
    writel((SEL_SD2_DAT0_ALT3 & 0x1), IOMUXC_AUDMUX_P4_INPUT_DA_AMX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_DAT0(0x020E0368)
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
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_DAT0);

    // Config audmux_AUD4_TXC to pad SD2_DAT3(B22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_DAT3(0x020E035C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_DAT3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD2_DAT3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT3 of instance: usdhc2.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS3 of instance: ecspi5.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: COL[6] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_COL_6_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXC of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P4_INPUT_TXCLK_AMX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[11] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[12] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DONE of instance: sjc.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[3] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT3 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_DAT3);
    // Pad SD2_DAT3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_AUDMUX_P4_INPUT_TXCLK_AMX_SELECT_INPUT(0x020E07C4)
    //   DAISY (0) Reset: SEL_DISP0_DAT20_ALT3
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: audmux, In Pin: p4_input_txclk_amx
    //     SEL_DISP0_DAT20_ALT3 (0) - Selecting Pad: DISP0_DAT20 for Mode: ALT3.
    //     SEL_SD2_DAT3_ALT3 (1) - Selecting Pad: SD2_DAT3 for Mode: ALT3.
    writel((SEL_DISP0_DAT20_ALT3 & 0x1), IOMUXC_AUDMUX_P4_INPUT_TXCLK_AMX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_DAT3(0x020E0744)
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
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_DAT3);

    // Config audmux_AUD4_TXD to pad SD2_DAT2(A23)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_DAT2(0x020E0050)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_DAT2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD2_DAT2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT2 of instance: usdhc2.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS1 of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_IND_SS_B_1_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: WEIM_CS[3] of instance: weim.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXD of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P4_INPUT_DB_AMX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: ROW[6] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_ROW_6_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[13] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: STOP of instance: ccm.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[1] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT3 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_DAT2);
    // Pad SD2_DAT2 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_AUDMUX_P4_INPUT_DB_AMX_SELECT_INPUT(0x020E07B8)
    //   DAISY (0) Reset: SEL_SD2_DAT2_ALT3
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: audmux, In Pin: p4_input_db_amx
    //     SEL_SD2_DAT2_ALT3 (0) - Selecting Pad: SD2_DAT2 for Mode: ALT3.
    //     SEL_DISP0_DAT21_ALT3 (1) - Selecting Pad: DISP0_DAT21 for Mode: ALT3.
    writel((SEL_SD2_DAT2_ALT3 & 0x1), IOMUXC_AUDMUX_P4_INPUT_DB_AMX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_DAT2(0x020E0364)
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
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_DAT2);

    // Config audmux_AUD4_TXFS to pad SD2_DAT1(E20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD2_DAT1(0x020E004C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD2_DAT1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD2_DAT1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT1 of instance: usdhc2.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS0 of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_IND_SS_B_0_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: WEIM_CS[2] of instance: weim.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXFS of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P4_INPUT_TXFS_AMX_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: COL[7] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_COL_7_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[14] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: WAIT of instance: ccm.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[0] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT3 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD2_DAT1);
    // Pad SD2_DAT1 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_AUDMUX_P4_INPUT_TXFS_AMX_SELECT_INPUT(0x020E07C8)
    //   DAISY (0) Reset: SEL_SD2_DAT1_ALT3
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: audmux, In Pin: p4_input_txfs_amx
    //     SEL_SD2_DAT1_ALT3 (0) - Selecting Pad: SD2_DAT1 for Mode: ALT3.
    //     SEL_DISP0_DAT22_ALT3 (1) - Selecting Pad: DISP0_DAT22 for Mode: ALT3.
    writel((SEL_SD2_DAT1_ALT3 & 0x1), IOMUXC_AUDMUX_P4_INPUT_TXFS_AMX_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD2_DAT1(0x020E0360)
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
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD2_DAT1);
}
