/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"
#include "registers/regssrc.h"

//globals used for gic_test
unsigned int gicTestDone;

extern void startup_imx6x(void);    // entry function, startup routine, defined in startup.s


void gic_sgi_test_handler(void)
{
    printf("In gic_sgi_test_handler()\n");

    gicTestDone = 0;            // test complete
}

void gic_test(void)
{
    printf("Starting GIC SGI test\n");

    // register and enable sgi isr
    register_interrupt_routine(SW_INTERRUPT_3, gic_sgi_test_handler);
    enable_interrupt(SW_INTERRUPT_3, CPU_0, 0);

    gicTestDone = 1;

    printf("Sending SGI\n");
    gic_send_sgi(SW_INTERRUPT_3, 1, 0);

    printf("Waiting\n");
    while (gicTestDone) ;

    printf("SGI was handled\n");
}
