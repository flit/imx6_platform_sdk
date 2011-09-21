/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
  
/*!
 * @file startup.s
 * @brief this file contains startup code with support for multi-core startup
 * @for imx6quad/dual
 */
    .code 32
    .section ".startup","ax"
    
	.equ Mode_USR, 0x10
	.equ Mode_FIQ, 0x11
	.equ Mode_IRQ, 0x12
	.equ Mode_SVC, 0x13
	.equ Mode_ABT, 0x17
	.equ Mode_UND, 0x1B
	.equ Mode_SYS, 0x1F 

	.equ I_Bit, 0x80 @ /* when I bit is set EQU IRQ is disabled */
	.equ F_Bit, 0x40 @ /* when F bit is set EQU FIQ is disabled */

	@ exception vector adddress holders in iRAM for iMX6Quad/Dual
	.equ IRQ_MEM_ADDR, 0x0093fff4
	.equ FIQ_MEM_ADDR, 0x0093fff8
    
    .global startup_imx6x
    .func startup_imx6x 
startup_imx6x:
    mov 	r4, r0	@ save r0 for cores 1-3, r0 arg field passed by ROM
                @ r0 is a function pointer for secondary cpus

    ldr		r0, =top_of_stacks  @ symbol defined in $(TARGET).ld linker file
    mov		r1, #2048           @1024*2 is STACK_SIZE per cpu

    @ get cpu id, and subtract the offset from the stacks base address
    mrc     p15,0,r2,c0,c0,5  @ read multiprocessor affinity register
    and     r2, r2, #3        @ mask off, leaving CPU ID field
    mov     r5, r2		     @ save cpu id for later
    mul     r3, r2, r1
    sub     r0, r0, r3
  
    mov     r1, r1, lsl #2
           
    @ set stack for SVC mode
    mov     sp, r0 

    @ set stacks for all other modes 
    msr     CPSR_c, #Mode_FIQ | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    msr     CPSR_c, #Mode_IRQ | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    msr     CPSR_c, #Mode_ABT | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    msr     CPSR_c, #Mode_UND | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    msr     CPSR_c, #Mode_SYS | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    @ go back to SVC mode and enable interrupts
    msr     CPSR_c, #Mode_SVC
   
    @ check cpu id - cpu0 is primary cpu
    cmp r5, #0
    bleq primary_cpu_init	
    blne secondary_cpus_init	

primary_cpu_init:
    @@  set-up exception vectors, update ISR jump addresses    
    ldr		r0, =IRQ_MEM_ADDR
    ldr		r1, =IRQ_HDLR
    str		r1, [r0]
   
   	/* init .bss */
    /* clear the .bss section (zero init) */
    ldr     r1,=__bss_start__
    ldr     r2,=__bss_end__
    mov     r3,#0
1:
    cmp     r1,r2
    stmltia r1!,{r3}
    blt     1b
   
    @bl enable_scu
    @bl enableALL_interrupts_non_secure
   
    mov r0, #0xFF	   @ 0xFF is lowest priority level
    bl set_cpu_priority_mask
   
    bl enable_gic_processor_interface
    bl enable_GIC
   
    @ branch to c library entry point 
    ldr     r12, =main               /* save this in register for possible long jump */
    bx      r12                         /* branch to __main */ 

secondary_cpus_init:
    @bl secondary_cpus_init  @ debug endless loop
    mov r0, #0xFF	   @ 0xFF is lowest priority level
    bl set_cpu_priority_mask
    bl enable_gic_processor_interface   
    bx r4		       @ jump to argument function pointer passed in by ROM 
	
    .endfunc    @ startup_imx6x()

    .end

