/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file snvs.h
 * @brief  SNVS driver header file.
 *
 */

#ifndef __SNVS_H__
#define __SNVS_H__

#include "io.h"

/* SNVS driver API */
void snvs_init(struct hw_module *port);
void snvs_deinit(struct hw_module *port);
void snvs_rtc_counter(struct hw_module *port, uint8_t state);
void snvs_rtc_alarm(struct hw_module *port, uint8_t state);
void snvs_rtc_periodic_interrupt(struct hw_module *port, uint8_t freq, uint8_t state);
void snvs_srtc_counter(struct hw_module *port, uint8_t state);
void snvs_srtc_alarm(struct hw_module *port, uint8_t state);
void snvs_rtc_set_counter(struct hw_module *port, uint64_t count);
void snvs_rtc_set_alarm_timeout(struct hw_module *port, uint64_t timeout);
void snvs_srtc_set_counter(struct hw_module *port, uint64_t count);
void snvs_srtc_set_alarm_timeout(struct hw_module *port, uint32_t timeout);

/* SNVS Registers list */
struct mx_snvs {
    volatile uint32_t hplr;
    volatile uint32_t hpcomr;
    volatile uint32_t hpcr;
    volatile uint32_t hpsicr;
    volatile uint32_t hpsvcr;
    volatile uint32_t hpsr;
    volatile uint32_t hpsvsr;
    volatile uint32_t hphacivr;
    volatile uint32_t hphacr;
    volatile uint32_t hprtcmr;
    volatile uint32_t hprtclr;
    volatile uint32_t hptamr;
    volatile uint32_t hptalr;
    volatile uint32_t lplr;
    volatile uint32_t lpcr;
    volatile uint32_t lpmkcr;
    volatile uint32_t lpsvcr;
    volatile uint32_t lplgfcr;
    volatile uint32_t lptdcr;
    volatile uint32_t lpsr;
    volatile uint32_t lpsrtcmr;
    volatile uint32_t lpsrtclr;
    volatile uint32_t lptar;
    volatile uint32_t lpsmcmr;
    volatile uint32_t lpsmclr;
    volatile uint32_t lppgdr;
    volatile uint32_t lpgpr;
    volatile uint32_t lpzmkr0;
    volatile uint32_t lpzmkr1;
    volatile uint32_t lpzmkr2;
    volatile uint32_t lpzmkr3;
    volatile uint32_t lpzmkr4;
    volatile uint32_t lpzmkr5;
    volatile uint32_t lpzmkr6;
    volatile uint32_t lpzmkr7;
};

/* SNVS Registers Bit Fields */
#define HPCR_RTC_EN                     (0x00000001)
#define HPCR_HPTA_EN                    (0x00000002)
#define HPCR_PI_EN                      (0x00000008)
#define HPCR_PI_FREQ_MASK               (0x000000F0)
#define HPCR_PI_FREQ_SHIFT              (4)

#define LPCR_RTC_EN                     (0x00000001)
#define LPCR_LPTA_EN                    (0x00000002)

#define HPSR_HPTA                       (0x00000001)
#define HPSR_PI                         (0x00000002)

#define LPSR_LPTA                       (0x00000001)

#endif //__SNVS_H__
