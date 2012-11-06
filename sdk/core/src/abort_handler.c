/*
 * Copyright (c) 2009-2012, Freescale Semiconductor, Inc.
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

/*!
 * @file  abort_handler.c
 *
 * @ingroup diag_init
 */

#include "sdk.h"

typedef struct {
    uint32_t cpsr;
    uint32_t pc;
    uint32_t sp;
    uint32_t lr;
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
} arm_regs_t, *arm_regs_p;

/**************************** Functions ***************************************/
int dump_regs(arm_regs_p regs)
{
    printf("Opps, data abort! The registers right before this exception hanppened were dumped as:\n");

    printf("R0: 0x%08x\n", regs->r0);
    printf("R1: 0x%08x\n", regs->r1);
    printf("R2: 0x%08x\n", regs->r2);
    printf("R3: 0x%08x\n", regs->r3);
    printf("R4: 0x%08x\n", regs->r4);
    printf("R5: 0x%08x\n", regs->r5);
    printf("R6: 0x%08x\n", regs->r6);
    printf("R7: 0x%08x\n", regs->r7);
    printf("R8: 0x%08x\n", regs->r8);
    printf("R9: 0x%08x\n", regs->r9);
    printf("R10: 0x%08x\n", regs->r10);
    printf("R11: 0x%08x\n", regs->r11);
    printf("R12: 0x%08x\n", regs->r12);
    printf("SP: 0x%08x\n", regs->sp);
    printf("LR: 0x%08x\n", regs->lr);
    printf("PC: 0x%08x\n", regs->pc);
    printf("CPSR: 0x%08x\n", regs->cpsr);

    return 0;
}
