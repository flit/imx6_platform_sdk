/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__CORTEX_A9_H__)
#define __CORTEX_A9_H__

#include <stdint.h>
#include <stdlib.h>

//! @addtogroup cortexa9
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @name Instruction macros
//@{
#define _ARM_NOP()  asm volatile ("nop\n")
#define _ARM_WFI()  asm volatile ("wfi\n")
#define _ARM_WFE()  asm volatile ("wfe\n")
#define _ARM_SEV()  asm volatile ("sev\n")
#define _ARM_DSB()	asm volatile ("dsb\n")
#define _ARM_ISB()	asm volatile ("isb\n")

#define _ARM_MRC(coproc, opcode1, Rt, CRn, CRm, opcode2)	\
    asm volatile ("mrc p" #coproc ", " #opcode1 ", %[output], c" #CRn ", c" #CRm ", " #opcode2 "\n" : [output] "=r" (Rt))
    
#define _ARM_MCR(coproc, opcode1, Rt, CRn, CRm, opcode2)	\
    asm volatile ("mcr p" #coproc ", " #opcode1 ", %[input], c" #CRn ", c" #CRm ", " #opcode2 "\n" :: [input] "r" (Rt))
//@}

//! @name Cache sizes
//@{
//! @brief Eight 32-bit words per cache line.
#define L1_CACHE_LINE_SIZE (32)
//@}

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @name Misc
//@{
//! @brief Get current CPU ID.
int cpu_get_current(void);

//! @brief Enable the NEON MPE.
void enable_neon_fpu(void);

//! @brief Disable aborts on unaligned accesses.
void disable_strict_align_check(void);

//! @brief Enable the L1 cache.
void enable_L1_cache(void);

//! @brief Get base address of private perpherial space.
//! 
//! @return The address of the ARM CPU's private peripherals.
uint32_t get_arm_private_peripheral_base(void);
//@}

//! @name Data cache operations
//@{
//! @brief Enables data cache at any available cache level.
//!
//! Works only if MMU is enabled!
void arm_dcache_enable();

//! @brief Disables the data cache at any available cache level.
void arm_dcache_disable();

//! @brief Invalidates the entire data cache.
void arm_dcache_invalidate();

//! @brief Invalidate a line of data cache.
void arm_dcache_invalidate_line(const void * addr);

//! @brief Invalidate a number of lines of data cache.
//!
//! Number of lines depends on length parameter and size of line.
//! Size of line for A9 L1 cache is 32B.
void arm_dcache_invalidate_mlines(const void * addr, size_t length);

//! @brief Flush (clean) all lines of cache (all sets in all ways).
void arm_dcache_flush();

//! @brief Flush (clean) one line of cache.
void arm_dcache_flush_line(const void * addr);

// @brief Flush (clean) multiple lines of cache.
//!
//! Number of lines depends on length parameter and size of line.
void arm_dcache_flush_mlines(const void * addr, size_t length);
//@}

//! @name Instrution cache operations
//@{
//! @brief Enables instruction cache at any available cache level.
//!
//! Works without enabled MMU too!
void arm_icache_enable();

//! @brief Disables the instruction cache at any available cache level.
void arm_icache_disable();

//! @brief Invalidates the entire instruction cache.
void arm_icache_invalidate();

//! @brief Invalidates the entire instruction cache inner shareable.
void arm_icache_invalidate_is();

//! @brief Invalidate a line of the instruction cache.
void arm_icache_invalidate_line(const void * addr);

//! @brief Invalidate a number of lines of instruction cache.
//!
//! Number of lines depends on length parameter and size of line.
void arm_icache_invalidate_mlines(const void * addr, size_t length);
//@}

//! @name TLB operations
//@{
//! @brief Invalidate entire unified TLB.
void arm_unified_tlb_invalidate(void);

//! @brief Invalidate entire unified TLB Inner Shareable.
void arm_unified_tlb_invalidate_is(void);
//@}

//! @name Branch predictor operations
//@{
//! @brief Enable branch prediction.
void arm_branch_prediction_enable(void);

//! @brief Disable branch prediction.
void arm_branch_prediction_disable(void);

//! @brief Invalidate entire branch predictor array.
void arm_branch_target_cache_invalidate(void);

//! @brief Invalidate entire branch predictor array Inner Shareable
void arm_branch_target_cache_invalidate_is(void);
//@}

//! @name SCU
//@{
//! @brief Enables the SCU.
void scu_enable(void);

//! @brief Set this CPU as participating in SMP.
void scu_join_smp(void);

//! @brief Set this CPU as not participating in SMP.
void scu_leave_smp(void);

//! @brief Determine which CPUs are participating in SMP.
//!
//! The return value is 1 bit per core:
//! - bit 0 - CPU 0
//! - bit 1 - CPU 1
//! - etc...
unsigned int scu_get_cpus_in_smp(void);

//! @brief Enable the broadcasting of cache & TLB maintenance operations.
//!
//! When enabled AND in SMP, broadcast all "inner sharable"
//! cache and TLM maintenance operations to other SMP cores
void scu_enable_maintenance_broadcast(void);

//! @brief Disable the broadcasting of cache & TLB maintenance operations.
void scu_disable_maintenance_broadcast(void);

//! @brief Invalidates the SCU copy of the tag rams for the specified core.
//!
//! Typically only done at start-up.
//! Possible flow:
//! - Invalidate L1 caches
//! - Invalidate SCU copy of TAG RAMs
//! - Join SMP
//!
//! @param cpu 0x0=CPU 0, 0x1=CPU 1, etc...
//! @param ways The ways to invalidate. Pass 0xf to invalidate all ways.
void scu_secure_invalidate(unsigned int cpu, unsigned int ways);
//@}

#if defined(__cplusplus)
}
#endif

//! @}

#endif // __CORTEX_A9_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
