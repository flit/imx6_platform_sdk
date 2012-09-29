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

#include "obds.h"
#include "hardware.h"
#include "io.h"
//#include "enet.h"

#if defined(BOARD_SMART_DEVICE) || defined(BOARD_SABRE_AI) || (defined(CHIPMX6SL) && defined(BOARD_EVB))
#define ENET_PHY_ADDR 1
#endif

#if (!defined(CHIP_MX6SL) && defined(BOARD_EVB)) || defined(BOARD_SABRE_LITE) /* todo: Need confirm SABRE_LITE ENET_PHY_ADDR */
#define ENET_PHY_ADDR 0
#endif

#ifndef ENET_PHY_ADDR
#error "please define ENET_PHY_ADDR"
#endif

static imx_enet_priv_t enet0;
static unsigned char pkt_send[2048], pkt_recv[2048];
static unsigned char mac_addr0[6] = { 0x00, 0x04, 0x9f, 0x00, 0x00, 0x01 };

extern int imx_enet_mii_type(imx_enet_priv_t * dev, enum imx_mii_type mii_type);

extern void imx_enet_iomux(void);
extern void imx_ar8031_reset(void);
extern void imx_KSZ9021RN_reset(void);

static void pkt_fill(unsigned char *packet, unsigned char *eth_addr, unsigned char seed, int length)
{
    unsigned char *pkt = packet;
    //unsigned char eth_type[2] = { 0x08, 0x00 };
    int i;
    //memset(pkt, 0xff, 6);
    pkt += 6;
    //memcpy(pkt, eth_addr, 6);
    pkt += 6;
    //memcpy(pkt, eth_type, 2);
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
 * This test performs a loopback transfer on the ENET interface through
 * an external ??? ethernet PHY.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
int enet_test_enable;
int enet_test_main(void)
{
    imx_enet_priv_t *dev0 = &enet0;
    int pkt_len_send = 0, pkt_len_recv = 0, ret = 0, i;
    unsigned int enet_events = 0;

    if (!enet_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("ENET ETHERNET", NULL);

    // Enet loopback test
    printf("\nWould you like to run the Ethernet loopback test?\n \
           (Please note that in order to run the test, you need to\n \
           first plug in a loopback cable to the Ethernet port) \n");
    if (!is_input_char('y', NULL)) {
        printf("  skip ETHERNET test \n");
        return TEST_BYPASSED;
    }
    //setup iomux for ENET
    imx_enet_iomux();
    //init enet0
    imx_enet_init(dev0, ENET_BASE_ADDR, 0);
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
    pkt_len_send = 120;
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

/*!
 * This test performs a loopback transfer on the RGMII interface through
 * an external AR8031 giga ethernet PHY.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
int ar8031_test_enable;
int ar8031_test_main(void)
{
    imx_enet_priv_t *dev0 = &enet0;
    int pkt_len_send = 0, pkt_len_recv = 0, ret = 0, i;
    unsigned int enet_events = 0;

    if (!ar8031_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("RGMII AR8031 G-Ethernet", NULL);

    // Enet loopback test
    printf("\nWould you like to run the Ethernet loopback test?\n \
           (Please note that in order to run the test, you need to\n \
           first plug in a loopback cable to the Ethernet port) \n");
    if (!is_input_char('y', NULL)) {
        printf("  skip ETHERNET test \n");
        return TEST_BYPASSED;
    }
    //setup iomux for ENET
    imx_enet_iomux();
    imx_ar8031_reset();

    //init enet0
    imx_enet_init(dev0, ENET_BASE_ADDR, ENET_PHY_ADDR);
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

/*!
 * This test performs a loopback transfer on the RGMII interface through
 * an external KSZ9021RN giga ethernet PHY.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
int KSZ9021RN_test_enable;
int KSZ9021RN_test_main(void)
{
    imx_enet_priv_t *dev0 = &enet0;
    int pkt_len_send = 0, pkt_len_recv = 0, ret = 0, i;
    unsigned int enet_events = 0;

    if (!KSZ9021RN_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("RGMII KSZ9021RN G-Ethernet", NULL);

    // Enet loopback test
    printf("\nWould you like to run the Ethernet loopback test?\n \
           (Please note that in order to run the test, you need to\n \
           first plug in a loopback cable to the Ethernet port) \n");
    if (!is_input_char('y', NULL)) {
        printf("  skip ETHERNET test \n");
        return TEST_BYPASSED;
    }
    //setup iomux for ENET
    imx_KSZ9021RN_reset();
    imx_enet_iomux();

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

//RUN_TEST_INTERACTIVE("ETHERNET", enet_test_main);
//RUN_TEST_INTERACTIVE("RGMII AR8031 G-Ethernet", ar8031_test_main);
//RUN_TEST_INTERACTIVE("RGMII KSZ9021RN G-Ethernet", KSZ9021RN_test_main);
