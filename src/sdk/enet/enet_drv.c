/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file enet_drv.c
 * @brief Driver of the i.MX ENET controller.
 *
 * @ingroup diag_enet
 */

#include "hardware.h"
#include "enet.h"

/*!
 *Global variable which defines the buffer descriptions for receiving frame
 * 	comment:: it must aligned by 128-bits.
 */
static imx_enet_bd_t imx_enet_rx_bd[ENET_BD_RX_NUM * NUM_OF_ETH_DEVS] __attribute__ ((aligned(32)));

/*!
 *Global variable which defines the buffer descriptions for receiving frame
 * 	comment:: it must aligned by 128-bits.
 */
static imx_enet_bd_t imx_enet_tx_bd[ENET_BD_TX_NUM * NUM_OF_ETH_DEVS] __attribute__ ((aligned(32)));

/*!
 * Global variable which contains the frame buffers ,
 */
static unsigned char imx_enet_rx_buf[ENET_BD_RX_NUM * NUM_OF_ETH_DEVS][2048]
    __attribute__ ((aligned(32)));

/*!
 * Global variable which contains the frame buffers ,
 */
static unsigned char imx_enet_tx_buf[ENET_BD_TX_NUM * NUM_OF_ETH_DEVS][2048]
    __attribute__ ((aligned(32)));

/*!
 * This function gets the value of the PHY registers through the MII interface.
 */
int imx_enet_mii_read(volatile imx_enet_reg_t * hw_reg, unsigned char phy_addr,
                      unsigned char reg_addr, unsigned short int *value)
{
    unsigned long waiting = ENET_MII_TIMEOUT;

    if (hw_reg->eir & ENET_EVENT_MII) {
        hw_reg->eir = ENET_EVENT_MII;
    }

    hw_reg->mmfr = ENET_MII_READ(phy_addr, reg_addr);   /*Write CMD */

    while (1) {
        if (hw_reg->eir & ENET_EVENT_MII) {
            hw_reg->eir = ENET_EVENT_MII;
            break;
        }
        if ((--waiting) == 0)
            return -1;

        hal_delay_us(ENET_MII_TICK);
    }

    *value = ENET_MII_GET_DATA(hw_reg->mmfr);
    return 0;
}

/*!
 * This function sets the value of the PHY registers through the MII interface.
 */
int imx_enet_mii_write(volatile imx_enet_reg_t * hw_reg, unsigned char phy_addr,
                       unsigned char reg_addr, unsigned short int value)
{
    unsigned long waiting = ENET_MII_TIMEOUT;

    if (hw_reg->eir & ENET_EVENT_MII) {
        hw_reg->eir = ENET_EVENT_MII;
    }

    hw_reg->mmfr = ENET_MII_WRITE(phy_addr, reg_addr, value);   /* Write CMD */

    while (1) {
        if (hw_reg->eir & ENET_EVENT_MII) {
            hw_reg->eir = ENET_EVENT_MII;
            break;
        }

        if ((--waiting) == 0)
            return -1;

        hal_delay_us(ENET_MII_TICK);
    }

    return 0;
}

/*!
 * The function initializes the description buffer for receiving or transmitting.
 */
static void imx_enet_bd_init(imx_enet_priv_t * dev, int dev_idx)
{
    int i;
    imx_enet_bd_t *p;
    imx_enet_bd_t *rx_bd_base = imx_enet_rx_bd, *tx_bd_base = imx_enet_tx_bd;

    rx_bd_base += (dev_idx * ENET_BD_RX_NUM);
    tx_bd_base += (dev_idx * ENET_BD_TX_NUM);

    p = dev->rx_bd = (imx_enet_bd_t *) rx_bd_base;

    for (i = 0; i < ENET_BD_RX_NUM; i++, p++) {
        p->status = BD_RX_ST_EMPTY;
        p->length = 0;
        p->data = (unsigned char *)imx_enet_rx_buf[i + dev_idx * ENET_BD_RX_NUM];
        printf("rx bd %x, buffer is %x\n", (unsigned int)p, (unsigned int)p->data);
    }

    dev->rx_bd[i - 1].status |= BD_RX_ST_WRAP;
    dev->rx_cur = dev->rx_bd;

    p = dev->tx_bd = (imx_enet_bd_t *) tx_bd_base;

    for (i = 0; i < ENET_BD_TX_NUM; i++, p++) {
        p->status = 0;
        p->length = 0;
        p->data = (unsigned char *)imx_enet_tx_buf[i + dev_idx * ENET_BD_TX_NUM];
        printf("tx bd %x, buffer is %x\n", (unsigned int)p, (unsigned int)p->data);
    }

    dev->tx_bd[i - 1].status |= BD_TX_ST_WRAP;
    dev->tx_cur = dev->tx_bd;

    /*TODO:: add the sync function for items */
}

/*!
 * This function initializes the ENET controller.
 */
static void imx_enet_chip_init(imx_enet_priv_t * dev)
{
    volatile imx_enet_reg_t *chip = (imx_enet_reg_t *) dev->hw_reg;

    chip->ecr = ENET_RESET;

    while (chip->ecr & ENET_RESET) {
        hal_delay_us(ENET_COMMON_TICK);
    }

    chip->eimr = 0x00000000;
    chip->eir = 0xFFFFFFFF;

    /*
     * setup the MII gasket for RMII mode
     */
    chip->rcr = (chip->rcr & ~(0x0000003F)) | ENET_RCR_RGMII_EN | ENET_RCR_FCE | ENET_RCR_PROM;
    chip->tcr |= ENET_TCR_FDEN;
    chip->mibc |= ENET_MIB_DISABLE;

    chip->iaur = 0;
    chip->ialr = 0;
    chip->gaur = 0;
    chip->galr = 0;

    /*TODO:: Use MII_SPEED(IPG_CLK) to get the value */
    chip->mscr = (chip->mscr & (~0x7e)) | (1 << 8) | (40 << 1);

    /*Enable ETHER_EN */
    chip->mrbr = 2048 - 16;
    chip->rdsr = (unsigned long)dev->rx_bd;
    chip->tdsr = (unsigned long)dev->tx_bd;
}

void imx_enet_phy_clock_output_125M(imx_enet_priv_t * dev)
{
    unsigned short val = 0;
    int i;
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1d, 0x1F);
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0x1e, &val);
    printf("debug before 0x1F val = 0x%x\n", val);
    val |= 0x4;
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1e, val);
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0x1e, &val);
    printf("debug after 0x1F val = 0x%x\n", val);

    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0xd, 0x7);
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0xe, 0x8016);
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0xd, 0x4007);
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0xe, &val);
    printf("debug read from 0x8016 val = 0x%x\n", val);
    val &= 0xffe3;
    val |= 0x18;
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0xe, val);
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0xe, &val);
    printf("debug after read from 0x8016 val = 0x%x\n", val);
    for (i = 0; i < 100000; i++) ;

    //debug register 0x5[8]=1'b1 - suggest add 2ns GTX_CLK delay
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1d, 0x5);
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0x1e, &val);
    val |= 0x0100;
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1e, val);

    // Config to external loopback
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1d, 0xb);
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0x1e, &val);
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1e, 0x3c40);

    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1d, 0x11);
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0x1e, &val);
    val |= 0x0001;
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1e, val);

    // PHY AR8031 Integrated 10/100/1000 Gigabit
    // Reset & full duplex
    // Use default speed - after Pwer on reset - 1000Mbs
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0, 0x8140);
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0, &val);
    while (val == 0x8140)
        imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0, &val);

}

/*!
 * This function initializes the PHY connected to the ENET controller.
 */
void imx_enet_phy_init(imx_enet_priv_t * dev)
{
    unsigned short value = 0;
    unsigned long id = 0, timeout = 50;
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, PHY_IDENTIFY_1, &value);
    id = (value & PHY_ID1_MASK) << PHY_ID1_SHIFT;
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, PHY_IDENTIFY_2, &value);
    id |= (value & PHY_ID2_MASK) << PHY_ID2_SHIFT;

    switch (id & 0xfffffff0) {
    case 0x00540088:
        break;
    case 0x0007c0c0:
        printf("ENET LAN8700 PHY: ID=%lx\n", id);
        break;
    case 0x0007c0f0:
        printf("ENET LAN8720 PHY: ID=%lx\n", id);
        break;
    case 0x004dd070:
        printf("ENET AR8031 PHY: ID=%lx\n", id);
        break;
    case 0x00221610:
        printf("ENET KSZ9021RN PHY: ID=%lx\n", id);
        break;
    default:
        printf("[Warning] ENET not connect right PHY: ID=%lx\n", id);
    }

    value = 0x8100;
    imx_enet_mii_write(dev->hw_reg, dev->phy_addr, 0x1f, value);
    imx_enet_phy_clock_output_125M(dev);
    for (id = 0x0; id <= 0x1f; id++) {
        imx_enet_mii_read(dev->hw_reg, dev->phy_addr, id, &value);
        printf("ENET phy reg %lx is %x\n", id, value);
    }

    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, PHY_STATUS_REG, &value);
    printf("ENET phy status %x\n", value);
    timeout = 5;

    while ((0 == (value & PHY_STATUS_LINK_ST)) && (timeout > 0)) {
        hal_delay_us(500000);
        imx_enet_mii_read(dev->hw_reg, dev->phy_addr, PHY_STATUS_REG, &value);
        printf("enet phy status %0d: %04x\n", dev->phy_addr, value);    //  0x7809 or 0x782d
        timeout--;
    }
    if (value & PHY_STATUS_LINK_ST) {
        dev->status |= ENET_STATUS_LINK_ON;
    } else {
        dev->status &= ~ENET_STATUS_LINK_ON;
    }
    for (id = 0x0; id <= 0x1f; id++) {
        imx_enet_mii_read(dev->hw_reg, dev->phy_addr, id, &value);
        printf("ENET phy reg %lx is %x\n", id, value);
    }
    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, 0x1b, &value);
    if (value & (1 << 2))
        dev->status |= ENET_STATUS_FULL_DPLX;
    else
        dev->status &= ~ENET_STATUS_FULL_DPLX;

    if (value & 0x2)
        dev->status |= ENET_STATUS_1000M;
    else if (value & 0x1)
        dev->status |= ENET_STATUS_100M;
    else
        dev->status |= ENET_STATUS_10M;

/*    imx_enet_mii_read(dev->hw_reg, dev->phy_addr, PHY_AUTO_NEG_REG, &value);
    printf("enet phy reg 0x5 is %x\n",value);
    if (value & PHY_AUTO_10BASET) {
        dev->status &= ~ENET_STATUS_100M;

        if (value & PHY_AUTO_10BASET_DPLX) {
            dev->status |= ENET_STATUS_FULL_DPLX;
        } else {
            dev->status &= ~ENET_STATUS_FULL_DPLX;
        }
    }

    if (value & PHY_AUTO_100BASET) {
        dev->status |= ENET_STATUS_100M;

        if (value & PHY_AUTO_100BASET_DPLX) {
            dev->status |= ENET_STATUS_FULL_DPLX;
        } else {
            dev->status &= ~ENET_STATUS_FULL_DPLX;
        }
    }
*/
    printf("ENET %0d: [ %s ] [ %s ] [ %s ]:\n", dev->phy_addr,
           (dev->status & ENET_STATUS_FULL_DPLX) ? "FULL_DUPLEX" : "HALF_DUPLEX",
           (dev->status & ENET_STATUS_LINK_ON) ? "connected" : "disconnected",
           (dev->status & ENET_STATUS_1000M) ? "1000M bps" : (dev->status & ENET_STATUS_100M) ?
           "100M bps" : "10M bps");
    return;
}

unsigned long imx_enet_poll(imx_enet_priv_t * dev)
{
    volatile imx_enet_reg_t *hw_reg = dev->hw_reg;
    unsigned int value = 0;

    value = hw_reg->eir;
    hw_reg->eir = value & (~ENET_EVENT_MII);

    if (value & ENET_EVENT_TX_ERR) {
        printf("WARNING[POLL]: There are error(%x) for transmit\n", value & ENET_EVENT_TX_ERR);
        dev->tx_busy = 0;
    } else {
        if (value & ENET_EVENT_TX) {
            dev->tx_busy = 0;
        }
    }

    if (value & ENET_EVENT_RX) {
        //imx_enet_check_rx_bd(sc);
    }

    if (value & ENET_EVENT_HBERR) {
        printf("WARNGING[POLL]: Hearbeat error!\n");
    }

    if (value & ENET_EVENT_EBERR) {
        printf("WARNING[POLL]: Ethernet Bus Error!\n");
    }

    return value;
}

int imx_enet_send(imx_enet_priv_t * dev, unsigned char *buf, int length, unsigned long key)
{
    volatile imx_enet_reg_t *hw_reg = dev->hw_reg;
    imx_enet_bd_t *p = dev->tx_cur;

    memcpy(p->data, buf, length);

    p->length = length;
    p->status &= ~(BD_TX_ST_LAST | BD_TX_ST_RDY | BD_TX_ST_TC | BD_TX_ST_ABC);
    p->status |= BD_TX_ST_LAST | BD_TX_ST_RDY | BD_TX_ST_TC;

    if (p->status & BD_TX_ST_WRAP) {
        p = dev->tx_bd;
    } else
        p++;

    dev->tx_cur = p;
    dev->tx_busy = 1;
    dev->tx_key = key;
    hw_reg->tdar = ENET_RX_TX_ACTIVE;

    return 0;
}

int imx_enet_recv(imx_enet_priv_t * dev, unsigned char *buf, int *length)
{
    imx_enet_bd_t *p = dev->rx_cur;
    volatile imx_enet_reg_t *hw_reg = dev->hw_reg;

    if (p->status & BD_RX_ST_EMPTY) {
        return -1;
    }

    if (!(p->status & BD_RX_ST_LAST)) {
        printf("BUG[RX]: status=%x, length=%x\n", p->status, p->length);
        return -1;
    }

    if ((p->status & BD_RX_ST_ERRS) || (p->length > ENET_FRAME_LEN)) {
        printf("BUG1[RX]: status=%x, length=%x\n", p->status, p->length);
    } else {
        memcpy(buf, p->data, p->length - 4);
        *length = p->length - 4;
    }

    p->status = (p->status & BD_RX_ST_WRAP) | BD_RX_ST_EMPTY;

    if (p->status & BD_RX_ST_WRAP) {
        p = dev->rx_bd;
    } else {
        p++;
    }

    dev->rx_cur = p;
    hw_reg->ecr |= ENET_ETHER_EN;
    hw_reg->rdar |= ENET_RX_TX_ACTIVE;

    return 0;
}

int imx_enet_init(imx_enet_priv_t * dev, unsigned long reg_base, int phy_addr)
{
    dev->hw_reg = (imx_enet_reg_t *) reg_base;
    dev->tx_busy = 0;
    dev->status = 0;
    dev->phy_addr = phy_addr;   /* 0 or 1 */

    imx_enet_bd_init(dev, phy_addr);

    imx_enet_chip_init(dev);

    //imx_enet_phy_init(dev);

    return 0;
}

static void imx_enet_set_mac_address(volatile imx_enet_reg_t * hw_reg, unsigned char *enaddr)
{
    unsigned long value;

    value = enaddr[0];
    value = (value << 8) + enaddr[1];
    value = (value << 8) + enaddr[2];
    value = (value << 8) + enaddr[3];
    hw_reg->palr = value;

    value = enaddr[4];
    value = (value << 8) + enaddr[5];
    hw_reg->paur = (value << 16);
}

void imx_enet_start(imx_enet_priv_t * dev, unsigned char *enaddr)
{
    imx_enet_set_mac_address(dev->hw_reg, enaddr);

    dev->tx_busy = 0;
    dev->hw_reg->ecr |= ENET_ETHER_EN | ENET_ETHER_SPEED_1000M | ENET_ETHER_LITTLE_ENDIAN;
    dev->hw_reg->rdar |= ENET_RX_TX_ACTIVE;
}

void imx_enet_stop(imx_enet_priv_t * dev)
{
    dev->hw_reg->ecr &= ~ENET_ETHER_EN;
}

int imx_enet_isolate_phy(imx_enet_priv_t * dev)
{
    unsigned short value = 0;

    if (!imx_enet_mii_read(dev->hw_reg, dev->phy_addr, PHY_CTRL_REG, &value)) {
        value |= (0x01 << 10);
        if (!imx_enet_mii_write(dev->hw_reg, dev->phy_addr, PHY_CTRL_REG, value)) {
            return 0;
        }
    }
    return -1;
}

int imx_enet_unisolate_phy(imx_enet_priv_t * dev)
{
    unsigned short value = 0;

    if (!imx_enet_mii_read(dev->hw_reg, dev->phy_addr, PHY_CTRL_REG, &value)) {
        value &= ~(0x01 << 10);
        if (!imx_enet_mii_write(dev->hw_reg, dev->phy_addr, PHY_CTRL_REG, value)) {
            imx_enet_mii_read(dev->hw_reg, dev->phy_addr, PHY_CTRL_REG, &value);
            return 0;
        }
    }
    return -1;
}

int imx_enet_mii_type(imx_enet_priv_t * dev, enum imx_mii_type mii_type)
{
    volatile imx_enet_reg_t *hw_reg = dev->hw_reg;

    switch (mii_type) {
    case MII:
        /*clear RMII and RGMII */
        hw_reg->rcr &= ~(ENET_RCR_RMII_MODE | ENET_RCR_RGMII_EN);
        hw_reg->rcr |= ENET_RCR_MII_MODE;
        break;
    case RMII:
        hw_reg->rcr &= ~(ENET_RCR_RGMII_EN);
        hw_reg->rcr |= (ENET_RCR_MII_MODE | ENET_RCR_RMII_MODE);
        break;
    case RGMII:
        hw_reg->rcr &= ~(ENET_RCR_RMII_MODE | ENET_RCR_MII_MODE);
        hw_reg->rcr |= ENET_RCR_RGMII_EN;
        hw_reg->tfwr = 0x3f;    //for mx6dq
        break;
    default:
        printf("BUG:unknow MII type=%x\n", mii_type);
        break;
    }
    return 0;
}
