/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ldb.c
 * @brief lvds bridge configuration.
 * @ingroup diag_ldb
 */

#include <stdio.h>
#include <string.h>
#include "hardware.h"
#include "ldb_def.h"
#include "../../ipu/inc/ipu_common.h"

inline void ldb_write_field(unsigned int reg, int bit_offset, int bit_width, unsigned int val)
{
    uint32_t data;

    data = reg32_read(reg);
    data &= ~(((1 << bit_width) - 1) << bit_offset);
    data |= val << bit_offset;
    reg32_write(reg, data);
}

inline void ldb_set_channel_route(int ipu_port, int lvds_port)
{
    if (ipu_port == IPU1_DI0 || ipu_port == IPU2_DI0) {
        if (lvds_port == LVDS_PORT0)
            ldb_write_field(LDB_CTRL_REG, 0, 2, 1);
        else if (lvds_port == LVDS_PORT1)
            ldb_write_field(LDB_CTRL_REG, 2, 2, 1);
        else {
            ldb_write_field(LDB_CTRL_REG, 0, 2, 1);
            ldb_write_field(LDB_CTRL_REG, 2, 2, 1);
        }
    } else if (ipu_port == IPU1_DI1 || ipu_port == IPU2_DI1) {
        if (lvds_port == LVDS_PORT0)
            ldb_write_field(LDB_CTRL_REG, 0, 2, 3);
        else if (lvds_port == LVDS_PORT1)
            ldb_write_field(LDB_CTRL_REG, 2, 2, 3);
        else {
            ldb_write_field(LDB_CTRL_REG, 0, 2, 3);
            ldb_write_field(LDB_CTRL_REG, 2, 2, 3);
        }
    } else {
        printf("Wrong IPU display port %d input!!\n", ipu_port);
        return;
    }
}

/*!
 * lvds bridge configuration
 *
 * @param	ipu_port: 	ipu display port selection, di0 or di1
 * @param 	lvds_port:	lvds channel selection
 * @param   data_width:	18 or 24bit mode selection
 * @param 	bit_map:	SPWG or JEIDA mode selection
 *
 */
void ldb_config(int ipu_port, int lvds_port, int data_width, int bit_map)
{
    switch (lvds_port) {
    case LVDS_PORT0:
        ldb_write_field(LDB_CTRL_REG, 6, 1, bit_map);
        ldb_write_field(LDB_CTRL_REG, 5, 1, data_width);
#ifdef MX61
        ldb_write_field(IOMUXC_GPR3, 6, 2, ipu_port);
#endif
        break;
    case LVDS_PORT1:
        ldb_write_field(LDB_CTRL_REG, 8, 1, bit_map);
        ldb_write_field(LDB_CTRL_REG, 7, 1, data_width);
#ifdef MX61
        ldb_write_field(IOMUXC_GPR3, 8, 2, ipu_port);
#endif
        break;
    case LVDS_SPLIT_PORT:
        ldb_write_field(LDB_CTRL_REG, 4, 1, 1);
        break;
    case LVDS_DUAL_PORT:
        ldb_write_field(LDB_CTRL_REG, 8, 1, bit_map);
        ldb_write_field(LDB_CTRL_REG, 7, 1, data_width);
        ldb_write_field(LDB_CTRL_REG, 6, 1, bit_map);
        ldb_write_field(LDB_CTRL_REG, 5, 1, data_width);
#ifdef MX61
        ldb_write_field(IOMUXC_GPR3, 6, 2, ipu_port);
        ldb_write_field(IOMUXC_GPR3, 8, 2, ipu_port);
#endif
        break;
    default:
        printf("Wrong LVDS port input!!\n");
        return;
    }
    ldb_set_channel_route(ipu_port, lvds_port);

}

/*!
 * vsync polarity setting
 *
 * @param	ipu_port: 	ipu display port selection, di0 or di1
 * @param 	vs_pol:		vsync polarity setting
 *
 */
void ldb_set_vs_polarity(int ipu_port, int vs_pol)
{
    switch (ipu_port) {
    case IPU1_DI0:
    case IPU2_DI0:
        ldb_write_field(LDB_CTRL_REG, 9, 1, vs_pol);
        break;
    case IPU1_DI1:
    case IPU2_DI1:
        ldb_write_field(LDB_CTRL_REG, 10, 1, vs_pol);
        break;
    default:
        printf("unkown display port %d!! please check.\n", ipu_port);
        break;
    }
}
