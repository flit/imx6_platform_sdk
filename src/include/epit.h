/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file epit.h
 * @brief  Defines related to the EPIT controller and used by epit.c
 *
 */

#ifndef __EPIT_H__
#define __EPIT_H__

#include "io.h"

/* EPIT Registers Bit Fields */
#define EPITCR_CLKSRC_OFF       (0 << 24)   // clock source is OFF
#define EPITCR_CLKSRC_PER_CLK   (1 << 24)   // clock source is peripheral clock
#define EPITCR_CLKSRC_HIFREQ_CLK    (2 << 24)   // clock source is high-freq reference clock
#define EPITCR_CLKSRC_LOFREQ_CLK    (3 << 24)   // clock source is low-freq reference clock
#define EPITCR_OM_DISC          (0 << 22)   // EPIT output disconneted from pad
#define EPITCR_OM_TOGGLE        (1 << 22)   // EPIT output toggle mode
#define EPITCR_OM_CLR           (2 << 22)   // EPIT output set low mode
#define EPITCR_OM_SET           (3 << 22)   // EPIT output set high mode
#define EPITCR_STOPEN           (1 << 21)   // EPIT enabled in STOP mode
#define EPITCR_WAITEN           (1 << 19)   // EPIT enabled in WAIT mode
#define EPITCR_DBGEN            (1 << 18)   // EPIT enabled in debug mode
#define EPITCR_IOVW             (1 << 17)   // write to load register overwrite the current value
#define EPITCR_SWR              (1 << 16)   // starts a software reset
#define EPITCR_PRESCALAR(x)     ((x & 0xFFF) << 4)  // set prescaler value
#define EPITCR_RLD              (1 << 3)    // enable counter reload from modulus register
#define EPITCR_OCIEN            (1 << 2)    // output compare interrupt enabled
#define EPITCR_ENMOD            (1 << 1)    // counter start mode
#define EPITCR_EN               (1 << 0)    // EPIT enable
#define EPITSR_OCIF             (1 << 0)    // Compare event occured

/* EPIT specific defines */
#define WAIT_MODE_EN    EPITCR_WAITEN
#define STOP_MODE_EN    EPITCR_STOPEN
#define CLKSRC_OFF      EPITCR_CLKSRC_OFF          // clock source is OFF
#define CLKSRC_IPG_CLK  EPITCR_CLKSRC_PER_CLK      // clock source is peripheral clock
#define CLKSRC_PER_CLK  EPITCR_CLKSRC_HIFREQ_CLK   // clock source is high-freq reference clock
#define CLKSRC_CKIL     EPITCR_CLKSRC_LOFREQ_CLK   // clock source is low-freq reference clock
#define FREE_RUNNING    0
#define SET_AND_FORGET  EPITCR_RLD

/* EPIT driver list of functions */
void epit_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
               uint32_t reload_mode, uint32_t load_val, uint32_t low_power_mode);
void epit_setup_interrupt(struct hw_module *port, uint8_t state);
void epit_enable(struct hw_module *port);


/* EPIT Registers list */
struct mx_epit {
    volatile uint32_t epitcr;
    volatile uint32_t epitsr;
    volatile uint32_t epitlr;
    volatile uint32_t epitcmpr;
    volatile uint32_t epitcnr;
};

#endif //__EPIT_H__
