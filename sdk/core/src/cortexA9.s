/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file cortexA9.s
 * @brief This file contains cortexA9 functions
 *
 */
 
    .code 32
    .section ".cortexA9","ax"

	.equ STRONGLY_ORDERED,  0x00010C02
	.equ OUTER_INNER_WB_WA, 0x00001C0E	
	.equ OUTER_INNER_WT,	0x00000C0A
	.equ OUTER_INNER_WT_S,	0x00010C0A
	.equ DEVICE_SHARED,		0x00010C06
	.equ DEVICE_NSHARED,	0x00002C02
	.equ NON_CACHABLE,		0x00001C02

	.equ PAGE_TABLE_ADDR,	0x00930000 @ store the page table in IRAM

	.equ L2CC_REG1_CTRL,	0x00A02100
	.equ L2CC_INV_REG,		0x00A0277C
	.equ L2CC_TAG_R_CTRL,	0x00A02108
	.equ L2CC_DAT_R_CTRL,	0x00A0210C
	.equ L2CC_PREFETCH_CTRL,0x00A02F60

  .global cpu_get_current
  @ int cpu_get_current(void);
  @ get current CPU ID
  .func cpu_get_current
cpu_get_current: 
    MRC   p15, 0, r0, c0, c0, 5
    AND   r0, r0, #3
	BX	  lr
  .endfunc    @cpu_get_current();

  .global enable_neon_fpu
  .func enable_neon_fpu
enable_neon_fpu:
	/* set NSACR, both Secure and Non-secure access are allowed to NEON */
	MRC p15, 0, r0, c1, c1, 2
	ORR r0, r0, #(0x3<<10) @ enable fpu/neon
	MCR p15, 0, r0, c1, c1, 2
	/* Set the CPACR for access to CP10 and CP11*/
	LDR r0, =0xF00000
	MCR p15, 0, r0, c1, c0, 2
	/* Set the FPEXC EN bit to enable the FPU */
	MOV r3, #0x40000000 
	@VMSR FPEXC, r3
	MCR p10, 7, r3, c8, c0, 0
  .endfunc

  .global disable_strict_align_check
  .func disable_strict_align_check
disable_strict_align_check:
  	/*Ray's note: disable strict alignment fault checking.
 	without disabling this, data abort will happen when accessing
	the BPB structure of file system since it is packed.*/
    
  	push	{r0, lr}
	
	mrc p15, 0, r0, c1, c0, 0
	bic r0, r0, #(0x1<<1) @clear A bit of SCTLR 
	mcr p15, 0, r0, c1, c0, 0

    pop {r0, pc}
  .endfunc

  .global disable_L1_cache
  .func disable_L1_cache
disable_L1_cache:
    push	{r0-r6, lr}

	mrc p15, 0, r0, c1, c0, 0
	bic r0, r0, #(0x1<<12) 
	bic r0, r0, #(0x1<<11) 
	bic r0, r0, #(0x1<<2) 
	bic r0, r0, #(0x1<<0) 
	mcr p15, 0, r0, c1, c0, 0

    pop {r0-r6, pc}

  .endfunc
  
  .global enable_L1_cache
  .func enable_L1_cache
enable_L1_cache:
    push	{r0-r6, lr}
    mov     r0, #0
    mcr		p15, 0, r0, c7, c5,6  @ invalidate btac
    mcr		p15, 0, r0, c7, c5,0  @ invalidate icache

    mov     r0, #0
    mcr		p15, 2, r0, c0, c0, 0  @ cache size selection register, select dcache
    mrc		p15, 1, r0, c0, c0, 0  @ cache size ID register
    mov     r0, r0, ASR #13
    ldr     r3, =0xfff
    and     r0, r0, r3
    cmp     r0, #0x7f
    moveq   r6, #0x1000
    beq     size_done
    cmp     r0, #0xff
    moveq   r6, #0x2000
    movne   r6, #0x4000

size_done:      
    mov     r2, #0
    mov     r3, #0x40000000
    mov     r4, #0x80000000
    mov     r5, #0xc0000000

d_inv_loop:     
    mcr	p15, 0, r2, c7, c6, 2  @ invalidate dcache by set / way
    mcr	p15, 0, r3, c7, c6, 2  @ invalidate dcache by set / way
    mcr	p15, 0, r4, c7, c6, 2  @ invalidate dcache by set / way
    mcr	p15, 0, r5, c7, c6, 2  @ invalidate dcache by set / way
    add r2, r2, #0x20
    add r3, r3, #0x20
    add r4, r4, #0x20
    add r5, r5, #0x20

    cmp     r2, r6
    bne     d_inv_loop

	/*before the Cache is enabled, system_memory_arrange must be run*/
    mrc     p15, 0, r0, c1, c0, 0    @ read CP15 register 1 into r0
    orr     r0, r0, #(0x1<<12)     @ enable I Cache
    orr     r0, r0, #(0x1<<11)     @ turn on BP
    orr     r0, r0, #(0x1<<2)      @ enable D Cache
    orr     r0, r0, #(0x1<<0)      @ enable MMU
    mcr     p15, 0, r0, c1, c0, 0    @ write CP15 register 1

    pop {r0-r6, pc}

  .endfunc

  .global get_arm_private_peripheral_base
  @ uint32_t get_arm_private_peripheral_base(void);
  .func get_arm_private_peripheral_base
get_arm_private_peripheral_base: 

  @ Get base address of private perpherial space
  mrc     p15, 4, r0, c15, c0, 0  @ Read periph base address
  bx      lr
  
  .endfunc    @get_arm_private_peripheral_base();

@ ------------------------------------------------------------
@ End of cortexA9.s
@ ------------------------------------------------------------
    .end
