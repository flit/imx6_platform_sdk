/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file esai_playback.c
 * @brief ESAI test example
 *
 */

#include <stdio.h>
#include "io.h"
#include "hardware.h"
#include "../inc/audio.h"

extern audio_card_t snd_card_esai;

int32_t esai_playback(audio_pcm_p pcm_file)
{
    uint8_t recvCh;
    int32_t result;
    uint32_t bytes_written = 0;
    audio_card_p snd_card = &snd_card_esai;
    audio_dev_para_t dev_para;

    dev_para.bus_mode = AUDIO_BUS_MODE_MASTER;
    dev_para.trans_dir = AUDIO_TRANS_DIR_TX;
    dev_para.sample_rate = pcm_file->para->sample_rate;
    dev_para.word_length = pcm_file->para->word_length;
    dev_para.channel_number = pcm_file->para->channel_number;

    printf("Please ensure:\n");
    printf
        (" 1. i.MX61_ARD board and the Automotive Card are both mounted to the ARMADILLO 2 board.\n");
    printf
        (" 2. The converting cable's two plugs were plugged into the Automotive Card's AOUT1 and AOUT2 sockets.\n");
    printf(" 3. The headphone is plugged into the converting cable's socket.\n");
    if (!is_input_char('y')) {
        printf("  skip AUDIO test \n");
        return TEST_BYPASSED;
    }

    if (0 != snd_card->ops->init(snd_card)) {
        printf("Init %s failed.\n", snd_card->name);
        return -1;
    }
    if (0 != snd_card->ops->config(snd_card, &dev_para)) {
        printf("Configure %s failed.\n", snd_card->name);
        return -1;
    }

    while (1) {
        snd_card->ops->write(snd_card, pcm_file->buf, pcm_file->size, &bytes_written);
        printf(" Do you need to re-hear it? (y/n)\n");

        do {
            recvCh = getchar();
        }
        while (recvCh == (uint8_t) 0xFF);

        if ((recvCh == 'Y') || (recvCh == 'y'))
            continue;           /* hear again */
        else
            break;              /* by pass */
    }

    printf(" Do you hear audio from headphone? (y/n)\n");

    do {
        recvCh = getchar();
    }
    while (recvCh == (uint8_t) 0xFF);

    if ((recvCh == 'y') || (recvCh == 'Y'))
        result = 0;             /* If user types 'Y' or 'y' test passed */
    else
        result = -1;            /* Else test failed */

    return result;
}
