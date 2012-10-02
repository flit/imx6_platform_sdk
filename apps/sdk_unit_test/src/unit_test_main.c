/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "hardware.h"
#include "platform_init.h"
#include "cortex_a9.h"
#include "mmu.h"
#include "version.h"
#include "print_clock_info.h"
//#include "board_id/board_id.h"

extern int SDK_TEST(void);

/*!
 * main function that decides which tests to run and prompts the user before
 * running test.
 * @return      should never return because ARM is at WFI (low power mode in the end)
 */
int main(void)
{
    enable_neon_fpu();

#if defined(BOARD_EVB)||defined(BOARD_SMART_DEVICE)
    system_memory_arrange();
    disable_strict_align_check();
#endif

    platform_init();
    
    print_version();

    show_freq();
    show_ddr_config();


    SDK_TEST();

    _sys_exit(0);

    return 0;
}
