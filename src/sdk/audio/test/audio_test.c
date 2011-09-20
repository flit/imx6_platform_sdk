/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "io.h"
#include "../inc/audio.h"
#include "wav_data.data"

extern int32_t ssi_playback(audio_pcm_p);
extern int32_t esai_playback(audio_pcm_p);
extern int32_t spdif_playback(audio_pcm_p);

typedef struct {
    const char *name;
    int32_t (*test) (audio_pcm_p);
} audio_test_t;

audio_pcm_para_t pcm_para = {
    .sample_rate = SAMPLERATE_44_1KHz,
    .channel_number = 2,
    .word_length = WL_16,
};

audio_pcm_t pcm_music = {
    .name = "some noise",
    .para = &pcm_para,
    .buf = (uint8_t *) wav_data,
    .size = sizeof(wav_data),
};

static audio_test_t audio_tests[] = {
    {"SSI playback", ssi_playback},
    {"ESAI playback", esai_playback},
    {"SPDIF playback", spdif_playback},
};

int32_t audio_test(void)
{
    int32_t retv, idx;
    uint8_t sel;

    printf("\n--- Running audio test, type 'x' to exit.\n");

    do {
        printf("Please select test type:\n");
        for (idx = 0; idx < (sizeof(audio_tests) / sizeof(audio_test_t)); idx++) {
            printf("\t%d - %s\n", idx, audio_tests[idx].name);
        }

        do {
            sel = (uint8_t) getchar();
        } while (sel == (uint8_t) 0xFF);
        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }
        idx = sel - '0';

        if ((idx >= 0) && (idx < (sizeof(audio_tests) / sizeof(audio_test_t)))) {
            printf("\n");
            retv = audio_tests[idx].test(&pcm_music);
            if (0 == retv) {
                printf("\n%s test PASSED.\n", audio_tests[idx].name);
            } else {
                printf("\n%s test FAILED.\n", audio_tests[idx].name);
            }

        }
    } while (1);

    return retv;
}
