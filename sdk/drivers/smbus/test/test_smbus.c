/*
 * Copyright (c) 2010-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
