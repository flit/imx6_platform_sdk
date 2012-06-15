/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "sdma_test.h"

static sdma_test_t sdma_tests[] = {
    {"Memory to memory", mem_2_mem_test},
    {"eCSPI1 loopback - shared memory", ecspi_shp_test},
#ifdef CHIP_MX53
    {"eCSPI2 loopback - peripheral", ecspi_app_test},
#endif
#ifdef CHIP_MX53
    {"UART3 loopback  - shared memory", uart_shp_test},
#else
#if !defined(BOARD_SMART_DEVICE)    //Since mx6x SD board uses UART1 as debug uart.
    {"UART1 loopback  - shared memory", uart_shp_test},
#endif
#endif
    {"UART5 loopback  - perihperal", uart_app_test},
    {"UART5 loopback with interrupt supported", uart_app_interrupt_test},
};

int sdma_test(void)
{
    int retv = FALSE, idx;
    uint8_t sel;

    printf("\n---- Running SDMA test, type 'x' to exit.\n");

    do {
        printf("Please select script type:\n");
        for (idx = 0; idx < (sizeof(sdma_tests) / sizeof(sdma_test_t)); idx++) {
            printf("\t%d - %s\n", idx, sdma_tests[idx].name);
        }
        printf("\tx - to exit.\n");

        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        idx = sel - '0';

        if ((idx >= 0) && (idx < (sizeof(sdma_tests) / sizeof(sdma_test_t)))) {
            printf("\n");
            retv = sdma_tests[idx].test();
            if (retv == TRUE) {
                printf("\n%s test PASSED.\n", sdma_tests[idx].name);
            } else {
                printf("\n%s test FAILED.\n", sdma_tests[idx].name);
            }

        }
    } while (1);

    return retv;
}
