/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#ifndef __WATCHDOG__
#define __WATCHDOG__

#include "io.h"

typedef struct {
    volatile uint16_t wcr;      /* control */
    volatile uint16_t wsr;      /* service */
    volatile uint16_t wrsr;     /* reset status */
    volatile uint16_t wicr;     /* interrupt control */
    volatile uint16_t wmcr;     /* misc control */
} watchdog_reg_t, *watchdog_reg_p;

#define WCR_WDE  0x0004         /* write once */
#define WCR_WDT  0x0008         /* write once */
#define WCR_SRS  0x0010         /* software reset */
#define WCR_WDA  0x0020         /* assert output */
#define WCR_WDBG 0x0002         /* suspend time while in debug mode */
#define WCR_WT   0x0300         /* 2 seconds */

/* Timeout = (wt + 1) / 2 */

#endif
