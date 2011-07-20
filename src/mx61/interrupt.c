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

#include "hardware.h"
#include "registers.h"
#include "functions.h"
/************************* Global Variables ***********************************/
#define NUM_OF_INTERRUPTS 160

typedef void (*int_hdlr_t) (void);
int_hdlr_t interrupt_handlers[NUM_OF_INTERRUPTS];

extern int_hdlr_t IRQ_HDLR;

/**************************** Functions ***************************************/

void disable_hdler(unsigned int int_num, int cpu_num)
{
    reg32clrbit(ICDIPTR + 4 * (int_num / 4), (int_num % 4) * 8 + cpu_num);
}

void enable_interrupt(unsigned int int_num, int cpu_num)
{
    reg32setbit(ICDIPTR + 4 * (int_num / 4), (int_num % 4) * 8 + cpu_num);
}

void capture_interrupt(int int_num, int_hdlr_t isr, int cpu_num)
{
    interrupt_handlers[int_num] = isr;
    enable_interrupt(int_num, cpu_num);
}

void default_int_routine(void)
{
    unsigned int int_num;

    int_num = reg32_read(ICCIAR) & 0x3ff;
    printf("Interrupt %d has been asserted\n", int_num);
}

void init_interrupts(void)
{
    int i;

    for (i = 0; i < NUM_OF_INTERRUPTS; interrupt_handlers[i++] = default_int_routine) ;

    /* Configure all interrupts as non-secure */
    reg32_write(ICDISR + 0x04, 0xffffffff);
    reg32_write(ICDISR + 0x08, 0xffffffff);
    reg32_write(ICDISR + 0x0c, 0xffffffff);
    reg32_write(ICDISR + 0x10, 0xffffffff);

    /* enable all SPIs */
    reg32_write(ICDISER + 0x04, 0xffffffff);
    reg32_write(ICDISER + 0x08, 0xffffffff);
    reg32_write(ICDISER + 0x0c, 0xffffffff);
    reg32_write(ICDISER + 0x10, 0xffffffff);

    /* all interrupts by default will not sent to any CPU */
    for (i = 0; i < 128; i = i + 4) {
        reg32_write(ICDIPTR + 0x20 + i, 0x0);
    }

    /* Configure priority mask to lowest value - enables all priorities */
    reg32_write(ICCPMR, 0x000000ff);

    /* Enable both secure and non-secure interrupts at CPU interface & distributor
       Also enable secure id_read & acknowledge of non-secure interrupts            */
    reg32_write(ICCICR, 0x00000007);
    reg32_write(ICDDCR, 0x00000003);

    reg32_write(IRAM_BASE_ADDR + 0x3ffbc, 0xe59ff01c);
    reg32_write(IRAM_BASE_ADDR + 0x3ffc0, 0xe59ff01c);
    reg32_write(IRAM_BASE_ADDR + 0x3ffc4, 0xe59ff01c);
    reg32_write(IRAM_BASE_ADDR + 0x3ffc8, 0xe59ff01c);
    reg32_write(IRAM_BASE_ADDR + 0x3ffcc, 0xe59ff01c);
    reg32_write(IRAM_BASE_ADDR + 0x3ffd0, 0xe59ff01c);
    reg32_write(IRAM_BASE_ADDR + 0x3ffd4, 0xe59ff01c);
    reg32_write(IRAM_BASE_ADDR + 0x3ffd8, 0xe59ff01c);

    reg32_write(IRAM_BASE_ADDR + 0x3ffe0, (unsigned int)&default_int_routine);
    reg32_write(IRAM_BASE_ADDR + 0x3ffe4, (unsigned int)&default_int_routine);
    reg32_write(IRAM_BASE_ADDR + 0x3ffe8, (unsigned int)&default_int_routine);
    reg32_write(IRAM_BASE_ADDR + 0x3ffec, (unsigned int)&default_int_routine);
    reg32_write(IRAM_BASE_ADDR + 0x3fff0, (unsigned int)&default_int_routine);
    reg32_write(IRAM_BASE_ADDR + 0x3fff4, (unsigned int)&IRQ_HDLR);
    reg32_write(IRAM_BASE_ADDR + 0x3fff8, (unsigned int)&default_int_routine);
    reg32_write(IRAM_BASE_ADDR + 0x3fffc, (unsigned int)&default_int_routine);
}
