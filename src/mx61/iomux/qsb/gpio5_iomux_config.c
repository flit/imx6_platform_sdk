/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: gpio5_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance gpio5.
void gpio5_iomux_config(void)
{
    // Config gpio5_GPIO[0] to pad EIM_WAIT(M25)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT(0x020E0154)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_WAIT.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 5 iomux modes to be used for pad: EIM_WAIT.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_WAIT of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: WEIM_DTACK_B of instance: weim.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[0] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: HDATA[30] of instance: tpsmp.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[25] of instance: src.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0x7), IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT(0x020E0468)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_WAIT.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_WAIT.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_WAIT.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_WAIT.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_WAIT.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_50MHZ
    //                 Select one out of next values for pad: EIM_WAIT.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_60OHM
    //               Select one out of next values for pad: EIM_WAIT.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_WAIT.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_50MHZ & 0x3) << 6 |
           (DSE_60OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT);

    // Config gpio5_GPIO[4] to pad EIM_A24(F25)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_A24(0x020E00D4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_A24.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_A24.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_A[24] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[19] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI1_D[19] of instance: ipu2.
    //                NOTE: - Config Register IOMUXC_IPU2_IPP_IND_SENS1_DATA_19_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: SISG[2] of instance: ipu2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SISG[2] of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[4] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: HPROT[2] of instance: pl301_mx63per1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[24] of instance: src.
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0x7), IOMUXC_SW_MUX_CTL_PAD_EIM_A24);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_A24(0x020E03E8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_A24.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_A24.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_A24.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_A24.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_A24.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_A24.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_A24.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_A24.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_DISABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_FAST & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_A24);
}
