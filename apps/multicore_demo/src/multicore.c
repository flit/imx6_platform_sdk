/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"
#include "platform_init.h"
#include "irq_numbers.h"
#include "registers/regssrc.h"
#include "cpu_utility/cpu_utility.h"
#include "core/cortex_a9.h"
#include "gic/gic.h"
#include "core/interrupt.h"
#include "utility/system_util.h"

////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

extern void startup_imx6x(void);    // entry function, startup routine, defined in startup.s

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

unsigned int isTestDone;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void SGI3_ISR(void)
{
    uint32_t cpu_id = cpu_get_current();
    int cpuCount = cpu_get_cores();
    
    //while(1); // debug
    
    printf("Hello from CPU %d\n", cpu_id);

    if (cpu_id < (cpuCount - 1))
    {
        gic_send_sgi(SW_INTERRUPT_3, (1 << (cpu_id + 1)), 0);   // send to next core to start sgi loop;
    }

    if (cpu_id == (cpuCount - 1))
    {
        isTestDone = 0;        // test complete
    }
}

void start_secondary_cpu(uint32_t cpu_num, void functPtr(void))
{
    // Prepare pointers for ROM code.
    switch (cpu_num)
    {
        case 1:
            HW_SRC_GPR3_WR((uint32_t) & startup_imx6x);
            HW_SRC_GPR4_WR((uint32_t) functPtr);
    
            HW_SRC_SCR.B.CORE1_ENABLE = 1;
            break;

#if defined(CHIP_MX6DQ)
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
#endif // CHIP_MX6DQ
    }
}

//! This test first starts the secondary CPUs in order from 1 through 3. When each secondary
//! CPU starts, it executes this function. The first thing this function does for secondary CPUs
//! is to enable interrupts for the CPU in the GIC.
//!
//! When the last CPU enters this function, it will start a loop of sending software interrupts
//! to all cores in sequence by sending the first SGI to core 0. As each core handles the SGI,
//! it will print a message and send an SGI to the next CPU in sequence.
void multicore_test(void)
{
    uint32_t cpu_id = cpu_get_current();
    int cpuCount = cpu_get_cores();
    
    if (cpuCount == 1)
    {
        printf("This chip only has one CPU!\n");
        return;
    }

    if (cpu_id != 0)
    {
        // Enable interrupts on secondary CPUs.
        gic_set_cpu_priority_mask(0xff);
        gic_cpu_enable(true);
    }

    // primary cpu
    if (cpu_id == 0)
    {
        isTestDone = 1;

        register_interrupt_routine(SW_INTERRUPT_3, SGI3_ISR);   // register sgi isr

        printf("Running the GIC Multicore Test \n");
        printf("Starting and sending SGIs to secondary CPUs for \"hello world\" \n\n");

        // start second cpu
        start_secondary_cpu(1, &multicore_test);

        while (isTestDone) ;   //cpu0 wait until test is done, that is until cpu3 completes its SGI.
        //writel((readl(SRC_BASE_ADDR + SRC_SCR_OFFSET) & ~(7 << 22)),
        //       (SRC_BASE_ADDR + SRC_SCR_OFFSET));
        
        // put other cores back into reset with SRC module
        HW_SRC_SCR.B.CORE1_ENABLE = 0;
        
#if defined(CHIP_MX6DQ)
        HW_SRC_SCR.B.CORE2_ENABLE = 0;
        HW_SRC_SCR.B.CORE3_ENABLE = 0;
#endif
        
        printf("\nEnd of test\n");
    }
    // other cpus
    else
    {
        printf("secondary main cpu: %d\n", cpu_id);

        if (cpu_id == (cpuCount - 1))
        {
            //void send_sgi(unsigned int ID, unsigned int target_list, unsigned int filter_list);
            gic_send_sgi(SW_INTERRUPT_3, 1, 0); // send to cpu_0 to start sgi loop;
        }
        else
        {
            start_secondary_cpu(cpu_id + 1, &multicore_test);
        }
        
        while (1) ;             //do nothing wait to be interrupted
    }
}

void main(void)
{
    platform_init();

    // Run the demo.
    multicore_test();

    _sys_exit(0);
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
