/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef _SOC_MEMORY_MAP_H
#define _SOC_MEMORY_MAP_H

#define BAAD_STATUS                 0xbaadbaad
#define GOOD_STATUS                 0x900d900d

// CPU Memory Map
#define BOOT_ROM_BASE_ADDR          0x00000000
#define ROM_SI_REV_OFFSET		    0x48
#define SCC_RAM_BASE_ADDR			0x07000000
#define TZIC_BASE_ADDR				0x0FFFC000
#define SATA_BASE_ADDR				0x10000000
#define IPU_BASE_ADDR               0x18000000
#define OPENVG_BASE_ADDR			0x20000000
#define GPU_BASE_ADDR				0x30000000
#define DEBUG_ROM_BASE_ADDR         0x40000000
#define ETB_BASE_ADDR				0x40001000
#define ETM_BASE_ADDR				0x40002000
#define TPIU_BASE_ADDR				0x40003000
#define CTI0_BASE_ADDR				0x40004000
#define CTI1_BASE_ADDR				0x40005000
#define CTI2_BASE_ADDR				0x40006000
#define CTI3_BASE_ADDR				0x40007000
#define CORTEX_DEBUG_UNIT			0x40008000

#define AIPS_TZ1_BASE_ADDR			0x50000000
#define AIPS_TZ2_BASE_ADDR			0x60000000

#define ESDHC1_BASE_ADDR			0x50004000
#define ESDHC2_BASE_ADDR			0x50008000
#define UART3_BASE_ADDR             0x5000C000
#define ECSPI1_BASE_ADDR			0x50010000
#define SSI2_BASE_ADDR				0x50014000
#define ESAI1_BASE_ADDR             0x50018000
#define ESDHC3_BASE_ADDR			0x50020000
#define ESDHC4_BASE_ADDR			0x50024000
#define SPDIF_BASE_ADDR             0x50028000
#define ASRC_BASE_ADDR				0x5002C000
#define PATA_PORT_UDMA_BASE_ADDR	0x50030000
#define SPBA_BASE_ADDR				0x5003C000

// AIPS_TZ#1- On Platform
#define AIPS1_BASE_ADDR                AIPS_TZ1_BASE_ADDR+0x03F00000

// AIPS_TZ#1- Off Platform
#define USBOH3_BASE_ADDR			0x53F80000
#define GPIO1_BASE_ADDR			0x53F84000
#define GPIO2_BASE_ADDR			0x53F88000
#define GPIO3_BASE_ADDR			0x53F8C000
#define GPIO4_BASE_ADDR			0x53F90000
#define KPP_BASE_ADDR			       0x53F94000
#define WDOG1_BASE_ADDR			0x53F98000
#define WDOG2_BASE_ADDR			0x53F9C000
#define GPT_BASE_ADDR			       0x53FA0000
#define SRTC_BASE_ADDR			       0x53FA4000
#define IOMUXC_BASE_ADDR			0x53FA8000
#define EPIT1_BASE_ADDR			0x53FAC000
#define EPIT2_BASE_ADDR			0x53FB0000
#define PWM1_BASE_ADDR			0x53FB4000
#define PWM2_BASE_ADDR			0x53FB8000
#define UART1_BASE_ADDR			0x53FBC000
#define UART2_BASE_ADDR			0x53FC0000
#define PL301_USBOH3_BASE_ADDR	0x53FC4000
#define CAN1_BASE_ADDR				0x53FC8000
#define CAN2_BASE_ADDR				0x53FCC000
#define SRC_BASE_ADDR				0x53FD0000
#define CCM_BASE_ADDR				0x53FD4000
#define GPC_BASE_ADDR				0x53FD8000
#define GPIO5_BASE_ADDR			0x53FDC000
#define GPIO6_BASE_ADDR			0x53FE0000
#define GPIO7_BASE_ADDR			0x53FE4000
#define PATA_PORT_PIO_BASE_ADDR	0x53FE8000
#define I2C3_BASE_ADDR				0x53FEC000
#define UART4_BASE_ADDR			0x53FF0000

// AIPS_TZ#2- On Platform
#define AIPS2_BASE_ADDR                AIPS_TZ2_BASE_ADDR+0x03F00000

// AIPS_TZ#2- Off Platform
#define DPLLIP1_BASE_ADDR			0x63F80000
#define DPLLIP2_BASE_ADDR			0x63F84000
#define DPLLIP3_BASE_ADDR			0x63F88000
#define DPLLIP4_BASE_ADDR			0x63F8C000
#define UART5_BASE_ADDR			0x63F90000
#define AHBMAX_BASE_ADDR			0x63F94000
#define MAX_BASE_ADDR				AHBMAX_BASE_ADDR
#define IIM_BASE_ADDR				0x63F98000
#define CSU_BASE_ADDR			       0x63F9C000
#define ARM_BASE_ADDR				0x63FA0000
#define OWIRE_BASE_ADDR			0x63FA4000
#define FIRI_BASE_ADDR				0x63FA8000
#define ECSPI2_BASE_ADDR			0x63FAC000
#define SDMA_PORT_IPS_HOST_BASE_ADDR	0x63FB0000
#define SDMA_IPS_HOST_BASE_ADDR	SDMA_PORT_IPS_HOST_BASE_ADDR
#define SCC_BASE_ADDR				0x63FB4000
#define ROMCP_BASE_ADDR			0x63FB8000
#define RTICV3_BASE_ADDR			0x63FBC000
#define RTIC_BASE_ADDR				RTICV3_BASE_ADDR
#define CSPI_BASE_ADDR				0x63FC0000
#define I2C2_BASE_ADDR				0x63FC4000
#define I2C1_BASE_ADDR				0x63FC8000
#define SSI1_BASE_ADDR				0x63FCC000
#define AUDMUX_BASE_ADDR			0x63FD0000
#define RTC_BASE_ADDR				0x63FD4000
#define M4IF_REGISTERS_BASE_ADDR	0x63FD8000
#define ESDCTL_REGISTERS_BASE_ADDR	0x63FD9000
#define WEIM_REGISTERS_BASE_ADDR		0x63FDA000
#define EIM_BASE_ADDR                   WEIM_REGISTERS_BASE_ADDR
#define NFC_IP_BASE					0x63FDB000
#define EMIV2_REGISTERS_BASE_ADDR		0x63FDBF00
#define PL301_2X2_BASE_ADDR		0x63FDC000
#define PL301_4X1_BASE_ADDR		0x63FE0000
#define MLB_BASE_ADDR      			0x63FE4000
#define SSI3_BASE_ADDR				0x63FE8000
#define FEC_BASE_ADDR				0x63FEC000
#define TVE_BASE_ADDR				0x63FF0000
#define VPU_BASE_ADDR				0x63FF4000
#define SAHARA_BASE_ADDR			0x63FF8000
#define PTP_BASE_ADDR    			0x63FFC000

#define CSD0_DDR_BASE_ADDR		 0x70000000
#define CSD1_DDR_BASE_ADDR		 0xB0000000
#define CS0_BASE_ADDR			        0xF0000000
#define NFC_BASE				        0xF7FF0000
#define IRAM_BASE_ADDR			        0xF8000000
#define GPU_MEM_BASE_ADDR		        0xF8020000

/* define the TZIC registers*/
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

/*
 * Interrupt numbers
 */
#define IMX_INT_BASE                0
#define IMX_INT_RESV0               0
#define IMX_INT_MMC_SDHC1           1
#define IMX_INT_MMC_SDHC2           2
#define IMX_INT_MMC_SDHC3           3
#define IMX_INT_MMC_SDHC4           4
#define IMX_INT_DAP                 5
#define IMX_INT_SDMA                6
#define IMX_INT_IOMUX               7
#define IMX_INT_NFC                 8
#define IMX_INT_VPU                 9
#define IMX_INT_IPU_ERR				10
#define IMX_INT_IPU_SYN				11
#define IMX_INT_GPU                 12
#define IMX_INT_UART4               13
#define IMX_INT_USB_H1              14
#define IMX_INT_EMI                 15
#define IMX_INT_USB_H2              16
#define IMX_INT_USB_H3              17
#define IMX_INT_USB_OTG             18
#define IMX_INT_SAHARA_H0           19
#define IMX_INT_SAHARA_H1           20
#define IMX_INT_SCC_SMN				21
#define IMX_INT_SCC_STZ				22
#define IMX_INT_SCC_SCM				23
#define IMX_INT_SRTC_NTZ			24
#define IMX_INT_SRTC_TZ				25
#define IMX_INT_RTIC                26
#define IMX_INT_CSU                 27
#define IMX_INT_SATA                28
#define IMX_INT_SSI1                29
#define IMX_INT_SSI2                30
#define IMX_INT_UART1               31
#define IMX_INT_UART2               32
#define IMX_INT_UART3               33
#define IMX_INT_RTC_IEEE1588        34
#define IMX_INT_PTP_IEEE1588        35
#define IMX_INT_ECSPI1              36
#define IMX_INT_ECSPI2              37
#define IMX_INT_CSPI                38
#define IMX_INT_GPT                 39
#define IMX_INT_EPIT1               40
#define IMX_INT_EPIT2               41
#define IMX_INT_GPIO1_INT7          42
#define IMX_INT_GPIO1_INT6          43
#define IMX_INT_GPIO1_INT5          44
#define IMX_INT_GPIO1_INT4          45
#define IMX_INT_GPIO1_INT3          46
#define IMX_INT_GPIO1_INT2          47
#define IMX_INT_GPIO1_INT1          48
#define IMX_INT_GPIO1_INT0          49
#define IMX_INT_GPIO1_LOW           50
#define IMX_INT_GPIO1_HIGH          51
#define IMX_INT_GPIO2_LOW           52
#define IMX_INT_GPIO2_HIGH          53
#define IMX_INT_GPIO3_LOW           54
#define IMX_INT_GPIO3_HIGH          55
#define IMX_INT_GPIO4_LOW           56
#define IMX_INT_GPIO4_HIGH          57
#define IMX_INT_WDOG1               58
#define IMX_INT_WDOG2               59
#define IMX_INT_KPP                 60
#define IMX_INT_PWM1                61
#define IMX_INT_I2C1                62
#define IMX_INT_I2C2                63
#define IMX_INT_I2C3                64
#define IMX_INT_MLB                 65
#define IMX_INT_ASRC                66
#define IMX_INT_SPDIF               67
#define IMX_INT_RESV1               68
#define IMX_INT_IIM                 69
#define IMX_INT_PATA                70
#define IMX_INT_CCM1                71
#define IMX_INT_CCM2                72
#define IMX_INT_GPC1                73
#define IMX_INT_GPC2                74
#define IMX_INT_SRC                 75
#define IMX_INT_NM                  76
#define IMX_INT_PMU                 77
#define IMX_INT_CTI_IRQ             78
#define IMX_INT_CTI1_TG0            79
#define IMX_INT_CTI1_TG1            80
#define IMX_INT_ESAI1               81
#define IMX_INT_CAN1                82
#define IMX_INT_CAN2                83
#define IMX_INT_OPENVG              84
#define IMX_INT_OPENVG_BUSY         85
#define IMX_INT_UART5               86
#define IMX_INT_FEC                 87
#define IMX_INT_OWIRE               88
#define IMX_INT_CTI1_TG2            89
#define IMX_INT_SJC                 90
#define IMX_INT_RESV2               91
#define IMX_INT_TVE                 92
#define IMX_INT_FIRI                93
#define IMX_INT_PWM2                94
#define IMX_INT_RESV3               95
#define IMX_INT_SSI3                96
#define IMX_INT_RESV4               97
#define IMX_INT_CTI1_TG3            98
#define IMX_INT_RESV5               99
#define IMX_INT_VPU_IDLE            100
#define IMX_INT_EMI_NFC_AUTOPROG    101
#define IMX_INT_GPU_IDLE            102
#define IMX_INT_GPIO5_LOW           103
#define IMX_INT_GPIO5_HIGH          104
#define IMX_INT_GPIO6_LOW           105
#define IMX_INT_GPIO6_HIGH          106
#define IMX_INT_GPIO7_LOW           107
#define IMX_INT_GPIO7_HIGH          108
#endif //_SOC_MEMORY_MAP_H
