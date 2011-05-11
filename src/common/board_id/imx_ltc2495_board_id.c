/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "imx_i2c.h"
#include "hardware.h"

#define LTC2495_ID                0x14

#define CPU_ID0     12
#define CPU_ID1     13

/* Board ID list */

#define IMX53_EVK_RA_CPU_ID               0x1512
#define IMX53_EVK_RC_CPU_ID               0x1513
#define IMX53_EVK_RB_CPU_ID               0x150F

//-----------------------------------------------------------------------------
//
//  Function: adc2id_level
//
//  Translate ADC conversion value to ID level.
//
//  Parameters:
//      value: ADC conversion value.
//
//  Returns:
//      Returns the translated board ID level.
//
//-----------------------------------------------------------------------------
static unsigned char adc2id_level(unsigned int value)
{
    unsigned char level;

    if (value < 0x3FFFC0) {
        level = 0;
    } else if (value < 0x461863) {
        level = 1;
    } else if (value < 0x4C30C4) {
        level = 2;
    } else if (value < 0x524926) {
        level = 3;
    } else if (value < 0x586187) {
        level = 4;
    } else if (value < 0x5E79E9) {
        level = 5;
    } else if (value < 0x64924A) {
        level = 6;
    } else if (value < 0x6AAAAC) {
        level = 7;
    } else if (value < 0x70C30D) {
        level = 8;
    } else if (value < 0x70C30D) {
        level = 9;
    } else if (value < 0x7CF3D0) {
        level = 10;
    } else if (value < 0x830C32) {
        level = 11;
    } else if (value < 0x892493) {
        level = 12;
    } else if (value < 0x8F3CF5) {
        level = 13;
    } else if (value < 0x955556) {
        level = 14;
    } else if (value < 0x9B6DB8) {
        level = 15;
    } else if (value < 0xA18619) {
        level = 16;
    } else if (value < 0xA79E7B) {
        level = 17;
    } else if (value < 0xADB6DC) {
        level = 18;
    } else if (value < 0xB3CF3E) {
        level = 19;
    } else if (value < 0xB9E79F) {
        level = 20;
    } else {
        level = 21;
    }

    return level;
}

//-----------------------------------------------------------------------------
//
//  Function: read_adc_channel
//
//  Read a single ADC channel.
//
//  Parameters:
//      channel: ADC channel to read.
//      pdata   : points to buffer for channel data.
//
//  Returns:
//      Returns 0 if successful, otherwise returns -1.
//
//-----------------------------------------------------------------------------
static int read_adc_channel(unsigned int channel, unsigned int *pdata)
{
    struct imx_i2c_request rq;
    int rc = -1;
    unsigned char byteOutData;
    unsigned char byteInData[3];

    //Write Data:   | 1 | 0 | En |SGL|Odd| A2| A1| A0|
    //              | 1 | 0 | 1  | 1 | x | x | x | x |
    byteOutData = 0xB0 | ((channel & 0x1) << 3) | ((channel >> 1) & 0x7);

    rq.dev_addr = LTC2495_ID;
    rq.reg_addr = 0x0;
    rq.reg_addr_sz = 0;
    rq.buffer_sz = 1;
    rq.buffer = &byteOutData;

    do {
        rc = i2c_xfer(BOARD_ID_I2C_BASE, &rq, I2C_WRITE);
    }
    while (rc == ERR_NO_ACK_ON_START);

    if (rc != 0)
        goto cleanUp;

    // Start a new read cycle
    rq.buffer_sz = 3;
    rq.buffer = byteInData;

    // Send command to read conversion
    do {
        rc = i2c_xfer(BOARD_ID_I2C_BASE, &rq, I2C_READ);
    }
    while (rc == ERR_NO_ACK_ON_START);

    if (rc != 0)
        goto cleanUp;

    *pdata = (byteInData[0] << 16) + (byteInData[1] << 8) + byteInData[2];

    rc = 0;

  cleanUp:
    return rc;
}

//-----------------------------------------------------------------------------
//
// Function: board_id_read
//
// This function reads board ID from LTC2495.
//
// Parameters:
//      pData: pointer to result.
//
// Returns:
//      Returns 0 if successful, otherwise returns -1.
//
//-----------------------------------------------------------------------------
int board_id_read(unsigned int *pData)
{
    int rc = -1;
    unsigned int adcData;
    unsigned char cpuId0, cpuId1;

    if (i2c_init(BOARD_ID_I2C_BASE, 50000) != 0) {
        printf("Failed to initialize Board ID I2C\n");
    }
    // Read CPU ID0 from LTC2495
    if (read_adc_channel(CPU_ID0, &adcData) != 0)
        goto cleanUp;

    printf1("CPU ID 0 = %x\n", adcData);

    // Convert ADC value from LTC2495 into a board ID
    cpuId0 = adc2id_level(adcData);

    // Read CPU ID1 from LTC2495
    if (read_adc_channel(CPU_ID1, &adcData) != 0)
        goto cleanUp;

    printf1("CPU ID 1 = %x\n", adcData);

    // Convert ADC value from LTC2495 into a board ID
    cpuId1 = adc2id_level(adcData);

    // Create combined board ID
    *pData = (cpuId0 << 8) | cpuId1;

    printf(" Board ID is: 0x%x\n", *pData);

    if ((*pData >= 0x150F) && (*pData <= 0x1513)) {
        if (*pData == IMX53_EVK_RA_CPU_ID)
            printf(" MX53 EVK Rev A \n");
        else if (*pData == IMX53_EVK_RB_CPU_ID)
            printf(" MX53 EVK Rev B \n");
        else if (*pData == IMX53_EVK_RC_CPU_ID)
            printf(" MX53 EVK Rev C \n");
        else
            printf(" Board ID is not in the list of known IDs \n");

        rc = 0;
    } else {
        printf(" Board ID is NOT valid. \n");
        rc = 1;
    }

  cleanUp:
    return rc;
}
