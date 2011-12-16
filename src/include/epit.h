/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file epit.h
 * @brief EPIT driver header file.
 * @ingroup diag_timer
 */

#ifndef __EPIT_H__
#define __EPIT_H__

#include "io.h"

/* EPIT Registers Bit Fields */
    /* x = clock source */
#define EPITCR_CLKSRC(x)        ((x) << 24) // clock source
    /* x = output mode */
#define EPITCR_OM_MODE(x)       ((x) << 22) // EPIT output mode
#define EPITCR_STOPEN           (1 << 21)   // EPIT enabled in STOP mode
#define EPITCR_WAITEN           (1 << 19)   // EPIT enabled in WAIT mode
#define EPITCR_DBGEN            (1 << 18)   // EPIT enabled in debug mode
#define EPITCR_IOVW             (1 << 17)   // write to load register overwrite the current value
#define EPITCR_SWR              (1 << 16)   // starts a software reset
#define EPITCR_PRESCALAR(x)     (((x) & 0xFFF) << 4)  // set prescaler value
#define EPITCR_RLD              (1 << 3)    // enable counter reload from modulus register
#define EPITCR_OCIEN            (1 << 2)    // output compare interrupt enabled
#define EPITCR_ENMOD            (1 << 1)    // counter start mode
#define EPITCR_EN               (1 << 0)    // EPIT enable

#define EPITSR_OCIF             (1 << 0)    // Compare event occured

/* EPIT specific defines */
#define FREE_RUNNING    0
#define SET_AND_FORGET  EPITCR_RLD

#define IRQ_MODE 1

/* EPIT driver list of functions */
void epit_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
               uint32_t reload_mode, uint32_t load_val, uint32_t low_power_mode);
void epit_setup_interrupt(struct hw_module *port, uint8_t state);
void epit_counter_enable(struct hw_module *port, uint32_t load_val, uint32_t irq_mode);
void epit_counter_disable(struct hw_module *port);
uint32_t epit_get_compare_event(struct hw_module *port);
void epit_reload_counter(struct hw_module *port, uint32_t load_val);

/* EPIT Registers list */
struct mx_epit {
    volatile uint32_t epitcr;
    volatile uint32_t epitsr;
    volatile uint32_t epitlr;
    volatile uint32_t epitcmpr;
    volatile uint32_t epitcnr;
};

#endif //__EPIT_H__
