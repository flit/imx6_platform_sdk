/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "ips_test.h"

extern int ips_display_test(void);
extern void ipu_iomux_config(void);
static ipu_test_t ipu_tests[] = {
    {"IPU DISPLAY TEST", ips_display_test},
};

int ipu_test(void)
{
    int retv;

    printf("\n---- Running IPU test ----\n");
    printf("Note that the Display test is using the Hannstar LVDS panel pluged into LVDS0/1\n");
    ipu_iomux_config();

    retv = ipu_tests[0].test();
    if (retv == TRUE) {
        printf("\n%s test PASSED.\n", ipu_tests[0].name);
    } else {
        printf("\n%s test FAILED.\n", ipu_tests[0].name);
    }

    return retv;
}
