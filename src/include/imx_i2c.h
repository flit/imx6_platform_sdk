/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_I2C_H__
#define __IMX_I2C_H__

#include "io.h"

#define I2C_AR                      0x0
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
#define ERR_TX                                      -1
#define ERR_RX                                      -2
#define ERR_ARB_LOST                          -3
#define ERR_NO_ACK                             -4
#define ERR_XFER                                  -5
#define ERR_RX_ACK                              -6
#define ERR_NO_ACK_ON_START           -7

struct imx_i2c_request {
    u32 ctl_addr;               // the I2C controller base address
    u32 dev_addr;               // the I2C DEVICE address
    u32 reg_addr;               // the actual REGISTER address
    u32 reg_addr_sz;            // number of bytes for the address of I2C device register
    u8 *buffer;                 // buffer to hold the data
    u32 buffer_sz;              // the number of bytes for read/write
};

extern u32 i2c_base_addr[];
extern u32 i2c_num;

int i2c_init(u32 base, u32 baud);
int i2c_xfer(u32 base, struct imx_i2c_request *rq, int dir);
#define i2c_read(base, rq)      i2c_xfer(base, rq, I2C_READ)
#define i2c_write(base, rq)      i2c_xfer(base, rq, I2C_WRITE)

#define I2C_DEBUG
#ifdef I2C_DEBUG
#define I2CDBG(fmt,args...) printf(fmt, ## args)
#else
#define I2CDBG(fmt,args...)
#endif

#endif /* __IMX_I2C_H__ */
