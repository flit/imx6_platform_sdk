/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file snvs.h
 * @brief  SNVS driver header file.
 */

#ifndef __SNVS_H__
#define __SNVS_H__

#include "sdk.h"

//! @addtogroup diag_snvs
//! @{

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Presently nothing to do as part of snvs initialization
 *
 * @param   port Pointer to the SNVS module structure.
 */
void snvs_init(struct hw_module *port);

/*!
 * @brief Presently nothing to do as part of snvs deinit
 *
 * @param   port Pointer to the SNVS module structure.
 */
void snvs_deinit(struct hw_module *port);

/*!
 * @brief Enable or disable non-secured real time counter
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   state True to enable the counter and false to disable it.
 */
void snvs_rtc_counter(struct hw_module *port, uint8_t state);

/*!
 * @brief Enable or disable non-secured time alarm
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   state True to enable the alarm and false to disable it.
 */
void snvs_rtc_alarm(struct hw_module *port, uint8_t state);

/*!
 * @brief Enable or disable non-secured periodic interrupt
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   freq Frequence for periodic interrupt, valid values 0 to 15,
 *          a value greater than 15 will be regarded as 15.
 * @param   state True to enable the alarm and false to disable it.
 */
void snvs_rtc_periodic_interrupt(struct hw_module *port, uint8_t freq, uint8_t state);

/*!
 * @brief Enable or disable secure real time counter
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   state 1 to enable the counter and any other value to disable it.
 */
void snvs_srtc_counter(struct hw_module *port, uint8_t state);

/*!
 * @brief Enable or disable secure time alarm
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   state 1 to enable the alarm and any other value to disable it.
 */
void snvs_srtc_alarm(struct hw_module *port, uint8_t state);

/*!
 * @brief Programs non-secured real time counter
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   count 64-bit integer to program into 47-bit RTC counter register;
 *          only 47-bit LSB will be used
 */
void snvs_rtc_set_counter(struct hw_module *port, uint64_t count);

/*!
 * @brief Sets non-secured RTC time alarm register
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   timeout 64-bit integer to program into 47-bit time alarm register;
 *          only 47-bit LSB will be used
 */
void snvs_rtc_set_alarm_timeout(struct hw_module *port, uint64_t timeout);

/*!
 * @brief Programs secure real time counter
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   count 64-bit integer to program into 47-bit SRTC counter register;
 *          only 47-bit LSB will be used
 */
void snvs_srtc_set_counter(struct hw_module *port, uint64_t count);

/*!
 * @brief Set secured RTC time alarm register
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   timeout 32-bit integer to program into 32-bit time alarm register;
 */
void snvs_srtc_set_alarm_timeout(struct hw_module *port, uint32_t timeout);

#if defined(__cplusplus)
}
#endif

//! @}

#endif //__SNVS_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
