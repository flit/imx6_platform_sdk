/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
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

#ifndef __PWM_IFC__
#define __PWM_IFC__

#include "sdk.h"

//! @addtogroup diag_pwm
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Available PWM interrupts.
enum _pwm_interrupts
{
    kPwmFifoEmptyIrq = 1 << 0,       //!< FIFO empty interrupt.
    kPwmRolloverIrq = 1 << 1,   //!< Rollover interrupt. The counter has reached the period and reset.
    kPwmCompareIrq = 1 << 2     //!< Compare interrupt. The counter value matches the current sample value
};

//! @brief Clock sources for the PWM.
//!
//! Pass one of these values in the hw_module_t::freq member.
enum _pwm_clksrc
{
    kPwmClockSourceNone = 0,
    kPwmClockSourceIpg = 1,
    kPwmClockSourceCkih = 2,
    kPwmClockSourceCkil = 3
};

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize PWM module.
 *
 * Sets up samples and pulse width.
 * - Pulse Width = (prescale * period) / Fsrc (second)
 * - Duty Cycle = sample[idx] / period
 *
 * @param port Device instance.
 * @param prescale Frequency prescale.
 * @param period Period value.
 * @param sample Sample list.
 * @param smp_cnt Sample count.
 *
 * @retval TRUE on success
 * @retval FALSE on fail
 */
int pwm_init(struct hw_module * port,
                    uint16_t prescale,
                    uint16_t period,
                    uint16_t * sample,
                    uint32_t smp_cnt);

/*!
 * @brief Setup interrupt service routine.
 *
 * The @a mask parameter should be composed of one or more of the below:
 *    - #kPwmFifoEmptyIrq
 *    - #kPwmRolloverIrq
 *    - #kPwmCompareIrq
 *
 * @param port Device instance.
 * @param state Pass true or false to enable or disable interrupts.
 * @param mask Mask of interrupts to enable or disable.
 */
void pwm_setup_interrupt(struct hw_module * port,
                                bool state,
                                uint8_t mask);

/*!
 * @brief Clear status that will issue interrupt.
 *
 * The @a mask parameter should be composed of one or more of the below:
 *    - #kPwmFifoEmptyIrq
 *    - #kPwmRolloverIrq
 *    - #kPwmCompareIrq
 *
 * @param port Device instance.
 * @param mask Mask of status bits to clear.
 */
void pwm_clear_int_status(struct hw_module * port,
                          uint32_t mask);

/*!
 * @brief Enable PWM output.
 *
 * The PWM counter starts counting and the waveform is produced on the output
 * pin. Interrupts will be triggered upon compare and rollover.
 *
 * @param port Device instance.
 */
void pwm_enable(struct hw_module * port);

/*!
 * @brief Disable PWM ouput.
 *
 * Stops the PWM counter.
 *
 * @param port Device instance.
 */
void pwm_disable(struct hw_module * port);

#if defined(__cplusplus)
}
#endif

//! @}

#endif
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
