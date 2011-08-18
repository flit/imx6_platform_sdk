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
void set_interrupt_as_nonsecure(uint32_t irq_id);
void set_interrupt_as_secure(uint32_t irq_id);
void enable_irq_id(uint32_t irq_id);
void disable_irq_id(uint32_t irq_id);
void set_irq_priority(uint32_t irq_id, uint32_t priority);
void enable_interrupt_target_cpu(uint32_t irq_id, uint32_t target_cpu);
void disable_interrupt_target_cpu(uint32_t irq_id, uint32_t target_cpu);

// GIC CPU Interface Functions
void enable_gic_processor_interface(void);
void disable_gic_processor_interface(void);
void set_cpu_priority_mask(uint32_t priority);
uint32_t read_irq_ack(void);
void write_end_of_irq(uint32_t irq_id);

#endif /*GIC_H_ */
