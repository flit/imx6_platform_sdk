/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __TIME_H__
#define __TIME_H__

//#########################################
//# EPIT peripheral defines
//#########################################
#define EPIT_EPITCR_OFFSET 0x00 //  32bit timer 3 control reg
#define EPIT_EPITSR_OFFSET 0x04 //  32bit timer 3 prescaler reg
#define EPIT_EPITLR_OFFSET 0x08 //  32bit timer 3 compare reg
#define EPIT_EPITCMPR_OFFSET 0x0C   //  32bit timer 3 capture reg
#define EPIT_EPITCNR_OFFSET 0x10    //  32bit timer 3 counter reg

#define EPITCR              EPIT_EPITCR_OFFSET
#define EPITSR              EPIT_EPITSR_OFFSET
#define EPITLR              EPIT_EPITLR_OFFSET
#define EPITCMPR            EPIT_EPITCMPR_OFFSET
#define EPITCNR             EPIT_EPITCNR_OFFSET

//#########################################
//# GPT peripheral defines
//#########################################
#define GPT_GPTCR_OFFSET 0x00   //  32bit timer 1 control reg
#define GPT_GPTPR_OFFSET 0x04   //  32bit timer 1 prescaler reg
#define GPT_GPTSR_OFFSET 0x08   //  32bit timer 1 compare reg
#define GPT_GPTIR_OFFSET 0x0C   //  32bit timer 1 capture reg
#define GPT_GPTOCR1_OFFSET 0x10 //  32bit timer 1 counter reg
#define GPT_GPTOCR2_OFFSET 0x14 //  32bit timer 1 status reg
#define GPT_GPTOCR3_OFFSET 0x18 // 32 bit read & write
#define GPT_GPTICR1_OFFSET 0x1C // 32 bit read
#define GPT_GPTICR2_OFFSET 0x20 // 32 bit read
#define GPT_GPTCNT_OFFSET 0x24  // 32 bit read

#endif
