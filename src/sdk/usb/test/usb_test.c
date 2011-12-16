/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file usb_test.c
 * @brief USB test.
 *
 * @ingroup diag_usb
 */

#include "hardware.h"

extern void usb0_host_test (void);

void usb_test (void)
{
    /* only the host 0 test is available for now, more in next release */
    usb0_host_test();
}
