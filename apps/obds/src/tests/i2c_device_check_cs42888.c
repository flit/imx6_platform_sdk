/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "obds.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

//! @todo Implement cs42888 device check using audio driver, if possible.
//!
//! The original test attempted to read each of the device's registers, from
//! register 0x01 through 0x19.
int i2c_device_check_cs42888(void)
{
//     unsigned int i, ret;
//     unsigned char data;
// 
//     cs42888_i2c_init();
//     for (i = 1; i < 0x1A; i++) {
//         if ((ret = cs42888_reg_read(i, &data)) != 0) {
//             printf("CS42888 I2C device check failed.\n\n");
//             return ret;
//         }
//     }
// 
//     printf("CS42888 I2C device check passed. \n\n");

    return TEST_PASSED;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
