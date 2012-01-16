/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_enet Driver and test for the ethernet interface.
 */

/*!
 * @file enet_test.c
 * @brief Test for the ethernet interface through the ENET + PHY.
 *
 * @ingroup diag_enet
 */

#include "hardware.h"
#include "io.h"
#include "enet.h"

static imx_enet_priv_t enet0;
static unsigned char pkt_send[2048], pkt_recv[2048];
static unsigned char mac_addr0[6] = { 0x00, 0x04, 0x9f, 0x00, 0x00, 0x01 };

extern int imx_enet_mii_type(imx_enet_priv_t * dev, enum imx_mii_type mii_type);
extern void imx_enet_iomux(void);
extern void imx_ar8031_iomux(void);
extern void imx_ar8031_reset(void);
static void pkt_fill(unsigned char *packet, unsigned char *eth_addr, unsigned char seed, int length)
{
    unsigned char *pkt = packet;
    unsigned char eth_type[2] = { 0x08, 0x00 };
    int i;
    memset(pkt, 0xff, 6);
    pkt += 6;
    memcpy(pkt, eth_addr, 6);
    pkt += 6;
    memcpy(pkt, eth_type, 2);
    pkt += 2;

    for (i = 0; i < (length - 14); i++)
        *pkt++ = (seed + i) & 0xff;

    return;
}

static int pkt_compare(unsigned char *packet1, unsigned char *packet2, int length)
{
    int i = 0;
    unsigned char *pkt1 = packet1, *pkt2 = packet2;

    for (i = 0; i < length; i++) {
        if (*(pkt1 + i) != *(pkt2 + i))
            break;
    }

    if (i < length)
        return TEST_FAILED;
    else
        return 0;
}


/*!
 * This test performs a loopback transfer on the RGMII interface through
 * an external AR8031 giga ethernet PHY.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
int enet_test(void)
{
    imx_enet_priv_t *dev0 = &enet0;
    int pkt_len_send = 0, pkt_len_recv = 0, ret = 0, i;
    unsigned int enet_events = 0;

    // Enet loopback test
    printf("\nWould you like to run the Ethernet loopback test?\n \
           (Please note that in order to run the test, you need to\n \
           first plug in a loopback cable to the Ethernet port) \n");
    if (!is_input_char('y')) {
        printf("  skip ETHERNET test \n");
        return TEST_BYPASSED;
    }
    //setup iomux for ENET
    imx_ar8031_reset();
    imx_ar8031_iomux();

    //init enet0
    imx_enet_init(dev0, ENET_BASE_ADDR, 0);
    imx_enet_mii_type(dev0, RGMII);
    //init phy0.
    imx_enet_phy_init(dev0);

    //check phy status
    if (!(dev0->status & ENET_STATUS_LINK_ON)) {
        printf("ENET link status check fail\n");
        return TEST_FAILED;
    }

    imx_enet_start(dev0, mac_addr0);

    //send packet
    printf("send packet\n");
    pkt_len_send = 1500;
    pkt_fill(pkt_send, mac_addr0, 0x23, pkt_len_send);
    imx_enet_send(dev0, pkt_send, pkt_len_send, 1);
    enet_events = 0;

    for (i = 0; i < 100; i++) {
        enet_events = imx_enet_poll(dev0);

        if (ENET_EVENT_TX & enet_events) {
            printf("enet_events = %08x\n", enet_events);
            break;
        }

        hal_delay_us(100);
    }

    if (!(ENET_EVENT_TX & enet_events)) {
        printf("ENET tx fail\n");
        return TEST_FAILED;
    }

    if (!(ENET_EVENT_RX & enet_events)) {
        printf("ENET rx fail\n");
        return TEST_FAILED;
    }

    pkt_len_recv = 0;
    imx_enet_recv(dev0, pkt_recv, &pkt_len_recv);

    if (pkt_len_recv != pkt_len_send) {
        printf("ENET rx length check fail \n");
        return TEST_FAILED;
    }

    ret = pkt_compare(pkt_send, pkt_recv, pkt_len_send);

    if (ret != 0) {
        printf("ENET rx packet check fail \n");
        return TEST_FAILED;
    }
#ifdef DEBUG_PRINT
    printf("ENET rx ok\n");
#endif

    printf(" ENET loopback test pass\n");

    imx_enet_stop(dev0);
    return TEST_PASSED;
}
