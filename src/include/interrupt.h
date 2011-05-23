
/*
 * Copyright (C) 2009-2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_init Base SDK files
 */

/*!
 * @file  interrupt.c
 *
 * @ingroup diag_init
 */

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#define ATTACH_INTERRUPT(index,routine) ( interrupt_routine_list[index] = routine )

#define MAX_INTERRUPT_NUM	128
extern void (*interrupt_routine_list[]) (void);

/* defube the TZIC registers*/
#define TZIC_INTCTRL_OFFSET	0x0000  // Control Register
#define TZIC_INTTYPE_OFFSET	0x0004  // Interrupt Controller Type Reg.
#define TZIC_IMPID_OFFSET	0x0008  // Distributor Implementer Identification Reg.
#define TZIC_PRIOMASK_OFFSET	0x000C  // Priority Mask Register R/W
#define TZIC_INTSEC0_OFFSET	0x0080  // Interrupt Security Register
#define TZIC_INTSEC1_OFFSET	0x0084  // Interrupt Security Register
#define TZIC_INTSEC2_OFFSET	0x0088  // Interrupt Security Register
#define TZIC_INTSEC3_OFFSET	0x008C  // Interrupt Security Register
#define TZIC_ENSET0_OFFSET	0x0100  // Enable Set Register
#define TZIC_ENSET1_OFFSET	0x0104  // Enable Set Register
#define TZIC_ENSET2_OFFSET	0x0108  // Enable Set Register
#define TZIC_ENSET3_OFFSET	0x010C  // Enable Set Register
#define TZIC_ENCLEAR0_OFFSET	0x0180  // Enable Clear Register
#define TZIC_ENCLEAR1_OFFSET	0x0184  // Enable Clear Register
#define TZIC_ENCLEAR2_OFFSET	0x0188  // Enable Clear Register
#define TZIC_ENCLEAR3_OFFSET	0x018C  // Enable Clear Register
#define TZIC_SRCSET0_OFFSET	0x0200  // Source Set Register
#define TZIC_SRCSET1_OFFSET	0x0204  // Source Set Register
#define TZIC_SRCSET2_OFFSET	0x0208  // Source Set Register
#define TZIC_SRCSET3_OFFSET	0x020C  // Source Set Register
#define TZIC_SRCCLEAR0_OFFSET	0x0280  // Source Clear Register
#define TZIC_SRCCLEAR1_OFFSET	0x0284  // Source Clear Register
#define TZIC_SRCCLEAR2_OFFSET	0x0288  // Source Clear Register
#define TZIC_SRCCLEAR3_OFFSET	0x028C  // Source Clear Register
#define TZIC_PRIORITY0_OFFSET	0x0400  // Priority Register
#define TZIC_PRIORITY1_OFFSET	0x0404  // Priority Register
#define TZIC_PRIORITY2_OFFSET	0x0408  // Priority Register
#define TZIC_PRIORITY3_OFFSET	0x040C  // Priority Register
#define TZIC_PRIORITY4_OFFSET	0x0410  // Priority Register
#define TZIC_PRIORITY5_OFFSET	0x0414  // Priority Register
#define TZIC_PRIORITY6_OFFSET	0x0418  // Priority Register
#define TZIC_PRIORITY7_OFFSET	0x041C  // Priority Register
#define TZIC_PRIORITY8_OFFSET	0x0420  // Priority Register
#define TZIC_PRIORITY9_OFFSET	0x0424  // Priority Register
#define TZIC_PRIORITY10_OFFSET	0x0428  // Priority Register
#define TZIC_PRIORITY11_OFFSET	0x042C  // Priority Register
#define TZIC_PRIORITY12_OFFSET	0x0430  // Priority Register
#define TZIC_PRIORITY13_OFFSET	0x0434  // Priority Register
#define TZIC_PRIORITY14_OFFSET	0x0438  // Priority Register
#define TZIC_PRIORITY15_OFFSET	0x043C  // Priority Register
#define TZIC_PRIORITY16_OFFSET	0x0440  // Priority Register
#define TZIC_PRIORITY17_OFFSET	0x0444  // Priority Register
#define TZIC_PRIORITY18_OFFSET	0x0448  // Priority Register
#define TZIC_PRIORITY19_OFFSET	0x044C  // Priority Register
#define TZIC_PRIORITY20_OFFSET	0x0450  // Priority Register
#define TZIC_PRIORITY21_OFFSET	0x0454  // Priority Register
#define TZIC_PRIORITY22_OFFSET	0x0458  // Priority Register
#define TZIC_PRIORITY23_OFFSET	0x045C  // Priority Register
#define TZIC_PRIORITY24_OFFSET	0x0460  // Priority Register
#define TZIC_PRIORITY25_OFFSET	0x0464  // Priority Register
#define TZIC_PRIORITY26_OFFSET	0x0468  // Priority Register
#define TZIC_PRIORITY27_OFFSET	0x046C  // Priority Register
#define TZIC_PRIORITY28_OFFSET	0x0470  // Priority Register
#define TZIC_PRIORITY29_OFFSET	0x0474  // Priority Register
#define TZIC_PRIORITY30_OFFSET	0x0478  // Priority Register
#define TZIC_PRIORITY31_OFFSET	0x047C  // Priority Register
#define TZIC_PND0_OFFSET	0x0D00  // Pending Register
#define TZIC_PND1_OFFSET	0x0D04  // Pending Register
#define TZIC_PND2_OFFSET	0x0D08  // Pending Register
#define TZIC_PND3_OFFSET	0x0D0C  // Pending Register
#define TZIC_HIPND0_OFFSET	0x0D80  // High Priority Pending Register
#define TZIC_HIPND1_OFFSET	0x0D84  // High Priority Pending Register
#define TZIC_HIPND2_OFFSET	0x0D88  // High Priority Pending Register
#define TZIC_HIPND3_OFFSET	0x0D8C  // High Priority Pending Register
#define TZIC_WAKEUP0_OFFSET	0x0E00  // Wakeup Config Register
#define TZIC_WAKEUP1_OFFSET	0x0E04  // Wakeup Config Register
#define TZIC_WAKEUP2_OFFSET	0x0E08  // Wakeup Config Register
#define TZIC_WAKEUP3_OFFSET	0x0E0C  // Wakeup Config Register
#define TZIC_SWINT_OFFSET	0x0F00  // Software Interrupt Trigger Register
#define TZIC_ID0_OFFSET	0x0Fd0  // Identification Register 0
#define TZIC_ID1_OFFSET	0x0fd4  // Identification Register 1
#define TZIC_ID2_OFFSET	0x0fd8  // Identification Register 2
#define TZIC_ID3_OFFSET	0x0fdc  // Identification Register 3
#define TZIC_ID4_OFFSET	0x0fe0  // Identification Register 4
#define TZIC_ID5_OFFSET	0x0fe4  // Identification Register 5
#define TZIC_ID6_OFFSET	0x0fe8  // Identification Register 6
#define TZIC_ID7_OFFSET	0x0fec  // Identification Register 7
#define TZIC_ID8_OFFSET	0x0ff0  // Identification Register 8
#define TZIC_ID9_OFFSET	0x0ff4  // Identification Register 9
#define TZIC_ID10_OFFSET	0x0ff8  // Identification Register 10
#define TZIC_ID11_OFFSET	0x0ffc  // Identification Register 11
#define TZIC_PRIO0PND0_OFFSET	0x8000  // Priority 0 Pending Register
#define TZIC_PRIO8PND1_OFFSET	0x8004  // Priority 8 Pending Register
#define TZIC_PRIO16PND2_OFFSET	0x8008  // Priority 16 Pending Register
#define TZIC_PRIO24PND3_OFFSET	0x800C  // Priority 24 Pending Register

#endif
