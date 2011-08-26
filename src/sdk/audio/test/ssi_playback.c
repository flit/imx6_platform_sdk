/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "io.h"
#include "../inc/audio.h"
#include "../inc/imx-ssi.h"
#include "../inc/imx-audmux.h"

extern audio_codec_t sgtl5000;
extern audio_ctrl_t imx_ssi_2;
audio_codec_p codec = &sgtl5000;
audio_ctrl_p ctrl = &imx_ssi_2;

void autio_test_init(void)
{
    audio_dev_para_t dev_para;

    audmux_route(AUDMUX_PORT_2, AUDMUX_PORT_5, AUDMUX_SSI_SLAVE);

    dev_para.bus_mode = AUDIO_BUS_MODE_SLAVE;
    dev_para.bus_protocol = AUDIO_BUS_PROTOCOL_I2S;
    dev_para.sample_rate = SAMPLERATE_48KHz;
    dev_para.word_length = WL_16;
    dev_para.trans_dir = AUDIO_TRANS_DIR_TX;

    ctrl->ops->init(ctrl);
    ctrl->ops->config(ctrl, &dev_para);

    dev_para.bus_mode = AUDIO_BUS_MODE_MASTER;
    dev_para.trans_dir = AUDIO_TRANS_DIR_RX;
    codec->ops->init(codec);
    codec->ops->config(codec, &dev_para);
}

int ssi_playback(audio_pcm_p pcm_file)
{
    char recvCh;
    int result;
    uint32_t bytes_written = 0;

    printf("Please plug in headphones to the HEADPHONE OUT jack\n");

    if (!is_input_char('y')) {
        printf("  skip AUDIO test \n");
        return TEST_BYPASSED;
    }

    autio_test_init();

    printf("Audio output: please ensure headphones are plugged in to hear \n");
    printf("If you hear the sound, enter Y to exit. Or press any other key to try it again.\n");

    while (1) {
        ctrl->ops->write(ctrl, pcm_file->buf, pcm_file->size, &bytes_written);

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

    printf(" Do you hear audio from headphone?? (y/n)\n");

    do {
        recvCh = getchar();
    }
    while (recvCh == (uint8_t) 0xFF);

    if ((recvCh == 'y') || (recvCh == 'Y'))
        result = 0;             /* If user types 'Y' or 'y' test passed */
    else
        result = -1;            /* Else test failed */

    if (result == 0) {
        return TEST_PASSED;
    } else {
        return TEST_FAILED;
    }

    return result;
}
