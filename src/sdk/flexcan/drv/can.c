/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "can.h"

void can_init(struct hw_module *port, uint32_t max_mb)
{
    volatile struct mx_can_control *can_ctl = (volatile struct mx_can_control *)port->base;
    uint32_t ctl;
    int i;

    /* configure the I/O for the port */
    can_iomux_config(port->base);

    ctl = can_ctl->mcr;
    ctl &= 0xFFFFFF00;          //clear MAXMB field
    ctl |= (max_mb & 0x3F);     // set MAXMB field (0-63)
    can_ctl->mcr = ctl;
    can_ctl->mcr &= 0x7fffffff; // enable the module

    // Programming the bit timing segments"
    can_ctl->ctrl1 = (CAN_TIMING_PARAMETERS << 16);

    // initialize MBs to zero
    for (i = 0; i < CAN_NUMBER_OF_BUFFERS; i++) {
        set_can_mb(port, i, 0, 0, 0, 0);
    }

    // disable all MB interrupts
    can_ctl->imask1 = 0;
    can_ctl->imask2 = 0;
}

void set_can_mb(struct hw_module *port, uint32_t mbID, uint32_t cs, uint32_t id, uint32_t data0,
                uint32_t data1)
{
    volatile struct can_message_buffers *can_mb =
        (volatile struct can_message_buffers *)(port->base + CAN_MB_OFFSET);

    can_mb->MB[mbID].cs = cs;
    can_mb->MB[mbID].id = id;
    can_mb->MB[mbID].data0 = data0;
    can_mb->MB[mbID].data1 = data1;
}

void print_can_mb(struct hw_module *port, uint32_t mbID)
{
    volatile struct can_message_buffers *can_mb =
        (volatile struct can_message_buffers *)(port->base + CAN_MB_OFFSET);
    printf("\tMB[%d].cs    = 0x%x\n", mbID, can_mb->MB[mbID].cs);
    printf("\tMB[%d].id    = 0x%x\n", mbID, can_mb->MB[mbID].id);
    printf("\tMB[%d].data0 = 0x%x\n", mbID, can_mb->MB[mbID].data0);
    printf("\tMB[%d].data1 = 0x%x\n", mbID, can_mb->MB[mbID].data1);
}

void can_enable_mb_interrupt(struct hw_module *port, uint32_t mbID)
{
    volatile struct mx_can_control *can_ctl = (volatile struct mx_can_control *)port->base;

    if (mbID < 32) {
        can_ctl->imask1 |= (1 << mbID);
    } else if (mbID < 64) {
        can_ctl->imask2 |= (1 << (mbID - 32));
    }
}

void can_disable_mb_interrupt(struct hw_module *port, uint32_t mbID)
{
    volatile struct mx_can_control *can_ctl = (volatile struct mx_can_control *)port->base;

    if (mbID < 32) {
        can_ctl->imask1 &= ~(1 << mbID);
    } else if (mbID < 64) {
        can_ctl->imask2 &= ~(1 << (mbID - 32));
    }
}

void can_exit_freeze(struct hw_module *port)
{
    volatile struct mx_can_control *can_ctl = (volatile struct mx_can_control *)port->base;

    can_ctl->mcr &= ~(1 << 28);
}

void can_freeze(struct hw_module *port)
{
    volatile struct mx_can_control *can_ctl = (volatile struct mx_can_control *)port->base;

    can_ctl->mcr |= (1 << 28);
}
