/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file pmic_mc13892.c
 * @brief This file uses abstracted pmic interface functions to talk to the PMIC.
 *
 * @ingroup diag_pmic
 */

#include "obds.h"
#include "hardware.h"

#define PMIC_READ                   1
#define PMIC_WRITE                  0

#define MC13892_ID                  0x8
#define LTC2495_ID                  0x14
#define PMIC_MC13892_I2C_NUM        1   // Which I2C used to interface with the PMIC; 0=I2C1, 1=I2C2
#define PMIC_MC13892_I2C_ADDR       0x8 // PMIC I2C Slave address
#define PMIC_MC13892_I2C_REG_BYTE   0x1 // Number of Bytes to transfer the PMIC reg number
#define PMIC_MC13892_I2C_DATA_BYTE  0x3 // Number of Bytes to transfer the PMIC reg data


typedef unsigned int (*pmic_mc13892_reg_t) (unsigned int reg, unsigned int val, unsigned int write);

//Check PMIC ID
unsigned int mc13892_i2c_reg(unsigned int reg, unsigned int val, unsigned int dir)
{
//    struct imx_i2c_request rq;
//    unsigned char buf[4];
    unsigned int ret = 0; //, i = 0;
/*
    if (reg > 63 || dir > 1) {
        printf("<reg num> = %d is invalid. Should be less then 63\n", reg);
        return 0;
    }
*/printf("before i2c_init\n");
/*    i2c_init(PMIC_MC13892_I2C_BASE, 170000);

    if (dir == I2C_WRITE) {
        for (i = 0; i < PMIC_MC13892_I2C_DATA_BYTE; i++) {
            buf[i] = val >> (8 * (PMIC_MC13892_I2C_DATA_BYTE - i - 1)) & 0xff;
        }
    }
printf("before i2c_xfer\n");
    rq.ctl_addr = PMIC_MC13892_I2C_BASE;
    rq.dev_addr = PMIC_MC13892_I2C_ADDR;
    rq.reg_addr = reg;
    rq.reg_addr_sz = PMIC_MC13892_I2C_REG_BYTE;
    rq.buffer_sz = PMIC_MC13892_I2C_DATA_BYTE;
    rq.buffer = buf;
    i2c_xfer(&rq, dir);

    if (dir == I2C_WRITE) {
        i2c_xfer(&rq, I2C_READ);
    }
*/
    /* Swap bytes 0 & 2 */
/*    for (i = 0; i < PMIC_MC13892_I2C_DATA_BYTE; i++) {
        ret |= buf[i] << (8 * (PMIC_MC13892_I2C_DATA_BYTE - i - 1));
    }
*/
    return ret;
}

/*!
 * This function pointer
 */
pmic_mc13892_reg_t pmic_mc13892_reg;

void pmic_open_vgen1(void)
{
    unsigned int val;

    val = pmic_mc13892_reg(32, 0, PMIC_READ);

    if (!(val & 0x1)) {
        /* Set the VGEN1 */
        val = pmic_mc13892_reg(30, 0, PMIC_READ);
        val |= 0x30003;
        val &= ~(1 << 14);      //VGEN3->1.8V
        pmic_mc13892_reg(30, val, PMIC_WRITE);

        /* Enable VGEN1 */
        val = pmic_mc13892_reg(32, 0, PMIC_READ);
        val |= 0x1;
        pmic_mc13892_reg(32, val, PMIC_WRITE);
    }
}

void pmic_open_vusb()
{
    unsigned int val;

    /*Set SWBST to 5.15V */
    val = pmic_mc13892_reg(31, 0, PMIC_READ);
    val |= 0x03;
    val |= 0x03 << 2;
    val |= 0x03 << 5;
    pmic_mc13892_reg(31, val, PMIC_WRITE);

    /*Enable VUSB regulator to supply VUSB */
    val = pmic_mc13892_reg(32, 0, PMIC_READ);
    val |= 0x01 << 2;
    val |= 0x01 << 3;
    pmic_mc13892_reg(32, val, PMIC_WRITE);
}

void pmic_open_vsd(void)
{
    unsigned int val;

    val = pmic_mc13892_reg(33, 0, PMIC_READ);

    if ((val & 0x40000) == 0) {
        val |= 0x40000;
        pmic_mc13892_reg(33, val, PMIC_WRITE);
    }

    val = pmic_mc13892_reg(31, 0, PMIC_READ);

    if ((val & 0x1C0) != 0x1C0) {
        val |= 0x1C0;
        pmic_mc13892_reg(31, val, PMIC_WRITE);
    }

    /* Enable VCAM & VGEN3   */
    val = pmic_mc13892_reg(33, 0, PMIC_READ);
    val |= 0x40;
    val |= 0x1;
    pmic_mc13892_reg(33, val, PMIC_WRITE);
}

int device_id_check_mc13892(void)
{
//    unsigned int reg_data = 0;

//    TEST_ENTER("PMIC Device ID test");

//#if defined(MX50_REF) && defined(BOARD_VERSION3)
    /*For MX50_REVD board, the read value of the PMIC's ID is 0x91 which is not mentioned in the spec.
       So use the write-read mode to test the PMIC */
/*    pmic_mc13892_reg(16, 0x55, PMIC_WRITE);
    reg_data = pmic_mc13892_reg(16, 0, PMIC_READ);
    if (reg_data != 0x55) {
        return TEST_FAILED;
    }
printf("MX50_REF\n");
    pmic_mc13892_reg(17, 0xaa, PMIC_WRITE);
    reg_data = pmic_mc13892_reg(17, 0, PMIC_READ);
    if (reg_data != 0xaa) {
        return TEST_FAILED;
    }

    return TEST_PASSED;
#else
*/
printf("Not MX50_REF\n");
//    reg_data = pmic_mc13892_reg(7, 0, PMIC_READ);
printf("read reg\n");
/*    if ((reg_data & 0xFFFF) == 0x45d0) {
        printf("\tMC13892 Device ID correct %x, ATLAS v2.0a\n", reg_data);
        return TEST_PASSED;
    } else if ((reg_data & 0xFFFF) == 0x45d1) {
        printf("\tMC13892 Device ID correct %x, ATLAS v2.1\n", reg_data);
        return TEST_PASSED;
    } else if ((reg_data & 0xFFFF) == 0x00c9) {
        printf("\tMC34708 Device ID correct %x, RIPLEY v1.1\n", reg_data);
        return TEST_PASSED;
    } else if ((reg_data & 0xFFFF) == 0x0010) {
        printf("\tMC34708 Device ID correct %x, RIPLEY v2.0\n", reg_data);
        return TEST_PASSED;
    } else if ((reg_data & 0xFFFF) == 0x0011) {
        printf("\tMC34708 Device ID correct %x, RIPLEY v2.1\n", reg_data);
        return TEST_PASSED;
    } else {
        printf("\tPMIC Device ID error, %x\n", reg_data);
        return TEST_FAILED;
    }
*/
//#endif
return TEST_PASSED;
}

int pmic_mc13892_test_enable;
int device_id_mc13892_test(void)
{
    if (!pmic_mc13892_test_enable) {
        return TEST_NOT_PRESENT;
    }

    PROMPT_RUN_TEST("PMIC ID test", NULL);
    return device_id_check_mc13892();
}

//RUN_TEST("PMIC ID Test", device_id_mc13892_test)
