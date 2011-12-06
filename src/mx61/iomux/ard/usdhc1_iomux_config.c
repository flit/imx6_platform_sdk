/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: usdhc1_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance usdhc1.
void usdhc1_iomux_config(void)
{
    // Config usdhc1_CD to pad GPIO_1(T4)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_1(0x020E0224)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SCKR of instance: esai1.
    //                NOTE: - Config Register IOMUXC_ESAI1_IPP_IND_SCKR_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: WDOG_B of instance: wdog2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: ROW[5] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_ROW_5_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: USBOTG_ID of instance: anatop.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: PWMO of instance: pwm2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[1] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: CD of instance: usdhc1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: TESTER_ACK of instance: src.
    writel((SION_DISABLED & 0x1) << 4 | (ALT6 & 0x7), IOMUXC_SW_MUX_CTL_PAD_GPIO_1);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_1(0x020E05F4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_GPIO_1);

    // Config usdhc1_CLK to pad SD1_CLK(D20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD1_CLK(0x020E0350)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD1_CLK.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: SD1_CLK.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CLK of instance: usdhc1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SCLK of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_CSPI_CLK_IN_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: 32K_OUT of instance: osc32k.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CLKIN of instance: gpt.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[20] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DTB[0] of instance: phy.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DTB[0] of instance: sata_phy.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD1_CLK);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD1_CLK(0x020E0738)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD1_CLK.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD1_CLK.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD1_CLK.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD1_CLK.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD1_CLK.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD1_CLK.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD1_CLK.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD1_CLK.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD1_CLK);

    // Config usdhc1_CMD to pad SD1_CMD(B21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD1_CMD(0x020E0348)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD1_CMD.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: SD1_CMD.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CMD of instance: usdhc1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MOSI of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_IND_MOSI_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: PWMO of instance: pwm4.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CMPOUT1 of instance: gpt.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[18] of instance: gpio1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[5] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD1_CMD);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD1_CMD(0x020E0730)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD1_CMD.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD1_CMD.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD1_CMD.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD1_CMD.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD1_CMD.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD1_CMD.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD1_CMD.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD1_CMD.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD1_CMD);

    // Config usdhc1_DAT0 to pad SD1_DAT0(A21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD1_DAT0(0x020E0340)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD1_DAT0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD1_DAT0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT0 of instance: usdhc1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MISO of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_IND_MISO_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: RNG_OSC_OBS of instance: caam_wrapper.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CAPIN1 of instance: gpt.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[8] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[16] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: OPHYDTB[1] of instance: hdmi_tx.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[7] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD1_DAT0);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD1_DAT0(0x020E0728)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD1_DAT0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD1_DAT0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD1_DAT0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD1_DAT0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD1_DAT0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD1_DAT0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD1_DAT0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD1_DAT0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD1_DAT0);

    // Config usdhc1_DAT1 to pad SD1_DAT1(C20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1(0x020E033C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD1_DAT1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD1_DAT1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT1 of instance: usdhc1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS0 of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_IND_SS_B_0_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: PWMO of instance: pwm3.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CAPIN2 of instance: gpt.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[7] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[17] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: OPHYDTB[0] of instance: hdmi_tx.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[8] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1(0x020E0724)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD1_DAT1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD1_DAT1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD1_DAT1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD1_DAT1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD1_DAT1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD1_DAT1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD1_DAT1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD1_DAT1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1);

    // Config usdhc1_DAT2 to pad SD1_DAT2(E19)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD1_DAT2(0x020E034C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD1_DAT2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD1_DAT2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT2 of instance: usdhc1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS1 of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_IND_SS_B_1_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CMPOUT2 of instance: gpt.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: PWMO of instance: pwm2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: WDOG_B of instance: wdog1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[19] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: WDOG_RST_B_DEB of instance: wdog1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[4] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD1_DAT2);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD1_DAT2(0x020E0734)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD1_DAT2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD1_DAT2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD1_DAT2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD1_DAT2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD1_DAT2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD1_DAT2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD1_DAT2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD1_DAT2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD1_DAT2);

    // Config usdhc1_DAT3 to pad SD1_DAT3(F18)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3(0x020E0344)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD1_DAT3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD1_DAT3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT3 of instance: usdhc1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS2 of instance: ecspi5.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CMPOUT3 of instance: gpt.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: PWMO of instance: pwm1.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: WDOG_B of instance: wdog2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[21] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: WDOG_RST_B_DEB of instance: wdog2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[6] of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT0 & 0x7), IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD1_DAT3(0x020E072C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD1_DAT3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD1_DAT3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD1_DAT3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD1_DAT3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD1_DAT3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD1_DAT3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD1_DAT3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD1_DAT3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_SD1_DAT3);

    // Config usdhc1_DAT4 to pad NANDF_D0(A18)
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
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D0);
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

    // Config usdhc1_DAT5 to pad NANDF_D1(C17)
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
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D1);
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

    // Config usdhc1_DAT6 to pad NANDF_D2(F16)
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
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D2);
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

    // Config usdhc1_DAT7 to pad NANDF_D3(D17)
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
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_NANDF_D3);
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
}
