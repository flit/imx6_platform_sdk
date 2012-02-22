/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CSU_H
#define _CSU_H

#include "regs.h"

#ifndef REGS_CSU_BASE
#define REGS_CSU_BASE (REGS_BASE + 0x021c0000)
#endif


/*!
 * @brief HW_CSU_CSL - Config security level register
 *
 * There are 40 Config Security Level (CSU_CSL0-CSU_CSL39) registers. Each
 * CSU_CSL is comprised of two fields, each field used to determine the read and write access
 * permissions for                             a slave peripheral. These 8-bit fields for the first
 * and second slaves are in the locations b23-b16 and bits b7-b0, respectively.  Permission Access
 * Table shows security levels and csu_sec_level signal levels corresponding to
 * different values of the 8-bit CSU_CSL field for a given slave.  Memory space has been reserved
 * for 128 slaves                             since each of the sixty-four 32-bit register can
 * accommodate CSL fields of two                             slaves. However, actual number of
 * registers inferred in a design                             would depend on the following
 * Parameter --- Name - No_Of_Slaves  Min. Value - 48  Max. Value - 128  Possible Values -
 * 48,64,80,96,112,128   Most slaves have unique CSL registers. Some slaves are grouped together in
 * USB, Timers, PowerUp and Audio groups.  The following table shows allocation of CSL register per
 * slave or group of slave modules.   CSL Slave Modules Mapping         Slave Module
 * Corresponding CSL register and bit field   Comments       PWM1  PWM2  PWM3  PWM4    CSL0 [7:0]
 * Audio group shared control      CAN1    CSL0 [23:16]       CAN2    CSL1 [7:0]       GPT  EPIT1
 * EPIT2    CSL1 [23:16]    Timers group      GPIO1  GPIO2    CSL2 [7:0]    GPIO1 and GPIO2 group
 * GPIO3  GPIO4    CSL2 [23:16]    GPIO3 and GPIO4 group      GPIO5  GPIO6    CSL3 [7:0]    GPIO5
 * and GPIO6 group      GPIO7    CSL3 [23:16]       KPP    CSL4 [7:0]       WDOG1    CSL4 [23:16]
 * WDOG2    CSL5 [7:0]       CCM  SNVS_HP  SRC  GPC    CSL5 [23:16]    Power group
 * IP2APB_ANATOP    CSL6 [7:0]       IOMUXC    CSL6 [23:16]       DCIC1  DCIC2    CSL7 [7:0]
 * SDMA (port IPS_HOST)  EPDC for i.MX6SDL only  LCDIF for i.MX6SDL only  PXP for i.MX6SDL only
 * CSL7 [23:16]       USBOH3 (port PL301)  USBOH3 (port USB)    CSL8 [7:0]       ENET    CSL8
 * [23:16]       MLB150    CSL9 [7:0]       USDHC1    CSL9 [23:16]       USDHC2    CSL10 [7:0]
 * USDHC3    CSL10 [23:16]       USDHC4    CSL11 [7:0]       I2C1    CSL11 [23:16]       I2C2
 * CSL12 [7:0]       I2C3    CSL12 [23:16]       ROMCP    CSL13[7:0]      VPU MMDC_CORE (port
 * IPS_P0)  MMDC_CORE (port IPS_P1)    CSL13 [23:16]    MMDC Group      WEIM    CSL14 [7:0]
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
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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
} hw_csu_csl_t;
#endif

/*
 * constants & macros for entire CSU_CSL register
 */
#define HW_CSU_CSL_ADDR      (REGS_CSU_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_CSU_CSL           (*(volatile hw_csu_csl_t *) HW_CSU_CSL_ADDR)
#define HW_CSU_CSL_RD()      (HW_CSU_CSL.U)
#define HW_CSU_CSL_WR(v)     (HW_CSU_CSL.U = (v))
#define HW_CSU_CSL_SET(v)    (HW_CSU_CSL_WR(HW_CSU_CSL_RD() |  (v)))
#define HW_CSU_CSL_CLR(v)    (HW_CSU_CSL_WR(HW_CSU_CSL_RD() & ~(v)))
#define HW_CSU_CSL_TOG(v)    (HW_CSU_CSL_WR(HW_CSU_CSL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CSU_CSL bitfields
 */

/* --- Register HW_CSU_CSL, field SUR_S2
 *
 * Secure user read access control for the second slave
 */

#define BP_CSU_CSL_SUR_S2      0
#define BM_CSU_CSL_SUR_S2      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_SUR_S2(v)   ((((reg32_t) v) << 0) & BM_CSU_CSL_SUR_S2)
#else
#define BF_CSU_CSL_SUR_S2(v)   (((v) << 0) & BM_CSU_CSL_SUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_SUR_S2(v)   BF_CS1(CSU_CSL, SUR_S2, v)
#endif

/* --- Register HW_CSU_CSL, field SSR_S2
 *
 * Secure supervisor read access control for the second slave
 */

#define BP_CSU_CSL_SSR_S2      1
#define BM_CSU_CSL_SSR_S2      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_SSR_S2(v)   ((((reg32_t) v) << 1) & BM_CSU_CSL_SSR_S2)
#else
#define BF_CSU_CSL_SSR_S2(v)   (((v) << 1) & BM_CSU_CSL_SSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_SSR_S2(v)   BF_CS1(CSU_CSL, SSR_S2, v)
#endif

/* --- Register HW_CSU_CSL, field NUR_S2
 *
 * Non-secure user read access control for the second slave
 */

#define BP_CSU_CSL_NUR_S2      2
#define BM_CSU_CSL_NUR_S2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_NUR_S2(v)   ((((reg32_t) v) << 2) & BM_CSU_CSL_NUR_S2)
#else
#define BF_CSU_CSL_NUR_S2(v)   (((v) << 2) & BM_CSU_CSL_NUR_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_NUR_S2(v)   BF_CS1(CSU_CSL, NUR_S2, v)
#endif

/* --- Register HW_CSU_CSL, field NSR_S2
 *
 * Non-secure supervisor read access control for the second slave
 */

#define BP_CSU_CSL_NSR_S2      3
#define BM_CSU_CSL_NSR_S2      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_NSR_S2(v)   ((((reg32_t) v) << 3) & BM_CSU_CSL_NSR_S2)
#else
#define BF_CSU_CSL_NSR_S2(v)   (((v) << 3) & BM_CSU_CSL_NSR_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_NSR_S2(v)   BF_CS1(CSU_CSL, NSR_S2, v)
#endif

/* --- Register HW_CSU_CSL, field SUW_S2
 *
 * Secure user write access control for the second slave
 */

#define BP_CSU_CSL_SUW_S2      4
#define BM_CSU_CSL_SUW_S2      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_SUW_S2(v)   ((((reg32_t) v) << 4) & BM_CSU_CSL_SUW_S2)
#else
#define BF_CSU_CSL_SUW_S2(v)   (((v) << 4) & BM_CSU_CSL_SUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_SUW_S2(v)   BF_CS1(CSU_CSL, SUW_S2, v)
#endif

/* --- Register HW_CSU_CSL, field SSW_S2
 *
 * Secure supervisor write access control for the second slave
 */

#define BP_CSU_CSL_SSW_S2      5
#define BM_CSU_CSL_SSW_S2      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_SSW_S2(v)   ((((reg32_t) v) << 5) & BM_CSU_CSL_SSW_S2)
#else
#define BF_CSU_CSL_SSW_S2(v)   (((v) << 5) & BM_CSU_CSL_SSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_SSW_S2(v)   BF_CS1(CSU_CSL, SSW_S2, v)
#endif

/* --- Register HW_CSU_CSL, field NUW_S2
 *
 * Non-secure user write access control for the second slave
 */

#define BP_CSU_CSL_NUW_S2      6
#define BM_CSU_CSL_NUW_S2      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_NUW_S2(v)   ((((reg32_t) v) << 6) & BM_CSU_CSL_NUW_S2)
#else
#define BF_CSU_CSL_NUW_S2(v)   (((v) << 6) & BM_CSU_CSL_NUW_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_NUW_S2(v)   BF_CS1(CSU_CSL, NUW_S2, v)
#endif

/* --- Register HW_CSU_CSL, field NSW_S2
 *
 * Non-secure supervisor write access control for the second slave
 */

#define BP_CSU_CSL_NSW_S2      7
#define BM_CSU_CSL_NSW_S2      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_NSW_S2(v)   ((((reg32_t) v) << 7) & BM_CSU_CSL_NSW_S2)
#else
#define BF_CSU_CSL_NSW_S2(v)   (((v) << 7) & BM_CSU_CSL_NSW_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_NSW_S2(v)   BF_CS1(CSU_CSL, NSW_S2, v)
#endif

/* --- Register HW_CSU_CSL, field LOCK_S2
 *
 * Lock bit corresponding to the second slave. Written by secure software.
 */

#define BP_CSU_CSL_LOCK_S2      8
#define BM_CSU_CSL_LOCK_S2      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_LOCK_S2(v)   ((((reg32_t) v) << 8) & BM_CSU_CSL_LOCK_S2)
#else
#define BF_CSU_CSL_LOCK_S2(v)   (((v) << 8) & BM_CSU_CSL_LOCK_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_LOCK_S2(v)   BF_CS1(CSU_CSL, LOCK_S2, v)
#endif

/* --- Register HW_CSU_CSL, field SUR_S1
 *
 * Secure user read access control for the first slave
 */

#define BP_CSU_CSL_SUR_S1      16
#define BM_CSU_CSL_SUR_S1      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_SUR_S1(v)   ((((reg32_t) v) << 16) & BM_CSU_CSL_SUR_S1)
#else
#define BF_CSU_CSL_SUR_S1(v)   (((v) << 16) & BM_CSU_CSL_SUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_SUR_S1(v)   BF_CS1(CSU_CSL, SUR_S1, v)
#endif

/* --- Register HW_CSU_CSL, field SSR_S1
 *
 * Secure supervisor read access control for the first slave
 */

#define BP_CSU_CSL_SSR_S1      17
#define BM_CSU_CSL_SSR_S1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_SSR_S1(v)   ((((reg32_t) v) << 17) & BM_CSU_CSL_SSR_S1)
#else
#define BF_CSU_CSL_SSR_S1(v)   (((v) << 17) & BM_CSU_CSL_SSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_SSR_S1(v)   BF_CS1(CSU_CSL, SSR_S1, v)
#endif

/* --- Register HW_CSU_CSL, field NUR_S1
 *
 * Non-secure user read access control for the first slave
 */

#define BP_CSU_CSL_NUR_S1      18
#define BM_CSU_CSL_NUR_S1      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_NUR_S1(v)   ((((reg32_t) v) << 18) & BM_CSU_CSL_NUR_S1)
#else
#define BF_CSU_CSL_NUR_S1(v)   (((v) << 18) & BM_CSU_CSL_NUR_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_NUR_S1(v)   BF_CS1(CSU_CSL, NUR_S1, v)
#endif

/* --- Register HW_CSU_CSL, field NSR_S1
 *
 * Non-secure supervisor read access control for the first slave
 */

#define BP_CSU_CSL_NSR_S1      19
#define BM_CSU_CSL_NSR_S1      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_NSR_S1(v)   ((((reg32_t) v) << 19) & BM_CSU_CSL_NSR_S1)
#else
#define BF_CSU_CSL_NSR_S1(v)   (((v) << 19) & BM_CSU_CSL_NSR_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_NSR_S1(v)   BF_CS1(CSU_CSL, NSR_S1, v)
#endif

/* --- Register HW_CSU_CSL, field SUW_S1
 *
 * Secure user write access control for the first slave
 */

#define BP_CSU_CSL_SUW_S1      20
#define BM_CSU_CSL_SUW_S1      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_SUW_S1(v)   ((((reg32_t) v) << 20) & BM_CSU_CSL_SUW_S1)
#else
#define BF_CSU_CSL_SUW_S1(v)   (((v) << 20) & BM_CSU_CSL_SUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_SUW_S1(v)   BF_CS1(CSU_CSL, SUW_S1, v)
#endif

/* --- Register HW_CSU_CSL, field SSW_S1
 *
 * Secure supervisor write access control for the first slave
 */

#define BP_CSU_CSL_SSW_S1      21
#define BM_CSU_CSL_SSW_S1      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_SSW_S1(v)   ((((reg32_t) v) << 21) & BM_CSU_CSL_SSW_S1)
#else
#define BF_CSU_CSL_SSW_S1(v)   (((v) << 21) & BM_CSU_CSL_SSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_SSW_S1(v)   BF_CS1(CSU_CSL, SSW_S1, v)
#endif

/* --- Register HW_CSU_CSL, field NUW_S1
 *
 * Non-secure user write access control for the first slave
 */

#define BP_CSU_CSL_NUW_S1      22
#define BM_CSU_CSL_NUW_S1      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_NUW_S1(v)   ((((reg32_t) v) << 22) & BM_CSU_CSL_NUW_S1)
#else
#define BF_CSU_CSL_NUW_S1(v)   (((v) << 22) & BM_CSU_CSL_NUW_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_NUW_S1(v)   BF_CS1(CSU_CSL, NUW_S1, v)
#endif

/* --- Register HW_CSU_CSL, field NSW_S1
 *
 * Non-secure supervisor write access control for the first slave
 */

#define BP_CSU_CSL_NSW_S1      23
#define BM_CSU_CSL_NSW_S1      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_NSW_S1(v)   ((((reg32_t) v) << 23) & BM_CSU_CSL_NSW_S1)
#else
#define BF_CSU_CSL_NSW_S1(v)   (((v) << 23) & BM_CSU_CSL_NSW_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_NSW_S1(v)   BF_CS1(CSU_CSL, NSW_S1, v)
#endif

/* --- Register HW_CSU_CSL, field LOCK_S1
 *
 * Lock bit corresponding to the first slave. Written by secure software.
 */

#define BP_CSU_CSL_LOCK_S1      24
#define BM_CSU_CSL_LOCK_S1      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_CSL_LOCK_S1(v)   ((((reg32_t) v) << 24) & BM_CSU_CSL_LOCK_S1)
#else
#define BF_CSU_CSL_LOCK_S1(v)   (((v) << 24) & BM_CSU_CSL_LOCK_S1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_CSL_LOCK_S1(v)   BF_CS1(CSU_CSL, LOCK_S1, v)
#endif

/*!
 * @brief HW_CSU_HP0 - HP0 register
 *
 * The SCU_HP0 and SCU_HP1 registers may be programmed to determine the privilege (either User
 * Mode or Supervisor Mode) for seventeen different master groups. The
 * privilege of a particular master group may be overridden by muxing it with the
 * corresponding bit in this register.  The even bit positions (CSU_HP0[30,28,...0] and CSU_HP1[0])
 * in the registers hold                             the privilege indicator bits; while the odd bit
 * positions                             (CSU_HP0[31,29,...,1] and CSU_HP1[1]) contain lock bits
 * which enable/disable writing to                             the corresponding privilege indicator
 * bits.  Memory Space has been reserved for 32 Masters.                             Since, one 32
 * bit register can accommodate HP fields corresponding to 16                             masters,
 * hence for 32 masters memory equivalent of 2 registers is
 * reserved.However, actual number of registers(flops) inferred in a design
 * would depend on the following Parameter --- Name - No_Of_Masters  Min. Value -1  Max. Value - 32
 * Possible Values - 1 to 32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HP_PCIE : 1; //!< Indicate the Privilege/User Mode for PCIE.
        unsigned L_PCIE : 1; //!< Lock bit set by TZ software for HP_PCIE.
        unsigned RESERVED0 : 1; //!< Indicate the Privilege/User Mode for SATA.
        unsigned RESERVED1 : 1; //!< Lock bit set by TZ software for HP_SATA.
        unsigned HP_SDMA : 1; //!< Indicate the Privilege/User Mode for SDMA.
        unsigned L_SDMA : 1; //!< Lock bit set by TZ software for HP_SDMA.
        unsigned HP_PU : 1; //!< Indicate the Privilege/User Mode for GPU3D, GPU2D, VPU, IPU1, IPU2, OpenVG EPDC, PXP, LCDIF and VDOA.  NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
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

/* --- Register HW_CSU_HP0, field HP_PCIE
 *
 * Indicate the Privilege/User Mode for PCIE.
 */

#define BP_CSU_HP0_HP_PCIE      0
#define BM_CSU_HP0_HP_PCIE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_PCIE(v)   ((((reg32_t) v) << 0) & BM_CSU_HP0_HP_PCIE)
#else
#define BF_CSU_HP0_HP_PCIE(v)   (((v) << 0) & BM_CSU_HP0_HP_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_PCIE(v)   BF_CS1(CSU_HP0, HP_PCIE, v)
#endif

/* --- Register HW_CSU_HP0, field L_PCIE
 *
 * Lock bit set by TZ software for HP_PCIE.
 */

#define BP_CSU_HP0_L_PCIE      1
#define BM_CSU_HP0_L_PCIE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_PCIE(v)   ((((reg32_t) v) << 1) & BM_CSU_HP0_L_PCIE)
#else
#define BF_CSU_HP0_L_PCIE(v)   (((v) << 1) & BM_CSU_HP0_L_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_PCIE(v)   BF_CS1(CSU_HP0, L_PCIE, v)
#endif

/* --- Register HW_CSU_HP0, field HP_SDMA
 *
 * Indicate the Privilege/User Mode for SDMA.
 */

#define BP_CSU_HP0_HP_SDMA      4
#define BM_CSU_HP0_HP_SDMA      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_SDMA(v)   ((((reg32_t) v) << 4) & BM_CSU_HP0_HP_SDMA)
#else
#define BF_CSU_HP0_HP_SDMA(v)   (((v) << 4) & BM_CSU_HP0_HP_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_SDMA(v)   BF_CS1(CSU_HP0, HP_SDMA, v)
#endif

/* --- Register HW_CSU_HP0, field L_SDMA
 *
 * Lock bit set by TZ software for HP_SDMA.
 */

#define BP_CSU_HP0_L_SDMA      5
#define BM_CSU_HP0_L_SDMA      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_SDMA(v)   ((((reg32_t) v) << 5) & BM_CSU_HP0_L_SDMA)
#else
#define BF_CSU_HP0_L_SDMA(v)   (((v) << 5) & BM_CSU_HP0_L_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_SDMA(v)   BF_CS1(CSU_HP0, L_SDMA, v)
#endif

/* --- Register HW_CSU_HP0, field HP_PU
 *
 * Indicate the Privilege/User Mode for GPU3D, GPU2D, VPU, IPU1, IPU2, OpenVG EPDC, PXP, LCDIF and
 * VDOA.  NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
 */

#define BP_CSU_HP0_HP_PU      6
#define BM_CSU_HP0_HP_PU      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_PU(v)   ((((reg32_t) v) << 6) & BM_CSU_HP0_HP_PU)
#else
#define BF_CSU_HP0_HP_PU(v)   (((v) << 6) & BM_CSU_HP0_HP_PU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_PU(v)   BF_CS1(CSU_HP0, HP_PU, v)
#endif

/* --- Register HW_CSU_HP0, field L_PU
 *
 * Lock bit set by TZ software for HP_PU.
 */

#define BP_CSU_HP0_L_PU      7
#define BM_CSU_HP0_L_PU      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_PU(v)   ((((reg32_t) v) << 7) & BM_CSU_HP0_L_PU)
#else
#define BF_CSU_HP0_L_PU(v)   (((v) << 7) & BM_CSU_HP0_L_PU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_PU(v)   BF_CS1(CSU_HP0, L_PU, v)
#endif

/* --- Register HW_CSU_HP0, field HP_USB
 *
 * Indicate the Privilege/User Mode for USB.
 */

#define BP_CSU_HP0_HP_USB      8
#define BM_CSU_HP0_HP_USB      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USB(v)   ((((reg32_t) v) << 8) & BM_CSU_HP0_HP_USB)
#else
#define BF_CSU_HP0_HP_USB(v)   (((v) << 8) & BM_CSU_HP0_HP_USB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_USB(v)   BF_CS1(CSU_HP0, HP_USB, v)
#endif

/* --- Register HW_CSU_HP0, field L_USB
 *
 * Lock bit set by TZ software for HP_USB.
 */

#define BP_CSU_HP0_L_USB      9
#define BM_CSU_HP0_L_USB      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USB(v)   ((((reg32_t) v) << 9) & BM_CSU_HP0_L_USB)
#else
#define BF_CSU_HP0_L_USB(v)   (((v) << 9) & BM_CSU_HP0_L_USB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_USB(v)   BF_CS1(CSU_HP0, L_USB, v)
#endif

/* --- Register HW_CSU_HP0, field HP_TEST
 *
 * Indicate the Privilege/User Mode for IOMUX Test Port.
 */

#define BP_CSU_HP0_HP_TEST      10
#define BM_CSU_HP0_HP_TEST      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_TEST(v)   ((((reg32_t) v) << 10) & BM_CSU_HP0_HP_TEST)
#else
#define BF_CSU_HP0_HP_TEST(v)   (((v) << 10) & BM_CSU_HP0_HP_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_TEST(v)   BF_CS1(CSU_HP0, HP_TEST, v)
#endif

/* --- Register HW_CSU_HP0, field L_TEST
 *
 * Lock bit set by TZ software for HP_TEST.
 */

#define BP_CSU_HP0_L_TEST      11
#define BM_CSU_HP0_L_TEST      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_TEST(v)   ((((reg32_t) v) << 11) & BM_CSU_HP0_L_TEST)
#else
#define BF_CSU_HP0_L_TEST(v)   (((v) << 11) & BM_CSU_HP0_L_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_TEST(v)   BF_CS1(CSU_HP0, L_TEST, v)
#endif

/* --- Register HW_CSU_HP0, field HP_MLB
 *
 * Indicate the mode Privilege/User Mode for MLB.
 */

#define BP_CSU_HP0_HP_MLB      12
#define BM_CSU_HP0_HP_MLB      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_MLB(v)   ((((reg32_t) v) << 12) & BM_CSU_HP0_HP_MLB)
#else
#define BF_CSU_HP0_HP_MLB(v)   (((v) << 12) & BM_CSU_HP0_HP_MLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_MLB(v)   BF_CS1(CSU_HP0, HP_MLB, v)
#endif

/* --- Register HW_CSU_HP0, field L_MLB
 *
 * Lock bit set by TZ software for HP_MLB.
 */

#define BP_CSU_HP0_L_MLB      13
#define BM_CSU_HP0_L_MLB      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_MLB(v)   ((((reg32_t) v) << 13) & BM_CSU_HP0_L_MLB)
#else
#define BF_CSU_HP0_L_MLB(v)   (((v) << 13) & BM_CSU_HP0_L_MLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_MLB(v)   BF_CS1(CSU_HP0, L_MLB, v)
#endif

/* --- Register HW_CSU_HP0, field HP_CAAM
 *
 * Indicate the Privilege/User Mode for CAAM.
 */

#define BP_CSU_HP0_HP_CAAM      14
#define BM_CSU_HP0_HP_CAAM      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_CAAM(v)   ((((reg32_t) v) << 14) & BM_CSU_HP0_HP_CAAM)
#else
#define BF_CSU_HP0_HP_CAAM(v)   (((v) << 14) & BM_CSU_HP0_HP_CAAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_CAAM(v)   BF_CS1(CSU_HP0, HP_CAAM, v)
#endif

/* --- Register HW_CSU_HP0, field L_CAAM
 *
 * Lock bit set by TZ software for HP_CAAM.
 */

#define BP_CSU_HP0_L_CAAM      15
#define BM_CSU_HP0_L_CAAM      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_CAAM(v)   ((((reg32_t) v) << 15) & BM_CSU_HP0_L_CAAM)
#else
#define BF_CSU_HP0_L_CAAM(v)   (((v) << 15) & BM_CSU_HP0_L_CAAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_CAAM(v)   BF_CS1(CSU_HP0, L_CAAM, v)
#endif

/* --- Register HW_CSU_HP0, field HP_RAWNAND
 *
 * Indicate the Privilege/User Mode for RawNAND.
 */

#define BP_CSU_HP0_HP_RAWNAND      16
#define BM_CSU_HP0_HP_RAWNAND      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_RAWNAND(v)   ((((reg32_t) v) << 16) & BM_CSU_HP0_HP_RAWNAND)
#else
#define BF_CSU_HP0_HP_RAWNAND(v)   (((v) << 16) & BM_CSU_HP0_HP_RAWNAND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_RAWNAND(v)   BF_CS1(CSU_HP0, HP_RAWNAND, v)
#endif

/* --- Register HW_CSU_HP0, field L_RAWNAND
 *
 * Lock bit set by TZ software for HP_RAWNAND.
 */

#define BP_CSU_HP0_L_RAWNAND      17
#define BM_CSU_HP0_L_RAWNAND      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_RAWNAND(v)   ((((reg32_t) v) << 17) & BM_CSU_HP0_L_RAWNAND)
#else
#define BF_CSU_HP0_L_RAWNAND(v)   (((v) << 17) & BM_CSU_HP0_L_RAWNAND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_RAWNAND(v)   BF_CS1(CSU_HP0, L_RAWNAND, v)
#endif

/* --- Register HW_CSU_HP0, field HP_APBHDMA
 *
 * Indicate the Privilege/User Mode for apbhdma.
 */

#define BP_CSU_HP0_HP_APBHDMA      18
#define BM_CSU_HP0_HP_APBHDMA      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_APBHDMA(v)   ((((reg32_t) v) << 18) & BM_CSU_HP0_HP_APBHDMA)
#else
#define BF_CSU_HP0_HP_APBHDMA(v)   (((v) << 18) & BM_CSU_HP0_HP_APBHDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_APBHDMA(v)   BF_CS1(CSU_HP0, HP_APBHDMA, v)
#endif

/* --- Register HW_CSU_HP0, field L_ABPHDMA
 *
 * Lock bit set by TZ software for HP_APBHDMA.
 */

#define BP_CSU_HP0_L_ABPHDMA      19
#define BM_CSU_HP0_L_ABPHDMA      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_ABPHDMA(v)   ((((reg32_t) v) << 19) & BM_CSU_HP0_L_ABPHDMA)
#else
#define BF_CSU_HP0_L_ABPHDMA(v)   (((v) << 19) & BM_CSU_HP0_L_ABPHDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_ABPHDMA(v)   BF_CS1(CSU_HP0, L_ABPHDMA, v)
#endif

/* --- Register HW_CSU_HP0, field HP_ENET
 *
 * Indicate the Privilege/User Mode for ENET.
 */

#define BP_CSU_HP0_HP_ENET      20
#define BM_CSU_HP0_HP_ENET      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_ENET(v)   ((((reg32_t) v) << 20) & BM_CSU_HP0_HP_ENET)
#else
#define BF_CSU_HP0_HP_ENET(v)   (((v) << 20) & BM_CSU_HP0_HP_ENET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_ENET(v)   BF_CS1(CSU_HP0, HP_ENET, v)
#endif

/* --- Register HW_CSU_HP0, field L_ENET
 *
 * Lock bit set by TZ software for HP_ENET.
 */

#define BP_CSU_HP0_L_ENET      21
#define BM_CSU_HP0_L_ENET      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_ENET(v)   ((((reg32_t) v) << 21) & BM_CSU_HP0_L_ENET)
#else
#define BF_CSU_HP0_L_ENET(v)   (((v) << 21) & BM_CSU_HP0_L_ENET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_ENET(v)   BF_CS1(CSU_HP0, L_ENET, v)
#endif

/* --- Register HW_CSU_HP0, field HP_DAP
 *
 * Indicate the Privilege/User Mode for DAP.
 */

#define BP_CSU_HP0_HP_DAP      22
#define BM_CSU_HP0_HP_DAP      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_DAP(v)   ((((reg32_t) v) << 22) & BM_CSU_HP0_HP_DAP)
#else
#define BF_CSU_HP0_HP_DAP(v)   (((v) << 22) & BM_CSU_HP0_HP_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_DAP(v)   BF_CS1(CSU_HP0, HP_DAP, v)
#endif

/* --- Register HW_CSU_HP0, field L_DAP
 *
 * Lock bit set by TZ software for HP_DAP.
 */

#define BP_CSU_HP0_L_DAP      23
#define BM_CSU_HP0_L_DAP      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_DAP(v)   ((((reg32_t) v) << 23) & BM_CSU_HP0_L_DAP)
#else
#define BF_CSU_HP0_L_DAP(v)   (((v) << 23) & BM_CSU_HP0_L_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_DAP(v)   BF_CS1(CSU_HP0, L_DAP, v)
#endif

/* --- Register HW_CSU_HP0, field HP_USDHC1
 *
 * Indicate the Privilege/User Mode for USDHC1.
 */

#define BP_CSU_HP0_HP_USDHC1      24
#define BM_CSU_HP0_HP_USDHC1      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USDHC1(v)   ((((reg32_t) v) << 24) & BM_CSU_HP0_HP_USDHC1)
#else
#define BF_CSU_HP0_HP_USDHC1(v)   (((v) << 24) & BM_CSU_HP0_HP_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_USDHC1(v)   BF_CS1(CSU_HP0, HP_USDHC1, v)
#endif

/* --- Register HW_CSU_HP0, field L_USDHC1
 *
 * Lock bit set by TZ software for HP_USDHC1.
 */

#define BP_CSU_HP0_L_USDHC1      25
#define BM_CSU_HP0_L_USDHC1      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USDHC1(v)   ((((reg32_t) v) << 25) & BM_CSU_HP0_L_USDHC1)
#else
#define BF_CSU_HP0_L_USDHC1(v)   (((v) << 25) & BM_CSU_HP0_L_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_USDHC1(v)   BF_CS1(CSU_HP0, L_USDHC1, v)
#endif

/* --- Register HW_CSU_HP0, field HP_USDHC2
 *
 * Indicate the Privilege/User Mode for USDHC2.
 */

#define BP_CSU_HP0_HP_USDHC2      26
#define BM_CSU_HP0_HP_USDHC2      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USDHC2(v)   ((((reg32_t) v) << 26) & BM_CSU_HP0_HP_USDHC2)
#else
#define BF_CSU_HP0_HP_USDHC2(v)   (((v) << 26) & BM_CSU_HP0_HP_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_USDHC2(v)   BF_CS1(CSU_HP0, HP_USDHC2, v)
#endif

/* --- Register HW_CSU_HP0, field L_USDHC2
 *
 * Lock bit set by TZ software for HP_USDHC2.
 */

#define BP_CSU_HP0_L_USDHC2      27
#define BM_CSU_HP0_L_USDHC2      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USDHC2(v)   ((((reg32_t) v) << 27) & BM_CSU_HP0_L_USDHC2)
#else
#define BF_CSU_HP0_L_USDHC2(v)   (((v) << 27) & BM_CSU_HP0_L_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_USDHC2(v)   BF_CS1(CSU_HP0, L_USDHC2, v)
#endif

/* --- Register HW_CSU_HP0, field HP_USDHC3
 *
 * Indicate the Privilege/User Mode for USDHC3.
 */

#define BP_CSU_HP0_HP_USDHC3      28
#define BM_CSU_HP0_HP_USDHC3      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USDHC3(v)   ((((reg32_t) v) << 28) & BM_CSU_HP0_HP_USDHC3)
#else
#define BF_CSU_HP0_HP_USDHC3(v)   (((v) << 28) & BM_CSU_HP0_HP_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_USDHC3(v)   BF_CS1(CSU_HP0, HP_USDHC3, v)
#endif

/* --- Register HW_CSU_HP0, field L_USDHC3
 *
 * Lock bit set by TZ software for HP_USDHC3.
 */

#define BP_CSU_HP0_L_USDHC3      29
#define BM_CSU_HP0_L_USDHC3      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USDHC3(v)   ((((reg32_t) v) << 29) & BM_CSU_HP0_L_USDHC3)
#else
#define BF_CSU_HP0_L_USDHC3(v)   (((v) << 29) & BM_CSU_HP0_L_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_USDHC3(v)   BF_CS1(CSU_HP0, L_USDHC3, v)
#endif

/* --- Register HW_CSU_HP0, field HP_USDHC4
 *
 * Indicate the Privilege/User Mode for USDHC4.
 */

#define BP_CSU_HP0_HP_USDHC4      30
#define BM_CSU_HP0_HP_USDHC4      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_HP_USDHC4(v)   ((((reg32_t) v) << 30) & BM_CSU_HP0_HP_USDHC4)
#else
#define BF_CSU_HP0_HP_USDHC4(v)   (((v) << 30) & BM_CSU_HP0_HP_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_HP_USDHC4(v)   BF_CS1(CSU_HP0, HP_USDHC4, v)
#endif

/* --- Register HW_CSU_HP0, field L_USDHC4
 *
 * Lock bit set by TZ software for HP_USDHC4.
 */

#define BP_CSU_HP0_L_USDHC4      31
#define BM_CSU_HP0_L_USDHC4      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP0_L_USDHC4(v)   ((((reg32_t) v) << 31) & BM_CSU_HP0_L_USDHC4)
#else
#define BF_CSU_HP0_L_USDHC4(v)   (((v) << 31) & BM_CSU_HP0_L_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP0_L_USDHC4(v)   BF_CS1(CSU_HP0, L_USDHC4, v)
#endif

/*!
 * @brief HW_CSU_HP1 - HP1 register
 *
 * The SCU_HP1 register is an expansion of the SCU_HP0 register. See SCU_HP0 register definition.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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

/* --- Register HW_CSU_HP1, field HP_HDMI_HSI
 *
 * Indicate the Privilege/User Mode for HDMI Tx and HSI.
 */

#define BP_CSU_HP1_HP_HDMI_HSI      0
#define BM_CSU_HP1_HP_HDMI_HSI      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP1_HP_HDMI_HSI(v)   ((((reg32_t) v) << 0) & BM_CSU_HP1_HP_HDMI_HSI)
#else
#define BF_CSU_HP1_HP_HDMI_HSI(v)   (((v) << 0) & BM_CSU_HP1_HP_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP1_HP_HDMI_HSI(v)   BF_CS1(CSU_HP1, HP_HDMI_HSI, v)
#endif

/* --- Register HW_CSU_HP1, field L_HDMI_HSI
 *
 * Lock bit set by TZ software for HP_HDMI_HSI.
 */

#define BP_CSU_HP1_L_HDMI_HSI      1
#define BM_CSU_HP1_L_HDMI_HSI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HP1_L_HDMI_HSI(v)   ((((reg32_t) v) << 1) & BM_CSU_HP1_L_HDMI_HSI)
#else
#define BF_CSU_HP1_L_HDMI_HSI(v)   (((v) << 1) & BM_CSU_HP1_L_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HP1_L_HDMI_HSI(v)   BF_CS1(CSU_HP1, L_HDMI_HSI, v)
#endif

/*!
 * @brief HW_CSU_SA - Secure access register
 *
 * The Secure Access register may be programmed to specify the access policy
 * (either Secure or Non-secure) for up to sixteen different masters. This
 * register is used to set the access policy for Type 1 masters which are
 * incapable of setting the policy by themselves.  The sixteen even bit positions
 * (CSU_SA[30,28,...,0]) in the register hold                             the policy indicator bits;
 * while the odd bit positions                             (CSU_SA[31,29,...,1]) contain lock bits
 * which enable/disable writing to                             the corresponding policy indicator
 * bits.  Memory Space has been reserved for 32 Type 1                             Masters. Since,
 * one 32 bit register can accommodate SA fields                             corresponding to 16
 * masters, hence for 32 masters memory equivalent of 2                             registers is
 * reserved.However, actual number of registers(flops)                             inferred in a
 * design would depend on the following Parameter --- Name                                 -
 * No_Of_TP1_Masters  Min. Value -1  Max. Value - 32  Possible Values - 1 to 32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SA_CP15 : 1; //!< Indicate the Type (Secured/Non-Secured) Access to ARM CP15 register.
        unsigned L_CP15 : 1; //!< Lock bit set by TZ software for SA_CP15.
        unsigned RESERVED0 : 1; //!< Indicate the Type (Secured/Non-Secured) Access for SATA.
        unsigned RESERVED1 : 1; //!< Lock bit set by TZ software for SA_SATA.
        unsigned SA_SDMA : 1; //!< Indicate the Type (Secured/Non-Secured) Access for SDMA.
        unsigned L_SDMA : 1; //!< Lock bit set by TZ software for SA_SDMA.
        unsigned SA_PU : 1; //!< Indicate the Type (Secured/Non-Secured) Access for GPU3D, VDOA, GPU2D, IPU1, IPU2, OPENVG EPDC, PXP, LCDIF and VPU.  NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
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

/* --- Register HW_CSU_SA, field SA_CP15
 *
 * Indicate the Type (Secured/Non-Secured) Access to ARM CP15 register.
 */

#define BP_CSU_SA_SA_CP15      0
#define BM_CSU_SA_SA_CP15      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_CP15(v)   ((((reg32_t) v) << 0) & BM_CSU_SA_SA_CP15)
#else
#define BF_CSU_SA_SA_CP15(v)   (((v) << 0) & BM_CSU_SA_SA_CP15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_CP15(v)   BF_CS1(CSU_SA, SA_CP15, v)
#endif

/* --- Register HW_CSU_SA, field L_CP15
 *
 * Lock bit set by TZ software for SA_CP15.
 */

#define BP_CSU_SA_L_CP15      1
#define BM_CSU_SA_L_CP15      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_CP15(v)   ((((reg32_t) v) << 1) & BM_CSU_SA_L_CP15)
#else
#define BF_CSU_SA_L_CP15(v)   (((v) << 1) & BM_CSU_SA_L_CP15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_CP15(v)   BF_CS1(CSU_SA, L_CP15, v)
#endif

/* --- Register HW_CSU_SA, field SA_SDMA
 *
 * Indicate the Type (Secured/Non-Secured) Access for SDMA.
 */

#define BP_CSU_SA_SA_SDMA      4
#define BM_CSU_SA_SA_SDMA      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_SDMA(v)   ((((reg32_t) v) << 4) & BM_CSU_SA_SA_SDMA)
#else
#define BF_CSU_SA_SA_SDMA(v)   (((v) << 4) & BM_CSU_SA_SA_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_SDMA(v)   BF_CS1(CSU_SA, SA_SDMA, v)
#endif

/* --- Register HW_CSU_SA, field L_SDMA
 *
 * Lock bit set by TZ software for SA_SDMA.
 */

#define BP_CSU_SA_L_SDMA      5
#define BM_CSU_SA_L_SDMA      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_SDMA(v)   ((((reg32_t) v) << 5) & BM_CSU_SA_L_SDMA)
#else
#define BF_CSU_SA_L_SDMA(v)   (((v) << 5) & BM_CSU_SA_L_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_SDMA(v)   BF_CS1(CSU_SA, L_SDMA, v)
#endif

/* --- Register HW_CSU_SA, field SA_PU
 *
 * Indicate the Type (Secured/Non-Secured) Access for GPU3D, VDOA, GPU2D, IPU1, IPU2, OPENVG EPDC,
 * PXP, LCDIF and VPU.  NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
 */

#define BP_CSU_SA_SA_PU      6
#define BM_CSU_SA_SA_PU      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_PU(v)   ((((reg32_t) v) << 6) & BM_CSU_SA_SA_PU)
#else
#define BF_CSU_SA_SA_PU(v)   (((v) << 6) & BM_CSU_SA_SA_PU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_PU(v)   BF_CS1(CSU_SA, SA_PU, v)
#endif

/* --- Register HW_CSU_SA, field L_PU
 *
 * Lock bit set by TZ software for SA_PU.
 */

#define BP_CSU_SA_L_PU      7
#define BM_CSU_SA_L_PU      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_PU(v)   ((((reg32_t) v) << 7) & BM_CSU_SA_L_PU)
#else
#define BF_CSU_SA_L_PU(v)   (((v) << 7) & BM_CSU_SA_L_PU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_PU(v)   BF_CS1(CSU_SA, L_PU, v)
#endif

/* --- Register HW_CSU_SA, field SA_USB_MLB
 *
 * Indicate the Type (Secured/Non-Secured) Access for USB and MLB.
 */

#define BP_CSU_SA_SA_USB_MLB      8
#define BM_CSU_SA_SA_USB_MLB      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USB_MLB(v)   ((((reg32_t) v) << 8) & BM_CSU_SA_SA_USB_MLB)
#else
#define BF_CSU_SA_SA_USB_MLB(v)   (((v) << 8) & BM_CSU_SA_SA_USB_MLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_USB_MLB(v)   BF_CS1(CSU_SA, SA_USB_MLB, v)
#endif

/* --- Register HW_CSU_SA, field L_USB_MLB
 *
 * Lock bit set by TZ software for SA_USB_MLB.
 */

#define BP_CSU_SA_L_USB_MLB      9
#define BM_CSU_SA_L_USB_MLB      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USB_MLB(v)   ((((reg32_t) v) << 9) & BM_CSU_SA_L_USB_MLB)
#else
#define BF_CSU_SA_L_USB_MLB(v)   (((v) << 9) & BM_CSU_SA_L_USB_MLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_USB_MLB(v)   BF_CS1(CSU_SA, L_USB_MLB, v)
#endif

/* --- Register HW_CSU_SA, field SA_PCIE_TEST
 *
 * Indicate the Type (Secured/Non-Secured) Access for PCIe and IOMUX Test Port.
 */

#define BP_CSU_SA_SA_PCIE_TEST      10
#define BM_CSU_SA_SA_PCIE_TEST      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_PCIE_TEST(v)   ((((reg32_t) v) << 10) & BM_CSU_SA_SA_PCIE_TEST)
#else
#define BF_CSU_SA_SA_PCIE_TEST(v)   (((v) << 10) & BM_CSU_SA_SA_PCIE_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_PCIE_TEST(v)   BF_CS1(CSU_SA, SA_PCIE_TEST, v)
#endif

/* --- Register HW_CSU_SA, field L_PCIE_TEST
 *
 * Lock bit set by TZ software for SA_PCIE_TEST.
 */

#define BP_CSU_SA_L_PCIE_TEST      11
#define BM_CSU_SA_L_PCIE_TEST      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_PCIE_TEST(v)   ((((reg32_t) v) << 11) & BM_CSU_SA_L_PCIE_TEST)
#else
#define BF_CSU_SA_L_PCIE_TEST(v)   (((v) << 11) & BM_CSU_SA_L_PCIE_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_PCIE_TEST(v)   BF_CS1(CSU_SA, L_PCIE_TEST, v)
#endif

/* --- Register HW_CSU_SA, field SA_RAWNAND_APBHDMA
 *
 * Indicate the Type (Secured/Non-Secured) Access for RawNAND and apbhdmat.
 */

#define BP_CSU_SA_SA_RAWNAND_APBHDMA      14
#define BM_CSU_SA_SA_RAWNAND_APBHDMA      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_RAWNAND_APBHDMA(v)   ((((reg32_t) v) << 14) & BM_CSU_SA_SA_RAWNAND_APBHDMA)
#else
#define BF_CSU_SA_SA_RAWNAND_APBHDMA(v)   (((v) << 14) & BM_CSU_SA_SA_RAWNAND_APBHDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_RAWNAND_APBHDMA(v)   BF_CS1(CSU_SA, SA_RAWNAND_APBHDMA, v)
#endif

/* --- Register HW_CSU_SA, field L_RAWNAND_APBHDMA
 *
 * Lock bit set by TZ software for SA_RAWNAND_APBHDMA.
 */

#define BP_CSU_SA_L_RAWNAND_APBHDMA      15
#define BM_CSU_SA_L_RAWNAND_APBHDMA      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_RAWNAND_APBHDMA(v)   ((((reg32_t) v) << 15) & BM_CSU_SA_L_RAWNAND_APBHDMA)
#else
#define BF_CSU_SA_L_RAWNAND_APBHDMA(v)   (((v) << 15) & BM_CSU_SA_L_RAWNAND_APBHDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_RAWNAND_APBHDMA(v)   BF_CS1(CSU_SA, L_RAWNAND_APBHDMA, v)
#endif

/* --- Register HW_CSU_SA, field SA_ENET
 *
 * Indicate the Type (Secured/Non-Secured) Access for ENET.
 */

#define BP_CSU_SA_SA_ENET      16
#define BM_CSU_SA_SA_ENET      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_ENET(v)   ((((reg32_t) v) << 16) & BM_CSU_SA_SA_ENET)
#else
#define BF_CSU_SA_SA_ENET(v)   (((v) << 16) & BM_CSU_SA_SA_ENET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_ENET(v)   BF_CS1(CSU_SA, SA_ENET, v)
#endif

/* --- Register HW_CSU_SA, field L_ENET
 *
 * Lock bit set by TZ software for SA_ENET.
 */

#define BP_CSU_SA_L_ENET      17
#define BM_CSU_SA_L_ENET      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_ENET(v)   ((((reg32_t) v) << 17) & BM_CSU_SA_L_ENET)
#else
#define BF_CSU_SA_L_ENET(v)   (((v) << 17) & BM_CSU_SA_L_ENET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_ENET(v)   BF_CS1(CSU_SA, L_ENET, v)
#endif

/* --- Register HW_CSU_SA, field SA_DAP
 *
 * Access Policy indicator bits
 */

#define BP_CSU_SA_SA_DAP      18
#define BM_CSU_SA_SA_DAP      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_DAP(v)   ((((reg32_t) v) << 18) & BM_CSU_SA_SA_DAP)
#else
#define BF_CSU_SA_SA_DAP(v)   (((v) << 18) & BM_CSU_SA_SA_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_DAP(v)   BF_CS1(CSU_SA, SA_DAP, v)
#endif

/* --- Register HW_CSU_SA, field L_DAP
 *
 * Lock bit set by TZ software for SA_DAP.
 */

#define BP_CSU_SA_L_DAP      19
#define BM_CSU_SA_L_DAP      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_DAP(v)   ((((reg32_t) v) << 19) & BM_CSU_SA_L_DAP)
#else
#define BF_CSU_SA_L_DAP(v)   (((v) << 19) & BM_CSU_SA_L_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_DAP(v)   BF_CS1(CSU_SA, L_DAP, v)
#endif

/* --- Register HW_CSU_SA, field SA_USDHC1
 *
 * Indicate the Type (Secured/Non-Secured) Access for USDHC1.
 */

#define BP_CSU_SA_SA_USDHC1      20
#define BM_CSU_SA_SA_USDHC1      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USDHC1(v)   ((((reg32_t) v) << 20) & BM_CSU_SA_SA_USDHC1)
#else
#define BF_CSU_SA_SA_USDHC1(v)   (((v) << 20) & BM_CSU_SA_SA_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_USDHC1(v)   BF_CS1(CSU_SA, SA_USDHC1, v)
#endif

/* --- Register HW_CSU_SA, field L_USDHC1
 *
 * Lock bit set by TZ software for SA_.USDHC1
 */

#define BP_CSU_SA_L_USDHC1      21
#define BM_CSU_SA_L_USDHC1      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USDHC1(v)   ((((reg32_t) v) << 21) & BM_CSU_SA_L_USDHC1)
#else
#define BF_CSU_SA_L_USDHC1(v)   (((v) << 21) & BM_CSU_SA_L_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_USDHC1(v)   BF_CS1(CSU_SA, L_USDHC1, v)
#endif

/* --- Register HW_CSU_SA, field SA_USDHC2
 *
 * Indicate the Type (Secured/Non-Secured) Access for USDHC2.
 */

#define BP_CSU_SA_SA_USDHC2      22
#define BM_CSU_SA_SA_USDHC2      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USDHC2(v)   ((((reg32_t) v) << 22) & BM_CSU_SA_SA_USDHC2)
#else
#define BF_CSU_SA_SA_USDHC2(v)   (((v) << 22) & BM_CSU_SA_SA_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_USDHC2(v)   BF_CS1(CSU_SA, SA_USDHC2, v)
#endif

/* --- Register HW_CSU_SA, field L_USDHC2
 *
 * Lock bit set by TZ software for SA_.USDHC2
 */

#define BP_CSU_SA_L_USDHC2      23
#define BM_CSU_SA_L_USDHC2      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USDHC2(v)   ((((reg32_t) v) << 23) & BM_CSU_SA_L_USDHC2)
#else
#define BF_CSU_SA_L_USDHC2(v)   (((v) << 23) & BM_CSU_SA_L_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_USDHC2(v)   BF_CS1(CSU_SA, L_USDHC2, v)
#endif

/* --- Register HW_CSU_SA, field SA_USDHC3
 *
 * Indicate the Type (Secured/Non-Secured) Access for USDHC3.
 */

#define BP_CSU_SA_SA_USDHC3      24
#define BM_CSU_SA_SA_USDHC3      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USDHC3(v)   ((((reg32_t) v) << 24) & BM_CSU_SA_SA_USDHC3)
#else
#define BF_CSU_SA_SA_USDHC3(v)   (((v) << 24) & BM_CSU_SA_SA_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_USDHC3(v)   BF_CS1(CSU_SA, SA_USDHC3, v)
#endif

/* --- Register HW_CSU_SA, field L_USDHC3
 *
 * Lock bit set by TZ software for SA_.USDHC3
 */

#define BP_CSU_SA_L_USDHC3      25
#define BM_CSU_SA_L_USDHC3      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USDHC3(v)   ((((reg32_t) v) << 25) & BM_CSU_SA_L_USDHC3)
#else
#define BF_CSU_SA_L_USDHC3(v)   (((v) << 25) & BM_CSU_SA_L_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_USDHC3(v)   BF_CS1(CSU_SA, L_USDHC3, v)
#endif

/* --- Register HW_CSU_SA, field SA_USDHC4
 *
 * Indicate the Type (Secured/Non-Secured) Access for USDHC4.
 */

#define BP_CSU_SA_SA_USDHC4      26
#define BM_CSU_SA_SA_USDHC4      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_USDHC4(v)   ((((reg32_t) v) << 26) & BM_CSU_SA_SA_USDHC4)
#else
#define BF_CSU_SA_SA_USDHC4(v)   (((v) << 26) & BM_CSU_SA_SA_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_USDHC4(v)   BF_CS1(CSU_SA, SA_USDHC4, v)
#endif

/* --- Register HW_CSU_SA, field L_USDHC4
 *
 * Lock bit set by TZ software for SA_.USDHC14
 */

#define BP_CSU_SA_L_USDHC4      27
#define BM_CSU_SA_L_USDHC4      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_USDHC4(v)   ((((reg32_t) v) << 27) & BM_CSU_SA_L_USDHC4)
#else
#define BF_CSU_SA_L_USDHC4(v)   (((v) << 27) & BM_CSU_SA_L_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_USDHC4(v)   BF_CS1(CSU_SA, L_USDHC4, v)
#endif

/* --- Register HW_CSU_SA, field SA_HDMI_HSI
 *
 * Indicate the Type (Secured/Non-Secured) Access for HDMI Tx and HSI.
 */

#define BP_CSU_SA_SA_HDMI_HSI      28
#define BM_CSU_SA_SA_HDMI_HSI      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_SA_HDMI_HSI(v)   ((((reg32_t) v) << 28) & BM_CSU_SA_SA_HDMI_HSI)
#else
#define BF_CSU_SA_SA_HDMI_HSI(v)   (((v) << 28) & BM_CSU_SA_SA_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_SA_HDMI_HSI(v)   BF_CS1(CSU_SA, SA_HDMI_HSI, v)
#endif

/* --- Register HW_CSU_SA, field L_HDMI_HSI
 *
 * Lock bit set by TZ software for SA_.HDMI_HSI
 */

#define BP_CSU_SA_L_HDMI_HSI      29
#define BM_CSU_SA_L_HDMI_HSI      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_SA_L_HDMI_HSI(v)   ((((reg32_t) v) << 29) & BM_CSU_SA_L_HDMI_HSI)
#else
#define BF_CSU_SA_L_HDMI_HSI(v)   (((v) << 29) & BM_CSU_SA_L_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_SA_L_HDMI_HSI(v)   BF_CS1(CSU_SA, L_HDMI_HSI, v)
#endif

/*!
 * @brief HW_CSU_HPCONTROL0 - HPCONTROL0 register
 *
 * The HP Control registers CSU_HPCONTROL0 and CSU_HPCONTROL1 enable CSU to control the
 * USER/SUPERVISOR mode state for the specified masters. The register toggles the output signal
 * csu_hprot1 for system masters. The two possibilities sources for the csu_hprot1 output are:   the
 * hprot1 input signal, or  the corresponding bit in the HP register.   The even bits in the
 * registers are used for locking the control bit values.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HPC_PCIE : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of PCIE.
        unsigned L_PCIE : 1; //!< Lock bit set by TZ software for HPC_PCIE.
        unsigned RESERVED0 : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of SATA.
        unsigned RESERVED1 : 1; //!< Lock bit set by TZ software for HPC_SATA.
        unsigned HPC_SDMA : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of SDMA.
        unsigned L_SDMA : 1; //!< Lock bit set by TZ software for HPC_SDMA.
        unsigned HPC_PU : 1; //!< Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of GPU3D, GPU2D, VPU, IPU1, IPU2, OpenVG EPDC, PXP, LCDIF and VDOA.  NOTE: IPU2 and OpenVG on i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
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

/* --- Register HW_CSU_HPCONTROL0, field HPC_PCIE
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * PCIE.
 */

#define BP_CSU_HPCONTROL0_HPC_PCIE      0
#define BM_CSU_HPCONTROL0_HPC_PCIE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_PCIE(v)   ((((reg32_t) v) << 0) & BM_CSU_HPCONTROL0_HPC_PCIE)
#else
#define BF_CSU_HPCONTROL0_HPC_PCIE(v)   (((v) << 0) & BM_CSU_HPCONTROL0_HPC_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_PCIE(v)   BF_CS1(CSU_HPCONTROL0, HPC_PCIE, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_PCIE
 *
 * Lock bit set by TZ software for HPC_PCIE.
 */

#define BP_CSU_HPCONTROL0_L_PCIE      1
#define BM_CSU_HPCONTROL0_L_PCIE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_PCIE(v)   ((((reg32_t) v) << 1) & BM_CSU_HPCONTROL0_L_PCIE)
#else
#define BF_CSU_HPCONTROL0_L_PCIE(v)   (((v) << 1) & BM_CSU_HPCONTROL0_L_PCIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_PCIE(v)   BF_CS1(CSU_HPCONTROL0, L_PCIE, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_SDMA
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * SDMA.
 */

#define BP_CSU_HPCONTROL0_HPC_SDMA      4
#define BM_CSU_HPCONTROL0_HPC_SDMA      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_SDMA(v)   ((((reg32_t) v) << 4) & BM_CSU_HPCONTROL0_HPC_SDMA)
#else
#define BF_CSU_HPCONTROL0_HPC_SDMA(v)   (((v) << 4) & BM_CSU_HPCONTROL0_HPC_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_SDMA(v)   BF_CS1(CSU_HPCONTROL0, HPC_SDMA, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_SDMA
 *
 * Lock bit set by TZ software for HPC_SDMA.
 */

#define BP_CSU_HPCONTROL0_L_SDMA      5
#define BM_CSU_HPCONTROL0_L_SDMA      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_SDMA(v)   ((((reg32_t) v) << 5) & BM_CSU_HPCONTROL0_L_SDMA)
#else
#define BF_CSU_HPCONTROL0_L_SDMA(v)   (((v) << 5) & BM_CSU_HPCONTROL0_L_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_SDMA(v)   BF_CS1(CSU_HPCONTROL0, L_SDMA, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_PU
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * GPU3D, GPU2D, VPU, IPU1, IPU2, OpenVG EPDC, PXP, LCDIF and VDOA.  NOTE: IPU2 and OpenVG on
 * i.MX6DQ only; EPDC, PXP and LCDIF on i.MX6SDL only
 */

#define BP_CSU_HPCONTROL0_HPC_PU      6
#define BM_CSU_HPCONTROL0_HPC_PU      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_PU(v)   ((((reg32_t) v) << 6) & BM_CSU_HPCONTROL0_HPC_PU)
#else
#define BF_CSU_HPCONTROL0_HPC_PU(v)   (((v) << 6) & BM_CSU_HPCONTROL0_HPC_PU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_PU(v)   BF_CS1(CSU_HPCONTROL0, HPC_PU, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_PU
 *
 * Lock bit set by TZ software for HPC_PU.
 */

#define BP_CSU_HPCONTROL0_L_PU      7
#define BM_CSU_HPCONTROL0_L_PU      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_PU(v)   ((((reg32_t) v) << 7) & BM_CSU_HPCONTROL0_L_PU)
#else
#define BF_CSU_HPCONTROL0_L_PU(v)   (((v) << 7) & BM_CSU_HPCONTROL0_L_PU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_PU(v)   BF_CS1(CSU_HPCONTROL0, L_PU, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_USB
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USB.
 */

#define BP_CSU_HPCONTROL0_HPC_USB      8
#define BM_CSU_HPCONTROL0_HPC_USB      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USB(v)   ((((reg32_t) v) << 8) & BM_CSU_HPCONTROL0_HPC_USB)
#else
#define BF_CSU_HPCONTROL0_HPC_USB(v)   (((v) << 8) & BM_CSU_HPCONTROL0_HPC_USB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_USB(v)   BF_CS1(CSU_HPCONTROL0, HPC_USB, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_USB
 *
 * Lock bit set by TZ software for HPC_USB.
 */

#define BP_CSU_HPCONTROL0_L_USB      9
#define BM_CSU_HPCONTROL0_L_USB      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USB(v)   ((((reg32_t) v) << 9) & BM_CSU_HPCONTROL0_L_USB)
#else
#define BF_CSU_HPCONTROL0_L_USB(v)   (((v) << 9) & BM_CSU_HPCONTROL0_L_USB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_USB(v)   BF_CS1(CSU_HPCONTROL0, L_USB, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_TEST
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * IOMUX Test Port.
 */

#define BP_CSU_HPCONTROL0_HPC_TEST      10
#define BM_CSU_HPCONTROL0_HPC_TEST      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_TEST(v)   ((((reg32_t) v) << 10) & BM_CSU_HPCONTROL0_HPC_TEST)
#else
#define BF_CSU_HPCONTROL0_HPC_TEST(v)   (((v) << 10) & BM_CSU_HPCONTROL0_HPC_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_TEST(v)   BF_CS1(CSU_HPCONTROL0, HPC_TEST, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_TEST
 *
 * Lock bit set by TZ software for HPC_TEST.
 */

#define BP_CSU_HPCONTROL0_L_TEST      11
#define BM_CSU_HPCONTROL0_L_TEST      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_TEST(v)   ((((reg32_t) v) << 11) & BM_CSU_HPCONTROL0_L_TEST)
#else
#define BF_CSU_HPCONTROL0_L_TEST(v)   (((v) << 11) & BM_CSU_HPCONTROL0_L_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_TEST(v)   BF_CS1(CSU_HPCONTROL0, L_TEST, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_MLB
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * MLB.
 */

#define BP_CSU_HPCONTROL0_HPC_MLB      12
#define BM_CSU_HPCONTROL0_HPC_MLB      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_MLB(v)   ((((reg32_t) v) << 12) & BM_CSU_HPCONTROL0_HPC_MLB)
#else
#define BF_CSU_HPCONTROL0_HPC_MLB(v)   (((v) << 12) & BM_CSU_HPCONTROL0_HPC_MLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_MLB(v)   BF_CS1(CSU_HPCONTROL0, HPC_MLB, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_MLB
 *
 * Lock bit set by TZ software for HPC_MLB.
 */

#define BP_CSU_HPCONTROL0_L_MLB      13
#define BM_CSU_HPCONTROL0_L_MLB      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_MLB(v)   ((((reg32_t) v) << 13) & BM_CSU_HPCONTROL0_L_MLB)
#else
#define BF_CSU_HPCONTROL0_L_MLB(v)   (((v) << 13) & BM_CSU_HPCONTROL0_L_MLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_MLB(v)   BF_CS1(CSU_HPCONTROL0, L_MLB, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_CAAM
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * CAAM.
 */

#define BP_CSU_HPCONTROL0_HPC_CAAM      14
#define BM_CSU_HPCONTROL0_HPC_CAAM      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_CAAM(v)   ((((reg32_t) v) << 14) & BM_CSU_HPCONTROL0_HPC_CAAM)
#else
#define BF_CSU_HPCONTROL0_HPC_CAAM(v)   (((v) << 14) & BM_CSU_HPCONTROL0_HPC_CAAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_CAAM(v)   BF_CS1(CSU_HPCONTROL0, HPC_CAAM, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_CAAM
 *
 * Lock bit set by TZ software for HPC_CAAM.
 */

#define BP_CSU_HPCONTROL0_L_CAAM      15
#define BM_CSU_HPCONTROL0_L_CAAM      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_CAAM(v)   ((((reg32_t) v) << 15) & BM_CSU_HPCONTROL0_L_CAAM)
#else
#define BF_CSU_HPCONTROL0_L_CAAM(v)   (((v) << 15) & BM_CSU_HPCONTROL0_L_CAAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_CAAM(v)   BF_CS1(CSU_HPCONTROL0, L_CAAM, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_RAWNAND
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * RawNAND.
 */

#define BP_CSU_HPCONTROL0_HPC_RAWNAND      16
#define BM_CSU_HPCONTROL0_HPC_RAWNAND      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_RAWNAND(v)   ((((reg32_t) v) << 16) & BM_CSU_HPCONTROL0_HPC_RAWNAND)
#else
#define BF_CSU_HPCONTROL0_HPC_RAWNAND(v)   (((v) << 16) & BM_CSU_HPCONTROL0_HPC_RAWNAND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_RAWNAND(v)   BF_CS1(CSU_HPCONTROL0, HPC_RAWNAND, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_RAWNAND
 *
 * Lock bit set by TZ software for HPC_RAWNAND.
 */

#define BP_CSU_HPCONTROL0_L_RAWNAND      17
#define BM_CSU_HPCONTROL0_L_RAWNAND      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_RAWNAND(v)   ((((reg32_t) v) << 17) & BM_CSU_HPCONTROL0_L_RAWNAND)
#else
#define BF_CSU_HPCONTROL0_L_RAWNAND(v)   (((v) << 17) & BM_CSU_HPCONTROL0_L_RAWNAND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_RAWNAND(v)   BF_CS1(CSU_HPCONTROL0, L_RAWNAND, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_APBHDMA
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * apbhdma.
 */

#define BP_CSU_HPCONTROL0_HPC_APBHDMA      18
#define BM_CSU_HPCONTROL0_HPC_APBHDMA      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_APBHDMA(v)   ((((reg32_t) v) << 18) & BM_CSU_HPCONTROL0_HPC_APBHDMA)
#else
#define BF_CSU_HPCONTROL0_HPC_APBHDMA(v)   (((v) << 18) & BM_CSU_HPCONTROL0_HPC_APBHDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_APBHDMA(v)   BF_CS1(CSU_HPCONTROL0, HPC_APBHDMA, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_ABPHDMA
 *
 * Lock bit set by TZ software for HPC_APBHDMA.
 */

#define BP_CSU_HPCONTROL0_L_ABPHDMA      19
#define BM_CSU_HPCONTROL0_L_ABPHDMA      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_ABPHDMA(v)   ((((reg32_t) v) << 19) & BM_CSU_HPCONTROL0_L_ABPHDMA)
#else
#define BF_CSU_HPCONTROL0_L_ABPHDMA(v)   (((v) << 19) & BM_CSU_HPCONTROL0_L_ABPHDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_ABPHDMA(v)   BF_CS1(CSU_HPCONTROL0, L_ABPHDMA, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_ENET
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * ENET.
 */

#define BP_CSU_HPCONTROL0_HPC_ENET      20
#define BM_CSU_HPCONTROL0_HPC_ENET      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_ENET(v)   ((((reg32_t) v) << 20) & BM_CSU_HPCONTROL0_HPC_ENET)
#else
#define BF_CSU_HPCONTROL0_HPC_ENET(v)   (((v) << 20) & BM_CSU_HPCONTROL0_HPC_ENET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_ENET(v)   BF_CS1(CSU_HPCONTROL0, HPC_ENET, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_ENET
 *
 * Lock bit set by TZ software for HPC_ENET.
 */

#define BP_CSU_HPCONTROL0_L_ENET      21
#define BM_CSU_HPCONTROL0_L_ENET      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_ENET(v)   ((((reg32_t) v) << 21) & BM_CSU_HPCONTROL0_L_ENET)
#else
#define BF_CSU_HPCONTROL0_L_ENET(v)   (((v) << 21) & BM_CSU_HPCONTROL0_L_ENET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_ENET(v)   BF_CS1(CSU_HPCONTROL0, L_ENET, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_DAP
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * DAP.
 */

#define BP_CSU_HPCONTROL0_HPC_DAP      22
#define BM_CSU_HPCONTROL0_HPC_DAP      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_DAP(v)   ((((reg32_t) v) << 22) & BM_CSU_HPCONTROL0_HPC_DAP)
#else
#define BF_CSU_HPCONTROL0_HPC_DAP(v)   (((v) << 22) & BM_CSU_HPCONTROL0_HPC_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_DAP(v)   BF_CS1(CSU_HPCONTROL0, HPC_DAP, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_DAP
 *
 * Lock bit set by TZ software for HPC_DAP.
 */

#define BP_CSU_HPCONTROL0_L_DAP      23
#define BM_CSU_HPCONTROL0_L_DAP      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_DAP(v)   ((((reg32_t) v) << 23) & BM_CSU_HPCONTROL0_L_DAP)
#else
#define BF_CSU_HPCONTROL0_L_DAP(v)   (((v) << 23) & BM_CSU_HPCONTROL0_L_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_DAP(v)   BF_CS1(CSU_HPCONTROL0, L_DAP, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_USDHC1
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USDHC1.
 */

#define BP_CSU_HPCONTROL0_HPC_USDHC1      24
#define BM_CSU_HPCONTROL0_HPC_USDHC1      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USDHC1(v)   ((((reg32_t) v) << 24) & BM_CSU_HPCONTROL0_HPC_USDHC1)
#else
#define BF_CSU_HPCONTROL0_HPC_USDHC1(v)   (((v) << 24) & BM_CSU_HPCONTROL0_HPC_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_USDHC1(v)   BF_CS1(CSU_HPCONTROL0, HPC_USDHC1, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_USDHC1
 *
 * Lock bit set by TZ software for HPC_USDHC1.
 */

#define BP_CSU_HPCONTROL0_L_USDHC1      25
#define BM_CSU_HPCONTROL0_L_USDHC1      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USDHC1(v)   ((((reg32_t) v) << 25) & BM_CSU_HPCONTROL0_L_USDHC1)
#else
#define BF_CSU_HPCONTROL0_L_USDHC1(v)   (((v) << 25) & BM_CSU_HPCONTROL0_L_USDHC1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_USDHC1(v)   BF_CS1(CSU_HPCONTROL0, L_USDHC1, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_USDHC2
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USDHC2.
 */

#define BP_CSU_HPCONTROL0_HPC_USDHC2      26
#define BM_CSU_HPCONTROL0_HPC_USDHC2      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USDHC2(v)   ((((reg32_t) v) << 26) & BM_CSU_HPCONTROL0_HPC_USDHC2)
#else
#define BF_CSU_HPCONTROL0_HPC_USDHC2(v)   (((v) << 26) & BM_CSU_HPCONTROL0_HPC_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_USDHC2(v)   BF_CS1(CSU_HPCONTROL0, HPC_USDHC2, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_USDHC2
 *
 * Lock bit set by TZ software for HPC_USDHC2.
 */

#define BP_CSU_HPCONTROL0_L_USDHC2      27
#define BM_CSU_HPCONTROL0_L_USDHC2      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USDHC2(v)   ((((reg32_t) v) << 27) & BM_CSU_HPCONTROL0_L_USDHC2)
#else
#define BF_CSU_HPCONTROL0_L_USDHC2(v)   (((v) << 27) & BM_CSU_HPCONTROL0_L_USDHC2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_USDHC2(v)   BF_CS1(CSU_HPCONTROL0, L_USDHC2, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_USDHC3
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USDHC3.
 */

#define BP_CSU_HPCONTROL0_HPC_USDHC3      28
#define BM_CSU_HPCONTROL0_HPC_USDHC3      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USDHC3(v)   ((((reg32_t) v) << 28) & BM_CSU_HPCONTROL0_HPC_USDHC3)
#else
#define BF_CSU_HPCONTROL0_HPC_USDHC3(v)   (((v) << 28) & BM_CSU_HPCONTROL0_HPC_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_USDHC3(v)   BF_CS1(CSU_HPCONTROL0, HPC_USDHC3, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_USDHC3
 *
 * Lock bit set by TZ software for HPC_USDHC3.
 */

#define BP_CSU_HPCONTROL0_L_USDHC3      29
#define BM_CSU_HPCONTROL0_L_USDHC3      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USDHC3(v)   ((((reg32_t) v) << 29) & BM_CSU_HPCONTROL0_L_USDHC3)
#else
#define BF_CSU_HPCONTROL0_L_USDHC3(v)   (((v) << 29) & BM_CSU_HPCONTROL0_L_USDHC3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_USDHC3(v)   BF_CS1(CSU_HPCONTROL0, L_USDHC3, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field HPC_USDHC4
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * USDHC4.
 */

#define BP_CSU_HPCONTROL0_HPC_USDHC4      30
#define BM_CSU_HPCONTROL0_HPC_USDHC4      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_HPC_USDHC4(v)   ((((reg32_t) v) << 30) & BM_CSU_HPCONTROL0_HPC_USDHC4)
#else
#define BF_CSU_HPCONTROL0_HPC_USDHC4(v)   (((v) << 30) & BM_CSU_HPCONTROL0_HPC_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_HPC_USDHC4(v)   BF_CS1(CSU_HPCONTROL0, HPC_USDHC4, v)
#endif

/* --- Register HW_CSU_HPCONTROL0, field L_USDHC4
 *
 * Lock bit set by TZ software for HPC_USDHC4.
 */

#define BP_CSU_HPCONTROL0_L_USDHC4      31
#define BM_CSU_HPCONTROL0_L_USDHC4      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL0_L_USDHC4(v)   ((((reg32_t) v) << 31) & BM_CSU_HPCONTROL0_L_USDHC4)
#else
#define BF_CSU_HPCONTROL0_L_USDHC4(v)   (((v) << 31) & BM_CSU_HPCONTROL0_L_USDHC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL0_L_USDHC4(v)   BF_CS1(CSU_HPCONTROL0, L_USDHC4, v)
#endif

/*!
 * @brief HW_CSU_HPCONTROL1 - HPCONTROL1 register
 *
 * The SCU_HPCONTROL1 register is expansion of SCU_HPCONTROL0 register. See SCU_HPCONTROL0 register
 * definition.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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

/* --- Register HW_CSU_HPCONTROL1, field HPC_HDMI_HSI
 *
 * Determines if the Register value of the HP field corresponding will be pass as the hprot[1] of
 * HDMI Tx and HSI.
 */

#define BP_CSU_HPCONTROL1_HPC_HDMI_HSI      0
#define BM_CSU_HPCONTROL1_HPC_HDMI_HSI      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL1_HPC_HDMI_HSI(v)   ((((reg32_t) v) << 0) & BM_CSU_HPCONTROL1_HPC_HDMI_HSI)
#else
#define BF_CSU_HPCONTROL1_HPC_HDMI_HSI(v)   (((v) << 0) & BM_CSU_HPCONTROL1_HPC_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL1_HPC_HDMI_HSI(v)   BF_CS1(CSU_HPCONTROL1, HPC_HDMI_HSI, v)
#endif

/* --- Register HW_CSU_HPCONTROL1, field L_HDMI_HSI
 *
 * Lock bit set by TZ software for HPC_HDMI_HSI.
 */

#define BP_CSU_HPCONTROL1_L_HDMI_HSI      1
#define BM_CSU_HPCONTROL1_L_HDMI_HSI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CSU_HPCONTROL1_L_HDMI_HSI(v)   ((((reg32_t) v) << 1) & BM_CSU_HPCONTROL1_L_HDMI_HSI)
#else
#define BF_CSU_HPCONTROL1_L_HDMI_HSI(v)   (((v) << 1) & BM_CSU_HPCONTROL1_L_HDMI_HSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSU_HPCONTROL1_L_HDMI_HSI(v)   BF_CS1(CSU_HPCONTROL1, L_HDMI_HSI, v)
#endif



/*!
 * @brief All CSU module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_csu_csl_t CSL; //!< Config security level register
    reg32_t _reserved0[127];
    volatile hw_csu_hp0_t HP0; //!< HP0 register
    volatile hw_csu_hp1_t HP1; //!< HP1 register
    reg32_t _reserved1[4];
    volatile hw_csu_sa_t SA; //!< Secure access register
    reg32_t _reserved2[79];
    volatile hw_csu_hpcontrol0_t HPCONTROL0; //!< HPCONTROL0 register
    volatile hw_csu_hpcontrol1_t HPCONTROL1; //!< HPCONTROL1 register
} hw_csu_t
#endif

//! @brief Macro to access all CSU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CSU(0)</code>.
#define HW_CSU     (*(volatile hw_csu_t *) REGS_CSU_BASE)


#endif // _CSU_H
