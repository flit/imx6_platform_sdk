/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file time.c
 * @brief Basic clock functions used by the ANSI C time (see time.h)
 *
 */

#include "hardware.h"
#include "time.h"

void hal_delay_us(uint32_t usecs)
{
    volatile struct mx_epit *pepit = (volatile struct mx_epit *)g_system_timer.base;

    if (usecs == 0) {
        return;
    }

    pepit->epitlr = usecs;

   /* do not return until compare bit is set, use IRQ later? */
    while ((pepit->epitsr & EPITSR_OCIF) == 0) ;
    pepit->epitsr |= EPITSR_OCIF;
}






