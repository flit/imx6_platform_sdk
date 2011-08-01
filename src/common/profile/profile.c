/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

void StartPerfCounter(void)
{
    asm("mov r1, #12");         /* divider enable (64 cycles/count), cycle counter reset */
    asm("mcr p15, 0, r1, c9, c12, 0");

    asm("ldr r1,=0x80000000");
    asm("mcr p15, 0, r1, c9, c12, 1");  /*enable C bit of c9,Count Enable Set register */

    asm("mov r1, #9");          /* Counter enable */
    asm("mcr p15, 0, r1, c9, c12, 0");
}

unsigned int StopPerfCounter(void)
{
    unsigned int counter = 0;

    asm volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (counter):);

    asm("ldr r1,=0x80000000");
    asm("mcr p15, 0, r1, c9, c12, 2 "); /*disable C bit of c9,Count Clear register */

    return counter * 64;
}
