/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "io.h"
#include "hardware.h"
#include "imx_i2c.h"
#include "../inc/audio.h"
#include "../inc/sgtl5000.h"

//////////////////////////////MACRO definition/////////////////////////////////
#define DEBUG_ENABLE	1
#if DEBUG_ENABLE
#define TRACE(fmt, args...)	printf(fmt,##args)
#else
#define TRACE(fmt, args...)
#endif

#define SGTL5000_REG_DUMP(codec, reg_addr)	\
	do{	\
		uint16_t reg_val;	\
		if(0 == sgtl5000_read_reg(codec, reg_addr, &reg_val))	\
			printf("##reg_addr: 0x%04x\n",reg_val);	\
		else	\
			return -1;	\
	}while(0)

#define SGTL5000_REG_WRITE(codec, reg_addr, reg_val)	\
 	do{     \
		if(0 != sgtl5000_write_reg(codec, reg_addr, reg_val))   \
			return -1;	\
	}while(0)

#define SGTL5000_REG_READ(codec, reg_addr, reg_val)	\
 	do{     \
		if(0 != sgtl5000_write_reg(codec, reg_addr, &reg_val))   \
			return -1;	\
	}while(0)

////////////////////////////////Extern symbols///////////////////////////////////
extern void SGTL5000PowerUp_and_clockinit(void);

///////////////////////////////////////Local functions//////////////////////////////////////////
static int sgtl5000_i2c_init(audio_codec_p codec)
{
    return i2c_init(codec->i2c_base, codec->i2c_freq);
}

static int sgtl5000_read_reg(audio_codec_p codec, uint16_t reg_addr, uint16_t * reg_val)
{
    uint8_t data[2];
    unsigned char buf[2];
    struct imx_i2c_request rq;

    /*because the driver send reg_addr from low byte to high byte,but device need high byte firstly, so swap them */
    buf[0] = reg_addr & 0xff;
    buf[1] = (reg_addr & 0xff00) >> 8;

    rq.dev_addr = codec->i2c_dev_addr;
    rq.reg_addr = (buf[0] << 8) | buf[1];
    rq.reg_addr_sz = 2;
    rq.buffer_sz = 2;
    rq.buffer = data;

    if (!i2c_xfer(codec->i2c_base, &rq, 1))
        return -1;

    *reg_val = (data[0] << 8) | data[1];

    return 0;
}

static int sgtl5000_write_reg(audio_codec_p codec, unsigned short reg_addr, unsigned int reg_data)
{
    unsigned char data[2];
    unsigned char buf[2];
    struct imx_i2c_request rq;

    buf[0] = reg_addr & 0xff;
    buf[1] = (reg_addr & 0xff00) >> 8;

    data[1] = reg_data & 0x00ff;
    data[0] = (reg_data & 0xff00) >> 8;

    rq.dev_addr = codec->i2c_dev_addr;
    rq.reg_addr = (buf[0] << 8) | buf[1];
    rq.reg_addr_sz = 2;
    rq.buffer_sz = 2;
    rq.buffer = data;

    return i2c_xfer(codec->i2c_base, &rq, 0);
}

static int sgtl5000_dump(audio_codec_p codec)
{
    uint16_t reg_val = 0;

    printf("=============Dump %s registers=================\n");

    SGTL5000_REG_DUMP(codec, SGTL5000_CHIP_ID);
    SGTL5000_REG_DUMP(codec, SGTL5000_CHIP_DIG_POWER);
    SGTL5000_REG_DUMP(codec, SGTL5000_CHIP_CLK_CTRL);
    SGTL5000_REG_DUMP(codec, SGTL5000_CHIP_I2S_CTRL);
    SGTL5000_REG_DUMP(codec, SGTL5000_CHIP_ADCDAC_CTRL);

    return 0;
}

static int sgtl5000_digital_mute(audio_codec_p codec, int mute)
{
    uint16_t adcdac_ctrl;

    if (0 != sgtl5000_read_reg(codec, SGTL5000_CHIP_ADCDAC_CTRL, adcdac_ctrl))
        return -1;

    if (mute) {
        adcdac_ctrl |= SGTL5000_DAC_MUTE_LEFT;
        adcdac_ctrl |= SGTL5000_DAC_MUTE_RIGHT;
    } else {
        adcdac_ctrl &= ~SGTL5000_DAC_MUTE_LEFT;
        adcdac_ctrl &= ~SGTL5000_DAC_MUTE_RIGHT;
    }

    sgtl5000_write_reg(codec, SGTL5000_CHIP_ADCDAC_CTRL, adcdac_ctrl);

    return 0;
}

static int sgtl5000_DAP_init(audio_codec_p codec)
{
    uint16_t v;

    /*Set I2S-IN->DAP->DAC->HP route */
    v = (0x1 << 8)              // I2S_IN -> DAP mixer
        | (0x1 << 6)            //DAP data source as I2S_IN
        | (0x3 << 4)            //DAC data source as DAP
        ;
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_SSS_CTRL, v);

    /* enable DAP */
    v = (1 << 4)                // enable dap mixer
        | (1 << 0);             //enable dap
    SGTL5000_REG_WRITE(codec, SGTL5000_DAP_CTRL, v);

    /* Power Up DAP */
    SGTL5000_REG_READ(codec, SGTL5000_CHIP_DIG_POWER, v);
    v |= (1 << 4);
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_DIG_POWER, v);

    return 0;
}

/////////////////////////////////////////API fucntons///////////////////////////////////////////////
/*!
 * Initialize the sgtl5000
 *
 */
int sgtl5000_init(audio_codec_p codec)
{
    TRACE("%s called.\n", __FUNCTION__);

    SGTL5000PowerUp_and_clockinit();

    //-------------------Power Configuration-----------------------
    SGTL5000_REG_DUMP(codec, SGTL5000_CHIP_ID);
    // Set VAG_VAL(bits 8:4)(Analog ground level) level to to VDDA/2
    // reference bias current for all the analog blocks
    // set to -50% from the nominal value
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_REF_CTRL, 0x1FF);
    // Enable the internal oscillator for the charge pump (Set bit 11)
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_CLK_TOP_CTRL, 0x0800);
    // Turn down the charge pump supply (clear bit 11)
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_ANA_POWER, 0x4260);
    // Set LINEOUT VAG voltage to VDDIO/2 (1.375V) and bias current
    // the recommended value of 0.36mA for 10kOhm load with 1nF
    // capacitance
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_LINE_OUT_CTRL, 0x0322);
    // Power up the VAG reference buffer. Also power off the startup
    // and simple linreg needed for power up.  These are not needed as
    // internal VDDD is already enabled above.
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_ANA_POWER, 0x0AA0);
    // delay for stablity after power up 
    hal_delay_us(100000);

    //------------------Startup volume configuration-----------------
    // Set LINEOUT volume based on VAG and LINEOUT_VAG values
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_LINE_OUT_VOL, CHIP_LINE_OUT_VOL_REG_VALUE);
    // Ramp down the HP volume to the lowest level -51.5dB
    //SGTL5000RampHPVolume(HP_LOWEST_VOL);

    //----------------Other Analog Block Configuration---------------
    // Configure slow ramp up rate to minimize pop (bit 0)
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_REF_CTRL, CHIP_REF_CTRL_REG_VALUE);
    // Enable short detect mode for headphone left/right
    // and center channel and set short detect current trip level
    // to 75mA
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_SHORT_CTRL, 0x1106);
    // Enable Zero-cross detect for HP_OUT (bit 5) and ADC (bit 1)
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_ANA_CTRL, 0x0133);

    return 0;
}

int sgtl5000_deinit(audio_codec_p codec)
{
    TRACE("%s called.\n", __FUNCTION__);

    sgtl5000_write_reg(codec, SGTL5000_CHIP_DIG_POWER, 0x0000); /* Power off ADC, DAC, I2S in, I2S out */
    sgtl5000_write_reg(codec, SGTL5000_CHIP_ADCDAC_CTRL, 0x000C);   /* Mute DAC */
    sgtl5000_write_reg(codec, SGTL5000_CHIP_ANA_CTRL, 0x0091);  /* Mute all outputs, Line in to ADC */

    return 0;
}

/*!
 * Config sgtl5000 according the parameter by audio_card driver.
 *
 */
int sgtl5000_config(audio_codec_p codec, void *para)
{
    uint16_t v = 0;

    TRACE("%s called.\n", __FUNCTION__);

    v = (0x0 << 8)              //64Fs
        | (0x1 << 7)            //master of I2S
        | (0x0 << 6)            //data is valid in rising edge of SCLK
        | (0x0 << 2)            //I2S mode
        | (0x0 << 1)            //I2S_LRCLK is not aligned to data
        | (0x0 << 0)            //defaule LRCLK polarity
        ;
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_I2S_CTRL, v);

    sgtl5000_DAP_init(codec);

    v = 0x00;
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_ANA_CTRL, v);
    /*Power up HP,ADC,DAC,Lineout */
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_ANA_POWER, 0x4ff9); // ADC is off
    /*Power up desired digital blocks: DAC, I2S_IN */
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_DIG_POWER, v);
    v |= (1 << 0) | (1 << 5);
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_DIG_POWER, v);

    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_ANA_HP_CTRL, 0x1818);

    /*Umute DAC */
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_ADCDAC_CTRL, 0x0230);
    /* default configuration for word length, 16 bits */
    SGTL5000_REG_READ(codec, SGTL5000_CHIP_I2S_CTRL, v);
    v &= ~(0x3 << 4);
    v |= (0x3 << 4);
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_I2S_CTRL, v);

    /*Set sample rate as 48kHz */
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_CLK_TOP_CTRL, CHIP_CLK_TOP_CTRL_REG_VALUE);
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_PLL_CTRL, CHIP_PLL_CTRL_REG_VALUE);
    SGTL5000_REG_WRITE(codec, SGTL5000_CHIP_CLK_CTRL, CHIP_CLK_CTRL_REG_VALUE);

    return 0;
}

int sgtl5000_ioctl(audio_codec_p codec, uint32_t cmd, void *para)
{
    TRACE("%s called.\n", __FUNCTION__);
    //TODO

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
audio_dev_ops_t sgtl5000_ops = {
	.init = sgtl5000_init,
	.deinit = sgtl5000_deinit,
	.config = sgtl5000_config,
	.ioctl = sgtl5000_ioctl,
};

audio_codec_t sgtl5000 = {
	.name = "sgtl5000",
	.i2c_base = I2C2_BASE_ADDR,
	.i2c_freq = 100000,
	.i2c_dev_addr = SGTL5000_I2C_ID,
	.bus = INTERFACE_TYPE_SSI,
	.ops = &sgtl5000_ops,
};
