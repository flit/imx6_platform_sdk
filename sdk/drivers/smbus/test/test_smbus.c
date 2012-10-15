/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#include "smbus/smbus.h"
#include "sdk.h"

extern int smbus_prepare_to_arp(void);
extern int smbus_reset_device(uint8_t dev_addr);
extern int smbus_get_udid(uint8_t * dev_addr, smbus_device_udid_t * ptr);
extern int smbus_assign_address(uint8_t * dev_addr, smbus_device_udid_t * ptr);

int smbus_test_enable;
int smbus_test_routine(void)
{
    int ret;
    uint8_t dev_addr;
    smbus_device_udid_t udid;

    if (!smbus_test_enable) {
        return TEST_NOT_PRESENT;
    }

    PROMPT_RUN_TEST("SMB BUS", NULL);

    ret = smbus_prepare_to_arp();
    if (ret)
        goto error_handler;

    ret = smbus_reset_device(SMBUS_DEVICE_DEFAULT_ADDRESS);
    if (ret)
        goto error_handler;

    ret = smbus_get_udid(&dev_addr, &udid);
    if (ret)
        goto error_handler;

    TEST_EXIT("PASSED");
    return TEST_PASSED;

  error_handler:
    TEST_EXIT("FAILED");
    return TEST_FAILED;
}

//RUN_TEST("SMB BUS", smbus_test_routine)
