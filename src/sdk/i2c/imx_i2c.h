/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_I2C_H__
#define __IMX_I2C_H__

#include "io.h"

#define I2C_IADR                    0x0
#define I2C_IFDR                    0x4
#define I2C_I2CR                    0x8
#define I2C_I2SR                    0xC
#define I2C_I2DR                    0x10

#define I2C_I2CR_IEN                (1 << 7)
#define I2C_I2CR_IIEN               (1 << 6)
#define I2C_I2CR_MSTA               (1 << 5)
#define I2C_I2CR_MTX                (1 << 4)
#define I2C_I2CR_TXAK               (1 << 3)
#define I2C_I2CR_RSTA               (1 << 2)

#define I2C_I2SR_ICF                (1 << 7)
#define I2C_I2SR_IAAS               (1 << 6)
#define I2C_I2SR_IBB                (1 << 5)
#define I2C_I2SR_IAL                (1 << 4)
#define I2C_I2SR_SRW                (1 << 2)
#define I2C_I2SR_IIF                (1 << 1)
#define I2C_I2SR_RXAK               (1 << 0)

// bit 0 of the i2c device address cycle to indicate r/w (0 is for write, 1 for read)
#define I2C_WRITE   0
#define I2C_READ    1

//Error Codes
#define ERR_TX                      -1
#define ERR_RX                      -2
#define ERR_ARB_LOST                -3
#define ERR_NO_ACK                  -4
#define ERR_XFER                    -5
#define ERR_RX_ACK                  -6
#define ERR_NO_ACK_ON_START         -7

#define IMX6_SLAVE_ID              0x60

struct imx_i2c_request {
    uint32_t ctl_addr;          // the I2C controller base address
    uint32_t dev_addr;          // the I2C DEVICE address
    uint32_t reg_addr;          // the actual REGISTER address
    uint32_t reg_addr_sz;       // number of bytes for the address of I2C device register
    uint8_t *buffer;            // buffer to hold the data
    uint32_t buffer_sz;         // the number of bytes for read/write
    int32_t (*slave_receive) (struct imx_i2c_request *rq);  // slave receive data from master
    int32_t (*slave_transmit) (struct imx_i2c_request *rq); // slave transmit data to master
};

extern uint32_t i2c_base_addr[];
extern uint32_t i2c_num;

int i2c_init(uint32_t base, uint32_t baud);
int i2c_xfer(struct imx_i2c_request *rq, int dir);
#define i2c_read(rq)      i2c_xfer(rq, I2C_READ)
#define i2c_write(rq)      i2c_xfer(rq, I2C_WRITE)
void i2c_setup_interrupt(struct hw_module *port, uint8_t state);
void i2c_interrupt_routine(void);
void i2c_slave_handler(struct imx_i2c_request *rq);
void i2c_slave_xfer(struct hw_module *port, struct imx_i2c_request *rq);

static const uint16_t i2c_freq_div[50][2] = {
        { 22,   0x20 }, { 24,   0x21 }, { 26,   0x22 }, { 28,   0x23 },
        { 30,   0x00 }, { 32,   0x24 }, { 36,   0x25 }, { 40,   0x26 },
        { 42,   0x03 }, { 44,   0x27 }, { 48,   0x28 }, { 52,   0x05 },
        { 56,   0x29 }, { 60,   0x06 }, { 64,   0x2A }, { 72,   0x2B },
        { 80,   0x2C }, { 88,   0x09 }, { 96,   0x2D }, { 104,  0x0A },
        { 112,  0x2E }, { 128,  0x2F }, { 144,  0x0C }, { 160,  0x30 },
        { 192,  0x31 }, { 224,  0x32 }, { 240,  0x0F }, { 256,  0x33 },
        { 288,  0x10 }, { 320,  0x34 }, { 384,  0x35 }, { 448,  0x36 },
        { 480,  0x13 }, { 512,  0x37 }, { 576,  0x14 }, { 640,  0x38 },
        { 768,  0x39 }, { 896,  0x3A }, { 960,  0x17 }, { 1024, 0x3B },
        { 1152, 0x18 }, { 1280, 0x3C }, { 1536, 0x3D }, { 1792, 0x3E },
        { 1920, 0x1B }, { 2048, 0x3F }, { 2304, 0x1C }, { 2560, 0x1D },
        { 3072, 0x1E }, { 3840, 0x1F }
};

#define I2C_DEBUG
#ifdef I2C_DEBUG
#define I2CDBG(fmt,args...) printf(fmt, ## args)
#else
#define I2CDBG(fmt,args...)
#endif

#endif /* __IMX_I2C_H__ */
