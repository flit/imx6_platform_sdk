/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__SPINLOCK_H__)
#define __SPINLOCK_H__

#include <stdint.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Typedef for a spinlock.
typedef volatile uint32_t spinlock_t;

//! @brief Special timeout values for the spinlock.
enum _spinlock_timeouts
{
    //! Timeout value meaning do not block at all if the spinlock isn't free.
    kSpinlockNoWait = 0,
    
    //! Timeout value to use to wait indefinitely for the spinlock to become available.
    kSpinlockWaitForever = 0xffffffff
};

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @name Spinlock API
//@{

//! @brief Initialize a new spinlock.
//!
//! The spinlock is initialized in the unlocked state. Call spinlock_lock() if you need it
//! to be locked.
//!
//! @param lock Pointer to the new spinlock.
void spinlock_init(spinlock_t * lock);

//! @brief Lock the given spinlock.
//!
//! Use this function to lock a spinlock. If the spinlock is unlocked, it will be locked and
//! this function will return immediately. However, if the spinlock is already locked then
//! this function will block for up to @a timeout microseconds waiting for another thread to
//! unlock it.
//!
//! If #kSpinlockNoWait is passed for the timeout, then the function will not block at all.
//! In this case, either the spinlock is locked immediately or it is left untouched.
//!
//! To wait infinitely for the spinlock to become free, pass #kSpinlockWaitForever. If the
//! spinlock is already locked and no other thread unlocks it, then this function will never
//! return (i.e., deadlock).
//!
//! @param lock Pointer to the spinlock to lock.
//! @param timeout Maximum number of microseconds to block waiting for the spinlock to become
//!     available if it was locked upon entry to this function.
//!
//! @retval 0 The spinlock was locked successfully.
//! @retval 1 A timeout occurred while waiting for the spinlock to be unlocked.
int spinlock_lock(spinlock_t * lock, uint32_t timeout);

//! @brief Unlock the given spinlock.
//!
//! @param lock Pointer to the spinlock to unlock.
void spinlock_unlock(spinlock_t * lock);

//! @brief Check whether a spinlock is currently locked.
//!
//! @param lock Pointer to the spinlock to test.
bool spinlock_is_locked(spinlock_t * lock);

//@}

#if defined(__cplusplus)
}
#endif

#endif // __SPINLOCK_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
