/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#include "gic/gic.h"
#include "gic_registers.h"
#include "cortex_a9.h"

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

static inline gicd_t * gic_get_gicd(void);
static inline gicc_t * gic_get_gicc(void);
static inline uint32_t irq_get_register_offset(uint32_t irqID);
static inline uint32_t irq_get_bit_offset(uint32_t irqID);
static inline uint32_t irq_get_bit_mask(uint32_t irqID);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

static inline gicd_t * gic_get_gicd(void)
{
    uint32_t base = get_arm_private_peripheral_base() + kGICDBaseOffset;
    return (gicd_t *)base;
}

static inline gicc_t * gic_get_gicc(void)
{
    uint32_t base = get_arm_private_peripheral_base() + kGICCBaseOffset;
    return (gicc_t *)base;
}

static inline uint32_t irq_get_register_offset(uint32_t irqID)
{
    return irqID / 32;
}

static inline uint32_t irq_get_bit_offset(uint32_t irqID)
{
    return irqID & 0x1f;
}

static inline uint32_t irq_get_bit_mask(uint32_t irqID)
{
    return 1 << irq_get_bit_offset(irqID);    
}

void gic_enable(bool enableIt)
{
    gicd_t * gicd = gic_get_gicd();
    
    if (enableIt)
    {
        // Enable both secure and non-secure.
        gicd->CTLR |= kBM_GICD_CTLR_EnableGrp0 | kBM_GICD_CTLR_EnableGrp1;
    }
    else
    {
        // Clear non-secure enable bit.
        gicd->CTLR &= ~kBM_GICD_CTLR_EnableGrp1;
    }
}

void gic_set_irq_security(uint32_t irqID, bool isSecure)
{
    gicd_t * gicd = gic_get_gicd();
    
    uint32_t reg = irq_get_register_offset(irqID);
    uint32_t mask = irq_get_bit_mask(irqID);
    
    uint32_t value = gicd->IGROUPRn[reg];
    if (!isSecure)
    {
        value &= ~mask;
    }
    else
    {
        value |= mask;
    }
    gicd->IGROUPRn[reg] = value;
}

void gic_enable_irq(uint32_t irqID, bool isEnabled)
{
    gicd_t * gicd = gic_get_gicd();
    
    uint32_t reg = irq_get_register_offset(irqID);
    uint32_t mask = irq_get_bit_mask(irqID);
    
    // Select set-enable or clear-enable register based on enable flag.
    if (isEnabled)
    {
        gicd->ISENABLERn[reg] = mask;
    }
    else
    {
        gicd->ICENABLERn[reg] = mask;
    }
}

void gic_set_irq_priority(uint32_t ID, uint32_t priority)
{
    gicd_t * gicd = gic_get_gicd();
    
    // Update the priority register. The priority registers are byte accessible, and the register
    // struct has the priority registers as a byte array, so we can just index directly by the
    // interrupt ID.
    gicd->IPRIORITYRn[ID] = priority & 0xff;
}

void gic_set_cpu_target(uint32_t irqID, uint32_t cpuMask, bool enableIt)
{
    gicd_t * gicd = gic_get_gicd();
    
    // Like the priority registers, the target registers are byte accessible, and the register
    // struct has the them as a byte array, so we can just index directly by the
    // interrupt ID.
    if (enableIt)
    {
        gicd->ITARGETSRn[irqID] |= (cpuMask & 0xff);
    }
    else
    {
        gicd->ITARGETSRn[irqID] &= ~(cpuMask & 0xff);
    }
}

void gic_send_sgi(uint32_t irqID, uint32_t target_list, uint32_t filter_list)
{
    gicd_t * gicd = gic_get_gicd();
    
    gicd->SGIR = (filter_list << kBP_GICD_SGIR_TargetListFilter)
                    | (target_list << kBP_GICD_SGIR_CPUTargetList)
                    | (irqID & 0xf);
}

void gic_cpu_enable(bool enableIt)
{
    gicc_t * gicc = gic_get_gicc();
    
    if (enableIt)
    {
        gicc->CTLR |= kBM_GICC_CTLR_EnableS | kBM_GICC_CTLR_EnableNS;
    }
    else
    {
        gicc->CTLR &= ~kBM_GICC_CTLR_EnableNS;
    }
}

void gic_set_cpu_priority_mask(uint32_t priority)
{
    gicc_t * gicc = gic_get_gicc();
    gicc->PMR = priority & 0xff;    
}

uint32_t gic_read_irq_ack(void)
{
    gicc_t * gicc = gic_get_gicc();
    return gicc->IAR;
}

void gic_write_end_of_irq(uint32_t irqID)
{
    gicc_t * gicc = gic_get_gicc();
    gicc->EOIR = irqID;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
