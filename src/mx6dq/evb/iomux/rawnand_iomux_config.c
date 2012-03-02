/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: rawnand_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance rawnand.
void rawnand_iomux_config(void)
{
    // Config rawnand.ALE to pad NANDF_ALE(A16)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE(0x020E02D8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_ALE.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_ALE.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: ALE of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RST of instance: usdhc4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DIAG_STATUS_BUS_MUX[0] of instance: pcie_ctrl.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[12] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[12] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[8] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[24] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HTRANS[1] of instance: tpsmp.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE(0x020E06C0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_ALE.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_ALE.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_ALE.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_ALE.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_ALE.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_ALE.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_ALE.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_ALE.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE);

    // Config rawnand.CE0N to pad NANDF_CS0(F15)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0(0x020E02E4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: NANDF_CS0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE0N of instance: rawnand.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[15] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[15] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[11] of instance: gpio6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HSIZE[2] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0(0x020E06CC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CS0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CS0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CS0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CS0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CS0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CS0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CS0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CS0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0);

    // Config rawnand.CE1N to pad NANDF_CS1(C16)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1(0x020E02E8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: NANDF_CS1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE1N of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: VSELECT of instance: usdhc4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: VSELECT of instance: usdhc3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[3] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[14] of instance: gpio6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HREADYOUT of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1(0x020E06D0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CS1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CS1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CS1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CS1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CS1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CS1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CS1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CS1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1);

    // Config rawnand.CE2N to pad NANDF_CS2(A17)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2(0x020E02EC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: NANDF_CS2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE2N of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[0] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX0 of instance: esai.
    //                NOTE: - Config Register IOMUXC_ESAI_IPP_IND_SDO0_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: WEIM_CRE of instance: weim.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CLKO2 of instance: ccm.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[15] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SISG[0] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2(0x020E06D4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CS2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CS2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CS2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CS2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CS2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CS2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CS2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CS2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2);

    // Config rawnand.CE3N to pad NANDF_CS3(D16)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3(0x020E02F0)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_CS3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE3N of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[1] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX1 of instance: esai.
    //                NOTE: - Config Register IOMUXC_ESAI_IPP_IND_SDO1_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: WEIM_A[26] of instance: weim.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[4] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[16] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SISG[1] of instance: ipu2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: CLK of instance: tpsmp.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3(0x020E06D8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CS3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CS3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CS3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CS3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CS3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CS3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CS3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CS3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3);

    // Config rawnand.CLE to pad NANDF_CLE(C15)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE(0x020E02D4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CLE.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_CLE.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CLE of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[4] of instance: ipu2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DIAG_STATUS_BUS_MUX[31] of instance: pcie_ctrl.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[11] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[11] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[7] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[23] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HTRANS[0] of instance: tpsmp.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE(0x020E06BC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CLE.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CLE.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CLE.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CLE.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CLE.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CLE.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CLE.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CLE.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE);

    // Config rawnand.D0 to pad NANDF_D0(A18)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_D0(0x020E02FC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_D0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_D0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D0 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT4 of instance: usdhc1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: GPU_DEBUG_OUT[0] of instance: gpu3d.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[16] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[16] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[0] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[0] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[0] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D0);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_D0(0x020E06E4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_D0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_D0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_D0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_D0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_D0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_D0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_D0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_D0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_D0);

    // Config rawnand.D1 to pad NANDF_D1(C17)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_D1(0x020E0300)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_D1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_D1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D1 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT5 of instance: usdhc1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: GPU_DEBUG_OUT[1] of instance: gpu3d.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[17] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[17] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[1] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[1] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[1] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D1);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_D1(0x020E06E8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_D1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_D1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_D1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_D1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_D1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_D1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_D1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_D1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_D1);

    // Config rawnand.D2 to pad NANDF_D2(F16)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_D2(0x020E0304)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_D2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_D2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D2 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT6 of instance: usdhc1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: GPU_DEBUG_OUT[2] of instance: gpu3d.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[18] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[18] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[2] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[2] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[2] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D2);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_D2(0x020E06EC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_D2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_D2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_D2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_D2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_D2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_D2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_D2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_D2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_D2);

    // Config rawnand.D3 to pad NANDF_D3(D17)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_D3(0x020E0308)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_D3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_D3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D3 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT7 of instance: usdhc1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: GPU_DEBUG_OUT[3] of instance: gpu3d.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[19] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[19] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[3] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[3] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[3] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D3);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_D3(0x020E06F0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_D3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_D3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_D3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_D3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_D3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_D3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_D3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_D3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_D3);

    // Config rawnand.D4 to pad NANDF_D4(A19)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_D4(0x020E030C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_D4.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_D4.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D4 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT4 of instance: usdhc2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: GPU_DEBUG_OUT[4] of instance: gpu3d.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[20] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[20] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[4] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[4] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[4] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D4);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_D4(0x020E06F4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_D4.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_D4.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_D4.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_D4.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_D4.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_D4.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_D4.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_D4.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_D4);

    // Config rawnand.D5 to pad NANDF_D5(B18)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_D5(0x020E0310)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_D5.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_D5.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D5 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT5 of instance: usdhc2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: GPU_DEBUG_OUT[5] of instance: gpu3d.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[21] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[21] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[5] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[5] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[5] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D5);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_D5(0x020E06F8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_D5.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_D5.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_D5.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_D5.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_D5.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_D5.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_D5.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_D5.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_D5);

    // Config rawnand.D6 to pad NANDF_D6(E17)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_D6(0x020E0314)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_D6.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_D6.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D6 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT6 of instance: usdhc2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: GPU_DEBUG_OUT[6] of instance: gpu3d.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[22] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[22] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[6] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[6] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[6] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D6);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_D6(0x020E06FC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_D6.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_D6.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_D6.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_D6.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_D6.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_D6.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_D6.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_D6.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_D6);

    // Config rawnand.D7 to pad NANDF_D7(C18)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_D7(0x020E0318)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_D7.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_D7.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D7 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT7 of instance: usdhc2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: GPU_DEBUG_OUT[7] of instance: gpu3d.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[23] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[23] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[7] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[7] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[7] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D7);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_D7(0x020E0700)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_D7.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_D7.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_D7.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_D7.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_D7.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_D7.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_D7.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_D7.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_D7);

    // Config rawnand.DQS to pad SD4_DAT0(D18)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD4_DAT0(0x020E031C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD4_DAT0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD4_DAT0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D8 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT0 of instance: usdhc4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DQS of instance: rawnand.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[24] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[24] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[8] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[8] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[8] of instance: ipu2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD4_DAT0);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD4_DAT0(0x020E0704)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD4_DAT0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD4_DAT0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD4_DAT0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD4_DAT0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD4_DAT0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD4_DAT0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD4_DAT0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD4_DAT0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD4_DAT0);

    // Config rawnand.RDN to pad SD4_CMD(B17)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD4_CMD(0x020E02F4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD4_CMD.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: SD4_CMD.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CMD of instance: usdhc4.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RDN of instance: rawnand.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TXD_MUX of instance: uart3.
    //                NOTE: - Config Register IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[5] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[9] of instance: gpio7.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HDATA_DIR of instance: tpsmp.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD4_CMD);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD4_CMD(0x020E06DC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD4_CMD.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD4_CMD.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD4_CMD.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD4_CMD.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD4_CMD.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD4_CMD.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD4_CMD.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD4_CMD.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD4_CMD);

    // Config rawnand.READY0 to pad NANDF_RB0(B16)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0(0x020E02E0)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_RB0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_RB0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: READY0 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI0_PIN1 of instance: ipu2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DIAG_STATUS_BUS_MUX[2] of instance: pcie_ctrl.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[14] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[14] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[10] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_OUT[33] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HSIZE[1] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0(0x020E06C8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_RB0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_RB0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_RB0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_RB0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_RB0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_RB0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_RB0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_RB0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0);

    // Config rawnand.RESETN to pad NANDF_WP_B(E15)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B(0x020E02DC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_WP_B.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_WP_B.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: RESETN of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[5] of instance: ipu2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DIAG_STATUS_BUS_MUX[1] of instance: pcie_ctrl.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[13] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[13] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[9] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_OUT[32] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HSIZE[0] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B(0x020E06C4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_WP_B.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_WP_B.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_WP_B.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_WP_B.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_WP_B.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_WP_B.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_WP_B.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_WP_B.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B);

    // Config rawnand.WRN to pad SD4_CLK(E16)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD4_CLK(0x020E02F8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD4_CLK.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: SD4_CLK.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CLK of instance: usdhc4.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: WRN of instance: rawnand.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: RXD_MUX of instance: uart3.
    //                NOTE: - Config Register IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[6] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[10] of instance: gpio7.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD4_CLK);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD4_CLK(0x020E06E0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD4_CLK.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD4_CLK.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD4_CLK.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD4_CLK.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD4_CLK.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD4_CLK.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD4_CLK.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD4_CLK.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD4_CLK);
}
