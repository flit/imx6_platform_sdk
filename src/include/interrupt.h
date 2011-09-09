
/*
 * Copyright (C) 2009-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_init Base SDK files
 */

/*!
 * @file  interrupt.h
 *
 * @ingroup diag_init
 */

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

/* The list of interrupts ID can be found into src/include/mx??/soc_memory_map.h */

#define ATTACH_INTERRUPT(index,routine) ( g_interrupt_handlers[index] = routine )

#define CPU_0   0
#define CPU_1   1
#define CPU_2   2
#define CPU_3   3

#define POLLING_MODE 0

extern void (*g_interrupt_handlers[]) (void);

typedef void (*irq_hdlr_t) (void);

void disable_interrupt(uint32_t irq_id, uint32_t cpu_num);
void enable_interrupt(uint32_t irq_id, uint32_t cpu_num, uint32_t priority);
void register_interrupt_routine(uint32_t irq_id, irq_hdlr_t isr);
void default_interrupt_routine(void);

void enableALL_interrupts_non_secure(void);

#endif
