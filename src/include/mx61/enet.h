/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __ENET_H__
#define __ENET_H__

#define 	NUM_OF_ETH_DEVS	1

/* The defines of event bits */
#define ENET_EVENT_HBERR	0x80000000

#define ENET_EVENT_BABR	0x40000000

#define ENET_EVENT_BABT	0x20000000

#define ENET_EVENT_GRA	0x10000000

#define ENET_EVENT_TXF 	0x08000000

#define ENET_EVENT_TXB	0x04000000

#define ENET_EVENT_RXF	0x02000000

#define ENET_EVENT_RXB	0x01000000

#define ENET_EVENT_MII	0x00800000

#define ENET_EVENT_EBERR	0x00400000

#define ENET_EVENT_LC	0x00200000

#define ENET_EVENT_RL	0x00100000

#define ENET_EVENT_UN	0x00080000

#define ENET_EVENT_TX		ENET_EVENT_TXF

#define ENET_EVENT_TX_ERR	(ENET_EVENT_BABT | ENET_EVENT_LC | ENET_EVENT_RL | ENET_EVENT_UN)

#define ENET_EVENT_RX		ENET_EVENT_RXF

#define ENET_EVENT_ERR		(ENET_EVENT_HBERR | ENET_EVENT_EBERR)

#define ENET_RX_FRAMES		8

#define ENET_FRAME_LEN		(1540+4)

/* the defines to active transmit or receive frame */
#define ENET_RX_TX_ACTIVE	0x01000000

/* the defines of Ethernet Control register */
#define ENET_RESET	0x00000001

#define ENET_ETHER_EN	0x00000002
#define ENET_ETHER_SPEED_1000M (1<<5)
#define ENET_ETHER_LITTLE_ENDIAN (1<<8)
/* the defins of MII operation */
#define ENET_MII_ST	0x40000000

#define ENET_MII_OP_OFF	28

#define ENET_MII_OP_MASK 0x03

#define ENET_MII_OP_RD	0x02

#define ENET_MII_OP_WR	0x01

#define ENET_MII_PA_OFF	23

#define ENET_MII_PA_MASK 0xFF

#define ENET_MII_RA_OFF	18

#define ENET_MII_RA_MASK	0xFF

#define ENET_MII_TA	0x00020000

#define ENET_MII_DATA_OFF 0

#define ENET_MII_DATA_MASK 0x0000FFFF

#define ENET_MII_FRAME	( ENET_MII_ST | ENET_MII_TA )

#define ENET_MII_OP(x)	( ((x) & ENET_MII_OP_MASK) << ENET_MII_OP_OFF )

#define ENET_MII_PA(pa)  (((pa)& ENET_MII_PA_MASK) << ENET_MII_PA_OFF)

#define ENET_MII_RA(ra)	(((ra)& ENET_MII_RA_MASK) << ENET_MII_RA_OFF)

#define ENET_MII_SET_DATA(v) (((v) & ENET_MII_DATA_MASK) << ENET_MII_DATA_OFF)

#define ENET_MII_GET_DATA(v) (((v) >> ENET_MII_DATA_OFF) & ENET_MII_DATA_MASK )

#define ENET_MII_READ(pa, ra) (	( ENET_MII_FRAME | ENET_MII_OP(ENET_MII_OP_RD) )|\
					ENET_MII_PA(pa) | ENET_MII_RA(ra) )

#define ENET_MII_WRITE(pa, ra, v) ( ENET_MII_FRAME | ENET_MII_OP(ENET_MII_OP_WR)|\
				ENET_MII_PA(pa) | ENET_MII_RA(ra) |ENET_MII_SET_DATA(v) )

#define MII_SPEED_SHIFT	1

#define MII_SPEED_MASK 	0x0000003F

#define MII_SPEED(x)	( (((((x)+499999)/2500000)&(MII_SPEED_MASK))>>1)<<(MII_SPEED_SHIFT) )

/*the defines of MIB control */
#define ENET_MIB_DISABLE	0x80000000

/*the defines of Receive Control*/
#define ENET_RCR_FCE	0x00000020

#define ENET_RCR_BC_REJ	0x00000010

#define ENET_RCR_PROM	0x00000008

#define ENET_RCR_MII_MODE	(1<<2)
#define ENET_RCR_RGMII_EN       (1<<6)  /*RGMII enable/disable */
#define ENET_RCR_RMII_MODE      (1<<8)  /*RMII mode:1->10M, 0->100M */

/*the defines of Transmit Control*/
#define ENET_TCR_RFC_PAUSE	0x00000010

#define ENET_TCR_FDEN		0x00000004

/*the defines of buffer description*/
#define ENET_BD_RX_NUM	8

#define ENET_BD_TX_NUM	2

enum imx_mii_type {
    MII,
    RMII,
    RGMII,
};

typedef struct imx_enet_reg_s {
    unsigned long res1;
    /*0x004 */
    unsigned long eir;          /* Interrupt Event Register */
    /*0x008 */
    unsigned long eimr;         /* Interrupt Mask Register */
    unsigned long res2;
    /*0x010 */
    unsigned long rdar;         /* Receive Descriptor Active Register */
    /*0x014 */
    unsigned long tdar;         /* Transmit Descriptor Active Register */
    unsigned long res3[3];
    /*0x024 */
    unsigned long ecr;          /*Ethernet Control Register */
    unsigned long res4[6];
    /*0x040 */
    unsigned long mmfr;         /*MII Management Frame Register */
    /*0x044 */
    unsigned long mscr;         /*MII Speed Control Register */
    unsigned long res5[7];
    /*0x064 */
    unsigned long mibc;         /*MII Control/Status Register */
    unsigned long res6[7];
    /*0x084 */
    unsigned long rcr;          /*Receive Control Register */
    unsigned long res7[15];
    /*0x0C4 */
    unsigned long tcr;          /*Transmit Control register */
    unsigned long res8[7];
    /*0x0E4 */
    unsigned long palr;         /*Physical Address Low Register */
    /*0x0E8 */
    unsigned long paur;         /*Physical Address High+Type Register */
    /*0x0EC */
    unsigned long opd;          /*Opcode+Pause Duration */
    unsigned long res9[10];
    /*0x118 */
    unsigned long iaur;         /*Upper 32bits Individual Hash Table */
    /*0x11c */
    unsigned long ialr;         /*lower 32bits Individual Hash Table */
    /*0x120 */
    unsigned long gaur;         /*Upper 32bits Group Hash Table */
    /*0x124 */
    unsigned long galr;         /*lower 32bits Group Hash Table */
    unsigned long res10[7];
    /*0x144 */
    unsigned long tfwr;         /*Trasmit FIFO Watermark */
    unsigned long res11[14];
    /*0x180 */
    unsigned long rdsr;         /*Pointer to Receive Descriptor Ring */
    /*0x184 */
    unsigned long tdsr;         /*Pointer to Transmit Descriptor Ring */
    /*0x188 */
    unsigned long mrbr;         /*Maximum Receive Buffer size */
    unsigned long res12;
    /*0x190 */
    unsigned long rsfl;         /*Receive FIFO Section Full Threshold */
    /*0x194 */
    unsigned long rsem;         /*Receive FIFO Section Empty Threshold */
    /*0x198 */
    unsigned long raem;         /*Receive FIFO Almost Empty Threshold */
    /*0x19C */
    unsigned long rafl;         /*Receive FIFO Almost Full Threshold */
    /*0x1A0 */
    unsigned long tsem;         /*Transmit FIFO Section Empty Threshold */
    /*0x1A4 */
    unsigned long taem;         /*Transmit FIFO Almost Empty Threshold */
    /*0x1A8 */
    unsigned long tafl;         /*Transmit FIFO Almost Full Threshold */
    /*0x1AC */
    unsigned long tipg;         /*Transmit Inter-Packet Gap */
    /*0x1B0 */
    unsigned long ftrl;         /*Frame Truncation length */
    unsigned long res13[3];
    /*0x1C0 */
    unsigned long tacc;         /*Transmit Accelerator Function config */
    /*0x1C4 */
    unsigned long racc;         /*Receive Accelerator Function config */
    unsigned short res14[142];
    /*0x400 */
    unsigned short atcr;        /* Timer Control Register */
    /*0x404 */
    unsigned short atvr;        /* Timer Value Register */
    /*0x408 */
    unsigned short atoff;       /* Timer Offset Register */
    /*0x40C */
    unsigned short atper;       /* Timer Period Register */
    /*0x410 */
    unsigned short atcor;       /* Timer Correction Register */
    /*0x414 */
    unsigned short atinc;       /* Time-Stamping Clock Period Register */
    /*0x418 */
    unsigned short atstmp;      /* Timestamp of Last Transmitted Frame */
    unsigned short res15[122];
    /*0x604 */
    unsigned short tgsr;        /* Timer Global Status Register */
    /*0x608 */
    unsigned short tcsr0;       /* Timer Control Status Register 0 */
    /*0x60C */
    unsigned short tccr0;       /* Timer Compare Capture Register 0 */
    /*0x610 */
    unsigned short tcsr1;       /* Timer Control Status Register 1 */
    /*0x614 */
    unsigned short tccr1;       /* Timer Compare Capture Register 1 */
    /*0x618 */
    unsigned short tcsr2;       /* Timer Control Status Register 2 */
    /*0x61C */
    unsigned short tccr2;       /* Timer Compare Capture Register 2 */
    /*0x620 */
    unsigned short tcsr3;       /* Timer Control Status Register 3 */
    /*0x624 */
    unsigned short tccr3;       /* Timer Compare Capture Register 3 */
} imx_enet_reg_t;

#define BD_RX_ST_EMPTY 0x8000

#define BD_RX_ST_WRAP  0x2000

#define BD_RX_ST_LAST  0x0800

#define BD_RX_ST_ERRS  0x0037

#define BD_TX_ST_RDY	0x8000

#define BD_TX_ST_WRAP	0x2000

#define BD_TX_ST_LAST  	0x0800

#define BD_TX_ST_TC  	0x0400

#define BD_TX_ST_ABC	0x0200

typedef struct imx_enet_bd_t {
    unsigned short int length;  /*packet size */
    unsigned short int status;  /*control & statue of this buffer description */
    unsigned char *data;        /*frame buffer address */
} imx_enet_bd_t;

typedef struct imx_enet_priv_s {
    imx_enet_reg_t *hw_reg;     /*the reister base address of ENET */
    unsigned char phy_addr;     /*the address of PHY which associated with ENET controller */
    unsigned char tx_busy;      /*0:free, 1:transmitting frame */
    unsigned char res[2];
    unsigned long status;       /*the status of ENET device:link-status etc. */
    unsigned long tx_key;       /*save the key delivered from send function */
    imx_enet_bd_t *rx_bd;       /*the receive buffer description ring */
    imx_enet_bd_t *rx_cur;      /*the next recveive buffer description */
    imx_enet_bd_t *tx_bd;       /*the transmit buffer description rign */
    imx_enet_bd_t *tx_cur;      /*the next transmit buffer description */
    /*TODO: Add interrupt about fields */
    /*TODO: Add timer about fields */
} imx_enet_priv_t;

#define MXC_ENET_PRIVATE(x)	((imx_enet_priv_t *)(x)->driver_private)

/*The defines of the status field of imx_enet_priv_t */
#define ENET_STATUS_LINK_ON	0x80000000

#define ENET_STATUS_FULL_DPLX	0x40000000

#define ENET_STATUS_AUTO_NEG	0x20000000
#define ENET_STATUS_10M		0x8000000
#define ENET_STATUS_100M		0x10000000
#define ENET_STATUS_1000M		0x20000000
/*The defines about PHY */
#ifndef ENET_PHY_ADDR
#define PHY_PORT_ADDR		0x01
#else
#define PHY_PORT_ADDR		ENET_PHY_ADDR
#endif

#define PHY_CTRL_REG		0x00

#define PHY_CTRL_RESET		0x8000

#define PHY_CTRL_AUTO_NEG	0x1000

#define PHY_CTRL_FULL_DPLX	0x0100

#define PHY_STATUS_REG		0x01

#define PHY_STATUS_LINK_ST	0x0004

#define PHY_IDENTIFY_1		0x02

#define PHY_IDENTIFY_2		0x03

#define PHY_ID1_SHIFT		16

#define PHY_ID1_MASK		0xFFFF

#define PHY_ID2_SHIFT		0

#define PHY_ID2_MASK		0xFFFF

#define PHY_MODE_NUM		0x03F0

#define PHY_REV_NUM		0x000F

#define PHY_DIAG_REG		0x12

#define PHY_DIAG_DPLX		0x0800

#define PHY_DIAG_RATE		0x0400

#define PHY_MODE_REG		0x15

#define PHY_LED_SEL			0x200

#define PHY_AUTO_NEG_REG	0x5

#define PHY_AUTO_10BASET	0x20

#define PHY_AUTO_10BASET_DPLX		0x40

#define PHY_AUTO_100BASET	0x80

#define PHY_AUTO_100BASET_DPLX	0x100

#define PHY_AUTO_NEG_EXP_REG	0x6

#define PHY_AUTO_NEG_NEW_PAGE	0x2

#define PHY_AUTO_NEG_CAP		0x1

#define PHY_INT_SRC_REG	29

#define PHY_INT_AUTO_NEG	0x40

#define ENET_COMMON_TICK	2

#define ENET_COMMON_TIMEOUT	(1000*1000)

#define ENET_MII_TICK	2

#define ENET_MII_TIMEOUT	(1000*1000)

void imx_enet_start(imx_enet_priv_t * dev, unsigned char *enaddr);
void imx_enet_stop(imx_enet_priv_t * dev);
void imx_enet_phy_init(imx_enet_priv_t * dev);
int imx_enet_init(imx_enet_priv_t * dev, unsigned long reg_base, int phy_addr);
unsigned long imx_enet_poll(imx_enet_priv_t * dev);
int imx_enet_recv(imx_enet_priv_t * dev, unsigned char *buf, int *length);
int imx_enet_send(imx_enet_priv_t * dev, unsigned char *buf, int length, unsigned long key);

#endif //__ENET_H__
