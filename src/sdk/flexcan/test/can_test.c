/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "flexcan/flexcan.h"

void can2_rx_handler(void);

/* CAN module data structures */
static struct hw_module can1_port = {
    "CAN1",          // int8_t* name; // name
    CAN1_BASE_ADDR,  // uint32_t base; // base_address
    30000000,        // uint32_t freq; // frequency CAN_CLK_ROOT aka can_PE_clock
    IMX_INT_FLEXCAN1,    // uint32_t irq_id; // interrut source ID
    // void (*irq_subroutine)(void); // IRQ subroutine
    // void (*iomux_config) (void); // module iomux configuration fucntion
};

static struct hw_module can2_port = {
    "CAN2",           // int8_t* name; // name
    CAN2_BASE_ADDR,   // uint32_t base; // base_address
    30000000,         // uint32_t freq; // frequency CAN_CLK_ROOT aka can_PE_clock
    IMX_INT_FLEXCAN2,     // uint32_t irq_id; // interrut source ID
    &can2_rx_handler, // void (*irq_subroutine)(void); // IRQ subroutine
    // void (*iomux_config) (void); // module iomux configuration fucntion
};

uint32_t can_test_count;

/*! ------------------------------------------------------------
 * CAN Test (loopback can1/can2 ports)
 *  ------------------------------------------------------------
 */
void flexcan_test(void)
{
    int i;
    //struct imx_flexcan can1, can2;    

    //can_set_can_attributes(&can1, KBPS_500, &can1_port);
    //can_set_can_attributes(&can2, KBPS_500, &can2_port);
    //can_update_bitrate(&can1);
    //can_update_bitrate(&can2);

    printf("\n---- Running CAN1/2 loopback test ----\n");
    can_test_count = 0;

    can_init(&can1_port, CAN_LAST_MB);  // max 64 MB 0-63
    can_init(&can2_port, CAN_LAST_MB);  // last mb is MB[63]

    printf("CAN1-TX and CAN2-RX\n");
    // configure CAN1 MBs as Tx, and CAN2 MBs as Rx
    // set-up 8 MBs for the test
    for (i = 1; i < 9; i++) {
        set_can_mb(&can1_port, i, 0x0c000000 + (i << 16), 0x0a000000 + (i << 20), 0x12345678,
                   0x87654321);
        set_can_mb(&can2_port, i, 0x04000000 + (i << 16), 0x0a000000 + (i << 20), 0, 0);
        can_enable_mb_interrupt(&can2_port, i); // enable MB interrupt for idMB=i
    }

    //enable CAN2 interrupt
    register_interrupt_routine(can2_port.irq_id, can2_port.irq_subroutine);
    enable_interrupt(can2_port.irq_id, CPU_0, 0);   // to cpu0, max priority (0)

    // init CAN1 MB0
    can_exit_freeze(&can2_port);    // Rx
    can_exit_freeze(&can1_port);    // Tx

    while (!(can_test_count)) ;

    can_freeze(&can2_port);     // Rx
    can_freeze(&can1_port);     // Tx

    printf("%d MBs were transmitted \n", can_test_count);
    printf("---- CAN1/2 test complete ----\n");
}

/*!
 * Can2 receive ISR function
 */
void can2_rx_handler(void)
{
    int i = 0;
    volatile struct mx_can_control *can_ctl = (volatile struct mx_can_control *)can2_port.base;
//    volatile struct can_message_buffers *can_mb = (volatile struct can_message_buffers *)(can2_port.base + CAN_MB_OFFSET);

    if (can_ctl->iflag1 != 0) {
        for (i = 0; i < 32; i++) {
            if (can_ctl->iflag1 & (1 << i)) {
                can_ctl->iflag1 = (1 << i); //clear interrupt flag
                printf("\tCAN2 MB:%d Recieved:\n", i);
                print_can_mb(&can2_port, i);
                can_test_count++;

            }
        }
    } else if (can_ctl->iflag2 != 0) {
        for (i = 0; i < 32; i++) {
            if (can_ctl->iflag2 & (1 << i)) {
                can_ctl->iflag1 = (1 << i); //clear interrupt flag
                printf("\tCAN2 MB:%d Recieved:\n", i + 32);
                print_can_mb(&can2_port, i + 32);
                can_test_count++;
            }
        }
    }
}
