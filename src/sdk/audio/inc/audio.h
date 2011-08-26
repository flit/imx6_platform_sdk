/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __AUDIO_H
#define __AUDIO_H

typedef enum {
    AUDIO_BUS_TYPE_SSI,
    AUDIO_BUS_TYPE_ESAI,
    AUDIO_BUS_TYPE_SPDIF,
} audio_bus_type_e;

typedef enum {
    AUDIO_BUS_MODE_SLAVE = 0,
    AUDIO_BUS_MODE_MASTER = 1,
    AUDIO_BUS_MODE_EITHER = 2,    //the audio controller or codec can be configured as Master or Slave
} audio_bus_mode_e;

typedef enum {
    AUDIO_BUS_PROTOCOL_NORMAL,
    AUDIO_BUS_PROTOCOL_NETWORK,
    AUDIO_BUS_PROTOCOL_I2S,
    AUDIO_BUS_PROTOCOL_LEFT_ALIGNED,
    AUDIO_BUS_PROTOCOL_AC97,
} audio_bus_protocol_e;

typedef enum {
    AUDIO_TRANS_DIR_TX = 0,
    AUDIO_TRANS_DIR_RX = 1,
    AUDIO_TRANS_DIR_TXRX = 2,
} audio_trans_dir_e;

typedef enum {
    SAMPLERATE_8KHz = 8000,
    SAMPLERATE_32KHz = 32000,
    SAMPLERATE_44_1KHz = 44100,
    SAMPLERATE_48KHz = 48000,
} audio_samplerate_e;

typedef enum {
	WL_8 = 8,
	WL_16 = 16,
	WL_20 = 20,
	WL_24 = 24,
	WL_32 = 32,
}audio_word_length_e;

typedef struct {
    audio_samplerate_e sample_rate;
    unsigned int channel_number;
    audio_word_length_e word_length;
} audio_pcm_para_t, *audio_pcm_para_p;


typedef struct {
    const char *name;
    audio_pcm_para_p para;
    uint8_t *buf;
    uint32_t size;
} audio_pcm_t, *audio_pcm_p;

typedef struct {
    audio_bus_mode_e bus_mode;
    audio_bus_protocol_e bus_protocol;
    audio_trans_dir_e trans_dir;
    audio_samplerate_e sample_rate;
    audio_word_length_e word_length;
    unsigned int channel_number;
} audio_dev_para_t, *audio_dev_para_p;

typedef struct {
    int (*init) (void *priv);
    int (*deinit) (void *priv);
    int (*config) (void *priv, audio_dev_para_p para);
    int (*ioctl) (void *priv, uint32_t cmd, void *para);
    int (*write) (void *priv, uint8_t * buf, uint32_t byte2write, uint32_t *bytewrittern);
    int (*read) (void *priv, uint8_t * buf, uint32_t byte2read, uint32_t byteread);
} audio_dev_ops_t, *audio_dev_ops_p;

typedef struct {
    const char *name;
    uint32_t i2c_base;          //the i2c connect with the codec
    uint32_t i2c_freq;          // i2c operate freq;
    uint32_t i2c_dev_addr;      //Device address for I2C bus
    audio_bus_type_e bus_type;  //The bus type(ssi, esai or spdif) the codec supports
    audio_bus_mode_e bus_mode;  //the bus mode(master, slave or both)the codec supports
    void *priv_info;            //point to the private info of the audio controller 
    audio_dev_ops_p ops;
} audio_codec_t, *audio_codec_p;

typedef struct {
    const char *name;
    uint32_t base_addr;         // the io base address of the controller
    audio_bus_type_e bus_type;  //The bus type(ssi, esai or spdif) the controller supports
    audio_bus_mode_e bus_mode;  //the bus mode(master, slave or both)the controller supports
    void *priv_info;            //point to the private info of the audio controller 
    int irq;                    //the irq number
    int sdma_ch;                //Will be used for SDMA
    audio_dev_ops_p ops;
} audio_ctrl_t, *audio_ctrl_p;

typedef struct {
    const char *name;
    audio_codec_p codec;
    audio_ctrl_p ctrl;
    void *priv_info;
    audio_dev_ops_p ops;
} audio_card_t, *audio_card_p;

#endif
