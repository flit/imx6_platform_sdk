
/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_spdif.h
 * @brief Header file for spdif driver.
 *
 * @ingroup diag_audio
 */

#ifndef __IMX_SPDIF_H__
#define __IMX_SPDIF_H__

/* Register fields */
#define SCR_RXFIFO_FSEL_BIT	(19)
#define SCR_RXFIFO_FSEL_MASK	(0x3 << SCR_RXFIFO_FSEL_BIT)
#define SCR_TXFIFO_ESEL_BIT	(15)
#define SCR_TXFIFO_ESEL_MASK	(0x3 << SCR_TXFIFO_ESEL_BIT)
#define SCR_TXFIFO_ESEL_0_SAMPLE	(0x0 << SCR_TXFIFO_ESEL_BIT)
#define SCR_TXFIFO_ESEL_4_SAMPLE	(0x1 << SCR_TXFIFO_ESEL_BIT)
#define SCR_TXFIFO_ESEL_8_SAMPLE	(0x2 << SCR_TXFIFO_ESEL_BIT)
#define SCR_TXFIFO_ESEL_12_SAMPLE	(0x3 << SCR_TXFIFO_ESEL_BIT)
#define SCR_TXFIFO_ZERO		(0 << 10)
#define SCR_TXFIFO_NORMAL	(1 << 10)
#define SCR_VAL_CLEAR		(1 << 5)
#define SCR_TXSEL_OFF		(0 << 2)
#define SCR_TXSEL_RX		(1 << 2)
#define SCR_TXSEL_NORMAL	(0x5 << 2)
#define SCR_USRC_SEL_NONE	(0x0)
#define SCR_USRC_SEL_RECV	(0x1)
#define SCR_USRC_SEL_CHIP	(0x3)

typedef enum {
    CLK_TO_MEAS_RXCLK_EXTAL = 0,
    CLK_TO_MEAS_RXCLK_SPDIF_CLK,
    CLK_TO_MEAS_RXCLK_ASRC_CLK,
    CLK_TO_MEAS_RXCLK_SPDIF_EXTCLK,
    CLK_TO_MEAS_RXCLK_ESAI_HCKT,
    CLK_TO_MEAS_EXTAL_CLK,
    CLK_TO_MEAS_SPDIF_CLK,
    CLK_TO_MEAS_ASRC_CLK,
    CLK_TO_MEAS_SPDIF_EXTCLK,
    CLK_TO_MEAS_ESAI_HCKT,
    CLK_TO_MEAS_RXCLK_MLB_CLK,
    CLK_TO_MEAS_RXCLK_MLB_PHY_CLK,
    CLK_TO_MEAS_MKB_CLK,
    CLK_TO_MEAS_PHY_CLK,
} spdif_clk_to_meas_e;

enum spdif_gainsel {
    GAINSEL_MULTI_24 = 0,
    GAINSEL_MULTI_16,
    GAINSEL_MULTI_12,
    GAINSEL_MULTI_8,
    GAINSEL_MULTI_6,
    GAINSEL_MULTI_4,
    GAINSEL_MULTI_3,
    GAINSEL_MULTI_MAX,
};

#define SPDIF_DEFAULT_GAINSEL	GAINSEL_MULTI_8

typedef enum {
    TX_CLK_SEL_XTAL0 = 0,
    TX_CLK_SEL_SPDIF0_CLK,
    TX_CLK_SEL_ASRC_CLK,
    TX_CLK_SEL_SPDIF_EXTCLK,
    TX_CLK_SEL_ESAI_HCKT,
    TX_CLK_SEL_IPG_CLK_DIVIDED,
    TX_CLK_SEL_MLB_CLK,
    TX_CLK_SEL_MLB_PHY_CLK,
} spdif_tx_clk_sel_e;

#define SPDIF_CSTATUS_BYTE	6
#define SPDIF_UBITS_SIZE	96
#define SPDIF_QSUB_SIZE		(SPDIF_UBITS_SIZE/8)

//------------------------------------------------------------------------------
// Channel Status for Consumer use according to IEC60959-3
//------------------------------------------------------------------------------
typedef struct {
    union {
        uint32_t data;
        struct {
            uint32_t channel_number:4;  //cs-channel.23-20
            uint32_t source_number:4;
            uint32_t category_code:8;
            uint32_t channel_mode:2;
            uint32_t add_info:3;
            uint32_t copyright:1;
            uint32_t audio_format:1;
            uint32_t channel_status:1;  //cs-channel.0
            uint32_t dummy:8;
        } ctrl;
    } h;                        //bits [0:23] of c channel
    //todo : need check if place of h,l right?
    union {
        uint32_t data;
        struct {
            uint32_t dummy1:6;
            uint32_t cgms_a:2;
            uint32_t orig_sample_freq:4;
            uint32_t sample_len:3;
            uint32_t max_len:1;
            uint32_t dummy4:2;
            uint32_t clock_accuracy:2;
            uint32_t sample_freq:4;
            uint32_t dummy5:8;
        } ctrl;
    } l;                        //bits [24:47] of c channel

} iec958_cchannel_t, *iec958_cchannel_p;

#define IEC958_CON_CTRL_CONS        (0x0 << 0)  //Consumer use of channel status block
#define IEC958_CON_AUDIO_PCM        (0x0 << 0)
#define IEC958_CON_AUDIO_COMPRESSED (0x1 << 0)
#define IEC958_CON_COPYRIGHT_NONE   (0x0 << 0)
#define IEC958_CON_COPYRIGHT_WITH   (0x1 << 0)
#define IEC958_CON_EMPHASIS_NONE    (0x0 << 0)
#define IEC958_CON_EMPHASIS_5015    (0x4 << 0)
#define IEC958_CON_EMPHASIS_RESV    (0x2 << 0)
#define IEC958_CON_CHANNEL_MODE0    (0x0 << 0)

#define IEC958_CON_SOURCE_NUMBER_0  (0x0 << 0)
#define IEC958_CON_SOURCE_NUMBER_1  (0x8 << 0)
#define IEC958_CON_SOURCE_NUMBER_2  (0x4 << 0)
#define IEC958_CON_SOURCE_NUMBER_3  (0xc << 0)
#define IEC958_CON_SOURCE_NUMBER_4  (0x2 << 0)
#define IEC958_CON_SOURCE_NUMBER_5  (0xa << 0)
#define IEC958_CON_SOURCE_NUMBER_6  (0x6 << 0)
#define IEC958_CON_SOURCE_NUMBER_7  (0xe << 0)
#define IEC958_CON_SOURCE_NUMBER_8  (0x1 << 0)
#define IEC958_CON_SOURCE_NUMBER_9  (0x9 << 0)
#define IEC958_CON_SOURCE_NUMBER_10 (0x5 << 0)
#define IEC958_CON_SOURCE_NUMBER_11 (0xd << 0)
#define IEC958_CON_SOURCE_NUMBER_12 (0x3 << 0)
#define IEC958_CON_SOURCE_NUMBER_13 (0xb << 0)
#define IEC958_CON_SOURCE_NUMBER_14 (0x7 << 0)
#define IEC958_CON_SOURCE_NUMBER_15 (0xf << 0)

#define IEC958_CON_SAMPLE_FREQ_44100 (0x0 << 0)
#define IEC958_CON_SAMPLE_FREQ_48000 (0x4 << 0)
#define IEC958_CON_SAMPLE_FREQ_32000 (0xc << 0)

#define IEC958_CON_CLOCK_ACCURACY_LEVEL2 (0x0 << 0)
#define IEC958_CON_CLOCK_ACCURACY_LEVEL1 (0x2 << 0)
#define IEC958_CON_CLOCK_ACCURACY_LEVEL3 (0x1 << 0)
#define IEC958_CON_CLOCK_ACCURACY_RSV    (0x3 << 0)

#define IEC958_CON_MAX_LENGTH_20         (0x0 << 0)
#define IEC958_CON_MAX_LENGTH_24         (0x1 << 0)

#define IEC958_CON_SAMPLE_LENGTH_NODEFINED  (0x0 << 0)
#define IEC958_CON_SAMPLE_LENGTH_20_16   (0x4 << 0)
#define IEC958_CON_SAMPLE_LENGTH_22_18   (0x2 << 0)
#define IEC958_CON_SAMPLE_LENGTH_23_19   (0x1 << 0)
#define IEC958_CON_SAMPLE_LENGTH_24_20   (0x5 << 0)
#define IEC958_CON_SAMPLE_LENGTH_21_17   (0x3 << 0)

typedef enum {
    SPDIF_GET_FREQMEAS = 0,
    SPDIF_GET_GAIN_SEL,
    SPDIF_GET_RX_CCHANNEL_INFO_H,
    SPDIF_GET_RX_CCHANNEL_INFO_L,
    SPDIF_GET_RX_UCHANNEL_INFO,
    SPDIF_GET_RX_QCHANNEL_INFO,
    SPDIF_GET_INT_STATUS,
} spdif_get_setting_e;

typedef enum {
    SPDIF_HW_SETTING_SCR = 0,
    SPDIF_HW_SETTING_USYNCMODE,
    SPDIF_HW_SETTING_TX_CHANNEL_INFO_H,
    SPDIF_HW_SETTING_TX_CHANNEL_INFO_L,
    SPDIF_HW_SETTING_TX_CLK_CFG,
} spdif_set_hw_setting_e;

static uint32_t spdif_cal_txclk_div(audio_ctrl_p ctrl, uint32_t sample_rate);
static uint32_t spdif_cal_txclk_div(audio_ctrl_p ctrl, uint32_t sample_rate);

#endif //__IMX_SPDIF_H__
