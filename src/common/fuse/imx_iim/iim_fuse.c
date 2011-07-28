/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "iim_fuse.h"

#define IIM_ERR_SHIFT       8
#define POLL_FUSE_PRGD      (IIM_STAT_PRGD | (IIM_ERR_PRGE << IIM_ERR_SHIFT))
#define POLL_FUSE_SNSD      (IIM_STAT_SNSD | (IIM_ERR_SNSE << IIM_ERR_SHIFT))

static void fuse_op_start(void)
{
    /* Do not generate interrupt */
    writel(0, IIM_BASE_ADDR + IIM_STATM_OFF);
    // clear the status bits and error bits
    writel(0x3, IIM_BASE_ADDR + IIM_STAT_OFF);
    writel(0xFE, IIM_BASE_ADDR + IIM_ERR_OFF);
}

/*
 * The action should be either:
 *          POLL_FUSE_PRGD
 * or:
 *          POLL_FUSE_SNSD
 */
static int poll_fuse_op_done(int action)
{
    uint32_t status, error;

    if (action != POLL_FUSE_PRGD && action != POLL_FUSE_SNSD) {
        printf("%s(%d) invalid operation\n", __FUNCTION__, action);
        return TEST_FAILED;
    }

    /* Poll busy bit till it is NOT set */
    while ((readl(IIM_BASE_ADDR + IIM_STAT_OFF) & IIM_STAT_BUSY) != 0) {
    }

    /* Test for successful write */
    status = readl(IIM_BASE_ADDR + IIM_STAT_OFF);
    error = readl(IIM_BASE_ADDR + IIM_ERR_OFF);

    if ((status & action) != 0 && (error & (action >> IIM_ERR_SHIFT)) == 0) {
        if (error) {
            printf("Even though the operation seems successful...\n");
            printf("There are some error(s) at addr=0x%x: 0x%x\n",
                   (IIM_BASE_ADDR + IIM_ERR_OFF), error);
        }
        return TEST_PASSED;
    }
    printf("%s(%d) failed\n", __FUNCTION__, action);
    printf("status address=0x%x, value=0x%x\n", (IIM_BASE_ADDR + IIM_STAT_OFF), status);
    printf("There are some error(s) at addr=0x%x: 0x%x\n", (IIM_BASE_ADDR + IIM_ERR_OFF), error);
    return TEST_FAILED;
}

unsigned int sense_fuse(int bank, int row)
{
    int addr, addr_l, addr_h, reg_addr;

    fuse_op_start();

    addr = ((bank << 11) | (row << 3));
    /* Set IIM Program Upper Address */
    addr_h = (addr >> 8) & 0x000000FF;
    /* Set IIM Program Lower Address */
    addr_l = (addr & 0x000000FF);

#ifdef IIM_FUSE_DEBUG
    printf("%s: addr_h=0x%x, addr_l=0x%x\n", __FUNCTION__, addr_h, addr_l);
#endif
    writel(addr_h, IIM_BASE_ADDR + IIM_UA_OFF);
    writel(addr_l, IIM_BASE_ADDR + IIM_LA_OFF);
    /* Start sensing */
    writel(0x8, IIM_BASE_ADDR + IIM_FCTL_OFF);
    if (poll_fuse_op_done(POLL_FUSE_SNSD) != 0) {
        printf("%s(bank: %d, row: %d failed\n", __FUNCTION__, bank, row);
    }
    reg_addr = IIM_BASE_ADDR + IIM_SDAT_OFF;
    return readl(reg_addr);
}

static int fuse_blow_bit(int bank, int row, int bit)
{
    int addr, addr_l, addr_h, ret = -1;

    fuse_op_start();

    /* Disable IIM Program Protect */
    writel(0xAA, IIM_BASE_ADDR + IIM_PREG_P_OFF);

    addr = ((bank << 11) | (row << 3) | (bit & 0x7));
    /* Set IIM Program Upper Address */
    addr_h = (addr >> 8) & 0x000000FF;
    /* Set IIM Program Lower Address */
    addr_l = (addr & 0x000000FF);

#ifdef IIM_FUSE_DEBUG
    printf("blowing addr_h=0x%x, addr_l=0x%x\n", addr_h, addr_l);
#endif

    writel(addr_h, IIM_BASE_ADDR + IIM_UA_OFF);
    writel(addr_l, IIM_BASE_ADDR + IIM_LA_OFF);
    /* Start Programming */
    writel(0x31, IIM_BASE_ADDR + IIM_FCTL_OFF);
    if (poll_fuse_op_done(POLL_FUSE_PRGD) == 0) {
        ret = TEST_PASSED;
    }

    /* Enable IIM Program Protect */
    writel(0x0, IIM_BASE_ADDR + IIM_PREG_P_OFF);
    return ret;
}

void fuse_blow_row(int bank, int row, unsigned int value)
{
    unsigned int i;

    for (i = 0; i < 8; i++) {
        if (((value >> i) & 0x1) == 0) {
            continue;
        }
        if (fuse_blow_bit(bank, row, i) != 0) {
            printf("fuse_blow(bank: %d, row: %d, bit: %d failed\n", bank, row, i);
        }
    }
}
