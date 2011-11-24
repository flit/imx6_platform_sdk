/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

// I2C3 is used to be a slave port
struct hw_module imx6_i2c_slave_port = {
    "I2C3 is slave port",
    I2C3_BASE_ADDR,
    66000000,
    IMX_INT_I2C3,
    &default_interrupt_routine,
};

static struct imx_i2c_request imx6_i2c_req;

//static uint8_t test_buffer[] = {'F', 'S', 'L', ' ', 'I', '2', 'C', ' ', 'T', 'E', 'S', 'T'};

// function when in slave mode to receive data from the master
int32_t imx6_slave_receive(struct imx_i2c_request *rq)
{
    int32_t ret = 0;

/* TO DO build the address depending on its size */

   rq->buffer[rq->reg_addr_sz] = 'T'; 


    return ret;
}

// function when in slave mode to transmit data to the master
int32_t imx6_slave_transmit(struct imx_i2c_request *rq)
{
    int32_t ret = 0;


/* TO DO build the address depending on its size */

   rq->buffer[rq->reg_addr_sz] = 'T'; 

    return ret;
}

int32_t i2c_imx6_slave_test(void)
{
    uint8_t sel;
    int32_t ret = 0;
    uint8_t data_buffer[16];    

    printf("  Starting i.MX61 slave test...\n");

    // Initialize the request
    imx6_i2c_req.ctl_addr = imx6_i2c_slave_port.base;   // the I2C controller base address
    imx6_i2c_req.dev_addr = IMX6_SLAVE_ID;  // the I2C DEVICE address - keep default
    imx6_i2c_req.reg_addr_sz = 2;   /* is used to configure address size of the slave */
    imx6_i2c_req.buffer_sz = 1;     /* is used to configure data size of the slave */

    imx6_i2c_req.buffer = data_buffer;
    imx6_i2c_req.slave_receive = &imx6_slave_receive;   // slave receive data from master
    imx6_i2c_req.slave_transmit = &imx6_slave_transmit; // slave transmit data to master

    ret = i2c_init(imx6_i2c_req.ctl_addr, 170000);

#ifdef MX61_EVB
    /*Set iomux and daisy chain for eeprom test */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D17, ALT6 | 0x10);
    reg32_write(IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT, 0x00);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D17, 0x1b8b0);

    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D18, ALT6 | 0x10);
    reg32_write(IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT, 0x00);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D18, 0x1b8b0);
#endif

    do {
        printf("\n    1 - to perform an access from the external master.\n");
        printf("    x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == NONE_CHAR);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
        {
            printf("    Waiting for the access from the master...\n");
            i2c_slave_xfer(&imx6_i2c_slave_port, &imx6_i2c_req);
        }

    } while(1);

    printf("i.MX6 as I2C slave test pass.\n");
    return TEST_PASSED;
 }
