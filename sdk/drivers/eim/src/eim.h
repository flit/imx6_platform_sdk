/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __EIM_HDR__
#define __EIM_HDR__

#include "sdk.h"
#include "eim/eim_ifc.h"

enum eim_reg_e {
    EIM_GCR1 = 0,
    EIM_GCR2 = 1,
    EIM_RCR1 = 2,
    EIM_RCR2 = 3,
    EIM_WCR1 = 4,
    EIM_WCR2 = 5,
    EIM_WCR = 6,
    EIM_WIAR = 7,
    EIM_NUM_REG = 8            //EAR is read only
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
} eim_cs_reg_t, *eim_cs_reg_p;

typedef struct {
    eim_cs_reg_t reg_cs[EIM_NUM_CS];

    volatile uint32_t wcr;
    volatile uint32_t wiar;
    volatile uint32_t ear;
} eim_reg_t, *eim_reg_p;

typedef struct {
    uint8_t id;                 //parameter ID
    uint8_t boolean;            //boolean or integer
    uint8_t shift;              //bit shift in register
    uint8_t reg;                //which register
    uint32_t mask;              //CFG mask
} eim_cfg_t;

#endif
