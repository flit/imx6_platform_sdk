/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
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

int ipu_test(void)
{
    int retv = TRUE;
    ips_dev_panel_t *panel;
    int i;

    printf("\n---- Running IPU test ----\n");
    printf("Note that the Display test is using the Hannstar LVDS panel pluged into LVDS0/1\n");
    ipu_iomux_config();

    /*enable panel */
    panel = search_panel("HannStar XGA LVDS");
    panel->panel_init();

    for (i = 0; i < sizeof(ipu_tests) / sizeof(ipu_test_t); i++) {
        retv = ipu_tests[i].test(panel);
        if (retv == TRUE) {
            printf("\n%s test PASSED.\n\n", ipu_tests[i].name);
        } else {
            printf("\n%s test FAILED.\n\n", ipu_tests[i].name);
        }
    }

    return retv;
}
