/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#ifndef __ECSPI_IFC_HDR__
#define __ECSPI_IFC_HDR__

#include "sdk.h"

/* Enumeration define */
typedef enum {
    DEV_ECSPI1 = 0,
    DEV_ECSPI2 = 1,
    DEV_ECSPI3 = 2,
    DEV_ECSPI4 = 3,
    DEV_ECSPI5 = 4,
    NUM_OF_ECSPI
} dev_ecspi_e;

/* Structure define */
typedef union {
    uint32_t U;
    struct {
        unsigned channel:2;     //SS channel
        unsigned mode:1;        //0: slave, 1: master
        unsigned ss_pol:1;      //0: active low, 1: active high
        unsigned sclk_pol:1;    //0: active high, 1: active low
        unsigned sclk_pha:1;    //0: phase 0 op, 1: phase 1 op
        unsigned pre_div:4;     //clock pre-divider
        unsigned post_div:4;    //clock post-divider
        unsigned reserved:18;   //reserved
    } B;
} param_ecspi_t, *param_ecspi_p;

/* Function define */

/*!
 * Open and initialize eCSPI device
 * Parameter:
 *     device:    eCSPI port
 *     parameter: device configuration defined above
 * Return:
 *     TRUE on success, FALSE on failure
 */
extern int ecspi_open(dev_ecspi_e, param_ecspi_t);

/*!
 * Close/disable eCSPI  device
 * Parameter:
 *     device:	 eCSPI port
 * Return:
 *     TRUE on success, FALSE on failure
 */
extern int ecspi_close(dev_ecspi_e);

/*!
 * Configure eCSPI device
 * Parameter:
 *     device:    eCSPI port
 *     parameter: device configuration defined above
 * Return:
 *     TRUE on success, FALSE on failure
 */
extern int ecspi_ioctl(dev_ecspi_e, param_ecspi_t);

/*!
 * Transfer from/to target device
 * Parameter:
 *     device:    eCSPI port
 *     tx_buf:    source buffer that contain data to send
 *     rx_buf:    buffer that store data received
 *     brs_bts:   burst length in bits
 * Return:
 *     TRUE on success, FALSE on failure
 */
extern int ecspi_xfer(dev_ecspi_e, uint8_t *, uint8_t *, uint16_t);

#endif
