/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "io.h"
#include "audio.h"
#include "imx-ssi.h"
#include "sgtl5000.h"

#define DEBUG_ENABLE	1
#if DEBUG_ENABLE
#define TRACE(fmt, args...)	printf(fmt,##args)
#else
#define TRACE(fmt, args...)
#endif

extern audio_ctrl_t imx_ssi_2;
extern audio_codec_t sgtl5000;
static int snd_card_init(void *priv)
{
    audio_card_p card = (audio_card_p) priv;
    audio_ctrl_p ctrl = card->ctrl;
    audio_codec_p codec = card->codec;

    if (NULL == priv)
        return -1;

    if (0 != ctrl->ops->init((void *)ctrl)) {
        TRACE("Initialize %s failed.\n", ctrl->name);
        return -2;
    }
    if (0 != codec->ops->init((void *)codec)) {
        TRACE("Initialize %s failed.\n", codec->name);
        return -2;
    }

    return 0;
}

static int snd_card_deinit(void *priv)
{
    audio_card_p card = (audio_card_p) priv;
    audio_ctrl_p ctrl = card->ctrl;
    audio_codec_p codec = card->codec;

    if (NULL == priv)
        return -1;

    if (0 != ctrl->ops->deinit((void *)ctrl)) {
        TRACE("De-initialize %s failed.\n", ctrl->name);
        return -1;
    }
    if (0 != codec->ops->deinit((void *)codec)) {
        TRACE("De-initialize %s failed.\n", codec->name);
        return -2;
    }

    return 0;
}

/*!
 *  Default config function for sound card.
  */
static int snd_card_config(void *priv, audio_dev_para_p para)
{
    audio_card_p card = (audio_card_p) priv;
    audio_ctrl_p ctrl = card->ctrl;
    audio_codec_p codec = card->codec;

    if (NULL == priv)
        return -1;

    if (0 != ctrl->ops->config((void *)ctrl, para)) {
        TRACE("Configure %s failed.\n", ctrl->name);
        return -1;
    }
    if (0 != codec->ops->config((void *)codec, para)) {
        TRACE("Configure %s failed.\n", codec->name);
        return -1;
    }

    return 0;
}

static int snd_card_ioctl(void *priv, uint32_t cmd, void *para)
{
    //audio_card_p card = (audio_card_p) priv;
    //audio_ctrl_p ctrl = card->ctrl;
    //audio_codec_p codec = card->codec;

    if (NULL == priv)
        return -1;

    return 0;
}

static int snd_card_write(void *priv, uint8_t * buf, uint32_t bytes2write, uint32_t *bytes_written)
{
    audio_card_p card = (audio_card_p) priv;
    audio_ctrl_p ctrl = card->ctrl;

    ctrl->ops->write((void *)ctrl, buf, bytes2write, bytes_written);

    return 0;
}

static audio_dev_ops_t snd_card_ops = {
    .init = snd_card_init,
    .deinit = snd_card_deinit,
    .config = snd_card_config,
    .ioctl = snd_card_ioctl,
    .write = snd_card_write,
};

audio_card_t snd_card_ssi = {
    .name = "i.MX SSI sound card",
    .codec = &sgtl5000,
    .ctrl = &imx_ssi_2,
    .ops = &snd_card_ops,       //TODO
};
audio_card_t snd_card_esai = {
    .name = "i.MX EASI sound card",
    .codec = NULL,
    .ctrl = NULL,
    .ops = NULL,                //TODO
};
audio_card_t snd_card_spdif = {
    .name = "i.MX SPDIF sound card",
    .codec = NULL,
    .ctrl = NULL,
    .ops = NULL,                //TODO
};
