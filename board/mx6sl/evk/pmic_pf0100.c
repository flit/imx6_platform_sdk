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

#include "sdk.h"

#define PMIC_PF0100_I2C_BASE       I2C1_BASE_ADDR 

#define PMIC_PF0100_I2C_NUM        1    // Which I2C used to interface with the PMIC; 0=I2C1, 1=I2C2
#define PMIC_PF0100_I2C_REG_BYTE   0x1  // Number of Bytes to transfer the PMIC reg number
#define PMIC_PF0100_I2C_DATA_BYTE  0x1  // Number of Bytes to transfer the PMIC reg data

#define PMIC_PF0100_I2C_ID         (0x10 >> 1)  //0x08

unsigned char pf0100_reg_read(unsigned char reg_addr)
{
    struct imx_i2c_request rq = {0};
    unsigned char buf;

    rq.ctl_addr = PMIC_PF0100_I2C_BASE;
    rq.dev_addr = PMIC_PF0100_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = &buf;

    i2c_xfer(&rq, I2C_READ);

    return buf;
}

void pf0100_reg_write(unsigned char reg_addr, unsigned char reg_data)
{
    struct imx_i2c_request rq = {0};

    rq.ctl_addr = PMIC_PF0100_I2C_BASE;
    rq.dev_addr = PMIC_PF0100_I2C_ID;
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 1;
    rq.buffer = &reg_data;

    i2c_xfer(&rq, I2C_WRITE);
}

void pf0100_enable_vgen2_1v5(void)
{
    unsigned char data;

    i2c_init(PMIC_PF0100_I2C_BASE, 170000);
    data = pf0100_reg_read(109);
    pf0100_reg_write(109, 0x1E);
}

void pf0100_enable_vgen4_1v8(void)
{
    unsigned char data;

    i2c_init(PMIC_PF0100_I2C_BASE, 170000);
    data = pf0100_reg_read(111);
    pf0100_reg_write(111, 0x10);
}

void pf0100_enable_vgen6_2v8(void)
{
    unsigned char data;

    i2c_init(PMIC_PF0100_I2C_BASE, 170000);
    data = pf0100_reg_read(113);
    pf0100_reg_write(113, 0x1A);
}
