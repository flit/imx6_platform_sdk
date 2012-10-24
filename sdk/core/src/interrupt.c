/*
 * Copyright (c) 2009-2012, Freescale Semiconductor, Inc.
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
 * @file  interrupt.c
 *
 * @ingroup diag_init
 */

#include "sdk.h"

/************************* Global Variables ***********************************/
#define NUM_OF_INTERRUPTS 160

irq_hdlr_t g_interrupt_handlers[NUM_OF_INTERRUPTS];

/* That variable can be used to determine the interrupt source
 * while being in an interrupt context.
 * Being updated during an interrupt, therefore at any time,
 * that variable shouldn't be used out of this particular context.
 */
volatile uint32_t g_vectNum[4];

/**************************** Functions ***************************************/

// IRQ_Handler, this functions handles IRQ exceptions
//void C_IRQ_Handler() __attribute__ ((interrupt ("IRQ")));
__attribute__ ((interrupt("IRQ")))
void IRQ_HDLR(void)
{
    /* Keep a local copy for better code */
    uint32_t vectNum;

    /* vectNum = RESERVED[31:13] | CPUID[12:10] | INTERRUPT_ID[9:0] */
    vectNum = gic_read_irq_ack();   /* send ack and get ID source */
    if (vectNum & 0x0200) {     /* Check that INT_ID isn't 1023 or 1022 (spurious interrupt) */
        gic_write_end_of_irq(vectNum);  /* send end of irq */
    } else {
        /* copy the local value to the global image of CPUID */
        g_vectNum[(vectNum >> 10) & 0x7] = vectNum & 0x1FF;
        g_interrupt_handlers[vectNum & 0x1FF] ();   /* jump to ISR in the look up table */
        gic_write_end_of_irq(vectNum);  /* send end of irq */
    }
}

void enableALL_interrupts_non_secure(void)
{
    uint32_t i;
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

void disable_interrupt(uint32_t irq_id, uint32_t cpu_id)
{
    gic_enable_irq(irq_id, false);
    gic_set_cpu_target(irq_id, cpu_id, false);
}

void enable_interrupt(uint32_t irq_id, uint32_t cpu_id, uint32_t priority)
{
    gic_set_irq_priority(irq_id, priority);
    gic_set_irq_security(irq_id, false);    // set IRQ as non-secure
    gic_set_cpu_target(irq_id, cpu_id, true);
    gic_enable_irq(irq_id, true);
}

// set funcISR as the ISR function for the source ID #
void register_interrupt_routine(uint32_t irq_id, irq_hdlr_t isr)
{
    g_interrupt_handlers[irq_id] = isr;
}

void default_interrupt_routine(void)
{
    /* find a way to address an IRQ handled by another CPU. Assumes
     * here that CPU_0 is used.
     */
    printf("Interrupt %d has been asserted\n", g_vectNum[0]);
}
