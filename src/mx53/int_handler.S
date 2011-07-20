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

    .code 32

    .global IRQ_HDLR
	.func IRQ_HDLR
IRQ_HDLR:
	stmfd   sp!, {r0-r12,lr}

	ldr  	r0, = TZIC_BASE_ADDR+0xD80 /*HIPND0 interrupt pending register*/
	mov 	r2, #32

find_int_src:
	ldr  	r1, [r0]
	cmp 	r1, #0
	bne 	check_int_index
	add		r0, r0, #4
	add		r2, r2, #32
	b		find_int_src

	/* check the interrupt index. */
check_int_index:
	cmp 	r1, #0
	beq 	proc_interrupt
	sub 	r2, r2, #1
	mov 	r1, r1, lsl #1
	b 		check_int_index

	/* the interrupt routines are maintained in a function pointer
	 * array. it is determined by the entry of table plus the offset
	 * of index*/
proc_interrupt:
	ldr		r3, = TZIC_BASE_ADDR + 0x280
	mov		r4, r2, lsr #5
	mov		r4, r4, lsl #2
	add		r3, r3, r4 /*get the addr of clear register*/
	sub		r4, r2, r4, lsl #3
	mov		r1, #1 
	mov		r4, r1, lsl r4
	str		r4, [r3] /*clear the interrupt source*/
	mov 	r2, r2, lsl #2 /*a function pointer occupy 4 bytes*/
	ldr  	r0, =interrupt_routine_list
	ldr		r0, [r0, r2] /*set the routine address to r0*/
	ldr		r1, =default_interrupt_routine
	cmp 	r1, r0
	bne		proc_isr

disable_int_src:
	/*disable the interrupt, if no specified isr is attached.*/
	sub		r3, r3, #0x100 //enclear register
	str		r4, [r3]

proc_isr:
	mov 	lr, pc
	bx    	r0 /*process the interrupt*/
	ldmfd   sp!, {r0-r12,lr}
	subs    pc,lr,#4

	.endfunc
    .end
