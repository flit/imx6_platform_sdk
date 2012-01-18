/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
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

extern void SDK_TEST(void);
extern void init_interrupts(void);
extern void disable_strict_align_check(void);
extern void system_memory_arrange(void);

/*!
 * main function that decides which tests to run and prompts the user before
 * runninng test.
 * @return      should never return because ARM is at WFI (low power mode in the end)
 */
int main(void)
{
#if defined(MX61_EVB)||defined(MX61_SABRE_TABLET)
    system_memory_arrange();
    disable_strict_align_check();
#endif

    platform_init();

    // please keep this for i.MX53 and need to check what is needed here for i.MX61
    init_interrupts();

    SDK_TEST();

    _sys_exit(0);

    return 0;
}
