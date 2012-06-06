/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpt.h
 * @brief GPT driver header file.
 * @ingroup diag_timer
 */

#ifndef __GPT_H__
#define __GPT_H__

#include "sdk.h"

/* GPT Registers Bit Fields */
#define GPTCR_FO3           (0 << 31)   // GPT force output compare
#define GPTCR_FO2           (0 << 30)   // GPT force output compare
#define GPTCR_FO1           (0 << 29)   // GPT force output compare
    /* x=1,2,3 - y=output mode listed into timer.h */
#define GPTCR_OM_MODE(x,y)  ((y) << (17+x*3)) // GPT output compare mode
    /* x=1,2 - y=input mode listed below */
#define GPTCR_IM_MODE(x,y)  ((y) << (14+x*2)) // GPT input capture mode
#define GPTCR_SWR           (1 << 15)   // starts a software reset
#define GPTCR_FRR           (1 << 9)    // Free-run or restart mode
    /* x = clock source */
#define GPTCR_CLKSRC(x)     ((x) << 6)  // clock source
#define GPTCR_STOPEN        (1 << 5)    // GPT enabled in STOP mode
#define GPTCR_WAITEN        (1 << 3)    // GPT enabled in WAIT mode
#define GPTCR_DBGEN         (1 << 2)    // GPT enabled in debug mode
#define GPTCR_ENMOD         (1 << 1)    // counter start mode
#define GPTCR_EN            (1 << 0)    // GPT enable

#define GPTSR_ROV           (1 << 5)    // Rollover flag set
#define GPTSR_IF2           (1 << 4)    // Input capture flag 2 set
#define GPTSR_IF1           (1 << 3)    // Input capture flag 1 set
#define GPTSR_OF3           (1 << 2)    // Output compare flag 3 set
#define GPTSR_OF2           (1 << 1)    // Output compare flag 2 set
#define GPTSR_OF1           (1 << 0)    // Output compare flag 1 set
#define GPTSR_ALL           0x3F        // All flags

#define GPTSR_ROVIE         (1 << 5)    // Rollover interrupt enable
#define GPTSR_IF2IE         (1 << 4)    // Input capture 2 interrupt enable
#define GPTSR_IF1IE         (1 << 3)    // Input capture 1 interrupt enable
#define GPTSR_OF3IE         (1 << 2)    // Output compare 3 interrupt enable
#define GPTSR_OF2IE         (1 << 1)    // Output compare 2 interrupt enable
#define GPTSR_OF1IE         (1 << 0)    // Output compare 1 interrupt enable

/* GPT specific defines */
#define RESTART_MODE    0
#define FREE_RUN_MODE   GPTCR_FRR
/* list of input capture modes supported */
#define INPUT_CAP_DISABLE       0x0 // input capture event disabled
#define INPUT_CAP_RISING_EDGE   0x1 // input capture event on a rising edge
#define INPUT_CAP_FALLING_EDGE  0x2 // input capture event on a falling edge
#define INPUT_CAP_BOTH_EDGE     0x3 // input capture event on a both edge

#define CAP_INPUT1  1
#define CAP_INPUT2  2
#define CMP_OUTPUT1  1
#define CMP_OUTPUT2  2
#define CMP_OUTPUT3  3

/* GPT driver list of functions */
void gpt_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
              uint32_t counter_mode, uint32_t low_power_mode);
void gpt_setup_interrupt(struct hw_module *port, uint8_t state);
void gpt_counter_enable(struct hw_module *port, uint32_t irq_mode);
void gpt_counter_disable(struct hw_module *port);
uint32_t gpt_get_rollover_event(struct hw_module *port);
uint32_t gpt_get_capture_event(struct hw_module *port, uint8_t flag,
                               uint32_t * capture_val);
void gpt_set_capture_event(struct hw_module *port, uint8_t cap_input,
                           uint8_t cap_input_mode);
uint32_t gpt_get_compare_event(struct hw_module *port, uint8_t flag);
void gpt_set_compare_event(struct hw_module *port, uint8_t cmp_output,
                           uint8_t cmp_output_mode, uint32_t cmp_value);

/* GPT Registers list */
struct mx_gpt {
    volatile uint32_t gpt_cr;
    volatile uint32_t gpt_pr;
    volatile uint32_t gpt_sr;
    volatile uint32_t gpt_ir;
    volatile uint32_t gpt_ocr1;
    volatile uint32_t gpt_ocr2;
    volatile uint32_t gpt_ocr3;
    volatile uint32_t gpt_icr1;
    volatile uint32_t gpt_icr2;
    volatile uint32_t gpt_cnt;
};

#endif //__GPT_H__
