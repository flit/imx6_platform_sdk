/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __ENET_H__
#define __ENET_H__

#define 	NUM_OF_ETH_DEVS	1

/* The defines of event bits */
#define FEC_EVENT_HBERR	0x80000000

#define FEC_EVENT_BABR	0x40000000

#define FEC_EVENT_BABT	0x20000000

#define FEC_EVENT_GRA	0x10000000

#define FEC_EVENT_TXF 	0x08000000

#define FEC_EVENT_TXB	0x04000000

#define FEC_EVENT_RXF	0x02000000

#define FEC_EVENT_RXB	0x01000000

#define FEC_EVENT_MII	0x00800000

#define FEC_EVENT_EBERR	0x00400000

#define FEC_EVENT_LC	0x00200000

#define FEC_EVENT_RL	0x00100000

#define FEC_EVENT_UN	0x00080000

#define FEC_EVENT_TX		FEC_EVENT_TXF

#define FEC_EVENT_TX_ERR	(FEC_EVENT_BABT | FEC_EVENT_LC | FEC_EVENT_RL | FEC_EVENT_UN)

#define FEC_EVENT_RX		FEC_EVENT_RXF

#define FEC_EVENT_ERR		(FEC_EVENT_HBERR | FEC_EVENT_EBERR)

#define FEC_RX_FRAMES		8

#define FEC_FRAME_LEN		(1540+4)

/* the defines to active transmit or receive frame */
#define FEC_RX_TX_ACTIVE	0x01000000

/* the defines of Ethernet Control register */
#define FEC_RESET	0x00000001

#define FEC_ETHER_EN	0x00000002

/* the defins of MII operation */
#define FEC_MII_ST	0x40000000

#define FEC_MII_OP_OFF	28

#define FEC_MII_OP_MASK 0x03

#define FEC_MII_OP_RD	0x02

#define FEC_MII_OP_WR	0x01

#define FEC_MII_PA_OFF	23

#define FEC_MII_PA_MASK 0xFF

#define FEC_MII_RA_OFF	18

#define FEC_MII_RA_MASK	0xFF

#define FEC_MII_TA	0x00020000

#define FEC_MII_DATA_OFF 0

#define FEC_MII_DATA_MASK 0x0000FFFF

#define FEC_MII_FRAME	( FEC_MII_ST | FEC_MII_TA )

#define FEC_MII_OP(x)	( ((x) & FEC_MII_OP_MASK) << FEC_MII_OP_OFF )

#define FEC_MII_PA(pa)  (((pa)& FEC_MII_PA_MASK) << FEC_MII_PA_OFF)

#define FEC_MII_RA(ra)	(((ra)& FEC_MII_RA_MASK) << FEC_MII_RA_OFF)

#define FEC_MII_SET_DATA(v) (((v) & FEC_MII_DATA_MASK) << FEC_MII_DATA_OFF)

#define FEC_MII_GET_DATA(v) (((v) >> FEC_MII_DATA_OFF) & FEC_MII_DATA_MASK )

#define FEC_MII_READ(pa, ra) (	( FEC_MII_FRAME | FEC_MII_OP(FEC_MII_OP_RD) )|\
					FEC_MII_PA(pa) | FEC_MII_RA(ra) )

#define FEC_MII_WRITE(pa, ra, v) ( FEC_MII_FRAME | FEC_MII_OP(FEC_MII_OP_WR)|\
				FEC_MII_PA(pa) | FEC_MII_RA(ra) |FEC_MII_SET_DATA(v) )

#define MII_SPEED_SHIFT	1

#define MII_SPEED_MASK 	0x0000003F

#define MII_SPEED(x)	( (((((x)+499999)/2500000)&(MII_SPEED_MASK))>>1)<<(MII_SPEED_SHIFT) )

/*the defines of MIB control */
#define FEC_MIB_DISABLE	0x80000000

/*the defines of Receive Control*/
#define FEC_RCR_FCE	0x00000020

#define FEC_RCR_BC_REJ	0x00000010

#define FEC_RCR_PROM	0x00000008

#define FEC_RCR_MII_MODE	0x00000004

/*the defines of Transmit Control*/
#define FEC_TCR_RFC_PAUSE	0x00000010

#define FEC_TCR_FDEN		0x00000004

/*the defines of buffer description*/
#define FEC_BD_RX_NUM	8

#define FEC_BD_TX_NUM	2

/* RMII mode */
#define MIIGSK_CFGR_IF_MODE_RMII	(1 << 0)

/* reflects MIIGSK Enable bit (RO) */
#define MIIGSK_ENR_READY		(1 << 2)

/* enable MIGSK (set by default) */
#define MIIGSK_ENR_EN			(1 << 1)

typedef struct mxc_fec_reg_s {
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
    unsigned long ecr;          /*Receive Descriptor Active Register */
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
    unsigned long res11;
    /*0x14c */
    unsigned long frbr;         /*FIFO Receive Bound Register */
    /*0x150 */
    unsigned long frsr;         /*FIFO Receive FIFO Start Registers */
    unsigned long res12[11];
    /*0x180 */
    unsigned long erdsr;        /*Pointer to Receive Descriptor Ring */
    /*0x184 */
    unsigned long etdsr;        /*Pointer to Transmit Descriptor Ring */
    /*0x188 */
    unsigned long emrbr;        /*Maximum Receive Buffer size */
    unsigned long res13[93];
    /*0x300 */
    unsigned short miigsk_cfgr; /* MIIGSK Configuration Register */
    unsigned short res14[3];
    /*0x308 */
    unsigned short miigsk_enr;  /* MIIGSK Enable Register */
} mxc_fec_reg_t;

#define BD_RX_ST_EMPTY 0x8000

#define BD_RX_ST_WRAP  0x2000

#define BD_RX_ST_LAST  0x0800

#define BD_RX_ST_ERRS  0x0037

#define BD_TX_ST_RDY	0x8000

#define BD_TX_ST_WRAP	0x2000

#define BD_TX_ST_LAST  	0x0800

#define BD_TX_ST_TC  	0x0400

#define BD_TX_ST_ABC	0x0200

typedef struct mxc_fec_bd_t {
    unsigned short int length;  /*packet size */
    unsigned short int status;  /*control & statue of this buffer description */
    unsigned char *data;        /*frame buffer address */
} mxc_fec_bd_t;

typedef struct mxc_fec_priv_s {
    mxc_fec_reg_t *hw_reg;      /*the reister base address of FEC */
    unsigned char phy_addr;     /*the address of PHY which associated with FEC controller */
    unsigned char tx_busy;      /*0:free, 1:transmitting frame */
    unsigned char res[2];
    unsigned long status;       /*the status of FEC device:link-status etc. */
    unsigned long tx_key;       /*save the key delivered from send function */
    mxc_fec_bd_t *rx_bd;        /*the receive buffer description ring */
    mxc_fec_bd_t *rx_cur;       /*the next recveive buffer description */
    mxc_fec_bd_t *tx_bd;        /*the transmit buffer description rign */
    mxc_fec_bd_t *tx_cur;       /*the next transmit buffer description */
    /*TODO: Add interrupt about fields */
    /*TODO: Add timer about fields */
} mxc_fec_priv_t;

#define MXC_FEC_PRIVATE(x)	((mxc_fec_priv_t *)(x)->driver_private)

/*The defines of the status field of mxc_fec_priv_t */
#define FEC_STATUS_LINK_ON	0x80000000

#define FEC_STATUS_FULL_DPLX	0x40000000

#define FEC_STATUS_AUTO_NEG	0x20000000

#define FEC_STATUS_100M		0x10000000

/*The defines about PHY */
#ifndef FEC_PHY_ADDR
#define PHY_PORT_ADDR		0x01
#else
#define PHY_PORT_ADDR		FEC_PHY_ADDR
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

#define FEC_COMMON_TICK	2

#define FEC_COMMON_TIMEOUT	(1000*1000)

#define FEC_MII_TICK	2

#define FEC_MII_TIMEOUT	(1000*1000)

void mxc_fec_start(mxc_fec_priv_t * dev, unsigned char *enaddr);
void mxc_fec_stop(mxc_fec_priv_t * dev);
void mxc_fec_phy_init(mxc_fec_priv_t * dev);
int mxc_fec_init(mxc_fec_priv_t * dev, unsigned long reg_base, int phy_addr);
unsigned long mxc_fec_poll(mxc_fec_priv_t * dev);
int mxc_fec_recv(mxc_fec_priv_t * dev, unsigned char *buf, int *length);
int mxc_fec_send(mxc_fec_priv_t * dev, unsigned char *buf, int length, unsigned long key);

#endif //__ENET_H__
