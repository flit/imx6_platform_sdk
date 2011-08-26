/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gic.s
 * @brief This file contains GIC functions
 *
 */
#include "gic.h"

    .code 32
    .section ".gic","ax"
    
@ ------------------------------------------------------------
@ GIC
@ ------------------------------------------------------------

@ ------------------------------------------------------------
@ GIC Interrupt Distributor Functions
@ Interrupt Distributor offset from base of private peripheral space --> 0x1000
@ ------------------------------------------------------------

  .global enable_GIC
  @ void enable_GIC(void);
  @ Global enable of the Interrupt Distributor
  .func enable_GIC
enable_GIC: 

  @ Get base address of private perpherial space
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address
  ADD     r0, r0, #0x1000         @ Add the GIC Distributor offset

  LDR     r1, [r0]                @ Read the GIC's Enable Register  (ICDDCR)
  ORR     r1, r1, #0x03           @ the enable bits for imx cortex a9
  STR     r1, [r0]                @ Write the GIC's Enable Register  (ICDDCR)

  BX      lr
  .endfunc    @enable_GIC();
  
@ ------------------------------------------------------------

  .global disable_GIC
  @ void disable_GIC(void);
  @ Global disable of the Interrupt Distributor
  .func disable_GIC
disable_GIC:

  @ Get base address of private perpherial space
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address
  ADD     r0, r0, #0x1000         @ Add the GIC offset

  LDR     r1, [r0]                @ Read the GIC's Enable Register  (ICDDCR)
  BIC     r1, r1, #0x01           @ Set bit 0, the enable bit
  STR     r1, [r0]                @ Write the GIC's Enable Register  (ICDDCR)

  BX      lr
  .endfunc    @disable_GIC();

@ ------------------------------------------------------------

  .global  set_interrupt_as_nonsecure
  @ void set_interrupt_as_nonsecure(unsigned int ID);
  @ sets the interrupt source number ID as a non-secure interrupt
  .func set_interrupt_as_nonsecure
set_interrupt_as_nonsecure:

  @ Get base address of private perpherial space
  MOV     r1, r0                  @ Back up passed in ID value
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  @ Each interrupt source has an security bit in the GIC.  These
  @ are grouped into registers, with 32 sources per register
  @ First, we need to identify which 32 bit block the interrupt lives in
  MOV     r2, r1                  @ Make working copy of ID in r2
  MOV     r2, r2, LSR #5          @ LSR by 5 places, effectively dividing by 32
                                  @ r2 now contains the 32 bit block this ID lives in
  MOV     r2, r2, LSL #2          @ Now multiply by 4, to covert into an address offset

  @ Now work out which bit within the 32 bit block the ID is
  AND     r1, r1, #0x1F           @ Mask off to give offset within 32bit block
  MOV     r3, #1                  @ Move non-secure enable value into r3
  MOV     r3, r3, LSL r1          @ Shift it left to position of ID

  ADD     r2, r2, #0x1080         @ Add the base offset of the Enable Set registers to the offset for the ID
  LDR     r1, [r2]                @ Read the IDs Security Register (ICDISR)
  ORR     r1, r1, r3              @ Set ID bit position
  STR     r1, [r0, r2]            @ Write the IDs Security Register (ICDISR)
  
  BX      lr
  .endfunc    @set_interrupt_as_nonsecure

@ ------------------------------------------------------------

  .global  set_interrupt_as_nonsecure
  @ void set_interrupt_as_secure(unsigned int ID);
  @ sets the interrupt source number ID as a secure interrupt
  .func set_interrupt_as_secure
set_interrupt_as_secure:

  @ Get base address of private perpherial space
  MOV     r1, r0                  @ Back up passed in ID value
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  @ Each interrupt source has an security bit in the GIC.  These
  @ are grouped into registers, with 32 sources per register
  @ First, we need to identify which 32 bit block the interrupt lives in
  MOV     r2, r1                  @ Make working copy of ID in r2
  MOV     r2, r2, LSR #5          @ LSR by 5 places, effectively dividing by 32
                                  @ r2 now contains the 32 bit block this ID lives in
  MOV     r2, r2, LSL #2          @ Now multiply by 4, to covert into an address offset

  @ Now work out which bit within the 32 bit block the ID is
  AND     r1, r1, #0x1F           @ Mask off to give offset within 32bit block
  MOV     r3, #1                  @ Move non-secure enable value into r3
  MOV     r3, r3, LSL r1          @ Shift it left to position of ID

  ADD     r2, r2, #0x1080         @ Add the base offset of the Enable Set registers to the offset for the ID
  LDR     r1, [r0, r2]            @ Read the IDs Security Register (ICDISR)
  BIC     r1, r1, r3              @ Clear ID bit position to set as secure
  STR     r1, [r0, r2]            @ Write the IDs Security Register (ICDISR)
  
  BX      lr
  .endfunc    @set_interrupt_as_secure

@ ------------------------------------------------------------

  .global  enable_irq_id
  @ void enable_irq_id(unsigned int ID);
  @ Enables the interrupt source number ID
  .func enable_irq_id
enable_irq_id:

  @ Get base address of private perpherial space
  MOV     r1, r0                  @ Back up passed in ID value
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  @ Each interrupt source has an enable bit in the GIC.  These
  @ are grouped into registers, with 32 sources per register
  @ First, we need to identify which 32 bit block the interrupt lives in
  MOV     r2, r1                  @ Make working copy of ID in r2
  MOV     r2, r2, LSR #5          @ LSR by 5 places, affective divide by 32
                                  @ r2 now contains the 32 bit block this ID lives in
  MOV     r2, r2, LSL #2          @ Now multiply by 4, to covert offset into an address offset (four bytes per reg)

  @ Now work out which bit within the 32 bit block the ID is
  AND     r1, r1, #0x1F           @ Mask off to give offset within 32bit block
  MOV     r3, #1                  @ Move enable value into r3
  MOV     r3, r3, LSL r1          @ Shift it left to position of ID

  ADD     r2, r2, #0x1100         @ Add the base offset of the Enable Set registers to the offset for the ID
  STR     r3, [r0, r2]            @ Store out  (ICDISER)

  BX      lr
  .endfunc    @enable_irq_id

@ ------------------------------------------------------------

  .global  disable_irq_id
  @ void disable_irq_id(unsigned int ID);
  @ Disables the interrupt source number ID
  .func disable_irq_id
disable_irq_id:

  @ Get base address of private perpherial space
  MOV     r1, r0                  @ Back up passed in ID value
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  @ First, we need to identify which 32 bit block the interrupt lives in
  MOV     r2, r1                  @ Make working copy of ID in r2
  MOV     r2, r2, LSR #5          @ LSR by 5 places, affective divide by 32
                                  @ r2 now contains the 32 bit block this ID lives in
  MOV     r2, r2, LSL #2          @ Now multiply by 4, to covert offset into an address offset (four bytes per reg)

  @ Now work out which bit within the 32 bit block the ID is
  AND     r1, r1, #0x1F           @ Mask off to give offset within 32bit block
  MOV     r3, #1                  @ Move enable value into r3
  MOV     r3, r3, LSL r1          @ Shift it left to position of ID in 32 bit block

  ADD     r2, r2, #0x1180         @ Add the base offset of the Enable Clear registers to the offset for the ID
  STR     r3, [r0, r2]            @ Store out (ICDICER)

  BX      lr
  .endfunc    @diable_irq_id

@ ------------------------------------------------------------

  .global set_irq_priority
  @ void set_irq_priority(unsigned int ID, unsigned int priority);
  @ Sets the priority of the specifed ID
  @ r0 = ID
  @ r1 = priority
  .func set_irq_priority
set_irq_priority:

  @ Get base address of private perpherial space
  MOV     r2, r0                  @ Back up passed in ID value
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  @ r0 = base addr
  @ r1 = priority
  @ r2 = ID
  
  @ Make sure that priority value is only 8 bits, and convert to expected format
  AND     r1, r1, #0xFF

  @ Find which priority register this ID lives in
  BIC     r3, r2, #0x03           @ Make a copy of the ID, clearing off the bottom two bits
                                  @ There are four IDs per reg, by clearing the bottom two bits we get an address offset
  ADD     r3, r3, #0x1400         @ Now add the offset of the Priority Level registers from the base of the private peripheral space
  ADD     r0, r0, r3              @ Now add in the base address of the private peripheral space, giving us the absolute address


  @ Now work out which ID in the register it is
  AND     r2, r2, #0x03           @ Clear all but the bottom four bits, leaves which ID in the reg it is (which byte)
  MOV     r2, r2, LSL #3          @ Multiply by 8, this gives a bit offset

  MOV     r12, #0xFF              @ Mask (8 bits)
  MOV     r12, r12, LSL r2        @ Move mask into correct bit position
  MOV     r1, r1, LSL r2          @ Also, move passed in priority value into correct bit position

  LDR     r3, [r0]                @ Read current value of the Priority Level register (ICDIPR)
  BIC     r3, r3, r12             @ Clear appropiate field
  ORR     r3, r3, r1              @ Now OR in the priority value
  STR     r3, [r0]                @ And store it back again  (ICDIPR)

  BX      lr
  .endfunc    @set_irq_priority

@ ------------------------------------------------------------

  .global enable_interrupt_target_cpu
  @ void enable_interrupt_target_cpu(unsigned int ID, unsigned int target_cpu);
  @ enables the target cpu to handle interrupts of the specifed ID
  @ r0 = ID
  @ r1 = target_cpu (CPU0- CPU3)
  .func enable_interrupt_target_cpu
enable_interrupt_target_cpu:

  @ Get base address of private perpherial space
  MOV     r2, r0                  @ Back up passed in ID value
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  @ r0 = base addr
  @ r1 = target_CPU  (value = 0 thru MAX_CPUs) 4 CPUs for iMXQuad so 0-3
  @ r2 = ID
  
  @ Make sure that cpu value is only 2 bits max CPU value is 3
  AND     r1, r1, #0x3

  @ Find which cpu_target register this ID lives in
  BIC     r3, r2, #0x03           @ Make a copy of the ID, clearing off the bottom two bits
                                  @ There are four IDs per reg, by clearing the bottom two bits we get an address offset
  ADD     r3, r3, #0x1800         @ Now add the offset of the Target CPU registers from the base of the private peripheral space
  ADD     r0, r0, r3              @ Now add in the base address of the private peripheral space, giving us the absolute address


  @ Now work out which ID in the register it is
  AND     r2, r2, #0x03           @ Clear all but the bottom four bits, leaves which ID in the reg it is (which byte)
  MOV     r2, r2, LSL #3          @ Multiply by 8, this gives a bit offset

  MOV     r4, #1                  @ Move enable value into r4
  MOV     r4, r4, LSL r1          @ Shift it left to position of CPU target
  MOV     r4, r4, LSL r2          @ move it to correct bit ID offset position
  
  LDR     r3, [r0]                @ Read current value of the CPU Target register (ICDITR)  
  ORR     r3, r3, r4              @ Now OR in the CPU Target value
  STR     r3, [r0]                @ And store it back again  (ICDITR)

  BX      lr
  .endfunc    @enable_interrupt_target_cpu
  
@ ------------------------------------------------------------

  .global disable_interrupt_target_cpu
  @ void disable_interrupt_target_cpu(unsigned int ID, unsigned int target_cpu);
  @ disables the target cpu to handle interrupts of the specifed ID
  @ r0 = ID
  @ r1 = target_cpu (CPU0- CPU3)
  .func disable_interrupt_target_cpu
disable_interrupt_target_cpu:

  @ Get base address of private perpherial space
  MOV     r2, r0                  @ Back up passed in ID value
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  @ r0 = base addr
  @ r1 = target_CPU  (value = 0 thru MAX_CPUs) 4 CPUs for iMXQuad so 0-3
  @ r2 = ID
  
  @ Make sure that cpu value is only 2 bits max CPU value is 3
  AND     r1, r1, #0x3

  @ Find which cpu_target register this ID lives in
  BIC     r3, r2, #0x03           @ Make a copy of the ID, clearing off the bottom two bits
                                  @ There are four IDs per reg, by clearing the bottom two bits we get an address offset
  ADD     r3, r3, #0x1800         @ Now add the offset of the Target CPU registers from the base of the private peripheral space
  ADD     r0, r0, r3              @ Now add in the base address of the private peripheral space, giving us the absolute address


  @ Now work out which ID in the register it is
  AND     r2, r2, #0x03           @ Clear all but the bottom four bits, leaves which ID in the reg it is (which byte)
  MOV     r2, r2, LSL #3          @ Multiply by 8, this gives a bit offset

  MOV     r4, #1                  @ Move enable value into r4
  MOV     r4, r4, LSL r1          @ Shift it left to position of CPU target
  MOV     r4, r4, LSL r2          @ move it to correct bit ID offset position
  
  LDR     r3, [r0]                @ Read current value of the CPU Target register (ICDITR)  
  BIC     r3, r3, r4              @ Now clear the CPU Target value
  STR     r3, [r0]                @ And store it back again  (ICDITR)

  BX      lr
  .endfunc    @disable_interrupt_target_cpu

@ ------------------------------------------------------------

@ ------------------------------------------------------------
@ SGI
@ ------------------------------------------------------------
  .global send_sgi
  @ void send_sgi(unsigned int ID, unsigned int target_list, unsigned int filter_list);
  @ Send a software generate interrupt
  .func send_sgi
send_sgi:

  AND     r3, r0, #0x0F           @ Mask off unused bits of ID, and move to r3
  AND     r1, r1, #0x0F           @ Mask off unused bits of target_filter
  AND     r2, r2, #0x0F           @ Mask off unused bits of filter_list

  ORR     r3, r3, r1, LSL #16     @ Combine ID and target_filter
  ORR     r3, r3, r2, LSL #24     @ and now the filter list

  @ Get the address of the GIC
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address
  ADD     r0, r0, #0x1F00         @ Add offset of the sgi_trigger reg

  STR     r3, [r0]                @ Write to the Software Generated Interrupt Register  (ICDSGIR)

  BX      lr
  .endfunc    @send_sgi

@ ------------------------------------------------------------
@ GIC CPU Interface Functions
@ CPU Interface offset from base of private peripheral space --> 0x0100
@ ------------------------------------------------------------
  
  .global enable_gic_processor_interface
  @ void enable_gic_processor_interface(void);
  @ Enables the processor interface which must been done one each CPU seperately
  .func enable_gic_processor_interface 
enable_gic_processor_interface:

  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  LDR     r1, [r0, #0x100]        @ Read the Processor Interface Control register   (ICCICR/ICPICR)
  ORR     r1, r1, #0x03           @ Bit 0: Enables secure interrupts, Bit 1: Enables Non-Secure interrupts
  ORR     r1, r1, #0x04			  @ Bit 2: enables AckCtl
  STR     r1, [r0, #0x100]        @ Write the Processor Interface Control register  (ICCICR/ICPICR)

  BX      lr
  .endfunc	@enable_gic_processor_interface

@ ------------------------------------------------------------

  .global disable_gic_processor_interface
  @ void disable_gic_processor_interface(void);
  @ Disables the processor interface which must been done one each CPU seperately
  .func disable_gic_processor_interface
disable_gic_processor_interface:

  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address

  LDR     r1, [r0, #0x100]        @ Read the Processor Interface Control register   (ICCICR/ICPICR)
  BIC     r1, r1, #0x03           @ Bit 0: Enables secure interrupts, Bit 1: Enables Non-Secure interrupts
  STR     r1, [r0, #0x100]        @ Write the Processor Interface Control register  (ICCICR/ICPICR)

  BX      lr
  .endfunc @ disable_gic_processor_interface

@ ------------------------------------------------------------

  .global set_cpu_priority_mask
  @ void set_cpu_priority_mask(unsigned int priority);
  @ Sets the Priority mask register for the CPU run on
  @ r0 contains the passed in priority value; the reset value masks ALL interrupts!
  .func set_cpu_priority_mask
set_cpu_priority_mask:

  MRC     p15, 4, r1, c15, c0, 0  @ Read periph base address to r1
  
  STR     r0, [r1, #0x0104]       @ Write the Priority Mask register (ICCPMR/ICCIPMR)

  BX      lr
  .endfunc @ set_cpu_priority_mask
  
@ ------------------------------------------------------------

  .global  read_irq_ack
  @ unsigned int read_irq_ack(void);
  @ Returns the value of the Interrupt Acknowledge Register, this contains the interrupt ID
  .func read_irq_ack
read_irq_ack:
  MRC     p15, 4, r0, c15, c0, 0  @ Read periph base address
  LDR     r0, [r0, #0x010C]       @ Read the Interrupt Acknowledge Register  (ICCIAR)
  BX      lr
  .endfunc @ read_irq_ack

@ ------------------------------------------------------------

  .global  write_end_of_irq
  @ void write_end_of_irq(unsigned int ID);
  @ Writes ID to the End Of Interrupt register
  .func write_end_of_irq
write_end_of_irq:

  MRC     p15, 4, r1, c15, c0, 0  @ Read periph base address
  STR     r0, [r1, #0x0110]       @ Write ID to the End of Interrupt register (ICCEOIR)

  BX      lr
  .endfunc @ write_end_of_irq

@ ------------------------------------------------------------
@ End of gic.s
@ ------------------------------------------------------------
    .end
