/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__CORTEX_A9_H__)
#define __CORTEX_A9_H__

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif


//! @brief Get current CPU ID.
int getCPUnum(void);

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


#if defined(__cplusplus)
}
#endif

#endif // __CORTEX_A9_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
