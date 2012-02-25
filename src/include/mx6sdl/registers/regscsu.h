/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CSU_H
#define _CSU_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_CSU_CSL0 - Config security level register 0
 * - HW_CSU_CSL1 - Config security level register 1
 * - HW_CSU_CSL2 - Config security level register 2
 * - HW_CSU_CSL3 - Config security level register 3
 * - HW_CSU_CSL4 - Config security level register 4
 * - HW_CSU_CSL5 - Config security level register 5
 * - HW_CSU_CSL6 - Config security level register 6
 * - HW_CSU_CSL7 - Config security level register 7
 * - HW_CSU_CSL8 - Config security level register 8
 * - HW_CSU_CSL9 - Config security level register 9
 * - HW_CSU_CSL10 - Config security level register 10
 * - HW_CSU_CSL11 - Config security level register 11
 * - HW_CSU_CSL12 - Config security level register 12
 * - HW_CSU_CSL13 - Config security level register 13
 * - HW_CSU_CSL14 - Config security level register 14
 * - HW_CSU_CSL15 - Config security level register 15
 * - HW_CSU_CSL16 - Config security level register 16
 * - HW_CSU_CSL17 - Config security level register 17
 * - HW_CSU_CSL18 - Config security level register 18
 * - HW_CSU_CSL19 - Config security level register 19
 * - HW_CSU_CSL20 - Config security level register 20
 * - HW_CSU_CSL21 - Config security level register 21
 * - HW_CSU_CSL22 - Config security level register 22
 * - HW_CSU_CSL23 - Config security level register 23
 * - HW_CSU_CSL24 - Config security level register 24
 * - HW_CSU_CSL25 - Config security level register 25
 * - HW_CSU_CSL26 - Config security level register 26
 * - HW_CSU_CSL27 - Config security level register 27
 * - HW_CSU_CSL28 - Config security level register 28
 * - HW_CSU_CSL29 - Config security level register 29
 * - HW_CSU_CSL30 - Config security level register 30
 * - HW_CSU_CSL31 - Config security level register 31
 * - HW_CSU_CSL32 - Config security level register 32
 * - HW_CSU_CSL33 - Config security level register 33
 * - HW_CSU_CSL34 - Config security level register 34
 * - HW_CSU_CSL35 - Config security level register 35
 * - HW_CSU_CSL36 - Config security level register 36
 * - HW_CSU_CSL37 - Config security level register 37
 * - HW_CSU_CSL38 - Config security level register 38
 * - HW_CSU_CSL39 - Config security level register 39
 * - HW_CSU_HP0 - HP0 register
 * - HW_CSU_HP1 - HP1 register
 * - HW_CSU_SA - Secure access register
 * - HW_CSU_HPCONTROL0 - HPCONTROL0 register
 * - HW_CSU_HPCONTROL1 - HPCONTROL1 register
 *
 * hw_csu_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_CSU_BASE
#define REGS_CSU_BASE (0x021c0000) //!< Base address for CSU.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL0 - Config security level register 0 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl0_t;
#endif

/*
 * constants & macros for entire CSU_CSL0 register
 */
#define HW_CSU_CSL0_ADDR      (REGS_CSU_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL0           (*(volatile hw_csu_csl0_t *) HW_CSU_CSL0_ADDR)
#define HW_CSU_CSL0_RD()      (HW_CSU_CSL0.U)
#define HW_CSU_CSL0_WR(v)     (HW_CSU_CSL0.U = (v))
#define HW_CSU_CSL0_SET(v)    (HW_CSU_CSL0_WR(HW_CSU_CSL0_RD() |  (v)))
#define HW_CSU_CSL0_CLR(v)    (HW_CSU_CSL0_WR(HW_CSU_CSL0_RD() & ~(v)))
#define HW_CSU_CSL0_TOG(v)    (HW_CSU_CSL0_WR(HW_CSU_CSL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL0 bitfields
 */

/* --- Register HW_CSU_CSL0, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL0_SUR_S2      (0)
#define BM_CSU_CSL0_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL0_SUR_S2)
#else
#define BF_CSU_CSL0_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL0_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL0_SUR_S2(v)   BF_CS1(CSU_CSL0, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL0_SSR_S2      (1)
#define BM_CSU_CSL0_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL0_SSR_S2)
#else
#define BF_CSU_CSL0_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL0_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL0_SSR_S2(v)   BF_CS1(CSU_CSL0, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL0_NUR_S2      (2)
#define BM_CSU_CSL0_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL0_NUR_S2)
#else
#define BF_CSU_CSL0_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL0_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL0_NUR_S2(v)   BF_CS1(CSU_CSL0, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL0_NSR_S2      (3)
#define BM_CSU_CSL0_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL0_NSR_S2)
#else
#define BF_CSU_CSL0_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL0_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL0_NSR_S2(v)   BF_CS1(CSU_CSL0, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL0_SUW_S2      (4)
#define BM_CSU_CSL0_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL0_SUW_S2)
#else
#define BF_CSU_CSL0_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL0_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL0_SUW_S2(v)   BF_CS1(CSU_CSL0, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL0_SSW_S2      (5)
#define BM_CSU_CSL0_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL0_SSW_S2)
#else
#define BF_CSU_CSL0_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL0_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL0_SSW_S2(v)   BF_CS1(CSU_CSL0, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL0_NUW_S2      (6)
#define BM_CSU_CSL0_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL0_NUW_S2)
#else
#define BF_CSU_CSL0_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL0_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL0_NUW_S2(v)   BF_CS1(CSU_CSL0, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL0_NSW_S2      (7)
#define BM_CSU_CSL0_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL0_NSW_S2)
#else
#define BF_CSU_CSL0_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL0_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL0_NSW_S2(v)   BF_CS1(CSU_CSL0, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL0_LOCK_S2      (8)
#define BM_CSU_CSL0_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL0_LOCK_S2)
#else
#define BF_CSU_CSL0_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL0_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL0_LOCK_S2(v)   BF_CS1(CSU_CSL0, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL0, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL0_SUR_S1      (16)
#define BM_CSU_CSL0_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL0_SUR_S1)
#else
#define BF_CSU_CSL0_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL0_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL0_SUR_S1(v)   BF_CS1(CSU_CSL0, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL0, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL0_SSR_S1      (17)
#define BM_CSU_CSL0_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL0_SSR_S1)
#else
#define BF_CSU_CSL0_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL0_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL0_SSR_S1(v)   BF_CS1(CSU_CSL0, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL0, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL0_NUR_S1      (18)
#define BM_CSU_CSL0_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL0_NUR_S1)
#else
#define BF_CSU_CSL0_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL0_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL0_NUR_S1(v)   BF_CS1(CSU_CSL0, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL0, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL0_NSR_S1      (19)
#define BM_CSU_CSL0_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL0_NSR_S1)
#else
#define BF_CSU_CSL0_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL0_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL0_NSR_S1(v)   BF_CS1(CSU_CSL0, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL0, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL0_SUW_S1      (20)
#define BM_CSU_CSL0_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL0_SUW_S1)
#else
#define BF_CSU_CSL0_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL0_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL0_SUW_S1(v)   BF_CS1(CSU_CSL0, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL0, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL0_SSW_S1      (21)
#define BM_CSU_CSL0_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL0_SSW_S1)
#else
#define BF_CSU_CSL0_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL0_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL0_SSW_S1(v)   BF_CS1(CSU_CSL0, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL0, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL0_NUW_S1      (22)
#define BM_CSU_CSL0_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL0_NUW_S1)
#else
#define BF_CSU_CSL0_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL0_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL0_NUW_S1(v)   BF_CS1(CSU_CSL0, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL0, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL0_NSW_S1      (23)
#define BM_CSU_CSL0_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL0_NSW_S1)
#else
#define BF_CSU_CSL0_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL0_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL0_NSW_S1(v)   BF_CS1(CSU_CSL0, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL0, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL0_LOCK_S1      (24)
#define BM_CSU_CSL0_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL0_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL0_LOCK_S1)
#else
#define BF_CSU_CSL0_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL0_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL0_LOCK_S1(v)   BF_CS1(CSU_CSL0, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL1 - Config security level register 1 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl1_t;
#endif

/*
 * constants & macros for entire CSU_CSL1 register
 */
#define HW_CSU_CSL1_ADDR      (REGS_CSU_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL1           (*(volatile hw_csu_csl1_t *) HW_CSU_CSL1_ADDR)
#define HW_CSU_CSL1_RD()      (HW_CSU_CSL1.U)
#define HW_CSU_CSL1_WR(v)     (HW_CSU_CSL1.U = (v))
#define HW_CSU_CSL1_SET(v)    (HW_CSU_CSL1_WR(HW_CSU_CSL1_RD() |  (v)))
#define HW_CSU_CSL1_CLR(v)    (HW_CSU_CSL1_WR(HW_CSU_CSL1_RD() & ~(v)))
#define HW_CSU_CSL1_TOG(v)    (HW_CSU_CSL1_WR(HW_CSU_CSL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL1 bitfields
 */

/* --- Register HW_CSU_CSL1, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL1_SUR_S2      (0)
#define BM_CSU_CSL1_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL1_SUR_S2)
#else
#define BF_CSU_CSL1_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL1_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL1_SUR_S2(v)   BF_CS1(CSU_CSL1, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL1_SSR_S2      (1)
#define BM_CSU_CSL1_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL1_SSR_S2)
#else
#define BF_CSU_CSL1_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL1_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL1_SSR_S2(v)   BF_CS1(CSU_CSL1, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL1_NUR_S2      (2)
#define BM_CSU_CSL1_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL1_NUR_S2)
#else
#define BF_CSU_CSL1_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL1_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL1_NUR_S2(v)   BF_CS1(CSU_CSL1, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL1_NSR_S2      (3)
#define BM_CSU_CSL1_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL1_NSR_S2)
#else
#define BF_CSU_CSL1_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL1_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL1_NSR_S2(v)   BF_CS1(CSU_CSL1, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL1_SUW_S2      (4)
#define BM_CSU_CSL1_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL1_SUW_S2)
#else
#define BF_CSU_CSL1_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL1_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL1_SUW_S2(v)   BF_CS1(CSU_CSL1, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL1_SSW_S2      (5)
#define BM_CSU_CSL1_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL1_SSW_S2)
#else
#define BF_CSU_CSL1_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL1_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL1_SSW_S2(v)   BF_CS1(CSU_CSL1, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL1_NUW_S2      (6)
#define BM_CSU_CSL1_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL1_NUW_S2)
#else
#define BF_CSU_CSL1_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL1_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL1_NUW_S2(v)   BF_CS1(CSU_CSL1, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL1_NSW_S2      (7)
#define BM_CSU_CSL1_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL1_NSW_S2)
#else
#define BF_CSU_CSL1_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL1_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL1_NSW_S2(v)   BF_CS1(CSU_CSL1, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL1_LOCK_S2      (8)
#define BM_CSU_CSL1_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL1_LOCK_S2)
#else
#define BF_CSU_CSL1_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL1_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL1_LOCK_S2(v)   BF_CS1(CSU_CSL1, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL1, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL1_SUR_S1      (16)
#define BM_CSU_CSL1_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL1_SUR_S1)
#else
#define BF_CSU_CSL1_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL1_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL1_SUR_S1(v)   BF_CS1(CSU_CSL1, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL1, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL1_SSR_S1      (17)
#define BM_CSU_CSL1_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL1_SSR_S1)
#else
#define BF_CSU_CSL1_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL1_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL1_SSR_S1(v)   BF_CS1(CSU_CSL1, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL1, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL1_NUR_S1      (18)
#define BM_CSU_CSL1_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL1_NUR_S1)
#else
#define BF_CSU_CSL1_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL1_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL1_NUR_S1(v)   BF_CS1(CSU_CSL1, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL1, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL1_NSR_S1      (19)
#define BM_CSU_CSL1_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL1_NSR_S1)
#else
#define BF_CSU_CSL1_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL1_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL1_NSR_S1(v)   BF_CS1(CSU_CSL1, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL1, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL1_SUW_S1      (20)
#define BM_CSU_CSL1_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL1_SUW_S1)
#else
#define BF_CSU_CSL1_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL1_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL1_SUW_S1(v)   BF_CS1(CSU_CSL1, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL1, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL1_SSW_S1      (21)
#define BM_CSU_CSL1_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL1_SSW_S1)
#else
#define BF_CSU_CSL1_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL1_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL1_SSW_S1(v)   BF_CS1(CSU_CSL1, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL1, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL1_NUW_S1      (22)
#define BM_CSU_CSL1_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL1_NUW_S1)
#else
#define BF_CSU_CSL1_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL1_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL1_NUW_S1(v)   BF_CS1(CSU_CSL1, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL1, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL1_NSW_S1      (23)
#define BM_CSU_CSL1_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL1_NSW_S1)
#else
#define BF_CSU_CSL1_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL1_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL1_NSW_S1(v)   BF_CS1(CSU_CSL1, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL1, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL1_LOCK_S1      (24)
#define BM_CSU_CSL1_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL1_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL1_LOCK_S1)
#else
#define BF_CSU_CSL1_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL1_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL1_LOCK_S1(v)   BF_CS1(CSU_CSL1, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL2 - Config security level register 2 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl2_t;
#endif

/*
 * constants & macros for entire CSU_CSL2 register
 */
#define HW_CSU_CSL2_ADDR      (REGS_CSU_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL2           (*(volatile hw_csu_csl2_t *) HW_CSU_CSL2_ADDR)
#define HW_CSU_CSL2_RD()      (HW_CSU_CSL2.U)
#define HW_CSU_CSL2_WR(v)     (HW_CSU_CSL2.U = (v))
#define HW_CSU_CSL2_SET(v)    (HW_CSU_CSL2_WR(HW_CSU_CSL2_RD() |  (v)))
#define HW_CSU_CSL2_CLR(v)    (HW_CSU_CSL2_WR(HW_CSU_CSL2_RD() & ~(v)))
#define HW_CSU_CSL2_TOG(v)    (HW_CSU_CSL2_WR(HW_CSU_CSL2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL2 bitfields
 */

/* --- Register HW_CSU_CSL2, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL2_SUR_S2      (0)
#define BM_CSU_CSL2_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL2_SUR_S2)
#else
#define BF_CSU_CSL2_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL2_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL2_SUR_S2(v)   BF_CS1(CSU_CSL2, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL2_SSR_S2      (1)
#define BM_CSU_CSL2_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL2_SSR_S2)
#else
#define BF_CSU_CSL2_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL2_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL2_SSR_S2(v)   BF_CS1(CSU_CSL2, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL2_NUR_S2      (2)
#define BM_CSU_CSL2_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL2_NUR_S2)
#else
#define BF_CSU_CSL2_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL2_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL2_NUR_S2(v)   BF_CS1(CSU_CSL2, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL2_NSR_S2      (3)
#define BM_CSU_CSL2_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL2_NSR_S2)
#else
#define BF_CSU_CSL2_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL2_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL2_NSR_S2(v)   BF_CS1(CSU_CSL2, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL2_SUW_S2      (4)
#define BM_CSU_CSL2_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL2_SUW_S2)
#else
#define BF_CSU_CSL2_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL2_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL2_SUW_S2(v)   BF_CS1(CSU_CSL2, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL2_SSW_S2      (5)
#define BM_CSU_CSL2_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL2_SSW_S2)
#else
#define BF_CSU_CSL2_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL2_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL2_SSW_S2(v)   BF_CS1(CSU_CSL2, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL2_NUW_S2      (6)
#define BM_CSU_CSL2_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL2_NUW_S2)
#else
#define BF_CSU_CSL2_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL2_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL2_NUW_S2(v)   BF_CS1(CSU_CSL2, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL2_NSW_S2      (7)
#define BM_CSU_CSL2_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL2_NSW_S2)
#else
#define BF_CSU_CSL2_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL2_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL2_NSW_S2(v)   BF_CS1(CSU_CSL2, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL2_LOCK_S2      (8)
#define BM_CSU_CSL2_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL2_LOCK_S2)
#else
#define BF_CSU_CSL2_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL2_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL2_LOCK_S2(v)   BF_CS1(CSU_CSL2, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL2, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL2_SUR_S1      (16)
#define BM_CSU_CSL2_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL2_SUR_S1)
#else
#define BF_CSU_CSL2_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL2_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL2_SUR_S1(v)   BF_CS1(CSU_CSL2, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL2, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL2_SSR_S1      (17)
#define BM_CSU_CSL2_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL2_SSR_S1)
#else
#define BF_CSU_CSL2_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL2_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL2_SSR_S1(v)   BF_CS1(CSU_CSL2, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL2, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL2_NUR_S1      (18)
#define BM_CSU_CSL2_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL2_NUR_S1)
#else
#define BF_CSU_CSL2_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL2_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL2_NUR_S1(v)   BF_CS1(CSU_CSL2, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL2, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL2_NSR_S1      (19)
#define BM_CSU_CSL2_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL2_NSR_S1)
#else
#define BF_CSU_CSL2_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL2_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL2_NSR_S1(v)   BF_CS1(CSU_CSL2, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL2, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL2_SUW_S1      (20)
#define BM_CSU_CSL2_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL2_SUW_S1)
#else
#define BF_CSU_CSL2_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL2_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL2_SUW_S1(v)   BF_CS1(CSU_CSL2, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL2, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL2_SSW_S1      (21)
#define BM_CSU_CSL2_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL2_SSW_S1)
#else
#define BF_CSU_CSL2_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL2_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL2_SSW_S1(v)   BF_CS1(CSU_CSL2, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL2, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL2_NUW_S1      (22)
#define BM_CSU_CSL2_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL2_NUW_S1)
#else
#define BF_CSU_CSL2_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL2_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL2_NUW_S1(v)   BF_CS1(CSU_CSL2, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL2, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL2_NSW_S1      (23)
#define BM_CSU_CSL2_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL2_NSW_S1)
#else
#define BF_CSU_CSL2_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL2_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL2_NSW_S1(v)   BF_CS1(CSU_CSL2, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL2, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL2_LOCK_S1      (24)
#define BM_CSU_CSL2_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL2_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL2_LOCK_S1)
#else
#define BF_CSU_CSL2_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL2_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL2_LOCK_S1(v)   BF_CS1(CSU_CSL2, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL3 - Config security level register 3 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl3_t;
#endif

/*
 * constants & macros for entire CSU_CSL3 register
 */
#define HW_CSU_CSL3_ADDR      (REGS_CSU_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL3           (*(volatile hw_csu_csl3_t *) HW_CSU_CSL3_ADDR)
#define HW_CSU_CSL3_RD()      (HW_CSU_CSL3.U)
#define HW_CSU_CSL3_WR(v)     (HW_CSU_CSL3.U = (v))
#define HW_CSU_CSL3_SET(v)    (HW_CSU_CSL3_WR(HW_CSU_CSL3_RD() |  (v)))
#define HW_CSU_CSL3_CLR(v)    (HW_CSU_CSL3_WR(HW_CSU_CSL3_RD() & ~(v)))
#define HW_CSU_CSL3_TOG(v)    (HW_CSU_CSL3_WR(HW_CSU_CSL3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL3 bitfields
 */

/* --- Register HW_CSU_CSL3, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL3_SUR_S2      (0)
#define BM_CSU_CSL3_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL3_SUR_S2)
#else
#define BF_CSU_CSL3_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL3_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL3_SUR_S2(v)   BF_CS1(CSU_CSL3, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL3_SSR_S2      (1)
#define BM_CSU_CSL3_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL3_SSR_S2)
#else
#define BF_CSU_CSL3_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL3_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL3_SSR_S2(v)   BF_CS1(CSU_CSL3, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL3_NUR_S2      (2)
#define BM_CSU_CSL3_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL3_NUR_S2)
#else
#define BF_CSU_CSL3_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL3_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL3_NUR_S2(v)   BF_CS1(CSU_CSL3, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL3_NSR_S2      (3)
#define BM_CSU_CSL3_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL3_NSR_S2)
#else
#define BF_CSU_CSL3_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL3_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL3_NSR_S2(v)   BF_CS1(CSU_CSL3, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL3_SUW_S2      (4)
#define BM_CSU_CSL3_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL3_SUW_S2)
#else
#define BF_CSU_CSL3_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL3_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL3_SUW_S2(v)   BF_CS1(CSU_CSL3, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL3_SSW_S2      (5)
#define BM_CSU_CSL3_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL3_SSW_S2)
#else
#define BF_CSU_CSL3_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL3_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL3_SSW_S2(v)   BF_CS1(CSU_CSL3, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL3_NUW_S2      (6)
#define BM_CSU_CSL3_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL3_NUW_S2)
#else
#define BF_CSU_CSL3_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL3_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL3_NUW_S2(v)   BF_CS1(CSU_CSL3, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL3_NSW_S2      (7)
#define BM_CSU_CSL3_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL3_NSW_S2)
#else
#define BF_CSU_CSL3_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL3_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL3_NSW_S2(v)   BF_CS1(CSU_CSL3, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL3_LOCK_S2      (8)
#define BM_CSU_CSL3_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL3_LOCK_S2)
#else
#define BF_CSU_CSL3_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL3_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL3_LOCK_S2(v)   BF_CS1(CSU_CSL3, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL3, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL3_SUR_S1      (16)
#define BM_CSU_CSL3_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL3_SUR_S1)
#else
#define BF_CSU_CSL3_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL3_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL3_SUR_S1(v)   BF_CS1(CSU_CSL3, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL3, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL3_SSR_S1      (17)
#define BM_CSU_CSL3_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL3_SSR_S1)
#else
#define BF_CSU_CSL3_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL3_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL3_SSR_S1(v)   BF_CS1(CSU_CSL3, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL3, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL3_NUR_S1      (18)
#define BM_CSU_CSL3_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL3_NUR_S1)
#else
#define BF_CSU_CSL3_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL3_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL3_NUR_S1(v)   BF_CS1(CSU_CSL3, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL3, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL3_NSR_S1      (19)
#define BM_CSU_CSL3_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL3_NSR_S1)
#else
#define BF_CSU_CSL3_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL3_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL3_NSR_S1(v)   BF_CS1(CSU_CSL3, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL3, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL3_SUW_S1      (20)
#define BM_CSU_CSL3_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL3_SUW_S1)
#else
#define BF_CSU_CSL3_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL3_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL3_SUW_S1(v)   BF_CS1(CSU_CSL3, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL3, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL3_SSW_S1      (21)
#define BM_CSU_CSL3_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL3_SSW_S1)
#else
#define BF_CSU_CSL3_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL3_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL3_SSW_S1(v)   BF_CS1(CSU_CSL3, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL3, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL3_NUW_S1      (22)
#define BM_CSU_CSL3_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL3_NUW_S1)
#else
#define BF_CSU_CSL3_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL3_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL3_NUW_S1(v)   BF_CS1(CSU_CSL3, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL3, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL3_NSW_S1      (23)
#define BM_CSU_CSL3_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL3_NSW_S1)
#else
#define BF_CSU_CSL3_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL3_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL3_NSW_S1(v)   BF_CS1(CSU_CSL3, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL3, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL3_LOCK_S1      (24)
#define BM_CSU_CSL3_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL3_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL3_LOCK_S1)
#else
#define BF_CSU_CSL3_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL3_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL3_LOCK_S1(v)   BF_CS1(CSU_CSL3, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL4 - Config security level register 4 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl4_t;
#endif

/*
 * constants & macros for entire CSU_CSL4 register
 */
#define HW_CSU_CSL4_ADDR      (REGS_CSU_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL4           (*(volatile hw_csu_csl4_t *) HW_CSU_CSL4_ADDR)
#define HW_CSU_CSL4_RD()      (HW_CSU_CSL4.U)
#define HW_CSU_CSL4_WR(v)     (HW_CSU_CSL4.U = (v))
#define HW_CSU_CSL4_SET(v)    (HW_CSU_CSL4_WR(HW_CSU_CSL4_RD() |  (v)))
#define HW_CSU_CSL4_CLR(v)    (HW_CSU_CSL4_WR(HW_CSU_CSL4_RD() & ~(v)))
#define HW_CSU_CSL4_TOG(v)    (HW_CSU_CSL4_WR(HW_CSU_CSL4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL4 bitfields
 */

/* --- Register HW_CSU_CSL4, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL4_SUR_S2      (0)
#define BM_CSU_CSL4_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL4_SUR_S2)
#else
#define BF_CSU_CSL4_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL4_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL4_SUR_S2(v)   BF_CS1(CSU_CSL4, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL4_SSR_S2      (1)
#define BM_CSU_CSL4_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL4_SSR_S2)
#else
#define BF_CSU_CSL4_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL4_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL4_SSR_S2(v)   BF_CS1(CSU_CSL4, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL4_NUR_S2      (2)
#define BM_CSU_CSL4_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL4_NUR_S2)
#else
#define BF_CSU_CSL4_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL4_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL4_NUR_S2(v)   BF_CS1(CSU_CSL4, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL4_NSR_S2      (3)
#define BM_CSU_CSL4_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL4_NSR_S2)
#else
#define BF_CSU_CSL4_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL4_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL4_NSR_S2(v)   BF_CS1(CSU_CSL4, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL4_SUW_S2      (4)
#define BM_CSU_CSL4_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL4_SUW_S2)
#else
#define BF_CSU_CSL4_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL4_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL4_SUW_S2(v)   BF_CS1(CSU_CSL4, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL4_SSW_S2      (5)
#define BM_CSU_CSL4_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL4_SSW_S2)
#else
#define BF_CSU_CSL4_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL4_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL4_SSW_S2(v)   BF_CS1(CSU_CSL4, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL4_NUW_S2      (6)
#define BM_CSU_CSL4_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL4_NUW_S2)
#else
#define BF_CSU_CSL4_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL4_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL4_NUW_S2(v)   BF_CS1(CSU_CSL4, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL4_NSW_S2      (7)
#define BM_CSU_CSL4_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL4_NSW_S2)
#else
#define BF_CSU_CSL4_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL4_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL4_NSW_S2(v)   BF_CS1(CSU_CSL4, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL4_LOCK_S2      (8)
#define BM_CSU_CSL4_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL4_LOCK_S2)
#else
#define BF_CSU_CSL4_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL4_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL4_LOCK_S2(v)   BF_CS1(CSU_CSL4, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL4, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL4_SUR_S1      (16)
#define BM_CSU_CSL4_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL4_SUR_S1)
#else
#define BF_CSU_CSL4_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL4_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL4_SUR_S1(v)   BF_CS1(CSU_CSL4, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL4, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL4_SSR_S1      (17)
#define BM_CSU_CSL4_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL4_SSR_S1)
#else
#define BF_CSU_CSL4_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL4_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL4_SSR_S1(v)   BF_CS1(CSU_CSL4, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL4, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL4_NUR_S1      (18)
#define BM_CSU_CSL4_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL4_NUR_S1)
#else
#define BF_CSU_CSL4_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL4_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL4_NUR_S1(v)   BF_CS1(CSU_CSL4, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL4, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL4_NSR_S1      (19)
#define BM_CSU_CSL4_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL4_NSR_S1)
#else
#define BF_CSU_CSL4_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL4_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL4_NSR_S1(v)   BF_CS1(CSU_CSL4, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL4, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL4_SUW_S1      (20)
#define BM_CSU_CSL4_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL4_SUW_S1)
#else
#define BF_CSU_CSL4_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL4_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL4_SUW_S1(v)   BF_CS1(CSU_CSL4, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL4, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL4_SSW_S1      (21)
#define BM_CSU_CSL4_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL4_SSW_S1)
#else
#define BF_CSU_CSL4_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL4_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL4_SSW_S1(v)   BF_CS1(CSU_CSL4, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL4, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL4_NUW_S1      (22)
#define BM_CSU_CSL4_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL4_NUW_S1)
#else
#define BF_CSU_CSL4_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL4_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL4_NUW_S1(v)   BF_CS1(CSU_CSL4, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL4, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL4_NSW_S1      (23)
#define BM_CSU_CSL4_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL4_NSW_S1)
#else
#define BF_CSU_CSL4_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL4_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL4_NSW_S1(v)   BF_CS1(CSU_CSL4, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL4, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL4_LOCK_S1      (24)
#define BM_CSU_CSL4_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL4_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL4_LOCK_S1)
#else
#define BF_CSU_CSL4_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL4_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL4_LOCK_S1(v)   BF_CS1(CSU_CSL4, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL5 - Config security level register 5 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl5_t;
#endif

/*
 * constants & macros for entire CSU_CSL5 register
 */
#define HW_CSU_CSL5_ADDR      (REGS_CSU_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL5           (*(volatile hw_csu_csl5_t *) HW_CSU_CSL5_ADDR)
#define HW_CSU_CSL5_RD()      (HW_CSU_CSL5.U)
#define HW_CSU_CSL5_WR(v)     (HW_CSU_CSL5.U = (v))
#define HW_CSU_CSL5_SET(v)    (HW_CSU_CSL5_WR(HW_CSU_CSL5_RD() |  (v)))
#define HW_CSU_CSL5_CLR(v)    (HW_CSU_CSL5_WR(HW_CSU_CSL5_RD() & ~(v)))
#define HW_CSU_CSL5_TOG(v)    (HW_CSU_CSL5_WR(HW_CSU_CSL5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL5 bitfields
 */

/* --- Register HW_CSU_CSL5, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL5_SUR_S2      (0)
#define BM_CSU_CSL5_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL5_SUR_S2)
#else
#define BF_CSU_CSL5_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL5_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL5_SUR_S2(v)   BF_CS1(CSU_CSL5, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL5_SSR_S2      (1)
#define BM_CSU_CSL5_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL5_SSR_S2)
#else
#define BF_CSU_CSL5_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL5_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL5_SSR_S2(v)   BF_CS1(CSU_CSL5, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL5_NUR_S2      (2)
#define BM_CSU_CSL5_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL5_NUR_S2)
#else
#define BF_CSU_CSL5_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL5_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL5_NUR_S2(v)   BF_CS1(CSU_CSL5, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL5_NSR_S2      (3)
#define BM_CSU_CSL5_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL5_NSR_S2)
#else
#define BF_CSU_CSL5_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL5_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL5_NSR_S2(v)   BF_CS1(CSU_CSL5, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL5_SUW_S2      (4)
#define BM_CSU_CSL5_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL5_SUW_S2)
#else
#define BF_CSU_CSL5_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL5_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL5_SUW_S2(v)   BF_CS1(CSU_CSL5, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL5_SSW_S2      (5)
#define BM_CSU_CSL5_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL5_SSW_S2)
#else
#define BF_CSU_CSL5_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL5_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL5_SSW_S2(v)   BF_CS1(CSU_CSL5, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL5_NUW_S2      (6)
#define BM_CSU_CSL5_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL5_NUW_S2)
#else
#define BF_CSU_CSL5_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL5_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL5_NUW_S2(v)   BF_CS1(CSU_CSL5, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL5_NSW_S2      (7)
#define BM_CSU_CSL5_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL5_NSW_S2)
#else
#define BF_CSU_CSL5_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL5_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL5_NSW_S2(v)   BF_CS1(CSU_CSL5, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL5_LOCK_S2      (8)
#define BM_CSU_CSL5_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL5_LOCK_S2)
#else
#define BF_CSU_CSL5_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL5_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL5_LOCK_S2(v)   BF_CS1(CSU_CSL5, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL5, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL5_SUR_S1      (16)
#define BM_CSU_CSL5_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL5_SUR_S1)
#else
#define BF_CSU_CSL5_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL5_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL5_SUR_S1(v)   BF_CS1(CSU_CSL5, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL5, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL5_SSR_S1      (17)
#define BM_CSU_CSL5_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL5_SSR_S1)
#else
#define BF_CSU_CSL5_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL5_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL5_SSR_S1(v)   BF_CS1(CSU_CSL5, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL5, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL5_NUR_S1      (18)
#define BM_CSU_CSL5_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL5_NUR_S1)
#else
#define BF_CSU_CSL5_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL5_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL5_NUR_S1(v)   BF_CS1(CSU_CSL5, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL5, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL5_NSR_S1      (19)
#define BM_CSU_CSL5_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL5_NSR_S1)
#else
#define BF_CSU_CSL5_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL5_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL5_NSR_S1(v)   BF_CS1(CSU_CSL5, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL5, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL5_SUW_S1      (20)
#define BM_CSU_CSL5_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL5_SUW_S1)
#else
#define BF_CSU_CSL5_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL5_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL5_SUW_S1(v)   BF_CS1(CSU_CSL5, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL5, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL5_SSW_S1      (21)
#define BM_CSU_CSL5_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL5_SSW_S1)
#else
#define BF_CSU_CSL5_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL5_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL5_SSW_S1(v)   BF_CS1(CSU_CSL5, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL5, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL5_NUW_S1      (22)
#define BM_CSU_CSL5_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL5_NUW_S1)
#else
#define BF_CSU_CSL5_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL5_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL5_NUW_S1(v)   BF_CS1(CSU_CSL5, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL5, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL5_NSW_S1      (23)
#define BM_CSU_CSL5_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL5_NSW_S1)
#else
#define BF_CSU_CSL5_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL5_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL5_NSW_S1(v)   BF_CS1(CSU_CSL5, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL5, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL5_LOCK_S1      (24)
#define BM_CSU_CSL5_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL5_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL5_LOCK_S1)
#else
#define BF_CSU_CSL5_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL5_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL5_LOCK_S1(v)   BF_CS1(CSU_CSL5, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL6 - Config security level register 6 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl6_t;
#endif

/*
 * constants & macros for entire CSU_CSL6 register
 */
#define HW_CSU_CSL6_ADDR      (REGS_CSU_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL6           (*(volatile hw_csu_csl6_t *) HW_CSU_CSL6_ADDR)
#define HW_CSU_CSL6_RD()      (HW_CSU_CSL6.U)
#define HW_CSU_CSL6_WR(v)     (HW_CSU_CSL6.U = (v))
#define HW_CSU_CSL6_SET(v)    (HW_CSU_CSL6_WR(HW_CSU_CSL6_RD() |  (v)))
#define HW_CSU_CSL6_CLR(v)    (HW_CSU_CSL6_WR(HW_CSU_CSL6_RD() & ~(v)))
#define HW_CSU_CSL6_TOG(v)    (HW_CSU_CSL6_WR(HW_CSU_CSL6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL6 bitfields
 */

/* --- Register HW_CSU_CSL6, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL6_SUR_S2      (0)
#define BM_CSU_CSL6_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL6_SUR_S2)
#else
#define BF_CSU_CSL6_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL6_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL6_SUR_S2(v)   BF_CS1(CSU_CSL6, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL6_SSR_S2      (1)
#define BM_CSU_CSL6_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL6_SSR_S2)
#else
#define BF_CSU_CSL6_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL6_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL6_SSR_S2(v)   BF_CS1(CSU_CSL6, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL6_NUR_S2      (2)
#define BM_CSU_CSL6_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL6_NUR_S2)
#else
#define BF_CSU_CSL6_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL6_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL6_NUR_S2(v)   BF_CS1(CSU_CSL6, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL6_NSR_S2      (3)
#define BM_CSU_CSL6_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL6_NSR_S2)
#else
#define BF_CSU_CSL6_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL6_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL6_NSR_S2(v)   BF_CS1(CSU_CSL6, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL6_SUW_S2      (4)
#define BM_CSU_CSL6_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL6_SUW_S2)
#else
#define BF_CSU_CSL6_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL6_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL6_SUW_S2(v)   BF_CS1(CSU_CSL6, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL6_SSW_S2      (5)
#define BM_CSU_CSL6_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL6_SSW_S2)
#else
#define BF_CSU_CSL6_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL6_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL6_SSW_S2(v)   BF_CS1(CSU_CSL6, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL6_NUW_S2      (6)
#define BM_CSU_CSL6_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL6_NUW_S2)
#else
#define BF_CSU_CSL6_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL6_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL6_NUW_S2(v)   BF_CS1(CSU_CSL6, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL6_NSW_S2      (7)
#define BM_CSU_CSL6_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL6_NSW_S2)
#else
#define BF_CSU_CSL6_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL6_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL6_NSW_S2(v)   BF_CS1(CSU_CSL6, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL6_LOCK_S2      (8)
#define BM_CSU_CSL6_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL6_LOCK_S2)
#else
#define BF_CSU_CSL6_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL6_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL6_LOCK_S2(v)   BF_CS1(CSU_CSL6, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL6, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL6_SUR_S1      (16)
#define BM_CSU_CSL6_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL6_SUR_S1)
#else
#define BF_CSU_CSL6_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL6_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL6_SUR_S1(v)   BF_CS1(CSU_CSL6, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL6, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL6_SSR_S1      (17)
#define BM_CSU_CSL6_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL6_SSR_S1)
#else
#define BF_CSU_CSL6_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL6_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL6_SSR_S1(v)   BF_CS1(CSU_CSL6, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL6, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL6_NUR_S1      (18)
#define BM_CSU_CSL6_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL6_NUR_S1)
#else
#define BF_CSU_CSL6_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL6_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL6_NUR_S1(v)   BF_CS1(CSU_CSL6, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL6, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL6_NSR_S1      (19)
#define BM_CSU_CSL6_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL6_NSR_S1)
#else
#define BF_CSU_CSL6_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL6_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL6_NSR_S1(v)   BF_CS1(CSU_CSL6, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL6, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL6_SUW_S1      (20)
#define BM_CSU_CSL6_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL6_SUW_S1)
#else
#define BF_CSU_CSL6_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL6_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL6_SUW_S1(v)   BF_CS1(CSU_CSL6, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL6, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL6_SSW_S1      (21)
#define BM_CSU_CSL6_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL6_SSW_S1)
#else
#define BF_CSU_CSL6_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL6_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL6_SSW_S1(v)   BF_CS1(CSU_CSL6, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL6, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL6_NUW_S1      (22)
#define BM_CSU_CSL6_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL6_NUW_S1)
#else
#define BF_CSU_CSL6_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL6_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL6_NUW_S1(v)   BF_CS1(CSU_CSL6, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL6, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL6_NSW_S1      (23)
#define BM_CSU_CSL6_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL6_NSW_S1)
#else
#define BF_CSU_CSL6_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL6_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL6_NSW_S1(v)   BF_CS1(CSU_CSL6, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL6, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL6_LOCK_S1      (24)
#define BM_CSU_CSL6_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL6_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL6_LOCK_S1)
#else
#define BF_CSU_CSL6_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL6_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL6_LOCK_S1(v)   BF_CS1(CSU_CSL6, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL7 - Config security level register 7 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl7_t;
#endif

/*
 * constants & macros for entire CSU_CSL7 register
 */
#define HW_CSU_CSL7_ADDR      (REGS_CSU_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL7           (*(volatile hw_csu_csl7_t *) HW_CSU_CSL7_ADDR)
#define HW_CSU_CSL7_RD()      (HW_CSU_CSL7.U)
#define HW_CSU_CSL7_WR(v)     (HW_CSU_CSL7.U = (v))
#define HW_CSU_CSL7_SET(v)    (HW_CSU_CSL7_WR(HW_CSU_CSL7_RD() |  (v)))
#define HW_CSU_CSL7_CLR(v)    (HW_CSU_CSL7_WR(HW_CSU_CSL7_RD() & ~(v)))
#define HW_CSU_CSL7_TOG(v)    (HW_CSU_CSL7_WR(HW_CSU_CSL7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL7 bitfields
 */

/* --- Register HW_CSU_CSL7, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL7_SUR_S2      (0)
#define BM_CSU_CSL7_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL7_SUR_S2)
#else
#define BF_CSU_CSL7_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL7_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL7_SUR_S2(v)   BF_CS1(CSU_CSL7, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL7_SSR_S2      (1)
#define BM_CSU_CSL7_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL7_SSR_S2)
#else
#define BF_CSU_CSL7_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL7_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL7_SSR_S2(v)   BF_CS1(CSU_CSL7, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL7_NUR_S2      (2)
#define BM_CSU_CSL7_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL7_NUR_S2)
#else
#define BF_CSU_CSL7_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL7_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL7_NUR_S2(v)   BF_CS1(CSU_CSL7, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL7_NSR_S2      (3)
#define BM_CSU_CSL7_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL7_NSR_S2)
#else
#define BF_CSU_CSL7_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL7_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL7_NSR_S2(v)   BF_CS1(CSU_CSL7, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL7_SUW_S2      (4)
#define BM_CSU_CSL7_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL7_SUW_S2)
#else
#define BF_CSU_CSL7_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL7_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL7_SUW_S2(v)   BF_CS1(CSU_CSL7, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL7_SSW_S2      (5)
#define BM_CSU_CSL7_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL7_SSW_S2)
#else
#define BF_CSU_CSL7_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL7_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL7_SSW_S2(v)   BF_CS1(CSU_CSL7, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL7_NUW_S2      (6)
#define BM_CSU_CSL7_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL7_NUW_S2)
#else
#define BF_CSU_CSL7_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL7_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL7_NUW_S2(v)   BF_CS1(CSU_CSL7, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL7_NSW_S2      (7)
#define BM_CSU_CSL7_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL7_NSW_S2)
#else
#define BF_CSU_CSL7_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL7_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL7_NSW_S2(v)   BF_CS1(CSU_CSL7, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL7_LOCK_S2      (8)
#define BM_CSU_CSL7_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL7_LOCK_S2)
#else
#define BF_CSU_CSL7_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL7_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL7_LOCK_S2(v)   BF_CS1(CSU_CSL7, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL7, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL7_SUR_S1      (16)
#define BM_CSU_CSL7_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL7_SUR_S1)
#else
#define BF_CSU_CSL7_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL7_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL7_SUR_S1(v)   BF_CS1(CSU_CSL7, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL7, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL7_SSR_S1      (17)
#define BM_CSU_CSL7_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL7_SSR_S1)
#else
#define BF_CSU_CSL7_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL7_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL7_SSR_S1(v)   BF_CS1(CSU_CSL7, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL7, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL7_NUR_S1      (18)
#define BM_CSU_CSL7_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL7_NUR_S1)
#else
#define BF_CSU_CSL7_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL7_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL7_NUR_S1(v)   BF_CS1(CSU_CSL7, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL7, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL7_NSR_S1      (19)
#define BM_CSU_CSL7_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL7_NSR_S1)
#else
#define BF_CSU_CSL7_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL7_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL7_NSR_S1(v)   BF_CS1(CSU_CSL7, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL7, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL7_SUW_S1      (20)
#define BM_CSU_CSL7_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL7_SUW_S1)
#else
#define BF_CSU_CSL7_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL7_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL7_SUW_S1(v)   BF_CS1(CSU_CSL7, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL7, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL7_SSW_S1      (21)
#define BM_CSU_CSL7_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL7_SSW_S1)
#else
#define BF_CSU_CSL7_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL7_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL7_SSW_S1(v)   BF_CS1(CSU_CSL7, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL7, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL7_NUW_S1      (22)
#define BM_CSU_CSL7_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL7_NUW_S1)
#else
#define BF_CSU_CSL7_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL7_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL7_NUW_S1(v)   BF_CS1(CSU_CSL7, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL7, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL7_NSW_S1      (23)
#define BM_CSU_CSL7_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL7_NSW_S1)
#else
#define BF_CSU_CSL7_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL7_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL7_NSW_S1(v)   BF_CS1(CSU_CSL7, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL7, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL7_LOCK_S1      (24)
#define BM_CSU_CSL7_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL7_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL7_LOCK_S1)
#else
#define BF_CSU_CSL7_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL7_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL7_LOCK_S1(v)   BF_CS1(CSU_CSL7, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL8 - Config security level register 8 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl8_t;
#endif

/*
 * constants & macros for entire CSU_CSL8 register
 */
#define HW_CSU_CSL8_ADDR      (REGS_CSU_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL8           (*(volatile hw_csu_csl8_t *) HW_CSU_CSL8_ADDR)
#define HW_CSU_CSL8_RD()      (HW_CSU_CSL8.U)
#define HW_CSU_CSL8_WR(v)     (HW_CSU_CSL8.U = (v))
#define HW_CSU_CSL8_SET(v)    (HW_CSU_CSL8_WR(HW_CSU_CSL8_RD() |  (v)))
#define HW_CSU_CSL8_CLR(v)    (HW_CSU_CSL8_WR(HW_CSU_CSL8_RD() & ~(v)))
#define HW_CSU_CSL8_TOG(v)    (HW_CSU_CSL8_WR(HW_CSU_CSL8_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL8 bitfields
 */

/* --- Register HW_CSU_CSL8, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL8_SUR_S2      (0)
#define BM_CSU_CSL8_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL8_SUR_S2)
#else
#define BF_CSU_CSL8_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL8_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL8_SUR_S2(v)   BF_CS1(CSU_CSL8, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL8_SSR_S2      (1)
#define BM_CSU_CSL8_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL8_SSR_S2)
#else
#define BF_CSU_CSL8_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL8_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL8_SSR_S2(v)   BF_CS1(CSU_CSL8, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL8_NUR_S2      (2)
#define BM_CSU_CSL8_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL8_NUR_S2)
#else
#define BF_CSU_CSL8_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL8_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL8_NUR_S2(v)   BF_CS1(CSU_CSL8, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL8_NSR_S2      (3)
#define BM_CSU_CSL8_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL8_NSR_S2)
#else
#define BF_CSU_CSL8_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL8_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL8_NSR_S2(v)   BF_CS1(CSU_CSL8, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL8_SUW_S2      (4)
#define BM_CSU_CSL8_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL8_SUW_S2)
#else
#define BF_CSU_CSL8_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL8_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL8_SUW_S2(v)   BF_CS1(CSU_CSL8, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL8_SSW_S2      (5)
#define BM_CSU_CSL8_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL8_SSW_S2)
#else
#define BF_CSU_CSL8_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL8_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL8_SSW_S2(v)   BF_CS1(CSU_CSL8, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL8_NUW_S2      (6)
#define BM_CSU_CSL8_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL8_NUW_S2)
#else
#define BF_CSU_CSL8_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL8_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL8_NUW_S2(v)   BF_CS1(CSU_CSL8, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL8_NSW_S2      (7)
#define BM_CSU_CSL8_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL8_NSW_S2)
#else
#define BF_CSU_CSL8_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL8_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL8_NSW_S2(v)   BF_CS1(CSU_CSL8, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL8_LOCK_S2      (8)
#define BM_CSU_CSL8_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL8_LOCK_S2)
#else
#define BF_CSU_CSL8_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL8_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL8_LOCK_S2(v)   BF_CS1(CSU_CSL8, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL8, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL8_SUR_S1      (16)
#define BM_CSU_CSL8_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL8_SUR_S1)
#else
#define BF_CSU_CSL8_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL8_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL8_SUR_S1(v)   BF_CS1(CSU_CSL8, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL8, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL8_SSR_S1      (17)
#define BM_CSU_CSL8_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL8_SSR_S1)
#else
#define BF_CSU_CSL8_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL8_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL8_SSR_S1(v)   BF_CS1(CSU_CSL8, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL8, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL8_NUR_S1      (18)
#define BM_CSU_CSL8_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL8_NUR_S1)
#else
#define BF_CSU_CSL8_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL8_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL8_NUR_S1(v)   BF_CS1(CSU_CSL8, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL8, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL8_NSR_S1      (19)
#define BM_CSU_CSL8_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL8_NSR_S1)
#else
#define BF_CSU_CSL8_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL8_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL8_NSR_S1(v)   BF_CS1(CSU_CSL8, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL8, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL8_SUW_S1      (20)
#define BM_CSU_CSL8_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL8_SUW_S1)
#else
#define BF_CSU_CSL8_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL8_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL8_SUW_S1(v)   BF_CS1(CSU_CSL8, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL8, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL8_SSW_S1      (21)
#define BM_CSU_CSL8_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL8_SSW_S1)
#else
#define BF_CSU_CSL8_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL8_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL8_SSW_S1(v)   BF_CS1(CSU_CSL8, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL8, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL8_NUW_S1      (22)
#define BM_CSU_CSL8_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL8_NUW_S1)
#else
#define BF_CSU_CSL8_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL8_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL8_NUW_S1(v)   BF_CS1(CSU_CSL8, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL8, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL8_NSW_S1      (23)
#define BM_CSU_CSL8_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL8_NSW_S1)
#else
#define BF_CSU_CSL8_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL8_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL8_NSW_S1(v)   BF_CS1(CSU_CSL8, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL8, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL8_LOCK_S1      (24)
#define BM_CSU_CSL8_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL8_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL8_LOCK_S1)
#else
#define BF_CSU_CSL8_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL8_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL8_LOCK_S1(v)   BF_CS1(CSU_CSL8, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL9 - Config security level register 9 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl9_t;
#endif

/*
 * constants & macros for entire CSU_CSL9 register
 */
#define HW_CSU_CSL9_ADDR      (REGS_CSU_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL9           (*(volatile hw_csu_csl9_t *) HW_CSU_CSL9_ADDR)
#define HW_CSU_CSL9_RD()      (HW_CSU_CSL9.U)
#define HW_CSU_CSL9_WR(v)     (HW_CSU_CSL9.U = (v))
#define HW_CSU_CSL9_SET(v)    (HW_CSU_CSL9_WR(HW_CSU_CSL9_RD() |  (v)))
#define HW_CSU_CSL9_CLR(v)    (HW_CSU_CSL9_WR(HW_CSU_CSL9_RD() & ~(v)))
#define HW_CSU_CSL9_TOG(v)    (HW_CSU_CSL9_WR(HW_CSU_CSL9_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL9 bitfields
 */

/* --- Register HW_CSU_CSL9, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL9_SUR_S2      (0)
#define BM_CSU_CSL9_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL9_SUR_S2)
#else
#define BF_CSU_CSL9_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL9_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL9_SUR_S2(v)   BF_CS1(CSU_CSL9, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL9_SSR_S2      (1)
#define BM_CSU_CSL9_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL9_SSR_S2)
#else
#define BF_CSU_CSL9_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL9_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL9_SSR_S2(v)   BF_CS1(CSU_CSL9, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL9_NUR_S2      (2)
#define BM_CSU_CSL9_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL9_NUR_S2)
#else
#define BF_CSU_CSL9_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL9_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL9_NUR_S2(v)   BF_CS1(CSU_CSL9, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL9_NSR_S2      (3)
#define BM_CSU_CSL9_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL9_NSR_S2)
#else
#define BF_CSU_CSL9_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL9_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL9_NSR_S2(v)   BF_CS1(CSU_CSL9, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL9_SUW_S2      (4)
#define BM_CSU_CSL9_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL9_SUW_S2)
#else
#define BF_CSU_CSL9_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL9_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL9_SUW_S2(v)   BF_CS1(CSU_CSL9, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL9_SSW_S2      (5)
#define BM_CSU_CSL9_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL9_SSW_S2)
#else
#define BF_CSU_CSL9_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL9_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL9_SSW_S2(v)   BF_CS1(CSU_CSL9, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL9_NUW_S2      (6)
#define BM_CSU_CSL9_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL9_NUW_S2)
#else
#define BF_CSU_CSL9_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL9_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL9_NUW_S2(v)   BF_CS1(CSU_CSL9, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL9_NSW_S2      (7)
#define BM_CSU_CSL9_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL9_NSW_S2)
#else
#define BF_CSU_CSL9_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL9_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL9_NSW_S2(v)   BF_CS1(CSU_CSL9, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL9_LOCK_S2      (8)
#define BM_CSU_CSL9_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL9_LOCK_S2)
#else
#define BF_CSU_CSL9_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL9_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL9_LOCK_S2(v)   BF_CS1(CSU_CSL9, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL9, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL9_SUR_S1      (16)
#define BM_CSU_CSL9_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL9_SUR_S1)
#else
#define BF_CSU_CSL9_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL9_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL9_SUR_S1(v)   BF_CS1(CSU_CSL9, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL9, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL9_SSR_S1      (17)
#define BM_CSU_CSL9_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL9_SSR_S1)
#else
#define BF_CSU_CSL9_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL9_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL9_SSR_S1(v)   BF_CS1(CSU_CSL9, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL9, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL9_NUR_S1      (18)
#define BM_CSU_CSL9_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL9_NUR_S1)
#else
#define BF_CSU_CSL9_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL9_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL9_NUR_S1(v)   BF_CS1(CSU_CSL9, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL9, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL9_NSR_S1      (19)
#define BM_CSU_CSL9_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL9_NSR_S1)
#else
#define BF_CSU_CSL9_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL9_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL9_NSR_S1(v)   BF_CS1(CSU_CSL9, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL9, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL9_SUW_S1      (20)
#define BM_CSU_CSL9_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL9_SUW_S1)
#else
#define BF_CSU_CSL9_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL9_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL9_SUW_S1(v)   BF_CS1(CSU_CSL9, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL9, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL9_SSW_S1      (21)
#define BM_CSU_CSL9_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL9_SSW_S1)
#else
#define BF_CSU_CSL9_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL9_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL9_SSW_S1(v)   BF_CS1(CSU_CSL9, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL9, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL9_NUW_S1      (22)
#define BM_CSU_CSL9_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL9_NUW_S1)
#else
#define BF_CSU_CSL9_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL9_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL9_NUW_S1(v)   BF_CS1(CSU_CSL9, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL9, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL9_NSW_S1      (23)
#define BM_CSU_CSL9_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL9_NSW_S1)
#else
#define BF_CSU_CSL9_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL9_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL9_NSW_S1(v)   BF_CS1(CSU_CSL9, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL9, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL9_LOCK_S1      (24)
#define BM_CSU_CSL9_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL9_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL9_LOCK_S1)
#else
#define BF_CSU_CSL9_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL9_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL9_LOCK_S1(v)   BF_CS1(CSU_CSL9, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL10 - Config security level register 10 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl10_t;
#endif

/*
 * constants & macros for entire CSU_CSL10 register
 */
#define HW_CSU_CSL10_ADDR      (REGS_CSU_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL10           (*(volatile hw_csu_csl10_t *) HW_CSU_CSL10_ADDR)
#define HW_CSU_CSL10_RD()      (HW_CSU_CSL10.U)
#define HW_CSU_CSL10_WR(v)     (HW_CSU_CSL10.U = (v))
#define HW_CSU_CSL10_SET(v)    (HW_CSU_CSL10_WR(HW_CSU_CSL10_RD() |  (v)))
#define HW_CSU_CSL10_CLR(v)    (HW_CSU_CSL10_WR(HW_CSU_CSL10_RD() & ~(v)))
#define HW_CSU_CSL10_TOG(v)    (HW_CSU_CSL10_WR(HW_CSU_CSL10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL10 bitfields
 */

/* --- Register HW_CSU_CSL10, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL10_SUR_S2      (0)
#define BM_CSU_CSL10_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL10_SUR_S2)
#else
#define BF_CSU_CSL10_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL10_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL10_SUR_S2(v)   BF_CS1(CSU_CSL10, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL10_SSR_S2      (1)
#define BM_CSU_CSL10_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL10_SSR_S2)
#else
#define BF_CSU_CSL10_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL10_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL10_SSR_S2(v)   BF_CS1(CSU_CSL10, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL10_NUR_S2      (2)
#define BM_CSU_CSL10_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL10_NUR_S2)
#else
#define BF_CSU_CSL10_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL10_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL10_NUR_S2(v)   BF_CS1(CSU_CSL10, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL10_NSR_S2      (3)
#define BM_CSU_CSL10_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL10_NSR_S2)
#else
#define BF_CSU_CSL10_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL10_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL10_NSR_S2(v)   BF_CS1(CSU_CSL10, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL10_SUW_S2      (4)
#define BM_CSU_CSL10_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL10_SUW_S2)
#else
#define BF_CSU_CSL10_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL10_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL10_SUW_S2(v)   BF_CS1(CSU_CSL10, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL10_SSW_S2      (5)
#define BM_CSU_CSL10_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL10_SSW_S2)
#else
#define BF_CSU_CSL10_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL10_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL10_SSW_S2(v)   BF_CS1(CSU_CSL10, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL10_NUW_S2      (6)
#define BM_CSU_CSL10_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL10_NUW_S2)
#else
#define BF_CSU_CSL10_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL10_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL10_NUW_S2(v)   BF_CS1(CSU_CSL10, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL10_NSW_S2      (7)
#define BM_CSU_CSL10_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL10_NSW_S2)
#else
#define BF_CSU_CSL10_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL10_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL10_NSW_S2(v)   BF_CS1(CSU_CSL10, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL10_LOCK_S2      (8)
#define BM_CSU_CSL10_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL10_LOCK_S2)
#else
#define BF_CSU_CSL10_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL10_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL10_LOCK_S2(v)   BF_CS1(CSU_CSL10, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL10, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL10_SUR_S1      (16)
#define BM_CSU_CSL10_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL10_SUR_S1)
#else
#define BF_CSU_CSL10_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL10_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL10_SUR_S1(v)   BF_CS1(CSU_CSL10, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL10, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL10_SSR_S1      (17)
#define BM_CSU_CSL10_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL10_SSR_S1)
#else
#define BF_CSU_CSL10_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL10_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL10_SSR_S1(v)   BF_CS1(CSU_CSL10, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL10, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL10_NUR_S1      (18)
#define BM_CSU_CSL10_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL10_NUR_S1)
#else
#define BF_CSU_CSL10_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL10_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL10_NUR_S1(v)   BF_CS1(CSU_CSL10, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL10, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL10_NSR_S1      (19)
#define BM_CSU_CSL10_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL10_NSR_S1)
#else
#define BF_CSU_CSL10_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL10_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL10_NSR_S1(v)   BF_CS1(CSU_CSL10, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL10, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL10_SUW_S1      (20)
#define BM_CSU_CSL10_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL10_SUW_S1)
#else
#define BF_CSU_CSL10_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL10_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL10_SUW_S1(v)   BF_CS1(CSU_CSL10, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL10, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL10_SSW_S1      (21)
#define BM_CSU_CSL10_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL10_SSW_S1)
#else
#define BF_CSU_CSL10_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL10_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL10_SSW_S1(v)   BF_CS1(CSU_CSL10, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL10, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL10_NUW_S1      (22)
#define BM_CSU_CSL10_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL10_NUW_S1)
#else
#define BF_CSU_CSL10_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL10_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL10_NUW_S1(v)   BF_CS1(CSU_CSL10, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL10, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL10_NSW_S1      (23)
#define BM_CSU_CSL10_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL10_NSW_S1)
#else
#define BF_CSU_CSL10_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL10_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL10_NSW_S1(v)   BF_CS1(CSU_CSL10, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL10, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL10_LOCK_S1      (24)
#define BM_CSU_CSL10_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL10_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL10_LOCK_S1)
#else
#define BF_CSU_CSL10_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL10_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL10_LOCK_S1(v)   BF_CS1(CSU_CSL10, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL11 - Config security level register 11 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl11_t;
#endif

/*
 * constants & macros for entire CSU_CSL11 register
 */
#define HW_CSU_CSL11_ADDR      (REGS_CSU_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL11           (*(volatile hw_csu_csl11_t *) HW_CSU_CSL11_ADDR)
#define HW_CSU_CSL11_RD()      (HW_CSU_CSL11.U)
#define HW_CSU_CSL11_WR(v)     (HW_CSU_CSL11.U = (v))
#define HW_CSU_CSL11_SET(v)    (HW_CSU_CSL11_WR(HW_CSU_CSL11_RD() |  (v)))
#define HW_CSU_CSL11_CLR(v)    (HW_CSU_CSL11_WR(HW_CSU_CSL11_RD() & ~(v)))
#define HW_CSU_CSL11_TOG(v)    (HW_CSU_CSL11_WR(HW_CSU_CSL11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL11 bitfields
 */

/* --- Register HW_CSU_CSL11, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL11_SUR_S2      (0)
#define BM_CSU_CSL11_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL11_SUR_S2)
#else
#define BF_CSU_CSL11_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL11_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL11_SUR_S2(v)   BF_CS1(CSU_CSL11, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL11_SSR_S2      (1)
#define BM_CSU_CSL11_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL11_SSR_S2)
#else
#define BF_CSU_CSL11_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL11_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL11_SSR_S2(v)   BF_CS1(CSU_CSL11, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL11_NUR_S2      (2)
#define BM_CSU_CSL11_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL11_NUR_S2)
#else
#define BF_CSU_CSL11_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL11_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL11_NUR_S2(v)   BF_CS1(CSU_CSL11, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL11_NSR_S2      (3)
#define BM_CSU_CSL11_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL11_NSR_S2)
#else
#define BF_CSU_CSL11_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL11_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL11_NSR_S2(v)   BF_CS1(CSU_CSL11, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL11_SUW_S2      (4)
#define BM_CSU_CSL11_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL11_SUW_S2)
#else
#define BF_CSU_CSL11_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL11_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL11_SUW_S2(v)   BF_CS1(CSU_CSL11, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL11_SSW_S2      (5)
#define BM_CSU_CSL11_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL11_SSW_S2)
#else
#define BF_CSU_CSL11_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL11_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL11_SSW_S2(v)   BF_CS1(CSU_CSL11, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL11_NUW_S2      (6)
#define BM_CSU_CSL11_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL11_NUW_S2)
#else
#define BF_CSU_CSL11_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL11_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL11_NUW_S2(v)   BF_CS1(CSU_CSL11, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL11_NSW_S2      (7)
#define BM_CSU_CSL11_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL11_NSW_S2)
#else
#define BF_CSU_CSL11_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL11_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL11_NSW_S2(v)   BF_CS1(CSU_CSL11, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL11_LOCK_S2      (8)
#define BM_CSU_CSL11_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL11_LOCK_S2)
#else
#define BF_CSU_CSL11_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL11_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL11_LOCK_S2(v)   BF_CS1(CSU_CSL11, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL11, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL11_SUR_S1      (16)
#define BM_CSU_CSL11_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL11_SUR_S1)
#else
#define BF_CSU_CSL11_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL11_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL11_SUR_S1(v)   BF_CS1(CSU_CSL11, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL11, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL11_SSR_S1      (17)
#define BM_CSU_CSL11_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL11_SSR_S1)
#else
#define BF_CSU_CSL11_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL11_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL11_SSR_S1(v)   BF_CS1(CSU_CSL11, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL11, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL11_NUR_S1      (18)
#define BM_CSU_CSL11_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL11_NUR_S1)
#else
#define BF_CSU_CSL11_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL11_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL11_NUR_S1(v)   BF_CS1(CSU_CSL11, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL11, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL11_NSR_S1      (19)
#define BM_CSU_CSL11_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL11_NSR_S1)
#else
#define BF_CSU_CSL11_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL11_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL11_NSR_S1(v)   BF_CS1(CSU_CSL11, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL11, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL11_SUW_S1      (20)
#define BM_CSU_CSL11_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL11_SUW_S1)
#else
#define BF_CSU_CSL11_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL11_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL11_SUW_S1(v)   BF_CS1(CSU_CSL11, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL11, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL11_SSW_S1      (21)
#define BM_CSU_CSL11_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL11_SSW_S1)
#else
#define BF_CSU_CSL11_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL11_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL11_SSW_S1(v)   BF_CS1(CSU_CSL11, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL11, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL11_NUW_S1      (22)
#define BM_CSU_CSL11_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL11_NUW_S1)
#else
#define BF_CSU_CSL11_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL11_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL11_NUW_S1(v)   BF_CS1(CSU_CSL11, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL11, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL11_NSW_S1      (23)
#define BM_CSU_CSL11_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL11_NSW_S1)
#else
#define BF_CSU_CSL11_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL11_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL11_NSW_S1(v)   BF_CS1(CSU_CSL11, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL11, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL11_LOCK_S1      (24)
#define BM_CSU_CSL11_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL11_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL11_LOCK_S1)
#else
#define BF_CSU_CSL11_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL11_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL11_LOCK_S1(v)   BF_CS1(CSU_CSL11, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL12 - Config security level register 12 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl12_t;
#endif

/*
 * constants & macros for entire CSU_CSL12 register
 */
#define HW_CSU_CSL12_ADDR      (REGS_CSU_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL12           (*(volatile hw_csu_csl12_t *) HW_CSU_CSL12_ADDR)
#define HW_CSU_CSL12_RD()      (HW_CSU_CSL12.U)
#define HW_CSU_CSL12_WR(v)     (HW_CSU_CSL12.U = (v))
#define HW_CSU_CSL12_SET(v)    (HW_CSU_CSL12_WR(HW_CSU_CSL12_RD() |  (v)))
#define HW_CSU_CSL12_CLR(v)    (HW_CSU_CSL12_WR(HW_CSU_CSL12_RD() & ~(v)))
#define HW_CSU_CSL12_TOG(v)    (HW_CSU_CSL12_WR(HW_CSU_CSL12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL12 bitfields
 */

/* --- Register HW_CSU_CSL12, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL12_SUR_S2      (0)
#define BM_CSU_CSL12_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL12_SUR_S2)
#else
#define BF_CSU_CSL12_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL12_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL12_SUR_S2(v)   BF_CS1(CSU_CSL12, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL12_SSR_S2      (1)
#define BM_CSU_CSL12_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL12_SSR_S2)
#else
#define BF_CSU_CSL12_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL12_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL12_SSR_S2(v)   BF_CS1(CSU_CSL12, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL12_NUR_S2      (2)
#define BM_CSU_CSL12_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL12_NUR_S2)
#else
#define BF_CSU_CSL12_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL12_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL12_NUR_S2(v)   BF_CS1(CSU_CSL12, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL12_NSR_S2      (3)
#define BM_CSU_CSL12_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL12_NSR_S2)
#else
#define BF_CSU_CSL12_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL12_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL12_NSR_S2(v)   BF_CS1(CSU_CSL12, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL12_SUW_S2      (4)
#define BM_CSU_CSL12_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL12_SUW_S2)
#else
#define BF_CSU_CSL12_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL12_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL12_SUW_S2(v)   BF_CS1(CSU_CSL12, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL12_SSW_S2      (5)
#define BM_CSU_CSL12_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL12_SSW_S2)
#else
#define BF_CSU_CSL12_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL12_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL12_SSW_S2(v)   BF_CS1(CSU_CSL12, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL12_NUW_S2      (6)
#define BM_CSU_CSL12_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL12_NUW_S2)
#else
#define BF_CSU_CSL12_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL12_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL12_NUW_S2(v)   BF_CS1(CSU_CSL12, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL12_NSW_S2      (7)
#define BM_CSU_CSL12_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL12_NSW_S2)
#else
#define BF_CSU_CSL12_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL12_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL12_NSW_S2(v)   BF_CS1(CSU_CSL12, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL12_LOCK_S2      (8)
#define BM_CSU_CSL12_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL12_LOCK_S2)
#else
#define BF_CSU_CSL12_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL12_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL12_LOCK_S2(v)   BF_CS1(CSU_CSL12, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL12, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL12_SUR_S1      (16)
#define BM_CSU_CSL12_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL12_SUR_S1)
#else
#define BF_CSU_CSL12_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL12_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL12_SUR_S1(v)   BF_CS1(CSU_CSL12, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL12, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL12_SSR_S1      (17)
#define BM_CSU_CSL12_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL12_SSR_S1)
#else
#define BF_CSU_CSL12_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL12_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL12_SSR_S1(v)   BF_CS1(CSU_CSL12, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL12, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL12_NUR_S1      (18)
#define BM_CSU_CSL12_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL12_NUR_S1)
#else
#define BF_CSU_CSL12_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL12_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL12_NUR_S1(v)   BF_CS1(CSU_CSL12, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL12, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL12_NSR_S1      (19)
#define BM_CSU_CSL12_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL12_NSR_S1)
#else
#define BF_CSU_CSL12_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL12_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL12_NSR_S1(v)   BF_CS1(CSU_CSL12, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL12, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL12_SUW_S1      (20)
#define BM_CSU_CSL12_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL12_SUW_S1)
#else
#define BF_CSU_CSL12_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL12_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL12_SUW_S1(v)   BF_CS1(CSU_CSL12, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL12, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL12_SSW_S1      (21)
#define BM_CSU_CSL12_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL12_SSW_S1)
#else
#define BF_CSU_CSL12_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL12_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL12_SSW_S1(v)   BF_CS1(CSU_CSL12, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL12, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL12_NUW_S1      (22)
#define BM_CSU_CSL12_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL12_NUW_S1)
#else
#define BF_CSU_CSL12_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL12_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL12_NUW_S1(v)   BF_CS1(CSU_CSL12, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL12, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL12_NSW_S1      (23)
#define BM_CSU_CSL12_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL12_NSW_S1)
#else
#define BF_CSU_CSL12_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL12_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL12_NSW_S1(v)   BF_CS1(CSU_CSL12, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL12, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL12_LOCK_S1      (24)
#define BM_CSU_CSL12_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL12_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL12_LOCK_S1)
#else
#define BF_CSU_CSL12_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL12_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL12_LOCK_S1(v)   BF_CS1(CSU_CSL12, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL13 - Config security level register 13 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl13_t;
#endif

/*
 * constants & macros for entire CSU_CSL13 register
 */
#define HW_CSU_CSL13_ADDR      (REGS_CSU_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL13           (*(volatile hw_csu_csl13_t *) HW_CSU_CSL13_ADDR)
#define HW_CSU_CSL13_RD()      (HW_CSU_CSL13.U)
#define HW_CSU_CSL13_WR(v)     (HW_CSU_CSL13.U = (v))
#define HW_CSU_CSL13_SET(v)    (HW_CSU_CSL13_WR(HW_CSU_CSL13_RD() |  (v)))
#define HW_CSU_CSL13_CLR(v)    (HW_CSU_CSL13_WR(HW_CSU_CSL13_RD() & ~(v)))
#define HW_CSU_CSL13_TOG(v)    (HW_CSU_CSL13_WR(HW_CSU_CSL13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL13 bitfields
 */

/* --- Register HW_CSU_CSL13, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL13_SUR_S2      (0)
#define BM_CSU_CSL13_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL13_SUR_S2)
#else
#define BF_CSU_CSL13_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL13_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL13_SUR_S2(v)   BF_CS1(CSU_CSL13, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL13_SSR_S2      (1)
#define BM_CSU_CSL13_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL13_SSR_S2)
#else
#define BF_CSU_CSL13_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL13_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL13_SSR_S2(v)   BF_CS1(CSU_CSL13, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL13_NUR_S2      (2)
#define BM_CSU_CSL13_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL13_NUR_S2)
#else
#define BF_CSU_CSL13_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL13_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL13_NUR_S2(v)   BF_CS1(CSU_CSL13, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL13_NSR_S2      (3)
#define BM_CSU_CSL13_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL13_NSR_S2)
#else
#define BF_CSU_CSL13_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL13_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL13_NSR_S2(v)   BF_CS1(CSU_CSL13, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL13_SUW_S2      (4)
#define BM_CSU_CSL13_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL13_SUW_S2)
#else
#define BF_CSU_CSL13_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL13_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL13_SUW_S2(v)   BF_CS1(CSU_CSL13, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL13_SSW_S2      (5)
#define BM_CSU_CSL13_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL13_SSW_S2)
#else
#define BF_CSU_CSL13_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL13_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL13_SSW_S2(v)   BF_CS1(CSU_CSL13, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL13_NUW_S2      (6)
#define BM_CSU_CSL13_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL13_NUW_S2)
#else
#define BF_CSU_CSL13_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL13_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL13_NUW_S2(v)   BF_CS1(CSU_CSL13, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL13_NSW_S2      (7)
#define BM_CSU_CSL13_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL13_NSW_S2)
#else
#define BF_CSU_CSL13_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL13_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL13_NSW_S2(v)   BF_CS1(CSU_CSL13, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL13_LOCK_S2      (8)
#define BM_CSU_CSL13_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL13_LOCK_S2)
#else
#define BF_CSU_CSL13_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL13_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL13_LOCK_S2(v)   BF_CS1(CSU_CSL13, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL13, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL13_SUR_S1      (16)
#define BM_CSU_CSL13_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL13_SUR_S1)
#else
#define BF_CSU_CSL13_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL13_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL13_SUR_S1(v)   BF_CS1(CSU_CSL13, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL13, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL13_SSR_S1      (17)
#define BM_CSU_CSL13_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL13_SSR_S1)
#else
#define BF_CSU_CSL13_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL13_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL13_SSR_S1(v)   BF_CS1(CSU_CSL13, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL13, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL13_NUR_S1      (18)
#define BM_CSU_CSL13_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL13_NUR_S1)
#else
#define BF_CSU_CSL13_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL13_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL13_NUR_S1(v)   BF_CS1(CSU_CSL13, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL13, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL13_NSR_S1      (19)
#define BM_CSU_CSL13_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL13_NSR_S1)
#else
#define BF_CSU_CSL13_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL13_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL13_NSR_S1(v)   BF_CS1(CSU_CSL13, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL13, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL13_SUW_S1      (20)
#define BM_CSU_CSL13_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL13_SUW_S1)
#else
#define BF_CSU_CSL13_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL13_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL13_SUW_S1(v)   BF_CS1(CSU_CSL13, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL13, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL13_SSW_S1      (21)
#define BM_CSU_CSL13_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL13_SSW_S1)
#else
#define BF_CSU_CSL13_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL13_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL13_SSW_S1(v)   BF_CS1(CSU_CSL13, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL13, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL13_NUW_S1      (22)
#define BM_CSU_CSL13_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL13_NUW_S1)
#else
#define BF_CSU_CSL13_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL13_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL13_NUW_S1(v)   BF_CS1(CSU_CSL13, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL13, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL13_NSW_S1      (23)
#define BM_CSU_CSL13_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL13_NSW_S1)
#else
#define BF_CSU_CSL13_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL13_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL13_NSW_S1(v)   BF_CS1(CSU_CSL13, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL13, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL13_LOCK_S1      (24)
#define BM_CSU_CSL13_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL13_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL13_LOCK_S1)
#else
#define BF_CSU_CSL13_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL13_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL13_LOCK_S1(v)   BF_CS1(CSU_CSL13, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL14 - Config security level register 14 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl14_t;
#endif

/*
 * constants & macros for entire CSU_CSL14 register
 */
#define HW_CSU_CSL14_ADDR      (REGS_CSU_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL14           (*(volatile hw_csu_csl14_t *) HW_CSU_CSL14_ADDR)
#define HW_CSU_CSL14_RD()      (HW_CSU_CSL14.U)
#define HW_CSU_CSL14_WR(v)     (HW_CSU_CSL14.U = (v))
#define HW_CSU_CSL14_SET(v)    (HW_CSU_CSL14_WR(HW_CSU_CSL14_RD() |  (v)))
#define HW_CSU_CSL14_CLR(v)    (HW_CSU_CSL14_WR(HW_CSU_CSL14_RD() & ~(v)))
#define HW_CSU_CSL14_TOG(v)    (HW_CSU_CSL14_WR(HW_CSU_CSL14_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL14 bitfields
 */

/* --- Register HW_CSU_CSL14, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL14_SUR_S2      (0)
#define BM_CSU_CSL14_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL14_SUR_S2)
#else
#define BF_CSU_CSL14_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL14_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL14_SUR_S2(v)   BF_CS1(CSU_CSL14, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL14_SSR_S2      (1)
#define BM_CSU_CSL14_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL14_SSR_S2)
#else
#define BF_CSU_CSL14_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL14_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL14_SSR_S2(v)   BF_CS1(CSU_CSL14, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL14_NUR_S2      (2)
#define BM_CSU_CSL14_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL14_NUR_S2)
#else
#define BF_CSU_CSL14_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL14_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL14_NUR_S2(v)   BF_CS1(CSU_CSL14, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL14_NSR_S2      (3)
#define BM_CSU_CSL14_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL14_NSR_S2)
#else
#define BF_CSU_CSL14_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL14_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL14_NSR_S2(v)   BF_CS1(CSU_CSL14, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL14_SUW_S2      (4)
#define BM_CSU_CSL14_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL14_SUW_S2)
#else
#define BF_CSU_CSL14_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL14_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL14_SUW_S2(v)   BF_CS1(CSU_CSL14, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL14_SSW_S2      (5)
#define BM_CSU_CSL14_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL14_SSW_S2)
#else
#define BF_CSU_CSL14_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL14_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL14_SSW_S2(v)   BF_CS1(CSU_CSL14, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL14_NUW_S2      (6)
#define BM_CSU_CSL14_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL14_NUW_S2)
#else
#define BF_CSU_CSL14_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL14_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL14_NUW_S2(v)   BF_CS1(CSU_CSL14, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL14_NSW_S2      (7)
#define BM_CSU_CSL14_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL14_NSW_S2)
#else
#define BF_CSU_CSL14_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL14_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL14_NSW_S2(v)   BF_CS1(CSU_CSL14, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL14_LOCK_S2      (8)
#define BM_CSU_CSL14_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL14_LOCK_S2)
#else
#define BF_CSU_CSL14_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL14_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL14_LOCK_S2(v)   BF_CS1(CSU_CSL14, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL14, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL14_SUR_S1      (16)
#define BM_CSU_CSL14_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL14_SUR_S1)
#else
#define BF_CSU_CSL14_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL14_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL14_SUR_S1(v)   BF_CS1(CSU_CSL14, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL14, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL14_SSR_S1      (17)
#define BM_CSU_CSL14_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL14_SSR_S1)
#else
#define BF_CSU_CSL14_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL14_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL14_SSR_S1(v)   BF_CS1(CSU_CSL14, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL14, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL14_NUR_S1      (18)
#define BM_CSU_CSL14_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL14_NUR_S1)
#else
#define BF_CSU_CSL14_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL14_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL14_NUR_S1(v)   BF_CS1(CSU_CSL14, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL14, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL14_NSR_S1      (19)
#define BM_CSU_CSL14_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL14_NSR_S1)
#else
#define BF_CSU_CSL14_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL14_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL14_NSR_S1(v)   BF_CS1(CSU_CSL14, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL14, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL14_SUW_S1      (20)
#define BM_CSU_CSL14_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL14_SUW_S1)
#else
#define BF_CSU_CSL14_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL14_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL14_SUW_S1(v)   BF_CS1(CSU_CSL14, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL14, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL14_SSW_S1      (21)
#define BM_CSU_CSL14_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL14_SSW_S1)
#else
#define BF_CSU_CSL14_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL14_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL14_SSW_S1(v)   BF_CS1(CSU_CSL14, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL14, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL14_NUW_S1      (22)
#define BM_CSU_CSL14_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL14_NUW_S1)
#else
#define BF_CSU_CSL14_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL14_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL14_NUW_S1(v)   BF_CS1(CSU_CSL14, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL14, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL14_NSW_S1      (23)
#define BM_CSU_CSL14_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL14_NSW_S1)
#else
#define BF_CSU_CSL14_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL14_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL14_NSW_S1(v)   BF_CS1(CSU_CSL14, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL14, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL14_LOCK_S1      (24)
#define BM_CSU_CSL14_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL14_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL14_LOCK_S1)
#else
#define BF_CSU_CSL14_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL14_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL14_LOCK_S1(v)   BF_CS1(CSU_CSL14, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL15 - Config security level register 15 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl15_t;
#endif

/*
 * constants & macros for entire CSU_CSL15 register
 */
#define HW_CSU_CSL15_ADDR      (REGS_CSU_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL15           (*(volatile hw_csu_csl15_t *) HW_CSU_CSL15_ADDR)
#define HW_CSU_CSL15_RD()      (HW_CSU_CSL15.U)
#define HW_CSU_CSL15_WR(v)     (HW_CSU_CSL15.U = (v))
#define HW_CSU_CSL15_SET(v)    (HW_CSU_CSL15_WR(HW_CSU_CSL15_RD() |  (v)))
#define HW_CSU_CSL15_CLR(v)    (HW_CSU_CSL15_WR(HW_CSU_CSL15_RD() & ~(v)))
#define HW_CSU_CSL15_TOG(v)    (HW_CSU_CSL15_WR(HW_CSU_CSL15_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL15 bitfields
 */

/* --- Register HW_CSU_CSL15, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL15_SUR_S2      (0)
#define BM_CSU_CSL15_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL15_SUR_S2)
#else
#define BF_CSU_CSL15_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL15_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL15_SUR_S2(v)   BF_CS1(CSU_CSL15, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL15_SSR_S2      (1)
#define BM_CSU_CSL15_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL15_SSR_S2)
#else
#define BF_CSU_CSL15_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL15_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL15_SSR_S2(v)   BF_CS1(CSU_CSL15, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL15_NUR_S2      (2)
#define BM_CSU_CSL15_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL15_NUR_S2)
#else
#define BF_CSU_CSL15_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL15_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL15_NUR_S2(v)   BF_CS1(CSU_CSL15, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL15_NSR_S2      (3)
#define BM_CSU_CSL15_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL15_NSR_S2)
#else
#define BF_CSU_CSL15_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL15_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL15_NSR_S2(v)   BF_CS1(CSU_CSL15, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL15_SUW_S2      (4)
#define BM_CSU_CSL15_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL15_SUW_S2)
#else
#define BF_CSU_CSL15_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL15_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL15_SUW_S2(v)   BF_CS1(CSU_CSL15, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL15_SSW_S2      (5)
#define BM_CSU_CSL15_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL15_SSW_S2)
#else
#define BF_CSU_CSL15_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL15_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL15_SSW_S2(v)   BF_CS1(CSU_CSL15, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL15_NUW_S2      (6)
#define BM_CSU_CSL15_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL15_NUW_S2)
#else
#define BF_CSU_CSL15_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL15_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL15_NUW_S2(v)   BF_CS1(CSU_CSL15, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL15_NSW_S2      (7)
#define BM_CSU_CSL15_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL15_NSW_S2)
#else
#define BF_CSU_CSL15_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL15_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL15_NSW_S2(v)   BF_CS1(CSU_CSL15, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL15_LOCK_S2      (8)
#define BM_CSU_CSL15_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL15_LOCK_S2)
#else
#define BF_CSU_CSL15_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL15_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL15_LOCK_S2(v)   BF_CS1(CSU_CSL15, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL15, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL15_SUR_S1      (16)
#define BM_CSU_CSL15_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL15_SUR_S1)
#else
#define BF_CSU_CSL15_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL15_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL15_SUR_S1(v)   BF_CS1(CSU_CSL15, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL15, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL15_SSR_S1      (17)
#define BM_CSU_CSL15_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL15_SSR_S1)
#else
#define BF_CSU_CSL15_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL15_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL15_SSR_S1(v)   BF_CS1(CSU_CSL15, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL15, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL15_NUR_S1      (18)
#define BM_CSU_CSL15_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL15_NUR_S1)
#else
#define BF_CSU_CSL15_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL15_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL15_NUR_S1(v)   BF_CS1(CSU_CSL15, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL15, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL15_NSR_S1      (19)
#define BM_CSU_CSL15_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL15_NSR_S1)
#else
#define BF_CSU_CSL15_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL15_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL15_NSR_S1(v)   BF_CS1(CSU_CSL15, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL15, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL15_SUW_S1      (20)
#define BM_CSU_CSL15_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL15_SUW_S1)
#else
#define BF_CSU_CSL15_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL15_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL15_SUW_S1(v)   BF_CS1(CSU_CSL15, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL15, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL15_SSW_S1      (21)
#define BM_CSU_CSL15_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL15_SSW_S1)
#else
#define BF_CSU_CSL15_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL15_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL15_SSW_S1(v)   BF_CS1(CSU_CSL15, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL15, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL15_NUW_S1      (22)
#define BM_CSU_CSL15_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL15_NUW_S1)
#else
#define BF_CSU_CSL15_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL15_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL15_NUW_S1(v)   BF_CS1(CSU_CSL15, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL15, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL15_NSW_S1      (23)
#define BM_CSU_CSL15_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL15_NSW_S1)
#else
#define BF_CSU_CSL15_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL15_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL15_NSW_S1(v)   BF_CS1(CSU_CSL15, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL15, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL15_LOCK_S1      (24)
#define BM_CSU_CSL15_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL15_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL15_LOCK_S1)
#else
#define BF_CSU_CSL15_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL15_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL15_LOCK_S1(v)   BF_CS1(CSU_CSL15, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL16 - Config security level register 16 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl16_t;
#endif

/*
 * constants & macros for entire CSU_CSL16 register
 */
#define HW_CSU_CSL16_ADDR      (REGS_CSU_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL16           (*(volatile hw_csu_csl16_t *) HW_CSU_CSL16_ADDR)
#define HW_CSU_CSL16_RD()      (HW_CSU_CSL16.U)
#define HW_CSU_CSL16_WR(v)     (HW_CSU_CSL16.U = (v))
#define HW_CSU_CSL16_SET(v)    (HW_CSU_CSL16_WR(HW_CSU_CSL16_RD() |  (v)))
#define HW_CSU_CSL16_CLR(v)    (HW_CSU_CSL16_WR(HW_CSU_CSL16_RD() & ~(v)))
#define HW_CSU_CSL16_TOG(v)    (HW_CSU_CSL16_WR(HW_CSU_CSL16_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL16 bitfields
 */

/* --- Register HW_CSU_CSL16, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL16_SUR_S2      (0)
#define BM_CSU_CSL16_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL16_SUR_S2)
#else
#define BF_CSU_CSL16_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL16_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL16_SUR_S2(v)   BF_CS1(CSU_CSL16, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL16_SSR_S2      (1)
#define BM_CSU_CSL16_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL16_SSR_S2)
#else
#define BF_CSU_CSL16_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL16_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL16_SSR_S2(v)   BF_CS1(CSU_CSL16, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL16_NUR_S2      (2)
#define BM_CSU_CSL16_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL16_NUR_S2)
#else
#define BF_CSU_CSL16_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL16_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL16_NUR_S2(v)   BF_CS1(CSU_CSL16, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL16_NSR_S2      (3)
#define BM_CSU_CSL16_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL16_NSR_S2)
#else
#define BF_CSU_CSL16_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL16_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL16_NSR_S2(v)   BF_CS1(CSU_CSL16, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL16_SUW_S2      (4)
#define BM_CSU_CSL16_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL16_SUW_S2)
#else
#define BF_CSU_CSL16_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL16_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL16_SUW_S2(v)   BF_CS1(CSU_CSL16, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL16_SSW_S2      (5)
#define BM_CSU_CSL16_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL16_SSW_S2)
#else
#define BF_CSU_CSL16_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL16_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL16_SSW_S2(v)   BF_CS1(CSU_CSL16, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL16_NUW_S2      (6)
#define BM_CSU_CSL16_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL16_NUW_S2)
#else
#define BF_CSU_CSL16_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL16_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL16_NUW_S2(v)   BF_CS1(CSU_CSL16, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL16_NSW_S2      (7)
#define BM_CSU_CSL16_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL16_NSW_S2)
#else
#define BF_CSU_CSL16_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL16_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL16_NSW_S2(v)   BF_CS1(CSU_CSL16, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL16_LOCK_S2      (8)
#define BM_CSU_CSL16_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL16_LOCK_S2)
#else
#define BF_CSU_CSL16_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL16_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL16_LOCK_S2(v)   BF_CS1(CSU_CSL16, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL16, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL16_SUR_S1      (16)
#define BM_CSU_CSL16_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL16_SUR_S1)
#else
#define BF_CSU_CSL16_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL16_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL16_SUR_S1(v)   BF_CS1(CSU_CSL16, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL16, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL16_SSR_S1      (17)
#define BM_CSU_CSL16_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL16_SSR_S1)
#else
#define BF_CSU_CSL16_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL16_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL16_SSR_S1(v)   BF_CS1(CSU_CSL16, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL16, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL16_NUR_S1      (18)
#define BM_CSU_CSL16_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL16_NUR_S1)
#else
#define BF_CSU_CSL16_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL16_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL16_NUR_S1(v)   BF_CS1(CSU_CSL16, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL16, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL16_NSR_S1      (19)
#define BM_CSU_CSL16_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL16_NSR_S1)
#else
#define BF_CSU_CSL16_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL16_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL16_NSR_S1(v)   BF_CS1(CSU_CSL16, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL16, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL16_SUW_S1      (20)
#define BM_CSU_CSL16_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL16_SUW_S1)
#else
#define BF_CSU_CSL16_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL16_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL16_SUW_S1(v)   BF_CS1(CSU_CSL16, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL16, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL16_SSW_S1      (21)
#define BM_CSU_CSL16_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL16_SSW_S1)
#else
#define BF_CSU_CSL16_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL16_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL16_SSW_S1(v)   BF_CS1(CSU_CSL16, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL16, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL16_NUW_S1      (22)
#define BM_CSU_CSL16_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL16_NUW_S1)
#else
#define BF_CSU_CSL16_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL16_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL16_NUW_S1(v)   BF_CS1(CSU_CSL16, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL16, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL16_NSW_S1      (23)
#define BM_CSU_CSL16_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL16_NSW_S1)
#else
#define BF_CSU_CSL16_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL16_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL16_NSW_S1(v)   BF_CS1(CSU_CSL16, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL16, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL16_LOCK_S1      (24)
#define BM_CSU_CSL16_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL16_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL16_LOCK_S1)
#else
#define BF_CSU_CSL16_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL16_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL16_LOCK_S1(v)   BF_CS1(CSU_CSL16, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL17 - Config security level register 17 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl17_t;
#endif

/*
 * constants & macros for entire CSU_CSL17 register
 */
#define HW_CSU_CSL17_ADDR      (REGS_CSU_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL17           (*(volatile hw_csu_csl17_t *) HW_CSU_CSL17_ADDR)
#define HW_CSU_CSL17_RD()      (HW_CSU_CSL17.U)
#define HW_CSU_CSL17_WR(v)     (HW_CSU_CSL17.U = (v))
#define HW_CSU_CSL17_SET(v)    (HW_CSU_CSL17_WR(HW_CSU_CSL17_RD() |  (v)))
#define HW_CSU_CSL17_CLR(v)    (HW_CSU_CSL17_WR(HW_CSU_CSL17_RD() & ~(v)))
#define HW_CSU_CSL17_TOG(v)    (HW_CSU_CSL17_WR(HW_CSU_CSL17_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL17 bitfields
 */

/* --- Register HW_CSU_CSL17, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL17_SUR_S2      (0)
#define BM_CSU_CSL17_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL17_SUR_S2)
#else
#define BF_CSU_CSL17_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL17_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL17_SUR_S2(v)   BF_CS1(CSU_CSL17, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL17_SSR_S2      (1)
#define BM_CSU_CSL17_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL17_SSR_S2)
#else
#define BF_CSU_CSL17_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL17_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL17_SSR_S2(v)   BF_CS1(CSU_CSL17, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL17_NUR_S2      (2)
#define BM_CSU_CSL17_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL17_NUR_S2)
#else
#define BF_CSU_CSL17_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL17_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL17_NUR_S2(v)   BF_CS1(CSU_CSL17, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL17_NSR_S2      (3)
#define BM_CSU_CSL17_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL17_NSR_S2)
#else
#define BF_CSU_CSL17_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL17_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL17_NSR_S2(v)   BF_CS1(CSU_CSL17, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL17_SUW_S2      (4)
#define BM_CSU_CSL17_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL17_SUW_S2)
#else
#define BF_CSU_CSL17_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL17_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL17_SUW_S2(v)   BF_CS1(CSU_CSL17, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL17_SSW_S2      (5)
#define BM_CSU_CSL17_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL17_SSW_S2)
#else
#define BF_CSU_CSL17_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL17_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL17_SSW_S2(v)   BF_CS1(CSU_CSL17, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL17_NUW_S2      (6)
#define BM_CSU_CSL17_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL17_NUW_S2)
#else
#define BF_CSU_CSL17_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL17_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL17_NUW_S2(v)   BF_CS1(CSU_CSL17, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL17_NSW_S2      (7)
#define BM_CSU_CSL17_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL17_NSW_S2)
#else
#define BF_CSU_CSL17_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL17_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL17_NSW_S2(v)   BF_CS1(CSU_CSL17, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL17_LOCK_S2      (8)
#define BM_CSU_CSL17_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL17_LOCK_S2)
#else
#define BF_CSU_CSL17_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL17_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL17_LOCK_S2(v)   BF_CS1(CSU_CSL17, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL17, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL17_SUR_S1      (16)
#define BM_CSU_CSL17_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL17_SUR_S1)
#else
#define BF_CSU_CSL17_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL17_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL17_SUR_S1(v)   BF_CS1(CSU_CSL17, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL17, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL17_SSR_S1      (17)
#define BM_CSU_CSL17_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL17_SSR_S1)
#else
#define BF_CSU_CSL17_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL17_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL17_SSR_S1(v)   BF_CS1(CSU_CSL17, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL17, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL17_NUR_S1      (18)
#define BM_CSU_CSL17_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL17_NUR_S1)
#else
#define BF_CSU_CSL17_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL17_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL17_NUR_S1(v)   BF_CS1(CSU_CSL17, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL17, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL17_NSR_S1      (19)
#define BM_CSU_CSL17_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL17_NSR_S1)
#else
#define BF_CSU_CSL17_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL17_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL17_NSR_S1(v)   BF_CS1(CSU_CSL17, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL17, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL17_SUW_S1      (20)
#define BM_CSU_CSL17_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL17_SUW_S1)
#else
#define BF_CSU_CSL17_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL17_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL17_SUW_S1(v)   BF_CS1(CSU_CSL17, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL17, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL17_SSW_S1      (21)
#define BM_CSU_CSL17_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL17_SSW_S1)
#else
#define BF_CSU_CSL17_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL17_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL17_SSW_S1(v)   BF_CS1(CSU_CSL17, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL17, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL17_NUW_S1      (22)
#define BM_CSU_CSL17_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL17_NUW_S1)
#else
#define BF_CSU_CSL17_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL17_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL17_NUW_S1(v)   BF_CS1(CSU_CSL17, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL17, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL17_NSW_S1      (23)
#define BM_CSU_CSL17_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL17_NSW_S1)
#else
#define BF_CSU_CSL17_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL17_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL17_NSW_S1(v)   BF_CS1(CSU_CSL17, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL17, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL17_LOCK_S1      (24)
#define BM_CSU_CSL17_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL17_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL17_LOCK_S1)
#else
#define BF_CSU_CSL17_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL17_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL17_LOCK_S1(v)   BF_CS1(CSU_CSL17, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL18 - Config security level register 18 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl18_t;
#endif

/*
 * constants & macros for entire CSU_CSL18 register
 */
#define HW_CSU_CSL18_ADDR      (REGS_CSU_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL18           (*(volatile hw_csu_csl18_t *) HW_CSU_CSL18_ADDR)
#define HW_CSU_CSL18_RD()      (HW_CSU_CSL18.U)
#define HW_CSU_CSL18_WR(v)     (HW_CSU_CSL18.U = (v))
#define HW_CSU_CSL18_SET(v)    (HW_CSU_CSL18_WR(HW_CSU_CSL18_RD() |  (v)))
#define HW_CSU_CSL18_CLR(v)    (HW_CSU_CSL18_WR(HW_CSU_CSL18_RD() & ~(v)))
#define HW_CSU_CSL18_TOG(v)    (HW_CSU_CSL18_WR(HW_CSU_CSL18_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL18 bitfields
 */

/* --- Register HW_CSU_CSL18, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL18_SUR_S2      (0)
#define BM_CSU_CSL18_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL18_SUR_S2)
#else
#define BF_CSU_CSL18_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL18_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL18_SUR_S2(v)   BF_CS1(CSU_CSL18, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL18_SSR_S2      (1)
#define BM_CSU_CSL18_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL18_SSR_S2)
#else
#define BF_CSU_CSL18_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL18_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL18_SSR_S2(v)   BF_CS1(CSU_CSL18, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL18_NUR_S2      (2)
#define BM_CSU_CSL18_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL18_NUR_S2)
#else
#define BF_CSU_CSL18_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL18_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL18_NUR_S2(v)   BF_CS1(CSU_CSL18, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL18_NSR_S2      (3)
#define BM_CSU_CSL18_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL18_NSR_S2)
#else
#define BF_CSU_CSL18_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL18_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL18_NSR_S2(v)   BF_CS1(CSU_CSL18, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL18_SUW_S2      (4)
#define BM_CSU_CSL18_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL18_SUW_S2)
#else
#define BF_CSU_CSL18_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL18_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL18_SUW_S2(v)   BF_CS1(CSU_CSL18, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL18_SSW_S2      (5)
#define BM_CSU_CSL18_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL18_SSW_S2)
#else
#define BF_CSU_CSL18_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL18_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL18_SSW_S2(v)   BF_CS1(CSU_CSL18, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL18_NUW_S2      (6)
#define BM_CSU_CSL18_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL18_NUW_S2)
#else
#define BF_CSU_CSL18_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL18_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL18_NUW_S2(v)   BF_CS1(CSU_CSL18, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL18_NSW_S2      (7)
#define BM_CSU_CSL18_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL18_NSW_S2)
#else
#define BF_CSU_CSL18_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL18_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL18_NSW_S2(v)   BF_CS1(CSU_CSL18, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL18_LOCK_S2      (8)
#define BM_CSU_CSL18_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL18_LOCK_S2)
#else
#define BF_CSU_CSL18_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL18_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL18_LOCK_S2(v)   BF_CS1(CSU_CSL18, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL18, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL18_SUR_S1      (16)
#define BM_CSU_CSL18_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL18_SUR_S1)
#else
#define BF_CSU_CSL18_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL18_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL18_SUR_S1(v)   BF_CS1(CSU_CSL18, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL18, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL18_SSR_S1      (17)
#define BM_CSU_CSL18_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL18_SSR_S1)
#else
#define BF_CSU_CSL18_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL18_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL18_SSR_S1(v)   BF_CS1(CSU_CSL18, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL18, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL18_NUR_S1      (18)
#define BM_CSU_CSL18_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL18_NUR_S1)
#else
#define BF_CSU_CSL18_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL18_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL18_NUR_S1(v)   BF_CS1(CSU_CSL18, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL18, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL18_NSR_S1      (19)
#define BM_CSU_CSL18_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL18_NSR_S1)
#else
#define BF_CSU_CSL18_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL18_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL18_NSR_S1(v)   BF_CS1(CSU_CSL18, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL18, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL18_SUW_S1      (20)
#define BM_CSU_CSL18_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL18_SUW_S1)
#else
#define BF_CSU_CSL18_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL18_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL18_SUW_S1(v)   BF_CS1(CSU_CSL18, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL18, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL18_SSW_S1      (21)
#define BM_CSU_CSL18_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL18_SSW_S1)
#else
#define BF_CSU_CSL18_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL18_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL18_SSW_S1(v)   BF_CS1(CSU_CSL18, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL18, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL18_NUW_S1      (22)
#define BM_CSU_CSL18_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL18_NUW_S1)
#else
#define BF_CSU_CSL18_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL18_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL18_NUW_S1(v)   BF_CS1(CSU_CSL18, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL18, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL18_NSW_S1      (23)
#define BM_CSU_CSL18_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL18_NSW_S1)
#else
#define BF_CSU_CSL18_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL18_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL18_NSW_S1(v)   BF_CS1(CSU_CSL18, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL18, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL18_LOCK_S1      (24)
#define BM_CSU_CSL18_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL18_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL18_LOCK_S1)
#else
#define BF_CSU_CSL18_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL18_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL18_LOCK_S1(v)   BF_CS1(CSU_CSL18, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL19 - Config security level register 19 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl19_t;
#endif

/*
 * constants & macros for entire CSU_CSL19 register
 */
#define HW_CSU_CSL19_ADDR      (REGS_CSU_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL19           (*(volatile hw_csu_csl19_t *) HW_CSU_CSL19_ADDR)
#define HW_CSU_CSL19_RD()      (HW_CSU_CSL19.U)
#define HW_CSU_CSL19_WR(v)     (HW_CSU_CSL19.U = (v))
#define HW_CSU_CSL19_SET(v)    (HW_CSU_CSL19_WR(HW_CSU_CSL19_RD() |  (v)))
#define HW_CSU_CSL19_CLR(v)    (HW_CSU_CSL19_WR(HW_CSU_CSL19_RD() & ~(v)))
#define HW_CSU_CSL19_TOG(v)    (HW_CSU_CSL19_WR(HW_CSU_CSL19_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL19 bitfields
 */

/* --- Register HW_CSU_CSL19, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL19_SUR_S2      (0)
#define BM_CSU_CSL19_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL19_SUR_S2)
#else
#define BF_CSU_CSL19_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL19_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL19_SUR_S2(v)   BF_CS1(CSU_CSL19, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL19_SSR_S2      (1)
#define BM_CSU_CSL19_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL19_SSR_S2)
#else
#define BF_CSU_CSL19_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL19_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL19_SSR_S2(v)   BF_CS1(CSU_CSL19, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL19_NUR_S2      (2)
#define BM_CSU_CSL19_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL19_NUR_S2)
#else
#define BF_CSU_CSL19_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL19_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL19_NUR_S2(v)   BF_CS1(CSU_CSL19, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL19_NSR_S2      (3)
#define BM_CSU_CSL19_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL19_NSR_S2)
#else
#define BF_CSU_CSL19_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL19_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL19_NSR_S2(v)   BF_CS1(CSU_CSL19, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL19_SUW_S2      (4)
#define BM_CSU_CSL19_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL19_SUW_S2)
#else
#define BF_CSU_CSL19_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL19_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL19_SUW_S2(v)   BF_CS1(CSU_CSL19, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL19_SSW_S2      (5)
#define BM_CSU_CSL19_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL19_SSW_S2)
#else
#define BF_CSU_CSL19_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL19_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL19_SSW_S2(v)   BF_CS1(CSU_CSL19, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL19_NUW_S2      (6)
#define BM_CSU_CSL19_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL19_NUW_S2)
#else
#define BF_CSU_CSL19_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL19_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL19_NUW_S2(v)   BF_CS1(CSU_CSL19, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL19_NSW_S2      (7)
#define BM_CSU_CSL19_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL19_NSW_S2)
#else
#define BF_CSU_CSL19_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL19_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL19_NSW_S2(v)   BF_CS1(CSU_CSL19, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL19_LOCK_S2      (8)
#define BM_CSU_CSL19_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL19_LOCK_S2)
#else
#define BF_CSU_CSL19_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL19_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL19_LOCK_S2(v)   BF_CS1(CSU_CSL19, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL19, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL19_SUR_S1      (16)
#define BM_CSU_CSL19_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL19_SUR_S1)
#else
#define BF_CSU_CSL19_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL19_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL19_SUR_S1(v)   BF_CS1(CSU_CSL19, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL19, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL19_SSR_S1      (17)
#define BM_CSU_CSL19_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL19_SSR_S1)
#else
#define BF_CSU_CSL19_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL19_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL19_SSR_S1(v)   BF_CS1(CSU_CSL19, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL19, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL19_NUR_S1      (18)
#define BM_CSU_CSL19_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL19_NUR_S1)
#else
#define BF_CSU_CSL19_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL19_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL19_NUR_S1(v)   BF_CS1(CSU_CSL19, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL19, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL19_NSR_S1      (19)
#define BM_CSU_CSL19_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL19_NSR_S1)
#else
#define BF_CSU_CSL19_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL19_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL19_NSR_S1(v)   BF_CS1(CSU_CSL19, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL19, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL19_SUW_S1      (20)
#define BM_CSU_CSL19_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL19_SUW_S1)
#else
#define BF_CSU_CSL19_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL19_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL19_SUW_S1(v)   BF_CS1(CSU_CSL19, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL19, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL19_SSW_S1      (21)
#define BM_CSU_CSL19_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL19_SSW_S1)
#else
#define BF_CSU_CSL19_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL19_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL19_SSW_S1(v)   BF_CS1(CSU_CSL19, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL19, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL19_NUW_S1      (22)
#define BM_CSU_CSL19_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL19_NUW_S1)
#else
#define BF_CSU_CSL19_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL19_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL19_NUW_S1(v)   BF_CS1(CSU_CSL19, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL19, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL19_NSW_S1      (23)
#define BM_CSU_CSL19_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL19_NSW_S1)
#else
#define BF_CSU_CSL19_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL19_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL19_NSW_S1(v)   BF_CS1(CSU_CSL19, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL19, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL19_LOCK_S1      (24)
#define BM_CSU_CSL19_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL19_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL19_LOCK_S1)
#else
#define BF_CSU_CSL19_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL19_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL19_LOCK_S1(v)   BF_CS1(CSU_CSL19, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL20 - Config security level register 20 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl20_t;
#endif

/*
 * constants & macros for entire CSU_CSL20 register
 */
#define HW_CSU_CSL20_ADDR      (REGS_CSU_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL20           (*(volatile hw_csu_csl20_t *) HW_CSU_CSL20_ADDR)
#define HW_CSU_CSL20_RD()      (HW_CSU_CSL20.U)
#define HW_CSU_CSL20_WR(v)     (HW_CSU_CSL20.U = (v))
#define HW_CSU_CSL20_SET(v)    (HW_CSU_CSL20_WR(HW_CSU_CSL20_RD() |  (v)))
#define HW_CSU_CSL20_CLR(v)    (HW_CSU_CSL20_WR(HW_CSU_CSL20_RD() & ~(v)))
#define HW_CSU_CSL20_TOG(v)    (HW_CSU_CSL20_WR(HW_CSU_CSL20_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL20 bitfields
 */

/* --- Register HW_CSU_CSL20, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL20_SUR_S2      (0)
#define BM_CSU_CSL20_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL20_SUR_S2)
#else
#define BF_CSU_CSL20_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL20_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL20_SUR_S2(v)   BF_CS1(CSU_CSL20, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL20_SSR_S2      (1)
#define BM_CSU_CSL20_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL20_SSR_S2)
#else
#define BF_CSU_CSL20_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL20_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL20_SSR_S2(v)   BF_CS1(CSU_CSL20, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL20_NUR_S2      (2)
#define BM_CSU_CSL20_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL20_NUR_S2)
#else
#define BF_CSU_CSL20_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL20_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL20_NUR_S2(v)   BF_CS1(CSU_CSL20, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL20_NSR_S2      (3)
#define BM_CSU_CSL20_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL20_NSR_S2)
#else
#define BF_CSU_CSL20_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL20_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL20_NSR_S2(v)   BF_CS1(CSU_CSL20, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL20_SUW_S2      (4)
#define BM_CSU_CSL20_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL20_SUW_S2)
#else
#define BF_CSU_CSL20_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL20_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL20_SUW_S2(v)   BF_CS1(CSU_CSL20, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL20_SSW_S2      (5)
#define BM_CSU_CSL20_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL20_SSW_S2)
#else
#define BF_CSU_CSL20_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL20_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL20_SSW_S2(v)   BF_CS1(CSU_CSL20, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL20_NUW_S2      (6)
#define BM_CSU_CSL20_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL20_NUW_S2)
#else
#define BF_CSU_CSL20_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL20_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL20_NUW_S2(v)   BF_CS1(CSU_CSL20, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL20_NSW_S2      (7)
#define BM_CSU_CSL20_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL20_NSW_S2)
#else
#define BF_CSU_CSL20_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL20_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL20_NSW_S2(v)   BF_CS1(CSU_CSL20, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL20_LOCK_S2      (8)
#define BM_CSU_CSL20_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL20_LOCK_S2)
#else
#define BF_CSU_CSL20_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL20_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL20_LOCK_S2(v)   BF_CS1(CSU_CSL20, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL20, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL20_SUR_S1      (16)
#define BM_CSU_CSL20_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL20_SUR_S1)
#else
#define BF_CSU_CSL20_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL20_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL20_SUR_S1(v)   BF_CS1(CSU_CSL20, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL20, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL20_SSR_S1      (17)
#define BM_CSU_CSL20_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL20_SSR_S1)
#else
#define BF_CSU_CSL20_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL20_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL20_SSR_S1(v)   BF_CS1(CSU_CSL20, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL20, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL20_NUR_S1      (18)
#define BM_CSU_CSL20_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL20_NUR_S1)
#else
#define BF_CSU_CSL20_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL20_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL20_NUR_S1(v)   BF_CS1(CSU_CSL20, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL20, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL20_NSR_S1      (19)
#define BM_CSU_CSL20_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL20_NSR_S1)
#else
#define BF_CSU_CSL20_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL20_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL20_NSR_S1(v)   BF_CS1(CSU_CSL20, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL20, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL20_SUW_S1      (20)
#define BM_CSU_CSL20_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL20_SUW_S1)
#else
#define BF_CSU_CSL20_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL20_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL20_SUW_S1(v)   BF_CS1(CSU_CSL20, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL20, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL20_SSW_S1      (21)
#define BM_CSU_CSL20_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL20_SSW_S1)
#else
#define BF_CSU_CSL20_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL20_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL20_SSW_S1(v)   BF_CS1(CSU_CSL20, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL20, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL20_NUW_S1      (22)
#define BM_CSU_CSL20_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL20_NUW_S1)
#else
#define BF_CSU_CSL20_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL20_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL20_NUW_S1(v)   BF_CS1(CSU_CSL20, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL20, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL20_NSW_S1      (23)
#define BM_CSU_CSL20_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL20_NSW_S1)
#else
#define BF_CSU_CSL20_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL20_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL20_NSW_S1(v)   BF_CS1(CSU_CSL20, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL20, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL20_LOCK_S1      (24)
#define BM_CSU_CSL20_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL20_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL20_LOCK_S1)
#else
#define BF_CSU_CSL20_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL20_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL20_LOCK_S1(v)   BF_CS1(CSU_CSL20, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL21 - Config security level register 21 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl21_t;
#endif

/*
 * constants & macros for entire CSU_CSL21 register
 */
#define HW_CSU_CSL21_ADDR      (REGS_CSU_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL21           (*(volatile hw_csu_csl21_t *) HW_CSU_CSL21_ADDR)
#define HW_CSU_CSL21_RD()      (HW_CSU_CSL21.U)
#define HW_CSU_CSL21_WR(v)     (HW_CSU_CSL21.U = (v))
#define HW_CSU_CSL21_SET(v)    (HW_CSU_CSL21_WR(HW_CSU_CSL21_RD() |  (v)))
#define HW_CSU_CSL21_CLR(v)    (HW_CSU_CSL21_WR(HW_CSU_CSL21_RD() & ~(v)))
#define HW_CSU_CSL21_TOG(v)    (HW_CSU_CSL21_WR(HW_CSU_CSL21_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL21 bitfields
 */

/* --- Register HW_CSU_CSL21, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL21_SUR_S2      (0)
#define BM_CSU_CSL21_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL21_SUR_S2)
#else
#define BF_CSU_CSL21_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL21_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL21_SUR_S2(v)   BF_CS1(CSU_CSL21, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL21_SSR_S2      (1)
#define BM_CSU_CSL21_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL21_SSR_S2)
#else
#define BF_CSU_CSL21_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL21_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL21_SSR_S2(v)   BF_CS1(CSU_CSL21, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL21_NUR_S2      (2)
#define BM_CSU_CSL21_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL21_NUR_S2)
#else
#define BF_CSU_CSL21_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL21_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL21_NUR_S2(v)   BF_CS1(CSU_CSL21, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL21_NSR_S2      (3)
#define BM_CSU_CSL21_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL21_NSR_S2)
#else
#define BF_CSU_CSL21_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL21_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL21_NSR_S2(v)   BF_CS1(CSU_CSL21, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL21_SUW_S2      (4)
#define BM_CSU_CSL21_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL21_SUW_S2)
#else
#define BF_CSU_CSL21_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL21_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL21_SUW_S2(v)   BF_CS1(CSU_CSL21, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL21_SSW_S2      (5)
#define BM_CSU_CSL21_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL21_SSW_S2)
#else
#define BF_CSU_CSL21_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL21_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL21_SSW_S2(v)   BF_CS1(CSU_CSL21, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL21_NUW_S2      (6)
#define BM_CSU_CSL21_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL21_NUW_S2)
#else
#define BF_CSU_CSL21_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL21_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL21_NUW_S2(v)   BF_CS1(CSU_CSL21, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL21_NSW_S2      (7)
#define BM_CSU_CSL21_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL21_NSW_S2)
#else
#define BF_CSU_CSL21_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL21_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL21_NSW_S2(v)   BF_CS1(CSU_CSL21, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL21_LOCK_S2      (8)
#define BM_CSU_CSL21_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL21_LOCK_S2)
#else
#define BF_CSU_CSL21_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL21_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL21_LOCK_S2(v)   BF_CS1(CSU_CSL21, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL21, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL21_SUR_S1      (16)
#define BM_CSU_CSL21_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL21_SUR_S1)
#else
#define BF_CSU_CSL21_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL21_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL21_SUR_S1(v)   BF_CS1(CSU_CSL21, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL21, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL21_SSR_S1      (17)
#define BM_CSU_CSL21_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL21_SSR_S1)
#else
#define BF_CSU_CSL21_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL21_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL21_SSR_S1(v)   BF_CS1(CSU_CSL21, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL21, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL21_NUR_S1      (18)
#define BM_CSU_CSL21_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL21_NUR_S1)
#else
#define BF_CSU_CSL21_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL21_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL21_NUR_S1(v)   BF_CS1(CSU_CSL21, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL21, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL21_NSR_S1      (19)
#define BM_CSU_CSL21_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL21_NSR_S1)
#else
#define BF_CSU_CSL21_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL21_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL21_NSR_S1(v)   BF_CS1(CSU_CSL21, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL21, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL21_SUW_S1      (20)
#define BM_CSU_CSL21_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL21_SUW_S1)
#else
#define BF_CSU_CSL21_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL21_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL21_SUW_S1(v)   BF_CS1(CSU_CSL21, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL21, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL21_SSW_S1      (21)
#define BM_CSU_CSL21_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL21_SSW_S1)
#else
#define BF_CSU_CSL21_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL21_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL21_SSW_S1(v)   BF_CS1(CSU_CSL21, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL21, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL21_NUW_S1      (22)
#define BM_CSU_CSL21_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL21_NUW_S1)
#else
#define BF_CSU_CSL21_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL21_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL21_NUW_S1(v)   BF_CS1(CSU_CSL21, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL21, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL21_NSW_S1      (23)
#define BM_CSU_CSL21_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL21_NSW_S1)
#else
#define BF_CSU_CSL21_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL21_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL21_NSW_S1(v)   BF_CS1(CSU_CSL21, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL21, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL21_LOCK_S1      (24)
#define BM_CSU_CSL21_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL21_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL21_LOCK_S1)
#else
#define BF_CSU_CSL21_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL21_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL21_LOCK_S1(v)   BF_CS1(CSU_CSL21, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL22 - Config security level register 22 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl22_t;
#endif

/*
 * constants & macros for entire CSU_CSL22 register
 */
#define HW_CSU_CSL22_ADDR      (REGS_CSU_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL22           (*(volatile hw_csu_csl22_t *) HW_CSU_CSL22_ADDR)
#define HW_CSU_CSL22_RD()      (HW_CSU_CSL22.U)
#define HW_CSU_CSL22_WR(v)     (HW_CSU_CSL22.U = (v))
#define HW_CSU_CSL22_SET(v)    (HW_CSU_CSL22_WR(HW_CSU_CSL22_RD() |  (v)))
#define HW_CSU_CSL22_CLR(v)    (HW_CSU_CSL22_WR(HW_CSU_CSL22_RD() & ~(v)))
#define HW_CSU_CSL22_TOG(v)    (HW_CSU_CSL22_WR(HW_CSU_CSL22_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL22 bitfields
 */

/* --- Register HW_CSU_CSL22, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL22_SUR_S2      (0)
#define BM_CSU_CSL22_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL22_SUR_S2)
#else
#define BF_CSU_CSL22_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL22_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL22_SUR_S2(v)   BF_CS1(CSU_CSL22, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL22_SSR_S2      (1)
#define BM_CSU_CSL22_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL22_SSR_S2)
#else
#define BF_CSU_CSL22_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL22_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL22_SSR_S2(v)   BF_CS1(CSU_CSL22, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL22_NUR_S2      (2)
#define BM_CSU_CSL22_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL22_NUR_S2)
#else
#define BF_CSU_CSL22_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL22_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL22_NUR_S2(v)   BF_CS1(CSU_CSL22, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL22_NSR_S2      (3)
#define BM_CSU_CSL22_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL22_NSR_S2)
#else
#define BF_CSU_CSL22_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL22_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL22_NSR_S2(v)   BF_CS1(CSU_CSL22, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL22_SUW_S2      (4)
#define BM_CSU_CSL22_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL22_SUW_S2)
#else
#define BF_CSU_CSL22_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL22_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL22_SUW_S2(v)   BF_CS1(CSU_CSL22, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL22_SSW_S2      (5)
#define BM_CSU_CSL22_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL22_SSW_S2)
#else
#define BF_CSU_CSL22_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL22_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL22_SSW_S2(v)   BF_CS1(CSU_CSL22, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL22_NUW_S2      (6)
#define BM_CSU_CSL22_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL22_NUW_S2)
#else
#define BF_CSU_CSL22_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL22_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL22_NUW_S2(v)   BF_CS1(CSU_CSL22, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL22_NSW_S2      (7)
#define BM_CSU_CSL22_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL22_NSW_S2)
#else
#define BF_CSU_CSL22_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL22_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL22_NSW_S2(v)   BF_CS1(CSU_CSL22, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL22_LOCK_S2      (8)
#define BM_CSU_CSL22_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL22_LOCK_S2)
#else
#define BF_CSU_CSL22_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL22_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL22_LOCK_S2(v)   BF_CS1(CSU_CSL22, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL22, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL22_SUR_S1      (16)
#define BM_CSU_CSL22_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL22_SUR_S1)
#else
#define BF_CSU_CSL22_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL22_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL22_SUR_S1(v)   BF_CS1(CSU_CSL22, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL22, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL22_SSR_S1      (17)
#define BM_CSU_CSL22_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL22_SSR_S1)
#else
#define BF_CSU_CSL22_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL22_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL22_SSR_S1(v)   BF_CS1(CSU_CSL22, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL22, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL22_NUR_S1      (18)
#define BM_CSU_CSL22_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL22_NUR_S1)
#else
#define BF_CSU_CSL22_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL22_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL22_NUR_S1(v)   BF_CS1(CSU_CSL22, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL22, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL22_NSR_S1      (19)
#define BM_CSU_CSL22_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL22_NSR_S1)
#else
#define BF_CSU_CSL22_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL22_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL22_NSR_S1(v)   BF_CS1(CSU_CSL22, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL22, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL22_SUW_S1      (20)
#define BM_CSU_CSL22_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL22_SUW_S1)
#else
#define BF_CSU_CSL22_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL22_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL22_SUW_S1(v)   BF_CS1(CSU_CSL22, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL22, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL22_SSW_S1      (21)
#define BM_CSU_CSL22_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL22_SSW_S1)
#else
#define BF_CSU_CSL22_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL22_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL22_SSW_S1(v)   BF_CS1(CSU_CSL22, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL22, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL22_NUW_S1      (22)
#define BM_CSU_CSL22_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL22_NUW_S1)
#else
#define BF_CSU_CSL22_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL22_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL22_NUW_S1(v)   BF_CS1(CSU_CSL22, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL22, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL22_NSW_S1      (23)
#define BM_CSU_CSL22_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL22_NSW_S1)
#else
#define BF_CSU_CSL22_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL22_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL22_NSW_S1(v)   BF_CS1(CSU_CSL22, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL22, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL22_LOCK_S1      (24)
#define BM_CSU_CSL22_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL22_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL22_LOCK_S1)
#else
#define BF_CSU_CSL22_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL22_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL22_LOCK_S1(v)   BF_CS1(CSU_CSL22, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL23 - Config security level register 23 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl23_t;
#endif

/*
 * constants & macros for entire CSU_CSL23 register
 */
#define HW_CSU_CSL23_ADDR      (REGS_CSU_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL23           (*(volatile hw_csu_csl23_t *) HW_CSU_CSL23_ADDR)
#define HW_CSU_CSL23_RD()      (HW_CSU_CSL23.U)
#define HW_CSU_CSL23_WR(v)     (HW_CSU_CSL23.U = (v))
#define HW_CSU_CSL23_SET(v)    (HW_CSU_CSL23_WR(HW_CSU_CSL23_RD() |  (v)))
#define HW_CSU_CSL23_CLR(v)    (HW_CSU_CSL23_WR(HW_CSU_CSL23_RD() & ~(v)))
#define HW_CSU_CSL23_TOG(v)    (HW_CSU_CSL23_WR(HW_CSU_CSL23_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL23 bitfields
 */

/* --- Register HW_CSU_CSL23, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL23_SUR_S2      (0)
#define BM_CSU_CSL23_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL23_SUR_S2)
#else
#define BF_CSU_CSL23_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL23_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL23_SUR_S2(v)   BF_CS1(CSU_CSL23, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL23_SSR_S2      (1)
#define BM_CSU_CSL23_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL23_SSR_S2)
#else
#define BF_CSU_CSL23_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL23_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL23_SSR_S2(v)   BF_CS1(CSU_CSL23, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL23_NUR_S2      (2)
#define BM_CSU_CSL23_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL23_NUR_S2)
#else
#define BF_CSU_CSL23_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL23_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL23_NUR_S2(v)   BF_CS1(CSU_CSL23, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL23_NSR_S2      (3)
#define BM_CSU_CSL23_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL23_NSR_S2)
#else
#define BF_CSU_CSL23_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL23_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL23_NSR_S2(v)   BF_CS1(CSU_CSL23, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL23_SUW_S2      (4)
#define BM_CSU_CSL23_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL23_SUW_S2)
#else
#define BF_CSU_CSL23_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL23_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL23_SUW_S2(v)   BF_CS1(CSU_CSL23, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL23_SSW_S2      (5)
#define BM_CSU_CSL23_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL23_SSW_S2)
#else
#define BF_CSU_CSL23_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL23_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL23_SSW_S2(v)   BF_CS1(CSU_CSL23, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL23_NUW_S2      (6)
#define BM_CSU_CSL23_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL23_NUW_S2)
#else
#define BF_CSU_CSL23_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL23_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL23_NUW_S2(v)   BF_CS1(CSU_CSL23, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL23_NSW_S2      (7)
#define BM_CSU_CSL23_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL23_NSW_S2)
#else
#define BF_CSU_CSL23_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL23_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL23_NSW_S2(v)   BF_CS1(CSU_CSL23, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL23_LOCK_S2      (8)
#define BM_CSU_CSL23_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL23_LOCK_S2)
#else
#define BF_CSU_CSL23_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL23_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL23_LOCK_S2(v)   BF_CS1(CSU_CSL23, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL23, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL23_SUR_S1      (16)
#define BM_CSU_CSL23_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL23_SUR_S1)
#else
#define BF_CSU_CSL23_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL23_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL23_SUR_S1(v)   BF_CS1(CSU_CSL23, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL23, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL23_SSR_S1      (17)
#define BM_CSU_CSL23_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL23_SSR_S1)
#else
#define BF_CSU_CSL23_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL23_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL23_SSR_S1(v)   BF_CS1(CSU_CSL23, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL23, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL23_NUR_S1      (18)
#define BM_CSU_CSL23_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL23_NUR_S1)
#else
#define BF_CSU_CSL23_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL23_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL23_NUR_S1(v)   BF_CS1(CSU_CSL23, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL23, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL23_NSR_S1      (19)
#define BM_CSU_CSL23_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL23_NSR_S1)
#else
#define BF_CSU_CSL23_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL23_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL23_NSR_S1(v)   BF_CS1(CSU_CSL23, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL23, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL23_SUW_S1      (20)
#define BM_CSU_CSL23_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL23_SUW_S1)
#else
#define BF_CSU_CSL23_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL23_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL23_SUW_S1(v)   BF_CS1(CSU_CSL23, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL23, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL23_SSW_S1      (21)
#define BM_CSU_CSL23_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL23_SSW_S1)
#else
#define BF_CSU_CSL23_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL23_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL23_SSW_S1(v)   BF_CS1(CSU_CSL23, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL23, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL23_NUW_S1      (22)
#define BM_CSU_CSL23_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL23_NUW_S1)
#else
#define BF_CSU_CSL23_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL23_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL23_NUW_S1(v)   BF_CS1(CSU_CSL23, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL23, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL23_NSW_S1      (23)
#define BM_CSU_CSL23_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL23_NSW_S1)
#else
#define BF_CSU_CSL23_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL23_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL23_NSW_S1(v)   BF_CS1(CSU_CSL23, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL23, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL23_LOCK_S1      (24)
#define BM_CSU_CSL23_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL23_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL23_LOCK_S1)
#else
#define BF_CSU_CSL23_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL23_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL23_LOCK_S1(v)   BF_CS1(CSU_CSL23, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL24 - Config security level register 24 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl24_t;
#endif

/*
 * constants & macros for entire CSU_CSL24 register
 */
#define HW_CSU_CSL24_ADDR      (REGS_CSU_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL24           (*(volatile hw_csu_csl24_t *) HW_CSU_CSL24_ADDR)
#define HW_CSU_CSL24_RD()      (HW_CSU_CSL24.U)
#define HW_CSU_CSL24_WR(v)     (HW_CSU_CSL24.U = (v))
#define HW_CSU_CSL24_SET(v)    (HW_CSU_CSL24_WR(HW_CSU_CSL24_RD() |  (v)))
#define HW_CSU_CSL24_CLR(v)    (HW_CSU_CSL24_WR(HW_CSU_CSL24_RD() & ~(v)))
#define HW_CSU_CSL24_TOG(v)    (HW_CSU_CSL24_WR(HW_CSU_CSL24_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL24 bitfields
 */

/* --- Register HW_CSU_CSL24, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL24_SUR_S2      (0)
#define BM_CSU_CSL24_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL24_SUR_S2)
#else
#define BF_CSU_CSL24_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL24_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL24_SUR_S2(v)   BF_CS1(CSU_CSL24, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL24_SSR_S2      (1)
#define BM_CSU_CSL24_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL24_SSR_S2)
#else
#define BF_CSU_CSL24_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL24_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL24_SSR_S2(v)   BF_CS1(CSU_CSL24, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL24_NUR_S2      (2)
#define BM_CSU_CSL24_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL24_NUR_S2)
#else
#define BF_CSU_CSL24_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL24_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL24_NUR_S2(v)   BF_CS1(CSU_CSL24, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL24_NSR_S2      (3)
#define BM_CSU_CSL24_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL24_NSR_S2)
#else
#define BF_CSU_CSL24_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL24_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL24_NSR_S2(v)   BF_CS1(CSU_CSL24, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL24_SUW_S2      (4)
#define BM_CSU_CSL24_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL24_SUW_S2)
#else
#define BF_CSU_CSL24_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL24_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL24_SUW_S2(v)   BF_CS1(CSU_CSL24, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL24_SSW_S2      (5)
#define BM_CSU_CSL24_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL24_SSW_S2)
#else
#define BF_CSU_CSL24_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL24_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL24_SSW_S2(v)   BF_CS1(CSU_CSL24, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL24_NUW_S2      (6)
#define BM_CSU_CSL24_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL24_NUW_S2)
#else
#define BF_CSU_CSL24_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL24_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL24_NUW_S2(v)   BF_CS1(CSU_CSL24, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL24_NSW_S2      (7)
#define BM_CSU_CSL24_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL24_NSW_S2)
#else
#define BF_CSU_CSL24_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL24_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL24_NSW_S2(v)   BF_CS1(CSU_CSL24, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL24_LOCK_S2      (8)
#define BM_CSU_CSL24_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL24_LOCK_S2)
#else
#define BF_CSU_CSL24_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL24_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL24_LOCK_S2(v)   BF_CS1(CSU_CSL24, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL24, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL24_SUR_S1      (16)
#define BM_CSU_CSL24_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL24_SUR_S1)
#else
#define BF_CSU_CSL24_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL24_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL24_SUR_S1(v)   BF_CS1(CSU_CSL24, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL24, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL24_SSR_S1      (17)
#define BM_CSU_CSL24_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL24_SSR_S1)
#else
#define BF_CSU_CSL24_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL24_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL24_SSR_S1(v)   BF_CS1(CSU_CSL24, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL24, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL24_NUR_S1      (18)
#define BM_CSU_CSL24_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL24_NUR_S1)
#else
#define BF_CSU_CSL24_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL24_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL24_NUR_S1(v)   BF_CS1(CSU_CSL24, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL24, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL24_NSR_S1      (19)
#define BM_CSU_CSL24_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL24_NSR_S1)
#else
#define BF_CSU_CSL24_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL24_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL24_NSR_S1(v)   BF_CS1(CSU_CSL24, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL24, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL24_SUW_S1      (20)
#define BM_CSU_CSL24_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL24_SUW_S1)
#else
#define BF_CSU_CSL24_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL24_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL24_SUW_S1(v)   BF_CS1(CSU_CSL24, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL24, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL24_SSW_S1      (21)
#define BM_CSU_CSL24_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL24_SSW_S1)
#else
#define BF_CSU_CSL24_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL24_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL24_SSW_S1(v)   BF_CS1(CSU_CSL24, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL24, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL24_NUW_S1      (22)
#define BM_CSU_CSL24_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL24_NUW_S1)
#else
#define BF_CSU_CSL24_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL24_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL24_NUW_S1(v)   BF_CS1(CSU_CSL24, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL24, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL24_NSW_S1      (23)
#define BM_CSU_CSL24_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL24_NSW_S1)
#else
#define BF_CSU_CSL24_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL24_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL24_NSW_S1(v)   BF_CS1(CSU_CSL24, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL24, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL24_LOCK_S1      (24)
#define BM_CSU_CSL24_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL24_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL24_LOCK_S1)
#else
#define BF_CSU_CSL24_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL24_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL24_LOCK_S1(v)   BF_CS1(CSU_CSL24, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL25 - Config security level register 25 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl25_t;
#endif

/*
 * constants & macros for entire CSU_CSL25 register
 */
#define HW_CSU_CSL25_ADDR      (REGS_CSU_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL25           (*(volatile hw_csu_csl25_t *) HW_CSU_CSL25_ADDR)
#define HW_CSU_CSL25_RD()      (HW_CSU_CSL25.U)
#define HW_CSU_CSL25_WR(v)     (HW_CSU_CSL25.U = (v))
#define HW_CSU_CSL25_SET(v)    (HW_CSU_CSL25_WR(HW_CSU_CSL25_RD() |  (v)))
#define HW_CSU_CSL25_CLR(v)    (HW_CSU_CSL25_WR(HW_CSU_CSL25_RD() & ~(v)))
#define HW_CSU_CSL25_TOG(v)    (HW_CSU_CSL25_WR(HW_CSU_CSL25_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL25 bitfields
 */

/* --- Register HW_CSU_CSL25, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL25_SUR_S2      (0)
#define BM_CSU_CSL25_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL25_SUR_S2)
#else
#define BF_CSU_CSL25_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL25_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL25_SUR_S2(v)   BF_CS1(CSU_CSL25, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL25_SSR_S2      (1)
#define BM_CSU_CSL25_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL25_SSR_S2)
#else
#define BF_CSU_CSL25_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL25_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL25_SSR_S2(v)   BF_CS1(CSU_CSL25, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL25_NUR_S2      (2)
#define BM_CSU_CSL25_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL25_NUR_S2)
#else
#define BF_CSU_CSL25_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL25_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL25_NUR_S2(v)   BF_CS1(CSU_CSL25, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL25_NSR_S2      (3)
#define BM_CSU_CSL25_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL25_NSR_S2)
#else
#define BF_CSU_CSL25_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL25_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL25_NSR_S2(v)   BF_CS1(CSU_CSL25, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL25_SUW_S2      (4)
#define BM_CSU_CSL25_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL25_SUW_S2)
#else
#define BF_CSU_CSL25_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL25_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL25_SUW_S2(v)   BF_CS1(CSU_CSL25, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL25_SSW_S2      (5)
#define BM_CSU_CSL25_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL25_SSW_S2)
#else
#define BF_CSU_CSL25_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL25_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL25_SSW_S2(v)   BF_CS1(CSU_CSL25, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL25_NUW_S2      (6)
#define BM_CSU_CSL25_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL25_NUW_S2)
#else
#define BF_CSU_CSL25_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL25_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL25_NUW_S2(v)   BF_CS1(CSU_CSL25, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL25_NSW_S2      (7)
#define BM_CSU_CSL25_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL25_NSW_S2)
#else
#define BF_CSU_CSL25_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL25_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL25_NSW_S2(v)   BF_CS1(CSU_CSL25, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL25_LOCK_S2      (8)
#define BM_CSU_CSL25_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL25_LOCK_S2)
#else
#define BF_CSU_CSL25_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL25_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL25_LOCK_S2(v)   BF_CS1(CSU_CSL25, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL25, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL25_SUR_S1      (16)
#define BM_CSU_CSL25_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL25_SUR_S1)
#else
#define BF_CSU_CSL25_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL25_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL25_SUR_S1(v)   BF_CS1(CSU_CSL25, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL25, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL25_SSR_S1      (17)
#define BM_CSU_CSL25_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL25_SSR_S1)
#else
#define BF_CSU_CSL25_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL25_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL25_SSR_S1(v)   BF_CS1(CSU_CSL25, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL25, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL25_NUR_S1      (18)
#define BM_CSU_CSL25_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL25_NUR_S1)
#else
#define BF_CSU_CSL25_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL25_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL25_NUR_S1(v)   BF_CS1(CSU_CSL25, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL25, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL25_NSR_S1      (19)
#define BM_CSU_CSL25_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL25_NSR_S1)
#else
#define BF_CSU_CSL25_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL25_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL25_NSR_S1(v)   BF_CS1(CSU_CSL25, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL25, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL25_SUW_S1      (20)
#define BM_CSU_CSL25_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL25_SUW_S1)
#else
#define BF_CSU_CSL25_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL25_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL25_SUW_S1(v)   BF_CS1(CSU_CSL25, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL25, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL25_SSW_S1      (21)
#define BM_CSU_CSL25_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL25_SSW_S1)
#else
#define BF_CSU_CSL25_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL25_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL25_SSW_S1(v)   BF_CS1(CSU_CSL25, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL25, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL25_NUW_S1      (22)
#define BM_CSU_CSL25_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL25_NUW_S1)
#else
#define BF_CSU_CSL25_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL25_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL25_NUW_S1(v)   BF_CS1(CSU_CSL25, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL25, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL25_NSW_S1      (23)
#define BM_CSU_CSL25_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL25_NSW_S1)
#else
#define BF_CSU_CSL25_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL25_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL25_NSW_S1(v)   BF_CS1(CSU_CSL25, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL25, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL25_LOCK_S1      (24)
#define BM_CSU_CSL25_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL25_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL25_LOCK_S1)
#else
#define BF_CSU_CSL25_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL25_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL25_LOCK_S1(v)   BF_CS1(CSU_CSL25, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL26 - Config security level register 26 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl26_t;
#endif

/*
 * constants & macros for entire CSU_CSL26 register
 */
#define HW_CSU_CSL26_ADDR      (REGS_CSU_BASE + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL26           (*(volatile hw_csu_csl26_t *) HW_CSU_CSL26_ADDR)
#define HW_CSU_CSL26_RD()      (HW_CSU_CSL26.U)
#define HW_CSU_CSL26_WR(v)     (HW_CSU_CSL26.U = (v))
#define HW_CSU_CSL26_SET(v)    (HW_CSU_CSL26_WR(HW_CSU_CSL26_RD() |  (v)))
#define HW_CSU_CSL26_CLR(v)    (HW_CSU_CSL26_WR(HW_CSU_CSL26_RD() & ~(v)))
#define HW_CSU_CSL26_TOG(v)    (HW_CSU_CSL26_WR(HW_CSU_CSL26_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL26 bitfields
 */

/* --- Register HW_CSU_CSL26, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL26_SUR_S2      (0)
#define BM_CSU_CSL26_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL26_SUR_S2)
#else
#define BF_CSU_CSL26_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL26_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL26_SUR_S2(v)   BF_CS1(CSU_CSL26, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL26_SSR_S2      (1)
#define BM_CSU_CSL26_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL26_SSR_S2)
#else
#define BF_CSU_CSL26_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL26_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL26_SSR_S2(v)   BF_CS1(CSU_CSL26, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL26_NUR_S2      (2)
#define BM_CSU_CSL26_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL26_NUR_S2)
#else
#define BF_CSU_CSL26_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL26_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL26_NUR_S2(v)   BF_CS1(CSU_CSL26, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL26_NSR_S2      (3)
#define BM_CSU_CSL26_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL26_NSR_S2)
#else
#define BF_CSU_CSL26_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL26_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL26_NSR_S2(v)   BF_CS1(CSU_CSL26, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL26_SUW_S2      (4)
#define BM_CSU_CSL26_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL26_SUW_S2)
#else
#define BF_CSU_CSL26_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL26_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL26_SUW_S2(v)   BF_CS1(CSU_CSL26, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL26_SSW_S2      (5)
#define BM_CSU_CSL26_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL26_SSW_S2)
#else
#define BF_CSU_CSL26_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL26_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL26_SSW_S2(v)   BF_CS1(CSU_CSL26, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL26_NUW_S2      (6)
#define BM_CSU_CSL26_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL26_NUW_S2)
#else
#define BF_CSU_CSL26_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL26_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL26_NUW_S2(v)   BF_CS1(CSU_CSL26, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL26_NSW_S2      (7)
#define BM_CSU_CSL26_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL26_NSW_S2)
#else
#define BF_CSU_CSL26_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL26_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL26_NSW_S2(v)   BF_CS1(CSU_CSL26, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL26_LOCK_S2      (8)
#define BM_CSU_CSL26_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL26_LOCK_S2)
#else
#define BF_CSU_CSL26_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL26_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL26_LOCK_S2(v)   BF_CS1(CSU_CSL26, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL26, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL26_SUR_S1      (16)
#define BM_CSU_CSL26_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL26_SUR_S1)
#else
#define BF_CSU_CSL26_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL26_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL26_SUR_S1(v)   BF_CS1(CSU_CSL26, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL26, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL26_SSR_S1      (17)
#define BM_CSU_CSL26_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL26_SSR_S1)
#else
#define BF_CSU_CSL26_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL26_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL26_SSR_S1(v)   BF_CS1(CSU_CSL26, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL26, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL26_NUR_S1      (18)
#define BM_CSU_CSL26_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL26_NUR_S1)
#else
#define BF_CSU_CSL26_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL26_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL26_NUR_S1(v)   BF_CS1(CSU_CSL26, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL26, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL26_NSR_S1      (19)
#define BM_CSU_CSL26_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL26_NSR_S1)
#else
#define BF_CSU_CSL26_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL26_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL26_NSR_S1(v)   BF_CS1(CSU_CSL26, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL26, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL26_SUW_S1      (20)
#define BM_CSU_CSL26_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL26_SUW_S1)
#else
#define BF_CSU_CSL26_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL26_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL26_SUW_S1(v)   BF_CS1(CSU_CSL26, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL26, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL26_SSW_S1      (21)
#define BM_CSU_CSL26_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL26_SSW_S1)
#else
#define BF_CSU_CSL26_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL26_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL26_SSW_S1(v)   BF_CS1(CSU_CSL26, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL26, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL26_NUW_S1      (22)
#define BM_CSU_CSL26_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL26_NUW_S1)
#else
#define BF_CSU_CSL26_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL26_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL26_NUW_S1(v)   BF_CS1(CSU_CSL26, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL26, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL26_NSW_S1      (23)
#define BM_CSU_CSL26_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL26_NSW_S1)
#else
#define BF_CSU_CSL26_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL26_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL26_NSW_S1(v)   BF_CS1(CSU_CSL26, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL26, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL26_LOCK_S1      (24)
#define BM_CSU_CSL26_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL26_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL26_LOCK_S1)
#else
#define BF_CSU_CSL26_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL26_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL26_LOCK_S1(v)   BF_CS1(CSU_CSL26, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL27 - Config security level register 27 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl27_t;
#endif

/*
 * constants & macros for entire CSU_CSL27 register
 */
#define HW_CSU_CSL27_ADDR      (REGS_CSU_BASE + 0x6c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL27           (*(volatile hw_csu_csl27_t *) HW_CSU_CSL27_ADDR)
#define HW_CSU_CSL27_RD()      (HW_CSU_CSL27.U)
#define HW_CSU_CSL27_WR(v)     (HW_CSU_CSL27.U = (v))
#define HW_CSU_CSL27_SET(v)    (HW_CSU_CSL27_WR(HW_CSU_CSL27_RD() |  (v)))
#define HW_CSU_CSL27_CLR(v)    (HW_CSU_CSL27_WR(HW_CSU_CSL27_RD() & ~(v)))
#define HW_CSU_CSL27_TOG(v)    (HW_CSU_CSL27_WR(HW_CSU_CSL27_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL27 bitfields
 */

/* --- Register HW_CSU_CSL27, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL27_SUR_S2      (0)
#define BM_CSU_CSL27_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL27_SUR_S2)
#else
#define BF_CSU_CSL27_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL27_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL27_SUR_S2(v)   BF_CS1(CSU_CSL27, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL27_SSR_S2      (1)
#define BM_CSU_CSL27_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL27_SSR_S2)
#else
#define BF_CSU_CSL27_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL27_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL27_SSR_S2(v)   BF_CS1(CSU_CSL27, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL27_NUR_S2      (2)
#define BM_CSU_CSL27_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL27_NUR_S2)
#else
#define BF_CSU_CSL27_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL27_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL27_NUR_S2(v)   BF_CS1(CSU_CSL27, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL27_NSR_S2      (3)
#define BM_CSU_CSL27_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL27_NSR_S2)
#else
#define BF_CSU_CSL27_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL27_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL27_NSR_S2(v)   BF_CS1(CSU_CSL27, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL27_SUW_S2      (4)
#define BM_CSU_CSL27_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL27_SUW_S2)
#else
#define BF_CSU_CSL27_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL27_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL27_SUW_S2(v)   BF_CS1(CSU_CSL27, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL27_SSW_S2      (5)
#define BM_CSU_CSL27_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL27_SSW_S2)
#else
#define BF_CSU_CSL27_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL27_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL27_SSW_S2(v)   BF_CS1(CSU_CSL27, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL27_NUW_S2      (6)
#define BM_CSU_CSL27_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL27_NUW_S2)
#else
#define BF_CSU_CSL27_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL27_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL27_NUW_S2(v)   BF_CS1(CSU_CSL27, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL27_NSW_S2      (7)
#define BM_CSU_CSL27_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL27_NSW_S2)
#else
#define BF_CSU_CSL27_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL27_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL27_NSW_S2(v)   BF_CS1(CSU_CSL27, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL27_LOCK_S2      (8)
#define BM_CSU_CSL27_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL27_LOCK_S2)
#else
#define BF_CSU_CSL27_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL27_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL27_LOCK_S2(v)   BF_CS1(CSU_CSL27, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL27, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL27_SUR_S1      (16)
#define BM_CSU_CSL27_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL27_SUR_S1)
#else
#define BF_CSU_CSL27_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL27_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL27_SUR_S1(v)   BF_CS1(CSU_CSL27, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL27, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL27_SSR_S1      (17)
#define BM_CSU_CSL27_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL27_SSR_S1)
#else
#define BF_CSU_CSL27_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL27_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL27_SSR_S1(v)   BF_CS1(CSU_CSL27, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL27, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL27_NUR_S1      (18)
#define BM_CSU_CSL27_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL27_NUR_S1)
#else
#define BF_CSU_CSL27_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL27_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL27_NUR_S1(v)   BF_CS1(CSU_CSL27, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL27, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL27_NSR_S1      (19)
#define BM_CSU_CSL27_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL27_NSR_S1)
#else
#define BF_CSU_CSL27_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL27_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL27_NSR_S1(v)   BF_CS1(CSU_CSL27, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL27, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL27_SUW_S1      (20)
#define BM_CSU_CSL27_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL27_SUW_S1)
#else
#define BF_CSU_CSL27_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL27_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL27_SUW_S1(v)   BF_CS1(CSU_CSL27, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL27, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL27_SSW_S1      (21)
#define BM_CSU_CSL27_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL27_SSW_S1)
#else
#define BF_CSU_CSL27_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL27_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL27_SSW_S1(v)   BF_CS1(CSU_CSL27, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL27, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL27_NUW_S1      (22)
#define BM_CSU_CSL27_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL27_NUW_S1)
#else
#define BF_CSU_CSL27_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL27_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL27_NUW_S1(v)   BF_CS1(CSU_CSL27, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL27, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL27_NSW_S1      (23)
#define BM_CSU_CSL27_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL27_NSW_S1)
#else
#define BF_CSU_CSL27_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL27_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL27_NSW_S1(v)   BF_CS1(CSU_CSL27, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL27, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL27_LOCK_S1      (24)
#define BM_CSU_CSL27_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL27_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL27_LOCK_S1)
#else
#define BF_CSU_CSL27_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL27_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL27_LOCK_S1(v)   BF_CS1(CSU_CSL27, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL28 - Config security level register 28 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl28_t;
#endif

/*
 * constants & macros for entire CSU_CSL28 register
 */
#define HW_CSU_CSL28_ADDR      (REGS_CSU_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL28           (*(volatile hw_csu_csl28_t *) HW_CSU_CSL28_ADDR)
#define HW_CSU_CSL28_RD()      (HW_CSU_CSL28.U)
#define HW_CSU_CSL28_WR(v)     (HW_CSU_CSL28.U = (v))
#define HW_CSU_CSL28_SET(v)    (HW_CSU_CSL28_WR(HW_CSU_CSL28_RD() |  (v)))
#define HW_CSU_CSL28_CLR(v)    (HW_CSU_CSL28_WR(HW_CSU_CSL28_RD() & ~(v)))
#define HW_CSU_CSL28_TOG(v)    (HW_CSU_CSL28_WR(HW_CSU_CSL28_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL28 bitfields
 */

/* --- Register HW_CSU_CSL28, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL28_SUR_S2      (0)
#define BM_CSU_CSL28_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL28_SUR_S2)
#else
#define BF_CSU_CSL28_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL28_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL28_SUR_S2(v)   BF_CS1(CSU_CSL28, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL28_SSR_S2      (1)
#define BM_CSU_CSL28_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL28_SSR_S2)
#else
#define BF_CSU_CSL28_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL28_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL28_SSR_S2(v)   BF_CS1(CSU_CSL28, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL28_NUR_S2      (2)
#define BM_CSU_CSL28_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL28_NUR_S2)
#else
#define BF_CSU_CSL28_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL28_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL28_NUR_S2(v)   BF_CS1(CSU_CSL28, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL28_NSR_S2      (3)
#define BM_CSU_CSL28_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL28_NSR_S2)
#else
#define BF_CSU_CSL28_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL28_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL28_NSR_S2(v)   BF_CS1(CSU_CSL28, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL28_SUW_S2      (4)
#define BM_CSU_CSL28_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL28_SUW_S2)
#else
#define BF_CSU_CSL28_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL28_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL28_SUW_S2(v)   BF_CS1(CSU_CSL28, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL28_SSW_S2      (5)
#define BM_CSU_CSL28_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL28_SSW_S2)
#else
#define BF_CSU_CSL28_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL28_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL28_SSW_S2(v)   BF_CS1(CSU_CSL28, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL28_NUW_S2      (6)
#define BM_CSU_CSL28_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL28_NUW_S2)
#else
#define BF_CSU_CSL28_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL28_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL28_NUW_S2(v)   BF_CS1(CSU_CSL28, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL28_NSW_S2      (7)
#define BM_CSU_CSL28_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL28_NSW_S2)
#else
#define BF_CSU_CSL28_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL28_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL28_NSW_S2(v)   BF_CS1(CSU_CSL28, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL28_LOCK_S2      (8)
#define BM_CSU_CSL28_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL28_LOCK_S2)
#else
#define BF_CSU_CSL28_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL28_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL28_LOCK_S2(v)   BF_CS1(CSU_CSL28, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL28, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL28_SUR_S1      (16)
#define BM_CSU_CSL28_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL28_SUR_S1)
#else
#define BF_CSU_CSL28_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL28_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL28_SUR_S1(v)   BF_CS1(CSU_CSL28, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL28, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL28_SSR_S1      (17)
#define BM_CSU_CSL28_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL28_SSR_S1)
#else
#define BF_CSU_CSL28_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL28_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL28_SSR_S1(v)   BF_CS1(CSU_CSL28, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL28, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL28_NUR_S1      (18)
#define BM_CSU_CSL28_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL28_NUR_S1)
#else
#define BF_CSU_CSL28_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL28_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL28_NUR_S1(v)   BF_CS1(CSU_CSL28, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL28, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL28_NSR_S1      (19)
#define BM_CSU_CSL28_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL28_NSR_S1)
#else
#define BF_CSU_CSL28_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL28_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL28_NSR_S1(v)   BF_CS1(CSU_CSL28, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL28, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL28_SUW_S1      (20)
#define BM_CSU_CSL28_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL28_SUW_S1)
#else
#define BF_CSU_CSL28_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL28_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL28_SUW_S1(v)   BF_CS1(CSU_CSL28, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL28, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL28_SSW_S1      (21)
#define BM_CSU_CSL28_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL28_SSW_S1)
#else
#define BF_CSU_CSL28_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL28_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL28_SSW_S1(v)   BF_CS1(CSU_CSL28, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL28, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL28_NUW_S1      (22)
#define BM_CSU_CSL28_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL28_NUW_S1)
#else
#define BF_CSU_CSL28_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL28_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL28_NUW_S1(v)   BF_CS1(CSU_CSL28, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL28, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL28_NSW_S1      (23)
#define BM_CSU_CSL28_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL28_NSW_S1)
#else
#define BF_CSU_CSL28_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL28_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL28_NSW_S1(v)   BF_CS1(CSU_CSL28, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL28, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL28_LOCK_S1      (24)
#define BM_CSU_CSL28_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL28_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL28_LOCK_S1)
#else
#define BF_CSU_CSL28_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL28_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL28_LOCK_S1(v)   BF_CS1(CSU_CSL28, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL29 - Config security level register 29 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl29_t;
#endif

/*
 * constants & macros for entire CSU_CSL29 register
 */
#define HW_CSU_CSL29_ADDR      (REGS_CSU_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL29           (*(volatile hw_csu_csl29_t *) HW_CSU_CSL29_ADDR)
#define HW_CSU_CSL29_RD()      (HW_CSU_CSL29.U)
#define HW_CSU_CSL29_WR(v)     (HW_CSU_CSL29.U = (v))
#define HW_CSU_CSL29_SET(v)    (HW_CSU_CSL29_WR(HW_CSU_CSL29_RD() |  (v)))
#define HW_CSU_CSL29_CLR(v)    (HW_CSU_CSL29_WR(HW_CSU_CSL29_RD() & ~(v)))
#define HW_CSU_CSL29_TOG(v)    (HW_CSU_CSL29_WR(HW_CSU_CSL29_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL29 bitfields
 */

/* --- Register HW_CSU_CSL29, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL29_SUR_S2      (0)
#define BM_CSU_CSL29_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL29_SUR_S2)
#else
#define BF_CSU_CSL29_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL29_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL29_SUR_S2(v)   BF_CS1(CSU_CSL29, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL29_SSR_S2      (1)
#define BM_CSU_CSL29_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL29_SSR_S2)
#else
#define BF_CSU_CSL29_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL29_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL29_SSR_S2(v)   BF_CS1(CSU_CSL29, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL29_NUR_S2      (2)
#define BM_CSU_CSL29_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL29_NUR_S2)
#else
#define BF_CSU_CSL29_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL29_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL29_NUR_S2(v)   BF_CS1(CSU_CSL29, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL29_NSR_S2      (3)
#define BM_CSU_CSL29_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL29_NSR_S2)
#else
#define BF_CSU_CSL29_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL29_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL29_NSR_S2(v)   BF_CS1(CSU_CSL29, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL29_SUW_S2      (4)
#define BM_CSU_CSL29_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL29_SUW_S2)
#else
#define BF_CSU_CSL29_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL29_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL29_SUW_S2(v)   BF_CS1(CSU_CSL29, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL29_SSW_S2      (5)
#define BM_CSU_CSL29_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL29_SSW_S2)
#else
#define BF_CSU_CSL29_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL29_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL29_SSW_S2(v)   BF_CS1(CSU_CSL29, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL29_NUW_S2      (6)
#define BM_CSU_CSL29_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL29_NUW_S2)
#else
#define BF_CSU_CSL29_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL29_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL29_NUW_S2(v)   BF_CS1(CSU_CSL29, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL29_NSW_S2      (7)
#define BM_CSU_CSL29_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL29_NSW_S2)
#else
#define BF_CSU_CSL29_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL29_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL29_NSW_S2(v)   BF_CS1(CSU_CSL29, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL29_LOCK_S2      (8)
#define BM_CSU_CSL29_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL29_LOCK_S2)
#else
#define BF_CSU_CSL29_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL29_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL29_LOCK_S2(v)   BF_CS1(CSU_CSL29, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL29, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL29_SUR_S1      (16)
#define BM_CSU_CSL29_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL29_SUR_S1)
#else
#define BF_CSU_CSL29_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL29_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL29_SUR_S1(v)   BF_CS1(CSU_CSL29, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL29, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL29_SSR_S1      (17)
#define BM_CSU_CSL29_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL29_SSR_S1)
#else
#define BF_CSU_CSL29_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL29_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL29_SSR_S1(v)   BF_CS1(CSU_CSL29, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL29, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL29_NUR_S1      (18)
#define BM_CSU_CSL29_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL29_NUR_S1)
#else
#define BF_CSU_CSL29_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL29_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL29_NUR_S1(v)   BF_CS1(CSU_CSL29, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL29, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL29_NSR_S1      (19)
#define BM_CSU_CSL29_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL29_NSR_S1)
#else
#define BF_CSU_CSL29_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL29_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL29_NSR_S1(v)   BF_CS1(CSU_CSL29, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL29, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL29_SUW_S1      (20)
#define BM_CSU_CSL29_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL29_SUW_S1)
#else
#define BF_CSU_CSL29_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL29_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL29_SUW_S1(v)   BF_CS1(CSU_CSL29, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL29, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL29_SSW_S1      (21)
#define BM_CSU_CSL29_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL29_SSW_S1)
#else
#define BF_CSU_CSL29_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL29_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL29_SSW_S1(v)   BF_CS1(CSU_CSL29, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL29, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL29_NUW_S1      (22)
#define BM_CSU_CSL29_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL29_NUW_S1)
#else
#define BF_CSU_CSL29_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL29_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL29_NUW_S1(v)   BF_CS1(CSU_CSL29, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL29, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL29_NSW_S1      (23)
#define BM_CSU_CSL29_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL29_NSW_S1)
#else
#define BF_CSU_CSL29_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL29_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL29_NSW_S1(v)   BF_CS1(CSU_CSL29, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL29, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL29_LOCK_S1      (24)
#define BM_CSU_CSL29_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL29_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL29_LOCK_S1)
#else
#define BF_CSU_CSL29_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL29_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL29_LOCK_S1(v)   BF_CS1(CSU_CSL29, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL30 - Config security level register 30 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl30_t;
#endif

/*
 * constants & macros for entire CSU_CSL30 register
 */
#define HW_CSU_CSL30_ADDR      (REGS_CSU_BASE + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL30           (*(volatile hw_csu_csl30_t *) HW_CSU_CSL30_ADDR)
#define HW_CSU_CSL30_RD()      (HW_CSU_CSL30.U)
#define HW_CSU_CSL30_WR(v)     (HW_CSU_CSL30.U = (v))
#define HW_CSU_CSL30_SET(v)    (HW_CSU_CSL30_WR(HW_CSU_CSL30_RD() |  (v)))
#define HW_CSU_CSL30_CLR(v)    (HW_CSU_CSL30_WR(HW_CSU_CSL30_RD() & ~(v)))
#define HW_CSU_CSL30_TOG(v)    (HW_CSU_CSL30_WR(HW_CSU_CSL30_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL30 bitfields
 */

/* --- Register HW_CSU_CSL30, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL30_SUR_S2      (0)
#define BM_CSU_CSL30_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL30_SUR_S2)
#else
#define BF_CSU_CSL30_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL30_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL30_SUR_S2(v)   BF_CS1(CSU_CSL30, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL30_SSR_S2      (1)
#define BM_CSU_CSL30_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL30_SSR_S2)
#else
#define BF_CSU_CSL30_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL30_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL30_SSR_S2(v)   BF_CS1(CSU_CSL30, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL30_NUR_S2      (2)
#define BM_CSU_CSL30_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL30_NUR_S2)
#else
#define BF_CSU_CSL30_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL30_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL30_NUR_S2(v)   BF_CS1(CSU_CSL30, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL30_NSR_S2      (3)
#define BM_CSU_CSL30_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL30_NSR_S2)
#else
#define BF_CSU_CSL30_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL30_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL30_NSR_S2(v)   BF_CS1(CSU_CSL30, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL30_SUW_S2      (4)
#define BM_CSU_CSL30_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL30_SUW_S2)
#else
#define BF_CSU_CSL30_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL30_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL30_SUW_S2(v)   BF_CS1(CSU_CSL30, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL30_SSW_S2      (5)
#define BM_CSU_CSL30_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL30_SSW_S2)
#else
#define BF_CSU_CSL30_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL30_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL30_SSW_S2(v)   BF_CS1(CSU_CSL30, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL30_NUW_S2      (6)
#define BM_CSU_CSL30_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL30_NUW_S2)
#else
#define BF_CSU_CSL30_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL30_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL30_NUW_S2(v)   BF_CS1(CSU_CSL30, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL30_NSW_S2      (7)
#define BM_CSU_CSL30_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL30_NSW_S2)
#else
#define BF_CSU_CSL30_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL30_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL30_NSW_S2(v)   BF_CS1(CSU_CSL30, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL30_LOCK_S2      (8)
#define BM_CSU_CSL30_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL30_LOCK_S2)
#else
#define BF_CSU_CSL30_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL30_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL30_LOCK_S2(v)   BF_CS1(CSU_CSL30, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL30, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL30_SUR_S1      (16)
#define BM_CSU_CSL30_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL30_SUR_S1)
#else
#define BF_CSU_CSL30_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL30_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL30_SUR_S1(v)   BF_CS1(CSU_CSL30, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL30, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL30_SSR_S1      (17)
#define BM_CSU_CSL30_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL30_SSR_S1)
#else
#define BF_CSU_CSL30_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL30_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL30_SSR_S1(v)   BF_CS1(CSU_CSL30, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL30, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL30_NUR_S1      (18)
#define BM_CSU_CSL30_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL30_NUR_S1)
#else
#define BF_CSU_CSL30_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL30_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL30_NUR_S1(v)   BF_CS1(CSU_CSL30, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL30, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL30_NSR_S1      (19)
#define BM_CSU_CSL30_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL30_NSR_S1)
#else
#define BF_CSU_CSL30_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL30_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL30_NSR_S1(v)   BF_CS1(CSU_CSL30, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL30, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL30_SUW_S1      (20)
#define BM_CSU_CSL30_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL30_SUW_S1)
#else
#define BF_CSU_CSL30_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL30_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL30_SUW_S1(v)   BF_CS1(CSU_CSL30, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL30, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL30_SSW_S1      (21)
#define BM_CSU_CSL30_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL30_SSW_S1)
#else
#define BF_CSU_CSL30_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL30_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL30_SSW_S1(v)   BF_CS1(CSU_CSL30, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL30, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL30_NUW_S1      (22)
#define BM_CSU_CSL30_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL30_NUW_S1)
#else
#define BF_CSU_CSL30_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL30_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL30_NUW_S1(v)   BF_CS1(CSU_CSL30, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL30, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL30_NSW_S1      (23)
#define BM_CSU_CSL30_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL30_NSW_S1)
#else
#define BF_CSU_CSL30_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL30_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL30_NSW_S1(v)   BF_CS1(CSU_CSL30, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL30, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL30_LOCK_S1      (24)
#define BM_CSU_CSL30_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL30_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL30_LOCK_S1)
#else
#define BF_CSU_CSL30_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL30_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL30_LOCK_S1(v)   BF_CS1(CSU_CSL30, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL31 - Config security level register 31 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl31_t;
#endif

/*
 * constants & macros for entire CSU_CSL31 register
 */
#define HW_CSU_CSL31_ADDR      (REGS_CSU_BASE + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL31           (*(volatile hw_csu_csl31_t *) HW_CSU_CSL31_ADDR)
#define HW_CSU_CSL31_RD()      (HW_CSU_CSL31.U)
#define HW_CSU_CSL31_WR(v)     (HW_CSU_CSL31.U = (v))
#define HW_CSU_CSL31_SET(v)    (HW_CSU_CSL31_WR(HW_CSU_CSL31_RD() |  (v)))
#define HW_CSU_CSL31_CLR(v)    (HW_CSU_CSL31_WR(HW_CSU_CSL31_RD() & ~(v)))
#define HW_CSU_CSL31_TOG(v)    (HW_CSU_CSL31_WR(HW_CSU_CSL31_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL31 bitfields
 */

/* --- Register HW_CSU_CSL31, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL31_SUR_S2      (0)
#define BM_CSU_CSL31_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL31_SUR_S2)
#else
#define BF_CSU_CSL31_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL31_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL31_SUR_S2(v)   BF_CS1(CSU_CSL31, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL31_SSR_S2      (1)
#define BM_CSU_CSL31_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL31_SSR_S2)
#else
#define BF_CSU_CSL31_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL31_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL31_SSR_S2(v)   BF_CS1(CSU_CSL31, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL31_NUR_S2      (2)
#define BM_CSU_CSL31_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL31_NUR_S2)
#else
#define BF_CSU_CSL31_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL31_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL31_NUR_S2(v)   BF_CS1(CSU_CSL31, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL31_NSR_S2      (3)
#define BM_CSU_CSL31_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL31_NSR_S2)
#else
#define BF_CSU_CSL31_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL31_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL31_NSR_S2(v)   BF_CS1(CSU_CSL31, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL31_SUW_S2      (4)
#define BM_CSU_CSL31_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL31_SUW_S2)
#else
#define BF_CSU_CSL31_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL31_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL31_SUW_S2(v)   BF_CS1(CSU_CSL31, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL31_SSW_S2      (5)
#define BM_CSU_CSL31_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL31_SSW_S2)
#else
#define BF_CSU_CSL31_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL31_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL31_SSW_S2(v)   BF_CS1(CSU_CSL31, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL31_NUW_S2      (6)
#define BM_CSU_CSL31_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL31_NUW_S2)
#else
#define BF_CSU_CSL31_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL31_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL31_NUW_S2(v)   BF_CS1(CSU_CSL31, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL31_NSW_S2      (7)
#define BM_CSU_CSL31_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL31_NSW_S2)
#else
#define BF_CSU_CSL31_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL31_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL31_NSW_S2(v)   BF_CS1(CSU_CSL31, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL31_LOCK_S2      (8)
#define BM_CSU_CSL31_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL31_LOCK_S2)
#else
#define BF_CSU_CSL31_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL31_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL31_LOCK_S2(v)   BF_CS1(CSU_CSL31, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL31, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL31_SUR_S1      (16)
#define BM_CSU_CSL31_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL31_SUR_S1)
#else
#define BF_CSU_CSL31_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL31_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL31_SUR_S1(v)   BF_CS1(CSU_CSL31, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL31, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL31_SSR_S1      (17)
#define BM_CSU_CSL31_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL31_SSR_S1)
#else
#define BF_CSU_CSL31_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL31_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL31_SSR_S1(v)   BF_CS1(CSU_CSL31, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL31, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL31_NUR_S1      (18)
#define BM_CSU_CSL31_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL31_NUR_S1)
#else
#define BF_CSU_CSL31_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL31_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL31_NUR_S1(v)   BF_CS1(CSU_CSL31, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL31, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL31_NSR_S1      (19)
#define BM_CSU_CSL31_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL31_NSR_S1)
#else
#define BF_CSU_CSL31_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL31_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL31_NSR_S1(v)   BF_CS1(CSU_CSL31, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL31, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL31_SUW_S1      (20)
#define BM_CSU_CSL31_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL31_SUW_S1)
#else
#define BF_CSU_CSL31_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL31_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL31_SUW_S1(v)   BF_CS1(CSU_CSL31, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL31, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL31_SSW_S1      (21)
#define BM_CSU_CSL31_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL31_SSW_S1)
#else
#define BF_CSU_CSL31_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL31_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL31_SSW_S1(v)   BF_CS1(CSU_CSL31, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL31, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL31_NUW_S1      (22)
#define BM_CSU_CSL31_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL31_NUW_S1)
#else
#define BF_CSU_CSL31_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL31_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL31_NUW_S1(v)   BF_CS1(CSU_CSL31, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL31, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL31_NSW_S1      (23)
#define BM_CSU_CSL31_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL31_NSW_S1)
#else
#define BF_CSU_CSL31_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL31_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL31_NSW_S1(v)   BF_CS1(CSU_CSL31, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL31, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL31_LOCK_S1      (24)
#define BM_CSU_CSL31_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL31_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL31_LOCK_S1)
#else
#define BF_CSU_CSL31_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL31_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL31_LOCK_S1(v)   BF_CS1(CSU_CSL31, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL32 - Config security level register 32 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl32_t;
#endif

/*
 * constants & macros for entire CSU_CSL32 register
 */
#define HW_CSU_CSL32_ADDR      (REGS_CSU_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL32           (*(volatile hw_csu_csl32_t *) HW_CSU_CSL32_ADDR)
#define HW_CSU_CSL32_RD()      (HW_CSU_CSL32.U)
#define HW_CSU_CSL32_WR(v)     (HW_CSU_CSL32.U = (v))
#define HW_CSU_CSL32_SET(v)    (HW_CSU_CSL32_WR(HW_CSU_CSL32_RD() |  (v)))
#define HW_CSU_CSL32_CLR(v)    (HW_CSU_CSL32_WR(HW_CSU_CSL32_RD() & ~(v)))
#define HW_CSU_CSL32_TOG(v)    (HW_CSU_CSL32_WR(HW_CSU_CSL32_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL32 bitfields
 */

/* --- Register HW_CSU_CSL32, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL32_SUR_S2      (0)
#define BM_CSU_CSL32_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL32_SUR_S2)
#else
#define BF_CSU_CSL32_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL32_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL32_SUR_S2(v)   BF_CS1(CSU_CSL32, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL32_SSR_S2      (1)
#define BM_CSU_CSL32_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL32_SSR_S2)
#else
#define BF_CSU_CSL32_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL32_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL32_SSR_S2(v)   BF_CS1(CSU_CSL32, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL32_NUR_S2      (2)
#define BM_CSU_CSL32_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL32_NUR_S2)
#else
#define BF_CSU_CSL32_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL32_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL32_NUR_S2(v)   BF_CS1(CSU_CSL32, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL32_NSR_S2      (3)
#define BM_CSU_CSL32_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL32_NSR_S2)
#else
#define BF_CSU_CSL32_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL32_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL32_NSR_S2(v)   BF_CS1(CSU_CSL32, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL32_SUW_S2      (4)
#define BM_CSU_CSL32_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL32_SUW_S2)
#else
#define BF_CSU_CSL32_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL32_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL32_SUW_S2(v)   BF_CS1(CSU_CSL32, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL32_SSW_S2      (5)
#define BM_CSU_CSL32_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL32_SSW_S2)
#else
#define BF_CSU_CSL32_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL32_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL32_SSW_S2(v)   BF_CS1(CSU_CSL32, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL32_NUW_S2      (6)
#define BM_CSU_CSL32_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL32_NUW_S2)
#else
#define BF_CSU_CSL32_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL32_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL32_NUW_S2(v)   BF_CS1(CSU_CSL32, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL32_NSW_S2      (7)
#define BM_CSU_CSL32_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL32_NSW_S2)
#else
#define BF_CSU_CSL32_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL32_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL32_NSW_S2(v)   BF_CS1(CSU_CSL32, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL32_LOCK_S2      (8)
#define BM_CSU_CSL32_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL32_LOCK_S2)
#else
#define BF_CSU_CSL32_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL32_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL32_LOCK_S2(v)   BF_CS1(CSU_CSL32, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL32, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL32_SUR_S1      (16)
#define BM_CSU_CSL32_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL32_SUR_S1)
#else
#define BF_CSU_CSL32_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL32_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL32_SUR_S1(v)   BF_CS1(CSU_CSL32, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL32, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL32_SSR_S1      (17)
#define BM_CSU_CSL32_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL32_SSR_S1)
#else
#define BF_CSU_CSL32_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL32_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL32_SSR_S1(v)   BF_CS1(CSU_CSL32, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL32, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL32_NUR_S1      (18)
#define BM_CSU_CSL32_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL32_NUR_S1)
#else
#define BF_CSU_CSL32_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL32_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL32_NUR_S1(v)   BF_CS1(CSU_CSL32, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL32, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL32_NSR_S1      (19)
#define BM_CSU_CSL32_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL32_NSR_S1)
#else
#define BF_CSU_CSL32_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL32_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL32_NSR_S1(v)   BF_CS1(CSU_CSL32, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL32, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL32_SUW_S1      (20)
#define BM_CSU_CSL32_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL32_SUW_S1)
#else
#define BF_CSU_CSL32_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL32_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL32_SUW_S1(v)   BF_CS1(CSU_CSL32, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL32, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL32_SSW_S1      (21)
#define BM_CSU_CSL32_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL32_SSW_S1)
#else
#define BF_CSU_CSL32_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL32_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL32_SSW_S1(v)   BF_CS1(CSU_CSL32, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL32, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL32_NUW_S1      (22)
#define BM_CSU_CSL32_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL32_NUW_S1)
#else
#define BF_CSU_CSL32_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL32_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL32_NUW_S1(v)   BF_CS1(CSU_CSL32, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL32, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL32_NSW_S1      (23)
#define BM_CSU_CSL32_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL32_NSW_S1)
#else
#define BF_CSU_CSL32_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL32_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL32_NSW_S1(v)   BF_CS1(CSU_CSL32, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL32, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL32_LOCK_S1      (24)
#define BM_CSU_CSL32_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL32_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL32_LOCK_S1)
#else
#define BF_CSU_CSL32_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL32_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL32_LOCK_S1(v)   BF_CS1(CSU_CSL32, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL33 - Config security level register 33 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl33_t;
#endif

/*
 * constants & macros for entire CSU_CSL33 register
 */
#define HW_CSU_CSL33_ADDR      (REGS_CSU_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL33           (*(volatile hw_csu_csl33_t *) HW_CSU_CSL33_ADDR)
#define HW_CSU_CSL33_RD()      (HW_CSU_CSL33.U)
#define HW_CSU_CSL33_WR(v)     (HW_CSU_CSL33.U = (v))
#define HW_CSU_CSL33_SET(v)    (HW_CSU_CSL33_WR(HW_CSU_CSL33_RD() |  (v)))
#define HW_CSU_CSL33_CLR(v)    (HW_CSU_CSL33_WR(HW_CSU_CSL33_RD() & ~(v)))
#define HW_CSU_CSL33_TOG(v)    (HW_CSU_CSL33_WR(HW_CSU_CSL33_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL33 bitfields
 */

/* --- Register HW_CSU_CSL33, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL33_SUR_S2      (0)
#define BM_CSU_CSL33_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL33_SUR_S2)
#else
#define BF_CSU_CSL33_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL33_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL33_SUR_S2(v)   BF_CS1(CSU_CSL33, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL33_SSR_S2      (1)
#define BM_CSU_CSL33_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL33_SSR_S2)
#else
#define BF_CSU_CSL33_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL33_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL33_SSR_S2(v)   BF_CS1(CSU_CSL33, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL33_NUR_S2      (2)
#define BM_CSU_CSL33_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL33_NUR_S2)
#else
#define BF_CSU_CSL33_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL33_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL33_NUR_S2(v)   BF_CS1(CSU_CSL33, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL33_NSR_S2      (3)
#define BM_CSU_CSL33_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL33_NSR_S2)
#else
#define BF_CSU_CSL33_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL33_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL33_NSR_S2(v)   BF_CS1(CSU_CSL33, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL33_SUW_S2      (4)
#define BM_CSU_CSL33_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL33_SUW_S2)
#else
#define BF_CSU_CSL33_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL33_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL33_SUW_S2(v)   BF_CS1(CSU_CSL33, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL33_SSW_S2      (5)
#define BM_CSU_CSL33_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL33_SSW_S2)
#else
#define BF_CSU_CSL33_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL33_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL33_SSW_S2(v)   BF_CS1(CSU_CSL33, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL33_NUW_S2      (6)
#define BM_CSU_CSL33_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL33_NUW_S2)
#else
#define BF_CSU_CSL33_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL33_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL33_NUW_S2(v)   BF_CS1(CSU_CSL33, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL33_NSW_S2      (7)
#define BM_CSU_CSL33_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL33_NSW_S2)
#else
#define BF_CSU_CSL33_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL33_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL33_NSW_S2(v)   BF_CS1(CSU_CSL33, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL33_LOCK_S2      (8)
#define BM_CSU_CSL33_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL33_LOCK_S2)
#else
#define BF_CSU_CSL33_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL33_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL33_LOCK_S2(v)   BF_CS1(CSU_CSL33, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL33, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL33_SUR_S1      (16)
#define BM_CSU_CSL33_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL33_SUR_S1)
#else
#define BF_CSU_CSL33_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL33_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL33_SUR_S1(v)   BF_CS1(CSU_CSL33, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL33, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL33_SSR_S1      (17)
#define BM_CSU_CSL33_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL33_SSR_S1)
#else
#define BF_CSU_CSL33_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL33_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL33_SSR_S1(v)   BF_CS1(CSU_CSL33, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL33, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL33_NUR_S1      (18)
#define BM_CSU_CSL33_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL33_NUR_S1)
#else
#define BF_CSU_CSL33_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL33_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL33_NUR_S1(v)   BF_CS1(CSU_CSL33, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL33, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL33_NSR_S1      (19)
#define BM_CSU_CSL33_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL33_NSR_S1)
#else
#define BF_CSU_CSL33_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL33_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL33_NSR_S1(v)   BF_CS1(CSU_CSL33, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL33, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL33_SUW_S1      (20)
#define BM_CSU_CSL33_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL33_SUW_S1)
#else
#define BF_CSU_CSL33_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL33_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL33_SUW_S1(v)   BF_CS1(CSU_CSL33, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL33, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL33_SSW_S1      (21)
#define BM_CSU_CSL33_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL33_SSW_S1)
#else
#define BF_CSU_CSL33_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL33_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL33_SSW_S1(v)   BF_CS1(CSU_CSL33, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL33, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL33_NUW_S1      (22)
#define BM_CSU_CSL33_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL33_NUW_S1)
#else
#define BF_CSU_CSL33_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL33_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL33_NUW_S1(v)   BF_CS1(CSU_CSL33, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL33, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL33_NSW_S1      (23)
#define BM_CSU_CSL33_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL33_NSW_S1)
#else
#define BF_CSU_CSL33_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL33_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL33_NSW_S1(v)   BF_CS1(CSU_CSL33, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL33, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL33_LOCK_S1      (24)
#define BM_CSU_CSL33_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL33_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL33_LOCK_S1)
#else
#define BF_CSU_CSL33_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL33_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL33_LOCK_S1(v)   BF_CS1(CSU_CSL33, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL34 - Config security level register 34 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl34_t;
#endif

/*
 * constants & macros for entire CSU_CSL34 register
 */
#define HW_CSU_CSL34_ADDR      (REGS_CSU_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL34           (*(volatile hw_csu_csl34_t *) HW_CSU_CSL34_ADDR)
#define HW_CSU_CSL34_RD()      (HW_CSU_CSL34.U)
#define HW_CSU_CSL34_WR(v)     (HW_CSU_CSL34.U = (v))
#define HW_CSU_CSL34_SET(v)    (HW_CSU_CSL34_WR(HW_CSU_CSL34_RD() |  (v)))
#define HW_CSU_CSL34_CLR(v)    (HW_CSU_CSL34_WR(HW_CSU_CSL34_RD() & ~(v)))
#define HW_CSU_CSL34_TOG(v)    (HW_CSU_CSL34_WR(HW_CSU_CSL34_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL34 bitfields
 */

/* --- Register HW_CSU_CSL34, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL34_SUR_S2      (0)
#define BM_CSU_CSL34_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL34_SUR_S2)
#else
#define BF_CSU_CSL34_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL34_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL34_SUR_S2(v)   BF_CS1(CSU_CSL34, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL34_SSR_S2      (1)
#define BM_CSU_CSL34_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL34_SSR_S2)
#else
#define BF_CSU_CSL34_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL34_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL34_SSR_S2(v)   BF_CS1(CSU_CSL34, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL34_NUR_S2      (2)
#define BM_CSU_CSL34_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL34_NUR_S2)
#else
#define BF_CSU_CSL34_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL34_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL34_NUR_S2(v)   BF_CS1(CSU_CSL34, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL34_NSR_S2      (3)
#define BM_CSU_CSL34_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL34_NSR_S2)
#else
#define BF_CSU_CSL34_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL34_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL34_NSR_S2(v)   BF_CS1(CSU_CSL34, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL34_SUW_S2      (4)
#define BM_CSU_CSL34_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL34_SUW_S2)
#else
#define BF_CSU_CSL34_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL34_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL34_SUW_S2(v)   BF_CS1(CSU_CSL34, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL34_SSW_S2      (5)
#define BM_CSU_CSL34_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL34_SSW_S2)
#else
#define BF_CSU_CSL34_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL34_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL34_SSW_S2(v)   BF_CS1(CSU_CSL34, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL34_NUW_S2      (6)
#define BM_CSU_CSL34_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL34_NUW_S2)
#else
#define BF_CSU_CSL34_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL34_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL34_NUW_S2(v)   BF_CS1(CSU_CSL34, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL34_NSW_S2      (7)
#define BM_CSU_CSL34_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL34_NSW_S2)
#else
#define BF_CSU_CSL34_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL34_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL34_NSW_S2(v)   BF_CS1(CSU_CSL34, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL34_LOCK_S2      (8)
#define BM_CSU_CSL34_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL34_LOCK_S2)
#else
#define BF_CSU_CSL34_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL34_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL34_LOCK_S2(v)   BF_CS1(CSU_CSL34, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL34, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL34_SUR_S1      (16)
#define BM_CSU_CSL34_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL34_SUR_S1)
#else
#define BF_CSU_CSL34_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL34_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL34_SUR_S1(v)   BF_CS1(CSU_CSL34, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL34, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL34_SSR_S1      (17)
#define BM_CSU_CSL34_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL34_SSR_S1)
#else
#define BF_CSU_CSL34_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL34_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL34_SSR_S1(v)   BF_CS1(CSU_CSL34, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL34, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL34_NUR_S1      (18)
#define BM_CSU_CSL34_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL34_NUR_S1)
#else
#define BF_CSU_CSL34_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL34_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL34_NUR_S1(v)   BF_CS1(CSU_CSL34, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL34, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL34_NSR_S1      (19)
#define BM_CSU_CSL34_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL34_NSR_S1)
#else
#define BF_CSU_CSL34_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL34_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL34_NSR_S1(v)   BF_CS1(CSU_CSL34, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL34, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL34_SUW_S1      (20)
#define BM_CSU_CSL34_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL34_SUW_S1)
#else
#define BF_CSU_CSL34_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL34_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL34_SUW_S1(v)   BF_CS1(CSU_CSL34, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL34, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL34_SSW_S1      (21)
#define BM_CSU_CSL34_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL34_SSW_S1)
#else
#define BF_CSU_CSL34_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL34_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL34_SSW_S1(v)   BF_CS1(CSU_CSL34, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL34, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL34_NUW_S1      (22)
#define BM_CSU_CSL34_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL34_NUW_S1)
#else
#define BF_CSU_CSL34_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL34_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL34_NUW_S1(v)   BF_CS1(CSU_CSL34, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL34, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL34_NSW_S1      (23)
#define BM_CSU_CSL34_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL34_NSW_S1)
#else
#define BF_CSU_CSL34_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL34_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL34_NSW_S1(v)   BF_CS1(CSU_CSL34, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL34, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL34_LOCK_S1      (24)
#define BM_CSU_CSL34_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL34_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL34_LOCK_S1)
#else
#define BF_CSU_CSL34_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL34_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL34_LOCK_S1(v)   BF_CS1(CSU_CSL34, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL35 - Config security level register 35 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl35_t;
#endif

/*
 * constants & macros for entire CSU_CSL35 register
 */
#define HW_CSU_CSL35_ADDR      (REGS_CSU_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL35           (*(volatile hw_csu_csl35_t *) HW_CSU_CSL35_ADDR)
#define HW_CSU_CSL35_RD()      (HW_CSU_CSL35.U)
#define HW_CSU_CSL35_WR(v)     (HW_CSU_CSL35.U = (v))
#define HW_CSU_CSL35_SET(v)    (HW_CSU_CSL35_WR(HW_CSU_CSL35_RD() |  (v)))
#define HW_CSU_CSL35_CLR(v)    (HW_CSU_CSL35_WR(HW_CSU_CSL35_RD() & ~(v)))
#define HW_CSU_CSL35_TOG(v)    (HW_CSU_CSL35_WR(HW_CSU_CSL35_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL35 bitfields
 */

/* --- Register HW_CSU_CSL35, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL35_SUR_S2      (0)
#define BM_CSU_CSL35_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL35_SUR_S2)
#else
#define BF_CSU_CSL35_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL35_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL35_SUR_S2(v)   BF_CS1(CSU_CSL35, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL35_SSR_S2      (1)
#define BM_CSU_CSL35_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL35_SSR_S2)
#else
#define BF_CSU_CSL35_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL35_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL35_SSR_S2(v)   BF_CS1(CSU_CSL35, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL35_NUR_S2      (2)
#define BM_CSU_CSL35_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL35_NUR_S2)
#else
#define BF_CSU_CSL35_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL35_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL35_NUR_S2(v)   BF_CS1(CSU_CSL35, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL35_NSR_S2      (3)
#define BM_CSU_CSL35_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL35_NSR_S2)
#else
#define BF_CSU_CSL35_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL35_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL35_NSR_S2(v)   BF_CS1(CSU_CSL35, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL35_SUW_S2      (4)
#define BM_CSU_CSL35_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL35_SUW_S2)
#else
#define BF_CSU_CSL35_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL35_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL35_SUW_S2(v)   BF_CS1(CSU_CSL35, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL35_SSW_S2      (5)
#define BM_CSU_CSL35_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL35_SSW_S2)
#else
#define BF_CSU_CSL35_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL35_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL35_SSW_S2(v)   BF_CS1(CSU_CSL35, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL35_NUW_S2      (6)
#define BM_CSU_CSL35_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL35_NUW_S2)
#else
#define BF_CSU_CSL35_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL35_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL35_NUW_S2(v)   BF_CS1(CSU_CSL35, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL35_NSW_S2      (7)
#define BM_CSU_CSL35_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL35_NSW_S2)
#else
#define BF_CSU_CSL35_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL35_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL35_NSW_S2(v)   BF_CS1(CSU_CSL35, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL35_LOCK_S2      (8)
#define BM_CSU_CSL35_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL35_LOCK_S2)
#else
#define BF_CSU_CSL35_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL35_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL35_LOCK_S2(v)   BF_CS1(CSU_CSL35, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL35, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL35_SUR_S1      (16)
#define BM_CSU_CSL35_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL35_SUR_S1)
#else
#define BF_CSU_CSL35_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL35_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL35_SUR_S1(v)   BF_CS1(CSU_CSL35, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL35, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL35_SSR_S1      (17)
#define BM_CSU_CSL35_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL35_SSR_S1)
#else
#define BF_CSU_CSL35_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL35_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL35_SSR_S1(v)   BF_CS1(CSU_CSL35, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL35, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL35_NUR_S1      (18)
#define BM_CSU_CSL35_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL35_NUR_S1)
#else
#define BF_CSU_CSL35_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL35_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL35_NUR_S1(v)   BF_CS1(CSU_CSL35, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL35, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL35_NSR_S1      (19)
#define BM_CSU_CSL35_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL35_NSR_S1)
#else
#define BF_CSU_CSL35_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL35_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL35_NSR_S1(v)   BF_CS1(CSU_CSL35, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL35, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL35_SUW_S1      (20)
#define BM_CSU_CSL35_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL35_SUW_S1)
#else
#define BF_CSU_CSL35_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL35_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL35_SUW_S1(v)   BF_CS1(CSU_CSL35, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL35, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL35_SSW_S1      (21)
#define BM_CSU_CSL35_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL35_SSW_S1)
#else
#define BF_CSU_CSL35_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL35_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL35_SSW_S1(v)   BF_CS1(CSU_CSL35, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL35, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL35_NUW_S1      (22)
#define BM_CSU_CSL35_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL35_NUW_S1)
#else
#define BF_CSU_CSL35_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL35_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL35_NUW_S1(v)   BF_CS1(CSU_CSL35, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL35, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL35_NSW_S1      (23)
#define BM_CSU_CSL35_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL35_NSW_S1)
#else
#define BF_CSU_CSL35_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL35_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL35_NSW_S1(v)   BF_CS1(CSU_CSL35, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL35, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL35_LOCK_S1      (24)
#define BM_CSU_CSL35_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL35_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL35_LOCK_S1)
#else
#define BF_CSU_CSL35_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL35_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL35_LOCK_S1(v)   BF_CS1(CSU_CSL35, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL36 - Config security level register 36 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl36_t;
#endif

/*
 * constants & macros for entire CSU_CSL36 register
 */
#define HW_CSU_CSL36_ADDR      (REGS_CSU_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL36           (*(volatile hw_csu_csl36_t *) HW_CSU_CSL36_ADDR)
#define HW_CSU_CSL36_RD()      (HW_CSU_CSL36.U)
#define HW_CSU_CSL36_WR(v)     (HW_CSU_CSL36.U = (v))
#define HW_CSU_CSL36_SET(v)    (HW_CSU_CSL36_WR(HW_CSU_CSL36_RD() |  (v)))
#define HW_CSU_CSL36_CLR(v)    (HW_CSU_CSL36_WR(HW_CSU_CSL36_RD() & ~(v)))
#define HW_CSU_CSL36_TOG(v)    (HW_CSU_CSL36_WR(HW_CSU_CSL36_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL36 bitfields
 */

/* --- Register HW_CSU_CSL36, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL36_SUR_S2      (0)
#define BM_CSU_CSL36_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL36_SUR_S2)
#else
#define BF_CSU_CSL36_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL36_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL36_SUR_S2(v)   BF_CS1(CSU_CSL36, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL36_SSR_S2      (1)
#define BM_CSU_CSL36_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL36_SSR_S2)
#else
#define BF_CSU_CSL36_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL36_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL36_SSR_S2(v)   BF_CS1(CSU_CSL36, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL36_NUR_S2      (2)
#define BM_CSU_CSL36_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL36_NUR_S2)
#else
#define BF_CSU_CSL36_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL36_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL36_NUR_S2(v)   BF_CS1(CSU_CSL36, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL36_NSR_S2      (3)
#define BM_CSU_CSL36_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL36_NSR_S2)
#else
#define BF_CSU_CSL36_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL36_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL36_NSR_S2(v)   BF_CS1(CSU_CSL36, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL36_SUW_S2      (4)
#define BM_CSU_CSL36_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL36_SUW_S2)
#else
#define BF_CSU_CSL36_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL36_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL36_SUW_S2(v)   BF_CS1(CSU_CSL36, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL36_SSW_S2      (5)
#define BM_CSU_CSL36_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL36_SSW_S2)
#else
#define BF_CSU_CSL36_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL36_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL36_SSW_S2(v)   BF_CS1(CSU_CSL36, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL36_NUW_S2      (6)
#define BM_CSU_CSL36_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL36_NUW_S2)
#else
#define BF_CSU_CSL36_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL36_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL36_NUW_S2(v)   BF_CS1(CSU_CSL36, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL36_NSW_S2      (7)
#define BM_CSU_CSL36_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL36_NSW_S2)
#else
#define BF_CSU_CSL36_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL36_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL36_NSW_S2(v)   BF_CS1(CSU_CSL36, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL36_LOCK_S2      (8)
#define BM_CSU_CSL36_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL36_LOCK_S2)
#else
#define BF_CSU_CSL36_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL36_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL36_LOCK_S2(v)   BF_CS1(CSU_CSL36, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL36, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL36_SUR_S1      (16)
#define BM_CSU_CSL36_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL36_SUR_S1)
#else
#define BF_CSU_CSL36_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL36_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL36_SUR_S1(v)   BF_CS1(CSU_CSL36, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL36, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL36_SSR_S1      (17)
#define BM_CSU_CSL36_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL36_SSR_S1)
#else
#define BF_CSU_CSL36_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL36_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL36_SSR_S1(v)   BF_CS1(CSU_CSL36, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL36, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL36_NUR_S1      (18)
#define BM_CSU_CSL36_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL36_NUR_S1)
#else
#define BF_CSU_CSL36_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL36_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL36_NUR_S1(v)   BF_CS1(CSU_CSL36, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL36, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL36_NSR_S1      (19)
#define BM_CSU_CSL36_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL36_NSR_S1)
#else
#define BF_CSU_CSL36_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL36_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL36_NSR_S1(v)   BF_CS1(CSU_CSL36, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL36, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL36_SUW_S1      (20)
#define BM_CSU_CSL36_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL36_SUW_S1)
#else
#define BF_CSU_CSL36_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL36_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL36_SUW_S1(v)   BF_CS1(CSU_CSL36, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL36, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL36_SSW_S1      (21)
#define BM_CSU_CSL36_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL36_SSW_S1)
#else
#define BF_CSU_CSL36_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL36_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL36_SSW_S1(v)   BF_CS1(CSU_CSL36, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL36, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL36_NUW_S1      (22)
#define BM_CSU_CSL36_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL36_NUW_S1)
#else
#define BF_CSU_CSL36_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL36_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL36_NUW_S1(v)   BF_CS1(CSU_CSL36, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL36, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL36_NSW_S1      (23)
#define BM_CSU_CSL36_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL36_NSW_S1)
#else
#define BF_CSU_CSL36_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL36_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL36_NSW_S1(v)   BF_CS1(CSU_CSL36, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL36, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL36_LOCK_S1      (24)
#define BM_CSU_CSL36_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL36_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL36_LOCK_S1)
#else
#define BF_CSU_CSL36_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL36_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL36_LOCK_S1(v)   BF_CS1(CSU_CSL36, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL37 - Config security level register 37 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl37_t;
#endif

/*
 * constants & macros for entire CSU_CSL37 register
 */
#define HW_CSU_CSL37_ADDR      (REGS_CSU_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL37           (*(volatile hw_csu_csl37_t *) HW_CSU_CSL37_ADDR)
#define HW_CSU_CSL37_RD()      (HW_CSU_CSL37.U)
#define HW_CSU_CSL37_WR(v)     (HW_CSU_CSL37.U = (v))
#define HW_CSU_CSL37_SET(v)    (HW_CSU_CSL37_WR(HW_CSU_CSL37_RD() |  (v)))
#define HW_CSU_CSL37_CLR(v)    (HW_CSU_CSL37_WR(HW_CSU_CSL37_RD() & ~(v)))
#define HW_CSU_CSL37_TOG(v)    (HW_CSU_CSL37_WR(HW_CSU_CSL37_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL37 bitfields
 */

/* --- Register HW_CSU_CSL37, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL37_SUR_S2      (0)
#define BM_CSU_CSL37_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL37_SUR_S2)
#else
#define BF_CSU_CSL37_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL37_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL37_SUR_S2(v)   BF_CS1(CSU_CSL37, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL37_SSR_S2      (1)
#define BM_CSU_CSL37_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL37_SSR_S2)
#else
#define BF_CSU_CSL37_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL37_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL37_SSR_S2(v)   BF_CS1(CSU_CSL37, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL37_NUR_S2      (2)
#define BM_CSU_CSL37_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL37_NUR_S2)
#else
#define BF_CSU_CSL37_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL37_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL37_NUR_S2(v)   BF_CS1(CSU_CSL37, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL37_NSR_S2      (3)
#define BM_CSU_CSL37_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL37_NSR_S2)
#else
#define BF_CSU_CSL37_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL37_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL37_NSR_S2(v)   BF_CS1(CSU_CSL37, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL37_SUW_S2      (4)
#define BM_CSU_CSL37_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL37_SUW_S2)
#else
#define BF_CSU_CSL37_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL37_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL37_SUW_S2(v)   BF_CS1(CSU_CSL37, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL37_SSW_S2      (5)
#define BM_CSU_CSL37_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL37_SSW_S2)
#else
#define BF_CSU_CSL37_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL37_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL37_SSW_S2(v)   BF_CS1(CSU_CSL37, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL37_NUW_S2      (6)
#define BM_CSU_CSL37_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL37_NUW_S2)
#else
#define BF_CSU_CSL37_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL37_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL37_NUW_S2(v)   BF_CS1(CSU_CSL37, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL37_NSW_S2      (7)
#define BM_CSU_CSL37_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL37_NSW_S2)
#else
#define BF_CSU_CSL37_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL37_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL37_NSW_S2(v)   BF_CS1(CSU_CSL37, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL37_LOCK_S2      (8)
#define BM_CSU_CSL37_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL37_LOCK_S2)
#else
#define BF_CSU_CSL37_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL37_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL37_LOCK_S2(v)   BF_CS1(CSU_CSL37, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL37, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL37_SUR_S1      (16)
#define BM_CSU_CSL37_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL37_SUR_S1)
#else
#define BF_CSU_CSL37_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL37_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL37_SUR_S1(v)   BF_CS1(CSU_CSL37, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL37, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL37_SSR_S1      (17)
#define BM_CSU_CSL37_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL37_SSR_S1)
#else
#define BF_CSU_CSL37_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL37_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL37_SSR_S1(v)   BF_CS1(CSU_CSL37, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL37, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL37_NUR_S1      (18)
#define BM_CSU_CSL37_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL37_NUR_S1)
#else
#define BF_CSU_CSL37_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL37_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL37_NUR_S1(v)   BF_CS1(CSU_CSL37, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL37, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL37_NSR_S1      (19)
#define BM_CSU_CSL37_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL37_NSR_S1)
#else
#define BF_CSU_CSL37_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL37_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL37_NSR_S1(v)   BF_CS1(CSU_CSL37, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL37, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL37_SUW_S1      (20)
#define BM_CSU_CSL37_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL37_SUW_S1)
#else
#define BF_CSU_CSL37_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL37_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL37_SUW_S1(v)   BF_CS1(CSU_CSL37, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL37, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL37_SSW_S1      (21)
#define BM_CSU_CSL37_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL37_SSW_S1)
#else
#define BF_CSU_CSL37_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL37_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL37_SSW_S1(v)   BF_CS1(CSU_CSL37, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL37, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL37_NUW_S1      (22)
#define BM_CSU_CSL37_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL37_NUW_S1)
#else
#define BF_CSU_CSL37_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL37_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL37_NUW_S1(v)   BF_CS1(CSU_CSL37, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL37, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL37_NSW_S1      (23)
#define BM_CSU_CSL37_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL37_NSW_S1)
#else
#define BF_CSU_CSL37_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL37_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL37_NSW_S1(v)   BF_CS1(CSU_CSL37, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL37, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL37_LOCK_S1      (24)
#define BM_CSU_CSL37_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL37_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL37_LOCK_S1)
#else
#define BF_CSU_CSL37_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL37_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL37_LOCK_S1(v)   BF_CS1(CSU_CSL37, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL38 - Config security level register 38 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl38_t;
#endif

/*
 * constants & macros for entire CSU_CSL38 register
 */
#define HW_CSU_CSL38_ADDR      (REGS_CSU_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL38           (*(volatile hw_csu_csl38_t *) HW_CSU_CSL38_ADDR)
#define HW_CSU_CSL38_RD()      (HW_CSU_CSL38.U)
#define HW_CSU_CSL38_WR(v)     (HW_CSU_CSL38.U = (v))
#define HW_CSU_CSL38_SET(v)    (HW_CSU_CSL38_WR(HW_CSU_CSL38_RD() |  (v)))
#define HW_CSU_CSL38_CLR(v)    (HW_CSU_CSL38_WR(HW_CSU_CSL38_RD() & ~(v)))
#define HW_CSU_CSL38_TOG(v)    (HW_CSU_CSL38_WR(HW_CSU_CSL38_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL38 bitfields
 */

/* --- Register HW_CSU_CSL38, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL38_SUR_S2      (0)
#define BM_CSU_CSL38_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL38_SUR_S2)
#else
#define BF_CSU_CSL38_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL38_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL38_SUR_S2(v)   BF_CS1(CSU_CSL38, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL38_SSR_S2      (1)
#define BM_CSU_CSL38_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL38_SSR_S2)
#else
#define BF_CSU_CSL38_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL38_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL38_SSR_S2(v)   BF_CS1(CSU_CSL38, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL38_NUR_S2      (2)
#define BM_CSU_CSL38_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL38_NUR_S2)
#else
#define BF_CSU_CSL38_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL38_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL38_NUR_S2(v)   BF_CS1(CSU_CSL38, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL38_NSR_S2      (3)
#define BM_CSU_CSL38_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL38_NSR_S2)
#else
#define BF_CSU_CSL38_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL38_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL38_NSR_S2(v)   BF_CS1(CSU_CSL38, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL38_SUW_S2      (4)
#define BM_CSU_CSL38_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL38_SUW_S2)
#else
#define BF_CSU_CSL38_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL38_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL38_SUW_S2(v)   BF_CS1(CSU_CSL38, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL38_SSW_S2      (5)
#define BM_CSU_CSL38_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL38_SSW_S2)
#else
#define BF_CSU_CSL38_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL38_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL38_SSW_S2(v)   BF_CS1(CSU_CSL38, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL38_NUW_S2      (6)
#define BM_CSU_CSL38_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL38_NUW_S2)
#else
#define BF_CSU_CSL38_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL38_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL38_NUW_S2(v)   BF_CS1(CSU_CSL38, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL38_NSW_S2      (7)
#define BM_CSU_CSL38_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL38_NSW_S2)
#else
#define BF_CSU_CSL38_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL38_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL38_NSW_S2(v)   BF_CS1(CSU_CSL38, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL38_LOCK_S2      (8)
#define BM_CSU_CSL38_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL38_LOCK_S2)
#else
#define BF_CSU_CSL38_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL38_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL38_LOCK_S2(v)   BF_CS1(CSU_CSL38, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL38, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL38_SUR_S1      (16)
#define BM_CSU_CSL38_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL38_SUR_S1)
#else
#define BF_CSU_CSL38_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL38_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL38_SUR_S1(v)   BF_CS1(CSU_CSL38, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL38, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL38_SSR_S1      (17)
#define BM_CSU_CSL38_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL38_SSR_S1)
#else
#define BF_CSU_CSL38_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL38_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL38_SSR_S1(v)   BF_CS1(CSU_CSL38, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL38, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL38_NUR_S1      (18)
#define BM_CSU_CSL38_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL38_NUR_S1)
#else
#define BF_CSU_CSL38_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL38_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL38_NUR_S1(v)   BF_CS1(CSU_CSL38, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL38, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL38_NSR_S1      (19)
#define BM_CSU_CSL38_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL38_NSR_S1)
#else
#define BF_CSU_CSL38_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL38_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL38_NSR_S1(v)   BF_CS1(CSU_CSL38, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL38, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL38_SUW_S1      (20)
#define BM_CSU_CSL38_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL38_SUW_S1)
#else
#define BF_CSU_CSL38_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL38_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL38_SUW_S1(v)   BF_CS1(CSU_CSL38, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL38, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL38_SSW_S1      (21)
#define BM_CSU_CSL38_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL38_SSW_S1)
#else
#define BF_CSU_CSL38_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL38_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL38_SSW_S1(v)   BF_CS1(CSU_CSL38, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL38, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL38_NUW_S1      (22)
#define BM_CSU_CSL38_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL38_NUW_S1)
#else
#define BF_CSU_CSL38_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL38_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL38_NUW_S1(v)   BF_CS1(CSU_CSL38, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL38, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL38_NSW_S1      (23)
#define BM_CSU_CSL38_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL38_NSW_S1)
#else
#define BF_CSU_CSL38_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL38_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL38_NSW_S1(v)   BF_CS1(CSU_CSL38, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL38, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL38_LOCK_S1      (24)
#define BM_CSU_CSL38_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL38_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL38_LOCK_S1)
#else
#define BF_CSU_CSL38_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL38_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL38_LOCK_S1(v)   BF_CS1(CSU_CSL38, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_CSL39 - Config security level register 39 (RW)
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each CSU_CSL is comprised of
 * two fields, each field used to determine the read and write access permissions for a slave
 * peripheral. These 8-bit fields for the first and second slaves are in the locations b23-b16 and
 * bits b7-b0, respectively.  Permission Access Table shows security levels and csu_sec_level signal
 * levels corresponding to different values of the 8-bit CSU_CSL field for a given slave.  Memory
 * space has been reserved for 128 slaves since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two slaves. However, actual number of registers inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value -
 * 128  Possible Values - 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves
 * are grouped together in USB, Timers, PowerUp and Audio groups. The following table shows
 * allocation of CSL register per slave or group of slave modules.   CSL Slave Modules Mapping
 * Slave Module    Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4
 * CSL0 [7:0]    Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]
 * GPT  EPIT1  EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and
 * GPIO2 group      GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3
 * [7:0]    GPIO5 and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1
 * CSL4 [23:16]       WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power
 * group      IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7
 * [7:0]       SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for
 * i.MX6SDL only    CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]
 * ENET    CSL8 [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2
 * CSL10 [7:0]       USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]
 * I2C2    CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE
 * (port IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
 * OCOTP_CTRL    CSL14 [23:16]       Reserved    CSL15 [7:0]       PERFMON1  PERFMON2  PERFMON3
 * CSL15 [23:16]    PerfMon group      TZASC1    CSL16 [7:0]       TZASC2    CSL16 [23:16]
 * AUDMUX    CSL17 [7:0]       CAAM    CSL17 [23:16]       SPDIF    CSL18 [7:0]       eCSPI1
 * CSL18 [23:16]       eCSPI2    CSL19 [7:0]       eCSPI3    CSL19 [23:16]       eCSPI4    CSL20
 * [7:0]       eCSPI5  Reserved for i.MX6SDL    CSL20 [23:16]       UART1    CSL21 [7:0]       ESAI1
 * CSL21 [23:16]       SSI1    CSL22 [7:0]       SSI2    CSL22 [23:16]       SSI3    CSL23 [7:0]
 * ASRC (VIA IPSYNC)    CSL23 [23:16]       Reserved    CSL24 [7:0]       ROMCP    CSL24 [23:16]
 * Reserved    CSL25 [7:0]       Reserved    CSL25 [23:16]       OCRAM    CSL26 [7:0]       CAAM
 * CSL26 [23:16]       APBH_DMA    CSL27 [7:0]       HDMI    CSL27 [23:16]       GPU3D    CSL28[7:0]
 * SATA  Reserved for i.MX6SDL    CSL28 [23:16]       OPENVG  Reserved for i.MX6SDL    CSL29 [7:0]
 * ARM core platform DAP and platform controller    CSL29 [23:16]       HSI    CSL30 [7:0]
 * IPU1    CSL30 [23:16]       IPU2  Reserved for i.MX6SDL    CSL31 [7:0]       WEIM    CSL31
 * [23:16]       PCIE    CSL32 [7:0]       GPU2D    CSL32 [23:16]       MIPI_CORE_CSI    CSL33 [7:0]
 * MIPI_CORE_HSI    CSL33 [23:16]       VDOA    CSL34 [7:0]       UART2    CSL34 [23:16]       UART3
 * CSL35 [7:0]       UART4    CSL35 [23:16]       UART5  I2C4 for i.MX6SDL only    CSL36 [7:0]
 * DTCP    CSL36 [23:16]       Reserved    CSL37 [7:0]       Reserved    CSL37 [23:16]
 * Reserved    CSL38 [7:0]       Reserved    CSL38 [23:16]       SPBA    CSL39 [7:0]       Reserved
 * CSL39 [23:16]        Do not modify the following peripherals' CSL register bits while they are
 * being accessed through the AHB/AXI slave bus: EIM, IPU, DTCP, APBHDMA and PCIe.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUR_S2 : 1; //!< Secure user read access control for the second slave
        unsigned SSR_S2 : 1; //!< Secure supervisor read access control for the second slave
        unsigned NUR_S2 : 1; //!< Non-secure user read access control for the second slave
        unsigned NSR_S2 : 1; //!< Non-secure supervisor read access control for the second slave
        unsigned SUW_S2 : 1; //!< Secure user write access control for the second slave
        unsigned SSW_S2 : 1; //!< Secure supervisor write access control for the second slave
        unsigned NUW_S2 : 1; //!< Non-secure user write access control for the second slave
        unsigned NSW_S2 : 1; //!< Non-secure supervisor write access control for the second slave
        unsigned LOCK_S2 : 1; //!< Lock bit corresponding to the second slave. Written by secure software.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SUR_S1 : 1; //!< Secure user read access control for the first slave
        unsigned SSR_S1 : 1; //!< Secure supervisor read access control for the first slave
        unsigned NUR_S1 : 1; //!< Non-secure user read access control for the first slave
        unsigned NSR_S1 : 1; //!< Non-secure supervisor read access control for the first slave
        unsigned SUW_S1 : 1; //!< Secure user write access control for the first slave
        unsigned SSW_S1 : 1; //!< Secure supervisor write access control for the first slave
        unsigned NUW_S1 : 1; //!< Non-secure user write access control for the first slave
        unsigned NSW_S1 : 1; //!< Non-secure supervisor write access control for the first slave
        unsigned LOCK_S1 : 1; //!< Lock bit corresponding to the first slave. Written by secure software.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_csu_csl39_t;
#endif

/*
 * constants & macros for entire CSU_CSL39 register
 */
#define HW_CSU_CSL39_ADDR      (REGS_CSU_BASE + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL39           (*(volatile hw_csu_csl39_t *) HW_CSU_CSL39_ADDR)
#define HW_CSU_CSL39_RD()      (HW_CSU_CSL39.U)
#define HW_CSU_CSL39_WR(v)     (HW_CSU_CSL39.U = (v))
#define HW_CSU_CSL39_SET(v)    (HW_CSU_CSL39_WR(HW_CSU_CSL39_RD() |  (v)))
#define HW_CSU_CSL39_CLR(v)    (HW_CSU_CSL39_WR(HW_CSU_CSL39_RD() & ~(v)))
#define HW_CSU_CSL39_TOG(v)    (HW_CSU_CSL39_WR(HW_CSU_CSL39_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_CSL39 bitfields
 */

/* --- Register HW_CSU_CSL39, field SUR_S2[0:0] (RW)
 *
 * Secure user read access control for the second slave
 *
 * Values:
 * 0 - Secure user read access disabled for the second slave.
 * 1 - Secure user read access enabled for the second slave
 */

#define BP_CSU_CSL39_SUR_S2      (0)
#define BM_CSU_CSL39_SUR_S2      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL39_SUR_S2)
#else
#define BF_CSU_CSL39_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL39_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S2 field to a new value.
#define BW_CSU_CSL39_SUR_S2(v)   BF_CS1(CSU_CSL39, SUR_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field SSR_S2[1:1] (RW)
 *
 * Secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the second slave.
 * 1 - Secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL39_SSR_S2      (1)
#define BM_CSU_CSL39_SSR_S2      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL39_SSR_S2)
#else
#define BF_CSU_CSL39_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL39_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S2 field to a new value.
#define BW_CSU_CSL39_SSR_S2(v)   BF_CS1(CSU_CSL39, SSR_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field NUR_S2[2:2] (RW)
 *
 * Non-secure user read access control for the second slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the second slave.
 * 1 - Non-secure user read access enabled for the second slave.
 */

#define BP_CSU_CSL39_NUR_S2      (2)
#define BM_CSU_CSL39_NUR_S2      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL39_NUR_S2)
#else
#define BF_CSU_CSL39_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL39_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S2 field to a new value.
#define BW_CSU_CSL39_NUR_S2(v)   BF_CS1(CSU_CSL39, NUR_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field NSR_S2[3:3] (RW)
 *
 * Non-secure supervisor read access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the second slave.
 * 1 - Non-secure supervisor read access enabled for the second slave.
 */

#define BP_CSU_CSL39_NSR_S2      (3)
#define BM_CSU_CSL39_NSR_S2      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL39_NSR_S2)
#else
#define BF_CSU_CSL39_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL39_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S2 field to a new value.
#define BW_CSU_CSL39_NSR_S2(v)   BF_CS1(CSU_CSL39, NSR_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field SUW_S2[4:4] (RW)
 *
 * Secure user write access control for the second slave
 *
 * Values:
 * 0 - Secure user write access disabled for the second slave.
 * 1 - Secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL39_SUW_S2      (4)
#define BM_CSU_CSL39_SUW_S2      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL39_SUW_S2)
#else
#define BF_CSU_CSL39_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL39_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S2 field to a new value.
#define BW_CSU_CSL39_SUW_S2(v)   BF_CS1(CSU_CSL39, SUW_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field SSW_S2[5:5] (RW)
 *
 * Secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the second slave.
 * 1 - Secure supervisor write access enabled for the second slave.
 */

#define BP_CSU_CSL39_SSW_S2      (5)
#define BM_CSU_CSL39_SSW_S2      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL39_SSW_S2)
#else
#define BF_CSU_CSL39_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL39_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S2 field to a new value.
#define BW_CSU_CSL39_SSW_S2(v)   BF_CS1(CSU_CSL39, SSW_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field NUW_S2[6:6] (RW)
 *
 * Non-secure user write access control for the second slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the second slave.
 * 1 - Non-secure user write access enabled for the second slave.
 */

#define BP_CSU_CSL39_NUW_S2      (6)
#define BM_CSU_CSL39_NUW_S2      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL39_NUW_S2)
#else
#define BF_CSU_CSL39_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL39_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S2 field to a new value.
#define BW_CSU_CSL39_NUW_S2(v)   BF_CS1(CSU_CSL39, NUW_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field NSW_S2[7:7] (RW)
 *
 * Non-secure supervisor write access control for the second slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the second slave.
 * 1 - Non-secure supervisor write access enabled for the second slave
 */

#define BP_CSU_CSL39_NSW_S2      (7)
#define BM_CSU_CSL39_NSW_S2      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL39_NSW_S2)
#else
#define BF_CSU_CSL39_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL39_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S2 field to a new value.
#define BW_CSU_CSL39_NSW_S2(v)   BF_CS1(CSU_CSL39, NSW_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field LOCK_S2[8:8] (RW)
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 7-0 may be written by software
 * 1 - Bits 7-0 locked and cannot be written by software
 */

#define BP_CSU_CSL39_LOCK_S2      (8)
#define BM_CSU_CSL39_LOCK_S2      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL39_LOCK_S2)
#else
#define BF_CSU_CSL39_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL39_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S2 field to a new value.
#define BW_CSU_CSL39_LOCK_S2(v)   BF_CS1(CSU_CSL39, LOCK_S2, v)
#endif


/* --- Register HW_CSU_CSL39, field SUR_S1[16:16] (RW)
 *
 * Secure user read access control for the first slave
 *
 * Values:
 * 0 - Secure user read access disabled for the first slave.
 * 1 - Secure user read access enabled for the first slave
 */

#define BP_CSU_CSL39_SUR_S1      (16)
#define BM_CSU_CSL39_SUR_S1      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL39_SUR_S1)
#else
#define BF_CSU_CSL39_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL39_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUR_S1 field to a new value.
#define BW_CSU_CSL39_SUR_S1(v)   BF_CS1(CSU_CSL39, SUR_S1, v)
#endif


/* --- Register HW_CSU_CSL39, field SSR_S1[17:17] (RW)
 *
 * Secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor read access disabled for the first slave.
 * 1 - Secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL39_SSR_S1      (17)
#define BM_CSU_CSL39_SSR_S1      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL39_SSR_S1)
#else
#define BF_CSU_CSL39_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL39_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSR_S1 field to a new value.
#define BW_CSU_CSL39_SSR_S1(v)   BF_CS1(CSU_CSL39, SSR_S1, v)
#endif


/* --- Register HW_CSU_CSL39, field NUR_S1[18:18] (RW)
 *
 * Non-secure user read access control for the first slave
 *
 * Values:
 * 0 - Non-secure user read access disabled for the first slave.
 * 1 - Non-secure user read access enabled for the first slave.
 */

#define BP_CSU_CSL39_NUR_S1      (18)
#define BM_CSU_CSL39_NUR_S1      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL39_NUR_S1)
#else
#define BF_CSU_CSL39_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL39_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUR_S1 field to a new value.
#define BW_CSU_CSL39_NUR_S1(v)   BF_CS1(CSU_CSL39, NUR_S1, v)
#endif


/* --- Register HW_CSU_CSL39, field NSR_S1[19:19] (RW)
 *
 * Non-secure supervisor read access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor read access disabled for the first slave.
 * 1 - Non-secure supervisor read access enabled for the first slave.
 */

#define BP_CSU_CSL39_NSR_S1      (19)
#define BM_CSU_CSL39_NSR_S1      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL39_NSR_S1)
#else
#define BF_CSU_CSL39_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL39_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSR_S1 field to a new value.
#define BW_CSU_CSL39_NSR_S1(v)   BF_CS1(CSU_CSL39, NSR_S1, v)
#endif


/* --- Register HW_CSU_CSL39, field SUW_S1[20:20] (RW)
 *
 * Secure user write access control for the first slave
 *
 * Values:
 * 0 - Secure user write access disabled for the first slave.
 * 1 - Secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL39_SUW_S1      (20)
#define BM_CSU_CSL39_SUW_S1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL39_SUW_S1)
#else
#define BF_CSU_CSL39_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL39_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUW_S1 field to a new value.
#define BW_CSU_CSL39_SUW_S1(v)   BF_CS1(CSU_CSL39, SUW_S1, v)
#endif


/* --- Register HW_CSU_CSL39, field SSW_S1[21:21] (RW)
 *
 * Secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Secure supervisor write access disabled for the first slave.
 * 1 - Secure supervisor write access enabled for the first slave.
 */

#define BP_CSU_CSL39_SSW_S1      (21)
#define BM_CSU_CSL39_SSW_S1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL39_SSW_S1)
#else
#define BF_CSU_CSL39_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL39_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SSW_S1 field to a new value.
#define BW_CSU_CSL39_SSW_S1(v)   BF_CS1(CSU_CSL39, SSW_S1, v)
#endif


/* --- Register HW_CSU_CSL39, field NUW_S1[22:22] (RW)
 *
 * Non-secure user write access control for the first slave
 *
 * Values:
 * 0 - Non-secure user write access disabled for the first slave.
 * 1 - Non-secure user write access enabled for the first slave.
 */

#define BP_CSU_CSL39_NUW_S1      (22)
#define BM_CSU_CSL39_NUW_S1      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL39_NUW_S1)
#else
#define BF_CSU_CSL39_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL39_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUW_S1 field to a new value.
#define BW_CSU_CSL39_NUW_S1(v)   BF_CS1(CSU_CSL39, NUW_S1, v)
#endif


/* --- Register HW_CSU_CSL39, field NSW_S1[23:23] (RW)
 *
 * Non-secure supervisor write access control for the first slave
 *
 * Values:
 * 0 - Non-secure supervisor write access disabled for the first slave.
 * 1 - Non-secure supervisor write access enabled for the first slave
 */

#define BP_CSU_CSL39_NSW_S1      (23)
#define BM_CSU_CSL39_NSW_S1      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL39_NSW_S1)
#else
#define BF_CSU_CSL39_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL39_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NSW_S1 field to a new value.
#define BW_CSU_CSL39_NSW_S1(v)   BF_CS1(CSU_CSL39, NSW_S1, v)
#endif


/* --- Register HW_CSU_CSL39, field LOCK_S1[24:24] (RW)
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 *
 * Values:
 * 0 - Not locked. Bits 16-23 may be written by software
 * 1 - Bits 16-23 locked and cannot be written by software
 */

#define BP_CSU_CSL39_LOCK_S1      (24)
#define BM_CSU_CSL39_LOCK_S1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL39_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL39_LOCK_S1)
#else
#define BF_CSU_CSL39_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL39_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK_S1 field to a new value.
#define BW_CSU_CSL39_LOCK_S1(v)   BF_CS1(CSU_CSL39, LOCK_S1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_HP0 - HP0 register (RW)
 *
 * The SCU_HP0 and SCU_HP1 registers may be programmed to determine the privilege (either User Mode
 * or Supervisor Mode) for seventeen different master groups. The privilege of a particular master
 * group may be overridden by muxing it with the corresponding bit in this register.  The even bit
 * positions (CSU_HP0[30,28,...0] and CSU_HP1[0]) in the registers hold the privilege indicator
 * bits; while the odd bit positions (CSU_HP0[31,29,...,1] and CSU_HP1[1]) contain lock bits which
 * enable/disable writing to the corresponding privilege indicator bits.  Memory Space has been
 * reserved for 32 Masters. Since, one 32 bit register can accommodate HP fields corresponding to 16
 * masters, hence for 32 masters memory equivalent of 2 registers is reserved.However, actual number
 * of registers(flops) inferred in a design would depend on the following Parameter --- Name -
 * No_Of_Masters  Min. Value -1  Max. Value - 32  Possible Values - 1 to 32
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HP_PCIE : 1; //!< Indicate the Privilege/User Mode for PCIE.
        unsigned L_PCIE : 1; //!< Lock bit set by TZ software for HP_PCIE.
        unsigned RESERVED0 : 1; //!< Indicate the Privilege/User Mode for SATA.
        unsigned RESERVED1 : 1; //!< Lock bit set by TZ software for HP_SATA.
        unsigned HP_SDMA : 1; //!< Indicate the Privilege/User Mode for SDMA.
        unsigned L_SDMA : 1; //!< Lock bit set by TZ software for HP_SDMA.
        unsigned HP_PU : 1; //!< Indicate the Privilege/User Mode for GPU3D, GPU2D, VPU, IPU1, IPU2, OpenVG EPDC, PXP, LCDIF and VDOA. NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
        unsigned L_PU : 1; //!< Lock bit set by TZ software for HP_PU.
        unsigned HP_USB : 1; //!< Indicate the Privilege/User Mode for USB.
        unsigned L_USB : 1; //!< Lock bit set by TZ software for HP_USB.
        unsigned HP_TEST : 1; //!< Indicate the Privilege/User Mode for IOMUX Test Port.
        unsigned L_TEST : 1; //!< Lock bit set by TZ software for HP_TEST.
        unsigned HP_MLB : 1; //!< Indicate the mode Privilege/User Mode for MLB.
        unsigned L_MLB : 1; //!< Lock bit set by TZ software for HP_MLB.
        unsigned HP_CAAM : 1; //!< Indicate the Privilege/User Mode for CAAM.
        unsigned L_CAAM : 1; //!< Lock bit set by TZ software for HP_CAAM.
        unsigned HP_RAWNAND : 1; //!< Indicate the Privilege/User Mode for RawNAND.
        unsigned L_RAWNAND : 1; //!< Lock bit set by TZ software for HP_RAWNAND.
        unsigned HP_APBHDMA : 1; //!< Indicate the Privilege/User Mode for apbhdma.
        unsigned L_ABPHDMA : 1; //!< Lock bit set by TZ software for HP_APBHDMA.
        unsigned HP_ENET : 1; //!< Indicate the Privilege/User Mode for ENET.
        unsigned L_ENET : 1; //!< Lock bit set by TZ software for HP_ENET.
        unsigned HP_DAP : 1; //!< Indicate the Privilege/User Mode for DAP.
        unsigned L_DAP : 1; //!< Lock bit set by TZ software for HP_DAP.
        unsigned HP_USDHC1 : 1; //!< Indicate the Privilege/User Mode for USDHC1.
        unsigned L_USDHC1 : 1; //!< Lock bit set by TZ software for HP_USDHC1.
        unsigned HP_USDHC2 : 1; //!< Indicate the Privilege/User Mode for USDHC2.
        unsigned L_USDHC2 : 1; //!< Lock bit set by TZ software for HP_USDHC2.
        unsigned HP_USDHC3 : 1; //!< Indicate the Privilege/User Mode for USDHC3.
        unsigned L_USDHC3 : 1; //!< Lock bit set by TZ software for HP_USDHC3.
        unsigned HP_USDHC4 : 1; //!< Indicate the Privilege/User Mode for USDHC4.
        unsigned L_USDHC4 : 1; //!< Lock bit set by TZ software for HP_USDHC4.
    } B;
} hw_csu_hp0_t;
#endif

/*
 * constants & macros for entire CSU_HP0 register
 */
#define HW_CSU_HP0_ADDR      (REGS_CSU_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_HP0           (*(volatile hw_csu_hp0_t *) HW_CSU_HP0_ADDR)
#define HW_CSU_HP0_RD()      (HW_CSU_HP0.U)
#define HW_CSU_HP0_WR(v)     (HW_CSU_HP0.U = (v))
#define HW_CSU_HP0_SET(v)    (HW_CSU_HP0_WR(HW_CSU_HP0_RD() |  (v)))
#define HW_CSU_HP0_CLR(v)    (HW_CSU_HP0_WR(HW_CSU_HP0_RD() & ~(v)))
#define HW_CSU_HP0_TOG(v)    (HW_CSU_HP0_WR(HW_CSU_HP0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_HP0 bitfields
 */

/* --- Register HW_CSU_HP0, field HP_PCIE[0:0] (RW)
 *
 * Indicate the Privilege/User Mode for PCIE.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_PCIE      (0)
#define BM_CSU_HP0_HP_PCIE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_PCIE(v)   ((((reg32_t) v) << 0) & BM_CSU_HP0_HP_PCIE)
#else
#define BF_CSU_HP0_HP_PCIE(v)   (((v) << 0) & BM_CSU_HP0_HP_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_PCIE field to a new value.
#define BW_CSU_HP0_HP_PCIE(v)   BF_CS1(CSU_HP0, HP_PCIE, v)
#endif


/* --- Register HW_CSU_HP0, field L_PCIE[1:1] (RW)
 *
 * Lock bit set by TZ software for HP_PCIE.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_PCIE      (1)
#define BM_CSU_HP0_L_PCIE      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_PCIE(v)   ((((reg32_t) v) << 1) & BM_CSU_HP0_L_PCIE)
#else
#define BF_CSU_HP0_L_PCIE(v)   (((v) << 1) & BM_CSU_HP0_L_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_PCIE field to a new value.
#define BW_CSU_HP0_L_PCIE(v)   BF_CS1(CSU_HP0, L_PCIE, v)
#endif


/* --- Register HW_CSU_HP0, field HP_SDMA[4:4] (RW)
 *
 * Indicate the Privilege/User Mode for SDMA.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_SDMA      (4)
#define BM_CSU_HP0_HP_SDMA      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_SDMA(v)   ((((reg32_t) v) << 4) & BM_CSU_HP0_HP_SDMA)
#else
#define BF_CSU_HP0_HP_SDMA(v)   (((v) << 4) & BM_CSU_HP0_HP_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_SDMA field to a new value.
#define BW_CSU_HP0_HP_SDMA(v)   BF_CS1(CSU_HP0, HP_SDMA, v)
#endif


/* --- Register HW_CSU_HP0, field L_SDMA[5:5] (RW)
 *
 * Lock bit set by TZ software for HP_SDMA.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_SDMA      (5)
#define BM_CSU_HP0_L_SDMA      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_SDMA(v)   ((((reg32_t) v) << 5) & BM_CSU_HP0_L_SDMA)
#else
#define BF_CSU_HP0_L_SDMA(v)   (((v) << 5) & BM_CSU_HP0_L_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_SDMA field to a new value.
#define BW_CSU_HP0_L_SDMA(v)   BF_CS1(CSU_HP0, L_SDMA, v)
#endif


/* --- Register HW_CSU_HP0, field HP_PU[6:6] (RW)
 *
 * Indicate the Privilege/User Mode for GPU3D, GPU2D, VPU, IPU1, IPU2, OpenVG EPDC, PXP, LCDIF and
 * VDOA. NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_PU      (6)
#define BM_CSU_HP0_HP_PU      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_PU(v)   ((((reg32_t) v) << 6) & BM_CSU_HP0_HP_PU)
#else
#define BF_CSU_HP0_HP_PU(v)   (((v) << 6) & BM_CSU_HP0_HP_PU)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_PU field to a new value.
#define BW_CSU_HP0_HP_PU(v)   BF_CS1(CSU_HP0, HP_PU, v)
#endif


/* --- Register HW_CSU_HP0, field L_PU[7:7] (RW)
 *
 * Lock bit set by TZ software for HP_PU.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_PU      (7)
#define BM_CSU_HP0_L_PU      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_PU(v)   ((((reg32_t) v) << 7) & BM_CSU_HP0_L_PU)
#else
#define BF_CSU_HP0_L_PU(v)   (((v) << 7) & BM_CSU_HP0_L_PU)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_PU field to a new value.
#define BW_CSU_HP0_L_PU(v)   BF_CS1(CSU_HP0, L_PU, v)
#endif


/* --- Register HW_CSU_HP0, field HP_USB[8:8] (RW)
 *
 * Indicate the Privilege/User Mode for USB.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_USB      (8)
#define BM_CSU_HP0_HP_USB      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USB(v)   ((((reg32_t) v) << 8) & BM_CSU_HP0_HP_USB)
#else
#define BF_CSU_HP0_HP_USB(v)   (((v) << 8) & BM_CSU_HP0_HP_USB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_USB field to a new value.
#define BW_CSU_HP0_HP_USB(v)   BF_CS1(CSU_HP0, HP_USB, v)
#endif


/* --- Register HW_CSU_HP0, field L_USB[9:9] (RW)
 *
 * Lock bit set by TZ software for HP_USB.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_USB      (9)
#define BM_CSU_HP0_L_USB      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USB(v)   ((((reg32_t) v) << 9) & BM_CSU_HP0_L_USB)
#else
#define BF_CSU_HP0_L_USB(v)   (((v) << 9) & BM_CSU_HP0_L_USB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USB field to a new value.
#define BW_CSU_HP0_L_USB(v)   BF_CS1(CSU_HP0, L_USB, v)
#endif


/* --- Register HW_CSU_HP0, field HP_TEST[10:10] (RW)
 *
 * Indicate the Privilege/User Mode for IOMUX Test Port.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_TEST      (10)
#define BM_CSU_HP0_HP_TEST      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_TEST(v)   ((((reg32_t) v) << 10) & BM_CSU_HP0_HP_TEST)
#else
#define BF_CSU_HP0_HP_TEST(v)   (((v) << 10) & BM_CSU_HP0_HP_TEST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_TEST field to a new value.
#define BW_CSU_HP0_HP_TEST(v)   BF_CS1(CSU_HP0, HP_TEST, v)
#endif


/* --- Register HW_CSU_HP0, field L_TEST[11:11] (RW)
 *
 * Lock bit set by TZ software for HP_TEST.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_TEST      (11)
#define BM_CSU_HP0_L_TEST      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_TEST(v)   ((((reg32_t) v) << 11) & BM_CSU_HP0_L_TEST)
#else
#define BF_CSU_HP0_L_TEST(v)   (((v) << 11) & BM_CSU_HP0_L_TEST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_TEST field to a new value.
#define BW_CSU_HP0_L_TEST(v)   BF_CS1(CSU_HP0, L_TEST, v)
#endif


/* --- Register HW_CSU_HP0, field HP_MLB[12:12] (RW)
 *
 * Indicate the mode Privilege/User Mode for MLB.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_MLB      (12)
#define BM_CSU_HP0_HP_MLB      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_MLB(v)   ((((reg32_t) v) << 12) & BM_CSU_HP0_HP_MLB)
#else
#define BF_CSU_HP0_HP_MLB(v)   (((v) << 12) & BM_CSU_HP0_HP_MLB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_MLB field to a new value.
#define BW_CSU_HP0_HP_MLB(v)   BF_CS1(CSU_HP0, HP_MLB, v)
#endif


/* --- Register HW_CSU_HP0, field L_MLB[13:13] (RW)
 *
 * Lock bit set by TZ software for HP_MLB.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_MLB      (13)
#define BM_CSU_HP0_L_MLB      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_MLB(v)   ((((reg32_t) v) << 13) & BM_CSU_HP0_L_MLB)
#else
#define BF_CSU_HP0_L_MLB(v)   (((v) << 13) & BM_CSU_HP0_L_MLB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_MLB field to a new value.
#define BW_CSU_HP0_L_MLB(v)   BF_CS1(CSU_HP0, L_MLB, v)
#endif


/* --- Register HW_CSU_HP0, field HP_CAAM[14:14] (RW)
 *
 * Indicate the Privilege/User Mode for CAAM.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_CAAM      (14)
#define BM_CSU_HP0_HP_CAAM      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_CAAM(v)   ((((reg32_t) v) << 14) & BM_CSU_HP0_HP_CAAM)
#else
#define BF_CSU_HP0_HP_CAAM(v)   (((v) << 14) & BM_CSU_HP0_HP_CAAM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_CAAM field to a new value.
#define BW_CSU_HP0_HP_CAAM(v)   BF_CS1(CSU_HP0, HP_CAAM, v)
#endif


/* --- Register HW_CSU_HP0, field L_CAAM[15:15] (RW)
 *
 * Lock bit set by TZ software for HP_CAAM.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_CAAM      (15)
#define BM_CSU_HP0_L_CAAM      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_CAAM(v)   ((((reg32_t) v) << 15) & BM_CSU_HP0_L_CAAM)
#else
#define BF_CSU_HP0_L_CAAM(v)   (((v) << 15) & BM_CSU_HP0_L_CAAM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_CAAM field to a new value.
#define BW_CSU_HP0_L_CAAM(v)   BF_CS1(CSU_HP0, L_CAAM, v)
#endif


/* --- Register HW_CSU_HP0, field HP_RAWNAND[16:16] (RW)
 *
 * Indicate the Privilege/User Mode for RawNAND.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_RAWNAND      (16)
#define BM_CSU_HP0_HP_RAWNAND      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_RAWNAND(v)   ((((reg32_t) v) << 16) & BM_CSU_HP0_HP_RAWNAND)
#else
#define BF_CSU_HP0_HP_RAWNAND(v)   (((v) << 16) & BM_CSU_HP0_HP_RAWNAND)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_RAWNAND field to a new value.
#define BW_CSU_HP0_HP_RAWNAND(v)   BF_CS1(CSU_HP0, HP_RAWNAND, v)
#endif


/* --- Register HW_CSU_HP0, field L_RAWNAND[17:17] (RW)
 *
 * Lock bit set by TZ software for HP_RAWNAND.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_RAWNAND      (17)
#define BM_CSU_HP0_L_RAWNAND      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_RAWNAND(v)   ((((reg32_t) v) << 17) & BM_CSU_HP0_L_RAWNAND)
#else
#define BF_CSU_HP0_L_RAWNAND(v)   (((v) << 17) & BM_CSU_HP0_L_RAWNAND)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_RAWNAND field to a new value.
#define BW_CSU_HP0_L_RAWNAND(v)   BF_CS1(CSU_HP0, L_RAWNAND, v)
#endif


/* --- Register HW_CSU_HP0, field HP_APBHDMA[18:18] (RW)
 *
 * Indicate the Privilege/User Mode for apbhdma.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_APBHDMA      (18)
#define BM_CSU_HP0_HP_APBHDMA      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_APBHDMA(v)   ((((reg32_t) v) << 18) & BM_CSU_HP0_HP_APBHDMA)
#else
#define BF_CSU_HP0_HP_APBHDMA(v)   (((v) << 18) & BM_CSU_HP0_HP_APBHDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_APBHDMA field to a new value.
#define BW_CSU_HP0_HP_APBHDMA(v)   BF_CS1(CSU_HP0, HP_APBHDMA, v)
#endif


/* --- Register HW_CSU_HP0, field L_ABPHDMA[19:19] (RW)
 *
 * Lock bit set by TZ software for HP_APBHDMA.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_ABPHDMA      (19)
#define BM_CSU_HP0_L_ABPHDMA      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_ABPHDMA(v)   ((((reg32_t) v) << 19) & BM_CSU_HP0_L_ABPHDMA)
#else
#define BF_CSU_HP0_L_ABPHDMA(v)   (((v) << 19) & BM_CSU_HP0_L_ABPHDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_ABPHDMA field to a new value.
#define BW_CSU_HP0_L_ABPHDMA(v)   BF_CS1(CSU_HP0, L_ABPHDMA, v)
#endif


/* --- Register HW_CSU_HP0, field HP_ENET[20:20] (RW)
 *
 * Indicate the Privilege/User Mode for ENET.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_ENET      (20)
#define BM_CSU_HP0_HP_ENET      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_ENET(v)   ((((reg32_t) v) << 20) & BM_CSU_HP0_HP_ENET)
#else
#define BF_CSU_HP0_HP_ENET(v)   (((v) << 20) & BM_CSU_HP0_HP_ENET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_ENET field to a new value.
#define BW_CSU_HP0_HP_ENET(v)   BF_CS1(CSU_HP0, HP_ENET, v)
#endif


/* --- Register HW_CSU_HP0, field L_ENET[21:21] (RW)
 *
 * Lock bit set by TZ software for HP_ENET.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_ENET      (21)
#define BM_CSU_HP0_L_ENET      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_ENET(v)   ((((reg32_t) v) << 21) & BM_CSU_HP0_L_ENET)
#else
#define BF_CSU_HP0_L_ENET(v)   (((v) << 21) & BM_CSU_HP0_L_ENET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_ENET field to a new value.
#define BW_CSU_HP0_L_ENET(v)   BF_CS1(CSU_HP0, L_ENET, v)
#endif


/* --- Register HW_CSU_HP0, field HP_DAP[22:22] (RW)
 *
 * Indicate the Privilege/User Mode for DAP.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_DAP      (22)
#define BM_CSU_HP0_HP_DAP      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_DAP(v)   ((((reg32_t) v) << 22) & BM_CSU_HP0_HP_DAP)
#else
#define BF_CSU_HP0_HP_DAP(v)   (((v) << 22) & BM_CSU_HP0_HP_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_DAP field to a new value.
#define BW_CSU_HP0_HP_DAP(v)   BF_CS1(CSU_HP0, HP_DAP, v)
#endif


/* --- Register HW_CSU_HP0, field L_DAP[23:23] (RW)
 *
 * Lock bit set by TZ software for HP_DAP.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_DAP      (23)
#define BM_CSU_HP0_L_DAP      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_DAP(v)   ((((reg32_t) v) << 23) & BM_CSU_HP0_L_DAP)
#else
#define BF_CSU_HP0_L_DAP(v)   (((v) << 23) & BM_CSU_HP0_L_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_DAP field to a new value.
#define BW_CSU_HP0_L_DAP(v)   BF_CS1(CSU_HP0, L_DAP, v)
#endif


/* --- Register HW_CSU_HP0, field HP_USDHC1[24:24] (RW)
 *
 * Indicate the Privilege/User Mode for USDHC1.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_USDHC1      (24)
#define BM_CSU_HP0_HP_USDHC1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USDHC1(v)   ((((reg32_t) v) << 24) & BM_CSU_HP0_HP_USDHC1)
#else
#define BF_CSU_HP0_HP_USDHC1(v)   (((v) << 24) & BM_CSU_HP0_HP_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_USDHC1 field to a new value.
#define BW_CSU_HP0_HP_USDHC1(v)   BF_CS1(CSU_HP0, HP_USDHC1, v)
#endif


/* --- Register HW_CSU_HP0, field L_USDHC1[25:25] (RW)
 *
 * Lock bit set by TZ software for HP_USDHC1.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_USDHC1      (25)
#define BM_CSU_HP0_L_USDHC1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USDHC1(v)   ((((reg32_t) v) << 25) & BM_CSU_HP0_L_USDHC1)
#else
#define BF_CSU_HP0_L_USDHC1(v)   (((v) << 25) & BM_CSU_HP0_L_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC1 field to a new value.
#define BW_CSU_HP0_L_USDHC1(v)   BF_CS1(CSU_HP0, L_USDHC1, v)
#endif


/* --- Register HW_CSU_HP0, field HP_USDHC2[26:26] (RW)
 *
 * Indicate the Privilege/User Mode for USDHC2.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_USDHC2      (26)
#define BM_CSU_HP0_HP_USDHC2      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USDHC2(v)   ((((reg32_t) v) << 26) & BM_CSU_HP0_HP_USDHC2)
#else
#define BF_CSU_HP0_HP_USDHC2(v)   (((v) << 26) & BM_CSU_HP0_HP_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_USDHC2 field to a new value.
#define BW_CSU_HP0_HP_USDHC2(v)   BF_CS1(CSU_HP0, HP_USDHC2, v)
#endif


/* --- Register HW_CSU_HP0, field L_USDHC2[27:27] (RW)
 *
 * Lock bit set by TZ software for HP_USDHC2.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_USDHC2      (27)
#define BM_CSU_HP0_L_USDHC2      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USDHC2(v)   ((((reg32_t) v) << 27) & BM_CSU_HP0_L_USDHC2)
#else
#define BF_CSU_HP0_L_USDHC2(v)   (((v) << 27) & BM_CSU_HP0_L_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC2 field to a new value.
#define BW_CSU_HP0_L_USDHC2(v)   BF_CS1(CSU_HP0, L_USDHC2, v)
#endif


/* --- Register HW_CSU_HP0, field HP_USDHC3[28:28] (RW)
 *
 * Indicate the Privilege/User Mode for USDHC3.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_USDHC3      (28)
#define BM_CSU_HP0_HP_USDHC3      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USDHC3(v)   ((((reg32_t) v) << 28) & BM_CSU_HP0_HP_USDHC3)
#else
#define BF_CSU_HP0_HP_USDHC3(v)   (((v) << 28) & BM_CSU_HP0_HP_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_USDHC3 field to a new value.
#define BW_CSU_HP0_HP_USDHC3(v)   BF_CS1(CSU_HP0, HP_USDHC3, v)
#endif


/* --- Register HW_CSU_HP0, field L_USDHC3[29:29] (RW)
 *
 * Lock bit set by TZ software for HP_USDHC3.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_USDHC3      (29)
#define BM_CSU_HP0_L_USDHC3      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USDHC3(v)   ((((reg32_t) v) << 29) & BM_CSU_HP0_L_USDHC3)
#else
#define BF_CSU_HP0_L_USDHC3(v)   (((v) << 29) & BM_CSU_HP0_L_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC3 field to a new value.
#define BW_CSU_HP0_L_USDHC3(v)   BF_CS1(CSU_HP0, L_USDHC3, v)
#endif


/* --- Register HW_CSU_HP0, field HP_USDHC4[30:30] (RW)
 *
 * Indicate the Privilege/User Mode for USDHC4.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP0_HP_USDHC4      (30)
#define BM_CSU_HP0_HP_USDHC4      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USDHC4(v)   ((((reg32_t) v) << 30) & BM_CSU_HP0_HP_USDHC4)
#else
#define BF_CSU_HP0_HP_USDHC4(v)   (((v) << 30) & BM_CSU_HP0_HP_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_USDHC4 field to a new value.
#define BW_CSU_HP0_HP_USDHC4(v)   BF_CS1(CSU_HP0, HP_USDHC4, v)
#endif


/* --- Register HW_CSU_HP0, field L_USDHC4[31:31] (RW)
 *
 * Lock bit set by TZ software for HP_USDHC4.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP0_L_USDHC4      (31)
#define BM_CSU_HP0_L_USDHC4      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USDHC4(v)   ((((reg32_t) v) << 31) & BM_CSU_HP0_L_USDHC4)
#else
#define BF_CSU_HP0_L_USDHC4(v)   (((v) << 31) & BM_CSU_HP0_L_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC4 field to a new value.
#define BW_CSU_HP0_L_USDHC4(v)   BF_CS1(CSU_HP0, L_USDHC4, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_HP1 - HP1 register (RW)
 *
 * The SCU_HP1 register is an expansion of the SCU_HP0 register. See SCU_HP0 register definition.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HP_HDMI_HSI : 1; //!< Indicate the Privilege/User Mode for HDMI Tx and HSI.
        unsigned L_HDMI_HSI : 1; //!< Lock bit set by TZ software for HP_HDMI_HSI.
        unsigned RESERVED0 : 30; //!< Reserved.
    } B;
} hw_csu_hp1_t;
#endif

/*
 * constants & macros for entire CSU_HP1 register
 */
#define HW_CSU_HP1_ADDR      (REGS_CSU_BASE + 0x204)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_HP1           (*(volatile hw_csu_hp1_t *) HW_CSU_HP1_ADDR)
#define HW_CSU_HP1_RD()      (HW_CSU_HP1.U)
#define HW_CSU_HP1_WR(v)     (HW_CSU_HP1.U = (v))
#define HW_CSU_HP1_SET(v)    (HW_CSU_HP1_WR(HW_CSU_HP1_RD() |  (v)))
#define HW_CSU_HP1_CLR(v)    (HW_CSU_HP1_WR(HW_CSU_HP1_RD() & ~(v)))
#define HW_CSU_HP1_TOG(v)    (HW_CSU_HP1_WR(HW_CSU_HP1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_HP1 bitfields
 */

/* --- Register HW_CSU_HP1, field HP_HDMI_HSI[0:0] (RW)
 *
 * Indicate the Privilege/User Mode for HDMI Tx and HSI.
 *
 * Values:
 * 0 - User Mode for the corresponding master
 * 1 - Supervisor Mode for the corresponding master
 */

#define BP_CSU_HP1_HP_HDMI_HSI      (0)
#define BM_CSU_HP1_HP_HDMI_HSI      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP1_HP_HDMI_HSI(v)   ((((reg32_t) v) << 0) & BM_CSU_HP1_HP_HDMI_HSI)
#else
#define BF_CSU_HP1_HP_HDMI_HSI(v)   (((v) << 0) & BM_CSU_HP1_HP_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HP_HDMI_HSI field to a new value.
#define BW_CSU_HP1_HP_HDMI_HSI(v)   BF_CS1(CSU_HP1, HP_HDMI_HSI, v)
#endif


/* --- Register HW_CSU_HP1, field L_HDMI_HSI[1:1] (RW)
 *
 * Lock bit set by TZ software for HP_HDMI_HSI.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HP1_L_HDMI_HSI      (1)
#define BM_CSU_HP1_L_HDMI_HSI      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP1_L_HDMI_HSI(v)   ((((reg32_t) v) << 1) & BM_CSU_HP1_L_HDMI_HSI)
#else
#define BF_CSU_HP1_L_HDMI_HSI(v)   (((v) << 1) & BM_CSU_HP1_L_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_HDMI_HSI field to a new value.
#define BW_CSU_HP1_L_HDMI_HSI(v)   BF_CS1(CSU_HP1, L_HDMI_HSI, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_SA - Secure access register (RW)
 *
 * The Secure Access register may be programmed to specify the access policy (either Secure or Non-
 * secure) for up to sixteen different masters. This register is used to set the access policy for
 * Type 1 masters which are incapable of setting the policy by themselves.  The sixteen even bit
 * positions (CSU_SA[30,28,...,0]) in the register hold the policy indicator bits; while the odd bit
 * positions (CSU_SA[31,29,...,1]) contain lock bits which enable/disable writing to the
 * corresponding policy indicator bits.  Memory Space has been reserved for 32 Type 1 Masters.
 * Since, one 32 bit register can accommodate SA fields corresponding to 16 masters, hence for 32
 * masters memory equivalent of 2 registers is reserved.However, actual number of registers(flops)
 * inferred in a design would depend on the following Parameter --- Name - No_Of_TP1_Masters  Min.
 * Value -1  Max. Value - 32  Possible Values - 1 to 32
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SA_CP15 : 1; //!< Indicate the Type (Secured/Non-Secured) Access to ARM CP15 register.
        unsigned L_CP15 : 1; //!< Lock bit set by TZ software for SA_CP15.
        unsigned RESERVED0 : 1; //!< Indicate the Type (Secured/Non-Secured) Access for SATA.
        unsigned RESERVED1 : 1; //!< Lock bit set by TZ software for SA_SATA.
        unsigned SA_SDMA : 1; //!< Indicate the Type (Secured/Non-Secured) Access for SDMA.
        unsigned L_SDMA : 1; //!< Lock bit set by TZ software for SA_SDMA.
        unsigned SA_PU : 1; //!< Indicate the Type (Secured/Non-Secured) Access for GPU3D, VDOA, GPU2D, IPU1, IPU2, OPENVG EPDC, PXP, LCDIF and VPU. NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
        unsigned L_PU : 1; //!< Lock bit set by TZ software for SA_PU.
        unsigned SA_USB_MLB : 1; //!< Indicate the Type (Secured/Non-Secured) Access for USB and MLB.
        unsigned L_USB_MLB : 1; //!< Lock bit set by TZ software for SA_USB_MLB.
        unsigned SA_PCIE_TEST : 1; //!< Indicate the Type (Secured/Non-Secured) Access for PCIe and IOMUX Test Port.
        unsigned L_PCIE_TEST : 1; //!< Lock bit set by TZ software for SA_PCIE_TEST.
        unsigned RESERVED2 : 2; //!< Reserved
        unsigned SA_RAWNAND_APBHDMA : 1; //!< Indicate the Type (Secured/Non-Secured) Access for RawNAND and apbhdmat.
        unsigned L_RAWNAND_APBHDMA : 1; //!< Lock bit set by TZ software for SA_RAWNAND_APBHDMA.
        unsigned SA_ENET : 1; //!< Indicate the Type (Secured/Non-Secured) Access for ENET.
        unsigned L_ENET : 1; //!< Lock bit set by TZ software for SA_ENET.
        unsigned SA_DAP : 1; //!< Access Policy indicator bits
        unsigned L_DAP : 1; //!< Lock bit set by TZ software for SA_DAP.
        unsigned SA_USDHC1 : 1; //!< Indicate the Type (Secured/Non-Secured) Access for USDHC1.
        unsigned L_USDHC1 : 1; //!< Lock bit set by TZ software for SA_.USDHC1
        unsigned SA_USDHC2 : 1; //!< Indicate the Type (Secured/Non-Secured) Access for USDHC2.
        unsigned L_USDHC2 : 1; //!< Lock bit set by TZ software for SA_.USDHC2
        unsigned SA_USDHC3 : 1; //!< Indicate the Type (Secured/Non-Secured) Access for USDHC3.
        unsigned L_USDHC3 : 1; //!< Lock bit set by TZ software for SA_.USDHC3
        unsigned SA_USDHC4 : 1; //!< Indicate the Type (Secured/Non-Secured) Access for USDHC4.
        unsigned L_USDHC4 : 1; //!< Lock bit set by TZ software for SA_.USDHC14
        unsigned SA_HDMI_HSI : 1; //!< Indicate the Type (Secured/Non-Secured) Access for HDMI Tx and HSI.
        unsigned L_HDMI_HSI : 1; //!< Lock bit set by TZ software for SA_.HDMI_HSI
        unsigned RESERVED3 : 2; //!< Reserved
    } B;
} hw_csu_sa_t;
#endif

/*
 * constants & macros for entire CSU_SA register
 */
#define HW_CSU_SA_ADDR      (REGS_CSU_BASE + 0x218)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_SA           (*(volatile hw_csu_sa_t *) HW_CSU_SA_ADDR)
#define HW_CSU_SA_RD()      (HW_CSU_SA.U)
#define HW_CSU_SA_WR(v)     (HW_CSU_SA.U = (v))
#define HW_CSU_SA_SET(v)    (HW_CSU_SA_WR(HW_CSU_SA_RD() |  (v)))
#define HW_CSU_SA_CLR(v)    (HW_CSU_SA_WR(HW_CSU_SA_RD() & ~(v)))
#define HW_CSU_SA_TOG(v)    (HW_CSU_SA_WR(HW_CSU_SA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_SA bitfields
 */

/* --- Register HW_CSU_SA, field SA_CP15[0:0] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access to ARM CP15 register.
 *
 * Values:
 * 0 - ARM CP15 register is accesible
 * 1 - ARM CP15 register is not accesible
 */

#define BP_CSU_SA_SA_CP15      (0)
#define BM_CSU_SA_SA_CP15      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_CP15(v)   ((((reg32_t) v) << 0) & BM_CSU_SA_SA_CP15)
#else
#define BF_CSU_SA_SA_CP15(v)   (((v) << 0) & BM_CSU_SA_SA_CP15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_CP15 field to a new value.
#define BW_CSU_SA_SA_CP15(v)   BF_CS1(CSU_SA, SA_CP15, v)
#endif


/* --- Register HW_CSU_SA, field L_CP15[1:1] (RW)
 *
 * Lock bit set by TZ software for SA_CP15.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_CP15      (1)
#define BM_CSU_SA_L_CP15      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_CP15(v)   ((((reg32_t) v) << 1) & BM_CSU_SA_L_CP15)
#else
#define BF_CSU_SA_L_CP15(v)   (((v) << 1) & BM_CSU_SA_L_CP15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_CP15 field to a new value.
#define BW_CSU_SA_L_CP15(v)   BF_CS1(CSU_SA, L_CP15, v)
#endif


/* --- Register HW_CSU_SA, field SA_SDMA[4:4] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for SDMA.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_SDMA      (4)
#define BM_CSU_SA_SA_SDMA      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_SDMA(v)   ((((reg32_t) v) << 4) & BM_CSU_SA_SA_SDMA)
#else
#define BF_CSU_SA_SA_SDMA(v)   (((v) << 4) & BM_CSU_SA_SA_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_SDMA field to a new value.
#define BW_CSU_SA_SA_SDMA(v)   BF_CS1(CSU_SA, SA_SDMA, v)
#endif


/* --- Register HW_CSU_SA, field L_SDMA[5:5] (RW)
 *
 * Lock bit set by TZ software for SA_SDMA.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_SDMA      (5)
#define BM_CSU_SA_L_SDMA      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_SDMA(v)   ((((reg32_t) v) << 5) & BM_CSU_SA_L_SDMA)
#else
#define BF_CSU_SA_L_SDMA(v)   (((v) << 5) & BM_CSU_SA_L_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_SDMA field to a new value.
#define BW_CSU_SA_L_SDMA(v)   BF_CS1(CSU_SA, L_SDMA, v)
#endif


/* --- Register HW_CSU_SA, field SA_PU[6:6] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for GPU3D, VDOA, GPU2D, IPU1, IPU2, OPENVG EPDC,
 * PXP, LCDIF and VPU. NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_PU      (6)
#define BM_CSU_SA_SA_PU      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_PU(v)   ((((reg32_t) v) << 6) & BM_CSU_SA_SA_PU)
#else
#define BF_CSU_SA_SA_PU(v)   (((v) << 6) & BM_CSU_SA_SA_PU)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_PU field to a new value.
#define BW_CSU_SA_SA_PU(v)   BF_CS1(CSU_SA, SA_PU, v)
#endif


/* --- Register HW_CSU_SA, field L_PU[7:7] (RW)
 *
 * Lock bit set by TZ software for SA_PU.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_PU      (7)
#define BM_CSU_SA_L_PU      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_PU(v)   ((((reg32_t) v) << 7) & BM_CSU_SA_L_PU)
#else
#define BF_CSU_SA_L_PU(v)   (((v) << 7) & BM_CSU_SA_L_PU)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_PU field to a new value.
#define BW_CSU_SA_L_PU(v)   BF_CS1(CSU_SA, L_PU, v)
#endif


/* --- Register HW_CSU_SA, field SA_USB_MLB[8:8] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for USB and MLB.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_USB_MLB      (8)
#define BM_CSU_SA_SA_USB_MLB      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USB_MLB(v)   ((((reg32_t) v) << 8) & BM_CSU_SA_SA_USB_MLB)
#else
#define BF_CSU_SA_SA_USB_MLB(v)   (((v) << 8) & BM_CSU_SA_SA_USB_MLB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_USB_MLB field to a new value.
#define BW_CSU_SA_SA_USB_MLB(v)   BF_CS1(CSU_SA, SA_USB_MLB, v)
#endif


/* --- Register HW_CSU_SA, field L_USB_MLB[9:9] (RW)
 *
 * Lock bit set by TZ software for SA_USB_MLB.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_USB_MLB      (9)
#define BM_CSU_SA_L_USB_MLB      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USB_MLB(v)   ((((reg32_t) v) << 9) & BM_CSU_SA_L_USB_MLB)
#else
#define BF_CSU_SA_L_USB_MLB(v)   (((v) << 9) & BM_CSU_SA_L_USB_MLB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USB_MLB field to a new value.
#define BW_CSU_SA_L_USB_MLB(v)   BF_CS1(CSU_SA, L_USB_MLB, v)
#endif


/* --- Register HW_CSU_SA, field SA_PCIE_TEST[10:10] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for PCIe and IOMUX Test Port.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_PCIE_TEST      (10)
#define BM_CSU_SA_SA_PCIE_TEST      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_PCIE_TEST(v)   ((((reg32_t) v) << 10) & BM_CSU_SA_SA_PCIE_TEST)
#else
#define BF_CSU_SA_SA_PCIE_TEST(v)   (((v) << 10) & BM_CSU_SA_SA_PCIE_TEST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_PCIE_TEST field to a new value.
#define BW_CSU_SA_SA_PCIE_TEST(v)   BF_CS1(CSU_SA, SA_PCIE_TEST, v)
#endif


/* --- Register HW_CSU_SA, field L_PCIE_TEST[11:11] (RW)
 *
 * Lock bit set by TZ software for SA_PCIE_TEST.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_PCIE_TEST      (11)
#define BM_CSU_SA_L_PCIE_TEST      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_PCIE_TEST(v)   ((((reg32_t) v) << 11) & BM_CSU_SA_L_PCIE_TEST)
#else
#define BF_CSU_SA_L_PCIE_TEST(v)   (((v) << 11) & BM_CSU_SA_L_PCIE_TEST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_PCIE_TEST field to a new value.
#define BW_CSU_SA_L_PCIE_TEST(v)   BF_CS1(CSU_SA, L_PCIE_TEST, v)
#endif


/* --- Register HW_CSU_SA, field SA_RAWNAND_APBHDMA[14:14] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for RawNAND and apbhdmat.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_RAWNAND_APBHDMA      (14)
#define BM_CSU_SA_SA_RAWNAND_APBHDMA      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_RAWNAND_APBHDMA(v)   ((((reg32_t) v) << 14) & BM_CSU_SA_SA_RAWNAND_APBHDMA)
#else
#define BF_CSU_SA_SA_RAWNAND_APBHDMA(v)   (((v) << 14) & BM_CSU_SA_SA_RAWNAND_APBHDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_RAWNAND_APBHDMA field to a new value.
#define BW_CSU_SA_SA_RAWNAND_APBHDMA(v)   BF_CS1(CSU_SA, SA_RAWNAND_APBHDMA, v)
#endif


/* --- Register HW_CSU_SA, field L_RAWNAND_APBHDMA[15:15] (RW)
 *
 * Lock bit set by TZ software for SA_RAWNAND_APBHDMA.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_RAWNAND_APBHDMA      (15)
#define BM_CSU_SA_L_RAWNAND_APBHDMA      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_RAWNAND_APBHDMA(v)   ((((reg32_t) v) << 15) & BM_CSU_SA_L_RAWNAND_APBHDMA)
#else
#define BF_CSU_SA_L_RAWNAND_APBHDMA(v)   (((v) << 15) & BM_CSU_SA_L_RAWNAND_APBHDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_RAWNAND_APBHDMA field to a new value.
#define BW_CSU_SA_L_RAWNAND_APBHDMA(v)   BF_CS1(CSU_SA, L_RAWNAND_APBHDMA, v)
#endif


/* --- Register HW_CSU_SA, field SA_ENET[16:16] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for ENET.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_ENET      (16)
#define BM_CSU_SA_SA_ENET      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_ENET(v)   ((((reg32_t) v) << 16) & BM_CSU_SA_SA_ENET)
#else
#define BF_CSU_SA_SA_ENET(v)   (((v) << 16) & BM_CSU_SA_SA_ENET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_ENET field to a new value.
#define BW_CSU_SA_SA_ENET(v)   BF_CS1(CSU_SA, SA_ENET, v)
#endif


/* --- Register HW_CSU_SA, field L_ENET[17:17] (RW)
 *
 * Lock bit set by TZ software for SA_ENET.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_ENET      (17)
#define BM_CSU_SA_L_ENET      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_ENET(v)   ((((reg32_t) v) << 17) & BM_CSU_SA_L_ENET)
#else
#define BF_CSU_SA_L_ENET(v)   (((v) << 17) & BM_CSU_SA_L_ENET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_ENET field to a new value.
#define BW_CSU_SA_L_ENET(v)   BF_CS1(CSU_SA, L_ENET, v)
#endif


/* --- Register HW_CSU_SA, field SA_DAP[18:18] (RW)
 *
 * Access Policy indicator bits
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_DAP      (18)
#define BM_CSU_SA_SA_DAP      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_DAP(v)   ((((reg32_t) v) << 18) & BM_CSU_SA_SA_DAP)
#else
#define BF_CSU_SA_SA_DAP(v)   (((v) << 18) & BM_CSU_SA_SA_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_DAP field to a new value.
#define BW_CSU_SA_SA_DAP(v)   BF_CS1(CSU_SA, SA_DAP, v)
#endif


/* --- Register HW_CSU_SA, field L_DAP[19:19] (RW)
 *
 * Lock bit set by TZ software for SA_DAP.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_DAP      (19)
#define BM_CSU_SA_L_DAP      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_DAP(v)   ((((reg32_t) v) << 19) & BM_CSU_SA_L_DAP)
#else
#define BF_CSU_SA_L_DAP(v)   (((v) << 19) & BM_CSU_SA_L_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_DAP field to a new value.
#define BW_CSU_SA_L_DAP(v)   BF_CS1(CSU_SA, L_DAP, v)
#endif


/* --- Register HW_CSU_SA, field SA_USDHC1[20:20] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for USDHC1.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_USDHC1      (20)
#define BM_CSU_SA_SA_USDHC1      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USDHC1(v)   ((((reg32_t) v) << 20) & BM_CSU_SA_SA_USDHC1)
#else
#define BF_CSU_SA_SA_USDHC1(v)   (((v) << 20) & BM_CSU_SA_SA_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_USDHC1 field to a new value.
#define BW_CSU_SA_SA_USDHC1(v)   BF_CS1(CSU_SA, SA_USDHC1, v)
#endif


/* --- Register HW_CSU_SA, field L_USDHC1[21:21] (RW)
 *
 * Lock bit set by TZ software for SA_.USDHC1
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_USDHC1      (21)
#define BM_CSU_SA_L_USDHC1      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USDHC1(v)   ((((reg32_t) v) << 21) & BM_CSU_SA_L_USDHC1)
#else
#define BF_CSU_SA_L_USDHC1(v)   (((v) << 21) & BM_CSU_SA_L_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC1 field to a new value.
#define BW_CSU_SA_L_USDHC1(v)   BF_CS1(CSU_SA, L_USDHC1, v)
#endif


/* --- Register HW_CSU_SA, field SA_USDHC2[22:22] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for USDHC2.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_USDHC2      (22)
#define BM_CSU_SA_SA_USDHC2      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USDHC2(v)   ((((reg32_t) v) << 22) & BM_CSU_SA_SA_USDHC2)
#else
#define BF_CSU_SA_SA_USDHC2(v)   (((v) << 22) & BM_CSU_SA_SA_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_USDHC2 field to a new value.
#define BW_CSU_SA_SA_USDHC2(v)   BF_CS1(CSU_SA, SA_USDHC2, v)
#endif


/* --- Register HW_CSU_SA, field L_USDHC2[23:23] (RW)
 *
 * Lock bit set by TZ software for SA_.USDHC2
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_USDHC2      (23)
#define BM_CSU_SA_L_USDHC2      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USDHC2(v)   ((((reg32_t) v) << 23) & BM_CSU_SA_L_USDHC2)
#else
#define BF_CSU_SA_L_USDHC2(v)   (((v) << 23) & BM_CSU_SA_L_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC2 field to a new value.
#define BW_CSU_SA_L_USDHC2(v)   BF_CS1(CSU_SA, L_USDHC2, v)
#endif


/* --- Register HW_CSU_SA, field SA_USDHC3[24:24] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for USDHC3.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_USDHC3      (24)
#define BM_CSU_SA_SA_USDHC3      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USDHC3(v)   ((((reg32_t) v) << 24) & BM_CSU_SA_SA_USDHC3)
#else
#define BF_CSU_SA_SA_USDHC3(v)   (((v) << 24) & BM_CSU_SA_SA_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_USDHC3 field to a new value.
#define BW_CSU_SA_SA_USDHC3(v)   BF_CS1(CSU_SA, SA_USDHC3, v)
#endif


/* --- Register HW_CSU_SA, field L_USDHC3[25:25] (RW)
 *
 * Lock bit set by TZ software for SA_.USDHC3
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_USDHC3      (25)
#define BM_CSU_SA_L_USDHC3      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USDHC3(v)   ((((reg32_t) v) << 25) & BM_CSU_SA_L_USDHC3)
#else
#define BF_CSU_SA_L_USDHC3(v)   (((v) << 25) & BM_CSU_SA_L_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC3 field to a new value.
#define BW_CSU_SA_L_USDHC3(v)   BF_CS1(CSU_SA, L_USDHC3, v)
#endif


/* --- Register HW_CSU_SA, field SA_USDHC4[26:26] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for USDHC4.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_USDHC4      (26)
#define BM_CSU_SA_SA_USDHC4      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USDHC4(v)   ((((reg32_t) v) << 26) & BM_CSU_SA_SA_USDHC4)
#else
#define BF_CSU_SA_SA_USDHC4(v)   (((v) << 26) & BM_CSU_SA_SA_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_USDHC4 field to a new value.
#define BW_CSU_SA_SA_USDHC4(v)   BF_CS1(CSU_SA, SA_USDHC4, v)
#endif


/* --- Register HW_CSU_SA, field L_USDHC4[27:27] (RW)
 *
 * Lock bit set by TZ software for SA_.USDHC14
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_USDHC4      (27)
#define BM_CSU_SA_L_USDHC4      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USDHC4(v)   ((((reg32_t) v) << 27) & BM_CSU_SA_L_USDHC4)
#else
#define BF_CSU_SA_L_USDHC4(v)   (((v) << 27) & BM_CSU_SA_L_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC4 field to a new value.
#define BW_CSU_SA_L_USDHC4(v)   BF_CS1(CSU_SA, L_USDHC4, v)
#endif


/* --- Register HW_CSU_SA, field SA_HDMI_HSI[28:28] (RW)
 *
 * Indicate the Type (Secured/Non-Secured) Access for HDMI Tx and HSI.
 *
 * Values:
 * 0 - Secure access for the corresponding Type 1 master
 * 1 - Non-secure access for the corresponding Type 1 master
 */

#define BP_CSU_SA_SA_HDMI_HSI      (28)
#define BM_CSU_SA_SA_HDMI_HSI      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_HDMI_HSI(v)   ((((reg32_t) v) << 28) & BM_CSU_SA_SA_HDMI_HSI)
#else
#define BF_CSU_SA_SA_HDMI_HSI(v)   (((v) << 28) & BM_CSU_SA_SA_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SA_HDMI_HSI field to a new value.
#define BW_CSU_SA_SA_HDMI_HSI(v)   BF_CS1(CSU_SA, SA_HDMI_HSI, v)
#endif


/* --- Register HW_CSU_SA, field L_HDMI_HSI[29:29] (RW)
 *
 * Lock bit set by TZ software for SA_.HDMI_HSI
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_SA_L_HDMI_HSI      (29)
#define BM_CSU_SA_L_HDMI_HSI      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_HDMI_HSI(v)   ((((reg32_t) v) << 29) & BM_CSU_SA_L_HDMI_HSI)
#else
#define BF_CSU_SA_L_HDMI_HSI(v)   (((v) << 29) & BM_CSU_SA_L_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_HDMI_HSI field to a new value.
#define BW_CSU_SA_L_HDMI_HSI(v)   BF_CS1(CSU_SA, L_HDMI_HSI, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_HPCONTROL0 - HPCONTROL0 register (RW)
 *
 * The HP Control registers CSU_HPCONTROL0 and CSU_HPCONTROL1 enable CSU to control the
 * USER/SUPERVISOR mode state for the specified masters. The register toggles the output signal
 * csu_hprot1 for system masters. The two possibilities sources for the csu_hprot1 output are:   the
 * hprot1 input signal, or  the corresponding bit in the HP register.   The even bits in the
 * registers are used for locking the control bit values.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HPC_PCIE : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of PCIE.
        unsigned L_PCIE : 1; //!< Lock bit set by TZ software for HPC_PCIE.
        unsigned RESERVED0 : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of SATA.
        unsigned RESERVED1 : 1; //!< Lock bit set by TZ software for HPC_SATA.
        unsigned HPC_SDMA : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of SDMA.
        unsigned L_SDMA : 1; //!< Lock bit set by TZ software for HPC_SDMA.
        unsigned HPC_PU : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of GPU3D, GPU2D, VPU, IPU1, IPU2, OpenVG EPDC, PXP, LCDIF and VDOA. NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
        unsigned L_PU : 1; //!< Lock bit set by TZ software for HPC_PU.
        unsigned HPC_USB : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of USB.
        unsigned L_USB : 1; //!< Lock bit set by TZ software for HPC_USB.
        unsigned HPC_TEST : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of IOMUX Test Port.
        unsigned L_TEST : 1; //!< Lock bit set by TZ software for HPC_TEST.
        unsigned HPC_MLB : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of MLB.
        unsigned L_MLB : 1; //!< Lock bit set by TZ software for HPC_MLB.
        unsigned HPC_CAAM : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of CAAM.
        unsigned L_CAAM : 1; //!< Lock bit set by TZ software for HPC_CAAM.
        unsigned HPC_RAWNAND : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of RawNAND.
        unsigned L_RAWNAND : 1; //!< Lock bit set by TZ software for HPC_RAWNAND.
        unsigned HPC_APBHDMA : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of apbhdma.
        unsigned L_ABPHDMA : 1; //!< Lock bit set by TZ software for HPC_APBHDMA.
        unsigned HPC_ENET : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of ENET.
        unsigned L_ENET : 1; //!< Lock bit set by TZ software for HPC_ENET.
        unsigned HPC_DAP : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of DAP.
        unsigned L_DAP : 1; //!< Lock bit set by TZ software for HPC_DAP.
        unsigned HPC_USDHC1 : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of USDHC1.
        unsigned L_USDHC1 : 1; //!< Lock bit set by TZ software for HPC_USDHC1.
        unsigned HPC_USDHC2 : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of USDHC2.
        unsigned L_USDHC2 : 1; //!< Lock bit set by TZ software for HPC_USDHC2.
        unsigned HPC_USDHC3 : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of USDHC3.
        unsigned L_USDHC3 : 1; //!< Lock bit set by TZ software for HPC_USDHC3.
        unsigned HPC_USDHC4 : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of USDHC4.
        unsigned L_USDHC4 : 1; //!< Lock bit set by TZ software for HPC_USDHC4.
    } B;
} hw_csu_hpcontrol0_t;
#endif

/*
 * constants & macros for entire CSU_HPCONTROL0 register
 */
#define HW_CSU_HPCONTROL0_ADDR      (REGS_CSU_BASE + 0x358)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_HPCONTROL0           (*(volatile hw_csu_hpcontrol0_t *) HW_CSU_HPCONTROL0_ADDR)
#define HW_CSU_HPCONTROL0_RD()      (HW_CSU_HPCONTROL0.U)
#define HW_CSU_HPCONTROL0_WR(v)     (HW_CSU_HPCONTROL0.U = (v))
#define HW_CSU_HPCONTROL0_SET(v)    (HW_CSU_HPCONTROL0_WR(HW_CSU_HPCONTROL0_RD() |  (v)))
#define HW_CSU_HPCONTROL0_CLR(v)    (HW_CSU_HPCONTROL0_WR(HW_CSU_HPCONTROL0_RD() & ~(v)))
#define HW_CSU_HPCONTROL0_TOG(v)    (HW_CSU_HPCONTROL0_WR(HW_CSU_HPCONTROL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_HPCONTROL0 bitfields
 */

/* --- Register HW_CSU_HPCONTROL0, field HPC_PCIE[0:0] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * PCIE.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_PCIE      (0)
#define BM_CSU_HPCONTROL0_HPC_PCIE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_PCIE(v)   ((((reg32_t) v) << 0) & BM_CSU_HPCONTROL0_HPC_PCIE)
#else
#define BF_CSU_HPCONTROL0_HPC_PCIE(v)   (((v) << 0) & BM_CSU_HPCONTROL0_HPC_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_PCIE field to a new value.
#define BW_CSU_HPCONTROL0_HPC_PCIE(v)   BF_CS1(CSU_HPCONTROL0, HPC_PCIE, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_PCIE[1:1] (RW)
 *
 * Lock bit set by TZ software for HPC_PCIE.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_PCIE      (1)
#define BM_CSU_HPCONTROL0_L_PCIE      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_PCIE(v)   ((((reg32_t) v) << 1) & BM_CSU_HPCONTROL0_L_PCIE)
#else
#define BF_CSU_HPCONTROL0_L_PCIE(v)   (((v) << 1) & BM_CSU_HPCONTROL0_L_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_PCIE field to a new value.
#define BW_CSU_HPCONTROL0_L_PCIE(v)   BF_CS1(CSU_HPCONTROL0, L_PCIE, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_SDMA[4:4] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * SDMA.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_SDMA      (4)
#define BM_CSU_HPCONTROL0_HPC_SDMA      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_SDMA(v)   ((((reg32_t) v) << 4) & BM_CSU_HPCONTROL0_HPC_SDMA)
#else
#define BF_CSU_HPCONTROL0_HPC_SDMA(v)   (((v) << 4) & BM_CSU_HPCONTROL0_HPC_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_SDMA field to a new value.
#define BW_CSU_HPCONTROL0_HPC_SDMA(v)   BF_CS1(CSU_HPCONTROL0, HPC_SDMA, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_SDMA[5:5] (RW)
 *
 * Lock bit set by TZ software for HPC_SDMA.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_SDMA      (5)
#define BM_CSU_HPCONTROL0_L_SDMA      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_SDMA(v)   ((((reg32_t) v) << 5) & BM_CSU_HPCONTROL0_L_SDMA)
#else
#define BF_CSU_HPCONTROL0_L_SDMA(v)   (((v) << 5) & BM_CSU_HPCONTROL0_L_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_SDMA field to a new value.
#define BW_CSU_HPCONTROL0_L_SDMA(v)   BF_CS1(CSU_HPCONTROL0, L_SDMA, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_PU[6:6] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * GPU3D, GPU2D, VPU, IPU1, IPU2, OpenVG EPDC, PXP, LCDIF and VDOA. NOTE: IPU2 and OpenVG on i.MX6DQ
 * only; EPDC, PXP and LCDIF on i.MX6SDL only
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_PU      (6)
#define BM_CSU_HPCONTROL0_HPC_PU      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_PU(v)   ((((reg32_t) v) << 6) & BM_CSU_HPCONTROL0_HPC_PU)
#else
#define BF_CSU_HPCONTROL0_HPC_PU(v)   (((v) << 6) & BM_CSU_HPCONTROL0_HPC_PU)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_PU field to a new value.
#define BW_CSU_HPCONTROL0_HPC_PU(v)   BF_CS1(CSU_HPCONTROL0, HPC_PU, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_PU[7:7] (RW)
 *
 * Lock bit set by TZ software for HPC_PU.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_PU      (7)
#define BM_CSU_HPCONTROL0_L_PU      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_PU(v)   ((((reg32_t) v) << 7) & BM_CSU_HPCONTROL0_L_PU)
#else
#define BF_CSU_HPCONTROL0_L_PU(v)   (((v) << 7) & BM_CSU_HPCONTROL0_L_PU)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_PU field to a new value.
#define BW_CSU_HPCONTROL0_L_PU(v)   BF_CS1(CSU_HPCONTROL0, L_PU, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_USB[8:8] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USB.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_USB      (8)
#define BM_CSU_HPCONTROL0_HPC_USB      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USB(v)   ((((reg32_t) v) << 8) & BM_CSU_HPCONTROL0_HPC_USB)
#else
#define BF_CSU_HPCONTROL0_HPC_USB(v)   (((v) << 8) & BM_CSU_HPCONTROL0_HPC_USB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_USB field to a new value.
#define BW_CSU_HPCONTROL0_HPC_USB(v)   BF_CS1(CSU_HPCONTROL0, HPC_USB, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_USB[9:9] (RW)
 *
 * Lock bit set by TZ software for HPC_USB.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_USB      (9)
#define BM_CSU_HPCONTROL0_L_USB      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USB(v)   ((((reg32_t) v) << 9) & BM_CSU_HPCONTROL0_L_USB)
#else
#define BF_CSU_HPCONTROL0_L_USB(v)   (((v) << 9) & BM_CSU_HPCONTROL0_L_USB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USB field to a new value.
#define BW_CSU_HPCONTROL0_L_USB(v)   BF_CS1(CSU_HPCONTROL0, L_USB, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_TEST[10:10] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * IOMUX Test Port.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_TEST      (10)
#define BM_CSU_HPCONTROL0_HPC_TEST      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_TEST(v)   ((((reg32_t) v) << 10) & BM_CSU_HPCONTROL0_HPC_TEST)
#else
#define BF_CSU_HPCONTROL0_HPC_TEST(v)   (((v) << 10) & BM_CSU_HPCONTROL0_HPC_TEST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_TEST field to a new value.
#define BW_CSU_HPCONTROL0_HPC_TEST(v)   BF_CS1(CSU_HPCONTROL0, HPC_TEST, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_TEST[11:11] (RW)
 *
 * Lock bit set by TZ software for HPC_TEST.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_TEST      (11)
#define BM_CSU_HPCONTROL0_L_TEST      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_TEST(v)   ((((reg32_t) v) << 11) & BM_CSU_HPCONTROL0_L_TEST)
#else
#define BF_CSU_HPCONTROL0_L_TEST(v)   (((v) << 11) & BM_CSU_HPCONTROL0_L_TEST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_TEST field to a new value.
#define BW_CSU_HPCONTROL0_L_TEST(v)   BF_CS1(CSU_HPCONTROL0, L_TEST, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_MLB[12:12] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * MLB.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_MLB      (12)
#define BM_CSU_HPCONTROL0_HPC_MLB      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_MLB(v)   ((((reg32_t) v) << 12) & BM_CSU_HPCONTROL0_HPC_MLB)
#else
#define BF_CSU_HPCONTROL0_HPC_MLB(v)   (((v) << 12) & BM_CSU_HPCONTROL0_HPC_MLB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_MLB field to a new value.
#define BW_CSU_HPCONTROL0_HPC_MLB(v)   BF_CS1(CSU_HPCONTROL0, HPC_MLB, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_MLB[13:13] (RW)
 *
 * Lock bit set by TZ software for HPC_MLB.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_MLB      (13)
#define BM_CSU_HPCONTROL0_L_MLB      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_MLB(v)   ((((reg32_t) v) << 13) & BM_CSU_HPCONTROL0_L_MLB)
#else
#define BF_CSU_HPCONTROL0_L_MLB(v)   (((v) << 13) & BM_CSU_HPCONTROL0_L_MLB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_MLB field to a new value.
#define BW_CSU_HPCONTROL0_L_MLB(v)   BF_CS1(CSU_HPCONTROL0, L_MLB, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_CAAM[14:14] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * CAAM.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_CAAM      (14)
#define BM_CSU_HPCONTROL0_HPC_CAAM      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_CAAM(v)   ((((reg32_t) v) << 14) & BM_CSU_HPCONTROL0_HPC_CAAM)
#else
#define BF_CSU_HPCONTROL0_HPC_CAAM(v)   (((v) << 14) & BM_CSU_HPCONTROL0_HPC_CAAM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_CAAM field to a new value.
#define BW_CSU_HPCONTROL0_HPC_CAAM(v)   BF_CS1(CSU_HPCONTROL0, HPC_CAAM, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_CAAM[15:15] (RW)
 *
 * Lock bit set by TZ software for HPC_CAAM.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_CAAM      (15)
#define BM_CSU_HPCONTROL0_L_CAAM      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_CAAM(v)   ((((reg32_t) v) << 15) & BM_CSU_HPCONTROL0_L_CAAM)
#else
#define BF_CSU_HPCONTROL0_L_CAAM(v)   (((v) << 15) & BM_CSU_HPCONTROL0_L_CAAM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_CAAM field to a new value.
#define BW_CSU_HPCONTROL0_L_CAAM(v)   BF_CS1(CSU_HPCONTROL0, L_CAAM, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_RAWNAND[16:16] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * RawNAND.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_RAWNAND      (16)
#define BM_CSU_HPCONTROL0_HPC_RAWNAND      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_RAWNAND(v)   ((((reg32_t) v) << 16) & BM_CSU_HPCONTROL0_HPC_RAWNAND)
#else
#define BF_CSU_HPCONTROL0_HPC_RAWNAND(v)   (((v) << 16) & BM_CSU_HPCONTROL0_HPC_RAWNAND)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_RAWNAND field to a new value.
#define BW_CSU_HPCONTROL0_HPC_RAWNAND(v)   BF_CS1(CSU_HPCONTROL0, HPC_RAWNAND, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_RAWNAND[17:17] (RW)
 *
 * Lock bit set by TZ software for HPC_RAWNAND.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_RAWNAND      (17)
#define BM_CSU_HPCONTROL0_L_RAWNAND      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_RAWNAND(v)   ((((reg32_t) v) << 17) & BM_CSU_HPCONTROL0_L_RAWNAND)
#else
#define BF_CSU_HPCONTROL0_L_RAWNAND(v)   (((v) << 17) & BM_CSU_HPCONTROL0_L_RAWNAND)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_RAWNAND field to a new value.
#define BW_CSU_HPCONTROL0_L_RAWNAND(v)   BF_CS1(CSU_HPCONTROL0, L_RAWNAND, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_APBHDMA[18:18] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * apbhdma.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_APBHDMA      (18)
#define BM_CSU_HPCONTROL0_HPC_APBHDMA      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_APBHDMA(v)   ((((reg32_t) v) << 18) & BM_CSU_HPCONTROL0_HPC_APBHDMA)
#else
#define BF_CSU_HPCONTROL0_HPC_APBHDMA(v)   (((v) << 18) & BM_CSU_HPCONTROL0_HPC_APBHDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_APBHDMA field to a new value.
#define BW_CSU_HPCONTROL0_HPC_APBHDMA(v)   BF_CS1(CSU_HPCONTROL0, HPC_APBHDMA, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_ABPHDMA[19:19] (RW)
 *
 * Lock bit set by TZ software for HPC_APBHDMA.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_ABPHDMA      (19)
#define BM_CSU_HPCONTROL0_L_ABPHDMA      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_ABPHDMA(v)   ((((reg32_t) v) << 19) & BM_CSU_HPCONTROL0_L_ABPHDMA)
#else
#define BF_CSU_HPCONTROL0_L_ABPHDMA(v)   (((v) << 19) & BM_CSU_HPCONTROL0_L_ABPHDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_ABPHDMA field to a new value.
#define BW_CSU_HPCONTROL0_L_ABPHDMA(v)   BF_CS1(CSU_HPCONTROL0, L_ABPHDMA, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_ENET[20:20] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * ENET.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_ENET      (20)
#define BM_CSU_HPCONTROL0_HPC_ENET      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_ENET(v)   ((((reg32_t) v) << 20) & BM_CSU_HPCONTROL0_HPC_ENET)
#else
#define BF_CSU_HPCONTROL0_HPC_ENET(v)   (((v) << 20) & BM_CSU_HPCONTROL0_HPC_ENET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_ENET field to a new value.
#define BW_CSU_HPCONTROL0_HPC_ENET(v)   BF_CS1(CSU_HPCONTROL0, HPC_ENET, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_ENET[21:21] (RW)
 *
 * Lock bit set by TZ software for HPC_ENET.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_ENET      (21)
#define BM_CSU_HPCONTROL0_L_ENET      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_ENET(v)   ((((reg32_t) v) << 21) & BM_CSU_HPCONTROL0_L_ENET)
#else
#define BF_CSU_HPCONTROL0_L_ENET(v)   (((v) << 21) & BM_CSU_HPCONTROL0_L_ENET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_ENET field to a new value.
#define BW_CSU_HPCONTROL0_L_ENET(v)   BF_CS1(CSU_HPCONTROL0, L_ENET, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_DAP[22:22] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * DAP.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_DAP      (22)
#define BM_CSU_HPCONTROL0_HPC_DAP      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_DAP(v)   ((((reg32_t) v) << 22) & BM_CSU_HPCONTROL0_HPC_DAP)
#else
#define BF_CSU_HPCONTROL0_HPC_DAP(v)   (((v) << 22) & BM_CSU_HPCONTROL0_HPC_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_DAP field to a new value.
#define BW_CSU_HPCONTROL0_HPC_DAP(v)   BF_CS1(CSU_HPCONTROL0, HPC_DAP, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_DAP[23:23] (RW)
 *
 * Lock bit set by TZ software for HPC_DAP.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_DAP      (23)
#define BM_CSU_HPCONTROL0_L_DAP      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_DAP(v)   ((((reg32_t) v) << 23) & BM_CSU_HPCONTROL0_L_DAP)
#else
#define BF_CSU_HPCONTROL0_L_DAP(v)   (((v) << 23) & BM_CSU_HPCONTROL0_L_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_DAP field to a new value.
#define BW_CSU_HPCONTROL0_L_DAP(v)   BF_CS1(CSU_HPCONTROL0, L_DAP, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_USDHC1[24:24] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USDHC1.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_USDHC1      (24)
#define BM_CSU_HPCONTROL0_HPC_USDHC1      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USDHC1(v)   ((((reg32_t) v) << 24) & BM_CSU_HPCONTROL0_HPC_USDHC1)
#else
#define BF_CSU_HPCONTROL0_HPC_USDHC1(v)   (((v) << 24) & BM_CSU_HPCONTROL0_HPC_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_USDHC1 field to a new value.
#define BW_CSU_HPCONTROL0_HPC_USDHC1(v)   BF_CS1(CSU_HPCONTROL0, HPC_USDHC1, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_USDHC1[25:25] (RW)
 *
 * Lock bit set by TZ software for HPC_USDHC1.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_USDHC1      (25)
#define BM_CSU_HPCONTROL0_L_USDHC1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USDHC1(v)   ((((reg32_t) v) << 25) & BM_CSU_HPCONTROL0_L_USDHC1)
#else
#define BF_CSU_HPCONTROL0_L_USDHC1(v)   (((v) << 25) & BM_CSU_HPCONTROL0_L_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC1 field to a new value.
#define BW_CSU_HPCONTROL0_L_USDHC1(v)   BF_CS1(CSU_HPCONTROL0, L_USDHC1, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_USDHC2[26:26] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USDHC2.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_USDHC2      (26)
#define BM_CSU_HPCONTROL0_HPC_USDHC2      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USDHC2(v)   ((((reg32_t) v) << 26) & BM_CSU_HPCONTROL0_HPC_USDHC2)
#else
#define BF_CSU_HPCONTROL0_HPC_USDHC2(v)   (((v) << 26) & BM_CSU_HPCONTROL0_HPC_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_USDHC2 field to a new value.
#define BW_CSU_HPCONTROL0_HPC_USDHC2(v)   BF_CS1(CSU_HPCONTROL0, HPC_USDHC2, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_USDHC2[27:27] (RW)
 *
 * Lock bit set by TZ software for HPC_USDHC2.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_USDHC2      (27)
#define BM_CSU_HPCONTROL0_L_USDHC2      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USDHC2(v)   ((((reg32_t) v) << 27) & BM_CSU_HPCONTROL0_L_USDHC2)
#else
#define BF_CSU_HPCONTROL0_L_USDHC2(v)   (((v) << 27) & BM_CSU_HPCONTROL0_L_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC2 field to a new value.
#define BW_CSU_HPCONTROL0_L_USDHC2(v)   BF_CS1(CSU_HPCONTROL0, L_USDHC2, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_USDHC3[28:28] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USDHC3.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_USDHC3      (28)
#define BM_CSU_HPCONTROL0_HPC_USDHC3      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USDHC3(v)   ((((reg32_t) v) << 28) & BM_CSU_HPCONTROL0_HPC_USDHC3)
#else
#define BF_CSU_HPCONTROL0_HPC_USDHC3(v)   (((v) << 28) & BM_CSU_HPCONTROL0_HPC_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_USDHC3 field to a new value.
#define BW_CSU_HPCONTROL0_HPC_USDHC3(v)   BF_CS1(CSU_HPCONTROL0, HPC_USDHC3, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_USDHC3[29:29] (RW)
 *
 * Lock bit set by TZ software for HPC_USDHC3.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_USDHC3      (29)
#define BM_CSU_HPCONTROL0_L_USDHC3      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USDHC3(v)   ((((reg32_t) v) << 29) & BM_CSU_HPCONTROL0_L_USDHC3)
#else
#define BF_CSU_HPCONTROL0_L_USDHC3(v)   (((v) << 29) & BM_CSU_HPCONTROL0_L_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC3 field to a new value.
#define BW_CSU_HPCONTROL0_L_USDHC3(v)   BF_CS1(CSU_HPCONTROL0, L_USDHC3, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field HPC_USDHC4[30:30] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USDHC4.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL0_HPC_USDHC4      (30)
#define BM_CSU_HPCONTROL0_HPC_USDHC4      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USDHC4(v)   ((((reg32_t) v) << 30) & BM_CSU_HPCONTROL0_HPC_USDHC4)
#else
#define BF_CSU_HPCONTROL0_HPC_USDHC4(v)   (((v) << 30) & BM_CSU_HPCONTROL0_HPC_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_USDHC4 field to a new value.
#define BW_CSU_HPCONTROL0_HPC_USDHC4(v)   BF_CS1(CSU_HPCONTROL0, HPC_USDHC4, v)
#endif


/* --- Register HW_CSU_HPCONTROL0, field L_USDHC4[31:31] (RW)
 *
 * Lock bit set by TZ software for HPC_USDHC4.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL0_L_USDHC4      (31)
#define BM_CSU_HPCONTROL0_L_USDHC4      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USDHC4(v)   ((((reg32_t) v) << 31) & BM_CSU_HPCONTROL0_L_USDHC4)
#else
#define BF_CSU_HPCONTROL0_L_USDHC4(v)   (((v) << 31) & BM_CSU_HPCONTROL0_L_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_USDHC4 field to a new value.
#define BW_CSU_HPCONTROL0_L_USDHC4(v)   BF_CS1(CSU_HPCONTROL0, L_USDHC4, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSU_HPCONTROL1 - HPCONTROL1 register (RW)
 *
 * The SCU_HPCONTROL1 register is expansion of SCU_HPCONTROL0 register. See SCU_HPCONTROL0 register
 * definition.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HPC_HDMI_HSI : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of HDMI Tx and HSI.
        unsigned L_HDMI_HSI : 1; //!< Lock bit set by TZ software for HPC_HDMI_HSI.
        unsigned RESERVED0 : 30; //!< Reserved.
    } B;
} hw_csu_hpcontrol1_t;
#endif

/*
 * constants & macros for entire CSU_HPCONTROL1 register
 */
#define HW_CSU_HPCONTROL1_ADDR      (REGS_CSU_BASE + 0x35c)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_HPCONTROL1           (*(volatile hw_csu_hpcontrol1_t *) HW_CSU_HPCONTROL1_ADDR)
#define HW_CSU_HPCONTROL1_RD()      (HW_CSU_HPCONTROL1.U)
#define HW_CSU_HPCONTROL1_WR(v)     (HW_CSU_HPCONTROL1.U = (v))
#define HW_CSU_HPCONTROL1_SET(v)    (HW_CSU_HPCONTROL1_WR(HW_CSU_HPCONTROL1_RD() |  (v)))
#define HW_CSU_HPCONTROL1_CLR(v)    (HW_CSU_HPCONTROL1_WR(HW_CSU_HPCONTROL1_RD() & ~(v)))
#define HW_CSU_HPCONTROL1_TOG(v)    (HW_CSU_HPCONTROL1_WR(HW_CSU_HPCONTROL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSU_HPCONTROL1 bitfields
 */

/* --- Register HW_CSU_HPCONTROL1, field HPC_HDMI_HSI[0:0] (RW)
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * HDMI Tx and HSI.
 *
 * Values:
 * 0 - Input signal hprot1 value is routed to csu_hprot1 output for the corresponding master
 * 1 - HP register bit is routed to csu_hprot1 output for the corresponding master
 */

#define BP_CSU_HPCONTROL1_HPC_HDMI_HSI      (0)
#define BM_CSU_HPCONTROL1_HPC_HDMI_HSI      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL1_HPC_HDMI_HSI(v)   ((((reg32_t) v) << 0) & BM_CSU_HPCONTROL1_HPC_HDMI_HSI)
#else
#define BF_CSU_HPCONTROL1_HPC_HDMI_HSI(v)   (((v) << 0) & BM_CSU_HPCONTROL1_HPC_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HPC_HDMI_HSI field to a new value.
#define BW_CSU_HPCONTROL1_HPC_HDMI_HSI(v)   BF_CS1(CSU_HPCONTROL1, HPC_HDMI_HSI, v)
#endif


/* --- Register HW_CSU_HPCONTROL1, field L_HDMI_HSI[1:1] (RW)
 *
 * Lock bit set by TZ software for HPC_HDMI_HSI.
 *
 * Values:
 * 0 - No lock -- adjacent (next lower) bit can be written by software
 * 1 - Lock -- adjacent (next lower) bit cannot be written by software
 */

#define BP_CSU_HPCONTROL1_L_HDMI_HSI      (1)
#define BM_CSU_HPCONTROL1_L_HDMI_HSI      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL1_L_HDMI_HSI(v)   ((((reg32_t) v) << 1) & BM_CSU_HPCONTROL1_L_HDMI_HSI)
#else
#define BF_CSU_HPCONTROL1_L_HDMI_HSI(v)   (((v) << 1) & BM_CSU_HPCONTROL1_L_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the L_HDMI_HSI field to a new value.
#define BW_CSU_HPCONTROL1_L_HDMI_HSI(v)   BF_CS1(CSU_HPCONTROL1, L_HDMI_HSI, v)
#endif



/*!
 * @brief All CSU module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_csu_csl0_t CSL0; //!< Config security level register 0
    volatile hw_csu_csl1_t CSL1; //!< Config security level register 1
    volatile hw_csu_csl2_t CSL2; //!< Config security level register 2
    volatile hw_csu_csl3_t CSL3; //!< Config security level register 3
    volatile hw_csu_csl4_t CSL4; //!< Config security level register 4
    volatile hw_csu_csl5_t CSL5; //!< Config security level register 5
    volatile hw_csu_csl6_t CSL6; //!< Config security level register 6
    volatile hw_csu_csl7_t CSL7; //!< Config security level register 7
    volatile hw_csu_csl8_t CSL8; //!< Config security level register 8
    volatile hw_csu_csl9_t CSL9; //!< Config security level register 9
    volatile hw_csu_csl10_t CSL10; //!< Config security level register 10
    volatile hw_csu_csl11_t CSL11; //!< Config security level register 11
    volatile hw_csu_csl12_t CSL12; //!< Config security level register 12
    volatile hw_csu_csl13_t CSL13; //!< Config security level register 13
    volatile hw_csu_csl14_t CSL14; //!< Config security level register 14
    volatile hw_csu_csl15_t CSL15; //!< Config security level register 15
    volatile hw_csu_csl16_t CSL16; //!< Config security level register 16
    volatile hw_csu_csl17_t CSL17; //!< Config security level register 17
    volatile hw_csu_csl18_t CSL18; //!< Config security level register 18
    volatile hw_csu_csl19_t CSL19; //!< Config security level register 19
    volatile hw_csu_csl20_t CSL20; //!< Config security level register 20
    volatile hw_csu_csl21_t CSL21; //!< Config security level register 21
    volatile hw_csu_csl22_t CSL22; //!< Config security level register 22
    volatile hw_csu_csl23_t CSL23; //!< Config security level register 23
    volatile hw_csu_csl24_t CSL24; //!< Config security level register 24
    volatile hw_csu_csl25_t CSL25; //!< Config security level register 25
    volatile hw_csu_csl26_t CSL26; //!< Config security level register 26
    volatile hw_csu_csl27_t CSL27; //!< Config security level register 27
    volatile hw_csu_csl28_t CSL28; //!< Config security level register 28
    volatile hw_csu_csl29_t CSL29; //!< Config security level register 29
    volatile hw_csu_csl30_t CSL30; //!< Config security level register 30
    volatile hw_csu_csl31_t CSL31; //!< Config security level register 31
    volatile hw_csu_csl32_t CSL32; //!< Config security level register 32
    volatile hw_csu_csl33_t CSL33; //!< Config security level register 33
    volatile hw_csu_csl34_t CSL34; //!< Config security level register 34
    volatile hw_csu_csl35_t CSL35; //!< Config security level register 35
    volatile hw_csu_csl36_t CSL36; //!< Config security level register 36
    volatile hw_csu_csl37_t CSL37; //!< Config security level register 37
    volatile hw_csu_csl38_t CSL38; //!< Config security level register 38
    volatile hw_csu_csl39_t CSL39; //!< Config security level register 39
    reg32_t _reserved0[88];
    volatile hw_csu_hp0_t HP0; //!< HP0 register
    volatile hw_csu_hp1_t HP1; //!< HP1 register
    reg32_t _reserved1[4];
    volatile hw_csu_sa_t SA; //!< Secure access register
    reg32_t _reserved2[79];
    volatile hw_csu_hpcontrol0_t HPCONTROL0; //!< HPCONTROL0 register
    volatile hw_csu_hpcontrol1_t HPCONTROL1; //!< HPCONTROL1 register
} hw_csu_t;
#endif

//! @brief Macro to access all CSU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CSU(0)</code>.
#define HW_CSU     (*(volatile hw_csu_t *) REGS_CSU_BASE)


#endif // _CSU_H
