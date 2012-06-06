/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __EIM_IFC__
#define __EIM_IFC__

#include "sdk.h"

/* CS enumeration */
enum eim_cs_e {
    EIM_CS0 = 0,
    EIM_CS1 = 1,
    EIM_CS2 = 2,
    EIM_CS3 = 3,
    EIM_CS4 = 4,
    EIM_CS5 = 5,
    EIM_NUM_CS = 6
};

/* CFG ID enumeration */
enum eim_cfg_e {
    GCR1_CSEN = 0,              //GCR1
    GCR1_SWR,
    GCR1_SDR,
    GCR1_MUM,
    GCR1_WFL,
    GCR1_RFL,
    GCR1_CRE,
    GCR1_CREP,
    GCR1_BL,
    GCR1_WC,
    GCR1_BCD,
    GCR1_BCS,
    GCR1_DSZ,
    GCR1_SP,
    GCR1_CSREC,
    GCR1_AUS,
    GCR1_GBC,
    GCR1_WP,
    GCR1_PSZ,
    GCR2_ADH,                   //GCR2
    GCR2_DAPS,
    GCR2_DAE,
    GCR2_DAP,
    GCR2_MUX16_BYP_GRANT,
    RCR1_RCSN,                  //RCR1
    RCR1_RCSA,
    RCR1_OEN,
    RCR1_OEA,
    RCR1_RADVN,
    RCR1_RAL,
    RCR1_RADVA,
    RCR1_RWSC,
    RCR2_RBEN,                  //RCR2
    RCR2_RBE,
    RCR2_RBEA,
    RCR2_RL,
    RCR2_PAT,
    RCR2_APR,
    WCR1_WCSN,                  //WCR1
    WCR1_WCSA,
    WCR1_WEN,
    WCR1_WEA,
    WCR1_WBEN,
    WCR1_WBEA,
    WCR1_WADVN,
    WCR1_WADVA,
    WCR1_WWSC,
    WCR1_WBED,
    WCR1_WAL,
    WCR2_WBCDD,                 //WCR2
    WCR_BCM,                    //WCR
    WCR_GBCD,
    WCR_INTEN,
    WCR_INTPOL,
    WCR_WDOG_EN,
    WCR_WDOG_LIMIT,
    WIAR_IPS_REG,               //WIAR
    WIAR_IPS_ACK,
    WIAR_INT,
    WIAR_ERRST,
    WIAR_ACLK_EN,
    NUM_CFG
};

/* Data port size */
enum eim_dsz_e {
    DSZ_16_LOW = 1,
    DSZ_16_HIGH = 2,
    DSZ_32 = 3,
    DSZ_8_LOW_LOW = 4,
    DSZ_8_LOW_HIGH = 5,
    DSZ_8_HIGH_LOW = 6,
    DSZ_8_HIGH_HIGH = 7
};

/*!
 * @brief Initialize EIM controller.
 *
 * Only setup the data port size and enable the chip select.
 * 
 * @param cs chip select
 * @param dsz data port size
 * @param mum multiplexed mode
 * @param aus address unshift
 * 
 * @return TRUE on success, FALSE on fail
 */
extern uint32_t eim_init(uint32_t, uint32_t, uint32_t, uint32_t);

/*!
 * @brief Setup EIM configuration, each field per call.
 *
 * @param cs chip select
 * @param cfg CFG id
 * @param value CFG value
 *
 * @return TRUE on success, FALSE on fail
 */
extern uint32_t eim_cfg_set(uint32_t, uint32_t, uint32_t);

#endif
