/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "obds.h"

#define REG_CTRL_REG1		0x2A
#define REG_XYZ_DATA_CFG	0x0E

int mma8451_show_accel(unsigned int i2c_base_addr);

static unsigned char mma8451_reg_read(unsigned int i2c_base_addr, unsigned char reg_addr)
{
    struct imx_i2c_request rq = {0};
    unsigned char buf[1];
    unsigned char reg_data = 0;

    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = MMA8451_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;
    i2c_xfer(&rq, I2C_READ);
//    i2c_xfer(i2c_base_addr, &rq, I2C_READ);
    reg_data = buf[0];

    return reg_data;
}

static int mma8451_reg_write(unsigned int i2c_base_addr, unsigned char reg_addr,
                             unsigned char reg_val)
{
    struct imx_i2c_request rq = {0};
    unsigned char buf[1];

    buf[0] = reg_val;
    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = MMA8451_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = buf;

    return i2c_xfer(&rq, I2C_WRITE); 
//    return i2c_xfer(i2c_base_addr, &rq, I2C_WRITE);
}

int i2c_device_id_check_MMA8451(unsigned int i2c_base_addr)
{
    unsigned int reg_data = 0;
    printf("Test MMA8451 Device ID - ");
    i2c_init(i2c_base_addr, 170000);
    reg_data = mma8451_reg_read(i2c_base_addr, 0x0D);   //read  WHO_AM_I reg

    if (0x1A == reg_data) {
        printf("passed 0x%02X\n\n", reg_data);
        mma8451_show_accel(i2c_base_addr);
        return 0;
    } else {
        printf("failed, 0x1A vs 0x%02X\n\n", reg_data);
        return 1;
    }
}

int mma8451_set_config(unsigned int i2c_base_addr)
{
    unsigned char val = 0;

    /*Put the mma8451 into standby mode */
    val = mma8451_reg_read(i2c_base_addr, REG_CTRL_REG1);
    val &= ~(0x01);
    mma8451_reg_write(i2c_base_addr, REG_CTRL_REG1, val);

    /*Set the range, -8g to 8g */
    val = mma8451_reg_read(i2c_base_addr, REG_XYZ_DATA_CFG);
    val &= ~0x03;
    val |= 0x02;
    mma8451_reg_write(i2c_base_addr, REG_XYZ_DATA_CFG, val);

    /*Set the F_MODE, disable FIFO */
    val = mma8451_reg_read(i2c_base_addr, 0x09);
    val &= 0x3F;
    mma8451_reg_write(i2c_base_addr, 0x09, val);

    /*Put the mma8451 into active mode */
    val = mma8451_reg_read(i2c_base_addr, REG_CTRL_REG1);
    val |= 0x01;
    val &= ~0x02;               //set F_READ to 0
    mma8451_reg_write(i2c_base_addr, REG_CTRL_REG1, val);
    return 0;
}

typedef struct {
    short accel_x;
    short accel_y;
    short accel_z;
} Accel, *pAccel;

int mma8451_get_accel(unsigned int i2c_base_addr, Accel * acc)
{
    unsigned char ucVal1 = 0, ucVal2 = 0;
    unsigned char ucStatus = 0;
    unsigned short iTemp = 0;
    int sign = 1;
    char signch = '+';
    do {
        ucStatus = mma8451_reg_read(i2c_base_addr, 0x00);
    } while (!(ucStatus & 0x08));

    ucVal1 = mma8451_reg_read(i2c_base_addr, 0x01);
    ucVal2 = mma8451_reg_read(i2c_base_addr, 0x02);
    sign = (ucVal1 & 0x80) ? (-1) : 1;
    iTemp = ((ucVal1 & 0x7F) << 6) + ((ucVal2) >> 2);
    if (sign == -1)             //2's completement
        iTemp = (~iTemp + 1) & 0x1FFF;
    signch = (sign == -1) ? '-' : '+';
    acc->accel_x = iTemp * sign;
    printf("\r 	  The acceleration is: (%c%01d.%02dg, ",
           signch, iTemp * 8 / 0x2000, (iTemp & 0x3FF) * 800 / 0x2000);

    ucVal1 = mma8451_reg_read(i2c_base_addr, 0x03);
    ucVal2 = mma8451_reg_read(i2c_base_addr, 0x04);
    sign = (ucVal1 & 0x80) ? (-1) : 1;
    iTemp = ((ucVal1 & 0x7F) << 6) + ((ucVal2) >> 2);
    if (sign == -1)             //2's completement
        iTemp = (~iTemp + 1) & 0x1FFF;
    signch = (sign == -1) ? '-' : '+';
    acc->accel_y = iTemp * sign;
    printf(" %c%01d.%02dg, ", signch, iTemp * 8 / 0x2000, (iTemp & 0x3FF) * 800 / 0x2000);

    ucVal1 = mma8451_reg_read(i2c_base_addr, 0x05);
    ucVal2 = mma8451_reg_read(i2c_base_addr, 0x06);
    sign = (ucVal1 & 0x80) ? (-1) : 1;
    iTemp = ((ucVal1 & 0x7F) << 6) + ((ucVal2) >> 2);
    if (sign == -1)             //2's completement
        iTemp = (~iTemp + 1) & 0x1FFF;
    signch = (sign == -1) ? '-' : '+';
    acc->accel_z = iTemp * sign;
    printf(" %c%01d.%02dg)", signch, iTemp * 8 / 0x2000, (iTemp & 0x3FF) * 800 / 0x2000);

    return 0;
}

int mma8451_show_accel(unsigned int i2c_base_addr)
{
    unsigned char uc = NONE_CHAR;
    Accel acc;

    printf("    Do you want to check the accelerometer?(y/n)\n\n");

    do {
       uc = getchar();
//        uc = receive_char();
    } while (uc == NONE_CHAR);

    if (uc == 'y' || uc == 'Y') {
        mma8451_set_config(i2c_base_addr);

        printf("    Start show acceleration. Type 'x' to exit.\n\n");
        while (1) {
            mma8451_get_accel(i2c_base_addr, &acc);
            uc = getchar();
//            uc = receive_char();
            if (uc == 'x' || uc == 'X') {
                printf("\n\n");
                break;
            }
        }
    } else {
        return 1;
    }
    return 0;
}
