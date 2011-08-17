
/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "io.h"

extern int ssi_playback(void);
extern int esai_playback(void);
extern int spdif_playback(void);

typedef struct {
    const char *name;
    int (*test) (void);
} audio_test_t;

static audio_test_t audio_tests[] = {
    {"SSI playback", ssi_playback},
    {"ESAI playback", esai_playback},
    {"SPDIF playback", spdif_playback},
};

int audio_test(void)
{
    int retv, idx;
    uint8_t sel;

    printf("\n--- Running audio test, type 'x' to exit.\n");

    do {
        printf("Please select test type:\n");
        for (idx = 0; idx < (sizeof(audio_tests) / sizeof(audio_test_t)); idx++) {
            printf("\t%d - %s\n", idx, audio_tests[idx].name);
        }

        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        idx = sel - '0';

        if ((idx >= 0) && (idx < (sizeof(audio_tests) / sizeof(audio_test_t)))) {
            printf("\n");
            retv = audio_tests[idx].test();
            if (retv == TRUE) {
                printf("\n%s test PASSED.\n", audio_tests[idx].name);
            } else {
                printf("\n%s test FAILED.\n", audio_tests[idx].name);
            }

        }
    } while (1);

    return retv;
}
