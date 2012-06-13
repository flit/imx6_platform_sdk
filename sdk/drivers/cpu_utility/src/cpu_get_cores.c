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
#include "hardware.h"
#include "registers/regsocotp.h"
#include "cpu_utility/cpu_utility.h"


//////////////////////////////////////////////////////////////////////////////////////////
// Definitions
//////////////////////////////////////////////////////////////////////////////////////////

//! @name Core number available register constants 
//!{
#define CORE_NUM_MASK (0x0300000) //!< Number of cores available bit mask.
#define CORE_NUM_SHIFT (20)       //!< Number of cores available bit shift.
//@}

//! @name Number of cores constants 
//!{
#define FOUR_CORES (0)            //!< Four cores available register output.
#define TWO_CORES (2)             //!< Two cores available register output.
//@}

//////////////////////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////////////////////

int cpu_get_cores(void)
{
    // Declare variables for number of cores and temporary storage
    // for the content of the NUM_CORES register.
    int core_count;             
    uint32_t raw_data;
    
    // Mask and shift the contents of the control register so bit 21 and 20, which
    // are responsible for tracking cpu accessbility, are isolated.
    raw_data = (HW_OCOTP_CFG2_RD() & CORE_NUM_MASK) >> CORE_NUM_SHIFT;
    
    // Determine whether there are 2 or 4 cores active and set the return
    // value accordingly. If no core is active, return error.
    switch(raw_data)
    {
        case FOUR_CORES:
            core_count = FOUR_CORES_ACTIVE;
            break;
        case TWO_CORES:
            core_count = TWO_CORES_ACTIVE;
            break;
        default:
            core_count = GET_CORES_ERROR;
    }
    
    return core_count;
}


