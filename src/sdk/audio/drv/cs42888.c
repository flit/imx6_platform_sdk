/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file cs42888.c
 * @brief Driver and test for audio codec CS42888 controlled through I2C.
 *
 * @ingroup diag_audio
 */

#include "hardware.h"
#include "functions.h"
#include "../inc/audio.h"
#include "imx_i2c.h"

extern int esai_codec_power_on(void);

////////////////////////////// Macros  ///////////////////////////////////////////
#define DEBUG_ENABLE	1
#if DEBUG_ENABLE
#define TRACE(fmt, args...)	printf(fmt,##args)
#else
#define TRACE(fmt, args...)
#endif

#define CS42888_REG_WRITE(codec, addr,val)	\
	do{\
		if(0!=cs42888_reg_write(codec, addr, val)){\
			return -1;\
		}\
	}while(0)

#define CS42888_REG_read(codec, addr, val)	\
	do{\
		if(0!=cs42888_reg_read(codec, addr, &val)){\
			return -1;\
		}\
	}while(0)

////////////////////////////Local variables and functions /////////////////////////////////////////
static void cs42888_i2c_init(audio_codec_p codec)
{
    i2c_init(codec->i2c_base, codec->i2c_freq);
}

static int cs42888_reg_read(audio_codec_p codec, unsigned char reg_addr, unsigned char *ret_val)
{
    struct imx_i2c_request rq;

    rq.dev_addr = codec->i2c_dev_addr;  // the I2C DEVICE address
    rq.reg_addr_sz = 1;         // number of bytes of I2C device register's address
    rq.buffer_sz = 1;           // number of data bytes
    rq.reg_addr = reg_addr;
    rq.buffer = ret_val;

    if (i2c_xfer(codec->i2c_base, &rq, I2C_READ) != 0) {
        return -1;
    }

    return 0;
}

static int cs42888_reg_write(audio_codec_p codec, unsigned char reg_addr, unsigned char reg_data)
{
    struct imx_i2c_request rq;

    rq.dev_addr = codec->i2c_dev_addr;  // the I2C DEVICE address
    rq.reg_addr_sz = 1;         // number of bytes of I2C device register's address
    rq.buffer_sz = 1;           // number of data bytes
    rq.reg_addr = reg_addr;
    rq.buffer = &reg_data;

    return i2c_xfer(codec->i2c_base, &rq, I2C_WRITE);
}

////////////////////////////////////// APIs /////////////////////////////////////
int cs42888_init(void *priv)
{
    audio_codec_p codec = (audio_codec_p) priv;

    esai_codec_power_on();

    cs42888_i2c_init(codec);

    return 0;
}

int cs42888_config(void *priv, audio_dev_para_p para)
{
    uint32_t is_master = 0;
    audio_codec_p codec = (audio_codec_p) priv;

    CS42888_REG_WRITE(codec, 0x2, 0x01);    // Power up dac, and enter low power

    if (is_master) {
        CS42888_REG_WRITE(codec, 0x3, 0x04);    // X512 (32*2*4), master
    } else {
        CS42888_REG_WRITE(codec, 0x3, 0xF0);    // X256 (32*2*4), slave
    }
    //Interface Format
    CS42888_REG_WRITE(codec, 0x4, 0x0); // ADC Left-aligned, DAC Left-aligned
    CS42888_REG_WRITE(codec, 0x6, 0x0); // diable auto-mute

    //Volume Control: default value 0db

    // mute all DACs
    CS42888_REG_WRITE(codec, 0x7, 0xFF);
    // out of low power
    CS42888_REG_WRITE(codec, 0x2, 0x00);
    hal_delay_us(100000);
    //unmute DACs
    CS42888_REG_WRITE(codec, 0x7, 0x00);

    return 0;
}

int cs42888_deinit(void *priv)
{
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
audio_dev_ops_t cs42888_ops = {
    .init = cs42888_init,
    .deinit = cs42888_deinit,
    .config = cs42888_config,
};

audio_codec_t cs42888 = {
    .name = "cs42888",
    .i2c_base = CS42888_I2C_BASE,
    .i2c_freq = 100000,
    .i2c_dev_addr = CS42888_I2C_ID,
    .ops = &cs42888_ops,
};
