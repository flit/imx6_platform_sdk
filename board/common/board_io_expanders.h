/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__BOARD_IO_EXPANDERS_H__)
#define __BOARD_IO_EXPANDERS_H__

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

/* 
 * BOARD_SMART_DEVICE/BOARD_SABRE_LITE for compile error
 */
#if defined(BOARD_SMART_DEVICE) || defined(BOARD_SABRE_LITE)
#define MAX7310_NBR 0
#endif

/* For the ARD board which has 3 MAX7310 */
#ifdef BOARD_SABRE_AI
#define MAX7310_NBR 3

/* I/O expander A */
#define MAX7310_I2C_BASE_ID0     3
#define MAX7310_I2C_ID0          0x30
#define MAX7310_ID0_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID0_DEF_VAL      0xFF   // init value for the output

/* I/O expander B */
#define MAX7310_I2C_BASE_ID1     3
#define MAX7310_I2C_ID1          0x32
#define MAX7310_ID1_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID1_DEF_VAL      0xE7   // init value for the output

/* I/O expander C */
#define MAX7310_I2C_BASE_ID2     3
#define MAX7310_I2C_ID2          0x34
#define MAX7310_ID2_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID2_DEF_VAL      0x57   // init value for the output
#endif

#ifdef BOARD_EVB
/* For the EVB board which has 2 MAX7310 */
#define MAX7310_NBR 2

/* Number 1 controls: BACKLIGHT_ON, PORT3_P114, CPU_PER_RST_B, PORT3_P110,
   PORT3_P105, PORT3_P112, PORT3_P107, PORT3_P109.
*/
#define MAX7310_I2C_BASE_ID0     3
#define MAX7310_I2C_ID0          (0x36 >> 1)
#define MAX7310_ID0_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID0_DEF_VAL      0xFF   // init value for the output

/* Number 2 controls: CTRL_0, CTRL_1, CTRL_2, CTRL_3, CTRL_4, PORT3_P116,
   PORT2_P81, PORT3_P101
*/
#define MAX7310_I2C_BASE_ID1     3
#define MAX7310_I2C_ID1          (0x3E >> 1)
#define MAX7310_ID1_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID1_DEF_VAL      0x09   // init value for the output
#endif

////////////////////////////////////////////////////////////////////////////////
// Globals
////////////////////////////////////////////////////////////////////////////////

//! @brief Array of I2C requests for all used expanders on the board.
//!
//! This array is primarily used to pass details about I2C addresses and ports
//! to the max7310 driver.
extern imx_i2c_request_t max7310_i2c_req_array[];

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif


/*!
 * @brief Init the array of I/O expanders.
 */
void board_ioexpander_init(void);


#if defined(__cplusplus)
}
#endif


#endif // __BOARD_IO_EXPANDERS_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
