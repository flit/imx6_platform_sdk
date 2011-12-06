/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: enet_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance enet.
void enet_iomux_config(void)
{
    // Config enet_MDC to pad KEY_COL2(W6)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL2(0x020E0208)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_COL2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SS1 of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RDATA[2] of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_RXDATA_2_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TXCAN of instance: can1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: COL[2] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: MDC of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[10] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: H1USB_PWRCTL_WAKEUP of instance: usboh3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HADDR[3] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT4 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_COL2);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL2(0x020E05D8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_COL2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_COL2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_COL2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_COL2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_COL2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_COL2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_COL2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_COL2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_KEY_COL2);

    // Config enet_MDIO to pad KEY_COL1(U7)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL1(0x020E0200)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_COL1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: MISO of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MDIO of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_MDIO_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUD5_TXFS of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_TXFS_AMX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: COL[1] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: TXD_MUX of instance: uart5.
    //                NOTE: - Config Register IOMUXC_UART5_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[8] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: VSELECT of instance: usdhc1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HADDR[1] of instance: pl301_mx63per1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_KEY_COL1);
    // Pad KEY_COL1 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ENET_IPP_IND_MAC0_MDIO_SELECT_INPUT(0x020E0840)
    //   DAISY (0) Reset: SEL_ENET_MDIO_ALT1
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: enet, In Pin: ipp_ind_mac0_mdio
    //     SEL_ENET_MDIO_ALT1 (0) - Selecting Pad: ENET_MDIO for Mode: ALT1.
    //     SEL_KEY_COL1_ALT1 (1) - Selecting Pad: KEY_COL1 for Mode: ALT1.
    writel((SEL_ENET_MDIO_ALT1 & 0x1), IOMUXC_ENET_IPP_IND_MAC0_MDIO_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL1(0x020E05D0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_COL1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_COL1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_COL1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_COL1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_COL1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_COL1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_COL1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_COL1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_KEY_COL1);

    // Config enet_RGMII_RD0 to pad RGMII_RD0(C24)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_RD0(0x020E0070)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_RD0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 4 iomux modes to be used for pad: RGMII_RD0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: RX_READY of instance: mipi_hsi_ctrl.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_RD0 of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_RXDATA_0_SELECT_INPUT for mode ALT1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[25] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[6] of instance: mipi_core.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_RD0);
    // Pad RGMII_RD0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ENET_IPP_IND_MAC0_RXDATA_0_SELECT_INPUT(0x020E0848)
    //   DAISY (0) Reset: SEL_RGMII_RD0_ALT1
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: enet, In Pin: ipp_ind_mac0_rxdata[0]
    //     SEL_RGMII_RD0_ALT1 (0) - Selecting Pad: RGMII_RD0 for Mode: ALT1.
    //     SEL_ENET_RXD0_ALT1 (1) - Selecting Pad: ENET_RXD0 for Mode: ALT1.
    writel((SEL_RGMII_RD0_ALT1 & 0x1), IOMUXC_ENET_IPP_IND_MAC0_RXDATA_0_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_RD0(0x020E0384)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_RD0.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_RD0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: RGMII_RD0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_RD0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_RD0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //                NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_RD0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_RD0);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM(0x020E07AC)
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Select one out of next values for group: RGMII_TERM (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                RGMII_RX_CTL).
    //     ODT_OFF (0) - Off
    //     ODT_120OHM (1) - 120 Ohm ODT
    //     ODT_60OHM (2) - 60 Ohm ODT
    //     ODT_40OHM (3) - 40 Ohm ODT
    //     ODT_30OHM (4) - 30 Ohm ODT
    //     ODT_RES5 (5) - Reserved
    //     ODT_20OHM (6) - 20 Ohm ODT
    //     ODT_RES7 (7) - Reserved
    writel((ODT_OFF & 0x7) << 8, IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM);

    // Config enet_RGMII_RD1 to pad RGMII_RD1(B23)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_RD1(0x020E0078)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_RD1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: RGMII_RD1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX_FLAG of instance: mipi_hsi_ctrl.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_RD1 of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_RXDATA_1_SELECT_INPUT for mode ALT1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[27] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[8] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: FAIL of instance: sjc.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_RD1);
    // Pad RGMII_RD1 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ENET_IPP_IND_MAC0_RXDATA_1_SELECT_INPUT(0x020E084C)
    //   DAISY (0) Reset: SEL_RGMII_RD1_ALT1
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: enet, In Pin: ipp_ind_mac0_rxdata[1]
    //     SEL_RGMII_RD1_ALT1 (0) - Selecting Pad: RGMII_RD1 for Mode: ALT1.
    //     SEL_ENET_RXD1_ALT1 (1) - Selecting Pad: ENET_RXD1 for Mode: ALT1.
    writel((SEL_RGMII_RD1_ALT1 & 0x1), IOMUXC_ENET_IPP_IND_MAC0_RXDATA_1_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_RD1(0x020E038C)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_RD1.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_RD1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: RGMII_RD1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_RD1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_RD1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //                NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_RD1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_RD1);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM(0x020E07AC)
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Select one out of next values for group: RGMII_TERM (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                RGMII_RX_CTL).
    //     ODT_OFF (0) - Off
    //     ODT_120OHM (1) - 120 Ohm ODT
    //     ODT_60OHM (2) - 60 Ohm ODT
    //     ODT_40OHM (3) - 40 Ohm ODT
    //     ODT_30OHM (4) - 30 Ohm ODT
    //     ODT_RES5 (5) - Reserved
    //     ODT_20OHM (6) - 20 Ohm ODT
    //     ODT_RES7 (7) - Reserved
    writel((ODT_OFF & 0x7) << 8, IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM);

    // Config enet_RGMII_RD2 to pad RGMII_RD2(B24)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_RD2(0x020E007C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_RD2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 4 iomux modes to be used for pad: RGMII_RD2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX_DATA of instance: mipi_hsi_ctrl.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_RD2 of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_RXDATA_2_SELECT_INPUT for mode ALT1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[28] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[9] of instance: mipi_core.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_RD2);
    // Pad RGMII_RD2 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ENET_IPP_IND_MAC0_RXDATA_2_SELECT_INPUT(0x020E0850)
    //   DAISY (0) Reset: SEL_RGMII_RD2_ALT1
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: enet, In Pin: ipp_ind_mac0_rxdata[2]
    //     SEL_RGMII_RD2_ALT1 (0) - Selecting Pad: RGMII_RD2 for Mode: ALT1.
    //     SEL_KEY_COL2_ALT1 (1) - Selecting Pad: KEY_COL2 for Mode: ALT1.
    writel((SEL_RGMII_RD2_ALT1 & 0x1), IOMUXC_ENET_IPP_IND_MAC0_RXDATA_2_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_RD2(0x020E0390)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_RD2.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_RD2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: RGMII_RD2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_RD2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_RD2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //                NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_RD2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_RD2);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM(0x020E07AC)
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Select one out of next values for group: RGMII_TERM (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                RGMII_RX_CTL).
    //     ODT_OFF (0) - Off
    //     ODT_120OHM (1) - 120 Ohm ODT
    //     ODT_60OHM (2) - 60 Ohm ODT
    //     ODT_40OHM (3) - 40 Ohm ODT
    //     ODT_30OHM (4) - 30 Ohm ODT
    //     ODT_RES5 (5) - Reserved
    //     ODT_20OHM (6) - 20 Ohm ODT
    //     ODT_RES7 (7) - Reserved
    writel((ODT_OFF & 0x7) << 8, IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM);

    // Config enet_RGMII_RD3 to pad RGMII_RD3(D23)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_RD3(0x020E0080)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_RD3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 4 iomux modes to be used for pad: RGMII_RD3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX_WAKE of instance: mipi_hsi_ctrl.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_RD3 of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_RXDATA_3_SELECT_INPUT for mode ALT1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[29] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[10] of instance: mipi_core.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_RD3);
    // Pad RGMII_RD3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ENET_IPP_IND_MAC0_RXDATA_3_SELECT_INPUT(0x020E0854)
    //   DAISY (0) Reset: SEL_RGMII_RD3_ALT1
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: enet, In Pin: ipp_ind_mac0_rxdata[3]
    //     SEL_RGMII_RD3_ALT1 (0) - Selecting Pad: RGMII_RD3 for Mode: ALT1.
    //     SEL_KEY_COL0_ALT1 (1) - Selecting Pad: KEY_COL0 for Mode: ALT1.
    writel((SEL_RGMII_RD3_ALT1 & 0x1), IOMUXC_ENET_IPP_IND_MAC0_RXDATA_3_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_RD3(0x020E0394)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_RD3.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_RD3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: RGMII_RD3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_RD3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_RD3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //                NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_RD3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_RD3);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM(0x020E07AC)
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Select one out of next values for group: RGMII_TERM (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                RGMII_RX_CTL).
    //     ODT_OFF (0) - Off
    //     ODT_120OHM (1) - 120 Ohm ODT
    //     ODT_60OHM (2) - 60 Ohm ODT
    //     ODT_40OHM (3) - 40 Ohm ODT
    //     ODT_30OHM (4) - 30 Ohm ODT
    //     ODT_RES5 (5) - Reserved
    //     ODT_20OHM (6) - 20 Ohm ODT
    //     ODT_RES7 (7) - Reserved
    writel((ODT_OFF & 0x7) << 8, IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM);

    // Config enet_RGMII_RX_CTL to pad RGMII_RX_CTL(D22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_RX_CTL(0x020E006C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_RX_CTL.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 4 iomux modes to be used for pad: RGMII_RX_CTL.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: H3_DATA of instance: usboh3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_RX_CTL of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_RXEN_SELECT_INPUT for mode ALT1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[24] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[5] of instance: mipi_core.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_RX_CTL);
    // Pad RGMII_RX_CTL is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ENET_IPP_IND_MAC0_RXEN_SELECT_INPUT(0x020E0858)
    //   DAISY (0) Reset: SEL_RGMII_RX_CTL_ALT1
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: enet, In Pin: ipp_ind_mac0_rxen
    //     SEL_RGMII_RX_CTL_ALT1 (0) - Selecting Pad: RGMII_RX_CTL for Mode: ALT1.
    //     SEL_ENET_CRS_DV_ALT1 (1) - Selecting Pad: ENET_CRS_DV for Mode: ALT1.
    writel((SEL_RGMII_RX_CTL_ALT1 & 0x1), IOMUXC_ENET_IPP_IND_MAC0_RXEN_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_RX_CTL(0x020E0380)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_RX_CTL.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_RX_CTL.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: RGMII_RX_CTL.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_RX_CTL.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_RX_CTL.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //                NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_RX_CTL.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PD & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_RX_CTL);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM(0x020E07AC)
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Select one out of next values for group: RGMII_TERM (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                RGMII_RX_CTL).
    //     ODT_OFF (0) - Off
    //     ODT_120OHM (1) - 120 Ohm ODT
    //     ODT_60OHM (2) - 60 Ohm ODT
    //     ODT_40OHM (3) - 40 Ohm ODT
    //     ODT_30OHM (4) - 30 Ohm ODT
    //     ODT_RES5 (5) - Reserved
    //     ODT_20OHM (6) - 20 Ohm ODT
    //     ODT_RES7 (7) - Reserved
    writel((ODT_OFF & 0x7) << 8, IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM);

    // Config enet_RGMII_RXC to pad RGMII_RXC(B25)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_RXC(0x020E0084)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_RXC.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 4 iomux modes to be used for pad: RGMII_RXC.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: H3_STROBE of instance: usboh3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_RXC of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPP_IND_MAC0_RXCLK_SELECT_INPUT for mode ALT1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[30] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[11] of instance: mipi_core.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_RXC);
    // Pad RGMII_RXC is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ENET_IPP_IND_MAC0_RXCLK_SELECT_INPUT(0x020E0844)
    //   DAISY (0) Reset: SEL_RGMII_RXC_ALT1
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: enet, In Pin: ipp_ind_mac0_rxclk
    //     SEL_RGMII_RXC_ALT1 (0) - Selecting Pad: RGMII_RXC for Mode: ALT1.
    //     SEL_GPIO_18_ALT1 (1) - Selecting Pad: GPIO_18 for Mode: ALT1.
    writel((SEL_RGMII_RXC_ALT1 & 0x1), IOMUXC_ENET_IPP_IND_MAC0_RXCLK_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_RXC(0x020E0398)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_RXC.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_RXC.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: RGMII_RXC.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_RXC.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_RXC.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //                NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_RXC.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PD & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_RXC);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM(0x020E07AC)
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Select one out of next values for group: RGMII_TERM (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                RGMII_RX_CTL).
    //     ODT_OFF (0) - Off
    //     ODT_120OHM (1) - 120 Ohm ODT
    //     ODT_60OHM (2) - 60 Ohm ODT
    //     ODT_40OHM (3) - 40 Ohm ODT
    //     ODT_30OHM (4) - 30 Ohm ODT
    //     ODT_RES5 (5) - Reserved
    //     ODT_20OHM (6) - 20 Ohm ODT
    //     ODT_RES7 (7) - Reserved
    writel((ODT_OFF & 0x7) << 8, IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM);

    // Config enet_RGMII_TD0 to pad RGMII_TD0(C22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_TD0(0x020E005C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_TD0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 4 iomux modes to be used for pad: RGMII_TD0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX_READY of instance: mipi_hsi_ctrl.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_TD0 of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[20] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[1] of instance: mipi_core.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_TD0);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_TD0(0x020E0370)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_TD0.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_TD0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: RGMII_TD0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_TD0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_TD0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_TD0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_TD0);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);

    // Config enet_RGMII_TD1 to pad RGMII_TD1(F20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_TD1(0x020E0060)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_TD1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: RGMII_TD1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: RX_FLAG of instance: mipi_hsi_ctrl.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_TD1 of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[21] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[2] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: PLL3_BYP of instance: ccm.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_TD1);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_TD1(0x020E0374)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_TD1.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_TD1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: RGMII_TD1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_TD1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_TD1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_TD1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_TD1);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);

    // Config enet_RGMII_TD2 to pad RGMII_TD2(E21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_TD2(0x020E0064)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_TD2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: RGMII_TD2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: RX_DATA of instance: mipi_hsi_ctrl.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_TD2 of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[22] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[3] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: PLL2_BYP of instance: ccm.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_TD2);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_TD2(0x020E0378)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_TD2.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_TD2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: RGMII_TD2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_TD2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_TD2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_TD2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_TD2);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);

    // Config enet_RGMII_TD3 to pad RGMII_TD3(A24)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_TD3(0x020E0068)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_TD3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 4 iomux modes to be used for pad: RGMII_TD3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: RX_WAKE of instance: mipi_hsi_ctrl.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_TD3 of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[23] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[4] of instance: mipi_core.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_TD3);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_TD3(0x020E037C)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Select one out of next values for pad: RGMII_TD3.
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //     DDR_INPUT_DIFF (1) - Differential input mode
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_TD3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: RGMII_TD3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_TD3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_TD3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_TD3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_TD3);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);

    // Config enet_RGMII_TX_CTL to pad RGMII_TX_CTL(C23)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_TX_CTL(0x020E0074)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_TX_CTL.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: RGMII_TX_CTL.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: H2_STROBE of instance: usboh3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_TX_CTL of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[26] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[7] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_ETHERNET_REF_OUT of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPG_CLK_RMII_SELECT_INPUT for mode ALT7.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_TX_CTL);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_TX_CTL(0x020E0388)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Read Only Field
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_TX_CTL.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: RGMII_TX_CTL.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_TX_CTL.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_TX_CTL.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_TX_CTL.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PD & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_TX_CTL);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);

    // Config enet_RGMII_TXC to pad RGMII_TXC(D21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_RGMII_TXC(0x020E0058)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad RGMII_TXC.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: RGMII_TXC.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: H2_DATA of instance: usboh3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RGMII_TXC of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SPDIF_EXTCLK of instance: spdif.
    //                NOTE: - Config Register IOMUXC_SPDIF_TX_CLK2_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[19] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[0] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_24M_OUT of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_RGMII_TXC);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_RGMII_TXC(0x020E036C)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_RES0
    //                     Read Only Field
    //                     NOTE: Can be configured using Group Control Register: IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
    //     DDR_SEL_RES0 (0) - Reserved
    //   DDR_INPUT (17) - DDR / CMOS Input Mode Field Reset: DDR_INPUT_CMOS
    //                    Read Only Field
    //     DDR_INPUT_CMOS (0) - CMOS input type
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: RGMII_TXC.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: RGMII_TXC.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: RGMII_TXC.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: RGMII_TXC.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODT (10-8) - On Die Termination Field Reset: ODT_OFF
    //                Read Only Field
    //     ODT_OFF (0) - Off
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: RGMII_TXC.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    writel((DDR_SEL_RES0 & 0x3) << 18 | (DDR_INPUT_CMOS & 0x1) << 17 | (HYS_ENABLED & 0x1) << 16 |
           (PUS_100KOHM_PD & 0x3) << 14 | (PUE_PULL & 0x1) << 13 | (PKE_ENABLED & 0x1) << 12 |
           (ODT_OFF & 0x7) << 8 | (DSE_40OHM & 0x7) << 3, IOMUXC_SW_PAD_CTL_PAD_RGMII_TXC);
    // Pad Group Control Register:
    // IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII(0x020E0790)
    //   DDR_SEL (19-18) - DDR Select Field Reset: DDR_SEL_LPDDR2
    //                     Select one out of next values for group: DDR_TYPE_RGMII (Pads: RGMII_RD0 RGMII_RD1 RGMII_RD2 RGMII_RD3 RGMII_RXC
    //                     RGMII_RX_CTL RGMII_TD0 RGMII_TD1 RGMII_TD2 RGMII_TD3 RGMII_TXC RGMII_TX_CTL).
    //     DDR_SEL_RES0 (0) - Reserved
    //     DDR_SEL_RES1 (1) - Reserved
    //     DDR_SEL_LPDDR2 (2) - LPDDR2 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.2V)
    //     DDR_SEL_DDR3 (3) - DDR3 mode (240 Ohm driver unit calibration, 240, 120, 80, 60, 48, 40, 32 Ohm drive strngths at 1.5V)
    writel((DDR_SEL_LPDDR2 & 0x3) << 18, IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII);

    // Config enet_TX_CLK to pad ENET_REF_CLK(V22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK(0x020E01D4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_REF_CLK.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: ENET_REF_CLK.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: Reserved of instance: Reserved.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: TX_CLK of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: FSR of instance: esai1.
    //                NOTE: - Config Register IOMUXC_ESAI1_IPP_IND_FSR_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: DEBUG_BUS_DEVICE[4] of instance: sdma.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[23] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SRCLK of instance: spdif.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: USBPHY1_TSTO_RX_SQUELCH of instance: anatop.
    writel((SION_DISABLED & 0x1) << 4 | (ALT1 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK(0x020E04E8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_REF_CLK.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_REF_CLK.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_REF_CLK.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_REF_CLK.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_REF_CLK.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_REF_CLK.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_REF_CLK.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_REF_CLK.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK);
}
