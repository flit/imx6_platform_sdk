/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "sdk.h"
#include "hardware.h"

#define SSI_WRITE_TIMEOUT	0x400000

#if (defined(CHIP_MX6SL) && defined(BOARD_EVB))
//#define 	WM8962_I2C_UNSTABLE
#endif

extern audio_pcm_t pcm_music;
extern audio_pcm_para_t pcm_para;

uint8_t audio_record_buf[AUDIO_RECORD_BUF_LEN] __attribute__ ((aligned(4)));
audio_pcm_t pcm_record = {
    .name = "Record",
    .buf = audio_record_buf,
    .size = sizeof(audio_record_buf),
    .para = &pcm_para
};

extern void audio_codec_power_on(void);
extern void audio_clock_config(void);

audio_card_p snd_card;

extern audio_card_t snd_card_ssi_sgtl5000;
extern audio_card_t snd_card_ssi_wm8958;
extern audio_card_t snd_card_ssi_wm8962;

/* This function initializes AUDMUX for SSI2, and Audio Codec */
int audio_test_init(void)
{
    audio_dev_para_t dev_para;

    //Default 
    snd_card = &snd_card_ssi_sgtl5000;

#if defined(BOARD_SMART_DEVICE)
#if defined(BOARD_VERSION1)
    snd_card = &snd_card_ssi_wm8958;
#endif
#if defined(BOARD_VERSION2)
    snd_card = &snd_card_ssi_wm8962;
#endif
#endif

#if defined(BOARD_SABRE_LITE)
    snd_card = snd_card_ssi_sgtl5000;
#endif
#if (defined(CHIP_MX6SL) && defined(BOARD_EVB))
    snd_card = snd_card_ssi_wm8962;
#endif

#if defined(BOARD_SMART_DEVICE) || (defined(CHIP_MX6SL) && defined(BOARD_EVB))
    audmux_route(AUDMUX_PORT_2, AUDMUX_PORT_3, AUDMUX_SSI_MASTER);
    dev_para.bus_mode = AUDIO_BUS_MODE_MASTER;
#endif

#if defined(BOARD_SABRE_LITE)
    /*SABRE_LITE board used audumx_port4 to conncet sgtl500 */
    audmux_route(AUDMUX_PORT_2, AUDMUX_PORT_4, AUDMUX_SSI_SLAVE);
    dev_para.bus_mode = AUDIO_BUS_MODE_SLAVE;
#endif
    //Config SSI 
    dev_para.bus_protocol = AUDIO_BUS_PROTOCOL_I2S;
    dev_para.sample_rate = SAMPLERATE_48KHz;
    dev_para.word_length = WL_16;
    dev_para.trans_dir = AUDIO_TRANS_DIR_TX;

    if (0 != snd_card->ops->init(snd_card)) {
        printf("Init %s failed.\n", snd_card->name);
        return -1;
    }
    printf("SSI port2 initialized\n");

    if (0 != snd_card->ops->config(snd_card, &dev_para)) {
        printf("The codec %s failed to be configured.\n", snd_card->name);
        return -1;
    }

    return 0;
}

int i2s_audio_test_enable;

/* 	This function sends square wave data to I2S data in of SGTL5000 and output through headphone.
	make sure SSI port has been initialized
*/
int i2s_audio_test(void)
{
    char recvCh;
    uint32_t bytes_written = 0;
//    int time_out = SSI_WRITE_TIMEOUT;

    if (!i2s_audio_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("I2S AUDIO");

    printf("Please plug in headphones to the HEADPHONE OUT jack\n");

    if (!is_input_char('y')) {
        printf(" Skip AUDIO test \n");
        return TEST_BYPASSED;
    }
    //printf("To power code on\n");
    audio_codec_power_on();     // in hardware.c
    //hal_delay_us(1000*1000);
    //printf("Audio codec powered.\n");
    audio_clock_config();
    //printf("Audio clock configed.\n");

    if (0 != audio_test_init()) {
        printf("Initialization of audio subsystem failed\n");
        return TEST_FAILED;
    }

    printf("Audio output: please ensure headphones are plugged in to hear \n");
    printf("If you hear the sound, enter Y to exit. Or press any other key to try it again.\n");

    while (1) {
        if (snd_card->ops->write(snd_card, pcm_music.buf, pcm_music.size, &bytes_written) < 0) {
            printf("Write to SSI timeout\n");
            return TEST_FAILED;
        }

        printf(" Do you need to re-hear it? (y/n)\n");

        do {
            recvCh = getchar();
        }
        while (recvCh == 0xFF);

        if ((recvCh == 'Y') || (recvCh == 'y'))
            continue;           /* hear again */
        else
            break;              /* by pass */
    }

    printf(" Do you hear audio from headphone? (y/n)\n");

    do {
        recvCh = getchar();
    }
    while (recvCh == 0xFF);

    if ((recvCh == 'y') || (recvCh == 'Y')) {
        printf(" SSI playback test passed.\n");
    } else {
        printf(" SSI playback test failed.\n");
        return TEST_FAILED;
    }

#if (defined(CHIP_MX6SL) && defined(BOARD_EVB)) || (defined(BOARD_SMART_DEVICE) && defined(BOARD_VERSION2))
#if !defined(WM8962_I2C_UNSTABLE)
    printf(" Audio input: please ensure micphone is plugged in. Press 'y/Y' to confirm.\n");
    do {
        recvCh = getchar();
    }
    while (recvCh == 0xFF);

    if ((recvCh == 'y') || (recvCh == 'Y')) {
        printf(" Start recording...\n");
        if (snd_card->ops->read(snd_card, pcm_record.buf, pcm_record.size, &bytes_written) > 0) {
            printf("Read SSI fifo timeout.\n");
            return TEST_FAILED;
        }

        printf(" Start playbacking the voice just recorded...\n");
        if (snd_card->ops->write(snd_card, pcm_record.buf, pcm_record.size, &bytes_written) > 0) {
            printf("Write SSI fifo timeout.\n");
            return TEST_FAILED;
        }
        printf(" Do you hear voice from headphone? (y/n)\n");

        do {
            recvCh = getchar();
        }
        while (recvCh == 0xFF);

        if ((recvCh == 'y') || (recvCh == 'Y')) {
            printf(" SSI record test passed.\n");
        } else {
            printf(" SSI record test failed.\n");
            return TEST_FAILED;
        }
    }
#endif
#endif

    return TEST_PASSED;
}

//RUN_TEST_INTERACTIVE("I2S AUDIO", i2s_audio_test)
