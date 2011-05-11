/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef _SOC_MEMORY_MAP_H
#define _SOC_MEMORY_MAP_H

#define BAAD_STATUS                    	0xbaadbaad
#define GOOD_STATUS                    	0x900d900d

// CPU Memory Map
#define BOOT_ROM_BASE_ADDR		0x00000000
#define ROM_SI_REV_OFFSET		    0x48
#define SCC_RAM_BASE_ADDR			0x07000000
#define TZIC_BASE_ADDR				0x0FFFC000
#define SATA_BASE_ADDR				0x10000000
#define IPU_BASE_ADDR   				0x18000000
#define OPENVG_BASE_ADDR			0x20000000
#define GPU_BASE_ADDR				0x30000000
#define DEBUG_ROM_BASE_ADDR		0x40000000
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
#define UART3_BASE_ADDR			0x5000C000
#define ECSPI1_BASE_ADDR			0x50010000
#define SSI2_BASE_ADDR				0x50014000
#define ESAI1_BASE_ADDR			0x50018000
#define ESDHC3_BASE_ADDR			0x50020000
#define ESDHC4_BASE_ADDR			0x50024000
#define SPDIF_BASE_ADDR			0x50028000
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

/*
 * Interrupt numbers
 */
#define MXC_INT_BASE                0
#define MXC_INT_RESV0               0
#define MXC_INT_MMC_SDHC1           1
#define MXC_INT_MMC_SDHC2           2
#define MXC_INT_MMC_SDHC3           3
#define MXC_INT_MMC_SDHC4           4
#define MXC_INT_DAP                 5
#define MXC_INT_SDMA                6
#define MXC_INT_IOMUX               7
#define MXC_INT_NFC                 8
#define MXC_INT_VPU                 9
#define MXC_INT_IPU_ERR				10
#define MXC_INT_IPU_SYN				11
#define MXC_INT_GPU                 12
#define MXC_INT_UART4               13
#define MXC_INT_USB_H1              14
#define MXC_INT_EMI                 15
#define MXC_INT_USB_H2              16
#define MXC_INT_USB_H3              17
#define MXC_INT_USB_OTG             18
#define MXC_INT_SAHARA_H0           19
#define MXC_INT_SAHARA_H1           20
#define MXC_INT_SCC_SMN				21
#define MXC_INT_SCC_STZ				22
#define MXC_INT_SCC_SCM				23
#define MXC_INT_SRTC_NTZ			24
#define MXC_INT_SRTC_TZ				25
#define MXC_INT_RTIC                26
#define MXC_INT_CSU                 27
#define MXC_INT_SATA                28
#define MXC_INT_SSI1                29
#define MXC_INT_SSI2                30
#define MXC_INT_UART1               31
#define MXC_INT_UART2               32
#define MXC_INT_UART3               33
#define MXC_INT_RTC_IEEE1588        34
#define MXC_INT_PTP_IEEE1588        35
#define MXC_INT_ECSPI1              36
#define MXC_INT_ECSPI2              37
#define MXC_INT_CSPI                38
#define MXC_INT_GPT                 39
#define MXC_INT_EPIT1               40
#define MXC_INT_EPIT2               41
#define MXC_INT_GPIO1_INT7          42
#define MXC_INT_GPIO1_INT6          43
#define MXC_INT_GPIO1_INT5          44
#define MXC_INT_GPIO1_INT4          45
#define MXC_INT_GPIO1_INT3          46
#define MXC_INT_GPIO1_INT2          47
#define MXC_INT_GPIO1_INT1          48
#define MXC_INT_GPIO1_INT0          49
#define MXC_INT_GPIO1_LOW           50
#define MXC_INT_GPIO1_HIGH          51
#define MXC_INT_GPIO2_LOW           52
#define MXC_INT_GPIO2_HIGH          53
#define MXC_INT_GPIO3_LOW           54
#define MXC_INT_GPIO3_HIGH          55
#define MXC_INT_GPIO4_LOW           56
#define MXC_INT_GPIO4_HIGH          57
#define MXC_INT_WDOG1               58
#define MXC_INT_WDOG2               59
#define MXC_INT_KPP                 60
#define MXC_INT_PWM1                61
#define MXC_INT_I2C1                62
#define MXC_INT_I2C2                63
#define MXC_INT_I2C3                64
#define MXC_INT_MLB                 65
#define MXC_INT_ASRC                66
#define MXC_INT_SPDIF               67
#define MXC_INT_RESV1               68
#define MXC_INT_IIM                 69
#define MXC_INT_PATA                70
#define MXC_INT_CCM1                71
#define MXC_INT_CCM2                72
#define MXC_INT_GPC1                73
#define MXC_INT_GPC2                74
#define MXC_INT_SRC                 75
#define MXC_INT_NM                  76
#define MXC_INT_PMU                 77
#define MXC_INT_CTI_IRQ             78
#define MXC_INT_CTI1_TG0            79
#define MXC_INT_CTI1_TG1            80
#define MXC_INT_ESAI1               81
#define MXC_INT_CAN1                82
#define MXC_INT_CAN2                83
#define MXC_INT_OPENVG              84
#define MXC_INT_OPENVG_BUSY         85
#define MXC_INT_UART5               86
#define MXC_INT_FEC                 87
#define MXC_INT_OWIRE               88
#define MXC_INT_CTI1_TG2            89
#define MXC_INT_SJC                 90
#define MXC_INT_RESV2               91
#define MXC_INT_TVE                 92
#define MXC_INT_FIRI                93
#define MXC_INT_PWM2                94
#define MXC_INT_RESV3               95
#define MXC_INT_SSI3                96
#define MXC_INT_RESV4               97
#define MXC_INT_CTI1_TG3            98
#define MXC_INT_RESV5               99
#define MXC_INT_VPU_IDLE            100
#define MXC_INT_EMI_NFC_AUTOPROG    101
#define MXC_INT_GPU_IDLE            102
#define MXC_INT_GPIO5_LOW           103
#define MXC_INT_GPIO5_HIGH          104
#define MXC_INT_GPIO6_LOW           105
#define MXC_INT_GPIO6_HIGH          106
#define MXC_INT_GPIO7_LOW           107
#define MXC_INT_GPIO7_HIGH          108
#endif //_SOC_MEMORY_MAP_H
