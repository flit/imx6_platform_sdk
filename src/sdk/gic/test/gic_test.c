/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

//globals used for gic_test
unsigned int gicTestDone;
//unsigned int uartFREE;
extern void startup_imx6x(void);    // entry function, startup routine, defined in startup.s
extern uint32_t getCPUnum(void);

void SGI3_ISR(void)
{
    uint32_t cpu_id;
    cpu_id = getCPUnum();
    //while(1); // debug
    printf("Hello from CPU %d\n", cpu_id);

    if (cpu_id < 4) {
        send_sgi(SW_INTERRUPT_3, (1 << (cpu_id + 1)), 0);   // send to cpu_0 to start sgi loop;
    }

    if (cpu_id == 3) {
        gicTestDone = 0;        // test complete
    }
}

void start_secondary_cpu(uint32_t cpu_num, void functPtr(void))
{
    //printf("start sedondary %d\n", cpu_num);
    //printf("ptr 0x%x\n",(uint32_t)functPtr);                                         
    /* prepare pointers for ROM code */
    writel((uint32_t) & startup_imx6x, SRC_BASE_ADDR + (SRC_GPR1_OFFSET + cpu_num * 8));
    writel((uint32_t) functPtr, SRC_BASE_ADDR + (SRC_GPR2_OFFSET + cpu_num * 8));
    /* start core */
    if (cpu_num > 0) {
        writel((readl(SRC_BASE_ADDR + SRC_SCR_OFFSET) | (1 << (21 + cpu_num))),
               (SRC_BASE_ADDR + SRC_SCR_OFFSET));
    }
}

// only primary cpu will run gic_test
void gic_test(void)
{
    uint32_t cpu_id;

    cpu_id = getCPUnum();

    if (cpu_id == 0) {
        gicTestDone = 1;
        //uartFREE = 1;
        register_interrupt_routine(SW_INTERRUPT_3, SGI3_ISR);   // register sgi isr

        printf("Running the GIC Test \n");
        printf("Starting and sending SGIs to secondary CPUs for \"hello world\" \n\n");

        // start second cpu
        start_secondary_cpu(1, &gic_test);

        while (gicTestDone) ;   //cpu0 wait until test is done, that is until cpu3 completes its SGI.
        //writel((readl(SRC_BASE_ADDR + SRC_SCR_OFFSET) & ~(7 << 22)),
        //       (SRC_BASE_ADDR + SRC_SCR_OFFSET));  // put other cores back into reset with SRC module
        printf("\nEND of GIC Test \n");
    } else {                    //other cpus
        //printf("secondary main cpu: %d\n", cpu_id);

        if (cpu_id == 3) {
            //void send_sgi(unsigned int ID, unsigned int target_list, unsigned int filter_list);
            send_sgi(SW_INTERRUPT_3, 1, 0); // send to cpu_0 to start sgi loop;
        } else {
            start_secondary_cpu(cpu_id + 1, &gic_test);
        }
        while (1) ;             //do nothing wait to be interrupted
    }
}
