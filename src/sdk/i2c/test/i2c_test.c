/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file i2c_test.c
 * @brief Unit test for the I2C controller.
 *
 * @ingroup diag_i2c
 */

#include <stdio.h>
#include "hardware.h"

extern int32_t i2c_eeprom_at24cxx_test(void);
extern int32_t i2c_imx6_slave_test(void);

/*! 
 * I2c test.
 * This test uses the EEPROM write/read test !
 *
 * @return  none
 */
int32_t i2c_test(void)
{
    uint8_t sel;

    printf("Start I2C unit tests:");

    do {
        printf("\n  1 - to perform a test with the i.MX6 as a master accessing an EEPROM.\n");
        printf("  2 - to perform a test with the i.MX6 as a slave device.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == NONE_CHAR);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
            i2c_eeprom_at24cxx_test();
        if (sel == '2')
            i2c_imx6_slave_test();

    } while(1);

    return 0;
}