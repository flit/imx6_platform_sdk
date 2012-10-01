/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __KEYPAD_PORT_H__
#define __KEYPAD_PORT_H__

//! @addtogroup diag_keypad
//! @{

/*!
 * @file keypad_port.h
 * @brief Keypad port driver header file.
 */

#include "sdk.h"

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize the keypad controller.
 *
 * @param kpp_col Mask of active columns in the keypad.
 * @param kpp_row Mask of active rows in the keypad.
 */
void kpp_open(uint8_t kpp_col, uint8_t kpp_row);

/*!
 * @brief Close the keypad driver.
 *
 * Leaves the keypad controller in a known state. Interrupts are disabled. All rows
 * are disabled.
 */
void kpp_close(void);

/*!
 * @brief Keypad port function to return the read key.
 *
 * @param[out] rd_keys Active columns in the keypad.
 * @param returnImmediately Pass true to wait for a key pressed interrupt, or false to read
 *      the keypad state immediately.
 */
void kpp_get_keypad_state(uint16_t *rd_keys, bool returnImmediately);

/*!
 * @brief Waits for all keys to release.
 *
 * The hardware can only detect this condition, and couldn't
 * detect the release of a single key but by doing it
 * by software.
 */
void kpp_wait_for_release_state(void);

#if defined(__cplusplus)
}
#endif

//! @}

#endif /* __KEYPAD_PORT_H__ */
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
