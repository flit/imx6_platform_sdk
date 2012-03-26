/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __PWM_HDR__
#define __PWM_HDR__

#include "sdk.h"

typedef struct {
    volatile uint32_t pwmcr;
    volatile uint32_t pwmsr;
    volatile uint32_t pwmir;
    volatile uint32_t pwmsar;
    volatile uint32_t pwmpr;
    volatile uint32_t pwmcnr;
} pwm_reg_t, *pwm_reg_p;

enum {
    CLK_SRC_NONE = 0,
    CLK_SRC_IPG = 1,
    CLK_SRC_CKIH = 2,
    CLK_SRC_CKIL = 3
} clk_src_e;

/* FIFO watermark */
#define PWMCR_MASK_FWM  ((uint32_t)0x0C000000)
#define PWMCR_FWM_SLOT1 (0x00000000)
#define PWMCR_FWM_SLOT2 (0x04000000)
#define PWMCR_FWM_SLOT3 (0x08000000)
#define PWMCR_FWM_SLOT4 (0x0C000000)

/* Clock source selection */
#define PWMCR_MASK_CLKSRC          ((uint32_t)0x00030000)
#define PWMCR_SHIFT_CLKSRC (16)

/* Prescaler */
#define PWMCR_MASK_PRESCALER       ((uint32_t)0x0000FFF0)
#define PWMCR_SHIFT_PRESCALER (4)

/* Threshold value */
#define PWMCR_PRESCALER_MAX   (4096)
#define PWM_CNT_FIFO_SZ       (4)

#define PWMCR_MASK_ENABLE          ((uint32_t)0x00000001)

/* Interrupt enable mask */
#define PWMIR_MASK_INT ((uint32_t)0x7)
#define PWMSR_MASK_ALL ((uint32_t)0x78)

#define PWMSAR_MASK_SMP ((uint32_t)0xFFFF)
#define PWMPR_MASK_PRD  ((uint32_t)0xFFFF)
#define PWMPR_MASK_CNT  ((uint32_t)0xFFFF)

#endif
