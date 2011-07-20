/*
 * Copyright (C) 2009-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_init Base SDK files
 */

/*!
 * @file  interrupt.c
 *
 * @ingroup diag_init
 */

#include <stdio.h>
#include "hardware.h"
#include "version.h"
#include "functions.h"

#define NUM_OF_INTERRUPTS 128

typedef void (*int_hdlr_t) (void);

extern int_hdlr_t IRQ_HDLR;

/*define a list which contains 128 interrupt routins*/
void (*interrupt_routine_list[MAX_INTERRUPT_NUM]) (void) = {
};

void clear_all_interrupts(void)
{
    writel(0xFFFFFFFF, TZIC_BASE_ADDR + 0x280);
    writel(0xFFFFFFFF, TZIC_BASE_ADDR + 0x284);
    writel(0xFFFFFFFF, TZIC_BASE_ADDR + 0x288);
    writel(0xFFFFFFFF, TZIC_BASE_ADDR + 0x28C);
}

void default_interrupt_routine(void)
{
    printf("Attention: No specified interrupt routine attached!\n");
    printf("please use ATTACH_INTERRUPT to link the interrupt source.\n");
    return;
}

void setup_interrupts_in_RAM(void)
{
    /*attach all the interrupt routines to default one */
    int index = 0;
    for (index = 0; index < MAX_INTERRUPT_NUM; index++) {
        ATTACH_INTERRUPT(index, default_interrupt_routine);
    }

    /* to realize the interrupt, here vector table in rom code is 
     * used. vector table in ROM is located in 0x0 addr, when interrupt
     * occurs, pc jump to IRAMi(0xf801ffbc) for further process.
     * and interrupt routines are located from 0xf801ffe0*/
    writel(0xe59ff01c, 0xf801ffbc);
    writel(0xe59ff01c, 0xf801ffc0);
    writel(0xe59ff01c, 0xf801ffc4);
    writel(0xe59ff01c, 0xf801ffc8);
    writel(0xe59ff01c, 0xf801ffcc);
    writel(0xe59ff01c, 0xf801ffd0);
    writel(0xe59ff01c, 0xf801ffd4);
    writel(0xe59ff01c, 0xf801ffd8);

    writel(0x0, 0xf801ffe0);
    writel(0x0, 0xf801ffe4);
    writel(0x0, 0xf801ffe8);
    writel(0x0, 0xf801ffec);
    writel(0x0, 0xf801fff0);
    writel((unsigned int)(&IRQ_HDLR), 0xf801fff4);
    writel(0x0, 0xf801fff8);
    writel(0x0, 0xf801fffc);
}

void tzic_init(void)
{
    /*set interrupts to non-secure */
    reg32_write(TZIC_BASE_ADDR + TZIC_INTSEC0_OFFSET, 0xf397ffff);
    reg32_write(TZIC_BASE_ADDR + TZIC_INTSEC1_OFFSET, 0xffffffff);
    reg32_write(TZIC_BASE_ADDR + TZIC_INTSEC2_OFFSET, 0xffffffff);
    reg32_write(TZIC_BASE_ADDR + TZIC_INTSEC3_OFFSET, 0xffffffff);

    // Configure priority mask to lowest value - enables all priorities
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIOMASK_OFFSET, 0x000000f8);
    // Set EN and NSEN bits to enable both secure and non secure interrupts
    reg32_write(TZIC_BASE_ADDR + TZIC_INTCTRL_OFFSET, 0x80010001);

    // Set All interrupts as higest priority
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY0_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY1_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY2_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY3_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY4_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY5_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY6_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY7_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY8_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY9_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY10_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY11_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY12_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY13_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY14_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY15_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY16_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY17_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY18_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY19_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY20_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY21_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY22_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY23_OFFSET, 0x00000000);
    reg32_write(TZIC_BASE_ADDR + TZIC_PRIORITY24_OFFSET, 0x00000000);
}

void enable_interrupt(unsigned int int_num, int cpu_num)
{
    reg32setbit(TZIC_BASE_ADDR + TZIC_ENSET0_OFFSET + (int_num / 32) * 4, int_num % 32);
}

void capture_interrupt(int int_num, int_hdlr_t isr, int cpu_num)
{
    interrupt_routine_list[int_num] = isr;
    enable_interrupt(int_num, cpu_num);
}

void init_interrupts(void)
{
    setup_interrupts_in_RAM();
    tzic_init();
}
