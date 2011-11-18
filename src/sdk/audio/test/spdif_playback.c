/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file spdif_playback.c
 * @brief SPDIF test example
 *
 */

#include <stdio.h>
#include "io.h"
#include "hardware.h"
#include "../inc/audio.h"

extern audio_card_t snd_card_spdif;

int32_t spdif_playback(audio_pcm_p pcm_file)
{
    uint8_t recvCh;
    int32_t result;
    uint32_t bytes_written = 0;
    audio_dev_para_t dev_para;
    audio_card_p snd_card = &snd_card_spdif;

    printf("Please make sure : \n");
    printf(" 1. The EVB board was mounted on the MX6QVPC board. \n");
    printf
        (" 2. A rework should be done to connect \"TP6[SPDIF_OUT]\" with \"PORT2_P98\" on the MX6QVPC board\n");
    printf
        (" 3. The \"SPDIF_OUT\" socket and your PC are connected using a SPDIF recording device, such as \"M-AUDIO\".\n");
    printf(" 4. The recording program is running on your PC and ready to record.\n");
    if (!is_input_char('y')) {
        printf("  skip AUDIO test \n");
        return TEST_BYPASSED;
    }

    dev_para.bus_mode = AUDIO_BUS_MODE_SLAVE;
    dev_para.bus_protocol = AUDIO_BUS_PROTOCOL_I2S;
    dev_para.sample_rate = pcm_file->para->sample_rate;
    dev_para.word_length = pcm_file->para->word_length;
    dev_para.trans_dir = AUDIO_TRANS_DIR_TX;

    if (0 != snd_card->ops->init(snd_card)) {
        printf("Init %s failed.\n", snd_card->name);
        return -1;
    }
    if (0 != snd_card->ops->config(snd_card, &dev_para)) {
        printf("Configure %s failed.\n", snd_card->name);
        return -1;
    }

    uint32_t cnt;
    while (1) {
        cnt = 2;
        while (cnt--) {
            snd_card->ops->write(snd_card, pcm_file->buf, pcm_file->size, &bytes_written);
        }

        printf(" Do you need to re-play it? (y/n)\n");

        do {
            recvCh = getchar();
        }
        while (recvCh == (uint8_t) 0xFF);

        if ((recvCh == 'Y') || (recvCh == 'y'))
            continue;           /* hear again */
        else
            break;              /* by pass */
    }

    printf(" Please replay the audio file just recorded on your PC. Do you hear audio? (y/n)\n");

    do {
        recvCh = getchar();
    }
    while (recvCh == (uint8_t) 0xFF);

    if ((recvCh == 'y') || (recvCh == 'Y'))
        result = 0;             /* If user types 'Y' or 'y' test passed */
    else
        result = -1;            /* Else test failed */

    return result;

    return true;
}
