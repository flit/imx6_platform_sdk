/*
 * Copyright (c) 2010-2012, Freescale Semiconductor, Inc.
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
 * @file vectors.S
 * @brief This file contains the exception vectors
 *
 * @ingroup diag_init
 */
#include "asm_defines.h"

    .code 32
    .section ".vectors","ax"
    

    .global startup
    .func startup 
startup:
#ifdef PLATFORM_ASM_STARTUP
        PLATFORM_ASM_STARTUP            // start up code in assembly
#endif
#if defined(CHIP_MX6DQ)||defined(CHIP_MX6SDL)||defined(CHIP_MX6SL)
        b startup_imx6x
#endif
        ldr     r0, =top_of_stacks
        msr     cpsr_c, #MODE_FIQ | F_BIT  /*| I_BIT no interrupts*/
        sub     sp, r0, #OFFSET_FIQ_STACK
        msr     cpsr_c, #MODE_IRQ | F_BIT  /* | I_BITno interrupts */
        sub     sp, r0, #OFFSET_IRQ_STACK
        msr     cpsr_c, #MODE_ABT | F_BIT /*| I_BIT  no interrupts */
        sub     sp, r0, #OFFSET_ABT_STACK
        msr     cpsr_c, #MODE_UND | F_BIT
        sub     sp, r0, #OFFSET_UND_STACK
        msr     cpsr_c, #MODE_SVC | F_BIT /* | I_BIT no interrupts */
        sub     sp, r0, #OFFSET_SVC_STACK

        /* init .bss */
        /* clear the .bss section (zero init) */
        ldr     r1,=__bss_start__
        ldr     r2,=__bss_end__
        mov     r3,#0
1:
        cmp     r1,r2
        stmltia r1!,{r3}
        blt     1b

        /* branch to c library entry point */
        ldr     r12, =main               /* save this in register for possible long jump */
        bx      r12                         /* branch to __main */
    .endfunc    //startup()

    .func startup_vectors
startup_vectors:
        ldr     pc, reset_addr
        ldr     pc, undefined_addr
        ldr     pc, swi_addr
        ldr     pc, prefetch_addr
        ldr     pc, abort_addr
        nop                             /* reserved vector */
        ldr     pc, irq_addr
        ldr     pc, fiq_addr

reset_addr:      .word     startup
undefined_addr:  .word     undefined_handler
swi_addr:        .word     swi_handler
prefetch_addr:   .word     prefetch_handler
abort_addr:      .word     abort_handler
irq_addr:        .word     irq_handler
fiq_addr:        .word     fiq_handler

/*!
 * Exception Handlers
 */
undefined_handler:
        b       undefined_handler
swi_handler:
        b       swi_handler
prefetch_handler:
        b       prefetch_handler
abort_handler:
        b       ABORT_HDLR
irq_handler:
        b       IRQ_HDLR //only response to the IRQ
fiq_handler:
        b       fiq_handler

    .endfunc    //startup()

    .end
