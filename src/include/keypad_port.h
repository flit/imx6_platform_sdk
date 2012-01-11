/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __KEYPAD_PORT_H__
#define __KEYPAD_PORT_H__

#include "io.h"

/* registers address */
#define KPP_KPCR (KPP_BASE_ADDR + KPP_KPCR_OFFSET)
#define KPP_KPSR (KPP_BASE_ADDR + KPP_KPSR_OFFSET)
#define KPP_KDDR (KPP_BASE_ADDR + KPP_KDDR_OFFSET)
#define KPP_KPDR (KPP_BASE_ADDR + KPP_KPDR_OFFSET)

/* bit field of KPSR register */
#define KRIE    (1 << 9)
#define KDIE    (1 << 8)
#define KRSS    (1 << 3)
#define KDSC    (1 << 2)
#define KPKR    (1 << 1)
#define KPKD    (1 << 0)

/* macros */
#define set_col_opendrain(x)    writew((x << 8), KPP_KPCR)
#define set_col_drive(x)        writew((~x << 8), KPP_KPCR)

#define enable_irq(x)           writew(x, KPP_KPSR)
#define disable_irq(x)          writew(readw(KPP_KPSR) & ~(x), KPP_KPSR)

#define COL_IN_TTPOLE   0x0000
#define COL_IN_ODRAIN   0xFF00

/* functions of the driver */
void kpp_init(void);
void kpp_setup_interrupt(uint8_t state);
uint8_t kpp_get_key(uint16_t *rd_keys, uint8_t kpp_col, uint8_t kpp_row);

#endif /* __KEYPAD_PORT_H__ */
