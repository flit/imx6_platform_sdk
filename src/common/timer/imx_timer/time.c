/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
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
#include "functions.h"

extern void enable_interrupt(int);
static volatile int clock_counter;

/* Return the current clock value */
/* In order to obtain a high precision, whilst keeping the performance  */
/* penalty low, IRQs are only occuring at a rate of 100 per second, but */
/* the current timer value is factored in.  */
unsigned int ref_clock(void)
{
    return 0xFFFFFFFF - readl(EPIT_BASE_ADDR + EPITCNR);
}

/*!
 * clock initialization - it is called even before main()
 * TODO: need to allow user to specific to use CKIL or IPG or IPG_CLK_HIGHFREQ
 *       for higher resolution
 */
void init_clock(u32 rate)
{
    // enable timer and start it with 32KHz input clock
    writel(0x00010000, EPIT_BASE_ADDR + EPITCR);

    // make sure reset is complete
    while ((readl(EPIT_BASE_ADDR + EPITCR) & 0x10000) != 0) ;

    writel(0, EPIT_BASE_ADDR + EPITCMPR);   // always compare with 0

    if (rate == CLK_SRC_32K) {

        writel(0x030E0002, EPIT_BASE_ADDR + EPITCR);
        writel(0x030E0003, EPIT_BASE_ADDR + EPITCR);
    } else {
        printf("TODO\n");

        while (1) {
        }
    }
}

//
// Delay for some number of micro-seconds
//
void hal_delay_us(unsigned int usecs)
{
    /*
     * This causes overflow.
     * unsigned int delayCount = (usecs * 32768) / 1000000;
     * So use the following one instead
     */
    unsigned int delayCount = (usecs * 512) / 15625;

    if (delayCount == 0) {
        return;
    }

    writel(0x01, EPIT_BASE_ADDR + EPITSR);  // clear the compare status bit

    writel(delayCount, EPIT_BASE_ADDR + EPITLR);

    while ((0x1 & readl(EPIT_BASE_ADDR + EPITSR)) == 0) ;   // return until compare bit is set
}

void epit2_timer_init(int rate)
{
    // reset epit2
    writel(0x00030000, EPIT2_BASE_ADDR + EPITCR);

    // make sure reset is complete
    while ((readl(EPIT2_BASE_ADDR + EPITCR) & 0x10000) != 0) ;

    // use 32k clock as epit counter, and enable epit in wait and stop mode
    writel(0x0302000E, EPIT2_BASE_ADDR + EPITCR);

    // set the LR reg to be the largest number
    writel(0xFFFFFFFF, EPIT2_BASE_ADDR + EPITLR);

    // enable epit1 counter
    writel(0, EPIT2_BASE_ADDR + EPITCMPR);
}

void epit2_isr(void)
{
    writel(0x1, EPIT2_BASE_ADDR + EPITSR);  // to clear interrupt source
    printf("epit timer interrupt!!\n");
}

void epit2_periodic_interrupt(unsigned int interval)
{
    unsigned int epitCr, val;
    epitCr = readl(EPIT2_BASE_ADDR + EPITCR);
    val = (epitCr & 0x03000000) >> 24;

    if (val == 3) {
        writel(interval, EPIT2_BASE_ADDR + EPITLR);
    } else {
        printf("undefine the clock you select\n");
    }

    val = readl(EPIT2_BASE_ADDR + EPITCR);
    enable_interrupt(MXC_INT_EPIT2);
    ATTACH_INTERRUPT(MXC_INT_EPIT2, epit2_isr);
    writel(val | 0x1, EPIT2_BASE_ADDR + EPITCR);
}
