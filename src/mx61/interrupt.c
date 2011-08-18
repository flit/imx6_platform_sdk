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

/************************* Global Variables ***********************************/
#define NUM_OF_INTERRUPTS 160

irq_hdlr_t g_interrupt_handlers[NUM_OF_INTERRUPTS];

/**************************** Functions ***************************************/

// IRQ_Handler, this functions handles IRQ exceptions
//void C_IRQ_Handler() __attribute__ ((interrupt ("IRQ")));
__attribute__ ((interrupt("IRQ")))
void C_IRQ_Handler(void)
{
    unsigned int vectNum;

    vectNum = read_irq_ack();   // send ack, get ID source # 
    if (vectNum & 0x0200) {     // Check that INT_ID isn't 1023 or 1022 (spurious interrupt)
        write_end_of_irq(vectNum);  // send end of irq
    } else {
        g_interrupt_handlers[vectNum & 0x1FF] ();   // jump to ISR in the look up table
        write_end_of_irq(vectNum);  // send end of irq
    }
}

void enableALL_interrupts_non_secure(void)
{
    int i;
    /* Configure all interrupts as non-secure */
    writel(0xffffffff, 0x00a01080 + 0x04);
    writel(0xffffffff, 0x00a01080 + 0x08);
    writel(0xffffffff, 0x00a01080 + 0x0c);
    writel(0xffffffff, 0x00a01080 + 0x10);

    /* enable all SPIs */
    writel(0xffffffff, 0x00a01100 + 0x04);
    writel(0xffffffff, 0x00a01100 + 0x08);
    writel(0xffffffff, 0x00a01100 + 0x0c);
    writel(0xffffffff, 0x00a01100 + 0x10);

    /* all interrupts by default will not sent to any CPU */
    for (i = 0; i < 128; i = i + 4) {
        writel(0x0, 0x00a01800 + 0x20 + i);
    }
}

void disable_interrupt(uint32_t irq_id, uint32_t cpu_num)
{
    disable_irq_id(irq_id);
    disable_interrupt_target_cpu(irq_id, cpu_num);
}

void enable_interrupt(uint32_t irq_id, uint32_t cpu_num, uint32_t priority)
{
    enable_irq_id(irq_id);
    set_irq_priority(irq_id, priority);
    /* set IRQ as non-secure */
    set_interrupt_as_nonsecure(irq_id);
    enable_interrupt_target_cpu(irq_id, cpu_num);
}

// set funcISR as the ISR function for the source ID #
void register_interrupt_routine(uint32_t irq_id, irq_hdlr_t isr)
{
    g_interrupt_handlers[irq_id] = isr;
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

    for (i = 0; i < NUM_OF_INTERRUPTS; g_interrupt_handlers[i++] = default_int_routine) ;

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
