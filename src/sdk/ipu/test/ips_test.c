/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_test.c
 * @brief Main IPU test.
 * @ingroup diag_ipu
 */

#include <stdio.h>
#include "ips_test.h"

extern void ipu_iomux_config(void);
static ipu_test_t ipu_tests[] = {
    {"IPU SINGLE DISPLAY TEST", ips_display_test},
    {"IPU COMBINE DISPLAY TEST", ips_combiner_test},
    {"IPU ROTATE TEST", ips_rotate_test},
    {"IPU RESIZE TEST", ips_resize_test},
    {"IPU CSC TEST", ips_csc_test},
};

int32_t ipu_test(void)
{
    int32_t retv = TRUE;
    ips_dev_panel_t *panel;
    uint8_t revchar;
    int32_t test_num = sizeof(ipu_tests) / sizeof(ipu_test_t);
    int32_t i;

    ipu_sw_reset(0, 1000);
    ipu_sw_reset(1, 1000);
    ipu_iomux_config();

    printf("\nStart IPU test\n");
    printf("Note that the Display test is using the Hannstar LVDS panel pluged into LVDS0/1\n");
    /*enable panel */
    panel = search_panel("HannStar XGA LVDS");
    panel->panel_init();

    do {
        for (i = 0; i < test_num; i++)
            printf("\t%d - %s\n", i, ipu_tests[i].name);
        printf("\tx - to exit.\n");

        do {
            revchar = getchar();
        } while (revchar == (uint8_t) 0xFF);
        if (revchar == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        i = revchar - '0';
        if ((i >= 0) && (i < test_num)) {
            printf("\n");
            retv = ipu_tests[i].test(panel);
            if (retv == TRUE)
                printf("\n%s test PASSED.\n\n", ipu_tests[i].name);
            else
                printf("\n%s test FAILED.\n\n", ipu_tests[i].name);
        }
    } while (1);

    return retv;
}
