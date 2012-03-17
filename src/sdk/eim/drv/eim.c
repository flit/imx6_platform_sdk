/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>

#include "eim.h"
#include "hardware.h"

static eim_reg_p eim_reg_base;
static eim_cfg_t cfg_table[] = {
/*	ID						BOOL	SHF	REGISTER		MASK 		*/
    {GCR1_CSEN, TRUE, 0, EIM_GCR1, 0x00000001},
    {GCR1_SWR, TRUE, 1, EIM_GCR1, 0x00000002},
    {GCR1_SDR, TRUE, 2, EIM_GCR1, 0x00000004},
    {GCR1_MUM, TRUE, 3, EIM_GCR1, 0x00000008},
    {GCR1_WFL, TRUE, 4, EIM_GCR1, 0x00000010},
    {GCR1_RFL, TRUE, 5, EIM_GCR1, 0x00000020},
    {GCR1_CRE, TRUE, 6, EIM_GCR1, 0x00000040},
    {GCR1_CREP, TRUE, 7, EIM_GCR1, 0x00000080},
    {GCR1_BL, FALSE, 8, EIM_GCR1, 0x00000700},
    {GCR1_WC, TRUE, 11, EIM_GCR1, 0x00000800},
    {GCR1_BCD, FALSE, 12, EIM_GCR1, 0x00003000},
    {GCR1_BCS, FALSE, 14, EIM_GCR1, 0x0000C000},
    {GCR1_DSZ, FALSE, 16, EIM_GCR1, 0x00070000},
    {GCR1_SP, TRUE, 19, EIM_GCR1, 0x00080000},
    {GCR1_CSREC, FALSE, 20, EIM_GCR1, 0x00700000},
    {GCR1_AUS, TRUE, 23, EIM_GCR1, 0x00800000},
    {GCR1_GBC, FALSE, 24, EIM_GCR1, 0x07000000},
    {GCR1_WP, TRUE, 27, EIM_GCR1, 0x08000000},
    {GCR1_PSZ, FALSE, 28, EIM_GCR1, 0xF0000000},

    {GCR2_ADH, FALSE, 0, EIM_GCR2, 0x00000003},
    {GCR2_DAPS, FALSE, 4, EIM_GCR2, 0x000000F0},
    {GCR2_DAE, TRUE, 8, EIM_GCR2, 0x00000100},
    {GCR2_DAP, TRUE, 9, EIM_GCR2, 0x00000200},
    {GCR2_MUX16_BYP_GRANT, TRUE, 12, EIM_GCR2, 0x00001000},

    {RCR1_RCSN, FALSE, 0, EIM_RCR1, 0x00000007},
    {RCR1_RCSA, FALSE, 4, EIM_RCR1, 0x00000070},
    {RCR1_OEN, FALSE, 8, EIM_RCR1, 0x00000700},
    {RCR1_OEA, FALSE, 12, EIM_RCR1, 0x00007000},
    {RCR1_RADVN, FALSE, 16, EIM_RCR1, 0x00070000},
    {RCR1_RAL, TRUE, 19, EIM_RCR1, 0x00080000},
    {RCR1_RADVA, FALSE, 20, EIM_RCR1, 0x00700000},
    {RCR1_RWSC, FALSE, 24, EIM_RCR1, 0x3F000000},

    {RCR2_RBEN, FALSE, 0, EIM_RCR2, 0x00000007},
    {RCR2_RBE, TRUE, 3, EIM_RCR2, 0x00000008},
    {RCR2_RBEA, FALSE, 4, EIM_RCR2, 0x00000070},
    {RCR2_RL, FALSE, 8, EIM_RCR2, 0x00000300},
    {RCR2_PAT, FALSE, 12, EIM_RCR2, 0x00007000},
    {RCR2_APR, TRUE, 15, EIM_RCR2, 0x00008000},

    {WCR1_WCSN, FALSE, 0, EIM_WCR1, 0x00000007},
    {WCR1_WCSA, FALSE, 3, EIM_WCR1, 0x00000038},
    {WCR1_WEN, FALSE, 6, EIM_WCR1, 0x000001C0},
    {WCR1_WEA, FALSE, 9, EIM_WCR1, 0x00000E00},
    {WCR1_WBEN, FALSE, 12, EIM_WCR1, 0x00007000},
    {WCR1_WBEA, FALSE, 15, EIM_WCR1, 0x00038000},
    {WCR1_WADVN, FALSE, 18, EIM_WCR1, 0x001C0000},
    {WCR1_WADVA, FALSE, 21, EIM_WCR1, 0x00E00000},
    {WCR1_WWSC, FALSE, 24, EIM_WCR1, 0x3F000000},
    {WCR1_WBED, TRUE, 30, EIM_WCR1, 0x40000000},
    {WCR1_WAL, TRUE, 31, EIM_WCR1, 0x80000000},

    {WCR2_WBCDD, TRUE, 0, EIM_WCR2, 0x00000001},

    {WCR_BCM, TRUE, 0, EIM_WCR, 0x00000001},
    {WCR_GBCD, FALSE, 1, EIM_WCR, 0x00000006},
    {WCR_INTEN, TRUE, 4, EIM_WCR, 0x00000010},
    {WCR_INTPOL, TRUE, 5, EIM_WCR, 0x00000020},
    {WCR_WDOG_EN, TRUE, 8, EIM_WCR, 0x00000100},
    {WCR_WDOG_LIMIT, FALSE, 9, EIM_WCR, 0x00000600},

    {WIAR_IPS_REG, TRUE, 0, EIM_WIAR, 0x00000001},
    {WIAR_IPS_ACK, TRUE, 1, EIM_WIAR, 0x00000002},
    {WIAR_INT, TRUE, 2, EIM_WIAR, 0x00000004},
    {WIAR_ERRST, TRUE, 3, EIM_WIAR, 0x00000008},
    {WIAR_ACLK_EN, TRUE, 4, EIM_WIAR, 0x00000010},

    {NUM_CFG, FALSE, 0, EIM_NUM_REG, 0x00000000},
};

uint32_t eim_init(uint32_t cs, uint32_t dsz, uint32_t mum, uint32_t aus)
{
    /*
     * Init clock
     */

    /* Init EIM controller */
    eim_reg_base = (eim_reg_p) WEIM_BASE_ADDR;

    if (cs >= EIM_NUM_CS) {
        printf("Invalid chip select.\n");
        return FALSE;
    }

    if ((dsz > REG_CSCFG_MAX_DSZ) || (dsz < REG_CSCFG_MIN_DSZ)) {
        printf("Invalid data port size.\n");
        return FALSE;
    }

    /* Set data port size */
    eim_reg_base->reg_cs[cs].gcr1 &= ~REG_CSCFG_MSK_DSZ;
    eim_reg_base->reg_cs[cs].gcr1 |= dsz << REG_CSCFG_DSZ_SHIFT;

    /* Set multiplexed mode */
    if (mum == TRUE) {
        eim_reg_base->reg_cs[cs].gcr1 |= REG_CSCFG_MSK_MUM;
    } else {
        eim_reg_base->reg_cs[cs].gcr1 &= ~REG_CSCFG_MSK_MUM;
    }

    /* Set address unshift */
    if (aus == TRUE) {
        eim_reg_base->reg_cs[cs].gcr1 |= REG_CSCFG_MSK_SHFT;
    } else {
        eim_reg_base->reg_cs[cs].gcr1 &= ~REG_CSCFG_MSK_SHFT;
    }

    /* Enable chip select */
    eim_reg_base->reg_cs[cs].gcr1 |= REG_CSCFG_MSK_CSEN;

    /* Init IOMUX */
    weim_iomux_config();

    return TRUE;
}

uint32_t eim_cfg_set(uint32_t cs, uint32_t cfg, uint32_t value)
{
    uint32_t idx;
    volatile uint32_t *reg;

    /* Lookup CFG in table */
    for (idx = 0; cfg_table[idx].id != NUM_CFG; idx++) {
        if (cfg == cfg_table[idx].id) {
            break;
        }
    }

    if (cfg_table[idx].id == NUM_CFG) {
        printf("Invalid CFG id.\n");
        return FALSE;
    }

    /* Validate CS */
    if (cs >= EIM_NUM_CS) {
        printf("Invalid CS value.\n");
        return FALSE;
    }

    /* Obtain register address */
    switch (cfg_table[idx].reg) {
    case EIM_GCR1:
        reg = &eim_reg_base->reg_cs[cs].gcr1;
        break;
    case EIM_GCR2:
        reg = &eim_reg_base->reg_cs[cs].gcr2;
        break;
    case EIM_RCR1:
        reg = &eim_reg_base->reg_cs[cs].rcr1;
        break;
    case EIM_RCR2:
        reg = &eim_reg_base->reg_cs[cs].rcr2;
        break;
    case EIM_WCR1:
        reg = &eim_reg_base->reg_cs[cs].wcr1;
        break;
    case EIM_WCR2:
        reg = &eim_reg_base->reg_cs[cs].wcr2;
        break;
    case EIM_WCR:
        reg = &eim_reg_base->wcr;
        break;
    case EIM_WIAR:
        reg = &eim_reg_base->wiar;
        break;
    default:                   /* should never happen */
        break;
    }

    /* Boolean CFG */
    if (cfg_table[idx].boolean == TRUE) {
        if (value == TRUE) {
            *reg |= cfg_table[idx].mask;
        } else {
            *reg &= ~cfg_table[idx].mask;
        }
    }

    /* Integer CFG */
    else {
        if (value > (cfg_table[idx].mask >> cfg_table[idx].shift)) {
            printf("Invalid CFG value.\n");
            return FALSE;
        }

        *reg = (*reg & (~cfg_table[idx].mask)) | (value << cfg_table[idx].shift);
    }

    return TRUE;
}
