/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ssi_playback.c
 * @brief SSI test example.
 *
 */

#include "io.h"
#include "../inc/audio.h"
#include "../inc/snd_card.h"
#include "wav_data.data"

int ssi_playback(void)
{
    int result;
    uint32_t bytes_written = 0;
    uint8_t recvCh = 0;

    while (1) {
        printf("Please plug in headphones to the HEADPHONE OUT jack.\n");
        do {
            recvCh = (uint8_t) getchar();
        }
        while (recvCh == 0xFF);

        if ((recvCh == 'Y') || (recvCh == 'y'))
            continue;
        else
            break;
    }

    audio_card_p card = &snd_card_ssi;

    card->ops->init(card);

    card->ops->config(card, NULL);

    while (1) {

        card->ops->write(card, (uint8_t *) wav_data, sizeof(wav_data), &bytes_written);

        do {
            recvCh = (uint8_t) getchar();
        }
        while (recvCh == 0xFF);

        if ((recvCh == 'Y') || (recvCh == 'y'))
            continue;           /* hear again */
        else
            break;              /* by pass */
    }

    printf(" Do you hear audio from headphone? (y/n)\n");

    do {
        recvCh = (uint8_t) getchar();
    }
    while (recvCh == 0xFF);

    if ((recvCh == 'y') || (recvCh == 'Y'))
        result = 0;             /* If user types 'Y' or 'y' test passed */
    else
        result = -1;            /* Else test failed */

    card->ops->deinit(card);

    return result;
}
