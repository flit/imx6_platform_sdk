/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "sdk.h"
#include "hardware.h"
#include "audio/audio.h"
#include "audio/imx-audmux.h"

/*
 * For smart_device board only.
 */
extern audio_card_t snd_card_ssi_wm8962;
extern void audio_codec_power_on(void);
extern void audio_clock_config(void);

int32_t ssi_playback(audio_pcm_p pcm_file)
{
    uint8_t recvCh;
    int32_t result;
    uint32_t bytes_written = 0;
    audio_dev_para_t dev_para;
    audio_card_p snd_card = &snd_card_ssi_wm8962;

    printf("Please ensure headphones are plugged in to hear.\n");

    if (!is_input_char('y', NULL)) {
        printf("  skip AUDIO test \n");
        return TEST_BYPASSED;
    }
    
    audio_codec_power_on();
    audio_clock_config();

    audmux_route(AUDMUX_PORT_2, AUDMUX_PORT_3, AUDMUX_SSI_MASTER);
    dev_para.bus_mode = AUDIO_BUS_MODE_MASTER;

    dev_para.bus_protocol = AUDIO_BUS_PROTOCOL_I2S;
    dev_para.sample_rate = SAMPLERATE_48KHz;
    dev_para.word_length = WL_16;
    dev_para.trans_dir = AUDIO_TRANS_DIR_TX;

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
