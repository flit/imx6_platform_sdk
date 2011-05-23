/*
 * Copyright (C) 2009-2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_init Base SDK files
 */

/*!
 * @file  main.c
 * @brief main() function
 *
 * @ingroup diag_init
 */

#include <stdio.h>
#include "hardware.h"
#include "version.h"
#include "text_color.h"
#include "time.h"

extern void setup_interrupts_in_RAM(void);
extern void tzic_init(void);
extern void SDK_TEST(void);
/*!
 * main function that decides which tests to run and prompts the user before
 * runninng test.
 * @return      should never return because ARM is at WFI (low power mode in the end)
 */
int main(void)
{

    platform_init();

    setup_interrupts_in_RAM();
    tzic_init();

    SDK_TEST();

    _sys_exit(0);

    return 0;
}
