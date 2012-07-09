/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "registers/regssrc.h"

//globals used for gic_test
unsigned int gicTestDone;

extern void startup_imx6x(void);    // entry function, startup routine, defined in startup.s
extern uint32_t getCPUnum(void);

#ifdef CHIP_MX6DQ
#	define CPU_NUMBER	4
#else
#	ifdef CHIP_MX6SDL
#		define CPU_NUMBER	2
#	else
#		define CPU_NUMBER	1
#	endif
#endif

void SGI3_ISR(void)
{
    uint32_t cpu_id;
    cpu_id = getCPUnum();
    //while(1); // debug
    printf("Hello from CPU %d\n", cpu_id);

    if (cpu_id < (CPU_NUMBER - 1)) {
        gic_send_sgi(SW_INTERRUPT_3, (1 << (cpu_id + 1)), 0);   // send to next core to start sgi loop;
    }

    if (cpu_id == (CPU_NUMBER - 1)) {
        gicTestDone = 0;        // test complete
    }
}

void start_secondary_cpu(uint32_t cpu_num, void functPtr(void))
{
    //printf("start sedondary %d\n", cpu_num);
    //printf("ptr 0x%x\n",(uint32_t)functPtr); 

    // Prepare pointers for ROM code.
//     writel((uint32_t) & startup_imx6x, SRC_BASE_ADDR + (SRC_GPR1_OFFSET + cpu_num * 8));
//     writel((uint32_t) functPtr, SRC_BASE_ADDR + (SRC_GPR2_OFFSET + cpu_num * 8));

    switch (cpu_num) {
    case 1:
        HW_SRC_GPR3_WR((uint32_t) & startup_imx6x);
        HW_SRC_GPR4_WR((uint32_t) functPtr);

        HW_SRC_SCR.B.CORE1_ENABLE = 1;
        break;

    case 2:
        HW_SRC_GPR5_WR((uint32_t) & startup_imx6x);
        HW_SRC_GPR6_WR((uint32_t) functPtr);

        HW_SRC_SCR.B.CORE2_ENABLE = 1;
        break;

    case 3:
        HW_SRC_GPR7_WR((uint32_t) & startup_imx6x);
        HW_SRC_GPR8_WR((uint32_t) functPtr);

        HW_SRC_SCR.B.CORE3_ENABLE = 1;
        break;
    }

    // Start secondary core.
//     if (cpu_num > 0) {
// //         writel((readl(SRC_BASE_ADDR + SRC_SCR_OFFSET) | (1 << (21 + cpu_num))),
// //                (SRC_BASE_ADDR + SRC_SCR_OFFSET));
//             
//         HW_SRC_SCR_SET(BM_SRC_SCR_CORE1_ENABLE << (cpu_num - 1));
//     }
}

//! This test first starts the secondary CPUs in order from 1 through 3. When each secondary
//! CPU starts, it executes this function. The first thing this function does for secondary CPUs
//! is to enable interrupts for the CPU in the GIC.
//!
//! When the last CPU enters this function, it will start a loop of sending software interrupts
//! to all cores in sequence by sending the first SGI to core 0. As each core handles the SGI,
//! it will print a message and send an SGI to the next CPU in sequence.
void gic_multicore_test(void)
{
    uint32_t cpu_id;

    cpu_id = getCPUnum();

    if (cpu_id != 0) {
        // Enable interrupts on secondary CPUs.
        gic_set_cpu_priority_mask(0xff);
        gic_cpu_enable(true);
    }

    if (cpu_id == 0) {
        gicTestDone = 1;

        register_interrupt_routine(SW_INTERRUPT_3, SGI3_ISR);   // register sgi isr

        printf("Running the GIC Multicore Test \n");
        printf("Starting and sending SGIs to secondary CPUs for \"hello world\" \n\n");

        // start second cpu
        start_secondary_cpu(1, &gic_multicore_test);

        while (gicTestDone) ;   //cpu0 wait until test is done, that is until cpu3 completes its SGI.
        //writel((readl(SRC_BASE_ADDR + SRC_SCR_OFFSET) & ~(7 << 22)),
        //       (SRC_BASE_ADDR + SRC_SCR_OFFSET));  // put other cores back into reset with SRC module
        printf("\nEND of GIC Test \n");
    } else {                    //other cpus
        printf("secondary main cpu: %d\n", cpu_id);

        if (cpu_id == (CPU_NUMBER - 1)) {
            //void send_sgi(unsigned int ID, unsigned int target_list, unsigned int filter_list);
            gic_send_sgi(SW_INTERRUPT_3, 1, 0); // send to cpu_0 to start sgi loop;
        } else {
            start_secondary_cpu(cpu_id + 1, &gic_multicore_test);
        }
        while (1) ;             //do nothing wait to be interrupted
    }
}

void gic_sgi_test_handler(void)
{
    printf("In gic_sgi_test_handler()\n");

    gicTestDone = 0;            // test complete
}

void gic_sgi_test(void)
{
    printf("Starting GIC SGI test\n");

    // register and enable sgi isr
    register_interrupt_routine(SW_INTERRUPT_3, gic_sgi_test_handler);
    enable_interrupt(SW_INTERRUPT_3, CPU_0, 0);

    gicTestDone = 1;

    printf("Sending SGI\n");
    gic_send_sgi(SW_INTERRUPT_3, 1, 0);

    printf("Waiting\n");
    while (gicTestDone) ;

    printf("SGI was handled\n");
}
