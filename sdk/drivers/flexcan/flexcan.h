/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __CAN_H__
#define __CAN_H__

#include "hardware.h"
#include "registers/regsflexcan.h"

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


// definitions for the bits/field in the C/S Message Buffer Structure
#define  CAN_CS_RTR           0x00100000
#define  CAN_CS_IDE           0x00200000
#define  CAN_CS_SRR           0x00400000

/* CAN message buffer structure */
struct can_mb {
    volatile uint32_t cs;       // 0x0
    volatile uint32_t id;       // 0x4
    volatile uint32_t data0;    // 0x8
    volatile uint32_t data1;    // 0xc
};

#define CAN_MB_OFFSET 0x80
// CAN Message Buffers   0x80 - 0x170
struct can_message_buffers {
    volatile struct can_mb MB[64];
};

/* CAN timing related structures */
struct time_segment {
	uint32_t propseg;
	uint32_t pseg1;
	uint32_t pseg2;
};

enum can_bitrate {
      MBPS_1,
      KBPS_800,
      KBPS_500,
      KBPS_250,
      KBPS_125,
      KBPS_62,  //62.5kps
      KBPS_20,
      KBPS_10
};

/* CAN structure with attributes */
struct imx_flexcan {
    hw_module_t *port;

    // attributes
    uint32_t presdiv;
    enum can_bitrate bitrate;  //default 500kbps
    struct time_segment ts;
};

/* CAN driver list of functions */
void can_sw_reset(struct hw_module *port);
void can_init(struct hw_module *port, uint32_t max_mb);
void set_can_mb(struct hw_module *port, uint32_t mbID, uint32_t cs, uint32_t id, uint32_t data0,
                uint32_t data1);
void print_can_mb(struct hw_module *port, uint32_t mbID);
void can_enable_mb_interrupt(struct hw_module *port, uint32_t mbID);
void can_disable_mb_interrupt(struct hw_module *port, uint32_t mbID);
void can_exit_freeze(struct hw_module *port);
void can_freeze(struct hw_module *port);

void can_update_bitrate(struct imx_flexcan *can_module);
void can_set_can_attributes(struct imx_flexcan *can_module, uint32_t bitrate, struct hw_module *hw_port);

#endif //__CAN_H__
