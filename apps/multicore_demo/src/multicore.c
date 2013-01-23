/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "sdk.h"
#include "platform_init.h"
#include "irq_numbers.h"
#include "registers/regssrc.h"
#include "cpu_utility/cpu_utility.h"
#include "core/cortex_a9.h"
#include "core/gic.h"
#include "core/interrupt.h"
#include "utility/system_util.h"

////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

extern void _start(void);    // entry function, startup routine, defined in startup.s

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
        // send to next core to start sgi loop
        gic_send_sgi(SW_INTERRUPT_3, (1 << (cpu_id + 1)), kGicSgiFilter_UseTargetList);
    }

    if (cpu_id == (cpuCount - 1))
    {
        // test complete
        isTestDone = 0;
    }
}

void start_secondary_cpu(uint32_t cpu_num, void functPtr(void))
{
    // Prepare pointers for ROM code.
    switch (cpu_num)
    {
        case 1:
            HW_SRC_GPR3_WR((uint32_t) & _start);
            HW_SRC_GPR4_WR((uint32_t) functPtr);
    
            HW_SRC_SCR.B.CORE1_ENABLE = 1;
            break;

#if defined(CHIP_MX6DQ)
        case 2:
            HW_SRC_GPR5_WR((uint32_t) & _start);
            HW_SRC_GPR6_WR((uint32_t) functPtr);
    
            HW_SRC_SCR.B.CORE2_ENABLE = 1;
            break;
    
        case 3:
            HW_SRC_GPR7_WR((uint32_t) & _start);
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
        gic_init_cpu();
    }

    // primary cpu
    if (cpu_id == 0)
    {
        isTestDone = 1;

        // register sgi isr
        register_interrupt_routine(SW_INTERRUPT_3, SGI3_ISR);

        printf("Running the GIC Multicore Test \n");
        printf("Starting and sending SGIs to secondary CPUs for \"hello world\" \n\n");

        // start second cpu
        start_secondary_cpu(1, &multicore_test);

        // cpu0 wait until test is done, that is until cpu3 completes its SGI.
        while (isTestDone);
        
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
            // send to cpu_0 to start sgi loop
            gic_send_sgi(SW_INTERRUPT_3, 1, kGicSgiFilter_UseTargetList);
        }
        else
        {
            start_secondary_cpu(cpu_id + 1, &multicore_test);
        }
        
        // do nothing wait to be interrupted
        while (1);
    }
}

void main(void)
{
    platform_init();

    // Run the demo.
    multicore_test();
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
