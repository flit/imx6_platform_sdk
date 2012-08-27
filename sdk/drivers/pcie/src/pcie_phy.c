/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"
#include "soc_memory_map.h"
#include "pcie/pcie_common.h"

#define PCIE_PHY_CR_ACK_POLLING_TIMES	0x100

/***************** PCI-e phy variable and routines ***************/
static int pcie_phy_cr_ack_polling(int32_t max_iterations, int32_t exp_val)
{
    uint32_t val;
    int wait_counter;

    wait_counter = 0;
    do {
        val = (reg32_read(PCIE_DBI_BASE_ADDR + PHY_STS_R) >> PCIE_CR_STAT_ACK_LOC) & 0x1;
        wait_counter++;
    } while ((wait_counter < max_iterations) && (val != exp_val));

    if (val != exp_val)
        return -1;

    return 0;
}

static int pcie_phy_cr_cap_addr(uint32_t addr)
{
    int val;

    // write addr
    val = (addr & 0xFFFF) << PCIE_CR_CTL_DATA_LOC;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // capture addr
    val |= (0x1 << PCIE_CR_CTL_CAP_ADR_LOC);
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // wait for ack
    if (0 != pcie_phy_cr_ack_polling(PCIE_PHY_CR_ACK_POLLING_TIMES, 1)) {
        return -1;
    }
    // deassert cap addr
    val = (addr & 0xFFFF) << PCIE_CR_CTL_DATA_LOC;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // wait for ack de-assetion
    if (0 != pcie_phy_cr_ack_polling(PCIE_PHY_CR_ACK_POLLING_TIMES, 0)) {
        return -1;
    }

    return 0;
}

/*! 
 * This function read the control register of the PCIE phy
 * @param    addr: address of the register to be read	
 * @param    data:	register value be read
 *
 * @return   0 on success,
 *           -1 if failed
 */
int pcie_phy_cr_read(uint32_t addr, uint32_t * data)
{
    int32_t val;

    if (0 != pcie_phy_cr_cap_addr(addr)) {
        return -1;
    }
    // assert rd signal
    val = 0x1 << PCIE_CR_CTL_RD_LOC;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // wait for ack
    if (0 != pcie_phy_cr_ack_polling(PCIE_PHY_CR_ACK_POLLING_TIMES, 1)) {
        return -1;
    }
    // read data
    val = reg32_read(PCIE_DBI_BASE_ADDR + PHY_STS_R);
    *data = (val >> PCIE_CR_STAT_DATA_LOC) & 0xFFFF;

    // deassert rd signal
    val = 0x0;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // wait for ack de-assetion
    if (0 != pcie_phy_cr_ack_polling(PCIE_PHY_CR_ACK_POLLING_TIMES, 0)) {
        return -1;
    }

    return 0;
}

/*! 
 * This function write the control register of the PCIE phy
 * @param    addr: address of the register to be written
 * @param    data:	register value to be written
 *
 * @return   0 on success,
 *           -1 if failed
 */
int pcie_phy_cr_write(uint32_t addr, uint32_t data)
{
    int32_t val;

    if (0 != pcie_phy_cr_cap_addr(addr)) {
        return -1;
    }

    val = (data & 0xFFFF) << PCIE_CR_CTL_DATA_LOC;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // capture data
    val |= (0x1 << PCIE_CR_CTL_CAP_DAT_LOC);
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // wait for ack
    if (0 != pcie_phy_cr_ack_polling(PCIE_PHY_CR_ACK_POLLING_TIMES, 1)) {
        return -1;
    }
    // deassert cap data
    val = (data & 0xFFFF) << PCIE_CR_CTL_DATA_LOC;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // wait for ack de-assetion
    if (0 != pcie_phy_cr_ack_polling(PCIE_PHY_CR_ACK_POLLING_TIMES, 0)) {
        return -1;
    }
    // assert wr signal
    val = 0x1 << PCIE_CR_CTL_WR_LOC;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // wait for ack
    if (0 != pcie_phy_cr_ack_polling(PCIE_PHY_CR_ACK_POLLING_TIMES, 1)) {
        return -1;
    }
    // deassert wr signal
    val = (data & 0xFFFF) << PCIE_CR_CTL_DATA_LOC;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);
    // wait for ack de-assetion
    if (0 != pcie_phy_cr_ack_polling(PCIE_PHY_CR_ACK_POLLING_TIMES, 0)) {
        return -1;
    }
    val = 0x0;
    reg32_write(PCIE_DBI_BASE_ADDR + PHY_CTRL_R, val);

    return 0;
}
