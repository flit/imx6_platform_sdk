/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_lcd LCD Test
 */

#include <stdio.h>
#include "sdk.h"

extern int32_t lcdc_display_test(void);

typedef struct {
    const char *name;
	int32_t(*test) (void);
} lcdc_test_t;

static lcdc_test_t lcdc_tests[] = {
    {"LCDC display", lcdc_display_test},
};

int32_t lcdc_test(void)
{
    int32_t retv = TEST_PASSED, i;
    int32_t test_num = sizeof(lcdc_tests) / sizeof(lcdc_test_t);
    uint8_t revchar;

    printf("\nStart LCDC test\n");

    do {
        for (i = 0; i < test_num; i++) {
            printf("\t%d - %s\n", i, lcdc_tests[i].name);
        }
        printf("\tx - to exit.\n");

        do {
            revchar = (uint8_t) getchar();
        } while (revchar == (uint8_t) 0xFF);
        if (revchar == 'x') {
            printf("\nLCDC test exit.\n");
            break;
        }
        i = revchar - '0';

        if ((i >= 0) && (i < test_num)) {
            retv = lcdc_tests[i].test();
            if (retv == TEST_PASSED) {
                printf("\n%s test PASSED.\n", lcdc_tests[i].name);
            } else {
                printf("\n%s test FAILED.\n", lcdc_tests[i].name);
            }

        }
    } while (1);

    return retv;
}
