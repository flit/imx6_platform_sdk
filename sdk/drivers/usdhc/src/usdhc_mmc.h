/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 * Module Name: usdhc_mmc.h
 */

#ifndef __USDHC_MMC_H__
#define __USDHC_MMC_H__

#define MMC_SWITCH_SET_BUS_WIDTH 0x3B70000
#define MMC_SWITCH_SET_BOOT_BUS_WIDTH 0x3B10000
#define MMC_SWITCH_SET_BOOT_PARTITION 0x3B30000

#define MMC_SWITCH_SET_BOOT_ACK 0x01B34000
#define MMC_SWITCH_CLR_BOOT_ACK 0x02B34000

#define MMC_SWITCH_SET_PARAM_SHIFT 0x8

/* boot bus width */
#define BBW_1BIT 	(0x0<<0)
#define BBW_4BIT 	(0x1<<0)
#define BBW_8BIT 	(0x2<<0)
#define BBW_SAVE 	(0x1<<2)
#define BBW_DDR 	(0x2<<3)

#define BBW_DDR_MASK	(0x3<<3)
#define BBW_BUS_MASK	(0x3<<0)
#define BBW_SAV_MASK	(0x1<<2)

/* boot partition */
#define BP_USER		(0x7<<3)
#define BP_BT1		(0x1<<3)
#define BP_BT2		(0x2<<3)
#define BT_ACK		(0x1<<6)
#define BP_MASK		(0x7<<3)

#define BP_SHIFT 3
#define ACK_SHIFT 6

/* offset in esd */
#define MMC_ESD_OFF_PRT_CFG 179
#define MMC_ESD_OFF_BT_BW 177

enum mmc_ver_e {
    MMC_CARD_3_X,
    MMC_CARD_4_X,
    MMC_CARD_4_4,
    MMC_CARD_INV
};

struct csd_struct {
    uint32_t response[4];

    uint8_t ssv;                //system spec version
    uint8_t csds;               //CSD structure
};

#endif
