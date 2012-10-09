/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __LDB_DEF_H__
#define __LDB_DEF_H__

//! @addtogroup diag_ldb
//! @{

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

//! @brief Enumeration of available BIT mode for LDB
enum lvds_panel_bit_mode {
    LVDS_PANEL_18BITS_MODE = 0x0,
    LVDS_PANEL_24BITS_MODE = 0x1,
};

//! @brief Enumeration of LVDS port mode
//
//! LVDS_DUAL_PORT means the two ports are activated together with duplicated
//! content.
//!
//! LVDS_SPLIT_PORT means the two ports are activated together, one to display
//! the odd columns and the other for even columns
enum lvds_port {
    LVDS_PORT0,
    LVDS_PORT1,
    LVDS_DUAL_PORT,
    LVDS_SPLIT_PORT,
};

//! @brief Enumeration of LVDS bitmap
enum lvds_bitmap {
    SPWG,
    JEIDA,
};

///////////////////////////////////////////////////////////////////////////////
// API
///////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Configure the LVDS bridge to driven the synchronous LVDS panel
 *
 * @param ipu_port IPU display port selection, available value could be IPU<x>_DI<y>
 * @param lvds_port LVDS channel selection
 * @param data_width 18 or 24bit mode selection
 * @param bit_map SPWG or JEIDA mode selection 
 */
void ldb_config(int ipu_port, int lvds_port, int data_width, int bit_map);

/*!
 * @brief Vsync polarity setting
 * 
 * @param ipu_port IPU display port selection, di0 or di1
 * @param vs_pol Vsync polarity setting
 * 
 */
void ldb_set_vs_polarity(int ipu_port, int vs_pol);

//! @}
#endif
///////////////////////////////////////////////////////////////////////////////
// EOF
///////////////////////////////////////////////////////////////////////////////

