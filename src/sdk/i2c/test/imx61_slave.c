/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

void i2c_slave_interrupt_handler(void);

static struct imx_i2c_request mx61_i2c_req;
static uint8_t g_wait_flag;
static uint16_t g_i2c_status_reg;

/* I2C3 */
static struct hw_module i2c_slave_port = {
    "I2C3 for test",
    I2C3_BASE_ADDR,
    66000000,
    IMX_INT_I2C3,
    &i2c_slave_interrupt_handler,
};

/*! 
 * I2C slave interrupt handler.
 *
 * @return  none
 */
void i2c_slave_interrupt_handler(void)
{
    i2c_interrupt_routine(i2c_slave_port.base, &g_i2c_status_reg);
    
    g_wait_flag = 0;
}

//    mx61_i2c_req.buffer = buf;
//    mx61_i2c_req.reg_addr = addr;
//    ret = i2c_write(&mx61_i2c_req);

static uint8_t test_buffer[] = {'F', 'S', 'L', ' ', 'I', '2', 'C', ' ', 'T', 'E', 'S', 'T'};

int32_t i2c_imx61_slave_test(void)
{
    int32_t ret = 0;

    printf("  Starting i.MX61 slave test...\n");

    // Initialize the request
    mx61_i2c_req.ctl_addr = i2c_slave_port.base;
    mx61_i2c_req.dev_addr = IMX61_SLAVE_ID;
    mx61_i2c_req.reg_addr_sz = 2;
    mx61_i2c_req.buffer_sz = sizeof(test_buffer);

#ifdef BLA
    writel((SION_ENABLED & 0x1) << 4 | (ALT5 & 0x7), IOMUXC_SW_MUX_CTL_PAD_EIM_D17);
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_ENABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D24);

//    register_interrupt_routine(IMX_INT_GPIO3_INT31_16_NUM, &i2c_slave_interrupt_handler);
//   enable_interrupt(IMX_INT_GPIO3_INT31_16_NUM, CPU_0, 0);

while(1);
#endif

    ret = i2c_init(mx61_i2c_req.ctl_addr, 170000);

#ifdef MX61_EVB
    /*Set iomux and daisy chain for eeprom test */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D17, ALT6 | 0x10);
    reg32_write(IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT, 0x00);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D17, 0x1b8b0);

    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D18, ALT6 | 0x10);
    reg32_write(IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT, 0x00);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D18, 0x1b8b0);
#endif

    /* Enable the interrupts for the I2C controller */
    i2c_setup_interrupt(&i2c_slave_port, ENABLE);

    g_wait_flag = 1;
    while(g_wait_flag == 1);

    i2c_slave_handler(&mx61_i2c_req, &g_i2c_status_reg);

//    printf("i.MX61 was addressed by the external master !\n");




    /* Disable the interrupts for the I2C controller */
    i2c_setup_interrupt(&i2c_slave_port, DISABLE);

    printf("i.MX61 as I2C slave test pass.\n");
    return TEST_PASSED;
 }
