/*
 *   Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 *   THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 *   BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 *   Freescale Semiconductor, Inc.
 */
#include <stdio.h>
#include "hardware.h"
#include "watchdog.h"
#include "sdk.h"
#include "soc_memory_map.h"
/************************************************** Static Function ***********************************************/
static void watchdog_reset(void)
{
    watchdog_reg_p base = (watchdog_reg_p) WDOG1_BASE_ADDR;
    char stop_feeding;
    int i = 0;
    printf("Power reset...\n");

    /* Init Watchdog */
    base->wcr = WCR_WDA | WCR_SRS | WCR_WT | WCR_WDBG;

    printf
        ("watch dog is running,and system will reset in 2 seconds if you stop feeding dog.Stop feeding dog ?(Y or N)\n");
    /*enable watchdog */
    base->wcr |= WCR_WDE;
    /* Infinite loop */
    while (1) {
        stop_feeding = getchar();
        if (stop_feeding != 'Y') {
            if (i % 2 == 0)
                base->wsr = 0x5555;
            else
                base->wsr = 0xAAAA;
            i++;
        } else {
            printf("reboot\n");
            while (1) ;
        }
    }
}

/************************************************** Global Function ***********************************************/

int wdog_test(void)
{
    int retv = FALSE;

    watchdog_reset();

    return retv;
}
