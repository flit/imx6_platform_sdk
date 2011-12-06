/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ldb_def.h
 * @brief common macro and data structre defination of LDB module.
 * @ingroup diag_ldb
 */

#ifndef __LDB_DEF_H__
#define __LDB_DEF_H__

#define	LDB_CTRL_REG IOMUXC_GPR2

enum lvds_panel_bit_mode {
    LVDS_PANEL_18BITS_MODE = 0x0,
    LVDS_PANEL_24BITS_MODE = 0x1,
};

enum lvds_port {
    LVDS_PORT0,
    LVDS_PORT1,
    LVDS_DUAL_PORT,
    LVDS_SPLIT_PORT,
};

enum lvds_bitmap {
    SPWG,
    JEIDA,
};

void ldb_config(int ipu_port, int lvds_port, int data_width, int bit_map);

#endif
