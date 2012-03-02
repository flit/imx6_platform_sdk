/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file camera_test.c
 * @brief Main camera test.
 * @ingroup diag_camera
 */

#include <stdio.h>
#include "hardware.h"

extern int32_t sensor_capture(void);

typedef struct {
    const char *name;
     int32_t(*test) (void);
} camera_test_t;

static camera_test_t camera_tests[] = {
#if defined(MX53_SMD) || defined(MX6DQ_SMART_DEVICE)
    {"Sensor capture", sensor_capture},
#endif
};

int32_t camera_test(void)
{
    int32_t retv = TRUE, i;
    int32_t test_num = sizeof(camera_tests) / sizeof(camera_test_t);
    uint8_t revchar;

    printf("\nStart camera test\n");

    do {
        for (i = 0; i < test_num; i++) {
            printf("\t%d - %s\n", i, camera_tests[i].name);
        }
        printf("\tx - to exit.\n");

        do {
            revchar = (uint8_t) getchar();
        } while (revchar == (uint8_t) 0xFF);
        if (revchar == 'x') {
            printf("\nCamera test exit.\n");
            break;
        }
        i = revchar - '0';

        if ((i >= 0) && (i < test_num)) {
            retv = camera_tests[i].test();
            if (retv == TRUE) {
                printf("\n%s test PASSED.\n", camera_tests[i].name);
            } else {
                printf("\n%s test FAILED.\n", camera_tests[i].name);
            }

        }
    } while (1);

    return retv;
}
