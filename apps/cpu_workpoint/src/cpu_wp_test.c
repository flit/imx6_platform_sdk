/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
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

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include "sdk.h"
#include "platform_init.h"
#include "print_version.h"
#include "timer/epit.h"
#include "core/cortex_a9.h"
#include "core/mmu.h"
#include "pmu/pmu_driver.h"
#include "registers/regsccm.h"
#include "registers/regsccmanalog.h"
#include "registers/regspmu.h"

typedef struct cpu_wp_s {
    uint32_t cpu_freq;          // MHz
    uint32_t vdd_pu;            //mV
    uint32_t vdd_soc;           //mV
    uint32_t vdd_arm;           //mV
} cpu_wp_t;

static cpu_wp_t mx6_cpu_wp[] = {
    {
     .cpu_freq = 1200,
     .vdd_pu = 1275,
     .vdd_soc = 1275,
     .vdd_arm = 1275,
     },
    {
     .cpu_freq = 996,
     .vdd_pu = 1250,
     .vdd_soc = 1250,
     .vdd_arm = 1250,
     },
    {
     .cpu_freq = 792,
     .vdd_pu = 1175,
     .vdd_soc = 1175,
     .vdd_arm = 1150,
     },
    {
     .cpu_freq = 396,
     .vdd_pu = 1175,
     .vdd_soc = 1175,
     .vdd_arm = 950,
     },
};

void cpu_workpoint_set(cpu_wp_t * wp)
{
    unsigned int div = 0;

    /* calculate the pll loop divider. target Fout = Fin * div / 2 */
    div = wp->cpu_freq * 2 / 24;

    /* first, switch the cpu clock root to step clock */
    HW_CCM_CCSR.B.PLL1_SW_CLK_SEL = 1;

    /* set clock to target frequency */
    HW_CCM_ANALOG_PLL_ARM.B.POWERDOWN = 1;
    HW_CCM_ANALOG_PLL_ARM.B.DIV_SELECT = div;
    HW_CCM_ANALOG_PLL_ARM.B.POWERDOWN = 0;
    while (!HW_CCM_ANALOG_PLL_ARM.B.LOCK) ;
    HW_CCM_ANALOG_PLL_ARM.B.BYPASS = 0;

    /* set the power rail */
    switch (wp->cpu_freq) {
    case 1200:
    case 996:
    case 792:
    case 396:
        pmu_set_property(kPMURegulator_ArmCore, kPMUProperty_OutputMillivolts, &wp->vdd_arm);
        pmu_set_property(kPMURegulator_Graphics, kPMUProperty_OutputMillivolts, &wp->vdd_pu);
        pmu_set_property(kPMURegulator_SoC, kPMUProperty_OutputMillivolts, &wp->vdd_soc);
        break;
    default:
        printf("Unsupported CPU workpoint mode!!\n");
        return;
    }

    /*switch back to PLL1 */
    HW_CCM_CCSR.B.PLL1_SW_CLK_SEL = 0;
}

void my_memcpy(char *dst, char *src, int size)
{
    asm volatile ("push {r0-r6}");
    asm volatile ("loop:");
    asm volatile ("ldmia r1!, {r3-r6}");
    asm volatile ("stmia r0!, {r3-r6}");
    asm volatile ("subs r2, r2, #16");
    asm volatile ("bne loop");
    asm volatile ("pop {r4-r6}");
}

uint32_t memcpy_perf_record(int size)
{
    char *dst = (char *)0x24000000;
    char *src = (char *)0x28000000;
    uint32_t time_counter;

    static hw_module_t count_timer = {
        "EPIT2 for system tick",
        2,
        EPIT2_BASE_ADDR,
        27000000,
        IMX_INT_EPIT2,
        NULL,
        NULL
    };

    count_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&count_timer, CLKSRC_IPG_CLK, count_timer.freq / 1000000,
              SET_AND_FORGET, 10000, WAIT_MODE_EN | STOP_MODE_EN);
    epit_setup_interrupt(&count_timer, FALSE);
    epit_counter_enable(&count_timer, 0xFFFFFFFF, 0);   //polling mode

    my_memcpy(dst, src, size);

    time_counter = epit_get_counter_value(&count_timer);
    epit_counter_disable(&count_timer); //polling mode

    time_counter = (0xFFFFFFFF - time_counter) / 1000;  //ms

    return time_counter;
}

int cpu_wp_test(void)
{
    int i = 0;
    int time_elapsed = 0;
    int size = 0x1000000;

    if (arm_dcache_state_query() == 1) {
        arm_dcache_flush();
        arm_dcache_invalidate();
        mmu_disable();
        arm_dcache_disable();
    }

    pmu_init();

    while (i < sizeof(mx6_cpu_wp) / sizeof(mx6_cpu_wp[0])) {
        cpu_workpoint_set(&mx6_cpu_wp[i]);
        time_elapsed = memcpy_perf_record(size);
        printf(" Copying %dMB data takes %d ms when cpu running at %dMHz\n", size / (1024 * 1024),
               time_elapsed, mx6_cpu_wp[i].cpu_freq);
        hal_delay_us(3000);
        i++;
    }

    return 0;
}

int main(void)
{
    platform_init();
    print_version();
    cpu_wp_test();
    _sys_exit(0);
    return 0;
}
