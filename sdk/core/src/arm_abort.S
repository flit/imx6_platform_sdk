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

    .code 32
    .section ".text","ax"

    .extern  dump_regs

/*
 * A very simple impletement of the abort handler.
 * Just dump the registers before this exception occured, to make the debugging easier.
 */
  .global  ABORT_HDLR
  .func  ABORT_HDLR
 ABORT_HDLR: 
	push {r0-r12} ;	//push the general registers to this exception's stack
	mrs r7, cpsr;
	mrs r6, spsr;
	mov r5, sp;
	msr cpsr, r6; //go to the mode before this exception
	dsb;
	stmfd r5!, {sp, lr}; //push sp/lr to this exception's stack
	msr cpsr, r7;
	dsb;
	mov sp, r5;
	push {r6, lr};
	mov r0, sp;
	bl  dump_regs; //dumping
	pop {r0-r12};
	add sp, sp, #16; //adjust the sp pointer, just like 'pop {lr, r6}'
1:
	b 1b;	        
	sub pc, lr, #4; //abort handler's standard return, although never reach here.
  .endfunc   

    .end
