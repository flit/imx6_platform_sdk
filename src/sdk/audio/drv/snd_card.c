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

int snd_card_init(audio_card_p card)
{
	return 0;
}

int snd_card_deinit(audio_card_p card)
{
	return 0;
}

int snd_card_config(audio_card_p card, void *para)
{
	return 0;
}

int snd_card_ioctl(void *priv, uint32_t cmd, void *para)
{
	audio_card_p card = (audio_card_p)priv;

	return 0;
}

int snd_card_write(void *priv, uint8_t buf, uint32_t bytes2write, uint32_t bytes_written)
{
	audio_card_p card = (audio_card_p)priv;

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
	.ctrl = &imx_ssi_1,
	.ops = &snd_card_ops,	//TODO
};
audio_card_t snd_card_esai = {
	.name = "i.MX EASI sound card",
	.codec = NULL,
	.ctrl = NULL,
	.ops = NULL,	//TODO
};
audio_card_t snd_card_spdif = {
	.name = "i.MX SPDIF sound card",
	.codec = NULL,
	.ctrl = NULL,
	.ops = NULL,	//TODO
};
