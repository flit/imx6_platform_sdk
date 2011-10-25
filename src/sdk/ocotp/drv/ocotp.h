/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  ocotp.h
 * @brief header file with defines for the OCOTP module
 *
 */

#ifndef _OCOTP_H_
#define _OCOTP_H_

#include "io.h"

/*
 * HW_OCOTP_CTRL - OTP Controller Control Register
 */
typedef union {
    uint32_t U;
    struct {
        unsigned ADDR:7;
        unsigned RSRVD0:1;
        unsigned BUSY:1;
        unsigned ERROR:1;
        unsigned RELOAD_SHADOWS:1;
        unsigned CRC_TEST:1;
        unsigned CRC_FAIL:1;
        unsigned RSRVD1:3;
        unsigned WR_UNLOCK:16;
    } B;
} hw_ocotp_ctrl_t;

/*
 * constants & macros for entire HW_OCOTP_CTRL register
 */
#define HW_OCOTP_CTRL_ADDR      (OCOTP_BASE_ADDR + 0x0)
#define HW_OCOTP_CTRL_SET_ADDR  (OCOTP_BASE_ADDR + 0x4)
#define HW_OCOTP_CTRL_CLR_ADDR  (OCOTP_BASE_ADDR + 0x8)
#define HW_OCOTP_CTRL_TOG_ADDR  (OCOTP_BASE_ADDR + 0xc)

#define HW_OCOTP_CTRL           (*(volatile hw_ocotp_ctrl_t *) HW_OCOTP_CTRL_ADDR)
#define HW_OCOTP_CTRL_RD()      (HW_OCOTP_CTRL.U)
#define HW_OCOTP_CTRL_WR(v)     (HW_OCOTP_CTRL.U = (v))
#define HW_OCOTP_CTRL_SET(v)    ((*(volatile uint32_t *) HW_OCOTP_CTRL_SET_ADDR) = (v))
#define HW_OCOTP_CTRL_CLR(v)    ((*(volatile uint32_t *) HW_OCOTP_CTRL_CLR_ADDR) = (v))
#define HW_OCOTP_CTRL_TOG(v)    ((*(volatile uint32_t *) HW_OCOTP_CTRL_TOG_ADDR) = (v))

#define OCOTP_CTRL_WR_UNLOCK(x)     (((x) & 0xFFFF) << 16)
#define OCOTP_CTRL_CRC_FAILERROR    (1 << 12)
#define OCOTP_CTRL_CRC_TEST         (1 << 11)
#define BM_OCOTP_CTRL_RELOAD_SHADOWS   (1 << 10)
#define BM_OCOTP_CTRL_ERROR         (1 << 9)
#define BM_OCOTP_CTRL_BUSY          (1 << 8)
#define OCOTP_CTRL_ADDR(x)          ((x) & BM_OCOTP_CTRL_ADDR)
#define BM_OCOTP_CTRL_ADDR          0x7F

/*
 * HW_OCOTP_TIMING - OTP Controller Timing Register
 */
typedef union {
    uint32_t U;
    struct {
        unsigned STROBE_PROG:12;
        unsigned RELAX:4;
        unsigned STROBE_READ:6;
        unsigned WAIT:6;
        unsigned RSRVD:4;
    } B;
} hw_ocotp_timing_t;

/*
 * constants & macros for entire HW_OCOTP_TIMING register
 */
#define HW_OCOTP_TIMING_ADDR    (OCOTP_BASE_ADDR + 0x10)

#define HW_OCOTP_TIMING         (*(volatile hw_ocotp_timing_t *) HW_OCOTP_TIMING_ADDR)
#define HW_OCOTP_TIMING_RD()    (HW_OCOTP_TIMING.U)
#define HW_OCOTP_TIMING_WR(v)   (HW_OCOTP_TIMING.U = (v))
#define HW_OCOTP_TIMING_SET(v)  (HW_OCOTP_TIMING_WR(HW_OCOTP_TIMING_RD() |  (v)))
#define HW_OCOTP_TIMING_CLR(v)  (HW_OCOTP_TIMING_WR(HW_OCOTP_TIMING_RD() & ~(v)))
#define HW_OCOTP_TIMING_TOG(v)  (HW_OCOTP_TIMING_WR(HW_OCOTP_TIMING_RD() ^  (v)))

/*
 * HW_OCOTP_DATA - OTP Controller Write Data Register
 */
typedef union {
    uint32_t U;
    struct {
        unsigned DATA:32;
    } B;
} hw_ocotp_data_t;

/*
 * constants & macros for entire HW_OCOTP_DATA register
 */
#define HW_OCOTP_DATA_ADDR      (OCOTP_BASE_ADDR + 0x20)

#define HW_OCOTP_DATA           (*(volatile hw_ocotp_data_t *) HW_OCOTP_DATA_ADDR)
#define HW_OCOTP_DATA_RD()      (HW_OCOTP_DATA.U)
#define HW_OCOTP_DATA_WR(v)     (HW_OCOTP_DATA.U = (v))
#define HW_OCOTP_DATA_SET(v)    (HW_OCOTP_DATA_WR(HW_OCOTP_DATA_RD() |  (v)))
#define HW_OCOTP_DATA_CLR(v)    (HW_OCOTP_DATA_WR(HW_OCOTP_DATA_RD() & ~(v)))
#define HW_OCOTP_DATA_TOG(v)    (HW_OCOTP_DATA_WR(HW_OCOTP_DATA_RD() ^  (v)))

/*
 * HW_OCOTP_READ_CTRL - OTP Controller Read control register
 */
typedef union {
    uint32_t U;
    struct {
        unsigned READ_FUSE:1;
        unsigned RSRVD:31;
    } B;
} hw_ocotp_read_ctrl_t;

/*
 * constants & macros for HW_OCOTP_READ_CTRL register
 */
#define HW_OCOTP_READ_CTRL_ADDR     (OCOTP_BASE_ADDR + 0x30)
#define HW_OCOTP_READ_CTRL          (*(volatile hw_ocotp_read_ctrl_t *) HW_OCOTP_READ_CTRL_ADDR)
#define HW_OCOTP_READ_CTRL_RD()     (HW_OCOTP_READ_CTRL.U)
#define HW_OCOTP_READ_CTRL_WR(v)    (HW_OCOTP_READ_CTRL.U = (v))

#define OCOTP_READ_CTRL_READ_FUSE   1

/*
 * HW_OCOTP_READ_FUSE_DATA - OTP Controller Read fuse data register
 */
typedef union {
    uint32_t U;
    struct {
        unsigned READ_DATA:32;
    } B;
} hw_ocotp_read_fuse_data_t;

/*
 * constants & macros for HW_OCOTP_READ_FUSE_DATA register
 */
#define HW_OCOTP_READ_FUSE_DATA_ADDR     (OCOTP_BASE_ADDR + 0x40)
#define HW_OCOTP_READ_FUSE_DATA          (*(volatile hw_ocotp_read_fuse_data_t *) HW_OCOTP_READ_FUSE_DATA_ADDR)
#define HW_OCOTP_READ_FUSE_DATA_RD()     (HW_OCOTP_READ_FUSE_DATA.U)

//////////////////////
// Error codes
//
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

#define ERROR_BIT_SET                       (0x00000002)

#define OCOTP_WR_UNLOCK_KEY_VALUE  0x3E770000

#endif //_OCOTP_H_
