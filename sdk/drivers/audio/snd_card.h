/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#ifndef _SND_CARD_H_
#define _SND_CARD_H_

#include "audio.h"

//! @brief i.MX SSI sound card - sgtl5000
extern audio_card_t snd_card_ssi_sgtl5000;

//! @brief i.MX SSI sound card - wm8958
extern audio_card_t snd_card_ssi_wm8958;

//! @brief i.MX SSI sound card - wm8962
extern audio_card_t snd_card_ssi_wm8962;

//! @brief i.MX ESAI sound card - cs42888
extern audio_card_t snd_card_esai;

//! @brief i.MX SPDIF sound card
extern audio_card_t snd_card_spdif;

#endif //_SND_CARD_H_
