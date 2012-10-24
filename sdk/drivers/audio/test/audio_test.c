/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include "sdk.h"
#include "audio/audio.h"
#include "wav_data.data"

extern int32_t ssi_playback(audio_pcm_p);
extern int32_t esai_playback(audio_pcm_p);
extern int32_t spdif_playback(audio_pcm_p);

typedef struct {
    const char *name;
     int32_t(*test) (audio_pcm_p);
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
#if defined(BOARD_SABRE_AI) || defined(BOARD_EVB)
    {"ESAI playback", esai_playback},
#endif
#if defined(BOARD_EVB)
    {"SPDIF playback", spdif_playback},
#endif

#if defined(BOARD_SMART_DEVICE) && defined(BOARD_REV_B)
    {"SSI playback", ssi_playback},
#endif
};

int32_t audio_test(void)
{
    int32_t retv=-1, idx, num;
    uint8_t sel;

    num = sizeof(audio_tests)/sizeof(audio_test_t);

    if(0 == num){
        printf("Audio test not supported on this board.\n");
	return 0;
    }

    printf("\n--- Running audio test, type 'x' to exit.\n");

    do {
        printf("Please select test type:\n");
        for (idx = 0; idx < num; idx++) {
            printf("\t%d - %s\n", idx, audio_tests[idx].name);
        }
        printf("\tx - to exit.\n");

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
