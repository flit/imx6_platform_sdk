/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef _OCOTP_DRV_H_
#define _OCOTP_DRV_H_

/*!
 * @file  ocotp.h
 * @brief Header file with API for the OCOTP driver.
 * @ingroup diag_ocotp
 */

#include "sdk.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

#define SUCCESS 0

#define PITC_ERROR_OTP_RW (-1)

#define ERROR_OTP_PROGRAM_HCLK                  (PITC_ERROR_OTP_RW)
//! Could not set VDDIO voltage
#define ERROR_OTP_SET_VOLTAGE                   (PITC_ERROR_OTP_RW-1)
//! OTP Controller is busy
#define ERROR_OTP_CTRL_BUSY                     (PITC_ERROR_OTP_RW-2)
//! OTP Controller is reporting error
#define ERROR_OTP_CTRL_ERROR                    (PITC_ERROR_OTP_RW-3)
//! OTP Controller has timeout on write
#define ERROR_OTP_CTRL_TIMEOUT                  (PITC_ERROR_OTP_RW-4)
//! OTP Controller returns read open
#define ERROR_OTP_RD_BANK_OPEN                  (PITC_ERROR_OTP_RW-5)
//! invalid OTP register
#define ERROR_OTP_INVALID_REGISTER              (PITC_ERROR_OTP_RW-6)

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * Read the value of fuses located at bank/row.
 *
 * @param  bank Bank of the fuse.
 * @param  row Row or word of the fuse.
 * @return The value of the fuses at the given bank and row.
 */
int32_t ocotp_sense_fuse(uint32_t bank, uint32_t row);

/*!
 * Program fuses located at bank/row to value.
 *
 * @param  bank Bank of the fuses.
 * @param  row Row or word of the fuses.
 * @param  value Value to program in fuses.
 */
void ocotp_fuse_blow_row(uint32_t bank, uint32_t row, uint32_t value);

#if defined(__cplusplus)
extern "C" {
#endif

#endif //_OCOTP_DRV_H_
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
