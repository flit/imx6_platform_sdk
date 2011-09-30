/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: usboh3_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance usboh3.
void usboh3_iomux_config(void)
{
    // Config usboh3_USBH1_OC to pad EIM_D30(J20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D30(0x020E00CC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D30.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_D30.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[30] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[21] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_PIN11 of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI0_D[3] of instance: ipu1.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CTS of instance: uart3.
    //                NOTE: - Config Register IOMUXC_UART3_IPP_UART_RTS_B_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[30] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: USBH1_OC of instance: usboh3.
    //                NOTE: - Config Register IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HPROT[0] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT6 & 0x7), IOMUXC_SW_MUX_CTL_PAD_EIM_D30);
    // Pad EIM_D30 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT(0x020E0948)
    //   DAISY (0) Reset: SEL_EIM_D30_ALT6
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: usboh3, In Pin: ipp_ind_uh1_oc
    //     SEL_EIM_D30_ALT6 (0) - Selecting Pad: EIM_D30 for Mode: ALT6.
    //     SEL_GPIO_3_ALT6 (1) - Selecting Pad: GPIO_3 for Mode: ALT6.
    writel((SEL_EIM_D30_ALT6 & 0x1), IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D30(0x020E03E0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D30.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D30.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D30.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D30.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D30.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D30.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D30.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D30.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D30);

    // Config usboh3_USBOTG_OC to pad KEY_COL4(T6)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL4(0x020E0218)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL4.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_COL4.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TXCAN of instance: can2.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[4] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: USBOTG_OC of instance: usboh3.
    //                NOTE: - Config Register IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: COL[4] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: RTS of instance: uart5.
    //                NOTE: - Config Register IOMUXC_UART5_IPP_UART_RTS_B_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[14] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: MMDC_DEBUG[49] of instance: mmdc.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HADDR[7] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_COL4);
    // Pad KEY_COL4 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT(0x020E0944)
    //   DAISY (0) Reset: SEL_EIM_D21_ALT4
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: usboh3, In Pin: ipp_ind_otg_oc
    //     SEL_EIM_D21_ALT4 (0) - Selecting Pad: EIM_D21 for Mode: ALT4.
    //     SEL_KEY_COL4_ALT2 (1) - Selecting Pad: KEY_COL4 for Mode: ALT2.
    writel((SEL_EIM_D21_ALT4 & 0x1), IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL4(0x020E05E8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_COL4.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_COL4.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_COL4.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_COL4.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_COL4.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_COL4.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_COL4.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_COL4.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_KEY_COL4);

    // Config usboh3_USBOTG_PWR to pad EIM_D22(E23)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D22(0x020E00A8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D22.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_D22.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[22] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MISO of instance: ecspi4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_PIN1 of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_D[10] of instance: ipu2.
    //                NOTE: - Config Register IOMUXC_IPU2_IPP_IND_SENS1_DATA_10_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: USBOTG_PWR of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[22] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: OUT1 of instance: spdif.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HWRITE of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_EIM_D22);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D22(0x020E03BC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D22.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D22.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D22.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D22.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D22.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D22.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D22.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D22.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D22);
}
