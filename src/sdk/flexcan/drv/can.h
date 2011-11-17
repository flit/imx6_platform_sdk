/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __CAN_H__
#define __CAN_H__

#include "io.h"

/* CAN driver general defines */
#define CAN_NUMBER_OF_BUFFERS 64    // Define the number of MB
#define CAN_LAST_MB 63
// define CAN TIMING PARAMETERS PRESDIV=8, PROP_SEG=0, PSEG1=PSEG2=2, RJW=2
#define CAN_TIMING_PARAMETERS 0x0892
//#define CAN_TIMING_PARAMETERS 0x02db  // define CAN TIMING PARAMETERS PRESDIV=2, PROP_SEG=0, PSEG1=PSEG2=3, RJW=3
#define CAN_CS_8BYTES 0x0c680000    // define C&S of MBs to transmit 8 bytes of DATA
#define GPIO_MSG_GRP0           0

// CAN register reset values
#define CAN_MCR_RSTVAL      0x5980000f
#define CAN_CTRL1_RSTVAL     0x0
#define CAN_TIMER_RSTVAL    0x0
#define CAN_TCR_RSTVAL      0x0
#define CAN_RXGMASK_RSTVAL  0xffffffff
#define CAN_RX14MASK_RSTVAL 0xffffffff
#define CAN_RX15MASK_RSTVAL 0xffffffff
#define CAN_ECR_RSTVAL    0x0
#define CAN_ESR1_RSTVAL    0x0
#define CAN_IMASK2_RSTVAL   0x0
#define CAN_IMASK1_RSTVAL   0x0
#define CAN_IFLAG2_RSTVAL   0x0
#define CAN_IFLAG1_RSTVAL   0x0
#define CAN_CTRL2_RSTVAL      0x00800000
#define CAN_ESR2_RSTVAL       0x0
#define CAN_FUREQ_RSTVAL      0x0
#define CAN_FUACK_RSTVAL      0x0
#define CAN_CRCR_RSTVAL       0x0
#define CAN_RXFGMASK_RSTVAL   0xffffffff
#define CAN_RXFIR_RSTVAL      0x0

/****************************************************************************/
/*  Bit level definitions and macros                                        */
/****************************************************************************/
// definitions for the bits in the MCR register
#define  CAN_MDIS_BIT         0x80000000;
#define  CAN_FRZ_BIT          0x40000000;
#define  CAN_FEN_BIT          0x20000000;
#define  CAN_HALT_BIT         0x10000000;
#define  CAN_NOT_RDY_BIT      0x08000000;
#define  CAN_WAK_MSK_BIT      0x04000000;
#define  CAN_SOFT_RST_BIT     0x02000000;
#define  CAN_FRZ_ACK_BIT      0x01000000;
#define  CAN_SUPV_BIT         0x00800000;
#define  CAN_SLF_WAK_BIT      0x00400000;
#define  CAN_WARN_EN_BIT      0x00200000;
#define  CAN_LPM_ACK_BIT      0x00100000;
#define  CAN_WAK_SRC_BIT      0x00080000;
#define  CAN_DOZE_BIT         0x00040000;
#define  CAN_SRX_DIS_BIT      0x00020000;
#define  CAN_BCC_BIT          0x00010000;
#define  CAN_PEN_BIT          0x00002000;
#define  CAN_AEN_BIT          0x00001000;
#define  CAN_IDAM0_BIT        0x00000100;
#define  CAN_IDAM1_BIT        0x00000200;

// definitions for the bits in the CTRL register
#define  CAN_BOFF_MSK_BIT     0x00008000
#define  CAN_ERR_MSK_BIT      0x00004000
#define  CAN_CLK_SRC_BIT      0x00002000
#define  CAN_LPB_BIT          0x00001000
#define  CAN_SMP_BIT          0x00000080
#define  CAN_BOFF_REC_BIT     0x00000040
#define  CAN_TSYN_BIT         0x00000020
#define  CAN_LBUF_BIT         0x00000010
#define  CAN_LOM_BIT          0x00000008

// definitions for the bits in the TCR register
#define  CAN_TRD_BIT          0x00000400
#define  CAN_BITCLS_BIT       0x00000200
#define  CAN_DSCACK_BIT       0x00000100

// definitions for the bits in the RX masks registers
#define  CAN_MI0_BIT          0x00000001
#define  CAN_MI1_BIT          0x00000002
#define  CAN_MI2_BIT          0x00000004
#define  CAN_MI3_BIT          0x00000008
#define  CAN_MI4_BIT          0x00000010
#define  CAN_MI5_BIT          0x00000020
#define  CAN_MI6_BIT          0x00000040
#define  CAN_MI7_BIT          0x00000080
#define  CAN_MI8_BIT          0x00000100
#define  CAN_MI9_BIT          0x00000200
#define  CAN_MI10_BIT         0x00000400
#define  CAN_MI11_BIT         0x00000800
#define  CAN_MI12_BIT         0x00001000
#define  CAN_MI13_BIT         0x00002000
#define  CAN_MI14_BIT         0x00004000
#define  CAN_MI15_BIT         0x00008000
#define  CAN_MI16_BIT         0x00010000
#define  CAN_MI17_BIT         0x00020000
#define  CAN_MI18_BIT         0x00040000
#define  CAN_MI19_BIT         0x00080000
#define  CAN_MI20_BIT         0x00100000
#define  CAN_MI21_BIT         0x00200000
#define  CAN_MI22_BIT         0x00400000
#define  CAN_MI23_BIT         0x00800000
#define  CAN_MI24_BIT         0x01000000
#define  CAN_MI25_BIT         0x02000000
#define  CAN_MI26_BIT         0x04000000
#define  CAN_MI27_BIT         0x08000000
#define  CAN_MI28_BIT         0x10000000
#define  CAN_MI29_BIT         0x10000000
#define  CAN_MI30_BIT         0x10000000
#define  CAN_MI31_BIT         0x10000000

// definitions for the bits/field in the ESR registers
#define  CAN_BIT1_ERR_BIT     0x00008000
#define  CAN_BIT0_ERR_BIT     0x00004000
#define  CAN_ACK_ERR_BIT      0x00002000
#define  CAN_CRC_ERR_BIT      0x00001000
#define  CAN_FRM_ERR_BIT      0x00000800
#define  CAN_STF_ERR_BIT      0x00000400
#define  CAN_TX_WRN_BIT       0x00000200
#define  CAN_RX_WRN_BIT       0x00000100
#define  CAN_IDLE_BIT         0x00000080
#define  CAN_TXRX_BIT         0x00000040
#define  CAN_FLT_CONF_FIELD   0x00000030
#define  CAN_BOFF_INT_BIT     0x00000004
#define  CAN_ERR_INT_BIT      0x00000002
#define  CAN_WAK_INT_BIT      0x00000001

// definitions for the bits/field in the C/S Message Buffer Structure
#define  CAN_CS_RTR           0x00100000
#define  CAN_CS_IDE           0x00200000
#define  CAN_CS_SRR           0x00400000

// definitions for the bits in the IMASK registers
#define  CAN_BUF0M_BIT        0x00000001
#define  CAN_BUF1M_BIT        0x00000002
#define  CAN_BUF2M_BIT        0x00000004
#define  CAN_BUF3M_BIT        0x00000008
#define  CAN_BUF4M_BIT        0x00000010
#define  CAN_BUF5M_BIT        0x00000020
#define  CAN_BUF6M_BIT        0x00000040
#define  CAN_BUF7M_BIT        0x00000080
#define  CAN_BUF8M_BIT        0x00000100
#define  CAN_BUF9M_BIT        0x00000200
#define  CAN_BUF10M_BIT       0x00000400
#define  CAN_BUF11M_BIT       0x00000800
#define  CAN_BUF12M_BIT       0x00001000
#define  CAN_BUF13M_BIT       0x00002000
#define  CAN_BUF14M_BIT       0x00004000
#define  CAN_BUF15M_BIT       0x00008000
#define  CAN_BUF16M_BIT       0x00010000
#define  CAN_BUF17M_BIT       0x00020000
#define  CAN_BUF18M_BIT       0x00040000
#define  CAN_BUF19M_BIT       0x00080000
#define  CAN_BUF20M_BIT       0x00100000
#define  CAN_BUF21M_BIT       0x00200000
#define  CAN_BUF22M_BIT       0x00400000
#define  CAN_BUF23M_BIT       0x00800000
#define  CAN_BUF24M_BIT       0x01000000
#define  CAN_BUF25M_BIT       0x02000000
#define  CAN_BUF26M_BIT       0x04000000
#define  CAN_BUF27M_BIT       0x08000000
#define  CAN_BUF28M_BIT       0x10000000
#define  CAN_BUF29M_BIT       0x20000000
#define  CAN_BUF30M_BIT       0x40000000
#define  CAN_BUF31M_BIT       0x80000000

#define  CAN_BUF32M_BIT       0x00000001
#define  CAN_BUF33M_BIT       0x00000002
#define  CAN_BUF34M_BIT       0x00000004
#define  CAN_BUF35M_BIT       0x00000008
#define  CAN_BUF36M_BIT       0x00000010
#define  CAN_BUF37M_BIT       0x00000020
#define  CAN_BUF38M_BIT       0x00000040
#define  CAN_BUF39M_BIT       0x00000080
#define  CAN_BUF40M_BIT       0x00000100
#define  CAN_BUF41M_BIT       0x00000200
#define  CAN_BUF42M_BIT       0x00000400
#define  CAN_BUF43M_BIT       0x00000800
#define  CAN_BUF44M_BIT       0x00001000
#define  CAN_BUF45M_BIT       0x00002000
#define  CAN_BUF46M_BIT       0x00004000
#define  CAN_BUF47M_BIT       0x00008000
#define  CAN_BUF48M_BIT       0x00010000
#define  CAN_BUF49M_BIT       0x00020000
#define  CAN_BUF50M_BIT       0x00040000
#define  CAN_BUF51M_BIT       0x00080000
#define  CAN_BUF52M_BIT       0x00100000
#define  CAN_BUF53M_BIT       0x00200000
#define  CAN_BUF54M_BIT       0x00400000
#define  CAN_BUF55M_BIT       0x00800000
#define  CAN_BUF56M_BIT       0x01000000
#define  CAN_BUF57M_BIT       0x02000000
#define  CAN_BUF58M_BIT       0x04000000
#define  CAN_BUF59M_BIT       0x08000000
#define  CAN_BUF60M_BIT       0x10000000
#define  CAN_BUF61M_BIT       0x20000000
#define  CAN_BUF62M_BIT       0x40000000
#define  CAN_BUF63M_BIT       0x80000000

// definitions for the bits in the IFLAG registers
#define  CAN_BUF0I_BIT        0x00000001
#define  CAN_BUF1I_BIT        0x00000002
#define  CAN_BUF2I_BIT        0x00000004
#define  CAN_BUF3I_BIT        0x00000008
#define  CAN_BUF4I_BIT        0x00000010
#define  CAN_BUF5I_BIT        0x00000020
#define  CAN_BUF6I_BIT        0x00000040
#define  CAN_BUF7I_BIT        0x00000080
#define  CAN_BUF8I_BIT        0x00000100
#define  CAN_BUF9I_BIT        0x00000200
#define  CAN_BUF10I_BIT       0x00000400
#define  CAN_BUF11I_BIT       0x00000800
#define  CAN_BUF12I_BIT       0x00001000
#define  CAN_BUF13I_BIT       0x00002000
#define  CAN_BUF14I_BIT       0x00004000
#define  CAN_BUF15I_BIT       0x00008000
#define  CAN_BUF16I_BIT       0x00010000
#define  CAN_BUF17I_BIT       0x00020000
#define  CAN_BUF18I_BIT       0x00040000
#define  CAN_BUF19I_BIT       0x00080000
#define  CAN_BUF20I_BIT       0x00100000
#define  CAN_BUF21I_BIT       0x00200000
#define  CAN_BUF22I_BIT       0x00400000
#define  CAN_BUF23I_BIT       0x00800000
#define  CAN_BUF24I_BIT       0x01000000
#define  CAN_BUF25I_BIT       0x02000000
#define  CAN_BUF26I_BIT       0x04000000
#define  CAN_BUF27I_BIT       0x08000000
#define  CAN_BUF28I_BIT       0x10000000
#define  CAN_BUF29I_BIT       0x20000000
#define  CAN_BUF30I_BIT       0x40000000
#define  CAN_BUF31I_BIT       0x80000000

#define  CAN_BUF32I_BIT       0x00000001
#define  CAN_BUF33I_BIT       0x00000002
#define  CAN_BUF34I_BIT       0x00000004
#define  CAN_BUF35I_BIT       0x00000008
#define  CAN_BUF36I_BIT       0x00000010
#define  CAN_BUF37I_BIT       0x00000020
#define  CAN_BUF38I_BIT       0x00000040
#define  CAN_BUF39I_BIT       0x00000080
#define  CAN_BUF40I_BIT       0x00000100
#define  CAN_BUF41I_BIT       0x00000200
#define  CAN_BUF42I_BIT       0x00000400
#define  CAN_BUF43I_BIT       0x00000800
#define  CAN_BUF44I_BIT       0x00001000
#define  CAN_BUF45I_BIT       0x00002000
#define  CAN_BUF46I_BIT       0x00004000
#define  CAN_BUF47I_BIT       0x00008000
#define  CAN_BUF48I_BIT       0x00010000
#define  CAN_BUF49I_BIT       0x00020000
#define  CAN_BUF50I_BIT       0x00040000
#define  CAN_BUF51I_BIT       0x00080000
#define  CAN_BUF52I_BIT       0x00100000
#define  CAN_BUF53I_BIT       0x00200000
#define  CAN_BUF54I_BIT       0x00400000
#define  CAN_BUF55I_BIT       0x00800000
#define  CAN_BUF56I_BIT       0x01000000
#define  CAN_BUF57I_BIT       0x02000000
#define  CAN_BUF58I_BIT       0x04000000
#define  CAN_BUF59I_BIT       0x08000000
#define  CAN_BUF60I_BIT       0x10000000
#define  CAN_BUF61I_BIT       0x20000000
#define  CAN_BUF62I_BIT       0x40000000
#define  CAN_BUF63I_BIT       0x80000000

/* CAN message buffer structure */
struct can_mb {
    volatile uint32_t cs;       // 0x0
    volatile uint32_t id;       // 0x4
    volatile uint32_t data0;    // 0x8
    volatile uint32_t data1;    // 0xc
};

/* CAN Registers list */
struct mx_can_control {
    volatile uint32_t mcr;      // 0x0
    volatile uint32_t ctrl1;    // 0x4
    volatile uint32_t timer;    // 0x8
    volatile uint32_t reserved1;    // 0xc
    volatile uint32_t rxmgmask; // 0x10
    volatile uint32_t rx14mask; // 0x14
    volatile uint32_t rx15mask; // 0x18
    volatile uint32_t ecr;      // 0x1c
    volatile uint32_t esr1;     // 0x20
    volatile uint32_t imask2;   // 0x24
    volatile uint32_t imask1;   // 0x28
    volatile uint32_t iflag2;   // 0x2c
    volatile uint32_t iflag1;   // 0x30
    volatile uint32_t ctrl2;    // 0x34
    volatile uint32_t esr2;     // 0x38
    volatile uint32_t reserved2;    // 0x3c
    volatile uint32_t reserved3;    // 0x40
    volatile uint32_t crcr;     // 0x44
    volatile uint32_t rxfgmask; // 0x48
    volatile uint32_t rxfir;    // 0x4c 
};

#define CAN_MB_OFFSET 0x80
// CAN Message Buffers   0x80 - 0x170
struct can_message_buffers {
    volatile struct can_mb MB[64];
/*    volatile struct can_mb MB0;
    volatile struct can_mb MB1;
    volatile struct can_mb MB2;
    volatile struct can_mb MB3;
    volatile struct can_mb MB4;
    volatile struct can_mb MB5;
    volatile struct can_mb MB6;
    volatile struct can_mb MB7;
    volatile struct can_mb MB8;
    volatile struct can_mb MB9;
    volatile struct can_mb MB10;
    volatile struct can_mb MB11;
    volatile struct can_mb MB12;
    volatile struct can_mb MB13;
    volatile struct can_mb MB14;
    volatile struct can_mb MB15;
    volatile struct can_mb MB16;
    volatile struct can_mb MB17;
    volatile struct can_mb MB18;
    volatile struct can_mb MB19;
    volatile struct can_mb MB20;
    volatile struct can_mb MB21;
    volatile struct can_mb MB22;
    volatile struct can_mb MB23;
    volatile struct can_mb MB24;
    volatile struct can_mb MB25;
    volatile struct can_mb MB26;
    volatile struct can_mb MB27;
    volatile struct can_mb MB28;
    volatile struct can_mb MB29;
    volatile struct can_mb MB30;
    volatile struct can_mb MB31;
    volatile struct can_mb MB32;
    volatile struct can_mb MB33;
    volatile struct can_mb MB34;
    volatile struct can_mb MB35;
    volatile struct can_mb MB36;
    volatile struct can_mb MB37;
    volatile struct can_mb MB38;
    volatile struct can_mb MB39;
    volatile struct can_mb MB40;
    volatile struct can_mb MB41;
    volatile struct can_mb MB42;
    volatile struct can_mb MB43;
    volatile struct can_mb MB44;
    volatile struct can_mb MB45;
    volatile struct can_mb MB46;
    volatile struct can_mb MB47;
    volatile struct can_mb MB48;
    volatile struct can_mb MB49;
    volatile struct can_mb MB50;
    volatile struct can_mb MB51;
    volatile struct can_mb MB52;
    volatile struct can_mb MB53;
    volatile struct can_mb MB54;
    volatile struct can_mb MB55;
    volatile struct can_mb MB56;
    volatile struct can_mb MB57;
    volatile struct can_mb MB58;
    volatile struct can_mb MB59;
    volatile struct can_mb MB60;
    volatile struct can_mb MB61;
    volatile struct can_mb MB62;
    volatile struct can_mb MB63;  */
};

#define CAN_RXIMR_OFFSET 0x880
// CAN RX Individual Mask Registers   0x880 - 0x97c
struct can_rx_masks {
    volatile uint32_t rximr[64];    // 0x880-0x97c
/*    volatile uint32_t rximr0;          // 0x880
    volatile uint32_t rximr1;          // 0x884
    volatile uint32_t rximr2;          // 0x888
    volatile uint32_t rximr3;          // 0x88c
    volatile uint32_t rximr4;          // 0x890
    volatile uint32_t rximr5;          // 0x894
    volatile uint32_t rximr6;          // 0x898
    volatile uint32_t rximr7;          // 0x89c
    volatile uint32_t rximr8;          // 0x8a0
    volatile uint32_t rximr9;          // 0x8a4
    volatile uint32_t rximr10;         // 0x8a8
    volatile uint32_t rximr11;         // 0x8ac
    volatile uint32_t rximr12;         // 0x8b0
    volatile uint32_t rximr13;         // 0x8b4
    volatile uint32_t rximr14;         // 0x8b8
    volatile uint32_t rximr15;         // 0x8bc
    volatile uint32_t rximr16;         // 0x8c0
    volatile uint32_t rximr17;         // 0x8c4
    volatile uint32_t rximr18;         // 0x8c8
    volatile uint32_t rximr19;         // 0x8cc
    volatile uint32_t rximr20;         // 0x8d0
    volatile uint32_t rximr21;         // 0x8d4
    volatile uint32_t rximr22;         // 0x8d8
    volatile uint32_t rximr23;         // 0x8dc
    volatile uint32_t rximr24;         // 0x8e0
    volatile uint32_t rximr25;         // 0x8e4
    volatile uint32_t rximr26;         // 0x8e8
    volatile uint32_t rximr27;         // 0x8ec
    volatile uint32_t rximr28;         // 0x8f0
    volatile uint32_t rximr29;         // 0x8f4
    volatile uint32_t rximr30;         // 0x8f8
    volatile uint32_t rximr31;         // 0x8fc
    volatile uint32_t rximr32;         // 0x900
    volatile uint32_t rximr33;         // 0x904
    volatile uint32_t rximr34;         // 0x908
    volatile uint32_t rximr35;         // 0x90c
    volatile uint32_t rximr36;         // 0x910
    volatile uint32_t rximr37;         // 0x914
    volatile uint32_t rximr38;         // 0x918
    volatile uint32_t rximr39;         // 0x91c
    volatile uint32_t rximr40;         // 0x920
    volatile uint32_t rximr41;         // 0x924
    volatile uint32_t rximr42;         // 0x928
    volatile uint32_t rximr43;         // 0x92c
    volatile uint32_t rximr44;         // 0x930
    volatile uint32_t rximr45;         // 0x934
    volatile uint32_t rximr46;         // 0x938
    volatile uint32_t rximr47;         // 0x93c
    volatile uint32_t rximr48;         // 0x940
    volatile uint32_t rximr49;         // 0x944
    volatile uint32_t rximr50;         // 0x948
    volatile uint32_t rximr51;         // 0x94c
    volatile uint32_t rximr52;         // 0x950
    volatile uint32_t rximr53;         // 0x954
    volatile uint32_t rximr54;         // 0x958
    volatile uint32_t rximr55;         // 0x95c
    volatile uint32_t rximr56;         // 0x960
    volatile uint32_t rximr57;         // 0x964
    volatile uint32_t rximr58;         // 0x968
    volatile uint32_t rximr59;         // 0x96c
    volatile uint32_t rximr60;         // 0x970
    volatile uint32_t rximr61;         // 0x974
    volatile uint32_t rximr62;         // 0x978
    volatile uint32_t rximr63;         // 0x97c
*/
};

#define CAN_GFWR_OFFSET 0x9e0
// CAN Glitch Filter Width Registers   0x09e0
struct can_gfw {
    volatile uint32_t gfwr;     // 09e0
};

/* CAN driver list of functions */
void can_init(struct hw_module *port, uint32_t max_mb);
void set_can_mb(struct hw_module *port, uint32_t mbID, uint32_t cs, uint32_t id, uint32_t data0,
                uint32_t data1);
void print_can_mb(struct hw_module *port, uint32_t mbID);
void can_enable_mb_interrupt(struct hw_module *port, uint32_t mbID);
void can_disable_mb_interrupt(struct hw_module *port, uint32_t mbID);
void can_exit_freeze(struct hw_module *port);
void can_freeze(struct hw_module *port);

#endif //__CAN_H__
