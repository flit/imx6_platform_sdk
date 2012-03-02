/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file vectors.S
 * @brief This file contains the exception vectors
 *
 * @ingroup diag_init
 */
#include "plat_startup.h"
#include "asm_defines.h"

    .code 32
    .section ".vectors","ax"
    
#ifdef PLATFORM_INIT
    PLATFORM_INIT                       // beginning of the image can put dcd here
#endif

    .global startup
    .func startup 
startup:
#ifdef PLATFORM_ASM_STARTUP
        PLATFORM_ASM_STARTUP            // start up code in assembly
#endif
#if defined(MX6DQ)||defined(MX6SDL)
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
        b       abort_handler
irq_handler:
        b       IRQ_HDLR //only response to the IRQ
fiq_handler:
        b       fiq_handler

    .endfunc    //startup()

    .end
