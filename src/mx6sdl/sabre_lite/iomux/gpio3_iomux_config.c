/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: gpio3_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance gpio3.
void gpio3_iomux_config(void)
{
    // Config gpio3.GPIO[0] to pad EIM_DA0(L20)
    // J12 - Boot Mode select
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

    // Config gpio3.GPIO[1] to pad EIM_DA1(J25)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA1(0x020E0188)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA1.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[1] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[8] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[8] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[1] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[1] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDLE of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA1);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA1(0x020E0558)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA1);

    // Config gpio3.GPIO[10] to pad EIM_DA10(M22)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA10(0x020E018C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA10.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_DA10.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[10] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_PIN15 of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_DATA_EN of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_DATA_EN_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[10] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[10] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[1] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA10);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA10(0x020E055C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA10.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA10.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA10.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA10.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA10.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA10.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA10.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA10.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA10);

    // Config gpio3.GPIO[11] to pad EIM_DA11(M20)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA11(0x020E0190)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA11.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA11.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[11] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_PIN2 of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_HSYNC of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_HSYNC_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[11] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[11] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[3] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA11);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA11(0x020E0560)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA11.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA11.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA11.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA11.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA11.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA11.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA11.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA11.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA11);

    // Config gpio3.GPIO[12] to pad EIM_DA12(M24)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA12(0x020E0194)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA12.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA12.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[12] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_PIN3 of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_VSYNC of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_VSYNC_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[12] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[12] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[2] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA12);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA12(0x020E0564)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA12.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA12.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA12.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA12.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA12.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA12.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA12.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA12.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA12);

    // Config gpio3.GPIO[13] to pad EIM_DA13(M23)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA13(0x020E0198)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA13.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA13.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[13] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_D0_CS of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI1_EXT_CLK of instance: ccm.
    //                NOTE: - Config IOMUXC_CCM_IPP_DI1_CLK_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[13] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[13] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[13] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA13);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA13(0x020E0568)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA13.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA13.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA13.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA13.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA13.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA13.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA13.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA13.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA13);

    // Config gpio3.GPIO[14] to pad EIM_DA14(N23)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA14(0x020E019C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA14.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA14.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[14] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_D1_CS of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_EXT_CLK of instance: ccm.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[14] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[14] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[14] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA14);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA14(0x020E056C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA14.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA14.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA14.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA14.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA14.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA14.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA14.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA14.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA14);

    // Config gpio3.GPIO[15] to pad EIM_DA15(N24)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA15(0x020E01A0)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA15.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_DA15.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[15] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_PIN1 of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI1_PIN4 of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[15] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[15] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[9] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA15);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA15(0x020E0570)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA15.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA15.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA15.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA15.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA15.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA15.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA15.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA15.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA15);

    // Config gpio3.GPIO[2] to pad EIM_DA2(L21)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA2(0x020E01A4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA2.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[2] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[7] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[7] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[2] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[2] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: BDR[0] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA2);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA2(0x020E0574)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA2);

    // Config gpio3.GPIO[23] to pad EIM_D23(D25)
    // RGMII reset
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D23(0x020E0160)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D23.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_D23.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[23] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI0_D0_CS of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CTS of instance: uart3.
    //                NOTE: - Config IOMUXC_UART3_IPP_UART_RTS_B_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: DCD of instance: uart1.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CSI1_DATA_EN of instance: ipu1.
    //                NOTE: - Config IOMUXC_IPU1_IPP_IND_SENS1_DATA_EN_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[23] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DI1_PIN2 of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DI1_PIN14 of instance: ipu1.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDDO[11] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_D23);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D23(0x020E0530)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D23.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D23.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D23.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D23.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D23.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D23.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D23.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D23.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D23);

    // Config gpio3.GPIO[3] to pad EIM_DA3(K24)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA3(0x020E01A8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA3.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[3] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[6] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[6] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[3] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[3] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: BDR[1] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA3);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA3(0x020E0578)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA3);

    // Config gpio3.GPIO[4] to pad EIM_DA4(L22)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA4(0x020E01AC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA4.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA4.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[4] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[5] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[5] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[4] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[4] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCE[0] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA4);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA4(0x020E057C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA4.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA4.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA4.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA4.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA4.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA4.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA4.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA4.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA4);

    // Config gpio3.GPIO[5] to pad EIM_DA5(L23)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA5(0x020E01B0)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA5.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA5.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[5] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[4] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[4] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[5] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[5] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCE[1] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA5);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA5(0x020E0580)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA5.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA5.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA5.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA5.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA5.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA5.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA5.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA5.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA5);

    // Config gpio3.GPIO[6] to pad EIM_DA6(K25)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA6(0x020E01B4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA6.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 9 iomux modes to be used for pad: EIM_DA6.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[6] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[3] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[3] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[6] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[6] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCE[2] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA6);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA6(0x020E0584)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA6.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA6.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA6.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA6.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA6.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA6.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA6.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA6.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA6);

    // Config gpio3.GPIO[7] to pad EIM_DA7(L25)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA7(0x020E01B8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA7.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_DA7.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[7] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[2] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[2] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[7] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[7] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCE[3] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA7);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA7(0x020E0588)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA7.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA7.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA7.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA7.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA7.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA7.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA7.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA7.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA7);

    // Config gpio3.GPIO[8] to pad EIM_DA8(L24)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA8(0x020E01BC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA8.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_DA8.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[8] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[1] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[1] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[8] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[8] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCE[4] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA8);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA8(0x020E058C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA8.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA8.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA8.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA8.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA8.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA8.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA8.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA8.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA8);

    // Config gpio3.GPIO[9] to pad EIM_DA9(M21)
    // J12 - Boot Mode select
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA9(0x020E01C0)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA9.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_DA9.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_DA_A[9] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[0] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[0] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[9] of instance: gpio3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[9] of instance: src.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: SDCE[5] of instance: epdc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0xF), IOMUXC_SW_MUX_CTL_PAD_EIM_DA9);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA9(0x020E0590)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_DA9.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_DA9.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_DA9.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_DA9.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_DA9.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_DA9.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_DA9.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_DA9.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_DA9);
}
