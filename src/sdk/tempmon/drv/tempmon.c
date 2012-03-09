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
#define BM_ROOM_COUNT (0xfff00000)  //!< Room temperature sensor count bit mask.
#define BP_ROOM_COUNT (20)          //!< Room temperature sensor count bit position.
#define BM_HOT_COUNT (0x000fff00)   //!< Hot temperature sensor count bit mask.
#define BP_HOT_COUNT (8)            //!< Hot temperature sensor count bit position.
#define BM_HOT_TEMP (0x000000ff)    //!< Hot test temperature in degrees C bit mask.
#define BP_HOT_TEMP (0)             //!< Hot test temperature in degrees C bit position.
//@}

//!< Room temperature in degrees C.
#define ROOM_TEMP (25)

//! @brief Temperature calibration OTP register info
enum _temp_cal_otp_reg {
    kTempCalibrationOtpBank = 1,    //!< Bank 1
    kTempCalibrationOtpRow = 6      //!< Row/word 6
};

//! @brief Default temperature calibration points.
#define DEFAULT_TEMP_CAL_DATA (0x57d4df7d)

/*!
 * @brief Global data for the tempmon driver.
 */
typedef struct _tempmon_info {
    uint32_t roomCount; //!< Room temperature sensor count value.
    uint32_t hotCount;  //!< Hot temperature sensor count value.
    uint32_t hotTemp;  //!< The hot test temperature in degrees C.
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
    
    // Clear the measure frequency so we only get single measurements.
    HW_TEMPMON_TEMPSENSE1_WR(BF_TEMPMON_TEMPSENSE1_MEASURE_FREQ(0));
    
    // Read the calibration point data from OTP.
    uint32_t calibrationData = sense_fuse(kTempCalibrationOtpBank, kTempCalibrationOtpRow);
    
    // If the OTP fields are blank, use a default set of calibration points.
    if (calibrationData == 0)
    {
        calibrationData = DEFAULT_TEMP_CAL_DATA;
    }
    
    // Extract calibration points from the OTP data.
    s_tempmon.roomCount = (calibrationData & BM_ROOM_COUNT) >> BP_ROOM_COUNT;
    s_tempmon.hotCount = (calibrationData & BM_HOT_COUNT) >> BP_HOT_COUNT;
    s_tempmon.hotTemp = (calibrationData & BM_HOT_TEMP) >> BP_HOT_TEMP;
    
    return 0;
}

inline int compute_temp(int measuredCount, int roomCount, int hotCount, int hotTemp)
{
    return hotTemp - (measuredCount - hotCount) * ((hotTemp - ROOM_TEMP) / (roomCount - hotCount));
}

int tempmon_get_temp(void)
{
    // Start a measurement cycle.
    BF_SETV(TEMPMON_TEMPSENSE0, MEASURE_TEMP, BV_TEMPMON_TEMPSENSE0_MEASURE_TEMP__START);
    
    // Wait until the measurement is ready.
    while (HW_TEMPMON_TEMPSENSE0.B.FINISHED);
    
    // Read the measured temperature.
    int measuredCount = HW_TEMPMON_TEMPSENSE0.B.TEMP_VALUE;
    
    // Return the computed temperature.
    return compute_temp(measuredCount, s_tempmon.roomCount, s_tempmon.hotCount, s_tempmon.hotTemp);
}

//////////////////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////////////////
