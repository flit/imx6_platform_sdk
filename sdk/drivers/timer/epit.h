/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

//! @addtogroup diag_timer
//! @{

/*!
 * @file epit.h
 * @brief EPIT driver public interface.
 */

#ifndef __EPIT_H__
#define __EPIT_H__

#include "sdk.h"
#include "timer.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Free running reload mode.
//!
//! When the counter reaches zero it rolls over to 0xFFFF_FFFF.
#define FREE_RUNNING    0

//! @brief Set and forget reload mode.
//!
//! When the counter reaches zero it reloads from the modulus register.
#define SET_AND_FORGET  1

//! @brief Pass to epit_counter_enable() to enable interrupts.
#define IRQ_MODE 1

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize the EPIT timer.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   clock_src Source clock of the counter: CLKSRC_OFF, CLKSRC_IPG_CLK,
 *                      CLKSRC_PER_CLK, CLKSRC_CKIL.
 * @param   prescaler Prescaler of source clock from 1 to 4096.
 * @param   reload_mode Counter reload mode: FREE_RUNNING or SET_AND_FORGET.
 * @param   load_val Load value from where the counter start.
 * @param   low_power_mode Low power during which the timer is enabled:
 *                           WAIT_MODE_EN and/or STOP_MODE_EN.
 */
void epit_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
               uint32_t reload_mode, uint32_t load_val, uint32_t low_power_mode);

/*!
 * @brief Setup EPIT interrupt.
 *
 * It enables or disables the related HW module interrupt, and attached the related sub-routine
 * into the vector table.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   enableIt True to enable the interrupt, false to disable.
 */
void epit_setup_interrupt(struct hw_module *port, bool enableIt);

/*!
 * @brief Enable the EPIT module. 
 *
 * Used typically when the epit_init is done, and other interrupt related settings are ready.
 *
 * In interrupt mode, when the interrupt fires you should call epit_get_compare_event() to
 * clear the compare flag.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   load_val Load value from where the counter starts.
 * @param   irq_mode Interrupt mode: IRQ_MODE or POLLING_MODE.
 */
void epit_counter_enable(struct hw_module *port, uint32_t load_val, uint32_t irq_mode);

/*!
 * @brief Disable the counter.
 *
 * It saves energy when not used.
 *
 * @param   port Pointer to the EPIT module structure.
 */
void epit_counter_disable(struct hw_module *port);

/*!
 * @brief Get the output compare status flag and clear it if set.
 * 
 * This function can typically be used for polling method, but
 * is also used to clear the status compare flag in IRQ mode.
 *
 * @param   port Pointer to the EPIT module structure.
 * @return  Value of the compare event flag.
 */
uint32_t epit_get_compare_event(struct hw_module *port);

/*!
 * @brief Set the output compare register.
 * 
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   Value of the compare register.
 */
void epit_set_compare_event(struct hw_module *port, uint32_t compare_val);

/*!
 * @brief Get the counter value.
 * 
 *
 * @param   port Pointer to the EPIT module structure.
 * @return  Value of the counter register.
 */
uint32_t epit_get_counter_value(struct hw_module *port);

/*!
 * @brief Reload the counter with a known value.
 *
 * @param port Pointer to the EPIT module structure.
 * @param load_val Value loaded into the timer counter.
 */
void epit_reload_counter(struct hw_module *port, uint32_t load_val);

#if defined(__cplusplus)
}
#endif

//! @}

#endif //__EPIT_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
