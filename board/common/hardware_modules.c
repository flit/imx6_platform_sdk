/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file hardware.c
 * @brief This file contains the module definitions and some init functions.
 *
 * @ingroup diag_init
 */

#include <math.h>
#include "registers/regsccmanalog.h"
#if !defined (CHIP_MX6SL)
#include "registers/regsflexcan.h"
#include "registers/regsipu.h"
#endif
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

#if  defined(BOARD_SABRE_LITE)
// UART2 is the serial debug/console port for sabre_lite board
hw_module_t g_debug_uart = {
    "UART2 for debug",
    2,
    UART2_BASE_ADDR,
    80000000,
    IMX_INT_UART2,
    &default_interrupt_routine,
};
#elif defined(BOARD_SMART_DEVICE)
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
// UART4 is the serial debug/console port for EVB and ARD
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

/*!
 * @brief Retrieve the freq info based on the passed in module base address.
 *
 * @param   module_base     The base address of the module.
 * @return  Frequency in Hz or 0 for an invalid module.
 */
uint32_t get_freq(uint32_t module_base)
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

void freq_populate(void)
{
    int32_t i;
    hw_module_t *tmp;

    // Populate module frequency settings (important for UART driver)
    for (i = 0; (tmp = g_imx_modules[i]) != NULL; i++)
    {
        tmp->freq = get_freq(tmp->base);
    }
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
