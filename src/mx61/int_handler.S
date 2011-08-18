/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file int_handler.S
 * @brief This file contains the exception vectors
 *
 * @ingroup diag_init
 */
#include "plat_startup.h"
#include "asm_defines.h"
#include "registers.h"
    .code 32

    .global IRQ_HDLR
	.func IRQ_HDLR
IRQ_HDLR:
    stmfd   sp!, {r0-r7}
    stmfd   sp!, {r8-r12,lr}

    ldr     r0,=ICCIAR      // Interrupt Acknowledge register
    ldr     r3,[r0]         // r0[12:10] = CPU_ID of software interrupts, r0[9:0] = INT_ID
    ldr     r2,=0x00001C00
    and     r1,r3,r2
    lsr     r1,r1,#10       // Keep CPU_ID at r1
    ldr     r2,=0x00000200
    and     r2,r3,r2        
    cmp     r2,#0           // Check that INT_ID isn't 1023 or 1022 (spurious interrupt)
    bne     END_IRQ_HLDR
    ldr     r2,=0x000001FF
    and     r0,r3,r2        // Keep INT_ID at r0
    stmfd   sp!, {r3}       // Save original ICCIAR value

    lsl     r2,r0,#2
    ldr     lr,=g_interrupt_handlers
    ldr     r2,[lr,r2]
    mov     lr,pc
    bx      r2              // Jump to Interrupt Service Routine
    ldmfd   sp!, {r3}       // Restore original ICCIAR value
    ldr     r0,=ICCEOIR
    str     r3,[r0]         // Update End of Interrupt register with original value from ICCIAR
END_IRQ_HLDR:
    mrs     r2, cpsr
    bic     r0, r2, #0x100
    msr     cpsr_cxsf, r0
    ldmfd   sp!, {r8-r12,lr}
    ldmfd   sp!, {r0-r7}
    subs    pc,lr,#4
	.endfunc
    .end
