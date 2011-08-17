/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "interrupts.h"
#include "gic.h"                // include GIC functions
#include "io.h"

// declare the interrupt vector table
funct_t vect_IRQ[NUM_INT_SOURCES];

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
        vect_IRQ[vectNum & 0x1FF] ();   // jump to ISR in the look up table
        write_end_of_irq(vectNum);  // send end of irq
    }
}

// set funcISR as the ISR function for the source ID #
void registerIRQ(int ID, funct_t funcISR)
{
    vect_IRQ[ID] = funcISR;
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
