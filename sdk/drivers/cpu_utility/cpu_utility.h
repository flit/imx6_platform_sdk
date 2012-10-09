/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#if !defined(__CPU_UTILITY_H__)
#define __CPU_UTILITY_H__

//! @addtogroup cpu_utility
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Number of cores available.
enum _get_cores_results
{
    GET_CORES_ERROR = 0,             //!< Failed to determine the number of cores.
    FOUR_CORES_ACTIVE = 4,           //!< Four available CPU cores.
    TWO_CORES_ACTIVE = 2,            //!< Two available CPU cores.
    ONE_CORE_ACTIVE = 1              //!< One available CPU core.
};

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @brief Find the number of available cores.
//!
//! This function uses the chip type and OCOTP fuses to determine the number
//! of cores that are enabled on the chip. The result can then be used to
//! enable the available cores using the SRC (System Reset Controller) or
//! related API.
//!
//! @return The integer value (1,2,4) of the number of available CPU cores.
//!     There is also a #_get_cores_results enum that has constants for each
//!     of the valid return values.
//! @retval GET_CORES_ERROR Could not determine the number of cores for some
//!     reason. The caller must assume that only one core is available.
int cpu_get_cores(void);

#if defined(__cplusplus)
}
#endif

//! @}

#endif // __CPU_UTILITY_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
