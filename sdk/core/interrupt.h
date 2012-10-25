/*
 * Copyright (c) 2009-2012, Freescale Semiconductor, Inc.
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
#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include "irq_numbers.h"

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
