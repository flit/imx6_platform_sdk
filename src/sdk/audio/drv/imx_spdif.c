/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_spdif.c
 * @brief Driver for spdif controller.
 *
 * @ingroup diag_audio
 */

#include "hardware.h"
#include "functions.h"
#include "../inc/audio.h"
#include "imx_spdif.h"

#define SPDIF_DEBUG 0

#if SPDIF_DEBUG
#define D(fmt,args...) printf(fmt, ## args)
#else
#define D(fmt,args...)
#endif

extern void iomux_config_spdif(void);
extern void spdif_clk_cfg(void);
extern unsigned int spdif_get_tx_clk_freq(void);

#if SPDIF_DEBUG
static int32_t spdif_dump(audio_ctrl_p ctrl)
{
    volatile imx_spdif_regs_p spdif = (imx_ssi_regs_p) (ctrl->base_addr);

    printf("=================%s dump==================\n", ctrl->name);

    printf("SCR       :0x%x", spdif->scr);
    printf("SRCD      :0x%x", spdif->srcd);
    printf("SRPC      :0x%x", spdif->srpc);
    printf("SIE       :0x%x", spdif->sie);
    printf("SIS       :0x%x", spdif->sis);
    printf("SRCSLH    :0x%x", spdif->srcsh);
    printf("SRCSLL    :0x%x", spdif->srcsl);
    printf("SQU       :0x%x", spdif->sru);
    printf("SRQ       :0x%x", spdif->srq);
    printf("STCSCH    :0x%x", spdif->stcsch);
    printf("STCSCL    :0x%x", spdif->stcscl);
    printf("SRFM      :0x%x", spdif->srfm);
    printf("STC       :0x%x", spdif->stc);

    return 0;
}
#else
static int32_t spdif_dump(audio_ctrl_p ctrl)
{
    return 0;
}
#endif

/*! 
 * Put the spdif to soft-reset mode, and then can be configured.
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the ssi module
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
static int32_t spdif_soft_reset(audio_ctrl_p ctrl)
{
    volatile imx_spdif_regs_p spdif = (imx_spdif_regs_p) (ctrl->base_addr);

    int cycle = 0;

    spdif->scr |= SCR_SOFT_RESET;

    while ((spdif->scr & 0x1000) && (cycle++ < 50)) ;

    return 0;
}

/*!
 * Get the spdif's settings.
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the ssi module
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
static uint32_t spdif_get_hw_setting(audio_ctrl_p ctrl, uint32_t type)
{
    volatile imx_spdif_regs_p spdif = (imx_spdif_regs_p) (ctrl->base_addr);
    uint32_t val = 0;

    switch (type) {
    case SPDIF_GET_FREQMEAS:
        val = spdif->srfm;
        break;
    case SPDIF_GET_GAIL_SEL:
        val = (spdif->srpc & (0x7 << 3)) >> 3;
        break;
    case SPDIF_GET_RX_CCHANNEL_INFO_H:
        val = spdif->srcsh;
        break;
    case SPDIF_GET_RX_CCHANNEL_INFO_L:
        val = spdif->srcsl;
        break;
    case SPDIF_GET_RX_UCHANNEL_INFO:
        val = spdif->sru;
        break;
    case SPDIF_GET_RX_QCHANNEL_INFO:
        val = spdif->srq;
        break;
    case SPDIF_GET_INT_STATUS:
        val = spdif->sis;
    }

    return val;
}

static uint32_t spdif_cal_txclk_div(audio_ctrl_p ctrl, uint32_t sample_rate)
{
    float val;

    val = (float)spdif_get_tx_clk_freq() / (float)sample_rate + 0.5f;

    return (uint32_t) val;
}

//////////////////////////////////////// APIs //////////////////////////////////////////////////////////////

/*!
 * Initialize the spdif module and set the ssi to default status. 
 * This function will be called by the snd_card driver. 
 *
 * @param       priv    a pointer passed by audio card driver, spdif driver should change it 
 *			to a audio_ctrl_p pointer which presents the spdif controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t spdif_init(void *priv)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;

    iomux_config_spdif();
    spdif_soft_reset(ctrl);
    spdif_clk_cfg();

    return 0;
}

/*!
 * Configure the spdif module according the parameters which was passed by audio_card driver.
 *
 * @param       priv    a pointer passed by audio card driver, spdif driver should change it
 *                      to a audio_ctrl_p pointer which presents the spdif controller.
 *				para	a pointer passed by audio card driver, consists of configuration parameters
 *						for spdif controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t spdif_config(void *priv, audio_dev_para_p para)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_spdif_regs_p spdif = (imx_spdif_regs_p) (ctrl->base_addr);
    iec958_cchannel_t cchannel;
    uint32_t val;

    /* Set channel information */
    memset(&cchannel, 0, sizeof(cchannel));
    cchannel.h.ctrl.audio_format = IEC958_CON_AUDIO_PCM;
    cchannel.h.ctrl.copyright = IEC958_CON_COPYRIGHT_NONE;
    cchannel.h.ctrl.add_info = IEC958_CON_EMPHASIS_5015;
    cchannel.h.ctrl.channel_mode = IEC958_CON_CHANNEL_MODE0;
    cchannel.h.ctrl.source_number = IEC958_CON_SOURCE_NUMBER_2;

    cchannel.l.ctrl.clock_accuracy = IEC958_CON_CLOCK_ACCURACY_LEVEL2;

    if (para->sample_rate == SAMPLERATE_44_1KHz)
        cchannel.l.ctrl.sample_freq = IEC958_CON_SAMPLE_FREQ_44100;
    else if (para->sample_rate == SAMPLERATE_32KHz)
        cchannel.l.ctrl.sample_freq = IEC958_CON_SAMPLE_FREQ_32000;
    else                        //48K
        cchannel.l.ctrl.sample_freq = IEC958_CON_SAMPLE_FREQ_48000;

    if (para->word_length == WL_16) // 16 bits
    {
        cchannel.l.ctrl.max_len = IEC958_CON_MAX_LENGTH_20;
        cchannel.l.ctrl.sample_len = IEC958_CON_SAMPLE_LENGTH_20_16;    //IEC958_CON_SAMPLE_LENGTH_20_16;
    } else                      //wBitsPerSample == 24, 32
    {
        cchannel.l.ctrl.max_len = IEC958_CON_MAX_LENGTH_24;
        cchannel.l.ctrl.sample_len = IEC958_CON_SAMPLE_LENGTH_24_20;    //IEC958_CON_SAMPLE_LENGTH_24_20;
    }
    spdif->stcsch = cchannel.h.data;
    spdif->stcscl = cchannel.l.data;

    val = spdif->scr;
    val |=
        SCR_USRC_SEL_NONE | SCR_TXSEL_NORMAL | SCR_VAL_CLEAR | SCR_TXFIFO_NORMAL |
        SCR_TXFIFO_AUTOSYNC | SCR_TXFIFO_ESEL_8_SAMPLE;
    spdif->scr = val;

    val = spdif->stc;
    val |= TX_CLK_SEL_SPDIF0_CLK << STC_TXCLK_SRC_OFFSET;
    val |= spdif_cal_txclk_div(ctrl, para->sample_rate) << STC_TXCLK_DIV_OFFSET;
    val |= STC_TX_ALL_CLK_ON;
    spdif->stc = val;

    return 0;
}

/*!
 * Write datas to the spdif fifo in polling mode.
 * @param       priv    a pointer passed by audio card driver, spdif driver should change it
 *                      to a audio_ctrl_p pointer which presents the spdif controller.
 *		buf	points to the buffer which hold the data to be written to the spdif tx fifo
 *		size    the size of the buffer pointed by buf.
 *		bytes_written	bytes be written to the spdif tx fifo
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t spdif_write_fifo(void *priv, uint8_t * buf, uint32_t size, uint32_t * bytes_written)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_spdif_regs_p spdif = (imx_spdif_regs_p) (ctrl->base_addr);
    int i;

    while (i < size) {
        if (spdif->sis & INT_TX_EMPTY) {
            spdif->stl = *((uint16_t *) (buf + i));
            spdif->str = *((uint16_t *) (buf + i));
            i += 2;
        }
    }

    *bytes_written = size;

    return 0;
}

/*!
 * Close the spdif module
 * @param       priv    a pointer passed by audio card driver, spdif driver should change it
 *                      to a audio_ctrl_p pointer which presents the spdif controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t spdif_deinit(void *priv)
{
    return 0;
}

static audio_dev_ops_t spdif_ops = {
    .init = spdif_init,
    .deinit = spdif_deinit,
    .config = spdif_config,
    .ioctl = NULL,
    .write = spdif_write_fifo,
};

audio_ctrl_t imx_spdif = {
    .name = "imx SPDIF audio controller",
    .base_addr = SPDIF_BASE_ADDR,
    .ops = &spdif_ops,
};
