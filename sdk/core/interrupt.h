/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

//! @addtogroup diag_interrupt
//! @{

/*!
 * @file  interrupt.h
 */

#define ATTACH_INTERRUPT(index,routine) ( g_interrupt_handlers[index] = routine )

typedef enum {
    CPU_0,
    CPU_1,
    CPU_2,
    CPU_3,
} cpuid_e;

extern void (*g_interrupt_handlers[]) (void);
extern volatile uint32_t g_vectNum[4];

typedef void (*irq_hdlr_t) (void);

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

void disable_interrupt(uint32_t irq_id, uint32_t cpu_id);
void enable_interrupt(uint32_t irq_id, uint32_t cpu_id, uint32_t priority);
void register_interrupt_routine(uint32_t irq_id, irq_hdlr_t isr);
void default_interrupt_routine(void);

void enableALL_interrupts_non_secure(void);

#if defined(__cplusplus)
}
#endif

//! @}

#endif
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
