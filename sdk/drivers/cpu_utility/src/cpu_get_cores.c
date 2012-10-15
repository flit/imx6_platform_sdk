/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "sdk.h"
#include "registers/regsocotp.h"
#include "cpu_utility/cpu_utility.h"


//////////////////////////////////////////////////////////////////////////////////////////
// Definitions
//////////////////////////////////////////////////////////////////////////////////////////

//! @name Core number available OTP register constants 
//!{
#define CORE_NUM_MASK (0x0300000) //!< Number of cores available bit mask.
#define CORE_NUM_SHIFT (20)       //!< Number of cores available bit shift.
//@}

//! @name Number of cores constants in OTP register
//!
//! The same OTP bits are used for both MX6DQ and MX6SDL to determine the number
//! of available cores. But the default value of 0 has a different meaning for
//! the two chips.
//!{
#if defined(CHIP_MX6DQ)
#define FOUR_CORES (0)            //!< Four cores available register value.
#define TWO_CORES (2)             //!< Two cores available register value.
#elif defined(CHIP_MX6SDL)
#define TWO_CORES (0)             //!< Two cores available register value.
#define ONE_CORE (1)             //!< One cores available register value.
#endif
//@}

//////////////////////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////////////////////

int cpu_get_cores(void)
{
    int core_count = GET_CORES_ERROR;             

#if defined(CHIP_MX6DQ) || defined(CHIP_MX6SDL)
    // Mask and shift the contents of the control register so bit 21 and 20, which
    // are responsible for tracking cpu accessbility, are isolated.
    uint32_t raw_data = (HW_OCOTP_CFG2_RD() & CORE_NUM_MASK) >> CORE_NUM_SHIFT;
    
    // Determine whether there are 2 or 4 cores active and set the return
    // value accordingly. If no core is active, return error.
    switch(raw_data)
    {
// 4 cores only available on mx6dq
#if defined(CHIP_MX6DQ)
        case FOUR_CORES:
            core_count = FOUR_CORES_ACTIVE;
            break;
#endif // defined(CHIP_MX6DQ)
        case TWO_CORES:
            core_count = TWO_CORES_ACTIVE;
            break;
// 1 core only available on mx6sdl
#if defined(CHIP_MX6SDL)
        case ONE_CORE:
            core_count = ONE_CORE_ACTIVE;
            break;
#endif // defined(CHIP_MX6SDL)
        default:
            core_count = GET_CORES_ERROR;
    }
#elif defined(CHIP_MX6SL)
    // mx6sl only has one core
    core_count = ONE_CORE_ACTIVE;
#else
    #error Unknown cpu!
#endif

    return core_count;
}

//////////////////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////////////////
