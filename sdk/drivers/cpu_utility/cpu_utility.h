/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
