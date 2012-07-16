/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__ATOMICS_H__)
#define __ATOMICS_H__

#include <stdint.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @name Atomic operations
//@{

//! @brief Atomic compare and swap operation.
//!
//! Tests the word pointed to by @a value for equality with @a oldValue. If they are
//! equal, the word pointed to by @a value is set to @a newValue. If *value is not
//! equal to @a oldValue, then no change is made. The return value indicates whether
//! the swap was performed. Of course, this entire operation is guaranteed to be
//! atomic even on multiprocessor platforms.
//!
//! A memory barrier is performed prior to the compare and swap operation.
//!
//! @param value Pointer to the word to compare and swap.
//! @param oldValue Value to compare against.
//! @param newValue Value to value to swap in if *value is equal to oldValue.
//! @retval false No change was made to *value.
//! @retval true The swap was performed, and *value is now equal to newValue.
bool atomic_compare_and_swap(volatile uint32_t * value, uint32_t oldValue, uint32_t newValue);

//! @brief Atomic add operation.
//!
//! A memory barrier is performed prior to the add operation.
//!
//! @param value Pointer to the word to add to.
//! @param delta Signed value to atomically add to *value.
//! @return The original value is returned.
int32_t atomic_add(volatile int32_t * value, int32_t delta);

//! @brief Atomically increment a value.
//!
//! @param value Pointer to the word to increment.
//! @return The original value is returned.
int32_t atomic_increment(volatile int32_t * value);

//! @brief Atomically decrement a value.
//!
//! @param value Pointer to the word to decrement.
//! @return The original value is returned.
int32_t atomic_decrement(volatile int32_t * value);

//@}

#if defined(__cplusplus)
}
#endif

#endif // __ATOMICS_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
