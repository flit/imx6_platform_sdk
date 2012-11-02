/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file hardware.c
 * @brief This file contains the module definitions and some init functions.
 *
 * @ingroup diag_init
 */

#include <math.h>
#include "registers/regsccmanalog.h"
#include "registers/regsflexcan.h"
#include "registers/regsipu.h"
#include "registers/regspmu.h"
#include "registers/regsccm.h"
#include "sdk.h"

#define DUMMY_ARM_CORE_BASE_ADDR 0x12345789

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

// ARM core.
hw_module_t g_arm_core = {
    "Cortex A9 core",
    1,
    DUMMY_ARM_CORE_BASE_ADDR,
    792000000,
};

#if defined(BOARD_SMART_DEVICE)
// UART1 is the serial debug/console port for smart_device board
hw_module_t g_debug_uart = {
    "UART1 for debug",
    1,
    UART1_BASE_ADDR,
    80000000,
    IMX_INT_UART1,
    &default_interrupt_routine,
};
#else
// UART4 is the serial debug/console port for EVB and sabre_ai
hw_module_t g_debug_uart = {
    "UART4 for debug",
    4,
    UART4_BASE_ADDR,
    80000000,
    IMX_INT_UART4,
    &default_interrupt_routine,
};
#endif

/* EPIT1 used for time functions */
hw_module_t g_system_timer = {
    "EPIT1 for system timer",
    1,
    EPIT1_BASE_ADDR,
    66000000,
    IMX_INT_EPIT1,
    &default_interrupt_routine,
};

hw_module_t g_ddr = {
    "DDR memory",
    1,
    MMDC_P0_BASE_ADDR,
#if defined(CHIP_MX6DQ)
    528000000,
#else
    400000000,
#endif
};

hw_module_t *g_imx_modules[] = {
    &g_arm_core,
    &g_ddr,
    &g_debug_uart,
    &g_system_timer,
    NULL,
};

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

uint32_t get_module_freq(uint32_t module_base)
{
    if (module_base == DUMMY_ARM_CORE_BASE_ADDR)
        return get_main_clock(CPU_CLK);
    else if (module_base == MMDC_P0_BASE_ADDR)
        return get_main_clock(MMDC_CH0_AXI_CLK);
    else if (module_base == g_debug_uart.base)
        return get_peri_clock(UART4_BAUD);
    else if (module_base == g_system_timer.base)
        /* value depends on how the timer is configured, 
           and this is actually initialized in system_time_init() */
        return g_system_timer.freq;
    else {
        printf("Not a valid module base address \n");
        return 0;
    }
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
