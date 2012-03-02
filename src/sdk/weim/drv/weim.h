/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __WEIM_HDR__
#define __WEIM_HDR__

#include "io.h"
#include "../inc/weim_ifc.h"

enum weim_reg_e {
    WEIM_GCR1 = 0,
    WEIM_GCR2 = 1,
    WEIM_RCR1 = 2,
    WEIM_RCR2 = 3,
    WEIM_WCR1 = 4,
    WEIM_WCR2 = 5,
    WEIM_WCR = 6,
    WEIM_WIAR = 7,
    WEIM_NUM_REG = 8            //EAR is read only
};

#define REG_CSCFG_MSK_CSEN ((uint32_t)0x00000001)
#define REG_CSCFG_MSK_DSZ  ((uint32_t)0x00070000)
#define REG_CSCFG_MSK_MUM  ((uint32_t)0x00000008)
#define REG_CSCFG_MSK_SHFT ((uint32_t)0x00800000)
#define REG_CSCFG_DSZ_SHIFT 16
#define REG_CSCFG_MAX_DSZ 7
#define REG_CSCFG_MIN_DSZ 1

typedef struct {
    volatile uint32_t gcr1;
    volatile uint32_t gcr2;
    volatile uint32_t rcr1;
    volatile uint32_t rcr2;
    volatile uint32_t wcr1;
    volatile uint32_t wcr2;
} weim_cs_reg_t, *weim_cs_reg_p;

typedef struct {
    weim_cs_reg_t reg_cs[WEIM_NUM_CS];

    volatile uint32_t wcr;
    volatile uint32_t wiar;
    volatile uint32_t ear;
} weim_reg_t, *weim_reg_p;

typedef struct {
    uint8_t id;                 //parameter ID
    uint8_t boolean;            //boolean or integer
    uint8_t shift;              //bit shift in register
    uint8_t reg;                //which register
    uint32_t mask;              //CFG mask
} weim_cfg_t;

#endif
