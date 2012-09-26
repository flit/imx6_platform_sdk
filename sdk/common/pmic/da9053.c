/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

#define PMIC_DA9053_I2C_ADDR        (0x90 >> 1) // PMIC I2C Slave address
#define PMIC_DA9053_I2C_REG_BYTE    0x1 // Number of Bytes to transfer the PMIC reg number
#define PMIC_DA9053_I2C_DATA_BYTE   0x1 // Number of Bytes to transfer the PMIC reg data

void I2CDBG(char * x, ...) {}

uint8_t da9053_i2c_reg(uint32_t reg, uint8_t val, uint32_t dir)
{
    struct imx_i2c_request rq;
    uint8_t buf = 0;

    if (dir == I2C_WRITE) {
        buf = val;
    }

    i2c_init(PMIC_DA9053_I2C_BASE, 170000);

    /* Initialize some of the I2C imx_i2c_request structure, these parameters shouldn't need to be changed */
    rq.ctl_addr = PMIC_DA9053_I2C_BASE;
    rq.dev_addr = PMIC_DA9053_I2C_ADDR;
    rq.reg_addr_sz = PMIC_DA9053_I2C_REG_BYTE;
    rq.buffer_sz = PMIC_DA9053_I2C_DATA_BYTE;
    rq.reg_addr = reg;
    rq.buffer = &buf;

    i2c_xfer(&rq, dir);

    if (dir == I2C_WRITE) {
        i2c_xfer(&rq, I2C_READ);
    }

    return buf;
}

void da9053_eval(void)
{
    uint8_t buf;

    /* Read BUCKCORE register */
    buf = da9053_i2c_reg(46, 0, I2C_READ);

    printf(" Initial BUCKCORE (VDDGP) register read is: 0x%x\n", buf);

    if (buf != 0x56)
        printf("  Error, BUCKCORE should be 0x56 which translates to 1.05V \n");
    else
        printf("  BUCKCORE read back correct,  translates to 1.05V \n");

    /* Read LDO6 register */
    buf = da9053_i2c_reg(55, 0, I2C_READ);

    printf(" Initial LDO6 (VDDAL1) register read is: 0x%x\n", buf);

    if (buf != 0x40)
        printf("  Error, LDO6 should be 0x40 which translates to 1.2V \n");
    else
        printf("  LDO6 read back correct,  translates to 1.2V \n");

    /* Read BUCKPRO register */
    buf = da9053_i2c_reg(47, 0, I2C_READ);

    printf(" Initial BUCKPRO (VCC) register read is: 0x%x\n", buf);

    if (buf != 0x5D)
        printf("  Error, BUCKPRO should be 0x5D which translates to 1.225V \n");
    else
        printf("  BUCKPRO read back correct,  translates to 1.225V \n");

    /* Read LDO1 register */
    buf = da9053_i2c_reg(50, 0, I2C_READ);

    printf(" Initial LDO1 (SRTC) register read is: 0x%x\n", buf);

    if (buf != 0x4C)
        printf("  Error, LDO1 should be 0x4C which translates to 1.2V \n");
    else
        printf("  LDO1 read back correct,  translates to 1.2V \n");

    /* BUCKCORE test, increase voltage */
    da9053_i2c_reg(46, 0x58, I2C_WRITE);

    /* read back BUCKCORE register */
    buf = da9053_i2c_reg(46, 0, I2C_READ);

    printf("\n BUCKCORE register read after programming is: 0x%x\n", buf);

    /* Once the BUCKCORE register has been written the next step is to assert the VB_CORE_GO bit in the
     * Supply register(R60)
     */
    da9053_i2c_reg(60, 0x61, I2C_WRITE);

    printf(" Probe VDDGP, it should read 1.10V, does it? (y/n) \n");

    if (!is_input_char('y')) {
        printf("  BUCKCORE (VDDGP) voltage increased correctly \n");
    } else {
        printf("  BUCKORE voltage not raised correctly \n");
    }

    /* Set BUCKCORE back to original value */
    da9053_i2c_reg(46, 0x56, I2C_WRITE);

    /* Once the BUCKCORE register has been written the next step is to assert the VB_CORE_GO bit in the
     * Supply register(R60)
     */
    da9053_i2c_reg(60, 0x61, I2C_WRITE);

    printf(" Now re-probe VDDGP, it should read 1.05V, does it? (y/n) \n");

    if (!is_input_char('y')) {
        printf("  BUCKCORE (VDDGP) voltage decreased correctly \n");
    } else {
        printf("  BUCKCORE voltage not decreased correctly \n");
    }

    /******/
    /* BUCKPRO test, increase voltage */
    da9053_i2c_reg(47, 0x5F, I2C_WRITE);

    /* read back BUCKPRO register */
    da9053_i2c_reg(47, 0, I2C_READ);

    printf("\n BUCKPRO register read after programming is: 0x%x\n", buf);

    /* Once the BUCKPRO register has been written the next step is to assert the VB_PRO_GO bit in the
     * Supply register(R60)
     */
    da9053_i2c_reg(60, 0x62, I2C_WRITE);

    printf(" Probe VCC, it should read 1.275V, does it? (y/n) \n");

    if (!is_input_char('y')) {
        printf("  BUCKPRO (VCC) voltage increased correctly \n");
    } else {
        printf("  BUCKPRO voltage not raised correctly \n");
    }

    /* Set BUCKPRO back to original value */
    da9053_i2c_reg(47, 0x5D, I2C_WRITE);

    /* Once the BUCKPRO register has been written the next step is to assert the VB_CORE_GO bit in the
     * Supply register(R60)
     */
    da9053_i2c_reg(60, 0x62, I2C_WRITE);

    printf(" Now re-probe VCC, it should read 1.225V, does it? (y/n) \n");

    if (!is_input_char('y')) {
        printf("  BUCKPRO (VCC) voltage decreased correctly \n");
    } else {
        printf("  BUCKPRO voltage not decreased correctly \n");
    }

    /******/
    /* LDO6 test, increase voltage */
    da9053_i2c_reg(55, 0x41, I2C_WRITE);

    /* read back LDO6 register */
    da9053_i2c_reg(55, 0, I2C_READ);

    printf("\n LD06 register read after programming is: 0x%x\n", buf);

    printf(" Probe VDDAL1, it should read 1.25V, does it? (y/n) \n");

    if (!is_input_char('y')) {
        printf("  LDO6 (VDDAL1) voltage increased correctly \n");
    } else {
        printf("  LDO6 voltage not raised correctly \n");
    }

    /* Set LDO6 back to original value */
    da9053_i2c_reg(55, 0x40, I2C_WRITE);

    printf(" Now re-probe VDDAL1, it should read 1.2V, does it? (y/n) \n");

    if (!is_input_char('y')) {
        printf("  LDO6 (VDDAL1) voltage decreased correctly \n");
    } else {
        printf("  LDO6 voltage not decreased correctly \n");
    }
}

int i2c_device_id_check_DA9053_test_enable;
int i2c_device_id_check_DA9053(void)
{
    uint8_t reg_data = 0;

    if (!i2c_device_id_check_DA9053_test_enable) {
        return TEST_NOTPRESENT;
    }

//    PROMPT_RUN_TEST("PMIC DA9053 Device ID test");

    reg_data = da9053_i2c_reg(0x78, 0, I2C_READ);

    if (reg_data == 0x1) {
        /* Write 0xC */
        da9053_i2c_reg(0x78, 0xC, I2C_WRITE);

        /* Read it back to see if we read what we wrote */
        reg_data = da9053_i2c_reg(0x78, 0, I2C_READ);

        /* Write 0x1 -- default value */
        da9053_i2c_reg(0x78, 0x1, I2C_WRITE);

        /* Make sure we read back what we wrote */
        if (reg_data == 0xC) {
            I2CDBG("\tI2C communication to PMIC DA9053 validated \n");

#ifdef DA9053_VALIDATION
            // Dialog specific evaluation test
            printf("\n\t Would you like to run the Dialog specific device test (y/n) \n");
            printf("\t Note, this is for evaluation purposes only, \n");
            printf("\t hence no pass/fail condition generated \n");

            if (is_input_char('y')) {
                printf("\t Running Dialog test \n\n");
                da9053_eval();
            }
#endif

            return TEST_PASSED;
        }
    }

    I2CDBG("\tDA9053 Device ID error, 0x%04x\n", reg_data);
    return TEST_FAILED;
}
