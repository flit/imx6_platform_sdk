/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "core/cortex_a9.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void arm_dcache_enable()
{
    uint32_t sctlr;// System Control Register 
    
    // read sctlr 
    _ARM_MRC(15, 0, sctlr, 1, 0, 0);

    // set  C bit (data caching enable) 
    sctlr |= 0x1 << 2; // |= sctlr_C_MASK

    // write modified sctlr
    _ARM_MCR(15, 0, sctlr, 1, 0, 0);
    
    // All Cache, Branch predictor and TLB maintenance operations before followed instruction complete
    _ARM_DSB();
}

void arm_dcache_disable()
{
    uint32_t sctlr;// System Control Register 
    
    // read sctlr 
    _ARM_MRC(15, 0, sctlr, 1, 0, 0);
    
    // set  C bit (data caching enable) 
    sctlr &= ~(0x1 << 2);   //&= ~(sctlr_C_MASK)

    // write modified sctlr
    _ARM_MCR(15, 0, sctlr, 1, 0, 0);
    
    // All Cache, Branch predictor and TLB maintenance operations before followed instruction complete
    _ARM_DSB();
}

void arm_dcache_invalidate()
{
    uint32_t csid;    // Cache Size ID
    uint32_t wayset;  // wayset parameter 
    int num_sets; // number of sets  
    int num_ways; // number of ways

    _ARM_MRC(15, 1, csid, 0, 0, 0);    // Read Cache Size ID 
    
    // Fill number of sets  and number of ways from csid register  This walues are decremented by 1
    num_ways = (csid >> 0x03) & 0x3FFu; //((csid& csid_ASSOCIATIVITY_MASK) >> csid_ASSOCIATIVITY_SHIFT)
    
    // Invalidation all lines (all Sets in all ways) 
    while (num_ways >= 0)
    {
        num_sets = (csid >> 0x13) & 0x7FFFu; //((csid & csid_NUMSETS_MASK) >> csid_NUMSETS_SHIFT)
        while (num_sets >= 0 )
        {
            wayset = (num_sets << 5u) | (num_ways << 30u); //(num_sets << SETWAY_SET_SHIFT) | (num_sets << 3SETWAY_WAY_SHIFT)
            // invalidate line if we know set and way 
            _ARM_MCR(15, 0, wayset, 7, 6, 2);
            num_sets--;
        }
        num_ways--;
    }
    
    // All Cache, Branch predictor and TLB maintenance operations before followed instruction complete
    _ARM_DSB();
}

void arm_dcache_invalidate_line(const void * addr)
{
    uint32_t va = (uint32_t) addr & 0xfffffff0; //addr & va_VIRTUAL_ADDRESS_MASK
    
    // Invalidate data cache line by va to PoC (Point of Coherency). 
    _ARM_MCR(15, 0, va, 7, 6, 1);
    
    // All Cache, Branch predictor and TLB maintenance operations before followed instruction complete
    _ARM_DSB();
}

void arm_dcache_invalidate_mlines(const void * addr, size_t length)
{
    uint32_t va;
    const void * end_addr = (const void *)((uint32_t)addr + length);
    
    do
    {
        // Clean data cache line to PoC (Point of Coherence) by va. 
        va = (uint32_t) ((uint32_t)addr & 0xfffffff0); //addr & va_VIRTUAL_ADDRESS_MASK
        _ARM_MCR(15, 0, va, 7, 6, 1);
        // increment addres to next line and decrement lenght 
        addr = (const void *) ((uint32_t)addr + L1_CACHE_LINE_SIZE);
    } while (addr < end_addr);
    
    // All Cache, Branch predictor and TLB maintenance operations before followed instruction complete
    _ARM_DSB();
}

void arm_dcache_flush()
{
    uint32_t csid;    // Cache Size ID
    uint32_t wayset;  // wayset parameter 
    int num_sets; // number of sets  
    int num_ways; // number of ways

    _ARM_MRC(15, 1, csid, 0, 0, 0);    // Read Cache Size ID 
    
    // Fill number of sets  and number of ways from csid register  This walues are decremented by 1
    num_ways = (csid >> 0x03) & 0x3FFu; //((csid& csid_ASSOCIATIVITY_MASK) >> csid_ASSOCIATIVITY_SHIFT`)
    while (num_ways >= 0)
    {
        num_sets = (csid >> 0x13) & 0x7FFFu; //((csid & csid_NUMSETS_MASK)      >> csid_NUMSETS_SHIFT       )
        while (num_sets >= 0 )
        {
            wayset = (num_sets << 5u) | (num_ways << 30u); //(num_sets << SETWAY_SET_SHIFT) | (num_ways << 3SETWAY_WAY_SHIFT)
            // FLUSH (clean) line if we know set and way 
            _ARM_MCR(15, 0, wayset, 7, 10, 2);
            num_sets--;
        }
        num_ways--;
    }
    
    // All Cache, Branch predictor and TLB maintenance operations before followed instruction complete
    _ARM_DSB();
}

void arm_dcache_flush_line(const void * addr)
{
    uint32_t va = (uint32_t) addr & 0xfffffff0; //addr & va_VIRTUAL_ADDRESS_MASK
    
    // Clean data cache line to PoC (Point of Coherence) by va. 
    _ARM_MCR(15, 0, va, 7, 10, 1);
    
    // All Cache, Branch predictor and TLB maintenance operations before followed instruction complete
    _ARM_DSB();
}

void arm_dcache_flush_mlines(const void * addr, size_t length)
{
    uint32_t va;
    const void * end_addr = (const void *)((uint32_t)addr + length);
    
    do
    {
        // Clean data cache line to PoC (Point of Coherence) by va. 
        va = (uint32_t) ((uint32_t)addr & 0xfffffff0); //addr & va_VIRTUAL_ADDRESS_MASK
        _ARM_MCR(15, 0, va, 7, 10, 1);
        // increment addres to next line and decrement lenght 
        addr = (const void *) ((uint32_t)addr + L1_CACHE_LINE_SIZE);
    } while (addr < end_addr);
    
    // All Cache, Branch predictor and TLB maintenance operations before followed instruction complete
    _ARM_DSB();
}

void arm_icache_enable()
{
    uint32_t sctlr  ;// System Control Register 
    
    // read sctlr 
    _ARM_MRC(15, 0, sctlr, 1, 0, 0);
    
    // set  I bit (instruction caching enable) 
    sctlr |= 0x1 << 12;  // |= sctlr_I_MASK

    // write modified sctlr
    _ARM_MCR(15, 0, sctlr, 1, 0, 0);
    
    // synchronize context on this processor 
    _ARM_ISB();
}

void arm_icache_disable()
{
    uint32_t sctlr  ;// System Control Register 
    
    // read sctlr 
    _ARM_MRC(15, 0, sctlr, 1, 0, 0);
    
    // Clear  I bit (instruction caching enable) 
    sctlr &= ~(0x1 << 12); // &= ~sctlr_I_MASK

    // write modified sctlr
    _ARM_MCR(15, 0, sctlr, 1, 0, 0);
    
    // synchronize context on this processor 
    _ARM_ISB();
}

void arm_icache_invalidate()
{
    uint32_t SBZ = 0x0u;
    
    _ARM_MCR(15, 0, SBZ, 7, 5, 0);
    
    // synchronize context on this processor 
    _ARM_ISB();
}

void arm_icache_invalidate_is()
{
    uint32_t SBZ = 0x0u;
    
    _ARM_MCR(15, 0, SBZ, 7, 1, 0);
    
    // synchronize context on this processor 
    _ARM_ISB();
}

void arm_icache_invalidate_line(const void * addr)
{
    uint32_t va = (uint32_t) addr & 0xfffffff0; //addr & va_VIRTUAL_ADDRESS_MASK
    
    // Invalidate instruction cache by va to PoU (Point of unification). 
    _ARM_MCR(15, 0, va, 7, 5, 1);
    
    // synchronize context on this processor 
    _ARM_ISB();
}

void arm_icache_invalidate_mlines(const void * addr, size_t length)
{
    uint32_t va;
    const void * end_addr = (const void *)((uint32_t)addr + length);
    
    do
    {
        // Clean data cache line to PoC (Point of Coherence) by va. 
        va = (uint32_t) ((uint32_t)addr & 0xfffffff0); //addr & va_VIRTUAL_ADDRESS_MASK
        _ARM_MCR(15, 0, va, 7, 5, 1);
        // increment addres to next line and decrement lenght 
        addr = (const void *) ((uint32_t)addr + L1_CACHE_LINE_SIZE);
    } while (addr < end_addr);
    
    // synchronize context on this processor 
    _ARM_ISB();
}


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
