/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "tempmon/tempmon.h"
#include "registers/regstempmon.h"
#include "registers/regsocotp.h"

//////////////////////////////////////////////////////////////////////////////////////////
// Definitions
//////////////////////////////////////////////////////////////////////////////////////////

//! @name Temperature calibration OTP field masks
//!{
#define ROOM_COUNT (0xfff00000) //!< Room temperature sensor count value.
#define ROOM_TEMP (22)          //!< Room temperature in degrees C.
#define HOT_COUNT (0x000fff00)  //!< Hot temperature sensor count value.
#define HOT_TEMP (0x000000ff)   //!< The hot test temperature in degrees C.
//@}

/*!
 * @brief Global data for the tempmon driver.
 */
typedef struct _tempmon_info {
    uint32_t roomCount; //!< Room temperature sensor count value.
    uint32_t hotCount;  //!< Hot temperature sensor count value.
    uint32_t hotTempC;  //!< The hot test temperature in degrees C.
} tempmon_info_t;

//////////////////////////////////////////////////////////////////////////////////////////
// Externs
//////////////////////////////////////////////////////////////////////////////////////////

// These externs for the ocotp driver need to go away when there is a public header!
extern int32_t sense_fuse(uint32_t bank, uint32_t row);
extern void fuse_blow_row(uint32_t bank, uint32_t row, uint32_t value);

//////////////////////////////////////////////////////////////////////////////////////////
// Variables
//////////////////////////////////////////////////////////////////////////////////////////

//! @brief Global data for the tempmon driver.
static tempmon_info_t s_tempmon;

//////////////////////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////////////////////

int tempmon_init(void)
{
    // Wake up the temp monitor.
    HW_TEMPMON_TEMPSENSE0_CLR(BM_TEMPMON_TEMPSENSE0_POWER_DOWN);
    
    // Read the calibration point data from OTP.
//     int32_t sense_fuse(b, r);
//     s_tempmon
    
    s_tempmon.roomCount = 0;
    s_tempmon.hotCount = 0;
    s_tempmon.hotTempC = 0;
    
    return 0;
}

int tempmon_get_temp(void)
{
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////////////////
