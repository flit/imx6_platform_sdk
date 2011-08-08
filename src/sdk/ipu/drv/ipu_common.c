/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file ipu_common.c
 * @brief common functions defination of IPU.
 * @ingroup diag_ipu
 */

#include <string.h>
#include "ipu_common.h"
#include "hardware.h"

/*!
 * write field of ipu registers, without affecting other bits.
 *
 * @param	ipu_index:	ipu index
 * @param	ID_addr:    register address
 * @param	ID_mask:    fields position
 * @param	data:	    the value of input
 */
void ipu_write_field(int ipu_index, uint32_t ID_addr, uint32_t ID_mask, uint32_t data)
{
    uint32_t rdata;

    if (ipu_index == 1)
        ID_addr += IPU1_CTRL_BASE_ADDR;
    else if (ipu_index == 2)
        ID_addr += IPU2_CTRL_BASE_ADDR;
    else {
        printf("wrong ipu index %d\n", ipu_index);
        return;
    }

    rdata = reg32_read(ID_addr);
    rdata &= ~ID_mask;
    rdata |= (data * (ID_mask & -ID_mask)) & ID_mask;
    reg32_write(ID_addr, rdata);
}

/*!
 * enable submodules of IPU to establish the data path.
 * for different display connection, di0 or di1 should be chosen, we enabled them together here
 */
void ipu_enable_display(int ipu_index)
{
    /*enable all the related submodules. */
    ipu_write_field(ipu_index, IPU_IPU_CONF__DI0_EN, 1);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DI1_EN, 1);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DP_EN, 1);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DC_EN, 1);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DMFC_EN, 1);
}

/*!
 * disable submodules of IPU to establish the data path.
 */
void ipu_disable_display(int ipu_index)
{
    /*enable all the related submodules. */
    ipu_write_field(ipu_index, IPU_IPU_CONF__DI0_EN, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DI1_EN, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DP_EN, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DC_EN, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DMFC_EN, 0);
}

/*!
 * reset ipu by SRC(system reset controller)
 * @param	timeout:    time out setting for ipu reset
 * @return	:   0 for success, others for time out.
 */
int ipu_sw_reset(int timeout)
{
    uint32_t tmpVal;
    int ipuOffset = 0x3;
    tmpVal = readl(SRC_BASE_ADDR);
    writel(tmpVal | (0x1 << ipuOffset), SRC_BASE_ADDR);

    while (timeout > 0) {
        tmpVal = readl(SRC_BASE_ADDR) & (0x1 << ipuOffset);
        timeout--;

        if (tmpVal == 0)
            return 0;
    }

    printf("Error: ipu software reset time out!!\n");
    return -1;
}

void ipu_display_config(int ipu_index)
{
    dmfc_config(ipu_index);
    dc_config(ipu_index);
    dp_config(ipu_index, 1);
    di_config(ipu_index);
    ipu_enable_display(ipu_index);
}
