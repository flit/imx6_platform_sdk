/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file mipi_test.c
 * @brief Main mipi test.
 * @ingroup diag_mipi
 */

#include <stdio.h>
#include "hardware.h"

extern int32_t mipi_csi2_test(void);
extern int32_t mipi_dsi_test(void);

typedef struct {
    const char *name;
     int32_t(*test) (void);
} mipi_test_t;

static mipi_test_t mipi_tests[] = {
    {"mipi csi-2", mipi_csi2_test},
    {"mipi dsi test", mipi_dsi_test},
};

int32_t mipi_test(void)
{
    int32_t retv = TRUE, i;
    int32_t test_num = sizeof(mipi_tests) / sizeof(mipi_test_t);
    uint8_t revchar;

    printf("\nStart mipi test\n");

    do {
        for (i = 0; i < test_num; i++) {
            printf("\t%d - %s\n", i, mipi_tests[i].name);
        }
        printf("\tx - to exit.\n");

        do {
            revchar = (uint8_t) getchar();
        } while (revchar == (uint8_t) 0xFF);
        if (revchar == 'x') {
            printf("\nmipi test exit.\n");
            break;
        }
        i = revchar - '0';

        if ((i >= 0) && (i < test_num)) {
            retv = mipi_tests[i].test();
            if (retv == TRUE) {
                printf("\n%s test PASSED.\n", mipi_tests[i].name);
            } else {
                printf("\n%s test FAILED.\n", mipi_tests[i].name);
            }

        }
    } while (1);

    return retv;
}
