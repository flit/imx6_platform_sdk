/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
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
extern void disable_strict_align_check(void);
extern void system_memory_arrange(void);
extern void enable_neon_fpu(void);

/*!
 * main function that decides which tests to run and prompts the user before
 * running test.
 * @return      should never return because ARM is at WFI (low power mode in the end)
 */
int main(void)
{
    enable_neon_fpu();

#if defined(MX6DQ_EVB)||defined(MX6SDL_EVB)||defined(MX6DQ_SMART_DEVICE)||defined(MX6SDL_SMART_DEVICE)
    system_memory_arrange();
    disable_strict_align_check();
#endif

    platform_init();

    SDK_TEST();

    _sys_exit(0);

    return 0;
}
