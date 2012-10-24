/*
 * Copyright (c) 2008-2012, Freescale Semiconductor, Inc.
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
 * @file asm_defines.h
 * @brief         defines for startup assembly code
 *
 * @ingroup diag_util
 */

#ifndef _ASM_DEFINES_H_
#define _ASM_DEFINES_H_

#define    MODE_USR     0X10
#define    MODE_FIQ     0X11
#define    MODE_IRQ     0X12
#define    MODE_SVC     0X13
#define    MODE_ABT     0X17
#define    MODE_UND     0X1B
#define    MODE_SYS     0X1F

#define    I_BIT        0x80    /* when I bit is set, IRQ is disabled */
#define    F_BIT        0x40    /* when F bit is set, FIQ is disabled */

/* --- Amount of memory (in bytes) allocated for stacks */
#define    LEN_FIQ_STACK  1024
#define    LEN_IRQ_STACK  1024
#define    LEN_ABT_STACK  1024
#define    LEN_UND_STACK  1024
#define    LEN_SVC_STACK  1024
#define    LEN_USR_STACK  1024

/*  Add lengths >0 for FIQ_Stack, ABT_Stack, UND_Stack if you need them.
 * Offsets will be loaded as immediate values.
 * Offsets must be 8 byte aligned.
*/
#define    OFFSET_FIQ_STACK   0
#define    OFFSET_IRQ_STACK   (OFFSET_FIQ_STACK + LEN_FIQ_STACK)
#define    OFFSET_ABT_STACK   (OFFSET_IRQ_STACK + LEN_IRQ_STACK)
#define    OFFSET_UND_STACK   (OFFSET_ABT_STACK + LEN_ABT_STACK)
#define    OFFSET_SVC_STACK   (OFFSET_UND_STACK + LEN_UND_STACK)
#define    OFFSET_USR_STACK   (OFFSET_SVC_STACK + LEN_SVC_STACK)

#endif /*_ASM_DEFINES_H_ */
