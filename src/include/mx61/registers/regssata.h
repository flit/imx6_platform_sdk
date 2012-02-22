/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SATA_H
#define _SATA_H

#include "regs.h"

#ifndef REGS_SATA_BASE
#define REGS_SATA_BASE (REGS_BASE + 0x02200000)
#endif


/*!
 * @brief HW_SATA_CAP - HBA Capabilites Register
 *
 * This register indicates basic capabilities of the SATA block to the
 * software.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NP : 5; //!< Number of Ports.  0's based value indicating the number of Ports supported by the SATA block:  The options for this field are:  • 0x00: 1 Port  • 0x01: 2 Ports  • 0x02: 3 Ports  Reset Value: 0x00  Configurable: AHSATA_NUM_PORTS-1
        unsigned SXS : 1; //!< Supports External SATA.  The options for this field are:  1 Indicates that the SATA block has one or more Ports that has a signal only connector (power is not part of that connector) that is externally accessible. When this bit is set to 1, the software can refer to the SATA_P #  0 CMD[ESP] bit to determine whether a specific Port has its signal connector externally accessible.  0 Indicates that the SATA block has no Ports that have a signal only connector externally accessible.  Reset Value: Configurable
        unsigned EMS : 1; //!< Enclosure Management Support.  SATA block does not support enclosure management.
        unsigned CCCS : 1; //!< Command Completion Coalescing Support.  SATA block supports command completion coalescing.
        unsigned NCS : 5; //!< Number of Command Slots.  SATA block supports 32 command slots per Port.
        unsigned PSC : 1; //!< Partial State Capable.  SATA block supports transitions to the interface PARTIAL power management state.
        unsigned SSC : 1; //!< Slumber State Capable.  SATA block supports transitions to the interface SLUMBER power management state.
        unsigned PMD : 1; //!< PIO Multiple DRQ Block.  SATA block supports multiple DRQ block data transfers for the PIO command protocol.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned SMP : 1; //!< Supports Port Multiplier.  SATA block supports command-based switching Port Multiplier on any of its Ports.
        unsigned SAM : 1; //!< Supports AHCI Mode Only.  SATA block supports AHCI mode only and does not support legacy, task-file based register interface.
        unsigned RESERVED1 : 1; //!< Reserved. Returns 0 on read.
        unsigned ISS : 4; //!< Interface Speed Support.  Reserved. Returns 0x2 on read.
        unsigned SCLO : 1; //!< Supports Command List Override.  SATA block supports the SATA_P #  0 CMD[CLO] bit functionality for Port  Multiplier devices' enumeration.
        unsigned SAL : 1; //!< Supports Activity LED.  SATA block supports activity indication using signal p #  0 _act_led.
        unsigned SALP : 1; //!< Supports Aggressive Link Power Management.  SATA block supports auto-generating (Port-initiated) Link Layer requests to the PARTIAL or SLUMBER power management states when there are no commands to process.
        unsigned SSS : 1; //!< Supports Staggered Spin-up.  This bit is set by the system firmware/BIOS to indicate platform support for staggered devices' spin-up. SATA block supports this feature through the SATA_P #  0 CMD[SUD] bit functionality.
        unsigned SMPS : 1; //!< Supports Mechanical Presence Switch.  This bit is set by the system firmware/BIOS when the platform supports mechanical presence switch for hot plug operation.  Dependencies: This field is implemented only when parameter (Macro configuration parm) DEV_MP_SWITCH==Include. When this field is not implemented, this field is reserved, and reads 1'b0.
        unsigned SSNTF : 1; //!< Supports SNotification Register.  SATA block supports SATA_P #  0 SNTF (SNotification) register and its associated functionality.
        unsigned SNCQ : 1; //!< Supports Native Command Queuing.  SATA block supports SATA native command queueing by handling DMA Setup FIS natively.
        unsigned S64A : 1; //!< Supports 64-bit Addressing  SATA block supports 64-bit addressable data structures by utilizing  PFFBU and P#CLBU registers.  Reset Value: Configurable.
    } B;
} hw_sata_cap_t;
#endif

/*
 * constants & macros for entire SATA_CAP register
 */
#define HW_SATA_CAP_ADDR      (REGS_SATA_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_CAP           (*(volatile hw_sata_cap_t *) HW_SATA_CAP_ADDR)
#define HW_SATA_CAP_RD()      (HW_SATA_CAP.U)
#define HW_SATA_CAP_WR(v)     (HW_SATA_CAP.U = (v))
#define HW_SATA_CAP_SET(v)    (HW_SATA_CAP_WR(HW_SATA_CAP_RD() |  (v)))
#define HW_SATA_CAP_CLR(v)    (HW_SATA_CAP_WR(HW_SATA_CAP_RD() & ~(v)))
#define HW_SATA_CAP_TOG(v)    (HW_SATA_CAP_WR(HW_SATA_CAP_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_CAP bitfields
 */

/* --- Register HW_SATA_CAP, field NP
 *
 * Number of Ports.  0's based value indicating the number of Ports supported by the SATA
 * block:  The options for this field are:  • 0x00: 1 Port  • 0x01: 2 Ports  • 0x02: 3 Ports  Reset
 * Value: 0x00  Configurable: AHSATA_NUM_PORTS-1
 */

#define BP_SATA_CAP_NP      0
#define BM_SATA_CAP_NP      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_NP(v)   ((((reg32_t) v) << 0) & BM_SATA_CAP_NP)
#else
#define BF_SATA_CAP_NP(v)   (((v) << 0) & BM_SATA_CAP_NP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_NP(v)   BF_CS1(SATA_CAP, NP, v)
#endif

/* --- Register HW_SATA_CAP, field SXS
 *
 * Supports External SATA.  The options for this field are:  1 Indicates that the SATA block has one
 * or more Ports that has a                                 signal only connector (power is not part
 * of that connector) that is                                 externally accessible. When this bit
 * is set to 1, the software can                                 refer to the SATA_P #  0 CMD[ESP]
 * bit to determine whether a                                 specific Port has its signal connector
 * externally accessible.  0 Indicates that the SATA block has no Ports that have a signal only
 * connector externally accessible.  Reset Value: Configurable
 */

#define BP_SATA_CAP_SXS      5
#define BM_SATA_CAP_SXS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SXS(v)   ((((reg32_t) v) << 5) & BM_SATA_CAP_SXS)
#else
#define BF_SATA_CAP_SXS(v)   (((v) << 5) & BM_SATA_CAP_SXS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SXS(v)   BF_CS1(SATA_CAP, SXS, v)
#endif

/* --- Register HW_SATA_CAP, field EMS
 *
 * Enclosure Management Support.  SATA block does not support enclosure management.
 */

#define BP_SATA_CAP_EMS      6
#define BM_SATA_CAP_EMS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_EMS(v)   ((((reg32_t) v) << 6) & BM_SATA_CAP_EMS)
#else
#define BF_SATA_CAP_EMS(v)   (((v) << 6) & BM_SATA_CAP_EMS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_EMS(v)   BF_CS1(SATA_CAP, EMS, v)
#endif

/* --- Register HW_SATA_CAP, field CCCS
 *
 * Command Completion Coalescing Support.  SATA block supports command completion coalescing.
 */

#define BP_SATA_CAP_CCCS      7
#define BM_SATA_CAP_CCCS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_CCCS(v)   ((((reg32_t) v) << 7) & BM_SATA_CAP_CCCS)
#else
#define BF_SATA_CAP_CCCS(v)   (((v) << 7) & BM_SATA_CAP_CCCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_CCCS(v)   BF_CS1(SATA_CAP, CCCS, v)
#endif

/* --- Register HW_SATA_CAP, field NCS
 *
 * Number of Command Slots.  SATA block supports 32 command slots per Port.
 */

#define BP_SATA_CAP_NCS      8
#define BM_SATA_CAP_NCS      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_NCS(v)   ((((reg32_t) v) << 8) & BM_SATA_CAP_NCS)
#else
#define BF_SATA_CAP_NCS(v)   (((v) << 8) & BM_SATA_CAP_NCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_NCS(v)   BF_CS1(SATA_CAP, NCS, v)
#endif

/* --- Register HW_SATA_CAP, field PSC
 *
 * Partial State Capable.  SATA block supports transitions to the interface PARTIAL power
 * management state.
 */

#define BP_SATA_CAP_PSC      13
#define BM_SATA_CAP_PSC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_PSC(v)   ((((reg32_t) v) << 13) & BM_SATA_CAP_PSC)
#else
#define BF_SATA_CAP_PSC(v)   (((v) << 13) & BM_SATA_CAP_PSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_PSC(v)   BF_CS1(SATA_CAP, PSC, v)
#endif

/* --- Register HW_SATA_CAP, field SSC
 *
 * Slumber State Capable.  SATA block supports transitions to the interface SLUMBER power
 * management state.
 */

#define BP_SATA_CAP_SSC      14
#define BM_SATA_CAP_SSC      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SSC(v)   ((((reg32_t) v) << 14) & BM_SATA_CAP_SSC)
#else
#define BF_SATA_CAP_SSC(v)   (((v) << 14) & BM_SATA_CAP_SSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SSC(v)   BF_CS1(SATA_CAP, SSC, v)
#endif

/* --- Register HW_SATA_CAP, field PMD
 *
 * PIO Multiple DRQ Block.  SATA block supports multiple DRQ block data transfers for the PIO
 * command protocol.
 */

#define BP_SATA_CAP_PMD      15
#define BM_SATA_CAP_PMD      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_PMD(v)   ((((reg32_t) v) << 15) & BM_SATA_CAP_PMD)
#else
#define BF_SATA_CAP_PMD(v)   (((v) << 15) & BM_SATA_CAP_PMD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_PMD(v)   BF_CS1(SATA_CAP, PMD, v)
#endif

/* --- Register HW_SATA_CAP, field SMP
 *
 * Supports Port Multiplier.  SATA block supports command-based switching Port Multiplier on any of
 * its Ports.
 */

#define BP_SATA_CAP_SMP      17
#define BM_SATA_CAP_SMP      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SMP(v)   ((((reg32_t) v) << 17) & BM_SATA_CAP_SMP)
#else
#define BF_SATA_CAP_SMP(v)   (((v) << 17) & BM_SATA_CAP_SMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SMP(v)   BF_CS1(SATA_CAP, SMP, v)
#endif

/* --- Register HW_SATA_CAP, field SAM
 *
 * Supports AHCI Mode Only.  SATA block supports AHCI mode only and does not support legacy,
 * task-file based register interface.
 */

#define BP_SATA_CAP_SAM      18
#define BM_SATA_CAP_SAM      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SAM(v)   ((((reg32_t) v) << 18) & BM_SATA_CAP_SAM)
#else
#define BF_SATA_CAP_SAM(v)   (((v) << 18) & BM_SATA_CAP_SAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SAM(v)   BF_CS1(SATA_CAP, SAM, v)
#endif

/* --- Register HW_SATA_CAP, field ISS
 *
 * Interface Speed Support.  Reserved. Returns 0x2 on read.
 */

#define BP_SATA_CAP_ISS      20
#define BM_SATA_CAP_ISS      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_ISS(v)   ((((reg32_t) v) << 20) & BM_SATA_CAP_ISS)
#else
#define BF_SATA_CAP_ISS(v)   (((v) << 20) & BM_SATA_CAP_ISS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_ISS(v)   BF_CS1(SATA_CAP, ISS, v)
#endif

/* --- Register HW_SATA_CAP, field SCLO
 *
 * Supports Command List Override.  SATA block supports the SATA_P #  0 CMD[CLO] bit functionality
 * for                                 Port  Multiplier devices' enumeration.
 */

#define BP_SATA_CAP_SCLO      24
#define BM_SATA_CAP_SCLO      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SCLO(v)   ((((reg32_t) v) << 24) & BM_SATA_CAP_SCLO)
#else
#define BF_SATA_CAP_SCLO(v)   (((v) << 24) & BM_SATA_CAP_SCLO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SCLO(v)   BF_CS1(SATA_CAP, SCLO, v)
#endif

/* --- Register HW_SATA_CAP, field SAL
 *
 * Supports Activity LED.  SATA block supports activity indication using signal p #  0 _act_led.
 */

#define BP_SATA_CAP_SAL      25
#define BM_SATA_CAP_SAL      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SAL(v)   ((((reg32_t) v) << 25) & BM_SATA_CAP_SAL)
#else
#define BF_SATA_CAP_SAL(v)   (((v) << 25) & BM_SATA_CAP_SAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SAL(v)   BF_CS1(SATA_CAP, SAL, v)
#endif

/* --- Register HW_SATA_CAP, field SALP
 *
 * Supports Aggressive Link Power Management.  SATA block supports auto-generating (Port-initiated)
 * Link Layer                                 requests to the PARTIAL or SLUMBER power management
 * states when                                 there are no commands to process.
 */

#define BP_SATA_CAP_SALP      26
#define BM_SATA_CAP_SALP      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SALP(v)   ((((reg32_t) v) << 26) & BM_SATA_CAP_SALP)
#else
#define BF_SATA_CAP_SALP(v)   (((v) << 26) & BM_SATA_CAP_SALP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SALP(v)   BF_CS1(SATA_CAP, SALP, v)
#endif

/* --- Register HW_SATA_CAP, field SSS
 *
 * Supports Staggered Spin-up.  This bit is set by the system firmware/BIOS to indicate platform
 * support for staggered devices' spin-up. SATA block supports this
 * feature through the SATA_P #  0 CMD[SUD] bit functionality.
 */

#define BP_SATA_CAP_SSS      27
#define BM_SATA_CAP_SSS      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SSS(v)   ((((reg32_t) v) << 27) & BM_SATA_CAP_SSS)
#else
#define BF_SATA_CAP_SSS(v)   (((v) << 27) & BM_SATA_CAP_SSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SSS(v)   BF_CS1(SATA_CAP, SSS, v)
#endif

/* --- Register HW_SATA_CAP, field SMPS
 *
 * Supports Mechanical Presence Switch.  This bit is set by the system firmware/BIOS when the
 * platform                                 supports mechanical presence switch for hot plug
 * operation.  Dependencies: This field is implemented only when parameter (Macro
 * configuration parm) DEV_MP_SWITCH==Include. When this field is not
 * implemented, this field is reserved, and reads 1'b0.
 */

#define BP_SATA_CAP_SMPS      28
#define BM_SATA_CAP_SMPS      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SMPS(v)   ((((reg32_t) v) << 28) & BM_SATA_CAP_SMPS)
#else
#define BF_SATA_CAP_SMPS(v)   (((v) << 28) & BM_SATA_CAP_SMPS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SMPS(v)   BF_CS1(SATA_CAP, SMPS, v)
#endif

/* --- Register HW_SATA_CAP, field SSNTF
 *
 * Supports SNotification Register.  SATA block supports SATA_P #  0 SNTF (SNotification) register
 * and its                                 associated functionality.
 */

#define BP_SATA_CAP_SSNTF      29
#define BM_SATA_CAP_SSNTF      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SSNTF(v)   ((((reg32_t) v) << 29) & BM_SATA_CAP_SSNTF)
#else
#define BF_SATA_CAP_SSNTF(v)   (((v) << 29) & BM_SATA_CAP_SSNTF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SSNTF(v)   BF_CS1(SATA_CAP, SSNTF, v)
#endif

/* --- Register HW_SATA_CAP, field SNCQ
 *
 * Supports Native Command Queuing.  SATA block supports SATA native command queueing by handling
 * DMA                                 Setup FIS natively.
 */

#define BP_SATA_CAP_SNCQ      30
#define BM_SATA_CAP_SNCQ      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_SNCQ(v)   ((((reg32_t) v) << 30) & BM_SATA_CAP_SNCQ)
#else
#define BF_SATA_CAP_SNCQ(v)   (((v) << 30) & BM_SATA_CAP_SNCQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_SNCQ(v)   BF_CS1(SATA_CAP, SNCQ, v)
#endif

/* --- Register HW_SATA_CAP, field S64A
 *
 * Supports 64-bit Addressing  SATA block supports 64-bit addressable data structures by
 * utilizing  PFFBU and P#CLBU registers.  Reset Value: Configurable.
 */

#define BP_SATA_CAP_S64A      31
#define BM_SATA_CAP_S64A      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP_S64A(v)   ((((reg32_t) v) << 31) & BM_SATA_CAP_S64A)
#else
#define BF_SATA_CAP_S64A(v)   (((v) << 31) & BM_SATA_CAP_S64A)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP_S64A(v)   BF_CS1(SATA_CAP, S64A, v)
#endif

/*!
 * @brief HW_SATA_GHC - Global HBA Control Register
 *
 * This register controls various global actions of the SATA block.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HR : 1; //!< HBA Reset.  When set by the software, this bit causes an internal Global reset of the SATA block. All state machines that relate to data transfers and queueing return to an idle state, and all the Ports are re-initialized by sending COMRESET When staggered spin-up is not supported. When staggered spin-up is supported, then the software must spin-up each Port after this reset has completed. See for details.  The SATA block clears this bit when the reset action is done. A software write of 0 has no effect.
        unsigned IE : 1; //!< Interrupt Enable.  This global bit enables interrupts from the SATA block. When cleared, all interrupt sources from all the Ports are disabled (masked). When set, interrupts are enabled and any SATA block interrupt event causes intrq output assertion.  This field is reset on Global reset (SATA_GHC[HR]=1).
        unsigned RESERVED0 : 29; //!< Reserved
        unsigned AE : 1; //!< AHCI Enable.  This bit is always set since SATA block supports only AHCI mode as indicated by the SATA_CAP[SAM]=1.
    } B;
} hw_sata_ghc_t;
#endif

/*
 * constants & macros for entire SATA_GHC register
 */
#define HW_SATA_GHC_ADDR      (REGS_SATA_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GHC           (*(volatile hw_sata_ghc_t *) HW_SATA_GHC_ADDR)
#define HW_SATA_GHC_RD()      (HW_SATA_GHC.U)
#define HW_SATA_GHC_WR(v)     (HW_SATA_GHC.U = (v))
#define HW_SATA_GHC_SET(v)    (HW_SATA_GHC_WR(HW_SATA_GHC_RD() |  (v)))
#define HW_SATA_GHC_CLR(v)    (HW_SATA_GHC_WR(HW_SATA_GHC_RD() & ~(v)))
#define HW_SATA_GHC_TOG(v)    (HW_SATA_GHC_WR(HW_SATA_GHC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_GHC bitfields
 */

/* --- Register HW_SATA_GHC, field HR
 *
 * HBA Reset.  When set by the software, this bit causes an internal Global reset of
 * the SATA block. All state machines that relate to data transfers and
 * queueing return to an idle state, and all the Ports are                                 re-
 * initialized by sending COMRESET When staggered spin-up is not
 * supported. When staggered spin-up is supported, then the software
 * must spin-up each Port after this reset has completed. See for
 * details.  The SATA block clears this bit when the reset action is done. A
 * software write of 0 has no effect.
 */

#define BP_SATA_GHC_HR      0
#define BM_SATA_GHC_HR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GHC_HR(v)   ((((reg32_t) v) << 0) & BM_SATA_GHC_HR)
#else
#define BF_SATA_GHC_HR(v)   (((v) << 0) & BM_SATA_GHC_HR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GHC_HR(v)   BF_CS1(SATA_GHC, HR, v)
#endif

/* --- Register HW_SATA_GHC, field IE
 *
 * Interrupt Enable.  This global bit enables interrupts from the SATA block. When cleared,
 * all interrupt sources from all the Ports are disabled (masked). When
 * set, interrupts are enabled and any SATA block interrupt event
 * causes intrq output assertion.  This field is reset on Global reset (SATA_GHC[HR]=1).
 */

#define BP_SATA_GHC_IE      1
#define BM_SATA_GHC_IE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GHC_IE(v)   ((((reg32_t) v) << 1) & BM_SATA_GHC_IE)
#else
#define BF_SATA_GHC_IE(v)   (((v) << 1) & BM_SATA_GHC_IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GHC_IE(v)   BF_CS1(SATA_GHC, IE, v)
#endif

/* --- Register HW_SATA_GHC, field AE
 *
 * AHCI Enable.  This bit is always set since SATA block supports only AHCI mode as
 * indicated by the SATA_CAP[SAM]=1.
 */

#define BP_SATA_GHC_AE      31
#define BM_SATA_GHC_AE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GHC_AE(v)   ((((reg32_t) v) << 31) & BM_SATA_GHC_AE)
#else
#define BF_SATA_GHC_AE(v)   (((v) << 31) & BM_SATA_GHC_AE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GHC_AE(v)   BF_CS1(SATA_GHC, AE, v)
#endif

/*!
 * @brief HW_SATA_IS - Interrupt Status Register
 *
 * This register indicates which of the Ports within the SATA block have an
 * interrupt pending and require service. This register is reset on Global
 * reset (SATA_GHC[HR]=1).   Size: 32 bits  Address offset: 0x08  Read/write access: Read/Write One
 * to Clear  Reset: 0x0000_00000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPS : 2; //!< Interrupt Pending Status.  np-1-0  np = AHSATA_NUM_PORTS.  When bit 1is set, this bit indicates that the corresponding Port 0 has an interrupt pending. Software can use this information to determine which Ports require service after an interrupt.    The bits of this field are set by the Ports that have interrupt events pending in the P#IS bits and enabled by the P#IE (see "Interrupts" on page 73). Set bits are cleared by the software writing 1 to all bits to clear. This bit is set when the Port has an interrupt event pending and the interrupt source is enabled (see the definition of the SATA_P #  0 IE register). Bit 0 of the IPS field is not used.
        unsigned RESERVED0 : 30; //!< Reserved.  31- np +1   np = AHSATA_NUM_PORTS
    } B;
} hw_sata_is_t;
#endif

/*
 * constants & macros for entire SATA_IS register
 */
#define HW_SATA_IS_ADDR      (REGS_SATA_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_IS           (*(volatile hw_sata_is_t *) HW_SATA_IS_ADDR)
#define HW_SATA_IS_RD()      (HW_SATA_IS.U)
#define HW_SATA_IS_WR(v)     (HW_SATA_IS.U = (v))
#define HW_SATA_IS_SET(v)    (HW_SATA_IS_WR(HW_SATA_IS_RD() |  (v)))
#define HW_SATA_IS_CLR(v)    (HW_SATA_IS_WR(HW_SATA_IS_RD() & ~(v)))
#define HW_SATA_IS_TOG(v)    (HW_SATA_IS_WR(HW_SATA_IS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_IS bitfields
 */

/* --- Register HW_SATA_IS, field IPS
 *
 * Interrupt Pending Status.  np-1-0  np = AHSATA_NUM_PORTS.  When bit 1is set, this bit indicates
 * that the corresponding Port 0 has an interrupt pending. Software can use this information to
 * determine which Ports require service after an                                 interrupt.    The
 * bits of this field are set by the Ports                                     that have interrupt
 * events pending in the P#IS bits and enabled                                     by the P#IE (see
 * "Interrupts" on page 73). Set bits are cleared                                     by the
 * software writing 1 to all bits to clear. This bit is                                 set when the
 * Port has an interrupt event pending and the interrupt                                 source is
 * enabled (see the definition of the SATA_P #  0 IE                                 register). Bit
 * 0 of the IPS field is not used.
 */

#define BP_SATA_IS_IPS      0
#define BM_SATA_IS_IPS      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SATA_IS_IPS(v)   ((((reg32_t) v) << 0) & BM_SATA_IS_IPS)
#else
#define BF_SATA_IS_IPS(v)   (((v) << 0) & BM_SATA_IS_IPS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_IS_IPS(v)   BF_CS1(SATA_IS, IPS, v)
#endif

/*!
 * @brief HW_SATA_PI - Ports Implemented Register
 *
 * This register indicates which Ports are exposed by the SATA block and are
 * available for the software to use. It is loaded by the BIOS. For
 * example, when the SATA block supports 8 Ports as indicated in the
 * SATA_CAP[NP], only Ports 1, 3, 5, and 7 could be available, while Ports
 * 0, 2, 4, and 6 being unavailable.  The contents of this register are relevant to the
 * SATA_CCC_PORTS                             (Command Completion Coalescing Ports) register.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PI : 1; //!< Ports Implemented.  BIOS must set this bit to 1  np-1-0.  np = AHSATA_NUM_PORTS.  This register is bit significant.  The maximum number of bits that can be set to 1 is CAP.NP+1. At least one bit must be set to 1.
        unsigned RESERVED0 : 31; //!< Reserved.  31-1np   np = AHSATA_NUM_PORTS.
    } B;
} hw_sata_pi_t;
#endif

/*
 * constants & macros for entire SATA_PI register
 */
#define HW_SATA_PI_ADDR      (REGS_SATA_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_PI           (*(volatile hw_sata_pi_t *) HW_SATA_PI_ADDR)
#define HW_SATA_PI_RD()      (HW_SATA_PI.U)
#define HW_SATA_PI_WR(v)     (HW_SATA_PI.U = (v))
#define HW_SATA_PI_SET(v)    (HW_SATA_PI_WR(HW_SATA_PI_RD() |  (v)))
#define HW_SATA_PI_CLR(v)    (HW_SATA_PI_WR(HW_SATA_PI_RD() & ~(v)))
#define HW_SATA_PI_TOG(v)    (HW_SATA_PI_WR(HW_SATA_PI_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_PI bitfields
 */

/* --- Register HW_SATA_PI, field PI
 *
 * Ports Implemented.  BIOS must set this bit to 1  np-1-0.  np = AHSATA_NUM_PORTS.  This register
 * is bit significant.  The maximum number of bits that can be set to 1 is
 * CAP.NP+1. At least one bit must be set to 1.
 */

#define BP_SATA_PI_PI      0
#define BM_SATA_PI_PI      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PI_PI(v)   ((((reg32_t) v) << 0) & BM_SATA_PI_PI)
#else
#define BF_SATA_PI_PI(v)   (((v) << 0) & BM_SATA_PI_PI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PI_PI(v)   BF_CS1(SATA_PI, PI, v)
#endif

/*!
 * @brief HW_SATA_VS - AHCl Version Register
 *
 * This register indicates the major and minor version of the AHCI
 * specification that the SATA block implementation supports. The SATA
 * block supports version 1.30.  The SATA block core currently complies fully with AHCI version 1.10
 * ,                             and complies with AHCI version 1.3, except with respect to FIS-
 * based                             switching. FIS-based switching is not currently supported.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MNR : 16; //!< Minor Version Number.  Indicates that the minor AHCI version is 30.
        unsigned MJR : 16; //!< Major Version Number.  Indicates that the major AHCI version is 1.
    } B;
} hw_sata_vs_t;
#endif

/*
 * constants & macros for entire SATA_VS register
 */
#define HW_SATA_VS_ADDR      (REGS_SATA_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_VS           (*(volatile hw_sata_vs_t *) HW_SATA_VS_ADDR)
#define HW_SATA_VS_RD()      (HW_SATA_VS.U)
#define HW_SATA_VS_WR(v)     (HW_SATA_VS.U = (v))
#define HW_SATA_VS_SET(v)    (HW_SATA_VS_WR(HW_SATA_VS_RD() |  (v)))
#define HW_SATA_VS_CLR(v)    (HW_SATA_VS_WR(HW_SATA_VS_RD() & ~(v)))
#define HW_SATA_VS_TOG(v)    (HW_SATA_VS_WR(HW_SATA_VS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_VS bitfields
 */

/* --- Register HW_SATA_VS, field MNR
 *
 * Minor Version Number.  Indicates that the minor AHCI version is 30.
 */

#define BP_SATA_VS_MNR      0
#define BM_SATA_VS_MNR      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_VS_MNR(v)   ((((reg32_t) v) << 0) & BM_SATA_VS_MNR)
#else
#define BF_SATA_VS_MNR(v)   (((v) << 0) & BM_SATA_VS_MNR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_VS_MNR(v)   BF_CS1(SATA_VS, MNR, v)
#endif

/* --- Register HW_SATA_VS, field MJR
 *
 * Major Version Number.  Indicates that the major AHCI version is 1.
 */

#define BP_SATA_VS_MJR      16
#define BM_SATA_VS_MJR      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_VS_MJR(v)   ((((reg32_t) v) << 16) & BM_SATA_VS_MJR)
#else
#define BF_SATA_VS_MJR(v)   (((v) << 16) & BM_SATA_VS_MJR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_VS_MJR(v)   BF_CS1(SATA_VS, MJR, v)
#endif

/*!
 * @brief HW_SATA_CCC_CTL - Command Completion Coalescing Control
 *
 * This register is used to configure the command completion coalescing
 * (CCC) feature for the SATA block core. It is reset on Global reset.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EN : 1; //!< Enable.  When field SATA_CCC_CTL[EN]==1, the software can not change the fields SATA_CCC_CTL[TV] and SATA_CCC_CTL[CC].  The options for this field are:
        unsigned RESERVED0 : 2; //!< Reserved.
        unsigned INT : 5; //!< Interrupt.  Set this field to 0x01.  This field specifies the interrupt used by the CCC feature, using the number of Ports configured for the core. For example, when AHSATA_NUM_PORTS==6  then  This field SATA_CCC_CTL.INT==6.  When a CCC interrupt occurs, the field SATA_IS.IPS[INT] is set to 1.   Reset Value: Configurable: AHSATA_NUM_PORTS.
        unsigned CC : 8; //!< Command Completions.  This field specifies the number of command completions that are necessary to cause a CCC interrupt.  The value 0x00 for this field disables CCC interrupts being generated based on the number of commands completed. In this case, CCC interrupts are only generated based on the timer.  Software loads this value prior to enabling CCC: Field access is:  • RW when SATA_CCC_CTL[EN]==0  • RO when SATA_CCC_CTL[EN]==1
        unsigned TV : 16; //!< Time-out Value.  This field specifies the CCC time-out value in 1ms intervals. The software loads this value prior to enabling CCC.  The options for this field are:  • RW when SATA_CCC_CTL[EN]==0.  • RO when SATA_CCC_CTL[EN]==1.  A time-out value of 0x0000 is reserved and should not be used.
    } B;
} hw_sata_ccc_ctl_t;
#endif

/*
 * constants & macros for entire SATA_CCC_CTL register
 */
#define HW_SATA_CCC_CTL_ADDR      (REGS_SATA_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_CCC_CTL           (*(volatile hw_sata_ccc_ctl_t *) HW_SATA_CCC_CTL_ADDR)
#define HW_SATA_CCC_CTL_RD()      (HW_SATA_CCC_CTL.U)
#define HW_SATA_CCC_CTL_WR(v)     (HW_SATA_CCC_CTL.U = (v))
#define HW_SATA_CCC_CTL_SET(v)    (HW_SATA_CCC_CTL_WR(HW_SATA_CCC_CTL_RD() |  (v)))
#define HW_SATA_CCC_CTL_CLR(v)    (HW_SATA_CCC_CTL_WR(HW_SATA_CCC_CTL_RD() & ~(v)))
#define HW_SATA_CCC_CTL_TOG(v)    (HW_SATA_CCC_CTL_WR(HW_SATA_CCC_CTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_CCC_CTL bitfields
 */

/* --- Register HW_SATA_CCC_CTL, field EN
 *
 * Enable.  When field SATA_CCC_CTL[EN]==1, the software can not change the
 * fields SATA_CCC_CTL[TV] and SATA_CCC_CTL[CC].  The options for this field are:
 */

#define BP_SATA_CCC_CTL_EN      0
#define BM_SATA_CCC_CTL_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CCC_CTL_EN(v)   ((((reg32_t) v) << 0) & BM_SATA_CCC_CTL_EN)
#else
#define BF_SATA_CCC_CTL_EN(v)   (((v) << 0) & BM_SATA_CCC_CTL_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CCC_CTL_EN(v)   BF_CS1(SATA_CCC_CTL, EN, v)
#endif

/* --- Register HW_SATA_CCC_CTL, field INT
 *
 * Interrupt.  Set this field to 0x01.  This field specifies the interrupt used by the CCC
 * feature, using the number of Ports configured for the core. For
 * example, when AHSATA_NUM_PORTS==6  then  This field SATA_CCC_CTL.INT==6.  When a CCC interrupt
 * occurs, the field                                 SATA_IS.IPS[INT] is set to 1.   Reset Value:
 * Configurable:                                     AHSATA_NUM_PORTS.
 */

#define BP_SATA_CCC_CTL_INT      3
#define BM_SATA_CCC_CTL_INT      0x000000f8

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CCC_CTL_INT(v)   ((((reg32_t) v) << 3) & BM_SATA_CCC_CTL_INT)
#else
#define BF_SATA_CCC_CTL_INT(v)   (((v) << 3) & BM_SATA_CCC_CTL_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CCC_CTL_INT(v)   BF_CS1(SATA_CCC_CTL, INT, v)
#endif

/* --- Register HW_SATA_CCC_CTL, field CC
 *
 * Command Completions.  This field specifies the number of command completions that are
 * necessary to cause a CCC interrupt.  The value 0x00 for this field disables CCC interrupts being
 * generated                                 based on the number of commands completed. In this
 * case, CCC                                 interrupts are only generated based on the timer.
 * Software loads this value prior to enabling CCC: Field access is:  • RW when SATA_CCC_CTL[EN]==0
 * • RO when SATA_CCC_CTL[EN]==1
 */

#define BP_SATA_CCC_CTL_CC      8
#define BM_SATA_CCC_CTL_CC      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CCC_CTL_CC(v)   ((((reg32_t) v) << 8) & BM_SATA_CCC_CTL_CC)
#else
#define BF_SATA_CCC_CTL_CC(v)   (((v) << 8) & BM_SATA_CCC_CTL_CC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CCC_CTL_CC(v)   BF_CS1(SATA_CCC_CTL, CC, v)
#endif

/* --- Register HW_SATA_CCC_CTL, field TV
 *
 * Time-out Value.  This field specifies the CCC time-out value in 1ms intervals. The
 * software loads this value prior to enabling CCC.  The options for this field are:  • RW when
 * SATA_CCC_CTL[EN]==0.  • RO when SATA_CCC_CTL[EN]==1.  A time-out value of 0x0000 is reserved and
 * should not be used.
 */

#define BP_SATA_CCC_CTL_TV      16
#define BM_SATA_CCC_CTL_TV      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CCC_CTL_TV(v)   ((((reg32_t) v) << 16) & BM_SATA_CCC_CTL_TV)
#else
#define BF_SATA_CCC_CTL_TV(v)   (((v) << 16) & BM_SATA_CCC_CTL_TV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CCC_CTL_TV(v)   BF_CS1(SATA_CCC_CTL, TV, v)
#endif

/*!
 * @brief HW_SATA_CCC_PORTS - Command Completion Coalescing Ports
 *
 * This register specifies the Ports that are coalesced as part of the
 * command completion coalescing (CCC) feature when SATA_CCC_CTL[EN]==1. It
 * is reset on Global reset.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PRT : 32; //!< Ports.  This field is bit significant. Each bit corresponds to a particular Port, where bit 0 corresponds to Port0.  Bits set in this register must have the corresponding bit set in the SATA_PI (Ports Implemented Register).  The options for this field are:
    } B;
} hw_sata_ccc_ports_t;
#endif

/*
 * constants & macros for entire SATA_CCC_PORTS register
 */
#define HW_SATA_CCC_PORTS_ADDR      (REGS_SATA_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_CCC_PORTS           (*(volatile hw_sata_ccc_ports_t *) HW_SATA_CCC_PORTS_ADDR)
#define HW_SATA_CCC_PORTS_RD()      (HW_SATA_CCC_PORTS.U)
#define HW_SATA_CCC_PORTS_WR(v)     (HW_SATA_CCC_PORTS.U = (v))
#define HW_SATA_CCC_PORTS_SET(v)    (HW_SATA_CCC_PORTS_WR(HW_SATA_CCC_PORTS_RD() |  (v)))
#define HW_SATA_CCC_PORTS_CLR(v)    (HW_SATA_CCC_PORTS_WR(HW_SATA_CCC_PORTS_RD() & ~(v)))
#define HW_SATA_CCC_PORTS_TOG(v)    (HW_SATA_CCC_PORTS_WR(HW_SATA_CCC_PORTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_CCC_PORTS bitfields
 */

/* --- Register HW_SATA_CCC_PORTS, field PRT
 *
 * Ports.  This field is bit significant. Each bit corresponds to a particular
 * Port, where bit 0 corresponds to Port0.  Bits set in this register must have the corresponding
 * bit set in the                                 SATA_PI (Ports Implemented Register).  The options
 * for this field are:
 */

#define BP_SATA_CCC_PORTS_PRT      0
#define BM_SATA_CCC_PORTS_PRT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CCC_PORTS_PRT(v)   ((((reg32_t) v) << 0) & BM_SATA_CCC_PORTS_PRT)
#else
#define BF_SATA_CCC_PORTS_PRT(v)   (((v) << 0) & BM_SATA_CCC_PORTS_PRT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CCC_PORTS_PRT(v)   BF_CS1(SATA_CCC_PORTS, PRT, v)
#endif

/*!
 * @brief HW_SATA_CAP2 - HBA Capabilities Extended Register
 *
 * This register indicates capabilites of the SATA block core to the
 * software.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved.
        unsigned APST : 1; //!< Automatic Partial to Slumber Transitions.  SATA block supports automatic Partial to Slumber transitions.
        unsigned RESERVED1 : 29; //!< Reserved
    } B;
} hw_sata_cap2_t;
#endif

/*
 * constants & macros for entire SATA_CAP2 register
 */
#define HW_SATA_CAP2_ADDR      (REGS_SATA_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_CAP2           (*(volatile hw_sata_cap2_t *) HW_SATA_CAP2_ADDR)
#define HW_SATA_CAP2_RD()      (HW_SATA_CAP2.U)
#define HW_SATA_CAP2_WR(v)     (HW_SATA_CAP2.U = (v))
#define HW_SATA_CAP2_SET(v)    (HW_SATA_CAP2_WR(HW_SATA_CAP2_RD() |  (v)))
#define HW_SATA_CAP2_CLR(v)    (HW_SATA_CAP2_WR(HW_SATA_CAP2_RD() & ~(v)))
#define HW_SATA_CAP2_TOG(v)    (HW_SATA_CAP2_WR(HW_SATA_CAP2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_CAP2 bitfields
 */

/* --- Register HW_SATA_CAP2, field APST
 *
 * Automatic Partial to Slumber Transitions.  SATA block supports automatic Partial to Slumber
 * transitions.
 */

#define BP_SATA_CAP2_APST      2
#define BM_SATA_CAP2_APST      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SATA_CAP2_APST(v)   ((((reg32_t) v) << 2) & BM_SATA_CAP2_APST)
#else
#define BF_SATA_CAP2_APST(v)   (((v) << 2) & BM_SATA_CAP2_APST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_CAP2_APST(v)   BF_CS1(SATA_CAP2, APST, v)
#endif

/*!
 * @brief HW_SATA_BISTAFR - BIST Activate FIS Register
 *
 * This register contains the pattern definition (bits [23:16] of the first
 * DWORD) and data pattern (bits [7:0] of the second DWORD) fields of the
 * received BIST Activate FIS. These fields define the SATA block loopback
 * responder mode requested by the device. It is updated every time a new
 * BIST Activate FIS is received from the device. Reset on Global or Port
 * reset.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PD : 8; //!< Pattern Definition  Indicates the pattern definition field of the received BIST Activate FIS - bits [23:16] of the first DWORD. It is used to put the SATA block in one of the following BIST modes:  For far-end transmit only modes SATA_BISTAFR[NCP] field contains the required data pattern.
        unsigned NCP : 8; //!< Least significant byte of the received BIST Activate FIS second DWORD (bits [7:0]). This value defines the required pattern for far-end transmit only mode (SATA_BISTAFR[PD]=0x80 or 0xA0):  When none of these values is decoded, the simultaneous switching pattern is transmitted by default.
        unsigned RESERVED0 : 16; //!< Reserved.
    } B;
} hw_sata_bistafr_t;
#endif

/*
 * constants & macros for entire SATA_BISTAFR register
 */
#define HW_SATA_BISTAFR_ADDR      (REGS_SATA_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_BISTAFR           (*(volatile hw_sata_bistafr_t *) HW_SATA_BISTAFR_ADDR)
#define HW_SATA_BISTAFR_RD()      (HW_SATA_BISTAFR.U)
#define HW_SATA_BISTAFR_WR(v)     (HW_SATA_BISTAFR.U = (v))
#define HW_SATA_BISTAFR_SET(v)    (HW_SATA_BISTAFR_WR(HW_SATA_BISTAFR_RD() |  (v)))
#define HW_SATA_BISTAFR_CLR(v)    (HW_SATA_BISTAFR_WR(HW_SATA_BISTAFR_RD() & ~(v)))
#define HW_SATA_BISTAFR_TOG(v)    (HW_SATA_BISTAFR_WR(HW_SATA_BISTAFR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_BISTAFR bitfields
 */

/* --- Register HW_SATA_BISTAFR, field PD
 *
 * Pattern Definition  Indicates the pattern definition field of the received BIST Activate
 * FIS - bits [23:16] of the first DWORD. It is used to put the SATA
 * block in one of the following BIST modes:  For far-end transmit only modes SATA_BISTAFR[NCP]
 * field contains the                                 required data pattern.
 */

#define BP_SATA_BISTAFR_PD      0
#define BM_SATA_BISTAFR_PD      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTAFR_PD(v)   ((((reg32_t) v) << 0) & BM_SATA_BISTAFR_PD)
#else
#define BF_SATA_BISTAFR_PD(v)   (((v) << 0) & BM_SATA_BISTAFR_PD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTAFR_PD(v)   BF_CS1(SATA_BISTAFR, PD, v)
#endif

/* --- Register HW_SATA_BISTAFR, field NCP
 *
 * Least significant byte of the received BIST Activate FIS second DWORD
 * (bits [7:0]). This value defines the required pattern for far-end
 * transmit only mode (SATA_BISTAFR[PD]=0x80 or 0xA0):  When none of these values is decoded, the
 * simultaneous switching                                 pattern is transmitted by default.
 */

#define BP_SATA_BISTAFR_NCP      8
#define BM_SATA_BISTAFR_NCP      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTAFR_NCP(v)   ((((reg32_t) v) << 8) & BM_SATA_BISTAFR_NCP)
#else
#define BF_SATA_BISTAFR_NCP(v)   (((v) << 8) & BM_SATA_BISTAFR_NCP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTAFR_NCP(v)   BF_CS1(SATA_BISTAFR, NCP, v)
#endif

/*!
 * @brief HW_SATA_BISTCR - BIST Control Register
 *
 * This register is used in BIST initiator modes. It is loaded by the host
 * software prior to sending BIST Activate FIS to the device (via TXBISTPD
 * write). It is reset on a Global or Port reset.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PATTERN : 4; //!< This field defines one of the following SATA compliant patterns for far-end retimed/ far-end analog/ near-end analog initiator modes, or non-compliant patterns for transmit-only responder mode when initiated by the software writing to the SATA_BISTCR[TXO] bit.  If the value is none of the listed below, Composite pattern (COMP) is transmitted by default.
        unsigned PV : 1; //!< Pattern Version  This bit is used to select either short or long version of the SSOP, HTDP, LTDP, LFSCP, COMP patterns.  The options for this field are:
        unsigned FLIP : 1; //!< Flip Disparity  This bit is used to change disparity of the current test pattern to the opposite every time its state is changed by the software.
        unsigned ERREN : 1; //!< Error Enable.  This bit is used to allow or filter (disable) [ internal errors outside the FIS  boundary to set corresponding SATA_P #  0 SERR bits.  The options for this field are:
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned LLC : 3; //!< Link Layer Control  This field controls the Port Link Layer functions: scrambler, descrambler, and repeat primitive drop. Note the different meanings for normal and BIST modes of operation:  • Bit8-SCRAM  The options for this field are:  0 Scrambler disabled in normal mode, enabled in BIST mode  1 Scrambler enabled in normal mode, disabled in BIST mode  • Bit9-DESCRAM  The options for this field are:  0 Descrambler disabled in normal mode, enabled in BIST mode  1 Descrambler enabled in normal mode, disabled in BIST mode  • Bit10-RPD  The options for this field are:  0 Repeat primitive drop function disabled in normal mode, NA in BIST  mode.  1 Repeat primitive drop function enabled in normal mode, NA in BIST  mode.  The SCRAM bit is cleared (enabled) by the Port when the Port enters a responder far-end transmit BIST mode with scrambling enabled (SATA_BISTAFR[PD]=0x80).  In normal mode, the functions scrambler, descrambler, or RPD can be changed only during Port reset (SATA_P #  0 SCTL[DET]=0x1)
        unsigned RESERVED1 : 1; //!< Reserved.
        unsigned SDFE : 1; //!< Signal Detect Feature Enable  Reset: PHY_INTERFACE_TYPE 1: Link layer feature to handle unstable/absent phy_sig_det signal is enabled 0: Link layer feature to handle unstable/absent phy_sig_det signal is disabled. This bit is set on power-up or asynchronous reset if PHY_INTERFACE_TYPE = Synopsys_SATA_II (1) or PHY_INTERFACE_TYPE = Synopsys_SATA_6G (2), otherwise, the bit is cleared until it is set via programming. It is not affected by a Global reset or COMRESET.  For special handling in systems where phy_sig_det may not be present or stable after OOB signalling and during normal operation , see . For these systems, phy_rx_data_vld must not be tied high and must go low when no data is detected on the wires.
        unsigned RESERVED2 : 1; //!< Reserved.
        unsigned QPHYINIT : 1; //!< When set, this bit enables quick PHY initialization feature. The Link does not require any ALIGNs to transition from OOB to normal operation. For more details, see   This bit is available only when TX_OOB_MODE = Exclude (0) and ALIGN_MODE = Aligned (1), otherwise it is reserved.
        unsigned RESERVED3 : 1; //!< Reserved.
        unsigned NEALB : 1; //!< Near-End Analog Loopback  This mode should be initiated either in the PARTIAL or SLUMBER power mode, or with the device disconnected from the Port PHY (Link NOCOMM state).  BIST Activate FIS is not sent to the device in this mode.  This bit places the Port PHY into near-end analog loopback mode. This field is one-shot type and reads returns 0:
        unsigned CNTCLR : 1; //!< Counter Clear  This bit clears BIST error count registers. This field is one-shot type and reads returns 0.
        unsigned TXO : 1; //!< Transmit Only.  This bit is used to initiate transmission of one of the non-compliant patterns defined by the SATA_BISTCR[PATTERN] value when the device is disconnected.
        unsigned RESERVED4 : 1; //!< Reserved.
        unsigned FERLB : 1; //!< Far-end Retimed Loopback.  When set, this bit is used to put the SATA block Link into Far-end Retimed mode, without the BIST Activate FIS, regardless whether the device is connected or disconnected (Link in NOCOMM state). This field is one-shot type and reads returns 0.
        unsigned RESERVED5 : 11; //!< Reserved.
    } B;
} hw_sata_bistcr_t;
#endif

/*
 * constants & macros for entire SATA_BISTCR register
 */
#define HW_SATA_BISTCR_ADDR      (REGS_SATA_BASE + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_BISTCR           (*(volatile hw_sata_bistcr_t *) HW_SATA_BISTCR_ADDR)
#define HW_SATA_BISTCR_RD()      (HW_SATA_BISTCR.U)
#define HW_SATA_BISTCR_WR(v)     (HW_SATA_BISTCR.U = (v))
#define HW_SATA_BISTCR_SET(v)    (HW_SATA_BISTCR_WR(HW_SATA_BISTCR_RD() |  (v)))
#define HW_SATA_BISTCR_CLR(v)    (HW_SATA_BISTCR_WR(HW_SATA_BISTCR_RD() & ~(v)))
#define HW_SATA_BISTCR_TOG(v)    (HW_SATA_BISTCR_WR(HW_SATA_BISTCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_BISTCR bitfields
 */

/* --- Register HW_SATA_BISTCR, field PATTERN
 *
 * This field defines one of the following SATA compliant patterns for
 * far-end retimed/ far-end analog/ near-end analog initiator modes, or
 * non-compliant patterns for transmit-only responder mode when
 * initiated by the software writing to the SATA_BISTCR[TXO] bit.  If the value is none of the
 * listed below, Composite pattern (COMP) is                             transmitted by default.
 */

#define BP_SATA_BISTCR_PATTERN      0
#define BM_SATA_BISTCR_PATTERN      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_PATTERN(v)   ((((reg32_t) v) << 0) & BM_SATA_BISTCR_PATTERN)
#else
#define BF_SATA_BISTCR_PATTERN(v)   (((v) << 0) & BM_SATA_BISTCR_PATTERN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_PATTERN(v)   BF_CS1(SATA_BISTCR, PATTERN, v)
#endif

/* --- Register HW_SATA_BISTCR, field PV
 *
 * Pattern Version  This bit is used to select either short or long version of the SSOP,
 * HTDP, LTDP, LFSCP, COMP patterns.  The options for this field are:
 */

#define BP_SATA_BISTCR_PV      4
#define BM_SATA_BISTCR_PV      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_PV(v)   ((((reg32_t) v) << 4) & BM_SATA_BISTCR_PV)
#else
#define BF_SATA_BISTCR_PV(v)   (((v) << 4) & BM_SATA_BISTCR_PV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_PV(v)   BF_CS1(SATA_BISTCR, PV, v)
#endif

/* --- Register HW_SATA_BISTCR, field FLIP
 *
 * Flip Disparity  This bit is used to change disparity of the current test pattern to
 * the opposite every time its state is changed by the software.
 */

#define BP_SATA_BISTCR_FLIP      5
#define BM_SATA_BISTCR_FLIP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_FLIP(v)   ((((reg32_t) v) << 5) & BM_SATA_BISTCR_FLIP)
#else
#define BF_SATA_BISTCR_FLIP(v)   (((v) << 5) & BM_SATA_BISTCR_FLIP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_FLIP(v)   BF_CS1(SATA_BISTCR, FLIP, v)
#endif

/* --- Register HW_SATA_BISTCR, field ERREN
 *
 * Error Enable.  This bit is used to allow or filter (disable) [ internal errors
 * outside the FIS  boundary to set corresponding SATA_P #  0 SERR bits.  The options for this field
 * are:
 */

#define BP_SATA_BISTCR_ERREN      6
#define BM_SATA_BISTCR_ERREN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_ERREN(v)   ((((reg32_t) v) << 6) & BM_SATA_BISTCR_ERREN)
#else
#define BF_SATA_BISTCR_ERREN(v)   (((v) << 6) & BM_SATA_BISTCR_ERREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_ERREN(v)   BF_CS1(SATA_BISTCR, ERREN, v)
#endif

/* --- Register HW_SATA_BISTCR, field LLC
 *
 * Link Layer Control  This field controls the Port Link Layer functions: scrambler,
 * descrambler, and repeat primitive drop. Note the different meanings
 * for normal and BIST modes of operation:  • Bit8-SCRAM  The options for this field are:  0
 * Scrambler disabled in normal mode, enabled in BIST mode  1 Scrambler enabled in normal mode,
 * disabled in BIST mode  • Bit9-DESCRAM  The options for this field are:  0 Descrambler disabled in
 * normal mode, enabled in BIST mode  1 Descrambler enabled in normal mode, disabled in BIST mode  •
 * Bit10-RPD  The options for this field are:  0 Repeat primitive drop function disabled in normal
 * mode, NA in                                 BIST  mode.  1 Repeat primitive drop function enabled
 * in normal mode, NA in                                 BIST  mode.  The SCRAM bit is cleared
 * (enabled) by the Port when the Port enters a                                 responder far-end
 * transmit BIST mode with scrambling enabled
 * (SATA_BISTAFR[PD]=0x80).  In normal mode, the functions scrambler, descrambler, or RPD can be
 * changed only during Port reset (SATA_P #  0 SCTL[DET]=0x1)
 */

#define BP_SATA_BISTCR_LLC      8
#define BM_SATA_BISTCR_LLC      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_LLC(v)   ((((reg32_t) v) << 8) & BM_SATA_BISTCR_LLC)
#else
#define BF_SATA_BISTCR_LLC(v)   (((v) << 8) & BM_SATA_BISTCR_LLC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_LLC(v)   BF_CS1(SATA_BISTCR, LLC, v)
#endif

/* --- Register HW_SATA_BISTCR, field SDFE
 *
 * Signal Detect Feature Enable  Reset: PHY_INTERFACE_TYPE                 1: Link layer feature to
 * handle unstable/absent phy_sig_det signal is enabled                 0: Link layer feature to
 * handle unstable/absent phy_sig_det signal is disabled.                 This bit is set on power-
 * up or asynchronous reset if PHY_INTERFACE_TYPE = Synopsys_SATA_II (1) or PHY_INTERFACE_TYPE =
 * Synopsys_SATA_6G (2), otherwise, the bit is cleared until it is set via programming. It is not
 * affected by a Global reset or COMRESET.  For special handling in systems where phy_sig_det may
 * not be present or stable after                  OOB signalling and during normal operation , see
 * . For these systems, phy_rx_data_vld must not be tied high and must go low when no data is
 * detected on the wires.
 */

#define BP_SATA_BISTCR_SDFE      12
#define BM_SATA_BISTCR_SDFE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_SDFE(v)   ((((reg32_t) v) << 12) & BM_SATA_BISTCR_SDFE)
#else
#define BF_SATA_BISTCR_SDFE(v)   (((v) << 12) & BM_SATA_BISTCR_SDFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_SDFE(v)   BF_CS1(SATA_BISTCR, SDFE, v)
#endif

/* --- Register HW_SATA_BISTCR, field QPHYINIT
 *
 * When set, this bit enables quick PHY initialization feature.                  The Link does not
 * require any ALIGNs to transition from OOB to                  normal operation. For more details,
 * see   This bit is available only when TX_OOB_MODE = Exclude (0) and                 ALIGN_MODE =
 * Aligned (1), otherwise it is reserved.
 */

#define BP_SATA_BISTCR_QPHYINIT      14
#define BM_SATA_BISTCR_QPHYINIT      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_QPHYINIT(v)   ((((reg32_t) v) << 14) & BM_SATA_BISTCR_QPHYINIT)
#else
#define BF_SATA_BISTCR_QPHYINIT(v)   (((v) << 14) & BM_SATA_BISTCR_QPHYINIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_QPHYINIT(v)   BF_CS1(SATA_BISTCR, QPHYINIT, v)
#endif

/* --- Register HW_SATA_BISTCR, field NEALB
 *
 * Near-End Analog Loopback  This mode should be initiated either in the PARTIAL or SLUMBER power
 * mode, or with the device disconnected from the Port PHY (Link NOCOMM
 * state).  BIST Activate FIS is not sent to the device in this mode.  This bit places the Port PHY
 * into near-end analog loopback mode. This                                 field is one-shot type
 * and reads returns 0:
 */

#define BP_SATA_BISTCR_NEALB      16
#define BM_SATA_BISTCR_NEALB      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_NEALB(v)   ((((reg32_t) v) << 16) & BM_SATA_BISTCR_NEALB)
#else
#define BF_SATA_BISTCR_NEALB(v)   (((v) << 16) & BM_SATA_BISTCR_NEALB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_NEALB(v)   BF_CS1(SATA_BISTCR, NEALB, v)
#endif

/* --- Register HW_SATA_BISTCR, field CNTCLR
 *
 * Counter Clear  This bit clears BIST error count registers. This field is one-shot
 * type and reads returns 0.
 */

#define BP_SATA_BISTCR_CNTCLR      17
#define BM_SATA_BISTCR_CNTCLR      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_CNTCLR(v)   ((((reg32_t) v) << 17) & BM_SATA_BISTCR_CNTCLR)
#else
#define BF_SATA_BISTCR_CNTCLR(v)   (((v) << 17) & BM_SATA_BISTCR_CNTCLR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_CNTCLR(v)   BF_CS1(SATA_BISTCR, CNTCLR, v)
#endif

/* --- Register HW_SATA_BISTCR, field TXO
 *
 * Transmit Only.  This bit is used to initiate transmission of one of the non-compliant
 * patterns defined by the SATA_BISTCR[PATTERN] value when the device
 * is disconnected.
 */

#define BP_SATA_BISTCR_TXO      18
#define BM_SATA_BISTCR_TXO      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_TXO(v)   ((((reg32_t) v) << 18) & BM_SATA_BISTCR_TXO)
#else
#define BF_SATA_BISTCR_TXO(v)   (((v) << 18) & BM_SATA_BISTCR_TXO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_TXO(v)   BF_CS1(SATA_BISTCR, TXO, v)
#endif

/* --- Register HW_SATA_BISTCR, field FERLB
 *
 * Far-end Retimed Loopback.  When set, this bit is used to put the SATA block Link into Far-end
 * Retimed mode, without the BIST Activate FIS, regardless whether the
 * device is connected or disconnected (Link in NOCOMM state). This
 * field is one-shot type and reads returns 0.
 */

#define BP_SATA_BISTCR_FERLB      20
#define BM_SATA_BISTCR_FERLB      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTCR_FERLB(v)   ((((reg32_t) v) << 20) & BM_SATA_BISTCR_FERLB)
#else
#define BF_SATA_BISTCR_FERLB(v)   (((v) << 20) & BM_SATA_BISTCR_FERLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTCR_FERLB(v)   BF_CS1(SATA_BISTCR, FERLB, v)
#endif

/*!
 * @brief HW_SATA_BISTFCTR - BIST FIS Count Register
 *
 * This register contains the received BIST FIS count in the loopback
 * initiator far-end retimed, far-end analog and near-end analog modes. It
 * is updated each time a new BIST FIS is received. It is reset by Global
 * reset, Port reset (COMRESET) or by setting the SATA_BISTCR[CNTCLR] bit.
 * This register does not roll over and freezes when the FFFF_FFFFh value
 * is reached. It takes approximately 65 hours of continuous BIST operation
 * to reach this value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Received BIST FIS Count
    } B;
} hw_sata_bistfctr_t;
#endif

/*
 * constants & macros for entire SATA_BISTFCTR register
 */
#define HW_SATA_BISTFCTR_ADDR      (REGS_SATA_BASE + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_BISTFCTR           (*(volatile hw_sata_bistfctr_t *) HW_SATA_BISTFCTR_ADDR)
#define HW_SATA_BISTFCTR_RD()      (HW_SATA_BISTFCTR.U)
#define HW_SATA_BISTFCTR_WR(v)     (HW_SATA_BISTFCTR.U = (v))
#define HW_SATA_BISTFCTR_SET(v)    (HW_SATA_BISTFCTR_WR(HW_SATA_BISTFCTR_RD() |  (v)))
#define HW_SATA_BISTFCTR_CLR(v)    (HW_SATA_BISTFCTR_WR(HW_SATA_BISTFCTR_RD() & ~(v)))
#define HW_SATA_BISTFCTR_TOG(v)    (HW_SATA_BISTFCTR_WR(HW_SATA_BISTFCTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_BISTFCTR bitfields
 */

/*!
 * @brief HW_SATA_BISTSR - BIST Status Register
 *
 * This register contains errors detected in the received BIST FIS in the
 * loopback initiator far-end retimed, far- end analog and near-end analog
 * modes. It is updated each time a new BIST FIS is received. It is reset
 * by Global reset, Port reset (COMRESET) or by setting the
 * SATA_BISTCR[CNTCLR] bit.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FRAMERR : 16; //!< Frame Error.  This field contains the frame error count. It is accumulated (new value is added to the old value) each time a new BIST frame with a CRC error is received. The FRAMERR value does not roll over and freezes at FFFFh.
        unsigned BRSTERR : 8; //!< Burst Error.  This field contains the burst error count. It is accumulated each time a burst error condition is detected: DWORD error is detected in the received frame and 1.5 seconds (27,000 frames) passed since the previous burst error was detected. The BRSTERR value does not roll over and freezes at FFh.  This field is updated when parameter (Macro configuration parm) BIST_MODE=DWORD.
        unsigned RESERVED0 : 8; //!< Reserved.
    } B;
} hw_sata_bistsr_t;
#endif

/*
 * constants & macros for entire SATA_BISTSR register
 */
#define HW_SATA_BISTSR_ADDR      (REGS_SATA_BASE + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_BISTSR           (*(volatile hw_sata_bistsr_t *) HW_SATA_BISTSR_ADDR)
#define HW_SATA_BISTSR_RD()      (HW_SATA_BISTSR.U)
#define HW_SATA_BISTSR_WR(v)     (HW_SATA_BISTSR.U = (v))
#define HW_SATA_BISTSR_SET(v)    (HW_SATA_BISTSR_WR(HW_SATA_BISTSR_RD() |  (v)))
#define HW_SATA_BISTSR_CLR(v)    (HW_SATA_BISTSR_WR(HW_SATA_BISTSR_RD() & ~(v)))
#define HW_SATA_BISTSR_TOG(v)    (HW_SATA_BISTSR_WR(HW_SATA_BISTSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_BISTSR bitfields
 */

/* --- Register HW_SATA_BISTSR, field FRAMERR
 *
 * Frame Error.  This field contains the frame error count. It is accumulated (new
 * value is added to the old value) each time a new BIST frame with a
 * CRC error is received. The FRAMERR value does not roll over and
 * freezes at FFFFh.
 */

#define BP_SATA_BISTSR_FRAMERR      0
#define BM_SATA_BISTSR_FRAMERR      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTSR_FRAMERR(v)   ((((reg32_t) v) << 0) & BM_SATA_BISTSR_FRAMERR)
#else
#define BF_SATA_BISTSR_FRAMERR(v)   (((v) << 0) & BM_SATA_BISTSR_FRAMERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTSR_FRAMERR(v)   BF_CS1(SATA_BISTSR, FRAMERR, v)
#endif

/* --- Register HW_SATA_BISTSR, field BRSTERR
 *
 * Burst Error.  This field contains the burst error count. It is accumulated each
 * time a burst error condition is detected: DWORD error is detected in
 * the received frame and 1.5 seconds (27,000 frames) passed since the
 * previous burst error was detected. The BRSTERR value does not roll
 * over and freezes at FFh.  This field is updated when parameter (Macro configuration parm)
 * BIST_MODE=DWORD.
 */

#define BP_SATA_BISTSR_BRSTERR      16
#define BM_SATA_BISTSR_BRSTERR      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_BISTSR_BRSTERR(v)   ((((reg32_t) v) << 16) & BM_SATA_BISTSR_BRSTERR)
#else
#define BF_SATA_BISTSR_BRSTERR(v)   (((v) << 16) & BM_SATA_BISTSR_BRSTERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_BISTSR_BRSTERR(v)   BF_CS1(SATA_BISTSR, BRSTERR, v)
#endif

/*!
 * @brief HW_SATA_OOBR - OOB Register
 *
 * This register controls the Link layer OOB detection counters. The default
 * values, MIN_COMWAKE, MAX_COMWAKE, MIN_COMINIT and MAX_COMINIT are
 * calculated based on the RXOOB_CLK  RXOOB_CLK_FREQ parameter and loaded on
 * power-up or asynchronous SATA block reset.   The resulting default OOB spacing ranges are
 * shown in Table 3-1. To change these ranges, the new values must be
 * recalculated based on formulas in and and                                 loaded into the link as
 * follows:    Set SATA_OOBR bit 31 to enable other SATA_OOBR fields  Write new values to the
 * corresponding SATA_OOBR fields  Generate PORT Reset (COMRESET)   Dependencies: Present only when
 * RXOOB_CLK_MODE==Include
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CIMAX : 8; //!< COMINIT Maximum Value  This field is RW when WE=1 and RO when WE=0.
        unsigned CIMIN : 8; //!< COMINIT Minimum Value  This field is RW when WE=1 and RO when WE=0.
        unsigned CWMAX : 8; //!< COMWAKE Maximum Value  This field is RW when WE=1 and RO when WE=0.
        unsigned CWMIN : 7; //!< COMWAKE Minimum Value  This field is RW when WE=1 and RO when WE=0.
        unsigned WE : 1; //!< Write Enable  This bit is cleared when COMRESET is detected.  The options for this field are:
    } B;
} hw_sata_oobr_t;
#endif

/*
 * constants & macros for entire SATA_OOBR register
 */
#define HW_SATA_OOBR_ADDR      (REGS_SATA_BASE + 0xbc)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_OOBR           (*(volatile hw_sata_oobr_t *) HW_SATA_OOBR_ADDR)
#define HW_SATA_OOBR_RD()      (HW_SATA_OOBR.U)
#define HW_SATA_OOBR_WR(v)     (HW_SATA_OOBR.U = (v))
#define HW_SATA_OOBR_SET(v)    (HW_SATA_OOBR_WR(HW_SATA_OOBR_RD() |  (v)))
#define HW_SATA_OOBR_CLR(v)    (HW_SATA_OOBR_WR(HW_SATA_OOBR_RD() & ~(v)))
#define HW_SATA_OOBR_TOG(v)    (HW_SATA_OOBR_WR(HW_SATA_OOBR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_OOBR bitfields
 */

/* --- Register HW_SATA_OOBR, field CIMAX
 *
 * COMINIT Maximum Value  This field is RW when WE=1 and RO when WE=0.
 */

#define BP_SATA_OOBR_CIMAX      0
#define BM_SATA_OOBR_CIMAX      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_OOBR_CIMAX(v)   ((((reg32_t) v) << 0) & BM_SATA_OOBR_CIMAX)
#else
#define BF_SATA_OOBR_CIMAX(v)   (((v) << 0) & BM_SATA_OOBR_CIMAX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_OOBR_CIMAX(v)   BF_CS1(SATA_OOBR, CIMAX, v)
#endif

/* --- Register HW_SATA_OOBR, field CIMIN
 *
 * COMINIT Minimum Value  This field is RW when WE=1 and RO when WE=0.
 */

#define BP_SATA_OOBR_CIMIN      8
#define BM_SATA_OOBR_CIMIN      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_OOBR_CIMIN(v)   ((((reg32_t) v) << 8) & BM_SATA_OOBR_CIMIN)
#else
#define BF_SATA_OOBR_CIMIN(v)   (((v) << 8) & BM_SATA_OOBR_CIMIN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_OOBR_CIMIN(v)   BF_CS1(SATA_OOBR, CIMIN, v)
#endif

/* --- Register HW_SATA_OOBR, field CWMAX
 *
 * COMWAKE Maximum Value  This field is RW when WE=1 and RO when WE=0.
 */

#define BP_SATA_OOBR_CWMAX      16
#define BM_SATA_OOBR_CWMAX      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_OOBR_CWMAX(v)   ((((reg32_t) v) << 16) & BM_SATA_OOBR_CWMAX)
#else
#define BF_SATA_OOBR_CWMAX(v)   (((v) << 16) & BM_SATA_OOBR_CWMAX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_OOBR_CWMAX(v)   BF_CS1(SATA_OOBR, CWMAX, v)
#endif

/* --- Register HW_SATA_OOBR, field CWMIN
 *
 * COMWAKE Minimum Value  This field is RW when WE=1 and RO when WE=0.
 */

#define BP_SATA_OOBR_CWMIN      24
#define BM_SATA_OOBR_CWMIN      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_OOBR_CWMIN(v)   ((((reg32_t) v) << 24) & BM_SATA_OOBR_CWMIN)
#else
#define BF_SATA_OOBR_CWMIN(v)   (((v) << 24) & BM_SATA_OOBR_CWMIN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_OOBR_CWMIN(v)   BF_CS1(SATA_OOBR, CWMIN, v)
#endif

/* --- Register HW_SATA_OOBR, field WE
 *
 * Write Enable  This bit is cleared when COMRESET is detected.  The options for this field are:
 */

#define BP_SATA_OOBR_WE      31
#define BM_SATA_OOBR_WE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_OOBR_WE(v)   ((((reg32_t) v) << 31) & BM_SATA_OOBR_WE)
#else
#define BF_SATA_OOBR_WE(v)   (((v) << 31) & BM_SATA_OOBR_WE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_OOBR_WE(v)   BF_CS1(SATA_OOBR, WE, v)
#endif

/*!
 * @brief HW_SATA_GPCR - General Purpose Control Register
 *
 * This 32-bit register is used for general purpose control. This register only exists when GP_CTRL
 * parameter is set to “Include” otherwise this location is reserved.  The bits of this register are
 * connected to the corresponding bits of the gp_ctrl output. Resets on power-up
 * (system reset) only to the GP_CTRL_DEF value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GP_CONTROL : 32; //!< General Purpose Control. Present only when GP_CTRL=Include(1). Reset Value: Configurable parameter GP_CTRL_DEF
    } B;
} hw_sata_gpcr_t;
#endif

/*
 * constants & macros for entire SATA_GPCR register
 */
#define HW_SATA_GPCR_ADDR      (REGS_SATA_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GPCR           (*(volatile hw_sata_gpcr_t *) HW_SATA_GPCR_ADDR)
#define HW_SATA_GPCR_RD()      (HW_SATA_GPCR.U)
#define HW_SATA_GPCR_WR(v)     (HW_SATA_GPCR.U = (v))
#define HW_SATA_GPCR_SET(v)    (HW_SATA_GPCR_WR(HW_SATA_GPCR_RD() |  (v)))
#define HW_SATA_GPCR_CLR(v)    (HW_SATA_GPCR_WR(HW_SATA_GPCR_RD() & ~(v)))
#define HW_SATA_GPCR_TOG(v)    (HW_SATA_GPCR_WR(HW_SATA_GPCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_GPCR bitfields
 */

/* --- Register HW_SATA_GPCR, field GP_CONTROL
 *
 * General Purpose Control. Present only when GP_CTRL=Include(1).                 Reset Value:
 * Configurable parameter GP_CTRL_DEF
 */

#define BP_SATA_GPCR_GP_CONTROL      0
#define BM_SATA_GPCR_GP_CONTROL      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPCR_GP_CONTROL(v)   ((((reg32_t) v) << 0) & BM_SATA_GPCR_GP_CONTROL)
#else
#define BF_SATA_GPCR_GP_CONTROL(v)   (((v) << 0) & BM_SATA_GPCR_GP_CONTROL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPCR_GP_CONTROL(v)   BF_CS1(SATA_GPCR, GP_CONTROL, v)
#endif

/*!
 * @brief HW_SATA_GPSR - General Purpose Status Register
 *
 * This 32-bit register is used to monitor the general purpose status. This register only exists
 * when GP_STAT             parameter is set to “Include”, otherwise, this location is reserved.
 * The bits of this register reflect the state of the corresponding bits of the gp_status input.
 * Signals connected to the gp_status input can be asynchronous to any of the DWC_ahsata clocks,
 * however they must not change faster than five hclk/aclk periods, otherwise the GPSR register
 * may never be updated with the intermediate changing values.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GP_STATUS : 32; //!< General Purpose Status. Present only when GP_STAT=Include(1)
    } B;
} hw_sata_gpsr_t;
#endif

/*
 * constants & macros for entire SATA_GPSR register
 */
#define HW_SATA_GPSR_ADDR      (REGS_SATA_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GPSR           (*(volatile hw_sata_gpsr_t *) HW_SATA_GPSR_ADDR)
#define HW_SATA_GPSR_RD()      (HW_SATA_GPSR.U)
#define HW_SATA_GPSR_WR(v)     (HW_SATA_GPSR.U = (v))
#define HW_SATA_GPSR_SET(v)    (HW_SATA_GPSR_WR(HW_SATA_GPSR_RD() |  (v)))
#define HW_SATA_GPSR_CLR(v)    (HW_SATA_GPSR_WR(HW_SATA_GPSR_RD() & ~(v)))
#define HW_SATA_GPSR_TOG(v)    (HW_SATA_GPSR_WR(HW_SATA_GPSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_GPSR bitfields
 */

/* --- Register HW_SATA_GPSR, field GP_STATUS
 *
 * General Purpose Status. Present only when GP_STAT=Include(1)
 */

#define BP_SATA_GPSR_GP_STATUS      0
#define BM_SATA_GPSR_GP_STATUS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPSR_GP_STATUS(v)   ((((reg32_t) v) << 0) & BM_SATA_GPSR_GP_STATUS)
#else
#define BF_SATA_GPSR_GP_STATUS(v)   (((v) << 0) & BM_SATA_GPSR_GP_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPSR_GP_STATUS(v)   BF_CS1(SATA_GPSR, GP_STATUS, v)
#endif

/*!
 * @brief HW_SATA_TIMER1MS - Timer 1-ms Register
 *
 * This register is used to generate a 1-ms tick for the command completion
 * coalescing (CCC) logic, based on the AHB bus clock frequency. The
 * Software must initialize this register with the required value after
 * power up before using the CCC feature. This register is reset to 100,000
 * (TIMV value for 100-MHz hclk) on power up and is not affected by Global
 * reset.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TIMV : 20; //!< 1ms Timer Value  This field contains the following value for the internal timer to generate 1-ms tick:  Fhclk*1000  where Fhclk = AHB clock frequency in MHz  The options for this field are:  • RW when SATA_CCC_CTL[EN]==0  • RO when SATA_CCC_CTL[EN]==1.
        unsigned RESERVED0 : 12; //!< Reserved.
    } B;
} hw_sata_timer1ms_t;
#endif

/*
 * constants & macros for entire SATA_TIMER1MS register
 */
#define HW_SATA_TIMER1MS_ADDR      (REGS_SATA_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_TIMER1MS           (*(volatile hw_sata_timer1ms_t *) HW_SATA_TIMER1MS_ADDR)
#define HW_SATA_TIMER1MS_RD()      (HW_SATA_TIMER1MS.U)
#define HW_SATA_TIMER1MS_WR(v)     (HW_SATA_TIMER1MS.U = (v))
#define HW_SATA_TIMER1MS_SET(v)    (HW_SATA_TIMER1MS_WR(HW_SATA_TIMER1MS_RD() |  (v)))
#define HW_SATA_TIMER1MS_CLR(v)    (HW_SATA_TIMER1MS_WR(HW_SATA_TIMER1MS_RD() & ~(v)))
#define HW_SATA_TIMER1MS_TOG(v)    (HW_SATA_TIMER1MS_WR(HW_SATA_TIMER1MS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_TIMER1MS bitfields
 */

/* --- Register HW_SATA_TIMER1MS, field TIMV
 *
 * 1ms Timer Value  This field contains the following value for the internal timer to
 * generate 1-ms tick:  Fhclk*1000  where Fhclk = AHB clock frequency in MHz  The options for this
 * field are:  • RW when SATA_CCC_CTL[EN]==0  • RO when SATA_CCC_CTL[EN]==1.
 */

#define BP_SATA_TIMER1MS_TIMV      0
#define BM_SATA_TIMER1MS_TIMV      0x000fffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_TIMER1MS_TIMV(v)   ((((reg32_t) v) << 0) & BM_SATA_TIMER1MS_TIMV)
#else
#define BF_SATA_TIMER1MS_TIMV(v)   (((v) << 0) & BM_SATA_TIMER1MS_TIMV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_TIMER1MS_TIMV(v)   BF_CS1(SATA_TIMER1MS, TIMV, v)
#endif

/*!
 * @brief HW_SATA_GPARAM1R - Global Parameter 1 Register
 *
 * This read-only register contains encoded information about the SATA block
 * global configuration parameters' settings.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 6; //!< Reserved.
        unsigned M_HADDR : 1; //!< AHB Master Address Bus Width  This value is derived from the M_HADDR_WIDTH parameter: The options for this field are:
        unsigned S_HADDR : 1; //!< AHB Slave Address Bus Width  This value is derived from the S_HADDR_WIDTH parameter: The options for this field are:
        unsigned AHB_ENDIAN : 2; //!< AHB Bus Endianness  This value is derived from the AHB_ENDIANNESS parameter: The options for this field are:
        unsigned RETURN_ERR : 1; //!< AHB Error Response  This value is derived from the RETURN_ERR_RESP parameter: The options for this field are:
        unsigned RESERVED1 : 2; //!< Reserved. Returns 1.
        unsigned BIST_M : 1; //!< BIST Loopback Checking Depth  This value is derived from the BIST_MODE parameter. The options for this field are:
        unsigned RESERVED2 : 1; //!< Reserved. Returns 0.
        unsigned PHY_STAT : 6; //!< PHY Status Width   0x20 (32) PHY Status Width is 32 bits.  This value reflects the PHY_STAT_W parameter.
        unsigned PHY_CTRL : 6; //!< PHY Control Width   0x20 (32) PHY Control Width is 32 bits.  This value reflects the PHY_CTRL_W parameter.
        unsigned PHY_RST : 1; //!< PHY Reset Mode  This value is derived from the PHY_RST_MODE parameter. The options for this field are:
        unsigned PHY_DATA : 2; //!< PHY Data Width  This value is derived from the PHY_DATA_WIDTH parameter: The options for this field are:  • 0x0: 1  0x1: PHY DATA WIDTH = 2  • 0x2: 4   Other values are reserved.
        unsigned RX_BUFFER : 1; //!< Rx Data Buffer  This value is derived from the RX_BUFFER_MODE parameter:
        unsigned ALIGN_M : 1; //!< Rx Data Alignment  This value is derived from the ALIGN_MODE parameter.  The options for this field are:
    } B;
} hw_sata_gparam1r_t;
#endif

/*
 * constants & macros for entire SATA_GPARAM1R register
 */
#define HW_SATA_GPARAM1R_ADDR      (REGS_SATA_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GPARAM1R           (*(volatile hw_sata_gparam1r_t *) HW_SATA_GPARAM1R_ADDR)
#define HW_SATA_GPARAM1R_RD()      (HW_SATA_GPARAM1R.U)
#define HW_SATA_GPARAM1R_WR(v)     (HW_SATA_GPARAM1R.U = (v))
#define HW_SATA_GPARAM1R_SET(v)    (HW_SATA_GPARAM1R_WR(HW_SATA_GPARAM1R_RD() |  (v)))
#define HW_SATA_GPARAM1R_CLR(v)    (HW_SATA_GPARAM1R_WR(HW_SATA_GPARAM1R_RD() & ~(v)))
#define HW_SATA_GPARAM1R_TOG(v)    (HW_SATA_GPARAM1R_WR(HW_SATA_GPARAM1R_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_GPARAM1R bitfields
 */

/* --- Register HW_SATA_GPARAM1R, field M_HADDR
 *
 * AHB Master Address Bus Width  This value is derived from the M_HADDR_WIDTH
 * parameter: The options for this field are:
 */

#define BP_SATA_GPARAM1R_M_HADDR      6
#define BM_SATA_GPARAM1R_M_HADDR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_M_HADDR(v)   ((((reg32_t) v) << 6) & BM_SATA_GPARAM1R_M_HADDR)
#else
#define BF_SATA_GPARAM1R_M_HADDR(v)   (((v) << 6) & BM_SATA_GPARAM1R_M_HADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_M_HADDR(v)   BF_CS1(SATA_GPARAM1R, M_HADDR, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field S_HADDR
 *
 * AHB Slave Address Bus Width  This value is derived from the S_HADDR_WIDTH
 * parameter: The options for this field are:
 */

#define BP_SATA_GPARAM1R_S_HADDR      7
#define BM_SATA_GPARAM1R_S_HADDR      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_S_HADDR(v)   ((((reg32_t) v) << 7) & BM_SATA_GPARAM1R_S_HADDR)
#else
#define BF_SATA_GPARAM1R_S_HADDR(v)   (((v) << 7) & BM_SATA_GPARAM1R_S_HADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_S_HADDR(v)   BF_CS1(SATA_GPARAM1R, S_HADDR, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field AHB_ENDIAN
 *
 * AHB Bus Endianness  This value is derived from the AHB_ENDIANNESS
 * parameter: The options for this field are:
 */

#define BP_SATA_GPARAM1R_AHB_ENDIAN      8
#define BM_SATA_GPARAM1R_AHB_ENDIAN      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_AHB_ENDIAN(v)   ((((reg32_t) v) << 8) & BM_SATA_GPARAM1R_AHB_ENDIAN)
#else
#define BF_SATA_GPARAM1R_AHB_ENDIAN(v)   (((v) << 8) & BM_SATA_GPARAM1R_AHB_ENDIAN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_AHB_ENDIAN(v)   BF_CS1(SATA_GPARAM1R, AHB_ENDIAN, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field RETURN_ERR
 *
 * AHB Error Response  This value is derived from the RETURN_ERR_RESP
 * parameter: The options for this field are:
 */

#define BP_SATA_GPARAM1R_RETURN_ERR      10
#define BM_SATA_GPARAM1R_RETURN_ERR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_RETURN_ERR(v)   ((((reg32_t) v) << 10) & BM_SATA_GPARAM1R_RETURN_ERR)
#else
#define BF_SATA_GPARAM1R_RETURN_ERR(v)   (((v) << 10) & BM_SATA_GPARAM1R_RETURN_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_RETURN_ERR(v)   BF_CS1(SATA_GPARAM1R, RETURN_ERR, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field BIST_M
 *
 * BIST Loopback Checking Depth  This value is derived from the BIST_MODE
 * parameter. The options for this field are:
 */

#define BP_SATA_GPARAM1R_BIST_M      13
#define BM_SATA_GPARAM1R_BIST_M      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_BIST_M(v)   ((((reg32_t) v) << 13) & BM_SATA_GPARAM1R_BIST_M)
#else
#define BF_SATA_GPARAM1R_BIST_M(v)   (((v) << 13) & BM_SATA_GPARAM1R_BIST_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_BIST_M(v)   BF_CS1(SATA_GPARAM1R, BIST_M, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field PHY_STAT
 *
 * PHY Status Width   0x20 (32) PHY Status Width is 32 bits.  This value reflects the PHY_STAT_W
 * parameter.
 */

#define BP_SATA_GPARAM1R_PHY_STAT      15
#define BM_SATA_GPARAM1R_PHY_STAT      0x001f8000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_PHY_STAT(v)   ((((reg32_t) v) << 15) & BM_SATA_GPARAM1R_PHY_STAT)
#else
#define BF_SATA_GPARAM1R_PHY_STAT(v)   (((v) << 15) & BM_SATA_GPARAM1R_PHY_STAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_PHY_STAT(v)   BF_CS1(SATA_GPARAM1R, PHY_STAT, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field PHY_CTRL
 *
 * PHY Control Width   0x20 (32) PHY Control Width is 32 bits.  This value reflects the PHY_CTRL_W
 * parameter.
 */

#define BP_SATA_GPARAM1R_PHY_CTRL      21
#define BM_SATA_GPARAM1R_PHY_CTRL      0x07e00000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_PHY_CTRL(v)   ((((reg32_t) v) << 21) & BM_SATA_GPARAM1R_PHY_CTRL)
#else
#define BF_SATA_GPARAM1R_PHY_CTRL(v)   (((v) << 21) & BM_SATA_GPARAM1R_PHY_CTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_PHY_CTRL(v)   BF_CS1(SATA_GPARAM1R, PHY_CTRL, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field PHY_RST
 *
 * PHY Reset Mode  This value is derived from the PHY_RST_MODE
 * parameter. The options for this field are:
 */

#define BP_SATA_GPARAM1R_PHY_RST      27
#define BM_SATA_GPARAM1R_PHY_RST      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_PHY_RST(v)   ((((reg32_t) v) << 27) & BM_SATA_GPARAM1R_PHY_RST)
#else
#define BF_SATA_GPARAM1R_PHY_RST(v)   (((v) << 27) & BM_SATA_GPARAM1R_PHY_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_PHY_RST(v)   BF_CS1(SATA_GPARAM1R, PHY_RST, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field PHY_DATA
 *
 * PHY Data Width  This value is derived from the PHY_DATA_WIDTH
 * parameter: The options for this field are:  • 0x0: 1  0x1: PHY DATA WIDTH = 2  • 0x2: 4   Other
 * values are reserved.
 */

#define BP_SATA_GPARAM1R_PHY_DATA      28
#define BM_SATA_GPARAM1R_PHY_DATA      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_PHY_DATA(v)   ((((reg32_t) v) << 28) & BM_SATA_GPARAM1R_PHY_DATA)
#else
#define BF_SATA_GPARAM1R_PHY_DATA(v)   (((v) << 28) & BM_SATA_GPARAM1R_PHY_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_PHY_DATA(v)   BF_CS1(SATA_GPARAM1R, PHY_DATA, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field RX_BUFFER
 *
 * Rx Data Buffer  This value is derived from the RX_BUFFER_MODE
 * parameter:
 */

#define BP_SATA_GPARAM1R_RX_BUFFER      30
#define BM_SATA_GPARAM1R_RX_BUFFER      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_RX_BUFFER(v)   ((((reg32_t) v) << 30) & BM_SATA_GPARAM1R_RX_BUFFER)
#else
#define BF_SATA_GPARAM1R_RX_BUFFER(v)   (((v) << 30) & BM_SATA_GPARAM1R_RX_BUFFER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_RX_BUFFER(v)   BF_CS1(SATA_GPARAM1R, RX_BUFFER, v)
#endif

/* --- Register HW_SATA_GPARAM1R, field ALIGN_M
 *
 * Rx Data Alignment  This value is derived from the ALIGN_MODE
 * parameter.  The options for this field are:
 */

#define BP_SATA_GPARAM1R_ALIGN_M      31
#define BM_SATA_GPARAM1R_ALIGN_M      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM1R_ALIGN_M(v)   ((((reg32_t) v) << 31) & BM_SATA_GPARAM1R_ALIGN_M)
#else
#define BF_SATA_GPARAM1R_ALIGN_M(v)   (((v) << 31) & BM_SATA_GPARAM1R_ALIGN_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM1R_ALIGN_M(v)   BF_CS1(SATA_GPARAM1R, ALIGN_M, v)
#endif

/*!
 * @brief HW_SATA_GPARAM2R - Global Parameter 1 Register
 *
 * This read-only register contains encoded information about the SATA block
 * global configuration parameters' settings.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RXOOB_CLK : 9; //!< Rx OOB Clock Frequency  This field returns 0x32 (50 decimal)  The Rx OOB clock frequency is 50 MHz.  This value reflects the hexadecimal value of the RXOOB_CLK_FREQ   parameter .
        unsigned TX_OOB_M : 1; //!< Tx OOB Mode  This value is derived from the TX_OOB_MODE parameter:  The options for this field are:
        unsigned RX_OOB_M : 1; //!< Rx OOB Mode  This value is derived from the RX_OOB_MODE parameter:  The options for this field are:
        unsigned RXOOB_CLK_M : 1; //!< Rx OOB Clock Mode  This value is derived from the RXOOB_CLK_MODE parameter,  The options for this field are:
        unsigned ENCODE_M : 1; //!< 8b/10b Encoding/Decoding  This value is derived from the ENCODE_MODE parameter.  The options for this field are:
        unsigned DEV_MP : 1; //!< Mechanical Presence Switch  This value is derived from the DEV_MP_SWITCH parameter.  The options for this field are:
        unsigned DEV_CP : 1; //!< Cold Presence Detect  This value is derived from the DEV_CP_DET parameter. The options for this field are:
        unsigned RESERVED0 : 17; //!< Reserved
    } B;
} hw_sata_gparam2r_t;
#endif

/*
 * constants & macros for entire SATA_GPARAM2R register
 */
#define HW_SATA_GPARAM2R_ADDR      (REGS_SATA_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GPARAM2R           (*(volatile hw_sata_gparam2r_t *) HW_SATA_GPARAM2R_ADDR)
#define HW_SATA_GPARAM2R_RD()      (HW_SATA_GPARAM2R.U)
#define HW_SATA_GPARAM2R_WR(v)     (HW_SATA_GPARAM2R.U = (v))
#define HW_SATA_GPARAM2R_SET(v)    (HW_SATA_GPARAM2R_WR(HW_SATA_GPARAM2R_RD() |  (v)))
#define HW_SATA_GPARAM2R_CLR(v)    (HW_SATA_GPARAM2R_WR(HW_SATA_GPARAM2R_RD() & ~(v)))
#define HW_SATA_GPARAM2R_TOG(v)    (HW_SATA_GPARAM2R_WR(HW_SATA_GPARAM2R_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_GPARAM2R bitfields
 */

/* --- Register HW_SATA_GPARAM2R, field RXOOB_CLK
 *
 * Rx OOB Clock Frequency  This field returns 0x32 (50 decimal)  The Rx OOB clock frequency is 50
 * MHz.  This value reflects the hexadecimal value of the
 * RXOOB_CLK_FREQ   parameter .
 */

#define BP_SATA_GPARAM2R_RXOOB_CLK      0
#define BM_SATA_GPARAM2R_RXOOB_CLK      0x000001ff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM2R_RXOOB_CLK(v)   ((((reg32_t) v) << 0) & BM_SATA_GPARAM2R_RXOOB_CLK)
#else
#define BF_SATA_GPARAM2R_RXOOB_CLK(v)   (((v) << 0) & BM_SATA_GPARAM2R_RXOOB_CLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM2R_RXOOB_CLK(v)   BF_CS1(SATA_GPARAM2R, RXOOB_CLK, v)
#endif

/* --- Register HW_SATA_GPARAM2R, field TX_OOB_M
 *
 * Tx OOB Mode  This value is derived from the TX_OOB_MODE
 * parameter:  The options for this field are:
 */

#define BP_SATA_GPARAM2R_TX_OOB_M      9
#define BM_SATA_GPARAM2R_TX_OOB_M      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM2R_TX_OOB_M(v)   ((((reg32_t) v) << 9) & BM_SATA_GPARAM2R_TX_OOB_M)
#else
#define BF_SATA_GPARAM2R_TX_OOB_M(v)   (((v) << 9) & BM_SATA_GPARAM2R_TX_OOB_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM2R_TX_OOB_M(v)   BF_CS1(SATA_GPARAM2R, TX_OOB_M, v)
#endif

/* --- Register HW_SATA_GPARAM2R, field RX_OOB_M
 *
 * Rx OOB Mode  This value is derived from the RX_OOB_MODE
 * parameter:  The options for this field are:
 */

#define BP_SATA_GPARAM2R_RX_OOB_M      10
#define BM_SATA_GPARAM2R_RX_OOB_M      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM2R_RX_OOB_M(v)   ((((reg32_t) v) << 10) & BM_SATA_GPARAM2R_RX_OOB_M)
#else
#define BF_SATA_GPARAM2R_RX_OOB_M(v)   (((v) << 10) & BM_SATA_GPARAM2R_RX_OOB_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM2R_RX_OOB_M(v)   BF_CS1(SATA_GPARAM2R, RX_OOB_M, v)
#endif

/* --- Register HW_SATA_GPARAM2R, field RXOOB_CLK_M
 *
 * Rx OOB Clock Mode  This value is derived from the RXOOB_CLK_MODE
 * parameter,  The options for this field are:
 */

#define BP_SATA_GPARAM2R_RXOOB_CLK_M      11
#define BM_SATA_GPARAM2R_RXOOB_CLK_M      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM2R_RXOOB_CLK_M(v)   ((((reg32_t) v) << 11) & BM_SATA_GPARAM2R_RXOOB_CLK_M)
#else
#define BF_SATA_GPARAM2R_RXOOB_CLK_M(v)   (((v) << 11) & BM_SATA_GPARAM2R_RXOOB_CLK_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM2R_RXOOB_CLK_M(v)   BF_CS1(SATA_GPARAM2R, RXOOB_CLK_M, v)
#endif

/* --- Register HW_SATA_GPARAM2R, field ENCODE_M
 *
 * 8b/10b Encoding/Decoding  This value is derived from the ENCODE_MODE
 * parameter.  The options for this field are:
 */

#define BP_SATA_GPARAM2R_ENCODE_M      12
#define BM_SATA_GPARAM2R_ENCODE_M      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM2R_ENCODE_M(v)   ((((reg32_t) v) << 12) & BM_SATA_GPARAM2R_ENCODE_M)
#else
#define BF_SATA_GPARAM2R_ENCODE_M(v)   (((v) << 12) & BM_SATA_GPARAM2R_ENCODE_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM2R_ENCODE_M(v)   BF_CS1(SATA_GPARAM2R, ENCODE_M, v)
#endif

/* --- Register HW_SATA_GPARAM2R, field DEV_MP
 *
 * Mechanical Presence Switch  This value is derived from the DEV_MP_SWITCH
 * parameter.  The options for this field are:
 */

#define BP_SATA_GPARAM2R_DEV_MP      13
#define BM_SATA_GPARAM2R_DEV_MP      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM2R_DEV_MP(v)   ((((reg32_t) v) << 13) & BM_SATA_GPARAM2R_DEV_MP)
#else
#define BF_SATA_GPARAM2R_DEV_MP(v)   (((v) << 13) & BM_SATA_GPARAM2R_DEV_MP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM2R_DEV_MP(v)   BF_CS1(SATA_GPARAM2R, DEV_MP, v)
#endif

/* --- Register HW_SATA_GPARAM2R, field DEV_CP
 *
 * Cold Presence Detect  This value is derived from the DEV_CP_DET
 * parameter. The options for this field are:
 */

#define BP_SATA_GPARAM2R_DEV_CP      14
#define BM_SATA_GPARAM2R_DEV_CP      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_GPARAM2R_DEV_CP(v)   ((((reg32_t) v) << 14) & BM_SATA_GPARAM2R_DEV_CP)
#else
#define BF_SATA_GPARAM2R_DEV_CP(v)   (((v) << 14) & BM_SATA_GPARAM2R_DEV_CP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_GPARAM2R_DEV_CP(v)   BF_CS1(SATA_GPARAM2R, DEV_CP, v)
#endif

/*!
 * @brief HW_SATA_PPARAMR - Port Parameter Register
 *
 * This read-only register contains encoded information about the selected
 * Port configuration parameters' settings. The Port is selected by the
 * SATA_TESTR[PSEL] field.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RXFIFO_DEPTH : 3; //!< Rx FIFO Depth  0x4 Rx FIFO Depth set to 512 DWORDs  This value is derived from the P#_RXFIFO_DEPTH parameter: The options for this field are:
        unsigned TXFIFO_DEPTH : 3; //!< Tx FIFO Depth  0x4 Tx FIFO Depth set to 512 DWORDs  This value is derived from the P#_TXFIFO_DEPTH parameter: The options for this field are:
        unsigned RX_MEM_S : 1; //!< Rx FIFO Memory Type  This value is derived from the P#_RX_MEM_SELECT parameter:  The options for this field are:
        unsigned RX_MEM_M : 1; //!< Rx FIFO Memory Read Port Type  This value is derived from the P#_RX_MEM_MODE parameter:  The options for this field are:
        unsigned TX_MEM_S : 1; //!< Tx FIFO Memory Type  This value is derived from the P#_TX_MEM_SELECT parameter:  The options for this field are:
        unsigned TX_MEM_M : 1; //!< Tx FIFO Memory Read Port Type  This value is derived from the P#_TX_MEM_MODE parameter:  The options for this field are:
        unsigned TX_MEM_S1 : 1; //!< TX FIFO Memory This value is derived from the P0_TX_MEM_SELECT parameter. The options for this field are:
        unsigned TX_MEM_M1 : 1; //!< TX FIFO Memory Read Port Type This value is derived from the P0_TX_MEM_MODE parameter. The options for this field are:
        unsigned RESERVED0 : 20; //!< Reserved
    } B;
} hw_sata_pparamr_t;
#endif

/*
 * constants & macros for entire SATA_PPARAMR register
 */
#define HW_SATA_PPARAMR_ADDR      (REGS_SATA_BASE + 0xf0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_PPARAMR           (*(volatile hw_sata_pparamr_t *) HW_SATA_PPARAMR_ADDR)
#define HW_SATA_PPARAMR_RD()      (HW_SATA_PPARAMR.U)
#define HW_SATA_PPARAMR_WR(v)     (HW_SATA_PPARAMR.U = (v))
#define HW_SATA_PPARAMR_SET(v)    (HW_SATA_PPARAMR_WR(HW_SATA_PPARAMR_RD() |  (v)))
#define HW_SATA_PPARAMR_CLR(v)    (HW_SATA_PPARAMR_WR(HW_SATA_PPARAMR_RD() & ~(v)))
#define HW_SATA_PPARAMR_TOG(v)    (HW_SATA_PPARAMR_WR(HW_SATA_PPARAMR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_PPARAMR bitfields
 */

/* --- Register HW_SATA_PPARAMR, field RXFIFO_DEPTH
 *
 * Rx FIFO Depth  0x4 Rx FIFO Depth set to 512 DWORDs  This value is derived from the
 * P#_RXFIFO_DEPTH                                 parameter: The options for this field are:
 */

#define BP_SATA_PPARAMR_RXFIFO_DEPTH      0
#define BM_SATA_PPARAMR_RXFIFO_DEPTH      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PPARAMR_RXFIFO_DEPTH(v)   ((((reg32_t) v) << 0) & BM_SATA_PPARAMR_RXFIFO_DEPTH)
#else
#define BF_SATA_PPARAMR_RXFIFO_DEPTH(v)   (((v) << 0) & BM_SATA_PPARAMR_RXFIFO_DEPTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PPARAMR_RXFIFO_DEPTH(v)   BF_CS1(SATA_PPARAMR, RXFIFO_DEPTH, v)
#endif

/* --- Register HW_SATA_PPARAMR, field TXFIFO_DEPTH
 *
 * Tx FIFO Depth  0x4 Tx FIFO Depth set to 512 DWORDs  This value is derived from the
 * P#_TXFIFO_DEPTH                                 parameter: The options for this field are:
 */

#define BP_SATA_PPARAMR_TXFIFO_DEPTH      3
#define BM_SATA_PPARAMR_TXFIFO_DEPTH      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PPARAMR_TXFIFO_DEPTH(v)   ((((reg32_t) v) << 3) & BM_SATA_PPARAMR_TXFIFO_DEPTH)
#else
#define BF_SATA_PPARAMR_TXFIFO_DEPTH(v)   (((v) << 3) & BM_SATA_PPARAMR_TXFIFO_DEPTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PPARAMR_TXFIFO_DEPTH(v)   BF_CS1(SATA_PPARAMR, TXFIFO_DEPTH, v)
#endif

/* --- Register HW_SATA_PPARAMR, field RX_MEM_S
 *
 * Rx FIFO Memory Type  This value is derived from the P#_RX_MEM_SELECT
 * parameter:  The options for this field are:
 */

#define BP_SATA_PPARAMR_RX_MEM_S      6
#define BM_SATA_PPARAMR_RX_MEM_S      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PPARAMR_RX_MEM_S(v)   ((((reg32_t) v) << 6) & BM_SATA_PPARAMR_RX_MEM_S)
#else
#define BF_SATA_PPARAMR_RX_MEM_S(v)   (((v) << 6) & BM_SATA_PPARAMR_RX_MEM_S)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PPARAMR_RX_MEM_S(v)   BF_CS1(SATA_PPARAMR, RX_MEM_S, v)
#endif

/* --- Register HW_SATA_PPARAMR, field RX_MEM_M
 *
 * Rx FIFO Memory Read Port Type  This value is derived from the P#_RX_MEM_MODE
 * parameter:  The options for this field are:
 */

#define BP_SATA_PPARAMR_RX_MEM_M      7
#define BM_SATA_PPARAMR_RX_MEM_M      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PPARAMR_RX_MEM_M(v)   ((((reg32_t) v) << 7) & BM_SATA_PPARAMR_RX_MEM_M)
#else
#define BF_SATA_PPARAMR_RX_MEM_M(v)   (((v) << 7) & BM_SATA_PPARAMR_RX_MEM_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PPARAMR_RX_MEM_M(v)   BF_CS1(SATA_PPARAMR, RX_MEM_M, v)
#endif

/* --- Register HW_SATA_PPARAMR, field TX_MEM_S
 *
 * Tx FIFO Memory Type  This value is derived from the P#_TX_MEM_SELECT
 * parameter:  The options for this field are:
 */

#define BP_SATA_PPARAMR_TX_MEM_S      8
#define BM_SATA_PPARAMR_TX_MEM_S      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PPARAMR_TX_MEM_S(v)   ((((reg32_t) v) << 8) & BM_SATA_PPARAMR_TX_MEM_S)
#else
#define BF_SATA_PPARAMR_TX_MEM_S(v)   (((v) << 8) & BM_SATA_PPARAMR_TX_MEM_S)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PPARAMR_TX_MEM_S(v)   BF_CS1(SATA_PPARAMR, TX_MEM_S, v)
#endif

/* --- Register HW_SATA_PPARAMR, field TX_MEM_M
 *
 * Tx FIFO Memory Read Port Type  This value is derived from the P#_TX_MEM_MODE
 * parameter:  The options for this field are:
 */

#define BP_SATA_PPARAMR_TX_MEM_M      9
#define BM_SATA_PPARAMR_TX_MEM_M      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PPARAMR_TX_MEM_M(v)   ((((reg32_t) v) << 9) & BM_SATA_PPARAMR_TX_MEM_M)
#else
#define BF_SATA_PPARAMR_TX_MEM_M(v)   (((v) << 9) & BM_SATA_PPARAMR_TX_MEM_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PPARAMR_TX_MEM_M(v)   BF_CS1(SATA_PPARAMR, TX_MEM_M, v)
#endif

/* --- Register HW_SATA_PPARAMR, field TX_MEM_S
 *
 * TX FIFO Memory                 This value is derived from the P0_TX_MEM_SELECT
 * parameter.                 The options for this field are:
 */

#define BP_SATA_PPARAMR_TX_MEM_S      10
#define BM_SATA_PPARAMR_TX_MEM_S      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PPARAMR_TX_MEM_S(v)   ((((reg32_t) v) << 10) & BM_SATA_PPARAMR_TX_MEM_S)
#else
#define BF_SATA_PPARAMR_TX_MEM_S(v)   (((v) << 10) & BM_SATA_PPARAMR_TX_MEM_S)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PPARAMR_TX_MEM_S(v)   BF_CS1(SATA_PPARAMR, TX_MEM_S, v)
#endif

/* --- Register HW_SATA_PPARAMR, field TX_MEM_M
 *
 * TX FIFO Memory Read Port Type                 This value is derived from the P0_TX_MEM_MODE
 * parameter. The options for this field are:
 */

#define BP_SATA_PPARAMR_TX_MEM_M      11
#define BM_SATA_PPARAMR_TX_MEM_M      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SATA_PPARAMR_TX_MEM_M(v)   ((((reg32_t) v) << 11) & BM_SATA_PPARAMR_TX_MEM_M)
#else
#define BF_SATA_PPARAMR_TX_MEM_M(v)   (((v) << 11) & BM_SATA_PPARAMR_TX_MEM_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_PPARAMR_TX_MEM_M(v)   BF_CS1(SATA_PPARAMR, TX_MEM_M, v)
#endif

/*!
 * @brief HW_SATA_TESTR - Test Register
 *
 * This register is used to put the SATA block slave interface into a test
 * mode and to select a Port for BIST operation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TEST_IF : 1; //!< TEST_IF: Test Interface  Normal operation is disabled. The following registers can be accessed in this  mode:  - SATA_GHC register IE bit  - SATA_BISTAFR register NCP and PD bits become read-write  - SATA_BISTCR register LLC, ERREN, FLIP, PV, PATTERN  - SATA_BISTFCTR, SATA_BISTSR , SATA_BISTDECR become read-write  - SATA_P #  0 CLB /CLBU , SATA_P #  0 FB /FBU registers  - SATA_P #  0 IS register RW1C and UFS bits become read-write  - SATA_P #  0 IE register  - SATA_P #  0 CMD register ASP, ALPE, DLAE, ATAPI, PMA bits  - SATA_P #  0 TFD, SATA_P #  0 SIG registers become read-write  - SATA_P #  0 SCTL register  - SATA_P #  0 SERR register RW1C bits become read-write bits  - SATA_P #  0 SACT, SATA_P #  0 CI, SATA_P #  0 SNTF registers become read-write  - SATA_P #  0 DMACR register  - SATA_P #  0 PHYCR register  - SATA_P #  0 PHYSR register becomes read-write  Notes:  • Interrupt is asserted when any of the SATA_IS register bits is set after setting the corresponding SATA_P #  0 IS and SATA_P #  0 IE registers and SATA_GHC[IE]=1.  • SATA_CAP[SMPS], SATA_CAP[SSS], SATA_PI, SATA_P #  0 CMD[ESP], SATA_P #  0 CMD[CPD], SATA_P #  0 CMD[MPSP], and SATA_P #  0 CMD[HPCP] register bits are HwInit type and can not be used in Test mode. They are written once after power-on reset and become read-only.  • Global SATA block reset must be issued (SATA_GHC[HR]=1) after TEST_WHEN bit is cleared following the Test mode operation.  This bit is used to put the SATA block slave interface into the test mode: The options for this field are:
        unsigned RESERVED0 : 15; //!< Reserved
        unsigned PSEL : 3; //!< Port Select  This field is used to select a Port for BIST operation: The options for this field are:
        unsigned RESERVED1 : 13; //!< Reserved
    } B;
} hw_sata_testr_t;
#endif

/*
 * constants & macros for entire SATA_TESTR register
 */
#define HW_SATA_TESTR_ADDR      (REGS_SATA_BASE + 0xf4)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_TESTR           (*(volatile hw_sata_testr_t *) HW_SATA_TESTR_ADDR)
#define HW_SATA_TESTR_RD()      (HW_SATA_TESTR.U)
#define HW_SATA_TESTR_WR(v)     (HW_SATA_TESTR.U = (v))
#define HW_SATA_TESTR_SET(v)    (HW_SATA_TESTR_WR(HW_SATA_TESTR_RD() |  (v)))
#define HW_SATA_TESTR_CLR(v)    (HW_SATA_TESTR_WR(HW_SATA_TESTR_RD() & ~(v)))
#define HW_SATA_TESTR_TOG(v)    (HW_SATA_TESTR_WR(HW_SATA_TESTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_TESTR bitfields
 */

/* --- Register HW_SATA_TESTR, field TEST_IF
 *
 * TEST_IF: Test Interface  Normal operation is disabled. The following registers can be accessed
 * in this  mode:  - SATA_GHC register IE bit  - SATA_BISTAFR register NCP and PD bits become read-
 * write  - SATA_BISTCR register LLC, ERREN, FLIP, PV, PATTERN  - SATA_BISTFCTR, SATA_BISTSR ,
 * SATA_BISTDECR become read-write  - SATA_P #  0 CLB /CLBU , SATA_P #  0 FB /FBU registers  -
 * SATA_P #  0 IS                                 register RW1C and UFS bits become read-write  -
 * SATA_P #  0 IE                                 register  - SATA_P #  0 CMD register ASP, ALPE,
 * DLAE, ATAPI, PMA bits  - SATA_P #  0 TFD, SATA_P #  0 SIG registers become read-write  - SATA_P #
 * 0 SCTL register  - SATA_P #  0 SERR register RW1C bits become read-write bits  - SATA_P #  0
 * SACT, SATA_P #  0 CI, SATA_P #  0 SNTF registers become                                 read-
 * write  - SATA_P #  0 DMACR register  - SATA_P #  0 PHYCR register  - SATA_P #  0 PHYSR register
 * becomes read-write  Notes:  • Interrupt is asserted when any of the SATA_IS register bits is set
 * after setting the corresponding SATA_P #  0 IS and SATA_P #  0 IE
 * registers and SATA_GHC[IE]=1.  • SATA_CAP[SMPS], SATA_CAP[SSS], SATA_PI, SATA_P #  0 CMD[ESP],
 * SATA_P #  0 CMD[CPD], SATA_P #  0 CMD[MPSP], and SATA_P #  0 CMD[HPCP]
 * register bits are HwInit type and can not be used in Test mode. They
 * are written once after power-on reset and become read-only.  • Global SATA block reset must be
 * issued (SATA_GHC[HR]=1) after                                 TEST_WHEN bit is cleared following
 * the Test mode operation.  This bit is used to put the SATA block slave interface into the test
 * mode: The options for this field are:
 */

#define BP_SATA_TESTR_TEST_IF      0
#define BM_SATA_TESTR_TEST_IF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATA_TESTR_TEST_IF(v)   ((((reg32_t) v) << 0) & BM_SATA_TESTR_TEST_IF)
#else
#define BF_SATA_TESTR_TEST_IF(v)   (((v) << 0) & BM_SATA_TESTR_TEST_IF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_TESTR_TEST_IF(v)   BF_CS1(SATA_TESTR, TEST_IF, v)
#endif

/* --- Register HW_SATA_TESTR, field PSEL
 *
 * Port Select  This field is used to select a Port for BIST operation: The options
 * for this field are:
 */

#define BP_SATA_TESTR_PSEL      16
#define BM_SATA_TESTR_PSEL      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_TESTR_PSEL(v)   ((((reg32_t) v) << 16) & BM_SATA_TESTR_PSEL)
#else
#define BF_SATA_TESTR_PSEL(v)   (((v) << 16) & BM_SATA_TESTR_PSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_TESTR_PSEL(v)   BF_CS1(SATA_TESTR, PSEL, v)
#endif

/*!
 * @brief HW_SATA_VERSIONR - Version Register
 *
 * This 32-bit read-only register contains a                                 hard-coded ASCII string
 * that represents the version level of the                                 SATA block. This
 * register contains the ASCII string                                 "300*" (hexadecimal
 * 0x3330302A). This 32-bit read-only register contains a                                 hard-coded
 * component version value set by the AHSATA_VERSION_NUM                                 parameter.
 * The value represents an ASCII code of the version number.                                 For
 * example, version 1.24* is coded as 0x3132_342A.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< SATA block hard-coded hexadecimal version value encoded in ASCII.   Parameter AHSATA_VERSION_NUM
    } B;
} hw_sata_versionr_t;
#endif

/*
 * constants & macros for entire SATA_VERSIONR register
 */
#define HW_SATA_VERSIONR_ADDR      (REGS_SATA_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_VERSIONR           (*(volatile hw_sata_versionr_t *) HW_SATA_VERSIONR_ADDR)
#define HW_SATA_VERSIONR_RD()      (HW_SATA_VERSIONR.U)
#define HW_SATA_VERSIONR_WR(v)     (HW_SATA_VERSIONR.U = (v))
#define HW_SATA_VERSIONR_SET(v)    (HW_SATA_VERSIONR_WR(HW_SATA_VERSIONR_RD() |  (v)))
#define HW_SATA_VERSIONR_CLR(v)    (HW_SATA_VERSIONR_WR(HW_SATA_VERSIONR_RD() & ~(v)))
#define HW_SATA_VERSIONR_TOG(v)    (HW_SATA_VERSIONR_WR(HW_SATA_VERSIONR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_VERSIONR bitfields
 */

/*!
 * @brief HW_SATA_P0CLB - Port0 Command List Base Address Register
 *
 * The algorithm for the software to determine the offset                             is:   Port
 * offset = 0x100 + (PI Asserted Bit Position *                                 0x80)    Size: 32
 * bits  Address offset: for # = 0 to 7:   P0CLB: 0x100  P1CLB: 0x180  P2CLB: 0x200  P3CLB: 0x280
 * P4CLB: 0x300  P5CLB: 0x380  P6CLB: 0x400  P7CLB: 0x480    Read/write access: Read/write  Reset:
 * 0x0000_0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 10; //!< Reserved.
        unsigned CLB : 22; //!< Command List Base Address  Indicates the 32-bit base physical address for the command list for this Port. This base is used when fetching commands to execute. The structure pointed to by this address range is 1 KB in length. This address must be 1-KB-aligned as indicated by bits [9:0] being read only.
    } B;
} hw_sata_p0clb_t;
#endif

/*
 * constants & macros for entire SATA_P0CLB register
 */
#define HW_SATA_P0CLB_ADDR      (REGS_SATA_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0CLB           (*(volatile hw_sata_p0clb_t *) HW_SATA_P0CLB_ADDR)
#define HW_SATA_P0CLB_RD()      (HW_SATA_P0CLB.U)
#define HW_SATA_P0CLB_WR(v)     (HW_SATA_P0CLB.U = (v))
#define HW_SATA_P0CLB_SET(v)    (HW_SATA_P0CLB_WR(HW_SATA_P0CLB_RD() |  (v)))
#define HW_SATA_P0CLB_CLR(v)    (HW_SATA_P0CLB_WR(HW_SATA_P0CLB_RD() & ~(v)))
#define HW_SATA_P0CLB_TOG(v)    (HW_SATA_P0CLB_WR(HW_SATA_P0CLB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0CLB bitfields
 */

/* --- Register HW_SATA_P0CLB, field CLB
 *
 * Command List Base Address  Indicates the 32-bit base physical address for the command list for
 * this Port. This base is used when fetching commands to execute. The
 * structure pointed to by this address range is 1 KB in length. This
 * address must be 1-KB-aligned as indicated by bits [9:0] being read
 * only.
 */

#define BP_SATA_P0CLB_CLB      10
#define BM_SATA_P0CLB_CLB      0xfffffc00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CLB_CLB(v)   ((((reg32_t) v) << 10) & BM_SATA_P0CLB_CLB)
#else
#define BF_SATA_P0CLB_CLB(v)   (((v) << 10) & BM_SATA_P0CLB_CLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CLB_CLB(v)   BF_CS1(SATA_P0CLB, CLB, v)
#endif

/*!
 * @brief HW_SATA_P0FB - Port0 FIS Base Address Register
 *
 * Size: 32 bits  Address offset: for # = 0 to 7:   P0FB: 0x108  P1FB: 0x188  P2FB: 0x208  P3FB:
 * 0x288  P4FB: 0x308  P5FB: 0x388  P6FB: 0x408  P7FB: 0x488    Read/write access: Read/write
 * Reset: 0x0000_0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8; //!< Reserved.
        unsigned FB : 24; //!< FIS Base Address.  Indicates the 32-bit base physical address for received FISes. The structure pointed to by this address range is 256 bytes in length. This address must be  256byte-aligned as indicated by bits [7:0] being read only.  Reset: 0x000000
    } B;
} hw_sata_p0fb_t;
#endif

/*
 * constants & macros for entire SATA_P0FB register
 */
#define HW_SATA_P0FB_ADDR      (REGS_SATA_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0FB           (*(volatile hw_sata_p0fb_t *) HW_SATA_P0FB_ADDR)
#define HW_SATA_P0FB_RD()      (HW_SATA_P0FB.U)
#define HW_SATA_P0FB_WR(v)     (HW_SATA_P0FB.U = (v))
#define HW_SATA_P0FB_SET(v)    (HW_SATA_P0FB_WR(HW_SATA_P0FB_RD() |  (v)))
#define HW_SATA_P0FB_CLR(v)    (HW_SATA_P0FB_WR(HW_SATA_P0FB_RD() & ~(v)))
#define HW_SATA_P0FB_TOG(v)    (HW_SATA_P0FB_WR(HW_SATA_P0FB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0FB bitfields
 */

/* --- Register HW_SATA_P0FB, field FB
 *
 * FIS Base Address.  Indicates the 32-bit base physical address for received FISes. The
 * structure pointed to by this address range is 256 bytes in length.
 * This address must be  256byte-aligned as indicated by bits [7:0] being read only.  Reset:
 * 0x000000
 */

#define BP_SATA_P0FB_FB      8
#define BM_SATA_P0FB_FB      0xffffff00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0FB_FB(v)   ((((reg32_t) v) << 8) & BM_SATA_P0FB_FB)
#else
#define BF_SATA_P0FB_FB(v)   (((v) << 8) & BM_SATA_P0FB_FB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0FB_FB(v)   BF_CS1(SATA_P0FB, FB, v)
#endif

/*!
 * @brief HW_SATA_P0IS - Port0 Interrupt Status Register
 *
 * This register is used to generate SATA block interrupt when any of the
 * bits are set. Bits in this register are set by some internal conditions,
 * and cleared by the software writing ones in the positions it wants to
 * clear. This register is reset on Global SATA block reset.   Size: 32 bits  Address offset: for #
 * = 0 to 7:   SATA_P0IS: 0x110  P1IS: 0x190  P2IS: 0x210  P3IS: 0x290  P4IS: 0x310  P5IS: 0x390
 * P6IS: 0x410  P7IS: 0x490    Read/write access: Read-only/Write One to Clear  Reset: 0x0000_0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DHRS : 1; //!< Device to Host Register FIS Interrupt  A D2H Register FIS has been received with the 'I' bit set, and has been copied into system memory.
        unsigned PSS : 1; //!< PIO Setup FIS Interrupt.  A PIO Setup FIS has been received with the 'I' bit set, it has been copied into system memory, and the data related to that FIS has been transferred.  This bit is set even when the data transfer resulted in an error.
        unsigned DSS : 1; //!< DMA Setup FIS Interrupt  A DMA Setup FIS has been received with the 'I' bit set and has been copied into system memory.
        unsigned SDBS : 1; //!< Set Device Bits Interrupt.  A Set Device Bits FIS has been received with the 'I' bit set and has been copied into system memory.
        unsigned UFS : 1; //!< Unknown FIS Interrupt.  When set to 1, indicates that an unknown FIS was received and has been copied into system memory.  This bit is cleared to 0 by the software clearing the SATA_P #  0 SERR[DIAG_F] bit to 0.  The UFS bit does not directly reflect the SATA_P #  0 SERR[DIAG_F] bit. SATA_P #  0 SERR[DIAG_F] bit is set immediately when an unknown FIS is detected, whereas the UFS bit is set when that FIS is posted to memory. The software should wait to act on an unknown FIS until the UFS bit is set to 1 or the two bits may become out of sync.
        unsigned DPS : 1; //!< Descriptor Processed  A PRD with the I bit set has transferred all of its data.  This is an opportunistic interrupt and must not be used to definitively indicate the end of a transfer. Two PRD interrupts could happen close in time together such that the second interrupt is missed when the first PRD interrupt is being cleared.
        unsigned PCS : 1; //!< Port Connect Change Status  This bit is cleared only when SATA_P #  0 SERR[DIAG_X] is cleared.  This bit reflects the state of the SATA_P #  0 SERR[DIAG_X] bit:
        unsigned RESERVED0 : 15; //!< Reserved. Returns 0 on read.
        unsigned PRCS : 1; //!< PHY Ready Change Status  This bit reflects the state of the SATA_P #  0 SERR[DIAG_N] bit.  When set to 1, indicates the internal p #  0 _phy_ready signal changed state.  To clear this bit, the software must clear the SATA_P #  0 SERR[DIAG_N] bit to 0.
        unsigned IPMS : 1; //!< Incorrect Port Multiplier Status.  Indicates that the HBA received a FIS from a device whose Port Multiplier field did not match what was expected.  This bit may be set during enumeration of devices on a Port Multiplier due to the normal Port Multiplier enumeration process.  The software must use the IPMS bit only after enumeration is complete on the  Port Multiplier.
        unsigned OFS : 1; //!< Overflow Status  This bit is set when command list overflow is detected during read or write operation when the software builds command table that has fever total bytes than the transaction given to the device.  Port DMA transitions to a fatal state until the software clears SATA_P #  0 CMD[ST] bit or resets the interface by way of Port or Global reset.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned INFS : 1; //!< Interface Non-fatal Error Status  This bit is set when any of the following conditions is detected:  • One or more of the following errors are detected during non-data FIS  transfer  - 10B to 8B Decode Error (SATA_P #  0 SERR[DIAG_B])  - Protocol (SATA_P #  0 SERR[ERR_P])  - CRC (SATA_P #  0 SERR[DIAG_C]),  - Handshake (SATA_P #  0 SERR[DIAG_H])  - PHY Not Ready (SATA_P #  0 SERR[ERR_C]);  • Command list underflow during read operation (i.e. DMA read) when the software builds command table that has more total bytes than the transaction given to the device.
        unsigned IFS : 1; //!< Interface Fatal Error Status  This bit is set when any of the following conditions is detected:  • SYNC escape is received from the device during H2D Register or Data FIS  transmission;  • One or more of the following errors are detected during Data FIS transfer:  - 10B to 8B Decode Error (SATA_P #  0 SERR[DIAG_B])  - Protocol (SATA_P #  0 SERR[ERR_P])  - CRC (SATA_P #  0 SERR[DIAG_C])  - Handshake (SATA_P #  0 SERR[DIAG_H])  - PHY Not Ready (SATA_P #  0 SERR[ERR_C])  • Unknown FIS is received with good CRC, but the length exceeds 64 bytes;  • PRD table byte count is zero.  Port DMA transitions to a fatal state until the software clears SATA_P #  0 CMD[ST] bit or resets the interface by way of Port or Global reset.
        unsigned HBDS : 1; //!< Host Bus Data Error Status.  This bit is always cleared to 0.
        unsigned HBFS : 1; //!< Host Bus Fatal Error Status.  This bit is set when SATA block AHB Master detects an ERROR response from the slave.
        unsigned TFES : 1; //!< Task File Error Status.  This bit is set whenever the SATA_P #  0 TFD[STS] register is updated by the device and the error bit (bit 0) is set.
        unsigned RESERVED2 : 1; //!< Reserved. Returns 0 on read.
    } B;
} hw_sata_p0is_t;
#endif

/*
 * constants & macros for entire SATA_P0IS register
 */
#define HW_SATA_P0IS_ADDR      (REGS_SATA_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0IS           (*(volatile hw_sata_p0is_t *) HW_SATA_P0IS_ADDR)
#define HW_SATA_P0IS_RD()      (HW_SATA_P0IS.U)
#define HW_SATA_P0IS_WR(v)     (HW_SATA_P0IS.U = (v))
#define HW_SATA_P0IS_SET(v)    (HW_SATA_P0IS_WR(HW_SATA_P0IS_RD() |  (v)))
#define HW_SATA_P0IS_CLR(v)    (HW_SATA_P0IS_WR(HW_SATA_P0IS_RD() & ~(v)))
#define HW_SATA_P0IS_TOG(v)    (HW_SATA_P0IS_WR(HW_SATA_P0IS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0IS bitfields
 */

/* --- Register HW_SATA_P0IS, field DHRS
 *
 * Device to Host Register FIS Interrupt  A D2H Register FIS has been received with the 'I' bit set,
 * and has                                 been copied into system memory.
 */

#define BP_SATA_P0IS_DHRS      0
#define BM_SATA_P0IS_DHRS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_DHRS(v)   ((((reg32_t) v) << 0) & BM_SATA_P0IS_DHRS)
#else
#define BF_SATA_P0IS_DHRS(v)   (((v) << 0) & BM_SATA_P0IS_DHRS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_DHRS(v)   BF_CS1(SATA_P0IS, DHRS, v)
#endif

/* --- Register HW_SATA_P0IS, field PSS
 *
 * PIO Setup FIS Interrupt.  A PIO Setup FIS has been received with the 'I' bit set, it has been
 * copied into system memory, and the data related to that FIS has been
 * transferred.  This bit is set even when the data transfer resulted in an
 * error.
 */

#define BP_SATA_P0IS_PSS      1
#define BM_SATA_P0IS_PSS      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_PSS(v)   ((((reg32_t) v) << 1) & BM_SATA_P0IS_PSS)
#else
#define BF_SATA_P0IS_PSS(v)   (((v) << 1) & BM_SATA_P0IS_PSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_PSS(v)   BF_CS1(SATA_P0IS, PSS, v)
#endif

/* --- Register HW_SATA_P0IS, field DSS
 *
 * DMA Setup FIS Interrupt  A DMA Setup FIS has been received with the 'I' bit set and has been
 * copied into system memory.
 */

#define BP_SATA_P0IS_DSS      2
#define BM_SATA_P0IS_DSS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_DSS(v)   ((((reg32_t) v) << 2) & BM_SATA_P0IS_DSS)
#else
#define BF_SATA_P0IS_DSS(v)   (((v) << 2) & BM_SATA_P0IS_DSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_DSS(v)   BF_CS1(SATA_P0IS, DSS, v)
#endif

/* --- Register HW_SATA_P0IS, field SDBS
 *
 * Set Device Bits Interrupt.  A Set Device Bits FIS has been received with the 'I' bit set and has
 * been copied into system memory.
 */

#define BP_SATA_P0IS_SDBS      3
#define BM_SATA_P0IS_SDBS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_SDBS(v)   ((((reg32_t) v) << 3) & BM_SATA_P0IS_SDBS)
#else
#define BF_SATA_P0IS_SDBS(v)   (((v) << 3) & BM_SATA_P0IS_SDBS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_SDBS(v)   BF_CS1(SATA_P0IS, SDBS, v)
#endif

/* --- Register HW_SATA_P0IS, field UFS
 *
 * Unknown FIS Interrupt.  When set to 1, indicates that an unknown FIS was received and has
 * been copied into system memory.  This bit is cleared to 0 by the software clearing the SATA_P #
 * 0 SERR[DIAG_F] bit to 0.  The UFS bit does not directly reflect the SATA_P #  0 SERR[DIAG_F] bit.
 * SATA_P #  0 SERR[DIAG_F] bit is set immediately                                 when an unknown
 * FIS is detected, whereas the UFS bit is set when                                 that FIS is
 * posted to memory. The software should wait to act on an                                 unknown
 * FIS until the UFS bit is set to 1 or the two bits may become                                 out
 * of sync.
 */

#define BP_SATA_P0IS_UFS      4
#define BM_SATA_P0IS_UFS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_UFS(v)   ((((reg32_t) v) << 4) & BM_SATA_P0IS_UFS)
#else
#define BF_SATA_P0IS_UFS(v)   (((v) << 4) & BM_SATA_P0IS_UFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_UFS(v)   BF_CS1(SATA_P0IS, UFS, v)
#endif

/* --- Register HW_SATA_P0IS, field DPS
 *
 * Descriptor Processed  A PRD with the I bit set has transferred all of its data.  This is an
 * opportunistic interrupt and must not be used to                                 definitively
 * indicate the end of a transfer. Two PRD interrupts                                 could happen
 * close in time together such that the second interrupt                                 is missed
 * when the first PRD interrupt is being cleared.
 */

#define BP_SATA_P0IS_DPS      5
#define BM_SATA_P0IS_DPS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_DPS(v)   ((((reg32_t) v) << 5) & BM_SATA_P0IS_DPS)
#else
#define BF_SATA_P0IS_DPS(v)   (((v) << 5) & BM_SATA_P0IS_DPS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_DPS(v)   BF_CS1(SATA_P0IS, DPS, v)
#endif

/* --- Register HW_SATA_P0IS, field PCS
 *
 * Port Connect Change Status  This bit is cleared only when SATA_P #  0 SERR[DIAG_X] is cleared.
 * This bit reflects the state of the SATA_P #  0 SERR[DIAG_X] bit:
 */

#define BP_SATA_P0IS_PCS      6
#define BM_SATA_P0IS_PCS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_PCS(v)   ((((reg32_t) v) << 6) & BM_SATA_P0IS_PCS)
#else
#define BF_SATA_P0IS_PCS(v)   (((v) << 6) & BM_SATA_P0IS_PCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_PCS(v)   BF_CS1(SATA_P0IS, PCS, v)
#endif

/* --- Register HW_SATA_P0IS, field PRCS
 *
 * PHY Ready Change Status  This bit reflects the state of the SATA_P #  0 SERR[DIAG_N] bit.  When
 * set to 1, indicates the internal p #  0 _phy_ready signal changed
 * state.  To clear this bit, the software must clear the SATA_P #  0 SERR[DIAG_N] bit to 0.
 */

#define BP_SATA_P0IS_PRCS      22
#define BM_SATA_P0IS_PRCS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_PRCS(v)   ((((reg32_t) v) << 22) & BM_SATA_P0IS_PRCS)
#else
#define BF_SATA_P0IS_PRCS(v)   (((v) << 22) & BM_SATA_P0IS_PRCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_PRCS(v)   BF_CS1(SATA_P0IS, PRCS, v)
#endif

/* --- Register HW_SATA_P0IS, field IPMS
 *
 * Incorrect Port Multiplier Status.  Indicates that the HBA received a FIS from a device whose Port
 * Multiplier field did not match what was expected.  This bit may be set during enumeration of
 * devices on a Port                                 Multiplier due to the normal Port Multiplier
 * enumeration                                 process.  The software must use the IPMS bit only
 * after enumeration is complete                                 on the  Port Multiplier.
 */

#define BP_SATA_P0IS_IPMS      23
#define BM_SATA_P0IS_IPMS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_IPMS(v)   ((((reg32_t) v) << 23) & BM_SATA_P0IS_IPMS)
#else
#define BF_SATA_P0IS_IPMS(v)   (((v) << 23) & BM_SATA_P0IS_IPMS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_IPMS(v)   BF_CS1(SATA_P0IS, IPMS, v)
#endif

/* --- Register HW_SATA_P0IS, field OFS
 *
 * Overflow Status  This bit is set when command list overflow is detected during read or
 * write operation when the software builds command table that has
 * fever total bytes than the transaction given to the device.  Port DMA transitions to a fatal
 * state until the software clears                                     SATA_P #  0 CMD[ST] bit or
 * resets the interface by way of Port or                                 Global reset.
 */

#define BP_SATA_P0IS_OFS      24
#define BM_SATA_P0IS_OFS      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_OFS(v)   ((((reg32_t) v) << 24) & BM_SATA_P0IS_OFS)
#else
#define BF_SATA_P0IS_OFS(v)   (((v) << 24) & BM_SATA_P0IS_OFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_OFS(v)   BF_CS1(SATA_P0IS, OFS, v)
#endif

/* --- Register HW_SATA_P0IS, field INFS
 *
 * Interface Non-fatal Error Status  This bit is set when any of the following conditions is
 * detected:  • One or more of the following errors are detected during non-data
 * FIS  transfer  - 10B to 8B Decode Error (SATA_P #  0 SERR[DIAG_B])  - Protocol (SATA_P #  0
 * SERR[ERR_P])  - CRC (SATA_P #  0 SERR[DIAG_C]),  - Handshake (SATA_P #  0 SERR[DIAG_H])  - PHY
 * Not Ready (SATA_P #  0 SERR[ERR_C]);  • Command list underflow during read operation (i.e. DMA
 * read) when                                 the software builds command table that has more total
 * bytes than the                                 transaction given to the device.
 */

#define BP_SATA_P0IS_INFS      26
#define BM_SATA_P0IS_INFS      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_INFS(v)   ((((reg32_t) v) << 26) & BM_SATA_P0IS_INFS)
#else
#define BF_SATA_P0IS_INFS(v)   (((v) << 26) & BM_SATA_P0IS_INFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_INFS(v)   BF_CS1(SATA_P0IS, INFS, v)
#endif

/* --- Register HW_SATA_P0IS, field IFS
 *
 * Interface Fatal Error Status  This bit is set when any of the following conditions is detected:
 * • SYNC escape is received from the device during H2D Register or Data
 * FIS  transmission;  • One or more of the following errors are detected during Data FIS
 * transfer:  - 10B to 8B Decode Error (SATA_P #  0 SERR[DIAG_B])  - Protocol (SATA_P #  0
 * SERR[ERR_P])  - CRC (SATA_P #  0 SERR[DIAG_C])  - Handshake (SATA_P #  0 SERR[DIAG_H])  - PHY Not
 * Ready (SATA_P #  0 SERR[ERR_C])  • Unknown FIS is received with good CRC, but the length exceeds
 * 64                                 bytes;  • PRD table byte count is zero.  Port DMA transitions
 * to a fatal state until the software clears                                     SATA_P #  0
 * CMD[ST] bit or resets the interface by way of Port or                                 Global
 * reset.
 */

#define BP_SATA_P0IS_IFS      27
#define BM_SATA_P0IS_IFS      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_IFS(v)   ((((reg32_t) v) << 27) & BM_SATA_P0IS_IFS)
#else
#define BF_SATA_P0IS_IFS(v)   (((v) << 27) & BM_SATA_P0IS_IFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_IFS(v)   BF_CS1(SATA_P0IS, IFS, v)
#endif

/* --- Register HW_SATA_P0IS, field HBDS
 *
 * Host Bus Data Error Status.  This bit is always cleared to 0.
 */

#define BP_SATA_P0IS_HBDS      28
#define BM_SATA_P0IS_HBDS      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_HBDS(v)   ((((reg32_t) v) << 28) & BM_SATA_P0IS_HBDS)
#else
#define BF_SATA_P0IS_HBDS(v)   (((v) << 28) & BM_SATA_P0IS_HBDS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_HBDS(v)   BF_CS1(SATA_P0IS, HBDS, v)
#endif

/* --- Register HW_SATA_P0IS, field HBFS
 *
 * Host Bus Fatal Error Status.  This bit is set when SATA block AHB Master detects an ERROR
 * response                                 from the slave.
 */

#define BP_SATA_P0IS_HBFS      29
#define BM_SATA_P0IS_HBFS      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_HBFS(v)   ((((reg32_t) v) << 29) & BM_SATA_P0IS_HBFS)
#else
#define BF_SATA_P0IS_HBFS(v)   (((v) << 29) & BM_SATA_P0IS_HBFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_HBFS(v)   BF_CS1(SATA_P0IS, HBFS, v)
#endif

/* --- Register HW_SATA_P0IS, field TFES
 *
 * Task File Error Status.  This bit is set whenever the SATA_P #  0 TFD[STS] register is updated by
 * the                                 device and the error bit (bit 0) is set.
 */

#define BP_SATA_P0IS_TFES      30
#define BM_SATA_P0IS_TFES      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IS_TFES(v)   ((((reg32_t) v) << 30) & BM_SATA_P0IS_TFES)
#else
#define BF_SATA_P0IS_TFES(v)   (((v) << 30) & BM_SATA_P0IS_TFES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IS_TFES(v)   BF_CS1(SATA_P0IS, TFES, v)
#endif

/*!
 * @brief HW_SATA_P0IE - Port0 Interrupt Enable Register
 *
 * This register enables and disables the reporting of the corresponding
 * interrupt to the software. When a bit is set (1), and the corresponding
 * interrupt condition is active, then the SATA block intrq output is
 * asserted. Interrupt sources that are disabled (0) are still reflected in
 * the status registers. This register is symmetrical with the SATA_P #  0 IS register.
 * This register is reset on Global SATA block reset.   Size: 32 bits  Address offset: for # = 0 to
 * 7:   P0IE: 0x114  P0IE: 0x194  P0IE: 0x214  P0IE: 0x294  P0IE: 0x314  P0IE: 0x394  P0IE: 0x414
 * P0IE: 0x494    Read/write access: Read/write  Reset: 0x0000_0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DHRE : 1; //!< Device to Host Register FIS Interrupt  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[DHRS]=1
        unsigned PSE : 1; //!< PIO Setup FIS Interrupt Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[PSS]=1
        unsigned DSE : 1; //!< DMA Setup FIS Interrupt Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[DSS]=1
        unsigned SDBE : 1; //!< Set Device Bits FIS Interrupt Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[SDBS]=1
        unsigned UFE : 1; //!< Unknown FIS Interrupt Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[UFS]=1
        unsigned DPE : 1; //!< Descriptor Processed Interrupt Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[DPS]=1
        unsigned PCE : 1; //!< Port Change Interrupt Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[PCS]=1
        unsigned RESERVED0 : 1; //!< Reserved Returns 0 on .read.
        unsigned RESERVED1 : 14; //!< Reserved.
        unsigned PRCE : 1; //!< PHY Ready Change Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[PRCS]=1
        unsigned IPME : 1; //!< Incorrect Port Multiplier Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[IPMS]=1
        unsigned OFE : 1; //!< Overflow Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[OFS]=1
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned INFE : 1; //!< Interface Non-Fatal Error Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[INFS]=1
        unsigned IFE : 1; //!< Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[IFS]=1
        unsigned HBDE : 1; //!< Host Bus Data Error Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[HBDS]=1
        unsigned HBFE : 1; //!< Host Bus Fatal Error Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[HBFS]=1
        unsigned TFEE : 1; //!< Task File Error Enable  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[TFES]=1
        unsigned CPDE : 1; //!< Cold Port Detect Enable  Read-only. Returns 0.  The options for this field are:  • When DEV_CP_DET=Include, this bit is read/write.  • When DEV_CP_DET=Exclude, this bit is read-only 0.  Dependencies: when the following conditions are true, the intrq output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1   • P#IS[CPDS]=1
    } B;
} hw_sata_p0ie_t;
#endif

/*
 * constants & macros for entire SATA_P0IE register
 */
#define HW_SATA_P0IE_ADDR      (REGS_SATA_BASE + 0x114)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0IE           (*(volatile hw_sata_p0ie_t *) HW_SATA_P0IE_ADDR)
#define HW_SATA_P0IE_RD()      (HW_SATA_P0IE.U)
#define HW_SATA_P0IE_WR(v)     (HW_SATA_P0IE.U = (v))
#define HW_SATA_P0IE_SET(v)    (HW_SATA_P0IE_WR(HW_SATA_P0IE_RD() |  (v)))
#define HW_SATA_P0IE_CLR(v)    (HW_SATA_P0IE_WR(HW_SATA_P0IE_RD() & ~(v)))
#define HW_SATA_P0IE_TOG(v)    (HW_SATA_P0IE_WR(HW_SATA_P0IE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0IE bitfields
 */

/* --- Register HW_SATA_P0IE, field DHRE
 *
 * Device to Host Register FIS Interrupt  Dependencies: when the following conditions are true, the
 * intrq                                 output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1
 * • SATA_P #  0 IS[DHRS]=1
 */

#define BP_SATA_P0IE_DHRE      0
#define BM_SATA_P0IE_DHRE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_DHRE(v)   ((((reg32_t) v) << 0) & BM_SATA_P0IE_DHRE)
#else
#define BF_SATA_P0IE_DHRE(v)   (((v) << 0) & BM_SATA_P0IE_DHRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_DHRE(v)   BF_CS1(SATA_P0IE, DHRE, v)
#endif

/* --- Register HW_SATA_P0IE, field PSE
 *
 * PIO Setup FIS Interrupt Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[PSS]=1
 */

#define BP_SATA_P0IE_PSE      1
#define BM_SATA_P0IE_PSE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_PSE(v)   ((((reg32_t) v) << 1) & BM_SATA_P0IE_PSE)
#else
#define BF_SATA_P0IE_PSE(v)   (((v) << 1) & BM_SATA_P0IE_PSE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_PSE(v)   BF_CS1(SATA_P0IE, PSE, v)
#endif

/* --- Register HW_SATA_P0IE, field DSE
 *
 * DMA Setup FIS Interrupt Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[DSS]=1
 */

#define BP_SATA_P0IE_DSE      2
#define BM_SATA_P0IE_DSE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_DSE(v)   ((((reg32_t) v) << 2) & BM_SATA_P0IE_DSE)
#else
#define BF_SATA_P0IE_DSE(v)   (((v) << 2) & BM_SATA_P0IE_DSE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_DSE(v)   BF_CS1(SATA_P0IE, DSE, v)
#endif

/* --- Register HW_SATA_P0IE, field SDBE
 *
 * Set Device Bits FIS Interrupt Enable  Dependencies: when the following conditions are true, the
 * intrq                                 output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1
 * • SATA_P #  0 IS[SDBS]=1
 */

#define BP_SATA_P0IE_SDBE      3
#define BM_SATA_P0IE_SDBE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_SDBE(v)   ((((reg32_t) v) << 3) & BM_SATA_P0IE_SDBE)
#else
#define BF_SATA_P0IE_SDBE(v)   (((v) << 3) & BM_SATA_P0IE_SDBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_SDBE(v)   BF_CS1(SATA_P0IE, SDBE, v)
#endif

/* --- Register HW_SATA_P0IE, field UFE
 *
 * Unknown FIS Interrupt Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[UFS]=1
 */

#define BP_SATA_P0IE_UFE      4
#define BM_SATA_P0IE_UFE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_UFE(v)   ((((reg32_t) v) << 4) & BM_SATA_P0IE_UFE)
#else
#define BF_SATA_P0IE_UFE(v)   (((v) << 4) & BM_SATA_P0IE_UFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_UFE(v)   BF_CS1(SATA_P0IE, UFE, v)
#endif

/* --- Register HW_SATA_P0IE, field DPE
 *
 * Descriptor Processed Interrupt Enable  Dependencies: when the following conditions are true, the
 * intrq                                 output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1
 * • SATA_P #  0 IS[DPS]=1
 */

#define BP_SATA_P0IE_DPE      5
#define BM_SATA_P0IE_DPE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_DPE(v)   ((((reg32_t) v) << 5) & BM_SATA_P0IE_DPE)
#else
#define BF_SATA_P0IE_DPE(v)   (((v) << 5) & BM_SATA_P0IE_DPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_DPE(v)   BF_CS1(SATA_P0IE, DPE, v)
#endif

/* --- Register HW_SATA_P0IE, field PCE
 *
 * Port Change Interrupt Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[PCS]=1
 */

#define BP_SATA_P0IE_PCE      6
#define BM_SATA_P0IE_PCE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_PCE(v)   ((((reg32_t) v) << 6) & BM_SATA_P0IE_PCE)
#else
#define BF_SATA_P0IE_PCE(v)   (((v) << 6) & BM_SATA_P0IE_PCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_PCE(v)   BF_CS1(SATA_P0IE, PCE, v)
#endif

/* --- Register HW_SATA_P0IE, field PRCE
 *
 * PHY Ready Change Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[PRCS]=1
 */

#define BP_SATA_P0IE_PRCE      22
#define BM_SATA_P0IE_PRCE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_PRCE(v)   ((((reg32_t) v) << 22) & BM_SATA_P0IE_PRCE)
#else
#define BF_SATA_P0IE_PRCE(v)   (((v) << 22) & BM_SATA_P0IE_PRCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_PRCE(v)   BF_CS1(SATA_P0IE, PRCE, v)
#endif

/* --- Register HW_SATA_P0IE, field IPME
 *
 * Incorrect Port Multiplier Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[IPMS]=1
 */

#define BP_SATA_P0IE_IPME      23
#define BM_SATA_P0IE_IPME      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_IPME(v)   ((((reg32_t) v) << 23) & BM_SATA_P0IE_IPME)
#else
#define BF_SATA_P0IE_IPME(v)   (((v) << 23) & BM_SATA_P0IE_IPME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_IPME(v)   BF_CS1(SATA_P0IE, IPME, v)
#endif

/* --- Register HW_SATA_P0IE, field OFE
 *
 * Overflow Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[OFS]=1
 */

#define BP_SATA_P0IE_OFE      24
#define BM_SATA_P0IE_OFE      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_OFE(v)   ((((reg32_t) v) << 24) & BM_SATA_P0IE_OFE)
#else
#define BF_SATA_P0IE_OFE(v)   (((v) << 24) & BM_SATA_P0IE_OFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_OFE(v)   BF_CS1(SATA_P0IE, OFE, v)
#endif

/* --- Register HW_SATA_P0IE, field INFE
 *
 * Interface Non-Fatal Error Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[INFS]=1
 */

#define BP_SATA_P0IE_INFE      26
#define BM_SATA_P0IE_INFE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_INFE(v)   ((((reg32_t) v) << 26) & BM_SATA_P0IE_INFE)
#else
#define BF_SATA_P0IE_INFE(v)   (((v) << 26) & BM_SATA_P0IE_INFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_INFE(v)   BF_CS1(SATA_P0IE, INFE, v)
#endif

/* --- Register HW_SATA_P0IE, field IFE
 *
 * Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[IFS]=1
 */

#define BP_SATA_P0IE_IFE      27
#define BM_SATA_P0IE_IFE      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_IFE(v)   ((((reg32_t) v) << 27) & BM_SATA_P0IE_IFE)
#else
#define BF_SATA_P0IE_IFE(v)   (((v) << 27) & BM_SATA_P0IE_IFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_IFE(v)   BF_CS1(SATA_P0IE, IFE, v)
#endif

/* --- Register HW_SATA_P0IE, field HBDE
 *
 * Host Bus Data Error Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[HBDS]=1
 */

#define BP_SATA_P0IE_HBDE      28
#define BM_SATA_P0IE_HBDE      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_HBDE(v)   ((((reg32_t) v) << 28) & BM_SATA_P0IE_HBDE)
#else
#define BF_SATA_P0IE_HBDE(v)   (((v) << 28) & BM_SATA_P0IE_HBDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_HBDE(v)   BF_CS1(SATA_P0IE, HBDE, v)
#endif

/* --- Register HW_SATA_P0IE, field HBFE
 *
 * Host Bus Fatal Error Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[HBFS]=1
 */

#define BP_SATA_P0IE_HBFE      29
#define BM_SATA_P0IE_HBFE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_HBFE(v)   ((((reg32_t) v) << 29) & BM_SATA_P0IE_HBFE)
#else
#define BF_SATA_P0IE_HBFE(v)   (((v) << 29) & BM_SATA_P0IE_HBFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_HBFE(v)   BF_CS1(SATA_P0IE, HBFE, v)
#endif

/* --- Register HW_SATA_P0IE, field TFEE
 *
 * Task File Error Enable  Dependencies: when the following conditions are true, the intrq
 * output signal is asserted:  • This bit=1  • SATA_GHC[IE]=1  • SATA_P #  0 IS[TFES]=1
 */

#define BP_SATA_P0IE_TFEE      30
#define BM_SATA_P0IE_TFEE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_TFEE(v)   ((((reg32_t) v) << 30) & BM_SATA_P0IE_TFEE)
#else
#define BF_SATA_P0IE_TFEE(v)   (((v) << 30) & BM_SATA_P0IE_TFEE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_TFEE(v)   BF_CS1(SATA_P0IE, TFEE, v)
#endif

/* --- Register HW_SATA_P0IE, field CPDE
 *
 * Cold Port Detect Enable  Read-only. Returns 0.  The options for this field are:  • When
 * DEV_CP_DET=Include, this bit is                                 read/write.  • When
 * DEV_CP_DET=Exclude, this bit is read-only                                 0.  Dependencies: when
 * the following conditions are                                 true, the intrq output signal is
 * asserted:  • This bit=1  • SATA_GHC[IE]=1   • P#IS[CPDS]=1
 */

#define BP_SATA_P0IE_CPDE      31
#define BM_SATA_P0IE_CPDE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0IE_CPDE(v)   ((((reg32_t) v) << 31) & BM_SATA_P0IE_CPDE)
#else
#define BF_SATA_P0IE_CPDE(v)   (((v) << 31) & BM_SATA_P0IE_CPDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0IE_CPDE(v)   BF_CS1(SATA_P0IE, CPDE, v)
#endif

/*!
 * @brief HW_SATA_P0CMD - Port0 Command Register
 *
 * This register contains bits controlling various Port functions. All RW
 * bits are reset on Global reset.   Size: 32 bits  Address offset: for # = 0 to 7:  P0CMD: 0x118
 * P1CMD: 0x198  P2CMD: 0x218  P3CMD: 0x298  P4CMD: 0x318  P5CMD: 0x398  P6CMD: 0x418  P7CMD: 0x498
 * Read/write access: (See table below)  Reset: 0x0000_0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ST : 1; //!< Start  When set to 1, the Port processes the command list. When cleared, the Port does not process the command list. Whenever this bit is changed from a 0 to a 1, the Port starts processing the command list at entry'0. Whenever this bit is changed from a 1 to a 0, the SATA_P #  0 CI register is cleared by the Port upon transition into an idle state. Refer to AHCI specification, section 10.3.1, for important restrictions on when this bit can be set to 1.  Note: SATA_P #  0 SERR register must be cleared prior to setting ST bit to 1.
        unsigned SUD : 1; //!< Spin-Up Device  This bit is read/write when staggered spin-up is supported as indicated by the SATA_CAP[SSS]=1. This bit is read-only 1 when staggered spin-up is not supported and SATA_CAP[SSS]=0. On an edge detect from 0 to 1, the Port starts a COMRESET initialization sequence to the device. Clearing this bit causes no action on the interface.  Note: The SUD bit is read-only 0 on power-up until SATA_CAP[SSS] bit is written with the required value.
        unsigned POD : 1; //!< Power On Device  This bit is read/write when cold presence detection is supported on this Port as indicated by SATA_P #  0 CMD[CPD]=1. This bit is read-only 1 when cold presence detection is not supported and SATA_P #  0 CMD[CPD]=0. When set, the Port asserts the p #  0 _cp_pod output pin so that it may be used to provide power to a cold-presence detectable Port.
        unsigned CLO : 1; //!< Command List Override  Setting this bit to 1 causes the SATA_P #  0 TFD[STS] field BSY bit and the SATA_P #  0 TFD[STS] field DRQ bit to be cleared. This allows a software reset to be transmitted to the device regardless of whether the BSY and DRQ bits are still set in the SATA_P #  0 TFD[STS] field. This bit is cleared to 0 when SATA_P #  0 TFD[STS] BSY bit and SATA_P #  0 TFD[STS] DRQ bit have been cleared. A write to this register with a value of '0' has no effect.  This bit should only be set to 1 immediately prior to setting SATA_P #  0 CMD[ST] bit to 1 from a previous value of 0. Setting this bit to 1 at any other time is not supported and results in indeterminate behavior.
        unsigned FRE : 1; //!< FIS Receive Enable  When set to 1, the Port may post received FISes into the FIS receive area pointed to by SATA_P #  0 FB (and P#FBU when M_HADDR_WIDTH=64) . When cleared, received FISes are not accepted by the Port, except for the first D2H register FIS after the initialization sequence, and no FISes are posted to the FIS receive area.  The software must not set this bit until SATA_P #  0 FB (P#FBU) has been programmed with a valid pointer to the FIS receive area  When the software wishes to move the base, this bit must first be cleared, and the software must wait for the SATA_P #  0 CMD[FR] bit to be cleared.
        unsigned RESERVED0 : 3; //!< Reserved.
        unsigned CCS : 5; //!< Current Command Slot  This field is set to the command slot value value of the command that is currently being issued by the Port.  • When SATA_P #  0 CMD[ST] transitions from 1 to 0, this field is recleared to  0x00.  • After SATA_P #  0 CMD[ST] transitions from 0 to 1, the highest priority slot to issue from next is command slot 0.  After the first command has been issued, the highest priority slot to issue from next is SATA_P #  0 CMD[CCS]+1.For example, after the Port has issued its first command, when CCS=0x00 and SATA_P #  0 CI is cleared to 0x3, the next command issued is from command slot 1.  This field is valid only when SATA_P #  0 CMD[ST] is set to 1.
        unsigned MPSS : 1; //!< Mechanical Presence Switch State  The software must use this bit only when both SATA_CAP[SMPS] and SATA_P #  0 CMD[MPSP] are set.  This bit reports the state of a mechanical presence switch attached to this Port as indicated by the p #  0 _mp_switch input state (assuming SATA_CAP[SMPS]=1 and SATA_P #  0 CMD[MPSP]=1).  The options for this field are:  When SATA_CAP[SMPS]=0 then this bit is cleared to 0.
        unsigned FR : 1; //!< FIS Receive Running  When set to '1', the FIS Receive DMA engine for the Port is running. See AHCI specification section 10.3.2 for details on when this bit is set and cleared by the Port.
        unsigned CR : 1; //!< Command List Running  When this bit is set to '1', the command list DMA engine for this Port is running. See AHCI state machine in AHCI specification section 5.3.2 (this is a reference to an external document) for details on when this bit is set and cleared by the Port.
        unsigned CPS : 1; //!< Cold Presence State  This bit reports whether a device is currently detected on this Port as indicated by the p #  0 _cp_det input state (assuming SATA_P #  0 CMD[CPD]=1).  The options for this field are:
        unsigned PMA : 1; //!< Port Multiplier Attached  The software is responsible for detecting whether a Port Multiplier is present; the SATA block Port does not auto-detect the presence of a Port Multiplier.  The options for this field are:
        unsigned HPCP : 1; //!< Hot Plug Capable Port  The HPCP bit is mutually exclusive with SATA_P #  0 CMD[ESP].  The options for this field are:
        unsigned RESERVED1 : 1; //!< Reserved. Returns 0 on read.
        unsigned RESERVED2 : 1; //!< Reserved. Returns 0 on read.
        unsigned ESP : 1; //!< External SATA Port  When set to 1, indicates that this Port's signal only connector is externally accessible. When set to 1, SATA_CAP[SXS] is also set to 1.  When cleared to 0, indicates that this Port's signal only connector is not externally accessible.  Note: The ESP bit is mutually exclusive with SATA_P #  0 CMD[HPCP]
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned APSTE : 1; //!< Device is ATAPI  This bit is used by the Port to control whether to assert p #  0 _act_led output when commands are active (see " ) . The options for this field are:
        unsigned ATAPI : 1; //!< ATAPI Device is ATAPI  This bit is used by the Port to control whether to assert p #  0 _act_led output when commands are active (see " ) . The options for this field are:
        unsigned DLAE : 1; //!< Drive LED on ATAPI Enable  When set to 1, SATA_P #  0 CMD[ATAPI]=1, and commands are active, the Port asserts p #  0 _act_led output (see " ) .
        unsigned ALPE : 1; //!< Aggressive Link Power Management Enable  When set to 1, the Port aggressively enters a lower link power state (PARTIAL or SLUMBER) based on the setting of the SATA_P #  0 CMD[ASP] bit. When cleared to 0, aggressive power management state transition is  disabled.
        unsigned ASP : 1; //!< Aggressive Slumber/ Partial  The options for this field are:  • When set to 1, and SATA_P #  0 CMD[ALPE]=1, the Port aggressively enters the SLUMBER state when one of the following conditions is true:  - The Port clears the SATA_P #  0 CI and the SATA_P #  0 SACT register is cleared.  - The Port clears the SATA_P #  0 SACT register and SATA_P #  0 CI is cleared.  • When cleared to 0, and SATA_P #  0 CMD[ALPE]=1, the Port aggressively enters the PARTIAL state when one of the following conditions is true:  - The Port clears the SATA_P #  0 CI register and the SATA_P #  0 SACT register is cleared.  - The Port clears the SATA_P #  0 SACT register and SATA_P #  0 CI is cleared.
        unsigned ICC : 4; //!< Interface Communication Control  This field is used to control power management states of the interface. When the Link layer is currently in the L_IDLE state, writes to this field cause the Port to initiate a transition to the interface power management state requested. When the Link layer is not currently in the L_IDLE state, writes to this field have no effect.  • 0xF-0x7: Reserved  • 0x6: Slumber. This causes the Port to request a transition of the interface to the Slumber state. The SATA device can reject the request and the interface remains in its current state.  • 0x5-0x3: Reserved  • 0x2: Partial. This causes the Port to request a transition of the interface to the Partial state. The SATA device can reject the request and the interface remains in its current state.  • 0x1: Active. This causes the Port to request a transition of the interface into the active state.  • 0x0: No-Op/ Idle. This value indicates to the software that the Port #  0 is ready to accept a new interface control command, although the transition to the previously selected state may not yet have occurred.  When the software writes a non-reserved value other than No-Op (0x0), the Port performs the action and update this field back to Idle (0x0).  When the software writes to this field to change the state to a state the link is already in (i.e., interface is in the active state and a request is made to go to the active state), the Port takes no action and returns this field to Idle. When the interface is in a low power state and the software wants to transition to a different low power state, the software must first bring the link to active and then initiate the transition to the desired low power state.
    } B;
} hw_sata_p0cmd_t;
#endif

/*
 * constants & macros for entire SATA_P0CMD register
 */
#define HW_SATA_P0CMD_ADDR      (REGS_SATA_BASE + 0x118)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0CMD           (*(volatile hw_sata_p0cmd_t *) HW_SATA_P0CMD_ADDR)
#define HW_SATA_P0CMD_RD()      (HW_SATA_P0CMD.U)
#define HW_SATA_P0CMD_WR(v)     (HW_SATA_P0CMD.U = (v))
#define HW_SATA_P0CMD_SET(v)    (HW_SATA_P0CMD_WR(HW_SATA_P0CMD_RD() |  (v)))
#define HW_SATA_P0CMD_CLR(v)    (HW_SATA_P0CMD_WR(HW_SATA_P0CMD_RD() & ~(v)))
#define HW_SATA_P0CMD_TOG(v)    (HW_SATA_P0CMD_WR(HW_SATA_P0CMD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0CMD bitfields
 */

/* --- Register HW_SATA_P0CMD, field ST
 *
 * Start  When set to 1, the Port processes the command list. When cleared, the
 * Port does not process the command list. Whenever this bit is changed
 * from a 0 to a 1, the Port starts processing the command list at
 * entry'0. Whenever this bit is changed from a 1 to a 0, the SATA_P #  0 CI
 * register is cleared by the Port upon transition into an idle state.
 * Refer to AHCI specification, section 10.3.1, for important
 * restrictions on when this bit can be set to 1.  Note: SATA_P #  0 SERR register must be cleared
 * prior to setting ST bit to                                 1.
 */

#define BP_SATA_P0CMD_ST      0
#define BM_SATA_P0CMD_ST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_ST(v)   ((((reg32_t) v) << 0) & BM_SATA_P0CMD_ST)
#else
#define BF_SATA_P0CMD_ST(v)   (((v) << 0) & BM_SATA_P0CMD_ST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_ST(v)   BF_CS1(SATA_P0CMD, ST, v)
#endif

/* --- Register HW_SATA_P0CMD, field SUD
 *
 * Spin-Up Device  This bit is read/write when staggered spin-up is supported as
 * indicated by the SATA_CAP[SSS]=1. This bit is read-only 1 when
 * staggered spin-up is not supported and SATA_CAP[SSS]=0. On an edge
 * detect from 0 to 1, the Port starts a COMRESET initialization
 * sequence to the device. Clearing this bit causes no action on the
 * interface.  Note: The SUD bit is read-only 0 on power-up until SATA_CAP[SSS] bit
 * is written with the required value.
 */

#define BP_SATA_P0CMD_SUD      1
#define BM_SATA_P0CMD_SUD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_SUD(v)   ((((reg32_t) v) << 1) & BM_SATA_P0CMD_SUD)
#else
#define BF_SATA_P0CMD_SUD(v)   (((v) << 1) & BM_SATA_P0CMD_SUD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_SUD(v)   BF_CS1(SATA_P0CMD, SUD, v)
#endif

/* --- Register HW_SATA_P0CMD, field POD
 *
 * Power On Device  This bit is read/write when cold presence detection is supported on
 * this Port as indicated by SATA_P #  0 CMD[CPD]=1. This bit is read-only 1
 * when cold presence detection is not supported and SATA_P #  0 CMD[CPD]=0. When set, the Port
 * asserts the p #  0 _cp_pod                                 output pin so that it may be used to
 * provide power to a                                 cold-presence detectable Port.
 */

#define BP_SATA_P0CMD_POD      2
#define BM_SATA_P0CMD_POD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_POD(v)   ((((reg32_t) v) << 2) & BM_SATA_P0CMD_POD)
#else
#define BF_SATA_P0CMD_POD(v)   (((v) << 2) & BM_SATA_P0CMD_POD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_POD(v)   BF_CS1(SATA_P0CMD, POD, v)
#endif

/* --- Register HW_SATA_P0CMD, field CLO
 *
 * Command List Override  Setting this bit to 1 causes the SATA_P #  0 TFD[STS] field BSY bit and
 * the SATA_P #  0 TFD[STS] field DRQ bit to be cleared. This allows a
 * software reset to be transmitted to the device regardless of whether
 * the BSY and DRQ bits are still set in the SATA_P #  0 TFD[STS]
 * field. This bit is cleared to 0 when SATA_P #  0 TFD[STS] BSY bit and
 * SATA_P #  0 TFD[STS] DRQ bit have been cleared. A write to this
 * register with a value of '0' has no effect.  This bit should only be set to 1 immediately prior
 * to setting                                     SATA_P #  0 CMD[ST] bit to 1 from a previous value
 * of 0. Setting this                                 bit to 1 at any other time is not supported
 * and results in                                 indeterminate behavior.
 */

#define BP_SATA_P0CMD_CLO      3
#define BM_SATA_P0CMD_CLO      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_CLO(v)   ((((reg32_t) v) << 3) & BM_SATA_P0CMD_CLO)
#else
#define BF_SATA_P0CMD_CLO(v)   (((v) << 3) & BM_SATA_P0CMD_CLO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_CLO(v)   BF_CS1(SATA_P0CMD, CLO, v)
#endif

/* --- Register HW_SATA_P0CMD, field FRE
 *
 * FIS Receive Enable  When set to 1, the Port may post received FISes into the FIS receive
 * area pointed to by SATA_P #  0 FB (and P#FBU                                     when
 * M_HADDR_WIDTH=64) . When cleared, received FISes are                                 not accepted
 * by the Port, except for the first D2H register FIS                                 after the
 * initialization sequence, and no FISes are posted to the                                 FIS
 * receive area.  The software must not set this bit until SATA_P #  0 FB (P#FBU) has been
 * programmed with a valid pointer to the                                 FIS receive area  When the
 * software wishes to move the base, this bit must first be                                 cleared,
 * and the software must wait for the SATA_P #  0 CMD[FR]                                 bit to be
 * cleared.
 */

#define BP_SATA_P0CMD_FRE      4
#define BM_SATA_P0CMD_FRE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_FRE(v)   ((((reg32_t) v) << 4) & BM_SATA_P0CMD_FRE)
#else
#define BF_SATA_P0CMD_FRE(v)   (((v) << 4) & BM_SATA_P0CMD_FRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_FRE(v)   BF_CS1(SATA_P0CMD, FRE, v)
#endif

/* --- Register HW_SATA_P0CMD, field CCS
 *
 * Current Command Slot  This field is set to the command slot value value of the command that
 * is currently being issued by the Port.  • When SATA_P #  0 CMD[ST] transitions from 1 to 0, this
 * field is recleared                                 to  0x00.  • After SATA_P #  0 CMD[ST]
 * transitions from 0 to 1, the highest priority                                 slot to issue from
 * next is command slot 0.  After the first command has been issued, the highest priority slot to
 * issue from next is SATA_P #  0 CMD[CCS]+1.For example, after the Port
 * has issued its first command, when CCS=0x00 and SATA_P #  0 CI is
 * cleared to 0x3, the next command issued is from command slot 1.  This field is valid only when
 * SATA_P #  0 CMD[ST] is set to 1.
 */

#define BP_SATA_P0CMD_CCS      8
#define BM_SATA_P0CMD_CCS      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_CCS(v)   ((((reg32_t) v) << 8) & BM_SATA_P0CMD_CCS)
#else
#define BF_SATA_P0CMD_CCS(v)   (((v) << 8) & BM_SATA_P0CMD_CCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_CCS(v)   BF_CS1(SATA_P0CMD, CCS, v)
#endif

/* --- Register HW_SATA_P0CMD, field MPSS
 *
 * Mechanical Presence Switch State  The software must use this bit only when both SATA_CAP[SMPS]
 * and                                     SATA_P #  0 CMD[MPSP] are set.  This bit reports the
 * state of a mechanical presence switch attached                                 to this Port as
 * indicated by the p #  0 _mp_switch input state (assuming
 * SATA_CAP[SMPS]=1 and SATA_P #  0 CMD[MPSP]=1).  The options for this field are:  When
 * SATA_CAP[SMPS]=0 then this bit is cleared to 0.
 */

#define BP_SATA_P0CMD_MPSS      13
#define BM_SATA_P0CMD_MPSS      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_MPSS(v)   ((((reg32_t) v) << 13) & BM_SATA_P0CMD_MPSS)
#else
#define BF_SATA_P0CMD_MPSS(v)   (((v) << 13) & BM_SATA_P0CMD_MPSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_MPSS(v)   BF_CS1(SATA_P0CMD, MPSS, v)
#endif

/* --- Register HW_SATA_P0CMD, field FR
 *
 * FIS Receive Running  When set to '1', the FIS Receive DMA engine for the Port is running.
 * See AHCI specification section 10.3.2 for details on when this bit
 * is set and cleared by the Port.
 */

#define BP_SATA_P0CMD_FR      14
#define BM_SATA_P0CMD_FR      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_FR(v)   ((((reg32_t) v) << 14) & BM_SATA_P0CMD_FR)
#else
#define BF_SATA_P0CMD_FR(v)   (((v) << 14) & BM_SATA_P0CMD_FR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_FR(v)   BF_CS1(SATA_P0CMD, FR, v)
#endif

/* --- Register HW_SATA_P0CMD, field CR
 *
 * Command List Running  When this bit is set to '1', the command list DMA engine for this
 * Port is running. See AHCI state machine in AHCI specification
 * section 5.3.2 (this is a reference to an                                     external document)
 * for details on when this bit is set and                                 cleared by the Port.
 */

#define BP_SATA_P0CMD_CR      15
#define BM_SATA_P0CMD_CR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_CR(v)   ((((reg32_t) v) << 15) & BM_SATA_P0CMD_CR)
#else
#define BF_SATA_P0CMD_CR(v)   (((v) << 15) & BM_SATA_P0CMD_CR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_CR(v)   BF_CS1(SATA_P0CMD, CR, v)
#endif

/* --- Register HW_SATA_P0CMD, field CPS
 *
 * Cold Presence State  This bit reports whether a device is currently detected on this Port
 * as indicated by the p #  0 _cp_det input state (assuming
 * SATA_P #  0 CMD[CPD]=1).  The options for this field are:
 */

#define BP_SATA_P0CMD_CPS      16
#define BM_SATA_P0CMD_CPS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_CPS(v)   ((((reg32_t) v) << 16) & BM_SATA_P0CMD_CPS)
#else
#define BF_SATA_P0CMD_CPS(v)   (((v) << 16) & BM_SATA_P0CMD_CPS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_CPS(v)   BF_CS1(SATA_P0CMD, CPS, v)
#endif

/* --- Register HW_SATA_P0CMD, field PMA
 *
 * Port Multiplier Attached  The software is responsible for detecting whether a Port Multiplier
 * is present; the SATA block Port does not auto-detect the presence of
 * a Port Multiplier.  The options for this field are:
 */

#define BP_SATA_P0CMD_PMA      17
#define BM_SATA_P0CMD_PMA      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_PMA(v)   ((((reg32_t) v) << 17) & BM_SATA_P0CMD_PMA)
#else
#define BF_SATA_P0CMD_PMA(v)   (((v) << 17) & BM_SATA_P0CMD_PMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_PMA(v)   BF_CS1(SATA_P0CMD, PMA, v)
#endif

/* --- Register HW_SATA_P0CMD, field HPCP
 *
 * Hot Plug Capable Port  The HPCP bit is mutually exclusive with SATA_P #  0 CMD[ESP].  The options
 * for this field are:
 */

#define BP_SATA_P0CMD_HPCP      18
#define BM_SATA_P0CMD_HPCP      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_HPCP(v)   ((((reg32_t) v) << 18) & BM_SATA_P0CMD_HPCP)
#else
#define BF_SATA_P0CMD_HPCP(v)   (((v) << 18) & BM_SATA_P0CMD_HPCP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_HPCP(v)   BF_CS1(SATA_P0CMD, HPCP, v)
#endif

/* --- Register HW_SATA_P0CMD, field ESP
 *
 * External SATA Port  When set to 1, indicates that this Port's signal only connector is
 * externally accessible. When set to 1, SATA_CAP[SXS] is also set to
 * 1.  When cleared to 0, indicates that this Port's signal only connector
 * is not externally accessible.  Note: The ESP bit is mutually exclusive with SATA_P #  0 CMD[HPCP]
 */

#define BP_SATA_P0CMD_ESP      21
#define BM_SATA_P0CMD_ESP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_ESP(v)   ((((reg32_t) v) << 21) & BM_SATA_P0CMD_ESP)
#else
#define BF_SATA_P0CMD_ESP(v)   (((v) << 21) & BM_SATA_P0CMD_ESP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_ESP(v)   BF_CS1(SATA_P0CMD, ESP, v)
#endif

/* --- Register HW_SATA_P0CMD, field APSTE
 *
 * Device is ATAPI  This bit is used by the Port to control whether to assert p #  0 _act_led
 * output when commands are active (see                                     " ) . The
 * options for this field are:
 */

#define BP_SATA_P0CMD_APSTE      23
#define BM_SATA_P0CMD_APSTE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_APSTE(v)   ((((reg32_t) v) << 23) & BM_SATA_P0CMD_APSTE)
#else
#define BF_SATA_P0CMD_APSTE(v)   (((v) << 23) & BM_SATA_P0CMD_APSTE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_APSTE(v)   BF_CS1(SATA_P0CMD, APSTE, v)
#endif

/* --- Register HW_SATA_P0CMD, field ATAPI
 *
 * ATAPI Device is ATAPI  This bit is used by the Port to control whether to assert p #  0 _act_led
 * output when commands are active (see                                     " ) . The
 * options for this field are:
 */

#define BP_SATA_P0CMD_ATAPI      24
#define BM_SATA_P0CMD_ATAPI      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_ATAPI(v)   ((((reg32_t) v) << 24) & BM_SATA_P0CMD_ATAPI)
#else
#define BF_SATA_P0CMD_ATAPI(v)   (((v) << 24) & BM_SATA_P0CMD_ATAPI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_ATAPI(v)   BF_CS1(SATA_P0CMD, ATAPI, v)
#endif

/* --- Register HW_SATA_P0CMD, field DLAE
 *
 * Drive LED on ATAPI Enable  When set to 1, SATA_P #  0 CMD[ATAPI]=1, and commands are active,
 * the Port asserts p #  0 _act_led output (see                                     " ) .
 */

#define BP_SATA_P0CMD_DLAE      25
#define BM_SATA_P0CMD_DLAE      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_DLAE(v)   ((((reg32_t) v) << 25) & BM_SATA_P0CMD_DLAE)
#else
#define BF_SATA_P0CMD_DLAE(v)   (((v) << 25) & BM_SATA_P0CMD_DLAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_DLAE(v)   BF_CS1(SATA_P0CMD, DLAE, v)
#endif

/* --- Register HW_SATA_P0CMD, field ALPE
 *
 * Aggressive Link Power Management Enable  When set to 1, the Port aggressively enters a lower link
 * power state                                 (PARTIAL or SLUMBER) based on the setting of the
 * SATA_P #  0 CMD[ASP]                                 bit. When cleared to 0, aggressive power
 * management state transition                                 is  disabled.
 */

#define BP_SATA_P0CMD_ALPE      26
#define BM_SATA_P0CMD_ALPE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_ALPE(v)   ((((reg32_t) v) << 26) & BM_SATA_P0CMD_ALPE)
#else
#define BF_SATA_P0CMD_ALPE(v)   (((v) << 26) & BM_SATA_P0CMD_ALPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_ALPE(v)   BF_CS1(SATA_P0CMD, ALPE, v)
#endif

/* --- Register HW_SATA_P0CMD, field ASP
 *
 * Aggressive Slumber/ Partial  The options for this field are:  • When set to 1, and SATA_P #  0
 * CMD[ALPE]=1, the Port aggressively                                 enters the SLUMBER state when
 * one of the following conditions is                                 true:  - The Port clears the
 * SATA_P #  0 CI and the SATA_P #  0 SACT                                 register is cleared.  -
 * The Port clears the SATA_P #  0 SACT register and SATA_P #  0 CI is
 * cleared.  • When cleared to 0, and SATA_P #  0 CMD[ALPE]=1, the Port aggressively
 * enters the PARTIAL state when one of the following conditions is
 * true:  - The Port clears the SATA_P #  0 CI register and the SATA_P #  0 SACT
 * register is cleared.  - The Port clears the SATA_P #  0 SACT register and SATA_P #  0 CI is
 * cleared.
 */

#define BP_SATA_P0CMD_ASP      27
#define BM_SATA_P0CMD_ASP      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_ASP(v)   ((((reg32_t) v) << 27) & BM_SATA_P0CMD_ASP)
#else
#define BF_SATA_P0CMD_ASP(v)   (((v) << 27) & BM_SATA_P0CMD_ASP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_ASP(v)   BF_CS1(SATA_P0CMD, ASP, v)
#endif

/* --- Register HW_SATA_P0CMD, field ICC
 *
 * Interface Communication Control  This field is used to control power management states of the
 * interface. When the Link layer is currently in the L_IDLE state,
 * writes to this field cause the Port to initiate a transition to the
 * interface power management state requested. When the Link layer is
 * not currently in the L_IDLE state, writes to this field have no
 * effect.  • 0xF-0x7: Reserved  • 0x6: Slumber. This causes the Port to request a transition of the
 * interface to the Slumber state. The SATA device can reject the
 * request and the interface remains in its current state.  • 0x5-0x3: Reserved  • 0x2: Partial.
 * This causes the Port to request a transition of the                                 interface to
 * the Partial state. The SATA device can reject the                                 request and the
 * interface remains in its current state.  • 0x1: Active. This causes the Port to request a
 * transition of the                                 interface into the active state.  • 0x0: No-Op/
 * Idle. This value indicates to the software that the                                     Port #  0
 * is ready to accept a new interface control command, although the
 * transition to the previously selected state may not yet have
 * occurred.  When the software writes a non-reserved value other than No-Op (0x0),
 * the Port performs the action and update this field back to Idle
 * (0x0).  When the software writes to this field to change the state to a state
 * the link is already in (i.e., interface is in the active state and a
 * request is made to go to the active state), the Port takes no action
 * and returns this field to Idle. When the interface is in a low power
 * state and the software wants to transition to a different low power
 * state, the software must first bring the link to active and then
 * initiate the transition to the desired low power state.
 */

#define BP_SATA_P0CMD_ICC      28
#define BM_SATA_P0CMD_ICC      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CMD_ICC(v)   ((((reg32_t) v) << 28) & BM_SATA_P0CMD_ICC)
#else
#define BF_SATA_P0CMD_ICC(v)   (((v) << 28) & BM_SATA_P0CMD_ICC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CMD_ICC(v)   BF_CS1(SATA_P0CMD, ICC, v)
#endif

/*!
 * @brief HW_SATA_P0TFD - Port0 Task File Data Register
 *
 * This register contains Error and Status registers updated every time a
 * new Register FIS, PIO Setup FIS, or Set Device Bits FIS is received from
 * the device. Reset on Global or Port reset (COMRESET).   Size: 32 bits  Address offset: for # = 0
 * to 7:   P0TFD: 0x120  P1TFD: 0x1A0  P2TFD: 0x220  P3TFD: 0x2A0  P4TFD: 0x320  P5TFD: 0x3A0
 * P6TFD: 0x420  P7TFD: 0x4A0    Read/write access: Read-only  Reset: 0x0000_007F
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned STS : 8; //!< Status  This field contains the latest copy of the task file status register. The bits that affect SATA block operation are:  • Bit [7] BSY - Indicates the interface is busy  • Bits [6:4] cs - Command specific  • Bit [3] DRQ - Indicates a data transfer is requested  • Bits [2:1] cs - Command specific  • Bit [0] ERR - Indicates an error during the transfer  The Port updates the entire 8-bit field, not just the bits noted above.
        unsigned ERR : 8; //!< Error  This field contains the latest copy of the task file error register.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sata_p0tfd_t;
#endif

/*
 * constants & macros for entire SATA_P0TFD register
 */
#define HW_SATA_P0TFD_ADDR      (REGS_SATA_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0TFD           (*(volatile hw_sata_p0tfd_t *) HW_SATA_P0TFD_ADDR)
#define HW_SATA_P0TFD_RD()      (HW_SATA_P0TFD.U)
#define HW_SATA_P0TFD_WR(v)     (HW_SATA_P0TFD.U = (v))
#define HW_SATA_P0TFD_SET(v)    (HW_SATA_P0TFD_WR(HW_SATA_P0TFD_RD() |  (v)))
#define HW_SATA_P0TFD_CLR(v)    (HW_SATA_P0TFD_WR(HW_SATA_P0TFD_RD() & ~(v)))
#define HW_SATA_P0TFD_TOG(v)    (HW_SATA_P0TFD_WR(HW_SATA_P0TFD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0TFD bitfields
 */

/* --- Register HW_SATA_P0TFD, field STS
 *
 * Status  This field contains the latest copy of the task file status register.
 * The bits that affect SATA block operation are:  • Bit [7] BSY - Indicates the interface is busy
 * • Bits [6:4] cs - Command specific  • Bit [3] DRQ - Indicates a data transfer is requested  •
 * Bits [2:1] cs - Command specific  • Bit [0] ERR - Indicates an error during the transfer  The
 * Port updates the entire 8-bit field, not just the bits noted
 * above.
 */

#define BP_SATA_P0TFD_STS      0
#define BM_SATA_P0TFD_STS      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0TFD_STS(v)   ((((reg32_t) v) << 0) & BM_SATA_P0TFD_STS)
#else
#define BF_SATA_P0TFD_STS(v)   (((v) << 0) & BM_SATA_P0TFD_STS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0TFD_STS(v)   BF_CS1(SATA_P0TFD, STS, v)
#endif

/* --- Register HW_SATA_P0TFD, field ERR
 *
 * Error  This field contains the latest copy of the task file error
 * register.
 */

#define BP_SATA_P0TFD_ERR      8
#define BM_SATA_P0TFD_ERR      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0TFD_ERR(v)   ((((reg32_t) v) << 8) & BM_SATA_P0TFD_ERR)
#else
#define BF_SATA_P0TFD_ERR(v)   (((v) << 8) & BM_SATA_P0TFD_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0TFD_ERR(v)   BF_CS1(SATA_P0TFD, ERR, v)
#endif

/*!
 * @brief HW_SATA_P0SIG - Port0 Signature Register
 *
 * Size: 32 bits  Address offset: for # = 0 to 7:  P0SIG: 0x124  P1SIG: 0x1A4  P2SIG: 0x224  P3SIG:
 * 0x2A4  P4SIG: 0x324  P5SIG: 0x3A4  P6SIG: 0x424  P7SIG: 0x4A4    Read/write access: Read-only
 * Reset: 0xFFFF_FFFF
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SIG : 32; //!< Signature  This field contains the signature received from a device on the first D2H Register FIS. The bit order as follows:  • Bits [31:24] - LBA High (Cylinder High) Register  • Bits [23:16] - LBA Mid (Cylinder Low) Register  • Bits [15:8] - LBA Low (Sector Number) Register  • Bits [7:0] - Sector Count Register  This field is updated once after a reset sequence. Reset on Global or Port reset.
    } B;
} hw_sata_p0sig_t;
#endif

/*
 * constants & macros for entire SATA_P0SIG register
 */
#define HW_SATA_P0SIG_ADDR      (REGS_SATA_BASE + 0x124)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SIG           (*(volatile hw_sata_p0sig_t *) HW_SATA_P0SIG_ADDR)
#define HW_SATA_P0SIG_RD()      (HW_SATA_P0SIG.U)
#define HW_SATA_P0SIG_WR(v)     (HW_SATA_P0SIG.U = (v))
#define HW_SATA_P0SIG_SET(v)    (HW_SATA_P0SIG_WR(HW_SATA_P0SIG_RD() |  (v)))
#define HW_SATA_P0SIG_CLR(v)    (HW_SATA_P0SIG_WR(HW_SATA_P0SIG_RD() & ~(v)))
#define HW_SATA_P0SIG_TOG(v)    (HW_SATA_P0SIG_WR(HW_SATA_P0SIG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0SIG bitfields
 */

/* --- Register HW_SATA_P0SIG, field SIG
 *
 * Signature  This field contains the signature received from a device on the first
 * D2H Register FIS. The bit order as follows:  • Bits [31:24] - LBA High (Cylinder High) Register
 * • Bits [23:16] - LBA Mid (Cylinder Low) Register  • Bits [15:8] - LBA Low (Sector Number)
 * Register  • Bits [7:0] - Sector Count Register  This field is updated once after a reset
 * sequence. Reset on Global or                                 Port reset.
 */

#define BP_SATA_P0SIG_SIG      0
#define BM_SATA_P0SIG_SIG      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SIG_SIG(v)   ((((reg32_t) v) << 0) & BM_SATA_P0SIG_SIG)
#else
#define BF_SATA_P0SIG_SIG(v)   (((v) << 0) & BM_SATA_P0SIG_SIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SIG_SIG(v)   BF_CS1(SATA_P0SIG, SIG, v)
#endif

/*!
 * @brief HW_SATA_P0SSTS - Port0 Serial ATA Status Register
 *
 * This 32-bit register conveys the current state of the interface and host.
 * The Port updates it continuously and asynchronously. When the Port
 * transmits a COMRESET to the device, this register is updated to its
 * reset values (i.e., Global reset, Port reset, or COMINIT from the
 * device   Size: 32 bits  Address offset: 0x128  for # = 0 to 7:  P0SSTS: 0x128  P1SSTS: 0x1A8
 * P2SSTS: 0x228  P3SSTS: 0x2A8  P4SSTS: 0x328  P5SSTS: 0x3A8  P6SSTS: 0x428  P7SSTS: 0x4A8
 * Read/write access: Read-only  Reset: 0x0000_0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DET : 4; //!< Indicates the interface device detection and PHY state. The options for this field are:   0x0: No device detected and PHY communication not established  0x1: Device presence detected but PHY communication not established (COMINIT is detected)  0x3: Device presence detected and PHY communication established (“PHY Ready” is detected)  0x4: PHY in offline mode as a result of the interface being disabled or running in a BIST loopback mode.   All other values reserved.
        unsigned SPD : 4; //!< Current Interface Speed  Indicates the negotiated interface communication speed. The options for this field are:
        unsigned IPM : 4; //!< Interface Power Management  Indicates the current interface state. The options for this field are:
        unsigned RESERVED0 : 20; //!< Reserved
    } B;
} hw_sata_p0ssts_t;
#endif

/*
 * constants & macros for entire SATA_P0SSTS register
 */
#define HW_SATA_P0SSTS_ADDR      (REGS_SATA_BASE + 0x128)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SSTS           (*(volatile hw_sata_p0ssts_t *) HW_SATA_P0SSTS_ADDR)
#define HW_SATA_P0SSTS_RD()      (HW_SATA_P0SSTS.U)
#define HW_SATA_P0SSTS_WR(v)     (HW_SATA_P0SSTS.U = (v))
#define HW_SATA_P0SSTS_SET(v)    (HW_SATA_P0SSTS_WR(HW_SATA_P0SSTS_RD() |  (v)))
#define HW_SATA_P0SSTS_CLR(v)    (HW_SATA_P0SSTS_WR(HW_SATA_P0SSTS_RD() & ~(v)))
#define HW_SATA_P0SSTS_TOG(v)    (HW_SATA_P0SSTS_WR(HW_SATA_P0SSTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0SSTS bitfields
 */

/* --- Register HW_SATA_P0SSTS, field DET
 *
 * Indicates the interface device detection and PHY state.              The options for this field
 * are:   0x0: No device detected and PHY communication not established  0x1: Device presence
 * detected but PHY communication not established                    (COMINIT is detected)  0x3:
 * Device presence detected and PHY communication established (“PHY Ready” is detected)  0x4: PHY in
 * offline mode as a result of the interface being disabled or running in a BIST loopback mode.
 * All other values reserved.
 */

#define BP_SATA_P0SSTS_DET      0
#define BM_SATA_P0SSTS_DET      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SSTS_DET(v)   ((((reg32_t) v) << 0) & BM_SATA_P0SSTS_DET)
#else
#define BF_SATA_P0SSTS_DET(v)   (((v) << 0) & BM_SATA_P0SSTS_DET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SSTS_DET(v)   BF_CS1(SATA_P0SSTS, DET, v)
#endif

/* --- Register HW_SATA_P0SSTS, field SPD
 *
 * Current Interface Speed  Indicates the negotiated interface communication speed. The options
 * for this field are:
 */

#define BP_SATA_P0SSTS_SPD      4
#define BM_SATA_P0SSTS_SPD      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SSTS_SPD(v)   ((((reg32_t) v) << 4) & BM_SATA_P0SSTS_SPD)
#else
#define BF_SATA_P0SSTS_SPD(v)   (((v) << 4) & BM_SATA_P0SSTS_SPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SSTS_SPD(v)   BF_CS1(SATA_P0SSTS, SPD, v)
#endif

/* --- Register HW_SATA_P0SSTS, field IPM
 *
 * Interface Power Management  Indicates the current interface state. The options for this field
 * are:
 */

#define BP_SATA_P0SSTS_IPM      8
#define BM_SATA_P0SSTS_IPM      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SSTS_IPM(v)   ((((reg32_t) v) << 8) & BM_SATA_P0SSTS_IPM)
#else
#define BF_SATA_P0SSTS_IPM(v)   (((v) << 8) & BM_SATA_P0SSTS_IPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SSTS_IPM(v)   BF_CS1(SATA_P0SSTS, IPM, v)
#endif

/*!
 * @brief HW_SATA_P0SCTL - Port0 Serial ATA Control {SControl}                        Register
 *
 * This 32-bit read-write register is used by the software to control SATA
 * interface capabilities. Writes to this register result in an action
 * being taken by the Port PHY interface. Reads from the register return
 * the last value written to it. Reset on Global reset.  These bits are static and should not be
 * changed frequently due to the                             clock crossing between the Transport
 * and Link Layers. The software must                             wait for at least seven periods of
 * the slower clock (clk_asic #  0 or hclk)                             before changing this
 * register   Size: 32 bits  Address offset: for # = 0 to 7:   P0SCTL: 0x12C  P1SCTL: 0x1AC  P2SCTL:
 * 0x22C  P3SCTL: 0x2AC  P4SCTL: 0x32C  P5SCTL: 0x3AC  P6SCTL: 0x42C  P7SCTL: 0x4AC    Read/write
 * access: Read/Write  Reset: 0x0000_0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DET : 4; //!< Device Detection Initialization  Controls the Port's device detection and interface initialization. The options for this field are:  This field may only be modified when SATA_P #  0 CMD[ST] is 0. Changing this field while the SATA_P #  0 CMD[ST]=1 results in undefined behavior. When SATA_P #  0 CMD[ST] is set to 1, this field should have a value of 0x0.
        unsigned SPD : 4; //!< Speed Allowed  This field indicates the highest allowable speed of the Port PHY interface. The options for this field are:  When the host software must change this field value, the host must also reset the Port (SATA_P #  0 SCTL[DET] = 0x1) at the same time to ensure proper speed negotiation.
        unsigned IPM : 4; //!< Interface Power Management Transitions Allowed  This field indicates which power states the Port PHY interface is allowed to transition to. When an interface power management state is disabled, the Port does not initiate that state and any request from the device to enter that state is rejected via PMNAKp  The options for this field are:
        unsigned RESERVED0 : 20; //!< Reserved
    } B;
} hw_sata_p0sctl_t;
#endif

/*
 * constants & macros for entire SATA_P0SCTL register
 */
#define HW_SATA_P0SCTL_ADDR      (REGS_SATA_BASE + 0x12c)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SCTL           (*(volatile hw_sata_p0sctl_t *) HW_SATA_P0SCTL_ADDR)
#define HW_SATA_P0SCTL_RD()      (HW_SATA_P0SCTL.U)
#define HW_SATA_P0SCTL_WR(v)     (HW_SATA_P0SCTL.U = (v))
#define HW_SATA_P0SCTL_SET(v)    (HW_SATA_P0SCTL_WR(HW_SATA_P0SCTL_RD() |  (v)))
#define HW_SATA_P0SCTL_CLR(v)    (HW_SATA_P0SCTL_WR(HW_SATA_P0SCTL_RD() & ~(v)))
#define HW_SATA_P0SCTL_TOG(v)    (HW_SATA_P0SCTL_WR(HW_SATA_P0SCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0SCTL bitfields
 */

/* --- Register HW_SATA_P0SCTL, field DET
 *
 * Device Detection Initialization  Controls the Port's device detection and interface
 * initialization.                                 The options for this field are:  This field may
 * only be modified when SATA_P #  0 CMD[ST] is 0. Changing this
 * field while the SATA_P #  0 CMD[ST]=1 results in undefined
 * behavior. When SATA_P #  0 CMD[ST] is set to 1, this field should
 * have a value of 0x0.
 */

#define BP_SATA_P0SCTL_DET      0
#define BM_SATA_P0SCTL_DET      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SCTL_DET(v)   ((((reg32_t) v) << 0) & BM_SATA_P0SCTL_DET)
#else
#define BF_SATA_P0SCTL_DET(v)   (((v) << 0) & BM_SATA_P0SCTL_DET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SCTL_DET(v)   BF_CS1(SATA_P0SCTL, DET, v)
#endif

/* --- Register HW_SATA_P0SCTL, field SPD
 *
 * Speed Allowed  This field indicates the highest allowable speed of the Port PHY
 * interface. The options for this field are:  When the host software must change this field value,
 * the host must                                 also reset the Port (SATA_P #  0 SCTL[DET] = 0x1)
 * at the same time to                                 ensure proper speed negotiation.
 */

#define BP_SATA_P0SCTL_SPD      4
#define BM_SATA_P0SCTL_SPD      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SCTL_SPD(v)   ((((reg32_t) v) << 4) & BM_SATA_P0SCTL_SPD)
#else
#define BF_SATA_P0SCTL_SPD(v)   (((v) << 4) & BM_SATA_P0SCTL_SPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SCTL_SPD(v)   BF_CS1(SATA_P0SCTL, SPD, v)
#endif

/* --- Register HW_SATA_P0SCTL, field IPM
 *
 * Interface Power Management Transitions Allowed  This field indicates which power states the Port
 * PHY interface is                                 allowed to transition to. When an interface
 * power management state                                 is disabled, the Port does not initiate
 * that state and any request                                 from the device to enter that state is
 * rejected via PMNAKp  The options for this field are:
 */

#define BP_SATA_P0SCTL_IPM      8
#define BM_SATA_P0SCTL_IPM      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SCTL_IPM(v)   ((((reg32_t) v) << 8) & BM_SATA_P0SCTL_IPM)
#else
#define BF_SATA_P0SCTL_IPM(v)   (((v) << 8) & BM_SATA_P0SCTL_IPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SCTL_IPM(v)   BF_CS1(SATA_P0SCTL, IPM, v)
#endif

/*!
 * @brief HW_SATA_P0SERR - Port0 Serial ATA Error Register
 *
 * This 32-bit register represents all the detected interface errors
 * accumulated since the last time it was cleared. The set bits in the
 * SError register indicate that the corresponding error condition became
 * true one or more times since the last time the bit was cleared. The set
 * bits in this register are explicitly cleared by a write operation to the
 * register, Global reset, or Port reset (COMRESET). The value written to
 * clear the set error bits should have ones encoded in the bit positions
 * corresponding to the bits that are to be cleared. All bits in the
 * following table have a reset value of 0.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ERR_I : 1; //!< This bit is set when any of the following SATA_P #  0 SERR register bits is set during non- Data FIS transfer:  • DIAG_C (CRC)  • DIAG_H (Handshake)  • ERR_C ("PHY Ready" negation)
        unsigned ERR_M : 1; //!< Recovered Communication Error  This bit is set to 1 when PHY Ready condition is detected after interface initialization, but not after transition from Partial or Slumber power management state to active state.
        unsigned RESERVED0 : 6; //!< Reserved
        unsigned ERR_T : 1; //!< Non-Recovered Transient Data Integrity Error  This bit is set when any of the following SATA_P #  0 SERR register bits is set during Data  FIS transfer: ERR_P (Protocol)  • DIAG_C (CRC)  • DIAG_H (Handshake)  • ERR_C ("PHY Ready" negation)
        unsigned ERR_C : 1; //!< Non-Recovered Persistent Communication Error  This bit is set to 1 when PHY Ready signal is negated due to the loss of communication with the device or problems with interface, but not after transition from active to Partial or Slumber power management state.
        unsigned ERR_P : 1; //!< Protocol Error  This bit is set to 1 when any of the following conditions are detected.  • Transport state transition error (DIAG_T)  • Link sequence error (DIAG_S)  • RxFIFO overflow  • Link bad end error (WTRM instead of EOF is received).
        unsigned ERR_E : 1; //!< Internal Error  This bit is set to 1 when one or more AHB bus ERROR responses are detected on the master interface.
        unsigned RESERVED1 : 4; //!< Reserved
        unsigned DIAG_N : 1; //!< PHY Ready Change  This bit indicates that the PHY Ready signal changed state. This bit is reflected in the SATA_P #  0 IS[PRCS] bit.
        unsigned DIAG_I : 1; //!< PHY Internal Error  This bit is set when the PHY detects some internal error as indicated by the assertion of the p #  0 _phy_rx_err input.  The setting of this bit is controlled by the SATA_BISTCR[ERREN] bit: when ERREN==0 (default), only errors occurring inside the received FIS cause DIAG_I bit to be set; when ERREN==1, any error inside or outside the FIS causes the DIAG_I bit to be set.
        unsigned DIAG_W : 1; //!< Comm Wake  This bit is set when PHY COMWAKE signal is detected.
        unsigned DIAG_B : 1; //!< 10B to 8B Decode Error  This bit indicates errors were detected by 10b8b decoder.  This bit indicates that one or more CRC errors were detected by the Link layer during FIS reception.  This bit is set only when an error is detected on the received FIS data dword. This bit is not set when an error is detected on the primitive, regardless whether it is inside or outside the FIS.
        unsigned DIAG_D : 1; //!< Disparity Error  This bit is always cleared to 0 since it is not used by the AHCI specification.
        unsigned DIAG_C : 1; //!< CRC Error
        unsigned DIAG_H : 1; //!< Handshake Error  This bit indicates that one or more R_ERRp was received in response to frame transmission. Such errors may be the result of a CRC error detected by the device, a disparity or 8b/10b decoding error, or other error condition leading to a negative handshake on a transmitted frame.
        unsigned DIAG_S : 1; //!< Link Sequence Error  This bit indicates that one or more Link state machine error conditions was encountered. One of the conditions that cause this bit to be set is device doing SYNC escape during FIS transmission.
        unsigned DIAG_T : 1; //!< Transport State Transition Error  This bit indicates that a Transport Layer protocol violation was detected since the last time this bit was cleared. See for details.
        unsigned DIAG_F : 1; //!< Unknown FIS Type  This bit indicates that one or more FISes were received by the Transport layer with good CRC, but had a type field that was not recognized/known and the length was less than or equal to 64bytes.  When the Unknown FIS length exceeds 64 bytes, the DIAG_F bit is not set and the DIAG_T bit is set instead.
        unsigned DIAG_X : 1; //!< Exchanged  This bit is set to 1 when PHY COMINIT signal is detected. This bit is reflected in the SATA_P #  0 IS[PCS] bit.
        unsigned RESERVED2 : 5; //!< Reserved
    } B;
} hw_sata_p0serr_t;
#endif

/*
 * constants & macros for entire SATA_P0SERR register
 */
#define HW_SATA_P0SERR_ADDR      (REGS_SATA_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SERR           (*(volatile hw_sata_p0serr_t *) HW_SATA_P0SERR_ADDR)
#define HW_SATA_P0SERR_RD()      (HW_SATA_P0SERR.U)
#define HW_SATA_P0SERR_WR(v)     (HW_SATA_P0SERR.U = (v))
#define HW_SATA_P0SERR_SET(v)    (HW_SATA_P0SERR_WR(HW_SATA_P0SERR_RD() |  (v)))
#define HW_SATA_P0SERR_CLR(v)    (HW_SATA_P0SERR_WR(HW_SATA_P0SERR_RD() & ~(v)))
#define HW_SATA_P0SERR_TOG(v)    (HW_SATA_P0SERR_WR(HW_SATA_P0SERR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0SERR bitfields
 */

/* --- Register HW_SATA_P0SERR, field ERR_I
 *
 * This bit is set when any of the following SATA_P #  0 SERR
 * register bits is set during non- Data FIS transfer:  • DIAG_C (CRC)  • DIAG_H (Handshake)  •
 * ERR_C ("PHY Ready" negation)
 */

#define BP_SATA_P0SERR_ERR_I      0
#define BM_SATA_P0SERR_ERR_I      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_ERR_I(v)   ((((reg32_t) v) << 0) & BM_SATA_P0SERR_ERR_I)
#else
#define BF_SATA_P0SERR_ERR_I(v)   (((v) << 0) & BM_SATA_P0SERR_ERR_I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_ERR_I(v)   BF_CS1(SATA_P0SERR, ERR_I, v)
#endif

/* --- Register HW_SATA_P0SERR, field ERR_M
 *
 * Recovered Communication Error  This bit is set to 1 when PHY Ready condition is detected after
 * interface initialization, but not after transition from Partial or
 * Slumber power management state to active state.
 */

#define BP_SATA_P0SERR_ERR_M      1
#define BM_SATA_P0SERR_ERR_M      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_ERR_M(v)   ((((reg32_t) v) << 1) & BM_SATA_P0SERR_ERR_M)
#else
#define BF_SATA_P0SERR_ERR_M(v)   (((v) << 1) & BM_SATA_P0SERR_ERR_M)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_ERR_M(v)   BF_CS1(SATA_P0SERR, ERR_M, v)
#endif

/* --- Register HW_SATA_P0SERR, field ERR_T
 *
 * Non-Recovered Transient Data Integrity Error  This bit is set when any of the following SATA_P #
 * 0 SERR                                 register bits is set during Data  FIS transfer: ERR_P
 * (Protocol)  • DIAG_C (CRC)  • DIAG_H (Handshake)  • ERR_C ("PHY Ready" negation)
 */

#define BP_SATA_P0SERR_ERR_T      8
#define BM_SATA_P0SERR_ERR_T      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_ERR_T(v)   ((((reg32_t) v) << 8) & BM_SATA_P0SERR_ERR_T)
#else
#define BF_SATA_P0SERR_ERR_T(v)   (((v) << 8) & BM_SATA_P0SERR_ERR_T)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_ERR_T(v)   BF_CS1(SATA_P0SERR, ERR_T, v)
#endif

/* --- Register HW_SATA_P0SERR, field ERR_C
 *
 * Non-Recovered Persistent Communication Error  This bit is set to 1 when PHY Ready signal is
 * negated due to the loss                                 of communication with the device or
 * problems with interface, but not                                 after transition from active to
 * Partial or Slumber power management                                 state.
 */

#define BP_SATA_P0SERR_ERR_C      9
#define BM_SATA_P0SERR_ERR_C      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_ERR_C(v)   ((((reg32_t) v) << 9) & BM_SATA_P0SERR_ERR_C)
#else
#define BF_SATA_P0SERR_ERR_C(v)   (((v) << 9) & BM_SATA_P0SERR_ERR_C)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_ERR_C(v)   BF_CS1(SATA_P0SERR, ERR_C, v)
#endif

/* --- Register HW_SATA_P0SERR, field ERR_P
 *
 * Protocol Error  This bit is set to 1 when any of the following conditions are
 * detected.  • Transport state transition error (DIAG_T)  • Link sequence error (DIAG_S)  • RxFIFO
 * overflow  • Link bad end error (WTRM instead of EOF is received).
 */

#define BP_SATA_P0SERR_ERR_P      10
#define BM_SATA_P0SERR_ERR_P      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_ERR_P(v)   ((((reg32_t) v) << 10) & BM_SATA_P0SERR_ERR_P)
#else
#define BF_SATA_P0SERR_ERR_P(v)   (((v) << 10) & BM_SATA_P0SERR_ERR_P)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_ERR_P(v)   BF_CS1(SATA_P0SERR, ERR_P, v)
#endif

/* --- Register HW_SATA_P0SERR, field ERR_E
 *
 * Internal Error  This bit is set to 1 when one or more AHB bus ERROR responses are
 * detected on the master interface.
 */

#define BP_SATA_P0SERR_ERR_E      11
#define BM_SATA_P0SERR_ERR_E      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_ERR_E(v)   ((((reg32_t) v) << 11) & BM_SATA_P0SERR_ERR_E)
#else
#define BF_SATA_P0SERR_ERR_E(v)   (((v) << 11) & BM_SATA_P0SERR_ERR_E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_ERR_E(v)   BF_CS1(SATA_P0SERR, ERR_E, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_N
 *
 * PHY Ready Change  This bit indicates that the PHY Ready signal changed state. This bit
 * is reflected in the SATA_P #  0 IS[PRCS] bit.
 */

#define BP_SATA_P0SERR_DIAG_N      16
#define BM_SATA_P0SERR_DIAG_N      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_N(v)   ((((reg32_t) v) << 16) & BM_SATA_P0SERR_DIAG_N)
#else
#define BF_SATA_P0SERR_DIAG_N(v)   (((v) << 16) & BM_SATA_P0SERR_DIAG_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_N(v)   BF_CS1(SATA_P0SERR, DIAG_N, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_I
 *
 * PHY Internal Error  This bit is set when the PHY detects some internal error as indicated
 * by the assertion of the p #  0 _phy_rx_err input.  The setting of this bit is controlled by the
 * SATA_BISTCR[ERREN]                                 bit: when ERREN==0 (default), only errors
 * occurring inside the                                 received FIS cause DIAG_I bit to be set;
 * when ERREN==1, any error                                 inside or outside the FIS causes the
 * DIAG_I bit to be set.
 */

#define BP_SATA_P0SERR_DIAG_I      17
#define BM_SATA_P0SERR_DIAG_I      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_I(v)   ((((reg32_t) v) << 17) & BM_SATA_P0SERR_DIAG_I)
#else
#define BF_SATA_P0SERR_DIAG_I(v)   (((v) << 17) & BM_SATA_P0SERR_DIAG_I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_I(v)   BF_CS1(SATA_P0SERR, DIAG_I, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_W
 *
 * Comm Wake  This bit is set when PHY COMWAKE signal is detected.
 */

#define BP_SATA_P0SERR_DIAG_W      18
#define BM_SATA_P0SERR_DIAG_W      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_W(v)   ((((reg32_t) v) << 18) & BM_SATA_P0SERR_DIAG_W)
#else
#define BF_SATA_P0SERR_DIAG_W(v)   (((v) << 18) & BM_SATA_P0SERR_DIAG_W)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_W(v)   BF_CS1(SATA_P0SERR, DIAG_W, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_B
 *
 * 10B to 8B Decode Error  This bit indicates errors were detected by 10b8b decoder.  This bit
 * indicates that one or more CRC errors were detected by the                                 Link
 * layer during FIS reception.  This bit is set only when an error is detected on the received FIS
 * data dword. This bit is not set when an error is detected on the
 * primitive, regardless whether it is inside or outside the                                 FIS.
 */

#define BP_SATA_P0SERR_DIAG_B      19
#define BM_SATA_P0SERR_DIAG_B      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_B(v)   ((((reg32_t) v) << 19) & BM_SATA_P0SERR_DIAG_B)
#else
#define BF_SATA_P0SERR_DIAG_B(v)   (((v) << 19) & BM_SATA_P0SERR_DIAG_B)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_B(v)   BF_CS1(SATA_P0SERR, DIAG_B, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_D
 *
 * Disparity Error  This bit is always cleared to 0 since it is not used by the AHCI
 * specification.
 */

#define BP_SATA_P0SERR_DIAG_D      20
#define BM_SATA_P0SERR_DIAG_D      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_D(v)   ((((reg32_t) v) << 20) & BM_SATA_P0SERR_DIAG_D)
#else
#define BF_SATA_P0SERR_DIAG_D(v)   (((v) << 20) & BM_SATA_P0SERR_DIAG_D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_D(v)   BF_CS1(SATA_P0SERR, DIAG_D, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_C
 *
 * CRC Error
 */

#define BP_SATA_P0SERR_DIAG_C      21
#define BM_SATA_P0SERR_DIAG_C      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_C(v)   ((((reg32_t) v) << 21) & BM_SATA_P0SERR_DIAG_C)
#else
#define BF_SATA_P0SERR_DIAG_C(v)   (((v) << 21) & BM_SATA_P0SERR_DIAG_C)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_C(v)   BF_CS1(SATA_P0SERR, DIAG_C, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_H
 *
 * Handshake Error  This bit indicates that one or more R_ERRp was received in response
 * to frame transmission. Such errors may be the result of a CRC error
 * detected by the device, a disparity or 8b/10b decoding error, or
 * other error condition leading to a negative handshake on a
 * transmitted frame.
 */

#define BP_SATA_P0SERR_DIAG_H      22
#define BM_SATA_P0SERR_DIAG_H      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_H(v)   ((((reg32_t) v) << 22) & BM_SATA_P0SERR_DIAG_H)
#else
#define BF_SATA_P0SERR_DIAG_H(v)   (((v) << 22) & BM_SATA_P0SERR_DIAG_H)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_H(v)   BF_CS1(SATA_P0SERR, DIAG_H, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_S
 *
 * Link Sequence Error  This bit indicates that one or more Link state machine error
 * conditions was encountered. One of the conditions that cause this
 * bit to be set is device doing SYNC escape during FIS
 * transmission.
 */

#define BP_SATA_P0SERR_DIAG_S      23
#define BM_SATA_P0SERR_DIAG_S      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_S(v)   ((((reg32_t) v) << 23) & BM_SATA_P0SERR_DIAG_S)
#else
#define BF_SATA_P0SERR_DIAG_S(v)   (((v) << 23) & BM_SATA_P0SERR_DIAG_S)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_S(v)   BF_CS1(SATA_P0SERR, DIAG_S, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_T
 *
 * Transport State Transition Error  This bit indicates that a Transport Layer protocol violation
 * was                                 detected since the last time this bit was cleared. See for
 * details.
 */

#define BP_SATA_P0SERR_DIAG_T      24
#define BM_SATA_P0SERR_DIAG_T      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_T(v)   ((((reg32_t) v) << 24) & BM_SATA_P0SERR_DIAG_T)
#else
#define BF_SATA_P0SERR_DIAG_T(v)   (((v) << 24) & BM_SATA_P0SERR_DIAG_T)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_T(v)   BF_CS1(SATA_P0SERR, DIAG_T, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_F
 *
 * Unknown FIS Type  This bit indicates that one or more FISes were received by the
 * Transport layer with good CRC, but had a type field that was not
 * recognized/known and the length was less than or equal to
 * 64bytes.  When the Unknown FIS length exceeds 64 bytes, the DIAG_F bit is
 * not set and the DIAG_T bit is set instead.
 */

#define BP_SATA_P0SERR_DIAG_F      25
#define BM_SATA_P0SERR_DIAG_F      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_F(v)   ((((reg32_t) v) << 25) & BM_SATA_P0SERR_DIAG_F)
#else
#define BF_SATA_P0SERR_DIAG_F(v)   (((v) << 25) & BM_SATA_P0SERR_DIAG_F)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_F(v)   BF_CS1(SATA_P0SERR, DIAG_F, v)
#endif

/* --- Register HW_SATA_P0SERR, field DIAG_X
 *
 * Exchanged  This bit is set to 1 when PHY COMINIT signal is detected. This bit is
 * reflected in the SATA_P #  0 IS[PCS] bit.
 */

#define BP_SATA_P0SERR_DIAG_X      26
#define BM_SATA_P0SERR_DIAG_X      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SERR_DIAG_X(v)   ((((reg32_t) v) << 26) & BM_SATA_P0SERR_DIAG_X)
#else
#define BF_SATA_P0SERR_DIAG_X(v)   (((v) << 26) & BM_SATA_P0SERR_DIAG_X)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SERR_DIAG_X(v)   BF_CS1(SATA_P0SERR, DIAG_X, v)
#endif

/*!
 * @brief HW_SATA_P0SACT - Port0 Serial ATA Active Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DS : 32; //!< Device Status  This field is bit significant. Each bit corresponds to the TAG and command slot of a native queued command, where bit 0 corresponds to TAG 0 and command slot 0.  Software sets this field prior to issuing a native queued command for a particular command slot. Prior to writing SATA_P #  0 CI[TAG] to 1, the software sets DS[TAG] to 1 to indicate that a command with that TAG is outstanding.  This field is cleared to 0 when:  • The software writes SATA_P #  0 CMD[ST from a 1 to a 0 .  • The device sends a Set Device Bits FIS to the Port. The Port clears bits in this field that are set in the SActive field of the Set Device Bits FIS. The Port clears only bits that correspond to native queued commands that have completed successfully.  This field is not cleared by the following:  • Port reset (COMRESET).  • Software reset.  Software must write this field only when SATA_P #  0 CMD[ST] bit is set to 1.
    } B;
} hw_sata_p0sact_t;
#endif

/*
 * constants & macros for entire SATA_P0SACT register
 */
#define HW_SATA_P0SACT_ADDR      (REGS_SATA_BASE + 0x134)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SACT           (*(volatile hw_sata_p0sact_t *) HW_SATA_P0SACT_ADDR)
#define HW_SATA_P0SACT_RD()      (HW_SATA_P0SACT.U)
#define HW_SATA_P0SACT_WR(v)     (HW_SATA_P0SACT.U = (v))
#define HW_SATA_P0SACT_SET(v)    (HW_SATA_P0SACT_WR(HW_SATA_P0SACT_RD() |  (v)))
#define HW_SATA_P0SACT_CLR(v)    (HW_SATA_P0SACT_WR(HW_SATA_P0SACT_RD() & ~(v)))
#define HW_SATA_P0SACT_TOG(v)    (HW_SATA_P0SACT_WR(HW_SATA_P0SACT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0SACT bitfields
 */

/* --- Register HW_SATA_P0SACT, field DS
 *
 * Device Status  This field is bit significant. Each bit corresponds to the TAG and
 * command slot of a native queued command, where bit 0 corresponds to
 * TAG 0 and command slot 0.  Software sets this field prior to issuing a native queued command for
 * a particular command slot. Prior to writing SATA_P #  0 CI[TAG]
 * to 1, the software sets DS[TAG] to 1 to indicate that a command with
 * that TAG is outstanding.  This field is cleared to 0 when:  • The software writes SATA_P #  0
 * CMD[ST from a 1 to a 0 .  • The device sends a Set Device Bits FIS to the Port. The Port clears
 * bits in this field that are set in the SActive field of the Set
 * Device Bits FIS. The Port clears only bits that correspond to native
 * queued commands that have completed successfully.  This field is not cleared by the following:  •
 * Port reset (COMRESET).  • Software reset.  Software must write this field only when SATA_P #  0
 * CMD[ST]                                 bit is set to 1.
 */

#define BP_SATA_P0SACT_DS      0
#define BM_SATA_P0SACT_DS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SACT_DS(v)   ((((reg32_t) v) << 0) & BM_SATA_P0SACT_DS)
#else
#define BF_SATA_P0SACT_DS(v)   (((v) << 0) & BM_SATA_P0SACT_DS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SACT_DS(v)   BF_CS1(SATA_P0SACT, DS, v)
#endif

/*!
 * @brief HW_SATA_P0CI - Port0 Command Issue Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CI : 32; //!< Command Issued  This field is bit significant. Each bit corresponds to a command slot, where bit 0 corresponds to command slot 0. This field is set by the software to indicate to the Port that a command has been built in system memory for a command slot and may be sent to the device.  When the Port receives a FIS which clears the BSY, DRQ, and ERR bits for the command, it clears the corresponding bit in this register for that command slot. Bits in this field can only be set to 1 by the software when SATA_P #  0 CMD[ST] is set to 1.  This field is reset when SATA_P #  0 CMD[ST] is written from a 1 to a 0 by the software.
    } B;
} hw_sata_p0ci_t;
#endif

/*
 * constants & macros for entire SATA_P0CI register
 */
#define HW_SATA_P0CI_ADDR      (REGS_SATA_BASE + 0x138)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0CI           (*(volatile hw_sata_p0ci_t *) HW_SATA_P0CI_ADDR)
#define HW_SATA_P0CI_RD()      (HW_SATA_P0CI.U)
#define HW_SATA_P0CI_WR(v)     (HW_SATA_P0CI.U = (v))
#define HW_SATA_P0CI_SET(v)    (HW_SATA_P0CI_WR(HW_SATA_P0CI_RD() |  (v)))
#define HW_SATA_P0CI_CLR(v)    (HW_SATA_P0CI_WR(HW_SATA_P0CI_RD() & ~(v)))
#define HW_SATA_P0CI_TOG(v)    (HW_SATA_P0CI_WR(HW_SATA_P0CI_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0CI bitfields
 */

/* --- Register HW_SATA_P0CI, field CI
 *
 * Command Issued  This field is bit significant. Each bit corresponds to a command
 * slot, where bit 0 corresponds to command slot 0. This field is set
 * by the software to indicate to the Port that a command has been
 * built in system memory for a command slot and may be sent to the
 * device.  When the Port receives a FIS which clears the BSY, DRQ, and ERR bits
 * for the command, it clears the corresponding bit in this register
 * for that command slot. Bits in this field can only be set to 1 by
 * the software when SATA_P #  0 CMD[ST] is set to 1.  This field is reset when SATA_P #  0 CMD[ST]
 * is written from a 1 to a 0 by                                 the software.
 */

#define BP_SATA_P0CI_CI      0
#define BM_SATA_P0CI_CI      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0CI_CI(v)   ((((reg32_t) v) << 0) & BM_SATA_P0CI_CI)
#else
#define BF_SATA_P0CI_CI(v)   (((v) << 0) & BM_SATA_P0CI_CI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0CI_CI(v)   BF_CS1(SATA_P0CI, CI, v)
#endif

/*!
 * @brief HW_SATA_P0SNTF - Port0 Serial ATA Notification Register
 *
 * This register is used to determine when asynchronous notification events
 * have occurred for directly connected devices and devices connected to a
 * Port Multiplier.   Size: 32 bits  Address offset: for # = 0 to 7:  P0SNTF: 0x13C  P1SNTF: 0x1BC
 * P2SNTF: 0x23C  P3SNTF: 0x2BC  P4SNTF: 0x33C  P5SNTF: 0x3BC  P6SNTF: 0x43C  P7SNTF: 0x4BC
 * Read/write access: Read/Write One to Clear  Reset: 0x0000_0000
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PMN : 16; //!< PM Notify  This field indicates whether a particular device with the corresponding PM Port number issued a Set Device Bits FIS to the SATA block Port with the Notification bit set:  • PM Port 0h sets bit 0,  • PM Port 1h sets bit 1,  ...  • PM Port Fh sets bit 15.  Individual bits are cleared by the software writing 1s to the corresponding bit positions.  This field is reset on Global reset, but it is not reset by Port reset (COMRESET) or software reset.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sata_p0sntf_t;
#endif

/*
 * constants & macros for entire SATA_P0SNTF register
 */
#define HW_SATA_P0SNTF_ADDR      (REGS_SATA_BASE + 0x13c)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SNTF           (*(volatile hw_sata_p0sntf_t *) HW_SATA_P0SNTF_ADDR)
#define HW_SATA_P0SNTF_RD()      (HW_SATA_P0SNTF.U)
#define HW_SATA_P0SNTF_WR(v)     (HW_SATA_P0SNTF.U = (v))
#define HW_SATA_P0SNTF_SET(v)    (HW_SATA_P0SNTF_WR(HW_SATA_P0SNTF_RD() |  (v)))
#define HW_SATA_P0SNTF_CLR(v)    (HW_SATA_P0SNTF_WR(HW_SATA_P0SNTF_RD() & ~(v)))
#define HW_SATA_P0SNTF_TOG(v)    (HW_SATA_P0SNTF_WR(HW_SATA_P0SNTF_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0SNTF bitfields
 */

/* --- Register HW_SATA_P0SNTF, field PMN
 *
 * PM Notify  This field indicates whether a particular device with the
 * corresponding PM Port number issued a Set Device Bits FIS to the
 * SATA block Port with the Notification bit set:  • PM Port 0h sets bit 0,  • PM Port 1h sets bit
 * 1,  ...  • PM Port Fh sets bit 15.  Individual bits are cleared by the software writing 1s to the
 * corresponding bit positions.  This field is reset on Global reset, but it is not reset by Port
 * reset (COMRESET) or software reset.
 */

#define BP_SATA_P0SNTF_PMN      0
#define BM_SATA_P0SNTF_PMN      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0SNTF_PMN(v)   ((((reg32_t) v) << 0) & BM_SATA_P0SNTF_PMN)
#else
#define BF_SATA_P0SNTF_PMN(v)   (((v) << 0) & BM_SATA_P0SNTF_PMN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0SNTF_PMN(v)   BF_CS1(SATA_P0SNTF, PMN, v)
#endif

/*!
 * @brief HW_SATA_P0DMACR - Port0 DMA Control Register
 *
 * This register contains bits for controlling the Port DMA engine. The
 * software can change the fields of this register only when SATA_P 0  # CMD[ST]=0.
 * Power-up (system reset), Global reset, or Port reset (COMRESET) reset
 * this register to the default value.   Size: 32 bits  Address offset: for # = 0 to 7:  P0DMACR:
 * 0x170  P1DMACR: 0x1F0  P2DMACR: 0x270  P3DMACR: 0x2F0  P4DMACR: 0x370  P5DMACR: 0x3F0  P6DMACR:
 * 0x470  P7DMACR: 0x4F0    Read/write access: Read/Write or Read-only  Reset: 0x0000_0044
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TXTS : 4; //!< Transmit Transaction Size  This field defines the DMA transaction size in DWORDs for transmit (system bus read, device write) operation.  The options for this field are:  This field is read-write when SATA_P 0  # CMD[ST]=0 and read-only when SATA_P 0  # CMD[ST]=1.  The maximum value of this field is determined by the TxFIFO depth set by the P#_TXFIFO_DEPTH parameter. When the software attempts to write a value exceeding this value, the maximum value would be set instead.
        unsigned RXTS : 4; //!< Receive Transaction Size  This field defines the Port DMA transaction size in DWORDs for receive (system bus write, device read) operation.  This field is read-write when SATA_P 0  # CMD[ST]=0 and read-only when SATA_P 0  # CMD[ST]=1.  The maximum value of this field is determined by the RxFIFO depth set by the P#_RXFIFO_DEPTH parameter. When the software attempts to write a value exceeding this value, the maximum value would be set instead.
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned RESERVED1 : 4; //!< Reserved
        unsigned RESERVED2 : 16; //!< Reserved
    } B;
} hw_sata_p0dmacr_t;
#endif

/*
 * constants & macros for entire SATA_P0DMACR register
 */
#define HW_SATA_P0DMACR_ADDR      (REGS_SATA_BASE + 0x170)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0DMACR           (*(volatile hw_sata_p0dmacr_t *) HW_SATA_P0DMACR_ADDR)
#define HW_SATA_P0DMACR_RD()      (HW_SATA_P0DMACR.U)
#define HW_SATA_P0DMACR_WR(v)     (HW_SATA_P0DMACR.U = (v))
#define HW_SATA_P0DMACR_SET(v)    (HW_SATA_P0DMACR_WR(HW_SATA_P0DMACR_RD() |  (v)))
#define HW_SATA_P0DMACR_CLR(v)    (HW_SATA_P0DMACR_WR(HW_SATA_P0DMACR_RD() & ~(v)))
#define HW_SATA_P0DMACR_TOG(v)    (HW_SATA_P0DMACR_WR(HW_SATA_P0DMACR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0DMACR bitfields
 */

/* --- Register HW_SATA_P0DMACR, field TXTS
 *
 * Transmit Transaction Size  This field defines the DMA transaction size in DWORDs for transmit
 * (system bus read, device write) operation.  The options for this field are:  This field is read-
 * write when SATA_P 0  # CMD[ST]=0 and read-only when SATA_P 0  # CMD[ST]=1.  The maximum value of
 * this field is determined by the TxFIFO depth set by the P#_TXFIFO_DEPTH parameter.
 * When the software attempts to write a value exceeding this value,
 * the maximum value would be set instead.
 */

#define BP_SATA_P0DMACR_TXTS      0
#define BM_SATA_P0DMACR_TXTS      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0DMACR_TXTS(v)   ((((reg32_t) v) << 0) & BM_SATA_P0DMACR_TXTS)
#else
#define BF_SATA_P0DMACR_TXTS(v)   (((v) << 0) & BM_SATA_P0DMACR_TXTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0DMACR_TXTS(v)   BF_CS1(SATA_P0DMACR, TXTS, v)
#endif

/* --- Register HW_SATA_P0DMACR, field RXTS
 *
 * Receive Transaction Size  This field defines the Port DMA transaction size in DWORDs for
 * receive (system bus write, device read) operation.  This field is read-write when SATA_P 0  #
 * CMD[ST]=0 and read-only when SATA_P 0  # CMD[ST]=1.  The maximum value of this field is
 * determined by the RxFIFO depth set by the P#_RXFIFO_DEPTH parameter.
 * When the software attempts to write a value exceeding this value,
 * the maximum value would be set instead.
 */

#define BP_SATA_P0DMACR_RXTS      4
#define BM_SATA_P0DMACR_RXTS      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0DMACR_RXTS(v)   ((((reg32_t) v) << 4) & BM_SATA_P0DMACR_RXTS)
#else
#define BF_SATA_P0DMACR_RXTS(v)   (((v) << 4) & BM_SATA_P0DMACR_RXTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0DMACR_RXTS(v)   BF_CS1(SATA_P0DMACR, RXTS, v)
#endif

/*!
 * @brief HW_SATA_P0PHYCR - Port0 PHY Control Register
 *
 * This register is used for Port PHY control. This                                 register only
 * exists when PHY_CTRL_W parameter is set to a non-zero                                 value,
 * otherwise this location is reserved. The width is set by the
 * PHY_CTRL_W parameter (valid range: 0 to 32). When PHY_CTRL_W <
 * 32, the remaining bits are reserved: reads return zeros, writes have
 * no effect.   Bits of this register are connected to the corresponding bits of the p 0  #
 * _phy_ctrl                             output Port. Resets on power- up (system reset)
 * only to the PHY_CTRL_DEF value.   The SATA_P #  0 PHYCR register supports only 32-bit write
 * access (s_hsize = 3'b010).    Size: 32 bits  Address offset: for # = 0 to 7:  P0PHYCR: 0x178
 * P1PHYCR: 0x1F8  P2PHYCR: 0x278  P3PHYCR: 0x2F8  P4PHYCR: 0x378  P5PHYCR: 0x3F8  P6PHYCR: 0x478
 * P7PHYCR: 0x4F8    Read/write access: Read/Write  Reset: 0x0000_0000 PHY_CTRL_DEF
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CR_DATA_IN : 16; //!< CR Address and Write Data Input Bus. Supplies and captures address and write data.
        unsigned CR_CAP_ADDR : 1; //!< CR Capture Address. Captures phy_cr_data_in[15:0] into the Address register.
        unsigned CR_CAP_DATA : 1; //!< CR Capture Data. Captures phy_cr_data_in[15:0] into the Write Data register.
        unsigned CR_WRITE : 1; //!< CR Write. Writes the Write Data register to the referenced Address register.
        unsigned CR_READ : 1; //!< CR Read. Reads from the referenced Address register.
        unsigned TEST_PDDQ : 1; //!< Test IDDQ
        unsigned RESERVED0 : 11; //!< Reserved
    } B;
} hw_sata_p0phycr_t;
#endif

/*
 * constants & macros for entire SATA_P0PHYCR register
 */
#define HW_SATA_P0PHYCR_ADDR      (REGS_SATA_BASE + 0x178)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0PHYCR           (*(volatile hw_sata_p0phycr_t *) HW_SATA_P0PHYCR_ADDR)
#define HW_SATA_P0PHYCR_RD()      (HW_SATA_P0PHYCR.U)
#define HW_SATA_P0PHYCR_WR(v)     (HW_SATA_P0PHYCR.U = (v))
#define HW_SATA_P0PHYCR_SET(v)    (HW_SATA_P0PHYCR_WR(HW_SATA_P0PHYCR_RD() |  (v)))
#define HW_SATA_P0PHYCR_CLR(v)    (HW_SATA_P0PHYCR_WR(HW_SATA_P0PHYCR_RD() & ~(v)))
#define HW_SATA_P0PHYCR_TOG(v)    (HW_SATA_P0PHYCR_WR(HW_SATA_P0PHYCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0PHYCR bitfields
 */

/* --- Register HW_SATA_P0PHYCR, field CR_DATA_IN
 *
 * CR Address and Write Data Input Bus. Supplies and captures address and write data.
 */

#define BP_SATA_P0PHYCR_CR_DATA_IN      0
#define BM_SATA_P0PHYCR_CR_DATA_IN      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0PHYCR_CR_DATA_IN(v)   ((((reg32_t) v) << 0) & BM_SATA_P0PHYCR_CR_DATA_IN)
#else
#define BF_SATA_P0PHYCR_CR_DATA_IN(v)   (((v) << 0) & BM_SATA_P0PHYCR_CR_DATA_IN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0PHYCR_CR_DATA_IN(v)   BF_CS1(SATA_P0PHYCR, CR_DATA_IN, v)
#endif

/* --- Register HW_SATA_P0PHYCR, field CR_CAP_ADDR
 *
 * CR Capture Address. Captures phy_cr_data_in[15:0] into the Address register.
 */

#define BP_SATA_P0PHYCR_CR_CAP_ADDR      16
#define BM_SATA_P0PHYCR_CR_CAP_ADDR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0PHYCR_CR_CAP_ADDR(v)   ((((reg32_t) v) << 16) & BM_SATA_P0PHYCR_CR_CAP_ADDR)
#else
#define BF_SATA_P0PHYCR_CR_CAP_ADDR(v)   (((v) << 16) & BM_SATA_P0PHYCR_CR_CAP_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0PHYCR_CR_CAP_ADDR(v)   BF_CS1(SATA_P0PHYCR, CR_CAP_ADDR, v)
#endif

/* --- Register HW_SATA_P0PHYCR, field CR_CAP_DATA
 *
 * CR Capture Data. Captures phy_cr_data_in[15:0] into the Write Data register.
 */

#define BP_SATA_P0PHYCR_CR_CAP_DATA      17
#define BM_SATA_P0PHYCR_CR_CAP_DATA      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0PHYCR_CR_CAP_DATA(v)   ((((reg32_t) v) << 17) & BM_SATA_P0PHYCR_CR_CAP_DATA)
#else
#define BF_SATA_P0PHYCR_CR_CAP_DATA(v)   (((v) << 17) & BM_SATA_P0PHYCR_CR_CAP_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0PHYCR_CR_CAP_DATA(v)   BF_CS1(SATA_P0PHYCR, CR_CAP_DATA, v)
#endif

/* --- Register HW_SATA_P0PHYCR, field CR_WRITE
 *
 * CR Write. Writes the Write Data register to the referenced Address register.
 */

#define BP_SATA_P0PHYCR_CR_WRITE      18
#define BM_SATA_P0PHYCR_CR_WRITE      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0PHYCR_CR_WRITE(v)   ((((reg32_t) v) << 18) & BM_SATA_P0PHYCR_CR_WRITE)
#else
#define BF_SATA_P0PHYCR_CR_WRITE(v)   (((v) << 18) & BM_SATA_P0PHYCR_CR_WRITE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0PHYCR_CR_WRITE(v)   BF_CS1(SATA_P0PHYCR, CR_WRITE, v)
#endif

/* --- Register HW_SATA_P0PHYCR, field CR_READ
 *
 * CR Read. Reads from the referenced Address register.
 */

#define BP_SATA_P0PHYCR_CR_READ      19
#define BM_SATA_P0PHYCR_CR_READ      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0PHYCR_CR_READ(v)   ((((reg32_t) v) << 19) & BM_SATA_P0PHYCR_CR_READ)
#else
#define BF_SATA_P0PHYCR_CR_READ(v)   (((v) << 19) & BM_SATA_P0PHYCR_CR_READ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0PHYCR_CR_READ(v)   BF_CS1(SATA_P0PHYCR, CR_READ, v)
#endif

/* --- Register HW_SATA_P0PHYCR, field TEST_PDDQ
 *
 * Test IDDQ
 */

#define BP_SATA_P0PHYCR_TEST_PDDQ      20
#define BM_SATA_P0PHYCR_TEST_PDDQ      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0PHYCR_TEST_PDDQ(v)   ((((reg32_t) v) << 20) & BM_SATA_P0PHYCR_TEST_PDDQ)
#else
#define BF_SATA_P0PHYCR_TEST_PDDQ(v)   (((v) << 20) & BM_SATA_P0PHYCR_TEST_PDDQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0PHYCR_TEST_PDDQ(v)   BF_CS1(SATA_P0PHYCR, TEST_PDDQ, v)
#endif

/*!
 * @brief HW_SATA_P0PHYSR - Port0 PHY Status Register
 *
 * This register is used to monitor PHY status. This                                 register only
 * exists when PHY_STAT_W parameter is set to a non-zero                                 value,
 * otherwise this location is reserved. The width is set by the
 * PHY_STAT_W parameter (valid range: 0 to 32). When PHY_CTRL_W <
 * 32, the remaining bits are reserved: reads return zeros, writes have
 * no effect.   The bits of this register reflect the state of the corresponding bits of
 * the p #  0 _phy_status input.  Signals connected to the p #  0 _phy_status input can be
 * asynchronous to                             any of the SATA block clocks, however they must not
 * change faster than                             five hclk periods, otherwise the SATA_P #  0 PHYSR
 * register may never be updated with                             the intermediate changing values.
 * Size: 32 bits  Address offset: for # = 0 to 7:  P0PHYSR: 0x17C  P1PHYSR: 0x1FC  P2PHYSR: 0x27C
 * P3PHYSR: 0x2FC  P4PHYSR: 0x37C  P5PHYSR: 0x3FC  P6PHYSR: 0x47C  P7PHYSR: 0x4FC    Read/write
 * access: Read-only  Reset: p#_phy_status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CR_DATA_OUT : 16; //!< CR Data Output Bus. Always presents last read data.
        unsigned RESERVED0 : 2; //!< 
        unsigned CR_ACK : 1; //!< CR Acknowledgement. Acknowledgement for the phy_cr_cap_addr, phy_cr_cap_data, phy_cr_write, and phy_cr_read control signals.
        unsigned RESERVED1 : 13; //!< 
    } B;
} hw_sata_p0physr_t;
#endif

/*
 * constants & macros for entire SATA_P0PHYSR register
 */
#define HW_SATA_P0PHYSR_ADDR      (REGS_SATA_BASE + 0x17c)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0PHYSR           (*(volatile hw_sata_p0physr_t *) HW_SATA_P0PHYSR_ADDR)
#define HW_SATA_P0PHYSR_RD()      (HW_SATA_P0PHYSR.U)
#define HW_SATA_P0PHYSR_WR(v)     (HW_SATA_P0PHYSR.U = (v))
#define HW_SATA_P0PHYSR_SET(v)    (HW_SATA_P0PHYSR_WR(HW_SATA_P0PHYSR_RD() |  (v)))
#define HW_SATA_P0PHYSR_CLR(v)    (HW_SATA_P0PHYSR_WR(HW_SATA_P0PHYSR_RD() & ~(v)))
#define HW_SATA_P0PHYSR_TOG(v)    (HW_SATA_P0PHYSR_WR(HW_SATA_P0PHYSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SATA_P0PHYSR bitfields
 */

/* --- Register HW_SATA_P0PHYSR, field CR_DATA_OUT
 *
 * CR Data Output Bus. Always presents last read data.
 */

#define BP_SATA_P0PHYSR_CR_DATA_OUT      0
#define BM_SATA_P0PHYSR_CR_DATA_OUT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0PHYSR_CR_DATA_OUT(v)   ((((reg32_t) v) << 0) & BM_SATA_P0PHYSR_CR_DATA_OUT)
#else
#define BF_SATA_P0PHYSR_CR_DATA_OUT(v)   (((v) << 0) & BM_SATA_P0PHYSR_CR_DATA_OUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0PHYSR_CR_DATA_OUT(v)   BF_CS1(SATA_P0PHYSR, CR_DATA_OUT, v)
#endif

/* --- Register HW_SATA_P0PHYSR, field CR_ACK
 *
 * CR Acknowledgement. Acknowledgement for the phy_cr_cap_addr, phy_cr_cap_data, phy_cr_write, and
 * phy_cr_read control signals.
 */

#define BP_SATA_P0PHYSR_CR_ACK      18
#define BM_SATA_P0PHYSR_CR_ACK      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SATA_P0PHYSR_CR_ACK(v)   ((((reg32_t) v) << 18) & BM_SATA_P0PHYSR_CR_ACK)
#else
#define BF_SATA_P0PHYSR_CR_ACK(v)   (((v) << 18) & BM_SATA_P0PHYSR_CR_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SATA_P0PHYSR_CR_ACK(v)   BF_CS1(SATA_P0PHYSR, CR_ACK, v)
#endif



/*!
 * @brief All SATA module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_sata_cap_t CAP; //!< HBA Capabilites Register
    volatile hw_sata_ghc_t GHC; //!< Global HBA Control Register
    volatile hw_sata_is_t IS; //!< Interrupt Status Register
    volatile hw_sata_pi_t PI; //!< Ports Implemented Register
    volatile hw_sata_vs_t VS; //!< AHCl Version Register
    volatile hw_sata_ccc_ctl_t CCC_CTL; //!< Command Completion Coalescing Control
    volatile hw_sata_ccc_ports_t CCC_PORTS; //!< Command Completion Coalescing Ports
    reg32_t _reserved0[2];
    volatile hw_sata_cap2_t CAP2; //!< HBA Capabilities Extended Register
    reg32_t _reserved1[30];
    volatile hw_sata_bistafr_t BISTAFR; //!< BIST Activate FIS Register
    volatile hw_sata_bistcr_t BISTCR; //!< BIST Control Register
    volatile hw_sata_bistfctr_t BISTFCTR; //!< BIST FIS Count Register
    volatile hw_sata_bistsr_t BISTSR; //!< BIST Status Register
    reg32_t _reserved2[3];
    volatile hw_sata_oobr_t OOBR; //!< OOB Register
    reg32_t _reserved3[4];
    volatile hw_sata_gpcr_t GPCR; //!< General Purpose Control Register
    volatile hw_sata_gpsr_t GPSR; //!< General Purpose Status Register
    reg32_t _reserved4[2];
    volatile hw_sata_timer1ms_t TIMER1MS; //!< Timer 1-ms Register
    reg32_t _reserved5;
    volatile hw_sata_gparam1r_t GPARAM1R; //!< Global Parameter 1 Register
    volatile hw_sata_gparam2r_t GPARAM2R; //!< Global Parameter 1 Register
    volatile hw_sata_pparamr_t PPARAMR; //!< Port Parameter Register
    volatile hw_sata_testr_t TESTR; //!< Test Register
    volatile hw_sata_versionr_t VERSIONR; //!< Version Register
    reg32_t _reserved6;
    volatile hw_sata_p0clb_t P0CLB; //!< Port0 Command List Base Address Register
    reg32_t _reserved7;
    volatile hw_sata_p0fb_t P0FB; //!< Port0 FIS Base Address Register
    reg32_t _reserved8;
    volatile hw_sata_p0is_t P0IS; //!< Port0 Interrupt Status Register
    volatile hw_sata_p0ie_t P0IE; //!< Port0 Interrupt Enable Register
    volatile hw_sata_p0cmd_t P0CMD; //!< Port0 Command Register
    reg32_t _reserved9;
    volatile hw_sata_p0tfd_t P0TFD; //!< Port0 Task File Data Register
    volatile hw_sata_p0sig_t P0SIG; //!< Port0 Signature Register
    volatile hw_sata_p0ssts_t P0SSTS; //!< Port0 Serial ATA Status Register
    volatile hw_sata_p0sctl_t P0SCTL; //!< Port0 Serial ATA Control {SControl}                        Register
    volatile hw_sata_p0serr_t P0SERR; //!< Port0 Serial ATA Error Register
    volatile hw_sata_p0sact_t P0SACT; //!< Port0 Serial ATA Active Register
    volatile hw_sata_p0ci_t P0CI; //!< Port0 Command Issue Register
    volatile hw_sata_p0sntf_t P0SNTF; //!< Port0 Serial ATA Notification Register
    reg32_t _reserved10[12];
    volatile hw_sata_p0dmacr_t P0DMACR; //!< Port0 DMA Control Register
    reg32_t _reserved11;
    volatile hw_sata_p0phycr_t P0PHYCR; //!< Port0 PHY Control Register
    volatile hw_sata_p0physr_t P0PHYSR; //!< Port0 PHY Status Register
} hw_sata_t
#endif

//! @brief Macro to access all SATA registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SATA(0)</code>.
#define HW_SATA     (*(volatile hw_sata_t *) REGS_SATA_BASE)


#endif // _SATA_H
