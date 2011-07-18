/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
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

.code 32. section ".vectors", "ax"
#ifdef PLATFORM_INIT
    PLATFORM_INIT               // beginning of the image can put dcd here
#endif
.global startup.func startup startup:
#ifdef PLATFORM_ASM_STARTUP
 PLATFORM_ASM_STARTUP           // start up code in assembly
#endif
 ldr r0, = top_of_stacks msr cpsr_c,
#MODE_FIQ | F_BIT
    /*| I_BIT no interrupts */
    sub sp, r0,
#OFFSET_FIQ_STACK
    msr cpsr_c,
#MODE_IRQ | F_BIT
    /* | I_BITno interrupts */
    sub sp, r0,
#OFFSET_IRQ_STACK
    msr cpsr_c,
#MODE_ABT | F_BIT
    /*| I_BIT  no interrupts */
    sub sp, r0,
#OFFSET_ABT_STACK
    msr cpsr_c,
#MODE_UND | F_BIT
    sub sp, r0,
#OFFSET_UND_STACK
    msr cpsr_c,
#MODE_SVC | F_BIT
    /* | I_BIT no interrupts */
    sub sp, r0,
#OFFSET_SVC_STACK
    /* init .bss */
    /* clear the .bss section (zero init) */
    ldr r1, = __bss_start__ ldr r2, = __bss_end__ mov r3,
#0
1:
cmp r1, r2 stmltia r1 !, {
r3}

blt 1 b
    /* branch to c library entry point */
    ldr r12, = main             /* save this in register for possible long jump */
    bx r12                      /* branch to __main */
    .endfunc                    //startup()
.func startup_vectors startup_vectors:
ldr pc, reset_addr ldr pc, undefined_addr ldr pc, swi_addr ldr pc, prefetch_addr ldr pc, abort_addr nop /* reserved vector */
ldr pc, irq_addr ldr pc, fiq_addr reset_addr: .word startup undefined_addr: .word undefined_handler swi_addr: .word swi_handler prefetch_addr: .word prefetch_handler abort_addr: .word abort_handler irq_addr: .word irq_handler fiq_addr:.
    word
    fiq_handler
/*!
 * Exception Handlers
 */
undefined_handler:
b undefined_handler swi_handler:
b swi_handler prefetch_handler:
b prefetch_handler abort_handler:
b abort_handler irq_handler:
#ifdef MX53
b IRQ_HDLR                      //only response to the IRQ
#else
b irq_handler
#endif
fiq_handler:
b fiq_handler.endfunc           //startup()
#ifdef MX53
.global IRQ_HDLR.func IRQ_HDLR IRQ_HDLR:stmfd sp !, {
r0 - r12, lr} ldr r0, = TZIC_BASE_ADDR + 0xD80  /*HIPND0 interrupt pending register */
    mov r2,
#32
find_int_src:
ldr r1,[r0]
cmp r1,
#0
 bne check_int_index add r0, r0,
#4
 add r2, r2,
#32
 b find_int_src
    /* check the interrupt index. */
 check_int_index:cmp r1,
#0
 beq proc_interrupt sub r2, r2,
#1
 mov r1, r1, lsl
#1
 b check_int_index
    /* the interrupt routines are maintained in a function pointer
     * array. it is determined by the entry of table plus the offset
     * of index*/
 proc_interrupt:ldr r3, = TZIC_BASE_ADDR + 0x280 mov r4, r2, lsr
#5
    mov r4, r4, lsl
#2
    add r3, r3, r4              /*get the addr of clear register */
    sub r4, r2, r4, lsl
#3
    mov r1,
#1
    mov r4, r1, lsl r4 str r4,[r3]  /*clear the interrupt source */
mov r2, r2, lsl
#2                              /*a function pointer occupy 4 bytes */
 ldr r0, = interrupt_routine_list ldr r0,[r0, r2]   /*set the routine address to r0 */
ldr r1, = default_interrupt_routine cmp r1, r0 bne proc_isr disable_int_src:
    /*disable the interrupt, if no specified isr is attached. */
sub r3, r3,
#0x100
    //enclear register
    str r4,[r3]

proc_isr:
mov lr, pc bx r0                /*process the interrupt */
    ldmfd sp !, {
r0 - r12, lr}

subs pc, lr,
#4
.endfunc
#endif
.end
