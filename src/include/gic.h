/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef GIC_H_
#define GIC_H_

// ------------------------------------------------------------
// GIC
// ------------------------------------------------------------

// GIC Interrupt Distributor Functions
void enable_GIC(void);
void disable_GIC(void);
void set_interrupt_as_nonsecure(unsigned int ID);
void set_interrupt_as_secure(unsigned int ID);
void enable_irq_id(unsigned int ID);
void disable_irq_id(unsigned int ID);
void set_irq_priority(unsigned int ID, unsigned int priority);
void enable_interrupt_target_cpu(unsigned int ID, unsigned int target_cpu);
void disable_interrupt_target_cpu(unsigned int ID, unsigned int target_cpu);

// GIC CPU Interface Functions
void enable_gic_processor_interface(void);
void disable_gic_processor_interface(void);
void set_cpu_priority_mask(unsigned int priority);
unsigned int read_irq_ack(void);
void write_end_of_irq(unsigned int ID);

#endif /*GIC_H_ */
