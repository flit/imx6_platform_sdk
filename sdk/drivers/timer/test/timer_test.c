/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "timer/epit.h"
#include "timer/timer.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void microseconds_test(void)
{
    printf("---- Microsecond Tick Counter Test ----\n\n");

    printf("timing 20 millisecond delay using EPIT...\n");
    
    uint64_t startTime = time_get_microseconds();
    hal_delay_us(20000);
    uint64_t endTime = time_get_microseconds();

    printf("start time = %08x%08x microseconds\n", (uint32_t)(startTime >> 32), (uint32_t)(startTime & 0xffffffff));
    printf("end time = %08x%08x microseconds\n", (uint32_t)(endTime >> 32), (uint32_t)(startTime & 0xffffffff));
    printf("time delta = %ld microseconds\n", (uint32_t)(endTime - startTime));
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////

