/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __GIC_H__
#define __GIC_H__

#include "sdk_types.h"

//! @addtogroup gic
//! @{

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif


//! @name GIC Interrupt Distributor Functions
//@{
void gic_enable(bool enableIt);
void gic_set_irq_security(uint32_t irqID, bool isSecure);
void gic_enable_irq(uint32_t irqID, bool isEnabled);
void gic_set_cpu_target(uint32_t irqID, uint32_t cpuMask, bool enableIt);
void gic_set_irq_priority(uint32_t irq_id, uint32_t priority);
void gic_send_sgi(uint32_t irq_id, uint32_t target_cpu, uint32_t filter);
//@}

//! @name GIC CPU Interface Functions
//@{
void gic_cpu_enable(bool enableIt);
void gic_set_cpu_priority_mask(uint32_t priority);
uint32_t gic_read_irq_ack(void);
void gic_write_end_of_irq(uint32_t irq_id);
//@}


#if defined(__cplusplus)
}
#endif

//! @}

#endif // __GIC_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
