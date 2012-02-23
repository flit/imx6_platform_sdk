/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _HDMI_H
#define _HDMI_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_HDMI_DESIGN_ID - Design Identification Register
 * - HW_HDMI_REVISION_ID - Revision Identification Register
 * - HW_HDMI_PRODUCT_ID0 - Product Identification Register 0
 * - HW_HDMI_PRODUCT_ID1 - Product Identification Register 1
 * - HW_HDMI_CONFIG0_ID - Configuration Identification Register 0
 * - HW_HDMI_CONFIG1_ID - Configuration Identification Register 1
 * - HW_HDMI_CONFIG2_ID - Configuration Identification Register 2
 * - HW_HDMI_CONFIG3_ID - Configuration Identification Register 3
 * - HW_HDMI_IH_FC_STAT0 - Frame Composer Interrupt Status Register 0
 * - HW_HDMI_IH_FC_STAT1 - Frame Composer Interrupt Status Register 1
 * - HW_HDMI_IH_FC_STAT2 - Frame Composer Interrupt Status Register 2
 * - HW_HDMI_IH_AS_STAT0 - Audio Sampler Interrupt Status Register
 * - HW_HDMI_IH_PHY_STAT0 - PHY Interface Interrupt Status Register
 * - HW_HDMI_IH_I2CM_STAT0 - E-DDC I2C Master Interrupt Status Register
 * - HW_HDMI_IH_CEC_STAT0 - CEC Interrupt Status Register
 * - HW_HDMI_IH_VP_STAT0 - Video Packetizer Interrupt Status Register
 * - HW_HDMI_IH_I2CMPHY_STAT0 - PHY GEN2 I2C Master Interrupt Status Register
 * - HW_HDMI_IH_AHBDMAAUD_STAT0 - AHB Audio DMA Interrupt Status Register
 * - HW_HDMI_IH_MUTE_FC_STAT0 - Frame Composer Interrupt Mute Control Register 0
 * - HW_HDMI_IH_MUTE_FC_STAT1 - Frame Composer Interrupt Mute Control Register 1
 * - HW_HDMI_IH_MUTE_FC_STAT2 - Frame Composer Interrupt Mute Control Register 2
 * - HW_HDMI_IH_MUTE_AS_STAT0 - Audio Sampler Interrupt Mute Control Register 0
 * - HW_HDMI_IH_MUTE_PHY_STAT0 - PHY Interface Interrupt Mute Control Register
 * - HW_HDMI_IH_MUTE_I2CM_STAT0 - E-DDC I2C Master Interrupt Mute Control Register
 * - HW_HDMI_IH_MUTE_CEC_STAT0 - CEC Interrupt Mute Control Register
 * - HW_HDMI_IH_MUTE_VP_STAT0 - Video Packetizer Interrupt Mute Control Register
 * - HW_HDMI_IH_MUTE_I2CMPHY_STAT0 - PHY GEN 2 I2C Master Interrupt Mute Control Register
 * - HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0 - AHB Audio DMA Interrupt Mute Control Register
 * - HW_HDMI_IH_MUTE - Global Interrupt Mute Control Register
 * - HW_HDMI_TX_INVID0 - Video Input Mapping and Internal Data Enable Configuration Register
 * - HW_HDMI_TX_INSTUFFING - Video Input Stuffing Enable Register
 * - HW_HDMI_TX_GYDATA0 - Video Input GY Data Channel Stuffing Register 0
 * - HW_HDMI_TX_GYDATA1 - Video Input GY Data Channel Stuffing Register 1
 * - HW_HDMI_TX_RCRDATA0 - Video Input RCR Data Channel Stuffing Register 0
 * - HW_HDMI_TX_RCRDATA1 - Video Input RCR Data Channel Stuffing Register 1
 * - HW_HDMI_TX_BCBDATA0 - Video Input RCB Data Channel Stuffing Register 0
 * - HW_HDMI_TX_BCBDATA1 - Video Input RCB Data Channel Stuffing Register 1
 * - HW_HDMI_VP_STATUS - Video Packetizer Packing Phase Status Register
 * - HW_HDMI_VP_PR_CD - Video Packetizer Pixel Repetition and Color Depth Register
 * - HW_HDMI_VP_STUFF - Video Packetizer Stuffing and Default Packing Phase Register
 * - HW_HDMI_VP_REMAP - Video Packetizer YCC422 Remapping Register
 * - HW_HDMI_VP_CONF - Video Packetizer Output, Bypass, and Enable Configuration Register
 * - HW_HDMI_VP_STAT - VP_STAT
 * - HW_HDMI_VP_INT - VP_INT
 * - HW_HDMI_VP_MASK - Video Packetizer Interrupt Mask Register
 * - HW_HDMI_VP_POL - VP_POL
 * - HW_HDMI_FC_INVIDCONF - Frame Composer Input Video Configuration and HDCP Keepout Register
 * - HW_HDMI_FC_INHACTIV0 - Frame Composer Input Video HActive Pixels Register 0
 * - HW_HDMI_FC_INHACTIV1 - Frame Composer Input Video HActive Pixels Register 1
 * - HW_HDMI_FC_INHBLANK0 - Frame Composer Input Video HBlank Pixels Register 0
 * - HW_HDMI_FC_INHBLANK1 - Frame Composer Input Video HBlank Pixels Register 1
 * - HW_HDMI_FC_INVACTIV0 - Frame Composer Input Video VActive Pixels Register 0
 * - HW_HDMI_FC_INVACTIV1 - Frame Composer Input Video VActive Pixels Register 1
 * - HW_HDMI_FC_INVBLANK - Frame Composer Input Video VBlank Pixels Register
 * - HW_HDMI_FC_HSYNCINDELAY0 - Frame Composer Input Video HSync Front Porch Register 0
 * - HW_HDMI_FC_HSYNCINDELAY1 - Frame Composer Input Video HSync Front Porch Register 1
 * - HW_HDMI_FC_HSYNCINWIDTH0 - Frame Composer Input Video HSync Width Register 0
 * - HW_HDMI_FC_HSYNCINWIDTH1 - Frame Composer Input Video HSync Width Register 1
 * - HW_HDMI_FC_VSYNCINDELAY - Frame Composer Input Video VSync Front Porch Register
 * - HW_HDMI_FC_VSYNCINWIDTH - Frame Composer Input Video VSync Width Register
 * - HW_HDMI_FC_INFREQ0 - Frame Composer Input Video Refresh Rate Register 0
 * - HW_HDMI_FC_INFREQ1 - Frame Composer Input Video Refresh Rate Register 1
 * - HW_HDMI_FC_INFREQ2 - Frame Composer Input Video Refresh Rate Register 2
 * - HW_HDMI_FC_CTRLDUR - Frame Composer Control Period Duration Register
 * - HW_HDMI_FC_EXCTRLDUR - Frame Composer Extended Control Period Duration Register
 * - HW_HDMI_FC_EXCTRLSPAC - Frame Composer Extended Control Period Maximum Spacing Register
 * - HW_HDMI_FC_CH0PREAM - Frame Composer Channel 0 Non-Preamble Data Register
 * - HW_HDMI_FC_CH1PREAM - Frame Composer Channel 1 Non-Preamble Data Register
 * - HW_HDMI_FC_CH2PREAM - Frame Composer Channel 2 Non-Preamble Data Register
 * - HW_HDMI_FC_AVICONF3 - Frame Composer AVI Configuration Register 3
 * - HW_HDMI_FC_GCP - Frame Composer GCP Packet Configuration Register
 * - HW_HDMI_FC_AVICONF0 - Frame Composer AVI Packet Configuration Register 0
 * - HW_HDMI_FC_AVICONF1 - Frame Composer AVI Packet Configuration Register 1
 * - HW_HDMI_FC_AVICONF2 - FC_AVICONFFrame Composer AVI Packet Configuration Register 2
 * - HW_HDMI_FC_AVIVID - Frame Composer AVI Packet VIC Register
 * - HW_HDMI_FC_AVIETB0 - Frame Composer AVI Packet End of Top Bar Register 0
 * - HW_HDMI_FC_AVIETB1 - Frame Composer AVI Packet End of Top Bar Register 1
 * - HW_HDMI_FC_AVISBB0 - Frame Composer AVI Packet Start of Bottom Bar Register 0
 * - HW_HDMI_FC_AVISBB1 - Frame Composer AVI Packet Start of Bottom Bar Register 1
 * - HW_HDMI_FC_AVIELB0 - Frame Composer AVI Packet End of Left Bar Register 0
 * - HW_HDMI_FC_AVIELB1 - Frame Composer AVI Packet End of Left Bar Register 1
 * - HW_HDMI_FC_AVISRB0 - Frame Composer AVI Packet Start of Right Bar Register 0
 * - HW_HDMI_FC_AVISRB1 - Frame Composer AVI Packet Start of Right Bar Register 1
 * - HW_HDMI_FC_AUDICONF0 - Frame Composer AUD Packet Configuration Register 0
 * - HW_HDMI_FC_AUDICONF1 - Frame Composer AUD Packet Configuration Register 1
 * - HW_HDMI_FC_AUDICONF2 - Frame Composer AUD Packet Configuration Register 2
 * - HW_HDMI_FC_AUDICONF3 - Frame Composer AUD Packet Configuration Register 3
 * - HW_HDMI_FC_VSDIEEEID0 - Frame Composer VSI Packet Data IEEE Register 0
 * - HW_HDMI_FC_VSDSIZE - Frame Composer VSI Packet Data Size Register
 * - HW_HDMI_FC_VSDIEEEID1 - Frame Composer VSI Packet Data IEEE Register 1
 * - HW_HDMI_FC_VSDIEEEID2 - Frame Composer VSI Packet Data IEEE Register 2
 * - HW_HDMI_FC_VSDPAYLOAD0 - Frame Composer VSI Packet Data IEEE Register 0
 * - HW_HDMI_FC_VSDPAYLOAD1 - Frame Composer VSI Packet Data IEEE Register 1
 * - HW_HDMI_FC_VSDPAYLOAD2 - Frame Composer VSI Packet Data IEEE Register 2
 * - HW_HDMI_FC_VSDPAYLOAD3 - Frame Composer VSI Packet Data IEEE Register 3
 * - HW_HDMI_FC_VSDPAYLOAD4 - Frame Composer VSI Packet Data IEEE Register 4
 * - HW_HDMI_FC_VSDPAYLOAD5 - Frame Composer VSI Packet Data IEEE Register 5
 * - HW_HDMI_FC_VSDPAYLOAD6 - Frame Composer VSI Packet Data IEEE Register 6
 * - HW_HDMI_FC_VSDPAYLOAD7 - Frame Composer VSI Packet Data IEEE Register 7
 * - HW_HDMI_FC_VSDPAYLOAD8 - Frame Composer VSI Packet Data IEEE Register 8
 * - HW_HDMI_FC_VSDPAYLOAD9 - Frame Composer VSI Packet Data IEEE Register 9
 * - HW_HDMI_FC_VSDPAYLOAD10 - Frame Composer VSI Packet Data IEEE Register 10
 * - HW_HDMI_FC_VSDPAYLOAD11 - Frame Composer VSI Packet Data IEEE Register 11
 * - HW_HDMI_FC_VSDPAYLOAD12 - Frame Composer VSI Packet Data IEEE Register 12
 * - HW_HDMI_FC_VSDPAYLOAD13 - Frame Composer VSI Packet Data IEEE Register 13
 * - HW_HDMI_FC_VSDPAYLOAD14 - Frame Composer VSI Packet Data IEEE Register 14
 * - HW_HDMI_FC_VSDPAYLOAD15 - Frame Composer VSI Packet Data IEEE Register 15
 * - HW_HDMI_FC_VSDPAYLOAD16 - Frame Composer VSI Packet Data IEEE Register 16
 * - HW_HDMI_FC_VSDPAYLOAD17 - Frame Composer VSI Packet Data IEEE Register 17
 * - HW_HDMI_FC_VSDPAYLOAD18 - Frame Composer VSI Packet Data IEEE Register 18
 * - HW_HDMI_FC_VSDPAYLOAD19 - Frame Composer VSI Packet Data IEEE Register 19
 * - HW_HDMI_FC_VSDPAYLOAD20 - Frame Composer VSI Packet Data IEEE Register 20
 * - HW_HDMI_FC_VSDPAYLOAD21 - Frame Composer VSI Packet Data IEEE Register 21
 * - HW_HDMI_FC_VSDPAYLOAD22 - Frame Composer VSI Packet Data IEEE Register 22
 * - HW_HDMI_FC_VSDPAYLOAD23 - Frame Composer VSI Packet Data IEEE Register 23
 * - HW_HDMI_FC_SPDVENDORNAME0 - Frame Composer SPD Packet Data Vendor Name Register 0
 * - HW_HDMI_FC_SPDPRODUCTNAME0 - Frame Composer SPD Packet Data Product Name Register 0
 * - HW_HDMI_FC_SPDDEVICEINF - Frame Composer SPD Packet Data Source Product Descriptor Register
 * - HW_HDMI_FC_AUDSCONF - Frame Composer Audio Sample Flat and Layout Configuration Register
 * - HW_HDMI_FC_AUDSSTAT - Frame Composer Audio Packet Sample Present Status Register
 * - HW_HDMI_FC_CTRLQHIGH - Frame Composer Number of High Priority Packets Attended Configuration Register
 * - HW_HDMI_FC_CTRLQLOW - Frame Composer Number of Low Priority Packets Attended Configuration Register
 * - HW_HDMI_FC_ACP0 - Frame Composer ACP Packet Type Configuration Register 0
 * - HW_HDMI_FC_ACP1 - Frame Composer ACP Packet Type Configuration Register 1
 * - HW_HDMI_FC_ISCR1_0 - FC_ISCR1_Frame Composer Packet Status, Valid, and Continue Configuration Register
 * - HW_HDMI_FC_ISCR1_1 - Frame Composer ISCR1 Packet Body Register 1
 * - HW_HDMI_FC_ISCR2_0 - Frame Composer ISCR2 Packet Body Register 0
 * - HW_HDMI_FC_DATAUTO0 - Frame Composer Data Island Auto Packet Scheduling Register 0
 * - HW_HDMI_FC_DATAUTO1 - Frame Composer Data Island Auto Packet Scheduling Register 1
 * - HW_HDMI_FC_DATAUTO2 - Frame Composer Data Island Auto Packet Scheduling Register 2
 * - HW_HDMI_FC_DATMAN - Frame Composer Data Island Manual Packet Request Register
 * - HW_HDMI_FC_DATAUTO3 - Frame Composer Data Island Auto Packet Scheduling Register 3
 * - HW_HDMI_FC_RDRB0 - Frame Composer Round Robin ACR Packet Insertion Register 0
 * - HW_HDMI_FC_RDRB1 - Frame Composer Round Robin ACR Packet Insertion Register 1
 * - HW_HDMI_FC_RDRB2 - Frame Composer Round Robin ACR Packet Insertion Register 2
 * - HW_HDMI_FC_RDRB3 - Frame Composer Round Robin ACR Packet Insertion Register 3
 * - HW_HDMI_FC_RDRB4 - Frame Composer Round Robin ACR Packet Insertion Register 4
 * - HW_HDMI_FC_RDRB5 - Frame Composer Round Robin ACR Packet Insertion Register 5
 * - HW_HDMI_FC_RDRB6 - Frame Composer Round Robin ACR Packet Insertion Register 6
 * - HW_HDMI_FC_RDRB7 - Frame Composer Round Robin ACR Packet Insertion Register 7
 * - HW_HDMI_FC_STAT0 - FC_STAT0
 * - HW_HDMI_FC_INT0 - FC_INT0
 * - HW_HDMI_FC_MASK0 - Frame Composer Packet Interrupt Mask Register 0
 * - HW_HDMI_FC_POL0 - FC_POL0
 * - HW_HDMI_FC_STAT1 - FC_STAT1
 * - HW_HDMI_FC_INT1 - FC_INT1
 * - HW_HDMI_FC_MASK1 - Frame Composer Packet Interrupt Mask Register 1
 * - HW_HDMI_FC_POL1 - FC_POL1
 * - HW_HDMI_FC_STAT2 - FC_STAT2
 * - HW_HDMI_FC_INT2 - FC_INT2
 * - HW_HDMI_FC_MASK2 - Frame Composer High/Low Priority Overflow Interrupt Mask Register 2
 * - HW_HDMI_FC_POL2 - FC_POL2
 * - HW_HDMI_FC_PRCONF - Frame Composer Pixel Repetition Configuration Register
 * - HW_HDMI_FC_GMD_STAT - Frame Composer GMD Packet Status Register
 * - HW_HDMI_FC_GMD_EN - Frame Composer GMD Packet Enable Register
 * - HW_HDMI_FC_GMD_UP - Frame Composer GMD Packet Update Register
 * - HW_HDMI_FC_GMD_CONF - Frame Composer GMD Packet Schedule Configuration Register
 * - HW_HDMI_FC_GMD_HB - Frame Composer GMD Packet Profile and Gamut Sequence Configuration Register
 * - HW_HDMI_FC_GMD_PB0 - Frame Composer GMD Packet Body Register 0
 * - HW_HDMI_FC_GMD_PB1 - Frame Composer GMD Packet Body Register 1
 * - HW_HDMI_FC_GMD_PB2 - Frame Composer GMD Packet Body Register 2
 * - HW_HDMI_FC_GMD_PB3 - Frame Composer GMD Packet Body Register 3
 * - HW_HDMI_FC_GMD_PB4 - Frame Composer GMD Packet Body Register 4
 * - HW_HDMI_FC_GMD_PB5 - Frame Composer GMD Packet Body Register 5
 * - HW_HDMI_FC_GMD_PB6 - Frame Composer GMD Packet Body Register 6
 * - HW_HDMI_FC_GMD_PB7 - Frame Composer GMD Packet Body Register 7
 * - HW_HDMI_FC_GMD_PB8 - Frame Composer GMD Packet Body Register 8
 * - HW_HDMI_FC_GMD_PB9 - Frame Composer GMD Packet Body Register 9
 * - HW_HDMI_FC_GMD_PB10 - Frame Composer GMD Packet Body Register 10
 * - HW_HDMI_FC_GMD_PB11 - Frame Composer GMD Packet Body Register 11
 * - HW_HDMI_FC_GMD_PB12 - Frame Composer GMD Packet Body Register 12
 * - HW_HDMI_FC_GMD_PB13 - Frame Composer GMD Packet Body Register 13
 * - HW_HDMI_FC_GMD_PB14 - Frame Composer GMD Packet Body Register 14
 * - HW_HDMI_FC_GMD_PB15 - Frame Composer GMD Packet Body Register 15
 * - HW_HDMI_FC_GMD_PB16 - Frame Composer GMD Packet Body Register 16
 * - HW_HDMI_FC_GMD_PB17 - Frame Composer GMD Packet Body Register 17
 * - HW_HDMI_FC_GMD_PB18 - Frame Composer GMD Packet Body Register 18
 * - HW_HDMI_FC_GMD_PB19 - Frame Composer GMD Packet Body Register 19
 * - HW_HDMI_FC_GMD_PB20 - Frame Composer GMD Packet Body Register 20
 * - HW_HDMI_FC_GMD_PB21 - Frame Composer GMD Packet Body Register 21
 * - HW_HDMI_FC_GMD_PB22 - Frame Composer GMD Packet Body Register 22
 * - HW_HDMI_FC_GMD_PB23 - Frame Composer GMD Packet Body Register 23
 * - HW_HDMI_FC_GMD_PB24 - Frame Composer GMD Packet Body Register 24
 * - HW_HDMI_FC_GMD_PB25 - Frame Composer GMD Packet Body Register 25
 * - HW_HDMI_FC_GMD_PB26 - Frame Composer GMD Packet Body Register 26
 * - HW_HDMI_FC_GMD_PB27 - Frame Composer GMD Packet Body Register 27
 * - HW_HDMI_FC_DBGFORCE - Frame Composer Video/Audio Force Enable Register
 * - HW_HDMI_FC_DBGAUD0CH0 - Frame Composer Audio Channel 0 Register 0
 * - HW_HDMI_FC_DBGAUD1CH0 - Frame Composer Audio Channel 0 Register 1
 * - HW_HDMI_FC_DBGAUD2CH0 - Frame Composer Audio Channel 0 Register 2
 * - HW_HDMI_FC_DBGAUD0CH1 - Frame Composer Audio Channel 1 Register 0
 * - HW_HDMI_FC_DBGAUD1CH1 - Frame Composer Audio Channel 1 Register 1
 * - HW_HDMI_FC_DBGAUD2CH1 - Frame Composer Audio Channel 1 Register 2
 * - HW_HDMI_FC_DBGAUD0CH2 - Frame Composer Debug Audio Channel 2 Register 0
 * - HW_HDMI_FC_DBGAUD1CH2 - Frame Composer Debug Audio Channel 2 Register 1
 * - HW_HDMI_FC_DBGAUD2CH2 - Frame Composer Audio Channel 2 Register 2
 * - HW_HDMI_FC_DBGAUD0CH3 - Frame Composer Audio Channel 3 Register 0
 * - HW_HDMI_FC_DBGAUD1CH3 - Frame Composer Audio Channel 3 Register 1
 * - HW_HDMI_FC_DBGAUD2CH3 - Frame Composer Audio Channel 3 Register 2
 * - HW_HDMI_FC_DBGAUD0CH4 - Frame Composer Audio Channel 4 Register 0
 * - HW_HDMI_FC_DBGAUD1CH4 - Frame Composer Audio Channel 4 Register 1
 * - HW_HDMI_FC_DBGAUD2CH4 - Frame Composer Audio Channel 4 Register 2
 * - HW_HDMI_FC_DBGAUD0CH5 - Frame Composer Audio Channel 5 Register 0
 * - HW_HDMI_FC_DBGAUD1CH5 - Frame Composer Audio Channel 5 Register 1
 * - HW_HDMI_FC_DBGAUD2CH5 - Frame Composer Audio Channel 5 Register 2
 * - HW_HDMI_FC_DBGAUD0CH6 - Frame Composer Audio Channel 6 Register 0
 * - HW_HDMI_FC_DBGAUD1CH6 - Frame Composer Audio Channel 6 Register 1
 * - HW_HDMI_FC_DBGAUD2CH6 - Frame Composer Audio Channel 6 Register 2
 * - HW_HDMI_FC_DBGAUD0CH7 - Frame Composer Audio Channel 7 Register 1
 * - HW_HDMI_FC_DBGAUD1CH7 - Frame Composer Audio Channel 7 Register 0
 * - HW_HDMI_FC_DBGAUD2CH7 - Frame Composer Audio Channel 7 Register 2
 * - HW_HDMI_FC_DBGTMDS0 - Frame Composer TMDS Channel 0 Register
 * - HW_HDMI_FC_DBGTMDS1 - Frame Composer TMDS Channel 1 Register
 * - HW_HDMI_FC_DBGTMDS2 - Frame Composer TMDS Channel 2 Register
 * - HW_HDMI_PHY_CONF0 - PHY Configuration Register
 * - HW_HDMI_PHY_TST0 - PHY Test Interface Register 0
 * - HW_HDMI_PHY_TST1 - PHY Test Interface Register 1
 * - HW_HDMI_PHY_TST2 - PHY Test Interface Register 2
 * - HW_HDMI_PHY_STAT0 - PHY RXSENSE, PLL lock, and HPD Status Register
 * - HW_HDMI_PHY_INT0 - PHY RXSENSE, PLL lock, and HPD Interrupt Register
 * - HW_HDMI_PHY_MASK0 - PHY RXSENSE, PLL lock, and HPD Mask Register
 * - HW_HDMI_PHY_POL0 - PHY RXSENSE, PLL lock and HPD Polarity Register
 * - HW_HDMI_PHY_I2CM_SLAVE_ADDR - PHY I2C Slave Address Configuration Register
 * - HW_HDMI_PHY_I2CM_ADDRESS_ADDR - PHY I2C Address Configuration Register
 * - HW_HDMI_PHY_I2CM_DATAO_1_ADDR - PHY I2C Data Write Register 1
 * - HW_HDMI_PHY_I2CM_DATAO_0_ADDR - PHY I2C Data Write Register 0
 * - HW_HDMI_PHY_I2CM_DATAI_1_ADDR - PHY I2C Data Read Register 1
 * - HW_HDMI_PHY_I2CM_DATAI_0_ADDR - PHY I2C Data Read Register 0
 * - HW_HDMI_PHY_I2CM_OPERATION_ADDR - PHY I2C Read/Write Operation
 * - HW_HDMI_PHY_I2CM_INT_ADDR - PHY I2C Done Interrupt Register
 * - HW_HDMI_PHY_I2CM_CTLINT_ADDR - PHY I2C Done Interrupt Register
 * - HW_HDMI_PHY_I2CM_DIV_ADDR - PHY I2C Speed Control Register
 * - HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR - PHY I2C Software Reset Register
 * - HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR - PHY I2C Slow Speed SCL High Level Control Register 1
 * - HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR - PHY I2C Slow Speed SCL High Level Control Register 0
 * - HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR - PHY I2C Slow Speed SCL Low Level Control Register 1
 * - HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR - PHY I2C Slow Speed SCL Low Level Control Register 0
 * - HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR - PHY I2C Fast Speed SCL High Level Control Register 1
 * - HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR - PHY I2C Fast Speed SCL High Level Control Register 0
 * - HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR - PHY I2C Fast Speed SCL Low Level Control Register 1
 * - HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR - PHY I2C Fast Speed SCL Low Level Control Register 0
 * - HW_HDMI_AUD_N1 - Audio Clock Regenerator N Value Register 1
 * - HW_HDMI_AUD_N2 - Audio Clock Regenerator N Value Register 2
 * - HW_HDMI_AUD_N3 - Audio Clock Regenerator N Value Register 3
 * - HW_HDMI_AUD_CTS1 - AUD_CTS1
 * - HW_HDMI_AUD_CTS2 - AUD_CTS2
 * - HW_HDMI_AUD_CTS3 - AUD_CTS3
 * - HW_HDMI_AHB_DMA_CONF0 - Audio DMA Start Register
 * - HW_HDMI_AHB_DMA_START - AHB_DMA_START
 * - HW_HDMI_AHB_DMA_STOP - Audio DMA Stop Register
 * - HW_HDMI_AHB_DMA_THRSLD - Audio DMA FIFO Threshold Register
 * - HW_HDMI_AHB_DMA_STRADDR0 - Audio DMA Start Address Register 0
 * - HW_HDMI_AHB_DMA_STRADDR1 - Audio DMA Start Address Register 1
 * - HW_HDMI_AHB_DMA_STRADDR2 - Audio DMA Start Address Register 2
 * - HW_HDMI_AHB_DMA_STRADDR3 - Audio DMA Start Address Register 3
 * - HW_HDMI_AHB_DMA_STPADDR0 - Audio DMA Stop Address Register 0
 * - HW_HDMI_AHB_DMA_STPADDR1 - Audio DMA Stop Address Register 1
 * - HW_HDMI_AHB_DMA_STPADDR2 - Audio DMA Stop Address Register 2
 * - HW_HDMI_AHB_DMA_STPADDR3 - Audio DMA Stop Address Register 3
 * - HW_HDMI_AHB_DMA_BSTADDR0 - Audio DMA Burst Start Address Register 0
 * - HW_HDMI_AHB_DMA_BSTADDR1 - Audio DMA Burst Start Address Register 1
 * - HW_HDMI_AHB_DMA_BSTADDR2 - Audio DMA Burst Start Address Register 2
 * - HW_HDMI_AHB_DMA_BSTADDR3 - Audio DMA Burst Start Address Register 3
 * - HW_HDMI_AHB_DMA_MBLENGTH0 - Audio DMA Burst Length Register 0
 * - HW_HDMI_AHB_DMA_MBLENGTH1 - Audio DMA Burst Length Register 1
 * - HW_HDMI_AHB_DMA_STAT - Audio DMA Interrupt Status Register
 * - HW_HDMI_AHB_DMA_INT - Audio DMA Interrupt Register
 * - HW_HDMI_AHB_DMA_MASK - Audio DMA Mask Interrupt Register
 * - HW_HDMI_AHB_DMA_POL - Audio DMA Polarity Interrupt Register
 * - HW_HDMI_AHB_DMA_CONF1 - Audio DMA Channel Enable Configuration Register 1
 * - HW_HDMI_AHB_DMA_BUFFSTAT - Audio DMA Buffer Interrupt Status Register
 * - HW_HDMI_AHB_DMA_BUFFINT - Audio DMA Buffer Interrupt Register
 * - HW_HDMI_AHB_DMA_BUFFMASK - Audio DMA Buffer Mask Interrupt Register
 * - HW_HDMI_AHB_DMA_BUFFPOL - Audio DMA Buffer Polarity Interrupt Register
 * - HW_HDMI_MC_CLKDIS - Main Controller Synchronous Clock Domain Disable Register
 * - HW_HDMI_MC_SWRSTZREQ - Main Controller Software Reset Register
 * - HW_HDMI_MC_FLOWCTRL - Main Controller Feed Through Control Register
 * - HW_HDMI_MC_PHYRSTZ - Main Controller PHY Reset Register
 * - HW_HDMI_MC_LOCKONCLOCK - Main Controller Clock Present Register
 * - HW_HDMI_MC_HEACPHY_RST - Main Controller HEAC PHY Reset Register
 * - HW_HDMI_CSC_CFG - Color Space Converter Interpolation and Decimation Configuration Register
 * - HW_HDMI_CSC_SCALE - Color Space Converter Scale and Deep Color Configuration Register
 * - HW_HDMI_CSC_COEF_A1_MSB - CSC_COEF_A1_MSB
 * - HW_HDMI_CSC_COEF_A1_LSB - CSC_COEF_A1_LSB
 * - HW_HDMI_CSC_COEF_A2_MSB - CSC_COEF_A2_MSB
 * - HW_HDMI_CSC_COEF_A2_LSB - CSC_COEF_A2_LSB
 * - HW_HDMI_CSC_COEF_A3_MSB - CSC_COEF_A3_MSB
 * - HW_HDMI_CSC_COEF_A3_LSB - CSC_COEF_A3_LSB
 * - HW_HDMI_CSC_COEF_A4_MSB - CSC_COEF_A4_MSB
 * - HW_HDMI_CSC_COEF_A4_LSB - CSC_COEF_A4_LSB
 * - HW_HDMI_CSC_COEF_B1_MSB - CSC_COEF_B1_MSB
 * - HW_HDMI_CSC_COEF_B1_LSB - CSC_COEF_B1_LSB
 * - HW_HDMI_CSC_COEF_B2_MSB - CSC_COEF_B2_MSB
 * - HW_HDMI_CSC_COEF_B2_LSB - CSC_COEF_B2_LSB
 * - HW_HDMI_CSC_COEF_B3_MSB - CSC_COEF_B3_MSB
 * - HW_HDMI_CSC_COEF_B3_LSB - CSC_COEF_B3_LSB
 * - HW_HDMI_CSC_COEF_B4_MSB - CSC_COEF_B4_MSB
 * - HW_HDMI_CSC_COEF_B4_LSB - CSC_COEF_B4_LSB
 * - HW_HDMI_CSC_COEF_C1_MSB - CSC_COEF_C1_MSB
 * - HW_HDMI_CSC_COEF_C1_LSB - CSC_COEF_C1_LSB
 * - HW_HDMI_CSC_COEF_C2_MSB - CSC_COEF_C2_MSB
 * - HW_HDMI_CSC_COEF_C2_LSB - CSC_COEF_C2_LSB
 * - HW_HDMI_CSC_COEF_C3_MSB - CSC_COEF_C3_MSB
 * - HW_HDMI_CSC_COEF_C3_LSB - CSC_COEF_C3_LSB
 * - HW_HDMI_CSC_COEFC4_MSB - CSC_COEFC4_MSB
 * - HW_HDMI_CSC_COEFC4_LSB - CSC_COEFC4_LSB
 * - HW_HDMI_A_HDCPCFG0 - A_HDCPCFG0
 * - HW_HDMI_A_HDCPCFG1 - A_HDCPCFG1
 * - HW_HDMI_A_HDCPOBS0 - A_HDCPOBS0
 * - HW_HDMI_A_HDCPOBS1 - A_HDCPOBS1
 * - HW_HDMI_A_HDCPOBS2 - A_HDCPOBS2
 * - HW_HDMI_A_HDCPOBS3 - A_HDCPOBS3
 * - HW_HDMI_A_APIINTCLR - A_APIINTCLR
 * - HW_HDMI_A_APIINTSTAT - A_APIINTSTAT
 * - HW_HDMI_A_APIINTMSK - A_APIINTMSK
 * - HW_HDMI_A_VIDPOLCFG - A_VIDPOLCFG
 * - HW_HDMI_A_OESSWCFG - A_OESSWCFG
 * - HW_HDMI_A_COREVERLSB - A_COREVERLSB
 * - HW_HDMI_A_COREVERMSB - A_COREVERMSB
 * - HW_HDMI_A_KSVMEMCTRL - A_KSVMEMCTRL
 * - HW_HDMI_HDCPREG_BKSV0 - HDCPREG_BKSV0
 * - HW_HDMI_HDCPREG_BKSV1 - HDCPREG_BKSV1
 * - HW_HDMI_HDCPREG_BKSV2 - HDCPREG_BKSV2
 * - HW_HDMI_HDCPREG_BKSV3 - HDCPREG_BKSV3
 * - HW_HDMI_HDCPREG_BKSV4 - HDCPREG_BKSV4
 * - HW_HDMI_HDCPREG_ANCONF - HDCPREG_ANCONF
 * - HW_HDMI_HDCPREG_AN0 - HDCPREG_AN0
 * - HW_HDMI_HDCPREG_AN1 - HDCPREG_AN1
 * - HW_HDMI_HDCPREG_AN2 - HDCPREG_AN2
 * - HW_HDMI_HDCPREG_AN3 - HDCPREG_AN3
 * - HW_HDMI_HDCPREG_AN4 - HDCPREG_AN4
 * - HW_HDMI_HDCPREG_AN5 - HDCPREG_AN5
 * - HW_HDMI_HDCPREG_AN6 - HDCPREG_AN6
 * - HW_HDMI_HDCPREG_AN7 - HDCPREG_AN7
 * - HW_HDMI_CEC_CTRL - CEC_CTRL
 * - HW_HDMI_CEC_STAT - CEC_STAT
 * - HW_HDMI_CEC_MASK - CEC_MASK
 * - HW_HDMI_CEC_POLARITY - CEC_POLARITY
 * - HW_HDMI_CEC_INT - CEC_INT
 * - HW_HDMI_CEC_ADDR_L - CEC_ADDR_L
 * - HW_HDMI_CEC_ADDR_H - CEC_ADDR_H
 * - HW_HDMI_CEC_TX_CNT - CEC_TX_CNT
 * - HW_HDMI_CEC_RX_CNT - CEC_RX_CNT
 * - HW_HDMI_CEC_TX_DATAN - CEC_TX_DATAn
 * - HW_HDMI_CEC_RX_DATAN - CEC_RX_DATAn
 * - HW_HDMI_CEC_LOCK - CEC_LOCK
 * - HW_HDMI_CEC_WKUPCTRL - CEC_WKUPCTRL
 * - HW_HDMI_I2CM_SLAVE - I2CM_SLAVE
 * - HW_HDMI_I2CM_ADDRESS - I2CM_ADDRESS
 * - HW_HDMI_I2CM_DATAO - I2CM_DATAO
 * - HW_HDMI_I2CM_DATAI - I2CM_DATAI
 * - HW_HDMI_I2CM_OPERATION - I2CM_OPERATION
 * - HW_HDMI_I2CM_INT - I2CM_INT
 * - HW_HDMI_I2CM_CTLINT - I2CM_CTLINT
 * - HW_HDMI_I2CM_DIV - I2CM_DIV
 * - HW_HDMI_I2CM_SEGADDR - I2CM_SEGADDR
 * - HW_HDMI_I2CM_SOFTRSTZ - I2CM_SOFTRSTZ
 * - HW_HDMI_I2CM_SEGPTR - I2CM_SEGPTR
 * - HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR - I2CM_SS_SCL_HCNT_1_ADDR
 * - HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR - I2CM_SS_SCL_HCNT_0_ADDR
 * - HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR - I2CM_SS_SCL_LCNT_1_ADDR
 * - HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR - I2CM_SS_SCL_LCNT_0_ADDR
 * - HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR - I2CM_FS_SCL_HCNT_1_ADDR
 * - HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR - I2CM_FS_SCL_HCNT_0_ADDR
 * - HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR - I2CM_FS_SCL_LCNT_1_ADDR
 * - HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR - I2CM_FS_SCL_LCNT_0_ADDR
 * - HW_HDMI_BASE_POINTER_ADDR - BASE_POINTER_ADDR
 *
 * hw_hdmi_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_HDMI_BASE
#define REGS_HDMI_BASE (0x00120000) //!< Base address for HDMI.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_DESIGN_ID - Design Identification Register (RO)
 *
 * The following are the registers used to identify the HDMI TX controller.   Name: Design
 * Identification Register  Address Offset: 0x0000  Size: 8 bits  Value after Reset: Implementation
 * Dependent  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DESIGN_ID : 8; //!< This is a 1 byte design ID code fixed by Freescale that Identifies the main revision of the HDMI TX controller. For example, HDMI TX 1.30a, DESIGN_ID = 11h; REVISION_ID = 0Ah
    } B;
} hw_hdmi_design_id_t;
#endif

/*
 * constants & macros for entire HDMI_DESIGN_ID register
 */
#define HW_HDMI_DESIGN_ID_ADDR      (REGS_HDMI_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_DESIGN_ID           (*(volatile hw_hdmi_design_id_t *) HW_HDMI_DESIGN_ID_ADDR)
#define HW_HDMI_DESIGN_ID_RD()      (HW_HDMI_DESIGN_ID.U)
#endif

/*
 * constants & macros for individual HDMI_DESIGN_ID bitfields
 */

/* --- Register HW_HDMI_DESIGN_ID, field DESIGN_ID (RO)
 *
 * This is a 1 byte design ID code fixed by Freescale that Identifies the main revision of the HDMI
 * TX controller. For example, HDMI TX 1.30a, DESIGN_ID = 11h; REVISION_ID = 0Ah
 */

#define BP_HDMI_DESIGN_ID_DESIGN_ID      0
#define BM_HDMI_DESIGN_ID_DESIGN_ID      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_REVISION_ID - Revision Identification Register (RO)
 *
 * Name: Revision Identification Register  Address Offset: 0x0001  Size: 8 bits  Value after Reset:
 * Implementation Dependent  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char REVISION_ID : 8; //!< This is a one byte revision ID code fixed by Freescale that Identifies the main revision of the HDMI TX controller. For example, HDMI TX 1.30a, DESIGN_ID = 12h; REVISION_ID = 0Ah
    } B;
} hw_hdmi_revision_id_t;
#endif

/*
 * constants & macros for entire HDMI_REVISION_ID register
 */
#define HW_HDMI_REVISION_ID_ADDR      (REGS_HDMI_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_REVISION_ID           (*(volatile hw_hdmi_revision_id_t *) HW_HDMI_REVISION_ID_ADDR)
#define HW_HDMI_REVISION_ID_RD()      (HW_HDMI_REVISION_ID.U)
#endif

/*
 * constants & macros for individual HDMI_REVISION_ID bitfields
 */

/* --- Register HW_HDMI_REVISION_ID, field REVISION_ID (RO)
 *
 * This is a one byte revision ID code fixed by Freescale that Identifies the main revision of the
 * HDMI TX controller. For example, HDMI TX 1.30a, DESIGN_ID = 12h; REVISION_ID = 0Ah
 */

#define BP_HDMI_REVISION_ID_REVISION_ID      0
#define BM_HDMI_REVISION_ID_REVISION_ID      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PRODUCT_ID0 - Product Identification Register 0 (RO)
 *
 * Name: Product Identification Register 0  Address Offset: 0x0002  Size: 8 bits  Value after Reset:
 * Implementation Dependent  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PRODUCT_ID0 : 8; //!< This one byte fixed code Identifies Freescale's product line ("A0h" for HDMI TX products).
    } B;
} hw_hdmi_product_id0_t;
#endif

/*
 * constants & macros for entire HDMI_PRODUCT_ID0 register
 */
#define HW_HDMI_PRODUCT_ID0_ADDR      (REGS_HDMI_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PRODUCT_ID0           (*(volatile hw_hdmi_product_id0_t *) HW_HDMI_PRODUCT_ID0_ADDR)
#define HW_HDMI_PRODUCT_ID0_RD()      (HW_HDMI_PRODUCT_ID0.U)
#endif

/*
 * constants & macros for individual HDMI_PRODUCT_ID0 bitfields
 */

/* --- Register HW_HDMI_PRODUCT_ID0, field PRODUCT_ID0 (RO)
 *
 * This one byte fixed code Identifies Freescale's product line ("A0h" for HDMI TX products).
 */

#define BP_HDMI_PRODUCT_ID0_PRODUCT_ID0      0
#define BM_HDMI_PRODUCT_ID0_PRODUCT_ID0      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PRODUCT_ID1 - Product Identification Register 1 (RO)
 *
 * Name: Product Identification Register 1  Address Offset: 0x0003  Size: 8 bits  Value after Reset:
 * Implementation Dependent  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PRODUCT_ID1 : 8; //!< This one byte fixed code identifies Freescale's product line according to: 01h HDMI TX Controller 02h DWC_hdmi_rx Controller C1h HDMI TX Controller with HDCP encryption engine C2h DWC_hdmi_rx Controller with encryption engine
    } B;
} hw_hdmi_product_id1_t;
#endif

/*
 * constants & macros for entire HDMI_PRODUCT_ID1 register
 */
#define HW_HDMI_PRODUCT_ID1_ADDR      (REGS_HDMI_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PRODUCT_ID1           (*(volatile hw_hdmi_product_id1_t *) HW_HDMI_PRODUCT_ID1_ADDR)
#define HW_HDMI_PRODUCT_ID1_RD()      (HW_HDMI_PRODUCT_ID1.U)
#endif

/*
 * constants & macros for individual HDMI_PRODUCT_ID1 bitfields
 */

/* --- Register HW_HDMI_PRODUCT_ID1, field PRODUCT_ID1 (RO)
 *
 * This one byte fixed code identifies Freescale's product line according to: 01h HDMI TX Controller
 * 02h DWC_hdmi_rx Controller C1h HDMI TX Controller with HDCP encryption engine C2h DWC_hdmi_rx
 * Controller with encryption engine
 */

#define BP_HDMI_PRODUCT_ID1_PRODUCT_ID1      0
#define BM_HDMI_PRODUCT_ID1_PRODUCT_ID1      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CONFIG0_ID - Configuration Identification Register 0 (RO)
 *
 * Name: Configuration Identification Register 0  Address Offset: 0x0004  Size: 8 bits  Value after
 * Reset: Implementation Dependent  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCP : 1; //!< Indicates if HDCP is present
        unsigned char CEC : 1; //!< Indicates if CEC is present
        unsigned char CSC : 1; //!< Indicates if Color Space Conversion block is present
        unsigned char HDMI14 : 1; //!< Indicates if HDMI 1.4 features are present
        unsigned char AUDI2S : 1; //!< Indicates if I2S interface is present
        unsigned char AUDSPDIF : 1; //!< Indicates if SPDIF interface is present
        unsigned char AUDHBR : 1; //!< Indicates if HBR interface is present
        unsigned char PREPEN : 1; //!< Indicates if it is possible to use internal pixel repetition
    } B;
} hw_hdmi_config0_id_t;
#endif

/*
 * constants & macros for entire HDMI_CONFIG0_ID register
 */
#define HW_HDMI_CONFIG0_ID_ADDR      (REGS_HDMI_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CONFIG0_ID           (*(volatile hw_hdmi_config0_id_t *) HW_HDMI_CONFIG0_ID_ADDR)
#define HW_HDMI_CONFIG0_ID_RD()      (HW_HDMI_CONFIG0_ID.U)
#endif

/*
 * constants & macros for individual HDMI_CONFIG0_ID bitfields
 */

/* --- Register HW_HDMI_CONFIG0_ID, field HDCP (RO)
 *
 * Indicates if HDCP is present
 */

#define BP_HDMI_CONFIG0_ID_HDCP      0
#define BM_HDMI_CONFIG0_ID_HDCP      0x00000001

/* --- Register HW_HDMI_CONFIG0_ID, field CEC (RO)
 *
 * Indicates if CEC is present
 */

#define BP_HDMI_CONFIG0_ID_CEC      1
#define BM_HDMI_CONFIG0_ID_CEC      0x00000002

/* --- Register HW_HDMI_CONFIG0_ID, field CSC (RO)
 *
 * Indicates if Color Space Conversion block is present
 */

#define BP_HDMI_CONFIG0_ID_CSC      2
#define BM_HDMI_CONFIG0_ID_CSC      0x00000004

/* --- Register HW_HDMI_CONFIG0_ID, field HDMI14 (RO)
 *
 * Indicates if HDMI 1.4 features are present
 */

#define BP_HDMI_CONFIG0_ID_HDMI14      3
#define BM_HDMI_CONFIG0_ID_HDMI14      0x00000008

/* --- Register HW_HDMI_CONFIG0_ID, field AUDI2S (RO)
 *
 * Indicates if I2S interface is present
 */

#define BP_HDMI_CONFIG0_ID_AUDI2S      4
#define BM_HDMI_CONFIG0_ID_AUDI2S      0x00000010

/* --- Register HW_HDMI_CONFIG0_ID, field AUDSPDIF (RO)
 *
 * Indicates if SPDIF interface is present
 */

#define BP_HDMI_CONFIG0_ID_AUDSPDIF      5
#define BM_HDMI_CONFIG0_ID_AUDSPDIF      0x00000020

/* --- Register HW_HDMI_CONFIG0_ID, field AUDHBR (RO)
 *
 * Indicates if HBR interface is present
 */

#define BP_HDMI_CONFIG0_ID_AUDHBR      6
#define BM_HDMI_CONFIG0_ID_AUDHBR      0x00000040

/* --- Register HW_HDMI_CONFIG0_ID, field PREPEN (RO)
 *
 * Indicates if it is possible to use internal pixel repetition
 */

#define BP_HDMI_CONFIG0_ID_PREPEN      7
#define BM_HDMI_CONFIG0_ID_PREPEN      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CONFIG1_ID - Configuration Identification Register 1 (RO)
 *
 * Name: Configuration Identification Register 1  Address Offset: 0x0005  Size: 8 bits  Value after
 * Reset: Implementation Dependent  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CONFAHB : 1; //!< Indicates that configuration interface is AHB interface
        unsigned char CONFAPB : 1; //!< Indicates that configuration interface is APB interface
        unsigned char CONFOCP : 1; //!< Indicates that configuration interface is OCP interface
        unsigned char CONFI2C : 1; //!< Indicates that configuration interface is I2C interface
        unsigned char CONFSFRDIR : 1; //!< Indicates that configuration interface is SFR interface
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_config1_id_t;
#endif

/*
 * constants & macros for entire HDMI_CONFIG1_ID register
 */
#define HW_HDMI_CONFIG1_ID_ADDR      (REGS_HDMI_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CONFIG1_ID           (*(volatile hw_hdmi_config1_id_t *) HW_HDMI_CONFIG1_ID_ADDR)
#define HW_HDMI_CONFIG1_ID_RD()      (HW_HDMI_CONFIG1_ID.U)
#endif

/*
 * constants & macros for individual HDMI_CONFIG1_ID bitfields
 */

/* --- Register HW_HDMI_CONFIG1_ID, field CONFAHB (RO)
 *
 * Indicates that configuration interface is AHB interface
 */

#define BP_HDMI_CONFIG1_ID_CONFAHB      0
#define BM_HDMI_CONFIG1_ID_CONFAHB      0x00000001

/* --- Register HW_HDMI_CONFIG1_ID, field CONFAPB (RO)
 *
 * Indicates that configuration interface is APB interface
 */

#define BP_HDMI_CONFIG1_ID_CONFAPB      1
#define BM_HDMI_CONFIG1_ID_CONFAPB      0x00000002

/* --- Register HW_HDMI_CONFIG1_ID, field CONFOCP (RO)
 *
 * Indicates that configuration interface is OCP interface
 */

#define BP_HDMI_CONFIG1_ID_CONFOCP      2
#define BM_HDMI_CONFIG1_ID_CONFOCP      0x00000004

/* --- Register HW_HDMI_CONFIG1_ID, field CONFI2C (RO)
 *
 * Indicates that configuration interface is I2C interface
 */

#define BP_HDMI_CONFIG1_ID_CONFI2C      3
#define BM_HDMI_CONFIG1_ID_CONFI2C      0x00000008

/* --- Register HW_HDMI_CONFIG1_ID, field CONFSFRDIR (RO)
 *
 * Indicates that configuration interface is SFR interface
 */

#define BP_HDMI_CONFIG1_ID_CONFSFRDIR      4
#define BM_HDMI_CONFIG1_ID_CONFSFRDIR      0x00000010

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CONFIG2_ID - Configuration Identification Register 2 (RO)
 *
 * Name: Configuration Identification Register 2  Address Offset: 0x0006  Size: 8 bits  Value after
 * Reset: Implementation Dependent  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PHYTYPE : 8; //!< Indicates the type of PHY interface selected: 00h Legacy PHY (HDMI TX PHY) F2h PHY_Gen2 (HDMI 3D TX PHY) E2h PHY_Gen2 (HDMI 3D TX PHY) + HEAC PHY
    } B;
} hw_hdmi_config2_id_t;
#endif

/*
 * constants & macros for entire HDMI_CONFIG2_ID register
 */
#define HW_HDMI_CONFIG2_ID_ADDR      (REGS_HDMI_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CONFIG2_ID           (*(volatile hw_hdmi_config2_id_t *) HW_HDMI_CONFIG2_ID_ADDR)
#define HW_HDMI_CONFIG2_ID_RD()      (HW_HDMI_CONFIG2_ID.U)
#endif

/*
 * constants & macros for individual HDMI_CONFIG2_ID bitfields
 */

/* --- Register HW_HDMI_CONFIG2_ID, field PHYTYPE (RO)
 *
 * Indicates the type of PHY interface selected: 00h Legacy PHY (HDMI TX PHY) F2h PHY_Gen2 (HDMI 3D
 * TX PHY) E2h PHY_Gen2 (HDMI 3D TX PHY) + HEAC PHY
 */

#define BP_HDMI_CONFIG2_ID_PHYTYPE      0
#define BM_HDMI_CONFIG2_ID_PHYTYPE      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CONFIG3_ID - Configuration Identification Register 3 (RO)
 *
 * Name: Configuration Identification Register 3  Address Offset: 0x0007  Size: 8 bits  Value after
 * Reset: Implementation Dependent  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CONFGPAUD : 1; //!< Indicates that configuration interface is Generic Parallel Audio (GPAUD) interface
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_config3_id_t;
#endif

/*
 * constants & macros for entire HDMI_CONFIG3_ID register
 */
#define HW_HDMI_CONFIG3_ID_ADDR      (REGS_HDMI_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CONFIG3_ID           (*(volatile hw_hdmi_config3_id_t *) HW_HDMI_CONFIG3_ID_ADDR)
#define HW_HDMI_CONFIG3_ID_RD()      (HW_HDMI_CONFIG3_ID.U)
#endif

/*
 * constants & macros for individual HDMI_CONFIG3_ID bitfields
 */

/* --- Register HW_HDMI_CONFIG3_ID, field CONFGPAUD (RO)
 *
 * Indicates that configuration interface is Generic Parallel Audio (GPAUD) interface
 */

#define BP_HDMI_CONFIG3_ID_CONFGPAUD      0
#define BM_HDMI_CONFIG3_ID_CONFGPAUD      0x00000001

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_FC_STAT0 - Frame Composer Interrupt Status Register 0 (W1C)
 *
 * This section describes clear on write (1 to corresponding bit) status registers, which contain
 * the following active-high, sticky bit interrupts.  HDMI TX introduces a new set of sticky bit
 * mute control registers (IH_MUTE_FC_STAT0 to IH_MUTE_AHBDMAAUD_STAT0) that correspond to the
 * interrupt registers. You can ignore a sticky bit interrupt by setting the corresponding mute
 * control register bit to 1. This puts the global interrupt line on a higher priority than the
 * sticky bit interrupt.   Address Offset: 0x0100  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char NULL : 1; //!< Active after successful transmission of an Null packet. Due to high number of audio sample packets transmitted, this interrupt is by default masked at frame composer.
        unsigned char ACR : 1; //!< Active after successful transmission of an Audio Clock Regeneration (N/CTS transmission) packet.
        unsigned char AUDS : 1; //!< Active after successful transmission of an Audio Sample packet. Due to high number of audio sample packets transmitted, this interrupt is by default masked at frame composer.
        unsigned char OBA : 1; //!< Reserved
        unsigned char DST : 1; //!< Reserved
        unsigned char HBR : 1; //!< Active after successful transmission of an Audio HBR packet.
        unsigned char ACP : 1; //!< Active after successful transmission of an Audio Content Protection packet.
        unsigned char AUDI : 1; //!< Active after successful transmission of an Audio InfoFrame packet.
    } B;
} hw_hdmi_ih_fc_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_FC_STAT0 register
 */
#define HW_HDMI_IH_FC_STAT0_ADDR      (REGS_HDMI_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_FC_STAT0           (*(volatile hw_hdmi_ih_fc_stat0_t *) HW_HDMI_IH_FC_STAT0_ADDR)
#define HW_HDMI_IH_FC_STAT0_RD()      (HW_HDMI_IH_FC_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_IH_FC_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_FC_STAT0, field NULL (W1C)
 *
 * Active after successful transmission of an Null packet. Due to high number of audio sample
 * packets transmitted, this interrupt is by default masked at frame composer.
 */

#define BP_HDMI_IH_FC_STAT0_NULL      0
#define BM_HDMI_IH_FC_STAT0_NULL      0x00000001

/* --- Register HW_HDMI_IH_FC_STAT0, field ACR (W1C)
 *
 * Active after successful transmission of an Audio Clock Regeneration (N/CTS transmission) packet.
 */

#define BP_HDMI_IH_FC_STAT0_ACR      1
#define BM_HDMI_IH_FC_STAT0_ACR      0x00000002

/* --- Register HW_HDMI_IH_FC_STAT0, field AUDS (W1C)
 *
 * Active after successful transmission of an Audio Sample packet. Due to high number of audio
 * sample packets transmitted, this interrupt is by default masked at frame composer.
 */

#define BP_HDMI_IH_FC_STAT0_AUDS      2
#define BM_HDMI_IH_FC_STAT0_AUDS      0x00000004

/* --- Register HW_HDMI_IH_FC_STAT0, field OBA (W1C)
 *
 * Reserved
 */

#define BP_HDMI_IH_FC_STAT0_OBA      3
#define BM_HDMI_IH_FC_STAT0_OBA      0x00000008

/* --- Register HW_HDMI_IH_FC_STAT0, field DST (W1C)
 *
 * Reserved
 */

#define BP_HDMI_IH_FC_STAT0_DST      4
#define BM_HDMI_IH_FC_STAT0_DST      0x00000010

/* --- Register HW_HDMI_IH_FC_STAT0, field HBR (W1C)
 *
 * Active after successful transmission of an Audio HBR packet.
 */

#define BP_HDMI_IH_FC_STAT0_HBR      5
#define BM_HDMI_IH_FC_STAT0_HBR      0x00000020

/* --- Register HW_HDMI_IH_FC_STAT0, field ACP (W1C)
 *
 * Active after successful transmission of an Audio Content Protection packet.
 */

#define BP_HDMI_IH_FC_STAT0_ACP      6
#define BM_HDMI_IH_FC_STAT0_ACP      0x00000040

/* --- Register HW_HDMI_IH_FC_STAT0, field AUDI (W1C)
 *
 * Active after successful transmission of an Audio InfoFrame packet.
 */

#define BP_HDMI_IH_FC_STAT0_AUDI      7
#define BM_HDMI_IH_FC_STAT0_AUDI      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_FC_STAT1 - Frame Composer Interrupt Status Register 1 (W1C)
 *
 * Address Offset: 0x0101  Size: 8 bits  Value after Reset: 0x00  Access: Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GCP : 1; //!< Active after successful transmission of an General Control Packet.
        unsigned char AVI : 1; //!< Active after successful transmission of an AVI infoFrame packet.
        unsigned char MPEG : 1; //!< Reserved
        unsigned char SPD : 1; //!< Active after successful transmission of an Source Product Descriptor infoFrame packet.
        unsigned char VSD : 1; //!< Active after successful transmission of an Vendor Specific Data infoFrame packet.
        unsigned char ISCR2 : 1; //!< Active after successful transmission of an International Standard Recording Code 2 packet.
        unsigned char ISCR1 : 1; //!< Active after successful transmission of an International Standard Recording Code 1 packet.
        unsigned char GMD : 1; //!< Active after successful transmission of an Gamut metadata packet.
    } B;
} hw_hdmi_ih_fc_stat1_t;
#endif

/*
 * constants & macros for entire HDMI_IH_FC_STAT1 register
 */
#define HW_HDMI_IH_FC_STAT1_ADDR      (REGS_HDMI_BASE + 0x101)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_FC_STAT1           (*(volatile hw_hdmi_ih_fc_stat1_t *) HW_HDMI_IH_FC_STAT1_ADDR)
#define HW_HDMI_IH_FC_STAT1_RD()      (HW_HDMI_IH_FC_STAT1.U)
#endif

/*
 * constants & macros for individual HDMI_IH_FC_STAT1 bitfields
 */

/* --- Register HW_HDMI_IH_FC_STAT1, field GCP (W1C)
 *
 * Active after successful transmission of an General Control Packet.
 */

#define BP_HDMI_IH_FC_STAT1_GCP      0
#define BM_HDMI_IH_FC_STAT1_GCP      0x00000001

/* --- Register HW_HDMI_IH_FC_STAT1, field AVI (W1C)
 *
 * Active after successful transmission of an AVI infoFrame packet.
 */

#define BP_HDMI_IH_FC_STAT1_AVI      1
#define BM_HDMI_IH_FC_STAT1_AVI      0x00000002

/* --- Register HW_HDMI_IH_FC_STAT1, field MPEG (W1C)
 *
 * Reserved
 */

#define BP_HDMI_IH_FC_STAT1_MPEG      2
#define BM_HDMI_IH_FC_STAT1_MPEG      0x00000004

/* --- Register HW_HDMI_IH_FC_STAT1, field SPD (W1C)
 *
 * Active after successful transmission of an Source Product Descriptor infoFrame packet.
 */

#define BP_HDMI_IH_FC_STAT1_SPD      3
#define BM_HDMI_IH_FC_STAT1_SPD      0x00000008

/* --- Register HW_HDMI_IH_FC_STAT1, field VSD (W1C)
 *
 * Active after successful transmission of an Vendor Specific Data infoFrame packet.
 */

#define BP_HDMI_IH_FC_STAT1_VSD      4
#define BM_HDMI_IH_FC_STAT1_VSD      0x00000010

/* --- Register HW_HDMI_IH_FC_STAT1, field ISCR2 (W1C)
 *
 * Active after successful transmission of an International Standard Recording Code 2 packet.
 */

#define BP_HDMI_IH_FC_STAT1_ISCR2      5
#define BM_HDMI_IH_FC_STAT1_ISCR2      0x00000020

/* --- Register HW_HDMI_IH_FC_STAT1, field ISCR1 (W1C)
 *
 * Active after successful transmission of an International Standard Recording Code 1 packet.
 */

#define BP_HDMI_IH_FC_STAT1_ISCR1      6
#define BM_HDMI_IH_FC_STAT1_ISCR1      0x00000040

/* --- Register HW_HDMI_IH_FC_STAT1, field GMD (W1C)
 *
 * Active after successful transmission of an Gamut metadata packet.
 */

#define BP_HDMI_IH_FC_STAT1_GMD      7
#define BM_HDMI_IH_FC_STAT1_GMD      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_FC_STAT2 - Frame Composer Interrupt Status Register 2 (W1C)
 *
 * Address Offset: 0x0102  Size: 8 bits  Value after Reset: 0x00  Access: Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HIGHPRIORITY_OVERFLOW : 1; //!< Frame Composer high priority packet queue descriptor overflow indication.
        unsigned char LOWPRIORITY_OVERFLOW : 1; //!< Frame Composer low priority packet queue descriptor overflow indication.
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ih_fc_stat2_t;
#endif

/*
 * constants & macros for entire HDMI_IH_FC_STAT2 register
 */
#define HW_HDMI_IH_FC_STAT2_ADDR      (REGS_HDMI_BASE + 0x102)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_FC_STAT2           (*(volatile hw_hdmi_ih_fc_stat2_t *) HW_HDMI_IH_FC_STAT2_ADDR)
#define HW_HDMI_IH_FC_STAT2_RD()      (HW_HDMI_IH_FC_STAT2.U)
#endif

/*
 * constants & macros for individual HDMI_IH_FC_STAT2 bitfields
 */

/* --- Register HW_HDMI_IH_FC_STAT2, field HIGHPRIORITY_OVERFLOW (W1C)
 *
 * Frame Composer high priority packet queue descriptor overflow indication.
 */

#define BP_HDMI_IH_FC_STAT2_HIGHPRIORITY_OVERFLOW      0
#define BM_HDMI_IH_FC_STAT2_HIGHPRIORITY_OVERFLOW      0x00000001

/* --- Register HW_HDMI_IH_FC_STAT2, field LOWPRIORITY_OVERFLOW (W1C)
 *
 * Frame Composer low priority packet queue descriptor overflow indication.
 */

#define BP_HDMI_IH_FC_STAT2_LOWPRIORITY_OVERFLOW      1
#define BM_HDMI_IH_FC_STAT2_LOWPRIORITY_OVERFLOW      0x00000002

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_AS_STAT0 - Audio Sampler Interrupt Status Register (W1C)
 *
 * Address Offset: 0x0103  Size: 8 bits  Value after Reset: 0x00  Access: Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUD_FIFO_OVERFLOW : 1; //!< Audio Sampler audio FIFO full indication.
        unsigned char AUD_FIFO_UNDERFLOW : 1; //!< Audio Sampler audio FIFO empty indication.
        unsigned char AUD_FIFO_UNDERFLOW_THR : 1; //!< Audio Sampler audio FIFO empty threshold (four samples) indication. Only valid in HBR audio.
        unsigned char RESERVED0 : 5; //!< Reserved
    } B;
} hw_hdmi_ih_as_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_AS_STAT0 register
 */
#define HW_HDMI_IH_AS_STAT0_ADDR      (REGS_HDMI_BASE + 0x103)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_AS_STAT0           (*(volatile hw_hdmi_ih_as_stat0_t *) HW_HDMI_IH_AS_STAT0_ADDR)
#define HW_HDMI_IH_AS_STAT0_RD()      (HW_HDMI_IH_AS_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_IH_AS_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_AS_STAT0, field AUD_FIFO_OVERFLOW (W1C)
 *
 * Audio Sampler audio FIFO full indication.
 */

#define BP_HDMI_IH_AS_STAT0_AUD_FIFO_OVERFLOW      0
#define BM_HDMI_IH_AS_STAT0_AUD_FIFO_OVERFLOW      0x00000001

/* --- Register HW_HDMI_IH_AS_STAT0, field AUD_FIFO_UNDERFLOW (W1C)
 *
 * Audio Sampler audio FIFO empty indication.
 */

#define BP_HDMI_IH_AS_STAT0_AUD_FIFO_UNDERFLOW      1
#define BM_HDMI_IH_AS_STAT0_AUD_FIFO_UNDERFLOW      0x00000002

/* --- Register HW_HDMI_IH_AS_STAT0, field AUD_FIFO_UNDERFLOW_THR (W1C)
 *
 * Audio Sampler audio FIFO empty threshold (four samples) indication. Only valid in HBR audio.
 */

#define BP_HDMI_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_THR      2
#define BM_HDMI_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_THR      0x00000004

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_PHY_STAT0 - PHY Interface Interrupt Status Register (W1C)
 *
 * Address Offset: 0x0104  Size: 8 bits  Value after Reset: 0x00  Access: Clear on Write/Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDP : 1; //!< HDMI Hot Plug Detect indication. You may need to mask or change polarity of this interrupt after it has become active.
        unsigned char TX_PHY_LOCK : 1; //!< TX PHY PLL lock indication. Please refer to PHY datasheet for more information. You may need to mask or change polarity of this interrupt after it has become active.
        unsigned char RX_SENSE : 1; //!< TX PHY RX_SENSE indication for driver 0. You may need to mask or change polarity of this interrupt after it has become active.
        unsigned char RX_SENSE1 : 1; //!< TX PHY RX_SENSE indication for driver 1. You may need to mask or change polarity of this interrupt after it has become active.
        unsigned char RX_SENSE2 : 1; //!< TX PHY RX_SENSE indication for driver 2. You may need to mask or change polarity of this interrupt after it has become active.
        unsigned char RX_SENSE3 : 1; //!< TX PHY RX_SENSE indication for driver 3. You may need to mask or change polarity of this interrupt after it has become active.
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_ih_phy_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_PHY_STAT0 register
 */
#define HW_HDMI_IH_PHY_STAT0_ADDR      (REGS_HDMI_BASE + 0x104)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_PHY_STAT0           (*(volatile hw_hdmi_ih_phy_stat0_t *) HW_HDMI_IH_PHY_STAT0_ADDR)
#define HW_HDMI_IH_PHY_STAT0_RD()      (HW_HDMI_IH_PHY_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_IH_PHY_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_PHY_STAT0, field HDP (W1C)
 *
 * HDMI Hot Plug Detect indication. You may need to mask or change polarity of this interrupt after
 * it has become active.
 */

#define BP_HDMI_IH_PHY_STAT0_HDP      0
#define BM_HDMI_IH_PHY_STAT0_HDP      0x00000001

/* --- Register HW_HDMI_IH_PHY_STAT0, field TX_PHY_LOCK (W1C)
 *
 * TX PHY PLL lock indication. Please refer to PHY datasheet for more information. You may need to
 * mask or change polarity of this interrupt after it has become active.
 */

#define BP_HDMI_IH_PHY_STAT0_TX_PHY_LOCK      1
#define BM_HDMI_IH_PHY_STAT0_TX_PHY_LOCK      0x00000002

/* --- Register HW_HDMI_IH_PHY_STAT0, field RX_SENSE (W1C)
 *
 * TX PHY RX_SENSE indication for driver 0. You may need to mask or change polarity of this
 * interrupt after it has become active.
 */

#define BP_HDMI_IH_PHY_STAT0_RX_SENSE      2
#define BM_HDMI_IH_PHY_STAT0_RX_SENSE      0x00000004

/* --- Register HW_HDMI_IH_PHY_STAT0, field RX_SENSE (W1C)
 *
 * TX PHY RX_SENSE indication for driver 1. You may need to mask or change polarity of this
 * interrupt after it has become active.
 */

#define BP_HDMI_IH_PHY_STAT0_RX_SENSE      3
#define BM_HDMI_IH_PHY_STAT0_RX_SENSE      0x00000008

/* --- Register HW_HDMI_IH_PHY_STAT0, field RX_SENSE (W1C)
 *
 * TX PHY RX_SENSE indication for driver 2. You may need to mask or change polarity of this
 * interrupt after it has become active.
 */

#define BP_HDMI_IH_PHY_STAT0_RX_SENSE      4
#define BM_HDMI_IH_PHY_STAT0_RX_SENSE      0x00000010

/* --- Register HW_HDMI_IH_PHY_STAT0, field RX_SENSE (W1C)
 *
 * TX PHY RX_SENSE indication for driver 3. You may need to mask or change polarity of this
 * interrupt after it has become active.
 */

#define BP_HDMI_IH_PHY_STAT0_RX_SENSE      5
#define BM_HDMI_IH_PHY_STAT0_RX_SENSE      0x00000020

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_I2CM_STAT0 - E-DDC I2C Master Interrupt Status Register (W1C)
 *
 * Address Offset: 0x0105  Size: 8 bits  Value after Reset: 0x00  Access: Clear on Write/Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMASTER_ERROR : 1; //!< I2C Master error indication
        unsigned char I2CMASTERDONE : 1; //!< I2C Master done indication
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ih_i2cm_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_I2CM_STAT0 register
 */
#define HW_HDMI_IH_I2CM_STAT0_ADDR      (REGS_HDMI_BASE + 0x105)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_I2CM_STAT0           (*(volatile hw_hdmi_ih_i2cm_stat0_t *) HW_HDMI_IH_I2CM_STAT0_ADDR)
#define HW_HDMI_IH_I2CM_STAT0_RD()      (HW_HDMI_IH_I2CM_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_IH_I2CM_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_I2CM_STAT0, field I2CMASTER_ERROR (W1C)
 *
 * I2C Master error indication
 */

#define BP_HDMI_IH_I2CM_STAT0_I2CMASTER_ERROR      0
#define BM_HDMI_IH_I2CM_STAT0_I2CMASTER_ERROR      0x00000001

/* --- Register HW_HDMI_IH_I2CM_STAT0, field I2CMASTERDONE (W1C)
 *
 * I2C Master done indication
 */

#define BP_HDMI_IH_I2CM_STAT0_I2CMASTERDONE      1
#define BM_HDMI_IH_I2CM_STAT0_I2CMASTERDONE      0x00000002

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_CEC_STAT0 - CEC Interrupt Status Register (W1C)
 *
 * Address Offset: 0x0106  Size: 8 bits  Value after Reset: 0x00  Access: Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DONE : 1; //!< CEC Done Indication
        unsigned char EOM : 1; //!< CEC End of Message Indication
        unsigned char NACK : 1; //!< CEC Nack indication
        unsigned char ARB_LOST : 1; //!< CEC Arb_Lost indication
        unsigned char ERROR_INITIATOR : 1; //!< CEC Error_follow indication
        unsigned char ERROR_FOLLOW : 1; //!< CEC Error_follow indication
        unsigned char WAKEUP : 1; //!< CEC Wake-up indication
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_ih_cec_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_CEC_STAT0 register
 */
#define HW_HDMI_IH_CEC_STAT0_ADDR      (REGS_HDMI_BASE + 0x106)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_CEC_STAT0           (*(volatile hw_hdmi_ih_cec_stat0_t *) HW_HDMI_IH_CEC_STAT0_ADDR)
#define HW_HDMI_IH_CEC_STAT0_RD()      (HW_HDMI_IH_CEC_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_IH_CEC_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_CEC_STAT0, field DONE (W1C)
 *
 * CEC Done Indication
 */

#define BP_HDMI_IH_CEC_STAT0_DONE      0
#define BM_HDMI_IH_CEC_STAT0_DONE      0x00000001

/* --- Register HW_HDMI_IH_CEC_STAT0, field EOM (W1C)
 *
 * CEC End of Message Indication
 */

#define BP_HDMI_IH_CEC_STAT0_EOM      1
#define BM_HDMI_IH_CEC_STAT0_EOM      0x00000002

/* --- Register HW_HDMI_IH_CEC_STAT0, field NACK (W1C)
 *
 * CEC Nack indication
 */

#define BP_HDMI_IH_CEC_STAT0_NACK      2
#define BM_HDMI_IH_CEC_STAT0_NACK      0x00000004

/* --- Register HW_HDMI_IH_CEC_STAT0, field ARB_LOST (W1C)
 *
 * CEC Arb_Lost indication
 */

#define BP_HDMI_IH_CEC_STAT0_ARB_LOST      3
#define BM_HDMI_IH_CEC_STAT0_ARB_LOST      0x00000008

/* --- Register HW_HDMI_IH_CEC_STAT0, field ERROR_INITIATOR (W1C)
 *
 * CEC Error_follow indication
 */

#define BP_HDMI_IH_CEC_STAT0_ERROR_INITIATOR      4
#define BM_HDMI_IH_CEC_STAT0_ERROR_INITIATOR      0x00000010

/* --- Register HW_HDMI_IH_CEC_STAT0, field ERROR_FOLLOW (W1C)
 *
 * CEC Error_follow indication
 */

#define BP_HDMI_IH_CEC_STAT0_ERROR_FOLLOW      5
#define BM_HDMI_IH_CEC_STAT0_ERROR_FOLLOW      0x00000020

/* --- Register HW_HDMI_IH_CEC_STAT0, field WAKEUP (W1C)
 *
 * CEC Wake-up indication
 */

#define BP_HDMI_IH_CEC_STAT0_WAKEUP      6
#define BM_HDMI_IH_CEC_STAT0_WAKEUP      0x00000040

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_VP_STAT0 - Video Packetizer Interrupt Status Register (W1C)
 *
 * Address Offset: 0x0107  Size: 8 bits  Value after Reset: 0x00  Access: Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FIFOEMPTYBYP : 1; //!< Video packetizer 8-bit bypass fifo empty interrupt
        unsigned char FIFOFULLBYP : 1; //!< Video packetizer 8-bit bypass fifo full interrupt
        unsigned char FIFOEMPTYREMAP : 1; //!< Video packetizer pixel YCC 422 re-mapper FIFO empty interrupt
        unsigned char FIFOFULLREMAP : 1; //!< Video packetizer pixel YCC 422 re-mapper FIFO full interrupt
        unsigned char FIFOEMPTYPP : 1; //!< Video packetizer pixel packing FIFO empty interrupt
        unsigned char FIFOFULLPP : 1; //!< Video packetizer pixel packing FIFO full interrupt
        unsigned char FIFOEMPTYREPET : 1; //!< Video packetizer pixel repeater FIFO empty interrupt
        unsigned char FIFOFULLREPET : 1; //!< Video packetizer pixel repeater FIFO full interrupt
    } B;
} hw_hdmi_ih_vp_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_VP_STAT0 register
 */
#define HW_HDMI_IH_VP_STAT0_ADDR      (REGS_HDMI_BASE + 0x107)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_VP_STAT0           (*(volatile hw_hdmi_ih_vp_stat0_t *) HW_HDMI_IH_VP_STAT0_ADDR)
#define HW_HDMI_IH_VP_STAT0_RD()      (HW_HDMI_IH_VP_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_IH_VP_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_VP_STAT0, field FIFOEMPTYBYP (W1C)
 *
 * Video packetizer 8-bit bypass fifo empty interrupt
 */

#define BP_HDMI_IH_VP_STAT0_FIFOEMPTYBYP      0
#define BM_HDMI_IH_VP_STAT0_FIFOEMPTYBYP      0x00000001

/* --- Register HW_HDMI_IH_VP_STAT0, field FIFOFULLBYP (W1C)
 *
 * Video packetizer 8-bit bypass fifo full interrupt
 */

#define BP_HDMI_IH_VP_STAT0_FIFOFULLBYP      1
#define BM_HDMI_IH_VP_STAT0_FIFOFULLBYP      0x00000002

/* --- Register HW_HDMI_IH_VP_STAT0, field FIFOEMPTYREMAP (W1C)
 *
 * Video packetizer pixel YCC 422 re-mapper FIFO empty interrupt
 */

#define BP_HDMI_IH_VP_STAT0_FIFOEMPTYREMAP      2
#define BM_HDMI_IH_VP_STAT0_FIFOEMPTYREMAP      0x00000004

/* --- Register HW_HDMI_IH_VP_STAT0, field FIFOFULLREMAP (W1C)
 *
 * Video packetizer pixel YCC 422 re-mapper FIFO full interrupt
 */

#define BP_HDMI_IH_VP_STAT0_FIFOFULLREMAP      3
#define BM_HDMI_IH_VP_STAT0_FIFOFULLREMAP      0x00000008

/* --- Register HW_HDMI_IH_VP_STAT0, field FIFOEMPTYPP (W1C)
 *
 * Video packetizer pixel packing FIFO empty interrupt
 */

#define BP_HDMI_IH_VP_STAT0_FIFOEMPTYPP      4
#define BM_HDMI_IH_VP_STAT0_FIFOEMPTYPP      0x00000010

/* --- Register HW_HDMI_IH_VP_STAT0, field FIFOFULLPP (W1C)
 *
 * Video packetizer pixel packing FIFO full interrupt
 */

#define BP_HDMI_IH_VP_STAT0_FIFOFULLPP      5
#define BM_HDMI_IH_VP_STAT0_FIFOFULLPP      0x00000020

/* --- Register HW_HDMI_IH_VP_STAT0, field FIFOEMPTYREPET (W1C)
 *
 * Video packetizer pixel repeater FIFO empty interrupt
 */

#define BP_HDMI_IH_VP_STAT0_FIFOEMPTYREPET      6
#define BM_HDMI_IH_VP_STAT0_FIFOEMPTYREPET      0x00000040

/* --- Register HW_HDMI_IH_VP_STAT0, field FIFOFULLREPET (W1C)
 *
 * Video packetizer pixel repeater FIFO full interrupt
 */

#define BP_HDMI_IH_VP_STAT0_FIFOFULLREPET      7
#define BM_HDMI_IH_VP_STAT0_FIFOFULLREPET      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_I2CMPHY_STAT0 - PHY GEN2 I2C Master Interrupt Status Register (W1C)
 *
 * This clear on write (1 to corresponding bit) register contains the following active high sticky
 * bit interrupts. That I2C Master PHY is the I2C Master block used to access the PHY I2C Slave.
 * Address Offset: 0x0108  Size: 8 bits  Value after Reset: 0x00  Access: Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMPHYERROR : 1; //!< I2C Master PHY error indication
        unsigned char I2CMPHYDONE : 1; //!< I2C Master PHY done indication
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ih_i2cmphy_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_I2CMPHY_STAT0 register
 */
#define HW_HDMI_IH_I2CMPHY_STAT0_ADDR      (REGS_HDMI_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_I2CMPHY_STAT0           (*(volatile hw_hdmi_ih_i2cmphy_stat0_t *) HW_HDMI_IH_I2CMPHY_STAT0_ADDR)
#define HW_HDMI_IH_I2CMPHY_STAT0_RD()      (HW_HDMI_IH_I2CMPHY_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_IH_I2CMPHY_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_I2CMPHY_STAT0, field I2CMPHYERROR (W1C)
 *
 * I2C Master PHY error indication
 */

#define BP_HDMI_IH_I2CMPHY_STAT0_I2CMPHYERROR      0
#define BM_HDMI_IH_I2CMPHY_STAT0_I2CMPHYERROR      0x00000001

/* --- Register HW_HDMI_IH_I2CMPHY_STAT0, field I2CMPHYDONE (W1C)
 *
 * I2C Master PHY done indication
 */

#define BP_HDMI_IH_I2CMPHY_STAT0_I2CMPHYDONE      1
#define BM_HDMI_IH_I2CMPHY_STAT0_I2CMPHYDONE      0x00000002

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_AHBDMAAUD_STAT0 - AHB Audio DMA Interrupt Status Register (W1C)
 *
 * Address Offset: 0x0109  Size: 8 bits  Value after Reset: 0x00  Access: Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AHBDMAAUD_INTBUFFEMPTY : 1; //!< AHB audio DMA Buffer empty interrupt
        unsigned char AHBDMAAUD_INTBUFFFULL : 1; //!< AHB audio DMA Buffer full interrupt
        unsigned char AHBDMAAUD_INTDONE : 1; //!< AHB audio DMA done interrupt
        unsigned char AHBDMAAUD_INTRETRYSPLIT : 1; //!< AHB audio DMA RETRY/SPLIT interrupt
        unsigned char AHBDMAAUD_INTLOSTOWNERSHIP : 1; //!< AHB audio DMA lost ownership interrupt
        unsigned char AHBDMAAUD_INTERROR : 1; //!< AHB audio DMA error interrupt
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_ih_ahbdmaaud_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_AHBDMAAUD_STAT0 register
 */
#define HW_HDMI_IH_AHBDMAAUD_STAT0_ADDR      (REGS_HDMI_BASE + 0x109)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_AHBDMAAUD_STAT0           (*(volatile hw_hdmi_ih_ahbdmaaud_stat0_t *) HW_HDMI_IH_AHBDMAAUD_STAT0_ADDR)
#define HW_HDMI_IH_AHBDMAAUD_STAT0_RD()      (HW_HDMI_IH_AHBDMAAUD_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_IH_AHBDMAAUD_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_AHBDMAAUD_STAT0, field AHBDMAAUD_INTBUFFEMPTY (W1C)
 *
 * AHB audio DMA Buffer empty interrupt
 */

#define BP_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY      0
#define BM_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY      0x00000001

/* --- Register HW_HDMI_IH_AHBDMAAUD_STAT0, field AHBDMAAUD_INTBUFFFULL (W1C)
 *
 * AHB audio DMA Buffer full interrupt
 */

#define BP_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL      1
#define BM_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL      0x00000002

/* --- Register HW_HDMI_IH_AHBDMAAUD_STAT0, field AHBDMAAUD_INTDONE (W1C)
 *
 * AHB audio DMA done interrupt
 */

#define BP_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE      2
#define BM_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE      0x00000004

/* --- Register HW_HDMI_IH_AHBDMAAUD_STAT0, field AHBDMAAUD_INTRETRYSPLIT (W1C)
 *
 * AHB audio DMA RETRY/SPLIT interrupt
 */

#define BP_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT      3
#define BM_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT      0x00000008

/* --- Register HW_HDMI_IH_AHBDMAAUD_STAT0, field AHBDMAAUD_INTLOSTOWNERSHIP (W1C)
 *
 * AHB audio DMA lost ownership interrupt
 */

#define BP_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP      4
#define BM_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP      0x00000010

/* --- Register HW_HDMI_IH_AHBDMAAUD_STAT0, field AHBDMAAUD_INTERROR (W1C)
 *
 * AHB audio DMA error interrupt
 */

#define BP_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR      5
#define BM_HDMI_IH_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR      0x00000020

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_FC_STAT0 - Frame Composer Interrupt Mute Control Register 0 (RW)
 *
 * Address Offset: 0x0180  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char NULL : 1; //!< When set to 1, mutes IH_ FC_STAT0[0]
        unsigned char ACR : 1; //!< When set to 1, mutes IH_ FC_STAT0[1]
        unsigned char AUDS : 1; //!< When set to 1, mutes IH_ FC_STAT0[2]
        unsigned char OBA : 1; //!< When set to 1, mutes IH_ FC_STAT0[3]
        unsigned char DST : 1; //!< When set to 1, mutes IH_ FC_STAT0[4]
        unsigned char HBR : 1; //!< When set to 1, mutes IH_ FC_STAT0[5]
        unsigned char ACP : 1; //!< When set to 1, mutes IH_ FC_STAT0[6]
        unsigned char AUDI : 1; //!< When set to 1, mutes IH_ FC_STAT0[7]
    } B;
} hw_hdmi_ih_mute_fc_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_FC_STAT0 register
 */
#define HW_HDMI_IH_MUTE_FC_STAT0_ADDR      (REGS_HDMI_BASE + 0x180)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_FC_STAT0           (*(volatile hw_hdmi_ih_mute_fc_stat0_t *) HW_HDMI_IH_MUTE_FC_STAT0_ADDR)
#define HW_HDMI_IH_MUTE_FC_STAT0_RD()      (HW_HDMI_IH_MUTE_FC_STAT0.U)
#define HW_HDMI_IH_MUTE_FC_STAT0_WR(v)     (HW_HDMI_IH_MUTE_FC_STAT0.U = (v))
#define HW_HDMI_IH_MUTE_FC_STAT0_SET(v)    (HW_HDMI_IH_MUTE_FC_STAT0_WR(HW_HDMI_IH_MUTE_FC_STAT0_RD() |  (v)))
#define HW_HDMI_IH_MUTE_FC_STAT0_CLR(v)    (HW_HDMI_IH_MUTE_FC_STAT0_WR(HW_HDMI_IH_MUTE_FC_STAT0_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_FC_STAT0_TOG(v)    (HW_HDMI_IH_MUTE_FC_STAT0_WR(HW_HDMI_IH_MUTE_FC_STAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_FC_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_FC_STAT0, field NULL (RW)
 *
 * When set to 1, mutes IH_ FC_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_FC_STAT0_NULL      0
#define BM_HDMI_IH_MUTE_FC_STAT0_NULL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT0_NULL(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_FC_STAT0_NULL)
#else
#define BF_HDMI_IH_MUTE_FC_STAT0_NULL(v)   (((v) << 0) & BM_HDMI_IH_MUTE_FC_STAT0_NULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NULL field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT0_NULL(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT0, NULL, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT0, field ACR (RW)
 *
 * When set to 1, mutes IH_ FC_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_FC_STAT0_ACR      1
#define BM_HDMI_IH_MUTE_FC_STAT0_ACR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT0_ACR(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_FC_STAT0_ACR)
#else
#define BF_HDMI_IH_MUTE_FC_STAT0_ACR(v)   (((v) << 1) & BM_HDMI_IH_MUTE_FC_STAT0_ACR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACR field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT0_ACR(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT0, ACR, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT0, field AUDS (RW)
 *
 * When set to 1, mutes IH_ FC_STAT0[2]
 */

#define BP_HDMI_IH_MUTE_FC_STAT0_AUDS      2
#define BM_HDMI_IH_MUTE_FC_STAT0_AUDS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT0_AUDS(v)   ((((reg32_t) v) << 2) & BM_HDMI_IH_MUTE_FC_STAT0_AUDS)
#else
#define BF_HDMI_IH_MUTE_FC_STAT0_AUDS(v)   (((v) << 2) & BM_HDMI_IH_MUTE_FC_STAT0_AUDS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDS field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT0_AUDS(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT0, AUDS, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT0, field OBA (RW)
 *
 * When set to 1, mutes IH_ FC_STAT0[3]
 */

#define BP_HDMI_IH_MUTE_FC_STAT0_OBA      3
#define BM_HDMI_IH_MUTE_FC_STAT0_OBA      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT0_OBA(v)   ((((reg32_t) v) << 3) & BM_HDMI_IH_MUTE_FC_STAT0_OBA)
#else
#define BF_HDMI_IH_MUTE_FC_STAT0_OBA(v)   (((v) << 3) & BM_HDMI_IH_MUTE_FC_STAT0_OBA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OBA field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT0_OBA(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT0, OBA, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT0, field DST (RW)
 *
 * When set to 1, mutes IH_ FC_STAT0[4]
 */

#define BP_HDMI_IH_MUTE_FC_STAT0_DST      4
#define BM_HDMI_IH_MUTE_FC_STAT0_DST      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT0_DST(v)   ((((reg32_t) v) << 4) & BM_HDMI_IH_MUTE_FC_STAT0_DST)
#else
#define BF_HDMI_IH_MUTE_FC_STAT0_DST(v)   (((v) << 4) & BM_HDMI_IH_MUTE_FC_STAT0_DST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DST field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT0_DST(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT0, DST, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT0, field HBR (RW)
 *
 * When set to 1, mutes IH_ FC_STAT0[5]
 */

#define BP_HDMI_IH_MUTE_FC_STAT0_HBR      5
#define BM_HDMI_IH_MUTE_FC_STAT0_HBR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT0_HBR(v)   ((((reg32_t) v) << 5) & BM_HDMI_IH_MUTE_FC_STAT0_HBR)
#else
#define BF_HDMI_IH_MUTE_FC_STAT0_HBR(v)   (((v) << 5) & BM_HDMI_IH_MUTE_FC_STAT0_HBR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBR field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT0_HBR(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT0, HBR, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT0, field ACP (RW)
 *
 * When set to 1, mutes IH_ FC_STAT0[6]
 */

#define BP_HDMI_IH_MUTE_FC_STAT0_ACP      6
#define BM_HDMI_IH_MUTE_FC_STAT0_ACP      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT0_ACP(v)   ((((reg32_t) v) << 6) & BM_HDMI_IH_MUTE_FC_STAT0_ACP)
#else
#define BF_HDMI_IH_MUTE_FC_STAT0_ACP(v)   (((v) << 6) & BM_HDMI_IH_MUTE_FC_STAT0_ACP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACP field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT0_ACP(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT0, ACP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT0, field AUDI (RW)
 *
 * When set to 1, mutes IH_ FC_STAT0[7]
 */

#define BP_HDMI_IH_MUTE_FC_STAT0_AUDI      7
#define BM_HDMI_IH_MUTE_FC_STAT0_AUDI      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT0_AUDI(v)   ((((reg32_t) v) << 7) & BM_HDMI_IH_MUTE_FC_STAT0_AUDI)
#else
#define BF_HDMI_IH_MUTE_FC_STAT0_AUDI(v)   (((v) << 7) & BM_HDMI_IH_MUTE_FC_STAT0_AUDI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDI field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT0_AUDI(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT0, AUDI, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_FC_STAT1 - Frame Composer Interrupt Mute Control Register 1 (RW)
 *
 * Address Offset: 0x0181  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GCP : 1; //!< When set to 1, mutes IH_ FC_STAT1[0]
        unsigned char AVI : 1; //!< When set to 1, mutes IH_ FC_STAT1[1]
        unsigned char MPEG : 1; //!< When set to 1, mutes IH_ FC_STAT1[2]
        unsigned char SPD : 1; //!< When set to 1, mutes IH_ FC_STAT1[3]
        unsigned char VSD : 1; //!< When set to 1, mutes IH_ FC_STAT1[4]
        unsigned char ISCR2 : 1; //!< When set to 1, mutes IH_ FC_STAT1[5]
        unsigned char ISCR1 : 1; //!< When set to 1, mutes IH_ FC_STAT1[6]
        unsigned char GMD : 1; //!< When set to 1, mutes IH_ FC_STAT1[7]
    } B;
} hw_hdmi_ih_mute_fc_stat1_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_FC_STAT1 register
 */
#define HW_HDMI_IH_MUTE_FC_STAT1_ADDR      (REGS_HDMI_BASE + 0x181)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_FC_STAT1           (*(volatile hw_hdmi_ih_mute_fc_stat1_t *) HW_HDMI_IH_MUTE_FC_STAT1_ADDR)
#define HW_HDMI_IH_MUTE_FC_STAT1_RD()      (HW_HDMI_IH_MUTE_FC_STAT1.U)
#define HW_HDMI_IH_MUTE_FC_STAT1_WR(v)     (HW_HDMI_IH_MUTE_FC_STAT1.U = (v))
#define HW_HDMI_IH_MUTE_FC_STAT1_SET(v)    (HW_HDMI_IH_MUTE_FC_STAT1_WR(HW_HDMI_IH_MUTE_FC_STAT1_RD() |  (v)))
#define HW_HDMI_IH_MUTE_FC_STAT1_CLR(v)    (HW_HDMI_IH_MUTE_FC_STAT1_WR(HW_HDMI_IH_MUTE_FC_STAT1_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_FC_STAT1_TOG(v)    (HW_HDMI_IH_MUTE_FC_STAT1_WR(HW_HDMI_IH_MUTE_FC_STAT1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_FC_STAT1 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_FC_STAT1, field GCP (RW)
 *
 * When set to 1, mutes IH_ FC_STAT1[0]
 */

#define BP_HDMI_IH_MUTE_FC_STAT1_GCP      0
#define BM_HDMI_IH_MUTE_FC_STAT1_GCP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT1_GCP(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_FC_STAT1_GCP)
#else
#define BF_HDMI_IH_MUTE_FC_STAT1_GCP(v)   (((v) << 0) & BM_HDMI_IH_MUTE_FC_STAT1_GCP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCP field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT1_GCP(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT1, GCP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT1, field AVI (RW)
 *
 * When set to 1, mutes IH_ FC_STAT1[1]
 */

#define BP_HDMI_IH_MUTE_FC_STAT1_AVI      1
#define BM_HDMI_IH_MUTE_FC_STAT1_AVI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT1_AVI(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_FC_STAT1_AVI)
#else
#define BF_HDMI_IH_MUTE_FC_STAT1_AVI(v)   (((v) << 1) & BM_HDMI_IH_MUTE_FC_STAT1_AVI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVI field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT1_AVI(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT1, AVI, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT1, field MPEG (RW)
 *
 * When set to 1, mutes IH_ FC_STAT1[2]
 */

#define BP_HDMI_IH_MUTE_FC_STAT1_MPEG      2
#define BM_HDMI_IH_MUTE_FC_STAT1_MPEG      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT1_MPEG(v)   ((((reg32_t) v) << 2) & BM_HDMI_IH_MUTE_FC_STAT1_MPEG)
#else
#define BF_HDMI_IH_MUTE_FC_STAT1_MPEG(v)   (((v) << 2) & BM_HDMI_IH_MUTE_FC_STAT1_MPEG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPEG field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT1_MPEG(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT1, MPEG, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT1, field SPD (RW)
 *
 * When set to 1, mutes IH_ FC_STAT1[3]
 */

#define BP_HDMI_IH_MUTE_FC_STAT1_SPD      3
#define BM_HDMI_IH_MUTE_FC_STAT1_SPD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT1_SPD(v)   ((((reg32_t) v) << 3) & BM_HDMI_IH_MUTE_FC_STAT1_SPD)
#else
#define BF_HDMI_IH_MUTE_FC_STAT1_SPD(v)   (((v) << 3) & BM_HDMI_IH_MUTE_FC_STAT1_SPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SPD field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT1_SPD(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT1, SPD, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT1, field VSD (RW)
 *
 * When set to 1, mutes IH_ FC_STAT1[4]
 */

#define BP_HDMI_IH_MUTE_FC_STAT1_VSD      4
#define BM_HDMI_IH_MUTE_FC_STAT1_VSD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT1_VSD(v)   ((((reg32_t) v) << 4) & BM_HDMI_IH_MUTE_FC_STAT1_VSD)
#else
#define BF_HDMI_IH_MUTE_FC_STAT1_VSD(v)   (((v) << 4) & BM_HDMI_IH_MUTE_FC_STAT1_VSD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSD field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT1_VSD(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT1, VSD, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT1, field ISCR2 (RW)
 *
 * When set to 1, mutes IH_ FC_STAT1[5]
 */

#define BP_HDMI_IH_MUTE_FC_STAT1_ISCR2      5
#define BM_HDMI_IH_MUTE_FC_STAT1_ISCR2      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT1_ISCR2(v)   ((((reg32_t) v) << 5) & BM_HDMI_IH_MUTE_FC_STAT1_ISCR2)
#else
#define BF_HDMI_IH_MUTE_FC_STAT1_ISCR2(v)   (((v) << 5) & BM_HDMI_IH_MUTE_FC_STAT1_ISCR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR2 field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT1_ISCR2(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT1, ISCR2, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT1, field ISCR1 (RW)
 *
 * When set to 1, mutes IH_ FC_STAT1[6]
 */

#define BP_HDMI_IH_MUTE_FC_STAT1_ISCR1      6
#define BM_HDMI_IH_MUTE_FC_STAT1_ISCR1      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT1_ISCR1(v)   ((((reg32_t) v) << 6) & BM_HDMI_IH_MUTE_FC_STAT1_ISCR1)
#else
#define BF_HDMI_IH_MUTE_FC_STAT1_ISCR1(v)   (((v) << 6) & BM_HDMI_IH_MUTE_FC_STAT1_ISCR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR1 field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT1_ISCR1(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT1, ISCR1, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT1, field GMD (RW)
 *
 * When set to 1, mutes IH_ FC_STAT1[7]
 */

#define BP_HDMI_IH_MUTE_FC_STAT1_GMD      7
#define BM_HDMI_IH_MUTE_FC_STAT1_GMD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT1_GMD(v)   ((((reg32_t) v) << 7) & BM_HDMI_IH_MUTE_FC_STAT1_GMD)
#else
#define BF_HDMI_IH_MUTE_FC_STAT1_GMD(v)   (((v) << 7) & BM_HDMI_IH_MUTE_FC_STAT1_GMD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMD field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT1_GMD(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT1, GMD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_FC_STAT2 - Frame Composer Interrupt Mute Control Register 2 (RW)
 *
 * Address Offset: 0x0182  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HIGHPRIORITY_OVERFLOW : 1; //!< When set to 1, mutes IH_ FC_STAT2[0]
        unsigned char LOWPRIORITY_OVERFLOW : 1; //!< When set to 1, mutes IH_ FC_STAT2[1]
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ih_mute_fc_stat2_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_FC_STAT2 register
 */
#define HW_HDMI_IH_MUTE_FC_STAT2_ADDR      (REGS_HDMI_BASE + 0x182)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_FC_STAT2           (*(volatile hw_hdmi_ih_mute_fc_stat2_t *) HW_HDMI_IH_MUTE_FC_STAT2_ADDR)
#define HW_HDMI_IH_MUTE_FC_STAT2_RD()      (HW_HDMI_IH_MUTE_FC_STAT2.U)
#define HW_HDMI_IH_MUTE_FC_STAT2_WR(v)     (HW_HDMI_IH_MUTE_FC_STAT2.U = (v))
#define HW_HDMI_IH_MUTE_FC_STAT2_SET(v)    (HW_HDMI_IH_MUTE_FC_STAT2_WR(HW_HDMI_IH_MUTE_FC_STAT2_RD() |  (v)))
#define HW_HDMI_IH_MUTE_FC_STAT2_CLR(v)    (HW_HDMI_IH_MUTE_FC_STAT2_WR(HW_HDMI_IH_MUTE_FC_STAT2_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_FC_STAT2_TOG(v)    (HW_HDMI_IH_MUTE_FC_STAT2_WR(HW_HDMI_IH_MUTE_FC_STAT2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_FC_STAT2 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_FC_STAT2, field HIGHPRIORITY_OVERFLOW (RW)
 *
 * When set to 1, mutes IH_ FC_STAT2[0]
 */

#define BP_HDMI_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW      0
#define BM_HDMI_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW)
#else
#define BF_HDMI_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW(v)   (((v) << 0) & BM_HDMI_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HIGHPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT2, HIGHPRIORITY_OVERFLOW, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_FC_STAT2, field LOWPRIORITY_OVERFLOW (RW)
 *
 * When set to 1, mutes IH_ FC_STAT2[1]
 */

#define BP_HDMI_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW      1
#define BM_HDMI_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW)
#else
#define BF_HDMI_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW(v)   (((v) << 1) & BM_HDMI_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOWPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_IH_MUTE_FC_STAT2, LOWPRIORITY_OVERFLOW, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_AS_STAT0 - Audio Sampler Interrupt Mute Control Register 0 (RW)
 *
 * Address Offset: 0x0183  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUD_FIFO_OVERFLOW : 1; //!< When set to 1, mutes IH_ AS_STAT0[0]
        unsigned char AUD_FIFO_UNDERFLOW : 1; //!< When set to 1, mutes IH_ AS_STAT0[1]
        unsigned char AUD_FIFO_UNDERFLOW_THR : 1; //!< When set to 1, mutes IH_ AS_STAT0[2]
        unsigned char RESERVED0 : 5; //!< Reserved
    } B;
} hw_hdmi_ih_mute_as_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_AS_STAT0 register
 */
#define HW_HDMI_IH_MUTE_AS_STAT0_ADDR      (REGS_HDMI_BASE + 0x183)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_AS_STAT0           (*(volatile hw_hdmi_ih_mute_as_stat0_t *) HW_HDMI_IH_MUTE_AS_STAT0_ADDR)
#define HW_HDMI_IH_MUTE_AS_STAT0_RD()      (HW_HDMI_IH_MUTE_AS_STAT0.U)
#define HW_HDMI_IH_MUTE_AS_STAT0_WR(v)     (HW_HDMI_IH_MUTE_AS_STAT0.U = (v))
#define HW_HDMI_IH_MUTE_AS_STAT0_SET(v)    (HW_HDMI_IH_MUTE_AS_STAT0_WR(HW_HDMI_IH_MUTE_AS_STAT0_RD() |  (v)))
#define HW_HDMI_IH_MUTE_AS_STAT0_CLR(v)    (HW_HDMI_IH_MUTE_AS_STAT0_WR(HW_HDMI_IH_MUTE_AS_STAT0_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_AS_STAT0_TOG(v)    (HW_HDMI_IH_MUTE_AS_STAT0_WR(HW_HDMI_IH_MUTE_AS_STAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_AS_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_AS_STAT0, field AUD_FIFO_OVERFLOW (RW)
 *
 * When set to 1, mutes IH_ AS_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW      0
#define BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW)
#else
#define BF_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW(v)   (((v) << 0) & BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUD_FIFO_OVERFLOW field to a new value.
#define BW_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW(v)   BF_CS1(HDMI_IH_MUTE_AS_STAT0, AUD_FIFO_OVERFLOW, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_AS_STAT0, field AUD_FIFO_UNDERFLOW (RW)
 *
 * When set to 1, mutes IH_ AS_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW      1
#define BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW)
#else
#define BF_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW(v)   (((v) << 1) & BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUD_FIFO_UNDERFLOW field to a new value.
#define BW_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW(v)   BF_CS1(HDMI_IH_MUTE_AS_STAT0, AUD_FIFO_UNDERFLOW, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_AS_STAT0, field AUD_FIFO_UNDERFLOW_THR (RW)
 *
 * When set to 1, mutes IH_ AS_STAT0[2]
 */

#define BP_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR      2
#define BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR(v)   ((((reg32_t) v) << 2) & BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR)
#else
#define BF_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR(v)   (((v) << 2) & BM_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUD_FIFO_UNDERFLOW_THR field to a new value.
#define BW_HDMI_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR(v)   BF_CS1(HDMI_IH_MUTE_AS_STAT0, AUD_FIFO_UNDERFLOW_THR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_PHY_STAT0 - PHY Interface Interrupt Mute Control Register (RW)
 *
 * Address Offset: 0x0184  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDP : 1; //!< When set to 1, mutes IH_ PHY_STAT0[0]
        unsigned char TX_PHY_LOCK : 1; //!< When set to 1, mutes IH_ PHY_STAT0[1]
        unsigned char RX_SENSE : 1; //!< When set to 1, mutes IH_ PHY_STAT0[2]
        unsigned char RX_SENSE1 : 1; //!< When set to 1, mutes IH_ PHY_STAT0[3]
        unsigned char RX_SENSE2 : 1; //!< When set to 1, mutes IH_ PHY_STAT0[4]
        unsigned char RX_SENSE3 : 1; //!< When set to 1, mutes IH_ PHY_STAT0[5]
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_ih_mute_phy_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_PHY_STAT0 register
 */
#define HW_HDMI_IH_MUTE_PHY_STAT0_ADDR      (REGS_HDMI_BASE + 0x184)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_PHY_STAT0           (*(volatile hw_hdmi_ih_mute_phy_stat0_t *) HW_HDMI_IH_MUTE_PHY_STAT0_ADDR)
#define HW_HDMI_IH_MUTE_PHY_STAT0_RD()      (HW_HDMI_IH_MUTE_PHY_STAT0.U)
#define HW_HDMI_IH_MUTE_PHY_STAT0_WR(v)     (HW_HDMI_IH_MUTE_PHY_STAT0.U = (v))
#define HW_HDMI_IH_MUTE_PHY_STAT0_SET(v)    (HW_HDMI_IH_MUTE_PHY_STAT0_WR(HW_HDMI_IH_MUTE_PHY_STAT0_RD() |  (v)))
#define HW_HDMI_IH_MUTE_PHY_STAT0_CLR(v)    (HW_HDMI_IH_MUTE_PHY_STAT0_WR(HW_HDMI_IH_MUTE_PHY_STAT0_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_PHY_STAT0_TOG(v)    (HW_HDMI_IH_MUTE_PHY_STAT0_WR(HW_HDMI_IH_MUTE_PHY_STAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_PHY_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_PHY_STAT0, field HDP (RW)
 *
 * When set to 1, mutes IH_ PHY_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_PHY_STAT0_HDP      0
#define BM_HDMI_IH_MUTE_PHY_STAT0_HDP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_PHY_STAT0_HDP(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_PHY_STAT0_HDP)
#else
#define BF_HDMI_IH_MUTE_PHY_STAT0_HDP(v)   (((v) << 0) & BM_HDMI_IH_MUTE_PHY_STAT0_HDP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDP field to a new value.
#define BW_HDMI_IH_MUTE_PHY_STAT0_HDP(v)   BF_CS1(HDMI_IH_MUTE_PHY_STAT0, HDP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_PHY_STAT0, field TX_PHY_LOCK (RW)
 *
 * When set to 1, mutes IH_ PHY_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_PHY_STAT0_TX_PHY_LOCK      1
#define BM_HDMI_IH_MUTE_PHY_STAT0_TX_PHY_LOCK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_PHY_STAT0_TX_PHY_LOCK(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_PHY_STAT0_TX_PHY_LOCK)
#else
#define BF_HDMI_IH_MUTE_PHY_STAT0_TX_PHY_LOCK(v)   (((v) << 1) & BM_HDMI_IH_MUTE_PHY_STAT0_TX_PHY_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_PHY_LOCK field to a new value.
#define BW_HDMI_IH_MUTE_PHY_STAT0_TX_PHY_LOCK(v)   BF_CS1(HDMI_IH_MUTE_PHY_STAT0, TX_PHY_LOCK, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_PHY_STAT0, field RX_SENSE (RW)
 *
 * When set to 1, mutes IH_ PHY_STAT0[2]
 */

#define BP_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE      2
#define BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   ((((reg32_t) v) << 2) & BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE)
#else
#define BF_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   (((v) << 2) & BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   BF_CS1(HDMI_IH_MUTE_PHY_STAT0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_PHY_STAT0, field RX_SENSE (RW)
 *
 * When set to 1, mutes IH_ PHY_STAT0[3]
 */

#define BP_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE      3
#define BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   ((((reg32_t) v) << 3) & BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE)
#else
#define BF_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   (((v) << 3) & BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   BF_CS1(HDMI_IH_MUTE_PHY_STAT0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_PHY_STAT0, field RX_SENSE (RW)
 *
 * When set to 1, mutes IH_ PHY_STAT0[4]
 */

#define BP_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE      4
#define BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   ((((reg32_t) v) << 4) & BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE)
#else
#define BF_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   (((v) << 4) & BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   BF_CS1(HDMI_IH_MUTE_PHY_STAT0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_PHY_STAT0, field RX_SENSE (RW)
 *
 * When set to 1, mutes IH_ PHY_STAT0[5]
 */

#define BP_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE      5
#define BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   ((((reg32_t) v) << 5) & BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE)
#else
#define BF_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   (((v) << 5) & BM_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_IH_MUTE_PHY_STAT0_RX_SENSE(v)   BF_CS1(HDMI_IH_MUTE_PHY_STAT0, RX_SENSE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_I2CM_STAT0 - E-DDC I2C Master Interrupt Mute Control Register (RW)
 *
 * Address Offset: 0x0185  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMASTER_ERROR : 1; //!< When set to 1, mutes IH_ I2CM_STAT0[0]
        unsigned char I2CMASTERDONE : 1; //!< When set to 1, mutes IH_ I2CM_STAT0[1]
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ih_mute_i2cm_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_I2CM_STAT0 register
 */
#define HW_HDMI_IH_MUTE_I2CM_STAT0_ADDR      (REGS_HDMI_BASE + 0x185)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_I2CM_STAT0           (*(volatile hw_hdmi_ih_mute_i2cm_stat0_t *) HW_HDMI_IH_MUTE_I2CM_STAT0_ADDR)
#define HW_HDMI_IH_MUTE_I2CM_STAT0_RD()      (HW_HDMI_IH_MUTE_I2CM_STAT0.U)
#define HW_HDMI_IH_MUTE_I2CM_STAT0_WR(v)     (HW_HDMI_IH_MUTE_I2CM_STAT0.U = (v))
#define HW_HDMI_IH_MUTE_I2CM_STAT0_SET(v)    (HW_HDMI_IH_MUTE_I2CM_STAT0_WR(HW_HDMI_IH_MUTE_I2CM_STAT0_RD() |  (v)))
#define HW_HDMI_IH_MUTE_I2CM_STAT0_CLR(v)    (HW_HDMI_IH_MUTE_I2CM_STAT0_WR(HW_HDMI_IH_MUTE_I2CM_STAT0_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_I2CM_STAT0_TOG(v)    (HW_HDMI_IH_MUTE_I2CM_STAT0_WR(HW_HDMI_IH_MUTE_I2CM_STAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_I2CM_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_I2CM_STAT0, field I2CMASTER_ERROR (RW)
 *
 * When set to 1, mutes IH_ I2CM_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTER_ERROR      0
#define BM_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTER_ERROR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTER_ERROR(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTER_ERROR)
#else
#define BF_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTER_ERROR(v)   (((v) << 0) & BM_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTER_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMASTER_ERROR field to a new value.
#define BW_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTER_ERROR(v)   BF_CS1(HDMI_IH_MUTE_I2CM_STAT0, I2CMASTER_ERROR, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_I2CM_STAT0, field I2CMASTERDONE (RW)
 *
 * When set to 1, mutes IH_ I2CM_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTERDONE      1
#define BM_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTERDONE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTERDONE(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTERDONE)
#else
#define BF_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTERDONE(v)   (((v) << 1) & BM_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTERDONE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMASTERDONE field to a new value.
#define BW_HDMI_IH_MUTE_I2CM_STAT0_I2CMASTERDONE(v)   BF_CS1(HDMI_IH_MUTE_I2CM_STAT0, I2CMASTERDONE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_CEC_STAT0 - CEC Interrupt Mute Control Register (RW)
 *
 * Address Offset: 0x0186  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DONE : 1; //!< When set to 1, mutes IH_ CEC_STAT0[0]
        unsigned char EOM : 1; //!< When set to 1, mutes IH_ CEC_STAT0[1]
        unsigned char NACK : 1; //!< When set to 1, mutes IH_ CEC_STAT0[2]
        unsigned char ARB_LOST : 1; //!< When set to 1, mutes IH_ CEC_STAT0[3]
        unsigned char ERROR_INITIATOR : 1; //!< When set to 1, mutes IH_ CEC_STAT0[4]
        unsigned char ERROR_FOLLOW : 1; //!< When set to 1, mutes IH_ CEC_STAT0[5]
        unsigned char WAKEUP : 1; //!< When set to 1, mutes IH_ CEC_STAT0[6]
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_ih_mute_cec_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_CEC_STAT0 register
 */
#define HW_HDMI_IH_MUTE_CEC_STAT0_ADDR      (REGS_HDMI_BASE + 0x186)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_CEC_STAT0           (*(volatile hw_hdmi_ih_mute_cec_stat0_t *) HW_HDMI_IH_MUTE_CEC_STAT0_ADDR)
#define HW_HDMI_IH_MUTE_CEC_STAT0_RD()      (HW_HDMI_IH_MUTE_CEC_STAT0.U)
#define HW_HDMI_IH_MUTE_CEC_STAT0_WR(v)     (HW_HDMI_IH_MUTE_CEC_STAT0.U = (v))
#define HW_HDMI_IH_MUTE_CEC_STAT0_SET(v)    (HW_HDMI_IH_MUTE_CEC_STAT0_WR(HW_HDMI_IH_MUTE_CEC_STAT0_RD() |  (v)))
#define HW_HDMI_IH_MUTE_CEC_STAT0_CLR(v)    (HW_HDMI_IH_MUTE_CEC_STAT0_WR(HW_HDMI_IH_MUTE_CEC_STAT0_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_CEC_STAT0_TOG(v)    (HW_HDMI_IH_MUTE_CEC_STAT0_WR(HW_HDMI_IH_MUTE_CEC_STAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_CEC_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_CEC_STAT0, field DONE (RW)
 *
 * When set to 1, mutes IH_ CEC_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_CEC_STAT0_DONE      0
#define BM_HDMI_IH_MUTE_CEC_STAT0_DONE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_CEC_STAT0_DONE(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_CEC_STAT0_DONE)
#else
#define BF_HDMI_IH_MUTE_CEC_STAT0_DONE(v)   (((v) << 0) & BM_HDMI_IH_MUTE_CEC_STAT0_DONE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE field to a new value.
#define BW_HDMI_IH_MUTE_CEC_STAT0_DONE(v)   BF_CS1(HDMI_IH_MUTE_CEC_STAT0, DONE, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_CEC_STAT0, field EOM (RW)
 *
 * When set to 1, mutes IH_ CEC_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_CEC_STAT0_EOM      1
#define BM_HDMI_IH_MUTE_CEC_STAT0_EOM      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_CEC_STAT0_EOM(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_CEC_STAT0_EOM)
#else
#define BF_HDMI_IH_MUTE_CEC_STAT0_EOM(v)   (((v) << 1) & BM_HDMI_IH_MUTE_CEC_STAT0_EOM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EOM field to a new value.
#define BW_HDMI_IH_MUTE_CEC_STAT0_EOM(v)   BF_CS1(HDMI_IH_MUTE_CEC_STAT0, EOM, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_CEC_STAT0, field NACK (RW)
 *
 * When set to 1, mutes IH_ CEC_STAT0[2]
 */

#define BP_HDMI_IH_MUTE_CEC_STAT0_NACK      2
#define BM_HDMI_IH_MUTE_CEC_STAT0_NACK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_CEC_STAT0_NACK(v)   ((((reg32_t) v) << 2) & BM_HDMI_IH_MUTE_CEC_STAT0_NACK)
#else
#define BF_HDMI_IH_MUTE_CEC_STAT0_NACK(v)   (((v) << 2) & BM_HDMI_IH_MUTE_CEC_STAT0_NACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK field to a new value.
#define BW_HDMI_IH_MUTE_CEC_STAT0_NACK(v)   BF_CS1(HDMI_IH_MUTE_CEC_STAT0, NACK, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_CEC_STAT0, field ARB_LOST (RW)
 *
 * When set to 1, mutes IH_ CEC_STAT0[3]
 */

#define BP_HDMI_IH_MUTE_CEC_STAT0_ARB_LOST      3
#define BM_HDMI_IH_MUTE_CEC_STAT0_ARB_LOST      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_CEC_STAT0_ARB_LOST(v)   ((((reg32_t) v) << 3) & BM_HDMI_IH_MUTE_CEC_STAT0_ARB_LOST)
#else
#define BF_HDMI_IH_MUTE_CEC_STAT0_ARB_LOST(v)   (((v) << 3) & BM_HDMI_IH_MUTE_CEC_STAT0_ARB_LOST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARB_LOST field to a new value.
#define BW_HDMI_IH_MUTE_CEC_STAT0_ARB_LOST(v)   BF_CS1(HDMI_IH_MUTE_CEC_STAT0, ARB_LOST, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_CEC_STAT0, field ERROR_INITIATOR (RW)
 *
 * When set to 1, mutes IH_ CEC_STAT0[4]
 */

#define BP_HDMI_IH_MUTE_CEC_STAT0_ERROR_INITIATOR      4
#define BM_HDMI_IH_MUTE_CEC_STAT0_ERROR_INITIATOR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_CEC_STAT0_ERROR_INITIATOR(v)   ((((reg32_t) v) << 4) & BM_HDMI_IH_MUTE_CEC_STAT0_ERROR_INITIATOR)
#else
#define BF_HDMI_IH_MUTE_CEC_STAT0_ERROR_INITIATOR(v)   (((v) << 4) & BM_HDMI_IH_MUTE_CEC_STAT0_ERROR_INITIATOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_INITIATOR field to a new value.
#define BW_HDMI_IH_MUTE_CEC_STAT0_ERROR_INITIATOR(v)   BF_CS1(HDMI_IH_MUTE_CEC_STAT0, ERROR_INITIATOR, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_CEC_STAT0, field ERROR_FOLLOW (RW)
 *
 * When set to 1, mutes IH_ CEC_STAT0[5]
 */

#define BP_HDMI_IH_MUTE_CEC_STAT0_ERROR_FOLLOW      5
#define BM_HDMI_IH_MUTE_CEC_STAT0_ERROR_FOLLOW      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_CEC_STAT0_ERROR_FOLLOW(v)   ((((reg32_t) v) << 5) & BM_HDMI_IH_MUTE_CEC_STAT0_ERROR_FOLLOW)
#else
#define BF_HDMI_IH_MUTE_CEC_STAT0_ERROR_FOLLOW(v)   (((v) << 5) & BM_HDMI_IH_MUTE_CEC_STAT0_ERROR_FOLLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_FOLLOW field to a new value.
#define BW_HDMI_IH_MUTE_CEC_STAT0_ERROR_FOLLOW(v)   BF_CS1(HDMI_IH_MUTE_CEC_STAT0, ERROR_FOLLOW, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_CEC_STAT0, field WAKEUP (RW)
 *
 * When set to 1, mutes IH_ CEC_STAT0[6]
 */

#define BP_HDMI_IH_MUTE_CEC_STAT0_WAKEUP      6
#define BM_HDMI_IH_MUTE_CEC_STAT0_WAKEUP      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_CEC_STAT0_WAKEUP(v)   ((((reg32_t) v) << 6) & BM_HDMI_IH_MUTE_CEC_STAT0_WAKEUP)
#else
#define BF_HDMI_IH_MUTE_CEC_STAT0_WAKEUP(v)   (((v) << 6) & BM_HDMI_IH_MUTE_CEC_STAT0_WAKEUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP field to a new value.
#define BW_HDMI_IH_MUTE_CEC_STAT0_WAKEUP(v)   BF_CS1(HDMI_IH_MUTE_CEC_STAT0, WAKEUP, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_VP_STAT0 - Video Packetizer Interrupt Mute Control Register (RW)
 *
 * Address Offset: 0x0187  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FIFOEMPTYBYP : 1; //!< When set to 1, mutes IH_ VP_STAT0[0]
        unsigned char FIFOFULLBYP : 1; //!< When set to 1, mutes IH_ VP_STAT0[1]
        unsigned char FIFOEMPTYREMAP : 1; //!< When set to 1, mutes IH_ VP_STAT0[2]
        unsigned char FIFOFULLREMAP : 1; //!< When set to 1, mutes IH_ VP_STAT0[3]
        unsigned char FIFOEMPTYPP : 1; //!< When set to 1, mutes IH_ VP_STAT0[4]
        unsigned char FIFOFULLPP : 1; //!< When set to 1, mutes IH_ VP_STAT0[5]
        unsigned char FIFOEMPTYREPET : 1; //!< When set to 1, mutes IH_ VP_STAT0[6]
        unsigned char FIFOFULLREPET : 1; //!< When set to 1, mutes IH_ VP_STAT0[7]
    } B;
} hw_hdmi_ih_mute_vp_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_VP_STAT0 register
 */
#define HW_HDMI_IH_MUTE_VP_STAT0_ADDR      (REGS_HDMI_BASE + 0x187)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_VP_STAT0           (*(volatile hw_hdmi_ih_mute_vp_stat0_t *) HW_HDMI_IH_MUTE_VP_STAT0_ADDR)
#define HW_HDMI_IH_MUTE_VP_STAT0_RD()      (HW_HDMI_IH_MUTE_VP_STAT0.U)
#define HW_HDMI_IH_MUTE_VP_STAT0_WR(v)     (HW_HDMI_IH_MUTE_VP_STAT0.U = (v))
#define HW_HDMI_IH_MUTE_VP_STAT0_SET(v)    (HW_HDMI_IH_MUTE_VP_STAT0_WR(HW_HDMI_IH_MUTE_VP_STAT0_RD() |  (v)))
#define HW_HDMI_IH_MUTE_VP_STAT0_CLR(v)    (HW_HDMI_IH_MUTE_VP_STAT0_WR(HW_HDMI_IH_MUTE_VP_STAT0_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_VP_STAT0_TOG(v)    (HW_HDMI_IH_MUTE_VP_STAT0_WR(HW_HDMI_IH_MUTE_VP_STAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_VP_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_VP_STAT0, field FIFOEMPTYBYP (RW)
 *
 * When set to 1, mutes IH_ VP_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYBYP      0
#define BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYBYP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYBYP(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYBYP)
#else
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYBYP(v)   (((v) << 0) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYBYP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFOEMPTYBYP field to a new value.
#define BW_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYBYP(v)   BF_CS1(HDMI_IH_MUTE_VP_STAT0, FIFOEMPTYBYP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_VP_STAT0, field FIFOFULLBYP (RW)
 *
 * When set to 1, mutes IH_ VP_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_VP_STAT0_FIFOFULLBYP      1
#define BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLBYP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOFULLBYP(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLBYP)
#else
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOFULLBYP(v)   (((v) << 1) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLBYP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFOFULLBYP field to a new value.
#define BW_HDMI_IH_MUTE_VP_STAT0_FIFOFULLBYP(v)   BF_CS1(HDMI_IH_MUTE_VP_STAT0, FIFOFULLBYP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_VP_STAT0, field FIFOEMPTYREMAP (RW)
 *
 * When set to 1, mutes IH_ VP_STAT0[2]
 */

#define BP_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP      2
#define BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP(v)   ((((reg32_t) v) << 2) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP)
#else
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP(v)   (((v) << 2) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFOEMPTYREMAP field to a new value.
#define BW_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP(v)   BF_CS1(HDMI_IH_MUTE_VP_STAT0, FIFOEMPTYREMAP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_VP_STAT0, field FIFOFULLREMAP (RW)
 *
 * When set to 1, mutes IH_ VP_STAT0[3]
 */

#define BP_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREMAP      3
#define BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREMAP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREMAP(v)   ((((reg32_t) v) << 3) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREMAP)
#else
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREMAP(v)   (((v) << 3) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREMAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFOFULLREMAP field to a new value.
#define BW_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREMAP(v)   BF_CS1(HDMI_IH_MUTE_VP_STAT0, FIFOFULLREMAP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_VP_STAT0, field FIFOEMPTYPP (RW)
 *
 * When set to 1, mutes IH_ VP_STAT0[4]
 */

#define BP_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYPP      4
#define BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYPP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYPP(v)   ((((reg32_t) v) << 4) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYPP)
#else
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYPP(v)   (((v) << 4) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYPP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFOEMPTYPP field to a new value.
#define BW_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYPP(v)   BF_CS1(HDMI_IH_MUTE_VP_STAT0, FIFOEMPTYPP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_VP_STAT0, field FIFOFULLPP (RW)
 *
 * When set to 1, mutes IH_ VP_STAT0[5]
 */

#define BP_HDMI_IH_MUTE_VP_STAT0_FIFOFULLPP      5
#define BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLPP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOFULLPP(v)   ((((reg32_t) v) << 5) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLPP)
#else
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOFULLPP(v)   (((v) << 5) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLPP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFOFULLPP field to a new value.
#define BW_HDMI_IH_MUTE_VP_STAT0_FIFOFULLPP(v)   BF_CS1(HDMI_IH_MUTE_VP_STAT0, FIFOFULLPP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_VP_STAT0, field FIFOEMPTYREPET (RW)
 *
 * When set to 1, mutes IH_ VP_STAT0[6]
 */

#define BP_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREPET      6
#define BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREPET      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREPET(v)   ((((reg32_t) v) << 6) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREPET)
#else
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREPET(v)   (((v) << 6) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREPET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFOEMPTYREPET field to a new value.
#define BW_HDMI_IH_MUTE_VP_STAT0_FIFOEMPTYREPET(v)   BF_CS1(HDMI_IH_MUTE_VP_STAT0, FIFOEMPTYREPET, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_VP_STAT0, field FIFOFULLREPET (RW)
 *
 * When set to 1, mutes IH_ VP_STAT0[7]
 */

#define BP_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREPET      7
#define BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREPET      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREPET(v)   ((((reg32_t) v) << 7) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREPET)
#else
#define BF_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREPET(v)   (((v) << 7) & BM_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREPET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFOFULLREPET field to a new value.
#define BW_HDMI_IH_MUTE_VP_STAT0_FIFOFULLREPET(v)   BF_CS1(HDMI_IH_MUTE_VP_STAT0, FIFOFULLREPET, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_I2CMPHY_STAT0 - PHY GEN 2 I2C Master Interrupt Mute Control Register (RW)
 *
 * Address Offset: 0x0188  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMPHYERROR : 1; //!< When set to 1, mutes IH_ I2CMPHY_STAT0[0]
        unsigned char I2CMPHYDONE : 1; //!< When set to 1, mutes IH_ I2CMPHY_STAT0[1]
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ih_mute_i2cmphy_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_I2CMPHY_STAT0 register
 */
#define HW_HDMI_IH_MUTE_I2CMPHY_STAT0_ADDR      (REGS_HDMI_BASE + 0x188)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_I2CMPHY_STAT0           (*(volatile hw_hdmi_ih_mute_i2cmphy_stat0_t *) HW_HDMI_IH_MUTE_I2CMPHY_STAT0_ADDR)
#define HW_HDMI_IH_MUTE_I2CMPHY_STAT0_RD()      (HW_HDMI_IH_MUTE_I2CMPHY_STAT0.U)
#define HW_HDMI_IH_MUTE_I2CMPHY_STAT0_WR(v)     (HW_HDMI_IH_MUTE_I2CMPHY_STAT0.U = (v))
#define HW_HDMI_IH_MUTE_I2CMPHY_STAT0_SET(v)    (HW_HDMI_IH_MUTE_I2CMPHY_STAT0_WR(HW_HDMI_IH_MUTE_I2CMPHY_STAT0_RD() |  (v)))
#define HW_HDMI_IH_MUTE_I2CMPHY_STAT0_CLR(v)    (HW_HDMI_IH_MUTE_I2CMPHY_STAT0_WR(HW_HDMI_IH_MUTE_I2CMPHY_STAT0_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_I2CMPHY_STAT0_TOG(v)    (HW_HDMI_IH_MUTE_I2CMPHY_STAT0_WR(HW_HDMI_IH_MUTE_I2CMPHY_STAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_I2CMPHY_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_I2CMPHY_STAT0, field I2CMPHYERROR (RW)
 *
 * When set to 1, mutes IH_ I2CMPHY_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR      0
#define BM_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR)
#else
#define BF_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR(v)   (((v) << 0) & BM_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMPHYERROR field to a new value.
#define BW_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR(v)   BF_CS1(HDMI_IH_MUTE_I2CMPHY_STAT0, I2CMPHYERROR, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_I2CMPHY_STAT0, field I2CMPHYDONE (RW)
 *
 * When set to 1, mutes IH_ I2CMPHY_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE      1
#define BM_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE)
#else
#define BF_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE(v)   (((v) << 1) & BM_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMPHYDONE field to a new value.
#define BW_HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE(v)   BF_CS1(HDMI_IH_MUTE_I2CMPHY_STAT0, I2CMPHYDONE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0 - AHB Audio DMA Interrupt Mute Control Register (RW)
 *
 * Address Offset: 0x0189  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AHBDMAAUD_INTBUFFEMPTY : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[0]
        unsigned char AHBDMAAUD_INTBUFFFULL : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[1]
        unsigned char AHBDMAAUD_INTDONE : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[2]
        unsigned char AHBDMAAUD_INTRETRYSPLIT : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[3]
        unsigned char AHBDMAAUD_INTLOSTOWNERSHIP : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[4]
        unsigned char AHBDMAAUD_INTERROR : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[5]
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_ih_mute_ahbdmaaud_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE_AHBDMAAUD_STAT0 register
 */
#define HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_ADDR      (REGS_HDMI_BASE + 0x189)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0           (*(volatile hw_hdmi_ih_mute_ahbdmaaud_stat0_t *) HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_ADDR)
#define HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_RD()      (HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0.U)
#define HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_WR(v)     (HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0.U = (v))
#define HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_SET(v)    (HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_WR(HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_RD() |  (v)))
#define HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_CLR(v)    (HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_WR(HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_TOG(v)    (HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_WR(HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE_AHBDMAAUD_STAT0 bitfields
 */

/* --- Register HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0, field AHBDMAAUD_INTBUFFEMPTY (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY      0
#define BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY(v)   (((v) << 0) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTBUFFEMPTY field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFEMPTY(v)   BF_CS1(HDMI_IH_MUTE_AHBDMAAUD_STAT0, AHBDMAAUD_INTBUFFEMPTY, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0, field AHBDMAAUD_INTBUFFFULL (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL      1
#define BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL(v)   (((v) << 1) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTBUFFFULL field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTBUFFFULL(v)   BF_CS1(HDMI_IH_MUTE_AHBDMAAUD_STAT0, AHBDMAAUD_INTBUFFFULL, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0, field AHBDMAAUD_INTDONE (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[2]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE      2
#define BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE(v)   ((((reg32_t) v) << 2) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE(v)   (((v) << 2) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTDONE field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTDONE(v)   BF_CS1(HDMI_IH_MUTE_AHBDMAAUD_STAT0, AHBDMAAUD_INTDONE, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0, field AHBDMAAUD_INTRETRYSPLIT (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[3]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT      3
#define BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT(v)   ((((reg32_t) v) << 3) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT(v)   (((v) << 3) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTRETRYSPLIT field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTRETRYSPLIT(v)   BF_CS1(HDMI_IH_MUTE_AHBDMAAUD_STAT0, AHBDMAAUD_INTRETRYSPLIT, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0, field AHBDMAAUD_INTLOSTOWNERSHIP (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[4]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP      4
#define BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP(v)   ((((reg32_t) v) << 4) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP(v)   (((v) << 4) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTLOSTOWNERSHIP field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTLOSTOWNERSHIP(v)   BF_CS1(HDMI_IH_MUTE_AHBDMAAUD_STAT0, AHBDMAAUD_INTLOSTOWNERSHIP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE_AHBDMAAUD_STAT0, field AHBDMAAUD_INTERROR (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[5]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR      5
#define BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR(v)   ((((reg32_t) v) << 5) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR(v)   (((v) << 5) & BM_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTERROR field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_STAT0_AHBDMAAUD_INTERROR(v)   BF_CS1(HDMI_IH_MUTE_AHBDMAAUD_STAT0, AHBDMAAUD_INTERROR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_IH_MUTE - Global Interrupt Mute Control Register (RW)
 *
 * Address Offset: 0x01FF  Size: 8 bits  Value after Reset: 0x03  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AHBDMAAUD_INTBUFFEMPTY : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[0]
        unsigned char AHBDMAAUD_INTBUFFFULL : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[1]
        unsigned char AHBDMAAUD_INTDONE : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[2]
        unsigned char AHBDMAAUD_INTRETRYSPLIT : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[3]
        unsigned char AHBDMAAUD_INTLOSTOWNERSHIP : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[4]
        unsigned char AHBDMAAUD_INTERROR : 1; //!< When set to 1, mutes IH_AHBDMAAUD_STAT0[5]
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_ih_mute_t;
#endif

/*
 * constants & macros for entire HDMI_IH_MUTE register
 */
#define HW_HDMI_IH_MUTE_ADDR      (REGS_HDMI_BASE + 0x1ff)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_IH_MUTE           (*(volatile hw_hdmi_ih_mute_t *) HW_HDMI_IH_MUTE_ADDR)
#define HW_HDMI_IH_MUTE_RD()      (HW_HDMI_IH_MUTE.U)
#define HW_HDMI_IH_MUTE_WR(v)     (HW_HDMI_IH_MUTE.U = (v))
#define HW_HDMI_IH_MUTE_SET(v)    (HW_HDMI_IH_MUTE_WR(HW_HDMI_IH_MUTE_RD() |  (v)))
#define HW_HDMI_IH_MUTE_CLR(v)    (HW_HDMI_IH_MUTE_WR(HW_HDMI_IH_MUTE_RD() & ~(v)))
#define HW_HDMI_IH_MUTE_TOG(v)    (HW_HDMI_IH_MUTE_WR(HW_HDMI_IH_MUTE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_IH_MUTE bitfields
 */

/* --- Register HW_HDMI_IH_MUTE, field AHBDMAAUD_INTBUFFEMPTY (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[0]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFEMPTY      0
#define BM_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFEMPTY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFEMPTY(v)   ((((reg32_t) v) << 0) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFEMPTY)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFEMPTY(v)   (((v) << 0) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFEMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTBUFFEMPTY field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFEMPTY(v)   BF_CS1(HDMI_IH_MUTE, AHBDMAAUD_INTBUFFEMPTY, v)
#endif

/* --- Register HW_HDMI_IH_MUTE, field AHBDMAAUD_INTBUFFFULL (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[1]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFFULL      1
#define BM_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFFULL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFFULL(v)   ((((reg32_t) v) << 1) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFFULL)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFFULL(v)   (((v) << 1) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFFULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTBUFFFULL field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_INTBUFFFULL(v)   BF_CS1(HDMI_IH_MUTE, AHBDMAAUD_INTBUFFFULL, v)
#endif

/* --- Register HW_HDMI_IH_MUTE, field AHBDMAAUD_INTDONE (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[2]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_INTDONE      2
#define BM_HDMI_IH_MUTE_AHBDMAAUD_INTDONE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTDONE(v)   ((((reg32_t) v) << 2) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTDONE)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTDONE(v)   (((v) << 2) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTDONE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTDONE field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_INTDONE(v)   BF_CS1(HDMI_IH_MUTE, AHBDMAAUD_INTDONE, v)
#endif

/* --- Register HW_HDMI_IH_MUTE, field AHBDMAAUD_INTRETRYSPLIT (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[3]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_INTRETRYSPLIT      3
#define BM_HDMI_IH_MUTE_AHBDMAAUD_INTRETRYSPLIT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTRETRYSPLIT(v)   ((((reg32_t) v) << 3) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTRETRYSPLIT)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTRETRYSPLIT(v)   (((v) << 3) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTRETRYSPLIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTRETRYSPLIT field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_INTRETRYSPLIT(v)   BF_CS1(HDMI_IH_MUTE, AHBDMAAUD_INTRETRYSPLIT, v)
#endif

/* --- Register HW_HDMI_IH_MUTE, field AHBDMAAUD_INTLOSTOWNERSHIP (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[4]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_INTLOSTOWNERSHIP      4
#define BM_HDMI_IH_MUTE_AHBDMAAUD_INTLOSTOWNERSHIP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTLOSTOWNERSHIP(v)   ((((reg32_t) v) << 4) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTLOSTOWNERSHIP)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTLOSTOWNERSHIP(v)   (((v) << 4) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTLOSTOWNERSHIP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTLOSTOWNERSHIP field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_INTLOSTOWNERSHIP(v)   BF_CS1(HDMI_IH_MUTE, AHBDMAAUD_INTLOSTOWNERSHIP, v)
#endif

/* --- Register HW_HDMI_IH_MUTE, field AHBDMAAUD_INTERROR (RW)
 *
 * When set to 1, mutes IH_AHBDMAAUD_STAT0[5]
 */

#define BP_HDMI_IH_MUTE_AHBDMAAUD_INTERROR      5
#define BM_HDMI_IH_MUTE_AHBDMAAUD_INTERROR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTERROR(v)   ((((reg32_t) v) << 5) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTERROR)
#else
#define BF_HDMI_IH_MUTE_AHBDMAAUD_INTERROR(v)   (((v) << 5) & BM_HDMI_IH_MUTE_AHBDMAAUD_INTERROR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBDMAAUD_INTERROR field to a new value.
#define BW_HDMI_IH_MUTE_AHBDMAAUD_INTERROR(v)   BF_CS1(HDMI_IH_MUTE, AHBDMAAUD_INTERROR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_TX_INVID0 - Video Input Mapping and Internal Data Enable Configuration Register (RW)
 *
 * This registers contains the input video mapping code as defined in Table 2-1.   Address Offset:
 * 0x0200  Size: 8 bits  Value after Reset: 0x01  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char VIDEO_MAPPING : 5; //!< video_mapping
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char INTERNAL_DE_GENERATOR : 1; //!< Internal data enable (DE) generator enable. If data enable is not available for the input video the user may set this bit to one to activate the internal data enable generator. This feature only works for input video modes that have native repetition (such as, all CEA videos). No desired pixel repetition can be used with this feature because these configurations only affect the Frame Composer and not this block.
    } B;
} hw_hdmi_tx_invid0_t;
#endif

/*
 * constants & macros for entire HDMI_TX_INVID0 register
 */
#define HW_HDMI_TX_INVID0_ADDR      (REGS_HDMI_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_TX_INVID0           (*(volatile hw_hdmi_tx_invid0_t *) HW_HDMI_TX_INVID0_ADDR)
#define HW_HDMI_TX_INVID0_RD()      (HW_HDMI_TX_INVID0.U)
#define HW_HDMI_TX_INVID0_WR(v)     (HW_HDMI_TX_INVID0.U = (v))
#define HW_HDMI_TX_INVID0_SET(v)    (HW_HDMI_TX_INVID0_WR(HW_HDMI_TX_INVID0_RD() |  (v)))
#define HW_HDMI_TX_INVID0_CLR(v)    (HW_HDMI_TX_INVID0_WR(HW_HDMI_TX_INVID0_RD() & ~(v)))
#define HW_HDMI_TX_INVID0_TOG(v)    (HW_HDMI_TX_INVID0_WR(HW_HDMI_TX_INVID0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_TX_INVID0 bitfields
 */

/* --- Register HW_HDMI_TX_INVID0, field VIDEO_MAPPING (RW)
 *
 * video_mapping
 */

#define BP_HDMI_TX_INVID0_VIDEO_MAPPING      0
#define BM_HDMI_TX_INVID0_VIDEO_MAPPING      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_INVID0_VIDEO_MAPPING(v)   ((((reg32_t) v) << 0) & BM_HDMI_TX_INVID0_VIDEO_MAPPING)
#else
#define BF_HDMI_TX_INVID0_VIDEO_MAPPING(v)   (((v) << 0) & BM_HDMI_TX_INVID0_VIDEO_MAPPING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VIDEO_MAPPING field to a new value.
#define BW_HDMI_TX_INVID0_VIDEO_MAPPING(v)   BF_CS1(HDMI_TX_INVID0, VIDEO_MAPPING, v)
#endif

/* --- Register HW_HDMI_TX_INVID0, field INTERNAL_DE_GENERATOR (RW)
 *
 * Internal data enable (DE) generator enable. If data enable is not available for the input video
 * the user may set this bit to one to activate the internal data enable generator. This feature
 * only works for input video modes that have native repetition (such as, all CEA videos). No
 * desired pixel repetition can be used with this feature because these configurations only affect
 * the Frame Composer and not this block.
 */

#define BP_HDMI_TX_INVID0_INTERNAL_DE_GENERATOR      7
#define BM_HDMI_TX_INVID0_INTERNAL_DE_GENERATOR      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_INVID0_INTERNAL_DE_GENERATOR(v)   ((((reg32_t) v) << 7) & BM_HDMI_TX_INVID0_INTERNAL_DE_GENERATOR)
#else
#define BF_HDMI_TX_INVID0_INTERNAL_DE_GENERATOR(v)   (((v) << 7) & BM_HDMI_TX_INVID0_INTERNAL_DE_GENERATOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTERNAL_DE_GENERATOR field to a new value.
#define BW_HDMI_TX_INVID0_INTERNAL_DE_GENERATOR(v)   BF_CS1(HDMI_TX_INVID0, INTERNAL_DE_GENERATOR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_TX_INSTUFFING - Video Input Stuffing Enable Register (RW)
 *
 * This register enables the stuffing mechanism of the Video Sampler module in order to correctly
 * perform Color Space Conversion of the ITU.601 standard YCC video. In this case, when "de" is low,
 * the output video components gydata[15:0], rcrdata[15:0], and bcbdata[15:0] can be configured.
 * Address Offset: 0x0201  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GYDATA_STUFFING : 1; //!< 
        unsigned char RCRDATA_STUFFING : 1; //!< 
        unsigned char BCBDATA_STUFFING : 1; //!< 
        unsigned char RESERVED0 : 5; //!< Reserved
    } B;
} hw_hdmi_tx_instuffing_t;
#endif

/*
 * constants & macros for entire HDMI_TX_INSTUFFING register
 */
#define HW_HDMI_TX_INSTUFFING_ADDR      (REGS_HDMI_BASE + 0x201)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_TX_INSTUFFING           (*(volatile hw_hdmi_tx_instuffing_t *) HW_HDMI_TX_INSTUFFING_ADDR)
#define HW_HDMI_TX_INSTUFFING_RD()      (HW_HDMI_TX_INSTUFFING.U)
#define HW_HDMI_TX_INSTUFFING_WR(v)     (HW_HDMI_TX_INSTUFFING.U = (v))
#define HW_HDMI_TX_INSTUFFING_SET(v)    (HW_HDMI_TX_INSTUFFING_WR(HW_HDMI_TX_INSTUFFING_RD() |  (v)))
#define HW_HDMI_TX_INSTUFFING_CLR(v)    (HW_HDMI_TX_INSTUFFING_WR(HW_HDMI_TX_INSTUFFING_RD() & ~(v)))
#define HW_HDMI_TX_INSTUFFING_TOG(v)    (HW_HDMI_TX_INSTUFFING_WR(HW_HDMI_TX_INSTUFFING_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_TX_INSTUFFING bitfields
 */

/* --- Register HW_HDMI_TX_INSTUFFING, field GYDATA_STUFFING (RW)
 *

 *
 * Values:
 * 0 - when the dataen signal is low, the value in the gydata[15:0] output is the one sampled from the
 *     corresponding input data.
 * 1 - When the dataen signal is low, the value in the gydata[15:0] output is given by the values in
 *     TX_GYDTA0 and TX_GYDATA1 registers.
 */

#define BP_HDMI_TX_INSTUFFING_GYDATA_STUFFING      0
#define BM_HDMI_TX_INSTUFFING_GYDATA_STUFFING      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_INSTUFFING_GYDATA_STUFFING(v)   ((((reg32_t) v) << 0) & BM_HDMI_TX_INSTUFFING_GYDATA_STUFFING)
#else
#define BF_HDMI_TX_INSTUFFING_GYDATA_STUFFING(v)   (((v) << 0) & BM_HDMI_TX_INSTUFFING_GYDATA_STUFFING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GYDATA_STUFFING field to a new value.
#define BW_HDMI_TX_INSTUFFING_GYDATA_STUFFING(v)   BF_CS1(HDMI_TX_INSTUFFING, GYDATA_STUFFING, v)
#endif


/* --- Register HW_HDMI_TX_INSTUFFING, field RCRDATA_STUFFING (RW)
 *

 *
 * Values:
 * 0 - When the dataen signal is low, the value in the rcrdata[15:0] output is the one sampled from the
 *     corresponding input data.
 * 1 - When the dataen signal is low, the value in the rcrdata[15:0] output is given by the values in
 *     TX_RCRDTA0 and TX_RCRDATA1 registers.
 */

#define BP_HDMI_TX_INSTUFFING_RCRDATA_STUFFING      1
#define BM_HDMI_TX_INSTUFFING_RCRDATA_STUFFING      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_INSTUFFING_RCRDATA_STUFFING(v)   ((((reg32_t) v) << 1) & BM_HDMI_TX_INSTUFFING_RCRDATA_STUFFING)
#else
#define BF_HDMI_TX_INSTUFFING_RCRDATA_STUFFING(v)   (((v) << 1) & BM_HDMI_TX_INSTUFFING_RCRDATA_STUFFING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCRDATA_STUFFING field to a new value.
#define BW_HDMI_TX_INSTUFFING_RCRDATA_STUFFING(v)   BF_CS1(HDMI_TX_INSTUFFING, RCRDATA_STUFFING, v)
#endif


/* --- Register HW_HDMI_TX_INSTUFFING, field BCBDATA_STUFFING (RW)
 *

 *
 * Values:
 * 0 - When the dataen signal is low, the value in the bcbdata[15:0] output is the one sampled from the
 *     corresponding input data.
 * 1 - When the dataen signal is low, the value in the bcbdata[15:0] output is given by the values in
 *     register TX_BCBDTA0 and TX_BCBDATA1.
 */

#define BP_HDMI_TX_INSTUFFING_BCBDATA_STUFFING      2
#define BM_HDMI_TX_INSTUFFING_BCBDATA_STUFFING      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_INSTUFFING_BCBDATA_STUFFING(v)   ((((reg32_t) v) << 2) & BM_HDMI_TX_INSTUFFING_BCBDATA_STUFFING)
#else
#define BF_HDMI_TX_INSTUFFING_BCBDATA_STUFFING(v)   (((v) << 2) & BM_HDMI_TX_INSTUFFING_BCBDATA_STUFFING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCBDATA_STUFFING field to a new value.
#define BW_HDMI_TX_INSTUFFING_BCBDATA_STUFFING(v)   BF_CS1(HDMI_TX_INSTUFFING, BCBDATA_STUFFING, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_TX_GYDATA0 - Video Input GY Data Channel Stuffing Register 0 (RW)
 *
 * Address Offset: 0x0202  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GYDATA : 8; //!< gydata[7:0].This register defines the value of gydata[7:0] when TX_INSTUFFING[0] (gydata_stuffing) is set to 1b.
    } B;
} hw_hdmi_tx_gydata0_t;
#endif

/*
 * constants & macros for entire HDMI_TX_GYDATA0 register
 */
#define HW_HDMI_TX_GYDATA0_ADDR      (REGS_HDMI_BASE + 0x202)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_TX_GYDATA0           (*(volatile hw_hdmi_tx_gydata0_t *) HW_HDMI_TX_GYDATA0_ADDR)
#define HW_HDMI_TX_GYDATA0_RD()      (HW_HDMI_TX_GYDATA0.U)
#define HW_HDMI_TX_GYDATA0_WR(v)     (HW_HDMI_TX_GYDATA0.U = (v))
#define HW_HDMI_TX_GYDATA0_SET(v)    (HW_HDMI_TX_GYDATA0_WR(HW_HDMI_TX_GYDATA0_RD() |  (v)))
#define HW_HDMI_TX_GYDATA0_CLR(v)    (HW_HDMI_TX_GYDATA0_WR(HW_HDMI_TX_GYDATA0_RD() & ~(v)))
#define HW_HDMI_TX_GYDATA0_TOG(v)    (HW_HDMI_TX_GYDATA0_WR(HW_HDMI_TX_GYDATA0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_TX_GYDATA0 bitfields
 */

/* --- Register HW_HDMI_TX_GYDATA0, field GYDATA (RW)
 *
 * gydata[7:0].This register defines the value of gydata[7:0] when TX_INSTUFFING[0]
 * (gydata_stuffing) is set to 1b.
 */

#define BP_HDMI_TX_GYDATA0_GYDATA      0
#define BM_HDMI_TX_GYDATA0_GYDATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_GYDATA0_GYDATA(v)   ((((reg32_t) v) << 0) & BM_HDMI_TX_GYDATA0_GYDATA)
#else
#define BF_HDMI_TX_GYDATA0_GYDATA(v)   (((v) << 0) & BM_HDMI_TX_GYDATA0_GYDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GYDATA field to a new value.
#define BW_HDMI_TX_GYDATA0_GYDATA(v)   BF_CS1(HDMI_TX_GYDATA0, GYDATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_TX_GYDATA1 - Video Input GY Data Channel Stuffing Register 1 (RW)
 *
 * Address Offset: 0x0203  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GYDATA : 8; //!< gydata[15:8].This register defines the value of gydata[15:8] when TX_INSTUFFING[0] (gydata_stuffing) is set to 1b.
    } B;
} hw_hdmi_tx_gydata1_t;
#endif

/*
 * constants & macros for entire HDMI_TX_GYDATA1 register
 */
#define HW_HDMI_TX_GYDATA1_ADDR      (REGS_HDMI_BASE + 0x203)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_TX_GYDATA1           (*(volatile hw_hdmi_tx_gydata1_t *) HW_HDMI_TX_GYDATA1_ADDR)
#define HW_HDMI_TX_GYDATA1_RD()      (HW_HDMI_TX_GYDATA1.U)
#define HW_HDMI_TX_GYDATA1_WR(v)     (HW_HDMI_TX_GYDATA1.U = (v))
#define HW_HDMI_TX_GYDATA1_SET(v)    (HW_HDMI_TX_GYDATA1_WR(HW_HDMI_TX_GYDATA1_RD() |  (v)))
#define HW_HDMI_TX_GYDATA1_CLR(v)    (HW_HDMI_TX_GYDATA1_WR(HW_HDMI_TX_GYDATA1_RD() & ~(v)))
#define HW_HDMI_TX_GYDATA1_TOG(v)    (HW_HDMI_TX_GYDATA1_WR(HW_HDMI_TX_GYDATA1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_TX_GYDATA1 bitfields
 */

/* --- Register HW_HDMI_TX_GYDATA1, field GYDATA (RW)
 *
 * gydata[15:8].This register defines the value of gydata[15:8] when TX_INSTUFFING[0]
 * (gydata_stuffing) is set to 1b.
 */

#define BP_HDMI_TX_GYDATA1_GYDATA      0
#define BM_HDMI_TX_GYDATA1_GYDATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_GYDATA1_GYDATA(v)   ((((reg32_t) v) << 0) & BM_HDMI_TX_GYDATA1_GYDATA)
#else
#define BF_HDMI_TX_GYDATA1_GYDATA(v)   (((v) << 0) & BM_HDMI_TX_GYDATA1_GYDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GYDATA field to a new value.
#define BW_HDMI_TX_GYDATA1_GYDATA(v)   BF_CS1(HDMI_TX_GYDATA1, GYDATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_TX_RCRDATA0 - Video Input RCR Data Channel Stuffing Register 0 (RW)
 *
 * Address Offset: 0x0204  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RCRDATA : 8; //!< rcrdata[7:0]. This register defines the value of rcrydata[7:0] when TX_INSTUFFING[1] (rcrdata_stuffing) is set to 1b.
    } B;
} hw_hdmi_tx_rcrdata0_t;
#endif

/*
 * constants & macros for entire HDMI_TX_RCRDATA0 register
 */
#define HW_HDMI_TX_RCRDATA0_ADDR      (REGS_HDMI_BASE + 0x204)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_TX_RCRDATA0           (*(volatile hw_hdmi_tx_rcrdata0_t *) HW_HDMI_TX_RCRDATA0_ADDR)
#define HW_HDMI_TX_RCRDATA0_RD()      (HW_HDMI_TX_RCRDATA0.U)
#define HW_HDMI_TX_RCRDATA0_WR(v)     (HW_HDMI_TX_RCRDATA0.U = (v))
#define HW_HDMI_TX_RCRDATA0_SET(v)    (HW_HDMI_TX_RCRDATA0_WR(HW_HDMI_TX_RCRDATA0_RD() |  (v)))
#define HW_HDMI_TX_RCRDATA0_CLR(v)    (HW_HDMI_TX_RCRDATA0_WR(HW_HDMI_TX_RCRDATA0_RD() & ~(v)))
#define HW_HDMI_TX_RCRDATA0_TOG(v)    (HW_HDMI_TX_RCRDATA0_WR(HW_HDMI_TX_RCRDATA0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_TX_RCRDATA0 bitfields
 */

/* --- Register HW_HDMI_TX_RCRDATA0, field RCRDATA (RW)
 *
 * rcrdata[7:0]. This register defines the value of rcrydata[7:0] when TX_INSTUFFING[1]
 * (rcrdata_stuffing) is set to 1b.
 */

#define BP_HDMI_TX_RCRDATA0_RCRDATA      0
#define BM_HDMI_TX_RCRDATA0_RCRDATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_RCRDATA0_RCRDATA(v)   ((((reg32_t) v) << 0) & BM_HDMI_TX_RCRDATA0_RCRDATA)
#else
#define BF_HDMI_TX_RCRDATA0_RCRDATA(v)   (((v) << 0) & BM_HDMI_TX_RCRDATA0_RCRDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCRDATA field to a new value.
#define BW_HDMI_TX_RCRDATA0_RCRDATA(v)   BF_CS1(HDMI_TX_RCRDATA0, RCRDATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_TX_RCRDATA1 - Video Input RCR Data Channel Stuffing Register 1 (RW)
 *
 * Address Offset: 0x0205  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RCRDATA : 8; //!< rcrdata[15:8]. This register defines the value of rcrydata[15:8] when TX_INSTUFFING[1] (rcrdata_stuffing) is set to 1b.
    } B;
} hw_hdmi_tx_rcrdata1_t;
#endif

/*
 * constants & macros for entire HDMI_TX_RCRDATA1 register
 */
#define HW_HDMI_TX_RCRDATA1_ADDR      (REGS_HDMI_BASE + 0x205)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_TX_RCRDATA1           (*(volatile hw_hdmi_tx_rcrdata1_t *) HW_HDMI_TX_RCRDATA1_ADDR)
#define HW_HDMI_TX_RCRDATA1_RD()      (HW_HDMI_TX_RCRDATA1.U)
#define HW_HDMI_TX_RCRDATA1_WR(v)     (HW_HDMI_TX_RCRDATA1.U = (v))
#define HW_HDMI_TX_RCRDATA1_SET(v)    (HW_HDMI_TX_RCRDATA1_WR(HW_HDMI_TX_RCRDATA1_RD() |  (v)))
#define HW_HDMI_TX_RCRDATA1_CLR(v)    (HW_HDMI_TX_RCRDATA1_WR(HW_HDMI_TX_RCRDATA1_RD() & ~(v)))
#define HW_HDMI_TX_RCRDATA1_TOG(v)    (HW_HDMI_TX_RCRDATA1_WR(HW_HDMI_TX_RCRDATA1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_TX_RCRDATA1 bitfields
 */

/* --- Register HW_HDMI_TX_RCRDATA1, field RCRDATA (RW)
 *
 * rcrdata[15:8]. This register defines the value of rcrydata[15:8] when TX_INSTUFFING[1]
 * (rcrdata_stuffing) is set to 1b.
 */

#define BP_HDMI_TX_RCRDATA1_RCRDATA      0
#define BM_HDMI_TX_RCRDATA1_RCRDATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_RCRDATA1_RCRDATA(v)   ((((reg32_t) v) << 0) & BM_HDMI_TX_RCRDATA1_RCRDATA)
#else
#define BF_HDMI_TX_RCRDATA1_RCRDATA(v)   (((v) << 0) & BM_HDMI_TX_RCRDATA1_RCRDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCRDATA field to a new value.
#define BW_HDMI_TX_RCRDATA1_RCRDATA(v)   BF_CS1(HDMI_TX_RCRDATA1, RCRDATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_TX_BCBDATA0 - Video Input RCB Data Channel Stuffing Register 0 (RW)
 *
 * Address Offset: 0x0206  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BCBDATA : 8; //!< bcbdata[7:0]. This register defines the value of bcbdata[7:0] when TX_INSTUFFING[2] (bcbdata_stuffing) is set to 1b.
    } B;
} hw_hdmi_tx_bcbdata0_t;
#endif

/*
 * constants & macros for entire HDMI_TX_BCBDATA0 register
 */
#define HW_HDMI_TX_BCBDATA0_ADDR      (REGS_HDMI_BASE + 0x206)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_TX_BCBDATA0           (*(volatile hw_hdmi_tx_bcbdata0_t *) HW_HDMI_TX_BCBDATA0_ADDR)
#define HW_HDMI_TX_BCBDATA0_RD()      (HW_HDMI_TX_BCBDATA0.U)
#define HW_HDMI_TX_BCBDATA0_WR(v)     (HW_HDMI_TX_BCBDATA0.U = (v))
#define HW_HDMI_TX_BCBDATA0_SET(v)    (HW_HDMI_TX_BCBDATA0_WR(HW_HDMI_TX_BCBDATA0_RD() |  (v)))
#define HW_HDMI_TX_BCBDATA0_CLR(v)    (HW_HDMI_TX_BCBDATA0_WR(HW_HDMI_TX_BCBDATA0_RD() & ~(v)))
#define HW_HDMI_TX_BCBDATA0_TOG(v)    (HW_HDMI_TX_BCBDATA0_WR(HW_HDMI_TX_BCBDATA0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_TX_BCBDATA0 bitfields
 */

/* --- Register HW_HDMI_TX_BCBDATA0, field BCBDATA (RW)
 *
 * bcbdata[7:0]. This register defines the value of bcbdata[7:0] when TX_INSTUFFING[2]
 * (bcbdata_stuffing) is set to 1b.
 */

#define BP_HDMI_TX_BCBDATA0_BCBDATA      0
#define BM_HDMI_TX_BCBDATA0_BCBDATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_BCBDATA0_BCBDATA(v)   ((((reg32_t) v) << 0) & BM_HDMI_TX_BCBDATA0_BCBDATA)
#else
#define BF_HDMI_TX_BCBDATA0_BCBDATA(v)   (((v) << 0) & BM_HDMI_TX_BCBDATA0_BCBDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCBDATA field to a new value.
#define BW_HDMI_TX_BCBDATA0_BCBDATA(v)   BF_CS1(HDMI_TX_BCBDATA0, BCBDATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_TX_BCBDATA1 - Video Input RCB Data Channel Stuffing Register 1 (RW)
 *
 * Address Offset: 0x0207  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BCBDATA : 8; //!< bcbdata[15:8]. This register defines the value of bcbdata[15:8] when TX_INSTUFFING[2] (bcbdata_stuffing) is set to 1b.
    } B;
} hw_hdmi_tx_bcbdata1_t;
#endif

/*
 * constants & macros for entire HDMI_TX_BCBDATA1 register
 */
#define HW_HDMI_TX_BCBDATA1_ADDR      (REGS_HDMI_BASE + 0x207)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_TX_BCBDATA1           (*(volatile hw_hdmi_tx_bcbdata1_t *) HW_HDMI_TX_BCBDATA1_ADDR)
#define HW_HDMI_TX_BCBDATA1_RD()      (HW_HDMI_TX_BCBDATA1.U)
#define HW_HDMI_TX_BCBDATA1_WR(v)     (HW_HDMI_TX_BCBDATA1.U = (v))
#define HW_HDMI_TX_BCBDATA1_SET(v)    (HW_HDMI_TX_BCBDATA1_WR(HW_HDMI_TX_BCBDATA1_RD() |  (v)))
#define HW_HDMI_TX_BCBDATA1_CLR(v)    (HW_HDMI_TX_BCBDATA1_WR(HW_HDMI_TX_BCBDATA1_RD() & ~(v)))
#define HW_HDMI_TX_BCBDATA1_TOG(v)    (HW_HDMI_TX_BCBDATA1_WR(HW_HDMI_TX_BCBDATA1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_TX_BCBDATA1 bitfields
 */

/* --- Register HW_HDMI_TX_BCBDATA1, field BCBDATA (RW)
 *
 * bcbdata[15:8]. This register defines the value of bcbdata[15:8] when TX_INSTUFFING[2]
 * (bcbdata_stuffing) is set to 1b.
 */

#define BP_HDMI_TX_BCBDATA1_BCBDATA      0
#define BM_HDMI_TX_BCBDATA1_BCBDATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_TX_BCBDATA1_BCBDATA(v)   ((((reg32_t) v) << 0) & BM_HDMI_TX_BCBDATA1_BCBDATA)
#else
#define BF_HDMI_TX_BCBDATA1_BCBDATA(v)   (((v) << 0) & BM_HDMI_TX_BCBDATA1_BCBDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCBDATA field to a new value.
#define BW_HDMI_TX_BCBDATA1_BCBDATA(v)   BF_CS1(HDMI_TX_BCBDATA1, BCBDATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_STATUS - Video Packetizer Packing Phase Status Register (RO)
 *
 * Address Offset: 0x0800  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PACKING_PHASE : 4; //!< Read only register that holds the "packing phase" output by the Video packetizer block. For more information about "packing" video data, refer to the HDMI1.4a specification. The register is updated at tmds clock rate.
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_vp_status_t;
#endif

/*
 * constants & macros for entire HDMI_VP_STATUS register
 */
#define HW_HDMI_VP_STATUS_ADDR      (REGS_HDMI_BASE + 0x800)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_STATUS           (*(volatile hw_hdmi_vp_status_t *) HW_HDMI_VP_STATUS_ADDR)
#define HW_HDMI_VP_STATUS_RD()      (HW_HDMI_VP_STATUS.U)
#endif

/*
 * constants & macros for individual HDMI_VP_STATUS bitfields
 */

/* --- Register HW_HDMI_VP_STATUS, field PACKING_PHASE (RO)
 *
 * Read only register that holds the "packing phase" output by the Video packetizer block. For more
 * information about "packing" video data, refer to the HDMI1.4a specification. The register is
 * updated at tmds clock rate.
 */

#define BP_HDMI_VP_STATUS_PACKING_PHASE      0
#define BM_HDMI_VP_STATUS_PACKING_PHASE      0x0000000f

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_PR_CD - Video Packetizer Pixel Repetition and Color Depth Register (RW)
 *
 * This register configures the Color Depth of the input video and Pixel repetition to apply to
 * video.   Address Offset: 0x0801  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DESIRED_PR_FACTOR : 4; //!< Desired pixel repetition factor configuration. The configured value sets H13T PHY PLL to multiply pixel clock by the factor in order to obtain the desired repetition clock. For the CEA modes some are already defined with pixel repetition in the input video. So for CEA modes this shall be always 0. Shall only be used if the user wants to do pixel repetition using H13TCTRL core. other Reserved. Not used.
        unsigned char COLOR_DEPTH : 4; //!< Color depth configuration: other Reserved. Not used.
    } B;
} hw_hdmi_vp_pr_cd_t;
#endif

/*
 * constants & macros for entire HDMI_VP_PR_CD register
 */
#define HW_HDMI_VP_PR_CD_ADDR      (REGS_HDMI_BASE + 0x801)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_PR_CD           (*(volatile hw_hdmi_vp_pr_cd_t *) HW_HDMI_VP_PR_CD_ADDR)
#define HW_HDMI_VP_PR_CD_RD()      (HW_HDMI_VP_PR_CD.U)
#define HW_HDMI_VP_PR_CD_WR(v)     (HW_HDMI_VP_PR_CD.U = (v))
#define HW_HDMI_VP_PR_CD_SET(v)    (HW_HDMI_VP_PR_CD_WR(HW_HDMI_VP_PR_CD_RD() |  (v)))
#define HW_HDMI_VP_PR_CD_CLR(v)    (HW_HDMI_VP_PR_CD_WR(HW_HDMI_VP_PR_CD_RD() & ~(v)))
#define HW_HDMI_VP_PR_CD_TOG(v)    (HW_HDMI_VP_PR_CD_WR(HW_HDMI_VP_PR_CD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_VP_PR_CD bitfields
 */

/* --- Register HW_HDMI_VP_PR_CD, field DESIRED_PR_FACTOR (RW)
 *
 * Desired pixel repetition factor configuration. The configured value sets H13T PHY PLL to multiply
 * pixel clock by the factor in order to obtain the desired repetition clock. For the CEA modes some
 * are already defined with pixel repetition in the input video. So for CEA modes this shall be
 * always 0. Shall only be used if the user wants to do pixel repetition using H13TCTRL core. other
 * Reserved. Not used.
 *
 * Values:
 * 0000 - No pixel repetition (pixel sent only once)
 * 0001 - Pixel sent 2 times (pixel repeated once)
 * 0010 - Pixel sent 3 times
 * 0011 - Pixel sent 4 times
 * 0100 - Pixel sent 5 times
 * 0101 - Pixel sent 6 times
 * 0110 - Pixel sent 7 times
 * 0111 - Pixel sent 8 times
 * 1000 - Pixel sent 9 times
 * 1001 - Pixel sent 10 times
 */

#define BP_HDMI_VP_PR_CD_DESIRED_PR_FACTOR      0
#define BM_HDMI_VP_PR_CD_DESIRED_PR_FACTOR      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_PR_CD_DESIRED_PR_FACTOR(v)   ((((reg32_t) v) << 0) & BM_HDMI_VP_PR_CD_DESIRED_PR_FACTOR)
#else
#define BF_HDMI_VP_PR_CD_DESIRED_PR_FACTOR(v)   (((v) << 0) & BM_HDMI_VP_PR_CD_DESIRED_PR_FACTOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DESIRED_PR_FACTOR field to a new value.
#define BW_HDMI_VP_PR_CD_DESIRED_PR_FACTOR(v)   BF_CS1(HDMI_VP_PR_CD, DESIRED_PR_FACTOR, v)
#endif


/* --- Register HW_HDMI_VP_PR_CD, field COLOR_DEPTH (RW)
 *
 * Color depth configuration: other Reserved. Not used.
 *
 * Values:
 * 0000 - 24 bits per pixel video (8 bit per component). 8-bit packing mode.
 * 0100 - 24 bits per pixel video (8 bit per component). 8-bit packing mode.
 * 0101 - 30 bits per pixel video (10 bit per component). 10-bit packing mode.
 * 0110 - 36 bits per pixel video (12 bit per component). 12-bit packing mode.
 * 0111 - 48 bits per pixel video (16 bit per component). 16-bit packing mode.
 */

#define BP_HDMI_VP_PR_CD_COLOR_DEPTH      4
#define BM_HDMI_VP_PR_CD_COLOR_DEPTH      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_PR_CD_COLOR_DEPTH(v)   ((((reg32_t) v) << 4) & BM_HDMI_VP_PR_CD_COLOR_DEPTH)
#else
#define BF_HDMI_VP_PR_CD_COLOR_DEPTH(v)   (((v) << 4) & BM_HDMI_VP_PR_CD_COLOR_DEPTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the COLOR_DEPTH field to a new value.
#define BW_HDMI_VP_PR_CD_COLOR_DEPTH(v)   BF_CS1(HDMI_VP_PR_CD, COLOR_DEPTH, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_STUFF - Video Packetizer Stuffing and Default Packing Phase Register (RW)
 *
 * This register controls the Pixel repetition, pixel packing and YCC422 stuffing.   Address Offset:
 * 0x0802  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PR_STUFFING : 1; //!< Pixel repeater stuffing control
        unsigned char PP_STUFFING : 1; //!< Pixel packing stuffing control
        unsigned char YCC422_STUFFING : 1; //!< YCC 422 remap stuffing control. For horizontal blanking:
        unsigned char ICX_GOTO_P0_ST : 1; //!< Reserved. Controls packing machine strategy.
        unsigned char IFIX_PP_TO_LAST : 1; //!< Reserved. Controls packing machine strategy.
        unsigned char IDEFAULT_PHASE : 1; //!< Controls the default phase packing machine used according to: "If the transmitted video format has timing such that the phase of the first pixel of every Video Data Period corresponds to pixel packing phase 0 (for example, 10P0, 12P0, 16P0), the Source may set the Default_Phase bit in the GCP. The Sink may use this bit to optimize it's filtering or handling of the PP field." (HDMI specification version 1.4a) This means that for10 bit mode the Htotal must be dividable by 4 and for 12 bit mode the Htotal must be dividable by 2.
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_vp_stuff_t;
#endif

/*
 * constants & macros for entire HDMI_VP_STUFF register
 */
#define HW_HDMI_VP_STUFF_ADDR      (REGS_HDMI_BASE + 0x802)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_STUFF           (*(volatile hw_hdmi_vp_stuff_t *) HW_HDMI_VP_STUFF_ADDR)
#define HW_HDMI_VP_STUFF_RD()      (HW_HDMI_VP_STUFF.U)
#define HW_HDMI_VP_STUFF_WR(v)     (HW_HDMI_VP_STUFF.U = (v))
#define HW_HDMI_VP_STUFF_SET(v)    (HW_HDMI_VP_STUFF_WR(HW_HDMI_VP_STUFF_RD() |  (v)))
#define HW_HDMI_VP_STUFF_CLR(v)    (HW_HDMI_VP_STUFF_WR(HW_HDMI_VP_STUFF_RD() & ~(v)))
#define HW_HDMI_VP_STUFF_TOG(v)    (HW_HDMI_VP_STUFF_WR(HW_HDMI_VP_STUFF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_VP_STUFF bitfields
 */

/* --- Register HW_HDMI_VP_STUFF, field PR_STUFFING (RW)
 *
 * Pixel repeater stuffing control
 *
 * Values:
 * 0 - Pixel repeater block in direct mode (input blanking data goes directly to output).
 * 1 - Pixel repeater block in stuffing mode. When "de" goes to low the outputs are fixed to 0x00.
 */

#define BP_HDMI_VP_STUFF_PR_STUFFING      0
#define BM_HDMI_VP_STUFF_PR_STUFFING      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_STUFF_PR_STUFFING(v)   ((((reg32_t) v) << 0) & BM_HDMI_VP_STUFF_PR_STUFFING)
#else
#define BF_HDMI_VP_STUFF_PR_STUFFING(v)   (((v) << 0) & BM_HDMI_VP_STUFF_PR_STUFFING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PR_STUFFING field to a new value.
#define BW_HDMI_VP_STUFF_PR_STUFFING(v)   BF_CS1(HDMI_VP_STUFF, PR_STUFFING, v)
#endif


/* --- Register HW_HDMI_VP_STUFF, field PP_STUFFING (RW)
 *
 * Pixel packing stuffing control
 *
 * Values:
 * 0 - Pixel packing block in direct mode (input blanking data goes directly to output).
 * 1 - Pixel packing block in stuffing mode. When "de_rep" goes to low the outputs are fixed to 0x00.
 */

#define BP_HDMI_VP_STUFF_PP_STUFFING      1
#define BM_HDMI_VP_STUFF_PP_STUFFING      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_STUFF_PP_STUFFING(v)   ((((reg32_t) v) << 1) & BM_HDMI_VP_STUFF_PP_STUFFING)
#else
#define BF_HDMI_VP_STUFF_PP_STUFFING(v)   (((v) << 1) & BM_HDMI_VP_STUFF_PP_STUFFING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PP_STUFFING field to a new value.
#define BW_HDMI_VP_STUFF_PP_STUFFING(v)   BF_CS1(HDMI_VP_STUFF, PP_STUFFING, v)
#endif


/* --- Register HW_HDMI_VP_STUFF, field YCC422_STUFFING (RW)
 *
 * YCC 422 remap stuffing control. For horizontal blanking:
 *
 * Values:
 * 0 - YCC 422 remap block in direct mode (input blanking data goes directly to output).
 * 1 - YCC 422 remap block in stuffing mode. When "de" goes to low the outputs are fixed to 0x00.
 */

#define BP_HDMI_VP_STUFF_YCC422_STUFFING      2
#define BM_HDMI_VP_STUFF_YCC422_STUFFING      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_STUFF_YCC422_STUFFING(v)   ((((reg32_t) v) << 2) & BM_HDMI_VP_STUFF_YCC422_STUFFING)
#else
#define BF_HDMI_VP_STUFF_YCC422_STUFFING(v)   (((v) << 2) & BM_HDMI_VP_STUFF_YCC422_STUFFING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the YCC422_STUFFING field to a new value.
#define BW_HDMI_VP_STUFF_YCC422_STUFFING(v)   BF_CS1(HDMI_VP_STUFF, YCC422_STUFFING, v)
#endif


/* --- Register HW_HDMI_VP_STUFF, field ICX_GOTO_P0_ST (RW)
 *
 * Reserved. Controls packing machine strategy.
 */

#define BP_HDMI_VP_STUFF_ICX_GOTO_P0_ST      3
#define BM_HDMI_VP_STUFF_ICX_GOTO_P0_ST      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_STUFF_ICX_GOTO_P0_ST(v)   ((((reg32_t) v) << 3) & BM_HDMI_VP_STUFF_ICX_GOTO_P0_ST)
#else
#define BF_HDMI_VP_STUFF_ICX_GOTO_P0_ST(v)   (((v) << 3) & BM_HDMI_VP_STUFF_ICX_GOTO_P0_ST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICX_GOTO_P0_ST field to a new value.
#define BW_HDMI_VP_STUFF_ICX_GOTO_P0_ST(v)   BF_CS1(HDMI_VP_STUFF, ICX_GOTO_P0_ST, v)
#endif

/* --- Register HW_HDMI_VP_STUFF, field IFIX_PP_TO_LAST (RW)
 *
 * Reserved. Controls packing machine strategy.
 */

#define BP_HDMI_VP_STUFF_IFIX_PP_TO_LAST      4
#define BM_HDMI_VP_STUFF_IFIX_PP_TO_LAST      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_STUFF_IFIX_PP_TO_LAST(v)   ((((reg32_t) v) << 4) & BM_HDMI_VP_STUFF_IFIX_PP_TO_LAST)
#else
#define BF_HDMI_VP_STUFF_IFIX_PP_TO_LAST(v)   (((v) << 4) & BM_HDMI_VP_STUFF_IFIX_PP_TO_LAST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IFIX_PP_TO_LAST field to a new value.
#define BW_HDMI_VP_STUFF_IFIX_PP_TO_LAST(v)   BF_CS1(HDMI_VP_STUFF, IFIX_PP_TO_LAST, v)
#endif

/* --- Register HW_HDMI_VP_STUFF, field IDEFAULT_PHASE (RW)
 *
 * Controls the default phase packing machine used according to: "If the transmitted video format
 * has timing such that the phase of the first pixel of every Video Data Period corresponds to pixel
 * packing phase 0 (for example, 10P0, 12P0, 16P0), the Source may set the Default_Phase bit in the
 * GCP. The Sink may use this bit to optimize it's filtering or handling of the PP field." (HDMI
 * specification version 1.4a) This means that for10 bit mode the Htotal must be dividable by 4 and
 * for 12 bit mode the Htotal must be dividable by 2.
 */

#define BP_HDMI_VP_STUFF_IDEFAULT_PHASE      5
#define BM_HDMI_VP_STUFF_IDEFAULT_PHASE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_STUFF_IDEFAULT_PHASE(v)   ((((reg32_t) v) << 5) & BM_HDMI_VP_STUFF_IDEFAULT_PHASE)
#else
#define BF_HDMI_VP_STUFF_IDEFAULT_PHASE(v)   (((v) << 5) & BM_HDMI_VP_STUFF_IDEFAULT_PHASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IDEFAULT_PHASE field to a new value.
#define BW_HDMI_VP_STUFF_IDEFAULT_PHASE(v)   BF_CS1(HDMI_VP_STUFF, IDEFAULT_PHASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_REMAP - Video Packetizer YCC422 Remapping Register (RW)
 *
 * This register controls YCC422 remap of the Video Packetizer. For more information about YCC422
 * remap refer to HDMI 1.4a specification.   Address Offset: 0x0803  Size: 8 bits  Value after
 * Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char YCC422_SIZE : 2; //!< YCC 422 remap input video size:
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_vp_remap_t;
#endif

/*
 * constants & macros for entire HDMI_VP_REMAP register
 */
#define HW_HDMI_VP_REMAP_ADDR      (REGS_HDMI_BASE + 0x803)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_REMAP           (*(volatile hw_hdmi_vp_remap_t *) HW_HDMI_VP_REMAP_ADDR)
#define HW_HDMI_VP_REMAP_RD()      (HW_HDMI_VP_REMAP.U)
#define HW_HDMI_VP_REMAP_WR(v)     (HW_HDMI_VP_REMAP.U = (v))
#define HW_HDMI_VP_REMAP_SET(v)    (HW_HDMI_VP_REMAP_WR(HW_HDMI_VP_REMAP_RD() |  (v)))
#define HW_HDMI_VP_REMAP_CLR(v)    (HW_HDMI_VP_REMAP_WR(HW_HDMI_VP_REMAP_RD() & ~(v)))
#define HW_HDMI_VP_REMAP_TOG(v)    (HW_HDMI_VP_REMAP_WR(HW_HDMI_VP_REMAP_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_VP_REMAP bitfields
 */

/* --- Register HW_HDMI_VP_REMAP, field YCC422_SIZE (RW)
 *
 * YCC 422 remap input video size:
 *
 * Values:
 * 00 - YCC 422 16-bit input video (8 bits per component).
 * 01 - YCC 422 20-bit input video (10 bits per component).
 * 10 - YCC 422 24-bit input video (12 bits per component).
 * 11 - Reserved. Not used.
 */

#define BP_HDMI_VP_REMAP_YCC422_SIZE      0
#define BM_HDMI_VP_REMAP_YCC422_SIZE      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_REMAP_YCC422_SIZE(v)   ((((reg32_t) v) << 0) & BM_HDMI_VP_REMAP_YCC422_SIZE)
#else
#define BF_HDMI_VP_REMAP_YCC422_SIZE(v)   (((v) << 0) & BM_HDMI_VP_REMAP_YCC422_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the YCC422_SIZE field to a new value.
#define BW_HDMI_VP_REMAP_YCC422_SIZE(v)   BF_CS1(HDMI_VP_REMAP, YCC422_SIZE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_CONF - Video Packetizer Output, Bypass, and Enable Configuration Register (RW)
 *
 * This register controls the Video Packetizer output selection, bypass select, YCC422 enable, Pixel
 * repeater, and pixel packing enabling.   Address Offset: 0x0804  Size: 8 bits  Value after Reset:
 * 0x46  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char OUTPUT_SELECTOR : 2; //!< Video packetizer output selection.
        unsigned char BYPASS_SELECT : 1; //!< 
        unsigned char YCC422_EN : 1; //!< YCC 422 select enable. Disabling forces bypass module to output always zeros.
        unsigned char PR_EN : 1; //!< Pixel repeater enable. Disabling forces bypass module to output always zeros.
        unsigned char PP_EN : 1; //!< Pixel packing enable. Disabling forces bypass module to output always zeros.
        unsigned char BYPASS_EN : 1; //!< Bypass enable. Disabling forces bypass module to output always zeros.
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_vp_conf_t;
#endif

/*
 * constants & macros for entire HDMI_VP_CONF register
 */
#define HW_HDMI_VP_CONF_ADDR      (REGS_HDMI_BASE + 0x804)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_CONF           (*(volatile hw_hdmi_vp_conf_t *) HW_HDMI_VP_CONF_ADDR)
#define HW_HDMI_VP_CONF_RD()      (HW_HDMI_VP_CONF.U)
#define HW_HDMI_VP_CONF_WR(v)     (HW_HDMI_VP_CONF.U = (v))
#define HW_HDMI_VP_CONF_SET(v)    (HW_HDMI_VP_CONF_WR(HW_HDMI_VP_CONF_RD() |  (v)))
#define HW_HDMI_VP_CONF_CLR(v)    (HW_HDMI_VP_CONF_WR(HW_HDMI_VP_CONF_RD() & ~(v)))
#define HW_HDMI_VP_CONF_TOG(v)    (HW_HDMI_VP_CONF_WR(HW_HDMI_VP_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_VP_CONF bitfields
 */

/* --- Register HW_HDMI_VP_CONF, field OUTPUT_SELECTOR (RW)
 *
 * Video packetizer output selection.
 *
 * Values:
 * 00 - Data from pixel packing block.
 * 01 - Data from YCC 422 remap block.
 * 10 - Data from 8-bit bypass block.
 * 11 - Data from 8-bit bypass block.
 */

#define BP_HDMI_VP_CONF_OUTPUT_SELECTOR      0
#define BM_HDMI_VP_CONF_OUTPUT_SELECTOR      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_CONF_OUTPUT_SELECTOR(v)   ((((reg32_t) v) << 0) & BM_HDMI_VP_CONF_OUTPUT_SELECTOR)
#else
#define BF_HDMI_VP_CONF_OUTPUT_SELECTOR(v)   (((v) << 0) & BM_HDMI_VP_CONF_OUTPUT_SELECTOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTPUT_SELECTOR field to a new value.
#define BW_HDMI_VP_CONF_OUTPUT_SELECTOR(v)   BF_CS1(HDMI_VP_CONF, OUTPUT_SELECTOR, v)
#endif


/* --- Register HW_HDMI_VP_CONF, field BYPASS_SELECT (RW)
 *

 *
 * Values:
 * 0 - Data from pixel repeater block.
 * 1 - Data from input of video packetizer block.
 */

#define BP_HDMI_VP_CONF_BYPASS_SELECT      2
#define BM_HDMI_VP_CONF_BYPASS_SELECT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_CONF_BYPASS_SELECT(v)   ((((reg32_t) v) << 2) & BM_HDMI_VP_CONF_BYPASS_SELECT)
#else
#define BF_HDMI_VP_CONF_BYPASS_SELECT(v)   (((v) << 2) & BM_HDMI_VP_CONF_BYPASS_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_SELECT field to a new value.
#define BW_HDMI_VP_CONF_BYPASS_SELECT(v)   BF_CS1(HDMI_VP_CONF, BYPASS_SELECT, v)
#endif


/* --- Register HW_HDMI_VP_CONF, field YCC422_EN (RW)
 *
 * YCC 422 select enable. Disabling forces bypass module to output always zeros.
 */

#define BP_HDMI_VP_CONF_YCC422_EN      3
#define BM_HDMI_VP_CONF_YCC422_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_CONF_YCC422_EN(v)   ((((reg32_t) v) << 3) & BM_HDMI_VP_CONF_YCC422_EN)
#else
#define BF_HDMI_VP_CONF_YCC422_EN(v)   (((v) << 3) & BM_HDMI_VP_CONF_YCC422_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the YCC422_EN field to a new value.
#define BW_HDMI_VP_CONF_YCC422_EN(v)   BF_CS1(HDMI_VP_CONF, YCC422_EN, v)
#endif

/* --- Register HW_HDMI_VP_CONF, field PR_EN (RW)
 *
 * Pixel repeater enable. Disabling forces bypass module to output always zeros.
 */

#define BP_HDMI_VP_CONF_PR_EN      4
#define BM_HDMI_VP_CONF_PR_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_CONF_PR_EN(v)   ((((reg32_t) v) << 4) & BM_HDMI_VP_CONF_PR_EN)
#else
#define BF_HDMI_VP_CONF_PR_EN(v)   (((v) << 4) & BM_HDMI_VP_CONF_PR_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PR_EN field to a new value.
#define BW_HDMI_VP_CONF_PR_EN(v)   BF_CS1(HDMI_VP_CONF, PR_EN, v)
#endif

/* --- Register HW_HDMI_VP_CONF, field PP_EN (RW)
 *
 * Pixel packing enable. Disabling forces bypass module to output always zeros.
 */

#define BP_HDMI_VP_CONF_PP_EN      5
#define BM_HDMI_VP_CONF_PP_EN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_CONF_PP_EN(v)   ((((reg32_t) v) << 5) & BM_HDMI_VP_CONF_PP_EN)
#else
#define BF_HDMI_VP_CONF_PP_EN(v)   (((v) << 5) & BM_HDMI_VP_CONF_PP_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PP_EN field to a new value.
#define BW_HDMI_VP_CONF_PP_EN(v)   BF_CS1(HDMI_VP_CONF, PP_EN, v)
#endif

/* --- Register HW_HDMI_VP_CONF, field BYPASS_EN (RW)
 *
 * Bypass enable. Disabling forces bypass module to output always zeros.
 */

#define BP_HDMI_VP_CONF_BYPASS_EN      6
#define BM_HDMI_VP_CONF_BYPASS_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_CONF_BYPASS_EN(v)   ((((reg32_t) v) << 6) & BM_HDMI_VP_CONF_BYPASS_EN)
#else
#define BF_HDMI_VP_CONF_BYPASS_EN(v)   (((v) << 6) & BM_HDMI_VP_CONF_BYPASS_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_EN field to a new value.
#define BW_HDMI_VP_CONF_BYPASS_EN(v)   BF_CS1(HDMI_VP_CONF, BYPASS_EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_STAT - VP_STAT (RO)
 *
 * This register contains the following active high FIFO status indications:   Address Offset:
 * 0x0805  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char OSTEMPTYBYP : 1; //!< Video packetizer 8-bit bypass FIFO empty status.
        unsigned char OSTFULLBYP : 1; //!< Video packetizer 8-bit bypass FIFO full status.
        unsigned char OSTEMPTYREMAP : 1; //!< Video packetizer pixel YCC 422 re-mapper FIFO empty status.
        unsigned char OSTFULLREMAP : 1; //!< Video packetizer pixel YCC 422 re-mapper FIFO full status.
        unsigned char OSTEMPTYPP : 1; //!< Video packetizer pixel packing FIFO empty status.
        unsigned char OSTFULLPP : 1; //!< Video packetizer pixel packing FIFO full status.
        unsigned char OSTEMPTYREPET : 1; //!< Video packetizer pixel repeater FIFO empty status.
        unsigned char OSTFULLREPET : 1; //!< Video packetizer pixel repeater FIFO full status.
    } B;
} hw_hdmi_vp_stat_t;
#endif

/*
 * constants & macros for entire HDMI_VP_STAT register
 */
#define HW_HDMI_VP_STAT_ADDR      (REGS_HDMI_BASE + 0x805)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_STAT           (*(volatile hw_hdmi_vp_stat_t *) HW_HDMI_VP_STAT_ADDR)
#define HW_HDMI_VP_STAT_RD()      (HW_HDMI_VP_STAT.U)
#endif

/*
 * constants & macros for individual HDMI_VP_STAT bitfields
 */

/* --- Register HW_HDMI_VP_STAT, field OSTEMPTYBYP (RO)
 *
 * Video packetizer 8-bit bypass FIFO empty status.
 */

#define BP_HDMI_VP_STAT_OSTEMPTYBYP      0
#define BM_HDMI_VP_STAT_OSTEMPTYBYP      0x00000001

/* --- Register HW_HDMI_VP_STAT, field OSTFULLBYP (RO)
 *
 * Video packetizer 8-bit bypass FIFO full status.
 */

#define BP_HDMI_VP_STAT_OSTFULLBYP      1
#define BM_HDMI_VP_STAT_OSTFULLBYP      0x00000002

/* --- Register HW_HDMI_VP_STAT, field OSTEMPTYREMAP (RO)
 *
 * Video packetizer pixel YCC 422 re-mapper FIFO empty status.
 */

#define BP_HDMI_VP_STAT_OSTEMPTYREMAP      2
#define BM_HDMI_VP_STAT_OSTEMPTYREMAP      0x00000004

/* --- Register HW_HDMI_VP_STAT, field OSTFULLREMAP (RO)
 *
 * Video packetizer pixel YCC 422 re-mapper FIFO full status.
 */

#define BP_HDMI_VP_STAT_OSTFULLREMAP      3
#define BM_HDMI_VP_STAT_OSTFULLREMAP      0x00000008

/* --- Register HW_HDMI_VP_STAT, field OSTEMPTYPP (RO)
 *
 * Video packetizer pixel packing FIFO empty status.
 */

#define BP_HDMI_VP_STAT_OSTEMPTYPP      4
#define BM_HDMI_VP_STAT_OSTEMPTYPP      0x00000010

/* --- Register HW_HDMI_VP_STAT, field OSTFULLPP (RO)
 *
 * Video packetizer pixel packing FIFO full status.
 */

#define BP_HDMI_VP_STAT_OSTFULLPP      5
#define BM_HDMI_VP_STAT_OSTFULLPP      0x00000020

/* --- Register HW_HDMI_VP_STAT, field OSTEMPTYREPET (RO)
 *
 * Video packetizer pixel repeater FIFO empty status.
 */

#define BP_HDMI_VP_STAT_OSTEMPTYREPET      6
#define BM_HDMI_VP_STAT_OSTEMPTYREPET      0x00000040

/* --- Register HW_HDMI_VP_STAT, field OSTFULLREPET (RO)
 *
 * Video packetizer pixel repeater FIFO full status.
 */

#define BP_HDMI_VP_STAT_OSTFULLREPET      7
#define BM_HDMI_VP_STAT_OSTFULLREPET      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_INT - VP_INT (RO)
 *
 * This register contains the interrupt indication of the VP_STAT status interrupts. Interrupt
 * generation is accomplished in the following way:  interrupt = (mask == 1'b0) && (polarity ==
 * status);  All this interrupts are forwarded to the Interrupt Handler sticky bit registers and
 * after ORed to a single main interrupt line to micro controller. Assertion of this interrupt
 * implies that data related with the corresponding packet has been sent through the HDMI interface.
 * Address Offset: 0x0806  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char OINTEMPTYBYP : 1; //!< Video packetizer 8-bit bypass FIFO empty status.
        unsigned char OINTFULLBYP : 1; //!< Video packetizer 8-bit bypass FIFO full status.
        unsigned char OINTEMPTYREMAP : 1; //!< Video packetizer pixel YCC 422 re-mapper FIFO empty status.
        unsigned char OINTFULLREMAP : 1; //!< Video packetizer pixel YCC 422 re-mapper FIFO full status.
        unsigned char OINTEMPTYPP : 1; //!< Video packetizer pixel packing FIFO empty status
        unsigned char OINTFULLPP : 1; //!< Video packetizer pixel packing FIFO full status
        unsigned char OINTEMPTYREPET : 1; //!< Video packetizer pixel repeater FIFO empty status
        unsigned char OINTFULLREPET : 1; //!< Video packetizer pixel repeater FIFO full status
    } B;
} hw_hdmi_vp_int_t;
#endif

/*
 * constants & macros for entire HDMI_VP_INT register
 */
#define HW_HDMI_VP_INT_ADDR      (REGS_HDMI_BASE + 0x806)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_INT           (*(volatile hw_hdmi_vp_int_t *) HW_HDMI_VP_INT_ADDR)
#define HW_HDMI_VP_INT_RD()      (HW_HDMI_VP_INT.U)
#endif

/*
 * constants & macros for individual HDMI_VP_INT bitfields
 */

/* --- Register HW_HDMI_VP_INT, field OINTEMPTYBYP (RO)
 *
 * Video packetizer 8-bit bypass FIFO empty status.
 */

#define BP_HDMI_VP_INT_OINTEMPTYBYP      0
#define BM_HDMI_VP_INT_OINTEMPTYBYP      0x00000001

/* --- Register HW_HDMI_VP_INT, field OINTFULLBYP (RO)
 *
 * Video packetizer 8-bit bypass FIFO full status.
 */

#define BP_HDMI_VP_INT_OINTFULLBYP      1
#define BM_HDMI_VP_INT_OINTFULLBYP      0x00000002

/* --- Register HW_HDMI_VP_INT, field OINTEMPTYREMAP (RO)
 *
 * Video packetizer pixel YCC 422 re-mapper FIFO empty status.
 */

#define BP_HDMI_VP_INT_OINTEMPTYREMAP      2
#define BM_HDMI_VP_INT_OINTEMPTYREMAP      0x00000004

/* --- Register HW_HDMI_VP_INT, field OINTFULLREMAP (RO)
 *
 * Video packetizer pixel YCC 422 re-mapper FIFO full status.
 */

#define BP_HDMI_VP_INT_OINTFULLREMAP      3
#define BM_HDMI_VP_INT_OINTFULLREMAP      0x00000008

/* --- Register HW_HDMI_VP_INT, field OINTEMPTYPP (RO)
 *
 * Video packetizer pixel packing FIFO empty status
 */

#define BP_HDMI_VP_INT_OINTEMPTYPP      4
#define BM_HDMI_VP_INT_OINTEMPTYPP      0x00000010

/* --- Register HW_HDMI_VP_INT, field OINTFULLPP (RO)
 *
 * Video packetizer pixel packing FIFO full status
 */

#define BP_HDMI_VP_INT_OINTFULLPP      5
#define BM_HDMI_VP_INT_OINTFULLPP      0x00000020

/* --- Register HW_HDMI_VP_INT, field OINTEMPTYREPET (RO)
 *
 * Video packetizer pixel repeater FIFO empty status
 */

#define BP_HDMI_VP_INT_OINTEMPTYREPET      6
#define BM_HDMI_VP_INT_OINTEMPTYREPET      0x00000040

/* --- Register HW_HDMI_VP_INT, field OINTFULLREPET (RO)
 *
 * Video packetizer pixel repeater FIFO full status
 */

#define BP_HDMI_VP_INT_OINTFULLREPET      7
#define BM_HDMI_VP_INT_OINTFULLREPET      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_MASK - Video Packetizer Interrupt Mask Register (RW)
 *
 * Mask register for generation of VP_INT interrupts.   Address Offset: 0x0807  Size: 8 bits  Value
 * after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char VPMASK : 1; //!< Mask bit for VP_INT[0] interrupt bit.
        unsigned char VPMASK1 : 1; //!< Mask bit for VP_INT[1] interrupt bit.
        unsigned char VPMASK2 : 1; //!< Mask bit for VP_INT[2] interrupt bit.
        unsigned char VPMASK3 : 1; //!< Mask bit for VP_INT[3] interrupt bit.
        unsigned char VPMASK4 : 1; //!< Mask bit for VP_INT[4] interrupt bit.
        unsigned char VPMASK5 : 1; //!< Mask bit for VP_INT[5] interrupt bit.
        unsigned char VPMASK6 : 1; //!< Mask bit for VP_INT[6] interrupt bit.
        unsigned char VPMASK7 : 1; //!< Mask bit for VP_INT[7] interrupt bit.
    } B;
} hw_hdmi_vp_mask_t;
#endif

/*
 * constants & macros for entire HDMI_VP_MASK register
 */
#define HW_HDMI_VP_MASK_ADDR      (REGS_HDMI_BASE + 0x807)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_MASK           (*(volatile hw_hdmi_vp_mask_t *) HW_HDMI_VP_MASK_ADDR)
#define HW_HDMI_VP_MASK_RD()      (HW_HDMI_VP_MASK.U)
#define HW_HDMI_VP_MASK_WR(v)     (HW_HDMI_VP_MASK.U = (v))
#define HW_HDMI_VP_MASK_SET(v)    (HW_HDMI_VP_MASK_WR(HW_HDMI_VP_MASK_RD() |  (v)))
#define HW_HDMI_VP_MASK_CLR(v)    (HW_HDMI_VP_MASK_WR(HW_HDMI_VP_MASK_RD() & ~(v)))
#define HW_HDMI_VP_MASK_TOG(v)    (HW_HDMI_VP_MASK_WR(HW_HDMI_VP_MASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_VP_MASK bitfields
 */

/* --- Register HW_HDMI_VP_MASK, field VPMASK (RW)
 *
 * Mask bit for VP_INT[0] interrupt bit.
 */

#define BP_HDMI_VP_MASK_VPMASK      0
#define BM_HDMI_VP_MASK_VPMASK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_MASK_VPMASK(v)   ((((reg32_t) v) << 0) & BM_HDMI_VP_MASK_VPMASK)
#else
#define BF_HDMI_VP_MASK_VPMASK(v)   (((v) << 0) & BM_HDMI_VP_MASK_VPMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPMASK field to a new value.
#define BW_HDMI_VP_MASK_VPMASK(v)   BF_CS1(HDMI_VP_MASK, VPMASK, v)
#endif

/* --- Register HW_HDMI_VP_MASK, field VPMASK (RW)
 *
 * Mask bit for VP_INT[1] interrupt bit.
 */

#define BP_HDMI_VP_MASK_VPMASK      1
#define BM_HDMI_VP_MASK_VPMASK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_MASK_VPMASK(v)   ((((reg32_t) v) << 1) & BM_HDMI_VP_MASK_VPMASK)
#else
#define BF_HDMI_VP_MASK_VPMASK(v)   (((v) << 1) & BM_HDMI_VP_MASK_VPMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPMASK field to a new value.
#define BW_HDMI_VP_MASK_VPMASK(v)   BF_CS1(HDMI_VP_MASK, VPMASK, v)
#endif

/* --- Register HW_HDMI_VP_MASK, field VPMASK (RW)
 *
 * Mask bit for VP_INT[2] interrupt bit.
 */

#define BP_HDMI_VP_MASK_VPMASK      2
#define BM_HDMI_VP_MASK_VPMASK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_MASK_VPMASK(v)   ((((reg32_t) v) << 2) & BM_HDMI_VP_MASK_VPMASK)
#else
#define BF_HDMI_VP_MASK_VPMASK(v)   (((v) << 2) & BM_HDMI_VP_MASK_VPMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPMASK field to a new value.
#define BW_HDMI_VP_MASK_VPMASK(v)   BF_CS1(HDMI_VP_MASK, VPMASK, v)
#endif

/* --- Register HW_HDMI_VP_MASK, field VPMASK (RW)
 *
 * Mask bit for VP_INT[3] interrupt bit.
 */

#define BP_HDMI_VP_MASK_VPMASK      3
#define BM_HDMI_VP_MASK_VPMASK      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_MASK_VPMASK(v)   ((((reg32_t) v) << 3) & BM_HDMI_VP_MASK_VPMASK)
#else
#define BF_HDMI_VP_MASK_VPMASK(v)   (((v) << 3) & BM_HDMI_VP_MASK_VPMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPMASK field to a new value.
#define BW_HDMI_VP_MASK_VPMASK(v)   BF_CS1(HDMI_VP_MASK, VPMASK, v)
#endif

/* --- Register HW_HDMI_VP_MASK, field VPMASK (RW)
 *
 * Mask bit for VP_INT[4] interrupt bit.
 */

#define BP_HDMI_VP_MASK_VPMASK      4
#define BM_HDMI_VP_MASK_VPMASK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_MASK_VPMASK(v)   ((((reg32_t) v) << 4) & BM_HDMI_VP_MASK_VPMASK)
#else
#define BF_HDMI_VP_MASK_VPMASK(v)   (((v) << 4) & BM_HDMI_VP_MASK_VPMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPMASK field to a new value.
#define BW_HDMI_VP_MASK_VPMASK(v)   BF_CS1(HDMI_VP_MASK, VPMASK, v)
#endif

/* --- Register HW_HDMI_VP_MASK, field VPMASK (RW)
 *
 * Mask bit for VP_INT[5] interrupt bit.
 */

#define BP_HDMI_VP_MASK_VPMASK      5
#define BM_HDMI_VP_MASK_VPMASK      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_MASK_VPMASK(v)   ((((reg32_t) v) << 5) & BM_HDMI_VP_MASK_VPMASK)
#else
#define BF_HDMI_VP_MASK_VPMASK(v)   (((v) << 5) & BM_HDMI_VP_MASK_VPMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPMASK field to a new value.
#define BW_HDMI_VP_MASK_VPMASK(v)   BF_CS1(HDMI_VP_MASK, VPMASK, v)
#endif

/* --- Register HW_HDMI_VP_MASK, field VPMASK (RW)
 *
 * Mask bit for VP_INT[6] interrupt bit.
 */

#define BP_HDMI_VP_MASK_VPMASK      6
#define BM_HDMI_VP_MASK_VPMASK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_MASK_VPMASK(v)   ((((reg32_t) v) << 6) & BM_HDMI_VP_MASK_VPMASK)
#else
#define BF_HDMI_VP_MASK_VPMASK(v)   (((v) << 6) & BM_HDMI_VP_MASK_VPMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPMASK field to a new value.
#define BW_HDMI_VP_MASK_VPMASK(v)   BF_CS1(HDMI_VP_MASK, VPMASK, v)
#endif

/* --- Register HW_HDMI_VP_MASK, field VPMASK (RW)
 *
 * Mask bit for VP_INT[7] interrupt bit.
 */

#define BP_HDMI_VP_MASK_VPMASK      7
#define BM_HDMI_VP_MASK_VPMASK      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_MASK_VPMASK(v)   ((((reg32_t) v) << 7) & BM_HDMI_VP_MASK_VPMASK)
#else
#define BF_HDMI_VP_MASK_VPMASK(v)   (((v) << 7) & BM_HDMI_VP_MASK_VPMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPMASK field to a new value.
#define BW_HDMI_VP_MASK_VPMASK(v)   BF_CS1(HDMI_VP_MASK, VPMASK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_VP_POL - VP_POL (RW)
 *
 * Polarity register for generation of VP_INT interrupts.   Address Offset: 0x0808  Size: 8 bits
 * Value after Reset: 0xFF  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char VPPOL : 1; //!< Polarity bit for VP_INT[0] interrupt bit.
        unsigned char VPPOL1 : 1; //!< Polarity bit for VP_INT[1] interrupt bit.
        unsigned char VPPOL2 : 1; //!< Polarity bit for VP_INT[2] interrupt bit.
        unsigned char VPPOL3 : 1; //!< Polarity bit for VP_INT[3] interrupt bit.
        unsigned char VPPOL4 : 1; //!< Polarity bit for VP_INT[4] interrupt bit.
        unsigned char VPPOL5 : 1; //!< Polarity bit for VP_INT[5] interrupt bit.
        unsigned char VPPOL6 : 1; //!< Polarity bit for VP_INT[6] interrupt bit.
        unsigned char VPPOL7 : 1; //!< Polarity bit for VP_INT[7] interrupt bit.
    } B;
} hw_hdmi_vp_pol_t;
#endif

/*
 * constants & macros for entire HDMI_VP_POL register
 */
#define HW_HDMI_VP_POL_ADDR      (REGS_HDMI_BASE + 0x808)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_VP_POL           (*(volatile hw_hdmi_vp_pol_t *) HW_HDMI_VP_POL_ADDR)
#define HW_HDMI_VP_POL_RD()      (HW_HDMI_VP_POL.U)
#define HW_HDMI_VP_POL_WR(v)     (HW_HDMI_VP_POL.U = (v))
#define HW_HDMI_VP_POL_SET(v)    (HW_HDMI_VP_POL_WR(HW_HDMI_VP_POL_RD() |  (v)))
#define HW_HDMI_VP_POL_CLR(v)    (HW_HDMI_VP_POL_WR(HW_HDMI_VP_POL_RD() & ~(v)))
#define HW_HDMI_VP_POL_TOG(v)    (HW_HDMI_VP_POL_WR(HW_HDMI_VP_POL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_VP_POL bitfields
 */

/* --- Register HW_HDMI_VP_POL, field VPPOL (RW)
 *
 * Polarity bit for VP_INT[0] interrupt bit.
 */

#define BP_HDMI_VP_POL_VPPOL      0
#define BM_HDMI_VP_POL_VPPOL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_POL_VPPOL(v)   ((((reg32_t) v) << 0) & BM_HDMI_VP_POL_VPPOL)
#else
#define BF_HDMI_VP_POL_VPPOL(v)   (((v) << 0) & BM_HDMI_VP_POL_VPPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPPOL field to a new value.
#define BW_HDMI_VP_POL_VPPOL(v)   BF_CS1(HDMI_VP_POL, VPPOL, v)
#endif

/* --- Register HW_HDMI_VP_POL, field VPPOL (RW)
 *
 * Polarity bit for VP_INT[1] interrupt bit.
 */

#define BP_HDMI_VP_POL_VPPOL      1
#define BM_HDMI_VP_POL_VPPOL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_POL_VPPOL(v)   ((((reg32_t) v) << 1) & BM_HDMI_VP_POL_VPPOL)
#else
#define BF_HDMI_VP_POL_VPPOL(v)   (((v) << 1) & BM_HDMI_VP_POL_VPPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPPOL field to a new value.
#define BW_HDMI_VP_POL_VPPOL(v)   BF_CS1(HDMI_VP_POL, VPPOL, v)
#endif

/* --- Register HW_HDMI_VP_POL, field VPPOL (RW)
 *
 * Polarity bit for VP_INT[2] interrupt bit.
 */

#define BP_HDMI_VP_POL_VPPOL      2
#define BM_HDMI_VP_POL_VPPOL      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_POL_VPPOL(v)   ((((reg32_t) v) << 2) & BM_HDMI_VP_POL_VPPOL)
#else
#define BF_HDMI_VP_POL_VPPOL(v)   (((v) << 2) & BM_HDMI_VP_POL_VPPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPPOL field to a new value.
#define BW_HDMI_VP_POL_VPPOL(v)   BF_CS1(HDMI_VP_POL, VPPOL, v)
#endif

/* --- Register HW_HDMI_VP_POL, field VPPOL (RW)
 *
 * Polarity bit for VP_INT[3] interrupt bit.
 */

#define BP_HDMI_VP_POL_VPPOL      3
#define BM_HDMI_VP_POL_VPPOL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_POL_VPPOL(v)   ((((reg32_t) v) << 3) & BM_HDMI_VP_POL_VPPOL)
#else
#define BF_HDMI_VP_POL_VPPOL(v)   (((v) << 3) & BM_HDMI_VP_POL_VPPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPPOL field to a new value.
#define BW_HDMI_VP_POL_VPPOL(v)   BF_CS1(HDMI_VP_POL, VPPOL, v)
#endif

/* --- Register HW_HDMI_VP_POL, field VPPOL (RW)
 *
 * Polarity bit for VP_INT[4] interrupt bit.
 */

#define BP_HDMI_VP_POL_VPPOL      4
#define BM_HDMI_VP_POL_VPPOL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_POL_VPPOL(v)   ((((reg32_t) v) << 4) & BM_HDMI_VP_POL_VPPOL)
#else
#define BF_HDMI_VP_POL_VPPOL(v)   (((v) << 4) & BM_HDMI_VP_POL_VPPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPPOL field to a new value.
#define BW_HDMI_VP_POL_VPPOL(v)   BF_CS1(HDMI_VP_POL, VPPOL, v)
#endif

/* --- Register HW_HDMI_VP_POL, field VPPOL (RW)
 *
 * Polarity bit for VP_INT[5] interrupt bit.
 */

#define BP_HDMI_VP_POL_VPPOL      5
#define BM_HDMI_VP_POL_VPPOL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_POL_VPPOL(v)   ((((reg32_t) v) << 5) & BM_HDMI_VP_POL_VPPOL)
#else
#define BF_HDMI_VP_POL_VPPOL(v)   (((v) << 5) & BM_HDMI_VP_POL_VPPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPPOL field to a new value.
#define BW_HDMI_VP_POL_VPPOL(v)   BF_CS1(HDMI_VP_POL, VPPOL, v)
#endif

/* --- Register HW_HDMI_VP_POL, field VPPOL (RW)
 *
 * Polarity bit for VP_INT[6] interrupt bit.
 */

#define BP_HDMI_VP_POL_VPPOL      6
#define BM_HDMI_VP_POL_VPPOL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_POL_VPPOL(v)   ((((reg32_t) v) << 6) & BM_HDMI_VP_POL_VPPOL)
#else
#define BF_HDMI_VP_POL_VPPOL(v)   (((v) << 6) & BM_HDMI_VP_POL_VPPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPPOL field to a new value.
#define BW_HDMI_VP_POL_VPPOL(v)   BF_CS1(HDMI_VP_POL, VPPOL, v)
#endif

/* --- Register HW_HDMI_VP_POL, field VPPOL (RW)
 *
 * Polarity bit for VP_INT[7] interrupt bit.
 */

#define BP_HDMI_VP_POL_VPPOL      7
#define BM_HDMI_VP_POL_VPPOL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_VP_POL_VPPOL(v)   ((((reg32_t) v) << 7) & BM_HDMI_VP_POL_VPPOL)
#else
#define BF_HDMI_VP_POL_VPPOL(v)   (((v) << 7) & BM_HDMI_VP_POL_VPPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPPOL field to a new value.
#define BW_HDMI_VP_POL_VPPOL(v)   BF_CS1(HDMI_VP_POL, VPPOL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INVIDCONF - Frame Composer Input Video Configuration and HDCP Keepout Register (RW)
 *
 * This register configures the Interlaced/progressive, Vblank variation and polarity of all video
 * synchronism of the input video signal.   Address Offset: 0x1000  Size: 8 bits  Value after Reset:
 * 0x70  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char IN_I_P : 1; //!< Input video mode:
        unsigned char R_V_BLANK_IN_OSC : 1; //!< Used for CEA861-D modes with fractional Vblank (for example, modes 5, 6, 7, 10, 11, 20, 21, and 22. For more modes, refer to CEA861-D specification.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char DVI_MODEZ : 1; //!< Active low
        unsigned char DE_IN_POLARITY : 1; //!< Data enable input polarity
        unsigned char HSYNC_IN_POLARITY : 1; //!< Hsync input polarity
        unsigned char VSYNC_IN_POLARITY : 1; //!< Vsync input polarity
        unsigned char HDCP_KEEPOUT : 1; //!< Start/stop HDCP keepout window generation
    } B;
} hw_hdmi_fc_invidconf_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INVIDCONF register
 */
#define HW_HDMI_FC_INVIDCONF_ADDR      (REGS_HDMI_BASE + 0x1000)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INVIDCONF           (*(volatile hw_hdmi_fc_invidconf_t *) HW_HDMI_FC_INVIDCONF_ADDR)
#define HW_HDMI_FC_INVIDCONF_RD()      (HW_HDMI_FC_INVIDCONF.U)
#define HW_HDMI_FC_INVIDCONF_WR(v)     (HW_HDMI_FC_INVIDCONF.U = (v))
#define HW_HDMI_FC_INVIDCONF_SET(v)    (HW_HDMI_FC_INVIDCONF_WR(HW_HDMI_FC_INVIDCONF_RD() |  (v)))
#define HW_HDMI_FC_INVIDCONF_CLR(v)    (HW_HDMI_FC_INVIDCONF_WR(HW_HDMI_FC_INVIDCONF_RD() & ~(v)))
#define HW_HDMI_FC_INVIDCONF_TOG(v)    (HW_HDMI_FC_INVIDCONF_WR(HW_HDMI_FC_INVIDCONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INVIDCONF bitfields
 */

/* --- Register HW_HDMI_FC_INVIDCONF, field IN_I_P (RW)
 *
 * Input video mode:
 *
 * Values:
 * 1 - Interlaced
 * 0 - Progressive
 */

#define BP_HDMI_FC_INVIDCONF_IN_I_P      0
#define BM_HDMI_FC_INVIDCONF_IN_I_P      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVIDCONF_IN_I_P(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INVIDCONF_IN_I_P)
#else
#define BF_HDMI_FC_INVIDCONF_IN_I_P(v)   (((v) << 0) & BM_HDMI_FC_INVIDCONF_IN_I_P)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IN_I_P field to a new value.
#define BW_HDMI_FC_INVIDCONF_IN_I_P(v)   BF_CS1(HDMI_FC_INVIDCONF, IN_I_P, v)
#endif


/* --- Register HW_HDMI_FC_INVIDCONF, field R_V_BLANK_IN_OSC (RW)
 *
 * Used for CEA861-D modes with fractional Vblank (for example, modes 5, 6, 7, 10, 11, 20, 21, and
 * 22. For more modes, refer to CEA861-D specification.
 *
 * Values:
 * 1 - Active high
 */

#define BP_HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC      1
#define BM_HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC)
#else
#define BF_HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC(v)   (((v) << 1) & BM_HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the R_V_BLANK_IN_OSC field to a new value.
#define BW_HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC(v)   BF_CS1(HDMI_FC_INVIDCONF, R_V_BLANK_IN_OSC, v)
#endif


/* --- Register HW_HDMI_FC_INVIDCONF, field DVI_MODEZ (RW)
 *
 * Active low
 *
 * Values:
 * 0 - DVI mode selected
 * 1 - HDMI mode selected
 */

#define BP_HDMI_FC_INVIDCONF_DVI_MODEZ      3
#define BM_HDMI_FC_INVIDCONF_DVI_MODEZ      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVIDCONF_DVI_MODEZ(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_INVIDCONF_DVI_MODEZ)
#else
#define BF_HDMI_FC_INVIDCONF_DVI_MODEZ(v)   (((v) << 3) & BM_HDMI_FC_INVIDCONF_DVI_MODEZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DVI_MODEZ field to a new value.
#define BW_HDMI_FC_INVIDCONF_DVI_MODEZ(v)   BF_CS1(HDMI_FC_INVIDCONF, DVI_MODEZ, v)
#endif


/* --- Register HW_HDMI_FC_INVIDCONF, field DE_IN_POLARITY (RW)
 *
 * Data enable input polarity
 *
 * Values:
 * 1 - Active high
 * 0 - Active low
 */

#define BP_HDMI_FC_INVIDCONF_DE_IN_POLARITY      4
#define BM_HDMI_FC_INVIDCONF_DE_IN_POLARITY      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVIDCONF_DE_IN_POLARITY(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_INVIDCONF_DE_IN_POLARITY)
#else
#define BF_HDMI_FC_INVIDCONF_DE_IN_POLARITY(v)   (((v) << 4) & BM_HDMI_FC_INVIDCONF_DE_IN_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DE_IN_POLARITY field to a new value.
#define BW_HDMI_FC_INVIDCONF_DE_IN_POLARITY(v)   BF_CS1(HDMI_FC_INVIDCONF, DE_IN_POLARITY, v)
#endif


/* --- Register HW_HDMI_FC_INVIDCONF, field HSYNC_IN_POLARITY (RW)
 *
 * Hsync input polarity
 *
 * Values:
 * 1 - Active high
 * 0 - Active low
 */

#define BP_HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY      5
#define BM_HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY)
#else
#define BF_HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY(v)   (((v) << 5) & BM_HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNC_IN_POLARITY field to a new value.
#define BW_HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY(v)   BF_CS1(HDMI_FC_INVIDCONF, HSYNC_IN_POLARITY, v)
#endif


/* --- Register HW_HDMI_FC_INVIDCONF, field VSYNC_IN_POLARITY (RW)
 *
 * Vsync input polarity
 *
 * Values:
 * 1 - Active high
 * 0 - Active low
 */

#define BP_HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY      6
#define BM_HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY)
#else
#define BF_HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY(v)   (((v) << 6) & BM_HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_IN_POLARITY field to a new value.
#define BW_HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY(v)   BF_CS1(HDMI_FC_INVIDCONF, VSYNC_IN_POLARITY, v)
#endif


/* --- Register HW_HDMI_FC_INVIDCONF, field HDCP_KEEPOUT (RW)
 *
 * Start/stop HDCP keepout window generation
 *
 * Values:
 * 1b - Active
 */

#define BP_HDMI_FC_INVIDCONF_HDCP_KEEPOUT      7
#define BM_HDMI_FC_INVIDCONF_HDCP_KEEPOUT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVIDCONF_HDCP_KEEPOUT(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_INVIDCONF_HDCP_KEEPOUT)
#else
#define BF_HDMI_FC_INVIDCONF_HDCP_KEEPOUT(v)   (((v) << 7) & BM_HDMI_FC_INVIDCONF_HDCP_KEEPOUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCP_KEEPOUT field to a new value.
#define BW_HDMI_FC_INVIDCONF_HDCP_KEEPOUT(v)   BF_CS1(HDMI_FC_INVIDCONF, HDCP_KEEPOUT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INHACTIV0 - Frame Composer Input Video HActive Pixels Register 0 (RW)
 *
 * Address Offset: 0x1001  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char H_IN_ACTIV : 8; //!< Input video Horizontal active pixel region width. Number of Horizontal active pixels [0...8191].
    } B;
} hw_hdmi_fc_inhactiv0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INHACTIV0 register
 */
#define HW_HDMI_FC_INHACTIV0_ADDR      (REGS_HDMI_BASE + 0x1001)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INHACTIV0           (*(volatile hw_hdmi_fc_inhactiv0_t *) HW_HDMI_FC_INHACTIV0_ADDR)
#define HW_HDMI_FC_INHACTIV0_RD()      (HW_HDMI_FC_INHACTIV0.U)
#define HW_HDMI_FC_INHACTIV0_WR(v)     (HW_HDMI_FC_INHACTIV0.U = (v))
#define HW_HDMI_FC_INHACTIV0_SET(v)    (HW_HDMI_FC_INHACTIV0_WR(HW_HDMI_FC_INHACTIV0_RD() |  (v)))
#define HW_HDMI_FC_INHACTIV0_CLR(v)    (HW_HDMI_FC_INHACTIV0_WR(HW_HDMI_FC_INHACTIV0_RD() & ~(v)))
#define HW_HDMI_FC_INHACTIV0_TOG(v)    (HW_HDMI_FC_INHACTIV0_WR(HW_HDMI_FC_INHACTIV0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INHACTIV0 bitfields
 */

/* --- Register HW_HDMI_FC_INHACTIV0, field H_IN_ACTIV (RW)
 *
 * Input video Horizontal active pixel region width. Number of Horizontal active pixels [0...8191].
 */

#define BP_HDMI_FC_INHACTIV0_H_IN_ACTIV      0
#define BM_HDMI_FC_INHACTIV0_H_IN_ACTIV      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INHACTIV0_H_IN_ACTIV(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INHACTIV0_H_IN_ACTIV)
#else
#define BF_HDMI_FC_INHACTIV0_H_IN_ACTIV(v)   (((v) << 0) & BM_HDMI_FC_INHACTIV0_H_IN_ACTIV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the H_IN_ACTIV field to a new value.
#define BW_HDMI_FC_INHACTIV0_H_IN_ACTIV(v)   BF_CS1(HDMI_FC_INHACTIV0, H_IN_ACTIV, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INHACTIV1 - Frame Composer Input Video HActive Pixels Register 1 (RW)
 *
 * Address Offset: 0x1002  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char H_IN_ACTIV : 5; //!< Input video Horizontal active pixel region width. Dependencies: Value after Reset: 0000b the higher bit of Horizontal active pixels; Number of Horizontal active pixels [0...8191].
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_inhactiv1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INHACTIV1 register
 */
#define HW_HDMI_FC_INHACTIV1_ADDR      (REGS_HDMI_BASE + 0x1002)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INHACTIV1           (*(volatile hw_hdmi_fc_inhactiv1_t *) HW_HDMI_FC_INHACTIV1_ADDR)
#define HW_HDMI_FC_INHACTIV1_RD()      (HW_HDMI_FC_INHACTIV1.U)
#define HW_HDMI_FC_INHACTIV1_WR(v)     (HW_HDMI_FC_INHACTIV1.U = (v))
#define HW_HDMI_FC_INHACTIV1_SET(v)    (HW_HDMI_FC_INHACTIV1_WR(HW_HDMI_FC_INHACTIV1_RD() |  (v)))
#define HW_HDMI_FC_INHACTIV1_CLR(v)    (HW_HDMI_FC_INHACTIV1_WR(HW_HDMI_FC_INHACTIV1_RD() & ~(v)))
#define HW_HDMI_FC_INHACTIV1_TOG(v)    (HW_HDMI_FC_INHACTIV1_WR(HW_HDMI_FC_INHACTIV1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INHACTIV1 bitfields
 */

/* --- Register HW_HDMI_FC_INHACTIV1, field H_IN_ACTIV (RW)
 *
 * Input video Horizontal active pixel region width. Dependencies: Value after Reset: 0000b the
 * higher bit of Horizontal active pixels; Number of Horizontal active pixels [0...8191].
 */

#define BP_HDMI_FC_INHACTIV1_H_IN_ACTIV      0
#define BM_HDMI_FC_INHACTIV1_H_IN_ACTIV      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INHACTIV1_H_IN_ACTIV(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INHACTIV1_H_IN_ACTIV)
#else
#define BF_HDMI_FC_INHACTIV1_H_IN_ACTIV(v)   (((v) << 0) & BM_HDMI_FC_INHACTIV1_H_IN_ACTIV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the H_IN_ACTIV field to a new value.
#define BW_HDMI_FC_INHACTIV1_H_IN_ACTIV(v)   BF_CS1(HDMI_FC_INHACTIV1, H_IN_ACTIV, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INHBLANK0 - Frame Composer Input Video HBlank Pixels Register 0 (RW)
 *
 * Address Offset: 0x1003  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char H_IN_BLANK : 8; //!< Input video Horizontal blanking pixel region width. Number of Horizontal blanking pixels [0...4095].
    } B;
} hw_hdmi_fc_inhblank0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INHBLANK0 register
 */
#define HW_HDMI_FC_INHBLANK0_ADDR      (REGS_HDMI_BASE + 0x1003)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INHBLANK0           (*(volatile hw_hdmi_fc_inhblank0_t *) HW_HDMI_FC_INHBLANK0_ADDR)
#define HW_HDMI_FC_INHBLANK0_RD()      (HW_HDMI_FC_INHBLANK0.U)
#define HW_HDMI_FC_INHBLANK0_WR(v)     (HW_HDMI_FC_INHBLANK0.U = (v))
#define HW_HDMI_FC_INHBLANK0_SET(v)    (HW_HDMI_FC_INHBLANK0_WR(HW_HDMI_FC_INHBLANK0_RD() |  (v)))
#define HW_HDMI_FC_INHBLANK0_CLR(v)    (HW_HDMI_FC_INHBLANK0_WR(HW_HDMI_FC_INHBLANK0_RD() & ~(v)))
#define HW_HDMI_FC_INHBLANK0_TOG(v)    (HW_HDMI_FC_INHBLANK0_WR(HW_HDMI_FC_INHBLANK0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INHBLANK0 bitfields
 */

/* --- Register HW_HDMI_FC_INHBLANK0, field H_IN_BLANK (RW)
 *
 * Input video Horizontal blanking pixel region width. Number of Horizontal blanking pixels
 * [0...4095].
 */

#define BP_HDMI_FC_INHBLANK0_H_IN_BLANK      0
#define BM_HDMI_FC_INHBLANK0_H_IN_BLANK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INHBLANK0_H_IN_BLANK(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INHBLANK0_H_IN_BLANK)
#else
#define BF_HDMI_FC_INHBLANK0_H_IN_BLANK(v)   (((v) << 0) & BM_HDMI_FC_INHBLANK0_H_IN_BLANK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the H_IN_BLANK field to a new value.
#define BW_HDMI_FC_INHBLANK0_H_IN_BLANK(v)   BF_CS1(HDMI_FC_INHBLANK0, H_IN_BLANK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INHBLANK1 - Frame Composer Input Video HBlank Pixels Register 1 (RW)
 *
 * Address Offset: 0x1004  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char H_IN_BLANK : 5; //!< Input video Horizontal blanking pixel region width. Dependencies: Value after Reset: 0000b the higher bits of Horizontal blanking pixels; Number of Horizontal blanking pixels [0...8191].
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_inhblank1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INHBLANK1 register
 */
#define HW_HDMI_FC_INHBLANK1_ADDR      (REGS_HDMI_BASE + 0x1004)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INHBLANK1           (*(volatile hw_hdmi_fc_inhblank1_t *) HW_HDMI_FC_INHBLANK1_ADDR)
#define HW_HDMI_FC_INHBLANK1_RD()      (HW_HDMI_FC_INHBLANK1.U)
#define HW_HDMI_FC_INHBLANK1_WR(v)     (HW_HDMI_FC_INHBLANK1.U = (v))
#define HW_HDMI_FC_INHBLANK1_SET(v)    (HW_HDMI_FC_INHBLANK1_WR(HW_HDMI_FC_INHBLANK1_RD() |  (v)))
#define HW_HDMI_FC_INHBLANK1_CLR(v)    (HW_HDMI_FC_INHBLANK1_WR(HW_HDMI_FC_INHBLANK1_RD() & ~(v)))
#define HW_HDMI_FC_INHBLANK1_TOG(v)    (HW_HDMI_FC_INHBLANK1_WR(HW_HDMI_FC_INHBLANK1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INHBLANK1 bitfields
 */

/* --- Register HW_HDMI_FC_INHBLANK1, field H_IN_BLANK (RW)
 *
 * Input video Horizontal blanking pixel region width. Dependencies: Value after Reset: 0000b the
 * higher bits of Horizontal blanking pixels; Number of Horizontal blanking pixels [0...8191].
 */

#define BP_HDMI_FC_INHBLANK1_H_IN_BLANK      0
#define BM_HDMI_FC_INHBLANK1_H_IN_BLANK      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INHBLANK1_H_IN_BLANK(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INHBLANK1_H_IN_BLANK)
#else
#define BF_HDMI_FC_INHBLANK1_H_IN_BLANK(v)   (((v) << 0) & BM_HDMI_FC_INHBLANK1_H_IN_BLANK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the H_IN_BLANK field to a new value.
#define BW_HDMI_FC_INHBLANK1_H_IN_BLANK(v)   BF_CS1(HDMI_FC_INHBLANK1, H_IN_BLANK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INVACTIV0 - Frame Composer Input Video VActive Pixels Register 0 (RW)
 *
 * Address Offset: 0x1005  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char V_IN_ACTIV : 8; //!< Input video Vertical active pixel region width. Number of Vertical active lines [0...4095].
    } B;
} hw_hdmi_fc_invactiv0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INVACTIV0 register
 */
#define HW_HDMI_FC_INVACTIV0_ADDR      (REGS_HDMI_BASE + 0x1005)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INVACTIV0           (*(volatile hw_hdmi_fc_invactiv0_t *) HW_HDMI_FC_INVACTIV0_ADDR)
#define HW_HDMI_FC_INVACTIV0_RD()      (HW_HDMI_FC_INVACTIV0.U)
#define HW_HDMI_FC_INVACTIV0_WR(v)     (HW_HDMI_FC_INVACTIV0.U = (v))
#define HW_HDMI_FC_INVACTIV0_SET(v)    (HW_HDMI_FC_INVACTIV0_WR(HW_HDMI_FC_INVACTIV0_RD() |  (v)))
#define HW_HDMI_FC_INVACTIV0_CLR(v)    (HW_HDMI_FC_INVACTIV0_WR(HW_HDMI_FC_INVACTIV0_RD() & ~(v)))
#define HW_HDMI_FC_INVACTIV0_TOG(v)    (HW_HDMI_FC_INVACTIV0_WR(HW_HDMI_FC_INVACTIV0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INVACTIV0 bitfields
 */

/* --- Register HW_HDMI_FC_INVACTIV0, field V_IN_ACTIV (RW)
 *
 * Input video Vertical active pixel region width. Number of Vertical active lines [0...4095].
 */

#define BP_HDMI_FC_INVACTIV0_V_IN_ACTIV      0
#define BM_HDMI_FC_INVACTIV0_V_IN_ACTIV      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVACTIV0_V_IN_ACTIV(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INVACTIV0_V_IN_ACTIV)
#else
#define BF_HDMI_FC_INVACTIV0_V_IN_ACTIV(v)   (((v) << 0) & BM_HDMI_FC_INVACTIV0_V_IN_ACTIV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the V_IN_ACTIV field to a new value.
#define BW_HDMI_FC_INVACTIV0_V_IN_ACTIV(v)   BF_CS1(HDMI_FC_INVACTIV0, V_IN_ACTIV, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INVACTIV1 - Frame Composer Input Video VActive Pixels Register 1 (RW)
 *
 * Address Offset: 0x1006  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char V_IN_ACTIV : 5; //!< Input video Vertical active pixel region width. Dependencies: Value after Reset: 0000b the higher 5 bits of Vertical active line; Number of Vertical active lines [0...8191].
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_invactiv1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INVACTIV1 register
 */
#define HW_HDMI_FC_INVACTIV1_ADDR      (REGS_HDMI_BASE + 0x1006)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INVACTIV1           (*(volatile hw_hdmi_fc_invactiv1_t *) HW_HDMI_FC_INVACTIV1_ADDR)
#define HW_HDMI_FC_INVACTIV1_RD()      (HW_HDMI_FC_INVACTIV1.U)
#define HW_HDMI_FC_INVACTIV1_WR(v)     (HW_HDMI_FC_INVACTIV1.U = (v))
#define HW_HDMI_FC_INVACTIV1_SET(v)    (HW_HDMI_FC_INVACTIV1_WR(HW_HDMI_FC_INVACTIV1_RD() |  (v)))
#define HW_HDMI_FC_INVACTIV1_CLR(v)    (HW_HDMI_FC_INVACTIV1_WR(HW_HDMI_FC_INVACTIV1_RD() & ~(v)))
#define HW_HDMI_FC_INVACTIV1_TOG(v)    (HW_HDMI_FC_INVACTIV1_WR(HW_HDMI_FC_INVACTIV1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INVACTIV1 bitfields
 */

/* --- Register HW_HDMI_FC_INVACTIV1, field V_IN_ACTIV (RW)
 *
 * Input video Vertical active pixel region width. Dependencies: Value after Reset: 0000b the higher
 * 5 bits of Vertical active line; Number of Vertical active lines [0...8191].
 */

#define BP_HDMI_FC_INVACTIV1_V_IN_ACTIV      0
#define BM_HDMI_FC_INVACTIV1_V_IN_ACTIV      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVACTIV1_V_IN_ACTIV(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INVACTIV1_V_IN_ACTIV)
#else
#define BF_HDMI_FC_INVACTIV1_V_IN_ACTIV(v)   (((v) << 0) & BM_HDMI_FC_INVACTIV1_V_IN_ACTIV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the V_IN_ACTIV field to a new value.
#define BW_HDMI_FC_INVACTIV1_V_IN_ACTIV(v)   BF_CS1(HDMI_FC_INVACTIV1, V_IN_ACTIV, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INVBLANK - Frame Composer Input Video VBlank Pixels Register (RW)
 *
 * Address Offset: 0x1007  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char V_IN_BLANK : 8; //!< Input video Vertical blanking pixel region width. Number of Vertical blanking lines [0...255]. Value after Reset: 0x00
    } B;
} hw_hdmi_fc_invblank_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INVBLANK register
 */
#define HW_HDMI_FC_INVBLANK_ADDR      (REGS_HDMI_BASE + 0x1007)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INVBLANK           (*(volatile hw_hdmi_fc_invblank_t *) HW_HDMI_FC_INVBLANK_ADDR)
#define HW_HDMI_FC_INVBLANK_RD()      (HW_HDMI_FC_INVBLANK.U)
#define HW_HDMI_FC_INVBLANK_WR(v)     (HW_HDMI_FC_INVBLANK.U = (v))
#define HW_HDMI_FC_INVBLANK_SET(v)    (HW_HDMI_FC_INVBLANK_WR(HW_HDMI_FC_INVBLANK_RD() |  (v)))
#define HW_HDMI_FC_INVBLANK_CLR(v)    (HW_HDMI_FC_INVBLANK_WR(HW_HDMI_FC_INVBLANK_RD() & ~(v)))
#define HW_HDMI_FC_INVBLANK_TOG(v)    (HW_HDMI_FC_INVBLANK_WR(HW_HDMI_FC_INVBLANK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INVBLANK bitfields
 */

/* --- Register HW_HDMI_FC_INVBLANK, field V_IN_BLANK (RW)
 *
 * Input video Vertical blanking pixel region width. Number of Vertical blanking lines [0...255].
 * Value after Reset: 0x00
 */

#define BP_HDMI_FC_INVBLANK_V_IN_BLANK      0
#define BM_HDMI_FC_INVBLANK_V_IN_BLANK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INVBLANK_V_IN_BLANK(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INVBLANK_V_IN_BLANK)
#else
#define BF_HDMI_FC_INVBLANK_V_IN_BLANK(v)   (((v) << 0) & BM_HDMI_FC_INVBLANK_V_IN_BLANK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the V_IN_BLANK field to a new value.
#define BW_HDMI_FC_INVBLANK_V_IN_BLANK(v)   BF_CS1(HDMI_FC_INVBLANK, V_IN_BLANK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_HSYNCINDELAY0 - Frame Composer Input Video HSync Front Porch Register 0 (RW)
 *
 * Address Offset: 0x1008  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char H_IN_DELAY : 8; //!< Input video Hsync active edge delay. Integer number of pixel clock cycles from "de" non active edge of the last "de" valid period [0...4095].
    } B;
} hw_hdmi_fc_hsyncindelay0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_HSYNCINDELAY0 register
 */
#define HW_HDMI_FC_HSYNCINDELAY0_ADDR      (REGS_HDMI_BASE + 0x1008)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_HSYNCINDELAY0           (*(volatile hw_hdmi_fc_hsyncindelay0_t *) HW_HDMI_FC_HSYNCINDELAY0_ADDR)
#define HW_HDMI_FC_HSYNCINDELAY0_RD()      (HW_HDMI_FC_HSYNCINDELAY0.U)
#define HW_HDMI_FC_HSYNCINDELAY0_WR(v)     (HW_HDMI_FC_HSYNCINDELAY0.U = (v))
#define HW_HDMI_FC_HSYNCINDELAY0_SET(v)    (HW_HDMI_FC_HSYNCINDELAY0_WR(HW_HDMI_FC_HSYNCINDELAY0_RD() |  (v)))
#define HW_HDMI_FC_HSYNCINDELAY0_CLR(v)    (HW_HDMI_FC_HSYNCINDELAY0_WR(HW_HDMI_FC_HSYNCINDELAY0_RD() & ~(v)))
#define HW_HDMI_FC_HSYNCINDELAY0_TOG(v)    (HW_HDMI_FC_HSYNCINDELAY0_WR(HW_HDMI_FC_HSYNCINDELAY0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_HSYNCINDELAY0 bitfields
 */

/* --- Register HW_HDMI_FC_HSYNCINDELAY0, field H_IN_DELAY (RW)
 *
 * Input video Hsync active edge delay. Integer number of pixel clock cycles from "de" non active
 * edge of the last "de" valid period [0...4095].
 */

#define BP_HDMI_FC_HSYNCINDELAY0_H_IN_DELAY      0
#define BM_HDMI_FC_HSYNCINDELAY0_H_IN_DELAY      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_HSYNCINDELAY0_H_IN_DELAY(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_HSYNCINDELAY0_H_IN_DELAY)
#else
#define BF_HDMI_FC_HSYNCINDELAY0_H_IN_DELAY(v)   (((v) << 0) & BM_HDMI_FC_HSYNCINDELAY0_H_IN_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the H_IN_DELAY field to a new value.
#define BW_HDMI_FC_HSYNCINDELAY0_H_IN_DELAY(v)   BF_CS1(HDMI_FC_HSYNCINDELAY0, H_IN_DELAY, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_HSYNCINDELAY1 - Frame Composer Input Video HSync Front Porch Register 1 (RW)
 *
 * Address Offset: 0x1009  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char H_IN_DELAY : 5; //!< Input video Hsync active edge delay. Dependencies: Value after Reset: 0000b the higher 5 bits of delay; Integer number of pixel clock cycles from "de" non active edge of the last "de" valid period [0...8191].
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_hsyncindelay1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_HSYNCINDELAY1 register
 */
#define HW_HDMI_FC_HSYNCINDELAY1_ADDR      (REGS_HDMI_BASE + 0x1009)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_HSYNCINDELAY1           (*(volatile hw_hdmi_fc_hsyncindelay1_t *) HW_HDMI_FC_HSYNCINDELAY1_ADDR)
#define HW_HDMI_FC_HSYNCINDELAY1_RD()      (HW_HDMI_FC_HSYNCINDELAY1.U)
#define HW_HDMI_FC_HSYNCINDELAY1_WR(v)     (HW_HDMI_FC_HSYNCINDELAY1.U = (v))
#define HW_HDMI_FC_HSYNCINDELAY1_SET(v)    (HW_HDMI_FC_HSYNCINDELAY1_WR(HW_HDMI_FC_HSYNCINDELAY1_RD() |  (v)))
#define HW_HDMI_FC_HSYNCINDELAY1_CLR(v)    (HW_HDMI_FC_HSYNCINDELAY1_WR(HW_HDMI_FC_HSYNCINDELAY1_RD() & ~(v)))
#define HW_HDMI_FC_HSYNCINDELAY1_TOG(v)    (HW_HDMI_FC_HSYNCINDELAY1_WR(HW_HDMI_FC_HSYNCINDELAY1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_HSYNCINDELAY1 bitfields
 */

/* --- Register HW_HDMI_FC_HSYNCINDELAY1, field H_IN_DELAY (RW)
 *
 * Input video Hsync active edge delay. Dependencies: Value after Reset: 0000b the higher 5 bits of
 * delay; Integer number of pixel clock cycles from "de" non active edge of the last "de" valid
 * period [0...8191].
 */

#define BP_HDMI_FC_HSYNCINDELAY1_H_IN_DELAY      0
#define BM_HDMI_FC_HSYNCINDELAY1_H_IN_DELAY      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_HSYNCINDELAY1_H_IN_DELAY(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_HSYNCINDELAY1_H_IN_DELAY)
#else
#define BF_HDMI_FC_HSYNCINDELAY1_H_IN_DELAY(v)   (((v) << 0) & BM_HDMI_FC_HSYNCINDELAY1_H_IN_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the H_IN_DELAY field to a new value.
#define BW_HDMI_FC_HSYNCINDELAY1_H_IN_DELAY(v)   BF_CS1(HDMI_FC_HSYNCINDELAY1, H_IN_DELAY, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_HSYNCINWIDTH0 - Frame Composer Input Video HSync Width Register 0 (RW)
 *
 * Address Offset: 0x100A  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char H_IN_WIDTH : 8; //!< Input video Hsync active pulse width. Integer number of pixel clock cycles [0...511].
    } B;
} hw_hdmi_fc_hsyncinwidth0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_HSYNCINWIDTH0 register
 */
#define HW_HDMI_FC_HSYNCINWIDTH0_ADDR      (REGS_HDMI_BASE + 0x100a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_HSYNCINWIDTH0           (*(volatile hw_hdmi_fc_hsyncinwidth0_t *) HW_HDMI_FC_HSYNCINWIDTH0_ADDR)
#define HW_HDMI_FC_HSYNCINWIDTH0_RD()      (HW_HDMI_FC_HSYNCINWIDTH0.U)
#define HW_HDMI_FC_HSYNCINWIDTH0_WR(v)     (HW_HDMI_FC_HSYNCINWIDTH0.U = (v))
#define HW_HDMI_FC_HSYNCINWIDTH0_SET(v)    (HW_HDMI_FC_HSYNCINWIDTH0_WR(HW_HDMI_FC_HSYNCINWIDTH0_RD() |  (v)))
#define HW_HDMI_FC_HSYNCINWIDTH0_CLR(v)    (HW_HDMI_FC_HSYNCINWIDTH0_WR(HW_HDMI_FC_HSYNCINWIDTH0_RD() & ~(v)))
#define HW_HDMI_FC_HSYNCINWIDTH0_TOG(v)    (HW_HDMI_FC_HSYNCINWIDTH0_WR(HW_HDMI_FC_HSYNCINWIDTH0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_HSYNCINWIDTH0 bitfields
 */

/* --- Register HW_HDMI_FC_HSYNCINWIDTH0, field H_IN_WIDTH (RW)
 *
 * Input video Hsync active pulse width. Integer number of pixel clock cycles [0...511].
 */

#define BP_HDMI_FC_HSYNCINWIDTH0_H_IN_WIDTH      0
#define BM_HDMI_FC_HSYNCINWIDTH0_H_IN_WIDTH      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_HSYNCINWIDTH0_H_IN_WIDTH(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_HSYNCINWIDTH0_H_IN_WIDTH)
#else
#define BF_HDMI_FC_HSYNCINWIDTH0_H_IN_WIDTH(v)   (((v) << 0) & BM_HDMI_FC_HSYNCINWIDTH0_H_IN_WIDTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the H_IN_WIDTH field to a new value.
#define BW_HDMI_FC_HSYNCINWIDTH0_H_IN_WIDTH(v)   BF_CS1(HDMI_FC_HSYNCINWIDTH0, H_IN_WIDTH, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_HSYNCINWIDTH1 - Frame Composer Input Video HSync Width Register 1 (RW)
 *
 * Address Offset: 0x100B  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char H_IN_WIDTH : 2; //!< Input video Hsync active pulse width. Dependencies: Value after Reset after Reset: 0b Integer number of pixel clock cycles [0...1024].
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_fc_hsyncinwidth1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_HSYNCINWIDTH1 register
 */
#define HW_HDMI_FC_HSYNCINWIDTH1_ADDR      (REGS_HDMI_BASE + 0x100b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_HSYNCINWIDTH1           (*(volatile hw_hdmi_fc_hsyncinwidth1_t *) HW_HDMI_FC_HSYNCINWIDTH1_ADDR)
#define HW_HDMI_FC_HSYNCINWIDTH1_RD()      (HW_HDMI_FC_HSYNCINWIDTH1.U)
#define HW_HDMI_FC_HSYNCINWIDTH1_WR(v)     (HW_HDMI_FC_HSYNCINWIDTH1.U = (v))
#define HW_HDMI_FC_HSYNCINWIDTH1_SET(v)    (HW_HDMI_FC_HSYNCINWIDTH1_WR(HW_HDMI_FC_HSYNCINWIDTH1_RD() |  (v)))
#define HW_HDMI_FC_HSYNCINWIDTH1_CLR(v)    (HW_HDMI_FC_HSYNCINWIDTH1_WR(HW_HDMI_FC_HSYNCINWIDTH1_RD() & ~(v)))
#define HW_HDMI_FC_HSYNCINWIDTH1_TOG(v)    (HW_HDMI_FC_HSYNCINWIDTH1_WR(HW_HDMI_FC_HSYNCINWIDTH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_HSYNCINWIDTH1 bitfields
 */

/* --- Register HW_HDMI_FC_HSYNCINWIDTH1, field H_IN_WIDTH (RW)
 *
 * Input video Hsync active pulse width. Dependencies: Value after Reset after Reset: 0b Integer
 * number of pixel clock cycles [0...1024].
 */

#define BP_HDMI_FC_HSYNCINWIDTH1_H_IN_WIDTH      0
#define BM_HDMI_FC_HSYNCINWIDTH1_H_IN_WIDTH      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_HSYNCINWIDTH1_H_IN_WIDTH(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_HSYNCINWIDTH1_H_IN_WIDTH)
#else
#define BF_HDMI_FC_HSYNCINWIDTH1_H_IN_WIDTH(v)   (((v) << 0) & BM_HDMI_FC_HSYNCINWIDTH1_H_IN_WIDTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the H_IN_WIDTH field to a new value.
#define BW_HDMI_FC_HSYNCINWIDTH1_H_IN_WIDTH(v)   BF_CS1(HDMI_FC_HSYNCINWIDTH1, H_IN_WIDTH, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSYNCINDELAY - Frame Composer Input Video VSync Front Porch Register (RW)
 *
 * Address Offset: 0x100C  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char V_IN_DELAY : 8; //!< Input video Vsync active edge delay. Integer number of Hsync pulses from "de" non active edge of the last "de" valid period. [0...255].
    } B;
} hw_hdmi_fc_vsyncindelay_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSYNCINDELAY register
 */
#define HW_HDMI_FC_VSYNCINDELAY_ADDR      (REGS_HDMI_BASE + 0x100c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSYNCINDELAY           (*(volatile hw_hdmi_fc_vsyncindelay_t *) HW_HDMI_FC_VSYNCINDELAY_ADDR)
#define HW_HDMI_FC_VSYNCINDELAY_RD()      (HW_HDMI_FC_VSYNCINDELAY.U)
#define HW_HDMI_FC_VSYNCINDELAY_WR(v)     (HW_HDMI_FC_VSYNCINDELAY.U = (v))
#define HW_HDMI_FC_VSYNCINDELAY_SET(v)    (HW_HDMI_FC_VSYNCINDELAY_WR(HW_HDMI_FC_VSYNCINDELAY_RD() |  (v)))
#define HW_HDMI_FC_VSYNCINDELAY_CLR(v)    (HW_HDMI_FC_VSYNCINDELAY_WR(HW_HDMI_FC_VSYNCINDELAY_RD() & ~(v)))
#define HW_HDMI_FC_VSYNCINDELAY_TOG(v)    (HW_HDMI_FC_VSYNCINDELAY_WR(HW_HDMI_FC_VSYNCINDELAY_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSYNCINDELAY bitfields
 */

/* --- Register HW_HDMI_FC_VSYNCINDELAY, field V_IN_DELAY (RW)
 *
 * Input video Vsync active edge delay. Integer number of Hsync pulses from "de" non active edge of
 * the last "de" valid period. [0...255].
 */

#define BP_HDMI_FC_VSYNCINDELAY_V_IN_DELAY      0
#define BM_HDMI_FC_VSYNCINDELAY_V_IN_DELAY      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_VSYNCINDELAY_V_IN_DELAY(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_VSYNCINDELAY_V_IN_DELAY)
#else
#define BF_HDMI_FC_VSYNCINDELAY_V_IN_DELAY(v)   (((v) << 0) & BM_HDMI_FC_VSYNCINDELAY_V_IN_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the V_IN_DELAY field to a new value.
#define BW_HDMI_FC_VSYNCINDELAY_V_IN_DELAY(v)   BF_CS1(HDMI_FC_VSYNCINDELAY, V_IN_DELAY, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSYNCINWIDTH - Frame Composer Input Video VSync Width Register (RW)
 *
 * Address Offset: 0x100D  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char V_IN_WIDTH : 6; //!< Value after Reset: 000000b Input video Vsync active pulse width: Integer number of pixel clock cycles [0...63].
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_fc_vsyncinwidth_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSYNCINWIDTH register
 */
#define HW_HDMI_FC_VSYNCINWIDTH_ADDR      (REGS_HDMI_BASE + 0x100d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSYNCINWIDTH           (*(volatile hw_hdmi_fc_vsyncinwidth_t *) HW_HDMI_FC_VSYNCINWIDTH_ADDR)
#define HW_HDMI_FC_VSYNCINWIDTH_RD()      (HW_HDMI_FC_VSYNCINWIDTH.U)
#define HW_HDMI_FC_VSYNCINWIDTH_WR(v)     (HW_HDMI_FC_VSYNCINWIDTH.U = (v))
#define HW_HDMI_FC_VSYNCINWIDTH_SET(v)    (HW_HDMI_FC_VSYNCINWIDTH_WR(HW_HDMI_FC_VSYNCINWIDTH_RD() |  (v)))
#define HW_HDMI_FC_VSYNCINWIDTH_CLR(v)    (HW_HDMI_FC_VSYNCINWIDTH_WR(HW_HDMI_FC_VSYNCINWIDTH_RD() & ~(v)))
#define HW_HDMI_FC_VSYNCINWIDTH_TOG(v)    (HW_HDMI_FC_VSYNCINWIDTH_WR(HW_HDMI_FC_VSYNCINWIDTH_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSYNCINWIDTH bitfields
 */

/* --- Register HW_HDMI_FC_VSYNCINWIDTH, field V_IN_WIDTH (RW)
 *
 * Value after Reset: 000000b Input video Vsync active pulse width: Integer number of pixel clock
 * cycles [0...63].
 */

#define BP_HDMI_FC_VSYNCINWIDTH_V_IN_WIDTH      0
#define BM_HDMI_FC_VSYNCINWIDTH_V_IN_WIDTH      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_VSYNCINWIDTH_V_IN_WIDTH(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_VSYNCINWIDTH_V_IN_WIDTH)
#else
#define BF_HDMI_FC_VSYNCINWIDTH_V_IN_WIDTH(v)   (((v) << 0) & BM_HDMI_FC_VSYNCINWIDTH_V_IN_WIDTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the V_IN_WIDTH field to a new value.
#define BW_HDMI_FC_VSYNCINWIDTH_V_IN_WIDTH(v)   BF_CS1(HDMI_FC_VSYNCINWIDTH, V_IN_WIDTH, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INFREQ0 - Frame Composer Input Video Refresh Rate Register 0 (RW)
 *
 * Address Offset: 0x100E  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INFREQ : 8; //!< Video refresh rate in Hz*1E3 format. This registers are provided for debug and informative purposes. No data is written to this registers by the H13TCTRL and the data here written by software is not used in any way by the H13TCTRL.
    } B;
} hw_hdmi_fc_infreq0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INFREQ0 register
 */
#define HW_HDMI_FC_INFREQ0_ADDR      (REGS_HDMI_BASE + 0x100e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INFREQ0           (*(volatile hw_hdmi_fc_infreq0_t *) HW_HDMI_FC_INFREQ0_ADDR)
#define HW_HDMI_FC_INFREQ0_RD()      (HW_HDMI_FC_INFREQ0.U)
#define HW_HDMI_FC_INFREQ0_WR(v)     (HW_HDMI_FC_INFREQ0.U = (v))
#define HW_HDMI_FC_INFREQ0_SET(v)    (HW_HDMI_FC_INFREQ0_WR(HW_HDMI_FC_INFREQ0_RD() |  (v)))
#define HW_HDMI_FC_INFREQ0_CLR(v)    (HW_HDMI_FC_INFREQ0_WR(HW_HDMI_FC_INFREQ0_RD() & ~(v)))
#define HW_HDMI_FC_INFREQ0_TOG(v)    (HW_HDMI_FC_INFREQ0_WR(HW_HDMI_FC_INFREQ0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INFREQ0 bitfields
 */

/* --- Register HW_HDMI_FC_INFREQ0, field INFREQ (RW)
 *
 * Video refresh rate in Hz*1E3 format. This registers are provided for debug and informative
 * purposes. No data is written to this registers by the H13TCTRL and the data here written by
 * software is not used in any way by the H13TCTRL.
 */

#define BP_HDMI_FC_INFREQ0_INFREQ      0
#define BM_HDMI_FC_INFREQ0_INFREQ      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INFREQ0_INFREQ(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INFREQ0_INFREQ)
#else
#define BF_HDMI_FC_INFREQ0_INFREQ(v)   (((v) << 0) & BM_HDMI_FC_INFREQ0_INFREQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INFREQ field to a new value.
#define BW_HDMI_FC_INFREQ0_INFREQ(v)   BF_CS1(HDMI_FC_INFREQ0, INFREQ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INFREQ1 - Frame Composer Input Video Refresh Rate Register 1 (RW)
 *
 * Address Offset: 0x100F  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INFREQ : 8; //!< Video refresh rate in Hz*1E3 format. This registers are provided for debug and informative purposes. No data is written to this registers by the H13TCTRL and the data here written by software is not used in any way by the H13TCTRL.
    } B;
} hw_hdmi_fc_infreq1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INFREQ1 register
 */
#define HW_HDMI_FC_INFREQ1_ADDR      (REGS_HDMI_BASE + 0x100f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INFREQ1           (*(volatile hw_hdmi_fc_infreq1_t *) HW_HDMI_FC_INFREQ1_ADDR)
#define HW_HDMI_FC_INFREQ1_RD()      (HW_HDMI_FC_INFREQ1.U)
#define HW_HDMI_FC_INFREQ1_WR(v)     (HW_HDMI_FC_INFREQ1.U = (v))
#define HW_HDMI_FC_INFREQ1_SET(v)    (HW_HDMI_FC_INFREQ1_WR(HW_HDMI_FC_INFREQ1_RD() |  (v)))
#define HW_HDMI_FC_INFREQ1_CLR(v)    (HW_HDMI_FC_INFREQ1_WR(HW_HDMI_FC_INFREQ1_RD() & ~(v)))
#define HW_HDMI_FC_INFREQ1_TOG(v)    (HW_HDMI_FC_INFREQ1_WR(HW_HDMI_FC_INFREQ1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INFREQ1 bitfields
 */

/* --- Register HW_HDMI_FC_INFREQ1, field INFREQ (RW)
 *
 * Video refresh rate in Hz*1E3 format. This registers are provided for debug and informative
 * purposes. No data is written to this registers by the H13TCTRL and the data here written by
 * software is not used in any way by the H13TCTRL.
 */

#define BP_HDMI_FC_INFREQ1_INFREQ      0
#define BM_HDMI_FC_INFREQ1_INFREQ      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INFREQ1_INFREQ(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INFREQ1_INFREQ)
#else
#define BF_HDMI_FC_INFREQ1_INFREQ(v)   (((v) << 0) & BM_HDMI_FC_INFREQ1_INFREQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INFREQ field to a new value.
#define BW_HDMI_FC_INFREQ1_INFREQ(v)   BF_CS1(HDMI_FC_INFREQ1, INFREQ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INFREQ2 - Frame Composer Input Video Refresh Rate Register 2 (RW)
 *
 * Address Offset: 0x1010  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INFREQ : 4; //!< Video refresh rate in Hz*1E3 format. This registers are provided for debug and informative purposes. No data is written to this registers by the H13TCTRL and the data here written by software is not used in any way by the H13TCTRL. Value after Reset: 0000b
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_infreq2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INFREQ2 register
 */
#define HW_HDMI_FC_INFREQ2_ADDR      (REGS_HDMI_BASE + 0x1010)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INFREQ2           (*(volatile hw_hdmi_fc_infreq2_t *) HW_HDMI_FC_INFREQ2_ADDR)
#define HW_HDMI_FC_INFREQ2_RD()      (HW_HDMI_FC_INFREQ2.U)
#define HW_HDMI_FC_INFREQ2_WR(v)     (HW_HDMI_FC_INFREQ2.U = (v))
#define HW_HDMI_FC_INFREQ2_SET(v)    (HW_HDMI_FC_INFREQ2_WR(HW_HDMI_FC_INFREQ2_RD() |  (v)))
#define HW_HDMI_FC_INFREQ2_CLR(v)    (HW_HDMI_FC_INFREQ2_WR(HW_HDMI_FC_INFREQ2_RD() & ~(v)))
#define HW_HDMI_FC_INFREQ2_TOG(v)    (HW_HDMI_FC_INFREQ2_WR(HW_HDMI_FC_INFREQ2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INFREQ2 bitfields
 */

/* --- Register HW_HDMI_FC_INFREQ2, field INFREQ (RW)
 *
 * Video refresh rate in Hz*1E3 format. This registers are provided for debug and informative
 * purposes. No data is written to this registers by the H13TCTRL and the data here written by
 * software is not used in any way by the H13TCTRL. Value after Reset: 0000b
 */

#define BP_HDMI_FC_INFREQ2_INFREQ      0
#define BM_HDMI_FC_INFREQ2_INFREQ      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INFREQ2_INFREQ(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INFREQ2_INFREQ)
#else
#define BF_HDMI_FC_INFREQ2_INFREQ(v)   (((v) << 0) & BM_HDMI_FC_INFREQ2_INFREQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INFREQ field to a new value.
#define BW_HDMI_FC_INFREQ2_INFREQ(v)   BF_CS1(HDMI_FC_INFREQ2, INFREQ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_CTRLDUR - Frame Composer Control Period Duration Register (RW)
 *
 * Address Offset: 0x1011  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CTRLPERIODDURATION : 8; //!< Configuration of the control period minimum duration (min. of 12 pixel clock cycles, refer to HDMI 1.4a specification). Integer number of pixel clocks cycles [0..255].
    } B;
} hw_hdmi_fc_ctrldur_t;
#endif

/*
 * constants & macros for entire HDMI_FC_CTRLDUR register
 */
#define HW_HDMI_FC_CTRLDUR_ADDR      (REGS_HDMI_BASE + 0x1011)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_CTRLDUR           (*(volatile hw_hdmi_fc_ctrldur_t *) HW_HDMI_FC_CTRLDUR_ADDR)
#define HW_HDMI_FC_CTRLDUR_RD()      (HW_HDMI_FC_CTRLDUR.U)
#define HW_HDMI_FC_CTRLDUR_WR(v)     (HW_HDMI_FC_CTRLDUR.U = (v))
#define HW_HDMI_FC_CTRLDUR_SET(v)    (HW_HDMI_FC_CTRLDUR_WR(HW_HDMI_FC_CTRLDUR_RD() |  (v)))
#define HW_HDMI_FC_CTRLDUR_CLR(v)    (HW_HDMI_FC_CTRLDUR_WR(HW_HDMI_FC_CTRLDUR_RD() & ~(v)))
#define HW_HDMI_FC_CTRLDUR_TOG(v)    (HW_HDMI_FC_CTRLDUR_WR(HW_HDMI_FC_CTRLDUR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_CTRLDUR bitfields
 */

/* --- Register HW_HDMI_FC_CTRLDUR, field CTRLPERIODDURATION (RW)
 *
 * Configuration of the control period minimum duration (min. of 12 pixel clock cycles, refer to
 * HDMI 1.4a specification). Integer number of pixel clocks cycles [0..255].
 */

#define BP_HDMI_FC_CTRLDUR_CTRLPERIODDURATION      0
#define BM_HDMI_FC_CTRLDUR_CTRLPERIODDURATION      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_CTRLDUR_CTRLPERIODDURATION(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_CTRLDUR_CTRLPERIODDURATION)
#else
#define BF_HDMI_FC_CTRLDUR_CTRLPERIODDURATION(v)   (((v) << 0) & BM_HDMI_FC_CTRLDUR_CTRLPERIODDURATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTRLPERIODDURATION field to a new value.
#define BW_HDMI_FC_CTRLDUR_CTRLPERIODDURATION(v)   BF_CS1(HDMI_FC_CTRLDUR, CTRLPERIODDURATION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_EXCTRLDUR - Frame Composer Extended Control Period Duration Register (RW)
 *
 * Address Offset: 0x1012  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char EXCTRLPERIODDURATION : 8; //!< Configuration of the extended control period minimum duration (min. of 32 pixel clock cycles, see HDMI 1.4a specification). Integer number of pixel clocks cycles [0..255].
    } B;
} hw_hdmi_fc_exctrldur_t;
#endif

/*
 * constants & macros for entire HDMI_FC_EXCTRLDUR register
 */
#define HW_HDMI_FC_EXCTRLDUR_ADDR      (REGS_HDMI_BASE + 0x1012)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_EXCTRLDUR           (*(volatile hw_hdmi_fc_exctrldur_t *) HW_HDMI_FC_EXCTRLDUR_ADDR)
#define HW_HDMI_FC_EXCTRLDUR_RD()      (HW_HDMI_FC_EXCTRLDUR.U)
#define HW_HDMI_FC_EXCTRLDUR_WR(v)     (HW_HDMI_FC_EXCTRLDUR.U = (v))
#define HW_HDMI_FC_EXCTRLDUR_SET(v)    (HW_HDMI_FC_EXCTRLDUR_WR(HW_HDMI_FC_EXCTRLDUR_RD() |  (v)))
#define HW_HDMI_FC_EXCTRLDUR_CLR(v)    (HW_HDMI_FC_EXCTRLDUR_WR(HW_HDMI_FC_EXCTRLDUR_RD() & ~(v)))
#define HW_HDMI_FC_EXCTRLDUR_TOG(v)    (HW_HDMI_FC_EXCTRLDUR_WR(HW_HDMI_FC_EXCTRLDUR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_EXCTRLDUR bitfields
 */

/* --- Register HW_HDMI_FC_EXCTRLDUR, field EXCTRLPERIODDURATION (RW)
 *
 * Configuration of the extended control period minimum duration (min. of 32 pixel clock cycles, see
 * HDMI 1.4a specification). Integer number of pixel clocks cycles [0..255].
 */

#define BP_HDMI_FC_EXCTRLDUR_EXCTRLPERIODDURATION      0
#define BM_HDMI_FC_EXCTRLDUR_EXCTRLPERIODDURATION      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_EXCTRLDUR_EXCTRLPERIODDURATION(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_EXCTRLDUR_EXCTRLPERIODDURATION)
#else
#define BF_HDMI_FC_EXCTRLDUR_EXCTRLPERIODDURATION(v)   (((v) << 0) & BM_HDMI_FC_EXCTRLDUR_EXCTRLPERIODDURATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EXCTRLPERIODDURATION field to a new value.
#define BW_HDMI_FC_EXCTRLDUR_EXCTRLPERIODDURATION(v)   BF_CS1(HDMI_FC_EXCTRLDUR, EXCTRLPERIODDURATION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_EXCTRLSPAC - Frame Composer Extended Control Period Maximum Spacing Register (RW)
 *
 * Address Offset: 0x1013  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char EXCTRLPERIODSPACING : 8; //!< Configuration of the maximum spacing between consecutive extended control periods (max of 50msec, see HDMI 1.4a specification): generated spacing = (1/freq tmds clock)*256*256*extctrlperiodspacing
    } B;
} hw_hdmi_fc_exctrlspac_t;
#endif

/*
 * constants & macros for entire HDMI_FC_EXCTRLSPAC register
 */
#define HW_HDMI_FC_EXCTRLSPAC_ADDR      (REGS_HDMI_BASE + 0x1013)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_EXCTRLSPAC           (*(volatile hw_hdmi_fc_exctrlspac_t *) HW_HDMI_FC_EXCTRLSPAC_ADDR)
#define HW_HDMI_FC_EXCTRLSPAC_RD()      (HW_HDMI_FC_EXCTRLSPAC.U)
#define HW_HDMI_FC_EXCTRLSPAC_WR(v)     (HW_HDMI_FC_EXCTRLSPAC.U = (v))
#define HW_HDMI_FC_EXCTRLSPAC_SET(v)    (HW_HDMI_FC_EXCTRLSPAC_WR(HW_HDMI_FC_EXCTRLSPAC_RD() |  (v)))
#define HW_HDMI_FC_EXCTRLSPAC_CLR(v)    (HW_HDMI_FC_EXCTRLSPAC_WR(HW_HDMI_FC_EXCTRLSPAC_RD() & ~(v)))
#define HW_HDMI_FC_EXCTRLSPAC_TOG(v)    (HW_HDMI_FC_EXCTRLSPAC_WR(HW_HDMI_FC_EXCTRLSPAC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_EXCTRLSPAC bitfields
 */

/* --- Register HW_HDMI_FC_EXCTRLSPAC, field EXCTRLPERIODSPACING (RW)
 *
 * Configuration of the maximum spacing between consecutive extended control periods (max of 50msec,
 * see HDMI 1.4a specification): generated spacing = (1/freq tmds
 * clock)*256*256*extctrlperiodspacing
 */

#define BP_HDMI_FC_EXCTRLSPAC_EXCTRLPERIODSPACING      0
#define BM_HDMI_FC_EXCTRLSPAC_EXCTRLPERIODSPACING      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_EXCTRLSPAC_EXCTRLPERIODSPACING(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_EXCTRLSPAC_EXCTRLPERIODSPACING)
#else
#define BF_HDMI_FC_EXCTRLSPAC_EXCTRLPERIODSPACING(v)   (((v) << 0) & BM_HDMI_FC_EXCTRLSPAC_EXCTRLPERIODSPACING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EXCTRLPERIODSPACING field to a new value.
#define BW_HDMI_FC_EXCTRLSPAC_EXCTRLPERIODSPACING(v)   BF_CS1(HDMI_FC_EXCTRLSPAC, EXCTRLPERIODSPACING, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_CH0PREAM - Frame Composer Channel 0 Non-Preamble Data Register (RW)
 *
 * Address Offset: 0x1014  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CH0_PREAMBLE_FILTER : 8; //!< When in control mode, configures 8-bits that are going to fill the channel 0 data lines not used to transmit the preamble (for more clarifications refer to HDMI 1.4a specification).
    } B;
} hw_hdmi_fc_ch0pream_t;
#endif

/*
 * constants & macros for entire HDMI_FC_CH0PREAM register
 */
#define HW_HDMI_FC_CH0PREAM_ADDR      (REGS_HDMI_BASE + 0x1014)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_CH0PREAM           (*(volatile hw_hdmi_fc_ch0pream_t *) HW_HDMI_FC_CH0PREAM_ADDR)
#define HW_HDMI_FC_CH0PREAM_RD()      (HW_HDMI_FC_CH0PREAM.U)
#define HW_HDMI_FC_CH0PREAM_WR(v)     (HW_HDMI_FC_CH0PREAM.U = (v))
#define HW_HDMI_FC_CH0PREAM_SET(v)    (HW_HDMI_FC_CH0PREAM_WR(HW_HDMI_FC_CH0PREAM_RD() |  (v)))
#define HW_HDMI_FC_CH0PREAM_CLR(v)    (HW_HDMI_FC_CH0PREAM_WR(HW_HDMI_FC_CH0PREAM_RD() & ~(v)))
#define HW_HDMI_FC_CH0PREAM_TOG(v)    (HW_HDMI_FC_CH0PREAM_WR(HW_HDMI_FC_CH0PREAM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_CH0PREAM bitfields
 */

/* --- Register HW_HDMI_FC_CH0PREAM, field CH0_PREAMBLE_FILTER (RW)
 *
 * When in control mode, configures 8-bits that are going to fill the channel 0 data lines not used
 * to transmit the preamble (for more clarifications refer to HDMI 1.4a specification).
 */

#define BP_HDMI_FC_CH0PREAM_CH0_PREAMBLE_FILTER      0
#define BM_HDMI_FC_CH0PREAM_CH0_PREAMBLE_FILTER      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_CH0PREAM_CH0_PREAMBLE_FILTER(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_CH0PREAM_CH0_PREAMBLE_FILTER)
#else
#define BF_HDMI_FC_CH0PREAM_CH0_PREAMBLE_FILTER(v)   (((v) << 0) & BM_HDMI_FC_CH0PREAM_CH0_PREAMBLE_FILTER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0_PREAMBLE_FILTER field to a new value.
#define BW_HDMI_FC_CH0PREAM_CH0_PREAMBLE_FILTER(v)   BF_CS1(HDMI_FC_CH0PREAM, CH0_PREAMBLE_FILTER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_CH1PREAM - Frame Composer Channel 1 Non-Preamble Data Register (RW)
 *
 * Address Offset: 0x1015  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CH1_PREAMBLE_FILTER : 6; //!< When in control mode, configures 6-bits that are going to fill the channel 1 data lines not used to transmit the preamble (for more clarifications refer to HDMI 1.4a specification).
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_fc_ch1pream_t;
#endif

/*
 * constants & macros for entire HDMI_FC_CH1PREAM register
 */
#define HW_HDMI_FC_CH1PREAM_ADDR      (REGS_HDMI_BASE + 0x1015)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_CH1PREAM           (*(volatile hw_hdmi_fc_ch1pream_t *) HW_HDMI_FC_CH1PREAM_ADDR)
#define HW_HDMI_FC_CH1PREAM_RD()      (HW_HDMI_FC_CH1PREAM.U)
#define HW_HDMI_FC_CH1PREAM_WR(v)     (HW_HDMI_FC_CH1PREAM.U = (v))
#define HW_HDMI_FC_CH1PREAM_SET(v)    (HW_HDMI_FC_CH1PREAM_WR(HW_HDMI_FC_CH1PREAM_RD() |  (v)))
#define HW_HDMI_FC_CH1PREAM_CLR(v)    (HW_HDMI_FC_CH1PREAM_WR(HW_HDMI_FC_CH1PREAM_RD() & ~(v)))
#define HW_HDMI_FC_CH1PREAM_TOG(v)    (HW_HDMI_FC_CH1PREAM_WR(HW_HDMI_FC_CH1PREAM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_CH1PREAM bitfields
 */

/* --- Register HW_HDMI_FC_CH1PREAM, field CH1_PREAMBLE_FILTER (RW)
 *
 * When in control mode, configures 6-bits that are going to fill the channel 1 data lines not used
 * to transmit the preamble (for more clarifications refer to HDMI 1.4a specification).
 */

#define BP_HDMI_FC_CH1PREAM_CH1_PREAMBLE_FILTER      0
#define BM_HDMI_FC_CH1PREAM_CH1_PREAMBLE_FILTER      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_CH1PREAM_CH1_PREAMBLE_FILTER(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_CH1PREAM_CH1_PREAMBLE_FILTER)
#else
#define BF_HDMI_FC_CH1PREAM_CH1_PREAMBLE_FILTER(v)   (((v) << 0) & BM_HDMI_FC_CH1PREAM_CH1_PREAMBLE_FILTER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH1_PREAMBLE_FILTER field to a new value.
#define BW_HDMI_FC_CH1PREAM_CH1_PREAMBLE_FILTER(v)   BF_CS1(HDMI_FC_CH1PREAM, CH1_PREAMBLE_FILTER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_CH2PREAM - Frame Composer Channel 2 Non-Preamble Data Register (RW)
 *
 * Address Offset: 0x1016  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CH2_PREAMBLE_FILTER : 6; //!< When in control mode, configures 6-bits that are going to fill the channel 2 data lines not used to transmit the preamble (for more clarifications, see HDMI 1.4a specification).
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_fc_ch2pream_t;
#endif

/*
 * constants & macros for entire HDMI_FC_CH2PREAM register
 */
#define HW_HDMI_FC_CH2PREAM_ADDR      (REGS_HDMI_BASE + 0x1016)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_CH2PREAM           (*(volatile hw_hdmi_fc_ch2pream_t *) HW_HDMI_FC_CH2PREAM_ADDR)
#define HW_HDMI_FC_CH2PREAM_RD()      (HW_HDMI_FC_CH2PREAM.U)
#define HW_HDMI_FC_CH2PREAM_WR(v)     (HW_HDMI_FC_CH2PREAM.U = (v))
#define HW_HDMI_FC_CH2PREAM_SET(v)    (HW_HDMI_FC_CH2PREAM_WR(HW_HDMI_FC_CH2PREAM_RD() |  (v)))
#define HW_HDMI_FC_CH2PREAM_CLR(v)    (HW_HDMI_FC_CH2PREAM_WR(HW_HDMI_FC_CH2PREAM_RD() & ~(v)))
#define HW_HDMI_FC_CH2PREAM_TOG(v)    (HW_HDMI_FC_CH2PREAM_WR(HW_HDMI_FC_CH2PREAM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_CH2PREAM bitfields
 */

/* --- Register HW_HDMI_FC_CH2PREAM, field CH2_PREAMBLE_FILTER (RW)
 *
 * When in control mode, configures 6-bits that are going to fill the channel 2 data lines not used
 * to transmit the preamble (for more clarifications, see HDMI 1.4a specification).
 */

#define BP_HDMI_FC_CH2PREAM_CH2_PREAMBLE_FILTER      0
#define BM_HDMI_FC_CH2PREAM_CH2_PREAMBLE_FILTER      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_CH2PREAM_CH2_PREAMBLE_FILTER(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_CH2PREAM_CH2_PREAMBLE_FILTER)
#else
#define BF_HDMI_FC_CH2PREAM_CH2_PREAMBLE_FILTER(v)   (((v) << 0) & BM_HDMI_FC_CH2PREAM_CH2_PREAMBLE_FILTER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH2_PREAMBLE_FILTER field to a new value.
#define BW_HDMI_FC_CH2PREAM_CH2_PREAMBLE_FILTER(v)   BF_CS1(HDMI_FC_CH2PREAM, CH2_PREAMBLE_FILTER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVICONF3 - Frame Composer AVI Configuration Register 3 (RW)
 *
 * Address Offset: 0x1017  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write   configuration
 * of Quantization range and IT content type.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CN1 : 2; //!< IT content type according to CEA specification
        unsigned char YQ1 : 2; //!< Quantization range according to CEA specification.
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_aviconf3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVICONF3 register
 */
#define HW_HDMI_FC_AVICONF3_ADDR      (REGS_HDMI_BASE + 0x1017)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVICONF3           (*(volatile hw_hdmi_fc_aviconf3_t *) HW_HDMI_FC_AVICONF3_ADDR)
#define HW_HDMI_FC_AVICONF3_RD()      (HW_HDMI_FC_AVICONF3.U)
#define HW_HDMI_FC_AVICONF3_WR(v)     (HW_HDMI_FC_AVICONF3.U = (v))
#define HW_HDMI_FC_AVICONF3_SET(v)    (HW_HDMI_FC_AVICONF3_WR(HW_HDMI_FC_AVICONF3_RD() |  (v)))
#define HW_HDMI_FC_AVICONF3_CLR(v)    (HW_HDMI_FC_AVICONF3_WR(HW_HDMI_FC_AVICONF3_RD() & ~(v)))
#define HW_HDMI_FC_AVICONF3_TOG(v)    (HW_HDMI_FC_AVICONF3_WR(HW_HDMI_FC_AVICONF3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVICONF3 bitfields
 */

/* --- Register HW_HDMI_FC_AVICONF3, field CN1 (RW)
 *
 * IT content type according to CEA specification
 */

#define BP_HDMI_FC_AVICONF3_CN1      0
#define BM_HDMI_FC_AVICONF3_CN1      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF3_CN1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVICONF3_CN1)
#else
#define BF_HDMI_FC_AVICONF3_CN1(v)   (((v) << 0) & BM_HDMI_FC_AVICONF3_CN1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CN1 field to a new value.
#define BW_HDMI_FC_AVICONF3_CN1(v)   BF_CS1(HDMI_FC_AVICONF3, CN1, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF3, field YQ1 (RW)
 *
 * Quantization range according to CEA specification.
 */

#define BP_HDMI_FC_AVICONF3_YQ1      2
#define BM_HDMI_FC_AVICONF3_YQ1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF3_YQ1(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_AVICONF3_YQ1)
#else
#define BF_HDMI_FC_AVICONF3_YQ1(v)   (((v) << 2) & BM_HDMI_FC_AVICONF3_YQ1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the YQ1 field to a new value.
#define BW_HDMI_FC_AVICONF3_YQ1(v)   BF_CS1(HDMI_FC_AVICONF3, YQ1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GCP - Frame Composer GCP Packet Configuration Register (RW)
 *
 * Configures the General Control Packet A/V mute indicators and the default phase.   Address
 * Offset: 0x1018  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CLEAR_AVMUTE : 1; //!< Value of "clear_avmute" in the GCP packet. Value after Reset: 0b
        unsigned char SET_AVMUTE : 1; //!< Value of "set_avmute" in the GCP packet. Value after Reset: 0b
        unsigned char DEFAULT_PHASE : 1; //!< Value of "default_phase" in the GCP packet. This data should be equal to the default phase used at Video packetizer packing machine. Value after Reset: 0b
        unsigned char RESERVED0 : 5; //!< Reserved
    } B;
} hw_hdmi_fc_gcp_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GCP register
 */
#define HW_HDMI_FC_GCP_ADDR      (REGS_HDMI_BASE + 0x1018)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GCP           (*(volatile hw_hdmi_fc_gcp_t *) HW_HDMI_FC_GCP_ADDR)
#define HW_HDMI_FC_GCP_RD()      (HW_HDMI_FC_GCP.U)
#define HW_HDMI_FC_GCP_WR(v)     (HW_HDMI_FC_GCP.U = (v))
#define HW_HDMI_FC_GCP_SET(v)    (HW_HDMI_FC_GCP_WR(HW_HDMI_FC_GCP_RD() |  (v)))
#define HW_HDMI_FC_GCP_CLR(v)    (HW_HDMI_FC_GCP_WR(HW_HDMI_FC_GCP_RD() & ~(v)))
#define HW_HDMI_FC_GCP_TOG(v)    (HW_HDMI_FC_GCP_WR(HW_HDMI_FC_GCP_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GCP bitfields
 */

/* --- Register HW_HDMI_FC_GCP, field CLEAR_AVMUTE (RW)
 *
 * Value of "clear_avmute" in the GCP packet. Value after Reset: 0b
 */

#define BP_HDMI_FC_GCP_CLEAR_AVMUTE      0
#define BM_HDMI_FC_GCP_CLEAR_AVMUTE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GCP_CLEAR_AVMUTE(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GCP_CLEAR_AVMUTE)
#else
#define BF_HDMI_FC_GCP_CLEAR_AVMUTE(v)   (((v) << 0) & BM_HDMI_FC_GCP_CLEAR_AVMUTE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLEAR_AVMUTE field to a new value.
#define BW_HDMI_FC_GCP_CLEAR_AVMUTE(v)   BF_CS1(HDMI_FC_GCP, CLEAR_AVMUTE, v)
#endif

/* --- Register HW_HDMI_FC_GCP, field SET_AVMUTE (RW)
 *
 * Value of "set_avmute" in the GCP packet. Value after Reset: 0b
 */

#define BP_HDMI_FC_GCP_SET_AVMUTE      1
#define BM_HDMI_FC_GCP_SET_AVMUTE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GCP_SET_AVMUTE(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_GCP_SET_AVMUTE)
#else
#define BF_HDMI_FC_GCP_SET_AVMUTE(v)   (((v) << 1) & BM_HDMI_FC_GCP_SET_AVMUTE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SET_AVMUTE field to a new value.
#define BW_HDMI_FC_GCP_SET_AVMUTE(v)   BF_CS1(HDMI_FC_GCP, SET_AVMUTE, v)
#endif

/* --- Register HW_HDMI_FC_GCP, field DEFAULT_PHASE (RW)
 *
 * Value of "default_phase" in the GCP packet. This data should be equal to the default phase used
 * at Video packetizer packing machine. Value after Reset: 0b
 */

#define BP_HDMI_FC_GCP_DEFAULT_PHASE      2
#define BM_HDMI_FC_GCP_DEFAULT_PHASE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GCP_DEFAULT_PHASE(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_GCP_DEFAULT_PHASE)
#else
#define BF_HDMI_FC_GCP_DEFAULT_PHASE(v)   (((v) << 2) & BM_HDMI_FC_GCP_DEFAULT_PHASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DEFAULT_PHASE field to a new value.
#define BW_HDMI_FC_GCP_DEFAULT_PHASE(v)   BF_CS1(HDMI_FC_GCP, DEFAULT_PHASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVICONF0 - Frame Composer AVI Packet Configuration Register 0 (RW)
 *
 * Configures the following contents of the AVI infoFrame:   RGB/YCC indication  Bar information
 * Scan information  Active format present  Progressive/Interlaced indicator  Active aspect ratio
 * Picture aspect ratio  Colorimetry  IT content  Extended colorimetry  Quantization range  Non-
 * uniform picture scaling   For more information, refer to HDMI 1.4a and CEA - 861D specifications.
 * Address Offset: 0x1019  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVICONF0 : 2; //!< RGB/YCC indication Value after Reset: 0b
        unsigned char FC_AVICONF01 : 2; //!< Bar information
        unsigned char FC_AVICONF02 : 2; //!< Scan information
        unsigned char FC_AVICONF03 : 1; //!< Active format present
        unsigned char FC_AVICONF04 : 1; //!< ?
    } B;
} hw_hdmi_fc_aviconf0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVICONF0 register
 */
#define HW_HDMI_FC_AVICONF0_ADDR      (REGS_HDMI_BASE + 0x1019)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVICONF0           (*(volatile hw_hdmi_fc_aviconf0_t *) HW_HDMI_FC_AVICONF0_ADDR)
#define HW_HDMI_FC_AVICONF0_RD()      (HW_HDMI_FC_AVICONF0.U)
#define HW_HDMI_FC_AVICONF0_WR(v)     (HW_HDMI_FC_AVICONF0.U = (v))
#define HW_HDMI_FC_AVICONF0_SET(v)    (HW_HDMI_FC_AVICONF0_WR(HW_HDMI_FC_AVICONF0_RD() |  (v)))
#define HW_HDMI_FC_AVICONF0_CLR(v)    (HW_HDMI_FC_AVICONF0_WR(HW_HDMI_FC_AVICONF0_RD() & ~(v)))
#define HW_HDMI_FC_AVICONF0_TOG(v)    (HW_HDMI_FC_AVICONF0_WR(HW_HDMI_FC_AVICONF0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVICONF0 bitfields
 */

/* --- Register HW_HDMI_FC_AVICONF0, field FC_AVICONF0 (RW)
 *
 * RGB/YCC indication Value after Reset: 0b
 */

#define BP_HDMI_FC_AVICONF0_FC_AVICONF0      0
#define BM_HDMI_FC_AVICONF0_FC_AVICONF0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#else
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   (((v) << 0) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF0 field to a new value.
#define BW_HDMI_FC_AVICONF0_FC_AVICONF0(v)   BF_CS1(HDMI_FC_AVICONF0, FC_AVICONF0, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF0, field FC_AVICONF0 (RW)
 *
 * Bar information
 */

#define BP_HDMI_FC_AVICONF0_FC_AVICONF0      2
#define BM_HDMI_FC_AVICONF0_FC_AVICONF0      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#else
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   (((v) << 2) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF0 field to a new value.
#define BW_HDMI_FC_AVICONF0_FC_AVICONF0(v)   BF_CS1(HDMI_FC_AVICONF0, FC_AVICONF0, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF0, field FC_AVICONF0 (RW)
 *
 * Scan information
 */

#define BP_HDMI_FC_AVICONF0_FC_AVICONF0      4
#define BM_HDMI_FC_AVICONF0_FC_AVICONF0      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#else
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   (((v) << 4) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF0 field to a new value.
#define BW_HDMI_FC_AVICONF0_FC_AVICONF0(v)   BF_CS1(HDMI_FC_AVICONF0, FC_AVICONF0, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF0, field FC_AVICONF0 (RW)
 *
 * Active format present
 */

#define BP_HDMI_FC_AVICONF0_FC_AVICONF0      6
#define BM_HDMI_FC_AVICONF0_FC_AVICONF0      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#else
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   (((v) << 6) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF0 field to a new value.
#define BW_HDMI_FC_AVICONF0_FC_AVICONF0(v)   BF_CS1(HDMI_FC_AVICONF0, FC_AVICONF0, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF0, field FC_AVICONF0 (RW)
 *
 * ?
 */

#define BP_HDMI_FC_AVICONF0_FC_AVICONF0      7
#define BM_HDMI_FC_AVICONF0_FC_AVICONF0      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#else
#define BF_HDMI_FC_AVICONF0_FC_AVICONF0(v)   (((v) << 7) & BM_HDMI_FC_AVICONF0_FC_AVICONF0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF0 field to a new value.
#define BW_HDMI_FC_AVICONF0_FC_AVICONF0(v)   BF_CS1(HDMI_FC_AVICONF0, FC_AVICONF0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVICONF1 - Frame Composer AVI Packet Configuration Register 1 (RW)
 *
 * Address Offset: 0x101A  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVICONF1 : 4; //!< Active aspect ratio Value after Reset: 0b
        unsigned char FC_AVICONF11 : 2; //!< Picture aspect ratio
        unsigned char FC_AVICONF0 : 2; //!< Colorimetry
    } B;
} hw_hdmi_fc_aviconf1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVICONF1 register
 */
#define HW_HDMI_FC_AVICONF1_ADDR      (REGS_HDMI_BASE + 0x101a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVICONF1           (*(volatile hw_hdmi_fc_aviconf1_t *) HW_HDMI_FC_AVICONF1_ADDR)
#define HW_HDMI_FC_AVICONF1_RD()      (HW_HDMI_FC_AVICONF1.U)
#define HW_HDMI_FC_AVICONF1_WR(v)     (HW_HDMI_FC_AVICONF1.U = (v))
#define HW_HDMI_FC_AVICONF1_SET(v)    (HW_HDMI_FC_AVICONF1_WR(HW_HDMI_FC_AVICONF1_RD() |  (v)))
#define HW_HDMI_FC_AVICONF1_CLR(v)    (HW_HDMI_FC_AVICONF1_WR(HW_HDMI_FC_AVICONF1_RD() & ~(v)))
#define HW_HDMI_FC_AVICONF1_TOG(v)    (HW_HDMI_FC_AVICONF1_WR(HW_HDMI_FC_AVICONF1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVICONF1 bitfields
 */

/* --- Register HW_HDMI_FC_AVICONF1, field FC_AVICONF1 (RW)
 *
 * Active aspect ratio Value after Reset: 0b
 */

#define BP_HDMI_FC_AVICONF1_FC_AVICONF1      0
#define BM_HDMI_FC_AVICONF1_FC_AVICONF1      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF1_FC_AVICONF1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVICONF1_FC_AVICONF1)
#else
#define BF_HDMI_FC_AVICONF1_FC_AVICONF1(v)   (((v) << 0) & BM_HDMI_FC_AVICONF1_FC_AVICONF1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF1 field to a new value.
#define BW_HDMI_FC_AVICONF1_FC_AVICONF1(v)   BF_CS1(HDMI_FC_AVICONF1, FC_AVICONF1, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF1, field FC_AVICONF1 (RW)
 *
 * Picture aspect ratio
 */

#define BP_HDMI_FC_AVICONF1_FC_AVICONF1      4
#define BM_HDMI_FC_AVICONF1_FC_AVICONF1      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF1_FC_AVICONF1(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_AVICONF1_FC_AVICONF1)
#else
#define BF_HDMI_FC_AVICONF1_FC_AVICONF1(v)   (((v) << 4) & BM_HDMI_FC_AVICONF1_FC_AVICONF1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF1 field to a new value.
#define BW_HDMI_FC_AVICONF1_FC_AVICONF1(v)   BF_CS1(HDMI_FC_AVICONF1, FC_AVICONF1, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF1, field FC_AVICONF0 (RW)
 *
 * Colorimetry
 */

#define BP_HDMI_FC_AVICONF1_FC_AVICONF0      6
#define BM_HDMI_FC_AVICONF1_FC_AVICONF0      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF1_FC_AVICONF0(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_AVICONF1_FC_AVICONF0)
#else
#define BF_HDMI_FC_AVICONF1_FC_AVICONF0(v)   (((v) << 6) & BM_HDMI_FC_AVICONF1_FC_AVICONF0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF0 field to a new value.
#define BW_HDMI_FC_AVICONF1_FC_AVICONF0(v)   BF_CS1(HDMI_FC_AVICONF1, FC_AVICONF0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVICONF2 - FC_AVICONFFrame Composer AVI Packet Configuration Register 2 (RW)
 *
 * Address Offset: 0x101B  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVICONF2 : 2; //!< Non-uniform picture scaling Value after Reset: 0b
        unsigned char RESERVED0 : 2; //!< Quantization range
        unsigned char FC_AVICONF21 : 3; //!< Extended colorimetry
        unsigned char FC_AVICONF22 : 1; //!< IT content
    } B;
} hw_hdmi_fc_aviconf2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVICONF2 register
 */
#define HW_HDMI_FC_AVICONF2_ADDR      (REGS_HDMI_BASE + 0x101b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVICONF2           (*(volatile hw_hdmi_fc_aviconf2_t *) HW_HDMI_FC_AVICONF2_ADDR)
#define HW_HDMI_FC_AVICONF2_RD()      (HW_HDMI_FC_AVICONF2.U)
#define HW_HDMI_FC_AVICONF2_WR(v)     (HW_HDMI_FC_AVICONF2.U = (v))
#define HW_HDMI_FC_AVICONF2_SET(v)    (HW_HDMI_FC_AVICONF2_WR(HW_HDMI_FC_AVICONF2_RD() |  (v)))
#define HW_HDMI_FC_AVICONF2_CLR(v)    (HW_HDMI_FC_AVICONF2_WR(HW_HDMI_FC_AVICONF2_RD() & ~(v)))
#define HW_HDMI_FC_AVICONF2_TOG(v)    (HW_HDMI_FC_AVICONF2_WR(HW_HDMI_FC_AVICONF2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVICONF2 bitfields
 */

/* --- Register HW_HDMI_FC_AVICONF2, field FC_AVICONF2 (RW)
 *
 * Non-uniform picture scaling Value after Reset: 0b
 */

#define BP_HDMI_FC_AVICONF2_FC_AVICONF2      0
#define BM_HDMI_FC_AVICONF2_FC_AVICONF2      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF2_FC_AVICONF2(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVICONF2_FC_AVICONF2)
#else
#define BF_HDMI_FC_AVICONF2_FC_AVICONF2(v)   (((v) << 0) & BM_HDMI_FC_AVICONF2_FC_AVICONF2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF2 field to a new value.
#define BW_HDMI_FC_AVICONF2_FC_AVICONF2(v)   BF_CS1(HDMI_FC_AVICONF2, FC_AVICONF2, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF2, field FC_AVICONF2 (RW)
 *
 * Extended colorimetry
 */

#define BP_HDMI_FC_AVICONF2_FC_AVICONF2      4
#define BM_HDMI_FC_AVICONF2_FC_AVICONF2      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF2_FC_AVICONF2(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_AVICONF2_FC_AVICONF2)
#else
#define BF_HDMI_FC_AVICONF2_FC_AVICONF2(v)   (((v) << 4) & BM_HDMI_FC_AVICONF2_FC_AVICONF2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF2 field to a new value.
#define BW_HDMI_FC_AVICONF2_FC_AVICONF2(v)   BF_CS1(HDMI_FC_AVICONF2, FC_AVICONF2, v)
#endif

/* --- Register HW_HDMI_FC_AVICONF2, field FC_AVICONF2 (RW)
 *
 * IT content
 */

#define BP_HDMI_FC_AVICONF2_FC_AVICONF2      7
#define BM_HDMI_FC_AVICONF2_FC_AVICONF2      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVICONF2_FC_AVICONF2(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_AVICONF2_FC_AVICONF2)
#else
#define BF_HDMI_FC_AVICONF2_FC_AVICONF2(v)   (((v) << 7) & BM_HDMI_FC_AVICONF2_FC_AVICONF2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVICONF2 field to a new value.
#define BW_HDMI_FC_AVICONF2_FC_AVICONF2(v)   BF_CS1(HDMI_FC_AVICONF2, FC_AVICONF2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVIVID - Frame Composer AVI Packet VIC Register (RW)
 *
 * Configures the AVI infoFrame Video Identification code. For more information, refer to the
 * CEA-861-E specification.   Address Offset: 0x101C  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVIVID : 8; //!< the AVI infoFrame Video Identification code.
    } B;
} hw_hdmi_fc_avivid_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVIVID register
 */
#define HW_HDMI_FC_AVIVID_ADDR      (REGS_HDMI_BASE + 0x101c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVIVID           (*(volatile hw_hdmi_fc_avivid_t *) HW_HDMI_FC_AVIVID_ADDR)
#define HW_HDMI_FC_AVIVID_RD()      (HW_HDMI_FC_AVIVID.U)
#define HW_HDMI_FC_AVIVID_WR(v)     (HW_HDMI_FC_AVIVID.U = (v))
#define HW_HDMI_FC_AVIVID_SET(v)    (HW_HDMI_FC_AVIVID_WR(HW_HDMI_FC_AVIVID_RD() |  (v)))
#define HW_HDMI_FC_AVIVID_CLR(v)    (HW_HDMI_FC_AVIVID_WR(HW_HDMI_FC_AVIVID_RD() & ~(v)))
#define HW_HDMI_FC_AVIVID_TOG(v)    (HW_HDMI_FC_AVIVID_WR(HW_HDMI_FC_AVIVID_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVIVID bitfields
 */

/* --- Register HW_HDMI_FC_AVIVID, field FC_AVIVID (RW)
 *
 * the AVI infoFrame Video Identification code.
 */

#define BP_HDMI_FC_AVIVID_FC_AVIVID      0
#define BM_HDMI_FC_AVIVID_FC_AVIVID      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVIVID_FC_AVIVID(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVIVID_FC_AVIVID)
#else
#define BF_HDMI_FC_AVIVID_FC_AVIVID(v)   (((v) << 0) & BM_HDMI_FC_AVIVID_FC_AVIVID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVIVID field to a new value.
#define BW_HDMI_FC_AVIVID_FC_AVIVID(v)   BF_CS1(HDMI_FC_AVIVID, FC_AVIVID, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVIETB0 - Frame Composer AVI Packet End of Top Bar Register 0 (RW)
 *
 * These registers define the AVI infoFrame End of Top Bar value. For more information, refer to
 * CEA-861-E specification.   Address Offset: 0x101D  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< Line number of end of top bar (lower 8 bits)
    } B;
} hw_hdmi_fc_avietb0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVIETB0 register
 */
#define HW_HDMI_FC_AVIETB0_ADDR      (REGS_HDMI_BASE + 0x101d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVIETB0           (*(volatile hw_hdmi_fc_avietb0_t *) HW_HDMI_FC_AVIETB0_ADDR)
#define HW_HDMI_FC_AVIETB0_RD()      (HW_HDMI_FC_AVIETB0.U)
#define HW_HDMI_FC_AVIETB0_WR(v)     (HW_HDMI_FC_AVIETB0.U = (v))
#define HW_HDMI_FC_AVIETB0_SET(v)    (HW_HDMI_FC_AVIETB0_WR(HW_HDMI_FC_AVIETB0_RD() |  (v)))
#define HW_HDMI_FC_AVIETB0_CLR(v)    (HW_HDMI_FC_AVIETB0_WR(HW_HDMI_FC_AVIETB0_RD() & ~(v)))
#define HW_HDMI_FC_AVIETB0_TOG(v)    (HW_HDMI_FC_AVIETB0_WR(HW_HDMI_FC_AVIETB0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVIETB0 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVIETB1 - Frame Composer AVI Packet End of Top Bar Register 1 (RW)
 *
 * Address Offset: 0x101E  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< Line number of end of top bar (upper 8 bits)
    } B;
} hw_hdmi_fc_avietb1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVIETB1 register
 */
#define HW_HDMI_FC_AVIETB1_ADDR      (REGS_HDMI_BASE + 0x101e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVIETB1           (*(volatile hw_hdmi_fc_avietb1_t *) HW_HDMI_FC_AVIETB1_ADDR)
#define HW_HDMI_FC_AVIETB1_RD()      (HW_HDMI_FC_AVIETB1.U)
#define HW_HDMI_FC_AVIETB1_WR(v)     (HW_HDMI_FC_AVIETB1.U = (v))
#define HW_HDMI_FC_AVIETB1_SET(v)    (HW_HDMI_FC_AVIETB1_WR(HW_HDMI_FC_AVIETB1_RD() |  (v)))
#define HW_HDMI_FC_AVIETB1_CLR(v)    (HW_HDMI_FC_AVIETB1_WR(HW_HDMI_FC_AVIETB1_RD() & ~(v)))
#define HW_HDMI_FC_AVIETB1_TOG(v)    (HW_HDMI_FC_AVIETB1_WR(HW_HDMI_FC_AVIETB1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVIETB1 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVISBB0 - Frame Composer AVI Packet Start of Bottom Bar Register 0 (RW)
 *
 * These registers define the AVI infoFrame Start of Bottom Bar value. For more information, refer
 * to CEA-861D specification.   Address Offset: 0x101F  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVISBB0 : 8; //!< Line number of Start of Bottom Bar (lower 8 bits)
    } B;
} hw_hdmi_fc_avisbb0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVISBB0 register
 */
#define HW_HDMI_FC_AVISBB0_ADDR      (REGS_HDMI_BASE + 0x101f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVISBB0           (*(volatile hw_hdmi_fc_avisbb0_t *) HW_HDMI_FC_AVISBB0_ADDR)
#define HW_HDMI_FC_AVISBB0_RD()      (HW_HDMI_FC_AVISBB0.U)
#define HW_HDMI_FC_AVISBB0_WR(v)     (HW_HDMI_FC_AVISBB0.U = (v))
#define HW_HDMI_FC_AVISBB0_SET(v)    (HW_HDMI_FC_AVISBB0_WR(HW_HDMI_FC_AVISBB0_RD() |  (v)))
#define HW_HDMI_FC_AVISBB0_CLR(v)    (HW_HDMI_FC_AVISBB0_WR(HW_HDMI_FC_AVISBB0_RD() & ~(v)))
#define HW_HDMI_FC_AVISBB0_TOG(v)    (HW_HDMI_FC_AVISBB0_WR(HW_HDMI_FC_AVISBB0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVISBB0 bitfields
 */

/* --- Register HW_HDMI_FC_AVISBB0, field FC_AVISBB0 (RW)
 *
 * Line number of Start of Bottom Bar (lower 8 bits)
 */

#define BP_HDMI_FC_AVISBB0_FC_AVISBB0      0
#define BM_HDMI_FC_AVISBB0_FC_AVISBB0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVISBB0_FC_AVISBB0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVISBB0_FC_AVISBB0)
#else
#define BF_HDMI_FC_AVISBB0_FC_AVISBB0(v)   (((v) << 0) & BM_HDMI_FC_AVISBB0_FC_AVISBB0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVISBB0 field to a new value.
#define BW_HDMI_FC_AVISBB0_FC_AVISBB0(v)   BF_CS1(HDMI_FC_AVISBB0, FC_AVISBB0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVISBB1 - Frame Composer AVI Packet Start of Bottom Bar Register 1 (RW)
 *
 * Address Offset: 0x1020  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVISBB1 : 8; //!< Line number of Start of Bottom Bar (upper 8 bits)
    } B;
} hw_hdmi_fc_avisbb1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVISBB1 register
 */
#define HW_HDMI_FC_AVISBB1_ADDR      (REGS_HDMI_BASE + 0x1020)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVISBB1           (*(volatile hw_hdmi_fc_avisbb1_t *) HW_HDMI_FC_AVISBB1_ADDR)
#define HW_HDMI_FC_AVISBB1_RD()      (HW_HDMI_FC_AVISBB1.U)
#define HW_HDMI_FC_AVISBB1_WR(v)     (HW_HDMI_FC_AVISBB1.U = (v))
#define HW_HDMI_FC_AVISBB1_SET(v)    (HW_HDMI_FC_AVISBB1_WR(HW_HDMI_FC_AVISBB1_RD() |  (v)))
#define HW_HDMI_FC_AVISBB1_CLR(v)    (HW_HDMI_FC_AVISBB1_WR(HW_HDMI_FC_AVISBB1_RD() & ~(v)))
#define HW_HDMI_FC_AVISBB1_TOG(v)    (HW_HDMI_FC_AVISBB1_WR(HW_HDMI_FC_AVISBB1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVISBB1 bitfields
 */

/* --- Register HW_HDMI_FC_AVISBB1, field FC_AVISBB1 (RW)
 *
 * Line number of Start of Bottom Bar (upper 8 bits)
 */

#define BP_HDMI_FC_AVISBB1_FC_AVISBB1      0
#define BM_HDMI_FC_AVISBB1_FC_AVISBB1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVISBB1_FC_AVISBB1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVISBB1_FC_AVISBB1)
#else
#define BF_HDMI_FC_AVISBB1_FC_AVISBB1(v)   (((v) << 0) & BM_HDMI_FC_AVISBB1_FC_AVISBB1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVISBB1 field to a new value.
#define BW_HDMI_FC_AVISBB1_FC_AVISBB1(v)   BF_CS1(HDMI_FC_AVISBB1, FC_AVISBB1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVIELB0 - Frame Composer AVI Packet End of Left Bar Register 0 (RW)
 *
 * These registers define the AVI infoFrame End of Left Bar value. For more information, refer to
 * CEA-861D specification.   Address Offset: 0x1021  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVIELB0 : 8; //!< Pixel number of end of left Bar (lower 8 bits)
    } B;
} hw_hdmi_fc_avielb0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVIELB0 register
 */
#define HW_HDMI_FC_AVIELB0_ADDR      (REGS_HDMI_BASE + 0x1021)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVIELB0           (*(volatile hw_hdmi_fc_avielb0_t *) HW_HDMI_FC_AVIELB0_ADDR)
#define HW_HDMI_FC_AVIELB0_RD()      (HW_HDMI_FC_AVIELB0.U)
#define HW_HDMI_FC_AVIELB0_WR(v)     (HW_HDMI_FC_AVIELB0.U = (v))
#define HW_HDMI_FC_AVIELB0_SET(v)    (HW_HDMI_FC_AVIELB0_WR(HW_HDMI_FC_AVIELB0_RD() |  (v)))
#define HW_HDMI_FC_AVIELB0_CLR(v)    (HW_HDMI_FC_AVIELB0_WR(HW_HDMI_FC_AVIELB0_RD() & ~(v)))
#define HW_HDMI_FC_AVIELB0_TOG(v)    (HW_HDMI_FC_AVIELB0_WR(HW_HDMI_FC_AVIELB0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVIELB0 bitfields
 */

/* --- Register HW_HDMI_FC_AVIELB0, field FC_AVIELB0 (RW)
 *
 * Pixel number of end of left Bar (lower 8 bits)
 */

#define BP_HDMI_FC_AVIELB0_FC_AVIELB0      0
#define BM_HDMI_FC_AVIELB0_FC_AVIELB0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVIELB0_FC_AVIELB0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVIELB0_FC_AVIELB0)
#else
#define BF_HDMI_FC_AVIELB0_FC_AVIELB0(v)   (((v) << 0) & BM_HDMI_FC_AVIELB0_FC_AVIELB0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVIELB0 field to a new value.
#define BW_HDMI_FC_AVIELB0_FC_AVIELB0(v)   BF_CS1(HDMI_FC_AVIELB0, FC_AVIELB0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVIELB1 - Frame Composer AVI Packet End of Left Bar Register 1 (RW)
 *
 * Address Offset: 0x1022  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVIELB1 : 8; //!< Pixel number of end of left Bar (lower 8 bits)
    } B;
} hw_hdmi_fc_avielb1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVIELB1 register
 */
#define HW_HDMI_FC_AVIELB1_ADDR      (REGS_HDMI_BASE + 0x1022)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVIELB1           (*(volatile hw_hdmi_fc_avielb1_t *) HW_HDMI_FC_AVIELB1_ADDR)
#define HW_HDMI_FC_AVIELB1_RD()      (HW_HDMI_FC_AVIELB1.U)
#define HW_HDMI_FC_AVIELB1_WR(v)     (HW_HDMI_FC_AVIELB1.U = (v))
#define HW_HDMI_FC_AVIELB1_SET(v)    (HW_HDMI_FC_AVIELB1_WR(HW_HDMI_FC_AVIELB1_RD() |  (v)))
#define HW_HDMI_FC_AVIELB1_CLR(v)    (HW_HDMI_FC_AVIELB1_WR(HW_HDMI_FC_AVIELB1_RD() & ~(v)))
#define HW_HDMI_FC_AVIELB1_TOG(v)    (HW_HDMI_FC_AVIELB1_WR(HW_HDMI_FC_AVIELB1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVIELB1 bitfields
 */

/* --- Register HW_HDMI_FC_AVIELB1, field FC_AVIELB1 (RW)
 *
 * Pixel number of end of left Bar (lower 8 bits)
 */

#define BP_HDMI_FC_AVIELB1_FC_AVIELB1      0
#define BM_HDMI_FC_AVIELB1_FC_AVIELB1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVIELB1_FC_AVIELB1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVIELB1_FC_AVIELB1)
#else
#define BF_HDMI_FC_AVIELB1_FC_AVIELB1(v)   (((v) << 0) & BM_HDMI_FC_AVIELB1_FC_AVIELB1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVIELB1 field to a new value.
#define BW_HDMI_FC_AVIELB1_FC_AVIELB1(v)   BF_CS1(HDMI_FC_AVIELB1, FC_AVIELB1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVISRB0 - Frame Composer AVI Packet Start of Right Bar Register 0 (RW)
 *
 * These registers define the AVI infoFrame Start of Right Bar value. For more information, refer to
 * CEA-861D specification.   Address Offset: 0x1023  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVISRB0 : 8; //!< Pixel number of start of right Bar (lower 8 bits)
    } B;
} hw_hdmi_fc_avisrb0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVISRB0 register
 */
#define HW_HDMI_FC_AVISRB0_ADDR      (REGS_HDMI_BASE + 0x1023)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVISRB0           (*(volatile hw_hdmi_fc_avisrb0_t *) HW_HDMI_FC_AVISRB0_ADDR)
#define HW_HDMI_FC_AVISRB0_RD()      (HW_HDMI_FC_AVISRB0.U)
#define HW_HDMI_FC_AVISRB0_WR(v)     (HW_HDMI_FC_AVISRB0.U = (v))
#define HW_HDMI_FC_AVISRB0_SET(v)    (HW_HDMI_FC_AVISRB0_WR(HW_HDMI_FC_AVISRB0_RD() |  (v)))
#define HW_HDMI_FC_AVISRB0_CLR(v)    (HW_HDMI_FC_AVISRB0_WR(HW_HDMI_FC_AVISRB0_RD() & ~(v)))
#define HW_HDMI_FC_AVISRB0_TOG(v)    (HW_HDMI_FC_AVISRB0_WR(HW_HDMI_FC_AVISRB0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVISRB0 bitfields
 */

/* --- Register HW_HDMI_FC_AVISRB0, field FC_AVISRB0 (RW)
 *
 * Pixel number of start of right Bar (lower 8 bits)
 */

#define BP_HDMI_FC_AVISRB0_FC_AVISRB0      0
#define BM_HDMI_FC_AVISRB0_FC_AVISRB0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVISRB0_FC_AVISRB0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVISRB0_FC_AVISRB0)
#else
#define BF_HDMI_FC_AVISRB0_FC_AVISRB0(v)   (((v) << 0) & BM_HDMI_FC_AVISRB0_FC_AVISRB0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVISRB0 field to a new value.
#define BW_HDMI_FC_AVISRB0_FC_AVISRB0(v)   BF_CS1(HDMI_FC_AVISRB0, FC_AVISRB0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AVISRB1 - Frame Composer AVI Packet Start of Right Bar Register 1 (RW)
 *
 * Address Offset: 0x1024  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_AVISRB1 : 8; //!< Pixel number of start of right Bar (upper 8 bits)
    } B;
} hw_hdmi_fc_avisrb1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AVISRB1 register
 */
#define HW_HDMI_FC_AVISRB1_ADDR      (REGS_HDMI_BASE + 0x1024)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AVISRB1           (*(volatile hw_hdmi_fc_avisrb1_t *) HW_HDMI_FC_AVISRB1_ADDR)
#define HW_HDMI_FC_AVISRB1_RD()      (HW_HDMI_FC_AVISRB1.U)
#define HW_HDMI_FC_AVISRB1_WR(v)     (HW_HDMI_FC_AVISRB1.U = (v))
#define HW_HDMI_FC_AVISRB1_SET(v)    (HW_HDMI_FC_AVISRB1_WR(HW_HDMI_FC_AVISRB1_RD() |  (v)))
#define HW_HDMI_FC_AVISRB1_CLR(v)    (HW_HDMI_FC_AVISRB1_WR(HW_HDMI_FC_AVISRB1_RD() & ~(v)))
#define HW_HDMI_FC_AVISRB1_TOG(v)    (HW_HDMI_FC_AVISRB1_WR(HW_HDMI_FC_AVISRB1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AVISRB1 bitfields
 */

/* --- Register HW_HDMI_FC_AVISRB1, field FC_AVISRB1 (RW)
 *
 * Pixel number of start of right Bar (upper 8 bits)
 */

#define BP_HDMI_FC_AVISRB1_FC_AVISRB1      0
#define BM_HDMI_FC_AVISRB1_FC_AVISRB1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AVISRB1_FC_AVISRB1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AVISRB1_FC_AVISRB1)
#else
#define BF_HDMI_FC_AVISRB1_FC_AVISRB1(v)   (((v) << 0) & BM_HDMI_FC_AVISRB1_FC_AVISRB1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_AVISRB1 field to a new value.
#define BW_HDMI_FC_AVISRB1_FC_AVISRB1(v)   BF_CS1(HDMI_FC_AVISRB1, FC_AVISRB1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AUDICONF0 - Frame Composer AUD Packet Configuration Register 0 (RW)
 *
 * These registers configure the following contents of the AUDIO infoFrame:   Coding type  Channel
 * count  Sampling frequency  Sampling size  Channel allocation  Audio level shift value  Down mix
 * enable   For more information, refer to CEA-861D specification.   Address Offset: 0x1025 to
 * 0x1028  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write   For the FC_AUDICONF0
 * register, bits [6:5] correspond to LFEPBL1, LFEPBL0 LFE playback level as compared to the other
 * channels (from HDMI 1.4a specification).
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CT : 4; //!< Coding Type
        unsigned char CC : 3; //!< Channel count
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_fc_audiconf0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AUDICONF0 register
 */
#define HW_HDMI_FC_AUDICONF0_ADDR      (REGS_HDMI_BASE + 0x1025)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AUDICONF0           (*(volatile hw_hdmi_fc_audiconf0_t *) HW_HDMI_FC_AUDICONF0_ADDR)
#define HW_HDMI_FC_AUDICONF0_RD()      (HW_HDMI_FC_AUDICONF0.U)
#define HW_HDMI_FC_AUDICONF0_WR(v)     (HW_HDMI_FC_AUDICONF0.U = (v))
#define HW_HDMI_FC_AUDICONF0_SET(v)    (HW_HDMI_FC_AUDICONF0_WR(HW_HDMI_FC_AUDICONF0_RD() |  (v)))
#define HW_HDMI_FC_AUDICONF0_CLR(v)    (HW_HDMI_FC_AUDICONF0_WR(HW_HDMI_FC_AUDICONF0_RD() & ~(v)))
#define HW_HDMI_FC_AUDICONF0_TOG(v)    (HW_HDMI_FC_AUDICONF0_WR(HW_HDMI_FC_AUDICONF0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AUDICONF0 bitfields
 */

/* --- Register HW_HDMI_FC_AUDICONF0, field CT (RW)
 *
 * Coding Type
 */

#define BP_HDMI_FC_AUDICONF0_CT      0
#define BM_HDMI_FC_AUDICONF0_CT      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDICONF0_CT(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AUDICONF0_CT)
#else
#define BF_HDMI_FC_AUDICONF0_CT(v)   (((v) << 0) & BM_HDMI_FC_AUDICONF0_CT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CT field to a new value.
#define BW_HDMI_FC_AUDICONF0_CT(v)   BF_CS1(HDMI_FC_AUDICONF0, CT, v)
#endif

/* --- Register HW_HDMI_FC_AUDICONF0, field CC (RW)
 *
 * Channel count
 */

#define BP_HDMI_FC_AUDICONF0_CC      4
#define BM_HDMI_FC_AUDICONF0_CC      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDICONF0_CC(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_AUDICONF0_CC)
#else
#define BF_HDMI_FC_AUDICONF0_CC(v)   (((v) << 4) & BM_HDMI_FC_AUDICONF0_CC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CC field to a new value.
#define BW_HDMI_FC_AUDICONF0_CC(v)   BF_CS1(HDMI_FC_AUDICONF0, CC, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AUDICONF1 - Frame Composer AUD Packet Configuration Register 1 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char SF : 3; //!< Sampling frequency
        unsigned char SS : 2; //!< Sampling size
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_audiconf1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AUDICONF1 register
 */
#define HW_HDMI_FC_AUDICONF1_ADDR      (REGS_HDMI_BASE + 0x1026)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AUDICONF1           (*(volatile hw_hdmi_fc_audiconf1_t *) HW_HDMI_FC_AUDICONF1_ADDR)
#define HW_HDMI_FC_AUDICONF1_RD()      (HW_HDMI_FC_AUDICONF1.U)
#define HW_HDMI_FC_AUDICONF1_WR(v)     (HW_HDMI_FC_AUDICONF1.U = (v))
#define HW_HDMI_FC_AUDICONF1_SET(v)    (HW_HDMI_FC_AUDICONF1_WR(HW_HDMI_FC_AUDICONF1_RD() |  (v)))
#define HW_HDMI_FC_AUDICONF1_CLR(v)    (HW_HDMI_FC_AUDICONF1_WR(HW_HDMI_FC_AUDICONF1_RD() & ~(v)))
#define HW_HDMI_FC_AUDICONF1_TOG(v)    (HW_HDMI_FC_AUDICONF1_WR(HW_HDMI_FC_AUDICONF1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AUDICONF1 bitfields
 */

/* --- Register HW_HDMI_FC_AUDICONF1, field SF (RW)
 *
 * Sampling frequency
 */

#define BP_HDMI_FC_AUDICONF1_SF      0
#define BM_HDMI_FC_AUDICONF1_SF      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDICONF1_SF(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AUDICONF1_SF)
#else
#define BF_HDMI_FC_AUDICONF1_SF(v)   (((v) << 0) & BM_HDMI_FC_AUDICONF1_SF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SF field to a new value.
#define BW_HDMI_FC_AUDICONF1_SF(v)   BF_CS1(HDMI_FC_AUDICONF1, SF, v)
#endif

/* --- Register HW_HDMI_FC_AUDICONF1, field SS (RW)
 *
 * Sampling size
 */

#define BP_HDMI_FC_AUDICONF1_SS      3
#define BM_HDMI_FC_AUDICONF1_SS      0x00000018

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDICONF1_SS(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_AUDICONF1_SS)
#else
#define BF_HDMI_FC_AUDICONF1_SS(v)   (((v) << 3) & BM_HDMI_FC_AUDICONF1_SS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SS field to a new value.
#define BW_HDMI_FC_AUDICONF1_SS(v)   BF_CS1(HDMI_FC_AUDICONF1, SS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AUDICONF2 - Frame Composer AUD Packet Configuration Register 2 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CA : 8; //!< Channel allocation
    } B;
} hw_hdmi_fc_audiconf2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AUDICONF2 register
 */
#define HW_HDMI_FC_AUDICONF2_ADDR      (REGS_HDMI_BASE + 0x1027)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AUDICONF2           (*(volatile hw_hdmi_fc_audiconf2_t *) HW_HDMI_FC_AUDICONF2_ADDR)
#define HW_HDMI_FC_AUDICONF2_RD()      (HW_HDMI_FC_AUDICONF2.U)
#define HW_HDMI_FC_AUDICONF2_WR(v)     (HW_HDMI_FC_AUDICONF2.U = (v))
#define HW_HDMI_FC_AUDICONF2_SET(v)    (HW_HDMI_FC_AUDICONF2_WR(HW_HDMI_FC_AUDICONF2_RD() |  (v)))
#define HW_HDMI_FC_AUDICONF2_CLR(v)    (HW_HDMI_FC_AUDICONF2_WR(HW_HDMI_FC_AUDICONF2_RD() & ~(v)))
#define HW_HDMI_FC_AUDICONF2_TOG(v)    (HW_HDMI_FC_AUDICONF2_WR(HW_HDMI_FC_AUDICONF2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AUDICONF2 bitfields
 */

/* --- Register HW_HDMI_FC_AUDICONF2, field CA (RW)
 *
 * Channel allocation
 */

#define BP_HDMI_FC_AUDICONF2_CA      0
#define BM_HDMI_FC_AUDICONF2_CA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDICONF2_CA(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AUDICONF2_CA)
#else
#define BF_HDMI_FC_AUDICONF2_CA(v)   (((v) << 0) & BM_HDMI_FC_AUDICONF2_CA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CA field to a new value.
#define BW_HDMI_FC_AUDICONF2_CA(v)   BF_CS1(HDMI_FC_AUDICONF2, CA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AUDICONF3 - Frame Composer AUD Packet Configuration Register 3 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char LSV : 4; //!< Level shift value (for down mixing)
        unsigned char DM_INH : 1; //!< Down mix enable
        unsigned char LFEPBL : 2; //!< LFE playback information
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_fc_audiconf3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AUDICONF3 register
 */
#define HW_HDMI_FC_AUDICONF3_ADDR      (REGS_HDMI_BASE + 0x1028)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AUDICONF3           (*(volatile hw_hdmi_fc_audiconf3_t *) HW_HDMI_FC_AUDICONF3_ADDR)
#define HW_HDMI_FC_AUDICONF3_RD()      (HW_HDMI_FC_AUDICONF3.U)
#define HW_HDMI_FC_AUDICONF3_WR(v)     (HW_HDMI_FC_AUDICONF3.U = (v))
#define HW_HDMI_FC_AUDICONF3_SET(v)    (HW_HDMI_FC_AUDICONF3_WR(HW_HDMI_FC_AUDICONF3_RD() |  (v)))
#define HW_HDMI_FC_AUDICONF3_CLR(v)    (HW_HDMI_FC_AUDICONF3_WR(HW_HDMI_FC_AUDICONF3_RD() & ~(v)))
#define HW_HDMI_FC_AUDICONF3_TOG(v)    (HW_HDMI_FC_AUDICONF3_WR(HW_HDMI_FC_AUDICONF3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AUDICONF3 bitfields
 */

/* --- Register HW_HDMI_FC_AUDICONF3, field LSV (RW)
 *
 * Level shift value (for down mixing)
 */

#define BP_HDMI_FC_AUDICONF3_LSV      0
#define BM_HDMI_FC_AUDICONF3_LSV      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDICONF3_LSV(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AUDICONF3_LSV)
#else
#define BF_HDMI_FC_AUDICONF3_LSV(v)   (((v) << 0) & BM_HDMI_FC_AUDICONF3_LSV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LSV field to a new value.
#define BW_HDMI_FC_AUDICONF3_LSV(v)   BF_CS1(HDMI_FC_AUDICONF3, LSV, v)
#endif

/* --- Register HW_HDMI_FC_AUDICONF3, field DM_INH (RW)
 *
 * Down mix enable
 */

#define BP_HDMI_FC_AUDICONF3_DM_INH      4
#define BM_HDMI_FC_AUDICONF3_DM_INH      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDICONF3_DM_INH(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_AUDICONF3_DM_INH)
#else
#define BF_HDMI_FC_AUDICONF3_DM_INH(v)   (((v) << 4) & BM_HDMI_FC_AUDICONF3_DM_INH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DM_INH field to a new value.
#define BW_HDMI_FC_AUDICONF3_DM_INH(v)   BF_CS1(HDMI_FC_AUDICONF3, DM_INH, v)
#endif

/* --- Register HW_HDMI_FC_AUDICONF3, field LFEPBL (RW)
 *
 * LFE playback information
 */

#define BP_HDMI_FC_AUDICONF3_LFEPBL      5
#define BM_HDMI_FC_AUDICONF3_LFEPBL      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDICONF3_LFEPBL(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_AUDICONF3_LFEPBL)
#else
#define BF_HDMI_FC_AUDICONF3_LFEPBL(v)   (((v) << 5) & BM_HDMI_FC_AUDICONF3_LFEPBL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LFEPBL field to a new value.
#define BW_HDMI_FC_AUDICONF3_LFEPBL(v)   BF_CS1(HDMI_FC_AUDICONF3, LFEPBL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDIEEEID0 - Frame Composer VSI Packet Data IEEE Register 0 (RW)
 *
 * These registers configure the Vendor Specific infoFrame IEEE registration identifier. For more
 * information, refer to CEA-861D specification.   Address Offset: 0x1029  Size: 8 bits  Value after
 * Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame IEEE registration identifier byte 0
    } B;
} hw_hdmi_fc_vsdieeeid0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDIEEEID0 register
 */
#define HW_HDMI_FC_VSDIEEEID0_ADDR      (REGS_HDMI_BASE + 0x1029)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDIEEEID0           (*(volatile hw_hdmi_fc_vsdieeeid0_t *) HW_HDMI_FC_VSDIEEEID0_ADDR)
#define HW_HDMI_FC_VSDIEEEID0_RD()      (HW_HDMI_FC_VSDIEEEID0.U)
#define HW_HDMI_FC_VSDIEEEID0_WR(v)     (HW_HDMI_FC_VSDIEEEID0.U = (v))
#define HW_HDMI_FC_VSDIEEEID0_SET(v)    (HW_HDMI_FC_VSDIEEEID0_WR(HW_HDMI_FC_VSDIEEEID0_RD() |  (v)))
#define HW_HDMI_FC_VSDIEEEID0_CLR(v)    (HW_HDMI_FC_VSDIEEEID0_WR(HW_HDMI_FC_VSDIEEEID0_RD() & ~(v)))
#define HW_HDMI_FC_VSDIEEEID0_TOG(v)    (HW_HDMI_FC_VSDIEEEID0_WR(HW_HDMI_FC_VSDIEEEID0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDIEEEID0 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDSIZE - Frame Composer VSI Packet Data Size Register (RW)
 *
 * Address Offset: 0x102A  Size: 8 bits  Value after Reset: 0x1B  Access: Read/Write   configuration
 * of Packet size.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char VSDSIZE : 5; //!< Packet size as described in HDMI Vendor Specific InfoFrame (from HDMI specification).
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_vsdsize_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDSIZE register
 */
#define HW_HDMI_FC_VSDSIZE_ADDR      (REGS_HDMI_BASE + 0x102a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDSIZE           (*(volatile hw_hdmi_fc_vsdsize_t *) HW_HDMI_FC_VSDSIZE_ADDR)
#define HW_HDMI_FC_VSDSIZE_RD()      (HW_HDMI_FC_VSDSIZE.U)
#define HW_HDMI_FC_VSDSIZE_WR(v)     (HW_HDMI_FC_VSDSIZE.U = (v))
#define HW_HDMI_FC_VSDSIZE_SET(v)    (HW_HDMI_FC_VSDSIZE_WR(HW_HDMI_FC_VSDSIZE_RD() |  (v)))
#define HW_HDMI_FC_VSDSIZE_CLR(v)    (HW_HDMI_FC_VSDSIZE_WR(HW_HDMI_FC_VSDSIZE_RD() & ~(v)))
#define HW_HDMI_FC_VSDSIZE_TOG(v)    (HW_HDMI_FC_VSDSIZE_WR(HW_HDMI_FC_VSDSIZE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDSIZE bitfields
 */

/* --- Register HW_HDMI_FC_VSDSIZE, field VSDSIZE (RW)
 *
 * Packet size as described in HDMI Vendor Specific InfoFrame (from HDMI specification).
 */

#define BP_HDMI_FC_VSDSIZE_VSDSIZE      0
#define BM_HDMI_FC_VSDSIZE_VSDSIZE      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_VSDSIZE_VSDSIZE(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_VSDSIZE_VSDSIZE)
#else
#define BF_HDMI_FC_VSDSIZE_VSDSIZE(v)   (((v) << 0) & BM_HDMI_FC_VSDSIZE_VSDSIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSDSIZE field to a new value.
#define BW_HDMI_FC_VSDSIZE_VSDSIZE(v)   BF_CS1(HDMI_FC_VSDSIZE, VSDSIZE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDIEEEID1 - Frame Composer VSI Packet Data IEEE Register 1 (RW)
 *
 * Address Offset: 0x102a  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame IEEE registration identifier byte 1
    } B;
} hw_hdmi_fc_vsdieeeid1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDIEEEID1 register
 */
#define HW_HDMI_FC_VSDIEEEID1_ADDR      (REGS_HDMI_BASE + 0x1030)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDIEEEID1           (*(volatile hw_hdmi_fc_vsdieeeid1_t *) HW_HDMI_FC_VSDIEEEID1_ADDR)
#define HW_HDMI_FC_VSDIEEEID1_RD()      (HW_HDMI_FC_VSDIEEEID1.U)
#define HW_HDMI_FC_VSDIEEEID1_WR(v)     (HW_HDMI_FC_VSDIEEEID1.U = (v))
#define HW_HDMI_FC_VSDIEEEID1_SET(v)    (HW_HDMI_FC_VSDIEEEID1_WR(HW_HDMI_FC_VSDIEEEID1_RD() |  (v)))
#define HW_HDMI_FC_VSDIEEEID1_CLR(v)    (HW_HDMI_FC_VSDIEEEID1_WR(HW_HDMI_FC_VSDIEEEID1_RD() & ~(v)))
#define HW_HDMI_FC_VSDIEEEID1_TOG(v)    (HW_HDMI_FC_VSDIEEEID1_WR(HW_HDMI_FC_VSDIEEEID1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDIEEEID1 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDIEEEID2 - Frame Composer VSI Packet Data IEEE Register 2 (RW)
 *
 * Address Offset: 0x102b  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame IEEE registration identifier byte 2
    } B;
} hw_hdmi_fc_vsdieeeid2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDIEEEID2 register
 */
#define HW_HDMI_FC_VSDIEEEID2_ADDR      (REGS_HDMI_BASE + 0x1031)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDIEEEID2           (*(volatile hw_hdmi_fc_vsdieeeid2_t *) HW_HDMI_FC_VSDIEEEID2_ADDR)
#define HW_HDMI_FC_VSDIEEEID2_RD()      (HW_HDMI_FC_VSDIEEEID2.U)
#define HW_HDMI_FC_VSDIEEEID2_WR(v)     (HW_HDMI_FC_VSDIEEEID2.U = (v))
#define HW_HDMI_FC_VSDIEEEID2_SET(v)    (HW_HDMI_FC_VSDIEEEID2_WR(HW_HDMI_FC_VSDIEEEID2_RD() |  (v)))
#define HW_HDMI_FC_VSDIEEEID2_CLR(v)    (HW_HDMI_FC_VSDIEEEID2_WR(HW_HDMI_FC_VSDIEEEID2_RD() & ~(v)))
#define HW_HDMI_FC_VSDIEEEID2_TOG(v)    (HW_HDMI_FC_VSDIEEEID2_WR(HW_HDMI_FC_VSDIEEEID2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDIEEEID2 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD0 - Frame Composer VSI Packet Data IEEE Register 0 (RW)
 *
 * These registers configure the Vendor Specific infoFrame 24 bytes specific payload. For more
 * information, refer to CEA-861D specification.   Address Offset: 0x1032  Size: 8 bits  Value after
 * Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte0
    } B;
} hw_hdmi_fc_vsdpayload0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD0 register
 */
#define HW_HDMI_FC_VSDPAYLOAD0_ADDR      (REGS_HDMI_BASE + 0x1032)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD0           (*(volatile hw_hdmi_fc_vsdpayload0_t *) HW_HDMI_FC_VSDPAYLOAD0_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD0_RD()      (HW_HDMI_FC_VSDPAYLOAD0.U)
#define HW_HDMI_FC_VSDPAYLOAD0_WR(v)     (HW_HDMI_FC_VSDPAYLOAD0.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD0_SET(v)    (HW_HDMI_FC_VSDPAYLOAD0_WR(HW_HDMI_FC_VSDPAYLOAD0_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD0_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD0_WR(HW_HDMI_FC_VSDPAYLOAD0_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD0_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD0_WR(HW_HDMI_FC_VSDPAYLOAD0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD0 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD1 - Frame Composer VSI Packet Data IEEE Register 1 (RW)
 *
 * Address Offset: 0x1033  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte1
    } B;
} hw_hdmi_fc_vsdpayload1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD1 register
 */
#define HW_HDMI_FC_VSDPAYLOAD1_ADDR      (REGS_HDMI_BASE + 0x1033)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD1           (*(volatile hw_hdmi_fc_vsdpayload1_t *) HW_HDMI_FC_VSDPAYLOAD1_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD1_RD()      (HW_HDMI_FC_VSDPAYLOAD1.U)
#define HW_HDMI_FC_VSDPAYLOAD1_WR(v)     (HW_HDMI_FC_VSDPAYLOAD1.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD1_SET(v)    (HW_HDMI_FC_VSDPAYLOAD1_WR(HW_HDMI_FC_VSDPAYLOAD1_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD1_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD1_WR(HW_HDMI_FC_VSDPAYLOAD1_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD1_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD1_WR(HW_HDMI_FC_VSDPAYLOAD1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD1 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD2 - Frame Composer VSI Packet Data IEEE Register 2 (RW)
 *
 * Address Offset: 0x1034  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte2
    } B;
} hw_hdmi_fc_vsdpayload2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD2 register
 */
#define HW_HDMI_FC_VSDPAYLOAD2_ADDR      (REGS_HDMI_BASE + 0x1034)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD2           (*(volatile hw_hdmi_fc_vsdpayload2_t *) HW_HDMI_FC_VSDPAYLOAD2_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD2_RD()      (HW_HDMI_FC_VSDPAYLOAD2.U)
#define HW_HDMI_FC_VSDPAYLOAD2_WR(v)     (HW_HDMI_FC_VSDPAYLOAD2.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD2_SET(v)    (HW_HDMI_FC_VSDPAYLOAD2_WR(HW_HDMI_FC_VSDPAYLOAD2_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD2_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD2_WR(HW_HDMI_FC_VSDPAYLOAD2_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD2_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD2_WR(HW_HDMI_FC_VSDPAYLOAD2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD2 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD3 - Frame Composer VSI Packet Data IEEE Register 3 (RW)
 *
 * Address Offset: 0x1035  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte3
    } B;
} hw_hdmi_fc_vsdpayload3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD3 register
 */
#define HW_HDMI_FC_VSDPAYLOAD3_ADDR      (REGS_HDMI_BASE + 0x1035)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD3           (*(volatile hw_hdmi_fc_vsdpayload3_t *) HW_HDMI_FC_VSDPAYLOAD3_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD3_RD()      (HW_HDMI_FC_VSDPAYLOAD3.U)
#define HW_HDMI_FC_VSDPAYLOAD3_WR(v)     (HW_HDMI_FC_VSDPAYLOAD3.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD3_SET(v)    (HW_HDMI_FC_VSDPAYLOAD3_WR(HW_HDMI_FC_VSDPAYLOAD3_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD3_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD3_WR(HW_HDMI_FC_VSDPAYLOAD3_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD3_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD3_WR(HW_HDMI_FC_VSDPAYLOAD3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD3 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD4 - Frame Composer VSI Packet Data IEEE Register 4 (RW)
 *
 * Address Offset: 0x1036  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte4
    } B;
} hw_hdmi_fc_vsdpayload4_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD4 register
 */
#define HW_HDMI_FC_VSDPAYLOAD4_ADDR      (REGS_HDMI_BASE + 0x1036)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD4           (*(volatile hw_hdmi_fc_vsdpayload4_t *) HW_HDMI_FC_VSDPAYLOAD4_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD4_RD()      (HW_HDMI_FC_VSDPAYLOAD4.U)
#define HW_HDMI_FC_VSDPAYLOAD4_WR(v)     (HW_HDMI_FC_VSDPAYLOAD4.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD4_SET(v)    (HW_HDMI_FC_VSDPAYLOAD4_WR(HW_HDMI_FC_VSDPAYLOAD4_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD4_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD4_WR(HW_HDMI_FC_VSDPAYLOAD4_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD4_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD4_WR(HW_HDMI_FC_VSDPAYLOAD4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD4 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD5 - Frame Composer VSI Packet Data IEEE Register 5 (RW)
 *
 * Address Offset: 0x1037  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte5
    } B;
} hw_hdmi_fc_vsdpayload5_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD5 register
 */
#define HW_HDMI_FC_VSDPAYLOAD5_ADDR      (REGS_HDMI_BASE + 0x1037)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD5           (*(volatile hw_hdmi_fc_vsdpayload5_t *) HW_HDMI_FC_VSDPAYLOAD5_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD5_RD()      (HW_HDMI_FC_VSDPAYLOAD5.U)
#define HW_HDMI_FC_VSDPAYLOAD5_WR(v)     (HW_HDMI_FC_VSDPAYLOAD5.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD5_SET(v)    (HW_HDMI_FC_VSDPAYLOAD5_WR(HW_HDMI_FC_VSDPAYLOAD5_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD5_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD5_WR(HW_HDMI_FC_VSDPAYLOAD5_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD5_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD5_WR(HW_HDMI_FC_VSDPAYLOAD5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD5 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD6 - Frame Composer VSI Packet Data IEEE Register 6 (RW)
 *
 * Address Offset: 0x1038  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte6
    } B;
} hw_hdmi_fc_vsdpayload6_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD6 register
 */
#define HW_HDMI_FC_VSDPAYLOAD6_ADDR      (REGS_HDMI_BASE + 0x1038)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD6           (*(volatile hw_hdmi_fc_vsdpayload6_t *) HW_HDMI_FC_VSDPAYLOAD6_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD6_RD()      (HW_HDMI_FC_VSDPAYLOAD6.U)
#define HW_HDMI_FC_VSDPAYLOAD6_WR(v)     (HW_HDMI_FC_VSDPAYLOAD6.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD6_SET(v)    (HW_HDMI_FC_VSDPAYLOAD6_WR(HW_HDMI_FC_VSDPAYLOAD6_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD6_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD6_WR(HW_HDMI_FC_VSDPAYLOAD6_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD6_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD6_WR(HW_HDMI_FC_VSDPAYLOAD6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD6 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD7 - Frame Composer VSI Packet Data IEEE Register 7 (RW)
 *
 * Address Offset: 0x1039  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte7
    } B;
} hw_hdmi_fc_vsdpayload7_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD7 register
 */
#define HW_HDMI_FC_VSDPAYLOAD7_ADDR      (REGS_HDMI_BASE + 0x1039)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD7           (*(volatile hw_hdmi_fc_vsdpayload7_t *) HW_HDMI_FC_VSDPAYLOAD7_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD7_RD()      (HW_HDMI_FC_VSDPAYLOAD7.U)
#define HW_HDMI_FC_VSDPAYLOAD7_WR(v)     (HW_HDMI_FC_VSDPAYLOAD7.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD7_SET(v)    (HW_HDMI_FC_VSDPAYLOAD7_WR(HW_HDMI_FC_VSDPAYLOAD7_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD7_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD7_WR(HW_HDMI_FC_VSDPAYLOAD7_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD7_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD7_WR(HW_HDMI_FC_VSDPAYLOAD7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD7 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD8 - Frame Composer VSI Packet Data IEEE Register 8 (RW)
 *
 * Address Offset: 0x103a  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte8
    } B;
} hw_hdmi_fc_vsdpayload8_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD8 register
 */
#define HW_HDMI_FC_VSDPAYLOAD8_ADDR      (REGS_HDMI_BASE + 0x103a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD8           (*(volatile hw_hdmi_fc_vsdpayload8_t *) HW_HDMI_FC_VSDPAYLOAD8_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD8_RD()      (HW_HDMI_FC_VSDPAYLOAD8.U)
#define HW_HDMI_FC_VSDPAYLOAD8_WR(v)     (HW_HDMI_FC_VSDPAYLOAD8.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD8_SET(v)    (HW_HDMI_FC_VSDPAYLOAD8_WR(HW_HDMI_FC_VSDPAYLOAD8_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD8_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD8_WR(HW_HDMI_FC_VSDPAYLOAD8_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD8_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD8_WR(HW_HDMI_FC_VSDPAYLOAD8_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD8 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD9 - Frame Composer VSI Packet Data IEEE Register 9 (RW)
 *
 * Address Offset: 0x103b  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte9
    } B;
} hw_hdmi_fc_vsdpayload9_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD9 register
 */
#define HW_HDMI_FC_VSDPAYLOAD9_ADDR      (REGS_HDMI_BASE + 0x103b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD9           (*(volatile hw_hdmi_fc_vsdpayload9_t *) HW_HDMI_FC_VSDPAYLOAD9_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD9_RD()      (HW_HDMI_FC_VSDPAYLOAD9.U)
#define HW_HDMI_FC_VSDPAYLOAD9_WR(v)     (HW_HDMI_FC_VSDPAYLOAD9.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD9_SET(v)    (HW_HDMI_FC_VSDPAYLOAD9_WR(HW_HDMI_FC_VSDPAYLOAD9_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD9_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD9_WR(HW_HDMI_FC_VSDPAYLOAD9_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD9_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD9_WR(HW_HDMI_FC_VSDPAYLOAD9_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD9 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD10 - Frame Composer VSI Packet Data IEEE Register 10 (RW)
 *
 * Address Offset: 0x103c  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte10
    } B;
} hw_hdmi_fc_vsdpayload10_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD10 register
 */
#define HW_HDMI_FC_VSDPAYLOAD10_ADDR      (REGS_HDMI_BASE + 0x103c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD10           (*(volatile hw_hdmi_fc_vsdpayload10_t *) HW_HDMI_FC_VSDPAYLOAD10_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD10_RD()      (HW_HDMI_FC_VSDPAYLOAD10.U)
#define HW_HDMI_FC_VSDPAYLOAD10_WR(v)     (HW_HDMI_FC_VSDPAYLOAD10.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD10_SET(v)    (HW_HDMI_FC_VSDPAYLOAD10_WR(HW_HDMI_FC_VSDPAYLOAD10_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD10_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD10_WR(HW_HDMI_FC_VSDPAYLOAD10_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD10_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD10_WR(HW_HDMI_FC_VSDPAYLOAD10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD10 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD11 - Frame Composer VSI Packet Data IEEE Register 11 (RW)
 *
 * Address Offset: 0x103d  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte11
    } B;
} hw_hdmi_fc_vsdpayload11_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD11 register
 */
#define HW_HDMI_FC_VSDPAYLOAD11_ADDR      (REGS_HDMI_BASE + 0x103d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD11           (*(volatile hw_hdmi_fc_vsdpayload11_t *) HW_HDMI_FC_VSDPAYLOAD11_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD11_RD()      (HW_HDMI_FC_VSDPAYLOAD11.U)
#define HW_HDMI_FC_VSDPAYLOAD11_WR(v)     (HW_HDMI_FC_VSDPAYLOAD11.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD11_SET(v)    (HW_HDMI_FC_VSDPAYLOAD11_WR(HW_HDMI_FC_VSDPAYLOAD11_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD11_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD11_WR(HW_HDMI_FC_VSDPAYLOAD11_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD11_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD11_WR(HW_HDMI_FC_VSDPAYLOAD11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD11 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD12 - Frame Composer VSI Packet Data IEEE Register 12 (RW)
 *
 * Address Offset: 0x103e  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte12
    } B;
} hw_hdmi_fc_vsdpayload12_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD12 register
 */
#define HW_HDMI_FC_VSDPAYLOAD12_ADDR      (REGS_HDMI_BASE + 0x103e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD12           (*(volatile hw_hdmi_fc_vsdpayload12_t *) HW_HDMI_FC_VSDPAYLOAD12_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD12_RD()      (HW_HDMI_FC_VSDPAYLOAD12.U)
#define HW_HDMI_FC_VSDPAYLOAD12_WR(v)     (HW_HDMI_FC_VSDPAYLOAD12.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD12_SET(v)    (HW_HDMI_FC_VSDPAYLOAD12_WR(HW_HDMI_FC_VSDPAYLOAD12_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD12_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD12_WR(HW_HDMI_FC_VSDPAYLOAD12_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD12_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD12_WR(HW_HDMI_FC_VSDPAYLOAD12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD12 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD13 - Frame Composer VSI Packet Data IEEE Register 13 (RW)
 *
 * Address Offset: 0x103f  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte13
    } B;
} hw_hdmi_fc_vsdpayload13_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD13 register
 */
#define HW_HDMI_FC_VSDPAYLOAD13_ADDR      (REGS_HDMI_BASE + 0x103f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD13           (*(volatile hw_hdmi_fc_vsdpayload13_t *) HW_HDMI_FC_VSDPAYLOAD13_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD13_RD()      (HW_HDMI_FC_VSDPAYLOAD13.U)
#define HW_HDMI_FC_VSDPAYLOAD13_WR(v)     (HW_HDMI_FC_VSDPAYLOAD13.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD13_SET(v)    (HW_HDMI_FC_VSDPAYLOAD13_WR(HW_HDMI_FC_VSDPAYLOAD13_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD13_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD13_WR(HW_HDMI_FC_VSDPAYLOAD13_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD13_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD13_WR(HW_HDMI_FC_VSDPAYLOAD13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD13 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD14 - Frame Composer VSI Packet Data IEEE Register 14 (RW)
 *
 * Address Offset: 0x1040  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte14
    } B;
} hw_hdmi_fc_vsdpayload14_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD14 register
 */
#define HW_HDMI_FC_VSDPAYLOAD14_ADDR      (REGS_HDMI_BASE + 0x1040)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD14           (*(volatile hw_hdmi_fc_vsdpayload14_t *) HW_HDMI_FC_VSDPAYLOAD14_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD14_RD()      (HW_HDMI_FC_VSDPAYLOAD14.U)
#define HW_HDMI_FC_VSDPAYLOAD14_WR(v)     (HW_HDMI_FC_VSDPAYLOAD14.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD14_SET(v)    (HW_HDMI_FC_VSDPAYLOAD14_WR(HW_HDMI_FC_VSDPAYLOAD14_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD14_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD14_WR(HW_HDMI_FC_VSDPAYLOAD14_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD14_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD14_WR(HW_HDMI_FC_VSDPAYLOAD14_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD14 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD15 - Frame Composer VSI Packet Data IEEE Register 15 (RW)
 *
 * Address Offset: 0x1041  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte15
    } B;
} hw_hdmi_fc_vsdpayload15_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD15 register
 */
#define HW_HDMI_FC_VSDPAYLOAD15_ADDR      (REGS_HDMI_BASE + 0x1041)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD15           (*(volatile hw_hdmi_fc_vsdpayload15_t *) HW_HDMI_FC_VSDPAYLOAD15_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD15_RD()      (HW_HDMI_FC_VSDPAYLOAD15.U)
#define HW_HDMI_FC_VSDPAYLOAD15_WR(v)     (HW_HDMI_FC_VSDPAYLOAD15.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD15_SET(v)    (HW_HDMI_FC_VSDPAYLOAD15_WR(HW_HDMI_FC_VSDPAYLOAD15_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD15_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD15_WR(HW_HDMI_FC_VSDPAYLOAD15_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD15_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD15_WR(HW_HDMI_FC_VSDPAYLOAD15_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD15 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD16 - Frame Composer VSI Packet Data IEEE Register 16 (RW)
 *
 * Address Offset: 0x1042  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte16
    } B;
} hw_hdmi_fc_vsdpayload16_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD16 register
 */
#define HW_HDMI_FC_VSDPAYLOAD16_ADDR      (REGS_HDMI_BASE + 0x1042)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD16           (*(volatile hw_hdmi_fc_vsdpayload16_t *) HW_HDMI_FC_VSDPAYLOAD16_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD16_RD()      (HW_HDMI_FC_VSDPAYLOAD16.U)
#define HW_HDMI_FC_VSDPAYLOAD16_WR(v)     (HW_HDMI_FC_VSDPAYLOAD16.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD16_SET(v)    (HW_HDMI_FC_VSDPAYLOAD16_WR(HW_HDMI_FC_VSDPAYLOAD16_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD16_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD16_WR(HW_HDMI_FC_VSDPAYLOAD16_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD16_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD16_WR(HW_HDMI_FC_VSDPAYLOAD16_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD16 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD17 - Frame Composer VSI Packet Data IEEE Register 17 (RW)
 *
 * Address Offset: 0x1043  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte17
    } B;
} hw_hdmi_fc_vsdpayload17_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD17 register
 */
#define HW_HDMI_FC_VSDPAYLOAD17_ADDR      (REGS_HDMI_BASE + 0x1043)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD17           (*(volatile hw_hdmi_fc_vsdpayload17_t *) HW_HDMI_FC_VSDPAYLOAD17_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD17_RD()      (HW_HDMI_FC_VSDPAYLOAD17.U)
#define HW_HDMI_FC_VSDPAYLOAD17_WR(v)     (HW_HDMI_FC_VSDPAYLOAD17.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD17_SET(v)    (HW_HDMI_FC_VSDPAYLOAD17_WR(HW_HDMI_FC_VSDPAYLOAD17_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD17_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD17_WR(HW_HDMI_FC_VSDPAYLOAD17_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD17_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD17_WR(HW_HDMI_FC_VSDPAYLOAD17_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD17 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD18 - Frame Composer VSI Packet Data IEEE Register 18 (RW)
 *
 * Address Offset: 0x1044  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte18
    } B;
} hw_hdmi_fc_vsdpayload18_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD18 register
 */
#define HW_HDMI_FC_VSDPAYLOAD18_ADDR      (REGS_HDMI_BASE + 0x1044)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD18           (*(volatile hw_hdmi_fc_vsdpayload18_t *) HW_HDMI_FC_VSDPAYLOAD18_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD18_RD()      (HW_HDMI_FC_VSDPAYLOAD18.U)
#define HW_HDMI_FC_VSDPAYLOAD18_WR(v)     (HW_HDMI_FC_VSDPAYLOAD18.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD18_SET(v)    (HW_HDMI_FC_VSDPAYLOAD18_WR(HW_HDMI_FC_VSDPAYLOAD18_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD18_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD18_WR(HW_HDMI_FC_VSDPAYLOAD18_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD18_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD18_WR(HW_HDMI_FC_VSDPAYLOAD18_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD18 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD19 - Frame Composer VSI Packet Data IEEE Register 19 (RW)
 *
 * Address Offset: 0x1045  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte19
    } B;
} hw_hdmi_fc_vsdpayload19_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD19 register
 */
#define HW_HDMI_FC_VSDPAYLOAD19_ADDR      (REGS_HDMI_BASE + 0x1045)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD19           (*(volatile hw_hdmi_fc_vsdpayload19_t *) HW_HDMI_FC_VSDPAYLOAD19_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD19_RD()      (HW_HDMI_FC_VSDPAYLOAD19.U)
#define HW_HDMI_FC_VSDPAYLOAD19_WR(v)     (HW_HDMI_FC_VSDPAYLOAD19.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD19_SET(v)    (HW_HDMI_FC_VSDPAYLOAD19_WR(HW_HDMI_FC_VSDPAYLOAD19_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD19_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD19_WR(HW_HDMI_FC_VSDPAYLOAD19_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD19_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD19_WR(HW_HDMI_FC_VSDPAYLOAD19_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD19 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD20 - Frame Composer VSI Packet Data IEEE Register 20 (RW)
 *
 * Address Offset: 0x1046  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte20
    } B;
} hw_hdmi_fc_vsdpayload20_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD20 register
 */
#define HW_HDMI_FC_VSDPAYLOAD20_ADDR      (REGS_HDMI_BASE + 0x1046)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD20           (*(volatile hw_hdmi_fc_vsdpayload20_t *) HW_HDMI_FC_VSDPAYLOAD20_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD20_RD()      (HW_HDMI_FC_VSDPAYLOAD20.U)
#define HW_HDMI_FC_VSDPAYLOAD20_WR(v)     (HW_HDMI_FC_VSDPAYLOAD20.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD20_SET(v)    (HW_HDMI_FC_VSDPAYLOAD20_WR(HW_HDMI_FC_VSDPAYLOAD20_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD20_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD20_WR(HW_HDMI_FC_VSDPAYLOAD20_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD20_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD20_WR(HW_HDMI_FC_VSDPAYLOAD20_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD20 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD21 - Frame Composer VSI Packet Data IEEE Register 21 (RW)
 *
 * Address Offset: 0x1047  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte21
    } B;
} hw_hdmi_fc_vsdpayload21_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD21 register
 */
#define HW_HDMI_FC_VSDPAYLOAD21_ADDR      (REGS_HDMI_BASE + 0x1047)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD21           (*(volatile hw_hdmi_fc_vsdpayload21_t *) HW_HDMI_FC_VSDPAYLOAD21_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD21_RD()      (HW_HDMI_FC_VSDPAYLOAD21.U)
#define HW_HDMI_FC_VSDPAYLOAD21_WR(v)     (HW_HDMI_FC_VSDPAYLOAD21.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD21_SET(v)    (HW_HDMI_FC_VSDPAYLOAD21_WR(HW_HDMI_FC_VSDPAYLOAD21_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD21_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD21_WR(HW_HDMI_FC_VSDPAYLOAD21_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD21_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD21_WR(HW_HDMI_FC_VSDPAYLOAD21_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD21 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD22 - Frame Composer VSI Packet Data IEEE Register 22 (RW)
 *
 * Address Offset: 0x1048  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte22
    } B;
} hw_hdmi_fc_vsdpayload22_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD22 register
 */
#define HW_HDMI_FC_VSDPAYLOAD22_ADDR      (REGS_HDMI_BASE + 0x1048)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD22           (*(volatile hw_hdmi_fc_vsdpayload22_t *) HW_HDMI_FC_VSDPAYLOAD22_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD22_RD()      (HW_HDMI_FC_VSDPAYLOAD22.U)
#define HW_HDMI_FC_VSDPAYLOAD22_WR(v)     (HW_HDMI_FC_VSDPAYLOAD22.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD22_SET(v)    (HW_HDMI_FC_VSDPAYLOAD22_WR(HW_HDMI_FC_VSDPAYLOAD22_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD22_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD22_WR(HW_HDMI_FC_VSDPAYLOAD22_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD22_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD22_WR(HW_HDMI_FC_VSDPAYLOAD22_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD22 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_VSDPAYLOAD23 - Frame Composer VSI Packet Data IEEE Register 23 (RW)
 *
 * Address Offset: 0x1049  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 8; //!< the Vendor Specific infoFrame 24 bytes specific payload byte23
    } B;
} hw_hdmi_fc_vsdpayload23_t;
#endif

/*
 * constants & macros for entire HDMI_FC_VSDPAYLOAD23 register
 */
#define HW_HDMI_FC_VSDPAYLOAD23_ADDR      (REGS_HDMI_BASE + 0x1049)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_VSDPAYLOAD23           (*(volatile hw_hdmi_fc_vsdpayload23_t *) HW_HDMI_FC_VSDPAYLOAD23_ADDR)
#define HW_HDMI_FC_VSDPAYLOAD23_RD()      (HW_HDMI_FC_VSDPAYLOAD23.U)
#define HW_HDMI_FC_VSDPAYLOAD23_WR(v)     (HW_HDMI_FC_VSDPAYLOAD23.U = (v))
#define HW_HDMI_FC_VSDPAYLOAD23_SET(v)    (HW_HDMI_FC_VSDPAYLOAD23_WR(HW_HDMI_FC_VSDPAYLOAD23_RD() |  (v)))
#define HW_HDMI_FC_VSDPAYLOAD23_CLR(v)    (HW_HDMI_FC_VSDPAYLOAD23_WR(HW_HDMI_FC_VSDPAYLOAD23_RD() & ~(v)))
#define HW_HDMI_FC_VSDPAYLOAD23_TOG(v)    (HW_HDMI_FC_VSDPAYLOAD23_WR(HW_HDMI_FC_VSDPAYLOAD23_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_VSDPAYLOAD23 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_SPDVENDORNAME0 - Frame Composer SPD Packet Data Vendor Name Register 0 (RW)
 *
 * These registers configure the Source Product Descriptor infoFrame 8 bytes Vendor name. For more
 * information, refer to CEA-861D specification.   Address Offset: 0x104A to 0x1051  Size: 8 bits
 * Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char VENDOR_NAME : 8; //!< Vendor name
    } B;
} hw_hdmi_fc_spdvendorname0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_SPDVENDORNAME0 register
 */
#define HW_HDMI_FC_SPDVENDORNAME0_ADDR      (REGS_HDMI_BASE + 0x104a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_SPDVENDORNAME0           (*(volatile hw_hdmi_fc_spdvendorname0_t *) HW_HDMI_FC_SPDVENDORNAME0_ADDR)
#define HW_HDMI_FC_SPDVENDORNAME0_RD()      (HW_HDMI_FC_SPDVENDORNAME0.U)
#define HW_HDMI_FC_SPDVENDORNAME0_WR(v)     (HW_HDMI_FC_SPDVENDORNAME0.U = (v))
#define HW_HDMI_FC_SPDVENDORNAME0_SET(v)    (HW_HDMI_FC_SPDVENDORNAME0_WR(HW_HDMI_FC_SPDVENDORNAME0_RD() |  (v)))
#define HW_HDMI_FC_SPDVENDORNAME0_CLR(v)    (HW_HDMI_FC_SPDVENDORNAME0_WR(HW_HDMI_FC_SPDVENDORNAME0_RD() & ~(v)))
#define HW_HDMI_FC_SPDVENDORNAME0_TOG(v)    (HW_HDMI_FC_SPDVENDORNAME0_WR(HW_HDMI_FC_SPDVENDORNAME0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_SPDVENDORNAME0 bitfields
 */

/* --- Register HW_HDMI_FC_SPDVENDORNAME0, field VENDOR_NAME (RW)
 *
 * Vendor name
 */

#define BP_HDMI_FC_SPDVENDORNAME0_VENDOR_NAME      0
#define BM_HDMI_FC_SPDVENDORNAME0_VENDOR_NAME      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_SPDVENDORNAME0_VENDOR_NAME(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_SPDVENDORNAME0_VENDOR_NAME)
#else
#define BF_HDMI_FC_SPDVENDORNAME0_VENDOR_NAME(v)   (((v) << 0) & BM_HDMI_FC_SPDVENDORNAME0_VENDOR_NAME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VENDOR_NAME field to a new value.
#define BW_HDMI_FC_SPDVENDORNAME0_VENDOR_NAME(v)   BF_CS1(HDMI_FC_SPDVENDORNAME0, VENDOR_NAME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_SPDPRODUCTNAME0 - Frame Composer SPD Packet Data Product Name Register 0 (RW)
 *
 * These registers configure the Source Product Descriptor infoFrame 16 bytes Product name. For more
 * information, refer to CEA-861D specification.   Address Offset: 0x1052 to 0x1061  Size: 8 bits
 * Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PRODUCT_NAME : 8; //!< Product name
    } B;
} hw_hdmi_fc_spdproductname0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_SPDPRODUCTNAME0 register
 */
#define HW_HDMI_FC_SPDPRODUCTNAME0_ADDR      (REGS_HDMI_BASE + 0x1052)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_SPDPRODUCTNAME0           (*(volatile hw_hdmi_fc_spdproductname0_t *) HW_HDMI_FC_SPDPRODUCTNAME0_ADDR)
#define HW_HDMI_FC_SPDPRODUCTNAME0_RD()      (HW_HDMI_FC_SPDPRODUCTNAME0.U)
#define HW_HDMI_FC_SPDPRODUCTNAME0_WR(v)     (HW_HDMI_FC_SPDPRODUCTNAME0.U = (v))
#define HW_HDMI_FC_SPDPRODUCTNAME0_SET(v)    (HW_HDMI_FC_SPDPRODUCTNAME0_WR(HW_HDMI_FC_SPDPRODUCTNAME0_RD() |  (v)))
#define HW_HDMI_FC_SPDPRODUCTNAME0_CLR(v)    (HW_HDMI_FC_SPDPRODUCTNAME0_WR(HW_HDMI_FC_SPDPRODUCTNAME0_RD() & ~(v)))
#define HW_HDMI_FC_SPDPRODUCTNAME0_TOG(v)    (HW_HDMI_FC_SPDPRODUCTNAME0_WR(HW_HDMI_FC_SPDPRODUCTNAME0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_SPDPRODUCTNAME0 bitfields
 */

/* --- Register HW_HDMI_FC_SPDPRODUCTNAME0, field PRODUCT_NAME (RW)
 *
 * Product name
 */

#define BP_HDMI_FC_SPDPRODUCTNAME0_PRODUCT_NAME      0
#define BM_HDMI_FC_SPDPRODUCTNAME0_PRODUCT_NAME      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_SPDPRODUCTNAME0_PRODUCT_NAME(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_SPDPRODUCTNAME0_PRODUCT_NAME)
#else
#define BF_HDMI_FC_SPDPRODUCTNAME0_PRODUCT_NAME(v)   (((v) << 0) & BM_HDMI_FC_SPDPRODUCTNAME0_PRODUCT_NAME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PRODUCT_NAME field to a new value.
#define BW_HDMI_FC_SPDPRODUCTNAME0_PRODUCT_NAME(v)   BF_CS1(HDMI_FC_SPDPRODUCTNAME0, PRODUCT_NAME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_SPDDEVICEINF - Frame Composer SPD Packet Data Source Product Descriptor Register (RW)
 *
 * This register configures Source Product Descriptor infoFrame description device field. For more
 * information, refer to CEA-861D specification.   Address Offset: 0x1062  Size: 8 bits  Value after
 * Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PRODUCT_DESCRIPTOR : 8; //!< Product descriptor
    } B;
} hw_hdmi_fc_spddeviceinf_t;
#endif

/*
 * constants & macros for entire HDMI_FC_SPDDEVICEINF register
 */
#define HW_HDMI_FC_SPDDEVICEINF_ADDR      (REGS_HDMI_BASE + 0x1062)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_SPDDEVICEINF           (*(volatile hw_hdmi_fc_spddeviceinf_t *) HW_HDMI_FC_SPDDEVICEINF_ADDR)
#define HW_HDMI_FC_SPDDEVICEINF_RD()      (HW_HDMI_FC_SPDDEVICEINF.U)
#define HW_HDMI_FC_SPDDEVICEINF_WR(v)     (HW_HDMI_FC_SPDDEVICEINF.U = (v))
#define HW_HDMI_FC_SPDDEVICEINF_SET(v)    (HW_HDMI_FC_SPDDEVICEINF_WR(HW_HDMI_FC_SPDDEVICEINF_RD() |  (v)))
#define HW_HDMI_FC_SPDDEVICEINF_CLR(v)    (HW_HDMI_FC_SPDDEVICEINF_WR(HW_HDMI_FC_SPDDEVICEINF_RD() & ~(v)))
#define HW_HDMI_FC_SPDDEVICEINF_TOG(v)    (HW_HDMI_FC_SPDDEVICEINF_WR(HW_HDMI_FC_SPDDEVICEINF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_SPDDEVICEINF bitfields
 */

/* --- Register HW_HDMI_FC_SPDDEVICEINF, field PRODUCT_DESCRIPTOR (RW)
 *
 * Product descriptor
 */

#define BP_HDMI_FC_SPDDEVICEINF_PRODUCT_DESCRIPTOR      0
#define BM_HDMI_FC_SPDDEVICEINF_PRODUCT_DESCRIPTOR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_SPDDEVICEINF_PRODUCT_DESCRIPTOR(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_SPDDEVICEINF_PRODUCT_DESCRIPTOR)
#else
#define BF_HDMI_FC_SPDDEVICEINF_PRODUCT_DESCRIPTOR(v)   (((v) << 0) & BM_HDMI_FC_SPDDEVICEINF_PRODUCT_DESCRIPTOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PRODUCT_DESCRIPTOR field to a new value.
#define BW_HDMI_FC_SPDDEVICEINF_PRODUCT_DESCRIPTOR(v)   BF_CS1(HDMI_FC_SPDDEVICEINF, PRODUCT_DESCRIPTOR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AUDSCONF - Frame Composer Audio Sample Flat and Layout Configuration Register (RW)
 *
 * Configures the Audio sample packet sample flat and layout configuration. For more information,
 * refer to HDMI 1.4a specification.   Address Offset: 0x1063  Size: 8 bits  Value after Reset: 0x00
 * AEccess: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUD_PACKET_LAYOUT : 1; //!< Set the audio packet layout to be sent in the packet:
        unsigned char RESERVED0 : 3; //!< Reserved
        unsigned char AUD_PACKET_SAMPFIT : 4; //!< Set the audio packet sample flat value to be sent on the packet.
    } B;
} hw_hdmi_fc_audsconf_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AUDSCONF register
 */
#define HW_HDMI_FC_AUDSCONF_ADDR      (REGS_HDMI_BASE + 0x1063)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AUDSCONF           (*(volatile hw_hdmi_fc_audsconf_t *) HW_HDMI_FC_AUDSCONF_ADDR)
#define HW_HDMI_FC_AUDSCONF_RD()      (HW_HDMI_FC_AUDSCONF.U)
#define HW_HDMI_FC_AUDSCONF_WR(v)     (HW_HDMI_FC_AUDSCONF.U = (v))
#define HW_HDMI_FC_AUDSCONF_SET(v)    (HW_HDMI_FC_AUDSCONF_WR(HW_HDMI_FC_AUDSCONF_RD() |  (v)))
#define HW_HDMI_FC_AUDSCONF_CLR(v)    (HW_HDMI_FC_AUDSCONF_WR(HW_HDMI_FC_AUDSCONF_RD() & ~(v)))
#define HW_HDMI_FC_AUDSCONF_TOG(v)    (HW_HDMI_FC_AUDSCONF_WR(HW_HDMI_FC_AUDSCONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_AUDSCONF bitfields
 */

/* --- Register HW_HDMI_FC_AUDSCONF, field AUD_PACKET_LAYOUT (RW)
 *
 * Set the audio packet layout to be sent in the packet:
 *
 * Values:
 * 1 - layout 1
 * 0 - layout 0
 */

#define BP_HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT      0
#define BM_HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT)
#else
#define BF_HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT(v)   (((v) << 0) & BM_HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUD_PACKET_LAYOUT field to a new value.
#define BW_HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT(v)   BF_CS1(HDMI_FC_AUDSCONF, AUD_PACKET_LAYOUT, v)
#endif


/* --- Register HW_HDMI_FC_AUDSCONF, field AUD_PACKET_SAMPFIT (RW)
 *
 * Set the audio packet sample flat value to be sent on the packet.
 */

#define BP_HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT      4
#define BM_HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT)
#else
#define BF_HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT(v)   (((v) << 4) & BM_HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUD_PACKET_SAMPFIT field to a new value.
#define BW_HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT(v)   BF_CS1(HDMI_FC_AUDSCONF, AUD_PACKET_SAMPFIT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_AUDSSTAT - Frame Composer Audio Packet Sample Present Status Register (RO)
 *
 * Shows the data sample present indication of the last Audio sample packet sent by the HDMI TX
 * Controller. For more information, refer to HDMI 1.4a specification.   Address Offset: 0x1064
 * Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PACKET_SAMPPRS : 4; //!< Shows the data sample present indication of the last Audio sample packet sent by the HDMI TX Controller. This register information is at tmds clock rate.
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_audsstat_t;
#endif

/*
 * constants & macros for entire HDMI_FC_AUDSSTAT register
 */
#define HW_HDMI_FC_AUDSSTAT_ADDR      (REGS_HDMI_BASE + 0x1064)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_AUDSSTAT           (*(volatile hw_hdmi_fc_audsstat_t *) HW_HDMI_FC_AUDSSTAT_ADDR)
#define HW_HDMI_FC_AUDSSTAT_RD()      (HW_HDMI_FC_AUDSSTAT.U)
#endif

/*
 * constants & macros for individual HDMI_FC_AUDSSTAT bitfields
 */

/* --- Register HW_HDMI_FC_AUDSSTAT, field PACKET_SAMPPRS (RO)
 *
 * Shows the data sample present indication of the last Audio sample packet sent by the HDMI TX
 * Controller. This register information is at tmds clock rate.
 */

#define BP_HDMI_FC_AUDSSTAT_PACKET_SAMPPRS      0
#define BM_HDMI_FC_AUDSSTAT_PACKET_SAMPPRS      0x0000000f

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_CTRLQHIGH - Frame Composer Number of High Priority Packets Attended Configuration Register (RW)
 *
 * Address Offset: 0x1073  Size: 8 bits  Value after Reset: 0x0F  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ONHIGHATTENDED : 5; //!< Configures the number of high priority packets or audio sample packets consecutively attended before checking low priority queue status. Integer number [0..31]
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_ctrlqhigh_t;
#endif

/*
 * constants & macros for entire HDMI_FC_CTRLQHIGH register
 */
#define HW_HDMI_FC_CTRLQHIGH_ADDR      (REGS_HDMI_BASE + 0x1073)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_CTRLQHIGH           (*(volatile hw_hdmi_fc_ctrlqhigh_t *) HW_HDMI_FC_CTRLQHIGH_ADDR)
#define HW_HDMI_FC_CTRLQHIGH_RD()      (HW_HDMI_FC_CTRLQHIGH.U)
#define HW_HDMI_FC_CTRLQHIGH_WR(v)     (HW_HDMI_FC_CTRLQHIGH.U = (v))
#define HW_HDMI_FC_CTRLQHIGH_SET(v)    (HW_HDMI_FC_CTRLQHIGH_WR(HW_HDMI_FC_CTRLQHIGH_RD() |  (v)))
#define HW_HDMI_FC_CTRLQHIGH_CLR(v)    (HW_HDMI_FC_CTRLQHIGH_WR(HW_HDMI_FC_CTRLQHIGH_RD() & ~(v)))
#define HW_HDMI_FC_CTRLQHIGH_TOG(v)    (HW_HDMI_FC_CTRLQHIGH_WR(HW_HDMI_FC_CTRLQHIGH_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_CTRLQHIGH bitfields
 */

/* --- Register HW_HDMI_FC_CTRLQHIGH, field ONHIGHATTENDED (RW)
 *
 * Configures the number of high priority packets or audio sample packets consecutively attended
 * before checking low priority queue status. Integer number [0..31]
 */

#define BP_HDMI_FC_CTRLQHIGH_ONHIGHATTENDED      0
#define BM_HDMI_FC_CTRLQHIGH_ONHIGHATTENDED      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_CTRLQHIGH_ONHIGHATTENDED(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_CTRLQHIGH_ONHIGHATTENDED)
#else
#define BF_HDMI_FC_CTRLQHIGH_ONHIGHATTENDED(v)   (((v) << 0) & BM_HDMI_FC_CTRLQHIGH_ONHIGHATTENDED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ONHIGHATTENDED field to a new value.
#define BW_HDMI_FC_CTRLQHIGH_ONHIGHATTENDED(v)   BF_CS1(HDMI_FC_CTRLQHIGH, ONHIGHATTENDED, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_CTRLQLOW - Frame Composer Number of Low Priority Packets Attended Configuration Register (RW)
 *
 * Address Offset: 0x1074  Size: 8 bits  Value after Reset: 0x03  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ONLOWATTENDED : 5; //!< Configures the number of low priority packets or null packets consecutively attended before checking high priority queue status or audio sample availability. Integer number [0..31]
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_ctrlqlow_t;
#endif

/*
 * constants & macros for entire HDMI_FC_CTRLQLOW register
 */
#define HW_HDMI_FC_CTRLQLOW_ADDR      (REGS_HDMI_BASE + 0x1074)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_CTRLQLOW           (*(volatile hw_hdmi_fc_ctrlqlow_t *) HW_HDMI_FC_CTRLQLOW_ADDR)
#define HW_HDMI_FC_CTRLQLOW_RD()      (HW_HDMI_FC_CTRLQLOW.U)
#define HW_HDMI_FC_CTRLQLOW_WR(v)     (HW_HDMI_FC_CTRLQLOW.U = (v))
#define HW_HDMI_FC_CTRLQLOW_SET(v)    (HW_HDMI_FC_CTRLQLOW_WR(HW_HDMI_FC_CTRLQLOW_RD() |  (v)))
#define HW_HDMI_FC_CTRLQLOW_CLR(v)    (HW_HDMI_FC_CTRLQLOW_WR(HW_HDMI_FC_CTRLQLOW_RD() & ~(v)))
#define HW_HDMI_FC_CTRLQLOW_TOG(v)    (HW_HDMI_FC_CTRLQLOW_WR(HW_HDMI_FC_CTRLQLOW_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_CTRLQLOW bitfields
 */

/* --- Register HW_HDMI_FC_CTRLQLOW, field ONLOWATTENDED (RW)
 *
 * Configures the number of low priority packets or null packets consecutively attended before
 * checking high priority queue status or audio sample availability. Integer number [0..31]
 */

#define BP_HDMI_FC_CTRLQLOW_ONLOWATTENDED      0
#define BM_HDMI_FC_CTRLQLOW_ONLOWATTENDED      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_CTRLQLOW_ONLOWATTENDED(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_CTRLQLOW_ONLOWATTENDED)
#else
#define BF_HDMI_FC_CTRLQLOW_ONLOWATTENDED(v)   (((v) << 0) & BM_HDMI_FC_CTRLQLOW_ONLOWATTENDED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ONLOWATTENDED field to a new value.
#define BW_HDMI_FC_CTRLQLOW_ONLOWATTENDED(v)   BF_CS1(HDMI_FC_CTRLQLOW, ONLOWATTENDED, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_ACP0 - Frame Composer ACP Packet Type Configuration Register 0 (RW)
 *
 * Configures the following contents of the ACP packet. For more information, refer to the HDMI 1.4
 * specification.   Address Offset: 0x1075  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ACPTYPE : 8; //!< Configures the ACP packet type.
    } B;
} hw_hdmi_fc_acp0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_ACP0 register
 */
#define HW_HDMI_FC_ACP0_ADDR      (REGS_HDMI_BASE + 0x1075)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_ACP0           (*(volatile hw_hdmi_fc_acp0_t *) HW_HDMI_FC_ACP0_ADDR)
#define HW_HDMI_FC_ACP0_RD()      (HW_HDMI_FC_ACP0.U)
#define HW_HDMI_FC_ACP0_WR(v)     (HW_HDMI_FC_ACP0.U = (v))
#define HW_HDMI_FC_ACP0_SET(v)    (HW_HDMI_FC_ACP0_WR(HW_HDMI_FC_ACP0_RD() |  (v)))
#define HW_HDMI_FC_ACP0_CLR(v)    (HW_HDMI_FC_ACP0_WR(HW_HDMI_FC_ACP0_RD() & ~(v)))
#define HW_HDMI_FC_ACP0_TOG(v)    (HW_HDMI_FC_ACP0_WR(HW_HDMI_FC_ACP0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_ACP0 bitfields
 */

/* --- Register HW_HDMI_FC_ACP0, field ACPTYPE (RW)
 *
 * Configures the ACP packet type.
 */

#define BP_HDMI_FC_ACP0_ACPTYPE      0
#define BM_HDMI_FC_ACP0_ACPTYPE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_ACP0_ACPTYPE(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_ACP0_ACPTYPE)
#else
#define BF_HDMI_FC_ACP0_ACPTYPE(v)   (((v) << 0) & BM_HDMI_FC_ACP0_ACPTYPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACPTYPE field to a new value.
#define BW_HDMI_FC_ACP0_ACPTYPE(v)   BF_CS1(HDMI_FC_ACP0, ACPTYPE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_ACP1 - Frame Composer ACP Packet Type Configuration Register 1 (RW)
 *
 * Configures the following contents of the Audio Content Packet (ACP) body:   Address Offset:
 * 0x1091 to 0x1082  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDIO_CONTENTPACKET : 8; //!< Audio content packet
    } B;
} hw_hdmi_fc_acp1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_ACP1 register
 */
#define HW_HDMI_FC_ACP1_ADDR      (REGS_HDMI_BASE + 0x1091)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_ACP1           (*(volatile hw_hdmi_fc_acp1_t *) HW_HDMI_FC_ACP1_ADDR)
#define HW_HDMI_FC_ACP1_RD()      (HW_HDMI_FC_ACP1.U)
#define HW_HDMI_FC_ACP1_WR(v)     (HW_HDMI_FC_ACP1.U = (v))
#define HW_HDMI_FC_ACP1_SET(v)    (HW_HDMI_FC_ACP1_WR(HW_HDMI_FC_ACP1_RD() |  (v)))
#define HW_HDMI_FC_ACP1_CLR(v)    (HW_HDMI_FC_ACP1_WR(HW_HDMI_FC_ACP1_RD() & ~(v)))
#define HW_HDMI_FC_ACP1_TOG(v)    (HW_HDMI_FC_ACP1_WR(HW_HDMI_FC_ACP1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_ACP1 bitfields
 */

/* --- Register HW_HDMI_FC_ACP1, field AUDIO_CONTENTPACKET (RW)
 *
 * Audio content packet
 */

#define BP_HDMI_FC_ACP1_AUDIO_CONTENTPACKET      0
#define BM_HDMI_FC_ACP1_AUDIO_CONTENTPACKET      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_ACP1_AUDIO_CONTENTPACKET(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_ACP1_AUDIO_CONTENTPACKET)
#else
#define BF_HDMI_FC_ACP1_AUDIO_CONTENTPACKET(v)   (((v) << 0) & BM_HDMI_FC_ACP1_AUDIO_CONTENTPACKET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDIO_CONTENTPACKET field to a new value.
#define BW_HDMI_FC_ACP1_AUDIO_CONTENTPACKET(v)   BF_CS1(HDMI_FC_ACP1, AUDIO_CONTENTPACKET, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_ISCR1_0 - FC_ISCR1_Frame Composer Packet Status, Valid, and Continue Configuration Register (RW)
 *
 * Configures the following contents of the ISRC1 packet:   Address Offset: 0x1092  Size: 8 bits
 * Value after Reset: 0x00  Access: Read/Write   For more information, see the HDMI 1.4
 * specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ISRC_CONT : 1; //!< Indication of ISRC2.
        unsigned char ISRC_VALID : 1; //!< Valid of ISRC1.
        unsigned char ISRC_STATUS : 3; //!< Status of ISRC1.
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_iscr1_0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_ISCR1_0 register
 */
#define HW_HDMI_FC_ISCR1_0_ADDR      (REGS_HDMI_BASE + 0x1092)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_ISCR1_0           (*(volatile hw_hdmi_fc_iscr1_0_t *) HW_HDMI_FC_ISCR1_0_ADDR)
#define HW_HDMI_FC_ISCR1_0_RD()      (HW_HDMI_FC_ISCR1_0.U)
#define HW_HDMI_FC_ISCR1_0_WR(v)     (HW_HDMI_FC_ISCR1_0.U = (v))
#define HW_HDMI_FC_ISCR1_0_SET(v)    (HW_HDMI_FC_ISCR1_0_WR(HW_HDMI_FC_ISCR1_0_RD() |  (v)))
#define HW_HDMI_FC_ISCR1_0_CLR(v)    (HW_HDMI_FC_ISCR1_0_WR(HW_HDMI_FC_ISCR1_0_RD() & ~(v)))
#define HW_HDMI_FC_ISCR1_0_TOG(v)    (HW_HDMI_FC_ISCR1_0_WR(HW_HDMI_FC_ISCR1_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_ISCR1_0 bitfields
 */

/* --- Register HW_HDMI_FC_ISCR1_0, field ISRC_CONT (RW)
 *
 * Indication of ISRC2.
 */

#define BP_HDMI_FC_ISCR1_0_ISRC_CONT      0
#define BM_HDMI_FC_ISCR1_0_ISRC_CONT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_ISCR1_0_ISRC_CONT(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_ISCR1_0_ISRC_CONT)
#else
#define BF_HDMI_FC_ISCR1_0_ISRC_CONT(v)   (((v) << 0) & BM_HDMI_FC_ISCR1_0_ISRC_CONT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISRC_CONT field to a new value.
#define BW_HDMI_FC_ISCR1_0_ISRC_CONT(v)   BF_CS1(HDMI_FC_ISCR1_0, ISRC_CONT, v)
#endif

/* --- Register HW_HDMI_FC_ISCR1_0, field ISRC_VALID (RW)
 *
 * Valid of ISRC1.
 */

#define BP_HDMI_FC_ISCR1_0_ISRC_VALID      1
#define BM_HDMI_FC_ISCR1_0_ISRC_VALID      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_ISCR1_0_ISRC_VALID(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_ISCR1_0_ISRC_VALID)
#else
#define BF_HDMI_FC_ISCR1_0_ISRC_VALID(v)   (((v) << 1) & BM_HDMI_FC_ISCR1_0_ISRC_VALID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISRC_VALID field to a new value.
#define BW_HDMI_FC_ISCR1_0_ISRC_VALID(v)   BF_CS1(HDMI_FC_ISCR1_0, ISRC_VALID, v)
#endif

/* --- Register HW_HDMI_FC_ISCR1_0, field ISRC_STATUS (RW)
 *
 * Status of ISRC1.
 */

#define BP_HDMI_FC_ISCR1_0_ISRC_STATUS      2
#define BM_HDMI_FC_ISCR1_0_ISRC_STATUS      0x0000001c

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_ISCR1_0_ISRC_STATUS(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_ISCR1_0_ISRC_STATUS)
#else
#define BF_HDMI_FC_ISCR1_0_ISRC_STATUS(v)   (((v) << 2) & BM_HDMI_FC_ISCR1_0_ISRC_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISRC_STATUS field to a new value.
#define BW_HDMI_FC_ISCR1_0_ISRC_STATUS(v)   BF_CS1(HDMI_FC_ISCR1_0, ISRC_STATUS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_ISCR1_1 - Frame Composer ISCR1 Packet Body Register 1 (RW)
 *
 * Configures the following contents of the ISRC1 packet:   ISRC1 packet body  Address Offset:
 * 0x10A2 to 0x1093  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write   For more
 * information, see the HDMI 1.4 specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ISRC1 : 8; //!< Configures the contents of the ISRC1 packet:
    } B;
} hw_hdmi_fc_iscr1_1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_ISCR1_1 register
 */
#define HW_HDMI_FC_ISCR1_1_ADDR      (REGS_HDMI_BASE + 0x1093)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_ISCR1_1           (*(volatile hw_hdmi_fc_iscr1_1_t *) HW_HDMI_FC_ISCR1_1_ADDR)
#define HW_HDMI_FC_ISCR1_1_RD()      (HW_HDMI_FC_ISCR1_1.U)
#define HW_HDMI_FC_ISCR1_1_WR(v)     (HW_HDMI_FC_ISCR1_1.U = (v))
#define HW_HDMI_FC_ISCR1_1_SET(v)    (HW_HDMI_FC_ISCR1_1_WR(HW_HDMI_FC_ISCR1_1_RD() |  (v)))
#define HW_HDMI_FC_ISCR1_1_CLR(v)    (HW_HDMI_FC_ISCR1_1_WR(HW_HDMI_FC_ISCR1_1_RD() & ~(v)))
#define HW_HDMI_FC_ISCR1_1_TOG(v)    (HW_HDMI_FC_ISCR1_1_WR(HW_HDMI_FC_ISCR1_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_ISCR1_1 bitfields
 */

/* --- Register HW_HDMI_FC_ISCR1_1, field ISRC1 (RW)
 *
 * Configures the contents of the ISRC1 packet:
 */

#define BP_HDMI_FC_ISCR1_1_ISRC1      0
#define BM_HDMI_FC_ISCR1_1_ISRC1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_ISCR1_1_ISRC1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_ISCR1_1_ISRC1)
#else
#define BF_HDMI_FC_ISCR1_1_ISRC1(v)   (((v) << 0) & BM_HDMI_FC_ISCR1_1_ISRC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISRC1 field to a new value.
#define BW_HDMI_FC_ISCR1_1_ISRC1(v)   BF_CS1(HDMI_FC_ISCR1_1, ISRC1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_ISCR2_0 - Frame Composer ISCR2 Packet Body Register 0 (RW)
 *
 * Configures the following contents of the ISRC2 packet:   ISRC2 packet body  Address Offset:
 * 0x10B2 to 0x10A3  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write   For more
 * information, see the HDMI 1.4 specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ISRC2 : 8; //!< Configures the contents of the ISRC1 packet:
    } B;
} hw_hdmi_fc_iscr2_0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_ISCR2_0 register
 */
#define HW_HDMI_FC_ISCR2_0_ADDR      (REGS_HDMI_BASE + 0x10a3)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_ISCR2_0           (*(volatile hw_hdmi_fc_iscr2_0_t *) HW_HDMI_FC_ISCR2_0_ADDR)
#define HW_HDMI_FC_ISCR2_0_RD()      (HW_HDMI_FC_ISCR2_0.U)
#define HW_HDMI_FC_ISCR2_0_WR(v)     (HW_HDMI_FC_ISCR2_0.U = (v))
#define HW_HDMI_FC_ISCR2_0_SET(v)    (HW_HDMI_FC_ISCR2_0_WR(HW_HDMI_FC_ISCR2_0_RD() |  (v)))
#define HW_HDMI_FC_ISCR2_0_CLR(v)    (HW_HDMI_FC_ISCR2_0_WR(HW_HDMI_FC_ISCR2_0_RD() & ~(v)))
#define HW_HDMI_FC_ISCR2_0_TOG(v)    (HW_HDMI_FC_ISCR2_0_WR(HW_HDMI_FC_ISCR2_0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_ISCR2_0 bitfields
 */

/* --- Register HW_HDMI_FC_ISCR2_0, field ISRC2 (RW)
 *
 * Configures the contents of the ISRC1 packet:
 */

#define BP_HDMI_FC_ISCR2_0_ISRC2      0
#define BM_HDMI_FC_ISCR2_0_ISRC2      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_ISCR2_0_ISRC2(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_ISCR2_0_ISRC2)
#else
#define BF_HDMI_FC_ISCR2_0_ISRC2(v)   (((v) << 0) & BM_HDMI_FC_ISCR2_0_ISRC2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISRC2 field to a new value.
#define BW_HDMI_FC_ISCR2_0_ISRC2(v)   BF_CS1(HDMI_FC_ISCR2_0, ISRC2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DATAUTO0 - Frame Composer Data Island Auto Packet Scheduling Register 0 (RW)
 *
 * Configures the Frame Composer RDRB(1)/Manual(0) data island packet insertion for SPD, VSD, ISRC2,
 * ISRC1 and ACP packets. On RDRB mode the described packet scheduling is controlled by registers
 * FC_DATAUTO1 and FC_DATAUTO2, while in Manual mode register FC_DATMAN requests to FC the insertion
 * of the requested packet.   Address Offset: 0x10B3  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ACP_AUTO : 1; //!< Enables ACP automatic packet scheduling
        unsigned char ISCR1_AUTO : 1; //!< Enables ISRC1 automatic packet scheduling
        unsigned char ISCR2_AUTO : 1; //!< Enables ISRC2 automatic packet scheduling
        unsigned char VSD_AUTO : 1; //!< Enables VSD automatic packet scheduling
        unsigned char SPD_AUTO : 1; //!< Enables SPD automatic packet scheduling
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_datauto0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DATAUTO0 register
 */
#define HW_HDMI_FC_DATAUTO0_ADDR      (REGS_HDMI_BASE + 0x10b3)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DATAUTO0           (*(volatile hw_hdmi_fc_datauto0_t *) HW_HDMI_FC_DATAUTO0_ADDR)
#define HW_HDMI_FC_DATAUTO0_RD()      (HW_HDMI_FC_DATAUTO0.U)
#define HW_HDMI_FC_DATAUTO0_WR(v)     (HW_HDMI_FC_DATAUTO0.U = (v))
#define HW_HDMI_FC_DATAUTO0_SET(v)    (HW_HDMI_FC_DATAUTO0_WR(HW_HDMI_FC_DATAUTO0_RD() |  (v)))
#define HW_HDMI_FC_DATAUTO0_CLR(v)    (HW_HDMI_FC_DATAUTO0_WR(HW_HDMI_FC_DATAUTO0_RD() & ~(v)))
#define HW_HDMI_FC_DATAUTO0_TOG(v)    (HW_HDMI_FC_DATAUTO0_WR(HW_HDMI_FC_DATAUTO0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DATAUTO0 bitfields
 */

/* --- Register HW_HDMI_FC_DATAUTO0, field ACP_AUTO (RW)
 *
 * Enables ACP automatic packet scheduling
 */

#define BP_HDMI_FC_DATAUTO0_ACP_AUTO      0
#define BM_HDMI_FC_DATAUTO0_ACP_AUTO      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO0_ACP_AUTO(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DATAUTO0_ACP_AUTO)
#else
#define BF_HDMI_FC_DATAUTO0_ACP_AUTO(v)   (((v) << 0) & BM_HDMI_FC_DATAUTO0_ACP_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACP_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO0_ACP_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO0, ACP_AUTO, v)
#endif

/* --- Register HW_HDMI_FC_DATAUTO0, field ISCR1_AUTO (RW)
 *
 * Enables ISRC1 automatic packet scheduling
 */

#define BP_HDMI_FC_DATAUTO0_ISCR1_AUTO      1
#define BM_HDMI_FC_DATAUTO0_ISCR1_AUTO      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO0_ISCR1_AUTO(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_DATAUTO0_ISCR1_AUTO)
#else
#define BF_HDMI_FC_DATAUTO0_ISCR1_AUTO(v)   (((v) << 1) & BM_HDMI_FC_DATAUTO0_ISCR1_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR1_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO0_ISCR1_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO0, ISCR1_AUTO, v)
#endif

/* --- Register HW_HDMI_FC_DATAUTO0, field ISCR2_AUTO (RW)
 *
 * Enables ISRC2 automatic packet scheduling
 */

#define BP_HDMI_FC_DATAUTO0_ISCR2_AUTO      2
#define BM_HDMI_FC_DATAUTO0_ISCR2_AUTO      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO0_ISCR2_AUTO(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_DATAUTO0_ISCR2_AUTO)
#else
#define BF_HDMI_FC_DATAUTO0_ISCR2_AUTO(v)   (((v) << 2) & BM_HDMI_FC_DATAUTO0_ISCR2_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR2_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO0_ISCR2_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO0, ISCR2_AUTO, v)
#endif

/* --- Register HW_HDMI_FC_DATAUTO0, field VSD_AUTO (RW)
 *
 * Enables VSD automatic packet scheduling
 */

#define BP_HDMI_FC_DATAUTO0_VSD_AUTO      3
#define BM_HDMI_FC_DATAUTO0_VSD_AUTO      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO0_VSD_AUTO(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_DATAUTO0_VSD_AUTO)
#else
#define BF_HDMI_FC_DATAUTO0_VSD_AUTO(v)   (((v) << 3) & BM_HDMI_FC_DATAUTO0_VSD_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSD_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO0_VSD_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO0, VSD_AUTO, v)
#endif

/* --- Register HW_HDMI_FC_DATAUTO0, field SPD_AUTO (RW)
 *
 * Enables SPD automatic packet scheduling
 */

#define BP_HDMI_FC_DATAUTO0_SPD_AUTO      4
#define BM_HDMI_FC_DATAUTO0_SPD_AUTO      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO0_SPD_AUTO(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_DATAUTO0_SPD_AUTO)
#else
#define BF_HDMI_FC_DATAUTO0_SPD_AUTO(v)   (((v) << 4) & BM_HDMI_FC_DATAUTO0_SPD_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SPD_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO0_SPD_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO0, SPD_AUTO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DATAUTO1 - Frame Composer Data Island Auto Packet Scheduling Register 1 (RW)
 *
 * Configures the Frame Composer (FC) RDRB frame interpolation for SPD, VSD, ISRC2, ISRC1 and ACP
 * packet insertion on data island when FC is on RDRB mode for the listed packets.   Address Offset:
 * 0x10B4  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUTO_FRAME_INTERPOLATION : 4; //!< Packet frame interpolation, for automatic packet scheduling
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_datauto1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DATAUTO1 register
 */
#define HW_HDMI_FC_DATAUTO1_ADDR      (REGS_HDMI_BASE + 0x10b4)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DATAUTO1           (*(volatile hw_hdmi_fc_datauto1_t *) HW_HDMI_FC_DATAUTO1_ADDR)
#define HW_HDMI_FC_DATAUTO1_RD()      (HW_HDMI_FC_DATAUTO1.U)
#define HW_HDMI_FC_DATAUTO1_WR(v)     (HW_HDMI_FC_DATAUTO1.U = (v))
#define HW_HDMI_FC_DATAUTO1_SET(v)    (HW_HDMI_FC_DATAUTO1_WR(HW_HDMI_FC_DATAUTO1_RD() |  (v)))
#define HW_HDMI_FC_DATAUTO1_CLR(v)    (HW_HDMI_FC_DATAUTO1_WR(HW_HDMI_FC_DATAUTO1_RD() & ~(v)))
#define HW_HDMI_FC_DATAUTO1_TOG(v)    (HW_HDMI_FC_DATAUTO1_WR(HW_HDMI_FC_DATAUTO1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DATAUTO1 bitfields
 */

/* --- Register HW_HDMI_FC_DATAUTO1, field AUTO_FRAME_INTERPOLATION (RW)
 *
 * Packet frame interpolation, for automatic packet scheduling
 */

#define BP_HDMI_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION      0
#define BM_HDMI_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION)
#else
#define BF_HDMI_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION(v)   (((v) << 0) & BM_HDMI_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUTO_FRAME_INTERPOLATION field to a new value.
#define BW_HDMI_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION(v)   BF_CS1(HDMI_FC_DATAUTO1, AUTO_FRAME_INTERPOLATION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DATAUTO2 - Frame Composer Data Island Auto Packet Scheduling Register 2 (RW)
 *
 * Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for
 * SPD, VSD, ISRC2, ISRC1 and ACP packet insertion on data island when FC is on RDRB mode for the
 * listed packets.   Address Offset: 0x10B5  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUTO_LINE_SPACING : 4; //!< Packets line spacing, for automatic packet scheduling
        unsigned char AUTO_FRAME_PACKETS : 4; //!< Packets per frame, for automatic packet scheduling
    } B;
} hw_hdmi_fc_datauto2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DATAUTO2 register
 */
#define HW_HDMI_FC_DATAUTO2_ADDR      (REGS_HDMI_BASE + 0x10b5)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DATAUTO2           (*(volatile hw_hdmi_fc_datauto2_t *) HW_HDMI_FC_DATAUTO2_ADDR)
#define HW_HDMI_FC_DATAUTO2_RD()      (HW_HDMI_FC_DATAUTO2.U)
#define HW_HDMI_FC_DATAUTO2_WR(v)     (HW_HDMI_FC_DATAUTO2.U = (v))
#define HW_HDMI_FC_DATAUTO2_SET(v)    (HW_HDMI_FC_DATAUTO2_WR(HW_HDMI_FC_DATAUTO2_RD() |  (v)))
#define HW_HDMI_FC_DATAUTO2_CLR(v)    (HW_HDMI_FC_DATAUTO2_WR(HW_HDMI_FC_DATAUTO2_RD() & ~(v)))
#define HW_HDMI_FC_DATAUTO2_TOG(v)    (HW_HDMI_FC_DATAUTO2_WR(HW_HDMI_FC_DATAUTO2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DATAUTO2 bitfields
 */

/* --- Register HW_HDMI_FC_DATAUTO2, field AUTO_LINE_SPACING (RW)
 *
 * Packets line spacing, for automatic packet scheduling
 */

#define BP_HDMI_FC_DATAUTO2_AUTO_LINE_SPACING      0
#define BM_HDMI_FC_DATAUTO2_AUTO_LINE_SPACING      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO2_AUTO_LINE_SPACING(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DATAUTO2_AUTO_LINE_SPACING)
#else
#define BF_HDMI_FC_DATAUTO2_AUTO_LINE_SPACING(v)   (((v) << 0) & BM_HDMI_FC_DATAUTO2_AUTO_LINE_SPACING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUTO_LINE_SPACING field to a new value.
#define BW_HDMI_FC_DATAUTO2_AUTO_LINE_SPACING(v)   BF_CS1(HDMI_FC_DATAUTO2, AUTO_LINE_SPACING, v)
#endif

/* --- Register HW_HDMI_FC_DATAUTO2, field AUTO_FRAME_PACKETS (RW)
 *
 * Packets per frame, for automatic packet scheduling
 */

#define BP_HDMI_FC_DATAUTO2_AUTO_FRAME_PACKETS      4
#define BM_HDMI_FC_DATAUTO2_AUTO_FRAME_PACKETS      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO2_AUTO_FRAME_PACKETS(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_DATAUTO2_AUTO_FRAME_PACKETS)
#else
#define BF_HDMI_FC_DATAUTO2_AUTO_FRAME_PACKETS(v)   (((v) << 4) & BM_HDMI_FC_DATAUTO2_AUTO_FRAME_PACKETS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUTO_FRAME_PACKETS field to a new value.
#define BW_HDMI_FC_DATAUTO2_AUTO_FRAME_PACKETS(v)   BF_CS1(HDMI_FC_DATAUTO2, AUTO_FRAME_PACKETS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DATMAN - Frame Composer Data Island Manual Packet Request Register (WO)
 *
 * Requests to the Frame Composer the data island packet insertion for NULL, SPD, VSD, ISRC2, ISRC1
 * and ACP packets when FC_DATAUTO0 bit is in manual mode for the packet requested.   Address
 * Offset: 0x10B6  Size: 8 bits  Value after Reset: 0x00  Access: Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ACP_TX : 1; //!< ACP packet
        unsigned char ISR1_TX : 1; //!< ISRC1 packet
        unsigned char ISCR2_TX : 1; //!< ISRC2 packet
        unsigned char VSD_TX : 1; //!< VSD packet
        unsigned char SPD_TX : 1; //!< SPD packet
        unsigned char NULL_TX : 1; //!< Null packet
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_fc_datman_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DATMAN register
 */
#define HW_HDMI_FC_DATMAN_ADDR      (REGS_HDMI_BASE + 0x10b6)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DATMAN           (*(volatile hw_hdmi_fc_datman_t *) HW_HDMI_FC_DATMAN_ADDR)
#define HW_HDMI_FC_DATMAN_WR(v)     (HW_HDMI_FC_DATMAN.U = (v))
#endif

/*
 * constants & macros for individual HDMI_FC_DATMAN bitfields
 */

/* --- Register HW_HDMI_FC_DATMAN, field ACP_TX (WO)
 *
 * ACP packet
 */

#define BP_HDMI_FC_DATMAN_ACP_TX      0
#define BM_HDMI_FC_DATMAN_ACP_TX      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATMAN_ACP_TX(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DATMAN_ACP_TX)
#else
#define BF_HDMI_FC_DATMAN_ACP_TX(v)   (((v) << 0) & BM_HDMI_FC_DATMAN_ACP_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACP_TX field to a new value.
#define BW_HDMI_FC_DATMAN_ACP_TX(v)   BF_CS1(HDMI_FC_DATMAN, ACP_TX, v)
#endif

/* --- Register HW_HDMI_FC_DATMAN, field ISR1_TX (WO)
 *
 * ISRC1 packet
 */

#define BP_HDMI_FC_DATMAN_ISR1_TX      1
#define BM_HDMI_FC_DATMAN_ISR1_TX      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATMAN_ISR1_TX(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_DATMAN_ISR1_TX)
#else
#define BF_HDMI_FC_DATMAN_ISR1_TX(v)   (((v) << 1) & BM_HDMI_FC_DATMAN_ISR1_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISR1_TX field to a new value.
#define BW_HDMI_FC_DATMAN_ISR1_TX(v)   BF_CS1(HDMI_FC_DATMAN, ISR1_TX, v)
#endif

/* --- Register HW_HDMI_FC_DATMAN, field ISCR2_TX (WO)
 *
 * ISRC2 packet
 */

#define BP_HDMI_FC_DATMAN_ISCR2_TX      2
#define BM_HDMI_FC_DATMAN_ISCR2_TX      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATMAN_ISCR2_TX(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_DATMAN_ISCR2_TX)
#else
#define BF_HDMI_FC_DATMAN_ISCR2_TX(v)   (((v) << 2) & BM_HDMI_FC_DATMAN_ISCR2_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR2_TX field to a new value.
#define BW_HDMI_FC_DATMAN_ISCR2_TX(v)   BF_CS1(HDMI_FC_DATMAN, ISCR2_TX, v)
#endif

/* --- Register HW_HDMI_FC_DATMAN, field VSD_TX (WO)
 *
 * VSD packet
 */

#define BP_HDMI_FC_DATMAN_VSD_TX      3
#define BM_HDMI_FC_DATMAN_VSD_TX      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATMAN_VSD_TX(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_DATMAN_VSD_TX)
#else
#define BF_HDMI_FC_DATMAN_VSD_TX(v)   (((v) << 3) & BM_HDMI_FC_DATMAN_VSD_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSD_TX field to a new value.
#define BW_HDMI_FC_DATMAN_VSD_TX(v)   BF_CS1(HDMI_FC_DATMAN, VSD_TX, v)
#endif

/* --- Register HW_HDMI_FC_DATMAN, field SPD_TX (WO)
 *
 * SPD packet
 */

#define BP_HDMI_FC_DATMAN_SPD_TX      4
#define BM_HDMI_FC_DATMAN_SPD_TX      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATMAN_SPD_TX(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_DATMAN_SPD_TX)
#else
#define BF_HDMI_FC_DATMAN_SPD_TX(v)   (((v) << 4) & BM_HDMI_FC_DATMAN_SPD_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SPD_TX field to a new value.
#define BW_HDMI_FC_DATMAN_SPD_TX(v)   BF_CS1(HDMI_FC_DATMAN, SPD_TX, v)
#endif

/* --- Register HW_HDMI_FC_DATMAN, field NULL_TX (WO)
 *
 * Null packet
 */

#define BP_HDMI_FC_DATMAN_NULL_TX      5
#define BM_HDMI_FC_DATMAN_NULL_TX      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATMAN_NULL_TX(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_DATMAN_NULL_TX)
#else
#define BF_HDMI_FC_DATMAN_NULL_TX(v)   (((v) << 5) & BM_HDMI_FC_DATMAN_NULL_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NULL_TX field to a new value.
#define BW_HDMI_FC_DATMAN_NULL_TX(v)   BF_CS1(HDMI_FC_DATMAN, NULL_TX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DATAUTO3 - Frame Composer Data Island Auto Packet Scheduling Register 3 (RW)
 *
 * Configures the Frame Composer Automatic(1)/RDRB(0) data island packet insertion for AVI, GCP,
 * AUDI and ACR packets. In Automatic mode, the packet will be inserted on Vblanking when first line
 * with active Vsync appears.   Address Offset: 0x10B7  Size: 8 bits  Value after Reset: 0x0F
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ACR_AUTO : 1; //!< Enable ACR packet insertion
        unsigned char AUDI_AUTO : 1; //!< Enable AUDI packet insertion
        unsigned char GCP_AUTO : 1; //!< Enable GCP packet insertion
        unsigned char AVI_AUTO : 1; //!< Enable AVI packet insertion
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_datauto3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DATAUTO3 register
 */
#define HW_HDMI_FC_DATAUTO3_ADDR      (REGS_HDMI_BASE + 0x10b7)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DATAUTO3           (*(volatile hw_hdmi_fc_datauto3_t *) HW_HDMI_FC_DATAUTO3_ADDR)
#define HW_HDMI_FC_DATAUTO3_RD()      (HW_HDMI_FC_DATAUTO3.U)
#define HW_HDMI_FC_DATAUTO3_WR(v)     (HW_HDMI_FC_DATAUTO3.U = (v))
#define HW_HDMI_FC_DATAUTO3_SET(v)    (HW_HDMI_FC_DATAUTO3_WR(HW_HDMI_FC_DATAUTO3_RD() |  (v)))
#define HW_HDMI_FC_DATAUTO3_CLR(v)    (HW_HDMI_FC_DATAUTO3_WR(HW_HDMI_FC_DATAUTO3_RD() & ~(v)))
#define HW_HDMI_FC_DATAUTO3_TOG(v)    (HW_HDMI_FC_DATAUTO3_WR(HW_HDMI_FC_DATAUTO3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DATAUTO3 bitfields
 */

/* --- Register HW_HDMI_FC_DATAUTO3, field ACR_AUTO (RW)
 *
 * Enable ACR packet insertion
 */

#define BP_HDMI_FC_DATAUTO3_ACR_AUTO      0
#define BM_HDMI_FC_DATAUTO3_ACR_AUTO      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO3_ACR_AUTO(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DATAUTO3_ACR_AUTO)
#else
#define BF_HDMI_FC_DATAUTO3_ACR_AUTO(v)   (((v) << 0) & BM_HDMI_FC_DATAUTO3_ACR_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACR_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO3_ACR_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO3, ACR_AUTO, v)
#endif

/* --- Register HW_HDMI_FC_DATAUTO3, field AUDI_AUTO (RW)
 *
 * Enable AUDI packet insertion
 */

#define BP_HDMI_FC_DATAUTO3_AUDI_AUTO      1
#define BM_HDMI_FC_DATAUTO3_AUDI_AUTO      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO3_AUDI_AUTO(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_DATAUTO3_AUDI_AUTO)
#else
#define BF_HDMI_FC_DATAUTO3_AUDI_AUTO(v)   (((v) << 1) & BM_HDMI_FC_DATAUTO3_AUDI_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDI_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO3_AUDI_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO3, AUDI_AUTO, v)
#endif

/* --- Register HW_HDMI_FC_DATAUTO3, field GCP_AUTO (RW)
 *
 * Enable GCP packet insertion
 */

#define BP_HDMI_FC_DATAUTO3_GCP_AUTO      2
#define BM_HDMI_FC_DATAUTO3_GCP_AUTO      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO3_GCP_AUTO(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_DATAUTO3_GCP_AUTO)
#else
#define BF_HDMI_FC_DATAUTO3_GCP_AUTO(v)   (((v) << 2) & BM_HDMI_FC_DATAUTO3_GCP_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCP_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO3_GCP_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO3, GCP_AUTO, v)
#endif

/* --- Register HW_HDMI_FC_DATAUTO3, field AVI_AUTO (RW)
 *
 * Enable AVI packet insertion
 */

#define BP_HDMI_FC_DATAUTO3_AVI_AUTO      3
#define BM_HDMI_FC_DATAUTO3_AVI_AUTO      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DATAUTO3_AVI_AUTO(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_DATAUTO3_AVI_AUTO)
#else
#define BF_HDMI_FC_DATAUTO3_AVI_AUTO(v)   (((v) << 3) & BM_HDMI_FC_DATAUTO3_AVI_AUTO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVI_AUTO field to a new value.
#define BW_HDMI_FC_DATAUTO3_AVI_AUTO(v)   BF_CS1(HDMI_FC_DATAUTO3, AVI_AUTO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_RDRB0 - Frame Composer Round Robin ACR Packet Insertion Register 0 (RW)
 *
 * Configures the Frame Composer (FC) RDRB frame interpolation for ACR packet insertion on data
 * island when FC is on RDRB mode for this packet.   Address Offset: 0x10B8  Size: 8 bits  Value
 * after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ACRFRAMEINTERPOLATION : 4; //!< ACR frame interpolation
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_rdrb0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_RDRB0 register
 */
#define HW_HDMI_FC_RDRB0_ADDR      (REGS_HDMI_BASE + 0x10b8)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_RDRB0           (*(volatile hw_hdmi_fc_rdrb0_t *) HW_HDMI_FC_RDRB0_ADDR)
#define HW_HDMI_FC_RDRB0_RD()      (HW_HDMI_FC_RDRB0.U)
#define HW_HDMI_FC_RDRB0_WR(v)     (HW_HDMI_FC_RDRB0.U = (v))
#define HW_HDMI_FC_RDRB0_SET(v)    (HW_HDMI_FC_RDRB0_WR(HW_HDMI_FC_RDRB0_RD() |  (v)))
#define HW_HDMI_FC_RDRB0_CLR(v)    (HW_HDMI_FC_RDRB0_WR(HW_HDMI_FC_RDRB0_RD() & ~(v)))
#define HW_HDMI_FC_RDRB0_TOG(v)    (HW_HDMI_FC_RDRB0_WR(HW_HDMI_FC_RDRB0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_RDRB0 bitfields
 */

/* --- Register HW_HDMI_FC_RDRB0, field ACRFRAMEINTERPOLATION (RW)
 *
 * ACR frame interpolation
 */

#define BP_HDMI_FC_RDRB0_ACRFRAMEINTERPOLATION      0
#define BM_HDMI_FC_RDRB0_ACRFRAMEINTERPOLATION      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB0_ACRFRAMEINTERPOLATION(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_RDRB0_ACRFRAMEINTERPOLATION)
#else
#define BF_HDMI_FC_RDRB0_ACRFRAMEINTERPOLATION(v)   (((v) << 0) & BM_HDMI_FC_RDRB0_ACRFRAMEINTERPOLATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACRFRAMEINTERPOLATION field to a new value.
#define BW_HDMI_FC_RDRB0_ACRFRAMEINTERPOLATION(v)   BF_CS1(HDMI_FC_RDRB0, ACRFRAMEINTERPOLATION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_RDRB1 - Frame Composer Round Robin ACR Packet Insertion Register 1 (RW)
 *
 * Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the
 * ACR packet insertion on data island when FC is on RDRB mode this packet.   Address Offset: 0x10B9
 * Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ACRPACKETLINESPACING : 4; //!< ACR packet line spacing
        unsigned char ACRPACKETSINFRAME : 4; //!< ACR packets in frame
    } B;
} hw_hdmi_fc_rdrb1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_RDRB1 register
 */
#define HW_HDMI_FC_RDRB1_ADDR      (REGS_HDMI_BASE + 0x10b9)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_RDRB1           (*(volatile hw_hdmi_fc_rdrb1_t *) HW_HDMI_FC_RDRB1_ADDR)
#define HW_HDMI_FC_RDRB1_RD()      (HW_HDMI_FC_RDRB1.U)
#define HW_HDMI_FC_RDRB1_WR(v)     (HW_HDMI_FC_RDRB1.U = (v))
#define HW_HDMI_FC_RDRB1_SET(v)    (HW_HDMI_FC_RDRB1_WR(HW_HDMI_FC_RDRB1_RD() |  (v)))
#define HW_HDMI_FC_RDRB1_CLR(v)    (HW_HDMI_FC_RDRB1_WR(HW_HDMI_FC_RDRB1_RD() & ~(v)))
#define HW_HDMI_FC_RDRB1_TOG(v)    (HW_HDMI_FC_RDRB1_WR(HW_HDMI_FC_RDRB1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_RDRB1 bitfields
 */

/* --- Register HW_HDMI_FC_RDRB1, field ACRPACKETLINESPACING (RW)
 *
 * ACR packet line spacing
 */

#define BP_HDMI_FC_RDRB1_ACRPACKETLINESPACING      0
#define BM_HDMI_FC_RDRB1_ACRPACKETLINESPACING      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB1_ACRPACKETLINESPACING(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_RDRB1_ACRPACKETLINESPACING)
#else
#define BF_HDMI_FC_RDRB1_ACRPACKETLINESPACING(v)   (((v) << 0) & BM_HDMI_FC_RDRB1_ACRPACKETLINESPACING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACRPACKETLINESPACING field to a new value.
#define BW_HDMI_FC_RDRB1_ACRPACKETLINESPACING(v)   BF_CS1(HDMI_FC_RDRB1, ACRPACKETLINESPACING, v)
#endif

/* --- Register HW_HDMI_FC_RDRB1, field ACRPACKETSINFRAME (RW)
 *
 * ACR packets in frame
 */

#define BP_HDMI_FC_RDRB1_ACRPACKETSINFRAME      4
#define BM_HDMI_FC_RDRB1_ACRPACKETSINFRAME      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB1_ACRPACKETSINFRAME(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_RDRB1_ACRPACKETSINFRAME)
#else
#define BF_HDMI_FC_RDRB1_ACRPACKETSINFRAME(v)   (((v) << 4) & BM_HDMI_FC_RDRB1_ACRPACKETSINFRAME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACRPACKETSINFRAME field to a new value.
#define BW_HDMI_FC_RDRB1_ACRPACKETSINFRAME(v)   BF_CS1(HDMI_FC_RDRB1, ACRPACKETSINFRAME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_RDRB2 - Frame Composer Round Robin ACR Packet Insertion Register 2 (RW)
 *
 * Configures the Frame Composer (FC) RDRB frame interpolation for AUDI packet insertion on data
 * island when FC is on RDRB mode for this packet.   Address Offset: 0x10BA  Size: 8 bits  Value
 * after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDIFRAMEINTERPOLATION : 4; //!< Audio frame interpolation
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_rdrb2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_RDRB2 register
 */
#define HW_HDMI_FC_RDRB2_ADDR      (REGS_HDMI_BASE + 0x10ba)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_RDRB2           (*(volatile hw_hdmi_fc_rdrb2_t *) HW_HDMI_FC_RDRB2_ADDR)
#define HW_HDMI_FC_RDRB2_RD()      (HW_HDMI_FC_RDRB2.U)
#define HW_HDMI_FC_RDRB2_WR(v)     (HW_HDMI_FC_RDRB2.U = (v))
#define HW_HDMI_FC_RDRB2_SET(v)    (HW_HDMI_FC_RDRB2_WR(HW_HDMI_FC_RDRB2_RD() |  (v)))
#define HW_HDMI_FC_RDRB2_CLR(v)    (HW_HDMI_FC_RDRB2_WR(HW_HDMI_FC_RDRB2_RD() & ~(v)))
#define HW_HDMI_FC_RDRB2_TOG(v)    (HW_HDMI_FC_RDRB2_WR(HW_HDMI_FC_RDRB2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_RDRB2 bitfields
 */

/* --- Register HW_HDMI_FC_RDRB2, field AUDIFRAMEINTERPOLATION (RW)
 *
 * Audio frame interpolation
 */

#define BP_HDMI_FC_RDRB2_AUDIFRAMEINTERPOLATION      0
#define BM_HDMI_FC_RDRB2_AUDIFRAMEINTERPOLATION      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB2_AUDIFRAMEINTERPOLATION(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_RDRB2_AUDIFRAMEINTERPOLATION)
#else
#define BF_HDMI_FC_RDRB2_AUDIFRAMEINTERPOLATION(v)   (((v) << 0) & BM_HDMI_FC_RDRB2_AUDIFRAMEINTERPOLATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDIFRAMEINTERPOLATION field to a new value.
#define BW_HDMI_FC_RDRB2_AUDIFRAMEINTERPOLATION(v)   BF_CS1(HDMI_FC_RDRB2, AUDIFRAMEINTERPOLATION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_RDRB3 - Frame Composer Round Robin ACR Packet Insertion Register 3 (RW)
 *
 * Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the
 * AUDI packet insertion on data island when FC is on RDRB mode this packet.   Address Offset:
 * 0x10BB  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDIPACKETLINESPACING : 4; //!< Audio packets line spacing
        unsigned char AUDIPACKETSINFRAME : 4; //!< Audio packets per frame
    } B;
} hw_hdmi_fc_rdrb3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_RDRB3 register
 */
#define HW_HDMI_FC_RDRB3_ADDR      (REGS_HDMI_BASE + 0x10bb)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_RDRB3           (*(volatile hw_hdmi_fc_rdrb3_t *) HW_HDMI_FC_RDRB3_ADDR)
#define HW_HDMI_FC_RDRB3_RD()      (HW_HDMI_FC_RDRB3.U)
#define HW_HDMI_FC_RDRB3_WR(v)     (HW_HDMI_FC_RDRB3.U = (v))
#define HW_HDMI_FC_RDRB3_SET(v)    (HW_HDMI_FC_RDRB3_WR(HW_HDMI_FC_RDRB3_RD() |  (v)))
#define HW_HDMI_FC_RDRB3_CLR(v)    (HW_HDMI_FC_RDRB3_WR(HW_HDMI_FC_RDRB3_RD() & ~(v)))
#define HW_HDMI_FC_RDRB3_TOG(v)    (HW_HDMI_FC_RDRB3_WR(HW_HDMI_FC_RDRB3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_RDRB3 bitfields
 */

/* --- Register HW_HDMI_FC_RDRB3, field AUDIPACKETLINESPACING (RW)
 *
 * Audio packets line spacing
 */

#define BP_HDMI_FC_RDRB3_AUDIPACKETLINESPACING      0
#define BM_HDMI_FC_RDRB3_AUDIPACKETLINESPACING      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB3_AUDIPACKETLINESPACING(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_RDRB3_AUDIPACKETLINESPACING)
#else
#define BF_HDMI_FC_RDRB3_AUDIPACKETLINESPACING(v)   (((v) << 0) & BM_HDMI_FC_RDRB3_AUDIPACKETLINESPACING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDIPACKETLINESPACING field to a new value.
#define BW_HDMI_FC_RDRB3_AUDIPACKETLINESPACING(v)   BF_CS1(HDMI_FC_RDRB3, AUDIPACKETLINESPACING, v)
#endif

/* --- Register HW_HDMI_FC_RDRB3, field AUDIPACKETSINFRAME (RW)
 *
 * Audio packets per frame
 */

#define BP_HDMI_FC_RDRB3_AUDIPACKETSINFRAME      4
#define BM_HDMI_FC_RDRB3_AUDIPACKETSINFRAME      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB3_AUDIPACKETSINFRAME(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_RDRB3_AUDIPACKETSINFRAME)
#else
#define BF_HDMI_FC_RDRB3_AUDIPACKETSINFRAME(v)   (((v) << 4) & BM_HDMI_FC_RDRB3_AUDIPACKETSINFRAME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDIPACKETSINFRAME field to a new value.
#define BW_HDMI_FC_RDRB3_AUDIPACKETSINFRAME(v)   BF_CS1(HDMI_FC_RDRB3, AUDIPACKETSINFRAME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_RDRB4 - Frame Composer Round Robin ACR Packet Insertion Register 4 (RW)
 *
 * Configures the Frame Composer (FC) RDRB frame interpolation for GCP packet insertion on data
 * island when FC is on RDRB mode for this packet.   Address Offset: 0x10BC  Size: 8 bits  Value
 * after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GCPFRAMEINTERPOLATION : 4; //!< GCP packets line spacing
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_rdrb4_t;
#endif

/*
 * constants & macros for entire HDMI_FC_RDRB4 register
 */
#define HW_HDMI_FC_RDRB4_ADDR      (REGS_HDMI_BASE + 0x10bc)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_RDRB4           (*(volatile hw_hdmi_fc_rdrb4_t *) HW_HDMI_FC_RDRB4_ADDR)
#define HW_HDMI_FC_RDRB4_RD()      (HW_HDMI_FC_RDRB4.U)
#define HW_HDMI_FC_RDRB4_WR(v)     (HW_HDMI_FC_RDRB4.U = (v))
#define HW_HDMI_FC_RDRB4_SET(v)    (HW_HDMI_FC_RDRB4_WR(HW_HDMI_FC_RDRB4_RD() |  (v)))
#define HW_HDMI_FC_RDRB4_CLR(v)    (HW_HDMI_FC_RDRB4_WR(HW_HDMI_FC_RDRB4_RD() & ~(v)))
#define HW_HDMI_FC_RDRB4_TOG(v)    (HW_HDMI_FC_RDRB4_WR(HW_HDMI_FC_RDRB4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_RDRB4 bitfields
 */

/* --- Register HW_HDMI_FC_RDRB4, field GCPFRAMEINTERPOLATION (RW)
 *
 * GCP packets line spacing
 */

#define BP_HDMI_FC_RDRB4_GCPFRAMEINTERPOLATION      0
#define BM_HDMI_FC_RDRB4_GCPFRAMEINTERPOLATION      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB4_GCPFRAMEINTERPOLATION(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_RDRB4_GCPFRAMEINTERPOLATION)
#else
#define BF_HDMI_FC_RDRB4_GCPFRAMEINTERPOLATION(v)   (((v) << 0) & BM_HDMI_FC_RDRB4_GCPFRAMEINTERPOLATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCPFRAMEINTERPOLATION field to a new value.
#define BW_HDMI_FC_RDRB4_GCPFRAMEINTERPOLATION(v)   BF_CS1(HDMI_FC_RDRB4, GCPFRAMEINTERPOLATION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_RDRB5 - Frame Composer Round Robin ACR Packet Insertion Register 5 (RW)
 *
 * Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the
 * GCP packet insertion on data island when FC is on RDRB mode this packet.   Address Offset: 0x10BD
 * Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GCPPACKETLINESPACING : 4; //!< GCP packets line spacing
        unsigned char GCPPACKETSINFRAME : 4; //!< GCP packets per frame
    } B;
} hw_hdmi_fc_rdrb5_t;
#endif

/*
 * constants & macros for entire HDMI_FC_RDRB5 register
 */
#define HW_HDMI_FC_RDRB5_ADDR      (REGS_HDMI_BASE + 0x10bd)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_RDRB5           (*(volatile hw_hdmi_fc_rdrb5_t *) HW_HDMI_FC_RDRB5_ADDR)
#define HW_HDMI_FC_RDRB5_RD()      (HW_HDMI_FC_RDRB5.U)
#define HW_HDMI_FC_RDRB5_WR(v)     (HW_HDMI_FC_RDRB5.U = (v))
#define HW_HDMI_FC_RDRB5_SET(v)    (HW_HDMI_FC_RDRB5_WR(HW_HDMI_FC_RDRB5_RD() |  (v)))
#define HW_HDMI_FC_RDRB5_CLR(v)    (HW_HDMI_FC_RDRB5_WR(HW_HDMI_FC_RDRB5_RD() & ~(v)))
#define HW_HDMI_FC_RDRB5_TOG(v)    (HW_HDMI_FC_RDRB5_WR(HW_HDMI_FC_RDRB5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_RDRB5 bitfields
 */

/* --- Register HW_HDMI_FC_RDRB5, field GCPPACKETLINESPACING (RW)
 *
 * GCP packets line spacing
 */

#define BP_HDMI_FC_RDRB5_GCPPACKETLINESPACING      0
#define BM_HDMI_FC_RDRB5_GCPPACKETLINESPACING      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB5_GCPPACKETLINESPACING(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_RDRB5_GCPPACKETLINESPACING)
#else
#define BF_HDMI_FC_RDRB5_GCPPACKETLINESPACING(v)   (((v) << 0) & BM_HDMI_FC_RDRB5_GCPPACKETLINESPACING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCPPACKETLINESPACING field to a new value.
#define BW_HDMI_FC_RDRB5_GCPPACKETLINESPACING(v)   BF_CS1(HDMI_FC_RDRB5, GCPPACKETLINESPACING, v)
#endif

/* --- Register HW_HDMI_FC_RDRB5, field GCPPACKETSINFRAME (RW)
 *
 * GCP packets per frame
 */

#define BP_HDMI_FC_RDRB5_GCPPACKETSINFRAME      4
#define BM_HDMI_FC_RDRB5_GCPPACKETSINFRAME      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB5_GCPPACKETSINFRAME(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_RDRB5_GCPPACKETSINFRAME)
#else
#define BF_HDMI_FC_RDRB5_GCPPACKETSINFRAME(v)   (((v) << 4) & BM_HDMI_FC_RDRB5_GCPPACKETSINFRAME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCPPACKETSINFRAME field to a new value.
#define BW_HDMI_FC_RDRB5_GCPPACKETSINFRAME(v)   BF_CS1(HDMI_FC_RDRB5, GCPPACKETSINFRAME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_RDRB6 - Frame Composer Round Robin ACR Packet Insertion Register 6 (RW)
 *
 * Configures the Frame Composer (FC) RDRB frame interpolation for AVI packet insertion on data
 * island when FC is on RDRB mode for this packet.   Address Offset: 0x10BE  Size: 8 bits  Value
 * after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AVIFRAMEINTERPOLATION : 4; //!< GCP packets line spacing
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_fc_rdrb6_t;
#endif

/*
 * constants & macros for entire HDMI_FC_RDRB6 register
 */
#define HW_HDMI_FC_RDRB6_ADDR      (REGS_HDMI_BASE + 0x10be)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_RDRB6           (*(volatile hw_hdmi_fc_rdrb6_t *) HW_HDMI_FC_RDRB6_ADDR)
#define HW_HDMI_FC_RDRB6_RD()      (HW_HDMI_FC_RDRB6.U)
#define HW_HDMI_FC_RDRB6_WR(v)     (HW_HDMI_FC_RDRB6.U = (v))
#define HW_HDMI_FC_RDRB6_SET(v)    (HW_HDMI_FC_RDRB6_WR(HW_HDMI_FC_RDRB6_RD() |  (v)))
#define HW_HDMI_FC_RDRB6_CLR(v)    (HW_HDMI_FC_RDRB6_WR(HW_HDMI_FC_RDRB6_RD() & ~(v)))
#define HW_HDMI_FC_RDRB6_TOG(v)    (HW_HDMI_FC_RDRB6_WR(HW_HDMI_FC_RDRB6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_RDRB6 bitfields
 */

/* --- Register HW_HDMI_FC_RDRB6, field AVIFRAMEINTERPOLATION (RW)
 *
 * GCP packets line spacing
 */

#define BP_HDMI_FC_RDRB6_AVIFRAMEINTERPOLATION      0
#define BM_HDMI_FC_RDRB6_AVIFRAMEINTERPOLATION      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB6_AVIFRAMEINTERPOLATION(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_RDRB6_AVIFRAMEINTERPOLATION)
#else
#define BF_HDMI_FC_RDRB6_AVIFRAMEINTERPOLATION(v)   (((v) << 0) & BM_HDMI_FC_RDRB6_AVIFRAMEINTERPOLATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVIFRAMEINTERPOLATION field to a new value.
#define BW_HDMI_FC_RDRB6_AVIFRAMEINTERPOLATION(v)   BF_CS1(HDMI_FC_RDRB6, AVIFRAMEINTERPOLATION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_RDRB7 - Frame Composer Round Robin ACR Packet Insertion Register 7 (RW)
 *
 * Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the
 * AVI packet insertion on data island when FC is on RDRB mode this packet.   Address Offset: 0x10BF
 * Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AVIPACKETLINESPACING : 4; //!< AVI packets line spacing
        unsigned char AVIPACKETSINFRAME : 4; //!< AVI packets per frame
    } B;
} hw_hdmi_fc_rdrb7_t;
#endif

/*
 * constants & macros for entire HDMI_FC_RDRB7 register
 */
#define HW_HDMI_FC_RDRB7_ADDR      (REGS_HDMI_BASE + 0x10bf)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_RDRB7           (*(volatile hw_hdmi_fc_rdrb7_t *) HW_HDMI_FC_RDRB7_ADDR)
#define HW_HDMI_FC_RDRB7_RD()      (HW_HDMI_FC_RDRB7.U)
#define HW_HDMI_FC_RDRB7_WR(v)     (HW_HDMI_FC_RDRB7.U = (v))
#define HW_HDMI_FC_RDRB7_SET(v)    (HW_HDMI_FC_RDRB7_WR(HW_HDMI_FC_RDRB7_RD() |  (v)))
#define HW_HDMI_FC_RDRB7_CLR(v)    (HW_HDMI_FC_RDRB7_WR(HW_HDMI_FC_RDRB7_RD() & ~(v)))
#define HW_HDMI_FC_RDRB7_TOG(v)    (HW_HDMI_FC_RDRB7_WR(HW_HDMI_FC_RDRB7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_RDRB7 bitfields
 */

/* --- Register HW_HDMI_FC_RDRB7, field AVIPACKETLINESPACING (RW)
 *
 * AVI packets line spacing
 */

#define BP_HDMI_FC_RDRB7_AVIPACKETLINESPACING      0
#define BM_HDMI_FC_RDRB7_AVIPACKETLINESPACING      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB7_AVIPACKETLINESPACING(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_RDRB7_AVIPACKETLINESPACING)
#else
#define BF_HDMI_FC_RDRB7_AVIPACKETLINESPACING(v)   (((v) << 0) & BM_HDMI_FC_RDRB7_AVIPACKETLINESPACING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVIPACKETLINESPACING field to a new value.
#define BW_HDMI_FC_RDRB7_AVIPACKETLINESPACING(v)   BF_CS1(HDMI_FC_RDRB7, AVIPACKETLINESPACING, v)
#endif

/* --- Register HW_HDMI_FC_RDRB7, field AVIPACKETSINFRAME (RW)
 *
 * AVI packets per frame
 */

#define BP_HDMI_FC_RDRB7_AVIPACKETSINFRAME      4
#define BM_HDMI_FC_RDRB7_AVIPACKETSINFRAME      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_RDRB7_AVIPACKETSINFRAME(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_RDRB7_AVIPACKETSINFRAME)
#else
#define BF_HDMI_FC_RDRB7_AVIPACKETSINFRAME(v)   (((v) << 4) & BM_HDMI_FC_RDRB7_AVIPACKETSINFRAME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVIPACKETSINFRAME field to a new value.
#define BW_HDMI_FC_RDRB7_AVIPACKETSINFRAME(v)   BF_CS1(HDMI_FC_RDRB7, AVIPACKETSINFRAME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_STAT0 - FC_STAT0 (RO)
 *
 * Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the
 * AVI packet insertion on data island when FC is on RDRB mode this packet.   Address Offset: 0x10D0
 * Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char NULL : 1; //!< Status bit Active after successful transmission of an Null packet.
        unsigned char ACR : 1; //!< Status bit Active after successful transmission of an Audio Clock Regeneration (N/CTS transmission) packet.
        unsigned char AUDS : 1; //!< Status bit Active after successful transmission of an Audio Sample packet.
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char HBR : 1; //!< Status bit. Active after successful transmission of an Audio HBR packet
        unsigned char ACP : 1; //!< Status bit. Active after successful transmission of an Audio Content Protection Packet.
        unsigned char AUDI : 1; //!< Status bit Active after successful transmission of an Audio InfoFrame packet.
    } B;
} hw_hdmi_fc_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_STAT0 register
 */
#define HW_HDMI_FC_STAT0_ADDR      (REGS_HDMI_BASE + 0x10d0)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_STAT0           (*(volatile hw_hdmi_fc_stat0_t *) HW_HDMI_FC_STAT0_ADDR)
#define HW_HDMI_FC_STAT0_RD()      (HW_HDMI_FC_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_FC_STAT0 bitfields
 */

/* --- Register HW_HDMI_FC_STAT0, field NULL (RO)
 *
 * Status bit Active after successful transmission of an Null packet.
 */

#define BP_HDMI_FC_STAT0_NULL      0
#define BM_HDMI_FC_STAT0_NULL      0x00000001

/* --- Register HW_HDMI_FC_STAT0, field ACR (RO)
 *
 * Status bit Active after successful transmission of an Audio Clock Regeneration (N/CTS
 * transmission) packet.
 */

#define BP_HDMI_FC_STAT0_ACR      1
#define BM_HDMI_FC_STAT0_ACR      0x00000002

/* --- Register HW_HDMI_FC_STAT0, field AUDS (RO)
 *
 * Status bit Active after successful transmission of an Audio Sample packet.
 */

#define BP_HDMI_FC_STAT0_AUDS      2
#define BM_HDMI_FC_STAT0_AUDS      0x00000004

/* --- Register HW_HDMI_FC_STAT0, field HBR (RO)
 *
 * Status bit. Active after successful transmission of an Audio HBR packet
 */

#define BP_HDMI_FC_STAT0_HBR      5
#define BM_HDMI_FC_STAT0_HBR      0x00000020

/* --- Register HW_HDMI_FC_STAT0, field ACP (RO)
 *
 * Status bit. Active after successful transmission of an Audio Content Protection Packet.
 */

#define BP_HDMI_FC_STAT0_ACP      6
#define BM_HDMI_FC_STAT0_ACP      0x00000040

/* --- Register HW_HDMI_FC_STAT0, field AUDI (RO)
 *
 * Status bit Active after successful transmission of an Audio InfoFrame packet.
 */

#define BP_HDMI_FC_STAT0_AUDI      7
#define BM_HDMI_FC_STAT0_AUDI      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INT0 - FC_INT0 (RW)
 *
 * This register contains the interrupt indication of the FC_STAT0 status interrupts. Interrupt
 * generation is accomplished in the following way:  interrupt = (mask == 1'b0) && (polarity ==
 * status);  All this interrupts are forwarded to the Interrupt Handler sticky bit registers and
 * after ORed to a single main interrupt line to micro controller. Assertion of this interrupt
 * implies that data related with the corresponding packet has been sent through the HDMI interface.
 * Address Offset: 0x10D1  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char NULL : 1; //!< Interrupt indication bit Active after successful transmission of an Null packet interrupt.
        unsigned char ACR : 1; //!< Interrupt indication bit Active after successful transmission of an Audio Clock Regeneration (N/CTS transmission) packet interrupt.
        unsigned char AUDS : 1; //!< Interrupt indication bit Active after successful transmission of an Audio Sample packet interrupt.
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char HBR : 1; //!< Interrupt indication bit Active after successful transmission of a Audio HBR packet interrupt.
        unsigned char ACP : 1; //!< Interrupt indication bit Active after successful transmission of an Audio Content Protection packet interrupt.
        unsigned char AUDI : 1; //!< Interrupt indication bit Active after successful transmission of an Audio InfoFrame packet interrupt.
    } B;
} hw_hdmi_fc_int0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INT0 register
 */
#define HW_HDMI_FC_INT0_ADDR      (REGS_HDMI_BASE + 0x10d1)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INT0           (*(volatile hw_hdmi_fc_int0_t *) HW_HDMI_FC_INT0_ADDR)
#define HW_HDMI_FC_INT0_RD()      (HW_HDMI_FC_INT0.U)
#define HW_HDMI_FC_INT0_WR(v)     (HW_HDMI_FC_INT0.U = (v))
#define HW_HDMI_FC_INT0_SET(v)    (HW_HDMI_FC_INT0_WR(HW_HDMI_FC_INT0_RD() |  (v)))
#define HW_HDMI_FC_INT0_CLR(v)    (HW_HDMI_FC_INT0_WR(HW_HDMI_FC_INT0_RD() & ~(v)))
#define HW_HDMI_FC_INT0_TOG(v)    (HW_HDMI_FC_INT0_WR(HW_HDMI_FC_INT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INT0 bitfields
 */

/* --- Register HW_HDMI_FC_INT0, field NULL (RW)
 *
 * Interrupt indication bit Active after successful transmission of an Null packet interrupt.
 */

#define BP_HDMI_FC_INT0_NULL      0
#define BM_HDMI_FC_INT0_NULL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT0_NULL(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INT0_NULL)
#else
#define BF_HDMI_FC_INT0_NULL(v)   (((v) << 0) & BM_HDMI_FC_INT0_NULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NULL field to a new value.
#define BW_HDMI_FC_INT0_NULL(v)   BF_CS1(HDMI_FC_INT0, NULL, v)
#endif

/* --- Register HW_HDMI_FC_INT0, field ACR (RW)
 *
 * Interrupt indication bit Active after successful transmission of an Audio Clock Regeneration
 * (N/CTS transmission) packet interrupt.
 */

#define BP_HDMI_FC_INT0_ACR      1
#define BM_HDMI_FC_INT0_ACR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT0_ACR(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_INT0_ACR)
#else
#define BF_HDMI_FC_INT0_ACR(v)   (((v) << 1) & BM_HDMI_FC_INT0_ACR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACR field to a new value.
#define BW_HDMI_FC_INT0_ACR(v)   BF_CS1(HDMI_FC_INT0, ACR, v)
#endif

/* --- Register HW_HDMI_FC_INT0, field AUDS (RW)
 *
 * Interrupt indication bit Active after successful transmission of an Audio Sample packet
 * interrupt.
 */

#define BP_HDMI_FC_INT0_AUDS      2
#define BM_HDMI_FC_INT0_AUDS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT0_AUDS(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_INT0_AUDS)
#else
#define BF_HDMI_FC_INT0_AUDS(v)   (((v) << 2) & BM_HDMI_FC_INT0_AUDS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDS field to a new value.
#define BW_HDMI_FC_INT0_AUDS(v)   BF_CS1(HDMI_FC_INT0, AUDS, v)
#endif

/* --- Register HW_HDMI_FC_INT0, field HBR (RW)
 *
 * Interrupt indication bit Active after successful transmission of a Audio HBR packet interrupt.
 */

#define BP_HDMI_FC_INT0_HBR      5
#define BM_HDMI_FC_INT0_HBR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT0_HBR(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_INT0_HBR)
#else
#define BF_HDMI_FC_INT0_HBR(v)   (((v) << 5) & BM_HDMI_FC_INT0_HBR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBR field to a new value.
#define BW_HDMI_FC_INT0_HBR(v)   BF_CS1(HDMI_FC_INT0, HBR, v)
#endif

/* --- Register HW_HDMI_FC_INT0, field ACP (RW)
 *
 * Interrupt indication bit Active after successful transmission of an Audio Content Protection
 * packet interrupt.
 */

#define BP_HDMI_FC_INT0_ACP      6
#define BM_HDMI_FC_INT0_ACP      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT0_ACP(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_INT0_ACP)
#else
#define BF_HDMI_FC_INT0_ACP(v)   (((v) << 6) & BM_HDMI_FC_INT0_ACP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACP field to a new value.
#define BW_HDMI_FC_INT0_ACP(v)   BF_CS1(HDMI_FC_INT0, ACP, v)
#endif

/* --- Register HW_HDMI_FC_INT0, field AUDI (RW)
 *
 * Interrupt indication bit Active after successful transmission of an Audio InfoFrame packet
 * interrupt.
 */

#define BP_HDMI_FC_INT0_AUDI      7
#define BM_HDMI_FC_INT0_AUDI      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT0_AUDI(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_INT0_AUDI)
#else
#define BF_HDMI_FC_INT0_AUDI(v)   (((v) << 7) & BM_HDMI_FC_INT0_AUDI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDI field to a new value.
#define BW_HDMI_FC_INT0_AUDI(v)   BF_CS1(HDMI_FC_INT0, AUDI, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_MASK0 - Frame Composer Packet Interrupt Mask Register 0 (RW)
 *
 * Mask register for generation of FC_INT0 interrupts.   Address Offset: 0x10D2  Size: 8 bits  Value
 * after Reset: 0x25  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char NULL : 1; //!< Mask bit for FC_INT0.NULL interrupt bit Value after Reset: 0b
        unsigned char ACR : 1; //!< Mask bit for FC_INT0.ACR interrupt bit Value after Reset: 0b
        unsigned char AUDS : 1; //!< Mask bit for FC_INT0.AUDS interrupt bit Value after Reset: 0b
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char HBR : 1; //!< Mask bit for FC_INT0.HBR interrupt bit Value after Reset: 0b
        unsigned char ACP : 1; //!< Mask bit for FC_INT0.ACP interrupt bit Value after Reset: 0b
        unsigned char AUDI : 1; //!< Mask bit for FC_INT0.AUDI interrupt bit Value after Reset: 0b
    } B;
} hw_hdmi_fc_mask0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_MASK0 register
 */
#define HW_HDMI_FC_MASK0_ADDR      (REGS_HDMI_BASE + 0x10d2)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_MASK0           (*(volatile hw_hdmi_fc_mask0_t *) HW_HDMI_FC_MASK0_ADDR)
#define HW_HDMI_FC_MASK0_RD()      (HW_HDMI_FC_MASK0.U)
#define HW_HDMI_FC_MASK0_WR(v)     (HW_HDMI_FC_MASK0.U = (v))
#define HW_HDMI_FC_MASK0_SET(v)    (HW_HDMI_FC_MASK0_WR(HW_HDMI_FC_MASK0_RD() |  (v)))
#define HW_HDMI_FC_MASK0_CLR(v)    (HW_HDMI_FC_MASK0_WR(HW_HDMI_FC_MASK0_RD() & ~(v)))
#define HW_HDMI_FC_MASK0_TOG(v)    (HW_HDMI_FC_MASK0_WR(HW_HDMI_FC_MASK0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_MASK0 bitfields
 */

/* --- Register HW_HDMI_FC_MASK0, field NULL (RW)
 *
 * Mask bit for FC_INT0.NULL interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_MASK0_NULL      0
#define BM_HDMI_FC_MASK0_NULL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK0_NULL(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_MASK0_NULL)
#else
#define BF_HDMI_FC_MASK0_NULL(v)   (((v) << 0) & BM_HDMI_FC_MASK0_NULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NULL field to a new value.
#define BW_HDMI_FC_MASK0_NULL(v)   BF_CS1(HDMI_FC_MASK0, NULL, v)
#endif

/* --- Register HW_HDMI_FC_MASK0, field ACR (RW)
 *
 * Mask bit for FC_INT0.ACR interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_MASK0_ACR      1
#define BM_HDMI_FC_MASK0_ACR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK0_ACR(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_MASK0_ACR)
#else
#define BF_HDMI_FC_MASK0_ACR(v)   (((v) << 1) & BM_HDMI_FC_MASK0_ACR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACR field to a new value.
#define BW_HDMI_FC_MASK0_ACR(v)   BF_CS1(HDMI_FC_MASK0, ACR, v)
#endif

/* --- Register HW_HDMI_FC_MASK0, field AUDS (RW)
 *
 * Mask bit for FC_INT0.AUDS interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_MASK0_AUDS      2
#define BM_HDMI_FC_MASK0_AUDS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK0_AUDS(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_MASK0_AUDS)
#else
#define BF_HDMI_FC_MASK0_AUDS(v)   (((v) << 2) & BM_HDMI_FC_MASK0_AUDS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDS field to a new value.
#define BW_HDMI_FC_MASK0_AUDS(v)   BF_CS1(HDMI_FC_MASK0, AUDS, v)
#endif

/* --- Register HW_HDMI_FC_MASK0, field HBR (RW)
 *
 * Mask bit for FC_INT0.HBR interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_MASK0_HBR      5
#define BM_HDMI_FC_MASK0_HBR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK0_HBR(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_MASK0_HBR)
#else
#define BF_HDMI_FC_MASK0_HBR(v)   (((v) << 5) & BM_HDMI_FC_MASK0_HBR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBR field to a new value.
#define BW_HDMI_FC_MASK0_HBR(v)   BF_CS1(HDMI_FC_MASK0, HBR, v)
#endif

/* --- Register HW_HDMI_FC_MASK0, field ACP (RW)
 *
 * Mask bit for FC_INT0.ACP interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_MASK0_ACP      6
#define BM_HDMI_FC_MASK0_ACP      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK0_ACP(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_MASK0_ACP)
#else
#define BF_HDMI_FC_MASK0_ACP(v)   (((v) << 6) & BM_HDMI_FC_MASK0_ACP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACP field to a new value.
#define BW_HDMI_FC_MASK0_ACP(v)   BF_CS1(HDMI_FC_MASK0, ACP, v)
#endif

/* --- Register HW_HDMI_FC_MASK0, field AUDI (RW)
 *
 * Mask bit for FC_INT0.AUDI interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_MASK0_AUDI      7
#define BM_HDMI_FC_MASK0_AUDI      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK0_AUDI(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_MASK0_AUDI)
#else
#define BF_HDMI_FC_MASK0_AUDI(v)   (((v) << 7) & BM_HDMI_FC_MASK0_AUDI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDI field to a new value.
#define BW_HDMI_FC_MASK0_AUDI(v)   BF_CS1(HDMI_FC_MASK0, AUDI, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_POL0 - FC_POL0 (RW)
 *
 * Polarity register for generation of FC_INT0 interrupts.   Address Offset: 0x10D3  Size: 8 bits
 * Value after Reset: 0xFF  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char NULL : 1; //!< Polarity bit for FC_INT0.NULL interrupt bit Value after Reset: 0b
        unsigned char ACR : 1; //!< Polarity bit for FC_INT0.ACR interrupt bit Value after Reset: 0b
        unsigned char AUDS : 1; //!< Polarity bit for FC_INT0.AUDS interrupt bit Value after Reset: 0b
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char HBR : 1; //!< Polarity bit for FC_INT0.HBR interrupt bit Value after Reset: 0b
        unsigned char ACP : 1; //!< Polarity bit for FC_INT0.ACP interrupt bit Value after Reset: 0b
        unsigned char AUDI : 1; //!< Polarity bit for FC_INT0.AUDI interrupt bit Value after Reset: 0b
    } B;
} hw_hdmi_fc_pol0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_POL0 register
 */
#define HW_HDMI_FC_POL0_ADDR      (REGS_HDMI_BASE + 0x10d3)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_POL0           (*(volatile hw_hdmi_fc_pol0_t *) HW_HDMI_FC_POL0_ADDR)
#define HW_HDMI_FC_POL0_RD()      (HW_HDMI_FC_POL0.U)
#define HW_HDMI_FC_POL0_WR(v)     (HW_HDMI_FC_POL0.U = (v))
#define HW_HDMI_FC_POL0_SET(v)    (HW_HDMI_FC_POL0_WR(HW_HDMI_FC_POL0_RD() |  (v)))
#define HW_HDMI_FC_POL0_CLR(v)    (HW_HDMI_FC_POL0_WR(HW_HDMI_FC_POL0_RD() & ~(v)))
#define HW_HDMI_FC_POL0_TOG(v)    (HW_HDMI_FC_POL0_WR(HW_HDMI_FC_POL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_POL0 bitfields
 */

/* --- Register HW_HDMI_FC_POL0, field NULL (RW)
 *
 * Polarity bit for FC_INT0.NULL interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_POL0_NULL      0
#define BM_HDMI_FC_POL0_NULL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL0_NULL(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_POL0_NULL)
#else
#define BF_HDMI_FC_POL0_NULL(v)   (((v) << 0) & BM_HDMI_FC_POL0_NULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NULL field to a new value.
#define BW_HDMI_FC_POL0_NULL(v)   BF_CS1(HDMI_FC_POL0, NULL, v)
#endif

/* --- Register HW_HDMI_FC_POL0, field ACR (RW)
 *
 * Polarity bit for FC_INT0.ACR interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_POL0_ACR      1
#define BM_HDMI_FC_POL0_ACR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL0_ACR(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_POL0_ACR)
#else
#define BF_HDMI_FC_POL0_ACR(v)   (((v) << 1) & BM_HDMI_FC_POL0_ACR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACR field to a new value.
#define BW_HDMI_FC_POL0_ACR(v)   BF_CS1(HDMI_FC_POL0, ACR, v)
#endif

/* --- Register HW_HDMI_FC_POL0, field AUDS (RW)
 *
 * Polarity bit for FC_INT0.AUDS interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_POL0_AUDS      2
#define BM_HDMI_FC_POL0_AUDS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL0_AUDS(v)   ((((reg32_t) v) << 2) & BM_HDMI_FC_POL0_AUDS)
#else
#define BF_HDMI_FC_POL0_AUDS(v)   (((v) << 2) & BM_HDMI_FC_POL0_AUDS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDS field to a new value.
#define BW_HDMI_FC_POL0_AUDS(v)   BF_CS1(HDMI_FC_POL0, AUDS, v)
#endif

/* --- Register HW_HDMI_FC_POL0, field HBR (RW)
 *
 * Polarity bit for FC_INT0.HBR interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_POL0_HBR      5
#define BM_HDMI_FC_POL0_HBR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL0_HBR(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_POL0_HBR)
#else
#define BF_HDMI_FC_POL0_HBR(v)   (((v) << 5) & BM_HDMI_FC_POL0_HBR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBR field to a new value.
#define BW_HDMI_FC_POL0_HBR(v)   BF_CS1(HDMI_FC_POL0, HBR, v)
#endif

/* --- Register HW_HDMI_FC_POL0, field ACP (RW)
 *
 * Polarity bit for FC_INT0.ACP interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_POL0_ACP      6
#define BM_HDMI_FC_POL0_ACP      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL0_ACP(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_POL0_ACP)
#else
#define BF_HDMI_FC_POL0_ACP(v)   (((v) << 6) & BM_HDMI_FC_POL0_ACP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACP field to a new value.
#define BW_HDMI_FC_POL0_ACP(v)   BF_CS1(HDMI_FC_POL0, ACP, v)
#endif

/* --- Register HW_HDMI_FC_POL0, field AUDI (RW)
 *
 * Polarity bit for FC_INT0.AUDI interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_POL0_AUDI      7
#define BM_HDMI_FC_POL0_AUDI      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL0_AUDI(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_POL0_AUDI)
#else
#define BF_HDMI_FC_POL0_AUDI(v)   (((v) << 7) & BM_HDMI_FC_POL0_AUDI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDI field to a new value.
#define BW_HDMI_FC_POL0_AUDI(v)   BF_CS1(HDMI_FC_POL0, AUDI, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_STAT1 - FC_STAT1 (RW)
 *
 * This register contains the following active high packet sent status indications:   Address
 * Offset: 0x10D4  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GCP : 1; //!< Status bit Active after successful transmission of an General Content Packet.
        unsigned char AVI : 1; //!< Status bit Active after successful transmission of an AVI infoFrame packet.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char SPD : 1; //!< Active after successful transmission of an Source Product Descriptor infoFrame packet.
        unsigned char VSD : 1; //!< Active after successful transmission of an Vendor Specific Data infoFrame packet.
        unsigned char ISCR2 : 1; //!< Active after successful transmission of an International Standard Recording Code 2 packet.
        unsigned char ISCR1 : 1; //!< Status bit Active after successful transmission of an International Standard Recording Code 1 packet.
        unsigned char GMD : 1; //!< Status bit Active after successful transmission of an Gamut metadata packet.
    } B;
} hw_hdmi_fc_stat1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_STAT1 register
 */
#define HW_HDMI_FC_STAT1_ADDR      (REGS_HDMI_BASE + 0x10d4)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_STAT1           (*(volatile hw_hdmi_fc_stat1_t *) HW_HDMI_FC_STAT1_ADDR)
#define HW_HDMI_FC_STAT1_RD()      (HW_HDMI_FC_STAT1.U)
#define HW_HDMI_FC_STAT1_WR(v)     (HW_HDMI_FC_STAT1.U = (v))
#define HW_HDMI_FC_STAT1_SET(v)    (HW_HDMI_FC_STAT1_WR(HW_HDMI_FC_STAT1_RD() |  (v)))
#define HW_HDMI_FC_STAT1_CLR(v)    (HW_HDMI_FC_STAT1_WR(HW_HDMI_FC_STAT1_RD() & ~(v)))
#define HW_HDMI_FC_STAT1_TOG(v)    (HW_HDMI_FC_STAT1_WR(HW_HDMI_FC_STAT1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_STAT1 bitfields
 */

/* --- Register HW_HDMI_FC_STAT1, field GCP (RW)
 *
 * Status bit Active after successful transmission of an General Content Packet.
 */

#define BP_HDMI_FC_STAT1_GCP      0
#define BM_HDMI_FC_STAT1_GCP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT1_GCP(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_STAT1_GCP)
#else
#define BF_HDMI_FC_STAT1_GCP(v)   (((v) << 0) & BM_HDMI_FC_STAT1_GCP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCP field to a new value.
#define BW_HDMI_FC_STAT1_GCP(v)   BF_CS1(HDMI_FC_STAT1, GCP, v)
#endif

/* --- Register HW_HDMI_FC_STAT1, field AVI (RW)
 *
 * Status bit Active after successful transmission of an AVI infoFrame packet.
 */

#define BP_HDMI_FC_STAT1_AVI      1
#define BM_HDMI_FC_STAT1_AVI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT1_AVI(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_STAT1_AVI)
#else
#define BF_HDMI_FC_STAT1_AVI(v)   (((v) << 1) & BM_HDMI_FC_STAT1_AVI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVI field to a new value.
#define BW_HDMI_FC_STAT1_AVI(v)   BF_CS1(HDMI_FC_STAT1, AVI, v)
#endif

/* --- Register HW_HDMI_FC_STAT1, field SPD (RW)
 *
 * Active after successful transmission of an Source Product Descriptor infoFrame packet.
 */

#define BP_HDMI_FC_STAT1_SPD      3
#define BM_HDMI_FC_STAT1_SPD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT1_SPD(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_STAT1_SPD)
#else
#define BF_HDMI_FC_STAT1_SPD(v)   (((v) << 3) & BM_HDMI_FC_STAT1_SPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SPD field to a new value.
#define BW_HDMI_FC_STAT1_SPD(v)   BF_CS1(HDMI_FC_STAT1, SPD, v)
#endif

/* --- Register HW_HDMI_FC_STAT1, field VSD (RW)
 *
 * Active after successful transmission of an Vendor Specific Data infoFrame packet.
 */

#define BP_HDMI_FC_STAT1_VSD      4
#define BM_HDMI_FC_STAT1_VSD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT1_VSD(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_STAT1_VSD)
#else
#define BF_HDMI_FC_STAT1_VSD(v)   (((v) << 4) & BM_HDMI_FC_STAT1_VSD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSD field to a new value.
#define BW_HDMI_FC_STAT1_VSD(v)   BF_CS1(HDMI_FC_STAT1, VSD, v)
#endif

/* --- Register HW_HDMI_FC_STAT1, field ISCR2 (RW)
 *
 * Active after successful transmission of an International Standard Recording Code 2 packet.
 */

#define BP_HDMI_FC_STAT1_ISCR2      5
#define BM_HDMI_FC_STAT1_ISCR2      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT1_ISCR2(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_STAT1_ISCR2)
#else
#define BF_HDMI_FC_STAT1_ISCR2(v)   (((v) << 5) & BM_HDMI_FC_STAT1_ISCR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR2 field to a new value.
#define BW_HDMI_FC_STAT1_ISCR2(v)   BF_CS1(HDMI_FC_STAT1, ISCR2, v)
#endif

/* --- Register HW_HDMI_FC_STAT1, field ISCR1 (RW)
 *
 * Status bit Active after successful transmission of an International Standard Recording Code 1
 * packet.
 */

#define BP_HDMI_FC_STAT1_ISCR1      6
#define BM_HDMI_FC_STAT1_ISCR1      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT1_ISCR1(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_STAT1_ISCR1)
#else
#define BF_HDMI_FC_STAT1_ISCR1(v)   (((v) << 6) & BM_HDMI_FC_STAT1_ISCR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR1 field to a new value.
#define BW_HDMI_FC_STAT1_ISCR1(v)   BF_CS1(HDMI_FC_STAT1, ISCR1, v)
#endif

/* --- Register HW_HDMI_FC_STAT1, field GMD (RW)
 *
 * Status bit Active after successful transmission of an Gamut metadata packet.
 */

#define BP_HDMI_FC_STAT1_GMD      7
#define BM_HDMI_FC_STAT1_GMD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT1_GMD(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_STAT1_GMD)
#else
#define BF_HDMI_FC_STAT1_GMD(v)   (((v) << 7) & BM_HDMI_FC_STAT1_GMD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMD field to a new value.
#define BW_HDMI_FC_STAT1_GMD(v)   BF_CS1(HDMI_FC_STAT1, GMD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INT1 - FC_INT1 (RW)
 *
 * This register contains the interrupt indication of the FC_STAT1 status interrupts. Interrupt
 * generation is accomplished in the following way:  interrupt = (mask == 1'b0) && (polarity ==
 * status);  All this interrupts are forwarded to the Interrupt Handler sticky bit registers and
 * after ORed to a single main interrupt line to micro controller. Assertion of this interrupt
 * implies that data related with the corresponding packet has been sent through the HDMI interface.
 * Address Offset: 0x10D5  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GCP : 1; //!< Interrupt indication bit Active after successful transmission of an General Content Packet interrupt.
        unsigned char AVI : 1; //!< Interrupt indication bit Active after successful transmission of an AVI infoFrame packet interrupt.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char SPD : 1; //!< Interrupt indication bit Active after successful transmission of an Source Product Descriptor infoFrame packet interrupt.
        unsigned char VSD : 1; //!< Interrupt indication bit Active after successful transmission of an Vendor Specific Data infoFrame packet interrupt.
        unsigned char ISCR2 : 1; //!< Interrupt indication bit Active after successful transmission of an International Standard Recording Code 2 packet interrupt.
        unsigned char ISCR1 : 1; //!< Interrupt indication bit Active after successful transmission of an International Standard Recording Code 1 packet interrupt.
        unsigned char GMD : 1; //!< Interrupt indication bit Active after successful transmission of an Gamut metadata packet interrupt.
    } B;
} hw_hdmi_fc_int1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INT1 register
 */
#define HW_HDMI_FC_INT1_ADDR      (REGS_HDMI_BASE + 0x10d5)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INT1           (*(volatile hw_hdmi_fc_int1_t *) HW_HDMI_FC_INT1_ADDR)
#define HW_HDMI_FC_INT1_RD()      (HW_HDMI_FC_INT1.U)
#define HW_HDMI_FC_INT1_WR(v)     (HW_HDMI_FC_INT1.U = (v))
#define HW_HDMI_FC_INT1_SET(v)    (HW_HDMI_FC_INT1_WR(HW_HDMI_FC_INT1_RD() |  (v)))
#define HW_HDMI_FC_INT1_CLR(v)    (HW_HDMI_FC_INT1_WR(HW_HDMI_FC_INT1_RD() & ~(v)))
#define HW_HDMI_FC_INT1_TOG(v)    (HW_HDMI_FC_INT1_WR(HW_HDMI_FC_INT1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INT1 bitfields
 */

/* --- Register HW_HDMI_FC_INT1, field GCP (RW)
 *
 * Interrupt indication bit Active after successful transmission of an General Content Packet
 * interrupt.
 */

#define BP_HDMI_FC_INT1_GCP      0
#define BM_HDMI_FC_INT1_GCP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT1_GCP(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INT1_GCP)
#else
#define BF_HDMI_FC_INT1_GCP(v)   (((v) << 0) & BM_HDMI_FC_INT1_GCP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCP field to a new value.
#define BW_HDMI_FC_INT1_GCP(v)   BF_CS1(HDMI_FC_INT1, GCP, v)
#endif

/* --- Register HW_HDMI_FC_INT1, field AVI (RW)
 *
 * Interrupt indication bit Active after successful transmission of an AVI infoFrame packet
 * interrupt.
 */

#define BP_HDMI_FC_INT1_AVI      1
#define BM_HDMI_FC_INT1_AVI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT1_AVI(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_INT1_AVI)
#else
#define BF_HDMI_FC_INT1_AVI(v)   (((v) << 1) & BM_HDMI_FC_INT1_AVI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVI field to a new value.
#define BW_HDMI_FC_INT1_AVI(v)   BF_CS1(HDMI_FC_INT1, AVI, v)
#endif

/* --- Register HW_HDMI_FC_INT1, field SPD (RW)
 *
 * Interrupt indication bit Active after successful transmission of an Source Product Descriptor
 * infoFrame packet interrupt.
 */

#define BP_HDMI_FC_INT1_SPD      3
#define BM_HDMI_FC_INT1_SPD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT1_SPD(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_INT1_SPD)
#else
#define BF_HDMI_FC_INT1_SPD(v)   (((v) << 3) & BM_HDMI_FC_INT1_SPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SPD field to a new value.
#define BW_HDMI_FC_INT1_SPD(v)   BF_CS1(HDMI_FC_INT1, SPD, v)
#endif

/* --- Register HW_HDMI_FC_INT1, field VSD (RW)
 *
 * Interrupt indication bit Active after successful transmission of an Vendor Specific Data
 * infoFrame packet interrupt.
 */

#define BP_HDMI_FC_INT1_VSD      4
#define BM_HDMI_FC_INT1_VSD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT1_VSD(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_INT1_VSD)
#else
#define BF_HDMI_FC_INT1_VSD(v)   (((v) << 4) & BM_HDMI_FC_INT1_VSD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSD field to a new value.
#define BW_HDMI_FC_INT1_VSD(v)   BF_CS1(HDMI_FC_INT1, VSD, v)
#endif

/* --- Register HW_HDMI_FC_INT1, field ISCR2 (RW)
 *
 * Interrupt indication bit Active after successful transmission of an International Standard
 * Recording Code 2 packet interrupt.
 */

#define BP_HDMI_FC_INT1_ISCR2      5
#define BM_HDMI_FC_INT1_ISCR2      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT1_ISCR2(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_INT1_ISCR2)
#else
#define BF_HDMI_FC_INT1_ISCR2(v)   (((v) << 5) & BM_HDMI_FC_INT1_ISCR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR2 field to a new value.
#define BW_HDMI_FC_INT1_ISCR2(v)   BF_CS1(HDMI_FC_INT1, ISCR2, v)
#endif

/* --- Register HW_HDMI_FC_INT1, field ISCR1 (RW)
 *
 * Interrupt indication bit Active after successful transmission of an International Standard
 * Recording Code 1 packet interrupt.
 */

#define BP_HDMI_FC_INT1_ISCR1      6
#define BM_HDMI_FC_INT1_ISCR1      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT1_ISCR1(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_INT1_ISCR1)
#else
#define BF_HDMI_FC_INT1_ISCR1(v)   (((v) << 6) & BM_HDMI_FC_INT1_ISCR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR1 field to a new value.
#define BW_HDMI_FC_INT1_ISCR1(v)   BF_CS1(HDMI_FC_INT1, ISCR1, v)
#endif

/* --- Register HW_HDMI_FC_INT1, field GMD (RW)
 *
 * Interrupt indication bit Active after successful transmission of an Gamut metadata packet
 * interrupt.
 */

#define BP_HDMI_FC_INT1_GMD      7
#define BM_HDMI_FC_INT1_GMD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT1_GMD(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_INT1_GMD)
#else
#define BF_HDMI_FC_INT1_GMD(v)   (((v) << 7) & BM_HDMI_FC_INT1_GMD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMD field to a new value.
#define BW_HDMI_FC_INT1_GMD(v)   BF_CS1(HDMI_FC_INT1, GMD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_MASK1 - Frame Composer Packet Interrupt Mask Register 1 (RW)
 *
 * Mask register for generation of FC_INT1 interrupts.   Address Offset: 0x10D6  Size: 8 bits  Value
 * after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GCP : 1; //!< Mask bit for FC_INT1.GCP interrupt bit
        unsigned char AVI : 1; //!< Mask bit for FC_INT1.AVI interrupt bit
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char SPD : 1; //!< Mask bit for FC_INT1.SPD interrupt bit
        unsigned char VSD : 1; //!< Mask bit for FC_INT1.VSD interrupt bit
        unsigned char ISCR2 : 1; //!< Mask bit for FC_INT1.ISRC2 interrupt bit
        unsigned char ISCR1 : 1; //!< Mask bit for FC_INT1.ISRC1 interrupt bit
        unsigned char GMD : 1; //!< Mask bit for FC_INT1.GMD interrupt bit
    } B;
} hw_hdmi_fc_mask1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_MASK1 register
 */
#define HW_HDMI_FC_MASK1_ADDR      (REGS_HDMI_BASE + 0x10d6)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_MASK1           (*(volatile hw_hdmi_fc_mask1_t *) HW_HDMI_FC_MASK1_ADDR)
#define HW_HDMI_FC_MASK1_RD()      (HW_HDMI_FC_MASK1.U)
#define HW_HDMI_FC_MASK1_WR(v)     (HW_HDMI_FC_MASK1.U = (v))
#define HW_HDMI_FC_MASK1_SET(v)    (HW_HDMI_FC_MASK1_WR(HW_HDMI_FC_MASK1_RD() |  (v)))
#define HW_HDMI_FC_MASK1_CLR(v)    (HW_HDMI_FC_MASK1_WR(HW_HDMI_FC_MASK1_RD() & ~(v)))
#define HW_HDMI_FC_MASK1_TOG(v)    (HW_HDMI_FC_MASK1_WR(HW_HDMI_FC_MASK1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_MASK1 bitfields
 */

/* --- Register HW_HDMI_FC_MASK1, field GCP (RW)
 *
 * Mask bit for FC_INT1.GCP interrupt bit
 */

#define BP_HDMI_FC_MASK1_GCP      0
#define BM_HDMI_FC_MASK1_GCP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK1_GCP(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_MASK1_GCP)
#else
#define BF_HDMI_FC_MASK1_GCP(v)   (((v) << 0) & BM_HDMI_FC_MASK1_GCP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCP field to a new value.
#define BW_HDMI_FC_MASK1_GCP(v)   BF_CS1(HDMI_FC_MASK1, GCP, v)
#endif

/* --- Register HW_HDMI_FC_MASK1, field AVI (RW)
 *
 * Mask bit for FC_INT1.AVI interrupt bit
 */

#define BP_HDMI_FC_MASK1_AVI      1
#define BM_HDMI_FC_MASK1_AVI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK1_AVI(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_MASK1_AVI)
#else
#define BF_HDMI_FC_MASK1_AVI(v)   (((v) << 1) & BM_HDMI_FC_MASK1_AVI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVI field to a new value.
#define BW_HDMI_FC_MASK1_AVI(v)   BF_CS1(HDMI_FC_MASK1, AVI, v)
#endif

/* --- Register HW_HDMI_FC_MASK1, field SPD (RW)
 *
 * Mask bit for FC_INT1.SPD interrupt bit
 */

#define BP_HDMI_FC_MASK1_SPD      3
#define BM_HDMI_FC_MASK1_SPD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK1_SPD(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_MASK1_SPD)
#else
#define BF_HDMI_FC_MASK1_SPD(v)   (((v) << 3) & BM_HDMI_FC_MASK1_SPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SPD field to a new value.
#define BW_HDMI_FC_MASK1_SPD(v)   BF_CS1(HDMI_FC_MASK1, SPD, v)
#endif

/* --- Register HW_HDMI_FC_MASK1, field VSD (RW)
 *
 * Mask bit for FC_INT1.VSD interrupt bit
 */

#define BP_HDMI_FC_MASK1_VSD      4
#define BM_HDMI_FC_MASK1_VSD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK1_VSD(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_MASK1_VSD)
#else
#define BF_HDMI_FC_MASK1_VSD(v)   (((v) << 4) & BM_HDMI_FC_MASK1_VSD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSD field to a new value.
#define BW_HDMI_FC_MASK1_VSD(v)   BF_CS1(HDMI_FC_MASK1, VSD, v)
#endif

/* --- Register HW_HDMI_FC_MASK1, field ISCR2 (RW)
 *
 * Mask bit for FC_INT1.ISRC2 interrupt bit
 */

#define BP_HDMI_FC_MASK1_ISCR2      5
#define BM_HDMI_FC_MASK1_ISCR2      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK1_ISCR2(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_MASK1_ISCR2)
#else
#define BF_HDMI_FC_MASK1_ISCR2(v)   (((v) << 5) & BM_HDMI_FC_MASK1_ISCR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR2 field to a new value.
#define BW_HDMI_FC_MASK1_ISCR2(v)   BF_CS1(HDMI_FC_MASK1, ISCR2, v)
#endif

/* --- Register HW_HDMI_FC_MASK1, field ISCR1 (RW)
 *
 * Mask bit for FC_INT1.ISRC1 interrupt bit
 */

#define BP_HDMI_FC_MASK1_ISCR1      6
#define BM_HDMI_FC_MASK1_ISCR1      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK1_ISCR1(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_MASK1_ISCR1)
#else
#define BF_HDMI_FC_MASK1_ISCR1(v)   (((v) << 6) & BM_HDMI_FC_MASK1_ISCR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR1 field to a new value.
#define BW_HDMI_FC_MASK1_ISCR1(v)   BF_CS1(HDMI_FC_MASK1, ISCR1, v)
#endif

/* --- Register HW_HDMI_FC_MASK1, field GMD (RW)
 *
 * Mask bit for FC_INT1.GMD interrupt bit
 */

#define BP_HDMI_FC_MASK1_GMD      7
#define BM_HDMI_FC_MASK1_GMD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK1_GMD(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_MASK1_GMD)
#else
#define BF_HDMI_FC_MASK1_GMD(v)   (((v) << 7) & BM_HDMI_FC_MASK1_GMD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMD field to a new value.
#define BW_HDMI_FC_MASK1_GMD(v)   BF_CS1(HDMI_FC_MASK1, GMD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_POL1 - FC_POL1 (RW)
 *
 * Polarity register for generation of FC_INT1 interrupts.   Address Offset: 0x10D7  Size: 8 bits
 * Value after Reset: 0xFF  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GCP : 1; //!< Polarity bit for FC_INT1.GCP interrupt bit
        unsigned char AVI : 1; //!< Polarity bit for FC_INT1.AVI interrupt bit
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char SPD : 1; //!< Polarity bit for FC_INT1.SPD interrupt bit
        unsigned char VSD : 1; //!< Polarity bit for FC_INT1.VSD interrupt bit
        unsigned char ISCR2 : 1; //!< Polarity bit for FC_INT1.ISRC2 interrupt bit
        unsigned char ISCR1 : 1; //!< Polarity bit for FC_INT1.ISRC1 interrupt bit
        unsigned char GMD : 1; //!< Polarity bit for FC_INT1.GMD interrupt bit
    } B;
} hw_hdmi_fc_pol1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_POL1 register
 */
#define HW_HDMI_FC_POL1_ADDR      (REGS_HDMI_BASE + 0x10d7)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_POL1           (*(volatile hw_hdmi_fc_pol1_t *) HW_HDMI_FC_POL1_ADDR)
#define HW_HDMI_FC_POL1_RD()      (HW_HDMI_FC_POL1.U)
#define HW_HDMI_FC_POL1_WR(v)     (HW_HDMI_FC_POL1.U = (v))
#define HW_HDMI_FC_POL1_SET(v)    (HW_HDMI_FC_POL1_WR(HW_HDMI_FC_POL1_RD() |  (v)))
#define HW_HDMI_FC_POL1_CLR(v)    (HW_HDMI_FC_POL1_WR(HW_HDMI_FC_POL1_RD() & ~(v)))
#define HW_HDMI_FC_POL1_TOG(v)    (HW_HDMI_FC_POL1_WR(HW_HDMI_FC_POL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_POL1 bitfields
 */

/* --- Register HW_HDMI_FC_POL1, field GCP (RW)
 *
 * Polarity bit for FC_INT1.GCP interrupt bit
 */

#define BP_HDMI_FC_POL1_GCP      0
#define BM_HDMI_FC_POL1_GCP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL1_GCP(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_POL1_GCP)
#else
#define BF_HDMI_FC_POL1_GCP(v)   (((v) << 0) & BM_HDMI_FC_POL1_GCP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GCP field to a new value.
#define BW_HDMI_FC_POL1_GCP(v)   BF_CS1(HDMI_FC_POL1, GCP, v)
#endif

/* --- Register HW_HDMI_FC_POL1, field AVI (RW)
 *
 * Polarity bit for FC_INT1.AVI interrupt bit
 */

#define BP_HDMI_FC_POL1_AVI      1
#define BM_HDMI_FC_POL1_AVI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL1_AVI(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_POL1_AVI)
#else
#define BF_HDMI_FC_POL1_AVI(v)   (((v) << 1) & BM_HDMI_FC_POL1_AVI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVI field to a new value.
#define BW_HDMI_FC_POL1_AVI(v)   BF_CS1(HDMI_FC_POL1, AVI, v)
#endif

/* --- Register HW_HDMI_FC_POL1, field SPD (RW)
 *
 * Polarity bit for FC_INT1.SPD interrupt bit
 */

#define BP_HDMI_FC_POL1_SPD      3
#define BM_HDMI_FC_POL1_SPD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL1_SPD(v)   ((((reg32_t) v) << 3) & BM_HDMI_FC_POL1_SPD)
#else
#define BF_HDMI_FC_POL1_SPD(v)   (((v) << 3) & BM_HDMI_FC_POL1_SPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SPD field to a new value.
#define BW_HDMI_FC_POL1_SPD(v)   BF_CS1(HDMI_FC_POL1, SPD, v)
#endif

/* --- Register HW_HDMI_FC_POL1, field VSD (RW)
 *
 * Polarity bit for FC_INT1.VSD interrupt bit
 */

#define BP_HDMI_FC_POL1_VSD      4
#define BM_HDMI_FC_POL1_VSD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL1_VSD(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_POL1_VSD)
#else
#define BF_HDMI_FC_POL1_VSD(v)   (((v) << 4) & BM_HDMI_FC_POL1_VSD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSD field to a new value.
#define BW_HDMI_FC_POL1_VSD(v)   BF_CS1(HDMI_FC_POL1, VSD, v)
#endif

/* --- Register HW_HDMI_FC_POL1, field ISCR2 (RW)
 *
 * Polarity bit for FC_INT1.ISRC2 interrupt bit
 */

#define BP_HDMI_FC_POL1_ISCR2      5
#define BM_HDMI_FC_POL1_ISCR2      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL1_ISCR2(v)   ((((reg32_t) v) << 5) & BM_HDMI_FC_POL1_ISCR2)
#else
#define BF_HDMI_FC_POL1_ISCR2(v)   (((v) << 5) & BM_HDMI_FC_POL1_ISCR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR2 field to a new value.
#define BW_HDMI_FC_POL1_ISCR2(v)   BF_CS1(HDMI_FC_POL1, ISCR2, v)
#endif

/* --- Register HW_HDMI_FC_POL1, field ISCR1 (RW)
 *
 * Polarity bit for FC_INT1.ISRC1 interrupt bit
 */

#define BP_HDMI_FC_POL1_ISCR1      6
#define BM_HDMI_FC_POL1_ISCR1      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL1_ISCR1(v)   ((((reg32_t) v) << 6) & BM_HDMI_FC_POL1_ISCR1)
#else
#define BF_HDMI_FC_POL1_ISCR1(v)   (((v) << 6) & BM_HDMI_FC_POL1_ISCR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISCR1 field to a new value.
#define BW_HDMI_FC_POL1_ISCR1(v)   BF_CS1(HDMI_FC_POL1, ISCR1, v)
#endif

/* --- Register HW_HDMI_FC_POL1, field GMD (RW)
 *
 * Polarity bit for FC_INT1.GMD interrupt bit
 */

#define BP_HDMI_FC_POL1_GMD      7
#define BM_HDMI_FC_POL1_GMD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL1_GMD(v)   ((((reg32_t) v) << 7) & BM_HDMI_FC_POL1_GMD)
#else
#define BF_HDMI_FC_POL1_GMD(v)   (((v) << 7) & BM_HDMI_FC_POL1_GMD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMD field to a new value.
#define BW_HDMI_FC_POL1_GMD(v)   BF_CS1(HDMI_FC_POL1, GMD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_STAT2 - FC_STAT2 (RW)
 *
 * This register contains the following active high packet sent status indications:   Address
 * Offset: 0x10D8  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HIGHPRIORITY_OVERFLOW : 1; //!< Status bit Frame Composer high priority packet queue descriptor overflow indication.
        unsigned char LOWPRIORITY_OVERFLOW : 1; //!< Status bit Frame Composer low priority packet queue descriptor overflow indication.
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_fc_stat2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_STAT2 register
 */
#define HW_HDMI_FC_STAT2_ADDR      (REGS_HDMI_BASE + 0x10d8)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_STAT2           (*(volatile hw_hdmi_fc_stat2_t *) HW_HDMI_FC_STAT2_ADDR)
#define HW_HDMI_FC_STAT2_RD()      (HW_HDMI_FC_STAT2.U)
#define HW_HDMI_FC_STAT2_WR(v)     (HW_HDMI_FC_STAT2.U = (v))
#define HW_HDMI_FC_STAT2_SET(v)    (HW_HDMI_FC_STAT2_WR(HW_HDMI_FC_STAT2_RD() |  (v)))
#define HW_HDMI_FC_STAT2_CLR(v)    (HW_HDMI_FC_STAT2_WR(HW_HDMI_FC_STAT2_RD() & ~(v)))
#define HW_HDMI_FC_STAT2_TOG(v)    (HW_HDMI_FC_STAT2_WR(HW_HDMI_FC_STAT2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_STAT2 bitfields
 */

/* --- Register HW_HDMI_FC_STAT2, field HIGHPRIORITY_OVERFLOW (RW)
 *
 * Status bit Frame Composer high priority packet queue descriptor overflow indication.
 */

#define BP_HDMI_FC_STAT2_HIGHPRIORITY_OVERFLOW      0
#define BM_HDMI_FC_STAT2_HIGHPRIORITY_OVERFLOW      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT2_HIGHPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_STAT2_HIGHPRIORITY_OVERFLOW)
#else
#define BF_HDMI_FC_STAT2_HIGHPRIORITY_OVERFLOW(v)   (((v) << 0) & BM_HDMI_FC_STAT2_HIGHPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HIGHPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_FC_STAT2_HIGHPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_FC_STAT2, HIGHPRIORITY_OVERFLOW, v)
#endif

/* --- Register HW_HDMI_FC_STAT2, field LOWPRIORITY_OVERFLOW (RW)
 *
 * Status bit Frame Composer low priority packet queue descriptor overflow indication.
 */

#define BP_HDMI_FC_STAT2_LOWPRIORITY_OVERFLOW      1
#define BM_HDMI_FC_STAT2_LOWPRIORITY_OVERFLOW      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_STAT2_LOWPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_STAT2_LOWPRIORITY_OVERFLOW)
#else
#define BF_HDMI_FC_STAT2_LOWPRIORITY_OVERFLOW(v)   (((v) << 1) & BM_HDMI_FC_STAT2_LOWPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOWPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_FC_STAT2_LOWPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_FC_STAT2, LOWPRIORITY_OVERFLOW, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_INT2 - FC_INT2 (RW)
 *
 * This register contains the interrupt indication of the FC_STAT2 status interrupts. Interrupt
 * generation is accomplished in the following way:  interrupt = (mask == 1'b0) && (polarity ==
 * status);  All this interrupts are forwarded to the Interrupt Handler sticky bit registers and
 * after ORed to a single main interrupt line to micro controller. Assertion of this interrupt
 * implies that data related with the corresponding packet has been sent through the HDMI interface.
 * Address Offset: 0x10D9  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HIGHPRIORITY_OVERFLOW : 1; //!< Interrupt indication bit Frame Composer high priority packet queue descriptor overflow indication interrupt.
        unsigned char LOWPRIORITY_OVERFLOW : 1; //!< Interrupt indication bit Frame Composer low priority packet queue descriptor overflow indication interrupt.
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_fc_int2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_INT2 register
 */
#define HW_HDMI_FC_INT2_ADDR      (REGS_HDMI_BASE + 0x10d9)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_INT2           (*(volatile hw_hdmi_fc_int2_t *) HW_HDMI_FC_INT2_ADDR)
#define HW_HDMI_FC_INT2_RD()      (HW_HDMI_FC_INT2.U)
#define HW_HDMI_FC_INT2_WR(v)     (HW_HDMI_FC_INT2.U = (v))
#define HW_HDMI_FC_INT2_SET(v)    (HW_HDMI_FC_INT2_WR(HW_HDMI_FC_INT2_RD() |  (v)))
#define HW_HDMI_FC_INT2_CLR(v)    (HW_HDMI_FC_INT2_WR(HW_HDMI_FC_INT2_RD() & ~(v)))
#define HW_HDMI_FC_INT2_TOG(v)    (HW_HDMI_FC_INT2_WR(HW_HDMI_FC_INT2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_INT2 bitfields
 */

/* --- Register HW_HDMI_FC_INT2, field HIGHPRIORITY_OVERFLOW (RW)
 *
 * Interrupt indication bit Frame Composer high priority packet queue descriptor overflow indication
 * interrupt.
 */

#define BP_HDMI_FC_INT2_HIGHPRIORITY_OVERFLOW      0
#define BM_HDMI_FC_INT2_HIGHPRIORITY_OVERFLOW      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT2_HIGHPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_INT2_HIGHPRIORITY_OVERFLOW)
#else
#define BF_HDMI_FC_INT2_HIGHPRIORITY_OVERFLOW(v)   (((v) << 0) & BM_HDMI_FC_INT2_HIGHPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HIGHPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_FC_INT2_HIGHPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_FC_INT2, HIGHPRIORITY_OVERFLOW, v)
#endif

/* --- Register HW_HDMI_FC_INT2, field LOWPRIORITY_OVERFLOW (RW)
 *
 * Interrupt indication bit Frame Composer low priority packet queue descriptor overflow indication
 * interrupt.
 */

#define BP_HDMI_FC_INT2_LOWPRIORITY_OVERFLOW      1
#define BM_HDMI_FC_INT2_LOWPRIORITY_OVERFLOW      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_INT2_LOWPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_INT2_LOWPRIORITY_OVERFLOW)
#else
#define BF_HDMI_FC_INT2_LOWPRIORITY_OVERFLOW(v)   (((v) << 1) & BM_HDMI_FC_INT2_LOWPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOWPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_FC_INT2_LOWPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_FC_INT2, LOWPRIORITY_OVERFLOW, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_MASK2 - Frame Composer High/Low Priority Overflow Interrupt Mask Register 2 (RW)
 *
 * Mask register for generation of FC_INT2 interrupts.   Address Offset: 0x10DA  Size: 8 bits  Value
 * after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HIGHPRIORITY_OVERFLOW : 1; //!< Mask bit for FC_INT1.HighPriority_overflow interrupt bit Value after Reset: 0b
        unsigned char LOWPRIORITY_OVERFLOW : 1; //!< Mask bit for FC_INT1.LowPriority_overflow interrupt bit Value after Reset: 0b
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_fc_mask2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_MASK2 register
 */
#define HW_HDMI_FC_MASK2_ADDR      (REGS_HDMI_BASE + 0x10da)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_MASK2           (*(volatile hw_hdmi_fc_mask2_t *) HW_HDMI_FC_MASK2_ADDR)
#define HW_HDMI_FC_MASK2_RD()      (HW_HDMI_FC_MASK2.U)
#define HW_HDMI_FC_MASK2_WR(v)     (HW_HDMI_FC_MASK2.U = (v))
#define HW_HDMI_FC_MASK2_SET(v)    (HW_HDMI_FC_MASK2_WR(HW_HDMI_FC_MASK2_RD() |  (v)))
#define HW_HDMI_FC_MASK2_CLR(v)    (HW_HDMI_FC_MASK2_WR(HW_HDMI_FC_MASK2_RD() & ~(v)))
#define HW_HDMI_FC_MASK2_TOG(v)    (HW_HDMI_FC_MASK2_WR(HW_HDMI_FC_MASK2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_MASK2 bitfields
 */

/* --- Register HW_HDMI_FC_MASK2, field HIGHPRIORITY_OVERFLOW (RW)
 *
 * Mask bit for FC_INT1.HighPriority_overflow interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_MASK2_HIGHPRIORITY_OVERFLOW      0
#define BM_HDMI_FC_MASK2_HIGHPRIORITY_OVERFLOW      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK2_HIGHPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_MASK2_HIGHPRIORITY_OVERFLOW)
#else
#define BF_HDMI_FC_MASK2_HIGHPRIORITY_OVERFLOW(v)   (((v) << 0) & BM_HDMI_FC_MASK2_HIGHPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HIGHPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_FC_MASK2_HIGHPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_FC_MASK2, HIGHPRIORITY_OVERFLOW, v)
#endif

/* --- Register HW_HDMI_FC_MASK2, field LOWPRIORITY_OVERFLOW (RW)
 *
 * Mask bit for FC_INT1.LowPriority_overflow interrupt bit Value after Reset: 0b
 */

#define BP_HDMI_FC_MASK2_LOWPRIORITY_OVERFLOW      1
#define BM_HDMI_FC_MASK2_LOWPRIORITY_OVERFLOW      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_MASK2_LOWPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_MASK2_LOWPRIORITY_OVERFLOW)
#else
#define BF_HDMI_FC_MASK2_LOWPRIORITY_OVERFLOW(v)   (((v) << 1) & BM_HDMI_FC_MASK2_LOWPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOWPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_FC_MASK2_LOWPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_FC_MASK2, LOWPRIORITY_OVERFLOW, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_POL2 - FC_POL2 (RW)
 *
 * Polarity register for generation of FC_INT2 interrupts.   Address Offset: 0x10DB  Size: 8 bits
 * Value after Reset: 0x03  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HIGHPRIORITY_OVERFLOW : 1; //!< Polarity bit for FC_INT1.HighPriority_overflow interrupt bit Value after Reset: 1b
        unsigned char LOWPRIORITY_OVERFLOW : 1; //!< Polarity bit for FC_INT1.LowPriority_overflow interrupt bit Value after Reset: 1b
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_fc_pol2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_POL2 register
 */
#define HW_HDMI_FC_POL2_ADDR      (REGS_HDMI_BASE + 0x10db)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_POL2           (*(volatile hw_hdmi_fc_pol2_t *) HW_HDMI_FC_POL2_ADDR)
#define HW_HDMI_FC_POL2_RD()      (HW_HDMI_FC_POL2.U)
#define HW_HDMI_FC_POL2_WR(v)     (HW_HDMI_FC_POL2.U = (v))
#define HW_HDMI_FC_POL2_SET(v)    (HW_HDMI_FC_POL2_WR(HW_HDMI_FC_POL2_RD() |  (v)))
#define HW_HDMI_FC_POL2_CLR(v)    (HW_HDMI_FC_POL2_WR(HW_HDMI_FC_POL2_RD() & ~(v)))
#define HW_HDMI_FC_POL2_TOG(v)    (HW_HDMI_FC_POL2_WR(HW_HDMI_FC_POL2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_POL2 bitfields
 */

/* --- Register HW_HDMI_FC_POL2, field HIGHPRIORITY_OVERFLOW (RW)
 *
 * Polarity bit for FC_INT1.HighPriority_overflow interrupt bit Value after Reset: 1b
 */

#define BP_HDMI_FC_POL2_HIGHPRIORITY_OVERFLOW      0
#define BM_HDMI_FC_POL2_HIGHPRIORITY_OVERFLOW      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL2_HIGHPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_POL2_HIGHPRIORITY_OVERFLOW)
#else
#define BF_HDMI_FC_POL2_HIGHPRIORITY_OVERFLOW(v)   (((v) << 0) & BM_HDMI_FC_POL2_HIGHPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HIGHPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_FC_POL2_HIGHPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_FC_POL2, HIGHPRIORITY_OVERFLOW, v)
#endif

/* --- Register HW_HDMI_FC_POL2, field LOWPRIORITY_OVERFLOW (RW)
 *
 * Polarity bit for FC_INT1.LowPriority_overflow interrupt bit Value after Reset: 1b
 */

#define BP_HDMI_FC_POL2_LOWPRIORITY_OVERFLOW      1
#define BM_HDMI_FC_POL2_LOWPRIORITY_OVERFLOW      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_POL2_LOWPRIORITY_OVERFLOW(v)   ((((reg32_t) v) << 1) & BM_HDMI_FC_POL2_LOWPRIORITY_OVERFLOW)
#else
#define BF_HDMI_FC_POL2_LOWPRIORITY_OVERFLOW(v)   (((v) << 1) & BM_HDMI_FC_POL2_LOWPRIORITY_OVERFLOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOWPRIORITY_OVERFLOW field to a new value.
#define BW_HDMI_FC_POL2_LOWPRIORITY_OVERFLOW(v)   BF_CS1(HDMI_FC_POL2, LOWPRIORITY_OVERFLOW, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_PRCONF - Frame Composer Pixel Repetition Configuration Register (RW)
 *
 * Defines the Pixel Repetition ratio factor of the input and output video signal.   Address Offset:
 * 0x10E0  Size: 8 bits  Value after Reset: 0x10  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char OUTPUT_PR_FACTOR : 4; //!< Configures the video pixel repetition ratio to be sent on the AVI infoFrame. This value must be valid according to HDMI spec. The output_pr_factor = incoming_pr_factor(without the + 1 factor) * desired_pr_factor. other: Reserved. Not used.
        unsigned char INCOMING_PR_FACTOR : 4; //!< Configures the input video pixel repetition. A plus 1 factor should be added in this register configuration. For CEA modes this value should be extracted from the CEA spec for the video mode being inputted. When working in YCC422 video the actual repetition of the stream will be Incoming_pr_factor * (desired_pr_factor + 1). This calculation is done internally in the H13TCTRL and no HW overflow protection is available. Care must be taken to avoid this result passes the maximum number of 10 pixels repeated since no HDMI support is available for this in the spec and the H13TPHY does not support this higher repetition values. other: Reserved. Not used.
    } B;
} hw_hdmi_fc_prconf_t;
#endif

/*
 * constants & macros for entire HDMI_FC_PRCONF register
 */
#define HW_HDMI_FC_PRCONF_ADDR      (REGS_HDMI_BASE + 0x10e0)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_PRCONF           (*(volatile hw_hdmi_fc_prconf_t *) HW_HDMI_FC_PRCONF_ADDR)
#define HW_HDMI_FC_PRCONF_RD()      (HW_HDMI_FC_PRCONF.U)
#define HW_HDMI_FC_PRCONF_WR(v)     (HW_HDMI_FC_PRCONF.U = (v))
#define HW_HDMI_FC_PRCONF_SET(v)    (HW_HDMI_FC_PRCONF_WR(HW_HDMI_FC_PRCONF_RD() |  (v)))
#define HW_HDMI_FC_PRCONF_CLR(v)    (HW_HDMI_FC_PRCONF_WR(HW_HDMI_FC_PRCONF_RD() & ~(v)))
#define HW_HDMI_FC_PRCONF_TOG(v)    (HW_HDMI_FC_PRCONF_WR(HW_HDMI_FC_PRCONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_PRCONF bitfields
 */

/* --- Register HW_HDMI_FC_PRCONF, field OUTPUT_PR_FACTOR (RW)
 *
 * Configures the video pixel repetition ratio to be sent on the AVI infoFrame. This value must be
 * valid according to HDMI spec. The output_pr_factor = incoming_pr_factor(without the + 1 factor) *
 * desired_pr_factor. other: Reserved. Not used.
 *
 * Values:
 * 0000 - No action. Shall not be used.
 * 0001 - Pixel sent twice (pixel repeated once).
 * 0010 - Pixel sent 3 times.
 * 0011 - Pixel sent 4 times.
 * 0100 - Pixel sent 5 times.
 * 0101 - Pixel sent 6 times.
 * 0110 - Pixel sent 7 times.
 * 0111 - Pixel sent 8 times.
 * 1000 - Pixel sent 9 times.
 * 1001 - Pixel sent 10 times.
 */

#define BP_HDMI_FC_PRCONF_OUTPUT_PR_FACTOR      0
#define BM_HDMI_FC_PRCONF_OUTPUT_PR_FACTOR      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_PRCONF_OUTPUT_PR_FACTOR(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_PRCONF_OUTPUT_PR_FACTOR)
#else
#define BF_HDMI_FC_PRCONF_OUTPUT_PR_FACTOR(v)   (((v) << 0) & BM_HDMI_FC_PRCONF_OUTPUT_PR_FACTOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTPUT_PR_FACTOR field to a new value.
#define BW_HDMI_FC_PRCONF_OUTPUT_PR_FACTOR(v)   BF_CS1(HDMI_FC_PRCONF, OUTPUT_PR_FACTOR, v)
#endif


/* --- Register HW_HDMI_FC_PRCONF, field INCOMING_PR_FACTOR (RW)
 *
 * Configures the input video pixel repetition. A plus 1 factor should be added in this register
 * configuration. For CEA modes this value should be extracted from the CEA spec for the video mode
 * being inputted. When working in YCC422 video the actual repetition of the stream will be
 * Incoming_pr_factor * (desired_pr_factor + 1). This calculation is done internally in the H13TCTRL
 * and no HW overflow protection is available. Care must be taken to avoid this result passes the
 * maximum number of 10 pixels repeated since no HDMI support is available for this in the spec and
 * the H13TPHY does not support this higher repetition values. other: Reserved. Not used.
 *
 * Values:
 * 0000 - No action. Shall not be used.
 * 0001 - No pixel repetition (pixel sent only once).
 * 0010 - Pixel sent twice (pixel repeated once).
 * 0011 - Pixel sent 3 times.
 * 0100 - Pixel sent 4 times.
 * 0101 - Pixel sent 5 times.
 * 0110 - Pixel sent 6 times.
 * 0111 - Pixel sent 7 times.
 * 1000 - Pixel sent 8 times.
 * 1001 - Pixel sent 9 times.
 * 1010 - Pixel sent 10 times.
 */

#define BP_HDMI_FC_PRCONF_INCOMING_PR_FACTOR      4
#define BM_HDMI_FC_PRCONF_INCOMING_PR_FACTOR      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_PRCONF_INCOMING_PR_FACTOR(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_PRCONF_INCOMING_PR_FACTOR)
#else
#define BF_HDMI_FC_PRCONF_INCOMING_PR_FACTOR(v)   (((v) << 4) & BM_HDMI_FC_PRCONF_INCOMING_PR_FACTOR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INCOMING_PR_FACTOR field to a new value.
#define BW_HDMI_FC_PRCONF_INCOMING_PR_FACTOR(v)   BF_CS1(HDMI_FC_PRCONF, INCOMING_PR_FACTOR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_STAT - Frame Composer GMD Packet Status Register (RO)
 *
 * Gamut metadata packet status bit information for no_current_gmd, next_gmd_field,
 * gmd_packet_sequence and current_gamut_seq_num. For more information, refer to the HDMI 1.4a
 * specification.   Address Offset: 0x1100  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char IGMDCURRENT_GAMUT_SEQ_NUM : 4; //!< Gamut scheduling: Current Gamut packet sequence number
        unsigned char IGMDPACKET_SEQ : 2; //!< Gamut scheduling: Gamut packet sequence
        unsigned char IGMDDNEXT_FIELD : 1; //!< Gamut scheduling: Gamut Next field
        unsigned char IGMDNO_CRNT_GBD : 1; //!< Gamut scheduling: No current gamut data
    } B;
} hw_hdmi_fc_gmd_stat_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_STAT register
 */
#define HW_HDMI_FC_GMD_STAT_ADDR      (REGS_HDMI_BASE + 0x1100)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_STAT           (*(volatile hw_hdmi_fc_gmd_stat_t *) HW_HDMI_FC_GMD_STAT_ADDR)
#define HW_HDMI_FC_GMD_STAT_RD()      (HW_HDMI_FC_GMD_STAT.U)
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_STAT bitfields
 */

/* --- Register HW_HDMI_FC_GMD_STAT, field IGMDCURRENT_GAMUT_SEQ_NUM (RO)
 *
 * Gamut scheduling: Current Gamut packet sequence number
 */

#define BP_HDMI_FC_GMD_STAT_IGMDCURRENT_GAMUT_SEQ_NUM      0
#define BM_HDMI_FC_GMD_STAT_IGMDCURRENT_GAMUT_SEQ_NUM      0x0000000f

/* --- Register HW_HDMI_FC_GMD_STAT, field IGMDPACKET_SEQ (RO)
 *
 * Gamut scheduling: Gamut packet sequence
 */

#define BP_HDMI_FC_GMD_STAT_IGMDPACKET_SEQ      4
#define BM_HDMI_FC_GMD_STAT_IGMDPACKET_SEQ      0x00000030

/* --- Register HW_HDMI_FC_GMD_STAT, field IGMDDNEXT_FIELD (RO)
 *
 * Gamut scheduling: Gamut Next field
 */

#define BP_HDMI_FC_GMD_STAT_IGMDDNEXT_FIELD      6
#define BM_HDMI_FC_GMD_STAT_IGMDDNEXT_FIELD      0x00000040

/* --- Register HW_HDMI_FC_GMD_STAT, field IGMDNO_CRNT_GBD (RO)
 *
 * Gamut scheduling: No current gamut data
 */

#define BP_HDMI_FC_GMD_STAT_IGMDNO_CRNT_GBD      7
#define BM_HDMI_FC_GMD_STAT_IGMDNO_CRNT_GBD      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_EN - Frame Composer GMD Packet Enable Register (RW)
 *
 * This register enables Gamut metadata (GMD) packet transmission. Packets are inserted in the
 * incoming frame, starting in the line where active Vsync indication starts. After enable of GMD
 * packets the outgoing packet is sent with no_current_gmd active indication until update GMD
 * request is performed in the controller.   Address Offset: 0x1101  Size: 8 bits  Value after
 * Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GMDENABLETX : 1; //!< Gamut Metadata packet transmission enable (1b).
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_fc_gmd_en_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_EN register
 */
#define HW_HDMI_FC_GMD_EN_ADDR      (REGS_HDMI_BASE + 0x1101)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_EN           (*(volatile hw_hdmi_fc_gmd_en_t *) HW_HDMI_FC_GMD_EN_ADDR)
#define HW_HDMI_FC_GMD_EN_RD()      (HW_HDMI_FC_GMD_EN.U)
#define HW_HDMI_FC_GMD_EN_WR(v)     (HW_HDMI_FC_GMD_EN.U = (v))
#define HW_HDMI_FC_GMD_EN_SET(v)    (HW_HDMI_FC_GMD_EN_WR(HW_HDMI_FC_GMD_EN_RD() |  (v)))
#define HW_HDMI_FC_GMD_EN_CLR(v)    (HW_HDMI_FC_GMD_EN_WR(HW_HDMI_FC_GMD_EN_RD() & ~(v)))
#define HW_HDMI_FC_GMD_EN_TOG(v)    (HW_HDMI_FC_GMD_EN_WR(HW_HDMI_FC_GMD_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_EN bitfields
 */

/* --- Register HW_HDMI_FC_GMD_EN, field GMDENABLETX (RW)
 *
 * Gamut Metadata packet transmission enable (1b).
 */

#define BP_HDMI_FC_GMD_EN_GMDENABLETX      0
#define BM_HDMI_FC_GMD_EN_GMDENABLETX      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_EN_GMDENABLETX(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_EN_GMDENABLETX)
#else
#define BF_HDMI_FC_GMD_EN_GMDENABLETX(v)   (((v) << 0) & BM_HDMI_FC_GMD_EN_GMDENABLETX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMDENABLETX field to a new value.
#define BW_HDMI_FC_GMD_EN_GMDENABLETX(v)   BF_CS1(HDMI_FC_GMD_EN, GMDENABLETX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_UP - Frame Composer GMD Packet Update Register (WO)
 *
 * This register performs an GMD packet content update according to the configured packet body
 * (FC_GMD_PB0 to FC_GMD_PB27) and packet header (FC_GMD_HB). This active high auto clear register
 * reflects the body and header configurations on the GMD packets sent arbitrating the
 * current_gamut_seq_num, gmd_packet_sequence and next_gmd_field bits on packet to correctly
 * indicate to source the Gamut change to be performed. After enable GMD packets the first update
 * request is also responsible for deactivating the no_current_gmd indication bit. Attention packet
 * update request must only be done after correct configuration of GMD packet body and header
 * registers. Correct affected_gamut_seq_num and gmd_profile configuration is user responsibility
 * and must convey with HDMI 1.4a standard gamut rules.   Address Offset: 0x1102  Size: 8 bits
 * Value after Reset: 0x00  Access: Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GMDUPDATEPACKET : 1; //!< Gamut Metadata packet update.
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_fc_gmd_up_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_UP register
 */
#define HW_HDMI_FC_GMD_UP_ADDR      (REGS_HDMI_BASE + 0x1102)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_UP           (*(volatile hw_hdmi_fc_gmd_up_t *) HW_HDMI_FC_GMD_UP_ADDR)
#define HW_HDMI_FC_GMD_UP_WR(v)     (HW_HDMI_FC_GMD_UP.U = (v))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_UP bitfields
 */

/* --- Register HW_HDMI_FC_GMD_UP, field GMDUPDATEPACKET (WO)
 *
 * Gamut Metadata packet update.
 */

#define BP_HDMI_FC_GMD_UP_GMDUPDATEPACKET      0
#define BM_HDMI_FC_GMD_UP_GMDUPDATEPACKET      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_UP_GMDUPDATEPACKET(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_UP_GMDUPDATEPACKET)
#else
#define BF_HDMI_FC_GMD_UP_GMDUPDATEPACKET(v)   (((v) << 0) & BM_HDMI_FC_GMD_UP_GMDUPDATEPACKET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMDUPDATEPACKET field to a new value.
#define BW_HDMI_FC_GMD_UP_GMDUPDATEPACKET(v)   BF_CS1(HDMI_FC_GMD_UP, GMDUPDATEPACKET, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_CONF - Frame Composer GMD Packet Schedule Configuration Register (RW)
 *
 * This register configures the number of GMD packets to be inserted per frame (starting always in
 * the line where the active Vsync appears) and the line spacing between the transmitted GMD
 * packets. Note that for profile P0 (refer to HDMI 1.4a spec) this register should only indicate
 * one GMD packet to be inserted per video field.   Address Offset: 0x1103  Size: 8 bits  Value
 * after Reset: 0x10  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GMDPACKETLINESPACING : 4; //!< Number of line spacing between the transmitted GMD packets
        unsigned char GMDPACKETSINFRAME : 4; //!< Number of GMD packets per frame or video field (profile P0)
    } B;
} hw_hdmi_fc_gmd_conf_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_CONF register
 */
#define HW_HDMI_FC_GMD_CONF_ADDR      (REGS_HDMI_BASE + 0x1103)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_CONF           (*(volatile hw_hdmi_fc_gmd_conf_t *) HW_HDMI_FC_GMD_CONF_ADDR)
#define HW_HDMI_FC_GMD_CONF_RD()      (HW_HDMI_FC_GMD_CONF.U)
#define HW_HDMI_FC_GMD_CONF_WR(v)     (HW_HDMI_FC_GMD_CONF.U = (v))
#define HW_HDMI_FC_GMD_CONF_SET(v)    (HW_HDMI_FC_GMD_CONF_WR(HW_HDMI_FC_GMD_CONF_RD() |  (v)))
#define HW_HDMI_FC_GMD_CONF_CLR(v)    (HW_HDMI_FC_GMD_CONF_WR(HW_HDMI_FC_GMD_CONF_RD() & ~(v)))
#define HW_HDMI_FC_GMD_CONF_TOG(v)    (HW_HDMI_FC_GMD_CONF_WR(HW_HDMI_FC_GMD_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_CONF bitfields
 */

/* --- Register HW_HDMI_FC_GMD_CONF, field GMDPACKETLINESPACING (RW)
 *
 * Number of line spacing between the transmitted GMD packets
 */

#define BP_HDMI_FC_GMD_CONF_GMDPACKETLINESPACING      0
#define BM_HDMI_FC_GMD_CONF_GMDPACKETLINESPACING      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_CONF_GMDPACKETLINESPACING(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_CONF_GMDPACKETLINESPACING)
#else
#define BF_HDMI_FC_GMD_CONF_GMDPACKETLINESPACING(v)   (((v) << 0) & BM_HDMI_FC_GMD_CONF_GMDPACKETLINESPACING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMDPACKETLINESPACING field to a new value.
#define BW_HDMI_FC_GMD_CONF_GMDPACKETLINESPACING(v)   BF_CS1(HDMI_FC_GMD_CONF, GMDPACKETLINESPACING, v)
#endif

/* --- Register HW_HDMI_FC_GMD_CONF, field GMDPACKETSINFRAME (RW)
 *
 * Number of GMD packets per frame or video field (profile P0)
 */

#define BP_HDMI_FC_GMD_CONF_GMDPACKETSINFRAME      4
#define BM_HDMI_FC_GMD_CONF_GMDPACKETSINFRAME      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_CONF_GMDPACKETSINFRAME(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_GMD_CONF_GMDPACKETSINFRAME)
#else
#define BF_HDMI_FC_GMD_CONF_GMDPACKETSINFRAME(v)   (((v) << 4) & BM_HDMI_FC_GMD_CONF_GMDPACKETSINFRAME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMDPACKETSINFRAME field to a new value.
#define BW_HDMI_FC_GMD_CONF_GMDPACKETSINFRAME(v)   BF_CS1(HDMI_FC_GMD_CONF, GMDPACKETSINFRAME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_HB - Frame Composer GMD Packet Profile and Gamut Sequence Configuration Register (RW)
 *
 * This register configures the GMD packet header affected_gamut_seq_num and gmd_profile bits. For
 * more information, refer to the HDMI 1.4a specification.   Address Offset: 0x1104  Size: 8 bits
 * Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char GMDAFFECTED_GAMUT_SEQ_NUM : 4; //!< Affected gamut sequence number
        unsigned char GMDGBD_PROFILE : 3; //!< GMD profile bits
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_fc_gmd_hb_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_HB register
 */
#define HW_HDMI_FC_GMD_HB_ADDR      (REGS_HDMI_BASE + 0x1104)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_HB           (*(volatile hw_hdmi_fc_gmd_hb_t *) HW_HDMI_FC_GMD_HB_ADDR)
#define HW_HDMI_FC_GMD_HB_RD()      (HW_HDMI_FC_GMD_HB.U)
#define HW_HDMI_FC_GMD_HB_WR(v)     (HW_HDMI_FC_GMD_HB.U = (v))
#define HW_HDMI_FC_GMD_HB_SET(v)    (HW_HDMI_FC_GMD_HB_WR(HW_HDMI_FC_GMD_HB_RD() |  (v)))
#define HW_HDMI_FC_GMD_HB_CLR(v)    (HW_HDMI_FC_GMD_HB_WR(HW_HDMI_FC_GMD_HB_RD() & ~(v)))
#define HW_HDMI_FC_GMD_HB_TOG(v)    (HW_HDMI_FC_GMD_HB_WR(HW_HDMI_FC_GMD_HB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_HB bitfields
 */

/* --- Register HW_HDMI_FC_GMD_HB, field GMDAFFECTED_GAMUT_SEQ_NUM (RW)
 *
 * Affected gamut sequence number
 */

#define BP_HDMI_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM      0
#define BM_HDMI_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM)
#else
#define BF_HDMI_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM(v)   (((v) << 0) & BM_HDMI_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMDAFFECTED_GAMUT_SEQ_NUM field to a new value.
#define BW_HDMI_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM(v)   BF_CS1(HDMI_FC_GMD_HB, GMDAFFECTED_GAMUT_SEQ_NUM, v)
#endif

/* --- Register HW_HDMI_FC_GMD_HB, field GMDGBD_PROFILE (RW)
 *
 * GMD profile bits
 */

#define BP_HDMI_FC_GMD_HB_GMDGBD_PROFILE      4
#define BM_HDMI_FC_GMD_HB_GMDGBD_PROFILE      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_HB_GMDGBD_PROFILE(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_GMD_HB_GMDGBD_PROFILE)
#else
#define BF_HDMI_FC_GMD_HB_GMDGBD_PROFILE(v)   (((v) << 4) & BM_HDMI_FC_GMD_HB_GMDGBD_PROFILE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GMDGBD_PROFILE field to a new value.
#define BW_HDMI_FC_GMD_HB_GMDGBD_PROFILE(v)   BF_CS1(HDMI_FC_GMD_HB, GMDGBD_PROFILE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB0 - Frame Composer GMD Packet Body Register 0 (RW)
 *
 * Configures the following contents of the GMD packet:   GMD packet body byte0  Address Offset:
 * 0x1105  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write   For more information, refer
 * to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB0 : 8; //!< Gamut Metadata packet byte0
    } B;
} hw_hdmi_fc_gmd_pb0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB0 register
 */
#define HW_HDMI_FC_GMD_PB0_ADDR      (REGS_HDMI_BASE + 0x1105)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB0           (*(volatile hw_hdmi_fc_gmd_pb0_t *) HW_HDMI_FC_GMD_PB0_ADDR)
#define HW_HDMI_FC_GMD_PB0_RD()      (HW_HDMI_FC_GMD_PB0.U)
#define HW_HDMI_FC_GMD_PB0_WR(v)     (HW_HDMI_FC_GMD_PB0.U = (v))
#define HW_HDMI_FC_GMD_PB0_SET(v)    (HW_HDMI_FC_GMD_PB0_WR(HW_HDMI_FC_GMD_PB0_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB0_CLR(v)    (HW_HDMI_FC_GMD_PB0_WR(HW_HDMI_FC_GMD_PB0_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB0_TOG(v)    (HW_HDMI_FC_GMD_PB0_WR(HW_HDMI_FC_GMD_PB0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB0 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB0, field FC_GMD_PB0 (RW)
 *
 * Gamut Metadata packet byte0
 */

#define BP_HDMI_FC_GMD_PB0_FC_GMD_PB0      0
#define BM_HDMI_FC_GMD_PB0_FC_GMD_PB0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB0_FC_GMD_PB0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB0_FC_GMD_PB0)
#else
#define BF_HDMI_FC_GMD_PB0_FC_GMD_PB0(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB0_FC_GMD_PB0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB0 field to a new value.
#define BW_HDMI_FC_GMD_PB0_FC_GMD_PB0(v)   BF_CS1(HDMI_FC_GMD_PB0, FC_GMD_PB0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB1 - Frame Composer GMD Packet Body Register 1 (RW)
 *
 * GMD packet body byte1  Address Offset: 0x1106  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB1 : 8; //!< Gamut Metadata packet byte1
    } B;
} hw_hdmi_fc_gmd_pb1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB1 register
 */
#define HW_HDMI_FC_GMD_PB1_ADDR      (REGS_HDMI_BASE + 0x1106)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB1           (*(volatile hw_hdmi_fc_gmd_pb1_t *) HW_HDMI_FC_GMD_PB1_ADDR)
#define HW_HDMI_FC_GMD_PB1_RD()      (HW_HDMI_FC_GMD_PB1.U)
#define HW_HDMI_FC_GMD_PB1_WR(v)     (HW_HDMI_FC_GMD_PB1.U = (v))
#define HW_HDMI_FC_GMD_PB1_SET(v)    (HW_HDMI_FC_GMD_PB1_WR(HW_HDMI_FC_GMD_PB1_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB1_CLR(v)    (HW_HDMI_FC_GMD_PB1_WR(HW_HDMI_FC_GMD_PB1_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB1_TOG(v)    (HW_HDMI_FC_GMD_PB1_WR(HW_HDMI_FC_GMD_PB1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB1 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB1, field FC_GMD_PB1 (RW)
 *
 * Gamut Metadata packet byte1
 */

#define BP_HDMI_FC_GMD_PB1_FC_GMD_PB1      0
#define BM_HDMI_FC_GMD_PB1_FC_GMD_PB1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB1_FC_GMD_PB1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB1_FC_GMD_PB1)
#else
#define BF_HDMI_FC_GMD_PB1_FC_GMD_PB1(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB1_FC_GMD_PB1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB1 field to a new value.
#define BW_HDMI_FC_GMD_PB1_FC_GMD_PB1(v)   BF_CS1(HDMI_FC_GMD_PB1, FC_GMD_PB1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB2 - Frame Composer GMD Packet Body Register 2 (RW)
 *
 * GMD packet body byte2  Address Offset: 0x1107  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB2 : 8; //!< Gamut Metadata packet byte2
    } B;
} hw_hdmi_fc_gmd_pb2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB2 register
 */
#define HW_HDMI_FC_GMD_PB2_ADDR      (REGS_HDMI_BASE + 0x1107)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB2           (*(volatile hw_hdmi_fc_gmd_pb2_t *) HW_HDMI_FC_GMD_PB2_ADDR)
#define HW_HDMI_FC_GMD_PB2_RD()      (HW_HDMI_FC_GMD_PB2.U)
#define HW_HDMI_FC_GMD_PB2_WR(v)     (HW_HDMI_FC_GMD_PB2.U = (v))
#define HW_HDMI_FC_GMD_PB2_SET(v)    (HW_HDMI_FC_GMD_PB2_WR(HW_HDMI_FC_GMD_PB2_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB2_CLR(v)    (HW_HDMI_FC_GMD_PB2_WR(HW_HDMI_FC_GMD_PB2_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB2_TOG(v)    (HW_HDMI_FC_GMD_PB2_WR(HW_HDMI_FC_GMD_PB2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB2 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB2, field FC_GMD_PB2 (RW)
 *
 * Gamut Metadata packet byte2
 */

#define BP_HDMI_FC_GMD_PB2_FC_GMD_PB2      0
#define BM_HDMI_FC_GMD_PB2_FC_GMD_PB2      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB2_FC_GMD_PB2(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB2_FC_GMD_PB2)
#else
#define BF_HDMI_FC_GMD_PB2_FC_GMD_PB2(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB2_FC_GMD_PB2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB2 field to a new value.
#define BW_HDMI_FC_GMD_PB2_FC_GMD_PB2(v)   BF_CS1(HDMI_FC_GMD_PB2, FC_GMD_PB2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB3 - Frame Composer GMD Packet Body Register 3 (RW)
 *
 * GMD packet body byte3  Address Offset: 0x1108  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB3 : 8; //!< Gamut Metadata packet byte3
    } B;
} hw_hdmi_fc_gmd_pb3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB3 register
 */
#define HW_HDMI_FC_GMD_PB3_ADDR      (REGS_HDMI_BASE + 0x1108)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB3           (*(volatile hw_hdmi_fc_gmd_pb3_t *) HW_HDMI_FC_GMD_PB3_ADDR)
#define HW_HDMI_FC_GMD_PB3_RD()      (HW_HDMI_FC_GMD_PB3.U)
#define HW_HDMI_FC_GMD_PB3_WR(v)     (HW_HDMI_FC_GMD_PB3.U = (v))
#define HW_HDMI_FC_GMD_PB3_SET(v)    (HW_HDMI_FC_GMD_PB3_WR(HW_HDMI_FC_GMD_PB3_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB3_CLR(v)    (HW_HDMI_FC_GMD_PB3_WR(HW_HDMI_FC_GMD_PB3_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB3_TOG(v)    (HW_HDMI_FC_GMD_PB3_WR(HW_HDMI_FC_GMD_PB3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB3 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB3, field FC_GMD_PB3 (RW)
 *
 * Gamut Metadata packet byte3
 */

#define BP_HDMI_FC_GMD_PB3_FC_GMD_PB3      0
#define BM_HDMI_FC_GMD_PB3_FC_GMD_PB3      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB3_FC_GMD_PB3(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB3_FC_GMD_PB3)
#else
#define BF_HDMI_FC_GMD_PB3_FC_GMD_PB3(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB3_FC_GMD_PB3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB3 field to a new value.
#define BW_HDMI_FC_GMD_PB3_FC_GMD_PB3(v)   BF_CS1(HDMI_FC_GMD_PB3, FC_GMD_PB3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB4 - Frame Composer GMD Packet Body Register 4 (RW)
 *
 * GMD packet body byte4  Address Offset: 0x1109  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB4 : 8; //!< Gamut Metadata packet byte4
    } B;
} hw_hdmi_fc_gmd_pb4_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB4 register
 */
#define HW_HDMI_FC_GMD_PB4_ADDR      (REGS_HDMI_BASE + 0x1109)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB4           (*(volatile hw_hdmi_fc_gmd_pb4_t *) HW_HDMI_FC_GMD_PB4_ADDR)
#define HW_HDMI_FC_GMD_PB4_RD()      (HW_HDMI_FC_GMD_PB4.U)
#define HW_HDMI_FC_GMD_PB4_WR(v)     (HW_HDMI_FC_GMD_PB4.U = (v))
#define HW_HDMI_FC_GMD_PB4_SET(v)    (HW_HDMI_FC_GMD_PB4_WR(HW_HDMI_FC_GMD_PB4_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB4_CLR(v)    (HW_HDMI_FC_GMD_PB4_WR(HW_HDMI_FC_GMD_PB4_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB4_TOG(v)    (HW_HDMI_FC_GMD_PB4_WR(HW_HDMI_FC_GMD_PB4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB4 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB4, field FC_GMD_PB4 (RW)
 *
 * Gamut Metadata packet byte4
 */

#define BP_HDMI_FC_GMD_PB4_FC_GMD_PB4      0
#define BM_HDMI_FC_GMD_PB4_FC_GMD_PB4      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB4_FC_GMD_PB4(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB4_FC_GMD_PB4)
#else
#define BF_HDMI_FC_GMD_PB4_FC_GMD_PB4(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB4_FC_GMD_PB4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB4 field to a new value.
#define BW_HDMI_FC_GMD_PB4_FC_GMD_PB4(v)   BF_CS1(HDMI_FC_GMD_PB4, FC_GMD_PB4, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB5 - Frame Composer GMD Packet Body Register 5 (RW)
 *
 * GMD packet body byte5  Address Offset: 0x110a  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB5 : 8; //!< Gamut Metadata packet byte5
    } B;
} hw_hdmi_fc_gmd_pb5_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB5 register
 */
#define HW_HDMI_FC_GMD_PB5_ADDR      (REGS_HDMI_BASE + 0x110a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB5           (*(volatile hw_hdmi_fc_gmd_pb5_t *) HW_HDMI_FC_GMD_PB5_ADDR)
#define HW_HDMI_FC_GMD_PB5_RD()      (HW_HDMI_FC_GMD_PB5.U)
#define HW_HDMI_FC_GMD_PB5_WR(v)     (HW_HDMI_FC_GMD_PB5.U = (v))
#define HW_HDMI_FC_GMD_PB5_SET(v)    (HW_HDMI_FC_GMD_PB5_WR(HW_HDMI_FC_GMD_PB5_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB5_CLR(v)    (HW_HDMI_FC_GMD_PB5_WR(HW_HDMI_FC_GMD_PB5_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB5_TOG(v)    (HW_HDMI_FC_GMD_PB5_WR(HW_HDMI_FC_GMD_PB5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB5 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB5, field FC_GMD_PB5 (RW)
 *
 * Gamut Metadata packet byte5
 */

#define BP_HDMI_FC_GMD_PB5_FC_GMD_PB5      0
#define BM_HDMI_FC_GMD_PB5_FC_GMD_PB5      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB5_FC_GMD_PB5(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB5_FC_GMD_PB5)
#else
#define BF_HDMI_FC_GMD_PB5_FC_GMD_PB5(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB5_FC_GMD_PB5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB5 field to a new value.
#define BW_HDMI_FC_GMD_PB5_FC_GMD_PB5(v)   BF_CS1(HDMI_FC_GMD_PB5, FC_GMD_PB5, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB6 - Frame Composer GMD Packet Body Register 6 (RW)
 *
 * GMD packet body byte6  Address Offset: 0x110b  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB6 : 8; //!< Gamut Metadata packet byte6
    } B;
} hw_hdmi_fc_gmd_pb6_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB6 register
 */
#define HW_HDMI_FC_GMD_PB6_ADDR      (REGS_HDMI_BASE + 0x110b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB6           (*(volatile hw_hdmi_fc_gmd_pb6_t *) HW_HDMI_FC_GMD_PB6_ADDR)
#define HW_HDMI_FC_GMD_PB6_RD()      (HW_HDMI_FC_GMD_PB6.U)
#define HW_HDMI_FC_GMD_PB6_WR(v)     (HW_HDMI_FC_GMD_PB6.U = (v))
#define HW_HDMI_FC_GMD_PB6_SET(v)    (HW_HDMI_FC_GMD_PB6_WR(HW_HDMI_FC_GMD_PB6_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB6_CLR(v)    (HW_HDMI_FC_GMD_PB6_WR(HW_HDMI_FC_GMD_PB6_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB6_TOG(v)    (HW_HDMI_FC_GMD_PB6_WR(HW_HDMI_FC_GMD_PB6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB6 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB6, field FC_GMD_PB6 (RW)
 *
 * Gamut Metadata packet byte6
 */

#define BP_HDMI_FC_GMD_PB6_FC_GMD_PB6      0
#define BM_HDMI_FC_GMD_PB6_FC_GMD_PB6      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB6_FC_GMD_PB6(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB6_FC_GMD_PB6)
#else
#define BF_HDMI_FC_GMD_PB6_FC_GMD_PB6(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB6_FC_GMD_PB6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB6 field to a new value.
#define BW_HDMI_FC_GMD_PB6_FC_GMD_PB6(v)   BF_CS1(HDMI_FC_GMD_PB6, FC_GMD_PB6, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB7 - Frame Composer GMD Packet Body Register 7 (RW)
 *
 * GMD packet body byte7  Address Offset: 0x110c  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB2 : 8; //!< Gamut Metadata packet byte7
    } B;
} hw_hdmi_fc_gmd_pb7_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB7 register
 */
#define HW_HDMI_FC_GMD_PB7_ADDR      (REGS_HDMI_BASE + 0x110c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB7           (*(volatile hw_hdmi_fc_gmd_pb7_t *) HW_HDMI_FC_GMD_PB7_ADDR)
#define HW_HDMI_FC_GMD_PB7_RD()      (HW_HDMI_FC_GMD_PB7.U)
#define HW_HDMI_FC_GMD_PB7_WR(v)     (HW_HDMI_FC_GMD_PB7.U = (v))
#define HW_HDMI_FC_GMD_PB7_SET(v)    (HW_HDMI_FC_GMD_PB7_WR(HW_HDMI_FC_GMD_PB7_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB7_CLR(v)    (HW_HDMI_FC_GMD_PB7_WR(HW_HDMI_FC_GMD_PB7_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB7_TOG(v)    (HW_HDMI_FC_GMD_PB7_WR(HW_HDMI_FC_GMD_PB7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB7 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB7, field FC_GMD_PB2 (RW)
 *
 * Gamut Metadata packet byte7
 */

#define BP_HDMI_FC_GMD_PB7_FC_GMD_PB2      0
#define BM_HDMI_FC_GMD_PB7_FC_GMD_PB2      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB7_FC_GMD_PB2(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB7_FC_GMD_PB2)
#else
#define BF_HDMI_FC_GMD_PB7_FC_GMD_PB2(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB7_FC_GMD_PB2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB2 field to a new value.
#define BW_HDMI_FC_GMD_PB7_FC_GMD_PB2(v)   BF_CS1(HDMI_FC_GMD_PB7, FC_GMD_PB2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB8 - Frame Composer GMD Packet Body Register 8 (RW)
 *
 * GMD packet body byte8  Address Offset: 0x110d  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB8 : 8; //!< Gamut Metadata packet byte8
    } B;
} hw_hdmi_fc_gmd_pb8_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB8 register
 */
#define HW_HDMI_FC_GMD_PB8_ADDR      (REGS_HDMI_BASE + 0x110d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB8           (*(volatile hw_hdmi_fc_gmd_pb8_t *) HW_HDMI_FC_GMD_PB8_ADDR)
#define HW_HDMI_FC_GMD_PB8_RD()      (HW_HDMI_FC_GMD_PB8.U)
#define HW_HDMI_FC_GMD_PB8_WR(v)     (HW_HDMI_FC_GMD_PB8.U = (v))
#define HW_HDMI_FC_GMD_PB8_SET(v)    (HW_HDMI_FC_GMD_PB8_WR(HW_HDMI_FC_GMD_PB8_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB8_CLR(v)    (HW_HDMI_FC_GMD_PB8_WR(HW_HDMI_FC_GMD_PB8_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB8_TOG(v)    (HW_HDMI_FC_GMD_PB8_WR(HW_HDMI_FC_GMD_PB8_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB8 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB8, field FC_GMD_PB8 (RW)
 *
 * Gamut Metadata packet byte8
 */

#define BP_HDMI_FC_GMD_PB8_FC_GMD_PB8      0
#define BM_HDMI_FC_GMD_PB8_FC_GMD_PB8      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB8_FC_GMD_PB8(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB8_FC_GMD_PB8)
#else
#define BF_HDMI_FC_GMD_PB8_FC_GMD_PB8(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB8_FC_GMD_PB8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB8 field to a new value.
#define BW_HDMI_FC_GMD_PB8_FC_GMD_PB8(v)   BF_CS1(HDMI_FC_GMD_PB8, FC_GMD_PB8, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB9 - Frame Composer GMD Packet Body Register 9 (RW)
 *
 * GMD packet body byte9  Address Offset: 0x110e  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB9 : 8; //!< Gamut Metadata packet byte9
    } B;
} hw_hdmi_fc_gmd_pb9_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB9 register
 */
#define HW_HDMI_FC_GMD_PB9_ADDR      (REGS_HDMI_BASE + 0x110e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB9           (*(volatile hw_hdmi_fc_gmd_pb9_t *) HW_HDMI_FC_GMD_PB9_ADDR)
#define HW_HDMI_FC_GMD_PB9_RD()      (HW_HDMI_FC_GMD_PB9.U)
#define HW_HDMI_FC_GMD_PB9_WR(v)     (HW_HDMI_FC_GMD_PB9.U = (v))
#define HW_HDMI_FC_GMD_PB9_SET(v)    (HW_HDMI_FC_GMD_PB9_WR(HW_HDMI_FC_GMD_PB9_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB9_CLR(v)    (HW_HDMI_FC_GMD_PB9_WR(HW_HDMI_FC_GMD_PB9_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB9_TOG(v)    (HW_HDMI_FC_GMD_PB9_WR(HW_HDMI_FC_GMD_PB9_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB9 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB9, field FC_GMD_PB9 (RW)
 *
 * Gamut Metadata packet byte9
 */

#define BP_HDMI_FC_GMD_PB9_FC_GMD_PB9      0
#define BM_HDMI_FC_GMD_PB9_FC_GMD_PB9      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB9_FC_GMD_PB9(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB9_FC_GMD_PB9)
#else
#define BF_HDMI_FC_GMD_PB9_FC_GMD_PB9(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB9_FC_GMD_PB9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB9 field to a new value.
#define BW_HDMI_FC_GMD_PB9_FC_GMD_PB9(v)   BF_CS1(HDMI_FC_GMD_PB9, FC_GMD_PB9, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB10 - Frame Composer GMD Packet Body Register 10 (RW)
 *
 * GMD packet body byte10  Address Offset: 0x110f  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB10 : 8; //!< Gamut Metadata packet byte10
    } B;
} hw_hdmi_fc_gmd_pb10_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB10 register
 */
#define HW_HDMI_FC_GMD_PB10_ADDR      (REGS_HDMI_BASE + 0x110f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB10           (*(volatile hw_hdmi_fc_gmd_pb10_t *) HW_HDMI_FC_GMD_PB10_ADDR)
#define HW_HDMI_FC_GMD_PB10_RD()      (HW_HDMI_FC_GMD_PB10.U)
#define HW_HDMI_FC_GMD_PB10_WR(v)     (HW_HDMI_FC_GMD_PB10.U = (v))
#define HW_HDMI_FC_GMD_PB10_SET(v)    (HW_HDMI_FC_GMD_PB10_WR(HW_HDMI_FC_GMD_PB10_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB10_CLR(v)    (HW_HDMI_FC_GMD_PB10_WR(HW_HDMI_FC_GMD_PB10_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB10_TOG(v)    (HW_HDMI_FC_GMD_PB10_WR(HW_HDMI_FC_GMD_PB10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB10 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB10, field FC_GMD_PB10 (RW)
 *
 * Gamut Metadata packet byte10
 */

#define BP_HDMI_FC_GMD_PB10_FC_GMD_PB10      0
#define BM_HDMI_FC_GMD_PB10_FC_GMD_PB10      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB10_FC_GMD_PB10(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB10_FC_GMD_PB10)
#else
#define BF_HDMI_FC_GMD_PB10_FC_GMD_PB10(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB10_FC_GMD_PB10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB10 field to a new value.
#define BW_HDMI_FC_GMD_PB10_FC_GMD_PB10(v)   BF_CS1(HDMI_FC_GMD_PB10, FC_GMD_PB10, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB11 - Frame Composer GMD Packet Body Register 11 (RW)
 *
 * GMD packet body byte11  Address Offset: 0x1110  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB11 : 8; //!< Gamut Metadata packet byte11
    } B;
} hw_hdmi_fc_gmd_pb11_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB11 register
 */
#define HW_HDMI_FC_GMD_PB11_ADDR      (REGS_HDMI_BASE + 0x1110)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB11           (*(volatile hw_hdmi_fc_gmd_pb11_t *) HW_HDMI_FC_GMD_PB11_ADDR)
#define HW_HDMI_FC_GMD_PB11_RD()      (HW_HDMI_FC_GMD_PB11.U)
#define HW_HDMI_FC_GMD_PB11_WR(v)     (HW_HDMI_FC_GMD_PB11.U = (v))
#define HW_HDMI_FC_GMD_PB11_SET(v)    (HW_HDMI_FC_GMD_PB11_WR(HW_HDMI_FC_GMD_PB11_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB11_CLR(v)    (HW_HDMI_FC_GMD_PB11_WR(HW_HDMI_FC_GMD_PB11_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB11_TOG(v)    (HW_HDMI_FC_GMD_PB11_WR(HW_HDMI_FC_GMD_PB11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB11 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB11, field FC_GMD_PB11 (RW)
 *
 * Gamut Metadata packet byte11
 */

#define BP_HDMI_FC_GMD_PB11_FC_GMD_PB11      0
#define BM_HDMI_FC_GMD_PB11_FC_GMD_PB11      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB11_FC_GMD_PB11(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB11_FC_GMD_PB11)
#else
#define BF_HDMI_FC_GMD_PB11_FC_GMD_PB11(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB11_FC_GMD_PB11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB11 field to a new value.
#define BW_HDMI_FC_GMD_PB11_FC_GMD_PB11(v)   BF_CS1(HDMI_FC_GMD_PB11, FC_GMD_PB11, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB12 - Frame Composer GMD Packet Body Register 12 (RW)
 *
 * GMD packet body byte12  Address Offset: 0x1111  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB12 : 8; //!< Gamut Metadata packet byte12
    } B;
} hw_hdmi_fc_gmd_pb12_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB12 register
 */
#define HW_HDMI_FC_GMD_PB12_ADDR      (REGS_HDMI_BASE + 0x1111)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB12           (*(volatile hw_hdmi_fc_gmd_pb12_t *) HW_HDMI_FC_GMD_PB12_ADDR)
#define HW_HDMI_FC_GMD_PB12_RD()      (HW_HDMI_FC_GMD_PB12.U)
#define HW_HDMI_FC_GMD_PB12_WR(v)     (HW_HDMI_FC_GMD_PB12.U = (v))
#define HW_HDMI_FC_GMD_PB12_SET(v)    (HW_HDMI_FC_GMD_PB12_WR(HW_HDMI_FC_GMD_PB12_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB12_CLR(v)    (HW_HDMI_FC_GMD_PB12_WR(HW_HDMI_FC_GMD_PB12_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB12_TOG(v)    (HW_HDMI_FC_GMD_PB12_WR(HW_HDMI_FC_GMD_PB12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB12 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB12, field FC_GMD_PB12 (RW)
 *
 * Gamut Metadata packet byte12
 */

#define BP_HDMI_FC_GMD_PB12_FC_GMD_PB12      0
#define BM_HDMI_FC_GMD_PB12_FC_GMD_PB12      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB12_FC_GMD_PB12(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB12_FC_GMD_PB12)
#else
#define BF_HDMI_FC_GMD_PB12_FC_GMD_PB12(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB12_FC_GMD_PB12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB12 field to a new value.
#define BW_HDMI_FC_GMD_PB12_FC_GMD_PB12(v)   BF_CS1(HDMI_FC_GMD_PB12, FC_GMD_PB12, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB13 - Frame Composer GMD Packet Body Register 13 (RW)
 *
 * GMD packet body byte13  Address Offset: 0x1112  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB13 : 8; //!< Gamut Metadata packet byte13
    } B;
} hw_hdmi_fc_gmd_pb13_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB13 register
 */
#define HW_HDMI_FC_GMD_PB13_ADDR      (REGS_HDMI_BASE + 0x1112)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB13           (*(volatile hw_hdmi_fc_gmd_pb13_t *) HW_HDMI_FC_GMD_PB13_ADDR)
#define HW_HDMI_FC_GMD_PB13_RD()      (HW_HDMI_FC_GMD_PB13.U)
#define HW_HDMI_FC_GMD_PB13_WR(v)     (HW_HDMI_FC_GMD_PB13.U = (v))
#define HW_HDMI_FC_GMD_PB13_SET(v)    (HW_HDMI_FC_GMD_PB13_WR(HW_HDMI_FC_GMD_PB13_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB13_CLR(v)    (HW_HDMI_FC_GMD_PB13_WR(HW_HDMI_FC_GMD_PB13_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB13_TOG(v)    (HW_HDMI_FC_GMD_PB13_WR(HW_HDMI_FC_GMD_PB13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB13 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB13, field FC_GMD_PB13 (RW)
 *
 * Gamut Metadata packet byte13
 */

#define BP_HDMI_FC_GMD_PB13_FC_GMD_PB13      0
#define BM_HDMI_FC_GMD_PB13_FC_GMD_PB13      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB13_FC_GMD_PB13(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB13_FC_GMD_PB13)
#else
#define BF_HDMI_FC_GMD_PB13_FC_GMD_PB13(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB13_FC_GMD_PB13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB13 field to a new value.
#define BW_HDMI_FC_GMD_PB13_FC_GMD_PB13(v)   BF_CS1(HDMI_FC_GMD_PB13, FC_GMD_PB13, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB14 - Frame Composer GMD Packet Body Register 14 (RW)
 *
 * GMD packet body byte14  Address Offset: 0x1113  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB14 : 8; //!< Gamut Metadata packet byte14
    } B;
} hw_hdmi_fc_gmd_pb14_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB14 register
 */
#define HW_HDMI_FC_GMD_PB14_ADDR      (REGS_HDMI_BASE + 0x1113)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB14           (*(volatile hw_hdmi_fc_gmd_pb14_t *) HW_HDMI_FC_GMD_PB14_ADDR)
#define HW_HDMI_FC_GMD_PB14_RD()      (HW_HDMI_FC_GMD_PB14.U)
#define HW_HDMI_FC_GMD_PB14_WR(v)     (HW_HDMI_FC_GMD_PB14.U = (v))
#define HW_HDMI_FC_GMD_PB14_SET(v)    (HW_HDMI_FC_GMD_PB14_WR(HW_HDMI_FC_GMD_PB14_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB14_CLR(v)    (HW_HDMI_FC_GMD_PB14_WR(HW_HDMI_FC_GMD_PB14_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB14_TOG(v)    (HW_HDMI_FC_GMD_PB14_WR(HW_HDMI_FC_GMD_PB14_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB14 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB14, field FC_GMD_PB14 (RW)
 *
 * Gamut Metadata packet byte14
 */

#define BP_HDMI_FC_GMD_PB14_FC_GMD_PB14      0
#define BM_HDMI_FC_GMD_PB14_FC_GMD_PB14      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB14_FC_GMD_PB14(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB14_FC_GMD_PB14)
#else
#define BF_HDMI_FC_GMD_PB14_FC_GMD_PB14(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB14_FC_GMD_PB14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB14 field to a new value.
#define BW_HDMI_FC_GMD_PB14_FC_GMD_PB14(v)   BF_CS1(HDMI_FC_GMD_PB14, FC_GMD_PB14, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB15 - Frame Composer GMD Packet Body Register 15 (RW)
 *
 * GMD packet body byte15  Address Offset: 0x1114  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB15 : 8; //!< Gamut Metadata packet byte15
    } B;
} hw_hdmi_fc_gmd_pb15_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB15 register
 */
#define HW_HDMI_FC_GMD_PB15_ADDR      (REGS_HDMI_BASE + 0x1114)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB15           (*(volatile hw_hdmi_fc_gmd_pb15_t *) HW_HDMI_FC_GMD_PB15_ADDR)
#define HW_HDMI_FC_GMD_PB15_RD()      (HW_HDMI_FC_GMD_PB15.U)
#define HW_HDMI_FC_GMD_PB15_WR(v)     (HW_HDMI_FC_GMD_PB15.U = (v))
#define HW_HDMI_FC_GMD_PB15_SET(v)    (HW_HDMI_FC_GMD_PB15_WR(HW_HDMI_FC_GMD_PB15_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB15_CLR(v)    (HW_HDMI_FC_GMD_PB15_WR(HW_HDMI_FC_GMD_PB15_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB15_TOG(v)    (HW_HDMI_FC_GMD_PB15_WR(HW_HDMI_FC_GMD_PB15_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB15 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB15, field FC_GMD_PB15 (RW)
 *
 * Gamut Metadata packet byte15
 */

#define BP_HDMI_FC_GMD_PB15_FC_GMD_PB15      0
#define BM_HDMI_FC_GMD_PB15_FC_GMD_PB15      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB15_FC_GMD_PB15(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB15_FC_GMD_PB15)
#else
#define BF_HDMI_FC_GMD_PB15_FC_GMD_PB15(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB15_FC_GMD_PB15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB15 field to a new value.
#define BW_HDMI_FC_GMD_PB15_FC_GMD_PB15(v)   BF_CS1(HDMI_FC_GMD_PB15, FC_GMD_PB15, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB16 - Frame Composer GMD Packet Body Register 16 (RW)
 *
 * GMD packet body byte16  Address Offset: 0x1115  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB16 : 8; //!< Gamut Metadata packet byte16
    } B;
} hw_hdmi_fc_gmd_pb16_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB16 register
 */
#define HW_HDMI_FC_GMD_PB16_ADDR      (REGS_HDMI_BASE + 0x1115)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB16           (*(volatile hw_hdmi_fc_gmd_pb16_t *) HW_HDMI_FC_GMD_PB16_ADDR)
#define HW_HDMI_FC_GMD_PB16_RD()      (HW_HDMI_FC_GMD_PB16.U)
#define HW_HDMI_FC_GMD_PB16_WR(v)     (HW_HDMI_FC_GMD_PB16.U = (v))
#define HW_HDMI_FC_GMD_PB16_SET(v)    (HW_HDMI_FC_GMD_PB16_WR(HW_HDMI_FC_GMD_PB16_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB16_CLR(v)    (HW_HDMI_FC_GMD_PB16_WR(HW_HDMI_FC_GMD_PB16_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB16_TOG(v)    (HW_HDMI_FC_GMD_PB16_WR(HW_HDMI_FC_GMD_PB16_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB16 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB16, field FC_GMD_PB16 (RW)
 *
 * Gamut Metadata packet byte16
 */

#define BP_HDMI_FC_GMD_PB16_FC_GMD_PB16      0
#define BM_HDMI_FC_GMD_PB16_FC_GMD_PB16      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB16_FC_GMD_PB16(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB16_FC_GMD_PB16)
#else
#define BF_HDMI_FC_GMD_PB16_FC_GMD_PB16(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB16_FC_GMD_PB16)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB16 field to a new value.
#define BW_HDMI_FC_GMD_PB16_FC_GMD_PB16(v)   BF_CS1(HDMI_FC_GMD_PB16, FC_GMD_PB16, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB17 - Frame Composer GMD Packet Body Register 17 (RW)
 *
 * GMD packet body byte17  Address Offset: 0x1116  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB17 : 8; //!< Gamut Metadata packet byte17
    } B;
} hw_hdmi_fc_gmd_pb17_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB17 register
 */
#define HW_HDMI_FC_GMD_PB17_ADDR      (REGS_HDMI_BASE + 0x1116)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB17           (*(volatile hw_hdmi_fc_gmd_pb17_t *) HW_HDMI_FC_GMD_PB17_ADDR)
#define HW_HDMI_FC_GMD_PB17_RD()      (HW_HDMI_FC_GMD_PB17.U)
#define HW_HDMI_FC_GMD_PB17_WR(v)     (HW_HDMI_FC_GMD_PB17.U = (v))
#define HW_HDMI_FC_GMD_PB17_SET(v)    (HW_HDMI_FC_GMD_PB17_WR(HW_HDMI_FC_GMD_PB17_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB17_CLR(v)    (HW_HDMI_FC_GMD_PB17_WR(HW_HDMI_FC_GMD_PB17_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB17_TOG(v)    (HW_HDMI_FC_GMD_PB17_WR(HW_HDMI_FC_GMD_PB17_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB17 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB17, field FC_GMD_PB17 (RW)
 *
 * Gamut Metadata packet byte17
 */

#define BP_HDMI_FC_GMD_PB17_FC_GMD_PB17      0
#define BM_HDMI_FC_GMD_PB17_FC_GMD_PB17      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB17_FC_GMD_PB17(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB17_FC_GMD_PB17)
#else
#define BF_HDMI_FC_GMD_PB17_FC_GMD_PB17(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB17_FC_GMD_PB17)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB17 field to a new value.
#define BW_HDMI_FC_GMD_PB17_FC_GMD_PB17(v)   BF_CS1(HDMI_FC_GMD_PB17, FC_GMD_PB17, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB18 - Frame Composer GMD Packet Body Register 18 (RW)
 *
 * GMD packet body byte18  Address Offset: 0x1117  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB18 : 8; //!< Gamut Metadata packet byte18
    } B;
} hw_hdmi_fc_gmd_pb18_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB18 register
 */
#define HW_HDMI_FC_GMD_PB18_ADDR      (REGS_HDMI_BASE + 0x1117)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB18           (*(volatile hw_hdmi_fc_gmd_pb18_t *) HW_HDMI_FC_GMD_PB18_ADDR)
#define HW_HDMI_FC_GMD_PB18_RD()      (HW_HDMI_FC_GMD_PB18.U)
#define HW_HDMI_FC_GMD_PB18_WR(v)     (HW_HDMI_FC_GMD_PB18.U = (v))
#define HW_HDMI_FC_GMD_PB18_SET(v)    (HW_HDMI_FC_GMD_PB18_WR(HW_HDMI_FC_GMD_PB18_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB18_CLR(v)    (HW_HDMI_FC_GMD_PB18_WR(HW_HDMI_FC_GMD_PB18_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB18_TOG(v)    (HW_HDMI_FC_GMD_PB18_WR(HW_HDMI_FC_GMD_PB18_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB18 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB18, field FC_GMD_PB18 (RW)
 *
 * Gamut Metadata packet byte18
 */

#define BP_HDMI_FC_GMD_PB18_FC_GMD_PB18      0
#define BM_HDMI_FC_GMD_PB18_FC_GMD_PB18      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB18_FC_GMD_PB18(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB18_FC_GMD_PB18)
#else
#define BF_HDMI_FC_GMD_PB18_FC_GMD_PB18(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB18_FC_GMD_PB18)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB18 field to a new value.
#define BW_HDMI_FC_GMD_PB18_FC_GMD_PB18(v)   BF_CS1(HDMI_FC_GMD_PB18, FC_GMD_PB18, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB19 - Frame Composer GMD Packet Body Register 19 (RW)
 *
 * GMD packet body byte19  Address Offset: 0x1118  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB18 : 8; //!< Gamut Metadata packet byte18
    } B;
} hw_hdmi_fc_gmd_pb19_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB19 register
 */
#define HW_HDMI_FC_GMD_PB19_ADDR      (REGS_HDMI_BASE + 0x1118)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB19           (*(volatile hw_hdmi_fc_gmd_pb19_t *) HW_HDMI_FC_GMD_PB19_ADDR)
#define HW_HDMI_FC_GMD_PB19_RD()      (HW_HDMI_FC_GMD_PB19.U)
#define HW_HDMI_FC_GMD_PB19_WR(v)     (HW_HDMI_FC_GMD_PB19.U = (v))
#define HW_HDMI_FC_GMD_PB19_SET(v)    (HW_HDMI_FC_GMD_PB19_WR(HW_HDMI_FC_GMD_PB19_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB19_CLR(v)    (HW_HDMI_FC_GMD_PB19_WR(HW_HDMI_FC_GMD_PB19_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB19_TOG(v)    (HW_HDMI_FC_GMD_PB19_WR(HW_HDMI_FC_GMD_PB19_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB19 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB19, field FC_GMD_PB18 (RW)
 *
 * Gamut Metadata packet byte18
 */

#define BP_HDMI_FC_GMD_PB19_FC_GMD_PB18      0
#define BM_HDMI_FC_GMD_PB19_FC_GMD_PB18      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB19_FC_GMD_PB18(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB19_FC_GMD_PB18)
#else
#define BF_HDMI_FC_GMD_PB19_FC_GMD_PB18(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB19_FC_GMD_PB18)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB18 field to a new value.
#define BW_HDMI_FC_GMD_PB19_FC_GMD_PB18(v)   BF_CS1(HDMI_FC_GMD_PB19, FC_GMD_PB18, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB20 - Frame Composer GMD Packet Body Register 20 (RW)
 *
 * GMD packet body byte20  Address Offset: 0x1119  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB20 : 8; //!< Gamut Metadata packet byte20
    } B;
} hw_hdmi_fc_gmd_pb20_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB20 register
 */
#define HW_HDMI_FC_GMD_PB20_ADDR      (REGS_HDMI_BASE + 0x1119)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB20           (*(volatile hw_hdmi_fc_gmd_pb20_t *) HW_HDMI_FC_GMD_PB20_ADDR)
#define HW_HDMI_FC_GMD_PB20_RD()      (HW_HDMI_FC_GMD_PB20.U)
#define HW_HDMI_FC_GMD_PB20_WR(v)     (HW_HDMI_FC_GMD_PB20.U = (v))
#define HW_HDMI_FC_GMD_PB20_SET(v)    (HW_HDMI_FC_GMD_PB20_WR(HW_HDMI_FC_GMD_PB20_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB20_CLR(v)    (HW_HDMI_FC_GMD_PB20_WR(HW_HDMI_FC_GMD_PB20_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB20_TOG(v)    (HW_HDMI_FC_GMD_PB20_WR(HW_HDMI_FC_GMD_PB20_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB20 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB20, field FC_GMD_PB20 (RW)
 *
 * Gamut Metadata packet byte20
 */

#define BP_HDMI_FC_GMD_PB20_FC_GMD_PB20      0
#define BM_HDMI_FC_GMD_PB20_FC_GMD_PB20      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB20_FC_GMD_PB20(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB20_FC_GMD_PB20)
#else
#define BF_HDMI_FC_GMD_PB20_FC_GMD_PB20(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB20_FC_GMD_PB20)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB20 field to a new value.
#define BW_HDMI_FC_GMD_PB20_FC_GMD_PB20(v)   BF_CS1(HDMI_FC_GMD_PB20, FC_GMD_PB20, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB21 - Frame Composer GMD Packet Body Register 21 (RW)
 *
 * GMD packet body byte21  Address Offset: 0x111a  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB21 : 8; //!< Gamut Metadata packet byte21
    } B;
} hw_hdmi_fc_gmd_pb21_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB21 register
 */
#define HW_HDMI_FC_GMD_PB21_ADDR      (REGS_HDMI_BASE + 0x111a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB21           (*(volatile hw_hdmi_fc_gmd_pb21_t *) HW_HDMI_FC_GMD_PB21_ADDR)
#define HW_HDMI_FC_GMD_PB21_RD()      (HW_HDMI_FC_GMD_PB21.U)
#define HW_HDMI_FC_GMD_PB21_WR(v)     (HW_HDMI_FC_GMD_PB21.U = (v))
#define HW_HDMI_FC_GMD_PB21_SET(v)    (HW_HDMI_FC_GMD_PB21_WR(HW_HDMI_FC_GMD_PB21_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB21_CLR(v)    (HW_HDMI_FC_GMD_PB21_WR(HW_HDMI_FC_GMD_PB21_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB21_TOG(v)    (HW_HDMI_FC_GMD_PB21_WR(HW_HDMI_FC_GMD_PB21_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB21 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB21, field FC_GMD_PB21 (RW)
 *
 * Gamut Metadata packet byte21
 */

#define BP_HDMI_FC_GMD_PB21_FC_GMD_PB21      0
#define BM_HDMI_FC_GMD_PB21_FC_GMD_PB21      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB21_FC_GMD_PB21(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB21_FC_GMD_PB21)
#else
#define BF_HDMI_FC_GMD_PB21_FC_GMD_PB21(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB21_FC_GMD_PB21)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB21 field to a new value.
#define BW_HDMI_FC_GMD_PB21_FC_GMD_PB21(v)   BF_CS1(HDMI_FC_GMD_PB21, FC_GMD_PB21, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB22 - Frame Composer GMD Packet Body Register 22 (RW)
 *
 * GMD packet body byte22  Address Offset: 0x111b  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB22 : 8; //!< Gamut Metadata packet byte22
    } B;
} hw_hdmi_fc_gmd_pb22_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB22 register
 */
#define HW_HDMI_FC_GMD_PB22_ADDR      (REGS_HDMI_BASE + 0x111b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB22           (*(volatile hw_hdmi_fc_gmd_pb22_t *) HW_HDMI_FC_GMD_PB22_ADDR)
#define HW_HDMI_FC_GMD_PB22_RD()      (HW_HDMI_FC_GMD_PB22.U)
#define HW_HDMI_FC_GMD_PB22_WR(v)     (HW_HDMI_FC_GMD_PB22.U = (v))
#define HW_HDMI_FC_GMD_PB22_SET(v)    (HW_HDMI_FC_GMD_PB22_WR(HW_HDMI_FC_GMD_PB22_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB22_CLR(v)    (HW_HDMI_FC_GMD_PB22_WR(HW_HDMI_FC_GMD_PB22_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB22_TOG(v)    (HW_HDMI_FC_GMD_PB22_WR(HW_HDMI_FC_GMD_PB22_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB22 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB22, field FC_GMD_PB22 (RW)
 *
 * Gamut Metadata packet byte22
 */

#define BP_HDMI_FC_GMD_PB22_FC_GMD_PB22      0
#define BM_HDMI_FC_GMD_PB22_FC_GMD_PB22      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB22_FC_GMD_PB22(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB22_FC_GMD_PB22)
#else
#define BF_HDMI_FC_GMD_PB22_FC_GMD_PB22(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB22_FC_GMD_PB22)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB22 field to a new value.
#define BW_HDMI_FC_GMD_PB22_FC_GMD_PB22(v)   BF_CS1(HDMI_FC_GMD_PB22, FC_GMD_PB22, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB23 - Frame Composer GMD Packet Body Register 23 (RW)
 *
 * GMD packet body byte23  Address Offset: 0x111c  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB23 : 8; //!< Gamut Metadata packet byte23
    } B;
} hw_hdmi_fc_gmd_pb23_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB23 register
 */
#define HW_HDMI_FC_GMD_PB23_ADDR      (REGS_HDMI_BASE + 0x111c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB23           (*(volatile hw_hdmi_fc_gmd_pb23_t *) HW_HDMI_FC_GMD_PB23_ADDR)
#define HW_HDMI_FC_GMD_PB23_RD()      (HW_HDMI_FC_GMD_PB23.U)
#define HW_HDMI_FC_GMD_PB23_WR(v)     (HW_HDMI_FC_GMD_PB23.U = (v))
#define HW_HDMI_FC_GMD_PB23_SET(v)    (HW_HDMI_FC_GMD_PB23_WR(HW_HDMI_FC_GMD_PB23_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB23_CLR(v)    (HW_HDMI_FC_GMD_PB23_WR(HW_HDMI_FC_GMD_PB23_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB23_TOG(v)    (HW_HDMI_FC_GMD_PB23_WR(HW_HDMI_FC_GMD_PB23_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB23 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB23, field FC_GMD_PB23 (RW)
 *
 * Gamut Metadata packet byte23
 */

#define BP_HDMI_FC_GMD_PB23_FC_GMD_PB23      0
#define BM_HDMI_FC_GMD_PB23_FC_GMD_PB23      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB23_FC_GMD_PB23(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB23_FC_GMD_PB23)
#else
#define BF_HDMI_FC_GMD_PB23_FC_GMD_PB23(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB23_FC_GMD_PB23)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB23 field to a new value.
#define BW_HDMI_FC_GMD_PB23_FC_GMD_PB23(v)   BF_CS1(HDMI_FC_GMD_PB23, FC_GMD_PB23, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB24 - Frame Composer GMD Packet Body Register 24 (RW)
 *
 * GMD packet body byte24  Address Offset: 0x111d  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB24 : 8; //!< Gamut Metadata packet byte24
    } B;
} hw_hdmi_fc_gmd_pb24_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB24 register
 */
#define HW_HDMI_FC_GMD_PB24_ADDR      (REGS_HDMI_BASE + 0x111d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB24           (*(volatile hw_hdmi_fc_gmd_pb24_t *) HW_HDMI_FC_GMD_PB24_ADDR)
#define HW_HDMI_FC_GMD_PB24_RD()      (HW_HDMI_FC_GMD_PB24.U)
#define HW_HDMI_FC_GMD_PB24_WR(v)     (HW_HDMI_FC_GMD_PB24.U = (v))
#define HW_HDMI_FC_GMD_PB24_SET(v)    (HW_HDMI_FC_GMD_PB24_WR(HW_HDMI_FC_GMD_PB24_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB24_CLR(v)    (HW_HDMI_FC_GMD_PB24_WR(HW_HDMI_FC_GMD_PB24_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB24_TOG(v)    (HW_HDMI_FC_GMD_PB24_WR(HW_HDMI_FC_GMD_PB24_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB24 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB24, field FC_GMD_PB24 (RW)
 *
 * Gamut Metadata packet byte24
 */

#define BP_HDMI_FC_GMD_PB24_FC_GMD_PB24      0
#define BM_HDMI_FC_GMD_PB24_FC_GMD_PB24      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB24_FC_GMD_PB24(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB24_FC_GMD_PB24)
#else
#define BF_HDMI_FC_GMD_PB24_FC_GMD_PB24(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB24_FC_GMD_PB24)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB24 field to a new value.
#define BW_HDMI_FC_GMD_PB24_FC_GMD_PB24(v)   BF_CS1(HDMI_FC_GMD_PB24, FC_GMD_PB24, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB25 - Frame Composer GMD Packet Body Register 25 (RW)
 *
 * GMD packet body byte25  Address Offset: 0x111e  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB25 : 8; //!< Gamut Metadata packet byte25
    } B;
} hw_hdmi_fc_gmd_pb25_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB25 register
 */
#define HW_HDMI_FC_GMD_PB25_ADDR      (REGS_HDMI_BASE + 0x111e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB25           (*(volatile hw_hdmi_fc_gmd_pb25_t *) HW_HDMI_FC_GMD_PB25_ADDR)
#define HW_HDMI_FC_GMD_PB25_RD()      (HW_HDMI_FC_GMD_PB25.U)
#define HW_HDMI_FC_GMD_PB25_WR(v)     (HW_HDMI_FC_GMD_PB25.U = (v))
#define HW_HDMI_FC_GMD_PB25_SET(v)    (HW_HDMI_FC_GMD_PB25_WR(HW_HDMI_FC_GMD_PB25_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB25_CLR(v)    (HW_HDMI_FC_GMD_PB25_WR(HW_HDMI_FC_GMD_PB25_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB25_TOG(v)    (HW_HDMI_FC_GMD_PB25_WR(HW_HDMI_FC_GMD_PB25_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB25 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB25, field FC_GMD_PB25 (RW)
 *
 * Gamut Metadata packet byte25
 */

#define BP_HDMI_FC_GMD_PB25_FC_GMD_PB25      0
#define BM_HDMI_FC_GMD_PB25_FC_GMD_PB25      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB25_FC_GMD_PB25(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB25_FC_GMD_PB25)
#else
#define BF_HDMI_FC_GMD_PB25_FC_GMD_PB25(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB25_FC_GMD_PB25)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB25 field to a new value.
#define BW_HDMI_FC_GMD_PB25_FC_GMD_PB25(v)   BF_CS1(HDMI_FC_GMD_PB25, FC_GMD_PB25, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB26 - Frame Composer GMD Packet Body Register 26 (RW)
 *
 * GMD packet body byte26  Address Offset: 0x111f  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB26 : 8; //!< Gamut Metadata packet byte26
    } B;
} hw_hdmi_fc_gmd_pb26_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB26 register
 */
#define HW_HDMI_FC_GMD_PB26_ADDR      (REGS_HDMI_BASE + 0x111f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB26           (*(volatile hw_hdmi_fc_gmd_pb26_t *) HW_HDMI_FC_GMD_PB26_ADDR)
#define HW_HDMI_FC_GMD_PB26_RD()      (HW_HDMI_FC_GMD_PB26.U)
#define HW_HDMI_FC_GMD_PB26_WR(v)     (HW_HDMI_FC_GMD_PB26.U = (v))
#define HW_HDMI_FC_GMD_PB26_SET(v)    (HW_HDMI_FC_GMD_PB26_WR(HW_HDMI_FC_GMD_PB26_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB26_CLR(v)    (HW_HDMI_FC_GMD_PB26_WR(HW_HDMI_FC_GMD_PB26_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB26_TOG(v)    (HW_HDMI_FC_GMD_PB26_WR(HW_HDMI_FC_GMD_PB26_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB26 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB26, field FC_GMD_PB26 (RW)
 *
 * Gamut Metadata packet byte26
 */

#define BP_HDMI_FC_GMD_PB26_FC_GMD_PB26      0
#define BM_HDMI_FC_GMD_PB26_FC_GMD_PB26      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB26_FC_GMD_PB26(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB26_FC_GMD_PB26)
#else
#define BF_HDMI_FC_GMD_PB26_FC_GMD_PB26(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB26_FC_GMD_PB26)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB26 field to a new value.
#define BW_HDMI_FC_GMD_PB26_FC_GMD_PB26(v)   BF_CS1(HDMI_FC_GMD_PB26, FC_GMD_PB26, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_GMD_PB27 - Frame Composer GMD Packet Body Register 27 (RW)
 *
 * GMD packet body byte27  Address Offset: 0x1120  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write   For more information, refer to the HDMI 1.4a specification.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_GMD_PB27 : 8; //!< Gamut Metadata packet byte27
    } B;
} hw_hdmi_fc_gmd_pb27_t;
#endif

/*
 * constants & macros for entire HDMI_FC_GMD_PB27 register
 */
#define HW_HDMI_FC_GMD_PB27_ADDR      (REGS_HDMI_BASE + 0x1120)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_GMD_PB27           (*(volatile hw_hdmi_fc_gmd_pb27_t *) HW_HDMI_FC_GMD_PB27_ADDR)
#define HW_HDMI_FC_GMD_PB27_RD()      (HW_HDMI_FC_GMD_PB27.U)
#define HW_HDMI_FC_GMD_PB27_WR(v)     (HW_HDMI_FC_GMD_PB27.U = (v))
#define HW_HDMI_FC_GMD_PB27_SET(v)    (HW_HDMI_FC_GMD_PB27_WR(HW_HDMI_FC_GMD_PB27_RD() |  (v)))
#define HW_HDMI_FC_GMD_PB27_CLR(v)    (HW_HDMI_FC_GMD_PB27_WR(HW_HDMI_FC_GMD_PB27_RD() & ~(v)))
#define HW_HDMI_FC_GMD_PB27_TOG(v)    (HW_HDMI_FC_GMD_PB27_WR(HW_HDMI_FC_GMD_PB27_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_GMD_PB27 bitfields
 */

/* --- Register HW_HDMI_FC_GMD_PB27, field FC_GMD_PB27 (RW)
 *
 * Gamut Metadata packet byte27
 */

#define BP_HDMI_FC_GMD_PB27_FC_GMD_PB27      0
#define BM_HDMI_FC_GMD_PB27_FC_GMD_PB27      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_GMD_PB27_FC_GMD_PB27(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_GMD_PB27_FC_GMD_PB27)
#else
#define BF_HDMI_FC_GMD_PB27_FC_GMD_PB27(v)   (((v) << 0) & BM_HDMI_FC_GMD_PB27_FC_GMD_PB27)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_GMD_PB27 field to a new value.
#define BW_HDMI_FC_GMD_PB27_FC_GMD_PB27(v)   BF_CS1(HDMI_FC_GMD_PB27, FC_GMD_PB27, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGFORCE - Frame Composer Video/Audio Force Enable Register (RW)
 *
 * This register allows to force the controller to output audio and video data the values configured
 * in the FC_DBGAUD and FC_DBGTMDS registers.   Address Offset: 0x1200  Size: 8 bits  Value after
 * Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FORCEVIDEO : 1; //!< Force fixed video output with FC_DBGTMDSx registers contain.
        unsigned char RESERVED0 : 3; //!< Reserved
        unsigned char FORCEAUDIO : 1; //!< Force fixed audio output with FC_DBGAUDxCHx registers contain.
        unsigned char RESERVED1 : 3; //!< Reserved
    } B;
} hw_hdmi_fc_dbgforce_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGFORCE register
 */
#define HW_HDMI_FC_DBGFORCE_ADDR      (REGS_HDMI_BASE + 0x1200)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGFORCE           (*(volatile hw_hdmi_fc_dbgforce_t *) HW_HDMI_FC_DBGFORCE_ADDR)
#define HW_HDMI_FC_DBGFORCE_RD()      (HW_HDMI_FC_DBGFORCE.U)
#define HW_HDMI_FC_DBGFORCE_WR(v)     (HW_HDMI_FC_DBGFORCE.U = (v))
#define HW_HDMI_FC_DBGFORCE_SET(v)    (HW_HDMI_FC_DBGFORCE_WR(HW_HDMI_FC_DBGFORCE_RD() |  (v)))
#define HW_HDMI_FC_DBGFORCE_CLR(v)    (HW_HDMI_FC_DBGFORCE_WR(HW_HDMI_FC_DBGFORCE_RD() & ~(v)))
#define HW_HDMI_FC_DBGFORCE_TOG(v)    (HW_HDMI_FC_DBGFORCE_WR(HW_HDMI_FC_DBGFORCE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGFORCE bitfields
 */

/* --- Register HW_HDMI_FC_DBGFORCE, field FORCEVIDEO (RW)
 *
 * Force fixed video output with FC_DBGTMDSx registers contain.
 */

#define BP_HDMI_FC_DBGFORCE_FORCEVIDEO      0
#define BM_HDMI_FC_DBGFORCE_FORCEVIDEO      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGFORCE_FORCEVIDEO(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGFORCE_FORCEVIDEO)
#else
#define BF_HDMI_FC_DBGFORCE_FORCEVIDEO(v)   (((v) << 0) & BM_HDMI_FC_DBGFORCE_FORCEVIDEO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FORCEVIDEO field to a new value.
#define BW_HDMI_FC_DBGFORCE_FORCEVIDEO(v)   BF_CS1(HDMI_FC_DBGFORCE, FORCEVIDEO, v)
#endif

/* --- Register HW_HDMI_FC_DBGFORCE, field FORCEAUDIO (RW)
 *
 * Force fixed audio output with FC_DBGAUDxCHx registers contain.
 */

#define BP_HDMI_FC_DBGFORCE_FORCEAUDIO      4
#define BM_HDMI_FC_DBGFORCE_FORCEAUDIO      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGFORCE_FORCEAUDIO(v)   ((((reg32_t) v) << 4) & BM_HDMI_FC_DBGFORCE_FORCEAUDIO)
#else
#define BF_HDMI_FC_DBGFORCE_FORCEAUDIO(v)   (((v) << 4) & BM_HDMI_FC_DBGFORCE_FORCEAUDIO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FORCEAUDIO field to a new value.
#define BW_HDMI_FC_DBGFORCE_FORCEAUDIO(v)   BF_CS1(HDMI_FC_DBGFORCE, FORCEAUDIO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD0CH0 - Frame Composer Audio Channel 0 Register 0 (RW)
 *
 * Configures the audio fixed data to be used in channel 0 when in fixed audio selection.   Address
 * Offset: 0x1201  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD0CH0 : 8; //!< the audio fixed data byte0 to be used in channel 0 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud0ch0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD0CH0 register
 */
#define HW_HDMI_FC_DBGAUD0CH0_ADDR      (REGS_HDMI_BASE + 0x1201)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD0CH0           (*(volatile hw_hdmi_fc_dbgaud0ch0_t *) HW_HDMI_FC_DBGAUD0CH0_ADDR)
#define HW_HDMI_FC_DBGAUD0CH0_RD()      (HW_HDMI_FC_DBGAUD0CH0.U)
#define HW_HDMI_FC_DBGAUD0CH0_WR(v)     (HW_HDMI_FC_DBGAUD0CH0.U = (v))
#define HW_HDMI_FC_DBGAUD0CH0_SET(v)    (HW_HDMI_FC_DBGAUD0CH0_WR(HW_HDMI_FC_DBGAUD0CH0_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD0CH0_CLR(v)    (HW_HDMI_FC_DBGAUD0CH0_WR(HW_HDMI_FC_DBGAUD0CH0_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD0CH0_TOG(v)    (HW_HDMI_FC_DBGAUD0CH0_WR(HW_HDMI_FC_DBGAUD0CH0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD0CH0 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD0CH0, field FC_DBGAUD0CH0 (RW)
 *
 * the audio fixed data byte0 to be used in channel 0 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD0CH0_FC_DBGAUD0CH0      0
#define BM_HDMI_FC_DBGAUD0CH0_FC_DBGAUD0CH0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD0CH0_FC_DBGAUD0CH0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD0CH0_FC_DBGAUD0CH0)
#else
#define BF_HDMI_FC_DBGAUD0CH0_FC_DBGAUD0CH0(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD0CH0_FC_DBGAUD0CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD0CH0 field to a new value.
#define BW_HDMI_FC_DBGAUD0CH0_FC_DBGAUD0CH0(v)   BF_CS1(HDMI_FC_DBGAUD0CH0, FC_DBGAUD0CH0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD1CH0 - Frame Composer Audio Channel 0 Register 1 (RW)
 *
 * Address Offset: 0x1202  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD1CH0 : 8; //!< the audio fixed data byte1 to be used in channel 0 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud1ch0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD1CH0 register
 */
#define HW_HDMI_FC_DBGAUD1CH0_ADDR      (REGS_HDMI_BASE + 0x1202)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD1CH0           (*(volatile hw_hdmi_fc_dbgaud1ch0_t *) HW_HDMI_FC_DBGAUD1CH0_ADDR)
#define HW_HDMI_FC_DBGAUD1CH0_RD()      (HW_HDMI_FC_DBGAUD1CH0.U)
#define HW_HDMI_FC_DBGAUD1CH0_WR(v)     (HW_HDMI_FC_DBGAUD1CH0.U = (v))
#define HW_HDMI_FC_DBGAUD1CH0_SET(v)    (HW_HDMI_FC_DBGAUD1CH0_WR(HW_HDMI_FC_DBGAUD1CH0_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD1CH0_CLR(v)    (HW_HDMI_FC_DBGAUD1CH0_WR(HW_HDMI_FC_DBGAUD1CH0_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD1CH0_TOG(v)    (HW_HDMI_FC_DBGAUD1CH0_WR(HW_HDMI_FC_DBGAUD1CH0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD1CH0 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD1CH0, field FC_DBGAUD1CH0 (RW)
 *
 * the audio fixed data byte1 to be used in channel 0 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD1CH0_FC_DBGAUD1CH0      0
#define BM_HDMI_FC_DBGAUD1CH0_FC_DBGAUD1CH0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD1CH0_FC_DBGAUD1CH0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD1CH0_FC_DBGAUD1CH0)
#else
#define BF_HDMI_FC_DBGAUD1CH0_FC_DBGAUD1CH0(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD1CH0_FC_DBGAUD1CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD1CH0 field to a new value.
#define BW_HDMI_FC_DBGAUD1CH0_FC_DBGAUD1CH0(v)   BF_CS1(HDMI_FC_DBGAUD1CH0, FC_DBGAUD1CH0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD2CH0 - Frame Composer Audio Channel 0 Register 2 (RW)
 *
 * Address Offset: 0x1203  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD2CH0 : 8; //!< the audio fixed data byte2 to be used in channel 0 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud2ch0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD2CH0 register
 */
#define HW_HDMI_FC_DBGAUD2CH0_ADDR      (REGS_HDMI_BASE + 0x1203)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD2CH0           (*(volatile hw_hdmi_fc_dbgaud2ch0_t *) HW_HDMI_FC_DBGAUD2CH0_ADDR)
#define HW_HDMI_FC_DBGAUD2CH0_RD()      (HW_HDMI_FC_DBGAUD2CH0.U)
#define HW_HDMI_FC_DBGAUD2CH0_WR(v)     (HW_HDMI_FC_DBGAUD2CH0.U = (v))
#define HW_HDMI_FC_DBGAUD2CH0_SET(v)    (HW_HDMI_FC_DBGAUD2CH0_WR(HW_HDMI_FC_DBGAUD2CH0_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD2CH0_CLR(v)    (HW_HDMI_FC_DBGAUD2CH0_WR(HW_HDMI_FC_DBGAUD2CH0_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD2CH0_TOG(v)    (HW_HDMI_FC_DBGAUD2CH0_WR(HW_HDMI_FC_DBGAUD2CH0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD2CH0 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD2CH0, field FC_DBGAUD2CH0 (RW)
 *
 * the audio fixed data byte2 to be used in channel 0 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD2CH0_FC_DBGAUD2CH0      0
#define BM_HDMI_FC_DBGAUD2CH0_FC_DBGAUD2CH0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD2CH0_FC_DBGAUD2CH0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD2CH0_FC_DBGAUD2CH0)
#else
#define BF_HDMI_FC_DBGAUD2CH0_FC_DBGAUD2CH0(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD2CH0_FC_DBGAUD2CH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD2CH0 field to a new value.
#define BW_HDMI_FC_DBGAUD2CH0_FC_DBGAUD2CH0(v)   BF_CS1(HDMI_FC_DBGAUD2CH0, FC_DBGAUD2CH0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD0CH1 - Frame Composer Audio Channel 1 Register 0 (RW)
 *
 * Configures the audio fixed data to be used in channel 0 when in fixed audio selection.   Address
 * Offset: 0x1204  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD0CH1 : 8; //!< the audio fixed data byte2 to be used in channel 0 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud0ch1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD0CH1 register
 */
#define HW_HDMI_FC_DBGAUD0CH1_ADDR      (REGS_HDMI_BASE + 0x1204)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD0CH1           (*(volatile hw_hdmi_fc_dbgaud0ch1_t *) HW_HDMI_FC_DBGAUD0CH1_ADDR)
#define HW_HDMI_FC_DBGAUD0CH1_RD()      (HW_HDMI_FC_DBGAUD0CH1.U)
#define HW_HDMI_FC_DBGAUD0CH1_WR(v)     (HW_HDMI_FC_DBGAUD0CH1.U = (v))
#define HW_HDMI_FC_DBGAUD0CH1_SET(v)    (HW_HDMI_FC_DBGAUD0CH1_WR(HW_HDMI_FC_DBGAUD0CH1_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD0CH1_CLR(v)    (HW_HDMI_FC_DBGAUD0CH1_WR(HW_HDMI_FC_DBGAUD0CH1_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD0CH1_TOG(v)    (HW_HDMI_FC_DBGAUD0CH1_WR(HW_HDMI_FC_DBGAUD0CH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD0CH1 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD0CH1, field FC_DBGAUD0CH1 (RW)
 *
 * the audio fixed data byte2 to be used in channel 0 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD0CH1_FC_DBGAUD0CH1      0
#define BM_HDMI_FC_DBGAUD0CH1_FC_DBGAUD0CH1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD0CH1_FC_DBGAUD0CH1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD0CH1_FC_DBGAUD0CH1)
#else
#define BF_HDMI_FC_DBGAUD0CH1_FC_DBGAUD0CH1(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD0CH1_FC_DBGAUD0CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD0CH1 field to a new value.
#define BW_HDMI_FC_DBGAUD0CH1_FC_DBGAUD0CH1(v)   BF_CS1(HDMI_FC_DBGAUD0CH1, FC_DBGAUD0CH1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD1CH1 - Frame Composer Audio Channel 1 Register 1 (RW)
 *
 * Address Offset: 0x1205  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD1CH1 : 8; //!< the audio fixed data byte1 to be used in channel 1 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud1ch1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD1CH1 register
 */
#define HW_HDMI_FC_DBGAUD1CH1_ADDR      (REGS_HDMI_BASE + 0x1205)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD1CH1           (*(volatile hw_hdmi_fc_dbgaud1ch1_t *) HW_HDMI_FC_DBGAUD1CH1_ADDR)
#define HW_HDMI_FC_DBGAUD1CH1_RD()      (HW_HDMI_FC_DBGAUD1CH1.U)
#define HW_HDMI_FC_DBGAUD1CH1_WR(v)     (HW_HDMI_FC_DBGAUD1CH1.U = (v))
#define HW_HDMI_FC_DBGAUD1CH1_SET(v)    (HW_HDMI_FC_DBGAUD1CH1_WR(HW_HDMI_FC_DBGAUD1CH1_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD1CH1_CLR(v)    (HW_HDMI_FC_DBGAUD1CH1_WR(HW_HDMI_FC_DBGAUD1CH1_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD1CH1_TOG(v)    (HW_HDMI_FC_DBGAUD1CH1_WR(HW_HDMI_FC_DBGAUD1CH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD1CH1 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD1CH1, field FC_DBGAUD1CH1 (RW)
 *
 * the audio fixed data byte1 to be used in channel 1 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD1CH1_FC_DBGAUD1CH1      0
#define BM_HDMI_FC_DBGAUD1CH1_FC_DBGAUD1CH1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD1CH1_FC_DBGAUD1CH1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD1CH1_FC_DBGAUD1CH1)
#else
#define BF_HDMI_FC_DBGAUD1CH1_FC_DBGAUD1CH1(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD1CH1_FC_DBGAUD1CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD1CH1 field to a new value.
#define BW_HDMI_FC_DBGAUD1CH1_FC_DBGAUD1CH1(v)   BF_CS1(HDMI_FC_DBGAUD1CH1, FC_DBGAUD1CH1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD2CH1 - Frame Composer Audio Channel 1 Register 2 (RW)
 *
 * Address Offset: 0x1206  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD2CH1 : 8; //!< the audio fixed data byte2 to be used in channel 1 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud2ch1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD2CH1 register
 */
#define HW_HDMI_FC_DBGAUD2CH1_ADDR      (REGS_HDMI_BASE + 0x1206)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD2CH1           (*(volatile hw_hdmi_fc_dbgaud2ch1_t *) HW_HDMI_FC_DBGAUD2CH1_ADDR)
#define HW_HDMI_FC_DBGAUD2CH1_RD()      (HW_HDMI_FC_DBGAUD2CH1.U)
#define HW_HDMI_FC_DBGAUD2CH1_WR(v)     (HW_HDMI_FC_DBGAUD2CH1.U = (v))
#define HW_HDMI_FC_DBGAUD2CH1_SET(v)    (HW_HDMI_FC_DBGAUD2CH1_WR(HW_HDMI_FC_DBGAUD2CH1_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD2CH1_CLR(v)    (HW_HDMI_FC_DBGAUD2CH1_WR(HW_HDMI_FC_DBGAUD2CH1_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD2CH1_TOG(v)    (HW_HDMI_FC_DBGAUD2CH1_WR(HW_HDMI_FC_DBGAUD2CH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD2CH1 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD2CH1, field FC_DBGAUD2CH1 (RW)
 *
 * the audio fixed data byte2 to be used in channel 1 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD2CH1_FC_DBGAUD2CH1      0
#define BM_HDMI_FC_DBGAUD2CH1_FC_DBGAUD2CH1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD2CH1_FC_DBGAUD2CH1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD2CH1_FC_DBGAUD2CH1)
#else
#define BF_HDMI_FC_DBGAUD2CH1_FC_DBGAUD2CH1(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD2CH1_FC_DBGAUD2CH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD2CH1 field to a new value.
#define BW_HDMI_FC_DBGAUD2CH1_FC_DBGAUD2CH1(v)   BF_CS1(HDMI_FC_DBGAUD2CH1, FC_DBGAUD2CH1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD0CH2 - Frame Composer Debug Audio Channel 2 Register 0 (RW)
 *
 * Configures the audio fixed data to be used in channel 0 when in fixed audio selection.   Address
 * Offset: 0x1207  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD0CH2 : 8; //!< the audio fixed data byte0 to be used in channel 2 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud0ch2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD0CH2 register
 */
#define HW_HDMI_FC_DBGAUD0CH2_ADDR      (REGS_HDMI_BASE + 0x1207)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD0CH2           (*(volatile hw_hdmi_fc_dbgaud0ch2_t *) HW_HDMI_FC_DBGAUD0CH2_ADDR)
#define HW_HDMI_FC_DBGAUD0CH2_RD()      (HW_HDMI_FC_DBGAUD0CH2.U)
#define HW_HDMI_FC_DBGAUD0CH2_WR(v)     (HW_HDMI_FC_DBGAUD0CH2.U = (v))
#define HW_HDMI_FC_DBGAUD0CH2_SET(v)    (HW_HDMI_FC_DBGAUD0CH2_WR(HW_HDMI_FC_DBGAUD0CH2_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD0CH2_CLR(v)    (HW_HDMI_FC_DBGAUD0CH2_WR(HW_HDMI_FC_DBGAUD0CH2_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD0CH2_TOG(v)    (HW_HDMI_FC_DBGAUD0CH2_WR(HW_HDMI_FC_DBGAUD0CH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD0CH2 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD0CH2, field FC_DBGAUD0CH2 (RW)
 *
 * the audio fixed data byte0 to be used in channel 2 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD0CH2_FC_DBGAUD0CH2      0
#define BM_HDMI_FC_DBGAUD0CH2_FC_DBGAUD0CH2      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD0CH2_FC_DBGAUD0CH2(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD0CH2_FC_DBGAUD0CH2)
#else
#define BF_HDMI_FC_DBGAUD0CH2_FC_DBGAUD0CH2(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD0CH2_FC_DBGAUD0CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD0CH2 field to a new value.
#define BW_HDMI_FC_DBGAUD0CH2_FC_DBGAUD0CH2(v)   BF_CS1(HDMI_FC_DBGAUD0CH2, FC_DBGAUD0CH2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD1CH2 - Frame Composer Debug Audio Channel 2 Register 1 (RW)
 *
 * Address Offset: 0x1208  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD1CH2 : 8; //!< the audio fixed data byte1 to be used in channel 2 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud1ch2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD1CH2 register
 */
#define HW_HDMI_FC_DBGAUD1CH2_ADDR      (REGS_HDMI_BASE + 0x1208)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD1CH2           (*(volatile hw_hdmi_fc_dbgaud1ch2_t *) HW_HDMI_FC_DBGAUD1CH2_ADDR)
#define HW_HDMI_FC_DBGAUD1CH2_RD()      (HW_HDMI_FC_DBGAUD1CH2.U)
#define HW_HDMI_FC_DBGAUD1CH2_WR(v)     (HW_HDMI_FC_DBGAUD1CH2.U = (v))
#define HW_HDMI_FC_DBGAUD1CH2_SET(v)    (HW_HDMI_FC_DBGAUD1CH2_WR(HW_HDMI_FC_DBGAUD1CH2_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD1CH2_CLR(v)    (HW_HDMI_FC_DBGAUD1CH2_WR(HW_HDMI_FC_DBGAUD1CH2_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD1CH2_TOG(v)    (HW_HDMI_FC_DBGAUD1CH2_WR(HW_HDMI_FC_DBGAUD1CH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD1CH2 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD1CH2, field FC_DBGAUD1CH2 (RW)
 *
 * the audio fixed data byte1 to be used in channel 2 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD1CH2_FC_DBGAUD1CH2      0
#define BM_HDMI_FC_DBGAUD1CH2_FC_DBGAUD1CH2      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD1CH2_FC_DBGAUD1CH2(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD1CH2_FC_DBGAUD1CH2)
#else
#define BF_HDMI_FC_DBGAUD1CH2_FC_DBGAUD1CH2(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD1CH2_FC_DBGAUD1CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD1CH2 field to a new value.
#define BW_HDMI_FC_DBGAUD1CH2_FC_DBGAUD1CH2(v)   BF_CS1(HDMI_FC_DBGAUD1CH2, FC_DBGAUD1CH2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD2CH2 - Frame Composer Audio Channel 2 Register 2 (RW)
 *
 * Address Offset: 0x1209  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD2CH2 : 8; //!< the audio fixed data byte2 to be used in channel 2 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud2ch2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD2CH2 register
 */
#define HW_HDMI_FC_DBGAUD2CH2_ADDR      (REGS_HDMI_BASE + 0x1209)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD2CH2           (*(volatile hw_hdmi_fc_dbgaud2ch2_t *) HW_HDMI_FC_DBGAUD2CH2_ADDR)
#define HW_HDMI_FC_DBGAUD2CH2_RD()      (HW_HDMI_FC_DBGAUD2CH2.U)
#define HW_HDMI_FC_DBGAUD2CH2_WR(v)     (HW_HDMI_FC_DBGAUD2CH2.U = (v))
#define HW_HDMI_FC_DBGAUD2CH2_SET(v)    (HW_HDMI_FC_DBGAUD2CH2_WR(HW_HDMI_FC_DBGAUD2CH2_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD2CH2_CLR(v)    (HW_HDMI_FC_DBGAUD2CH2_WR(HW_HDMI_FC_DBGAUD2CH2_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD2CH2_TOG(v)    (HW_HDMI_FC_DBGAUD2CH2_WR(HW_HDMI_FC_DBGAUD2CH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD2CH2 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD2CH2, field FC_DBGAUD2CH2 (RW)
 *
 * the audio fixed data byte2 to be used in channel 2 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD2CH2_FC_DBGAUD2CH2      0
#define BM_HDMI_FC_DBGAUD2CH2_FC_DBGAUD2CH2      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD2CH2_FC_DBGAUD2CH2(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD2CH2_FC_DBGAUD2CH2)
#else
#define BF_HDMI_FC_DBGAUD2CH2_FC_DBGAUD2CH2(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD2CH2_FC_DBGAUD2CH2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD2CH2 field to a new value.
#define BW_HDMI_FC_DBGAUD2CH2_FC_DBGAUD2CH2(v)   BF_CS1(HDMI_FC_DBGAUD2CH2, FC_DBGAUD2CH2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD0CH3 - Frame Composer Audio Channel 3 Register 0 (RW)
 *
 * Configures the audio fixed data to be used in channel 0 when in fixed audio selection.   Address
 * Offset: 0x120A  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD0CH3 : 8; //!< the audio fixed data byte0 to be used in channel 3 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud0ch3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD0CH3 register
 */
#define HW_HDMI_FC_DBGAUD0CH3_ADDR      (REGS_HDMI_BASE + 0x120a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD0CH3           (*(volatile hw_hdmi_fc_dbgaud0ch3_t *) HW_HDMI_FC_DBGAUD0CH3_ADDR)
#define HW_HDMI_FC_DBGAUD0CH3_RD()      (HW_HDMI_FC_DBGAUD0CH3.U)
#define HW_HDMI_FC_DBGAUD0CH3_WR(v)     (HW_HDMI_FC_DBGAUD0CH3.U = (v))
#define HW_HDMI_FC_DBGAUD0CH3_SET(v)    (HW_HDMI_FC_DBGAUD0CH3_WR(HW_HDMI_FC_DBGAUD0CH3_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD0CH3_CLR(v)    (HW_HDMI_FC_DBGAUD0CH3_WR(HW_HDMI_FC_DBGAUD0CH3_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD0CH3_TOG(v)    (HW_HDMI_FC_DBGAUD0CH3_WR(HW_HDMI_FC_DBGAUD0CH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD0CH3 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD0CH3, field FC_DBGAUD0CH3 (RW)
 *
 * the audio fixed data byte0 to be used in channel 3 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD0CH3_FC_DBGAUD0CH3      0
#define BM_HDMI_FC_DBGAUD0CH3_FC_DBGAUD0CH3      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD0CH3_FC_DBGAUD0CH3(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD0CH3_FC_DBGAUD0CH3)
#else
#define BF_HDMI_FC_DBGAUD0CH3_FC_DBGAUD0CH3(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD0CH3_FC_DBGAUD0CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD0CH3 field to a new value.
#define BW_HDMI_FC_DBGAUD0CH3_FC_DBGAUD0CH3(v)   BF_CS1(HDMI_FC_DBGAUD0CH3, FC_DBGAUD0CH3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD1CH3 - Frame Composer Audio Channel 3 Register 1 (RW)
 *
 * Address Offset: 0x120B  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD1CH3 : 8; //!< the audio fixed data byte1 to be used in channel 3 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud1ch3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD1CH3 register
 */
#define HW_HDMI_FC_DBGAUD1CH3_ADDR      (REGS_HDMI_BASE + 0x120b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD1CH3           (*(volatile hw_hdmi_fc_dbgaud1ch3_t *) HW_HDMI_FC_DBGAUD1CH3_ADDR)
#define HW_HDMI_FC_DBGAUD1CH3_RD()      (HW_HDMI_FC_DBGAUD1CH3.U)
#define HW_HDMI_FC_DBGAUD1CH3_WR(v)     (HW_HDMI_FC_DBGAUD1CH3.U = (v))
#define HW_HDMI_FC_DBGAUD1CH3_SET(v)    (HW_HDMI_FC_DBGAUD1CH3_WR(HW_HDMI_FC_DBGAUD1CH3_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD1CH3_CLR(v)    (HW_HDMI_FC_DBGAUD1CH3_WR(HW_HDMI_FC_DBGAUD1CH3_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD1CH3_TOG(v)    (HW_HDMI_FC_DBGAUD1CH3_WR(HW_HDMI_FC_DBGAUD1CH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD1CH3 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD1CH3, field FC_DBGAUD1CH3 (RW)
 *
 * the audio fixed data byte1 to be used in channel 3 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD1CH3_FC_DBGAUD1CH3      0
#define BM_HDMI_FC_DBGAUD1CH3_FC_DBGAUD1CH3      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD1CH3_FC_DBGAUD1CH3(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD1CH3_FC_DBGAUD1CH3)
#else
#define BF_HDMI_FC_DBGAUD1CH3_FC_DBGAUD1CH3(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD1CH3_FC_DBGAUD1CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD1CH3 field to a new value.
#define BW_HDMI_FC_DBGAUD1CH3_FC_DBGAUD1CH3(v)   BF_CS1(HDMI_FC_DBGAUD1CH3, FC_DBGAUD1CH3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD2CH3 - Frame Composer Audio Channel 3 Register 2 (RW)
 *
 * Address Offset: 0x120C  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD2CH3 : 8; //!< the audio fixed data byte2 to be used in channel 3 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud2ch3_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD2CH3 register
 */
#define HW_HDMI_FC_DBGAUD2CH3_ADDR      (REGS_HDMI_BASE + 0x120c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD2CH3           (*(volatile hw_hdmi_fc_dbgaud2ch3_t *) HW_HDMI_FC_DBGAUD2CH3_ADDR)
#define HW_HDMI_FC_DBGAUD2CH3_RD()      (HW_HDMI_FC_DBGAUD2CH3.U)
#define HW_HDMI_FC_DBGAUD2CH3_WR(v)     (HW_HDMI_FC_DBGAUD2CH3.U = (v))
#define HW_HDMI_FC_DBGAUD2CH3_SET(v)    (HW_HDMI_FC_DBGAUD2CH3_WR(HW_HDMI_FC_DBGAUD2CH3_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD2CH3_CLR(v)    (HW_HDMI_FC_DBGAUD2CH3_WR(HW_HDMI_FC_DBGAUD2CH3_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD2CH3_TOG(v)    (HW_HDMI_FC_DBGAUD2CH3_WR(HW_HDMI_FC_DBGAUD2CH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD2CH3 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD2CH3, field FC_DBGAUD2CH3 (RW)
 *
 * the audio fixed data byte2 to be used in channel 3 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD2CH3_FC_DBGAUD2CH3      0
#define BM_HDMI_FC_DBGAUD2CH3_FC_DBGAUD2CH3      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD2CH3_FC_DBGAUD2CH3(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD2CH3_FC_DBGAUD2CH3)
#else
#define BF_HDMI_FC_DBGAUD2CH3_FC_DBGAUD2CH3(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD2CH3_FC_DBGAUD2CH3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD2CH3 field to a new value.
#define BW_HDMI_FC_DBGAUD2CH3_FC_DBGAUD2CH3(v)   BF_CS1(HDMI_FC_DBGAUD2CH3, FC_DBGAUD2CH3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD0CH4 - Frame Composer Audio Channel 4 Register 0 (RW)
 *
 * Configures the audio fixed data to be used in channel 0 when in fixed audio selection.   Address
 * Offset: 0x120D  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD0CH4 : 8; //!< the audio fixed data byte0 to be used in channel 4 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud0ch4_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD0CH4 register
 */
#define HW_HDMI_FC_DBGAUD0CH4_ADDR      (REGS_HDMI_BASE + 0x120d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD0CH4           (*(volatile hw_hdmi_fc_dbgaud0ch4_t *) HW_HDMI_FC_DBGAUD0CH4_ADDR)
#define HW_HDMI_FC_DBGAUD0CH4_RD()      (HW_HDMI_FC_DBGAUD0CH4.U)
#define HW_HDMI_FC_DBGAUD0CH4_WR(v)     (HW_HDMI_FC_DBGAUD0CH4.U = (v))
#define HW_HDMI_FC_DBGAUD0CH4_SET(v)    (HW_HDMI_FC_DBGAUD0CH4_WR(HW_HDMI_FC_DBGAUD0CH4_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD0CH4_CLR(v)    (HW_HDMI_FC_DBGAUD0CH4_WR(HW_HDMI_FC_DBGAUD0CH4_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD0CH4_TOG(v)    (HW_HDMI_FC_DBGAUD0CH4_WR(HW_HDMI_FC_DBGAUD0CH4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD0CH4 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD0CH4, field FC_DBGAUD0CH4 (RW)
 *
 * the audio fixed data byte0 to be used in channel 4 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD0CH4_FC_DBGAUD0CH4      0
#define BM_HDMI_FC_DBGAUD0CH4_FC_DBGAUD0CH4      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD0CH4_FC_DBGAUD0CH4(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD0CH4_FC_DBGAUD0CH4)
#else
#define BF_HDMI_FC_DBGAUD0CH4_FC_DBGAUD0CH4(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD0CH4_FC_DBGAUD0CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD0CH4 field to a new value.
#define BW_HDMI_FC_DBGAUD0CH4_FC_DBGAUD0CH4(v)   BF_CS1(HDMI_FC_DBGAUD0CH4, FC_DBGAUD0CH4, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD1CH4 - Frame Composer Audio Channel 4 Register 1 (RW)
 *
 * Address Offset: 0x120E  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD1CH4 : 8; //!< the audio fixed data byte1 to be used in channel 4 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud1ch4_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD1CH4 register
 */
#define HW_HDMI_FC_DBGAUD1CH4_ADDR      (REGS_HDMI_BASE + 0x120e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD1CH4           (*(volatile hw_hdmi_fc_dbgaud1ch4_t *) HW_HDMI_FC_DBGAUD1CH4_ADDR)
#define HW_HDMI_FC_DBGAUD1CH4_RD()      (HW_HDMI_FC_DBGAUD1CH4.U)
#define HW_HDMI_FC_DBGAUD1CH4_WR(v)     (HW_HDMI_FC_DBGAUD1CH4.U = (v))
#define HW_HDMI_FC_DBGAUD1CH4_SET(v)    (HW_HDMI_FC_DBGAUD1CH4_WR(HW_HDMI_FC_DBGAUD1CH4_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD1CH4_CLR(v)    (HW_HDMI_FC_DBGAUD1CH4_WR(HW_HDMI_FC_DBGAUD1CH4_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD1CH4_TOG(v)    (HW_HDMI_FC_DBGAUD1CH4_WR(HW_HDMI_FC_DBGAUD1CH4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD1CH4 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD1CH4, field FC_DBGAUD1CH4 (RW)
 *
 * the audio fixed data byte1 to be used in channel 4 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD1CH4_FC_DBGAUD1CH4      0
#define BM_HDMI_FC_DBGAUD1CH4_FC_DBGAUD1CH4      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD1CH4_FC_DBGAUD1CH4(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD1CH4_FC_DBGAUD1CH4)
#else
#define BF_HDMI_FC_DBGAUD1CH4_FC_DBGAUD1CH4(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD1CH4_FC_DBGAUD1CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD1CH4 field to a new value.
#define BW_HDMI_FC_DBGAUD1CH4_FC_DBGAUD1CH4(v)   BF_CS1(HDMI_FC_DBGAUD1CH4, FC_DBGAUD1CH4, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD2CH4 - Frame Composer Audio Channel 4 Register 2 (RW)
 *
 * Address Offset: 0x120F  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD2CH4 : 8; //!< the audio fixed data byte2 to be used in channel 4 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud2ch4_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD2CH4 register
 */
#define HW_HDMI_FC_DBGAUD2CH4_ADDR      (REGS_HDMI_BASE + 0x120f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD2CH4           (*(volatile hw_hdmi_fc_dbgaud2ch4_t *) HW_HDMI_FC_DBGAUD2CH4_ADDR)
#define HW_HDMI_FC_DBGAUD2CH4_RD()      (HW_HDMI_FC_DBGAUD2CH4.U)
#define HW_HDMI_FC_DBGAUD2CH4_WR(v)     (HW_HDMI_FC_DBGAUD2CH4.U = (v))
#define HW_HDMI_FC_DBGAUD2CH4_SET(v)    (HW_HDMI_FC_DBGAUD2CH4_WR(HW_HDMI_FC_DBGAUD2CH4_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD2CH4_CLR(v)    (HW_HDMI_FC_DBGAUD2CH4_WR(HW_HDMI_FC_DBGAUD2CH4_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD2CH4_TOG(v)    (HW_HDMI_FC_DBGAUD2CH4_WR(HW_HDMI_FC_DBGAUD2CH4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD2CH4 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD2CH4, field FC_DBGAUD2CH4 (RW)
 *
 * the audio fixed data byte2 to be used in channel 4 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD2CH4_FC_DBGAUD2CH4      0
#define BM_HDMI_FC_DBGAUD2CH4_FC_DBGAUD2CH4      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD2CH4_FC_DBGAUD2CH4(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD2CH4_FC_DBGAUD2CH4)
#else
#define BF_HDMI_FC_DBGAUD2CH4_FC_DBGAUD2CH4(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD2CH4_FC_DBGAUD2CH4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD2CH4 field to a new value.
#define BW_HDMI_FC_DBGAUD2CH4_FC_DBGAUD2CH4(v)   BF_CS1(HDMI_FC_DBGAUD2CH4, FC_DBGAUD2CH4, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD0CH5 - Frame Composer Audio Channel 5 Register 0 (RW)
 *
 * Configures the audio fixed data to be used in channel 0 when in fixed audio selection.   Address
 * Offset: 0x1210  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD0CH5 : 8; //!< the audio fixed data byte0 to be used in channel 5 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud0ch5_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD0CH5 register
 */
#define HW_HDMI_FC_DBGAUD0CH5_ADDR      (REGS_HDMI_BASE + 0x1210)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD0CH5           (*(volatile hw_hdmi_fc_dbgaud0ch5_t *) HW_HDMI_FC_DBGAUD0CH5_ADDR)
#define HW_HDMI_FC_DBGAUD0CH5_RD()      (HW_HDMI_FC_DBGAUD0CH5.U)
#define HW_HDMI_FC_DBGAUD0CH5_WR(v)     (HW_HDMI_FC_DBGAUD0CH5.U = (v))
#define HW_HDMI_FC_DBGAUD0CH5_SET(v)    (HW_HDMI_FC_DBGAUD0CH5_WR(HW_HDMI_FC_DBGAUD0CH5_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD0CH5_CLR(v)    (HW_HDMI_FC_DBGAUD0CH5_WR(HW_HDMI_FC_DBGAUD0CH5_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD0CH5_TOG(v)    (HW_HDMI_FC_DBGAUD0CH5_WR(HW_HDMI_FC_DBGAUD0CH5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD0CH5 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD0CH5, field FC_DBGAUD0CH5 (RW)
 *
 * the audio fixed data byte0 to be used in channel 5 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD0CH5_FC_DBGAUD0CH5      0
#define BM_HDMI_FC_DBGAUD0CH5_FC_DBGAUD0CH5      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD0CH5_FC_DBGAUD0CH5(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD0CH5_FC_DBGAUD0CH5)
#else
#define BF_HDMI_FC_DBGAUD0CH5_FC_DBGAUD0CH5(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD0CH5_FC_DBGAUD0CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD0CH5 field to a new value.
#define BW_HDMI_FC_DBGAUD0CH5_FC_DBGAUD0CH5(v)   BF_CS1(HDMI_FC_DBGAUD0CH5, FC_DBGAUD0CH5, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD1CH5 - Frame Composer Audio Channel 5 Register 1 (RW)
 *
 * Address Offset: 0x1211  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD1CH5 : 8; //!< the audio fixed data byte1 to be used in channel 5 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud1ch5_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD1CH5 register
 */
#define HW_HDMI_FC_DBGAUD1CH5_ADDR      (REGS_HDMI_BASE + 0x1211)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD1CH5           (*(volatile hw_hdmi_fc_dbgaud1ch5_t *) HW_HDMI_FC_DBGAUD1CH5_ADDR)
#define HW_HDMI_FC_DBGAUD1CH5_RD()      (HW_HDMI_FC_DBGAUD1CH5.U)
#define HW_HDMI_FC_DBGAUD1CH5_WR(v)     (HW_HDMI_FC_DBGAUD1CH5.U = (v))
#define HW_HDMI_FC_DBGAUD1CH5_SET(v)    (HW_HDMI_FC_DBGAUD1CH5_WR(HW_HDMI_FC_DBGAUD1CH5_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD1CH5_CLR(v)    (HW_HDMI_FC_DBGAUD1CH5_WR(HW_HDMI_FC_DBGAUD1CH5_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD1CH5_TOG(v)    (HW_HDMI_FC_DBGAUD1CH5_WR(HW_HDMI_FC_DBGAUD1CH5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD1CH5 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD1CH5, field FC_DBGAUD1CH5 (RW)
 *
 * the audio fixed data byte1 to be used in channel 5 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD1CH5_FC_DBGAUD1CH5      0
#define BM_HDMI_FC_DBGAUD1CH5_FC_DBGAUD1CH5      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD1CH5_FC_DBGAUD1CH5(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD1CH5_FC_DBGAUD1CH5)
#else
#define BF_HDMI_FC_DBGAUD1CH5_FC_DBGAUD1CH5(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD1CH5_FC_DBGAUD1CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD1CH5 field to a new value.
#define BW_HDMI_FC_DBGAUD1CH5_FC_DBGAUD1CH5(v)   BF_CS1(HDMI_FC_DBGAUD1CH5, FC_DBGAUD1CH5, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD2CH5 - Frame Composer Audio Channel 5 Register 2 (RW)
 *
 * Address Offset: 0x1212  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD2CH5 : 8; //!< the audio fixed data byte2 to be used in channel 5 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud2ch5_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD2CH5 register
 */
#define HW_HDMI_FC_DBGAUD2CH5_ADDR      (REGS_HDMI_BASE + 0x1212)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD2CH5           (*(volatile hw_hdmi_fc_dbgaud2ch5_t *) HW_HDMI_FC_DBGAUD2CH5_ADDR)
#define HW_HDMI_FC_DBGAUD2CH5_RD()      (HW_HDMI_FC_DBGAUD2CH5.U)
#define HW_HDMI_FC_DBGAUD2CH5_WR(v)     (HW_HDMI_FC_DBGAUD2CH5.U = (v))
#define HW_HDMI_FC_DBGAUD2CH5_SET(v)    (HW_HDMI_FC_DBGAUD2CH5_WR(HW_HDMI_FC_DBGAUD2CH5_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD2CH5_CLR(v)    (HW_HDMI_FC_DBGAUD2CH5_WR(HW_HDMI_FC_DBGAUD2CH5_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD2CH5_TOG(v)    (HW_HDMI_FC_DBGAUD2CH5_WR(HW_HDMI_FC_DBGAUD2CH5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD2CH5 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD2CH5, field FC_DBGAUD2CH5 (RW)
 *
 * the audio fixed data byte2 to be used in channel 5 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD2CH5_FC_DBGAUD2CH5      0
#define BM_HDMI_FC_DBGAUD2CH5_FC_DBGAUD2CH5      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD2CH5_FC_DBGAUD2CH5(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD2CH5_FC_DBGAUD2CH5)
#else
#define BF_HDMI_FC_DBGAUD2CH5_FC_DBGAUD2CH5(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD2CH5_FC_DBGAUD2CH5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD2CH5 field to a new value.
#define BW_HDMI_FC_DBGAUD2CH5_FC_DBGAUD2CH5(v)   BF_CS1(HDMI_FC_DBGAUD2CH5, FC_DBGAUD2CH5, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD0CH6 - Frame Composer Audio Channel 6 Register 0 (RW)
 *
 * Configures the audio fixed data to be used in channel 0 when in fixed audio selection.   Address
 * Offset: 0x1213  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD0CH6 : 8; //!< The audio fixed data byte0 to be used in channel 6 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud0ch6_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD0CH6 register
 */
#define HW_HDMI_FC_DBGAUD0CH6_ADDR      (REGS_HDMI_BASE + 0x1213)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD0CH6           (*(volatile hw_hdmi_fc_dbgaud0ch6_t *) HW_HDMI_FC_DBGAUD0CH6_ADDR)
#define HW_HDMI_FC_DBGAUD0CH6_RD()      (HW_HDMI_FC_DBGAUD0CH6.U)
#define HW_HDMI_FC_DBGAUD0CH6_WR(v)     (HW_HDMI_FC_DBGAUD0CH6.U = (v))
#define HW_HDMI_FC_DBGAUD0CH6_SET(v)    (HW_HDMI_FC_DBGAUD0CH6_WR(HW_HDMI_FC_DBGAUD0CH6_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD0CH6_CLR(v)    (HW_HDMI_FC_DBGAUD0CH6_WR(HW_HDMI_FC_DBGAUD0CH6_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD0CH6_TOG(v)    (HW_HDMI_FC_DBGAUD0CH6_WR(HW_HDMI_FC_DBGAUD0CH6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD0CH6 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD0CH6, field FC_DBGAUD0CH6 (RW)
 *
 * The audio fixed data byte0 to be used in channel 6 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD0CH6_FC_DBGAUD0CH6      0
#define BM_HDMI_FC_DBGAUD0CH6_FC_DBGAUD0CH6      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD0CH6_FC_DBGAUD0CH6(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD0CH6_FC_DBGAUD0CH6)
#else
#define BF_HDMI_FC_DBGAUD0CH6_FC_DBGAUD0CH6(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD0CH6_FC_DBGAUD0CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD0CH6 field to a new value.
#define BW_HDMI_FC_DBGAUD0CH6_FC_DBGAUD0CH6(v)   BF_CS1(HDMI_FC_DBGAUD0CH6, FC_DBGAUD0CH6, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD1CH6 - Frame Composer Audio Channel 6 Register 1 (RW)
 *
 * Address Offset: 0x1214  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD1CH6 : 8; //!< the audio fixed data byte1 to be used in channel 6 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud1ch6_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD1CH6 register
 */
#define HW_HDMI_FC_DBGAUD1CH6_ADDR      (REGS_HDMI_BASE + 0x1214)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD1CH6           (*(volatile hw_hdmi_fc_dbgaud1ch6_t *) HW_HDMI_FC_DBGAUD1CH6_ADDR)
#define HW_HDMI_FC_DBGAUD1CH6_RD()      (HW_HDMI_FC_DBGAUD1CH6.U)
#define HW_HDMI_FC_DBGAUD1CH6_WR(v)     (HW_HDMI_FC_DBGAUD1CH6.U = (v))
#define HW_HDMI_FC_DBGAUD1CH6_SET(v)    (HW_HDMI_FC_DBGAUD1CH6_WR(HW_HDMI_FC_DBGAUD1CH6_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD1CH6_CLR(v)    (HW_HDMI_FC_DBGAUD1CH6_WR(HW_HDMI_FC_DBGAUD1CH6_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD1CH6_TOG(v)    (HW_HDMI_FC_DBGAUD1CH6_WR(HW_HDMI_FC_DBGAUD1CH6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD1CH6 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD1CH6, field FC_DBGAUD1CH6 (RW)
 *
 * the audio fixed data byte1 to be used in channel 6 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD1CH6_FC_DBGAUD1CH6      0
#define BM_HDMI_FC_DBGAUD1CH6_FC_DBGAUD1CH6      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD1CH6_FC_DBGAUD1CH6(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD1CH6_FC_DBGAUD1CH6)
#else
#define BF_HDMI_FC_DBGAUD1CH6_FC_DBGAUD1CH6(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD1CH6_FC_DBGAUD1CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD1CH6 field to a new value.
#define BW_HDMI_FC_DBGAUD1CH6_FC_DBGAUD1CH6(v)   BF_CS1(HDMI_FC_DBGAUD1CH6, FC_DBGAUD1CH6, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD2CH6 - Frame Composer Audio Channel 6 Register 2 (RW)
 *
 * Address Offset: 0x1215  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD2CH6 : 8; //!< the audio fixed data byte2 to be used in channel 6 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud2ch6_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD2CH6 register
 */
#define HW_HDMI_FC_DBGAUD2CH6_ADDR      (REGS_HDMI_BASE + 0x1215)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD2CH6           (*(volatile hw_hdmi_fc_dbgaud2ch6_t *) HW_HDMI_FC_DBGAUD2CH6_ADDR)
#define HW_HDMI_FC_DBGAUD2CH6_RD()      (HW_HDMI_FC_DBGAUD2CH6.U)
#define HW_HDMI_FC_DBGAUD2CH6_WR(v)     (HW_HDMI_FC_DBGAUD2CH6.U = (v))
#define HW_HDMI_FC_DBGAUD2CH6_SET(v)    (HW_HDMI_FC_DBGAUD2CH6_WR(HW_HDMI_FC_DBGAUD2CH6_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD2CH6_CLR(v)    (HW_HDMI_FC_DBGAUD2CH6_WR(HW_HDMI_FC_DBGAUD2CH6_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD2CH6_TOG(v)    (HW_HDMI_FC_DBGAUD2CH6_WR(HW_HDMI_FC_DBGAUD2CH6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD2CH6 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD2CH6, field FC_DBGAUD2CH6 (RW)
 *
 * the audio fixed data byte2 to be used in channel 6 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD2CH6_FC_DBGAUD2CH6      0
#define BM_HDMI_FC_DBGAUD2CH6_FC_DBGAUD2CH6      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD2CH6_FC_DBGAUD2CH6(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD2CH6_FC_DBGAUD2CH6)
#else
#define BF_HDMI_FC_DBGAUD2CH6_FC_DBGAUD2CH6(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD2CH6_FC_DBGAUD2CH6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD2CH6 field to a new value.
#define BW_HDMI_FC_DBGAUD2CH6_FC_DBGAUD2CH6(v)   BF_CS1(HDMI_FC_DBGAUD2CH6, FC_DBGAUD2CH6, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD0CH7 - Frame Composer Audio Channel 7 Register 1 (RW)
 *
 * Configures the audio fixed data to be used in channel 7 when in fixed audio selection.   Address
 * Offset: 0x1216  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD0CH7 : 8; //!< the audio fixed data byte0 to be used in channel 7 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud0ch7_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD0CH7 register
 */
#define HW_HDMI_FC_DBGAUD0CH7_ADDR      (REGS_HDMI_BASE + 0x1216)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD0CH7           (*(volatile hw_hdmi_fc_dbgaud0ch7_t *) HW_HDMI_FC_DBGAUD0CH7_ADDR)
#define HW_HDMI_FC_DBGAUD0CH7_RD()      (HW_HDMI_FC_DBGAUD0CH7.U)
#define HW_HDMI_FC_DBGAUD0CH7_WR(v)     (HW_HDMI_FC_DBGAUD0CH7.U = (v))
#define HW_HDMI_FC_DBGAUD0CH7_SET(v)    (HW_HDMI_FC_DBGAUD0CH7_WR(HW_HDMI_FC_DBGAUD0CH7_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD0CH7_CLR(v)    (HW_HDMI_FC_DBGAUD0CH7_WR(HW_HDMI_FC_DBGAUD0CH7_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD0CH7_TOG(v)    (HW_HDMI_FC_DBGAUD0CH7_WR(HW_HDMI_FC_DBGAUD0CH7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD0CH7 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD0CH7, field FC_DBGAUD0CH7 (RW)
 *
 * the audio fixed data byte0 to be used in channel 7 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD0CH7_FC_DBGAUD0CH7      0
#define BM_HDMI_FC_DBGAUD0CH7_FC_DBGAUD0CH7      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD0CH7_FC_DBGAUD0CH7(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD0CH7_FC_DBGAUD0CH7)
#else
#define BF_HDMI_FC_DBGAUD0CH7_FC_DBGAUD0CH7(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD0CH7_FC_DBGAUD0CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD0CH7 field to a new value.
#define BW_HDMI_FC_DBGAUD0CH7_FC_DBGAUD0CH7(v)   BF_CS1(HDMI_FC_DBGAUD0CH7, FC_DBGAUD0CH7, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD1CH7 - Frame Composer Audio Channel 7 Register 0 (RW)
 *
 * Address Offset: 0x1217  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD1CH7 : 8; //!< the audio fixed data byte1 to be used in channel 0 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud1ch7_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD1CH7 register
 */
#define HW_HDMI_FC_DBGAUD1CH7_ADDR      (REGS_HDMI_BASE + 0x1217)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD1CH7           (*(volatile hw_hdmi_fc_dbgaud1ch7_t *) HW_HDMI_FC_DBGAUD1CH7_ADDR)
#define HW_HDMI_FC_DBGAUD1CH7_RD()      (HW_HDMI_FC_DBGAUD1CH7.U)
#define HW_HDMI_FC_DBGAUD1CH7_WR(v)     (HW_HDMI_FC_DBGAUD1CH7.U = (v))
#define HW_HDMI_FC_DBGAUD1CH7_SET(v)    (HW_HDMI_FC_DBGAUD1CH7_WR(HW_HDMI_FC_DBGAUD1CH7_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD1CH7_CLR(v)    (HW_HDMI_FC_DBGAUD1CH7_WR(HW_HDMI_FC_DBGAUD1CH7_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD1CH7_TOG(v)    (HW_HDMI_FC_DBGAUD1CH7_WR(HW_HDMI_FC_DBGAUD1CH7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD1CH7 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD1CH7, field FC_DBGAUD1CH7 (RW)
 *
 * the audio fixed data byte1 to be used in channel 0 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD1CH7_FC_DBGAUD1CH7      0
#define BM_HDMI_FC_DBGAUD1CH7_FC_DBGAUD1CH7      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD1CH7_FC_DBGAUD1CH7(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD1CH7_FC_DBGAUD1CH7)
#else
#define BF_HDMI_FC_DBGAUD1CH7_FC_DBGAUD1CH7(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD1CH7_FC_DBGAUD1CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD1CH7 field to a new value.
#define BW_HDMI_FC_DBGAUD1CH7_FC_DBGAUD1CH7(v)   BF_CS1(HDMI_FC_DBGAUD1CH7, FC_DBGAUD1CH7, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGAUD2CH7 - Frame Composer Audio Channel 7 Register 2 (RW)
 *
 * Address Offset: 0x1218  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGAUD2CH7 : 8; //!< the audio fixed data byte2 to be used in channel 0 when in fixed audio selection
    } B;
} hw_hdmi_fc_dbgaud2ch7_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGAUD2CH7 register
 */
#define HW_HDMI_FC_DBGAUD2CH7_ADDR      (REGS_HDMI_BASE + 0x1218)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGAUD2CH7           (*(volatile hw_hdmi_fc_dbgaud2ch7_t *) HW_HDMI_FC_DBGAUD2CH7_ADDR)
#define HW_HDMI_FC_DBGAUD2CH7_RD()      (HW_HDMI_FC_DBGAUD2CH7.U)
#define HW_HDMI_FC_DBGAUD2CH7_WR(v)     (HW_HDMI_FC_DBGAUD2CH7.U = (v))
#define HW_HDMI_FC_DBGAUD2CH7_SET(v)    (HW_HDMI_FC_DBGAUD2CH7_WR(HW_HDMI_FC_DBGAUD2CH7_RD() |  (v)))
#define HW_HDMI_FC_DBGAUD2CH7_CLR(v)    (HW_HDMI_FC_DBGAUD2CH7_WR(HW_HDMI_FC_DBGAUD2CH7_RD() & ~(v)))
#define HW_HDMI_FC_DBGAUD2CH7_TOG(v)    (HW_HDMI_FC_DBGAUD2CH7_WR(HW_HDMI_FC_DBGAUD2CH7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGAUD2CH7 bitfields
 */

/* --- Register HW_HDMI_FC_DBGAUD2CH7, field FC_DBGAUD2CH7 (RW)
 *
 * the audio fixed data byte2 to be used in channel 0 when in fixed audio selection
 */

#define BP_HDMI_FC_DBGAUD2CH7_FC_DBGAUD2CH7      0
#define BM_HDMI_FC_DBGAUD2CH7_FC_DBGAUD2CH7      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGAUD2CH7_FC_DBGAUD2CH7(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGAUD2CH7_FC_DBGAUD2CH7)
#else
#define BF_HDMI_FC_DBGAUD2CH7_FC_DBGAUD2CH7(v)   (((v) << 0) & BM_HDMI_FC_DBGAUD2CH7_FC_DBGAUD2CH7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGAUD2CH7 field to a new value.
#define BW_HDMI_FC_DBGAUD2CH7_FC_DBGAUD2CH7(v)   BF_CS1(HDMI_FC_DBGAUD2CH7, FC_DBGAUD2CH7, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGTMDS0 - Frame Composer TMDS Channel 0 Register (RW)
 *
 * Configures the video fixed data to be used in tmds channel 0 when in fixed video selection. This
 * equals to set B pixel component value in RGB video or Cb pixel component value in YCbCr.
 * Address Offset: 0x1219  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGTMDS0 : 8; //!< set B pixel component value in RGB video or Cb pixel component value in YCbCr
    } B;
} hw_hdmi_fc_dbgtmds0_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGTMDS0 register
 */
#define HW_HDMI_FC_DBGTMDS0_ADDR      (REGS_HDMI_BASE + 0x1219)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGTMDS0           (*(volatile hw_hdmi_fc_dbgtmds0_t *) HW_HDMI_FC_DBGTMDS0_ADDR)
#define HW_HDMI_FC_DBGTMDS0_RD()      (HW_HDMI_FC_DBGTMDS0.U)
#define HW_HDMI_FC_DBGTMDS0_WR(v)     (HW_HDMI_FC_DBGTMDS0.U = (v))
#define HW_HDMI_FC_DBGTMDS0_SET(v)    (HW_HDMI_FC_DBGTMDS0_WR(HW_HDMI_FC_DBGTMDS0_RD() |  (v)))
#define HW_HDMI_FC_DBGTMDS0_CLR(v)    (HW_HDMI_FC_DBGTMDS0_WR(HW_HDMI_FC_DBGTMDS0_RD() & ~(v)))
#define HW_HDMI_FC_DBGTMDS0_TOG(v)    (HW_HDMI_FC_DBGTMDS0_WR(HW_HDMI_FC_DBGTMDS0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGTMDS0 bitfields
 */

/* --- Register HW_HDMI_FC_DBGTMDS0, field FC_DBGTMDS0 (RW)
 *
 * set B pixel component value in RGB video or Cb pixel component value in YCbCr
 */

#define BP_HDMI_FC_DBGTMDS0_FC_DBGTMDS0      0
#define BM_HDMI_FC_DBGTMDS0_FC_DBGTMDS0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGTMDS0_FC_DBGTMDS0(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGTMDS0_FC_DBGTMDS0)
#else
#define BF_HDMI_FC_DBGTMDS0_FC_DBGTMDS0(v)   (((v) << 0) & BM_HDMI_FC_DBGTMDS0_FC_DBGTMDS0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGTMDS0 field to a new value.
#define BW_HDMI_FC_DBGTMDS0_FC_DBGTMDS0(v)   BF_CS1(HDMI_FC_DBGTMDS0, FC_DBGTMDS0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGTMDS1 - Frame Composer TMDS Channel 1 Register (RW)
 *
 * Configures the video fixed data to be used in tmds channel 1 when in fixed video selection. This
 * equals to set G pixel component value in RGB video or Y pixel component value in YCbCr.   Address
 * Offset: 0x121A  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGTMDS1 : 8; //!< set G pixel component value in RGB video or Y pixel component value in YCbCr
    } B;
} hw_hdmi_fc_dbgtmds1_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGTMDS1 register
 */
#define HW_HDMI_FC_DBGTMDS1_ADDR      (REGS_HDMI_BASE + 0x121a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGTMDS1           (*(volatile hw_hdmi_fc_dbgtmds1_t *) HW_HDMI_FC_DBGTMDS1_ADDR)
#define HW_HDMI_FC_DBGTMDS1_RD()      (HW_HDMI_FC_DBGTMDS1.U)
#define HW_HDMI_FC_DBGTMDS1_WR(v)     (HW_HDMI_FC_DBGTMDS1.U = (v))
#define HW_HDMI_FC_DBGTMDS1_SET(v)    (HW_HDMI_FC_DBGTMDS1_WR(HW_HDMI_FC_DBGTMDS1_RD() |  (v)))
#define HW_HDMI_FC_DBGTMDS1_CLR(v)    (HW_HDMI_FC_DBGTMDS1_WR(HW_HDMI_FC_DBGTMDS1_RD() & ~(v)))
#define HW_HDMI_FC_DBGTMDS1_TOG(v)    (HW_HDMI_FC_DBGTMDS1_WR(HW_HDMI_FC_DBGTMDS1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGTMDS1 bitfields
 */

/* --- Register HW_HDMI_FC_DBGTMDS1, field FC_DBGTMDS1 (RW)
 *
 * set G pixel component value in RGB video or Y pixel component value in YCbCr
 */

#define BP_HDMI_FC_DBGTMDS1_FC_DBGTMDS1      0
#define BM_HDMI_FC_DBGTMDS1_FC_DBGTMDS1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGTMDS1_FC_DBGTMDS1(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGTMDS1_FC_DBGTMDS1)
#else
#define BF_HDMI_FC_DBGTMDS1_FC_DBGTMDS1(v)   (((v) << 0) & BM_HDMI_FC_DBGTMDS1_FC_DBGTMDS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGTMDS1 field to a new value.
#define BW_HDMI_FC_DBGTMDS1_FC_DBGTMDS1(v)   BF_CS1(HDMI_FC_DBGTMDS1, FC_DBGTMDS1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_FC_DBGTMDS2 - Frame Composer TMDS Channel 2 Register (RW)
 *
 * Configures the video fixed data to be used in tmds channel 2 when in fixed video selection. This
 * equals to set R pixel component value in RGB video or Cr pixel component value in YCbCr.
 * Address Offset: 0x121B  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FC_DBGTMDS2 : 8; //!< set R pixel component value in RGB video or Cr pixel component value in YCbCr
    } B;
} hw_hdmi_fc_dbgtmds2_t;
#endif

/*
 * constants & macros for entire HDMI_FC_DBGTMDS2 register
 */
#define HW_HDMI_FC_DBGTMDS2_ADDR      (REGS_HDMI_BASE + 0x121b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_FC_DBGTMDS2           (*(volatile hw_hdmi_fc_dbgtmds2_t *) HW_HDMI_FC_DBGTMDS2_ADDR)
#define HW_HDMI_FC_DBGTMDS2_RD()      (HW_HDMI_FC_DBGTMDS2.U)
#define HW_HDMI_FC_DBGTMDS2_WR(v)     (HW_HDMI_FC_DBGTMDS2.U = (v))
#define HW_HDMI_FC_DBGTMDS2_SET(v)    (HW_HDMI_FC_DBGTMDS2_WR(HW_HDMI_FC_DBGTMDS2_RD() |  (v)))
#define HW_HDMI_FC_DBGTMDS2_CLR(v)    (HW_HDMI_FC_DBGTMDS2_WR(HW_HDMI_FC_DBGTMDS2_RD() & ~(v)))
#define HW_HDMI_FC_DBGTMDS2_TOG(v)    (HW_HDMI_FC_DBGTMDS2_WR(HW_HDMI_FC_DBGTMDS2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_FC_DBGTMDS2 bitfields
 */

/* --- Register HW_HDMI_FC_DBGTMDS2, field FC_DBGTMDS2 (RW)
 *
 * set R pixel component value in RGB video or Cr pixel component value in YCbCr
 */

#define BP_HDMI_FC_DBGTMDS2_FC_DBGTMDS2      0
#define BM_HDMI_FC_DBGTMDS2_FC_DBGTMDS2      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_FC_DBGTMDS2_FC_DBGTMDS2(v)   ((((reg32_t) v) << 0) & BM_HDMI_FC_DBGTMDS2_FC_DBGTMDS2)
#else
#define BF_HDMI_FC_DBGTMDS2_FC_DBGTMDS2(v)   (((v) << 0) & BM_HDMI_FC_DBGTMDS2_FC_DBGTMDS2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FC_DBGTMDS2 field to a new value.
#define BW_HDMI_FC_DBGTMDS2_FC_DBGTMDS2(v)   BF_CS1(HDMI_FC_DBGTMDS2, FC_DBGTMDS2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_CONF0 - PHY Configuration Register (RW)
 *
 * This register holds the power down, data enable polarity and interface control of the HDMI Source
 * PHY control. For more information, refer to the DesignWare Cores HDMI TX PHY Databook.   Address
 * Offset: 0x3000  Size: 8 bits  Value after Reset: 0x06  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char SELDIPIF : 1; //!< Select interface control. Value after Reset: 0b
        unsigned char SELDATAENPOL : 1; //!< Select data enable polarity. Value after Reset: 1b
        unsigned char GEN2_ENHPDRXSENSE : 1; //!< PHY_Gen2 ENHPDRXSENSE signal Value after Reset: 1b
        unsigned char GEN2_TXPWRON : 1; //!< PHY_Gen2 TXPWRON signal Value after Reset: 0b
        unsigned char GEN2_PDDQ : 1; //!< PHY_Gen2 PDDQ signal Value after Reset: 0b
        unsigned char SPARECTRL : 1; //!< Reserved. Spare pin control. Value after Reset: 0b
        unsigned char ENTMDS : 1; //!< Enable TMDS drivers, bias, and TMDS digital logic. Value after Reset: 0b
        unsigned char PDZ : 1; //!< Power-down enable (active low 0b). Value after Reset: 0b
    } B;
} hw_hdmi_phy_conf0_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_CONF0 register
 */
#define HW_HDMI_PHY_CONF0_ADDR      (REGS_HDMI_BASE + 0x3000)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_CONF0           (*(volatile hw_hdmi_phy_conf0_t *) HW_HDMI_PHY_CONF0_ADDR)
#define HW_HDMI_PHY_CONF0_RD()      (HW_HDMI_PHY_CONF0.U)
#define HW_HDMI_PHY_CONF0_WR(v)     (HW_HDMI_PHY_CONF0.U = (v))
#define HW_HDMI_PHY_CONF0_SET(v)    (HW_HDMI_PHY_CONF0_WR(HW_HDMI_PHY_CONF0_RD() |  (v)))
#define HW_HDMI_PHY_CONF0_CLR(v)    (HW_HDMI_PHY_CONF0_WR(HW_HDMI_PHY_CONF0_RD() & ~(v)))
#define HW_HDMI_PHY_CONF0_TOG(v)    (HW_HDMI_PHY_CONF0_WR(HW_HDMI_PHY_CONF0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_CONF0 bitfields
 */

/* --- Register HW_HDMI_PHY_CONF0, field SELDIPIF (RW)
 *
 * Select interface control. Value after Reset: 0b
 */

#define BP_HDMI_PHY_CONF0_SELDIPIF      0
#define BM_HDMI_PHY_CONF0_SELDIPIF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CONF0_SELDIPIF(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_CONF0_SELDIPIF)
#else
#define BF_HDMI_PHY_CONF0_SELDIPIF(v)   (((v) << 0) & BM_HDMI_PHY_CONF0_SELDIPIF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SELDIPIF field to a new value.
#define BW_HDMI_PHY_CONF0_SELDIPIF(v)   BF_CS1(HDMI_PHY_CONF0, SELDIPIF, v)
#endif

/* --- Register HW_HDMI_PHY_CONF0, field SELDATAENPOL (RW)
 *
 * Select data enable polarity. Value after Reset: 1b
 */

#define BP_HDMI_PHY_CONF0_SELDATAENPOL      1
#define BM_HDMI_PHY_CONF0_SELDATAENPOL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CONF0_SELDATAENPOL(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_CONF0_SELDATAENPOL)
#else
#define BF_HDMI_PHY_CONF0_SELDATAENPOL(v)   (((v) << 1) & BM_HDMI_PHY_CONF0_SELDATAENPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SELDATAENPOL field to a new value.
#define BW_HDMI_PHY_CONF0_SELDATAENPOL(v)   BF_CS1(HDMI_PHY_CONF0, SELDATAENPOL, v)
#endif

/* --- Register HW_HDMI_PHY_CONF0, field GEN2_ENHPDRXSENSE (RW)
 *
 * PHY_Gen2 ENHPDRXSENSE signal Value after Reset: 1b
 */

#define BP_HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE      2
#define BM_HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE)
#else
#define BF_HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE(v)   (((v) << 2) & BM_HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN2_ENHPDRXSENSE field to a new value.
#define BW_HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE(v)   BF_CS1(HDMI_PHY_CONF0, GEN2_ENHPDRXSENSE, v)
#endif

/* --- Register HW_HDMI_PHY_CONF0, field GEN2_TXPWRON (RW)
 *
 * PHY_Gen2 TXPWRON signal Value after Reset: 0b
 */

#define BP_HDMI_PHY_CONF0_GEN2_TXPWRON      3
#define BM_HDMI_PHY_CONF0_GEN2_TXPWRON      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CONF0_GEN2_TXPWRON(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_CONF0_GEN2_TXPWRON)
#else
#define BF_HDMI_PHY_CONF0_GEN2_TXPWRON(v)   (((v) << 3) & BM_HDMI_PHY_CONF0_GEN2_TXPWRON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN2_TXPWRON field to a new value.
#define BW_HDMI_PHY_CONF0_GEN2_TXPWRON(v)   BF_CS1(HDMI_PHY_CONF0, GEN2_TXPWRON, v)
#endif

/* --- Register HW_HDMI_PHY_CONF0, field GEN2_PDDQ (RW)
 *
 * PHY_Gen2 PDDQ signal Value after Reset: 0b
 */

#define BP_HDMI_PHY_CONF0_GEN2_PDDQ      4
#define BM_HDMI_PHY_CONF0_GEN2_PDDQ      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CONF0_GEN2_PDDQ(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_CONF0_GEN2_PDDQ)
#else
#define BF_HDMI_PHY_CONF0_GEN2_PDDQ(v)   (((v) << 4) & BM_HDMI_PHY_CONF0_GEN2_PDDQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN2_PDDQ field to a new value.
#define BW_HDMI_PHY_CONF0_GEN2_PDDQ(v)   BF_CS1(HDMI_PHY_CONF0, GEN2_PDDQ, v)
#endif

/* --- Register HW_HDMI_PHY_CONF0, field SPARECTRL (RW)
 *
 * Reserved. Spare pin control. Value after Reset: 0b
 */

#define BP_HDMI_PHY_CONF0_SPARECTRL      5
#define BM_HDMI_PHY_CONF0_SPARECTRL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CONF0_SPARECTRL(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_CONF0_SPARECTRL)
#else
#define BF_HDMI_PHY_CONF0_SPARECTRL(v)   (((v) << 5) & BM_HDMI_PHY_CONF0_SPARECTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SPARECTRL field to a new value.
#define BW_HDMI_PHY_CONF0_SPARECTRL(v)   BF_CS1(HDMI_PHY_CONF0, SPARECTRL, v)
#endif

/* --- Register HW_HDMI_PHY_CONF0, field ENTMDS (RW)
 *
 * Enable TMDS drivers, bias, and TMDS digital logic. Value after Reset: 0b
 */

#define BP_HDMI_PHY_CONF0_ENTMDS      6
#define BM_HDMI_PHY_CONF0_ENTMDS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CONF0_ENTMDS(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_CONF0_ENTMDS)
#else
#define BF_HDMI_PHY_CONF0_ENTMDS(v)   (((v) << 6) & BM_HDMI_PHY_CONF0_ENTMDS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTMDS field to a new value.
#define BW_HDMI_PHY_CONF0_ENTMDS(v)   BF_CS1(HDMI_PHY_CONF0, ENTMDS, v)
#endif

/* --- Register HW_HDMI_PHY_CONF0, field PDZ (RW)
 *
 * Power-down enable (active low 0b). Value after Reset: 0b
 */

#define BP_HDMI_PHY_CONF0_PDZ      7
#define BM_HDMI_PHY_CONF0_PDZ      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_CONF0_PDZ(v)   ((((reg32_t) v) << 7) & BM_HDMI_PHY_CONF0_PDZ)
#else
#define BF_HDMI_PHY_CONF0_PDZ(v)   (((v) << 7) & BM_HDMI_PHY_CONF0_PDZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PDZ field to a new value.
#define BW_HDMI_PHY_CONF0_PDZ(v)   BF_CS1(HDMI_PHY_CONF0, PDZ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_TST0 - PHY Test Interface Register 0 (RW)
 *
 * PHY TX mapped text interface (control). For more information, refer to the DesignWare Cores HDMI
 * TX PHY Databook.   Address Offset: 0x3001  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char TESTCLK : 1; //!< Test clock signal. Value after Reset: 0b
        unsigned char RESERVED0 : 3; //!< Reserved
        unsigned char TESTEN : 1; //!< Reserved. Spare control pins. Value after Reset: 0b
        unsigned char TESTCLR : 1; //!< Enable TMDS drivers, bias and tmds digital logic. Value after Reset: 0b
        unsigned char RESERVED1 : 2; //!< Reserved
    } B;
} hw_hdmi_phy_tst0_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TST0 register
 */
#define HW_HDMI_PHY_TST0_ADDR      (REGS_HDMI_BASE + 0x3001)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TST0           (*(volatile hw_hdmi_phy_tst0_t *) HW_HDMI_PHY_TST0_ADDR)
#define HW_HDMI_PHY_TST0_RD()      (HW_HDMI_PHY_TST0.U)
#define HW_HDMI_PHY_TST0_WR(v)     (HW_HDMI_PHY_TST0.U = (v))
#define HW_HDMI_PHY_TST0_SET(v)    (HW_HDMI_PHY_TST0_WR(HW_HDMI_PHY_TST0_RD() |  (v)))
#define HW_HDMI_PHY_TST0_CLR(v)    (HW_HDMI_PHY_TST0_WR(HW_HDMI_PHY_TST0_RD() & ~(v)))
#define HW_HDMI_PHY_TST0_TOG(v)    (HW_HDMI_PHY_TST0_WR(HW_HDMI_PHY_TST0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_TST0 bitfields
 */

/* --- Register HW_HDMI_PHY_TST0, field TESTCLK (RW)
 *
 * Test clock signal. Value after Reset: 0b
 */

#define BP_HDMI_PHY_TST0_TESTCLK      0
#define BM_HDMI_PHY_TST0_TESTCLK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TST0_TESTCLK(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_TST0_TESTCLK)
#else
#define BF_HDMI_PHY_TST0_TESTCLK(v)   (((v) << 0) & BM_HDMI_PHY_TST0_TESTCLK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TESTCLK field to a new value.
#define BW_HDMI_PHY_TST0_TESTCLK(v)   BF_CS1(HDMI_PHY_TST0, TESTCLK, v)
#endif

/* --- Register HW_HDMI_PHY_TST0, field TESTEN (RW)
 *
 * Reserved. Spare control pins. Value after Reset: 0b
 */

#define BP_HDMI_PHY_TST0_TESTEN      4
#define BM_HDMI_PHY_TST0_TESTEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TST0_TESTEN(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_TST0_TESTEN)
#else
#define BF_HDMI_PHY_TST0_TESTEN(v)   (((v) << 4) & BM_HDMI_PHY_TST0_TESTEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TESTEN field to a new value.
#define BW_HDMI_PHY_TST0_TESTEN(v)   BF_CS1(HDMI_PHY_TST0, TESTEN, v)
#endif

/* --- Register HW_HDMI_PHY_TST0, field TESTCLR (RW)
 *
 * Enable TMDS drivers, bias and tmds digital logic. Value after Reset: 0b
 */

#define BP_HDMI_PHY_TST0_TESTCLR      5
#define BM_HDMI_PHY_TST0_TESTCLR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TST0_TESTCLR(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_TST0_TESTCLR)
#else
#define BF_HDMI_PHY_TST0_TESTCLR(v)   (((v) << 5) & BM_HDMI_PHY_TST0_TESTCLR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TESTCLR field to a new value.
#define BW_HDMI_PHY_TST0_TESTCLR(v)   BF_CS1(HDMI_PHY_TST0, TESTCLR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_TST1 - PHY Test Interface Register 1 (RW)
 *
 * PHY TX mapped text interface (data in). For more information, refer to the DesignWare Cores HDMI
 * TX PHY Databook.   Address Offset: 0x3002  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char TESTDIN : 8; //!< Test data input.
    } B;
} hw_hdmi_phy_tst1_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TST1 register
 */
#define HW_HDMI_PHY_TST1_ADDR      (REGS_HDMI_BASE + 0x3002)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TST1           (*(volatile hw_hdmi_phy_tst1_t *) HW_HDMI_PHY_TST1_ADDR)
#define HW_HDMI_PHY_TST1_RD()      (HW_HDMI_PHY_TST1.U)
#define HW_HDMI_PHY_TST1_WR(v)     (HW_HDMI_PHY_TST1.U = (v))
#define HW_HDMI_PHY_TST1_SET(v)    (HW_HDMI_PHY_TST1_WR(HW_HDMI_PHY_TST1_RD() |  (v)))
#define HW_HDMI_PHY_TST1_CLR(v)    (HW_HDMI_PHY_TST1_WR(HW_HDMI_PHY_TST1_RD() & ~(v)))
#define HW_HDMI_PHY_TST1_TOG(v)    (HW_HDMI_PHY_TST1_WR(HW_HDMI_PHY_TST1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_TST1 bitfields
 */

/* --- Register HW_HDMI_PHY_TST1, field TESTDIN (RW)
 *
 * Test data input.
 */

#define BP_HDMI_PHY_TST1_TESTDIN      0
#define BM_HDMI_PHY_TST1_TESTDIN      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_TST1_TESTDIN(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_TST1_TESTDIN)
#else
#define BF_HDMI_PHY_TST1_TESTDIN(v)   (((v) << 0) & BM_HDMI_PHY_TST1_TESTDIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TESTDIN field to a new value.
#define BW_HDMI_PHY_TST1_TESTDIN(v)   BF_CS1(HDMI_PHY_TST1, TESTDIN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_TST2 - PHY Test Interface Register 2 (RO)
 *
 * PHY TX mapped text interface (data out). For more information, refer to the DesignWare Cores HDMI
 * TX PHY Databook.   Address Offset: 0x3003  Size: 8 bits  Value after Reset: N/A  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char TESTDOUT : 8; //!< Test data output.
    } B;
} hw_hdmi_phy_tst2_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_TST2 register
 */
#define HW_HDMI_PHY_TST2_ADDR      (REGS_HDMI_BASE + 0x3003)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_TST2           (*(volatile hw_hdmi_phy_tst2_t *) HW_HDMI_PHY_TST2_ADDR)
#define HW_HDMI_PHY_TST2_RD()      (HW_HDMI_PHY_TST2.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_TST2 bitfields
 */

/* --- Register HW_HDMI_PHY_TST2, field TESTDOUT (RO)
 *
 * Test data output.
 */

#define BP_HDMI_PHY_TST2_TESTDOUT      0
#define BM_HDMI_PHY_TST2_TESTDOUT      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_STAT0 - PHY RXSENSE, PLL lock, and HPD Status Register (RO)
 *
 * This register contains the following active high packet sent status indications. For more
 * information, see   Address Offset: 0x3004  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char TX_PHY_LOCK : 1; //!< Status bit. TX PHY PLL lock indication. Please refer to PHY datasheet for more information. User may need to mask or change polarity of this interrupt after it has became active.
        unsigned char HPD : 1; //!< Status bit. HDMI Hot Plug Detect indication. User may need to mask or change polarity of this interrupt after it has became active.
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char RX_SENSE : 1; //!< Status bit. TX PHY RX_SENSE indication for TMDS channel 0 driver. User may need to mask or change polarity of this interrupt after it has became active.
        unsigned char RX_SENSE1 : 1; //!< Status bit. TX PHY RX_SENSE indication for TMDS channel 1 driver. User may need to mask or change polarity of this interrupt after it has became active.
        unsigned char RX_SENSE2 : 1; //!< Status bit. TX PHY RX_SENSE indication for TMDS channel 2 driver. User may need to mask or change polarity of this interrupt after it has became active.
        unsigned char RX_SENSE3 : 1; //!< Status bit. TX PHY RX_SENSE indication for TMDS CLK driver. User may need to mask or change polarity of this interrupt after it has became active.
    } B;
} hw_hdmi_phy_stat0_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_STAT0 register
 */
#define HW_HDMI_PHY_STAT0_ADDR      (REGS_HDMI_BASE + 0x3004)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_STAT0           (*(volatile hw_hdmi_phy_stat0_t *) HW_HDMI_PHY_STAT0_ADDR)
#define HW_HDMI_PHY_STAT0_RD()      (HW_HDMI_PHY_STAT0.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_STAT0 bitfields
 */

/* --- Register HW_HDMI_PHY_STAT0, field TX_PHY_LOCK (RO)
 *
 * Status bit. TX PHY PLL lock indication. Please refer to PHY datasheet for more information. User
 * may need to mask or change polarity of this interrupt after it has became active.
 */

#define BP_HDMI_PHY_STAT0_TX_PHY_LOCK      0
#define BM_HDMI_PHY_STAT0_TX_PHY_LOCK      0x00000001

/* --- Register HW_HDMI_PHY_STAT0, field HPD (RO)
 *
 * Status bit. HDMI Hot Plug Detect indication. User may need to mask or change polarity of this
 * interrupt after it has became active.
 */

#define BP_HDMI_PHY_STAT0_HPD      1
#define BM_HDMI_PHY_STAT0_HPD      0x00000002

/* --- Register HW_HDMI_PHY_STAT0, field RX_SENSE (RO)
 *
 * Status bit. TX PHY RX_SENSE indication for TMDS channel 0 driver. User may need to mask or change
 * polarity of this interrupt after it has became active.
 */

#define BP_HDMI_PHY_STAT0_RX_SENSE      4
#define BM_HDMI_PHY_STAT0_RX_SENSE      0x00000010

/* --- Register HW_HDMI_PHY_STAT0, field RX_SENSE (RO)
 *
 * Status bit. TX PHY RX_SENSE indication for TMDS channel 1 driver. User may need to mask or change
 * polarity of this interrupt after it has became active.
 */

#define BP_HDMI_PHY_STAT0_RX_SENSE      5
#define BM_HDMI_PHY_STAT0_RX_SENSE      0x00000020

/* --- Register HW_HDMI_PHY_STAT0, field RX_SENSE (RO)
 *
 * Status bit. TX PHY RX_SENSE indication for TMDS channel 2 driver. User may need to mask or change
 * polarity of this interrupt after it has became active.
 */

#define BP_HDMI_PHY_STAT0_RX_SENSE      6
#define BM_HDMI_PHY_STAT0_RX_SENSE      0x00000040

/* --- Register HW_HDMI_PHY_STAT0, field RX_SENSE (RO)
 *
 * Status bit. TX PHY RX_SENSE indication for TMDS CLK driver. User may need to mask or change
 * polarity of this interrupt after it has became active.
 */

#define BP_HDMI_PHY_STAT0_RX_SENSE      7
#define BM_HDMI_PHY_STAT0_RX_SENSE      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_INT0 - PHY RXSENSE, PLL lock, and HPD Interrupt Register (RO)
 *
 * This register contains the interrupt indication of the PHY_STAT0 status interrupts. Interrupt
 * generation is accomplished in the following way:  interrupt = (mask == 1'b0) && (polarity ==
 * status);  All this interrupts are forwarded to the Interrupt Handler sticky bit registers and
 * after ORed to a single main interrupt line to micro controller. Assertion of this interrupt
 * implies that data related with the corresponding packet has been sent through the HDMI interface.
 * Address Offset: 0x3005  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char TX_PHY_LOCK : 1; //!< Interrupt indication bit TX PHY PLL lock indication interrupt.
        unsigned char HPD : 1; //!< Interrupt indication bit HDMI Hot Plug Detect indication interrupt.
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char RX_SENSE : 1; //!< Interrupt indication bit TX PHY RX_SENSE indication interrupt for TMDS channel 0 driver.
        unsigned char RX_SENSE1 : 1; //!< Interrupt indication bit TX PHY RX_SENSE indication interrupt for TMDS channel 1 driver.
        unsigned char RX_SENSE2 : 1; //!< Interrupt indication bit TX PHY RX_SENSE indication interrupt for TMDS channel 2 driver.
        unsigned char RX_SENSE3 : 1; //!< Interrupt indication bit TX PHY RX_SENSE indication interrupt for TMDS CLK driver.
    } B;
} hw_hdmi_phy_int0_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_INT0 register
 */
#define HW_HDMI_PHY_INT0_ADDR      (REGS_HDMI_BASE + 0x3005)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_INT0           (*(volatile hw_hdmi_phy_int0_t *) HW_HDMI_PHY_INT0_ADDR)
#define HW_HDMI_PHY_INT0_RD()      (HW_HDMI_PHY_INT0.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_INT0 bitfields
 */

/* --- Register HW_HDMI_PHY_INT0, field TX_PHY_LOCK (RO)
 *
 * Interrupt indication bit TX PHY PLL lock indication interrupt.
 */

#define BP_HDMI_PHY_INT0_TX_PHY_LOCK      0
#define BM_HDMI_PHY_INT0_TX_PHY_LOCK      0x00000001

/* --- Register HW_HDMI_PHY_INT0, field HPD (RO)
 *
 * Interrupt indication bit HDMI Hot Plug Detect indication interrupt.
 */

#define BP_HDMI_PHY_INT0_HPD      1
#define BM_HDMI_PHY_INT0_HPD      0x00000002

/* --- Register HW_HDMI_PHY_INT0, field RX_SENSE (RO)
 *
 * Interrupt indication bit TX PHY RX_SENSE indication interrupt for TMDS channel 0 driver.
 */

#define BP_HDMI_PHY_INT0_RX_SENSE      4
#define BM_HDMI_PHY_INT0_RX_SENSE      0x00000010

/* --- Register HW_HDMI_PHY_INT0, field RX_SENSE (RO)
 *
 * Interrupt indication bit TX PHY RX_SENSE indication interrupt for TMDS channel 1 driver.
 */

#define BP_HDMI_PHY_INT0_RX_SENSE      5
#define BM_HDMI_PHY_INT0_RX_SENSE      0x00000020

/* --- Register HW_HDMI_PHY_INT0, field RX_SENSE (RO)
 *
 * Interrupt indication bit TX PHY RX_SENSE indication interrupt for TMDS channel 2 driver.
 */

#define BP_HDMI_PHY_INT0_RX_SENSE      6
#define BM_HDMI_PHY_INT0_RX_SENSE      0x00000040

/* --- Register HW_HDMI_PHY_INT0, field RX_SENSE (RO)
 *
 * Interrupt indication bit TX PHY RX_SENSE indication interrupt for TMDS CLK driver.
 */

#define BP_HDMI_PHY_INT0_RX_SENSE      7
#define BM_HDMI_PHY_INT0_RX_SENSE      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_MASK0 - PHY RXSENSE, PLL lock, and HPD Mask Register (RW)
 *
 * Mask register for generation of PHY_INT0 interrupts.   Address Offset: 0x3006  Size: 8 bits
 * Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char TX_PHY_LOCK : 1; //!< Mask bit for PHY_INT0.TX_PHY_LOCK interrupt bit
        unsigned char HPD : 1; //!< Mask bit for PHY_INT0.HPD interrupt bit
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char RX_SENSE : 1; //!< Mask bit for PHY_INT0.RX_SENSE[0] interrupt bit
        unsigned char RX_SENSE1 : 1; //!< Mask bit for PHY_INT0.RX_SENSE[1] interrupt bit
        unsigned char RX_SENSE2 : 1; //!< Mask bit for PHY_INT0.RX_SENSE[2] interrupt bit
        unsigned char RX_SENSE3 : 1; //!< Mask bit for PHY_INT0.RX_SENSE[3] interrupt bit
    } B;
} hw_hdmi_phy_mask0_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_MASK0 register
 */
#define HW_HDMI_PHY_MASK0_ADDR      (REGS_HDMI_BASE + 0x3006)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_MASK0           (*(volatile hw_hdmi_phy_mask0_t *) HW_HDMI_PHY_MASK0_ADDR)
#define HW_HDMI_PHY_MASK0_RD()      (HW_HDMI_PHY_MASK0.U)
#define HW_HDMI_PHY_MASK0_WR(v)     (HW_HDMI_PHY_MASK0.U = (v))
#define HW_HDMI_PHY_MASK0_SET(v)    (HW_HDMI_PHY_MASK0_WR(HW_HDMI_PHY_MASK0_RD() |  (v)))
#define HW_HDMI_PHY_MASK0_CLR(v)    (HW_HDMI_PHY_MASK0_WR(HW_HDMI_PHY_MASK0_RD() & ~(v)))
#define HW_HDMI_PHY_MASK0_TOG(v)    (HW_HDMI_PHY_MASK0_WR(HW_HDMI_PHY_MASK0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_MASK0 bitfields
 */

/* --- Register HW_HDMI_PHY_MASK0, field TX_PHY_LOCK (RW)
 *
 * Mask bit for PHY_INT0.TX_PHY_LOCK interrupt bit
 */

#define BP_HDMI_PHY_MASK0_TX_PHY_LOCK      0
#define BM_HDMI_PHY_MASK0_TX_PHY_LOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MASK0_TX_PHY_LOCK(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_MASK0_TX_PHY_LOCK)
#else
#define BF_HDMI_PHY_MASK0_TX_PHY_LOCK(v)   (((v) << 0) & BM_HDMI_PHY_MASK0_TX_PHY_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_PHY_LOCK field to a new value.
#define BW_HDMI_PHY_MASK0_TX_PHY_LOCK(v)   BF_CS1(HDMI_PHY_MASK0, TX_PHY_LOCK, v)
#endif

/* --- Register HW_HDMI_PHY_MASK0, field HPD (RW)
 *
 * Mask bit for PHY_INT0.HPD interrupt bit
 */

#define BP_HDMI_PHY_MASK0_HPD      1
#define BM_HDMI_PHY_MASK0_HPD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MASK0_HPD(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_MASK0_HPD)
#else
#define BF_HDMI_PHY_MASK0_HPD(v)   (((v) << 1) & BM_HDMI_PHY_MASK0_HPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPD field to a new value.
#define BW_HDMI_PHY_MASK0_HPD(v)   BF_CS1(HDMI_PHY_MASK0, HPD, v)
#endif

/* --- Register HW_HDMI_PHY_MASK0, field RX_SENSE (RW)
 *
 * Mask bit for PHY_INT0.RX_SENSE[0] interrupt bit
 */

#define BP_HDMI_PHY_MASK0_RX_SENSE      4
#define BM_HDMI_PHY_MASK0_RX_SENSE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MASK0_RX_SENSE(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_MASK0_RX_SENSE)
#else
#define BF_HDMI_PHY_MASK0_RX_SENSE(v)   (((v) << 4) & BM_HDMI_PHY_MASK0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_PHY_MASK0_RX_SENSE(v)   BF_CS1(HDMI_PHY_MASK0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_PHY_MASK0, field RX_SENSE (RW)
 *
 * Mask bit for PHY_INT0.RX_SENSE[1] interrupt bit
 */

#define BP_HDMI_PHY_MASK0_RX_SENSE      5
#define BM_HDMI_PHY_MASK0_RX_SENSE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MASK0_RX_SENSE(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_MASK0_RX_SENSE)
#else
#define BF_HDMI_PHY_MASK0_RX_SENSE(v)   (((v) << 5) & BM_HDMI_PHY_MASK0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_PHY_MASK0_RX_SENSE(v)   BF_CS1(HDMI_PHY_MASK0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_PHY_MASK0, field RX_SENSE (RW)
 *
 * Mask bit for PHY_INT0.RX_SENSE[2] interrupt bit
 */

#define BP_HDMI_PHY_MASK0_RX_SENSE      6
#define BM_HDMI_PHY_MASK0_RX_SENSE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MASK0_RX_SENSE(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_MASK0_RX_SENSE)
#else
#define BF_HDMI_PHY_MASK0_RX_SENSE(v)   (((v) << 6) & BM_HDMI_PHY_MASK0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_PHY_MASK0_RX_SENSE(v)   BF_CS1(HDMI_PHY_MASK0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_PHY_MASK0, field RX_SENSE (RW)
 *
 * Mask bit for PHY_INT0.RX_SENSE[3] interrupt bit
 */

#define BP_HDMI_PHY_MASK0_RX_SENSE      7
#define BM_HDMI_PHY_MASK0_RX_SENSE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_MASK0_RX_SENSE(v)   ((((reg32_t) v) << 7) & BM_HDMI_PHY_MASK0_RX_SENSE)
#else
#define BF_HDMI_PHY_MASK0_RX_SENSE(v)   (((v) << 7) & BM_HDMI_PHY_MASK0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_PHY_MASK0_RX_SENSE(v)   BF_CS1(HDMI_PHY_MASK0, RX_SENSE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_POL0 - PHY RXSENSE, PLL lock and HPD Polarity Register (RW)
 *
 * Polarity register for generation of PHY_INT0 interrupts.   Address Offset: 0x3007  Size: 8 bits
 * Value after Reset: 0xF3  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char TX_PHY_LOCK : 1; //!< Polarity bit for PHY_INT0.TX_PHY_LOCK interrupt bit
        unsigned char HPD : 1; //!< Polarity bit for PHY_INT0.HPD interrupt bit
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char RX_SENSE : 1; //!< Polarity bit for PHY_INT0.RX_SENSE[0] interrupt bit
        unsigned char RX_SENSE1 : 1; //!< Polarity bit for PHY_INT0.RX_SENSE[1] interrupt bit
        unsigned char RX_SENSE2 : 1; //!< Polarity bit for PHY_INT0.RX_SENSE[2] interrupt bit
        unsigned char RX_SENSE3 : 1; //!< Polarity bit for PHY_INT0.RX_SENSE[3] interrupt bit
    } B;
} hw_hdmi_phy_pol0_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_POL0 register
 */
#define HW_HDMI_PHY_POL0_ADDR      (REGS_HDMI_BASE + 0x3007)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_POL0           (*(volatile hw_hdmi_phy_pol0_t *) HW_HDMI_PHY_POL0_ADDR)
#define HW_HDMI_PHY_POL0_RD()      (HW_HDMI_PHY_POL0.U)
#define HW_HDMI_PHY_POL0_WR(v)     (HW_HDMI_PHY_POL0.U = (v))
#define HW_HDMI_PHY_POL0_SET(v)    (HW_HDMI_PHY_POL0_WR(HW_HDMI_PHY_POL0_RD() |  (v)))
#define HW_HDMI_PHY_POL0_CLR(v)    (HW_HDMI_PHY_POL0_WR(HW_HDMI_PHY_POL0_RD() & ~(v)))
#define HW_HDMI_PHY_POL0_TOG(v)    (HW_HDMI_PHY_POL0_WR(HW_HDMI_PHY_POL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_POL0 bitfields
 */

/* --- Register HW_HDMI_PHY_POL0, field TX_PHY_LOCK (RW)
 *
 * Polarity bit for PHY_INT0.TX_PHY_LOCK interrupt bit
 */

#define BP_HDMI_PHY_POL0_TX_PHY_LOCK      0
#define BM_HDMI_PHY_POL0_TX_PHY_LOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_POL0_TX_PHY_LOCK(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_POL0_TX_PHY_LOCK)
#else
#define BF_HDMI_PHY_POL0_TX_PHY_LOCK(v)   (((v) << 0) & BM_HDMI_PHY_POL0_TX_PHY_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_PHY_LOCK field to a new value.
#define BW_HDMI_PHY_POL0_TX_PHY_LOCK(v)   BF_CS1(HDMI_PHY_POL0, TX_PHY_LOCK, v)
#endif

/* --- Register HW_HDMI_PHY_POL0, field HPD (RW)
 *
 * Polarity bit for PHY_INT0.HPD interrupt bit
 */

#define BP_HDMI_PHY_POL0_HPD      1
#define BM_HDMI_PHY_POL0_HPD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_POL0_HPD(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_POL0_HPD)
#else
#define BF_HDMI_PHY_POL0_HPD(v)   (((v) << 1) & BM_HDMI_PHY_POL0_HPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPD field to a new value.
#define BW_HDMI_PHY_POL0_HPD(v)   BF_CS1(HDMI_PHY_POL0, HPD, v)
#endif

/* --- Register HW_HDMI_PHY_POL0, field RX_SENSE (RW)
 *
 * Polarity bit for PHY_INT0.RX_SENSE[0] interrupt bit
 */

#define BP_HDMI_PHY_POL0_RX_SENSE      4
#define BM_HDMI_PHY_POL0_RX_SENSE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_POL0_RX_SENSE(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_POL0_RX_SENSE)
#else
#define BF_HDMI_PHY_POL0_RX_SENSE(v)   (((v) << 4) & BM_HDMI_PHY_POL0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_PHY_POL0_RX_SENSE(v)   BF_CS1(HDMI_PHY_POL0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_PHY_POL0, field RX_SENSE (RW)
 *
 * Polarity bit for PHY_INT0.RX_SENSE[1] interrupt bit
 */

#define BP_HDMI_PHY_POL0_RX_SENSE      5
#define BM_HDMI_PHY_POL0_RX_SENSE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_POL0_RX_SENSE(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_POL0_RX_SENSE)
#else
#define BF_HDMI_PHY_POL0_RX_SENSE(v)   (((v) << 5) & BM_HDMI_PHY_POL0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_PHY_POL0_RX_SENSE(v)   BF_CS1(HDMI_PHY_POL0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_PHY_POL0, field RX_SENSE (RW)
 *
 * Polarity bit for PHY_INT0.RX_SENSE[2] interrupt bit
 */

#define BP_HDMI_PHY_POL0_RX_SENSE      6
#define BM_HDMI_PHY_POL0_RX_SENSE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_POL0_RX_SENSE(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_POL0_RX_SENSE)
#else
#define BF_HDMI_PHY_POL0_RX_SENSE(v)   (((v) << 6) & BM_HDMI_PHY_POL0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_PHY_POL0_RX_SENSE(v)   BF_CS1(HDMI_PHY_POL0, RX_SENSE, v)
#endif

/* --- Register HW_HDMI_PHY_POL0, field RX_SENSE (RW)
 *
 * Polarity bit for PHY_INT0.RX_SENSE[3] interrupt bit
 */

#define BP_HDMI_PHY_POL0_RX_SENSE      7
#define BM_HDMI_PHY_POL0_RX_SENSE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_POL0_RX_SENSE(v)   ((((reg32_t) v) << 7) & BM_HDMI_PHY_POL0_RX_SENSE)
#else
#define BF_HDMI_PHY_POL0_RX_SENSE(v)   (((v) << 7) & BM_HDMI_PHY_POL0_RX_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_SENSE field to a new value.
#define BW_HDMI_PHY_POL0_RX_SENSE(v)   BF_CS1(HDMI_PHY_POL0, RX_SENSE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_SLAVE_ADDR - PHY I2C Slave Address Configuration Register (RW)
 *
 * This register writes the slave address of the I2C Master PHY.   Address Offset: 0x3020  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 7; //!< Slave address to be sent during read and write operations. The PHY Gen2 slave address is: 7'h69 The HEAC PHY slave address is: 7'h49
        unsigned char RESERVED1 : 1; //!< Reserved
    } B;
} hw_hdmi_phy_i2cm_slave_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_SLAVE_ADDR register
 */
#define HW_HDMI_PHY_I2CM_SLAVE_ADDR_ADDR      (REGS_HDMI_BASE + 0x3020)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_SLAVE_ADDR           (*(volatile hw_hdmi_phy_i2cm_slave_addr_t *) HW_HDMI_PHY_I2CM_SLAVE_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_SLAVE_ADDR_RD()      (HW_HDMI_PHY_I2CM_SLAVE_ADDR.U)
#define HW_HDMI_PHY_I2CM_SLAVE_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_SLAVE_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_SLAVE_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_SLAVE_ADDR_WR(HW_HDMI_PHY_I2CM_SLAVE_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_SLAVE_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_SLAVE_ADDR_WR(HW_HDMI_PHY_I2CM_SLAVE_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_SLAVE_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_SLAVE_ADDR_WR(HW_HDMI_PHY_I2CM_SLAVE_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_SLAVE_ADDR bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_ADDRESS_ADDR - PHY I2C Address Configuration Register (RW)
 *
 * This register writes the address for read and writer operations.   Address Offset: 0x3021  Size:
 * 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ADDRESS : 8; //!< Register address for read and write operations.
    } B;
} hw_hdmi_phy_i2cm_address_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_ADDRESS_ADDR register
 */
#define HW_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDR      (REGS_HDMI_BASE + 0x3021)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_ADDRESS_ADDR           (*(volatile hw_hdmi_phy_i2cm_address_addr_t *) HW_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_ADDRESS_ADDR_RD()      (HW_HDMI_PHY_I2CM_ADDRESS_ADDR.U)
#define HW_HDMI_PHY_I2CM_ADDRESS_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_ADDRESS_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_ADDRESS_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_ADDRESS_ADDR_WR(HW_HDMI_PHY_I2CM_ADDRESS_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_ADDRESS_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_ADDRESS_ADDR_WR(HW_HDMI_PHY_I2CM_ADDRESS_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_ADDRESS_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_ADDRESS_ADDR_WR(HW_HDMI_PHY_I2CM_ADDRESS_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_ADDRESS_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_ADDRESS_ADDR, field ADDRESS (RW)
 *
 * Register address for read and write operations.
 */

#define BP_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDRESS      0
#define BM_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDRESS      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDRESS(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDRESS)
#else
#define BF_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDRESS(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRESS field to a new value.
#define BW_HDMI_PHY_I2CM_ADDRESS_ADDR_ADDRESS(v)   BF_CS1(HDMI_PHY_I2CM_ADDRESS_ADDR, ADDRESS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_DATAO_1_ADDR - PHY I2C Data Write Register 1 (RW)
 *
 * Address Offset: 0x3022  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DATAO : 8; //!< MSB's of data to be written on register pointed by address [7:0].
    } B;
} hw_hdmi_phy_i2cm_datao_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_DATAO_1_ADDR register
 */
#define HW_HDMI_PHY_I2CM_DATAO_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x3022)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_DATAO_1_ADDR           (*(volatile hw_hdmi_phy_i2cm_datao_1_addr_t *) HW_HDMI_PHY_I2CM_DATAO_1_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_DATAO_1_ADDR_RD()      (HW_HDMI_PHY_I2CM_DATAO_1_ADDR.U)
#define HW_HDMI_PHY_I2CM_DATAO_1_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_DATAO_1_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_DATAO_1_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_DATAO_1_ADDR_WR(HW_HDMI_PHY_I2CM_DATAO_1_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_DATAO_1_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_DATAO_1_ADDR_WR(HW_HDMI_PHY_I2CM_DATAO_1_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_DATAO_1_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_DATAO_1_ADDR_WR(HW_HDMI_PHY_I2CM_DATAO_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_DATAO_1_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_DATAO_1_ADDR, field DATAO (RW)
 *
 * MSB's of data to be written on register pointed by address [7:0].
 */

#define BP_HDMI_PHY_I2CM_DATAO_1_ADDR_DATAO      0
#define BM_HDMI_PHY_I2CM_DATAO_1_ADDR_DATAO      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_DATAO_1_ADDR_DATAO(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_DATAO_1_ADDR_DATAO)
#else
#define BF_HDMI_PHY_I2CM_DATAO_1_ADDR_DATAO(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_DATAO_1_ADDR_DATAO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAO field to a new value.
#define BW_HDMI_PHY_I2CM_DATAO_1_ADDR_DATAO(v)   BF_CS1(HDMI_PHY_I2CM_DATAO_1_ADDR, DATAO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_DATAO_0_ADDR - PHY I2C Data Write Register 0 (RW)
 *
 * Address Offset: 0x3023  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DATAO : 8; //!< LSB's of data to be written on register pointed by address [7:0].
    } B;
} hw_hdmi_phy_i2cm_datao_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_DATAO_0_ADDR register
 */
#define HW_HDMI_PHY_I2CM_DATAO_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x3023)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_DATAO_0_ADDR           (*(volatile hw_hdmi_phy_i2cm_datao_0_addr_t *) HW_HDMI_PHY_I2CM_DATAO_0_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_DATAO_0_ADDR_RD()      (HW_HDMI_PHY_I2CM_DATAO_0_ADDR.U)
#define HW_HDMI_PHY_I2CM_DATAO_0_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_DATAO_0_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_DATAO_0_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_DATAO_0_ADDR_WR(HW_HDMI_PHY_I2CM_DATAO_0_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_DATAO_0_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_DATAO_0_ADDR_WR(HW_HDMI_PHY_I2CM_DATAO_0_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_DATAO_0_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_DATAO_0_ADDR_WR(HW_HDMI_PHY_I2CM_DATAO_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_DATAO_0_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_DATAO_0_ADDR, field DATAO (RW)
 *
 * LSB's of data to be written on register pointed by address [7:0].
 */

#define BP_HDMI_PHY_I2CM_DATAO_0_ADDR_DATAO      0
#define BM_HDMI_PHY_I2CM_DATAO_0_ADDR_DATAO      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_DATAO_0_ADDR_DATAO(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_DATAO_0_ADDR_DATAO)
#else
#define BF_HDMI_PHY_I2CM_DATAO_0_ADDR_DATAO(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_DATAO_0_ADDR_DATAO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAO field to a new value.
#define BW_HDMI_PHY_I2CM_DATAO_0_ADDR_DATAO(v)   BF_CS1(HDMI_PHY_I2CM_DATAO_0_ADDR, DATAO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_DATAI_1_ADDR - PHY I2C Data Read Register 1 (RO)
 *
 * Address Offset: 0x3024  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DATAI : 8; //!< MSB's of data read from the register pointed by address [7:0].
    } B;
} hw_hdmi_phy_i2cm_datai_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_DATAI_1_ADDR register
 */
#define HW_HDMI_PHY_I2CM_DATAI_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x3024)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_DATAI_1_ADDR           (*(volatile hw_hdmi_phy_i2cm_datai_1_addr_t *) HW_HDMI_PHY_I2CM_DATAI_1_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_DATAI_1_ADDR_RD()      (HW_HDMI_PHY_I2CM_DATAI_1_ADDR.U)
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_DATAI_1_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_DATAI_1_ADDR, field DATAI (RO)
 *
 * MSB's of data read from the register pointed by address [7:0].
 */

#define BP_HDMI_PHY_I2CM_DATAI_1_ADDR_DATAI      0
#define BM_HDMI_PHY_I2CM_DATAI_1_ADDR_DATAI      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_DATAI_0_ADDR - PHY I2C Data Read Register 0 (RW)
 *
 * Address Offset: 0x3025  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DATAI : 8; //!< LSB's of data read from the register pointed by address [7:0].
    } B;
} hw_hdmi_phy_i2cm_datai_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_DATAI_0_ADDR register
 */
#define HW_HDMI_PHY_I2CM_DATAI_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x3025)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_DATAI_0_ADDR           (*(volatile hw_hdmi_phy_i2cm_datai_0_addr_t *) HW_HDMI_PHY_I2CM_DATAI_0_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_DATAI_0_ADDR_RD()      (HW_HDMI_PHY_I2CM_DATAI_0_ADDR.U)
#define HW_HDMI_PHY_I2CM_DATAI_0_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_DATAI_0_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_DATAI_0_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_DATAI_0_ADDR_WR(HW_HDMI_PHY_I2CM_DATAI_0_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_DATAI_0_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_DATAI_0_ADDR_WR(HW_HDMI_PHY_I2CM_DATAI_0_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_DATAI_0_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_DATAI_0_ADDR_WR(HW_HDMI_PHY_I2CM_DATAI_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_DATAI_0_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_DATAI_0_ADDR, field DATAI (RW)
 *
 * LSB's of data read from the register pointed by address [7:0].
 */

#define BP_HDMI_PHY_I2CM_DATAI_0_ADDR_DATAI      0
#define BM_HDMI_PHY_I2CM_DATAI_0_ADDR_DATAI      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_DATAI_0_ADDR_DATAI(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_DATAI_0_ADDR_DATAI)
#else
#define BF_HDMI_PHY_I2CM_DATAI_0_ADDR_DATAI(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_DATAI_0_ADDR_DATAI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAI field to a new value.
#define BW_HDMI_PHY_I2CM_DATAI_0_ADDR_DATAI(v)   BF_CS1(HDMI_PHY_I2CM_DATAI_0_ADDR, DATAI, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_OPERATION_ADDR - PHY I2C Read/Write Operation (WO)
 *
 * This register requests read and write operations from the I2C Master PHY. This register can only
 * be written; reading this register always results in 00h. Writing 1'b1 simultaneously to read and
 * write requests is considered a read request.   Address Offset: 0x3026  Size: 8 bits  Value after
 * Reset: 0x00  Access: Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char READ : 1; //!< Read operation request.
        unsigned char RESERVED0 : 3; //!< Reserved
        unsigned char WRITE : 1; //!< Write operation request
        unsigned char RESERVED1 : 3; //!< Reserved
    } B;
} hw_hdmi_phy_i2cm_operation_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_OPERATION_ADDR register
 */
#define HW_HDMI_PHY_I2CM_OPERATION_ADDR_ADDR      (REGS_HDMI_BASE + 0x3026)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_OPERATION_ADDR           (*(volatile hw_hdmi_phy_i2cm_operation_addr_t *) HW_HDMI_PHY_I2CM_OPERATION_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_OPERATION_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_OPERATION_ADDR.U = (v))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_OPERATION_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_OPERATION_ADDR, field READ (WO)
 *
 * Read operation request.
 */

#define BP_HDMI_PHY_I2CM_OPERATION_ADDR_READ      0
#define BM_HDMI_PHY_I2CM_OPERATION_ADDR_READ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_OPERATION_ADDR_READ(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_OPERATION_ADDR_READ)
#else
#define BF_HDMI_PHY_I2CM_OPERATION_ADDR_READ(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_OPERATION_ADDR_READ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the READ field to a new value.
#define BW_HDMI_PHY_I2CM_OPERATION_ADDR_READ(v)   BF_CS1(HDMI_PHY_I2CM_OPERATION_ADDR, READ, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_OPERATION_ADDR, field WRITE (WO)
 *
 * Write operation request
 */

#define BP_HDMI_PHY_I2CM_OPERATION_ADDR_WRITE      4
#define BM_HDMI_PHY_I2CM_OPERATION_ADDR_WRITE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_OPERATION_ADDR_WRITE(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_I2CM_OPERATION_ADDR_WRITE)
#else
#define BF_HDMI_PHY_I2CM_OPERATION_ADDR_WRITE(v)   (((v) << 4) & BM_HDMI_PHY_I2CM_OPERATION_ADDR_WRITE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WRITE field to a new value.
#define BW_HDMI_PHY_I2CM_OPERATION_ADDR_WRITE(v)   BF_CS1(HDMI_PHY_I2CM_OPERATION_ADDR, WRITE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_INT_ADDR - PHY I2C Done Interrupt Register (RW)
 *
 * This register contains and configures I2C master PHY done interrupt.   Address Offset: 0x3027
 * Size: 8 bits  Value after Reset: 0x08  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DONE_STATUS : 1; //!< Operation done status bit.Marks the end of a rd or write operation. Value after Reset: 0b
        unsigned char DONE_INTERRUPT : 1; //!< Operation done interrupt bit.{done_interrupt =(done_mask==0b)&& (done_status==done_pol)}. Value after Reset: 0b
        unsigned char DONE_MASK : 1; //!< Done interrupt mask signal Value after Reset: 0b
        unsigned char DONE_POL : 1; //!< Done interrupt polarity configuration Value after Reset: 1b
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_phy_i2cm_int_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_INT_ADDR register
 */
#define HW_HDMI_PHY_I2CM_INT_ADDR_ADDR      (REGS_HDMI_BASE + 0x3027)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_INT_ADDR           (*(volatile hw_hdmi_phy_i2cm_int_addr_t *) HW_HDMI_PHY_I2CM_INT_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_INT_ADDR_RD()      (HW_HDMI_PHY_I2CM_INT_ADDR.U)
#define HW_HDMI_PHY_I2CM_INT_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_INT_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_INT_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_INT_ADDR_WR(HW_HDMI_PHY_I2CM_INT_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_INT_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_INT_ADDR_WR(HW_HDMI_PHY_I2CM_INT_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_INT_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_INT_ADDR_WR(HW_HDMI_PHY_I2CM_INT_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_INT_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_INT_ADDR, field DONE_STATUS (RW)
 *
 * Operation done status bit.Marks the end of a rd or write operation. Value after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_INT_ADDR_DONE_STATUS      0
#define BM_HDMI_PHY_I2CM_INT_ADDR_DONE_STATUS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_INT_ADDR_DONE_STATUS(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_INT_ADDR_DONE_STATUS)
#else
#define BF_HDMI_PHY_I2CM_INT_ADDR_DONE_STATUS(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_INT_ADDR_DONE_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_STATUS field to a new value.
#define BW_HDMI_PHY_I2CM_INT_ADDR_DONE_STATUS(v)   BF_CS1(HDMI_PHY_I2CM_INT_ADDR, DONE_STATUS, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_INT_ADDR, field DONE_INTERRUPT (RW)
 *
 * Operation done interrupt bit.{done_interrupt =(done_mask==0b)&& (done_status==done_pol)}. Value
 * after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_INT_ADDR_DONE_INTERRUPT      1
#define BM_HDMI_PHY_I2CM_INT_ADDR_DONE_INTERRUPT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_INT_ADDR_DONE_INTERRUPT(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_I2CM_INT_ADDR_DONE_INTERRUPT)
#else
#define BF_HDMI_PHY_I2CM_INT_ADDR_DONE_INTERRUPT(v)   (((v) << 1) & BM_HDMI_PHY_I2CM_INT_ADDR_DONE_INTERRUPT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_INTERRUPT field to a new value.
#define BW_HDMI_PHY_I2CM_INT_ADDR_DONE_INTERRUPT(v)   BF_CS1(HDMI_PHY_I2CM_INT_ADDR, DONE_INTERRUPT, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_INT_ADDR, field DONE_MASK (RW)
 *
 * Done interrupt mask signal Value after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_INT_ADDR_DONE_MASK      2
#define BM_HDMI_PHY_I2CM_INT_ADDR_DONE_MASK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_INT_ADDR_DONE_MASK(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_I2CM_INT_ADDR_DONE_MASK)
#else
#define BF_HDMI_PHY_I2CM_INT_ADDR_DONE_MASK(v)   (((v) << 2) & BM_HDMI_PHY_I2CM_INT_ADDR_DONE_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_MASK field to a new value.
#define BW_HDMI_PHY_I2CM_INT_ADDR_DONE_MASK(v)   BF_CS1(HDMI_PHY_I2CM_INT_ADDR, DONE_MASK, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_INT_ADDR, field DONE_POL (RW)
 *
 * Done interrupt polarity configuration Value after Reset: 1b
 */

#define BP_HDMI_PHY_I2CM_INT_ADDR_DONE_POL      3
#define BM_HDMI_PHY_I2CM_INT_ADDR_DONE_POL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_INT_ADDR_DONE_POL(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_I2CM_INT_ADDR_DONE_POL)
#else
#define BF_HDMI_PHY_I2CM_INT_ADDR_DONE_POL(v)   (((v) << 3) & BM_HDMI_PHY_I2CM_INT_ADDR_DONE_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_POL field to a new value.
#define BW_HDMI_PHY_I2CM_INT_ADDR_DONE_POL(v)   BF_CS1(HDMI_PHY_I2CM_INT_ADDR, DONE_POL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_CTLINT_ADDR - PHY I2C Done Interrupt Register (RW)
 *
 * This register contains and configures the I2C master PHY error interrupts.   Address Offset:
 * 0x3028  Size: 8 bits  Value after Reset: 0x88  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ARBITRATION_STATUS : 1; //!< Arbitration error status bit. Error on master I2C protocol arbitration. Value after Reset: 0b
        unsigned char ARBITRATION_INTERRUPT : 1; //!< Arbitration error interrupt bit.{arbitration_interrupt = (arbitration_mask==0b)&& (arbitration_status==arbitration_pol)}. Value after Reset: 0b
        unsigned char ARBITRATION_MASK : 1; //!< Arbitration error interrupt mask signal. Value after Reset: 0b
        unsigned char ARBITRATION_POL : 1; //!< Arbitration error interrupt polarity configuration. Value after Reset: 1b
        unsigned char NACK_STATUS : 1; //!< Not acknowledge error status bit.Error on I2C not acknowledge. Value after Reset: 0b
        unsigned char NACK_INTERRUPT : 1; //!< Not acknowledge error interrupt bit.{nack_interrupt = nack_mask==0b) && (nack_status==nack_pol)}. Value after Reset: 0b
        unsigned char NACK_MASK : 1; //!< Not acknowledge error interrupt mask signal Value after Reset: 0b
        unsigned char NACK_POL : 1; //!< Not acknowledge error interrupt polarity configuration. Value after Reset: 1b
    } B;
} hw_hdmi_phy_i2cm_ctlint_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_CTLINT_ADDR register
 */
#define HW_HDMI_PHY_I2CM_CTLINT_ADDR_ADDR      (REGS_HDMI_BASE + 0x3028)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_CTLINT_ADDR           (*(volatile hw_hdmi_phy_i2cm_ctlint_addr_t *) HW_HDMI_PHY_I2CM_CTLINT_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_CTLINT_ADDR_RD()      (HW_HDMI_PHY_I2CM_CTLINT_ADDR.U)
#define HW_HDMI_PHY_I2CM_CTLINT_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_CTLINT_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_CTLINT_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_CTLINT_ADDR_WR(HW_HDMI_PHY_I2CM_CTLINT_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_CTLINT_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_CTLINT_ADDR_WR(HW_HDMI_PHY_I2CM_CTLINT_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_CTLINT_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_CTLINT_ADDR_WR(HW_HDMI_PHY_I2CM_CTLINT_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_CTLINT_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_CTLINT_ADDR, field ARBITRATION_STATUS (RW)
 *
 * Arbitration error status bit. Error on master I2C protocol arbitration. Value after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_STATUS      0
#define BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_STATUS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_STATUS(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_STATUS)
#else
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_STATUS(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_STATUS field to a new value.
#define BW_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_STATUS(v)   BF_CS1(HDMI_PHY_I2CM_CTLINT_ADDR, ARBITRATION_STATUS, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_CTLINT_ADDR, field ARBITRATION_INTERRUPT (RW)
 *
 * Arbitration error interrupt bit.{arbitration_interrupt = (arbitration_mask==0b)&&
 * (arbitration_status==arbitration_pol)}. Value after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_INTERRUPT      1
#define BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_INTERRUPT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_INTERRUPT(v)   ((((reg32_t) v) << 1) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_INTERRUPT)
#else
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_INTERRUPT(v)   (((v) << 1) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_INTERRUPT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_INTERRUPT field to a new value.
#define BW_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_INTERRUPT(v)   BF_CS1(HDMI_PHY_I2CM_CTLINT_ADDR, ARBITRATION_INTERRUPT, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_CTLINT_ADDR, field ARBITRATION_MASK (RW)
 *
 * Arbitration error interrupt mask signal. Value after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_MASK      2
#define BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_MASK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_MASK(v)   ((((reg32_t) v) << 2) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_MASK)
#else
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_MASK(v)   (((v) << 2) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_MASK field to a new value.
#define BW_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_MASK(v)   BF_CS1(HDMI_PHY_I2CM_CTLINT_ADDR, ARBITRATION_MASK, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_CTLINT_ADDR, field ARBITRATION_POL (RW)
 *
 * Arbitration error interrupt polarity configuration. Value after Reset: 1b
 */

#define BP_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL      3
#define BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL(v)   ((((reg32_t) v) << 3) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL)
#else
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL(v)   (((v) << 3) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_POL field to a new value.
#define BW_HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL(v)   BF_CS1(HDMI_PHY_I2CM_CTLINT_ADDR, ARBITRATION_POL, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_CTLINT_ADDR, field NACK_STATUS (RW)
 *
 * Not acknowledge error status bit.Error on I2C not acknowledge. Value after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_STATUS      4
#define BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_STATUS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_STATUS(v)   ((((reg32_t) v) << 4) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_STATUS)
#else
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_STATUS(v)   (((v) << 4) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_STATUS field to a new value.
#define BW_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_STATUS(v)   BF_CS1(HDMI_PHY_I2CM_CTLINT_ADDR, NACK_STATUS, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_CTLINT_ADDR, field NACK_INTERRUPT (RW)
 *
 * Not acknowledge error interrupt bit.{nack_interrupt = nack_mask==0b) && (nack_status==nack_pol)}.
 * Value after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_INTERRUPT      5
#define BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_INTERRUPT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_INTERRUPT(v)   ((((reg32_t) v) << 5) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_INTERRUPT)
#else
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_INTERRUPT(v)   (((v) << 5) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_INTERRUPT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_INTERRUPT field to a new value.
#define BW_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_INTERRUPT(v)   BF_CS1(HDMI_PHY_I2CM_CTLINT_ADDR, NACK_INTERRUPT, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_CTLINT_ADDR, field NACK_MASK (RW)
 *
 * Not acknowledge error interrupt mask signal Value after Reset: 0b
 */

#define BP_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_MASK      6
#define BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_MASK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_MASK(v)   ((((reg32_t) v) << 6) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_MASK)
#else
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_MASK(v)   (((v) << 6) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_MASK field to a new value.
#define BW_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_MASK(v)   BF_CS1(HDMI_PHY_I2CM_CTLINT_ADDR, NACK_MASK, v)
#endif

/* --- Register HW_HDMI_PHY_I2CM_CTLINT_ADDR, field NACK_POL (RW)
 *
 * Not acknowledge error interrupt polarity configuration. Value after Reset: 1b
 */

#define BP_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_POL      7
#define BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_POL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_POL(v)   ((((reg32_t) v) << 7) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_POL)
#else
#define BF_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_POL(v)   (((v) << 7) & BM_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_POL field to a new value.
#define BW_HDMI_PHY_I2CM_CTLINT_ADDR_NACK_POL(v)   BF_CS1(HDMI_PHY_I2CM_CTLINT_ADDR, NACK_POL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_DIV_ADDR - PHY I2C Speed Control Register (RW)
 *
 * This register wets the I2C Master PHY to work in either Fast or Standard mode.   Address Offset:
 * 0x3029  Size: 8 bits  Value after Reset: 0x0B  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FAST_MODE : 4; //!< Sets the I2C Master to work in Fast Mode or Standard Mode (x implies that it can take any value) Value after Reset: 1011b 1xxxb Fast Mode 0xxxb Standard Mode
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_phy_i2cm_div_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_DIV_ADDR register
 */
#define HW_HDMI_PHY_I2CM_DIV_ADDR_ADDR      (REGS_HDMI_BASE + 0x3029)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_DIV_ADDR           (*(volatile hw_hdmi_phy_i2cm_div_addr_t *) HW_HDMI_PHY_I2CM_DIV_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_DIV_ADDR_RD()      (HW_HDMI_PHY_I2CM_DIV_ADDR.U)
#define HW_HDMI_PHY_I2CM_DIV_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_DIV_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_DIV_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_DIV_ADDR_WR(HW_HDMI_PHY_I2CM_DIV_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_DIV_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_DIV_ADDR_WR(HW_HDMI_PHY_I2CM_DIV_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_DIV_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_DIV_ADDR_WR(HW_HDMI_PHY_I2CM_DIV_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_DIV_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_DIV_ADDR, field FAST_MODE (RW)
 *
 * Sets the I2C Master to work in Fast Mode or Standard Mode (x implies that it can take any value)
 * Value after Reset: 1011b 1xxxb Fast Mode 0xxxb Standard Mode
 */

#define BP_HDMI_PHY_I2CM_DIV_ADDR_FAST_MODE      0
#define BM_HDMI_PHY_I2CM_DIV_ADDR_FAST_MODE      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_DIV_ADDR_FAST_MODE(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_DIV_ADDR_FAST_MODE)
#else
#define BF_HDMI_PHY_I2CM_DIV_ADDR_FAST_MODE(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_DIV_ADDR_FAST_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FAST_MODE field to a new value.
#define BW_HDMI_PHY_I2CM_DIV_ADDR_FAST_MODE(v)   BF_CS1(HDMI_PHY_I2CM_DIV_ADDR, FAST_MODE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR - PHY I2C Software Reset Register (RW)
 *
 * This register sets the I2C Master PHY software reset.   Address Offset: 0x302A  Size: 8 bits
 * Value after Reset: 0x01  Access: Read/Write   The following *CNT registers must be set before any
 * I2C bus transaction can take place to ensure proper I/O timing. For more information about the
 * SFR_CLK frequency configuration, see ."   The following are the I2C Master SCL clock settings:
 * SS: Standard Speed  FS: Fast Speed  HCNT: SCL High Level counter  LCNT: SCL Low Level counter
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2C_SOFTRST : 1; //!< I2C Master PHY Software Reset. Active by writing a zero and auto cleared to one in the following cycle. Value after Reset: 1b
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_phy_i2cm_softrstz_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_SOFTRSTZ_ADDR register
 */
#define HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_ADDR      (REGS_HDMI_BASE + 0x302a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR           (*(volatile hw_hdmi_phy_i2cm_softrstz_addr_t *) HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_RD()      (HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR.U)
#define HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_WR(HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_WR(HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_WR(HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_SOFTRSTZ_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR, field I2C_SOFTRST (RW)
 *
 * I2C Master PHY Software Reset. Active by writing a zero and auto cleared to one in the following
 * cycle. Value after Reset: 1b
 */

#define BP_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_I2C_SOFTRST      0
#define BM_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_I2C_SOFTRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_I2C_SOFTRST(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_I2C_SOFTRST)
#else
#define BF_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_I2C_SOFTRST(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_I2C_SOFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2C_SOFTRST field to a new value.
#define BW_HDMI_PHY_I2CM_SOFTRSTZ_ADDR_I2C_SOFTRST(v)   BF_CS1(HDMI_PHY_I2CM_SOFTRSTZ_ADDR, I2C_SOFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR - PHY I2C Slow Speed SCL High Level Control Register 1 (RW)
 *
 * Address Offset: 0x302B  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_SS_SCL_HCNT : 8; //!< Value after Reset: 8'h00
    } B;
} hw_hdmi_phy_i2cm_ss_scl_hcnt_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR register
 */
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x302b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR           (*(volatile hw_hdmi_phy_i2cm_ss_scl_hcnt_1_addr_t *) HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_RD()      (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR.U)
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR, field I2CMP_SS_SCL_HCNT (RW)
 *
 * Value after Reset: 8'h00
 */

#define BP_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT      0
#define BM_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT)
#else
#define BF_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_SS_SCL_HCNT field to a new value.
#define BW_HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT(v)   BF_CS1(HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR, I2CMP_SS_SCL_HCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR - PHY I2C Slow Speed SCL High Level Control Register 0 (RW)
 *
 * Address Offset: 0x302C  Size: 8 bits  Value after Reset: 0x6C  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_SS_SCL_HCNT : 8; //!< Value after Reset: 8'h6C
    } B;
} hw_hdmi_phy_i2cm_ss_scl_hcnt_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR register
 */
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x302c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR           (*(volatile hw_hdmi_phy_i2cm_ss_scl_hcnt_0_addr_t *) HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_RD()      (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR.U)
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR, field I2CMP_SS_SCL_HCNT (RW)
 *
 * Value after Reset: 8'h6C
 */

#define BP_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT      0
#define BM_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT)
#else
#define BF_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_SS_SCL_HCNT field to a new value.
#define BW_HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT(v)   BF_CS1(HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR, I2CMP_SS_SCL_HCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR - PHY I2C Slow Speed SCL Low Level Control Register 1 (RW)
 *
 * Address Offset: 0x302D  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_SS_SCL_LCNT : 8; //!< Value after Reset: 8'h00
    } B;
} hw_hdmi_phy_i2cm_ss_scl_lcnt_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR register
 */
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x302d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR           (*(volatile hw_hdmi_phy_i2cm_ss_scl_lcnt_1_addr_t *) HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_RD()      (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR.U)
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR, field I2CMP_SS_SCL_LCNT (RW)
 *
 * Value after Reset: 8'h00
 */

#define BP_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT      0
#define BM_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT)
#else
#define BF_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_SS_SCL_LCNT field to a new value.
#define BW_HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT(v)   BF_CS1(HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR, I2CMP_SS_SCL_LCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR - PHY I2C Slow Speed SCL Low Level Control Register 0 (RW)
 *
 * Address Offset: 0x302E  Size: 8 bits  Value after Reset: 0x7F  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_SS_SCL_LCNT : 8; //!< Value after Reset: 8'h7F
    } B;
} hw_hdmi_phy_i2cm_ss_scl_lcnt_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR register
 */
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x302e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR           (*(volatile hw_hdmi_phy_i2cm_ss_scl_lcnt_0_addr_t *) HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_RD()      (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR.U)
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR, field I2CMP_SS_SCL_LCNT (RW)
 *
 * Value after Reset: 8'h7F
 */

#define BP_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT      0
#define BM_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT)
#else
#define BF_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_SS_SCL_LCNT field to a new value.
#define BW_HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT(v)   BF_CS1(HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR, I2CMP_SS_SCL_LCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR - PHY I2C Fast Speed SCL High Level Control Register 1 (RW)
 *
 * Address Offset: 0x302F  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_FS_SCL_HCNT : 8; //!< Value after Reset: 8'h00
    } B;
} hw_hdmi_phy_i2cm_fs_scl_hcnt_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR register
 */
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x302f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR           (*(volatile hw_hdmi_phy_i2cm_fs_scl_hcnt_1_addr_t *) HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_RD()      (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR.U)
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR, field I2CMP_FS_SCL_HCNT (RW)
 *
 * Value after Reset: 8'h00
 */

#define BP_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT      0
#define BM_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT)
#else
#define BF_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_FS_SCL_HCNT field to a new value.
#define BW_HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT(v)   BF_CS1(HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR, I2CMP_FS_SCL_HCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR - PHY I2C Fast Speed SCL High Level Control Register 0 (RW)
 *
 * Address Offset: 0x3030  Size: 8 bits  Value after Reset: 0x11  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_FS_SCL_HCNT : 8; //!< Value after Reset: 8'h11
    } B;
} hw_hdmi_phy_i2cm_fs_scl_hcnt_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR register
 */
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x3030)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR           (*(volatile hw_hdmi_phy_i2cm_fs_scl_hcnt_0_addr_t *) HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_RD()      (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR.U)
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR, field I2CMP_FS_SCL_HCNT (RW)
 *
 * Value after Reset: 8'h11
 */

#define BP_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT      0
#define BM_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT)
#else
#define BF_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_FS_SCL_HCNT field to a new value.
#define BW_HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT(v)   BF_CS1(HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR, I2CMP_FS_SCL_HCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR - PHY I2C Fast Speed SCL Low Level Control Register 1 (RW)
 *
 * Address Offset: 0x3031  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_FS_SCL_LCNT : 8; //!< Value after Reset: 8'h00
    } B;
} hw_hdmi_phy_i2cm_fs_scl_lcnt_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR register
 */
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x3031)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR           (*(volatile hw_hdmi_phy_i2cm_fs_scl_lcnt_1_addr_t *) HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_RD()      (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR.U)
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR, field I2CMP_FS_SCL_LCNT (RW)
 *
 * Value after Reset: 8'h00
 */

#define BP_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT      0
#define BM_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT)
#else
#define BF_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_FS_SCL_LCNT field to a new value.
#define BW_HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT(v)   BF_CS1(HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR, I2CMP_FS_SCL_LCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR - PHY I2C Fast Speed SCL Low Level Control Register 0 (RW)
 *
 * Address Offset: 0x3032  Size: 8 bits  Value after Reset: 0x24  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_FS_SCL_LCNT : 8; //!< Value after Reset: 8'h24
    } B;
} hw_hdmi_phy_i2cm_fs_scl_lcnt_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR register
 */
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x3032)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR           (*(volatile hw_hdmi_phy_i2cm_fs_scl_lcnt_0_addr_t *) HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_ADDR)
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_RD()      (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR.U)
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_WR(v)     (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR.U = (v))
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_SET(v)    (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_RD() |  (v)))
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_CLR(v)    (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_RD() & ~(v)))
#define HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_TOG(v)    (HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_WR(HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR bitfields
 */

/* --- Register HW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR, field I2CMP_FS_SCL_LCNT (RW)
 *
 * Value after Reset: 8'h24
 */

#define BP_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT      0
#define BM_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT)
#else
#define BF_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT(v)   (((v) << 0) & BM_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_FS_SCL_LCNT field to a new value.
#define BW_HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT(v)   BF_CS1(HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR, I2CMP_FS_SCL_LCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AUD_N1 - Audio Clock Regenerator N Value Register 1 (RW)
 *
 * For N expected values, refer to the HDMI 1.4a specification.   Address Offset: 0x3200  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDN : 8; //!< HDMI Audio Clock Regenerator N value
    } B;
} hw_hdmi_aud_n1_t;
#endif

/*
 * constants & macros for entire HDMI_AUD_N1 register
 */
#define HW_HDMI_AUD_N1_ADDR      (REGS_HDMI_BASE + 0x3200)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AUD_N1           (*(volatile hw_hdmi_aud_n1_t *) HW_HDMI_AUD_N1_ADDR)
#define HW_HDMI_AUD_N1_RD()      (HW_HDMI_AUD_N1.U)
#define HW_HDMI_AUD_N1_WR(v)     (HW_HDMI_AUD_N1.U = (v))
#define HW_HDMI_AUD_N1_SET(v)    (HW_HDMI_AUD_N1_WR(HW_HDMI_AUD_N1_RD() |  (v)))
#define HW_HDMI_AUD_N1_CLR(v)    (HW_HDMI_AUD_N1_WR(HW_HDMI_AUD_N1_RD() & ~(v)))
#define HW_HDMI_AUD_N1_TOG(v)    (HW_HDMI_AUD_N1_WR(HW_HDMI_AUD_N1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AUD_N1 bitfields
 */

/* --- Register HW_HDMI_AUD_N1, field AUDN (RW)
 *
 * HDMI Audio Clock Regenerator N value
 */

#define BP_HDMI_AUD_N1_AUDN      0
#define BM_HDMI_AUD_N1_AUDN      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AUD_N1_AUDN(v)   ((((reg32_t) v) << 0) & BM_HDMI_AUD_N1_AUDN)
#else
#define BF_HDMI_AUD_N1_AUDN(v)   (((v) << 0) & BM_HDMI_AUD_N1_AUDN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDN field to a new value.
#define BW_HDMI_AUD_N1_AUDN(v)   BF_CS1(HDMI_AUD_N1, AUDN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AUD_N2 - Audio Clock Regenerator N Value Register 2 (RW)
 *
 * For N expected values, refer to the HDMI 1.4a specification.   Address Offset: 0x3201  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDN : 8; //!< HDMI Audio Clock Regenerator N value
    } B;
} hw_hdmi_aud_n2_t;
#endif

/*
 * constants & macros for entire HDMI_AUD_N2 register
 */
#define HW_HDMI_AUD_N2_ADDR      (REGS_HDMI_BASE + 0x3201)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AUD_N2           (*(volatile hw_hdmi_aud_n2_t *) HW_HDMI_AUD_N2_ADDR)
#define HW_HDMI_AUD_N2_RD()      (HW_HDMI_AUD_N2.U)
#define HW_HDMI_AUD_N2_WR(v)     (HW_HDMI_AUD_N2.U = (v))
#define HW_HDMI_AUD_N2_SET(v)    (HW_HDMI_AUD_N2_WR(HW_HDMI_AUD_N2_RD() |  (v)))
#define HW_HDMI_AUD_N2_CLR(v)    (HW_HDMI_AUD_N2_WR(HW_HDMI_AUD_N2_RD() & ~(v)))
#define HW_HDMI_AUD_N2_TOG(v)    (HW_HDMI_AUD_N2_WR(HW_HDMI_AUD_N2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AUD_N2 bitfields
 */

/* --- Register HW_HDMI_AUD_N2, field AUDN (RW)
 *
 * HDMI Audio Clock Regenerator N value
 */

#define BP_HDMI_AUD_N2_AUDN      0
#define BM_HDMI_AUD_N2_AUDN      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AUD_N2_AUDN(v)   ((((reg32_t) v) << 0) & BM_HDMI_AUD_N2_AUDN)
#else
#define BF_HDMI_AUD_N2_AUDN(v)   (((v) << 0) & BM_HDMI_AUD_N2_AUDN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDN field to a new value.
#define BW_HDMI_AUD_N2_AUDN(v)   BF_CS1(HDMI_AUD_N2, AUDN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AUD_N3 - Audio Clock Regenerator N Value Register 3 (RW)
 *
 * For N expected values, refer to the HDMI 1.4a specification.   Address Offset: 0x3202  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDN : 4; //!< HDMI Audio Clock Regenerator N value
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_aud_n3_t;
#endif

/*
 * constants & macros for entire HDMI_AUD_N3 register
 */
#define HW_HDMI_AUD_N3_ADDR      (REGS_HDMI_BASE + 0x3202)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AUD_N3           (*(volatile hw_hdmi_aud_n3_t *) HW_HDMI_AUD_N3_ADDR)
#define HW_HDMI_AUD_N3_RD()      (HW_HDMI_AUD_N3.U)
#define HW_HDMI_AUD_N3_WR(v)     (HW_HDMI_AUD_N3.U = (v))
#define HW_HDMI_AUD_N3_SET(v)    (HW_HDMI_AUD_N3_WR(HW_HDMI_AUD_N3_RD() |  (v)))
#define HW_HDMI_AUD_N3_CLR(v)    (HW_HDMI_AUD_N3_WR(HW_HDMI_AUD_N3_RD() & ~(v)))
#define HW_HDMI_AUD_N3_TOG(v)    (HW_HDMI_AUD_N3_WR(HW_HDMI_AUD_N3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AUD_N3 bitfields
 */

/* --- Register HW_HDMI_AUD_N3, field AUDN (RW)
 *
 * HDMI Audio Clock Regenerator N value
 */

#define BP_HDMI_AUD_N3_AUDN      0
#define BM_HDMI_AUD_N3_AUDN      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AUD_N3_AUDN(v)   ((((reg32_t) v) << 0) & BM_HDMI_AUD_N3_AUDN)
#else
#define BF_HDMI_AUD_N3_AUDN(v)   (((v) << 0) & BM_HDMI_AUD_N3_AUDN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDN field to a new value.
#define BW_HDMI_AUD_N3_AUDN(v)   BF_CS1(HDMI_AUD_N3, AUDN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AUD_CTS1 - AUD_CTS1 (RW)
 *
 * For CTS expected values, refer to the HDMI 1.4a specification.   Address Offset: 0x3203  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDCTS : 8; //!< HDMI Audio Clock Regenerator CTS calculated value. This value can be manually set using the CTS_manual (AUD_CTS3) mechanism.
    } B;
} hw_hdmi_aud_cts1_t;
#endif

/*
 * constants & macros for entire HDMI_AUD_CTS1 register
 */
#define HW_HDMI_AUD_CTS1_ADDR      (REGS_HDMI_BASE + 0x3203)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AUD_CTS1           (*(volatile hw_hdmi_aud_cts1_t *) HW_HDMI_AUD_CTS1_ADDR)
#define HW_HDMI_AUD_CTS1_RD()      (HW_HDMI_AUD_CTS1.U)
#define HW_HDMI_AUD_CTS1_WR(v)     (HW_HDMI_AUD_CTS1.U = (v))
#define HW_HDMI_AUD_CTS1_SET(v)    (HW_HDMI_AUD_CTS1_WR(HW_HDMI_AUD_CTS1_RD() |  (v)))
#define HW_HDMI_AUD_CTS1_CLR(v)    (HW_HDMI_AUD_CTS1_WR(HW_HDMI_AUD_CTS1_RD() & ~(v)))
#define HW_HDMI_AUD_CTS1_TOG(v)    (HW_HDMI_AUD_CTS1_WR(HW_HDMI_AUD_CTS1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AUD_CTS1 bitfields
 */

/* --- Register HW_HDMI_AUD_CTS1, field AUDCTS (RW)
 *
 * HDMI Audio Clock Regenerator CTS calculated value. This value can be manually set using the
 * CTS_manual (AUD_CTS3) mechanism.
 */

#define BP_HDMI_AUD_CTS1_AUDCTS      0
#define BM_HDMI_AUD_CTS1_AUDCTS      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AUD_CTS1_AUDCTS(v)   ((((reg32_t) v) << 0) & BM_HDMI_AUD_CTS1_AUDCTS)
#else
#define BF_HDMI_AUD_CTS1_AUDCTS(v)   (((v) << 0) & BM_HDMI_AUD_CTS1_AUDCTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDCTS field to a new value.
#define BW_HDMI_AUD_CTS1_AUDCTS(v)   BF_CS1(HDMI_AUD_CTS1, AUDCTS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AUD_CTS2 - AUD_CTS2 (RW)
 *
 * For CTS expected values, refer to the HDMI 1.4a specification.   Address Offset: 0x3204  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDCTS : 8; //!< HDMI Audio Clock Regenerator CTS calculated value. This value can be manually set using the CTS_manual (AUD_CTS3) mechanism.
    } B;
} hw_hdmi_aud_cts2_t;
#endif

/*
 * constants & macros for entire HDMI_AUD_CTS2 register
 */
#define HW_HDMI_AUD_CTS2_ADDR      (REGS_HDMI_BASE + 0x3204)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AUD_CTS2           (*(volatile hw_hdmi_aud_cts2_t *) HW_HDMI_AUD_CTS2_ADDR)
#define HW_HDMI_AUD_CTS2_RD()      (HW_HDMI_AUD_CTS2.U)
#define HW_HDMI_AUD_CTS2_WR(v)     (HW_HDMI_AUD_CTS2.U = (v))
#define HW_HDMI_AUD_CTS2_SET(v)    (HW_HDMI_AUD_CTS2_WR(HW_HDMI_AUD_CTS2_RD() |  (v)))
#define HW_HDMI_AUD_CTS2_CLR(v)    (HW_HDMI_AUD_CTS2_WR(HW_HDMI_AUD_CTS2_RD() & ~(v)))
#define HW_HDMI_AUD_CTS2_TOG(v)    (HW_HDMI_AUD_CTS2_WR(HW_HDMI_AUD_CTS2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AUD_CTS2 bitfields
 */

/* --- Register HW_HDMI_AUD_CTS2, field AUDCTS (RW)
 *
 * HDMI Audio Clock Regenerator CTS calculated value. This value can be manually set using the
 * CTS_manual (AUD_CTS3) mechanism.
 */

#define BP_HDMI_AUD_CTS2_AUDCTS      0
#define BM_HDMI_AUD_CTS2_AUDCTS      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AUD_CTS2_AUDCTS(v)   ((((reg32_t) v) << 0) & BM_HDMI_AUD_CTS2_AUDCTS)
#else
#define BF_HDMI_AUD_CTS2_AUDCTS(v)   (((v) << 0) & BM_HDMI_AUD_CTS2_AUDCTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDCTS field to a new value.
#define BW_HDMI_AUD_CTS2_AUDCTS(v)   BF_CS1(HDMI_AUD_CTS2, AUDCTS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AUD_CTS3 - AUD_CTS3 (RW)
 *
 * For CTS expected values, refer to the HDMI 1.4a specification.   Address Offset: 0x3205  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char AUDCTS : 4; //!< HDMI Audio Clock Regenerator CTS calculated value. This value can be manually set using the CTS_manual (AUD_CTS3) mechanism.
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_aud_cts3_t;
#endif

/*
 * constants & macros for entire HDMI_AUD_CTS3 register
 */
#define HW_HDMI_AUD_CTS3_ADDR      (REGS_HDMI_BASE + 0x3205)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AUD_CTS3           (*(volatile hw_hdmi_aud_cts3_t *) HW_HDMI_AUD_CTS3_ADDR)
#define HW_HDMI_AUD_CTS3_RD()      (HW_HDMI_AUD_CTS3.U)
#define HW_HDMI_AUD_CTS3_WR(v)     (HW_HDMI_AUD_CTS3.U = (v))
#define HW_HDMI_AUD_CTS3_SET(v)    (HW_HDMI_AUD_CTS3_WR(HW_HDMI_AUD_CTS3_RD() |  (v)))
#define HW_HDMI_AUD_CTS3_CLR(v)    (HW_HDMI_AUD_CTS3_WR(HW_HDMI_AUD_CTS3_RD() & ~(v)))
#define HW_HDMI_AUD_CTS3_TOG(v)    (HW_HDMI_AUD_CTS3_WR(HW_HDMI_AUD_CTS3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AUD_CTS3 bitfields
 */

/* --- Register HW_HDMI_AUD_CTS3, field AUDCTS (RW)
 *
 * HDMI Audio Clock Regenerator CTS calculated value. This value can be manually set using the
 * CTS_manual (AUD_CTS3) mechanism.
 */

#define BP_HDMI_AUD_CTS3_AUDCTS      0
#define BM_HDMI_AUD_CTS3_AUDCTS      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AUD_CTS3_AUDCTS(v)   ((((reg32_t) v) << 0) & BM_HDMI_AUD_CTS3_AUDCTS)
#else
#define BF_HDMI_AUD_CTS3_AUDCTS(v)   (((v) << 0) & BM_HDMI_AUD_CTS3_AUDCTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDCTS field to a new value.
#define BW_HDMI_AUD_CTS3_AUDCTS(v)   BF_CS1(HDMI_AUD_CTS3, AUDCTS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_CONF0 - Audio DMA Start Register (RW)
 *
 * This register contains the software reset bit for the audio FIFOs. It also configures operating
 * modes of the AHB master.   Address Offset: 0x3600  Size: 8 bits  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BURST_MODE : 1; //!< 
        unsigned char INCR_TYPE : 2; //!< Forced size burst mode.
        unsigned char ENABLE_HLOCK : 1; //!< Enable request of locked burst AHB mechanism.
        unsigned char HBR : 1; //!< HBR packets enable. The HDMI TX sends the HBR packets. This bit is enabled when the audio frequency is higher than 192 KHz. If this bit is enabled, the number of channels configured in AHB_DMA_CONF1 is always 8.
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char SW_FIFO_RST : 1; //!< This is the software reset bit for the audio and FIFOs clear. Writing 0'b does not result in any action. Writing 1'b to this register resets all audio FIFOs. Reading from this register always returns 0'b.
    } B;
} hw_hdmi_ahb_dma_conf0_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_CONF0 register
 */
#define HW_HDMI_AHB_DMA_CONF0_ADDR      (REGS_HDMI_BASE + 0x3600)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_CONF0           (*(volatile hw_hdmi_ahb_dma_conf0_t *) HW_HDMI_AHB_DMA_CONF0_ADDR)
#define HW_HDMI_AHB_DMA_CONF0_RD()      (HW_HDMI_AHB_DMA_CONF0.U)
#define HW_HDMI_AHB_DMA_CONF0_WR(v)     (HW_HDMI_AHB_DMA_CONF0.U = (v))
#define HW_HDMI_AHB_DMA_CONF0_SET(v)    (HW_HDMI_AHB_DMA_CONF0_WR(HW_HDMI_AHB_DMA_CONF0_RD() |  (v)))
#define HW_HDMI_AHB_DMA_CONF0_CLR(v)    (HW_HDMI_AHB_DMA_CONF0_WR(HW_HDMI_AHB_DMA_CONF0_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_CONF0_TOG(v)    (HW_HDMI_AHB_DMA_CONF0_WR(HW_HDMI_AHB_DMA_CONF0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_CONF0 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_CONF0, field BURST_MODE (RW)
 *

 *
 * Values:
 * 1 - Forces the burst mode to be fixed beat incremental burst mode designated by the incr_type[1:0]
 *     signal.
 * 0 - Normal operation is unspecified length incremental burst. It corresponds to INCR AHB burst mode.
 */

#define BP_HDMI_AHB_DMA_CONF0_BURST_MODE      0
#define BM_HDMI_AHB_DMA_CONF0_BURST_MODE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF0_BURST_MODE(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_CONF0_BURST_MODE)
#else
#define BF_HDMI_AHB_DMA_CONF0_BURST_MODE(v)   (((v) << 0) & BM_HDMI_AHB_DMA_CONF0_BURST_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BURST_MODE field to a new value.
#define BW_HDMI_AHB_DMA_CONF0_BURST_MODE(v)   BF_CS1(HDMI_AHB_DMA_CONF0, BURST_MODE, v)
#endif


/* --- Register HW_HDMI_AHB_DMA_CONF0, field INCR_TYPE (RW)
 *
 * Forced size burst mode.
 *
 * Values:
 * 00 - Corresponds to INCR4 fixed four beat incremental AHB burst mode. Only valid when burst_mode is high.
 * 01 - Corresponds to INCR8 fixed eight beat incremental AHB burst mode. Only valid when burst_mode is
 *     high.
 * 10 - Corresponds to INCR16 fixed 16 beat incremental AHB burst mode. Only valid when burst_mode is high.
 * 11 - Corresponds to INCR16 fixed 16 beat incremental AHB burst mode. Only valid when burst_mode is high.
 */

#define BP_HDMI_AHB_DMA_CONF0_INCR_TYPE      1
#define BM_HDMI_AHB_DMA_CONF0_INCR_TYPE      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF0_INCR_TYPE(v)   ((((reg32_t) v) << 1) & BM_HDMI_AHB_DMA_CONF0_INCR_TYPE)
#else
#define BF_HDMI_AHB_DMA_CONF0_INCR_TYPE(v)   (((v) << 1) & BM_HDMI_AHB_DMA_CONF0_INCR_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INCR_TYPE field to a new value.
#define BW_HDMI_AHB_DMA_CONF0_INCR_TYPE(v)   BF_CS1(HDMI_AHB_DMA_CONF0, INCR_TYPE, v)
#endif


/* --- Register HW_HDMI_AHB_DMA_CONF0, field ENABLE_HLOCK (RW)
 *
 * Enable request of locked burst AHB mechanism.
 *
 * Values:
 * 1 - Enables the usage of ohlock for master request to arbiter of a locked complete burst.\
 * 0 - Disables request of locked burst AHB mechanism
 */

#define BP_HDMI_AHB_DMA_CONF0_ENABLE_HLOCK      3
#define BM_HDMI_AHB_DMA_CONF0_ENABLE_HLOCK      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF0_ENABLE_HLOCK(v)   ((((reg32_t) v) << 3) & BM_HDMI_AHB_DMA_CONF0_ENABLE_HLOCK)
#else
#define BF_HDMI_AHB_DMA_CONF0_ENABLE_HLOCK(v)   (((v) << 3) & BM_HDMI_AHB_DMA_CONF0_ENABLE_HLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_HLOCK field to a new value.
#define BW_HDMI_AHB_DMA_CONF0_ENABLE_HLOCK(v)   BF_CS1(HDMI_AHB_DMA_CONF0, ENABLE_HLOCK, v)
#endif


/* --- Register HW_HDMI_AHB_DMA_CONF0, field HBR (RW)
 *
 * HBR packets enable. The HDMI TX sends the HBR packets. This bit is enabled when the audio
 * frequency is higher than 192 KHz. If this bit is enabled, the number of channels configured in
 * AHB_DMA_CONF1 is always 8.
 */

#define BP_HDMI_AHB_DMA_CONF0_HBR      4
#define BM_HDMI_AHB_DMA_CONF0_HBR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF0_HBR(v)   ((((reg32_t) v) << 4) & BM_HDMI_AHB_DMA_CONF0_HBR)
#else
#define BF_HDMI_AHB_DMA_CONF0_HBR(v)   (((v) << 4) & BM_HDMI_AHB_DMA_CONF0_HBR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBR field to a new value.
#define BW_HDMI_AHB_DMA_CONF0_HBR(v)   BF_CS1(HDMI_AHB_DMA_CONF0, HBR, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_CONF0, field SW_FIFO_RST (RW)
 *
 * This is the software reset bit for the audio and FIFOs clear. Writing 0'b does not result in any
 * action. Writing 1'b to this register resets all audio FIFOs. Reading from this register always
 * returns 0'b.
 */

#define BP_HDMI_AHB_DMA_CONF0_SW_FIFO_RST      7
#define BM_HDMI_AHB_DMA_CONF0_SW_FIFO_RST      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF0_SW_FIFO_RST(v)   ((((reg32_t) v) << 7) & BM_HDMI_AHB_DMA_CONF0_SW_FIFO_RST)
#else
#define BF_HDMI_AHB_DMA_CONF0_SW_FIFO_RST(v)   (((v) << 7) & BM_HDMI_AHB_DMA_CONF0_SW_FIFO_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_FIFO_RST field to a new value.
#define BW_HDMI_AHB_DMA_CONF0_SW_FIFO_RST(v)   BF_CS1(HDMI_AHB_DMA_CONF0, SW_FIFO_RST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_START - AHB_DMA_START (RW)
 *
 * The data_ buffer_ready bit field signals the AHB audio DMA to start accessing system memory in
 * order to fetch data samples to store in the FIFO. After the operation starts, a new request for a
 * DMA start is ignored until the DMA is stopped or it reaches the end address. Only in one of these
 * situations will a new start request be acknowledged.  The first DMA burst request after
 * data_buffer_ready configuration uses the initial_addr[31:0] as the ohaddr[31:0] and the
 * mburstlength[10:0] = AUDIO_FIFO_DEPTH if AUDIO_FIFO_DEPTH < 1024 or mburstlength[10:0] = 1024 if
 * AUDIO_FIFO_DEPTH >= 1024.   Address Offset: 0x3601  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DATA_BUFFER_READY : 1; //!< Data buffer ready
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_ahb_dma_start_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_START register
 */
#define HW_HDMI_AHB_DMA_START_ADDR      (REGS_HDMI_BASE + 0x3601)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_START           (*(volatile hw_hdmi_ahb_dma_start_t *) HW_HDMI_AHB_DMA_START_ADDR)
#define HW_HDMI_AHB_DMA_START_RD()      (HW_HDMI_AHB_DMA_START.U)
#define HW_HDMI_AHB_DMA_START_WR(v)     (HW_HDMI_AHB_DMA_START.U = (v))
#define HW_HDMI_AHB_DMA_START_SET(v)    (HW_HDMI_AHB_DMA_START_WR(HW_HDMI_AHB_DMA_START_RD() |  (v)))
#define HW_HDMI_AHB_DMA_START_CLR(v)    (HW_HDMI_AHB_DMA_START_WR(HW_HDMI_AHB_DMA_START_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_START_TOG(v)    (HW_HDMI_AHB_DMA_START_WR(HW_HDMI_AHB_DMA_START_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_START bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_START, field DATA_BUFFER_READY (RW)
 *
 * Data buffer ready
 */

#define BP_HDMI_AHB_DMA_START_DATA_BUFFER_READY      0
#define BM_HDMI_AHB_DMA_START_DATA_BUFFER_READY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_START_DATA_BUFFER_READY(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_START_DATA_BUFFER_READY)
#else
#define BF_HDMI_AHB_DMA_START_DATA_BUFFER_READY(v)   (((v) << 0) & BM_HDMI_AHB_DMA_START_DATA_BUFFER_READY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_BUFFER_READY field to a new value.
#define BW_HDMI_AHB_DMA_START_DATA_BUFFER_READY(v)   BF_CS1(HDMI_AHB_DMA_START, DATA_BUFFER_READY, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STOP - Audio DMA Stop Register (RW)
 *
 * The stop_dma_transaction bit field signals the AHB audio DMA to stop current memory access. After
 * it stops, if a new start DMA operation is requested, the DMA engine restarts the memory access
 * assuming the initial_addr[31:0] is programmed at AHB_DMA_STRADDR0 to AHB_DMA_STRADDR3.   Address
 * Offset: 0x3602  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char STOP_DMA_TRANSACTION : 1; //!< Stop DMA transaction
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_ahb_dma_stop_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STOP register
 */
#define HW_HDMI_AHB_DMA_STOP_ADDR      (REGS_HDMI_BASE + 0x3602)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STOP           (*(volatile hw_hdmi_ahb_dma_stop_t *) HW_HDMI_AHB_DMA_STOP_ADDR)
#define HW_HDMI_AHB_DMA_STOP_RD()      (HW_HDMI_AHB_DMA_STOP.U)
#define HW_HDMI_AHB_DMA_STOP_WR(v)     (HW_HDMI_AHB_DMA_STOP.U = (v))
#define HW_HDMI_AHB_DMA_STOP_SET(v)    (HW_HDMI_AHB_DMA_STOP_WR(HW_HDMI_AHB_DMA_STOP_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STOP_CLR(v)    (HW_HDMI_AHB_DMA_STOP_WR(HW_HDMI_AHB_DMA_STOP_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STOP_TOG(v)    (HW_HDMI_AHB_DMA_STOP_WR(HW_HDMI_AHB_DMA_STOP_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STOP bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STOP, field STOP_DMA_TRANSACTION (RW)
 *
 * Stop DMA transaction
 */

#define BP_HDMI_AHB_DMA_STOP_STOP_DMA_TRANSACTION      0
#define BM_HDMI_AHB_DMA_STOP_STOP_DMA_TRANSACTION      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STOP_STOP_DMA_TRANSACTION(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STOP_STOP_DMA_TRANSACTION)
#else
#define BF_HDMI_AHB_DMA_STOP_STOP_DMA_TRANSACTION(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STOP_STOP_DMA_TRANSACTION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STOP_DMA_TRANSACTION field to a new value.
#define BW_HDMI_AHB_DMA_STOP_STOP_DMA_TRANSACTION(v)   BF_CS1(HDMI_AHB_DMA_STOP, STOP_DMA_TRANSACTION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_THRSLD - Audio DMA FIFO Threshold Register (RW)
 *
 * This register defines the FIFO medium threshold occupation value.  After the AHB master
 * successfully completes a burst transaction, the FIFO may stay remain full until the data fetch
 * interface requests samples. The sample request from the FIFO using the data fetch mechanism drops
 * the number of samples stored in the audio FIFO.  As soon as the number of samples in the FIFO
 * drops lower than the fifo_threshold[7:0], the DMA engine requests a new burst of samples to the
 * AHB master with a size (mburstlength[10:0]) equal to AUDIO_FIFO_DEPTH minus fifo_threshold[7:0].
 * Therefore, the fifo_threshold[7:0] is the medium number of samples that should be available in
 * the audio FIFO across the DMA operation.   Address Offset: 0x3603  Size: 8 bits  Value after
 * Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FIFO_THRESHOLD : 8; //!< FIFO medium threshold occupation value
    } B;
} hw_hdmi_ahb_dma_thrsld_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_THRSLD register
 */
#define HW_HDMI_AHB_DMA_THRSLD_ADDR      (REGS_HDMI_BASE + 0x3603)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_THRSLD           (*(volatile hw_hdmi_ahb_dma_thrsld_t *) HW_HDMI_AHB_DMA_THRSLD_ADDR)
#define HW_HDMI_AHB_DMA_THRSLD_RD()      (HW_HDMI_AHB_DMA_THRSLD.U)
#define HW_HDMI_AHB_DMA_THRSLD_WR(v)     (HW_HDMI_AHB_DMA_THRSLD.U = (v))
#define HW_HDMI_AHB_DMA_THRSLD_SET(v)    (HW_HDMI_AHB_DMA_THRSLD_WR(HW_HDMI_AHB_DMA_THRSLD_RD() |  (v)))
#define HW_HDMI_AHB_DMA_THRSLD_CLR(v)    (HW_HDMI_AHB_DMA_THRSLD_WR(HW_HDMI_AHB_DMA_THRSLD_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_THRSLD_TOG(v)    (HW_HDMI_AHB_DMA_THRSLD_WR(HW_HDMI_AHB_DMA_THRSLD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_THRSLD bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_THRSLD, field FIFO_THRESHOLD (RW)
 *
 * FIFO medium threshold occupation value
 */

#define BP_HDMI_AHB_DMA_THRSLD_FIFO_THRESHOLD      0
#define BM_HDMI_AHB_DMA_THRSLD_FIFO_THRESHOLD      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_THRSLD_FIFO_THRESHOLD(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_THRSLD_FIFO_THRESHOLD)
#else
#define BF_HDMI_AHB_DMA_THRSLD_FIFO_THRESHOLD(v)   (((v) << 0) & BM_HDMI_AHB_DMA_THRSLD_FIFO_THRESHOLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_THRESHOLD field to a new value.
#define BW_HDMI_AHB_DMA_THRSLD_FIFO_THRESHOLD(v)   BF_CS1(HDMI_AHB_DMA_THRSLD, FIFO_THRESHOLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STRADDR0 - Audio DMA Start Address Register 0 (RW)
 *
 * These registers define the initial_addr[31:0] used to initiate the DMA burst read transactions
 * upon data_buffer_ready configuration.   Address Offset: 0x3604 to 0x3607  Size: 8 bits per
 * register  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INITIAL_ADDR : 8; //!< Defines init_addr[7:0] for bits 7-0 to initiate DMA burst transactions
    } B;
} hw_hdmi_ahb_dma_straddr0_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STRADDR0 register
 */
#define HW_HDMI_AHB_DMA_STRADDR0_ADDR      (REGS_HDMI_BASE + 0x3604)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STRADDR0           (*(volatile hw_hdmi_ahb_dma_straddr0_t *) HW_HDMI_AHB_DMA_STRADDR0_ADDR)
#define HW_HDMI_AHB_DMA_STRADDR0_RD()      (HW_HDMI_AHB_DMA_STRADDR0.U)
#define HW_HDMI_AHB_DMA_STRADDR0_WR(v)     (HW_HDMI_AHB_DMA_STRADDR0.U = (v))
#define HW_HDMI_AHB_DMA_STRADDR0_SET(v)    (HW_HDMI_AHB_DMA_STRADDR0_WR(HW_HDMI_AHB_DMA_STRADDR0_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STRADDR0_CLR(v)    (HW_HDMI_AHB_DMA_STRADDR0_WR(HW_HDMI_AHB_DMA_STRADDR0_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STRADDR0_TOG(v)    (HW_HDMI_AHB_DMA_STRADDR0_WR(HW_HDMI_AHB_DMA_STRADDR0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STRADDR0 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STRADDR0, field INITIAL_ADDR (RW)
 *
 * Defines init_addr[7:0] for bits 7-0 to initiate DMA burst transactions
 */

#define BP_HDMI_AHB_DMA_STRADDR0_INITIAL_ADDR      0
#define BM_HDMI_AHB_DMA_STRADDR0_INITIAL_ADDR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STRADDR0_INITIAL_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STRADDR0_INITIAL_ADDR)
#else
#define BF_HDMI_AHB_DMA_STRADDR0_INITIAL_ADDR(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STRADDR0_INITIAL_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INITIAL_ADDR field to a new value.
#define BW_HDMI_AHB_DMA_STRADDR0_INITIAL_ADDR(v)   BF_CS1(HDMI_AHB_DMA_STRADDR0, INITIAL_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STRADDR1 - Audio DMA Start Address Register 1 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INITIAL_ADDR : 8; //!< Defines init_addr[15:8] for bits 7-0 to initiate DMA burst transactions
    } B;
} hw_hdmi_ahb_dma_straddr1_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STRADDR1 register
 */
#define HW_HDMI_AHB_DMA_STRADDR1_ADDR      (REGS_HDMI_BASE + 0x3605)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STRADDR1           (*(volatile hw_hdmi_ahb_dma_straddr1_t *) HW_HDMI_AHB_DMA_STRADDR1_ADDR)
#define HW_HDMI_AHB_DMA_STRADDR1_RD()      (HW_HDMI_AHB_DMA_STRADDR1.U)
#define HW_HDMI_AHB_DMA_STRADDR1_WR(v)     (HW_HDMI_AHB_DMA_STRADDR1.U = (v))
#define HW_HDMI_AHB_DMA_STRADDR1_SET(v)    (HW_HDMI_AHB_DMA_STRADDR1_WR(HW_HDMI_AHB_DMA_STRADDR1_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STRADDR1_CLR(v)    (HW_HDMI_AHB_DMA_STRADDR1_WR(HW_HDMI_AHB_DMA_STRADDR1_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STRADDR1_TOG(v)    (HW_HDMI_AHB_DMA_STRADDR1_WR(HW_HDMI_AHB_DMA_STRADDR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STRADDR1 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STRADDR1, field INITIAL_ADDR (RW)
 *
 * Defines init_addr[15:8] for bits 7-0 to initiate DMA burst transactions
 */

#define BP_HDMI_AHB_DMA_STRADDR1_INITIAL_ADDR      0
#define BM_HDMI_AHB_DMA_STRADDR1_INITIAL_ADDR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STRADDR1_INITIAL_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STRADDR1_INITIAL_ADDR)
#else
#define BF_HDMI_AHB_DMA_STRADDR1_INITIAL_ADDR(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STRADDR1_INITIAL_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INITIAL_ADDR field to a new value.
#define BW_HDMI_AHB_DMA_STRADDR1_INITIAL_ADDR(v)   BF_CS1(HDMI_AHB_DMA_STRADDR1, INITIAL_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STRADDR2 - Audio DMA Start Address Register 2 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INITIAL_ADDR : 8; //!< Defines init_addr[23:16] for bits 7-0 to initiate DMA burst transactions
    } B;
} hw_hdmi_ahb_dma_straddr2_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STRADDR2 register
 */
#define HW_HDMI_AHB_DMA_STRADDR2_ADDR      (REGS_HDMI_BASE + 0x3606)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STRADDR2           (*(volatile hw_hdmi_ahb_dma_straddr2_t *) HW_HDMI_AHB_DMA_STRADDR2_ADDR)
#define HW_HDMI_AHB_DMA_STRADDR2_RD()      (HW_HDMI_AHB_DMA_STRADDR2.U)
#define HW_HDMI_AHB_DMA_STRADDR2_WR(v)     (HW_HDMI_AHB_DMA_STRADDR2.U = (v))
#define HW_HDMI_AHB_DMA_STRADDR2_SET(v)    (HW_HDMI_AHB_DMA_STRADDR2_WR(HW_HDMI_AHB_DMA_STRADDR2_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STRADDR2_CLR(v)    (HW_HDMI_AHB_DMA_STRADDR2_WR(HW_HDMI_AHB_DMA_STRADDR2_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STRADDR2_TOG(v)    (HW_HDMI_AHB_DMA_STRADDR2_WR(HW_HDMI_AHB_DMA_STRADDR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STRADDR2 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STRADDR2, field INITIAL_ADDR (RW)
 *
 * Defines init_addr[23:16] for bits 7-0 to initiate DMA burst transactions
 */

#define BP_HDMI_AHB_DMA_STRADDR2_INITIAL_ADDR      0
#define BM_HDMI_AHB_DMA_STRADDR2_INITIAL_ADDR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STRADDR2_INITIAL_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STRADDR2_INITIAL_ADDR)
#else
#define BF_HDMI_AHB_DMA_STRADDR2_INITIAL_ADDR(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STRADDR2_INITIAL_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INITIAL_ADDR field to a new value.
#define BW_HDMI_AHB_DMA_STRADDR2_INITIAL_ADDR(v)   BF_CS1(HDMI_AHB_DMA_STRADDR2, INITIAL_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STRADDR3 - Audio DMA Start Address Register 3 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INITIAL_ADDR : 8; //!< Defines init_addr[31:24] for bits 7-0 to initiate DMA burst transactions
    } B;
} hw_hdmi_ahb_dma_straddr3_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STRADDR3 register
 */
#define HW_HDMI_AHB_DMA_STRADDR3_ADDR      (REGS_HDMI_BASE + 0x3607)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STRADDR3           (*(volatile hw_hdmi_ahb_dma_straddr3_t *) HW_HDMI_AHB_DMA_STRADDR3_ADDR)
#define HW_HDMI_AHB_DMA_STRADDR3_RD()      (HW_HDMI_AHB_DMA_STRADDR3.U)
#define HW_HDMI_AHB_DMA_STRADDR3_WR(v)     (HW_HDMI_AHB_DMA_STRADDR3.U = (v))
#define HW_HDMI_AHB_DMA_STRADDR3_SET(v)    (HW_HDMI_AHB_DMA_STRADDR3_WR(HW_HDMI_AHB_DMA_STRADDR3_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STRADDR3_CLR(v)    (HW_HDMI_AHB_DMA_STRADDR3_WR(HW_HDMI_AHB_DMA_STRADDR3_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STRADDR3_TOG(v)    (HW_HDMI_AHB_DMA_STRADDR3_WR(HW_HDMI_AHB_DMA_STRADDR3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STRADDR3 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STRADDR3, field INITIAL_ADDR (RW)
 *
 * Defines init_addr[31:24] for bits 7-0 to initiate DMA burst transactions
 */

#define BP_HDMI_AHB_DMA_STRADDR3_INITIAL_ADDR      0
#define BM_HDMI_AHB_DMA_STRADDR3_INITIAL_ADDR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STRADDR3_INITIAL_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STRADDR3_INITIAL_ADDR)
#else
#define BF_HDMI_AHB_DMA_STRADDR3_INITIAL_ADDR(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STRADDR3_INITIAL_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INITIAL_ADDR field to a new value.
#define BW_HDMI_AHB_DMA_STRADDR3_INITIAL_ADDR(v)   BF_CS1(HDMI_AHB_DMA_STRADDR3, INITIAL_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STPADDR0 - Audio DMA Stop Address Register 0 (RW)
 *
 * This registers define the final_addr[31:0] used as the final point to the DMA burst read
 * transactions.  Upon data_buffer_ready configuration, the DMA engine starts requesting burst reads
 * from the external system memory. Each burst read can have a maximum theoretical length of 1024
 * words (due to the AMBA AHB specification restriction). As an example, if the first burst
 * transaction of the AHB audio DMA has a length of 16, then the second burst starts at address
 * ohaddr[31:0] = initial_addr[31:0] + 16 and has a length of mburstlength[10:0] = AUDIO_FIFO_DEPTH
 * - fifo_threshold[7:0].  The DMA engine is responsible for incrementing the burst starting address
 * and defining its corresponding burst length to reach the final_addr[31:0] address. The last burst
 * request issued by the DMA engine takes into account that it should only request data until the
 * final_addr[31:0] address (included) and for that should calculate the correct burst length.
 * After reaching the final_addr[31:0] address, the done interrupt is active to signal completion of
 * DMA operation.   Address Offset: 0x3608 to 0x360B  Size: 8 bits per register  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FINAL_ADDR : 8; //!< Defines final_addr[7:0] for bits 7-0 to initiate DMA burst transactions
    } B;
} hw_hdmi_ahb_dma_stpaddr0_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STPADDR0 register
 */
#define HW_HDMI_AHB_DMA_STPADDR0_ADDR      (REGS_HDMI_BASE + 0x3608)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STPADDR0           (*(volatile hw_hdmi_ahb_dma_stpaddr0_t *) HW_HDMI_AHB_DMA_STPADDR0_ADDR)
#define HW_HDMI_AHB_DMA_STPADDR0_RD()      (HW_HDMI_AHB_DMA_STPADDR0.U)
#define HW_HDMI_AHB_DMA_STPADDR0_WR(v)     (HW_HDMI_AHB_DMA_STPADDR0.U = (v))
#define HW_HDMI_AHB_DMA_STPADDR0_SET(v)    (HW_HDMI_AHB_DMA_STPADDR0_WR(HW_HDMI_AHB_DMA_STPADDR0_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STPADDR0_CLR(v)    (HW_HDMI_AHB_DMA_STPADDR0_WR(HW_HDMI_AHB_DMA_STPADDR0_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STPADDR0_TOG(v)    (HW_HDMI_AHB_DMA_STPADDR0_WR(HW_HDMI_AHB_DMA_STPADDR0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STPADDR0 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STPADDR0, field FINAL_ADDR (RW)
 *
 * Defines final_addr[7:0] for bits 7-0 to initiate DMA burst transactions
 */

#define BP_HDMI_AHB_DMA_STPADDR0_FINAL_ADDR      0
#define BM_HDMI_AHB_DMA_STPADDR0_FINAL_ADDR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STPADDR0_FINAL_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STPADDR0_FINAL_ADDR)
#else
#define BF_HDMI_AHB_DMA_STPADDR0_FINAL_ADDR(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STPADDR0_FINAL_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FINAL_ADDR field to a new value.
#define BW_HDMI_AHB_DMA_STPADDR0_FINAL_ADDR(v)   BF_CS1(HDMI_AHB_DMA_STPADDR0, FINAL_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STPADDR1 - Audio DMA Stop Address Register 1 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FINAL_ADDR : 8; //!< Defines final_addr[15:8] for bits 7-0 to initiate DMA burst transactions
    } B;
} hw_hdmi_ahb_dma_stpaddr1_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STPADDR1 register
 */
#define HW_HDMI_AHB_DMA_STPADDR1_ADDR      (REGS_HDMI_BASE + 0x3609)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STPADDR1           (*(volatile hw_hdmi_ahb_dma_stpaddr1_t *) HW_HDMI_AHB_DMA_STPADDR1_ADDR)
#define HW_HDMI_AHB_DMA_STPADDR1_RD()      (HW_HDMI_AHB_DMA_STPADDR1.U)
#define HW_HDMI_AHB_DMA_STPADDR1_WR(v)     (HW_HDMI_AHB_DMA_STPADDR1.U = (v))
#define HW_HDMI_AHB_DMA_STPADDR1_SET(v)    (HW_HDMI_AHB_DMA_STPADDR1_WR(HW_HDMI_AHB_DMA_STPADDR1_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STPADDR1_CLR(v)    (HW_HDMI_AHB_DMA_STPADDR1_WR(HW_HDMI_AHB_DMA_STPADDR1_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STPADDR1_TOG(v)    (HW_HDMI_AHB_DMA_STPADDR1_WR(HW_HDMI_AHB_DMA_STPADDR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STPADDR1 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STPADDR1, field FINAL_ADDR (RW)
 *
 * Defines final_addr[15:8] for bits 7-0 to initiate DMA burst transactions
 */

#define BP_HDMI_AHB_DMA_STPADDR1_FINAL_ADDR      0
#define BM_HDMI_AHB_DMA_STPADDR1_FINAL_ADDR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STPADDR1_FINAL_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STPADDR1_FINAL_ADDR)
#else
#define BF_HDMI_AHB_DMA_STPADDR1_FINAL_ADDR(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STPADDR1_FINAL_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FINAL_ADDR field to a new value.
#define BW_HDMI_AHB_DMA_STPADDR1_FINAL_ADDR(v)   BF_CS1(HDMI_AHB_DMA_STPADDR1, FINAL_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STPADDR2 - Audio DMA Stop Address Register 2 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FINAL_ADDR : 8; //!< Defines final_addr[23:16] for bits 7-0 to initiate DMA burst transactions
    } B;
} hw_hdmi_ahb_dma_stpaddr2_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STPADDR2 register
 */
#define HW_HDMI_AHB_DMA_STPADDR2_ADDR      (REGS_HDMI_BASE + 0x360a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STPADDR2           (*(volatile hw_hdmi_ahb_dma_stpaddr2_t *) HW_HDMI_AHB_DMA_STPADDR2_ADDR)
#define HW_HDMI_AHB_DMA_STPADDR2_RD()      (HW_HDMI_AHB_DMA_STPADDR2.U)
#define HW_HDMI_AHB_DMA_STPADDR2_WR(v)     (HW_HDMI_AHB_DMA_STPADDR2.U = (v))
#define HW_HDMI_AHB_DMA_STPADDR2_SET(v)    (HW_HDMI_AHB_DMA_STPADDR2_WR(HW_HDMI_AHB_DMA_STPADDR2_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STPADDR2_CLR(v)    (HW_HDMI_AHB_DMA_STPADDR2_WR(HW_HDMI_AHB_DMA_STPADDR2_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STPADDR2_TOG(v)    (HW_HDMI_AHB_DMA_STPADDR2_WR(HW_HDMI_AHB_DMA_STPADDR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STPADDR2 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STPADDR2, field FINAL_ADDR (RW)
 *
 * Defines final_addr[23:16] for bits 7-0 to initiate DMA burst transactions
 */

#define BP_HDMI_AHB_DMA_STPADDR2_FINAL_ADDR      0
#define BM_HDMI_AHB_DMA_STPADDR2_FINAL_ADDR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STPADDR2_FINAL_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STPADDR2_FINAL_ADDR)
#else
#define BF_HDMI_AHB_DMA_STPADDR2_FINAL_ADDR(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STPADDR2_FINAL_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FINAL_ADDR field to a new value.
#define BW_HDMI_AHB_DMA_STPADDR2_FINAL_ADDR(v)   BF_CS1(HDMI_AHB_DMA_STPADDR2, FINAL_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STPADDR3 - Audio DMA Stop Address Register 3 (RW)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FINAL_ADDR : 8; //!< Defines final_addr[31:24] for bits 7-0 to initiate DMA burst transactions
    } B;
} hw_hdmi_ahb_dma_stpaddr3_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STPADDR3 register
 */
#define HW_HDMI_AHB_DMA_STPADDR3_ADDR      (REGS_HDMI_BASE + 0x360b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STPADDR3           (*(volatile hw_hdmi_ahb_dma_stpaddr3_t *) HW_HDMI_AHB_DMA_STPADDR3_ADDR)
#define HW_HDMI_AHB_DMA_STPADDR3_RD()      (HW_HDMI_AHB_DMA_STPADDR3.U)
#define HW_HDMI_AHB_DMA_STPADDR3_WR(v)     (HW_HDMI_AHB_DMA_STPADDR3.U = (v))
#define HW_HDMI_AHB_DMA_STPADDR3_SET(v)    (HW_HDMI_AHB_DMA_STPADDR3_WR(HW_HDMI_AHB_DMA_STPADDR3_RD() |  (v)))
#define HW_HDMI_AHB_DMA_STPADDR3_CLR(v)    (HW_HDMI_AHB_DMA_STPADDR3_WR(HW_HDMI_AHB_DMA_STPADDR3_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_STPADDR3_TOG(v)    (HW_HDMI_AHB_DMA_STPADDR3_WR(HW_HDMI_AHB_DMA_STPADDR3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STPADDR3 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STPADDR3, field FINAL_ADDR (RW)
 *
 * Defines final_addr[31:24] for bits 7-0 to initiate DMA burst transactions
 */

#define BP_HDMI_AHB_DMA_STPADDR3_FINAL_ADDR      0
#define BM_HDMI_AHB_DMA_STPADDR3_FINAL_ADDR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_STPADDR3_FINAL_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_STPADDR3_FINAL_ADDR)
#else
#define BF_HDMI_AHB_DMA_STPADDR3_FINAL_ADDR(v)   (((v) << 0) & BM_HDMI_AHB_DMA_STPADDR3_FINAL_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FINAL_ADDR field to a new value.
#define BW_HDMI_AHB_DMA_STPADDR3_FINAL_ADDR(v)   BF_CS1(HDMI_AHB_DMA_STPADDR3, FINAL_ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_BSTADDR0 - Audio DMA Burst Start Address Register 0 (RO)
 *
 * This read-only register composes the start address of the current burst operation. As an example,
 * if the first burst transaction of the AHB audio DMA as a length of 16, then the second burst
 * should start at address ohaddr[31:0] = initial_addr[31:0] + 16. While this burst is being
 * executed, burst_start_addr[31:0] = haddr[31:0] = initial_addr[31:0] + 16.   Address Offset:
 * 0x360C to 0x360F  Size: 8 bits per register  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BURST_START : 8; //!< Start address for the current burst operation
    } B;
} hw_hdmi_ahb_dma_bstaddr0_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_BSTADDR0 register
 */
#define HW_HDMI_AHB_DMA_BSTADDR0_ADDR      (REGS_HDMI_BASE + 0x360c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_BSTADDR0           (*(volatile hw_hdmi_ahb_dma_bstaddr0_t *) HW_HDMI_AHB_DMA_BSTADDR0_ADDR)
#define HW_HDMI_AHB_DMA_BSTADDR0_RD()      (HW_HDMI_AHB_DMA_BSTADDR0.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_BSTADDR0 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_BSTADDR0, field BURST_START (RO)
 *
 * Start address for the current burst operation
 */

#define BP_HDMI_AHB_DMA_BSTADDR0_BURST_START      0
#define BM_HDMI_AHB_DMA_BSTADDR0_BURST_START      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_BSTADDR1 - Audio DMA Burst Start Address Register 1 (RO)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BURST_START : 8; //!< Start address for the current burst operation
    } B;
} hw_hdmi_ahb_dma_bstaddr1_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_BSTADDR1 register
 */
#define HW_HDMI_AHB_DMA_BSTADDR1_ADDR      (REGS_HDMI_BASE + 0x360d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_BSTADDR1           (*(volatile hw_hdmi_ahb_dma_bstaddr1_t *) HW_HDMI_AHB_DMA_BSTADDR1_ADDR)
#define HW_HDMI_AHB_DMA_BSTADDR1_RD()      (HW_HDMI_AHB_DMA_BSTADDR1.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_BSTADDR1 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_BSTADDR1, field BURST_START (RO)
 *
 * Start address for the current burst operation
 */

#define BP_HDMI_AHB_DMA_BSTADDR1_BURST_START      0
#define BM_HDMI_AHB_DMA_BSTADDR1_BURST_START      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_BSTADDR2 - Audio DMA Burst Start Address Register 2 (RO)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BURST_START : 8; //!< Start address for the current burst operation
    } B;
} hw_hdmi_ahb_dma_bstaddr2_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_BSTADDR2 register
 */
#define HW_HDMI_AHB_DMA_BSTADDR2_ADDR      (REGS_HDMI_BASE + 0x360e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_BSTADDR2           (*(volatile hw_hdmi_ahb_dma_bstaddr2_t *) HW_HDMI_AHB_DMA_BSTADDR2_ADDR)
#define HW_HDMI_AHB_DMA_BSTADDR2_RD()      (HW_HDMI_AHB_DMA_BSTADDR2.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_BSTADDR2 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_BSTADDR2, field BURST_START (RO)
 *
 * Start address for the current burst operation
 */

#define BP_HDMI_AHB_DMA_BSTADDR2_BURST_START      0
#define BM_HDMI_AHB_DMA_BSTADDR2_BURST_START      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_BSTADDR3 - Audio DMA Burst Start Address Register 3 (RO)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BURST_START : 8; //!< Start address for the current burst operation
    } B;
} hw_hdmi_ahb_dma_bstaddr3_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_BSTADDR3 register
 */
#define HW_HDMI_AHB_DMA_BSTADDR3_ADDR      (REGS_HDMI_BASE + 0x360f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_BSTADDR3           (*(volatile hw_hdmi_ahb_dma_bstaddr3_t *) HW_HDMI_AHB_DMA_BSTADDR3_ADDR)
#define HW_HDMI_AHB_DMA_BSTADDR3_RD()      (HW_HDMI_AHB_DMA_BSTADDR3.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_BSTADDR3 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_BSTADDR3, field BURST_START (RO)
 *
 * Start address for the current burst operation
 */

#define BP_HDMI_AHB_DMA_BSTADDR3_BURST_START      0
#define BM_HDMI_AHB_DMA_BSTADDR3_BURST_START      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_MBLENGTH0 - Audio DMA Burst Length Register 0 (RO)
 *
 * These registers hold the length of the current burst operation. As an example, if the first burst
 * transaction of the AHB audio DMA is a length of 8, then the second burst should start at address
 * ohaddr[31:0] = initial_addr[31:0] + 8. It will also have length mburstlength[10:0] =
 * AUDIO_FIFO_DEPTH - fifo_threshold[7:0] while this burst is being executed, mburstlength[10:0] =
 * AUDIO_FIFO_DEPTH - fifo_threshold[7:0].   Address Offset: 0x3610 to 0x3611  Size: 8 bits per
 * register  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char MBURSTLENGTH : 8; //!< Requested burst length
    } B;
} hw_hdmi_ahb_dma_mblength0_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_MBLENGTH0 register
 */
#define HW_HDMI_AHB_DMA_MBLENGTH0_ADDR      (REGS_HDMI_BASE + 0x3610)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_MBLENGTH0           (*(volatile hw_hdmi_ahb_dma_mblength0_t *) HW_HDMI_AHB_DMA_MBLENGTH0_ADDR)
#define HW_HDMI_AHB_DMA_MBLENGTH0_RD()      (HW_HDMI_AHB_DMA_MBLENGTH0.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_MBLENGTH0 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_MBLENGTH0, field MBURSTLENGTH (RO)
 *
 * Requested burst length
 */

#define BP_HDMI_AHB_DMA_MBLENGTH0_MBURSTLENGTH      0
#define BM_HDMI_AHB_DMA_MBLENGTH0_MBURSTLENGTH      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_MBLENGTH1 - Audio DMA Burst Length Register 1 (RO)
 *

 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char MBURSTLENGTH : 1; //!< Requested burst length
        unsigned char MBURSTLENGTH1 : 1; //!< Requested burst length
        unsigned char MBURSTLENGTH2 : 1; //!< Requested burst length
        unsigned char RESERVED0 : 5; //!< Reserved
    } B;
} hw_hdmi_ahb_dma_mblength1_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_MBLENGTH1 register
 */
#define HW_HDMI_AHB_DMA_MBLENGTH1_ADDR      (REGS_HDMI_BASE + 0x3611)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_MBLENGTH1           (*(volatile hw_hdmi_ahb_dma_mblength1_t *) HW_HDMI_AHB_DMA_MBLENGTH1_ADDR)
#define HW_HDMI_AHB_DMA_MBLENGTH1_RD()      (HW_HDMI_AHB_DMA_MBLENGTH1.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_MBLENGTH1 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_MBLENGTH1, field MBURSTLENGTH (RO)
 *
 * Requested burst length
 */

#define BP_HDMI_AHB_DMA_MBLENGTH1_MBURSTLENGTH      0
#define BM_HDMI_AHB_DMA_MBLENGTH1_MBURSTLENGTH      0x00000001

/* --- Register HW_HDMI_AHB_DMA_MBLENGTH1, field MBURSTLENGTH (RO)
 *
 * Requested burst length
 */

#define BP_HDMI_AHB_DMA_MBLENGTH1_MBURSTLENGTH      1
#define BM_HDMI_AHB_DMA_MBLENGTH1_MBURSTLENGTH      0x00000002

/* --- Register HW_HDMI_AHB_DMA_MBLENGTH1, field MBURSTLENGTH (RO)
 *
 * Requested burst length
 */

#define BP_HDMI_AHB_DMA_MBLENGTH1_MBURSTLENGTH      2
#define BM_HDMI_AHB_DMA_MBLENGTH1_MBURSTLENGTH      0x00000004

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_STAT - Audio DMA Interrupt Status Register (RO)
 *
 * This register contains the status bits of the following interrupts:   Address Offset: 0x3612
 * Size: 8 bits per register  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char STATFIFOEMPTY : 1; //!< Status of audio FIFO empty interrupt.
        unsigned char STATFIFOFULL : 1; //!< Status of audio FIFO full interrupt.
        unsigned char STATTHRFIFOEMPTY : 1; //!< Status of audio FIFO empty when audio FIFO has less than four samples.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char STATERROR : 1; //!< Status of error interrupt. Active when slave indicates error through the isresp[1:0].
        unsigned char STATLOSTOWNERSHIP : 1; //!< Status of master lost ownership when in burst transfer. Active when AHB master loses BUS ownership within the course of a burst transfer.
        unsigned char STATRETRYSPLIT : 1; //!< Status of retry/split interrupt. Active when AHB master receives a RETRY or SPLIT response from slave.
        unsigned char STATDONE : 1; //!< Status of DMA end of operation interrupt. Active when DMA engine reaches final_addr[15:0] or when stop DMA operation is activated.
    } B;
} hw_hdmi_ahb_dma_stat_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_STAT register
 */
#define HW_HDMI_AHB_DMA_STAT_ADDR      (REGS_HDMI_BASE + 0x3612)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_STAT           (*(volatile hw_hdmi_ahb_dma_stat_t *) HW_HDMI_AHB_DMA_STAT_ADDR)
#define HW_HDMI_AHB_DMA_STAT_RD()      (HW_HDMI_AHB_DMA_STAT.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_STAT bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_STAT, field STATFIFOEMPTY (RO)
 *
 * Status of audio FIFO empty interrupt.
 */

#define BP_HDMI_AHB_DMA_STAT_STATFIFOEMPTY      0
#define BM_HDMI_AHB_DMA_STAT_STATFIFOEMPTY      0x00000001

/* --- Register HW_HDMI_AHB_DMA_STAT, field STATFIFOFULL (RO)
 *
 * Status of audio FIFO full interrupt.
 */

#define BP_HDMI_AHB_DMA_STAT_STATFIFOFULL      1
#define BM_HDMI_AHB_DMA_STAT_STATFIFOFULL      0x00000002

/* --- Register HW_HDMI_AHB_DMA_STAT, field STATTHRFIFOEMPTY (RO)
 *
 * Status of audio FIFO empty when audio FIFO has less than four samples.
 */

#define BP_HDMI_AHB_DMA_STAT_STATTHRFIFOEMPTY      2
#define BM_HDMI_AHB_DMA_STAT_STATTHRFIFOEMPTY      0x00000004

/* --- Register HW_HDMI_AHB_DMA_STAT, field STATERROR (RO)
 *
 * Status of error interrupt. Active when slave indicates error through the isresp[1:0].
 */

#define BP_HDMI_AHB_DMA_STAT_STATERROR      4
#define BM_HDMI_AHB_DMA_STAT_STATERROR      0x00000010

/* --- Register HW_HDMI_AHB_DMA_STAT, field STATLOSTOWNERSHIP (RO)
 *
 * Status of master lost ownership when in burst transfer. Active when AHB master loses BUS
 * ownership within the course of a burst transfer.
 */

#define BP_HDMI_AHB_DMA_STAT_STATLOSTOWNERSHIP      5
#define BM_HDMI_AHB_DMA_STAT_STATLOSTOWNERSHIP      0x00000020

/* --- Register HW_HDMI_AHB_DMA_STAT, field STATRETRYSPLIT (RO)
 *
 * Status of retry/split interrupt. Active when AHB master receives a RETRY or SPLIT response from
 * slave.
 */

#define BP_HDMI_AHB_DMA_STAT_STATRETRYSPLIT      6
#define BM_HDMI_AHB_DMA_STAT_STATRETRYSPLIT      0x00000040

/* --- Register HW_HDMI_AHB_DMA_STAT, field STATDONE (RO)
 *
 * Status of DMA end of operation interrupt. Active when DMA engine reaches final_addr[15:0] or when
 * stop DMA operation is activated.
 */

#define BP_HDMI_AHB_DMA_STAT_STATDONE      7
#define BM_HDMI_AHB_DMA_STAT_STATDONE      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_INT - Audio DMA Interrupt Register (RO)
 *
 * This register contains the interrupt bits of the following interrupts:   Address Offset: 0x3613
 * Size: 8 bits per register  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INTFIFOEMPTY : 1; //!< Audio FIFO empty interrupt.
        unsigned char INTFIFOFULL : 1; //!< Audio FIFO full interrupt.
        unsigned char INTTHRFIFOEMPTY : 1; //!< Audio FIFO empty interrupt when audio FIFO has less than four samples.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char INTERROR : 1; //!< Error interrupt. Active when slave indicates error through the isresp[1:0].
        unsigned char INTLOSTOWNERSHIP : 1; //!< Master lost ownership interrupt when in burst transfer. Active when AHB master loses BUS ownership within the course of a burst transfer.
        unsigned char INTRETRYSPLIT : 1; //!< Retry/split interrupt. Active when AHB master receives a RETRY or SPLIT response from slave.
        unsigned char INTDONE : 1; //!< DMA end of operation interrupt. Active when DMA engine reaches final_addr[15:0] or when stop DMA operation is activated.
    } B;
} hw_hdmi_ahb_dma_int_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_INT register
 */
#define HW_HDMI_AHB_DMA_INT_ADDR      (REGS_HDMI_BASE + 0x3613)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_INT           (*(volatile hw_hdmi_ahb_dma_int_t *) HW_HDMI_AHB_DMA_INT_ADDR)
#define HW_HDMI_AHB_DMA_INT_RD()      (HW_HDMI_AHB_DMA_INT.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_INT bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_INT, field INTFIFOEMPTY (RO)
 *
 * Audio FIFO empty interrupt.
 */

#define BP_HDMI_AHB_DMA_INT_INTFIFOEMPTY      0
#define BM_HDMI_AHB_DMA_INT_INTFIFOEMPTY      0x00000001

/* --- Register HW_HDMI_AHB_DMA_INT, field INTFIFOFULL (RO)
 *
 * Audio FIFO full interrupt.
 */

#define BP_HDMI_AHB_DMA_INT_INTFIFOFULL      1
#define BM_HDMI_AHB_DMA_INT_INTFIFOFULL      0x00000002

/* --- Register HW_HDMI_AHB_DMA_INT, field INTTHRFIFOEMPTY (RO)
 *
 * Audio FIFO empty interrupt when audio FIFO has less than four samples.
 */

#define BP_HDMI_AHB_DMA_INT_INTTHRFIFOEMPTY      2
#define BM_HDMI_AHB_DMA_INT_INTTHRFIFOEMPTY      0x00000004

/* --- Register HW_HDMI_AHB_DMA_INT, field INTERROR (RO)
 *
 * Error interrupt. Active when slave indicates error through the isresp[1:0].
 */

#define BP_HDMI_AHB_DMA_INT_INTERROR      4
#define BM_HDMI_AHB_DMA_INT_INTERROR      0x00000010

/* --- Register HW_HDMI_AHB_DMA_INT, field INTLOSTOWNERSHIP (RO)
 *
 * Master lost ownership interrupt when in burst transfer. Active when AHB master loses BUS
 * ownership within the course of a burst transfer.
 */

#define BP_HDMI_AHB_DMA_INT_INTLOSTOWNERSHIP      5
#define BM_HDMI_AHB_DMA_INT_INTLOSTOWNERSHIP      0x00000020

/* --- Register HW_HDMI_AHB_DMA_INT, field INTRETRYSPLIT (RO)
 *
 * Retry/split interrupt. Active when AHB master receives a RETRY or SPLIT response from slave.
 */

#define BP_HDMI_AHB_DMA_INT_INTRETRYSPLIT      6
#define BM_HDMI_AHB_DMA_INT_INTRETRYSPLIT      0x00000040

/* --- Register HW_HDMI_AHB_DMA_INT, field INTDONE (RO)
 *
 * DMA end of operation interrupt. Active when DMA engine reaches final_addr[15:0] or when stop DMA
 * operation is activated.
 */

#define BP_HDMI_AHB_DMA_INT_INTDONE      7
#define BM_HDMI_AHB_DMA_INT_INTDONE      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_MASK - Audio DMA Mask Interrupt Register (RW)
 *
 * Mask for each of the interrupts present in the AHB audio DMA module. For usage information, see
 * ."   Address Offset: 0x3614  Size: 8 bits per register  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FIFO_EMPTY_MASK : 1; //!< Audio FIFO empty interrupt mask.
        unsigned char FIFO_FULL_MASK : 1; //!< Audio FIFO full interrupt mask.
        unsigned char FIFO_THREMPTY_MASK : 1; //!< Audio FIFO empty interrupt mask when audio FIFO has less than four samples.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char ERROR_MASK : 1; //!< Error interrupt mask. Active when slave indicates error through the isresp[1:0].
        unsigned char LOSTOWNERSHIP_MASK : 1; //!< Master lost ownership interrupt mask when in burst transfer. Active when AHB master loses BUS ownership within the course of a burst transfer.
        unsigned char RETRYSPLIT_MASK : 1; //!< Retry/split interrupt mask. Active when AHB master receives a RETRY or SPLIT response from slave.
        unsigned char DONE_MASK : 1; //!< DMA end of operation interrupt mask. Active when DMA engine reaches final_addr[15:0] or when stop DMA operation is activated.
    } B;
} hw_hdmi_ahb_dma_mask_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_MASK register
 */
#define HW_HDMI_AHB_DMA_MASK_ADDR      (REGS_HDMI_BASE + 0x3614)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_MASK           (*(volatile hw_hdmi_ahb_dma_mask_t *) HW_HDMI_AHB_DMA_MASK_ADDR)
#define HW_HDMI_AHB_DMA_MASK_RD()      (HW_HDMI_AHB_DMA_MASK.U)
#define HW_HDMI_AHB_DMA_MASK_WR(v)     (HW_HDMI_AHB_DMA_MASK.U = (v))
#define HW_HDMI_AHB_DMA_MASK_SET(v)    (HW_HDMI_AHB_DMA_MASK_WR(HW_HDMI_AHB_DMA_MASK_RD() |  (v)))
#define HW_HDMI_AHB_DMA_MASK_CLR(v)    (HW_HDMI_AHB_DMA_MASK_WR(HW_HDMI_AHB_DMA_MASK_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_MASK_TOG(v)    (HW_HDMI_AHB_DMA_MASK_WR(HW_HDMI_AHB_DMA_MASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_MASK bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_MASK, field FIFO_EMPTY_MASK (RW)
 *
 * Audio FIFO empty interrupt mask.
 */

#define BP_HDMI_AHB_DMA_MASK_FIFO_EMPTY_MASK      0
#define BM_HDMI_AHB_DMA_MASK_FIFO_EMPTY_MASK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_MASK_FIFO_EMPTY_MASK(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_MASK_FIFO_EMPTY_MASK)
#else
#define BF_HDMI_AHB_DMA_MASK_FIFO_EMPTY_MASK(v)   (((v) << 0) & BM_HDMI_AHB_DMA_MASK_FIFO_EMPTY_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_EMPTY_MASK field to a new value.
#define BW_HDMI_AHB_DMA_MASK_FIFO_EMPTY_MASK(v)   BF_CS1(HDMI_AHB_DMA_MASK, FIFO_EMPTY_MASK, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_MASK, field FIFO_FULL_MASK (RW)
 *
 * Audio FIFO full interrupt mask.
 */

#define BP_HDMI_AHB_DMA_MASK_FIFO_FULL_MASK      1
#define BM_HDMI_AHB_DMA_MASK_FIFO_FULL_MASK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_MASK_FIFO_FULL_MASK(v)   ((((reg32_t) v) << 1) & BM_HDMI_AHB_DMA_MASK_FIFO_FULL_MASK)
#else
#define BF_HDMI_AHB_DMA_MASK_FIFO_FULL_MASK(v)   (((v) << 1) & BM_HDMI_AHB_DMA_MASK_FIFO_FULL_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_FULL_MASK field to a new value.
#define BW_HDMI_AHB_DMA_MASK_FIFO_FULL_MASK(v)   BF_CS1(HDMI_AHB_DMA_MASK, FIFO_FULL_MASK, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_MASK, field FIFO_THREMPTY_MASK (RW)
 *
 * Audio FIFO empty interrupt mask when audio FIFO has less than four samples.
 */

#define BP_HDMI_AHB_DMA_MASK_FIFO_THREMPTY_MASK      2
#define BM_HDMI_AHB_DMA_MASK_FIFO_THREMPTY_MASK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_MASK_FIFO_THREMPTY_MASK(v)   ((((reg32_t) v) << 2) & BM_HDMI_AHB_DMA_MASK_FIFO_THREMPTY_MASK)
#else
#define BF_HDMI_AHB_DMA_MASK_FIFO_THREMPTY_MASK(v)   (((v) << 2) & BM_HDMI_AHB_DMA_MASK_FIFO_THREMPTY_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_THREMPTY_MASK field to a new value.
#define BW_HDMI_AHB_DMA_MASK_FIFO_THREMPTY_MASK(v)   BF_CS1(HDMI_AHB_DMA_MASK, FIFO_THREMPTY_MASK, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_MASK, field ERROR_MASK (RW)
 *
 * Error interrupt mask. Active when slave indicates error through the isresp[1:0].
 */

#define BP_HDMI_AHB_DMA_MASK_ERROR_MASK      4
#define BM_HDMI_AHB_DMA_MASK_ERROR_MASK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_MASK_ERROR_MASK(v)   ((((reg32_t) v) << 4) & BM_HDMI_AHB_DMA_MASK_ERROR_MASK)
#else
#define BF_HDMI_AHB_DMA_MASK_ERROR_MASK(v)   (((v) << 4) & BM_HDMI_AHB_DMA_MASK_ERROR_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_MASK field to a new value.
#define BW_HDMI_AHB_DMA_MASK_ERROR_MASK(v)   BF_CS1(HDMI_AHB_DMA_MASK, ERROR_MASK, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_MASK, field LOSTOWNERSHIP_MASK (RW)
 *
 * Master lost ownership interrupt mask when in burst transfer. Active when AHB master loses BUS
 * ownership within the course of a burst transfer.
 */

#define BP_HDMI_AHB_DMA_MASK_LOSTOWNERSHIP_MASK      5
#define BM_HDMI_AHB_DMA_MASK_LOSTOWNERSHIP_MASK      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_MASK_LOSTOWNERSHIP_MASK(v)   ((((reg32_t) v) << 5) & BM_HDMI_AHB_DMA_MASK_LOSTOWNERSHIP_MASK)
#else
#define BF_HDMI_AHB_DMA_MASK_LOSTOWNERSHIP_MASK(v)   (((v) << 5) & BM_HDMI_AHB_DMA_MASK_LOSTOWNERSHIP_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOSTOWNERSHIP_MASK field to a new value.
#define BW_HDMI_AHB_DMA_MASK_LOSTOWNERSHIP_MASK(v)   BF_CS1(HDMI_AHB_DMA_MASK, LOSTOWNERSHIP_MASK, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_MASK, field RETRYSPLIT_MASK (RW)
 *
 * Retry/split interrupt mask. Active when AHB master receives a RETRY or SPLIT response from slave.
 */

#define BP_HDMI_AHB_DMA_MASK_RETRYSPLIT_MASK      6
#define BM_HDMI_AHB_DMA_MASK_RETRYSPLIT_MASK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_MASK_RETRYSPLIT_MASK(v)   ((((reg32_t) v) << 6) & BM_HDMI_AHB_DMA_MASK_RETRYSPLIT_MASK)
#else
#define BF_HDMI_AHB_DMA_MASK_RETRYSPLIT_MASK(v)   (((v) << 6) & BM_HDMI_AHB_DMA_MASK_RETRYSPLIT_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RETRYSPLIT_MASK field to a new value.
#define BW_HDMI_AHB_DMA_MASK_RETRYSPLIT_MASK(v)   BF_CS1(HDMI_AHB_DMA_MASK, RETRYSPLIT_MASK, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_MASK, field DONE_MASK (RW)
 *
 * DMA end of operation interrupt mask. Active when DMA engine reaches final_addr[15:0] or when stop
 * DMA operation is activated.
 */

#define BP_HDMI_AHB_DMA_MASK_DONE_MASK      7
#define BM_HDMI_AHB_DMA_MASK_DONE_MASK      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_MASK_DONE_MASK(v)   ((((reg32_t) v) << 7) & BM_HDMI_AHB_DMA_MASK_DONE_MASK)
#else
#define BF_HDMI_AHB_DMA_MASK_DONE_MASK(v)   (((v) << 7) & BM_HDMI_AHB_DMA_MASK_DONE_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_MASK field to a new value.
#define BW_HDMI_AHB_DMA_MASK_DONE_MASK(v)   BF_CS1(HDMI_AHB_DMA_MASK, DONE_MASK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_POL - Audio DMA Polarity Interrupt Register (RW)
 *
 * Polarity for each of the interrupts present in the AHB audio DMA module. For usage information,
 * see ."   Address Offset: 0x3615  Size: 8 bits per register  Value after Reset: 0x00  Access:
 * Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FIFO_EMPTY_POLARITY : 1; //!< Audio FIFO empty interrupt mask.
        unsigned char FIFO_FULL_POLARITY : 1; //!< Audio FIFO full interrupt mask.
        unsigned char FIFO_THRFIFOEMPTY_POLARITY : 1; //!< Audio FIFO empty interrupt mask when audio FIFO has less than four samples.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char ERROR_POLARITY : 1; //!< Error interrupt mask. Active when slave indicates error through the isresp[1:0].
        unsigned char LOSTOWNERSHIP_POLARITY : 1; //!< Master lost ownership interrupt mask when in burst transfer. Active when AHB master loses BUS ownership within the course of a burst transfer.
        unsigned char RETRYSPLIT_POLARITY : 1; //!< Retry/split interrupt mask. Active when AHB master receives a RETRY or SPLIT response from slave.
        unsigned char DONE_POLARITY : 1; //!< DMA end of operation interrupt mask. Active when DMA engine reaches final_addr[15:0] or when stop DMA operation is activated.
    } B;
} hw_hdmi_ahb_dma_pol_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_POL register
 */
#define HW_HDMI_AHB_DMA_POL_ADDR      (REGS_HDMI_BASE + 0x3615)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_POL           (*(volatile hw_hdmi_ahb_dma_pol_t *) HW_HDMI_AHB_DMA_POL_ADDR)
#define HW_HDMI_AHB_DMA_POL_RD()      (HW_HDMI_AHB_DMA_POL.U)
#define HW_HDMI_AHB_DMA_POL_WR(v)     (HW_HDMI_AHB_DMA_POL.U = (v))
#define HW_HDMI_AHB_DMA_POL_SET(v)    (HW_HDMI_AHB_DMA_POL_WR(HW_HDMI_AHB_DMA_POL_RD() |  (v)))
#define HW_HDMI_AHB_DMA_POL_CLR(v)    (HW_HDMI_AHB_DMA_POL_WR(HW_HDMI_AHB_DMA_POL_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_POL_TOG(v)    (HW_HDMI_AHB_DMA_POL_WR(HW_HDMI_AHB_DMA_POL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_POL bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_POL, field FIFO_EMPTY_POLARITY (RW)
 *
 * Audio FIFO empty interrupt mask.
 */

#define BP_HDMI_AHB_DMA_POL_FIFO_EMPTY_POLARITY      0
#define BM_HDMI_AHB_DMA_POL_FIFO_EMPTY_POLARITY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_POL_FIFO_EMPTY_POLARITY(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_POL_FIFO_EMPTY_POLARITY)
#else
#define BF_HDMI_AHB_DMA_POL_FIFO_EMPTY_POLARITY(v)   (((v) << 0) & BM_HDMI_AHB_DMA_POL_FIFO_EMPTY_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_EMPTY_POLARITY field to a new value.
#define BW_HDMI_AHB_DMA_POL_FIFO_EMPTY_POLARITY(v)   BF_CS1(HDMI_AHB_DMA_POL, FIFO_EMPTY_POLARITY, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_POL, field FIFO_FULL_POLARITY (RW)
 *
 * Audio FIFO full interrupt mask.
 */

#define BP_HDMI_AHB_DMA_POL_FIFO_FULL_POLARITY      1
#define BM_HDMI_AHB_DMA_POL_FIFO_FULL_POLARITY      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_POL_FIFO_FULL_POLARITY(v)   ((((reg32_t) v) << 1) & BM_HDMI_AHB_DMA_POL_FIFO_FULL_POLARITY)
#else
#define BF_HDMI_AHB_DMA_POL_FIFO_FULL_POLARITY(v)   (((v) << 1) & BM_HDMI_AHB_DMA_POL_FIFO_FULL_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_FULL_POLARITY field to a new value.
#define BW_HDMI_AHB_DMA_POL_FIFO_FULL_POLARITY(v)   BF_CS1(HDMI_AHB_DMA_POL, FIFO_FULL_POLARITY, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_POL, field FIFO_THRFIFOEMPTY_POLARITY (RW)
 *
 * Audio FIFO empty interrupt mask when audio FIFO has less than four samples.
 */

#define BP_HDMI_AHB_DMA_POL_FIFO_THRFIFOEMPTY_POLARITY      2
#define BM_HDMI_AHB_DMA_POL_FIFO_THRFIFOEMPTY_POLARITY      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_POL_FIFO_THRFIFOEMPTY_POLARITY(v)   ((((reg32_t) v) << 2) & BM_HDMI_AHB_DMA_POL_FIFO_THRFIFOEMPTY_POLARITY)
#else
#define BF_HDMI_AHB_DMA_POL_FIFO_THRFIFOEMPTY_POLARITY(v)   (((v) << 2) & BM_HDMI_AHB_DMA_POL_FIFO_THRFIFOEMPTY_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_THRFIFOEMPTY_POLARITY field to a new value.
#define BW_HDMI_AHB_DMA_POL_FIFO_THRFIFOEMPTY_POLARITY(v)   BF_CS1(HDMI_AHB_DMA_POL, FIFO_THRFIFOEMPTY_POLARITY, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_POL, field ERROR_POLARITY (RW)
 *
 * Error interrupt mask. Active when slave indicates error through the isresp[1:0].
 */

#define BP_HDMI_AHB_DMA_POL_ERROR_POLARITY      4
#define BM_HDMI_AHB_DMA_POL_ERROR_POLARITY      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_POL_ERROR_POLARITY(v)   ((((reg32_t) v) << 4) & BM_HDMI_AHB_DMA_POL_ERROR_POLARITY)
#else
#define BF_HDMI_AHB_DMA_POL_ERROR_POLARITY(v)   (((v) << 4) & BM_HDMI_AHB_DMA_POL_ERROR_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_POLARITY field to a new value.
#define BW_HDMI_AHB_DMA_POL_ERROR_POLARITY(v)   BF_CS1(HDMI_AHB_DMA_POL, ERROR_POLARITY, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_POL, field LOSTOWNERSHIP_POLARITY (RW)
 *
 * Master lost ownership interrupt mask when in burst transfer. Active when AHB master loses BUS
 * ownership within the course of a burst transfer.
 */

#define BP_HDMI_AHB_DMA_POL_LOSTOWNERSHIP_POLARITY      5
#define BM_HDMI_AHB_DMA_POL_LOSTOWNERSHIP_POLARITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_POL_LOSTOWNERSHIP_POLARITY(v)   ((((reg32_t) v) << 5) & BM_HDMI_AHB_DMA_POL_LOSTOWNERSHIP_POLARITY)
#else
#define BF_HDMI_AHB_DMA_POL_LOSTOWNERSHIP_POLARITY(v)   (((v) << 5) & BM_HDMI_AHB_DMA_POL_LOSTOWNERSHIP_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOSTOWNERSHIP_POLARITY field to a new value.
#define BW_HDMI_AHB_DMA_POL_LOSTOWNERSHIP_POLARITY(v)   BF_CS1(HDMI_AHB_DMA_POL, LOSTOWNERSHIP_POLARITY, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_POL, field RETRYSPLIT_POLARITY (RW)
 *
 * Retry/split interrupt mask. Active when AHB master receives a RETRY or SPLIT response from slave.
 */

#define BP_HDMI_AHB_DMA_POL_RETRYSPLIT_POLARITY      6
#define BM_HDMI_AHB_DMA_POL_RETRYSPLIT_POLARITY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_POL_RETRYSPLIT_POLARITY(v)   ((((reg32_t) v) << 6) & BM_HDMI_AHB_DMA_POL_RETRYSPLIT_POLARITY)
#else
#define BF_HDMI_AHB_DMA_POL_RETRYSPLIT_POLARITY(v)   (((v) << 6) & BM_HDMI_AHB_DMA_POL_RETRYSPLIT_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RETRYSPLIT_POLARITY field to a new value.
#define BW_HDMI_AHB_DMA_POL_RETRYSPLIT_POLARITY(v)   BF_CS1(HDMI_AHB_DMA_POL, RETRYSPLIT_POLARITY, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_POL, field DONE_POLARITY (RW)
 *
 * DMA end of operation interrupt mask. Active when DMA engine reaches final_addr[15:0] or when stop
 * DMA operation is activated.
 */

#define BP_HDMI_AHB_DMA_POL_DONE_POLARITY      7
#define BM_HDMI_AHB_DMA_POL_DONE_POLARITY      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_POL_DONE_POLARITY(v)   ((((reg32_t) v) << 7) & BM_HDMI_AHB_DMA_POL_DONE_POLARITY)
#else
#define BF_HDMI_AHB_DMA_POL_DONE_POLARITY(v)   (((v) << 7) & BM_HDMI_AHB_DMA_POL_DONE_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_POLARITY field to a new value.
#define BW_HDMI_AHB_DMA_POL_DONE_POLARITY(v)   BF_CS1(HDMI_AHB_DMA_POL, DONE_POLARITY, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_CONF1 - Audio DMA Channel Enable Configuration Register 1 (RW)
 *
 * Address Offset: 0x3616  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CH_IN_EN : 1; //!< Channel 0 is always enabled.
        unsigned char CH_IN_EN1 : 1; //!< Channel 1 is always enabled.
        unsigned char CH_IN_EN2 : 1; //!< Channel 2 enable bit
        unsigned char CH_IN_EN3 : 1; //!< Channel 3 enable bit
        unsigned char CH_IN_EN4 : 1; //!< Channel 4 enable bit
        unsigned char CH_IN_EN5 : 1; //!< Channel 5 enable bit
        unsigned char CH_IN_EN6 : 1; //!< Channel 6 enable bit
        unsigned char CH_IN_EN7 : 1; //!< Channel 7 enable bit
    } B;
} hw_hdmi_ahb_dma_conf1_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_CONF1 register
 */
#define HW_HDMI_AHB_DMA_CONF1_ADDR      (REGS_HDMI_BASE + 0x3616)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_CONF1           (*(volatile hw_hdmi_ahb_dma_conf1_t *) HW_HDMI_AHB_DMA_CONF1_ADDR)
#define HW_HDMI_AHB_DMA_CONF1_RD()      (HW_HDMI_AHB_DMA_CONF1.U)
#define HW_HDMI_AHB_DMA_CONF1_WR(v)     (HW_HDMI_AHB_DMA_CONF1.U = (v))
#define HW_HDMI_AHB_DMA_CONF1_SET(v)    (HW_HDMI_AHB_DMA_CONF1_WR(HW_HDMI_AHB_DMA_CONF1_RD() |  (v)))
#define HW_HDMI_AHB_DMA_CONF1_CLR(v)    (HW_HDMI_AHB_DMA_CONF1_WR(HW_HDMI_AHB_DMA_CONF1_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_CONF1_TOG(v)    (HW_HDMI_AHB_DMA_CONF1_WR(HW_HDMI_AHB_DMA_CONF1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_CONF1 bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_CONF1, field CH_IN_EN (RW)
 *
 * Channel 0 is always enabled.
 */

#define BP_HDMI_AHB_DMA_CONF1_CH_IN_EN      0
#define BM_HDMI_AHB_DMA_CONF1_CH_IN_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#else
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   (((v) << 0) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH_IN_EN field to a new value.
#define BW_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   BF_CS1(HDMI_AHB_DMA_CONF1, CH_IN_EN, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_CONF1, field CH_IN_EN (RW)
 *
 * Channel 1 is always enabled.
 */

#define BP_HDMI_AHB_DMA_CONF1_CH_IN_EN      1
#define BM_HDMI_AHB_DMA_CONF1_CH_IN_EN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   ((((reg32_t) v) << 1) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#else
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   (((v) << 1) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH_IN_EN field to a new value.
#define BW_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   BF_CS1(HDMI_AHB_DMA_CONF1, CH_IN_EN, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_CONF1, field CH_IN_EN (RW)
 *
 * Channel 2 enable bit
 *
 * Values:
 * 1 - Channel enabled
 * 0 - Channel disabled
 */

#define BP_HDMI_AHB_DMA_CONF1_CH_IN_EN      2
#define BM_HDMI_AHB_DMA_CONF1_CH_IN_EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   ((((reg32_t) v) << 2) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#else
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   (((v) << 2) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH_IN_EN field to a new value.
#define BW_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   BF_CS1(HDMI_AHB_DMA_CONF1, CH_IN_EN, v)
#endif


/* --- Register HW_HDMI_AHB_DMA_CONF1, field CH_IN_EN (RW)
 *
 * Channel 3 enable bit
 *
 * Values:
 * 1 - Channel enabled
 * 0 - Channel disabled
 */

#define BP_HDMI_AHB_DMA_CONF1_CH_IN_EN      3
#define BM_HDMI_AHB_DMA_CONF1_CH_IN_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   ((((reg32_t) v) << 3) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#else
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   (((v) << 3) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH_IN_EN field to a new value.
#define BW_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   BF_CS1(HDMI_AHB_DMA_CONF1, CH_IN_EN, v)
#endif


/* --- Register HW_HDMI_AHB_DMA_CONF1, field CH_IN_EN (RW)
 *
 * Channel 4 enable bit
 *
 * Values:
 * 1 - Channel enabled
 * 0 - Channel disabled
 */

#define BP_HDMI_AHB_DMA_CONF1_CH_IN_EN      4
#define BM_HDMI_AHB_DMA_CONF1_CH_IN_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   ((((reg32_t) v) << 4) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#else
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   (((v) << 4) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH_IN_EN field to a new value.
#define BW_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   BF_CS1(HDMI_AHB_DMA_CONF1, CH_IN_EN, v)
#endif


/* --- Register HW_HDMI_AHB_DMA_CONF1, field CH_IN_EN (RW)
 *
 * Channel 5 enable bit
 *
 * Values:
 * 1 - Channel enabled
 * 0 - Channel disabled
 */

#define BP_HDMI_AHB_DMA_CONF1_CH_IN_EN      5
#define BM_HDMI_AHB_DMA_CONF1_CH_IN_EN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   ((((reg32_t) v) << 5) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#else
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   (((v) << 5) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH_IN_EN field to a new value.
#define BW_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   BF_CS1(HDMI_AHB_DMA_CONF1, CH_IN_EN, v)
#endif


/* --- Register HW_HDMI_AHB_DMA_CONF1, field CH_IN_EN (RW)
 *
 * Channel 6 enable bit
 *
 * Values:
 * 1 - Channel enabled
 * 0 - Channel disabled
 */

#define BP_HDMI_AHB_DMA_CONF1_CH_IN_EN      6
#define BM_HDMI_AHB_DMA_CONF1_CH_IN_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   ((((reg32_t) v) << 6) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#else
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   (((v) << 6) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH_IN_EN field to a new value.
#define BW_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   BF_CS1(HDMI_AHB_DMA_CONF1, CH_IN_EN, v)
#endif


/* --- Register HW_HDMI_AHB_DMA_CONF1, field CH_IN_EN (RW)
 *
 * Channel 7 enable bit
 *
 * Values:
 * 1 - Channel enabled
 * 0 - Channel disabled
 */

#define BP_HDMI_AHB_DMA_CONF1_CH_IN_EN      7
#define BM_HDMI_AHB_DMA_CONF1_CH_IN_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   ((((reg32_t) v) << 7) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#else
#define BF_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   (((v) << 7) & BM_HDMI_AHB_DMA_CONF1_CH_IN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH_IN_EN field to a new value.
#define BW_HDMI_AHB_DMA_CONF1_CH_IN_EN(v)   BF_CS1(HDMI_AHB_DMA_CONF1, CH_IN_EN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_BUFFSTAT - Audio DMA Buffer Interrupt Status Register (RO)
 *
 * Address Offset: 0x3617  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BUFF_EMPTY : 1; //!< Buffer empty flag status
        unsigned char BUFF_FULL : 1; //!< Buffer full flag status
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ahb_dma_buffstat_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_BUFFSTAT register
 */
#define HW_HDMI_AHB_DMA_BUFFSTAT_ADDR      (REGS_HDMI_BASE + 0x3617)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_BUFFSTAT           (*(volatile hw_hdmi_ahb_dma_buffstat_t *) HW_HDMI_AHB_DMA_BUFFSTAT_ADDR)
#define HW_HDMI_AHB_DMA_BUFFSTAT_RD()      (HW_HDMI_AHB_DMA_BUFFSTAT.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_BUFFSTAT bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_BUFFSTAT, field BUFF_EMPTY (RO)
 *
 * Buffer empty flag status
 */

#define BP_HDMI_AHB_DMA_BUFFSTAT_BUFF_EMPTY      0
#define BM_HDMI_AHB_DMA_BUFFSTAT_BUFF_EMPTY      0x00000001

/* --- Register HW_HDMI_AHB_DMA_BUFFSTAT, field BUFF_FULL (RO)
 *
 * Buffer full flag status
 */

#define BP_HDMI_AHB_DMA_BUFFSTAT_BUFF_FULL      1
#define BM_HDMI_AHB_DMA_BUFFSTAT_BUFF_FULL      0x00000002

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_BUFFINT - Audio DMA Buffer Interrupt Register (RO)
 *
 * Address Offset: 0x3618  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INT_BUFF_EMPTY : 1; //!< Buffer empty flag interrupt
        unsigned char INT_BUFF_FULL : 1; //!< Buffer full flag interrupt
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ahb_dma_buffint_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_BUFFINT register
 */
#define HW_HDMI_AHB_DMA_BUFFINT_ADDR      (REGS_HDMI_BASE + 0x3618)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_BUFFINT           (*(volatile hw_hdmi_ahb_dma_buffint_t *) HW_HDMI_AHB_DMA_BUFFINT_ADDR)
#define HW_HDMI_AHB_DMA_BUFFINT_RD()      (HW_HDMI_AHB_DMA_BUFFINT.U)
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_BUFFINT bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_BUFFINT, field INT_BUFF_EMPTY (RO)
 *
 * Buffer empty flag interrupt
 */

#define BP_HDMI_AHB_DMA_BUFFINT_INT_BUFF_EMPTY      0
#define BM_HDMI_AHB_DMA_BUFFINT_INT_BUFF_EMPTY      0x00000001

/* --- Register HW_HDMI_AHB_DMA_BUFFINT, field INT_BUFF_FULL (RO)
 *
 * Buffer full flag interrupt
 */

#define BP_HDMI_AHB_DMA_BUFFINT_INT_BUFF_FULL      1
#define BM_HDMI_AHB_DMA_BUFFINT_INT_BUFF_FULL      0x00000002

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_BUFFMASK - Audio DMA Buffer Mask Interrupt Register (RW)
 *
 * Address Offset: 0x3619  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INT_BUFF_EMPTY : 1; //!< Buffer empty flag mask
        unsigned char INT_BUFF_FULL : 1; //!< Buffer full flag mask
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ahb_dma_buffmask_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_BUFFMASK register
 */
#define HW_HDMI_AHB_DMA_BUFFMASK_ADDR      (REGS_HDMI_BASE + 0x3619)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_BUFFMASK           (*(volatile hw_hdmi_ahb_dma_buffmask_t *) HW_HDMI_AHB_DMA_BUFFMASK_ADDR)
#define HW_HDMI_AHB_DMA_BUFFMASK_RD()      (HW_HDMI_AHB_DMA_BUFFMASK.U)
#define HW_HDMI_AHB_DMA_BUFFMASK_WR(v)     (HW_HDMI_AHB_DMA_BUFFMASK.U = (v))
#define HW_HDMI_AHB_DMA_BUFFMASK_SET(v)    (HW_HDMI_AHB_DMA_BUFFMASK_WR(HW_HDMI_AHB_DMA_BUFFMASK_RD() |  (v)))
#define HW_HDMI_AHB_DMA_BUFFMASK_CLR(v)    (HW_HDMI_AHB_DMA_BUFFMASK_WR(HW_HDMI_AHB_DMA_BUFFMASK_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_BUFFMASK_TOG(v)    (HW_HDMI_AHB_DMA_BUFFMASK_WR(HW_HDMI_AHB_DMA_BUFFMASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_BUFFMASK bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_BUFFMASK, field INT_BUFF_EMPTY (RW)
 *
 * Buffer empty flag mask
 */

#define BP_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_EMPTY      0
#define BM_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_EMPTY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_EMPTY(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_EMPTY)
#else
#define BF_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_EMPTY(v)   (((v) << 0) & BM_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_EMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_BUFF_EMPTY field to a new value.
#define BW_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_EMPTY(v)   BF_CS1(HDMI_AHB_DMA_BUFFMASK, INT_BUFF_EMPTY, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_BUFFMASK, field INT_BUFF_FULL (RW)
 *
 * Buffer full flag mask
 */

#define BP_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_FULL      1
#define BM_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_FULL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_FULL(v)   ((((reg32_t) v) << 1) & BM_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_FULL)
#else
#define BF_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_FULL(v)   (((v) << 1) & BM_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_FULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_BUFF_FULL field to a new value.
#define BW_HDMI_AHB_DMA_BUFFMASK_INT_BUFF_FULL(v)   BF_CS1(HDMI_AHB_DMA_BUFFMASK, INT_BUFF_FULL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_AHB_DMA_BUFFPOL - Audio DMA Buffer Polarity Interrupt Register (RW)
 *
 * Address Offset: 0x361A  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char INT_BUFF_EMPTY : 1; //!< Buffer empty flag polarity
        unsigned char INT_BUFF_FULL : 1; //!< Buffer full flag polarity
        unsigned char RESERVED0 : 6; //!< Reserved
    } B;
} hw_hdmi_ahb_dma_buffpol_t;
#endif

/*
 * constants & macros for entire HDMI_AHB_DMA_BUFFPOL register
 */
#define HW_HDMI_AHB_DMA_BUFFPOL_ADDR      (REGS_HDMI_BASE + 0x361a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_AHB_DMA_BUFFPOL           (*(volatile hw_hdmi_ahb_dma_buffpol_t *) HW_HDMI_AHB_DMA_BUFFPOL_ADDR)
#define HW_HDMI_AHB_DMA_BUFFPOL_RD()      (HW_HDMI_AHB_DMA_BUFFPOL.U)
#define HW_HDMI_AHB_DMA_BUFFPOL_WR(v)     (HW_HDMI_AHB_DMA_BUFFPOL.U = (v))
#define HW_HDMI_AHB_DMA_BUFFPOL_SET(v)    (HW_HDMI_AHB_DMA_BUFFPOL_WR(HW_HDMI_AHB_DMA_BUFFPOL_RD() |  (v)))
#define HW_HDMI_AHB_DMA_BUFFPOL_CLR(v)    (HW_HDMI_AHB_DMA_BUFFPOL_WR(HW_HDMI_AHB_DMA_BUFFPOL_RD() & ~(v)))
#define HW_HDMI_AHB_DMA_BUFFPOL_TOG(v)    (HW_HDMI_AHB_DMA_BUFFPOL_WR(HW_HDMI_AHB_DMA_BUFFPOL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_AHB_DMA_BUFFPOL bitfields
 */

/* --- Register HW_HDMI_AHB_DMA_BUFFPOL, field INT_BUFF_EMPTY (RW)
 *
 * Buffer empty flag polarity
 */

#define BP_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_EMPTY      0
#define BM_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_EMPTY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_EMPTY(v)   ((((reg32_t) v) << 0) & BM_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_EMPTY)
#else
#define BF_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_EMPTY(v)   (((v) << 0) & BM_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_EMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_BUFF_EMPTY field to a new value.
#define BW_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_EMPTY(v)   BF_CS1(HDMI_AHB_DMA_BUFFPOL, INT_BUFF_EMPTY, v)
#endif

/* --- Register HW_HDMI_AHB_DMA_BUFFPOL, field INT_BUFF_FULL (RW)
 *
 * Buffer full flag polarity
 */

#define BP_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_FULL      1
#define BM_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_FULL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_FULL(v)   ((((reg32_t) v) << 1) & BM_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_FULL)
#else
#define BF_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_FULL(v)   (((v) << 1) & BM_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_FULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_BUFF_FULL field to a new value.
#define BW_HDMI_AHB_DMA_BUFFPOL_INT_BUFF_FULL(v)   BF_CS1(HDMI_AHB_DMA_BUFFPOL, INT_BUFF_FULL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_MC_CLKDIS - Main Controller Synchronous Clock Domain Disable Register (RW)
 *
 * Main controller synchronous disable control per clock domain. Upon release of synchronous disable
 * the corresponding sw reset NRZ request signal, to that domain, is toggled asking to the output
 * for a synchronized active low reset to be generated to that domain.   Address Offset: 0x4001
 * Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PIXELCLK_DISABLE : 1; //!< Pixel clock synchronous disable signal.
        unsigned char TMDSCLK_DISABLE : 1; //!< TMDS clock synchronous disable signal.
        unsigned char PREPCLK_DISABLE : 1; //!< Pixel Repetition clock synchronous disable signal.
        unsigned char AUDCLK_DISABLE : 1; //!< Audio Sampler clock synchronous disable signal.
        unsigned char CSCCLK_DISABLE : 1; //!< Color Space Converter clock synchronous disable signal.
        unsigned char CECCLK_DISABLE : 1; //!< CEC Engine clock synchronous disable signal.
        unsigned char HDCPCLK_DISABLE : 1; //!< HDCP clock synchronous disable signal. When active (1b) simultaneously bypasses HDCP.
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_mc_clkdis_t;
#endif

/*
 * constants & macros for entire HDMI_MC_CLKDIS register
 */
#define HW_HDMI_MC_CLKDIS_ADDR      (REGS_HDMI_BASE + 0x4001)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_MC_CLKDIS           (*(volatile hw_hdmi_mc_clkdis_t *) HW_HDMI_MC_CLKDIS_ADDR)
#define HW_HDMI_MC_CLKDIS_RD()      (HW_HDMI_MC_CLKDIS.U)
#define HW_HDMI_MC_CLKDIS_WR(v)     (HW_HDMI_MC_CLKDIS.U = (v))
#define HW_HDMI_MC_CLKDIS_SET(v)    (HW_HDMI_MC_CLKDIS_WR(HW_HDMI_MC_CLKDIS_RD() |  (v)))
#define HW_HDMI_MC_CLKDIS_CLR(v)    (HW_HDMI_MC_CLKDIS_WR(HW_HDMI_MC_CLKDIS_RD() & ~(v)))
#define HW_HDMI_MC_CLKDIS_TOG(v)    (HW_HDMI_MC_CLKDIS_WR(HW_HDMI_MC_CLKDIS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_MC_CLKDIS bitfields
 */

/* --- Register HW_HDMI_MC_CLKDIS, field PIXELCLK_DISABLE (RW)
 *
 * Pixel clock synchronous disable signal.
 */

#define BP_HDMI_MC_CLKDIS_PIXELCLK_DISABLE      0
#define BM_HDMI_MC_CLKDIS_PIXELCLK_DISABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_CLKDIS_PIXELCLK_DISABLE(v)   ((((reg32_t) v) << 0) & BM_HDMI_MC_CLKDIS_PIXELCLK_DISABLE)
#else
#define BF_HDMI_MC_CLKDIS_PIXELCLK_DISABLE(v)   (((v) << 0) & BM_HDMI_MC_CLKDIS_PIXELCLK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXELCLK_DISABLE field to a new value.
#define BW_HDMI_MC_CLKDIS_PIXELCLK_DISABLE(v)   BF_CS1(HDMI_MC_CLKDIS, PIXELCLK_DISABLE, v)
#endif

/* --- Register HW_HDMI_MC_CLKDIS, field TMDSCLK_DISABLE (RW)
 *
 * TMDS clock synchronous disable signal.
 */

#define BP_HDMI_MC_CLKDIS_TMDSCLK_DISABLE      1
#define BM_HDMI_MC_CLKDIS_TMDSCLK_DISABLE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_CLKDIS_TMDSCLK_DISABLE(v)   ((((reg32_t) v) << 1) & BM_HDMI_MC_CLKDIS_TMDSCLK_DISABLE)
#else
#define BF_HDMI_MC_CLKDIS_TMDSCLK_DISABLE(v)   (((v) << 1) & BM_HDMI_MC_CLKDIS_TMDSCLK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TMDSCLK_DISABLE field to a new value.
#define BW_HDMI_MC_CLKDIS_TMDSCLK_DISABLE(v)   BF_CS1(HDMI_MC_CLKDIS, TMDSCLK_DISABLE, v)
#endif

/* --- Register HW_HDMI_MC_CLKDIS, field PREPCLK_DISABLE (RW)
 *
 * Pixel Repetition clock synchronous disable signal.
 */

#define BP_HDMI_MC_CLKDIS_PREPCLK_DISABLE      2
#define BM_HDMI_MC_CLKDIS_PREPCLK_DISABLE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_CLKDIS_PREPCLK_DISABLE(v)   ((((reg32_t) v) << 2) & BM_HDMI_MC_CLKDIS_PREPCLK_DISABLE)
#else
#define BF_HDMI_MC_CLKDIS_PREPCLK_DISABLE(v)   (((v) << 2) & BM_HDMI_MC_CLKDIS_PREPCLK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PREPCLK_DISABLE field to a new value.
#define BW_HDMI_MC_CLKDIS_PREPCLK_DISABLE(v)   BF_CS1(HDMI_MC_CLKDIS, PREPCLK_DISABLE, v)
#endif

/* --- Register HW_HDMI_MC_CLKDIS, field AUDCLK_DISABLE (RW)
 *
 * Audio Sampler clock synchronous disable signal.
 */

#define BP_HDMI_MC_CLKDIS_AUDCLK_DISABLE      3
#define BM_HDMI_MC_CLKDIS_AUDCLK_DISABLE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_CLKDIS_AUDCLK_DISABLE(v)   ((((reg32_t) v) << 3) & BM_HDMI_MC_CLKDIS_AUDCLK_DISABLE)
#else
#define BF_HDMI_MC_CLKDIS_AUDCLK_DISABLE(v)   (((v) << 3) & BM_HDMI_MC_CLKDIS_AUDCLK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDCLK_DISABLE field to a new value.
#define BW_HDMI_MC_CLKDIS_AUDCLK_DISABLE(v)   BF_CS1(HDMI_MC_CLKDIS, AUDCLK_DISABLE, v)
#endif

/* --- Register HW_HDMI_MC_CLKDIS, field CSCCLK_DISABLE (RW)
 *
 * Color Space Converter clock synchronous disable signal.
 */

#define BP_HDMI_MC_CLKDIS_CSCCLK_DISABLE      4
#define BM_HDMI_MC_CLKDIS_CSCCLK_DISABLE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_CLKDIS_CSCCLK_DISABLE(v)   ((((reg32_t) v) << 4) & BM_HDMI_MC_CLKDIS_CSCCLK_DISABLE)
#else
#define BF_HDMI_MC_CLKDIS_CSCCLK_DISABLE(v)   (((v) << 4) & BM_HDMI_MC_CLKDIS_CSCCLK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSCCLK_DISABLE field to a new value.
#define BW_HDMI_MC_CLKDIS_CSCCLK_DISABLE(v)   BF_CS1(HDMI_MC_CLKDIS, CSCCLK_DISABLE, v)
#endif

/* --- Register HW_HDMI_MC_CLKDIS, field CECCLK_DISABLE (RW)
 *
 * CEC Engine clock synchronous disable signal.
 */

#define BP_HDMI_MC_CLKDIS_CECCLK_DISABLE      5
#define BM_HDMI_MC_CLKDIS_CECCLK_DISABLE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_CLKDIS_CECCLK_DISABLE(v)   ((((reg32_t) v) << 5) & BM_HDMI_MC_CLKDIS_CECCLK_DISABLE)
#else
#define BF_HDMI_MC_CLKDIS_CECCLK_DISABLE(v)   (((v) << 5) & BM_HDMI_MC_CLKDIS_CECCLK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CECCLK_DISABLE field to a new value.
#define BW_HDMI_MC_CLKDIS_CECCLK_DISABLE(v)   BF_CS1(HDMI_MC_CLKDIS, CECCLK_DISABLE, v)
#endif

/* --- Register HW_HDMI_MC_CLKDIS, field HDCPCLK_DISABLE (RW)
 *
 * HDCP clock synchronous disable signal. When active (1b) simultaneously bypasses HDCP.
 */

#define BP_HDMI_MC_CLKDIS_HDCPCLK_DISABLE      6
#define BM_HDMI_MC_CLKDIS_HDCPCLK_DISABLE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_CLKDIS_HDCPCLK_DISABLE(v)   ((((reg32_t) v) << 6) & BM_HDMI_MC_CLKDIS_HDCPCLK_DISABLE)
#else
#define BF_HDMI_MC_CLKDIS_HDCPCLK_DISABLE(v)   (((v) << 6) & BM_HDMI_MC_CLKDIS_HDCPCLK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPCLK_DISABLE field to a new value.
#define BW_HDMI_MC_CLKDIS_HDCPCLK_DISABLE(v)   BF_CS1(HDMI_MC_CLKDIS, HDCPCLK_DISABLE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_MC_SWRSTZREQ - Main Controller Software Reset Register (RW)
 *
 * Main controller software reset request per clock domain. Writing zero to a bit of this register
 * results in an NRZ signal toggle at sfrclk rate to an output signal that indicates a software
 * reset request. This toggle must be used to generate a synchronized reset to de corresponding
 * domain, with at least 1 clock cycle. Register defaults back to 0xFF.   Address Offset: 0x4002
 * Size: 8 bits  Value after Reset: 0xFF  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PIXELSWRST_REQ : 1; //!< Pixel software reset request. Defaults back to 1b after reset request.
        unsigned char TMDSSWRST_REQ : 1; //!< TMDS software reset request. Defaults back to 1b after reset request.
        unsigned char PREPSWRST_REQ : 1; //!< Pixel Repetition clock synchronous disable signal.
        unsigned char RESERVED0 : 3; //!< Reserved
        unsigned char CECSWRST_REQ : 1; //!< CEC software reset request. Defaults back to 1b after reset request.
        unsigned char RESERVED1 : 1; //!< Reserved
    } B;
} hw_hdmi_mc_swrstzreq_t;
#endif

/*
 * constants & macros for entire HDMI_MC_SWRSTZREQ register
 */
#define HW_HDMI_MC_SWRSTZREQ_ADDR      (REGS_HDMI_BASE + 0x4002)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_MC_SWRSTZREQ           (*(volatile hw_hdmi_mc_swrstzreq_t *) HW_HDMI_MC_SWRSTZREQ_ADDR)
#define HW_HDMI_MC_SWRSTZREQ_RD()      (HW_HDMI_MC_SWRSTZREQ.U)
#define HW_HDMI_MC_SWRSTZREQ_WR(v)     (HW_HDMI_MC_SWRSTZREQ.U = (v))
#define HW_HDMI_MC_SWRSTZREQ_SET(v)    (HW_HDMI_MC_SWRSTZREQ_WR(HW_HDMI_MC_SWRSTZREQ_RD() |  (v)))
#define HW_HDMI_MC_SWRSTZREQ_CLR(v)    (HW_HDMI_MC_SWRSTZREQ_WR(HW_HDMI_MC_SWRSTZREQ_RD() & ~(v)))
#define HW_HDMI_MC_SWRSTZREQ_TOG(v)    (HW_HDMI_MC_SWRSTZREQ_WR(HW_HDMI_MC_SWRSTZREQ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_MC_SWRSTZREQ bitfields
 */

/* --- Register HW_HDMI_MC_SWRSTZREQ, field PIXELSWRST_REQ (RW)
 *
 * Pixel software reset request. Defaults back to 1b after reset request.
 */

#define BP_HDMI_MC_SWRSTZREQ_PIXELSWRST_REQ      0
#define BM_HDMI_MC_SWRSTZREQ_PIXELSWRST_REQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_SWRSTZREQ_PIXELSWRST_REQ(v)   ((((reg32_t) v) << 0) & BM_HDMI_MC_SWRSTZREQ_PIXELSWRST_REQ)
#else
#define BF_HDMI_MC_SWRSTZREQ_PIXELSWRST_REQ(v)   (((v) << 0) & BM_HDMI_MC_SWRSTZREQ_PIXELSWRST_REQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXELSWRST_REQ field to a new value.
#define BW_HDMI_MC_SWRSTZREQ_PIXELSWRST_REQ(v)   BF_CS1(HDMI_MC_SWRSTZREQ, PIXELSWRST_REQ, v)
#endif

/* --- Register HW_HDMI_MC_SWRSTZREQ, field TMDSSWRST_REQ (RW)
 *
 * TMDS software reset request. Defaults back to 1b after reset request.
 */

#define BP_HDMI_MC_SWRSTZREQ_TMDSSWRST_REQ      1
#define BM_HDMI_MC_SWRSTZREQ_TMDSSWRST_REQ      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_SWRSTZREQ_TMDSSWRST_REQ(v)   ((((reg32_t) v) << 1) & BM_HDMI_MC_SWRSTZREQ_TMDSSWRST_REQ)
#else
#define BF_HDMI_MC_SWRSTZREQ_TMDSSWRST_REQ(v)   (((v) << 1) & BM_HDMI_MC_SWRSTZREQ_TMDSSWRST_REQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TMDSSWRST_REQ field to a new value.
#define BW_HDMI_MC_SWRSTZREQ_TMDSSWRST_REQ(v)   BF_CS1(HDMI_MC_SWRSTZREQ, TMDSSWRST_REQ, v)
#endif

/* --- Register HW_HDMI_MC_SWRSTZREQ, field PREPSWRST_REQ (RW)
 *
 * Pixel Repetition clock synchronous disable signal.
 */

#define BP_HDMI_MC_SWRSTZREQ_PREPSWRST_REQ      2
#define BM_HDMI_MC_SWRSTZREQ_PREPSWRST_REQ      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_SWRSTZREQ_PREPSWRST_REQ(v)   ((((reg32_t) v) << 2) & BM_HDMI_MC_SWRSTZREQ_PREPSWRST_REQ)
#else
#define BF_HDMI_MC_SWRSTZREQ_PREPSWRST_REQ(v)   (((v) << 2) & BM_HDMI_MC_SWRSTZREQ_PREPSWRST_REQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PREPSWRST_REQ field to a new value.
#define BW_HDMI_MC_SWRSTZREQ_PREPSWRST_REQ(v)   BF_CS1(HDMI_MC_SWRSTZREQ, PREPSWRST_REQ, v)
#endif

/* --- Register HW_HDMI_MC_SWRSTZREQ, field CECSWRST_REQ (RW)
 *
 * CEC software reset request. Defaults back to 1b after reset request.
 */

#define BP_HDMI_MC_SWRSTZREQ_CECSWRST_REQ      6
#define BM_HDMI_MC_SWRSTZREQ_CECSWRST_REQ      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_SWRSTZREQ_CECSWRST_REQ(v)   ((((reg32_t) v) << 6) & BM_HDMI_MC_SWRSTZREQ_CECSWRST_REQ)
#else
#define BF_HDMI_MC_SWRSTZREQ_CECSWRST_REQ(v)   (((v) << 6) & BM_HDMI_MC_SWRSTZREQ_CECSWRST_REQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CECSWRST_REQ field to a new value.
#define BW_HDMI_MC_SWRSTZREQ_CECSWRST_REQ(v)   BF_CS1(HDMI_MC_SWRSTZREQ, CECSWRST_REQ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_MC_FLOWCTRL - Main Controller Feed Through Control Register (RW)
 *
 * Address Offset: 0x4004  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FEED_THROUGH_OFF : 1; //!< Video path Feed Through enable bit:
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_mc_flowctrl_t;
#endif

/*
 * constants & macros for entire HDMI_MC_FLOWCTRL register
 */
#define HW_HDMI_MC_FLOWCTRL_ADDR      (REGS_HDMI_BASE + 0x4004)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_MC_FLOWCTRL           (*(volatile hw_hdmi_mc_flowctrl_t *) HW_HDMI_MC_FLOWCTRL_ADDR)
#define HW_HDMI_MC_FLOWCTRL_RD()      (HW_HDMI_MC_FLOWCTRL.U)
#define HW_HDMI_MC_FLOWCTRL_WR(v)     (HW_HDMI_MC_FLOWCTRL.U = (v))
#define HW_HDMI_MC_FLOWCTRL_SET(v)    (HW_HDMI_MC_FLOWCTRL_WR(HW_HDMI_MC_FLOWCTRL_RD() |  (v)))
#define HW_HDMI_MC_FLOWCTRL_CLR(v)    (HW_HDMI_MC_FLOWCTRL_WR(HW_HDMI_MC_FLOWCTRL_RD() & ~(v)))
#define HW_HDMI_MC_FLOWCTRL_TOG(v)    (HW_HDMI_MC_FLOWCTRL_WR(HW_HDMI_MC_FLOWCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_MC_FLOWCTRL bitfields
 */

/* --- Register HW_HDMI_MC_FLOWCTRL, field FEED_THROUGH_OFF (RW)
 *
 * Video path Feed Through enable bit:
 *
 * Values:
 * 1 - Color Space Converter is in the video data path.
 * 0 - Color Space Converter is bypassed (not in the video data path).
 */

#define BP_HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF      0
#define BM_HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF(v)   ((((reg32_t) v) << 0) & BM_HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF)
#else
#define BF_HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF(v)   (((v) << 0) & BM_HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FEED_THROUGH_OFF field to a new value.
#define BW_HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF(v)   BF_CS1(HDMI_MC_FLOWCTRL, FEED_THROUGH_OFF, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_MC_PHYRSTZ - Main Controller PHY Reset Register (RW)
 *
 * Address Offset: 0x4005  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char PHYRSTZ : 1; //!< HDMI Source PHY active low reset control.
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_mc_phyrstz_t;
#endif

/*
 * constants & macros for entire HDMI_MC_PHYRSTZ register
 */
#define HW_HDMI_MC_PHYRSTZ_ADDR      (REGS_HDMI_BASE + 0x4005)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_MC_PHYRSTZ           (*(volatile hw_hdmi_mc_phyrstz_t *) HW_HDMI_MC_PHYRSTZ_ADDR)
#define HW_HDMI_MC_PHYRSTZ_RD()      (HW_HDMI_MC_PHYRSTZ.U)
#define HW_HDMI_MC_PHYRSTZ_WR(v)     (HW_HDMI_MC_PHYRSTZ.U = (v))
#define HW_HDMI_MC_PHYRSTZ_SET(v)    (HW_HDMI_MC_PHYRSTZ_WR(HW_HDMI_MC_PHYRSTZ_RD() |  (v)))
#define HW_HDMI_MC_PHYRSTZ_CLR(v)    (HW_HDMI_MC_PHYRSTZ_WR(HW_HDMI_MC_PHYRSTZ_RD() & ~(v)))
#define HW_HDMI_MC_PHYRSTZ_TOG(v)    (HW_HDMI_MC_PHYRSTZ_WR(HW_HDMI_MC_PHYRSTZ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_MC_PHYRSTZ bitfields
 */

/* --- Register HW_HDMI_MC_PHYRSTZ, field PHYRSTZ (RW)
 *
 * HDMI Source PHY active low reset control.
 */

#define BP_HDMI_MC_PHYRSTZ_PHYRSTZ      0
#define BM_HDMI_MC_PHYRSTZ_PHYRSTZ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_PHYRSTZ_PHYRSTZ(v)   ((((reg32_t) v) << 0) & BM_HDMI_MC_PHYRSTZ_PHYRSTZ)
#else
#define BF_HDMI_MC_PHYRSTZ_PHYRSTZ(v)   (((v) << 0) & BM_HDMI_MC_PHYRSTZ_PHYRSTZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYRSTZ field to a new value.
#define BW_HDMI_MC_PHYRSTZ_PHYRSTZ(v)   BF_CS1(HDMI_MC_PHYRSTZ, PHYRSTZ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_MC_LOCKONCLOCK - Main Controller Clock Present Register (W1C)
 *
 * Address Offset: 0x4006  Size: 8 bits  Value after Reset: 0x00  Access: Read/Clear on Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CECCLK : 1; //!< CEC clock status. Indicates that the clock is present in the system. Cleared by WR 1 to this position.
        unsigned char RESERVED0 : 3; //!< Reserved.
        unsigned char PREPCLK : 1; //!< Pixel repetition clock status. Indicates that the clock is present in the system. Cleared by WR 1 to this position.
        unsigned char TCLKTCLK : 1; //!< TMDS clock status. Indicates that the clock is present in the system. Cleared by WR 1 to this position
        unsigned char PCLK : 1; //!< Pixel clock status. Indicates that the clock is present in the system. Cleared by WR 1 to this position.
        unsigned char RESERVED1 : 1; //!< Reserved.
    } B;
} hw_hdmi_mc_lockonclock_t;
#endif

/*
 * constants & macros for entire HDMI_MC_LOCKONCLOCK register
 */
#define HW_HDMI_MC_LOCKONCLOCK_ADDR      (REGS_HDMI_BASE + 0x4006)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_MC_LOCKONCLOCK           (*(volatile hw_hdmi_mc_lockonclock_t *) HW_HDMI_MC_LOCKONCLOCK_ADDR)
#define HW_HDMI_MC_LOCKONCLOCK_RD()      (HW_HDMI_MC_LOCKONCLOCK.U)
#endif

/*
 * constants & macros for individual HDMI_MC_LOCKONCLOCK bitfields
 */

/* --- Register HW_HDMI_MC_LOCKONCLOCK, field CECCLK (W1C)
 *
 * CEC clock status. Indicates that the clock is present in the system. Cleared by WR 1 to this
 * position.
 */

#define BP_HDMI_MC_LOCKONCLOCK_CECCLK      0
#define BM_HDMI_MC_LOCKONCLOCK_CECCLK      0x00000001

/* --- Register HW_HDMI_MC_LOCKONCLOCK, field PREPCLK (W1C)
 *
 * Pixel repetition clock status. Indicates that the clock is present in the system. Cleared by WR 1
 * to this position.
 */

#define BP_HDMI_MC_LOCKONCLOCK_PREPCLK      4
#define BM_HDMI_MC_LOCKONCLOCK_PREPCLK      0x00000010

/* --- Register HW_HDMI_MC_LOCKONCLOCK, field TCLKTCLK (W1C)
 *
 * TMDS clock status. Indicates that the clock is present in the system. Cleared by WR 1 to this
 * position
 */

#define BP_HDMI_MC_LOCKONCLOCK_TCLKTCLK      5
#define BM_HDMI_MC_LOCKONCLOCK_TCLKTCLK      0x00000020

/* --- Register HW_HDMI_MC_LOCKONCLOCK, field PCLK (W1C)
 *
 * Pixel clock status. Indicates that the clock is present in the system. Cleared by WR 1 to this
 * position.
 */

#define BP_HDMI_MC_LOCKONCLOCK_PCLK      6
#define BM_HDMI_MC_LOCKONCLOCK_PCLK      0x00000040

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_MC_HEACPHY_RST - Main Controller HEAC PHY Reset Register (RW)
 *
 * Address Offset: 0x4007  Size: 8 bits  Value after Reset: N/A  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HEACPHYRST : 1; //!< HEAC PHY reset (active high)
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_mc_heacphy_rst_t;
#endif

/*
 * constants & macros for entire HDMI_MC_HEACPHY_RST register
 */
#define HW_HDMI_MC_HEACPHY_RST_ADDR      (REGS_HDMI_BASE + 0x4007)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_MC_HEACPHY_RST           (*(volatile hw_hdmi_mc_heacphy_rst_t *) HW_HDMI_MC_HEACPHY_RST_ADDR)
#define HW_HDMI_MC_HEACPHY_RST_RD()      (HW_HDMI_MC_HEACPHY_RST.U)
#define HW_HDMI_MC_HEACPHY_RST_WR(v)     (HW_HDMI_MC_HEACPHY_RST.U = (v))
#define HW_HDMI_MC_HEACPHY_RST_SET(v)    (HW_HDMI_MC_HEACPHY_RST_WR(HW_HDMI_MC_HEACPHY_RST_RD() |  (v)))
#define HW_HDMI_MC_HEACPHY_RST_CLR(v)    (HW_HDMI_MC_HEACPHY_RST_WR(HW_HDMI_MC_HEACPHY_RST_RD() & ~(v)))
#define HW_HDMI_MC_HEACPHY_RST_TOG(v)    (HW_HDMI_MC_HEACPHY_RST_WR(HW_HDMI_MC_HEACPHY_RST_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_MC_HEACPHY_RST bitfields
 */

/* --- Register HW_HDMI_MC_HEACPHY_RST, field HEACPHYRST (RW)
 *
 * HEAC PHY reset (active high)
 */

#define BP_HDMI_MC_HEACPHY_RST_HEACPHYRST      0
#define BM_HDMI_MC_HEACPHY_RST_HEACPHYRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_MC_HEACPHY_RST_HEACPHYRST(v)   ((((reg32_t) v) << 0) & BM_HDMI_MC_HEACPHY_RST_HEACPHYRST)
#else
#define BF_HDMI_MC_HEACPHY_RST_HEACPHYRST(v)   (((v) << 0) & BM_HDMI_MC_HEACPHY_RST_HEACPHYRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HEACPHYRST field to a new value.
#define BW_HDMI_MC_HEACPHY_RST_HEACPHYRST(v)   BF_CS1(HDMI_MC_HEACPHY_RST, HEACPHYRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_CFG - Color Space Converter Interpolation and Decimation Configuration Register (RW)
 *
 * Color Space Conversion configuration register. Configures YCC422 to YCC444 interpolation mode and
 * YCC444 to YCC422 decimation mode.   Address Offset: 0x4100  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DECMODE_ : 2; //!< Chroma decimation configuration: decmode[1:0] Chroma decimation 00 decimation disabled 01 H d? z?=1 10 H d? z?=1/ 4?1/ 2 z?1?1/4 z?2 11 H d? z?Þ211=?5?12 z?2?22 z?4?39 z?6?65 z?8?109 z?10?204 z?12?648 z?14?1024 z?15?648 z?16?204 z?18?109 z?20?65 z?22?39 z?24?22 z?26?12 z?28?5 z?30 00 decimation disabled 01 H d (z) = 1 10 H d (Z)=1/4 + 1/2z -1 1+1/4z -2 11H d (z)x2 11 =-5+12z -2 +22z -4 +39z -8 +109z -10 -204z -12 +648z -14 +1024z -15 +648z -16 -204z -18 +109z -20 -65z -22 +39z -24 -22z -26 +12z -28 -5z -30
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char INTMODE_ : 2; //!< Chroma interpolation configuration: 00 interpolation disabled 01 H u (z) = 1 + z -1 10 H u (z)=1/2 + Z -1 +1/2 z -2 11 interpolation disabled.
        unsigned char RESERVED1 : 2; //!< Reserved
    } B;
} hw_hdmi_csc_cfg_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_CFG register
 */
#define HW_HDMI_CSC_CFG_ADDR      (REGS_HDMI_BASE + 0x4100)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_CFG           (*(volatile hw_hdmi_csc_cfg_t *) HW_HDMI_CSC_CFG_ADDR)
#define HW_HDMI_CSC_CFG_RD()      (HW_HDMI_CSC_CFG.U)
#define HW_HDMI_CSC_CFG_WR(v)     (HW_HDMI_CSC_CFG.U = (v))
#define HW_HDMI_CSC_CFG_SET(v)    (HW_HDMI_CSC_CFG_WR(HW_HDMI_CSC_CFG_RD() |  (v)))
#define HW_HDMI_CSC_CFG_CLR(v)    (HW_HDMI_CSC_CFG_WR(HW_HDMI_CSC_CFG_RD() & ~(v)))
#define HW_HDMI_CSC_CFG_TOG(v)    (HW_HDMI_CSC_CFG_WR(HW_HDMI_CSC_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_CFG bitfields
 */

/* --- Register HW_HDMI_CSC_CFG, field DECMODE_ (RW)
 *
 * Chroma decimation configuration: decmode[1:0] Chroma decimation 00 decimation disabled 01 H d?
 * z?=1 10 H d? z?=1/ 4?1/ 2 z?1?1/4 z?2 11 H d? z?Þ211=?5?12 z?2?22 z?4?39 z?6?65 z?8?109 z?10?204
 * z?12?648 z?14?1024 z?15?648 z?16?204 z?18?109 z?20?65 z?22?39 z?24?22 z?26?12 z?28?5 z?30 00
 * decimation disabled 01 H d (z) = 1 10 H d (Z)=1/4 + 1/2z -1 1+1/4z -2 11H d (z)x2 11 =-5+12z -2
 * +22z -4 +39z -8 +109z -10 -204z -12 +648z -14 +1024z -15 +648z -16 -204z -18 +109z -20 -65z -22
 * +39z -24 -22z -26 +12z -28 -5z -30
 */

#define BP_HDMI_CSC_CFG_DECMODE_      0
#define BM_HDMI_CSC_CFG_DECMODE_      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_CFG_DECMODE_(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_CFG_DECMODE_)
#else
#define BF_HDMI_CSC_CFG_DECMODE_(v)   (((v) << 0) & BM_HDMI_CSC_CFG_DECMODE_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DECMODE_ field to a new value.
#define BW_HDMI_CSC_CFG_DECMODE_(v)   BF_CS1(HDMI_CSC_CFG, DECMODE_, v)
#endif

/* --- Register HW_HDMI_CSC_CFG, field INTMODE_ (RW)
 *
 * Chroma interpolation configuration: 00 interpolation disabled 01 H u (z) = 1 + z -1 10 H u
 * (z)=1/2 + Z -1 +1/2 z -2 11 interpolation disabled.
 */

#define BP_HDMI_CSC_CFG_INTMODE_      4
#define BM_HDMI_CSC_CFG_INTMODE_      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_CFG_INTMODE_(v)   ((((reg32_t) v) << 4) & BM_HDMI_CSC_CFG_INTMODE_)
#else
#define BF_HDMI_CSC_CFG_INTMODE_(v)   (((v) << 4) & BM_HDMI_CSC_CFG_INTMODE_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTMODE_ field to a new value.
#define BW_HDMI_CSC_CFG_INTMODE_(v)   BF_CS1(HDMI_CSC_CFG, INTMODE_, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_SCALE - Color Space Converter Scale and Deep Color Configuration Register (RW)
 *
 * Address Offset: 0x4101  Size: 8 bits  Value after Reset: 0x01  Access: Read/Write      Separator
 * text   CSC Conversion Functions
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 2; //!< Defines the cscscale[1:0] scale factor to apply to all coefficients in Color Space Conversion. This scale factor is expressed in the number of left shifts to apply to each of the coefficients, ranging from 0 to 2.
        unsigned char RESERVED1 : 2; //!< Reserved
        unsigned char CSC_COLORDE_PTH : 4; //!< Color space converter color depth configuration: Other: Reserved.
    } B;
} hw_hdmi_csc_scale_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_SCALE register
 */
#define HW_HDMI_CSC_SCALE_ADDR      (REGS_HDMI_BASE + 0x4101)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_SCALE           (*(volatile hw_hdmi_csc_scale_t *) HW_HDMI_CSC_SCALE_ADDR)
#define HW_HDMI_CSC_SCALE_RD()      (HW_HDMI_CSC_SCALE.U)
#define HW_HDMI_CSC_SCALE_WR(v)     (HW_HDMI_CSC_SCALE.U = (v))
#define HW_HDMI_CSC_SCALE_SET(v)    (HW_HDMI_CSC_SCALE_WR(HW_HDMI_CSC_SCALE_RD() |  (v)))
#define HW_HDMI_CSC_SCALE_CLR(v)    (HW_HDMI_CSC_SCALE_WR(HW_HDMI_CSC_SCALE_RD() & ~(v)))
#define HW_HDMI_CSC_SCALE_TOG(v)    (HW_HDMI_CSC_SCALE_WR(HW_HDMI_CSC_SCALE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_SCALE bitfields
 */

/* --- Register HW_HDMI_CSC_SCALE, field CSC_COLORDE_PTH (RW)
 *
 * Color space converter color depth configuration: Other: Reserved.
 *
 * Values:
 * 0000 - 24 bit per pixel video (8 bit per component).
 * 0100 - 24 bit per pixel video (8 bit per component).
 * 0101 - 30 bit per pixel video (10 bit per component).
 * 0110 - 36 bit per pixel video (12 bit per component).
 * 0111 - 48 bit per pixel video (16 bit per component).
 */

#define BP_HDMI_CSC_SCALE_CSC_COLORDE_PTH      4
#define BM_HDMI_CSC_SCALE_CSC_COLORDE_PTH      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_SCALE_CSC_COLORDE_PTH(v)   ((((reg32_t) v) << 4) & BM_HDMI_CSC_SCALE_CSC_COLORDE_PTH)
#else
#define BF_HDMI_CSC_SCALE_CSC_COLORDE_PTH(v)   (((v) << 4) & BM_HDMI_CSC_SCALE_CSC_COLORDE_PTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COLORDE_PTH field to a new value.
#define BW_HDMI_CSC_SCALE_CSC_COLORDE_PTH(v)   BF_CS1(HDMI_CSC_SCALE, CSC_COLORDE_PTH, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_A1_MSB - CSC_COEF_A1_MSB (RW)
 *
 * Color Space Conversion A1 coefficient.   Address Offset: 0x4102  Size: 8 bits  Value after Reset:
 * 0x20  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_A1_MSB : 8; //!< Color Space Conversion A1 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_a1_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_A1_MSB register
 */
#define HW_HDMI_CSC_COEF_A1_MSB_ADDR      (REGS_HDMI_BASE + 0x4102)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_A1_MSB           (*(volatile hw_hdmi_csc_coef_a1_msb_t *) HW_HDMI_CSC_COEF_A1_MSB_ADDR)
#define HW_HDMI_CSC_COEF_A1_MSB_RD()      (HW_HDMI_CSC_COEF_A1_MSB.U)
#define HW_HDMI_CSC_COEF_A1_MSB_WR(v)     (HW_HDMI_CSC_COEF_A1_MSB.U = (v))
#define HW_HDMI_CSC_COEF_A1_MSB_SET(v)    (HW_HDMI_CSC_COEF_A1_MSB_WR(HW_HDMI_CSC_COEF_A1_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_A1_MSB_CLR(v)    (HW_HDMI_CSC_COEF_A1_MSB_WR(HW_HDMI_CSC_COEF_A1_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_A1_MSB_TOG(v)    (HW_HDMI_CSC_COEF_A1_MSB_WR(HW_HDMI_CSC_COEF_A1_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_A1_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_A1_MSB, field CSC_COEF_A1_MSB (RW)
 *
 * Color Space Conversion A1 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB      0
#define BM_HDMI_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB)
#else
#define BF_HDMI_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_A1_MSB field to a new value.
#define BW_HDMI_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB(v)   BF_CS1(HDMI_CSC_COEF_A1_MSB, CSC_COEF_A1_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_A1_LSB - CSC_COEF_A1_LSB (RW)
 *
 * Color Space Conversion A1 coefficient.   Address Offset: 0x4103  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_A1_LSB : 8; //!< Color Space Conversion A1 LSB coefficient
    } B;
} hw_hdmi_csc_coef_a1_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_A1_LSB register
 */
#define HW_HDMI_CSC_COEF_A1_LSB_ADDR      (REGS_HDMI_BASE + 0x4103)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_A1_LSB           (*(volatile hw_hdmi_csc_coef_a1_lsb_t *) HW_HDMI_CSC_COEF_A1_LSB_ADDR)
#define HW_HDMI_CSC_COEF_A1_LSB_RD()      (HW_HDMI_CSC_COEF_A1_LSB.U)
#define HW_HDMI_CSC_COEF_A1_LSB_WR(v)     (HW_HDMI_CSC_COEF_A1_LSB.U = (v))
#define HW_HDMI_CSC_COEF_A1_LSB_SET(v)    (HW_HDMI_CSC_COEF_A1_LSB_WR(HW_HDMI_CSC_COEF_A1_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_A1_LSB_CLR(v)    (HW_HDMI_CSC_COEF_A1_LSB_WR(HW_HDMI_CSC_COEF_A1_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_A1_LSB_TOG(v)    (HW_HDMI_CSC_COEF_A1_LSB_WR(HW_HDMI_CSC_COEF_A1_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_A1_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_A1_LSB, field CSC_COEF_A1_LSB (RW)
 *
 * Color Space Conversion A1 LSB coefficient
 */

#define BP_HDMI_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB      0
#define BM_HDMI_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB)
#else
#define BF_HDMI_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_A1_LSB field to a new value.
#define BW_HDMI_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB(v)   BF_CS1(HDMI_CSC_COEF_A1_LSB, CSC_COEF_A1_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_A2_MSB - CSC_COEF_A2_MSB (RW)
 *
 * Color Space Conversion A2 coefficient.   Address Offset: 0x4104  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_A2_MSB : 8; //!< Color Space Conversion A2 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_a2_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_A2_MSB register
 */
#define HW_HDMI_CSC_COEF_A2_MSB_ADDR      (REGS_HDMI_BASE + 0x4104)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_A2_MSB           (*(volatile hw_hdmi_csc_coef_a2_msb_t *) HW_HDMI_CSC_COEF_A2_MSB_ADDR)
#define HW_HDMI_CSC_COEF_A2_MSB_RD()      (HW_HDMI_CSC_COEF_A2_MSB.U)
#define HW_HDMI_CSC_COEF_A2_MSB_WR(v)     (HW_HDMI_CSC_COEF_A2_MSB.U = (v))
#define HW_HDMI_CSC_COEF_A2_MSB_SET(v)    (HW_HDMI_CSC_COEF_A2_MSB_WR(HW_HDMI_CSC_COEF_A2_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_A2_MSB_CLR(v)    (HW_HDMI_CSC_COEF_A2_MSB_WR(HW_HDMI_CSC_COEF_A2_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_A2_MSB_TOG(v)    (HW_HDMI_CSC_COEF_A2_MSB_WR(HW_HDMI_CSC_COEF_A2_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_A2_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_A2_MSB, field CSC_COEF_A2_MSB (RW)
 *
 * Color Space Conversion A2 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB      0
#define BM_HDMI_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB)
#else
#define BF_HDMI_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_A2_MSB field to a new value.
#define BW_HDMI_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB(v)   BF_CS1(HDMI_CSC_COEF_A2_MSB, CSC_COEF_A2_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_A2_LSB - CSC_COEF_A2_LSB (RW)
 *
 * Color Space Conversion A2 coefficient.   Address Offset: 0x4105  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_A2_LSB : 8; //!< Color Space Conversion A2 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_a2_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_A2_LSB register
 */
#define HW_HDMI_CSC_COEF_A2_LSB_ADDR      (REGS_HDMI_BASE + 0x4105)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_A2_LSB           (*(volatile hw_hdmi_csc_coef_a2_lsb_t *) HW_HDMI_CSC_COEF_A2_LSB_ADDR)
#define HW_HDMI_CSC_COEF_A2_LSB_RD()      (HW_HDMI_CSC_COEF_A2_LSB.U)
#define HW_HDMI_CSC_COEF_A2_LSB_WR(v)     (HW_HDMI_CSC_COEF_A2_LSB.U = (v))
#define HW_HDMI_CSC_COEF_A2_LSB_SET(v)    (HW_HDMI_CSC_COEF_A2_LSB_WR(HW_HDMI_CSC_COEF_A2_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_A2_LSB_CLR(v)    (HW_HDMI_CSC_COEF_A2_LSB_WR(HW_HDMI_CSC_COEF_A2_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_A2_LSB_TOG(v)    (HW_HDMI_CSC_COEF_A2_LSB_WR(HW_HDMI_CSC_COEF_A2_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_A2_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_A2_LSB, field CSC_COEF_A2_LSB (RW)
 *
 * Color Space Conversion A2 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB      0
#define BM_HDMI_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB)
#else
#define BF_HDMI_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_A2_LSB field to a new value.
#define BW_HDMI_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB(v)   BF_CS1(HDMI_CSC_COEF_A2_LSB, CSC_COEF_A2_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_A3_MSB - CSC_COEF_A3_MSB (RW)
 *
 * Color Space Conversion A3 coefficient.   Address Offset: 0x4106  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_A3_MSB : 8; //!< Color Space Conversion A3 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_a3_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_A3_MSB register
 */
#define HW_HDMI_CSC_COEF_A3_MSB_ADDR      (REGS_HDMI_BASE + 0x4106)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_A3_MSB           (*(volatile hw_hdmi_csc_coef_a3_msb_t *) HW_HDMI_CSC_COEF_A3_MSB_ADDR)
#define HW_HDMI_CSC_COEF_A3_MSB_RD()      (HW_HDMI_CSC_COEF_A3_MSB.U)
#define HW_HDMI_CSC_COEF_A3_MSB_WR(v)     (HW_HDMI_CSC_COEF_A3_MSB.U = (v))
#define HW_HDMI_CSC_COEF_A3_MSB_SET(v)    (HW_HDMI_CSC_COEF_A3_MSB_WR(HW_HDMI_CSC_COEF_A3_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_A3_MSB_CLR(v)    (HW_HDMI_CSC_COEF_A3_MSB_WR(HW_HDMI_CSC_COEF_A3_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_A3_MSB_TOG(v)    (HW_HDMI_CSC_COEF_A3_MSB_WR(HW_HDMI_CSC_COEF_A3_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_A3_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_A3_MSB, field CSC_COEF_A3_MSB (RW)
 *
 * Color Space Conversion A3 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB      0
#define BM_HDMI_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB)
#else
#define BF_HDMI_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_A3_MSB field to a new value.
#define BW_HDMI_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB(v)   BF_CS1(HDMI_CSC_COEF_A3_MSB, CSC_COEF_A3_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_A3_LSB - CSC_COEF_A3_LSB (RW)
 *
 * Color Space Conversion A3 coefficient.   Address Offset: 0x4107  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_A3_LSB : 8; //!< Color Space Conversion A3 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_a3_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_A3_LSB register
 */
#define HW_HDMI_CSC_COEF_A3_LSB_ADDR      (REGS_HDMI_BASE + 0x4107)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_A3_LSB           (*(volatile hw_hdmi_csc_coef_a3_lsb_t *) HW_HDMI_CSC_COEF_A3_LSB_ADDR)
#define HW_HDMI_CSC_COEF_A3_LSB_RD()      (HW_HDMI_CSC_COEF_A3_LSB.U)
#define HW_HDMI_CSC_COEF_A3_LSB_WR(v)     (HW_HDMI_CSC_COEF_A3_LSB.U = (v))
#define HW_HDMI_CSC_COEF_A3_LSB_SET(v)    (HW_HDMI_CSC_COEF_A3_LSB_WR(HW_HDMI_CSC_COEF_A3_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_A3_LSB_CLR(v)    (HW_HDMI_CSC_COEF_A3_LSB_WR(HW_HDMI_CSC_COEF_A3_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_A3_LSB_TOG(v)    (HW_HDMI_CSC_COEF_A3_LSB_WR(HW_HDMI_CSC_COEF_A3_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_A3_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_A3_LSB, field CSC_COEF_A3_LSB (RW)
 *
 * Color Space Conversion A3 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB      0
#define BM_HDMI_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB)
#else
#define BF_HDMI_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_A3_LSB field to a new value.
#define BW_HDMI_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB(v)   BF_CS1(HDMI_CSC_COEF_A3_LSB, CSC_COEF_A3_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_A4_MSB - CSC_COEF_A4_MSB (RW)
 *
 * Color Space Conversion A4 coefficient.   Address Offset: 0x4108  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_A4_MSB : 8; //!< Color Space Conversion A4 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_a4_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_A4_MSB register
 */
#define HW_HDMI_CSC_COEF_A4_MSB_ADDR      (REGS_HDMI_BASE + 0x4108)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_A4_MSB           (*(volatile hw_hdmi_csc_coef_a4_msb_t *) HW_HDMI_CSC_COEF_A4_MSB_ADDR)
#define HW_HDMI_CSC_COEF_A4_MSB_RD()      (HW_HDMI_CSC_COEF_A4_MSB.U)
#define HW_HDMI_CSC_COEF_A4_MSB_WR(v)     (HW_HDMI_CSC_COEF_A4_MSB.U = (v))
#define HW_HDMI_CSC_COEF_A4_MSB_SET(v)    (HW_HDMI_CSC_COEF_A4_MSB_WR(HW_HDMI_CSC_COEF_A4_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_A4_MSB_CLR(v)    (HW_HDMI_CSC_COEF_A4_MSB_WR(HW_HDMI_CSC_COEF_A4_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_A4_MSB_TOG(v)    (HW_HDMI_CSC_COEF_A4_MSB_WR(HW_HDMI_CSC_COEF_A4_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_A4_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_A4_MSB, field CSC_COEF_A4_MSB (RW)
 *
 * Color Space Conversion A4 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB      0
#define BM_HDMI_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB)
#else
#define BF_HDMI_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_A4_MSB field to a new value.
#define BW_HDMI_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB(v)   BF_CS1(HDMI_CSC_COEF_A4_MSB, CSC_COEF_A4_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_A4_LSB - CSC_COEF_A4_LSB (RW)
 *
 * Color Space Conversion A4 coefficient.   Address Offset: 0x4109  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_A4_LSB : 8; //!< Color Space Conversion A4 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_a4_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_A4_LSB register
 */
#define HW_HDMI_CSC_COEF_A4_LSB_ADDR      (REGS_HDMI_BASE + 0x4109)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_A4_LSB           (*(volatile hw_hdmi_csc_coef_a4_lsb_t *) HW_HDMI_CSC_COEF_A4_LSB_ADDR)
#define HW_HDMI_CSC_COEF_A4_LSB_RD()      (HW_HDMI_CSC_COEF_A4_LSB.U)
#define HW_HDMI_CSC_COEF_A4_LSB_WR(v)     (HW_HDMI_CSC_COEF_A4_LSB.U = (v))
#define HW_HDMI_CSC_COEF_A4_LSB_SET(v)    (HW_HDMI_CSC_COEF_A4_LSB_WR(HW_HDMI_CSC_COEF_A4_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_A4_LSB_CLR(v)    (HW_HDMI_CSC_COEF_A4_LSB_WR(HW_HDMI_CSC_COEF_A4_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_A4_LSB_TOG(v)    (HW_HDMI_CSC_COEF_A4_LSB_WR(HW_HDMI_CSC_COEF_A4_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_A4_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_A4_LSB, field CSC_COEF_A4_LSB (RW)
 *
 * Color Space Conversion A4 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB      0
#define BM_HDMI_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB)
#else
#define BF_HDMI_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_A4_LSB field to a new value.
#define BW_HDMI_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB(v)   BF_CS1(HDMI_CSC_COEF_A4_LSB, CSC_COEF_A4_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_B1_MSB - CSC_COEF_B1_MSB (RW)
 *
 * Color Space Conversion B1 coefficient.   Address Offset: 0x410A  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_B1_MSB : 8; //!< Color Space Conversion B1 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_b1_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_B1_MSB register
 */
#define HW_HDMI_CSC_COEF_B1_MSB_ADDR      (REGS_HDMI_BASE + 0x410a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_B1_MSB           (*(volatile hw_hdmi_csc_coef_b1_msb_t *) HW_HDMI_CSC_COEF_B1_MSB_ADDR)
#define HW_HDMI_CSC_COEF_B1_MSB_RD()      (HW_HDMI_CSC_COEF_B1_MSB.U)
#define HW_HDMI_CSC_COEF_B1_MSB_WR(v)     (HW_HDMI_CSC_COEF_B1_MSB.U = (v))
#define HW_HDMI_CSC_COEF_B1_MSB_SET(v)    (HW_HDMI_CSC_COEF_B1_MSB_WR(HW_HDMI_CSC_COEF_B1_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_B1_MSB_CLR(v)    (HW_HDMI_CSC_COEF_B1_MSB_WR(HW_HDMI_CSC_COEF_B1_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_B1_MSB_TOG(v)    (HW_HDMI_CSC_COEF_B1_MSB_WR(HW_HDMI_CSC_COEF_B1_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_B1_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_B1_MSB, field CSC_COEF_B1_MSB (RW)
 *
 * Color Space Conversion B1 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB      0
#define BM_HDMI_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB)
#else
#define BF_HDMI_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_B1_MSB field to a new value.
#define BW_HDMI_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB(v)   BF_CS1(HDMI_CSC_COEF_B1_MSB, CSC_COEF_B1_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_B1_LSB - CSC_COEF_B1_LSB (RW)
 *
 * Color Space Conversion B1 coefficient.   Address Offset: 0x410B  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_B1_LSB : 8; //!< Color Space Conversion B1 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_b1_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_B1_LSB register
 */
#define HW_HDMI_CSC_COEF_B1_LSB_ADDR      (REGS_HDMI_BASE + 0x410b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_B1_LSB           (*(volatile hw_hdmi_csc_coef_b1_lsb_t *) HW_HDMI_CSC_COEF_B1_LSB_ADDR)
#define HW_HDMI_CSC_COEF_B1_LSB_RD()      (HW_HDMI_CSC_COEF_B1_LSB.U)
#define HW_HDMI_CSC_COEF_B1_LSB_WR(v)     (HW_HDMI_CSC_COEF_B1_LSB.U = (v))
#define HW_HDMI_CSC_COEF_B1_LSB_SET(v)    (HW_HDMI_CSC_COEF_B1_LSB_WR(HW_HDMI_CSC_COEF_B1_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_B1_LSB_CLR(v)    (HW_HDMI_CSC_COEF_B1_LSB_WR(HW_HDMI_CSC_COEF_B1_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_B1_LSB_TOG(v)    (HW_HDMI_CSC_COEF_B1_LSB_WR(HW_HDMI_CSC_COEF_B1_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_B1_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_B1_LSB, field CSC_COEF_B1_LSB (RW)
 *
 * Color Space Conversion B1 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB      0
#define BM_HDMI_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB)
#else
#define BF_HDMI_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_B1_LSB field to a new value.
#define BW_HDMI_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB(v)   BF_CS1(HDMI_CSC_COEF_B1_LSB, CSC_COEF_B1_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_B2_MSB - CSC_COEF_B2_MSB (RW)
 *
 * Color Space Conversion B2 coefficient.   Address Offset: 0x410C  Size: 8 bits  Value after Reset:
 * 0x20  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_B2_MSB : 8; //!< Color Space Conversion B2 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_b2_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_B2_MSB register
 */
#define HW_HDMI_CSC_COEF_B2_MSB_ADDR      (REGS_HDMI_BASE + 0x410c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_B2_MSB           (*(volatile hw_hdmi_csc_coef_b2_msb_t *) HW_HDMI_CSC_COEF_B2_MSB_ADDR)
#define HW_HDMI_CSC_COEF_B2_MSB_RD()      (HW_HDMI_CSC_COEF_B2_MSB.U)
#define HW_HDMI_CSC_COEF_B2_MSB_WR(v)     (HW_HDMI_CSC_COEF_B2_MSB.U = (v))
#define HW_HDMI_CSC_COEF_B2_MSB_SET(v)    (HW_HDMI_CSC_COEF_B2_MSB_WR(HW_HDMI_CSC_COEF_B2_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_B2_MSB_CLR(v)    (HW_HDMI_CSC_COEF_B2_MSB_WR(HW_HDMI_CSC_COEF_B2_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_B2_MSB_TOG(v)    (HW_HDMI_CSC_COEF_B2_MSB_WR(HW_HDMI_CSC_COEF_B2_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_B2_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_B2_MSB, field CSC_COEF_B2_MSB (RW)
 *
 * Color Space Conversion B2 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB      0
#define BM_HDMI_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB)
#else
#define BF_HDMI_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_B2_MSB field to a new value.
#define BW_HDMI_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB(v)   BF_CS1(HDMI_CSC_COEF_B2_MSB, CSC_COEF_B2_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_B2_LSB - CSC_COEF_B2_LSB (RW)
 *
 * Color Space Conversion B2 coefficient.   Address Offset: 0x410D  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_B2_LSB : 8; //!< Color Space Conversion B2 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_b2_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_B2_LSB register
 */
#define HW_HDMI_CSC_COEF_B2_LSB_ADDR      (REGS_HDMI_BASE + 0x410d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_B2_LSB           (*(volatile hw_hdmi_csc_coef_b2_lsb_t *) HW_HDMI_CSC_COEF_B2_LSB_ADDR)
#define HW_HDMI_CSC_COEF_B2_LSB_RD()      (HW_HDMI_CSC_COEF_B2_LSB.U)
#define HW_HDMI_CSC_COEF_B2_LSB_WR(v)     (HW_HDMI_CSC_COEF_B2_LSB.U = (v))
#define HW_HDMI_CSC_COEF_B2_LSB_SET(v)    (HW_HDMI_CSC_COEF_B2_LSB_WR(HW_HDMI_CSC_COEF_B2_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_B2_LSB_CLR(v)    (HW_HDMI_CSC_COEF_B2_LSB_WR(HW_HDMI_CSC_COEF_B2_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_B2_LSB_TOG(v)    (HW_HDMI_CSC_COEF_B2_LSB_WR(HW_HDMI_CSC_COEF_B2_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_B2_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_B2_LSB, field CSC_COEF_B2_LSB (RW)
 *
 * Color Space Conversion B2 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB      0
#define BM_HDMI_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB)
#else
#define BF_HDMI_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_B2_LSB field to a new value.
#define BW_HDMI_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB(v)   BF_CS1(HDMI_CSC_COEF_B2_LSB, CSC_COEF_B2_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_B3_MSB - CSC_COEF_B3_MSB (RW)
 *
 * Color Space Conversion B3 coefficient.   Address Offset: 0x410E  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_B3_MSB : 8; //!< Color Space Conversion B3 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_b3_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_B3_MSB register
 */
#define HW_HDMI_CSC_COEF_B3_MSB_ADDR      (REGS_HDMI_BASE + 0x410e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_B3_MSB           (*(volatile hw_hdmi_csc_coef_b3_msb_t *) HW_HDMI_CSC_COEF_B3_MSB_ADDR)
#define HW_HDMI_CSC_COEF_B3_MSB_RD()      (HW_HDMI_CSC_COEF_B3_MSB.U)
#define HW_HDMI_CSC_COEF_B3_MSB_WR(v)     (HW_HDMI_CSC_COEF_B3_MSB.U = (v))
#define HW_HDMI_CSC_COEF_B3_MSB_SET(v)    (HW_HDMI_CSC_COEF_B3_MSB_WR(HW_HDMI_CSC_COEF_B3_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_B3_MSB_CLR(v)    (HW_HDMI_CSC_COEF_B3_MSB_WR(HW_HDMI_CSC_COEF_B3_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_B3_MSB_TOG(v)    (HW_HDMI_CSC_COEF_B3_MSB_WR(HW_HDMI_CSC_COEF_B3_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_B3_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_B3_MSB, field CSC_COEF_B3_MSB (RW)
 *
 * Color Space Conversion B3 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB      0
#define BM_HDMI_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB)
#else
#define BF_HDMI_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_B3_MSB field to a new value.
#define BW_HDMI_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB(v)   BF_CS1(HDMI_CSC_COEF_B3_MSB, CSC_COEF_B3_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_B3_LSB - CSC_COEF_B3_LSB (RW)
 *
 * Color Space Conversion B3 coefficient.   Address Offset: 0x410F  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_B3_LSB : 8; //!< Color Space Conversion B3 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_b3_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_B3_LSB register
 */
#define HW_HDMI_CSC_COEF_B3_LSB_ADDR      (REGS_HDMI_BASE + 0x410f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_B3_LSB           (*(volatile hw_hdmi_csc_coef_b3_lsb_t *) HW_HDMI_CSC_COEF_B3_LSB_ADDR)
#define HW_HDMI_CSC_COEF_B3_LSB_RD()      (HW_HDMI_CSC_COEF_B3_LSB.U)
#define HW_HDMI_CSC_COEF_B3_LSB_WR(v)     (HW_HDMI_CSC_COEF_B3_LSB.U = (v))
#define HW_HDMI_CSC_COEF_B3_LSB_SET(v)    (HW_HDMI_CSC_COEF_B3_LSB_WR(HW_HDMI_CSC_COEF_B3_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_B3_LSB_CLR(v)    (HW_HDMI_CSC_COEF_B3_LSB_WR(HW_HDMI_CSC_COEF_B3_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_B3_LSB_TOG(v)    (HW_HDMI_CSC_COEF_B3_LSB_WR(HW_HDMI_CSC_COEF_B3_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_B3_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_B3_LSB, field CSC_COEF_B3_LSB (RW)
 *
 * Color Space Conversion B3 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB      0
#define BM_HDMI_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB)
#else
#define BF_HDMI_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_B3_LSB field to a new value.
#define BW_HDMI_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB(v)   BF_CS1(HDMI_CSC_COEF_B3_LSB, CSC_COEF_B3_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_B4_MSB - CSC_COEF_B4_MSB (RW)
 *
 * Color Space Conversion B4 coefficient.   Address Offset: 0x4110  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_B4_MSB : 8; //!< Color Space Conversion B4 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_b4_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_B4_MSB register
 */
#define HW_HDMI_CSC_COEF_B4_MSB_ADDR      (REGS_HDMI_BASE + 0x4110)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_B4_MSB           (*(volatile hw_hdmi_csc_coef_b4_msb_t *) HW_HDMI_CSC_COEF_B4_MSB_ADDR)
#define HW_HDMI_CSC_COEF_B4_MSB_RD()      (HW_HDMI_CSC_COEF_B4_MSB.U)
#define HW_HDMI_CSC_COEF_B4_MSB_WR(v)     (HW_HDMI_CSC_COEF_B4_MSB.U = (v))
#define HW_HDMI_CSC_COEF_B4_MSB_SET(v)    (HW_HDMI_CSC_COEF_B4_MSB_WR(HW_HDMI_CSC_COEF_B4_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_B4_MSB_CLR(v)    (HW_HDMI_CSC_COEF_B4_MSB_WR(HW_HDMI_CSC_COEF_B4_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_B4_MSB_TOG(v)    (HW_HDMI_CSC_COEF_B4_MSB_WR(HW_HDMI_CSC_COEF_B4_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_B4_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_B4_MSB, field CSC_COEF_B4_MSB (RW)
 *
 * Color Space Conversion B4 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB      0
#define BM_HDMI_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB)
#else
#define BF_HDMI_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_B4_MSB field to a new value.
#define BW_HDMI_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB(v)   BF_CS1(HDMI_CSC_COEF_B4_MSB, CSC_COEF_B4_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_B4_LSB - CSC_COEF_B4_LSB (RW)
 *
 * Color Space Conversion B4 coefficient.   Address Offset: 0x4111  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_B4_LSB : 8; //!< Color Space Conversion B4 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_b4_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_B4_LSB register
 */
#define HW_HDMI_CSC_COEF_B4_LSB_ADDR      (REGS_HDMI_BASE + 0x4111)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_B4_LSB           (*(volatile hw_hdmi_csc_coef_b4_lsb_t *) HW_HDMI_CSC_COEF_B4_LSB_ADDR)
#define HW_HDMI_CSC_COEF_B4_LSB_RD()      (HW_HDMI_CSC_COEF_B4_LSB.U)
#define HW_HDMI_CSC_COEF_B4_LSB_WR(v)     (HW_HDMI_CSC_COEF_B4_LSB.U = (v))
#define HW_HDMI_CSC_COEF_B4_LSB_SET(v)    (HW_HDMI_CSC_COEF_B4_LSB_WR(HW_HDMI_CSC_COEF_B4_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_B4_LSB_CLR(v)    (HW_HDMI_CSC_COEF_B4_LSB_WR(HW_HDMI_CSC_COEF_B4_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_B4_LSB_TOG(v)    (HW_HDMI_CSC_COEF_B4_LSB_WR(HW_HDMI_CSC_COEF_B4_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_B4_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_B4_LSB, field CSC_COEF_B4_LSB (RW)
 *
 * Color Space Conversion B4 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB      0
#define BM_HDMI_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB)
#else
#define BF_HDMI_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_B4_LSB field to a new value.
#define BW_HDMI_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB(v)   BF_CS1(HDMI_CSC_COEF_B4_LSB, CSC_COEF_B4_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_C1_MSB - CSC_COEF_C1_MSB (RW)
 *
 * Color Space Conversion C1 coefficient.   Address Offset: 0x4112  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_C1_MSB : 8; //!< Color Space Conversion C1 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_c1_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_C1_MSB register
 */
#define HW_HDMI_CSC_COEF_C1_MSB_ADDR      (REGS_HDMI_BASE + 0x4112)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_C1_MSB           (*(volatile hw_hdmi_csc_coef_c1_msb_t *) HW_HDMI_CSC_COEF_C1_MSB_ADDR)
#define HW_HDMI_CSC_COEF_C1_MSB_RD()      (HW_HDMI_CSC_COEF_C1_MSB.U)
#define HW_HDMI_CSC_COEF_C1_MSB_WR(v)     (HW_HDMI_CSC_COEF_C1_MSB.U = (v))
#define HW_HDMI_CSC_COEF_C1_MSB_SET(v)    (HW_HDMI_CSC_COEF_C1_MSB_WR(HW_HDMI_CSC_COEF_C1_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_C1_MSB_CLR(v)    (HW_HDMI_CSC_COEF_C1_MSB_WR(HW_HDMI_CSC_COEF_C1_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_C1_MSB_TOG(v)    (HW_HDMI_CSC_COEF_C1_MSB_WR(HW_HDMI_CSC_COEF_C1_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_C1_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_C1_MSB, field CSC_COEF_C1_MSB (RW)
 *
 * Color Space Conversion C1 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB      0
#define BM_HDMI_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB)
#else
#define BF_HDMI_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_C1_MSB field to a new value.
#define BW_HDMI_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB(v)   BF_CS1(HDMI_CSC_COEF_C1_MSB, CSC_COEF_C1_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_C1_LSB - CSC_COEF_C1_LSB (RW)
 *
 * Color Space Conversion C1 coefficient.   Address Offset: 0x4113  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_C1_LSB : 8; //!< Color Space Conversion C1 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_c1_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_C1_LSB register
 */
#define HW_HDMI_CSC_COEF_C1_LSB_ADDR      (REGS_HDMI_BASE + 0x4113)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_C1_LSB           (*(volatile hw_hdmi_csc_coef_c1_lsb_t *) HW_HDMI_CSC_COEF_C1_LSB_ADDR)
#define HW_HDMI_CSC_COEF_C1_LSB_RD()      (HW_HDMI_CSC_COEF_C1_LSB.U)
#define HW_HDMI_CSC_COEF_C1_LSB_WR(v)     (HW_HDMI_CSC_COEF_C1_LSB.U = (v))
#define HW_HDMI_CSC_COEF_C1_LSB_SET(v)    (HW_HDMI_CSC_COEF_C1_LSB_WR(HW_HDMI_CSC_COEF_C1_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_C1_LSB_CLR(v)    (HW_HDMI_CSC_COEF_C1_LSB_WR(HW_HDMI_CSC_COEF_C1_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_C1_LSB_TOG(v)    (HW_HDMI_CSC_COEF_C1_LSB_WR(HW_HDMI_CSC_COEF_C1_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_C1_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_C1_LSB, field CSC_COEF_C1_LSB (RW)
 *
 * Color Space Conversion C1 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB      0
#define BM_HDMI_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB)
#else
#define BF_HDMI_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_C1_LSB field to a new value.
#define BW_HDMI_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB(v)   BF_CS1(HDMI_CSC_COEF_C1_LSB, CSC_COEF_C1_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_C2_MSB - CSC_COEF_C2_MSB (RW)
 *
 * Color Space Conversion C2 coefficient.   Address Offset: 0x4114  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_C2_MSB : 8; //!< Color Space Conversion C2 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_c2_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_C2_MSB register
 */
#define HW_HDMI_CSC_COEF_C2_MSB_ADDR      (REGS_HDMI_BASE + 0x4114)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_C2_MSB           (*(volatile hw_hdmi_csc_coef_c2_msb_t *) HW_HDMI_CSC_COEF_C2_MSB_ADDR)
#define HW_HDMI_CSC_COEF_C2_MSB_RD()      (HW_HDMI_CSC_COEF_C2_MSB.U)
#define HW_HDMI_CSC_COEF_C2_MSB_WR(v)     (HW_HDMI_CSC_COEF_C2_MSB.U = (v))
#define HW_HDMI_CSC_COEF_C2_MSB_SET(v)    (HW_HDMI_CSC_COEF_C2_MSB_WR(HW_HDMI_CSC_COEF_C2_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_C2_MSB_CLR(v)    (HW_HDMI_CSC_COEF_C2_MSB_WR(HW_HDMI_CSC_COEF_C2_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_C2_MSB_TOG(v)    (HW_HDMI_CSC_COEF_C2_MSB_WR(HW_HDMI_CSC_COEF_C2_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_C2_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_C2_MSB, field CSC_COEF_C2_MSB (RW)
 *
 * Color Space Conversion C2 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB      0
#define BM_HDMI_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB)
#else
#define BF_HDMI_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_C2_MSB field to a new value.
#define BW_HDMI_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB(v)   BF_CS1(HDMI_CSC_COEF_C2_MSB, CSC_COEF_C2_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_C2_LSB - CSC_COEF_C2_LSB (RW)
 *
 * Color Space Conversion C2 coefficient.   Address Offset: 0x4115  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_C2_LSB : 8; //!< Color Space Conversion C2 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_c2_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_C2_LSB register
 */
#define HW_HDMI_CSC_COEF_C2_LSB_ADDR      (REGS_HDMI_BASE + 0x4115)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_C2_LSB           (*(volatile hw_hdmi_csc_coef_c2_lsb_t *) HW_HDMI_CSC_COEF_C2_LSB_ADDR)
#define HW_HDMI_CSC_COEF_C2_LSB_RD()      (HW_HDMI_CSC_COEF_C2_LSB.U)
#define HW_HDMI_CSC_COEF_C2_LSB_WR(v)     (HW_HDMI_CSC_COEF_C2_LSB.U = (v))
#define HW_HDMI_CSC_COEF_C2_LSB_SET(v)    (HW_HDMI_CSC_COEF_C2_LSB_WR(HW_HDMI_CSC_COEF_C2_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_C2_LSB_CLR(v)    (HW_HDMI_CSC_COEF_C2_LSB_WR(HW_HDMI_CSC_COEF_C2_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_C2_LSB_TOG(v)    (HW_HDMI_CSC_COEF_C2_LSB_WR(HW_HDMI_CSC_COEF_C2_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_C2_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_C2_LSB, field CSC_COEF_C2_LSB (RW)
 *
 * Color Space Conversion C2 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB      0
#define BM_HDMI_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB)
#else
#define BF_HDMI_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_C2_LSB field to a new value.
#define BW_HDMI_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB(v)   BF_CS1(HDMI_CSC_COEF_C2_LSB, CSC_COEF_C2_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_C3_MSB - CSC_COEF_C3_MSB (RW)
 *
 * Color Space Conversion C3 coefficient.   Address Offset: 0x4116  Size: 8 bits  Value after Reset:
 * 0x20  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_C3_MSB : 8; //!< Color Space Conversion C3 MSB coefficient.
    } B;
} hw_hdmi_csc_coef_c3_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_C3_MSB register
 */
#define HW_HDMI_CSC_COEF_C3_MSB_ADDR      (REGS_HDMI_BASE + 0x4116)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_C3_MSB           (*(volatile hw_hdmi_csc_coef_c3_msb_t *) HW_HDMI_CSC_COEF_C3_MSB_ADDR)
#define HW_HDMI_CSC_COEF_C3_MSB_RD()      (HW_HDMI_CSC_COEF_C3_MSB.U)
#define HW_HDMI_CSC_COEF_C3_MSB_WR(v)     (HW_HDMI_CSC_COEF_C3_MSB.U = (v))
#define HW_HDMI_CSC_COEF_C3_MSB_SET(v)    (HW_HDMI_CSC_COEF_C3_MSB_WR(HW_HDMI_CSC_COEF_C3_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_C3_MSB_CLR(v)    (HW_HDMI_CSC_COEF_C3_MSB_WR(HW_HDMI_CSC_COEF_C3_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_C3_MSB_TOG(v)    (HW_HDMI_CSC_COEF_C3_MSB_WR(HW_HDMI_CSC_COEF_C3_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_C3_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_C3_MSB, field CSC_COEF_C3_MSB (RW)
 *
 * Color Space Conversion C3 MSB coefficient.
 */

#define BP_HDMI_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB      0
#define BM_HDMI_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB)
#else
#define BF_HDMI_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_C3_MSB field to a new value.
#define BW_HDMI_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB(v)   BF_CS1(HDMI_CSC_COEF_C3_MSB, CSC_COEF_C3_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEF_C3_LSB - CSC_COEF_C3_LSB (RW)
 *
 * Color Space Conversion C3 coefficient.   Address Offset: 0x4117  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEF_C3_LSB : 8; //!< Color Space Conversion C3 LSB coefficient.
    } B;
} hw_hdmi_csc_coef_c3_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEF_C3_LSB register
 */
#define HW_HDMI_CSC_COEF_C3_LSB_ADDR      (REGS_HDMI_BASE + 0x4117)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEF_C3_LSB           (*(volatile hw_hdmi_csc_coef_c3_lsb_t *) HW_HDMI_CSC_COEF_C3_LSB_ADDR)
#define HW_HDMI_CSC_COEF_C3_LSB_RD()      (HW_HDMI_CSC_COEF_C3_LSB.U)
#define HW_HDMI_CSC_COEF_C3_LSB_WR(v)     (HW_HDMI_CSC_COEF_C3_LSB.U = (v))
#define HW_HDMI_CSC_COEF_C3_LSB_SET(v)    (HW_HDMI_CSC_COEF_C3_LSB_WR(HW_HDMI_CSC_COEF_C3_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEF_C3_LSB_CLR(v)    (HW_HDMI_CSC_COEF_C3_LSB_WR(HW_HDMI_CSC_COEF_C3_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEF_C3_LSB_TOG(v)    (HW_HDMI_CSC_COEF_C3_LSB_WR(HW_HDMI_CSC_COEF_C3_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEF_C3_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEF_C3_LSB, field CSC_COEF_C3_LSB (RW)
 *
 * Color Space Conversion C3 LSB coefficient.
 */

#define BP_HDMI_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB      0
#define BM_HDMI_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB)
#else
#define BF_HDMI_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEF_C3_LSB field to a new value.
#define BW_HDMI_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB(v)   BF_CS1(HDMI_CSC_COEF_C3_LSB, CSC_COEF_C3_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEFC4_MSB - CSC_COEFC4_MSB (RW)
 *
 * Color Space Conversion C4 coefficient.   Address Offset: 0x4118  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEFC4_MSB : 8; //!< Color Space Conversion C4 MSB coefficient.
    } B;
} hw_hdmi_csc_coefc4_msb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEFC4_MSB register
 */
#define HW_HDMI_CSC_COEFC4_MSB_ADDR      (REGS_HDMI_BASE + 0x4118)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEFC4_MSB           (*(volatile hw_hdmi_csc_coefc4_msb_t *) HW_HDMI_CSC_COEFC4_MSB_ADDR)
#define HW_HDMI_CSC_COEFC4_MSB_RD()      (HW_HDMI_CSC_COEFC4_MSB.U)
#define HW_HDMI_CSC_COEFC4_MSB_WR(v)     (HW_HDMI_CSC_COEFC4_MSB.U = (v))
#define HW_HDMI_CSC_COEFC4_MSB_SET(v)    (HW_HDMI_CSC_COEFC4_MSB_WR(HW_HDMI_CSC_COEFC4_MSB_RD() |  (v)))
#define HW_HDMI_CSC_COEFC4_MSB_CLR(v)    (HW_HDMI_CSC_COEFC4_MSB_WR(HW_HDMI_CSC_COEFC4_MSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEFC4_MSB_TOG(v)    (HW_HDMI_CSC_COEFC4_MSB_WR(HW_HDMI_CSC_COEFC4_MSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEFC4_MSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEFC4_MSB, field CSC_COEFC4_MSB (RW)
 *
 * Color Space Conversion C4 MSB coefficient.
 */

#define BP_HDMI_CSC_COEFC4_MSB_CSC_COEFC4_MSB      0
#define BM_HDMI_CSC_COEFC4_MSB_CSC_COEFC4_MSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEFC4_MSB_CSC_COEFC4_MSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEFC4_MSB_CSC_COEFC4_MSB)
#else
#define BF_HDMI_CSC_COEFC4_MSB_CSC_COEFC4_MSB(v)   (((v) << 0) & BM_HDMI_CSC_COEFC4_MSB_CSC_COEFC4_MSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEFC4_MSB field to a new value.
#define BW_HDMI_CSC_COEFC4_MSB_CSC_COEFC4_MSB(v)   BF_CS1(HDMI_CSC_COEFC4_MSB, CSC_COEFC4_MSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CSC_COEFC4_LSB - CSC_COEFC4_LSB (RW)
 *
 * Color Space Conversion C4 coefficient.   Address Offset: 0x4119  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CSC_COEFC4_LSB : 8; //!< Color Space Conversion C4 LSB coefficient.
    } B;
} hw_hdmi_csc_coefc4_lsb_t;
#endif

/*
 * constants & macros for entire HDMI_CSC_COEFC4_LSB register
 */
#define HW_HDMI_CSC_COEFC4_LSB_ADDR      (REGS_HDMI_BASE + 0x4119)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CSC_COEFC4_LSB           (*(volatile hw_hdmi_csc_coefc4_lsb_t *) HW_HDMI_CSC_COEFC4_LSB_ADDR)
#define HW_HDMI_CSC_COEFC4_LSB_RD()      (HW_HDMI_CSC_COEFC4_LSB.U)
#define HW_HDMI_CSC_COEFC4_LSB_WR(v)     (HW_HDMI_CSC_COEFC4_LSB.U = (v))
#define HW_HDMI_CSC_COEFC4_LSB_SET(v)    (HW_HDMI_CSC_COEFC4_LSB_WR(HW_HDMI_CSC_COEFC4_LSB_RD() |  (v)))
#define HW_HDMI_CSC_COEFC4_LSB_CLR(v)    (HW_HDMI_CSC_COEFC4_LSB_WR(HW_HDMI_CSC_COEFC4_LSB_RD() & ~(v)))
#define HW_HDMI_CSC_COEFC4_LSB_TOG(v)    (HW_HDMI_CSC_COEFC4_LSB_WR(HW_HDMI_CSC_COEFC4_LSB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CSC_COEFC4_LSB bitfields
 */

/* --- Register HW_HDMI_CSC_COEFC4_LSB, field CSC_COEFC4_LSB (RW)
 *
 * Color Space Conversion C4 LSB coefficient.
 */

#define BP_HDMI_CSC_COEFC4_LSB_CSC_COEFC4_LSB      0
#define BM_HDMI_CSC_COEFC4_LSB_CSC_COEFC4_LSB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CSC_COEFC4_LSB_CSC_COEFC4_LSB(v)   ((((reg32_t) v) << 0) & BM_HDMI_CSC_COEFC4_LSB_CSC_COEFC4_LSB)
#else
#define BF_HDMI_CSC_COEFC4_LSB_CSC_COEFC4_LSB(v)   (((v) << 0) & BM_HDMI_CSC_COEFC4_LSB_CSC_COEFC4_LSB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_COEFC4_LSB field to a new value.
#define BW_HDMI_CSC_COEFC4_LSB_CSC_COEFC4_LSB(v)   BF_CS1(HDMI_CSC_COEFC4_LSB, CSC_COEFC4_LSB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_HDCPCFG0 - A_HDCPCFG0 (RW)
 *
 * Address Offset: 0x5000  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDMIDVI : 1; //!< Configures the transmitter to operate with a HDMI capable device or with a DVI device.
        unsigned char EN11FEATURE : 1; //!< Enable the use of features 1.1 from the transmitter's side
        unsigned char RXDETECT : 1; //!< Information that a RX device was detected connected to the HDMI port
        unsigned char AVMUTE : 1; //!< Command given by the API system to enter in AVMUTE state
        unsigned char SYNCRICHECK : 1; //!< Configure if the Ri check should be done at every 2s even or synchronously to every 128 encrypted frame.
        unsigned char BYPENCRYPTION : 1; //!< Bypasses all the data encryption stage.
        unsigned char I2CFASTMODE : 1; //!< Enable the I2C fast mode option from the transmitter's side.
        unsigned char ELVENA : 1; //!< Enables the Enhanced Link Verification from the transmitter's side.
    } B;
} hw_hdmi_a_hdcpcfg0_t;
#endif

/*
 * constants & macros for entire HDMI_A_HDCPCFG0 register
 */
#define HW_HDMI_A_HDCPCFG0_ADDR      (REGS_HDMI_BASE + 0x5000)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_HDCPCFG0           (*(volatile hw_hdmi_a_hdcpcfg0_t *) HW_HDMI_A_HDCPCFG0_ADDR)
#define HW_HDMI_A_HDCPCFG0_RD()      (HW_HDMI_A_HDCPCFG0.U)
#define HW_HDMI_A_HDCPCFG0_WR(v)     (HW_HDMI_A_HDCPCFG0.U = (v))
#define HW_HDMI_A_HDCPCFG0_SET(v)    (HW_HDMI_A_HDCPCFG0_WR(HW_HDMI_A_HDCPCFG0_RD() |  (v)))
#define HW_HDMI_A_HDCPCFG0_CLR(v)    (HW_HDMI_A_HDCPCFG0_WR(HW_HDMI_A_HDCPCFG0_RD() & ~(v)))
#define HW_HDMI_A_HDCPCFG0_TOG(v)    (HW_HDMI_A_HDCPCFG0_WR(HW_HDMI_A_HDCPCFG0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_A_HDCPCFG0 bitfields
 */

/* --- Register HW_HDMI_A_HDCPCFG0, field HDMIDVI (RW)
 *
 * Configures the transmitter to operate with a HDMI capable device or with a DVI device.
 */

#define BP_HDMI_A_HDCPCFG0_HDMIDVI      0
#define BM_HDMI_A_HDCPCFG0_HDMIDVI      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG0_HDMIDVI(v)   ((((reg32_t) v) << 0) & BM_HDMI_A_HDCPCFG0_HDMIDVI)
#else
#define BF_HDMI_A_HDCPCFG0_HDMIDVI(v)   (((v) << 0) & BM_HDMI_A_HDCPCFG0_HDMIDVI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDMIDVI field to a new value.
#define BW_HDMI_A_HDCPCFG0_HDMIDVI(v)   BF_CS1(HDMI_A_HDCPCFG0, HDMIDVI, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG0, field EN11FEATURE (RW)
 *
 * Enable the use of features 1.1 from the transmitter's side
 */

#define BP_HDMI_A_HDCPCFG0_EN11FEATURE      1
#define BM_HDMI_A_HDCPCFG0_EN11FEATURE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG0_EN11FEATURE(v)   ((((reg32_t) v) << 1) & BM_HDMI_A_HDCPCFG0_EN11FEATURE)
#else
#define BF_HDMI_A_HDCPCFG0_EN11FEATURE(v)   (((v) << 1) & BM_HDMI_A_HDCPCFG0_EN11FEATURE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN11FEATURE field to a new value.
#define BW_HDMI_A_HDCPCFG0_EN11FEATURE(v)   BF_CS1(HDMI_A_HDCPCFG0, EN11FEATURE, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG0, field RXDETECT (RW)
 *
 * Information that a RX device was detected connected to the HDMI port
 */

#define BP_HDMI_A_HDCPCFG0_RXDETECT      2
#define BM_HDMI_A_HDCPCFG0_RXDETECT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG0_RXDETECT(v)   ((((reg32_t) v) << 2) & BM_HDMI_A_HDCPCFG0_RXDETECT)
#else
#define BF_HDMI_A_HDCPCFG0_RXDETECT(v)   (((v) << 2) & BM_HDMI_A_HDCPCFG0_RXDETECT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDETECT field to a new value.
#define BW_HDMI_A_HDCPCFG0_RXDETECT(v)   BF_CS1(HDMI_A_HDCPCFG0, RXDETECT, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG0, field AVMUTE (RW)
 *
 * Command given by the API system to enter in AVMUTE state
 */

#define BP_HDMI_A_HDCPCFG0_AVMUTE      3
#define BM_HDMI_A_HDCPCFG0_AVMUTE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG0_AVMUTE(v)   ((((reg32_t) v) << 3) & BM_HDMI_A_HDCPCFG0_AVMUTE)
#else
#define BF_HDMI_A_HDCPCFG0_AVMUTE(v)   (((v) << 3) & BM_HDMI_A_HDCPCFG0_AVMUTE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVMUTE field to a new value.
#define BW_HDMI_A_HDCPCFG0_AVMUTE(v)   BF_CS1(HDMI_A_HDCPCFG0, AVMUTE, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG0, field SYNCRICHECK (RW)
 *
 * Configure if the Ri check should be done at every 2s even or synchronously to every 128 encrypted
 * frame.
 */

#define BP_HDMI_A_HDCPCFG0_SYNCRICHECK      4
#define BM_HDMI_A_HDCPCFG0_SYNCRICHECK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG0_SYNCRICHECK(v)   ((((reg32_t) v) << 4) & BM_HDMI_A_HDCPCFG0_SYNCRICHECK)
#else
#define BF_HDMI_A_HDCPCFG0_SYNCRICHECK(v)   (((v) << 4) & BM_HDMI_A_HDCPCFG0_SYNCRICHECK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYNCRICHECK field to a new value.
#define BW_HDMI_A_HDCPCFG0_SYNCRICHECK(v)   BF_CS1(HDMI_A_HDCPCFG0, SYNCRICHECK, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG0, field BYPENCRYPTION (RW)
 *
 * Bypasses all the data encryption stage.
 */

#define BP_HDMI_A_HDCPCFG0_BYPENCRYPTION      5
#define BM_HDMI_A_HDCPCFG0_BYPENCRYPTION      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG0_BYPENCRYPTION(v)   ((((reg32_t) v) << 5) & BM_HDMI_A_HDCPCFG0_BYPENCRYPTION)
#else
#define BF_HDMI_A_HDCPCFG0_BYPENCRYPTION(v)   (((v) << 5) & BM_HDMI_A_HDCPCFG0_BYPENCRYPTION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPENCRYPTION field to a new value.
#define BW_HDMI_A_HDCPCFG0_BYPENCRYPTION(v)   BF_CS1(HDMI_A_HDCPCFG0, BYPENCRYPTION, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG0, field I2CFASTMODE (RW)
 *
 * Enable the I2C fast mode option from the transmitter's side.
 */

#define BP_HDMI_A_HDCPCFG0_I2CFASTMODE      6
#define BM_HDMI_A_HDCPCFG0_I2CFASTMODE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG0_I2CFASTMODE(v)   ((((reg32_t) v) << 6) & BM_HDMI_A_HDCPCFG0_I2CFASTMODE)
#else
#define BF_HDMI_A_HDCPCFG0_I2CFASTMODE(v)   (((v) << 6) & BM_HDMI_A_HDCPCFG0_I2CFASTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CFASTMODE field to a new value.
#define BW_HDMI_A_HDCPCFG0_I2CFASTMODE(v)   BF_CS1(HDMI_A_HDCPCFG0, I2CFASTMODE, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG0, field ELVENA (RW)
 *
 * Enables the Enhanced Link Verification from the transmitter's side.
 */

#define BP_HDMI_A_HDCPCFG0_ELVENA      7
#define BM_HDMI_A_HDCPCFG0_ELVENA      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG0_ELVENA(v)   ((((reg32_t) v) << 7) & BM_HDMI_A_HDCPCFG0_ELVENA)
#else
#define BF_HDMI_A_HDCPCFG0_ELVENA(v)   (((v) << 7) & BM_HDMI_A_HDCPCFG0_ELVENA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ELVENA field to a new value.
#define BW_HDMI_A_HDCPCFG0_ELVENA(v)   BF_CS1(HDMI_A_HDCPCFG0, ELVENA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_HDCPCFG1 - A_HDCPCFG1 (RW)
 *
 * Address Offset: 0x5001  Size: 8 bits  Value after Reset: 0x01  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char SWRESET : 1; //!< Software reset signal, active by writing a zero and auto cleared to one in the following cycle.
        unsigned char ENCRYPTIONDISABLE : 1; //!< Disable encryption without losing authentication.
        unsigned char PH2UPSHFTENC : 1; //!< This bit enables the encoding of packet header in the tmdsch0 bit[0] with cipher[2] instead of the tmdsch0 bit[2].
        unsigned char DISSHA1CHECK : 1; //!< This bit disables the request to the API processor to verify the SHA1 message digest of a received KSV List.
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_a_hdcpcfg1_t;
#endif

/*
 * constants & macros for entire HDMI_A_HDCPCFG1 register
 */
#define HW_HDMI_A_HDCPCFG1_ADDR      (REGS_HDMI_BASE + 0x5001)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_HDCPCFG1           (*(volatile hw_hdmi_a_hdcpcfg1_t *) HW_HDMI_A_HDCPCFG1_ADDR)
#define HW_HDMI_A_HDCPCFG1_RD()      (HW_HDMI_A_HDCPCFG1.U)
#define HW_HDMI_A_HDCPCFG1_WR(v)     (HW_HDMI_A_HDCPCFG1.U = (v))
#define HW_HDMI_A_HDCPCFG1_SET(v)    (HW_HDMI_A_HDCPCFG1_WR(HW_HDMI_A_HDCPCFG1_RD() |  (v)))
#define HW_HDMI_A_HDCPCFG1_CLR(v)    (HW_HDMI_A_HDCPCFG1_WR(HW_HDMI_A_HDCPCFG1_RD() & ~(v)))
#define HW_HDMI_A_HDCPCFG1_TOG(v)    (HW_HDMI_A_HDCPCFG1_WR(HW_HDMI_A_HDCPCFG1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_A_HDCPCFG1 bitfields
 */

/* --- Register HW_HDMI_A_HDCPCFG1, field SWRESET (RW)
 *
 * Software reset signal, active by writing a zero and auto cleared to one in the following cycle.
 */

#define BP_HDMI_A_HDCPCFG1_SWRESET      0
#define BM_HDMI_A_HDCPCFG1_SWRESET      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG1_SWRESET(v)   ((((reg32_t) v) << 0) & BM_HDMI_A_HDCPCFG1_SWRESET)
#else
#define BF_HDMI_A_HDCPCFG1_SWRESET(v)   (((v) << 0) & BM_HDMI_A_HDCPCFG1_SWRESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SWRESET field to a new value.
#define BW_HDMI_A_HDCPCFG1_SWRESET(v)   BF_CS1(HDMI_A_HDCPCFG1, SWRESET, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG1, field ENCRYPTIONDISABLE (RW)
 *
 * Disable encryption without losing authentication.
 */

#define BP_HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE      1
#define BM_HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE(v)   ((((reg32_t) v) << 1) & BM_HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE)
#else
#define BF_HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE(v)   (((v) << 1) & BM_HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENCRYPTIONDISABLE field to a new value.
#define BW_HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE(v)   BF_CS1(HDMI_A_HDCPCFG1, ENCRYPTIONDISABLE, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG1, field PH2UPSHFTENC (RW)
 *
 * This bit enables the encoding of packet header in the tmdsch0 bit[0] with cipher[2] instead of
 * the tmdsch0 bit[2].
 */

#define BP_HDMI_A_HDCPCFG1_PH2UPSHFTENC      2
#define BM_HDMI_A_HDCPCFG1_PH2UPSHFTENC      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG1_PH2UPSHFTENC(v)   ((((reg32_t) v) << 2) & BM_HDMI_A_HDCPCFG1_PH2UPSHFTENC)
#else
#define BF_HDMI_A_HDCPCFG1_PH2UPSHFTENC(v)   (((v) << 2) & BM_HDMI_A_HDCPCFG1_PH2UPSHFTENC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PH2UPSHFTENC field to a new value.
#define BW_HDMI_A_HDCPCFG1_PH2UPSHFTENC(v)   BF_CS1(HDMI_A_HDCPCFG1, PH2UPSHFTENC, v)
#endif

/* --- Register HW_HDMI_A_HDCPCFG1, field DISSHA1CHECK (RW)
 *
 * This bit disables the request to the API processor to verify the SHA1 message digest of a
 * received KSV List.
 */

#define BP_HDMI_A_HDCPCFG1_DISSHA1CHECK      3
#define BM_HDMI_A_HDCPCFG1_DISSHA1CHECK      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_HDCPCFG1_DISSHA1CHECK(v)   ((((reg32_t) v) << 3) & BM_HDMI_A_HDCPCFG1_DISSHA1CHECK)
#else
#define BF_HDMI_A_HDCPCFG1_DISSHA1CHECK(v)   (((v) << 3) & BM_HDMI_A_HDCPCFG1_DISSHA1CHECK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISSHA1CHECK field to a new value.
#define BW_HDMI_A_HDCPCFG1_DISSHA1CHECK(v)   BF_CS1(HDMI_A_HDCPCFG1, DISSHA1CHECK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_HDCPOBS0 - A_HDCPOBS0 (RO)
 *
 * Address Offset: 0x5002  Size: 8 bits  Value after Reset: N/A  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPENGAGED : 1; //!< Informs that the current HDMI link has the HDCP protocol fully engaged.
        unsigned char DISSHA1CHECK : 3; //!< Observability register informs in which sub-state the authentication is on.
        unsigned char STATEA : 4; //!< Observability register informs in which state the authentication machine is on.
    } B;
} hw_hdmi_a_hdcpobs0_t;
#endif

/*
 * constants & macros for entire HDMI_A_HDCPOBS0 register
 */
#define HW_HDMI_A_HDCPOBS0_ADDR      (REGS_HDMI_BASE + 0x5002)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_HDCPOBS0           (*(volatile hw_hdmi_a_hdcpobs0_t *) HW_HDMI_A_HDCPOBS0_ADDR)
#define HW_HDMI_A_HDCPOBS0_RD()      (HW_HDMI_A_HDCPOBS0.U)
#endif

/*
 * constants & macros for individual HDMI_A_HDCPOBS0 bitfields
 */

/* --- Register HW_HDMI_A_HDCPOBS0, field HDCPENGAGED (RO)
 *
 * Informs that the current HDMI link has the HDCP protocol fully engaged.
 */

#define BP_HDMI_A_HDCPOBS0_HDCPENGAGED      0
#define BM_HDMI_A_HDCPOBS0_HDCPENGAGED      0x00000001

/* --- Register HW_HDMI_A_HDCPOBS0, field DISSHA1CHECK (RO)
 *
 * Observability register informs in which sub-state the authentication is on.
 */

#define BP_HDMI_A_HDCPOBS0_DISSHA1CHECK      1
#define BM_HDMI_A_HDCPOBS0_DISSHA1CHECK      0x0000000e

/* --- Register HW_HDMI_A_HDCPOBS0, field STATEA (RO)
 *
 * Observability register informs in which state the authentication machine is on.
 */

#define BP_HDMI_A_HDCPOBS0_STATEA      4
#define BM_HDMI_A_HDCPOBS0_STATEA      0x000000f0

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_HDCPOBS1 - A_HDCPOBS1 (RO)
 *
 * Address Offset: 0x5003  Size: 8 bits  Value after Reset: N/A  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char STATER : 3; //!< Observability register informs in which state the revocation machine is on.
        unsigned char STATEOEG : 3; //!< Observability register informs in which state the OESS machine is on.
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_a_hdcpobs1_t;
#endif

/*
 * constants & macros for entire HDMI_A_HDCPOBS1 register
 */
#define HW_HDMI_A_HDCPOBS1_ADDR      (REGS_HDMI_BASE + 0x5003)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_HDCPOBS1           (*(volatile hw_hdmi_a_hdcpobs1_t *) HW_HDMI_A_HDCPOBS1_ADDR)
#define HW_HDMI_A_HDCPOBS1_RD()      (HW_HDMI_A_HDCPOBS1.U)
#endif

/*
 * constants & macros for individual HDMI_A_HDCPOBS1 bitfields
 */

/* --- Register HW_HDMI_A_HDCPOBS1, field STATER (RO)
 *
 * Observability register informs in which state the revocation machine is on.
 */

#define BP_HDMI_A_HDCPOBS1_STATER      0
#define BM_HDMI_A_HDCPOBS1_STATER      0x00000007

/* --- Register HW_HDMI_A_HDCPOBS1, field STATEOEG (RO)
 *
 * Observability register informs in which state the OESS machine is on.
 */

#define BP_HDMI_A_HDCPOBS1_STATEOEG      3
#define BM_HDMI_A_HDCPOBS1_STATEOEG      0x00000038

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_HDCPOBS2 - A_HDCPOBS2 (RO)
 *
 * Address Offset: 0x5004  Size: 8 bits  Value after Reset: N/A  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char STATEEEG : 3; //!< Observability register informs in which state the EESS machine is on.
        unsigned char STATEE : 3; //!< Observability register informs in which state the cipher machine is on.
        unsigned char RESERVED0 : 2; //!< Reserved
    } B;
} hw_hdmi_a_hdcpobs2_t;
#endif

/*
 * constants & macros for entire HDMI_A_HDCPOBS2 register
 */
#define HW_HDMI_A_HDCPOBS2_ADDR      (REGS_HDMI_BASE + 0x5004)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_HDCPOBS2           (*(volatile hw_hdmi_a_hdcpobs2_t *) HW_HDMI_A_HDCPOBS2_ADDR)
#define HW_HDMI_A_HDCPOBS2_RD()      (HW_HDMI_A_HDCPOBS2.U)
#endif

/*
 * constants & macros for individual HDMI_A_HDCPOBS2 bitfields
 */

/* --- Register HW_HDMI_A_HDCPOBS2, field STATEEEG (RO)
 *
 * Observability register informs in which state the EESS machine is on.
 */

#define BP_HDMI_A_HDCPOBS2_STATEEEG      0
#define BM_HDMI_A_HDCPOBS2_STATEEEG      0x00000007

/* --- Register HW_HDMI_A_HDCPOBS2, field STATEE (RO)
 *
 * Observability register informs in which state the cipher machine is on.
 */

#define BP_HDMI_A_HDCPOBS2_STATEE      3
#define BM_HDMI_A_HDCPOBS2_STATEE      0x00000038

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_HDCPOBS3 - A_HDCPOBS3 (RO)
 *
 * Address Offset: 0x5005  Size: 8 bits  Value after Reset: N/A  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char FAST_REAUTHENTICATION : 1; //!< From RX: Bcap(0x40) bit 0.
        unsigned char FEATURES_1_1 : 1; //!< From RX: Bcap(0x40) bit 1.
        unsigned char HDMI_MODE : 1; //!< From RX: Bstatus(0x41) bit 12.
        unsigned char HDMI_RESERVED_2 : 1; //!< From RX: Bstatus(0x41) bit 13.
        unsigned char FAST_I_2C : 1; //!< From RX: Bcap(0x40) bit 4.
        unsigned char KSV_FIFO_READY : 1; //!< From RX: Bcap(0x40) bit 5.
        unsigned char REPEATER : 1; //!< From RX: Bcap(0x40) bit 6.
        unsigned char HDMI_RESERVED_1 : 1; //!< From RX: Bcap(0x40) bit 7.
    } B;
} hw_hdmi_a_hdcpobs3_t;
#endif

/*
 * constants & macros for entire HDMI_A_HDCPOBS3 register
 */
#define HW_HDMI_A_HDCPOBS3_ADDR      (REGS_HDMI_BASE + 0x5005)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_HDCPOBS3           (*(volatile hw_hdmi_a_hdcpobs3_t *) HW_HDMI_A_HDCPOBS3_ADDR)
#define HW_HDMI_A_HDCPOBS3_RD()      (HW_HDMI_A_HDCPOBS3.U)
#endif

/*
 * constants & macros for individual HDMI_A_HDCPOBS3 bitfields
 */

/* --- Register HW_HDMI_A_HDCPOBS3, field FAST_REAUTHENTICATION (RO)
 *
 * From RX: Bcap(0x40) bit 0.
 */

#define BP_HDMI_A_HDCPOBS3_FAST_REAUTHENTICATION      0
#define BM_HDMI_A_HDCPOBS3_FAST_REAUTHENTICATION      0x00000001

/* --- Register HW_HDMI_A_HDCPOBS3, field FEATURES_1_1 (RO)
 *
 * From RX: Bcap(0x40) bit 1.
 */

#define BP_HDMI_A_HDCPOBS3_FEATURES_1_1      1
#define BM_HDMI_A_HDCPOBS3_FEATURES_1_1      0x00000002

/* --- Register HW_HDMI_A_HDCPOBS3, field HDMI_MODE (RO)
 *
 * From RX: Bstatus(0x41) bit 12.
 */

#define BP_HDMI_A_HDCPOBS3_HDMI_MODE      2
#define BM_HDMI_A_HDCPOBS3_HDMI_MODE      0x00000004

/* --- Register HW_HDMI_A_HDCPOBS3, field HDMI_RESERVED_2 (RO)
 *
 * From RX: Bstatus(0x41) bit 13.
 */

#define BP_HDMI_A_HDCPOBS3_HDMI_RESERVED_2      3
#define BM_HDMI_A_HDCPOBS3_HDMI_RESERVED_2      0x00000008

/* --- Register HW_HDMI_A_HDCPOBS3, field FAST_I_2C (RO)
 *
 * From RX: Bcap(0x40) bit 4.
 */

#define BP_HDMI_A_HDCPOBS3_FAST_I_2C      4
#define BM_HDMI_A_HDCPOBS3_FAST_I_2C      0x00000010

/* --- Register HW_HDMI_A_HDCPOBS3, field KSV_FIFO_READY (RO)
 *
 * From RX: Bcap(0x40) bit 5.
 */

#define BP_HDMI_A_HDCPOBS3_KSV_FIFO_READY      5
#define BM_HDMI_A_HDCPOBS3_KSV_FIFO_READY      0x00000020

/* --- Register HW_HDMI_A_HDCPOBS3, field REPEATER (RO)
 *
 * From RX: Bcap(0x40) bit 6.
 */

#define BP_HDMI_A_HDCPOBS3_REPEATER      6
#define BM_HDMI_A_HDCPOBS3_REPEATER      0x00000040

/* --- Register HW_HDMI_A_HDCPOBS3, field HDMI_RESERVED_1 (RO)
 *
 * From RX: Bcap(0x40) bit 7.
 */

#define BP_HDMI_A_HDCPOBS3_HDMI_RESERVED_1      7
#define BM_HDMI_A_HDCPOBS3_HDMI_RESERVED_1      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_APIINTCLR - A_APIINTCLR (WO)
 *
 * Write only register, active high and auto cleared, cleans the respective interruption in the
 * interrupt status register.   Address Offset: 0x5006  Size: 8 bits  Value after Reset: N/A
 * Access: Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char KSVACCESSINT : 1; //!< Clear the interruption related to KSV memory access grant for Read-Write access.
        unsigned char KSVSHA1CALCINT : 1; //!< Clear the interruption related to KSV list update in memory that needs to be SHA1 verified.
        unsigned char KEEPOUTERRORINT : 1; //!< Clear the interruption related to keep out window error.
        unsigned char LOSTARBITRATION : 1; //!< Clear the interruption related to I2C arbitration lost.
        unsigned char I2CNACK : 1; //!< Clear the interruption related to I2C NACK reception.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char HDCP_FAILED : 1; //!< Clear the interruption related to HDCP authentication process failed.
        unsigned char HDCP_ENGAGED : 1; //!< Clear the interruption related to HDCP authentication process successful.
    } B;
} hw_hdmi_a_apiintclr_t;
#endif

/*
 * constants & macros for entire HDMI_A_APIINTCLR register
 */
#define HW_HDMI_A_APIINTCLR_ADDR      (REGS_HDMI_BASE + 0x5006)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_APIINTCLR           (*(volatile hw_hdmi_a_apiintclr_t *) HW_HDMI_A_APIINTCLR_ADDR)
#define HW_HDMI_A_APIINTCLR_WR(v)     (HW_HDMI_A_APIINTCLR.U = (v))
#endif

/*
 * constants & macros for individual HDMI_A_APIINTCLR bitfields
 */

/* --- Register HW_HDMI_A_APIINTCLR, field KSVACCESSINT (WO)
 *
 * Clear the interruption related to KSV memory access grant for Read-Write access.
 */

#define BP_HDMI_A_APIINTCLR_KSVACCESSINT      0
#define BM_HDMI_A_APIINTCLR_KSVACCESSINT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTCLR_KSVACCESSINT(v)   ((((reg32_t) v) << 0) & BM_HDMI_A_APIINTCLR_KSVACCESSINT)
#else
#define BF_HDMI_A_APIINTCLR_KSVACCESSINT(v)   (((v) << 0) & BM_HDMI_A_APIINTCLR_KSVACCESSINT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KSVACCESSINT field to a new value.
#define BW_HDMI_A_APIINTCLR_KSVACCESSINT(v)   BF_CS1(HDMI_A_APIINTCLR, KSVACCESSINT, v)
#endif

/* --- Register HW_HDMI_A_APIINTCLR, field KSVSHA1CALCINT (WO)
 *
 * Clear the interruption related to KSV list update in memory that needs to be SHA1 verified.
 */

#define BP_HDMI_A_APIINTCLR_KSVSHA1CALCINT      1
#define BM_HDMI_A_APIINTCLR_KSVSHA1CALCINT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTCLR_KSVSHA1CALCINT(v)   ((((reg32_t) v) << 1) & BM_HDMI_A_APIINTCLR_KSVSHA1CALCINT)
#else
#define BF_HDMI_A_APIINTCLR_KSVSHA1CALCINT(v)   (((v) << 1) & BM_HDMI_A_APIINTCLR_KSVSHA1CALCINT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KSVSHA1CALCINT field to a new value.
#define BW_HDMI_A_APIINTCLR_KSVSHA1CALCINT(v)   BF_CS1(HDMI_A_APIINTCLR, KSVSHA1CALCINT, v)
#endif

/* --- Register HW_HDMI_A_APIINTCLR, field KEEPOUTERRORINT (WO)
 *
 * Clear the interruption related to keep out window error.
 */

#define BP_HDMI_A_APIINTCLR_KEEPOUTERRORINT      2
#define BM_HDMI_A_APIINTCLR_KEEPOUTERRORINT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTCLR_KEEPOUTERRORINT(v)   ((((reg32_t) v) << 2) & BM_HDMI_A_APIINTCLR_KEEPOUTERRORINT)
#else
#define BF_HDMI_A_APIINTCLR_KEEPOUTERRORINT(v)   (((v) << 2) & BM_HDMI_A_APIINTCLR_KEEPOUTERRORINT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KEEPOUTERRORINT field to a new value.
#define BW_HDMI_A_APIINTCLR_KEEPOUTERRORINT(v)   BF_CS1(HDMI_A_APIINTCLR, KEEPOUTERRORINT, v)
#endif

/* --- Register HW_HDMI_A_APIINTCLR, field LOSTARBITRATION (WO)
 *
 * Clear the interruption related to I2C arbitration lost.
 */

#define BP_HDMI_A_APIINTCLR_LOSTARBITRATION      3
#define BM_HDMI_A_APIINTCLR_LOSTARBITRATION      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTCLR_LOSTARBITRATION(v)   ((((reg32_t) v) << 3) & BM_HDMI_A_APIINTCLR_LOSTARBITRATION)
#else
#define BF_HDMI_A_APIINTCLR_LOSTARBITRATION(v)   (((v) << 3) & BM_HDMI_A_APIINTCLR_LOSTARBITRATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOSTARBITRATION field to a new value.
#define BW_HDMI_A_APIINTCLR_LOSTARBITRATION(v)   BF_CS1(HDMI_A_APIINTCLR, LOSTARBITRATION, v)
#endif

/* --- Register HW_HDMI_A_APIINTCLR, field I2CNACK (WO)
 *
 * Clear the interruption related to I2C NACK reception.
 */

#define BP_HDMI_A_APIINTCLR_I2CNACK      4
#define BM_HDMI_A_APIINTCLR_I2CNACK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTCLR_I2CNACK(v)   ((((reg32_t) v) << 4) & BM_HDMI_A_APIINTCLR_I2CNACK)
#else
#define BF_HDMI_A_APIINTCLR_I2CNACK(v)   (((v) << 4) & BM_HDMI_A_APIINTCLR_I2CNACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CNACK field to a new value.
#define BW_HDMI_A_APIINTCLR_I2CNACK(v)   BF_CS1(HDMI_A_APIINTCLR, I2CNACK, v)
#endif

/* --- Register HW_HDMI_A_APIINTCLR, field HDCP_FAILED (WO)
 *
 * Clear the interruption related to HDCP authentication process failed.
 */

#define BP_HDMI_A_APIINTCLR_HDCP_FAILED      6
#define BM_HDMI_A_APIINTCLR_HDCP_FAILED      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTCLR_HDCP_FAILED(v)   ((((reg32_t) v) << 6) & BM_HDMI_A_APIINTCLR_HDCP_FAILED)
#else
#define BF_HDMI_A_APIINTCLR_HDCP_FAILED(v)   (((v) << 6) & BM_HDMI_A_APIINTCLR_HDCP_FAILED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCP_FAILED field to a new value.
#define BW_HDMI_A_APIINTCLR_HDCP_FAILED(v)   BF_CS1(HDMI_A_APIINTCLR, HDCP_FAILED, v)
#endif

/* --- Register HW_HDMI_A_APIINTCLR, field HDCP_ENGAGED (WO)
 *
 * Clear the interruption related to HDCP authentication process successful.
 */

#define BP_HDMI_A_APIINTCLR_HDCP_ENGAGED      7
#define BM_HDMI_A_APIINTCLR_HDCP_ENGAGED      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTCLR_HDCP_ENGAGED(v)   ((((reg32_t) v) << 7) & BM_HDMI_A_APIINTCLR_HDCP_ENGAGED)
#else
#define BF_HDMI_A_APIINTCLR_HDCP_ENGAGED(v)   (((v) << 7) & BM_HDMI_A_APIINTCLR_HDCP_ENGAGED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCP_ENGAGED field to a new value.
#define BW_HDMI_A_APIINTCLR_HDCP_ENGAGED(v)   BF_CS1(HDMI_A_APIINTCLR, HDCP_ENGAGED, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_APIINTSTAT - A_APIINTSTAT (RO)
 *
 * Read only register, reports the interruption which caused the activation of the interruption
 * output pin.   Address Offset: 0x5007  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char KSVACCESSINT : 1; //!< Notifies that the KSV memory access as been guaranteed for Read-Write access.
        unsigned char KSVSHA1CALCINT : 1; //!< Notifies that the HDCP13TCTRL core as updated a KSV list in memory that needs to be SHA1 verified.
        unsigned char KEEPOUTERRORINT : 1; //!< Notifies that during the keep out window, the ctlout[3:0] bus was used besides control period.
        unsigned char LOSTARBITRATION : 1; //!< Notifies that the I2C lost the arbitration to communicate. Another master gained arbitration.
        unsigned char I2CNACK : 1; //!< Notifies that the I2C received a NACK from slave device.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char HDCP_FAILED : 1; //!< Notifies that the HDCP authentication process was failed.
        unsigned char HCDP_ENGAGED : 1; //!< Notifies that the HDCP authentication process was successful.
    } B;
} hw_hdmi_a_apiintstat_t;
#endif

/*
 * constants & macros for entire HDMI_A_APIINTSTAT register
 */
#define HW_HDMI_A_APIINTSTAT_ADDR      (REGS_HDMI_BASE + 0x5007)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_APIINTSTAT           (*(volatile hw_hdmi_a_apiintstat_t *) HW_HDMI_A_APIINTSTAT_ADDR)
#define HW_HDMI_A_APIINTSTAT_RD()      (HW_HDMI_A_APIINTSTAT.U)
#endif

/*
 * constants & macros for individual HDMI_A_APIINTSTAT bitfields
 */

/* --- Register HW_HDMI_A_APIINTSTAT, field KSVACCESSINT (RO)
 *
 * Notifies that the KSV memory access as been guaranteed for Read-Write access.
 */

#define BP_HDMI_A_APIINTSTAT_KSVACCESSINT      0
#define BM_HDMI_A_APIINTSTAT_KSVACCESSINT      0x00000001

/* --- Register HW_HDMI_A_APIINTSTAT, field KSVSHA1CALCINT (RO)
 *
 * Notifies that the HDCP13TCTRL core as updated a KSV list in memory that needs to be SHA1
 * verified.
 */

#define BP_HDMI_A_APIINTSTAT_KSVSHA1CALCINT      1
#define BM_HDMI_A_APIINTSTAT_KSVSHA1CALCINT      0x00000002

/* --- Register HW_HDMI_A_APIINTSTAT, field KEEPOUTERRORINT (RO)
 *
 * Notifies that during the keep out window, the ctlout[3:0] bus was used besides control period.
 */

#define BP_HDMI_A_APIINTSTAT_KEEPOUTERRORINT      2
#define BM_HDMI_A_APIINTSTAT_KEEPOUTERRORINT      0x00000004

/* --- Register HW_HDMI_A_APIINTSTAT, field LOSTARBITRATION (RO)
 *
 * Notifies that the I2C lost the arbitration to communicate. Another master gained arbitration.
 */

#define BP_HDMI_A_APIINTSTAT_LOSTARBITRATION      3
#define BM_HDMI_A_APIINTSTAT_LOSTARBITRATION      0x00000008

/* --- Register HW_HDMI_A_APIINTSTAT, field I2CNACK (RO)
 *
 * Notifies that the I2C received a NACK from slave device.
 */

#define BP_HDMI_A_APIINTSTAT_I2CNACK      4
#define BM_HDMI_A_APIINTSTAT_I2CNACK      0x00000010

/* --- Register HW_HDMI_A_APIINTSTAT, field HDCP_FAILED (RO)
 *
 * Notifies that the HDCP authentication process was failed.
 */

#define BP_HDMI_A_APIINTSTAT_HDCP_FAILED      6
#define BM_HDMI_A_APIINTSTAT_HDCP_FAILED      0x00000040

/* --- Register HW_HDMI_A_APIINTSTAT, field HCDP_ENGAGED (RO)
 *
 * Notifies that the HDCP authentication process was successful.
 */

#define BP_HDMI_A_APIINTSTAT_HCDP_ENGAGED      7
#define BM_HDMI_A_APIINTSTAT_HCDP_ENGAGED      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_APIINTMSK - A_APIINTMSK (RW)
 *
 * The configuration of this register mask a given setup of interruption, disabling them from
 * generating interruption pulses in the interruption output pin.   Address Offset: 0x5008  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char KSVACCESSINT : 1; //!< Masks the interruption related to KSV memory access grant for Read-Write access.
        unsigned char KSVSHA1CALCINT : 1; //!< Masks the interruption related to KSV list update in memory that needs to be SHA1 verified.
        unsigned char KEEPOUTERRORINT : 1; //!< Masks the interruption related to keep out window error.
        unsigned char LOSTARBITRATION : 1; //!< Masks the interruption related to I2C arbitration lost.
        unsigned char I2CNACK : 1; //!< Masks the interruption related to I2C NACK reception.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char HDCP_FAILED : 1; //!< Masks the interruption related to HDCP authentication process failed.
        unsigned char HCDP_ENGAGED : 1; //!< Masks the interruption related to HDCP authentication process successful.
    } B;
} hw_hdmi_a_apiintmsk_t;
#endif

/*
 * constants & macros for entire HDMI_A_APIINTMSK register
 */
#define HW_HDMI_A_APIINTMSK_ADDR      (REGS_HDMI_BASE + 0x5008)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_APIINTMSK           (*(volatile hw_hdmi_a_apiintmsk_t *) HW_HDMI_A_APIINTMSK_ADDR)
#define HW_HDMI_A_APIINTMSK_RD()      (HW_HDMI_A_APIINTMSK.U)
#define HW_HDMI_A_APIINTMSK_WR(v)     (HW_HDMI_A_APIINTMSK.U = (v))
#define HW_HDMI_A_APIINTMSK_SET(v)    (HW_HDMI_A_APIINTMSK_WR(HW_HDMI_A_APIINTMSK_RD() |  (v)))
#define HW_HDMI_A_APIINTMSK_CLR(v)    (HW_HDMI_A_APIINTMSK_WR(HW_HDMI_A_APIINTMSK_RD() & ~(v)))
#define HW_HDMI_A_APIINTMSK_TOG(v)    (HW_HDMI_A_APIINTMSK_WR(HW_HDMI_A_APIINTMSK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_A_APIINTMSK bitfields
 */

/* --- Register HW_HDMI_A_APIINTMSK, field KSVACCESSINT (RW)
 *
 * Masks the interruption related to KSV memory access grant for Read-Write access.
 */

#define BP_HDMI_A_APIINTMSK_KSVACCESSINT      0
#define BM_HDMI_A_APIINTMSK_KSVACCESSINT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTMSK_KSVACCESSINT(v)   ((((reg32_t) v) << 0) & BM_HDMI_A_APIINTMSK_KSVACCESSINT)
#else
#define BF_HDMI_A_APIINTMSK_KSVACCESSINT(v)   (((v) << 0) & BM_HDMI_A_APIINTMSK_KSVACCESSINT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KSVACCESSINT field to a new value.
#define BW_HDMI_A_APIINTMSK_KSVACCESSINT(v)   BF_CS1(HDMI_A_APIINTMSK, KSVACCESSINT, v)
#endif

/* --- Register HW_HDMI_A_APIINTMSK, field KSVSHA1CALCINT (RW)
 *
 * Masks the interruption related to KSV list update in memory that needs to be SHA1 verified.
 */

#define BP_HDMI_A_APIINTMSK_KSVSHA1CALCINT      1
#define BM_HDMI_A_APIINTMSK_KSVSHA1CALCINT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTMSK_KSVSHA1CALCINT(v)   ((((reg32_t) v) << 1) & BM_HDMI_A_APIINTMSK_KSVSHA1CALCINT)
#else
#define BF_HDMI_A_APIINTMSK_KSVSHA1CALCINT(v)   (((v) << 1) & BM_HDMI_A_APIINTMSK_KSVSHA1CALCINT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KSVSHA1CALCINT field to a new value.
#define BW_HDMI_A_APIINTMSK_KSVSHA1CALCINT(v)   BF_CS1(HDMI_A_APIINTMSK, KSVSHA1CALCINT, v)
#endif

/* --- Register HW_HDMI_A_APIINTMSK, field KEEPOUTERRORINT (RW)
 *
 * Masks the interruption related to keep out window error.
 */

#define BP_HDMI_A_APIINTMSK_KEEPOUTERRORINT      2
#define BM_HDMI_A_APIINTMSK_KEEPOUTERRORINT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTMSK_KEEPOUTERRORINT(v)   ((((reg32_t) v) << 2) & BM_HDMI_A_APIINTMSK_KEEPOUTERRORINT)
#else
#define BF_HDMI_A_APIINTMSK_KEEPOUTERRORINT(v)   (((v) << 2) & BM_HDMI_A_APIINTMSK_KEEPOUTERRORINT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KEEPOUTERRORINT field to a new value.
#define BW_HDMI_A_APIINTMSK_KEEPOUTERRORINT(v)   BF_CS1(HDMI_A_APIINTMSK, KEEPOUTERRORINT, v)
#endif

/* --- Register HW_HDMI_A_APIINTMSK, field LOSTARBITRATION (RW)
 *
 * Masks the interruption related to I2C arbitration lost.
 */

#define BP_HDMI_A_APIINTMSK_LOSTARBITRATION      3
#define BM_HDMI_A_APIINTMSK_LOSTARBITRATION      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTMSK_LOSTARBITRATION(v)   ((((reg32_t) v) << 3) & BM_HDMI_A_APIINTMSK_LOSTARBITRATION)
#else
#define BF_HDMI_A_APIINTMSK_LOSTARBITRATION(v)   (((v) << 3) & BM_HDMI_A_APIINTMSK_LOSTARBITRATION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOSTARBITRATION field to a new value.
#define BW_HDMI_A_APIINTMSK_LOSTARBITRATION(v)   BF_CS1(HDMI_A_APIINTMSK, LOSTARBITRATION, v)
#endif

/* --- Register HW_HDMI_A_APIINTMSK, field I2CNACK (RW)
 *
 * Masks the interruption related to I2C NACK reception.
 */

#define BP_HDMI_A_APIINTMSK_I2CNACK      4
#define BM_HDMI_A_APIINTMSK_I2CNACK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTMSK_I2CNACK(v)   ((((reg32_t) v) << 4) & BM_HDMI_A_APIINTMSK_I2CNACK)
#else
#define BF_HDMI_A_APIINTMSK_I2CNACK(v)   (((v) << 4) & BM_HDMI_A_APIINTMSK_I2CNACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CNACK field to a new value.
#define BW_HDMI_A_APIINTMSK_I2CNACK(v)   BF_CS1(HDMI_A_APIINTMSK, I2CNACK, v)
#endif

/* --- Register HW_HDMI_A_APIINTMSK, field HDCP_FAILED (RW)
 *
 * Masks the interruption related to HDCP authentication process failed.
 */

#define BP_HDMI_A_APIINTMSK_HDCP_FAILED      6
#define BM_HDMI_A_APIINTMSK_HDCP_FAILED      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTMSK_HDCP_FAILED(v)   ((((reg32_t) v) << 6) & BM_HDMI_A_APIINTMSK_HDCP_FAILED)
#else
#define BF_HDMI_A_APIINTMSK_HDCP_FAILED(v)   (((v) << 6) & BM_HDMI_A_APIINTMSK_HDCP_FAILED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCP_FAILED field to a new value.
#define BW_HDMI_A_APIINTMSK_HDCP_FAILED(v)   BF_CS1(HDMI_A_APIINTMSK, HDCP_FAILED, v)
#endif

/* --- Register HW_HDMI_A_APIINTMSK, field HCDP_ENGAGED (RW)
 *
 * Masks the interruption related to HDCP authentication process successful.
 */

#define BP_HDMI_A_APIINTMSK_HCDP_ENGAGED      7
#define BM_HDMI_A_APIINTMSK_HCDP_ENGAGED      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_APIINTMSK_HCDP_ENGAGED(v)   ((((reg32_t) v) << 7) & BM_HDMI_A_APIINTMSK_HCDP_ENGAGED)
#else
#define BF_HDMI_A_APIINTMSK_HCDP_ENGAGED(v)   (((v) << 7) & BM_HDMI_A_APIINTMSK_HCDP_ENGAGED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HCDP_ENGAGED field to a new value.
#define BW_HDMI_A_APIINTMSK_HCDP_ENGAGED(v)   BF_CS1(HDMI_A_APIINTMSK, HCDP_ENGAGED, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_VIDPOLCFG - A_VIDPOLCFG (RW)
 *
 * Address Offset: 0x5009  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED : 1; //!< Corps future use.
        unsigned char HSYNCPOL : 1; //!< Configuration of the video Horizontal synchronism polarity.
        unsigned char RESERVED0 : 1; //!< Reserved
        unsigned char VSYNCPOL : 1; //!< Configuration of the video Vertical synchronism polarity.
        unsigned char DATAENPOL : 1; //!< Configuration of the video data enable polarity.
        unsigned char UNENCRYPTCONF : 2; //!< Configuration of the color sent when sending unencrypted video data
        unsigned char RESERVED1 : 1; //!< Reserved
    } B;
} hw_hdmi_a_vidpolcfg_t;
#endif

/*
 * constants & macros for entire HDMI_A_VIDPOLCFG register
 */
#define HW_HDMI_A_VIDPOLCFG_ADDR      (REGS_HDMI_BASE + 0x5009)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_VIDPOLCFG           (*(volatile hw_hdmi_a_vidpolcfg_t *) HW_HDMI_A_VIDPOLCFG_ADDR)
#define HW_HDMI_A_VIDPOLCFG_RD()      (HW_HDMI_A_VIDPOLCFG.U)
#define HW_HDMI_A_VIDPOLCFG_WR(v)     (HW_HDMI_A_VIDPOLCFG.U = (v))
#define HW_HDMI_A_VIDPOLCFG_SET(v)    (HW_HDMI_A_VIDPOLCFG_WR(HW_HDMI_A_VIDPOLCFG_RD() |  (v)))
#define HW_HDMI_A_VIDPOLCFG_CLR(v)    (HW_HDMI_A_VIDPOLCFG_WR(HW_HDMI_A_VIDPOLCFG_RD() & ~(v)))
#define HW_HDMI_A_VIDPOLCFG_TOG(v)    (HW_HDMI_A_VIDPOLCFG_WR(HW_HDMI_A_VIDPOLCFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_A_VIDPOLCFG bitfields
 */

/* --- Register HW_HDMI_A_VIDPOLCFG, field RESERVED (RW)
 *
 * Corps future use.
 */

#define BP_HDMI_A_VIDPOLCFG_RESERVED      0
#define BM_HDMI_A_VIDPOLCFG_RESERVED      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_VIDPOLCFG_RESERVED(v)   ((((reg32_t) v) << 0) & BM_HDMI_A_VIDPOLCFG_RESERVED)
#else
#define BF_HDMI_A_VIDPOLCFG_RESERVED(v)   (((v) << 0) & BM_HDMI_A_VIDPOLCFG_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESERVED field to a new value.
#define BW_HDMI_A_VIDPOLCFG_RESERVED(v)   BF_CS1(HDMI_A_VIDPOLCFG, RESERVED, v)
#endif

/* --- Register HW_HDMI_A_VIDPOLCFG, field HSYNCPOL (RW)
 *
 * Configuration of the video Horizontal synchronism polarity.
 */

#define BP_HDMI_A_VIDPOLCFG_HSYNCPOL      1
#define BM_HDMI_A_VIDPOLCFG_HSYNCPOL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_VIDPOLCFG_HSYNCPOL(v)   ((((reg32_t) v) << 1) & BM_HDMI_A_VIDPOLCFG_HSYNCPOL)
#else
#define BF_HDMI_A_VIDPOLCFG_HSYNCPOL(v)   (((v) << 1) & BM_HDMI_A_VIDPOLCFG_HSYNCPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNCPOL field to a new value.
#define BW_HDMI_A_VIDPOLCFG_HSYNCPOL(v)   BF_CS1(HDMI_A_VIDPOLCFG, HSYNCPOL, v)
#endif

/* --- Register HW_HDMI_A_VIDPOLCFG, field VSYNCPOL (RW)
 *
 * Configuration of the video Vertical synchronism polarity.
 */

#define BP_HDMI_A_VIDPOLCFG_VSYNCPOL      3
#define BM_HDMI_A_VIDPOLCFG_VSYNCPOL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_VIDPOLCFG_VSYNCPOL(v)   ((((reg32_t) v) << 3) & BM_HDMI_A_VIDPOLCFG_VSYNCPOL)
#else
#define BF_HDMI_A_VIDPOLCFG_VSYNCPOL(v)   (((v) << 3) & BM_HDMI_A_VIDPOLCFG_VSYNCPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNCPOL field to a new value.
#define BW_HDMI_A_VIDPOLCFG_VSYNCPOL(v)   BF_CS1(HDMI_A_VIDPOLCFG, VSYNCPOL, v)
#endif

/* --- Register HW_HDMI_A_VIDPOLCFG, field DATAENPOL (RW)
 *
 * Configuration of the video data enable polarity.
 */

#define BP_HDMI_A_VIDPOLCFG_DATAENPOL      4
#define BM_HDMI_A_VIDPOLCFG_DATAENPOL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_VIDPOLCFG_DATAENPOL(v)   ((((reg32_t) v) << 4) & BM_HDMI_A_VIDPOLCFG_DATAENPOL)
#else
#define BF_HDMI_A_VIDPOLCFG_DATAENPOL(v)   (((v) << 4) & BM_HDMI_A_VIDPOLCFG_DATAENPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAENPOL field to a new value.
#define BW_HDMI_A_VIDPOLCFG_DATAENPOL(v)   BF_CS1(HDMI_A_VIDPOLCFG, DATAENPOL, v)
#endif

/* --- Register HW_HDMI_A_VIDPOLCFG, field UNENCRYPTCONF (RW)
 *
 * Configuration of the color sent when sending unencrypted video data
 *
 * Values:
 * 00 - tmdsch0out=0x00, tmdsch1out=0x00, tmdsch2out=0xFF
 * 01 - tmdsch0out=0x00, tmdsch1out=0xFF, tmdsch2out=0x00
 * 10 - tmdsch0out=0xFF, tmdsch1out=0x00, tmdsch2out=0x00
 * 11 - tmdsch0out=0xFF, tmdsch1out=0xFF, tmdsch2out=0xFF
 */

#define BP_HDMI_A_VIDPOLCFG_UNENCRYPTCONF      5
#define BM_HDMI_A_VIDPOLCFG_UNENCRYPTCONF      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_VIDPOLCFG_UNENCRYPTCONF(v)   ((((reg32_t) v) << 5) & BM_HDMI_A_VIDPOLCFG_UNENCRYPTCONF)
#else
#define BF_HDMI_A_VIDPOLCFG_UNENCRYPTCONF(v)   (((v) << 5) & BM_HDMI_A_VIDPOLCFG_UNENCRYPTCONF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UNENCRYPTCONF field to a new value.
#define BW_HDMI_A_VIDPOLCFG_UNENCRYPTCONF(v)   BF_CS1(HDMI_A_VIDPOLCFG, UNENCRYPTCONF, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_OESSWCFG - A_OESSWCFG (RW)
 *
 * Size of the window of opportunity for the OESS mode. The window of opportunity for the Original
 * Encryption Status Signaling will start at the active edge of the Vertical synchronism and will
 * stop after oesswindowoffset[7:0]*4 clock cycles of pixel clock (tmds).   Address Offset: 0x500A
 * Size: 8 bits  Value after Reset: 0x08  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char A_OESSWCFG : 8; //!< Size of the window of opportunity for the OESS mode. The window of opportunity for the Original Encryption Status Signaling will start at the active edge of the Vertical synchronism and will stop after oesswindowoffset[7:0]*4 clock cycles of pixel clock (tmds). OESS utilizes only CTL3, and is only used during DVI protocol. This signaling is accomplished with a single high-going pulse, during the vertical blanking interval, of sufficient width that it may be distinguished from bit errors on the channel or any effects due to resynchronization events in the receiver. The transmitter must assert CTL3 for at least 8 pixel clocks (the transmitter is encouraged to utilize a wider pulse to enhance reliability, but no more than the entire Vsync timeframe), starting no closer than 128 pixel clocks from the end of the vertical blank interval.
    } B;
} hw_hdmi_a_oesswcfg_t;
#endif

/*
 * constants & macros for entire HDMI_A_OESSWCFG register
 */
#define HW_HDMI_A_OESSWCFG_ADDR      (REGS_HDMI_BASE + 0x500a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_OESSWCFG           (*(volatile hw_hdmi_a_oesswcfg_t *) HW_HDMI_A_OESSWCFG_ADDR)
#define HW_HDMI_A_OESSWCFG_RD()      (HW_HDMI_A_OESSWCFG.U)
#define HW_HDMI_A_OESSWCFG_WR(v)     (HW_HDMI_A_OESSWCFG.U = (v))
#define HW_HDMI_A_OESSWCFG_SET(v)    (HW_HDMI_A_OESSWCFG_WR(HW_HDMI_A_OESSWCFG_RD() |  (v)))
#define HW_HDMI_A_OESSWCFG_CLR(v)    (HW_HDMI_A_OESSWCFG_WR(HW_HDMI_A_OESSWCFG_RD() & ~(v)))
#define HW_HDMI_A_OESSWCFG_TOG(v)    (HW_HDMI_A_OESSWCFG_WR(HW_HDMI_A_OESSWCFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_A_OESSWCFG bitfields
 */

/* --- Register HW_HDMI_A_OESSWCFG, field A_OESSWCFG (RW)
 *
 * Size of the window of opportunity for the OESS mode. The window of opportunity for the Original
 * Encryption Status Signaling will start at the active edge of the Vertical synchronism and will
 * stop after oesswindowoffset[7:0]*4 clock cycles of pixel clock (tmds). OESS utilizes only CTL3,
 * and is only used during DVI protocol. This signaling is accomplished with a single high-going
 * pulse, during the vertical blanking interval, of sufficient width that it may be distinguished
 * from bit errors on the channel or any effects due to resynchronization events in the receiver.
 * The transmitter must assert CTL3 for at least 8 pixel clocks (the transmitter is encouraged to
 * utilize a wider pulse to enhance reliability, but no more than the entire Vsync timeframe),
 * starting no closer than 128 pixel clocks from the end of the vertical blank interval.
 */

#define BP_HDMI_A_OESSWCFG_A_OESSWCFG      0
#define BM_HDMI_A_OESSWCFG_A_OESSWCFG      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_OESSWCFG_A_OESSWCFG(v)   ((((reg32_t) v) << 0) & BM_HDMI_A_OESSWCFG_A_OESSWCFG)
#else
#define BF_HDMI_A_OESSWCFG_A_OESSWCFG(v)   (((v) << 0) & BM_HDMI_A_OESSWCFG_A_OESSWCFG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the A_OESSWCFG field to a new value.
#define BW_HDMI_A_OESSWCFG_A_OESSWCFG(v)   BF_CS1(HDMI_A_OESSWCFG, A_OESSWCFG, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_COREVERLSB - A_COREVERLSB (RO)
 *
 * Design ID number.   Address Offset: 0x5014  Size: 8 bits  Value after Reset: N/A  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char A_COREVERLSB : 8; //!< Design ID number
    } B;
} hw_hdmi_a_coreverlsb_t;
#endif

/*
 * constants & macros for entire HDMI_A_COREVERLSB register
 */
#define HW_HDMI_A_COREVERLSB_ADDR      (REGS_HDMI_BASE + 0x5014)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_COREVERLSB           (*(volatile hw_hdmi_a_coreverlsb_t *) HW_HDMI_A_COREVERLSB_ADDR)
#define HW_HDMI_A_COREVERLSB_RD()      (HW_HDMI_A_COREVERLSB.U)
#endif

/*
 * constants & macros for individual HDMI_A_COREVERLSB bitfields
 */

/* --- Register HW_HDMI_A_COREVERLSB, field A_COREVERLSB (RO)
 *
 * Design ID number
 */

#define BP_HDMI_A_COREVERLSB_A_COREVERLSB      0
#define BM_HDMI_A_COREVERLSB_A_COREVERLSB      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_COREVERMSB - A_COREVERMSB (RO)
 *
 * Revision ID number.   Address Offset: 0x5015  Size: 8 bits  Value after Reset: N/A  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char A_COREVERMSB : 8; //!< Revision ID number
    } B;
} hw_hdmi_a_corevermsb_t;
#endif

/*
 * constants & macros for entire HDMI_A_COREVERMSB register
 */
#define HW_HDMI_A_COREVERMSB_ADDR      (REGS_HDMI_BASE + 0x5015)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_COREVERMSB           (*(volatile hw_hdmi_a_corevermsb_t *) HW_HDMI_A_COREVERMSB_ADDR)
#define HW_HDMI_A_COREVERMSB_RD()      (HW_HDMI_A_COREVERMSB.U)
#endif

/*
 * constants & macros for individual HDMI_A_COREVERMSB bitfields
 */

/* --- Register HW_HDMI_A_COREVERMSB, field A_COREVERMSB (RO)
 *
 * Revision ID number
 */

#define BP_HDMI_A_COREVERMSB_A_COREVERMSB      0
#define BM_HDMI_A_COREVERMSB_A_COREVERMSB      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_A_KSVMEMCTRL - A_KSVMEMCTRL (RW)
 *
 * The KSVCTRLupd bit is a notification flag. This flag will change polarity whenever the register
 * is written. This flag acts as a trigger to other blocks that will process this data. Upon reset
 * the flag returns to low default value.   Address Offset: 0x5016  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write    5K RAM memory for system renewability messages (SRM) and HDCP
 * encryption engine   These addresses map a 5K RAM memory used for System Renewability Messages
 * (SRM) or for the Revocation list exchange with the HDCP encryption engine (access must be granted
 * on KSVMEMaccess bit of A_KSVMEMCTRL).   Address Offset: 0x5020 to 0x6FFF    HDCP_SRM Address Map
 * 0x5020..0x5021Bstatus[15:0]    These registers hold the B status value. The value is stored in
 * two registers, organized as little endian.      0x5022..0x5029M0value[63:0]    These registers
 * hold the M0 value. The value is stored in eight registers, organized as little endian.
 * 0x502A..0x52A4KSV list    In this address space the KSV list is stored in 128 registers each with
 * 40 bits. The list is organized as little endian (LSB of register 0 is in address 0x502A).
 * 0x52A5..0x52B8VH list    In this address space the VH list is stored in five registers, each with
 * 32 bits. The list is organized as little endian (LSB of register 0 is in address 0x52A5).
 * 0x52B9..0x52BARevocation list size    These registers hold the size of revocation list. The value
 * is stored in two registers, organized as little endian.      0x52BB..0x66B5Revocation list values
 * In this address space the revocation list values are stored in 1024 registers each with 40 bits.
 * The list is organized as little endian (LSB of register 0 is in address 0x52BB).
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char KSVMEMREQUEST : 1; //!< Request access to the KSV memory, must be de-asserted after the access is completed by the system.
        unsigned char KSVMEMACCESS : 1; //!< Notification that the KSV memory access as been guaranteed.
        unsigned char KSVCTRLUPD : 1; //!< Set to inform that the KSV list in memory has been analyzed and the response to it's Message Digest as been updated.
        unsigned char SHA1FAIL : 1; //!< Notification that the KSV list's message digest is correct or not.
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_a_ksvmemctrl_t;
#endif

/*
 * constants & macros for entire HDMI_A_KSVMEMCTRL register
 */
#define HW_HDMI_A_KSVMEMCTRL_ADDR      (REGS_HDMI_BASE + 0x5016)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_A_KSVMEMCTRL           (*(volatile hw_hdmi_a_ksvmemctrl_t *) HW_HDMI_A_KSVMEMCTRL_ADDR)
#define HW_HDMI_A_KSVMEMCTRL_RD()      (HW_HDMI_A_KSVMEMCTRL.U)
#define HW_HDMI_A_KSVMEMCTRL_WR(v)     (HW_HDMI_A_KSVMEMCTRL.U = (v))
#define HW_HDMI_A_KSVMEMCTRL_SET(v)    (HW_HDMI_A_KSVMEMCTRL_WR(HW_HDMI_A_KSVMEMCTRL_RD() |  (v)))
#define HW_HDMI_A_KSVMEMCTRL_CLR(v)    (HW_HDMI_A_KSVMEMCTRL_WR(HW_HDMI_A_KSVMEMCTRL_RD() & ~(v)))
#define HW_HDMI_A_KSVMEMCTRL_TOG(v)    (HW_HDMI_A_KSVMEMCTRL_WR(HW_HDMI_A_KSVMEMCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_A_KSVMEMCTRL bitfields
 */

/* --- Register HW_HDMI_A_KSVMEMCTRL, field KSVMEMREQUEST (RW)
 *
 * Request access to the KSV memory, must be de-asserted after the access is completed by the
 * system.
 */

#define BP_HDMI_A_KSVMEMCTRL_KSVMEMREQUEST      0
#define BM_HDMI_A_KSVMEMCTRL_KSVMEMREQUEST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_KSVMEMCTRL_KSVMEMREQUEST(v)   ((((reg32_t) v) << 0) & BM_HDMI_A_KSVMEMCTRL_KSVMEMREQUEST)
#else
#define BF_HDMI_A_KSVMEMCTRL_KSVMEMREQUEST(v)   (((v) << 0) & BM_HDMI_A_KSVMEMCTRL_KSVMEMREQUEST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KSVMEMREQUEST field to a new value.
#define BW_HDMI_A_KSVMEMCTRL_KSVMEMREQUEST(v)   BF_CS1(HDMI_A_KSVMEMCTRL, KSVMEMREQUEST, v)
#endif

/* --- Register HW_HDMI_A_KSVMEMCTRL, field KSVMEMACCESS (RW)
 *
 * Notification that the KSV memory access as been guaranteed.
 */

#define BP_HDMI_A_KSVMEMCTRL_KSVMEMACCESS      1
#define BM_HDMI_A_KSVMEMCTRL_KSVMEMACCESS      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_KSVMEMCTRL_KSVMEMACCESS(v)   ((((reg32_t) v) << 1) & BM_HDMI_A_KSVMEMCTRL_KSVMEMACCESS)
#else
#define BF_HDMI_A_KSVMEMCTRL_KSVMEMACCESS(v)   (((v) << 1) & BM_HDMI_A_KSVMEMCTRL_KSVMEMACCESS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KSVMEMACCESS field to a new value.
#define BW_HDMI_A_KSVMEMCTRL_KSVMEMACCESS(v)   BF_CS1(HDMI_A_KSVMEMCTRL, KSVMEMACCESS, v)
#endif

/* --- Register HW_HDMI_A_KSVMEMCTRL, field KSVCTRLUPD (RW)
 *
 * Set to inform that the KSV list in memory has been analyzed and the response to it's Message
 * Digest as been updated.
 */

#define BP_HDMI_A_KSVMEMCTRL_KSVCTRLUPD      2
#define BM_HDMI_A_KSVMEMCTRL_KSVCTRLUPD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_KSVMEMCTRL_KSVCTRLUPD(v)   ((((reg32_t) v) << 2) & BM_HDMI_A_KSVMEMCTRL_KSVCTRLUPD)
#else
#define BF_HDMI_A_KSVMEMCTRL_KSVCTRLUPD(v)   (((v) << 2) & BM_HDMI_A_KSVMEMCTRL_KSVCTRLUPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the KSVCTRLUPD field to a new value.
#define BW_HDMI_A_KSVMEMCTRL_KSVCTRLUPD(v)   BF_CS1(HDMI_A_KSVMEMCTRL, KSVCTRLUPD, v)
#endif

/* --- Register HW_HDMI_A_KSVMEMCTRL, field SHA1FAIL (RW)
 *
 * Notification that the KSV list's message digest is correct or not.
 */

#define BP_HDMI_A_KSVMEMCTRL_SHA1FAIL      3
#define BM_HDMI_A_KSVMEMCTRL_SHA1FAIL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_A_KSVMEMCTRL_SHA1FAIL(v)   ((((reg32_t) v) << 3) & BM_HDMI_A_KSVMEMCTRL_SHA1FAIL)
#else
#define BF_HDMI_A_KSVMEMCTRL_SHA1FAIL(v)   (((v) << 3) & BM_HDMI_A_KSVMEMCTRL_SHA1FAIL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SHA1FAIL field to a new value.
#define BW_HDMI_A_KSVMEMCTRL_SHA1FAIL(v)   BF_CS1(HDMI_A_KSVMEMCTRL, SHA1FAIL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_BKSV0 - HDCPREG_BKSV0 (RO)
 *
 * During HDCP authentication, the HDCP Transmitter (Device A) sends an A Key Selection Vector
 * (AKSV) to the HDCP Receiver (Device B), which affirms its authorization to the HDCP Transmitter
 * by sending a B Key Selection Vector (BKSV). The BKSV registers contain the 40-bit BKSV value read
 * by the HDCP transmitter from the HDCP receiver.  The BKSV value that is received from the HDCP
 * receiver enables HDMI TX operation in repeater applications. The BKSV value is only valid once
 * the authentication is concluded (that is, HDCP is engaged). Bit 7 of the register A_APIINTSTAT
 * denotes that HDCP is engaged.  Contains the value of BKSV[7:0]   Address Offset: 0x7800  Size: 8
 * bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_BKSV0 : 8; //!< Contains the value of BKSV[7:0] During HDCP authentication, the HDCP Transmitter (Device A) sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
    } B;
} hw_hdmi_hdcpreg_bksv0_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_BKSV0 register
 */
#define HW_HDMI_HDCPREG_BKSV0_ADDR      (REGS_HDMI_BASE + 0x7800)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_BKSV0           (*(volatile hw_hdmi_hdcpreg_bksv0_t *) HW_HDMI_HDCPREG_BKSV0_ADDR)
#define HW_HDMI_HDCPREG_BKSV0_RD()      (HW_HDMI_HDCPREG_BKSV0.U)
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_BKSV0 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_BKSV0, field HDCPREG_BKSV0 (RO)
 *
 * Contains the value of BKSV[7:0] During HDCP authentication, the HDCP Transmitter (Device A) sends
 * an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its authorization
 * to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV registers contain
 * the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
 */

#define BP_HDMI_HDCPREG_BKSV0_HDCPREG_BKSV0      0
#define BM_HDMI_HDCPREG_BKSV0_HDCPREG_BKSV0      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_BKSV1 - HDCPREG_BKSV1 (RO)
 *
 * Contains the value of BKSV[15:8]   Address Offset: 0x7801  Size: 8 bits  Value after Reset: 0x00
 * Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_BKSV1 : 8; //!< Contains the value of BKSV[15:8] During HDCP authentication, the HDCP Transmitter (Device A) sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
    } B;
} hw_hdmi_hdcpreg_bksv1_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_BKSV1 register
 */
#define HW_HDMI_HDCPREG_BKSV1_ADDR      (REGS_HDMI_BASE + 0x7801)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_BKSV1           (*(volatile hw_hdmi_hdcpreg_bksv1_t *) HW_HDMI_HDCPREG_BKSV1_ADDR)
#define HW_HDMI_HDCPREG_BKSV1_RD()      (HW_HDMI_HDCPREG_BKSV1.U)
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_BKSV1 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_BKSV1, field HDCPREG_BKSV1 (RO)
 *
 * Contains the value of BKSV[15:8] During HDCP authentication, the HDCP Transmitter (Device A)
 * sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its
 * authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV
 * registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
 */

#define BP_HDMI_HDCPREG_BKSV1_HDCPREG_BKSV1      0
#define BM_HDMI_HDCPREG_BKSV1_HDCPREG_BKSV1      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_BKSV2 - HDCPREG_BKSV2 (RO)
 *
 * Contains the value of BKSV[23:16]   Address Offset: 0x7802  Size: 8 bits  Value after Reset: 0x00
 * Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_BKSV2 : 8; //!< Contains the value of BKSV[23:16] During HDCP authentication, the HDCP Transmitter (Device A) sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
    } B;
} hw_hdmi_hdcpreg_bksv2_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_BKSV2 register
 */
#define HW_HDMI_HDCPREG_BKSV2_ADDR      (REGS_HDMI_BASE + 0x7802)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_BKSV2           (*(volatile hw_hdmi_hdcpreg_bksv2_t *) HW_HDMI_HDCPREG_BKSV2_ADDR)
#define HW_HDMI_HDCPREG_BKSV2_RD()      (HW_HDMI_HDCPREG_BKSV2.U)
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_BKSV2 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_BKSV2, field HDCPREG_BKSV2 (RO)
 *
 * Contains the value of BKSV[23:16] During HDCP authentication, the HDCP Transmitter (Device A)
 * sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its
 * authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV
 * registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
 */

#define BP_HDMI_HDCPREG_BKSV2_HDCPREG_BKSV2      0
#define BM_HDMI_HDCPREG_BKSV2_HDCPREG_BKSV2      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_BKSV3 - HDCPREG_BKSV3 (RO)
 *
 * Contains the value of BKSV[31:24]   Address Offset: 0x7803  Size: 8 bits  Value after Reset: 0x00
 * Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_BKSV3 : 8; //!< Contains the value of BKSV[31:24] During HDCP authentication, the HDCP Transmitter (Device A) sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
    } B;
} hw_hdmi_hdcpreg_bksv3_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_BKSV3 register
 */
#define HW_HDMI_HDCPREG_BKSV3_ADDR      (REGS_HDMI_BASE + 0x7803)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_BKSV3           (*(volatile hw_hdmi_hdcpreg_bksv3_t *) HW_HDMI_HDCPREG_BKSV3_ADDR)
#define HW_HDMI_HDCPREG_BKSV3_RD()      (HW_HDMI_HDCPREG_BKSV3.U)
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_BKSV3 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_BKSV3, field HDCPREG_BKSV3 (RO)
 *
 * Contains the value of BKSV[31:24] During HDCP authentication, the HDCP Transmitter (Device A)
 * sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its
 * authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV
 * registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
 */

#define BP_HDMI_HDCPREG_BKSV3_HDCPREG_BKSV3      0
#define BM_HDMI_HDCPREG_BKSV3_HDCPREG_BKSV3      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_BKSV4 - HDCPREG_BKSV4 (RO)
 *
 * Contains the value of BKSV[39:32]   Address Offset: 0x7804  Size: 8 bits  Value after Reset: 0x00
 * Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_BKSV4 : 8; //!< Contains the value of BKSV[39:32] During HDCP authentication, the HDCP Transmitter (Device A) sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
    } B;
} hw_hdmi_hdcpreg_bksv4_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_BKSV4 register
 */
#define HW_HDMI_HDCPREG_BKSV4_ADDR      (REGS_HDMI_BASE + 0x7804)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_BKSV4           (*(volatile hw_hdmi_hdcpreg_bksv4_t *) HW_HDMI_HDCPREG_BKSV4_ADDR)
#define HW_HDMI_HDCPREG_BKSV4_RD()      (HW_HDMI_HDCPREG_BKSV4.U)
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_BKSV4 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_BKSV4, field HDCPREG_BKSV4 (RO)
 *
 * Contains the value of BKSV[39:32] During HDCP authentication, the HDCP Transmitter (Device A)
 * sends an A Key Selection Vector (AKSV) to the HDCP Receiver (Device B), which affirms its
 * authorization to the HDCP Transmitter by sending a B Key Selection Vector (BKSV). The BKSV
 * registers contain the 40-bit BKSV value read by the HDCP transmitter from the HDCP receiver.
 */

#define BP_HDMI_HDCPREG_BKSV4_HDCPREG_BKSV4      0
#define BM_HDMI_HDCPREG_BKSV4_HDCPREG_BKSV4      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_ANCONF - HDCPREG_ANCONF (RW)
 *
 * During HDCP authentication, the HDCP Transmitter (Device A) sends an A Key Selection Vector
 * (AKSV) and a 64-bit pseudo-random value (AN) to the HDCP Receiver (Device B).  HDCP AN registers
 * contain the 64-bit pseudo-random value (AN).  When you do not want to use the Random Number
 * Generator Interface (irndnum, orndnumgenena) of the HDMI TX core, the registers force the test AN
 * value to be used instead of the Random Number Generator Interface value.  This register is a
 * single-bit register and enforces the value of AN from the registers HDCPREG_AN0 to HDCPREG_AN7.
 * Address Offset: 0x7805  Size: 1 bit  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char OANBYPASS : 1; //!< When oanbypass=1, the value of AN used in the HDCP engine comes from the registers HDCPREG_AN0 to HDCPREG_AN7. When oanbypass=0, the value of AN used in the HDCP engine comes from the random number input.
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_hdcpreg_anconf_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_ANCONF register
 */
#define HW_HDMI_HDCPREG_ANCONF_ADDR      (REGS_HDMI_BASE + 0x7805)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_ANCONF           (*(volatile hw_hdmi_hdcpreg_anconf_t *) HW_HDMI_HDCPREG_ANCONF_ADDR)
#define HW_HDMI_HDCPREG_ANCONF_RD()      (HW_HDMI_HDCPREG_ANCONF.U)
#define HW_HDMI_HDCPREG_ANCONF_WR(v)     (HW_HDMI_HDCPREG_ANCONF.U = (v))
#define HW_HDMI_HDCPREG_ANCONF_SET(v)    (HW_HDMI_HDCPREG_ANCONF_WR(HW_HDMI_HDCPREG_ANCONF_RD() |  (v)))
#define HW_HDMI_HDCPREG_ANCONF_CLR(v)    (HW_HDMI_HDCPREG_ANCONF_WR(HW_HDMI_HDCPREG_ANCONF_RD() & ~(v)))
#define HW_HDMI_HDCPREG_ANCONF_TOG(v)    (HW_HDMI_HDCPREG_ANCONF_WR(HW_HDMI_HDCPREG_ANCONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_ANCONF bitfields
 */

/* --- Register HW_HDMI_HDCPREG_ANCONF, field OANBYPASS (RW)
 *
 * When oanbypass=1, the value of AN used in the HDCP engine comes from the registers HDCPREG_AN0 to
 * HDCPREG_AN7. When oanbypass=0, the value of AN used in the HDCP engine comes from the random
 * number input.
 */

#define BP_HDMI_HDCPREG_ANCONF_OANBYPASS      0
#define BM_HDMI_HDCPREG_ANCONF_OANBYPASS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_ANCONF_OANBYPASS(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_ANCONF_OANBYPASS)
#else
#define BF_HDMI_HDCPREG_ANCONF_OANBYPASS(v)   (((v) << 0) & BM_HDMI_HDCPREG_ANCONF_OANBYPASS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OANBYPASS field to a new value.
#define BW_HDMI_HDCPREG_ANCONF_OANBYPASS(v)   BF_CS1(HDMI_HDCPREG_ANCONF, OANBYPASS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_AN0 - HDCPREG_AN0 (RW)
 *
 * Contains the value of AN[7:0]   Address Offset: 0x7806  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_AN0 : 8; //!< Contains the value of AN[7:0]
    } B;
} hw_hdmi_hdcpreg_an0_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_AN0 register
 */
#define HW_HDMI_HDCPREG_AN0_ADDR      (REGS_HDMI_BASE + 0x7806)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_AN0           (*(volatile hw_hdmi_hdcpreg_an0_t *) HW_HDMI_HDCPREG_AN0_ADDR)
#define HW_HDMI_HDCPREG_AN0_RD()      (HW_HDMI_HDCPREG_AN0.U)
#define HW_HDMI_HDCPREG_AN0_WR(v)     (HW_HDMI_HDCPREG_AN0.U = (v))
#define HW_HDMI_HDCPREG_AN0_SET(v)    (HW_HDMI_HDCPREG_AN0_WR(HW_HDMI_HDCPREG_AN0_RD() |  (v)))
#define HW_HDMI_HDCPREG_AN0_CLR(v)    (HW_HDMI_HDCPREG_AN0_WR(HW_HDMI_HDCPREG_AN0_RD() & ~(v)))
#define HW_HDMI_HDCPREG_AN0_TOG(v)    (HW_HDMI_HDCPREG_AN0_WR(HW_HDMI_HDCPREG_AN0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_AN0 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_AN0, field HDCPREG_AN0 (RW)
 *
 * Contains the value of AN[7:0]
 */

#define BP_HDMI_HDCPREG_AN0_HDCPREG_AN0      0
#define BM_HDMI_HDCPREG_AN0_HDCPREG_AN0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_AN0_HDCPREG_AN0(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_AN0_HDCPREG_AN0)
#else
#define BF_HDMI_HDCPREG_AN0_HDCPREG_AN0(v)   (((v) << 0) & BM_HDMI_HDCPREG_AN0_HDCPREG_AN0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPREG_AN0 field to a new value.
#define BW_HDMI_HDCPREG_AN0_HDCPREG_AN0(v)   BF_CS1(HDMI_HDCPREG_AN0, HDCPREG_AN0, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_AN1 - HDCPREG_AN1 (RW)
 *
 * Contains the value of AN[15:8]   Address Offset: 0x7807  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_AN1 : 8; //!< Contains the value of AN[15:8]
    } B;
} hw_hdmi_hdcpreg_an1_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_AN1 register
 */
#define HW_HDMI_HDCPREG_AN1_ADDR      (REGS_HDMI_BASE + 0x7807)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_AN1           (*(volatile hw_hdmi_hdcpreg_an1_t *) HW_HDMI_HDCPREG_AN1_ADDR)
#define HW_HDMI_HDCPREG_AN1_RD()      (HW_HDMI_HDCPREG_AN1.U)
#define HW_HDMI_HDCPREG_AN1_WR(v)     (HW_HDMI_HDCPREG_AN1.U = (v))
#define HW_HDMI_HDCPREG_AN1_SET(v)    (HW_HDMI_HDCPREG_AN1_WR(HW_HDMI_HDCPREG_AN1_RD() |  (v)))
#define HW_HDMI_HDCPREG_AN1_CLR(v)    (HW_HDMI_HDCPREG_AN1_WR(HW_HDMI_HDCPREG_AN1_RD() & ~(v)))
#define HW_HDMI_HDCPREG_AN1_TOG(v)    (HW_HDMI_HDCPREG_AN1_WR(HW_HDMI_HDCPREG_AN1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_AN1 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_AN1, field HDCPREG_AN1 (RW)
 *
 * Contains the value of AN[15:8]
 */

#define BP_HDMI_HDCPREG_AN1_HDCPREG_AN1      0
#define BM_HDMI_HDCPREG_AN1_HDCPREG_AN1      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_AN1_HDCPREG_AN1(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_AN1_HDCPREG_AN1)
#else
#define BF_HDMI_HDCPREG_AN1_HDCPREG_AN1(v)   (((v) << 0) & BM_HDMI_HDCPREG_AN1_HDCPREG_AN1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPREG_AN1 field to a new value.
#define BW_HDMI_HDCPREG_AN1_HDCPREG_AN1(v)   BF_CS1(HDMI_HDCPREG_AN1, HDCPREG_AN1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_AN2 - HDCPREG_AN2 (RW)
 *
 * Contains the value of AN[23:16]   Address Offset: 0x7808  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_AN2 : 8; //!< Contains the value of AN[23:16]
    } B;
} hw_hdmi_hdcpreg_an2_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_AN2 register
 */
#define HW_HDMI_HDCPREG_AN2_ADDR      (REGS_HDMI_BASE + 0x7808)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_AN2           (*(volatile hw_hdmi_hdcpreg_an2_t *) HW_HDMI_HDCPREG_AN2_ADDR)
#define HW_HDMI_HDCPREG_AN2_RD()      (HW_HDMI_HDCPREG_AN2.U)
#define HW_HDMI_HDCPREG_AN2_WR(v)     (HW_HDMI_HDCPREG_AN2.U = (v))
#define HW_HDMI_HDCPREG_AN2_SET(v)    (HW_HDMI_HDCPREG_AN2_WR(HW_HDMI_HDCPREG_AN2_RD() |  (v)))
#define HW_HDMI_HDCPREG_AN2_CLR(v)    (HW_HDMI_HDCPREG_AN2_WR(HW_HDMI_HDCPREG_AN2_RD() & ~(v)))
#define HW_HDMI_HDCPREG_AN2_TOG(v)    (HW_HDMI_HDCPREG_AN2_WR(HW_HDMI_HDCPREG_AN2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_AN2 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_AN2, field HDCPREG_AN2 (RW)
 *
 * Contains the value of AN[23:16]
 */

#define BP_HDMI_HDCPREG_AN2_HDCPREG_AN2      0
#define BM_HDMI_HDCPREG_AN2_HDCPREG_AN2      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_AN2_HDCPREG_AN2(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_AN2_HDCPREG_AN2)
#else
#define BF_HDMI_HDCPREG_AN2_HDCPREG_AN2(v)   (((v) << 0) & BM_HDMI_HDCPREG_AN2_HDCPREG_AN2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPREG_AN2 field to a new value.
#define BW_HDMI_HDCPREG_AN2_HDCPREG_AN2(v)   BF_CS1(HDMI_HDCPREG_AN2, HDCPREG_AN2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_AN3 - HDCPREG_AN3 (RW)
 *
 * Contains the value of AN[31:24]   Address Offset: 0x7809  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_AN3 : 8; //!< Contains the value of AN[31:24]
    } B;
} hw_hdmi_hdcpreg_an3_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_AN3 register
 */
#define HW_HDMI_HDCPREG_AN3_ADDR      (REGS_HDMI_BASE + 0x7809)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_AN3           (*(volatile hw_hdmi_hdcpreg_an3_t *) HW_HDMI_HDCPREG_AN3_ADDR)
#define HW_HDMI_HDCPREG_AN3_RD()      (HW_HDMI_HDCPREG_AN3.U)
#define HW_HDMI_HDCPREG_AN3_WR(v)     (HW_HDMI_HDCPREG_AN3.U = (v))
#define HW_HDMI_HDCPREG_AN3_SET(v)    (HW_HDMI_HDCPREG_AN3_WR(HW_HDMI_HDCPREG_AN3_RD() |  (v)))
#define HW_HDMI_HDCPREG_AN3_CLR(v)    (HW_HDMI_HDCPREG_AN3_WR(HW_HDMI_HDCPREG_AN3_RD() & ~(v)))
#define HW_HDMI_HDCPREG_AN3_TOG(v)    (HW_HDMI_HDCPREG_AN3_WR(HW_HDMI_HDCPREG_AN3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_AN3 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_AN3, field HDCPREG_AN3 (RW)
 *
 * Contains the value of AN[31:24]
 */

#define BP_HDMI_HDCPREG_AN3_HDCPREG_AN3      0
#define BM_HDMI_HDCPREG_AN3_HDCPREG_AN3      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_AN3_HDCPREG_AN3(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_AN3_HDCPREG_AN3)
#else
#define BF_HDMI_HDCPREG_AN3_HDCPREG_AN3(v)   (((v) << 0) & BM_HDMI_HDCPREG_AN3_HDCPREG_AN3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPREG_AN3 field to a new value.
#define BW_HDMI_HDCPREG_AN3_HDCPREG_AN3(v)   BF_CS1(HDMI_HDCPREG_AN3, HDCPREG_AN3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_AN4 - HDCPREG_AN4 (RW)
 *
 * Contains the value of AN[39:32]   Address Offset: 0x780A  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_AN4 : 8; //!< Contains the value of AN[39:32]
    } B;
} hw_hdmi_hdcpreg_an4_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_AN4 register
 */
#define HW_HDMI_HDCPREG_AN4_ADDR      (REGS_HDMI_BASE + 0x780a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_AN4           (*(volatile hw_hdmi_hdcpreg_an4_t *) HW_HDMI_HDCPREG_AN4_ADDR)
#define HW_HDMI_HDCPREG_AN4_RD()      (HW_HDMI_HDCPREG_AN4.U)
#define HW_HDMI_HDCPREG_AN4_WR(v)     (HW_HDMI_HDCPREG_AN4.U = (v))
#define HW_HDMI_HDCPREG_AN4_SET(v)    (HW_HDMI_HDCPREG_AN4_WR(HW_HDMI_HDCPREG_AN4_RD() |  (v)))
#define HW_HDMI_HDCPREG_AN4_CLR(v)    (HW_HDMI_HDCPREG_AN4_WR(HW_HDMI_HDCPREG_AN4_RD() & ~(v)))
#define HW_HDMI_HDCPREG_AN4_TOG(v)    (HW_HDMI_HDCPREG_AN4_WR(HW_HDMI_HDCPREG_AN4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_AN4 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_AN4, field HDCPREG_AN4 (RW)
 *
 * Contains the value of AN[39:32]
 */

#define BP_HDMI_HDCPREG_AN4_HDCPREG_AN4      0
#define BM_HDMI_HDCPREG_AN4_HDCPREG_AN4      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_AN4_HDCPREG_AN4(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_AN4_HDCPREG_AN4)
#else
#define BF_HDMI_HDCPREG_AN4_HDCPREG_AN4(v)   (((v) << 0) & BM_HDMI_HDCPREG_AN4_HDCPREG_AN4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPREG_AN4 field to a new value.
#define BW_HDMI_HDCPREG_AN4_HDCPREG_AN4(v)   BF_CS1(HDMI_HDCPREG_AN4, HDCPREG_AN4, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_AN5 - HDCPREG_AN5 (RW)
 *
 * Contains the value of AN[47:40]   Address Offset: 0x780B  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_AN5 : 8; //!< Contains the value of AN[47:40]
    } B;
} hw_hdmi_hdcpreg_an5_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_AN5 register
 */
#define HW_HDMI_HDCPREG_AN5_ADDR      (REGS_HDMI_BASE + 0x780b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_AN5           (*(volatile hw_hdmi_hdcpreg_an5_t *) HW_HDMI_HDCPREG_AN5_ADDR)
#define HW_HDMI_HDCPREG_AN5_RD()      (HW_HDMI_HDCPREG_AN5.U)
#define HW_HDMI_HDCPREG_AN5_WR(v)     (HW_HDMI_HDCPREG_AN5.U = (v))
#define HW_HDMI_HDCPREG_AN5_SET(v)    (HW_HDMI_HDCPREG_AN5_WR(HW_HDMI_HDCPREG_AN5_RD() |  (v)))
#define HW_HDMI_HDCPREG_AN5_CLR(v)    (HW_HDMI_HDCPREG_AN5_WR(HW_HDMI_HDCPREG_AN5_RD() & ~(v)))
#define HW_HDMI_HDCPREG_AN5_TOG(v)    (HW_HDMI_HDCPREG_AN5_WR(HW_HDMI_HDCPREG_AN5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_AN5 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_AN5, field HDCPREG_AN5 (RW)
 *
 * Contains the value of AN[47:40]
 */

#define BP_HDMI_HDCPREG_AN5_HDCPREG_AN5      0
#define BM_HDMI_HDCPREG_AN5_HDCPREG_AN5      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_AN5_HDCPREG_AN5(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_AN5_HDCPREG_AN5)
#else
#define BF_HDMI_HDCPREG_AN5_HDCPREG_AN5(v)   (((v) << 0) & BM_HDMI_HDCPREG_AN5_HDCPREG_AN5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPREG_AN5 field to a new value.
#define BW_HDMI_HDCPREG_AN5_HDCPREG_AN5(v)   BF_CS1(HDMI_HDCPREG_AN5, HDCPREG_AN5, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_AN6 - HDCPREG_AN6 (RW)
 *
 * Contains the value of AN[55:48]   Address Offset: 0x780C  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_AN6 : 8; //!< Contains the value of AN[55:48]
    } B;
} hw_hdmi_hdcpreg_an6_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_AN6 register
 */
#define HW_HDMI_HDCPREG_AN6_ADDR      (REGS_HDMI_BASE + 0x780c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_AN6           (*(volatile hw_hdmi_hdcpreg_an6_t *) HW_HDMI_HDCPREG_AN6_ADDR)
#define HW_HDMI_HDCPREG_AN6_RD()      (HW_HDMI_HDCPREG_AN6.U)
#define HW_HDMI_HDCPREG_AN6_WR(v)     (HW_HDMI_HDCPREG_AN6.U = (v))
#define HW_HDMI_HDCPREG_AN6_SET(v)    (HW_HDMI_HDCPREG_AN6_WR(HW_HDMI_HDCPREG_AN6_RD() |  (v)))
#define HW_HDMI_HDCPREG_AN6_CLR(v)    (HW_HDMI_HDCPREG_AN6_WR(HW_HDMI_HDCPREG_AN6_RD() & ~(v)))
#define HW_HDMI_HDCPREG_AN6_TOG(v)    (HW_HDMI_HDCPREG_AN6_WR(HW_HDMI_HDCPREG_AN6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_AN6 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_AN6, field HDCPREG_AN6 (RW)
 *
 * Contains the value of AN[55:48]
 */

#define BP_HDMI_HDCPREG_AN6_HDCPREG_AN6      0
#define BM_HDMI_HDCPREG_AN6_HDCPREG_AN6      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_AN6_HDCPREG_AN6(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_AN6_HDCPREG_AN6)
#else
#define BF_HDMI_HDCPREG_AN6_HDCPREG_AN6(v)   (((v) << 0) & BM_HDMI_HDCPREG_AN6_HDCPREG_AN6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPREG_AN6 field to a new value.
#define BW_HDMI_HDCPREG_AN6_HDCPREG_AN6(v)   BF_CS1(HDMI_HDCPREG_AN6, HDCPREG_AN6, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_HDCPREG_AN7 - HDCPREG_AN7 (RW)
 *
 * Contains the value of AN[63:56]   Address Offset: 0x780D  Size: 8 bits  Value after Reset: 0x00
 * Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char HDCPREG_AN7 : 8; //!< Contains the value of AN[63:56]
    } B;
} hw_hdmi_hdcpreg_an7_t;
#endif

/*
 * constants & macros for entire HDMI_HDCPREG_AN7 register
 */
#define HW_HDMI_HDCPREG_AN7_ADDR      (REGS_HDMI_BASE + 0x780d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_HDCPREG_AN7           (*(volatile hw_hdmi_hdcpreg_an7_t *) HW_HDMI_HDCPREG_AN7_ADDR)
#define HW_HDMI_HDCPREG_AN7_RD()      (HW_HDMI_HDCPREG_AN7.U)
#define HW_HDMI_HDCPREG_AN7_WR(v)     (HW_HDMI_HDCPREG_AN7.U = (v))
#define HW_HDMI_HDCPREG_AN7_SET(v)    (HW_HDMI_HDCPREG_AN7_WR(HW_HDMI_HDCPREG_AN7_RD() |  (v)))
#define HW_HDMI_HDCPREG_AN7_CLR(v)    (HW_HDMI_HDCPREG_AN7_WR(HW_HDMI_HDCPREG_AN7_RD() & ~(v)))
#define HW_HDMI_HDCPREG_AN7_TOG(v)    (HW_HDMI_HDCPREG_AN7_WR(HW_HDMI_HDCPREG_AN7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_HDCPREG_AN7 bitfields
 */

/* --- Register HW_HDMI_HDCPREG_AN7, field HDCPREG_AN7 (RW)
 *
 * Contains the value of AN[63:56]
 */

#define BP_HDMI_HDCPREG_AN7_HDCPREG_AN7      0
#define BM_HDMI_HDCPREG_AN7_HDCPREG_AN7      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_HDCPREG_AN7_HDCPREG_AN7(v)   ((((reg32_t) v) << 0) & BM_HDMI_HDCPREG_AN7_HDCPREG_AN7)
#else
#define BF_HDMI_HDCPREG_AN7_HDCPREG_AN7(v)   (((v) << 0) & BM_HDMI_HDCPREG_AN7_HDCPREG_AN7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HDCPREG_AN7 field to a new value.
#define BW_HDMI_HDCPREG_AN7_HDCPREG_AN7(v)   BF_CS1(HDMI_HDCPREG_AN7, HDCPREG_AN7, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_CTRL - CEC_CTRL (RW)
 *
 * CEC registers control the CEC feature that is implemented in HDMI TX. They perform various
 * functions like controlling, monitoring, and buffering data for the transmitter and the receiver.
 * This register handles the main control of the CEC initiator.   Address Offset: 0x7D00  Size: 8
 * bits  Value after Reset: 0x02  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char SEND : 1; //!< 
        unsigned char FRAME_TYP : 2; //!< 
        unsigned char BC_NACK : 1; //!< 
        unsigned char STANDBY : 1; //!< 
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_cec_ctrl_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_CTRL register
 */
#define HW_HDMI_CEC_CTRL_ADDR      (REGS_HDMI_BASE + 0x7d00)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_CTRL           (*(volatile hw_hdmi_cec_ctrl_t *) HW_HDMI_CEC_CTRL_ADDR)
#define HW_HDMI_CEC_CTRL_RD()      (HW_HDMI_CEC_CTRL.U)
#define HW_HDMI_CEC_CTRL_WR(v)     (HW_HDMI_CEC_CTRL.U = (v))
#define HW_HDMI_CEC_CTRL_SET(v)    (HW_HDMI_CEC_CTRL_WR(HW_HDMI_CEC_CTRL_RD() |  (v)))
#define HW_HDMI_CEC_CTRL_CLR(v)    (HW_HDMI_CEC_CTRL_WR(HW_HDMI_CEC_CTRL_RD() & ~(v)))
#define HW_HDMI_CEC_CTRL_TOG(v)    (HW_HDMI_CEC_CTRL_WR(HW_HDMI_CEC_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_CTRL bitfields
 */

/* --- Register HW_HDMI_CEC_CTRL, field SEND (RW)
 *

 *
 * Values:
 * 0 - Reset to 0 by hardware when the CEC transmission is done (no matter successful or failed). It can
 *     also work as an indicator checked by software to see whether the transmission is finished.
 * 1 - Set by software to trigger CEC sending a frame as an initiator. This bit keeps at 1 while the
 *     transmission is going on.
 */

#define BP_HDMI_CEC_CTRL_SEND      0
#define BM_HDMI_CEC_CTRL_SEND      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_CTRL_SEND(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_CTRL_SEND)
#else
#define BF_HDMI_CEC_CTRL_SEND(v)   (((v) << 0) & BM_HDMI_CEC_CTRL_SEND)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEND field to a new value.
#define BW_HDMI_CEC_CTRL_SEND(v)   BF_CS1(HDMI_CEC_CTRL, SEND, v)
#endif


/* --- Register HW_HDMI_CEC_CTRL, field FRAME_TYP (RW)
 *

 *
 * Values:
 * 00 - Signal Free Time = 3-bit periods. Previous attempt to send frame is unsuccessful.
 * 01 - Signal Free Time = 5-bit periods. New initiator wants to send a frame.
 * 10 - Signal Free Time = 7-bit periods. Present initiator wants to send another frame immediately after
 *     its previous frame. (spec CEC 9.1)
 * 11 - Illegal value. If software write this value, hardware will set the value to the default 2'b01.
 */

#define BP_HDMI_CEC_CTRL_FRAME_TYP      1
#define BM_HDMI_CEC_CTRL_FRAME_TYP      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_CTRL_FRAME_TYP(v)   ((((reg32_t) v) << 1) & BM_HDMI_CEC_CTRL_FRAME_TYP)
#else
#define BF_HDMI_CEC_CTRL_FRAME_TYP(v)   (((v) << 1) & BM_HDMI_CEC_CTRL_FRAME_TYP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_TYP field to a new value.
#define BW_HDMI_CEC_CTRL_FRAME_TYP(v)   BF_CS1(HDMI_CEC_CTRL, FRAME_TYP, v)
#endif


/* --- Register HW_HDMI_CEC_CTRL, field BC_NACK (RW)
 *

 *
 * Values:
 * 0 - Reset by software to ACK the received broadcast message.
 * 1 - Set by software to NACK the received broadcast message. This bit holds till software resets. The
 *     broadcasts will be answered with 1'b0. It means the follower reject the message.
 */

#define BP_HDMI_CEC_CTRL_BC_NACK      3
#define BM_HDMI_CEC_CTRL_BC_NACK      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_CTRL_BC_NACK(v)   ((((reg32_t) v) << 3) & BM_HDMI_CEC_CTRL_BC_NACK)
#else
#define BF_HDMI_CEC_CTRL_BC_NACK(v)   (((v) << 3) & BM_HDMI_CEC_CTRL_BC_NACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BC_NACK field to a new value.
#define BW_HDMI_CEC_CTRL_BC_NACK(v)   BF_CS1(HDMI_CEC_CTRL, BC_NACK, v)
#endif


/* --- Register HW_HDMI_CEC_CTRL, field STANDBY (RW)
 *

 *
 * Values:
 * 0 - CEC controller responds the ACK to all messages.
 * 1 - CEC controller responds with ACK to all ping messages (only when the EOM is received) and responds
 *     with NACK to all other messages, generating wake-up status for selected opcodes. Attention
 *     that the NACK will only be posted on the last block of a frame.
 */

#define BP_HDMI_CEC_CTRL_STANDBY      4
#define BM_HDMI_CEC_CTRL_STANDBY      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_CTRL_STANDBY(v)   ((((reg32_t) v) << 4) & BM_HDMI_CEC_CTRL_STANDBY)
#else
#define BF_HDMI_CEC_CTRL_STANDBY(v)   (((v) << 4) & BM_HDMI_CEC_CTRL_STANDBY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STANDBY field to a new value.
#define BW_HDMI_CEC_CTRL_STANDBY(v)   BF_CS1(HDMI_CEC_CTRL, STANDBY, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_STAT - CEC_STAT (RO)
 *
 * This register indicates the status of CEC line. All bits are read only. When an event occurs, the
 * corresponding bit will set to 1 for one SFR clock cycle only. Then, the bit automatically resets
 * to 0. No software reset is required. Software can read the "stable" interrupts on IH_CEC_STAT0
 * register (this register has the same bit arrangement as CEC_STAT register).   Address Offset:
 * 0x7D01  Size: 8 bits  Value after Reset: N/A  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DONE : 1; //!< The current transmission is successful (for initiator only).
        unsigned char EOM : 1; //!< EOM is detected so that the received data is ready in the receiver data buffer (for follower only).
        unsigned char NACK : 1; //!< A frame is not acknowledged in a directly addressed message. Or a frame is negatively acknowledged in a broadcast message (for initiator only).
        unsigned char ARB_LOST : 1; //!< The initiator losses the CEC line arbitration to a second initiator. (specification CEC 9).
        unsigned char ERROR_INIT : 1; //!< An error is detected on cec line (for initiator only).
        unsigned char ERROR_FOLL : 1; //!< An error is notified by a follower. Abnormal logic data bit error (for follower).
        unsigned char WAKEUP : 1; //!< Follower received wake-up command (for follower only).
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_cec_stat_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_STAT register
 */
#define HW_HDMI_CEC_STAT_ADDR      (REGS_HDMI_BASE + 0x7d01)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_STAT           (*(volatile hw_hdmi_cec_stat_t *) HW_HDMI_CEC_STAT_ADDR)
#define HW_HDMI_CEC_STAT_RD()      (HW_HDMI_CEC_STAT.U)
#endif

/*
 * constants & macros for individual HDMI_CEC_STAT bitfields
 */

/* --- Register HW_HDMI_CEC_STAT, field DONE (RO)
 *
 * The current transmission is successful (for initiator only).
 */

#define BP_HDMI_CEC_STAT_DONE      0
#define BM_HDMI_CEC_STAT_DONE      0x00000001

/* --- Register HW_HDMI_CEC_STAT, field EOM (RO)
 *
 * EOM is detected so that the received data is ready in the receiver data buffer (for follower
 * only).
 */

#define BP_HDMI_CEC_STAT_EOM      1
#define BM_HDMI_CEC_STAT_EOM      0x00000002

/* --- Register HW_HDMI_CEC_STAT, field NACK (RO)
 *
 * A frame is not acknowledged in a directly addressed message. Or a frame is negatively
 * acknowledged in a broadcast message (for initiator only).
 */

#define BP_HDMI_CEC_STAT_NACK      2
#define BM_HDMI_CEC_STAT_NACK      0x00000004

/* --- Register HW_HDMI_CEC_STAT, field ARB_LOST (RO)
 *
 * The initiator losses the CEC line arbitration to a second initiator. (specification CEC 9).
 */

#define BP_HDMI_CEC_STAT_ARB_LOST      3
#define BM_HDMI_CEC_STAT_ARB_LOST      0x00000008

/* --- Register HW_HDMI_CEC_STAT, field ERROR_INIT (RO)
 *
 * An error is detected on cec line (for initiator only).
 */

#define BP_HDMI_CEC_STAT_ERROR_INIT      4
#define BM_HDMI_CEC_STAT_ERROR_INIT      0x00000010

/* --- Register HW_HDMI_CEC_STAT, field ERROR_FOLL (RO)
 *
 * An error is notified by a follower. Abnormal logic data bit error (for follower).
 */

#define BP_HDMI_CEC_STAT_ERROR_FOLL      5
#define BM_HDMI_CEC_STAT_ERROR_FOLL      0x00000020

/* --- Register HW_HDMI_CEC_STAT, field WAKEUP (RO)
 *
 * Follower received wake-up command (for follower only).
 */

#define BP_HDMI_CEC_STAT_WAKEUP      6
#define BM_HDMI_CEC_STAT_WAKEUP      0x00000040

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_MASK - CEC_MASK (RW)
 *
 * This read/write register masks/unmasks the interrupt events. When the bit is set to 1 (masked),
 * the corresponding event will not trigger an interrupt signal at the system interface. When the
 * bit is reset to 0, the interrupt event is unmasked.   Address Offset: 0x7D02  Size: 8 bits  Value
 * after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DONE_MASK : 1; //!< The current transmission is successful (for initiator only).
        unsigned char EOM_MASK : 1; //!< EOM is detected so that the received data is ready in the receiver data buffer (for follower only).
        unsigned char NACK_MASK : 1; //!< A frame is not acknowledged in a directly addressed message. Or a frame is negatively acknowledged in a broadcast message (for initiator only).
        unsigned char ARB_LOST_MASK : 1; //!< The initiator losses the CEC line arbitration to a second initiator. (specification CEC 9).
        unsigned char ERROR_INIT_MASK : 1; //!< An error is detected on cec line (for initiator only).
        unsigned char ERROR_FOLL__MASK : 1; //!< An error is notified by a follower. Abnormal logic data bit error (for follower).
        unsigned char WAKEUP_MASK : 1; //!< Follower wake-up signal mask
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_cec_mask_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_MASK register
 */
#define HW_HDMI_CEC_MASK_ADDR      (REGS_HDMI_BASE + 0x7d02)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_MASK           (*(volatile hw_hdmi_cec_mask_t *) HW_HDMI_CEC_MASK_ADDR)
#define HW_HDMI_CEC_MASK_RD()      (HW_HDMI_CEC_MASK.U)
#define HW_HDMI_CEC_MASK_WR(v)     (HW_HDMI_CEC_MASK.U = (v))
#define HW_HDMI_CEC_MASK_SET(v)    (HW_HDMI_CEC_MASK_WR(HW_HDMI_CEC_MASK_RD() |  (v)))
#define HW_HDMI_CEC_MASK_CLR(v)    (HW_HDMI_CEC_MASK_WR(HW_HDMI_CEC_MASK_RD() & ~(v)))
#define HW_HDMI_CEC_MASK_TOG(v)    (HW_HDMI_CEC_MASK_WR(HW_HDMI_CEC_MASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_MASK bitfields
 */

/* --- Register HW_HDMI_CEC_MASK, field DONE_MASK (RW)
 *
 * The current transmission is successful (for initiator only).
 */

#define BP_HDMI_CEC_MASK_DONE_MASK      0
#define BM_HDMI_CEC_MASK_DONE_MASK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_MASK_DONE_MASK(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_MASK_DONE_MASK)
#else
#define BF_HDMI_CEC_MASK_DONE_MASK(v)   (((v) << 0) & BM_HDMI_CEC_MASK_DONE_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_MASK field to a new value.
#define BW_HDMI_CEC_MASK_DONE_MASK(v)   BF_CS1(HDMI_CEC_MASK, DONE_MASK, v)
#endif

/* --- Register HW_HDMI_CEC_MASK, field EOM_MASK (RW)
 *
 * EOM is detected so that the received data is ready in the receiver data buffer (for follower
 * only).
 */

#define BP_HDMI_CEC_MASK_EOM_MASK      1
#define BM_HDMI_CEC_MASK_EOM_MASK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_MASK_EOM_MASK(v)   ((((reg32_t) v) << 1) & BM_HDMI_CEC_MASK_EOM_MASK)
#else
#define BF_HDMI_CEC_MASK_EOM_MASK(v)   (((v) << 1) & BM_HDMI_CEC_MASK_EOM_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EOM_MASK field to a new value.
#define BW_HDMI_CEC_MASK_EOM_MASK(v)   BF_CS1(HDMI_CEC_MASK, EOM_MASK, v)
#endif

/* --- Register HW_HDMI_CEC_MASK, field NACK_MASK (RW)
 *
 * A frame is not acknowledged in a directly addressed message. Or a frame is negatively
 * acknowledged in a broadcast message (for initiator only).
 */

#define BP_HDMI_CEC_MASK_NACK_MASK      2
#define BM_HDMI_CEC_MASK_NACK_MASK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_MASK_NACK_MASK(v)   ((((reg32_t) v) << 2) & BM_HDMI_CEC_MASK_NACK_MASK)
#else
#define BF_HDMI_CEC_MASK_NACK_MASK(v)   (((v) << 2) & BM_HDMI_CEC_MASK_NACK_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_MASK field to a new value.
#define BW_HDMI_CEC_MASK_NACK_MASK(v)   BF_CS1(HDMI_CEC_MASK, NACK_MASK, v)
#endif

/* --- Register HW_HDMI_CEC_MASK, field ARB_LOST_MASK (RW)
 *
 * The initiator losses the CEC line arbitration to a second initiator. (specification CEC 9).
 */

#define BP_HDMI_CEC_MASK_ARB_LOST_MASK      3
#define BM_HDMI_CEC_MASK_ARB_LOST_MASK      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_MASK_ARB_LOST_MASK(v)   ((((reg32_t) v) << 3) & BM_HDMI_CEC_MASK_ARB_LOST_MASK)
#else
#define BF_HDMI_CEC_MASK_ARB_LOST_MASK(v)   (((v) << 3) & BM_HDMI_CEC_MASK_ARB_LOST_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARB_LOST_MASK field to a new value.
#define BW_HDMI_CEC_MASK_ARB_LOST_MASK(v)   BF_CS1(HDMI_CEC_MASK, ARB_LOST_MASK, v)
#endif

/* --- Register HW_HDMI_CEC_MASK, field ERROR_INIT_MASK (RW)
 *
 * An error is detected on cec line (for initiator only).
 */

#define BP_HDMI_CEC_MASK_ERROR_INIT_MASK      4
#define BM_HDMI_CEC_MASK_ERROR_INIT_MASK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_MASK_ERROR_INIT_MASK(v)   ((((reg32_t) v) << 4) & BM_HDMI_CEC_MASK_ERROR_INIT_MASK)
#else
#define BF_HDMI_CEC_MASK_ERROR_INIT_MASK(v)   (((v) << 4) & BM_HDMI_CEC_MASK_ERROR_INIT_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_INIT_MASK field to a new value.
#define BW_HDMI_CEC_MASK_ERROR_INIT_MASK(v)   BF_CS1(HDMI_CEC_MASK, ERROR_INIT_MASK, v)
#endif

/* --- Register HW_HDMI_CEC_MASK, field ERROR_FOLL__MASK (RW)
 *
 * An error is notified by a follower. Abnormal logic data bit error (for follower).
 */

#define BP_HDMI_CEC_MASK_ERROR_FOLL__MASK      5
#define BM_HDMI_CEC_MASK_ERROR_FOLL__MASK      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_MASK_ERROR_FOLL__MASK(v)   ((((reg32_t) v) << 5) & BM_HDMI_CEC_MASK_ERROR_FOLL__MASK)
#else
#define BF_HDMI_CEC_MASK_ERROR_FOLL__MASK(v)   (((v) << 5) & BM_HDMI_CEC_MASK_ERROR_FOLL__MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_FOLL__MASK field to a new value.
#define BW_HDMI_CEC_MASK_ERROR_FOLL__MASK(v)   BF_CS1(HDMI_CEC_MASK, ERROR_FOLL__MASK, v)
#endif

/* --- Register HW_HDMI_CEC_MASK, field WAKEUP_MASK (RW)
 *
 * Follower wake-up signal mask
 */

#define BP_HDMI_CEC_MASK_WAKEUP_MASK      6
#define BM_HDMI_CEC_MASK_WAKEUP_MASK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_MASK_WAKEUP_MASK(v)   ((((reg32_t) v) << 6) & BM_HDMI_CEC_MASK_WAKEUP_MASK)
#else
#define BF_HDMI_CEC_MASK_WAKEUP_MASK(v)   (((v) << 6) & BM_HDMI_CEC_MASK_WAKEUP_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP_MASK field to a new value.
#define BW_HDMI_CEC_MASK_WAKEUP_MASK(v)   BF_CS1(HDMI_CEC_MASK, WAKEUP_MASK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_POLARITY - CEC_POLARITY (RW)
 *
 * This register is readable and writable, which controls the polarity of the interrupt status
 * register as well as the polarity of the interrupt signals at system interface.   Address Offset:
 * 0x7D03  Size: 8 bits  Value after Reset: 0x7F  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DONE_POL : 1; //!< Current transmission success or not signal polarity
        unsigned char EOM_POL : 1; //!< EOM detect signal polarity (follower only)
        unsigned char NACK_POL : 1; //!< Frame NACK signal polarity
        unsigned char ARB_LOST_POL : 1; //!< Initiator Arbitration lost signal polarity
        unsigned char ERROR_INIT_POL : 1; //!< CEC line error polarity (for initiator only)
        unsigned char ERROR_FOLL_POL : 1; //!< CEC line error polarity (for follower only)
        unsigned char WAKEUP_POL : 1; //!< Follower wakeup signal polarity
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_cec_polarity_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_POLARITY register
 */
#define HW_HDMI_CEC_POLARITY_ADDR      (REGS_HDMI_BASE + 0x7d03)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_POLARITY           (*(volatile hw_hdmi_cec_polarity_t *) HW_HDMI_CEC_POLARITY_ADDR)
#define HW_HDMI_CEC_POLARITY_RD()      (HW_HDMI_CEC_POLARITY.U)
#define HW_HDMI_CEC_POLARITY_WR(v)     (HW_HDMI_CEC_POLARITY.U = (v))
#define HW_HDMI_CEC_POLARITY_SET(v)    (HW_HDMI_CEC_POLARITY_WR(HW_HDMI_CEC_POLARITY_RD() |  (v)))
#define HW_HDMI_CEC_POLARITY_CLR(v)    (HW_HDMI_CEC_POLARITY_WR(HW_HDMI_CEC_POLARITY_RD() & ~(v)))
#define HW_HDMI_CEC_POLARITY_TOG(v)    (HW_HDMI_CEC_POLARITY_WR(HW_HDMI_CEC_POLARITY_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_POLARITY bitfields
 */

/* --- Register HW_HDMI_CEC_POLARITY, field DONE_POL (RW)
 *
 * Current transmission success or not signal polarity
 */

#define BP_HDMI_CEC_POLARITY_DONE_POL      0
#define BM_HDMI_CEC_POLARITY_DONE_POL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_POLARITY_DONE_POL(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_POLARITY_DONE_POL)
#else
#define BF_HDMI_CEC_POLARITY_DONE_POL(v)   (((v) << 0) & BM_HDMI_CEC_POLARITY_DONE_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_POL field to a new value.
#define BW_HDMI_CEC_POLARITY_DONE_POL(v)   BF_CS1(HDMI_CEC_POLARITY, DONE_POL, v)
#endif

/* --- Register HW_HDMI_CEC_POLARITY, field EOM_POL (RW)
 *
 * EOM detect signal polarity (follower only)
 */

#define BP_HDMI_CEC_POLARITY_EOM_POL      1
#define BM_HDMI_CEC_POLARITY_EOM_POL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_POLARITY_EOM_POL(v)   ((((reg32_t) v) << 1) & BM_HDMI_CEC_POLARITY_EOM_POL)
#else
#define BF_HDMI_CEC_POLARITY_EOM_POL(v)   (((v) << 1) & BM_HDMI_CEC_POLARITY_EOM_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EOM_POL field to a new value.
#define BW_HDMI_CEC_POLARITY_EOM_POL(v)   BF_CS1(HDMI_CEC_POLARITY, EOM_POL, v)
#endif

/* --- Register HW_HDMI_CEC_POLARITY, field NACK_POL (RW)
 *
 * Frame NACK signal polarity
 */

#define BP_HDMI_CEC_POLARITY_NACK_POL      2
#define BM_HDMI_CEC_POLARITY_NACK_POL      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_POLARITY_NACK_POL(v)   ((((reg32_t) v) << 2) & BM_HDMI_CEC_POLARITY_NACK_POL)
#else
#define BF_HDMI_CEC_POLARITY_NACK_POL(v)   (((v) << 2) & BM_HDMI_CEC_POLARITY_NACK_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_POL field to a new value.
#define BW_HDMI_CEC_POLARITY_NACK_POL(v)   BF_CS1(HDMI_CEC_POLARITY, NACK_POL, v)
#endif

/* --- Register HW_HDMI_CEC_POLARITY, field ARB_LOST_POL (RW)
 *
 * Initiator Arbitration lost signal polarity
 */

#define BP_HDMI_CEC_POLARITY_ARB_LOST_POL      3
#define BM_HDMI_CEC_POLARITY_ARB_LOST_POL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_POLARITY_ARB_LOST_POL(v)   ((((reg32_t) v) << 3) & BM_HDMI_CEC_POLARITY_ARB_LOST_POL)
#else
#define BF_HDMI_CEC_POLARITY_ARB_LOST_POL(v)   (((v) << 3) & BM_HDMI_CEC_POLARITY_ARB_LOST_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARB_LOST_POL field to a new value.
#define BW_HDMI_CEC_POLARITY_ARB_LOST_POL(v)   BF_CS1(HDMI_CEC_POLARITY, ARB_LOST_POL, v)
#endif

/* --- Register HW_HDMI_CEC_POLARITY, field ERROR_INIT_POL (RW)
 *
 * CEC line error polarity (for initiator only)
 */

#define BP_HDMI_CEC_POLARITY_ERROR_INIT_POL      4
#define BM_HDMI_CEC_POLARITY_ERROR_INIT_POL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_POLARITY_ERROR_INIT_POL(v)   ((((reg32_t) v) << 4) & BM_HDMI_CEC_POLARITY_ERROR_INIT_POL)
#else
#define BF_HDMI_CEC_POLARITY_ERROR_INIT_POL(v)   (((v) << 4) & BM_HDMI_CEC_POLARITY_ERROR_INIT_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_INIT_POL field to a new value.
#define BW_HDMI_CEC_POLARITY_ERROR_INIT_POL(v)   BF_CS1(HDMI_CEC_POLARITY, ERROR_INIT_POL, v)
#endif

/* --- Register HW_HDMI_CEC_POLARITY, field ERROR_FOLL_POL (RW)
 *
 * CEC line error polarity (for follower only)
 */

#define BP_HDMI_CEC_POLARITY_ERROR_FOLL_POL      5
#define BM_HDMI_CEC_POLARITY_ERROR_FOLL_POL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_POLARITY_ERROR_FOLL_POL(v)   ((((reg32_t) v) << 5) & BM_HDMI_CEC_POLARITY_ERROR_FOLL_POL)
#else
#define BF_HDMI_CEC_POLARITY_ERROR_FOLL_POL(v)   (((v) << 5) & BM_HDMI_CEC_POLARITY_ERROR_FOLL_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_FOLL_POL field to a new value.
#define BW_HDMI_CEC_POLARITY_ERROR_FOLL_POL(v)   BF_CS1(HDMI_CEC_POLARITY, ERROR_FOLL_POL, v)
#endif

/* --- Register HW_HDMI_CEC_POLARITY, field WAKEUP_POL (RW)
 *
 * Follower wakeup signal polarity
 */

#define BP_HDMI_CEC_POLARITY_WAKEUP_POL      6
#define BM_HDMI_CEC_POLARITY_WAKEUP_POL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_POLARITY_WAKEUP_POL(v)   ((((reg32_t) v) << 6) & BM_HDMI_CEC_POLARITY_WAKEUP_POL)
#else
#define BF_HDMI_CEC_POLARITY_WAKEUP_POL(v)   (((v) << 6) & BM_HDMI_CEC_POLARITY_WAKEUP_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP_POL field to a new value.
#define BW_HDMI_CEC_POLARITY_WAKEUP_POL(v)   BF_CS1(HDMI_CEC_POLARITY, WAKEUP_POL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_INT - CEC_INT (RO)
 *
 * This register is read only. Each bit of the register is output at the system interface. The
 * output signals hold the active interrupt state (high or low) for only one SFR clock cycle. Then
 * the hardware resets the bit to an inactive state. Software can read the "stable" interrupts on
 * the IH_CEC_STAT0 register at address 0x0106 (this register has the same bit arrangement as the
 * CEC_STAT register).  The functional formula for the interrupts is:  CEC_INT = (CEC_MASK == 0b) &&
 * (CEC_STATUS == CEC_POLARITY)   Address Offset: 0x7D04  Size: 8 bits  Value after Reset: 0x00
 * Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DONE_INT : 1; //!< EOM detect interrupt (for follower only)
        unsigned char EOM_INT : 1; //!< Frame NACK interrupt
        unsigned char NACK_INT : 1; //!< Initiator Arbitration lost interrupt
        unsigned char ARB_LOST_INT : 1; //!< CEC line error interrupt (for initiator only)
        unsigned char ERROR_INIT_INT : 1; //!< CEC line error interrupt (for follower only)
        unsigned char ERROR_FOLL_INT : 1; //!< Follower wakeup interrupt
        unsigned char WAKEUP_INT : 1; //!< Follower wakeup signal polarity
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_cec_int_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_INT register
 */
#define HW_HDMI_CEC_INT_ADDR      (REGS_HDMI_BASE + 0x7d04)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_INT           (*(volatile hw_hdmi_cec_int_t *) HW_HDMI_CEC_INT_ADDR)
#define HW_HDMI_CEC_INT_RD()      (HW_HDMI_CEC_INT.U)
#endif

/*
 * constants & macros for individual HDMI_CEC_INT bitfields
 */

/* --- Register HW_HDMI_CEC_INT, field DONE_INT (RO)
 *
 * EOM detect interrupt (for follower only)
 */

#define BP_HDMI_CEC_INT_DONE_INT      0
#define BM_HDMI_CEC_INT_DONE_INT      0x00000001

/* --- Register HW_HDMI_CEC_INT, field EOM_INT (RO)
 *
 * Frame NACK interrupt
 */

#define BP_HDMI_CEC_INT_EOM_INT      1
#define BM_HDMI_CEC_INT_EOM_INT      0x00000002

/* --- Register HW_HDMI_CEC_INT, field NACK_INT (RO)
 *
 * Initiator Arbitration lost interrupt
 */

#define BP_HDMI_CEC_INT_NACK_INT      2
#define BM_HDMI_CEC_INT_NACK_INT      0x00000004

/* --- Register HW_HDMI_CEC_INT, field ARB_LOST_INT (RO)
 *
 * CEC line error interrupt (for initiator only)
 */

#define BP_HDMI_CEC_INT_ARB_LOST_INT      3
#define BM_HDMI_CEC_INT_ARB_LOST_INT      0x00000008

/* --- Register HW_HDMI_CEC_INT, field ERROR_INIT_INT (RO)
 *
 * CEC line error interrupt (for follower only)
 */

#define BP_HDMI_CEC_INT_ERROR_INIT_INT      4
#define BM_HDMI_CEC_INT_ERROR_INIT_INT      0x00000010

/* --- Register HW_HDMI_CEC_INT, field ERROR_FOLL_INT (RO)
 *
 * Follower wakeup interrupt
 */

#define BP_HDMI_CEC_INT_ERROR_FOLL_INT      5
#define BM_HDMI_CEC_INT_ERROR_FOLL_INT      0x00000020

/* --- Register HW_HDMI_CEC_INT, field WAKEUP_INT (RO)
 *
 * Follower wakeup signal polarity
 */

#define BP_HDMI_CEC_INT_WAKEUP_INT      6
#define BM_HDMI_CEC_INT_WAKEUP_INT      0x00000040

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_ADDR_L - CEC_ADDR_L (RW)
 *
 * CEC_ADDR_L and CEC_ADDR_H registers indicate the logical address(es) allocated to the CEC device.
 * The logical address mappings are shown in and . This register is written by software when the
 * logical allocation is finished. Bit value 1 means the corresponding logical address is allocated
 * to this device. Bit value 0 means the corresponding logical address is not allocated to this
 * device.   Address Offset: 0x7D05  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CEC_ADDR_L_ : 1; //!< Logical address 0 - Device TV
        unsigned char CEC_ADDR_L_1 : 1; //!< Logical address 1 - Recording Device 1
        unsigned char CEC_ADDR_L_2 : 1; //!< Logical address 2 - Recording Device 2
        unsigned char CEC_ADDR_L_3 : 1; //!< Logical address 3 - Tuner 1
        unsigned char CEC_ADDR_L_4 : 1; //!< Logical address 4 - Playback Device 1
        unsigned char CEC_ADDR_L_5 : 1; //!< Logical address 5 - Audio System
        unsigned char CEC_ADDR_L_6 : 1; //!< Logical address 6 - Tuner 2
        unsigned char CEC_ADDR_L_7 : 1; //!< Logical address 7 - Tuner 3
    } B;
} hw_hdmi_cec_addr_l_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_ADDR_L register
 */
#define HW_HDMI_CEC_ADDR_L_ADDR      (REGS_HDMI_BASE + 0x7d05)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_ADDR_L           (*(volatile hw_hdmi_cec_addr_l_t *) HW_HDMI_CEC_ADDR_L_ADDR)
#define HW_HDMI_CEC_ADDR_L_RD()      (HW_HDMI_CEC_ADDR_L.U)
#define HW_HDMI_CEC_ADDR_L_WR(v)     (HW_HDMI_CEC_ADDR_L.U = (v))
#define HW_HDMI_CEC_ADDR_L_SET(v)    (HW_HDMI_CEC_ADDR_L_WR(HW_HDMI_CEC_ADDR_L_RD() |  (v)))
#define HW_HDMI_CEC_ADDR_L_CLR(v)    (HW_HDMI_CEC_ADDR_L_WR(HW_HDMI_CEC_ADDR_L_RD() & ~(v)))
#define HW_HDMI_CEC_ADDR_L_TOG(v)    (HW_HDMI_CEC_ADDR_L_WR(HW_HDMI_CEC_ADDR_L_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_ADDR_L bitfields
 */

/* --- Register HW_HDMI_CEC_ADDR_L, field CEC_ADDR_L_ (RW)
 *
 * Logical address 0 - Device TV
 */

#define BP_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0
#define BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#else
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   (((v) << 0) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_L_ field to a new value.
#define BW_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   BF_CS1(HDMI_CEC_ADDR_L, CEC_ADDR_L_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_L, field CEC_ADDR_L_ (RW)
 *
 * Logical address 1 - Recording Device 1
 */

#define BP_HDMI_CEC_ADDR_L_CEC_ADDR_L_      1
#define BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   ((((reg32_t) v) << 1) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#else
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   (((v) << 1) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_L_ field to a new value.
#define BW_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   BF_CS1(HDMI_CEC_ADDR_L, CEC_ADDR_L_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_L, field CEC_ADDR_L_ (RW)
 *
 * Logical address 2 - Recording Device 2
 */

#define BP_HDMI_CEC_ADDR_L_CEC_ADDR_L_      2
#define BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   ((((reg32_t) v) << 2) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#else
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   (((v) << 2) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_L_ field to a new value.
#define BW_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   BF_CS1(HDMI_CEC_ADDR_L, CEC_ADDR_L_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_L, field CEC_ADDR_L_ (RW)
 *
 * Logical address 3 - Tuner 1
 */

#define BP_HDMI_CEC_ADDR_L_CEC_ADDR_L_      3
#define BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   ((((reg32_t) v) << 3) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#else
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   (((v) << 3) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_L_ field to a new value.
#define BW_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   BF_CS1(HDMI_CEC_ADDR_L, CEC_ADDR_L_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_L, field CEC_ADDR_L_ (RW)
 *
 * Logical address 4 - Playback Device 1
 */

#define BP_HDMI_CEC_ADDR_L_CEC_ADDR_L_      4
#define BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   ((((reg32_t) v) << 4) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#else
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   (((v) << 4) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_L_ field to a new value.
#define BW_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   BF_CS1(HDMI_CEC_ADDR_L, CEC_ADDR_L_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_L, field CEC_ADDR_L_ (RW)
 *
 * Logical address 5 - Audio System
 */

#define BP_HDMI_CEC_ADDR_L_CEC_ADDR_L_      5
#define BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   ((((reg32_t) v) << 5) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#else
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   (((v) << 5) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_L_ field to a new value.
#define BW_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   BF_CS1(HDMI_CEC_ADDR_L, CEC_ADDR_L_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_L, field CEC_ADDR_L_ (RW)
 *
 * Logical address 6 - Tuner 2
 */

#define BP_HDMI_CEC_ADDR_L_CEC_ADDR_L_      6
#define BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   ((((reg32_t) v) << 6) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#else
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   (((v) << 6) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_L_ field to a new value.
#define BW_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   BF_CS1(HDMI_CEC_ADDR_L, CEC_ADDR_L_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_L, field CEC_ADDR_L_ (RW)
 *
 * Logical address 7 - Tuner 3
 */

#define BP_HDMI_CEC_ADDR_L_CEC_ADDR_L_      7
#define BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   ((((reg32_t) v) << 7) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#else
#define BF_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   (((v) << 7) & BM_HDMI_CEC_ADDR_L_CEC_ADDR_L_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_L_ field to a new value.
#define BW_HDMI_CEC_ADDR_L_CEC_ADDR_L_(v)   BF_CS1(HDMI_CEC_ADDR_L, CEC_ADDR_L_, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_ADDR_H - CEC_ADDR_H (RW)
 *
 * CEC_ADDR_L and CEC_ADDR_H registers indicate the logical address(es) allocated to the CEC device.
 * The logical address mappings are shown in and . This register is written by software when the
 * logical allocation is finished. Bit value 1 means the corresponding logical address is allocated
 * to this device. Bit value 0 means the corresponding logical address is not allocated to this
 * device.   Address Offset: 0x7D06  Size: 8 bits  Value after Reset: 0x80  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CEC_ADDR_H_ : 1; //!< Logical address 8 - Playback Device 2
        unsigned char CEC_ADDR_H_1 : 1; //!< Logical address 9 - Playback Device 3
        unsigned char CEC_ADDR_H_2 : 1; //!< Logical address 10 - Tuner 4
        unsigned char CEC_ADDR_H_3 : 1; //!< Logical address 11 - Playback Device 3
        unsigned char CEC_ADDR_H_4 : 1; //!< Logical address 12 - Reserved
        unsigned char CEC_ADDR_H_5 : 1; //!< Logical address 13 - Reserved
        unsigned char CEC_ADDR_H_6 : 1; //!< Logical address 14 - Free use
        unsigned char CEC_ADDR_H_7 : 1; //!< Logical address 15 - Unregistered (as initiator address), Broadcast (as destination address)
    } B;
} hw_hdmi_cec_addr_h_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_ADDR_H register
 */
#define HW_HDMI_CEC_ADDR_H_ADDR      (REGS_HDMI_BASE + 0x7d06)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_ADDR_H           (*(volatile hw_hdmi_cec_addr_h_t *) HW_HDMI_CEC_ADDR_H_ADDR)
#define HW_HDMI_CEC_ADDR_H_RD()      (HW_HDMI_CEC_ADDR_H.U)
#define HW_HDMI_CEC_ADDR_H_WR(v)     (HW_HDMI_CEC_ADDR_H.U = (v))
#define HW_HDMI_CEC_ADDR_H_SET(v)    (HW_HDMI_CEC_ADDR_H_WR(HW_HDMI_CEC_ADDR_H_RD() |  (v)))
#define HW_HDMI_CEC_ADDR_H_CLR(v)    (HW_HDMI_CEC_ADDR_H_WR(HW_HDMI_CEC_ADDR_H_RD() & ~(v)))
#define HW_HDMI_CEC_ADDR_H_TOG(v)    (HW_HDMI_CEC_ADDR_H_WR(HW_HDMI_CEC_ADDR_H_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_ADDR_H bitfields
 */

/* --- Register HW_HDMI_CEC_ADDR_H, field CEC_ADDR_H_ (RW)
 *
 * Logical address 8 - Playback Device 2
 */

#define BP_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0
#define BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#else
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   (((v) << 0) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_H_ field to a new value.
#define BW_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   BF_CS1(HDMI_CEC_ADDR_H, CEC_ADDR_H_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_H, field CEC_ADDR_H_ (RW)
 *
 * Logical address 9 - Playback Device 3
 */

#define BP_HDMI_CEC_ADDR_H_CEC_ADDR_H_      1
#define BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   ((((reg32_t) v) << 1) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#else
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   (((v) << 1) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_H_ field to a new value.
#define BW_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   BF_CS1(HDMI_CEC_ADDR_H, CEC_ADDR_H_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_H, field CEC_ADDR_H_ (RW)
 *
 * Logical address 10 - Tuner 4
 */

#define BP_HDMI_CEC_ADDR_H_CEC_ADDR_H_      2
#define BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   ((((reg32_t) v) << 2) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#else
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   (((v) << 2) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_H_ field to a new value.
#define BW_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   BF_CS1(HDMI_CEC_ADDR_H, CEC_ADDR_H_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_H, field CEC_ADDR_H_ (RW)
 *
 * Logical address 11 - Playback Device 3
 */

#define BP_HDMI_CEC_ADDR_H_CEC_ADDR_H_      3
#define BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   ((((reg32_t) v) << 3) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#else
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   (((v) << 3) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_H_ field to a new value.
#define BW_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   BF_CS1(HDMI_CEC_ADDR_H, CEC_ADDR_H_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_H, field CEC_ADDR_H_ (RW)
 *
 * Logical address 12 - Reserved
 */

#define BP_HDMI_CEC_ADDR_H_CEC_ADDR_H_      4
#define BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   ((((reg32_t) v) << 4) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#else
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   (((v) << 4) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_H_ field to a new value.
#define BW_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   BF_CS1(HDMI_CEC_ADDR_H, CEC_ADDR_H_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_H, field CEC_ADDR_H_ (RW)
 *
 * Logical address 13 - Reserved
 */

#define BP_HDMI_CEC_ADDR_H_CEC_ADDR_H_      5
#define BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   ((((reg32_t) v) << 5) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#else
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   (((v) << 5) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_H_ field to a new value.
#define BW_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   BF_CS1(HDMI_CEC_ADDR_H, CEC_ADDR_H_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_H, field CEC_ADDR_H_ (RW)
 *
 * Logical address 14 - Free use
 */

#define BP_HDMI_CEC_ADDR_H_CEC_ADDR_H_      6
#define BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   ((((reg32_t) v) << 6) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#else
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   (((v) << 6) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_H_ field to a new value.
#define BW_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   BF_CS1(HDMI_CEC_ADDR_H, CEC_ADDR_H_, v)
#endif

/* --- Register HW_HDMI_CEC_ADDR_H, field CEC_ADDR_H_ (RW)
 *
 * Logical address 15 - Unregistered (as initiator address), Broadcast (as destination address)
 */

#define BP_HDMI_CEC_ADDR_H_CEC_ADDR_H_      7
#define BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   ((((reg32_t) v) << 7) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#else
#define BF_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   (((v) << 7) & BM_HDMI_CEC_ADDR_H_CEC_ADDR_H_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_ADDR_H_ field to a new value.
#define BW_HDMI_CEC_ADDR_H_CEC_ADDR_H_(v)   BF_CS1(HDMI_CEC_ADDR_H, CEC_ADDR_H_, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_TX_CNT - CEC_TX_CNT (RW)
 *
 * This register indicates the size of the frame in bytes (including header and data blocks), which
 * are available in the transmitter data buffer.  When the value is zero, the CEC controller ignores
 * the send command triggered by software. When the transmission is done (no matter success or not),
 * the current value is held until it is overwritten by software.   Address Offset: 0x7D07  Size: 8
 * bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CEC_TX_CNT_ : 5; //!< CEC Transmitter Counter register: Value after Reset: 5'b00000
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_cec_tx_cnt_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_TX_CNT register
 */
#define HW_HDMI_CEC_TX_CNT_ADDR      (REGS_HDMI_BASE + 0x7d07)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_TX_CNT           (*(volatile hw_hdmi_cec_tx_cnt_t *) HW_HDMI_CEC_TX_CNT_ADDR)
#define HW_HDMI_CEC_TX_CNT_RD()      (HW_HDMI_CEC_TX_CNT.U)
#define HW_HDMI_CEC_TX_CNT_WR(v)     (HW_HDMI_CEC_TX_CNT.U = (v))
#define HW_HDMI_CEC_TX_CNT_SET(v)    (HW_HDMI_CEC_TX_CNT_WR(HW_HDMI_CEC_TX_CNT_RD() |  (v)))
#define HW_HDMI_CEC_TX_CNT_CLR(v)    (HW_HDMI_CEC_TX_CNT_WR(HW_HDMI_CEC_TX_CNT_RD() & ~(v)))
#define HW_HDMI_CEC_TX_CNT_TOG(v)    (HW_HDMI_CEC_TX_CNT_WR(HW_HDMI_CEC_TX_CNT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_TX_CNT bitfields
 */

/* --- Register HW_HDMI_CEC_TX_CNT, field CEC_TX_CNT_ (RW)
 *
 * CEC Transmitter Counter register: Value after Reset: 5'b00000
 *
 * Values:
 * 0 - No data needs to be transmitted.
 * 1 - Frame size is 1 byte.
 * 16 - Frame size is 16 byte.
 */

#define BP_HDMI_CEC_TX_CNT_CEC_TX_CNT_      0
#define BM_HDMI_CEC_TX_CNT_CEC_TX_CNT_      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_TX_CNT_CEC_TX_CNT_(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_TX_CNT_CEC_TX_CNT_)
#else
#define BF_HDMI_CEC_TX_CNT_CEC_TX_CNT_(v)   (((v) << 0) & BM_HDMI_CEC_TX_CNT_CEC_TX_CNT_)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CEC_TX_CNT_ field to a new value.
#define BW_HDMI_CEC_TX_CNT_CEC_TX_CNT_(v)   BF_CS1(HDMI_CEC_TX_CNT, CEC_TX_CNT_, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_RX_CNT - CEC_RX_CNT (RO)
 *
 * These registers (8 bits each) are the buffers used for storing the data waiting for transmission
 * (including header and data blocks).   Address Offset: 0x7D10 .. 0x7D1F  Size: 8 bits  Value after
 * Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char TX_DATA : 8; //!< Header block in CEC_TX_DATA0 Data blockn in CEC_TX_DATAn
    } B;
} hw_hdmi_cec_rx_cnt_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_RX_CNT register
 */
#define HW_HDMI_CEC_RX_CNT_ADDR      (REGS_HDMI_BASE + 0x7d08)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_RX_CNT           (*(volatile hw_hdmi_cec_rx_cnt_t *) HW_HDMI_CEC_RX_CNT_ADDR)
#define HW_HDMI_CEC_RX_CNT_RD()      (HW_HDMI_CEC_RX_CNT.U)
#endif

/*
 * constants & macros for individual HDMI_CEC_RX_CNT bitfields
 */

/* --- Register HW_HDMI_CEC_RX_CNT, field TX_DATA (RO)
 *
 * Header block in CEC_TX_DATA0 Data blockn in CEC_TX_DATAn
 */

#define BP_HDMI_CEC_RX_CNT_TX_DATA      0
#define BM_HDMI_CEC_RX_CNT_TX_DATA      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_TX_DATAN - CEC_TX_DATAn (RW)
 *
 * These registers (8 bit each) are the buffers used for storing the received data (including header
 * and data blocks).   Address Offset: 0x7D20 .. 0x7D2F  Size: 8 bits  Value after Reset: 0x00
 * Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RX_DATA : 8; //!< Header block in CEC_RX_DATA0 Data blockn in CEC_RX_DATAn
    } B;
} hw_hdmi_cec_tx_datan_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_TX_DATAN register
 */
#define HW_HDMI_CEC_TX_DATAN_ADDR      (REGS_HDMI_BASE + 0x7d10)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_TX_DATAN           (*(volatile hw_hdmi_cec_tx_datan_t *) HW_HDMI_CEC_TX_DATAN_ADDR)
#define HW_HDMI_CEC_TX_DATAN_RD()      (HW_HDMI_CEC_TX_DATAN.U)
#define HW_HDMI_CEC_TX_DATAN_WR(v)     (HW_HDMI_CEC_TX_DATAN.U = (v))
#define HW_HDMI_CEC_TX_DATAN_SET(v)    (HW_HDMI_CEC_TX_DATAN_WR(HW_HDMI_CEC_TX_DATAN_RD() |  (v)))
#define HW_HDMI_CEC_TX_DATAN_CLR(v)    (HW_HDMI_CEC_TX_DATAN_WR(HW_HDMI_CEC_TX_DATAN_RD() & ~(v)))
#define HW_HDMI_CEC_TX_DATAN_TOG(v)    (HW_HDMI_CEC_TX_DATAN_WR(HW_HDMI_CEC_TX_DATAN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_TX_DATAN bitfields
 */

/* --- Register HW_HDMI_CEC_TX_DATAN, field RX_DATA (RW)
 *
 * Header block in CEC_RX_DATA0 Data blockn in CEC_RX_DATAn
 */

#define BP_HDMI_CEC_TX_DATAN_RX_DATA      0
#define BM_HDMI_CEC_TX_DATAN_RX_DATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_TX_DATAN_RX_DATA(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_TX_DATAN_RX_DATA)
#else
#define BF_HDMI_CEC_TX_DATAN_RX_DATA(v)   (((v) << 0) & BM_HDMI_CEC_TX_DATAN_RX_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_DATA field to a new value.
#define BW_HDMI_CEC_TX_DATAN_RX_DATA(v)   BF_CS1(HDMI_CEC_TX_DATAN, RX_DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_RX_DATAN - CEC_RX_DATAn (RO)
 *
 * This register indicates the size of the frame in bytes (including header and data blocks), which
 * are available in the receiver data buffer.  Only after the whole receiving process is finished
 * successfully the counter will be refreshed to the value which indicates the total number of data
 * bytes in the Receiver Data Register.   Address Offset: 0x7D08  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CEC_RX_CNT_ : 5; //!< CEC Receiver Counter register Value after Reset: 5'b00000
        unsigned char RESERVED0 : 3; //!< Reserved
    } B;
} hw_hdmi_cec_rx_datan_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_RX_DATAN register
 */
#define HW_HDMI_CEC_RX_DATAN_ADDR      (REGS_HDMI_BASE + 0x7d20)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_RX_DATAN           (*(volatile hw_hdmi_cec_rx_datan_t *) HW_HDMI_CEC_RX_DATAN_ADDR)
#define HW_HDMI_CEC_RX_DATAN_RD()      (HW_HDMI_CEC_RX_DATAN.U)
#endif

/*
 * constants & macros for individual HDMI_CEC_RX_DATAN bitfields
 */

/* --- Register HW_HDMI_CEC_RX_DATAN, field CEC_RX_CNT_ (RO)
 *
 * CEC Receiver Counter register Value after Reset: 5'b00000
 *
 * Values:
 * 0 - No data is received
 * 1 - 1-byte data is received
 * 16 - 16-byte data is received
 */

#define BP_HDMI_CEC_RX_DATAN_CEC_RX_CNT_      0
#define BM_HDMI_CEC_RX_DATAN_CEC_RX_CNT_      0x0000001f


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_LOCK - CEC_LOCK (RW)
 *
 * Address Offset: 0x7D30  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char LOCKED_BUFFER : 1; //!< When a frame is received, this bit would be active. The CEC controller answers to all the messages with NACK until the CPU writes it to '0'.
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_cec_lock_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_LOCK register
 */
#define HW_HDMI_CEC_LOCK_ADDR      (REGS_HDMI_BASE + 0x7d30)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_LOCK           (*(volatile hw_hdmi_cec_lock_t *) HW_HDMI_CEC_LOCK_ADDR)
#define HW_HDMI_CEC_LOCK_RD()      (HW_HDMI_CEC_LOCK.U)
#define HW_HDMI_CEC_LOCK_WR(v)     (HW_HDMI_CEC_LOCK.U = (v))
#define HW_HDMI_CEC_LOCK_SET(v)    (HW_HDMI_CEC_LOCK_WR(HW_HDMI_CEC_LOCK_RD() |  (v)))
#define HW_HDMI_CEC_LOCK_CLR(v)    (HW_HDMI_CEC_LOCK_WR(HW_HDMI_CEC_LOCK_RD() & ~(v)))
#define HW_HDMI_CEC_LOCK_TOG(v)    (HW_HDMI_CEC_LOCK_WR(HW_HDMI_CEC_LOCK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_LOCK bitfields
 */

/* --- Register HW_HDMI_CEC_LOCK, field LOCKED_BUFFER (RW)
 *
 * When a frame is received, this bit would be active. The CEC controller answers to all the
 * messages with NACK until the CPU writes it to '0'.
 */

#define BP_HDMI_CEC_LOCK_LOCKED_BUFFER      0
#define BM_HDMI_CEC_LOCK_LOCKED_BUFFER      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_LOCK_LOCKED_BUFFER(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_LOCK_LOCKED_BUFFER)
#else
#define BF_HDMI_CEC_LOCK_LOCKED_BUFFER(v)   (((v) << 0) & BM_HDMI_CEC_LOCK_LOCKED_BUFFER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCKED_BUFFER field to a new value.
#define BW_HDMI_CEC_LOCK_LOCKED_BUFFER(v)   BF_CS1(HDMI_CEC_LOCK, LOCKED_BUFFER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_CEC_WKUPCTRL - CEC_WKUPCTRL (RW)
 *
 * Address Offset: 0x7D31  Size: 8 bits  Value after Reset: 0xFF  Access: Read/Write   After
 * receiving a message in the CEC_RX_DATA1 (OPCODE) registers, the CEC engine verifies the message
 * opcode[7:0] against one of the previously defined values to generate the wake-up status:
 * Wakeupstatus is 1 when:  received opcode is 0x04 and opcode0x04en is 1 or received opcode is 0x0D
 * and opcode0x0Den is 1 or received opcode is 0x41 and opcode0x41en is 1 or received opcode is 0x42
 * and opcode0x42en is 1 or received opcode is 0x44 and opcode0x44en is 1 or received opcode is 0x70
 * and opcode0x70en is 1 or received opcode is 0x82 and opcode0x82en is 1 or received opcode is 0x86
 * and opcode0x86en is 1  Wakeupstatus is 0 when none of the previous conditions are true.  This
 * formula means that the wake-up status (on CEC_STAT[6] register) is only '1' if the opcode[7:0]
 * received is equal to one of the defined values and the corresponding enable bit of that defined
 * value is set to '1'.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char OPCODE0X04EN : 1; //!< OPCODE 0x04 wake up enable
        unsigned char OPCODE0X0DEN : 1; //!< OPCODE 0x0D wake up enable
        unsigned char OPCODE0X41EN : 1; //!< OPCODE 0x41 wake up enable
        unsigned char OPCODE0X42EN : 1; //!< OPCODE 0x42 wake up enable
        unsigned char OPCODE0X44EN : 1; //!< OPCODE 0x44 wake up enable
        unsigned char OPCODE0X70EN : 1; //!< OPCODE 0x70 wake up enable
        unsigned char OPCODE0X82EN : 1; //!< OPCODE 0x82 wake up enable
        unsigned char OPCODE0X86EN : 1; //!< OPCODE 0x86 wake up enable
    } B;
} hw_hdmi_cec_wkupctrl_t;
#endif

/*
 * constants & macros for entire HDMI_CEC_WKUPCTRL register
 */
#define HW_HDMI_CEC_WKUPCTRL_ADDR      (REGS_HDMI_BASE + 0x7d31)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_CEC_WKUPCTRL           (*(volatile hw_hdmi_cec_wkupctrl_t *) HW_HDMI_CEC_WKUPCTRL_ADDR)
#define HW_HDMI_CEC_WKUPCTRL_RD()      (HW_HDMI_CEC_WKUPCTRL.U)
#define HW_HDMI_CEC_WKUPCTRL_WR(v)     (HW_HDMI_CEC_WKUPCTRL.U = (v))
#define HW_HDMI_CEC_WKUPCTRL_SET(v)    (HW_HDMI_CEC_WKUPCTRL_WR(HW_HDMI_CEC_WKUPCTRL_RD() |  (v)))
#define HW_HDMI_CEC_WKUPCTRL_CLR(v)    (HW_HDMI_CEC_WKUPCTRL_WR(HW_HDMI_CEC_WKUPCTRL_RD() & ~(v)))
#define HW_HDMI_CEC_WKUPCTRL_TOG(v)    (HW_HDMI_CEC_WKUPCTRL_WR(HW_HDMI_CEC_WKUPCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_CEC_WKUPCTRL bitfields
 */

/* --- Register HW_HDMI_CEC_WKUPCTRL, field OPCODE0X04EN (RW)
 *
 * OPCODE 0x04 wake up enable
 */

#define BP_HDMI_CEC_WKUPCTRL_OPCODE0X04EN      0
#define BM_HDMI_CEC_WKUPCTRL_OPCODE0X04EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X04EN(v)   ((((reg32_t) v) << 0) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X04EN)
#else
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X04EN(v)   (((v) << 0) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X04EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OPCODE0X04EN field to a new value.
#define BW_HDMI_CEC_WKUPCTRL_OPCODE0X04EN(v)   BF_CS1(HDMI_CEC_WKUPCTRL, OPCODE0X04EN, v)
#endif

/* --- Register HW_HDMI_CEC_WKUPCTRL, field OPCODE0X0DEN (RW)
 *
 * OPCODE 0x0D wake up enable
 */

#define BP_HDMI_CEC_WKUPCTRL_OPCODE0X0DEN      1
#define BM_HDMI_CEC_WKUPCTRL_OPCODE0X0DEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X0DEN(v)   ((((reg32_t) v) << 1) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X0DEN)
#else
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X0DEN(v)   (((v) << 1) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X0DEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OPCODE0X0DEN field to a new value.
#define BW_HDMI_CEC_WKUPCTRL_OPCODE0X0DEN(v)   BF_CS1(HDMI_CEC_WKUPCTRL, OPCODE0X0DEN, v)
#endif

/* --- Register HW_HDMI_CEC_WKUPCTRL, field OPCODE0X41EN (RW)
 *
 * OPCODE 0x41 wake up enable
 */

#define BP_HDMI_CEC_WKUPCTRL_OPCODE0X41EN      2
#define BM_HDMI_CEC_WKUPCTRL_OPCODE0X41EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X41EN(v)   ((((reg32_t) v) << 2) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X41EN)
#else
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X41EN(v)   (((v) << 2) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X41EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OPCODE0X41EN field to a new value.
#define BW_HDMI_CEC_WKUPCTRL_OPCODE0X41EN(v)   BF_CS1(HDMI_CEC_WKUPCTRL, OPCODE0X41EN, v)
#endif

/* --- Register HW_HDMI_CEC_WKUPCTRL, field OPCODE0X42EN (RW)
 *
 * OPCODE 0x42 wake up enable
 */

#define BP_HDMI_CEC_WKUPCTRL_OPCODE0X42EN      3
#define BM_HDMI_CEC_WKUPCTRL_OPCODE0X42EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X42EN(v)   ((((reg32_t) v) << 3) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X42EN)
#else
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X42EN(v)   (((v) << 3) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X42EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OPCODE0X42EN field to a new value.
#define BW_HDMI_CEC_WKUPCTRL_OPCODE0X42EN(v)   BF_CS1(HDMI_CEC_WKUPCTRL, OPCODE0X42EN, v)
#endif

/* --- Register HW_HDMI_CEC_WKUPCTRL, field OPCODE0X44EN (RW)
 *
 * OPCODE 0x44 wake up enable
 */

#define BP_HDMI_CEC_WKUPCTRL_OPCODE0X44EN      4
#define BM_HDMI_CEC_WKUPCTRL_OPCODE0X44EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X44EN(v)   ((((reg32_t) v) << 4) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X44EN)
#else
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X44EN(v)   (((v) << 4) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X44EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OPCODE0X44EN field to a new value.
#define BW_HDMI_CEC_WKUPCTRL_OPCODE0X44EN(v)   BF_CS1(HDMI_CEC_WKUPCTRL, OPCODE0X44EN, v)
#endif

/* --- Register HW_HDMI_CEC_WKUPCTRL, field OPCODE0X70EN (RW)
 *
 * OPCODE 0x70 wake up enable
 */

#define BP_HDMI_CEC_WKUPCTRL_OPCODE0X70EN      5
#define BM_HDMI_CEC_WKUPCTRL_OPCODE0X70EN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X70EN(v)   ((((reg32_t) v) << 5) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X70EN)
#else
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X70EN(v)   (((v) << 5) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X70EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OPCODE0X70EN field to a new value.
#define BW_HDMI_CEC_WKUPCTRL_OPCODE0X70EN(v)   BF_CS1(HDMI_CEC_WKUPCTRL, OPCODE0X70EN, v)
#endif

/* --- Register HW_HDMI_CEC_WKUPCTRL, field OPCODE0X82EN (RW)
 *
 * OPCODE 0x82 wake up enable
 */

#define BP_HDMI_CEC_WKUPCTRL_OPCODE0X82EN      6
#define BM_HDMI_CEC_WKUPCTRL_OPCODE0X82EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X82EN(v)   ((((reg32_t) v) << 6) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X82EN)
#else
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X82EN(v)   (((v) << 6) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X82EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OPCODE0X82EN field to a new value.
#define BW_HDMI_CEC_WKUPCTRL_OPCODE0X82EN(v)   BF_CS1(HDMI_CEC_WKUPCTRL, OPCODE0X82EN, v)
#endif

/* --- Register HW_HDMI_CEC_WKUPCTRL, field OPCODE0X86EN (RW)
 *
 * OPCODE 0x86 wake up enable
 */

#define BP_HDMI_CEC_WKUPCTRL_OPCODE0X86EN      7
#define BM_HDMI_CEC_WKUPCTRL_OPCODE0X86EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X86EN(v)   ((((reg32_t) v) << 7) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X86EN)
#else
#define BF_HDMI_CEC_WKUPCTRL_OPCODE0X86EN(v)   (((v) << 7) & BM_HDMI_CEC_WKUPCTRL_OPCODE0X86EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OPCODE0X86EN field to a new value.
#define BW_HDMI_CEC_WKUPCTRL_OPCODE0X86EN(v)   BF_CS1(HDMI_CEC_WKUPCTRL, OPCODE0X86EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_SLAVE - I2CM_SLAVE (RW)
 *
 * I2C Master Registers (E-DDC) registers are responsible for the Master's coordination with the
 * Slave, by coordinating the Slave address, data identification, transaction status,
 * acknowledgement, and reset functions.   Address Offset: 0x7E00  Size: 8 bits  Value after Reset:
 * 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char SLAVEADDR : 7; //!< Slave address to be sent during read and write normal operations.
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_i2cm_slave_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_SLAVE register
 */
#define HW_HDMI_I2CM_SLAVE_ADDR      (REGS_HDMI_BASE + 0x7e00)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_SLAVE           (*(volatile hw_hdmi_i2cm_slave_t *) HW_HDMI_I2CM_SLAVE_ADDR)
#define HW_HDMI_I2CM_SLAVE_RD()      (HW_HDMI_I2CM_SLAVE.U)
#define HW_HDMI_I2CM_SLAVE_WR(v)     (HW_HDMI_I2CM_SLAVE.U = (v))
#define HW_HDMI_I2CM_SLAVE_SET(v)    (HW_HDMI_I2CM_SLAVE_WR(HW_HDMI_I2CM_SLAVE_RD() |  (v)))
#define HW_HDMI_I2CM_SLAVE_CLR(v)    (HW_HDMI_I2CM_SLAVE_WR(HW_HDMI_I2CM_SLAVE_RD() & ~(v)))
#define HW_HDMI_I2CM_SLAVE_TOG(v)    (HW_HDMI_I2CM_SLAVE_WR(HW_HDMI_I2CM_SLAVE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_SLAVE bitfields
 */

/* --- Register HW_HDMI_I2CM_SLAVE, field SLAVEADDR (RW)
 *
 * Slave address to be sent during read and write normal operations.
 */

#define BP_HDMI_I2CM_SLAVE_SLAVEADDR      0
#define BM_HDMI_I2CM_SLAVE_SLAVEADDR      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_SLAVE_SLAVEADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_SLAVE_SLAVEADDR)
#else
#define BF_HDMI_I2CM_SLAVE_SLAVEADDR(v)   (((v) << 0) & BM_HDMI_I2CM_SLAVE_SLAVEADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLAVEADDR field to a new value.
#define BW_HDMI_I2CM_SLAVE_SLAVEADDR(v)   BF_CS1(HDMI_I2CM_SLAVE, SLAVEADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_ADDRESS - I2CM_ADDRESS (RW)
 *
 * Address Offset: 0x7E01  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ADDRESS : 8; //!< Register address for read and write operations.
    } B;
} hw_hdmi_i2cm_address_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_ADDRESS register
 */
#define HW_HDMI_I2CM_ADDRESS_ADDR      (REGS_HDMI_BASE + 0x7e01)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_ADDRESS           (*(volatile hw_hdmi_i2cm_address_t *) HW_HDMI_I2CM_ADDRESS_ADDR)
#define HW_HDMI_I2CM_ADDRESS_RD()      (HW_HDMI_I2CM_ADDRESS.U)
#define HW_HDMI_I2CM_ADDRESS_WR(v)     (HW_HDMI_I2CM_ADDRESS.U = (v))
#define HW_HDMI_I2CM_ADDRESS_SET(v)    (HW_HDMI_I2CM_ADDRESS_WR(HW_HDMI_I2CM_ADDRESS_RD() |  (v)))
#define HW_HDMI_I2CM_ADDRESS_CLR(v)    (HW_HDMI_I2CM_ADDRESS_WR(HW_HDMI_I2CM_ADDRESS_RD() & ~(v)))
#define HW_HDMI_I2CM_ADDRESS_TOG(v)    (HW_HDMI_I2CM_ADDRESS_WR(HW_HDMI_I2CM_ADDRESS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_ADDRESS bitfields
 */

/* --- Register HW_HDMI_I2CM_ADDRESS, field ADDRESS (RW)
 *
 * Register address for read and write operations.
 */

#define BP_HDMI_I2CM_ADDRESS_ADDRESS      0
#define BM_HDMI_I2CM_ADDRESS_ADDRESS      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_ADDRESS_ADDRESS(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_ADDRESS_ADDRESS)
#else
#define BF_HDMI_I2CM_ADDRESS_ADDRESS(v)   (((v) << 0) & BM_HDMI_I2CM_ADDRESS_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRESS field to a new value.
#define BW_HDMI_I2CM_ADDRESS_ADDRESS(v)   BF_CS1(HDMI_I2CM_ADDRESS, ADDRESS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_DATAO - I2CM_DATAO (RW)
 *
 * Address Offset: 0x7E02  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DATAO : 8; //!< Data to be written on register pointed by address[7:0].
    } B;
} hw_hdmi_i2cm_datao_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_DATAO register
 */
#define HW_HDMI_I2CM_DATAO_ADDR      (REGS_HDMI_BASE + 0x7e02)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_DATAO           (*(volatile hw_hdmi_i2cm_datao_t *) HW_HDMI_I2CM_DATAO_ADDR)
#define HW_HDMI_I2CM_DATAO_RD()      (HW_HDMI_I2CM_DATAO.U)
#define HW_HDMI_I2CM_DATAO_WR(v)     (HW_HDMI_I2CM_DATAO.U = (v))
#define HW_HDMI_I2CM_DATAO_SET(v)    (HW_HDMI_I2CM_DATAO_WR(HW_HDMI_I2CM_DATAO_RD() |  (v)))
#define HW_HDMI_I2CM_DATAO_CLR(v)    (HW_HDMI_I2CM_DATAO_WR(HW_HDMI_I2CM_DATAO_RD() & ~(v)))
#define HW_HDMI_I2CM_DATAO_TOG(v)    (HW_HDMI_I2CM_DATAO_WR(HW_HDMI_I2CM_DATAO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_DATAO bitfields
 */

/* --- Register HW_HDMI_I2CM_DATAO, field DATAO (RW)
 *
 * Data to be written on register pointed by address[7:0].
 */

#define BP_HDMI_I2CM_DATAO_DATAO      0
#define BM_HDMI_I2CM_DATAO_DATAO      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_DATAO_DATAO(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_DATAO_DATAO)
#else
#define BF_HDMI_I2CM_DATAO_DATAO(v)   (((v) << 0) & BM_HDMI_I2CM_DATAO_DATAO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAO field to a new value.
#define BW_HDMI_I2CM_DATAO_DATAO(v)   BF_CS1(HDMI_I2CM_DATAO, DATAO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_DATAI - I2CM_DATAI (RO)
 *
 * Address Offset: 0x7E03  Size: 8 bits  Value after Reset: 0x00  Access: Read
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DATAI : 8; //!< Data read from register pointed by address[7:0].
    } B;
} hw_hdmi_i2cm_datai_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_DATAI register
 */
#define HW_HDMI_I2CM_DATAI_ADDR      (REGS_HDMI_BASE + 0x7e03)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_DATAI           (*(volatile hw_hdmi_i2cm_datai_t *) HW_HDMI_I2CM_DATAI_ADDR)
#define HW_HDMI_I2CM_DATAI_RD()      (HW_HDMI_I2CM_DATAI.U)
#endif

/*
 * constants & macros for individual HDMI_I2CM_DATAI bitfields
 */

/* --- Register HW_HDMI_I2CM_DATAI, field DATAI (RO)
 *
 * Data read from register pointed by address[7:0].
 */

#define BP_HDMI_I2CM_DATAI_DATAI      0
#define BM_HDMI_I2CM_DATAI_DATAI      0x000000ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_OPERATION - I2CM_OPERATION (WO)
 *
 * Read and write operation request. This register can only be written, reading this register will
 * always result in 00h. Writing 1'b1 simultaneously to rd, rd_ext and wr requests is considered as
 * a read (rd) request.   Address Offset: 0x7E04  Size: 8 bits  Value after Reset: 0x00  Access:
 * Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RD : 1; //!< Read operation request.
        unsigned char RD_EXT : 1; //!< After writing 1'b1 to rd_ext bit a extended data read operation is started (E- DDC read operation).
        unsigned char RESERVED0 : 2; //!< Reserved
        unsigned char WR : 1; //!< Write operation request.
        unsigned char RESERVED1 : 3; //!< Reserved
    } B;
} hw_hdmi_i2cm_operation_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_OPERATION register
 */
#define HW_HDMI_I2CM_OPERATION_ADDR      (REGS_HDMI_BASE + 0x7e04)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_OPERATION           (*(volatile hw_hdmi_i2cm_operation_t *) HW_HDMI_I2CM_OPERATION_ADDR)
#define HW_HDMI_I2CM_OPERATION_WR(v)     (HW_HDMI_I2CM_OPERATION.U = (v))
#endif

/*
 * constants & macros for individual HDMI_I2CM_OPERATION bitfields
 */

/* --- Register HW_HDMI_I2CM_OPERATION, field RD (WO)
 *
 * Read operation request.
 */

#define BP_HDMI_I2CM_OPERATION_RD      0
#define BM_HDMI_I2CM_OPERATION_RD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_OPERATION_RD(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_OPERATION_RD)
#else
#define BF_HDMI_I2CM_OPERATION_RD(v)   (((v) << 0) & BM_HDMI_I2CM_OPERATION_RD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RD field to a new value.
#define BW_HDMI_I2CM_OPERATION_RD(v)   BF_CS1(HDMI_I2CM_OPERATION, RD, v)
#endif

/* --- Register HW_HDMI_I2CM_OPERATION, field RD_EXT (WO)
 *
 * After writing 1'b1 to rd_ext bit a extended data read operation is started (E- DDC read
 * operation).
 */

#define BP_HDMI_I2CM_OPERATION_RD_EXT      1
#define BM_HDMI_I2CM_OPERATION_RD_EXT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_OPERATION_RD_EXT(v)   ((((reg32_t) v) << 1) & BM_HDMI_I2CM_OPERATION_RD_EXT)
#else
#define BF_HDMI_I2CM_OPERATION_RD_EXT(v)   (((v) << 1) & BM_HDMI_I2CM_OPERATION_RD_EXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RD_EXT field to a new value.
#define BW_HDMI_I2CM_OPERATION_RD_EXT(v)   BF_CS1(HDMI_I2CM_OPERATION, RD_EXT, v)
#endif

/* --- Register HW_HDMI_I2CM_OPERATION, field WR (WO)
 *
 * Write operation request.
 */

#define BP_HDMI_I2CM_OPERATION_WR      4
#define BM_HDMI_I2CM_OPERATION_WR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_OPERATION_WR(v)   ((((reg32_t) v) << 4) & BM_HDMI_I2CM_OPERATION_WR)
#else
#define BF_HDMI_I2CM_OPERATION_WR(v)   (((v) << 4) & BM_HDMI_I2CM_OPERATION_WR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WR field to a new value.
#define BW_HDMI_I2CM_OPERATION_WR(v)   BF_CS1(HDMI_I2CM_OPERATION, WR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_INT - I2CM_INT (RW)
 *
 * This register contains and configures I2C master done interrupt.   Address Offset: 0x7E05  Size:
 * 8 bits  Value after Reset: 0x08  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char DONE_STATUS : 1; //!< Operation done status bit. Marks the end of a rd or write operation.
        unsigned char DONE_INTERRUPT : 1; //!< Operation done interrupt bit. Only lasts for 1 SFR clock cycle and is auto cleaned after it. {done_interrupt = (done_mask==0b) && (done_status==done_pol)}.
        unsigned char DONE_MASK : 1; //!< Done interrupt mask signal.
        unsigned char DONE_POL : 1; //!< Done interrupt polarity configuration.
        unsigned char RESERVED0 : 4; //!< Reserved
    } B;
} hw_hdmi_i2cm_int_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_INT register
 */
#define HW_HDMI_I2CM_INT_ADDR      (REGS_HDMI_BASE + 0x7e05)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_INT           (*(volatile hw_hdmi_i2cm_int_t *) HW_HDMI_I2CM_INT_ADDR)
#define HW_HDMI_I2CM_INT_RD()      (HW_HDMI_I2CM_INT.U)
#define HW_HDMI_I2CM_INT_WR(v)     (HW_HDMI_I2CM_INT.U = (v))
#define HW_HDMI_I2CM_INT_SET(v)    (HW_HDMI_I2CM_INT_WR(HW_HDMI_I2CM_INT_RD() |  (v)))
#define HW_HDMI_I2CM_INT_CLR(v)    (HW_HDMI_I2CM_INT_WR(HW_HDMI_I2CM_INT_RD() & ~(v)))
#define HW_HDMI_I2CM_INT_TOG(v)    (HW_HDMI_I2CM_INT_WR(HW_HDMI_I2CM_INT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_INT bitfields
 */

/* --- Register HW_HDMI_I2CM_INT, field DONE_STATUS (RW)
 *
 * Operation done status bit. Marks the end of a rd or write operation.
 */

#define BP_HDMI_I2CM_INT_DONE_STATUS      0
#define BM_HDMI_I2CM_INT_DONE_STATUS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_INT_DONE_STATUS(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_INT_DONE_STATUS)
#else
#define BF_HDMI_I2CM_INT_DONE_STATUS(v)   (((v) << 0) & BM_HDMI_I2CM_INT_DONE_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_STATUS field to a new value.
#define BW_HDMI_I2CM_INT_DONE_STATUS(v)   BF_CS1(HDMI_I2CM_INT, DONE_STATUS, v)
#endif

/* --- Register HW_HDMI_I2CM_INT, field DONE_INTERRUPT (RW)
 *
 * Operation done interrupt bit. Only lasts for 1 SFR clock cycle and is auto cleaned after it.
 * {done_interrupt = (done_mask==0b) && (done_status==done_pol)}.
 */

#define BP_HDMI_I2CM_INT_DONE_INTERRUPT      1
#define BM_HDMI_I2CM_INT_DONE_INTERRUPT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_INT_DONE_INTERRUPT(v)   ((((reg32_t) v) << 1) & BM_HDMI_I2CM_INT_DONE_INTERRUPT)
#else
#define BF_HDMI_I2CM_INT_DONE_INTERRUPT(v)   (((v) << 1) & BM_HDMI_I2CM_INT_DONE_INTERRUPT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_INTERRUPT field to a new value.
#define BW_HDMI_I2CM_INT_DONE_INTERRUPT(v)   BF_CS1(HDMI_I2CM_INT, DONE_INTERRUPT, v)
#endif

/* --- Register HW_HDMI_I2CM_INT, field DONE_MASK (RW)
 *
 * Done interrupt mask signal.
 */

#define BP_HDMI_I2CM_INT_DONE_MASK      2
#define BM_HDMI_I2CM_INT_DONE_MASK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_INT_DONE_MASK(v)   ((((reg32_t) v) << 2) & BM_HDMI_I2CM_INT_DONE_MASK)
#else
#define BF_HDMI_I2CM_INT_DONE_MASK(v)   (((v) << 2) & BM_HDMI_I2CM_INT_DONE_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_MASK field to a new value.
#define BW_HDMI_I2CM_INT_DONE_MASK(v)   BF_CS1(HDMI_I2CM_INT, DONE_MASK, v)
#endif

/* --- Register HW_HDMI_I2CM_INT, field DONE_POL (RW)
 *
 * Done interrupt polarity configuration.
 */

#define BP_HDMI_I2CM_INT_DONE_POL      3
#define BM_HDMI_I2CM_INT_DONE_POL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_INT_DONE_POL(v)   ((((reg32_t) v) << 3) & BM_HDMI_I2CM_INT_DONE_POL)
#else
#define BF_HDMI_I2CM_INT_DONE_POL(v)   (((v) << 3) & BM_HDMI_I2CM_INT_DONE_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DONE_POL field to a new value.
#define BW_HDMI_I2CM_INT_DONE_POL(v)   BF_CS1(HDMI_I2CM_INT, DONE_POL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_CTLINT - I2CM_CTLINT (RW)
 *
 * This register contains and configures I2C master arbitration error and not acknowledge error
 * interrupt.   Address Offset: 0x7E06  Size: 8 bits  Value after Reset: 0x88  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char ARBITRATION_STATUS : 1; //!< Arbitration error status bit. Error on master I2C protocol arbitration.
        unsigned char ARBITRATION_INTERRUPT : 1; //!< Arbitration error interrupt bit. Only lasts for 1 SFR clock cycle and is auto cleaned after it. {arbitration_interrupt = (arbitration_mask==0b) && (arbitration_status==arbitration_pol)}.
        unsigned char ARBITRATION_MASK : 1; //!< Arbitration error interrupt mask signal.
        unsigned char ARBITRATION_POL : 1; //!< Arbitration error interrupt polarity configuration.
        unsigned char NACK_STATUS : 1; //!< Not acknowledge error status bit. Error on I2C not acknowledge.
        unsigned char NACK_INTERRUPT : 1; //!< Not acknowledge error interrupt bit. Only lasts for 1 SFR clock cycle and is auto cleaned after it. {nack_interrupt = (nack_mask==0b) && (nack_status==nack_pol)}.
        unsigned char NACK_MASK : 1; //!< Not acknowledge error interrupt mask signal.
        unsigned char NACK_POL : 1; //!< Not acknowledge error interrupt polarity configuration.
    } B;
} hw_hdmi_i2cm_ctlint_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_CTLINT register
 */
#define HW_HDMI_I2CM_CTLINT_ADDR      (REGS_HDMI_BASE + 0x7e06)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_CTLINT           (*(volatile hw_hdmi_i2cm_ctlint_t *) HW_HDMI_I2CM_CTLINT_ADDR)
#define HW_HDMI_I2CM_CTLINT_RD()      (HW_HDMI_I2CM_CTLINT.U)
#define HW_HDMI_I2CM_CTLINT_WR(v)     (HW_HDMI_I2CM_CTLINT.U = (v))
#define HW_HDMI_I2CM_CTLINT_SET(v)    (HW_HDMI_I2CM_CTLINT_WR(HW_HDMI_I2CM_CTLINT_RD() |  (v)))
#define HW_HDMI_I2CM_CTLINT_CLR(v)    (HW_HDMI_I2CM_CTLINT_WR(HW_HDMI_I2CM_CTLINT_RD() & ~(v)))
#define HW_HDMI_I2CM_CTLINT_TOG(v)    (HW_HDMI_I2CM_CTLINT_WR(HW_HDMI_I2CM_CTLINT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_CTLINT bitfields
 */

/* --- Register HW_HDMI_I2CM_CTLINT, field ARBITRATION_STATUS (RW)
 *
 * Arbitration error status bit. Error on master I2C protocol arbitration.
 */

#define BP_HDMI_I2CM_CTLINT_ARBITRATION_STATUS      0
#define BM_HDMI_I2CM_CTLINT_ARBITRATION_STATUS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_CTLINT_ARBITRATION_STATUS(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_CTLINT_ARBITRATION_STATUS)
#else
#define BF_HDMI_I2CM_CTLINT_ARBITRATION_STATUS(v)   (((v) << 0) & BM_HDMI_I2CM_CTLINT_ARBITRATION_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_STATUS field to a new value.
#define BW_HDMI_I2CM_CTLINT_ARBITRATION_STATUS(v)   BF_CS1(HDMI_I2CM_CTLINT, ARBITRATION_STATUS, v)
#endif

/* --- Register HW_HDMI_I2CM_CTLINT, field ARBITRATION_INTERRUPT (RW)
 *
 * Arbitration error interrupt bit. Only lasts for 1 SFR clock cycle and is auto cleaned after it.
 * {arbitration_interrupt = (arbitration_mask==0b) && (arbitration_status==arbitration_pol)}.
 */

#define BP_HDMI_I2CM_CTLINT_ARBITRATION_INTERRUPT      1
#define BM_HDMI_I2CM_CTLINT_ARBITRATION_INTERRUPT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_CTLINT_ARBITRATION_INTERRUPT(v)   ((((reg32_t) v) << 1) & BM_HDMI_I2CM_CTLINT_ARBITRATION_INTERRUPT)
#else
#define BF_HDMI_I2CM_CTLINT_ARBITRATION_INTERRUPT(v)   (((v) << 1) & BM_HDMI_I2CM_CTLINT_ARBITRATION_INTERRUPT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_INTERRUPT field to a new value.
#define BW_HDMI_I2CM_CTLINT_ARBITRATION_INTERRUPT(v)   BF_CS1(HDMI_I2CM_CTLINT, ARBITRATION_INTERRUPT, v)
#endif

/* --- Register HW_HDMI_I2CM_CTLINT, field ARBITRATION_MASK (RW)
 *
 * Arbitration error interrupt mask signal.
 */

#define BP_HDMI_I2CM_CTLINT_ARBITRATION_MASK      2
#define BM_HDMI_I2CM_CTLINT_ARBITRATION_MASK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_CTLINT_ARBITRATION_MASK(v)   ((((reg32_t) v) << 2) & BM_HDMI_I2CM_CTLINT_ARBITRATION_MASK)
#else
#define BF_HDMI_I2CM_CTLINT_ARBITRATION_MASK(v)   (((v) << 2) & BM_HDMI_I2CM_CTLINT_ARBITRATION_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_MASK field to a new value.
#define BW_HDMI_I2CM_CTLINT_ARBITRATION_MASK(v)   BF_CS1(HDMI_I2CM_CTLINT, ARBITRATION_MASK, v)
#endif

/* --- Register HW_HDMI_I2CM_CTLINT, field ARBITRATION_POL (RW)
 *
 * Arbitration error interrupt polarity configuration.
 */

#define BP_HDMI_I2CM_CTLINT_ARBITRATION_POL      3
#define BM_HDMI_I2CM_CTLINT_ARBITRATION_POL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_CTLINT_ARBITRATION_POL(v)   ((((reg32_t) v) << 3) & BM_HDMI_I2CM_CTLINT_ARBITRATION_POL)
#else
#define BF_HDMI_I2CM_CTLINT_ARBITRATION_POL(v)   (((v) << 3) & BM_HDMI_I2CM_CTLINT_ARBITRATION_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_POL field to a new value.
#define BW_HDMI_I2CM_CTLINT_ARBITRATION_POL(v)   BF_CS1(HDMI_I2CM_CTLINT, ARBITRATION_POL, v)
#endif

/* --- Register HW_HDMI_I2CM_CTLINT, field NACK_STATUS (RW)
 *
 * Not acknowledge error status bit. Error on I2C not acknowledge.
 */

#define BP_HDMI_I2CM_CTLINT_NACK_STATUS      4
#define BM_HDMI_I2CM_CTLINT_NACK_STATUS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_CTLINT_NACK_STATUS(v)   ((((reg32_t) v) << 4) & BM_HDMI_I2CM_CTLINT_NACK_STATUS)
#else
#define BF_HDMI_I2CM_CTLINT_NACK_STATUS(v)   (((v) << 4) & BM_HDMI_I2CM_CTLINT_NACK_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_STATUS field to a new value.
#define BW_HDMI_I2CM_CTLINT_NACK_STATUS(v)   BF_CS1(HDMI_I2CM_CTLINT, NACK_STATUS, v)
#endif

/* --- Register HW_HDMI_I2CM_CTLINT, field NACK_INTERRUPT (RW)
 *
 * Not acknowledge error interrupt bit. Only lasts for 1 SFR clock cycle and is auto cleaned after
 * it. {nack_interrupt = (nack_mask==0b) && (nack_status==nack_pol)}.
 */

#define BP_HDMI_I2CM_CTLINT_NACK_INTERRUPT      5
#define BM_HDMI_I2CM_CTLINT_NACK_INTERRUPT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_CTLINT_NACK_INTERRUPT(v)   ((((reg32_t) v) << 5) & BM_HDMI_I2CM_CTLINT_NACK_INTERRUPT)
#else
#define BF_HDMI_I2CM_CTLINT_NACK_INTERRUPT(v)   (((v) << 5) & BM_HDMI_I2CM_CTLINT_NACK_INTERRUPT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_INTERRUPT field to a new value.
#define BW_HDMI_I2CM_CTLINT_NACK_INTERRUPT(v)   BF_CS1(HDMI_I2CM_CTLINT, NACK_INTERRUPT, v)
#endif

/* --- Register HW_HDMI_I2CM_CTLINT, field NACK_MASK (RW)
 *
 * Not acknowledge error interrupt mask signal.
 */

#define BP_HDMI_I2CM_CTLINT_NACK_MASK      6
#define BM_HDMI_I2CM_CTLINT_NACK_MASK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_CTLINT_NACK_MASK(v)   ((((reg32_t) v) << 6) & BM_HDMI_I2CM_CTLINT_NACK_MASK)
#else
#define BF_HDMI_I2CM_CTLINT_NACK_MASK(v)   (((v) << 6) & BM_HDMI_I2CM_CTLINT_NACK_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_MASK field to a new value.
#define BW_HDMI_I2CM_CTLINT_NACK_MASK(v)   BF_CS1(HDMI_I2CM_CTLINT, NACK_MASK, v)
#endif

/* --- Register HW_HDMI_I2CM_CTLINT, field NACK_POL (RW)
 *
 * Not acknowledge error interrupt polarity configuration.
 */

#define BP_HDMI_I2CM_CTLINT_NACK_POL      7
#define BM_HDMI_I2CM_CTLINT_NACK_POL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_CTLINT_NACK_POL(v)   ((((reg32_t) v) << 7) & BM_HDMI_I2CM_CTLINT_NACK_POL)
#else
#define BF_HDMI_I2CM_CTLINT_NACK_POL(v)   (((v) << 7) & BM_HDMI_I2CM_CTLINT_NACK_POL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NACK_POL field to a new value.
#define BW_HDMI_I2CM_CTLINT_NACK_POL(v)   BF_CS1(HDMI_I2CM_CTLINT, NACK_POL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_DIV - I2CM_DIV (RW)
 *
 * This register configures the division relation between master and scl clock.   Address Offset:
 * 0x7E07  Size: 8 bits  Value after Reset: 0x0B  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char RESERVED0 : 3; //!< Reserved
        unsigned char FAST_STD_MODE : 1; //!< Sets the I2C Master to work in Fast Mode or Standard Mode:
        unsigned char RESERVED1 : 4; //!< Reserved
    } B;
} hw_hdmi_i2cm_div_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_DIV register
 */
#define HW_HDMI_I2CM_DIV_ADDR      (REGS_HDMI_BASE + 0x7e07)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_DIV           (*(volatile hw_hdmi_i2cm_div_t *) HW_HDMI_I2CM_DIV_ADDR)
#define HW_HDMI_I2CM_DIV_RD()      (HW_HDMI_I2CM_DIV.U)
#define HW_HDMI_I2CM_DIV_WR(v)     (HW_HDMI_I2CM_DIV.U = (v))
#define HW_HDMI_I2CM_DIV_SET(v)    (HW_HDMI_I2CM_DIV_WR(HW_HDMI_I2CM_DIV_RD() |  (v)))
#define HW_HDMI_I2CM_DIV_CLR(v)    (HW_HDMI_I2CM_DIV_WR(HW_HDMI_I2CM_DIV_RD() & ~(v)))
#define HW_HDMI_I2CM_DIV_TOG(v)    (HW_HDMI_I2CM_DIV_WR(HW_HDMI_I2CM_DIV_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_DIV bitfields
 */

/* --- Register HW_HDMI_I2CM_DIV, field FAST_STD_MODE (RW)
 *
 * Sets the I2C Master to work in Fast Mode or Standard Mode:
 *
 * Values:
 * 1 - Fast Mode
 * 0 - Standard Mode
 */

#define BP_HDMI_I2CM_DIV_FAST_STD_MODE      3
#define BM_HDMI_I2CM_DIV_FAST_STD_MODE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_DIV_FAST_STD_MODE(v)   ((((reg32_t) v) << 3) & BM_HDMI_I2CM_DIV_FAST_STD_MODE)
#else
#define BF_HDMI_I2CM_DIV_FAST_STD_MODE(v)   (((v) << 3) & BM_HDMI_I2CM_DIV_FAST_STD_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FAST_STD_MODE field to a new value.
#define BW_HDMI_I2CM_DIV_FAST_STD_MODE(v)   BF_CS1(HDMI_I2CM_DIV, FAST_STD_MODE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_SEGADDR - I2CM_SEGADDR (RW)
 *
 * This register configures the segment address for extended RD/WR destination.   Address Offset:
 * 0x7E08  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char SEGADDR : 7; //!< E-DDC Extended read segment address
        unsigned char RESERVED0 : 1; //!< Reserved
    } B;
} hw_hdmi_i2cm_segaddr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_SEGADDR register
 */
#define HW_HDMI_I2CM_SEGADDR_ADDR      (REGS_HDMI_BASE + 0x7e08)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_SEGADDR           (*(volatile hw_hdmi_i2cm_segaddr_t *) HW_HDMI_I2CM_SEGADDR_ADDR)
#define HW_HDMI_I2CM_SEGADDR_RD()      (HW_HDMI_I2CM_SEGADDR.U)
#define HW_HDMI_I2CM_SEGADDR_WR(v)     (HW_HDMI_I2CM_SEGADDR.U = (v))
#define HW_HDMI_I2CM_SEGADDR_SET(v)    (HW_HDMI_I2CM_SEGADDR_WR(HW_HDMI_I2CM_SEGADDR_RD() |  (v)))
#define HW_HDMI_I2CM_SEGADDR_CLR(v)    (HW_HDMI_I2CM_SEGADDR_WR(HW_HDMI_I2CM_SEGADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_SEGADDR_TOG(v)    (HW_HDMI_I2CM_SEGADDR_WR(HW_HDMI_I2CM_SEGADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_SEGADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_SEGADDR, field SEGADDR (RW)
 *
 * E-DDC Extended read segment address
 */

#define BP_HDMI_I2CM_SEGADDR_SEGADDR      0
#define BM_HDMI_I2CM_SEGADDR_SEGADDR      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_SEGADDR_SEGADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_SEGADDR_SEGADDR)
#else
#define BF_HDMI_I2CM_SEGADDR_SEGADDR(v)   (((v) << 0) & BM_HDMI_I2CM_SEGADDR_SEGADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEGADDR field to a new value.
#define BW_HDMI_I2CM_SEGADDR_SEGADDR(v)   BF_CS1(HDMI_I2CM_SEGADDR, SEGADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_SOFTRSTZ - I2CM_SOFTRSTZ (RW)
 *
 * This register resets the I2C master.   Address Offset: 0x7E09  Size: 8 bits  Value after Reset:
 * 0x01  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2C_SOFTRST : 1; //!< I2C Master Software Reset. Active by writing a zero and auto cleared to one in the following cycle. Value after Reset: 1b
        unsigned char RESERVED0 : 7; //!< Reserved
    } B;
} hw_hdmi_i2cm_softrstz_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_SOFTRSTZ register
 */
#define HW_HDMI_I2CM_SOFTRSTZ_ADDR      (REGS_HDMI_BASE + 0x7e09)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_SOFTRSTZ           (*(volatile hw_hdmi_i2cm_softrstz_t *) HW_HDMI_I2CM_SOFTRSTZ_ADDR)
#define HW_HDMI_I2CM_SOFTRSTZ_RD()      (HW_HDMI_I2CM_SOFTRSTZ.U)
#define HW_HDMI_I2CM_SOFTRSTZ_WR(v)     (HW_HDMI_I2CM_SOFTRSTZ.U = (v))
#define HW_HDMI_I2CM_SOFTRSTZ_SET(v)    (HW_HDMI_I2CM_SOFTRSTZ_WR(HW_HDMI_I2CM_SOFTRSTZ_RD() |  (v)))
#define HW_HDMI_I2CM_SOFTRSTZ_CLR(v)    (HW_HDMI_I2CM_SOFTRSTZ_WR(HW_HDMI_I2CM_SOFTRSTZ_RD() & ~(v)))
#define HW_HDMI_I2CM_SOFTRSTZ_TOG(v)    (HW_HDMI_I2CM_SOFTRSTZ_WR(HW_HDMI_I2CM_SOFTRSTZ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_SOFTRSTZ bitfields
 */

/* --- Register HW_HDMI_I2CM_SOFTRSTZ, field I2C_SOFTRST (RW)
 *
 * I2C Master Software Reset. Active by writing a zero and auto cleared to one in the following
 * cycle. Value after Reset: 1b
 */

#define BP_HDMI_I2CM_SOFTRSTZ_I2C_SOFTRST      0
#define BM_HDMI_I2CM_SOFTRSTZ_I2C_SOFTRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_SOFTRSTZ_I2C_SOFTRST(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_SOFTRSTZ_I2C_SOFTRST)
#else
#define BF_HDMI_I2CM_SOFTRSTZ_I2C_SOFTRST(v)   (((v) << 0) & BM_HDMI_I2CM_SOFTRSTZ_I2C_SOFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2C_SOFTRST field to a new value.
#define BW_HDMI_I2CM_SOFTRSTZ_I2C_SOFTRST(v)   BF_CS1(HDMI_I2CM_SOFTRSTZ, I2C_SOFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_SEGPTR - I2CM_SEGPTR (RW)
 *
 * This register configures the segment pointer for extended RD/WR request.   Address Offset: 0x7E0A
 * Size: 8 bits  Value after Reset: 0x00  Access: Read/Write   The following *CNT registers must be
 * set before any I2C bus transaction can take place to ensure proper I/O timing. For more
 * information about the SFR_CLK frequency configuration, see ."
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CM_SEGPTR : 8; //!< I2CM_SEGPTR is used for EDID reading operations, particularly for the Extended Data Read Operation (See ") which is used for Enhanced DDC. This is all described in the VESA Enhanced Display Data Channel Standard v1.1 spec. (addresses A0h/A1h pairs and a segment pointer - 60h).
    } B;
} hw_hdmi_i2cm_segptr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_SEGPTR register
 */
#define HW_HDMI_I2CM_SEGPTR_ADDR      (REGS_HDMI_BASE + 0x7e0a)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_SEGPTR           (*(volatile hw_hdmi_i2cm_segptr_t *) HW_HDMI_I2CM_SEGPTR_ADDR)
#define HW_HDMI_I2CM_SEGPTR_RD()      (HW_HDMI_I2CM_SEGPTR.U)
#define HW_HDMI_I2CM_SEGPTR_WR(v)     (HW_HDMI_I2CM_SEGPTR.U = (v))
#define HW_HDMI_I2CM_SEGPTR_SET(v)    (HW_HDMI_I2CM_SEGPTR_WR(HW_HDMI_I2CM_SEGPTR_RD() |  (v)))
#define HW_HDMI_I2CM_SEGPTR_CLR(v)    (HW_HDMI_I2CM_SEGPTR_WR(HW_HDMI_I2CM_SEGPTR_RD() & ~(v)))
#define HW_HDMI_I2CM_SEGPTR_TOG(v)    (HW_HDMI_I2CM_SEGPTR_WR(HW_HDMI_I2CM_SEGPTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_SEGPTR bitfields
 */

/* --- Register HW_HDMI_I2CM_SEGPTR, field I2CM_SEGPTR (RW)
 *
 * I2CM_SEGPTR is used for EDID reading operations, particularly for the Extended Data Read
 * Operation (See ") which is used for Enhanced DDC. This is all described in the VESA Enhanced
 * Display Data Channel Standard v1.1 spec. (addresses A0h/A1h pairs and a segment pointer - 60h).
 */

#define BP_HDMI_I2CM_SEGPTR_I2CM_SEGPTR      0
#define BM_HDMI_I2CM_SEGPTR_I2CM_SEGPTR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_SEGPTR_I2CM_SEGPTR(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_SEGPTR_I2CM_SEGPTR)
#else
#define BF_HDMI_I2CM_SEGPTR_I2CM_SEGPTR(v)   (((v) << 0) & BM_HDMI_I2CM_SEGPTR_I2CM_SEGPTR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CM_SEGPTR field to a new value.
#define BW_HDMI_I2CM_SEGPTR_I2CM_SEGPTR(v)   BF_CS1(HDMI_I2CM_SEGPTR, I2CM_SEGPTR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR - I2CM_SS_SCL_HCNT_1_ADDR (RW)
 *
 * Address Offset: 0x7E0B  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_SS_SCL_HCNT : 8; //!< Value after Reset: 8'h00
    } B;
} hw_hdmi_i2cm_ss_scl_hcnt_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_SS_SCL_HCNT_1_ADDR register
 */
#define HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x7e0b)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR           (*(volatile hw_hdmi_i2cm_ss_scl_hcnt_1_addr_t *) HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_ADDR)
#define HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_RD()      (HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR.U)
#define HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_WR(v)     (HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR.U = (v))
#define HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_SET(v)    (HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_WR(HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_RD() |  (v)))
#define HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_CLR(v)    (HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_WR(HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_TOG(v)    (HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_WR(HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_SS_SCL_HCNT_1_ADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR, field I2CMP_SS_SCL_HCNT (RW)
 *
 * Value after Reset: 8'h00
 */

#define BP_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT      0
#define BM_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT)
#else
#define BF_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT(v)   (((v) << 0) & BM_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_SS_SCL_HCNT field to a new value.
#define BW_HDMI_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT(v)   BF_CS1(HDMI_I2CM_SS_SCL_HCNT_1_ADDR, I2CMP_SS_SCL_HCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR - I2CM_SS_SCL_HCNT_0_ADDR (RW)
 *
 * Address Offset: 0x7E0C  Size: 8 bits  Value after Reset: 0x6C  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_SS_SCL_HCNT : 8; //!< Value after Reset: 8'h6C
    } B;
} hw_hdmi_i2cm_ss_scl_hcnt_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_SS_SCL_HCNT_0_ADDR register
 */
#define HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x7e0c)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR           (*(volatile hw_hdmi_i2cm_ss_scl_hcnt_0_addr_t *) HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_ADDR)
#define HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_RD()      (HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR.U)
#define HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_WR(v)     (HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR.U = (v))
#define HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_SET(v)    (HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_WR(HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_RD() |  (v)))
#define HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_CLR(v)    (HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_WR(HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_TOG(v)    (HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_WR(HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_SS_SCL_HCNT_0_ADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR, field I2CMP_SS_SCL_HCNT (RW)
 *
 * Value after Reset: 8'h6C
 */

#define BP_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT      0
#define BM_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT)
#else
#define BF_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT(v)   (((v) << 0) & BM_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_SS_SCL_HCNT field to a new value.
#define BW_HDMI_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT(v)   BF_CS1(HDMI_I2CM_SS_SCL_HCNT_0_ADDR, I2CMP_SS_SCL_HCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR - I2CM_SS_SCL_LCNT_1_ADDR (RW)
 *
 * Address Offset: 0x7E0D  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_SS_SCL_LCNT : 8; //!< Value after Reset: 8'h00
    } B;
} hw_hdmi_i2cm_ss_scl_lcnt_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_SS_SCL_LCNT_1_ADDR register
 */
#define HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x7e0d)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR           (*(volatile hw_hdmi_i2cm_ss_scl_lcnt_1_addr_t *) HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_ADDR)
#define HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_RD()      (HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR.U)
#define HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_WR(v)     (HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR.U = (v))
#define HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_SET(v)    (HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_WR(HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_RD() |  (v)))
#define HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_CLR(v)    (HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_WR(HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_TOG(v)    (HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_WR(HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_SS_SCL_LCNT_1_ADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR, field I2CMP_SS_SCL_LCNT (RW)
 *
 * Value after Reset: 8'h00
 */

#define BP_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT      0
#define BM_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT)
#else
#define BF_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT(v)   (((v) << 0) & BM_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_SS_SCL_LCNT field to a new value.
#define BW_HDMI_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT(v)   BF_CS1(HDMI_I2CM_SS_SCL_LCNT_1_ADDR, I2CMP_SS_SCL_LCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR - I2CM_SS_SCL_LCNT_0_ADDR (RW)
 *
 * Address Offset: 0x7E0E  Size: 8 bits  Value after Reset: 0x7F  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_SS_SCL_LCNT : 8; //!< Value after Reset: 8'h7F
    } B;
} hw_hdmi_i2cm_ss_scl_lcnt_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_SS_SCL_LCNT_0_ADDR register
 */
#define HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x7e0e)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR           (*(volatile hw_hdmi_i2cm_ss_scl_lcnt_0_addr_t *) HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_ADDR)
#define HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_RD()      (HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR.U)
#define HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_WR(v)     (HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR.U = (v))
#define HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_SET(v)    (HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_WR(HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_RD() |  (v)))
#define HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_CLR(v)    (HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_WR(HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_TOG(v)    (HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_WR(HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_SS_SCL_LCNT_0_ADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR, field I2CMP_SS_SCL_LCNT (RW)
 *
 * Value after Reset: 8'h7F
 */

#define BP_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT      0
#define BM_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT)
#else
#define BF_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT(v)   (((v) << 0) & BM_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_SS_SCL_LCNT field to a new value.
#define BW_HDMI_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT(v)   BF_CS1(HDMI_I2CM_SS_SCL_LCNT_0_ADDR, I2CMP_SS_SCL_LCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR - I2CM_FS_SCL_HCNT_1_ADDR (RW)
 *
 * Address Offset: 0x7E0F  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_FS_SCL_HCNT : 8; //!< Value after Reset: 8'h00
    } B;
} hw_hdmi_i2cm_fs_scl_hcnt_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_FS_SCL_HCNT_1_ADDR register
 */
#define HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x7e0f)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR           (*(volatile hw_hdmi_i2cm_fs_scl_hcnt_1_addr_t *) HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_ADDR)
#define HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_RD()      (HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR.U)
#define HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_WR(v)     (HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR.U = (v))
#define HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_SET(v)    (HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_WR(HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_RD() |  (v)))
#define HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_CLR(v)    (HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_WR(HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_TOG(v)    (HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_WR(HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_FS_SCL_HCNT_1_ADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR, field I2CMP_FS_SCL_HCNT (RW)
 *
 * Value after Reset: 8'h00
 */

#define BP_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT      0
#define BM_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT)
#else
#define BF_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT(v)   (((v) << 0) & BM_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_FS_SCL_HCNT field to a new value.
#define BW_HDMI_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT(v)   BF_CS1(HDMI_I2CM_FS_SCL_HCNT_1_ADDR, I2CMP_FS_SCL_HCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR - I2CM_FS_SCL_HCNT_0_ADDR (RW)
 *
 * Address Offset: 0x7E10  Size: 8 bits  Value after Reset: 0x11  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_FS_SCL_HCNT : 8; //!< Value after Reset: 8'h11
    } B;
} hw_hdmi_i2cm_fs_scl_hcnt_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_FS_SCL_HCNT_0_ADDR register
 */
#define HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x7e10)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR           (*(volatile hw_hdmi_i2cm_fs_scl_hcnt_0_addr_t *) HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_ADDR)
#define HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_RD()      (HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR.U)
#define HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_WR(v)     (HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR.U = (v))
#define HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_SET(v)    (HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_WR(HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_RD() |  (v)))
#define HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_CLR(v)    (HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_WR(HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_TOG(v)    (HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_WR(HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_FS_SCL_HCNT_0_ADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR, field I2CMP_FS_SCL_HCNT (RW)
 *
 * Value after Reset: 8'h11
 */

#define BP_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT      0
#define BM_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT)
#else
#define BF_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT(v)   (((v) << 0) & BM_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_FS_SCL_HCNT field to a new value.
#define BW_HDMI_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT(v)   BF_CS1(HDMI_I2CM_FS_SCL_HCNT_0_ADDR, I2CMP_FS_SCL_HCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR - I2CM_FS_SCL_LCNT_1_ADDR (RW)
 *
 * Address Offset: 0x7E11  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_FS_SCL_LCNT : 8; //!< Value after Reset: 8'h00
    } B;
} hw_hdmi_i2cm_fs_scl_lcnt_1_addr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_FS_SCL_LCNT_1_ADDR register
 */
#define HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_ADDR      (REGS_HDMI_BASE + 0x7e11)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR           (*(volatile hw_hdmi_i2cm_fs_scl_lcnt_1_addr_t *) HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_ADDR)
#define HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_RD()      (HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR.U)
#define HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_WR(v)     (HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR.U = (v))
#define HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_SET(v)    (HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_WR(HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_RD() |  (v)))
#define HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_CLR(v)    (HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_WR(HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_TOG(v)    (HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_WR(HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_FS_SCL_LCNT_1_ADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR, field I2CMP_FS_SCL_LCNT (RW)
 *
 * Value after Reset: 8'h00
 */

#define BP_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT      0
#define BM_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT)
#else
#define BF_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT(v)   (((v) << 0) & BM_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_FS_SCL_LCNT field to a new value.
#define BW_HDMI_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT(v)   BF_CS1(HDMI_I2CM_FS_SCL_LCNT_1_ADDR, I2CMP_FS_SCL_LCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR - I2CM_FS_SCL_LCNT_0_ADDR (RW)
 *
 * Address Offset: 0x7E12  Size: 8 bits  Value after Reset: 0x24  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char I2CMP_FS_SCL_LCNT : 8; //!< Value after Reset: 8'h24
    } B;
} hw_hdmi_i2cm_fs_scl_lcnt_0_addr_t;
#endif

/*
 * constants & macros for entire HDMI_I2CM_FS_SCL_LCNT_0_ADDR register
 */
#define HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_ADDR      (REGS_HDMI_BASE + 0x7e12)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR           (*(volatile hw_hdmi_i2cm_fs_scl_lcnt_0_addr_t *) HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_ADDR)
#define HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_RD()      (HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR.U)
#define HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_WR(v)     (HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR.U = (v))
#define HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_SET(v)    (HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_WR(HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_RD() |  (v)))
#define HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_CLR(v)    (HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_WR(HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_RD() & ~(v)))
#define HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_TOG(v)    (HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_WR(HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_I2CM_FS_SCL_LCNT_0_ADDR bitfields
 */

/* --- Register HW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR, field I2CMP_FS_SCL_LCNT (RW)
 *
 * Value after Reset: 8'h24
 */

#define BP_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT      0
#define BM_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT(v)   ((((reg32_t) v) << 0) & BM_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT)
#else
#define BF_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT(v)   (((v) << 0) & BM_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the I2CMP_FS_SCL_LCNT field to a new value.
#define BW_HDMI_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT(v)   BF_CS1(HDMI_I2CM_FS_SCL_LCNT_0_ADDR, I2CMP_FS_SCL_LCNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_HDMI_BASE_POINTER_ADDR - BASE_POINTER_ADDR (RW)
 *
 * The I2C Slave Registers allow register memory pagination, and function in the incremental burst
 * operation mode that increases the data throughput when consecutive addressed registers need to be
 * read or write.  The I2C base pointer operation mode is a aimed to allow register memory
 * pagination. As long as this operational mode is enabled the value written to this register will
 * be used as the seven most significant bits of the internal Special Function Register address
 * interface (sfraddr[14:8]) for all read or write operations. I2C data transfer protocol used shall
 * be the 7-bit addressed as defined in the section 9 of the I2C-bus Specification, version 2.1.
 * Address Offset: 0x7F00  Size: 8 bits  Value after Reset: 0x00  Access: Read/Write
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char BASE_POINTER_BASE_ADDR : 7; //!< Defines the base address for base pointer operation mode. They represent the address bits [14:8]
        unsigned char EN_BASE_POINTER_ADDR : 1; //!< Enables the base pointer operation mode.
    } B;
} hw_hdmi_base_pointer_addr_t;
#endif

/*
 * constants & macros for entire HDMI_BASE_POINTER_ADDR register
 */
#define HW_HDMI_BASE_POINTER_ADDR_ADDR      (REGS_HDMI_BASE + 0x7f00)

#ifndef __LANGUAGE_ASM__
#define HW_HDMI_BASE_POINTER_ADDR           (*(volatile hw_hdmi_base_pointer_addr_t *) HW_HDMI_BASE_POINTER_ADDR_ADDR)
#define HW_HDMI_BASE_POINTER_ADDR_RD()      (HW_HDMI_BASE_POINTER_ADDR.U)
#define HW_HDMI_BASE_POINTER_ADDR_WR(v)     (HW_HDMI_BASE_POINTER_ADDR.U = (v))
#define HW_HDMI_BASE_POINTER_ADDR_SET(v)    (HW_HDMI_BASE_POINTER_ADDR_WR(HW_HDMI_BASE_POINTER_ADDR_RD() |  (v)))
#define HW_HDMI_BASE_POINTER_ADDR_CLR(v)    (HW_HDMI_BASE_POINTER_ADDR_WR(HW_HDMI_BASE_POINTER_ADDR_RD() & ~(v)))
#define HW_HDMI_BASE_POINTER_ADDR_TOG(v)    (HW_HDMI_BASE_POINTER_ADDR_WR(HW_HDMI_BASE_POINTER_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual HDMI_BASE_POINTER_ADDR bitfields
 */

/* --- Register HW_HDMI_BASE_POINTER_ADDR, field BASE_POINTER_BASE_ADDR (RW)
 *
 * Defines the base address for base pointer operation mode. They represent the address bits [14:8]
 */

#define BP_HDMI_BASE_POINTER_ADDR_BASE_POINTER_BASE_ADDR      0
#define BM_HDMI_BASE_POINTER_ADDR_BASE_POINTER_BASE_ADDR      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_BASE_POINTER_ADDR_BASE_POINTER_BASE_ADDR(v)   ((((reg32_t) v) << 0) & BM_HDMI_BASE_POINTER_ADDR_BASE_POINTER_BASE_ADDR)
#else
#define BF_HDMI_BASE_POINTER_ADDR_BASE_POINTER_BASE_ADDR(v)   (((v) << 0) & BM_HDMI_BASE_POINTER_ADDR_BASE_POINTER_BASE_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BASE_POINTER_BASE_ADDR field to a new value.
#define BW_HDMI_BASE_POINTER_ADDR_BASE_POINTER_BASE_ADDR(v)   BF_CS1(HDMI_BASE_POINTER_ADDR, BASE_POINTER_BASE_ADDR, v)
#endif

/* --- Register HW_HDMI_BASE_POINTER_ADDR, field EN_BASE_POINTER_ADDR (RW)
 *
 * Enables the base pointer operation mode.
 */

#define BP_HDMI_BASE_POINTER_ADDR_EN_BASE_POINTER_ADDR      7
#define BM_HDMI_BASE_POINTER_ADDR_EN_BASE_POINTER_ADDR      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_HDMI_BASE_POINTER_ADDR_EN_BASE_POINTER_ADDR(v)   ((((reg32_t) v) << 7) & BM_HDMI_BASE_POINTER_ADDR_EN_BASE_POINTER_ADDR)
#else
#define BF_HDMI_BASE_POINTER_ADDR_EN_BASE_POINTER_ADDR(v)   (((v) << 7) & BM_HDMI_BASE_POINTER_ADDR_EN_BASE_POINTER_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_BASE_POINTER_ADDR field to a new value.
#define BW_HDMI_BASE_POINTER_ADDR_EN_BASE_POINTER_ADDR(v)   BF_CS1(HDMI_BASE_POINTER_ADDR, EN_BASE_POINTER_ADDR, v)
#endif


/*!
 * @brief All HDMI module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_hdmi_design_id_t DESIGN_ID; //!< Design Identification Register
    volatile hw_hdmi_revision_id_t REVISION_ID; //!< Revision Identification Register
    volatile hw_hdmi_product_id0_t PRODUCT_ID0; //!< Product Identification Register 0
    volatile hw_hdmi_product_id1_t PRODUCT_ID1; //!< Product Identification Register 1
    volatile hw_hdmi_config0_id_t CONFIG0_ID; //!< Configuration Identification Register 0
    volatile hw_hdmi_config1_id_t CONFIG1_ID; //!< Configuration Identification Register 1
    volatile hw_hdmi_config2_id_t CONFIG2_ID; //!< Configuration Identification Register 2
    volatile hw_hdmi_config3_id_t CONFIG3_ID; //!< Configuration Identification Register 3
    reg32_t _reserved0[62];
    volatile hw_hdmi_ih_fc_stat0_t IH_FC_STAT0; //!< Frame Composer Interrupt Status Register 0
    volatile hw_hdmi_ih_fc_stat1_t IH_FC_STAT1; //!< Frame Composer Interrupt Status Register 1
    volatile hw_hdmi_ih_fc_stat2_t IH_FC_STAT2; //!< Frame Composer Interrupt Status Register 2
    volatile hw_hdmi_ih_as_stat0_t IH_AS_STAT0; //!< Audio Sampler Interrupt Status Register
    volatile hw_hdmi_ih_phy_stat0_t IH_PHY_STAT0; //!< PHY Interface Interrupt Status Register
    volatile hw_hdmi_ih_i2cm_stat0_t IH_I2CM_STAT0; //!< E-DDC I2C Master Interrupt Status Register
    volatile hw_hdmi_ih_cec_stat0_t IH_CEC_STAT0; //!< CEC Interrupt Status Register
    volatile hw_hdmi_ih_vp_stat0_t IH_VP_STAT0; //!< Video Packetizer Interrupt Status Register
    volatile hw_hdmi_ih_i2cmphy_stat0_t IH_I2CMPHY_STAT0; //!< PHY GEN2 I2C Master Interrupt Status Register
    volatile hw_hdmi_ih_ahbdmaaud_stat0_t IH_AHBDMAAUD_STAT0; //!< AHB Audio DMA Interrupt Status Register
    reg16_t _reserved1[59];
    volatile hw_hdmi_ih_mute_fc_stat0_t IH_MUTE_FC_STAT0; //!< Frame Composer Interrupt Mute Control Register 0
    volatile hw_hdmi_ih_mute_fc_stat1_t IH_MUTE_FC_STAT1; //!< Frame Composer Interrupt Mute Control Register 1
    volatile hw_hdmi_ih_mute_fc_stat2_t IH_MUTE_FC_STAT2; //!< Frame Composer Interrupt Mute Control Register 2
    volatile hw_hdmi_ih_mute_as_stat0_t IH_MUTE_AS_STAT0; //!< Audio Sampler Interrupt Mute Control Register 0
    volatile hw_hdmi_ih_mute_phy_stat0_t IH_MUTE_PHY_STAT0; //!< PHY Interface Interrupt Mute Control Register
    volatile hw_hdmi_ih_mute_i2cm_stat0_t IH_MUTE_I2CM_STAT0; //!< E-DDC I2C Master Interrupt Mute Control Register
    volatile hw_hdmi_ih_mute_cec_stat0_t IH_MUTE_CEC_STAT0; //!< CEC Interrupt Mute Control Register
    volatile hw_hdmi_ih_mute_vp_stat0_t IH_MUTE_VP_STAT0; //!< Video Packetizer Interrupt Mute Control Register
    volatile hw_hdmi_ih_mute_i2cmphy_stat0_t IH_MUTE_I2CMPHY_STAT0; //!< PHY GEN 2 I2C Master Interrupt Mute Control Register
    volatile hw_hdmi_ih_mute_ahbdmaaud_stat0_t IH_MUTE_AHBDMAAUD_STAT0; //!< AHB Audio DMA Interrupt Mute Control Register
    reg8_t _reserved2[117];
    volatile hw_hdmi_ih_mute_t IH_MUTE; //!< Global Interrupt Mute Control Register
    volatile hw_hdmi_tx_invid0_t TX_INVID0; //!< Video Input Mapping and Internal Data Enable Configuration Register
    volatile hw_hdmi_tx_instuffing_t TX_INSTUFFING; //!< Video Input Stuffing Enable Register
    volatile hw_hdmi_tx_gydata0_t TX_GYDATA0; //!< Video Input GY Data Channel Stuffing Register 0
    volatile hw_hdmi_tx_gydata1_t TX_GYDATA1; //!< Video Input GY Data Channel Stuffing Register 1
    volatile hw_hdmi_tx_rcrdata0_t TX_RCRDATA0; //!< Video Input RCR Data Channel Stuffing Register 0
    volatile hw_hdmi_tx_rcrdata1_t TX_RCRDATA1; //!< Video Input RCR Data Channel Stuffing Register 1
    volatile hw_hdmi_tx_bcbdata0_t TX_BCBDATA0; //!< Video Input RCB Data Channel Stuffing Register 0
    volatile hw_hdmi_tx_bcbdata1_t TX_BCBDATA1; //!< Video Input RCB Data Channel Stuffing Register 1
    reg32_t _reserved3[382];
    volatile hw_hdmi_vp_status_t VP_STATUS; //!< Video Packetizer Packing Phase Status Register
    volatile hw_hdmi_vp_pr_cd_t VP_PR_CD; //!< Video Packetizer Pixel Repetition and Color Depth Register
    volatile hw_hdmi_vp_stuff_t VP_STUFF; //!< Video Packetizer Stuffing and Default Packing Phase Register
    volatile hw_hdmi_vp_remap_t VP_REMAP; //!< Video Packetizer YCC422 Remapping Register
    volatile hw_hdmi_vp_conf_t VP_CONF; //!< Video Packetizer Output, Bypass, and Enable Configuration Register
    volatile hw_hdmi_vp_stat_t VP_STAT; //!< VP_STAT
    volatile hw_hdmi_vp_int_t VP_INT; //!< VP_INT
    volatile hw_hdmi_vp_mask_t VP_MASK; //!< Video Packetizer Interrupt Mask Register
    volatile hw_hdmi_vp_pol_t VP_POL; //!< VP_POL
    reg8_t _reserved4[2039];
    volatile hw_hdmi_fc_invidconf_t FC_INVIDCONF; //!< Frame Composer Input Video Configuration and HDCP Keepout Register
    volatile hw_hdmi_fc_inhactiv0_t FC_INHACTIV0; //!< Frame Composer Input Video HActive Pixels Register 0
    volatile hw_hdmi_fc_inhactiv1_t FC_INHACTIV1; //!< Frame Composer Input Video HActive Pixels Register 1
    volatile hw_hdmi_fc_inhblank0_t FC_INHBLANK0; //!< Frame Composer Input Video HBlank Pixels Register 0
    volatile hw_hdmi_fc_inhblank1_t FC_INHBLANK1; //!< Frame Composer Input Video HBlank Pixels Register 1
    volatile hw_hdmi_fc_invactiv0_t FC_INVACTIV0; //!< Frame Composer Input Video VActive Pixels Register 0
    volatile hw_hdmi_fc_invactiv1_t FC_INVACTIV1; //!< Frame Composer Input Video VActive Pixels Register 1
    volatile hw_hdmi_fc_invblank_t FC_INVBLANK; //!< Frame Composer Input Video VBlank Pixels Register
    volatile hw_hdmi_fc_hsyncindelay0_t FC_HSYNCINDELAY0; //!< Frame Composer Input Video HSync Front Porch Register 0
    volatile hw_hdmi_fc_hsyncindelay1_t FC_HSYNCINDELAY1; //!< Frame Composer Input Video HSync Front Porch Register 1
    volatile hw_hdmi_fc_hsyncinwidth0_t FC_HSYNCINWIDTH0; //!< Frame Composer Input Video HSync Width Register 0
    volatile hw_hdmi_fc_hsyncinwidth1_t FC_HSYNCINWIDTH1; //!< Frame Composer Input Video HSync Width Register 1
    volatile hw_hdmi_fc_vsyncindelay_t FC_VSYNCINDELAY; //!< Frame Composer Input Video VSync Front Porch Register
    volatile hw_hdmi_fc_vsyncinwidth_t FC_VSYNCINWIDTH; //!< Frame Composer Input Video VSync Width Register
    volatile hw_hdmi_fc_infreq0_t FC_INFREQ0; //!< Frame Composer Input Video Refresh Rate Register 0
    volatile hw_hdmi_fc_infreq1_t FC_INFREQ1; //!< Frame Composer Input Video Refresh Rate Register 1
    volatile hw_hdmi_fc_infreq2_t FC_INFREQ2; //!< Frame Composer Input Video Refresh Rate Register 2
    volatile hw_hdmi_fc_ctrldur_t FC_CTRLDUR; //!< Frame Composer Control Period Duration Register
    volatile hw_hdmi_fc_exctrldur_t FC_EXCTRLDUR; //!< Frame Composer Extended Control Period Duration Register
    volatile hw_hdmi_fc_exctrlspac_t FC_EXCTRLSPAC; //!< Frame Composer Extended Control Period Maximum Spacing Register
    volatile hw_hdmi_fc_ch0pream_t FC_CH0PREAM; //!< Frame Composer Channel 0 Non-Preamble Data Register
    volatile hw_hdmi_fc_ch1pream_t FC_CH1PREAM; //!< Frame Composer Channel 1 Non-Preamble Data Register
    volatile hw_hdmi_fc_ch2pream_t FC_CH2PREAM; //!< Frame Composer Channel 2 Non-Preamble Data Register
    volatile hw_hdmi_fc_aviconf3_t FC_AVICONF3; //!< Frame Composer AVI Configuration Register 3
    volatile hw_hdmi_fc_gcp_t FC_GCP; //!< Frame Composer GCP Packet Configuration Register
    volatile hw_hdmi_fc_aviconf0_t FC_AVICONF0; //!< Frame Composer AVI Packet Configuration Register 0
    volatile hw_hdmi_fc_aviconf1_t FC_AVICONF1; //!< Frame Composer AVI Packet Configuration Register 1
    volatile hw_hdmi_fc_aviconf2_t FC_AVICONF2; //!< FC_AVICONFFrame Composer AVI Packet Configuration Register 2
    volatile hw_hdmi_fc_avivid_t FC_AVIVID; //!< Frame Composer AVI Packet VIC Register
    volatile hw_hdmi_fc_avietb0_t FC_AVIETB0; //!< Frame Composer AVI Packet End of Top Bar Register 0
    volatile hw_hdmi_fc_avietb1_t FC_AVIETB1; //!< Frame Composer AVI Packet End of Top Bar Register 1
    volatile hw_hdmi_fc_avisbb0_t FC_AVISBB0; //!< Frame Composer AVI Packet Start of Bottom Bar Register 0
    volatile hw_hdmi_fc_avisbb1_t FC_AVISBB1; //!< Frame Composer AVI Packet Start of Bottom Bar Register 1
    volatile hw_hdmi_fc_avielb0_t FC_AVIELB0; //!< Frame Composer AVI Packet End of Left Bar Register 0
    volatile hw_hdmi_fc_avielb1_t FC_AVIELB1; //!< Frame Composer AVI Packet End of Left Bar Register 1
    volatile hw_hdmi_fc_avisrb0_t FC_AVISRB0; //!< Frame Composer AVI Packet Start of Right Bar Register 0
    volatile hw_hdmi_fc_avisrb1_t FC_AVISRB1; //!< Frame Composer AVI Packet Start of Right Bar Register 1
    volatile hw_hdmi_fc_audiconf0_t FC_AUDICONF0; //!< Frame Composer AUD Packet Configuration Register 0
    volatile hw_hdmi_fc_audiconf1_t FC_AUDICONF1; //!< Frame Composer AUD Packet Configuration Register 1
    volatile hw_hdmi_fc_audiconf2_t FC_AUDICONF2; //!< Frame Composer AUD Packet Configuration Register 2
    volatile hw_hdmi_fc_audiconf3_t FC_AUDICONF3; //!< Frame Composer AUD Packet Configuration Register 3
    volatile hw_hdmi_fc_vsdieeeid0_t FC_VSDIEEEID0; //!< Frame Composer VSI Packet Data IEEE Register 0
    volatile hw_hdmi_fc_vsdsize_t FC_VSDSIZE; //!< Frame Composer VSI Packet Data Size Register
    reg8_t _reserved5[5];
    volatile hw_hdmi_fc_vsdieeeid1_t FC_VSDIEEEID1; //!< Frame Composer VSI Packet Data IEEE Register 1
    volatile hw_hdmi_fc_vsdieeeid2_t FC_VSDIEEEID2; //!< Frame Composer VSI Packet Data IEEE Register 2
    volatile hw_hdmi_fc_vsdpayload0_t FC_VSDPAYLOAD0; //!< Frame Composer VSI Packet Data IEEE Register 0
    volatile hw_hdmi_fc_vsdpayload1_t FC_VSDPAYLOAD1; //!< Frame Composer VSI Packet Data IEEE Register 1
    volatile hw_hdmi_fc_vsdpayload2_t FC_VSDPAYLOAD2; //!< Frame Composer VSI Packet Data IEEE Register 2
    volatile hw_hdmi_fc_vsdpayload3_t FC_VSDPAYLOAD3; //!< Frame Composer VSI Packet Data IEEE Register 3
    volatile hw_hdmi_fc_vsdpayload4_t FC_VSDPAYLOAD4; //!< Frame Composer VSI Packet Data IEEE Register 4
    volatile hw_hdmi_fc_vsdpayload5_t FC_VSDPAYLOAD5; //!< Frame Composer VSI Packet Data IEEE Register 5
    volatile hw_hdmi_fc_vsdpayload6_t FC_VSDPAYLOAD6; //!< Frame Composer VSI Packet Data IEEE Register 6
    volatile hw_hdmi_fc_vsdpayload7_t FC_VSDPAYLOAD7; //!< Frame Composer VSI Packet Data IEEE Register 7
    volatile hw_hdmi_fc_vsdpayload8_t FC_VSDPAYLOAD8; //!< Frame Composer VSI Packet Data IEEE Register 8
    volatile hw_hdmi_fc_vsdpayload9_t FC_VSDPAYLOAD9; //!< Frame Composer VSI Packet Data IEEE Register 9
    volatile hw_hdmi_fc_vsdpayload10_t FC_VSDPAYLOAD10; //!< Frame Composer VSI Packet Data IEEE Register 10
    volatile hw_hdmi_fc_vsdpayload11_t FC_VSDPAYLOAD11; //!< Frame Composer VSI Packet Data IEEE Register 11
    volatile hw_hdmi_fc_vsdpayload12_t FC_VSDPAYLOAD12; //!< Frame Composer VSI Packet Data IEEE Register 12
    volatile hw_hdmi_fc_vsdpayload13_t FC_VSDPAYLOAD13; //!< Frame Composer VSI Packet Data IEEE Register 13
    volatile hw_hdmi_fc_vsdpayload14_t FC_VSDPAYLOAD14; //!< Frame Composer VSI Packet Data IEEE Register 14
    volatile hw_hdmi_fc_vsdpayload15_t FC_VSDPAYLOAD15; //!< Frame Composer VSI Packet Data IEEE Register 15
    volatile hw_hdmi_fc_vsdpayload16_t FC_VSDPAYLOAD16; //!< Frame Composer VSI Packet Data IEEE Register 16
    volatile hw_hdmi_fc_vsdpayload17_t FC_VSDPAYLOAD17; //!< Frame Composer VSI Packet Data IEEE Register 17
    volatile hw_hdmi_fc_vsdpayload18_t FC_VSDPAYLOAD18; //!< Frame Composer VSI Packet Data IEEE Register 18
    volatile hw_hdmi_fc_vsdpayload19_t FC_VSDPAYLOAD19; //!< Frame Composer VSI Packet Data IEEE Register 19
    volatile hw_hdmi_fc_vsdpayload20_t FC_VSDPAYLOAD20; //!< Frame Composer VSI Packet Data IEEE Register 20
    volatile hw_hdmi_fc_vsdpayload21_t FC_VSDPAYLOAD21; //!< Frame Composer VSI Packet Data IEEE Register 21
    volatile hw_hdmi_fc_vsdpayload22_t FC_VSDPAYLOAD22; //!< Frame Composer VSI Packet Data IEEE Register 22
    volatile hw_hdmi_fc_vsdpayload23_t FC_VSDPAYLOAD23; //!< Frame Composer VSI Packet Data IEEE Register 23
    volatile hw_hdmi_fc_spdvendorname0_t FC_SPDVENDORNAME0; //!< Frame Composer SPD Packet Data Vendor Name Register 0
    reg8_t _reserved6[7];
    volatile hw_hdmi_fc_spdproductname0_t FC_SPDPRODUCTNAME0; //!< Frame Composer SPD Packet Data Product Name Register 0
    reg8_t _reserved7[15];
    volatile hw_hdmi_fc_spddeviceinf_t FC_SPDDEVICEINF; //!< Frame Composer SPD Packet Data Source Product Descriptor Register
    volatile hw_hdmi_fc_audsconf_t FC_AUDSCONF; //!< Frame Composer Audio Sample Flat and Layout Configuration Register
    volatile hw_hdmi_fc_audsstat_t FC_AUDSSTAT; //!< Frame Composer Audio Packet Sample Present Status Register
    reg16_t _reserved8[7];
    volatile hw_hdmi_fc_ctrlqhigh_t FC_CTRLQHIGH; //!< Frame Composer Number of High Priority Packets Attended Configuration Register
    volatile hw_hdmi_fc_ctrlqlow_t FC_CTRLQLOW; //!< Frame Composer Number of Low Priority Packets Attended Configuration Register
    volatile hw_hdmi_fc_acp0_t FC_ACP0; //!< Frame Composer ACP Packet Type Configuration Register 0
    reg8_t _reserved9[27];
    volatile hw_hdmi_fc_acp1_t FC_ACP1; //!< Frame Composer ACP Packet Type Configuration Register 1
    volatile hw_hdmi_fc_iscr1_0_t FC_ISCR1_0; //!< FC_ISCR1_Frame Composer Packet Status, Valid, and Continue Configuration Register
    volatile hw_hdmi_fc_iscr1_1_t FC_ISCR1_1; //!< Frame Composer ISCR1 Packet Body Register 1
    reg8_t _reserved10[15];
    volatile hw_hdmi_fc_iscr2_0_t FC_ISCR2_0; //!< Frame Composer ISCR2 Packet Body Register 0
    reg8_t _reserved11[15];
    volatile hw_hdmi_fc_datauto0_t FC_DATAUTO0; //!< Frame Composer Data Island Auto Packet Scheduling Register 0
    volatile hw_hdmi_fc_datauto1_t FC_DATAUTO1; //!< Frame Composer Data Island Auto Packet Scheduling Register 1
    volatile hw_hdmi_fc_datauto2_t FC_DATAUTO2; //!< Frame Composer Data Island Auto Packet Scheduling Register 2
    volatile hw_hdmi_fc_datman_t FC_DATMAN; //!< Frame Composer Data Island Manual Packet Request Register
    volatile hw_hdmi_fc_datauto3_t FC_DATAUTO3; //!< Frame Composer Data Island Auto Packet Scheduling Register 3
    volatile hw_hdmi_fc_rdrb0_t FC_RDRB0; //!< Frame Composer Round Robin ACR Packet Insertion Register 0
    volatile hw_hdmi_fc_rdrb1_t FC_RDRB1; //!< Frame Composer Round Robin ACR Packet Insertion Register 1
    volatile hw_hdmi_fc_rdrb2_t FC_RDRB2; //!< Frame Composer Round Robin ACR Packet Insertion Register 2
    volatile hw_hdmi_fc_rdrb3_t FC_RDRB3; //!< Frame Composer Round Robin ACR Packet Insertion Register 3
    volatile hw_hdmi_fc_rdrb4_t FC_RDRB4; //!< Frame Composer Round Robin ACR Packet Insertion Register 4
    volatile hw_hdmi_fc_rdrb5_t FC_RDRB5; //!< Frame Composer Round Robin ACR Packet Insertion Register 5
    volatile hw_hdmi_fc_rdrb6_t FC_RDRB6; //!< Frame Composer Round Robin ACR Packet Insertion Register 6
    volatile hw_hdmi_fc_rdrb7_t FC_RDRB7; //!< Frame Composer Round Robin ACR Packet Insertion Register 7
    reg32_t _reserved12[4];
    volatile hw_hdmi_fc_stat0_t FC_STAT0; //!< FC_STAT0
    volatile hw_hdmi_fc_int0_t FC_INT0; //!< FC_INT0
    volatile hw_hdmi_fc_mask0_t FC_MASK0; //!< Frame Composer Packet Interrupt Mask Register 0
    volatile hw_hdmi_fc_pol0_t FC_POL0; //!< FC_POL0
    volatile hw_hdmi_fc_stat1_t FC_STAT1; //!< FC_STAT1
    volatile hw_hdmi_fc_int1_t FC_INT1; //!< FC_INT1
    volatile hw_hdmi_fc_mask1_t FC_MASK1; //!< Frame Composer Packet Interrupt Mask Register 1
    volatile hw_hdmi_fc_pol1_t FC_POL1; //!< FC_POL1
    volatile hw_hdmi_fc_stat2_t FC_STAT2; //!< FC_STAT2
    volatile hw_hdmi_fc_int2_t FC_INT2; //!< FC_INT2
    volatile hw_hdmi_fc_mask2_t FC_MASK2; //!< Frame Composer High/Low Priority Overflow Interrupt Mask Register 2
    volatile hw_hdmi_fc_pol2_t FC_POL2; //!< FC_POL2
    reg32_t _reserved13;
    volatile hw_hdmi_fc_prconf_t FC_PRCONF; //!< Frame Composer Pixel Repetition Configuration Register
    reg8_t _reserved14[31];
    volatile hw_hdmi_fc_gmd_stat_t FC_GMD_STAT; //!< Frame Composer GMD Packet Status Register
    volatile hw_hdmi_fc_gmd_en_t FC_GMD_EN; //!< Frame Composer GMD Packet Enable Register
    volatile hw_hdmi_fc_gmd_up_t FC_GMD_UP; //!< Frame Composer GMD Packet Update Register
    volatile hw_hdmi_fc_gmd_conf_t FC_GMD_CONF; //!< Frame Composer GMD Packet Schedule Configuration Register
    volatile hw_hdmi_fc_gmd_hb_t FC_GMD_HB; //!< Frame Composer GMD Packet Profile and Gamut Sequence Configuration Register
    volatile hw_hdmi_fc_gmd_pb0_t FC_GMD_PB0; //!< Frame Composer GMD Packet Body Register 0
    volatile hw_hdmi_fc_gmd_pb1_t FC_GMD_PB1; //!< Frame Composer GMD Packet Body Register 1
    volatile hw_hdmi_fc_gmd_pb2_t FC_GMD_PB2; //!< Frame Composer GMD Packet Body Register 2
    volatile hw_hdmi_fc_gmd_pb3_t FC_GMD_PB3; //!< Frame Composer GMD Packet Body Register 3
    volatile hw_hdmi_fc_gmd_pb4_t FC_GMD_PB4; //!< Frame Composer GMD Packet Body Register 4
    volatile hw_hdmi_fc_gmd_pb5_t FC_GMD_PB5; //!< Frame Composer GMD Packet Body Register 5
    volatile hw_hdmi_fc_gmd_pb6_t FC_GMD_PB6; //!< Frame Composer GMD Packet Body Register 6
    volatile hw_hdmi_fc_gmd_pb7_t FC_GMD_PB7; //!< Frame Composer GMD Packet Body Register 7
    volatile hw_hdmi_fc_gmd_pb8_t FC_GMD_PB8; //!< Frame Composer GMD Packet Body Register 8
    volatile hw_hdmi_fc_gmd_pb9_t FC_GMD_PB9; //!< Frame Composer GMD Packet Body Register 9
    volatile hw_hdmi_fc_gmd_pb10_t FC_GMD_PB10; //!< Frame Composer GMD Packet Body Register 10
    volatile hw_hdmi_fc_gmd_pb11_t FC_GMD_PB11; //!< Frame Composer GMD Packet Body Register 11
    volatile hw_hdmi_fc_gmd_pb12_t FC_GMD_PB12; //!< Frame Composer GMD Packet Body Register 12
    volatile hw_hdmi_fc_gmd_pb13_t FC_GMD_PB13; //!< Frame Composer GMD Packet Body Register 13
    volatile hw_hdmi_fc_gmd_pb14_t FC_GMD_PB14; //!< Frame Composer GMD Packet Body Register 14
    volatile hw_hdmi_fc_gmd_pb15_t FC_GMD_PB15; //!< Frame Composer GMD Packet Body Register 15
    volatile hw_hdmi_fc_gmd_pb16_t FC_GMD_PB16; //!< Frame Composer GMD Packet Body Register 16
    volatile hw_hdmi_fc_gmd_pb17_t FC_GMD_PB17; //!< Frame Composer GMD Packet Body Register 17
    volatile hw_hdmi_fc_gmd_pb18_t FC_GMD_PB18; //!< Frame Composer GMD Packet Body Register 18
    volatile hw_hdmi_fc_gmd_pb19_t FC_GMD_PB19; //!< Frame Composer GMD Packet Body Register 19
    volatile hw_hdmi_fc_gmd_pb20_t FC_GMD_PB20; //!< Frame Composer GMD Packet Body Register 20
    volatile hw_hdmi_fc_gmd_pb21_t FC_GMD_PB21; //!< Frame Composer GMD Packet Body Register 21
    volatile hw_hdmi_fc_gmd_pb22_t FC_GMD_PB22; //!< Frame Composer GMD Packet Body Register 22
    volatile hw_hdmi_fc_gmd_pb23_t FC_GMD_PB23; //!< Frame Composer GMD Packet Body Register 23
    volatile hw_hdmi_fc_gmd_pb24_t FC_GMD_PB24; //!< Frame Composer GMD Packet Body Register 24
    volatile hw_hdmi_fc_gmd_pb25_t FC_GMD_PB25; //!< Frame Composer GMD Packet Body Register 25
    volatile hw_hdmi_fc_gmd_pb26_t FC_GMD_PB26; //!< Frame Composer GMD Packet Body Register 26
    volatile hw_hdmi_fc_gmd_pb27_t FC_GMD_PB27; //!< Frame Composer GMD Packet Body Register 27
    reg8_t _reserved15[223];
    volatile hw_hdmi_fc_dbgforce_t FC_DBGFORCE; //!< Frame Composer Video/Audio Force Enable Register
    volatile hw_hdmi_fc_dbgaud0ch0_t FC_DBGAUD0CH0; //!< Frame Composer Audio Channel 0 Register 0
    volatile hw_hdmi_fc_dbgaud1ch0_t FC_DBGAUD1CH0; //!< Frame Composer Audio Channel 0 Register 1
    volatile hw_hdmi_fc_dbgaud2ch0_t FC_DBGAUD2CH0; //!< Frame Composer Audio Channel 0 Register 2
    volatile hw_hdmi_fc_dbgaud0ch1_t FC_DBGAUD0CH1; //!< Frame Composer Audio Channel 1 Register 0
    volatile hw_hdmi_fc_dbgaud1ch1_t FC_DBGAUD1CH1; //!< Frame Composer Audio Channel 1 Register 1
    volatile hw_hdmi_fc_dbgaud2ch1_t FC_DBGAUD2CH1; //!< Frame Composer Audio Channel 1 Register 2
    volatile hw_hdmi_fc_dbgaud0ch2_t FC_DBGAUD0CH2; //!< Frame Composer Debug Audio Channel 2 Register 0
    volatile hw_hdmi_fc_dbgaud1ch2_t FC_DBGAUD1CH2; //!< Frame Composer Debug Audio Channel 2 Register 1
    volatile hw_hdmi_fc_dbgaud2ch2_t FC_DBGAUD2CH2; //!< Frame Composer Audio Channel 2 Register 2
    volatile hw_hdmi_fc_dbgaud0ch3_t FC_DBGAUD0CH3; //!< Frame Composer Audio Channel 3 Register 0
    volatile hw_hdmi_fc_dbgaud1ch3_t FC_DBGAUD1CH3; //!< Frame Composer Audio Channel 3 Register 1
    volatile hw_hdmi_fc_dbgaud2ch3_t FC_DBGAUD2CH3; //!< Frame Composer Audio Channel 3 Register 2
    volatile hw_hdmi_fc_dbgaud0ch4_t FC_DBGAUD0CH4; //!< Frame Composer Audio Channel 4 Register 0
    volatile hw_hdmi_fc_dbgaud1ch4_t FC_DBGAUD1CH4; //!< Frame Composer Audio Channel 4 Register 1
    volatile hw_hdmi_fc_dbgaud2ch4_t FC_DBGAUD2CH4; //!< Frame Composer Audio Channel 4 Register 2
    volatile hw_hdmi_fc_dbgaud0ch5_t FC_DBGAUD0CH5; //!< Frame Composer Audio Channel 5 Register 0
    volatile hw_hdmi_fc_dbgaud1ch5_t FC_DBGAUD1CH5; //!< Frame Composer Audio Channel 5 Register 1
    volatile hw_hdmi_fc_dbgaud2ch5_t FC_DBGAUD2CH5; //!< Frame Composer Audio Channel 5 Register 2
    volatile hw_hdmi_fc_dbgaud0ch6_t FC_DBGAUD0CH6; //!< Frame Composer Audio Channel 6 Register 0
    volatile hw_hdmi_fc_dbgaud1ch6_t FC_DBGAUD1CH6; //!< Frame Composer Audio Channel 6 Register 1
    volatile hw_hdmi_fc_dbgaud2ch6_t FC_DBGAUD2CH6; //!< Frame Composer Audio Channel 6 Register 2
    volatile hw_hdmi_fc_dbgaud0ch7_t FC_DBGAUD0CH7; //!< Frame Composer Audio Channel 7 Register 1
    volatile hw_hdmi_fc_dbgaud1ch7_t FC_DBGAUD1CH7; //!< Frame Composer Audio Channel 7 Register 0
    volatile hw_hdmi_fc_dbgaud2ch7_t FC_DBGAUD2CH7; //!< Frame Composer Audio Channel 7 Register 2
    volatile hw_hdmi_fc_dbgtmds0_t FC_DBGTMDS0; //!< Frame Composer TMDS Channel 0 Register
    volatile hw_hdmi_fc_dbgtmds1_t FC_DBGTMDS1; //!< Frame Composer TMDS Channel 1 Register
    volatile hw_hdmi_fc_dbgtmds2_t FC_DBGTMDS2; //!< Frame Composer TMDS Channel 2 Register
    reg32_t _reserved16[1913];
    volatile hw_hdmi_phy_conf0_t PHY_CONF0; //!< PHY Configuration Register
    volatile hw_hdmi_phy_tst0_t PHY_TST0; //!< PHY Test Interface Register 0
    volatile hw_hdmi_phy_tst1_t PHY_TST1; //!< PHY Test Interface Register 1
    volatile hw_hdmi_phy_tst2_t PHY_TST2; //!< PHY Test Interface Register 2
    volatile hw_hdmi_phy_stat0_t PHY_STAT0; //!< PHY RXSENSE, PLL lock, and HPD Status Register
    volatile hw_hdmi_phy_int0_t PHY_INT0; //!< PHY RXSENSE, PLL lock, and HPD Interrupt Register
    volatile hw_hdmi_phy_mask0_t PHY_MASK0; //!< PHY RXSENSE, PLL lock, and HPD Mask Register
    volatile hw_hdmi_phy_pol0_t PHY_POL0; //!< PHY RXSENSE, PLL lock and HPD Polarity Register
    reg32_t _reserved17[6];
    volatile hw_hdmi_phy_i2cm_slave_addr_t PHY_I2CM_SLAVE_ADDR; //!< PHY I2C Slave Address Configuration Register
    volatile hw_hdmi_phy_i2cm_address_addr_t PHY_I2CM_ADDRESS_ADDR; //!< PHY I2C Address Configuration Register
    volatile hw_hdmi_phy_i2cm_datao_1_addr_t PHY_I2CM_DATAO_1_ADDR; //!< PHY I2C Data Write Register 1
    volatile hw_hdmi_phy_i2cm_datao_0_addr_t PHY_I2CM_DATAO_0_ADDR; //!< PHY I2C Data Write Register 0
    volatile hw_hdmi_phy_i2cm_datai_1_addr_t PHY_I2CM_DATAI_1_ADDR; //!< PHY I2C Data Read Register 1
    volatile hw_hdmi_phy_i2cm_datai_0_addr_t PHY_I2CM_DATAI_0_ADDR; //!< PHY I2C Data Read Register 0
    volatile hw_hdmi_phy_i2cm_operation_addr_t PHY_I2CM_OPERATION_ADDR; //!< PHY I2C Read/Write Operation
    volatile hw_hdmi_phy_i2cm_int_addr_t PHY_I2CM_INT_ADDR; //!< PHY I2C Done Interrupt Register
    volatile hw_hdmi_phy_i2cm_ctlint_addr_t PHY_I2CM_CTLINT_ADDR; //!< PHY I2C Done Interrupt Register
    volatile hw_hdmi_phy_i2cm_div_addr_t PHY_I2CM_DIV_ADDR; //!< PHY I2C Speed Control Register
    volatile hw_hdmi_phy_i2cm_softrstz_addr_t PHY_I2CM_SOFTRSTZ_ADDR; //!< PHY I2C Software Reset Register
    volatile hw_hdmi_phy_i2cm_ss_scl_hcnt_1_addr_t PHY_I2CM_SS_SCL_HCNT_1_ADDR; //!< PHY I2C Slow Speed SCL High Level Control Register 1
    volatile hw_hdmi_phy_i2cm_ss_scl_hcnt_0_addr_t PHY_I2CM_SS_SCL_HCNT_0_ADDR; //!< PHY I2C Slow Speed SCL High Level Control Register 0
    volatile hw_hdmi_phy_i2cm_ss_scl_lcnt_1_addr_t PHY_I2CM_SS_SCL_LCNT_1_ADDR; //!< PHY I2C Slow Speed SCL Low Level Control Register 1
    volatile hw_hdmi_phy_i2cm_ss_scl_lcnt_0_addr_t PHY_I2CM_SS_SCL_LCNT_0_ADDR; //!< PHY I2C Slow Speed SCL Low Level Control Register 0
    volatile hw_hdmi_phy_i2cm_fs_scl_hcnt_1_addr_t PHY_I2CM_FS_SCL_HCNT_1_ADDR; //!< PHY I2C Fast Speed SCL High Level Control Register 1
    volatile hw_hdmi_phy_i2cm_fs_scl_hcnt_0_addr_t PHY_I2CM_FS_SCL_HCNT_0_ADDR; //!< PHY I2C Fast Speed SCL High Level Control Register 0
    volatile hw_hdmi_phy_i2cm_fs_scl_lcnt_1_addr_t PHY_I2CM_FS_SCL_LCNT_1_ADDR; //!< PHY I2C Fast Speed SCL Low Level Control Register 1
    volatile hw_hdmi_phy_i2cm_fs_scl_lcnt_0_addr_t PHY_I2CM_FS_SCL_LCNT_0_ADDR; //!< PHY I2C Fast Speed SCL Low Level Control Register 0
    reg8_t _reserved18[461];
    volatile hw_hdmi_aud_n1_t AUD_N1; //!< Audio Clock Regenerator N Value Register 1
    volatile hw_hdmi_aud_n2_t AUD_N2; //!< Audio Clock Regenerator N Value Register 2
    volatile hw_hdmi_aud_n3_t AUD_N3; //!< Audio Clock Regenerator N Value Register 3
    volatile hw_hdmi_aud_cts1_t AUD_CTS1; //!< AUD_CTS1
    volatile hw_hdmi_aud_cts2_t AUD_CTS2; //!< AUD_CTS2
    volatile hw_hdmi_aud_cts3_t AUD_CTS3; //!< AUD_CTS3
    reg16_t _reserved19[509];
    volatile hw_hdmi_ahb_dma_conf0_t AHB_DMA_CONF0; //!< Audio DMA Start Register
    volatile hw_hdmi_ahb_dma_start_t AHB_DMA_START; //!< AHB_DMA_START
    volatile hw_hdmi_ahb_dma_stop_t AHB_DMA_STOP; //!< Audio DMA Stop Register
    volatile hw_hdmi_ahb_dma_thrsld_t AHB_DMA_THRSLD; //!< Audio DMA FIFO Threshold Register
    volatile hw_hdmi_ahb_dma_straddr0_t AHB_DMA_STRADDR0; //!< Audio DMA Start Address Register 0
    volatile hw_hdmi_ahb_dma_straddr1_t AHB_DMA_STRADDR1; //!< Audio DMA Start Address Register 1
    volatile hw_hdmi_ahb_dma_straddr2_t AHB_DMA_STRADDR2; //!< Audio DMA Start Address Register 2
    volatile hw_hdmi_ahb_dma_straddr3_t AHB_DMA_STRADDR3; //!< Audio DMA Start Address Register 3
    volatile hw_hdmi_ahb_dma_stpaddr0_t AHB_DMA_STPADDR0; //!< Audio DMA Stop Address Register 0
    volatile hw_hdmi_ahb_dma_stpaddr1_t AHB_DMA_STPADDR1; //!< Audio DMA Stop Address Register 1
    volatile hw_hdmi_ahb_dma_stpaddr2_t AHB_DMA_STPADDR2; //!< Audio DMA Stop Address Register 2
    volatile hw_hdmi_ahb_dma_stpaddr3_t AHB_DMA_STPADDR3; //!< Audio DMA Stop Address Register 3
    volatile hw_hdmi_ahb_dma_bstaddr0_t AHB_DMA_BSTADDR0; //!< Audio DMA Burst Start Address Register 0
    volatile hw_hdmi_ahb_dma_bstaddr1_t AHB_DMA_BSTADDR1; //!< Audio DMA Burst Start Address Register 1
    volatile hw_hdmi_ahb_dma_bstaddr2_t AHB_DMA_BSTADDR2; //!< Audio DMA Burst Start Address Register 2
    volatile hw_hdmi_ahb_dma_bstaddr3_t AHB_DMA_BSTADDR3; //!< Audio DMA Burst Start Address Register 3
    volatile hw_hdmi_ahb_dma_mblength0_t AHB_DMA_MBLENGTH0; //!< Audio DMA Burst Length Register 0
    volatile hw_hdmi_ahb_dma_mblength1_t AHB_DMA_MBLENGTH1; //!< Audio DMA Burst Length Register 1
    volatile hw_hdmi_ahb_dma_stat_t AHB_DMA_STAT; //!< Audio DMA Interrupt Status Register
    volatile hw_hdmi_ahb_dma_int_t AHB_DMA_INT; //!< Audio DMA Interrupt Register
    volatile hw_hdmi_ahb_dma_mask_t AHB_DMA_MASK; //!< Audio DMA Mask Interrupt Register
    volatile hw_hdmi_ahb_dma_pol_t AHB_DMA_POL; //!< Audio DMA Polarity Interrupt Register
    volatile hw_hdmi_ahb_dma_conf1_t AHB_DMA_CONF1; //!< Audio DMA Channel Enable Configuration Register 1
    volatile hw_hdmi_ahb_dma_buffstat_t AHB_DMA_BUFFSTAT; //!< Audio DMA Buffer Interrupt Status Register
    volatile hw_hdmi_ahb_dma_buffint_t AHB_DMA_BUFFINT; //!< Audio DMA Buffer Interrupt Register
    volatile hw_hdmi_ahb_dma_buffmask_t AHB_DMA_BUFFMASK; //!< Audio DMA Buffer Mask Interrupt Register
    volatile hw_hdmi_ahb_dma_buffpol_t AHB_DMA_BUFFPOL; //!< Audio DMA Buffer Polarity Interrupt Register
    reg16_t _reserved20[1267];
    volatile hw_hdmi_mc_clkdis_t MC_CLKDIS; //!< Main Controller Synchronous Clock Domain Disable Register
    volatile hw_hdmi_mc_swrstzreq_t MC_SWRSTZREQ; //!< Main Controller Software Reset Register
    reg8_t _reserved21;
    volatile hw_hdmi_mc_flowctrl_t MC_FLOWCTRL; //!< Main Controller Feed Through Control Register
    volatile hw_hdmi_mc_phyrstz_t MC_PHYRSTZ; //!< Main Controller PHY Reset Register
    volatile hw_hdmi_mc_lockonclock_t MC_LOCKONCLOCK; //!< Main Controller Clock Present Register
    volatile hw_hdmi_mc_heacphy_rst_t MC_HEACPHY_RST; //!< Main Controller HEAC PHY Reset Register
    reg32_t _reserved22[62];
    volatile hw_hdmi_csc_cfg_t CSC_CFG; //!< Color Space Converter Interpolation and Decimation Configuration Register
    volatile hw_hdmi_csc_scale_t CSC_SCALE; //!< Color Space Converter Scale and Deep Color Configuration Register
    volatile hw_hdmi_csc_coef_a1_msb_t CSC_COEF_A1_MSB; //!< CSC_COEF_A1_MSB
    volatile hw_hdmi_csc_coef_a1_lsb_t CSC_COEF_A1_LSB; //!< CSC_COEF_A1_LSB
    volatile hw_hdmi_csc_coef_a2_msb_t CSC_COEF_A2_MSB; //!< CSC_COEF_A2_MSB
    volatile hw_hdmi_csc_coef_a2_lsb_t CSC_COEF_A2_LSB; //!< CSC_COEF_A2_LSB
    volatile hw_hdmi_csc_coef_a3_msb_t CSC_COEF_A3_MSB; //!< CSC_COEF_A3_MSB
    volatile hw_hdmi_csc_coef_a3_lsb_t CSC_COEF_A3_LSB; //!< CSC_COEF_A3_LSB
    volatile hw_hdmi_csc_coef_a4_msb_t CSC_COEF_A4_MSB; //!< CSC_COEF_A4_MSB
    volatile hw_hdmi_csc_coef_a4_lsb_t CSC_COEF_A4_LSB; //!< CSC_COEF_A4_LSB
    volatile hw_hdmi_csc_coef_b1_msb_t CSC_COEF_B1_MSB; //!< CSC_COEF_B1_MSB
    volatile hw_hdmi_csc_coef_b1_lsb_t CSC_COEF_B1_LSB; //!< CSC_COEF_B1_LSB
    volatile hw_hdmi_csc_coef_b2_msb_t CSC_COEF_B2_MSB; //!< CSC_COEF_B2_MSB
    volatile hw_hdmi_csc_coef_b2_lsb_t CSC_COEF_B2_LSB; //!< CSC_COEF_B2_LSB
    volatile hw_hdmi_csc_coef_b3_msb_t CSC_COEF_B3_MSB; //!< CSC_COEF_B3_MSB
    volatile hw_hdmi_csc_coef_b3_lsb_t CSC_COEF_B3_LSB; //!< CSC_COEF_B3_LSB
    volatile hw_hdmi_csc_coef_b4_msb_t CSC_COEF_B4_MSB; //!< CSC_COEF_B4_MSB
    volatile hw_hdmi_csc_coef_b4_lsb_t CSC_COEF_B4_LSB; //!< CSC_COEF_B4_LSB
    volatile hw_hdmi_csc_coef_c1_msb_t CSC_COEF_C1_MSB; //!< CSC_COEF_C1_MSB
    volatile hw_hdmi_csc_coef_c1_lsb_t CSC_COEF_C1_LSB; //!< CSC_COEF_C1_LSB
    volatile hw_hdmi_csc_coef_c2_msb_t CSC_COEF_C2_MSB; //!< CSC_COEF_C2_MSB
    volatile hw_hdmi_csc_coef_c2_lsb_t CSC_COEF_C2_LSB; //!< CSC_COEF_C2_LSB
    volatile hw_hdmi_csc_coef_c3_msb_t CSC_COEF_C3_MSB; //!< CSC_COEF_C3_MSB
    volatile hw_hdmi_csc_coef_c3_lsb_t CSC_COEF_C3_LSB; //!< CSC_COEF_C3_LSB
    volatile hw_hdmi_csc_coefc4_msb_t CSC_COEFC4_MSB; //!< CSC_COEFC4_MSB
    volatile hw_hdmi_csc_coefc4_lsb_t CSC_COEFC4_LSB; //!< CSC_COEFC4_LSB
    reg16_t _reserved23[1907];
    volatile hw_hdmi_a_hdcpcfg0_t A_HDCPCFG0; //!< A_HDCPCFG0
    volatile hw_hdmi_a_hdcpcfg1_t A_HDCPCFG1; //!< A_HDCPCFG1
    volatile hw_hdmi_a_hdcpobs0_t A_HDCPOBS0; //!< A_HDCPOBS0
    volatile hw_hdmi_a_hdcpobs1_t A_HDCPOBS1; //!< A_HDCPOBS1
    volatile hw_hdmi_a_hdcpobs2_t A_HDCPOBS2; //!< A_HDCPOBS2
    volatile hw_hdmi_a_hdcpobs3_t A_HDCPOBS3; //!< A_HDCPOBS3
    volatile hw_hdmi_a_apiintclr_t A_APIINTCLR; //!< A_APIINTCLR
    volatile hw_hdmi_a_apiintstat_t A_APIINTSTAT; //!< A_APIINTSTAT
    volatile hw_hdmi_a_apiintmsk_t A_APIINTMSK; //!< A_APIINTMSK
    volatile hw_hdmi_a_vidpolcfg_t A_VIDPOLCFG; //!< A_VIDPOLCFG
    volatile hw_hdmi_a_oesswcfg_t A_OESSWCFG; //!< A_OESSWCFG
    reg8_t _reserved24[9];
    volatile hw_hdmi_a_coreverlsb_t A_COREVERLSB; //!< A_COREVERLSB
    volatile hw_hdmi_a_corevermsb_t A_COREVERMSB; //!< A_COREVERMSB
    volatile hw_hdmi_a_ksvmemctrl_t A_KSVMEMCTRL; //!< A_KSVMEMCTRL
    reg8_t _reserved25[10217];
    volatile hw_hdmi_hdcpreg_bksv0_t HDCPREG_BKSV0; //!< HDCPREG_BKSV0
    volatile hw_hdmi_hdcpreg_bksv1_t HDCPREG_BKSV1; //!< HDCPREG_BKSV1
    volatile hw_hdmi_hdcpreg_bksv2_t HDCPREG_BKSV2; //!< HDCPREG_BKSV2
    volatile hw_hdmi_hdcpreg_bksv3_t HDCPREG_BKSV3; //!< HDCPREG_BKSV3
    volatile hw_hdmi_hdcpreg_bksv4_t HDCPREG_BKSV4; //!< HDCPREG_BKSV4
    volatile hw_hdmi_hdcpreg_anconf_t HDCPREG_ANCONF; //!< HDCPREG_ANCONF
    volatile hw_hdmi_hdcpreg_an0_t HDCPREG_AN0; //!< HDCPREG_AN0
    volatile hw_hdmi_hdcpreg_an1_t HDCPREG_AN1; //!< HDCPREG_AN1
    volatile hw_hdmi_hdcpreg_an2_t HDCPREG_AN2; //!< HDCPREG_AN2
    volatile hw_hdmi_hdcpreg_an3_t HDCPREG_AN3; //!< HDCPREG_AN3
    volatile hw_hdmi_hdcpreg_an4_t HDCPREG_AN4; //!< HDCPREG_AN4
    volatile hw_hdmi_hdcpreg_an5_t HDCPREG_AN5; //!< HDCPREG_AN5
    volatile hw_hdmi_hdcpreg_an6_t HDCPREG_AN6; //!< HDCPREG_AN6
    volatile hw_hdmi_hdcpreg_an7_t HDCPREG_AN7; //!< HDCPREG_AN7
    reg16_t _reserved26[633];
    volatile hw_hdmi_cec_ctrl_t CEC_CTRL; //!< CEC_CTRL
    volatile hw_hdmi_cec_stat_t CEC_STAT; //!< CEC_STAT
    volatile hw_hdmi_cec_mask_t CEC_MASK; //!< CEC_MASK
    volatile hw_hdmi_cec_polarity_t CEC_POLARITY; //!< CEC_POLARITY
    volatile hw_hdmi_cec_int_t CEC_INT; //!< CEC_INT
    volatile hw_hdmi_cec_addr_l_t CEC_ADDR_L; //!< CEC_ADDR_L
    volatile hw_hdmi_cec_addr_h_t CEC_ADDR_H; //!< CEC_ADDR_H
    volatile hw_hdmi_cec_tx_cnt_t CEC_TX_CNT; //!< CEC_TX_CNT
    volatile hw_hdmi_cec_rx_cnt_t CEC_RX_CNT; //!< CEC_RX_CNT
    reg8_t _reserved27[7];
    volatile hw_hdmi_cec_tx_datan_t CEC_TX_DATAN; //!< CEC_TX_DATAn
    reg8_t _reserved28[15];
    volatile hw_hdmi_cec_rx_datan_t CEC_RX_DATAN; //!< CEC_RX_DATAn
    reg8_t _reserved29[15];
    volatile hw_hdmi_cec_lock_t CEC_LOCK; //!< CEC_LOCK
    volatile hw_hdmi_cec_wkupctrl_t CEC_WKUPCTRL; //!< CEC_WKUPCTRL
    reg16_t _reserved30[103];
    volatile hw_hdmi_i2cm_slave_t I2CM_SLAVE; //!< I2CM_SLAVE
    volatile hw_hdmi_i2cm_address_t I2CM_ADDRESS; //!< I2CM_ADDRESS
    volatile hw_hdmi_i2cm_datao_t I2CM_DATAO; //!< I2CM_DATAO
    volatile hw_hdmi_i2cm_datai_t I2CM_DATAI; //!< I2CM_DATAI
    volatile hw_hdmi_i2cm_operation_t I2CM_OPERATION; //!< I2CM_OPERATION
    volatile hw_hdmi_i2cm_int_t I2CM_INT; //!< I2CM_INT
    volatile hw_hdmi_i2cm_ctlint_t I2CM_CTLINT; //!< I2CM_CTLINT
    volatile hw_hdmi_i2cm_div_t I2CM_DIV; //!< I2CM_DIV
    volatile hw_hdmi_i2cm_segaddr_t I2CM_SEGADDR; //!< I2CM_SEGADDR
    volatile hw_hdmi_i2cm_softrstz_t I2CM_SOFTRSTZ; //!< I2CM_SOFTRSTZ
    volatile hw_hdmi_i2cm_segptr_t I2CM_SEGPTR; //!< I2CM_SEGPTR
    volatile hw_hdmi_i2cm_ss_scl_hcnt_1_addr_t I2CM_SS_SCL_HCNT_1_ADDR; //!< I2CM_SS_SCL_HCNT_1_ADDR
    volatile hw_hdmi_i2cm_ss_scl_hcnt_0_addr_t I2CM_SS_SCL_HCNT_0_ADDR; //!< I2CM_SS_SCL_HCNT_0_ADDR
    volatile hw_hdmi_i2cm_ss_scl_lcnt_1_addr_t I2CM_SS_SCL_LCNT_1_ADDR; //!< I2CM_SS_SCL_LCNT_1_ADDR
    volatile hw_hdmi_i2cm_ss_scl_lcnt_0_addr_t I2CM_SS_SCL_LCNT_0_ADDR; //!< I2CM_SS_SCL_LCNT_0_ADDR
    volatile hw_hdmi_i2cm_fs_scl_hcnt_1_addr_t I2CM_FS_SCL_HCNT_1_ADDR; //!< I2CM_FS_SCL_HCNT_1_ADDR
    volatile hw_hdmi_i2cm_fs_scl_hcnt_0_addr_t I2CM_FS_SCL_HCNT_0_ADDR; //!< I2CM_FS_SCL_HCNT_0_ADDR
    volatile hw_hdmi_i2cm_fs_scl_lcnt_1_addr_t I2CM_FS_SCL_LCNT_1_ADDR; //!< I2CM_FS_SCL_LCNT_1_ADDR
    volatile hw_hdmi_i2cm_fs_scl_lcnt_0_addr_t I2CM_FS_SCL_LCNT_0_ADDR; //!< I2CM_FS_SCL_LCNT_0_ADDR
    reg8_t _reserved31[237];
    volatile hw_hdmi_base_pointer_addr_t BASE_POINTER_ADDR; //!< BASE_POINTER_ADDR
} hw_hdmi_t
#endif

//! @brief Macro to access all HDMI registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_HDMI(0)</code>.
#define HW_HDMI     (*(volatile hw_hdmi_t *) REGS_HDMI_BASE)


#endif // _HDMI_H
